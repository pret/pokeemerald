.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts:: @ 823D3E1
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition: @ 823D3E7
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant:: @ 823D3F0
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET, 1
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination:: @ 823D416
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, 0
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket:: @ 823D44E
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport:: @ 823D458
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove:: @ 823D483
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 255, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination:: @ 823D4AE
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry:: @ 823D4BA
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect:: @ 823D4D8
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign:: @ 823D4E2
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign:: @ 823D4EB
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign:: @ 823D4F4
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1:: @ 823D4FD
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2:: @ 823D4FD
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1:: @ 823D50F
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2:: @ 823D518
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1:: @ 823D52D
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1:: @ 823D536
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2:: @ 823D53D
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk:: @ 823D544
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFastestUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper:: @ 823D57F
	lock
	faceplayer
	delay 20
	compare VAR_FACING, DIR_NORTH
	call_if_eq BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	compare VAR_FACING, DIR_SOUTH
	call_if_eq BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	compare VAR_FACING, DIR_WEST
	call_if_eq BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	compare VAR_FACING, DIR_EAST
	call_if_eq BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory:: @ 823D5BA
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory:: @ 823D5C5
	return

BattleFrontier_OutsideWest_EventScript_Girl:: @ 823D5C6
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	compare VAR_FACING, DIR_SOUTH
	call_if_eq BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	compare VAR_FACING, DIR_WEST
	call_if_eq BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	compare VAR_FACING, DIR_EAST
	call_if_eq BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth:: @ 823D5FD
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth:: @ 823D608
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest:: @ 823D613
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast:: @ 823D61E
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth: @ 823D629
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth: @ 823D62C
	walk_in_place_fastest_up
	walk_in_place_fastest_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest: @ 823D62F
	walk_in_place_fastest_right
	walk_in_place_fastest_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast: @ 823D632
	walk_in_place_fastest_left
	walk_in_place_fastest_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2:: @ 823D635
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors:: @ 823D653
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors:: @ 823D65D
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1:: @ 823D667
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3:: @ 823D670
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman:: @ 823D679
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass:: @ 823D682
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM:: @ 823D68B
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2:: @ 823D694
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1:: @ 823D69D
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1:: @ 823D6A6
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2:: @ 823D6AF
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3:: @ 823D6B8
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2:: @ 823D6C3
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan:: @ 823D6CE
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4:: @ 823D6D7
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF:: @ 823D6EE
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign: @ 823D6F7
	.string "This is the BATTLE DOME!\n"
	.string "Your path to the invincible superstar!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign: @ 823D737
	.string "This is the BATTLE FACTORY!\n"
	.string "Seek out the toughest POKéMON!$"

BattleFrontier_OutsideWest_Text_BattlePikeSign: @ 823D772
	.string "This is the BATTLE PIKE!\n"
	.string "Choose one of three paths!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower: @ 823D7A6
	.string "This is the BATTLE TOWER.\p"
	.string "TRAINERS bring their best-raised\n"
	.string "POKéMON for elimination-style matches.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket: @ 823D808
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard: @ 823D842
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo: @ 823D89D
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

BattleFrontier_OutsideWest_Text_SlateportItIs: @ 823D8F2
	.string "SLATEPORT CITY it is, then!$"

BattleFrontier_OutsideWest_Text_LilycoveItIs: @ 823D90E
	.string "LILYCOVE CITY it is, then!$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime: @ 823D929
	.string "Please sail with us another time!$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry: @ 823D94B
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo: @ 823D97A
	.string "Then, where would you like to go?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends: @ 823D99C
	.string "I'm the best out of all my friends.\n"
	.string "But here…\l"
	.string "I've been useless!$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower: @ 823D9DD
	.string "I want to go to the BATTLE TOWER,\n"
	.string "but I can't find it even though I have\l"
	.string "a map of the BATTLE FRONTIER.\p"
	.string "This place is just too big!$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere: @ 823DA60
	.string "I wanted to take a challenge as soon\n"
	.string "as I arrived here.\p"
	.string "But on the way, I got seasick…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere: @ 823DABF
	.string "It's not as if just anyone can come\n"
	.string "here, you know?\p"
	.string "Only those TRAINERS who've been\n"
	.string "recognized as tough are brought here.\p"
	.string "That's why many TRAINERS don't even\n"
	.string "know about the BATTLE FRONTIER.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons: @ 823DB7D
	.string "Hey, bro…\p"
	.string "Are you sure we can make challenges\n"
	.string "even if we don't have any POKéMON?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons: @ 823DBCE
	.string "Uh…\n"
	.string "I'm sure it'll be okay.\p"
	.string "I think…\p"
	.string "But remember that big scary guy?\n"
	.string "He said, “I'll lend you POKéMON!”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons: @ 823DC36
	.string "That's the BATTLE FACTORY.\n"
	.string "You can rent strong POKéMON there.\p"
	.string "But it makes me wonder.\n"
	.string "Who's raising those rental POKéMON?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper: @ 823DCB0
	.string "I'm scared of going into the BATTLE\n"
	.string "PIKE because of SEVIPER…\p"
	.string "B-but I came all the way here, so I will\n"
	.string "try to conquer everything!\l"
	.string "…Shudder…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors: @ 823DD3B
	.string "Let's play rock, paper, scissors!\n"
	.string "One, two, three!\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge: @ 823DD7A
	.string "Yay! I won!\n"
	.string "I will take the BATTLE PIKE challenge!$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge: @ 823DDAD
	.string "Oh, no…\n"
	.string "I lost.\p"
	.string "I guess I'm not very lucky today.\n"
	.string "I'll put off my BATTLE PIKE challenge\l"
	.string "until tomorrow.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling: @ 823DE15
	.string "I believe I'm the only person here who,\n"
	.string "for some unknown reason, would choose\l"
	.string "fishing over battling.\p"
	.string "Huh? You can't catch anything here?\n"
	.string "That's disappointing…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol: @ 823DEB4
	.string "Today, I'm going to keep battling, no\n"
	.string "matter what, until I get a Symbol.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome: @ 823DEFD
	.string "Oh? You're off to challenge\n"
	.string "the BATTLE DOME?\p"
	.string "I'll wish you the best of luck.\n"
	.string "Let us both win our way up and meet\l"
	.string "in challenges.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa: @ 823DF7D
	.string "Grandpa, over here!\n"
	.string "The BATTLE DOME is here!\l"
	.string "Go get 'em, Grandpa!$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe: @ 823DFBF
	.string "Ah, so this here is the BATTLE DOME?\n"
	.string "I won't let GENTLEMEN beat me!\p"
	.string "But where is the entrance?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo: @ 823E01E
	.string "There used to be nothing here not all\n"
	.string "that long ago.\p"
	.string "But, now look at this place! Amazing!\n"
	.string "I'll bring my mother out to see this.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier: @ 823E09F
	.string "I've finally arrived at the BATTLE\n"
	.string "FRONTIER!\p"
	.string "I'm sure to grab attention with\n"
	.string "my looks and ability!$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople: @ 823E102
	.string "Munch, munch…\p"
	.string "It looks like this square's filled with\n"
	.string "tough people.\p"
	.string "Munch, munch…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike: @ 823E154
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

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet: @ 823E273
	.string "Huh? Will you listen to yourself?\n"
	.string "That's nothing!\p"
	.string "Why, the last time I cheered for him,\n"
	.string "our eyes met and sparks flew!$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering: @ 823E2E9
	.string "Whaaaaaat?!\n"
	.string "Pfft!\p"
	.string "That only happened because\n"
	.string "I happened to be sitting next to you!\p"
	.string "The DOME ACE only looked our way\n"
	.string "because my cheering was so loud!$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine: @ 823E37E
	.string "Oh, shush!\n"
	.string "Keep that racket down!\p"
	.string "You fair-weather fans should stick\n"
	.string "to cheering for some GYM LEADER!\p"
	.string "The DOME ACE is mine!\n"
	.string "The only idol for me!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers: @ 823E410
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

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier: @ 823E5A5
	.string "I heard a rumor that someone saw\n"
	.string "a POKéMON with an unusually long tail\l"
	.string "somewhere in the BATTLE FRONTIER.\p"
	.string "It must be adorable. I'm sure of it…\p"
	.string "Oh, challenges can wait. I feel driven\n"
	.string "to find the delightful creature!$"

