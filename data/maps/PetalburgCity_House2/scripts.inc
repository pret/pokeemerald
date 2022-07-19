PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN est le nouveau CHAMPION\n"
	.string "D’ARENE de notre ville.\p"
	.string "Je crois qu’il a fait venir sa famille\n"
	.string "d’une région lointaine.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "J’ai affronté NORMAN une fois.\n"
	.string "Mais il était bien trop fort.\p"
	.string "Comment dire…\p"
	.string "J’ai le sentiment qu’il ne vit\n"
	.string "que pour les POKéMON.$"

