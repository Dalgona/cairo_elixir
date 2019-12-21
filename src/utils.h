#pragma once
#ifndef CAIRO_ELIXIR_NIF_UTILS_H
#define CAIRO_ELIXIR_NIF_UTILS_H

#include <erl_nif.h>

#ifndef CAIRO_ELIXIR_NIF_UTILS_IMPL
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN int get_number(ErlNifEnv *env, const ERL_NIF_TERM term, double *dest);

#endif
