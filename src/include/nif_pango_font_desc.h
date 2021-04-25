#pragma once
#ifndef CAIRO_ELIXIR_NIF_PANGO_FONT_DESC_H
#define CAIRO_ELIXIR_NIF_PANGO_FONT_DESC_H

#include <pango/pango-font.h>
#include "nif_common.h"

#define PANGO_FONT_DESC_NIFS \
  USE_NIF(pango_font_desc_from_string, 1)

#define USE_NIF(name, arity) NIF_DECL(nif_##name);
PANGO_FONT_DESC_NIFS
#undef USE_NIF

#endif
