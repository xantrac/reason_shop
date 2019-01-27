defmodule ReasonShopWeb.PurchasesView do
  use ReasonShopWeb, :view
  alias ReasonShopWeb.PurchasesView

  def render("purchases.json", %{purchases: purchases}) do
    %{purchases: render_many(purchases, PurchasesView, "purchase.json", as: :purchase)}
  end

  def render("purchases.json", %{purchase: purchase}) do
    %{
      id: purchase.id,
      customer_id: purchase.customer_id,
      product_id: purchase.product_id,
      state: purchase.state,
    }
  end
end
