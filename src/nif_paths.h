#include "nif_common.h"

#define PATH_NIFS \
  /* USE_NIF(copy_path, 1) */ \
  /* USE_NIF(copy_path_flat, 1) */ \
  /* USE_NIF(path_destroy, 1) */ \
  /* USE_NIF(append_path, 2) */ \
  USE_NIF(has_current_point, 1) \
  USE_NIF(get_current_point, 1) \
  USE_NIF(new_path, 1) \
  USE_NIF(new_sub_path, 1) \
  USE_NIF(close_path, 1) \
  USE_NIF(arc, 6) \
  USE_NIF(arc_negative, 6) \
  USE_NIF(curve_to, 7) \
  USE_NIF(line_to, 3) \
  USE_NIF(move_to, 3) \
  USE_NIF(rectangle, 5) \
  /* USE_NIF(glyph_path, 2) */ \
  USE_NIF(text_path, 2) \
  USE_NIF(rel_curve_to, 7) \
  USE_NIF(rel_line_to, 3) \
  USE_NIF(rel_move_to, 3) \
  USE_NIF(path_extents, 1)

#define USE_NIF(name, arity) NIF_DECL(nif_##name);
PATH_NIFS
#undef USE_NIF
