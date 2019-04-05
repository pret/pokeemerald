Route111_OldLadysRestStop_MapScripts:: @ 822A916
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition: @ 822A91C
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_22A920:: @ 822A920
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_22A978, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111_OldLadysRestStop_EventScript_22A941
	compare VAR_RESULT, 0
	goto_if_eq Route111_OldLadysRestStop_EventScript_22A96E
	end

Route111_OldLadysRestStop_EventScript_22A941:: @ 822A941
	msgbox Route111_OldLadysRestStop_Text_22A9EC, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_22AA16, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route111_OldLadysRestStop_EventScript_22A941
	compare VAR_RESULT, 0
	goto_if_eq Route111_OldLadysRestStop_EventScript_22A96E
	end

Route111_OldLadysRestStop_EventScript_22A96E:: @ 822A96E
	msgbox Route111_OldLadysRestStop_Text_22AA8F, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_22A978: @ 822A978
	.string "Oh, dear, dear.\n"
	.string "Aren't your POKéMON exhausted?\p"
	.string "If you'd like, rest up here.\n"
	.string "That's a fine idea! You should do that.$"

Route111_OldLadysRestStop_Text_22A9EC: @ 822A9EC
	.string "That's right.\n"
	.string "Take your time and rest up!$"

Route111_OldLadysRestStop_Text_22AA16: @ 822AA16
	.string "Oh, dear, dear.\n"
	.string "Are your POKéMON still tired?\p"
	.string "You should take another rest here.\n"
	.string "That's a fine idea. You should do that.$"

Route111_OldLadysRestStop_Text_22AA8F: @ 822AA8F
	.string "Is that so?\n"
	.string "You don't need to be shy about it.$"

