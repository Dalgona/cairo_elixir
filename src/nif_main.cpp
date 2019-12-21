#include <cstring>

#include "nif_common.h"

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

#define NIF(name, arity) { #name, arity, nif_##name, 0 }

ErlNifFunc nif_funcs[] = {
  NIF(surface_create_similar, 4),
  NIF(surface_create_similar_image, 4),
  NIF(surface_create_for_rectangle, 5),
  NIF(surface_status, 1),
  NIF(surface_finish, 1),
  NIF(surface_flush, 1),
  // NIF(surface_get_font_options, 1),
  NIF(surface_get_content, 1),
  NIF(surface_mark_dirty, 1),
  NIF(surface_mark_dirty_rectangle, 5),
  NIF(surface_set_device_offset, 3),
  NIF(surface_get_device_offset, 1),
  NIF(surface_set_device_scale, 3),
  NIF(surface_get_device_scale, 1),
  NIF(surface_set_fallback_resolution, 3),
  NIF(surface_get_fallback_resolution, 1),
  NIF(surface_get_type, 1),

  NIF(format_stride_for_width, 2),
  NIF(image_surface_create, 3),
  NIF(image_surface_create_for_data, 5),
  NIF(image_surface_get_data, 1),
  NIF(image_surface_get_format, 1),
  NIF(image_surface_get_width, 1),
  NIF(image_surface_get_height, 1),
  NIF(image_surface_get_stride, 1),
};

ERL_NIF_INIT(Elixir.Cairo.NativeFunctions, nif_funcs, load, NULL, NULL, NULL)
