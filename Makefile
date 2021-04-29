MIX = mix
CXX = c++
ERL_DIR = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)
OUT_DIR = priv/nif_lib
BUILD_DIR = $(OUT_DIR)/build
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

MAKE_SRC = $(addsuffix .cpp,$(addprefix src/,$(1)))
MAKE_OBJ = $(addsuffix .o,$(addprefix $(BUILD_DIR)/,$(1)))

MAIN_FILE = nif_main
COMMON_FILES = atoms resource_types utils
NIF_FILES = nif_cairo nif_paths nif_font_options nif_patterns nif_surfaces nif_image_surfaces nif_png_support nif_pango_font_desc nif_pango_layout nif_pango_cairo

MAIN_SRC = $(call MAKE_SRC,$(MAIN_FILE))
MAIN_OBJ = $(call MAKE_OBJ,$(MAIN_FILE))
COMMON_SRC = $(call MAKE_SRC,$(COMMON_FILES))
COMMON_OBJ = $(call MAKE_OBJ,$(COMMON_FILES))
NIF_SRC = $(call MAKE_SRC,$(NIF_FILES))
NIF_OBJ = $(call MAKE_OBJ,$(NIF_FILES))
HEADERS = $(addsuffix .h,$(addprefix src/include/,$(COMMON_FILES) $(NIF_SRC)))

#
# TARGETS
#

$(OUT_DIR)/nif_cairo.so: $(MAIN_OBJ) $(COMMON_OBJ) $(NIF_OBJ)
	$(CXX) $(CXXFLAGS) $(LIBS) $(SHAREDFLAGS) $(LDFLAGS) -o $@ $^

$(MAIN_OBJ): $(MAIN_SRC) $(COMMON_OBJ) $(NIF_OBJ)
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<

$(NIF_OBJ): $(BUILD_DIR)/%.o: src/%.cpp src/include/%.h $(COMMON_OBJ)
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<

$(COMMON_OBJ): $(BUILD_DIR)/%.o: src/%.cpp src/include/%.h
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<

$(MAIN_SRC) $(COMMON_SRC) $(NIF_SRC): $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf priv/nif_lib/*
