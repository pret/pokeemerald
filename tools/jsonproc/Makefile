CXX ?= g++

CXXFLAGS := -Wall -std=c++11 -O2

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
