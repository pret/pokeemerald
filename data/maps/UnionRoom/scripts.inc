UnionRoom_MapScripts:: @ 823D1A6
	map_script 5, UnionRoom_MapScript1_23D1B1
	map_script 3, UnionRoom_MapScript1_23D1E5
	.byte 0

UnionRoom_MapScript1_23D1B1: @ 823D1B1
	setflag FLAG_0x2BF
	setflag FLAG_0x2C0
	setflag FLAG_0x2C1
	setflag FLAG_0x2C2
	setflag FLAG_0x2C3
	setflag FLAG_0x2C4
	setflag FLAG_0x2C5
	setflag FLAG_0x2C6
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

UnionRoom_MapScript1_23D1E5: @ 823D1E5
	end

UnionRoom_EventScript_23D1E6:: @ 823D1E6
	lock
	faceplayer
	setvar VAR_RESULT, 1
	waitstate
	release
	end

UnionRoom_EventScript_23D1F0:: @ 823D1F0
	lock
	faceplayer
	setvar VAR_RESULT, 2
	waitstate
	release
	end

UnionRoom_EventScript_23D1FA:: @ 823D1FA
	lock
	faceplayer
	setvar VAR_RESULT, 3
	waitstate
	release
	end

UnionRoom_EventScript_23D204:: @ 823D204
	lock
	faceplayer
	setvar VAR_RESULT, 4
	waitstate
	release
	end

UnionRoom_EventScript_23D20E:: @ 823D20E
	lock
	faceplayer
	setvar VAR_RESULT, 5
	waitstate
	release
	end

UnionRoom_EventScript_23D218:: @ 823D218
	lock
	faceplayer
	setvar VAR_RESULT, 6
	waitstate
	release
	end

UnionRoom_EventScript_23D222:: @ 823D222
	lock
	faceplayer
	setvar VAR_RESULT, 7
	waitstate
	release
	end

UnionRoom_EventScript_23D22C:: @ 823D22C
	lock
	faceplayer
	setvar VAR_RESULT, 8
	waitstate
	release
	end

UnionRoom_EventScript_23D236:: @ 823D236
	lock
	faceplayer
	setvar VAR_RESULT, 9
	waitstate
	release
	end

UnionRoom_EventScript_23D240:: @ 823D240
	lockall
	setvar VAR_RESULT, 10
	waitstate
	releaseall
	end

