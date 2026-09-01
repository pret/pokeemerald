EventScript_RemoveStaticMon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

EventScript_MonFlewAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox Text_MonFlewAway
	release
	end

EventScript_AwakenSnorlax::
	message Text_PlayedPokeFlute
	waitmessage
	playfanfare MUS_RG_POKE_FLUTE
	waitfanfare
	msgbox Text_SnorlaxWokeUp
	return
