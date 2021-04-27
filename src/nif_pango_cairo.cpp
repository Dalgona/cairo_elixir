#include "include/nif_pango_cairo.h"

/* NIF_DECL(nif_pc_context_get_font_options) */

/* NIF_DECL(nif_pc_context_get_resolution) */

/* NIF_DECL(nif_pc_context_get_shape_renderer) */

/* NIF_DECL(nif_pc_context_set_font_options) */

/* NIF_DECL(nif_pc_context_set_resolution) */

/* NIF_DECL(nif_pc_context_set_shape_renderer) */

NIF_DECL(nif_pc_create_layout)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  return nif_resource(env, pango_cairo_create_layout(cr)).term;
}

NIF_DECL(nif_pc_error_underline_path)
{
  ENSURE_ARGC(5)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x;
  double y;
  double width;
  double height;

  get_values(env, argv, &x, &y, &width, &height);
  pango_cairo_error_underline_path(cr, x, y, width, height);

  return g_atom_ok;
}

/* NIF_DECL(nif_pc_glyph_string_path) */

/* NIF_DECL(nif_pc_layout_line_path) */

NIF_DECL(nif_pc_layout_path)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 1)

  pango_cairo_layout_path(cr, layout);

  return g_atom_ok;
}

NIF_DECL(nif_pc_show_error_underline)
{
  ENSURE_ARGC(5)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)

  double x;
  double y;
  double width;
  double height;

  get_values(env, argv, &x, &y, &width, &height);
  pango_cairo_show_error_underline(cr, x, y, width, height);

  return g_atom_ok;
}

/* NIF_DECL(nif_pc_show_glyph_item) */

/* NIF_DECL(nif_pc_show_glyph_string) */

NIF_DECL(nif_pc_show_layout)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 1)

  pango_cairo_show_layout(cr, layout);

  return g_atom_ok;
}

/* NIF_DECL(nif_pc_show_layout_line) */

/* NIF_DECL(nif_pc_update_context) */

NIF_DECL(nif_pc_update_layout)
{
  ENSURE_ARGC(2)
  REQUIRE_OBJECT(cairo_t, cairo, cr, 0)
  REQUIRE_OBJECT(PangoLayout, pango_layout, layout, 1)

  pango_cairo_update_layout(cr, layout);

  return g_atom_ok;
}
