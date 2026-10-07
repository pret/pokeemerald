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
	.string "Mijn POKéMON krijgen bijnamen die\n"
	.string "perfect bij ze passen!\p"
	.string "Zo laat ik zien hoe, eh…\n"
	.string "origineel ik ben, ja, precies!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Maar een PIKACHU PEKACHU noemen?\n"
	.string "Dat slaat toch nergens op.\p"
	.string "Een naam die je snel snapt is\n"
	.string "wel handig, maar…$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"

