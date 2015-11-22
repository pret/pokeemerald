monstillfrontdir := data/graphics/pokemon/still_front_pics
monbackdir := data/graphics/pokemon/back_pics
monfrontdir := data/graphics/pokemon/front_pics
monpaldir := data/graphics/pokemon/palettes

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

tilesetdir := data/graphics/tilesets

$(tilesetdir)/secondary/petalburg/tiles.4bpp: $(tilesetdir)/secondary/petalburg/tiles.png
	$(4bpp) $< -num_tiles 159

$(tilesetdir)/secondary/rustboro/tiles.4bpp: $(tilesetdir)/secondary/rustboro/tiles.png
	$(4bpp) $< -num_tiles 498

$(tilesetdir)/secondary/dewford/tiles.4bpp: $(tilesetdir)/secondary/dewford/tiles.png
	$(4bpp) $< -num_tiles 503

$(tilesetdir)/secondary/slateport/tiles.4bpp: $(tilesetdir)/secondary/slateport/tiles.png
	$(4bpp) $< -num_tiles 504

$(tilesetdir)/secondary/mauville/tiles.4bpp: $(tilesetdir)/secondary/mauville/tiles.png
	$(4bpp) $< -num_tiles 503

$(tilesetdir)/secondary/lavaridge/tiles.4bpp: $(tilesetdir)/secondary/lavaridge/tiles.png
	$(4bpp) $< -num_tiles 450

$(tilesetdir)/secondary/fortree/tiles.4bpp: $(tilesetdir)/secondary/fortree/tiles.png
	$(4bpp) $< -num_tiles 493

$(tilesetdir)/secondary/pacifidlog/tiles.4bpp: $(tilesetdir)/secondary/pacifidlog/tiles.png
	$(4bpp) $< -num_tiles 504

$(tilesetdir)/secondary/sootopolis/tiles.4bpp: $(tilesetdir)/secondary/sootopolis/tiles.png
	$(4bpp) $< -num_tiles 328

$(tilesetdir)/secondary/battle_frontier_outside_west/tiles.4bpp: $(tilesetdir)/secondary/battle_frontier_outside_west/tiles.png
	$(4bpp) $< -num_tiles 508

$(tilesetdir)/secondary/battle_frontier_outside_east/tiles.4bpp: $(tilesetdir)/secondary/battle_frontier_outside_east/tiles.png
	$(4bpp) $< -num_tiles 508

$(tilesetdir)/primary/inside_building/tiles.4bpp: $(tilesetdir)/primary/inside_building/tiles.png
	$(4bpp) $< -num_tiles 502

$(tilesetdir)/secondary/shop/tiles.4bpp: $(tilesetdir)/secondary/shop/tiles.png
	$(4bpp) $< -num_tiles 502

$(tilesetdir)/secondary/pokemon_center/tiles.4bpp: $(tilesetdir)/secondary/pokemon_center/tiles.png
	$(4bpp) $< -num_tiles 478

$(tilesetdir)/secondary/cave/tiles.4bpp: $(tilesetdir)/secondary/cave/tiles.png
	$(4bpp) $< -num_tiles 425

$(tilesetdir)/secondary/pokemon_school/tiles.4bpp: $(tilesetdir)/secondary/pokemon_school/tiles.png
	$(4bpp) $< -num_tiles 278

$(tilesetdir)/secondary/pokemon_fan_club/tiles.4bpp: $(tilesetdir)/secondary/pokemon_fan_club/tiles.png
	$(4bpp) $< -num_tiles 319

$(tilesetdir)/secondary/unused_1/tiles.4bpp: $(tilesetdir)/secondary/unused_1/tiles.png
	$(4bpp) $< -num_tiles 17

$(tilesetdir)/secondary/meteor_falls/tiles.4bpp: $(tilesetdir)/secondary/meteor_falls/tiles.png
	$(4bpp) $< -num_tiles 460

$(tilesetdir)/secondary/oceanic_museum/tiles.4bpp: $(tilesetdir)/secondary/oceanic_museum/tiles.png
	$(4bpp) $< -num_tiles 319

$(tilesetdir)/secondary/cable_club/unknown_tiles.4bpp: $(tilesetdir)/secondary/cable_club/unknown_tiles.png
	$(4bpp) $< -num_tiles 120

$(tilesetdir)/secondary/seashore_house/tiles.4bpp: $(tilesetdir)/secondary/seashore_house/tiles.png
	$(4bpp) $< -num_tiles 312

$(tilesetdir)/secondary/pretty_petal_flower_shop/tiles.4bpp: $(tilesetdir)/secondary/pretty_petal_flower_shop/tiles.png
	$(4bpp) $< -num_tiles 345

$(tilesetdir)/secondary/pokemon_day_care/tiles.4bpp: $(tilesetdir)/secondary/pokemon_day_care/tiles.png
	$(4bpp) $< -num_tiles 355

$(tilesetdir)/secondary/secret_base/brown_cave/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/brown_cave/tiles.png
	$(4bpp) $< -output $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/tree/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/tree/tiles.png
	$(4bpp) $< -output $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/shrub/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/shrub/tiles.png
	$(4bpp) $< -output $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/blue_cave/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/blue_cave/tiles.png
	$(4bpp) $< -output $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/yellow_cave/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/yellow_cave/tiles.png
	$(4bpp) $< -output $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/red_cave/unused_tiles.4bpp: $(tilesetdir)/secondary/secret_base/red_cave/tiles.png
	$(4bpp) $< -output $@ -num_tiles 82

$(tilesetdir)/secondary/secret_base/brown_cave/tiles.4bpp: $(tilesetdir)/secondary/secret_base/brown_cave/tiles.png
	$(4bpp) $< -num_tiles 83

$(tilesetdir)/secondary/secret_base/tree/tiles.4bpp: $(tilesetdir)/secondary/secret_base/tree/tiles.png
	$(4bpp) $< -num_tiles 83

$(tilesetdir)/secondary/secret_base/shrub/tiles.4bpp: $(tilesetdir)/secondary/secret_base/shrub/tiles.png
	$(4bpp) $< -num_tiles 83

$(tilesetdir)/secondary/secret_base/blue_cave/tiles.4bpp: $(tilesetdir)/secondary/secret_base/blue_cave/tiles.png
	$(4bpp) $< -num_tiles 83

$(tilesetdir)/secondary/secret_base/yellow_cave/tiles.4bpp: $(tilesetdir)/secondary/secret_base/yellow_cave/tiles.png
	$(4bpp) $< -num_tiles 83

$(tilesetdir)/secondary/secret_base/red_cave/tiles.4bpp: $(tilesetdir)/secondary/secret_base/red_cave/tiles.png
	$(4bpp) $< -num_tiles 83

$(tilesetdir)/secondary/inside_of_truck/tiles.4bpp: $(tilesetdir)/secondary/inside_of_truck/tiles.png
	$(4bpp) $< -num_tiles 62

$(tilesetdir)/secondary/contest/tiles.4bpp: $(tilesetdir)/secondary/contest/tiles.png
	$(4bpp) $< -num_tiles 430

$(tilesetdir)/secondary/lilycove_museum/tiles.4bpp: $(tilesetdir)/secondary/lilycove_museum/tiles.png
	$(4bpp) $< -num_tiles 431

$(tilesetdir)/secondary/lab/tiles.4bpp: $(tilesetdir)/secondary/lab/tiles.png
	$(4bpp) $< -num_tiles 500

$(tilesetdir)/secondary/underwater/tiles.4bpp: $(tilesetdir)/secondary/underwater/tiles.png
	$(4bpp) $< -num_tiles 500

$(tilesetdir)/secondary/generic_building/tiles.4bpp: $(tilesetdir)/secondary/generic_building/tiles.png
	$(4bpp) $< -num_tiles 509

$(tilesetdir)/secondary/mauville_game_corner/tiles.4bpp: $(tilesetdir)/secondary/mauville_game_corner/tiles.png
	$(4bpp) $< -num_tiles 469

$(tilesetdir)/secondary/unused_2/tiles.4bpp: $(tilesetdir)/secondary/unused_2/tiles.png
	$(4bpp) $< -num_tiles 150

$(tilesetdir)/secondary/rustboro_gym/tiles.4bpp: $(tilesetdir)/secondary/rustboro_gym/tiles.png
	$(4bpp) $< -num_tiles 60

$(tilesetdir)/secondary/dewford_gym/tiles.4bpp: $(tilesetdir)/secondary/dewford_gym/tiles.png
	$(4bpp) $< -num_tiles 61

$(tilesetdir)/secondary/lavaridge_gym/tiles.4bpp: $(tilesetdir)/secondary/lavaridge_gym/tiles.png
	$(4bpp) $< -num_tiles 54

$(tilesetdir)/secondary/petalburg_gym/tiles.4bpp: $(tilesetdir)/secondary/petalburg_gym/tiles.png
	$(4bpp) $< -num_tiles 148

$(tilesetdir)/secondary/fortree_gym/tiles.4bpp: $(tilesetdir)/secondary/fortree_gym/tiles.png
	$(4bpp) $< -num_tiles 61

$(tilesetdir)/secondary/mossdeep_gym/tiles.4bpp: $(tilesetdir)/secondary/mossdeep_gym/tiles.png
	$(4bpp) $< -num_tiles 82

$(tilesetdir)/secondary/sootopolis_gym/tiles.4bpp: $(tilesetdir)/secondary/sootopolis_gym/tiles.png
	$(4bpp) $< -num_tiles 484

$(tilesetdir)/secondary/trick_house_puzzle/tiles.4bpp: $(tilesetdir)/secondary/trick_house_puzzle/tiles.png
	$(4bpp) $< -num_tiles 294

$(tilesetdir)/secondary/inside_ship/tiles.4bpp: $(tilesetdir)/secondary/inside_ship/tiles.png
	$(4bpp) $< -num_tiles 342

$(tilesetdir)/secondary/elite_four/tiles.4bpp: $(tilesetdir)/secondary/elite_four/tiles.png
	$(4bpp) $< -num_tiles 505

$(tilesetdir)/secondary/battle_frontier/tiles.4bpp: $(tilesetdir)/secondary/battle_frontier/tiles.png
	$(4bpp) $< -num_tiles 310

$(tilesetdir)/secondary/battle_factory/tiles.4bpp: $(tilesetdir)/secondary/battle_factory/tiles.png
	$(4bpp) $< -num_tiles 424

$(tilesetdir)/secondary/battle_pike/tiles.4bpp: $(tilesetdir)/secondary/battle_pike/tiles.png
	$(4bpp) $< -num_tiles 382

$(tilesetdir)/secondary/mirage_tower/tiles.4bpp: $(tilesetdir)/secondary/mirage_tower/tiles.png
	$(4bpp) $< -num_tiles 420

$(tilesetdir)/secondary/mossdeep_game_corner/tiles.4bpp: $(tilesetdir)/secondary/mossdeep_game_corner/tiles.png
	$(4bpp) $< -num_tiles 95

$(tilesetdir)/secondary/island_habor/tiles.4bpp: $(tilesetdir)/secondary/island_habor/tiles.png
	$(4bpp) $< -num_tiles 503

$(tilesetdir)/secondary/trainer_hill/tiles.4bpp: $(tilesetdir)/secondary/trainer_hill/tiles.png
	$(4bpp) $< -num_tiles 374

$(tilesetdir)/secondary/navel_rock/tiles.4bpp: $(tilesetdir)/secondary/navel_rock/tiles.png
	$(4bpp) $< -num_tiles 420

$(tilesetdir)/secondary/battle_frontier_ranking_hall/tiles.4bpp: $(tilesetdir)/secondary/battle_frontier_ranking_hall/tiles.png
	$(4bpp) $< -num_tiles 136

$(tilesetdir)/secondary/mystery_events_house/tiles.4bpp: $(tilesetdir)/secondary/mystery_events_house/tiles.png
	$(4bpp) $< -num_tiles 509
