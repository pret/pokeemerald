.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, so you are {PLAYER}{KUN}?\n"
	.string "I've heard tales of your exploits.\p"
	.string "My name is WALLACE.\p"
	.string "I was once the GYM LEADER of\n"
	.string "SOOTOPOLIS, but something came up.\p"
	.string "So now, I've entrusted my mentor JUAN\n"
	.string "with the GYM's operation.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON and KYOGRE, the two POKéMON\n"
	.string "wreaking havoc here, are considered\l"
	.string "to be super-ancient POKéMON.\p"
	.string "But there aren't just two super-\n"
	.string "ancient POKéMON.\p"
	.string "There is one more somewhere.\p"
	.string "Somewhere, there is a super-\n"
	.string "ancient POKéMON named RAYQUAZA.\p"
	.string "It's said that it was RAYQUAZA that\n"
	.string "becalmed the two combatants in\l"
	.string "the distant past.\p"
	.string "But even I have no clue as to\n"
	.string "RAYQUAZA's whereabouts…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}{KUN}, do you perhaps\n"
	.string "know where RAYQUAZA is now?\p"
	.string "If you do, please tell me.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: The CAVE OF ORIGIN?\p"
	.string "But that's right here!\n"
	.string "I need you to do better than that!\p"
	.string "Please, I need you to think about\n"
	.string "where RAYQUAZA might be right now.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: MT. PYRE?\p"
	.string "But when I met the old lady there\n"
	.string "earlier, she made no mention of it.\p"
	.string "I very much doubt that the old lady\n"
	.string "would try to hide something from me…\p"
	.string "{PLAYER}{KUN}, could you think about this\n"
	.string "more carefully for me?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: Huh? You don't remember?\n"
	.string "Hmm… That's a problem…\p"
	.string "Can't you remember somehow?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: The SKY PILLAR?\p"
	.string "That's it!\n"
	.string "It must be the SKY PILLAR!\p"
	.string "{PLAYER}{KUN}, there's not a moment to lose!\n"
	.string "We'll head to the SKY PILLAR right away!$"

