STD_REVERB = 50

$(MID_BUILDDIR)/%.o: $(MID_BUILDDIR)/%.s
	$(AS) $(ASFLAGS) -I sound -o $@ $<

$(MID_BUILDDIR)/mus_aqua_magma_hideout.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G076 -V084

$(MID_BUILDDIR)/mus_encounter_aqua.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G065 -V086

$(MID_BUILDDIR)/mus_route111.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G055 -V076

$(MID_BUILDDIR)/mus_encounter_suspicious.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G069 -V078

$(MID_BUILDDIR)/mus_b_arena.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G104 -V090

$(MID_BUILDDIR)/mus_b_dome.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G111 -V090

$(MID_BUILDDIR)/mus_b_dome_lobby.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G111 -V056

$(MID_BUILDDIR)/mus_b_factory.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G113 -V100

$(MID_BUILDDIR)/mus_b_frontier.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G103 -V094

$(MID_BUILDDIR)/mus_b_palace.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G108 -V105

$(MID_BUILDDIR)/mus_b_tower_rs.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G035 -V080

$(MID_BUILDDIR)/mus_b_pike.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G112 -V092

$(MID_BUILDDIR)/mus_vs_trainer.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G119 -V080 -P1

$(MID_BUILDDIR)/mus_vs_wild.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G117 -V080 -P1

$(MID_BUILDDIR)/mus_vs_aqua_magma_leader.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G126 -V080 -P1

$(MID_BUILDDIR)/mus_vs_aqua_magma.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G118 -V080 -P1

$(MID_BUILDDIR)/mus_vs_gym_leader.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G120 -V080 -P1

$(MID_BUILDDIR)/mus_vs_champion.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G121 -V080 -P1

$(MID_BUILDDIR)/mus_vs_kyogre_groudon.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G123 -V080 -P1

$(MID_BUILDDIR)/mus_vs_rival.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G124 -V080 -P1

$(MID_BUILDDIR)/mus_vs_regi.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G122 -V080 -P1

$(MID_BUILDDIR)/mus_vs_elite_four.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G125 -V080 -P1

$(MID_BUILDDIR)/mus_roulette.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G038 -V080

$(MID_BUILDDIR)/mus_lilycove_museum.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G020 -V080

$(MID_BUILDDIR)/mus_encounter_brendan.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G067 -V078

$(MID_BUILDDIR)/mus_encounter_male.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G028 -V080

$(MID_BUILDDIR)/mus_victory_road.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G075 -V076

$(MID_BUILDDIR)/mus_game_corner.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G072 -V072

$(MID_BUILDDIR)/mus_contest_winner.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G085 -V100

$(MID_BUILDDIR)/mus_contest_results.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G092 -V080

$(MID_BUILDDIR)/mus_contest_lobby.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G098 -V060

$(MID_BUILDDIR)/mus_contest.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G086 -V088

$(MID_BUILDDIR)/mus_cycling.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G049 -V083

$(MID_BUILDDIR)/mus_encounter_champion.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G100 -V076

$(MID_BUILDDIR)/mus_petalburg_woods.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G018 -V080

$(MID_BUILDDIR)/mus_abandoned_ship.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G030 -V080

$(MID_BUILDDIR)/mus_cave_of_origin.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G037 -V080

$(MID_BUILDDIR)/mus_underwater.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G057 -V094

$(MID_BUILDDIR)/mus_intro.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G060 -V090

$(MID_BUILDDIR)/mus_hall_of_fame.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G082 -V078

$(MID_BUILDDIR)/mus_route110.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G010 -V080

$(MID_BUILDDIR)/mus_route120.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G014 -V080

$(MID_BUILDDIR)/mus_route122.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G021 -V080

$(MID_BUILDDIR)/mus_route101.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G011 -V080

$(MID_BUILDDIR)/mus_dummy.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R40

$(MID_BUILDDIR)/mus_hall_of_fame_room.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G093 -V080

$(MID_BUILDDIR)/mus_end.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G102 -V036

$(MID_BUILDDIR)/mus_help.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G056 -V078

$(MID_BUILDDIR)/mus_level_up.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_obtain_item.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_evolved.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_gsc_route38.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_BUILDDIR)/mus_slateport.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G079 -V070

$(MID_BUILDDIR)/mus_poke_mart.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G050 -V085

$(MID_BUILDDIR)/mus_oceanic_museum.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G023 -V080

$(MID_BUILDDIR)/mus_gym.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G013 -V080

$(MID_BUILDDIR)/mus_encounter_may.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G061 -V078

$(MID_BUILDDIR)/mus_encounter_female.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G053 -V072

$(MID_BUILDDIR)/mus_verdanturf.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G044 -V090

$(MID_BUILDDIR)/mus_rustboro.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G045 -V085

$(MID_BUILDDIR)/mus_route119.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G048 -V096

$(MID_BUILDDIR)/mus_encounter_intense.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G062 -V078

$(MID_BUILDDIR)/mus_weather_groudon.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G090 -V050

$(MID_BUILDDIR)/mus_dewford.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G073 -V078

$(MID_BUILDDIR)/mus_encounter_twins.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G095 -V075

$(MID_BUILDDIR)/mus_encounter_interviewer.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G099 -V062

$(MID_BUILDDIR)/mus_victory_trainer.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G058 -V091

$(MID_BUILDDIR)/mus_victory_wild.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G025 -V080

$(MID_BUILDDIR)/mus_victory_gym_leader.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G024 -V080

$(MID_BUILDDIR)/mus_victory_aqua_magma.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G070 -V088

$(MID_BUILDDIR)/mus_victory_league.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G029 -V080

$(MID_BUILDDIR)/mus_caught.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G025 -V080

$(MID_BUILDDIR)/mus_encounter_cool.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G063 -V086

$(MID_BUILDDIR)/mus_trick_house.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G094 -V070

$(MID_BUILDDIR)/mus_route113.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G064 -V084

$(MID_BUILDDIR)/mus_sailing.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G077 -V086

$(MID_BUILDDIR)/mus_mt_pyre.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G078 -V088

$(MID_BUILDDIR)/mus_sealed_chamber.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G084 -V100

$(MID_BUILDDIR)/mus_petalburg.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G015 -V080

$(MID_BUILDDIR)/mus_fortree.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G032 -V080

$(MID_BUILDDIR)/mus_oldale.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G019 -V080

$(MID_BUILDDIR)/mus_mt_pyre_exterior.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G080 -V080

$(MID_BUILDDIR)/mus_heal.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_slots_jackpot.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_slots_win.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_obtain_badge.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_obtain_berry.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_obtain_b_points.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G103 -V090 -P5

$(MID_BUILDDIR)/mus_rg_photo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G180 -V100 -P5

$(MID_BUILDDIR)/mus_evolution_intro.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G026 -V080

$(MID_BUILDDIR)/mus_obtain_symbol.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G103 -V100 -P5

$(MID_BUILDDIR)/mus_awaken_legend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_register_match_call.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G105 -V090 -P5

$(MID_BUILDDIR)/mus_move_deleted.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_obtain_tmhm.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_too_bad.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G012 -V090 -P5

$(MID_BUILDDIR)/mus_encounter_magma.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G087 -V072

$(MID_BUILDDIR)/mus_lilycove.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G054 -V085

$(MID_BUILDDIR)/mus_littleroot.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G051 -V100

$(MID_BUILDDIR)/mus_surf.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G017 -V080

$(MID_BUILDDIR)/mus_route104.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G047 -V097

$(MID_BUILDDIR)/mus_gsc_pewter.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_BUILDDIR)/mus_birch_lab.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G033 -V080

$(MID_BUILDDIR)/mus_abnormal_weather.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G089 -V080

$(MID_BUILDDIR)/mus_school.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G081 -V100

$(MID_BUILDDIR)/mus_c_comm_center.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_BUILDDIR)/mus_poke_center.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G046 -V092

$(MID_BUILDDIR)/mus_b_pyramid.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G106 -V079

$(MID_BUILDDIR)/mus_b_pyramid_top.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G107 -V077

$(MID_BUILDDIR)/mus_ever_grande.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G068 -V086

$(MID_BUILDDIR)/mus_rayquaza_appears.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G109 -V090

$(MID_BUILDDIR)/mus_rg_rocket_hideout.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G133 -V090

$(MID_BUILDDIR)/mus_rg_follow_me.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G131 -V068

$(MID_BUILDDIR)/mus_rg_victory_road.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G154 -V090

$(MID_BUILDDIR)/mus_rg_cycling.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G141 -V090

$(MID_BUILDDIR)/mus_rg_intro_fight.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G136 -V090

$(MID_BUILDDIR)/mus_rg_hall_of_fame.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G145 -V079

$(MID_BUILDDIR)/mus_rg_encounter_deoxys.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G184 -V079

$(MID_BUILDDIR)/mus_rg_credits.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G149 -V090

$(MID_BUILDDIR)/mus_rg_encounter_gym_leader.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G144 -V090

$(MID_BUILDDIR)/mus_rg_dex_rating.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G175 -V070 -P5

$(MID_BUILDDIR)/mus_rg_obtain_key_item.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G178 -V077 -P5

$(MID_BUILDDIR)/mus_rg_caught_intro.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G179 -V094 -P5

$(MID_BUILDDIR)/mus_rg_caught.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G170 -V100

$(MID_BUILDDIR)/mus_rg_cinnabar.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G138 -V090

$(MID_BUILDDIR)/mus_rg_gym.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G134 -V090

$(MID_BUILDDIR)/mus_rg_fuchsia.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G167 -V090

$(MID_BUILDDIR)/mus_rg_poke_jump.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G132 -V090

$(MID_BUILDDIR)/mus_rg_heal.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G140 -V090

$(MID_BUILDDIR)/mus_rg_oak_lab.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G160 -V075

$(MID_BUILDDIR)/mus_rg_berry_pick.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G132 -V090

$(MID_BUILDDIR)/mus_rg_vermillion.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G172 -V090

$(MID_BUILDDIR)/mus_rg_route1.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G150 -V079

$(MID_BUILDDIR)/mus_rg_route3.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G152 -V083

$(MID_BUILDDIR)/mus_rg_route11.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G153 -V090

$(MID_BUILDDIR)/mus_rg_pallet.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G159 -V100

$(MID_BUILDDIR)/mus_rg_surf.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G164 -V071

$(MID_BUILDDIR)/mus_rg_sevii_45.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G188 -V084

$(MID_BUILDDIR)/mus_rg_sevii_67.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G189 -V084

$(MID_BUILDDIR)/mus_rg_sevii_123.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G173 -V084

$(MID_BUILDDIR)/mus_rg_sevii_cave.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G147 -V090

$(MID_BUILDDIR)/mus_rg_sevii_dungeon.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G146 -V090

$(MID_BUILDDIR)/mus_rg_sevii_route.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G187 -V080

$(MID_BUILDDIR)/mus_rg_net_center.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G162 -V096

$(MID_BUILDDIR)/mus_rg_pewter.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G173 -V084

$(MID_BUILDDIR)/mus_rg_oak.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G161 -V086

$(MID_BUILDDIR)/mus_rg_mystery_gift.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G183 -V100

$(MID_BUILDDIR)/mus_rg_route24.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G151 -V086

$(MID_BUILDDIR)/mus_rg_teachy_tv_show.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G131 -V068

$(MID_BUILDDIR)/mus_rg_mt_moon.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G147 -V090

$(MID_BUILDDIR)/mus_rg_poke_tower.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G165 -V090

$(MID_BUILDDIR)/mus_rg_poke_center.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G162 -V096

$(MID_BUILDDIR)/mus_rg_poke_flute.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G165 -V048 -P5

$(MID_BUILDDIR)/mus_rg_poke_mansion.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G148 -V090

$(MID_BUILDDIR)/mus_rg_jigglypuff.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G135 -V068 -P5

$(MID_BUILDDIR)/mus_rg_encounter_rival.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G174 -V079

$(MID_BUILDDIR)/mus_rg_rival_exit.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G174 -V079

$(MID_BUILDDIR)/mus_rg_encounter_rocket.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G142 -V096

$(MID_BUILDDIR)/mus_rg_ss_anne.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G163 -V090

$(MID_BUILDDIR)/mus_rg_new_game_exit.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G182 -V088

$(MID_BUILDDIR)/mus_rg_new_game_intro.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G182 -V088

$(MID_BUILDDIR)/mus_rg_lavender.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G139 -V090

$(MID_BUILDDIR)/mus_rg_silph.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G166 -V076

$(MID_BUILDDIR)/mus_rg_encounter_girl.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G143 -V051

$(MID_BUILDDIR)/mus_rg_encounter_boy.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G144 -V090

$(MID_BUILDDIR)/mus_rg_game_corner.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G132 -V090

$(MID_BUILDDIR)/mus_rg_slow_pallet.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G159 -V092

$(MID_BUILDDIR)/mus_rg_new_game_instruct.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G182 -V085

$(MID_BUILDDIR)/mus_rg_viridian_forest.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G146 -V090

$(MID_BUILDDIR)/mus_rg_trainer_tower.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G134 -V090

$(MID_BUILDDIR)/mus_rg_celadon.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G168 -V070

$(MID_BUILDDIR)/mus_rg_title.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G137 -V090

$(MID_BUILDDIR)/mus_rg_game_freak.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G181 -V075

$(MID_BUILDDIR)/mus_rg_teachy_tv_menu.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G186 -V059

$(MID_BUILDDIR)/mus_rg_union_room.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G132 -V090

$(MID_BUILDDIR)/mus_rg_vs_legend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G157 -V090

$(MID_BUILDDIR)/mus_rg_vs_deoxys.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G185 -V080

$(MID_BUILDDIR)/mus_rg_vs_gym_leader.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G155 -V090

$(MID_BUILDDIR)/mus_rg_vs_champion.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G158 -V090

$(MID_BUILDDIR)/mus_rg_vs_mewtwo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G157 -V090

$(MID_BUILDDIR)/mus_rg_vs_trainer.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G156 -V090

$(MID_BUILDDIR)/mus_rg_vs_wild.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G157 -V090

$(MID_BUILDDIR)/mus_rg_victory_gym_leader.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G171 -V090

$(MID_BUILDDIR)/mus_rg_victory_trainer.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G169 -V089

$(MID_BUILDDIR)/mus_rg_victory_wild.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G170 -V090

$(MID_BUILDDIR)/mus_cable_car.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G071 -V078

$(MID_BUILDDIR)/mus_sootopolis.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G091 -V062

$(MID_BUILDDIR)/mus_safari_zone.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G074 -V082

$(MID_BUILDDIR)/mus_b_tower.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G110 -V100

$(MID_BUILDDIR)/mus_evolution.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G026 -V080

$(MID_BUILDDIR)/mus_encounter_elite_four.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G096 -V078

$(MID_BUILDDIR)/mus_c_vs_legend_beast.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -V080

$(MID_BUILDDIR)/mus_encounter_swimmer.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G036 -V080

$(MID_BUILDDIR)/mus_encounter_girl.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G027 -V080

$(MID_BUILDDIR)/mus_intro_battle.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G088 -V088

$(MID_BUILDDIR)/mus_encounter_rich.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G043 -V094

$(MID_BUILDDIR)/mus_link_contest_p1.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G039 -V079

$(MID_BUILDDIR)/mus_link_contest_p2.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G040 -V090

$(MID_BUILDDIR)/mus_link_contest_p3.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G041 -V075

$(MID_BUILDDIR)/mus_link_contest_p4.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G042 -V090

$(MID_BUILDDIR)/mus_littleroot_test.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G034 -V099

$(MID_BUILDDIR)/mus_credits.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G101 -V100

$(MID_BUILDDIR)/mus_title.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G059 -V090

$(MID_BUILDDIR)/mus_fallarbor.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G083 -V100

$(MID_BUILDDIR)/mus_mt_chimney.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G052 -V078

$(MID_BUILDDIR)/mus_follow_me.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G066 -V074

$(MID_BUILDDIR)/mus_vs_frontier_brain.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G115 -V090 -P1

$(MID_BUILDDIR)/mus_vs_mew.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G116 -V090

$(MID_BUILDDIR)/mus_vs_rayquaza.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G114 -V080 -P1

$(MID_BUILDDIR)/mus_encounter_hiker.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G097 -V076

$(MID_BUILDDIR)/ph_choice_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_choice_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_choice_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_cloth_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_cloth_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_cloth_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_cure_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_cure_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_cure_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_dress_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_dress_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_dress_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_face_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_face_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_face_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_fleece_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_fleece_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_fleece_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_foot_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_foot_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_foot_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_goat_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_goat_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_goat_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_goose_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_goose_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_goose_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_kit_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_kit_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_kit_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_lot_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_lot_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_lot_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_mouth_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_mouth_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_mouth_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_nurse_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_nurse_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_nurse_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_price_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_price_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_price_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_strut_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_strut_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_strut_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_thought_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_thought_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_thought_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_trap_blend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_trap_held.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/ph_trap_solo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -G130 -P4

$(MID_BUILDDIR)/se_a.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V095 -P4

$(MID_BUILDDIR)/se_bang.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_taillow_wing_flap.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P5

$(MID_BUILDDIR)/se_glass_flute.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P5

$(MID_BUILDDIR)/se_boo.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P4

$(MID_BUILDDIR)/se_ball.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V070 -P4

$(MID_BUILDDIR)/se_ball_open.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_BUILDDIR)/se_mugshot.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P5

$(MID_BUILDDIR)/se_contest_heart.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P5

$(MID_BUILDDIR)/se_contest_curtain_fall.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V070 -P5

$(MID_BUILDDIR)/se_contest_curtain_rise.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V070 -P5

$(MID_BUILDDIR)/se_contest_icon_change.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P5

$(MID_BUILDDIR)/se_contest_mons_turn.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P5

$(MID_BUILDDIR)/se_contest_icon_clear.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P5

$(MID_BUILDDIR)/se_card.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P4

$(MID_BUILDDIR)/se_pike_curtain_close.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_BUILDDIR)/se_pike_curtain_open.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_BUILDDIR)/se_ledge.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P4

$(MID_BUILDDIR)/se_itemfinder.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P5

$(MID_BUILDDIR)/se_applause.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P5

$(MID_BUILDDIR)/se_field_poison.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P5

$(MID_BUILDDIR)/se_door.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V080 -P5

$(MID_BUILDDIR)/se_e.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P4

$(MID_BUILDDIR)/se_elevator.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_BUILDDIR)/se_escalator.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_BUILDDIR)/se_exp.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V080 -P5

$(MID_BUILDDIR)/se_exp_max.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V094 -P5

$(MID_BUILDDIR)/se_fu_zaku.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V120 -P4

$(MID_BUILDDIR)/se_contest_condition_lose.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P4

$(MID_BUILDDIR)/se_lavaridge_fall_warp.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -P4

$(MID_BUILDDIR)/se_balloon_red.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P4

$(MID_BUILDDIR)/se_balloon_blue.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P4

$(MID_BUILDDIR)/se_balloon_yellow.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P4

$(MID_BUILDDIR)/se_arena_timeup1.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_BUILDDIR)/se_arena_timeup2.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_BUILDDIR)/se_bridge_walk.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V095 -P4

$(MID_BUILDDIR)/se_failure.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V120 -P4

$(MID_BUILDDIR)/se_rotating_gate.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_BUILDDIR)/se_low_health.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P3

$(MID_BUILDDIR)/se_i.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P4

$(MID_BUILDDIR)/se_sliding_door.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V095 -P4

$(MID_BUILDDIR)/se_vend.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_bike_hop.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P4

$(MID_BUILDDIR)/se_bike_bell.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_BUILDDIR)/se_contest_place.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P4

$(MID_BUILDDIR)/se_exit.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V120 -P5

$(MID_BUILDDIR)/se_use_item.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_BUILDDIR)/se_unlock.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_BUILDDIR)/se_ball_bounce_1.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_BUILDDIR)/se_ball_bounce_2.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_BUILDDIR)/se_ball_bounce_3.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_BUILDDIR)/se_ball_bounce_4.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_BUILDDIR)/se_super_effective.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P5

$(MID_BUILDDIR)/se_not_effective.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P5

$(MID_BUILDDIR)/se_effective.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P5

$(MID_BUILDDIR)/se_puddle.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V020 -P4

$(MID_BUILDDIR)/se_berry_blender.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_BUILDDIR)/se_switch.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P4

$(MID_BUILDDIR)/se_n.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -P4

$(MID_BUILDDIR)/se_ball_throw.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P5

$(MID_BUILDDIR)/se_ship.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V075 -P4

$(MID_BUILDDIR)/se_flee.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P5

$(MID_BUILDDIR)/se_o.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P4

$(MID_BUILDDIR)/se_intro_blast.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_BUILDDIR)/se_pc_login.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_BUILDDIR)/se_pc_off.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_BUILDDIR)/se_pc_on.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_BUILDDIR)/se_pin.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V060 -P4

$(MID_BUILDDIR)/se_ding_dong.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P5

$(MID_BUILDDIR)/se_pokenav_off.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_BUILDDIR)/se_pokenav_on.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_BUILDDIR)/se_faint.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P5

$(MID_BUILDDIR)/se_shiny.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V095 -P5

$(MID_BUILDDIR)/se_shop.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P5

$(MID_BUILDDIR)/se_rg_bag_cursor.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_BUILDDIR)/se_rg_bag_pocket.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_BUILDDIR)/se_rg_card_flip.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_BUILDDIR)/se_rg_card_flipping.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -P5

$(MID_BUILDDIR)/se_rg_card_open.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V112 -P5

$(MID_BUILDDIR)/se_rg_deoxys_move.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V080 -P5

$(MID_BUILDDIR)/se_rg_poke_jump_success.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P5

$(MID_BUILDDIR)/se_rg_ball_click.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V100 -P5

$(MID_BUILDDIR)/se_rg_help_close.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V095 -P5

$(MID_BUILDDIR)/se_rg_help_error.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V125 -P5

$(MID_BUILDDIR)/se_rg_help_open.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V096 -P5

$(MID_BUILDDIR)/se_rg_ss_anne_horn.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V096 -P5

$(MID_BUILDDIR)/se_rg_poke_jump_failure.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -P5

$(MID_BUILDDIR)/se_rg_shop.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V080 -P5

$(MID_BUILDDIR)/se_rg_door.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V100 -P5

$(MID_BUILDDIR)/se_ice_crack.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P4

$(MID_BUILDDIR)/se_ice_stairs.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_BUILDDIR)/se_ice_break.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_BUILDDIR)/se_fall.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_save.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V080 -P5

$(MID_BUILDDIR)/se_success.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V080 -P4

$(MID_BUILDDIR)/se_select.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V080 -P5

$(MID_BUILDDIR)/se_ball_trade.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_BUILDDIR)/se_thunderstorm.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V080 -P2

$(MID_BUILDDIR)/se_thunderstorm_stop.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V080 -P2

$(MID_BUILDDIR)/se_thunder.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P3

$(MID_BUILDDIR)/se_thunder2.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P3

$(MID_BUILDDIR)/se_rain.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V080 -P2

$(MID_BUILDDIR)/se_rain_stop.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V080 -P2

$(MID_BUILDDIR)/se_downpour.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P2

$(MID_BUILDDIR)/se_downpour_stop.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P2

$(MID_BUILDDIR)/se_orb.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P5

$(MID_BUILDDIR)/se_egg_hatch.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P5

$(MID_BUILDDIR)/se_roulette_ball.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P2

$(MID_BUILDDIR)/se_roulette_ball2.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P2

$(MID_BUILDDIR)/se_ball_tray_exit.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V100 -P5

$(MID_BUILDDIR)/se_ball_tray_ball.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P5

$(MID_BUILDDIR)/se_ball_tray_enter.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P5

$(MID_BUILDDIR)/se_click.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V110 -P4

$(MID_BUILDDIR)/se_warp_in.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P4

$(MID_BUILDDIR)/se_warp_out.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P4

$(MID_BUILDDIR)/se_pokenav_call.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V120 -P5

$(MID_BUILDDIR)/se_pokenav_hang_up.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V110 -P5

$(MID_BUILDDIR)/se_note_a.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_note_b.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_note_c.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_note_c_high.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_note_d.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_mud_ball.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_note_e.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_note_f.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_note_g.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_breakable_door.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_truck_door.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_truck_unload.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -P4

$(MID_BUILDDIR)/se_truck_move.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -P4

$(MID_BUILDDIR)/se_truck_stop.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -P4

$(MID_BUILDDIR)/se_repel.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -V090 -P4

$(MID_BUILDDIR)/se_u.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -P4

$(MID_BUILDDIR)/se_sudowoodo_shake.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G129 -V077 -P5

$(MID_BUILDDIR)/se_m_double_slap.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_comet_punch.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P4

$(MID_BUILDDIR)/se_m_pay_day.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V095 -P4

$(MID_BUILDDIR)/se_m_fire_punch.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_scratch.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_vicegrip.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_razor_wind.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_razor_wind2.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_BUILDDIR)/se_m_swords_dance.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_BUILDDIR)/se_m_cut.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V120 -P4

$(MID_BUILDDIR)/se_m_gust.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_gust2.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_wing_attack.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P4

$(MID_BUILDDIR)/se_m_fly.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_bind.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V100 -P4

$(MID_BUILDDIR)/se_m_mega_kick.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V090 -P4

$(MID_BUILDDIR)/se_m_mega_kick2.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_jump_kick.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_sand_attack.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_headbutt.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_horn_attack.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_take_down.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V105 -P4

$(MID_BUILDDIR)/se_m_tail_whip.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_m_leer.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G128 -V110 -P4

$(MID_BUILDDIR)/se_dex_search.s: $(MID_BUILDDIR)/%.s: $(MID_SUBDIR)/%.mid
	$(MID) $< $@ -E -R$(STD_REVERB) -G127 -v100 -P5
