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
	compare VAR_RESULT, MALE
	goto_if_eq InsideOfTruck_EventScript_23BF20
	compare VAR_RESULT, FEMALE
	goto_if_eq InsideOfTruck_EventScript_23BF46
	end

InsideOfTruck_EventScript_23BF20:: @ 823BF20
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_0x4092, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_0x408C, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_23BF46:: @ 823BF46
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_0x4092, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_0x4082, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_23BF6C:: @ 823BF6C
	msgbox InsideOfTruck_Text_23BF75, MSGBOX_SIGN
	end

InsideOfTruck_Text_23BF75: @ 823BF75
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

