#include <string.h>

#include <cairo.h>
#include <erl_nif.h>

static ErlNifResourceType *g_res_type_surface;

void surface_dtor(ErlNifEnv *env, void *obj);

int load(ErlNifEnv *env, void **priv, ERL_NIF_TERM load_info)
{
  g_res_type_surface =
    enif_open_resource_type(env,
        NULL,
        "cairo_surface_t",
        surface_dtor,
        ERL_NIF_RT_CREATE,
        NULL
    );

  return 0;
}

void surface_dtor(ErlNifEnv *env, void *obj)
{
  cairo_surface_t *surface = obj;

  cairo_surface_destroy(surface);
}

ErlNifFunc nif_funcs[] = {
};

ERL_NIF_INIT(Elixir.Cairo.NativeFunctions, nif_funcs, load, NULL, NULL, NULL)
