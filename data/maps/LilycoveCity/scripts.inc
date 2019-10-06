LilycoveCity_MapScripts:: @ 81E2B3C
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_MapScript1_1E2B61
	.byte 0

LilycoveCity_OnTransition: @ 81E2B47
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_LINK_CONTEST_ROOM_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeather15
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_MapScript1_1E2B61: @ 81E2B61
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_1E2B6B
	end

LilycoveCity_EventScript_1E2B6B:: @ 81E2B6B
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, 1
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, 1
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, 1
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, 1
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, 1
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, 1
	return

LilycoveCity_EventScript_1E2BD8:: @ 81E2BD8
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_1E2C18
	msgbox LilycoveCity_Text_2A7244, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_2A72E3, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C18:: @ 81E2C18
	msgbox LilycoveCity_Text_2A7321, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C22:: @ 81E2C22
	msgbox LilycoveCity_Text_1E3D9E, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2C2B:: @ 81E2C2B
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_1E2C40
	msgbox LilycoveCity_Text_1E3E3C, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C40:: @ 81E2C40
	msgbox LilycoveCity_Text_1E3E7D, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C4A:: @ 81E2C4A
	msgbox LilycoveCity_Text_1E3F05, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2C53:: @ 81E2C53
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_1E2C68
	msgbox LilycoveCity_Text_1E3FAB, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C68:: @ 81E2C68
	msgbox LilycoveCity_Text_1E4020, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C72:: @ 81E2C72
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_1E2C87
	msgbox LilycoveCity_Text_1E40AD, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C87:: @ 81E2C87
	msgbox LilycoveCity_Text_1E4145, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2C91:: @ 81E2C91
	msgbox LilycoveCity_Text_1E417B, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2C9A:: @ 81E2C9A
	msgbox LilycoveCity_Text_1E420B, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2CA3:: @ 81E2CA3
	msgbox LilycoveCity_Text_1E4283, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2CAC:: @ 81E2CAC
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_1E2CC1
	msgbox LilycoveCity_Text_1E42FC, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2CC1:: @ 81E2CC1
	msgbox LilycoveCity_Text_1E43FF, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_1E2CCB:: @ 81E2CCB
	msgbox LilycoveCity_Text_1E48A5, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2CD4:: @ 81E2CD4
	msgbox LilycoveCity_Text_1E4902, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2CDD:: @ 81E2CDD
	lockall
	msgbox LilycoveCity_Text_1E494D, MSGBOX_NPC
	applymovement 20, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_1E2CEE:: @ 81E2CEE
	lockall
	msgbox LilycoveCity_Text_1E49F4, MSGBOX_NPC
	applymovement 19, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_1E2CFF:: @ 81E2CFF
	msgbox LilycoveCity_Text_1E448B, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D08:: @ 81E2D08
	msgbox LilycoveCity_Text_1E44C3, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D11:: @ 81E2D11
	msgbox LilycoveCity_Text_1E44FC, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D1A:: @ 81E2D1A
	lockall
	specialvar VAR_0x8004, CountPlayerContestPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_1E2D3A
	msgbox LilycoveCity_Text_1E4571, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_1E2D3A:: @ 81E2D3A
	msgbox LilycoveCity_Text_1E4534, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_1E2D44:: @ 81E2D44
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_1E2D58
	msgbox LilycoveCity_Text_1E45A7, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_1E2D58:: @ 81E2D58
	msgbox LilycoveCity_Text_1E4624, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_1E2D62:: @ 81E2D62
	msgbox LilycoveCity_Text_1E466E, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D6B:: @ 81E2D6B
	msgbox LilycoveCity_Text_1E46BE, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D74:: @ 81E2D74
	msgbox LilycoveCity_Text_1E473D, MSGBOX_SIGN
	end

LilycoveCity_EventScript_1E2D7D:: @ 81E2D7D
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_1E2DB0
	msgbox LilycoveCity_Text_1E3D1F, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_1E3D4A, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_1E2DB0:: @ 81E2DB0
	msgbox LilycoveCity_Text_1E3D1F, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_1E2DBA:: @ 81E2DBA
	msgbox LilycoveCity_Text_1E3B2C, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2DC3:: @ 81E2DC3
	msgbox LilycoveCity_Text_1E3B95, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2DCC:: @ 81E2DCC
	msgbox LilycoveCity_Text_1E3C46, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2DD5:: @ 81E2DD5
	msgbox LilycoveCity_Text_1E3CBE, MSGBOX_NPC
	end

LilycoveCity_EventScript_1E2DDE:: @ 81E2DDE
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LilycoveCity_EventScript_1E2DF8
	compare VAR_RESULT, FEMALE
	goto_if_eq LilycoveCity_EventScript_1E2E6B
	end

LilycoveCity_EventScript_1E2DF8:: @ 81E2DF8
	playbgm MUS_GIRL_SUP, 1
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2E48
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2E51
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_EventScript_1E2E5A
	msgbox LilycoveCity_Text_1E3234, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_1E2EDE
	case 1, LilycoveCity_EventScript_1E2EEE
	case 2, LilycoveCity_EventScript_1E2EFE
	end

LilycoveCity_EventScript_1E2E48:: @ 81E2E48
	msgbox LilycoveCity_Text_1E31F5, MSGBOX_YESNO
	return

LilycoveCity_EventScript_1E2E51:: @ 81E2E51
	msgbox LilycoveCity_Text_1E3061, MSGBOX_YESNO
	return

LilycoveCity_EventScript_1E2E5A:: @ 81E2E5A
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_1E318D, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_1E2E6B:: @ 81E2E6B
	playbgm MUS_BOY_SUP, 1
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2EBB
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2EC4
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_EventScript_1E2ECD
	msgbox LilycoveCity_Text_1E373C, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_1E2F0E
	case 1, LilycoveCity_EventScript_1E2F1E
	case 2, LilycoveCity_EventScript_1E2F2E
	end

LilycoveCity_EventScript_1E2EBB:: @ 81E2EBB
	msgbox LilycoveCity_Text_1E36FA, MSGBOX_YESNO
	return

LilycoveCity_EventScript_1E2EC4:: @ 81E2EC4
	msgbox LilycoveCity_Text_1E3608, MSGBOX_YESNO
	return

LilycoveCity_EventScript_1E2ECD:: @ 81E2ECD
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_1E36BF, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_1E2EDE:: @ 81E2EDE
	trainerbattle_no_intro TRAINER_MAY_12, LilycoveCity_Text_1E3275
	goto LilycoveCity_EventScript_1E2F3E
	end

LilycoveCity_EventScript_1E2EEE:: @ 81E2EEE
	trainerbattle_no_intro TRAINER_MAY_13, LilycoveCity_Text_1E3275
	goto LilycoveCity_EventScript_1E2F3E
	end

LilycoveCity_EventScript_1E2EFE:: @ 81E2EFE
	trainerbattle_no_intro TRAINER_MAY_11, LilycoveCity_Text_1E3275
	goto LilycoveCity_EventScript_1E2F3E
	end

LilycoveCity_EventScript_1E2F0E:: @ 81E2F0E
	trainerbattle_no_intro TRAINER_BRENDAN_14, LilycoveCity_Text_1E3777
	goto LilycoveCity_EventScript_1E2FAA
	end

LilycoveCity_EventScript_1E2F1E:: @ 81E2F1E
	trainerbattle_no_intro TRAINER_BRENDAN_15, LilycoveCity_Text_1E3777
	goto LilycoveCity_EventScript_1E2FAA
	end

LilycoveCity_EventScript_1E2F2E:: @ 81E2F2E
	trainerbattle_no_intro TRAINER_BRENDAN_13, LilycoveCity_Text_1E3777
	goto LilycoveCity_EventScript_1E2FAA
	end

LilycoveCity_EventScript_1E2F3E:: @ 81E2F3E
	msgbox LilycoveCity_Text_1E32FB, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_1E2F76
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_EventScript_1E2F86
	compare VAR_RESULT, 1
	call_if_eq LilycoveCity_EventScript_1E2F8F
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_1E3006
	end

LilycoveCity_EventScript_1E2F76:: @ 81E2F76
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_1E2F80
	return

LilycoveCity_EventScript_1E2F80:: @ 81E2F80
	setvar VAR_RESULT, 1
	return

LilycoveCity_EventScript_1E2F86:: @ 81E2F86
	msgbox LilycoveCity_Text_1E3398, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E2F8F:: @ 81E2F8F
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_1E2FA1
	msgbox LilycoveCity_Text_1E346D, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E2FA1:: @ 81E2FA1
	msgbox LilycoveCity_Text_1E353A, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E2FAA:: @ 81E2FAA
	msgbox LilycoveCity_Text_1E37D7, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_1E2F76
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_EventScript_1E2FE2
	compare VAR_RESULT, 1
	call_if_eq LilycoveCity_EventScript_1E2FEB
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_1E3006
	end

LilycoveCity_EventScript_1E2FE2:: @ 81E2FE2
	msgbox LilycoveCity_Text_1E3876, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E2FEB:: @ 81E2FEB
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_1E2FFD
	msgbox LilycoveCity_Text_1E390C, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E2FFD:: @ 81E2FFD
	msgbox LilycoveCity_Text_1E39E3, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E3006:: @ 81E3006
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_1E302D:: @ 81E302D
	lock
	faceplayer
	msgbox LilycoveCity_Text_1E4774, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq LilycoveCity_EventScript_1E304F
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_EventScript_1E3058
	release
	end

LilycoveCity_EventScript_1E304F:: @ 81E304F
	msgbox LilycoveCity_Text_1E47A1, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_1E3058:: @ 81E3058
	msgbox LilycoveCity_Text_1E4824, MSGBOX_DEFAULT
	return

LilycoveCity_Text_1E3061: @ 81E3061
	.string "MAY: Oh, hey?\n"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
	.string "I bought a whole bunch of DOLLS and\n"
	.string "POSTERS.\p"
	.string "Of course, I've also caught a lot of\n"
	.string "POKéMON, and I'm raising them\l"
	.string "properly, too.\p"
	.string "Actually, I'm more worried if you're\n"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
	.string "I'll battle with you, so you can show\n"
	.string "me your POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_1E318D: @ 81E318D
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
	.string "been raising your POKéMON?\p"
	.string "That's not a very good showing as a\n"
	.string "TRAINER…$"

LilycoveCity_Text_1E31F5: @ 81E31F5
	.string "MAY: Come on, battle with me, so I can\n"
	.string "check out your POKéMON!$"

LilycoveCity_Text_1E3234: @ 81E3234
	.string "MAY: The POKéMON I raised won't be\n"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"

LilycoveCity_Text_1E3275: @ 81E3275
	.string "… … … … … … … …\p"
	.string "I remember the battle I had with you,\n"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
	.string "That battle helped you become this\n"
	.string "strong, {PLAYER}{KUN}, didn't it?$"

LilycoveCity_Text_1E32FB: @ 81E32FB
	.string "MAY: I'm thinking of going back to\n"
	.string "LITTLEROOT soon.\p"
	.string "I've caught a decent group of POKéMON,\n"
	.string "and my POKéDEX is coming along, so\l"
	.string "I'm going home to show my dad.$"

LilycoveCity_Text_1E3398: @ 81E3398
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Collect all the GYM BADGES and take\n"
	.string "the POKéMON LEAGUE challenge?\p"
	.string "Well, while you're collecting BADGES,\n"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
	.string "POKéDEX. I'll complete it before you!\p"
	.string "See you!$"

LilycoveCity_Text_1E346D: @ 81E346D
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Are you taking the POKéMON LEAGUE\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my POKéDEX before you!\p"
	.string "See you!$"

LilycoveCity_Text_1E353A: @ 81E353A
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Are you taking the BATTLE FRONTIER\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my POKéDEX before you!\p"
	.string "See you!$"

LilycoveCity_Text_1E3608: @ 81E3608
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
	.string "I'm running an errand for my dad.\n"
	.string "No, I'm not buying any DOLLS.\p"
	.string "Anyways, it's been a while.\p"
	.string "Want to have a battle to see who's been\n"
	.string "raising POKéMON better?$"

LilycoveCity_Text_1E36BF: @ 81E36BF
	.string "BRENDAN: Oh, what's the matter?\n"
	.string "Don't have the confidence?$"

LilycoveCity_Text_1E36FA: @ 81E36FA
	.string "BRENDAN: Want to battle to see who's\n"
	.string "been raising POKéMON better?$"

LilycoveCity_Text_1E373C: @ 81E373C
	.string "BRENDAN: Aww, but you know I'm not\n"
	.string "going to lose to no {PLAYER}.$"

LilycoveCity_Text_1E3777: @ 81E3777
	.string "Humph…\n"
	.string "You've done a lot of raising.\p"
	.string "That stings a bit--I had a head start\n"
	.string "on you as a TRAINER…$"

LilycoveCity_Text_1E37D7: @ 81E37D7
	.string "BRENDAN: I…\n"
	.string "I plan on going home to LITTLEROOT.\p"
	.string "You know I'm helping out my dad on his\n"
	.string "POKéDEX. It's coming together pretty\l"
	.string "decently, so I should go show him.$"

LilycoveCity_Text_1E3876: @ 81E3876
	.string "{PLAYER}, what are you going to do?\p"
	.string "Collect all the GYM BADGES and take\n"
	.string "the POKéMON LEAGUE challenge?\p"
	.string "Maybe I'll do that, too…\p"
	.string "Well, anyway, hang in there!$"

LilycoveCity_Text_1E390C: @ 81E390C
	.string "{PLAYER}, what are you going to do?\p"
	.string "Since you're that strong, are you\n"
	.string "taking the POKéMON LEAGUE challenge?\p"
	.string "Heh, even me--if I trained my POKéMON\n"
	.string "a bit more, I should be stronger than\l"
	.string "you, {PLAYER}.\p"
	.string "Well, anyway, hang in there!$"

LilycoveCity_Text_1E39E3: @ 81E39E3
	.string "{PLAYER}, what are you going to do?\p"
	.string "Are you taking the BATTLE FRONTIER\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "Since you're that strong, you should\n"
	.string "consider the BATTLE FRONTIER.\p"
	.string "Heh, if I train my POKéMON a bit more,\n"
	.string "I'll get stronger than you, {PLAYER}.\p"
	.string "Maybe I should go to the BATTLE\n"
	.string "FRONTIER.\p"
	.string "Well, anyway, hang in there!$"

LilycoveCity_Text_1E3B2C: @ 81E3B2C
	.string "Fufufu…\p"
	.string "We moved more loot into our secret\n"
	.string "HIDEOUT today…\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_1E3B95: @ 81E3B95
	.string "I'm just a GRUNT, so I don't know what\n"
	.string "the BOSS is thinking…\p"
	.string "But being on TEAM AQUA, I know I'll get\n"
	.string "the chance to do big things!\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_1E3C46: @ 81E3C46
	.string "Hey, you!\p"
	.string "Don't go near the cave in the cove!\p"
	.string "Why? You don't need a reason why!\n"
	.string "I'm an adult, so you just listen to me!$"

LilycoveCity_Text_1E3CBE: @ 81E3CBE
	.string "If this whole wide world becomes ours,\n"
	.string "TEAM AQUA's, it will be a happier\l"
	.string "place for POKéMON, too.$"

LilycoveCity_Text_1E3D1F: @ 81E3D1F
	.string "There! WAILMER!\n"
	.string "Leap out of the water now!$"

LilycoveCity_Text_1E3D4A: @ 81E3D4A
	.string "Hunh? What do you want?\p"
	.string "You're messing up our training,\n"
	.string "so can you, like, get lost?$"

LilycoveCity_Text_1E3D9E: @ 81E3D9E
	.string "There's a POKéMON CONTEST HALL\n"
	.string "right in this here town. \p"
	.string "That means well-raised POKéMON will\n"
	.string "come from all over the country.\p"
	.string "My heart swells with excitement!$"

LilycoveCity_Text_1E3E3C: @ 81E3E3C
	.string "Have you seen that strange cave in\n"
	.string "the cove at the edge of town?$"

LilycoveCity_Text_1E3E7D: @ 81E3E7D
	.string "I'm going to teach my POKéMON some new\n"
	.string "moves for entering a CONTEST.\p"
	.string "So, I'm going to see the MOVE DELETER\n"
	.string "and make it forget HM moves.$"

LilycoveCity_Text_1E3F05: @ 81E3F05
	.string "I came from KANTO.\p"
	.string "The HOENN region is beautiful with\n"
	.string "all its water and verdant nature.\p"
	.string "Hunh? Wait a second…\p"
	.string "Could there be rare POKéMON that live\n"
	.string "only in this area?$"

LilycoveCity_Text_1E3FAB: @ 81E3FAB
	.string "TEAM AQUA's been training their\n"
	.string "WAILMER in the cove.\p"
	.string "We SAILORS can't get our boats out\n"
	.string "to sea with them in the way!$"

LilycoveCity_Text_1E4020: @ 81E4020
	.string "Ahoy, did you know?\p"
	.string "Someone punted TEAM AQUA out of\n"
	.string "the way for us!\p"
	.string "That got the WAILMER out of the cove,\n"
	.string "so we can get our boats out again.$"

LilycoveCity_Text_1E40AD: @ 81E40AD
	.string "I was taking a relaxing snooze at the\n"
	.string "seaside inn to the sound of waves…\p"
	.string "When someone stole my POKéMON!\p"
	.string "Who's the abductor?\n"
	.string "TEAM AQUA? Is it TEAM AQUA?$"

LilycoveCity_Text_1E4145: @ 81E4145
	.string "My missing POKéMON…\n"
	.string "It came back without me noticing!$"

LilycoveCity_Text_1E417B: @ 81E417B
	.string "I'm an ART DEALER.\p"
	.string "I am a buyer and seller of fine art,\n"
	.string "especially paintings.\p"
	.string "I've heard that the MUSEUM here has\n"
	.string "magnificent works on exhibit…$"

LilycoveCity_Text_1E420B: @ 81E420B
	.string "Even as we grow old and wrinkled,\n"
	.string "the sea remains forever young with\l"
	.string "the vivid brilliance of life…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_1E4283: @ 81E4283
	.string "It was sixty years ago that my husband\n"
	.string "proposed to me here.\l"
	.string "The sea remains as beautiful as ever.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_1E42FC: @ 81E42FC
	.string "Hm, you know of the peculiar cavern\n"
	.string "in this cove?\p"
	.string "That had been a natural formation,\n"
	.string "but then that TEAM AQUA lot came\l"
	.string "along and made their renovations.\p"
	.string "They call themselves\n"
	.string "the “nature-loving TEAM AQUA”!\p"
	.string "But what they do and what they say\n"
	.string "don't match at all!$"

LilycoveCity_Text_1E43FF: @ 81E43FF
	.string "That cave in the cove…\p"
	.string "I didn't notice it right away,\n"
	.string "but it's completely empty now.\p"
	.string "That TEAM AQUA lot, they must\n"
	.string "have gone away for good.$"

LilycoveCity_Text_1E448B: @ 81E448B
	.string "LILYCOVE CITY\p"
	.string "“Where the land ends and the\n"
	.string "sea begins.”$"

LilycoveCity_Text_1E44C3: @ 81E44C3
	.string "POKéMON CONTEST HALL\n"
	.string "“The gathering place for TRAINERS!”$"

LilycoveCity_Text_1E44FC: @ 81E44FC
	.string "COVE LILY MOTEL\p"
	.string "“Remember us as COVE LILY of\n"
	.string "LILYCOVE.”$"

LilycoveCity_Text_1E4534: @ 81E4534
	.string "LILYCOVE MUSEUM\p"
	.string "“POKéMON Masterpiece Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_1E4571: @ 81E4571
	.string "LILYCOVE MUSEUM\p"
	.string "“{PLAYER}'s POKéMON Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_1E45A7: @ 81E45A7
	.string "LILYCOVE CITY HARBOR\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in SLATEPORT CITY.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"

LilycoveCity_Text_1E4624: @ 81E4624
	.string "LILYCOVE CITY HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"

LilycoveCity_Text_1E466E: @ 81E466E
	.string "POKéMON TRAINER FAN CLUB\p"
	.string "The names of TRAINERS are scribbled\n"
	.string "all over the sign…$"

LilycoveCity_Text_1E46BE: @ 81E46BE
	.string "LILYCOVE DEPARTMENT STORE\p"
	.string "“Overflowing with great merchandise\n"
	.string "and excitement!\p"
	.string "“A great place to find that something\n"
	.string "you need!”$"

LilycoveCity_Text_1E473D: @ 81E473D
	.string "MOVE DELETER'S HOUSE\p"
	.string "“Unwanted POKéMON moves deleted.”$"

LilycoveCity_Text_1E4774: @ 81E4774
	.string "Do you know about the machine\n"
	.string "BERRY BLENDER?$"

LilycoveCity_Text_1E47A1: @ 81E47A1
	.string "People have to work together to get it\n"
	.string "to spin faster.\p"
	.string "The faster you can make it spin, the\n"
	.string "better {POKEBLOCK}S you can get, I've heard.$"

LilycoveCity_Text_1E4824: @ 81E4824
	.string "It's used for making a kind of candy\n"
	.string "called a {POKEBLOCK}.\p"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
	.string "its condition will improve by a lot.$"

LilycoveCity_Text_1E48A5: @ 81E48A5
	.string "I heard there's a tower somewhere out\n"
	.string "on the sea routes.\p"
	.string "It's called the SKY PILLAR, I hear.$"

LilycoveCity_Text_1E4902: @ 81E4902
	.string "I saw this tall tower somewhere\n"
	.string "around ROUTE 131.\p"
	.string "Could that possibly be…?$"

LilycoveCity_Text_1E494D: @ 81E494D
	.string "We just arrived here on our\n"
	.string "honeymoon vacation.\p"
	.string "We happened to see a DRAGON-type\n"
	.string "POKéMON flying way up in the sky.\p"
	.string "Do cool POKéMON like that live in\n"
	.string "the HOENN region?$"

LilycoveCity_Text_1E49F4: @ 81E49F4
	.string "On our honeymoon, we vowed to see as\n"
	.string "many rare POKéMON as we can.\p"
	.string "So we were delighted to see a rare\n"
	.string "POKéMON as soon as we arrived.\p"
	.string "I mean, we are totally happy!$"

