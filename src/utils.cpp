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

  if (!enif_get_tuple(env, term, &arity, &arr) || arity != 2)
  {
    return 0;
  }

  if (get_number(env, arr[0], &dest->first)
      && get_number(env, arr[1], &dest->second))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int get_matrix(ErlNifEnv *env, const ERL_NIF_TERM term, cairo_matrix_t *dest)
{
  const ERL_NIF_TERM *outer_arr;
  const ERL_NIF_TERM *inner_arrs[3];
  int arity;
  double tuple_values[3][2] { 0 };

  if (!enif_get_tuple(env, term, &arity, &outer_arr) || arity != 3)
  {
    return 0;
  }

  for (int i = 0; i < 3; i++)
  {
    if (!enif_get_tuple(env, outer_arr[i], &arity, &inner_arrs[i]) || arity != 2)
    {
      return 0;
    }

    if (!get_number(env, inner_arrs[i][0], &tuple_values[i][0])
        || !get_number(env, inner_arrs[i][1], &tuple_values[i][1]))
    {
      return 0;
    }
  }

  dest->xx = tuple_values[0][0];
  dest->yx = tuple_values[0][1];
  dest->xy = tuple_values[1][0];
  dest->yy = tuple_values[1][1];
  dest->x0 = tuple_values[2][0];
  dest->y0 = tuple_values[2][1];

  return 1;
}

template <> int _getvalue<double>(ErlNifEnv *env, ERL_NIF_TERM term, double *dest) { return get_number(env, term, dest); }
template <> int _getvalue<vec2_t>(ErlNifEnv *env, ERL_NIF_TERM term, vec2_t *dest) { return get_vec2(env, term, dest); }
template <> int _getvalue<cairo_matrix_t>(ErlNifEnv *env, ERL_NIF_TERM term, cairo_matrix_t *dest) { return get_matrix(env, term, dest); }

ERL_NIF_TERM make_vec2(ErlNifEnv *env, const double e1, const double e2)
{
  return enif_make_tuple2(env, enif_make_double(env, e1), enif_make_double(env, e2));
}

ERL_NIF_TERM make_matrix(ErlNifEnv *env, const cairo_matrix_t *matrix)
{
  return enif_make_tuple3(
    env,
    enif_make_tuple2(env, enif_make_double(env, matrix->xx), enif_make_double(env, matrix->yx)),
    enif_make_tuple2(env, enif_make_double(env, matrix->xy), enif_make_double(env, matrix->yy)),
    enif_make_tuple2(env, enif_make_double(env, matrix->x0), enif_make_double(env, matrix->y0))
  );
}
