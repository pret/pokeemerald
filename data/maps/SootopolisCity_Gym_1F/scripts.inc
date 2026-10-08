SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applywaitmovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo! Hoe gaat het, toekomstige\n"
	.string "KAMPIOEN {PLAYER}?\p"
	.string "De GYMLEIDER JUAN van SOOTOPOLIS\n"
	.string "is een meester in WATER-POKéMON.\p"
	.string "En om bij JUAN te komen, houdt\n"
	.string "een gladde ijsvloer je tegen…\p"
	.string "Sorry, maar meer tips heb ik\n"
	.string "niet voor je.\p"
	.string "Het laatste stuk moet je zelf\n"
	.string "doen!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! Je versloeg zelfs JUAN, die\n"
	.string "de beste van heel HOENN zou zijn!\p"
	.string "Oké! Kijk eens naar je TRAINERKAART.\p"
	.string "Als je alle BADGES hebt, ben je\n"
	.string "klaar voor de POKéMON LEAGUE!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Mag ik je iets vragen.\n"
	.string "Wist je het?\l"
	.string "Ah, ik hoef niet zo geheimzinnig te zijn.\p"
	.string "Ik leerde WALLACE alles wat er te\n"
	.string "weten valt over POKéMON.\p"
	.string "Eens gaf ik mijn plek als\n"
	.string "GYMLEIDER op.\p"
	.string "Ik liet WALLACE de GYM leiden.\p"
	.string "Maar er kwam een goede reden\n"
	.string "om terug te komen.\p"
	.string "Ah, genoeg gepraat.\n"
	.string "Laten we beginnen, zullen we?\p"
	.string "Zie en getuig van onze kunst.\p"
	.string "Een grote waterillusie, gevormd\n"
	.string "door POKéMON en mijzelf!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Hahaha, uitstekend!\n"
	.string "Jij bent de winnaar.\p"
	.string "Ik voel bij jou de stralende glans\n"
	.string "van een talent dat alles overwint.\p"
	.string "Maar vergeleken met mij of zelfs\n"
	.string "WALLACE mis je wat sierlijkheid.\p"
	.string "Misschien leen ik je mijn kleren?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Haha, ik maak maar een grapje!\p"
	.string "In plaats van mijn kleren geef ik\n"
	.string "je dit, de RAIN BADGE!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} krijgt de RAIN BADGE\n"
	.string "van JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Met de RAIN BADGE luisteren al je\n"
	.string "POKéMON helemaal naar je.\p"
	.string "Met de RAIN BADGE kun je ook de\n"
	.string "HM-aanval WATERVAL gebruiken om\l"
	.string "omhoog te klimmen langs water.\p"
	.string "En zodat je ons gevecht nooit\n"
	.string "vergeet, neem dit…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "De TECHNISCHE MACHINE die ik je gaf\n"
	.string "bevat WATERPULS.\p"
	.string "Die kan het doelwit soms in de\n"
	.string "war brengen met ultrageluid.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "GYMLEIDER JUAN staat nu\n"
	.string "in de POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "TRAINERS met alle GYM BADGES van\n"
	.string "HOENN gaan naar de eindbestemming.\p"
	.string "De POKéMON LEAGUE.\p"
	.string "Reis naar het uiterste oosten\n"
	.string "van HOENN, naar het eiland EVER GRANDE.\p"
	.string "Daar vind je de POKéMON\n"
	.string "LEAGUE.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Je mist nog één BADGE in HOENN.\p"
	.string "Wil je de POKéMON LEAGUE\n"
	.string "uitdagen, haal dan de laatste\l"
	.string "BADGE bij de GYM in FORTREE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "SOOTOPOLIS CITY POKéMON GYM$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "SOOTOPOLIS CITY POKéMON GYM\p"
	.string "TRAINERS GEKEURD DOOR JUAN:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "JUAN: Ah, deze GYM was weer rustig…\p"
	.string "Maar onze jonge storm is terug\n"
	.string "om ons weer te testen!\p"
	.string "Nou, mijn vriend, zeker!\p"
	.string "Ik dans graag met je, zo vaak\n"
	.string "als je wilt!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Hahaha, jij wint!\n"
	.string "Je hebt me weer verslagen!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "JUAN: Als ik zou zeggen dat je mijn\n"
	.string "leerling moet worden, weiger je vast.\p"
	.string "Ik zou je mijn jas willen geven.\n"
	.string "Maar ook dat weiger je.\p"
	.string "En dat, mijn vriend, is een\n"
	.string "teken van adel!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN: Ah, deze GYM was weer rustig…\p"
	.string "Maar onze jonge storm is terug\n"
	.string "om ons weer te testen!\p"
	.string "Nou, mijn vriend, zeker!\n"
	.string "Ik dans graag met je…\p"
	.string "Ah, nee, nee, nee.\n"
	.string "Je hebt maar één POKéMON bij je.\p"
	.string "Kom terug met twee, of meer,\n"
	.string "POKéMON, alsjeblieft.$"

