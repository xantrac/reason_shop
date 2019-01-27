type t = {
  id: int,
  brand: string,
  price: int,
  size: string,
  category: string,
};

let jsonDecodeExn = json =>
  Json.Decode.{
    id: json |> field("id", int),
    brand: json |> field("brand", string),
    price: json |> field("price", int),
    size: json |> field("size", string),
    category: json |> field("type", string),
  };

let jsonEncode = (record: t) =>
  Json.Encode.(
    object_([
      ("id", record.id |> int),
      ("brand", record.brand |> string),
      ("price", record.price |> int),
      ("size", record.size |> string),
      ("type", record.category |> string),
    ])
  );

let jsonDecode = Prelude.Json.decode(jsonDecodeExn);

let getId = (product: t): int => product.id;
