type t = {data: InitialState.t};

let jsonDecodeExn = json =>
  Json.Decode.{data: json |> field("data", InitialState.jsonDecodeExn)};

let jsonEncode = (record: t) =>
  Json.Encode.(object_([("data", record.data |> InitialState.jsonEncode)]));

let jsonDecode = Prelude.Json.decode(jsonDecodeExn);
