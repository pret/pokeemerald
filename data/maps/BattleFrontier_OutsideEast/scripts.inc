BattleFrontier_OutsideEast_MapScripts:: @ 8242C04
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_MapScript1_242C0F
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_MapScript1_242C2D
	.byte 0

BattleFrontier_OutsideEast_MapScript1_242C0F: @ 8242C0F
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_242C19
	end

BattleFrontier_OutsideEast_EventScript_242C19:: @ 8242C19
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_MapScript1_242C2D: @ 8242C2D
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_242C3F
	end

BattleFrontier_OutsideEast_EventScript_242C3F:: @ 8242C3F
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_242C43:: @ 8242C43
	msgbox BattleFrontier_OutsideEast_Text_242E11, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242C4C:: @ 8242C4C
	msgbox BattleFrontier_OutsideEast_Text_242E58, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242C55:: @ 8242C55
	msgbox BattleFrontier_OutsideEast_Text_242E96, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242C5E:: @ 8242C5E
	msgbox BattleFrontier_OutsideEast_Text_242ECF, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242C67:: @ 8242C67
	msgbox BattleFrontier_OutsideEast_Text_242F8C, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242C70:: @ 8242C70
	msgbox BattleFrontier_OutsideEast_Text_242FDC, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242C79:: @ 8242C79
	msgbox BattleFrontier_OutsideEast_Text_24308C, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242C82:: @ 8242C82
	msgbox BattleFrontier_OutsideEast_Text_243106, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242C8B:: @ 8242C8B
	msgbox BattleFrontier_OutsideEast_Text_2431A5, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242C94:: @ 8242C94
	lock
	msgbox BattleFrontier_OutsideEast_Text_2432DD, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242C9F:: @ 8242C9F
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox BattleFrontier_OutsideEast_Text_24334B, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_242CB2:: @ 8242CB2
	msgbox BattleFrontier_OutsideEast_Text_243363, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242CBB:: @ 8242CBB
	msgbox BattleFrontier_OutsideEast_Text_243425, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242CC4:: @ 8242CC4
	msgbox BattleFrontier_OutsideEast_Text_2434A0, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242CCD:: @ 8242CCD
	msgbox BattleFrontier_OutsideEast_Text_243504, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242CD6:: @ 8242CD6
	lock
	msgbox BattleFrontier_OutsideEast_Text_243529, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242CE1:: @ 8242CE1
	msgbox BattleFrontier_OutsideEast_Text_243230, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242CEA:: @ 8242CEA
	lock
	faceplayer
	waitse
	playse 269
	applymovement 14, BattleFrontier_OutsideEast_Movement_242D69
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_242CFC:: @ 8242CFC
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse 269
	applymovement 14, BattleFrontier_OutsideEast_Movement_242D69
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, 2
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, 14
	setwildbattle SPECIES_SUDOWOODO, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_OutsideEast_EventScript_242D60
	compare VAR_RESULT, 4
	goto_if_eq BattleFrontier_OutsideEast_EventScript_242D60
	compare VAR_RESULT, 5
	goto_if_eq BattleFrontier_OutsideEast_EventScript_242D60
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_242D60:: @ 8242D60
	setflag FLAG_DEFEATED_SUDOWOODO
	goto IslandCave_EventScript_27376D
	end

BattleFrontier_OutsideEast_Movement_242D69: @ 8242D69
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_242D79:: @ 8242D79
	msgbox BattleFrontier_OutsideEast_Text_243598, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242D82:: @ 8242D82
	msgbox BattleFrontier_OutsideEast_Text_243668, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242D8B:: @ 8242D8B
	msgbox BattleFrontier_OutsideEast_Text_2436F2, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242D94:: @ 8242D94
	msgbox BattleFrontier_OutsideEast_Text_243809, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242D9D:: @ 8242D9D
	msgbox BattleFrontier_OutsideEast_Text_243895, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242DA6:: @ 8242DA6
	msgbox BattleFrontier_OutsideEast_Text_243943, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242DAF:: @ 8242DAF
	msgbox BattleFrontier_OutsideEast_Text_2439A0, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242DB8:: @ 8242DB8
	lock
	msgbox BattleFrontier_OutsideEast_Text_243A2B, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242DC3:: @ 8242DC3
	lock
	msgbox BattleFrontier_OutsideEast_Text_243A53, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242DCE:: @ 8242DCE
	msgbox BattleFrontier_OutsideEast_Text_242F0D, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242DD7:: @ 8242DD7
	msgbox BattleFrontier_OutsideEast_Text_242F4A, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_242DE0:: @ 8242DE0
	msgbox BattleFrontier_OutsideEast_Text_243B68, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_242DE9:: @ 8242DE9
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_242DFE
	msgbox BattleFrontier_OutsideEast_Text_243C2C, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242DFE:: @ 8242DFE
	msgbox BattleFrontier_OutsideEast_Text_243CA3, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_242E08:: @ 8242E08
	msgbox BattleFrontier_OutsideEast_Text_243D0B, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_242E11: @ 8242E11
	.string "This is the BATTLE TOWER!\n"
	.string "Keep the win streak as the toughest\l"
	.string "TRAINER!$"

BattleFrontier_OutsideEast_Text_242E58: @ 8242E58
	.string "This is the BATTLE PALACE!\n"
	.string "Keep your eyes on POKéMON battles!$"

BattleFrontier_OutsideEast_Text_242E96: @ 8242E96
	.string "This is the BATTLE ARENA!\n"
	.string "Let the toughest teams gather!$"

BattleFrontier_OutsideEast_Text_242ECF: @ 8242ECF
	.string "This is the BATTLE PYRAMID!\n"
	.string "Advance through the Battle Quest!$"

BattleFrontier_OutsideEast_Text_242F0D: @ 8242F0D
	.string "BATTLE FRONTIER RANKING HALL\n"
	.string "Set your sights on new records!$"

BattleFrontier_OutsideEast_Text_242F4A: @ 8242F4A
	.string "BATTLE POINT EXCHANGE SERVICE CORNER\n"
	.string "Exchange your Battle Points!$"

BattleFrontier_OutsideEast_Text_242F8C: @ 8242F8C
	.string "Wow!\n"
	.string "It's huge!\p"
	.string "The BATTLE TOWER feels special.\n"
	.string "It's different from the others.$"

BattleFrontier_OutsideEast_Text_242FDC: @ 8242FDC
	.string "My grand ambition is to conquer both\n"
	.string "the BATTLE FRONTIER and the POKéMON\l"
	.string "LEAGUE.\p"
	.string "And if my dream comes true…\p"
	.string "I… I'm going to ask MIMI next door\n"
	.string "if she will be friends with me!$"

BattleFrontier_OutsideEast_Text_24308C: @ 824308C
	.string "The BATTLE PYRAMID's too harsh!\n"
	.string "I just can't make it to the top!\p"
	.string "Since I'm out of options, maybe I can\n"
	.string "climb the outside…$"

BattleFrontier_OutsideEast_Text_243106: @ 8243106
	.string "I thrive in darkness…\n"
	.string "Yes… What is worthy of me?\l"
	.string "None other than the BATTLE PYRAMID…\p"
	.string "What say you to wandering in darkness\n"
	.string "and in utter and total desperation?$"

BattleFrontier_OutsideEast_Text_2431A5: @ 82431A5
	.string "I didn't sleep for a week, but then\n"
	.string "I put together the ultimate team!\p"
	.string "I can't see myself losing, no joke.\n"
	.string "We're storming the BATTLE ARENA!$"

BattleFrontier_OutsideEast_Text_243230: @ 8243230
	.string "Did SCOTT bring you here, too?\n"
	.string "What is it with that guy?\p"
	.string "It sounds like he really does know\n"
	.string "how to spot talented TRAINERS, but…\p"
	.string "I've never seen him battling in person\n"
	.string "ever.$"

BattleFrontier_OutsideEast_Text_2432DD: @ 82432DD
	.string "ZIGG!\n"
	.string "I believe in you, little buddy!\p"
	.string "I'll make my little ZIGG any favorite\n"
	.string "tasty treats you like if you win!$"

BattleFrontier_OutsideEast_Text_24334B: @ 824334B
	.string "ZIGZAGOON looks vacant…$"

BattleFrontier_OutsideEast_Text_243363: @ 8243363
	.string "People call me a busybody,\n"
	.string "but I can't help it.\p"
	.string "Your hat's on crooked!\n"
	.string "Oh, no, trash on the ground!\l"
	.string "Oops, it's almost dinnertime!\p"
	.string "I don't know if I can stand to just\n"
	.string "watch at the BATTLE PALACE…$"

BattleFrontier_OutsideEast_Text_243425: @ 8243425
	.string "I may not look that impressive now,\n"
	.string "but I once beat a GYM LEADER.\p"
	.string "Who knows, maybe I should give it\n"
	.string "another shot at glory.$"

BattleFrontier_OutsideEast_Text_2434A0: @ 82434A0
	.string "I'm fast on my BIKE, and that goes for\n"
	.string "the way I battle, too.\p"
	.string "I win matches in the blink of\n"
	.string "an eye!$"

BattleFrontier_OutsideEast_Text_243504: @ 8243504
	.string "I'm better than my daddy\n"
	.string "at POKéMON.$"

BattleFrontier_OutsideEast_Text_243529: @ 8243529
	.string "Go on, my baby sweetie!\n"
	.string "Go rack up some wins for Daddy!\p"
	.string "You're just like your mother,\n"
	.string "so you'll be dominating!$"

BattleFrontier_OutsideEast_Text_243598: @ 8243598
	.string "It wasn't easy getting here,\n"
	.string "but I'd heard about this knockout\l"
	.string "pretty girl at the BATTLE ARENA.\p"
	.string "Instead of her, do you know what\n"
	.string "I found?\p"
	.string "A whole teeming mob of sweaty,\n"
	.string "stinky, and primitive martial artists!$"

BattleFrontier_OutsideEast_Text_243668: @ 8243668
	.string "I sometimes see this really important-\n"
	.string "looking old man going in there.\p"
	.string "He has these really awesome POKéMON.\n"
	.string "He seems really nice, though.$"

BattleFrontier_OutsideEast_Text_2436F2: @ 82436F2
	.string "Do you know it?\n"
	.string "The legend of the BATTLE PYRAMID?\p"
	.string "When there comes a confident TRAINER\n"
	.string "reaching for the golden pinnacle,\l"
	.string "there shall appear a man among men.\p"
	.string "Don't know that legend?\n"
	.string "Well, of course not!\l"
	.string "I just made it up!\p"
	.string "What's it supposed to mean?\n"
	.string "That, my friend, I can't say!$"

BattleFrontier_OutsideEast_Text_243809: @ 8243809
	.string "Man! Oh man!\n"
	.string "I've never lost once before!\p"
	.string "But I got wiped out with no saving\n"
	.string "grace at all!\p"
	.string "And then I'm told I don't have any\n"
	.string "talent?! Man!$"

BattleFrontier_OutsideEast_Text_243895: @ 8243895
	.string "This guy ran into a horribly tough\n"
	.string "TRAINER while he was on the BATTLE\l"
	.string "TOWER challenge.\p"
	.string "Now look at him…\p"
	.string "You need to be cautious if you ever\n"
	.string "decide to go to the BATTLE TOWER.$"

BattleFrontier_OutsideEast_Text_243943: @ 8243943
	.string "Yes!\n"
	.string "I've finally got enough Battle Points!\p"
	.string "I guess I'll trade for another giant\n"
	.string "plush DOLL!$"

BattleFrontier_OutsideEast_Text_2439A0: @ 82439A0
	.string "Oh, yeah, okay!\n"
	.string "So this is the RANKING HALL!\p"
	.string "I'd like to go down in history as\n"
	.string "a super champ and have my name\l"
	.string "recorded here for posterity.$"

BattleFrontier_OutsideEast_Text_243A2B: @ 8243A2B
	.string "With you by my side, I can do anything.$"

BattleFrontier_OutsideEast_Text_243A53: @ 8243A53
	.string "Ooh, darling, you are so wonderful!\p"
	.string "Ooh, I just can't wait anymore!\p"
	.string "Let's go to a MULTI BATTLE ROOM\n"
	.string "right this instant!\p"
	.string "If we get together in the BATTLE SALON,\n"
	.string "the power of our love will overcome\l"
	.string "everyone we meet.\p"
	.string "Why, before us, darling, everything\n"
	.string "will topple like dominoes!$"

BattleFrontier_OutsideEast_Text_243B68: @ 8243B68
	.string "The BATTLE FRONTIER isn't exclusively\n"
	.string "for tough TRAINERS.\p"
	.string "Many people with special abilities\n"
	.string "have been invited, it seems.\p"
	.string "That man SCOTT…\p"
	.string "He may have built this place to serve\n"
	.string "a bigger objective…$"

BattleFrontier_OutsideEast_Text_243C2C: @ 8243C2C
	.string "Excuse me, young one.\n"
	.string "Have you good eyesight?\p"
	.string "There is an odd tree past here, and to\n"
	.string "my tired eyes it seems to wiggle.$"

BattleFrontier_OutsideEast_Text_243CA3: @ 8243CA3
	.string "Excuse me, young one.\n"
	.string "Have you a good memory?\p"
	.string "I have this feeling there once was\n"
	.string "an odd tree past here.$"

BattleFrontier_OutsideEast_Text_243D0B: @ 8243D0B
	.string "I…\n"
	.string "I saw it!\p"
	.string "There was a sticky sort of a POKéMON\n"
	.string "with a long tail up ahead!\p"
	.string "It was hiding under a boulder, and\n"
	.string "it kept staring at me!$"
