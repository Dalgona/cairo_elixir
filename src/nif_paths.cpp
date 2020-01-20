#include "nif_paths.h"

NIF_DECL(nif_has_current_point)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  return cairo_has_current_point(cr) ? g_atom_true : g_atom_false;
}

NIF_DECL(nif_get_current_point)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x;
  double y;

  cairo_get_current_point(cr, &x, &y);

  return enif_make_tuple2(env, enif_make_double(env, x), enif_make_double(env, y));
}

NIF_DECL(nif_new_path)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_new_path(cr);

  return g_atom_ok;
}

NIF_DECL(nif_new_sub_path)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_new_sub_path(cr);

  return g_atom_ok;
}

NIF_DECL(nif_close_path)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_close_path(cr);

  return g_atom_ok;
}

NIF_DECL(nif_arc)
{
  ENSURE_ARGC(5)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  vec2_t center;
  double radius;
  double angle1;
  double angle2;

  if (!get_vec2(env, argv[1], &center)
      || !get_number(env, argv[2], &radius)
      || !get_number(env, argv[3], &angle1)
      || !get_number(env, argv[4], &angle2))
  {
    return enif_make_badarg(env);
  }

  cairo_arc(cr, center.first, center.second, radius, angle1, angle2);

  return g_atom_ok;
}

NIF_DECL(nif_arc_negative)
{
  ENSURE_ARGC(5)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  vec2_t center;
  double radius;
  double angle1;
  double angle2;

  if (!get_vec2(env, argv[1], &center)
      || !get_number(env, argv[2], &radius)
      || !get_number(env, argv[3], &angle1)
      || !get_number(env, argv[4], &angle2))
  {
    return enif_make_badarg(env);
  }

  cairo_arc_negative(cr, center.first, center.second, radius, angle1, angle2);

  return g_atom_ok;
}

NIF_DECL(nif_curve_to)
{
  ENSURE_ARGC(4)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  vec2_t pt1;
  vec2_t pt2;
  vec2_t pt3;

  if (!get_vec2(env, argv[1], &pt1)
      || !get_vec2(env, argv[2], &pt2)
      || !get_vec2(env, argv[3], &pt3))
  {
    return enif_make_badarg(env);
  }

  cairo_curve_to(cr, pt1.first, pt1.second, pt2.first, pt2.second, pt3.first, pt3.second);

  return g_atom_ok;
}

NIF_DECL(nif_line_to)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  vec2_t pt;

  if (!get_vec2(env, argv[1], &pt))
  {
    return enif_make_badarg(env);
  }

  cairo_line_to(cr, pt.first, pt.second);

  return g_atom_ok;
}

NIF_DECL(nif_move_to)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  vec2_t pt;

  if (!get_vec2(env, argv[1], &pt))
  {
    return enif_make_badarg(env);
  }

  cairo_move_to(cr, pt.first, pt.second);

  return g_atom_ok;
}

NIF_DECL(nif_rectangle)
{
  ENSURE_ARGC(5)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

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

  cairo_rectangle(cr, x, y, width, height);

  return g_atom_ok;
}

NIF_DECL(nif_text_path)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  ErlNifBinary utf8;

  if (!enif_inspect_binary(env, argv[1], &utf8))
  {
    return enif_make_badarg(env);
  }

  cairo_text_path(cr, (char *)utf8.data);
  enif_release_binary(&utf8);

  return g_atom_ok;
}

NIF_DECL(nif_rel_curve_to)
{
  ENSURE_ARGC(4)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  vec2_t pt1;
  vec2_t pt2;
  vec2_t pt3;

  if (!get_vec2(env, argv[1], &pt1)
      || !get_vec2(env, argv[2], &pt2)
      || !get_vec2(env, argv[3], &pt3))
  {
    return enif_make_badarg(env);
  }

  cairo_rel_curve_to(cr, pt1.first, pt1.second, pt2.first, pt2.second, pt3.first, pt3.second);

  return g_atom_ok;
}

NIF_DECL(nif_rel_line_to)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  vec2_t diff;

  if (!get_vec2(env, argv[1], &diff))
  {
    return enif_make_badarg(env);
  }

  cairo_rel_line_to(cr, diff.first, diff.second);

  return g_atom_ok;
}

NIF_DECL(nif_rel_move_to)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  vec2_t diff;

  if (!get_vec2(env, argv[1], &diff))
  {
    return enif_make_badarg(env);
  }

  cairo_rel_move_to(cr, diff.first, diff.second);

  return g_atom_ok;
}

NIF_DECL(nif_path_extents)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x1;
  double y1;
  double x2;
  double y2;

  cairo_path_extents(cr, &x1, &y1, &x2, &y2);

  return enif_make_tuple4(
      env,
      enif_make_double(env, x1),
      enif_make_double(env, y1),
      enif_make_double(env, x2),
      enif_make_double(env, y2)
  );
}
