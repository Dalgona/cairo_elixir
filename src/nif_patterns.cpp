#include "include/nif_patterns.h"

/* NIF_DECL(nif_pattern_add_color_stop_rgb) */

/* NIF_DECL(nif_pattern_add_color_stop_rgba) */

/* NIF_DECL(nif_pattern_get_color_stop_count) */

/* NIF_DECL(nif_pattern_get_color_stop_rgba) */

NIF_DECL(nif_pattern_create_rgb)
{
  ENSURE_ARGC(3)

  double red;
  double green;
  double blue;

  get_values(env, argv, red, green, blue);

  return nif_resource(env, cairo_pattern_create_rgb(red, green, blue)).term;
}

NIF_DECL(nif_pattern_create_rgba)
{
  ENSURE_ARGC(4)

  double red;
  double green;
  double blue;
  double alpha;

  get_values(env, argv, red, green, blue, alpha);

  return nif_resource(env, cairo_pattern_create_rgba(red, green, blue, alpha)).term;
}

/* NIF_DECL(nif_pattern_get_rgba) */

NIF_DECL(nif_pattern_create_for_surface)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;

  get_values(env, argv, res_surface);

  return nif_resource(env, cairo_pattern_create_for_surface(res_surface.obj)).term;
}

/* NIF_DECL(nif_pattern_get_surface) */

/* NIF_DECL(nif_pattern_create_linear) */

/* NIF_DECL(nif_pattern_get_linear_points) */

/* NIF_DECL(nif_pattern_create_radial) */

/* NIF_DECL(nif_pattern_get_radial_circles) */

/* NIF_DECL(nif_pattern_create_mesh) */

/* NIF_DECL(nif_mesh_pattern_begin_patch) */

/* NIF_DECL(nif_mesh_pattern_end_patch) */

/* NIF_DECL(nif_mesh_pattern_move_to) */

/* NIF_DECL(nif_mesh_pattern_line_to) */

/* NIF_DECL(nif_mesh_pattern_curve_to) */

/* NIF_DECL(nif_mesh_pattern_set_control_point) */

/* NIF_DECL(nif_mesh_pattern_set_corner_color_rgb) */

/* NIF_DECL(nif_mesh_pattern_set_corner_color_rgba) */

/* NIF_DECL(nif_mesh_pattern_get_patch_count) */

/* NIF_DECL(nif_mesh_pattern_get_path) */

/* NIF_DECL(nif_mesh_pattern_get_control_point) */

/* NIF_DECL(nif_mesh_pattern_get_corner_color_rgba) */

/* NIF_DECL(nif_pattern_reference) */

/* NIF_DECL(nif_pattern_destroy) */

NIF_DECL(nif_pattern_status)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_pattern_t> res_pattern;

  get_values(env, argv, res_pattern);

  return enum_to_atom(env, cairo_pattern_status(res_pattern.obj));
}

/* NIF_DECL(nif_pattern_set_extend) */

/* NIF_DECL(nif_pattern_get_extend) */

/* NIF_DECL(nif_pattern_set_filter) */

/* NIF_DECL(nif_pattern_get_filter) */

/* NIF_DECL(nif_pattern_set_matrix) */

/* NIF_DECL(nif_pattern_get_matrix) */

/* NIF_DECL(nif_pattern_get_type) */

/* NIF_DECL(nif_pattern_get_reference_count) */

/* NIF_DECL(nif_pattern_set_user_data) */

/* NIF_DECL(nif_pattern_get_user_data) */
