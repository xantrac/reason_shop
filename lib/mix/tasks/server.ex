defmodule Mix.Tasks.RS.Server do
  use Mix.Task

  def run(_args) do
    tasks = [
      Task.async(fn -> Mix.shell.cmd "cd assets && npm run start" end),
      Task.async(fn -> Mix.Task.run "phx.server" end)
    ]
    Enum.map(tasks, &Task.await(&1, :infinity))
    :ok
  end
end
