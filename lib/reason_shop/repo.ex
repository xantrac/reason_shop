defmodule ReasonShop.Repo do
  use Ecto.Repo,
    otp_app: :reason_shop,
    adapter: Ecto.Adapters.Postgres
end
