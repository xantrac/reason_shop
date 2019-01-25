defmodule ReasonShop.Purchase do
  use Ecto.Schema
  import Ecto.Changeset


  schema "purchases" do
    field :state, :string
    field :customer_id, :id
    field :product_id, :id

    timestamps()
  end

  @doc false
  def changeset(purchase, attrs) do
    purchase
    |> cast(attrs, [:state])
    |> validate_required([:state])
  end
end
