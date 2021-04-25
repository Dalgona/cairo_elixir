#pragma once
#ifndef CAIRO_ELIXIR_NIF_PANGO_CAIRO_H
#define CAIRO_ELIXIR_NIF_PANGO_CAIRO_H

#include <pango/pangocairo.h>
#include "nif_common.h"

#define PANGO_CAIRO_NIFS \
  /* USE_NIF(pc_context_get_font_options, ?) */ \
  /* USE_NIF(pc_context_get_resolution, ?) */ \
  /* USE_NIF(pc_context_get_shape_renderer, ?) */ \
  /* USE_NIF(pc_context_set_font_options, ?) */ \
  /* USE_NIF(pc_context_set_resolution, ?) */ \
  /* USE_NIF(pc_context_set_shape_renderer, ?) */ \
  /* USE_NIF(pc_create_context, ?) */ \
  USE_NIF(pc_create_layout, 1) \
  USE_NIF(pc_error_underline_path, 5) \
  /* USE_NIF(pc_glyph_string_path, ?) */ \
  /* USE_NIF(pc_layout_line_path, ?) */ \
  USE_NIF(pc_layout_path, 2) \
  USE_NIF(pc_show_error_underline, 5) \
  /* USE_NIF(pc_show_glyph_item, ?) */ \
  /* USE_NIF(pc_show_glyph_string, ?) */ \
  USE_NIF(pc_show_layout, 2) \
  /* USE_NIF(pc_show_layout_line, ?) */ \
  /* USE_NIF(pc_update_context, ?) */ \
  USE_NIF(pc_update_layout, 2)

#define USE_NIF(name, arity) NIF_DECL(nif_##name);
PANGO_CAIRO_NIFS
#undef USE_NIF

#endif
