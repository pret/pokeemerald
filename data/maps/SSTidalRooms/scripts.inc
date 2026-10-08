SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "Daar staat een bed…\n"
	.string "Laten we even uitrusten.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Ik vaar vaak naar LILYCOVE CITY.\p"
	.string "Ik ga daar graag naar\n"
	.string "WEDSTRIJDEN kijken.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "Dat was een leuk gevecht!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Ik word zo blij als ik bedenk welke\n"
	.string "POKéMON ik zie bij de volgende\l"
	.string "WEDSTRIJD. Ik kan niet wachten!$"

SSTidalRooms_Text_MicahIntro:
	.string "Zijn jouw vrienden sterk?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Jouw vrienden zijn echt sterk.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Vrienden hoeven geen mensen te zijn.\n"
	.string "POKéMON zijn mijn beste vrienden!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Kind…\n"
	.string "Heb jij op de deur geklopt?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Een verlies neem je aan zonder\n"
	.string "haast of paniek.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Altijd rustig blijven, wat er ook\n"
	.string "gebeurt. Zo doet een HEER dat.$"

SSTidalRooms_Text_JedIntro:
	.string "JED: Ik vind het een beetje eng, maar…\n"
	.string "We laten je onze liefdeskracht zien!$"

SSTidalRooms_Text_JedDefeat:
	.string "JED: Zucht…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED: Voor het eerst werkte onze\n"
	.string "liefdeskracht niet!\l"
	.string "Jij bent vast een super TRAINER!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED: Heb je maar één POKéMON?\n"
	.string "Is dat niet heel eenzaam?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA: Ik voel me een beetje gek, maar…\n"
	.string "We laten je onze liefdeskracht zien!$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA: O, boe!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA: Ik kan het niet geloven!\n"
	.string "Onze liefdeskracht werkte niet…\l"
	.string "Jij bent vast een super TRAINER!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LEA: Ik wilde vechten…\n"
	.string "Maar je hebt niet eens 2 POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, je komt precies op tijd.\p"
	.string "Ik verveel me, zie je.\n"
	.string "Jij mag me vermaken.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Dat is genoeg.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Misschien laat ik Vader een jacht\n"
	.string "voor me kopen.\l"
	.string "Een jacht voor mij en POKéMON!$"

SSTidalRooms_Text_NaomiIntro:
	.string "O, wat ben jij een lieve TRAINER.\n"
	.string "Wil je een kopje thee?\l"
	.string "Of wil je liever vechten?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Ik snap het.\n"
	.string "Jij houdt van actie.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Een wereldreis op een luxe schip\n"
	.string "is heel fijn, dat moet ik zeggen…\p"
	.string "Maar met de boot door HOENN\n"
	.string "reizen is ook heel leuk.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Eh… Hoi! Ik… Ik doe niet verdacht!\n"
	.string "Eh… Dit mag jij hebben! Gratis!\p"
	.string "Het… Echt, ik heb het niet van\n"
	.string "iemand GEGRAAID! Dat doe ik nooit!\l"
	.string "Het is eerlijk! Je mag het gebruiken!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "GRAAIEN steelt de goede effecten\n"
	.string "van sommige aanvallen, voordat\l"
	.string "een vijand of maatje ze gebruikt.$"

