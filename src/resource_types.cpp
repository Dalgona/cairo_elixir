#define CAIRO_ELIXIR_NIF_RESOURCE_TYPES_IMPL
#include "include/debug.h"
#include "include/resource_types.h"

template <> struct _destroy<cairo_t>
{
  static void call(cairo_t *obj)
  {
    dbgprintf("\x1b[90mDestroying cairo_t @ %p, ref count: %d\x1b[m\r\n", obj, cairo_get_reference_count(obj));
    cairo_destroy(obj);
  }
};

template <> struct _destroy<cairo_surface_t>
{
  static void call(cairo_surface_t *obj)
  {
    dbgprintf("\x1b[90mDestroying cairo_surface_t @ %p, ref count: %d\x1b[m\r\n", obj, cairo_surface_get_reference_count(obj));
    cairo_surface_destroy(obj);
  }
};

template <> struct _destroy<cairo_font_options_t>
{
  static void call(cairo_font_options_t *obj)
  {
    dbgprintf("\x1b[90mDestroying cairo_surface_t @ %p\x1b[m\r\n", obj);
    cairo_font_options_destroy(obj);
  }
};

template <> struct _destroy<PangoFontDescription>
{
  static void call(PangoFontDescription *obj)
  {
    dbgprintf("\x1b[90mDestroying PangoFontDescription @ %p\x1b[m\r\n", obj);
    pango_font_description_free(obj);
  }
};

template <> struct _destroy<PangoLayout>
{
  static void call(PangoLayout *obj)
  {
    dbgprintf("\x1b[90mDestroying PangoLayout @ %p\x1b[m\r\n", obj);
    g_object_unref(obj);
  }
};

template void resource_dtor<cairo_t>(ErlNifEnv *env, void *obj);
template void resource_dtor<cairo_surface_t>(ErlNifEnv *env, void *obj);
template void resource_dtor<cairo_font_options_t>(ErlNifEnv *env, void *obj);
template void resource_dtor<PangoFontDescription>(ErlNifEnv *env, void *obj);
template void resource_dtor<PangoLayout>(ErlNifEnv *env, void *obj);
