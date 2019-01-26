defmodule ReasonShop.Resources do

  import Ecto.Changeset
  import Ecto.Query, only: [from: 2]
  alias ReasonShop.Repo

  alias ReasonShop.Customer

  @spec list_customers() :: [%Customer{}] | []
  def list_customers() do
    Repo.all(Customer)
  end

  alias ReasonShop.Product

  @spec list_products() :: [%Product{}] | []
  def list_products() do
    Repo.all(Product)
  end

  alias ReasonShop.Purchase

  @spec purchases_list(customer_id :: String.t() | integer()) :: [%Purchase{}] | []
  def purchases_list(customer_id) do
    query = from p in Purchase,
    where: p.customer_id == ^customer_id
    Repo.all(query)
  end

  @spec add_purchase(attrs :: map()) :: {:ok, %Purchase{}} | {:error, %Ecto.Changeset{}}
  def add_purchase(attrs) do
    %Purchase{}
    |> purchase_create_changeset(attrs)
    |> Repo.insert()
  end

  @spec update_purchase_state(id :: String.t() | integer(), state :: String.t()) :: {:ok, %Purchase{}} | {:error, %Ecto.Changeset{}}
  def update_purchase_state(id, state) do
    case Repo.get(Purchase, id) do
       nil ->
        {:error, :no_record}
       
        purchase -> 
          purchase
          |> purchase_update_changeset(%{state: state})
          |> Repo.update()
    end
  end

  defp purchase_create_changeset(%Purchase{} = purchase, attrs) do
    purchase
    |> cast(attrs, [:customer_id, :product_id, :state])
    |> validate_inclusion(:state, ["Ordered", "Shipped", "Delivered"])
  end

  defp purchase_update_changeset(%Purchase{} = purchase, attrs) do
    purchase
    |> cast(attrs, [:state])
    |> validate_inclusion(:state, ["Ordered", "Shipped", "Delivered"])
  end
end
