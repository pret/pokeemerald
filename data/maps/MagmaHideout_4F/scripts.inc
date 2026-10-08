MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Ik wil GROUDON ook zien, maar ze\n"
	.string "laten me niet eens zijn staart zien…\p"
	.string "Ik word er echt chagrijnig van.\p"
	.string "Oh nee!\n"
	.string "Ik verklapte GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Winnen is onmogelijk als je\n"
	.string "geen rustig hoofd hebt…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Heeft GROUDON eigenlijk wel\n"
	.string "een staart?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Binnenkort! Heel binnenkort!\l"
	.string "Bereiken we ons grote doel!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "Ik kwam zo ver, en nu dit?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAXIE, meneer!\n"
	.string "Een indringer komt uw kant op!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Je bent nog niet klaar!\n"
	.string "Je komt niet zomaar langs me!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Was ik zo makkelijk te verslaan?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "K-kom op, nog één gevecht…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe!\n"
	.string "Je kwam zo ver, dus ik vertel het!\p"
	.string "Ja, echt!\n"
	.string "Verderop slaapt GROUDON!\p"
	.string "MAXIE ging net een paar\n"
	.string "seconden geleden naar GROUDON!\p"
	.string "Hij wordt zo wakker!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Weer verslagen…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…En terwijl je tijd met mij\n"
	.string "verspilde, heeft MAXIE GROUDON\l"
	.string "vast gewekt…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: GROUDON…\p"
	.string "Niets kon je wekken uit je slaap\n"
	.string "in het magma…\p"
	.string "De BLAUWE BOL is wat je zocht.\n"
	.string "Toch?\p"
	.string "Ik heb je de BLAUWE BOL gebracht.\n"
	.string "Laat zijn glans je wekken!\p"
	.string "En laat me zien…\n"
	.string "Laat me al je kracht zien!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: GROUDON!\n"
	.string "Wat is er?\p"
	.string "Was de BLAUWE BOL niet de sleutel?\p"
	.string "GROUDON!\n"
	.string "Waar ben je heen…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAXIE: Oh, jij was het?\p"
	.string "Ik zag je ongevraagd overal\n"
	.string "rondsnuffelen…\p"
	.string "Nu snap ik het!\n"
	.string "Jij hebt vals gespeeld!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Waarom ben je zo goed met\n"
	.string "POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAXIE: GROUDON moet een reden\n"
	.string "hebben gehad om te vluchten…\p"
	.string "Dat probeer je te zeggen,\n"
	.string "hè?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Pfff…\n"
	.string "Denk je dat ik dat niet wist?\p"
	.string "Zonder GROUDON hebben we geen\n"
	.string "behoefte meer aan deze vulkaan.\p"
	.string "Ik ga GROUDON achterna, dus hier\n"
	.string "scheiden onze wegen!$"
