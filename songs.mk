STD_REVERB = 50

$(MID_BUILDDIR)/%.o: $(MID_SUBDIR)/%.s
	$(AS) $(ASFLAGS) -I sound -o $@ $<

$(MID_SUBDIR)/mus_aqua_magma_hideout.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G076 -V084

$(MID_SUBDIR)/mus_encounter_aqua.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G065 -V086

$(MID_SUBDIR)/mus_route111.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G055 -V076

$(MID_SUBDIR)/mus_encounter_suspicious.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G069 -V078

$(MID_SUBDIR)/mus_b_arena.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G104 -V090

$(MID_SUBDIR)/mus_b_dome.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G111 -V090

$(MID_SUBDIR)/mus_b_dome_lobby.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G111 -V056

$(MID_SUBDIR)/mus_b_factory.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G113 -V100

$(MID_SUBDIR)/mus_b_frontier.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G103 -V094

$(MID_SUBDIR)/mus_b_palace.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G108 -V105

$(MID_SUBDIR)/mus_b_tower_rs.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G035 -V080

$(MID_SUBDIR)/mus_b_pike.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G112 -V092

$(MID_SUBDIR)/mus_vs_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G119 -V080 -P1

$(MID_SUBDIR)/mus_vs_wild.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G117 -V080 -P1

$(MID_SUBDIR)/mus_vs_aqua_magma_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G126 -V080 -P1

$(MID_SUBDIR)/mus_vs_aqua_magma.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G118 -V080 -P1

$(MID_SUBDIR)/mus_vs_gym_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G120 -V080 -P1

$(MID_SUBDIR)/mus_vs_champion.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G121 -V080 -P1

$(MID_SUBDIR)/mus_vs_kyogre_groudon.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G123 -V080 -P1

$(MID_SUBDIR)/mus_vs_rival.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G124 -V080 -P1

$(MID_SUBDIR)/mus_vs_regi.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G122 -V080 -P1

$(MID_SUBDIR)/mus_vs_elite_four.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G125 -V080 -P1

$(MID_SUBDIR)/mus_roulette.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G038 -V080

$(MID_SUBDIR)/mus_lilycove_museum.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G020 -V080

$(MID_SUBDIR)/mus_encounter_brendan.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G067 -V078

$(MID_SUBDIR)/mus_encounter_male.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G028 -V080

$(MID_SUBDIR)/mus_victory_road.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G075 -V076

$(MID_SUBDIR)/mus_game_corner.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G072 -V072

$(MID_SUBDIR)/mus_contest_winner.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G085 -V100

$(MID_SUBDIR)/mus_contest_results.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G092 -V080

$(MID_SUBDIR)/mus_contest_lobby.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G098 -V060

$(MID_SUBDIR)/mus_contest.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G086 -V088

$(MID_SUBDIR)/mus_cycling.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G049 -V083

$(MID_SUBDIR)/mus_encounter_champion.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G100 -V076

$(MID_SUBDIR)/mus_petalburg_woods.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G018 -V080

$(MID_SUBDIR)/mus_abandoned_ship.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G030 -V080

$(MID_SUBDIR)/mus_cave_of_origin.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G037 -V080

$(MID_SUBDIR)/mus_underwater.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G057 -V094

$(MID_SUBDIR)/mus_intro.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G060 -V090

$(MID_SUBDIR)/mus_hall_of_fame.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G082 -V078

$(MID_SUBDIR)/mus_route110.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G010 -V080

$(MID_SUBDIR)/mus_route120.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G014 -V080

$(MID_SUBDIR)/mus_route122.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G021 -V080

$(MID_SUBDIR)/mus_route101.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G011 -V080

$(MID_SUBDIR)/mus_dummy.s: %.s: %.mid
	$(MID) $< $@ -E -R40

$(MID_SUBDIR)/mus_hall_of_fame_room.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G093 -V080

$(MID_SUBDIR)/mus_end.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G102 -V036

$(MID_SUBDIR)/mus_help.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G056 -V078

$(MID_SUBDIR)/mus_level_up.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_obtain_item.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_evolved.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_gsc_route38.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_SUBDIR)/mus_slateport.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G079 -V070

$(MID_SUBDIR)/mus_poke_mart.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G050 -V085

$(MID_SUBDIR)/mus_oceanic_museum.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G023 -V080

$(MID_SUBDIR)/mus_gym.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G013 -V080

$(MID_SUBDIR)/mus_encounter_may.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G061 -V078

$(MID_SUBDIR)/mus_encounter_female.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G053 -V072

$(MID_SUBDIR)/mus_verdanturf.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G044 -V090

$(MID_SUBDIR)/mus_rustboro.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G045 -V085

$(MID_SUBDIR)/mus_route119.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G048 -V096

$(MID_SUBDIR)/mus_encounter_intense.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G062 -V078

$(MID_SUBDIR)/mus_weather_groudon.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G090 -V050

$(MID_SUBDIR)/mus_dewford.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G073 -V078

$(MID_SUBDIR)/mus_encounter_twins.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G095 -V075

$(MID_SUBDIR)/mus_encounter_interviewer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G099 -V062

$(MID_SUBDIR)/mus_victory_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G058 -V091

$(MID_SUBDIR)/mus_victory_wild.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G025 -V080

$(MID_SUBDIR)/mus_victory_gym_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G024 -V080

$(MID_SUBDIR)/mus_victory_aqua_magma.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G070 -V088

$(MID_SUBDIR)/mus_victory_league.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G029 -V080

$(MID_SUBDIR)/mus_caught.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G025 -V080

$(MID_SUBDIR)/mus_encounter_cool.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G063 -V086

$(MID_SUBDIR)/mus_trick_house.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G094 -V070

$(MID_SUBDIR)/mus_route113.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G064 -V084

$(MID_SUBDIR)/mus_sailing.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G077 -V086

$(MID_SUBDIR)/mus_mt_pyre.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G078 -V088

$(MID_SUBDIR)/mus_sealed_chamber.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G084 -V100

$(MID_SUBDIR)/mus_petalburg.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G015 -V080

$(MID_SUBDIR)/mus_fortree.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G032 -V080

$(MID_SUBDIR)/mus_oldale.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G019 -V080

$(MID_SUBDIR)/mus_mt_pyre_exterior.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G080 -V080

$(MID_SUBDIR)/mus_heal.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_slots_jackpot.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_slots_win.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_obtain_badge.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_obtain_berry.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_obtain_b_points.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G103 -V090 -P5

$(MID_SUBDIR)/mus_rg_photo.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G180 -V100 -P5

$(MID_SUBDIR)/mus_evolution_intro.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G026 -V080

$(MID_SUBDIR)/mus_obtain_symbol.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G103 -V100 -P5

$(MID_SUBDIR)/mus_awaken_legend.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_register_match_call.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G105 -V090 -P5

$(MID_SUBDIR)/mus_move_deleted.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_obtain_tmhm.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_too_bad.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_SUBDIR)/mus_encounter_magma.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G087 -V072

$(MID_SUBDIR)/mus_lilycove.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G054 -V085

$(MID_SUBDIR)/mus_littleroot.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G051 -V100

$(MID_SUBDIR)/mus_surf.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G017 -V080

$(MID_SUBDIR)/mus_route104.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G047 -V097

$(MID_SUBDIR)/mus_gsc_pewter.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_SUBDIR)/mus_birch_lab.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G033 -V080

$(MID_SUBDIR)/mus_abnormal_weather.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G089 -V080

$(MID_SUBDIR)/mus_school.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G081 -V100

$(MID_SUBDIR)/mus_c_comm_center.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_SUBDIR)/mus_poke_center.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G046 -V092

$(MID_SUBDIR)/mus_b_pyramid.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G106 -V079

$(MID_SUBDIR)/mus_b_pyramid_top.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G107 -V077

$(MID_SUBDIR)/mus_ever_grande.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G068 -V086

$(MID_SUBDIR)/mus_rayquaza_appears.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G109 -V090

$(MID_SUBDIR)/mus_rg_rocket_hideout.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G133 -V090

$(MID_SUBDIR)/mus_rg_follow_me.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G131 -V068

$(MID_SUBDIR)/mus_rg_victory_road.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G154 -V090

$(MID_SUBDIR)/mus_rg_cycling.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G141 -V090

$(MID_SUBDIR)/mus_rg_intro_fight.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G136 -V090

$(MID_SUBDIR)/mus_rg_hall_of_fame.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G145 -V079

$(MID_SUBDIR)/mus_rg_encounter_deoxys.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G184 -V079

$(MID_SUBDIR)/mus_rg_credits.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G149 -V090

$(MID_SUBDIR)/mus_rg_encounter_gym_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G144 -V090

$(MID_SUBDIR)/mus_rg_dex_rating.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G175 -V070 -P5

$(MID_SUBDIR)/mus_rg_obtain_key_item.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G178 -V077 -P5

$(MID_SUBDIR)/mus_rg_caught_intro.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G179 -V094 -P5

$(MID_SUBDIR)/mus_rg_caught.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G170 -V100

$(MID_SUBDIR)/mus_rg_cinnabar.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G138 -V090

$(MID_SUBDIR)/mus_rg_gym.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G134 -V090

$(MID_SUBDIR)/mus_rg_fuchsia.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G167 -V090

$(MID_SUBDIR)/mus_rg_poke_jump.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G132 -V090

$(MID_SUBDIR)/mus_rg_heal.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G140 -V090

$(MID_SUBDIR)/mus_rg_oak_lab.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G160 -V075

$(MID_SUBDIR)/mus_rg_berry_pick.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G132 -V090

$(MID_SUBDIR)/mus_rg_vermillion.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G172 -V090

$(MID_SUBDIR)/mus_rg_route1.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G150 -V079

$(MID_SUBDIR)/mus_rg_route3.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G152 -V083

$(MID_SUBDIR)/mus_rg_route11.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G153 -V090

$(MID_SUBDIR)/mus_rg_pallet.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G159 -V100

$(MID_SUBDIR)/mus_rg_surf.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G164 -V071

$(MID_SUBDIR)/mus_rg_sevii_45.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G188 -V084

$(MID_SUBDIR)/mus_rg_sevii_67.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G189 -V084

$(MID_SUBDIR)/mus_rg_sevii_route.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G187 -V080

$(MID_SUBDIR)/mus_rg_net_center.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G162 -V096

$(MID_SUBDIR)/mus_rg_pewter.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G173 -V084

$(MID_SUBDIR)/mus_rg_oak.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G161 -V086

$(MID_SUBDIR)/mus_rg_mystery_gift.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G183 -V100

$(MID_SUBDIR)/mus_rg_route24.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G151 -V086

$(MID_SUBDIR)/mus_rg_mt_moon.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G147 -V090

$(MID_SUBDIR)/mus_rg_poke_tower.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G165 -V090

$(MID_SUBDIR)/mus_rg_poke_center.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G162 -V096

$(MID_SUBDIR)/mus_rg_poke_flute.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G165 -V048 -P5

$(MID_SUBDIR)/mus_rg_poke_mansion.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G148 -V090

$(MID_SUBDIR)/mus_rg_jigglypuff.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G135 -V068 -P5

$(MID_SUBDIR)/mus_rg_encounter_rival.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G174 -V079

$(MID_SUBDIR)/mus_rg_rival_exit.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G174 -V079

$(MID_SUBDIR)/mus_rg_encounter_rocket.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G142 -V096

$(MID_SUBDIR)/mus_rg_ss_anne.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G163 -V090

$(MID_SUBDIR)/mus_rg_new_game_exit.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G182 -V088

$(MID_SUBDIR)/mus_rg_new_game_intro.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G182 -V088

$(MID_SUBDIR)/mus_rg_lavender.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G139 -V090

$(MID_SUBDIR)/mus_rg_silph.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G166 -V076

$(MID_SUBDIR)/mus_rg_encounter_girl.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G143 -V051

$(MID_SUBDIR)/mus_rg_encounter_boy.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G144 -V090

$(MID_SUBDIR)/mus_rg_game_corner.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G132 -V090

$(MID_SUBDIR)/mus_rg_slow_pallet.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G159 -V092

$(MID_SUBDIR)/mus_rg_new_game_instruct.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G182 -V085

$(MID_SUBDIR)/mus_rg_viridian_forest.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G146 -V090

$(MID_SUBDIR)/mus_rg_trainer_tower.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G134 -V090

$(MID_SUBDIR)/mus_rg_celadon.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G168 -V070

$(MID_SUBDIR)/mus_rg_title.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G137 -V090

$(MID_SUBDIR)/mus_rg_game_freak.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G181 -V075

$(MID_SUBDIR)/mus_rg_teachy_tv_menu.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G186 -V059

$(MID_SUBDIR)/mus_rg_union_room.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G132 -V090

$(MID_SUBDIR)/mus_rg_vs_legend.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G157 -V090

$(MID_SUBDIR)/mus_rg_vs_deoxys.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G185 -V080

$(MID_SUBDIR)/mus_rg_vs_gym_leader.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G155 -V090

$(MID_SUBDIR)/mus_rg_vs_champion.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G158 -V090

$(MID_SUBDIR)/mus_rg_vs_mewtwo.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G157 -V090

$(MID_SUBDIR)/mus_rg_vs_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G156 -V090

$(MID_SUBDIR)/mus_rg_vs_wild.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G157 -V090

$(MID_SUBDIR)/mus_cable_car.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G071 -V078

$(MID_SUBDIR)/mus_sootopolis.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G091 -V062

$(MID_SUBDIR)/mus_safari_zone.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G074 -V082

$(MID_SUBDIR)/mus_b_tower.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G110 -V100

$(MID_SUBDIR)/mus_evolution.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G026 -V080

$(MID_SUBDIR)/mus_encounter_elite_four.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G096 -V078

$(MID_SUBDIR)/mus_c_vs_legend_beast.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_SUBDIR)/mus_encounter_swimmer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G036 -V080

$(MID_SUBDIR)/mus_encounter_girl.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G027 -V080

$(MID_SUBDIR)/mus_intro_battle.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G088 -V088

$(MID_SUBDIR)/mus_encounter_rich.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G043 -V094

$(MID_SUBDIR)/mus_link_contest_p1.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G039 -V079

$(MID_SUBDIR)/mus_link_contest_p2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G040 -V090

$(MID_SUBDIR)/mus_link_contest_p3.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G041 -V075

$(MID_SUBDIR)/mus_link_contest_p4.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G042 -V090

$(MID_SUBDIR)/mus_littleroot_test.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G034 -V099

$(MID_SUBDIR)/mus_credits.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G101 -V100

$(MID_SUBDIR)/mus_title.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G059 -V090

$(MID_SUBDIR)/mus_fallarbor.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G083 -V100

$(MID_SUBDIR)/mus_mt_chimney.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G052 -V078

$(MID_SUBDIR)/mus_follow_me.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G066 -V074

$(MID_SUBDIR)/mus_vs_frontier_brain.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G115 -V090 -P1

$(MID_SUBDIR)/mus_vs_mew.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G116 -V090

$(MID_SUBDIR)/mus_encounter_hiker.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G097 -V076

$(MID_SUBDIR)/ph_choice_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_choice_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_choice_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_cloth_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_cloth_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_cloth_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_cure_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_cure_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_cure_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_dress_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_dress_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_dress_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_face_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_face_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_face_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_fleece_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_fleece_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_fleece_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_foot_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_foot_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_foot_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_goat_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_goat_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_goat_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_goose_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_goose_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_goose_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_kit_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_kit_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_kit_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_lot_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_lot_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_lot_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_mouth_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_mouth_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_mouth_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_nurse_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_nurse_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_nurse_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_price_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_price_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_price_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_strut_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_strut_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_strut_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_thought_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_thought_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_thought_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_trap_blend.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_trap_held.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/ph_trap_solo.s: %.s: %.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_SUBDIR)/se_a.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V095 -P4

$(MID_SUBDIR)/se_bang.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_taillow_wing_flap.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P5

$(MID_SUBDIR)/se_glass_flute.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P5

$(MID_SUBDIR)/se_boo.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P4

$(MID_SUBDIR)/se_ball.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V070 -P4

$(MID_SUBDIR)/se_ball_open.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_SUBDIR)/se_mugshot.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P5

$(MID_SUBDIR)/se_contest_heart.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P5

$(MID_SUBDIR)/se_contest_curtain_fall.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V070 -P5

$(MID_SUBDIR)/se_contest_curtain_rise.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V070 -P5

$(MID_SUBDIR)/se_contest_icon_change.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P5

$(MID_SUBDIR)/se_contest_mons_turn.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P5

$(MID_SUBDIR)/se_contest_icon_clear.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P5

$(MID_SUBDIR)/se_card.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P4

$(MID_SUBDIR)/se_pike_curtain_close.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_SUBDIR)/se_pike_curtain_open.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_SUBDIR)/se_ledge.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P4

$(MID_SUBDIR)/se_itemfinder.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P5

$(MID_SUBDIR)/se_applause.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P5

$(MID_SUBDIR)/se_field_poison.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P5

$(MID_SUBDIR)/se_door.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V080 -P5

$(MID_SUBDIR)/se_e.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P4

$(MID_SUBDIR)/se_elevator.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_SUBDIR)/se_escalator.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_SUBDIR)/se_exp.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V080 -P5

$(MID_SUBDIR)/se_exp_max.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V094 -P5

$(MID_SUBDIR)/se_fu_zaku.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V120 -P4

$(MID_SUBDIR)/se_contest_condition_lose.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P4

$(MID_SUBDIR)/se_lavaridge_fall_warp.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -P4

$(MID_SUBDIR)/se_balloon_red.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P4

$(MID_SUBDIR)/se_balloon_blue.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P4

$(MID_SUBDIR)/se_balloon_yellow.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P4

$(MID_SUBDIR)/se_arena_timeup1.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_SUBDIR)/se_arena_timeup2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_SUBDIR)/se_bridge_walk.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V095 -P4

$(MID_SUBDIR)/se_failure.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V120 -P4

$(MID_SUBDIR)/se_rotating_gate.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_SUBDIR)/se_low_health.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P3

$(MID_SUBDIR)/se_i.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P4

$(MID_SUBDIR)/se_sliding_door.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V095 -P4

$(MID_SUBDIR)/se_vend.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_bike_hop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P4

$(MID_SUBDIR)/se_bike_bell.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_SUBDIR)/se_contest_place.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P4

$(MID_SUBDIR)/se_exit.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V120 -P5

$(MID_SUBDIR)/se_use_item.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_SUBDIR)/se_unlock.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_SUBDIR)/se_ball_bounce_1.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_SUBDIR)/se_ball_bounce_2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_SUBDIR)/se_ball_bounce_3.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_SUBDIR)/se_ball_bounce_4.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_SUBDIR)/se_super_effective.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P5

$(MID_SUBDIR)/se_not_effective.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P5

$(MID_SUBDIR)/se_effective.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P5

$(MID_SUBDIR)/se_puddle.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V020 -P4

$(MID_SUBDIR)/se_berry_blender.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_SUBDIR)/se_switch.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P4

$(MID_SUBDIR)/se_n.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -P4

$(MID_SUBDIR)/se_ball_throw.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P5

$(MID_SUBDIR)/se_ship.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V075 -P4

$(MID_SUBDIR)/se_flee.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P5

$(MID_SUBDIR)/se_o.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P4

$(MID_SUBDIR)/se_intro_blast.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_SUBDIR)/se_pc_login.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_SUBDIR)/se_pc_off.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_SUBDIR)/se_pc_on.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_SUBDIR)/se_pin.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V060 -P4

$(MID_SUBDIR)/se_ding_dong.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P5

$(MID_SUBDIR)/se_pokenav_off.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_SUBDIR)/se_pokenav_on.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_SUBDIR)/se_faint.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P5

$(MID_SUBDIR)/se_shiny.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V095 -P5

$(MID_SUBDIR)/se_shop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P5

$(MID_SUBDIR)/se_rg_bag_cursor.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_SUBDIR)/se_rg_bag_pocket.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_SUBDIR)/se_rg_card_flip.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_SUBDIR)/se_rg_card_flipping.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_SUBDIR)/se_rg_card_open.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V112 -P5

$(MID_SUBDIR)/se_rg_deoxys_move.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V080 -P5

$(MID_SUBDIR)/se_rg_poke_jump_success.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P5

$(MID_SUBDIR)/se_rg_ball_click.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V100 -P5

$(MID_SUBDIR)/se_rg_help_close.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V095 -P5

$(MID_SUBDIR)/se_rg_help_error.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V125 -P5

$(MID_SUBDIR)/se_rg_help_open.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V096 -P5

$(MID_SUBDIR)/se_rg_ss_anne_horn.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V096 -P5

$(MID_SUBDIR)/se_rg_poke_jump_failure.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -P5

$(MID_SUBDIR)/se_rg_shop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V080 -P5

$(MID_SUBDIR)/se_rg_door.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V100 -P5

$(MID_SUBDIR)/se_ice_crack.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P4

$(MID_SUBDIR)/se_ice_stairs.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_SUBDIR)/se_ice_break.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_SUBDIR)/se_fall.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_save.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V080 -P5

$(MID_SUBDIR)/se_success.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V080 -P4

$(MID_SUBDIR)/se_select.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V080 -P5

$(MID_SUBDIR)/se_ball_trade.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_SUBDIR)/se_thunderstorm.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V080 -P2

$(MID_SUBDIR)/se_thunderstorm_stop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V080 -P2

$(MID_SUBDIR)/se_thunder.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P3

$(MID_SUBDIR)/se_thunder2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P3

$(MID_SUBDIR)/se_rain.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V080 -P2

$(MID_SUBDIR)/se_rain_stop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V080 -P2

$(MID_SUBDIR)/se_downpour.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P2

$(MID_SUBDIR)/se_downpour_stop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P2

$(MID_SUBDIR)/se_orb.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P5

$(MID_SUBDIR)/se_egg_hatch.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P5

$(MID_SUBDIR)/se_roulette_ball.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P2

$(MID_SUBDIR)/se_roulette_ball2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P2

$(MID_SUBDIR)/se_ball_tray_exit.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_SUBDIR)/se_ball_tray_ball.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P5

$(MID_SUBDIR)/se_ball_tray_enter.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P5

$(MID_SUBDIR)/se_click.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P4

$(MID_SUBDIR)/se_warp_in.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P4

$(MID_SUBDIR)/se_warp_out.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P4

$(MID_SUBDIR)/se_pokenav_call.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V120 -P5

$(MID_SUBDIR)/se_pokenav_hang_up.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V110 -P5

$(MID_SUBDIR)/se_note_a.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_note_b.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_note_c.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_note_c_high.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_note_d.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_mud_ball.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_note_e.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_note_f.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_note_g.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_breakable_door.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_truck_door.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_truck_unload.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -P4

$(MID_SUBDIR)/se_truck_move.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -P4

$(MID_SUBDIR)/se_truck_stop.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -P4

$(MID_SUBDIR)/se_repel.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P4

$(MID_SUBDIR)/se_u.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -P4

$(MID_SUBDIR)/se_sudowoodo_shake.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V077 -P5

$(MID_SUBDIR)/se_m_double_slap.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_comet_punch.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P4

$(MID_SUBDIR)/se_m_pay_day.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V095 -P4

$(MID_SUBDIR)/se_m_fire_punch.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_scratch.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_vicegrip.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_razor_wind.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_razor_wind2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_SUBDIR)/se_m_swords_dance.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_SUBDIR)/se_m_cut.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P4

$(MID_SUBDIR)/se_m_gust.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_gust2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_wing_attack.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P4

$(MID_SUBDIR)/se_m_fly.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_bind.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_SUBDIR)/se_m_mega_kick.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_SUBDIR)/se_m_mega_kick2.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_jump_kick.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_sand_attack.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_headbutt.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_horn_attack.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_take_down.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P4

$(MID_SUBDIR)/se_m_tail_whip.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_m_leer.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_SUBDIR)/se_dex_search.s: %.s: %.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -v100 -P5

$(MID_SUBDIR)/dp_seq_title00.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_title01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_opening.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_tv_housou.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V096

$(MID_SUBDIR)/dp_seq_tv_end.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090 -P5

$(MID_SUBDIR)/dp_seq_town01_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V125

$(MID_SUBDIR)/dp_seq_town01_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_the_riv.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V070

$(MID_SUBDIR)/dp_seq_road_a_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_road_a_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_d_lake.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V088

$(MID_SUBDIR)/dp_seq_the_event01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V096

$(MID_SUBDIR)/dp_seq_ba_poke.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V088

$(MID_SUBDIR)/dp_seq_winpoke.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V114

$(MID_SUBDIR)/dp_seq_the_girl.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_the_boy.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_fanfa4.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100 -P5

$(MID_SUBDIR)/dp_seq_town02_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_town02_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_kenkyujo.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_tsureteke.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V125

$(MID_SUBDIR)/dp_seq_pc_01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_pc_02.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_asa.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100 -P5

$(MID_SUBDIR)/dp_seq_eye_boy.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V105

$(MID_SUBDIR)/dp_seq_eye_girl.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V095

$(MID_SUBDIR)/dp_seq_ba_train.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V088

$(MID_SUBDIR)/dp_seq_wintrain.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V118

$(MID_SUBDIR)/dp_seq_city01_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V096

$(MID_SUBDIR)/dp_seq_city01_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V104

$(MID_SUBDIR)/dp_seq_fanfa3.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V094 -p5

$(MID_SUBDIR)/dp_seq_fs.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V082

$(MID_SUBDIR)/dp_seq_road_b_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_road_b_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_ba_rival.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V088

$(MID_SUBDIR)/dp_seq_d_05.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_waza.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100 -P5

$(MID_SUBDIR)/dp_seq_city03_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_city03_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_d_04.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V120

$(MID_SUBDIR)/dp_seq_gym.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V118

$(MID_SUBDIR)/dp_seq_ba_gym.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V088

$(MID_SUBDIR)/dp_seq_wintgym.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V120

$(MID_SUBDIR)/dp_seq_badge.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100 -P5

$(MID_SUBDIR)/dp_seq_eye_kid.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V082

$(MID_SUBDIR)/dp_seq_fanfa1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V125 -P5

$(MID_SUBDIR)/dp_seq_town03_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_town03_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_kinomi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100 -P5

$(MID_SUBDIR)/dp_seq_road_c_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V086

$(MID_SUBDIR)/dp_seq_road_c_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V086

$(MID_SUBDIR)/dp_seq_eye_ginga.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V068

$(MID_SUBDIR)/dp_seq_ba_ginga.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_d_02.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V088

$(MID_SUBDIR)/dp_seq_gonin.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V106 -P5

$(MID_SUBDIR)/dp_seq_city04_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V096

$(MID_SUBDIR)/dp_seq_city04_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V098

$(MID_SUBDIR)/dp_seq_d_ginlobby.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_ba_ginga3.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_winginga.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_shinka.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_fanfa5.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V094 -P5

$(MID_SUBDIR)/dp_seq_bicycle.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V115

$(MID_SUBDIR)/dp_seq_eye_sport.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V095

$(MID_SUBDIR)/dp_seq_road_d_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V108

$(MID_SUBDIR)/dp_seq_road_d_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V108

$(MID_SUBDIR)/dp_seq_city05_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V092

$(MID_SUBDIR)/dp_seq_city05_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_road_e_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V086

$(MID_SUBDIR)/dp_seq_road_e_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V086

$(MID_SUBDIR)/dp_seq_eye_mount.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V088

$(MID_SUBDIR)/dp_seq_town04_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_town04_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_pocketch.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100 -P5

$(MID_SUBDIR)/dp_seq_road_f_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V080

$(MID_SUBDIR)/dp_seq_road_f_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V080

$(MID_SUBDIR)/dp_seq_city07_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V120

$(MID_SUBDIR)/dp_seq_city07_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V118

$(MID_SUBDIR)/dp_seq_town07_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V096

$(MID_SUBDIR)/dp_seq_town07_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V095

$(MID_SUBDIR)/dp_seq_city02_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V108

$(MID_SUBDIR)/dp_seq_city02_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_road_snow_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_road_snow_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_city09_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_city09_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_d_agito.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V086

$(MID_SUBDIR)/dp_seq_ba_agaki.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_the_event04.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_d_mount1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V112

$(MID_SUBDIR)/dp_seq_d_mount2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_the_event02.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_the_event03.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_ba_dpoke2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_city08_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_city08_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_d_01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_eye_elite.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V080

$(MID_SUBDIR)/dp_seq_city10_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_city10_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_city11_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V080

$(MID_SUBDIR)/dp_seq_city11_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V080

$(MID_SUBDIR)/dp_seq_town06_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V094

$(MID_SUBDIR)/dp_seq_town06_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V094

$(MID_SUBDIR)/dp_seq_road_bza_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_road_bza_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_wifilobby.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_bld_tv.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V108

$(MID_SUBDIR)/dp_seq_bld_bld_gtc.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V096

$(MID_SUBDIR)/dp_seq_naminori.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V115

$(MID_SUBDIR)/dp_seq_wasure.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127 -P5

$(MID_SUBDIR)/dp_seq_eye_fight.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V070

$(MID_SUBDIR)/dp_seq_eye_enka.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V070

$(MID_SUBDIR)/dp_seq_tankou.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_hatanige.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_eye_lady.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_d_03.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_d_safari.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V084

$(MID_SUBDIR)/dp_seq_eye_mys.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V080

$(MID_SUBDIR)/dp_seq_bld_game.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_slot_atari.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V080

$(MID_SUBDIR)/dp_seq_slot_ooatari.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V075

$(MID_SUBDIR)/dp_seq_eye_rich.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V080

$(MID_SUBDIR)/dp_seq_d_ryayhy.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_ba_dpoke1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V078

$(MID_SUBDIR)/dp_seq_kusagasa.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V105

$(MID_SUBDIR)/dp_seq_eye_fun.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V115

$(MID_SUBDIR)/dp_seq_d_kouen.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V115

$(MID_SUBDIR)/dp_seq_acce.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V088 -P5

$(MID_SUBDIR)/dp_seq_bld_con.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V056

$(MID_SUBDIR)/dp_seq_kinomi1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_con_test.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_co_dress.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/dp_seq_co_kashi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_co_takuma.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V095

$(MID_SUBDIR)/dp_seq_co_kekka.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V080

$(MID_SUBDIR)/dp_seq_co_fanfa.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_bf_towwer.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V078

$(MID_SUBDIR)/dp_seq_d_06.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_ba_secret2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V092

$(MID_SUBDIR)/dp_seq_present.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_d_league.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_eye_tenno.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V086

$(MID_SUBDIR)/dp_seq_ba_tenno.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V094

$(MID_SUBDIR)/dp_seq_wintenno.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_eye_champ.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/dp_seq_ba_chanp.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/dp_seq_winchamp.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V105

$(MID_SUBDIR)/dp_seq_bld_dendo.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V112

$(MID_SUBDIR)/dp_seq_bld_ev_dendo2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V088

$(MID_SUBDIR)/dp_seq_bld_ending.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_ba_secret1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V092

$(MID_SUBDIR)/dp_seq_fue.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/dp_seq_aus.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/pl_seq_title00.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/pl_seq_title01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/pl_seq_tv_housou.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V096

$(MID_SUBDIR)/pl_seq_tv_end.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090 -P5

$(MID_SUBDIR)/pl_seq_pl_handsome.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V115

$(MID_SUBDIR)/pl_seq_pl_wifitower.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V085

$(MID_SUBDIR)/pl_seq_pl_wifiunion.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/pl_seq_pl_wifigame.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V115

$(MID_SUBDIR)/pl_seq_pl_winmini2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/pl_seq_pl_wifiparade.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/pl_seq_pl_ev_gira.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/pl_seq_pl_ev_gira2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V115

$(MID_SUBDIR)/pl_seq_pl_d_giratina.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V105

$(MID_SUBDIR)/pl_seq_pl_ba_gira.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V105

$(MID_SUBDIR)/pl_seq_pl_guruguru.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/pl_seq_pl_pthaifu.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V090

$(MID_SUBDIR)/pl_seq_pl_mtkawa.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/pl_seq_pl_mtkakko.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/pl_seq_pl_mttakma.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/pl_seq_pl_mtutsuk.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/pl_seq_pl_mtkashi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/pl_seq_pl_town02.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V100

$(MID_SUBDIR)/pl_seq_pl_audio.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V120

$(MID_SUBDIR)/pl_seq_city11_d.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V080

$(MID_SUBDIR)/pl_seq_pl_bf_roulette.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/pl_seq_pl_don2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V120

$(MID_SUBDIR)/pl_seq_pl_bf_stage.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V115

$(MID_SUBDIR)/pl_seq_pl_bf_factory.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/pl_seq_pl_bf_castle.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V110

$(MID_SUBDIR)/pl_seq_pl_fro.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V105

$(MID_SUBDIR)/pl_seq_pl_pointget3.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V127

$(MID_SUBDIR)/pl_seq_pl_ba_brain.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V120

$(MID_SUBDIR)/pl_seq_pl_winbrain.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V108

$(MID_SUBDIR)/pl_seq_pl_ba_regi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G191 -V105

$(MID_SUBDIR)/hg_seq_gs_title.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V122

$(MID_SUBDIR)/hg_seq_gs_pokemon_theme.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V109

$(MID_SUBDIR)/hg_seq_gs_starting.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V073

$(MID_SUBDIR)/hg_seq_gs_t_wakaba.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080

$(MID_SUBDIR)/hg_seq_gs_e_tsureteke1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V079

$(MID_SUBDIR)/hg_seq_gs_e_support_f.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V087

$(MID_SUBDIR)/hg_seq_gs_e_support_m.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V087

$(MID_SUBDIR)/hg_seq_gs_utsugi_rabo.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080

$(MID_SUBDIR)/hg_seq_me_keyitem.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V081 -P5

$(MID_SUBDIR)/hg_seq_gs_r_1_29.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V063

$(MID_SUBDIR)/hg_seq_gs_vs_norapoke.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V110

$(MID_SUBDIR)/hg_seq_gs_win2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V110

$(MID_SUBDIR)/hg_seq_gs_win2_not_fan.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V072

$(MID_SUBDIR)/hg_seq_me_lvup.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V102 -P5

$(MID_SUBDIR)/hg_seq_gs_c_yoshino.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V068

$(MID_SUBDIR)/hg_seq_gs_e_tsureteke2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V078

$(MID_SUBDIR)/hg_seq_gs_pokesen.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V075

$(MID_SUBDIR)/hg_seq_me_asa.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080 -P5

$(MID_SUBDIR)/hg_seq_gs_eye_j_shounen.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V102

$(MID_SUBDIR)/hg_seq_gs_vs_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V111

$(MID_SUBDIR)/hg_seq_gs_win1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V110

$(MID_SUBDIR)/hg_seq_gs_r_1_30.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V093

$(MID_SUBDIR)/hg_seq_me_hyouka1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V092 -P5

$(MID_SUBDIR)/hg_seq_gs_c_kikyou.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V078

$(MID_SUBDIR)/hg_seq_gs_to_madatsubomi1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V062

$(MID_SUBDIR)/hg_seq_gs_eye_bouzu.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V084

$(MID_SUBDIR)/hg_seq_gs_fs.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V078

$(MID_SUBDIR)/hg_seq_me_tamago_get.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V088 -P5

$(MID_SUBDIR)/hg_seq_gs_e_maiko_theme.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V088

$(MID_SUBDIR)/hg_seq_gs_d_chikatsuuro.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080

$(MID_SUBDIR)/hg_seq_me_item.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V081 -P5

$(MID_SUBDIR)/hg_seq_gs_d_unknown_iseki.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V093

$(MID_SUBDIR)/hg_seq_gs_radio_unknown.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V089

$(MID_SUBDIR)/hg_seq_me_hyouka2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V095 -P5

$(MID_SUBDIR)/hg_seq_gs_t_hiwada.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V073

$(MID_SUBDIR)/hg_seq_gs_eye_rocket.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V071

$(MID_SUBDIR)/hg_seq_gs_vs_rocket.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V102

$(MID_SUBDIR)/hg_seq_gs_r_4_34.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V092

$(MID_SUBDIR)/hg_seq_gs_e_rival1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V089

$(MID_SUBDIR)/hg_seq_gs_vs_rival.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V084

$(MID_SUBDIR)/hg_seq_gs_shinka.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080

$(MID_SUBDIR)/hg_seq_me_shinkaome.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V076 -p5

$(MID_SUBDIR)/hg_seq_gs_c_kogane.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V072

$(MID_SUBDIR)/hg_seq_gs_gym.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080

$(MID_SUBDIR)/hg_seq_gs_vs_gymreader.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V108

$(MID_SUBDIR)/hg_seq_gs_win3.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V102

$(MID_SUBDIR)/hg_seq_me_badge.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V104 -p5

$(MID_SUBDIR)/hg_seq_gs_radio_jingle.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V082

$(MID_SUBDIR)/hg_seq_gs_aikotoba.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V092

$(MID_SUBDIR)/hg_seq_me_waza.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V087 -p5

$(MID_SUBDIR)/hg_seq_gs_game.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V092

$(MID_SUBDIR)/hg_seq_gs_gameatari.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V078

$(MID_SUBDIR)/hg_seq_me_acce.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V072 -p5

$(MID_SUBDIR)/hg_seq_gs_wifitower.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V075

$(MID_SUBDIR)/hg_seq_gs_bld_gtc.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V091

$(MID_SUBDIR)/hg_seq_me_hyouka3.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V081 -p5

$(MID_SUBDIR)/hg_seq_pl_bicycle.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V085

$(MID_SUBDIR)/hg_seq_gs_eye_j_shoujo.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V084

$(MID_SUBDIR)/hg_seq_me_pokegear_regist.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V097 -p5

$(MID_SUBDIR)/hg_seq_gs_d_kouen.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V087

$(MID_SUBDIR)/hg_seq_me_kinomi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V082 -p5

$(MID_SUBDIR)/hg_seq_gs_c_enju.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V054

$(MID_SUBDIR)/hg_seq_gs_kaburenjou.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080

$(MID_SUBDIR)/hg_seq_gs_to_yaketa.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V070

$(MID_SUBDIR)/hg_seq_gs_e_minaki.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V086

$(MID_SUBDIR)/hg_seq_gs_ohkido_rabo.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V089

$(MID_SUBDIR)/hg_seq_me_hyouka4.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V092 -p5

$(MID_SUBDIR)/hg_seq_gs_r_6_38.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V083

$(MID_SUBDIR)/hg_seq_gs_radio_march.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V082

$(MID_SUBDIR)/hg_seq_gs_vs_raikou.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V098

$(MID_SUBDIR)/hg_seq_gs_to_toudai.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V050

$(MID_SUBDIR)/hg_seq_gs_naminori.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V085

$(MID_SUBDIR)/hg_seq_gs_c_tanba.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V073

$(MID_SUBDIR)/hg_seq_me_pt_special.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V098 -p5

$(MID_SUBDIR)/hg_seq_gs_r_7_42.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V085

$(MID_SUBDIR)/hg_seq_gs_kaidenpa.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V092

$(MID_SUBDIR)/hg_seq_gs_d_ajito.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V081

$(MID_SUBDIR)/hg_seq_gs_eye_j_ayashii.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V073

$(MID_SUBDIR)/hg_seq_gs_e_rival2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V089

$(MID_SUBDIR)/hg_seq_gs_senkyo.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V069

$(MID_SUBDIR)/hg_seq_gs_d_koorinonuke.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V072

$(MID_SUBDIR)/hg_seq_me_wasure.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V105 -p5

$(MID_SUBDIR)/hg_seq_gs_ryuunoana.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V087

$(MID_SUBDIR)/hg_seq_gs_ibuki.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V089

$(MID_SUBDIR)/hg_seq_gs_vs_entei.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V098

$(MID_SUBDIR)/hg_seq_gs_to_suzu.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080

$(MID_SUBDIR)/hg_seq_gs_e_maiko_mai.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V088

$(MID_SUBDIR)/hg_seq_gs_e_houou.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V108

$(MID_SUBDIR)/hg_seq_gs_vs_houou.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V079

$(MID_SUBDIR)/hg_seq_gs_r_1_26.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V078

$(MID_SUBDIR)/hg_seq_gs_kousokusen.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V077

$(MID_SUBDIR)/hg_seq_gs_c_kuchiba.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V062

$(MID_SUBDIR)/hg_seq_gs_vs_gymreader_kanto.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V075

$(MID_SUBDIR)/hg_seq_gs_t_chion.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V073

$(MID_SUBDIR)/hg_seq_gs_d_iwayama.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V079

$(MID_SUBDIR)/hg_seq_gs_vs_norapoke_kanto.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V103

$(MID_SUBDIR)/hg_seq_me_hyouka5.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V092 -p5

$(MID_SUBDIR)/hg_seq_gs_c_hanada.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V073

$(MID_SUBDIR)/hg_seq_gs_r_12_24.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080

$(MID_SUBDIR)/hg_seq_gs_e_linear.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V100

$(MID_SUBDIR)/hg_seq_gs_radio_komoriuta.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V082

$(MID_SUBDIR)/hg_seq_gs_vs_suicune.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V098

$(MID_SUBDIR)/hg_seq_gs_c_tamamushi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V063

$(MID_SUBDIR)/hg_seq_gs_r_10_11.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V077

$(MID_SUBDIR)/hg_seq_gs_hue.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V089

$(MID_SUBDIR)/hg_seq_gs_d_tokiwanomori3.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V087

$(MID_SUBDIR)/hg_seq_gs_eye_k_shounen.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V089

$(MID_SUBDIR)/hg_seq_gs_c_yamabuki.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V058

$(MID_SUBDIR)/hg_seq_gs_r_9_03.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V087

$(MID_SUBDIR)/hg_seq_gs_eye_k_ayashii.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V086

$(MID_SUBDIR)/hg_seq_gs_otsukimi_event.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V105

$(MID_SUBDIR)/hg_seq_gs_r_9_01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V085

$(MID_SUBDIR)/hg_seq_gs_t_masara.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080

$(MID_SUBDIR)/hg_seq_gs_ohkido.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V100

$(MID_SUBDIR)/hg_seq_me_hyouka6.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V092 -p5

$(MID_SUBDIR)/hg_seq_gs_eye_k_shoujo.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V097

$(MID_SUBDIR)/hg_seq_gs_vs_trainer_kanto.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V119

$(MID_SUBDIR)/hg_seq_gs_t_guren.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V075

$(MID_SUBDIR)/hg_seq_gs_safari_road.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V073

$(MID_SUBDIR)/hg_seq_gs_safari_house.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V079

$(MID_SUBDIR)/hg_seq_gs_safari_field.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V087

$(MID_SUBDIR)/hg_seq_gs_radio_variety.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V073

$(MID_SUBDIR)/hg_seq_gs_taikaimae.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V052

$(MID_SUBDIR)/hg_seq_gs_taikai.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V100

$(MID_SUBDIR)/hg_seq_me_mushitori3.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V097 -p5

$(MID_SUBDIR)/hg_seq_me_mushitori2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V102 -p5

$(MID_SUBDIR)/hg_seq_me_mushitori1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V097 -p5

$(MID_SUBDIR)/hg_seq_gs_pt_entr.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V085

$(MID_SUBDIR)/hg_seq_me_pt_new.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V102 -p5

$(MID_SUBDIR)/hg_seq_gs_pt_open.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V090

$(MID_SUBDIR)/hg_seq_gs_pt_title.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V089

$(MID_SUBDIR)/hg_seq_gs_pt_game.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V096

$(MID_SUBDIR)/hg_seq_me_pt_resultg.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V098 -p5

$(MID_SUBDIR)/hg_seq_gs_pt_gamef.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V097

$(MID_SUBDIR)/hg_seq_gs_pt_result.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V088

$(MID_SUBDIR)/hg_seq_gs_pt_end.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V098

$(MID_SUBDIR)/hg_seq_gs_pt_victory.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V088

$(MID_SUBDIR)/hg_seq_gs_wifi_present.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V087

$(MID_SUBDIR)/hg_seq_gs_battletower2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V070

$(MID_SUBDIR)/hg_seq_gs_battletower.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V097

$(MID_SUBDIR)/hg_seq_me_bpget.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V107 -p5

$(MID_SUBDIR)/hg_seq_gs_bf_factory.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V077

$(MID_SUBDIR)/hg_seq_gs_bf_stage.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V080

$(MID_SUBDIR)/hg_seq_gs_bf_roulette.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V077

$(MID_SUBDIR)/hg_seq_me_roulette.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V098 -p5

$(MID_SUBDIR)/hg_seq_gs_bf_castle.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V097

$(MID_SUBDIR)/hg_seq_me_castle.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V086 -p5

$(MID_SUBDIR)/hg_seq_gs_ba_brain.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V100

$(MID_SUBDIR)/hg_seq_gs_winbrain.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V097

$(MID_SUBDIR)/hg_seq_gs_radio_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V073

$(MID_SUBDIR)/hg_seq_gs_guruguru.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V093

$(MID_SUBDIR)/hg_seq_gs_wifi_access.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V079

$(MID_SUBDIR)/hg_seq_gs_wifiunion.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V085

$(MID_SUBDIR)/hg_seq_gs_wifigame.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V095

$(MID_SUBDIR)/hg_seq_me_minigame.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V091 -p5

$(MID_SUBDIR)/hg_seq_gs_wifiparade.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V092

$(MID_SUBDIR)/hg_seq_gs_radio_r_101.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V069

$(MID_SUBDIR)/hg_seq_gs_radio_r_201.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V104

$(MID_SUBDIR)/hg_seq_gs_phc.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V106

$(MID_SUBDIR)/hg_seq_gs_e_g_pichu.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V100

$(MID_SUBDIR)/hg_seq_gs_eye_maiko.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V084

$(MID_SUBDIR)/hg_seq_gs_e_lugia.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V092

$(MID_SUBDIR)/hg_seq_gs_vs_lugia.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V102

$(MID_SUBDIR)/hg_seq_gs_d_champroad.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V087

$(MID_SUBDIR)/hg_seq_gs_champroad.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V082

$(MID_SUBDIR)/hg_seq_gs_vs_champ.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V113

$(MID_SUBDIR)/hg_seq_gs_e_dendouiri.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V099

$(MID_SUBDIR)/hg_seq_gs_ending.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V059

$(MID_SUBDIR)/hg_seq_gs_ending2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V074

$(MID_SUBDIR)/hg_seq_gs_vs_kodai.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V110

$(MID_SUBDIR)/hg_seq_gs_d_shinto.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V088

$(MID_SUBDIR)/hg_seq_gs_e_arceus.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V099

$(MID_SUBDIR)/hg_seq_gs_koukan.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -v080

$(MID_SUBDIR)/hg_seq_me_cardgame1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V098 -p5

$(MID_SUBDIR)/hg_seq_me_cardgame2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V097 -p5

$(MID_SUBDIR)/hg_seq_me_gonin.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G229 -V088 -p5

$(MID_SUBDIR)/bw_seq_bgm_gf_logo.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G278 -V070

$(MID_SUBDIR)/bw_seq_bgm_title.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V092

$(MID_SUBDIR)/bw_seq_bgm_title01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V093

$(MID_SUBDIR)/bw_seq_bgm_pokemon_theme.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V106

$(MID_SUBDIR)/bw_seq_bgm_starting.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V045

$(MID_SUBDIR)/bw_seq_bgm_starting2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V090

$(MID_SUBDIR)/bw_seq_bgm_e_opening.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V103 -X

$(MID_SUBDIR)/bw_seq_bgm_t_01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V071

$(MID_SUBDIR)/bw_seq_bgm_vs_rival.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V079

$(MID_SUBDIR)/bw_seq_bgm_e_tsureteke1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V066

$(MID_SUBDIR)/bw_seq_bgm_e_doctor.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V100

$(MID_SUBDIR)/bw_seq_bgm_labo.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V066

$(MID_SUBDIR)/bw_seq_me_keyitem.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V085 -p5

$(MID_SUBDIR)/bw_seq_bgm_e_friend.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V081

$(MID_SUBDIR)/bw_seq_bgm_r_a.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V063

$(MID_SUBDIR)/bw_seq_bgm_vs_norapoke.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V094

$(MID_SUBDIR)/bw_seq_bgm_win1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V116

$(MID_SUBDIR)/bw_seq_me_lvup.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V090 -p5

$(MID_SUBDIR)/bw_seq_bgm_t_02.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V060

$(MID_SUBDIR)/bw_seq_bgm_e_tsureteke2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V066

$(MID_SUBDIR)/bw_seq_bgm_pokecen.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V066

$(MID_SUBDIR)/bw_seq_me_asa.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V070 -p5

$(MID_SUBDIR)/bw_seq_me_hyouka1.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V079 -p5

$(MID_SUBDIR)/bw_seq_bgm_e_sage.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V099

$(MID_SUBDIR)/bw_seq_bgm_r_b_sp.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V082

$(MID_SUBDIR)/bw_seq_bgm_r_b_su.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V082

$(MID_SUBDIR)/bw_seq_bgm_r_b_au.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V082

$(MID_SUBDIR)/bw_seq_bgm_r_b_wi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V082

$(MID_SUBDIR)/bw_seq_me_call.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V095 -p5

$(MID_SUBDIR)/bw_seq_bgm_eye_01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V064

$(MID_SUBDIR)/bw_seq_bgm_vs_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V090

$(MID_SUBDIR)/bw_seq_bgm_win2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V095

$(MID_SUBDIR)/bw_seq_bgm_eye_02.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V065

$(MID_SUBDIR)/bw_seq_me_item.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V070 -p5

$(MID_SUBDIR)/bw_seq_bgm_c_01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V064

$(MID_SUBDIR)/bw_seq_me_hyouka2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V081 -p5

$(MID_SUBDIR)/bw_seq_bgm_d_01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V093

$(MID_SUBDIR)/bw_seq_bgm_d_01_b1f.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V093

$(MID_SUBDIR)/bw_seq_bgm_e_plasma.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V073

$(MID_SUBDIR)/bw_seq_bgm_vs_plasma.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V120

$(MID_SUBDIR)/bw_seq_bgm_win6.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G277 -V079

$(MID_SUBDIR)/bw_seq_bgm_shinka.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V068

$(MID_SUBDIR)/bw_seq_bgm_koukan.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V076

$(MID_SUBDIR)/bw_seq_me_shinkaome.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V072 -p5

$(MID_SUBDIR)/bw_seq_bgm_eye_03.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V067

$(MID_SUBDIR)/bw_seq_bgm_e_rival.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V059

$(MID_SUBDIR)/bw_seq_bgm_e_trouble.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V092

$(MID_SUBDIR)/bw_seq_bgm_c_02.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V070

$(MID_SUBDIR)/bw_seq_me_hyouka3.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V070 -p5

$(MID_SUBDIR)/bw_seq_bgm_gym.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V056

$(MID_SUBDIR)/bw_seq_bgm_vs_gymleader.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V106

$(MID_SUBDIR)/bw_seq_bgm_battlesuperior.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V090

$(MID_SUBDIR)/bw_seq_bgm_win3.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V096

$(MID_SUBDIR)/bw_seq_me_badge.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V081 -p5

$(MID_SUBDIR)/bw_seq_me_waza.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V093 -p5

$(MID_SUBDIR)/bw_seq_bgm_gate.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V079

$(MID_SUBDIR)/bw_seq_bgm_h_01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V106

$(MID_SUBDIR)/bw_seq_bgm_c_03.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V064

$(MID_SUBDIR)/bw_seq_bgm_eye_12.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V073

$(MID_SUBDIR)/bw_seq_bgm_r_c_sp.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V086

$(MID_SUBDIR)/bw_seq_bgm_r_c_su.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V086

$(MID_SUBDIR)/bw_seq_bgm_r_c_au.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V086

$(MID_SUBDIR)/bw_seq_bgm_r_c_wi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V086

$(MID_SUBDIR)/bw_seq_bgm_eye_11.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V080

$(MID_SUBDIR)/bw_seq_bgm_c_04.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V073

$(MID_SUBDIR)/bw_seq_bgm_e_support.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V052

$(MID_SUBDIR)/bw_seq_bgm_e_emotion.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V090

$(MID_SUBDIR)/bw_seq_bgm_e_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V078

$(MID_SUBDIR)/bw_seq_bgm_vs_n.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V126

$(MID_SUBDIR)/bw_seq_bgm_battlepinch.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V086 -p1

$(MID_SUBDIR)/bw_seq_bgm_bicycle.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V082

$(MID_SUBDIR)/bw_seq_bgm_e_champion.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V068

$(MID_SUBDIR)/bw_seq_bgm_h_02.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V124

$(MID_SUBDIR)/bw_seq_bgm_c_05.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V076

$(MID_SUBDIR)/bw_seq_bgm_d_03.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V057

$(MID_SUBDIR)/bw_seq_bgm_r_d_sp.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V076

$(MID_SUBDIR)/bw_seq_bgm_r_d_su.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V076

$(MID_SUBDIR)/bw_seq_bgm_r_d_au.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V076

$(MID_SUBDIR)/bw_seq_bgm_r_d_wi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V076

$(MID_SUBDIR)/bw_seq_bgm_eye_06.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V050

$(MID_SUBDIR)/bw_seq_bgm_eye_09.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V059

$(MID_SUBDIR)/bw_seq_bgm_d_02.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V107

$(MID_SUBDIR)/bw_seq_bgm_d_02_b1f.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V107

$(MID_SUBDIR)/bw_seq_bgm_d_02_b2f.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V107

$(MID_SUBDIR)/bw_seq_bgm_c_06.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V089

$(MID_SUBDIR)/bw_seq_bgm_e_doctor2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V083

$(MID_SUBDIR)/bw_seq_me_hyouka4.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V082 -p5

$(MID_SUBDIR)/bw_seq_me_wasure.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V115 -p5

$(MID_SUBDIR)/bw_seq_bgm_eye_08.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V086

$(MID_SUBDIR)/bw_seq_bgm_c_07.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V064

$(MID_SUBDIR)/bw_seq_bgm_d_05.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V089

$(MID_SUBDIR)/bw_seq_bgm_eye_plasma.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V088

$(MID_SUBDIR)/bw_seq_bgm_d_07.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V094

$(MID_SUBDIR)/bw_seq_bgm_d_04.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V074

$(MID_SUBDIR)/bw_seq_me_item_mystery.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V088 -p5

$(MID_SUBDIR)/bw_seq_bgm_h_03.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V060

$(MID_SUBDIR)/bw_seq_bgm_fs.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V088

$(MID_SUBDIR)/bw_seq_bgm_eye_05.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V056

$(MID_SUBDIR)/bw_seq_bgm_c_08_b.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V058

$(MID_SUBDIR)/bw_seq_bgm_c_08_w.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V080 -X

$(MID_SUBDIR)/bw_seq_bgm_r_f.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V094

$(MID_SUBDIR)/bw_seq_bgm_d_champroad.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V098

$(MID_SUBDIR)/bw_seq_bgm_eye_04.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V061

$(MID_SUBDIR)/bw_seq_bgm_pokemon_league.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V092

$(MID_SUBDIR)/bw_seq_bgm_vs_shitenno.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V090

$(MID_SUBDIR)/bw_seq_bgm_e_n_castle.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V117

$(MID_SUBDIR)/bw_seq_bgm_n_castle_bridge.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V110

$(MID_SUBDIR)/bw_seq_bgm_n_castle.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V110

$(MID_SUBDIR)/bw_seq_bgm_n_room.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V089

$(MID_SUBDIR)/bw_seq_bgm_e_legend_come.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V111

$(MID_SUBDIR)/bw_seq_bgm_e_legend_born.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V118

$(MID_SUBDIR)/bw_seq_bgm_vs_shin.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V091 -X

$(MID_SUBDIR)/bw_seq_bgm_vs_n_2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V105

$(MID_SUBDIR)/bw_seq_bgm_e_g_cis.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V088

$(MID_SUBDIR)/bw_seq_bgm_vs_g_cis.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V126

$(MID_SUBDIR)/bw_seq_bgm_e_last.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V111 -X

$(MID_SUBDIR)/bw_seq_bgm_ending.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V106

$(MID_SUBDIR)/bw_seq_bgm_e_handsome.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V078

$(MID_SUBDIR)/bw_seq_me_tamago_get.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V072 -p5

$(MID_SUBDIR)/bw_seq_bgm_pleasure_boat.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V078

$(MID_SUBDIR)/bw_seq_bgm_wifi_access.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V065

$(MID_SUBDIR)/bw_seq_bgm_glterminal.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V094

$(MID_SUBDIR)/bw_seq_bgm_gts.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V100

$(MID_SUBDIR)/bw_seq_bgm_guruguru.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V061

$(MID_SUBDIR)/bw_seq_bgm_united_nations.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V074

$(MID_SUBDIR)/bw_seq_me_hyouka5.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V076 -p5

$(MID_SUBDIR)/bw_seq_bgm_gear_station.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V057

$(MID_SUBDIR)/bw_seq_bgm_battle_subway.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V071

$(MID_SUBDIR)/bw_seq_bgm_vs_subway_trainer.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V112

$(MID_SUBDIR)/bw_seq_me_bpget.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V081 -p5

$(MID_SUBDIR)/bw_seq_bgm_msl_field.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V113

$(MID_SUBDIR)/bw_seq_me_acce.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V063 -p5

$(MID_SUBDIR)/bw_seq_bgm_msl_dressup.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V074

$(MID_SUBDIR)/bw_seq_bgm_msl_before.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V072

$(MID_SUBDIR)/bw_seq_bgm_msl_01.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G277 -V074

$(MID_SUBDIR)/bw_seq_bgm_msl_02.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V084

$(MID_SUBDIR)/bw_seq_bgm_msl_03.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V079

$(MID_SUBDIR)/bw_seq_bgm_msl_04.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V074

$(MID_SUBDIR)/bw_seq_bgm_msl_dl_munna.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G278 -V080

$(MID_SUBDIR)/bw_seq_bgm_msl_dl_smash.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G278 -V080

$(MID_SUBDIR)/bw_seq_bgm_msl_dl_festa.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G278 -V080

$(MID_SUBDIR)/bw_seq_bgm_msl_dl_relic.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G278 -V080

$(MID_SUBDIR)/bw_seq_bgm_msl_dl_runpa.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G278 -V080

$(MID_SUBDIR)/bw_seq_bgm_e_kanransya.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V063

$(MID_SUBDIR)/bw_seq_me_aishou_kidou.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G277 -V110 -p5

$(MID_SUBDIR)/bw_seq_me_aishou_h.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G277 -V066 -p5

$(MID_SUBDIR)/bw_seq_me_aishou_m.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G277 -V066 -p5

$(MID_SUBDIR)/bw_seq_me_aishou_l.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G277 -V066 -p5

$(MID_SUBDIR)/bw_seq_bgm_vs_movepoke.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V106

$(MID_SUBDIR)/bw_seq_bgm_t_03.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V082

$(MID_SUBDIR)/bw_seq_bgm_h_05.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V089

$(MID_SUBDIR)/bw_seq_bgm_r_e_sp.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V071

$(MID_SUBDIR)/bw_seq_bgm_r_e_su.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V071

$(MID_SUBDIR)/bw_seq_bgm_r_e_au.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V071

$(MID_SUBDIR)/bw_seq_bgm_r_e_wi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V071

$(MID_SUBDIR)/bw_seq_bgm_eye_07.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V108

$(MID_SUBDIR)/bw_seq_bgm_palpark.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V077

$(MID_SUBDIR)/bw_seq_bgm_palpark_box.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V085

$(MID_SUBDIR)/bw_seq_bgm_palpark_game.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V073

$(MID_SUBDIR)/bw_seq_bgm_eye_10.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V058

$(MID_SUBDIR)/bw_seq_bgm_c_10_b.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V076

$(MID_SUBDIR)/bw_seq_bgm_c_10_w.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V098

$(MID_SUBDIR)/bw_seq_bgm_game_sync.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V086

$(MID_SUBDIR)/bw_seq_bgm_palace.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V078

$(MID_SUBDIR)/bw_seq_me_mission_start.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V112 -p5

$(MID_SUBDIR)/bw_seq_bgm_palace2.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V094

$(MID_SUBDIR)/bw_seq_me_mission_clear.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V105 -p5

$(MID_SUBDIR)/bw_seq_me_mission_failed.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V118 -p5

$(MID_SUBDIR)/bw_seq_bgm_eye_13.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V096

$(MID_SUBDIR)/bw_seq_bgm_t_05_sp.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V077

$(MID_SUBDIR)/bw_seq_bgm_t_05_su.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V094

$(MID_SUBDIR)/bw_seq_bgm_e_shirona.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V056

$(MID_SUBDIR)/bw_seq_bgm_vs_shirona.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G279 -V068

$(MID_SUBDIR)/bw_seq_bgm_d_06.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G277 -V062

$(MID_SUBDIR)/bw_seq_bgm_vs_tsuyopoke.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V096

$(MID_SUBDIR)/bw_seq_bgm_naminori.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V068

$(MID_SUBDIR)/bw_seq_bgm_diving.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V084

$(MID_SUBDIR)/bw_seq_bgm_t_04.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V090

$(MID_SUBDIR)/bw_seq_bgm_h_04.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G280 -V090 -X

$(MID_SUBDIR)/bw_seq_bgm_wifi_present.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V052

$(MID_SUBDIR)/bw_seq_bgm_wcs.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V092

$(MID_SUBDIR)/bw_seq_bgm_e_sound_designer.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V064

$(MID_SUBDIR)/bw_seq_bgm_vs_rai.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V091 -X

$(MID_SUBDIR)/bw_seq_me_hyouka6.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V076 -p5

$(MID_SUBDIR)/bw_seq_bgm_vs_champ.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G276 -V094

$(MID_SUBDIR)/bw_seq_bgm_win5.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G275 -V090

$(MID_SUBDIR)/bw_seq_bgm_e_dendouiri.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G277 -V074

$(MID_SUBDIR)/bw_seq_bgm_e_inishie.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V089

$(MID_SUBDIR)/bw_seq_bgm_vs_wcs.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V092

$(MID_SUBDIR)/bw_seq_me_kinomi.s: %.s: %.mid
	$(MID) $< $@ -E -R5 -G274 -V091 -p5
