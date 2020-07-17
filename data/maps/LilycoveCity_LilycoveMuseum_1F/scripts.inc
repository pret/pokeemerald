.set LOCALID_CURATOR, 2
.set LOCALID_ARTIST_2, 8

LilycoveCity_LilycoveMuseum_1F_MapScripts:: @ 8218CB8
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter:: @ 8218CB9
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator:: @ 8218CC2
	lockall
	applymovement LOCALID_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet:: @ 8218CEC
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings:: @ 8218CF5
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested:: @ 8218D14
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings:: @ 8218D1E
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth:: @ 8218D5A
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest:: @ 8218D6F
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast:: @ 8218D84
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 255, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs: @ 8218D99
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest: @ 8218D9B
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast: @ 8218D9E
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth: @ 8218DA1
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting:: @ 8218DA4
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting:: @ 8218DAD
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting:: @ 8218DB6
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting:: @ 8218DBF
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting:: @ 8218DC8
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting:: @ 8218DD1
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture:: @ 8218DDA
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture:: @ 8218DE3
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet:: @ 8218DEC
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM:: @ 8218DF5
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1:: @ 8218DFE
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy:: @ 8218E07
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1:: @ 8218E10
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2:: @ 8218E19
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM:: @ 8218E22
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2:: @ 8218E2B
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan:: @ 8218E42
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum: @ 8218E4B
	.string "Welcome to LILYCOVE MUSEUM.\p"
	.string "Please take the time to enjoy our\n"
	.string "collection of fantastic artwork\l"
	.string "featuring POKéMON.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings: @ 8218EBC
	.string "I'm the CURATOR of this MUSEUM of\n"
	.string "fine arts.\p"
	.string "It's heartening to see someone so\n"
	.string "young as you in our MUSEUM.\p"
	.string "Have you viewed our collection of\n"
	.string "paintings already?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime: @ 8218F5C
	.string "Ah, then let me not disturb you.\n"
	.string "Please, do take your time.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings: @ 8218F98
	.string "Oh? I do believe that you seem to\n"
	.string "be a POKéMON TRAINER.\p"
	.string "Have you an interest in paintings,\n"
	.string "too?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat: @ 8218FF8
	.string "I see…\p"
	.string "I'm honored that you would visit\n"
	.string "us in spite of that.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe: @ 8219035
	.string "Ah, excellent!\n"
	.string "You do like paintings!\p"
	.string "Then, may I ask you to come with me?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting: @ 8219080
	.string "It's a very old painting.\n"
	.string "The paint is peeling here and there.$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery: @ 82190BF
	.string "It's an odd landscape with bizarre\n"
	.string "and fantastic scenery.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman: @ 82190F9
	.string "It's a painting of a beautiful, smiling\n"
	.string "woman with a POKéMON on her lap.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon: @ 8219142
	.string "It's a painting of a legendary POKéMON\n"
	.string "from long ago.\p"
	.string "The artist painted this from\n"
	.string "imagination.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon: @ 82191A2
	.string "It's a painting of GRASS POKéMON\n"
	.string "swaying in a breeze.\p"
	.string "They appear to be enjoying the wind's\n"
	.string "gentle caress.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries: @ 821920D
	.string "It's a delicious-looking painting\n"
	.string "of BERRIES.\p"
	.string "This painting could make you hungry!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica: @ 8219260
	.string "It's a replica of a famous sculpture.\p"
	.string "It depicts an ancient BIRD POKéMON.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone: @ 82192AA
	.string "It's a big POKé BALL carved from\n"
	.string "a black stone.\p"
	.string "It was apparently used in festivals\n"
	.string "in the olden days.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText: @ 8219311
	.string "It's a huge stone tablet inscribed\n"
	.string "with POKéMON and dense text in the\l"
	.string "small characters of an ancient,\l"
	.string "unreadable language.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence: @ 821938C
	.string "Hmmm…\n"
	.string "What works of great magnificence…$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts: @ 82193B4
	.string "Battling with POKéMON is fun,\n"
	.string "I'll grant you that.\p"
	.string "But one mustn't forget our love for\n"
	.string "the fine arts.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration: @ 821941A
	.string "This ART MUSEUM… Well, you could\n"
	.string "see many fantastic paintings.\p"
	.string "And the CURATOR is a wonderful person.\p"
	.string "Among artists like myself, this MUSEUM\n"
	.string "is an inspiration.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty: @ 82194BA
	.string "This lady is pretty!\n"
	.string "She's like Mommy!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable: @ 82194E1
	.string "This POKéMON is adorable!\n"
	.string "Just like our little boy!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings: @ 8219515
	.string "I'd heard that this ART MUSEUM got\n"
	.string "in some new paintings.\p"
	.string "So, naturally I hurried over.\p"
	.string "Are the new paintings up on\n"
	.string "the second floor?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful: @ 821959B
	.string "Lately, the CURATOR has been\n"
	.string "unusually cheerful.\p"
	.string "I bet something good happened for him.\n"
	.string "Definitely.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings: @ 82195FF
	.string "I aim to see many great paintings\n"
	.string "here and learn from them.\p"
	.string "I have this dream of one day having\n"
	.string "my artwork exhibited here.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination: @ 821967A
	.string "The ART MUSEUM has become a favorite\n"
	.string "tourist destination.\p"
	.string "It's great for LILYCOVE…\n"
	.string "No, great for the HOENN region!\p"
	.string "This is what I've heard--a lone TRAINER\n"
	.string "procured all the paintings upstairs.$"

