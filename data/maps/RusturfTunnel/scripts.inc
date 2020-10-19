.equ LOCALID_WANDAS_BF, 1
.set LOCALID_BRINEY, 5
.set LOCALID_GRUNT, 6
.set LOCALID_PEEKO, 7
.equ LOCALID_WANDA, 10

RusturfTunnel_MapScripts:: @ 822CE27
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
	.byte 0

RusturfTunnel_OnFrame: @ 822CE32
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_ClearTunnelScene
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_ClearTunnelScene
	.2byte 0

RusturfTunnel_OnTransition: @ 822CE44
	compare VAR_RUSTURF_TUNNEL_STATE, 2
	call_if_eq RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
	end

RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos:: @ 822CE50
	setobjectxyperm LOCALID_PEEKO, 13, 4
	setobjectxyperm LOCALID_GRUNT, 13, 5
	return

RusturfTunnel_EventScript_Wanda:: @ 822CE5F
	lock
	faceplayer
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_WandasBoyfriend:: @ 822CE76
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
	setflag FLAG_TEMP_1
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_AlreadySpokenTo:: @ 822CE99
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_ClearTunnelScene:: @ 822CEAE
	lockall
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_FaceWandasBoyfriend1
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_FaceWandasBoyfriend2
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_FaceWandasBoyfriend3
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	giveitem ITEM_HM04
	setflag FLAG_RECEIVED_HM04
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_BoyfriendApproachWanda1
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_BoyfriendApproachWanda2
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_BoyfriendApproachWanda3
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_WandaAndBoyfriendExit1
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_WandaAndBoyfriendExit
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_WandaAndBoyfriendExit
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
	releaseall
	end

RusturfTunnel_EventScript_BoyfriendApproachWanda1:: @ 822CF5D
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda2:: @ 822CF6F
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda3:: @ 822CF8B
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend1:: @ 822CFA7
	applymovement LOCALID_WANDAS_BF, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend2:: @ 822CFBC
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend3:: @ 822CFC7
	return

RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer:: @ 822CFC8
	closemessage
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit1:: @ 822CFD4
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit1
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit:: @ 822CFE6
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
	waitmovement 0
	return

RusturfTunnel_EventScript_WandasBoyfriendNotice:: @ 822CFFF
	playse SE_PIN
	applymovement LOCALID_WANDAS_BF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WANDAS_BF, Common_Movement_Delay48
	waitmovement 0
	return

RusturfTunnel_Movement_WandaExit1: @ 822D017
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandaExit: @ 822D023
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_PlayerWatchWandaExit: @ 822D02F
	delay_8
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_Unused1: @ 822D035
	walk_left
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_Unused2: @ 822D038
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_Unused3: @ 822D03D
	walk_up
	walk_in_place_fastest_down
	delay_8
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend1: @ 822D042
	walk_left
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend: @ 822D045
	walk_right
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_BoyfriendFaceRight: @ 822D048
	walk_up
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit1: @ 822D04B
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit: @ 822D058
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendApproachPlayer: @ 822D065
	walk_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda1: @ 822D067
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda: @ 822D06C
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_fast_right
	walk_in_place_fastest_up
	step_end

RusturfTunnel_EventScript_TunnelBlockagePos1:: @ 822D071
	setvar VAR_TEMP_1, 1
	end

RusturfTunnel_EventScript_TunnelBlockagePos2:: @ 822D077
	setvar VAR_TEMP_1, 2
	end

RusturfTunnel_EventScript_TunnelBlockagePos3:: @ 822D07D
	setvar VAR_TEMP_1, 3
	end

RusturfTunnel_EventScript_AquaGruntBackUp:: @ 822D083
	lockall
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
	waitmovement 0
	copyobjectxytoperm LOCALID_GRUNT
	copyobjectxytoperm LOCALID_PEEKO
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
	releaseall
	end

RusturfTunnel_Movement_GruntAndPeekoBackUp: @ 822D0AB
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

RusturfTunnel_EventScript_Peeko:: @ 822D0AF
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RusturfTunnel_EventScript_Grunt:: @ 822D0C2
	lock
	faceplayer
	playbgm MUS_ENCOUNTER_AQUA, 0
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_GOODS
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntEscape
	waitmovement 0
	removeobject LOCALID_GRUNT
	delay 50
	addobject LOCALID_BRINEY
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko2
	waitmovement 0
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
	applymovement LOCALID_BRINEY, Common_Movement_FacePlayer
	waitmovement 0
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
	waitmessage
	waitse
	playmoncry SPECIES_WINGULL, 0
	waitbuttonpress
	waitmoncry
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyExit
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_PeekoExit
	waitmovement 0
	removeobject LOCALID_BRINEY
	removeobject LOCALID_PEEKO
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_CITY_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	release
	end

RusturfTunnel_Movement_PushPlayerAsideForGrunt: @ 822D178
	face_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_PlayerMoveAsideForBriney: @ 822D17E
	walk_down
	walk_in_place_fastest_up
	step_end

RusturfTunnel_Movement_GruntEscape: @ 822D181
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko1: @ 822D18B
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RusturfTunnel_Movement_BrineyExit: @ 822D193
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_Movement_PlayerWatchBrineyExit: @ 822D19F
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko2: @ 822D1A4
	delay_16
	walk_right
	step_end

RusturfTunnel_Movement_PeekoExit: @ 822D1A7
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_EventScript_Mike:: @ 822D1B1
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

RusturfTunnel_Text_ComeAndGetSome: @ 822D1C8
	.string "What, are you coming?\n"
	.string "Come and get some, then!$"

RusturfTunnel_Text_Peeko: @ 822D1F7
	.string "PEEKO: Pii pihyoh!$"

RusturfTunnel_Text_GruntIntro: @ 822D20A
	.string "Grah, keelhaul it all!\p"
	.string "That hostage POKéMON turned out to\n"
	.string "be worthless!\p"
	.string "And to think I made a getaway…\n"
	.string "In this tunnel to nowhere!\p"
	.string "Hey! You!\n"
	.string "So you want to battle me?$"

RusturfTunnel_Text_GruntDefeat: @ 822D2B0
	.string "Urrrggh! My career in crime comes to\n"
	.string "a dead end!$"

RusturfTunnel_Text_GruntTakePackage: @ 822D2E1
	.string "This is plain not right…\p"
	.string "The BOSS told me this would be a\n"
	.string "slick-and-easy job to pull.\p"
	.string "All I had to do was steal some package\n"
	.string "from DEVON.\p"
	.string "Tch!\n"
	.string "You want it back that badly, take it!$"

RusturfTunnel_Text_PeekoGladToSeeYouSafe: @ 822D395
	.string "PEEKO!\n"
	.string "Am I glad to see you're safe!$"

RusturfTunnel_Text_ThankYouLetsGoHomePeeko: @ 822D3BA
	.string "PEEKO owes her life to you!\p"
	.string "They call me MR. BRINEY.\n"
	.string "And, you are?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
	.string "I sincerely thank you!\p"
	.string "Now, if there's anything that troubles\n"
	.string "you, don't hesitate to tell me!\p"
	.string "You can usually find me in my cottage\n"
	.string "by the sea near PETALBURG WOODS.\p"
	.string "Come, PEEKO, we should make our way\n"
	.string "home.\p"
	.string "PEEKO: Pihyoh!$"

RusturfTunnel_Text_WhyCantTheyKeepDigging: @ 822D510
	.string "… …\p"
	.string "Why can't they keep digging?\n"
	.string "Is the bedrock too hard?\p"
	.string "My beloved awaits me in VERDANTURF\n"
	.string "TOWN just beyond here…\p"
	.string "If RUSTBORO and VERDANTURF were\n"
	.string "joined by this tunnel, I could visit\l"
	.string "her every day…\p"
	.string "But this…\n"
	.string "What am I to do?$"

RusturfTunnel_Text_ToGetToVerdanturf: @ 822D5F3
	.string "To get from RUSTBORO to VERDANTURF,\n"
	.string "you need to go to DEWFORD, then pass\l"
	.string "through SLATEPORT and MAUVILLE…$"

RusturfTunnel_Text_YouShatteredBoulderTakeHM: @ 822D65C
	.string "Wow! You shattered that boulder\n"
	.string "blocking the way.\p"
	.string "To show you how much I appreciate it,\n"
	.string "I'd like you to have this HM.$"

RusturfTunnel_Text_ExplainStrength: @ 822D6D2
	.string "That HM contains STRENGTH.\p"
	.string "If a muscular POKéMON were to learn\n"
	.string "that, it would be able to move even\l"
	.string "large boulders.$"

RusturfTunnel_Text_WandaReunion: @ 822D745
	.string "WANDA!\n"
	.string "Now I can see you anytime!\p"
	.string "WANDA: That's…wonderful.\p"
	.string "Please, take some rest at my home.$"

RusturfTunnel_Text_BoyfriendOnOtherSideOfRock: @ 822D7A3
	.string "On the other side of this rock…\n"
	.string "My boyfriend is there.\p"
	.string "He… He's not just digging the tunnel\n"
	.string "to come see me.\p"
	.string "He works his hands raw and rough\n"
	.string "for the benefit of everyone.$"

RusturfTunnel_Text_MikeIntro: @ 822D84D
	.string "What do you call a wild man up in the\n"
	.string "mountains? A mountain man, right?\p"
	.string "So why don't they call a POKéMON in\n"
	.string "the mountains a mountain POKéMON?$"

RusturfTunnel_Text_MikeDefeat: @ 822D8DB
	.string "My POKéMON…\n"
	.string "Ran out of power…$"

RusturfTunnel_Text_MikePostBattle: @ 822D8F9
	.string "They halted development here to\n"
	.string "protect POKéMON, right?\l"
	.string "There's a feel-good story!$"

