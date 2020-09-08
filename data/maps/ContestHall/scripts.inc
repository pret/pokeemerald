ContestHall_MapScripts:: @ 823B781
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ContestHall_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ContestHall_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, ContestHall_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ContestHall_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, ContestHall_OnReturn
	.byte 0

ContestHall_OnReturn: @ 823B79B
	special LoadLinkContestPlayerPalettes
	end

ContestHall_OnTransition: @ 823B79F
	call ContestHall_EventScript_ReadyContestMusic
	setvar VAR_TEMP_0, 1
	call ContestHall_EventScript_AddRandomAudienceMembers
	end

ContestHall_EventScript_ReadyContestMusic:: @ 823B7AF
	call ContestHall_EventScript_TryWaitForLink
	special GetContestMultiplayerId
	compare VAR_RESULT, 0
	call_if_eq ContestHall_EventScript_SaveContestMusicPlayer1
	compare VAR_RESULT, 1
	call_if_eq ContestHall_EventScript_SaveContestMusicPlayer2
	compare VAR_RESULT, 2
	call_if_eq ContestHall_EventScript_SaveContestMusicPlayer3
	compare VAR_RESULT, 3
	call_if_eq ContestHall_EventScript_SaveContestMusicPlayer4
	compare VAR_RESULT, 4
	call_if_eq ContestHall_EventScript_SaveContestMusic
	return

ContestHall_EventScript_SaveContestMusicPlayer1:: @ 823B7EF
	savebgm MUS_LINK_CONTEST_P1
	return

ContestHall_EventScript_SaveContestMusicPlayer2:: @ 823B7F3
	savebgm MUS_LINK_CONTEST_P2
	return

ContestHall_EventScript_SaveContestMusicPlayer3:: @ 823B7F7
	savebgm MUS_LINK_CONTEST_P3
	return

ContestHall_EventScript_SaveContestMusicPlayer4:: @ 823B7FB
	savebgm MUS_LINK_CONTEST_P4
	return

ContestHall_EventScript_SaveContestMusic:: @ 823B7FF
	savebgm MUS_CONTEST
	return

ContestHall_OnResume: @ 823B803
	compare VAR_TEMP_9, 1
	call_if_eq ContestHall_EventScript_ReShowAudience
	end

ContestHall_EventScript_ReShowAudience:: @ 823B80F
	call ContestHall_EventScript_CreateAudience
	return

ContestHall_OnFrame: @ 823B815
	map_script_2 VAR_CONTEST_HALL_STATE, 1, ContestHall_EventScript_Contest
	.2byte 0

ContestHall_OnWarp: @ 823B81F
	map_script_2 VAR_CONTEST_HALL_STATE, 1, ContestHall_EventScript_SetContestObjects
	.2byte 0

ContestHall_EventScript_Contest:: @ 823B829
	call ContestHall_EventScript_DoContest
	call ContestHall_EventScript_SetExitWarp
	end

ContestHall_EventScript_SetContestObjects:: @ 823B834
	special LoadLinkContestPlayerPalettes
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	call ContestHall_EventScript_CreateAudience
	end

@ There are 8 audience member object events, 7 of which are given random gfx below (the 8th is the Artist)
@ The rest of the audience is created statically by ContestHall_EventScript_CreateAudience
ContestHall_EventScript_AddRandomAudienceMembers:: @ 823B842
	call ContestHall_EventScript_GetRandomAudienceGfxId
	call ContestHall_EventScript_SetRandomAudienceGfx
	compare VAR_TEMP_0, 8
	goto_if_lt ContestHall_EventScript_AddRandomAudienceMembers
	return

ContestHall_EventScript_SetRandomAudienceGfx:: @ 823B858
	switch VAR_TEMP_0
	case 1, ContestHall_EventScript_SetRandomAudience1
	case 2, ContestHall_EventScript_SetRandomAudience2
	case 3, ContestHall_EventScript_SetRandomAudience3
	case 4, ContestHall_EventScript_SetRandomAudience4
	case 5, ContestHall_EventScript_SetRandomAudience5
	case 6, ContestHall_EventScript_SetRandomAudience6
	case 7, ContestHall_EventScript_SetRandomAudience7
	end

ContestHall_EventScript_SetRandomAudience1:: @ 823B8AB
	copyvar VAR_OBJ_GFX_ID_4, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience2:: @ 823B8B6
	copyvar VAR_OBJ_GFX_ID_5, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience3:: @ 823B8C1
	copyvar VAR_OBJ_GFX_ID_6, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience4:: @ 823B8CC
	copyvar VAR_OBJ_GFX_ID_7, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience5:: @ 823B8D7
	copyvar VAR_OBJ_GFX_ID_8, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience6:: @ 823B8E2
	copyvar VAR_OBJ_GFX_ID_9, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_SetRandomAudience7:: @ 823B8ED
	copyvar VAR_OBJ_GFX_ID_A, VAR_TEMP_1
	addvar VAR_TEMP_0, 1
	return

ContestHall_EventScript_GetRandomAudienceGfxId:: @ 823B8F8
	setvar VAR_RESULT, 32
	special GenerateContestRand
	addvar VAR_RESULT, 1
	switch VAR_RESULT
	case 1, ContestHall_EventScript_RandomAudienceNinjaBoy
	case 2, ContestHall_EventScript_RandomAudienceTwin
	case 3, ContestHall_EventScript_RandomAudienceBoy1
	case 4, ContestHall_EventScript_RandomAudienceGirl1
	case 5, ContestHall_EventScript_RandomAudienceGirl2
	case 6, ContestHall_EventScript_RandomAudienceLittleBoy
	case 7, ContestHall_EventScript_RandomAudienceGirl
	case 8, ContestHall_EventScript_RandomAudienceBoy3
	case 9, ContestHall_EventScript_RandomAudienceGirl3
	case 10, ContestHall_EventScript_RandomAudienceRichBoy
	case 11, ContestHall_EventScript_RandomAudienceFatMan
	case 12, ContestHall_EventScript_RandomAudiencePokefanF
	case 13, ContestHall_EventScript_RandomAudienceMan1
	case 14, ContestHall_EventScript_RandomAudienceWoman2
	case 15, ContestHall_EventScript_RandomAudienceExpertM
	case 16, ContestHall_EventScript_RandomAudienceExpertF
	case 17, ContestHall_EventScript_RandomAudiencePokefanM
	case 18, ContestHall_EventScript_RandomAudienceWoman4
	case 19, ContestHall_EventScript_RandomAudienceCook
	case 20, ContestHall_EventScript_RandomAudienceLass
	case 21, ContestHall_EventScript_RandomAudienceOldWoman
	case 22, ContestHall_EventScript_RandomAudienceCamper
	case 23, ContestHall_EventScript_RandomAudiencePicnicker
	case 24, ContestHall_EventScript_RandomAudienceMan3
	case 25, ContestHall_EventScript_RandomAudienceWoman5
	case 26, ContestHall_EventScript_RandomAudienceYoungster
	case 27, ContestHall_EventScript_RandomAudienceBugCatcher
	case 28, ContestHall_EventScript_RandomAudiencePsychicM
	case 29, ContestHall_EventScript_RandomAudienceSchoolKidM
	case 30, ContestHall_EventScript_RandomAudienceBlackBelt
	case 31, ContestHall_EventScript_RandomAudienceBeauty
	case 32, ContestHall_EventScript_RandomAudienceScientist1
	end

ContestHall_EventScript_RandomAudienceNinjaBoy:: @ 823BA6B
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_NINJA_BOY
	return

ContestHall_EventScript_RandomAudienceTwin:: @ 823BA71
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_TWIN
	return

ContestHall_EventScript_RandomAudienceBoy1:: @ 823BA77
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BOY_1
	return

ContestHall_EventScript_RandomAudienceGirl1:: @ 823BA7D
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_1
	return

ContestHall_EventScript_RandomAudienceGirl2:: @ 823BA83
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_2
	return

ContestHall_EventScript_RandomAudienceLittleBoy:: @ 823BA89
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_BOY
	return

ContestHall_EventScript_RandomAudienceGirl:: @ 823BA8F
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LITTLE_GIRL
	return

ContestHall_EventScript_RandomAudienceBoy3:: @ 823BA95
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BOY_3
	return

ContestHall_EventScript_RandomAudienceGirl3:: @ 823BA9B
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_GIRL_3
	return

ContestHall_EventScript_RandomAudienceRichBoy:: @ 823BAA1
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_RICH_BOY
	return

ContestHall_EventScript_RandomAudienceFatMan:: @ 823BAA7
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_FAT_MAN
	return

ContestHall_EventScript_RandomAudiencePokefanF:: @ 823BAAD
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEFAN_F
	return

ContestHall_EventScript_RandomAudienceMan1:: @ 823BAB3
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN_1
	return

ContestHall_EventScript_RandomAudienceWoman2:: @ 823BAB9
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_2
	return

ContestHall_EventScript_RandomAudienceExpertM:: @ 823BABF
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_EXPERT_M
	return

ContestHall_EventScript_RandomAudienceExpertF:: @ 823BAC5
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_EXPERT_F
	return

ContestHall_EventScript_RandomAudiencePokefanM:: @ 823BACB
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_POKEFAN_M
	return

ContestHall_EventScript_RandomAudienceWoman4:: @ 823BAD1
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_4
	return

ContestHall_EventScript_RandomAudienceCook:: @ 823BAD7
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_COOK
	return

ContestHall_EventScript_RandomAudienceLass:: @ 823BADD
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_LASS
	return

ContestHall_EventScript_RandomAudienceOldWoman:: @ 823BAE3
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_OLD_WOMAN
	return

ContestHall_EventScript_RandomAudienceCamper:: @ 823BAE9
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_CAMPER
	return

ContestHall_EventScript_RandomAudiencePicnicker:: @ 823BAEF
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PICNICKER
	return

ContestHall_EventScript_RandomAudienceMan3:: @ 823BAF5
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_MAN_3
	return

ContestHall_EventScript_RandomAudienceWoman5:: @ 823BAFB
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_WOMAN_5
	return

ContestHall_EventScript_RandomAudienceYoungster:: @ 823BB01
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_YOUNGSTER
	return

ContestHall_EventScript_RandomAudienceBugCatcher:: @ 823BB07
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BUG_CATCHER
	return

ContestHall_EventScript_RandomAudiencePsychicM:: @ 823BB0D
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_PSYCHIC_M
	return

ContestHall_EventScript_RandomAudienceSchoolKidM:: @ 823BB13
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCHOOL_KID_M
	return

ContestHall_EventScript_RandomAudienceBlackBelt:: @ 823BB19
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BLACK_BELT
	return

ContestHall_EventScript_RandomAudienceBeauty:: @ 823BB1F
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_BEAUTY
	return

ContestHall_EventScript_RandomAudienceScientist1:: @ 823BB25
	setvar VAR_TEMP_1, OBJ_EVENT_GFX_SCIENTIST_1
	return

ContestHall_EventScript_CreateAudience:: @ 823BB2B
	specialvar VAR_RESULT, IsWirelessContest
	compare VAR_RESULT, TRUE
	goto_if_eq ContestHall_EventScript_CreateWirelessContestAudience
	switch VAR_CONTEST_TYPE
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_CreateNormalContestAudience
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_CreateSuperContestAudience
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_CreateHyperContestAudience
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_CreateMasterContestAudience
	case CONTEST_TYPE_LINK, ContestHall_EventScript_CreateMasterContestAudience
	return

ContestHall_EventScript_CreateNormalContestAudience:: @ 823BB78
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_CreateSuperContestAudience:: @ 823BB8B
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_LASS, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_CreateHyperContestAudience:: @ 823BBE6
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_EXPERT_F, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_2, 20, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_WOMAN_5, 20, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 8, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 24, 11, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 25, 3, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_FAT_MAN, 27, 5, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
	return

ContestHall_EventScript_CreateMasterContestAudience:: @ 823BC92
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MANIAC, 4, 1, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_5, 6, 1, 5, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_4, 7, 1, 6, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_FISHERMAN, 14, 13, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_MAN_4, 17, 13, 6, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_3, 22, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SAILOR, 25, 3, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_YOUNGSTER, 26, 4, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 27, 5, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 28, 9, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_SCHOOL_KID_M, 29, 10, 9, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 30, 11, 9, 3, DIR_NORTH
	return

ContestHall_EventScript_CreateWirelessContestAudience:: @ 823BD86
	createvobject OBJ_EVENT_GFX_BEAUTY, 0, 2, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MAN_5, 1, 2, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_HIKER, 2, 2, 7, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 3, 2, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_MANIAC, 4, 1, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_5, 6, 1, 5, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_4, 7, 1, 6, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_GENTLEMAN, 9, 1, 8, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_NINJA_BOY, 10, 12, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_2, 11, 12, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_WOMAN_3, 12, 12, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_BEAUTY, 13, 12, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_FISHERMAN, 14, 13, 3, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, 15, 13, 4, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_MAN_4, 17, 13, 6, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_MART_EMPLOYEE, 18, 13, 7, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_DEVON_EMPLOYEE, 19, 13, 8, 3, DIR_WEST
	createvobject OBJ_EVENT_GFX_POKEFAN_M, 20, 3, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_CAMPER, 21, 6, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_MAN_3, 22, 7, 2, 3, DIR_SOUTH
	createvobject OBJ_EVENT_GFX_SCIENTIST_1, 24, 11, 2, 3, DIR_SOUTH
	return

ContestHall_EventScript_SetExitWarp:: @ 823BE44
	special ClearLinkContestFlags
	switch VAR_CONTEST_TYPE
	case CONTEST_TYPE_NPC_NORMAL, ContestHall_EventScript_SetExitWarpNormalContest
	case CONTEST_TYPE_NPC_SUPER, ContestHall_EventScript_SetExitWarpSuperContest
	case CONTEST_TYPE_NPC_HYPER, ContestHall_EventScript_SetExitWarpHyperContest
	case CONTEST_TYPE_NPC_MASTER, ContestHall_EventScript_SetExitWarpMasterContest
	case CONTEST_TYPE_LINK, ContestHall_EventScript_SetExitWarpLinkContest
	return

ContestHall_EventScript_SetExitWarpNormalContest:: @ 823BE84
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 255, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpSuperContest:: @ 823BE8E
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 255, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpHyperContest:: @ 823BE98
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 255, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpMasterContest:: @ 823BEA2
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 255, 14, 4
	waitstate
	end

ContestHall_EventScript_SetExitWarpLinkContest:: @ 823BEAC
	warp MAP_LILYCOVE_CITY_CONTEST_LOBBY, 255, 15, 4
	waitstate
	end

LilycoveCity_ContestLobby_EventScript_SetPlayerGfx:: @ 823BEB6
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LilycoveCity_ContestLobby_EventScript_SetPlayerGfxBrendan
	compare VAR_RESULT, FEMALE
	goto_if_eq LilycoveCity_ContestLobby_EventScript_SetPlayerGfxMay
	return

LilycoveCity_ContestLobby_EventScript_SetPlayerGfxBrendan:: @ 823BECE
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

LilycoveCity_ContestLobby_EventScript_SetPlayerGfxMay:: @ 823BED4
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

