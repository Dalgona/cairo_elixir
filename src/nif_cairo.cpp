#include <cstring>

#include "nif_cairo.h"

NIF_DECL(nif_create)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  cairo_t *cr = cairo_create(surface);
  cairo_t **resource = (cairo_t **)enif_alloc_resource(g_res_type_cairo, sizeof(cairo_t *));

  memcpy(resource, &cr, sizeof(cairo_t *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

NIF_DECL(nif_status)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  return enum_to_atom<cairo_status_t>(env, cairo_status(cr));
}

NIF_DECL(nif_save)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_save(cr);

  return g_atom_ok;
}

NIF_DECL(nif_restore)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_restore(cr);

  return g_atom_ok;
}

NIF_DECL(nif_set_source_rgb)
{
  ENSURE_ARGC(4)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double red;
  double green;
  double blue;

  if (!get_number(env, argv[1], &red)
      || !get_number(env, argv[2], &green)
      || !get_number(env, argv[3], &blue))
  {
    return enif_make_badarg(env);
  }

  cairo_set_source_rgb(cr, red, green, blue);

  return g_atom_ok;
}

NIF_DECL(nif_set_source_rgba)
{
  ENSURE_ARGC(5)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double red;
  double green;
  double blue;
  double alpha;

  if (!get_number(env, argv[1], &red)
      || !get_number(env, argv[2], &green)
      || !get_number(env, argv[3], &blue)
      || !get_number(env, argv[4], &alpha))
  {
    return enif_make_badarg(env);
  }

  cairo_set_source_rgba(cr, red, green, blue, alpha);

  return g_atom_ok;
}

NIF_DECL(nif_set_antialias)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_antialias_t antialias;

  if (!enum_from_atom<cairo_antialias_t>(env, argv[1], &antialias))
  {
    return enif_make_badarg(env);
  }

  cairo_set_antialias(cr, antialias);

  return g_atom_ok;
}

NIF_DECL(nif_get_antialias)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  return enum_to_atom<cairo_antialias_t>(env, cairo_get_antialias(cr));
}

NIF_DECL(nif_set_dash)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  unsigned int list_length;
  double dash_offset;
  ERL_NIF_TERM head;
  ERL_NIF_TERM tail = argv[1];

  if (!enif_get_list_length(env, argv[1], &list_length)
      || !get_number(env, argv[2], &dash_offset))
  {
    return enif_make_badarg(env);
  }

  double *dashes = new double[list_length];

  for (int i = 0; enif_get_list_cell(env, tail, &head, &tail); i++)
  {
    if (!get_number(env, head, dashes + i))
    {
      return enif_make_badarg(env);
    }
  }

  cairo_set_dash(cr, dashes, list_length, dash_offset);

  delete[] dashes;

  return g_atom_ok;
}

NIF_DECL(nif_get_dash)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  int dash_count = cairo_get_dash_count(cr);
  double *dashes = new double[dash_count];
  double dash_offset = 0;

  cairo_get_dash(cr, dashes, &dash_offset);

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
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_fill_rule_t fill_rule;

  if (!enum_from_atom<cairo_fill_rule_t>(env, argv[1], &fill_rule))
  {
    return enif_make_badarg(env);
  }

  cairo_set_fill_rule(cr, fill_rule);

  return g_atom_ok;
}

NIF_DECL(nif_get_fill_rule)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  return enum_to_atom<cairo_fill_rule_t>(env, cairo_get_fill_rule(cr));
}

NIF_DECL(nif_set_line_cap)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_line_cap_t line_cap;

  if (!enum_from_atom<cairo_line_cap_t>(env, argv[1], &line_cap))
  {
    return enif_make_badarg(env);
  }

  cairo_set_line_cap(cr, line_cap);

  return g_atom_ok;
}

NIF_DECL(nif_get_line_cap)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  return enum_to_atom<cairo_line_cap_t>(env, cairo_get_line_cap(cr));
}

NIF_DECL(nif_set_line_join)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_line_join_t line_join;

  if (!enum_from_atom<cairo_line_join_t>(env, argv[1], &line_join))
  {
    return enif_make_badarg(env);
  }

  cairo_set_line_join(cr, line_join);

  return g_atom_ok;
}

NIF_DECL(nif_get_line_join)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  return enum_to_atom<cairo_line_join_t>(env, cairo_get_line_join(cr));
}

NIF_DECL(nif_set_line_width)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double line_width;

  if (!get_number(env, argv[1], &line_width))
  {
    return enif_make_badarg(env);
  }

  cairo_set_line_width(cr, line_width);

  return g_atom_ok;
}

NIF_DECL(nif_get_line_width)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  return enif_make_double(env, cairo_get_line_width(cr));
}

NIF_DECL(nif_set_miter_limit)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double limit;

  if (!get_number(env, argv[1], &limit))
  {
    return enif_make_badarg(env);
  }

  cairo_set_miter_limit(cr, limit);

  return g_atom_ok;
}

NIF_DECL(nif_get_miter_limit)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  return enif_make_double(env, cairo_get_miter_limit(cr));
}

NIF_DECL(nif_set_tolerance)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double tolerance;

  if (!get_number(env, argv[1], &tolerance))
  {
    return enif_make_badarg(env);
  }

  cairo_set_tolerance(cr, tolerance);

  return g_atom_ok;
}

NIF_DECL(nif_get_tolerance)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  return enif_make_double(env, cairo_get_tolerance(cr));
}

NIF_DECL(nif_clip)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_clip(cr);

  return g_atom_ok;
}

NIF_DECL(nif_clip_preserve)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_clip_preserve(cr);

  return g_atom_ok;
}

NIF_DECL(nif_clip_extents)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x1;
  double y1;
  double x2;
  double y2;

  cairo_clip_extents(cr, &x1, &y1, &x2, &y2);

  return enif_make_tuple4(
      env,
      enif_make_double(env, x1),
      enif_make_double(env, y1),
      enif_make_double(env, x2),
      enif_make_double(env, y2)
  );
}

NIF_DECL(nif_in_clip)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x;
  double y;

  if (!get_number(env, argv[1], &x) || !get_number(env, argv[2], &y))
  {
    return enif_make_badarg(env);
  }

  return cairo_in_clip(cr, x, y) ? g_atom_true : g_atom_false;
}

NIF_DECL(nif_reset_clip)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_reset_clip(cr);

  return g_atom_ok;
}

NIF_DECL(nif_fill)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_fill(cr);

  return g_atom_ok;
}

NIF_DECL(nif_fill_preserve)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_fill_preserve(cr);

  return g_atom_ok;
}

NIF_DECL(nif_fill_extents)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x1;
  double y1;
  double x2;
  double y2;

  cairo_fill_extents(cr, &x1, &y1, &x2, &y2);

  return enif_make_tuple4(
      env,
      enif_make_double(env, x1),
      enif_make_double(env, y1),
      enif_make_double(env, x2),
      enif_make_double(env, y2)
  );
}

NIF_DECL(nif_in_fill)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x;
  double y;

  if (!get_number(env, argv[1], &x) || !get_number(env, argv[2], &y))
  {
    return enif_make_badarg(env);
  }

  return cairo_in_fill(cr, x, y) ? g_atom_true : g_atom_false;
}

NIF_DECL(nif_paint)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_paint(cr);

  return g_atom_ok;
}

NIF_DECL(nif_paint_with_alpha)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double alpha;

  if (!get_number(env, argv[1], &alpha))
  {
    return enif_make_badarg(env);
  }

  cairo_paint_with_alpha(cr, alpha);

  return g_atom_ok;
}

NIF_DECL(nif_stroke)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_stroke(cr);

  return g_atom_ok;
}

NIF_DECL(nif_stroke_preserve)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  cairo_stroke_preserve(cr);

  return g_atom_ok;
}

NIF_DECL(nif_stroke_extents)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x1;
  double y1;
  double x2;
  double y2;

  cairo_stroke_extents(cr, &x1, &y1, &x2, &y2);

  return enif_make_tuple4(
      env,
      enif_make_double(env, x1),
      enif_make_double(env, y1),
      enif_make_double(env, x2),
      enif_make_double(env, y2)
  );
}

NIF_DECL(nif_in_stroke)
{
  ENSURE_ARGC(3)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x;
  double y;

  if (!get_number(env, argv[1], &x) || !get_number(env, argv[2], &y))
  {
    return enif_make_badarg(env);
  }

  return cairo_in_stroke(cr, x, y) ? g_atom_true : g_atom_false;
}
