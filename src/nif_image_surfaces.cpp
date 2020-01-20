#include <cstring>

#include "nif_image_surfaces.h"

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

  return create_resource(env, g_res_type_surface, cairo_image_surface_create(format, width, height));
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

  return create_resource(env, g_res_type_surface, cairo_image_surface_create_for_data(data.data, format, width, height, stride));
}

NIF_DECL(nif_image_surface_get_data)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

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
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  return enum_to_atom<cairo_format_t>(env, cairo_image_surface_get_format(surface));
}

NIF_DECL(nif_image_surface_get_width)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  return enif_make_int(env, cairo_image_surface_get_width(surface));
}

NIF_DECL(nif_image_surface_get_height)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  return enif_make_int(env, cairo_image_surface_get_height(surface));
}

NIF_DECL(nif_image_surface_get_stride)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  return enif_make_int(env, cairo_image_surface_get_stride(surface));
}
