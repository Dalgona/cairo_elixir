#define CAIRO_ELIXIR_NIF_RESOURCE_TYPES_IMPL
#include "resource_types.h"

template <> struct _destroy<cairo_t>
{
  static void call(cairo_t *obj) { cairo_destroy(obj); }
};

template <> struct _destroy<cairo_surface_t>
{
  static void call(cairo_surface_t *obj) { cairo_surface_destroy(obj); }
};
