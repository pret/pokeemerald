CaveOfOrigin_1F_MapScripts:: @ 8235768
	map_script 3, CaveOfOrigin_1F_MapScript1_23576E
	.byte 0

CaveOfOrigin_1F_MapScript1_23576E: @ 823576E
	call_if_set FLAG_0x071, CaveOfOrigin_1F_EventScript_2722C1
	end

