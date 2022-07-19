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
	.string "Je suis le propriétaire de la MAISON\n"
	.string "DU BORD DE MER, mais tu peux m’appeler\l"
	.string "M. MER!\p"
	.string "Ce que j’aime par-dessus tout, ce sont\n"
	.string "les combats endiablés de POKéMON.\p"
	.string "Voyons si tu as un esprit combatif!\p"
	.string "Si tu peux vaincre tous ces DRESSEURS,\n"
	.string "je t’offrirai une récompense.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Montre-moi de beaux combats!\p"
	.string "Après tout, c’est pour ça que je dirige\n"
	.string "la MAISON DU BORD DE MER!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Bravo, ça c’était du combat qui tue!\n"
	.string "Ces combats étaient incroyables! J’en\l"
	.string "ai eu pour mon argent!\p"
	.string "Pour te remercier de m’avoir offert un\n"
	.string "tel spectacle, je vais t’offrir ça.\p"
	.string "Une demi-douzaine de bouteilles de\n"
	.string "SODA COOL!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, mais dis-moi, ton SAC est plein. Je\n"
	.string "vais garder ça pour toi.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Tu veux acheter du SODA COOL?\n"
	.string "Les POKéMON adorent ça!\p"
	.string "C’est 300¥ la bouteille!\n"
	.string "Achètes-en!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Voilà!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Tu n’as pas assez d’argent.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Non?\n"
	.string "Tant pis.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Si tu cherches un combat en haute mer,\n"
	.string "je suis ton homme. Le meilleur\l"
	.string "de tous, petit matelot!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "C’était un beau combat!\n"
	.string "J’accepte la défaite, mon pote!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Quand je suis à POIVRESSEL,\n"
	.string "je me bats et je bois du SODA COOL!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Moi, je ne perds pas mon temps avec des\n"
	.string "combats qui n’en valent pas la peine.\p"
	.string "Au moins, les combats endiablés enri-\n"
	.string "chissent les DRESSEURS et les POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "J’ai pas eu le temps de m’ennuyer!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "J’ai soif, maintenant. Je vais aller\n"
	.string "boire un SODA COOL.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Je vais te montrer la puissance de mes\n"
	.string "POKéMON, mais ne viens pas pleurer!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "J’ai perdu, mais je ne vais pas pleurer…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Si un de mes POKéMON pouvait me\n"
	.string "transporter sur son dos, je ne serais\l"
	.string "pas obligé de garder cette bouée.$"

