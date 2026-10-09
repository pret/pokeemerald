Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Wat?\n"
	.string "Wat ik aan het doen ben?\p"
	.string "Ik denk erover om hier mijn eigen\n"
	.string "kamer te maken met een POKéMON-aanval.\p"
	.string "Ik weet het! Ik geef je deze TM.\n"
	.string "Maak jij er je eigen kamer mee?$"

Route111_Text_ExplainSecretPower:
	.string "Zoek een grote boom waar ranken\n"
	.string "uit kunnen vallen.\p"
	.string "Gebruik GEHEIMKRACHT voor de boom.\n"
	.string "Er komen ranken los en vallen\l"
	.string "naar beneden, zodat je kunt klimmen.\p"
	.string "Daar is veel ruimte voor al je\n"
	.string "favoriete spullen.\p"
	.string "Het wordt je eigen geheime kamer…\n"
	.string "Een GEHEIME BASIS!\p"
	.string "Maak er ook een.\p"
	.string "Trouwens, je GEHEIME BASIS hoeft\n"
	.string "niet altijd in een boom.\p"
	.string "Probeer GEHEIMKRACHT op rotswanden\n"
	.string "met kleine inhammen.\p"
	.string "Ik ga ook naar andere plekken\n"
	.string "zoeken. Oké, dag!$"

Route111_Text_DontWantThis:
	.string "Oh, wil je dit niet?\n"
	.string "Van gedachten veranderd? Zeg het.$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, je hebt hier geen ruimte voor.\p"
	.string "Ik bewaar het, dus kom het een\n"
	.string "andere keer halen, oké?$"

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
	applywaitmovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	return

Route111_EventScript_SecretPowerManExitNorth::
	applywaitmovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
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
