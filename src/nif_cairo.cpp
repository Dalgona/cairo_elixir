#include <cstring>

#include "include/nif_cairo.h"

NIF_DECL(nif_create)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_surface_t> res_surface;

  get_values(env, argv, res_surface);

  return nif_resource(env, cairo_create(res_surface.obj)).term;
}

NIF_DECL(nif_status)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  return enum_to_atom<cairo_status_t>(env, cairo_status(res_cr.obj));
}

NIF_DECL(nif_save)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_save(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_restore)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_restore(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_set_source_rgb)
{
  ENSURE_ARGC(4)

  nif_resource<cairo_t> res_cr;
  double red;
  double green;
  double blue;

  get_values(env, argv, res_cr, red, green, blue);
  cairo_set_source_rgb(res_cr.obj, red, green, blue);

  return g_atom_ok;
}

NIF_DECL(nif_set_source_rgba)
{
  ENSURE_ARGC(5)

  nif_resource<cairo_t> res_cr;
  double red;
  double green;
  double blue;
  double alpha;

  get_values(env, argv, res_cr, red, green, blue, alpha);
  cairo_set_source_rgba(res_cr.obj, red, green, blue, alpha);

  return g_atom_ok;
}

NIF_DECL(nif_set_antialias)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  cairo_antialias_t antialias;

  get_values(env, argv, res_cr);

  if (!enum_from_atom<cairo_antialias_t>(env, argv[1], &antialias))
  {
    return enif_make_badarg(env);
  }

  cairo_set_antialias(res_cr.obj, antialias);

  return g_atom_ok;
}

NIF_DECL(nif_get_antialias)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  return enum_to_atom<cairo_antialias_t>(env, cairo_get_antialias(res_cr.obj));
}

NIF_DECL(nif_set_dash)
{
  ENSURE_ARGC(3)

  nif_resource<cairo_t> res_cr;
  std::vector<double> dashes;
  double dash_offset;

  get_values(env, argv, res_cr, dashes, dash_offset);
  cairo_set_dash(res_cr.obj, dashes.data(), dashes.size(), dash_offset);

  return g_atom_ok;
}

NIF_DECL(nif_get_dash)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  int dash_count = cairo_get_dash_count(res_cr.obj);
  double *dashes = new double[dash_count];
  double dash_offset = 0;

  cairo_get_dash(res_cr.obj, dashes, &dash_offset);

  ERL_NIF_TERM *list_items = new ERL_NIF_TERM[dash_count];

  for (int i = 0; i < dash_count; i++)
  {
    list_items[i] = enif_make_double(env, dashes[i]);
  }

  ERL_NIF_TERM list = enif_make_list_from_array(env, list_items, dash_count);

  delete[] list_items;
  delete[] dashes;

  return enif_make_tuple2(env, list, enif_make_double(env, dash_offset));
}

NIF_DECL(nif_set_fill_rule)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  cairo_fill_rule_t fill_rule;

  get_values(env, argv, res_cr);

  if (!enum_from_atom<cairo_fill_rule_t>(env, argv[1], &fill_rule))
  {
    return enif_make_badarg(env);
  }

  cairo_set_fill_rule(res_cr.obj, fill_rule);

  return g_atom_ok;
}

NIF_DECL(nif_get_fill_rule)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  return enum_to_atom<cairo_fill_rule_t>(env, cairo_get_fill_rule(res_cr.obj));
}

NIF_DECL(nif_set_line_cap)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  cairo_line_cap_t line_cap;

  get_values(env, argv, res_cr);

  if (!enum_from_atom<cairo_line_cap_t>(env, argv[1], &line_cap))
  {
    return enif_make_badarg(env);
  }

  cairo_set_line_cap(res_cr.obj, line_cap);

  return g_atom_ok;
}

NIF_DECL(nif_get_line_cap)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  return enum_to_atom<cairo_line_cap_t>(env, cairo_get_line_cap(res_cr.obj));
}

NIF_DECL(nif_set_line_join)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  cairo_line_join_t line_join;

  get_values(env, argv, res_cr);

  if (!enum_from_atom<cairo_line_join_t>(env, argv[1], &line_join))
  {
    return enif_make_badarg(env);
  }

  cairo_set_line_join(res_cr.obj, line_join);

  return g_atom_ok;
}

NIF_DECL(nif_get_line_join)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  return enum_to_atom<cairo_line_join_t>(env, cairo_get_line_join(res_cr.obj));
}

NIF_DECL(nif_set_line_width)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  double line_width;

  get_values(env, argv, res_cr, line_width);
  cairo_set_line_width(res_cr.obj, line_width);

  return g_atom_ok;
}

NIF_DECL(nif_get_line_width)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  return enif_make_double(env, cairo_get_line_width(res_cr.obj));
}

NIF_DECL(nif_set_miter_limit)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  double limit;

  get_values(env, argv, res_cr, limit);
  cairo_set_miter_limit(res_cr.obj, limit);

  return g_atom_ok;
}

NIF_DECL(nif_get_miter_limit)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  return enif_make_double(env, cairo_get_miter_limit(res_cr.obj));
}

NIF_DECL(nif_set_tolerance)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  double tolerance;

  get_values(env, argv, res_cr, tolerance);
  cairo_set_tolerance(res_cr.obj, tolerance);

  return g_atom_ok;
}

NIF_DECL(nif_get_tolerance)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  return enif_make_double(env, cairo_get_tolerance(res_cr.obj));
}

NIF_DECL(nif_clip)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_clip(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_clip_preserve)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_clip_preserve(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_clip_extents)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;
  double x1;
  double y1;
  double x2;
  double y2;

  get_values(env, argv, res_cr);
  cairo_clip_extents(res_cr.obj, &x1, &y1, &x2, &y2);

  return enif_make_tuple2(env, make_vec2(env, x1, y1), make_vec2(env, x2, y2));
}

NIF_DECL(nif_in_clip)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  vec2_t pt;

  get_values(env, argv, res_cr, pt);

  return cairo_in_clip(res_cr.obj, pt.first, pt.second) ? g_atom_true : g_atom_false;
}

NIF_DECL(nif_reset_clip)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_reset_clip(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_fill)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_fill(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_fill_preserve)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_fill_preserve(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_fill_extents)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;
  double x1;
  double y1;
  double x2;
  double y2;

  get_values(env, argv, res_cr);
  cairo_fill_extents(res_cr.obj, &x1, &y1, &x2, &y2);

  return enif_make_tuple2(env, make_vec2(env, x1, y1), make_vec2(env, x2, y2));
}

NIF_DECL(nif_in_fill)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  vec2_t pt;

  get_values(env, argv, res_cr, pt);

  return cairo_in_fill(res_cr.obj, pt.first, pt.second) ? g_atom_true : g_atom_false;
}

NIF_DECL(nif_paint)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_paint(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_paint_with_alpha)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  double alpha;

  get_values(env, argv, res_cr, alpha);
  cairo_paint_with_alpha(res_cr.obj, alpha);

  return g_atom_ok;
}

NIF_DECL(nif_stroke)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_stroke(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_stroke_preserve)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_stroke_preserve(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_stroke_extents)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;
  double x1;
  double y1;
  double x2;
  double y2;

  get_values(env, argv, res_cr);
  cairo_stroke_extents(res_cr.obj, &x1, &y1, &x2, &y2);

  return enif_make_tuple2(env, make_vec2(env, x1, y1), make_vec2(env, x2, y2));
}

NIF_DECL(nif_in_stroke)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  vec2_t pt;

  get_values(env, argv, res_cr, pt);

  return cairo_in_stroke(res_cr.obj, pt.first, pt.second) ? g_atom_true : g_atom_false;
}
