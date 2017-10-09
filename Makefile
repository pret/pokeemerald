SHELL := /bin/bash -o pipefail

AS      := $(DEVKITARM)/bin/arm-none-eabi-as
ASFLAGS := -mcpu=arm7tdmi

CC1             := tools/agbcc/bin/agbcc
override CFLAGS += -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm

CPP      := $(DEVKITARM)/bin/arm-none-eabi-cpp
CPPFLAGS := -I tools/agbcc/include -iquote include -nostdinc -undef

LD      := $(DEVKITARM)/bin/arm-none-eabi-ld
LDFLAGS := -T ld_script.ld -Map ../../pokeemerald.map

OBJCOPY := $(DEVKITARM)/bin/arm-none-eabi-objcopy

LIBGCC := tools/agbcc/lib/libgcc.a

SHA1 := sha1sum -c

GFX := tools/gbagfx/gbagfx
AIF := tools/aif2pcm/aif2pcm
MID := tools/mid2agb/mid2agb
SCANINC := tools/scaninc/scaninc
PREPROC := tools/preproc/preproc
RAMSCRGEN := tools/ramscrgen/ramscrgen

# Clear the default suffixes.
.SUFFIXES:

# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:

.PRECIOUS: %.1bpp %.4bpp %.8bpp %.gbapal %.lz %.rl

.PHONY: rom clean compare tidy


$(shell mkdir -p build/ build/emerald/{,asm,data,src})

C_SRCS := $(wildcard src/*.c)
C_OBJS := $(C_SRCS:%.c=build/emerald/%.o)

ASM_SRCS := $(wildcard asm/*.s)
ASM_OBJS := $(ASM_SRCS:%.s=build/emerald/%.o)

DATA_ASM_SRCS := $(wildcard data/*.s)
DATA_ASM_OBJS := $(DATA_ASM_SRCS:%.s=build/emerald/%.o)

OBJS := $(C_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS)

$OBJS_REL := $(OBJS:build/emerald/%=%)

ROM := pokeemerald.gba
ELF := $(ROM:.gba=.elf)

rom: $(ROM)

# For contributors to make sure a change didn't affect the contents of the ROM.
compare: $(ROM)
	@$(SHA1) rom.sha1

clean: tidy
	find . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' -o -iname '*.latfont' -o -iname '*.hwjpnfont' -o -iname '*.fwjpnfont' \) -exec rm {} +

tidy:
	rm -f pokeemerald.gba
	rm -f pokeemerald.map
	rm -f pokeemerald.elf
	rm -r build/*

include graphics_file_rules.mk

%.s: ;
%.bin: ;
%.png: ;
%.pal: ;
%.1bpp: %.png  ; $(GFX) $< $@
%.4bpp: %.png  ; $(GFX) $< $@
%.8bpp: %.png  ; $(GFX) $< $@
%.gbapal: %.pal ; $(GFX) $< $@
%.lz: % ; $(GFX) $< $@
%.rl: % ; $(GFX) $< $@

%src/libc.o: CC1 := tools/agbcc/bin/old_agbcc
%src/libc.o: CFLAGS := -O2

%src/siirtc.o: CFLAGS := -mthumb-interwork

%src/agb_flash.o: CFLAGS := -O -mthumb-interwork
%src/agb_flash_1m.o: CFLAGS := -O -mthumb-interwork
%src/agb_flash_mx.o: CFLAGS := -O -mthumb-interwork

%src/m4a_2.o: CC1 := tools/agbcc/bin/old_agbcc
%src/m4a_4.o: CC1 := tools/agbcc/bin/old_agbcc

ifeq ($(NODEP),)
build/emerald/src/%.o: c_dep = $(shell $(SCANINC) src/$(*F).c)
else
build/emerald/src/%.o: c_dep :=
endif

build/emerald/%.o : %.c $$(c_dep)
	@$(CPP) $(CPPFLAGS) $< -o build/emerald/$*.i
	@$(PREPROC) build/emerald/$*.i charmap.txt | $(CC1) $(CFLAGS) -o build/emerald/$*.s
	@echo -e ".text\n\t.align\t2, 0\n" >> build/emerald/$*.s
	$(AS) $(ASFLAGS) -o $@ build/emerald/$*.s

ifeq ($(NODEP),)
build/emerald/asm/%.o: asm_dep = $(shell $(SCANINC) asm/$(*F).s)
build/emerald/data/%.o: asm_dep = $(shell $(SCANINC) data/$(*F).s)
else
build/emerald/asm/%.o: asm_dep :=
build/emerald/data/%.o: asm_dep :=
endif

build/emerald/asm/%.o: asm/%.s $$(asm_dep)
	$(AS) $(ASFLAGS) -o $@ $<

build/emerald/data/%.o: data/%.s $$(asm_dep)
	$(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@

build/emerald/sym_bss.ld: sym_bss.txt
	cd build/emerald && ../../$(RAMSCRGEN) .bss ../../sym_bss.txt ENGLISH >sym_bss.ld

build/emerald/sym_common.ld: sym_common.txt $(C_OBJS) $(wildcard common_syms/*.txt)
	cd build/emerald && ../../$(RAMSCRGEN) COMMON ../../sym_common.txt ENGLISH -c src,../../common_syms >sym_common.ld

build/emerald/sym_ewram.ld: sym_ewram.txt
	cd build/emerald && ../../$(RAMSCRGEN) ewram_data ../../sym_ewram.txt ENGLISH >sym_ewram.ld

build/emerald/ld_script.ld: ld_script.txt build/emerald/sym_bss.ld build/emerald/sym_common.ld build/emerald/sym_ewram.ld
	cd build/emerald && sed -f ../../ld_script.sed ../../ld_script.txt | sed "s#tools/#../../tools/#g" | sed "s#sound/#../../sound/#g" >ld_script.ld

pokeemerald.elf: build/emerald/ld_script.ld $(OBJS)
	cd build/emerald && $(LD) $(LDFLAGS) -o ../../$@ $(OBJS_REL) ../../$(LIBGCC)

pokeemerald.gba: %.gba: %.elf
	$(OBJCOPY) -O binary --gap-fill 0xFF --pad-to 0x9000000 $< $@
