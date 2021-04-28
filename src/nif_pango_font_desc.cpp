#include "include/nif_pango_font_desc.h"

NIF_DECL(nif_pango_font_desc_from_string)
{
  ENSURE_ARGC(1)

  std::string str;

  get_values(env, argv, str);

  return nif_resource(env, pango_font_description_from_string(str.c_str())).term;
}
