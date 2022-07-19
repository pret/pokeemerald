VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case 0, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case 1, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case 2, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case 3, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case 4, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case 5, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case 6, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Laisse-moi voir ton POKéMON.\n"
	.string "Je vais regarder s’il t’aime bien.\p"
	.string "Oh.\n"
	.string "Ton POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Il t’adore.\n"
	.string "Il ne pourrait pas t’aimer plus.\l"
	.string "Ça fait plaisir à voir.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Il semble très heureux.\n"
	.string "A l’évidence, il t’aime de tout son cœur.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Il t’aime beaucoup.\n"
	.string "Il semble vouloir être dorloté.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "Il commence à s’habituer à toi.\n"
	.string "Il a l’air de croire en toi.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Il n’est pas encore très habitué à toi.\n"
	.string "Il ne t’aime pas, mais ne te déteste pas\l"
	.string "non plus.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "Il est sur ses gardes.\n"
	.string "Il pourrait être agressif.\p"
	.string "Il ne t’aime pas du tout.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "C’est un peu difficile à annoncer…\p"
	.string "Ton POKéMON te déteste franchement.\n"
	.string "Ça ne te met pas un peu mal à l’aise?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"

