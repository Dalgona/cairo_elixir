defmodule Cairo.NativeFunctions do
  @moduledoc false

  @on_load :load_nif

  def load_nif do
    :cairo
    |> :code.priv_dir()
    |> Path.join("nif_lib/nif_cairo")
    |> :erlang.load_nif(nil)
  end

  #
  # IMAGE SURFACES
  #

  def format_stride_for_width(_format, _width), do: nif_err!()
  def image_surface_create(_format, _width, _height), do: nif_err!()
  def image_surface_create_for_data(_data, _format, _width, _height, _stride), do: nif_err!()
  def image_surface_get_data(_surface), do: nif_err!()
  def image_surface_get_format(_surface), do: nif_err!()
  def image_surface_get_width(_surface), do: nif_err!()
  def image_surface_get_height(_surface), do: nif_err!()
  def image_surface_get_stride(_surface), do: nif_err!()

  defp nif_err!, do: raise "nif not loaded"
end
