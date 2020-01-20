#define CAIRO_ELIXIR_NIF_UTILS_IMPL
#include "utils.h"

int get_number(ErlNifEnv *env, const ERL_NIF_TERM term, double *dest)
{
  int tmp;

  if (enif_get_double(env, term, dest))
  {
    return 1;
  }
  else if (enif_get_int(env, term, &tmp))
  {
    *dest = (double)tmp;

    return 1;
  }
  else
  {
    return 0;
  }
}

int get_vec2(ErlNifEnv *env, const ERL_NIF_TERM term, vec2_t *dest)
{
  const ERL_NIF_TERM *arr;
  int arity;

  if (!enif_get_tuple(env, term, &arity, &arr))
  {
    return 0;
  }

  if (arity != 2)
  {
    return 0;
  }

  if (get_number(env, arr[0], &std::get<0>(*dest))
      && get_number(env, arr[1], &std::get<1>(*dest)))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
