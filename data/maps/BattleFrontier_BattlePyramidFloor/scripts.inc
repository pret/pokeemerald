BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_E, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_E, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_0
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "C’est le message d’essai.$"

gText_BattlePyramidConfirmRest::
	.string "Votre quête à la PYRAMIDE DE COMBAT\n"
	.string "sera sauvegardée pour que vous\l"
	.string "puissiez faire une pause. OK?$"

gText_BattlePyramidConfirmRetire::
	.string "Voulez-vous vraiment abandonner votre\n"
	.string "quête à la PYRAMIDE?$"

BattlePyramid_Text_ExitHintUp1::
	.string "Pour sortir de ce niveau, il faut aller\n"
	.string "dans cette direction: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft1::
	.string "Pour sortir de ce niveau, il faut aller\n"
	.string "dans cette direction: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight1::
	.string "Pour sortir de ce niveau, il faut aller\n"
	.string "dans cette direction: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown1::
	.string "Pour sortir de ce niveau, il faut aller\n"
	.string "dans cette direction: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp2::
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "La sortie de ce niveau se trouve\n"
	.string "dans cette direction: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "Va dans la direction {UP_ARROW}\n"
	.string "pour sortir.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "Va dans la direction {LEFT_ARROW}\n"
	.string "pour sortir.$"

BattlePyramid_Text_ExitHintRight3::
	.string "Va dans la direction {RIGHT_ARROW}\n"
	.string "pour sortir.$"

BattlePyramid_Text_ExitHintDown3::
	.string "Va dans la direction {DOWN_ARROW}\n"
	.string "pour sortir.$"

BattlePyramid_Text_ExitHintUp4::
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "A ce niveau, la sortie se trouve\n"
	.string "par là: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "La sortie?\n"
	.string "C’est par là, mon petit: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "La sortie?\n"
	.string "C’est par là, mon petit: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5::
	.string "La sortie?\n"
	.string "C’est par là, mon petit: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5::
	.string "La sortie?\n"
	.string "C’est par là, mon petit: {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6::
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "Pour sortir de ce niveau, va dans\n"
	.string "cette direction: {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Tu cherches des objets?\p"
	.string "Il reste huit objets à trouver.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Tu cherches des objets?\p"
	.string "Il reste sept objets à trouver.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Tu cherches des objets?\p"
	.string "Il reste six objets à trouver.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Tu cherches des objets?\p"
	.string "Il reste cinq objets à trouver.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Tu cherches des objets?\p"
	.string "Il reste quatre objets à trouver.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Tu cherches des objets?\p"
	.string "Il reste trois objets à trouver.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Tu cherches des objets?\p"
	.string "Il reste deux objets à trouver.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Tu cherches des objets?\p"
	.string "Il reste un objet à trouver.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Tu cherches des objets?\p"
	.string "Il n’y a plus d’objets à trouver!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a huit objets à trouver.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a sept objets à trouver.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a six objets à trouver.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a cinq objets à trouver.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a quatre objets à trouver.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a trois objets à trouver.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a deux objets à trouver.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il y a un objet à trouver.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Tu as gagné, alors je vais te confier\n"
	.string "un petit secret!\p"
	.string "Il n’y a plus d’objets à trouver.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Comment se porte ton stock d’objets?\p"
	.string "Je dirais qu’il reste huit objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Comment se porte ton stock d’objets?\p"
	.string "Je dirais qu’il reste sept objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Comment se porte ton stock d’objets?\p"
	.string "Je dirais qu’il reste six objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Comment se porte ton stock d’objets?\p"
	.string "Je dirais qu’il reste cinq objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Comment se porte ton stock d’objets?\p"
	.string "Je dirais qu’il reste quatre objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Comment se porte ton stock d’objets?\p"
	.string "Je dirais qu’il reste trois objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Comment se porte ton stock d’objets?\p"
	.string "Je dirais qu’il reste deux objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Comment se porte ton stock d’objets?\p"
	.string "Je dirais qu’il reste un objet à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Comment se porte ton stock d’objets?\p"
	.string "Je dirais qu’il ne reste plus d’objets à\n"
	.string "ramasser par terre.$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu’il reste huit objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu’il reste sept objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu’il reste six objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu’il reste cinq objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu’il reste quatre objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu’il reste trois objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu’il reste deux objets\n"
	.string "à ramasser.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu’il reste un objet\n"
	.string "à ramasser.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Tu es balèze, tu as bien mérité\n"
	.string "une information!\p"
	.string "Il semble qu’il ne reste aucun objet\n"
	.string "à ramasser.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a huit objets à trouver…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a sept objets à trouver…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a six objets à trouver…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a cinq objets à trouver…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a quatre objets à trouver…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a trois objets à trouver…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a deux objets à trouver…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il y a un objet à trouver…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "A ce niveau de la PYRAMIDE,\n"
	.string "il n’y a pas d’objets à trouver…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu’il en reste huit à ce\n"
	.string "niveau.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu’il en reste sept à ce\n"
	.string "niveau.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu’il en reste six à ce\n"
	.string "niveau.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu’il en reste cinq à ce\n"
	.string "niveau.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu’il en reste quatre à ce\n"
	.string "niveau.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu’il en reste trois à ce\n"
	.string "niveau.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu’il en reste deux à ce\n"
	.string "niveau.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu’il en reste un à ce\n"
	.string "niveau.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Est-ce que tu as trouvé des objets?\p"
	.string "Je pense qu’il n’en reste plus à ce\n"
	.string "niveau.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore sept DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore six DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore cinq DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore quatre DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore trois DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore deux DRESSEURS\n"
	.string "à battre!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Tu as été formidable!\p"
	.string "Mais il y a encore un DRESSEUR\n"
	.string "à battre!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Tu as été formidable!\p"
	.string "Il n’y a plus de DRESSEUR\n"
	.string "à battre!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "C’est rageant!\p"
	.string "Mais il y a sept autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "C’est rageant!\p"
	.string "Mais il y a six autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "C’est rageant!\p"
	.string "Mais il y a cinq autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "C’est rageant!\p"
	.string "Mais il y a quatre autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "C’est rageant!\p"
	.string "Mais il y a trois autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "C’est rageant!\p"
	.string "Mais il y a deux autres DRESSEURS!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "C’est rageant!\p"
	.string "Mais il y a un autre DRESSEUR!\n"
	.string "Tu ne résisteras pas!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "C’est rageant!\p"
	.string "Il ne reste plus de DRESSEUR!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "C’est impressionnant!\p"
	.string "Il reste sept DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "C’est impressionnant!\p"
	.string "Il reste six DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "C’est impressionnant!\p"
	.string "Il reste cinq DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "C’est impressionnant!\p"
	.string "Il reste quatre DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "C’est impressionnant!\p"
	.string "Il reste trois DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "C’est impressionnant!\p"
	.string "Il reste deux DRESSEURS à ce niveau.\n"
	.string "Arriveras-tu à tous les battre?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "C’est impressionnant!\p"
	.string "Il reste un DRESSEUR à ce niveau.\n"
	.string "Arriveras-tu à le battre?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "C’est impressionnant!\p"
	.string "Il ne reste plus de DRESSEURS\n"
	.string "à ce niveau.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux sept autres DRESSEURS du niveau.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux six autres DRESSEURS du niveau.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux cinq autres DRESSEURS du niveau.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Peut-être réussiras-tu à résister aux\n"
	.string "quatre autres DRESSEURS du niveau.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux trois autres DRESSEURS du niveau.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Peut-être réussiras-tu à résister\n"
	.string "aux deux autres DRESSEURS du niveau.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Peut-être réussiras-tu à résister\n"
	.string "au dernier DRESSEUR du niveau.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Tu as résisté à tous les DRESSEURS\n"
	.string "du niveau. Il n’en reste aucun.$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "sept autres DRESSEURS.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "six autres DRESSEURS.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "cinq autres DRESSEURS.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "quatre autres DRESSEURS.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "trois autres DRESSEURS.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Si ça se trouve, tu vas battre les\n"
	.string "deux autres DRESSEURS.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Si ça se trouve, tu vas battre le\n"
	.string "dernier DRESSEUR.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Tu te bats à la perfection.\p"
	.string "Il ne reste aucun DRESSEUR à\n"
	.string "battre.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Je me demande si tu vas battre\n"
	.string "les sept autres DRESSEURS!$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Je me demande si tu vas battre\n"
	.string "les six autres DRESSEURS!$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Je me demande si tu vas battre\n"
	.string "les cinq autres DRESSEURS!$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Je me demande si tu vas battre\n"
	.string "les quatre autres DRESSEURS!$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Je me demande si tu vas battre\n"
	.string "les trois autres DRESSEURS!$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Je me demande si tu vas battre\n"
	.string "les deux autres DRESSEURS!$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Je me demande si tu vas battre\n"
	.string "le dernier DRESSEUR!$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Il n’y a plus de DRESSEUR à\n"
	.string "battre ici…$"
