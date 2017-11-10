BattleFrontier_Lounge2_MapScripts:: @ 8260642
	.byte 0

BattleFrontier_Lounge2_EventScript_260643:: @ 8260643
	lock
	faceplayer
	checkflag FLAG_0x154
	goto_eq BattleFrontier_Lounge2_EventScript_26065F
	setflag FLAG_0x154
	msgbox BattleFrontier_Lounge2_Text_260766, 4
	goto BattleFrontier_Lounge2_EventScript_26066D
	end

BattleFrontier_Lounge2_EventScript_26065F:: @ 826065F
	msgbox BattleFrontier_Lounge2_Text_260857, 4
	goto BattleFrontier_Lounge2_EventScript_26066D
	end

BattleFrontier_Lounge2_EventScript_26066D:: @ 826066D
	compare_var_to_value VAR_0x402F, 0
	call_if 1, BattleFrontier_Lounge2_EventScript_26070A
	compare_var_to_value VAR_0x402F, 1
	call_if 1, BattleFrontier_Lounge2_EventScript_26070F
	compare_var_to_value VAR_0x402F, 2
	call_if 1, BattleFrontier_Lounge2_EventScript_260714
	compare_var_to_value VAR_0x402F, 3
	call_if 1, BattleFrontier_Lounge2_EventScript_260719
	compare_var_to_value VAR_0x402F, 4
	call_if 1, BattleFrontier_Lounge2_EventScript_26071E
	compare_var_to_value VAR_0x402F, 5
	call_if 1, BattleFrontier_Lounge2_EventScript_260723
	compare_var_to_value VAR_0x402F, 6
	call_if 1, BattleFrontier_Lounge2_EventScript_260728
	compare_var_to_value VAR_0x402F, 7
	call_if 1, BattleFrontier_Lounge2_EventScript_26072D
	compare_var_to_value VAR_0x402F, 8
	call_if 1, BattleFrontier_Lounge2_EventScript_260732
	compare_var_to_value VAR_0x402F, 9
	call_if 1, BattleFrontier_Lounge2_EventScript_260737
	compare_var_to_value VAR_0x402F, 3
	call_if 3, BattleFrontier_Lounge2_EventScript_2606F8
	compare_var_to_value VAR_0x402F, 4
	call_if 4, BattleFrontier_Lounge2_EventScript_260701
	special sub_8139F20
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_2606F8:: @ 82606F8
	msgbox BattleFrontier_Lounge2_Text_260933, 4
	return

BattleFrontier_Lounge2_EventScript_260701:: @ 8260701
	msgbox BattleFrontier_Lounge2_Text_2608F2, 4
	return

BattleFrontier_Lounge2_EventScript_26070A:: @ 826070A
	bufferstdstring 0, 19
	return

BattleFrontier_Lounge2_EventScript_26070F:: @ 826070F
	bufferstdstring 0, 20
	return

BattleFrontier_Lounge2_EventScript_260714:: @ 8260714
	bufferstdstring 0, 21
	return

BattleFrontier_Lounge2_EventScript_260719:: @ 8260719
	bufferstdstring 0, 22
	return

BattleFrontier_Lounge2_EventScript_26071E:: @ 826071E
	bufferstdstring 0, 24
	return

BattleFrontier_Lounge2_EventScript_260723:: @ 8260723
	bufferstdstring 0, 25
	return

BattleFrontier_Lounge2_EventScript_260728:: @ 8260728
	bufferstdstring 0, 26
	return

BattleFrontier_Lounge2_EventScript_26072D:: @ 826072D
	bufferstdstring 0, 27
	return

BattleFrontier_Lounge2_EventScript_260732:: @ 8260732
	bufferstdstring 0, 28
	return

BattleFrontier_Lounge2_EventScript_260737:: @ 8260737
	bufferstdstring 0, 29
	return

BattleFrontier_Lounge2_EventScript_26073C:: @ 826073C
	lock
	msgbox BattleFrontier_Lounge2_Text_261C9C, 4
	release
	end

BattleFrontier_Lounge2_EventScript_260747:: @ 8260747
	lock
	msgbox BattleFrontier_Lounge2_Text_261CDC, 4
	release
	end

BattleFrontier_Lounge2_EventScript_260752:: @ 8260752
	lock
	msgbox BattleFrontier_Lounge2_Text_261D1D, 4
	release
	end

BattleFrontier_Lounge2_EventScript_26075D:: @ 826075D
	msgbox BattleFrontier_Lounge2_Text_261D5C, 2
	end

BattleFrontier_Lounge2_Text_260766: @ 8260766
	.string "Howdy! When it comes to news about\n"
	.string "the BATTLE FRONTIER, I’m no. 1.\p"
	.string "You can think of me as\n"
	.string "the FRONTIER MANIAC.\p"
	.string "Just checking, but you are a TRAINER,\n"
	.string "isn’t that right?\p"
	.string "I’ll happily share the hottest news\n"
	.string "I gathered about the BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_260857: @ 8260857
	.string "Howdy! Did you swing by to grill me\n"
	.string "about the latest word? Oh, all right!$"

	.incbin "baserom.gba", 0x2608a1, 0x51

BattleFrontier_Lounge2_Text_2608F2: @ 82608F2
	.string "Let’s see now…\p"
	.string "It sounds like the {STR_VAR_1}\n"
	.string "is the hottest place going.$"

BattleFrontier_Lounge2_Text_260933: @ 8260933
	.string "Let’s see now…\p"
	.string "It sounds like BATTLE TOWER\n"
	.string "{STR_VAR_1} is the hottest.$"

	.incbin "baserom.gba", 0x260971, 0x132b

BattleFrontier_Lounge2_Text_261C9C: @ 8261C9C
	.string "What amazing news-gathering power!\n"
	.string "My mentor’s like none other!$"

BattleFrontier_Lounge2_Text_261CDC: @ 8261CDC
	.string "What amazing powers of observation!\n"
	.string "My mentor’s like none other!$"

BattleFrontier_Lounge2_Text_261D1D: @ 8261D1D
	.string "What amazing power of persuasion!\n"
	.string "My mentor’s like none other!$"

BattleFrontier_Lounge2_Text_261D5C: @ 8261D5C
	.string "…What is this place?\n"
	.string "It’s scaring me…$"

