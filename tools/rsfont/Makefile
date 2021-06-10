CC ?= gcc

CFLAGS = -Wall -Wextra -Werror -std=c11 -O2 -DPNG_SKIP_SETJMP_CHECK

LIBS = -lpng -lz

SRCS = main.c convert_png.c util.c font.c

.PHONY: all clean

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: rsfont$(EXE)
	@:

rsfont$(EXE): $(SRCS) convert_png.h gfx.h global.h util.h font.h
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LDFLAGS) $(LIBS)

clean:
	$(RM) rsfont rsfont.exe
