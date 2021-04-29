#pragma once
#ifndef CAIRO_ELIXIR_NIF_PATTERNS_H
#define CAIRO_ELIXIR_NIF_PATTERNS_H

#include "nif_common.h"

#define PATTERN_NIFS \
  /* USE_NIF(pattern_add_color_stop_rgb, ?) */ \
  /* USE_NIF(pattern_add_color_stop_rgba, ?) */ \
  /* USE_NIF(pattern_get_color_stop_count, ?) */ \
  /* USE_NIF(pattern_get_color_stop_rgba, ?) */ \
  USE_NIF(pattern_create_rgb, 3) \
  USE_NIF(pattern_create_rgba, 4) \
  /* USE_NIF(pattern_get_rgba, ?) */ \
  USE_NIF(pattern_create_for_surface, 1) \
  /* USE_NIF(pattern_get_surface, ?) */ \
  /* USE_NIF(pattern_create_linear, ?) */ \
  /* USE_NIF(pattern_get_linear_points, ?) */ \
  /* USE_NIF(pattern_create_radial, ?) */ \
  /* USE_NIF(pattern_get_radial_circles, ?) */ \
  /* USE_NIF(pattern_create_mesh, ?) */ \
  /* USE_NIF(mesh_pattern_begin_patch, ?) */ \
  /* USE_NIF(mesh_pattern_end_patch, ?) */ \
  /* USE_NIF(mesh_pattern_move_to, ?) */ \
  /* USE_NIF(mesh_pattern_line_to, ?) */ \
  /* USE_NIF(mesh_pattern_curve_to, ?) */ \
  /* USE_NIF(mesh_pattern_set_control_point, ?) */ \
  /* USE_NIF(mesh_pattern_set_corner_color_rgb, ?) */ \
  /* USE_NIF(mesh_pattern_set_corner_color_rgba, ?) */ \
  /* USE_NIF(mesh_pattern_get_patch_count, ?) */ \
  /* USE_NIF(mesh_pattern_get_path, ?) */ \
  /* USE_NIF(mesh_pattern_get_control_point, ?) */ \
  /* USE_NIF(mesh_pattern_get_corner_color_rgba, ?) */ \
  /* USE_NIF(pattern_reference, ?) */ \
  /* USE_NIF(pattern_destroy, ?) */ \
  USE_NIF(pattern_status, 1) \
  USE_NIF(pattern_set_extend, 2) \
  USE_NIF(pattern_get_extend, 1) \
  USE_NIF(pattern_set_filter, 2) \
  USE_NIF(pattern_get_filter, 1) \
  /* USE_NIF(pattern_set_matrix, ?) */ \
  /* USE_NIF(pattern_get_matrix, ?) */ \
  USE_NIF(pattern_get_type, 1) \
  /* USE_NIF(pattern_get_reference_count, ?) */ \
  /* USE_NIF(pattern_set_user_data, ?) */ \
  /* USE_NIF(pattern_get_user_data, ?) */

#define USE_NIF(name, arity) NIF_DECL(nif_##name);
PATTERN_NIFS
#undef USE_NIF

#endif
