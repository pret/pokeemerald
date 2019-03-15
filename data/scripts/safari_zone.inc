EventScript_2A4B4C:: @ 82A4B4C
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
	end

EventScript_2A4B5D:: @ 82A4B5D
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 255, 2, 5
	waitstate
	end

EventScript_2A4B6F:: @ 82A4B6F
	lockall
	msgbox Text_2A4BF4, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq EventScript_2A4B85
	releaseall
	end

EventScript_2A4B85:: @ 82A4B85
	goto EventScript_2A4B5D

EventScript_2A4B8A:: @ 82A4B8A
	lockall
	playse SE_PINPON
	message Text_2A4C26
	waitmessage
	waitbuttonpress
	releaseall
	goto EventScript_2A4B5D

EventScript_2A4B9B:: @ 82A4B9B
	lockall
	playse SE_PINPON
	message Text_2A4C56
	waitmessage
	waitbuttonpress
	releaseall
	goto EventScript_2A4B5D

EventScript_PokeBlockFeeder:: @ 82A4BAC
	lockall
	special GetPokeblockFeederInFront
	compare VAR_RESULT, 65535
	goto_if_ne EventScript_2A4BEB
	msgbox Text_2A4C90, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq EventScript_2A4BD0
	releaseall
	end

EventScript_2A4BD0:: @ 82A4BD0
	fadescreen 1
	special OpenPokeblockCaseOnFeeder
	waitstate
	compare VAR_RESULT, 65535
	goto_if_ne EventScript_2A4BE2
	end

EventScript_2A4BE2:: @ 82A4BE2
	message Text_2A4CEB
	waitmessage
	waitbuttonpress
	releaseall
	end

EventScript_2A4BEB:: @ 82A4BEB
	message Text_2A4CC5
	waitmessage
	waitbuttonpress
	releaseall
	end

Text_2A4BF4: @ 82A4BF4
	.string "Would you like to exit the SAFARI\n"
	.string "ZONE right now?$"

Text_2A4C26: @ 82A4C26
	.string "Ding-dong! Time's up!\n"
	.string "Your SAFARI Game is over.$"

Text_2A4C56: @ 82A4C56
	.string "You've run out of SAFARI BALLS.\n"
	.string "Your SAFARI Game is over.$"

Text_2A4C90: @ 82A4C90
	.string "Would you like to place a {POKEBLOCK}\n"
	.string "on the {POKEBLOCK} FEEDER?$"

Text_2A4CC5: @ 82A4CC5
	.string "The {STR_VAR_1} you left\n"
	.string "before is still here.$"

Text_2A4CEB: @ 82A4CEB
	.string "The {STR_VAR_1} was placed\n"
	.string "on the {POKEBLOCK} FEEDER.$"

Route121_SafariZoneEntrance_Text_2A4D12: @ 82A4D12
	.string "Welcome to the SAFARI ZONE!\p"
	.string "Here, you may witness many kinds of\n"
	.string "POKéMON rarely seen in HOENN.\p"
	.string "And, you'll see them in their wild,\n"
	.string "untamed state in natural habitats.\p"
	.string "What's more, we've thrown open the\n"
	.string "gates to POKéMON TRAINERS.\p"
	.string "You're encouraged to catch POKéMON\n"
	.string "for keeps!\p"
	.string "Come in and enjoy the SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_2A4E46: @ 82A4E46
	.string "Welcome to the SAFARI ZONE!\n"
	.string "Is it your first time here?$"

Route121_SafariZoneEntrance_Text_2A4E7E: @ 82A4E7E
	.string "Come in and enjoy the SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_2A4EA1: @ 82A4EA1
	.string "When you enter the SAFARI ZONE, you\n"
	.string "start with 30 SAFARI BALLS for\l"
	.string "catching POKéMON.\p"
	.string "The SAFARI Game is over when you run\n"
	.string "out of SAFARI BALLS, or when you've\l"
	.string "walked 500 steps.\p"
	.string "Come in and enjoy the SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_2A4F74: @ 82A4F74
	.string "Welcome to the SAFARI ZONE!\p"
	.string "All you can catch for just ¥500!\n"
	.string "Would you like to play a SAFARI Game?$"

Route121_SafariZoneEntrance_Text_2A4FD7: @ 82A4FD7
	.string "Okay.\n"
	.string "Please play another time!$"

Route121_SafariZoneEntrance_Text_2A4FF7: @ 82A4FF7
	.string "You don't have enough money.\n"
	.string "Sorry.$"

Route121_SafariZoneEntrance_Text_2A501B: @ 82A501B
	.string "That will be ¥500, please.$"

Route121_SafariZoneEntrance_Text_2A5036: @ 82A5036
	.string "Here are your SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_2A5052: @ 82A5052
	.string "{PLAYER} received 30 SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_2A506F: @ 82A506F
	.string "We'll let you know when your game\n"
	.string "is over.\p"
	.string "So, until then, enjoy yourself, please!\n"
	.string "Off you go on your wild excursion!$"

Route121_SafariZoneEntrance_Text_2A50E5: @ 82A50E5
	.string "Excuse me!\n"
	.string "Your PC BOX is full.$"

Route121_SafariZoneEntrance_Text_2A5105: @ 82A5105
	.string "Excuse me!\n"
	.string "You seem to be without a {POKEBLOCK} CASE.\p"
	.string "Your SAFARI Game will be much more\n"
	.string "fruitful if you use {POKEBLOCK}S.\p"
	.string "Please come back with a {POKEBLOCK} CASE.\p"
	.string "You may obtain a {POKEBLOCK} CASE from\n"
	.string "the LILYCOVE CONTEST HALL.$"

SafariZone_South_Text_2A51D4: @ 82A51D4
	.string "You still have time left. Would you like\n"
	.string "to exit the SAFARI ZONE now?$"

SafariZone_South_Text_2A521A: @ 82A521A
	.string "Please enjoy the rest of your wild\n"
	.string "adventure!$"

SafariZone_South_Text_2A5248: @ 82A5248
	.string "Okay.\p"
	.string "I'll take back your remaining SAFARI\n"
	.string "BALLS.\p"
	.string "Thank you for playing.\n"
	.string "We hope to see you again.$"

SafariZone_South_Text_2A52AB: @ 82A52AB
	.string "Good luck!\p"
	.string "If you need anything, don't hesitate\n"
	.string "to tell me, please!$"

SafariZone_South_Text_2A52EF: @ 82A52EF
	.string "Did you know?\p"
	.string "If you put a {POKEBLOCK} in that square box,\n"
	.string "POKéMON gather around.$"

SafariZone_South_Text_2A533B: @ 82A533B
	.string "I want to keep going deeper, but I\n"
	.string "forgot to bring a BIKE.\p"
	.string "Something tells me that rare POKéMON\n"
	.string "live in the outlying areas.$"

SafariZone_Southwest_Text_2A53B7: @ 82A53B7
	.string "Sometimes, when I toss a {POKEBLOCK} at \n"
	.string "POKéMON, it gets ignored.\p"
	.string "Do POKéMON have likes and dislikes\n"
	.string "about what they eat?$"

SafariZone_Northwest_Text_2A542C: @ 82A542C
	.string "Gasp… Gasp…\n"
	.string "I…made it out here…but…\p"
	.string "I'm exhausted… I don't have the\n"
	.string "energy to catch POKéMON…$"

SafariZone_North_Text_2A5489: @ 82A5489
	.string "I'm on a mission to find WATER POKéMON\n"
	.string "you don't see in HOENN.\p"
	.string "Do you have any idea where the lake is?$"

SafariZone_North_Text_2A54F0: @ 82A54F0
	.string "I'm going to catch a lot of rare POKéMON\n"
	.string "here and trade them with my friends!$"

SafariZone_South_Text_2A553E: @ 82A553E
	.string "I put a {POKEBLOCK} on the {POKEBLOCK} FEEDER.\n"
	.string "But it seems to have disappeared.\p"
	.string "I guess POKéMON must have eaten it\n"
	.string "without me noticing.$"

Route121_SafariZoneEntrance_Text_2A55BB: @ 82A55BB
	.string "SAFARI ZONE TRAINER TIP!\p"
	.string "Throw {POKEBLOCK}S at wild POKéMON to make\n"
	.string "them less likely to flee.$"

SafariZone_Southwest_Text_2A5613: @ 82A5613
	.string "“Relieve your tired feet.”\n"
	.string "REST HOUSE$"

SafariZone_RestHouse_Text_2A5639: @ 82A5639
	.string "I don't have any {POKEBLOCK}S, but I caught\n"
	.string "a good number of POKéMON.\p"
	.string "You can improve your chances of making\n"
	.string "a catch by getting closer to them\l"
	.string "before throwing a SAFARI BALL.$"

SafariZone_RestHouse_Text_2A56E1: @ 82A56E1
	.string "If you use {POKEBLOCK}S, wild POKéMON won't\n"
	.string "be so quick to run away.\p"
	.string "It's not much use to give {POKEBLOCK}S to\n"
	.string "POKéMON that don't flee easily.$"

SafariZone_RestHouse_Text_2A5764: @ 82A5764
	.string "If you put a {POKEBLOCK} on the FEEDER,\n"
	.string "POKéMON are attracted to it.\p"
	.string "I think POKéMON with the same sort of\n"
	.string "nature are drawn by a certain {POKEBLOCK}.$"

SafariZone_South_Text_2A57EE: @ 82A57EE
	.string "This area is still under construction.\n"
	.string "It's off-limits, sorry!$"

SafariZone_Southeast_Text_2A582D: @ 82A582D
	.string "The SAFARI ZONE's expansion project\n"
	.string "is finished now.\p"
	.string "We hope you will enjoy the new area.$"

SafariZone_South_Text_2A5887: @ 82A5887
	.string "This area is still under construction.\n"
	.string "It's off-limits, sorry!$"

SafariZone_Southeast_Text_2A58C6: @ 82A58C6
	.string "Wow! Whee! I haven't seen any of\n"
	.string "these POKéMON before!$"

SafariZone_Southeast_Text_2A58FD: @ 82A58FD
	.string "The POKéMON in this area are all\n"
	.string "new to me.\p"
	.string "And I'm allowed to catch these rare\n"
	.string "POKéMON! Too cool!$"

SafariZone_Southeast_Text_2A5960: @ 82A5960
	.string "The POKéMON around here seem to be\n"
	.string "from somewhere other than HOENN.$"

SafariZone_Northeast_Text_2A59A4: @ 82A59A4
	.string "I only have a couple SAFARI BALLS left.\p"
	.string "I'm having a hard time trying to\n"
	.string "decide what I should catch.$"

SafariZone_Northeast_Text_2A5A09: @ 82A5A09
	.string "I heard that you can see PIKACHU here.\n"
	.string "Where might one be?$"

SafariZone_Northeast_Text_2A5A44: @ 82A5A44
	.string "Oh, boo!\n"
	.string "I can't seem to catch anything!\p"
	.string "I'll end up wasting the admission\n"
	.string "price if I don't catch something!$"
