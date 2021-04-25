defmodule Cairo.NativeFunctions do
  @moduledoc false

  require __MODULE__.Macros
  import __MODULE__.Macros
  alias Cairo.FontOptions
  alias Cairo.Pango
  alias Cairo.Surface

  @type cairo_handle :: term()
  @type font_options_handle :: term()
  @type surface_handle :: term()
  @type pango_font_desc_handle :: term()
  @type pango_layout_handle :: term()

  @on_load :load_nif

  def load_nif do
    :cairo
    |> :code.priv_dir()
    |> Path.join("nif_lib/nif_cairo")
    |> to_charlist()
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
  # FONT OPTIONS
  #

  @spec font_options_create() :: font_options_handle()
  defnif font_options_create()

  @spec font_options_copy(font_options_handle()) :: font_options_handle()
  defnif font_options_copy(options)

  @spec font_options_status(font_options_handle()) :: Cairo.status()
  defnif font_options_status(options)

  @spec font_options_merge(font_options_handle(), font_options_handle()) :: :ok
  defnif font_options_merge(options, other)

  @spec font_options_set_antialias(font_options_handle(), Cairo.antialias()) :: :ok
  defnif font_options_set_antialias(options, antialias)

  @spec font_options_get_antialias(font_options_handle()) :: Cairo.antialias()
  defnif font_options_get_antialias(options)

  @spec font_options_set_subpixel_order(font_options_handle(), FontOptions.subpixel_order()) :: :ok
  defnif font_options_set_subpixel_order(options, subpixel_order)

  @spec font_options_get_subpixel_order(font_options_handle()) :: FontOptions.subpixel_order()
  defnif font_options_get_subpixel_order(options)

  @spec font_options_set_hint_style(font_options_handle(), FontOptions.hint_style()) :: :ok
  defnif font_options_set_hint_style(options, hint_style)

  @spec font_options_get_hint_style(font_options_handle()) :: FontOptions.hint_style()
  defnif font_options_get_hint_style(font_options_handle())

  @spec font_options_set_hint_metrics(font_options_handle(), FontOptions.font_metrics()) :: :ok
  defnif font_options_set_hint_metrics(options, font_metrics)

  @spec font_options_get_hint_metrics(font_options_handle()) :: FontOptions.font_metrics()
  defnif font_options_get_hint_metrics(options)

  @spec font_options_set_variations(font_options_handle(), binary()) :: :ok
  defnif font_options_set_variations(options, variations)

  @spec font_options_get_variations(font_options_handle()) :: binary()
  defnif font_options_get_variations(options)

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

  @spec image_surface_create_from_png(binary()) :: surface_handle()
  defnif image_surface_create_from_png(data)

  @spec surface_write_to_png(surface_handle()) :: iodata()
  defnif surface_write_to_png(surface)

  #
  # PANGO FONT DESCRIPTIONS
  #

  @spec pango_font_desc_from_string(binary()) :: pango_font_desc_handle()
  defnif pango_font_desc_from_string(str)

  #
  # PANGO LAYOUTS
  #

  @spec pango_layout_set_ellipsize(pango_layout_handle(), Pango.ellipsize_mode()) :: :ok
  defnif pango_layout_set_ellipsize(layout, ellipsize)

  @spec pango_layout_set_font_description(pango_layout_handle(), pango_font_desc_handle()) :: :ok
  defnif pango_layout_set_font_description(layout, font_desc)

  @spec pango_layout_set_height(pango_layout_handle(), number()) :: :ok
  defnif pango_layout_set_height(layout, height)

  @spec pango_layout_set_indent(pango_layout_handle(), number()) :: :ok
  defnif pango_layout_set_indent(layout, indent)

  @spec pango_layout_set_justify(pango_layout_handle(), boolean()) :: :ok
  defnif pango_layout_set_justify(layout, justify)

  # pango_layout_set_line_spacing

  @spec pango_layout_set_markup(pango_layout_handle(), binary()) :: :ok
  defnif pango_layout_set_markup(layout, markup)

  # pango_layout_set_markup_with_accel

  @spec pango_layout_set_single_paragraph_mode(pango_layout_handle(), boolean()) :: :ok
  defnif pango_layout_set_single_paragraph_mode(layout, setting)

  # pango_layout_set_spacing
  # pango_layout_set_tabs

  @spec pango_layout_set_text(pango_layout_handle(), binary()) :: :ok
  defnif pango_layout_set_text(layout, text)

  @spec pango_layout_set_width(pango_layout_handle(), number()) :: :ok
  defnif pango_layout_set_width(layout, width)

  @spec pango_layout_set_wrap(pango_layout_handle(), Pango.wrap_mode()) :: :ok
  defnif pango_layout_set_wrap(layout, wrap)

  # pango_layout_xy_to_index

  #
  # PANGO CAIRO
  #

  # pc_context_get_font_options
  # pc_context_get_resolution
  # pc_context_get_shape_renderer
  # pc_context_set_font_options
  # pc_context_set_resolution
  # pc_context_set_shape_renderer
  # pc_create_context

  @spec pc_create_layout(cairo_handle()) :: pango_layout_handle()
  defnif pc_create_layout(cr)

  @spec pc_error_underline_path(cairo_handle(), number(), number(), number(), number()) :: :ok
  defnif pc_error_underline_path(cr, x, y, width, height)

  # pc_glyph_string_path
  # pc_layout_line_path

  @spec pc_layout_path(cairo_handle(), pango_layout_handle()) :: :ok
  defnif pc_layout_path(cr, layout)

  @spec pc_show_error_underline(cairo_handle(), number(), number(), number(), number()) :: :ok
  defnif pc_show_error_underline(cr, x, y, width, height)

  # pc_show_glyph_item
  # pc_show_glyph_string

  @spec pc_show_layout(cairo_handle(), pango_layout_handle()) :: :ok
  defnif pc_show_layout(cr, layout)

  # pc_show_layout_line
  # pc_update_context

  @spec pc_update_layout(cairo_handle(), pango_layout_handle()) :: :ok
  defnif pc_update_layout(cr, layout)
end
