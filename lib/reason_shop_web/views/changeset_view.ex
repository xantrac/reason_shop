defmodule ReasonShopWeb.ChangesetView do
  use ReasonShopWeb, :view

  def render("errors.json", %Ecto.Changeset{} = changeset) do
    %{
      errors: render_errors(changeset.errors)
    }
  end

  # Private Functions

  defp render_errors(errors) do
    Enum.map(errors, fn {key, {message, _}} ->
      "#{key} #{message}"
    end)
  end
end
