defmodule Cairo.Surface do
  @on_load :load_nif

  def load_nif do
    :cairo
    |> :code.priv_dir()
    |> Path.join("nif_lib/nif_cairo_surface")
    |> :erlang.load_nif(nil)
  end

  def create_image_surface(_width, _height) do
    raise "nif not loaded"
  end
end
