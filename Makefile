MIX = mix
CXX = clang++
ERL_DIR = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)
OUT_DIR = priv/nif_lib
CXXFLAGS += -std=c++17 -O3 -fPIC -Wall -Wextra -Wno-unused-parameter
CXXFLAGS += -Wno-unused-function
INCLUDES = -I$(ERL_DIR) $(shell pkg-config --cflags pangocairo)
LIBS = $(shell pkg-config --libs pangocairo)

ifeq ($(shell uname),Darwin)
	LIBS += -flat_namespace -undefined suppress
	SHAREDFLAGS = -bundle
else
	SHAREDFLAGS = -shared
endif

ifeq ($(DEBUG),DEBUG)
	CXXFLAGS += -DCAIRO_ELIXIR_NIF_DEBUG
endif

FILES = atoms resource_types utils nif_cairo nif_paths nif_font_options nif_surfaces nif_image_surfaces nif_png_support nif_main
SRCFILES = $(addsuffix .cpp, $(addprefix src/, $(FILES)))
OBJFILES = $(addsuffix .o, $(addprefix $(OUT_DIR)/build/, $(FILES)))

#
# TARGETS
#

priv/nif_lib/nif_cairo.so: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(LIBS) $(SHAREDFLAGS) $(LDFLAGS) -o $@ $^

$(SRCFILES): build_dir

$(OBJFILES): $(OUT_DIR)/build/%.o: src/%.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<

build_dir:
	mkdir -p $(OUT_DIR)/build

clean:
	rm -rf priv/nif_lib/*
