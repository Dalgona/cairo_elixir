MIX = mix
CC = gcc
ERL_DIR = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)
CFLAGS += -O3 -fPIC -Wall -Wextra -Wno-unused-parameter
CFLAGS += -I$(ERL_DIR)
CFLAGS += $(shell pkg-config --cflags --libs pangocairo)
CFLAGS += -Wno-unused-function

priv/nif_lib/nif_cairo_surface.so: src/nif_cairo_surface.c
	$(CC) $(CFLAGS) -shared $(LDFLAGS) -o $@ src/nif_cairo_surface.c
