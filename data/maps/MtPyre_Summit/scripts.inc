MtPyre_Summit_MapScripts:: @ 8231FF7
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition: @ 8231FFD
	compare VAR_MT_PYRE_STATE, 2
	call_if_eq MtPyre_Summit_EventScript_232009
	end

MtPyre_Summit_EventScript_232009:: @ 8232009
	setobjectxyperm 8, 23, 6
	setobjectxyperm 2, 22, 6
	end

MtPyre_Summit_EventScript_232018:: @ 8232018
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_23203C
	end

MtPyre_Summit_EventScript_232024:: @ 8232024
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_23203C
	end

MtPyre_Summit_EventScript_232030:: @ 8232030
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_23203C
	end

MtPyre_Summit_EventScript_23203C:: @ 823203C
	playbgm MUS_AQA_0, 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 50
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_2320E0
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_2320EB
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_2320EC
	msgbox MtPyre_Summit_Text_23281A, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	removeobject 2
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen 0
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_2320F7
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_23210C
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_232117
	msgbox MtPyre_Summit_Text_23290E, MSGBOX_DEFAULT
	giveitem_std ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_2320E0:: @ 82320E0
	applymovement 2, MtPyre_Summit_Movement_232136
	waitmovement 0
	return

MtPyre_Summit_EventScript_2320EB:: @ 82320EB
	return

MtPyre_Summit_EventScript_2320EC:: @ 82320EC
	applymovement 2, MtPyre_Summit_Movement_232139
	waitmovement 0
	return

MtPyre_Summit_EventScript_2320F7:: @ 82320F7
	applymovement 3, MtPyre_Summit_Movement_23212C
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_23210C:: @ 823210C
	applymovement 3, MtPyre_Summit_Movement_232130
	waitmovement 0
	return

MtPyre_Summit_EventScript_232117:: @ 8232117
	applymovement 3, MtPyre_Summit_Movement_232132
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_23212C: @ 823212C
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_232130: @ 8232130
	walk_down
	step_end

MtPyre_Summit_Movement_232132: @ 8232132
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_232136: @ 8232136
	walk_left
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_232139: @ 8232139
	walk_right
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_EventScript_23213C:: @ 823213C
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_232167
	msgbox MtPyre_Summit_Text_232E0C, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq MtPyre_Summit_EventScript_232187
	compare VAR_RESULT, 0
	call_if_eq MtPyre_Summit_EventScript_232190
	release
	end

MtPyre_Summit_EventScript_232167:: @ 8232167
	msgbox MtPyre_Summit_Text_2331A6, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq MtPyre_Summit_EventScript_232199
	compare VAR_RESULT, 0
	call_if_eq MtPyre_Summit_EventScript_232190
	release
	end

MtPyre_Summit_EventScript_232187:: @ 8232187
	msgbox MtPyre_Summit_Text_232F27, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_232190:: @ 8232190
	msgbox MtPyre_Summit_Text_233162, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_232199:: @ 8232199
	msgbox MtPyre_Summit_Text_23325D, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_2321A2:: @ 82321A2
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_2321E2
	compare VAR_MT_PYRE_STATE, 3
	call_if_ge MtPyre_Summit_EventScript_2321CB
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_2321D8
	msgbox MtPyre_Summit_Text_232AD8, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_2321CB:: @ 82321CB
	msgbox MtPyre_Summit_Text_232CA6, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_2321D8:: @ 82321D8
	msgbox MtPyre_Summit_Text_232B4F, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_2321E2:: @ 82321E2
	msgbox MtPyre_Summit_Text_232D1E, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_2321EC:: @ 82321EC
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_232210
	end

MtPyre_Summit_EventScript_2321F8:: @ 82321F8
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_232210
	end

MtPyre_Summit_EventScript_232204:: @ 8232204
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_232210
	end

MtPyre_Summit_EventScript_232210:: @ 8232210
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 60
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_2322C4
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_2322DD
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_2322F6
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	delay 30
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_23230F
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_232328
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_232341
	msgbox MtPyre_Summit_Text_233183, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_23235A
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_232376
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_232392
	delay 30
	applymovement 2, MtPyre_Summit_Movement_2323B6
	applymovement 8, MtPyre_Summit_Movement_2323BD
	waitmovement 0
	removeobject 2
	removeobject 8
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_2322C4:: @ 82322C4
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323C4
	applymovement 2, MtPyre_Summit_Movement_2323B6
	applymovement 8, MtPyre_Summit_Movement_2323BD
	waitmovement 0
	return

MtPyre_Summit_EventScript_2322DD:: @ 82322DD
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323CB
	applymovement 2, MtPyre_Summit_Movement_2323B6
	applymovement 8, MtPyre_Summit_Movement_2323BD
	waitmovement 0
	return

MtPyre_Summit_EventScript_2322F6:: @ 82322F6
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323D2
	applymovement 2, MtPyre_Summit_Movement_2323B6
	applymovement 8, MtPyre_Summit_Movement_2323BD
	waitmovement 0
	return

MtPyre_Summit_EventScript_23230F:: @ 823230F
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323AE
	applymovement 2, MtPyre_Summit_Movement_2323E7
	applymovement 8, MtPyre_Summit_Movement_2323D8
	waitmovement 0
	return

MtPyre_Summit_EventScript_232328:: @ 8232328
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323B2
	applymovement 2, MtPyre_Summit_Movement_2323E7
	applymovement 8, MtPyre_Summit_Movement_2323DD
	waitmovement 0
	return

MtPyre_Summit_EventScript_232341:: @ 8232341
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323B2
	applymovement 2, MtPyre_Summit_Movement_2323E7
	applymovement 8, MtPyre_Summit_Movement_2323E2
	waitmovement 0
	return

MtPyre_Summit_EventScript_23235A:: @ 823235A
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323EA
	applymovement 8, MtPyre_Summit_Movement_2323ED
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_232376:: @ 8232376
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323EA
	applymovement 8, MtPyre_Summit_Movement_2323F3
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_232392:: @ 8232392
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323EA
	applymovement 8, MtPyre_Summit_Movement_2323F8
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

MtPyre_Summit_Movement_2323AE: @ 82323AE
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_2323B2: @ 82323B2
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_2323B6: @ 82323B6
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_2323BD: @ 82323BD
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_2323C4: @ 82323C4
	delay_16
	delay_8
	walk_left
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_2323CB: @ 82323CB
	delay_16
	delay_8
	walk_right
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_2323D2: @ 82323D2
	delay_16
	delay_8
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_2323D8: @ 82323D8
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_2323DD: @ 82323DD
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_2323E2: @ 82323E2
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_2323E7: @ 82323E7
	delay_16
	walk_in_place_fastest_up
	step_end

MtPyre_Summit_Movement_2323EA: @ 82323EA
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_2323ED: @ 82323ED
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_2323F3: @ 82323F3
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_2323F8: @ 82323F8
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_EventScript_2323FD:: @ 82323FD
	trainerbattle_single TRAINER_GRUNT_17, MtPyre_Summit_Text_232459, MtPyre_Summit_Text_2324A0
	msgbox MtPyre_Summit_Text_2324E0, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_232414:: @ 8232414
	trainerbattle_single TRAINER_GRUNT_18, MtPyre_Summit_Text_232513, MtPyre_Summit_Text_2325B0
	msgbox MtPyre_Summit_Text_2325E4, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_23242B:: @ 823242B
	trainerbattle_single TRAINER_GRUNT_19, MtPyre_Summit_Text_23261D, MtPyre_Summit_Text_232678
	msgbox MtPyre_Summit_Text_2326B3, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_232442:: @ 8232442
	trainerbattle_single TRAINER_GRUNT_29, MtPyre_Summit_Text_23271B, MtPyre_Summit_Text_23279A
	msgbox MtPyre_Summit_Text_2327D8, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_232459: @ 8232459
	.string "No! Those TEAM MAGMA goons got\n"
	.string "here ahead of us!\p"
	.string "We can't fall behind!$"

MtPyre_Summit_Text_2324A0: @ 82324A0
	.string "I thought you were one of the MAGMAS\n"
	.string "who happened to come back…$"

MtPyre_Summit_Text_2324E0: @ 82324E0
	.string "Yeah, so you are strong…\n"
	.string "But there're a lot of us!$"

MtPyre_Summit_Text_232513: @ 8232513
	.string "Hah!\n"
	.string "Too bad for you!\p"
	.string "If you came earlier, you only would've\n"
	.string "had to battle the wimpy TEAM MAGMA.\p"
	.string "But since you arrived now, you have\n"
	.string "to take on us toughies!$"

MtPyre_Summit_Text_2325B0: @ 82325B0
	.string "Urgh… I should've let you take on\n"
	.string "TEAM MAGMA first…$"

MtPyre_Summit_Text_2325E4: @ 82325E4
	.string "You don't know anything!\n"
	.string "So why are you messing with us?$"

MtPyre_Summit_Text_23261D: @ 823261D
	.string "You…\n"
	.string "We saw you at MT. CHIMNEY.\p"
	.string "You don't belong to either TEAM,\n"
	.string "so why would you be here?$"

MtPyre_Summit_Text_232678: @ 8232678
	.string "If you're going to mess with anyone,\n"
	.string "let it be TEAM MAGMA…$"

MtPyre_Summit_Text_2326B3: @ 82326B3
	.string "Heh, it doesn't matter!\n"
	.string "We bought ourselves some time!\p"
	.string "The BOSS should have snatched what\n"
	.string "he was after!$"

MtPyre_Summit_Text_23271B: @ 823271B
	.string "Oh, I know!\n"
	.string "You tried to join TEAM MAGMA,\l"
	.string "but they wouldn't have you!\p"
	.string "Well, don't think that we'll let you\n"
	.string "join our TEAM AQUA!$"

MtPyre_Summit_Text_23279A: @ 823279A
	.string "If you want to join TEAM AQUA that\n"
	.string "badly, we can consider it…$"

MtPyre_Summit_Text_2327D8: @ 82327D8
	.string "We have a great combination going\n"
	.string "with us members and our leader.$"

MtPyre_Summit_Text_23281A: @ 823281A
	.string "ARCHIE: TEAM MAGMA's MAXIE got ahead\n"
	.string "of us, but we also got what we wanted.\p"
	.string "The RED ORB preserved at MT. PYRE…\n"
	.string "I, ARCHIE, now have it in my possession!\p"
	.string "Fufufu… Now we can bring our ultimate\n"
	.string "objective to fruition!\p"
	.string "Okay, TEAM!\n"
	.string "We're pulling out!$"

MtPyre_Summit_Text_23290E: @ 823290E
	.string "Oh, no…\n"
	.string "This cannot happen…\p"
	.string "Not only the BLUE ORB, but even\n"
	.string "the RED ORB has been taken…\p"
	.string "The BLUE ORB and RED ORB must never\n"
	.string "be separated. They belong together.\p"
	.string "What are those men trying to do with\n"
	.string "the two ORBS?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, yes. Was it TEAM MAGMA who came\n"
	.string "and took the BLUE ORB first?\p"
	.string "Well, in their haste, they left this\n"
	.string "behind.\p"
	.string "I couldn't imagine what exactly it\n"
	.string "could be.\p"
	.string "I would like you to have it.\n"
	.string "Perhaps it will be useful in some way.$"

MtPyre_Summit_Text_232AD8: @ 8232AD8
	.string "The BLUE ORB and RED ORB taken by\n"
	.string "those sinister men…\p"
	.string "They must never be apart…\n"
	.string "I fear something terrible will happen…$"

MtPyre_Summit_Text_232B4F: @ 8232B4F
	.string "Oh, my goodness…\p"
	.string "You say that both GROUDON and KYOGRE\n"
	.string "have been awakened?\p"
	.string "It is said that the BLUE ORB and\n"
	.string "the RED ORB quelled the rage of\l"
	.string "the two POKéMON…\p"
	.string "It is also said that the true owner\n"
	.string "of the ORBS still exists.\p"
	.string "However, no one knows who, or what\n"
	.string "exactly, the ORBS belong to.\p"
	.string "It could be a human, or perhaps\n"
	.string "a POKéMON, but no one knows.$"

MtPyre_Summit_Text_232CA6: @ 8232CA6
	.string "The two men who took the ORBS came\n"
	.string "back to return them on their own.\p"
	.string "Those men…\n"
	.string "Perhaps they are not so evil after all…$"

MtPyre_Summit_Text_232D1E: @ 8232D1E
	.string "The embodiments of the land, sea,\n"
	.string "and the sky…\p"
	.string "That is said to be the identities of\n"
	.string "the super-ancient POKéMON…\p"
	.string "In the same way that we humans and\n"
	.string "POKéMON have life, our world, too,\l"
	.string "is alive…\p"
	.string "The super-ancient POKéMON have\n"
	.string "taught us that…$"

MtPyre_Summit_Text_232E0C: @ 8232E0C
	.string "MT. PYRE is where we calm the spirits\n"
	.string "of POKéMON that have passed on…\p"
	.string "This is a high place where one can\n"
	.string "see all of HOENN…\p"
	.string "The disembodied spirits of POKéMON\n"
	.string "must find solace here…\p"
	.string "Is it coincidence that you are here…\p"
	.string "Will you hear out my tale? A tale long\n"
	.string "told in the HOENN region?$"

MtPyre_Summit_Text_232F27: @ 8232F27
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the POKéMON of the land\l"
	.string "and the POKéMON of the sea…\p"
	.string "The POKéMON of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The POKéMON of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "infernos and vicious storms.\p"
	.string "The BLUE ORB and the RED ORB brought\n"
	.string "an end to the calamity.\p"
	.string "Light poured from the two ORBS and\n"
	.string "becalmed the enraged adversaries.\p"
	.string "The pair, made docile, dove deep into\n"
	.string "the sea where eventually they\l"
	.string "disappeared…$"

MtPyre_Summit_Text_233162: @ 8233162
	.string "I see…\n"
	.string "Well, that, too, is fine…$"

MtPyre_Summit_Text_233183: @ 8233183
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_2331A6: @ 82331A6
	.string "It is my role to pass on the legends\n"
	.string "of HOENN to future generations.\p"
	.string "And the crisis that just ended in\n"
	.string "SOOTOPOLIS rewrote a legend…\p"
	.string "Have you the time to hear the new\n"
	.string "legend of HOENN?$"

MtPyre_Summit_Text_23325D: @ 823325D
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the POKéMON of the land\l"
	.string "and the POKéMON of the sea…\p"
	.string "The POKéMON of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The POKéMON of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "fires and vicious storms.\p"
	.string "It was then that the POKéMON of\n"
	.string "the sky descended from a storm.\p"
	.string "The POKéMON, shining a vivid green,\n"
	.string "becalmed the two enraged POKéMON.\p"
	.string "Then, its duty done, the green POKéMON\n"
	.string "flew off into the wild blue yonder…$"

