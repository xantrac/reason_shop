module List = {
  include Belt.List;

  let listToIntMap = (list: list('a), idGetter: 'a => int) =>
    list
    |> Array.of_list
    |> Belt.Array.map(_, elem => (idGetter(elem), elem))
    |> Belt.Map.Int.fromArray;
};

module Map = {
  include Belt.Map;

  let intMapToList = (map: Belt.Map.Int.t('a)): list('a) =>
    map |> Belt.Map.Int.toList |> Belt.List.map(_, snd);

  let intMapToArray = (map: Belt.Map.Int.t('a)): array('a) =>
    map |> Belt.Map.Int.toArray |> Belt.Array.map(_, snd);
};

module Json = {
  include Js.Json;

  let toBeltResult =
      (jsonFunc: 'a => 'b, json: 'a): Belt.Result.t('b, string) =>
    switch (jsonFunc(json)) {
    | record => Belt.Result.Ok(record)
    | exception (Json.Decode.DecodeError(error)) => Belt.Result.Error(error)
    };

  let decode = (decodeFunc, json): Belt.Result.t('a, string) =>
    switch (decodeFunc(json)) {
    | record => Belt.Result.Ok(record)
    | exception (Json.Decode.DecodeError(error)) => Belt.Result.Error(error)
    };
};

let getOrInit = (myRef: ref(option('a)), init: unit => 'a): 'a =>
  switch (myRef^) {
  | Some(value) => value
  | None =>
    let value = init();
    myRef := Some(value);
    value;
  };

let normalizedColor = (hex: string): string => {
  Js.String.sliceToEnd(~from=1, hex);
};
