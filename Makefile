AS      := pokeas
ASFLAGS := -mcpu=arm7tdmi

CC     := gbacc
CFLAGS := -mthumb-interwork -O2 -Iinclude

SHA1 := sha1sum -c

GFX := @tools/gbagfx/gbagfx

SCANINC := tools/scaninc/scaninc

# Clear the default suffixes.
.SUFFIXES:

# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:

.PRECIOUS: %.1bpp %.4bpp %.8bpp %.gbapal %.lz

.PHONY: rom tools gbagfx scaninc clean compare deps

CSRCS := $(wildcard src/*.c)
OBJS := asm/emerald.o

$(foreach obj, $(OBJS), \
	$(eval $(obj)_deps := $(shell $(SCANINC) $(obj:.o=.s))) \
)

ROM := pokeemerald.gba
ELF := $(ROM:.gba=.elf)

rom: $(ROM)

tools: gbagfx scaninc

gbagfx:
	cd tools/gbagfx && make

scaninc:
	cd tools/scaninc && make

# For contributors to make sure a change didn't affect the contents of the ROM.
compare: $(ROM)
	@$(SHA1) rom.sha1

clean:
	$(RM) $(ROM) $(ELF) $(OBJS)
	$(RM) genasm/*
	find . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' -o -iname '*.latfont' -o -iname '*.hwjpnfont' -o -iname '*.fwjpnfont' \) -exec rm {} +

include graphics_file_rules.mk

%.png: ;
%.pal: ;
%.1bpp: %.png  ; $(GFX) $< $@
%.4bpp: %.png  ; $(GFX) $< $@
%.8bpp: %.png  ; $(GFX) $< $@
%.gbapal: %.pal ; $(GFX) $< $@
%.lz: % ; $(GFX) $< $@

$(OBJS): $(CSRCS:src/%.c=genasm/%.s)

# TODO: fix this .syntax hack

genasm/prefix.tmp:
	echo -e "\t.syntax divided" >$@

genasm/suffix.tmp:
	echo -e "\t.syntax unified" >$@

genasm/%.s: src/%.c genasm/prefix.tmp genasm/suffix.tmp
	mkdir -p genasm
	$(CC) $(CFLAGS) -o $@.tmp $< -S
	cat genasm/prefix.tmp $@.tmp genasm/suffix.tmp >$@.tmp2
	perl fix_local_labels.pl $@.tmp2 $@
	$(RM) $@.tmp $@.tmp2

%.o: %.s $$($$@_deps)
	$(AS) $(ASFLAGS) -o $@ $<

# Link objects to produce the ROM.
$(ROM): $(OBJS)
	./pokeld -T ld_script.txt -T wram_syms.txt -o $(ELF) $(OBJS)
	./pokeobjcopy -O binary $(ELF) $(ROM)
