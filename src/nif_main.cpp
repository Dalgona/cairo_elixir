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
  g_res_type_cairo =
    enif_open_resource_type(
        env,
        nullptr,
        "cairo_t",
        resource_dtor<cairo_t>,
        ERL_NIF_RT_CREATE,
        nullptr
    );

  g_res_type_surface =
    enif_open_resource_type(
        env,
        nullptr,
        "cairo_surface_t",
        resource_dtor<cairo_surface_t>,
        ERL_NIF_RT_CREATE,
        nullptr
    );

  g_res_type_font_options =
    enif_open_resource_type(
        env,
        nullptr,
        "cairo_font_options_t",
        resource_dtor<cairo_font_options_t>,
        ERL_NIF_RT_CREATE,
        nullptr
    );

  g_res_type_pango_font_description =
    enif_open_resource_type(
        env,
        nullptr,
        "PangoFontDescription",
        resource_dtor<PangoFontDescription>,
        ERL_NIF_RT_CREATE,
        nullptr
    );

  g_res_type_pango_layout =
    enif_open_resource_type(
        env,
        nullptr,
        "PangoLayout",
        resource_dtor<PangoLayout>,
        ERL_NIF_RT_CREATE,
        nullptr
    );

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
