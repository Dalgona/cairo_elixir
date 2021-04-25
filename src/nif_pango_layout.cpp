#include "include/nif_pango_layout.h"

NIF_DECL(nif_pango_layout_set_ellipsize)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 0)

  PangoEllipsizeMode ellipsize;

  if (!enum_from_atom(env, argv[1], &ellipsize))
  {
    return enif_make_badarg(env);
  }

  pango_layout_set_ellipsize(layout, ellipsize);

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_font_description)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 0)
  REQUIRE_OBJECT(PangoFontDescription, pango_font_description, font_desc, 1);

  pango_layout_set_font_description(layout, font_desc);

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_height)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 0)

  double height;

  get_values(env, argv, &height);
  pango_layout_set_height(layout, pango_units_from_double(height));

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_indent)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 0)

  double indent;

  get_values(env, argv, &indent);
  pango_layout_set_indent(layout, pango_units_from_double(indent));

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_justify)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 0)

  bool justify;

  get_values(env, argv, &justify);
  pango_layout_set_justify(layout, justify);

  return g_atom_ok;
}

// NIF_DECL(nif_pango_layout_set_line_spacing)

NIF_DECL(nif_pango_layout_set_markup)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 0)

  ErlNifBinary bin;

  if (!enif_inspect_binary(env, argv[1], &bin))
  {
    return enif_make_badarg(env);
  }

  pango_layout_set_markup(layout, (char *)bin.data, (int)bin.size);

  return g_atom_ok;
}

// NIF_DECL(nif_pango_layout_set_markup_with_accel)

NIF_DECL(nif_pango_layout_set_single_paragraph_mode)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 0)

  bool setting;

  get_values(env, argv, &setting);
  pango_layout_set_single_paragraph_mode(layout, setting);

  return g_atom_ok;
}

// NIF_DECL(nif_pango_layout_set_spacing)

// NIF_DECL(nif_pango_layout_set_tabs)

NIF_DECL(nif_pango_layout_set_text)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 0)

  ErlNifBinary bin;

  if (!enif_inspect_binary(env, argv[1], &bin))
  {
    return enif_make_badarg(env);
  }

  pango_layout_set_text(layout, (char *)bin.data, (int)bin.size);

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_width)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 0)

  double width;

  get_values(env, argv, &width);
  pango_layout_set_width(layout, pango_units_from_double(width));

  return g_atom_ok;
}

NIF_DECL(nif_pango_layout_set_wrap)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 0)

  PangoWrapMode wrap;

  if (!enum_from_atom(env, argv[1], &wrap))
  {
    return enif_make_badarg(env);
  }

  pango_layout_set_wrap(layout, wrap);

  return g_atom_ok;
}

// NIF_DECL(nif_pango_layout_xy_to_index)
