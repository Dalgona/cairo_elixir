#pragma once
#ifndef CAIRO_ELIXIR_NIF_MACROS_H
#define CAIRO_ELIXIR_NIF_MACROS_H

#define NIF_DECL(name) ERL_NIF_TERM name(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
#define ENSURE_ARGC(x) if (argc != x) { return enif_make_badarg(env); }

#endif
