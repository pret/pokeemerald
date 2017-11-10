BattleFrontier_OutsideEast_MapScripts:: @ 8242C04
	map_script 5, BattleFrontier_OutsideEast_MapScript1_242C0F
	map_script 3, BattleFrontier_OutsideEast_MapScript1_242C2D
	.byte 0

BattleFrontier_OutsideEast_MapScript1_242C0F: @ 8242C0F
	checkflag FLAG_SYS_CTRL_OBJ_DELETE
	call_if 1, BattleFrontier_OutsideEast_EventScript_242C19
	end

BattleFrontier_OutsideEast_EventScript_242C19:: @ 8242C19
	specialvar VAR_RESULT, sub_8138B80
	compare_var_to_value VAR_RESULT, 7
	goto_if 5, BattleFrontier_OutsideEast_EventScript_27374E
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_MapScript1_242C2D: @ 8242C2D
	setvar VAR_0x40BC, 0
	setflag FLAG_0x396
	checkflag FLAG_0x1C6
	call_if 0, BattleFrontier_OutsideEast_EventScript_242C3F
	end

BattleFrontier_OutsideEast_EventScript_242C3F:: @ 8242C3F
	clearflag FLAG_0x34A
	return

BattleFrontier_OutsideEast_EventScript_242C43:: @ 8242C43
	msgbox BattleFrontier_OutsideEast_Text_242E11, 3
	end

BattleFrontier_OutsideEast_EventScript_242C4C:: @ 8242C4C
	msgbox BattleFrontier_OutsideEast_Text_242E58, 3
	end

BattleFrontier_OutsideEast_EventScript_242C55:: @ 8242C55
	msgbox BattleFrontier_OutsideEast_Text_242E96, 3
	end

BattleFrontier_OutsideEast_EventScript_242C5E:: @ 8242C5E
	msgbox BattleFrontier_OutsideEast_Text_242ECF, 3
	end

BattleFrontier_OutsideEast_EventScript_242C67:: @ 8242C67
	msgbox BattleFrontier_OutsideEast_Text_242F8C, 2
	end

BattleFrontier_OutsideEast_EventScript_242C70:: @ 8242C70
	msgbox BattleFrontier_OutsideEast_Text_242FDC, 2
	end

BattleFrontier_OutsideEast_EventScript_242C79:: @ 8242C79
	msgbox BattleFrontier_OutsideEast_Text_24308C, 2
	end

BattleFrontier_OutsideEast_EventScript_242C82:: @ 8242C82
	msgbox BattleFrontier_OutsideEast_Text_243106, 2
	end

BattleFrontier_OutsideEast_EventScript_242C8B:: @ 8242C8B
	msgbox BattleFrontier_OutsideEast_Text_2431A5, 2
	end

BattleFrontier_OutsideEast_EventScript_242C94:: @ 8242C94
	lock
	msgbox BattleFrontier_OutsideEast_Text_2432DD, 4
	release
	end

BattleFrontier_OutsideEast_EventScript_242C9F:: @ 8242C9F
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox BattleFrontier_OutsideEast_Text_24334B, 4
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_242CB2:: @ 8242CB2
	msgbox BattleFrontier_OutsideEast_Text_243363, 2
	end

BattleFrontier_OutsideEast_EventScript_242CBB:: @ 8242CBB
	msgbox BattleFrontier_OutsideEast_Text_243425, 2
	end

BattleFrontier_OutsideEast_EventScript_242CC4:: @ 8242CC4
	msgbox BattleFrontier_OutsideEast_Text_2434A0, 2
	end

BattleFrontier_OutsideEast_EventScript_242CCD:: @ 8242CCD
	msgbox BattleFrontier_OutsideEast_Text_243504, 2
	end

BattleFrontier_OutsideEast_EventScript_242CD6:: @ 8242CD6
	lock
	msgbox BattleFrontier_OutsideEast_Text_243529, 4
	release
	end

BattleFrontier_OutsideEast_EventScript_242CE1:: @ 8242CE1
	msgbox BattleFrontier_OutsideEast_Text_243230, 2
	end

BattleFrontier_OutsideEast_EventScript_242CEA:: @ 8242CEA
	lock
	faceplayer
	waitse
	playse 269
	applymovement 14, BattleFrontier_OutsideEast_Movement_242D69
	waitmovement 0
	release
	end

