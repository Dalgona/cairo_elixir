#pragma once
#ifndef CAIRO_ELIXIR_PANGO_LAYOUT_H
#define CAIRO_ELIXIR_PANGO_LAYOUT_H

#include <pango/pango-layout.h>
#include "nif_common.h"

#define PANGO_LAYOUT_NIFS \
  /* USE_NIF(pango_layout_context_changed, ?) */ \
  /* USE_NIF(pango_layout_copy, ?) */ \
  /* USE_NIF(pango_layout_get_alignment, ?) */ \
  /* USE_NIF(pango_layout_get_attributes, ?) */ \
  /* USE_NIF(pango_layout_get_auto_dir, ?) */ \
  /* USE_NIF(pango_layout_get_baseline, ?) */ \
  /* USE_NIF(pango_layout_get_character_count, ?) */ \
  /* USE_NIF(pango_layout_get_context, ?) */ \
  /* USE_NIF(pango_layout_get_cursor_pos, ?) */ \
  /* USE_NIF(pango_layout_get_direction, ?) */ \
  /* USE_NIF(pango_layout_get_ellipsize, ?) */ \
  /* USE_NIF(pango_layout_get_extents, ?) */ \
  /* USE_NIF(pango_layout_get_font_description, ?) */ \
  /* USE_NIF(pango_layout_get_height, ?) */ \
  /* USE_NIF(pango_layout_get_indent, ?) */ \
  /* USE_NIF(pango_layout_get_iter, ?) */ \
  /* USE_NIF(pango_layout_get_justify, ?) */ \
  /* USE_NIF(pango_layout_get_line, ?) */ \
  /* USE_NIF(pango_layout_get_line_count, ?) */ \
  /* USE_NIF(pango_layout_get_line_readonly, ?) */ \
  /* USE_NIF(pango_layout_get_line_spacing, ?) */ \
  /* USE_NIF(pango_layout_get_lines, ?) */ \
  /* USE_NIF(pango_layout_get_lines_readonly, ?) */ \
  /* USE_NIF(pango_layout_get_log_attrs, ?) */ \
  /* USE_NIF(pango_layout_get_log_attrs_readonly, ?) */ \
  /* USE_NIF(pango_layout_get_pixel_extents, ?) */ \
  /* USE_NIF(pango_layout_get_pixel_size, ?) */ \
  /* USE_NIF(pango_layout_get_serial, ?) */ \
  /* USE_NIF(pango_layout_get_single_paragraph_mode, ?) */ \
  /* USE_NIF(pango_layout_get_size, ?) */ \
  /* USE_NIF(pango_layout_get_spacing, ?) */ \
  /* USE_NIF(pango_layout_get_tabs, ?) */ \
  /* USE_NIF(pango_layout_get_text, ?) */ \
  /* USE_NIF(pango_layout_get_unknown_glyphs_count, ?) */ \
  /* USE_NIF(pango_layout_get_width, ?) */ \
  /* USE_NIF(pango_layout_get_wrap, ?) */ \
  /* USE_NIF(pango_layout_index_to_line_x, ?) */ \
  /* USE_NIF(pango_layout_index_to_pos, ?) */ \
  /* USE_NIF(pango_layout_is_ellipsized, ?) */ \
  /* USE_NIF(pango_layout_is_wrapped, ?) */ \
  /* USE_NIF(pango_layout_move_cursor_visually, ?) */ \
  USE_NIF(pango_layout_set_alignment, 2) \
  /* USE_NIF(pango_layout_set_attributes, ?) */ \
  /* USE_NIF(pango_layout_set_auto_dir, ?) */ \
  USE_NIF(pango_layout_set_ellipsize, 2) \
  USE_NIF(pango_layout_set_font_description, 2) \
  USE_NIF(pango_layout_set_height, 2) \
  USE_NIF(pango_layout_set_height_pu, 2) \
  USE_NIF(pango_layout_set_indent, 2) \
  USE_NIF(pango_layout_set_justify, 2) \
  USE_NIF(pango_layout_set_line_spacing, 2) \
  USE_NIF(pango_layout_set_markup, 2) \
  /* USE_NIF(pango_layout_set_markup_with_accel, ?) */ \
  USE_NIF(pango_layout_set_single_paragraph_mode, 2) \
  /* USE_NIF(pango_layout_set_spacing, ?) */ \
  /* USE_NIF(pango_layout_set_tabs, ?) */ \
  USE_NIF(pango_layout_set_text, 2) \
  USE_NIF(pango_layout_set_width, 2) \
  USE_NIF(pango_layout_set_wrap, 2) \
  /* USE_NIF(pango_layout_xy_to_index, ?) */ \

#define USE_NIF(name, arity) NIF_DECL(nif_##name);
PANGO_LAYOUT_NIFS
#undef USE_NIF

#endif
