#define CAIRO_ELIXIR_NIF_RESOURCE_TYPES_IMPL
#include "debug.h"
#include "resource_types.h"

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

template void resource_dtor<cairo_t>(ErlNifEnv *env, void *obj);
template void resource_dtor<cairo_surface_t>(ErlNifEnv *env, void *obj);
template void resource_dtor<cairo_font_options_t>(ErlNifEnv *env, void *obj);
