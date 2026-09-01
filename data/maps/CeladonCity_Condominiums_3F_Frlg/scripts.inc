CeladonCity_Condominiums_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	special Special_ShowDiploma
	release
	end

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ImTheProgrammer::
	.string "Me?\n"
	.string "I'm the programmer!$"

CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist::
	.string "I'm the graphic artist!\n"
	.string "I drew you!$"

CeladonCity_Condominiums_3F_Text_IWroteTheStory::
	.string "I wrote the story!\n"
	.string "Isn't ERIKA cute?\p"
	.string "I like MISTY a lot, too!\n"
	.string "Oh, and SABRINA, I like her!$"

CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex::
	.string "Is that right?\p"
	.string "I'm the game designer!\p"
	.string "Filling up your POKéDEX is tough,\n"
	.string "but don't quit!\p"
	.string "When you finish, come tell me!$"

CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations::
	.string "Wow! Excellent!\n"
	.string "You completed your POKéDEX!\l"
	.string "Congratulations!\l"
	.string "…$"

CeladonCity_Condominiums_3F_Text_ItsTheGameProgram::
	.string "It's the game program! Messing with\n"
	.string "it could bug out the game!$"

CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame::
	.string "Someone's playing a game instead of\n"
	.string "working!$"

CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding::
	.string "It's the script!\n"
	.string "Better not look at the ending!$"

CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom::
	.string "GAME FREAK Development Room$"

