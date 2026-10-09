BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applywaitmovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "Ben je hier voor het eerst?\n"
	.string "Kom maar deze kant op!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "De frontlinie van POKéMON-gevechten!\n"
	.string "Welkom bij de BATTLE FRONTIER!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Voor nieuwe bezoekers hebben we de\n"
	.string "FRONTIER PASS.\p"
	.string "Die gebruik je in alle gebouwen\n"
	.string "van de BATTLE FRONTIER.\p"
	.string "Hier heb je hem!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} krijgt\n"
	.string "de FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} stopt de TRAINERKAART\n"
	.string "in de FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Veel plezier in de BATTLE\n"
	.string "FRONTIER!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Nou, als dat niet {PLAYER}{KUN} is!\n"
	.string "Je bent hier gekomen!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GIDS: Oh! MR. SCOTT, meneer!\n"
	.string "Goedendag, meneer!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SCOTT: Fijn je hier te zien,\n"
	.string "echt waar!\p"
	.string "Ik hoop dat je rustig de tijd neemt\n"
	.string "om overal rond te kijken.\p"
	.string "Natuurlijk hoop ik ook dat je de\n"
	.string "pure essentie van vechten ervaart.\p"
	.string "Ik heb hier ook mijn kamers, dus\n"
	.string "kom gerust langs als je tijd hebt.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Ik ben je gids voor de verschillende\n"
	.string "gebouwen hier in de BATTLE FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Waarover wil je meer weten?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "Het is de gigantische toren, het\n"
	.string "symbool van de BATTLE FRONTIER.\p"
	.string "Er zijn vier soorten GEVECHTSKAMERS\n"
	.string "in de toren voor ENKEL, DUBBEL,\l"
	.string "MULTI- en LINK MULTI-GEVECHTEN.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "De BATTLE DOME is het grote gebouw\n"
	.string "in de vorm van een enorm ei.\p"
	.string "Hier worden toernooien gehouden.\p"
	.string "Er zijn twee routes: voor ENKELE\n"
	.string "en DUBBELE GEVECHTEN.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "Het BATTLE PALACE is het rode\n"
	.string "gebouw rechts in de BATTLE FRONTIER.\p"
	.string "Er zijn twee soorten ZALEN voor\n"
	.string "ENKELE en DUBBELE GEVECHTEN.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "De BATTLE ARENA is het gebouw dat\n"
	.string "eruitziet als een dojo, rechts van\l"
	.string "het midden van de BATTLE FRONTIER.\p"
	.string "In de BATTLE ARENA is het\n"
	.string "KO-toernooi.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "De BATTLE FACTORY is het grote\n"
	.string "gebouw dat het dichtst bij ons is.\p"
	.string "Daar wordt Battle Swap gedaan.\p"
	.string "Battle Swap heeft twee routes\n"
	.string "voor ENKELE en DUBBELE GEVECHTEN.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "De BATTLE PIKE is het gebouw in de\n"
	.string "vorm van een POKéMON, links van het\l"
	.string "midden van de BATTLE FRONTIER.\p"
	.string "Daar wordt Battle Choice gedaan.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "De BATTLE PYRAMID is de enorme\n"
	.string "piramide.\p"
	.string "Daar wordt Battle Quest gedaan.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "De RANKING HALL ligt bij de\n"
	.string "BATTLE TOWER.\p"
	.string "Daar zie je de beste records van\n"
	.string "de TRAINERS die de uitdagingen van\l"
	.string "de BATTLE FRONTIER deden.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "De EXCHANGE SERVICE CORNER ligt\n"
	.string "bij de BATTLE TOWER.\p"
	.string "Daar kun je GEVECHTSPUNTEN uit de\n"
	.string "BATTLE FRONTIER inruilen voor\l"
	.string "prachtige prijzen.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Ik ben je gids voor de basisregels\n"
	.string "die gelden voor alle uitdagingen\l"
	.string "in de gebouwen van de BATTLE\l"
	.string "FRONTIER.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Waarover wil je meer weten?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Alle uitdagingen in de BATTLE\n"
	.string "FRONTIER hebben twee routes--\l"
	.string "Level 50 en Open Level.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "De Level 50-route is voor POKéMON tot\n"
	.string "en met Level 50.\p"
	.string "Let op: de TRAINERS die je tegenkomt\n"
	.string "hebben geen POKéMON onder Level 50.\p"
	.string "Deze route is het beginniveau\n"
	.string "voor gevechten in de BATTLE FRONTIER.\p"
	.string "Begin graag met deze route.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "De Open Level-route heeft geen\n"
	.string "limiet voor de levels van POKéMON.\p"
	.string "Het level van je tegenstanders\n"
	.string "wordt aangepast aan je POKéMON.\p"
	.string "Maar de TRAINERS die je tegenkomt\n"
	.string "hebben geen POKéMON onder Level 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Bijna elke soort POKéMON mag meedoen\n"
	.string "aan de uitdagingen.\p"
	.string "EIEREN en sommige soorten POKéMON\n"
	.string "mogen niet.\p"
	.string "Hoeveel POKéMON je nodig hebt,\n"
	.string "hangt af van het gebouw.\p"
	.string "In alle gebouwen mogen twee of meer\n"
	.string "POKéMON van dezelfde soort niet.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "Bij een uitdaging in de BATTLE\n"
	.string "FRONTIER mogen POKéMON niet\l"
	.string "dezelfde soort voorwerp vasthouden.\p"
	.string "Zorg dat alle POKéMON die meedoen\n"
	.string "verschillende voorwerpen vasthouden.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Ik ben je gids voor de FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Waarover wil je meer weten?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "De BATTLE FRONTIER heeft zeven\n"
	.string "gebouwen.\p"
	.string "TRAINERS die erkend worden om hun\n"
	.string "kunnen, krijgen misschien een\l"
	.string "symbool van elk gebouw.\p"
	.string "Om een symbool te krijgen, moet je\n"
	.string "misschien TRAINERS achter elkaar\l"
	.string "verslaan of vaak toernooien winnen.\p"
	.string "Symbolen winnen is zeker niet\n"
	.string "makkelijk. Veel succes!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Je kunt één gevecht opslaan op je\n"
	.string "FRONTIER PASS.\p"
	.string "Dat kan een gevecht met een\n"
	.string "vriend of vrienden zijn.\p"
	.string "Of een gevecht in de BATTLE\n"
	.string "FRONTIER, behalve gevechten in de\l"
	.string "BATTLE PIKE of de BATTLE PYRAMID.\p"
	.string "Je kunt kiezen om je gevecht op\n"
	.string "te slaan na afloop.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "GEVECHTSPUNTEN zijn beloningen voor\n"
	.string "TRAINERS die geweldig vochten in\l"
	.string "de BATTLE FRONTIER.\p"
	.string "Je kunt je GEVECHTSPUNTEN inruilen\n"
	.string "voor prijzen bij de EXCHANGE\l"
	.string "SERVICE CORNER.$"

