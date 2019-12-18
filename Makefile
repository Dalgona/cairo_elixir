MIX = mix
CXX = g++
ERL_DIR = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)
CXXFLAGS += -std=c++17 -O3 -fPIC -Wall -Wextra -Wno-unused-parameter
CXXFLAGS += -I$(ERL_DIR)
CXXFLAGS += $(shell pkg-config --cflags --libs pangocairo)
CXXFLAGS += -Wno-unused-function

priv/nif_lib/nif_cairo.so: src/nif_cairo.cpp
	$(CXX) $(CXXFLAGS) -shared $(LDFLAGS) -o $@ src/nif_cairo.cpp

clean:
	rm -rf priv/nif_lib/*
