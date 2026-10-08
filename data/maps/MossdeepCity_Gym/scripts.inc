MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applywaitmovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	turnrotatingtileobjects
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Yo, hoe gaat het, toekomstige\n"
	.string "KAMPIOEN {PLAYER}?\p"
	.string "De GYMLEIDERS hier gebruiken\n"
	.string "PSYCHISCH-POKéMON.\p"
	.string "Ga je tegen ze op met VECHT- of\n"
	.string "GIF-POKéMON, dan doe je veel schade!\p"
	.string "Maar zij vallen aan met\n"
	.string "sterke teamaanvallen.\p"
	.string "Wil je winnen? Laat dan zien hoe\n"
	.string "goed je band met je POKéMON is.\l"
	.string "Succes!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Wow, geweldig!\n"
	.string "Jij bent een top-TRAINER!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Een gevecht draait om je geest!\n"
	.string "Zwakke geesten winnen nooit!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "Ik verloor!\n"
	.string "Ik moet mijn geest weer trainen!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Wie twijfelt, verliest.\n"
	.string "Dat is mijn waarschuwing.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Laat me je talent zien!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Jij hebt prachtig talent!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Als er wonderkinderen bestaan,\n"
	.string "dan zijn onze GYMLEIDERS het!\p"
	.string "Maar jij hebt misschien nog meer\n"
	.string "talent dan zij…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu… Kijk hoe ik een POKé\n"
	.string "BALL laat zweven met mijn geest!\p"
	.string "Wrooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "Soms ben ik niet in de maat…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Mijn vechtkunst is ook niet\n"
	.string "in de maat!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "Een POKé BALL was te zwaar. Maar\n"
	.string "dit stofpluisje…\p"
	.string "Whoooooooooooooooh!\n"
	.string "… … … … … …\p"
	.string "Nee, ik speel niet vals!\n"
	.string "Ik heb er niet op geblazen! Echt!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Als je van mij verliest, wees\n"
	.string "dan niet te streng voor jezelf.\p"
	.string "Jij bent niet zwak, ik ben gewoon\n"
	.string "te sterk!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Je bent gewoon te sterk!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Ik baal niet van mijn verlies.\n"
	.string "Ik moet gewoon harder trainen.\p"
	.string "Positief denken, dat is mijn\n"
	.string "sterke punt!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Ik zie het…\n"
	.string "Ik zie je toekomst…\p"
	.string "Als je me verslaat, vertel ik je\n"
	.string "je toekomst!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Ik geef me over!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Je krijgt een ongelofelijk\n"
	.string "zwaar gevecht met onze GYMLEIDERS…\p"
	.string "De uitslag…\n"
	.string "Die vertel ik je niet!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "De wegen die je liep…\n"
	.string "Wat je allemaal meemaakte…\p"
	.string "Kom op me af met alles wat\n"
	.string "je geleerd hebt!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Je hebt een groots pad gelopen!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Wie hard werkt, krijgt een\n"
	.string "mooie toekomst.\p"
	.string "Wie lui was, heeft op het einde\n"
	.string "alleen wanhoop.\p"
	.string "Wat je zaait, zul je oogsten…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Zelfs als het mijn leven kost,\n"
	.string "ik win dit gevecht!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Wat jij doet…\n"
	.string "Het maakt me bang…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Hoe durf je me te verslaan…\p"
	.string "Het is niet mijn schuld als jou\n"
	.string "iets vreselijks overkomt…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hohoho.\p"
	.string "Ik laat je zien hoe taai het\n"
	.string "PSYCHISCH type kan zijn.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Oh! Jemig!\n"
	.string "Jouw vechtstijl is fantastisch!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "Ik… ik laat me niet uit het\n"
	.string "veld slaan, h-hoe erg ook.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Ik laat je een verschrikkelijk\n"
	.string "enge tijd beleven!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "N-neeeee!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Jouw energie is aanstekelijk!\n"
	.string "Weg bij me, snel!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Ik ben misschien niet jong meer,\n"
	.string "maar behandel me niet als oud.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Ah, jij zit vol jeugdige kracht!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Ik kon jouw jeugdige energie\n"
	.string "niet aan, zo te zien.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Je komt niet tot het einde!\n"
	.string "Niet als ik het kan voorkomen!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Hoe kun je zo belachelijk\n"
	.string "sterk zijn?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Hmpf! Je bent sterk, maar je past\n"
	.string "niet bij het PSYCHISCH type!\p"
	.string "Je vecht op een ruwe manier!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Wroooar! Proef mijn super\n"
	.string "POKéMON-vechtkracht!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Oh!\n"
	.string "Ik ben erbij!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Goed! Ik ga nu een speciale\n"
	.string "onverslaanbare POKéMON-kracht maken.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "TATE: Hehehe… Was je verrast?\p"
	.string "LIZA: Fufufu… Was je verrast?\p"
	.string "TATE: Dat er twee GYMLEIDERS zijn?\n"
	.string "LIZA: Dat er twee GYMLEIDERS zijn?\p"
	.string "TATE: Wij zijn een tweeling!\n"
	.string "LIZA: Wij zijn een tweeling!\p"
	.string "TATE: We hoeven niet te praten want…\n"
	.string "LIZA: We weten allebei wat…\p"
	.string "TATE: De ander denkt…\n"
	.string "LIZA: Alles in ons hoofd!\p"
	.string "TATE: Onze combinatie…\n"
	.string "LIZA: Kun jij die verslaan?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "TATE: Wat?! Onze combinatie…\n"
	.string "LIZA: Is verbroken!\p"
	.string "TATE: Dat kan niet anders. Je won…\n"
	.string "LIZA: Neem dit dan als beloning.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} krijgt de MIND BADGE\n"
	.string "van TATE en LIZA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "TATE: De MIND BADGE maakt de\n"
	.string "SP. AANV en SP. VERD van POKéMON\l"
	.string "hoger.\p"
	.string "LIZA: Met hem kun je ook de\n"
	.string "HM-aanval DUIKEN buiten een\l"
	.string "gevecht gebruiken.\p"
	.string "TATE: Neem dit ook mee.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "TATE: Die TM04 bevat…\n"
	.string "LIZA: KALME GEEST!\p"
	.string "TATE: Hij verhoogt SP. AANV en…\n"
	.string "LIZA: Hij verhoogt SP. VERD!\p"
	.string "TATE: Het is een perfecte aanval…\n"
	.string "LIZA: Voor PSYCHISCHE POKéMON!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "GYMLEIDERS TATE & LIZA staan nu\n"
	.string "in de POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "TATE: Jouw band met je POKéMON is\n"
	.string "sterker dan de band die wij als\l"
	.string "tweeling hebben.\p"
	.string "LIZA: Je wordt nog sterker!\n"
	.string "We hebben tegen je gevochten, dus\l"
	.string "we weten het.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "TATE: Hehehe… Was je verrast?\p"
	.string "LIZA: Dat er twee GYMLEIDERS zijn?\p"
	.string "TATE: Oeps, je hebt maar één…\n"
	.string "LIZA: POKéMON die kan vechten.\p"
	.string "TATE: Zo kunnen we niet vechten!\p"
	.string "LIZA: Wil je ons uitdagen, neem dan\n"
	.string "meer POKéMON mee.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "MOSSDEEP CITY POKéMON GYM$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "MOSSDEEP CITY POKéMON GYM\p"
	.string "TRAINERS GEKEURD DOOR LIZA EN TATE:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "TATE: POKéMON…\n"
	.string "LIZA: POKéMON…\p"
	.string "TATE: Als je het team verandert…\n"
	.string "LIZA: Verandert de vechtstijl.\p"
	.string "TATE: Maar ik…\n"
	.string "LIZA: Maar ik…\p"
	.string "TATE: Ik blijf altijd bij LIZA!\n"
	.string "LIZA: Ik blijf altijd bij TATE!\p"
	.string "TATE: Onze combinatie…\n"
	.string "LIZA: Die laten we je steeds zien!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "TATE: Jij en je POKéMON…\n"
	.string "LIZA: Net of jullie familie zijn!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "TATE: Je kunt ons omver gooien,\n"
	.string "maar we blijven niet liggen!\p"
	.string "LIZA: Want wij tweeën\n"
	.string "steunen elkaar altijd!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "TATE: Je bent terug…\n"
	.string "LIZA: Je bent terug…\p"
	.string "TATE: Voor een nieuw gevecht.\n"
	.string "LIZA: Voor een nieuw gevecht.\p"
	.string "TATE: Maar…\n"
	.string "LIZA: Voor ons gevecht…\p"
	.string "TATE: Je nam maar één POKéMON mee!\n"
	.string "LIZA: Je nam maar één POKéMON mee!\p"
	.string "TATE: Neem er minstens…\n"
	.string "LIZA: Twee POKéMON als je terugkomt.$"
