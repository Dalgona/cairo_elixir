#pragma once
#ifndef CAIRO_ELIXIR_NIF_RESOURCE_TYPES_H
#define CAIRO_ELIXIR_NIF_RESOURCE_TYPES_H

#include <cairo.h>
#include <erl_nif.h>

#ifndef CAIRO_ELIXIR_NIF_RESOURCE_TYPES_IMPL
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN ErlNifResourceType *g_res_type_cairo;
EXTERN ErlNifResourceType *g_res_type_surface;

#undef EXTERN

template <typename T> struct _destroy { static void call(T *obj); };

#ifndef CAIRO_ELIXIR_NIF_RESOURCE_TYPES_IMPL
extern template struct _destroy<cairo_t>;
extern template struct _destroy<cairo_surface_t>;
#endif

template <typename T> void resource_dtor(ErlNifEnv *env, void *obj)
{
  T **resource = (T **)obj;
  _destroy<T>::call(*resource);
}

#ifndef CAIRO_ELIXIR_NIF_RESOURCE_TYPES_IMPL
extern template void resource_dtor<cairo_t>(ErlNifEnv *env, void *obj);
extern template void resource_dtor<cairo_surface_t>(ErlNifEnv *env, void *obj);
#endif

#endif
