MossdeepCity_SpaceCenter_2F_MapScripts:: @ 8223D58
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_MapScript2_223DB5
	.byte 0

MossdeepCity_SpaceCenter_2F_OnTransition: @ 8223D63
	compare VAR_MOSSDEEP_STATE, 2
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_223D7A
	compare VAR_MOSSDEEP_SPACE_CENTER_STATE_2, 2
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_223D9F
	end

MossdeepCity_SpaceCenter_2F_EventScript_223D7A:: @ 8223D7A
	clearflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	setobjectxyperm 3, 5, 3
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 1, 3, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 2, 1, 3
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	return

MossdeepCity_SpaceCenter_2F_EventScript_223D9F:: @ 8223D9F
	setobjectxyperm 5, 11, 2
	setobjectxyperm 7, 15, 2
	setobjectxyperm 6, 13, 4
	return

MossdeepCity_SpaceCenter_2F_MapScript2_223DB5: @ 8223DB5
	map_script_2 VAR_MOSSDEEP_SPACE_CENTER_STATE_2, 1, MossdeepCity_SpaceCenter_2F_EventScript_223DBF
	.2byte 0

MossdeepCity_SpaceCenter_2F_EventScript_223DBF:: @ 8223DBF
	playse SE_PIN
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_2243A4, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_223E09
	msgbox MossdeepCity_SpaceCenter_2F_Text_2243FE, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_SpaceCenter_2F_Movement_223E07
	waitmovement 0
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 255, 13, 1
	waitstate
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_223E07: @ 8223E07
	walk_up
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_223E09:: @ 8223E09
	msgbox MossdeepCity_SpaceCenter_2F_Text_22442D, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_34, MossdeepCity_SpaceCenter_2F_Text_224461
	applymovement 6, MossdeepCity_SpaceCenter_2F_Movement_223E85
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_22446E, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_35, MossdeepCity_SpaceCenter_2F_Text_224499
	applymovement 5, MossdeepCity_SpaceCenter_2F_Movement_223E81
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_2244AB, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_36, MossdeepCity_SpaceCenter_2F_Text_2244F1
	applymovement 7, MossdeepCity_SpaceCenter_2F_Movement_223E89
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE_2, 2
	moveobjectoffscreen 5
	moveobjectoffscreen 7
	moveobjectoffscreen 6
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_223E81: @ 8223E81
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_223E85: @ 8223E85
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_Movement_223E89: @ 8223E89
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_223E8D:: @ 8223E8D
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_223EB4
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_223EBE
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_2F_EventScript_223EB4
	goto MossdeepCity_SpaceCenter_2F_EventScript_223EBE
	end

MossdeepCity_SpaceCenter_2F_EventScript_223EB4:: @ 8223EB4
	msgbox MossdeepCity_SpaceCenter_2F_Text_2241A1, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223EBE:: @ 8223EBE
	msgbox MossdeepCity_SpaceCenter_2F_Text_22420C, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223EC8:: @ 8223EC8
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_223EEF
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_223EF9
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_2F_EventScript_223EEF
	goto MossdeepCity_SpaceCenter_2F_EventScript_223EF9
	end

MossdeepCity_SpaceCenter_2F_EventScript_223EEF:: @ 8223EEF
	msgbox MossdeepCity_SpaceCenter_2F_Text_224253, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223EF9:: @ 8223EF9
	msgbox MossdeepCity_SpaceCenter_2F_Text_2242C5, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F03:: @ 8223F03
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_2F_EventScript_223F2A
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_223F34
	compare VAR_MOSSDEEP_STATE, 2
	goto_if_lt MossdeepCity_SpaceCenter_2F_EventScript_223F2A
	goto MossdeepCity_SpaceCenter_2F_EventScript_223F34
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F2A:: @ 8223F2A
	msgbox MossdeepCity_SpaceCenter_2F_Text_224342, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F34:: @ 8223F34
	msgbox MossdeepCity_SpaceCenter_2F_Text_224376, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F3E:: @ 8223F3E
	msgbox MossdeepCity_SpaceCenter_2F_Text_22452C, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F47:: @ 8223F47
	msgbox MossdeepCity_SpaceCenter_2F_Text_224570, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F50:: @ 8223F50
	msgbox MossdeepCity_SpaceCenter_2F_Text_2245AF, MSGBOX_NPC
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F59:: @ 8223F59
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_2F_Text_2245D9, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F6F:: @ 8223F6F
	lockall
	msgbox MossdeepCity_SpaceCenter_2F_Text_22467B, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_223F7A:: @ 8223F7A
	lockall
	goto_if_set FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER, MossdeepCity_SpaceCenter_2F_EventScript_223FDA
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	msgbox MossdeepCity_SpaceCenter_2F_Text_2246B2, MSGBOX_DEFAULT
	msgbox MossdeepCity_SpaceCenter_2F_Text_2246F0, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_KOUKA_L
	switch VAR_FACING
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_223FBA
	applymovement 4, MossdeepCity_SpaceCenter_2F_Movement_223FC6
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_223FBA:: @ 8223FBA
	applymovement 4, MossdeepCity_SpaceCenter_2F_Movement_223FCF
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_Movement_223FC6: @ 8223FC6
	lock_facing_direction
	walk_fast_up
	walk_fast_up
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_down
	walk_slow_down
	step_end

MossdeepCity_SpaceCenter_2F_Movement_223FCF: @ 8223FCF
	face_left
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	unlock_facing_direction
	delay_16
	delay_16
	walk_slow_left
	walk_slow_left
	face_down
	step_end

MossdeepCity_SpaceCenter_2F_EventScript_223FDA:: @ 8223FDA
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_2247FF, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MossdeepCity_SpaceCenter_2F_EventScript_22400C
	msgbox MossdeepCity_SpaceCenter_2F_Text_224854, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_22400C:: @ 822400C
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	special SavePlayerParty
	fadescreen 1
	special ChooseHalfPartyForBattle
	waitstate
	compare VAR_RESULT, 0
	goto_if_ne MossdeepCity_SpaceCenter_2F_EventScript_224032
	special LoadPlayerParty
	goto MossdeepCity_SpaceCenter_2F_EventScript_223FDA

MossdeepCity_SpaceCenter_2F_EventScript_224032:: @ 8224032
	special ReducePlayerPartyToSelectedMons
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special CallFrontierUtilFunc
	setvar VAR_0x8004, SPECIAL_BATTLE_STEVEN
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	setvar VAR_0x8004, 6
	special CallFrontierUtilFunc
	special LoadPlayerParty
	switch VAR_RESULT
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_224071
	fadescreen 1
	special sp0C8_whiteout_maybe
	waitstate

MossdeepCity_SpaceCenter_2F_EventScript_224071:: @ 8224071
	msgbox MossdeepCity_SpaceCenter_2F_Text_2248C2, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement 9, Common_Movement_WalkInPlaceLeft
	applymovement 8, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 60
	applymovement 9, Common_Movement_WalkInPlaceUp
	applymovement 8, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 20
	msgbox MossdeepCity_SpaceCenter_2F_Text_2249DC, MSGBOX_DEFAULT
	closemessage
	setvar VAR_MOSSDEEP_STATE, 3
	fadedefaultbgm
	fadescreen 1
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE_2, 3
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	removeobject 5
	removeobject 7
	removeobject 6
	removeobject 8
	removeobject 9
	setobjectxy 3, 5, 6
	turnobject 3, 1
	setobjectxy 2, 11, 8
	turnobject 2, 2
	setobjectxy 1, 6, 2
	turnobject 1, 2
	call MossdeepCity_SpaceCenter_2F_EventScript_224131
	fadescreen 0
	msgbox MossdeepCity_SpaceCenter_2F_Text_224A4A, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	removeobject 4
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_INVISIBLE_NINJA_BOY
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	removeobject 3
	setobjectxyperm 3, 5, 6
	setobjectmovementtype 3, MOVEMENT_TYPE_WANDER_AROUND
	addobject 3
	fadescreen 0
	end

MossdeepCity_SpaceCenter_2F_EventScript_224131:: @ 8224131
	switch VAR_FACING
	case 1, MossdeepCity_SpaceCenter_2F_EventScript_22414D
	case 3, MossdeepCity_SpaceCenter_2F_EventScript_224152
	return

MossdeepCity_SpaceCenter_2F_EventScript_22414D:: @ 822414D
	turnobject 4, 2
	return

MossdeepCity_SpaceCenter_2F_EventScript_224152:: @ 8224152
	turnobject 4, 4
	return

MossdeepCity_SpaceCenter_2F_EventScript_224157:: @ 8224157
	trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_MAXIE_3, 0, MossdeepCity_SpaceCenter_2F_Text_22487C, MossdeepCity_SpaceCenter_2F_Text_22487C
	end

MossdeepCity_SpaceCenter_2F_EventScript_224166:: @ 8224166
	trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_TABITHA_1, 0, MossdeepCity_SpaceCenter_Text_2248AD, MossdeepCity_SpaceCenter_Text_2248AD
	end

MossdeepCity_SpaceCenter_2F_EventScript_224175:: @ 8224175
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_224193
	compare VAR_RESULT, FEMALE
	call_if_eq MossdeepCity_SpaceCenter_2F_EventScript_22419A
	closemessage
	clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_224193:: @ 8224193
	pokenavcall MossdeepCity_SpaceCenter_2F_Text_2B38C1
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_EventScript_22419A:: @ 822419A
	pokenavcall MossdeepCity_SpaceCenter_2F_Text_2B39C6
	waitmessage
	return

MossdeepCity_SpaceCenter_2F_Text_2241A1: @ 82241A1
	.string "MOSSDEEP has mainly sunny weather,\n"
	.string "and its winds are stable.\p"
	.string "It's an ideal location for launching\n"
	.string "rockets.$"

MossdeepCity_SpaceCenter_2F_Text_22420C: @ 822420C
	.string "Why would TEAM MAGMA want to steal\n"
	.string "our rocket fuel in the first place?$"

MossdeepCity_SpaceCenter_2F_Text_224253: @ 8224253
	.string "If only I was a little younger, I would\n"
	.string "have liked being an astronaut…\p"
	.string "No… It's not too late!\n"
	.string "I can and will try!$"

MossdeepCity_SpaceCenter_2F_Text_2242C5: @ 82242C5
	.string "If TEAM MAGMA takes the rocket fuel,\n"
	.string "I won't be able to go to space!\p"
	.string "They can't be allowed to get away\n"
	.string "with such an outrage!$"

MossdeepCity_SpaceCenter_2F_Text_224342: @ 8224342
	.string "I wish ordinary people could go into\n"
	.string "space one day…$"

MossdeepCity_SpaceCenter_2F_Text_224376: @ 8224376
	.string "TEAM MAGMA…\n"
	.string "Do they want to go to space, too?$"

MossdeepCity_SpaceCenter_2F_Text_2243A4: @ 82243A4
	.string "What's wrong with you?\p"
	.string "You're outnumbered three to one,\n"
	.string "but you still want to take us on?$"

MossdeepCity_SpaceCenter_2F_Text_2243FE: @ 82243FE
	.string "Good answer!\n"
	.string "That's what a smart person'll do!$"

MossdeepCity_SpaceCenter_2F_Text_22442D: @ 822442D
	.string "A reckless go-getter, are you?\n"
	.string "Okay, I'll go first!$"

MossdeepCity_SpaceCenter_2F_Text_224461: @ 8224461
	.string "I lost!\n"
	.string "But!$"

MossdeepCity_SpaceCenter_2F_Text_22446E: @ 822446E
	.string "It's too soon to be relieved!\n"
	.string "I'm up next!$"

MossdeepCity_SpaceCenter_2F_Text_224499: @ 8224499
	.string "I lost, too!\n"
	.string "But!$"

MossdeepCity_SpaceCenter_2F_Text_2244AB: @ 82244AB
	.string "I bet you want to take a break.\n"
	.string "But I'm not about to let you do that!$"

MossdeepCity_SpaceCenter_2F_Text_2244F1: @ 82244F1
	.string "We should've taken a break…\n"
	.string "That's what we should've done…$"

MossdeepCity_SpaceCenter_2F_Text_22452C: @ 822452C
	.string "Three of us here, and look at the sorry\n"
	.string "mess we got ourselves into.$"

MossdeepCity_SpaceCenter_2F_Text_224570: @ 8224570
	.string "We three losing like this…\n"
	.string "We look worse than usual by triple!$"

MossdeepCity_SpaceCenter_2F_Text_2245AF: @ 82245AF
	.string "Are we being useful to our leader\n"
	.string "at all?$"

MossdeepCity_SpaceCenter_2F_Text_2245D9: @ 82245D9
	.string "Hehehe!\p"
	.string "We come all the way here to get some\n"
	.string "fuel, and we're interfered with again!\p"
	.string "If you're going to mess with us too,\n"
	.string "we'll take care of you at the same time!$"

MossdeepCity_SpaceCenter_2F_Text_22467B: @ 822467B
	.string "MAXIE: Clear out of the way!\n"
	.string "Don't you dare interfere!$"

MossdeepCity_SpaceCenter_2F_Text_2246B2: @ 82246B2
	.string "STEVEN: TEAM MAGMA…\p"
	.string "What's the point of stealing rocket\n"
	.string "fuel?$"

MossdeepCity_SpaceCenter_2F_Text_2246F0: @ 82246F0
	.string "MAXIE: Fufufu… Since you're so\n"
	.string "curious, you deserve an explanation.\p"
	.string "We're going to jettison the entire\n"
	.string "load into MT. CHIMNEY!\p"
	.string "With GROUDON gone, we have no need\n"
	.string "for that slag heap of a mountain!\p"
	.string "So we'll use the fuel's power to make\n"
	.string "the volcano erupt!\p"
	.string "It will be savage!$"

MossdeepCity_SpaceCenter_2F_Text_2247FF: @ 82247FF
	.string "STEVEN: {PLAYER}{KUN}!\n"
	.string "You're going to help me?\p"
	.string "Let's go into battle together!\n"
	.string "Are you ready?$"

MossdeepCity_SpaceCenter_2F_Text_224854: @ 8224854
	.string "STEVEN: Then, hurry!\n"
	.string "Get ready quickly!$"

MossdeepCity_SpaceCenter_2F_Text_22487C: @ 822487C
	.string "All I want…\n"
	.string "I just want to expand the land mass…$"

MossdeepCity_SpaceCenter_Text_2248AD: @ 82248AD
	.string "I'm with our leader…$"

MossdeepCity_SpaceCenter_2F_Text_2248C2: @ 82248C2
	.string "MAXIE: We failed to make the volcano\n"
	.string "erupt…\p"
	.string "We failed to control GROUDON after\n"
	.string "we had awoken it…\p"
	.string "Is our goal to expand the land\n"
	.string "misguided?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "If…\n"
	.string "If we, TEAM MAGMA, are wrong…\l"
	.string "… … … … … …\p"
	.string "Then might TEAM AQUA's goal to expand\n"
	.string "the sea also be equally misguided?$"

MossdeepCity_SpaceCenter_2F_Text_2249DC: @ 82249DC
	.string "MAXIE: All right…\n"
	.string "We will give up on the fuel…\p"
	.string "There appear to be more important\n"
	.string "matters that I must examine…$"

MossdeepCity_SpaceCenter_2F_Text_224A4A: @ 8224A4A
	.string "STEVEN: Whew, that was too tense.\n"
	.string "{PLAYER}{KUN}, thank you.\p"
	.string "I have something to give you as\n"
	.string "thanks for your support.\p"
	.string "Please come see me at home\n"
	.string "after this.\p"
	.string "Oh, yes, I don't live in RUSTBORO CITY.\n"
	.string "I live right here on this island.$"
