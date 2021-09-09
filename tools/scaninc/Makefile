CXX ?= g++

CXXFLAGS = -Wall -Werror -std=c++11 -O2

SRCS = scaninc.cpp c_file.cpp asm_file.cpp source_file.cpp

HEADERS := scaninc.h asm_file.h c_file.h source_file.h

.PHONY: all clean

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: scaninc$(EXE)
	@:

scaninc$(EXE): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) scaninc scaninc.exe
