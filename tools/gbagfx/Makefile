CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11 -O2 -s -DPNG_SKIP_SETJMP_CHECK

LIBS = -lpng -lz

SRCS = main.c convert_png.c gfx.c jasc_pal.c lz.c rl.c util.c font.c

.PHONY: all clean

all: gbagfx
	@:

gbagfx: $(SRCS) convert_png.h gfx.h global.h jasc_pal.h lz.h rl.h util.h font.h
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LDFLAGS) $(LIBS)

clean:
	$(RM) gbagfx gbagfx.exe
