.set LOCALID_HIDEOUT_GUARD, 5

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
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
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
	.string "Le SENTIER SINUROC du MONT CHIMNEE…\p"
	.string "J’ai toujours rêvé d’un endroit pareil…\p"
	.string "Ce relief accidenté…\n"
	.string "J’adore ça!$"

JaggedPass_Text_EricDefeat:
	.string "La défaite me laisse amer!$"

JaggedPass_Text_EricPostBattle:
	.string "Oui, je peux perdre avec les POKéMON…\p"
	.string "Mais s’il s’agissait de notre amour pour\n"
	.string "la montagne, je te battrais!$"

JaggedPass_Text_DianaIntro:
	.string "Tu n’te promènes pas ici par hasard.\n"
	.string "T’es pas là pour pique-niquer!$"

JaggedPass_Text_DianaDefeat:
	.string "Oooh, non!\n"
	.string "Ce sol est trop bosselé…$"

JaggedPass_Text_DianaPostBattle:
	.string "Tu savais ça?\p"
	.string "Les plus habiles utilisent leur VELO\n"
	.string "pour passer ce col très accidenté.$"

JaggedPass_Text_DianaRegister:
	.string "Tu reviendras un jour par ici?\n"
	.string "Si c’est le cas, j’aimerais bien\l"
	.string "refaire un match avec toi.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Un pique-nique, c’est toujours sympa.\n"
	.string "Exactement comme les POKéMON!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Si j’ai perdu, c’est juste à cause de ce\n"
	.string "sol trop bosselé!$"

JaggedPass_Text_DianaPostRematch:
	.string "Je vais oublier ma défaite et apprécier\n"
	.string "cette randonnée à travers les bosses.$"

JaggedPass_Text_EthanIntro:
	.string "C’est dur de marcher sur le SENTIER\n"
	.string "SINUROC.\p"
	.string "Mais c’est super pour s’entraîner!$"

JaggedPass_Text_EthanDefeat:
	.string "On essayait encore de trouver une\n"
	.string "bonne prise, alors que tout était\l"
	.string "déjà terminé.$"

JaggedPass_Text_EthanPostBattle:
	.string "Si j’avais un VELO CROSS, je pourrais\n"
	.string "sauter sur ces rebords rocheux.$"

JaggedPass_Text_EthanRegister:
	.string "J’arriverai à te battre quand je me\n"
	.string "serai habitué à ces bosses!\p"
	.string "Tu peux m’enregistrer dans ton\n"
	.string "POKéNAV?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Je suis habitué à toutes ces bosses.\n"
	.string "Maintenant, je chante en grimpant.$"

JaggedPass_Text_EthanRematchDefeat:
	.string "C’est quand même pas facile de se\n"
	.string "battre sur ce sol tout bosselé…$"

JaggedPass_Text_EthanPostRematch:
	.string "Il faudrait que j’aille à LAVANDIA pour\n"
	.string "que RODOLPHE me donne un VELO CROSS.$"

JaggedPass_Text_GruntIntro:
	.string "Quoi?\n"
	.string "Qu’est-ce que tu fais là?\p"
	.string "Qu’est-ce que je fais dans un endroit\n"
	.string "pareil?\p"
	.string "Ça te regarde?$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh…\p"
	.string "J’aurais dû rester caché dans la\n"
	.string "PLANQUE…$"

JaggedPass_Text_GoWhereverYouWant:
	.string "OK, OK…\n"
	.string "Je dois l’avouer, tu sais te battre!\p"
	.string "Ne t’inquiète pas pour moi. Tu peux\n"
	.string "aller où tu veux!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "Oh! Ce rocher semble réagir à la\n"
	.string "présence du SCEAU MAGMA!$"

JaggedPass_Text_JulioIntro:
	.string "Ça fait super peur de descendre la\n"
	.string "montagne d’un coup!$"

JaggedPass_Text_JulioDefeat:
	.string "J’ai l’impression de tomber en morceaux…$"

JaggedPass_Text_JulioPostBattle:
	.string "Mon vélo s’est pris tellement de bosses\n"
	.string "que je ne sens plus mon dos.$"

JaggedPass_Text_AutumnIntro:
	.string "Je gravis cette colline chaque jour.\n"
	.string "J’ai confiance en ma force!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hum…\n"
	.string "Qu’est-ce qui s’est passé?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Est-ce que tu sais ce qu’est cette\n"
	.string "étrange avancée rocheuse un peu\l"
	.string "plus loin?$"

