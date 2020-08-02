CXX ?= g++

CXX_DEBUG_FLAGS := -g -O0
CXX_NDEBUG_FLAGS := -O2

ifeq "x$(DEBUG)" "x"
CXXFLAGS := -Wall -std=c++11 $(CXX_NDEBUG_FLAGS)
else
CXXFLAGS := -Wall -std=c++11 $(CXX_DEBUG_FLAGS)
endif


INCLUDES := -I .

SRCS := jsonproc.cpp

HEADERS := jsonproc.h inja.hpp nlohmann/json.hpp

.PHONY: all clean

all: jsonproc
	@:

jsonproc: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) jsonproc jsonproc.exe
