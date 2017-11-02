monstillfrontdir := graphics/pokemon/front_pics
monbackdir := graphics/pokemon/back_pics
monfrontdir := graphics/pokemon/anim_front_pics
monpaldir := graphics/pokemon/palettes
INTROGFXDIR := graphics/intro
interfacedir := graphics/interface
PKNAVGFXDIR := graphics/pokenav

$(monstillfrontdir)/castform_still_front_pic.4bpp: $(monstillfrontdir)/castform_normal_form_still_front_pic.4bpp \
                                                   $(monstillfrontdir)/castform_sunny_form_still_front_pic.4bpp \
                                                   $(monstillfrontdir)/castform_rainy_form_still_front_pic.4bpp \
                                                   $(monstillfrontdir)/castform_snowy_form_still_front_pic.4bpp
	@cat $(monstillfrontdir)/castform_normal_form_still_front_pic.4bpp $(monstillfrontdir)/castform_sunny_form_still_front_pic.4bpp $(monstillfrontdir)/castform_rainy_form_still_front_pic.4bpp $(monstillfrontdir)/castform_snowy_form_still_front_pic.4bpp >$@

$(monbackdir)/castform_back_pic.4bpp: $(monbackdir)/castform_normal_form_back_pic.4bpp \
                                      $(monbackdir)/castform_sunny_form_back_pic.4bpp \
                                      $(monbackdir)/castform_rainy_form_back_pic.4bpp \
                                      $(monbackdir)/castform_snowy_form_back_pic.4bpp
	@cat $(monbackdir)/castform_normal_form_back_pic.4bpp $(monbackdir)/castform_sunny_form_back_pic.4bpp $(monbackdir)/castform_rainy_form_back_pic.4bpp $(monbackdir)/castform_snowy_form_back_pic.4bpp >$@

$(monfrontdir)/castform_front_pic.4bpp: $(monfrontdir)/castform_normal_form_front_pic.4bpp \
                                        $(monfrontdir)/castform_sunny_form_front_pic.4bpp \
                                        $(monfrontdir)/castform_rainy_form_front_pic.4bpp \
                                        $(monfrontdir)/castform_snowy_form_front_pic.4bpp
	@cat $(monfrontdir)/castform_normal_form_front_pic.4bpp $(monfrontdir)/castform_sunny_form_front_pic.4bpp $(monfrontdir)/castform_rainy_form_front_pic.4bpp $(monfrontdir)/castform_snowy_form_front_pic.4bpp >$@

$(monpaldir)/castform_palette.gbapal: $(monpaldir)/castform_normal_form_palette.gbapal \
                                      $(monpaldir)/castform_sunny_form_palette.gbapal \
                                      $(monpaldir)/castform_rainy_form_palette.gbapal \
                                      $(monpaldir)/castform_snowy_form_palette.gbapal
	@cat $(monpaldir)/castform_normal_form_palette.gbapal $(monpaldir)/castform_sunny_form_palette.gbapal $(monpaldir)/castform_rainy_form_palette.gbapal $(monpaldir)/castform_snowy_form_palette.gbapal >$@

$(monpaldir)/castform_shiny_palette.gbapal: $(monpaldir)/castform_normal_form_shiny_palette.gbapal \
                                            $(monpaldir)/castform_sunny_form_shiny_palette.gbapal \
                                            $(monpaldir)/castform_rainy_form_shiny_palette.gbapal \
                                            $(monpaldir)/castform_snowy_form_shiny_palette.gbapal
	@cat $(monpaldir)/castform_normal_form_shiny_palette.gbapal $(monpaldir)/castform_sunny_form_shiny_palette.gbapal $(monpaldir)/castform_rainy_form_shiny_palette.gbapal $(monpaldir)/castform_snowy_form_shiny_palette.gbapal >$@

tilesetdir := data/tilesets

$(tilesetdir)/secondary/petalburg/tiles.4bpp: $(tilesetdir)/secondary/petalburg/tiles.png
	$(GFX) $< $@ -num_tiles 159

$(tilesetdir)/secondary/rustboro/tiles.4bpp: $(tilesetdir)/secondary/rustboro/tiles.png
	$(GFX) $< $@ -num_tiles 498

$(tilesetdir)/secondary/dewford/tiles.4bpp: $(tilesetdir)/secondary/dewford/tiles.png
	$(GFX) $< $@ -num_tiles 503

$(tilesetdir)/secondary/slateport/tiles.4bpp: $(tilesetdir)/secondary/slateport/tiles.png
	$(GFX) $< $@ -num_tiles 504

$(tilesetdir)/secondary/mauville/tiles.4bpp: $(tilesetdir)/secondary/mauville/tiles.png
	$(GFX) $< $@ -num_tiles 503

$(tilesetdir)/secondary/lavaridge/tiles.4bpp: $(tilesetdir)/secondary/lavaridge/tiles.png
	$(GFX) $< $@ -num_tiles 450

$(tilesetdir)/secondary/fortree/tiles.4bpp: $(tilesetdir)/secondary/fortree/tiles.png
	$(GFX) $< $@ -num_tiles 493

$(tilesetdir)/secondary/pacifidlog/tiles.4bpp: $(tilesetdir)/secondary/pacifidlog/tiles.png
	$(GFX) $< $@ -num_tiles 504

$(tilesetdir)/secondary/sootopolis/tiles.4bpp: $(tilesetdir)/secondary/sootopolis/tiles.png
	$(GFX) $< $@ -num_tiles 328

$(tilesetdir)/secondary/battle_frontier_outside_west/tiles.4bpp: $(tilesetdir)/secondary/battle_frontier_outside_west/tiles.png
	$(GFX) $< $@ -num_tiles 508

$(tilesetdir)/secondary/battle_frontier_outside_east/tiles.4bpp: $(tilesetdir)/secondary/battle_frontier_outside_east/tiles.png
	$(GFX) $< $@ -num_tiles 508

$(tilesetdir)/primary/inside_building/tiles.4bpp: $(tilesetdir)/primary/inside_building/tiles.png
	$(GFX) $< $@ -num_tiles 502

$(tilesetdir)/secondary/shop/tiles.4bpp: $(tilesetdir)/secondary/shop/tiles.png
	$(GFX) $< $@ -num_tiles 502

$(tilesetdir)/secondary/pokemon_center/tiles.4bpp: $(tilesetdir)/secondary/pokemon_center/tiles.png
	$(GFX) $< $@ -num_tiles 478

$(tilesetdir)/secondary/cave/tiles.4bpp: $(tilesetdir)/secondary/cave/tiles.png
	$(GFX) $< $@ -num_tiles 425

$(tilesetdir)/secondary/pokemon_school/tiles.4bpp: $(tilesetdir)/secondary/pokemon_school/tiles.png
	$(GFX) $< $@ -num_tiles 278

$(tilesetdir)/secondary/pokemon_fan_club/tiles.4bpp: $(tilesetdir)/secondary/pokemon_fan_club/tiles.png
	$(GFX) $< $@ -num_tiles 319

$(tilesetdir)/secondary/unused_1/tiles.4bpp: $(tilesetdir)/secondary/unused_1/tiles.png
	$(GFX) $< $@ -num_tiles 17

$(tilesetdir)/secondary/meteor_falls/tiles.4bpp: $(tilesetdir)/secondary/meteor_falls/tiles.png
	$(GFX) $< $@ -num_tiles 460

$(tilesetdir)/secondary/oceanic_museum/tiles.4bpp: $(tilesetdir)/secondary/oceanic_museum/tiles.png
	$(GFX) $< $@ -num_tiles 319

$(tilesetdir)/secondary/cable_club/unknown_tiles.4bpp: $(tilesetdir)/secondary/cable_club/unknown_tiles.png
	$(GFX) $< $@ -num_tiles 120

$(tilesetdir)/secondary/seashore_house/tiles.4bpp: $(tilesetdir)/secondary/seashore_house/tiles.png
	$(GFX) $< $@ -num_tiles 312

$(tilesetdir)/secondary/pretty_petal_flower_shop/tiles.4bpp: $(tilesetdir)/secondary/pretty_petal_flower_shop/tiles.png
	$(GFX) $< $@ -num_tiles 345

$(tilesetdir)/secondary/pokemon_day_care/tiles.4bpp: $(tilesetdir)/secondary/pokemon_day_care/tiles.png
	$(GFX) $< $@ -num_tiles 355

$(tilesetdir)/secondary/secret_base/brown_cave/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/brown_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/tree/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/tree/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/shrub/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/shrub/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/blue_cave/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/blue_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/yellow_cave/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/yellow_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/red_cave/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/red_cave/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/brown_cave/tiles.4bpp: $(tilesetdir)/secondary/secret_base/brown_cave/tiles.png
	$(GFX) $< $@ -num_tiles 83

$(tilesetdir)/secondary/secret_base/tree/tiles.4bpp: $(tilesetdir)/secondary/secret_base/tree/tiles.png
	$(GFX) $< $@ -num_tiles 83

$(tilesetdir)/secondary/secret_base/shrub/tiles.4bpp: $(tilesetdir)/secondary/secret_base/shrub/tiles.png
	$(GFX) $< $@ -num_tiles 83

$(tilesetdir)/secondary/secret_base/blue_cave/tiles.4bpp: $(tilesetdir)/secondary/secret_base/blue_cave/tiles.png
	$(GFX) $< $@ -num_tiles 83

$(tilesetdir)/secondary/secret_base/yellow_cave/tiles.4bpp: $(tilesetdir)/secondary/secret_base/yellow_cave/tiles.png
	$(GFX) $< $@ -num_tiles 83

$(tilesetdir)/secondary/secret_base/red_cave/tiles.4bpp: $(tilesetdir)/secondary/secret_base/red_cave/tiles.png
	$(GFX) $< $@ -num_tiles 83

$(tilesetdir)/secondary/inside_of_truck/tiles.4bpp: $(tilesetdir)/secondary/inside_of_truck/tiles.png
	$(GFX) $< $@ -num_tiles 62

$(tilesetdir)/secondary/contest/tiles.4bpp: $(tilesetdir)/secondary/contest/tiles.png
	$(GFX) $< $@ -num_tiles 430

$(tilesetdir)/secondary/lilycove_museum/tiles.4bpp: $(tilesetdir)/secondary/lilycove_museum/tiles.png
	$(GFX) $< $@ -num_tiles 431

$(tilesetdir)/secondary/lab/tiles.4bpp: $(tilesetdir)/secondary/lab/tiles.png
	$(GFX) $< $@ -num_tiles 500

$(tilesetdir)/secondary/underwater/tiles.4bpp: $(tilesetdir)/secondary/underwater/tiles.png
	$(GFX) $< $@ -num_tiles 500

$(tilesetdir)/secondary/generic_building/tiles.4bpp: $(tilesetdir)/secondary/generic_building/tiles.png
	$(GFX) $< $@ -num_tiles 509

$(tilesetdir)/secondary/mauville_game_corner/tiles.4bpp: $(tilesetdir)/secondary/mauville_game_corner/tiles.png
	$(GFX) $< $@ -num_tiles 469

$(tilesetdir)/secondary/unused_2/tiles.4bpp: $(tilesetdir)/secondary/unused_2/tiles.png
	$(GFX) $< $@ -num_tiles 150

$(tilesetdir)/secondary/rustboro_gym/tiles.4bpp: $(tilesetdir)/secondary/rustboro_gym/tiles.png
	$(GFX) $< $@ -num_tiles 60

$(tilesetdir)/secondary/dewford_gym/tiles.4bpp: $(tilesetdir)/secondary/dewford_gym/tiles.png
	$(GFX) $< $@ -num_tiles 61

$(tilesetdir)/secondary/lavaridge_gym/tiles.4bpp: $(tilesetdir)/secondary/lavaridge_gym/tiles.png
	$(GFX) $< $@ -num_tiles 54

$(tilesetdir)/secondary/petalburg_gym/tiles.4bpp: $(tilesetdir)/secondary/petalburg_gym/tiles.png
	$(GFX) $< $@ -num_tiles 148

$(tilesetdir)/secondary/fortree_gym/tiles.4bpp: $(tilesetdir)/secondary/fortree_gym/tiles.png
	$(GFX) $< $@ -num_tiles 61

$(tilesetdir)/secondary/mossdeep_gym/tiles.4bpp: $(tilesetdir)/secondary/mossdeep_gym/tiles.png
	$(GFX) $< $@ -num_tiles 82

$(tilesetdir)/secondary/sootopolis_gym/tiles.4bpp: $(tilesetdir)/secondary/sootopolis_gym/tiles.png
	$(GFX) $< $@ -num_tiles 484

$(tilesetdir)/secondary/trick_house_puzzle/tiles.4bpp: $(tilesetdir)/secondary/trick_house_puzzle/tiles.png
	$(GFX) $< $@ -num_tiles 294

$(tilesetdir)/secondary/inside_ship/tiles.4bpp: $(tilesetdir)/secondary/inside_ship/tiles.png
	$(GFX) $< $@ -num_tiles 342

$(tilesetdir)/secondary/elite_four/tiles.4bpp: $(tilesetdir)/secondary/elite_four/tiles.png
	$(GFX) $< $@ -num_tiles 505

$(tilesetdir)/secondary/battle_frontier/tiles.4bpp: $(tilesetdir)/secondary/battle_frontier/tiles.png
	$(GFX) $< $@ -num_tiles 310

$(tilesetdir)/secondary/battle_factory/tiles.4bpp: $(tilesetdir)/secondary/battle_factory/tiles.png
	$(GFX) $< $@ -num_tiles 424

$(tilesetdir)/secondary/battle_pike/tiles.4bpp: $(tilesetdir)/secondary/battle_pike/tiles.png
	$(GFX) $< $@ -num_tiles 382

$(tilesetdir)/secondary/mirage_tower/tiles.4bpp: $(tilesetdir)/secondary/mirage_tower/tiles.png
	$(GFX) $< $@ -num_tiles 420

$(tilesetdir)/secondary/mossdeep_game_corner/tiles.4bpp: $(tilesetdir)/secondary/mossdeep_game_corner/tiles.png
	$(GFX) $< $@ -num_tiles 95

$(tilesetdir)/secondary/island_harbor/tiles.4bpp: $(tilesetdir)/secondary/island_harbor/tiles.png
	$(GFX) $< $@ -num_tiles 503

$(tilesetdir)/secondary/trainer_hill/tiles.4bpp: $(tilesetdir)/secondary/trainer_hill/tiles.png
	$(GFX) $< $@ -num_tiles 374

$(tilesetdir)/secondary/navel_rock/tiles.4bpp: $(tilesetdir)/secondary/navel_rock/tiles.png
	$(GFX) $< $@ -num_tiles 420

$(tilesetdir)/secondary/battle_frontier_ranking_hall/tiles.4bpp: $(tilesetdir)/secondary/battle_frontier_ranking_hall/tiles.png
	$(GFX) $< $@ -num_tiles 136

$(tilesetdir)/secondary/mystery_events_house/tiles.4bpp: $(tilesetdir)/secondary/mystery_events_house/tiles.png
	$(GFX) $< $@ -num_tiles 509

fontdir := data/graphics/fonts

$(fontdir)/font0.latfont: $(fontdir)/font0_latin.png
	$(GFX) $< $@

$(fontdir)/font1.latfont: $(fontdir)/font1_latin.png
	$(GFX) $< $@

$(fontdir)/font2.latfont: $(fontdir)/font2_latin.png
	$(GFX) $< $@

$(fontdir)/font7.latfont: $(fontdir)/font7_latin.png
	$(GFX) $< $@

$(fontdir)/font8.latfont: $(fontdir)/font8_latin.png
	$(GFX) $< $@

$(fontdir)/font0.hwjpnfont: $(fontdir)/font0_japanese.png
	$(GFX) $< $@

$(fontdir)/font1.hwjpnfont: $(fontdir)/font1_japanese.png
	$(GFX) $< $@

$(fontdir)/font9.hwjpnfont: $(fontdir)/font9_japanese.png
	$(GFX) $< $@

$(fontdir)/font2.fwjpnfont: $(fontdir)/font2_japanese.png
	$(GFX) $< $@

$(fontdir)/font6.fwjpnfont: $(fontdir)/font6_braille.png
	$(GFX) $< $@

$(fontdir)/unused_frlg_male.fwjpnfont: $(fontdir)/unused_japanese_frlg_male_font.png
	$(GFX) $< $@

$(fontdir)/unused_frlg_female.fwjpnfont: $(fontdir)/unused_japanese_frlg_female_font.png
	$(GFX) $< $@

$(fontdir)/down_arrow.4bpp: $(fontdir)/down_arrow.png
	$(GFX) $< $@

$(fontdir)/down_arrow_rs.4bpp: $(fontdir)/down_arrow_rs.png
	$(GFX) $< $@

$(fontdir)/unused_frlg_blanked_down_arrow.4bpp: $(fontdir)/unused_frlg_blanked_down_arrow.png
	$(GFX) $< $@

$(fontdir)/unused_frlg_down_arrow.4bpp: $(fontdir)/unused_frlg_down_arrow.png
	$(GFX) $< $@

$(fontdir)/keypad_icons.4bpp: $(fontdir)/keypad_icons.png
	$(GFX) $< $@

graphics/title_screen/pokemon_logo.gbapal: graphics/title_screen/pokemon_logo.pal
	$(GFX) $< $@ -num_colors 224

$(INTROGFXDIR)/copyright.4bpp: $(INTROGFXDIR)/copyright.png
	$(GFX) $< $@ -num_tiles 39

$(interfacedir)/pkmnjump_bg.4bpp: $(interfacedir)/pkmnjump_bg.png
	$(GFX) $< $@ -num_tiles 63


$(PKNAVGFXDIR)/region_map.8bpp: $(PKNAVGFXDIR)/region_map.png
	$(GFX) $< $@ -num_tiles 233
