#pragma once
#ifndef CAIRO_ELIXIR_NIF_DEBUG_H
#define CAIRO_ELIXIR_NIF_DEBUG_H

#ifdef CAIRO_ELIXIR_NIF_DEBUG

#include <cstdio>
#define dbgprintf(...) printf(__VA_ARGS__)

#else

#define dbgprintf(...)

#endif

#endif
