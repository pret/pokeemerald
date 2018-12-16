	.macro pokedex_entry height, width, text_pointer, pokemon_scale, pokemon_offset, trainer_scale, trainer_offset
	.2byte \height @ in decimeters
	.2byte \width @ in hectograms
	.4byte \text_pointer
	.2byte 0 @ unused
	.2byte \pokemon_scale
	.2byte \pokemon_offset
	.2byte \trainer_scale
	.2byte \trainer_offset
	.2byte 0 @ padding
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

	.macro evo_entry method, parameter, target_species
	.2byte \method
	.2byte \parameter
	.2byte \target_species
	.2byte 0 @ padding
	.endm

	.macro empty_evo_entries count
	.fill 8 * \count, 1, 0
	.endm

	.macro egg_moves_begin species
	.2byte 20000 + \species
	.endm

@ If the min level equals the max level, only one level argument is needed.
	.macro wild_mon species, min_level, max_level
	.byte \min_level

	.ifb \max_level
	.byte \min_level
	.else
	.byte \max_level
	.endif

	.2byte \species
	.endm
