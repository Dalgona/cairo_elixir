#pragma once
#ifndef CAIRO_ELIXIR_NIF_ATOMS_H
#define CAIRO_ELIXIR_NIF_ATOMS_H

#define ATOMS \
  ATOM_DECL(ok,) \
  FORMAT_ATOMS \
  CONTENT_ATOMS \
  SURFACE_TYPE_ATOMS \
  STATUS_ATOMS

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

#define STATUS_ATOMS \
  ATOM_DECL(success, CAIRO_STATUS_SUCCESS) \
  ATOM_DECL(no_memory, CAIRO_STATUS_NO_MEMORY) \
  ATOM_DECL(invalid_restore, CAIRO_STATUS_INVALID_RESTORE) \
  ATOM_DECL(invalid_pop_group, CAIRO_STATUS_INVALID_POP_GROUP) \
  ATOM_DECL(no_current_point, CAIRO_STATUS_NO_CURRENT_POINT) \
  ATOM_DECL(invalid_matrix, CAIRO_STATUS_INVALID_MATRIX) \
  ATOM_DECL(invalid_status, CAIRO_STATUS_INVALID_STATUS) \
  ATOM_DECL(null_pointer, CAIRO_STATUS_NULL_POINTER) \
  ATOM_DECL(invalid_string, CAIRO_STATUS_INVALID_STRING) \
  ATOM_DECL(invalid_path_data, CAIRO_STATUS_INVALID_PATH_DATA) \
  ATOM_DECL(read_error, CAIRO_STATUS_READ_ERROR) \
  ATOM_DECL(write_error, CAIRO_STATUS_WRITE_ERROR) \
  ATOM_DECL(surface_finished, CAIRO_STATUS_SURFACE_FINISHED) \
  ATOM_DECL(surface_type_mismatch, CAIRO_STATUS_SURFACE_TYPE_MISMATCH) \
  ATOM_DECL(pattern_type_mismatch, CAIRO_STATUS_PATTERN_TYPE_MISMATCH) \
  ATOM_DECL(invalid_content, CAIRO_STATUS_INVALID_CONTENT) \
  ATOM_DECL(invalid_format, CAIRO_STATUS_INVALID_FORMAT) \
  ATOM_DECL(invalid_visual, CAIRO_STATUS_INVALID_VISUAL) \
  ATOM_DECL(file_not_found, CAIRO_STATUS_FILE_NOT_FOUND) \
  ATOM_DECL(invalid_dash, CAIRO_STATUS_INVALID_DASH) \
  ATOM_DECL(invalid_dsc_comment, CAIRO_STATUS_INVALID_DSC_COMMENT) \
  ATOM_DECL(invalid_index, CAIRO_STATUS_INVALID_INDEX) \
  ATOM_DECL(clip_not_representable, CAIRO_STATUS_CLIP_NOT_REPRESENTABLE) \
  ATOM_DECL(temp_file_error, CAIRO_STATUS_TEMP_FILE_ERROR) \
  ATOM_DECL(invalid_stride, CAIRO_STATUS_INVALID_STRIDE) \
  ATOM_DECL(font_type_mismatch, CAIRO_STATUS_FONT_TYPE_MISMATCH) \
  ATOM_DECL(user_font_immutable, CAIRO_STATUS_USER_FONT_IMMUTABLE) \
  ATOM_DECL(user_font_error, CAIRO_STATUS_USER_FONT_ERROR) \
  ATOM_DECL(negative_count, CAIRO_STATUS_NEGATIVE_COUNT) \
  ATOM_DECL(invalid_clusters, CAIRO_STATUS_INVALID_CLUSTERS) \
  ATOM_DECL(invalid_slant, CAIRO_STATUS_INVALID_SLANT) \
  ATOM_DECL(invalid_weight, CAIRO_STATUS_INVALID_WEIGHT) \
  ATOM_DECL(invalid_size, CAIRO_STATUS_INVALID_SIZE) \
  ATOM_DECL(user_font_not_implemented, CAIRO_STATUS_USER_FONT_NOT_IMPLEMENTED) \
  ATOM_DECL(device_type_mismatch, CAIRO_STATUS_DEVICE_TYPE_MISMATCH) \
  ATOM_DECL(device_error, CAIRO_STATUS_DEVICE_ERROR) \
  ATOM_DECL(invalid_mesh_construction, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION) \
  ATOM_DECL(device_finished, CAIRO_STATUS_DEVICE_FINISHED) \
  ATOM_DECL(jbig2_global_missing, CAIRO_STATUS_JBIG2_GLOBAL_MISSING) \
  ATOM_DECL(png_error, CAIRO_STATUS_PNG_ERROR) \
  ATOM_DECL(freetype_error, CAIRO_STATUS_FREETYPE_ERROR) \
  ATOM_DECL(win32_gdi_error, CAIRO_STATUS_WIN32_GDI_ERROR) \
  ATOM_DECL(tag_error, CAIRO_STATUS_TAG_ERROR) \
  ATOM_DECL(last_status, CAIRO_STATUS_LAST_STATUS)

#define ATOM_DECL(a, _) static ERL_NIF_TERM g_atom_##a;
ATOMS
#undef ATOM_DECL

#define ATOM_DECL(a, e) { #a, e },
template <typename T> std::unordered_map<std::string, T> g_atom_map;
template <> std::unordered_map<std::string, cairo_format_t> g_atom_map<cairo_format_t> { FORMAT_ATOMS };
template <> std::unordered_map<std::string, cairo_content_t> g_atom_map<cairo_content_t> { CONTENT_ATOMS };
template <> std::unordered_map<std::string, cairo_surface_type_t> g_atom_map<cairo_surface_type_t> { SURFACE_TYPE_ATOMS };
template <> std::unordered_map<std::string, cairo_status_t> g_atom_map<cairo_status_t> { STATUS_ATOMS };
#undef ATOM_DECL

#define ATOM_DECL(a, e) { e, &g_atom_##a },
template <typename T> std::unordered_map<T, ERL_NIF_TERM *> g_enum_map;
template <> std::unordered_map<cairo_format_t, ERL_NIF_TERM *> g_enum_map<cairo_format_t> { FORMAT_ATOMS };
template <> std::unordered_map<cairo_content_t, ERL_NIF_TERM *> g_enum_map<cairo_content_t> { CONTENT_ATOMS };
template <> std::unordered_map<cairo_surface_type_t, ERL_NIF_TERM *> g_enum_map<cairo_surface_type_t> { SURFACE_TYPE_ATOMS };
template <> std::unordered_map<cairo_status_t, ERL_NIF_TERM *> g_enum_map<cairo_status_t> { STATUS_ATOMS };
#undef ATOM_DECL

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

#endif
