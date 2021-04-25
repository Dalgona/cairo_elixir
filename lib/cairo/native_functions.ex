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

  defnif create(surface :: surface_handle()) :: cairo_handle()
  defnif status(cr :: cairo_handle()) :: Cairo.status()
  defnif save(cr :: cairo_handle()) :: :ok
  defnif restore(cr :: cairo_handle()) :: :ok

  # defnif get_target(cr)
  # defnif push_group(cr)
  # defnif push_group_with_content(cr, content)
  # defnif pop_group(cr)
  # defnif pop_group_to_source(cr)
  # defnif get_group_target(cr)

  defnif set_source_rgb(
           cr :: cairo_handle(),
           red :: number(),
           green :: number(),
           blue :: number()
         ) :: :ok

  defnif set_source_rgba(
           cr :: cairo_handle(),
           red :: number(),
           green :: number(),
           blue :: number(),
           alpha :: number()
         ) :: :ok

  # defnif set_source(cr, source)
  # defnif set_source_surface(cr, surface, x, y)
  # defnif get_source(cr)

  defnif set_antialias(cr :: cairo_handle(), antialias :: Cairo.antialias()) :: :ok
  defnif get_antialias(cr :: cairo_handle()) :: Cairo.antialias()
  defnif set_dash(cr :: cairo_handle(), dashes :: [number()], offset :: number()) :: :ok
  defnif get_dash(cr :: cairo_handle()) :: {[number()], number()}
  defnif set_fill_rule(cr :: cairo_handle(), fill_rule :: Cairo.fill_rule()) :: :ok
  defnif get_fill_rule(cr :: cairo_handle()) :: Cairo.fill_rule()
  defnif set_line_cap(cr :: cairo_handle(), line_cap :: Cairo.line_cap()) :: :ok
  defnif get_line_cap(cr :: cairo_handle()) :: Cairo.line_cap()
  defnif set_line_join(cr :: cairo_handle(), line_join :: Cairo.line_join()) :: :ok
  defnif get_line_join(cr :: cairo_handle()) :: Cairo.line_join()
  defnif set_line_width(cr :: cairo_handle(), width :: number()) :: :ok
  defnif get_line_width(cr :: cairo_handle()) :: number()
  defnif set_miter_limit(cr :: cairo_handle(), limit :: number()) :: :ok
  defnif get_miter_limit(cr :: cairo_handle()) :: number()

  # defnif set_operator(cr, op)
  # defnif get_operator(cr)

  defnif set_tolerance(cr :: cairo_handle(), tolerance :: number()) :: :ok
  defnif get_tolerance(cr :: cairo_handle()) :: number()
  defnif clip(cr :: cairo_handle()) :: :ok
  defnif clip_preserve(cr :: cairo_handle()) :: :ok
  defnif clip_extents(cr :: cairo_handle()) :: {Cairo.vec2(), Cairo.vec2()}
  defnif in_clip(cr :: cairo_handle(), pt :: Cairo.vec2()) :: boolean()
  defnif reset_clip(cr :: cairo_handle()) :: :ok

  # defnif rectangle_list_destroy(rectangle_list)
  # defnif copy_clip_rectangle_list(cr)

  defnif fill(cr :: cairo_handle()) :: :ok
  defnif fill_preserve(cr :: cairo_handle()) :: :ok
  defnif fill_extents(cr :: cairo_handle()) :: {Cairo.vec2(), Cairo.vec2()}
  defnif in_fill(cr :: cairo_handle(), pt :: Cairo.vec2()) :: boolean()

  # defnif mask(cr, pattern)
  # defnif mask_surface(cr, surface, surface_x, surface_y)

  defnif paint(cr :: cairo_handle()) :: :ok
  defnif paint_with_alpha(cr :: cairo_handle(), alpha :: number()) :: :ok
  defnif stroke(cr :: cairo_handle()) :: :ok
  defnif stroke_preserve(cr :: cairo_handle()) :: :ok
  defnif stroke_extents(cr :: cairo_handle()) :: {Cairo.vec2(), Cairo.vec2()}
  defnif in_stroke(cr :: cairo_handle(), pt :: Cairo.vec2()) :: boolean()

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

  defnif has_current_point(cr :: cairo_handle()) :: boolean()
  defnif get_current_point(cr :: cairo_handle()) :: Cairo.vec2()
  defnif new_path(cr :: cairo_handle()) :: :ok
  defnif new_sub_path(cr :: cairo_handle()) :: :ok
  defnif close_path(cr :: cairo_handle()) :: :ok

  defnif arc(
           cr :: cairo_handle(),
           center :: Cairo.vec2(),
           radius :: number(),
           angle1 :: number(),
           angle2 :: number()
         ) :: :ok

  defnif arc_negative(
           cr :: cairo_handle(),
           center :: Cairo.vec2(),
           radius :: number(),
           angle1 :: number(),
           angle2 :: number()
         ) :: :ok

  defnif curve_to(
           cr :: cairo_handle(),
           pt1 :: Cairo.vec2(),
           pt2 :: Cairo.vec2(),
           pt3 :: Cairo.vec2()
         ) :: :ok

  defnif line_to(cr :: cairo_handle(), pt :: Cairo.vec2()) :: :ok
  defnif move_to(cr :: cairo_handle(), pt :: Cairo.vec2()) :: :ok

  defnif rectangle(
           cr :: cairo_handle(),
           x :: number(),
           y :: number(),
           width :: number(),
           height :: number()
         ) :: :ok

  # defnif glyph_path(cr, glyphs)

  defnif text_path(cr :: cairo_handle(), utf8 :: binary()) :: :ok

  defnif rel_curve_to(
           cr :: cairo_handle(),
           pt1 :: Cairo.vec2(),
           pt2 :: Cairo.vec2(),
           pt3 :: Cairo.vec2()
         ) :: :ok

  defnif rel_line_to(cr :: cairo_handle(), diff :: Cairo.vec2()) :: :ok
  defnif rel_move_to(cr :: cairo_handle(), diff :: Cairo.vec2()) :: :ok
  defnif path_extents(cr :: cairo_handle()) :: {Cairo.vec2(), Cairo.vec2()}

  #
  # FONT OPTIONS
  #

  defnif font_options_create() :: font_options_handle()
  defnif font_options_copy(options :: font_options_handle()) :: font_options_handle()
  defnif font_options_status(options :: font_options_handle()) :: Cairo.status()

  defnif font_options_merge(options :: font_options_handle(), other :: font_options_handle()) ::
           :ok

  defnif font_options_set_antialias(
           options :: font_options_handle(),
           antialias :: Cairo.antialias()
         ) :: :ok

  defnif font_options_get_antialias(options :: font_options_handle()) :: Cairo.antialias()

  defnif font_options_set_subpixel_order(
           options :: font_options_handle(),
           subpixel_order :: FontOptions.subpixel_order()
         ) :: :ok

  defnif font_options_get_subpixel_order(options :: font_options_handle()) ::
           FontOptions.subpixel_order()

  defnif font_options_set_hint_style(
           options :: font_options_handle(),
           hint_style :: FontOptions.hint_style()
         ) :: :ok

  defnif font_options_get_hint_style(options :: font_options_handle()) :: FontOptions.hint_style()

  defnif font_options_set_hint_metrics(
           options :: font_options_handle(),
           font_metrics :: FontOptions.font_metrics()
         ) :: :ok

  defnif font_options_get_hint_metrics(options :: font_options_handle()) ::
           FontOptions.font_metrics()

  defnif font_options_set_variations(options :: font_options_handle(), variations :: binary()) ::
           :ok

  defnif font_options_get_variations(options :: font_options_handle()) :: binary()

  #
  # SURFACES
  #

  defnif surface_create_similar(
           surface :: surface_handle(),
           content :: Surface.content_type(),
           width :: integer(),
           height :: integer()
         ) :: surface_handle()

  defnif surface_create_similar_image(
           surface :: surface_handle(),
           format :: Cairo.format(),
           width :: integer(),
           height :: integer()
         ) :: surface_handle()

  defnif surface_create_for_rectangle(
           surface :: surface_handle(),
           x :: number(),
           y :: number(),
           width :: number(),
           height :: number()
         ) :: surface_handle()

  defnif surface_status(surface :: surface_handle()) :: Cairo.status()
  defnif surface_finish(surface :: surface_handle()) :: :ok
  defnif surface_flush(surface :: surface_handle()) :: :ok

  # surface_get_font_options(surface)

  defnif surface_get_content(surface :: surface_handle()) :: Surface.content_type()
  defnif surface_mark_dirty(surface :: surface_handle()) :: :ok

  defnif surface_mark_dirty_rectangle(
           surface :: surface_handle(),
           x :: integer(),
           y :: integer(),
           width :: integer(),
           height :: integer()
         ) :: :ok

  defnif surface_set_device_offset(surface :: surface_handle(), offset :: Cairo.vec2()) :: :ok
  defnif surface_get_device_offset(surface :: surface_handle()) :: Cairo.vec2()
  defnif surface_set_device_scale(surface :: surface_handle(), scale :: Cairo.vec2()) :: :ok
  defnif surface_get_device_scale(surface :: surface_handle()) :: Cairo.vec2()
  defnif surface_set_fallback_resolution(surface :: surface_handle(), ppi :: Cairo.vec2()) :: :ok
  defnif surface_get_fallback_resolution(surface :: surface_handle()) :: Cairo.vec2()
  defnif surface_get_type(surface :: surface_handle()) :: Surface.type()

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

  defnif format_stride_for_width(format :: Cairo.format(), width :: integer()) :: integer()

  defnif image_surface_create(format :: Cairo.format(), width :: integer(), height :: integer()) ::
           surface_handle()

  defnif image_surface_create_for_data(
           data :: binary(),
           format :: Cairo.format(),
           width :: integer(),
           height :: integer(),
           stride :: integer()
         ) :: surface_handle()

  defnif image_surface_get_data(surface :: surface_handle()) :: binary()
  defnif image_surface_get_format(surface :: surface_handle()) :: Cairo.format()
  defnif image_surface_get_width(surface :: surface_handle()) :: integer()
  defnif image_surface_get_height(surface :: surface_handle()) :: integer()
  defnif image_surface_get_stride(surface :: surface_handle()) :: integer()

  #
  # PNG SUPPORT
  #

  defnif image_surface_create_from_png(data :: binary()) :: surface_handle()
  defnif surface_write_to_png(surface :: surface_handle()) :: iodata()

  #
  # PANGO FONT DESCRIPTIONS
  #

  defnif pango_font_desc_from_string(str :: binary()) :: pango_font_desc_handle()

  #
  # PANGO LAYOUTS
  #

  defnif pango_layout_set_alignment(
           layout :: pango_layout_handle(),
           alignment :: Pango.alignment()
         ) :: :ok

  defnif pango_layout_set_ellipsize(
           layout :: pango_layout_handle(),
           ellipsize :: Pango.ellipsize_mode()
         ) :: :ok

  defnif pango_layout_set_font_description(
           layout :: pango_layout_handle(),
           font_desc :: pango_font_desc_handle()
         ) :: :ok

  defnif pango_layout_set_height(layout :: pango_layout_handle(), height :: number()) :: :ok
  # This NIF takes a value in Pango units directly.
  defnif pango_layout_set_height_pu(layout :: pango_layout_handle(), height :: integer()) :: :ok
  defnif pango_layout_set_indent(layout :: pango_layout_handle(), indent :: number()) :: :ok
  defnif pango_layout_set_justify(layout :: pango_layout_handle(), justify :: boolean()) :: :ok
  defnif pango_layout_set_line_spacing(layout :: pango_layout_handle(), factor :: number()) :: :ok
  defnif pango_layout_set_markup(layout :: pango_layout_handle(), markup :: binary()) :: :ok

  # pango_layout_set_markup_with_accel

  defnif pango_layout_set_single_paragraph_mode(
           layout :: pango_layout_handle(),
           setting :: boolean()
         ) :: :ok

  # pango_layout_set_spacing
  # pango_layout_set_tabs

  defnif pango_layout_set_text(layout :: pango_layout_handle(), text :: binary()) :: :ok
  defnif pango_layout_set_width(layout :: pango_layout_handle(), width :: number()) :: :ok
  defnif pango_layout_set_wrap(layout :: pango_layout_handle(), wrap :: Pango.wrap_mode()) :: :ok

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

  defnif pc_create_layout(cr :: cairo_handle()) :: pango_layout_handle()

  defnif pc_error_underline_path(
           cr :: cairo_handle(),
           x :: number(),
           y :: number(),
           width :: number(),
           height :: number()
         ) :: :ok

  # pc_glyph_string_path
  # pc_layout_line_path

  defnif pc_layout_path(cr :: cairo_handle(), layout :: pango_layout_handle()) :: :ok

  defnif pc_show_error_underline(
           cr :: cairo_handle(),
           x :: number(),
           y :: number(),
           width :: number(),
           height :: number()
         ) :: :ok

  # pc_show_glyph_item
  # pc_show_glyph_string

  defnif pc_show_layout(cr :: cairo_handle(), layout :: pango_layout_handle()) :: :ok

  # pc_show_layout_line
  # pc_update_context

  defnif pc_update_layout(cr :: cairo_handle(), layout :: pango_layout_handle()) :: :ok
end
