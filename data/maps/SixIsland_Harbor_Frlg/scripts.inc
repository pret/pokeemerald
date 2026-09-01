SixIsland_Harbor_Frlg_MapScripts::
	.byte 0

SixIsland_Harbor_EventScript_Sailor::
	lock
	faceplayer
	message Text_WhereDoYouWantToSail
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_SIX_ISLAND
	goto EventScript_ChooseDestFromIsland
	end
