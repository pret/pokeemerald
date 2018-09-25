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

$(MID_SUBDIR)/mus_naminori.s: %.s: %.mid
	$(MID) $< $@ -G017 -R$(STD_REVERB)

$(MID_SUBDIR)/mus_ropeway.s: %.s: %.mid
	$(MID) $< $@ -G071 -R$(STD_REVERB) -V078
