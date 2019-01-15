defmodule ReasonShopWeb.PageController do
  use ReasonShopWeb, :controller

  def index(conn, _params) do
    render(conn, "index.html")
  end
end
