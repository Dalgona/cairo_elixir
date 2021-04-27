#pragma once
#ifndef CAIRO_ELIXIR_NIF_MACROS_H
#define CAIRO_ELIXIR_NIF_MACROS_H

#define NIF_DECL(name) ERL_NIF_TERM name(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
#define ENSURE_ARGC(x) if (argc != x) { return enif_make_badarg(env); }

#define REQUIRE_OBJECT(T, TRes, var, argi) \
  T *var = nullptr; \
  { \
    T **_ppobj = nullptr; \
    if (!enif_get_resource(env, argv[argi], nif_resource<T>::type, (void **)&_ppobj)) \
    { \
      return enif_make_badarg(env); \
    } \
    var = *_ppobj; \
  }

#endif
