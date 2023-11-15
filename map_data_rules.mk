# Map JSON data

# Inputs
MAPS_DIR = $(DATA_ASM_SUBDIR)/maps
LAYOUTS_DIR = $(DATA_ASM_SUBDIR)/layouts

# Outputs
MAPS_OUTDIR := $(BUILD_ASSETS_DIR)/$(MAPS_DIR)
LAYOUTS_OUTDIR := $(BUILD_ASSETS_DIR)/$(LAYOUTS_DIR)
INCLUDECONSTS_OUTDIR := $(BUILD_ASSETS_DIR)/include/generated/constants

MAP_DIRS := $(dir $(wildcard $(MAPS_DIR)/*/map.json))
MAP_OUTDIRS := $(patsubst $(MAPS_DIR)/%/, $(MAPS_OUTDIR)/%/, $(MAP_DIRS))
MAP_CONNECTIONS := $(patsubst $(MAPS_DIR)/%/,$(MAPS_DIR)/%/connections.inc,$(MAP_OUTDIRS))
MAP_EVENTS := $(patsubst $(MAPS_DIR)/%/,$(MAPS_DIR)/%/events.inc,$(MAP_OUTDIRS))
MAP_HEADERS := $(patsubst $(MAPS_DIR)/%/,$(MAPS_DIR)/%/header.inc,$(MAP_OUTDIRS))

SPECIAL_OUTDIRS := $(MAPS_OUTDIR) $(LAYOUTS_OUTDIR) $(INCLUDECONSTS_OUTDIR) $(MAP_OUTDIRS)
$(shell mkdir -p $(SPECIAL_OUTDIRS) )

# Rules

AUTO_GEN_TARGETS += $(INCLUDECONSTS_OUTDIR)/map_groups.h
AUTO_GEN_TARGETS += $(INCLUDECONSTS_OUTDIR)/layouts.h

# Master files (additional dependencies added on the auto-generated rule)
$(DATA_ASM_BUILDDIR)/maps.o: $(LAYOUTS_OUTDIR)/layouts.inc $(LAYOUTS_OUTDIR)/layouts_table.inc \
                             $(MAPS_OUTDIR)/headers.inc $(MAPS_OUTDIR)/groups.inc $(MAPS_OUTDIR)/connections.inc \
                             $(MAP_CONNECTIONS) $(MAP_HEADERS)

$(DATA_ASM_BUILDDIR)/map_events.o: $(MAPS_OUTDIR)/events.inc $(MAP_EVENTS)

# Individual maps
$(MAPS_OUTDIR)/%/header.inc $(MAPS_OUTDIR)/%/events.inc $(MAPS_OUTDIR)/%/connections.inc: $(MAPS_DIR)/%/map.json
	$(MAPJSON) map emerald $< $(LAYOUTS_DIR)/layouts.json $(@D)

$(MAPS_OUTDIR)/connections.inc $(MAPS_OUTDIR)/groups.inc $(MAPS_OUTDIR)/events.inc $(MAPS_OUTDIR)/headers.inc $(INCLUDECONSTS_OUTDIR)/map_groups.h: $(MAPS_DIR)/map_groups.json
	$(MAPJSON) groups emerald $< $(MAPS_OUTDIR) $(INCLUDECONSTS_OUTDIR)

$(LAYOUTS_OUTDIR)/layouts.inc $(LAYOUTS_OUTDIR)/layouts_table.inc $(INCLUDECONSTS_OUTDIR)/layouts.h: $(LAYOUTS_DIR)/layouts.json
	$(MAPJSON) layouts emerald $< $(LAYOUTS_OUTDIR) $(INCLUDECONSTS_OUTDIR)