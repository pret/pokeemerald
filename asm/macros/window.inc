	.macro window_template bg_id, x, y, width, height, palette, vram_tile_offset
	.byte \bg_id
	.byte \x
	.byte \y
	.byte \width
	.byte \height
	.byte \palette
	.2byte \vram_tile_offset
	.endm

	.macro null_window_template
	window_template 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0000
	.endm

	.macro glyph_width_func font_id, func
	.4byte \font_id
	.4byte \func
	.endm

	.macro keypad_icon tile_offset, width, height
	.2byte \tile_offset
	.byte \width
	.byte \height
	.endm

	.macro font_info func, max_glyph_width, glyph_height, glyph_spacing, line_spacing, text_color, shadow_color, bg_color
	.4byte \func
	.byte \max_glyph_width
	.byte \glyph_height
	.byte \glyph_spacing
	.byte \line_spacing
	.byte \text_color << 4 @ low nybble seems unused
	.byte (\shadow_color << 4) | \bg_color
	.2byte 0 @ padding
	.endm
