Text_ThisIsATestSignpostMsg::
.ifdef FRENCH
	.string "Message test.\n"
	.string "Panneau.$"
.else
.ifdef ITALIAN
	.string "Questo è un messaggio di prova.\n"
	.string "Questo è un cartello.$"
.else @ENGLISH
	.string "This is a test message.\n"
	.string "This is a signpost.$"
.endif
.endif

EventScript_TestSignpostMsg::
	msgbox Text_ThisIsATestSignpostMsg, MSGBOX_SIGN
	end
