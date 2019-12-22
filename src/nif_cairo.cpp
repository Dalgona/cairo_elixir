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
