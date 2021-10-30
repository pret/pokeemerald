	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gFontSmallNarrowLatinGlyphs::
	.incbin "graphics/fonts/small_narrow/glyphs.latfont"

	.align 2
gFontSmallNarrowLatinGlyphWidths::
	.include "graphics/fonts/small_narrow/latin_widths.inc"

	.align 2
gFontSmallLatinGlyphs::
	.incbin "graphics/fonts/small/glyphs.latfont"

	.align 2
gFontSmallLatinGlyphWidths::
	.include "graphics/fonts/small/latin_widths.inc"

	.align 2
gFontNarrowLatinGlyphs::
	.incbin "graphics/fonts/narrow/glyphs.latfont"

	.align 2
gFontNarrowLatinGlyphWidths::
	.include "graphics/fonts/narrow/latin_widths.inc"

	.align 2
gFontShortLatinGlyphs::
	.incbin "graphics/fonts/short/glyphs.latfont"

	.align 2
gFontShortLatinGlyphWidths::
	.include "graphics/fonts/short/latin_widths.inc"

	.align 2
gFontNormalLatinGlyphs::
	.incbin "graphics/fonts/normal/glyphs.latfont"

	.align 2
gFontNormalLatinGlyphWidths::
	.include "graphics/fonts/normal/latin_widths.inc"

	.align 2
gFontSmallJapaneseGlyphs::
	.incbin "graphics/fonts/small/glyphs.hwjpnfont"

	.align 2
gFontNormalJapaneseGlyphs::
	.incbin "graphics/fonts/normal/glyphs.hwjpnfont"

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
gFontShortJapaneseGlyphs::
	.incbin "graphics/fonts/short/glyphs.fwjpnfont"

	.align 2
gFontShortJapaneseGlyphWidths::
	.include "graphics/fonts/short/japanese_widths.inc"
