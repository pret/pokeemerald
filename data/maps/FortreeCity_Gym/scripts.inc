FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Yo, hoe gaat het, toekomstige\n"
	.string "KAMPIOEN {PLAYER}?\p"
	.string "FORTREE GYMLEIDER WINONA is een\n"
	.string "meester in VLIEG-POKéMON.\p"
	.string "Ze wacht achterin deze GYM,\n"
	.string "achter de draaideuren.\p"
	.string "Ze wacht op nieuwe uitdagers die\n"
	.string "willen opstijgen!\p"
	.string "Oké, zet 'm op!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Gelukt!\n"
	.string "Je bent opgestegen!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Zie de mooie vechtstijl van\n"
	.string "VOGEL-POKéMON!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Jij…\n"
	.string "Je bent sterk…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Een TRAINER moet slim zijn voor\n"
	.string "onverwachte dingen.\p"
	.string "Ben jij slim genoeg om bij onze\n"
	.string "LEIDER te komen?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Fans van VOGEL-POKéMON willen bij\n"
	.string "deze GYM horen.\p"
	.string "Als lid van de FORTREE GYM\n"
	.string "mag ik niet verliezen!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "Het was te zwaar voor me…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "De wereld is groot en er zijn\n"
	.string "zoveel sterke TRAINERS.\p"
	.string "Ik blijf trainen en word nog\n"
	.string "sterker.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "WINONA, onze GYMLEIDER, hoeft\n"
	.string "zich niet met jou te bemoeien!\p"
	.string "Ik ben meer dan goed genoeg!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "WINONA, ik…\n"
	.string "Ik verloor!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "WINONA is schattig en sterk.\n"
	.string "De beste LEIDER ooit!\p"
	.string "Bloos…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "WINONA leerde het mij zelf!\n"
	.string "Ik ben niet zomaar te verslaan!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "Ik werd verslagen…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Dankzij WINONA leven de mensen\n"
	.string "van FORTREE zonder angst.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Als WINONA vecht, straalt haar\n"
	.string "gezicht van moed…\p"
	.string "Dat mooie gezicht laat ik jou\n"
	.string "niet zien!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Au!\n"
	.string "Ik kon je niet stoppen.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Pas op!\n"
	.string "Kijk niet te lang naar WINONA,\l"
	.string "anders val je met een bons neer!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Je moet weten dat er allerlei\n"
	.string "VLIEG-POKéMON zijn.\p"
	.string "Dat weet je toch wel?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Jij weet er wel iets van!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Je versloeg me, ja.\n"
	.string "Maar pas op! De POKéMON van onze\l"
	.string "LEIDER WINONA zijn echt serieus.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Ik ben WINONA. Ik ben de LEIDER\n"
	.string "van de FORTREE POKéMON GYM.\p"
	.string "Ik ben één met VOGEL-POKéMON\n"
	.string "en ben door de lucht gezweefd…\p"
	.string "Hoe zwaar het gevecht ook was,\n"
	.string "we wonnen met stijl…\p"
	.string "Zie de mooie dans van de\n"
	.string "VOGEL-POKéMON en mij!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Nog nooit zag ik een TRAINER\n"
	.string "POKéMON met meer stijl leiden\l"
	.string "dan ik…\p"
	.string "Om je kracht te belonen, geef ik\n"
	.string "je deze GYM BADGE.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} kreeg de FEATHER BADGE\n"
	.string "van WINONA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Met de FEATHER BADGE luisteren alle\n"
	.string "POKéMON tot LV 70 naar je, ook\l"
	.string "geruilde POKéMON.\p"
	.string "Ook kun je de HM-aanval VLIEGEN\n"
	.string "buiten gevechten gebruiken.\p"
	.string "En dit…\n"
	.string "Dit is een cadeau van mij.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 bevat LUCHTSLAG.\p"
	.string "Zo snel…\n"
	.string "Geen POKéMON kan hem ontwijken.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "GYMLEIDER WINONA staat nu\n"
	.string "in de POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Al verloor ik van jou, ik blijf\n"
	.string "van VOGEL-POKéMON houden.$"

FortreeCity_Gym_Text_GymStatue:
	.string "FORTREE CITY POKéMON GYM$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "FORTREE CITY POKéMON GYM\p"
	.string "WINONA'S ERKENDE TRAINERS:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA: Wij mensen ontsnappen nooit\n"
	.string "aan de zwaartekracht.\p"
	.string "Maar door ons best te doen,\n"
	.string "kunnen we opstijgen!\p"
	.string "Jij bent de top bereikt als\n"
	.string "de zittende KAMPIOEN.\p"
	.string "Laat me je kracht in volle\n"
	.string "vlucht zien!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Ik haalde je hoogte weer niet…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA: Al verloor ik, de vleugels\n"
	.string "van mijn hart blijven heel.\p"
	.string "Ik kan weer opstijgen, steeds\n"
	.string "opnieuw.\p"
	.string "Daar ben ik zeker van!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA: Wij mensen ontsnappen nooit\n"
	.string "aan de zwaartekracht.\p"
	.string "Maar door ons best te doen,\n"
	.string "kunnen we opstijgen!\p"
	.string "Jij bent de top bereikt als\n"
	.string "de zittende KAMPIOEN.\p"
	.string "Laat me je kracht in volle\n"
	.string "vlucht zien!\p"
	.string "O nee… Heb je maar één\n"
	.string "POKéMON bij je?\p"
	.string "Kom terug met minstens twee\n"
	.string "POKéMON.$"
