#pragma once
#ifndef CAIRO_ELIXIR_NIF_RESOURCE_TYPES_H
#define CAIRO_ELIXIR_NIF_RESOURCE_TYPES_H

#include <cstring>
#include <cairo.h>
#include <pango/pango-font.h>
#include <pango/pango-layout.h>
#include <erl_nif.h>

#ifndef CAIRO_ELIXIR_NIF_RESOURCE_TYPES_IMPL
#define EXTERN extern
#else
#define EXTERN
#endif

EXTERN ErlNifResourceType *g_res_type_cairo;
EXTERN ErlNifResourceType *g_res_type_surface;
EXTERN ErlNifResourceType *g_res_type_font_options;
EXTERN ErlNifResourceType *g_res_type_pango_font_description;
EXTERN ErlNifResourceType *g_res_type_pango_layout;

template <typename T> struct _destroy { static void call(T *obj); };

#ifndef CAIRO_ELIXIR_NIF_RESOURCE_TYPES_IMPL
extern template struct _destroy<cairo_t>;
extern template struct _destroy<cairo_surface_t>;
extern template struct _destroy<cairo_font_options_t>;
extern template struct _destroy<PangoFontDescription>;
extern template struct _destroy<PangoLayout>;
#endif

template <typename T> ERL_NIF_TERM create_resource(ErlNifEnv *env, ErlNifResourceType *resource_type, T *obj)
{
  T **resource = (T **)enif_alloc_resource(resource_type, sizeof(T *));

  memcpy(resource, &obj, sizeof(T *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

EXTERN template ERL_NIF_TERM create_resource(ErlNifEnv *, ErlNifResourceType *, cairo_t *);
EXTERN template ERL_NIF_TERM create_resource(ErlNifEnv *, ErlNifResourceType *, cairo_surface_t *);
EXTERN template ERL_NIF_TERM create_resource(ErlNifEnv *, ErlNifResourceType *, cairo_font_options_t *);
EXTERN template ERL_NIF_TERM create_resource(ErlNifEnv *, ErlNifResourceType *, PangoFontDescription *);
EXTERN template ERL_NIF_TERM create_resource(ErlNifEnv *, ErlNifResourceType *, PangoLayout *);

#undef EXTERN

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
