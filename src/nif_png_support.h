#include "nif_common.h"

#define PNG_SUPPORT_NIFS \
  /* USE_NIF(image_surface_create_from_png, 1) */ \
  USE_NIF(surface_write_to_png, 1)

#define USE_NIF(name, arity) NIF_DECL(nif_##name);
PNG_SUPPORT_NIFS
#undef USE_NIF
