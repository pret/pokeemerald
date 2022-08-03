TYPESGFXDIR := graphics/types

types := normal fight flying poison ground rock bug ghost steel mystery fire water grass electric psychic ice dragon dark
contest_types := cool beauty cute smart tough

$(TYPESGFXDIR)/move_types_fr.4bpp: $(types:%=$(TYPESGFXDIR)/%_fr.4bpp) $(contest_types:%=$(TYPESGFXDIR)/contest_%_fr.4bpp)
	@cat $^ >$@

$(TYPESGFXDIR)/move_types_fr.gbapal: $(TYPESGFXDIR)/move_types_1_fr.gbapal \
                                     $(TYPESGFXDIR)/move_types_2_fr.gbapal \
                                     $(TYPESGFXDIR)/move_types_3_fr.gbapal
	@cat $^ >$@