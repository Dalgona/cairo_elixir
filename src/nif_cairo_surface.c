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

ERL_NIF_TERM nif_create_image_surface(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
  int width, height;

  if (!(enif_get_int(env, argv[0], &width) && enif_get_int(env, argv[1], &height)))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_t *surface =
    cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);

  cairo_surface_t **resource =
    enif_alloc_resource(g_res_type_surface, sizeof(cairo_surface_t *));

  memcpy(resource, &surface, sizeof(cairo_surface_t *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

ErlNifFunc nif_funcs[] = {
  { "create_image_surface", 2, nif_create_image_surface }
};

ERL_NIF_INIT(Elixir.Cairo.Surface, nif_funcs, load, NULL, NULL, NULL)
