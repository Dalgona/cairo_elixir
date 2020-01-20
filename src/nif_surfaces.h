#include "nif_common.h"

#define SURFACE_NIFS \
  USE_NIF(surface_create_similar, 4) \
  USE_NIF(surface_create_similar_image, 4) \
  USE_NIF(surface_create_for_rectangle, 5) \
  USE_NIF(surface_status, 1) \
  USE_NIF(surface_finish, 1) \
  USE_NIF(surface_flush, 1) \
  /* USE_NIF(surface_get_font_options, 1) */ \
  USE_NIF(surface_get_content, 1) \
  USE_NIF(surface_mark_dirty, 1) \
  USE_NIF(surface_mark_dirty_rectangle, 5) \
  USE_NIF(surface_set_device_offset, 2) \
  USE_NIF(surface_get_device_offset, 1) \
  USE_NIF(surface_set_device_scale, 2) \
  USE_NIF(surface_get_device_scale, 1) \
  USE_NIF(surface_set_fallback_resolution, 2) \
  USE_NIF(surface_get_fallback_resolution, 1) \
  USE_NIF(surface_get_type, 1)

#define USE_NIF(name, arity) NIF_DECL(nif_##name);
SURFACE_NIFS
#undef USE_NIF
