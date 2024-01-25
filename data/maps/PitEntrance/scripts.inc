PitEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PitArena_Entrance
	.byte 0

PitArena_Entrance:
	setflashlevel 0
	return

PitEntrance_Warp::
	lockall
	warpteleport MAP_PIT_ARENA, 9, 7
	waitstate
	releaseall
	end

PitEntrance_EventScript_Sign::
	msgbox PitEntrance_Text_Rules, MSGBOX_SIGN
	release
	end

PitEntrance_Text_Rules:
	.string "Welcome to the Pit of 100 Trials\p"
	.string "Beyond this point is a neverending\n"
	.string "series of rooms filled with\l"
	.string "opponents to fight.\n"
	.string "Can you survive 100 floors?$"
