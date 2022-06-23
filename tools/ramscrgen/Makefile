CXX ?= g++

CXXFLAGS := -Wall -Werror -std=c++11 -O2 

SRCS := main.cpp sym_file.cpp elf.cpp

HEADERS := ramscrgen.h sym_file.h elf.h char_util.h

.PHONY: all clean

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: ramscrgen$(EXE)
	@:

ramscrgen$(EXE): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) ramscrgen ramscrgen.exe
