AS = ./pokeas
ASFLAGS = -mcpu=arm7tdmi

SHA1 := sha1sum -c

# Clear the default suffixes.
.SUFFIXES:

# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:

.PRECIOUS: %.1bpp %.4bpp %.8bpp %.gbapal %.lz

.PHONY: rom tools gbagfx scaninc clean compare

gfx     := tools/gbagfx/gbagfx
1bpp    := $(gfx) 1bpp
4bpp    := $(gfx) 4bpp
8bpp    := $(gfx) 8bpp
gbapal  := $(gfx) gbapal
lz      := $(gfx) lz
scaninc := tools/scaninc/scaninc

objs = asm/emerald.o

$(foreach obj, $(objs), \
	$(eval $(obj)_deps := $(shell $(scaninc) $(obj:.o=.s))) \
)

rom := pokeemerald.gba
elf := $(rom:.gba=.elf)

rom: $(rom)

tools: gbagfx scaninc

gbagfx:
	cd tools/gbagfx && make

scaninc:
	cd tools/scaninc && make

# For contributors to make sure a change didn't affect the contents of the ROM.
compare: $(rom)
	@$(SHA1) rom.sha1

clean:
	$(RM) $(rom) $(elf) $(objs)
	find . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' \) -exec rm {} +

include graphics_file_rules.mk

%.png: ;
%.pal: ;
%.1bpp: %.png  ; @$(1bpp) $<
%.4bpp: %.png  ; @$(4bpp) $<
%.8bpp: %.png  ; @$(8bpp) $<
%.gbapal: %.pal ; @$(gbapal) $<
%.lz: % ; @$(lz) $<

%.o: %.s $$($$@_deps)
	$(AS) $(ASFLAGS) -o $@ $<

# Link objects to produce the ROM.
$(rom): $(objs)
	./pokeld -T ld_script.txt -T wram_syms.txt -o $(elf) $(objs)
	./pokeobjcopy -O binary $(elf) $(rom)
