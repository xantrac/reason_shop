defmodule ReasonShopWeb.MainChannel do
  use ReasonShopWeb, :channel
  alias ReasonShopWeb.{ProductsView, CustomersView, PurchasesView, ChangesetView, ErrorView, Endpoint}
  alias ReasonShop.Resources
  alias ReasonShop.{Product, Customer, Purchase}
  alias Phoenix.{View, Socket}

  @channel_name "main"

  @spec join(String.t(), map(), Socket.t()) :: {:ok, map(), Socket.t()}
  def join(@channel_name, _params, socket) do
    customers = Resources.list_customers()
    products = Resources.list_products()

    data =
    %{}
    |> Map.merge(View.render(CustomersView, "customers.json", %{customers: customers}))
    |> Map.merge(View.render(ProductsView, "products.json", %{products: products}))
    {:ok, %{data: data}, socket}
  end

end
