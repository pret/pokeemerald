	.macro new_map_group
	inc cur_map_group
	.set cur_map_num, 0
	.endm

	.macro map_group map_name
	.set GROUP_\map_name, cur_map_group
	.set MAP_\map_name, cur_map_num
	inc cur_map_num
	.endm

	.macro map map_name
	.byte GROUP_\map_name
	.byte MAP_\map_name
	.endm

	.macro warp_map map_name
	.byte MAP_\map_name
	.byte GROUP_\map_name
	.endm

	.macro heal_location map_name, x, y
	.byte GROUP_\map_name
	.byte MAP_\map_name
	.2byte \x
	.2byte \y
	.space 2
	.endm

	.equiv GROUP_NONE, 0x7f
	.equiv MAP_NONE, 0x7f

	.equiv GROUP_UNDEFINED, 0xff
	.equiv MAP_UNDEFINED, 0xff

	.macro map_script type, address
	.byte \type
	.4byte \address
	.endm

	.macro map_script_2 word1, word2, address
	.2byte \word1
	.2byte \word2
	.4byte \address
	.endm

	.macro object_event byte1, word1, byte2, byte3, byte4, byte5, byte6, byte7, byte8, byte9, byte10, byte11, byte12, byte13, byte14, script, word2, byte15, byte16
	.byte \byte1
	.2byte \word1
	.byte \byte2, \byte3, \byte4, \byte5, \byte6, \byte7, \byte8, \byte9, \byte10, \byte11, \byte12, \byte13, \byte14
	.4byte \script
	.2byte \word2
	.byte \byte15, \byte16
	inc _num_npcs
	.endm

	.macro warp_def x, y, byte, warp, map
	.2byte \x, \y
	.byte \byte, \warp
	warp_map \map
	inc _num_warps
	.endm

	.macro coord_event x, y, byte1, byte2, word1, word2, word3, script
	.2byte \x, \y
	.byte \byte1, \byte2
	.2byte \word1, \word2, \word3
	.4byte \script
	inc _num_traps
	.endm

	.macro bg_event x, y, byte, kind, word, arg6, arg7, arg8
	.2byte \x, \y
	.byte \byte, \kind
	.2byte \word
	.if \kind < 5
	.4byte \arg6
	.else
	.2byte \arg6
	.byte \arg7, \arg8
	.endif
	inc _num_signs
	.endm

	.macro map_events npcs, warps, traps, signs
	.byte _num_npcs, _num_warps, _num_traps, _num_signs
	.4byte \npcs, \warps, \traps, \signs
	reset_map_events
	.endm

	.macro reset_map_events
	.set _num_npcs, 0
	.set _num_warps, 0
	.set _num_traps, 0
	.set _num_signs, 0
	.endm

	reset_map_events


	.equiv connection_down, 1
	.equiv connection_up, 2
	.equiv connection_left, 3
	.equiv connection_right, 4
	.equiv connection_dive, 5
	.equiv connection_emerge, 6

	.macro connection direction, offset, map, filler
	.4byte connection_\direction
	.4byte \offset
	map \map
	.space 2
	.endm
