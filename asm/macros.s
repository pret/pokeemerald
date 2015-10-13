	.macro include_range start, end
	.incbin "base_emerald.gba", \start, \end - \start
	.endm

	.macro arm_func_start name
	.align 2, 0
	.global \name
	.arm
	.type \name, %function
	.endm

	.macro arm_func_end name
	.size \name, .-\name
	.endm

	.macro thumb_func_start name
	.align 2, 0
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro non_word_aligned_thumb_func_start name
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro thumb_func_end name
	.size \name, .-\name
	.endm

	.macro window_template bg_id, x, y, width, height, palette, vram_tile_offset
	.byte \bg_id
	.byte \x
	.byte \y
	.byte \width
	.byte \height
	.byte \palette
	.2byte \vram_tile_offset
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
	.byte \text_color << 4 ; low nybble seems unused
	.byte (\shadow_color << 4) | \bg_color
	.2byte 0 ; padding
	.endm

	.macro pokedex_entry category_name, height, width, text_pointer, pokemon_scale, pokemon_offset, trainer_scale, trainer_offset
	.charmapstr "\category_name", 12
	.2byte \height ; in decimeters
	.2byte \width ; in hectograms
	.4byte \text_pointer
	.2byte 0 ; unused
	.2byte \pokemon_scale
	.2byte \pokemon_offset
	.2byte \trainer_scale
	.2byte \trainer_offset
	.2byte 0 ; padding
	.endm

	.macro base_stats hp, attack, defense, speed, sp_attack, sp_defense
	.byte \hp
	.byte \attack
	.byte \defense
	.byte \speed
	.byte \sp_attack
	.byte \sp_defense
	.endm

	.macro ev_yield hp, attack, defense, speed, sp_attack, sp_defense
	.2byte (\sp_defense << 10) | (\sp_attack << 8) | (\speed << 6) | (\defense << 4) | (\attack << 2) | \hp
	.endm

	.macro level_up_move level, move
	.2byte (\level << 9) | \move
	.endm

	.macro evo_entry method, parameter, target_pokemon
	.2byte \method
	.2byte \parameter
	.2byte \target_pokemon
	.2byte 0 ; padding
	.endm

	.macro empty_evo_entries count
	.fill 8 * \count, 1, 0
	.endm

	.macro egg_moves_begin species
	.2byte 20000 + \species
	.endm
