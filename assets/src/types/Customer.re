type t = {
  id: int,
  email: string,
  name: string,
  phone: string,
};

let jsonDecodeExn = json =>
  Json.Decode.{
    id: json |> field("id", int),
    email: json |> field("email", string),
    name: json |> field("name", string),
    phone: json |> field("phone", string),
  };

let jsonEncode = (record: t) =>
  Json.Encode.(
    object_([
      ("id", record.id |> int),
      ("email", record.email |> string),
      ("name", record.name |> string),
      ("phone", record.phone |> string),
    ])
  );

let jsonDecode = Prelude.Json.decode(jsonDecodeExn);

let getId = (customer: t): int => customer.id;
