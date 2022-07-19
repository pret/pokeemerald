Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Qu’est-ce que c’est?\n"
	.string "Qu’est-ce que je fais?\p"
	.string "Je vais me créer ma propre pièce ici, en\n"
	.string "utilisant la capacité d’un POKéMON.\p"
	.string "Je sais! Je vais te donner cette CT.\n"
	.string "Tu vas l’utiliser pour avoir ta pièce?$"

Route111_Text_ExplainSecretPower:
	.string "Trouve un grand arbre qui pourrait\n"
	.string "avoir des lianes.\p"
	.string "Utilise FORCE CACHEE devant l’arbre.\n"
	.string "Des lianes peuvent en tomber\l"
	.string "et te permettre de monter.\p"
	.string "Tu trouveras toute la place qu’il te\n"
	.string "faut pour y mettre tes objets préférés.\p"
	.string "Ce sera ta pièce secrète…\n"
	.string "Ta BASE SECRETE!\p"
	.string "Tu devrais t’en créer une!\p"
	.string "Autre chose: une BASE SECRETE ne se\n"
	.string "construit pas toujours dans un arbre.\p"
	.string "Essaie d’utiliser FORCE CACHEE sur\n"
	.string "des façades rocheuses fissurées.\p"
	.string "Je vais aussi chercher d’autres lieux.\n"
	.string "Salut!$"

Route111_Text_DontWantThis:
	.string "Oh, tu n’en veux pas? Si tu changes\n"
	.string "d’avis, fais-moi signe, OK?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, tu n’as pas de place pour ça.\p"
	.string "Bon, je vais la garder et tu pourras la\n"
	.string "prendre une autre fois, d’accord?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM43
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
