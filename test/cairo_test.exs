defmodule CairoTest do
  use ExUnit.Case
  doctest Cairo

  test "greets the world" do
    assert Cairo.hello() == :world
  end
end
