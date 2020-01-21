#include <cstring>

#include "nif_font_options.h"

NIF_DECL(nif_font_options_create)
{
  ENSURE_ARGC(0)

  return create_resource(env, g_res_type_font_options, cairo_font_options_create());
}

NIF_DECL(nif_font_options_copy)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  return create_resource(env, g_res_type_font_options, cairo_font_options_copy(options));
}

NIF_DECL(nif_font_options_status)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  return enum_to_atom<cairo_status_t>(env, cairo_font_options_status(options));
}

NIF_DECL(nif_font_options_merge)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  {
    REQUIRE_OBJECT(cairo_font_options_t, font_options, other, 1);
    cairo_font_options_merge(options, other);
  }

  return g_atom_ok;
}

NIF_DECL(nif_font_options_set_antialias)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  cairo_antialias_t antialias;

  if (!enum_from_atom(env, argv[1], &antialias))
  {
    return enif_make_badarg(env);
  }

  cairo_font_options_set_antialias(options, antialias);

  return g_atom_ok;
}

NIF_DECL(nif_font_options_get_antialias)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  return enum_to_atom(env, cairo_font_options_get_antialias(options));
}

NIF_DECL(nif_font_options_set_subpixel_order)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  cairo_subpixel_order_t subpixel_order;

  if (!enum_from_atom(env, argv[1], &subpixel_order))
  {
    return enif_make_badarg(env);
  }

  cairo_font_options_set_subpixel_order(options, subpixel_order);

  return g_atom_ok;
}

NIF_DECL(nif_font_options_get_subpixel_order)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  return enum_to_atom(env, cairo_font_options_get_subpixel_order(options));
}

NIF_DECL(nif_font_options_set_hint_style)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  cairo_hint_style_t hint_style;

  if (!enum_from_atom(env, argv[1], &hint_style))
  {
    return enif_make_badarg(env);
  }

  cairo_font_options_set_hint_style(options, hint_style);

  return g_atom_ok;
}

NIF_DECL(nif_font_options_get_hint_style)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  return enum_to_atom(env, cairo_font_options_get_hint_style(options));
}

NIF_DECL(nif_font_options_set_hint_metrics)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  cairo_hint_metrics_t hint_metrics;

  if (!enum_from_atom(env, argv[1], &hint_metrics))
  {
    return enif_make_badarg(env);
  }

  cairo_font_options_set_hint_metrics(options, hint_metrics);

  return g_atom_ok;
}

NIF_DECL(nif_font_options_get_hint_metrics)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  return enum_to_atom(env, cairo_font_options_get_hint_metrics(options));
}

NIF_DECL(nif_font_options_set_variations)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  ErlNifBinary bin;

  if (!enif_inspect_binary(env, argv[1], &bin))
  {
    return enif_make_badarg(env);
  }

  char *variations = new char[bin.size + 1];

  memcpy(variations, bin.data, bin.size);

  variations[bin.size] = 0;

  cairo_font_options_set_variations(options, (const char *)variations);

  delete[] variations;

  return g_atom_ok;
}

NIF_DECL(nif_font_options_get_variations)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_font_options_t, font_options, options, 0);

  auto variations = cairo_font_options_get_variations(options);

  if (variations == nullptr)
  {
    return g_atom_nil;
  }
  else
  {
    auto len = strlen(variations);
    ErlNifBinary bin;

    enif_alloc_binary(len, &bin);
    memcpy(bin.data, variations, len);

    return enif_make_binary(env, &bin);
  }
}
