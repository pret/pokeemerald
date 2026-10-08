CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	delay 60
	playse SE_PIN
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	delay 30
	applywaitmovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, dus jij bent {PLAYER}{KUN}?\n"
	.string "Ik heb over je daden gehoord.\p"
	.string "Ik ben WALLACE.\p"
	.string "Ik was GYMLEIDER van SOOTOPOLIS,\n"
	.string "maar er kwam iets tussen.\p"
	.string "Nu laat ik de GYM over aan mijn\n"
	.string "leraar JUAN.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON en KYOGRE zijn de twee\n"
	.string "POKéMON die hier chaos maken.\p"
	.string "Ze zijn al heel erg oud.\p"
	.string "Maar er zijn niet alleen twee\n"
	.string "zulke oude POKéMON.\p"
	.string "Er is er nog één, ergens.\p"
	.string "Een heel oude POKéMON, die\n"
	.string "RAYQUAZA heet.\p"
	.string "Het verhaal zegt dat RAYQUAZA die\n"
	.string "twee lang geleden kalm maakte.\p"
	.string "Maar zelfs ik weet niet waar\n"
	.string "RAYQUAZA nu is…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WALLACE: {PLAYER}{KUN}, weet jij\n"
	.string "misschien waar RAYQUAZA nu is?\p"
	.string "Als je het weet, zeg het me dan.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WALLACE: De CAVE OF ORIGIN?\p"
	.string "Maar die is hier!\n"
	.string "Dat kan beter!\p"
	.string "Denk goed na. Waar kan RAYQUAZA\n"
	.string "nu zijn?$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WALLACE: MT. PYRE?\p"
	.string "Maar ik sprak daar net een oude\n"
	.string "dame. Zij zei er niets over.\p"
	.string "Ik denk niet dat zij iets voor\n"
	.string "mij zou verbergen…\p"
	.string "{PLAYER}{KUN}, denk er nog eens\n"
	.string "goed over na, wil je?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE: Hè? Weet je het niet meer?\n"
	.string "Hmm… Dat is jammer…\p"
	.string "Kun je het je echt niet herinneren?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WALLACE: De SKY PILLAR?\p"
	.string "Dat is het!\n"
	.string "Het moet de SKY PILLAR zijn!\p"
	.string "{PLAYER}{KUN}, we hebben haast!\n"
	.string "We gaan meteen naar de SKY PILLAR!$"

