CXX ?= g++

CXXFLAGS := -std=c++11 -O2 -Wall -Wno-switch -Werror

SRCS := asm_file.cpp c_file.cpp charmap.cpp preproc.cpp string_parser.cpp \
	utf8.cpp

HEADERS := asm_file.h c_file.h char_util.h charmap.h preproc.h string_parser.h \
	utf8.h

.PHONY: all clean

all: preproc
	@:

preproc: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) preproc preproc.exe
