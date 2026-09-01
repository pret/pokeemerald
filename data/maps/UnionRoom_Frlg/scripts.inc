UnionRoom_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, UnionRoom_OnResume_Frlg
	map_script MAP_SCRIPT_ON_TRANSITION, UnionRoom_OnTransition_Frlg
	.byte 0

UnionRoom_OnResume_Frlg::
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_1
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_2
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_3
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_4
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_5
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_6
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_7
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_8
	removeobject LOCALID_UNION_ROOM_PLAYER_1
	removeobject LOCALID_UNION_ROOM_PLAYER_2
	removeobject LOCALID_UNION_ROOM_PLAYER_3
	removeobject LOCALID_UNION_ROOM_PLAYER_4
	removeobject LOCALID_UNION_ROOM_PLAYER_5
	removeobject LOCALID_UNION_ROOM_PLAYER_6
	removeobject LOCALID_UNION_ROOM_PLAYER_7
	removeobject LOCALID_UNION_ROOM_PLAYER_8
	special RunUnionRoom
	end

UnionRoom_OnTransition_Frlg::
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

UnionRoom_EventScript_Player1_Frlg::
	lock
	faceplayer
	setvar VAR_RESULT, 1
	waitstate
	release
	end

UnionRoom_EventScript_Player2_Frlg::
	lock
	faceplayer
	setvar VAR_RESULT, 2
	waitstate
	release
	end

UnionRoom_EventScript_Player3_Frlg::
	lock
	faceplayer
	setvar VAR_RESULT, 3
	waitstate
	release
	end

UnionRoom_EventScript_Player4_Frlg::
	lock
	faceplayer
	setvar VAR_RESULT, 4
	waitstate
	release
	end

UnionRoom_EventScript_Player5_Frlg::
	lock
	faceplayer
	setvar VAR_RESULT, 5
	waitstate
	release
	end

UnionRoom_EventScript_Player6_Frlg::
	lock
	faceplayer
	setvar VAR_RESULT, 6
	waitstate
	release
	end

UnionRoom_EventScript_Player7_Frlg::
	lock
	faceplayer
	setvar VAR_RESULT, 7
	waitstate
	release
	end

UnionRoom_EventScript_Player8_Frlg::
	lock
	faceplayer
	setvar VAR_RESULT, 8
	waitstate
	release
	end

UnionRoom_EventScript_Attendant_Frlg::
	lock
	faceplayer
	setvar VAR_RESULT, 9
	waitstate
	release
	end

UnionRoom_EventScript_Unused_Frlg::
	lockall
	setvar VAR_RESULT, 10
	waitstate
	releaseall
	end
