defmodule ReasonShop.Customer do
  use Ecto.Schema
  import Ecto.Changeset


  schema "customers" do
    field :email, :string
    field :name, :string
    field :phone, :string

    timestamps()
  end

  @doc false
  def changeset(customer, attrs) do
    customer
    |> cast(attrs, [:name, :email, :phone])
    |> validate_required([:name, :email, :phone])
  end
end
