PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Jij bent…\n"
	.string "Ah, jij moet {PLAYER}{KUN} zijn, toch?\p"
	.string "Bedankt dat je net met WALLY\n"
	.string "hebt gespeeld.\p"
	.string "Hij is al sinds hij een baby was\n"
	.string "zwak en vaak ziek.\p"
	.string "Hij gaat een tijdje logeren bij\n"
	.string "familie in VERDANTURF TOWN.\p"
	.string "Daar is de lucht veel schoner\n"
	.string "dan hier.\p"
	.string "Wat zeg je? Waar WALLY is?\n"
	.string "Hij is al vertrokken, onze WALLY.\p"
	.string "Waar zou hij nu\n"
	.string "zijn?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Hoe zou het met onze WALLY gaan?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN}! Sorry dat we je zo\n"
	.string "hierheen hebben gehaald.\p"
	.string "Maar onze WALLY is veel gezonder\n"
	.string "sinds hij in VERDANTURF TOWN woont.\p"
	.string "Dat komt allemaal door jou!\p"
	.string "Toen WALLY wegging, hielp jij hem\n"
	.string "een POKéMON te vangen, toch?\p"
	.string "Daar was WALLY heel blij mee.\p"
	.string "En niet alleen WALLY.\n"
	.string "Ik, zijn vader, ben ook blij.\p"
	.string "Blij dat hij zo'n goede vriend\n"
	.string "heeft als jij.\p"
	.string "Het is geen omkoping of zo, maar\n"
	.string "ik wil je dit graag geven.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Als je POKéMON kan SURFEN, kun je\n"
	.string "naar allerlei plekken gaan.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "WALLY komt snel weer thuis.\n"
	.string "Daar verheug ik me op.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "O? Heb je WALLY gezien in\n"
	.string "EVER GRANDE CITY?\p"
	.string "Ach, {PLAYER}{KUN}, doe niet zo gek.\p"
	.string "Hij is wel gezonder, maar hij kan\n"
	.string "nog niet zo ver weg alleen\l"
	.string "naartoe gaan.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "WALLY was echt blij toen hij vertelde\n"
	.string "dat hij een POKéMON had gevangen.\p"
	.string "Ik heb hem in jaren niet zo\n"
	.string "zien lachen.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Vertel dit niet aan mijn man…\p"
	.string "Maar onze WALLY is weggegaan uit\n"
	.string "VERDANTURF TOWN zonder iets te zeggen.\p"
	.string "WALLY is wel zwak, maar hij heeft\n"
	.string "een sterke wil.\p"
	.string "Ik weet zeker dat hij ooit\n"
	.string "veilig terugkomt!$"

