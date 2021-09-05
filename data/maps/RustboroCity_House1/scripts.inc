RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Stream::
	msgbox RustboroCity_House1_Text_Stream, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_PS3::
	msgbox RustboroCity_House1_Text_PS3, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_Text_Stream:
	.string "OBS is open but it's frozen.\p"
	.string "The Star Wars theme is blaring\n"
	.string "while a scene from Max and Me\l"
	.string "plays on loop.$"

RustboroCity_House1_Text_PS3:
	.string "It's the PS3 you got from Chowder.\n"
	.string "It still smells like the remnants\l"
	.string "of a roach infestation.$"

