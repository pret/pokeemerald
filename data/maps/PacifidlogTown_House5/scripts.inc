PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Je n’vois pas l’ILE MIRAGE aujourd’hui…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Oh! Oh mon Dieu! On peut voir\n"
	.string "l’ILE MIRAGE aujourd’hui!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "ILE MIRAGE…\p"
	.string "Elle devient probablement visible ou\n"
	.string "invisible en fonction du climat…\l"
	.string "Parfois, on peut voir le mirage.\p"
	.string "Ou peut-être apparaît-elle ou\n"
	.string "disparaît-elle pour de bon?$"

