Route12_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	end

Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_MonSprawledOutInSlumber::
	.string "A POKéMON is sprawled out in\n"
	.string "a deep and comfortable slumber.$"

Text_SnorlaxWokeUp::
	.string "SNORLAX woke up!\p"
	.string "It attacked in a grumpy rage!$"

Text_SnorlaxReturnedToMountains::
	.string "SNORLAX calmed down.\n"
	.string "It gave a huge yawn…\l"
	.string "And returned to the mountains.$"

Text_WantToUsePokeFlute::
	.string "Want to use the POKé FLUTE?$"

Text_PlayedPokeFlute::
	.string "{PLAYER} played the POKé FLUTE.$"

Route12_Text_NedIntro::
	.string "Yeah!\n"
	.string "I got a bite here!$"

Route12_Text_NedDefeat::
	.string "Tch!\n"
	.string "Just a small fry…$"

Route12_Text_NedPostBattle::
	.string "Hang on!\n"
	.string "My line's snagged!$"

Route12_Text_ChipIntro::
	.string "Be patient.\n"
	.string "Fishing is a waiting game.$"

Route12_Text_ChipDefeat::
	.string "That one got away!$"

Route12_Text_ChipPostBattle::
	.string "With a better ROD, I could catch\n"
	.string "better POKéMON…$"

Route12_Text_JustinIntro::
	.string "I'm searching for a MOON STONE.\n"
	.string "Have you found one?$"

Route12_Text_JustinDefeat::
	.string "Oww!$"

Route12_Text_JustinPostBattle::
	.string "I could have made my POKéMON\n"
	.string "evolve with a MOON STONE.\p"
	.string "I would have won then, I bet.$"

Route12_Text_LucaIntro::
	.string "Electricity is my specialty.\p"
	.string "I don't know a thing about POKéMON\n"
	.string "of the sea, though.$"

Route12_Text_LucaDefeat::
	.string "Unplugged!$"

Route12_Text_LucaPostBattle::
	.string "Water conducts electricity, so you\n"
	.string "should zap sea POKéMON.$"

Route12_Text_HankIntro::
	.string "The FISHING FOOL versus POKéMON\n"
	.string "KID!$"

Route12_Text_HankDefeat::
	.string "Touch too much!$"

Route12_Text_HankPostBattle::
	.string "I guess you get to be good at\n"
	.string "what you like.\p"
	.string "Well, you beat me at POKéMON,\n"
	.string "but you can't top me at fishing.$"

Route12_Text_ElliotIntro::
	.string "I love fishing, don't get me wrong.\p"
	.string "But it'd be best if I also had more\n"
	.string "work.$"

Route12_Text_ElliotDefeat::
	.string "It's not easy…$"

Route12_Text_ElliotPostBattle::
	.string "It's all right.\n"
	.string "Losing doesn't bug me anymore.$"

Route12_Text_AndrewIntro::
	.string "What's catching?\p"
	.string "You never know what you could\n"
	.string "catch!$"

Route12_Text_AndrewDefeat::
	.string "Lost it!$"

Route12_Text_AndrewPostBattle::
	.string "What, MAGIKARP?\p"
	.string "I catch them all the time, sure.\n"
	.string "But, boy are they wimpy.$"

Route12_Text_RouteSign::
	.string "ROUTE 12 \n"
	.string "North to LAVENDER$"

Route12_Text_SportfishingArea::
	.string "SPORTFISHING AREA$"

Route12_Text_JesIntro::
	.string "JES: If I win, I'm going to\n"
	.string "propose to GIA.$"

Route12_Text_JesDefeat::
	.string "JES: Oh, please, why couldn't you\n"
	.string "let us win?$"

Route12_Text_JesPostBattle::
	.string "JES: Oh, GIA, forgive me,\n"
	.string "my love!$"

Route12_Text_JesNotEnoughMons::
	.string "JES: GIA and I, we'll be\n"
	.string "together forever.\p"
	.string "We won't battle unless you have\n"
	.string "two POKéMON of your own.$"

Route12_Text_GiaIntro::
	.string "GIA: Hey, JES…\p"
	.string "If we win, I'll marry you!$"

Route12_Text_GiaDefeat::
	.string "GIA: Oh, but why?$"

Route12_Text_GiaPostBattle::
	.string "GIA: JES, you silly!\n"
	.string "You ruined this!$"

Route12_Text_GiaNotEnoughMons::
	.string "GIA: I can't bear to battle\n"
	.string "without my JES!\p"
	.string "Don't you have one more POKéMON?$"
