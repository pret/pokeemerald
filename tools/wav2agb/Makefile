GIT_VERSION := $(shell git describe --abbrev=7 --dirty --always --tags)

CXX = g++
STRIP = strip
CXXFLAGS = -Wall -Wextra -Wconversion -std=c++17 -O2 -g -DGIT_VERSION=\"$(GIT_VERSION)\"
EXE :=
ifeq ($(OS),Windows_NT)
  EXE := .exe
endif
BINARY = wav2agb$(EXE)

SRC_FILES = $(wildcard *.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)

LDFLAGS :=

ifneq (,$(RELEASE))
  LDFLAGS += -static
  CXXFLAGS += -flto
endif

.PHONY: clean clean
all: $(BINARY)

clean:
	rm -f $(OBJ_FILES) $(BINARY)

$(BINARY): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^
	if [ $(RELEASE)x != x ]; then strip -s $@; fi

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)
