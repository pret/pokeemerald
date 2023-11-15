# This file contains rules for making assemblies for most music in the game.

MID_ASM_DIR = $(MID_SUBDIR)

# For each line in midi.cfg, we do some trickery to convert it into a make rule for the `.mid` file described on the line
# Data following the colon in said file corresponds to arguments passed into mid2agb
MID_CFG_PATH := $(MID_SUBDIR)/midi.cfg

# $1: Source path no extension, $2 Options
define MID_RULE
$(MID_ASM_DIR)/$1.s: $(MID_SUBDIR)/$1.mid
	$(MID) $$< $$@ $2
endef
#                            source path,                             remaining text (options)
define MID_EXPANSION
	$(eval $(call MID_RULE,$(basename $(patsubst %:,%,$(word 1,$1))),$(wordlist 2,999,$1)))
endef

$(foreach line,$(shell cat $(MID_CFG_PATH) | sed "s/ /__SPACE__/g"),$(call MID_EXPANSION,$(subst __SPACE__, ,$(line))))

# Warn users building without a .cfg - build will fail at link time
$(MID_ASM_DIR)/%.s: $(MID_SUBDIR)/%.mid
	$(warning $< does not have an associated entry in midi.cfg! It cannot be built)