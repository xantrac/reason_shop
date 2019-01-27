open Phoenix;
open Prelude;

type state = {
  customers: Belt.Map.Int.t(Customer.t),
  products: Belt.Map.Int.t(Product.t),
};

let loadJoinDataToState = (data: InitialState.t): state => {
  customers: List.listToIntMap(data.customers, Customer.getId),
  products: List.listToIntMap(data.products, Product.getId),
};

type action =
  | ReceiveJoinData(InitialState.t);

let reducer = (action: action, state: state) =>
  switch (action) {
  | ReceiveJoinData(data) => ReasonReact.Update(loadJoinDataToState(data))
  };

let joinEventHandler =
    (
      self: ReasonReact.self(state, 'a, action),
      result: Belt.Result.t(InitialState.t, string),
    ) =>
  switch (result) {
  | Belt.Result.Ok(data) => self.send(ReceiveJoinData(data))
  | Belt.Result.Error(error) => Js.log(error)
  };

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    customers: Belt.Map.Int.empty,
    products: Belt.Map.Int.empty,
  },
  reducer,
  didMount: self => {
    ShopChannel.onJoin() |> Repromise.wait(joinEventHandler(self));
  },
  render: self => {
    <div> <CustomersList customers={self.state.customers} /> </div>;
  },
};
