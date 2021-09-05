RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Stream::
	msgbox RustboroCity_House1_Text_Stream, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hedgehog::
	msgbox RustboroCity_House1_Text_Hedgehog, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_PS3::
	msgbox RustboroCity_House1_Text_PS3, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Kitchen::
	msgbox RustboroCity_House1_Text_Kitchen, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Sink::
	msgbox RustboroCity_House1_Text_Sink, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_Text_Stream:
	.string "OBS is open but it's frozen.\p"
	.string "The Star Wars theme is blaring\n"
	.string "while a scene from Mac and Me\l"
	.string "plays on loop.$"

RustboroCity_House1_Text_PS3:
	.string "It's the PS3 you got from Chowder.\n"
	.string "It still smells like the remnants\l"
	.string "of a roach infestation.$"

RustboroCity_House1_Text_Hedgehog:
	.string "There's a hedgehog outside.\n"
	.string "It seems to be enjoying some ham.$"

RustboroCity_House1_Text_Kitchen:
	.string "There's a plate of stuvade makaroner\n"
	.string "med falukorv on the counter. Yum!$"

RustboroCity_House1_Text_Sink:
	.string "It's a sink.\p"
	.string "... ... ... ... ... ...\p"
	.string "Funny.$"