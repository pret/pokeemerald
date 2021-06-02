
TOOLDIRS := $(filter-out tools/agbcc tools/binutils,$(wildcard tools/*))
TOOLBASE = $(TOOLDIRS:tools/%=%)
TOOLS = $(foreach tool,$(TOOLBASE),tools/$(tool)/$(tool)$(EXE))

.PHONY: all $(TOOLDIRS)

all: $(TOOLDIRS)
	@:

$(TOOLDIRS):
	@$(MAKE) -C $@
