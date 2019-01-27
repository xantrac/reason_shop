type t = {
  customers: list(Customer.t),
  products: list(Product.t),
};

let jsonDecodeExn = json =>
  Json.Decode.{
    customers: json |> field("customers", list(Customer.jsonDecodeExn)),
    products: json |> field("products", list(Product.jsonDecodeExn)),
  };

let jsonEncode = (record: t) =>
  Json.Encode.(
    object_([
      ("agents", list(Customer.jsonEncode, record.customers)),
      ("engineers", list(Product.jsonEncode, record.products)),
    ])
  );

let jsonDecode = Prelude.Json.decode(jsonDecodeExn);
