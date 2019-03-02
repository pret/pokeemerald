AbandonedShip_Rooms_B1F_MapScripts:: @ 8237FB7
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Rooms_B1F_MapScript1_237FBD
	.byte 0

AbandonedShip_Rooms_B1F_MapScript1_237FBD: @ 8237FBD
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER2, 255, 17, 4
	end

AbandonedShip_Rooms_B1F_EventScript_237FC6:: @ 8237FC6
	msgbox AbandonedShip_Rooms_B1F_Text_237FCF, MSGBOX_NPC
	end

AbandonedShip_Rooms_B1F_Text_237FCF: @ 8237FCF
	.string "Urrrrppp…\p"
	.string "I'm getting queasy just being aboard\n"
	.string "this ship…\p"
	.string "It's not even moving, but…$"

