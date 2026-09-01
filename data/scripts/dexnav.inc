EventScript_StartDexNavBattle::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	dowildbattle	
	release
	end

EventScript_NotFoundNearby::
	msgbox sText_NotFoundNearby, MSGBOX_SIGN
	end

EventScript_MovedTooFast::
	msgbox sText_TryMovingSlower, MSGBOX_SIGN
	end

EventScript_PokemonGotAway::
	msgbox sText_PokemonGotAway, MSGBOX_SIGN
	end

EventScript_LostSignal::
	msgbox sText_LostSignal, MSGBOX_SIGN
	end

EventScript_TooDark::
	msgbox sText_TooDark, MSGBOX_SIGN
	end

sText_NotFoundNearby:
	.string "It couldn't be found nearby.\n"
	.string "Try looking in a different area!$"

sText_TryMovingSlower:
	.string "The Pokémon got away!\n"
	.string "Try moving more slowly.$"

sText_PokemonGotAway:
	.string "The Pokémon got away!$"

sText_LostSignal:
	.string "There is no reaction.\n"
	.string "The signal was lost!$"

sText_TooDark:
	.string "It's too dark to search\nfor a Pokémon!$"
