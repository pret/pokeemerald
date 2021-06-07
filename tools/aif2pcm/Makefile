CC ?= gcc

CFLAGS = -Wall -Wextra -Wno-switch -Werror -std=c11 -O2

LIBS = -lm

SRCS = main.c extended.c

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

.PHONY: all clean

all: aif2pcm$(EXE)
	@:

aif2pcm$(EXE): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LDFLAGS) $(LIBS)

clean:
	$(RM) aif2pcm aif2pcm.exe
