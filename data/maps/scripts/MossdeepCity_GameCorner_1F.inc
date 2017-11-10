MossdeepCity_GameCorner_1F_MapScripts:: @ 8224B27
	map_script 2, MossdeepCity_GameCorner_1F_MapScript2_224B41
	map_script 4, MossdeepCity_GameCorner_1F_MapScript2_224B37
	map_script 1, MossdeepCity_GameCorner_1F_MapScript1_276BBE
	.byte 0

MossdeepCity_GameCorner_1F_MapScript2_224B37: @ 8224B37
	map_script_2 VAR_0x4087, 8, MossdeepCity_GameCorner_1F_EventScript_276BAE
	.2byte 0

MossdeepCity_GameCorner_1F_MapScript2_224B41: @ 8224B41
	map_script_2 VAR_0x4087, 8, MossdeepCity_GameCorner_1F_EventScript_276C9D
	.2byte 0

MossdeepCity_GameCorner_1F_EventScript_224B4B:: @ 8224B4B
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_277C34
	release
	end

MossdeepCity_GameCorner_1F_EventScript_224B54:: @ 8224B54
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_277C91
	release
	end

MossdeepCity_GameCorner_1F_EventScript_224B5D:: @ 8224B5D
	msgbox MossdeepCity_GameCorner_1F_Text_224BFD, 3
	end

	.incbin "baserom.gba", 0x224b66, 0x97

MossdeepCity_GameCorner_1F_Text_224BFD: @ 8224BFD
	.string "The door appears to be locked.$"

	.incbin "baserom.gba", 0x224c1c, 0x22f

