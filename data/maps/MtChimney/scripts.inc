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
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
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
	applywaitmovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	playse SE_PIN
	applywaitmovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	return

MtChimney_EventScript_ArchieExitEast::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	return

MtChimney_EventScript_ArchieExitNorth::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
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
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
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
	.string "De kracht van de METEORIET…\p"
	.string "Als deze machine die kracht\n"
	.string "versterkt, wordt de vulkaan van\l"
	.string "MT. CHIMNEY meteen veel actiever…\p"
	.string "De energie groeit diep in de krater\n"
	.string "en…\l"
	.string "Hihihi…$"

MtChimney_Text_MaxieIntro:
	.string "MAXIE: Hm?\n"
	.string "Wie ben jij?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "ARCHIE klaagde over een kind\n"
	.string "dat zich met TEAM AQUA bemoeit.\p"
	.string "Jij bent vast dat kind.\p"
	.string "Hm! Wil je ons dwarszitten,\n"
	.string "TEAM MAGMA?\p"
	.string "Luister goed.\n"
	.string "Lang geleden gebruikten levende\l"
	.string "wezens het land om te leven.\p"
	.string "Daarom is land zo belangrijk!\n"
	.string "Het is de wieg van alles!\p"
	.string "Daarom wil TEAM MAGMA het land\n"
	.string "groter maken.\p"
	.string "Voor de toekomst van mensen\n"
	.string "en POKéMON!\p"
	.string "En daarvoor hebben we de kracht\n"
	.string "nodig die in deze berg slaapt…\p"
	.string "Oh! Dat hoefde je niet te weten.\p"
	.string "Maar goed!\n"
	.string "Ik leer je wat er gebeurt als je\l"
	.string "ons grote plan verstoort!$"

MtChimney_Text_MaxieDefeat:
	.string "Wat?!\p"
	.string "Ik, MAXIE, werd verrast?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAXIE: Maar genoeg.\n"
	.string "Deze keer trek ik me terug.\p"
	.string "Maar denk niet dat dit het einde\n"
	.string "is van TEAM MAGMA.\p"
	.string "Hihihi…\p"
	.string "Zelfs zonder de METEORIET, als\n"
	.string "we die ORB pakken… Hihihi…$"

MtChimney_Text_TabithaIntro:
	.string "Hehehe!\p"
	.string "Dus je bent helemaal hier\n"
	.string "gekomen!\p"
	.string "Maar je bent te laat!\n"
	.string "Ik gaf de METEORIET uit\l"
	.string "METEOR FALLS al aan de BAAS!$"

MtChimney_Text_TabithaDefeat:
	.string "Hehehe…\p"
	.string "Ik verloor, maar als onze leider\n"
	.string "het ding wakker maakt…$"

MtChimney_Text_TabithaPostBattle:
	.string "BAAS, snel!\n"
	.string "Geef hem de energie van\l"
	.string "de METEORIET!\p"
	.string "Hehehe…$"

MtChimney_Text_Grunt2Intro:
	.string "Wij van TEAM MAGMA werken hard\n"
	.string "voor iedereen.\p"
	.string "Als dat ding meer land maakt,\n"
	.string "zijn er meer plekken om te wonen.\p"
	.string "Iedereen is blij!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hè?\n"
	.string "Wat bedoel je, ik verloor?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Onze BAAS zegt: “Het maakt\n"
	.string "iedereen blij.”\p"
	.string "Maar waarom zit iedereen\n"
	.string "ons steeds dwars?$"

MtChimney_Text_Grunt1Intro:
	.string "Met meer land kon ik een groot\n"
	.string "huis voor mezelf krijgen!\p"
	.string "Ik bouw het op harde lava!$"

MtChimney_Text_Grunt1Defeat:
	.string "Mijn droom van een groot huis…$"

MtChimney_Text_Grunt1PostBattle:
	.string "Een kind zoals jij kan beter\n"
	.string "in de golven spetteren!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Dat vervelende TEAM AQUA…\n"
	.string "Ze verpesten altijd onze plannen!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "METEORIETEN zijn ongelooflijk sterk!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Je moet ons niet dwarszitten!\p"
	.string "We maken dat ding wakker voor\n"
	.string "het goede van iedereen!$"

MtChimney_Text_AquasNameSimilar:
	.string "Wij zijn TEAM MAGMA!\p"
	.string "Zij zijn TEAM AQUA!\p"
	.string "Ik word gek dat ze een naam\n"
	.string "als de onze gebruiken!$"

MtChimney_Text_DouseThemInFire:
	.string "Ja!\n"
	.string "Gooi ze in het vuur!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "We blijven meer land maken!$"

MtChimney_Text_Bufoh:
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARCHIE: Grr, {PLAYER}!\n"
	.string "Ik wist dat je zou komen!\p"
	.string "Kijk zelf wat de fanatiekelingen\n"
	.string "van TEAM MAGMA doen!\p"
	.string "Ze stoppen de kracht van de gestolen\n"
	.string "METEORIET in de vulkaan!\p"
	.string "Daardoor barst de vulkaan uit!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIE: Grrr…\p"
	.string "Ik wil MAXIE stoppen,\n"
	.string "maar ik kan niet!\p"
	.string "Ik vecht al tegen drie\n"
	.string "tegenstanders tegelijk!$"

MtChimney_Text_ArchieThankYou:
	.string "ARCHIE: {PLAYER}!\n"
	.string "Bedankt!\p"
	.string "Met jouw hulp stopten we het\n"
	.string "verschrikkelijke plan van TEAM MAGMA!\p"
	.string "Maar… Jij…\n"
	.string "Aan wiens kant sta jij?\p"
	.string "Ach, laat maar.\p"
	.string "We blijven TEAM MAGMA op de\n"
	.string "voet volgen.\p"
	.string "{PLAYER}, we zien elkaar vast weer!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Verdraaid… TEAM MAGMA is met meer!\n"
	.string "We houden ze niet bij!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Als ze het land groter maken,\n"
	.string "hebben WATER-POKéMON minder ruimte!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Wij zijn TEAM AQUA!\p"
	.string "Zij zijn TEAM MAGMA!\p"
	.string "Ik word boos dat ze zo'n\n"
	.string "verwarrende naam gebruiken!$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "LAVAKOEKJES zijn de lekkernij\n"
	.string "van MT. CHIMNEY.\p"
	.string "Probeer er een. Maar ¥200.$"

MtChimney_Text_ThankYouDear:
	.string "Dank je wel, schatje!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Oh jee. Je kunt niets kopen\n"
	.string "zonder geld.$"

MtChimney_Text_OhFineThen:
	.string "Oh, nou, goed dan.$"

MtChimney_Text_MeteoriteFittedOnMachine:
	.string "Er zit een METEORIET op een\n"
	.string "raar apparaat…\p"
	.string "Het apparaat slaat energie\n"
	.string "op in de METEORIET.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Er zit een METEORIET op een\n"
	.string "raar apparaat…\p"
	.string "Wil je de METEORIET weghalen?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} haalde de METEORIET\n"
	.string "van het rare apparaat.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} liet de METEORIET\n"
	.string "zitten waar hij zat.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Dit rare apparaat…\n"
	.string "Het reageert nergens op.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} JAGGED PATH\n"
	.string "LAVARIDGE TOWN VOORUIT$"

MtChimney_Text_ShelbyIntro:
	.string "Ik was in de warme bronnen en\n"
	.string "mijn oude botten zijn fris.\l"
	.string "Nu voel ik me sterk!$"

MtChimney_Text_ShelbyDefeat:
	.string "Och, goeie genade.\n"
	.string "Jij bent me er een!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Tja, ik verloor. Nu kan ik\n"
	.string "me geen EXPERT meer noemen, hè?$"

MtChimney_Text_ShelbyRegister:
	.string "Dank je, kind. Het was leuk, alsof\n"
	.string "ik vocht met mijn kleinkind.\p"
	.string "Kom me nog eens opzoeken\n"
	.string "voor een revanche.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Als je hart een is met dat van\n"
	.string "je POKéMON, kun je grote dingen\l"
	.string "bereiken.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Och, goeie genade.\n"
	.string "Jij bent me er een!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Misschien is je hart een geworden\n"
	.string "met de harten van je POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "Ik heb vuur in me, schat.\n"
	.string "Ik kan het niet laten! Ik moet vechten!$"

MtChimney_Text_MelissaDefeat:
	.string "Ooh, wat een bloedhete wedstrijd!$"

MtChimney_Text_MelissaPostBattle:
	.string "De hitte van MT. CHIMNEY\n"
	.string "warmt me op, schat!$"

MtChimney_Text_SheilaIntro:
	.string "Eindelijk ben ik op MT. CHIMNEY.\n"
	.string "Ik wil mijn POKéMON laten vechten!$"

MtChimney_Text_SheilaDefeat:
	.string "Hoe je vecht…\n"
	.string "Het is als een uitbarsting van\l"
	.string "MT. CHIMNEY!$"

MtChimney_Text_SheilaPostBattle:
	.string "Zoals ik zei, ik ben eindelijk op\n"
	.string "MT. CHIMNEY. Alleen maar rondkijken\l"
	.string "zou zonde zijn…\p"
	.string "Ik wil nog vechten en KOEKJES\n"
	.string "kopen als souvenir.$"

MtChimney_Text_ShirleyIntro:
	.string "Sinds ik in de warme bron zat,\n"
	.string "voel ik me geweldig!\l"
	.string "Ik ga zeker winnen!$"

MtChimney_Text_ShirleyDefeat:
	.string "Auw!\n"
	.string "Ik krijg het koud van het water.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Ik ga nog eens in de warme bron.\n"
	.string "Ga je mee?\p"
	.string "Grapje!$"

MtChimney_Text_SawyerIntro:
	.string "Wat een mooie berg! Veel hete\n"
	.string "mensen om me heen!$"

MtChimney_Text_SawyerDefeat:
	.string "Oh, jij bent ook een vuurkop!$"

MtChimney_Text_SawyerPostBattle:
	.string "Ik moet nodig in de LAVARIDGE\n"
	.string "WARME BRON met de locals!$"

MtChimney_Text_SawyerRegister:
	.string "Ik mag kleine vuurballen zoals jij.\n"
	.string "Ik zet je in mijn POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Ik ben blij met al die hete mensen\n"
	.string "hier. Ik ga niet verliezen!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Wauw, je bent nog steeds\n"
	.string "zo'n vuurkop als eerst!$"

MtChimney_Text_SawyerPostRematch:
	.string "Het is hier echt heet.\n"
	.string "Ik heb te veel kleren aan.$"

