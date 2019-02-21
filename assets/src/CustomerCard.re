open Css;

module Styles = {
  let customerCardBox = (isCustomerSelected: bool) =>
    style([
      flexDirection(column),
      width(vw(10.0)),
      isCustomerSelected ?
        border(px(3), solid, green) : border(px(3), none, green),
    ]);
};

let isCustomerSelected =
    (currentCustomer: Customer.t, selectedCustomer: option(Customer.t)): bool => {
  switch (selectedCustomer) {
  | Some(selectedCustomer) => currentCustomer.id === selectedCustomer.id
  | None => false
  };
};

let component = ReasonReact.statelessComponent("CustomerCard");

let make =
    (
      ~customer: Customer.t,
      ~selectCustomer: Customer.t => unit,
      ~selectedCustomer: option(Customer.t),
      _children,
    ) => {
  ...component,
  render: _self => {
    <div
      className={Styles.customerCardBox(
        isCustomerSelected(customer, selectedCustomer),
      )}
      onClick={_event => selectCustomer(customer)}>
      <div> {ReasonReact.string(customer.name)} </div>
    </div>;
  },
};
