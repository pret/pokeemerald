MauvilleCity_PokemonCenter_1F_EventScript_28E066:: @ 828E066
	special ScrSpecial_GetCurrentMauvilleMan
	switch VAR_RESULT
	case 0, MauvilleCity_PokemonCenter_1F_EventScript_28E0A6
	case 1, MauvilleCity_PokemonCenter_1F_EventScript_28E167
	case 2, MauvilleCity_PokemonCenter_1F_EventScript_28E4D4
	case 3, MauvilleCity_PokemonCenter_1F_EventScript_29014A
	case 4, MauvilleCity_PokemonCenter_1F_EventScript_2902F6
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E0A6:: @ 828E0A6
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_29038E, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E0C7
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E0EA
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E0C7:: @ 828E0C7
	setvar VAR_0x8004, 0
	special ScrSpecial_PlayBardSong
	delay 60
	special ScrSpecial_HasBardSongBeenChanged
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E0F4
	msgbox MauvilleCity_PokemonCenter_1F_Text_2903E6, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E0EA:: @ 828E0EA
	msgbox MauvilleCity_PokemonCenter_1F_Text_2903C0, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E0F4:: @ 828E0F4
	msgbox MauvilleCity_PokemonCenter_1F_Text_290421, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E113
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E15D
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E113:: @ 828E113
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E15D
	msgbox MauvilleCity_PokemonCenter_1F_Text_2904C1, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special ScrSpecial_PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_2904EB, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E113
	special ScrSpecial_SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_290514, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E15D:: @ 828E15D
	msgbox MauvilleCity_PokemonCenter_1F_Text_29049B, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E167:: @ 828E167
	lock
	faceplayer
	setflag FLAG_SYS_HIPSTER_MEET
	msgbox MauvilleCity_PokemonCenter_1F_Text_29054C, MSGBOX_DEFAULT
	special ScrSpecial_GetHipsterSpokenFlag
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E18C
	msgbox MauvilleCity_PokemonCenter_1F_Text_290598, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E18C:: @ 828E18C
	special ScrSpecial_HipsterTeachWord
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E1A4
	msgbox MauvilleCity_PokemonCenter_1F_Text_290602, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E1A4:: @ 828E1A4
	msgbox MauvilleCity_PokemonCenter_1F_Text_290666, MSGBOX_DEFAULT
	special ScrSpecial_SetHipsterSpokenFlag
	release
	end

MauvilleCity_PokemonCenter_1F_Text_28E1B1: @ 828E1B1
	.string "Hi, I'm the TRADER.\n"
	.string "Want to trade decorations with me?$"

MauvilleCity_PokemonCenter_1F_Text_28E1E8: @ 828E1E8
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_28E20E: @ 828E20E
	.string "But we've traded decorations already,\n"
	.string "you and I.$"

MauvilleCity_PokemonCenter_1F_Text_28E23F: @ 828E23F
	.string "If you see any decorative item that\n"
	.string "you want of mine, speak up.$"

MauvilleCity_PokemonCenter_1F_Text_28E27F: @ 828E27F
	.string "You don't want anything?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_28E2A9: @ 828E2A9
	.string "That decorative item once belonged\n"
	.string "to {STR_VAR_1}.\p"
	.string "Do you want it?$"

MauvilleCity_PokemonCenter_1F_Text_28E2E3: @ 828E2E3
	.string "Uh… Wait a second. You don't have a\n"
	.string "single piece of decoration!$"

MauvilleCity_PokemonCenter_1F_Text_28E323: @ 828E323
	.string "Okay, pick the decoration that you'll\n"
	.string "trade to me.$"

MauvilleCity_PokemonCenter_1F_Text_28E356: @ 828E356
	.string "You won't trade with me?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_28E380: @ 828E380
	.string "You've got all the {STR_VAR_2}S that can\n"
	.string "be stored. You've no room for this.$"

MauvilleCity_PokemonCenter_1F_Text_28E3C4: @ 828E3C4
	.string "Okay, so we'll trade my {STR_VAR_3}\n"
	.string "for your {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_28E3EC: @ 828E3EC
	.string "That piece of decoration is in use.\n"
	.string "You can't trade it.$"

MauvilleCity_PokemonCenter_1F_Text_28E424: @ 828E424
	.string "Then we'll trade!\n"
	.string "I'll send my decoration to your PC.$"

MauvilleCity_PokemonCenter_1F_Text_28E45A: @ 828E45A
	.string "Oops! Sorry! That's a really rare\n"
	.string "piece of decoration.\l"
	.string "I can't trade that one away!\p"
	.string "Can I interest you in something else?$"

MauvilleCity_PokemonCenter_1F_EventScript_28E4D4:: @ 828E4D4
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E1B1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E503
	special ScrSpecial_GetTraderTradedFlag
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E50D
	message MauvilleCity_PokemonCenter_1F_Text_28E23F
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E517
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E503:: @ 828E503
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E1E8, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E50D:: @ 828E50D
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E20E, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E517:: @ 828E517
	special ScrSpecial_TraderMenuGetDecoration
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E558
	compare VAR_0x8004, 65535
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E562
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E2A9, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E56E
	special ScrSpecial_DoesPlayerHaveNoDecorations
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E57A
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E584
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E558:: @ 828E558
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E27F, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E562:: @ 828E562
	message MauvilleCity_PokemonCenter_1F_Text_28E45A
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E517
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E56E:: @ 828E56E
	message MauvilleCity_PokemonCenter_1F_Text_28E23F
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E517
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E57A:: @ 828E57A
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E2E3, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E584:: @ 828E584
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E323, MSGBOX_DEFAULT
	special ScrSpecial_TraderMenuGiveDecoration
	waitstate
	compare VAR_0x8006, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E5D4
	compare VAR_0x8006, 65535
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E5DE
	special ScrSpecial_IsDecorationFull
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E5EC
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E3C4, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_28E584
	special ScrSpecial_TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E424, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E5D4:: @ 828E5D4
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E356, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E5DE:: @ 828E5DE
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E3EC, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E584
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E5EC:: @ 828E5EC
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E380, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_28E5F6: @ 828E5F6
	.string "I'm the STORYTELLER.\n"
	.string "I'll tell you tales of legendary\l"
	.string "TRAINERS.\p"
	.string "Will you hear my tale?$"

MauvilleCity_PokemonCenter_1F_Text_28E64D: @ 828E64D
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_28E673: @ 828E673
	.string "I know of these legends.\n"
	.string "Which tale will you have me tell?$"

MauvilleCity_PokemonCenter_1F_Text_28E6AE: @ 828E6AE
	.string "But, I know of no legendary TRAINERS.\n"
	.string "Hence, I know no tales.\p"
	.string "Where does one find a TRAINER worthy\n"
	.string "of a legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_28E726: @ 828E726
	.string "What's that?!\n"
	.string "You… You…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} time(s)?!\p"
	.string "That is indeed magnificent!\n"
	.string "It's the birth of a new legend!$"

MauvilleCity_PokemonCenter_1F_Text_28E78A: @ 828E78A
	.string "It gets me thinking, could there be\n"
	.string "other TRAINERS with more impressive\l"
	.string "legends awaiting discovery?$"

MauvilleCity_PokemonCenter_1F_Text_28E7EE: @ 828E7EE
	.string "Are you a TRAINER?\p"
	.string "Then tell me, have you any tales that\n"
	.string "are even remotely legendary?$"

MauvilleCity_PokemonCenter_1F_Text_28E844: @ 828E844
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_28E881: @ 828E881
	.string "Hmm…\n"
	.string "I'm not satisfied…\p"
	.string "I wish you would bring me news worthy\n"
	.string "of being called a legend.$"

MauvilleCity_PokemonCenter_1F_Text_28E8D9: @ 828E8D9
	.string "I wish more people would be interested\n"
	.string "in hearing my epic tales of legendary\l"
	.string "TRAINERS.$"

MauvilleCity_PokemonCenter_1F_Text_28E930:: @ 828E930
	.string "The Save-Happy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28E947:: @ 828E947
	.string "Saved the game$"

MauvilleCity_PokemonCenter_1F_Text_28E956:: @ 828E956
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER saved the game\n"
	.string "{STR_VAR_1} times!\p"
	.string "A more cautious TRAINER than\n"
	.string "{STR_VAR_3} one will never find!$"

MauvilleCity_PokemonCenter_1F_Text_28E9D7:: @ 828E9D7
	.string "The Trendsetter TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28E9EF:: @ 828E9EF
	.string "Started trends$"

MauvilleCity_PokemonCenter_1F_Text_28E9FE:: @ 828E9FE
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER started new trends\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is setting trends for all\n"
	.string "the HOENN region!$"

MauvilleCity_PokemonCenter_1F_Text_28EA7D:: @ 828EA7D
    .string "The BERRY-Planting TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28EA98:: @ 828EA98
	.string "Planted BERRIES$"

MauvilleCity_PokemonCenter_1F_Text_28EAA8:: @ 828EAA8
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER planted BERRIES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a legendary lover of\n"
	.string "BERRIES!$"

MauvilleCity_PokemonCenter_1F_Text_28EB19:: @ 828EB19
	.string "The BIKE-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28EB31:: @ 828EB31
	.string "Traded BIKES$"

MauvilleCity_PokemonCenter_1F_Text_28EB3E:: @ 828EB3E
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER swapped BIKES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love BIKES deeply\n"
	.string "and passionately!$"

MauvilleCity_PokemonCenter_1F_Text_28EBB5:: @ 828EBB5
	.string "The Interviewed TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28EBCD:: @ 828EBCD
	.string "Got interviewed$"

MauvilleCity_PokemonCenter_1F_Text_28EBDD:: @ 828EBDD
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER got interviewed\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who's\n"
	.string "attracting much attention!$"

MauvilleCity_PokemonCenter_1F_Text_28EC60:: @ 828EC60
	.string "The Battle-Happy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28EC79:: @ 828EC79
	.string "Battled$"

MauvilleCity_PokemonCenter_1F_Text_28EC81:: @ 828EC81
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER battled {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who can\n"
	.string "never refuse a chance to battle!$"

MauvilleCity_PokemonCenter_1F_Text_28ED04:: @ 828ED04
	.string "The POKéMON-Catching TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28ED21:: @ 828ED21
	.string "Caught POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_28ED30:: @ 828ED30
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER caught\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} is a legendary catcher of\n"
	.string "wild POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_28EDA1:: @ 828EDA1
	.string "The Fishing TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28EDB5:: @ 828EDB5
	.string "Caught POKéMON with a ROD$"

MauvilleCity_PokemonCenter_1F_Text_28EDCF:: @ 828EDCF
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER caught\n"
	.string "{STR_VAR_1} POKéMON while fishing!\p"
	.string "{STR_VAR_3} is a legendary fishing\n"
	.string "expert!$"

MauvilleCity_PokemonCenter_1F_Text_28EE45:: @ 828EE45
	.string "The EGG-Warming TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28EE5D:: @ 828EE5D
	.string "Hatched EGGS$"

MauvilleCity_PokemonCenter_1F_Text_28EE6A:: @ 828EE6A
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER hatched {STR_VAR_1} POKéMON\n"
	.string "from EGGS!\p"
	.string "{STR_VAR_3} is a legendary warmer\n"
	.string "of EGGS!$"

MauvilleCity_PokemonCenter_1F_Text_28EEDD:: @ 828EEDD
	.string "The Evolver TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28EEF1:: @ 828EEF1
	.string "Evolved POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_28EF01:: @ 828EF01
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER made {STR_VAR_1} POKéMON\n"
	.string "evolve!\p"
	.string "{STR_VAR_3} is the ultimate evolver\n"
	.string "of POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_28EF73:: @ 828EF73
	.string "The POKéMON CENTER-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28EF95:: @ 828EF95
	.string "Used POKéMON CENTERS$"

MauvilleCity_PokemonCenter_1F_Text_28EFAA:: @ 828EFAA
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER healed POKéMON\n"
	.string "{STR_VAR_1} times at POKéMON CENTERS!\p"
	.string "There could be no greater lover of\n"
	.string "POKéMON CENTERS than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_28F045:: @ 828F045
	.string "The Homebody TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28F05A:: @ 828F05A
	.string "Rested POKéMON at home$"

MauvilleCity_PokemonCenter_1F_Text_28F071:: @ 828F071
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER healed POKéMON\n"
	.string "{STR_VAR_1} times at home!\p"
	.string "There could be no more of a homebody\n"
	.string "than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_28F0F3:: @ 828F0F3
	.string "The SAFARI-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28F10D:: @ 828F10D
	.string "Entered the SAFARI ZONE$"

MauvilleCity_PokemonCenter_1F_Text_28F125:: @ 828F125
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER went into the SAFARI ZONE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER whose wild side\n"
	.string "must come out in the SAFARI ZONE!$"

MauvilleCity_PokemonCenter_1F_Text_28F1BE:: @ 828F1BE
	.string "The CUT-Frenzy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28F1D5:: @ 828F1D5
	.string "Used CUT$"

MauvilleCity_PokemonCenter_1F_Text_28F1DE:: @ 828F1DE
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used CUT\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who just must\n"
	.string "love to CUT!$"

MauvilleCity_PokemonCenter_1F_Text_28F24F:: @ 828F24F
	.string "The ROCK-SMASHING TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28F269:: @ 828F269
	.string "Smashed rocks$"

MauvilleCity_PokemonCenter_1F_Text_28F277:: @ 828F277
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used ROCK SMASH\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who\n"
	.string "can't leave a stone unsmashed!$"

MauvilleCity_PokemonCenter_1F_Text_28F2FC:: @ 828F2FC
	.string "The Move-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28F314:: @ 828F314
	.string "Moved the SECRET BASE$"

MauvilleCity_PokemonCenter_1F_Text_28F32A:: @ 828F32A
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER moved the SECRET BASE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who loves\n"
	.string "to move houses often!$"

MauvilleCity_PokemonCenter_1F_Text_28F3AD:: @ 828F3AD
	.string "The SPLASH-Happy TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28F3C6:: @ 828F3C6
	.string "Used SPLASH$"

MauvilleCity_PokemonCenter_1F_Text_28F3D2:: @ 828F3D2
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used SPLASH\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who must love\n"
	.string "SPLASHING around!$"

MauvilleCity_PokemonCenter_1F_Text_28F44B:: @ 828F44B
	.string "The Tenacious TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28F461:: @ 828F461
	.string "Resorted to using STRUGGLE$"

MauvilleCity_PokemonCenter_1F_Text_28F47C:: @ 828F47C
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER had to rely on STRUGGLE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a tenacious TRAINER\n"
	.string "who never gives in to adversity!$"

MauvilleCity_PokemonCenter_1F_Text_28F50C:: @ 828F50C
	.string "The SLOT Champ$"

MauvilleCity_PokemonCenter_1F_Text_28F51B:: @ 828F51B
	.string "Won the jackpot on the SLOTS$"

MauvilleCity_PokemonCenter_1F_Text_28F538:: @ 828F538
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won the jackpot on\n"
	.string "the SLOTS {STR_VAR_1} times.\p"
	.string "{STR_VAR_3} is a TRAINER who was lucky\n"
	.string "on the SLOTS!$"

MauvilleCity_PokemonCenter_1F_Text_28F5BE:: @ 828F5BE
	.string "The ROULETTE Champ$"

MauvilleCity_PokemonCenter_1F_Text_28F5D1:: @ 828F5D1
	.string "Had consecutive ROULETTE wins of$"

MauvilleCity_PokemonCenter_1F_Text_28F5F2:: @ 828F5F2
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won in ROULETTE\n"
	.string "{STR_VAR_1} times in a row.\p"
	.string "{STR_VAR_3} was lucky when the ball\n"
	.string "bounced in ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_28F678:: @ 828F678
	.string "The BATTLE TOWER Challenger$"

MauvilleCity_PokemonCenter_1F_Text_28F694:: @ 828F694
	.string "Took the BATTLE TOWER challenge$"

MauvilleCity_PokemonCenter_1F_Text_28F6B4:: @ 828F6B4
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER took the BATTLE TOWER\n"
	.string "challenge {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who aspires\n"
	.string "for excellence in the BATTLE TOWER!$"

MauvilleCity_PokemonCenter_1F_Text_28F751:: @ 828F751
	.string "The Blend-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28F76A:: @ 828F76A
	.string "Made {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_28F776:: @ 828F776
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER made {POKEBLOCK}S\n"
	.string "{STR_VAR_1} times!\p"
	.string "There is none better at using a BERRY\n"
	.string "BLENDER than {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_28F7F6:: @ 828F7F6
	.string "The CONTEST-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28F811:: @ 828F811
	.string "Entered CONTESTS$"

MauvilleCity_PokemonCenter_1F_Text_28F822:: @ 828F822
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER entered CONTESTS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love showing off\n"
	.string "POKéMON to others!$"

MauvilleCity_PokemonCenter_1F_Text_28F89C:: @ 828F89C
	.string "The CONTEST Master$"

MauvilleCity_PokemonCenter_1F_Text_28F8AF:: @ 828F8AF
	.string "Won CONTESTS$"

MauvilleCity_PokemonCenter_1F_Text_28F8BC:: @ 828F8BC
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won CONTESTS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be an incredible\n"
	.string "CONTEST master!$"

MauvilleCity_PokemonCenter_1F_Text_28F92F:: @ 828F92F
	.string "The Happy Shopper$"

MauvilleCity_PokemonCenter_1F_Text_28F941:: @ 828F941
	.string "Shopped$"

MauvilleCity_PokemonCenter_1F_Text_28F949:: @ 828F949
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER bought items in shops\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be one of those\n"
	.string "people who are born to shop.$"

MauvilleCity_PokemonCenter_1F_Text_28F9D1:: @ 828F9D1
	.string "The Item-Finding TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28F9EA:: @ 828F9EA
	.string "Used an ITEMFINDER$"

MauvilleCity_PokemonCenter_1F_Text_28F9FD:: @ 828F9FD
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used an ITEMFINDER\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must enjoy scouring the\n"
	.string "ground for hidden items!$"

MauvilleCity_PokemonCenter_1F_Text_28FA81:: @ 828FA81
	.string "The Rain-Soaked TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28FA99:: @ 828FA99
	.string "Got rained on$"

MauvilleCity_PokemonCenter_1F_Text_28FAA7:: @ 828FAA7
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER got soaked by rain\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3}'s charisma must even\n"
	.string "attract rain!$"

MauvilleCity_PokemonCenter_1F_Text_28FB1D:: @ 828FB1D
	.string "The Avid POKéDEX Reader$"

MauvilleCity_PokemonCenter_1F_Text_28FB35:: @ 828FB35
	.string "Checked a POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_28FB47:: @ 828FB47
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER checked a POKéDEX\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love inspecting\n"
	.string "POKéMON in a POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_28FBC4:: @ 828FBC4
	.string "The RIBBON Collector$"

MauvilleCity_PokemonCenter_1F_Text_28FBD9:: @ 828FBD9
	.string "Received RIBBONS$"

MauvilleCity_PokemonCenter_1F_Text_28FBEA:: @ 828FBEA
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER received RIBBONS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who\n"
	.string "loves to collect RIBBONS!$"

MauvilleCity_PokemonCenter_1F_Text_28FC6B:: @ 828FC6B
	.string "The Ledge-Jumping TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28FC85:: @ 828FC85
	.string "Jumped down ledges$"

MauvilleCity_PokemonCenter_1F_Text_28FC98:: @ 828FC98
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER jumped down ledges\n"
	.string "{STR_VAR_1} times!\p"
	.string "If there's a ledge to be jumped,\n"
	.string "{STR_VAR_3} can't ignore it!$"

MauvilleCity_PokemonCenter_1F_Text_28FD1D:: @ 828FD1D
	.string "The Legendary TV Viewer$"

MauvilleCity_PokemonCenter_1F_Text_28FD35:: @ 828FD35
	.string "Watched TV$"

MauvilleCity_PokemonCenter_1F_Text_28FD40:: @ 828FD40
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER watched TV\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love watching TV!$"

MauvilleCity_PokemonCenter_1F_Text_28FDA2:: @ 828FDA2
	.string "The Time-Conscious TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28FDBD:: @ 828FDBD
	.string "Checked the time$"

MauvilleCity_PokemonCenter_1F_Text_28FDCE:: @ 828FDCE
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER checked the time\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a punctual TRAINER\n"
	.string "who's conscious of the time.$"

MauvilleCity_PokemonCenter_1F_Text_28FE57:: @ 828FE57
	.string "The POKéMON LOTTERY Wizard$"

MauvilleCity_PokemonCenter_1F_Text_28FE72:: @ 828FE72
	.string "Won POKéMON LOTTERIES$"

MauvilleCity_PokemonCenter_1F_Text_28FE88:: @ 828FE88
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won POKéMON LOTTERIES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must have many friends\n"
	.string "to trade POKéMON with!$"

MauvilleCity_PokemonCenter_1F_Text_28FF0C:: @ 828FF0C
	.string "The DAY CARE-Using Trainer$"

MauvilleCity_PokemonCenter_1F_Text_28FF27:: @ 828FF27
	.string "Left POKéMON at the DAY CARE$"

MauvilleCity_PokemonCenter_1F_Text_28FF44:: @ 828FF44
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER left POKéMON with the\n"
	.string "DAY CARE {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a real go-getter\n"
	.string "who raises POKéMON aggressively!$"

MauvilleCity_PokemonCenter_1F_Text_28FFDD:: @ 828FFDD
	.string "The CABLE CAR-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_28FFFA:: @ 828FFFA
	.string "Rode the CABLE CAR$"

MauvilleCity_PokemonCenter_1F_Text_29000D:: @ 829000D
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER rode the CABLE CAR\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a busy TRAINER\n"
	.string "who's up and down all the time!$"

MauvilleCity_PokemonCenter_1F_Text_290097:: @ 8290097
	.string "The Hot Spring-Loving TRAINER$"

MauvilleCity_PokemonCenter_1F_Text_2900B5:: @ 82900B5
	.string "Bathed in hot springs$"

MauvilleCity_PokemonCenter_1F_Text_2900CB:: @ 82900CB
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER bathed in hot springs\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER with\n"
	.string "baby-smooth skin!$"


MauvilleCity_PokemonCenter_1F_EventScript_29014A:: @ 829014A
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E5F6, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_290219
	specialvar VAR_RESULT, ScrSpecial_StorytellerGetFreeStorySlot
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_2901DA
	message MauvilleCity_PokemonCenter_1F_Text_28E673
	waitmessage
	special ScrSpecial_StorytellerStoryListMenu
	waitstate
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_2901B7
	setvar VAR_0x8008, 1
	special ScrSpecial_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, ScrSpecial_StorytellerUpdateStat
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_2901BD
	goto MauvilleCity_PokemonCenter_1F_EventScript_29020F

MauvilleCity_PokemonCenter_1F_EventScript_2901B7:: @ 82901B7
	goto MauvilleCity_PokemonCenter_1F_EventScript_290219
	end

MauvilleCity_PokemonCenter_1F_EventScript_2901BD:: @ 82901BD
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E78A, MSGBOX_DEFAULT
	specialvar VAR_RESULT, ScrSpecial_HasStorytellerAlreadyRecorded
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_29022D
	goto MauvilleCity_PokemonCenter_1F_EventScript_2901E2

MauvilleCity_PokemonCenter_1F_EventScript_2901DA:: @ 82901DA
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E6AE, MSGBOX_DEFAULT

MauvilleCity_PokemonCenter_1F_EventScript_2901E2:: @ 82901E2
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E7EE, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_290219
	specialvar VAR_RESULT, ScrSpecial_StorytellerInitializeRandomStat
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_29020F
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E881, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_29020F:: @ 829020F
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E726, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_290219:: @ 8290219
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E64D, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_290223:: @ 8290223
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E8D9, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_29022D:: @ 829022D
	release
	end

MauvilleCity_PokemonCenter_1F_Text_29022F: @ 829022F
	.string "I'm GIDDY!\n"
	.string "I have a scintillating story for you!\p"
	.string "Would you like to hear my story?$"

MauvilleCity_PokemonCenter_1F_Text_290281: @ 8290281
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_2902A7: @ 82902A7
	.string "Also, I was thinking…$"

MauvilleCity_PokemonCenter_1F_Text_2902BD: @ 82902BD
	.string "That's about it, I think…\p"
	.string "We should chat again!\n"
	.string "Bye-bye!$"

MauvilleCity_PokemonCenter_1F_EventScript_2902F6:: @ 82902F6
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_29022F, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_290317
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_29037A
	end

MauvilleCity_PokemonCenter_1F_EventScript_290317:: @ 8290317
	special ScrSpecial_GiddyShouldTellAnotherTale
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_290359
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_290384
	end

MauvilleCity_PokemonCenter_1F_EventScript_290331:: @ 8290331
	special ScrSpecial_GiddyShouldTellAnotherTale
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_29034B
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_290384
	end

MauvilleCity_PokemonCenter_1F_EventScript_29034B:: @ 829034B
	msgbox MauvilleCity_PokemonCenter_1F_Text_2902A7, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_290359
	end

MauvilleCity_PokemonCenter_1F_EventScript_290359:: @ 8290359
	special ScrSpecial_GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	compare VAR_RESULT, 1
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_290331
	compare VAR_RESULT, 0
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_290331
	end

MauvilleCity_PokemonCenter_1F_EventScript_29037A:: @ 829037A
	msgbox MauvilleCity_PokemonCenter_1F_Text_290281, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_290384:: @ 8290384
	msgbox MauvilleCity_PokemonCenter_1F_Text_2902BD, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_29038E: @ 829038E
	.string "Hi, I'm the BARD.\n"
	.string "Would you like to hear my song?$"

MauvilleCity_PokemonCenter_1F_Text_2903C0: @ 82903C0
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_2903E6: @ 82903E6
	.string "Oh, what a moving song…\n"
	.string "I wish I could play it for others…$"

MauvilleCity_PokemonCenter_1F_Text_290421: @ 8290421
	.string "So?\n"
	.string "How do you like my song?\p"
	.string "But I'm none too happy about\n"
	.string "the lyrics.\p"
	.string "How would you like to write some\n"
	.string "new lyrics for me?$"

MauvilleCity_PokemonCenter_1F_Text_29049B: @ 829049B
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_2904C1: @ 82904C1
	.string "Thank you kindly!\n"
	.string "Let me sing it for you.$"

MauvilleCity_PokemonCenter_1F_Text_2904EB: @ 82904EB
	.string "Was that how you wanted your song\n"
	.string "to go?$"

MauvilleCity_PokemonCenter_1F_Text_290514: @ 8290514
	.string "Okay! That's it, then.\n"
	.string "I'll sing this song for a while.$"

MauvilleCity_PokemonCenter_1F_Text_29054C: @ 829054C
	.string "Hey, yo! They call me the HIPSTER.\n"
	.string "I'll teach you what's hip and happening.$"

MauvilleCity_PokemonCenter_1F_Text_290598: @ 8290598
	.string "But, hey, I taught you what's hip and\n"
	.string "happening already.\p"
	.string "I'd like to spread the good word to\n"
	.string "other folks.$"

MauvilleCity_PokemonCenter_1F_Text_290602: @ 8290602
	.string "But, hey, you already know a lot about\n"
	.string "what's hip and happening.\p"
	.string "I've got nothing new to teach you!$"

MauvilleCity_PokemonCenter_1F_Text_290666: @ 8290666
	.string "Hey, have you heard about\n"
	.string "“{STR_VAR_1}”?\p"
	.string "What's it mean? Well…\n"
	.string "Ask your daddy or mommy, okay?$"
