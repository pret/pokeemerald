BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Hoi! Voor nieuws over de BATTLE\n"
	.string "FRONTIER ben ik nr. 1.\p"
	.string "Je mag me de FRONTIER MANIAC\n"
	.string "noemen.\p"
	.string "Even checken: jij bent een TRAINER,\n"
	.string "klopt dat?\p"
	.string "Ik deel graag het heetste nieuws\n"
	.string "over de BATTLE FRONTIER.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Hoi! Kom je me uithoren over het\n"
	.string "laatste nieuws? Oké, goed!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Nou? Nou? Nou?\p"
	.string "Mijn informatie is vast super\n"
	.string "nuttig voor je, hè?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Even kijken…\p"
	.string "Het lijkt erop dat de {STR_VAR_1}\n"
	.string "de allerleukste plek is.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Even kijken…\p"
	.string "Het lijkt erop dat BATTLE TOWER\n"
	.string "{STR_VAR_1} de leukste is.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Dit wist je vast niet!\p"
	.string "Een van de topTRAINERS die SCOTT\n"
	.string "de FRONTIER BRAINS noemt, is daar.\p"
	.string "Een mysterieuze TRAINER, de SALON\n"
	.string "MAIDEN, leidt die plek.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Heb je tegen de SALON MAIDEN\n"
	.string "gevochten?\p"
	.string "Als ze haar tegenstander inschat,\n"
	.string "gebruikt ze blijkbaar deze POKéMON:\p"
	.string "Een PSYCHISCH-type PSI-POKéMON,\n"
	.string "een VUUR-type VULKAAN-POKéMON,\l"
	.string "en een NORMAAL-type SLAAP-POKéMON.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Vocht je tegen de SALON MAIDEN\n"
	.string "als ze serieus is?\p"
	.string "Als ze alles geeft, gebruikt ze\n"
	.string "blijkbaar deze POKéMON:\p"
	.string "Een DRAAK & PSYCHISCH EON-POKéMON,\n"
	.string "een ELEKTRISCH-type DONDER-POKéMON,\l"
	.string "en een NORMAAL-type SLAAP-POKéMON.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Dit wist je vast niet!\p"
	.string "Een van de topTRAINERS die SCOTT\n"
	.string "de FRONTIER BRAINS noemt, is daar.\p"
	.string "Een opvallende TRAINER, de DOME ACE,\n"
	.string "leidt die plek.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Heb je tegen de DOME ACE gevochten?\p"
	.string "Als hij het rustig aandoet,\n"
	.string "gebruikt hij deze drie POKéMON:\p"
	.string "Een DRAAK & VLIEG DRAAK-POKéMON,\n"
	.string "een WATER & GROND MODDERVIS-POKéMON,\l"
	.string "en een VUUR & VLIEG VLAM-POKéMON.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Vocht je tegen de DOME ACE\n"
	.string "als hij serieus is?\p"
	.string "Als hij zijn strategie laat zien,\n"
	.string "gebruikt hij deze drie POKéMON:\p"
	.string "Een DRAAK & VLIEG EON-POKéMON,\n"
	.string "een WATER & GROND MODDERVIS-POKéMON,\l"
	.string "en een STAAL- & PSYCHISCH-type\l"
	.string "IJZERPOOT-POKéMON.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Dit wist je vast niet!\p"
	.string "Een van de topTRAINERS die SCOTT\n"
	.string "de FRONTIER BRAINS noemt, is daar.\p"
	.string "Een gekke TRAINER, de FACTORY HEAD,\n"
	.string "leidt die plek.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Heb je al tegen de FACTORY HEAD\n"
	.string "gevochten?\p"
	.string "Laat me denken… Voor een gevecht\n"
	.string "krijgt hij drie leen-POKéMON.\p"
	.string "Hij vecht onder bijna dezelfde\n"
	.string "regels als jij.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Vocht je tegen de FACTORY HEAD\n"
	.string "als hij serieus is?\p"
	.string "Als hij serieus vecht, krijgt hij nog\n"
	.string "steeds drie leen-POKéMON.\p"
	.string "Hij vecht onder bijna dezelfde\n"
	.string "regels als jij.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Dit wist je vast niet!\p"
	.string "Een van de topTRAINERS die SCOTT\n"
	.string "de FRONTIER BRAINS noemt, is daar.\p"
	.string "Een enge TRAINER, de PIKE QUEEN,\n"
	.string "leidt die plek.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Heb je al tegen de PIKE QUEEN\n"
	.string "gevochten?\p"
	.string "Als ze goed gezind is, gebruikt ze\n"
	.string "volgens het verhaal deze POKéMON:\p"
	.string "Een GIF-type TANDSLANG-POKéMON,\n"
	.string "een INSECT & STEEN SCHIMMEL-POKéMON,\l"
	.string "en een WATER-type TEDERE POKéMON.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Heb je tegen de PIKE QUEEN gevochten\n"
	.string "als ze serieus is?\p"
	.string "Als ze echt geïrriteerd is, gebruikt ze\n"
	.string "volgens het verhaal deze POKéMON:\p"
	.string "Een GIF-type TANDSLANG-POKéMON,\n"
	.string "een STAAL & GROND IJZERSLANG-POKéMON,\l"
	.string "en een WATER- & VLIEG-type\l"
	.string "AFSCHUWELIJKE POKéMON.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Dit wist je vast niet!\p"
	.string "Een van de topTRAINERS die SCOTT\n"
	.string "de FRONTIER BRAINS noemt, is daar.\p"
	.string "Een schattige TRAINER, de ARENA\n"
	.string "TYCOON, leidt die plek.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Heb je al tegen de ARENA TYCOON\n"
	.string "gevochten?\p"
	.string "Als ze de kracht van de vijand\n"
	.string "inschat, gebruikt ze deze POKéMON:\p"
	.string "Een INSECT & VECHT EENHOORN-POKéMON,\n"
	.string "een DUISTER-type MAANLICHT-POKéMON,\l"
	.string "en een INSECT & GEEST VELL-POKéMON.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Vocht je tegen de ARENA TYCOON\n"
	.string "als ze serieus is?\p"
	.string "Als ze om te winnen vecht,\n"
	.string "gebruikt ze deze POKéMON:\p"
	.string "Een DUISTER-type MAANLICHT-POKéMON,\n"
	.string "een GEEST & GIF SCHADUW-POKéMON\l"
	.string "en een GRAS- & VECHT-type\l"
	.string "PADDENSTOEL-POKéMON.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Dit wist je vast niet!\p"
	.string "Een van de topTRAINERS die SCOTT\n"
	.string "de FRONTIER BRAINS noemt, is daar.\p"
	.string "Een onheilspellende TRAINER, de PALACE\n"
	.string "MAVEN, leidt die plek.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Heb je al tegen de PALACE MAVEN\n"
	.string "gevochten?\p"
	.string "Als hij de geest van de vijand test,\n"
	.string "gebruikt hij deze POKéMON:\p"
	.string "Een GIF & VLIEG-type VLEERMUIS-\n"
	.string "POKéMON, een NORMAAL-type LUIE\l"
	.string "POKéMON en een WATER- & IJS-type\l"
	.string "VERVOER-POKéMON.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Vocht je tegen de PALACE MAVEN\n"
	.string "als hij serieus is?\p"
	.string "Als hij al zijn kracht inzet,\n"
	.string "gebruikt hij deze POKéMON:\p"
	.string "Een VUUR-type LEGENDARISCHE POKéMON,\n"
	.string "een NORMAAL-type LUIE POKéMON\l"
	.string "en een WATER-type AURORA-POKéMON.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Dit wist je vast niet!\p"
	.string "Een van de topTRAINERS die SCOTT\n"
	.string "de FRONTIER BRAINS noemt, is daar.\p"
	.string "Een vurige TRAINER, de PYRAMID KING,\n"
	.string "leidt die plek.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Heb je al tegen de PYRAMID KING\n"
	.string "gevochten?\p"
	.string "Als hij de kracht van de vijand\n"
	.string "checkt, gebruikt hij deze POKéMON:\p"
	.string "Een STEEN-type BERGTOP-POKéMON,\n"
	.string "een IJS-type IJSBERG-POKéMON,\l"
	.string "en een STAAL-type IJZER-POKéMON.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Vocht je tegen de PYRAMID KING\n"
	.string "als hij serieus is?\p"
	.string "Als hij vol hete kracht zit,\n"
	.string "gebruikt hij deze POKéMON:\p"
	.string "Een IJS & VLIEG VRIES-POKéMON,\n"
	.string "een ELEKTRISCH & VLIEG ELEKTRISCH-\l"
	.string "POKéMON en een VUUR- & VLIEG-type\l"
	.string "VLAM-POKéMON.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Er zijn meerdere plekken waar je\n"
	.string "DUBBELE GEVECHTEN kunt doen.\p"
	.string "Maar de DUBBEL GEVECHT-KAMERS van\n"
	.string "de BATTLE TOWER zijn de basis!\p"
	.string "Daar leer je hoe DUBBELE GEVECHTEN\n"
	.string "hier in de BATTLE FRONTIER werken.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Pas op in de gevechten hier.\p"
	.string "Ik hoor dat er TRAINERS zijn met\n"
	.string "strategieën die ze speciaal voor\l"
	.string "DUBBELE GEVECHTEN bedachten.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Als je goed bent in DUBBELE GEVECHTEN\n"
	.string "hier, kun je ook andere plekken met\l"
	.string "DUBBELE GEVECHTEN proberen.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Alle soorten TRAINERS komen naar\n"
	.string "de BATTLE SALON.\p"
	.string "Stel je voor--je ontmoet misschien\n"
	.string "je vrienden of fans!\l"
	.string "Kijk goed rond!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Als je met een vriend bent, ga dan\n"
	.string "naar de LINK MULTI-GEVECHTSKAMER.\p"
	.string "Als je met een sterke vriend speelt,\n"
	.string "krijg je sterke tegenstanders!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Wat een geweldige nieuwsneus!\n"
	.string "Mijn mentor is uniek!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Wat een geweldig oog voor detail!\n"
	.string "Mijn mentor is uniek!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Wat een geweldige overtuigingskracht!\n"
	.string "Mijn mentor is uniek!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…Wat is dit voor een plek?\n"
	.string "Ik word er bang van…$"

