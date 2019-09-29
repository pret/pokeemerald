Route110_MapScripts:: @ 81EF269
	map_script MAP_SCRIPT_ON_RESUME, Route110_MapScript1_1EF279
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_MapScript2_1EF297
	.byte 0

Route110_MapScript1_1EF279: @ 81EF279
	special UpdateCyclingRoadState
	end

Route110_OnTransition: @ 81EF27D
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_CYCLING_CHALLENGE_STATE, 1
	call_if_eq Route110_EventScript_1EF293
	end

Route110_EventScript_1EF293:: @ 81EF293
	savebgm MUS_CYCLING
	return

Route110_MapScript2_1EF297: @ 81EF297
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_1EF2A1
	.2byte 0

Route110_EventScript_1EF2A1:: @ 81EF2A1
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_1EF2AA:: @ 81EF2AA
	lock
	faceplayer
	msgbox Route110_Text_1EFB5D, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_1EF2C0:: @ 81EF2C0
	lock
	faceplayer
	msgbox Route110_Text_1EFB93, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_1EF2D6:: @ 81EF2D6
	lock
	faceplayer
	msgbox Route110_Text_1EFBCA, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_1EF2EC:: @ 81EF2EC
	lock
	faceplayer
	msgbox Route110_Text_1EFC0D, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_1EF302:: @ 81EF302
	msgbox Route110_Text_1EFFC3, MSGBOX_NPC
	end

Route110_EventScript_1EF30B:: @ 81EF30B
	msgbox Route110_Text_1F0006, MSGBOX_NPC
	end

Route110_EventScript_1EF314:: @ 81EF314
	msgbox Route110_Text_1F006A, MSGBOX_NPC
	end

Route110_EventScript_1EF31D:: @ 81EF31D
	msgbox Route110_Text_1F0261, MSGBOX_NPC
	end

Route110_EventScript_1EF326:: @ 81EF326
	msgbox Route110_Text_1F02CA, MSGBOX_NPC
	end

Route110_EventScript_1EF32F:: @ 81EF32F
	msgbox Route110_Text_1F030E, MSGBOX_NPC
	end

Route110_EventScript_1EF338:: @ 81EF338
	msgbox Route110_Text_1F0390, MSGBOX_NPC
	end

Route110_EventScript_1EF341:: @ 81EF341
	msgbox Route110_Text_1F0812, MSGBOX_SIGN
	end

Route110_EventScript_1EF34A:: @ 81EF34A
	msgbox Route110_Text_1F082D, MSGBOX_SIGN
	end

Route110_EventScript_1EF353:: @ 81EF353
	msgbox Route110_Text_1F0842, MSGBOX_SIGN
	end

Route110_EventScript_1EF35C:: @ 81EF35C
	msgbox Route110_Text_1F08CD, MSGBOX_SIGN
	end

Route110_EventScript_1EF365:: @ 81EF365
	msgbox Route110_Text_1F08E3, MSGBOX_SIGN
	end

Route110_EventScript_1EF36E:: @ 81EF36E
	msgbox Route110_Text_1F08F3, MSGBOX_SIGN
	end

Route110_EventScript_1EF377:: @ 81EF377
	msgbox Route110_Text_1F090D, MSGBOX_SIGN
	end

Route110_EventScript_1EF380:: @ 81EF380
	msgbox Route110_Text_1F0992, MSGBOX_SIGN
	end

Route110_EventScript_1EF389:: @ 81EF389
	msgbox Route110_Text_1F09DB, MSGBOX_SIGN
	end

Route110_EventScript_1EF392:: @ 81EF392
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	compare VAR_RESULT, 0
	goto_if_eq Route110_EventScript_1EF3AD
	msgbox Route110_Text_1F0A1E, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_1EF3AD:: @ 81EF3AD
	msgbox Route110_Text_1F0A5E, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_1EF3B7:: @ 81EF3B7
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_1EF3E8
	compare VAR_CYCLING_CHALLENGE_STATE, 0
	goto_if_eq Route110_EventScript_1EF3DE
	msgbox Route110_Text_1F06FB, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_1EF3DE:: @ 81EF3DE
	msgbox Route110_Text_1F0661, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_1EF3E8:: @ 81EF3E8
	msgbox Route110_Text_1F0755, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_1EF3F2:: @ 81EF3F2
	trainerbattle_single TRAINER_EDWARD, Route110_Text_29802B, Route110_Text_298064
	msgbox Route110_Text_29808A, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF409:: @ 81EF409
	trainerbattle_single TRAINER_JACLYN, Route110_Text_2980B9, Route110_Text_2980E5
	msgbox Route110_Text_2980F8, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF420:: @ 81EF420
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_29815E, Route110_Text_29818F, Route110_EventScript_1EF44C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_1EF46B
	msgbox Route110_Text_2981B3, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_1EF44C:: @ 81EF44C
	special sub_80B4808
	waitmovement 0
	msgbox Route110_Text_298201, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end

Route110_EventScript_1EF46B:: @ 81EF46B
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_298232, Route110_Text_298288
	msgbox Route110_Text_2982A2, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF482:: @ 81EF482
	trainerbattle_single TRAINER_DALE, Route110_Text_2982CC, Route110_Text_2982F5
	msgbox Route110_Text_298303, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF499:: @ 81EF499
	trainerbattle_single TRAINER_JACOB, Route110_Text_297B3F, Route110_Text_297B77
	msgbox Route110_Text_297B8F, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF4B0:: @ 81EF4B0
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_297BE7, Route110_Text_297C0F
	msgbox Route110_Text_297C1F, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF4C7:: @ 81EF4C7
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_297C63, Route110_Text_297C8A, Route110_EventScript_1EF4F3
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_1EF512
	msgbox Route110_Text_297CB4, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_1EF4F3:: @ 81EF4F3
	special sub_80B4808
	waitmovement 0
	msgbox Route110_Text_297CFE, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_1EF512:: @ 81EF512
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_297D4B, Route110_Text_297D8E
	msgbox Route110_Text_297DB0, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF529:: @ 81EF529
	trainerbattle_single TRAINER_JASMINE, Route110_Text_297F93, Route110_Text_297FD0
	msgbox Route110_Text_297FF1, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF540:: @ 81EF540
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_297DFA, Route110_Text_297E69, Route110_EventScript_1EF56C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_1EF58B
	msgbox Route110_Text_297E88, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_1EF56C:: @ 81EF56C
	special sub_80B4808
	waitmovement 0
	msgbox Route110_Text_297ECD, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end

Route110_EventScript_1EF58B:: @ 81EF58B
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_297F09, Route110_Text_297F37
	msgbox Route110_Text_297F58, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF5A2:: @ 81EF5A2
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_298349, Route110_Text_298389, Route110_EventScript_1EF5CE
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_1EF5ED
	msgbox Route110_Text_2983A2, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_1EF5CE:: @ 81EF5CE
	special sub_80B4808
	waitmovement 0
	msgbox Route110_Text_2983EE, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end

Route110_EventScript_1EF5ED:: @ 81EF5ED
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_298466, Route110_Text_2984AF
	msgbox Route110_Text_2984C8, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF604:: @ 81EF604
	trainerbattle_single TRAINER_TIMMY, Route110_Text_298525, Route110_Text_298559
	msgbox Route110_Text_298579, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF61B:: @ 81EF61B
	end

Route110_EventScript_1EF61C:: @ 81EF61C
	trainerbattle_single TRAINER_KALEB, Route110_Text_2986ED, Route110_Text_298735
	msgbox Route110_Text_298755, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF633:: @ 81EF633
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_298642, Route110_Text_298686
	msgbox Route110_Text_2986A9, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF64A:: @ 81EF64A
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_2985AB, Route110_Text_2985F9
	msgbox Route110_Text_298612, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_1EF661:: @ 81EF661
	lockall
	applymovement 21, Common_Movement_WalkInPlaceRight
	waitmovement 0
	call Route110_EventScript_1EF673
	releaseall
	end

Route110_EventScript_1EF673:: @ 81EF673
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_1F03FF, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_1EF6FD
	case 9, Route110_EventScript_1EF70B
	case 8, Route110_EventScript_1EF70B
	case 7, Route110_EventScript_1EF70B
	case 6, Route110_EventScript_1EF719
	case 5, Route110_EventScript_1EF719
	case 4, Route110_EventScript_1EF719
	case 3, Route110_EventScript_1EF727
	case 2, Route110_EventScript_1EF727
	case 1, Route110_EventScript_1EF727
	case 0, Route110_EventScript_1EF735
	end

Route110_EventScript_1EF6FD:: @ 81EF6FD
	msgbox Route110_Text_1F0431, MSGBOX_DEFAULT
	goto Route110_EventScript_1EF743
	end

Route110_EventScript_1EF70B:: @ 81EF70B
	msgbox Route110_Text_1F04A4, MSGBOX_DEFAULT
	goto Route110_EventScript_1EF743
	end

Route110_EventScript_1EF719:: @ 81EF719
	msgbox Route110_Text_1F0500, MSGBOX_DEFAULT
	goto Route110_EventScript_1EF743
	end

Route110_EventScript_1EF727:: @ 81EF727
	msgbox Route110_Text_1F0567, MSGBOX_DEFAULT
	goto Route110_EventScript_1EF743
	end

Route110_EventScript_1EF735:: @ 81EF735
	msgbox Route110_Text_1F05CE, MSGBOX_DEFAULT
	goto Route110_EventScript_1EF743
	end

Route110_EventScript_1EF743:: @ 81EF743
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_1EF74D:: @ 81EF74D
	setvar VAR_0x8008, 1
	goto Route110_EventScript_1EF76E
	end

Route110_EventScript_1EF758:: @ 81EF758
	setvar VAR_0x8008, 2
	goto Route110_EventScript_1EF76E
	end

Route110_EventScript_1EF763:: @ 81EF763
	setvar VAR_0x8008, 3
	goto Route110_EventScript_1EF76E
	end

Route110_EventScript_1EF76E:: @ 81EF76E
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route110_EventScript_1EF7E1
	compare VAR_RESULT, FEMALE
	call_if_eq Route110_EventScript_1EF7E6
	applymovement 28, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement 28, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 28, Common_Movement_Delay48
	waitmovement 0
	delay 30
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_1EF94E
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_1EF959
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_1EF964
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route110_EventScript_1EF7EB
	compare VAR_RESULT, FEMALE
	goto_if_eq Route110_EventScript_1EF865
	releaseall
	end

Route110_EventScript_1EF7E1:: @ 81EF7E1
	playbgm MUS_GIRL_SUP, 1
	return

Route110_EventScript_1EF7E6:: @ 81EF7E6
	playbgm MUS_BOY_SUP, 1
	return

Route110_EventScript_1EF7EB:: @ 81EF7EB
	msgbox Route110_Text_1EFC48, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_1EF81A
	case 1, Route110_EventScript_1EF82A
	case 2, Route110_EventScript_1EF83A
	end

Route110_EventScript_1EF81A:: @ 81EF81A
	trainerbattle_no_intro TRAINER_MAY_5, Route110_Text_1EFCCB
	goto Route110_EventScript_1EF84A
	end

Route110_EventScript_1EF82A:: @ 81EF82A
	trainerbattle_no_intro TRAINER_MAY_8, Route110_Text_1EFCCB
	goto Route110_EventScript_1EF84A
	end

Route110_EventScript_1EF83A:: @ 81EF83A
	trainerbattle_no_intro TRAINER_MAY_2, Route110_Text_1EFCCB
	goto Route110_EventScript_1EF84A
	end

Route110_EventScript_1EF84A:: @ 81EF84A
	msgbox Route110_Text_1EFCF1, MSGBOX_DEFAULT
	call Route110_EventScript_1EF8DF
	msgbox Route110_Text_1EFD58, MSGBOX_DEFAULT
	goto Route110_EventScript_1EF8EC
	end

Route110_EventScript_1EF865:: @ 81EF865
	msgbox Route110_Text_1EFE3F, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_1EF894
	case 1, Route110_EventScript_1EF8A4
	case 2, Route110_EventScript_1EF8B4
	end

Route110_EventScript_1EF894:: @ 81EF894
	trainerbattle_no_intro TRAINER_BRENDAN_5, Route110_Text_1EFEB4
	goto Route110_EventScript_1EF8C4
	end

Route110_EventScript_1EF8A4:: @ 81EF8A4
	trainerbattle_no_intro TRAINER_BRENDAN_8, Route110_Text_1EFEB4
	goto Route110_EventScript_1EF8C4
	end

Route110_EventScript_1EF8B4:: @ 81EF8B4
	trainerbattle_no_intro TRAINER_BRENDAN_2, Route110_Text_1EFEB4
	goto Route110_EventScript_1EF8C4
	end

Route110_EventScript_1EF8C4:: @ 81EF8C4
	msgbox Route110_Text_1EFECD, MSGBOX_DEFAULT
	call Route110_EventScript_1EF8DF
	msgbox Route110_Text_1EFF1C, MSGBOX_DEFAULT
	goto Route110_EventScript_1EF8EC
	end

Route110_EventScript_1EF8DF:: @ 81EF8DF
	giveitem_std ITEM_ITEMFINDER
	return

Route110_EventScript_1EF8EC:: @ 81EF8EC
	closemessage
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_1EF990
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_1EF998
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_1EF9A0
	setobjectmovementtype 28, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 29, MOVEMENT_TYPE_FACE_RIGHT
	removeobject 28
	addobject 29
	delay 45
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_1EF96F
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_1EF97A
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_1EF985
	removeobject 29
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_1EF94E:: @ 81EF94E
	applymovement 28, Route110_Movement_1EF9A8
	waitmovement 0
	return

Route110_EventScript_1EF959:: @ 81EF959
	applymovement 28, Route110_Movement_1EF9AC
	waitmovement 0
	return

Route110_EventScript_1EF964:: @ 81EF964
	applymovement 28, Route110_Movement_1EF9AE
	waitmovement 0
	return

Route110_EventScript_1EF96F:: @ 81EF96F
	applymovement 29, Route110_Movement_1EF9B2
	waitmovement 0
	return

Route110_EventScript_1EF97A:: @ 81EF97A
	applymovement 29, Route110_Movement_1EF9BA
	waitmovement 0
	return

Route110_EventScript_1EF985:: @ 81EF985
	applymovement 29, Route110_Movement_1EF9C3
	waitmovement 0
	return

Route110_EventScript_1EF990:: @ 81EF990
	setobjectxyperm 29, 33, 55
	return

Route110_EventScript_1EF998:: @ 81EF998
	setobjectxyperm 29, 34, 55
	return

Route110_EventScript_1EF9A0:: @ 81EF9A0
	setobjectxyperm 29, 35, 55
	return

Route110_Movement_1EF9A8: @ 81EF9A8
	walk_down
	walk_left
	walk_in_place_fastest_down
	step_end

Route110_Movement_1EF9AC: @ 81EF9AC
	walk_down
	step_end

Route110_Movement_1EF9AE: @ 81EF9AE
	walk_down
	walk_right
	walk_in_place_fastest_down
	step_end

Route110_Movement_1EF9B2: @ 81EF9B2
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_1EF9BA: @ 81EF9BA
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_1EF9C3: @ 81EF9C3
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_1EF9CB:: @ 81EF9CB
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_1EF9F7

Route110_EventScript_1EF9D6:: @ 81EF9D6
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_1EF9F7

Route110_EventScript_1EF9E1:: @ 81EF9E1
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_1EF9F7

Route110_EventScript_1EF9EC:: @ 81EF9EC
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_1EF9F7

Route110_EventScript_1EF9F7:: @ 81EF9F7
	addobject 36
	applymovement 36, Route110_Movement_1EFB30
	waitmovement 0
	playse SE_PIN
	applymovement 36, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 36, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_1EFAD8
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_1EFAE3
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_1EFAEE
	compare VAR_0x8008, 4
	call_if_eq Route110_EventScript_1EFAF9
	msgbox Route110_Text_1F0AB5, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement 36, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 10
	applymovement 36, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 20
	applymovement 36, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_1F0AFF, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox Route110_Text_1F0C0C, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_1F0C33, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_1EFB04
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_1EFB0F
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_1EFB1A
	compare VAR_0x8008, 4
	call_if_eq Route110_EventScript_1EFB25
	removeobject 36
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_1EFAD8:: @ 81EFAD8
	applymovement 36, Route110_Movement_1EFB34
	waitmovement 0
	return

Route110_EventScript_1EFAE3:: @ 81EFAE3
	applymovement 36, Route110_Movement_1EFB39
	waitmovement 0
	return

Route110_EventScript_1EFAEE:: @ 81EFAEE
	applymovement 36, Route110_Movement_1EFB3D
	waitmovement 0
	return

Route110_EventScript_1EFAF9:: @ 81EFAF9
	applymovement 36, Route110_Movement_1EFB40
	waitmovement 0
	return

Route110_EventScript_1EFB04:: @ 81EFB04
	applymovement 36, Route110_Movement_1EFB44
	waitmovement 0
	return

Route110_EventScript_1EFB0F:: @ 81EFB0F
	applymovement 36, Route110_Movement_1EFB4B
	waitmovement 0
	return

Route110_EventScript_1EFB1A:: @ 81EFB1A
	applymovement 36, Route110_Movement_1EFB51
	waitmovement 0
	return

Route110_EventScript_1EFB25:: @ 81EFB25
	applymovement 36, Route110_Movement_1EFB57
	waitmovement 0
	return

Route110_Movement_1EFB30: @ 81EFB30
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_1EFB34: @ 81EFB34
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_1EFB39: @ 81EFB39
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_1EFB3D: @ 81EFB3D
	walk_down
	walk_down
	step_end

Route110_Movement_1EFB40: @ 81EFB40
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_1EFB44: @ 81EFB44
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_1EFB4B: @ 81EFB4B
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_1EFB51: @ 81EFB51
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_1EFB57: @ 81EFB57
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_1EFB5D: @ 81EFB5D
	.string "TEAM AQUA's activities…\n"
	.string "We can't talk about them yet.$"

Route110_Text_1EFB93: @ 81EFB93
	.string "I want to get going to SLATEPORT and\n"
	.string "kick up a ruckus!$"

Route110_Text_1EFBCA: @ 81EFBCA
	.string "This is my first job after joining\n"
	.string "TEAM AQUA. It's a little scary.$"

Route110_Text_1EFC0D: @ 81EFC0D
	.string "TEAM AQUA's actions should bring\n"
	.string "smiles to people's faces!$"

Route110_Text_1EFC48: @ 81EFC48
	.string "MAY: Hi, {PLAYER}{KUN}, long time no see!\p"
	.string "While I was searching for other\n"
	.string "POKéMON, my POKéMON grew stronger.\p"
	.string "So…\n"
	.string "How about a little battle?$"

Route110_Text_1EFCCB: @ 81EFCCB
	.string "Yikes!\n"
	.string "You're better than I expected!$"

Route110_Text_1EFCF1: @ 81EFCF1
	.string "MAY: {PLAYER}{KUN}, you've been busy\n"
	.string "training, too, haven't you?\p"
	.string "I think you deserve a reward!\n"
	.string "This is from me!$"

Route110_Text_1EFD58: @ 81EFD58
	.string "MAY: That's an ITEMFINDER.\p"
	.string "Try it out. If there is an item that's\n"
	.string "not visible, it emits a sound.\p"
	.string "Okay, {PLAYER}{KUN}, let's meet again!\p"
	.string "I know it's a little silly coming from\n"
	.string "me, but I think you should train a lot\l"
	.string "harder for the next time.$"

Route110_Text_1EFE3F: @ 81EFE3F
	.string "BRENDAN: Hey, {PLAYER}.\n"
	.string "So this is where you were.\l"
	.string "How's it going?\p"
	.string "Have you been raising your POKéMON?\n"
	.string "I'll check for you.$"

Route110_Text_1EFEB4: @ 81EFEB4
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route110_Text_1EFECD: @ 81EFECD
	.string "BRENDAN: {PLAYER}, you've trained\n"
	.string "without me noticing…\p"
	.string "Good enough!\n"
	.string "Here, take this.$"

Route110_Text_1EFF1C: @ 81EFF1C
	.string "BRENDAN: That's an ITEMFINDER.\p"
	.string "Use it to root around for items that\n"
	.string "aren't visible.\p"
	.string "If it senses something, it emits\n"
	.string "a sound.\p"
	.string "Anyway, I'm off to look for new\n"
	.string "POKéMON.$"

Route110_Text_1EFFC3: @ 81EFFC3
	.string "Wouldn't it be great to ride a BIKE\n"
	.string "at full speed on CYCLING ROAD?$"

Route110_Text_1F0006: @ 81F0006
	.string "How do you like the way my raven-\n"
	.string "colored hair streams behind me?\p"
	.string "I grew my hair out just for that.$"

Route110_Text_1F006A: @ 81F006A
	.string "Oh, hey, you got that BIKE from RYDEL!\p"
	.string "Oh, it's glaringly obvious.\n"
	.string "It says right on your bike…\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
	.string "That name's everywhere.\p"
	.string "You should ride it around all over\n"
	.string "the place--it's good advertising!$"

Route110_Text_1F0261: @ 81F0261
	.string "The two roads, one above, one below…\p"
	.string "A road each for people and POKéMON.\n"
	.string "Perhaps that is right and fair.$"

Route110_Text_1F02CA: @ 81F02CA
	.string "I don't have a BIKE, so I'll take\n"
	.string "a leisurely walk on the low road.$"

Route110_Text_1F030E: @ 81F030E
	.string "Learning techniques will make BIKE\n"
	.string "riding even more fun.\p"
	.string "There are some places that you can\n"
	.string "reach only by using a BIKE technique.$"

Route110_Text_1F0390: @ 81F0390
	.string "Which should I choose?\p"
	.string "Make a beeline for MAUVILLE on\n"
	.string "CYCLING ROAD, or take the low road\l"
	.string "and look for POKéMON?$"

Route110_Text_1F03FF: @ 81F03FF
	.string "Number of collisions:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "Total time:\n"
	.string "… … {STR_VAR_2}!$"

Route110_Text_1F0431: @ 81F0431
	.string "Bravo! Splendid showing!\p"
	.string "Your love of cycling comes from deep\n"
	.string "within your heart.\l"
	.string "You've shaken me to my very soul!$"

Route110_Text_1F04A4: @ 81F04A4
	.string "Your technique is remarkable.\p"
	.string "I suggest you speed up a bit while\n"
	.string "still avoiding collisions.$"

Route110_Text_1F0500: @ 81F0500
	.string "I would consider you a work in\n"
	.string "progress.\p"
	.string "Still, I hope you don't forget the\n"
	.string "sheer pleasure of cycling.$"

Route110_Text_1F0567: @ 81F0567
	.string "My word… Your cycling skills border\n"
	.string "on terrifying.\p"
	.string "Most certainly, you need much more\n"
	.string "practice riding.$"

Route110_Text_1F05CE: @ 81F05CE
	.string "…I am aghast…\p"
	.string "You're perhaps not cut out for this\n"
	.string "unfortunate cycling business.\p"
	.string "You ought to give serious thought to\n"
	.string "returning that BIKE to RYDEL.$"

Route110_Text_1F0661: @ 81F0661
	.string "This is CYCLING ROAD.\p"
	.string "If you were to ride from MAUVILLE to\n"
	.string "SLATEPORT on a MACH BIKE, you would\l"
	.string "be rated for the number of collisions\l"
	.string "and your total time.$"

Route110_Text_1F06FB: @ 81F06FB
	.string "Regardless of the results, I count on\n"
	.string "seeing more challenges from you.\l"
	.string "Always aim higher!$"

Route110_Text_1F0755: @ 81F0755
	.string "On this CYCLING ROAD, those riding\n"
	.string "MACH BIKES are rated for their number\l"
	.string "of collisions and their total times.\p"
	.string "ACRO BIKES do not qualify for rating.\n"
	.string "They are easy to turn, so it's not fair.$"

Route110_Text_1F0812: @ 81F0812
	.string "ROUTE 110\n"
	.string "{DOWN_ARROW} SLATEPORT CITY$"

Route110_Text_1F082D: @ 81F082D
	.string "SEASIDE CYCLING ROAD$"

Route110_Text_1F0842: @ 81F0842
	.string "“TEAM AQUA was here!”\p"
	.string "Someone painted that onto this sign,\n"
	.string "but then someone else painted over it.\p"
	.string "“TEAM MAGMA rules!” is what it\n"
	.string "says now.$"

Route110_Text_1F08CD: @ 81F08CD
	.string "ROUTE 110\n"
	.string "{LEFT_ARROW} ROUTE 103$"

Route110_Text_1F08E3: @ 81F08E3
	.string "SEASIDE PARKING$"

Route110_Text_1F08F3: @ 81F08F3
	.string "ROUTE 110\n"
	.string "{UP_ARROW} MAUVILLE CITY$"

Route110_Text_1F090D: @ 81F090D
	.string "TRAINER TIPS\p"
	.string "The foe can be made helpless by\n"
	.string "paralyzing it or causing it to sleep.\p"
	.string "It is an important technique for\n"
	.string "POKéMON battles.$"

Route110_Text_1F0992: @ 81F0992
	.string "TRAINER TIPS\p"
	.string "The items in the BAG can be reorganized\n"
	.string "by pressing SELECT.$"

Route110_Text_1F09DB: @ 81F09DB
	.string "“Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
	.string "to reach the wondrous TRICK HOUSE.”$"

Route110_Text_1F0A1E: @ 81F0A1E
	.string "THE BEST RECORD TO DATE…\p"
	.string "No. of collisions: {STR_VAR_1}\p"
	.string "Elapsed time: {STR_VAR_2}$"

Route110_Text_1F0A5E: @ 81F0A5E
	.string "THE BEST RECORD TO DATE…\p"
	.string "No one seems to have taken the\n"
	.string "challenge. There is no record…$"

Route110_Text_1F0AB5: @ 81F0AB5
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "Imagine seeing you here!\p"
	.string "And where might my {RIVAL} be?$"

Route110_Text_1F0AFF: @ 81F0AFF
	.string "Oh, I see!\n"
	.string "You two are running separately.\l"
	.string "Well, that's fine.\p"
	.string "Oh, yes, I heard that your POKéNAV\n"
	.string "had the MATCH CALL system installed.\p"
	.string "Well, then, I should register you in\n"
	.string "my POKéNAV as well.\p"
	.string "That way, even when we're apart,\n"
	.string "I can rate your POKéDEX anytime.\p"
	.string "… … … … … …$"

Route110_Text_1F0C0C: @ 81F0C0C
	.string "Registered PROF. BIRCH\n"
	.string "in the POKéNAV.$"

Route110_Text_1F0C33: @ 81F0C33
	.string "PROF. BIRCH: {PLAYER}{KUN}…\p"
	.string "Please keep an eye out for my {RIVAL}.\n"
	.string "… … … … … …\p"
	.string "Well, I had better get going.\n"
	.string "See you again, {PLAYER}{KUN}!$"

