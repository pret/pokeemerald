MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceUp
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Nee! Die schurken van TEAM MAGMA\n"
	.string "zijn ons voor!\p"
	.string "We mogen niet achterlopen!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Ik dacht dat je een van de\n"
	.string "MAGMA's was die terugkwam…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Ja, je bent sterk…\n"
	.string "Maar wij zijn met velen!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah!\n"
	.string "Pech voor jou!\p"
	.string "Als je eerder kwam, had je alleen\n"
	.string "de watjes van TEAM MAGMA gehad.\p"
	.string "Maar nu moet je tegen\n"
	.string "ons, de stoere types!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Argh… Ik had je eerst tegen\n"
	.string "TEAM MAGMA moeten laten vechten…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Je weet er niets van!\n"
	.string "Waarom bemoei je je met ons?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Jij…\n"
	.string "We zagen je bij MT. CHIMNEY.\p"
	.string "Je hoort bij geen van beide TEAMS,\n"
	.string "waarom ben je dan hier?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Als je je ergens mee bemoeit,\n"
	.string "laat het dan TEAM MAGMA zijn…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, het maakt niet uit!\n"
	.string "We wonnen wat tijd!\p"
	.string "De BAAS heeft vast gepakt\n"
	.string "wat hij wilde!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, ik weet het!\n"
	.string "Je wilde bij TEAM MAGMA, maar\l"
	.string "ze wilden je niet!\p"
	.string "Denk maar niet dat jij bij ons\n"
	.string "TEAM AQUA mag!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Als je zo graag bij TEAM AQUA wilt,\n"
	.string "kunnen we erover denken…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Wij zijn een topteam, met onze\n"
	.string "leden en onze leider.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIE: MAXIE van TEAM MAGMA was ons\n"
	.string "voor, maar wij kregen ook wat we wilden.\p"
	.string "De RODE BOL van MT. PYRE…\n"
	.string "Ik, ARCHIE, heb hem nu!\p"
	.string "Fufufu… Nu kunnen we ons\n"
	.string "grootste doel bereiken!\p"
	.string "Oké, TEAM!\n"
	.string "We trekken ons terug!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh nee…\n"
	.string "Dit mag niet gebeuren…\p"
	.string "Niet alleen de BLAUWE BOL, maar\n"
	.string "ook de RODE BOL is gestolen…\p"
	.string "De BLAUWE BOL en RODE BOL mogen\n"
	.string "nooit gescheiden worden.\p"
	.string "Wat willen die mannen met de\n"
	.string "twee BOLLEN?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "O ja. Was het TEAM MAGMA dat\n"
	.string "eerst de BLAUWE BOL kwam pakken?\p"
	.string "In hun haast lieten ze dit\n"
	.string "achter.\p"
	.string "Ik kan me niet voorstellen\n"
	.string "wat het is.\p"
	.string "Je mag het hebben.\n"
	.string "Misschien is het ergens goed voor.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "De BLAUWE BOL en RODE BOL zijn\n"
	.string "genomen door die sinistere mannen…\p"
	.string "Ze mogen nooit gescheiden zijn…\n"
	.string "Ik vrees dat er iets ergs gebeurt…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Oh jee…\p"
	.string "Zeg je dat zowel GROUDON als\n"
	.string "KYOGRE wakker zijn?\p"
	.string "Men zegt dat de BLAUWE BOL en de\n"
	.string "RODE BOL de woede van die twee\l"
	.string "POKéMON temden…\p"
	.string "Men zegt ook dat de ware eigenaar\n"
	.string "van de BOLLEN nog bestaat.\p"
	.string "Maar niemand weet wie of wat\n"
	.string "de eigenaar van de BOLLEN is.\p"
	.string "Het kan een mens zijn, of een\n"
	.string "POKéMON, maar niemand weet het.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "De twee mannen die de BOLLEN namen,\n"
	.string "brachten ze zelf terug.\p"
	.string "Die mannen…\n"
	.string "Misschien zijn ze toch niet zo slecht…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "De belichamingen van land, zee\n"
	.string "en lucht…\p"
	.string "Dat zouden de oeroude POKéMON\n"
	.string "zijn…\p"
	.string "Net zoals wij mensen en POKéMON\n"
	.string "leven, leeft ook onze wereld…\p"
	.string "Dat leerden de oeroude POKéMON\n"
	.string "ons…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "Op MT. PYRE kalmeren we de geesten\n"
	.string "van overleden POKéMON…\p"
	.string "Dit is een hoge plek waar je\n"
	.string "heel HOENN kunt zien…\p"
	.string "De geesten van POKéMON moeten\n"
	.string "hier rust vinden…\p"
	.string "Is het toeval dat je hier bent…\p"
	.string "Wil je mijn verhaal horen? Een\n"
	.string "verhaal uit HOENN van lang geleden?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Het was lang, lang geleden…\p"
	.string "De wereld werd verscheurd door een\n"
	.string "wilde strijd tussen de POKéMON van\l"
	.string "het land en die van de zee…\p"
	.string "De POKéMON van het land maakten\n"
	.string "bergen en continenten…\p"
	.string "De POKéMON van de zee maakten\n"
	.string "reuzegolven en oceanen…\p"
	.string "Hun felle strijd ging eindeloos door.\p"
	.string "De wereld stond in vuur en vlam\n"
	.string "en werd geteisterd door stormen.\p"
	.string "De BLAUWE BOL en de RODE BOL\n"
	.string "maakten een einde aan de ramp.\p"
	.string "Licht stroomde uit de twee BOLLEN\n"
	.string "en kalmeerde de woedende vijanden.\p"
	.string "Het tweetal, tam geworden, dook\n"
	.string "diep de zee in en verdween\l"
	.string "uiteindelijk…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Ik begrijp het…\n"
	.string "Nou, dat is ook goed…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Het is mijn taak de legendes van\n"
	.string "HOENN door te geven.\p"
	.string "En de crisis die net eindigde in\n"
	.string "SOOTOPOLIS herschreef een legende…\p"
	.string "Heb je tijd om de nieuwe legende\n"
	.string "van HOENN te horen?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Het was lang, lang geleden…\p"
	.string "De wereld werd verscheurd door een\n"
	.string "wilde strijd tussen de POKéMON van\l"
	.string "het land en die van de zee…\p"
	.string "De POKéMON van het land maakten\n"
	.string "bergen en continenten…\p"
	.string "De POKéMON van de zee maakten\n"
	.string "reuzegolven en oceanen…\p"
	.string "Hun felle strijd ging eindeloos door.\p"
	.string "De wereld stond in vuur en vlam\n"
	.string "en werd geteisterd door stormen.\p"
	.string "Toen daalde de POKéMON van de lucht\n"
	.string "neer uit een storm.\p"
	.string "De POKéMON, fel groen glanzend,\n"
	.string "kalmeerde de twee woedende POKéMON.\p"
	.string "Toen vloog de groene POKéMON,\n"
	.string "zijn taak klaar, weg in de blauwe lucht…$"

