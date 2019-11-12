BattleFrontier_Lounge1_MapScripts:: @ 825E774
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder:: @ 825E775
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder:: @ 825E792
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_ne BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	compare VAR_0x8004, 255
	goto_if_eq BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro:: @ 825E7AD
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder:: @ 825E7B6
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder:: @ 825E7BF
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	compare VAR_0x8005, 90   @ Average of 15
	goto_if_le BattleFrontier_Lounge1_EventScript_AverageTotalIVs
	compare VAR_0x8005, 120  @ Average of 20
	goto_if_le BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs
	compare VAR_0x8005, 150  @ Average of 25
	goto_if_le BattleFrontier_Lounge1_EventScript_HighTotalIVs
	compare VAR_0x8005, 151  @ Average of > 25
	goto_if_ge BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder:: @ 825E7FF
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat:: @ 825E80D
	compare VAR_0x8006, STAT_HP
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVHP
	compare VAR_0x8006, STAT_ATK
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVAtk
	compare VAR_0x8006, STAT_DEF
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVDef
	compare VAR_0x8006, STAT_SPEED
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	compare VAR_0x8006, STAT_SPATK
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	compare VAR_0x8006, STAT_SPDEF
	goto_if_eq BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue:: @ 825E850
	compare VAR_0x8007, 15
	goto_if_le BattleFrontier_Lounge1_EventScript_HighestIVLow
	compare VAR_0x8007, 25
	goto_if_le BattleFrontier_Lounge1_EventScript_HighestIVMid
	compare VAR_0x8007, 30
	goto_if_le BattleFrontier_Lounge1_EventScript_HighestIVHigh
	compare VAR_0x8007, 31
	goto_if_ge BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments:: @ 825E87D
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs:: @ 825E87F
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs:: @ 825E88D
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs:: @ 825E89B
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs:: @ 825E8A9
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP:: @ 825E8B7
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk:: @ 825E8C5
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef:: @ 825E8D3
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed:: @ 825E8E1
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk:: @ 825E8EF
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef:: @ 825E8FD
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow:: @ 825E90B
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid:: @ 825E919
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh:: @ 825E927
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax:: @ 825E935
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect:: @ 825E943
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1:: @ 825E94D
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2:: @ 825E956
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro: @ 825E95F
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

BattleFrontier_Lounge1_Text_AverageAbility: @ 825EA92
	.string "…Hmm…\p"
	.string "This one, overall, I would describe\n"
	.string "as being of average ability.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility: @ 825EAD9
	.string "…Hmm…\p"
	.string "This one, overall, I would describe as\n"
	.string "having better-than-average ability.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility: @ 825EB2A
	.string "…Hmm…\p"
	.string "This one, overall, I would say is\n"
	.string "quite impressive in ability!$"

BattleFrontier_Lounge1_Text_OutstandingAbility: @ 825EB6F
	.string "…Hmm…\p"
	.string "This one, overall, I would say is\n"
	.string "wonderfully outstanding in ability!$"

BattleFrontier_Lounge1_Text_BestAspectHP: @ 825EBBB
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its HP…$"

BattleFrontier_Lounge1_Text_BestAspectAtk: @ 825EBF8
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its ATTACK…$"

BattleFrontier_Lounge1_Text_BestAspectDef: @ 825EC39
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its DEFENSE…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk: @ 825EC7B
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPECIAL ATTACK…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef: @ 825ECC4
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPECIAL DEFENSE…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed: @ 825ED0E
	.string "Incidentally, the best aspect of it,\n"
	.string "I would say, is its SPEED…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood: @ 825ED4E
	.string "That stat is relatively good.\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_StatImpressive: @ 825ED87
	.string "That stat is quite impressive.\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_StatOutstanding: @ 825EDC1
	.string "That stat is outstanding!\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_StatFlawless: @ 825EDF6
	.string "It's flawless! A thing of perfection!\n"
	.string "…Hm… That's how I call it.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice: @ 825EE37
	.string "What?\n"
	.string "You have no time for my advice?\p"
	.string "You should always be eager to learn\n"
	.string "from the experiences of your elders!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending: @ 825EEA6
	.string "Yes, what is it now?\p"
	.string "I have business that needs tending!\n"
	.string "Save it for next time!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon: @ 825EEF6
	.string "Ah, youngster! Do your POKéMON's\n"
	.string "abilities intrigue you?\p"
	.string "Here, here!\n"
	.string "Let's have a look at your POKéMON!$"

BattleFrontier_Lounge1_Text_EvenICantTell: @ 825EF5E
	.string "An expert I am, but even I can't tell\n"
	.string "anything about an unhatched POKéMON!\p"
	.string "Show me a POKéMON!\n"
	.string "A POKéMON is what I need to see!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding: @ 825EFDD
	.string "He said my POKéMON is outstanding!\n"
	.string "I'm glad I raised it carefully!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt: @ 825F020
	.string "He said my POKéMON is outstanding!\n"
	.string "But I didn't do anything special\l"
	.string "raising it…$"

