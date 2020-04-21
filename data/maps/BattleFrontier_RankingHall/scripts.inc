BattleFrontier_RankingHall_MapScripts:: @ 825E4A9
	.byte 0

BattleFrontier_RankingHall_EventScript_TowerSinglesRecords:: @ 825E4AA
	lockall
	setvar VAR_0x8005, RANKING_HALL_BATTLE_TOWER_SINGLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerDoublesRecords:: @ 825E4B6
	lockall
	setvar VAR_0x8005, RANKING_HALL_BATTLE_TOWER_DOUBLES
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerMultisRecords:: @ 825E4C2
	lockall
	setvar VAR_0x8005, RANKING_HALL_BATTLE_TOWER_MULTIS
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_TowerLinkRecords:: @ 825E4CE
	lockall
	setvar VAR_0x8005, RANKING_HALL_BATTLE_TOWER_LINK
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_ArenaRecords:: @ 825E4DA
	lockall
	setvar VAR_0x8005, RANKING_HALL_BATTLE_ARENA
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PalaceRecords:: @ 825E4E6
	lockall
	setvar VAR_0x8005, RANKING_HALL_BATTLE_PALACE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_FactoryRecords:: @ 825E4F2
	lockall
	setvar VAR_0x8005, RANKING_HALL_BATTLE_FACTORY
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_DomeRecords:: @ 825E4FE
	lockall
	setvar VAR_0x8005, RANKING_HALL_BATTLE_DOME
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PikeRecords:: @ 825E50A
	lockall
	setvar VAR_0x8005, RANKING_HALL_BATTLE_PIKE
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_PyramidRecords:: @ 825E516
	lockall
	setvar VAR_0x8005, RANKING_HALL_BATTLE_PYRAMID
	goto BattleFrontier_RankingHall_EventScript_ShowRecords
	end

BattleFrontier_RankingHall_EventScript_ShowRecords:: @ 825E522
	special ShowRankingHallRecordsWindow
	waitbuttonpress
	special ScrollRankingHallRecordsWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_RankingHall_EventScript_Attendant:: @ 825E52F
	msgbox BattleFrontier_RankingHall_Text_ExplainRankingHall, MSGBOX_NPC
	end

BattleFrontier_RankingHall_EventScript_DomePikeFactoryRecordsSign:: @ 825E538
	msgbox BattleFrontier_RankingHall_Text_DomePikeFactoryRecords, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_PalaceArenaPyramidRecordsSIgn:: @ 825E541
	msgbox BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords, MSGBOX_SIGN
	end

BattleFrontier_RankingHall_EventScript_NinjaBoy:: @ 825E54A
	lock
	faceplayer
	msgbox BattleFrontier_RankingHall_Text_IsYourNameOnThisList, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_RankingHall_EventScript_NinjaBoyNameOnList
	msgbox BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_NinjaBoyNameOnList:: @ 825E569
	msgbox BattleFrontier_RankingHall_Text_WowThatsSuper, MSGBOX_DEFAULT
	release
	end

BattleFrontier_RankingHall_EventScript_Boy:: @ 825E573
	msgbox BattleFrontier_RankingHall_Text_MyNamesNotUpThere, MSGBOX_NPC
	end

BattleFrontier_RankingHall_Text_ExplainRankingHall: @ 825E57C
	.string "This is the RANKING HALL.\p"
	.string "This is where we recognize the immortal\n"
	.string "TRAINERS who left great records in\l"
	.string "BATTLE FRONTIER events.$"

BattleFrontier_RankingHall_Text_DomePikeFactoryRecords: @ 825E5F9
	.string "BATTLE DOME, BATTLE PIKE,\n"
	.string "and BATTLE FACTORY Records$"

BattleFrontier_RankingHall_Text_PalaceArenaPyramidRecords: @ 825E62E
	.string "BATTLE PALACE, BATTLE ARENA,\n"
	.string "and BATTLE PYRAMID Records$"

BattleFrontier_RankingHall_Text_IsYourNameOnThisList: @ 825E666
	.string "Hi, is your name on this list?$"

BattleFrontier_RankingHall_Text_WowThatsSuper: @ 825E685
	.string "Wow, that's super!\n"
	.string "I'll have to try harder, too!$"

BattleFrontier_RankingHall_Text_WorkHarderIfYouSawFriendsName: @ 825E6B6
	.string "Oh, is that right?\p"
	.string "If you saw your friend's name up here,\n"
	.string "I bet it would make you work harder!$"

BattleFrontier_RankingHall_Text_MyNamesNotUpThere: @ 825E715
	.string "Hmm…\n"
	.string "My name's not up there…\p"
	.string "Well, it's only natural since I haven't\n"
	.string "taken any challenges yet.$"

