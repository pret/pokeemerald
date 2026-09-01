CeruleanCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

CeruleanCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CITY
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
	end

CeruleanCity_EventScript_BlockExits::
	setobjectxyperm LOCALID_CERULEAN_POLICEMAN, 30, 12
	setobjectxyperm LOCALID_CERULEAN_SLOWBRO, 26, 31
	setobjectxyperm LOCALID_CERULEAN_LASS, 27, 31
	return

CeruleanCity_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 23, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 24, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_Rival::
	textcolor NPC_TEXT_COLOR_MALE
	setvar VAR_MAP_SCENE_ROUTE22, 2
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_CERULEAN_RIVAL
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalEnter
	waitmovement 0
	msgbox CeruleanCity_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_RIVAL
	call_if_eq VAR_STARTER_MON, 2, CeruleanCity_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, CeruleanCity_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, CeruleanCity_EventScript_RivalCharmander
	famechecker FAMECHECKER_BILL, 0
	msgbox CeruleanCity_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	setflag FLAG_GOT_FAME_CHECKER
	giveitem ITEM_FAME_CHECKER
	msgbox CeruleanCity_Text_ExplainFameCheckerSmellYa
	closemessage
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_CERULEAN_RIVAL
	releaseall
	end

CeruleanCity_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalStartExit::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExit
	waitmovement 0
	return

CeruleanCity_EventScript_RivalStartExitRight::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExitRight
	waitmovement 0
	return

CeruleanCity_Movement_PlayerWatchRivalExit::
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_PlayerWatchRivalExitRight::
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_RivalEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_RivalStartExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalStartExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalExit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_Grunt::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
	message CeruleanCity_Text_GruntIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_GruntDefeated::
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM
	checkitemspace ITEM_TM28
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
	giveitem_msg CeruleanCity_Text_RecoveredTM28FromGrunt, ITEM_TM28
	msgbox CeruleanCity_Text_BetterGetMovingBye
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_CERULEAN_GRUNT
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_GOT_TM28_FROM_ROCKET
	release
	end

CeruleanCity_EventScript_NoRoomForTM28::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_MakeRoomForThisCantRun
	release
	end

CeruleanCity_EventScript_GruntTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_GruntIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_GRUNT
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_PeopleHereWereRobbed
	closemessage
	applymovement LOCALID_CERULEAN_POLICEMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree
	release
	end

CeruleanCity_EventScript_LittleBoySlowbroMoved::
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees
	release
	end

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
	end

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
	end

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_EventScript_Woman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_WantBrightRedBicycle
	closemessage
	applymovement LOCALID_CERULEAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_Lass::
	lock
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroCommand1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroCommand2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroCommand3
	waitmessage
	delay 40
	playse SE_PIN
	applymovement LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroFailed1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroFailed2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroFailed3
	release
	end

CeruleanCity_EventScript_SlowbroCommand1::
	message CeruleanCity_Text_SlowbroUseSonicboom
	return

CeruleanCity_EventScript_SlowbroCommand2::
	message CeruleanCity_Text_SlowbroPunch
	return

CeruleanCity_EventScript_SlowbroCommand3::
	message CeruleanCity_Text_SlowbroWithdraw
	return

CeruleanCity_EventScript_SlowbroFailed1::
	msgbox CeruleanCity_Text_SlowbroPayAttention
	return

CeruleanCity_EventScript_SlowbroFailed2::
	msgbox CeruleanCity_Text_NoYouBlewItAgain
	return

CeruleanCity_EventScript_SlowbroFailed3::
	msgbox CeruleanCity_Text_HardToControlMonsObedience
	return

CeruleanCity_EventScript_Slowbro::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroText1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroText2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroText3
	call_if_eq VAR_0x8008, 3, CeruleanCity_EventScript_SlowbroText4
	release
	end

CeruleanCity_EventScript_SlowbroText1::
	msgbox CeruleanCity_Text_SlowbroTookSnooze
	return

CeruleanCity_EventScript_SlowbroText2::
	msgbox CeruleanCity_Text_SlowbroLoafingAround
	return

CeruleanCity_EventScript_SlowbroText3::
	msgbox CeruleanCity_Text_SlowbroTurnedAway
	return

CeruleanCity_EventScript_SlowbroText4::
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders
	return

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_MISTY, 0
	msgbox CeruleanCity_Text_GymSign
	releaseall
	end

CeruleanCity_Text_RivalIntro::
	.string "{RIVAL}: Yo! {PLAYER}!\p"
	.string "You're still struggling along back\n"
	.string "here?\p"
	.string "I'm doing great! I caught a bunch\n"
	.string "of strong and smart POKéMON!\p"
	.string "Here, let me see what you caught,\n"
	.string "{PLAYER}!$"

CeruleanCity_Text_RivalDefeat::
	.string "Hey!\n"
	.string "Take it easy!\l"
	.string "You won already!$"

CeruleanCity_Text_RivalPostBattle::
	.string "{RIVAL}: Hey, guess what?\p"
	.string "I went to BILL's and got him to\n"
	.string "show me his rare POKéMON.\p"
	.string "That added a lot of pages to my\n"
	.string "POKéDEX!\p"
	.string "After all, BILL's world famous as a\n"
	.string "POKéMANIAC.\p"
	.string "He invented the POKéMON Storage\n"
	.string "System on PC, too.\p"
	.string "Since you're using his system,\n"
	.string "you should go thank him.\p"
	.string "Well, I better get rolling!\n"
	.string "Smell ya later!$"

CeruleanCity_Text_OhRightLittlePresentAsFavor::
	.string "Oh, yeah, right.\p"
	.string "I feel sorry for you. No, really.\n"
	.string "You're always plodding behind me.\p"
	.string "So here, I'll give you a little\n"
	.string "present as a favor.$"

CeruleanCity_Text_ExplainFameCheckerSmellYa::
	.string "A chatty gossip like you…\n"
	.string "That thing's perfect.\p"
	.string "I don't need it because I don't\n"
	.string "give a hoot about others.\p"
	.string "All right, this time I really am\n"
	.string "gone. Smell ya!$"

CeruleanCity_Text_GruntIntro::
	.string "Hey! Stay out!\n"
	.string "It's not your yard!\p"
	.string "…Huh?\n"
	.string "Me?\p"
	.string "I'm an innocent bystander!\n"
	.string "Don't you believe me?{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"

CeruleanCity_Text_GruntDefeat::
	.string "GRUNT: Stop! I give up!\n"
	.string "I'll leave quietly!$"

CeruleanCity_Text_OkayIllReturnStolenTM::
	.string "…Okay.\n"
	.string "I'll return the TM I stole.$"

CeruleanCity_Text_RecoveredTM28FromGrunt::
	.string "{PLAYER} recovered TM28 from\n"
	.string "the TEAM ROCKET GRUNT.$"

CeruleanCity_Text_BetterGetMovingBye::
	.string "I better get moving!\n"
	.string "Bye!$"

CeruleanCity_Text_MakeRoomForThisCantRun::
	.string "Make room for this!\n"
	.string "I can't run until I give it to you!$"

CeruleanCity_Text_TrainerLifeIsToughIsntIt::
	.string "You're a TRAINER, too?\p"
	.string "Collecting, battling…\n"
	.string "It's a tough life, isn't it?$"

CeruleanCity_Text_YouCanCutDownSmallTrees::
	.string "Did you know that you can CUT down\n"
	.string "small trees?\p"
	.string "Even that small tree in front of\n"
	.string "the shop can be CUT down.\p"
	.string "I think there's a way around it,\n"
	.string "though.$"

CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree::
	.string "If that SLOWBRO wasn't there, you\n"
	.string "could CUT down the small tree.\p"
	.string "That way, you could get to the\n"
	.string "other side.\p"
	.string "I think there's a way around it,\n"
	.string "though.$"

CeruleanCity_Text_PokemonEncyclopediaAmusing::
	.string "You're making an encyclopedia on\n"
	.string "POKéMON? That sounds amusing.$"

CeruleanCity_Text_PeopleHereWereRobbed::
	.string "The people here were robbed.\p"
	.string "It's obvious that TEAM ROCKET is\n"
	.string "behind this most heinous crime!\p"
	.string "Even our POLICE FORCE has\n"
	.string "trouble with the ROCKETS!$"

CeruleanCity_Text_SlowbroUseSonicboom::
	.string "Okay! SLOWBRO!\n"
	.string "Use SONICBOOM!$"

CeruleanCity_Text_SlowbroPayAttention::
	.string "Come on, SLOWBRO, pay attention!$"

CeruleanCity_Text_SlowbroPunch::
	.string "SLOWBRO, punch!$"

CeruleanCity_Text_NoYouBlewItAgain::
	.string "No!\n"
	.string "You blew it again!$"

CeruleanCity_Text_SlowbroWithdraw::
	.string "SLOWBRO, WITHDRAW!$"

CeruleanCity_Text_HardToControlMonsObedience::
	.string "No! That's wrong!\n"
	.string "It's so hard to control POKéMON!\p"
	.string "Your POKéMON's obedience depends\n"
	.string "on your abilities as a TRAINER.$"

CeruleanCity_Text_SlowbroTookSnooze::
	.string "SLOWBRO took a snooze…$"

CeruleanCity_Text_SlowbroLoafingAround::
	.string "SLOWBRO is loafing around…$"

CeruleanCity_Text_SlowbroTurnedAway::
	.string "SLOWBRO turned away…$"

CeruleanCity_Text_SlowbroIgnoredOrders::
	.string "SLOWBRO ignored orders…$"

CeruleanCity_Text_WantBrightRedBicycle::
	.string "I want a bright red bicycle.\p"
	.string "I'll keep it at home, so it won't\n"
	.string "get dirty.$"

CeruleanCity_Text_ThisIsCeruleanCave::
	.string "This is CERULEAN CAVE.\p"
	.string "Horribly strong POKéMON live inside\n"
	.string "there.\p"
	.string "It takes a very special TRAINER to\n"
	.string "be allowed inside there.\p"
	.string "You'd have to be strong enough to\n"
	.string "become the POKéMON LEAGUE\l"
	.string "CHAMPION for starters.\p"
	.string "And, you would have to have\n"
	.string "made a great achievement.$"

CeruleanCity_Text_CitySign::
	.string "CERULEAN CITY\n"
	.string "A Mysterious, Blue Aura Surrounds\l"
	.string "It$"

CeruleanCity_Text_TrainerTipsHeldItems::
	.string "TRAINER TIPS\p"
	.string "A POKéMON can be made to hold\n"
	.string "an item.\p"
	.string "Some items can even be used by\n"
	.string "the holding POKéMON in battle.$"

CeruleanCity_Text_BikeShopSign::
	.string "Grass and caves handled easily!\n"
	.string "BIKE SHOP$"

CeruleanCity_Text_GymSign::
	.string "CERULEAN CITY POKéMON GYM\n"
	.string "LEADER: MISTY\l"
	.string "The Tomboyish Mermaid!$"

