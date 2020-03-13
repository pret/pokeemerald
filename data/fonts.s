	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gFont8LatinGlyphs:: @ 862BAE4
	.incbin "graphics/fonts/font8.latfont"

	.align 2
gFont8LatinGlyphWidths:: @ 8633AE4
	.include "graphics/fonts/font8_latin_widths.inc"

	.align 2
gFont0LatinGlyphs:: @ 8633CE4
	.incbin "graphics/fonts/font0.latfont"

	.align 2
gFont0LatinGlyphWidths:: @ 863BCE4
	.include "graphics/fonts/font0_latin_widths.inc"

	.align 2
gFont7LatinGlyphs:: @ 863BEE4
	.incbin "graphics/fonts/font7.latfont"

	.align 2
gFont7LatinGlyphWidths:: @ 8643EE4
	.include "graphics/fonts/font7_latin_widths.inc"

	.align 2
gFont2LatinGlyphs:: @ 86440E4
	.incbin "graphics/fonts/font2.latfont"

	.align 2
gFont2LatinGlyphWidths:: @ 864C0E4
	.include "graphics/fonts/font2_latin_widths.inc"

	.align 2
gFont1LatinGlyphs:: @ 864C2E4
	.incbin "graphics/fonts/font1.latfont"

	.align 2
gFont1LatinGlyphWidths:: @ 86542E4
	.include "graphics/fonts/font1_latin_widths.inc"

	.align 2
gFont0JapaneseGlyphs:: @ 86544E4
	.incbin "graphics/fonts/font0.hwjpnfont"

	.align 2
gFont1JapaneseGlyphs:: @ 86584E4
	.incbin "graphics/fonts/font1.hwjpnfont"

	.align 2
gUnusedJapaneseFireRedLeafGreenMaleFontGlyphs:: @ 865C4E4
	.incbin "graphics/fonts/unused_frlg_male.fwjpnfont"

	.align 2
gUnusedJapaneseFireRedLeafGreenMaleFontGlyphWidths:: @ 86644E4
	.include "graphics/fonts/unused_japanese_frlg_male_font_widths.inc"

	.align 2
gUnusedJapaneseFireRedLeafGreenFemaleFontGlyphs:: @ 86646E4
	.incbin "graphics/fonts/unused_frlg_female.fwjpnfont"

	.align 2
gUnusedJapaneseFireRedLeafGreenFemaleFontGlyphWidths:: @ 866C6E4
	.include "graphics/fonts/unused_japanese_frlg_female_font_widths.inc"

	.align 2
gFont2JapaneseGlyphs:: @ 866C8E4
	.incbin "graphics/fonts/font2.fwjpnfont"

	.align 2
gFont2JapaneseGlyphWidths:: @ 86748E4
	.include "graphics/fonts/font2_japanese_widths.inc"
