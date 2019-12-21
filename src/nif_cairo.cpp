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

ErlNifFunc nif_funcs[] = {
  { "surface_create_similar", 4, nif_surface_create_similar, 0 },
  { "surface_create_similar_image", 4, nif_surface_create_similar_image, 0 },
  { "surface_create_for_rectangle", 5, nif_surface_create_for_rectangle, 0 },
  { "surface_get_content", 1, nif_surface_get_content, 0 },
  { "surface_mark_dirty", 1, nif_surface_mark_dirty, 0 },
  { "surface_mark_dirty_rectangle", 5, nif_surface_mark_dirty_rectangle, 0 },
  { "surface_set_device_offset", 3, nif_surface_set_device_offset, 0 },
  { "surface_get_device_offset", 1, nif_surface_get_device_offset, 0 },
  { "surface_set_device_scale", 3, nif_surface_set_device_scale, 0 },
  { "surface_get_device_scale", 1, nif_surface_get_device_scale, 0 },
  { "surface_set_fallback_resolution", 3, nif_surface_set_fallback_resolution, 0 },
  { "surface_get_fallback_resolution", 1, nif_surface_get_fallback_resolution, 0 },

  { "format_stride_for_width", 2, nif_format_stride_for_width, 0 },
  { "image_surface_create", 3, nif_image_surface_create, 0 },
  { "image_surface_create_for_data", 5, nif_image_surface_create_for_data, 0},
  { "image_surface_get_data", 1, nif_image_surface_get_data, 0 },
  { "image_surface_get_format", 1, nif_image_surface_get_format, 0},
  { "image_surface_get_width", 1, nif_image_surface_get_width, 0},
  { "image_surface_get_height", 1, nif_image_surface_get_height, 0},
  { "image_surface_get_stride", 1, nif_image_surface_get_stride, 0}
};

ERL_NIF_INIT(Elixir.Cairo.NativeFunctions, nif_funcs, load, NULL, NULL, NULL)
