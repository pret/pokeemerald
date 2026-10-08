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
	.string "Ik ben de baas van het SEASHORE\n"
	.string "HOUSE. Noem me maar MR. SEA!\p"
	.string "Ik hou het meest van hete\n"
	.string "POKéMON-gevechten.\p"
	.string "Laat zien dat jouw hart brandt!\p"
	.string "Als je alle TRAINERS hier verslaat,\n"
	.string "krijg je een beloning van mij.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Laat me hete gevechten zien!\p"
	.string "Daarom heb ik dit SEASHORE HOUSE!\n"
	.string "Alleen daarom!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Jij bent gloeiend heet!\n"
	.string "Wat een vurige gevechten!\l"
	.string "Ik ben heel tevreden!\p"
	.string "Als dank voor je hete gevechten\n"
	.string "krijg je deze van mij.\p"
	.string "Het zijn 6 flessen FRISDRANK!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "O, maar je TAS is propvol.\n"
	.string "Ik bewaar ze wel voor je.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Wil je FRISDRANK kopen?\n"
	.string "POKéMON zijn er dol op!\p"
	.string "Maar ¥300 per fles!\n"
	.string "Koop wat!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Alsjeblieft!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Je hebt niet genoeg geld.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Nee?\n"
	.string "Dat is jammer.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Zoek je een gevecht in het\n"
	.string "SEASHORE HOUSE? Niemand is\l"
	.string "heter dan ik, maatje!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Wat een heet gevecht!\n"
	.string "Dit verlies is oké, maatje!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "In SLATEPORT hou ik van hete\n"
	.string "gevechten en ijskoude FRISDRANK!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Saaie gevechten zijn niks waard.\p"
	.string "Van hete gevechten worden TRAINERS\n"
	.string "en POKéMON sterk!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Dat is heet!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Pfoe, ik heb dorst.\n"
	.string "Misschien neem ik een FRISDRANK.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Ik laat zien hoe goed mijn\n"
	.string "POKéMON zijn, maar niet huilen!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…Ik heb verloren, maar ik huil niet…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Als mijn POKéMON me op zijn rug\n"
	.string "over het water kon dragen, had ik\l"
	.string "deze zwemband niet meer nodig.$"

