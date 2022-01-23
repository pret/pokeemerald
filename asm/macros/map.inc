	.macro map map_id:req
	.byte \map_id >> 8    @ map group
	.byte \map_id & 0xFF  @ map num
	.endm

	.macro map_script type:req, script:req
	.byte \type
	.4byte \script
	.endm

	.macro map_script_2 var:req, compare:req, script:req
	.2byte \var
	.2byte \compare
	.4byte \script
	.endm

	.macro object_event index:req, gfx:req, inConnection:req, x:req, y:req, elevation:req, movement_type:req, x_radius:req, y_radius:req, trainer_type:req, sight_radius_tree_etc:req, script:req, event_flag:req
	.byte \index
	.byte \gfx
	.byte \inConnection
	.byte 0  @ Padding
	.2byte \x, \y
	.byte \elevation
	.byte \movement_type
	.byte ((\y_radius << 4) | \x_radius)
	.byte 0  @ Padding
	.2byte \trainer_type
	.2byte \sight_radius_tree_etc
	.4byte \script
	.2byte \event_flag
	.2byte 0  @ Padding
	inc _num_npcs
	.endm

	.macro warp_def x:req, y:req, elevation:req, warpId:req, map_id:req
	.2byte \x, \y
	.byte \elevation
	.byte \warpId
	.byte \map_id & 0xFF  @ map num
	.byte \map_id >> 8    @ map group
	inc _num_warps
	.endm

	.macro coord_event x:req, y:req, elevation:req, trigger:req, index:req, script:req
	.2byte \x, \y
	.byte \elevation
	.byte 0  @ Padding
	.2byte \trigger
	.2byte \index
	.2byte 0  @ Padding
	.4byte \script
	inc _num_traps
	.endm

	.macro coord_weather_event x:req, y:req, elevation:req, weather:req
	coord_event \x, \y, \elevation, \weather, 0, NULL
	.endm

	.macro bg_event x:req, y:req, elevation:req, kind:req, arg6:req, arg7
	.2byte \x, \y
	.byte \elevation
	.byte \kind
	.2byte 0  @ Padding
	.if \kind != BG_EVENT_HIDDEN_ITEM
		.4byte \arg6
	.else
		.2byte \arg6
		.2byte \arg7
	.endif
	inc _num_signs
	.endm

	.macro bg_sign_event x:req, y:req, elevation:req, facing_dir:req, script:req
	bg_event \x, \y, \elevation, \facing_dir, \script
	.endm

	.macro bg_hidden_item_event x:req, y:req, elevation:req, item:req, flag:req
	bg_event \x, \y, \elevation, BG_EVENT_HIDDEN_ITEM, \item, ((\flag) - FLAG_HIDDEN_ITEMS_START)
	.endm

	.macro bg_secret_base_event x:req, y:req, elevation:req, secret_base_id:req
	bg_event \x, \y, \elevation, BG_EVENT_SECRET_BASE, \secret_base_id
	.endm

	.macro map_events npcs:req, warps:req, traps:req, signs:req
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


	.equiv connection_down, CONNECTION_SOUTH
	.equiv connection_up, CONNECTION_NORTH
	.equiv connection_left, CONNECTION_WEST
	.equiv connection_right, CONNECTION_EAST
	.equiv connection_dive, CONNECTION_DIVE
	.equiv connection_emerge, CONNECTION_EMERGE

	.macro connection direction:req, offset:req, map:req
	.4byte connection_\direction
	.4byte \offset
	map \map
	.space 2
	.endm

	.macro map_header_flags allow_cycling:req, allow_escaping:req, allow_running:req, show_map_name:req
	.byte ((\show_map_name & 1) << 3) | ((\allow_running & 1) << 2) | ((\allow_escaping & 1) << 1) | \allow_cycling
	.endm
