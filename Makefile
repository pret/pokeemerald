SHELL := /bin/bash -o pipefail

AS      := $(DEVKITARM)/bin/arm-none-eabi-as
ASFLAGS := -mcpu=arm7tdmi

CC1             := tools/agbcc/bin/agbcc
override CFLAGS += -mthumb-interwork -Wimplicit -O2 -fhex-asm

CPP      := $(DEVKITARM)/bin/arm-none-eabi-cpp
CPPFLAGS := -I tools/agbcc/include -iquote include -nostdinc -undef

LD      := $(DEVKITARM)/bin/arm-none-eabi-ld
LDFLAGS := -T ld_script.ld -Map pokeemerald.map

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

C_SRCS := $(wildcard src/*.c)
C_OBJS := $(C_SRCS:%.c=%.o)

ASM_SRCS := $(wildcard asm/*.s)
ASM_OBJS := $(ASM_SRCS:%.s=%.o)

DATA_ASM_SRCS := $(wildcard data/*.s)
DATA_ASM_OBJS := $(DATA_ASM_SRCS:%.s=%.o)

OBJS := $(C_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS)

ROM := pokeemerald.gba
ELF := $(ROM:.gba=.elf)

rom: $(ROM)

# For contributors to make sure a change didn't affect the contents of the ROM.
compare: $(ROM)
	@$(SHA1) rom.sha1

clean: tidy
	find . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' -o -iname '*.latfont' -o -iname '*.hwjpnfont' -o -iname '*.fwjpnfont' \) -exec rm {} +

tidy:
	rm -f ld_script.ld sym_bss.ld sym_common.ld sym_ewram.ld
	rm -f $(ROM) $(ELF) $(OBJS) $(C_SRCS:%.c=%.i) pokeemerald.map

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

src/libc.o: CC1 := tools/agbcc/bin/old_agbcc
src/libc.o: CFLAGS := -O2

src/siirtc.o: CFLAGS := -mthumb-interwork

src/agb_flash.o: CFLAGS := -O -mthumb-interwork
src/agb_flash_1m.o: CFLAGS := -O -mthumb-interwork
src/agb_flash_mx.o: CFLAGS := -O -mthumb-interwork

src/m4a_2.o: CC1 := tools/agbcc/bin/old_agbcc
src/m4a_4.o: CC1 := tools/agbcc/bin/old_agbcc

$(C_OBJS): %.o : %.c
	@$(CPP) $(CPPFLAGS) $< -o $*.i
	@$(PREPROC) $*.i charmap.txt | $(CC1) $(CFLAGS) -o $*.s
	@echo -e ".text\n\t.align\t2, 0\n" >> $*.s
	$(AS) $(ASFLAGS) -o $@ $*.s

ifeq ($(NODEP),)
%.o: dep = $(shell $(SCANINC) $*.s)
else
%.o: dep :=
endif

$(ASM_OBJS): %.o: %.s $$(dep)
	$(AS) $(ASFLAGS) -o $@ $<

$(DATA_ASM_OBJS): %.o: %.s $$(dep)
	$(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@

sym_bss.ld: sym_bss.txt
	$(RAMSCRGEN) .bss sym_bss.txt >$@

sym_common.ld: sym_common.txt $(C_OBJS) $(wildcard common_syms/*.txt)
	$(RAMSCRGEN) COMMON sym_common.txt -c src,common_syms >$@

sym_ewram.ld: sym_ewram.txt
	$(RAMSCRGEN) ewram_data sym_ewram.txt >$@

ld_script.ld: ld_script.txt sym_bss.ld sym_common.ld sym_ewram.ld
	sed -f ld_script.sed ld_script.txt >ld_script.ld

$(ELF): ld_script.ld $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LIBGCC)

$(ROM): $(ELF)
	$(OBJCOPY) -O binary --gap-fill 0xFF --pad-to 0x9000000 $< $@
