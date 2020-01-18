SlateportCity_PokemonFanClub_MapScripts:: @ 8209E95
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman:: @ 8209E96
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment:: @ 8209ED2
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon:: @ 8209EE5
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	compare VAR_TEMP_2, CONTEST_CATEGORIES_COUNT
	call_if_eq SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	compare VAR_SLATEPORT_FAN_CLUB_STATE, 2
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves:: @ 8209F3B
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon:: @ 8209F45
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname 0
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves:: @ 8209FCA
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf:: @ 8209FD0
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions:: @ 8209FD6
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf:: @ 8209FE0
	checkitemspace ITEM_RED_SCARF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf:: @ 820A011
	checkitemspace ITEM_BLUE_SCARF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf:: @ 820A042
	checkitemspace ITEM_PINK_SCARF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf:: @ 820A073
	checkitemspace ITEM_GREEN_SCARF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf:: @ 820A0A4
	checkitemspace ITEM_YELLOW_SCARF, 1
	compare VAR_RESULT, FALSE
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf:: @ 820A0D5
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool:: @ 820A0DF
	specialvar VAR_RESULT, CheckLeadMonCool
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool:: @ 820A0F0
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty:: @ 820A0F6
	specialvar VAR_RESULT, CheckLeadMonBeauty
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty:: @ 820A107
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute:: @ 820A10D
	specialvar VAR_RESULT, CheckLeadMonCute
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute:: @ 820A11E
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart:: @ 820A124
	specialvar VAR_RESULT, CheckLeadMonSmart
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart:: @ 820A135
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough:: @ 820A13B
	specialvar VAR_RESULT, CheckLeadMonTough
	compare VAR_RESULT, TRUE
	call_if_eq SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough:: @ 820A14C
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest:: @ 820A152
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest:: @ 820A168
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman:: @ 820A172
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman:: @ 820A17E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	compare VAR_RESULT, 4
	goto_if_ge SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell:: @ 820A1A3
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell:: @ 820A1DE
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man:: @ 820A1E8
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin:: @ 820A1F1
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty:: @ 820A1FA
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon:: @ 820A20D
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill:: @ 820A220
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 0
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman: @ 820A233
	.string "Er-hem! I am the CHAIRMAN of the\n"
	.string "POKéMON FAN CLUB!\p"
	.string "Being the CHAIRMAN, I am naturally\n"
	.string "the most important!\p"
	.string "No one can best me when it comes\n"
	.string "to raising POKéMON. No one!\p"
	.string "Well, let me tell you about\n"
	.string "POKéMON CONTESTS.\p"
	.string "They're events where one can show off\n"
	.string "POKéMON for the world to see!\p"
	.string "However, they're held in far-off towns,\n"
	.string "so I cannot participate often enough.\p"
	.string "That is why we gather here to show\n"
	.string "off our POKéMON, and have others\l"
	.string "show us theirs.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon: @ 820A3EE
	.string "The POKéMON of a TRAINER who has\n"
	.string "entered a POKéMON CONTEST…\l"
	.string "That, I would like to see.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon: @ 820A445
	.string "Er-hem! I see you've participated in\n"
	.string "a POKéMON CONTEST!\p"
	.string "Please! Allow me to examine how you\n"
	.string "have raised your POKéMON.\p"
	.string "It delights me no end to see POKéMON\n"
	.string "raised by other TRAINERS.\p"
	.string "The happy expressions of POKéMON\n"
	.string "raised with proper care…\p"
	.string "The kindly eyes of the TRAINER that\n"
	.string "nurtured and raised the POKéMON…\p"
	.string "The very thought fills my heart to\n"
	.string "overwhelming with joy.\p"
	.string "Oh! I do beg your pardon!\n"
	.string "Forgive me for prattling on so!\p"
	.string "Please! Allow me to examine how much\n"
	.string "your POKéMON has grown!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing: @ 820A62A
	.string "How is your POKéMON growing?\n"
	.string "Allow me to examine it.$"

SlateportCity_PokemonFanClub_Text_HmHmISee: @ 820A65F
	.string "Hm, hm…\n"
	.string "I see…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks: @ 820A66E
	.string "Hmmm… It's not bad, but it's not\n"
	.string "good, either…\p"
	.string "You, the TRAINER, must put more\n"
	.string "effort into raising this POKéMON!\p"
	.string "For instance, may I suggest that\n"
	.string "you give it more {POKEBLOCK}S?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward: @ 820A719
	.string "Oh, my…\p"
	.string "Your POKéMON is growing quite well,\n"
	.string "so you deserve a reward.\p"
	.string "Unfortunately, you have no space for\n"
	.string "this in your BAG.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis: @ 820A795
	.string "Your {STR_VAR_1}, it is growing in\n"
	.string "a most impressive manner!\l"
	.string "It is one fine specimen!\p"
	.string "But! If you were to give it this,\n"
	.string "it would grow even better! Indeed!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf: @ 820A827
	.string "Let a POKéMON hold that RED SCARF.\p"
	.string "Everyone will recognize the coolness\n"
	.string "of that POKéMON!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf: @ 820A880
	.string "Let a POKéMON hold that BLUE SCARF.\p"
	.string "Its beauty will be accentuated much\n"
	.string "more than now!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf: @ 820A8D7
	.string "Let a POKéMON hold that PINK SCARF.\p"
	.string "It will draw out the cuteness of\n"
	.string "the POKéMON some more!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf: @ 820A933
	.string "Let a POKéMON hold that GREEN SCARF.\p"
	.string "That will enhance the\n"
	.string "smartness of POKéMON!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf: @ 820A984
	.string "Let a POKéMON hold that YELLOW SCARF.\p"
	.string "It will bolster your POKéMON's\n"
	.string "toughness so much more!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou: @ 820A9E1
	.string "I'm sorry, but I've nothing else to\n"
	.string "give you! None at all!\p"
	.string "After all, you're blessed with the gift\n"
	.string "of raising POKéMON without resorting\l"
	.string "to any items!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou: @ 820AA77
	.string "I love seeing POKéMON that love\n"
	.string "their TRAINERS.\p"
	.string "POKéMON are very sensitive to\n"
	.string "the feelings of their TRAINERS.\p"
	.string "If you treat your POKéMON with love\n"
	.string "and care, they'll love you back.\p"
	.string "When your POKéMON grow to love you,\n"
	.string "please come show me.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou: @ 820AB63
	.string "Your POKéMON really adores you.\p"
	.string "For you, a most compassionate\n"
	.string "TRAINER, a gift from the FAN CLUB!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove: @ 820ABC4
	.string "POKéMON are very sensitive to\n"
	.string "the feelings of their TRAINERS.\p"
	.string "If you treat your POKéMON with love\n"
	.string "and care, they'll love you back.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting: @ 820AC47
	.string "If you keep letting a POKéMON faint\n"
	.string "in battle, it'll come to resent it.\p"
	.string "Soon, it will become less trusting\n"
	.string "of the TRAINER.\p"
	.string "In other words, it certainly won't\n"
	.string "like you very much.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein: @ 820ACF9
	.string "Do POKéMON enjoy having items used\n"
	.string "on them?\p"
	.string "Mine acted really happy when I gave\n"
	.string "it some PROTEIN.$"

SlateportCity_PokemonFanClub_Text_Skitty: @ 820AD5A
	.string "SKITTY: Fffnyaaaah…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon: @ 820AD6E
	.string "ZIGZAGOON: Kyuuu…$"

SlateportCity_PokemonFanClub_Text_Azumarill: @ 820AD80
	.string "AZUMARILL: Marimari?$"

