LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "MAY: Hé?\n"
	.string "{PLAYER}{KUN}, ben jij ook aan het shoppen?\p"
	.string "Ik kocht een hele hoop DOLLS en\n"
	.string "POSTERS.\p"
	.string "Natuurlijk ving ik ook veel POKéMON\n"
	.string "en ik train ze goed.\p"
	.string "Ik vraag me meer af of jij je\n"
	.string "POKéMON goed traint, {PLAYER}{KUN}.\p"
	.string "Laten we vechten, dan zie ik je\n"
	.string "POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "MAY: Oh, waarom? {PLAYER}{KUN}, train je\n"
	.string "je POKéMON niet?\p"
	.string "Dat is geen goed voorbeeld\n"
	.string "voor een TRAINER…$"

LilycoveCity_Text_MayBattleMe:
	.string "MAY: Kom op, vecht met me, dan\n"
	.string "zie ik je POKéMON!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "MAY: Mijn POKéMON verliezen niet\n"
	.string "van jouw POKéMON, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Ik denk aan ons gevecht op\n"
	.string "ROUTE 103, {PLAYER}{KUN}.\p"
	.string "Dat gevecht hielp je zo sterk te\n"
	.string "worden, {PLAYER}{KUN}, hè?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "MAY: Ik ga straks terug naar\n"
	.string "LITTLEROOT.\p"
	.string "Ik ving best veel POKéMON en mijn\n"
	.string "POKéDEX groeit, dus ik ga naar\l"
	.string "huis om het aan papa te laten zien.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, wat ga jij doen?\p"
	.string "Alle GYM BADGES verzamelen en\n"
	.string "naar de POKéMON LEAGUE gaan?\p"
	.string "Terwijl jij BADGES verzamelt,\n"
	.string "{PLAYER}{KUN}, werk ik aan mijn POKéDEX.\l"
	.string "Ik maak hem eerder af dan jij!\p"
	.string "Tot ziens!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, wat ga jij doen?\p"
	.string "Doe je mee aan de POKéMON LEAGUE?\p"
	.string "Of maak je je POKéDEX af?\p"
	.string "Ik verloor misschien van je, maar\n"
	.string "ik maak mijn POKéDEX eerder af!\p"
	.string "Tot ziens!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, wat ga jij doen?\p"
	.string "Doe je mee aan het BATTLE FRONTIER?\p"
	.string "Of maak je je POKéDEX af?\p"
	.string "Ik verloor misschien van je, maar\n"
	.string "ik maak mijn POKéDEX eerder af!\p"
	.string "Tot ziens!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRENDAN: O, hé, het is {PLAYER}.\p"
	.string "Ik doe een boodschap voor mijn pa.\n"
	.string "Nee, ik koop geen DOLLS.\p"
	.string "Hoe dan ook, lang geleden.\p"
	.string "Zullen we vechten om te zien wie\n"
	.string "zijn POKéMON beter traint?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRENDAN: O, wat is er?\n"
	.string "Heb je geen zelfvertrouwen?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRENDAN: Zullen we vechten om te\n"
	.string "zien wie beter traint?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRENDAN: Aww, je weet dat ik niet\n"
	.string "ga verliezen van jou, {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Pfff…\n"
	.string "Je hebt veel getraind.\p"
	.string "Dat doet pijn, ik had een voorsprong\n"
	.string "als TRAINER…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRENDAN: Ik…\n"
	.string "Ik ga naar huis, naar LITTLEROOT.\p"
	.string "Ik help mijn pa met zijn POKéDEX.\n"
	.string "Hij wordt best goed, dus ik moet\n"
	.string "hem even laten zien.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, wat ga jij doen?\p"
	.string "Alle GYM BADGES verzamelen en\n"
	.string "naar de POKéMON LEAGUE gaan?\p"
	.string "Misschien doe ik dat ook…\p"
	.string "Nou, zet 'm op!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, wat ga jij doen?\p"
	.string "Je bent zo sterk. Doe je mee aan de\n"
	.string "POKéMON LEAGUE?\p"
	.string "Heh, als ik mijn POKéMON wat meer\n"
	.string "train, ben ik sterker dan jij,\l"
	.string "{PLAYER}.\p"
	.string "Nou, zet 'm op!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, wat ga jij doen?\p"
	.string "Doe je mee aan het BATTLE FRONTIER?\p"
	.string "Of maak je je POKéDEX af?\p"
	.string "Je bent zo sterk, je moet het\n"
	.string "BATTLE FRONTIER proberen.\p"
	.string "Heh, als ik mijn POKéMON wat meer\n"
	.string "train, ben ik sterker dan jij,\l"
	.string "{PLAYER}.\p"
	.string "Misschien ga ik ook naar het\n"
	.string "BATTLE FRONTIER.\p"
	.string "Nou, zet 'm op!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Hihihi…\p"
	.string "Vandaag brachten we meer buit\n"
	.string "naar onze geheime SCHUILPLAATS…\p"
	.string "W-wie ben jij?!\n"
	.string "Ik praatte tegen mezelf!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Ik ben maar een HANDLANGER, dus ik\n"
	.string "weet niet wat de BAAS denkt…\p"
	.string "Maar bij TEAM AQUA krijg ik vast\n"
	.string "kansen voor grote dingen!\p"
	.string "W-wie ben jij?!\n"
	.string "Ik praatte tegen mezelf!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Hé, jij!\p"
	.string "Ga niet in de buurt van de grot\n"
	.string "in de baai!\p"
	.string "Waarom? Daar heb je geen reden\n"
	.string "voor nodig! Ik ben groot, dus luister!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Als de hele wereld van TEAM AQUA\n"
	.string "wordt, is het ook voor POKéMON\l"
	.string "een fijnere plek.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Daar! WAILMER!\n"
	.string "Spring nu uit het water!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hè? Wat moet je?\p"
	.string "Je verpest onze training,\n"
	.string "dus donder maar op, oké?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Er is een POKéMON WEDSTRIJDHAL\n"
	.string "hier in deze stad.\p"
	.string "Dus goed getrainde POKéMON komen\n"
	.string "uit het hele land.\p"
	.string "Mijn hart klopt van spanning!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Heb je die rare grot in de baai\n"
	.string "aan de rand van de stad gezien?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Ik leer mijn POKéMON nieuwe\n"
	.string "aanvallen voor een WEDSTRIJD.\p"
	.string "Dus ga ik naar de MOVE DELETER\n"
	.string "om HM-aanvallen te laten vergeten.$"

LilycoveCity_Text_ImFromKanto:
	.string "Ik kom uit KANTO.\p"
	.string "HOENN is mooi, met zoveel water en\n"
	.string "weelderige natuur.\p"
	.string "Hè? Wacht even…\p"
	.string "Leven hier misschien zeldzame\n"
	.string "POKéMON die alleen hier wonen?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "TEAM AQUA trainde zijn\n"
	.string "WAILMER in de baai.\p"
	.string "Wij MATROZEN konden niet de zee\n"
	.string "op met ze in de weg!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ahoy, weet je het al?\p"
	.string "Iemand schopte TEAM AQUA\n"
	.string "voor ons weg!\p"
	.string "De WAILMER zijn de baai uit,\n"
	.string "dus we kunnen weer varen.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Ik lag lekker te slapen in de\n"
	.string "herberg aan zee, met golfgeluid…\p"
	.string "Toen stal iemand mijn POKéMON!\p"
	.string "Wie was de dief?\n"
	.string "TEAM AQUA? Was het TEAM AQUA?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Mijn vermiste POKéMON…\n"
	.string "Hij kwam terug zonder dat ik het zag!$"

LilycoveCity_Text_ImArtDealer:
	.string "Ik ben een KUNSTHANDELAAR.\p"
	.string "Ik koop en verkoop mooie kunst,\n"
	.string "vooral schilderijen.\p"
	.string "Ik hoor dat het MUSEUM hier\n"
	.string "prachtige werken heeft…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Al worden wij oud en rimpelig,\n"
	.string "de zee blijft altijd jong,\l"
	.string "vol levendige glans…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "Zestig jaar geleden vroeg mijn man\n"
	.string "mij hier ten huwelijk.\l"
	.string "De zee is nog net zo mooi.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, ken je de rare grot\n"
	.string "in deze baai?\p"
	.string "Die was eerst natuurlijk, maar toen\n"
	.string "kwam TEAM AQUA en bouwde hem om.\p"
	.string "Ze noemen zich\n"
	.string "“de natuurlievende TEAM AQUA”!\p"
	.string "Maar wat ze doen en zeggen\n"
	.string "klopt helemaal niet!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Die grot in de baai…\p"
	.string "Ik zag het niet meteen, maar\n"
	.string "hij is nu helemaal leeg.\p"
	.string "Die TEAM AQUA is vast\n"
	.string "voorgoed weggegaan.$"

LilycoveCity_Text_CitySign:
	.string "LILYCOVE CITY\p"
	.string "“Waar het land eindigt en\n"
	.string "de zee begint.”$"

LilycoveCity_Text_ContestHallSign:
	.string "POKéMON WEDSTRIJDHAL\n"
	.string "“Het verzamelpunt voor TRAINERS!”$"

LilycoveCity_Text_MotelSign:
	.string "COVE LILY MOTEL\p"
	.string "“Onthoud ons als COVE LILY van\n"
	.string "LILYCOVE.”$"

LilycoveCity_Text_MuseumSign:
	.string "LILYCOVE MUSEUM\p"
	.string "“Meesterwerken van POKéMON\n"
	.string "nu te zien!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "LILYCOVE MUSEUM\p"
	.string "“De POKéMON van {PLAYER}\n"
	.string "nu te zien!”$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "LILYCOVE CITY HAVEN\p"
	.string "“De ferry S.S. TIDAL wordt nog\n"
	.string "gebouwd in SLATEPORT CITY.\p"
	.string "“De dienst begint binnenkort.”$"

LilycoveCity_Text_HarborSign:
	.string "LILYCOVE CITY HAVEN\p"
	.string "“Geniet van een fijne reis met\n"
	.string "de ferry S.S. TIDAL.”$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "POKéMON TRAINER FANCLUB\p"
	.string "Op het bord staan overal\n"
	.string "namen van TRAINERS gekrabbeld…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "LILYCOVE WARENHUIS\p"
	.string "“Vol met leuke spullen\n"
	.string "en spanning!\p"
	.string "“Hier vind je wat je nodig hebt!”$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "HUIS VAN DE MOVE DELETER\p"
	.string "“Laat ongewenste aanvallen vergeten.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Ken je de machine\n"
	.string "BESSENMIXER?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Mensen moeten samenwerken om hem\n"
	.string "sneller te laten draaien.\p"
	.string "Hoe sneller hij draait, hoe betere\n"
	.string "{POKEBLOCK}S je krijgt, hoor ik.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "Hij maakt een soort snoep:\n"
	.string "een {POKEBLOCK}.\p"
	.string "Geef je POKéMON een goede {POKEBLOCK},\n"
	.string "dan wordt zijn vorm veel beter.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "Ik hoorde dat er ergens op zee\n"
	.string "een toren staat.\p"
	.string "Hij heet de SKY PILLAR, hoor ik.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "Ik zag een hoge toren ergens\n"
	.string "bij ROUTE 131.\p"
	.string "Zou dat…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "We zijn net aangekomen voor\n"
	.string "onze huwelijksreis.\p"
	.string "We zagen een DRAAK-POKéMON\n"
	.string "hoog in de lucht vliegen.\p"
	.string "Leven zulke gave POKéMON\n"
	.string "in HOENN?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Tijdens onze huwelijksreis wilden\n"
	.string "we zoveel zeldzame POKéMON zien.\p"
	.string "Dus we waren blij dat we meteen\n"
	.string "een zeldzame POKéMON zagen.\p"
	.string "We zijn helemaal gelukkig!$"

