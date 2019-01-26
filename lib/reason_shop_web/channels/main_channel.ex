defmodule ReasonShopWeb.MainChannel do
  use ReasonShopWeb, :channel
  alias PoolPartyWeb.{ProductView, CustomerView, PurchaseView, ChangesetView, ErrorView, Endpoint}
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
    |> Map.merge(View.render(CustomerView, "customers.json", %{customers: customers}))
    |> Map.merge(View.render(ProductView, "products.json", %{products: products}))
    {:ok, %{data: "hello"}, socket}
  end

end
