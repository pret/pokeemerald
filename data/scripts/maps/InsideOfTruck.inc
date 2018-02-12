InsideOfTruck_MapScripts:: @ 823BEDA
	map_script 1, InsideOfTruck_MapScript1_23BEE5
	map_script 5, InsideOfTruck_MapScript1_23BF01
	.byte 0

InsideOfTruck_MapScript1_23BEE5: @ 823BEE5
	setmetatile 4, 1, 520, 0
	setmetatile 4, 2, 528, 0
	setmetatile 4, 3, 536, 0
	end

InsideOfTruck_MapScript1_23BF01: @ 823BF01
	setstepcallback 5
	end

InsideOfTruck_EventScript_23BF04:: @ 823BF04
	lockall
	setflag FLAG_SPECIAL_FLAG_0x4000
	checkplayergender
	compare VAR_RESULT, 0
	goto_eq InsideOfTruck_EventScript_23BF20
	compare VAR_RESULT, 1
	goto_eq InsideOfTruck_EventScript_23BF46
	end

InsideOfTruck_EventScript_23BF20:: @ 823BF20
	setrespawn 1
	setvar VAR_0x4092, 1
	setflag FLAG_0x2F7
	setflag FLAG_0x2FA
	setflag FLAG_0x310
	setflag FLAG_0x2DF
	setflag FLAG_0x331
	setvar VAR_0x408C, 1
	setdynamicwarp LITTLEROOT_TOWN, 255, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_23BF46:: @ 823BF46
	setrespawn 2
	setvar VAR_0x4092, 2
	setflag FLAG_0x2F6
	setflag FLAG_0x2F9
	setflag FLAG_0x311
	setflag FLAG_0x2E0
	setflag FLAG_0x332
	setvar VAR_0x4082, 1
	setdynamicwarp LITTLEROOT_TOWN, 255, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_23BF6C:: @ 823BF6C
	msgbox InsideOfTruck_Text_23BF75, 3
	end

InsideOfTruck_Text_23BF75: @ 823BF75
	.string "The box is printed with a POKéMON logo.\p"
	.string "It’s a POKéMON brand moving and\n"
	.string "delivery service.$"

