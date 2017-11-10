BattleFrontier_Lounge5_MapScripts:: @ 82645C5
	.byte 0

BattleFrontier_Lounge5_EventScript_2645C6:: @ 82645C6
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_264632, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_Lounge5_EventScript_26460D
	special sub_81B94B0
	waitstate
	lock
	faceplayer
	compare_var_to_value VAR_0x8004, 255
	goto_eq BattleFrontier_Lounge5_EventScript_26460D
	specialvar VAR_RESULT, sub_81396E0
	compare_var_to_value VAR_RESULT, 412
	goto_eq BattleFrontier_Lounge5_EventScript_264603
	special sub_813A7B8
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_264603:: @ 8264603
	msgbox BattleFrontier_Lounge5_Text_264EEE, 4
	release
	end

BattleFrontier_Lounge5_EventScript_26460D:: @ 826460D
	msgbox BattleFrontier_Lounge5_Text_26467F, 4
	release
	end

BattleFrontier_Lounge5_EventScript_264617:: @ 8264617
	msgbox BattleFrontier_Lounge5_Text_264F22, 2
	end

BattleFrontier_Lounge5_EventScript_264620:: @ 8264620
	msgbox BattleFrontier_Lounge5_Text_264F64, 2
	end

BattleFrontier_Lounge5_EventScript_264629:: @ 8264629
	msgbox BattleFrontier_Lounge5_Text_264FAB, 2
	end

BattleFrontier_Lounge5_Text_264632: @ 8264632
	.string "Ehehe!\n"
	.string "I can tell what POKéMON are thinking!\p"
	.string "Please!\n"
	.string "Can I see your POKéMON?$"

BattleFrontier_Lounge5_Text_26467F: @ 826467F
	.string "Boo!\n"
	.string "Cheapie!$"

	.incbin "baserom.gba", 0x26468d, 0x861

BattleFrontier_Lounge5_Text_264EEE: @ 8264EEE
	.string "That’s silly! An EGG is asleep!\n"
	.string "I can’t talk to it!$"

BattleFrontier_Lounge5_Text_264F22: @ 8264F22
	.string "How charming!\n"
	.string "That little lady claims she can\l"
	.string "understand POKéMON!$"

BattleFrontier_Lounge5_Text_264F64: @ 8264F64
	.string "I have this feeling that the little girl\n"
	.string "is saying something profound.$"

BattleFrontier_Lounge5_Text_264FAB: @ 8264FAB
	.string "I know something!\p"
	.string "That little girl plays at the red house\n"
	.string "a lot!$"

