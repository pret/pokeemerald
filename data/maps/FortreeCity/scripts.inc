FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applywaitmovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Niemand gelooft me, maar ik zag\n"
	.string "een gigantische POKéMON in de lucht.\p"
	.string "Hij kronkelde terwijl hij naar\n"
	.string "ROUTE 131 vloog.\p"
	.string "Trouwens… Snuf…\n"
	.string "Eh… Jij, eh… ruikt verbrand.\p"
	.string "Was je bij een vulkaan of zo?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Ik wil naar de POKéMON GYM,\n"
	.string "maar er staat iets in de weg.\p"
	.string "Terwijl ik zo hard trainde\n"
	.string "op ROUTE 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "Mijn lievelings-POKéMON is bij me.\n"
	.string "Deze keer versla ik WINONA.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "De grond slurpt regenwater op en\n"
	.string "bomen groeien van dat water…\p"
	.string "Onze FORTREE CITY bestaat door\n"
	.string "water en aarde.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "De STAD heeft huizen in de bomen.\p"
	.string "Misschien daarom is iedereen\n"
	.string "gezond en vrolijk.\p"
	.string "Ik voel me zelf wel dertig jaar\n"
	.string "jonger!$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "In de bomen wonen is leuk.\p"
	.string "Maar soms komen INSECT-POKéMON\n"
	.string "door het raam.\l"
	.string "Dat is echt schrikken.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Sommige POKéMON evolueren als je\n"
	.string "ze ruilt! Dat heb ik gehoord.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Er staat iets onzichtbaars in de weg.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Er staat iets onzichtbaars in de weg.\p"
	.string "Wil je de DEVONKIJKER gebruiken?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} gebruikte de DEVONKIJKER.\p"
	.string "Een onzichtbare POKéMON werd\n"
	.string "helemaal zichtbaar!\p"
	.string "De POKéMON schrok en vluchtte weg!$"

FortreeCity_Text_CitySign:
	.string "FORTREE CITY\n"
	.string "“De stad in de boomtoppen,\l"
	.string "die speelt met de natuur.”$"

FortreeCity_Text_GymSign:
	.string "FORTREE CITY POKéMON GYM\n"
	.string "LEIDER: WINONA\p"
	.string "“De vogelfan die de wereld in\n"
	.string "vliegt.”$"

