BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applywaitmovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitse
	playse SE_SUDOWOODO_SHAKE
	applywaitmovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "Dit is de BATTLE TOWER!\n"
	.string "Blijf winnen als sterkste\l"
	.string "TRAINER!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "Dit is het BATTLE PALACE!\n"
	.string "Hou POKéMON-gevechten in de gaten!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "Dit is de BATTLE ARENA!\n"
	.string "Laat de sterkste teams komen!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "Dit is de BATTLE PYRAMID!\n"
	.string "Ga vooruit met de GEVECHTSTOCHT!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "BATTLE FRONTIER RANKING HALL\n"
	.string "Richt je op nieuwe records!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "GEVECHTSPUNTEN-RUILHOEK\n"
	.string "Ruil je GEVECHTSPUNTEN in!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Wow!\n"
	.string "Hij is enorm!\p"
	.string "De BATTLE TOWER voelt speciaal.\n"
	.string "Anders dan de rest.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Mijn grote droom is de BATTLE\n"
	.string "FRONTIER én de POKéMON LEAGUE\l"
	.string "te veroveren.\p"
	.string "En als mijn droom uitkomt…\p"
	.string "Dan… dan vraag ik MIMI hiernaast\n"
	.string "of ze mijn vriendin wil zijn!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "De BATTLE PYRAMID is te zwaar!\n"
	.string "Ik kom maar niet bovenaan!\p"
	.string "Omdat ik niets anders meer weet,\n"
	.string "klim ik misschien buitenom…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Ik gedij in het donker…\n"
	.string "Ja… Wat past bij mij?\l"
	.string "Alleen de BATTLE PYRAMID…\p"
	.string "Wat vind je van ronddwalen in het\n"
	.string "donker, in totale wanhoop?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Ik sliep een week niet, maar toen\n"
	.string "maakte ik het ultieme team!\p"
	.string "Ik kan niet verliezen, echt waar.\n"
	.string "We stormen de BATTLE ARENA in!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Heeft SCOTT jou hier ook gebracht?\n"
	.string "Wat is er met die kerel?\p"
	.string "Hij kan blijkbaar goed getalenteerde\n"
	.string "TRAINERS vinden, maar…\p"
	.string "Ik heb hem nog nooit zelf zien\n"
	.string "vechten.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG!\n"
	.string "Ik geloof in je, vriendje!\p"
	.string "Als je wint, maak ik je favoriete\n"
	.string "lekkernijen, mijn kleine ZIGG!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON kijkt wezenloos…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Mensen noemen me bemoeial,\n"
	.string "maar ik kan er niets aan doen.\p"
	.string "Je hoed zit scheef!\n"
	.string "Oh nee, afval op de grond!\l"
	.string "Oeps, het is bijna etenstijd!\p"
	.string "Ik weet niet of ik kan blijven\n"
	.string "kijken bij het BATTLE PALACE…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Ik zie er nu niet indrukwekkend\n"
	.string "uit, maar ik versloeg ooit een\l"
	.string "GYMLEIDER.\p"
	.string "Wie weet, probeer ik het nog eens\n"
	.string "voor de eer.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Ik ben snel op mijn FIETS, en dat\n"
	.string "geldt ook voor mijn gevechten.\p"
	.string "Ik win in een oogwenk!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Ik ben beter dan mijn papa\n"
	.string "in POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Ga maar, mijn schatje!\n"
	.string "Win maar veel voor papa!\p"
	.string "Je bent net als je moeder,\n"
	.string "dus je gaat winnen!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Het was niet makkelijk om hier te\n"
	.string "komen, maar ik hoorde van een\l"
	.string "prachtig meisje bij de BATTLE ARENA.\p"
	.string "Weet je wat ik in plaats daarvan\n"
	.string "vond?\p"
	.string "Een hele meute zweterige, stinkende\n"
	.string "en primitieve vechtsporters!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Soms zie ik een heel belangrijk\n"
	.string "uitziende oude man daar naar binnen.\p"
	.string "Hij heeft supergave POKéMON.\n"
	.string "Hij lijkt wel heel aardig.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Ken je het?\n"
	.string "De legende van de BATTLE PYRAMID?\p"
	.string "Als een zelfverzekerde TRAINER naar\n"
	.string "de gouden top reikt,\l"
	.string "verschijnt er een man onder de mannen.\p"
	.string "Ken je die legende niet?\n"
	.string "Natuurlijk niet!\l"
	.string "Ik verzon hem net!\p"
	.string "Wat het moet betekenen?\n"
	.string "Dat, mijn vriend, weet ik niet!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Man! Oh man!\n"
	.string "Ik had nog nooit verloren!\p"
	.string "Maar ik werd helemaal weggevaagd,\n"
	.string "zonder enige genade!\p"
	.string "En dan zeggen ze dat ik geen\n"
	.string "talent heb?! Man!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Deze kerel kwam een verschrikkelijk\n"
	.string "sterke TRAINER tegen bij de BATTLE\l"
	.string "TOWER-uitdaging.\p"
	.string "Kijk hem nu…\p"
	.string "Wees voorzichtig als je naar de\n"
	.string "BATTLE TOWER gaat.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Ja!\n"
	.string "Eindelijk genoeg GEVECHTSPUNTEN!\p"
	.string "Ik ruil ze voor weer een\n"
	.string "gigantische knuffel-POP!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Oh ja, oké!\n"
	.string "Dit is dus de RANKING HALL!\p"
	.string "Ik wil de geschiedenis in als\n"
	.string "superkampioen, met mijn naam\l"
	.string "hier voor altijd vastgelegd.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Met jou aan mijn zijde kan ik alles.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ooh, schatje, je bent zo geweldig!\p"
	.string "Ooh, ik kan niet langer wachten!\p"
	.string "Laten we meteen naar een\n"
	.string "MULTI-GEVECHTSKAMER gaan!\p"
	.string "Als we in de BATTLE SALON samen\n"
	.string "zijn, wint de kracht van onze liefde\l"
	.string "van iedereen die we ontmoeten.\p"
	.string "Kijk, schatje, voor ons valt alles\n"
	.string "om als dominostenen!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "De BATTLE FRONTIER is niet alleen\n"
	.string "voor sterke TRAINERS.\p"
	.string "Er zijn veel mensen met speciale\n"
	.string "talenten uitgenodigd, lijkt het.\p"
	.string "Die SCOTT…\p"
	.string "Misschien bouwde hij deze plek voor\n"
	.string "een groter doel…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Pardon, jongeling.\n"
	.string "Heb je goede ogen?\p"
	.string "Daarachter staat een vreemde boom en\n"
	.string "voor mijn vermoeide ogen lijkt\l"
	.string "hij te wiebelen.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Pardon, jongeling.\n"
	.string "Heb je een goed geheugen?\p"
	.string "Ik heb het gevoel dat daarachter\n"
	.string "vroeger een vreemde boom stond.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Ik…\n"
	.string "Ik zag het!\p"
	.string "Er was een kleverige POKéMON\n"
	.string "met een lange staart daarvoor!\p"
	.string "Hij zat onder een rotsblok en\n"
	.string "bleef maar naar me staren!$"
