open Prelude;

module type WebSocketInterface = {
  module Socket: {type t;};
  module Channel: {type t;};
  module Push: {type t;};

  let initSocket: (~opts: Js.t('a)=?, string) => Socket.t;
  let initChannel: (string, ~chanParams: Js.t('a)=?, Socket.t) => Channel.t;
  let joinChannel: (~timeout: float=?, Channel.t) => Push.t;
  let connectSocket: (~params: Js.t('a)=?, Socket.t) => Socket.t;
  let putReceive: (string, Js.Json.t => unit, Push.t) => Push.t;
  let push: (string, Js.t('a), ~timeout: float=?, Channel.t) => Push.t;
  let putOn: (string, Js.Json.t => unit, Channel.t) => Channel.t;
};

module CreateChannel = (WS: WebSocketInterface) => {
  type error;
  type t;

  let mySocket: ref(option(WS.Socket.t)) = ref(None);
  let myChannel: ref(option(WS.Channel.t)) = ref(None);
  let myJoinEvent: ref(option(WS.Push.t)) = ref(None);

  let getSocket = (): WS.Socket.t =>
    getOrInit(mySocket, () => WS.initSocket("/socket") |> WS.connectSocket);

  let getChannel = (): WS.Channel.t =>
    getOrInit(myChannel, () => getSocket() |> WS.initChannel("main"));

  let getJoinEvent = (): WS.Push.t =>
    getOrInit(myJoinEvent, () => getChannel() |> WS.joinChannel);

  let sendPush = (event: string, payload: Js.t('a)): WS.Push.t =>
    WS.push(event, payload, getChannel());

  let onJoin = (): Promise.t(Belt.Result.t(InitialState.t, string)) => {
    let (promise, resolve_promise) = Promise.pending();

    getJoinEvent()
    |> WS.putReceive("ok", response =>
         response
         |> Json.toBeltResult(JoinEvent.jsonDecodeExn)
         |> Belt.Result.map(_, resp => resp.data)
         |> resolve_promise
       )
    |> WS.putReceive("error", _errorJson =>
         Belt.Result.Error("Failed Join event") |> resolve_promise
       )
    |> ignore;

    promise;
  };
};

module ShopChannel = CreateChannel(Phx);
