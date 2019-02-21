type t = {
  id: int,
  name: string,
  price: float,
};

let jsonDecodeExn = json =>
  Json.Decode.{
    id: json |> field("id", int),
    name: json |> field("name", string),
    price: json |> field("price", float),
  };

let jsonEncode = (record: t) =>
  Json.Encode.(
    object_([
      ("id", record.id |> int),
      ("name", record.name |> string),
      ("price", record.price |> float),
    ])
  );

let jsonDecode = Prelude.Json.decode(jsonDecodeExn);

let getId = (product: t): int => product.id;
