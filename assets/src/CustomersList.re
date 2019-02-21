open Prelude;

let customers_list =
    (
      customersMap: Belt.Map.Int.t(Customer.t),
      selectCustomer: Customer.t => unit,
      selectedCustomer: option(Customer.t),
    )
    : ReasonReact.reactElement =>
  customersMap
  |> Map.intMapToArray
  |> Belt.Array.map(_, (customer: Customer.t) =>
       <CustomerCard
         key={string_of_int(customer.id)}
         customer
         selectCustomer
         selectedCustomer
       />
     )
  |> ReasonReact.array;

let component = ReasonReact.statelessComponent("CustomersList");

let make =
    (
      ~customers: Belt.Map.Int.t(Customer.t),
      ~selectCustomer: Customer.t => unit,
      ~selectedCustomer: option(Customer.t),
      _children,
    ) => {
  {
    ...component,
    render: _self => {
      customers_list(customers, selectCustomer, selectedCustomer);
    },
  };
};
