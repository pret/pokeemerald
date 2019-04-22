LavaridgeTown_MapScripts:: @ 81EA4D3
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_MapScript2_1EA547
	.byte 0

LavaridgeTown_OnTransition: @ 81EA4DE
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_FLANNERY_GIVES_BADGE_INFO, LavaridgeTown_EventScript_1EA514
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_1EA53F
	call Common_EventScript_SetupRivalGender
	call Common_EventScript_SetupRivalOnBikeGender
	compare VAR_LAVARIDGE_RIVAL_STATE, 1
	call_if_eq LavaridgeTown_EventScript_1EA518
	compare VAR_LAVARIDGE_RIVAL_STATE, 1
	call_if_eq LavaridgeTown_EventScript_1EA543
	end

LavaridgeTown_EventScript_1EA514:: @ 81EA514
	clearflag FLAG_FLANNERY_GIVES_BADGE_INFO
	return

LavaridgeTown_EventScript_1EA518:: @ 81EA518
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 9
	goto_if_eq LavaridgeTown_EventScript_1EA529
	return

LavaridgeTown_EventScript_1EA529:: @ 81EA529
	setobjectxyperm 8, 11, 9
	setobjectxyperm 7, 9, 8
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_1
	return

LavaridgeTown_EventScript_1EA53F:: @ 81EA53F
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_1EA543:: @ 81EA543
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_MapScript2_1EA547: @ 81EA547
	map_script_2 VAR_LAVARIDGE_RIVAL_STATE, 1, LavaridgeTown_EventScript_1EA551
	.2byte 0

LavaridgeTown_EventScript_1EA551:: @ 81EA551
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_1EA63A
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_1EA65C
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LavaridgeTown_EventScript_1EA630
	compare VAR_RESULT, FEMALE
	call_if_eq LavaridgeTown_EventScript_1EA635
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_1EA6A1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_1EA6AC
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LavaridgeTown_EventScript_1EA5B5
	compare VAR_RESULT, FEMALE
	goto_if_eq LavaridgeTown_EventScript_1EA5DA
	end

LavaridgeTown_EventScript_1EA5B5:: @ 81EA5B5
	msgbox LavaridgeTown_Text_1EA7C0, MSGBOX_DEFAULT
	giveitem_std ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_1EA897, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_1EA5FF
	end

LavaridgeTown_EventScript_1EA5DA:: @ 81EA5DA
	msgbox LavaridgeTown_Text_1EA9A2, MSGBOX_DEFAULT
	giveitem_std ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_1EAA2E, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_1EA5FF
	end

LavaridgeTown_EventScript_1EA5FF:: @ 81EA5FF
	closemessage
	removeobject 8
	addobject 7
	delay 30
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_1EA6B7
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_1EA6C9
	removeobject 7
	setvar VAR_LAVARIDGE_RIVAL_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_1EA630:: @ 81EA630
	playbgm MUS_GIRL_SUP, 1
	return

LavaridgeTown_EventScript_1EA635:: @ 81EA635
	playbgm MUS_BOY_SUP, 1
	return

LavaridgeTown_EventScript_1EA63A:: @ 81EA63A
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA65C:: @ 81EA65C
	opendoor 12, 15
	waitdooranim
	addobject 8
	applymovement 8, LavaridgeTown_Movement_1EA6F8
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement 8, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA6A1:: @ 81EA6A1
	applymovement 8, LavaridgeTown_Movement_1EA6F4
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA6AC:: @ 81EA6AC
	applymovement 8, LavaridgeTown_Movement_1EA6ED
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA6B7:: @ 81EA6B7
	applymovement EVENT_OBJ_ID_PLAYER, LavaridgeTown_Movement_1EA6DF
	applymovement 7, LavaridgeTown_Movement_1EA6E3
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA6C9:: @ 81EA6C9
	applymovement 7, LavaridgeTown_Movement_1EA6D4
	waitmovement 0
	return

LavaridgeTown_Movement_1EA6D4: @ 81EA6D4
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_1EA6DF: @ 81EA6DF
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LavaridgeTown_Movement_1EA6E3: @ 81EA6E3
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_1EA6ED: @ 81EA6ED
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_1EA6F4: @ 81EA6F4
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_1EA6F8: @ 81EA6F8
	walk_down
	step_end

LavaridgeTown_EventScript_1EA6FA:: @ 81EA6FA
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, 1
	goto_if_eq LavaridgeTown_EventScript_1EA70B
	end

LavaridgeTown_EventScript_1EA70B:: @ 81EA70B
	incrementgamestat 49
	end

LavaridgeTown_EventScript_1EA70E:: @ 81EA70E
	msgbox LavaridgeTown_Text_1EAE03, MSGBOX_NPC
	end

LavaridgeTown_EventScript_1EA717:: @ 81EA717
	msgbox LavaridgeTown_Text_1EAEE1, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_1EA720:: @ 81EA720
	msgbox LavaridgeTown_Text_1EAF9B, MSGBOX_NPC
	end

LavaridgeTown_EventScript_1EA729:: @ 81EA729
	msgbox LavaridgeTown_Text_1EB003, MSGBOX_NPC
	end

LavaridgeTown_EventScript_1EA732:: @ 81EA732
	msgbox LavaridgeTown_Text_1EB092, MSGBOX_NPC
	end

LavaridgeTown_EventScript_1EA73B:: @ 81EA73B
	msgbox LavaridgeTown_Text_1EAF4E, MSGBOX_NPC
	end

LavaridgeTown_EventScript_1EA744:: @ 81EA744
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_1EA787
	msgbox LavaridgeTown_Text_1EAB80, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LavaridgeTown_EventScript_1EA79B
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq LavaridgeTown_EventScript_1EA791
	msgbox LavaridgeTown_Text_1EACC0, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_FANFA4
	message LavaridgeTown_Text_1EACF4
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_1EA787:: @ 81EA787
	msgbox LavaridgeTown_Text_1EAD9E, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_1EA791:: @ 81EA791
	msgbox LavaridgeTown_Text_1EAD09, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_1EA79B:: @ 81EA79B
	msgbox LavaridgeTown_Text_1EAD44, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_1EA7A5:: @ 81EA7A5
	msgbox LavaridgeTown_Text_1EB12B, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_1EA7AE:: @ 81EA7AE
	msgbox LavaridgeTown_Text_1EB178, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_1EA7B7:: @ 81EA7B7
	msgbox LavaridgeTown_Text_1EB1CB, MSGBOX_SIGN
	end

LavaridgeTown_Text_1EA7C0: @ 81EA7C0
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
	.string "Oh? While I visited the hot springs,\n"
	.string "you got the LAVARIDGE GYM BADGE.\p"
	.string "You must have collected\n"
	.string "good POKéMON…\l"
	.string "No, I believe you raised some.\p"
	.string "I guess it would be okay for you to\n"
	.string "have this.$"

LavaridgeTown_Text_1EA897: @ 81EA897
	.string "MAY: With those GO-GOGGLES, you'll\n"
	.string "have no trouble getting through the\l"
	.string "desert near ROUTE 111.\p"
	.string "But, wow, {PLAYER}{KUN}…\n"
	.string "Challenging GYMS…\p"
	.string "You're trying hard because you don't\n"
	.string "want to lose to me, I bet!\p"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
	.string "your dad in PETALBURG GYM.\p"
	.string "See you again!$"

LavaridgeTown_Text_1EA9A2: @ 81EA9A2
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
	.string "How's it going?\p"
	.string "Hmm…\n"
	.string "That's a decent collection of BADGES.\p"
	.string "All right, then.\n"
	.string "You may as well have this.$"

LavaridgeTown_Text_1EAA2E: @ 81EAA2E
	.string "BRENDAN: Keep those with you if you're\n"
	.string "planning on going into that desert near\l"
	.string "ROUTE 111.\p"
	.string "There should be some POKéMON that\n"
	.string "are exclusively desert-dwellers.\l"
	.string "You might look around for those.\p"
	.string "As for me…\n"
	.string "I'm considering challenging NORMAN,\l"
	.string "the GYM LEADER of PETALBURG.\p"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
	.string "he really is tough.\p"
	.string "See you around!$"

LavaridgeTown_Text_1EAB80: @ 81EAB80
	.string "I have here an EGG.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with POKéMON and\l"
	.string "carried about.\p"
	.string "You are a TRAINER, yes?\n"
	.string "And your POKéMON radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this EGG to hatch?$"

LavaridgeTown_Text_1EACC0: @ 81EACC0
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here EGG!$"

LavaridgeTown_Text_1EACF4: @ 81EACF4
	.string "{PLAYER} received the EGG.$"

LavaridgeTown_Text_1EAD09: @ 81EAD09
	.string "Oh? You've too many POKéMON.\n"
	.string "There's no room for this EGG…$"

LavaridgeTown_Text_1EAD44: @ 81EAD44
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this EGG, I will be here.$"

LavaridgeTown_Text_1EAD9E: @ 81EAD9E
	.string "Every so often, an EGG will be found at\n"
	.string "the POKéMON DAY CARE.\p"
	.string "Or at least that's how the rumor goes.$"

LavaridgeTown_Text_1EAE03: @ 81EAE03
	.string "We draw as much hot water as we need,\n"
	.string "and yet the hot springs never run dry.\p"
	.string "Isn't it magical?\p"
	.string "These hot springs appear near active\n"
	.string "volcanoes. Veins of water under the\l"
	.string "ground are heated by magma to well up\l"
	.string "as hot springs.$"

LavaridgeTown_Text_1EAEE1: @ 81EAEE1
	.string "Being buried in this hot sand is…\n"
	.string "Sigh…\p"
	.string "So warm and heavenly…\p"
	.string "Eh? Gyaah! Ouch!\p"
	.string "A POKéMON nipped my backside!$"

LavaridgeTown_Text_1EAF4E: @ 81EAF4E
	.string "Oh, you like hot springs, do you?\p"
	.string "That's surprising for one as young\n"
	.string "as you.$"

LavaridgeTown_Text_1EAF9B: @ 81EAF9B
	.string "I bathe in the hot springs every day.\p"
	.string "I want to become a beautiful and strong\n"
	.string "GYM LEADER like FLANNERY.$"

LavaridgeTown_Text_1EB003: @ 81EB003
	.string "If people put POKéMON in hot springs,\n"
	.string "it might be seriously strange.\p"
	.string "Why, it might be an electric bath, or\n"
	.string "a bubble bath, or even a lava bath…$"

LavaridgeTown_Text_1EB092: @ 81EB092
	.string "They're claiming that these hot springs\n"
	.string "are good for calming nervous tension,\l"
	.string "relieving aching muscles, solving\l"
	.string "romantic problems, and attracting\l"
	.string "money…$"

LavaridgeTown_Text_1EB12B: @ 81EB12B
	.string "LAVARIDGE TOWN\p"
	.string "“POKéMON CENTER HOT SPRINGS\n"
	.string "An excellent place for relaxing!”$"

LavaridgeTown_Text_1EB178: @ 81EB178
	.string "LAVARIDGE TOWN POKéMON GYM\n"
	.string "LEADER: FLANNERY\l"
	.string "“One with a fiery passion that burns!”$"

LavaridgeTown_Text_1EB1CB: @ 81EB1CB
	.string "POKéMON HERB SHOP\n"
	.string "“Bitter taste--better cure!”$"

