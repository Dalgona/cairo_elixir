#pragma once
#ifndef CAIRO_ELIXIR_NIF_ATOMS_H
#define CAIRO_ELIXIR_NIF_ATOMS_H

#include <string>
#include <unordered_map>

#include <cairo.h>
#include <pango/pango-layout.h>
#include <erl_nif.h>

#define ATOMS \
  ATOM_DECL(ok,) \
  ATOM_DECL(error,) \
  ATOM_DECL(true,) \
  ATOM_DECL(false,) \
  ATOM_DECL(nil,) \
  FORMAT_ATOMS \
  CONTENT_ATOMS \
  SURFACE_TYPE_ATOMS \
  STATUS_ATOMS \
  ANTIALIAS_ATOMS \
  FILL_RULE_ATOMS \
  LINE_CAP_ATOMS \
  LINE_JOIN_ATOMS \
  SUBPIXEL_ORDER_ATOMS \
  HINT_STYLE_ATOMS \
  HINT_METRICS_ATOMS \
  PATTERN_TYPE_ATOMS \
  FILTER_ATOMS \
  EXTEND_ATOMS \
  WRAP_MODE_ATOMS \
  ELLIPSIZE_MODE_ATOMS \
  ALIGNMENT_ATOMS

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

#define ANTIALIAS_ATOMS \
  ATOM_DECL(default, CAIRO_ANTIALIAS_DEFAULT) \
  ATOM_DECL(none, CAIRO_ANTIALIAS_NONE) \
  ATOM_DECL(gray, CAIRO_ANTIALIAS_GRAY) \
  ATOM_DECL(subpixel, CAIRO_ANTIALIAS_SUBPIXEL) \
  ATOM_DECL(fast, CAIRO_ANTIALIAS_FAST) \
  ATOM_DECL(good, CAIRO_ANTIALIAS_GOOD) \
  ATOM_DECL(best, CAIRO_ANTIALIAS_BEST)

#define FILL_RULE_ATOMS \
  ATOM_DECL(winding, CAIRO_FILL_RULE_WINDING) \
  ATOM_DECL(even_odd, CAIRO_FILL_RULE_EVEN_ODD)

#define LINE_CAP_ATOMS \
  ATOM_DECL(butt_cap, CAIRO_LINE_CAP_BUTT) \
  ATOM_DECL(round_cap, CAIRO_LINE_CAP_ROUND) \
  ATOM_DECL(square_cap, CAIRO_LINE_CAP_SQUARE)

#define LINE_JOIN_ATOMS \
  ATOM_DECL(miter_join, CAIRO_LINE_JOIN_MITER) \
  ATOM_DECL(round_join, CAIRO_LINE_JOIN_ROUND) \
  ATOM_DECL(bevel_join, CAIRO_LINE_JOIN_BEVEL)

#define SUBPIXEL_ORDER_ATOMS \
  ATOM_DECL(subpixel_default, CAIRO_SUBPIXEL_ORDER_DEFAULT) \
  ATOM_DECL(subpixel_rgb, CAIRO_SUBPIXEL_ORDER_RGB) \
  ATOM_DECL(subpixel_bgr, CAIRO_SUBPIXEL_ORDER_BGR) \
  ATOM_DECL(subpixel_vrgb, CAIRO_SUBPIXEL_ORDER_VRGB) \
  ATOM_DECL(subpixel_vbgr, CAIRO_SUBPIXEL_ORDER_VBGR)

#define HINT_STYLE_ATOMS \
  ATOM_DECL(hint_default, CAIRO_HINT_STYLE_DEFAULT) \
  ATOM_DECL(hint_none, CAIRO_HINT_STYLE_NONE) \
  ATOM_DECL(hint_slight, CAIRO_HINT_STYLE_SLIGHT) \
  ATOM_DECL(hint_medium, CAIRO_HINT_STYLE_MEDIUM) \
  ATOM_DECL(hint_full, CAIRO_HINT_STYLE_FULL)

#define HINT_METRICS_ATOMS \
  ATOM_DECL(metrics_default, CAIRO_HINT_METRICS_DEFAULT) \
  ATOM_DECL(metrics_off, CAIRO_HINT_METRICS_OFF) \
  ATOM_DECL(metrics_on, CAIRO_HINT_METRICS_ON)

#define PATTERN_TYPE_ATOMS \
  ATOM_DECL(pattern_solid, CAIRO_PATTERN_TYPE_SOLID) \
  ATOM_DECL(pattern_surface, CAIRO_PATTERN_TYPE_SURFACE) \
  ATOM_DECL(pattern_linear, CAIRO_PATTERN_TYPE_LINEAR) \
  ATOM_DECL(pattern_radial, CAIRO_PATTERN_TYPE_RADIAL) \
  ATOM_DECL(pattern_mesh, CAIRO_PATTERN_TYPE_MESH) \
  ATOM_DECL(pattern_raster, CAIRO_PATTERN_TYPE_RASTER_SOURCE)

#define FILTER_ATOMS \
  ATOM_DECL(filter_fast, CAIRO_FILTER_FAST) \
  ATOM_DECL(filter_good, CAIRO_FILTER_GOOD) \
  ATOM_DECL(filter_best, CAIRO_FILTER_BEST) \
  ATOM_DECL(filter_nearest, CAIRO_FILTER_NEAREST) \
  ATOM_DECL(filter_bilinear, CAIRO_FILTER_BILINEAR) \
  ATOM_DECL(filter_gaussian, CAIRO_FILTER_GAUSSIAN)

#define EXTEND_ATOMS \
  ATOM_DECL(extend_none, CAIRO_EXTEND_NONE) \
  ATOM_DECL(extend_repeat, CAIRO_EXTEND_REPEAT) \
  ATOM_DECL(extend_reflect, CAIRO_EXTEND_REFLECT) \
  ATOM_DECL(extend_pad, CAIRO_EXTEND_PAD)

#define WRAP_MODE_ATOMS \
  ATOM_DECL(wrap_word, PANGO_WRAP_WORD) \
  ATOM_DECL(wrap_char, PANGO_WRAP_CHAR) \
  ATOM_DECL(wrap_word_char, PANGO_WRAP_WORD_CHAR)

#define ELLIPSIZE_MODE_ATOMS \
  ATOM_DECL(ellipsize_none, PANGO_ELLIPSIZE_NONE) \
  ATOM_DECL(ellipsize_start, PANGO_ELLIPSIZE_START) \
  ATOM_DECL(ellipsize_middle, PANGO_ELLIPSIZE_MIDDLE) \
  ATOM_DECL(ellipsize_end, PANGO_ELLIPSIZE_END)

#define ALIGNMENT_ATOMS \
  ATOM_DECL(align_left, PANGO_ALIGN_LEFT) \
  ATOM_DECL(align_center, PANGO_ALIGN_CENTER) \
  ATOM_DECL(align_right, PANGO_ALIGN_RIGHT)

#ifndef CAIRO_ELIXIR_NIF_ATOMS_IMPL
#define EXTERN extern
#else
#define EXTERN
#endif

#define ATOM_DECL(a, _) EXTERN ERL_NIF_TERM g_atom_##a;
ATOMS
#undef ATOM_DECL

#undef EXTERN

template <typename T> using atom_map = std::unordered_map<std::string, T>;
template <typename T> using enum_map = std::unordered_map<T, ERL_NIF_TERM *>;

template <typename T> atom_map<T> g_atom_map;
template <typename T> enum_map<T> g_enum_map;

#ifndef CAIRO_ELIXIR_NIF_ATOMS_IMPL
extern template atom_map<cairo_format_t> g_atom_map<cairo_format_t>;
extern template atom_map<cairo_content_t> g_atom_map<cairo_content_t>;
extern template atom_map<cairo_surface_type_t> g_atom_map<cairo_surface_type_t>;
extern template atom_map<cairo_status_t> g_atom_map<cairo_status_t>;
extern template atom_map<cairo_antialias_t> g_atom_map<cairo_antialias_t>;
extern template atom_map<cairo_fill_rule_t> g_atom_map<cairo_fill_rule_t>;
extern template atom_map<cairo_line_cap_t> g_atom_map<cairo_line_cap_t>;
extern template atom_map<cairo_line_join_t> g_atom_map<cairo_line_join_t>;
extern template atom_map<cairo_subpixel_order_t> g_atom_map<cairo_subpixel_order_t>;
extern template atom_map<cairo_hint_style_t> g_atom_map<cairo_hint_style_t>;
extern template atom_map<cairo_hint_metrics_t> g_atom_map<cairo_hint_metrics_t>;
extern template atom_map<cairo_pattern_type_t> g_atom_map<cairo_pattern_type_t>;
extern template atom_map<cairo_filter_t> g_atom_map<cairo_filter_t>;
extern template atom_map<cairo_extend_t> g_atom_map<cairo_extend_t>;
extern template atom_map<PangoWrapMode> g_atom_map<PangoWrapMode>;
extern template atom_map<PangoEllipsizeMode> g_atom_map<PangoEllipsizeMode>;
extern template atom_map<PangoAlignment> g_atom_map<PangoAlignment>;

extern template enum_map<cairo_format_t> g_enum_map<cairo_format_t>;
extern template enum_map<cairo_content_t> g_enum_map<cairo_content_t>;
extern template enum_map<cairo_surface_type_t> g_enum_map<cairo_surface_type_t>;
extern template enum_map<cairo_status_t> g_enum_map<cairo_status_t>;
extern template enum_map<cairo_antialias_t> g_enum_map<cairo_antialias_t>;
extern template enum_map<cairo_fill_rule_t> g_enum_map<cairo_fill_rule_t>;
extern template enum_map<cairo_line_cap_t> g_enum_map<cairo_line_cap_t>;
extern template enum_map<cairo_line_join_t> g_enum_map<cairo_line_join_t>;
extern template enum_map<cairo_subpixel_order_t> g_enum_map<cairo_subpixel_order_t>;
extern template enum_map<cairo_hint_style_t> g_enum_map<cairo_hint_style_t>;
extern template enum_map<cairo_hint_metrics_t> g_enum_map<cairo_hint_metrics_t>;
extern template enum_map<cairo_pattern_type_t> g_enum_map<cairo_pattern_type_t>;
extern template enum_map<cairo_filter_t> g_enum_map<cairo_filter_t>;
extern template enum_map<cairo_extend_t> g_enum_map<cairo_extend_t>;
extern template enum_map<PangoWrapMode> g_enum_map<PangoWrapMode>;
extern template enum_map<PangoEllipsizeMode> g_enum_map<PangoEllipsizeMode>;
extern template enum_map<PangoAlignment> g_enum_map<PangoAlignment>;
#endif

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

template <typename T> ERL_NIF_TERM enum_to_atom(ErlNifEnv *env, const T value)
{
  return *g_enum_map<T>[value];
}

#endif
