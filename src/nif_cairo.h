#include "nif_common.h"

#define CAIRO_NIFS \
  USE_NIF(create, 1) \
  USE_NIF(status, 1) \
  USE_NIF(save, 1) \
  USE_NIF(restore, 1) \
  /* USE_NIF(get_target, 1) */ \
  /* USE_NIF(push_group, 1) */ \
  /* USE_NIF(push_group_with_content, 2) */ \
  /* USE_NIF(pop_group, 1) */ \
  /* USE_NIF(pop_group_to_source, 1) */ \
  /* USE_NIF(get_group_target, 1) */ \
  USE_NIF(set_source_rgb, 4) \
  USE_NIF(set_source_rgba, 5) \
  /* USE_NIF(set_source, 2) */ \
  /* USE_NIF(set_source_surface, 4) */ \
  /* USE_NIF(get_source, 1) */ \
  USE_NIF(set_antialias, 2) \
  USE_NIF(get_antialias, 1) \
  USE_NIF(set_dash, 3) \
  USE_NIF(get_dash, 1) \
  USE_NIF(set_fill_rule, 2) \
  USE_NIF(get_fill_rule, 1) \
  USE_NIF(set_line_cap, 2) \
  USE_NIF(get_line_cap, 1) \
  USE_NIF(set_line_join, 2) \
  USE_NIF(get_line_join, 1) \
  USE_NIF(set_line_width, 2) \
  USE_NIF(get_line_width, 1) \
  USE_NIF(set_miter_limit, 2) \
  USE_NIF(get_miter_limit, 1) \
  /* USE_NIF(set_operator, 2) */ \
  /* USE_NIF(get_operator, 1) */ \
  USE_NIF(set_tolerance, 2) \
  USE_NIF(get_tolerance, 1) \
  USE_NIF(clip, 1) \
  USE_NIF(clip_preserve, 1) \
  USE_NIF(clip_extents, 1) \
  USE_NIF(in_clip, 3) \
  USE_NIF(reset_clip, 1) \
  /* USE_NIF(rectangle_list_destroy, 2) */ \
  /* USE_NIF(copy_clip_rectangle_list, 1) */ \
  USE_NIF(fill, 1) \
  USE_NIF(fill_preserve, 1) \
  USE_NIF(fill_extents, 1) \
  USE_NIF(in_fill, 3) \
  /* USE_NIF(mask, 2) */ \
  /* USE_NIF(mask_surface, 4) */ \
  USE_NIF(paint, 1) \
  USE_NIF(paint_with_alpha, 2) \
  USE_NIF(stroke, 1) \
  USE_NIF(stroke_preserve, 1) \
  USE_NIF(stroke_extents, 1) \
  USE_NIF(in_stroke, 3) \
  /* USE_NIF(copy_page, 1) */ \
  /* USE_NIF(show_page, 1) */ \
  /* USE_NIF(set_user_data, 4) */ \
  /* USE_NIF(get_user_data, 2) */

#define USE_NIF(name, arity) NIF_DECL(nif_##name);
CAIRO_NIFS
#undef USE_NIF
