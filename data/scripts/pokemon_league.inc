PokemonLeague_EventScript_OpenDoor::
	applymovement LOCALID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	call PokemonLeague_EventScript_SetDoorOpen
	special DrawWholeMapView
	setflag FLAG_TEMP_4
	return

PokemonLeague_EventScript_EnterRoom::
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp5
	waitmovement 0
	setflag FLAG_TEMP_2
	playse SE_UNLOCK
	call PokemonLeague_EventScript_CloseEntry
	special DrawWholeMapView
	return

PokemonLeague_EventScript_SetDoorOpen::
	setmetatile 6, 1, METATILE_PokemonLeague_Door_Top_Open, 1
	setmetatile 6, 2, METATILE_PokemonLeague_Door_Mid_Open, 0
	return

PokemonLeague_EventScript_PreventExit::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Text_VoiceRangOutDontRunAway
	closemessage
	applymovement LOCALID_PLAYER, PokemonLeague_Movement_ForcePlayerIn
	waitmovement 0
	releaseall
	end

PokemonLeague_EventScript_OpenDoorLance::
	applymovement LOCALID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 4, METATILE_PokemonLeague_Door_Top_Open, 1
	setmetatile 6, 5, METATILE_PokemonLeague_Door_Mid_Open, 0
	special DrawWholeMapView
	setflag FLAG_TEMP_4
	return

PokemonLeague_EventScript_SetDoorOpenLance::
	setmetatile 6, 4, METATILE_PokemonLeague_Door_Top_Open, 1
	setmetatile 6, 5, METATILE_PokemonLeague_Door_Mid_Open, 0
	return

PokemonLeague_EventScript_CloseEntry::
	setmetatile 5, 11, METATILE_PokemonLeague_Entry_TopLeft_Closed, 1
	setmetatile 6, 11, METATILE_PokemonLeague_Entry_TopMid_Closed, 1
	setmetatile 7, 11, METATILE_PokemonLeague_Entry_TopRight_Closed, 1
	setmetatile 5, 12, METATILE_PokemonLeague_Entry_BottomLeft_Closed, 1
	setmetatile 6, 12, METATILE_PokemonLeague_Entry_BottomMid_Closed, 1
	setmetatile 7, 12, METATILE_PokemonLeague_Entry_BottomRight_Closed, 1
	return

PokemonLeague_Movement_ForcePlayerIn::
	walk_up
	step_end

PokemonLeague_EventScript_DoLightingEffect::
	special DoPokemonLeagueLightingEffect
	return

Text_VoiceRangOutDontRunAway::
	.string "Someone's voice rang out,\n"
	.string "“Don't run away!”$"
