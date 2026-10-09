BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	delay 30
	hideobjectat LOCALID_FRONTIER_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_FRONTIER_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applywaitmovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applywaitmovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applywaitmovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applywaitmovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applywaitmovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "Dit is de BATTLE DOME!\n"
	.string "Jouw pad naar de grootste superster!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "Dit is de BATTLE FACTORY!\n"
	.string "Zoek de sterkste POKéMON!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "Dit is de BATTLE PIKE!\n"
	.string "Kies een van drie paden!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "Dit is de BATTLE TOWER.\p"
	.string "TRAINERS nemen hun best getrainde\n"
	.string "POKéMON mee voor knock-outgevechten.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Hallo, kom je voor de veerboot?\n"
	.string "Mag ik je PAS zien?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} heeft de PAS niet…\p"
	.string "Het spijt me heel erg.\p"
	.string "Je moet een PAS hebben om aan\n"
	.string "boord te gaan.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} laat de PAS zien.\p"
	.string "Perfect! Meer heb je niet nodig!\p"
	.string "En waar wil je naartoe?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "Dan wordt het SLATEPORT CITY!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "Dan wordt het LILYCOVE CITY!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Vaar maar een andere keer met ons mee!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Stap aan boord van de veerboot en\n"
	.string "wacht tot we vertrekken.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Dan, waar wil je naartoe?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Ik ben de beste van al mijn vrienden.\n"
	.string "Maar hier…\l"
	.string "ben ik nutteloos!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Ik wil naar de BATTLE TOWER, maar\n"
	.string "ik kan hem niet vinden, ook al heb\l"
	.string "ik een kaart van de BATTLE FRONTIER.\p"
	.string "Deze plek is gewoon te groot!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Ik wilde meteen een uitdaging doen\n"
	.string "toen ik hier aankwam.\p"
	.string "Maar onderweg werd ik zeeziek…\n"
	.string "Brrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Niet iedereen kan hier komen, weet\n"
	.string "je?\p"
	.string "Alleen TRAINERS die als sterk\n"
	.string "zijn erkend, worden hierheen\l"
	.string "gebracht.\p"
	.string "Daarom weten veel TRAINERS niet\n"
	.string "eens van de BATTLE FRONTIER.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Hé, broer…\p"
	.string "Weet je zeker dat we mogen meedoen\n"
	.string "zonder POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Eh…\n"
	.string "Het komt vast goed.\p"
	.string "Denk ik…\p"
	.string "Maar weet je nog die grote enge man?\n"
	.string "Hij zei: “Ik leen jullie POKéMON!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "Dat is de BATTLE FACTORY.\n"
	.string "Daar kun je sterke POKéMON huren.\p"
	.string "Maar ik vraag me af\n"
	.string "wie die huur-POKéMON opvoedt?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "Ik ben bang om de BATTLE PIKE in te\n"
	.string "gaan vanwege SEVIPER…\p"
	.string "M-maar ik ben helemaal hierheen\n"
	.string "gekomen, dus ik ga alles veroveren!\l"
	.string "…Rilling…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Laten we steen, papier, schaar doen!\n"
	.string "Een, twee, drie!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Yay! Ik won!\n"
	.string "Ik ga de BATTLE PIKE-uitdaging doen!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh nee…\n"
	.string "Ik verloor.\p"
	.string "Ik heb blijkbaar vandaag geen geluk.\n"
	.string "Ik stel mijn BATTLE PIKE-uitdaging\l"
	.string "uit tot morgen.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Ik ben denk ik de enige hier die om\n"
	.string "een onbekende reden liever vist\l"
	.string "dan vecht.\p"
	.string "Hè? Je kunt hier niets vangen?\n"
	.string "Wat jammer…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Vandaag blijf ik vechten, wat er\n"
	.string "ook gebeurt, tot ik een symbool heb.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh? Ga je de BATTLE DOME uitdagen?\p"
	.string "Veel succes. Laten we allebei\n"
	.string "omhoogvechten en elkaar ontmoeten\l"
	.string "in de uitdagingen.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Opa, hier!\n"
	.string "De BATTLE DOME is hier!\l"
	.string "Pak ze, opa!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, dus dit is de BATTLE DOME?\n"
	.string "Ik laat me niet verslaan door\l"
	.string "GENTLEMEN!\p"
	.string "Maar waar is de ingang?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Hier was nog niet zo lang geleden\n"
	.string "niets.\p"
	.string "Maar kijk nu eens! Geweldig!\n"
	.string "Ik neem mijn moeder mee om dit te zien.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Ik ben eindelijk in de BATTLE\n"
	.string "FRONTIER aangekomen!\p"
	.string "Ik val vast op met mijn uiterlijk\n"
	.string "en talent!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Mnam, mnam…\p"
	.string "Het lijkt wel of dit plein vol\n"
	.string "sterke mensen is.\p"
	.string "Mnam, mnam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Knabbel, mnam…\p"
	.string "Een tijdje terug ontmoette ik een\n"
	.string "groter meisje bij de BATTLE PIKE.\p"
	.string "Ze had een eng, chagrijnig blik\n"
	.string "in haar ogen.\p"
	.string "Knabbel, mnam…\p"
	.string "Ze werd woedend: “Hou op met\n"
	.string "eten!” En toen sloeg ze me.\p"
	.string "Het was echt een griezelige\n"
	.string "ervaring.\p"
	.string "Knabbel, mnam…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Hè? Luister je zelf wel?\n"
	.string "Dat is niets!\p"
	.string "De vorige keer dat ik voor hem\n"
	.string "juichte, keken onze ogen elkaar\l"
	.string "aan en vlogen de vonken eraf!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Wáááát?!\n"
	.string "Pfft!\p"
	.string "Dat gebeurde alleen omdat ik\n"
	.string "toevallig naast je zat!\p"
	.string "De DOME ACE keek alleen onze kant\n"
	.string "op omdat ik zo hard juichte!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Oh, stil!\n"
	.string "Hou op met dat lawaai!\p"
	.string "Jullie schoonweerfans kunnen beter\n"
	.string "voor een GYMLEIDER juichen!\p"
	.string "De DOME ACE is van mij!\n"
	.string "Mijn enige idool!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Die mensen die daar ruziën…\p"
	.string "Het is moeilijk te geloven, maar ze\n"
	.string "waren vroeger TRAINERS, en goede.\p"
	.string "Ze waren ongelofelijk sterk en\n"
	.string "ook beroemd.\p"
	.string "Maar ze werden helemaal verslagen\n"
	.string "door een bepaalde TRAINER.\p"
	.string "Ze werden zo hard verslagen dat\n"
	.string "ze verliefd werden op die TRAINER.\p"
	.string "Nu zijn ze fans van die TRAINER.\n"
	.string "Elke dag juichen ze voor hun\l"
	.string "idool bij de BATTLE DOME.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Ik hoorde een gerucht dat iemand\n"
	.string "een POKéMON met een ongewoon\l"
	.string "lange staart zag in de BATTLE FRONTIER.\p"
	.string "Hij moet schattig zijn, vast weten.\p"
	.string "Oh, uitdagingen kunnen wachten.\n"
	.string "Ik moet dat lieve wezen vinden!$"

