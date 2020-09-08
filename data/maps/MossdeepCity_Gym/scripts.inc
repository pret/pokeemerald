MossdeepCity_Gym_MapScripts:: @ 8220800
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad: @ 8220806
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2:: @ 8220815
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3:: @ 8220824
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4:: @ 8220833
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles:: @ 822083D
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles:: @ 8220855
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles:: @ 822086D
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, 0
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles:: @ 8220885
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, 0
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, 1
	end

MossdeepCity_Gym_EventScript_TateAndLiza:: @ 8220898
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM04, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated:: @ 82208D1
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2:: @ 8220937
	giveitem ITEM_TM04
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind:: @ 822095B
	giveitem ITEM_TM04
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM04
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch:: @ 822097E
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1:: @ 8220999
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed:: @ 82209C8
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1:: @ 82209D0
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RS_MossdeepGym_RedArrow_Left, 0
	setmetatile 2, 7, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2:: @ 82209F5
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2:: @ 8220A24
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RS_MossdeepGym_RedArrow_Down, 0
	setmetatile 8, 10, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3:: @ 8220A49
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Left, 0
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3:: @ 8220A78
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 17, 15, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4:: @ 8220A9D
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Up, 0
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Down, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4:: @ 8220ACC
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RS_MossdeepGym_RedArrow_Right, 0
	setmetatile 5, 24, METATILE_RS_MossdeepGym_Switch_Up, 1
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance:: @ 8220AF1
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 255, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston:: @ 8220AFD
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil:: @ 8220B14
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake:: @ 8220B2B
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah:: @ 8220B42
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha:: @ 8220B59
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura:: @ 8220B70
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia:: @ 8220B87
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate:: @ 8220B9E
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey:: @ 8220BB5
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford:: @ 8220BCC
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas:: @ 8220BE3
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen:: @ 8220BFA
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide:: @ 8220C11
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory:: @ 8220C26
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse: @ 8220C30
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue:: @ 8220C33
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue:: @ 8220C43
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified:: @ 8220C53
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue:: @ 8220C5D
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch:: @ 8220C67
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch:: @ 8220C7D
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch:: @ 8220C93
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch:: @ 8220CA9
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch:: @ 8220CBF
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice: @ 8220CD5
	.string "Yo, how's it going, CHAMPION-bound\n"
	.string "{PLAYER}?\p"
	.string "The GYM LEADERS here use\n"
	.string "PSYCHIC-type POKéMON.\p"
	.string "If you go up against them with\n"
	.string "FIGHTING- or POISON-type POKéMON,\l"
	.string "they'll inflict horrible damage!\p"
	.string "Plus, they'll come at you with\n"
	.string "outstanding combination attacks.\p"
	.string "If you want to win, you'll need to show\n"
	.string "them how tight you are with your\l"
	.string "POKéMON. Go for it!$"

MossdeepCity_Gym_Text_GymGuidePostVictory: @ 8220E2A
	.string "Wow, you're astounding!\n"
	.string "You're one great TRAINER!$"

MossdeepCity_Gym_Text_PrestonIntro: @ 8220E5C
	.string "Battles hinge on the strength of your\n"
	.string "spirit! The weak-spirited will never win!$"

MossdeepCity_Gym_Text_PrestonDefeat: @ 8220EAC
	.string "I lost!\n"
	.string "I must temper my spirit again!$"

MossdeepCity_Gym_Text_PrestonPostBattle: @ 8220ED3
	.string "The indecisive lose.\n"
	.string "That's my warning to you.$"

MossdeepCity_Gym_Text_VirgilIntro: @ 8220F02
	.string "Let me see your talent!$"

MossdeepCity_Gym_Text_VirgilDefeat: @ 8220F1A
	.string "You possess spectacular talent!$"

MossdeepCity_Gym_Text_VirgilPostBattle: @ 8220F3A
	.string "If there are prodigies in the world,\n"
	.string "then our GYM LEADERS are them!\p"
	.string "However, you may be even more talented\n"
	.string "than them…$"

MossdeepCity_Gym_Text_BlakeIntro: @ 8220FB0
	.string "Fufufufu… Watch me levitate a POKé\n"
	.string "BALL telekinetically!\p"
	.string "Wrooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "Sometimes, I'm out of sync…$"

MossdeepCity_Gym_Text_BlakeDefeat: @ 8221024
	.string "My POKéMON battling skills are out\n"
	.string "of sync, too!$"

MossdeepCity_Gym_Text_BlakePostBattle: @ 8221055
	.string "A POKé BALL was too heavy to lift\n"
	.string "psychically. But this dust bunny…\p"
	.string "Whoooooooooooooooh!\n"
	.string "… … … … … …\p"
	.string "No, I'm not cheating!\n"
	.string "I didn't blow on it! Honestly!$"

MossdeepCity_Gym_Text_HannahIntro: @ 82210EE
	.string "When you lose to me, don't be too hard\n"
	.string "on yourself.\p"
	.string "It's not that you're weak--I'm just\n"
	.string "too strong!$"

MossdeepCity_Gym_Text_HannahDefeat: @ 8221152
	.string "You're just too strong!$"

MossdeepCity_Gym_Text_HannahPostBattle: @ 822116A
	.string "I'm not going to get down on myself for\n"
	.string "losing. I just need to train harder.\p"
	.string "Positive thinking--that's my strong\n"
	.string "point!$"

MossdeepCity_Gym_Text_SamanthaIntro: @ 82211E2
	.string "I see it…\n"
	.string "I see your future…\p"
	.string "If you can beat me, I will tell you\n"
	.string "your future!$"

MossdeepCity_Gym_Text_SamanthaDefeat: @ 8221230
	.string "I surrender!$"

MossdeepCity_Gym_Text_SamanthaPostBattle: @ 822123D
	.string "You will wage a terrifically intense\n"
	.string "battle with our GYM LEADERS…\p"
	.string "The result…\n"
	.string "You won't hear it from me!$"

MossdeepCity_Gym_Text_MauraIntro: @ 82212A6
	.string "The roads you have traveled…\n"
	.string "What you have experienced…\p"
	.string "Come at me with everything you've\n"
	.string "learned!$"

MossdeepCity_Gym_Text_MauraDefeat: @ 8221309
	.string "You've traveled a path of greatness!$"

MossdeepCity_Gym_Text_MauraPostBattle: @ 822132E
	.string "A bright future awaits those who have\n"
	.string "worked diligently.\p"
	.string "For those who lazed idly, there is\n"
	.string "only despair at the end.\p"
	.string "What goes around comes around…$"

MossdeepCity_Gym_Text_SylviaIntro: @ 82213C2
	.string "Even at the risk of life, I will win\n"
	.string "this battle!$"

MossdeepCity_Gym_Text_SylviaDefeat: @ 82213F4
	.string "What you do…\n"
	.string "It horrifies me…$"

MossdeepCity_Gym_Text_SylviaPostBattle: @ 8221412
	.string "How dare you beat me…\p"
	.string "It won't be my fault if something\n"
	.string "horrible befalls you…$"

MossdeepCity_Gym_Text_NateIntro: @ 8221460
	.string "Hohoho.\p"
	.string "You need me to show you how tenacious\n"
	.string "the PSYCHIC type can be.$"

MossdeepCity_Gym_Text_NateDefeat: @ 82214A7
	.string "Oh! My, my!\n"
	.string "Your battle style is fantastic!$"

MossdeepCity_Gym_Text_NatePostBattle: @ 82214D3
	.string "I… I don't let defeat rattle m-me,\n"
	.string "however b-badly.$"

MossdeepCity_Gym_Text_KathleenIntro: @ 8221507
	.string "Let me show you a perfectly awful,\n"
	.string "horrifying time!$"

MossdeepCity_Gym_Text_KathleenDefeat: @ 822153B
	.string "N-nooooo!$"

MossdeepCity_Gym_Text_KathleenPostBattle: @ 8221545
	.string "Your vitality is contagious!\n"
	.string "Get away from me quickly!$"

MossdeepCity_Gym_Text_CliffordIntro: @ 822157C
	.string "I may be past my prime, but I suggest\n"
	.string "you not patronize me.$"

MossdeepCity_Gym_Text_CliffordDefeat: @ 82215B8
	.string "Ah, you overflow with the power\n"
	.string "of youth!$"

MossdeepCity_Gym_Text_CliffordPostBattle: @ 82215E2
	.string "It seems that I could not overcome\n"
	.string "your youthful energy.$"

MossdeepCity_Gym_Text_MaceyIntro: @ 822161B
	.string "You're not getting through to the end!\n"
	.string "Not if I can help it!$"

MossdeepCity_Gym_Text_MaceyDefeat: @ 8221658
	.string "How could you be so ludicrously\n"
	.string "strong?$"

MossdeepCity_Gym_Text_MaceyPostBattle: @ 8221680
	.string "Humph! You may be strong, but you're\n"
	.string "not suitable for the PSYCHIC type!\p"
	.string "The way you battle is somehow brutal!$"

MossdeepCity_Gym_Text_NicholasIntro: @ 82216EE
	.string "Wroooar! Have a taste of my super\n"
	.string "POKéMON hard-battling power!$"

MossdeepCity_Gym_Text_NicholasDefeat: @ 822172D
	.string "Oh!\n"
	.string "Done in!$"

MossdeepCity_Gym_Text_NicholasPostBattle: @ 822173A
	.string "All right! I think I'll develop a special\n"
	.string "invincible POKéMON power next.$"

MossdeepCity_Gym_Text_TateAndLizaIntro: @ 8221783
	.string "TATE: Hehehe… Were you surprised?\p"
	.string "LIZA: Fufufu… Were you surprised?\p"
	.string "TATE: That there are two GYM LEADERS?\n"
	.string "LIZA: That there are two GYM LEADERS?\p"
	.string "TATE: We're twins!\n"
	.string "LIZA: We're twins!\p"
	.string "TATE: We don't need to talk because…\n"
	.string "LIZA: We can each determine what…\p"
	.string "TATE: The other is thinking…\n"
	.string "LIZA: All in our minds!\p"
	.string "TATE: This combination of ours…\n"
	.string "LIZA: Can you beat it?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat: @ 82218EC
	.string "TATE: What?! Our combination…\n"
	.string "LIZA: Was shattered!\p"
	.string "TATE: It can't be helped. You've won…\n"
	.string "LIZA: So, in recognition, take this.$"

MossdeepCity_Gym_Text_ReceivedMindBadge: @ 822196A
	.string "{PLAYER} received the MIND BADGE\n"
	.string "from TATE and LIZA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis: @ 8221999
	.string "TATE: The MIND BADGE enhances the\n"
	.string "SP. ATK and SP. DEF of POKéMON.\p"
	.string "LIZA: It also lets you use the HM move\n"
	.string "DIVE outside of battle.\p"
	.string "TATE: You should also take this, too.$"

MossdeepCity_Gym_Text_ExplainCalmMind: @ 8221A40
	.string "TATE: That TM04 contains…\n"
	.string "LIZA: CALM MIND!\p"
	.string "TATE: It raises SP. ATK and…\n"
	.string "LIZA: It raises SP. DEF!\p"
	.string "TATE: It's a move that's perfect…\n"
	.string "LIZA: For PSYCHIC POKéMON!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza: @ 8221AEA
	.string "Registered GYM LEADERS TATE & LIZA\n"
	.string "in the POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle: @ 8221B1D
	.string "TATE: Looks like the bond between you\n"
	.string "and your POKéMON is far stronger than\l"
	.string "the bond that we share as twins.\p"
	.string "LIZA: You will become even stronger!\n"
	.string "We've battled you, so we know.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons: @ 8221BCE
	.string "TATE: Hehehe… Were you surprised?\p"
	.string "LIZA: That there are two GYM LEADERS?\p"
	.string "TATE: Oops, you have only one…\n"
	.string "LIZA: POKéMON that can battle.\p"
	.string "TATE: We can't battle that way!\p"
	.string "LIZA: If you want to challenge us,\n"
	.string "bring some more POKéMON.$"

MossdeepCity_Gym_Text_GymStatue: @ 8221CB0
	.string "MOSSDEEP CITY POKéMON GYM$"

MossdeepCity_Gym_Text_GymStatueCertified: @ 8221CCA
	.string "MOSSDEEP CITY POKéMON GYM\p"
	.string "LIZA AND TATE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch: @ 8221D0B
	.string "TATE: POKéMON…\n"
	.string "LIZA: POKéMON…\p"
	.string "TATE: By changing the party's mix…\n"
	.string "LIZA: The battle style changes.\p"
	.string "TATE: But me…\n"
	.string "LIZA: But me…\p"
	.string "TATE: I'll always be with LIZA!\n"
	.string "LIZA: I'll always be with TATE!\p"
	.string "TATE: Our combination…\n"
	.string "LIZA: We'll show you again and again!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat: @ 8221E05
	.string "TATE: You and your POKéMON…\n"
	.string "LIZA: It's as if you were siblings!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch: @ 8221E45
	.string "TATE: You can knock us down,\n"
	.string "but we'll never stay down!\p"
	.string "LIZA: Because the two of us,\n"
	.string "we always support each other!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons: @ 8221EB8
	.string "TATE: You're back again…\n"
	.string "LIZA: You're back again…\p"
	.string "TATE: To give us a rematch.\n"
	.string "LIZA: To give us a rematch.\p"
	.string "TATE: But…\n"
	.string "LIZA: For our match…\p"
	.string "TATE: You brought just one POKéMON!\n"
	.string "LIZA: You brought just one POKéMON!\p"
	.string "TATE: We need you to bring at least…\n"
	.string "LIZA: Two POKéMON when you come back.$"
