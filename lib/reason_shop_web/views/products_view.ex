defmodule ReasonShopWeb.ProductsView do
  use ReasonShopWeb, :view
  alias ReasonShopWeb.ProductsView

  def render("products.json", %{products: products}) do
    %{products: render_many(products, ProductsView, "product.json", as: :product)}
  end

  def render("product.json", %{product: product}) do
    %{
      id: product.id,
      name: product.name,
      price: product.price,
    }
  end
end
