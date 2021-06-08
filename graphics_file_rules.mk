CASTFORMGFXDIR := graphics/pokemon/castform
CHERRIMGFXDIR := graphics/pokemon/cherrim
TILESETGFXDIR := data/tilesets
FONTGFXDIR := graphics/fonts
INTERFACEGFXDIR := graphics/interface
BTLANMSPRGFXDIR := graphics/battle_anims/sprites
UNUSEDGFXDIR := graphics/unused
UNKNOWNGFXDIR := graphics/unknown
BATINTGFXDIR := graphics/battle_interface
MASKSGFXDIR := graphics/battle_anims/masks
BATTRANSGFXDIR := graphics/battle_transitions
TYPESGFXDIR := graphics/types
RAYQUAZAGFXDIR := graphics/rayquaza_scene
ROULETTEGFXDIR := graphics/roulette
SLOTMACHINEGFXDIR := graphics/slot_machine
PKNAVGFXDIR := graphics/pokenav
PKNAVOPTIONSGFXDIR := graphics/pokenav/options
WALLPAPERGFXDIR := graphics/pokemon_storage/wallpapers
OBJEVENTGFXDIR := graphics/object_events
MISCGFXDIR := graphics/misc

types := normal fight flying poison ground rock bug ghost steel mystery fire water grass electric psychic ice dragon dark fairy
contest_types := cool beauty cute smart tough



### Tilesets ###

$(TILESETGFXDIR)/secondary/petalburg/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 159

$(TILESETGFXDIR)/secondary/rustboro/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 498

$(TILESETGFXDIR)/secondary/dewford/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 503

$(TILESETGFXDIR)/secondary/slateport/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 504

$(TILESETGFXDIR)/secondary/mauville/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 503

$(TILESETGFXDIR)/secondary/lavaridge/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 450

$(TILESETGFXDIR)/secondary/fortree/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 493

$(TILESETGFXDIR)/secondary/pacifidlog/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 504

$(TILESETGFXDIR)/secondary/sootopolis/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 328

SOOTOPOLISANIMDIR := $(TILESETGFXDIR)/secondary/sootopolis/anim

$(SOOTOPOLISANIMDIR)/stormy_water/0.4bpp: $(SOOTOPOLISANIMDIR)/stormy_water/0_kyogre.4bpp \
                                          $(SOOTOPOLISANIMDIR)/stormy_water/0_groudon.4bpp 
	@cat $^ >$@

$(SOOTOPOLISANIMDIR)/stormy_water/1.4bpp: $(SOOTOPOLISANIMDIR)/stormy_water/1_kyogre.4bpp \
                                          $(SOOTOPOLISANIMDIR)/stormy_water/1_groudon.4bpp 
	@cat $^ >$@

$(SOOTOPOLISANIMDIR)/stormy_water/2.4bpp: $(SOOTOPOLISANIMDIR)/stormy_water/2_kyogre.4bpp \
                                          $(SOOTOPOLISANIMDIR)/stormy_water/2_groudon.4bpp 
	@cat $^ >$@

$(SOOTOPOLISANIMDIR)/stormy_water/3.4bpp: $(SOOTOPOLISANIMDIR)/stormy_water/3_kyogre.4bpp \
                                          $(SOOTOPOLISANIMDIR)/stormy_water/3_groudon.4bpp 
	@cat $^ >$@

$(SOOTOPOLISANIMDIR)/stormy_water/4.4bpp: $(SOOTOPOLISANIMDIR)/stormy_water/4_kyogre.4bpp \
                                          $(SOOTOPOLISANIMDIR)/stormy_water/4_groudon.4bpp 
	@cat $^ >$@

$(SOOTOPOLISANIMDIR)/stormy_water/5.4bpp: $(SOOTOPOLISANIMDIR)/stormy_water/5_kyogre.4bpp \
                                          $(SOOTOPOLISANIMDIR)/stormy_water/5_groudon.4bpp 
	@cat $^ >$@

$(SOOTOPOLISANIMDIR)/stormy_water/6.4bpp: $(SOOTOPOLISANIMDIR)/stormy_water/6_kyogre.4bpp \
                                          $(SOOTOPOLISANIMDIR)/stormy_water/6_groudon.4bpp 
	@cat $^ >$@

$(SOOTOPOLISANIMDIR)/stormy_water/7.4bpp: $(SOOTOPOLISANIMDIR)/stormy_water/7_kyogre.4bpp \
                                          $(SOOTOPOLISANIMDIR)/stormy_water/7_groudon.4bpp 
	@cat $^ >$@

$(TILESETGFXDIR)/secondary/battle_frontier_outside_west/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 508

$(TILESETGFXDIR)/secondary/battle_frontier_outside_east/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 508

$(TILESETGFXDIR)/primary/building/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 502

$(TILESETGFXDIR)/secondary/shop/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 502

$(TILESETGFXDIR)/secondary/pokemon_center/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 478

$(TILESETGFXDIR)/secondary/cave/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 425

$(TILESETGFXDIR)/secondary/pokemon_school/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 278

$(TILESETGFXDIR)/secondary/pokemon_fan_club/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 319

$(TILESETGFXDIR)/secondary/unused_1/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 17

$(TILESETGFXDIR)/secondary/meteor_falls/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 460

$(TILESETGFXDIR)/secondary/oceanic_museum/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 319

$(TILESETGFXDIR)/secondary/cable_club/unknown_tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 120

$(TILESETGFXDIR)/secondary/seashore_house/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 312

$(TILESETGFXDIR)/secondary/pretty_petal_flower_shop/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 345

$(TILESETGFXDIR)/secondary/pokemon_day_care/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 355

$(TILESETGFXDIR)/secondary/secret_base/brown_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/brown_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(TILESETGFXDIR)/secondary/secret_base/tree/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/tree/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(TILESETGFXDIR)/secondary/secret_base/shrub/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/shrub/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(TILESETGFXDIR)/secondary/secret_base/blue_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/blue_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(TILESETGFXDIR)/secondary/secret_base/yellow_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/yellow_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(TILESETGFXDIR)/secondary/secret_base/red_cave/unused_tiles.4bpp: $(TILESETGFXDIR)/secondary/secret_base/red_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(TILESETGFXDIR)/secondary/secret_base/brown_cave/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83

$(TILESETGFXDIR)/secondary/secret_base/tree/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83

$(TILESETGFXDIR)/secondary/secret_base/shrub/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83

$(TILESETGFXDIR)/secondary/secret_base/blue_cave/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83

$(TILESETGFXDIR)/secondary/secret_base/yellow_cave/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83

$(TILESETGFXDIR)/secondary/secret_base/red_cave/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 83

$(TILESETGFXDIR)/secondary/inside_of_truck/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 62

$(TILESETGFXDIR)/secondary/contest/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 430

$(TILESETGFXDIR)/secondary/lilycove_museum/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 431

$(TILESETGFXDIR)/secondary/lab/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 500

$(TILESETGFXDIR)/secondary/underwater/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 500

$(TILESETGFXDIR)/secondary/generic_building/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 509

$(TILESETGFXDIR)/secondary/mauville_game_corner/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 469

$(TILESETGFXDIR)/secondary/unused_2/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 150

$(TILESETGFXDIR)/secondary/rustboro_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 60

$(TILESETGFXDIR)/secondary/dewford_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 61

$(TILESETGFXDIR)/secondary/lavaridge_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 54

$(TILESETGFXDIR)/secondary/petalburg_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 148

$(TILESETGFXDIR)/secondary/fortree_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 61

$(TILESETGFXDIR)/secondary/mossdeep_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 82

$(TILESETGFXDIR)/secondary/sootopolis_gym/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 484

$(TILESETGFXDIR)/secondary/trick_house_puzzle/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 294

$(TILESETGFXDIR)/secondary/inside_ship/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 342

$(TILESETGFXDIR)/secondary/elite_four/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 505

$(TILESETGFXDIR)/secondary/battle_frontier/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 310

$(TILESETGFXDIR)/secondary/battle_factory/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 424

$(TILESETGFXDIR)/secondary/battle_pike/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 382

$(TILESETGFXDIR)/secondary/mirage_tower/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 420

$(TILESETGFXDIR)/secondary/mossdeep_game_corner/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 95

$(TILESETGFXDIR)/secondary/island_harbor/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 503

$(TILESETGFXDIR)/secondary/trainer_hill/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 374

$(TILESETGFXDIR)/secondary/navel_rock/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 420

$(TILESETGFXDIR)/secondary/battle_frontier_ranking_hall/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 136

$(TILESETGFXDIR)/secondary/mystery_events_house/tiles.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 509



### Fonts ###

$(FONTGFXDIR)/font0.latfont: $(FONTGFXDIR)/font0_latin.png
	$(GFX) $< $@

$(FONTGFXDIR)/font1.latfont: $(FONTGFXDIR)/font1_latin.png
	$(GFX) $< $@

$(FONTGFXDIR)/font2.latfont: $(FONTGFXDIR)/font2_latin.png
	$(GFX) $< $@

$(FONTGFXDIR)/font7.latfont: $(FONTGFXDIR)/font7_latin.png
	$(GFX) $< $@

$(FONTGFXDIR)/font8.latfont: $(FONTGFXDIR)/font8_latin.png
	$(GFX) $< $@

$(FONTGFXDIR)/font0.hwjpnfont: $(FONTGFXDIR)/font0_japanese.png
	$(GFX) $< $@

$(FONTGFXDIR)/font1.hwjpnfont: $(FONTGFXDIR)/font1_japanese.png
	$(GFX) $< $@

$(FONTGFXDIR)/font9.hwjpnfont: $(FONTGFXDIR)/font9_japanese.png
	$(GFX) $< $@

$(FONTGFXDIR)/font2.fwjpnfont: $(FONTGFXDIR)/font2_japanese.png
	$(GFX) $< $@

$(FONTGFXDIR)/font6.fwjpnfont: $(FONTGFXDIR)/font6_braille.png
	$(GFX) $< $@

$(FONTGFXDIR)/unused_frlg_male.fwjpnfont: $(FONTGFXDIR)/unused_japanese_frlg_male_font.png
	$(GFX) $< $@

$(FONTGFXDIR)/unused_frlg_female.fwjpnfont: $(FONTGFXDIR)/unused_japanese_frlg_female_font.png
	$(GFX) $< $@

$(FONTGFXDIR)/down_arrow.4bpp: %.4bpp: %.png
	$(GFX) $< $@

$(FONTGFXDIR)/down_arrow_rs.4bpp: %.4bpp: %.png
	$(GFX) $< $@

$(FONTGFXDIR)/unused_frlg_blanked_down_arrow.4bpp: %.4bpp: %.png
	$(GFX) $< $@

$(FONTGFXDIR)/unused_frlg_down_arrow.4bpp: %.4bpp: %.png
	$(GFX) $< $@

$(FONTGFXDIR)/keypad_icons.4bpp: %.4bpp: %.png
	$(GFX) $< $@



### Miscellaneous ###
graphics/title_screen/pokemon_logo.gbapal: %.gbapal: %.pal
	$(GFX) $< $@ -num_colors 224

graphics/pokemon_jump/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 63

graphics/pokenav/region_map.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -num_tiles 233

$(MISCGFXDIR)/japanese_hof.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 29

$(BATINTGFXDIR)/textbox.gbapal: $(BATINTGFXDIR)/textbox_0.gbapal \
								$(BATINTGFXDIR)/textbox_1.gbapal
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/ice_cube.4bpp: $(BTLANMSPRGFXDIR)/ice_cube_0.4bpp \
						 	 $(BTLANMSPRGFXDIR)/ice_cube_1.4bpp \
						 	 $(BTLANMSPRGFXDIR)/ice_cube_2.4bpp \
						 	 $(BTLANMSPRGFXDIR)/ice_cube_3.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi_palpak1.gbapal: $(UNUSEDGFXDIR)/old_pal1.gbapal \
									$(UNUSEDGFXDIR)/old_pal2.gbapal \
									$(UNUSEDGFXDIR)/old_pal3.gbapal
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi_palpak3.gbapal: $(UNUSEDGFXDIR)/old_pal5.gbapal \
									$(UNUSEDGFXDIR)/old_pal6.gbapal \
									$(UNUSEDGFXDIR)/old_pal7.gbapal
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi1.4bpp: $(UNUSEDGFXDIR)/old_bulbasaur.4bpp \
						   $(UNUSEDGFXDIR)/old_charizard.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/obi2.4bpp: $(UNUSEDGFXDIR)/old_bulbasaur2.4bpp \
						   $(UNUSEDGFXDIR)/old_battle_interface_1.4bpp \
						   $(UNUSEDGFXDIR)/old_battle_interface_2.4bpp \
						   $(UNUSEDGFXDIR)/old_battle_interface_3.4bpp
	@cat $^ >$@

$(INTERFACEGFXDIR)/hp_numbers.4bpp: $(INTERFACEGFXDIR)/hpbar_anim.4bpp \
									$(INTERFACEGFXDIR)/numbers1.4bpp \
									$(INTERFACEGFXDIR)/numbers2.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/redyellowgreen_frame.bin: $(UNUSEDGFXDIR)/red_frame.bin \
                                          $(UNUSEDGFXDIR)/yellow_frame.bin \
                                          $(UNUSEDGFXDIR)/green_frame.bin \
                                          $(UNUSEDGFXDIR)/blank_frame.bin
	@cat $^ >$@

$(UNUSEDGFXDIR)/color_frames.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 353

$(BATINTGFXDIR)/unused_window2bar.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 5

$(UNUSEDGFXDIR)/old_contest.4bpp: $(UNUSEDGFXDIR)/old_contest_frame_1.4bpp \
								  $(UNUSEDGFXDIR)/old_contest_floor.4bpp \
								  $(UNUSEDGFXDIR)/old_contest_frame_2.4bpp \
								  $(UNUSEDGFXDIR)/old_contest_symbols.4bpp \
								  $(UNUSEDGFXDIR)/old_contest_meter.4bpp \
								  $(UNUSEDGFXDIR)/old_contest_classes.4bpp \
								  $(UNUSEDGFXDIR)/old_contest_numbers.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/old_contest_2.4bpp: $(UNUSEDGFXDIR)/old_contest_2_1.4bpp \
									$(UNUSEDGFXDIR)/old_contest_2_2.4bpp
	@cat $^ >$@

$(UNKNOWNGFXDIR)/unknown_C19470.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 36

$(BTLANMSPRGFXDIR)/ice_crystals.4bpp: $(BTLANMSPRGFXDIR)/ice_crystals_0.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_crystals_1.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_crystals_2.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_crystals_3.4bpp \
						  $(BTLANMSPRGFXDIR)/ice_crystals_4.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/mud_sand.4bpp: $(BTLANMSPRGFXDIR)/mud_sand_0.4bpp \
						  $(BTLANMSPRGFXDIR)/mud_sand_1.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/flower.4bpp: $(BTLANMSPRGFXDIR)/flower_0.4bpp \
						  $(BTLANMSPRGFXDIR)/flower_1.4bpp
	@cat $^ >$@

$(BTLANMSPRGFXDIR)/spark.4bpp: $(BTLANMSPRGFXDIR)/spark_0.4bpp \
						  $(BTLANMSPRGFXDIR)/spark_1.4bpp
	@cat $^ >$@

$(MASKSGFXDIR)/unused_level_up.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 14

$(BATTRANSGFXDIR)/vs_frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 16

$(INTERFACEGFXDIR)/party_menu_bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 62

$(TYPESGFXDIR)/move_types.4bpp: $(types:%=$(TYPESGFXDIR)/%.4bpp) $(contest_types:%=$(TYPESGFXDIR)/contest_%.4bpp)
	@cat $^ >$@

$(TYPESGFXDIR)/move_types.gbapal: $(TYPESGFXDIR)/move_types_1.gbapal \
							   $(TYPESGFXDIR)/move_types_2.gbapal \
							   $(TYPESGFXDIR)/move_types_3.gbapal
	@cat $^ >$@

$(INTERFACEGFXDIR)/bag_screen.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53

$(RAYQUAZAGFXDIR)/scene_2/rayquaza.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -num_tiles 227

$(RAYQUAZAGFXDIR)/scene_2/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 313

$(RAYQUAZAGFXDIR)/scene_3/rayquaza.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 124

$(RAYQUAZAGFXDIR)/scene_3/rayquaza_tail_fix.4bpp: $(RAYQUAZAGFXDIR)/scene_3/rayquaza_tail.4bpp
	cp $< $@
	head -c 12 /dev/zero >> $@

$(RAYQUAZAGFXDIR)/scene_4/streaks.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 19

$(RAYQUAZAGFXDIR)/scene_4/rayquaza.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 155

graphics/picture_frame/lobby.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 86

$(ROULETTEGFXDIR)/roulette_tilt.4bpp: $(ROULETTEGFXDIR)/shroomish.4bpp \
									  $(ROULETTEGFXDIR)/tailow.4bpp
	@cat $^ >$@

$(ROULETTEGFXDIR)/wheel_icons.4bpp: $(ROULETTEGFXDIR)/wynaut.4bpp \
									$(ROULETTEGFXDIR)/azurill.4bpp \
									$(ROULETTEGFXDIR)/skitty.4bpp \
									$(ROULETTEGFXDIR)/makuhita.4bpp
	@cat $^ >$@

$(BATTRANSGFXDIR)/regis.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53

$(BATTRANSGFXDIR)/rayquaza.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 938

$(BATTRANSGFXDIR)/frontier_square_1.4bpp: $(BATTRANSGFXDIR)/frontier_squares_blanktiles.4bpp \
										 $(BATTRANSGFXDIR)/frontier_squares_1.4bpp
	@cat $^ >$@

$(BATTRANSGFXDIR)/frontier_square_2.4bpp: $(BATTRANSGFXDIR)/frontier_squares_blanktiles.4bpp \
										 $(BATTRANSGFXDIR)/frontier_squares_2.4bpp
	@cat $^ >$@

$(BATTRANSGFXDIR)/frontier_square_3.4bpp: $(BATTRANSGFXDIR)/frontier_squares_blanktiles.4bpp \
										 $(BATTRANSGFXDIR)/frontier_squares_3.4bpp
	@cat $^ >$@

$(BATTRANSGFXDIR)/frontier_square_4.4bpp: $(BATTRANSGFXDIR)/frontier_squares_blanktiles.4bpp \
										 $(BATTRANSGFXDIR)/frontier_squares_4.4bpp
	@cat $^ >$@

$(SLOTMACHINEGFXDIR)/reel_time_gfx.4bpp: $(SLOTMACHINEGFXDIR)/reel_time_pikachu.4bpp \
										 $(SLOTMACHINEGFXDIR)/reel_time_machine.4bpp
	@cat $^ >$@

$(UNUSEDGFXDIR)/intro_birch_beauty.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 822



### Pokémon Storage System ###

$(WALLPAPERGFXDIR)/forest/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 55

$(WALLPAPERGFXDIR)/forest/tiles.4bpp: $(WALLPAPERGFXDIR)/forest/frame.4bpp $(WALLPAPERGFXDIR)/forest/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/city/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 52

$(WALLPAPERGFXDIR)/city/tiles.4bpp: $(WALLPAPERGFXDIR)/city/frame.4bpp $(WALLPAPERGFXDIR)/city/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/desert/tiles.4bpp: $(WALLPAPERGFXDIR)/desert/frame.4bpp $(WALLPAPERGFXDIR)/desert/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/savanna/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 45

$(WALLPAPERGFXDIR)/savanna/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 23

$(WALLPAPERGFXDIR)/savanna/tiles.4bpp: $(WALLPAPERGFXDIR)/savanna/frame.4bpp $(WALLPAPERGFXDIR)/savanna/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/crag/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 49

$(WALLPAPERGFXDIR)/crag/tiles.4bpp: $(WALLPAPERGFXDIR)/crag/frame.4bpp $(WALLPAPERGFXDIR)/crag/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/volcano/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 56

$(WALLPAPERGFXDIR)/volcano/tiles.4bpp: $(WALLPAPERGFXDIR)/volcano/frame.4bpp $(WALLPAPERGFXDIR)/volcano/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/snow/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 57

$(WALLPAPERGFXDIR)/snow/tiles.4bpp: $(WALLPAPERGFXDIR)/snow/frame.4bpp $(WALLPAPERGFXDIR)/snow/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/cave/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 55

$(WALLPAPERGFXDIR)/cave/tiles.4bpp: $(WALLPAPERGFXDIR)/cave/frame.4bpp $(WALLPAPERGFXDIR)/cave/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/beach/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 46

$(WALLPAPERGFXDIR)/beach/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 23

$(WALLPAPERGFXDIR)/beach/tiles.4bpp: $(WALLPAPERGFXDIR)/beach/frame.4bpp $(WALLPAPERGFXDIR)/beach/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/seafloor/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 54

$(WALLPAPERGFXDIR)/seafloor/tiles.4bpp: $(WALLPAPERGFXDIR)/seafloor/frame.4bpp $(WALLPAPERGFXDIR)/seafloor/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/river/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 51

$(WALLPAPERGFXDIR)/river/bg.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 11

$(WALLPAPERGFXDIR)/river/tiles.4bpp: $(WALLPAPERGFXDIR)/river/frame.4bpp $(WALLPAPERGFXDIR)/river/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/sky/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 45

$(WALLPAPERGFXDIR)/sky/tiles.4bpp: $(WALLPAPERGFXDIR)/sky/frame.4bpp $(WALLPAPERGFXDIR)/sky/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/polkadot/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 54

$(WALLPAPERGFXDIR)/polkadot/tiles.4bpp: $(WALLPAPERGFXDIR)/polkadot/frame.4bpp $(WALLPAPERGFXDIR)/polkadot/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/pokecenter/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 35

$(WALLPAPERGFXDIR)/pokecenter/tiles.4bpp: $(WALLPAPERGFXDIR)/pokecenter/frame.4bpp $(WALLPAPERGFXDIR)/pokecenter/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/machine/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 33

$(WALLPAPERGFXDIR)/machine/tiles.4bpp: $(WALLPAPERGFXDIR)/machine/frame.4bpp $(WALLPAPERGFXDIR)/machine/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/plain/frame.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 18

$(WALLPAPERGFXDIR)/plain/tiles.4bpp: $(WALLPAPERGFXDIR)/plain/frame.4bpp $(WALLPAPERGFXDIR)/plain/bg.4bpp
	@cat $^ >$@

$(WALLPAPERGFXDIR)/friends_frame1.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 57

$(WALLPAPERGFXDIR)/friends_frame2.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 57

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

$(OBJEVENTGFXDIR)/pics/effects/unknown_4F6D38/0.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 11

$(INTERFACEGFXDIR)/selector_outline.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 8
	
$(BATTRANSGFXDIR)/frontier_logo_center.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 43



### Pokenav ###

$(PKNAVOPTIONSGFXDIR)/options.4bpp: $(PKNAVOPTIONSGFXDIR)/hoenn_map.4bpp \
								$(PKNAVOPTIONSGFXDIR)/condition.4bpp \
								$(PKNAVOPTIONSGFXDIR)/match_call.4bpp \
								$(PKNAVOPTIONSGFXDIR)/ribbons.4bpp \
								$(PKNAVOPTIONSGFXDIR)/switch_off.4bpp \
								$(PKNAVOPTIONSGFXDIR)/party.4bpp \
								$(PKNAVOPTIONSGFXDIR)/search.4bpp \
								$(PKNAVOPTIONSGFXDIR)/cool.4bpp \
								$(PKNAVOPTIONSGFXDIR)/beauty.4bpp \
								$(PKNAVOPTIONSGFXDIR)/cute.4bpp \
								$(PKNAVOPTIONSGFXDIR)/smart.4bpp \
								$(PKNAVOPTIONSGFXDIR)/tough.4bpp \
								$(PKNAVOPTIONSGFXDIR)/cancel.4bpp
	@cat $^ >$@

$(PKNAVGFXDIR)/header.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53

$(PKNAVGFXDIR)/device_outline.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 53
	
$(PKNAVGFXDIR)/ui_matchcall.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -num_tiles 13

$(INTERFACEGFXDIR)/region_map.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -num_tiles 232

$(INTERFACEGFXDIR)/region_map_affine.8bpp: %.8bpp: %.png
	$(GFX) $< $@ -num_tiles 233

$(MISCGFXDIR)/birch_help.4bpp: $(MISCGFXDIR)/birch_bag.4bpp $(MISCGFXDIR)/birch_grass.4bpp
	@cat $^ >$@
