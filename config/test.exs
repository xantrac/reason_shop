use Mix.Config

# We don't run a server during test. If one is required,
# you can enable the server option below.
config :reason_shop, ReasonShopWeb.Endpoint,
  http: [port: 4002],
  server: false

# Print only warnings and errors during test
config :logger, level: :warn

# Configure your database
config :reason_shop, ReasonShop.Repo,
  username: "postgres",
  password: "postgres",
  database: "reason_shop_test",
  hostname: "localhost",
  pool: Ecto.Adapters.SQL.Sandbox
