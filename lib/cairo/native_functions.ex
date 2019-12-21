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
  # CAIRO CONTEXTS
  #

  # defnif create(surface)
  # defnif status(cr)
  # defnif save(cr)
  # defnif restore(cr)
  # defnif get_target(cr)
  # defnif push_group(cr)
  # defnif push_group_with_content(cr, content)
  # defnif pop_group(cr)
  # defnif pop_group_to_source(cr)
  # defnif get_group_target(cr)
  # defnif set_source_rgb(cr, red, green, blue)
  # defnif set_source_rgba(cr, red, green, blue, alpha)
  # defnif set_source(cr, source)
  # defnif set_source_surface(cr, surface, x, y)
  # defnif get_source(cr)
  # defnif set_antialias(cr, antialias)
  # defnif get_antialias(cr)
  # defnif set_dash(cr, dashes, offset)
  # defnif get_dash(cr)
  # defnif set_fill_rule(cr, fill_rule)
  # defnif get_fill_rule(cr)
  # defnif set_line_cap(cr, line_cap)
  # defnif get_line_cap(cr)
  # defnif set_line_join(cr, line_join)
  # defnif get_line_join(cr)
  # defnif set_line_width(cr, width)
  # defnif get_line_width(cr)
  # defnif set_miter_limit(cr, limit)
  # defnif get_miter_limit(cr)
  # defnif set_operator(cr, op)
  # defnif get_operator(cr)
  # defnif set_tolerance(cr, tolerance)
  # defnif get_tolerance(cr)
  # defnif clip(cr)
  # defnif clip_preserve(cr)
  # defnif clip_extents(cr)
  # defnif in_clip(cr, x, y)
  # defnif reset_clip(cr)
  # defnif rectangle_list_destroy(rectangle_list)
  # defnif copy_clip_rectangle_list(cr)
  # defnif fill(cr)
  # defnif fill_preserve(cr)
  # defnif fill_extents(cr)
  # defnif in_fill(cr, x, y)
  # defnif mask(cr, pattern)
  # defnif mask_surface(cr, surface, surface_x, surface_y)
  # defnif paint(cr)
  # defnif paint_with_alpha(cr, alpha)
  # defnif stroke(cr)
  # defnif stroke_preserve(cr)
  # defnif stroke_extents(cr)
  # defnif in_stroke(cr, x, y)
  # defnif copy_page(cr)
  # defnif show_page(cr)
  # set_user_data(cr, key, user_data)
  # get_user_data(cr, key)

  #
  # PATHS
  #

  # defnif copy_path(cr)
  # defnif copy_path_flat(cr)
  # defnif append_path(cr, path)
  # defnif has_current_point(cr)
  # defnif get_current_point(cr)
  # defnif new_path(cr)
  # defnif new_sub_path(cr)
  # defnif close_path(cr)
  # defnif arc(cr, xc, yc, radius, angle1, angle2)
  # defnif arc_negative(cr, xc, yc, radius, angle1, angle2)
  # defnif curve_to(cr, x1, y1, x2, y2, x3, y3)
  # defnif line_to(cr, x, y)
  # defnif move_to(cr, x, y)
  # defnif rectangle(cr, x, y, width, height)
  # defnif glyph_path(cr, glyphs)
  # defnif text_path(cr, utf8)
  # defnif rel_curve_to(cr, dx1, dy1, dx2, dy2, dx3, dy3)
  # defnif rel_line_to(cr, dx, dy)
  # defnif rel_move_to(cr, dx, dy)
  # defnif path_extents(cr)

  #
  # SURFACES
  #

  defnif surface_create_similar(surface, content, width, height)
  defnif surface_create_similar_image(surface, format, width, height)
  defnif surface_create_for_rectangle(surface, x, y, width, height)
  # surface_status(surface)
  # surface_finish(surface)
  # surface_flush(surface)
  # surface_get_device(surface)
  # surface_get_font_options(surface)
  defnif surface_get_content(surface)
  defnif surface_mark_dirty(surface)
  defnif surface_mark_dirty_rectangle(surface, x, y, width, height)
  defnif surface_set_device_offset(surface, x_offset, y_offset)
  defnif surface_get_device_offset(surface)
  defnif surface_set_device_scale(surface, x_scale, y_scale)
  defnif surface_get_device_scale(surface)
  defnif surface_set_fallback_resolution(surface, x_ppi, y_ppi)
  defnif surface_get_fallback_resolution(surface)
  # surface_get_type(surface)
  # surface_get_reference_count(surface)
  # surface_set_user_data(surface, key, user_data)
  # surface_get_user_data(surface, key)
  # surface_copy_page(surface)
  # surface_show_page(surface)
  # surface_has_show_text_glyphs(surface)
  # surface_set_mime_data(surface, mime_type, data)
  # surface_get_mime_data(surface, mime_type)
  # surface_supports_mime_type(surface, mime_type)
  # surface_map_to_image(surface, x, y, width, height)
  # surface_unmap_image(surface, image)

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
