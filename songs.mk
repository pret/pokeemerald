STD_REVERB = 50

$(MID_BUILDDIR)/%.o: $(MID_SUBDIR)/%.s
	$(AS) $(ASFLAGS) -I sound -o $@ $<

$(MID_SUBDIR)/mus_ajito.s: %.s: %.mid
	$(MID) $< $@ -G076 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_aqa_0.s: %.s: %.mid
	$(MID) $< $@ -G065 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_ashroad.s: %.s: %.mid
	$(MID) $< $@ -G055 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_ayasii.s: %.s: %.mid
	$(MID) $< $@ -G069 -R$(STD_REVERB) -V078

$(MID_SUBDIR)/mus_b_arena.s: %.s: %.mid
	$(MID) $< $@ -G104 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_b_dome.s: %.s: %.mid
	$(MID) $< $@ -G111 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_b_dome1.s: %.s: %.mid
	$(MID) $< $@ -G111 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_b_frontier.s: %.s: %.mid
	$(MID) $< $@ -G103 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_b_factory.s: %.s: %.mid
	$(MID) $< $@ -G113 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_b_palace.s: %.s: %.mid
	$(MID) $< $@ -G108 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_b_tower.s: %.s: %.mid
	$(MID) $< $@ -G035 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_b_tube.s: %.s: %.mid
	$(MID) $< $@ -G112 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_battle20.s: %.s: %.mid
	$(MID) $< $@ -G119 -R$(STD_REVERB) -P1

$(MID_SUBDIR)/mus_battle27.s: %.s: %.mid
	$(MID) $< $@ -G117 -R$(STD_REVERB) -P1

$(MID_SUBDIR)/mus_battle30.s: %.s: %.mid
	$(MID) $< $@ -G126 -R$(STD_REVERB) -P1

$(MID_SUBDIR)/mus_battle31.s: %.s: %.mid
	$(MID) $< $@ -G118 -R$(STD_REVERB) -P1

$(MID_SUBDIR)/mus_battle32.s: %.s: %.mid
	$(MID) $< $@ -G120 -R$(STD_REVERB) -P1

$(MID_SUBDIR)/mus_battle33.s: %.s: %.mid
	$(MID) $< $@ -G121 -R$(STD_REVERB) -P1

$(MID_SUBDIR)/mus_battle34.s: %.s: %.mid
	$(MID) $< $@ -G123 -R$(STD_REVERB) -P1

$(MID_SUBDIR)/mus_battle35.s: %.s: %.mid
	$(MID) $< $@ -G124 -R$(STD_REVERB) -P1

$(MID_SUBDIR)/mus_battle36.s: %.s: %.mid
	$(MID) $< $@ -G122 -R$(STD_REVERB) -P1

$(MID_SUBDIR)/mus_battle38.s: %.s: %.mid
	$(MID) $< $@ -G125 -R$(STD_REVERB) -P1

$(MID_SUBDIR)/mus_bd_time.s: %.s: %.mid
	$(MID) $< $@ -G038 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_bijyutu.s: %.s: %.mid
	$(MID) $< $@ -G020 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_boy_sup.s: %.s: %.mid
	$(MID) $< $@ -G067 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_boyeye.s: %.s: %.mid
	$(MID) $< $@ -G028 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_c_road.s: %.s: %.mid
	$(MID) $< $@ -G075 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_casino.s: %.s: %.mid
	$(MID) $< $@ -G072 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_con_fan.s: %.s: %.mid
	$(MID) $< $@ -G085 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_con_k.s: %.s: %.mid
	$(MID) $< $@ -G092 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_conlobby.s: %.s: %.mid
	$(MID) $< $@ -G098 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_contest0.s: %.s: %.mid
	$(MID) $< $@ -G086 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_cycling.s: %.s: %.mid
	$(MID) $< $@ -G049 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_dan01.s: %.s: %.mid
	$(MID) $< $@ -G018 -R$(STD_REVERB) -V080 -E

$(MID_SUBDIR)/mus_dan02.s: %.s: %.mid
	$(MID) $< $@ -G030 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_dan03.s: %.s: %.mid
	$(MID) $< $@ -G037 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_deepdeep.s: %.s: %.mid
	$(MID) $< $@ -G057 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_demo1.s: %.s: %.mid
	$(MID) $< $@ -G060 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_daigo.s: %.s: %.mid
	$(MID) $< $@ -G100 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_dendou.s: %.s: %.mid
	$(MID) $< $@ -G082 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_dooro_x1.s: %.s: %.mid
	$(MID) $< $@ -G010 -R$(STD_REVERB) -V080

$(MID_SUBDIR)/mus_dooro_x3.s: %.s: %.mid
	$(MID) $< $@ -G014 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_dooro_x4.s: %.s: %.mid
	$(MID) $< $@ -G021 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_dooro1.s: %.s: %.mid
	$(MID) $< $@ -G011 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_dummy.s: %.s: %.mid
	$(MID) $< $@ -R40

$(MID_SUBDIR)/mus_eikou_r.s: %.s: %.mid
	$(MID) $< $@ -G093 -R$(STD_REVERB) -V080

$(MID_SUBDIR)/mus_end.s: %.s: %.mid
	$(MID) $< $@ -G102 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_event0.s: %.s: %.mid
	$(MID) $< $@ -G056 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_fanfa1.s: %.s: %.mid
	$(MID) $< $@ -G012 -R$(STD_REVERB) -P5

$(MID_SUBDIR)/mus_fanfa4.s: %.s: %.mid
	$(MID) $< $@ -G012 -R$(STD_REVERB) -P5

$(MID_SUBDIR)/mus_fanfa5.s: %.s: %.mid
	$(MID) $< $@ -G012 -R$(STD_REVERB) -P5

$(MID_SUBDIR)/mus_field13.s: %.s: %.mid
	$(MID) $< $@ -G000 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_finecity.s: %.s: %.mid
	$(MID) $< $@ -G079 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_friendly.s: %.s: %.mid
	$(MID) $< $@ -G050 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_fune_kan.s: %.s: %.mid
	$(MID) $< $@ -G023 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_gim.s: %.s: %.mid
	$(MID) $< $@ -G013 -R$(STD_REVERB) -V080

$(MID_SUBDIR)/mus_girl_sup.s: %.s: %.mid
	$(MID) $< $@ -G061 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_girleye.s: %.s: %.mid
	$(MID) $< $@ -G053 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_gomachi0.s: %.s: %.mid
	$(MID) $< $@ -G044 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_naminori.s: %.s: %.mid
	$(MID) $< $@ -G017 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_ropeway.s: %.s: %.mid
	$(MID) $< $@ -G071 -R$(STD_REVERB) -V078

$(MID_SUBDIR)/se_z_search.s: %.s: %.mid
	$(MID) $< $@ -G127 -R$(STD_REVERB) -P5
