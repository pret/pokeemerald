
MAKEFLAGS += --no-print-directory

# Inclusive list. If you don't want a tool to be built, don't add it here.
TOOLDIRS := tools/aif2pcm tools/bin2c tools/gbafix tools/gbagfx tools/jsonproc tools/mapjson tools/mid2agb tools/preproc tools/ramscrgen tools/rsfont tools/scaninc

.PHONY: all $(TOOLDIRS)

all: $(TOOLDIRS)

$(TOOLDIRS):
	@$(MAKE) -C $@
