CXX ?= g++

CXXFLAGS := -Wall -std=c++17 -O2

SRCS := json11.cpp mapjson.cpp

HEADERS := mapjson.h

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

.PHONY: all clean

all: mapjson$(EXE)
	@:

mapjson$(EXE): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) mapjson mapjson.exe
