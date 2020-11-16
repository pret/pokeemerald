.set LOCALID_CURATOR, 1

LilycoveCity_LilycoveMuseum_2F_MapScripts:: @ 821973A
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
	.byte 0

LilycoveCity_LilycoveMuseum_2F_OnLoad: @ 8219745
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting:: @ 8219754
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting:: @ 8219763
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting:: @ 8219772
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting:: @ 8219781
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting:: @ 821978B
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, 1
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting:: @ 82197A3
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, 1
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting:: @ 82197BB
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, 1
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting:: @ 82197D3
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, 1
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, 1
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting:: @ 82197EB
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, 1
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, 1
	end

LilycoveCity_LilycoveMuseum_2F_OnFrame: @ 82197FE
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall:: @ 8219808
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft: @ 8219861
	walk_in_place_fastest_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall: @ 8219863
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_Curator:: @ 8219866
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
	specialvar VAR_0x8004, CountPlayerContestPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting:: @ 82198BA
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer:: @ 82198C3
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament:: @ 82198EA
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
	givedecoration DECOR_GLASS_ORNAMENT
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament:: @ 8219911
	call Common_EventScript_NoRoomForDecor
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament:: @ 8219921
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting:: @ 821992B
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting:: @ 821993E
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting:: @ 8219951
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting:: @ 8219964
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting:: @ 8219977
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_Girl:: @ 821998A
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM:: @ 8219993
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy:: @ 821999C
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting:: @ 82199A5
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_MUSEUM_COOL
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting:: @ 82199B3
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_MUSEUM_BEAUTY
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting:: @ 82199C1
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_MUSEUM_CUTE
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting:: @ 82199CF
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_MUSEUM_SMART
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting:: @ 82199DD
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestwinner CONTEST_WINNER_MUSEUM_TOUGH
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall: @ 82199EB
	.string "This is our special exhibit hall.$"

LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall: @ 8219A0D
	.string "As you can plainly see, there is not\n"
	.string "a single painting on exhibit.\p"
	.string "Here, I don't wish to exhibit works of\n"
	.string "so-called classical art.\p"
	.string "Such classical works you can see on\n"
	.string "our ground floor.\p"
	.string "I wish to exhibit work that is far\n"
	.string "different from the classics.\p"
	.string "Art, after all, is not restricted to old,\n"
	.string "famous works!\p"
	.string "This exhibit hall, I wish to fill it with…\p"
	.string "Modern and vibrant artworks of\n"
	.string "POKéMON seemingly ready to spring\l"
	.string "forth into glorious life!$"

LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit: @ 8219BC4
	.string "I beg your pardon. I didn't intend\n"
	.string "to monopolize the conversation.\p"
	.string "Now, as you are young, and yet\n"
	.string "obviously well traveled…\p"
	.string "You must encounter lively POKéMON\n"
	.string "and works of art depicting them.\p"
	.string "If you were to come across such\n"
	.string "a painting, may we ask you to obtain\l"
	.string "the artist's permission to exhibit\l"
	.string "it here?$"

LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit: @ 8219CF3
	.string "I wish to fill this exhibit hall with\n"
	.string "modern and vibrant paintings of\l"
	.string "POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting: @ 8219D42
	.string "Thanks to you, we've added a new\n"
	.string "painting to our collection!\p"
	.string "I've heard it depicts your POKéMON.\n"
	.string "Truly magnificent!\p"
	.string "Thank you so very, very much!$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer: @ 8219DD4
	.string "Ah! It's you!\n"
	.string "{PLAYER}!$"

LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests: @ 8219DE6
	.string "Isn't this marvelous?\n"
	.string "This collection of paintings!\p"
	.string "Each one of them flawless!\n"
	.string "None better than another!\p"
	.string "These paintings have attracted\n"
	.string "more guests to our ART MUSEUM.\p"
	.string "Sincerely, I thank you, {PLAYER}.\n"
	.string "This is my dream come true!$"

LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude: @ 8219EC5
	.string "This is merely a token of my gratitude.$"

LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou: @ 8219EED
	.string "I will keep this for you until we\n"
	.string "meet again.$"

LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit: @ 8219F1B
	.string "Ah, so good to see you, {PLAYER}!\p"
	.string "It's an honor to have you visit us\n"
	.string "on your busy journeys.\p"
	.string "Please, relax and do enjoy your\n"
	.string "visit with us.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame: @ 8219FA0
	.string "It's a picture frame with pink-colored\n"
	.string "adornments.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame: @ 8219FD3
	.string "It's a picture frame with\n"
	.string "yellow-colored adornments.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame: @ 821A008
	.string "It's a picture frame with\n"
	.string "blue-colored adornments.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame: @ 821A03B
	.string "It's a picture frame with\n"
	.string "red-colored adornments.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame: @ 821A06D
	.string "It's a picture frame with\n"
	.string "green-colored adornments.$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon: @ 821A0A1
	.string "It's a painting of POKéMON.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe: @ 821A0BD
	.string "I've been away awhile, so the new\n"
	.string "paintings up here surprised me.\p"
	.string "I wish someone would paint my POKéMON\n"
	.string "this pretty.$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing: @ 821A132
	.string "Well… So this is where they show\n"
	.string "the topical POKéMON paintings.\p"
	.string "I see, these new paintings are indeed\n"
	.string "rather amusing.$"

LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon: @ 821A1A8
	.string "Wow, is that right?\n"
	.string "These paintings are of your POKéMON.\p"
	.string "Isn't that just the ultimate joy for\n"
	.string "a TRAINER?$"

