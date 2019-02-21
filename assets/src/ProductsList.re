open Prelude;

let products_list =
    (
      customersMap: Belt.Map.Int.t(Product.t),
      _self: ReasonReact.self('a, 'b, 'c),
    )
    : ReasonReact.reactElement =>
  customersMap
  |> Map.intMapToArray
  |> Belt.Array.map(_, (product: Product.t) =>
       <ProductCard key={string_of_int(product.id)} product />
     )
  |> ReasonReact.array;

let component = ReasonReact.statelessComponent("ProductsList");

let make = (~products: Belt.Map.Int.t(Product.t), _children) => {
  ...component,
  render: self => {
    products_list(products, self);
  },
};
