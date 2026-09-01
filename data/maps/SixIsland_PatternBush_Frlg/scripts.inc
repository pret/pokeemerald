SixIsland_PatternBush_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_PatternBush_OnTransition
	.byte 0

SixIsland_PatternBush_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_PATTERN_BUSH
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_ge VAR_TEMP_1, 50, SixIsland_PatternBush_EventScript_SetEscapeRightExit
	call_if_le VAR_TEMP_1, 49, SixIsland_PatternBush_EventScript_SetEscapeLeftExit
	end

SixIsland_PatternBush_EventScript_SetEscapeRightExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 64, 10
	return

SixIsland_PatternBush_EventScript_SetEscapeLeftExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 45, 10
	return

SixIsland_PatternBush_EventScript_Bethany::
	trainerbattle_single TRAINER_PKMN_BREEDER_BETHANY, SixIsland_PatternBush_Text_BethanyIntro, SixIsland_PatternBush_Text_BethanyDefeat
	msgbox SixIsland_PatternBush_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Allison::
	trainerbattle_single TRAINER_PKMN_BREEDER_ALLISON, SixIsland_PatternBush_Text_AllisonIntro, SixIsland_PatternBush_Text_AllisonDefeat
	msgbox SixIsland_PatternBush_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Garret::
	trainerbattle_single TRAINER_BUG_CATCHER_GARRET, SixIsland_PatternBush_Text_GarretIntro, SixIsland_PatternBush_Text_GarretDefeat
	msgbox SixIsland_PatternBush_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Jonah::
	trainerbattle_single TRAINER_BUG_CATCHER_JONAH, SixIsland_PatternBush_Text_JonahIntro, SixIsland_PatternBush_Text_JonahDefeat
	msgbox SixIsland_PatternBush_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Vance::
	trainerbattle_single TRAINER_BUG_CATCHER_VANCE, SixIsland_PatternBush_Text_VanceIntro, SixIsland_PatternBush_Text_VanceDefeat
	msgbox SixIsland_PatternBush_Text_VancePostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Nash::
	trainerbattle_single TRAINER_YOUNGSTER_NASH, SixIsland_PatternBush_Text_NashIntro, SixIsland_PatternBush_Text_NashDefeat
	msgbox SixIsland_PatternBush_Text_NashPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Cordell::
	trainerbattle_single TRAINER_YOUNGSTER_CORDELL, SixIsland_PatternBush_Text_CordellIntro, SixIsland_PatternBush_Text_CordellDefeat
	msgbox SixIsland_PatternBush_Text_CordellPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Dalia::
	trainerbattle_single TRAINER_LASS_DALIA, SixIsland_PatternBush_Text_DaliaIntro, SixIsland_PatternBush_Text_DaliaDefeat
	msgbox SixIsland_PatternBush_Text_DaliaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Joana::
	trainerbattle_single TRAINER_LASS_JOANA, SixIsland_PatternBush_Text_JoanaIntro, SixIsland_PatternBush_Text_JoanaDefeat
	msgbox SixIsland_PatternBush_Text_JoanaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Riley::
	trainerbattle_single TRAINER_CAMPER_RILEY, SixIsland_PatternBush_Text_RileyIntro, SixIsland_PatternBush_Text_RileyDefeat
	msgbox SixIsland_PatternBush_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Marcy::
	trainerbattle_single TRAINER_PICNICKER_MARCY, SixIsland_PatternBush_Text_MarcyIntro, SixIsland_PatternBush_Text_MarcyDefeat
	msgbox SixIsland_PatternBush_Text_MarcyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Layton::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAYTON, SixIsland_PatternBush_Text_LaytonIntro, SixIsland_PatternBush_Text_LaytonDefeat
	msgbox SixIsland_PatternBush_Text_LaytonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_Text_BethanyIntro::
	.string "I'm curious, how do you raise your\n"
	.string "POKéMON?$"

SixIsland_PatternBush_Text_BethanyDefeat::
	.string "You raise your POKéMON with a\n"
	.string "whole lot of love!$"

SixIsland_PatternBush_Text_BethanyPostBattle::
	.string "In the same way your mother raised\n"
	.string "you full of love, you should raise\l"
	.string "your POKéMON.$"

SixIsland_PatternBush_Text_AllisonIntro::
	.string "I'm working to preserve the natural\n"
	.string "ecology of POKéMON here.$"

SixIsland_PatternBush_Text_AllisonDefeat::
	.string "Oh, for someone so young, you are\n"
	.string "tremendous!$"

SixIsland_PatternBush_Text_AllisonPostBattle::
	.string "I'm not saying that you shouldn't\n"
	.string "catch POKéMON.\p"
	.string "I just want people to raise their\n"
	.string "POKéMON responsibly.$"

SixIsland_PatternBush_Text_GarretIntro::
	.string "I caught a BUG POKéMON that lives\n"
	.string "only around here!$"

SixIsland_PatternBush_Text_GarretDefeat::
	.string "Heheh…\n"
	.string "Isn't my POKéMON awesome?$"

SixIsland_PatternBush_Text_GarretPostBattle::
	.string "There's a girl near the BUSH who\n"
	.string "measures HERACROSS for TRAINERS.$"

SixIsland_PatternBush_Text_JonahIntro::
	.string "You know, it just doesn't feel right\n"
	.string "if I don't use BUG POKéMON.$"

SixIsland_PatternBush_Text_JonahDefeat::
	.string "It's okay, losing is a fun part of\n"
	.string "POKéMON's appeal, too.$"

SixIsland_PatternBush_Text_JonahPostBattle::
	.string "By the way, “appeal” is a weird\n"
	.string "word, if you think about it.\p"
	.string "Like, is it like an orange peel?\n"
	.string "Or like a ringing bell?$"

SixIsland_PatternBush_Text_VanceIntro::
	.string "Yeah, yeah, yeah!\n"
	.string "Look at all the BUG POKéMON!$"

SixIsland_PatternBush_Text_VanceDefeat::
	.string "I got beat while I was still busy\n"
	.string "celebrating!$"

SixIsland_PatternBush_Text_VancePostBattle::
	.string "I'm going to bring my little brother\n"
	.string "here next time.$"

SixIsland_PatternBush_Text_NashIntro::
	.string "Look, look! There are funny\n"
	.string "patterns on the ground.$"

SixIsland_PatternBush_Text_NashDefeat::
	.string "Super awesome!$"

SixIsland_PatternBush_Text_NashPostBattle::
	.string "The funny patterns on the ground…\p"
	.string "They look like the patterns on my\n"
	.string "grandpa's clothes.$"

SixIsland_PatternBush_Text_CordellIntro::
	.string "I bet you think I'm just some guy,\n"
	.string "don't you, eh?$"

SixIsland_PatternBush_Text_CordellDefeat::
	.string "I bet you think I'm weak,\n"
	.string "don't you, eh?$"

SixIsland_PatternBush_Text_CordellPostBattle::
	.string "Ayup, you townies come around all\n"
	.string "so dandy with a hat that flashy…\p"
	.string "How about giving me that?$"

SixIsland_PatternBush_Text_DaliaIntro::
	.string "Take a deep breath.\n"
	.string "Isn't the air delicious?$"

SixIsland_PatternBush_Text_DaliaDefeat::
	.string "If you'd like, I can teach you how\n"
	.string "to breathe properly.$"

SixIsland_PatternBush_Text_DaliaPostBattle::
	.string "First, exhale.\n"
	.string "Blow everything out.\p"
	.string "When you can't exhale anymore,\n"
	.string "inhale the clean air!\p"
	.string "Isn't it refreshing?$"

SixIsland_PatternBush_Text_JoanaIntro::
	.string "I love BUG POKéMON.\n"
	.string "That's why I'm here all the time.\p"
	.string "Am I the only girl like that?$"

SixIsland_PatternBush_Text_JoanaDefeat::
	.string "I lost, but I'm still laughing.\n"
	.string "Am I the only girl like that?$"

SixIsland_PatternBush_Text_JoanaPostBattle::
	.string "I'm going to keep on collecting\n"
	.string "BUG POKéMON.\p"
	.string "Am I the only girl like that?$"

SixIsland_PatternBush_Text_RileyIntro::
	.string "This is a good spot.\n"
	.string "I'll pitch my tent here.$"

SixIsland_PatternBush_Text_RileyDefeat::
	.string "Wimped out…$"

SixIsland_PatternBush_Text_RileyPostBattle::
	.string "I'm going to observe the night sky\n"
	.string "here.$"

SixIsland_PatternBush_Text_MarcyIntro::
	.string "Oh, yuck!\n"
	.string "I think a bug stung me!$"

SixIsland_PatternBush_Text_MarcyDefeat::
	.string "It wasn't a bug.\n"
	.string "I cut my shin on some grass.$"

SixIsland_PatternBush_Text_MarcyPostBattle::
	.string "A little cut like that…\n"
	.string "A little spit's enough to cure it!$"

SixIsland_PatternBush_Text_LaytonIntro::
	.string "Have you noticed something odd\n"
	.string "about these parts?$"

SixIsland_PatternBush_Text_LaytonDefeat::
	.string "Have you taken a good look around\n"
	.string "your feet?$"

SixIsland_PatternBush_Text_LaytonPostBattle::
	.string "There are places here in PATTERN\n"
	.string "BUSH where grass won't grow.\p"
	.string "What could be the cause of such\n"
	.string "a phenomenon?$"

