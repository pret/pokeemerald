Route111_OldLadysRestStop_MapScripts:: @ 822A916
	map_script 3, Route111_OldLadysRestStop_MapScript1_22A91C
	.byte 0

Route111_OldLadysRestStop_MapScript1_22A91C: @ 822A91C
	setflag FLAG_0x8A1
	end

Route111_OldLadysRestStop_EventScript_22A920:: @ 822A920
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_22A978, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route111_OldLadysRestStop_EventScript_22A941
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route111_OldLadysRestStop_EventScript_22A96E
	end

Route111_OldLadysRestStop_EventScript_22A941:: @ 822A941
	msgbox Route111_OldLadysRestStop_Text_22A9EC, 4
	closemessage
	call Route111_OldLadysRestStop_EventScript_272083
	msgbox Route111_OldLadysRestStop_Text_22AA16, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route111_OldLadysRestStop_EventScript_22A941
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route111_OldLadysRestStop_EventScript_22A96E
	end

Route111_OldLadysRestStop_EventScript_22A96E:: @ 822A96E
	msgbox Route111_OldLadysRestStop_Text_22AA8F, 4
	release
	end

Route111_OldLadysRestStop_Text_22A978: @ 822A978
	.string "Oh, dear, dear.\n"
	.string "Aren’t your POKéMON exhausted?\p"
	.string "If you’d like, rest up here.\n"
	.string "That’s a fine idea! You should do that.$"

Route111_OldLadysRestStop_Text_22A9EC: @ 822A9EC
	.string "That’s right.\n"
	.string "Take your time and rest up!$"

Route111_OldLadysRestStop_Text_22AA16: @ 822AA16
	.string "Oh, dear, dear.\n"
	.string "Are your POKéMON still tired?\p"
	.string "You should take another rest here.\n"
	.string "That’s a fine idea. You should do that.$"

Route111_OldLadysRestStop_Text_22AA8F: @ 822AA8F
	.string "Is that so?\n"
	.string "You don’t need to be shy about it.$"

