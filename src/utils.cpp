#define CAIRO_ELIXIR_NIF_UTILS_IMPL
#include <cstring>
#include "include/resource_types.h"
#include "include/utils.h"

int get_bool(ErlNifEnv *env, const ERL_NIF_TERM term, bool *dest)
{
  char buf[256];
  int atom_len = enif_get_atom(env, term, buf, 256, ERL_NIF_LATIN1);

  if (!atom_len)
  {
    return 0;
  }

  *dest = strncmp(buf, "true", atom_len) == 0;

  return 1;
}

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

template <typename T> int _getlist(ErlNifEnv *env, const ERL_NIF_TERM term, std::vector<T> *dest)
{
  ERL_NIF_TERM head;
  ERL_NIF_TERM tail = term;
  T item;

  if (!enif_is_list(env, term))
  {
    return 0;
  }

  while (enif_get_list_cell(env, tail, &head, &tail))
  {
    if (_getvalue(env, head, &item))
    {
      dest->push_back(item);
    }
    else
    {
      return 0;
    }
  }

  return 1;
}

template <typename T> int _getresource(ErlNifEnv *env, const ERL_NIF_TERM term, nif_resource<T> *dest)
{
  *dest = nif_resource<T>(env, term);

  return dest->obj != nullptr;
}

template <> int _getvalue<bool>(ErlNifEnv *env, const ERL_NIF_TERM term, bool *dest) { return get_bool(env, term, dest); }
template <> int _getvalue<int>(ErlNifEnv *env, const ERL_NIF_TERM term, int *dest) { return enif_get_int(env, term, dest); }
template <> int _getvalue<double>(ErlNifEnv *env, const ERL_NIF_TERM term, double *dest) { return get_number(env, term, dest); }
template <> int _getvalue<vec2_t>(ErlNifEnv *env, const ERL_NIF_TERM term, vec2_t *dest) { return get_vec2(env, term, dest); }
template <> int _getvalue<cairo_matrix_t>(ErlNifEnv *env, const ERL_NIF_TERM term, cairo_matrix_t *dest) { return get_matrix(env, term, dest); }

template <typename T> int _getvalue(ErlNifEnv *env, const ERL_NIF_TERM term, std::vector<T> *dest) { return _getlist(env, term, dest); }
template int _getvalue<double>(ErlNifEnv *, const ERL_NIF_TERM, std::vector<double> *);

template <typename T> int _getvalue(ErlNifEnv *env, const ERL_NIF_TERM term, nif_resource<T> *dest) { return _getresource(env, term, dest); }
template int _getvalue<cairo_t>(ErlNifEnv *, const ERL_NIF_TERM, nif_resource<cairo_t> *);
template int _getvalue<cairo_surface_t>(ErlNifEnv *, const ERL_NIF_TERM, nif_resource<cairo_surface_t> *);
template int _getvalue<cairo_font_options_t>(ErlNifEnv *, const ERL_NIF_TERM, nif_resource<cairo_font_options_t> *);
template int _getvalue<PangoFontDescription>(ErlNifEnv *, const ERL_NIF_TERM, nif_resource<PangoFontDescription> *);
template int _getvalue<PangoLayout>(ErlNifEnv *, const ERL_NIF_TERM, nif_resource<PangoLayout> *);

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
