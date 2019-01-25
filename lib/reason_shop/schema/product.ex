defmodule ReasonShop.Product do
  use Ecto.Schema
  import Ecto.Changeset


  schema "products" do
    field :brand, :string
    field :price, :integer
    field :size, :string
    field :type, :string

    timestamps()
  end

  @doc false
  def changeset(product, attrs) do
    product
    |> cast(attrs, [:type, :brand, :size, :price])
    |> validate_required([:type, :brand, :size, :price])
  end
end
