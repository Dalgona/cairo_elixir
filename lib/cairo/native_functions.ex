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
  # SURFACES
  #

  def surface_create_similar(surface, content, width, height), do: nif_err!
  def surface_create_similar_image(surface, format, width, height), do: nif_err!
  def surface_create_for_rectangle(surface, x, y, width, height), do: nif_err!
  def surface_get_content(_surface), do: nif_err!()
  def surface_mark_dirty(surface), do: nif_err!
  def surface_mark_dirty_rectangle(surface, x, y, width, height), do: nif_err!
  def surface_set_device_offset(surface, x_offset, y_offset), do: nif_err!
  def surface_get_device_offset(surface), do: nif_err!
  def surface_set_device_scale(surface, x_scale, y_scale), do: nif_err!
  def surface_get_device_scale(surface), do: nif_err!
  def surface_set_fallback_resolution(surface, x_ppi, y_ppi), do: nif_err!
  def surface_get_fallback_resolution(surface), do: nif_err!

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
