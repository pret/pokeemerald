.ifdef FRENCH
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
.else
.ifdef ITALIAN
Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Che c’è?\n"
	.string "Cosa sto facendo?\p"
	.string "Pensavo di stabilire qui il mio ritrovo\n"
	.string "usando una mossa POKéMON.\p"
	.string "Sì! Ti darò questa MT.\n"
	.string "La userai per creare il tuo ritrovo?$"

Route111_Text_ExplainSecretPower:
	.string "Cerca un grosso albero dal quale\n"
	.string "ti sembra possano cadere dei tralci.\p"
	.string "Usa FORZASEGRETA di fronte all’albero.\n"
	.string "In questo modo scenderanno dei tralci\l"
	.string "con cui ti potrai arrampicare.\p"
	.string "Ci sarà un sacco di spazio e potrai\n"
	.string "metterci tutte le tue cose.\p"
	.string "Questo sarà il tuo ritrovo segreto.\n"
	.string "La tua BASE SEGRETA!\p"
	.string "Dai, fanne una anche tu!\p"
	.string "Ricordati, la BASE SEGRETA non deve\n"
	.string "essere necessariamente su un albero.\p"
	.string "Prova ad usare FORZASEGRETA\n"
	.string "su pareti rocciose con piccole \l"
	.string "rientranze.\p"
	.string "Anch’io cercherò degli altri posti.\n"
	.string "Ok, ciao!$"

Route111_Text_DontWantThis:
	.string "Non vuoi averla?\n"
	.string "Fammi sapere se cambi idea, ok?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, non hai più spazio.\p"
	.string "La conserverò per te, puoi venire\n"
	.string "a prenderla un’altra volta, ok?$"
.else
Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "What's that?\n"
	.string "What am I doing?\p"
	.string "I'm thinking about making my own room\n"
	.string "here using a POKéMON move.\p"
	.string "I know! I'll give you this TM.\n"
	.string "Will you use it to make your own room?$"

Route111_Text_ExplainSecretPower:
	.string "Find a big tree that looks like it might\n"
	.string "drop some vines.\p"
	.string "Use SECRET POWER in front of the tree.\n"
	.string "Some vines should get free and drop\l"
	.string "down, so you can climb the tree.\p"
	.string "You'll find a lot of space for putting\n"
	.string "your favorite things.\p"
	.string "It'll be your own secret room…\n"
	.string "A SECRET BASE!\p"
	.string "You should make one, too.\p"
	.string "Another thing, you don't always have\n"
	.string "to make your SECRET BASE in a tree.\p"
	.string "Try using SECRET POWER on rock walls\n"
	.string "that have small indents in them.\p"
	.string "I'm going to look for other places, too.\n"
	.string "Okay, bye!$"

Route111_Text_DontWantThis:
	.string "Oh, you don't want this?\n"
	.string "If you change your mind, tell me, okay?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, you don't have any room for this.\p"
	.string "I'll hold on to it, so come back for it\n"
	.string "another time, okay?$"
.endif
.endif

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
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
