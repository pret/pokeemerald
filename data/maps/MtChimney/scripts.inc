.set LOCALID_ARCHIE, 1
.set LOCALID_MAXIE, 2
.set LOCALID_TABITHA, 3
.set LOCALID_MAGMA_GRUNT_2, 22
.set LOCALID_MAGMA_GRUNT_1, 29


MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "La puissance contenue dans le\n"
	.string "METEORITE…\p"
	.string "En l’amplifiant avec cette machine,\n"
	.string "l’activité volcanique du MONT CHIMNEE\l"
	.string "va s’intensifier instantanément…\p"
	.string "Son énergie va grandir à l’intérieur\n"
	.string "de ce cratère et…\l"
	.string "Hahaha…$"

MtChimney_Text_MaxieIntro:
	.string "MAX: Hum…\n"
	.string "Qui es-tu?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "J’ai entendu ARTHUR se plaindre d’un\n"
	.string "DRESSEUR qui se serait mêlé des\l"
	.string "affaires de la TEAM AQUA.\p"
	.string "Il devait parler de toi, je pense.\p"
	.string "Humpf! Alors tu veux également te\n"
	.string "mêler des affaires de la TEAM MAGMA?\p"
	.string "Ecoute-moi bien! Les êtres vivants ont\n"
	.string "besoin de la terre pour se développer.\p"
	.string "La terre représente tout! C’est le\n"
	.string "berceau de toute vie!\p"
	.string "C’est pour cela que la TEAM MAGMA\n"
	.string "s’est engagée à étendre la terre.\p"
	.string "Notre but est de faire prospérer les\n"
	.string "êtres humains et les POKéMON!\p"
	.string "Et pour cela, nous avons besoin de\n"
	.string "la puissance qui sommeille dans\l"
	.string "cette montagne…\p"
	.string "Oh, tu n’avais pas vraiment besoin de\n"
	.string "savoir tout ça…\p"
	.string "Mais peu importe!\n"
	.string "Je vais te montrer ce qu’il en coûte\l"
	.string "de se mêler de nos affaires!$"

MtChimney_Text_MaxieDefeat:
	.string "Quoi?!\p"
	.string "Moi, MAX, j’ai été pris au dépourvu?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAX: Ça suffit. Je pars pour cette\n"
	.string "fois.\p"
	.string "Mais n’espère pas ne plus entendre\n"
	.string "parler de la TEAM MAGMA.\p"
	.string "Hahaha…\p"
	.string "Même sans le METEORITE, si nous\n"
	.string "parvenons à obtenir l’ORBE…\l"
	.string "Alors là!$"

MtChimney_Text_TabithaIntro:
	.string "Hé, hé, hé!\p"
	.string "Alors t’as fait tout le chemin jusqu’ici!\p"
	.string "Mais il est trop tard!\n"
	.string "J’ai déjà remis le METEORITE du\l"
	.string "SITE METEORE au CHEF!$"

MtChimney_Text_TabithaDefeat:
	.string "Héhéhé…\p"
	.string "Même si j’ai perdu, si notre chef arrive\n"
	.string "à réveiller cette chose…$"

MtChimney_Text_TabithaPostBattle:
	.string "CHEF, vite!\n"
	.string "Donne-lui l’énergie du METEORITE!\p"
	.string "Héhéhé…$"

MtChimney_Text_Grunt2Intro:
	.string "Nous, la TEAM MAGMA, nous travaillons\n"
	.string "dur dans l’intérêt de tous.\p"
	.string "Si la puissance de cette chose\n"
	.string "étendait la terre, il y aurait plus\l"
	.string "d’espace pour vivre.\p"
	.string "Tout le monde serait heureux!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hum?\n"
	.string "Tu veux dire que j’ai perdu?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Notre CHEF dit que ça rendra tout\n"
	.string "le monde heureux.\p"
	.string "Mais pourquoi tout le monde se met en\n"
	.string "travers de notre route?$"

MtChimney_Text_Grunt1Intro:
	.string "S’il y avait plus de terre, je pourrais\n"
	.string "avoir ma propre maison!\p"
	.string "Je vais en construire une sur de\n"
	.string "la lave froide!$"

MtChimney_Text_Grunt1Defeat:
	.string "Mon rêve de grande maison…$"

MtChimney_Text_Grunt1PostBattle:
	.string "A ton âge, tu devrais être en\n"
	.string "train de jouer dans le sable!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Cette TEAM AQUA est agaçante…\n"
	.string "Ils font toujours échouer nos plans!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "Les METEORITES contiennent une\n"
	.string "puissance stupéfiante!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Tu ferais bien de pas te mêler de ça!\p"
	.string "Nous essayons de réveiller cette chose\n"
	.string "pour le bien de tous!$"

MtChimney_Text_AquasNameSimilar:
	.string "Nous sommes la TEAM MAGMA!\p"
	.string "Ils sont la TEAM AQUA!\p"
	.string "Ça m’énerve vraiment qu’ils utilisent\n"
	.string "un nom comme le nôtre!$"

MtChimney_Text_DouseThemInFire:
	.string "Yé!\n"
	.string "Fais-en du feu!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "On va continuer à créer plus de terre!$"

MtChimney_Text_Bufoh:
	.string "Youhou!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARTHUR: Grr, {PLAYER}!\p"
	.string "J’aurais dû me douter que tu pointerais\n"
	.string "le bout de ton nez!\p"
	.string "Vois par toi-même de quoi sont\n"
	.string "capables les fanatiques de la\l"
	.string "TEAM MAGMA!\p"
	.string "Ils essaient d’injecter la puissance\n"
	.string "du METEORITE volé à l’intérieur\l"
	.string "du volcan!\p"
	.string "A cause d’eux, le volcan risque\n"
	.string "d’entrer en éruption!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARTHUR: Arrrgh!\p"
	.string "Je veux arrêter ce MAX,\n"
	.string "mais je ne peux pas!\p"
	.string "Je suis trop occupé à me battre\n"
	.string "contre trois adversaires à la fois.$"

MtChimney_Text_ArchieThankYou:
	.string "ARTHUR: {PLAYER}!\n"
	.string "Merci!\p"
	.string "Grâce à ton aide, nous avons déjoué\n"
	.string "les plans de la TEAM MAGMA!\p"
	.string "Mais… Toi…\n"
	.string "De quel côté es-tu?\p"
	.string "Ah, peu importe…\p"
	.string "Nous resterons vigilants et\n"
	.string "continuerons de poursuivre la\l"
	.string "TEAM MAGMA.\p"
	.string "{PLAYER}, nous nous reverrons!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "La TEAM MAGMA est venue en force!\n"
	.string "Arrêtons! On ne fera pas le poids!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "S’ils étendent la terre, il y aura moins\n"
	.string "d’espace pour les POKéMON EAU!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Nous sommes la TEAM AQUA!\p"
	.string "Ils sont la TEAM MAGMA!\p"
	.string "Ça me fait mal au cœur qu’ils utilisent\n"
	.string "un nom qui ressemble au nôtre!$"

MtChimney_Text_Bushaa:
	.string "Bouhaha!$"

MtChimney_Text_LavaCookiesJust200:
	.string "Les LAVA COOKIES sont les spécialités\n"
	.string "locales du MONT CHIMNEE.\p"
	.string "Goûtes-en un. Ça ne coûte que 200¥.$"

MtChimney_Text_ThankYouDear:
	.string "Merci, mon p’tit!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Oh, tu ne peux pas acheter ce que tu\n"
	.string "veux, si tu n’as pas assez d’argent.$"

MtChimney_Text_OhFineThen:
	.string "Bon, très bien.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "Un METEORITE est placé sur une\n"
	.string "mystérieuse machine…\p"
	.string "Cette machine semble stocker de\n"
	.string "l’énergie dans le METEORITE.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Un METEORITE est placé sur une\n"
	.string "mystérieuse machine…\p"
	.string "Voulez-vous retirer le METEORITE?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} retire le METEORITE de la\n"
	.string "mystérieuse machine.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} laisse le METEORITE à sa\n"
	.string "place.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Cette mystérieuse machine…\n"
	.string "Elle ne répond pas.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} SENTIER SINUROC\n"
	.string "VERMILAVA DROIT DEVANT$"

MtChimney_Text_ShelbyIntro:
	.string "Je suis allée aux sources chaudes pour\n"
	.string "revigorer mes os fatigués.\l"
	.string "Maintenant, je me sens forte!$"

MtChimney_Text_ShelbyDefeat:
	.string "Oh, ça alors!\n"
	.string "Quel DRESSEUR tu fais!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Eh bien, j’ai perdu. Je ne peux plus me\n"
	.string "considérer comme étant EXPERT, hein?$"

MtChimney_Text_ShelbyRegister:
	.string "Merci, mon p’tit! C’était amusant.\n"
	.string "Comme si je m’étais battue contre\l"
	.string "mes petits-enfants.\p"
	.string "Reviens me voir quand tu veux\n"
	.string "pour une revanche.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Si tu réussis à toucher le cœur\n"
	.string "de tes POKéMON, tu devrais pouvoir\l"
	.string "accomplir de grandes choses.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Oh, ça alors!\n"
	.string "Quel DRESSEUR tu fais!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Peut-être ton cœur ne fait-il plus\n"
	.string "qu’un avec celui de tes POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "J’ai le feu en moi, bébé.\n"
	.string "J’en peux plus! Il faut que j’me batte!$"

MtChimney_Text_MelissaDefeat:
	.string "Oh, oh! C’était un combat torride!$"

MtChimney_Text_MelissaPostBattle:
	.string "La chaleur du MONT CHIMNEE avive\n"
	.string "le feu qui brûle en moi, bébé!$"

MtChimney_Text_SheilaIntro:
	.string "Je suis enfin parvenue au MONT CHIMNEE.\n"
	.string "Je veux que mon POKéMON combatte!$"

MtChimney_Text_SheilaDefeat:
	.string "La façon dont tu te bats… C’est comme\n"
	.string "une éruption du MONT CHIMNEE!$"

MtChimney_Text_SheilaPostBattle:
	.string "Comme je l’ai dit, je suis enfin parvenue\n"
	.string "au MONT CHIMNEE. Ce serait dommage\l"
	.string "que ce ne soit qu’en touriste…\p"
	.string "Je veux gagner quelques combats et\n"
	.string "ramener des COOKIES en souvenir.$"

MtChimney_Text_ShirleyIntro:
	.string "Depuis ma baignade dans les sources\n"
	.string "chaudes, je suis en super forme!\p"
	.string "Je suis sûre que je vais gagner!$"

MtChimney_Text_ShirleyDefeat:
	.string "Atchoum!\n"
	.string "Je prends froid hors de l’eau.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Je vais devoir prendre un autre bain\n"
	.string "dans les sources chaudes. Tu viens?\p"
	.string "Je plaisante!$"

MtChimney_Text_SawyerIntro:
	.string "C’est une belle montagne! Pleine de\n"
	.string "gens pour te tenir compagnie!$"

MtChimney_Text_SawyerDefeat:
	.string "Oh, tu as le feu, toi!$"

MtChimney_Text_SawyerPostBattle:
	.string "Je ferais mieux d’aller me baigner\n"
	.string "avec les gens du coin!$"

MtChimney_Text_SawyerRegister:
	.string "J’aime les petites boules de feu\n"
	.string "comme toi.\p"
	.string "Laisse-moi t’enregistrer dans mon\n"
	.string "POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Je suis entouré de gens chauds comme\n"
	.string "la braise, je ne peux pas perdre!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Tu as autant le feu qu’avant!$"

MtChimney_Text_SawyerPostRematch:
	.string "En fait, il fait un peu trop chaud ici.\n"
	.string "Je dois être un peu trop habillé.$"

