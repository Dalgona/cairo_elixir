#define CAIRO_ELIXIR_NIF_RESOURCE_TYPES_IMPL
#include "include/debug.h"
#include "include/resource_types.h"

template <> void _destroy<cairo_t>::call(cairo_t *obj)
{
  dbgprintf("\x1b[90mDestroying cairo_t @ %p, ref count: %d\x1b[m\r\n", obj, cairo_get_reference_count(obj));
  cairo_destroy(obj);
}

template <> void _destroy<cairo_surface_t>::call(cairo_surface_t *obj)
{
  dbgprintf("\x1b[90mDestroying cairo_surface_t @ %p, ref count: %d\x1b[m\r\n", obj, cairo_surface_get_reference_count(obj));
  cairo_surface_destroy(obj);
}

template <> void _destroy<cairo_font_options_t>::call(cairo_font_options_t *obj)
{
  dbgprintf("\x1b[90mDestroying cairo_surface_t @ %p\x1b[m\r\n", obj);
  cairo_font_options_destroy(obj);
}

template <> void _destroy<PangoFontDescription>::call(PangoFontDescription *obj)
{
  dbgprintf("\x1b[90mDestroying PangoFontDescription @ %p\x1b[m\r\n", obj);
  pango_font_description_free(obj);
}

template <> void _destroy<PangoLayout>::call(PangoLayout *obj)
{
  dbgprintf("\x1b[90mDestroying PangoLayout @ %p\x1b[m\r\n", obj);
  g_object_unref(obj);
}
