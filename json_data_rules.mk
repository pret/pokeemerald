# JSON files are run through jsonproc, which is a tool that converts JSON data to an output file
# based on an Inja template. https://github.com/pantor/inja

DATA_SRC_OUTDIR := $(BUILD_ASSETS_DIR)/include/generated/data

SPECIAL_OUTDIRS := $(DATA_SRC_OUTDIR) $(DATA_SRC_OUTDIR)/region_map
$(shell mkdir -p $(SPECIAL_OUTDIRS) )

AUTO_GEN_TARGETS += $(DATA_SRC_OUTDIR)/wild_encounters.h
AUTO_GEN_TARGETS += $(DATA_SRC_OUTDIR)/region_map/region_map_entries.h

$(DATA_SRC_OUTDIR)/wild_encounters.h: $(DATA_SRC_SUBDIR)/wild_encounters.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt
	$(JSONPROC) $^ $@

$(DATA_SRC_OUTDIR)/region_map/region_map_entries.h: $(DATA_SRC_SUBDIR)/region_map/region_map_sections.json $(DATA_SRC_SUBDIR)/region_map/region_map_sections.json.txt
	$(JSONPROC) $^ $@