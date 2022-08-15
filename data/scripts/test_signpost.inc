.ifdef ENGLISH
Text_ThisIsATestSignpostMsg::
	.string "This is a test message.\n"
	.string "This is a signpost.$"
.else
.ifdef FRENCH
Text_ThisIsATestSignpostMsg::
	.string "Message test.\n"
	.string "Panneau.$"
.else
.ifdef ITALIAN
Text_ThisIsATestSignpostMsg::
	.string "Questo è un messaggio di prova.\n"
	.string "Questo è un cartello.$"
.endif
.endif
.endif

EventScript_TestSignpostMsg::
	msgbox Text_ThisIsATestSignpostMsg, MSGBOX_SIGN
	end
