#include <cstring>

#include "include/nif_surfaces.h"

NIF_DECL(nif_surface_create_similar)
{
  ENSURE_ARGC(4)

  nif_resource<cairo_surface_t> res_surface;
  cairo_content_t content;
  int width;
  int height;

  get_values(env, argv, res_surface);

  if (!enum_from_atom<cairo_content_t>(env, argv[1], &content)
      || !enif_get_int(env, argv[2], &width)
      || !enif_get_int(env, argv[3], &height))
  {
    return enif_make_badarg(env);
  }

  return nif_resource(env, cairo_surface_create_similar(res_surface.obj, content, width, height)).term;
}

NIF_DECL(nif_surface_create_similar_image)
{
  ENSURE_ARGC(4)

  nif_resource<cairo_surface_t> res_surface;
  cairo_format_t format;
  int width;
  int height;

  get_values(env, argv, res_surface);

  if (!enum_from_atom<cairo_format_t>(env, argv[1], &format)
      || !enif_get_int(env, argv[2], &width)
      || !enif_get_int(env, argv[3], &height))
  {
    return enif_make_badarg(env);
  }

  return nif_resource(env, cairo_surface_create_similar_image(res_surface.obj, format, width, height)).term;
}

NIF_DECL(nif_surface_create_for_rectangle)
{
  ENSURE_ARGC(5)

  nif_resource<cairo_surface_t> res_surface;
  double x;
  double y;
  double width;
  double height;

  get_values(env, argv, res_surface, x, y, width, height);

  return nif_resource(env, cairo_surface_create_for_rectangle(res_surface.obj, x, y, width, height)).term;
}

NIF_DECL(nif_surface_status)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;

  get_values(env, argv, res_surface);

  return enum_to_atom<cairo_status_t>(env, cairo_surface_status(res_surface.obj));
}

NIF_DECL(nif_surface_finish)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;

  get_values(env, argv, res_surface);
  cairo_surface_finish(res_surface.obj);

  return g_atom_ok;
}

NIF_DECL(nif_surface_flush)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;

  get_values(env, argv, res_surface);
  cairo_surface_flush(res_surface.obj);

  return g_atom_ok;
}

// NIF_DECL(nif_surface_get_font_options);

NIF_DECL(nif_surface_get_content)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;

  get_values(env, argv, res_surface);

  return enum_to_atom<cairo_content_t>(env, cairo_surface_get_content(res_surface.obj));
}

NIF_DECL(nif_surface_mark_dirty)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;

  get_values(env, argv, res_surface);
  cairo_surface_mark_dirty(res_surface.obj);

  return g_atom_ok;
}

NIF_DECL(nif_surface_mark_dirty_rectangle)
{
  ENSURE_ARGC(5)

  nif_resource<cairo_surface_t> res_surface;
  int x;
  int y;
  int width;
  int height;

  get_values(env, argv, res_surface, x, y, width, height);
  cairo_surface_mark_dirty_rectangle(res_surface.obj, x, y, width, height);

  return g_atom_ok;
}

NIF_DECL(nif_surface_set_device_offset)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_surface_t> res_surface;
  vec2_t offset;

  get_values(env, argv, res_surface, offset);
  cairo_surface_set_device_offset(res_surface.obj, offset.first, offset.second);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_device_offset)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;
  double x_offset;
  double y_offset;

  get_values(env, argv, res_surface);
  cairo_surface_get_device_offset(res_surface.obj, &x_offset, &y_offset);

  return make_vec2(env, x_offset, y_offset);
}

NIF_DECL(nif_surface_set_device_scale)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_surface_t> res_surface;
  vec2_t scale;

  get_values(env, argv, res_surface, scale);
  cairo_surface_set_device_scale(res_surface.obj, scale.first, scale.second);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_device_scale)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;
  double x_scale;
  double y_scale;

  get_values(env, argv, res_surface);
  cairo_surface_get_device_scale(res_surface.obj, &x_scale, &y_scale);

  return make_vec2(env, x_scale, y_scale);
}

NIF_DECL(nif_surface_set_fallback_resolution)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_surface_t> res_surface;
  vec2_t ppi;

  get_values(env, argv, res_surface, ppi);
  cairo_surface_set_fallback_resolution(res_surface.obj, ppi.first, ppi.second);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_fallback_resolution)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;
  double x_ppi;
  double y_ppi;

  get_values(env, argv, res_surface);
  cairo_surface_get_fallback_resolution(res_surface.obj, &x_ppi, &y_ppi);

  return make_vec2(env, x_ppi, y_ppi);
}

NIF_DECL(nif_surface_get_type)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;

  get_values(env, argv, res_surface);

  return enum_to_atom<cairo_surface_type_t>(env, cairo_surface_get_type(res_surface.obj));
}
