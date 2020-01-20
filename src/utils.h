#pragma once
#ifndef CAIRO_ELIXIR_NIF_UTILS_H
#define CAIRO_ELIXIR_NIF_UTILS_H

#include <utility>
#include <erl_nif.h>

#ifndef CAIRO_ELIXIR_NIF_UTILS_IMPL
#define EXTERN extern
#else
#define EXTERN
#endif

using vec2_t = std::pair<double, double>;

EXTERN int get_number(ErlNifEnv *env, const ERL_NIF_TERM term, double *dest);
EXTERN int get_vec2(ErlNifEnv *env, const ERL_NIF_TERM term, vec2_t *dest);
EXTERN ERL_NIF_TERM make_vec2(ErlNifEnv *env, const double e1, const double e2);

#endif
