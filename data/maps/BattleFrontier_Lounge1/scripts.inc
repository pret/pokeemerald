BattleFrontier_Lounge1_MapScripts:: @ 825E774
	.byte 0

BattleFrontier_Lounge1_EventScript_25E775:: @ 825E775
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_25E7AD
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_25E7B6
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_25E792
	end

BattleFrontier_Lounge1_EventScript_25E792:: @ 825E792
	special sub_81B94B0
	waitstate
	compare VAR_0x8004, 255
	goto_if_ne BattleFrontier_Lounge1_EventScript_25E7BF
	compare VAR_0x8004, 255
	goto_if_eq BattleFrontier_Lounge1_EventScript_25E943
	end

BattleFrontier_Lounge1_EventScript_25E7AD:: @ 825E7AD
	msgbox BattleFrontier_Lounge1_Text_25E95F, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_25E7B6:: @ 825E7B6
	msgbox BattleFrontier_Lounge1_Text_25EEF6, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_25E7BF:: @ 825E7BF
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, 412
	goto_if_eq BattleFrontier_Lounge1_EventScript_25E7FF
	special sub_8139D98
	compare VAR_0x8005, 90
	goto_if_le BattleFrontier_Lounge1_EventScript_25E87F
	compare VAR_0x8005, 120
	goto_if_le BattleFrontier_Lounge1_EventScript_25E88D
	compare VAR_0x8005, 150
	goto_if_le BattleFrontier_Lounge1_EventScript_25E89B
	compare VAR_0x8005, 151
	goto_if_ge BattleFrontier_Lounge1_EventScript_25E8A9
	end

BattleFrontier_Lounge1_EventScript_25E7FF:: @ 825E7FF
	msgbox BattleFrontier_Lounge1_Text_25EF5E, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E792
	end

BattleFrontier_Lounge1_EventScript_25E80D:: @ 825E80D
	compare VAR_0x8006, 0
	goto_if_eq BattleFrontier_Lounge1_EventScript_25E8B7
	compare VAR_0x8006, 1
	goto_if_eq BattleFrontier_Lounge1_EventScript_25E8C5
	compare VAR_0x8006, 2
	goto_if_eq BattleFrontier_Lounge1_EventScript_25E8D3
	compare VAR_0x8006, 3
	goto_if_eq BattleFrontier_Lounge1_EventScript_25E8E1
	compare VAR_0x8006, 4
	goto_if_eq BattleFrontier_Lounge1_EventScript_25E8EF
	compare VAR_0x8006, 5
	goto_if_eq BattleFrontier_Lounge1_EventScript_25E8FD
	end

BattleFrontier_Lounge1_EventScript_25E850:: @ 825E850
	compare VAR_0x8007, 15
	goto_if_le BattleFrontier_Lounge1_EventScript_25E90B
	compare VAR_0x8007, 25
	goto_if_le BattleFrontier_Lounge1_EventScript_25E919
	compare VAR_0x8007, 30
	goto_if_le BattleFrontier_Lounge1_EventScript_25E927
	compare VAR_0x8007, 31
	goto_if_ge BattleFrontier_Lounge1_EventScript_25E935
	end

BattleFrontier_Lounge1_EventScript_25E87D:: @ 825E87D
	release
	end

BattleFrontier_Lounge1_EventScript_25E87F:: @ 825E87F
	msgbox BattleFrontier_Lounge1_Text_25EA92, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E80D
	end

BattleFrontier_Lounge1_EventScript_25E88D:: @ 825E88D
	msgbox BattleFrontier_Lounge1_Text_25EAD9, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E80D
	end

BattleFrontier_Lounge1_EventScript_25E89B:: @ 825E89B
	msgbox BattleFrontier_Lounge1_Text_25EB2A, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E80D
	end

BattleFrontier_Lounge1_EventScript_25E8A9:: @ 825E8A9
	msgbox BattleFrontier_Lounge1_Text_25EB6F, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E80D
	end

BattleFrontier_Lounge1_EventScript_25E8B7:: @ 825E8B7
	msgbox BattleFrontier_Lounge1_Text_25EBBB, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E850
	end

BattleFrontier_Lounge1_EventScript_25E8C5:: @ 825E8C5
	msgbox BattleFrontier_Lounge1_Text_25EBF8, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E850
	end

BattleFrontier_Lounge1_EventScript_25E8D3:: @ 825E8D3
	msgbox BattleFrontier_Lounge1_Text_25EC39, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E850
	end

BattleFrontier_Lounge1_EventScript_25E8E1:: @ 825E8E1
	msgbox BattleFrontier_Lounge1_Text_25ED0E, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E850
	end

BattleFrontier_Lounge1_EventScript_25E8EF:: @ 825E8EF
	msgbox BattleFrontier_Lounge1_Text_25EC7B, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E850
	end

BattleFrontier_Lounge1_EventScript_25E8FD:: @ 825E8FD
	msgbox BattleFrontier_Lounge1_Text_25ECC4, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E850
	end

BattleFrontier_Lounge1_EventScript_25E90B:: @ 825E90B
	msgbox BattleFrontier_Lounge1_Text_25ED4E, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E87D
	end

BattleFrontier_Lounge1_EventScript_25E919:: @ 825E919
	msgbox BattleFrontier_Lounge1_Text_25ED87, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E87D
	end

BattleFrontier_Lounge1_EventScript_25E927:: @ 825E927
	msgbox BattleFrontier_Lounge1_Text_25EDC1, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E87D
	end

BattleFrontier_Lounge1_EventScript_25E935:: @ 825E935
	msgbox BattleFrontier_Lounge1_Text_25EDF6, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_25E87D
	end

BattleFrontier_Lounge1_EventScript_25E943:: @ 825E943
	msgbox BattleFrontier_Lounge1_Text_25EE37, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_25E94D:: @ 825E94D
	msgbox BattleFrontier_Lounge1_Text_25EFDD, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_25E956:: @ 825E956
	msgbox BattleFrontier_Lounge1_Text_25F020, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_25E95F: @ 825E95F
	.string "For 70 years I have raised POKéMON!\n"
	.string "I am the man they revere as\l"
	.string "the legendary top POKéMON BREEDER!\p"
	.string "If you ever become as seasoned as me,\n"
	.string "you'll see the abilities of POKéMON\l"
	.string "at a glance.\p"
	.string "You're a TRAINER. Doesn't it interest\n"
	.string "you to know your own POKéMON's\l"
	.string "abilities?\p"
	.string "Here!\n"
	.string "Let's have a look at your POKéMON!$"

BattleFrontier_Lounge1_Text_25EA92: @ 825EA92
	.string "…Hmm…\p"
	.string "This one, overall, I would describe\n"
	.string "as being of average ability.$"

BattleFrontier_Lounge1_Text_25EAD9: @ 825EAD9
	.string "…Hmm…\p"
	.string "This one, overall, I would describe as\n"
	.string "having better-than-average ability.$"

BattleFrontier_Lounge1_Text_25EB2A: @ 825EB2A
	.string "…Hmm…\p"
	.string "This one, overall, I would say is\n"
	.string "quite impressive in ability!$"

BattleFrontier_Lounge1_Text_25EB6F: @ 825EB6F
	.string "…Hmm…\p"
	.string "This one, overall, I would say is\n"
	.string "wonderfully outstanding in ability!$"

BattleFrontier_Lounge1_Text_25EBBB: @ 825EBBB
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its HP…$"

BattleFrontier_Lounge1_Text_25EBF8: @ 825EBF8
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its ATTACK…$"

BattleFrontier_Lounge1_Text_25EC39: @ 825EC39
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its DEFENSE…$"

BattleFrontier_Lounge1_Text_25EC7B: @ 825EC7B
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPECIAL ATTACK…$"

BattleFrontier_Lounge1_Text_25ECC4: @ 825ECC4
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPECIAL DEFENSE…$"

BattleFrontier_Lounge1_Text_25ED0E: @ 825ED0E
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPEED…$"

BattleFrontier_Lounge1_Text_25ED4E: @ 825ED4E
	.string "That stat is relatively good.\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_25ED87: @ 825ED87
	.string "That stat is quite impressive.\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_25EDC1: @ 825EDC1
	.string "That stat is outstanding!\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_25EDF6: @ 825EDF6
	.string "It's flawless! A thing of perfection!\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_25EE37: @ 825EE37
	.string "What?\n"
	.string "You have no time for my advice?\p"
	.string "You should always be eager to learn\n"
	.string "from the experiences of your elders!$"

BattleFrontier_Lounge1_Text_25EEA6: @ 825EEA6
	.string "Yes, what is it now?\p"
	.string "I have business that needs tending!\n"
	.string "Save it for next time!$"

BattleFrontier_Lounge1_Text_25EEF6: @ 825EEF6
	.string "Ah, youngster! Do your POKéMON's\n"
	.string "abilities intrigue you?\p"
	.string "Here, here!\n"
	.string "Let's have a look at your POKéMON!$"

BattleFrontier_Lounge1_Text_25EF5E: @ 825EF5E
	.string "An expert I am, but even I can't tell\n"
	.string "anything about an unhatched POKéMON!\p"
	.string "Show me a POKéMON!\n"
	.string "A POKéMON is what I need to see!$"

BattleFrontier_Lounge1_Text_25EFDD: @ 825EFDD
	.string "He said my POKéMON is outstanding!\n"
	.string "I'm glad I raised it carefully!$"

BattleFrontier_Lounge1_Text_25F020: @ 825F020
	.string "He said my POKéMON is outstanding!\n"
	.string "But I didn't do anything special\l"
	.string "raising it…$"

