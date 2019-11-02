AbandonedShip_Corridors_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_MapScript1_237D8F
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_MapScript1_237D98
	.byte 0

AbandonedShip_Corridors_B1F_MapScript1_237D8F:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 255, 5, 4
	end

AbandonedShip_Corridors_B1F_MapScript1_237D98:
	call_if_unset FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_237DAB
	call_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_237DB5
	end

AbandonedShip_Corridors_B1F_EventScript_237DAB::
	setmetatile 11, 4, METATILE_InsideShip_InTactDoor0_Bottom, 1
	return

AbandonedShip_Corridors_B1F_EventScript_237DB5::
	setmetatile 11, 4, METATILE_InsideShip_InTactDoor1_Bottom, 1
	return

AbandonedShip_Corridors_B1F_EventScript_237DBF::
	msgbox AbandonedShip_Corridors_B1F_Text_237F03, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_237DC8::
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_237E09
	checkitem ITEM_STORAGE_KEY, 1
	compare VAR_RESULT, 0
	goto_if_eq AbandonedShip_Corridors_B1F_EventScript_237DFF
	msgbox AbandonedShip_Corridors_B1F_Text_237F4B, MSGBOX_DEFAULT
	playse SE_PIN
	takeitem ITEM_STORAGE_KEY, 1
	setflag FLAG_USED_STORAGE_KEY
	call AbandonedShip_Corridors_B1F_EventScript_237DB5
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_237DFF::
	msgbox AbandonedShip_Corridors_B1F_Text_237F15, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_237E09::
	msgbox AbandonedShip_Corridors_B1F_Text_237FA5, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_237E13::
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_237E2A, AbandonedShip_Corridors_B1F_Text_237E80
	msgbox AbandonedShip_Corridors_B1F_Text_237E92, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_237E2A:
	.string "바다로 나갈 때\n"
	.string "우리 선원들은\l"
	.string "항상 포켓몬을 데리고 간다!\l"
	.string "잠깐 승부해줘야겠어!$"

AbandonedShip_Corridors_B1F_Text_237E80:
	.string "이거 큰일인걸$"

AbandonedShip_Corridors_B1F_Text_237E92:
	.string "배가 물속으로\n"
	.string "가라앉아버렸어\p"
	.string "포켓몬이 물속에 잠수하는 기술을\n"
	.string "쓸 수 있다면\l"
	.string "일이 쉬워질 텐데...$"

AbandonedShip_Corridors_B1F_Text_237F03:
	.string "와-!\n"
	.string "배다-!$"

AbandonedShip_Corridors_B1F_Text_237F15:
	.string "열쇠가 걸려 있다\p"
	.string "문에는 “창고”라고 쓰여 있다$"

AbandonedShip_Corridors_B1F_Text_237F4B:
	.string "{PLAYER}{K_EUNNEUN}\n"
	.string "창고열쇠를 사용했다!\p"
	.string "넣은 열쇠는 뺄 수 없게 되었지만\n"
	.string "문은 열렸다!$"

AbandonedShip_Corridors_B1F_Text_237FA5:
AbandonedShip_HiddenFloorCorridors_Text_237FA5:
	.string "문이 열렸다!$"

