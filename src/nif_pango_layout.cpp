#include "include/nif_pango_layout.h"

NIF_DECL(nif_pango_layout_get_extents)
{
  ENSURE_ARGC(1)

  nif_resource<PangoLayout> res_layout;
  PangoRectangle extents;

  get_values(env, argv, res_layout);
  pango_layout_get_extents(res_layout.obj, nullptr, &extents);

  return enif_make_tuple2(
    env,
    make_vec2(env, pango_units_to_double(extents.x), pango_units_to_double(extents.y)),
    make_vec2(env, pango_units_to_double(extents.width), pango_units_to_double(extents.height))
  );
}

NIF_DECL(nif_pango_layout_set_alignment)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  PangoAlignment alignment;

  get_values(env, argv, res_layout);

  if (!enum_from_atom(env, argv[1], &alignment))
  {
    return enif_make_badarg(env);
  }

  pango_layout_set_alignment(res_layout.obj, alignment);

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_ellipsize)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  PangoEllipsizeMode ellipsize;

  get_values(env, argv, res_layout);

  if (!enum_from_atom(env, argv[1], &ellipsize))
  {
    return enif_make_badarg(env);
  }

  pango_layout_set_ellipsize(res_layout.obj, ellipsize);

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_font_description)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  nif_resource<PangoFontDescription> res_font_desc;

  get_values(env, argv, res_layout, res_font_desc);
  pango_layout_set_font_description(res_layout.obj, res_font_desc.obj);

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_height)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  double height;

  get_values(env, argv, res_layout, height);
  pango_layout_set_height(res_layout.obj, pango_units_from_double(height));

  return g_atom_ok;
}

// This NIF takes the value in Pango units directly.
NIF_DECL(nif_pango_layout_set_height_pu)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  int height;

  get_values(env, argv, res_layout, height);
  pango_layout_set_height(res_layout.obj, height);

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_indent)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  double indent;

  get_values(env, argv, res_layout, indent);
  pango_layout_set_indent(res_layout.obj, pango_units_from_double(indent));

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_justify)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  bool justify;

  get_values(env, argv, res_layout, justify);
  pango_layout_set_justify(res_layout.obj, justify);

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_line_spacing)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  double factor;

  get_values(env, argv, res_layout, factor);
  pango_layout_set_line_spacing(res_layout.obj, factor);

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_markup)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  std::string markup;

  get_values(env, argv, res_layout, markup);
  pango_layout_set_markup(res_layout.obj, markup.c_str(), markup.size());

  return g_atom_ok;
}

// NIF_DECL(nif_pango_layout_set_markup_with_accel)

NIF_DECL(nif_pango_layout_set_single_paragraph_mode)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  bool setting;

  get_values(env, argv, res_layout, setting);
  pango_layout_set_single_paragraph_mode(res_layout.obj, setting);

  return g_atom_ok;
}

// NIF_DECL(nif_pango_layout_set_spacing)

// NIF_DECL(nif_pango_layout_set_tabs)

NIF_DECL(nif_pango_layout_set_text)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  std::string text;

  get_values(env, argv, res_layout, text);
  pango_layout_set_text(res_layout.obj, text.c_str(), text.size());

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_width)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  double width;

  get_values(env, argv, res_layout, width);
  pango_layout_set_width(res_layout.obj, pango_units_from_double(width));

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_wrap)
{
  ENSURE_ARGC(2)

  nif_resource<PangoLayout> res_layout;
  PangoWrapMode wrap;

  get_values(env, argv, res_layout);

  if (!enum_from_atom(env, argv[1], &wrap))
  {
    return enif_make_badarg(env);
  }

  pango_layout_set_wrap(res_layout.obj, wrap);

  return g_atom_ok;
}

// NIF_DECL(nif_pango_layout_xy_to_index)
