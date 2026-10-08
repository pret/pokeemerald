MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applywaitmovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "Ik kreeg dit van STEVEN, maar ik\n"
	.string "weet niet waar het goed voor is.\p"
	.string "Ik denk dat het KING'S ROCK heet.\n"
	.string "Wil je het hebben?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Waarom zou je dat willen?\n"
	.string "Jij bent raar.\p"
	.string "Je mag het houden, maar hou het\n"
	.string "geheim voor STEVEN.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "STEVENs huis is daar vlakbij!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Ja, vind jij dat ook! Wat moet je\n"
	.string "nou met een rare steen?$"

MossdeepCity_Text_WailmerWatching:
	.string "Bij MOSSDEEP zie je wilde\n"
	.string "WAILMER.\p"
	.string "Hoe heet dat ook alweer…\n"
	.string "Wat was het nou…\p"
	.string "WAI, WAI, WAI…\p"
	.string "WAILMER kijken!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "Het SPACE CENTER op het eiland\n"
	.string "lanceert grote raketten.\p"
	.string "Er is ophef over een brief die\n"
	.string "ze laatst kregen.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "Het SPACE CENTER op het eiland\n"
	.string "lanceert grote raketten.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "Een MATROOS-vriend vertelde me dat\n"
	.string "TEAM AQUA in LILYCOVE zat.\p"
	.string "En iemand heeft ze verslagen!\p"
	.string "Maar TEAM MAGMA heeft het nu\n"
	.string "op MOSSDEEP gemunt.\p"
	.string "Wil je weten wat ze doen?\n"
	.string "Ga dan naar het SPACE CENTER.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Ik ben matroos, dus de zee is voor\n"
	.string "mij belangrijker.\p"
	.string "Maar na een lange reis ben ik\n"
	.string "blij als ik weer op land ben!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Zou het niet mooi zijn?\p"
	.string "Als de hele wereld vol planten en\n"
	.string "bloemen zat, zoals dit eiland?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Al het leven heeft de zee nodig,\n"
	.string "ook al woont het op het land.\p"
	.string "Als het leven voorbij is, wordt\n"
	.string "het aarde en keert terug naar land.\p"
	.string "En de zee hoort altijd bij\n"
	.string "het land.\p"
	.string "Ja, zoals de kust hier.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Een reis op een schip is fijn.\p"
	.string "Maar over zee gaan met POKéMON\n"
	.string "en SURF…\p"
	.string "Dat is pas spannend!\n"
	.string "Vind je ook niet, jochie?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Deze steen is speciaal voor de\n"
	.string "mensen van het SPACE CENTER.\p"
	.string "Ze zetten hem hier neer als wens\n"
	.string "dat hun raketten veilig vliegen.\p"
	.string "Wat gebruik jij als je een wens doet?\n"
	.string "Wens je op een ster?\p"
	.string "Ik gebruik een wenskaartje.\n"
	.string "Dat doe ik.$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "Het is een witte steen.$"

MossdeepCity_Text_GymSign:
	.string "MOSSDEEP CITY POKéMON GYM\n"
	.string "LEIDERS: LIZA & TATE\p"
	.string "“De mystieke combinatie!”$"

MossdeepCity_Text_CitySign:
	.string "MOSSDEEP CITY\n"
	.string "“Ons motto: Zorg goed voor POKéMON!”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "MOSSDEEP SPACE CENTER\n"
	.string "“Dichtst bij de ruimte.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, gaat het goed?\n"
	.string "Met mij wel!\p"
	.string "Ik hoorde dat de GYMLEIDER van\n"
	.string "MOSSDEEP sterk is. Ik kwam even\l"
	.string "kijken.\p"
	.string "Maar er is iets vreemds aan\n"
	.string "deze stad.\p"
	.string "Mensen praten over een waarschuwings-\n"
	.string "brief en het SPACE CENTER…\p"
	.string "Ik denk niet dat het mij\n"
	.string "wat aangaat.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… Wat heerlijk, de golven over\n"
	.string "mijn voeten…\p"
	.string "Over golven gesproken, ken je\n"
	.string "SOOTOPOLIS, die eilandstad?\p"
	.string "Daar is volgens mij een nieuwe\n"
	.string "LEIDER in de GYM.\p"
	.string "Mensen zeggen dat die LEIDER\n"
	.string "vroeger WALLACE trainde.$"

