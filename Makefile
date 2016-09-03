AS      := $(DEVKITARM)/bin/arm-none-eabi-as
ASFLAGS := -mcpu=arm7tdmi

CC1    := tools/agbcc/bin/agbcc
CFLAGS := -mthumb-interwork -O2

CPP      := $(DEVKITARM)/bin/arm-none-eabi-cpp
CPPFLAGS := -I tools/agbcc/include -iquote include -nostdinc -undef

LD      := $(DEVKITARM)/bin/arm-none-eabi-ld
LDFLAGS := -T ld_script.txt -T iwram_syms.txt -T ewram_syms.txt -Map pokeemerald.map

OBJCOPY := $(DEVKITARM)/bin/arm-none-eabi-objcopy

LIBGCC := tools/agbcc/lib/libgcc.a

SHA1 := sha1sum -c

GFX := @tools/gbagfx/gbagfx

SCANINC := tools/scaninc/scaninc

PREPROC := tools/preproc/preproc

# Clear the default suffixes.
.SUFFIXES:

# Secondary expansion is required for dependency variables in object rules.
.SECONDEXPANSION:

.PRECIOUS: %.1bpp %.4bpp %.8bpp %.gbapal %.lz %.rl

.PHONY: rom clean compare tidy

C_SRCS := $(wildcard src/*.c)
C_OBJS := $(C_SRCS:%.c=%.o)

ASM_OBJS := \
asm/crt0.o \
asm/main.o \
asm/dma3_manager.o \
asm/gpu_bg.o \
asm/pixel_buffer.o \
asm/window.o \
asm/text_renderer.o \
asm/gpu_obj.o \
asm/string_util.o \
asm/rom_80093CC.o \
asm/rtc.o \
asm/main_menu.o \
asm/rom_8032654.o \
asm/tileset_animation.o \
asm/rom_80A18F4.o \
asm/task.o \
asm/rom_80A92F4.o \
asm/multiboot.o \
asm/rom_81BAD84.o \
asm/libgcnmultiboot.o \
asm/libmks4agb.o \
asm/libagbbackup.o \
asm/librtc.o \
asm/librfu.o \
asm/libagbsyscall.o \
asm/libc.o

DATA_ASM_OBJS := data/data1.o data/data2.o data/anim_mon_front_pics.o \
data/graphics.o data/unknown_serial_data.o data/multiboot_berry_glitch_fix.o \
data/multiboot_pokemon_colosseum.o data/librfu_rodata.o

OBJS := $(C_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS)

ROM := pokeemerald.gba
ELF := $(ROM:.gba=.elf)

rom: $(ROM)

# For contributors to make sure a change didn't affect the contents of the ROM.
compare: $(ROM)
	@$(SHA1) rom.sha1

clean:
	rm -f $(ROM) $(ELF) $(OBJS) $(C_SRCS:%.c=%.i) pokeemerald.map
	find . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' -o -iname '*.latfont' -o -iname '*.hwjpnfont' -o -iname '*.fwjpnfont' \) -exec rm {} +

tidy:
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

%.o : dep = $(shell $(SCANINC) $*.s)

$(ASM_OBJS): %.o: %.s $$(dep)
	$(AS) $(ASFLAGS) -o $@ $<

$(DATA_ASM_OBJS): %.o: %.s $$(dep)
	$(PREPROC) $< charmap.txt | $(AS) $(ASFLAGS) -o $@

# Link objects to produce the ROM.
$(ROM): $(OBJS)
	$(LD) $(LDFLAGS) -o $(ELF) $(OBJS) $(LIBGCC)
	$(OBJCOPY) -O binary --gap-fill 0xFF --pad-to 0x9000000 $(ELF) $(ROM)
