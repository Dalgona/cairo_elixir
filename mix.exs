defmodule Cairo.MixProject do
  use Mix.Project

  def project do
    [
      app: :cairo,
      version: "0.1.0",
      elixir: ">= 1.8.0",
      start_permanent: Mix.env() == :prod,
      compilers: [:elixir_make] ++ Mix.compilers(),
      deps: deps()
    ]
  end

  # Run "mix help compile.app" to learn about applications.
  def application do
    [
      extra_applications: [:logger],
      mod: {Cairo.Application, []}
    ]
  end

  # Run "mix help deps" to learn about dependencies.
  defp deps do
    [
      {:elixir_make, "0.6.2"}
    ]
  end
end
