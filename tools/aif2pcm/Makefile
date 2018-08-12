CC = gcc

CFLAGS = -Wall -Wextra -Wno-switch -Werror -std=c11 -O2

LIBS = -lm

SRCS = main.c extended.c

.PHONY: clean

aif2pcm: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LDFLAGS) $(LIBS)

clean:
	$(RM) aif2pcm aif2pcm.exe
