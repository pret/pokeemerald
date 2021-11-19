.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

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
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
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
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
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
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
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
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
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
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
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
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "This is the BATTLE DOME!\n"
	.string "Your path to the invincible superstar!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "This is the BATTLE FACTORY!\n"
	.string "Seek out the toughest POKéMON!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "This is the BATTLE PIKE!\n"
	.string "Choose one of three paths!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "This is the BATTLE TOWER.\p"
	.string "TRAINERS bring their best-raised\n"
	.string "POKéMON for elimination-style matches.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "SLATEPORT CITY it is, then!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "LILYCOVE CITY it is, then!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Please sail with us another time!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Then, where would you like to go?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "I'm the best out of all my friends.\n"
	.string "But here…\l"
	.string "I've been useless!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "I want to go to the BATTLE TOWER,\n"
	.string "but I can't find it even though I have\l"
	.string "a map of the BATTLE FRONTIER.\p"
	.string "This place is just too big!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "I wanted to take a challenge as soon\n"
	.string "as I arrived here.\p"
	.string "But on the way, I got seasick…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "It's not as if just anyone can come\n"
	.string "here, you know?\p"
	.string "Only those TRAINERS who've been\n"
	.string "recognized as tough are brought here.\p"
	.string "That's why many TRAINERS don't even\n"
	.string "know about the BATTLE FRONTIER.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Hey, bro…\p"
	.string "Are you sure we can make challenges\n"
	.string "even if we don't have any POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Uh…\n"
	.string "I'm sure it'll be okay.\p"
	.string "I think…\p"
	.string "But remember that big scary guy?\n"
	.string "He said, “I'll lend you POKéMON!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "That's the BATTLE FACTORY.\n"
	.string "You can rent strong POKéMON there.\p"
	.string "But it makes me wonder.\n"
	.string "Who's raising those rental POKéMON?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "I'm scared of going into the BATTLE\n"
	.string "PIKE because of SEVIPER…\p"
	.string "B-but I came all the way here, so I will\n"
	.string "try to conquer everything!\l"
	.string "…Shudder…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Let's play rock, paper, scissors!\n"
	.string "One, two, three!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Yay! I won!\n"
	.string "I will take the BATTLE PIKE challenge!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, no…\n"
	.string "I lost.\p"
	.string "I guess I'm not very lucky today.\n"
	.string "I'll put off my BATTLE PIKE challenge\l"
	.string "until tomorrow.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "I believe I'm the only person here who,\n"
	.string "for some unknown reason, would choose\l"
	.string "fishing over battling.\p"
	.string "Huh? You can't catch anything here?\n"
	.string "That's disappointing…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Today, I'm going to keep battling, no\n"
	.string "matter what, until I get a Symbol.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh? You're off to challenge\n"
	.string "the BATTLE DOME?\p"
	.string "I'll wish you the best of luck.\n"
	.string "Let us both win our way up and meet\l"
	.string "in challenges.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Grandpa, over here!\n"
	.string "The BATTLE DOME is here!\l"
	.string "Go get 'em, Grandpa!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, so this here is the BATTLE DOME?\n"
	.string "I won't let GENTLEMEN beat me!\p"
	.string "But where is the entrance?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "There used to be nothing here not all\n"
	.string "that long ago.\p"
	.string "But, now look at this place! Amazing!\n"
	.string "I'll bring my mother out to see this.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "I've finally arrived at the BATTLE\n"
	.string "FRONTIER!\p"
	.string "I'm sure to grab attention with\n"
	.string "my looks and ability!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Munch, munch…\p"
	.string "It looks like this square's filled with\n"
	.string "tough people.\p"
	.string "Munch, munch…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Crunch, munch…\p"
	.string "A while back, I met this older girl\n"
	.string "at the BATTLE PIKE.\p"
	.string "She had these eyes that were scary\n"
	.string "in a real ornery way.\p"
	.string "Crunch, munch…\p"
	.string "She got all furious: “Will you quit\n"
	.string "eating!” Then she whaled on me.\p"
	.string "It was a hair-raising kind of\n"
	.string "scary experience, sure enough.\p"
	.string "Crunch, munch…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Huh? Will you listen to yourself?\n"
	.string "That's nothing!\p"
	.string "Why, the last time I cheered for him,\n"
	.string "our eyes met and sparks flew!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Whaaaaaat?!\n"
	.string "Pfft!\p"
	.string "That only happened because\n"
	.string "I happened to be sitting next to you!\p"
	.string "The DOME ACE only looked our way\n"
	.string "because my cheering was so loud!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Oh, shush!\n"
	.string "Keep that racket down!\p"
	.string "You fair-weather fans should stick\n"
	.string "to cheering for some GYM LEADER!\p"
	.string "The DOME ACE is mine!\n"
	.string "The only idol for me!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Those people squabbling over there…\p"
	.string "It's hard to believe, but they once\n"
	.string "were TRAINERS, and good ones, too.\p"
	.string "They used to be incredibly tough,\n"
	.string "and they were famous, too.\p"
	.string "But they were obliterated by this\n"
	.string "certain TRAINER at a tournament.\p"
	.string "They were so thoroughly whipped,\n"
	.string "they became smitten by the TRAINER.\p"
	.string "Now they're just fans of the TRAINER.\n"
	.string "They go cheer for their idol at the\l"
	.string "BATTLE DOME every day now.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "I heard a rumor that someone saw\n"
	.string "a POKéMON with an unusually long tail\l"
	.string "somewhere in the BATTLE FRONTIER.\p"
	.string "It must be adorable. I'm sure of it…\p"
	.string "Oh, challenges can wait. I feel driven\n"
	.string "to find the delightful creature!$"

