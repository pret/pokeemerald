# This file contains numerous rules for graphics files (specifically spritesheets) that require special behaviour when compiling.

OBJEVENTGFXDIR := graphics/object_events/pics
FLDEFFGFXDIR := graphics/field_effects/pics

# Output folders
OBJEVENT_OUTDIR    := $(BUILD_ASSETS_DIR)/$(OBJEVENTGFXDIR)
FLDEFF_OUTDIR      := $(BUILD_ASSETS_DIR)/$(FLDEFFGFXDIR)

$(OBJEVENT_OUTDIR)/people/brendan/walking.4bpp: $(OBJEVENTGFXDIR)/people/brendan/walking.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/brendan/running.4bpp: $(OBJEVENTGFXDIR)/people/brendan/running.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/brendan/field_move.4bpp: $(OBJEVENTGFXDIR)/people/brendan/field_move.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/brendan/surfing.4bpp: $(OBJEVENTGFXDIR)/people/brendan/surfing.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/brendan/mach_bike.4bpp: $(OBJEVENTGFXDIR)/people/brendan/mach_bike.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/brendan/acro_bike.4bpp: $(OBJEVENTGFXDIR)/people/brendan/acro_bike.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/brendan/fishing.4bpp: $(OBJEVENTGFXDIR)/people/brendan/fishing.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/brendan/watering.4bpp: $(OBJEVENTGFXDIR)/people/brendan/watering.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/brendan/underwater.4bpp: $(OBJEVENTGFXDIR)/people/brendan/underwater.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4


$(OBJEVENT_OUTDIR)/people/elite_four/drake.4bpp: $(OBJEVENTGFXDIR)/people/elite_four/drake.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/elite_four/glacia.4bpp: $(OBJEVENTGFXDIR)/people/elite_four/glacia.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/elite_four/phoebe.4bpp: $(OBJEVENTGFXDIR)/people/elite_four/phoebe.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/elite_four/sidney.4bpp: $(OBJEVENTGFXDIR)/people/elite_four/sidney.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4


$(OBJEVENT_OUTDIR)/people/frontier_brains/anabel.4bpp: $(OBJEVENTGFXDIR)/people/frontier_brains/anabel.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/frontier_brains/brandon.4bpp: $(OBJEVENTGFXDIR)/people/frontier_brains/brandon.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/frontier_brains/greta.4bpp: $(OBJEVENTGFXDIR)/people/frontier_brains/greta.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/frontier_brains/lucy.4bpp: $(OBJEVENTGFXDIR)/people/frontier_brains/lucy.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/frontier_brains/noland.4bpp: $(OBJEVENTGFXDIR)/people/frontier_brains/noland.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/frontier_brains/spenser.4bpp: $(OBJEVENTGFXDIR)/people/frontier_brains/spenser.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/frontier_brains/tucker.4bpp: $(OBJEVENTGFXDIR)/people/frontier_brains/tucker.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4


$(OBJEVENT_OUTDIR)/people/gym_leaders/brawly.4bpp: $(OBJEVENTGFXDIR)/people/gym_leaders/brawly.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/gym_leaders/flannery.4bpp: $(OBJEVENTGFXDIR)/people/gym_leaders/flannery.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/gym_leaders/juan.4bpp: $(OBJEVENTGFXDIR)/people/gym_leaders/juan.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/gym_leaders/liza.4bpp: $(OBJEVENTGFXDIR)/people/gym_leaders/liza.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/gym_leaders/norman.4bpp: $(OBJEVENTGFXDIR)/people/gym_leaders/norman.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/gym_leaders/roxanne.4bpp: $(OBJEVENTGFXDIR)/people/gym_leaders/roxanne.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/gym_leaders/tate.4bpp: $(OBJEVENTGFXDIR)/people/gym_leaders/tate.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/gym_leaders/wattson.4bpp: $(OBJEVENTGFXDIR)/people/gym_leaders/wattson.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/gym_leaders/winona.4bpp: $(OBJEVENTGFXDIR)/people/gym_leaders/winona.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4


$(OBJEVENT_OUTDIR)/people/may/walking.4bpp: $(OBJEVENTGFXDIR)/people/may/walking.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/may/running.4bpp: $(OBJEVENTGFXDIR)/people/may/running.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/may/field_move.4bpp: $(OBJEVENTGFXDIR)/people/may/field_move.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/may/surfing.4bpp: $(OBJEVENTGFXDIR)/people/may/surfing.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/may/mach_bike.4bpp: $(OBJEVENTGFXDIR)/people/may/mach_bike.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/may/acro_bike.4bpp: $(OBJEVENTGFXDIR)/people/may/acro_bike.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/may/fishing.4bpp: $(OBJEVENTGFXDIR)/people/may/fishing.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/may/watering.4bpp: $(OBJEVENTGFXDIR)/people/may/watering.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/may/underwater.4bpp: $(OBJEVENTGFXDIR)/people/may/underwater.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4


$(OBJEVENT_OUTDIR)/people/ruby_sapphire_brendan/walking.4bpp: $(OBJEVENTGFXDIR)/people/ruby_sapphire_brendan/walking.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/ruby_sapphire_brendan/running.4bpp: $(OBJEVENTGFXDIR)/people/ruby_sapphire_brendan/running.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4


$(OBJEVENT_OUTDIR)/people/ruby_sapphire_may/walking.4bpp: $(OBJEVENTGFXDIR)/people/ruby_sapphire_may/walking.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/ruby_sapphire_may/running.4bpp: $(OBJEVENTGFXDIR)/people/ruby_sapphire_may/running.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4


$(OBJEVENT_OUTDIR)/people/team_aqua/aqua_member_f.4bpp: $(OBJEVENTGFXDIR)/people/team_aqua/aqua_member_f.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/team_aqua/aqua_member_m.4bpp: $(OBJEVENTGFXDIR)/people/team_aqua/aqua_member_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/team_aqua/archie.4bpp: $(OBJEVENTGFXDIR)/people/team_aqua/archie.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4


$(OBJEVENT_OUTDIR)/people/team_magma/magma_member_f.4bpp: $(OBJEVENTGFXDIR)/people/team_magma/magma_member_f.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/team_magma/magma_member_m.4bpp: $(OBJEVENTGFXDIR)/people/team_magma/magma_member_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/team_magma/maxie.4bpp: $(OBJEVENTGFXDIR)/people/team_magma/maxie.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4


$(OBJEVENT_OUTDIR)/people/artist.4bpp: $(OBJEVENTGFXDIR)/people/artist.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/beauty.4bpp: $(OBJEVENTGFXDIR)/people/beauty.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/black_belt.4bpp: $(OBJEVENTGFXDIR)/people/black_belt.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/boy_1.4bpp: $(OBJEVENTGFXDIR)/people/boy_1.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/boy_2.4bpp: $(OBJEVENTGFXDIR)/people/boy_2.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/boy_3.4bpp: $(OBJEVENTGFXDIR)/people/boy_3.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/rich_boy.4bpp: $(OBJEVENTGFXDIR)/people/rich_boy.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/gameboy_kid.4bpp: $(OBJEVENTGFXDIR)/people/gameboy_kid.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/bug_catcher.4bpp: $(OBJEVENTGFXDIR)/people/bug_catcher.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/cameraman.4bpp: $(OBJEVENTGFXDIR)/people/cameraman.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/camper.4bpp: $(OBJEVENTGFXDIR)/people/camper.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/contest_judge.4bpp: $(OBJEVENTGFXDIR)/people/contest_judge.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/cook.4bpp: $(OBJEVENTGFXDIR)/people/cook.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/cycling_triathlete_f.4bpp: $(OBJEVENTGFXDIR)/people/cycling_triathlete_f.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/cycling_triathlete_m.4bpp: $(OBJEVENTGFXDIR)/people/cycling_triathlete_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/fat_man.4bpp: $(OBJEVENTGFXDIR)/people/fat_man.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/fisherman.4bpp: $(OBJEVENTGFXDIR)/people/fisherman.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/gentleman.4bpp: $(OBJEVENTGFXDIR)/people/gentleman.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/girl_1.4bpp: $(OBJEVENTGFXDIR)/people/girl_1.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/girl_2.4bpp: $(OBJEVENTGFXDIR)/people/girl_2.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/girl_3.4bpp: $(OBJEVENTGFXDIR)/people/girl_3.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/hex_maniac.4bpp: $(OBJEVENTGFXDIR)/people/hex_maniac.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/hiker.4bpp: $(OBJEVENTGFXDIR)/people/hiker.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/hot_springs_old_woman.4bpp: $(OBJEVENTGFXDIR)/people/hot_springs_old_woman.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/lass.4bpp: $(OBJEVENTGFXDIR)/people/lass.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/leaf.4bpp: $(OBJEVENTGFXDIR)/people/leaf.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/ninja_boy.4bpp: $(OBJEVENTGFXDIR)/people/ninja_boy.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/people/little_boy.4bpp: $(OBJEVENTGFXDIR)/people/little_boy.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/people/twin.4bpp: $(OBJEVENTGFXDIR)/people/twin.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/little_girl.4bpp: $(OBJEVENTGFXDIR)/people/little_girl.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/people/man_1.4bpp: $(OBJEVENTGFXDIR)/people/man_1.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/man_2.4bpp: $(OBJEVENTGFXDIR)/people/man_2.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/pokefan_m.4bpp: $(OBJEVENTGFXDIR)/people/pokefan_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/man_3.4bpp: $(OBJEVENTGFXDIR)/people/man_3.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/man_4.4bpp: $(OBJEVENTGFXDIR)/people/man_4.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/man_5.4bpp: $(OBJEVENTGFXDIR)/people/man_5.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/devon_employee.4bpp: $(OBJEVENTGFXDIR)/people/devon_employee.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/maniac.4bpp: $(OBJEVENTGFXDIR)/people/maniac.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/mart_employee.4bpp: $(OBJEVENTGFXDIR)/people/mart_employee.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/mauville_old_man_1.4bpp: $(OBJEVENTGFXDIR)/people/mauville_old_man_1.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/mauville_old_man_2.4bpp: $(OBJEVENTGFXDIR)/people/mauville_old_man_2.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/mom.4bpp: $(OBJEVENTGFXDIR)/people/mom.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/mystery_event_deliveryman.4bpp: $(OBJEVENTGFXDIR)/people/mystery_event_deliveryman.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/nurse.4bpp: $(OBJEVENTGFXDIR)/people/nurse.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/expert_m.4bpp: $(OBJEVENTGFXDIR)/people/expert_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/old_man.4bpp: $(OBJEVENTGFXDIR)/people/old_man.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/expert_f.4bpp: $(OBJEVENTGFXDIR)/people/expert_f.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/old_woman.4bpp: $(OBJEVENTGFXDIR)/people/old_woman.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/picnicker.4bpp: $(OBJEVENTGFXDIR)/people/picnicker.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/prof_birch.4bpp: $(OBJEVENTGFXDIR)/people/prof_birch.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/psychic_m.4bpp: $(OBJEVENTGFXDIR)/people/psychic_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/quinty_plump.4bpp: $(OBJEVENTGFXDIR)/people/quinty_plump.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/people/red.4bpp: $(OBJEVENTGFXDIR)/people/red.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/reporter_f.4bpp: $(OBJEVENTGFXDIR)/people/reporter_f.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/reporter_m.4bpp: $(OBJEVENTGFXDIR)/people/reporter_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/rooftop_sale_woman.4bpp: $(OBJEVENTGFXDIR)/people/rooftop_sale_woman.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/rs_little_boy.4bpp: $(OBJEVENTGFXDIR)/people/rs_little_boy.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/people/running_triathlete_f.4bpp: $(OBJEVENTGFXDIR)/people/running_triathlete_f.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/running_triathlete_m.4bpp: $(OBJEVENTGFXDIR)/people/running_triathlete_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/sailor.4bpp: $(OBJEVENTGFXDIR)/people/sailor.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/school_kid_m.4bpp: $(OBJEVENTGFXDIR)/people/school_kid_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/scientist_1.4bpp: $(OBJEVENTGFXDIR)/people/scientist_1.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/scientist_2.4bpp: $(OBJEVENTGFXDIR)/people/scientist_2.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/scott.4bpp: $(OBJEVENTGFXDIR)/people/scott.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/steven.4bpp: $(OBJEVENTGFXDIR)/people/steven.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/swimmer_f.4bpp: $(OBJEVENTGFXDIR)/people/swimmer_f.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/swimmer_m.4bpp: $(OBJEVENTGFXDIR)/people/swimmer_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/teala.4bpp: $(OBJEVENTGFXDIR)/people/teala.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/tuber_f.4bpp: $(OBJEVENTGFXDIR)/people/tuber_f.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/people/tuber_m.4bpp: $(OBJEVENTGFXDIR)/people/tuber_m.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/people/tuber_m_swimming.4bpp: $(OBJEVENTGFXDIR)/people/tuber_m_swimming.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/people/union_room_attendant.4bpp: $(OBJEVENTGFXDIR)/people/union_room_attendant.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/unused_woman.4bpp: $(OBJEVENTGFXDIR)/people/unused_woman.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/wallace.4bpp: $(OBJEVENTGFXDIR)/people/wallace.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/wally.4bpp: $(OBJEVENTGFXDIR)/people/wally.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/woman_1.4bpp: $(OBJEVENTGFXDIR)/people/woman_1.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/pokefan_f.4bpp: $(OBJEVENTGFXDIR)/people/pokefan_f.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/woman_2.4bpp: $(OBJEVENTGFXDIR)/people/woman_2.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/woman_3.4bpp: $(OBJEVENTGFXDIR)/people/woman_3.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/woman_4.4bpp: $(OBJEVENTGFXDIR)/people/woman_4.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/link_receptionist.4bpp: $(OBJEVENTGFXDIR)/people/link_receptionist.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/woman_5.4bpp: $(OBJEVENTGFXDIR)/people/woman_5.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/people/youngster.4bpp: $(OBJEVENTGFXDIR)/people/youngster.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4



$(OBJEVENT_OUTDIR)/pokemon/azumarill.4bpp: $(OBJEVENTGFXDIR)/pokemon/azumarill.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/pokemon/azurill.4bpp: $(OBJEVENTGFXDIR)/pokemon/azurill.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/pokemon/deoxys.4bpp: $(OBJEVENTGFXDIR)/pokemon/deoxys.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/dusclops.4bpp: $(OBJEVENTGFXDIR)/pokemon/dusclops.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/enemy_zigzagoon.4bpp: $(OBJEVENTGFXDIR)/pokemon/enemy_zigzagoon.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/groudon.4bpp: $(OBJEVENTGFXDIR)/pokemon/groudon.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/ho_oh.4bpp: $(OBJEVENTGFXDIR)/pokemon/ho_oh.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/kecleon.4bpp: $(OBJEVENTGFXDIR)/pokemon/kecleon.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/pokemon/kirlia.4bpp: $(OBJEVENTGFXDIR)/pokemon/kirlia.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/kyogre.4bpp: $(OBJEVENTGFXDIR)/pokemon/kyogre.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/latias_latios.4bpp: $(OBJEVENTGFXDIR)/pokemon/latias_latios.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/lugia.4bpp: $(OBJEVENTGFXDIR)/pokemon/lugia.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/mew.4bpp: $(OBJEVENTGFXDIR)/pokemon/mew.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/pikachu.4bpp: $(OBJEVENTGFXDIR)/pokemon/pikachu.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/pokemon/poochyena.4bpp: $(OBJEVENTGFXDIR)/pokemon/poochyena.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/rayquaza.4bpp: $(OBJEVENTGFXDIR)/pokemon/rayquaza.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 8 -mheight 8

$(OBJEVENT_OUTDIR)/pokemon/skitty.4bpp: $(OBJEVENTGFXDIR)/pokemon/skitty.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/pokemon/sudowoodo.4bpp: $(OBJEVENTGFXDIR)/pokemon/sudowoodo.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/vigoroth.4bpp: $(OBJEVENTGFXDIR)/pokemon/vigoroth.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(OBJEVENT_OUTDIR)/pokemon/wingull.4bpp: $(OBJEVENTGFXDIR)/pokemon/wingull.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/pokemon/zigzagoon.4bpp: $(OBJEVENTGFXDIR)/pokemon/zigzagoon.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2



$(OBJEVENT_OUTDIR)/berry_trees/aguav.4bpp: $(OBJEVENTGFXDIR)/berry_trees/aguav.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/aspear.4bpp: $(OBJEVENTGFXDIR)/berry_trees/aspear.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/cheri.4bpp: $(OBJEVENTGFXDIR)/berry_trees/cheri.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/chesto.4bpp: $(OBJEVENTGFXDIR)/berry_trees/chesto.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/cornn.4bpp: $(OBJEVENTGFXDIR)/berry_trees/cornn.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/durin.4bpp: $(OBJEVENTGFXDIR)/berry_trees/durin.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/figy.4bpp: $(OBJEVENTGFXDIR)/berry_trees/figy.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/grepa.4bpp: $(OBJEVENTGFXDIR)/berry_trees/grepa.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/hondew.4bpp: $(OBJEVENTGFXDIR)/berry_trees/hondew.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/iapapa.4bpp: $(OBJEVENTGFXDIR)/berry_trees/iapapa.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/kelpsy.4bpp: $(OBJEVENTGFXDIR)/berry_trees/kelpsy.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/lansat.4bpp: $(OBJEVENTGFXDIR)/berry_trees/lansat.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/leppa.4bpp: $(OBJEVENTGFXDIR)/berry_trees/leppa.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/liechi.4bpp: $(OBJEVENTGFXDIR)/berry_trees/liechi.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/lum.4bpp: $(OBJEVENTGFXDIR)/berry_trees/lum.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/mago.4bpp: $(OBJEVENTGFXDIR)/berry_trees/mago.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/nomel.4bpp: $(OBJEVENTGFXDIR)/berry_trees/nomel.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/oran.4bpp: $(OBJEVENTGFXDIR)/berry_trees/oran.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/pamtre.4bpp: $(OBJEVENTGFXDIR)/berry_trees/pamtre.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/pecha.4bpp: $(OBJEVENTGFXDIR)/berry_trees/pecha.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/persim.4bpp: $(OBJEVENTGFXDIR)/berry_trees/persim.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/pomeg.4bpp: $(OBJEVENTGFXDIR)/berry_trees/pomeg.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/rabuta.4bpp: $(OBJEVENTGFXDIR)/berry_trees/rabuta.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/rawst.4bpp: $(OBJEVENTGFXDIR)/berry_trees/rawst.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/razz.4bpp: $(OBJEVENTGFXDIR)/berry_trees/razz.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/sitrus.4bpp: $(OBJEVENTGFXDIR)/berry_trees/sitrus.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/spelon.4bpp: $(OBJEVENTGFXDIR)/berry_trees/spelon.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/sprout.4bpp: $(OBJEVENTGFXDIR)/berry_trees/sprout.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/berry_trees/tamato.4bpp: $(OBJEVENTGFXDIR)/berry_trees/tamato.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/wepear.4bpp: $(OBJEVENTGFXDIR)/berry_trees/wepear.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENT_OUTDIR)/berry_trees/wiki.4bpp: $(OBJEVENTGFXDIR)/berry_trees/wiki.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4



$(OBJEVENT_OUTDIR)/misc/breakable_rock.4bpp: $(OBJEVENTGFXDIR)/misc/breakable_rock.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/misc/cuttable_tree.4bpp: $(OBJEVENTGFXDIR)/misc/cuttable_tree.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(OBJEVENT_OUTDIR)/misc/mr_brineys_boat.4bpp: $(OBJEVENTGFXDIR)/misc/mr_brineys_boat.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4



$(FLDEFF_OUTDIR)/arrow.4bpp: $(FLDEFFGFXDIR)/arrow.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/ash.4bpp: $(FLDEFFGFXDIR)/ash.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/sparkle.4bpp: $(FLDEFFGFXDIR)/sparkle.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/jump_big_splash.4bpp: $(FLDEFFGFXDIR)/jump_big_splash.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/jump_small_splash.4bpp: $(FLDEFFGFXDIR)/jump_small_splash.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 1

$(FLDEFF_OUTDIR)/jump_tall_grass.4bpp: $(FLDEFFGFXDIR)/jump_tall_grass.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 1

$(FLDEFF_OUTDIR)/bike_tire_tracks.4bpp: $(FLDEFFGFXDIR)/bike_tire_tracks.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/bubbles.4bpp: $(FLDEFFGFXDIR)/bubbles.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(FLDEFF_OUTDIR)/deep_sand_footprints.4bpp: $(FLDEFFGFXDIR)/deep_sand_footprints.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/ground_impact_dust.4bpp: $(FLDEFFGFXDIR)/ground_impact_dust.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 1

$(FLDEFF_OUTDIR)/ash_puff.4bpp: $(FLDEFFGFXDIR)/ash_puff.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/long_grass.4bpp: $(FLDEFFGFXDIR)/long_grass.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/mountain_disguise.4bpp: $(FLDEFFGFXDIR)/mountain_disguise.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(FLDEFF_OUTDIR)/ripple.4bpp: $(FLDEFFGFXDIR)/ripple.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/sand_disguise_placeholder.4bpp: $(FLDEFFGFXDIR)/sand_disguise_placeholder.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(FLDEFF_OUTDIR)/sand_footprints.4bpp: $(FLDEFFGFXDIR)/sand_footprints.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/short_grass.4bpp: $(FLDEFFGFXDIR)/short_grass.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/surf_blob.4bpp: $(FLDEFFGFXDIR)/surf_blob.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 4

$(FLDEFF_OUTDIR)/tall_grass.4bpp: $(FLDEFFGFXDIR)/tall_grass.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/tree_disguise.4bpp: $(FLDEFFGFXDIR)/tree_disguise.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(FLDEFF_OUTDIR)/jump_long_grass.4bpp: $(FLDEFFGFXDIR)/jump_long_grass.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/unknown_17.4bpp: $(FLDEFFGFXDIR)/unknown_17.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/unused_grass_2.4bpp: $(FLDEFFGFXDIR)/unused_grass_2.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/unused_sand.4bpp: $(FLDEFFGFXDIR)/unused_sand.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/water_surfacing.4bpp: $(FLDEFFGFXDIR)/water_surfacing.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/sand_pile.4bpp: $(FLDEFFGFXDIR)/sand_pile.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 1

$(FLDEFF_OUTDIR)/ash_launch.4bpp: $(FLDEFFGFXDIR)/ash_launch.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/small_sparkle.4bpp: $(FLDEFFGFXDIR)/small_sparkle.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/unused_grass_3.4bpp: $(FLDEFFGFXDIR)/unused_grass_3.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/secret_power_cave.4bpp: $(FLDEFFGFXDIR)/secret_power_cave.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/secret_power_shrub.4bpp: $(FLDEFFGFXDIR)/secret_power_shrub.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/secret_power_tree.4bpp: $(FLDEFFGFXDIR)/secret_power_tree.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 2

$(FLDEFF_OUTDIR)/record_mix_lights.4bpp: $(FLDEFFGFXDIR)/record_mix_lights.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 4 -mheight 1

$(BUILD_ASSETS_DIR)/graphics/door_anims/battle_tower_multi_corridor.4bpp: graphics/door_anims/battle_tower_multi_corridor.png
	@mkdir -p $(@D)
	$(GFX) $< $@ -mwidth 2 -mheight 4
