VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "WALLY: Ik verloor van jou, {PLAYER},\n"
	.string "maar ik ben niet meer verdrietig.\p"
	.string "Want ik heb een nieuw doel.\n"
	.string "Samen met mijn RALTS ga ik\l"
	.string "POKéMON GYMS uitdagen en een\l"
	.string "goede TRAINER worden.\p"
	.string "Let maar op, {PLAYER}.\n"
	.string "Ik word sterker dan jij.\p"
	.string "En dan daag ik je opnieuw uit\n"
	.string "voor een gevecht.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "WALLY: Let maar op, {PLAYER}.\n"
	.string "Ik word sterker dan jij.\p"
	.string "En dan daag ik je opnieuw uit\n"
	.string "voor een gevecht.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "OOM: O! {PLAYER}{KUN}!\n"
	.string "WALLY is hiernaast.\p"
	.string "Maar zeg, ik moet je iets\n"
	.string "vertellen.\p"
	.string "De natuur hier doet WALLY\n"
	.string "heel goed.\p"
	.string "Maar misschien is het niet alleen\n"
	.string "de natuur. Misschien geven POKéMON\l"
	.string "de jongen hoop.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "WALLY is weg…\n"
	.string "Hij is in zijn eentje vertrokken…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "OOM: Echt waar?\n"
	.string "Is WALLY in zijn eentje zo ver\l"
	.string "gegaan…\p"
	.string "Nou, petje af. Hij is wel de\n"
	.string "zoon van mijn kleine broertje.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "WANDA: Wie ben jij?\n"
	.string "O ja, ik snap het al!\p"
	.string "Jij bent {PLAYER}. WALLY heeft\n"
	.string "over jou verteld.\p"
	.string "Ik ben de nicht van WALLY.\n"
	.string "Leuk je te ontmoeten!\p"
	.string "WALLY is veel vrolijker en gezonder\n"
	.string "sinds hij hier is.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "WANDA: Maak je geen zorgen om WALLY.\n"
	.string "Het komt wel goed met hem.\p"
	.string "Ik ken mijn neefje, en hij heeft\n"
	.string "ook POKéMON bij zich.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Dankzij jou zie ik mijn vriendin\n"
	.string "elke dag.\l"
	.string "Blij? Nou en of!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Het vriendje van mijn dochter\n"
	.string "geeft nooit op.\p"
	.string "Hij graaft steeds maar aan een\n"
	.string "tunnel, alleen om haar te zien.\p"
	.string "Mijn dochter maakt zich wat zorgen,\n"
	.string "dus ze gaat vaak naar de tunnel.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Ongelooflijk. Het vriendje van mijn\n"
	.string "dochter groef de tunnel met de hand!\p"
	.string "Wat knap!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Als er iets met WALLY gebeurt,\n"
	.string "durf ik zijn ouders in PETALBURG\l"
	.string "nooit meer aan te kijken…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "Was WALLY in EVER GRANDE?\p"
	.string "Zijn ouders in PETALBURG zullen\n"
	.string "stomverbaasd zijn!$"

