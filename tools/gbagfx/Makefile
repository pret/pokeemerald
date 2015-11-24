CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -O2

LIBS = -lz -lpng

SRCS = main.c convert_png.c gfx.c jasc_pal.c lz.c util.c font.c

.PHONY: clean

gbagfx: $(SRCS) convert_png.h gfx.h global.h jasc_pal.h lz.h util.h font.h
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LIBS)

clean:
	$(RM) gbagfx gbagfx.exe
