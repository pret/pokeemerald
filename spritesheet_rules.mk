OBJEVENTGFXDIR := graphics/object_events/pics

$(OBJEVENTGFXDIR)/people/brendan/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/brendan/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/may/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/may/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_brendan/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_brendan/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_may/walking.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4

$(OBJEVENTGFXDIR)/people/ruby_sapphire_may/running.4bpp: %.4bpp: %.png
	$(GFX) $< $@ -mwidth 2 -mheight 4
