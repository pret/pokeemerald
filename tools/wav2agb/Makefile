CXX ?= g++

CXXFLAGS := -Wall -Werror -std=c++17 -O2

SRCS := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)

EXE :=
ifeq ($(OS),Windows_NT)
  EXE := .exe
endif
BINARY = wav2agb$(EXE)

.PHONY: all clean

all: $(BINARY)
	@:

$(BINARY): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) $(BINARY)
