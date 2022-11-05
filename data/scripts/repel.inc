EventScript_RepelWoreOff::
.if I_REPEL_LURE_MENU == TRUE
	checkitem ITEM_REPEL, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_RepelUseAnother
	checkitem ITEM_SUPER_REPEL, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_RepelUseAnother
	checkitem ITEM_MAX_REPEL, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_RepelUseAnother
.else
	checkitem VAR_LAST_REPEL_LURE_USED, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_RepelUseAnother
.endif
	lock
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	release
	end

EventScript_RepelUseAnother:
	lock
	msgbox Text_UseAnotherRepel, MSGBOX_YESNO
.if I_REPEL_LURE_MENU == TRUE
	callnative TryDrawRepelMenu
	goto_if_eq VAR_RESULT, FALSE, EventScript_RepelWoreOff_Chose
	waitstate
	goto_if_eq VAR_RESULT, 127, EventScript_RepelWoreOff_End
EventScript_RepelWoreOff_Chose:
	callnative HandleRepelMenuChoice
	bufferitemname 1, VAR_0x8004
	removeitem VAR_0x8004, 1
	playse SE_REPEL
	msgbox Text_UsedNewRepelLure, MSGBOX_SIGN
.else
	goto_if_eq VAR_RESULT, YES, EventScript_UsedRepel
.endif
EventScript_RepelWoreOff_End:
	release
	end

EventScript_UsedRepel:
	bufferitemname 1, VAR_LAST_REPEL_LURE_USED
	playse SE_REPEL
	lock
	msgbox Text_UsedNewRepelLure, MSGBOX_SIGN
	removeitem VAR_LAST_REPEL_LURE_USED, 1
	waitse
	callnative HandleUseExpiredRepel
	release
	end

EventScript_LureWoreOff::
.if I_REPEL_LURE_MENU == TRUE
	checkitem ITEM_LURE, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_LureUseAnother
	checkitem ITEM_SUPER_LURE, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_LureUseAnother
	checkitem ITEM_MAX_LURE, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_LureUseAnother
.else
	checkitem VAR_LAST_REPEL_LURE_USED, 1
	goto_if_eq VAR_RESULT, TRUE, EventScript_LureUseAnother
.endif
	lock
	msgbox Text_LureWoreOff, MSGBOX_SIGN
	release
	end

EventScript_LureUseAnother:
	lock
	msgbox Text_UseAnotherLure, MSGBOX_YESNO
.if I_REPEL_LURE_MENU == TRUE
	callnative TryDrawLureMenu
	goto_if_eq VAR_RESULT, FALSE, EventScript_LureWoreOff_Chose
	waitstate
	goto_if_eq VAR_RESULT, 127, EventScript_LureWoreOff_End
EventScript_LureWoreOff_Chose:
	callnative HandleLureMenuChoice
	bufferitemname 1, VAR_0x8004
	removeitem VAR_0x8004, 1
	playse SE_REPEL
	msgbox Text_UsedNewRepelLure, MSGBOX_SIGN
.else
	goto_if_eq VAR_RESULT, YES, EventScript_UsedLure
.endif
EventScript_LureWoreOff_End:
	release
	end

EventScript_UsedLure:
	bufferitemname 1, VAR_LAST_REPEL_LURE_USED
	playse SE_REPEL
	lock
	msgbox Text_UsedNewRepelLure, MSGBOX_SIGN
	removeitem VAR_LAST_REPEL_LURE_USED, 1
	waitse
	callnative HandleUseExpiredLure
	release
	end

Text_RepelWoreOff:
	.string "REPEL's effect wore off…$"

Text_UseAnotherRepel::
	.string "REPEL's effect wore off!\n"
	.string "Use another?$"

Text_LureWoreOff:
	.string "Lure's effect wore off…$"

Text_UseAnotherLure::
	.string "Lure's effect wore off!\n"
	.string "Use another?$"

Text_UsedNewRepelLure::
	.string "{PLAYER} used the\n"
	.string "{STR_VAR_2}.$"
