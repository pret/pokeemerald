MtPyre_6F_MapScripts:: @ 8231D3A
	.byte 0

MtPyre_6F_EventScript_231D3B:: @ 8231D3B
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_231DB4, MtPyre_6F_Text_231DE2, MtPyre_6F_EventScript_231D67
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq MtPyre_6F_EventScript_231D86
	msgbox MtPyre_6F_Text_231DFC, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_231D67:: @ 8231D67
	special sub_80B4808
	waitmovement 0
	msgbox MtPyre_6F_Text_231E43, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_231D86:: @ 8231D86
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_231EB3, MtPyre_6F_Text_231ECB
	msgbox MtPyre_6F_Text_231EE1, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_231D9D:: @ 8231D9D
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_231F11, MtPyre_6F_Text_231F4A
	msgbox MtPyre_6F_Text_231F5C, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_231DB4: @ 8231DB4
	.string "When I'm here…\n"
	.string "A curious power flows into me…$"

MtPyre_6F_Text_231DE2: @ 8231DE2
	.string "The power is ebbing away…$"

MtPyre_6F_Text_231DFC: @ 8231DFC
	.string "Perhaps the power is from the spirits\n"
	.string "of POKéMON in fitful sleep here…$"

MtPyre_6F_Text_231E43: @ 8231E43
	.string "Fufufu… I lost the match, but…\n"
	.string "I have this little ability…\p"
	.string "Without ever laying my hands on\n"
	.string "your POKéNAV… Hiyah!$"

MtPyre_6F_Text_231EB3: @ 8231EB3
	.string "Behind you…\n"
	.string "What is it…$"

MtPyre_6F_Text_231ECB: @ 8231ECB
	.string "Something faded away…$"

MtPyre_6F_Text_231EE1: @ 8231EE1
	.string "The POKéMON at rest here…\n"
	.string "Sometimes, they play…$"

MtPyre_6F_Text_231F11: @ 8231F11
	.string "Have you lost your bearings?\n"
	.string "Have no fear for I am here!$"

MtPyre_6F_Text_231F4A: @ 8231F4A
	.string "Weren't you lost?$"

MtPyre_6F_Text_231F5C: @ 8231F5C
	.string "I had this feeling that a lost TRAINER\n"
	.string "would be panicked and easy to beat.\p"
	.string "It's dirty and I won't try it again…$"

