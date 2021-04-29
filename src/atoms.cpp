#define CAIRO_ELIXIR_NIF_ATOMS_IMPL
#include "include/atoms.h"

#define ATOM_DECL(a, e) { #a, e },
template <> atom_map<cairo_format_t> g_atom_map<cairo_format_t> { FORMAT_ATOMS };
template <> atom_map<cairo_content_t> g_atom_map<cairo_content_t> { CONTENT_ATOMS };
template <> atom_map<cairo_surface_type_t> g_atom_map<cairo_surface_type_t> { SURFACE_TYPE_ATOMS };
template <> atom_map<cairo_status_t> g_atom_map<cairo_status_t> { STATUS_ATOMS };
template <> atom_map<cairo_antialias_t> g_atom_map<cairo_antialias_t> { ANTIALIAS_ATOMS };
template <> atom_map<cairo_fill_rule_t> g_atom_map<cairo_fill_rule_t> { FILL_RULE_ATOMS };
template <> atom_map<cairo_line_cap_t> g_atom_map<cairo_line_cap_t> { LINE_CAP_ATOMS };
template <> atom_map<cairo_line_join_t> g_atom_map<cairo_line_join_t> { LINE_JOIN_ATOMS };
template <> atom_map<cairo_subpixel_order_t> g_atom_map<cairo_subpixel_order_t> { SUBPIXEL_ORDER_ATOMS };
template <> atom_map<cairo_hint_style_t> g_atom_map<cairo_hint_style_t> { HINT_STYLE_ATOMS };
template <> atom_map<cairo_hint_metrics_t> g_atom_map<cairo_hint_metrics_t> { HINT_METRICS_ATOMS };
template <> atom_map<cairo_pattern_type_t> g_atom_map<cairo_pattern_type_t> { PATTERN_TYPE_ATOMS };
template <> atom_map<cairo_filter_t> g_atom_map<cairo_filter_t> { FILTER_ATOMS };
template <> atom_map<cairo_extend_t> g_atom_map<cairo_extend_t> { EXTEND_ATOMS };
template <> atom_map<PangoWrapMode> g_atom_map<PangoWrapMode> { WRAP_MODE_ATOMS };
template <> atom_map<PangoEllipsizeMode> g_atom_map<PangoEllipsizeMode> { ELLIPSIZE_MODE_ATOMS };
template <> atom_map<PangoAlignment> g_atom_map<PangoAlignment> { ALIGNMENT_ATOMS };
#undef ATOM_DECL

#define ATOM_DECL(a, e) { e, &g_atom_##a },
template <> enum_map<cairo_format_t> g_enum_map<cairo_format_t> { FORMAT_ATOMS };
template <> enum_map<cairo_content_t> g_enum_map<cairo_content_t> { CONTENT_ATOMS };
template <> enum_map<cairo_surface_type_t> g_enum_map<cairo_surface_type_t> { SURFACE_TYPE_ATOMS };
template <> enum_map<cairo_status_t> g_enum_map<cairo_status_t> { STATUS_ATOMS };
template <> enum_map<cairo_antialias_t> g_enum_map<cairo_antialias_t> { ANTIALIAS_ATOMS };
template <> enum_map<cairo_fill_rule_t> g_enum_map<cairo_fill_rule_t> { FILL_RULE_ATOMS };
template <> enum_map<cairo_line_cap_t> g_enum_map<cairo_line_cap_t> { LINE_CAP_ATOMS };
template <> enum_map<cairo_line_join_t> g_enum_map<cairo_line_join_t> { LINE_JOIN_ATOMS };
template <> enum_map<cairo_subpixel_order_t> g_enum_map<cairo_subpixel_order_t> { SUBPIXEL_ORDER_ATOMS };
template <> enum_map<cairo_hint_style_t> g_enum_map<cairo_hint_style_t> { HINT_STYLE_ATOMS };
template <> enum_map<cairo_hint_metrics_t> g_enum_map<cairo_hint_metrics_t> { HINT_METRICS_ATOMS };
template <> enum_map<cairo_pattern_type_t> g_enum_map<cairo_pattern_type_t> { PATTERN_TYPE_ATOMS };
template <> enum_map<cairo_filter_t> g_enum_map<cairo_filter_t> { FILTER_ATOMS };
template <> enum_map<cairo_extend_t> g_enum_map<cairo_extend_t> { EXTEND_ATOMS };
template <> enum_map<PangoWrapMode> g_enum_map<PangoWrapMode> { WRAP_MODE_ATOMS };
template <> enum_map<PangoEllipsizeMode> g_enum_map<PangoEllipsizeMode> { ELLIPSIZE_MODE_ATOMS };
template <> enum_map<PangoAlignment> g_enum_map<PangoAlignment> { ALIGNMENT_ATOMS };
#undef ATOM_DECL

template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_format_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_content_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_surface_type_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_status_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_antialias_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_fill_rule_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_line_cap_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_line_join_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_subpixel_order_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_hint_style_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_hint_metrics_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_pattern_type_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_filter_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, cairo_extend_t *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, PangoWrapMode *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, PangoEllipsizeMode *);
template int enum_from_atom(ErlNifEnv *, const ERL_NIF_TERM, PangoAlignment *);

template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_format_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_content_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_surface_type_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_status_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_antialias_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_fill_rule_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_line_cap_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_line_join_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_subpixel_order_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_hint_style_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_hint_metrics_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_pattern_type_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_filter_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const cairo_extend_t);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const PangoWrapMode);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const PangoEllipsizeMode);
template ERL_NIF_TERM enum_to_atom(ErlNifEnv *, const PangoAlignment);
