defmodule ReasonShop.Repo.Migrations.CreatePurchases do
  use Ecto.Migration

  def change do
    create table(:purchases) do
      add :state, :string
      add :customer_id, references(:customers, on_delete: :nothing)
      add :product_id, references(:products, on_delete: :nothing)
      
      timestamps()
    end

    create index(:purchases, [:customer_id])
    create index(:purchases, [:product_id])
  end
end
