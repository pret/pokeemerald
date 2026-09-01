NavelRock_Harbor_Frlg_MapScripts::
	.byte 0

NavelRock_Harbor_Frlg_EventScript_Sailor::
	lock
	faceplayer
	message Text_WhereDoYouWantToSail
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_NAVEL_ROCK
	multichoice 20, 8, MULTI_SEAGALLOP_VERMILION, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToVermilionCity
	case 1, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end
