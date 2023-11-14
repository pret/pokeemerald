# This file contains numerous rules for graphics files that require special behaviour when building.

TILESETGFXDIR := data/tilesets
BATINTGFXDIR := graphics/battle_interface
BATTRANSGFXDIR := graphics/battle_transitions
BTLANMSPRGFXDIR := graphics/battle_anims/sprites
CASTFORMGFXDIR := graphics/pokemon/castform
FONTGFXDIR := graphics/fonts
JPCONTESTGFXDIR := graphics/contest/japanese
MISCGFXDIR := graphics/misc
NAMINGGFXDIR := graphics/naming_screen
PKNAVGFXDIR := graphics/pokenav
PKNAVOPTIONSGFXDIR := graphics/pokenav/options
POKEDEXGFXDIR := graphics/pokedex
RAYQUAZAGFXDIR := graphics/rayquaza_scene
ROULETTEGFXDIR := graphics/roulette
SLOTMACHINEGFXDIR := graphics/slot_machine
SPINDAGFXDIR := graphics/pokemon/spinda/spots
STARTERGFXDIR := graphics/starter_choose
TYPESGFXDIR := graphics/types
UNKNOWNGFXDIR := graphics/unknown
UNUSEDGFXDIR := graphics/unused
WALLPAPERGFXDIR := graphics/pokemon_storage/wallpapers

types := normal fight flying poison ground rock bug ghost steel mystery fire water grass electric psychic ice dragon dark
contest_types := cool beauty cute smart tough
castform_types := normal sunny rainy snowy

# Output folders
TILESET_OUTDIR      := $(TILESETGFXDIR)
BATINT_OUTDIR       := $(BATINTGFXDIR)
BATTRANS_OUTDIR     := $(BATTRANSGFXDIR)
BTLANMSPR_OUTDIR    := $(BTLANMSPRGFXDIR)
CASTFORM_OUTDIR     := $(CASTFORMGFXDIR)
FONT_OUTDIR         := $(FONTGFXDIR)
JPCONTEST_OUTDIR    := $(JPCONTESTGFXDIR)
MISC_OUTDIR         := $(MISCGFXDIR)
NAMING_OUTDIR       := $(NAMINGGFXDIR)
PKNAV_OUTDIR        := $(PKNAVGFXDIR)
PKNAVOPTIONS_OUTDIR := $(PKNAVOPTIONSGFXDIR)
POKEDEX_OUTDIR      := $(POKEDEXGFXDIR)
RAYQUAZA_OUTDIR     := $(RAYQUAZAGFXDIR)
ROULETTE_OUTDIR     := $(ROULETTEGFXDIR)
SLOTMACHINE_OUTDIR  := $(SLOTMACHINEGFXDIR)
SPINDA_OUTDIR       := $(SPINDAGFXDIR)
TYPES_OUTDIR        := $(TYPESGFXDIR)
UNUSED_OUTDIR       := $(UNUSEDGFXDIR)
WALLPAPER_OUTDIR    := $(WALLPAPERGFXDIR)

# TODO: A nicer way to create the directory tree
SPECIAL_OUTDIRS := $(CASTFORM_OUTDIR) $(patsubst %,$(CASTFORM_OUTDIR)/%,$(castform_types)) 
SPECIAL_OUTDIRS += $(TILESET_OUTDIR) $(FONT_OUTDIR) $(BTLANMSPR_OUTDIR) $(UNUSED_OUTDIR) $(BATINT_OUTDIR) $(BATTRANS_OUTDIR) $(TYPES_OUTDIR) $(RAYQUAZA_OUTDIR) $(ROULETTE_OUTDIR) $(SLOTMACHINE_OUTDIR) $(PKNAV_OUTDIR) $(PKNAVOPTIONS_OUTDIR) $(WALLPAPER_OUTDIR) $(MISC_OUTDIR) $(JPCONTEST_OUTDIR) $(POKEDEX_OUTDIR) $(NAMING_OUTDIR) $(SPINDA_OUTDIR)
$(shell mkdir -p $(SPECIAL_OUTDIRS))

# Rules in order as they are defined above:
#---------------------------------------------

### Tilesets
$(TILESET_OUTDIR)/secondary/petalburg/tiles.4bpp: $(TILESETGFXDIR)/secondary/petalburg/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 159 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/rustboro/tiles.4bpp: $(TILESETGFXDIR)/secondary/rustboro/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 498 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/dewford/tiles.4bpp: $(TILESETGFXDIR)/secondary/dewford/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 503 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/slateport/tiles.4bpp: $(TILESETGFXDIR)/secondary/slateport/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 504 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/mauville/tiles.4bpp: $(TILESETGFXDIR)/secondary/mauville/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 503 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/lavaridge/tiles.4bpp: $(TILESETGFXDIR)/secondary/lavaridge/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 450 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/fortree/tiles.4bpp: $(TILESETGFXDIR)/secondary/fortree/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 493 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/pacifidlog/tiles.4bpp: $(TILESETGFXDIR)/secondary/pacifidlog/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 504 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/sootopolis/tiles.4bpp: $(TILESETGFXDIR)/secondary/sootopolis/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 328 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/battle_frontier_outside_west/tiles.4bpp: $(TILESETGFXDIR)/secondary/battle_frontier_outside_west/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 508 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/battle_frontier_outside_east/tiles.4bpp: $(TILESETGFXDIR)/secondary/battle_frontier_outside_east/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 508 -Wnum_tiles

$(TILESET_OUTDIR)/primary/building/tiles.4bpp: $(TILESETGFXDIR)/primary/building/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 502 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/shop/tiles.4bpp: $(TILESETGFXDIR)/secondary/shop/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 502 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/pokemon_center/tiles.4bpp: $(TILESETGFXDIR)/secondary/pokemon_center/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 478 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/cave/tiles.4bpp: $(TILESETGFXDIR)/secondary/cave/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 425 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/pokemon_school/tiles.4bpp: $(TILESETGFXDIR)/secondary/pokemon_school/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 278 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/pokemon_fan_club/tiles.4bpp: $(TILESETGFXDIR)/secondary/pokemon_fan_club/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 319 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/unused_1/tiles.4bpp: $(TILESETGFXDIR)/secondary/unused_1/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 17 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/meteor_falls/tiles.4bpp: $(TILESETGFXDIR)/secondary/meteor_falls/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 460 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/oceanic_museum/tiles.4bpp: $(TILESETGFXDIR)/secondary/oceanic_museum/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 319 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/cable_club/unknown_tiles.4bpp: $(TILESETGFXDIR)/secondary/cable_club/unknown_tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 120 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/seashore_house/tiles.4bpp: $(TILESETGFXDIR)/secondary/seashore_house/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 312 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/pretty_petal_flower_shop/tiles.4bpp: $(TILESETGFXDIR)/secondary/pretty_petal_flower_shop/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 345 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/pokemon_day_care/tiles.4bpp: $(TILESETGFXDIR)/secondary/pokemon_day_care/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 355 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/brown_cave/tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/brown_cave/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/tree/tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/tree/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/shrub/tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/shrub/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/blue_cave/tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/blue_cave/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/yellow_cave/tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/yellow_cave/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/red_cave/tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/red_cave/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 83 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/inside_of_truck/tiles.4bpp: $(TILESETGFXDIR)/secondary/inside_of_truck/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 62 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/contest/tiles.4bpp: $(TILESETGFXDIR)/secondary/contest/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 430 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/lilycove_museum/tiles.4bpp: $(TILESETGFXDIR)/secondary/lilycove_museum/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 431 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/lab/tiles.4bpp: $(TILESETGFXDIR)/secondary/lab/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 500 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/underwater/tiles.4bpp: $(TILESETGFXDIR)/secondary/underwater/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 500 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/generic_building/tiles.4bpp: $(TILESETGFXDIR)/secondary/generic_building/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 509 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/mauville_game_corner/tiles.4bpp: $(TILESETGFXDIR)/secondary/mauville_game_corner/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 469 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/unused_2/tiles.4bpp: $(TILESETGFXDIR)/secondary/unused_2/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 150 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/rustboro_gym/tiles.4bpp: $(TILESETGFXDIR)/secondary/rustboro_gym/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 60 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/dewford_gym/tiles.4bpp: $(TILESETGFXDIR)/secondary/dewford_gym/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 61 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/lavaridge_gym/tiles.4bpp: $(TILESETGFXDIR)/secondary/lavaridge_gym/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 54 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/petalburg_gym/tiles.4bpp: $(TILESETGFXDIR)/secondary/petalburg_gym/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 148 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/fortree_gym/tiles.4bpp: $(TILESETGFXDIR)/secondary/fortree_gym/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 61 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/mossdeep_gym/tiles.4bpp: $(TILESETGFXDIR)/secondary/mossdeep_gym/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/sootopolis_gym/tiles.4bpp: $(TILESETGFXDIR)/secondary/sootopolis_gym/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 484 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/trick_house_puzzle/tiles.4bpp: $(TILESETGFXDIR)/secondary/trick_house_puzzle/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 294 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/inside_ship/tiles.4bpp: $(TILESETGFXDIR)/secondary/inside_ship/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 342 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/elite_four/tiles.4bpp: $(TILESETGFXDIR)/secondary/elite_four/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 505 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/battle_frontier/tiles.4bpp: $(TILESETGFXDIR)/secondary/battle_frontier/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 310 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/battle_factory/tiles.4bpp: $(TILESETGFXDIR)/secondary/battle_factory/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 424 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/battle_pike/tiles.4bpp: $(TILESETGFXDIR)/secondary/battle_pike/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 382 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/mirage_tower/tiles.4bpp: $(TILESETGFXDIR)/secondary/mirage_tower/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 420 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/mossdeep_game_corner/tiles.4bpp: $(TILESETGFXDIR)/secondary/mossdeep_game_corner/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 95 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/island_harbor/tiles.4bpp: $(TILESETGFXDIR)/secondary/island_harbor/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 503 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/trainer_hill/tiles.4bpp: $(TILESETGFXDIR)/secondary/trainer_hill/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 374 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/navel_rock/tiles.4bpp: $(TILESETGFXDIR)/secondary/navel_rock/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 420 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/battle_frontier_ranking_hall/tiles.4bpp: $(TILESETGFXDIR)/secondary/battle_frontier_ranking_hall/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 136 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/mystery_events_house/tiles.4bpp: $(TILESETGFXDIR)/secondary/mystery_events_house/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 509 -Wnum_tiles

#### Unused Tilesets
$(TILESET_OUTDIR)/secondary/secret_base/brown_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/brown_cave/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/tree/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/tree/tiles.png
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/shrub/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/shrub/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/blue_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/blue_cave/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/yellow_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/yellow_cave/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles

$(TILESET_OUTDIR)/secondary/secret_base/red_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/red_cave/tiles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 82 -Wnum_tiles


### Battle Interface
$(BATINT_OUTDIR)/textbox.gbapal: $(BATINT_OUTDIR)/textbox_0.gbapal \
                                $(BATINT_OUTDIR)/textbox_1.gbapal
	cat $^ >$@

$(BATINT_OUTDIR)/battle_bar.4bpp: $(BATINT_OUTDIR)/hpbar_anim_unused.4bpp \
                                 $(BATINT_OUTDIR)/numbers1.4bpp \
                                 $(BATINT_OUTDIR)/numbers2.4bpp
	cat $^ >$@

$(BATINT_OUTDIR)/unused_window2bar.4bpp: $(BATINTGFXDIR)/unused_window2bar.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

### Battle Transitions
$(BATTRANS_OUTDIR)/vs_frame.4bpp: $(BATTRANSGFXDIR)/vs_frame.png
	$(GFX) $< $@ -num_tiles 16 -Wnum_tiles

$(BATTRANS_OUTDIR)/regis.4bpp: $(BATTRANSGFXDIR)/regis.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(BATTRANS_OUTDIR)/rayquaza.4bpp: $(BATTRANSGFXDIR)/rayquaza.png
	$(GFX) $< $@ -num_tiles 938 -Wnum_tiles

$(BATTRANS_OUTDIR)/frontier_logo_center.4bpp: $(BATTRANSGFXDIR)/frontier_logo_center.png
	$(GFX) $< $@ -num_tiles 43 -Wnum_tiles

$(BATTRANS_OUTDIR)/frontier_square_1.4bpp: $(BATTRANS_OUTDIR)/frontier_squares_blanktiles.4bpp $(BATTRANS_OUTDIR)/frontier_squares_1.4bpp
	cat $^ >$@

$(BATTRANS_OUTDIR)/frontier_square_2.4bpp: $(BATTRANS_OUTDIR)/frontier_squares_blanktiles.4bpp $(BATTRANS_OUTDIR)/frontier_squares_2.4bpp
	cat $^ >$@

$(BATTRANS_OUTDIR)/frontier_square_3.4bpp: $(BATTRANS_OUTDIR)/frontier_squares_blanktiles.4bpp $(BATTRANS_OUTDIR)/frontier_squares_3.4bpp
	cat $^ >$@

$(BATTRANS_OUTDIR)/frontier_square_4.4bpp: $(BATTRANS_OUTDIR)/frontier_squares_blanktiles.4bpp $(BATTRANS_OUTDIR)/frontier_squares_4.4bpp
	cat $^ >$@

### Battle animation sprites
$(BTLANMSPR_OUTDIR)/ice_cube.4bpp: $(BTLANMSPR_OUTDIR)/ice_cube_0.4bpp \
                                  $(BTLANMSPR_OUTDIR)/ice_cube_1.4bpp \
                                  $(BTLANMSPR_OUTDIR)/ice_cube_2.4bpp \
                                  $(BTLANMSPR_OUTDIR)/ice_cube_3.4bpp
	cat $^ >$@

$(BTLANMSPR_OUTDIR)/ice_crystals.4bpp: $(BTLANMSPR_OUTDIR)/ice_crystals_0.4bpp \
                                      $(BTLANMSPR_OUTDIR)/ice_crystals_1.4bpp \
                                      $(BTLANMSPR_OUTDIR)/ice_crystals_2.4bpp \
                                      $(BTLANMSPR_OUTDIR)/ice_crystals_3.4bpp \
                                      $(BTLANMSPR_OUTDIR)/ice_crystals_4.4bpp
	cat $^ >$@

$(BTLANMSPR_OUTDIR)/mud_sand.4bpp: $(BTLANMSPR_OUTDIR)/mud_sand_0.4bpp \
                                  $(BTLANMSPR_OUTDIR)/mud_sand_1.4bpp
	cat $^ >$@

$(BTLANMSPR_OUTDIR)/flower.4bpp: $(BTLANMSPR_OUTDIR)/flower_0.4bpp \
                                $(BTLANMSPR_OUTDIR)/flower_1.4bpp
	cat $^ >$@

$(BTLANMSPR_OUTDIR)/spark.4bpp: $(BTLANMSPR_OUTDIR)/spark_0.4bpp \
                               $(BTLANMSPR_OUTDIR)/spark_1.4bpp
	cat $^ >$@


### Castform has all 4 of its forms joined together before compression
$(CASTFORM_OUTDIR)/front.4bpp: $(patsubst %,$(CASTFORM_OUTDIR)/%/front.4bpp,$(castform_types))
	cat $^ >$@

$(CASTFORM_OUTDIR)/back.4bpp: $(patsubst %,$(CASTFORM_OUTDIR)/%/back.4bpp,$(castform_types))
	cat $^ >$@

$(CASTFORM_OUTDIR)/anim_front.4bpp: $(patsubst %,$(CASTFORM_OUTDIR)/%/anim_front.4bpp,$(castform_types))
	cat $^ >$@

$(CASTFORM_OUTDIR)/normal.gbapal: $(patsubst %,$(CASTFORM_OUTDIR)/%/normal.gbapal,$(castform_types))
	cat $^ >$@

$(CASTFORM_OUTDIR)/shiny.gbapal: $(patsubst %,$(CASTFORM_OUTDIR)/%/shiny.gbapal,$(castform_types))
	cat $^ >$@

### Fonts ###
$(FONT_OUTDIR)/%.latfont: $(FONTGFXDIR)/latin_%.png
	$(GFX) $< $@

$(FONT_OUTDIR)/braille.fwjpnfont: $(FONTGFXDIR)/braille.png
	$(GFX) $< $@

$(FONT_OUTDIR)/%.hwjpnfont: $(FONTGFXDIR)/japanese_%.png
	$(GFX) $< $@

$(FONT_OUTDIR)/%.fwjpnfont: $(FONTGFXDIR)/japanese_%.png
	$(GFX) $< $@

### Japaneese Contests
jpcontest_composite1 = frame_1 floor frame_2 symbols meter letters numbers
$(JPCONTEST_OUTDIR)/composite_1.4bpp: $(patsubst %,$(JPCONTEST_OUTDIR)/%.4bpp,$(jpcontest_composite1))
	cat $^ >$@

$(JPCONTEST_OUTDIR)/composite_2.4bpp: $(JPCONTEST_OUTDIR)/interface.4bpp \
                                     $(JPCONTEST_OUTDIR)/audience.4bpp
	cat $^ >$@

$(JPCONTEST_OUTDIR)/voltage.4bpp: $(JPCONTESTGFXDIR)/voltage.png
	$(GFX) $< $@ -num_tiles 36 -Wnum_tiles

### Misc
$(MISC_OUTDIR)/japanese_hof.4bpp: $(MISCGFXDIR)/japanese_hof.png
	$(GFX) $< $@ -num_tiles 29 -Wnum_tiles

### Text entry (Naming) screen
$(NAMING_OUTDIR)/cursor.4bpp: $(NAMINGGFXDIR)/cursor.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

$(NAMING_OUTDIR)/cursor_squished.4bpp: $(NAMINGGFXDIR)/cursor_squished.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

$(NAMING_OUTDIR)/cursor_filled.4bpp: $(NAMINGGFXDIR)/cursor_filled.png
	$(GFX) $< $@ -num_tiles 5 -Wnum_tiles

### Pokenav
pknav_options = hoenn_map condition match_call ribbons switch_off party search $(contest_types) cancel
$(PKNAVOPTIONS_OUTDIR)/options.4bpp: $(patsubst %,$(PKNAVOPTIONS_OUTDIR)/%.4bpp,$(pknav_options))
	cat $^ >$@

$(PKNAV_OUTDIR)/header.4bpp : $(PKNAVGFXDIR)/header.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(PKNAV_OUTDIR)/device_outline.4bpp : $(PKNAVGFXDIR)/device_outline.png
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

$(PKNAV_OUTDIR)/match_call/ui.4bpp : $(PKNAVGFXDIR)/match_call/ui.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 13 -Wnum_tiles

$(PKNAV_OUTDIR)/region_map/map.8bpp: $(PKNAVGFXDIR)/region_map/map.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 233 -Wnum_tiles

### Region map (Pokedex)
$(POKEDEX_OUTDIR)/region_map.8bpp: $(POKEDEXGFXDIR)/region_map.png
	$(GFX) $< $@ -num_tiles 232 -Wnum_tiles

$(POKEDEX_OUTDIR)/region_map_affine.8bpp: $(POKEDEXGFXDIR)/region_map_affine.png
	$(GFX) $< $@ -num_tiles 233 -Wnum_tiles

### Rayquaza scene
$(RAYQUAZA_OUTDIR)/scene_2/rayquaza.8bpp: $(RAYQUAZAGFXDIR)/scene_2/rayquaza.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 227 -Wnum_tiles

$(RAYQUAZA_OUTDIR)/scene_2/bg.4bpp: $(RAYQUAZAGFXDIR)/scene_2/bg.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 313 -Wnum_tiles

$(RAYQUAZA_OUTDIR)/scene_3/rayquaza.4bpp: $(RAYQUAZAGFXDIR)/scene_3/rayquaza.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 124 -Wnum_tiles

$(RAYQUAZA_OUTDIR)/scene_3/rayquaza_tail_fix.4bpp: $(RAYQUAZA_OUTDIR)/scene_3/rayquaza_tail.4bpp
	mkdir -p $(@D)
	cp $< $@
	head -c 12 /dev/zero >> $@

$(RAYQUAZA_OUTDIR)/scene_4/streaks.4bpp: $(RAYQUAZAGFXDIR)/scene_4/streaks.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 19 -Wnum_tiles

$(RAYQUAZA_OUTDIR)/scene_4/rayquaza.4bpp: $(RAYQUAZAGFXDIR)/scene_4/rayquaza.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 155 -Wnum_tiles

### Game Corner
$(ROULETTE_OUTDIR)/roulette_tilt.4bpp: $(ROULETTE_OUTDIR)/shroomish.4bpp \
                                      $(ROULETTE_OUTDIR)/tailow.4bpp
	cat $^ >$@

$(ROULETTE_OUTDIR)/wheel_icons.4bpp: $(ROULETTE_OUTDIR)/wynaut.4bpp \
                                    $(ROULETTE_OUTDIR)/azurill.4bpp \
                                    $(ROULETTE_OUTDIR)/skitty.4bpp \
                                    $(ROULETTE_OUTDIR)/makuhita.4bpp
	cat $^ >$@

$(SLOTMACHINE_OUTDIR)/reel_time_gfx.4bpp: $(SLOTMACHINE_OUTDIR)/reel_time_pikachu.4bpp \
                                         $(SLOTMACHINE_OUTDIR)/reel_time_machine.4bpp
	cat $^ >$@

### Spinda
$(SPINDA_OUTDIR)/%.1bpp: $(SPINDAGFXDIR)/%.png
	$(GFX) $< $@ -plain -data_width 2

### Pokemon types
$(TYPES_OUTDIR)/move_types.gbapal: $(TYPES_OUTDIR)/move_types_1.gbapal \
                                  $(TYPES_OUTDIR)/move_types_2.gbapal \
                                  $(TYPES_OUTDIR)/move_types_3.gbapal
	cat $^ >$@

$(TYPES_OUTDIR)/move_types.4bpp: $(types:%=$(TYPES_OUTDIR)/%.4bpp) $(contest_types:%=$(TYPES_OUTDIR)/contest_%.4bpp)
	cat $^ >$@

### Unused Graphics
$(UNUSED_OUTDIR)/obi_palpak1.gbapal: $(patsubst %,$(UNUSED_OUTDIR)/old_pal%.gbapal,1 2 3)
	cat $^ >$@

$(UNUSED_OUTDIR)/obi_palpak3.gbapal: $(patsubst %,$(UNUSED_OUTDIR)/old_pal%.gbapal,5 6 7)
	cat $^ >$@

$(UNUSED_OUTDIR)/obi1.4bpp: $(UNUSED_OUTDIR)/old_bulbasaur.4bpp \
                           $(UNUSED_OUTDIR)/old_charizard.4bpp
	cat $^ >$@

$(UNUSED_OUTDIR)/obi2.4bpp: $(UNUSED_OUTDIR)/old_bulbasaur2.4bpp \
                           $(UNUSED_OUTDIR)/old_battle_interface_1.4bpp \
                           $(UNUSED_OUTDIR)/old_battle_interface_2.4bpp \
                           $(UNUSED_OUTDIR)/old_battle_interface_3.4bpp
	cat $^ >$@

$(UNUSED_OUTDIR)/color_frames.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 353 -Wnum_tiles

unused_frames := red_frame yellow_frame green_frame blank_frame
$(UNUSED_OUTDIR)/redyellowgreen_frame.bin: $(patsubst %,$(UNUSEDGFXDIR)/%.bin,$(unused_frames))
	cat $^ >$@

### Pokémon Storage System
#### Base images
$(WALLPAPER_OUTDIR)/forest/frame.4bpp: $(WALLPAPERGFXDIR)/forest/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 55 -Wnum_tiles

$(WALLPAPER_OUTDIR)/city/frame.4bpp: $(WALLPAPERGFXDIR)/city/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 52 -Wnum_tiles

$(WALLPAPER_OUTDIR)/savanna/frame.4bpp: $(WALLPAPERGFXDIR)/savanna/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 45 -Wnum_tiles

$(WALLPAPER_OUTDIR)/savanna/bg.4bpp: $(WALLPAPERGFXDIR)/savanna/bg.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 23 -Wnum_tiles

$(WALLPAPER_OUTDIR)/crag/frame.4bpp: $(WALLPAPERGFXDIR)/crag/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 49 -Wnum_tiles

$(WALLPAPER_OUTDIR)/volcano/frame.4bpp: $(WALLPAPERGFXDIR)/volcano/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 56 -Wnum_tiles

$(WALLPAPER_OUTDIR)/snow/frame.4bpp: $(WALLPAPERGFXDIR)/snow/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 57 -Wnum_tiles

$(WALLPAPER_OUTDIR)/cave/frame.4bpp: $(WALLPAPERGFXDIR)/cave/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 55 -Wnum_tiles

$(WALLPAPER_OUTDIR)/beach/frame.4bpp: $(WALLPAPERGFXDIR)/beach/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 46 -Wnum_tiles

$(WALLPAPER_OUTDIR)/beach/bg.4bpp: $(WALLPAPERGFXDIR)/beach/bg.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 23 -Wnum_tiles

$(WALLPAPER_OUTDIR)/seafloor/frame.4bpp: $(WALLPAPERGFXDIR)/seafloor/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 54 -Wnum_tiles

$(WALLPAPER_OUTDIR)/river/frame.4bpp: $(WALLPAPERGFXDIR)/river/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 51 -Wnum_tiles

$(WALLPAPER_OUTDIR)/river/bg.4bpp: $(WALLPAPERGFXDIR)/river/bg.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 11 -Wnum_tiles

$(WALLPAPER_OUTDIR)/sky/frame.4bpp: $(WALLPAPERGFXDIR)/sky/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 45 -Wnum_tiles

$(WALLPAPER_OUTDIR)/polkadot/frame.4bpp: $(WALLPAPERGFXDIR)/polkadot/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 54 -Wnum_tiles

$(WALLPAPER_OUTDIR)/pokecenter/frame.4bpp: $(WALLPAPERGFXDIR)/pokecenter/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 35 -Wnum_tiles

$(WALLPAPER_OUTDIR)/machine/frame.4bpp: $(WALLPAPERGFXDIR)/machine/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 33 -Wnum_tiles

$(WALLPAPER_OUTDIR)/plain/frame.4bpp: $(WALLPAPERGFXDIR)/plain/frame.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 18 -Wnum_tiles

$(WALLPAPER_OUTDIR)/friends_frame1.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 57 -Wnum_tiles

$(WALLPAPER_OUTDIR)/friends_frame2.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 57 -Wnum_tiles

#### Compound wallpapers
$(WALLPAPER_OUTDIR)/%/tiles.4bpp: $(WALLPAPER_OUTDIR)/%/frame.4bpp $(WALLPAPER_OUTDIR)/%/bg.4bpp
	@mkdir -p $(@D)
	cat $^ >$@

$(WALLPAPERGFXDIR)/zigzagoon/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/zigzagoon/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/screen/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/screen/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/horizontal/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/horizontal/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/diagonal/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/diagonal/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/block/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/block/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/ribbon/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/ribbon/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/pokecenter2/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/pokecenter2/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/frame/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/frame/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/blank/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/blank/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/circles/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame1.4bpp $(WALLPAPERGFXDIR)/circles/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/azumarill/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/azumarill/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/pikachu/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/pikachu/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/legendary/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/legendary/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/dusclops/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/dusclops/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/ludicolo/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/ludicolo/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/whiscash/tiles.4bpp: $(WALLPAPERGFXDIR)/friends_frame2.4bpp $(WALLPAPERGFXDIR)/whiscash/bg.4bpp
	@cat $^ >$@

### Miscellaneous ###
graphics/interface/outline_cursor.4bpp: graphics/interface/outline_cursor.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 8 -Wnum_tiles

graphics/battle_anims/masks/unused_level_up.4bpp: graphics/battle_anims/masks/unused_level_up.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 14 -Wnum_tiles

graphics/party_menu/bg.4bpp: graphics/party_menu/bg.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 62 -Wnum_tiles

graphics/title_screen/pokemon_logo.gbapal: graphics/title_screen/pokemon_logo.pal
	mkdir -p $(@D)
	$(GFX) $< $@ -num_colors 224

graphics/pokemon_jump/bg.4bpp: graphics/pokemon_jump/bg.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 63 -Wnum_tiles

graphics/bag/menu.4bpp: graphics/bag/menu.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 53 -Wnum_tiles

graphics/picture_frame/lobby.4bpp: graphics/picture_frame/lobby.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 86 -Wnum_tiles

graphics/birch_speech/unused_beauty.4bpp: graphics/birch_speech/unused_beauty.png
	mkdir -p $(@D)
	$(GFX) $< $@ -num_tiles 822 -Wnum_tiles