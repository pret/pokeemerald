# These rules catch most assets - some exceptions
%.s: ;
%.png: ;
%.pal: ;
%.aif: ;

%.1bpp: %.png
	@mkdir -p $(@D)
	$(GFX) $< $@
%.4bpp: %.png
	@mkdir -p $(@D)
	$(GFX) $< $@
%.8bpp: %.png
	@mkdir -p $(@D)
	$(GFX) $< $@
%.gbapal: %.pal
	@mkdir -p $(@D)
	$(GFX) $< $@
# Derives the palette from the image in the absence of a .pal file
%.gbapal: %.png
	@mkdir -p $(@D)
	$(GFX) $< $@

# If you put `.lz` on the end of a filename when using INCBIN it'll be automatically compressed.
$(BUILD_ASSETS_DIR)/%.lz: $(BUILD_ASSETS_DIR)/%
	$(GFX) $< $@
$(BUILD_ASSETS_DIR)/%.rl: $(BUILD_ASSETS_DIR)/%
	$(GFX) $< $@
%.lz: %
	$(GFX) $< $@
%.rl: %
	$(GFX) $< $@