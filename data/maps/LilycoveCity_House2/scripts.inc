LilycoveCity_House2_MapScripts:: @ 821ED74
	.byte 0

LilycoveCity_House2_EventScript_21ED75:: @ 821ED75
	lock
	faceplayer
	checkflag FLAG_0x0EA
	goto_eq LilycoveCity_House2_EventScript_21EDAC
	msgbox LilycoveCity_House2_Text_21EDB6, MSGBOX_DEFAULT
	giveitem_std ITEM_TM44
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_House2_EventScript_272054
	setflag FLAG_0x0EA
	msgbox LilycoveCity_House2_Text_21EDF9, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_EventScript_21EDAC:: @ 821EDAC
	msgbox LilycoveCity_House2_Text_21EDF9, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House2_Text_21EDB6: @ 821EDB6
	.string "Huh? What? What's that?\p"
	.string "I'm not near awake yet…\n"
	.string "You can have this…$"

LilycoveCity_House2_Text_21EDF9: @ 821EDF9
	.string "Yawn…\p"
	.string "Sleep is essential for good health…\n"
	.string "Sleep and regain health…$"

