type t = {
  id: int,
  customer_id: int,
  product_id: int,
  state: string,
};

let jsonDecodeExn = json =>
  Json.Decode.{
    id: json |> field("id", int),
    customer_id: json |> field("customer_id", int),
    product_id: json |> field("product_id", int),
    state: json |> field("state", string),
  };

let jsonEncode = (record: t) =>
  Json.Encode.(
    object_([
      ("id", record.id |> int),
      ("customer_id", record.customer_id |> int),
      ("product_id", record.product_id |> int),
      ("state", record.state |> string),
    ])
  );

let jsonDecode = Prelude.Json.decode(jsonDecodeExn);

let getId = (purchase: t): int => purchase.id;

 let decode = (decodeFunc, json): option('a) =>
   switch (decodeFunc(json)) {
   | record => Some(record)
   | exception (Json.Decode.DecodeError(error)) => None
   };
