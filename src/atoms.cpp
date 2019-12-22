#define CAIRO_ELIXIR_NIF_ATOMS_IMPL
#include "atoms.h"

#define ATOM_DECL(a, e) { #a, e },
template <> std::unordered_map<std::string, cairo_format_t> g_atom_map<cairo_format_t> { FORMAT_ATOMS };
template <> std::unordered_map<std::string, cairo_content_t> g_atom_map<cairo_content_t> { CONTENT_ATOMS };
template <> std::unordered_map<std::string, cairo_surface_type_t> g_atom_map<cairo_surface_type_t> { SURFACE_TYPE_ATOMS };
template <> std::unordered_map<std::string, cairo_status_t> g_atom_map<cairo_status_t> { STATUS_ATOMS };
template <> std::unordered_map<std::string, cairo_antialias_t> g_atom_map<cairo_antialias_t> { ANTIALIAS_ATOMS };
template <> std::unordered_map<std::string, cairo_fill_rule_t> g_atom_map<cairo_fill_rule_t> { FILL_RULE_ATOMS };
template <> std::unordered_map<std::string, cairo_line_cap_t> g_atom_map<cairo_line_cap_t> { LINE_CAP_ATOMS };
template <> std::unordered_map<std::string, cairo_line_join_t> g_atom_map<cairo_line_join_t> { LINE_JOIN_ATOMS };
#undef ATOM_DECL

#define ATOM_DECL(a, e) { e, &g_atom_##a },
template <> std::unordered_map<cairo_format_t, ERL_NIF_TERM *> g_enum_map<cairo_format_t> { FORMAT_ATOMS };
template <> std::unordered_map<cairo_content_t, ERL_NIF_TERM *> g_enum_map<cairo_content_t> { CONTENT_ATOMS };
template <> std::unordered_map<cairo_surface_type_t, ERL_NIF_TERM *> g_enum_map<cairo_surface_type_t> { SURFACE_TYPE_ATOMS };
template <> std::unordered_map<cairo_status_t, ERL_NIF_TERM *> g_enum_map<cairo_status_t> { STATUS_ATOMS };
template <> std::unordered_map<cairo_antialias_t, ERL_NIF_TERM *> g_enum_map<cairo_antialias_t> { ANTIALIAS_ATOMS };
template <> std::unordered_map<cairo_fill_rule_t, ERL_NIF_TERM *> g_enum_map<cairo_fill_rule_t> { FILL_RULE_ATOMS };
template <> std::unordered_map<cairo_line_cap_t, ERL_NIF_TERM *> g_enum_map<cairo_line_cap_t> { LINE_CAP_ATOMS };
template <> std::unordered_map<cairo_line_join_t, ERL_NIF_TERM *> g_enum_map<cairo_line_join_t> { LINE_JOIN_ATOMS };
#undef ATOM_DECL
