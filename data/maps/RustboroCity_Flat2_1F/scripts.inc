RustboroCity_Flat2_1F_MapScripts:: @ 8215F76
	.byte 0

RustboroCity_Flat2_1F_EventScript_215F77:: @ 8215F77
	msgbox RustboroCity_Flat2_1F_Text_215F93, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_215F80:: @ 8215F80
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox RustboroCity_Flat2_1F_Text_215FC6, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_215F93: @ 8215F93
	.string "DEVON CORPORATION's workers live in\n"
	.string "this building.$"

RustboroCity_Flat2_1F_Text_215FC6: @ 8215FC6
	.string "SKITTY: Gyaaaah!$"

