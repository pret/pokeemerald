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

	.macro ec_word_pokemon ec_word
	.2byte (EC_GROUP_POKEMON << 9) | SPECIES_\ec_word
	.endm

	.macro ec_word_trainer ec_word
	.2byte (EC_GROUP_TRAINER << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_status ec_word
	.2byte (EC_GROUP_STATUS << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_battle ec_word
	.2byte (EC_GROUP_BATTLE << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_greetings ec_word
	.2byte (EC_GROUP_GREETINGS << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_people ec_word
	.2byte (EC_GROUP_PEOPLE << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_voices ec_word
	.2byte (EC_GROUP_VOICES << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_speech ec_word
	.2byte (EC_GROUP_SPEECH << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_endings ec_word
	.2byte (EC_GROUP_ENDINGS << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_feelings ec_word
	.2byte (EC_GROUP_FEELINGS << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_conditions ec_word
	.2byte (EC_GROUP_CONDITIONS << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_actions ec_word
	.2byte (EC_GROUP_ACTIONS << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_lifestyle ec_word
	.2byte (EC_GROUP_LIFESTYLE << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_hobbies ec_word
	.2byte (EC_GROUP_HOBBIES << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_time ec_word
	.2byte (EC_GROUP_TIME << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_misc ec_word
	.2byte (EC_GROUP_MISC << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_adjectives ec_word
	.2byte (EC_GROUP_ADJECTIVES << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_events ec_word
	.2byte (EC_GROUP_EVENTS << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_move_1 ec_word
	.2byte (EC_GROUP_MOVE_1 << 9) | MOVE_\ec_word
	.endm

	.macro ec_word_move_2 ec_word
	.2byte (EC_GROUP_MOVE_2 << 9) | MOVE_\ec_word
	.endm

	.macro ec_word_trendy_saying ec_word
	.2byte (EC_GROUP_TRENDY_SAYING << 9) | EC_WORD_\ec_word
	.endm

	.macro ec_word_pokemon2 ec_word
	.2byte (EC_GROUP_POKEMON2 << 9) | SPECIES_\ec_word
	.endm
