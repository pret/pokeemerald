# JSON files are run through jsonproc, which is a tool that converts JSON data to an output file
# based on an Inja template. https://github.com/pantor/inja

AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/wild_encounters.h


$(DATA_SRC_SUBDIR)/wild_encounters.h: $(DATA_SRC_SUBDIR)/wild_encounters.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/wild_encounter.o: c_dep += $(DATA_SRC_SUBDIR)/wild_encounters.h



SPECIES_JSON := $(DATA_ASM_SUBDIR)/pokemon_species.json

GRAPHICS_SUBDIR := $(DATA_SRC_SUBDIR)/graphics
TEXT_SUBDIR := $(DATA_SRC_SUBDIR)/text
PKMN_SUBDIR := $(DATA_SRC_SUBDIR)/pokemon
PKMN_GRAPHICS_SUBDIR := $(DATA_SRC_SUBDIR)/pokemon_graphics


SPECIES_TEMPLATES_TEST := $(addsuffix .tmp.h,		\
	include/graphics_pokemon.h						\
	$(GRAPHICS_SUBDIR)/pokemon.h					\
	$(GRAPHICS_SUBDIR)/anim_mon_front_pics.h		\
	$(PKMN_GRAPHICS_SUBDIR)/front_pic_table.h		\
	$(PKMN_GRAPHICS_SUBDIR)/back_pic_table.h		\
	$(PKMN_GRAPHICS_SUBDIR)/footprint_table.h		\
	$(PKMN_GRAPHICS_SUBDIR)/palette_table.h			\
	$(PKMN_GRAPHICS_SUBDIR)/shiny_palette_table.h	\
	$(PKMN_GRAPHICS_SUBDIR)/still_front_pic_table.h	\
	$(PKMN_GRAPHICS_SUBDIR)/icon.h					\
	$(PKMN_GRAPHICS_SUBDIR)/jump.h					\
	$(PKMN_GRAPHICS_SUBDIR)/animation.h				\
	$(PKMN_GRAPHICS_SUBDIR)/unknown_anims.h)

SPECIES_TEMPLATES :=								\
	include/constants/species.h						\
	$(PKMN_SUBDIR)/base_stats.h						\
	$(PKMN_SUBDIR)/egg_moves.h						\
    $(PKMN_SUBDIR)/evolution.h                      \
	$(PKMN_SUBDIR)/pokedex_entries.h				\
	$(PKMN_SUBDIR)/pokedex_text.h					\
	$(PKMN_SUBDIR)/level_up_learnsets.h				\
	$(PKMN_SUBDIR)/level_up_learnset_pointers.h		\
	$(PKMN_SUBDIR)/tutor_learnsets.h                \
	$(PKMN_SUBDIR)/tmhm_learnsets.h 				\
	$(PKMN_GRAPHICS_SUBDIR)/back_pic_coordinates.h	\
	$(PKMN_GRAPHICS_SUBDIR)/front_pic_anims.h		\
	$(PKMN_GRAPHICS_SUBDIR)/front_pic_coordinates.h	\
	$(TEXT_SUBDIR)/species_names.h

AUTO_GEN_TARGETS += $(SPECIES_TEMPLATES_TEST)
AUTO_GEN_TARGETS += $(SPECIES_TEMPLATES)

$(SPECIES_TEMPLATES_TEST): %.h.tmp.h: $(SPECIES_JSON) %.h.template
	$(JSONPROC) $^ $@

$(SPECIES_TEMPLATES): %.h: $(SPECIES_JSON) %.h.template
	$(JSONPROC) $^ $@

species_templates_test: $(SPECIES_TEMPLATES_TEST)

species_templates: $(SPECIES_TEMPLATES)


$(C_BUILDDIR)/daycare.o: 	c_dep += $(PKMN_SUBDIR)/egg_moves.h
$(C_BUILDDIR)/party_menu.o: c_dep += $(PKMN_SUBDIR)/tutor_learnsets.h
$(C_BUILDDIR)/pokemon.o: 	c_dep += $(PKMN_SUBDIR)/evolution.h $(PKMN_SUBDIR)/level_up_learnsets.h $(PKMN_SUBDIR)/level_up_learnset_pointers.h $(PKMN_SUBDIR)/tmhm_learnsets.h
$(C_BUILDDIR)/pokedex.o:	c_dep += $(PKMN_SUBDIR)/pokedex_entries.h $(PKMN_SUBDIR)/pokedex_text.h
$(C_BUILDDIR)/evolution_scene.o: c_dep += $(PKMN_SUBDIR)/evolution.h
$(C_BUILDDIR)/data.o:       c_dep += $(PKMN_GRAPHICS_SUBDIR)/back_pic_coordinates.h $(PKMN_GRAPHICS_SUBDIR)/front_pic_anims.h $(PKMN_GRAPHICS_SUBDIR)/front_pic_coordinates.h
