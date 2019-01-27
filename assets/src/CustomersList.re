open Prelude;

let customers_list =
    (
      customersMap: Belt.Map.Int.t(Customer.t),
      _self: ReasonReact.self('a, 'b, 'c),
    )
    : ReasonReact.reactElement =>
  customersMap
  |> Map.intMapToArray
  |> Belt.Array.map(_, (customer: Customer.t) =>
       <div> {ReasonReact.string(customer.name)} </div>
     )
  |> ReasonReact.array;

let component = ReasonReact.statelessComponent("CustomersList");

let make = (~customers: Belt.Map.Int.t(Customer.t), _children) => {
  ...component,
  render: self => <div> {customers_list(customers, self)} </div>,
};
