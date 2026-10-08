PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Mensen zeiden dat ze een POKéMON\n"
	.string "hoog boven HOENN zagen vliegen.\p"
	.string "Vliegt hij de hele tijd rond?\n"
	.string "Moet hij nergens rusten?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Een lucht-POKéMON!\n"
	.string "Een lucht-POKéMON!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Waar kom jij vandaan?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Ja?\n"
	.string "YES TOWN?\p"
	.string "Van zo'n plek heb ik nog nooit\n"
	.string "gehoord.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "Nee? Dat klopt niet.\n"
	.string "Je moet ergens vandaan komen.\p"
	.string "Oh! Wacht! Je gaat toch niet zeggen\n"
	.string "dat je op de zeebodem geboren bent?$"

