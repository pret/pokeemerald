GAME_VERSION ?= EMERALD
TITLE        ?= POKEMON EMER
GAME_CODE    ?= BPEE
BUILD_NAME   ?= emerald
MAP_VERSION  ?= emerald

ifeq (firered, $(or $(BUILD), $(MAKECMDGOALS)))
  	GAME_VERSION 	:= FIRERED
	TITLE       	:= POKEMON FIRE
	GAME_CODE   	:= BPRE
	BUILD_NAME  	:= firered
	MAP_VERSION 	:= firered
else
ifeq (leafgreen, $(or $(BUILD), $(MAKECMDGOALS)))
	GAME_VERSION 	:= LEAFGREEN
	TITLE       	:= POKEMON LEAF
	GAME_CODE   	:= BPGE
	BUILD_NAME  	:= leafgreen
	MAP_VERSION 	:= firered
endif
endif

# GBA rom header
MAKER_CODE  := 01
REVISION    := 0
KEEP_TEMPS  ?= 0

# `File name`.gba
FILE_NAME := poke$(BUILD_NAME)
BUILD_DIR := build

# Compares the ROM to a checksum of the original - only makes sense using when non-modern
COMPARE     ?= 0
# Executes the Test Runner System that checks that all mechanics work as expected
TEST         ?= 0
# Enables -fanalyzer C flag to analyze in depth potential UBs
ANALYZE      ?= 0
# Count unused warnings as errors. Used by RH-Hideout's repo
UNUSED_ERROR ?= 0
# Count deprecated warnings as errors. Used by RH-Hideout's repo
DEPRECATED_ERROR ?= 0
# Adds -Og and -g flags, which optimize the build for debugging and include debug info respectively
DEBUG        ?= 0
# Adds -flto flag, which increases link time but results in a more efficient binary (especially in audio processing)
LTO          ?= 0
# Makes an optimized build for release, also enabling NDEBUG macro and disabling other debugging features
# Enables LTO by default, but can be changed in the config.mk file
RELEASE      ?= 0

ifeq (compare,$(MAKECMDGOALS))
  COMPARE := 1
endif
ifeq (check,$(MAKECMDGOALS))
  TEST := 1
endif
ifeq (debug,$(MAKECMDGOALS))
  DEBUG := 1
endif
ifneq (,$(filter release tidyrelease,$(MAKECMDGOALS)))
  RELEASE := 1
endif

include config.mk

# Default make rule
all: rom

# Toolchain selection
TOOLCHAIN := $(DEVKITARM)
# don't use dkP's base_tools anymore
# because the redefinition of $(CC) conflicts
# with when we want to use $(CC) to preprocess files
# thus, manually create the variables for the bin
# files, or use arm-none-eabi binaries on the system
# if dkP is not installed on this system
ifneq (,$(TOOLCHAIN))
  ifneq ($(wildcard $(TOOLCHAIN)/bin),)
    export PATH := $(TOOLCHAIN)/bin:$(PATH)
  endif
endif

PREFIX := arm-none-eabi-
OBJCOPY := $(PREFIX)objcopy
OBJDUMP := $(PREFIX)objdump
AS := $(PREFIX)as
LD := $(PREFIX)ld

EXE :=
ifeq ($(OS),Windows_NT)
  EXE := .exe
endif

CPP := $(PREFIX)cpp

ifeq ($(RELEASE),1)
	FILE_NAME := $(FILE_NAME)-release
endif

ROM_NAME := $(FILE_NAME).gba
OBJ_DIR_NAME := $(BUILD_DIR)/$(BUILD_NAME)
OBJ_DIR_NAME_TEST := $(BUILD_DIR)/$(BUILD_NAME)-test
OBJ_DIR_NAME_DEBUG := $(BUILD_DIR)/$(BUILD_NAME)-debug
OBJ_DIR_NAME_RELEASE := $(BUILD_DIR)/$(BUILD_NAME)-release
ASSETS_DIR_NAME := $(BUILD_DIR)/assets

ELF_NAME := $(ROM_NAME:.gba=.elf)
MAP_NAME := $(ROM_NAME:.gba=.map)
TESTELF := $(ROM_NAME:.gba=-test.elf)
HEADLESSELF := $(ROM_NAME:.gba=-test-headless.elf)

# Pick our active variables
ROM := $(ROM_NAME)
ifeq ($(TESTELF),$(MAKECMDGOALS))
  TEST := 1
endif
ifeq ($(TEST), 0)
  OBJ_DIR := $(OBJ_DIR_NAME)
else
  OBJ_DIR := $(OBJ_DIR_NAME_TEST)
endif
ifeq ($(DEBUG),1)
  OBJ_DIR := $(OBJ_DIR_NAME_DEBUG)
endif
ifeq ($(RELEASE),1)
  OBJ_DIR := $(OBJ_DIR_NAME_RELEASE)
endif
ELF := $(ROM:.gba=.elf)
MAP := $(ROM:.gba=.map)
SYM := $(ROM:.gba=.sym)

# Commonly used directories
C_SUBDIR = src
ASM_SUBDIR = asm
DATA_SRC_SUBDIR = src/data
DATA_ASM_SUBDIR = data
MID_SUBDIR = sound/songs/midi
TEST_SUBDIR = test

C_BUILDDIR = $(OBJ_DIR)/$(C_SUBDIR)
ASM_BUILDDIR = $(OBJ_DIR)/$(ASM_SUBDIR)
DATA_ASM_BUILDDIR = $(OBJ_DIR)/$(DATA_ASM_SUBDIR)
MID_BUILDDIR = $(OBJ_DIR)/$(MID_SUBDIR)
TEST_BUILDDIR = $(OBJ_DIR)/$(TEST_SUBDIR)

SHELL := bash -o pipefail

# Set flags for tools
ASFLAGS := -mcpu=arm7tdmi -march=armv4t -meabi=5 --defsym MODERN=1 --defsym $(GAME_VERSION)=1

INCLUDE_DIRS := include
INCLUDE_CPP_ARGS := $(INCLUDE_DIRS:%=-iquote %)
INCLUDE_SCANINC_ARGS := $(INCLUDE_DIRS:%=-I %)

ifeq ($(DEBUG),1)
O_LEVEL ?= g
else
O_LEVEL ?= 2
endif
CPPFLAGS := $(INCLUDE_CPP_ARGS) -Wno-trigraphs -DMODERN=1 -DTESTING=$(TEST) -D$(GAME_VERSION) -std=gnu17
ifeq ($(RELEASE),1)
	override CPPFLAGS += -DRELEASE
	ifeq ($(USE_LTO_ON_RELEASE),1)
		LTO := 1
	endif
endif
ARMCC := $(PREFIX)gcc
PATH_ARMCC := PATH="$(PATH)" $(ARMCC)
CC1 := $(shell $(PATH_ARMCC) --print-prog-name=cc1) -quiet

override CFLAGS += -mthumb -mthumb-interwork -O$(O_LEVEL) -mabi=apcs-gnu -mtune=arm7tdmi -march=armv4t -Wno-pointer-to-int-cast -std=gnu17 -Werror -Wall -Wno-strict-aliasing -Wno-attribute-alias -Woverride-init -Wnonnull -Wenum-conversion

ifneq ($(LTO),0)
  ifneq ($(TEST),1)
    override CFLAGS += -flto=auto -fno-fat-lto-objects -fno-asynchronous-unwind-tables -ffunction-sections -fdata-sections
  endif
endif

ifeq ($(ANALYZE),1)
  override CFLAGS += -fanalyzer
endif
# Only throw an error for unused elements if its RH-Hideout's repo
ifeq ($(UNUSED_ERROR),0)
  ifneq ($(GITHUB_REPOSITORY_OWNER),rh-hideout)
    override CFLAGS += -Wno-error=unused-variable -Wno-error=unused-const-variable -Wno-error=unused-parameter -Wno-error=unused-function -Wno-error=unused-but-set-parameter -Wno-error=unused-but-set-variable -Wno-error=unused-value -Wno-error=unused-local-typedefs
  endif
endif

ifeq ($(DEPRECATED_ERROR),0)
  ifneq ($(GITHUB_REPOSITORY_OWNER),rh-hideout)
    override CFLAGS += -Wno-error=deprecated-declarations
  endif
endif

LIBPATH := -L "$(dir $(shell $(PATH_ARMCC) -mthumb -print-file-name=libgcc.a))" -L "$(dir $(shell $(PATH_ARMCC) -mthumb -print-file-name=libnosys.a))" -L "$(dir $(shell $(PATH_ARMCC) -mthumb -print-file-name=libc.a))"
LIB := $(LIBPATH) -lc -lnosys -lgcc -L../../libagbsyscall -lagbsyscall
# Enable debug info if set
ifeq ($(DINFO),1)
  override CFLAGS += -g
else
  ifeq ($(DEBUG),1)
    override CFLAGS += -g
  endif
endif

ifeq ($(NOOPT),1)
override CFLAGS := $(filter-out -O1 -Og -O2,$(CFLAGS))
override CFLAGS += -O0
endif

# Variable filled out in other make files
AUTO_GEN_TARGETS :=
include make_tools.mk
# Tool executables
SMOLTM       := $(TOOLS_DIR)/compresSmol/compresSmolTilemap$(EXE)
SMOL         := $(TOOLS_DIR)/compresSmol/compresSmol$(EXE)
GFX          := $(TOOLS_DIR)/gbagfx/gbagfx$(EXE)
WAV2AGB      := $(TOOLS_DIR)/wav2agb/wav2agb$(EXE)
MID          := $(TOOLS_DIR)/mid2agb/mid2agb$(EXE)
SCANINC      := $(TOOLS_DIR)/scaninc/scaninc$(EXE)
PREPROC      := $(TOOLS_DIR)/preproc/preproc$(EXE)
RAMSCRGEN    := $(TOOLS_DIR)/ramscrgen/ramscrgen$(EXE)
FIX          := $(TOOLS_DIR)/gbafix/gbafix$(EXE)
MAPJSON      := $(TOOLS_DIR)/mapjson/mapjson$(EXE)
JSONPROC     := $(TOOLS_DIR)/jsonproc/jsonproc$(EXE)
TRAINERPROC  := $(TOOLS_DIR)/trainerproc/trainerproc$(EXE)
PATCHELF     := $(TOOLS_DIR)/patchelf/patchelf$(EXE)
ifeq ($(shell uname),Darwin)
    ROMTEST ?= $(shell command -v mgba-rom-test-mac 2>/dev/null || echo $(TOOLS_DIR)/mgba/mgba-rom-test-mac)
    ROMTESTHYDRA := $(shell command -v mgba-rom-test-hydra 2>/dev/null || echo $(TOOLS_DIR)/mgba-rom-test-hydra/mgba-rom-test-hydra)
else ifeq ($(shell uname),Linux)
    ROMTEST ?= $(shell command -v mgba-rom-test 2>/dev/null || echo $(TOOLS_DIR)/mgba/mgba-rom-test)
    ROMTESTHYDRA := $(shell command -v mgba-rom-test-hydra 2>/dev/null || echo $(TOOLS_DIR)/mgba-rom-test-hydra/mgba-rom-test-hydra)
else
    ROMTEST ?= $(TOOLS_DIR)/mgba/mgba-rom-test$(EXE)
    ROMTESTHYDRA := $(TOOLS_DIR)/mgba-rom-test-hydra/mgba-rom-test-hydra$(EXE)
endif

# Learnset helper is a Python script
LEARNSET_HELPERS_DIR := $(TOOLS_DIR)/learnset_helpers
LEARNSET_HELPERS_DATA_DIR := $(LEARNSET_HELPERS_DIR)/porymoves_files
LEARNSET_HELPERS_BUILD_DIR := $(LEARNSET_HELPERS_DIR)/build
ALL_LEARNABLES_JSON := $(DATA_SRC_SUBDIR)/pokemon/all_learnables.json
ALL_TUTORS_JSON := $(LEARNSET_HELPERS_BUILD_DIR)/all_tutors.json
ALL_TEACHING_TYPES_JSON := $(LEARNSET_HELPERS_BUILD_DIR)/all_teaching_types.json

# wild_encounters.h is generated by a Python script
WILD_ENCOUNTERS_TOOL_DIR := $(TOOLS_DIR)/wild_encounters
AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/wild_encounters.h

MISC_TOOL_DIR := $(TOOLS_DIR)/misc
AUTO_GEN_TARGETS +=  $(INCLUDE_DIRS)/constants/script_commands.h

$(DATA_SRC_SUBDIR)/wild_encounters.h: $(DATA_SRC_SUBDIR)/wild_encounters.json $(WILD_ENCOUNTERS_TOOL_DIR)/wild_encounters_to_header.py $(INCLUDE_DIRS)/config/overworld.h $(INCLUDE_DIRS)/config/dexnav.h
	python3 $(WILD_ENCOUNTERS_TOOL_DIR)/wild_encounters_to_header.py

$(INCLUDE_DIRS)/constants/script_commands.h: $(MISC_TOOL_DIR)/make_scr_cmd_constants.py $(DATA_ASM_SUBDIR)/script_cmd_table.inc
	python3  $(MISC_TOOL_DIR)/make_scr_cmd_constants.py

PERL := perl
SHA1 := $(shell { command -v sha1sum || command -v shasum; } 2>/dev/null) -c

MAKEFLAGS += --no-print-directory

# Clear the default suffixes
.SUFFIXES:
# Don't delete intermediate files
.SECONDARY:
# Delete files that weren't built properly
.DELETE_ON_ERROR:

RULES_NO_SCAN += libagbsyscall clean clean-assets tidy tidymodern tidycheck tidyrelease generated clean-generated clean-teachables clean-teachables_intermediates
.PHONY: all rom agbcc modern compare check debug release
.PHONY: $(RULES_NO_SCAN)

infoshell = $(foreach line, $(shell $1 | sed "s/ /__SPACE__/g"), $(info $(subst __SPACE__, ,$(line))))

# Check if we need to scan dependencies based on the chosen rule OR user preference
NODEP ?= 0
# Check if we need to pre-build tools and generate assets based on the chosen rule.
SETUP_PREREQS ?= 1
# Disable dependency scanning for rules that don't need it.
ifneq (,$(MAKECMDGOALS))
  ifeq (,$(filter-out $(RULES_NO_SCAN),$(MAKECMDGOALS)))
    NODEP := 1
    SETUP_PREREQS := 0
  endif
endif

.SHELLSTATUS ?= 0

ifeq ($(SETUP_PREREQS),1)
  # If set on: Default target or a rule requiring a scan
  # Forcibly execute `make tools` since we need them for what we are doing.
  $(foreach line, $(shell $(MAKE) -f make_tools.mk | sed "s/ /__SPACE__/g"), $(info $(subst __SPACE__, ,$(line))))
  ifneq ($(.SHELLSTATUS),0)
    $(error Errors occurred while building tools. See error messages above for more details)
  endif
  # Oh and also generate mapjson sources before we use `SCANINC`.
  $(foreach line, $(shell $(MAKE) MAP_VERSION=$(MAP_VERSION) generated | sed "s/ /__SPACE__/g"), $(info $(subst __SPACE__, ,$(line))))
  ifneq ($(.SHELLSTATUS),0)
    $(error Errors occurred while generating map-related sources. See error messages above for more details)
  endif
endif

# Collect sources
C_SRCS_IN := $(wildcard $(C_SUBDIR)/*.c $(C_SUBDIR)/*/*.c $(C_SUBDIR)/*/*/*.c)
C_SRCS := $(foreach src,$(C_SRCS_IN),$(if $(findstring .inc.c,$(src)),,$(src)))
C_OBJS := $(patsubst $(C_SUBDIR)/%.c,$(C_BUILDDIR)/%.o,$(C_SRCS))

TEST_SRCS_IN := $(wildcard $(TEST_SUBDIR)/*.c $(TEST_SUBDIR)/*/*.c $(TEST_SUBDIR)/*/*/*.c)
TEST_SRCS := $(foreach src,$(TEST_SRCS_IN),$(if $(findstring .inc.c,$(src)),,$(src)))
TEST_OBJS := $(patsubst $(TEST_SUBDIR)/%.c,$(TEST_BUILDDIR)/%.o,$(TEST_SRCS))
TEST_OBJS_REL := $(patsubst $(OBJ_DIR)/%,%,$(TEST_OBJS))

C_ASM_SRCS := $(wildcard $(C_SUBDIR)/*.s $(C_SUBDIR)/*/*.s $(C_SUBDIR)/*/*/*.s)
C_ASM_OBJS := $(patsubst $(C_SUBDIR)/%.s,$(C_BUILDDIR)/%.o,$(C_ASM_SRCS))

ASM_SRCS := $(wildcard $(ASM_SUBDIR)/*.s)
ASM_OBJS := $(patsubst $(ASM_SUBDIR)/%.s,$(ASM_BUILDDIR)/%.o,$(ASM_SRCS))

DATA_ASM_SRCS := $(wildcard $(DATA_ASM_SUBDIR)/*.s)
DATA_ASM_OBJS := $(patsubst $(DATA_ASM_SUBDIR)/%.s,$(DATA_ASM_BUILDDIR)/%.o,$(DATA_ASM_SRCS))

MID_SRCS := $(wildcard $(MID_SUBDIR)/*.mid)
MID_OBJS := $(patsubst $(MID_SUBDIR)/%.mid,$(MID_BUILDDIR)/%.o,$(MID_SRCS))

OBJS     := $(C_OBJS) $(C_ASM_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS) $(MID_OBJS)
OBJS_REL := $(patsubst $(OBJ_DIR)/%,%,$(OBJS))

SUBDIRS  := $(sort $(dir $(OBJS) $(dir $(TEST_OBJS))))
$(shell mkdir -p $(SUBDIRS))

# Pretend rules that are actually flags defer to `make all`
modern: all
compare: all
debug: all
release: all
# Uncomment the next line, and then comment the 4 lines after it to reenable agbcc.
#agbcc: all
agbcc:
	@echo "'make agbcc' is deprecated as of pokeemerald-expansion 1.9 and will be removed in 1.10."
	@echo "Search for 'agbcc: all' in Makefile to reenable agbcc."
	@exit 1

LD_SCRIPT_TEST := ld_script_test.ld

$(OBJ_DIR)/ld_script_test.ld: $(LD_SCRIPT_TEST)
	cd $(OBJ_DIR) && sed "s#tools/#../../tools/#g" ../../$(LD_SCRIPT_TEST) > ld_script_test.ld

$(TESTELF): $(OBJ_DIR)/ld_script_test.ld $(OBJS) $(TEST_OBJS) libagbsyscall tools check-tools
	@echo "cd $(OBJ_DIR) && $(LD) -T ld_script_test.ld -o ../../$@ <objects> <test-objects> <lib>"
	@cd $(OBJ_DIR) && $(LD) $(TESTLDFLAGS) -T ld_script_test.ld -o ../../$@ $(OBJS_REL) $(TEST_OBJS_REL) $(LIB)
	$(FIX) $@ -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION) -d0 --silent
	$(PATCHELF) $(TESTELF) gTestRunnerArgv "$(TESTS:%*=%)\0"

ifeq ($(GITHUB_REPOSITORY_OWNER),rh-hideout)
TEST_SKIP_IS_FAIL := \x01
else
TEST_SKIP_IS_FAIL := \x00
endif

check: $(TESTELF)
	@cp $< $(HEADLESSELF)
	$(PATCHELF) $(HEADLESSELF) gTestRunnerHeadless '\x01' gTestRunnerSkipIsFail "$(TEST_SKIP_IS_FAIL)"
	$(ROMTESTHYDRA) $(ROMTEST) $(OBJCOPY) $(HEADLESSELF)

# Other rules
rom: $(ROM)
ifeq ($(COMPARE),1)
	@$(SHA1) rom.sha1
endif

syms: $(SYM)

clean: tidy clean-tools clean-check-tools clean-generated clean-assets
	@$(MAKE) clean -C libagbsyscall

clean-assets:
	rm -rf $(ASSETS_DIR_NAME)
	rm -f $(MID_SUBDIR)/*.s
	rm -f $(DATA_ASM_SUBDIR)/layouts/layouts.inc $(DATA_ASM_SUBDIR)/layouts/layouts_table.inc
	rm -f $(DATA_ASM_SUBDIR)/maps/connections.inc $(DATA_ASM_SUBDIR)/maps/events.inc $(DATA_ASM_SUBDIR)/maps/groups.inc $(DATA_ASM_SUBDIR)/maps/headers.inc $(DATA_SRC_SUBDIR)/map_group_count.h
	rm -f .map_version
	find sound -iname '*.bin' -exec rm {} +
	find . \( -iname '*.1bpp' -o -iname '*.4bpp' -o -iname '*.8bpp' -o -iname '*.gbapal' -o -iname '*.lz' -o -iname '*.smol' -o -iname '*.fastSmol' -o -iname '*.smolTM' -o -iname '*.rl' -o -iname '*.latfont' -o -iname '*.hwjpnfont' -o -iname '*.fwjpnfont' \) -exec rm {} +
	find $(DATA_ASM_SUBDIR)/maps \( -iname 'connections.inc' -o -iname 'events.inc' -o -iname 'header.inc' \) -exec rm {} +

tidy: tidymodern tidycheck tidydebug tidyrelease

tidymodern:
	rm -f poke*.gba poke*.elf poke*.map
	rm -rf $(OBJ_DIR_NAME)

tidycheck:
	rm -f $(TESTELF) $(HEADLESSELF)
	rm -rf $(OBJ_DIR_NAME_TEST)

tidydebug:
	rm -rf $(OBJ_DIR_NAME_DEBUG)

tidyrelease:
ifeq ($(RELEASE),1)
	rm -f $(ROM_NAME) $(ELF_NAME) $(MAP_NAME)
else # Manually remove the release files on clean/tidy
	rm -f $(FILE_NAME)-release.gba $(FILE_NAME)-release.elf $(FILE_NAME)-release.map
endif
	rm -rf $(OBJ_DIR_NAME_RELEASE)

# Other rules
include graphics_file_rules.mk
include map_data_rules.mk
include spritesheet_rules.mk
include json_data_rules.mk
include audio_rules.mk
include trainer_rules.mk

# NOTE: Tools must have been built prior (FIXME)
# so you can't really call this rule directly
generated: $(AUTO_GEN_TARGETS)
	@: # Silence the "Nothing to be done for `generated'" message, which some people were confusing for an error.


%.s:   ;
%.png: ;
%.pal: ;
%.wav: ;

%.1bpp:     %.png  ; $(GFX) $< $@
%.4bpp:     %.png  ; $(GFX) $< $@
%.8bpp:     %.png  ; $(GFX) $< $@
%.gbapal:   %.pal  ; $(GFX) $< $@
%.gbapal:   %.png  ; $(GFX) $< $@
%.lz:       %      ; $(GFX) $< $@
%.smolTM:   %      ; $(SMOLTM) $< $@
%.fastSmol: %      ; $(SMOL) -w $< $@ false false false
%.smol:     %      ; $(SMOL) -w $< $@
%.rl:       %      ; $(GFX) $< $@

clean-teachables_intermediates:
	rm -f $(DATA_SRC_SUBDIR)/tutor_moves.h
	rm -f $(DATA_SRC_SUBDIR)/pokemon/teachable_learnsets.h
	@rm -Rf $(LEARNSET_HELPERS_BUILD_DIR)
	@echo "rm -Rf <LEARNSET_HELPERS_BUILD_DIR>"

clean-generated: clean-teachables_intermediates
	@rm -f $(AUTO_GEN_TARGETS)
	@echo "rm -f <AUTO_GEN_TARGETS>"

clean-teachables: clean-teachables_intermediates
	rm -f $(ALL_LEARNABLES_JSON)
	@touch $(C_SUBDIR)/pokemon.c

$(C_BUILDDIR)/librfu_intr.o: CFLAGS := -mthumb-interwork -O2 -mabi=apcs-gnu -mtune=arm7tdmi -march=armv4t -fno-toplevel-reorder -Wno-pointer-to-int-cast
$(C_BUILDDIR)/berry_crush.o: override CFLAGS += -Wno-address-of-packed-member
$(C_BUILDDIR)/agb_flash.o: override CFLAGS += -fno-toplevel-reorder
$(C_BUILDDIR)/pokedex_plus_hgss.o: CFLAGS := -mthumb -mthumb-interwork -O2 -mabi=apcs-gnu -mtune=arm7tdmi -march=armv4t -Wno-pointer-to-int-cast -std=gnu17 -Werror -Wall -Wno-strict-aliasing -Wno-attribute-alias -Woverride-init
# Annoyingly we can't turn this on just for src/data/trainers.h
$(C_BUILDDIR)/data.o: CFLAGS += -fno-show-column -fno-diagnostics-show-caret

# Needed for parity with pret
$(C_BUILDDIR)/graphics.o: override CFLAGS += -Wno-missing-braces

# Dependency rules (for the *.c & *.s sources to .o files)
# Have to be explicit or else missing files won't be reported.
$(C_BUILDDIR)/move_relearner.o: $(C_SUBDIR)/move_relearner.c $(DATA_SRC_SUBDIR)/tutor_moves.h
$(C_BUILDDIR)/pokemon.o: $(C_SUBDIR)/pokemon.c $(DATA_SRC_SUBDIR)/pokemon/teachable_learnsets.h

# As a side effect, they're evaluated immediately instead of when the rule is invoked.
# It doesn't look like $(shell) can be deferred so there might not be a better way (Icedude_907: there is soon).

$(C_BUILDDIR)/%.o: $(C_SUBDIR)/%.c
ifneq ($(KEEP_TEMPS),1)
	@echo "$(CC1) <flags> -o $@ $<"
	@$(CPP) $(CPPFLAGS) $< | $(PREPROC) -i -g $(ASSETS_DIR_NAME) $< charmap.txt | $(CC1) $(CFLAGS) -o - - | cat - <(echo -e ".text\n\t.align\t2, 0") | $(AS) $(ASFLAGS) -o $@ -
else
	@$(CPP) $(CPPFLAGS) $< -o $(C_BUILDDIR)/$*.i
	@$(PREPROC) -g $(ASSETS_DIR_NAME) $(C_BUILDDIR)/$*.i charmap.txt | $(CC1) $(CFLAGS) -o $(C_BUILDDIR)/$*.s
	@echo -e ".text\n\t.align\t2, 0\n" >> $(C_BUILDDIR)/$*.s
	$(AS) $(ASFLAGS) -o $@ $(C_BUILDDIR)/$*.s
endif

$(C_BUILDDIR)/%.d: $(C_SUBDIR)/%.c
	$(SCANINC) -M $@ -g $(ASSETS_DIR_NAME) $(INCLUDE_SCANINC_ARGS) -I tools/agbcc/include $<

ifneq ($(NODEP),1)
-include $(ALL_TUTORS_JSON), $(ALL_TEACHING_TYPES_JSON),
-include $(addprefix $(OBJ_DIR)/,$(C_SRCS:.c=.d))
endif

ifeq ($(TEST),1)
$(TEST_BUILDDIR)/%.o: $(TEST_SUBDIR)/%.c
	@echo "$(CC1) <flags> -o $@ $<"
	@$(CPP) $(CPPFLAGS) $< | $(PREPROC) -i -g $(ASSETS_DIR_NAME) $< charmap.txt | $(CC1) $(CFLAGS) -o - - | cat - <(echo -e ".text\n\t.align\t2, 0") | $(AS) $(ASFLAGS) -o $@ -

$(TEST_BUILDDIR)/%.d: $(TEST_SUBDIR)/%.c
	$(SCANINC) -M $@ -g $(ASSETS_DIR_NAME) $(INCLUDE_SCANINC_ARGS) -I tools/agbcc/include $<

ifneq ($(NODEP),1)
-include $(addprefix $(OBJ_DIR)/,$(TEST_SRCS:.c=.d))
endif
endif

$(ASM_BUILDDIR)/%.o: $(ASM_SUBDIR)/%.s
	$(AS) $(ASFLAGS) -o $@ $<

$(ASM_BUILDDIR)/%.d: $(ASM_SUBDIR)/%.s
	$(SCANINC) -M $@ -g $(ASSETS_DIR_NAME) $(INCLUDE_SCANINC_ARGS) -I "" $<

ifneq ($(NODEP),1)
-include $(addprefix $(OBJ_DIR)/,$(ASM_SRCS:.s=.d))
endif

$(C_BUILDDIR)/%.o: $(C_SUBDIR)/%.s
	$(PREPROC) $< charmap.txt | $(CPP) $(CPPFLAGS) $(INCLUDE_SCANINC_ARGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@

$(C_BUILDDIR)/%.d: $(C_SUBDIR)/%.s
	$(SCANINC) -M $@ -g $(ASSETS_DIR_NAME) $(INCLUDE_SCANINC_ARGS) -I "" $<

ifneq ($(NODEP),1)
-include $(addprefix $(OBJ_DIR)/,$(C_ASM_SRCS:.s=.d))
endif

$(DATA_ASM_BUILDDIR)/%.o: $(DATA_ASM_SUBDIR)/%.s
	$(PREPROC) -s $< charmap.txt | $(CPP) $(CPPFLAGS) $(INCLUDE_SCANINC_ARGS) - | $(PREPROC) -ie $< charmap.txt | $(AS) $(ASFLAGS) -o $@

$(DATA_ASM_BUILDDIR)/%.d: $(DATA_ASM_SUBDIR)/%.s
	$(SCANINC) -M $@ -g $(ASSETS_DIR_NAME) $(INCLUDE_SCANINC_ARGS) -I "" $<

ifneq ($(NODEP),1)
-include $(addprefix $(OBJ_DIR)/,$(DATA_ASM_SRCS:.s=.d))
endif

$(OBJ_DIR)/sym_bss.ld: sym_bss.txt
	$(RAMSCRGEN) .bss $< ENGLISH > $@

$(OBJ_DIR)/sym_common.ld: sym_common.txt $(C_OBJS) $(wildcard common_syms/*.txt)
	$(RAMSCRGEN) COMMON $< ENGLISH -c $(C_BUILDDIR),common_syms > $@

$(OBJ_DIR)/sym_ewram.ld: sym_ewram.txt
	$(RAMSCRGEN) ewram_data $< ENGLISH > $@

TEACHABLE_DEPS := $(ALL_LEARNABLES_JSON) $(INCLUDE_DIRS)/constants/tms_hms.h $(INCLUDE_DIRS)/config/pokemon.h $(DATA_SRC_SUBDIR)/pokemon/special_movesets.json $(INCLUDE_DIRS)/config/pokedex_plus_hgss.h $(LEARNSET_HELPERS_DIR)/make_teachables.py

$(LEARNSET_HELPERS_BUILD_DIR):
	@mkdir -p $@

$(ALL_LEARNABLES_JSON):
	python3 $(LEARNSET_HELPERS_DIR)/make_learnables.py $(LEARNSET_HELPERS_DATA_DIR) $@

$(ALL_TUTORS_JSON): $(shell find data/ -type f -name '*.inc')  $(LEARNSET_HELPERS_DIR)/make_tutors.py | $(LEARNSET_HELPERS_BUILD_DIR)
	python3 $(LEARNSET_HELPERS_DIR)/make_tutors.py $@

$(ALL_TEACHING_TYPES_JSON): $(wildcard $(DATA_SRC_SUBDIR)/pokemon/species_info/*_families.h)  $(LEARNSET_HELPERS_DIR)/make_teaching_types.py | $(LEARNSET_HELPERS_BUILD_DIR)
	python3 $(LEARNSET_HELPERS_DIR)/make_teaching_types.py $@

$(DATA_SRC_SUBDIR)/pokemon/teachable_learnsets.h: $(TEACHABLE_DEPS) | $(ALL_TUTORS_JSON) $(ALL_TEACHING_TYPES_JSON)
	python3 $(LEARNSET_HELPERS_DIR)/make_teachables.py $(LEARNSET_HELPERS_BUILD_DIR)

$(DATA_SRC_SUBDIR)/tutor_moves.h: $(DATA_SRC_SUBDIR)/pokemon/special_movesets.json | $(ALL_TUTORS_JSON)
	python3 $(LEARNSET_HELPERS_DIR)/make_teachables.py  --tutors $(LEARNSET_HELPERS_BUILD_DIR)

# Linker script
LD_SCRIPT := ld_script_modern.ld

# Final rules

libagbsyscall:
	@$(MAKE) -C libagbsyscall TOOLCHAIN=$(TOOLCHAIN) MODERN=1

# Enable LTO LDFLAGS if set
ifneq ($(LTO),0)
LDFLAGS := -march=armv4t -mabi=apcs-gnu -mcpu=arm7tdmi -Xlinker -Map=../../$(MAP) -Xlinker --print-memory-usage -Xassembler -meabi=5 -Xassembler -march=armv4t -Xassembler -mcpu=arm7tdmi -Xlinker --gc-sections
LDFLAGS += -Xlinker -flto=auto
$(ELF): $(LD_SCRIPT) $(OBJS) libagbsyscall
	@echo "cd $(OBJ_DIR) && $(ARMCC) $(LDFLAGS) -T ../../$< -o ../../$@ <objs> <libs>"
	+@cd $(OBJ_DIR) && $(ARMCC) $(LDFLAGS) -T ../../$< -o ../../$@ $(OBJS_REL) $(LIB)
	$(FIX) $@ -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION) --silent
else
# Output .map file, memory usage readout and gc sections to clean-up unused data
LDFLAGS = -Map ../../$(MAP) --print-memory-usage --gc-sections
$(ELF): $(LD_SCRIPT) $(OBJS) libagbsyscall
	@cd $(OBJ_DIR) && $(LD) $(LDFLAGS) -T ../../$<  -o ../../$@ $(OBJS_REL) $(LIB) | cat
	@echo "cd $(OBJ_DIR) && $(LD) $(LDFLAGS) -T ../../$< -o ../../$@ <objs> <libs> | cat"
	$(FIX) $@ -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION) --silent
endif

# Builds the rom from the elf file
$(ROM): $(ELF)
	$(OBJCOPY) -O binary $< $@
	$(FIX) $@ -p --silent

emerald: all
firered: all
leafgreen: all
# Symbol file (`make syms`)
$(SYM): $(ELF)
	$(OBJDUMP) -t $< | sort -u | grep -E "^0[2389]" | $(PERL) -p -e 's/^(\w{8}) (\w).{6} \S+\t(\w{8}) (\S+)$$/\1 \2 \3 \4/g' > $@
