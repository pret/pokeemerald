InsideOfTruck_MapScripts:: @ 823BEDA
	map_script EVENT_TAG_ON_MAP_LOAD, InsideOfTruck_MapScript_OnLoad
	map_script EVENT_TAG_ON_MAP_RESUME, InsideOfTruck_MapScript_OnResume
	.byte 0

InsideOfTruck_MapScript_OnLoad: @ 823BEE5
	setmetatile 4, 1, 520, 0
	setmetatile 4, 2, 528, 0
	setmetatile 4, 3, 536, 0
	end

InsideOfTruck_MapScript_OnResume: @ 823BF01
	setstepcallback 5
	end

InsideOfTruck_EventScript_SetupGenderHideFlags:: @ 823BF04
	lockall
	setflag FLAG_HIDE_MAP_NAME
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq InsideOfTruck_EventScript_SetupBrendanHideFlags
	compare VAR_RESULT, FEMALE
	goto_if_eq InsideOfTruck_EventScript_SetupMayHideFlags
	end

InsideOfTruck_EventScript_SetupBrendanHideFlags:: @ 823BF20
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_INTRO_SEQUENCE_STATE, INTRO_SEQUENCE_STATE_MALE
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_0x408C, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetupMayHideFlags:: @ 823BF46
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_INTRO_SEQUENCE_STATE, INTRO_SEQUENCE_STATE_FEMALE
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_0x4082, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBoxLogo:: @ 823BF6C
	msgbox InsideOfTruck_Text_BoxLogo, MSGBOX_SIGN
	end

InsideOfTruck_Text_BoxLogo: @ 823BF75
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

