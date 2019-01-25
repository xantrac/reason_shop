defmodule ReasonShop.Repo.Migrations.CreateProducts do
  use Ecto.Migration

  def change do
    create table(:products) do
      add :type, :string
      add :brand, :string
      add :size, :string
      add :price, :integer

      timestamps()
    end

  end
end
