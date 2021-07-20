	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gFont8LatinGlyphs::
	.incbin "graphics/fonts/font8.latfont"

	.align 2
gFont8LatinGlyphWidths::
	.include "graphics/fonts/font8_latin_widths.inc"

	.align 2
gFont0LatinGlyphs::
	.incbin "graphics/fonts/font0.latfont"

	.align 2
gFont0LatinGlyphWidths::
	.include "graphics/fonts/font0_latin_widths.inc"

	.align 2
gFont7LatinGlyphs::
	.incbin "graphics/fonts/font7.latfont"

	.align 2
gFont7LatinGlyphWidths::
	.include "graphics/fonts/font7_latin_widths.inc"

	.align 2
gFont2LatinGlyphs::
	.incbin "graphics/fonts/font2.latfont"

	.align 2
gFont2LatinGlyphWidths::
	.include "graphics/fonts/font2_latin_widths.inc"

	.align 2
gFont1LatinGlyphs::
	.incbin "graphics/fonts/font1.latfont"

	.align 2
gFont1LatinGlyphWidths::
	.include "graphics/fonts/font1_latin_widths.inc"

	.align 2
gFont0JapaneseGlyphs::
	.incbin "graphics/fonts/font0.hwjpnfont"

	.align 2
gFont1JapaneseGlyphs::
	.incbin "graphics/fonts/font1.hwjpnfont"

	.align 2
gUnusedJapaneseFireRedLeafGreenMaleFontGlyphs::
	.incbin "graphics/fonts/unused_frlg_male.fwjpnfont"

	.align 2
gUnusedJapaneseFireRedLeafGreenMaleFontGlyphWidths::
	.include "graphics/fonts/unused_japanese_frlg_male_font_widths.inc"

	.align 2
gUnusedJapaneseFireRedLeafGreenFemaleFontGlyphs::
	.incbin "graphics/fonts/unused_frlg_female.fwjpnfont"

	.align 2
gUnusedJapaneseFireRedLeafGreenFemaleFontGlyphWidths::
	.include "graphics/fonts/unused_japanese_frlg_female_font_widths.inc"

	.align 2
gFont2JapaneseGlyphs::
	.incbin "graphics/fonts/font2.fwjpnfont"

	.align 2
gFont2JapaneseGlyphWidths::
	.include "graphics/fonts/font2_japanese_widths.inc"
