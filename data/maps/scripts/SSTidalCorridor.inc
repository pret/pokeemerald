SSTidalCorridor_MapScripts:: @ 823BFCF
	map_script 2, SSTidalCorridor_MapScript2_23BFD5
	.byte 0

SSTidalCorridor_MapScript2_23BFD5: @ 823BFD5
	map_script_2 VAR_0x40D4, 0, SSTidalCorridor_EventScript_23C219
	map_script_2 VAR_PORTHOLE, 1, SSTidalCorridor_EventScript_23BFFF
	map_script_2 VAR_PORTHOLE, 5, SSTidalCorridor_EventScript_23C015
	map_script_2 VAR_PORTHOLE, 9, SSTidalCorridor_EventScript_23C067
	map_script_2 VAR_PORTHOLE, 10, SSTidalCorridor_EventScript_23C07D
	.2byte 0

SSTidalCorridor_EventScript_23BFFF:: @ 823BFFF
	special sub_8137F90
	setvar VAR_PORTHOLE, 2
	lockall
	playse SE_PINPON
	msgbox SSTidalCorridor_Text_23C462, 4
	releaseall
	end

SSTidalCorridor_EventScript_23C015:: @ 823C015
	setvar VAR_PORTHOLE, 6
	lockall
	playse SE_PINPON
	msgbox SSTidalCorridor_Text_23C4E3, 4
	releaseall
	end

SSTidalRooms_EventScript_23C028:: @ 823C028
	special sub_8137F90
	setvar VAR_PORTHOLE, 7
	playse SE_PINPON
	msgbox SSTidalRooms_Text_23C462, 4
	return

SSTidalRooms_EventScript_23C03C:: @ 823C03C
	special sub_8137FB0
	setvar VAR_PORTHOLE, 4
	playse SE_PINPON
	msgbox SSTidalRooms_Text_23C553, 4
	return

