CC ?= gcc

CFLAGS = -Wall -Wextra -Werror -std=c11 -O2

.PHONY: all clean

SRCS = gbafix.c

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: gbafix$(EXE)
	@:

gbafix$(EXE): $(SRCS)
	$(CC) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) gbafix gbafix.exe
