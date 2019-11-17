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
	removeobject 9
	removeobject 8
	removeobject 7
	removeobject 2
	removeobject 6
	removeobject 5
	removeobject 4
	removeobject 3
	special UnionRoomSpecial
	end

UnionRoom_OnTransition: @ 823D1E5
	end

UnionRoom_EventScript_Player1:: @ 823D1E6
	lock
	faceplayer
	setvar VAR_RESULT, 1
	waitstate
	release
	end

UnionRoom_EventScript_Player2:: @ 823D1F0
	lock
	faceplayer
	setvar VAR_RESULT, 2
	waitstate
	release
	end

UnionRoom_EventScript_Player3:: @ 823D1FA
	lock
	faceplayer
	setvar VAR_RESULT, 3
	waitstate
	release
	end

UnionRoom_EventScript_Player4:: @ 823D204
	lock
	faceplayer
	setvar VAR_RESULT, 4
	waitstate
	release
	end

UnionRoom_EventScript_Player5:: @ 823D20E
	lock
	faceplayer
	setvar VAR_RESULT, 5
	waitstate
	release
	end

UnionRoom_EventScript_Player6:: @ 823D218
	lock
	faceplayer
	setvar VAR_RESULT, 6
	waitstate
	release
	end

UnionRoom_EventScript_Player7:: @ 823D222
	lock
	faceplayer
	setvar VAR_RESULT, 7
	waitstate
	release
	end

UnionRoom_EventScript_Player8:: @ 823D22C
	lock
	faceplayer
	setvar VAR_RESULT, 8
	waitstate
	release
	end

UnionRoom_EventScript_Attendant:: @ 823D236
	lock
	faceplayer
	setvar VAR_RESULT, 9
	waitstate
	release
	end

UnionRoom_EventScript_Unused:: @ 823D240
	lockall
	setvar VAR_RESULT, 10
	waitstate
	releaseall
	end

