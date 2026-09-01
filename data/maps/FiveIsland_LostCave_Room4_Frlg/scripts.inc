FiveIsland_LostCave_Room4_Frlg_MapScripts::
	.byte 0

FiveIsland_LostCave_Room4_EventScript_Laura::
	trainerbattle_single TRAINER_PSYCHIC_LAURA, FiveIsland_LostCave_Room4_Text_LauraIntro, FiveIsland_LostCave_Room4_Text_LauraDefeat
	msgbox FiveIsland_LostCave_Room4_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_LostCave_Room4_Text_LauraIntro::
	.string "I think there is a mysterious power\n"
	.string "at work in this cave.$"

FiveIsland_LostCave_Room4_Text_LauraDefeat::
	.string "If you don't go into the right\n"
	.string "tunnel, you won't get ahead.$"

FiveIsland_LostCave_Room4_Text_LauraPostBattle::
	.string "Earlier, a lady went into the caves\n"
	.string "ahead.$"

