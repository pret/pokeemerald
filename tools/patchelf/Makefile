.PHONY: all clean

SRCS = patchelf.c

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: patchelf$(EXE)
	@:

patchelf$(EXE): $(SRCS)
	$(CC) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) patchelf$(EXE)
