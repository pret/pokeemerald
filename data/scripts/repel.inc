EventScript_RepelWoreOff::
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	end

Text_RepelWoreOff:
.ifdef FRENCH
	.string "L’effet de REPOUSSE se dissipe…$"
.else
.ifdef ITALIAN
	.string "Finito l’effetto del REPELLENTE…$"
.else @ENGLISH
	.string "REPEL's effect wore off…$"
.endif
.endif
