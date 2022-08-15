EventScript_RepelWoreOff::
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	end

.ifdef ENGLISH

Text_RepelWoreOff:
	.string "REPEL's effect wore off…$"

.else
.ifdef FRENCH

Text_RepelWoreOff:
	.string "L’effet de REPOUSSE se dissipe…$"

.else
.ifdef ITALIAN

Text_RepelWoreOff:
	.string "Finito l’effetto del REPELLENTE…$"

.endif
.endif
.endif
