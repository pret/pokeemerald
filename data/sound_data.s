	.section .rodata

voicegroup_pokemon_cry:: @ 8675D04
	.incbin "baserom.gba", 0x675D04, 0x27FF0

gCryTable:: @ 869DCF4
	.incbin "baserom.gba", 0x69dcf4, 0x1230

gCryTable2:: @ 869EF24
	.incbin "baserom.gba", 0x69ef24, 0x1200

gUnknown_086A0124:: @ 86A0124
	.incbin "baserom.gba", 0x6a0124, 0x1489c

gMPlayTable:: @ 86B49C0
	.incbin "baserom.gba", 0x6b49c0, 0x30

gSongTable:: @ 86B49F0
	.incbin "baserom.gba", 0x6b49f0, 0x2ee660
