# Script for populating the database. You can run it as:
#
#     mix run priv/repo/seeds.exs
#
# Inside the script, you can read and write to any of your
# repositories directly:
#
#     ReasonShop.Repo.insert!(%ReasonShop.SomeSchema{})
#
# We recommend using the bang functions (`insert!`, `update!`
# and so on) as they will fail if something goes wrong.

import ReasonShop.Factory

customers = insert_list(5, :customer)
products = insert_list(30, :product)

random_product_id = Enum.map(products, & &1.id) |> Enum.random

customers
|> Enum.each(fn customer ->
  (1..Faker.random_between(5, 10))
  |> Enum.each(fn _ -> 
    insert(:purchase, customer_id: customer.id, product_id: random_product_id )
  end)
end)

