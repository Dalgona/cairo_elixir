#include "include/nif_pango_font_desc.h"

NIF_DECL(nif_pango_font_desc_from_string)
{
  ENSURE_ARGC(1)

  ErlNifBinary bin;

  if (!enif_inspect_binary(env, argv[0], &bin))
  {
    return enif_make_badarg(env);
  }

  return nif_resource(env, pango_font_description_from_string((char *)bin.data)).term;
}
