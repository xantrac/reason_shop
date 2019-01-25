defmodule ReasonShop.Repo.Migrations.CreateCustomers do
  use Ecto.Migration

  def change do
    create table(:customers) do
      add :name, :string
      add :email, :string
      add :phone, :string

      timestamps()
    end

  end
end
