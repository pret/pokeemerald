MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Herinneringen aan mijn lieve\n"
	.string "SKITTY… Mijn ogen lopen vol.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Au, au… Er zitten gaten in de\n"
	.string "grond hier en daar.\p"
	.string "Ik zag het niet en viel van\n"
	.string "de verdieping erboven.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hé! Zoek je POKéMON?\n"
	.string "Je kwam achter me aan! Onbeleefd!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ayieeeeh!\n"
	.string "Sorry, vergeef me, alsjeblieft!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Mensen komen hier niet vaak, dus\n"
	.string "ik dacht dat er zeldzame POKéMON waren.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE: We zijn hier voor een\n"
	.string "uitdaging.\p"
	.string "Hehe, als ik laat zien hoe stoer\n"
	.string "ik ben, wordt ze verliefd. Echt!\p"
	.string "Ik weet het! Ik verpletter je en\n"
	.string "laat haar zien hoe stoer ik ben!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE: Oeps!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE: Nou, we verloren, maar dat\n"
	.string "is oké! Ik sta naast je.\l"
	.string "We halen deze uitdaging wel!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE: Wil je met me vechten,\n"
	.string "neem dan meer POKéMON mee.\p"
	.string "Anders kan ik mijn meisje niet\n"
	.string "laten zien hoe stoer ik ben!$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ: Ik kwam hier voor een\n"
	.string "uitdaging met mijn vriend.\p"
	.string "Het is echt eng, maar ik ben bij\n"
	.string "mijn vriend. Dat is oké.\p"
	.string "Ik weet het! Mijn vriend wordt\n"
	.string "stoer door jou te verslaan!$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ: Waaaah! Ik ben bang!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ: We zijn verliefd, dus het\n"
	.string "maakt niet uit dat we verloren!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ: Wil je ons uitdagen, neem dan\n"
	.string "minstens twee POKéMON mee.\p"
	.string "Mijn vriend is sterk.\n"
	.string "Eén POKéMON is echt niet genoeg.$"

MtPyre_2F_Text_LeahIntro:
	.string "Je bent hier vreemd…\n"
	.string "Ga weg voordat je iets overkomt!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm…\n"
	.string "Je bent taai.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Onze familie is hier TRAINER\n"
	.string "sinds mijn overgrootmoeder…\p"
	.string "Het is mijn plicht deze berg\n"
	.string "te beschermen…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiyaaaaah!\n"
	.string "Ik ben doodsbang!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Neeeeeee!\n"
	.string "Ik ben mijn verstand kwijt!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Ik schrik van alles wat beweegt…\p"
	.string "Ik had hier niet moeten komen\n"
	.string "trainen…$"

