JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "MT. CHIMNEY's JAGGED PASS…\p"
	.string "Dit is precies wat ik wil van\n"
	.string "een berg.\p"
	.string "Al die hobbelige paden…\n"
	.string "Ik word er blij van!$"

JaggedPass_Text_EricDefeat:
	.string "Verliezen maakt me chagrijnig!$"

JaggedPass_Text_EricPostBattle:
	.string "Ja, ik verloor van je…\p"
	.string "Maar ik hou meer van de bergen\n"
	.string "dan jij!$"

JaggedPass_Text_DianaIntro:
	.string "Dit is geen gewone wandeling.\n"
	.string "Een picknick past hier niet.$"

JaggedPass_Text_DianaDefeat:
	.string "Ohhh, nee!\n"
	.string "De grond is te hobbelig…$"

JaggedPass_Text_DianaPostBattle:
	.string "Wist je dat?\p"
	.string "Sommigen fietsen slim over dit\n"
	.string "verschrikkelijk hobbelige pad.$"

JaggedPass_Text_DianaRegister:
	.string "Kom je nog eens terug?\n"
	.string "Dan wil ik een revanche.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Een picknick is overal leuk.\n"
	.string "Net als POKéMON!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Ik verloor alleen door de\n"
	.string "hobbelige grond!$"

JaggedPass_Text_DianaPostRematch:
	.string "Ik vergeet het verlies en geniet\n"
	.string "van deze hobbelige wandeling.$"

JaggedPass_Text_EthanIntro:
	.string "JAGGED PASS is lastig om te lopen.\n"
	.string "Maar het is een goede trainingsplek.$"

JaggedPass_Text_EthanDefeat:
	.string "Het was al voorbij voordat we\n"
	.string "stevig stonden…$"

JaggedPass_Text_EthanPostBattle:
	.string "Met een STUNTFIETS kon ik over\n"
	.string "de randen springen.$"

JaggedPass_Text_EthanRegister:
	.string "Als ik aan het hobbelen gewend ben,\n"
	.string "win ik zeker!\p"
	.string "Zet je me in je POKéNAV?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Ik ben aan het hobbelen gewend.\n"
	.string "Nu zing ik tijdens het klimmen.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Vechten op deze hobbelige grond\n"
	.string "is nog steeds lastig…$"

JaggedPass_Text_EthanPostRematch:
	.string "Ik haal een STUNTFIETS bij RYDEL\n"
	.string "in MAUVILLE CITY…$"

JaggedPass_Text_GruntIntro:
	.string "Wah!\n"
	.string "Wat doe jij hier?\p"
	.string "Wat ik hier doe?\n"
	.string "Dat zijn jouw zaken niet!$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh…\p"
	.string "Ik had meteen onze SCHUILPLAATS\n"
	.string "in moeten duiken…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Oké, oké!\n"
	.string "Je bent sterk, dat geef ik toe!\p"
	.string "Maak je geen zorgen om mij.\n"
	.string "Ga maar waar je heen wilt!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! Deze rots trilt door\n"
	.string "het MAGMAEMBLEEM!$"

JaggedPass_Text_JulioIntro:
	.string "Aiyeeh! Het is doodeng om in één\n"
	.string "keer van de berg af te razen!$"

JaggedPass_Text_JulioDefeat:
	.string "Ik val bijna uit elkaar…$"

JaggedPass_Text_JulioPostBattle:
	.string "Mijn fiets stuiterde zo erg,\n"
	.string "mijn billen doen pijn…$"

JaggedPass_Text_AutumnIntro:
	.string "Ik klim elke dag deze heuvel op.\n"
	.string "Ik vertrouw op mijn kracht!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm…\n"
	.string "Wat ging er mis?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Wat is dat rare stuk rots\n"
	.string "een eindje hogerop?$"

