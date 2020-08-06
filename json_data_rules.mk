# JSON files are run through jsonproc, which is a tool that converts JSON data to an output file
# based on an Inja template. https://github.com/pantor/inja

AUTO_GEN_HEADERS += $(DATA_SRC_SUBDIR)/wild_encounters.h


$(DATA_SRC_SUBDIR)/wild_encounters.h: $(DATA_SRC_SUBDIR)/wild_encounters.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/wild_encounter.o: c_dep += $(DATA_SRC_SUBDIR)/wild_encounters.h



SPECIES_JSON := $(DATA_ASM_SUBDIR)/pokemon_species.json

GRAPHICS_SUBDIR := $(DATA_SRC_SUBDIR)/graphics
TEXT_SUBDIR := $(DATA_SRC_SUBDIR)/text
PKMN_SUBDIR := $(DATA_SRC_SUBDIR)/pokemon
PKMN_GRAPHICS_SUBDIR := $(DATA_SRC_SUBDIR)/pokemon_graphics


SPECIES_HEADERS :=                                  \
    include/constants/species.h                     \
    include/graphics_pokemon.h                      \
    $(GRAPHICS_SUBDIR)/pokemon.h                    \
    $(PKMN_SUBDIR)/base_stats.h                     \
    $(PKMN_SUBDIR)/egg_moves.h                      \
    $(PKMN_SUBDIR)/evolution.h                      \
    $(PKMN_SUBDIR)/pokedex_entries.h                \
    $(PKMN_SUBDIR)/pokedex_text.h                   \
    $(PKMN_SUBDIR)/pokemon_jump_table.h             \
    $(PKMN_SUBDIR)/level_up_learnsets.h             \
    $(PKMN_SUBDIR)/level_up_learnset_pointers.h     \
    $(PKMN_SUBDIR)/tutor_learnsets.h                \
    $(PKMN_SUBDIR)/tmhm_learnsets.h                 \
    $(PKMN_GRAPHICS_SUBDIR)/back_animation.h        \
    $(PKMN_GRAPHICS_SUBDIR)/back_pic_coordinates.h  \
    $(PKMN_GRAPHICS_SUBDIR)/back_pic_table.h        \
    $(PKMN_GRAPHICS_SUBDIR)/footprint_table.h       \
    $(PKMN_GRAPHICS_SUBDIR)/front_animation.h       \
    $(PKMN_GRAPHICS_SUBDIR)/front_pic_anims.h       \
    $(PKMN_GRAPHICS_SUBDIR)/front_pic_coordinates.h \
    $(PKMN_GRAPHICS_SUBDIR)/front_pic_table.h       \
    $(PKMN_GRAPHICS_SUBDIR)/icon.h                  \
    $(PKMN_GRAPHICS_SUBDIR)/palette_table.h         \
    $(PKMN_GRAPHICS_SUBDIR)/shiny_palette_table.h   \
    $(PKMN_GRAPHICS_SUBDIR)/still_front_pic_table.h \
    $(PKMN_GRAPHICS_SUBDIR)/unknown_anims.h         \
    $(TEXT_SUBDIR)/species_names.h
SPECIES_SRCS :=                                     \
    src/anim_mon_front_pics.c

AUTO_GEN_HEADERS += $(SPECIES_HEADERS)
AUTO_GEN_SRCS    += $(SPECIES_SRCS)

$(SPECIES_HEADERS): %.h: $(SPECIES_JSON) %.h.template
	$(JSONPROC) $^ $@
$(SPECIES_SRCS): %.c: $(SPECIES_JSON) %.c.template
	$(JSONPROC) $^ $@

species_templates: $(SPECIES_HEADERS) $(SPECIES_SRCS)
