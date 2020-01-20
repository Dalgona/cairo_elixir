defmodule Cairo.NativeFunctions do
  @moduledoc false

  require __MODULE__.Macros
  import __MODULE__.Macros
  alias Cairo.Surface

  @type cairo_handle :: term()
  @type surface_handle :: term()

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

  @spec create(surface_handle()) :: cairo_handle()
  defnif create(surface)

  @spec status(cairo_handle()) :: Cairo.status()
  defnif status(cr)

  @spec save(cairo_handle()) :: :ok
  defnif save(cr)

  @spec restore(cairo_handle()) :: :ok
  defnif restore(cr)

  # defnif get_target(cr)
  # defnif push_group(cr)
  # defnif push_group_with_content(cr, content)
  # defnif pop_group(cr)
  # defnif pop_group_to_source(cr)
  # defnif get_group_target(cr)

  @spec set_source_rgb(cairo_handle(), number(), number(), number()) :: :ok
  defnif set_source_rgb(cr, red, green, blue)

  @spec set_source_rgba(cairo_handle(), number(), number(), number(), number()) :: :ok
  defnif set_source_rgba(cr, red, green, blue, alpha)

  # defnif set_source(cr, source)
  # defnif set_source_surface(cr, surface, x, y)
  # defnif get_source(cr)

  @spec set_antialias(cairo_handle(), Cairo.antialias()) :: :ok
  defnif set_antialias(cr, antialias)

  @spec get_antialias(cairo_handle()) :: Cairo.antialias()
  defnif get_antialias(cr)

  @spec set_dash(cairo_handle(), [number()], number()) :: :ok
  defnif set_dash(cr, dashes, offset)

  @spec get_dash(cairo_handle()) :: {[number()], number()}
  defnif get_dash(cr)

  @spec set_fill_rule(cairo_handle(), Cairo.fill_rule()) :: :ok
  defnif set_fill_rule(cr, fill_rule)

  @spec get_fill_rule(cairo_handle()) :: Cairo.fill_rule()
  defnif get_fill_rule(cr)

  @spec set_line_cap(cairo_handle(), Cairo.line_cap()) :: :ok
  defnif set_line_cap(cr, line_cap)

  @spec get_line_cap(cairo_handle()) :: Cairo.line_cap()
  defnif get_line_cap(cr)

  @spec set_line_join(cairo_handle(), Cairo.line_join()) :: :ok
  defnif set_line_join(cr, line_join)

  @spec get_line_join(cairo_handle()) :: Cairo.line_join()
  defnif get_line_join(cr)

  @spec set_line_width(cairo_handle(), number()) :: :ok
  defnif set_line_width(cr, width)

  @spec get_line_width(cairo_handle()) :: number()
  defnif get_line_width(cr)

  @spec set_miter_limit(cairo_handle(), number()) :: :ok
  defnif set_miter_limit(cr, limit)

  @spec get_miter_limit(cairo_handle()) :: number()
  defnif get_miter_limit(cr)

  # defnif set_operator(cr, op)
  # defnif get_operator(cr)

  @spec set_tolerance(cairo_handle(), number()) :: :ok
  defnif set_tolerance(cr, tolerance)

  @spec get_tolerance(cairo_handle()) :: number()
  defnif get_tolerance(cr)

  @spec clip(cairo_handle()) :: :ok
  defnif clip(cr)

  @spec clip_preserve(cairo_handle()) :: :ok
  defnif clip_preserve(cr)

  @spec clip_extents(cairo_handle()) :: {Cairo.vec2(), Cairo.vec2()}
  defnif clip_extents(cr)

  @spec in_clip(cairo_handle(), Cairo.vec2()) :: boolean()
  defnif in_clip(cr, pt)

  @spec reset_clip(cairo_handle()) :: :ok
  defnif reset_clip(cr)

  # defnif rectangle_list_destroy(rectangle_list)
  # defnif copy_clip_rectangle_list(cr)

  @spec fill(cairo_handle()) :: :ok
  defnif fill(cr)

  @spec fill_preserve(cairo_handle()) :: :ok
  defnif fill_preserve(cr)

  @spec fill_extents(cairo_handle()) :: {Cairo.vec2(), Cairo.vec2()}
  defnif fill_extents(cr)

  @spec in_fill(cairo_handle(), Cairo.vec2()) :: boolean()
  defnif in_fill(cr, pt)

  # defnif mask(cr, pattern)
  # defnif mask_surface(cr, surface, surface_x, surface_y)

  @spec paint(cairo_handle()) :: :ok
  defnif paint(cr)

  @spec paint_with_alpha(cairo_handle(), number()) :: :ok
  defnif paint_with_alpha(cr, alpha)

  @spec stroke(cairo_handle()) :: :ok
  defnif stroke(cr)

  @spec stroke_preserve(cairo_handle()) :: :ok
  defnif stroke_preserve(cr)

  @spec stroke_extents(cairo_handle()) :: {Cairo.vec2(), Cairo.vec2()}
  defnif stroke_extents(cr)

  @spec in_stroke(cairo_handle(), Cairo.vec2()) :: boolean()
  defnif in_stroke(cr, pt)

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

  @spec has_current_point(cairo_handle()) :: boolean()
  defnif has_current_point(cr)

  @spec get_current_point(cairo_handle()) :: Cairo.vec2()
  defnif get_current_point(cr)

  @spec new_path(cairo_handle()) :: :ok
  defnif new_path(cr)

  @spec new_sub_path(cairo_handle()) :: :ok
  defnif new_sub_path(cr)

  @spec close_path(cairo_handle()) :: :ok
  defnif close_path(cr)

  @spec arc(cairo_handle(), Cairo.vec2(), number(), number(), number()) :: :ok
  defnif arc(cr, center, radius, angle1, angle2)

  @spec arc_negative(cairo_handle(), Cairo.vec2(), number(), number(), number()) :: :ok
  defnif arc_negative(cr, center, radius, angle1, angle2)

  @spec curve_to(cairo_handle(), Cairo.vec2(), Cairo.vec2(), Cairo.vec2()) :: :ok
  defnif curve_to(cr, pt1, pt2, pt3)

  @spec line_to(cairo_handle(), Cairo.vec2()) :: :ok
  defnif line_to(cr, pt)

  @spec move_to(cairo_handle(), Cairo.vec2()) :: :ok
  defnif move_to(cr, pt)

  @spec rectangle(cairo_handle(), number(), number(), number(), number()) :: :ok
  defnif rectangle(cr, x, y, width, height)

  # defnif glyph_path(cr, glyphs)

  @spec text_path(cairo_handle(), binary()) :: :ok
  defnif text_path(cr, utf8)

  @spec rel_curve_to(cairo_handle(), Cairo.vec2(), Cairo.vec2(), Cairo.vec2()) :: :ok
  defnif rel_curve_to(cr, pt1, pt2, pt3)

  @spec rel_line_to(cairo_handle(), Cairo.vec2()) :: :ok
  defnif rel_line_to(cr, diff)

  @spec rel_move_to(cairo_handle(), Cairo.vec2()) :: :ok
  defnif rel_move_to(cr, diff)

  @spec path_extents(cairo_handle()) :: {Cairo.vec2(), Cairo.vec2()}
  defnif path_extents(cr)

  #
  # SURFACES
  #

  @spec surface_create_similar(surface_handle(), Surface.content_type(), integer(), integer()) ::
          surface_handle()
  defnif surface_create_similar(surface, content, width, height)

  @spec surface_create_similar_image(surface_handle(), Cairo.format(), integer(), integer()) ::
          surface_handle()
  defnif surface_create_similar_image(surface, format, width, height)

  @spec surface_create_for_rectangle(surface_handle(), number(), number(), number(), number()) ::
          surface_handle()
  defnif surface_create_for_rectangle(surface, x, y, width, height)

  @spec surface_status(surface_handle()) :: Cairo.status()
  defnif surface_status(surface)

  @spec surface_finish(surface_handle()) :: :ok
  defnif surface_finish(surface)

  @spec surface_flush(surface_handle()) :: :ok
  defnif surface_flush(surface)

  # surface_get_font_options(surface)

  @spec surface_get_content(surface_handle()) :: Surface.content_type()
  defnif surface_get_content(surface)

  @spec surface_mark_dirty(surface_handle()) :: :ok
  defnif surface_mark_dirty(surface)

  @spec surface_mark_dirty_rectangle(surface_handle(), integer(), integer(), integer(), integer()) ::
          :ok
  defnif surface_mark_dirty_rectangle(surface, x, y, width, height)

  @spec surface_set_device_offset(surface_handle(), Cairo.vec2()) :: :ok
  defnif surface_set_device_offset(surface, offset)

  @spec surface_get_device_offset(surface_handle()) :: Cairo.vec2()
  defnif surface_get_device_offset(surface)

  @spec surface_set_device_scale(surface_handle(), Cairo.vec2()) :: :ok
  defnif surface_set_device_scale(surface, scale)

  @spec surface_get_device_scale(surface_handle()) :: Cairo.vec2()
  defnif surface_get_device_scale(surface)

  @spec surface_set_fallback_resolution(surface_handle(), Cairo.vec2()) :: :ok
  defnif surface_set_fallback_resolution(surface, ppi)

  @spec surface_get_fallback_resolution(surface_handle()) :: Cairo.vec2()
  defnif surface_get_fallback_resolution(surface)

  @spec surface_get_type(surface_handle()) :: Surface.type()
  defnif surface_get_type(surface)
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

  @spec format_stride_for_width(Cairo.format(), integer()) :: integer()
  defnif format_stride_for_width(format, width)

  @spec image_surface_create(Cairo.format(), integer(), integer()) :: surface_handle()
  defnif image_surface_create(format, width, height)

  @spec image_surface_create_for_data(binary(), Cairo.format(), integer(), integer(), integer()) ::
          surface_handle()
  defnif image_surface_create_for_data(data, format, width, height, stride)

  @spec image_surface_get_data(surface_handle()) :: binary()
  defnif image_surface_get_data(surface)

  @spec image_surface_get_format(surface_handle()) :: Cairo.format()
  defnif image_surface_get_format(surface)

  @spec image_surface_get_width(surface_handle()) :: integer()
  defnif image_surface_get_width(surface)

  @spec image_surface_get_height(surface_handle()) :: integer()
  defnif image_surface_get_height(surface)

  @spec image_surface_get_stride(surface_handle()) :: integer()
  defnif image_surface_get_stride(surface)

  #
  # PNG SUPPORT
  #

  # defnif image_surface_create_from_png(data)

  @spec surface_write_to_png(surface_handle()) :: iodata()
  defnif surface_write_to_png(surface)
end
