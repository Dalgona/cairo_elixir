#pragma once
#ifndef CAIRO_ELIXIR_NIF_UTILS_H
#define CAIRO_ELIXIR_NIF_UTILS_H

#include <utility>
#include <vector>
#include <cairo.h>
#include <pango/pango-layout.h>
#include <erl_nif.h>

#ifndef CAIRO_ELIXIR_NIF_UTILS_IMPL
#define EXTERN extern
#else
#define EXTERN
#endif

using vec2_t = std::pair<double, double>;

EXTERN int get_bool(ErlNifEnv *env, const ERL_NIF_TERM term, bool *dest);
EXTERN int get_number(ErlNifEnv *env, const ERL_NIF_TERM term, double *dest);
EXTERN int get_vec2(ErlNifEnv *env, const ERL_NIF_TERM term, vec2_t *dest);
EXTERN int get_matrix(ErlNifEnv *env, const ERL_NIF_TERM term, cairo_matrix_t *dest);

template <typename T> int _getvalue(ErlNifEnv *env, const ERL_NIF_TERM term, T *dest);
template <typename T> int _getvalue(ErlNifEnv *env, const ERL_NIF_TERM term, std::vector<T> *dest);
template <typename T> int _getvalue(ErlNifEnv *env, const ERL_NIF_TERM term, nif_resource<T> *dest);

#ifndef CAIRO_ELIXIR_NIF_UTILS_IMPL
extern template int _getvalue<bool>(ErlNifEnv *env, const ERL_NIF_TERM term, bool *dest);
extern template int _getvalue<int>(ErlNifEnv *env, const ERL_NIF_TERM term, int *dest);
extern template int _getvalue<double>(ErlNifEnv *env, const ERL_NIF_TERM term, double *dest);
extern template int _getvalue<vec2_t>(ErlNifEnv *env, const ERL_NIF_TERM term, vec2_t *dest);
extern template int _getvalue<cairo_matrix_t>(ErlNifEnv *env, const ERL_NIF_TERM term, cairo_matrix_t *dest);

extern template int _getvalue<double>(ErlNifEnv *env, const ERL_NIF_TERM term, std::vector<double> *dest);

extern template int _getvalue<cairo_t>(ErlNifEnv *env, const ERL_NIF_TERM term, nif_resource<cairo_t> *dest);
extern template int _getvalue<cairo_surface_t>(ErlNifEnv *env, const ERL_NIF_TERM term, nif_resource<cairo_surface_t> *dest);
extern template int _getvalue<cairo_font_options_t>(ErlNifEnv *env, const ERL_NIF_TERM term, nif_resource<cairo_font_options_t> *dest);
extern template int _getvalue<PangoFontDescription>(ErlNifEnv *env, const ERL_NIF_TERM term, nif_resource<PangoFontDescription> *dest);
extern template int _getvalue<PangoLayout>(ErlNifEnv *env, const ERL_NIF_TERM term, nif_resource<PangoLayout> *dest);
#endif

template <int ArgIndex, typename T>
void _getvalues(ErlNifEnv *env, const ERL_NIF_TERM argv[], T *dest)
{
  if (!_getvalue(env, argv[ArgIndex], dest)) {
    enif_make_badarg(env);
  }
}

template <int ArgIndex, typename THead, typename... TTail>
void _getvalues(ErlNifEnv *env, const ERL_NIF_TERM argv[], THead *dest, TTail*... dests)
{
  if (!_getvalue(env, argv[ArgIndex], dest))
  {
    enif_make_badarg(env);
  }
  else
  {
    _getvalues<ArgIndex + 1>(env, argv, dests...);
  }
}

template <typename... T>
void get_values(ErlNifEnv *env, const ERL_NIF_TERM argv[], T*... dests) { _getvalues<0>(env, argv, dests...); }

EXTERN ERL_NIF_TERM make_vec2(ErlNifEnv *env, const double e1, const double e2);
EXTERN ERL_NIF_TERM make_matrix(ErlNifEnv *env, const cairo_matrix_t *matrix);

#endif
