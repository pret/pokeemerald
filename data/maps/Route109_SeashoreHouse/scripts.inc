Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "I'm the owner of the SEASHORE HOUSE.\n"
	.string "But you can call me MR. SEA!\p"
	.string "What I love above all is to see hot\n"
	.string "POKéMON battles.\p"
	.string "Let me see that your heart burns hot!\p"
	.string "If you can defeat all the TRAINERS\n"
	.string "here, I'll reward your efforts.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Show me some hot matches!\p"
	.string "I run this SEASHORE HOUSE just for\n"
	.string "that reason alone!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "You're scorching hot!\n"
	.string "Those battles blazed!\l"
	.string "I'm more than just satisfied!\p"
	.string "As thanks for showing me your hot\n"
	.string "streak, I want you to take these.\p"
	.string "It's half a dozen bottles of SODA POP!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, but hey, your BAG's jammed full.\n"
	.string "I'll hang on to these for you.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Want to buy some SODA POP?\n"
	.string "POKéMON love it!\p"
	.string "Just ¥300 a bottle!\n"
	.string "Buy some!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Here you go!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "You don't have the money.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "No?\n"
	.string "That's too bad.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "If you're looking for a battle in the\n"
	.string "SEASHORE HOUSE, you'll find no\l"
	.string "hotter TRAINER than me, matey!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "That was a hot battle!\n"
	.string "I can accept that loss, matey!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Whenever I'm in SLATEPORT, I enjoy\n"
	.string "hot battles and ice-cold SODA POP!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Boring battles aren't worth the effort.\p"
	.string "Fiery hot battles are what toughen up\n"
	.string "TRAINERS and POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "That's hot!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Whew, I'm all thirsty.\n"
	.string "Maybe I'll have a SODA POP.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "I'm going to show you how great\n"
	.string "my POKéMON are, but don't cry!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…I lost, but I won't cry…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "If one of my POKéMON knew the move\n"
	.string "for carrying me across water on its\l"
	.string "back, I could get rid of this inner tube.$"

