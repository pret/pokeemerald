ViridianForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_FriendsItchingToBattle::
	.string "I came here with some friends to\n"
	.string "catch us some BUG POKéMON!\p"
	.string "They're all itching to get into\n"
	.string "some POKéMON battles!$"

ViridianForest_Text_RickIntro::
	.string "Hey! You have POKéMON!\n"
	.string "Come on!\l"
	.string "Let's battle 'em!$"

ViridianForest_Text_RickDefeat::
	.string "No!\nCATERPIE can't hack it!$"

ViridianForest_Text_RickPostBattle::
	.string "Ssh! You'll scare the bugs away.\n"
	.string "Another time, okay?$"

ViridianForest_Text_DougIntro::
	.string "Yo!\n"
	.string "You can't jam out if you're a\l"
	.string "POKéMON TRAINER!$"

ViridianForest_Text_DougDefeat::
	.string "Huh?\n"
	.string "I ran out of POKéMON!$"

ViridianForest_Text_DougPostBattle::
	.string "That totally stinks! I'm going to\n"
	.string "catch some stronger ones!$"

ViridianForest_Text_SammyIntro::
	.string "Hey, wait up!\n"
	.string "What's the hurry? Why the rush?$"

ViridianForest_Text_SammyDefeat::
	.string "I give!\n"
	.string "You're good at this!$"

ViridianForest_Text_SammyPostBattle::
	.string "Sometimes, you can find stuff on\n"
	.string "the ground.\p"
	.string "I'm looking for the stuff I\n"
	.string "dropped. Can you help me?$"

ViridianForest_Text_AnthonyIntro::
	.string "I might be little, but I won't like\n"
	.string "it if you go easy on me!$"

ViridianForest_Text_AnthonyDefeat::
	.string "Oh, boo.\n"
	.string "Nothing went right.$"

ViridianForest_Text_AnthonyPostBattle::
	.string "I lost some of my allowance…$"

ViridianForest_Text_CharlieIntro::
	.string "Did you know that POKéMON evolve?$"

ViridianForest_Text_CharlieDefeat::
	.string "Oh!\n"
	.string "I lost!$"

ViridianForest_Text_CharliePostBattle::
	.string "BUG POKéMON evolve quickly.\n"
	.string "They're a lot of fun!$"

ViridianForest_Text_RanOutOfPokeBalls::
	.string "I was throwing POKé BALLS to\n"
	.string "catch POKéMON, and I ran out.\p"
	.string "That's why you can never have too\n"
	.string "many POKé BALLS.$"

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
	.string "TRAINER TIPS\p"
	.string "If your POKéMON are weak and you\n"
	.string "want to avoid battles, stay away\l"
	.string "from grassy areas!$"

ViridianForest_Text_UseAntidoteForPoison::
	.string "For poison, use ANTIDOTE!\n"
	.string "Get it at POKéMON MARTS!$"

ViridianForest_Text_ContactOakViaPCToRatePokedex::
	.string "TRAINER TIPS\p"
	.string "Contact PROF. OAK via a PC to\n"
	.string "get your POKéDEX evaluated!$"

ViridianForest_Text_CantCatchOwnedMons::
	.string "TRAINER TIPS\p"
	.string "You can't catch a POKéMON that\n"
	.string "belongs to someone else.\p"
	.string "Throw POKé BALLS only at wild\n"
	.string "POKéMON to catch them!$"

ViridianForest_Text_WeakenMonsBeforeCapture::
	.string "TRAINER TIPS\p"
	.string "Weaken POKéMON before attempting\n"
	.string "capture!\p"
	.string "When healthy, they may escape!$"

ViridianForest_Text_LeavingViridianForest::
	.string "LEAVING VIRIDIAN FOREST\n"
	.string "PEWTER CITY AHEAD$"

