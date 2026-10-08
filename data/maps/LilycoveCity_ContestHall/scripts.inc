@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applywaitmovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Deze POKéMON won eerder de\n"
	.string "MOOI-WEDSTRIJD hier.\p"
	.string "En weet je? Vandaag liet ik hem een\n"
	.string "SLIM-WEDSTRIJD winnen!\p"
	.string "Mijn talent maakt mezelf bang…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Ik deed aan een hoop WEDSTRIJDEN\n"
	.string "mee, om te zien hoe het werkt.\p"
	.string "In een STOER-WEDSTRIJD is een stoere\n"
	.string "aanval een goed optreden.\p"
	.string "Maar slimme en schattige aanvallen\n"
	.string "gaan bijvoorbeeld niet zo goed.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Die jongen die eerder won had\n"
	.string "veel verschillende {POKEBLOCK}S.\p"
	.string "Kun je winnen als je er zoveel\n"
	.string "hebt?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Wauw, wat is het hier enorm!\p"
	.string "De spanning in de lucht… Dit is geen\n"
	.string "WEDSTRIJDHAL in een gehucht.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC: Oké, SLIMME POKéMON en hun\n"
	.string "TRAINERS, zijn jullie klaar?!\p"
	.string "Doe je best!\n"
	.string "Op naar het optreden!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "JURY: Vind je deze WEDSTRIJD leuk?\p"
	.string "Kom terug met drie vrienden, dan\n"
	.string "kunnen jullie samen meedoen!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ayayayay…\n"
	.string "Ik deed mee aan de verkeerde\l"
	.string "WEDSTRIJD.\p"
	.string "Ik gaf deze sterke POKéMON op voor\n"
	.string "de SLIM-WEDSTRIJD…\p"
	.string "Kom op, versteld ze met een\n"
	.string "slim ogende STEENBREKER.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Ik heb vele jaren en al mijn\n"
	.string "wijsheid gestoken in het slim\l"
	.string "opvoeden van deze POKéMON.\p"
	.string "Hij wordt niet zomaar verslagen\n"
	.string "door de POKéMON van een jonkie.\p"
	.string "Mijn lieve vrouw, zie je dit?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Daar is het!\p"
	.string "Als mijn POKéMON nu een slimme\n"
	.string "aanval doet, juicht het publiek!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Oh jee, nee!\p"
	.string "De LEVENSZUIGER van mijn ZUBAT is\n"
	.string "zo schattig, ik bleef hem gebruiken!\p"
	.string "Maar deze gemene mensen vinden\n"
	.string "het helemaal niks!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah! Je bent mooi, opa!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Ook als TRAINERS dezelfde POKéMON\n"
	.string "opgeven, doen ze allemaal andere\l"
	.string "aanvallen voor hun optreden.\p"
	.string "Net zoals mensen verschillende\n"
	.string "stijlen hebben bij het vechten.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Ik vind de POKéMON slimmer\n"
	.string "lijken dan hun TRAINERS. Veel slimmer.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Toch hou ik nog het meest van\n"
	.string "SLIM-WEDSTRIJDEN.\p"
	.string "Die slimme groene kleur…\n"
	.string "Zo… Zo… Gaaf.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC: Doe je ook mee aan de\n"
	.string "MOOI-WEDSTRIJD? Succes!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "JURY: Ah, elke POKéMON hier is een\n"
	.string "voorbeeld van pure schoonheid!\p"
	.string "Ik vergat bijna de punten te geven!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Een POKéMON zo mooi…\n"
	.string "Er is er geen tweede zoals hij.\p"
	.string "Iedereen blijft naar mijn\n"
	.string "schoonheid kijken.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaah!\p"
	.string "Ik heb mijn POKéMON voor deze\n"
	.string "WEDSTRIJD netjes geborsteld…\p"
	.string "Maar ik overdreef…\n"
	.string "Zijn vacht zit nu helemaal in de war…\p"
	.string "Wat moet ik doen?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Dit NOORDERLICHT is zo\n"
	.string "verblindend, dat de JURY niets ziet.\p"
	.string "Eh, wacht even…\n"
	.string "Dan heeft het geen zin!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Deze mooie POKéMON lijkt op\n"
	.string "mij toen ik jonger was.\p"
	.string "Toen ik dat zei, spuugde mijn man\n"
	.string "zijn koffie uit.\p"
	.string "Zei ik iets grappigs?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Als ik een MOOI-WEDSTRIJD win,\n"
	.string "ben ik blij.\l"
	.string "Nog blijer dan anders.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah!\p"
	.string "Kijk eens naar al die mooie\n"
	.string "POKéMON!\l"
	.string "Ik hou van zulke pracht!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Alleen mooi zijn is niet genoeg\n"
	.string "om te winnen.\p"
	.string "Borstel je POKéMON, zodat hij\n"
	.string "glanst zoals de mijne.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC: Oeps! Hallo!\n"
	.string "We zitten midden in een WEDSTRIJD!\p"
	.string "Meld je aan bij de balie en kom\n"
	.string "naar buiten, oké?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "JURY: Oh, wat een charmante en\n"
	.string "schattige optredens!\p"
	.string "Oh jee! Wat een schattig\n"
	.string "WATERSPORT-optreden!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh nee… Mijn lieve AZURILL werd\n"
	.string "afgeleid door een andere POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Mijn POKéMON won nog nooit een\n"
	.string "gevecht, maar in een WEDSTRIJD…!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "De BLAADJESDANS van mijn POKéMON\n"
	.string "is een wonder van sierlijkheid.\p"
	.string "Niemand mag zijn optreden\n"
	.string "verstoren.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Alle POKéMON zijn heel schattig.\p"
	.string "Maar als mijn POKéMON schattig\n"
	.string "optreedt…\p"
	.string "Dan is hij vast veel schattiger\n"
	.string "dan de rest.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Mijn kind doet mee aan deze\n"
	.string "WEDSTRIJD.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Kom op, schat. Zet 'm op!\n"
	.string "Jouw POKéMON is de beste!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Dat meisje daar is volgens mij\n"
	.string "de schattigste van allemaal.\p"
	.string "Wat? Beoordelen ze POKéMON op\n"
	.string "hun uiterlijk?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Oh, al die schattige POKéMON,\n"
	.string "ik wil er ook een!\p"
	.string "Ik ga er een vangen!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "MOOI-WEDSTRIJD PODIUM\n"
	.string "WORD BEZOCHT DOOR MOOIE POKéMON!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "SCHATTIG-WEDSTRIJD PODIUM\n"
	.string "WORD BEZOCHT DOOR SCHATTIGE POKéMON!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "SLIM-WEDSTRIJD PODIUM\n"
	.string "WORD BEZOCHT DOOR SLIMME POKéMON!$"

