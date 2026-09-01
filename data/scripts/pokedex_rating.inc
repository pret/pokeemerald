PokedexRating_EventScript_RateInPerson::
	call_if_set FLAG_OAK_SAW_DEX_COMPLETION, PokedexRating_EventScript_DexCompleteIntro
	call_if_unset FLAG_OAK_SAW_DEX_COMPLETION, PokedexRating_EventScript_NormalIntro
	call PokedexRating_EventScript_Rate
	return

PokedexRating_EventScript_DexCompleteIntro::
	msgbox PokedexRating_Text_LoveSeeingYourPokedex
	return

PokedexRating_EventScript_NormalIntro::
	msgbox PokedexRating_Text_HowIsPokedexComingAlong
	return

PokedexRating_EventScript_ShowRatingMsg::
	copyvar VAR_0x8004, VAR_0x8009
	special GetProfOaksRatingMessage
	waitmessage
	call_if_eq VAR_RESULT, FALSE, PokedexRating_EventScript_NormalFanfare
	call_if_eq VAR_RESULT, TRUE, PokedexRating_EventScript_DexCompleteFanfare
	waitfanfare
	waitbuttonpress
	return

PokedexRating_EventScript_NormalFanfare::
	playfanfare MUS_RG_DEX_RATING
	return

PokedexRating_EventScript_DexCompleteFanfare::
	playfanfare MUS_EVOLVED
	return

PokedexRating_EventScript_Rate::
	specialvar VAR_RESULT, GetFrlgPokedexCount
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008 @ Num Kanto Seen
	buffernumberstring STR_VAR_2, VAR_0x8009 @ Num Kanto Caught
	msgbox PokedexRating_Text_SeenXOwnedY
	call_if_unset FLAG_OAKS_RATING_IS_VIA_PC, PokedexRating_EventScript_SetTextColor
	call PokedexRating_EventScript_ShowRatingMsg
	goto_if_eq VAR_0x800A, FALSE, PokedexRating_EventScript_EndRating  @ National Dex not enabled
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetFrlgPokedexCount
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring STR_VAR_1, VAR_0x8008 @ Num National Seen
	buffernumberstring STR_VAR_2, VAR_0x8009 @ Num National Caught
	msgbox PokedexRating_Text_NationalDexSeenXOwnedY
	specialvar VAR_RESULT, HasAllMons
	goto_if_eq VAR_RESULT, FALSE, PokedexRating_EventScript_DexIncomplete
	goto_if_eq VAR_RESULT, TRUE, PokedexRating_EventScript_DexComplete
	end

PokedexRating_EventScript_SetTextColor::
	textcolor NPC_TEXT_COLOR_MALE
	return

PokedexRating_EventScript_DexIncomplete::
	msgbox PokedexRating_Text_LookForwardToFilledNationalDex
	goto PokedexRating_EventScript_EndRating
	end

PokedexRating_EventScript_DexComplete::
	setflag FLAG_OAK_SAW_DEX_COMPLETION
	msgbox PokedexRating_Text_YouveCompletedDex
	goto PokedexRating_EventScript_EndRating
	end

PokedexRating_EventScript_EndRating::
	return
