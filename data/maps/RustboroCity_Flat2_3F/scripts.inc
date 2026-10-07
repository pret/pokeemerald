RustboroCity_Flat2_3F_MapScripts::
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
	.string "De DIRECTEUR van DEVON verzamelt\n"
	.string "graag zeldzame stenen.$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
	.string "Volgens mij verzamelt de zoon van\n"
	.string "de DIRECTEUR ook zeldzame stenen.$"

