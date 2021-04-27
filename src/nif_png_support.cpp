#include <utility>
#include <vector>
#include <cstring>

#include "include/nif_png_support.h"

cairo_status_t read_func(void *closure, unsigned char *data, unsigned int length)
{
  auto state = (std::pair<unsigned char *, unsigned char *> *)closure;
  size_t remaining = state->second - state->first;

  memcpy(data, state->first, remaining < length ? remaining : length);

  state->first += length;

  return CAIRO_STATUS_SUCCESS;
}

NIF_DECL(nif_image_surface_create_from_png)
{
  ENSURE_ARGC(1)

  ErlNifBinary bin_data;

  if (!enif_inspect_binary(env, argv[0], &bin_data))
  {
    return enif_make_badarg(env);
  }

  unsigned char *start = bin_data.data;
  unsigned char *end = start + bin_data.size;
  auto state = std::make_pair(start, end);

  return nif_resource(env, cairo_image_surface_create_from_png_stream(read_func, &state)).term;
}

cairo_status_t write_func(void *closure, const unsigned char *data, unsigned int length)
{
  auto binaries = (std::vector<ErlNifBinary> *)closure;
  ErlNifBinary binary;

  enif_alloc_binary(length, &binary);
  memcpy(binary.data, data, length);
  binaries->push_back(std::move(binary));

  return CAIRO_STATUS_SUCCESS;
}

NIF_DECL(nif_surface_write_to_png)
{
  ENSURE_ARGC(1)
  REQUIRE_OBJECT(cairo_surface_t, surface, surface, 0)

  std::vector<ErlNifBinary> data;

  cairo_status_t status = cairo_surface_write_to_png_stream(surface, write_func, &data);
  ERL_NIF_TERM list = enif_make_list(env, 0);

  if (status != CAIRO_STATUS_SUCCESS)
  {
    return enif_make_tuple2(env, g_atom_error, enum_to_atom<cairo_status_t>(env, status));
  }

  for (auto it = data.rbegin(); it != data.rend(); it++)
  {
    list = enif_make_list_cell(env, enif_make_binary(env, &(*it)), list);
  }

  return enif_make_tuple2(env, g_atom_ok, list);
}
