#pragma once
#ifndef CAIRO_ELIXIR_NIF_RESOURCE_TYPES_H
#define CAIRO_ELIXIR_NIF_RESOURCE_TYPES_H

#include <cstring>
#include <cairo.h>
#include <pango/pango-font.h>
#include <pango/pango-layout.h>
#include <erl_nif.h>

template <typename T> struct _destroy { static void call(T *obj); };

#ifndef CAIRO_ELIXIR_NIF_RESOURCE_TYPES_IMPL
extern template struct _destroy<cairo_t>;
extern template struct _destroy<cairo_pattern_t>;
extern template struct _destroy<cairo_surface_t>;
extern template struct _destroy<cairo_font_options_t>;
extern template struct _destroy<PangoFontDescription>;
extern template struct _destroy<PangoLayout>;
#endif

template <typename T> struct nif_resource
{
  static ErlNifResourceType *type;

  T *obj;
  ERL_NIF_TERM term;

  static void _initialize(ErlNifEnv *env, const char *name)
  {
    type = enif_open_resource_type(
      env, nullptr, name, _dtor, ERL_NIF_RT_CREATE, nullptr
    );
  }

  static void _dtor(ErlNifEnv *env, void *obj)
  {
    T **resource = (T **)obj;

    _destroy<T>::call(*resource);
  }

  nif_resource() { }

  nif_resource(ErlNifEnv *env, T *obj)
  {
    T **resource = (T **)enif_alloc_resource(type, sizeof(T *));

    memcpy(resource, &obj, sizeof(T *));

    this->term = enif_make_resource(env, resource);
    this->obj = obj;

    enif_release_resource(resource);
  }

  nif_resource(ErlNifEnv *env, const ERL_NIF_TERM term)
  {
    T **ppobj = nullptr;

    this->term = term;
    this->obj = enif_get_resource(env, term, type, (void **)&ppobj) ? *ppobj : nullptr;
  }
};

template <typename T> ErlNifResourceType *nif_resource<T>::type {};

#endif
