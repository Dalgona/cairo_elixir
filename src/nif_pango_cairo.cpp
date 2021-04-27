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

  nif_resource<cairo_t> res_cr;

  get_values(env, argv, res_cr);

  return nif_resource(env, pango_cairo_create_layout(res_cr.obj)).term;
}

NIF_DECL(nif_pc_error_underline_path)
{
  ENSURE_ARGC(5)

  nif_resource<cairo_t> res_cr;
  double x;
  double y;
  double width;
  double height;

  get_values(env, argv, res_cr, x, y, width, height);
  pango_cairo_error_underline_path(res_cr.obj, x, y, width, height);

  return g_atom_ok;
}

/* NIF_DECL(nif_pc_glyph_string_path) */

/* NIF_DECL(nif_pc_layout_line_path) */

NIF_DECL(nif_pc_layout_path)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  nif_resource<PangoLayout> res_layout;

  get_values(env, argv, res_cr, res_layout);
  pango_cairo_layout_path(res_cr.obj, res_layout.obj);

  return g_atom_ok;
}

NIF_DECL(nif_pc_show_error_underline)
{
  ENSURE_ARGC(5)

  nif_resource<cairo_t> res_cr;
  double x;
  double y;
  double width;
  double height;

  get_values(env, argv, res_cr, x, y, width, height);
  pango_cairo_show_error_underline(res_cr.obj, x, y, width, height);

  return g_atom_ok;
}

/* NIF_DECL(nif_pc_show_glyph_item) */

/* NIF_DECL(nif_pc_show_glyph_string) */

NIF_DECL(nif_pc_show_layout)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  nif_resource<PangoLayout> res_layout;

  get_values(env, argv, res_cr, res_layout);
  pango_cairo_show_layout(res_cr.obj, res_layout.obj);

  return g_atom_ok;
}

/* NIF_DECL(nif_pc_show_layout_line) */

/* NIF_DECL(nif_pc_update_context) */

NIF_DECL(nif_pc_update_layout)
{
  ENSURE_ARGC(2)

  nif_resource<cairo_t> res_cr;
  nif_resource<PangoLayout> res_layout;

  get_values(env, argv, res_cr, res_layout);
  pango_cairo_update_layout(res_cr.obj, res_layout.obj);

  return g_atom_ok;
}
