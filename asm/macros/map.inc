	.macro map map_id
	.byte \map_id >> 8    @ map group
	.byte \map_id & 0xFF  @ map num
	.endm

	.macro map_script type, address
	.byte \type
	.4byte \address
	.endm

	.macro map_script_2 word1, word2, address
	.2byte \word1
	.2byte \word2
	.4byte \address
	.endm

	.macro object_event index:req, gfx:req, replacement:req, x:req, y:req, elevation:req, movement_type:req, x_radius:req, y_radius:req, trainer_type:req, sight_radius_tree_etc:req, script:req, event_flag:req
	.byte \index, \gfx, \replacement, 0
	.2byte \x
	.2byte \y
	.byte \elevation, \movement_type, ((\y_radius << 4) | \x_radius), 0
    .2byte \trainer_type, \sight_radius_tree_etc
	.4byte \script
	.2byte \event_flag
	.2byte 0
	inc _num_npcs
	.endm

	.macro warp_def x, y, byte, warp, map_id
	.2byte \x, \y
	.byte \byte, \warp
	.byte \map_id & 0xFF  @ map num
	.byte \map_id >> 8    @ map group
	inc _num_warps
	.endm

	.macro coord_event x, y, elevation, trigger, index, script
	.2byte \x, \y
	.byte \elevation, 0
	.2byte \trigger, \index, 0
	.4byte \script
	inc _num_traps
	.endm

	.macro coord_weather_event x, y, elevation, weather
	.2byte \x, \y
	.byte \elevation, 0
	.2byte \weather
	.2byte 0, 0
	.4byte 0
	inc _num_traps
	.endm

	.macro bg_event x, y, elevation, kind, arg6, arg7, arg8
	.2byte \x, \y
	.byte \elevation, \kind
	.2byte 0
	.if \kind < 5
	.4byte \arg6
	.else
	.2byte \arg6
	.byte \arg7, \arg8
	.endif
	inc _num_signs
	.endm

	.macro bg_hidden_item_event x, y, height, item, flag
	bg_event \x, \y, \height, 7, \item, ((\flag) - FLAG_HIDDEN_ITEMS_START), 0
	.endm

	.macro bg_secret_base_event x, y, height, secret_base_id
	bg_event \x, \y, \height, 8, \secret_base_id, 0, 0
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

	.macro connection direction, offset, map
	.4byte connection_\direction
	.4byte \offset
	map \map
	.space 2
	.endm

	.macro map_header_flags allow_cycling:req, allow_escaping:req, allow_running:req, show_map_name:req
	.byte ((\show_map_name & 1) << 3) | ((\allow_running & 1) << 2) | ((\allow_escaping & 1) << 1) | \allow_cycling
	.endm
