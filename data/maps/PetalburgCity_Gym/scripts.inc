PetalburgCity_Gym_MapScripts:: @ 8204889
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_MapScript1_20492D
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_MapScript2_20498B
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_MapScript2_20499A
	.byte 0

PetalburgCity_Gym_OnTransition: @ 820489E
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_eq PetalburgCity_Gym_EventScript_2048B5
	compare VAR_PETALBURG_GYM_STATE, 7
	call_if_ge PetalburgCity_Gym_EventScript_2048FF
	end

PetalburgCity_Gym_EventScript_2048B5:: @ 82048B5
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_20555E
	checktrainerflag TRAINER_RANDALL
	call_if_eq PetalburgCity_Gym_EventScript_20557F
	checktrainerflag TRAINER_MARY
	call_if_eq PetalburgCity_Gym_EventScript_2055A0
	checktrainerflag TRAINER_PARKER
	call_if_eq PetalburgCity_Gym_EventScript_2055C1
	checktrainerflag TRAINER_ALEXIA
	call_if_eq PetalburgCity_Gym_EventScript_2055E2
	checktrainerflag TRAINER_GEORGE
	call_if_eq PetalburgCity_Gym_EventScript_205603
	checktrainerflag TRAINER_JODY
	call_if_eq PetalburgCity_Gym_EventScript_205624
	checktrainerflag TRAINER_BERKE
	call_if_eq PetalburgCity_Gym_EventScript_205645
	end

PetalburgCity_Gym_EventScript_2048FF:: @ 82048FF
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_20555E
	call PetalburgCity_Gym_EventScript_20557F
	call PetalburgCity_Gym_EventScript_2055A0
	call PetalburgCity_Gym_EventScript_2055C1
	call PetalburgCity_Gym_EventScript_2055E2
	call PetalburgCity_Gym_EventScript_205603
	call PetalburgCity_Gym_EventScript_205624
	call PetalburgCity_Gym_EventScript_205645
	return

PetalburgCity_Gym_MapScript1_20492D: @ 820492D
	compare VAR_PETALBURG_GYM_STATE, 1
	call_if_eq PetalburgCity_Gym_EventScript_20494D
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_lt PetalburgCity_Gym_EventScript_204955
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_20495D
	end

PetalburgCity_Gym_EventScript_20494D:: @ 820494D
	setobjectxyperm 10, 5, 108
	return

PetalburgCity_Gym_EventScript_204955:: @ 8204955
	setobjectxyperm 1, 4, 107
	return

PetalburgCity_Gym_EventScript_20495D:: @ 820495D
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, 269
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_204985
	compare VAR_PETALBURG_GYM_STATE, 8
	goto_if_eq PetalburgCity_Gym_EventScript_204985
	setobjectxyperm 1, 4, 107
	return

PetalburgCity_Gym_EventScript_204985:: @ 8204985
	setvar VAR_PETALBURG_GYM_STATE, 8
	end

PetalburgCity_Gym_MapScript2_20498B: @ 820498B
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_204995
	.2byte 0

PetalburgCity_Gym_EventScript_204995:: @ 8204995
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

PetalburgCity_Gym_MapScript2_20499A: @ 820499A
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_2049A4
	.2byte 0

PetalburgCity_Gym_EventScript_2049A4:: @ 82049A4
	lockall
	msgbox PetalburgCity_Gym_Text_205B32, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_205B4C, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement 10, PetalburgCity_Gym_Movement_2049EC
	waitmovement 0
	playse SE_KAIDAN
	removeobject 10
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	delay 30
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_205C40, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_GYM_STATE, 2
	releaseall
	end

PetalburgCity_Gym_Movement_2049EC: @ 82049EC
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

PetalburgCity_Gym_EventScript_2049F1:: @ 82049F1
	lock
	faceplayer
	switch VAR_PETALBURG_GYM_STATE
	case 2, PetalburgCity_Gym_EventScript_204D4A
	case 3, PetalburgCity_Gym_EventScript_204D54
	case 4, PetalburgCity_Gym_EventScript_204D5E
	case 5, PetalburgCity_Gym_EventScript_204D68
	case 6, PetalburgCity_Gym_EventScript_204E3B
	case 7, PetalburgCity_Gym_EventScript_204D80
	case 8, PetalburgCity_Gym_EventScript_204DB3
	msgbox PetalburgCity_Gym_Text_2057A2, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case 1, PetalburgCity_Gym_EventScript_204A80
	case 2, PetalburgCity_Gym_EventScript_204A8B
	case 3, PetalburgCity_Gym_EventScript_204A96
	case 4, PetalburgCity_Gym_EventScript_204AA1
	end

PetalburgCity_Gym_EventScript_204A80:: @ 8204A80
	setvar VAR_0x8008, 0
	goto PetalburgCity_Gym_EventScript_204AAC
	end

PetalburgCity_Gym_EventScript_204A8B:: @ 8204A8B
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_204AAC
	end

PetalburgCity_Gym_EventScript_204A96:: @ 8204A96
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_204AAC
	end

PetalburgCity_Gym_EventScript_204AA1:: @ 8204AA1
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_204AAC
	end

PetalburgCity_Gym_EventScript_204AAC:: @ 8204AAC
	addobject 10
	playse SE_DOOR
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_204C31
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_204C43
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_204C5F
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_204C5F
	msgbox PetalburgCity_Gym_Text_2058B1, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_2058DB, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_205910, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_2059D8, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_204CC7
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_204CD2
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_204CE4
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_204CF6
	msgbox PetalburgCity_Gym_Text_2059E8, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_204D08
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_204D13
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_204D1E
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_204D29
	msgbox PetalburgCity_Gym_Text_205A46, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_205A89, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_205AF4, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_204D72
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_204D73
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_204D7E
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_204D7F
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_204D34
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_204D3F
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_204D34
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_204D34
	msgbox PetalburgCity_Gym_Text_205B0F, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SPECIAL_FLAG_0x4001
	playbgm MUS_TSURETEK, 0
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_Gym_EventScript_204C78
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_204C91
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_204CA3
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_204CB5
	removeobject 10
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_AUNT
	setvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_PETALBURG_CITY_STATE, 2
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	special InitBirchState
	warp MAP_PETALBURG_CITY, 255, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_204C31:: @ 8204C31
	applymovement 1, Common_Movement_WalkInPlaceDown
	applymovement 10, PetalburgCity_Gym_Movement_2050EB
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204C43:: @ 8204C43
	applymovement 10, PetalburgCity_Gym_Movement_2050E1
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204C5F:: @ 8204C5F
	applymovement 1, Common_Movement_WalkInPlaceDown
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement 10, PetalburgCity_Gym_Movement_2050EB
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204C78:: @ 8204C78
	applymovement 1, Common_Movement_WalkInPlaceDown
	applymovement 10, PetalburgCity_Gym_Movement_205102
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_205111
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204C91:: @ 8204C91
	applymovement 10, PetalburgCity_Gym_Movement_2050F2
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_205109
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204CA3:: @ 8204CA3
	applymovement 10, PetalburgCity_Gym_Movement_205102
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_20511B
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204CB5:: @ 8204CB5
	applymovement 10, PetalburgCity_Gym_Movement_2050FA
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_205123
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204CC7:: @ 8204CC7
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204CD2:: @ 8204CD2
	applymovement 1, Common_Movement_WalkInPlaceDown
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204CE4:: @ 8204CE4
	applymovement 1, Common_Movement_WalkInPlaceRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204CF6:: @ 8204CF6
	applymovement 1, Common_Movement_WalkInPlaceLeft
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204D08:: @ 8204D08
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204D13:: @ 8204D13
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204D1E:: @ 8204D1E
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204D29:: @ 8204D29
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204D34:: @ 8204D34
	applymovement 10, Common_Movement_FacePlayer
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204D3F:: @ 8204D3F
	applymovement 10, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204D4A:: @ 8204D4A
	msgbox PetalburgCity_Gym_Text_205DB4, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_204D54:: @ 8204D54
	msgbox PetalburgCity_Gym_Text_205EAE, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_204D5E:: @ 8204D5E
	msgbox PetalburgCity_Gym_Text_205F87, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_204D68:: @ 8204D68
	msgbox PetalburgCity_Gym_Text_205F87, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_204D72:: @ 8204D72
	return

PetalburgCity_Gym_EventScript_204D73:: @ 8204D73
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204D7E:: @ 8204D7E
	return

PetalburgCity_Gym_EventScript_204D7F:: @ 8204D7F
	return

PetalburgCity_Gym_EventScript_204D80:: @ 8204D80
	call PetalburgCity_Gym_EventScript_204DCE
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_204E1D
	goto_if_unset FLAG_RECEIVED_TM42, PetalburgCity_Gym_EventScript_204DAC
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_20512D
	msgbox PetalburgCity_Gym_Text_206417, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_204DAC:: @ 8204DAC
	call PetalburgCity_Gym_EventScript_204ED2
	release
	end

PetalburgCity_Gym_EventScript_204DB3:: @ 8204DB3
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_2074A2, PetalburgCity_Gym_Text_2075CE, PetalburgCity_Gym_Text_20764A
	msgbox PetalburgCity_Gym_Text_2075F7, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_204DCE:: @ 8204DCE
	specialvar VAR_RESULT, IsEnigmaBerryValid
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_204E17
	checkitem ITEM_ENIGMA_BERRY, 1
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_204E17
	checkpcitem ITEM_ENIGMA_BERRY, 1
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_204E17
	compare VAR_ENIGMA_BERRY_AVAILABLE, 0
	goto_if_eq PetalburgCity_Gym_EventScript_204E17
	msgbox PetalburgCity_Gym_Text_2A6D3D, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

PetalburgCity_Gym_EventScript_204E17:: @ 8204E17
	setvar VAR_RESULT, 0
	return

PetalburgCity_Gym_EventScript_204E1D:: @ 8204E1D
	giveitem_std ITEM_ENIGMA_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
	release
	end

PetalburgCity_Gym_EventScript_204E3B:: @ 8204E3B
	msgbox PetalburgCity_Gym_Text_205FE5, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_206107
	message PetalburgCity_Gym_Text_206162
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Text_20618A, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_BADGE05_GET
	special ResetHealLocationFromDewford
	call PetalburgCity_Gym_EventScript_2721F8
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_Gym_EventScript_2048FF
	special DrawWholeMapView
	call PetalburgCity_Gym_EventScript_204ED2
	delay 30
	msgbox PetalburgCity_Gym_Text_2062FB, MSGBOX_DEFAULT
	closemessage
	delay 40
	playse SE_DOOR
	delay 10
	addobject 11
	switch VAR_FACING
	case 2, PetalburgCity_Gym_EventScript_204EF5
	case 3, PetalburgCity_Gym_EventScript_204F09
	case 4, PetalburgCity_Gym_EventScript_204EFF
	end

PetalburgCity_Gym_EventScript_204ED2:: @ 8204ED2
	giveitem_std ITEM_TM42
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM42
	msgbox PetalburgCity_Gym_Text_206254, MSGBOX_DEFAULT
	return

PetalburgCity_Gym_EventScript_204EF5:: @ 8204EF5
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_204F13

PetalburgCity_Gym_EventScript_204EFF:: @ 8204EFF
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_204F13

PetalburgCity_Gym_EventScript_204F09:: @ 8204F09
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_204F13

PetalburgCity_Gym_EventScript_204F13:: @ 8204F13
	applymovement 11, PetalburgCity_Gym_Movement_2050BB
	waitmovement 0
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 11, Common_Movement_Delay48
	waitmovement 0
	delay 10
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_204FED
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_205009
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_205025
	msgbox PetalburgCity_Gym_Text_206377, MSGBOX_DEFAULT
	closemessage
	delay 20
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_204FCC
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_204FD7
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_204FE2
	msgbox PetalburgCity_Gym_Text_2063CA, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SPECIAL_FLAG_0x4001
	playbgm MUS_TSURETEK, 0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_Gym_EventScript_205041
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_Gym_EventScript_20505A
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_Gym_EventScript_20506C
	removeobject 11
	setvar VAR_PETALBURG_CITY_STATE, 4
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_UNCLE
	warp MAP_PETALBURG_CITY, 255, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_204FCC:: @ 8204FCC
	applymovement 11, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204FD7:: @ 8204FD7
	applymovement 11, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204FE2:: @ 8204FE2
	applymovement 11, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_204FED:: @ 8204FED
	applymovement 11, PetalburgCity_Gym_Movement_2050C3
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_205009:: @ 8205009
	applymovement 11, PetalburgCity_Gym_Movement_2050CA
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_205025:: @ 8205025
	applymovement 11, PetalburgCity_Gym_Movement_2050D0
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_205041:: @ 8205041
	applymovement 11, PetalburgCity_Gym_Movement_20507E
	applymovement 1, Common_Movement_WalkInPlaceDown
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_2050A1
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_20505A:: @ 820505A
	applymovement 11, PetalburgCity_Gym_Movement_205089
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_2050A9
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_20506C:: @ 820506C
	applymovement 11, PetalburgCity_Gym_Movement_205094
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_2050B1
	waitmovement 0
	return

PetalburgCity_Gym_Movement_20507E: @ 820507E
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_205089: @ 8205089
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_205094: @ 8205094
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_2050A1: @ 82050A1
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_2050A9: @ 82050A9
	delay_16
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_2050B1: @ 82050B1
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_2050BB: @ 82050BB
	walk_up
	delay_8
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_up
	step_end

PetalburgCity_Gym_Movement_2050C3: @ 82050C3
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

PetalburgCity_Gym_Movement_2050CA: @ 82050CA
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_2050D0: @ 82050D0
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Gym_Movement_2050D8: @ 82050D8
	walk_in_place_fastest_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_down
	step_end

PetalburgCity_Gym_Movement_2050E1: @ 82050E1
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

PetalburgCity_Gym_Movement_2050EB: @ 82050EB
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_2050F2: @ 82050F2
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_2050FA: @ 82050FA
	walk_down
	walk_down
	walk_right
	walk_down
	walk_in_place_fastest_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_205102: @ 8205102
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_205109: @ 8205109
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_205111: @ 8205111
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_20511B: @ 820511B
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_205123: @ 8205123
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_EventScript_20512D:: @ 820512D
	msgbox PetalburgCity_Gym_Text_2064C3, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_205137:: @ 8205137
	lockall
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 85
	msgbox PetalburgCity_Gym_Text_20721E, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_20516C:: @ 820516C
	closemessage
	delay 30
	warpdoor MAP_PETALBURG_CITY_GYM, 255, 32776, 32777
	waitstate
	releaseall
	end

PetalburgCity_Gym_EventScript_20517B:: @ 820517B
	releaseall
	end

PetalburgCity_Gym_EventScript_20517D:: @ 820517D
	msgbox PetalburgCity_Gym_Text_2071F4, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_EventScript_205187:: @ 8205187
	lockall
	compare VAR_PETALBURG_GYM_STATE, 6
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 98
	msgbox PetalburgCity_Gym_Text_207280, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_2051BC:: @ 82051BC
	lockall
	checktrainerflag TRAINER_RANDALL
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 46
	msgbox PetalburgCity_Gym_Text_2072BB, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_2051EF:: @ 82051EF
	lockall
	checktrainerflag TRAINER_RANDALL
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_2072F7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_205222:: @ 8205222
	lockall
	checktrainerflag TRAINER_MARY
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_2072F7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_205255:: @ 8205255
	lockall
	checktrainerflag TRAINER_MARY
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 72
	msgbox PetalburgCity_Gym_Text_207331, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_205288:: @ 8205288
	lockall
	checktrainerflag TRAINER_PARKER
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_20736C, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_2052BB:: @ 82052BB
	lockall
	checktrainerflag TRAINER_ALEXIA
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_20736C, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_2052EE:: @ 82052EE
	lockall
	checktrainerflag TRAINER_ALEXIA
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_2073A7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_205321:: @ 8205321
	lockall
	checktrainerflag TRAINER_GEORGE
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_2073A7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_205354:: @ 8205354
	lockall
	checktrainerflag TRAINER_JODY
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_2073E4, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_205387:: @ 8205387
	lockall
	checktrainerflag TRAINER_BERKE
	goto_if_lt PetalburgCity_Gym_EventScript_20517D
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_2073E4, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_20516C
	compare VAR_RESULT, 0
	goto_if_eq PetalburgCity_Gym_EventScript_20517B
	end

PetalburgCity_Gym_EventScript_2053BA:: @ 82053BA
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_20674F, PetalburgCity_Gym_Text_2067B9, PetalburgCity_Gym_EventScript_2053DE
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_2053ED
	msgbox PetalburgCity_Gym_Text_2067D8, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_2053DE:: @ 82053DE
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_20557F
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_2053ED:: @ 82053ED
	msgbox PetalburgCity_Gym_Text_20685E, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_2053F6:: @ 82053F6
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_2068FD, PetalburgCity_Gym_Text_20694F, PetalburgCity_Gym_EventScript_20541A
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_205429
	msgbox PetalburgCity_Gym_Text_206996, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_20541A:: @ 820541A
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_2055C1
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_205429:: @ 8205429
	msgbox PetalburgCity_Gym_Text_2069D9, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_205432:: @ 8205432
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_206A1B, PetalburgCity_Gym_Text_206AB8, PetalburgCity_Gym_EventScript_205456
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_205465
	msgbox PetalburgCity_Gym_Text_206AE9, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_205456:: @ 8205456
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_205603
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_205465:: @ 8205465
	msgbox PetalburgCity_Gym_Text_206BB1, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_20546E:: @ 820546E
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_206BF4, PetalburgCity_Gym_Text_206C7D, PetalburgCity_Gym_EventScript_205492
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_2054A1
	msgbox PetalburgCity_Gym_Text_206C9F, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_205492:: @ 8205492
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_205645
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_2054A1:: @ 82054A1
	msgbox PetalburgCity_Gym_Text_206D56, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_2054AA:: @ 82054AA
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_206DB2, PetalburgCity_Gym_Text_206E0D, PetalburgCity_Gym_EventScript_2054CE
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_2054DD
	msgbox PetalburgCity_Gym_Text_206E26, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_2054CE:: @ 82054CE
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_2055A0
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_2054DD:: @ 82054DD
	msgbox PetalburgCity_Gym_Text_206ED8, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_2054E6:: @ 82054E6
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_206F44, PetalburgCity_Gym_Text_206F82, PetalburgCity_Gym_EventScript_20550A
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_205519
	msgbox PetalburgCity_Gym_Text_206F9F, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_20550A:: @ 820550A
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_2055E2
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_205519:: @ 8205519
	msgbox PetalburgCity_Gym_Text_207069, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_205522:: @ 8205522
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_207088, PetalburgCity_Gym_Text_2070E6, PetalburgCity_Gym_EventScript_205546
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_205555
	msgbox PetalburgCity_Gym_Text_2070FB, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_205546:: @ 8205546
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_205624
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_205555:: @ 8205555
	msgbox PetalburgCity_Gym_Text_207170, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_20555E:: @ 820555E
	setvar VAR_0x8004, 1
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_205746
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_20574B
	call PetalburgCity_Gym_EventScript_205666
	return

PetalburgCity_Gym_EventScript_20557F:: @ 820557F
	setvar VAR_0x8004, 2
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_205746
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_20574B
	call PetalburgCity_Gym_EventScript_20568B
	return

PetalburgCity_Gym_EventScript_2055A0:: @ 82055A0
	setvar VAR_0x8004, 3
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_205746
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_20574B
	call PetalburgCity_Gym_EventScript_2056B0
	return

PetalburgCity_Gym_EventScript_2055C1:: @ 82055C1
	setvar VAR_0x8004, 4
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_205746
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_20574B
	call PetalburgCity_Gym_EventScript_2056D5
	return

PetalburgCity_Gym_EventScript_2055E2:: @ 82055E2
	setvar VAR_0x8004, 5
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_205746
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_20574B
	call PetalburgCity_Gym_EventScript_2056E8
	return

PetalburgCity_Gym_EventScript_205603:: @ 8205603
	setvar VAR_0x8004, 6
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_205746
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_20574B
	call PetalburgCity_Gym_EventScript_20570D
	return

PetalburgCity_Gym_EventScript_205624:: @ 8205624
	setvar VAR_0x8004, 7
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_205746
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_20574B
	call PetalburgCity_Gym_EventScript_205720
	return

PetalburgCity_Gym_EventScript_205645:: @ 8205645
	setvar VAR_0x8004, 8
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_EventScript_205746
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_EventScript_20574B
	call PetalburgCity_Gym_EventScript_205733
	return

PetalburgCity_Gym_EventScript_205666:: @ 8205666
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_20568B:: @ 820568B
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_2056B0:: @ 82056B0
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_2056D5:: @ 82056D5
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_2056E8:: @ 82056E8
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, 0
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_20570D:: @ 820570D
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_205720:: @ 8205720
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_205733:: @ 8205733
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, 0
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, 0
	return

PetalburgCity_Gym_EventScript_205746:: @ 8205746
	special PetalburgGymSpecial1
	waitstate
	return

PetalburgCity_Gym_EventScript_20574B:: @ 820574B
	special PetalburgGymSpecial2
	return

PetalburgCity_Gym_EventScript_20574F:: @ 820574F
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_205764
	msgbox PetalburgCity_Gym_Text_206542, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_205764:: @ 8205764
	msgbox PetalburgCity_Gym_Text_2066F3, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_20576E:: @ 820576E
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_20578E
	goto PetalburgCity_Gym_EventScript_205798
	end

PetalburgCity_Gym_EventScript_20577E:: @ 820577E
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_20578E
	goto PetalburgCity_Gym_EventScript_205798
	end

PetalburgCity_Gym_EventScript_20578E:: @ 820578E
	msgbox PetalburgCity_Gym_Text_207467, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_EventScript_205798:: @ 8205798
	msgbox PetalburgCity_Gym_Text_20744C, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_Text_2057A2: @ 82057A2
	.string "DAD: Hm?\p"
	.string "Well, if it isn't {PLAYER}!\n"
	.string "So you're all finished moving in?\p"
	.string "I'm surprised that you managed to\n"
	.string "get here by yourself.\p"
	.string "Oh, I see.\n"
	.string "You're with your POKéMON.\p"
	.string "Hm… Then I guess you're going to\n"
	.string "become a TRAINER like me, {PLAYER}.\p"
	.string "That's great news!\n"
	.string "I'll be looking forward to it!$"

PetalburgCity_Gym_Text_2058B1: @ 82058B1
	.string "Um… I…\n"
	.string "I'd like to get a POKéMON, please…$"

PetalburgCity_Gym_Text_2058DB: @ 82058DB
	.string "DAD: Hm? You're… Uh… Oh, right.\n"
	.string "You're WALLY, right?$"

PetalburgCity_Gym_Text_205910: @ 8205910
	.string "WALLY: I'm going to go stay with my\n"
	.string "relatives in VERDANTURF TOWN.\p"
	.string "I thought I would be lonely by myself,\n"
	.string "so I wanted to take a POKéMON along.\p"
	.string "But I've never caught a POKéMON before.\n"
	.string "I don't know how…$"

PetalburgCity_Gym_Text_2059D8: @ 82059D8
	.string "DAD: Hm. I see.$"

PetalburgCity_Gym_Text_2059E8: @ 82059E8
	.string "DAD: {PLAYER}, you heard that,\n"
	.string "right?\p"
	.string "Go with WALLY and make sure that he\n"
	.string "safely catches a POKéMON.$"

PetalburgCity_Gym_Text_205A46: @ 8205A46
	.string "WALLY, here, I'll loan you my POKéMON.\p"
	.string "WALLY received a ZIGZAGOON!$"

PetalburgCity_Gym_Text_205A89: @ 8205A89
	.string "WALLY: Oh, wow!\n"
	.string "A POKéMON!\p"
	.string "DAD: Hm. I'll give you a POKé BALL, too.\n"
	.string "Go for it!\p"
	.string "WALLY received a POKé BALL!$"

PetalburgCity_Gym_Text_205AF4: @ 8205AF4
	.string "WALLY: Oh, wow!\n"
	.string "Thank you!$"

PetalburgCity_Gym_Text_205B0F: @ 8205B0F
	.string "{PLAYER}… Would you really come\n"
	.string "with me?$"

PetalburgCity_Gym_Text_205B32: @ 8205B32
	.string "DAD: So, did it work out?$"

PetalburgCity_Gym_Text_205B4C: @ 8205B4C
	.string "WALLY: Thank you, yes, it did.\n"
	.string "Here's your POKéMON back.\p"
	.string "{PLAYER}, thank you for coming along\n"
	.string "with me.\p"
	.string "You two are why I was able to catch\n"
	.string "my POKéMON.\p"
	.string "I promise I'll take really good\n"
	.string "care of it.\p"
	.string "Oh! My mom's waiting for me,\n"
	.string "so I have to go!\p"
	.string "Bye, {PLAYER}!$"

PetalburgCity_Gym_Text_205C40: @ 8205C40
	.string "DAD: Now…\p"
	.string "{PLAYER}, if you want to become a\n"
	.string "strong TRAINER, here's my advice.\p"
	.string "Head for RUSTBORO CITY beyond this\n"
	.string "town.\p"
	.string "There, you should challenge\n"
	.string "the GYM LEADER, ROXANNE.\p"
	.string "After her, go on to other POKéMON\n"
	.string "GYMS and defeat their LEADERS.\p"
	.string "Collect BADGES from them,\n"
	.string "understood?\p"
	.string "Of course, I'm a GYM LEADER, too.\n"
	.string "We'll battle one day, {PLAYER}.\p"
	.string "But that's only after you become\n"
	.string "stronger.$"

PetalburgCity_Gym_Text_205DB4: @ 8205DB4
	.string "DAD: Hm? Aren't you going to the\n"
	.string "POKéMON GYM in RUSTBORO CITY?\p"
	.string "There's no challenge for me to\n"
	.string "battle a greenhorn TRAINER.\p"
	.string "{PLAYER}, I want you to challenge me\n"
	.string "when you become a lot stronger.\p"
	.string "I'll battle you, {PLAYER}, when you\n"
	.string "can show me four GYM BADGES, okay?$"

PetalburgCity_Gym_Text_205EAE: @ 8205EAE
	.string "DAD: I see… So, you've beaten\n"
	.string "the GYM LEADER in RUSTBORO CITY.\p"
	.string "But there are many more TRAINERS\n"
	.string "who are stronger than you, {PLAYER}.\p"
	.string "Across the sea in DEWFORD TOWN is a\n"
	.string "GYM LEADER named BRAWLY.\p"
	.string "You should go challenge him.$"

PetalburgCity_Gym_Text_205F87: @ 8205F87
	.string "DAD: Hm… {PLAYER}, you have gotten\n"
	.string "stronger.\p"
	.string "I can tell by the number of BADGES\n"
	.string "that you've earned.$"

PetalburgCity_Gym_Text_205FE5: @ 8205FE5
	.string "DAD: Hm…\n"
	.string "So, you did get four GYM BADGES.\p"
	.string "Fine, as I promised, we will have\n"
	.string "a POKéMON battle.\p"
	.string "{PLAYER}…\p"
	.string "I'm so happy that I can have\n"
	.string "a real battle with my own child.\p"
	.string "But, a battle is a battle!\p"
	.string "I will do everything in my power as\n"
	.string "a GYM LEADER to win.\p"
	.string "{PLAYER}, you'd better give it your\n"
	.string "best shot, too!$"

PetalburgCity_Gym_Text_206107: @ 8206107
	.string "…\p"
	.string "I… I can't…\p"
	.string "I can't believe it. {PLAYER}…\p"
	.string "I lost to {PLAYER}?\p"
	.string "But, rules are rules!\n"
	.string "Here, take this.$"

PetalburgCity_Gym_Text_206162: @ 8206162
	.string "{PLAYER} received the BALANCE BADGE\n"
	.string "from DAD!$"

PetalburgCity_Gym_Text_20618A: @ 820618A
	.string "DAD: With that BADGE, the DEFENSE\n"
	.string "of all your POKéMON will increase.\p"
	.string "POKéMON that know the HM move SURF\n"
	.string "will be able to travel over water.\p"
	.string "This is my gift to you. {PLAYER}, I'm\n"
	.string "sure you can use it correctly.$"

PetalburgCity_Gym_Text_206254: @ 8206254
	.string "DAD: TM42 contains FACADE.\p"
	.string "It doubles the power of moves if\n"
	.string "the POKéMON is poisoned, paralyzed,\l"
	.string "or burned.\p"
	.string "It might be able to turn a bad\n"
	.string "situation into an advantage.$"

PetalburgCity_Gym_Text_2062FB: @ 82062FB
	.string "DAD: As the GYM LEADER, I can't\n"
	.string "express how upset I am…\p"
	.string "But as a father, it makes me both\n"
	.string "happy and a little sad. It's odd…$"

PetalburgCity_Gym_Text_206377: @ 8206377
	.string "Ah, there you are, {PLAYER}{KUN}!\p"
	.string "Please come with me.\n"
	.string "I have something I want you to have.$"

PetalburgCity_Gym_Text_2063CA: @ 82063CA
	.string "NORMAN, you don't mind, do you?\p"
	.string "Let me borrow your {PLAYER}{KUN} for\n"
	.string "a minute or two.$"

PetalburgCity_Gym_Text_206417: @ 8206417
	.string "DAD: {PLAYER}, you should go visit\n"
	.string "your mother every so often.\p"
	.string "I'm going to stay here and redouble\n"
	.string "my training.\p"
	.string "It would bother me as a TRAINER to\n"
	.string "not avenge my loss to you, {PLAYER}!$"

PetalburgCity_Gym_Text_2064C3: @ 82064C3
	.string "DAD: {PLAYER}, how are things going?\p"
	.string "The world of POKéMON is deep.\p"
	.string "I honestly think that no amount of\n"
	.string "training would ever be enough.$"

PetalburgCity_Gym_Text_206542: @ 8206542
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "The doors in this GYM open when you\n"
	.string "beat the awaiting TRAINERS.\p"
	.string "Whoops! The doors in this room are\n"
	.string "already open, so don't attack me!\p"
	.string "The TRAINERS of PETALBURG GYM\n"
	.string "use all kinds of items.\p"
	.string "The door at the left leads to\n"
	.string "the SPEED ROOM.\p"
	.string "The door at the right leads to\n"
	.string "the ACCURACY ROOM.\p"
	.string "The room's name will be on\n"
	.string "the door, so choose carefully.\p"
	.string "Once you've chosen the door…\n"
	.string "Well, hey, go for it!$"

PetalburgCity_Gym_Text_2066F3: @ 82066F3
	.string "{PLAYER}! Whoa! You've overcome even\n"
	.string "your own father!\p"
	.string "Like, whoa!\n"
	.string "What a stunning turn of events!$"

PetalburgCity_Gym_Text_20674F: @ 820674F
	.string "The ability to attack before the\n"
	.string "opponent…\p"
	.string "Just that alone puts me at a great\n"
	.string "advantage, don't you agree?$"

PetalburgCity_Gym_Text_2067B9: @ 82067B9
	.string "That was a magnificent battle!$"

PetalburgCity_Gym_Text_2067D8: @ 82067D8
	.string "Go on to the next room where a new\n"
	.string "challenge awaits you.\p"
	.string "At the left is the CONFUSION ROOM.\p"
	.string "The right door leads to the DEFENSE\n"
	.string "ROOM.$"

PetalburgCity_Gym_Text_20685E: @ 820685E
	.string "Whomever you beat, and whomever you\n"
	.string "may lose to, you never shirk from\l"
	.string "training yourself and your POKéMON.\p"
	.string "That's what I think being a\n"
	.string "GYM LEADER is all about.$"

PetalburgCity_Gym_Text_2068FD: @ 82068FD
	.string "This is the CONFUSION ROOM.\p"
	.string "Let me see how well bonded you are\n"
	.string "with your POKéMON!$"

PetalburgCity_Gym_Text_20694F: @ 820694F
	.string "I couldn't confuse your team enough…\n"
	.string "You share a strong bond together.$"

PetalburgCity_Gym_Text_206996: @ 8206996
	.string "The next room is the STRENGTH ROOM.\n"
	.string "Can you withstand brute force?$"

PetalburgCity_Gym_Text_2069D9: @ 82069D9
	.string "After you beat our LEADER, the\n"
	.string "training has become a lot tougher.$"

PetalburgCity_Gym_Text_206A1B: @ 8206A1B
	.string "Just when you think you're going to\n"
	.string "win, your opponent restores HP…\p"
	.string "Can you just imagine how awful that\n"
	.string "must feel?\p"
	.string "I'll show you exactly how awful it\n"
	.string "feels!$"

PetalburgCity_Gym_Text_206AB8: @ 8206AB8
	.string "I couldn't restore HP enough…\n"
	.string "What ATTACK power…$"

PetalburgCity_Gym_Text_206AE9: @ 8206AE9
	.string "I should have expected no less from\n"
	.string "our LEADER's kid.\p"
	.string "No, wait! A TRAINER's abilities are\n"
	.string "earned only through effort.\p"
	.string "I lost because my own efforts\n"
	.string "weren't enough.\p"
	.string "Go on! The ONE-HIT KO ROOM is next.$"

PetalburgCity_Gym_Text_206BB1: @ 8206BB1
	.string "I'm going to keep training at GYMS.\n"
	.string "One day, I'll become a LEADER.$"

PetalburgCity_Gym_Text_206BF4: @ 8206BF4
	.string "I'm not going to take it easy just\n"
	.string "because you're our LEADER's kid.\p"
	.string "I'll show you how horrid it is for\n"
	.string "a POKéMON to take a critical hit!$"

PetalburgCity_Gym_Text_206C7D: @ 8206C7D
	.string "Your power…\n"
	.string "You're the real deal.$"

PetalburgCity_Gym_Text_206C9F: @ 8206C9F
	.string "Your father really is strong.\n"
	.string "He's a TRAINER worth my respect.\p"
	.string "And, I sense the same glow coming\n"
	.string "from you as your father.\p"
	.string "I hope that you'll stage a terrific\n"
	.string "battle with your father!$"

PetalburgCity_Gym_Text_206D56: @ 8206D56
	.string "Since your dad became the LEADER,\n"
	.string "the TRAINERS of PETALBURG CITY have\l"
	.string "become a lot tougher.$"

PetalburgCity_Gym_Text_206DB2: @ 8206DB2
	.string "Giggle…\n"
	.string "This is the ACCURACY ROOM.\p"
	.string "It's pretty nasty when every attack\n"
	.string "lands without fail.$"

PetalburgCity_Gym_Text_206E0D: @ 8206E0D
	.string "You were a cut above me…$"

PetalburgCity_Gym_Text_206E26: @ 8206E26
	.string "There are some even stronger\n"
	.string "TRAINERS waiting for you.\p"
	.string "The left is the DEFENSE ROOM, and\n"
	.string "the right is the RECOVERY ROOM.\p"
	.string "Your POKéMON's ATTACK power will be\n"
	.string "on trial either way.$"

PetalburgCity_Gym_Text_206ED8: @ 8206ED8
	.string "Do you know what we're trying to\n"
	.string "achieve as TRAINERS?\p"
	.string "We're striving to become soul mates\n"
	.string "with our POKéMON.$"

PetalburgCity_Gym_Text_206F44: @ 8206F44
	.string "The higher the DEFENSE, the more\n"
	.string "reckless I can be in attack.$"

PetalburgCity_Gym_Text_206F82: @ 8206F82
	.string "Our defenses weren't enough…$"

PetalburgCity_Gym_Text_206F9F: @ 8206F9F
	.string "I think you've taught me a valuable\n"
	.string "lesson here.\p"
	.string "Now, go on! The left door goes to\n"
	.string "the STRENGTH ROOM.\p"
	.string "The right door opens to\n"
	.string "the ONE-HIT KO ROOM.\p"
	.string "Both of them have TRAINERS who are\n"
	.string "skilled at offense.$"

PetalburgCity_Gym_Text_207069: @ 8207069
	.string "Hi! Have you tried using SURF?$"

PetalburgCity_Gym_Text_207088: @ 8207088
	.string "Our GYM LEADER told us to go all out\n"
	.string "and beat you.\p"
	.string "Even if you happen to be the\n"
	.string "LEADER's kid!$"

PetalburgCity_Gym_Text_2070E6: @ 82070E6
	.string "But… I went all out!$"

PetalburgCity_Gym_Text_2070FB: @ 82070FB
	.string "The way you use your POKéMON…\n"
	.string "It's like your father's style.\p"
	.string "Go on through! The GYM LEADER, your\n"
	.string "father, is waiting!$"

PetalburgCity_Gym_Text_207170: @ 8207170
	.string "Sure, it's fine to make your POKéMON\n"
	.string "stronger.\p"
	.string "But what decides the winner?\p"
	.string "Why, it's the feelings TRAINERS have\n"
	.string "for their POKéMON.$"

PetalburgCity_Gym_Text_2071F4: @ 82071F4
	.string "This door appears to be locked\n"
	.string "right now…$"

PetalburgCity_Gym_Text_20721E: @ 820721E
	.string "“SPEED ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_207256: @ 8207256
	.string "This door appears to be locked\n"
	.string "right now…$"

PetalburgCity_Gym_Text_207280: @ 8207280
	.string "“ACCURACY ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_2072BB: @ 82072BB
	.string "“CONFUSION ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_2072F7: @ 82072F7
	.string "“DEFENSE ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_207331: @ 8207331
	.string "“RECOVERY ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_20736C: @ 820736C
	.string "“STRENGTH ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_2073A7: @ 82073A7
	.string "“ONE-HIT KO ROOM,” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_2073E4: @ 82073E4
	.string "“GYM LEADER'S ROOM\p"
	.string "“See for yourself what POKéMON await\n"
	.string "you!” the sign says.\p"
	.string "Do you want to go through?$"

PetalburgCity_Gym_Text_20744C: @ 820744C
	.string "PETALBURG CITY POKéMON GYM$"

PetalburgCity_Gym_Text_207467: @ 8207467
	.string "PETALBURG CITY POKéMON GYM\p"
	.string "NORMAN'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

PetalburgCity_Gym_Text_2074A2: @ 82074A2
	.string "DAD: {PLAYER}…\n"
	.string "I had a feeling that you would come.\p"
	.string "I would never refuse to accept\n"
	.string "a challenge from you.\p"
	.string "You do understand, don't you?\p"
	.string "Inside a GYM, it doesn't matter that\n"
	.string "we are a parent and child.\p"
	.string "…No, because we are parent and child,\n"
	.string "we owe it to each other to do the best\l"
	.string "we can. Isn't that right, {PLAYER}?$"

PetalburgCity_Gym_Text_2075CE: @ 82075CE
	.string "Uh… Haha…\n"
	.string "Maybe that was going too hard…$"

PetalburgCity_Gym_Text_2075F7: @ 82075F7
	.string "DAD: {PLAYER}…\n"
	.string "What is your dream?\p"
	.string "My dream…\n"
	.string "Hahaha…\l"
	.string "It has already come true, actually.$"

PetalburgCity_Gym_Text_20764A: @ 820764A
	.string "DAD: {PLAYER}…\n"
	.string "I had a feeling that you would come.\p"
	.string "I would never refuse to accept\n"
	.string "a challenge from you.\p"
	.string "You do understand, don't you?\p"
	.string "Inside a GYM, it doesn't matter that\n"
	.string "we are a parent and child.\p"
	.string "Hm? Wait a second, {PLAYER}.\p"
	.string "Do you only have one POKéMON that is\n"
	.string "capable of battle?\p"
	.string "Sorry, but you'll have to come back\n"
	.string "with at least two POKéMON.$"

