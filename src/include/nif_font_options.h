#pragma once
#ifndef CAIRO_ELIXIR_NIF_FONT_OPTIONS_H
#define CAIRO_ELIXIR_NIF_FONT_OPTIONS_H

#include "nif_common.h"

#define FONT_OPTIONS_NIFS \
  USE_NIF(font_options_create, 0) \
  USE_NIF(font_options_copy, 1) \
  USE_NIF(font_options_status, 1) \
  USE_NIF(font_options_merge, 2) \
  USE_NIF(font_options_set_antialias, 2) \
  USE_NIF(font_options_get_antialias, 1) \
  USE_NIF(font_options_set_subpixel_order, 2) \
  USE_NIF(font_options_get_subpixel_order, 1) \
  USE_NIF(font_options_set_hint_style, 2) \
  USE_NIF(font_options_get_hint_style, 1) \
  USE_NIF(font_options_set_hint_metrics, 2) \
  USE_NIF(font_options_get_hint_metrics, 1) \
  USE_NIF(font_options_set_variations, 2) \
  USE_NIF(font_options_get_variations, 1)

#define USE_NIF(name, arity) NIF_DECL(nif_##name);
FONT_OPTIONS_NIFS
#undef USE_NIF

#endif
