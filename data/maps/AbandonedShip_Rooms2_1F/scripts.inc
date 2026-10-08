AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: We zochten een schat,\n"
	.string "maar we vonden een TRAINER!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: Zelfs samen konden we\n"
	.string "niet winnen…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: We vinden geen schatten…\n"
	.string "Heeft iemand ze al gevonden?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Je hebt niet eens 2 POKéMON.\n"
	.string "Zo kun je ons nooit verslaan.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: O?\n"
	.string "We zochten een schat.\l"
	.string "Maar we vonden een TRAINER!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: Oeh, wat sterk!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: Waar zou de schat zijn?\p"
	.string "Ik weet al wat ik ga kopen\n"
	.string "als we de schat vinden!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: O, je hebt geen 2 POKéMON?\n"
	.string "Dan vechten we een andere keer!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: O, ik word zo boos op je!\n"
	.string "Ik zet je in mijn POKéNAV!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: We zoeken al die tijd\n"
	.string "naar schatten.\p"
	.string "Onze POKéMON zijn ook sterker.\n"
	.string "Zullen we het je laten zien?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Jij bent sterk, zoals altijd!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: We vinden geen schatten,\n"
	.string "we verliezen met POKéMON…\p"
	.string "Ik wil naar huis… Maar als ik dat\n"
	.string "zeg, wordt zij heel boos…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Je hebt niet eens 2 POKéMON.\n"
	.string "Zo kun je ons nooit verslaan.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: O? Daar ben je weer!\p"
	.string "Jij zoekt ook nog steeds naar\n"
	.string "schatten, of niet?\p"
	.string "Wie verliest, moet stoppen met\n"
	.string "zoeken. Goed?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: O, weer verloren…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: We gaan pas weg als onze\n"
	.string "POKéMON sterker zijn en we de\l"
	.string "schat hier hebben gevonden!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: O, je hebt geen 2 POKéMON?\n"
	.string "Dan vechten we een andere keer!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Ik kan niet goed zwemmen,\n"
	.string "maar wel goed vechten!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Oeps.\n"
	.string "Dat ging niet zo goed.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Op blote voeten door dit schip\n"
	.string "lopen is best vies.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Kracht en een goed hart…\n"
	.string "Dat zijn de schatten van een TRAINER!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, er is iets aan jou\n"
	.string "dat schittert.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "In een hut ergens op dit schip\n"
	.string "zag ik iets schitteren.$"
