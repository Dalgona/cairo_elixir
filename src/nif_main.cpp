#include <cstring>

#include "nif_common.h"

#include "nif_cairo.h"
#include "nif_surfaces.h"
#include "nif_image_surfaces.h"

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

#define ATOM_DECL(a, _) g_atom_##a = enif_make_atom(env, #a);
  ATOMS
#undef ATOM_DECL

  return 0;
}


ErlNifFunc nif_funcs[] = {
#define USE_NIF(name, arity) { #name, arity, nif_##name, 0 },
  CAIRO_NIFS
  SURFACE_NIFS
  IMAGE_SURFACE_NIFS
#undef USE_NIF
};

ERL_NIF_INIT(Elixir.Cairo.NativeFunctions, nif_funcs, load, NULL, NULL, NULL)
