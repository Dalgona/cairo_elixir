#include <cstring>

#include "include/nif_font_options.h"

NIF_DECL(nif_font_options_create)
{
  ENSURE_ARGC(0)

  return nif_resource(env, cairo_font_options_create()).term;
}

NIF_DECL(nif_font_options_copy)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_font_options_t> res_options;

  get_values(env, argv, res_options);

  return nif_resource(env, cairo_font_options_copy(res_options.obj)).term;
}

NIF_DECL(nif_font_options_status)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_font_options_t> res_options;

  get_values(env, argv, res_options);

  return enum_to_atom<cairo_status_t>(env, cairo_font_options_status(res_options.obj));
}

NIF_DECL(nif_font_options_merge)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_font_options_t> res_options;
  nif_resource<cairo_font_options_t> res_other;

  get_values(env, argv, res_options, res_other);
  cairo_font_options_merge(res_options.obj, res_other.obj);

  return g_atom_ok;
}

NIF_DECL(nif_font_options_set_antialias)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_font_options_t> res_options;
  cairo_antialias_t antialias;

  get_values(env, argv, res_options);

  if (!enum_from_atom(env, argv[1], &antialias))
  {
    return enif_make_badarg(env);
  }

  cairo_font_options_set_antialias(res_options.obj, antialias);

  return g_atom_ok;
}

NIF_DECL(nif_font_options_get_antialias)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_font_options_t> res_options;

  get_values(env, argv, res_options);

  return enum_to_atom(env, cairo_font_options_get_antialias(res_options.obj));
}

NIF_DECL(nif_font_options_set_subpixel_order)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_font_options_t> res_options;
  cairo_subpixel_order_t subpixel_order;

  get_values(env, argv, res_options);

  if (!enum_from_atom(env, argv[1], &subpixel_order))
  {
    return enif_make_badarg(env);
  }

  cairo_font_options_set_subpixel_order(res_options.obj, subpixel_order);

  return g_atom_ok;
}

NIF_DECL(nif_font_options_get_subpixel_order)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_font_options_t> res_options;

  get_values(env, argv, res_options);

  return enum_to_atom(env, cairo_font_options_get_subpixel_order(res_options.obj));
}

NIF_DECL(nif_font_options_set_hint_style)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_font_options_t> res_options;
  cairo_hint_style_t hint_style;

  get_values(env, argv, res_options);

  if (!enum_from_atom(env, argv[1], &hint_style))
  {
    return enif_make_badarg(env);
  }

  cairo_font_options_set_hint_style(res_options.obj, hint_style);

  return g_atom_ok;
}

NIF_DECL(nif_font_options_get_hint_style)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_font_options_t> res_options;

  get_values(env, argv, res_options);

  return enum_to_atom(env, cairo_font_options_get_hint_style(res_options.obj));
}

NIF_DECL(nif_font_options_set_hint_metrics)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_font_options_t> res_options;
  cairo_hint_metrics_t hint_metrics;

  get_values(env, argv, res_options);

  if (!enum_from_atom(env, argv[1], &hint_metrics))
  {
    return enif_make_badarg(env);
  }

  cairo_font_options_set_hint_metrics(res_options.obj, hint_metrics);

  return g_atom_ok;
}

NIF_DECL(nif_font_options_get_hint_metrics)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_font_options_t> res_options;

  get_values(env, argv, res_options);

  return enum_to_atom(env, cairo_font_options_get_hint_metrics(res_options.obj));
}

NIF_DECL(nif_font_options_set_variations)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_font_options_t> res_options;
  ErlNifBinary bin;

  get_values(env, argv, res_options);

  if (!enif_inspect_binary(env, argv[1], &bin))
  {
    return enif_make_badarg(env);
  }

  char *variations = new char[bin.size + 1];

  memcpy(variations, bin.data, bin.size);

  variations[bin.size] = 0;

  cairo_font_options_set_variations(res_options.obj, (const char *)variations);

  delete[] variations;

  return g_atom_ok;
}

NIF_DECL(nif_font_options_get_variations)
{
  ENSURE_ARGC(1)

  nif_resource<cairo_font_options_t> res_options;

  get_values(env, argv, res_options);

  auto variations = cairo_font_options_get_variations(res_options.obj);

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
