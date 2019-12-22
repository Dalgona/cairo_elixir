MIX = mix
CXX = g++
ERL_DIR = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)
CXXFLAGS += -std=c++17 -O3 -fPIC -Wall -Wextra -Wno-unused-parameter
CXXFLAGS += -I$(ERL_DIR)
CXXFLAGS += $(shell pkg-config --cflags --libs pangocairo)
CXXFLAGS += -Wno-unused-function

FILES = src/atoms.cpp src/resource_types.cpp src/utils.cpp src/nif_cairo.cpp src/nif_paths.cpp src/nif_surfaces.cpp src/nif_image_surfaces.cpp src/nif_png_support.cpp src/nif_main.cpp

priv/nif_lib/nif_cairo.so: $(FILES)
	$(CXX) $(CXXFLAGS) -shared $(LDFLAGS) -o $@ $(FILES)

clean:
	rm -rf priv/nif_lib/*
