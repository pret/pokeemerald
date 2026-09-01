SSAnne_2F_Room3_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room3_EventScript_Gentleman::
	msgbox SSAnne_2F_Room3_Text_SeenMonsFerryPeople, MSGBOX_NPC
	end

SSAnne_2F_Room3_EventScript_OldMan::
	msgbox SSAnne_2F_Room3_Text_SomeTreesCanBeCutDown, MSGBOX_NPC
	end

SSAnne_2F_Room3_Text_SeenMonsFerryPeople::
	.string "Ah, yes, I have seen some POKéMON\n"
	.string "ferry people across the water!$"

SSAnne_2F_Room3_Text_SomeTreesCanBeCutDown::
	.string "Small trees can be chopped down\n"
	.string "using the move CUT.\p"
	.string "But remember this!\n"
	.string "CUT is an HM technique.\p"
	.string "Once learned, it is not so easily\n"
	.string "discarded.$"

