#include "include/nif_paths.h"

NIF_DECL(nif_has_current_point)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  return cairo_has_current_point(res_cr.obj) ? g_atom_true : g_atom_false;
}

NIF_DECL(nif_get_current_point)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;
  double x;
  double y;

  get_values(env, argv, res_cr);
  cairo_get_current_point(res_cr.obj, &x, &y);

  return make_vec2(env, x, y);
}

NIF_DECL(nif_new_path)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_new_path(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_new_sub_path)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_new_sub_path(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_close_path)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);
  cairo_close_path(res_cr.obj);

  return g_atom_ok;
}

NIF_DECL(nif_arc)
{
  ENSURE_ARGC(5)

  nif_resource<cairo_t> res_cr;
  vec2_t center;
  double radius;
  double angle1;
  double angle2;

  get_values(env, argv, res_cr, center, radius, angle1, angle2);
  cairo_arc(res_cr.obj, center.first, center.second, radius, angle1, angle2);

  return g_atom_ok;
}

NIF_DECL(nif_arc_negative)
{
  ENSURE_ARGC(5)

  nif_resource<cairo_t> res_cr;
  vec2_t center;
  double radius;
  double angle1;
  double angle2;

  get_values(env, argv, res_cr, center, radius, angle1, angle2);
  cairo_arc_negative(res_cr.obj, center.first, center.second, radius, angle1, angle2);

  return g_atom_ok;
}

NIF_DECL(nif_curve_to)
{
  ENSURE_ARGC(4)

  nif_resource<cairo_t> res_cr;
  vec2_t pt1;
  vec2_t pt2;
  vec2_t pt3;

  get_values(env, argv, res_cr, pt1, pt2, pt3);
  cairo_curve_to(res_cr.obj, pt1.first, pt1.second, pt2.first, pt2.second, pt3.first, pt3.second);

  return g_atom_ok;
}

NIF_DECL(nif_line_to)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  vec2_t pt;

  get_values(env, argv, res_cr, pt);
  cairo_line_to(res_cr.obj, pt.first, pt.second);

  return g_atom_ok;
}

NIF_DECL(nif_move_to)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  vec2_t pt;

  get_values(env, argv, res_cr, pt);
  cairo_move_to(res_cr.obj, pt.first, pt.second);

  return g_atom_ok;
}

NIF_DECL(nif_rectangle)
{
  ENSURE_ARGC(5)

  nif_resource<cairo_t> res_cr;
  double x;
  double y;
  double width;
  double height;

  get_values(env, argv, res_cr, x, y, width, height);
  cairo_rectangle(res_cr.obj, x, y, width, height);

  return g_atom_ok;
}

NIF_DECL(nif_text_path)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  std::string utf8;

  get_values(env, argv, res_cr, utf8);
  cairo_text_path(res_cr.obj, utf8.c_str());

  return g_atom_ok;
}

NIF_DECL(nif_rel_curve_to)
{
  ENSURE_ARGC(4)

  nif_resource<cairo_t> res_cr;
  vec2_t pt1;
  vec2_t pt2;
  vec2_t pt3;

  get_values(env, argv, res_cr, pt1, pt2, pt3);
  cairo_rel_curve_to(res_cr.obj, pt1.first, pt1.second, pt2.first, pt2.second, pt3.first, pt3.second);

  return g_atom_ok;
}

NIF_DECL(nif_rel_line_to)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  vec2_t diff;

  get_values(env, argv, res_cr, diff);
  cairo_rel_line_to(res_cr.obj, diff.first, diff.second);

  return g_atom_ok;
}

NIF_DECL(nif_rel_move_to)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  vec2_t diff;

  get_values(env, argv, res_cr, diff);
  cairo_rel_move_to(res_cr.obj, diff.first, diff.second);

  return g_atom_ok;
}

NIF_DECL(nif_path_extents)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_t> res_cr;

  double x1;
  double y1;
  double x2;
  double y2;

  get_values(env, argv, res_cr);
  cairo_path_extents(res_cr.obj, &x1, &y1, &x2, &y2);

  return enif_make_tuple2(env, make_vec2(env, x1, y1), make_vec2(env, x2, y2));
}
