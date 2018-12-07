VerdanturfTown_FriendshipRatersHouse_MapScripts:: @ 8203030
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_203031:: @ 8203031
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_2030ED, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case 0, VerdanturfTown_FriendshipRatersHouse_EventScript_203094
	case 1, VerdanturfTown_FriendshipRatersHouse_EventScript_20309E
	case 2, VerdanturfTown_FriendshipRatersHouse_EventScript_2030A8
	case 3, VerdanturfTown_FriendshipRatersHouse_EventScript_2030B2
	case 4, VerdanturfTown_FriendshipRatersHouse_EventScript_2030BC
	case 5, VerdanturfTown_FriendshipRatersHouse_EventScript_2030C6
	case 6, VerdanturfTown_FriendshipRatersHouse_EventScript_2030D0
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_203094:: @ 8203094
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_2032DF, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_20309E:: @ 820309E
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_203288, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030A8:: @ 82030A8
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_203249, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030B2:: @ 82030B2
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_203213, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030BC:: @ 82030BC
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_2031D1, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030C6:: @ 82030C6
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_203192, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030D0:: @ 82030D0
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_203141, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_2030DA:: @ 82030DA
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, 0
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_20334A, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_2030ED: @ 82030ED
	.string "Let me see your POKéMON.\n"
	.string "I'll check to see how much it likes you.\p"
	.string "Oh.\n"
	.string "Your POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_203141: @ 8203141
	.string "It adores you.\n"
	.string "It can't possibly love you any more.\l"
	.string "I even feel happy seeing it.$"

VerdanturfTown_FriendshipRatersHouse_Text_203192: @ 8203192
	.string "It seems to be very happy.\n"
	.string "It obviously likes you a whole lot.$"

VerdanturfTown_FriendshipRatersHouse_Text_2031D1: @ 82031D1
	.string "It likes you quite a lot.\n"
	.string "It seems to want to be babied a little.$"

VerdanturfTown_FriendshipRatersHouse_Text_203213: @ 8203213
	.string "It's getting used to you.\n"
	.string "It seems to believe in you.$"

VerdanturfTown_FriendshipRatersHouse_Text_203249: @ 8203249
	.string "It's not very used to you yet.\n"
	.string "It neither loves nor hates you.$"

VerdanturfTown_FriendshipRatersHouse_Text_203288: @ 8203288
	.string "It's very wary.\n"
	.string "It has scary viciousness in its eyes.\l"
	.string "It doesn't like you much at all.$"

VerdanturfTown_FriendshipRatersHouse_Text_2032DF: @ 82032DF
	.string "This is a little hard for me to say…\p"
	.string "Your POKéMON simply detests you.\n"
	.string "Doesn't that make you uncomfortable?$"

VerdanturfTown_FriendshipRatersHouse_Text_20334A: @ 820334A
	.string "PIKACHU: Pika pika!$"

