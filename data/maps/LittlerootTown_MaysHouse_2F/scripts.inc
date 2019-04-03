LittlerootTown_MaysHouse_2F_MapScripts:: @ 81F9296
	map_script 3, LittlerootTown_MaysHouse_2F_MapScript1_1F92A1
	map_script 2, YamakiTown_PlayerHouseUpstairs_MapScript1
	map_script 4, LittlerootTown_MaysHouse_2F_MapScript2_1F931D
	.byte 0
	
YamakiTown_PlayerHouseUpstairs_MapScript1:
	map_script_2 VAR_0x408C, 5, YamakiTown_PlayerHouseUpstairs_EggHatch
	.2byte 0
	
YamakiTown_PlayerHouseUpstairs_EggHatch::
	lock
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouseUpstairs_Movement_DelayedFaceLeft
	waitmovement 0
	applymovement 16, YamakiTown_PlayerHouseUpstairs_Movement_EggJump
	waitmovement 0
	setflag FLAG_SYS_POKEMON_GET
	applymovement EVENT_OBJ_ID_PLAYER, YamakiTown_PlayerHouseUpstairs_Movement_StepLeft
	waitmovement 0
	fadescreen 3
	removeobject 16
	bufferleadmonspeciesname 0
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	addobject 17
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	fadescreen 2
	playmoncry SPECIES_CHARMANDER, 0
	msgbox YamakiTown_PlayerHouseUpstairs_PlaceholderCry, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	addobject 1
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	applymovement 1, YamakiTown_PlayerHouseUpstairs_Movement_SisterWallRun
	waitmovement 0
	msgbox YamakiTown_PlayerHouseUpstairs_EggHatch_Text1, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_CHARMANDER, 0
	msgbox YamakiTown_PlayerHouseUpstairs_PlaceholderCry, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	applymovement 1, YamakiTown_PlayerHouseUpstairs_Movement_HeartMark
	waitmovement 0
	msgbox YamakiTown_PlayerHouseUpstairs_EggHatch_Text2, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, YamakiTown_PlayerHouseUpstairs_Movement_CameraMoveUp
	waitmovement 0
	msgbox YamakiTown_PlayerHouseUpstairs_EggHatch_Text3, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_CAMERA, YamakiTown_PlayerHouseUpstairs_Movement_CameraMoveDown
	waitmovement 0
	special RemoveCameraObject
	applymovement 1, YamakiTown_PlayerHouseUpstairs_Movement_SisterRunDownstairs
	waitmovement 0
	removeobject 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	applymovement 17, YamakiTown_PlayerHouseUpstairs_Movement_PokemonInventory
	waitmovement 0
	removeobject 17
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_0x408C, 6
	release
	end
	
YamakiTown_PlayerHouseUpstairs_Movement_DelayedFaceLeft:
	delay_8
	face_left
	step_end
	
YamakiTown_PlayerHouseUpstairs_Movement_EggJump:
	jump_down
	step_end
	
YamakiTown_PlayerHouseUpstairs_Movement_PokemonInventory:
	jump_up
	jump_right
	step_end
	
YamakiTown_PlayerHouseUpstairs_Movement_CameraMoveUp:
	walk_up
	step_end
	
YamakiTown_PlayerHouseUpstairs_Movement_CameraMoveDown:
	walk_down
	step_end
	
YamakiTown_PlayerHouseUpstairs_Movement_StepLeft:
	walk_left
	step_end
	
YamakiTown_PlayerHouseUpstairs_Movement_HeartMark:
	walk_up
	walk_right
	walk_right
	walk_right
	emote_heart
	step_end
	
YamakiTown_PlayerHouseUpstairs_Movement_SisterWallRun:
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	jump_up
	face_down
	delay_4
	face_right
	step_end
	
YamakiTown_PlayerHouseUpstairs_Movement_SisterRunDownstairs:
	walk_fastest_left
	walk_fastest_left
	walk_fastest_left
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

YamakiTown_PlayerHouseUpstairs_EggHatch_Text1:
	.string "Sister: I heard a Pokémon!$"	

YamakiTown_PlayerHouseUpstairs_PlaceholderCry:
	.string "{COLOR POKEMON_COLOR}{STR_VAR_1}:{COLOR NO_COLOR} Placeholder cry!$"
	
YamakiTown_PlayerHouseUpstairs_EggHatch_Text2:
	.string "Oh my gosh, a {COLOR POKEMON_COLOR}{STR_VAR_1}{COLOR NO_COLOR}!\n"
	.string "It's so CUTE!\p"
	.string "I better go check on my egg! I\n"
	.string "took it downstairs this morning!$"
	
YamakiTown_PlayerHouseUpstairs_EggHatch_Text3:
	.string "Mom: Sister!\n"
	.string "There's a Pokémon in your food!$"

LittlerootTown_MaysHouse_2F_MapScript1_1F92A1: @ 81F92A1
	compare VAR_0x408D, 2
	call_if_lt LittlerootTown_MaysHouse_2F_EventScript_1F930A
	compare VAR_0x408D, 3
	call_if_ge LittlerootTown_MaysHouse_2F_EventScript_1F92CD
	compare VAR_0x4092, 4
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_2926FE
	call LittlerootTown_MaysHouse_2F_EventScript_275CE1
	setvar VAR_0x4089, 0
	end

LittlerootTown_MaysHouse_2F_EventScript_1F92CD:: @ 81F92CD
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_1F92E6
	compare VAR_0x4084, 2
	goto_if_ge LittlerootTown_MaysHouse_2F_EventScript_1F9309
	goto LittlerootTown_MaysHouse_2F_EventScript_1F92E6

LittlerootTown_MaysHouse_2F_EventScript_1F92E6:: @ 81F92E6
	checkplayergender
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_1F9309
	compare VAR_0x40D3, 2
	goto_if_ge LittlerootTown_MaysHouse_2F_EventScript_1F9309
	setobjectxyperm 1, 8, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F9309:: @ 81F9309
LittlerootTown_MaysHouse_2F_EventScript_1F9309:: @ 81F9309
	return

LittlerootTown_MaysHouse_2F_EventScript_1F930A:: @ 81F930A
	checkplayergender
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_1F9317
	return

LittlerootTown_MaysHouse_2F_EventScript_1F9317:: @ 81F9317
	setvar VAR_0x408D, 2
	return

LittlerootTown_MaysHouse_2F_MapScript2_1F931D: @ 81F931D
	map_script_2 VAR_0x4089, 0, LittlerootTown_MaysHouse_2F_EventScript_1F9327
	.2byte 0

LittlerootTown_MaysHouse_2F_EventScript_1F9327:: @ 81F9327
	checkplayergender
	compare VAR_RESULT, 1
	goto_if_eq EventScript_275D0C
	end

LittlerootTown_MaysHouse_2F_EventScript_1F9334:: @ 81F9334
	lockall
	compare VAR_0x408D, 2
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_1F934A
	msgbox LittlerootTown_MaysHouse_2F_Text_1F9991, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_1F934A:: @ 81F934A
	delay 10
	addobject 1
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F946F
	waitmovement 0
	playse SE_PIN
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_272598
	waitmovement 0
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_27259A
	waitmovement 0
	delay 10
	playbgm MUS_GIRL_SUP, 1
	compare VAR_FACING, 2
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_1F93BA
	compare VAR_FACING, 1
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_1F93E9
	compare VAR_FACING, 3
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_1F9418
	compare VAR_FACING, 4
	call_if_eq LittlerootTown_MaysHouse_2F_EventScript_1F9440
	setvar VAR_0x408D, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	setvar VAR_0x4050, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_1F93BA:: @ 81F93BA
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F9473
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_2725A4
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_1F9483
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F9479
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_1F93E9:: @ 81F93E9
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F948B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_2725A4
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_1F9497
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F948F
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_1F9418:: @ 81F9418
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F949D
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_2725A6
	waitmovement 0
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F94A4
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_1F9440:: @ 81F9440
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F94AD
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_2725A4
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_1F94BB
	applymovement 1, LittlerootTown_MaysHouse_2F_Movement_1F94B2
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_Movement_1F946F: @ 81F946F
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F9473: @ 81F9473
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F9479: @ 81F9479
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F9483: @ 81F9483
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F948B: @ 81F948B
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F948F: @ 81F948F
	walk_up
	walk_in_place_fastest_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F9497: @ 81F9497
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F949D: @ 81F949D
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F94A4: @ 81F94A4
	walk_up
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F94A9: @ 81F94A9
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F94AD: @ 81F94AD
	walk_right
	walk_right
	walk_down
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F94B2: @ 81F94B2
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_1F94BB: @ 81F94BB
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

LittlerootTown_BrendansHouse_2F_EventScript_1F94C1:: @ 81F94C1
LittlerootTown_MaysHouse_2F_EventScript_1F94C1:: @ 81F94C1
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F94E3:: @ 81F94E3
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F978A, MSGBOX_DEFAULT
	releaseall
	end

EventScript_PlayerPCFemale:: @ 81F9553
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_1F956C
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_MaysHouse_2F_EventScript_1F9576
	end

LittlerootTown_MaysHouse_2F_EventScript_1F956C:: @ 81F956C
	msgbox gUnknown_08272CD5, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_1F9576:: @ 81F9576
	setvar VAR_0x8004, 2
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gUnknown_08272D87, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_1F958F:: @ 81F958F
	setvar VAR_0x8004, 2
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_Text_1F978A: @ 81F978A
	.string "POKéMON fully restored!\n"
	.string "Items ready, and…$"

LittlerootTown_BrendansHouse_2F_Text_1F97B4: @ 81F97B4
	.string "Some other time, okay?$"

LittlerootTown_BrendansHouse_2F_Text_1F9991: @ 81F9991
LittlerootTown_MaysHouse_2F_Text_1F9991: @ 81F9991
	.string "It's {RIVAL}'s POKé BALL!\p"
	.string "Better leave it right where it is.$"

LittlerootTown_BrendansHouse_2F_Text_1F9A9E: @ 81F9A9E
	.string "MAY: I wonder where I should go catch\n"
	.string "some POKéMON next?\p"
	.string "Wouldn't it be funny if we ran into each\n"
	.string "other, {PLAYER}{KUN}?$"
