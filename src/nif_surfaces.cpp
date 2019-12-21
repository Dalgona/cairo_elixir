#include <cstring>

#include "nif_surfaces.h"

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
