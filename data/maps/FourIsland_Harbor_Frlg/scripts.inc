FourIsland_Harbor_Frlg_MapScripts::
	.byte 0

FourIsland_Harbor_EventScript_Sailor::
	lock
	faceplayer
	message Text_WhereDoYouWantToSail
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_FOUR_ISLAND
	goto EventScript_ChooseDestFromIsland
	end
