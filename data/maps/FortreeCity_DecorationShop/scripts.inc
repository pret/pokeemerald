FortreeCity_DecorationShop_MapScripts:: @ 821800D
	.byte 0

FortreeCity_DecorationShop_EventScript_21800E:: @ 821800E
	msgbox FortreeCity_DecorationShop_Text_218078, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_218017:: @ 8218017
	msgbox FortreeCity_DecorationShop_Text_2180ED, MSGBOX_NPC
	end

FortreeCity_DecorationShop_EventScript_218020:: @ 8218020
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_218038
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

    .align 2
FortreeCity_DecorationShop_PokemartDecor_218038: @ 8218038
	.2byte 1
	.2byte 2
	.2byte 3
	.2byte 4
	.2byte 5
	.2byte 7
	.2byte 8
	.2byte 9
	.2byte 0
	release
	end

FortreeCity_DecorationShop_EventScript_21804C:: @ 821804C
	lock
	faceplayer
	message gUnknown_08272A21
	waitmessage
	pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_218064
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_DecorationShop_PokemartDecor_218064: @ 8218064
	.2byte 10
	.2byte 11
	.2byte 12
	.2byte 15
	.2byte 14
	.2byte 16
	.2byte 17
	.2byte 18
	.2byte 0
	release
	end

FortreeCity_DecorationShop_Text_218078: @ 8218078
	.string "Merchandise you buy here is sent to\n"
	.string "your own PC.\p"
	.string "That's fantastic! I wish they could\n"
	.string "also deliver me home like that.$"

FortreeCity_DecorationShop_Text_2180ED: @ 82180ED
	.string "I'm buying a pretty desk and I'm\n"
	.string "putting my cute DOLLS on it.\p"
	.string "If I don't, when I decorate my\n"
	.string "SECRET BASE, my DOLLS will get\l"
	.string "dirty or poked with splinters.$"

