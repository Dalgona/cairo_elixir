#include "nif_common.h"

#define IMAGE_SURFACE_NIFS \
  USE_NIF(format_stride_for_width, 2) \
  USE_NIF(image_surface_create, 3) \
  USE_NIF(image_surface_create_for_data, 5) \
  USE_NIF(image_surface_get_data, 1) \
  USE_NIF(image_surface_get_format, 1) \
  USE_NIF(image_surface_get_width, 1) \
  USE_NIF(image_surface_get_height, 1) \
  USE_NIF(image_surface_get_stride, 1)

#define USE_NIF(name, arity) NIF_DECL(nif_##name);
IMAGE_SURFACE_NIFS
#undef USE_NIF
