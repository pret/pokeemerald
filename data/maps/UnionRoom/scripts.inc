.set LOCALID_UR_PLAYER_4, 2
.set LOCALID_UR_PLAYER_8, 3
.set LOCALID_UR_PLAYER_7, 4
.set LOCALID_UR_PLAYER_6, 5
.set LOCALID_UR_PLAYER_5, 6
.set LOCALID_UR_PLAYER_3, 7
.set LOCALID_UR_PLAYER_2, 8
.set LOCALID_UR_PLAYER_1, 9

UnionRoom_MapScripts:: @ 823D1A6
	map_script MAP_SCRIPT_ON_RESUME, UnionRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, UnionRoom_OnTransition
	.byte 0

UnionRoom_OnResume: @ 823D1B1
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_1
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_2
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_3
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_4
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_5
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_6
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_7
	setflag FLAG_HIDE_UNION_ROOM_PLAYER_8
	removeobject LOCALID_UR_PLAYER_1
	removeobject LOCALID_UR_PLAYER_2
	removeobject LOCALID_UR_PLAYER_3
	removeobject LOCALID_UR_PLAYER_4
	removeobject LOCALID_UR_PLAYER_5
	removeobject LOCALID_UR_PLAYER_6
	removeobject LOCALID_UR_PLAYER_7
	removeobject LOCALID_UR_PLAYER_8
	special RunUnionRoom
	end

UnionRoom_OnTransition: @ 823D1E5
	end

UnionRoom_EventScript_Player1:: @ 823D1E6
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_1
	waitstate
	release
	end

UnionRoom_EventScript_Player2:: @ 823D1F0
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_2
	waitstate
	release
	end

UnionRoom_EventScript_Player3:: @ 823D1FA
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_3
	waitstate
	release
	end

UnionRoom_EventScript_Player4:: @ 823D204
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_4
	waitstate
	release
	end

UnionRoom_EventScript_Player5:: @ 823D20E
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_5
	waitstate
	release
	end

UnionRoom_EventScript_Player6:: @ 823D218
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_6
	waitstate
	release
	end

UnionRoom_EventScript_Player7:: @ 823D222
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_7
	waitstate
	release
	end

UnionRoom_EventScript_Player8:: @ 823D22C
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_8
	waitstate
	release
	end

UnionRoom_EventScript_Attendant:: @ 823D236
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_ATTENDANT
	waitstate
	release
	end

UnionRoom_EventScript_Unused:: @ 823D240
	lockall
	setvar VAR_RESULT, UR_INTERACT_UNUSED
	waitstate
	releaseall
	end

