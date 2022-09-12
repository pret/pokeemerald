EventScript_RepelWoreOff::
	checkitem I_VAR_LAST_REPEL_LURE_USED, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_UseAnother
	lock
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	release
	end

EventScript_UseAnother:
	lock
	msgbox Text_UseAnother, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_UsedRepel
	release
	end

EventScript_UsedRepel:
	bufferitemname 0, I_VAR_LAST_REPEL_LURE_USED
	playse SE_REPEL
	lock
	msgbox Text_UsedNewRepelLure, MSGBOX_SIGN
	removeitem I_VAR_LAST_REPEL_LURE_USED, 1
	waitse
	callnative HandleUseExpiredRepel
	release
	end

Text_RepelWoreOff:
	.string "REPEL's effect wore off…$"

Text_UseAnother::
	.string "REPEL's effect wore off!\n"
	.string "Use another?$"

Text_UsedNewRepelLure::
	.string "{PLAYER} used the\n"
	.string "{STR_VAR_1}.$"

EventScript_LureWoreOff::
	checkitem I_VAR_LAST_REPEL_LURE_USED, 1
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_LureUseAnother
	lock
	msgbox Text_LureWoreOff, MSGBOX_SIGN
	release
	end

EventScript_LureUseAnother:
	lock
	msgbox Text_UseAnotherLure, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_UsedLure
	release
	end

EventScript_UsedLure:
	bufferitemname 0, I_VAR_LAST_REPEL_LURE_USED
	playse SE_REPEL
	lock
	msgbox Text_UsedNewRepelLure, MSGBOX_SIGN
	removeitem I_VAR_LAST_REPEL_LURE_USED, 1
	waitse
	callnative HandleUseExpiredLure
	release
	end

Text_LureWoreOff:
	.string "Lure's effect wore off…$"

Text_UseAnotherLure::
	.string "Lure's effect wore off!\n"
	.string "Use another?$"
