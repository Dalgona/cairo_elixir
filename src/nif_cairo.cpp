#include <unordered_map>
#include <string>
#include <cstring>

#include <cairo.h>
#include <erl_nif.h>

#define NIF_DECL(name) ERL_NIF_TERM name(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])

#define ATOMS \
  ATOM_DECL(ok,) \
  FORMAT_ATOMS \
  CONTENT_ATOMS \
  SURFACE_TYPE_ATOMS

#define FORMAT_ATOMS \
  ATOM_DECL(invalid, CAIRO_FORMAT_INVALID) \
  ATOM_DECL(argb32, CAIRO_FORMAT_ARGB32) \
  ATOM_DECL(rgb24, CAIRO_FORMAT_RGB24) \
  ATOM_DECL(a8, CAIRO_FORMAT_A8) \
  ATOM_DECL(a1, CAIRO_FORMAT_A1) \
  ATOM_DECL(rgb16_565, CAIRO_FORMAT_RGB16_565) \
  ATOM_DECL(rgb30, CAIRO_FORMAT_RGB30)

#define CONTENT_ATOMS \
  ATOM_DECL(color, CAIRO_CONTENT_COLOR) \
  ATOM_DECL(alpha, CAIRO_CONTENT_ALPHA) \
  ATOM_DECL(color_alpha, CAIRO_CONTENT_COLOR_ALPHA)

#define SURFACE_TYPE_ATOMS \
  ATOM_DECL(image, CAIRO_SURFACE_TYPE_IMAGE) \
  ATOM_DECL(pdf, CAIRO_SURFACE_TYPE_PDF) \
  ATOM_DECL(ps, CAIRO_SURFACE_TYPE_PS) \
  ATOM_DECL(xlib, CAIRO_SURFACE_TYPE_XLIB) \
  ATOM_DECL(xcb, CAIRO_SURFACE_TYPE_XCB) \
  ATOM_DECL(glitz, CAIRO_SURFACE_TYPE_GLITZ) \
  ATOM_DECL(quartz, CAIRO_SURFACE_TYPE_QUARTZ) \
  ATOM_DECL(win32, CAIRO_SURFACE_TYPE_WIN32) \
  ATOM_DECL(beos, CAIRO_SURFACE_TYPE_BEOS) \
  ATOM_DECL(directfb, CAIRO_SURFACE_TYPE_DIRECTFB) \
  ATOM_DECL(svg, CAIRO_SURFACE_TYPE_SVG) \
  ATOM_DECL(os2, CAIRO_SURFACE_TYPE_OS2) \
  ATOM_DECL(win32_printing, CAIRO_SURFACE_TYPE_WIN32_PRINTING) \
  ATOM_DECL(quartz_image, CAIRO_SURFACE_TYPE_QUARTZ_IMAGE) \
  ATOM_DECL(script, CAIRO_SURFACE_TYPE_SCRIPT) \
  ATOM_DECL(qt, CAIRO_SURFACE_TYPE_QT) \
  ATOM_DECL(recording, CAIRO_SURFACE_TYPE_RECORDING) \
  ATOM_DECL(vg, CAIRO_SURFACE_TYPE_VG) \
  ATOM_DECL(gl, CAIRO_SURFACE_TYPE_GL) \
  ATOM_DECL(drm, CAIRO_SURFACE_TYPE_DRM) \
  ATOM_DECL(tee, CAIRO_SURFACE_TYPE_TEE) \
  ATOM_DECL(xml, CAIRO_SURFACE_TYPE_XML) \
  ATOM_DECL(skia, CAIRO_SURFACE_TYPE_SKIA) \
  ATOM_DECL(subsurface, CAIRO_SURFACE_TYPE_SUBSURFACE) \
  ATOM_DECL(cogl, CAIRO_SURFACE_TYPE_COGL)

#define ENSURE_ARGC(x) if (argc != x) { return enif_make_badarg(env); }

static ErlNifResourceType *g_res_type_surface;

#define ATOM_DECL(a, _) static ERL_NIF_TERM g_atom_##a;
ATOMS
#undef ATOM_DECL

#define ATOM_DECL(a, e) { #a, e },
template <typename T> std::unordered_map<std::string, T> g_atom_map;
template <> std::unordered_map<std::string, cairo_format_t> g_atom_map<cairo_format_t> { FORMAT_ATOMS };
template <> std::unordered_map<std::string, cairo_content_t> g_atom_map<cairo_content_t> { CONTENT_ATOMS };
template <> std::unordered_map<std::string, cairo_surface_type_t> g_atom_map<cairo_surface_type_t> { SURFACE_TYPE_ATOMS };
#undef ATOM_DECL

#define ATOM_DECL(a, e) { e, &g_atom_##a },
template <typename T> std::unordered_map<T, ERL_NIF_TERM *> g_enum_map;
template <> std::unordered_map<cairo_format_t, ERL_NIF_TERM *> g_enum_map<cairo_format_t> { FORMAT_ATOMS };
template <> std::unordered_map<cairo_content_t, ERL_NIF_TERM *> g_enum_map<cairo_content_t> { CONTENT_ATOMS };
template <> std::unordered_map<cairo_surface_type_t, ERL_NIF_TERM *> g_enum_map<cairo_surface_type_t> { SURFACE_TYPE_ATOMS };
#undef ATOM_DECL

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

#define ATOM_DECL(a, _) g_atom_##a = enif_make_atom(env, #a);
  ATOMS
#undef ATOM_DECL

  return 0;
}

void surface_dtor(ErlNifEnv *env, void *obj)
{
  cairo_surface_t *surface = (cairo_surface_t *)obj;

  cairo_surface_destroy(surface);
}

template <typename T> int enum_from_atom(ErlNifEnv *env, const ERL_NIF_TERM term, T *dest)
{
  char buf[256];
  size_t read_bytes = enif_get_atom(env, term, buf, 256, ERL_NIF_LATIN1);
  std::string atom_name(buf);

  if (read_bytes == 0) { return 0; }
  if (g_atom_map<T>.find(atom_name) == g_atom_map<T>.end()) { return 0; }

  *dest = g_atom_map<T>[atom_name];

  return 1;
}

template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_format_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_content_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_surface_type_t *);

template <typename T> ERL_NIF_TERM enum_to_atom(ErlNifEnv *env, const T value) { return *g_enum_map<T>[value]; }
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_format_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_content_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_surface_type_t);

int get_number(ErlNifEnv *env, const ERL_NIF_TERM term, double *dest)
{
  int tmp;

  if (enif_get_double(env, term, dest))
  {
    return 1;
  }
  else if (enif_get_int(env, term, &tmp))
  {
    *dest = (double)tmp;

    return 1;
  }
  else
  {
    return 0;
  }
}

/************/
/* SURFACES */
/************/

#define REQUIRE_SURFACE(var, argi) \
  cairo_surface_t **_ppsurface = NULL; \
  if (!enif_get_resource(env, argv[argi], g_res_type_surface, (void **)&_ppsurface)) { \
    return enif_make_badarg(env); \
  } \
  cairo_surface_t *var = *_ppsurface;

NIF_DECL(nif_surface_create_similar)
{
  ENSURE_ARGC(4)
  REQUIRE_SURFACE(surface, 0)

  cairo_content_t content;
  int width;
  int height;

  if (!enum_from_atom<cairo_content_t>(env, argv[1], &content)
      || !enif_get_int(env, argv[2], &width)
      || !enif_get_int(env, argv[3], &height))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_t *new_surface = cairo_surface_create_similar(surface, content, width, height);
  cairo_surface_t **resource = (cairo_surface_t **)enif_alloc_resource(g_res_type_surface, sizeof(cairo_surface_t *));

  memcpy(resource, &new_surface, sizeof(cairo_surface_t *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

NIF_DECL(nif_surface_create_similar_image)
{
  ENSURE_ARGC(4)
  REQUIRE_SURFACE(surface, 0)

  cairo_format_t format;
  int width;
  int height;

  if (!enum_from_atom<cairo_format_t>(env, argv[1], &format)
      || !enif_get_int(env, argv[2], &width)
      || !enif_get_int(env, argv[3], &height))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_t *new_surface = cairo_surface_create_similar_image(surface, format, width, height);
  cairo_surface_t **resource = (cairo_surface_t **)enif_alloc_resource(g_res_type_surface, sizeof(cairo_surface_t *));

  memcpy(resource, &new_surface, sizeof(cairo_surface_t *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

NIF_DECL(nif_surface_create_for_rectangle)
{
  ENSURE_ARGC(5)
  REQUIRE_SURFACE(surface, 0)

  cairo_format_t format;
  double x;
  double y;
  double width;
  double height;

  if (!enum_from_atom<cairo_format_t>(env, argv[1], &format)
      || !get_number(env, argv[2], &x)
      || !get_number(env, argv[3], &y)
      || !get_number(env, argv[4], &width)
      || !get_number(env, argv[5], &height))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_t *new_surface = cairo_surface_create_for_rectangle(surface, x, y, width, height);
  cairo_surface_t **resource = (cairo_surface_t **)enif_alloc_resource(g_res_type_surface, sizeof(cairo_surface_t *));

  memcpy(resource, &new_surface, sizeof(cairo_surface_t *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

NIF_DECL(nif_surface_get_content)
{
  ENSURE_ARGC(1)
  REQUIRE_SURFACE(surface, 0)

  return enum_to_atom<cairo_content_t>(env, cairo_surface_get_content(surface));
}

NIF_DECL(nif_surface_mark_dirty)
{
  ENSURE_ARGC(1)
  REQUIRE_SURFACE(surface, 0)

  cairo_surface_mark_dirty(surface);

  return g_atom_ok;
}

NIF_DECL(nif_surface_mark_dirty_rectangle)
{
  ENSURE_ARGC(5)
  REQUIRE_SURFACE(surface, 0)

  int x;
  int y;
  int width;
  int height;

  if (!enif_get_int(env, argv[1], &x)
      || !enif_get_int(env, argv[2], &y)
      || !enif_get_int(env, argv[3], &width)
      || !enif_get_int(env, argv[4], &height))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_mark_dirty_rectangle(surface, x, y, width, height);

  return g_atom_ok;
}

NIF_DECL(nif_surface_set_device_offset)
{
  ENSURE_ARGC(3)
  REQUIRE_SURFACE(surface, 0)

  double x_offset;
  double y_offset;

  if (!get_number(env, argv[1], &x_offset) || !get_number(env, argv[2], &y_offset))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_set_device_offset(surface, x_offset, y_offset);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_device_offset)
{
  ENSURE_ARGC(1)
  REQUIRE_SURFACE(surface, 0)

  double x_offset;
  double y_offset;

  cairo_surface_get_device_offset(surface, &x_offset, &y_offset);

  return enif_make_tuple2(env, enif_make_double(env, x_offset), enif_make_double(env, y_offset));
}

NIF_DECL(nif_surface_set_device_scale)
{
  ENSURE_ARGC(3)
  REQUIRE_SURFACE(surface, 0)

  double x_scale;
  double y_scale;

  if (!get_number(env, argv[1], &x_scale) || !get_number(env, argv[2], &y_scale))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_set_device_scale(surface, x_scale, y_scale);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_device_scale)
{
  ENSURE_ARGC(1)
  REQUIRE_SURFACE(surface, 0)

  double x_scale;
  double y_scale;

  cairo_surface_get_device_scale(surface, &x_scale, &y_scale);

  return enif_make_tuple2(env, enif_make_double(env, x_scale), enif_make_double(env, y_scale));
}

NIF_DECL(nif_surface_set_fallback_resolution)
{
  ENSURE_ARGC(3)
  REQUIRE_SURFACE(surface, 0)

  double x_ppi;
  double y_ppi;

  if (!get_number(env, argv[1], &x_ppi) || !get_number(env, argv[2], &y_ppi))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_set_fallback_resolution(surface, x_ppi, y_ppi);

  return g_atom_ok;
}

NIF_DECL(nif_surface_get_fallback_resolution)
{
  ENSURE_ARGC(1)
  REQUIRE_SURFACE(surface, 0)

  double x_ppi;
  double y_ppi;

  cairo_surface_get_fallback_resolution(surface, &x_ppi, &y_ppi);

  return enif_make_tuple2(env, enif_make_double(env, x_ppi), enif_make_double(env, y_ppi));
}

/******************/
/* IMAGE SURFACES */
/******************/

NIF_DECL(nif_format_stride_for_width)
{
  cairo_format_t format;
  int width;

  ENSURE_ARGC(2)

  if (!enum_from_atom<cairo_format_t>(env, argv[0], &format) || !enif_get_int(env, argv[1], &width))
  {
    return enif_make_badarg(env);
  }

  return enif_make_int(env, cairo_format_stride_for_width(format, width));
}

NIF_DECL(nif_image_surface_create)
{
  ENSURE_ARGC(3);

  cairo_format_t format;
  int width;
  int height;

  if (!enum_from_atom<cairo_format_t>(env, argv[0], &format)
      || !enif_get_int(env, argv[1], &width)
      || !enif_get_int(env, argv[2], &height))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_t *surface = cairo_image_surface_create(format, width, height);
  cairo_surface_t **resource = (cairo_surface_t **)enif_alloc_resource(g_res_type_surface, sizeof(cairo_surface_t *));

  memcpy(resource, &surface, sizeof(cairo_surface_t *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

NIF_DECL(nif_image_surface_create_for_data)
{
  ENSURE_ARGC(5)

  ErlNifBinary data;
  cairo_format_t format;
  int width;
  int height;
  int stride;

  if (!enif_inspect_binary(env, argv[0], &data)
      || !enum_from_atom<cairo_format_t>(env, argv[1], &format)
      || !enif_get_int(env, argv[2], &width)
      || !enif_get_int(env, argv[3], &height)
      || !enif_get_int(env, argv[4], &stride))
  {
    return enif_make_badarg(env);
  }

  cairo_surface_t *surface = cairo_image_surface_create_for_data(data.data, format, width, height, stride);
  cairo_surface_t **resource = (cairo_surface_t **)enif_alloc_resource(g_res_type_surface, sizeof(cairo_surface_t *));

  memcpy(resource, &surface, sizeof(cairo_surface_t *));

  ERL_NIF_TERM term = enif_make_resource(env, resource);

  enif_release_resource(resource);

  return term;
}

NIF_DECL(nif_image_surface_get_data)
{
  ENSURE_ARGC(1)
  REQUIRE_SURFACE(surface, 0)

  ErlNifBinary binary;
  unsigned char *data = cairo_image_surface_get_data(surface);
  int stride = cairo_image_surface_get_stride(surface);
  int height = cairo_image_surface_get_height(surface);
  size_t size = (size_t)(stride * height);

  enif_alloc_binary(size, &binary);
  memcpy(binary.data, data, size);

  return enif_make_binary(env, &binary);
}

NIF_DECL(nif_image_surface_get_format)
{
  ENSURE_ARGC(1)
  REQUIRE_SURFACE(surface, 0)

  return enum_to_atom<cairo_format_t>(env, cairo_image_surface_get_format(surface));
}

NIF_DECL(nif_image_surface_get_width)
{
  ENSURE_ARGC(1)
  REQUIRE_SURFACE(surface, 0)

  return enif_make_int(env, cairo_image_surface_get_width(surface));
}

NIF_DECL(nif_image_surface_get_height)
{
  ENSURE_ARGC(1)
  REQUIRE_SURFACE(surface, 0)

  return enif_make_int(env, cairo_image_surface_get_height(surface));
}

NIF_DECL(nif_image_surface_get_stride)
{
  ENSURE_ARGC(1)
  REQUIRE_SURFACE(surface, 0)

  return enif_make_int(env, cairo_image_surface_get_stride(surface));
}

ErlNifFunc nif_funcs[] = {
  { "surface_create_similar", 4, nif_surface_create_similar, 0 },
  { "surface_create_similar_image", 4, nif_surface_create_similar_image, 0 },
  { "surface_create_for_rectangle", 5, nif_surface_create_for_rectangle, 0 },
  { "surface_get_content", 1, nif_surface_get_content, 0 },
  { "surface_mark_dirty", 1, nif_surface_mark_dirty, 0 },
  { "surface_mark_dirty_rectangle", 5, nif_surface_mark_dirty_rectangle, 0 },
  { "surface_set_device_offset", 3, nif_surface_set_device_offset, 0 },
  { "surface_get_device_offset", 1, nif_surface_get_device_offset, 0 },
  { "surface_set_device_scale", 3, nif_surface_set_device_scale, 0 },
  { "surface_get_device_scale", 1, nif_surface_get_device_scale, 0 },
  { "surface_set_fallback_resolution", 3, nif_surface_set_fallback_resolution, 0 },
  { "surface_get_fallback_resolution", 1, nif_surface_get_fallback_resolution, 0 },

  { "format_stride_for_width", 2, nif_format_stride_for_width, 0 },
  { "image_surface_create", 3, nif_image_surface_create, 0 },
  { "image_surface_create_for_data", 5, nif_image_surface_create_for_data, 0},
  { "image_surface_get_data", 1, nif_image_surface_get_data, 0 },
  { "image_surface_get_format", 1, nif_image_surface_get_format, 0},
  { "image_surface_get_width", 1, nif_image_surface_get_width, 0},
  { "image_surface_get_height", 1, nif_image_surface_get_height, 0},
  { "image_surface_get_stride", 1, nif_image_surface_get_stride, 0}
};

ERL_NIF_INIT(Elixir.Cairo.NativeFunctions, nif_funcs, load, NULL, NULL, NULL)
