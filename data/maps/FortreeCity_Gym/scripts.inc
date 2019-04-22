FortreeCity_Gym_MapScripts:: @ 82165AB
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_MapScript2_2165BA
	.byte 0

FortreeCity_Gym_OnTransition: @ 82165B6
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_MapScript2_2165BA: @ 82165BA
	map_script_2 VAR_TEMP_0, 16384, FortreeCity_Gym_EventScript_2165C4
	.2byte 0

FortreeCity_Gym_EventScript_2165C4:: @ 82165C4
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_2165C8:: @ 82165C8
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_216D75, FortreeCity_Gym_Text_216E60, FortreeCity_Gym_EventScript_2165FD, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq FortreeCity_Gym_EventScript_21668D
	goto_if_unset FLAG_RECEIVED_TM40, FortreeCity_Gym_EventScript_216646
	msgbox FortreeCity_Gym_Text_217071, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_2165FD:: @ 82165FD
	message FortreeCity_Gym_Text_216EEC
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_216F17, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call FortreeCity_Gym_EventScript_271F43
	call FortreeCity_Gym_EventScript_21666A
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox FortreeCity_Gym_Text_217044, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_WINONA_CALL_STEP_COUNTER, 0
	setflag FLAG_REGISTER_WINONA_POKENAV
	release
	end

FortreeCity_Gym_EventScript_216646:: @ 8216646
	giveitem_std ITEM_TM40
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_216FEC, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	release
	end

FortreeCity_Gym_EventScript_21666A:: @ 821666A
	giveitem_std ITEM_TM40
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_216FEC, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	return

FortreeCity_Gym_EventScript_21668D:: @ 821668D
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_217100, FortreeCity_Gym_Text_2171E6, FortreeCity_Gym_Text_217292
	msgbox FortreeCity_Gym_Text_21720B, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_2166A8:: @ 82166A8
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_2168A2, FortreeCity_Gym_Text_2168D3
	msgbox FortreeCity_Gym_Text_2168E7, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_2166BF:: @ 82166BF
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_21695A, FortreeCity_Gym_Text_2169C7
	msgbox FortreeCity_Gym_Text_2169F1, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_2166D6:: @ 82166D6
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_216A66, FortreeCity_Gym_Text_216AC4
	msgbox FortreeCity_Gym_Text_216AD7, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_2166ED:: @ 82166ED
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_216B1A, FortreeCity_Gym_Text_216B51
	msgbox FortreeCity_Gym_Text_216B5F, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_216704:: @ 8216704
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_216B9E, FortreeCity_Gym_Text_216C18
	msgbox FortreeCity_Gym_Text_216C32, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_21671B:: @ 821671B
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_216C96, FortreeCity_Gym_Text_216CF2
	msgbox FortreeCity_Gym_Text_216D0F, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_216732:: @ 8216732
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_216747
	msgbox FortreeCity_Gym_Text_216785, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_216747:: @ 8216747
	msgbox FortreeCity_Gym_Text_21687D, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_216751:: @ 8216751
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_216771
	goto FortreeCity_Gym_EventScript_21677B
	end

FortreeCity_Gym_EventScript_216761:: @ 8216761
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_216771
	goto FortreeCity_Gym_EventScript_21677B
	end

FortreeCity_Gym_EventScript_216771:: @ 8216771
	msgbox FortreeCity_Gym_Text_2170C7, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_21677B:: @ 821677B
	msgbox FortreeCity_Gym_Text_2170AE, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_216785: @ 8216785
	.string "Yo, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "FORTREE GYM LEADER WINONA is\n"
	.string "a master of FLYING-type POKéMON.\p"
	.string "She's waiting at the back of this GYM,\n"
	.string "behind the rotating doors.\p"
	.string "She's waiting for new challengers\n"
	.string "who are trying to take wing!\p"
	.string "Okay, go for it!$"

FortreeCity_Gym_Text_21687D: @ 821687D
	.string "You did it!\n"
	.string "You've achieved liftoff!$"

FortreeCity_Gym_Text_2168A2: @ 82168A2
	.string "Behold the elegant battle style of\n"
	.string "BIRD POKéMON!$"

FortreeCity_Gym_Text_2168D3: @ 82168D3
	.string "You…\n"
	.string "You're strong…$"

FortreeCity_Gym_Text_2168E7: @ 82168E7
	.string "A TRAINER has to be smart to keep\n"
	.string "up with unexpected turns of events.\p"
	.string "Do you have the smarts to get to\n"
	.string "our LEADER?$"

FortreeCity_Gym_Text_21695A: @ 821695A
	.string "The lovers of BIRD POKéMON aspire\n"
	.string "to join this GYM.\p"
	.string "As a member of the FORTREE GYM,\n"
	.string "I'm not allowed to lose!$"

FortreeCity_Gym_Text_2169C7: @ 82169C7
	.string "It was too much of a load for me\n"
	.string "to bear…$"

FortreeCity_Gym_Text_2169F1: @ 82169F1
	.string "The world is huge, and there are\n"
	.string "countless tough TRAINERS.\p"
	.string "I'm going to keep training and make\n"
	.string "myself even stronger.$"

FortreeCity_Gym_Text_216A66: @ 8216A66
	.string "There's no need for WINONA, our GYM\n"
	.string "LEADER, to deal with you!\p"
	.string "I'm plenty good enough for you!$"

FortreeCity_Gym_Text_216AC4: @ 8216AC4
	.string "WINONA, I…\n"
	.string "I lost!$"

FortreeCity_Gym_Text_216AD7: @ 8216AD7
	.string "WINONA is cute and she's strong.\n"
	.string "She's the ultimate LEADER!\p"
	.string "Blush…$"

FortreeCity_Gym_Text_216B1A: @ 8216B1A
	.string "WINONA taught me personally!\n"
	.string "You can't beat me easily!$"

FortreeCity_Gym_Text_216B51: @ 8216B51
	.string "I was beaten…$"

FortreeCity_Gym_Text_216B5F: @ 8216B5F
	.string "Thanks to WINONA, the people of\n"
	.string "FORTREE can live without fear.$"

FortreeCity_Gym_Text_216B9E: @ 8216B9E
	.string "When WINONA takes to battle, her face\n"
	.string "shines with beautiful determination…\p"
	.string "I'm not letting you witness that\n"
	.string "lovely sight!$"

FortreeCity_Gym_Text_216C18: @ 8216C18
	.string "Urk!\n"
	.string "I couldn't stop you.$"

FortreeCity_Gym_Text_216C32: @ 8216C32
	.string "You'd better watch it!\n"
	.string "Don't get distracted staring at WINONA\l"
	.string "or you'll go crashing down in a heap!$"

FortreeCity_Gym_Text_216C96: @ 8216C96
	.string "You'd better know that there are all\n"
	.string "sorts of FLYING-type POKéMON.\p"
	.string "You do know that, right?$"

FortreeCity_Gym_Text_216CF2: @ 8216CF2
	.string "You seem to know your stuff!$"

FortreeCity_Gym_Text_216D0F: @ 8216D0F
	.string "Sure, you beat me all right.\n"
	.string "But you'd better watch it! Our LEADER\l"
	.string "WINONA's POKéMON are all business.$"

FortreeCity_Gym_Text_216D75: @ 8216D75
	.string "I am WINONA. I am the LEADER of\n"
	.string "the FORTREE POKéMON GYM.\p"
	.string "I have become one with BIRD POKéMON\n"
	.string "and have soared the skies…\p"
	.string "However grueling the battle, we have\n"
	.string "triumphed with grace…\p"
	.string "Witness the elegant choreography\n"
	.string "of BIRD POKéMON and I!$"

FortreeCity_Gym_Text_216E60: @ 8216E60
	.string "Never before have I seen a TRAINER\n"
	.string "command POKéMON with more grace\l"
	.string "than I…\p"
	.string "In recognition of your prowess,\n"
	.string "I present to you this GYM BADGE.$"

FortreeCity_Gym_Text_216EEC: @ 8216EEC
	.string "{PLAYER} received the FEATHER BADGE\n"
	.string "from WINONA.$"

FortreeCity_Gym_Text_216F17: @ 8216F17
	.string "With the FEATHER BADGE, all POKéMON up\n"
	.string "to LV 70, even those received through\l"
	.string "trades, will obey your every command.\p"
	.string "You will also be able to use\n"
	.string "the HM move FLY outside of battle.\p"
	.string "And this…\n"
	.string "This is a gift from me.$"

FortreeCity_Gym_Text_216FEC: @ 8216FEC
	.string "TM40 contains AERIAL ACE.\p"
	.string "Its speed…\n"
	.string "No POKéMON should be able to avoid it.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_217044: @ 8217044
	.string "Registered GYM LEADER WINONA\n"
	.string "in the POKéNAV.$"

FortreeCity_Gym_Text_217071: @ 8217071
	.string "Though I fell to you, I will remain\n"
	.string "devoted to BIRD POKéMON.$"

FortreeCity_Gym_Text_2170AE: @ 82170AE
	.string "FORTREE CITY POKéMON GYM$"

FortreeCity_Gym_Text_2170C7: @ 82170C7
	.string "FORTREE CITY POKéMON GYM\p"
	.string "WINONA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_217100: @ 8217100
	.string "WINONA: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning CHAMPION.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!$"

FortreeCity_Gym_Text_2171E6: @ 82171E6
	.string "I failed to reach your height again…$"

FortreeCity_Gym_Text_21720B: @ 821720B
	.string "WINONA: Even though I have lost,\n"
	.string "the wings of my heart remain unbroken.\p"
	.string "I can rise and soar again and\n"
	.string "yet again.\p"
	.string "I am convinced of it!$"

FortreeCity_Gym_Text_217292: @ 8217292
	.string "WINONA: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning CHAMPION.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!\p"
	.string "Oh, no… Do you have but one\n"
	.string "POKéMON with you?\p"
	.string "Please return with two POKéMON\n"
	.string "at the very least.$"
