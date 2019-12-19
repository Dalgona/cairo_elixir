defmodule Cairo.NativeFunctions do
  @moduledoc false

  require __MODULE__.Macros
  import __MODULE__.Macros

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

  defnif surface_create_similar(surface, content, width, height)
  defnif surface_create_similar_image(surface, format, width, height)
  defnif surface_create_for_rectangle(surface, x, y, width, height)
  defnif surface_get_content(surface)
  defnif surface_mark_dirty(surface)
  defnif surface_mark_dirty_rectangle(surface, x, y, width, height)
  defnif surface_set_device_offset(surface, x_offset, y_offset)
  defnif surface_get_device_offset(surface)
  defnif surface_set_device_scale(surface, x_scale, y_scale)
  defnif surface_get_device_scale(surface)
  defnif surface_set_fallback_resolution(surface, x_ppi, y_ppi)
  defnif surface_get_fallback_resolution(surface)

  #
  # IMAGE SURFACES
  #

  defnif format_stride_for_width(format, width)
  defnif image_surface_create(format, width, height)
  defnif image_surface_create_for_data(data, format, width, height, stride)
  defnif image_surface_get_data(surface)
  defnif image_surface_get_format(surface)
  defnif image_surface_get_width(surface)
  defnif image_surface_get_height(surface)
  defnif image_surface_get_stride(surface)
end
