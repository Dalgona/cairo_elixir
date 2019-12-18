defmodule Cairo.NativeFunctions do
  @moduledoc false

  @on_load :load_nif

  def load_nif do
    :cairo
    |> :code.priv_dir()
    |> Path.join("nif_lib/nif_cairo")
    |> :erlang.load_nif(nil)
  end
end
