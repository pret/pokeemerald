CeruleanCity_Gym_Frlg_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Misty::
	famechecker FAMECHECKER_MISTY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
	goto_if_unset FLAG_GOT_TM03_FROM_MISTY, CeruleanCity_Gym_EventScript_GiveTM03
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_MistyDefeated::
	famechecker FAMECHECKER_MISTY, 1
	setflag FLAG_DEFEATED_MISTY
	setflag FLAG_BADGE02_GET
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	set_gym_trainers_frlg 2
	goto CeruleanCity_Gym_EventScript_GiveTM03
	end

CeruleanCity_Gym_EventScript_GiveTM03::
	msgbox CeruleanCity_Gym_Text_ExplainCascadeBadge
	checkitemspace ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM03
	giveitem_msg CeruleanCity_Gym_Text_ReceivedTM03FromMisty, ITEM_TM03
	setflag FLAG_GOT_TM03_FROM_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_NoRoomForTM03::
	msgbox CeruleanCity_Gym_Text_BetterMakeRoomForThis
	release
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	famechecker FAMECHECKER_MISTY, 2
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MISTY, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice
	release
	end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam
	release
	end

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanCity_Gym_Text_MistyIntro::
	.string "Hi, you're a new face!\p"
	.string "Only those TRAINERS who have a\n"
	.string "policy about POKéMON can turn pro.\p"
	.string "What is your approach when you\n"
	.string "catch and train POKéMON?\p"
	.string "My policy is an all-out offensive\n"
	.string "with WATER-type POKéMON!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeruleanCity_Gym_Text_ExplainTM03::
	.string "TM03 teaches WATER PULSE.\p"
	.string "Use it on an aquatic POKéMON!$"

CeruleanCity_Gym_Text_ExplainCascadeBadge::
	.string "The CASCADEBADGE makes all\n"
	.string "POKéMON up to Lv. 30 obey.\p"
	.string "That includes even outsiders you\n"
	.string "got in trades.\p"
	.string "There's more. You can now use CUT\n"
	.string "anytime, even out of battle.\p"
	.string "You can CUT down small trees to\n"
	.string "open new pathways.\p"
	.string "You can also have my favorite TM.$"

CeruleanCity_Gym_Text_ReceivedTM03FromMisty::
	.string "{PLAYER} received TM03\n"
	.string "from MISTY.$"

CeruleanCity_Gym_Text_BetterMakeRoomForThis::
	.string "You better make room for this!$"

CeruleanCity_Gym_Text_MistyDefeat::
	.string "Wow!\n"
	.string "You're too much!\p"
	.string "All right!\p"
	.string "You can have the CASCADEBADGE to\n"
	.string "show you beat me.$"

CeruleanCity_Gym_Text_DianaIntro::
	.string "What? You?\n"
	.string "I'm more than good enough for you!\p"
	.string "MISTY won't have to be bothered.$"

CeruleanCity_Gym_Text_DianaDefeat::
	.string "You overwhelmed me!$"

CeruleanCity_Gym_Text_DianaPostBattle::
	.string "You have to face other TRAINERS\n"
	.string "to see how good you really are.$"

CeruleanCity_Gym_Text_LuisIntro::
	.string "Splash!\p"
	.string "I'm first up!\n"
	.string "Let's do it!$"

CeruleanCity_Gym_Text_LuisDefeat::
	.string "That can't be!$"

CeruleanCity_Gym_Text_LuisPostBattle::
	.string "MISTY is a TRAINER who's going to\n"
	.string "keep improving.\p"
	.string "She won't lose to someone like you!$"

CeruleanCity_Gym_Text_GymGuyAdvice::
	.string "Yo!\n"
	.string "Champ in the making!\p"
	.string "Let me give you some advice!\p"
	.string "The LEADER, MISTY, is a pro who\n"
	.string "uses WATER-type POKéMON.\p"
	.string "You can drain all their water with\n"
	.string "GRASS-type POKéMON.\p"
	.string "Or, you might use ELECTRIC-type\n"
	.string "POKéMON and zap them!$"

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
	.string "You beat MISTY!\n"
	.string "See, what'd I tell ya?\p"
	.string "You and me, kid, we make a pretty\n"
	.string "darn-good team!$"

CeruleanCity_Gym_Text_GymStatue::
	.string "CERULEAN POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
	.string "CERULEAN POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"

