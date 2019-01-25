defmodule ReasonShop.Factory do
  use ExMachina.Ecto, repo: ReasonShop.Repo

  # Faker usage guide:
  # https://github.com/igas/faker/blob/master/USAGE.md

  @spec customer_factory() :: Customer.t()
  def customer_factory do
    %ReasonShop.Customer{
      name: Faker.Name.name(),
      email: Faker.Internet.email(),
      phone: Faker.Phone.EnUs.phone()
    }
  end

  @spec product_factory() :: Product.t()
  def product_factory do
    %ReasonShop.Product{
      brand: "#{Faker.Commerce.product_name_adjective()} #{Faker.Commerce.product_name_material()}",
      price: Faker.random_between(20, 300),
      size: Faker.Util.pick(["S", "M", "L", "XL", "XXL", "XXXL"]),
      type: Faker.Util.pick(["T-Shirt", "Hat", "Jacket", "Pants", "Gloves"])
    }
  end

  @spec purchase_factory() :: Purchase.t()
  def purchase_factory do
    %ReasonShop.Purchase{
      customer_id: 1,
      product_id: 1,
      state: Faker.Util.pick(["Ordered", "Shipped", "Delivered"])
    }
  end

end
