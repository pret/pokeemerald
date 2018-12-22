BattleFrontier_Lounge5_MapScripts:: @ 82645C5
	.byte 0

BattleFrontier_Lounge5_EventScript_2645C6:: @ 82645C6
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_264632, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq BattleFrontier_Lounge5_EventScript_26460D
	special sub_81B94B0
	waitstate
	lock
	faceplayer
	compare VAR_0x8004, 255
	goto_if_eq BattleFrontier_Lounge5_EventScript_26460D
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, 412
	goto_if_eq BattleFrontier_Lounge5_EventScript_264603
	special sub_813A7B8
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_264603:: @ 8264603
	msgbox BattleFrontier_Lounge5_Text_264EEE, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_26460D:: @ 826460D
	msgbox BattleFrontier_Lounge5_Text_26467F, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_264617:: @ 8264617
	msgbox BattleFrontier_Lounge5_Text_264F22, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_264620:: @ 8264620
	msgbox BattleFrontier_Lounge5_Text_264F64, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_264629:: @ 8264629
	msgbox BattleFrontier_Lounge5_Text_264FAB, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_264632:: @ 8264632
	.string "Ehehe!\n"
	.string "I can tell what POKéMON are thinking!\p"
	.string "Please!\n"
	.string "Can I see your POKéMON?$"

BattleFrontier_Lounge5_Text_26467F:: @ 826467F
	.string "Boo!\n"
	.string "Cheapie!$"

BattleFrontier_Lounge5_Text_26468D:: @ 826468D
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"

BattleFrontier_Lounge5_Text_2646E5:: @ 82646E5
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_264741:: @ 8264741
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_2647A4:: @ 82647A4
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"

BattleFrontier_Lounge5_Text_2647FC:: @ 82647FC
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_264858:: @ 8264858
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_2648BE:: @ 82648BE
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"

BattleFrontier_Lounge5_Text_264916:: @ 8264916
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_264972:: @ 8264972
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_2649D5:: @ 82649D5
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_264A3F:: @ 8264A3F
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_264A9B:: @ 8264A9B
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"

BattleFrontier_Lounge5_Text_264AF3:: @ 8264AF3
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_264B5D:: @ 8264B5D
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_264BC3:: @ 8264BC3
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself whether\l"
	.string "or not it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_264C36:: @ 8264C36
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_264C95:: @ 8264C95
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_264D01:: @ 8264D01
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_264D6B:: @ 8264D6B
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_264DD7:: @ 8264DD7
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_264E33:: @ 8264E33
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_264E8F:: @ 8264E8F
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_264EEE:: @ 8264EEE
	.string "That's silly! An EGG is asleep!\n"
	.string "I can't talk to it!$"

BattleFrontier_Lounge5_Text_264F22:: @ 8264F22
	.string "How charming!\n"
	.string "That little lady claims she can\l"
	.string "understand POKéMON!$"

BattleFrontier_Lounge5_Text_264F64:: @ 8264F64
	.string "I have this feeling that the little girl\n"
	.string "is saying something profound.$"

BattleFrontier_Lounge5_Text_264FAB:: @ 8264FAB
	.string "I know something!\p"
	.string "That little girl plays at the red house\n"
	.string "a lot!$"

