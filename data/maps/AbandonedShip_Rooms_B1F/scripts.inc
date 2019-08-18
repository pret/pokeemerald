AbandonedShip_Rooms_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Rooms_B1F_MapScript1_237FBD
	.byte 0

AbandonedShip_Rooms_B1F_MapScript1_237FBD:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER2, 255, 17, 4
	end

AbandonedShip_Rooms_B1F_EventScript_237FC6::
	msgbox AbandonedShip_Rooms_B1F_Text_237FCF, MSGBOX_NPC
	end

AbandonedShip_Rooms_B1F_Text_237FCF:
	.string "우우웁...\p"
	.string "배 안에 있는 것만으로도\n"
	.string "멀미를 해버려...\p"
	.string "배는 움직이지도 않는데...$"

