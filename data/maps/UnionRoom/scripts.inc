@ Note: LOCALID_UNION_ROOM_PLAYER_# are local ids for this map used elsewhere. They're defined in event_objects.h

UnionRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, UnionRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, UnionRoom_OnTransition
	.byte 0

UnionRoom_OnResume:
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

UnionRoom_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER
	end

UnionRoom_EventScript_Player1::
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_1
	waitstate
	release
	end

UnionRoom_EventScript_Player2::
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_2
	waitstate
	release
	end

UnionRoom_EventScript_Player3::
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_3
	waitstate
	release
	end

UnionRoom_EventScript_Player4::
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_4
	waitstate
	release
	end

UnionRoom_EventScript_Player5::
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_5
	waitstate
	release
	end

UnionRoom_EventScript_Player6::
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_6
	waitstate
	release
	end

UnionRoom_EventScript_Player7::
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_7
	waitstate
	release
	end

UnionRoom_EventScript_Player8::
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_PLAYER_8
	waitstate
	release
	end

UnionRoom_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_RESULT, UR_INTERACT_ATTENDANT
	waitstate
	release
	end

UnionRoom_EventScript_Unused::
	lockall
	setvar VAR_RESULT, UR_INTERACT_UNUSED
	waitstate
	releaseall
	end
