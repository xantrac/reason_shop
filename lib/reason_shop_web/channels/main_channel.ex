defmodule ReasonShopWeb.MainChannel do
use ReasonShopWeb, :channel

  alias PoolPartyWeb.{ProductView, CustomerView, PurchaseView, ChangesetView, ErrorView, Endpoint}
  alias ReasonShop.Product
  alias ReasonShop.Customer
  alias ReasonShop.Purchase
  alias Phoenix.{View, Socket}

  @channel_name "main"

  @spec join(String.t(), map(), Socket.t()) :: {:ok, map(), Socket.t()}
  def join(@channel_name, _params, socket) do
    
    {:ok, %{data: "hello"}, socket}
  end

end
