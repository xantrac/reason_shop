defmodule ReasonShopWeb.CustomersView do
  use ReasonShopWeb, :view
  alias ReasonShopWeb.CustomersView

  def render("customers.json", %{customers: customers}) do
    %{customers: render_many(customers, CustomersView, "customer.json", as: :customer)}
  end

  def render("customer.json", %{customer: customer}) do
    %{
      id: customer.id,
      email: customer.email,
      name: customer.name,
      phone: customer.phone,
    }
  end
end
