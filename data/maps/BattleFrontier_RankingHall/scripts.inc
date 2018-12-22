BattleFrontier_RankingHall_MapScripts:: @ 825E4A9
	.byte 0

BattleFrontier_RankingHall_EventScript_25E4AA:: @ 825E4AA
	lockall
	setvar VAR_0x8005, 0
	goto BattleFrontier_RankingHall_EventScript_25E522
	end

BattleFrontier_RankingHall_EventScript_25E4B6:: @ 825E4B6
	lockall
	setvar VAR_0x8005, 1
	goto BattleFrontier_RankingHall_EventScript_25E522
	end

BattleFrontier_RankingHall_EventScript_25E4C2:: @ 825E4C2
	lockall
	setvar VAR_0x8005, 2
	goto BattleFrontier_RankingHall_EventScript_25E522
	end

BattleFrontier_RankingHall_EventScript_25E4CE:: @ 825E4CE
	lockall
	setvar VAR_0x8005, 9
	goto BattleFrontier_RankingHall_EventScript_25E522
	end

BattleFrontier_RankingHall_EventScript_25E4DA:: @ 825E4DA
	lockall
	setvar VAR_0x8005, 5
	goto BattleFrontier_RankingHall_EventScript_25E522
	end

BattleFrontier_RankingHall_EventScript_25E4E6:: @ 825E4E6
	lockall
	setvar VAR_0x8005, 4
	goto BattleFrontier_RankingHall_EventScript_25E522
	end

BattleFrontier_RankingHall_EventScript_25E4F2:: @ 825E4F2
	lockall
	setvar VAR_0x8005, 6
	goto BattleFrontier_RankingHall_EventScript_25E522
	end

BattleFrontier_RankingHall_EventScript_25E4FE:: @ 825E4FE
	lockall
	setvar VAR_0x8005, 3
	goto BattleFrontier_RankingHall_EventScript_25E522
	end

BattleFrontier_RankingHall_EventScript_25E50A:: @ 825E50A
	lockall
	setvar VAR_0x8005, 7
	goto BattleFrontier_RankingHall_EventScript_25E522
	end

BattleFrontier_RankingHall_EventScript_25E516:: @ 825E516
	lockall
	setvar VAR_0x8005, 8
	goto BattleFrontier_RankingHall_EventScript_25E522
	end

BattleFrontier_RankingHall_EventScript_25E522:: @ 825E522
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_25E52F:: @ 825E52F
	msgbox BattleFrontier_RankingHall_Text_25E57C, MSGBOX_NPC
	end

BattleFrontier_RankingHall_EventScript_25E538:: @ 825E538
	msgbox BattleFrontier_RankingHall_Text_25E5F9, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_25E541:: @ 825E541
	msgbox BattleFrontier_RankingHall_Text_25E62E, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_25E54A:: @ 825E54A
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_25E666, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_RankingHall_EventScript_25E569
	msgbox BattleFrontier_RankingHall_Text_25E6B6, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_25E569:: @ 825E569
	msgbox BattleFrontier_RankingHall_Text_25E685, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_25E573:: @ 825E573
	msgbox BattleFrontier_RankingHall_Text_25E715, MSGBOX_NPC
	end

BattleFrontier_RankingHall_Text_25E57C: @ 825E57C
	.string "This is the RANKING HALL.\p"
	.string "This is where we recognize the immortal\n"
	.string "TRAINERS who left great records in\l"
	.string "BATTLE FRONTIER events.$"

BattleFrontier_RankingHall_Text_25E5F9: @ 825E5F9
	.string "BATTLE DOME, BATTLE PIKE,\n"
	.string "and BATTLE FACTORY Records$"

BattleFrontier_RankingHall_Text_25E62E: @ 825E62E
	.string "BATTLE PALACE, BATTLE ARENA,\n"
	.string "and BATTLE PYRAMID Records$"

BattleFrontier_RankingHall_Text_25E666: @ 825E666
	.string "Hi, is your name on this list?$"

BattleFrontier_RankingHall_Text_25E685: @ 825E685
	.string "Wow, that's super!\n"
	.string "I'll have to try harder, too!$"

BattleFrontier_RankingHall_Text_25E6B6: @ 825E6B6
	.string "Oh, is that right?\p"
	.string "If you saw your friend's name up here,\n"
	.string "I bet it would make you work harder!$"

BattleFrontier_RankingHall_Text_25E715: @ 825E715
	.string "Hmm…\n"
	.string "My name's not up there…\p"
	.string "Well, it's only natural since I haven't\n"
	.string "taken any challenges yet.$"

