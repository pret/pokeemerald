RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Moi, à mes POKéMON, je leur donne\n"
	.string "des surnoms très appropriés!\p"
	.string "C’est l’expression de, euh…\n"
	.string "mon originalité, oui, c’est ça!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Mais surnommer PEKACHU un PIKACHU,\n"
	.string "ça ne rime à rien.\p"
	.string "C’est sûrement bien d’utiliser un nom\n"
	.string "facile à comprendre, mais de là à…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"

