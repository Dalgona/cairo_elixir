#include <cstring>

#include "include/nif_common.h"

#include "include/nif_cairo.h"
#include "include/nif_paths.h"
#include "include/nif_font_options.h"
#include "include/nif_surfaces.h"
#include "include/nif_image_surfaces.h"
#include "include/nif_png_support.h"
#include "include/nif_pango_font_desc.h"
#include "include/nif_pango_layout.h"
#include "include/nif_pango_cairo.h"

int load(ErlNifEnv *env, void **priv, ERL_NIF_TERM load_info)
{
  nif_resource<cairo_t>::_initialize(env, "cairo_t");
  nif_resource<cairo_pattern_t>::_initialize(env, "cairo_pattern_t");
  nif_resource<cairo_surface_t>::_initialize(env, "cairo_surface_t");
  nif_resource<cairo_font_options_t>::_initialize(env, "cairo_font_options_t");
  nif_resource<PangoFontDescription>::_initialize(env, "PangoFontDescription");
  nif_resource<PangoLayout>::_initialize(env, "PangoLayout");

#define ATOM_DECL(a, _) g_atom_##a = enif_make_atom(env, #a);
  ATOMS
#undef ATOM_DECL

  return 0;
}

ErlNifFunc nif_funcs[] = {
#define USE_NIF(name, arity) { #name, arity, nif_##name, 0 },
  CAIRO_NIFS
  PATH_NIFS
  FONT_OPTIONS_NIFS
  SURFACE_NIFS
  IMAGE_SURFACE_NIFS
  PNG_SUPPORT_NIFS
  PANGO_FONT_DESC_NIFS
  PANGO_LAYOUT_NIFS
  PANGO_CAIRO_NIFS
#undef USE_NIF
};

ERL_NIF_INIT(Elixir.Cairo.NativeFunctions, nif_funcs, load, NULL, NULL, NULL)
