open Phoenix;
open Prelude;
open Css;

module Styles = {
  let mainContainer =
    style([display(flexBox), flexDirection(row), backgroundColor(white)]);

  let customersColumn =
    style([
      display(flexBox),
      flexDirection(column),
      backgroundColor(ghostwhite),
      width(vw(20.0)),
    ]);

  let productsColumn =
    style([
      display(flexBox),
      flexDirection(row),
      flexWrap(wrap),
      backgroundColor(ghostwhite),
      width(vw(80.0)),
    ]);
};

type state = {
  customers: Belt.Map.Int.t(Customer.t),
  products: Belt.Map.Int.t(Product.t),
  current_customer: option(Customer.t),
};

let loadJoinDataToState = (data: InitialState.t): state => {
  customers: List.listToIntMap(data.customers, Customer.getId),
  products: List.listToIntMap(data.products, Product.getId),
  current_customer: None,
};

type action =
  | ReceiveJoinData(InitialState.t)
  | SelectCustomer(Customer.t);

let reducer = (action: action, state: state) =>
  switch (action) {
  | ReceiveJoinData(data) => ReasonReact.Update(loadJoinDataToState(data))
  | SelectCustomer(customer) =>
    ReasonReact.Update({...state, current_customer: Some(customer)})
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

let selectCustomer =
    (self: ReasonReact.self('a, 'b, 'c), customer: Customer.t): unit => {
  self.send(SelectCustomer(customer));
};

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  initialState: () => {
    customers: Belt.Map.Int.empty,
    products: Belt.Map.Int.empty,
    current_customer: None,
  },
  reducer,
  didMount: self => {
    ShopChannel.onJoin() |> Repromise.wait(joinEventHandler(self));
  },
  render: self => {
    <div className=Styles.mainContainer>
      <div className=Styles.customersColumn>
        <CustomersList
          customers={self.state.customers}
          selectCustomer={selectCustomer(self)}
          selectedCustomer={self.state.current_customer}
        />
      </div>
      <div className=Styles.productsColumn>
        <ProductsList
          products={self.state.products}
          selectedCustomer={self.state.current_customer}
        />
      </div>
    </div>;
  },
};
