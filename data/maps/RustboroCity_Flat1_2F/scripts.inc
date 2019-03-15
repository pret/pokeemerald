RustboroCity_Flat1_2F_MapScripts:: @ 8215139
	.byte 0

RustboroCity_Flat1_2F_EventScript_21513A:: @ 821513A
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_Flat1_2F_EventScript_21518D
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151AD

RustboroCity_Flat1_2F_EventScript_215157:: @ 8215157
	special DoWaldaNamingScreen
	waitstate
	compare VAR_0x8004, 1
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151D7
	compare VAR_0x8004, 2
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151E1
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151F8
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_Flat1_2F_EventScript_215221
	end

RustboroCity_Flat1_2F_EventScript_21518D:: @ 821518D
	msgbox RustboroCity_Flat1_2F_Text_2152FA, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151CD
	msgbox RustboroCity_Flat1_2F_Text_2154AD, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_215157

RustboroCity_Flat1_2F_EventScript_2151AD:: @ 82151AD
	msgbox RustboroCity_Flat1_2F_Text_215448, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_Flat1_2F_EventScript_2151CD
	msgbox RustboroCity_Flat1_2F_Text_2154AD, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_215157

RustboroCity_Flat1_2F_EventScript_2151CD:: @ 82151CD
	msgbox RustboroCity_Flat1_2F_Text_2154E7, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_2151D7:: @ 82151D7
	msgbox RustboroCity_Flat1_2F_Text_2156E3, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_2151E1:: @ 82151E1
	msgbox RustboroCity_Flat1_2F_Text_21561E, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_215238
	msgbox RustboroCity_Flat1_2F_Text_215699, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_2151F8:: @ 82151F8
	msgbox RustboroCity_Flat1_2F_Text_215535, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_215238
	msgbox RustboroCity_Flat1_2F_Text_215565, MSGBOX_DEFAULT
	applymovement 6, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_215792, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_215221:: @ 8215221
	msgbox RustboroCity_Flat1_2F_Text_2155A4, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_215238
	msgbox RustboroCity_Flat1_2F_Text_2155D4, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_215238:: @ 8215238
	turnobject 6, 4
	return

RustboroCity_Flat1_2F_EventScript_21523D:: @ 821523D
	msgbox RustboroCity_Flat1_2F_Text_21524F, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_215246:: @ 8215246
	msgbox RustboroCity_Flat1_2F_Text_215923, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_21524F: @ 821524F
	.string "Oh, it's so hard every day…\p"
	.string "What's hard?\n"
	.string "You need to ask?\p"
	.string "It's trying to figure out what to\n"
	.string "make for meals every day.\p"
	.string "It really isn't easy coming up with\n"
	.string "meals every day.$"

RustboroCity_Flat1_2F_Text_2152FA: @ 82152FA
	.string "Oh, hello!\n"
	.string "Welcome to the PEPPER household.\p"
	.string "I have a question for you.\n"
	.string "Have you ever baby-sat?\p"
	.string "You see, I'm a new father, so raising\n"
	.string "a child is all new to me.\p"
	.string "And I have a problem. My daughter\n"
	.string "WALDA doesn't laugh enough.\p"
	.string "I think she'd laugh for me if I told\n"
	.string "her something funny.\p"
	.string "Do you know of a funny word or\n"
	.string "phrase you can tell me?$"

RustboroCity_Flat1_2F_Text_215448: @ 8215448
	.string "I've been saying “{STR_VAR_1}”\n"
	.string "to amuse her lately.\p"
	.string "Do you know of a better word or\n"
	.string "a phrase that might work?$"

RustboroCity_Flat1_2F_Text_2154AD: @ 82154AD
	.string "Oh, that's wonderful.\n"
	.string "So, let's hear it, your suggestion.$"

RustboroCity_Flat1_2F_Text_2154E7: @ 82154E7
	.string "Oh, is that right?\p"
	.string "Well, if you come up with a good\n"
	.string "suggestion, I'm all ears.$"

RustboroCity_Flat1_2F_Text_215535: @ 8215535
	.string "Ah, I see.\n"
	.string "Well, let's give it a try, shall we?$"

RustboroCity_Flat1_2F_Text_215565: @ 8215565
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh, yes! She's laughing!\n"
	.string "Oh, I am as delighted as she!$"

RustboroCity_Flat1_2F_Text_2155A4: @ 82155A4
	.string "Ah, I see.\n"
	.string "Well, let's give it a try, shall we?$"

RustboroCity_Flat1_2F_Text_2155D4: @ 82155D4
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… She's not smiling at all.\n"
	.string "Maybe WALDA is one serious child…$"

RustboroCity_Flat1_2F_Text_21561E: @ 821561E
	.string "Oh, so you don't know any good words.\n"
	.string "I'd better think for myself, then.\p"
	.string "Hmm…\n"
	.string "How about “{STR_VAR_1}”?\l"
	.string "Let's see if that will work.$"

RustboroCity_Flat1_2F_Text_215699: @ 8215699
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… She's not smiling at all.\n"
	.string "Maybe WALDA is one serious child…$"

RustboroCity_Flat1_2F_Text_2156E3: @ 82156E3
	.string "Oh, so you don't know any good words.\n"
	.string "I guess I'll try to amuse her with\l"
	.string "the saying I used before.\p"
	.string "Anyways, if you have a good suggestion,\n"
	.string "don't hesitate in telling me, okay?$"

RustboroCity_Flat1_2F_Text_215792: @ 8215792
	.string "Thank you!\p"
	.string "Thanks to you, my darling WALDA\n"
	.string "laughed for me!\p"
	.string "Actually, I may not look all that\n"
	.string "special, but I'm one of DEVON\l"
	.string "CORPORATION's top researchers.\p"
	.string "So, how about I do something in return\n"
	.string "for you?\p"
	.string "I know, I'll add some new wallpaper\n"
	.string "patterns for the BOXES in the PC\l"
	.string "POKéMON Storage System.\p"
	.string "In the wallpaper pattern menu,\n"
	.string "select “FRIENDS.”\p"
	.string "That will give you access to the new\n"
	.string "wallpaper patterns.$"

RustboroCity_Flat1_2F_Text_215923: @ 8215923
	.string "It's a POKéMON plush DOLL!$"

