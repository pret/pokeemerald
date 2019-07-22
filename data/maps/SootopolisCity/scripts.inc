SootopolisCity_MapScripts:: @ 81E565C
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_MapScript1_1E5676
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_MapScript1_1E590B
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MapScript2_1E5914
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_MapScript2_1E58DB
	.byte 0

SootopolisCity_MapScript1_1E5676: @ 81E5676
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_1E56E5
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_1E5692
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_1E5693
	end

SootopolisCity_EventScript_1E5692:: @ 81E5692
	end

SootopolisCity_EventScript_1E5693:: @ 81E5693
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, 1
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, 1
	return

SootopolisCity_EventScript_1E56E5:: @ 81E56E5
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, 1
	return

SootopolisCity_OnTransition: @ 81E56EF
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	compare VAR_RAYQUAZA_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E5781
	compare VAR_SKY_PILLAR_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E5781
	call SootopolisCity_EventScript_1E5805
	call SootopolisCity_EventScript_1E57B2
	compare VAR_RAYQUAZA_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E5785
	compare VAR_RAYQUAZA_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E5785
	compare VAR_RAYQUAZA_STATE, 3
	call_if_eq SootopolisCity_EventScript_1E5785
	compare VAR_RAYQUAZA_STATE, 4
	call_if_eq SootopolisCity_EventScript_1E5785
	compare VAR_RAYQUAZA_STATE, 5
	call_if_eq SootopolisCity_EventScript_1E5785
	compare VAR_RAYQUAZA_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E5842
	compare VAR_RAYQUAZA_STATE, 3
	call_if_eq SootopolisCity_EventScript_1E5842
	compare VAR_RAYQUAZA_STATE, 4
	call_if_eq SootopolisCity_EventScript_1E585B
	compare VAR_RAYQUAZA_STATE, 5
	call_if_eq SootopolisCity_EventScript_1E5871
	compare VAR_RAYQUAZA_STATE, 6
	call_if_eq SootopolisCity_EventScript_1E58D3
	end

SootopolisCity_EventScript_1E5781:: @ 81E5781
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

SootopolisCity_EventScript_1E5785:: @ 81E5785
	setobjectxyperm 3, 13, 48
	setobjectxyperm 5, 46, 32
	setobjectxyperm 4, 48, 41
	setobjectxyperm 8, 45, 43
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_LEFT
	return

SootopolisCity_EventScript_1E57B2:: @ 81E57B2
	compare VAR_RAYQUAZA_STATE, 0
	goto_if_eq SootopolisCity_EventScript_1E5800
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E5800
	compare VAR_RAYQUAZA_STATE, 1
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_RAYQUAZA_STATE, 2
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_RAYQUAZA_STATE, 3
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_RAYQUAZA_STATE, 4
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E5801
	return

SootopolisCity_EventScript_1E5800:: @ 81E5800
	return

SootopolisCity_EventScript_1E5801:: @ 81E5801
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
	return

SootopolisCity_EventScript_1E5805:: @ 81E5805
	compare VAR_RAYQUAZA_STATE, 0
	goto_if_eq SootopolisCity_EventScript_1E583D
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E583D
	compare VAR_RAYQUAZA_STATE, 1
	goto_if_eq SootopolisCity_EventScript_1E583E
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_eq SootopolisCity_EventScript_1E583E
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_le Common_EventScript_SetWeather15
	return

SootopolisCity_EventScript_1E583D:: @ 81E583D
	return

SootopolisCity_EventScript_1E583E:: @ 81E583E
	setweather WEATHER_RAIN_HEAVY
	return

SootopolisCity_EventScript_1E5842:: @ 81E5842
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_1E584C
	return

SootopolisCity_EventScript_1E584C:: @ 81E584C
	setobjectxyperm 1, 30, 18
	setobjectxyperm 7, 32, 18
	return

SootopolisCity_EventScript_1E585B:: @ 81E585B
	setobjectxyperm 1, 30, 18
	setobjectxyperm 18, 31, 18
	setobjectxyperm 7, 32, 18
	end

SootopolisCity_EventScript_1E5871:: @ 81E5871
	setobjectxyperm 1, 31, 18
	setobjectxyperm 7, 29, 33
	setobjectxyperm 16, 33, 35
	setobjectxyperm 17, 34, 35
	compare VAR_SOOTOPOLIS_STATE, 0
	call_if_eq SootopolisCity_EventScript_1E58AF
	compare VAR_SOOTOPOLIS_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E58BB
	compare VAR_SOOTOPOLIS_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E58C7
	return

SootopolisCity_EventScript_1E58AF:: @ 81E58AF
	setobjectxyperm 18, 31, 33
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_1E58BB:: @ 81E58BB
	setobjectxyperm 18, 32, 33
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_1E58C7:: @ 81E58C7
	setobjectxyperm 18, 30, 33
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_1E58D3:: @ 81E58D3
	setobjectxyperm 1, 31, 18
	return

SootopolisCity_MapScript2_1E58DB: @ 81E58DB
	map_script_2 VAR_RAYQUAZA_STATE, 5, SootopolisCity_EventScript_1E58E5
	.2byte 0

SootopolisCity_EventScript_1E58E5:: @ 81E58E5
	compare VAR_SKY_PILLAR_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E58FC
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E5901
	end

SootopolisCity_EventScript_1E58FC:: @ 81E58FC
	turnobject EVENT_OBJ_ID_PLAYER, 2
	return

SootopolisCity_EventScript_1E5901:: @ 81E5901
	turnobject EVENT_OBJ_ID_PLAYER, 2
	setvar VAR_SKY_PILLAR_STATE, 3
	return

SootopolisCity_MapScript1_1E590B: @ 81E590B
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 255, 9, 6
	end

SootopolisCity_MapScript2_1E5914: @ 81E5914
	map_script_2 VAR_RAYQUAZA_STATE, 1, SootopolisCity_EventScript_1E5926
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_1E5BFE
	.2byte 0

SootopolisCity_EventScript_1E5926:: @ 81E5926
	lockall
	special StorePlayerCoordsInVars
	compare VAR_0x8004, 43
	goto_if_ne SootopolisCity_EventScript_1E5A82
	compare VAR_0x8005, 32
	goto_if_ne SootopolisCity_EventScript_1E5A82
	goto SootopolisCity_EventScript_1E5946
	end

SootopolisCity_EventScript_1E5946:: @ 81E5946
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5A68
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	setweather WEATHER_ALTERNATING
	doweather
	setvar VAR_0x8004, 0
	special sub_813B7D8
	waitstate
	applymovement 10, Common_Movement_WalkInPlaceLeft
	applymovement 9, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	applymovement 10, SootopolisCity_Movement_1E5BC2
	applymovement 9, SootopolisCity_Movement_1E5BDD
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	special SpawnCameraObject
	applymovement 10, SootopolisCity_Movement_1E5BD6
	applymovement 9, SootopolisCity_Movement_1E5BF7
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5A75
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_RAYQUAZA_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_1E5A68: @ 81E5A68
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_1E5A75: @ 81E5A75
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	step_end

SootopolisCity_EventScript_1E5A82:: @ 81E5A82
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5BA4
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	setweather WEATHER_ALTERNATING
	doweather
	setvar VAR_0x8004, 0
	special sub_813B7D8
	waitstate
	applymovement 10, Common_Movement_WalkInPlaceLeft
	applymovement 9, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	applymovement 10, SootopolisCity_Movement_1E5BC2
	applymovement 9, SootopolisCity_Movement_1E5BDD
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement 10, SootopolisCity_Movement_1E5BB8
	applymovement 9, SootopolisCity_Movement_1E5BE5
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	applymovement 10, SootopolisCity_Movement_1E5BCF
	applymovement 9, SootopolisCity_Movement_1E5BF0
	waitmovement 0
	special SpawnCameraObject
	applymovement 10, SootopolisCity_Movement_1E5BD6
	applymovement 9, SootopolisCity_Movement_1E5BF7
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5BAE
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_RAYQUAZA_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

SootopolisCity_Movement_1E5BA4: @ 81E5BA4
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E5BAE: @ 81E5BAE
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_Movement_1E5BB8: @ 81E5BB8
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_1E5BC2: @ 81E5BC2
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end

SootopolisCity_Movement_1E5BCF: @ 81E5BCF
	lock_facing_direction
	walk_right
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_1E5BD6: @ 81E5BD6
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	step_end

SootopolisCity_Movement_1E5BDD: @ 81E5BDD
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_1E5BE5: @ 81E5BE5
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end

SootopolisCity_Movement_1E5BF0: @ 81E5BF0
	lock_facing_direction
	walk_left
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end

SootopolisCity_Movement_1E5BF7: @ 81E5BF7
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	step_end

SootopolisCity_EventScript_1E5BFE:: @ 81E5BFE
	lockall
	special StorePlayerCoordsInVars
	compare VAR_0x8004, 43
	goto_if_ne SootopolisCity_EventScript_1E5CCE
	compare VAR_0x8005, 32
	goto_if_ne SootopolisCity_EventScript_1E5CCE
	goto SootopolisCity_EventScript_1E5C1E
	end

SootopolisCity_EventScript_1E5C1E:: @ 81E5C1E
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5A68
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	call SootopolisCity_EventScript_1E5D82
	removeobject 9
	removeobject 10
	addobject 11
	setvar VAR_0x8004, 1
	special sub_813B7D8
	waitstate
	playse SE_T_KAMI
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5E63
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special sub_8139560
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement 11, SootopolisCity_Movement_1E5E5B
	waitmovement 0
	removeobject 11
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 3
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_RUNECITY
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp8 MAP_SOOTOPOLIS_CITY, 255, 43, 32
	waitstate
	end

SootopolisCity_EventScript_1E5CCE:: @ 81E5CCE
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5BA4
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	call SootopolisCity_EventScript_1E5D82
	removeobject 9
	removeobject 10
	addobject 11
	setvar VAR_0x8004, 1
	special sub_813B7D8
	waitstate
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5E63
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E5E68
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special sub_8139560
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement 11, SootopolisCity_Movement_1E5E5B
	waitmovement 0
	removeobject 11
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 2
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	fadenewbgm MUS_NAMINORI
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp8 MAP_SOOTOPOLIS_CITY, 255, 29, 53
	waitstate
	end

SootopolisCity_EventScript_1E5D82:: @ 81E5D82
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, 0
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, 0
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, 0
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, 0
	return

SootopolisCity_Movement_1E5E5B: @ 81E5E5B
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

SootopolisCity_Movement_1E5E63: @ 81E5E63
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E5E68: @ 81E5E68
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E5E6D: @ 81E5E6D
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SootopolisCity_Movement_1E5E72: @ 81E5E72
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_1E5E7F: @ 81E5E7F
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

SootopolisCity_EventScript_1E5E8D:: @ 81E5E8D
	lock
	faceplayer
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E5EC4
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E5ECE
	compare VAR_RAYQUAZA_STATE, 2
	goto_if_ge SootopolisCity_EventScript_1E5EBA
	msgbox SootopolisCity_Text_1E6D77, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5EBA:: @ 81E5EBA
	msgbox SootopolisCity_Text_1E6DFE, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5EC4:: @ 81E5EC4
	msgbox SootopolisCity_Text_1E6F38, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5ECE:: @ 81E5ECE
	msgbox SootopolisCity_Text_1E6ED4, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5ED8:: @ 81E5ED8
	lock
	faceplayer
	compare VAR_RAYQUAZA_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E5F1B
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E5F1B
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E5F10
	msgbox SootopolisCity_Text_1E6BFF, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E5F10:: @ 81E5F10
	msgbox SootopolisCity_Text_1E6C53, MSGBOX_DEFAULT
	closemessage
	release
	end

SootopolisCity_EventScript_1E5F1B:: @ 81E5F1B
	dotimebasedevents
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_1E5FBB
	msgbox SootopolisCity_Text_2A7BB0, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, 20
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
	msgbox SootopolisCity_Text_2A7C7C, MSGBOX_DEFAULT
	random 2
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_EventScript_1E5F79
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_EventScript_1E5F9A
	end

SootopolisCity_EventScript_1E5F79:: @ 81E5F79
	giveitem_std ITEM_FIGY_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_2A7CB7, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5F9A:: @ 81E5F9A
	giveitem_std ITEM_IAPAPA_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_2A7CB7, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5FBB:: @ 81E5FBB
	msgbox SootopolisCity_Text_2A7CEC, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_EventScript_1E5FD8
	msgbox SootopolisCity_Text_2A7DD2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5FD8:: @ 81E5FD8
	msgbox SootopolisCity_Text_2A7D80, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E5FE2:: @ 81E5FE2
	lockall
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E600D
	msgbox SootopolisCity_Text_1E71A1, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E600D:: @ 81E600D
	msgbox SootopolisCity_Text_1E728C, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E6017:: @ 81E6017
	lock
	faceplayer
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E602E
	msgbox SootopolisCity_Text_1E6CCA, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E602E:: @ 81E602E
	msgbox SootopolisCity_Text_1E6D57, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E6038:: @ 81E6038
	lock
	faceplayer
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E607A
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6084
	compare VAR_RAYQUAZA_STATE, 2
	goto_if_ge SootopolisCity_EventScript_1E6065
	msgbox SootopolisCity_Text_1E6F90, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E6065:: @ 81E6065
	msgbox SootopolisCity_Text_1E7078, MSGBOX_DEFAULT
	closemessage
	applymovement 8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E607A:: @ 81E607A
	msgbox SootopolisCity_Text_1E710B, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E6084:: @ 81E6084
	msgbox SootopolisCity_Text_1E70D4, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E608E:: @ 81E608E
	lockall
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E60D9
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E60CF
	compare VAR_RAYQUAZA_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E60CF
	msgbox SootopolisCity_Text_1E690B, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E60CF:: @ 81E60CF
	msgbox SootopolisCity_Text_1E68A1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E60D9:: @ 81E60D9
	msgbox SootopolisCity_Text_1E6920, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E60E3:: @ 81E60E3
	lockall
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E612D
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_1E6137
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E6141
	compare VAR_RAYQUAZA_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E6141
	msgbox SootopolisCity_Text_1E6692, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SootopolisCity_EventScript_1E612D:: @ 81E612D
	msgbox SootopolisCity_Text_1E6750, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E6137:: @ 81E6137
	msgbox SootopolisCity_Text_1E677F, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E6141:: @ 81E6141
	msgbox SootopolisCity_Text_1E6618, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E614B:: @ 81E614B
	msgbox SootopolisCity_Text_1E656F, MSGBOX_SIGN
	end

SootopolisCity_EventScript_1E6154:: @ 81E6154
	msgbox SootopolisCity_Text_1E65C8, MSGBOX_SIGN
	end

EventScript_ClosedSootopolisDoor:: @ 81E615D
	msgbox SootopolisCity_Text_1E6604, MSGBOX_SIGN
	end

SootopolisCity_EventScript_1E6166:: @ 81E6166
	lockall
	applymovement 7, Common_Movement_FacePlayer
	waitmovement 0
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_1E61CC
	compare VAR_RAYQUAZA_STATE, 2
	goto_if_eq SootopolisCity_EventScript_1E61AE
	compare VAR_RAYQUAZA_STATE, 3
	goto_if_eq SootopolisCity_EventScript_1E61C2
	compare VAR_RAYQUAZA_STATE, 4
	goto_if_eq SootopolisCity_EventScript_1E61C2
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_1E61B8
	msgbox SootopolisCity_Text_1E78E5, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E61AE:: @ 81E61AE
	msgbox SootopolisCity_Text_1E7866, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E61B8:: @ 81E61B8
	msgbox SootopolisCity_Text_1E794B, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E61C2:: @ 81E61C2
	msgbox SootopolisCity_Text_1E789A, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E61CC:: @ 81E61CC
	msgbox SootopolisCity_Text_1E75CB, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 3
	call_if_eq SootopolisCity_EventScript_1E6243
	compare VAR_FACING, 2
	call_if_eq SootopolisCity_EventScript_1E6255
	msgbox SootopolisCity_Text_1E7737, MSGBOX_DEFAULT
	closemessage
	applymovement 7, SootopolisCity_Movement_1E62D4
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E630E
	waitmovement 0
	delay 120
	applymovement 1, SootopolisCity_Movement_1E6341
	waitmovement 0
	applymovement 7, SootopolisCity_Movement_1E6344
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E634F
	waitmovement 0
	msgbox SootopolisCity_Text_1E77F0, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E635A
	waitmovement 0
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 255, 9, 20
	waitstate
	end

SootopolisCity_EventScript_1E6243:: @ 81E6243
	applymovement 7, SootopolisCity_Movement_1E6267
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E628C
	waitmovement 0
	return

SootopolisCity_EventScript_1E6255:: @ 81E6255
	applymovement 7, SootopolisCity_Movement_1E6267
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E62B0
	waitmovement 0
	return

SootopolisCity_Movement_1E6267: @ 81E6267
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

SootopolisCity_Movement_1E628C: @ 81E628C
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E62B0: @ 81E62B0
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E62D4: @ 81E62D4
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	delay_4
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E630E: @ 81E630E
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_1E6341: @ 81E6341
	walk_slow_left
	walk_in_place_fastest_right
	step_end

SootopolisCity_Movement_1E6344: @ 81E6344
	walk_down
	walk_down
	walk_left
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_left
	step_end

SootopolisCity_Movement_1E634F: @ 81E634F
	delay_16
	delay_16
	delay_16
	delay_8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

SootopolisCity_Movement_1E635A: @ 81E635A
	walk_up
	walk_up
	step_end

SootopolisCity_EventScript_1E635D:: @ 81E635D
	lockall
	applymovement 15, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6388
	msgbox SootopolisCity_Text_1E67DC, MSGBOX_DEFAULT
	closemessage
	applymovement 15, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E6388:: @ 81E6388
	msgbox SootopolisCity_Text_1E6853, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_1E6393:: @ 81E6393
	lockall
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E63C7
	msgbox SootopolisCity_Text_1E6936, MSGBOX_DEFAULT
	closemessage
	applymovement 14, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_1E696C, MSGBOX_DEFAULT
	closemessage
	applymovement 14, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E63C7:: @ 81E63C7
	applymovement 14, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_1E69B8, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E63DB:: @ 81E63DB
	lockall
	applymovement 13, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6406
	msgbox SootopolisCity_Text_1E6C7C, MSGBOX_DEFAULT
	closemessage
	applymovement 13, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E6406:: @ 81E6406
	msgbox SootopolisCity_Text_1E6CA6, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_1E6411:: @ 81E6411
	lockall
	applymovement 12, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E643C
	msgbox SootopolisCity_Text_1E6A50, MSGBOX_DEFAULT
	closemessage
	applymovement 12, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SootopolisCity_EventScript_1E643C:: @ 81E643C
	msgbox SootopolisCity_Text_1E6B2A, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_EventScript_1E6446:: @ 81E6446
	lock
	faceplayer
	compare VAR_RAYQUAZA_STATE, 4
	goto_if_eq SootopolisCity_EventScript_1E64D8
	goto_if_set FLAG_RECEIVED_HM07, SootopolisCity_EventScript_1E64E2
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_1E646F
	msgbox SootopolisCity_Text_1E7A3E, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E646F:: @ 81E646F
	msgbox SootopolisCity_Text_1E7ACF, MSGBOX_DEFAULT
	giveitem_std ITEM_HM07
	setflag FLAG_RECEIVED_HM07
	msgbox SootopolisCity_Text_1E7B86, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 2
	call_if_eq SootopolisCity_EventScript_1E64B2
	compare VAR_FACING, 4
	call_if_eq SootopolisCity_EventScript_1E64B2
	compare VAR_FACING, 3
	call_if_eq SootopolisCity_EventScript_1E64C5
	release
	end

SootopolisCity_EventScript_1E64B2:: @ 81E64B2
	applymovement 18, SootopolisCity_Movement_1E64EC
	waitmovement 0
	moveobjectoffscreen 18
	setvar VAR_SOOTOPOLIS_STATE, 1
	return

SootopolisCity_EventScript_1E64C5:: @ 81E64C5
	applymovement 18, SootopolisCity_Movement_1E64EF
	waitmovement 0
	moveobjectoffscreen 18
	setvar VAR_SOOTOPOLIS_STATE, 2
	return

SootopolisCity_EventScript_1E64D8:: @ 81E64D8
	msgbox SootopolisCity_Text_1E79C8, MSGBOX_DEFAULT
	release
	end

SootopolisCity_EventScript_1E64E2:: @ 81E64E2
	msgbox SootopolisCity_Text_1E7CBC, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Movement_1E64EC: @ 81E64EC
	walk_right
	walk_in_place_fastest_down
	step_end

SootopolisCity_Movement_1E64EF: @ 81E64EF
	walk_left
	walk_in_place_fastest_down
	step_end

SootopolisCity_EventScript_1E64F2:: @ 81E64F2
	lockall
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6509
	msgbox SootopolisCity_Text_1E72DB, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_1E6509:: @ 81E6509
	msgbox SootopolisCity_Text_1E737E, MSGBOX_DEFAULT
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_1E654C
	releaseall
	end

SootopolisCity_EventScript_1E651F:: @ 81E651F
	lockall
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6536
	msgbox SootopolisCity_Text_1E7460, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SootopolisCity_EventScript_1E6536:: @ 81E6536
	msgbox SootopolisCity_Text_1E74F6, MSGBOX_DEFAULT
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_1E654C
	releaseall
	end

SootopolisCity_EventScript_1E654C:: @ 81E654C
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setvar VAR_MT_PYRE_STATE, 2
	warpsilent MAP_SOOTOPOLIS_CITY, 255, 31, 34
	waitstate
	releaseall
	end

SootopolisCity_Movement_1E656B:: @ 81E656B
	levitate
	step_end

SootopolisCity_Movement_1E656D:: @ 81E656D
	destroy_extra_task
	step_end

SootopolisCity_Text_1E656F: @ 81E656F
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
	.string "LEADER: JUAN\p"
	.string "“The GYM LEADER with the beauty\n"
	.string "of pure water!”$"

SootopolisCity_Text_1E65C8: @ 81E65C8
	.string "SOOTOPOLIS CITY\p"
	.string "“The mystical city where history\n"
	.string "slumbers.”$"


SootopolisCity_Text_1E6604: @ 81E6604
	.string "The door is closed.$"

SootopolisCity_Text_1E6618: @ 81E6618
	.string "Diving in the sea. Climbing up and\n"
	.string "down stairs all the time…\p"
	.string "If you live in this town, you end up\n"
	.string "getting physically fit.$"

SootopolisCity_Text_1E6692: @ 81E6692
	.string "These giant POKéMON suddenly appeared\n"
	.string "in the middle of the city!\p"
	.string "And, I've never seen them before!\p"
	.string "Why are they smashing into each\n"
	.string "other like that?\p"
	.string "Why can't they be friends, those\n"
	.string "POKéMON?$"

SootopolisCity_Text_1E6750: @ 81E6750
	.string "What? What? What?\n"
	.string "What is that green POKéMON?!$"

SootopolisCity_Text_1E677F: @ 81E677F
	.string "GROUDON and KYOGRE…\n"
	.string "Where did they go?\p"
	.string "Will they cause droughts or downpours\n"
	.string "somewhere else?$"

SootopolisCity_Text_1E67DC: @ 81E67DC
	.string "I just get this sense somehow that\n"
	.string "the two POKéMON aren't angry.\p"
	.string "I think… They probably can't control\n"
	.string "their own power…$"

SootopolisCity_Text_1E6853: @ 81E6853
	.string "That flying POKéMON came down from\n"
	.string "the sky and stopped the rampaging\l"
	.string "POKéMON…$"

SootopolisCity_Text_1E68A1: @ 81E68A1
	.string "I… I've never been out of this city.\p"
	.string "I wonder what the world is like on\n"
	.string "the other side of this round sky?$"

SootopolisCity_Text_1E690B: @ 81E690B
	.string "Wow!\n"
	.string "This is wicked!$"

SootopolisCity_Text_1E6920: @ 81E6920
	.string "Wow!\n"
	.string "That was wicked!$"

SootopolisCity_Text_1E6936: @ 81E6936
	.string "Go for it, red POKéMON!\n"
	.string "Don't back off, blue POKéMON!$"

SootopolisCity_Text_1E696C: @ 81E696C
	.string "… … … … … …\p"
	.string "Hi, do you know the names of those\n"
	.string "POKéMON fighting over there?$"

SootopolisCity_Text_1E69B8: @ 81E69B8
	.string "I was wondering which one would win,\n"
	.string "the red one or the blue one, but, oh no,\l"
	.string "it's the green one that settles things!\p"
	.string "Talk about a huge turn of events!$"

SootopolisCity_Text_1E6A50: @ 81E6A50
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between POKéMON.\p"
	.string "Well, I'm seeing that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"

SootopolisCity_Text_1E6B2A: @ 81E6B2A
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between POKéMON.\p"
	.string "Well, I saw that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"

SootopolisCity_Text_1E6BFF: @ 81E6BFF
	.string "A big POKéMON is fighting with\n"
	.string "another big POKéMON!\p"
	.string "Please, someone make them stop!$"

SootopolisCity_Text_1E6C53: @ 81E6C53
	.string "A pretty POKéMON came down from\n"
	.string "the sky…$"

SootopolisCity_Text_1E6C7C: @ 81E6C7C
	.string "Oh, no!\n"
	.string "SOOTOPOLIS CITY will get wrecked!$"

SootopolisCity_Text_1E6CA6: @ 81E6CA6
	.string "SOOTOPOLIS CITY didn't get wrecked!$"

SootopolisCity_Text_1E6CCA: @ 81E6CCA
	.string "Hm!\n"
	.string "You've come all the way to SOOTOPOLIS?\l"
	.string "You're no ordinary tourist.\p"
	.string "But I suppose that doesn't make you\n"
	.string "an extraordinary tourist, either.$"

SootopolisCity_Text_1E6D57: @ 81E6D57
	.string "The city has regained its calm…$"

SootopolisCity_Text_1E6D77: @ 81E6D77
	.string "Who might you be?\p"
	.string "This is the CAVE OF ORIGIN.\p"
	.string "The spirits of POKéMON, becalmed at\n"
	.string "MT. PYRE, are said to be revived here.\p"
	.string "Please leave.$"

SootopolisCity_Text_1E6DFE: @ 81E6DFE
	.string "A person with a strong will and\n"
	.string "superior talent…\p"
	.string "A TRAINER who has knowledge and\n"
	.string "experience of many kinds of POKéMON…\p"
	.string "If such a person were to appear, I was\n"
	.string "instructed by WALLACE to lead that\l"
	.string "TRAINER to this CAVE.$"

SootopolisCity_Text_1E6ED4: @ 81E6ED4
	.string "Oh, my…\p"
	.string "The clash between the two awakened\n"
	.string "POKéMON was quelled by the awakening\l"
	.string "of a third POKéMON…$"

SootopolisCity_Text_1E6F38: @ 81E6F38
	.string "This is the CAVE OF ORIGIN…\p"
	.string "With the passing of the crisis,\n"
	.string "the cave, too, shall sleep…$"

SootopolisCity_Text_1E6F90: @ 81E6F90
	.string "SOOTOPOLIS sprang up as a town in\n"
	.string "the crater of a volcano.\p"
	.string "If you look up at the sky, the lip of\n"
	.string "the crater is also visible.\l"
	.string "So, all you see is the sky in a circle.\p"
	.string "But that's what makes the sky above\n"
	.string "SOOTOPOLIS the most beautiful.$"

SootopolisCity_Text_1E7078: @ 81E7078
	.string "When two POKéMON that gigantic\n"
	.string "are fighting that savagely, there's\l"
	.string "not much that we can do.$"

SootopolisCity_Text_1E70D4: @ 81E70D4
	.string "When that third POKéMON flew down,\n"
	.string "I feared the worst.$"

SootopolisCity_Text_1E710B: @ 81E710B
	.string "A circle of a night sky framed by\n"
	.string "the crater of a volcano…\p"
	.string "And in that ring, stars flicker and\n"
	.string "blink as if they were alive…\l"
	.string "It's my favorite scenery.$"

SootopolisCity_Text_1E71A1: @ 81E71A1
	.string "The weather was clear this morning,\n"
	.string "but…\p"
	.string "All of a sudden, dark clouds brewed up,\n"
	.string "rain started falling in sheets, and\l"
	.string "there was thunder and lightning, too.\p"
	.string "The weather just went completely\n"
	.string "wild!\p"
	.string "Is all of this because of those\n"
	.string "POKéMON?$"

SootopolisCity_Text_1E728C: @ 81E728C
	.string "Oh?\p"
	.string "It was you who brought that flying\n"
	.string "POKéMON here?\p"
	.string "Well, aren't you amazing!$"

SootopolisCity_Text_1E72DB: @ 81E72DB
	.string "MAXIE: G… GROUDON…\n"
	.string "Please! Stop what you're doing!\p"
	.string "I know the extent of your power now!\p"
	.string "If you keep going, all HOENN, not just\n"
	.string "SOOTOPOLIS, will be utterly ruined!$"

SootopolisCity_Text_1E737E: @ 81E737E
	.string "MAXIE: So the super-ancient POKéMON\n"
	.string "weren't only GROUDON and KYOGRE…\p"
	.string "After all our fruitless scheming and\n"
	.string "frantic efforts, that one POKéMON's\l"
	.string "simple action puts everything right\l"
	.string "again as if nothing had happened…\p"
	.string "Fu…\n"
	.string "Fuhahaha…$"

SootopolisCity_Text_1E7460: @ 81E7460
	.string "ARCHIE: KYOGRE! What's wrong?!\n"
	.string "Look over here! It's the RED ORB!\l"
	.string "Calm down! KYOGRE!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "It's no good!\n"
	.string "It's not responding at all!$"

SootopolisCity_Text_1E74F6: @ 81E74F6
	.string "ARCHIE: KYOGRE and GROUDON both\n"
	.string "flew off to who knows where.\p"
	.string "The weather in HOENN has returned\n"
	.string "to its normal state…\p"
	.string "Haha…\n"
	.string "Hahaha…\p"
	.string "Maybe what we were trying to do was\n"
	.string "something small, even meaningless,\l"
	.string "to POKéMON…$"

SootopolisCity_Text_1E75CB: @ 81E75CB
	.string "STEVEN: Those POKéMON fighting…\n"
	.string "GROUDON… And KYOGRE…\p"
	.string "The two super-ancient POKéMON\n"
	.string "were awakened from a long sleep…\p"
	.string "And now they are smashing each other\n"
	.string "with their uncontrollable energy…\p"
	.string "…{PLAYER}{KUN}.\p"
	.string "You being here now I'll take to mean\n"
	.string "that you're prepared to become\l"
	.string "involved in this crisis.\p"
	.string "Well, then, there's someone that\n"
	.string "I'd like you to meet.\p"
	.string "Come with me, please.$"

SootopolisCity_Text_1E7737: @ 81E7737
	.string "STEVEN: Listen, {PLAYER}{KUN}.\p"
	.string "Does seeing GROUDON and KYOGRE make\n"
	.string "you think POKéMON are to be feared?\p"
	.string "But that's not true.\n"
	.string "POKéMON are really more…\p"
	.string "…Why am I asking you this?\n"
	.string "You already know.$"

SootopolisCity_Text_1E77F0: @ 81E77F0
	.string "STEVEN: Okay, here we are!\p"
	.string "Inside here you'll find someone named\n"
	.string "WALLACE.\p"
	.string "I think you have what's needed to\n"
	.string "help him…$"

SootopolisCity_Text_1E7866: @ 81E7866
	.string "STEVEN: I think you have what's\n"
	.string "needed to help him…$"

SootopolisCity_Text_1E789A: @ 81E789A
	.string "STEVEN: The SKY PILLAR…\p"
	.string "I've never been there.\n"
	.string "I wonder where it could be?$"

SootopolisCity_Text_1E78E5: @ 81E78E5
	.string "STEVEN: So that's RAYQUAZA…\p"
	.string "It's incredible how the two rampaging\n"
	.string "POKéMON would flee from it in fear…$"

SootopolisCity_Text_1E794B: @ 81E794B
	.string "STEVEN: It looks like both MAXIE and\n"
	.string "ARCHIE have gone away somewhere.\p"
	.string "Perhaps they've gone to MT. PYRE to\n"
	.string "return those ORBS…$"

SootopolisCity_Text_1E79C8: @ 81E79C8
	.string "WALLACE: Oh?\n"
	.string "{PLAYER}{KUN}?\p"
	.string "Haven't you scaled the SKY PILLAR\n"
	.string "yet?\p"
	.string "I'm sure that you can make it to\n"
	.string "the top of the SKY PILLAR…$"

SootopolisCity_Text_1E7A3E: @ 81E7A3E
	.string "WALLACE: {PLAYER}{KUN}…\p"
	.string "The leaders of TEAM MAGMA and AQUA,\n"
	.string "I don't think they meant harm.\p"
	.string "It wouldn't hurt to hear what they\n"
	.string "have to say for themselves.$"

SootopolisCity_Text_1E7ACF: @ 81E7ACF
	.string "WALLACE: {PLAYER}{KUN}…\n"
	.string "My eyes didn't deceive me.\p"
	.string "Thanks to your help, SOOTOPOLIS…\n"
	.string "No, all of HOENN was saved.\p"
	.string "On behalf of the people, I thank you.\p"
	.string "This is a gift from me.\n"
	.string "Please accept it.$"

SootopolisCity_Text_1E7B86: @ 81E7B86
	.string "That HIDDEN MACHINE contains\n"
	.string "WATERFALL.\p"
	.string "If you have the RAIN BADGE, a POKéMON\n"
	.string "that has learned that HM move can\l"
	.string "force its way up waterfalls.\p"
	.string "And where does one get the RAIN BADGE?\n"
	.string "You know, don't you?\p"
	.string "That's right! You have to beat\n"
	.string "the SOOTOPOLIS GYM LEADER.\p"
	.string "When you're all set to go, step through\n"
	.string "that door.$"

SootopolisCity_Text_1E7CBC: @ 81E7CBC
	.string "WALLACE: I'm sure that you will be\n"
	.string "dazzled by my mentor's breathtakingly\l"
	.string "elegant battle style.$"
