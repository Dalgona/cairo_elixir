defmodule Cairo do
  @moduledoc """
  Documentation for Cairo.
  """

  @type vec2 :: {number(), number()}
  @type point :: vec2
  @type matrix :: {vec2(), vec2(), vec2()}

  @type format :: :invalid | :argb32 | :rgb24 | :a8 | :a1 | :rgb16_565 | :rgb30

  @type status ::
          :success
          | :no_memory
          | :invalid_restore
          | :invalid_pop_group
          | :no_current_point
          | :invalid_matrix
          | :invalid_status
          | :null_pointer
          | :invalid_string
          | :invalid_path_data
          | :read_error
          | :write_error
          | :surface_finished
          | :surface_type_mismatch
          | :pattern_type_mismatch
          | :invalid_content
          | :invalid_format
          | :invalid_visual
          | :file_not_found
          | :invalid_dash
          | :invalid_dsc_comment
          | :invalid_index
          | :clip_not_representable
          | :temp_file_error
          | :invalid_stride
          | :font_type_mismatch
          | :user_font_immutable
          | :user_font_error
          | :negative_count
          | :invalid_clusters
          | :invalid_slant
          | :invalid_weight
          | :invalid_size
          | :user_font_not_implemented
          | :device_type_mismatch
          | :device_error
          | :invalid_mesh_construction
          | :device_finished
          | :jbig2_global_missing
          | :png_error
          | :freetype_error
          | :win32_gdi_error
          | :tag_error
          | :last_status

  @type antialias ::
          :default
          | :none
          | :gray
          | :subpixel
          | :fast
          | :good
          | :best

  @type fill_rule :: :winding | :even_odd

  @type line_cap :: :butt_cap | :round_cap | :square_cap

  @type line_join :: :miter_join | :round_join | :bevel_join
end
