#include <cstring>

#include "include/nif_surfaces.h"

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

  return nif_resource(env, cairo_surface_create_similar(surface, content, width, height)).term;
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

  return nif_resource(env, cairo_surface_create_similar_image(surface, format, width, height)).term;
}

NIF_DECL(nif_surface_create_for_rectangle)
{
  ENSURE_ARGC(5)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  double x;
  double y;
  double width;
  double height;

  if (!get_number(env, argv[1], &x)
      || !get_number(env, argv[2], &y)
      || !get_number(env, argv[3], &width)
      || !get_number(env, argv[4], &height))
  {
    return enif_make_badarg(env);
  }

  return nif_resource(env, cairo_surface_create_for_rectangle(surface, x, y, width, height)).term;
}

NIF_DECL(nif_surface_status)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  return enum_to_atom<cairo_status_t>(env, cairo_surface_status(surface));
}

NIF_DECL(nif_surface_finish)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  cairo_surface_finish(surface);

  return g_atom_ok;
}

NIF_DECL(nif_surface_flush)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  cairo_surface_flush(surface);

  return g_atom_ok;
}

// NIF_DECL(nif_surface_get_font_options);

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

  get_values(env, argv, &x, &y, &width, &height);
  cairo_surface_mark_dirty_rectangle(surface, x, y, width, height);

  return g_atom_ok;
}

NIF_DECL(nif_surface_set_device_offset)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  vec2_t offset;

  if (!get_vec2(env, argv[1], &offset))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_set_device_offset(surface, offset.first, offset.second);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_device_offset)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  double x_offset;
  double y_offset;

  cairo_surface_get_device_offset(surface, &x_offset, &y_offset);

  return make_vec2(env, x_offset, y_offset);
}

NIF_DECL(nif_surface_set_device_scale)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  vec2_t scale;

  if (!get_vec2(env, argv[1], &scale))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_set_device_scale(surface, scale.first, scale.second);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_device_scale)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  double x_scale;
  double y_scale;

  cairo_surface_get_device_scale(surface, &x_scale, &y_scale);

  return make_vec2(env, x_scale, y_scale);
}

NIF_DECL(nif_surface_set_fallback_resolution)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  vec2_t ppi;

  if (!get_vec2(env, argv[1], &ppi))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_set_fallback_resolution(surface, ppi.first, ppi.second);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_fallback_resolution)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  double x_ppi;
  double y_ppi;

  cairo_surface_get_fallback_resolution(surface, &x_ppi, &y_ppi);

  return make_vec2(env, x_ppi, y_ppi);
}

NIF_DECL(nif_surface_get_type)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  return enum_to_atom<cairo_surface_type_t>(env, cairo_surface_get_type(surface));
}
