# These rules catch most assets - some exceptions
%.s: ;
%.png: ;
%.pal: ;
%.aif: ;

$(BUILD_ASSETS_DIR)/%.1bpp: %.png
	@mkdir -p $(@D)
	$(GFX) $< $@
$(BUILD_ASSETS_DIR)/%.4bpp: %.png
	@mkdir -p $(@D)
	$(GFX) $< $@
$(BUILD_ASSETS_DIR)/%.8bpp: %.png
	@mkdir -p $(@D)
	$(GFX) $< $@
$(BUILD_ASSETS_DIR)/%.gbapal: %.pal
	@mkdir -p $(@D)
	$(GFX) $< $@
# Derives the palette from the image in the absence of a .pal file
$(BUILD_ASSETS_DIR)/%.gbapal: %.png
	@mkdir -p $(@D)
	$(GFX) $< $@

# If you put `.lz` on the end of a filename when using INCBIN it'll be automatically compressed.
$(BUILD_ASSETS_DIR)/%.lz: $(BUILD_ASSETS_DIR)/%
	$(GFX) $< $@
$(BUILD_ASSETS_DIR)/%.rl: $(BUILD_ASSETS_DIR)/%
	$(GFX) $< $@
$(BUILD_ASSETS_DIR)/%.lz: %
	@mkdir -p $(@D)
	$(GFX) $< $@
$(BUILD_ASSETS_DIR)/%.rl: %
	@mkdir -p $(@D)
	$(GFX) $< $@

# Legacy make rules for easy porting
%.1bpp: %.png
	$(GFX) $< $@
%.4bpp: %.png
	$(GFX) $< $@
%.8bpp: %.png
	$(GFX) $< $@
%.gbapal: %.pal
	$(GFX) $< $@
%.gbapal: %.png
	$(GFX) $< $@
%.lz: %
	$(GFX) $< $@
%.rl: %
	$(GFX) $< $@