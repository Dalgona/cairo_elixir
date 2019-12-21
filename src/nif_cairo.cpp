#include <unordered_map>
#include <string>
#include <cstring>

#include <cairo.h>
#include <erl_nif.h>

#include "atoms.h"
#include "macros.h"
#include "resource_types.h"

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

int get_number(ErlNifEnv *env, const ERL_NIF_TERM term, double *dest)
{
  int tmp;

  if (enif_get_double(env, term, dest))
  {
    return 1;
  }
  else if (enif_get_int(env, term, &tmp))
  {
    *dest = (double)tmp;

    return 1;
  }
  else
  {
    return 0;
  }
}

/************/
/* SURFACES */
/************/

NIF_DECL(nif_surface_create_similar)
{
  ENSURE_ARGC(4)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  cairo_content_t content;
  int width;
  int height;

  if (!enum_from_atom<cairo_content_t>(env, argv[1], &content)
      || !enif_get_int(env, argv[2], &width)
      || !enif_get_int(env, argv[3], &height))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_t *new_surface = cairo_surface_create_similar(surface, content, width, height);
  cairo_surface_t **resource = (cairo_surface_t **)enif_alloc_resource(g_res_type_surface, sizeof(cairo_surface_t *));

  memcpy(resource, &new_surface, sizeof(cairo_surface_t *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

NIF_DECL(nif_surface_create_similar_image)
{
  ENSURE_ARGC(4)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  cairo_format_t format;
  int width;
  int height;

  if (!enum_from_atom<cairo_format_t>(env, argv[1], &format)
      || !enif_get_int(env, argv[2], &width)
      || !enif_get_int(env, argv[3], &height))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_t *new_surface = cairo_surface_create_similar_image(surface, format, width, height);
  cairo_surface_t **resource = (cairo_surface_t **)enif_alloc_resource(g_res_type_surface, sizeof(cairo_surface_t *));

  memcpy(resource, &new_surface, sizeof(cairo_surface_t *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

NIF_DECL(nif_surface_create_for_rectangle)
{
  ENSURE_ARGC(5)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  cairo_format_t format;
  double x;
  double y;
  double width;
  double height;

  if (!enum_from_atom<cairo_format_t>(env, argv[1], &format)
      || !get_number(env, argv[2], &x)
      || !get_number(env, argv[3], &y)
      || !get_number(env, argv[4], &width)
      || !get_number(env, argv[5], &height))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_t *new_surface = cairo_surface_create_for_rectangle(surface, x, y, width, height);
  cairo_surface_t **resource = (cairo_surface_t **)enif_alloc_resource(g_res_type_surface, sizeof(cairo_surface_t *));

  memcpy(resource, &new_surface, sizeof(cairo_surface_t *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

NIF_DECL(nif_surface_get_content)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  return enum_to_atom<cairo_content_t>(env, cairo_surface_get_content(surface));
}

NIF_DECL(nif_surface_mark_dirty)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  cairo_surface_mark_dirty(surface);

  return g_atom_ok;
}

NIF_DECL(nif_surface_mark_dirty_rectangle)
{
  ENSURE_ARGC(5)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  int x;
  int y;
  int width;
  int height;

  if (!enif_get_int(env, argv[1], &x)
      || !enif_get_int(env, argv[2], &y)
      || !enif_get_int(env, argv[3], &width)
      || !enif_get_int(env, argv[4], &height))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_mark_dirty_rectangle(surface, x, y, width, height);

  return g_atom_ok;
}

NIF_DECL(nif_surface_set_device_offset)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  double x_offset;
  double y_offset;

  if (!get_number(env, argv[1], &x_offset) || !get_number(env, argv[2], &y_offset))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_set_device_offset(surface, x_offset, y_offset);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_device_offset)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  double x_offset;
  double y_offset;

  cairo_surface_get_device_offset(surface, &x_offset, &y_offset);

  return enif_make_tuple2(env, enif_make_double(env, x_offset), enif_make_double(env, y_offset));
}

NIF_DECL(nif_surface_set_device_scale)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  double x_scale;
  double y_scale;

  if (!get_number(env, argv[1], &x_scale) || !get_number(env, argv[2], &y_scale))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_set_device_scale(surface, x_scale, y_scale);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_device_scale)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  double x_scale;
  double y_scale;

  cairo_surface_get_device_scale(surface, &x_scale, &y_scale);

  return enif_make_tuple2(env, enif_make_double(env, x_scale), enif_make_double(env, y_scale));
}

NIF_DECL(nif_surface_set_fallback_resolution)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  double x_ppi;
  double y_ppi;

  if (!get_number(env, argv[1], &x_ppi) || !get_number(env, argv[2], &y_ppi))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_set_fallback_resolution(surface, x_ppi, y_ppi);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_fallback_resolution)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  double x_ppi;
  double y_ppi;

  cairo_surface_get_fallback_resolution(surface, &x_ppi, &y_ppi);

  return enif_make_tuple2(env, enif_make_double(env, x_ppi), enif_make_double(env, y_ppi));
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
