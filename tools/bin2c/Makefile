CC ?= gcc

CFLAGS = -Wall -Wextra -Werror -std=c11 -O2

.PHONY: all clean

SRCS = bin2c.c

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: bin2c$(EXE)
	@:

bin2c$(EXE): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) bin2c bin2c.exe
