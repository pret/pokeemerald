    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0
	
gUnknown_0855D114:: @ 855D114
	.incbin "baserom.gba", 0x55D114, 0x80

gUnknown_0855D194:: @ 855D194
	.incbin "baserom.gba", 0x55d194, 0x18

gUnknown_0855D1AC:: @ 855D1AC
	.incbin "baserom.gba", 0x55d1ac, 0x18

gUnknown_0855D1C4:: @ 855D1C4
	.incbin "baserom.gba", 0x55d1c4, 0x18

gUnknown_0855D1DC:: @ 855D1DC
	.incbin "baserom.gba", 0x55d1dc, 0x18

gUnknown_0855D1F4:: @ 855D1F4
	.incbin "baserom.gba", 0x55d1f4, 0x18

gUnknown_0855D20C:: @ 855D20C
	.incbin "baserom.gba", 0x55d20c, 0x18

gUnknown_0855D224:: @ 855D224
	.incbin "baserom.gba", 0x55d224, 0x18

gUnknown_0855D23C:: @ 855D23C
	.incbin "baserom.gba", 0x55d23c, 0x18

gUnknown_0855D254:: @ 855D254
	.incbin "baserom.gba", 0x55d254, 0x18

gUnknown_0855D26C:: @ 855D26C
	.incbin "baserom.gba", 0x55d26c, 0x10

gUnknown_0855D27C:: @ 855D27C
	.incbin "baserom.gba", 0x55d27c, 0x10

gUnknown_0855D28C:: @ 855D28C
	.incbin "baserom.gba", 0x55d28c, 0x5

gUnknown_0855D291:: @ 855D291
	.incbin "baserom.gba", 0x55d291, 0x7

gUnknown_0855D298:: @ 855D298
	.incbin "baserom.gba", 0x55d298, 0x10

gUnknown_0855D2A8:: @ 855D2A8
	.incbin "baserom.gba", 0x55d2a8, 0x10

gUnknown_0855D2B8:: @ 855D2B8
	.incbin "baserom.gba", 0x55d2b8, 0x6

gUnknown_0855D2BE:: @ 855D2BE
	.incbin "baserom.gba", 0x55d2be, 0x40

gUnknown_0855D2FE:: @ 855D2FE
	.incbin "baserom.gba", 0x55d2fe, 0xe

gUnknown_0855D30C:: @ 855D30C
	.string "$"

@ 855D30D
	.include "data/text/pokedex_text.inc"

@ 856B5B0
	.include "data/pokedex_entries.inc"

gUnknown_0856E610:: @ 856E610
	.incbin "baserom.gba", 0x56e610, 0x20

gUnknown_0856E630:: @ 856E630
	.incbin "baserom.gba", 0x56e630, 0x10

gUnknown_0856E640:: @ 856E640
	.incbin "baserom.gba", 0x56e640, 0x28

gUnknown_0856E668:: @ 856E668
	.incbin "baserom.gba", 0x56e668, 0x8

gUnknown_0856E670:: @ 856E670
	.incbin "baserom.gba", 0x56e670, 0x18

gUnknown_0856E688:: @ 856E688
	.incbin "baserom.gba", 0x56e688, 0xc

@ 856E694
	.include "data/graphics/pokemon/footprint_table.inc"

gUnknown_0856ED08:: @ 856ED08
	.incbin "baserom.gba", 0x56ed08, 0x28

gUnknown_0856ED30:: @ 856ED30
	.incbin "baserom.gba", 0x56ed30, 0x18

gUnknown_0856ED48:: @ 856ED48
	.incbin "baserom.gba", 0x56ed48, 0x54

gUnknown_0856ED9C:: @ 856ED9C
	.incbin "baserom.gba", 0x56ed9c, 0x1c

gUnknown_0856EDB8:: @ 856EDB8
	.incbin "baserom.gba", 0x56edb8, 0x1c

gUnknown_0856EDD4:: @ 856EDD4
	.incbin "baserom.gba", 0x56edd4, 0x1c

gUnknown_0856EDF0:: @ 856EDF0
	.incbin "baserom.gba", 0x56edf0, 0x1c

gUnknown_0856EE0C:: @ 856EE0C
	.incbin "baserom.gba", 0x56ee0c, 0x18

gUnknown_0856EE24:: @ 856EE24
	.incbin "baserom.gba", 0x56ee24, 0x38

gUnknown_0856EE5C:: @ 856EE5C
	.incbin "baserom.gba", 0x56ee5c, 0x58

gUnknown_0856EEB4:: @ 856EEB4
	.incbin "baserom.gba", 0x56eeb4, 0x60

gUnknown_0856EF14:: @ 856EF14
	.incbin "baserom.gba", 0x56ef14, 0x98

gUnknown_0856EFAC:: @ 856EFAC
	.incbin "baserom.gba", 0x56efac, 0x2

gUnknown_0856EFAE:: @ 856EFAE
	.incbin "baserom.gba", 0x56efae, 0x6

gUnknown_0856EFB4:: @ 856EFB4
	.incbin "baserom.gba", 0x56efb4, 0x14

gUnknown_0856EFC8:: @ 856EFC8
	.incbin "baserom.gba", 0x56efc8, 0x30

gUnknown_0856EFF8:: @ 856EFF8
	.incbin "baserom.gba", 0x56eff8, 0x10

gUnknown_0856F008:: @ 856F008
	.incbin "baserom.gba", 0x56f008, 0x10
