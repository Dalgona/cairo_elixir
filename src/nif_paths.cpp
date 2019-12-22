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
  ENSURE_ARGC(6)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double xc;
  double yc;
  double radius;
  double angle1;
  double angle2;

  if (!get_number(env, argv[1], &xc)
      || !get_number(env, argv[2], &yc)
      || !get_number(env, argv[3], &radius)
      || !get_number(env, argv[4], &angle1)
      || !get_number(env, argv[5], &angle2))
  {
    return enif_make_badarg(env);
  }

  cairo_arc(cr, xc, yc, radius, angle1, angle2);

  return g_atom_ok;
}

NIF_DECL(nif_arc_negative)
{
  ENSURE_ARGC(6)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double xc;
  double yc;
  double radius;
  double angle1;
  double angle2;

  if (!get_number(env, argv[1], &xc)
      || !get_number(env, argv[2], &yc)
      || !get_number(env, argv[3], &radius)
      || !get_number(env, argv[4], &angle1)
      || !get_number(env, argv[5], &angle2))
  {
    return enif_make_badarg(env);
  }

  cairo_arc_negative(cr, xc, yc, radius, angle1, angle2);

  return g_atom_ok;
}

NIF_DECL(nif_curve_to)
{
  ENSURE_ARGC(7)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x1;
  double y1;
  double x2;
  double y2;
  double x3;
  double y3;

  if (!get_number(env, argv[1], &x1)
      || !get_number(env, argv[2], &y1)
      || !get_number(env, argv[3], &x2)
      || !get_number(env, argv[4], &y2)
      || !get_number(env, argv[5], &x3)
      || !get_number(env, argv[6], &y3))
  {
    return enif_make_badarg(env);
  }

  cairo_curve_to(cr, x1, y1, x2, y2, x3, y3);

  return g_atom_ok;
}

NIF_DECL(nif_line_to)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x;
  double y;

  if (!get_number(env, argv[1], &x) || !get_number(env, argv[2], &y))
  {
    return enif_make_badarg(env);
  }

  cairo_line_to(cr, x, y);

  return g_atom_ok;
}

NIF_DECL(nif_move_to)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x;
  double y;

  if (!get_number(env, argv[1], &x) || !get_number(env, argv[2], &y))
  {
    return enif_make_badarg(env);
  }

  cairo_move_to(cr, x, y);

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
  ENSURE_ARGC(7)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double dx1;
  double dy1;
  double dx2;
  double dy2;
  double dx3;
  double dy3;

  if (!get_number(env, argv[1], &dx1)
      || !get_number(env, argv[2], &dy1)
      || !get_number(env, argv[3], &dx2)
      || !get_number(env, argv[4], &dy2)
      || !get_number(env, argv[5], &dx3)
      || !get_number(env, argv[6], &dy3))
  {
    return enif_make_badarg(env);
  }

  cairo_rel_curve_to(cr, dx1, dy1, dx2, dy2, dx3, dy3);

  return g_atom_ok;
}

NIF_DECL(nif_rel_line_to)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double dx;
  double dy;

  if (!get_number(env, argv[1], &dx) || !get_number(env, argv[2], &dy))
  {
    return enif_make_badarg(env);
  }

  cairo_rel_line_to(cr, dx, dy);

  return g_atom_ok;
}

NIF_DECL(nif_rel_move_to)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double dx;
  double dy;

  if (!get_number(env, argv[1], &dx) || !get_number(env, argv[2], &dy))
  {
    return enif_make_badarg(env);
  }

  cairo_rel_move_to(cr, dx, dy);

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
