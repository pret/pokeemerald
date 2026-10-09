BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
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
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
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
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, LOCALID_NONE, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
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
	.string "Dit is een voorbeeldbericht.$"

gText_BattlePyramidConfirmRest::
	.string "Je BATTLE PYRAMID-tocht wordt\n"
	.string "opgeslagen, zodat je kunt stoppen.\l"
	.string "Is dat goed?$"

gText_BattlePyramidConfirmRetire::
	.string "Weet je zeker dat je wilt stoppen\n"
	.string "met je PYRAMID-tocht?$"

BattlePyramid_Text_ExitHintUp1::
	.string "De uitgang van deze verdieping\n"
	.string "is die kant op: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "De uitgang van deze verdieping\n"
	.string "is die kant op: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "De uitgang van deze verdieping\n"
	.string "is die kant op: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "De uitgang van deze verdieping\n"
	.string "is die kant op: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "De uitgang van deze verdieping\n"
	.string "is in de richting {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "De uitgang van deze verdieping\n"
	.string "is in de richting {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "De uitgang van deze verdieping\n"
	.string "is in de richting {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "De uitgang van deze verdieping\n"
	.string "is in de richting {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "De uitgang is die\n"
	.string "kant op: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft3::
	.string "De uitgang is die\n"
	.string "kant op: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight3::
	.string "De uitgang is die\n"
	.string "kant op: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown3::
	.string "De uitgang is die\n"
	.string "kant op: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp4::
	.string "Op deze verdieping is de uitgang\n"
	.string "ergens in de richting {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "Op deze verdieping is de uitgang\n"
	.string "ergens in de richting {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "Op deze verdieping is de uitgang\n"
	.string "ergens in de richting {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "Op deze verdieping is de uitgang\n"
	.string "ergens in de richting {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "De uitgang?\n"
	.string "Die is die kant op: {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft5::
	.string "De uitgang?\n"
	.string "Die is die kant op: {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight5::
	.string "De uitgang?\n"
	.string "Die is die kant op: {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown5::
	.string "De uitgang?\n"
	.string "Die is die kant op: {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp6::
	.string "De uitgang is toevallig\n"
	.string "in de richting {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "De uitgang is toevallig\n"
	.string "in de richting {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "De uitgang is toevallig\n"
	.string "in de richting {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "De uitgang is toevallig\n"
	.string "in de richting {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Zoek je voorwerpen?\p"
	.string "Er zijn nog acht voorwerpen\n"
	.string "te vinden.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Zoek je voorwerpen?\p"
	.string "Er zijn nog zeven voorwerpen\n"
	.string "te vinden.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Zoek je voorwerpen?\p"
	.string "Er zijn nog zes voorwerpen\n"
	.string "te vinden.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Zoek je voorwerpen?\p"
	.string "Er zijn nog vijf voorwerpen\n"
	.string "te vinden.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Zoek je voorwerpen?\p"
	.string "Er zijn nog vier voorwerpen\n"
	.string "te vinden.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Zoek je voorwerpen?\p"
	.string "Er zijn nog drie voorwerpen\n"
	.string "te vinden.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Zoek je voorwerpen?\p"
	.string "Er zijn nog twee voorwerpen\n"
	.string "te vinden.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Zoek je voorwerpen?\p"
	.string "Er is nog één voorwerp\n"
	.string "te vinden.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Zoek je voorwerpen?\p"
	.string "Er is niets meer\n"
	.string "te vinden!$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Omdat je won, vertel ik je\n"
	.string "een geheimpje!\p"
	.string "Er liggen hier nog acht\n"
	.string "voorwerpen.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Omdat je won, vertel ik je\n"
	.string "een geheimpje!\p"
	.string "Er liggen hier nog zeven\n"
	.string "voorwerpen.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Omdat je won, vertel ik je\n"
	.string "een geheimpje!\p"
	.string "Er liggen hier nog zes\n"
	.string "voorwerpen.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Omdat je won, vertel ik je\n"
	.string "een geheimpje!\p"
	.string "Er liggen hier nog vijf\n"
	.string "voorwerpen.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Omdat je won, vertel ik je\n"
	.string "een geheimpje!\p"
	.string "Er liggen hier nog vier\n"
	.string "voorwerpen.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Omdat je won, vertel ik je\n"
	.string "een geheimpje!\p"
	.string "Er liggen hier nog drie\n"
	.string "voorwerpen.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Omdat je won, vertel ik je\n"
	.string "een geheimpje!\p"
	.string "Er liggen hier nog twee\n"
	.string "voorwerpen.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Omdat je won, vertel ik je\n"
	.string "een geheimpje!\p"
	.string "Er ligt hier nog één\n"
	.string "voorwerp.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Omdat je won, vertel ik je\n"
	.string "een geheimpje!\p"
	.string "Er ligt hier niets\n"
	.string "meer.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Hoe staat het met je voorraad?\p"
	.string "Ik denk dat er op deze verdieping\n"
	.string "nog acht voorwerpen liggen.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Hoe staat het met je voorraad?\p"
	.string "Ik denk dat er op deze verdieping\n"
	.string "nog zeven voorwerpen liggen.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Hoe staat het met je voorraad?\p"
	.string "Ik denk dat er op deze verdieping\n"
	.string "nog zes voorwerpen liggen.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Hoe staat het met je voorraad?\p"
	.string "Ik denk dat er op deze verdieping\n"
	.string "nog vijf voorwerpen liggen.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Hoe staat het met je voorraad?\p"
	.string "Ik denk dat er op deze verdieping\n"
	.string "nog vier voorwerpen liggen.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Hoe staat het met je voorraad?\p"
	.string "Ik denk dat er op deze verdieping\n"
	.string "nog drie voorwerpen liggen.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Hoe staat het met je voorraad?\p"
	.string "Ik denk dat er op deze verdieping\n"
	.string "nog twee voorwerpen liggen.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Hoe staat het met je voorraad?\p"
	.string "Ik denk dat er op deze verdieping\n"
	.string "nog maar één voorwerp ligt.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Hoe staat het met je voorraad?\p"
	.string "Ik denk dat er op deze verdieping\n"
	.string "geen voorwerpen meer liggen.\l"
	.string "Tot ziens!$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Je bent sterk, dus je krijgt\n"
	.string "een hint!\p"
	.string "Er liggen nog acht\n"
	.string "voorwerpen op de grond.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Je bent sterk, dus je krijgt\n"
	.string "een hint!\p"
	.string "Er liggen nog zeven\n"
	.string "voorwerpen op de grond.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Je bent sterk, dus je krijgt\n"
	.string "een hint!\p"
	.string "Er liggen nog zes\n"
	.string "voorwerpen op de grond.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Je bent sterk, dus je krijgt\n"
	.string "een hint!\p"
	.string "Er liggen nog vijf\n"
	.string "voorwerpen op de grond.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Je bent sterk, dus je krijgt\n"
	.string "een hint!\p"
	.string "Er liggen nog vier\n"
	.string "voorwerpen op de grond.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Je bent sterk, dus je krijgt\n"
	.string "een hint!\p"
	.string "Er liggen nog drie\n"
	.string "voorwerpen op de grond.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Je bent sterk, dus je krijgt\n"
	.string "een hint!\p"
	.string "Er liggen nog twee\n"
	.string "voorwerpen op de grond.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Je bent sterk, dus je krijgt\n"
	.string "een hint!\p"
	.string "Er ligt nog maar één\n"
	.string "voorwerp op de grond.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Je bent sterk, dus je krijgt\n"
	.string "een hint!\p"
	.string "Er liggen geen voorwerpen\n"
	.string "meer op de grond.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "Op deze verdieping van de\n"
	.string "PYRAMID liggen acht voorwerpen…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "Op deze verdieping van de\n"
	.string "PYRAMID liggen zeven voorwerpen…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "Op deze verdieping van de\n"
	.string "PYRAMID liggen zes voorwerpen…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "Op deze verdieping van de\n"
	.string "PYRAMID liggen vijf voorwerpen…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "Op deze verdieping van de\n"
	.string "PYRAMID liggen vier voorwerpen…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "Op deze verdieping van de\n"
	.string "PYRAMID liggen drie voorwerpen…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "Op deze verdieping van de\n"
	.string "PYRAMID liggen twee voorwerpen…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "Op deze verdieping van de\n"
	.string "PYRAMID ligt één voorwerp…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "Op deze verdieping van de\n"
	.string "PYRAMID liggen geen voorwerpen…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Heb je al voorwerpen gevonden?\p"
	.string "Ik denk dat hier nog acht\n"
	.string "voorwerpen liggen.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Heb je al voorwerpen gevonden?\p"
	.string "Ik denk dat hier nog zeven\n"
	.string "voorwerpen liggen.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Heb je al voorwerpen gevonden?\p"
	.string "Ik denk dat hier nog zes\n"
	.string "voorwerpen liggen.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Heb je al voorwerpen gevonden?\p"
	.string "Ik denk dat hier nog vijf\n"
	.string "voorwerpen liggen.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Heb je al voorwerpen gevonden?\p"
	.string "Ik denk dat hier nog vier\n"
	.string "voorwerpen liggen.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Heb je al voorwerpen gevonden?\p"
	.string "Ik denk dat hier nog drie\n"
	.string "voorwerpen liggen.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Heb je al voorwerpen gevonden?\p"
	.string "Ik denk dat hier nog twee\n"
	.string "voorwerpen liggen.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Heb je al voorwerpen gevonden?\p"
	.string "Ik denk dat hier nog één\n"
	.string "voorwerp ligt.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Heb je al voorwerpen gevonden?\p"
	.string "Ik denk dat hier geen\n"
	.string "voorwerpen meer liggen.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Wat was jij goed!\p"
	.string "Maar er zijn nog zeven sterke\n"
	.string "TRAINERS behalve ik!$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Wat was jij goed!\p"
	.string "Maar er zijn nog zes sterke\n"
	.string "TRAINERS behalve ik!$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Wat was jij goed!\p"
	.string "Maar er zijn nog vijf sterke\n"
	.string "TRAINERS behalve ik!$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Wat was jij goed!\p"
	.string "Maar er zijn nog vier sterke\n"
	.string "TRAINERS behalve ik!$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Wat was jij goed!\p"
	.string "Maar er zijn nog drie sterke\n"
	.string "TRAINERS behalve ik!$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Wat was jij goed!\p"
	.string "Maar er zijn nog twee sterke\n"
	.string "TRAINERS behalve ik!$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Wat was jij goed!\p"
	.string "Maar er is nog één sterke\n"
	.string "TRAINER behalve ik!$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Wat was jij goed!\p"
	.string "Er is niemand meer die\n"
	.string "jou kan verslaan!$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "Wat vervelend!\p"
	.string "Maar er zijn nog zeven TRAINERS!\n"
	.string "Iemand maakt je klein!$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "Wat vervelend!\p"
	.string "Maar er zijn nog zes TRAINERS!\n"
	.string "Iemand maakt je klein!$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "Wat vervelend!\p"
	.string "Maar er zijn nog vijf TRAINERS!\n"
	.string "Iemand maakt je klein!$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "Wat vervelend!\p"
	.string "Maar er zijn nog vier TRAINERS!\n"
	.string "Iemand maakt je klein!$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "Wat vervelend!\p"
	.string "Maar er zijn nog drie TRAINERS!\n"
	.string "Iemand maakt je klein!$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "Wat vervelend!\p"
	.string "Maar er zijn nog twee TRAINERS!\n"
	.string "Iemand maakt je klein!$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "Wat vervelend!\p"
	.string "Maar er is nog één TRAINER!\n"
	.string "Die maakt je vast klein!$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "Wat vervelend!\p"
	.string "Maar er zijn geen TRAINERS meer\n"
	.string "die tegen je kunnen vechten!$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "Best indrukwekkend!\p"
	.string "Maar er zijn nog zeven TRAINERS\n"
	.string "op deze verdieping. Pak je ze allemaal?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "Best indrukwekkend!\p"
	.string "Maar er zijn nog zes TRAINERS\n"
	.string "op deze verdieping. Pak je ze allemaal?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "Best indrukwekkend!\p"
	.string "Maar er zijn nog vijf TRAINERS\n"
	.string "op deze verdieping. Pak je ze allemaal?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "Best indrukwekkend!\p"
	.string "Maar er zijn nog vier TRAINERS\n"
	.string "op deze verdieping. Pak je ze allemaal?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "Best indrukwekkend!\p"
	.string "Maar er zijn nog drie TRAINERS\n"
	.string "op deze verdieping. Pak je ze allemaal?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "Best indrukwekkend!\p"
	.string "Maar er zijn nog twee TRAINERS\n"
	.string "op deze verdieping. Pak je ze allebei?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "Best indrukwekkend!\p"
	.string "Maar er is nog één TRAINER\n"
	.string "op deze verdieping. Lukt het?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "Best indrukwekkend!\p"
	.string "Je hebt alle TRAINERS op\n"
	.string "deze verdieping verslagen.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Misschien kun je alle zeven\n"
	.string "TRAINERS op deze verdieping aan.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Misschien kun je alle zes\n"
	.string "TRAINERS op deze verdieping aan.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Misschien kun je alle vijf\n"
	.string "TRAINERS op deze verdieping aan.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Misschien kun je alle vier\n"
	.string "TRAINERS op deze verdieping aan.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Misschien kun je alle drie\n"
	.string "TRAINERS op deze verdieping aan.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Misschien kun je alle twee\n"
	.string "TRAINERS op deze verdieping aan.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Misschien maak je het af met de\n"
	.string "laatste TRAINER op deze verdieping.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Er is niemand meer die je nu\n"
	.string "kan verslaan…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Misschien kun je de zeven sterke\n"
	.string "TRAINERS die over zijn verslaan.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Misschien kun je de zes sterke\n"
	.string "TRAINERS die over zijn verslaan.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Misschien kun je de vijf sterke\n"
	.string "TRAINERS die over zijn verslaan.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Misschien kun je de vier sterke\n"
	.string "TRAINERS die over zijn verslaan.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Misschien kun je de drie sterke\n"
	.string "TRAINERS die over zijn verslaan.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Misschien kun je de twee sterke\n"
	.string "TRAINERS die over zijn verslaan.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Misschien kun je de laatste sterke\n"
	.string "TRAINER die over is verslaan.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Je bent onverslaanbaar.\p"
	.string "Er zijn hier geen TRAINERS meer\n"
	.string "die je kunnen verslaan.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Blijf je winnen van de zeven\n"
	.string "TRAINERS die over zijn?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Blijf je winnen van de zes\n"
	.string "TRAINERS die over zijn?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Blijf je winnen van de vijf\n"
	.string "TRAINERS die over zijn?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Blijf je winnen van de vier\n"
	.string "TRAINERS die over zijn?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Blijf je winnen van de drie\n"
	.string "TRAINERS die over zijn?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Blijf je winnen van de twee\n"
	.string "TRAINERS die over zijn?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Blijf je winnen van de laatste\n"
	.string "TRAINER die over is?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Er is geen TRAINER meer die\n"
	.string "het tegen je opneemt…$"
