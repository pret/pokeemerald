@ the third big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

    .align 2
    .incbin "baserom.gba", 0x58d978, 0x2a0
    
	.align 2
gFieldEffectObjectPalette7:: @ 858DC18
	.incbin "graphics/map_objects/palettes/field_effect_object_palette_07.gbapal"

	.incbin "baserom.gba", 0x58dc38, 0x580

	.align 2
gFieldEffectObjectPalette8:: @ 858E1B8
	.incbin "graphics/map_objects/palettes/field_effect_object_palette_08.gbapal"

	.incbin "baserom.gba", 0x58e1d8, 0x428

gUnknown_0858E600:: @ 858E600
	.incbin "baserom.gba", 0x58e600, 0x18

gUnknown_0858E618:: @ 858E618
	.incbin "baserom.gba", 0x58e618, 0x18

gUnknown_0858E630:: @ 858E630
	.incbin "baserom.gba", 0x58e630, 0x18

	.align 2
gFieldEffectObjectPaletteInfo7:: @ 858E648
	obj_pal gFieldEffectObjectPalette7, 0x1003

	.align 2
gFieldEffectObjectPaletteInfo8:: @ 858E650
	obj_pal gFieldEffectObjectPalette8, 0x1008

	.incbin "baserom.gba", 0x58e658, 0x34

gUnknown_0858E68C:: @ 858E68C
	.incbin "baserom.gba", 0x58e68c, 0x18

	.align 2
@ This uses one of the secret base palettes, so there is no
@ "field_effect_object_palette_09.pal" file.
gFieldEffectObjectPaletteInfo9:: @ 858E6A4
	obj_pal gTilesetPalettes_SecretBase + 5 * 0x20, 0x100E

	.incbin "baserom.gba", 0x58e6ac, 0x1b8

gUnknown_0858E864:: @ 858E864
	.incbin "baserom.gba", 0x58e864, 0x1c

gUnknown_0858E880:: @ 858E880
	.incbin "baserom.gba", 0x58e880, 0x18

gUnknown_0858E898:: @ 858E898
	.incbin "baserom.gba", 0x58e898, 0x13

gUnknown_0858E8AB:: @ 858E8AB
	.incbin "baserom.gba", 0x58e8ab, 0x2

gUnknown_0858E8AD:: @ 858E8AD
	.incbin "baserom.gba", 0x58e8ad, 0x3

gUnknown_0858E8B0:: @ 858E8B0
	.incbin "baserom.gba", 0x58e8b0, 0x40

gUnknown_0858E8F0:: @ 858E8F0
	.incbin "baserom.gba", 0x58e8f0, 0x3468

gUnknown_08591D58:: @ 8591D58
	.incbin "baserom.gba", 0x591d58, 0x270

gUnknown_08591FC8:: @ 8591FC8
	.incbin "baserom.gba", 0x591fc8, 0x18

gUnknown_08591FE0:: @ 8591FE0
	.incbin "baserom.gba", 0x591fe0, 0x18

gUnknown_08591FF8:: @ 8591FF8
	.incbin "baserom.gba", 0x591ff8, 0x10

gUnknown_08592008:: @ 8592008
	.incbin "baserom.gba", 0x592008, 0x10

gUnknown_08592018:: @ 8592018
	.incbin "baserom.gba", 0x592018, 0x10

gUnknown_08592028:: @ 8592028
	.incbin "baserom.gba", 0x592028, 0x10

gUnknown_08592038:: @ 8592038
	.incbin "baserom.gba", 0x592038, 0x20

gUnknown_08592058:: @ 8592058
	.incbin "baserom.gba", 0x592058, 0x20

gUnknown_08592078:: @ 8592078
	.incbin "baserom.gba", 0x592078, 0x60

gUnknown_085920D8:: @ 85920D8
	.incbin "baserom.gba", 0x5920d8, 0xc

gUnknown_085920E4:: @ 85920E4
	.incbin "baserom.gba", 0x5920e4, 0x4

gUnknown_085920E8:: @ 85920E8
	.incbin "baserom.gba", 0x5920e8, 0x128

gUnknown_08592210:: @ 8592210
	.incbin "baserom.gba", 0x592210, 0x4f0

gUnknown_08592700:: @ 8592700
	.incbin "baserom.gba", 0x592700, 0x78

gUnknown_08592778:: @ 8592778
	.incbin "baserom.gba", 0x592778, 0x100

gUnknown_08592878:: @ 8592878
	.incbin "baserom.gba", 0x592878, 0x458

gUnknown_08592CD0:: @ 8592CD0
	.incbin "baserom.gba", 0x592cd0, 0x1ec

gUnknown_08592EBC:: @ 8592EBC
	.incbin "baserom.gba", 0x592ebc, 0x30

gUnknown_08592EEC:: @ 8592EEC
	.incbin "baserom.gba", 0x592eec, 0x134

gUnknown_08593020:: @ 8593020
	.incbin "baserom.gba", 0x593020, 0xf4

gUnknown_08593114:: @ 8593114
	.incbin "baserom.gba", 0x593114, 0x29c

gUnknown_085933B0:: @ 85933B0
	.incbin "baserom.gba", 0x5933b0, 0xf0

gUnknown_085934A0:: @ 85934A0
	.incbin "baserom.gba", 0x5934a0, 0x148

gUnknown_085935E8:: @ 85935E8
	.incbin "baserom.gba", 0x5935e8, 0x20

gUnknown_08593608:: @ 8593608
	.incbin "baserom.gba", 0x593608, 0x9c

gUnknown_085936A4:: @ 85936A4
	.incbin "baserom.gba", 0x5936a4, 0x20c

gUnknown_085938B0:: @ 85938B0
	.incbin "baserom.gba", 0x5938b0, 0x2c

gUnknown_085938DC:: @ 85938DC
	.incbin "baserom.gba", 0x5938dc, 0x18

gUnknown_085938F4:: @ 85938F4
	.incbin "baserom.gba", 0x5938f4, 0x5c

gUnknown_08593950:: @ 8593950
	.incbin "baserom.gba", 0x593950, 0x38

gUnknown_08593988:: @ 8593988
	.incbin "baserom.gba", 0x593988, 0x210

gUnknown_08593B98:: @ 8593B98
	.incbin "baserom.gba", 0x593b98, 0x1488

gUnknown_08595020:: @ 8595020
	.incbin "baserom.gba", 0x595020, 0x248

gUnknown_08595268:: @ 8595268
	.incbin "baserom.gba", 0x595268, 0xa8

gUnknown_08595310:: @ 8595310
	.incbin "baserom.gba", 0x595310, 0x2a4

gUnknown_085955B4:: @ 85955B4
	.incbin "baserom.gba", 0x5955b4, 0x18

gUnknown_085955CC:: @ 85955CC
	.incbin "baserom.gba", 0x5955cc, 0x2

gUnknown_085955CE:: @ 85955CE
	.incbin "baserom.gba", 0x5955ce, 0xb6

gUnknown_08595684:: @ 8595684
	.incbin "baserom.gba", 0x595684, 0x10

gUnknown_08595694:: @ 8595694
	.incbin "baserom.gba", 0x595694, 0x2c

gUnknown_085956C0:: @ 85956C0
	.incbin "baserom.gba", 0x5956c0, 0x168

gUnknown_08595828:: @ 8595828
	.incbin "baserom.gba", 0x595828, 0x18

gUnknown_08595840:: @ 8595840
	.incbin "baserom.gba", 0x595840, 0x18

gUnknown_08595858:: @ 8595858
	.incbin "baserom.gba", 0x595858, 0x50

gUnknown_085958A8:: @ 85958A8
	.incbin "baserom.gba", 0x5958a8, 0x158

gUnknown_08595A00:: @ 8595A00
	.incbin "baserom.gba", 0x595a00, 0x30

gUnknown_08595A30:: @ 8595A30
	.incbin "baserom.gba", 0x595a30, 0x138

gUnknown_08595B68:: @ 8595B68
	.incbin "baserom.gba", 0x595b68, 0xf4

gUnknown_08595C5C:: @ 8595C5C
	.incbin "baserom.gba", 0x595c5c, 0x2c

gUnknown_08595C88:: @ 8595C88
	.incbin "baserom.gba", 0x595c88, 0x2c

gUnknown_08595CB4:: @ 8595CB4
	.incbin "baserom.gba", 0x595cb4, 0x78

gUnknown_08595D2C:: @ 8595D2C
	.incbin "baserom.gba", 0x595d2c, 0xa14

gUnknown_08596740:: @ 8596740
	.incbin "baserom.gba", 0x596740, 0x1c

gUnknown_0859675C:: @ 859675C
	.incbin "baserom.gba", 0x59675c, 0x20

gUnknown_0859677C:: @ 859677C
	.incbin "baserom.gba", 0x59677c, 0x18

gUnknown_08596794:: @ 8596794
	.incbin "baserom.gba", 0x596794, 0xd0

gUnknown_08596864:: @ 8596864
	.incbin "baserom.gba", 0x596864, 0x35c

gUnknown_08596BC0:: @ 8596BC0
	.incbin "baserom.gba", 0x596bc0, 0x50

gUnknown_08596C10:: @ 8596C10
	.incbin "baserom.gba", 0x596c10, 0x18

gUnknown_08596C28:: @ 8596C28
	.incbin "baserom.gba", 0x596c28, 0x18

gUnknown_08596C40:: @ 8596C40
	.incbin "baserom.gba", 0x596c40, 0x178

gUnknown_08596DB8:: @ 8596DB8
	.incbin "baserom.gba", 0x596db8, 0x78

gUnknown_08596E30:: @ 8596E30
	.incbin "baserom.gba", 0x596e30, 0x528

gUnknown_08597358:: @ 8597358
	.incbin "baserom.gba", 0x597358, 0x30

gUnknown_08597388:: @ 8597388
	.incbin "baserom.gba", 0x597388, 0x60

gUnknown_085973E8:: @ 85973E8
	.incbin "baserom.gba", 0x5973e8, 0x30

gUnknown_08597418:: @ 8597418
	.incbin "baserom.gba", 0x597418, 0x2

gUnknown_0859741A:: @ 859741A
	.incbin "baserom.gba", 0x59741a, 0x4

gUnknown_0859741E:: @ 859741E
	.incbin "baserom.gba", 0x59741e, 0x6

gUnknown_08597424:: @ 8597424
	.incbin "baserom.gba", 0x597424, 0x28

gUnknown_0859744C:: @ 859744C
	.incbin "baserom.gba", 0x59744c, 0x10

gUnknown_0859745C:: @ 859745C
	.incbin "baserom.gba", 0x59745c, 0xc

gUnknown_08597468:: @ 8597468
	.incbin "baserom.gba", 0x597468, 0x34

gUnknown_0859749C:: @ 859749C
	.incbin "baserom.gba", 0x59749c, 0x1c

gUnknown_085974B8:: @ 85974B8
	.incbin "baserom.gba", 0x5974b8, 0x8

gUnknown_085974C0:: @ 85974C0
	.incbin "baserom.gba", 0x5974c0, 0x70

gUnknown_08597530:: @ 8597530
	.incbin "baserom.gba", 0x597530, 0x20

gUnknown_08597550:: @ 8597550
	.incbin "baserom.gba", 0x597550, 0x1f8

gUnknown_08597748:: @ 8597748
	.incbin "baserom.gba", 0x597748, 0x1c

gUnknown_08597764:: @ 8597764
	.incbin "baserom.gba", 0x597764, 0x8

gUnknown_0859776C:: @ 859776C
	.incbin "baserom.gba", 0x59776c, 0x3a8

gUnknown_08597B14:: @ 8597B14
	.incbin "baserom.gba", 0x597b14, 0x20

gUnknown_08597B34:: @ 8597B34
	.incbin "baserom.gba", 0x597b34, 0x20

gUnknown_08597B54:: @ 8597B54
	.incbin "baserom.gba", 0x597b54, 0xc8

gUnknown_08597C1C:: @ 8597C1C
	.incbin "baserom.gba", 0x597c1c, 0x8

gUnknown_08597C24:: @ 8597C24
	.incbin "baserom.gba", 0x597c24, 0xc

gUnknown_08597C30:: @ 8597C30
	.incbin "baserom.gba", 0x597c30, 0x24

gUnknown_08597C54:: @ 8597C54
	.incbin "baserom.gba", 0x597c54, 0x10

gUnknown_08597C64:: @ 8597C64
	.incbin "baserom.gba", 0x597c64, 0x20

gUnknown_08597C84:: @ 8597C84
	.incbin "baserom.gba", 0x597c84, 0x8

gUnknown_08597C8C:: @ 8597C8C
	.incbin "baserom.gba", 0x597c8c, 0x4

gUnknown_08597C90:: @ 8597C90
	.incbin "baserom.gba", 0x597c90, 0x10

gUnknown_08597CA0:: @ 8597CA0
	.incbin "baserom.gba", 0x597ca0, 0x20

gUnknown_08597CC0:: @ 8597CC0
	.incbin "baserom.gba", 0x597cc0, 0x28

gUnknown_08597CE8:: @ 8597CE8
	.incbin "baserom.gba", 0x597ce8, 0x20

gUnknown_08597D08:: @ 8597D08
	.incbin "baserom.gba", 0x597d08, 0x10

gUnknown_08597D18:: @ 8597D18
	.incbin "baserom.gba", 0x597d18, 0x50

gUnknown_08597D68:: @ 8597D68
	.incbin "baserom.gba", 0x597d68, 0x68

gUnknown_08597DD0:: @ 8597DD0
	.incbin "baserom.gba", 0x597dd0, 0x20

gUnknown_08597DF0:: @ 8597DF0
	.incbin "baserom.gba", 0x597df0, 0x40

gUnknown_08597E30:: @ 8597E30
	.incbin "baserom.gba", 0x597e30, 0x18

gUnknown_08597E48:: @ 8597E48
	.incbin "baserom.gba", 0x597e48, 0x18

gUnknown_08597E60:: @ 8597E60
	.incbin "baserom.gba", 0x597e60, 0xc

gUnknown_08597E6C:: @ 8597E6C
	.incbin "baserom.gba", 0x597e6c, 0x30

@ 8597E9C
	.include "data/text/easy_chat/easy_chat_groups.inc"

@ 859D0B4
	.include "data/text/easy_chat/easy_chat_words_by_letter.inc"

@ 859E5D4
	.include "data/text/easy_chat/easy_chat_group_name_pointers.inc"

gUnknown_0859E62C:: @ 859E62C
	.incbin "baserom.gba", 0x59e62c, 0x8

gUnknown_0859E634:: @ 859E634
	.incbin "baserom.gba", 0x59e634, 0xc

gUnknown_0859E640:: @ 859E640
	.incbin "baserom.gba", 0x59e640, 0xc

gUnknown_0859E64C:: @ 859E64C
	.incbin "baserom.gba", 0x59e64c, 0xc

gUnknown_0859E658:: @ 859E658
	.incbin "baserom.gba", 0x59e658, 0x4

gUnknown_0859E65C:: @ 859E65C
	.incbin "baserom.gba", 0x59e65c, 0x20

gUnknown_0859E67C:: @ 859E67C
	.incbin "baserom.gba", 0x59e67c, 0x800

gUnknown_0859EE7C:: @ 859EE7C
	.incbin "baserom.gba", 0x59ee7c, 0x8

gUnknown_0859EE84:: @ 859EE84
	.incbin "baserom.gba", 0x59ee84, 0x58

gUnknown_0859EEDC:: @ 859EEDC
	.incbin "baserom.gba", 0x59eedc, 0x38

gUnknown_0859EF14:: @ 859EF14
	.incbin "baserom.gba", 0x59ef14, 0x8

gUnknown_0859EF1C:: @ 859EF1C
	.incbin "baserom.gba", 0x59ef1c, 0x88

gUnknown_0859EFA4:: @ 859EFA4
	.incbin "baserom.gba", 0x59efa4, 0x40

gUnknown_0859EFE4:: @ 859EFE4
	.incbin "baserom.gba", 0x59efe4, 0xc

gUnknown_0859EFF0:: @ 859EFF0
	.incbin "baserom.gba", 0x59eff0, 0x20

gUnknown_0859F010:: @ 859F010
	.incbin "baserom.gba", 0x59f010, 0x20

gUnknown_0859F030:: @ 859F030
	.incbin "baserom.gba", 0x59f030, 0x18

gUnknown_0859F048:: @ 859F048
	.incbin "baserom.gba", 0x59f048, 0x230

gUnknown_0859F278:: @ 859F278
	.incbin "baserom.gba", 0x59f278, 0x10

gUnknown_0859F288:: @ 859F288
	.incbin "baserom.gba", 0x59f288, 0x8

gUnknown_0859F290:: @ 859F290
	.incbin "baserom.gba", 0x59f290, 0xc

gUnknown_0859F29C:: @ 859F29C
	.incbin "baserom.gba", 0x59f29c, 0x10

gUnknown_0859F2AC:: @ 859F2AC
	.incbin "baserom.gba", 0x59f2ac, 0x4

gUnknown_0859F2B0:: @ 859F2B0
	.incbin "baserom.gba", 0x59f2b0, 0x8

gUnknown_0859F2B8:: @ 859F2B8
	.incbin "baserom.gba", 0x59f2b8, 0xfc

gUnknown_0859F3B4:: @ 859F3B4
	.incbin "baserom.gba", 0x59f3b4, 0xa4

gUnknown_0859F458:: @ 859F458
	.incbin "baserom.gba", 0x59f458, 0xbc

gUnknown_0859F514:: @ 859F514
	.incbin "baserom.gba", 0x59f514, 0x8

gUnknown_0859F51C:: @ 859F51C
	.incbin "baserom.gba", 0x59f51c, 0x8

gUnknown_0859F524:: @ 859F524
	.incbin "baserom.gba", 0x59f524, 0x10

gUnknown_0859F534:: @ 859F534
	.incbin "baserom.gba", 0x59f534, 0x8

gUnknown_0859F53C:: @ 859F53C
	.incbin "baserom.gba", 0x59f53c, 0xd0

gUnknown_0859F60C:: @ 859F60C
	.incbin "baserom.gba", 0x59f60c, 0x44

gUnknown_0859F650:: @ 859F650
	.incbin "baserom.gba", 0x59f650, 0xec

gUnknown_0859F73C:: @ 859F73C
	.incbin "baserom.gba", 0x59f73c, 0x40

gUnknown_0859F77C:: @ 859F77C
	.incbin "baserom.gba", 0x59f77c, 0xd64

gUnknown_085A04E0:: @ 85A04E0
	.incbin "baserom.gba", 0x5a04e0, 0x34c

gUnknown_085A082C:: @ 85A082C
	.incbin "baserom.gba", 0x5a082c, 0x20

gUnknown_085A084C:: @ 85A084C
	.incbin "baserom.gba", 0x5a084c, 0x80

gUnknown_085A08CC:: @ 85A08CC
	.incbin "baserom.gba", 0x5a08cc, 0x20

gUnknown_085A08EC:: @ 85A08EC
	.incbin "baserom.gba", 0x5a08ec, 0x80

gUnknown_085A096C:: @ 85A096C
	.incbin "baserom.gba", 0x5a096c, 0x1a4

@ 85A0B10
	.include "data/region_map_entries.inc"

gUnknown_085A1B24:: @ 85A1B24
	.incbin "baserom.gba", 0x5a1b24, 0x60

gUnknown_085A1B84:: @ 85A1B84
	.incbin "baserom.gba", 0x5a1b84, 0x6

gUnknown_085A1B8A:: @ 85A1B8A
	.incbin "baserom.gba", 0x5a1b8a, 0x22

gUnknown_085A1BAC:: @ 85A1BAC
	.incbin "baserom.gba", 0x5a1bac, 0x20

gUnknown_085A1BCC:: @ 85A1BCC
	.incbin "baserom.gba", 0x5a1bcc, 0x34

gUnknown_085A1C00:: @ 85A1C00
	.incbin "baserom.gba", 0x5a1c00, 0x8

gUnknown_085A1C08:: @ 85A1C08
	.incbin "baserom.gba", 0x5a1c08, 0x18

gUnknown_085A1C20:: @ 85A1C20
	.incbin "baserom.gba", 0x5a1c20, 0x10

gUnknown_085A1C30:: @ 85A1C30
	.incbin "baserom.gba", 0x5a1c30, 0x4

gUnknown_085A1C34:: @ 85A1C34
	.incbin "baserom.gba", 0x5a1c34, 0x4

gUnknown_085A1C38:: @ 85A1C38
	.incbin "baserom.gba", 0x5a1c38, 0x20

gUnknown_085A1C58:: @ 85A1C58
	.incbin "baserom.gba", 0x5a1c58, 0x38

gUnknown_085A1C90:: @ 85A1C90
	.incbin "baserom.gba", 0x5a1c90, 0xd8

gUnknown_085A1D68:: @ 85A1D68
	.incbin "baserom.gba", 0x5a1d68, 0xd4

gUnknown_085A1E3C:: @ 85A1E3C
	.incbin "baserom.gba", 0x5a1e3c, 0xa0

gUnknown_085A1EDC:: @ 85A1EDC
	.incbin "baserom.gba", 0x5a1edc, 0x8

gUnknown_085A1EE4:: @ 85A1EE4
	.incbin "baserom.gba", 0x5a1ee4, 0xc

gUnknown_085A1EF0:: @ 85A1EF0
	.incbin "baserom.gba", 0x5a1ef0, 0x20

gUnknown_085A1F10:: @ 85A1F10
	.incbin "baserom.gba", 0x5a1f10, 0x8

gUnknown_085A1F18:: @ 85A1F18
	.incbin "baserom.gba", 0x5a1f18, 0x64

gUnknown_085A1F7C:: @ 85A1F7C
	.incbin "baserom.gba", 0x5a1f7c, 0x18

gUnknown_085A1F94:: @ 85A1F94
	.incbin "baserom.gba", 0x5a1f94, 0x3c74

gDecorations:: @ 85A5C08
	.incbin "baserom.gba", 0x5a5c08, 0x1

gUnknown_085A5C09:: @ 85A5C09
	.incbin "baserom.gba", 0x5a5c09, 0x1b

gUnknown_085A5C24:: @ 85A5C24
	.incbin "baserom.gba", 0x5a5c24, 0xf04

gUnknown_085A6B28:: @ 85A6B28
	.incbin "baserom.gba", 0x5a6b28, 0x20

gUnknown_085A6B48:: @ 85A6B48
	.incbin "baserom.gba", 0x5a6b48, 0x20

gUnknown_085A6B68:: @ 85A6B68
	.incbin "baserom.gba", 0x5a6b68, 0x10

gUnknown_085A6B78:: @ 85A6B78
	.incbin "baserom.gba", 0x5a6b78, 0x18

gUnknown_085A6B90:: @ 85A6B90
	.incbin "baserom.gba", 0x5a6b90, 0x20

gUnknown_085A6BB0:: @ 85A6BB0
	.incbin "baserom.gba", 0x5a6bb0, 0x20

gUnknown_085A6BD0:: @ 85A6BD0
	.incbin "baserom.gba", 0x5a6bd0, 0x18

gUnknown_085A6BE8:: @ 85A6BE8
	.incbin "baserom.gba", 0x5a6be8, 0x5c8

gUnknown_085A71B0:: @ 85A71B0
	.incbin "baserom.gba", 0x5a71b0, 0xa0

gUnknown_085A7250:: @ 85A7250
	.incbin "baserom.gba", 0x5a7250, 0x3c

gUnknown_085A728C:: @ 85A728C
	.incbin "baserom.gba", 0x5a728c, 0x18

gUnknown_085A72A4:: @ 85A72A4
	.incbin "baserom.gba", 0x5a72a4, 0x18

gUnknown_085A72BC:: @ 85A72BC
	.incbin "baserom.gba", 0x5a72bc, 0x8

gUnknown_085A72C4:: @ 85A72C4
	.incbin "baserom.gba", 0x5a72c4, 0x8

gUnknown_085A72CC:: @ 85A72CC
	.incbin "baserom.gba", 0x5a72cc, 0x8

gUnknown_085A72D4:: @ 85A72D4
	.incbin "baserom.gba", 0x5a72d4, 0x10

gUnknown_085A72E4:: @ 85A72E4
	.incbin "baserom.gba", 0x5a72e4, 0x8

gUnknown_085A72EC:: @ 85A72EC
	.incbin "baserom.gba", 0x5a72ec, 0x8

gUnknown_085A72F4:: @ 85A72F4
	.incbin "baserom.gba", 0x5a72f4, 0x54

gUnknown_085A7348:: @ 85A7348
	.incbin "baserom.gba", 0x5a7348, 0x8

gUnknown_085A7350:: @ 85A7350
	.incbin "baserom.gba", 0x5a7350, 0x88

gUnknown_085A73D8:: @ 85A73D8
	.incbin "baserom.gba", 0x5a73d8, 0x8

gUnknown_085A73E0:: @ 85A73E0
	.incbin "baserom.gba", 0x5a73e0, 0x24

gUnknown_085A7404:: @ 85A7404
	.incbin "baserom.gba", 0x5a7404, 0x18

gUnknown_085A741C:: @ 85A741C
	.incbin "baserom.gba", 0x5a741c, 0x8

gUnknown_085A7424:: @ 85A7424
	.incbin "baserom.gba", 0x5a7424, 0x10

gUnknown_085A7434:: @ 85A7434
	.incbin "baserom.gba", 0x5a7434, 0x10

gUnknown_085A7444:: @ 85A7444
	.incbin "baserom.gba", 0x5a7444, 0x8

gUnknown_085A744C:: @ 85A744C
	.incbin "baserom.gba", 0x5a744c, 0x4

gUnknown_085A7450:: @ 85A7450
	.incbin "baserom.gba", 0x5a7450, 0x74

gUnknown_085A74C4:: @ 85A74C4
	.incbin "baserom.gba", 0x5a74c4, 0xc

gUnknown_085A74D0:: @ 85A74D0
	.incbin "baserom.gba", 0x5a74d0, 0x14

gUnknown_085A74E4:: @ 85A74E4
	.incbin "baserom.gba", 0x5a74e4, 0xc

gUnknown_085A74F0:: @ 85A74F0
	.incbin "baserom.gba", 0x5a74f0, 0xc

gUnknown_085A74FC:: @ 85A74FC
	.incbin "baserom.gba", 0x5a74fc, 0xc

gUnknown_085A7508:: @ 85A7508
	.incbin "baserom.gba", 0x5a7508, 0xc

gUnknown_085A7514:: @ 85A7514
	.incbin "baserom.gba", 0x5a7514, 0xc

gUnknown_085A7520:: @ 85A7520
	.incbin "baserom.gba", 0x5a7520, 0xc

gUnknown_085A752C:: @ 85A752C
	.incbin "baserom.gba", 0x5a752c, 0xc

gUnknown_085A7538:: @ 85A7538
	.incbin "baserom.gba", 0x5a7538, 0xc

gUnknown_085A7544:: @ 85A7544
	.incbin "baserom.gba", 0x5a7544, 0xc

gUnknown_085A7550:: @ 85A7550
	.incbin "baserom.gba", 0x5a7550, 0x8

gUnknown_085A7558:: @ 85A7558
	.incbin "baserom.gba", 0x5a7558, 0x10

gUnknown_085A7568:: @ 85A7568
	.incbin "baserom.gba", 0x5a7568, 0x2

gUnknown_085A756A:: @ 85A756A
	.incbin "baserom.gba", 0x5a756a, 0xa

gUnknown_085A7574:: @ 85A7574
	.incbin "baserom.gba", 0x5a7574, 0x4c

gUnknown_085A75C0:: @ 85A75C0
	.incbin "baserom.gba", 0x5a75c0, 0x4

gUnknown_085A75C4:: @ 85A75C4
	.incbin "baserom.gba", 0x5a75c4, 0x8

gUnknown_085A75CC:: @ 85A75CC
	.incbin "baserom.gba", 0x5a75cc, 0x8

gUnknown_085A75D4:: @ 85A75D4
	.incbin "baserom.gba", 0x5a75d4, 0x3c

gUnknown_085A7610:: @ 85A7610
	.incbin "baserom.gba", 0x5a7610, 0x4

gUnknown_085A7614:: @ 85A7614
	.incbin "baserom.gba", 0x5a7614, 0x2

gUnknown_085A7616:: @ 85A7616
	.incbin "baserom.gba", 0x5a7616, 0x8

gUnknown_085A761E:: @ 85A761E
	.incbin "baserom.gba", 0x5a761e, 0x8

gUnknown_085A7626:: @ 85A7626
	.incbin "baserom.gba", 0x5a7626, 0x8

gUnknown_085A762E:: @ 85A762E
	.incbin "baserom.gba", 0x5a762e, 0x10

gUnknown_085A763E:: @ 85A763E
	.incbin "baserom.gba", 0x5a763e, 0x10

gUnknown_085A764E:: @ 85A764E
	.incbin "baserom.gba", 0x5a764e, 0x10

gUnknown_085A765E:: @ 85A765E
	.incbin "baserom.gba", 0x5a765e, 0x10

gUnknown_085A766E:: @ 85A766E
	.incbin "baserom.gba", 0x5a766e, 0x3f

gUnknown_085A76AD:: @ 85A76AD
	.incbin "baserom.gba", 0x5a76ad, 0x7

gUnknown_085A76B4:: @ 85A76B4
	.incbin "baserom.gba", 0x5a76b4, 0xc

gUnknown_085A76C0:: @ 85A76C0
	.incbin "baserom.gba", 0x5a76c0, 0x12

gUnknown_085A76D2:: @ 85A76D2
	.incbin "baserom.gba", 0x5a76d2, 0x12

gUnknown_085A76E4:: @ 85A76E4
	.incbin "baserom.gba", 0x5a76e4, 0x1e

gUnknown_085A7702:: @ 85A7702
	.incbin "baserom.gba", 0x5a7702, 0x66

gUnknown_085A7768:: @ 85A7768
	.incbin "baserom.gba", 0x5a7768, 0x66

gUnknown_085A77CE:: @ 85A77CE
	.incbin "baserom.gba", 0x5a77ce, 0xa

gUnknown_085A77D8:: @ 85A77D8
	.incbin "baserom.gba", 0x5a77d8, 0x14

gUnknown_085A77EC:: @ 85A77EC
	.incbin "baserom.gba", 0x5a77ec, 0xa

gUnknown_085A77F6:: @ 85A77F6
	.incbin "baserom.gba", 0x5a77f6, 0x8

gUnknown_085A77FE:: @ 85A77FE
	.incbin "baserom.gba", 0x5a77fe, 0x6

gUnknown_085A7804:: @ 85A7804
	.incbin "baserom.gba", 0x5a7804, 0xa

gUnknown_085A780E:: @ 85A780E
	.incbin "baserom.gba", 0x5a780e, 0x8

gUnknown_085A7816:: @ 85A7816
	.incbin "baserom.gba", 0x5a7816, 0x12

gUnknown_085A7828:: @ 85A7828
	.incbin "baserom.gba", 0x5a7828, 0x12

gUnknown_085A783A:: @ 85A783A
	.incbin "baserom.gba", 0x5a783a, 0x8e

gUnknown_085A78C8:: @ 85A78C8
	.incbin "baserom.gba", 0x5a78c8, 0x13c

gUnknown_085A7A04:: @ 85A7A04
	.incbin "baserom.gba", 0x5a7a04, 0x1c

gUnknown_085A7A20:: @ 85A7A20
	.incbin "baserom.gba", 0x5a7a20, 0x2c0

gUnknown_085A7CE0:: @ 85A7CE0
	.incbin "baserom.gba", 0x5a7ce0, 0x18

gUnknown_085A7CF8:: @ 85A7CF8
	.incbin "baserom.gba", 0x5a7cf8, 0x18

gUnknown_085A7D10:: @ 85A7D10
	.incbin "baserom.gba", 0x5a7d10, 0x18

gUnknown_085A7D28:: @ 85A7D28
	.incbin "baserom.gba", 0x5a7d28, 0x18

gUnknown_085A7D40:: @ 85A7D40
	.incbin "baserom.gba", 0x5a7d40, 0x18

gUnknown_085A7D58:: @ 85A7D58
	.incbin "baserom.gba", 0x5a7d58, 0x18

gUnknown_085A7D70:: @ 85A7D70
	.incbin "baserom.gba", 0x5a7d70, 0x18

gUnknown_085A7D88:: @ 85A7D88
	.incbin "baserom.gba", 0x5a7d88, 0x18

gUnknown_085A7DA0:: @ 85A7DA0
	.incbin "baserom.gba", 0x5a7da0, 0x18

gUnknown_085A7DB8:: @ 85A7DB8
	.incbin "baserom.gba", 0x5a7db8, 0x18

gUnknown_085A7DD0:: @ 85A7DD0
	.incbin "baserom.gba", 0x5a7dd0, 0x18

gUnknown_085A7DE8:: @ 85A7DE8
	.incbin "baserom.gba", 0x5a7de8, 0x18

gUnknown_085A7E00:: @ 85A7E00
	.incbin "baserom.gba", 0x5a7e00, 0x18

gUnknown_085A7E18:: @ 85A7E18
	.incbin "baserom.gba", 0x5a7e18, 0x18

gUnknown_085A7E30:: @ 85A7E30
	.incbin "baserom.gba", 0x5a7e30, 0x168

gUnknown_085A7F98:: @ 85A7F98
	.incbin "baserom.gba", 0x5a7f98, 0x28

gUnknown_085A7FC0:: @ 85A7FC0
	.incbin "baserom.gba", 0x5a7fc0, 0x20

gUnknown_085A7FE0:: @ 85A7FE0
	.incbin "baserom.gba", 0x5a7fe0, 0x14

gUnknown_085A7FF4:: @ 85A7FF4
	.incbin "baserom.gba", 0x5a7ff4, 0x1c

gUnknown_085A8010:: @ 85A8010
	.incbin "baserom.gba", 0x5a8010, 0x18

gUnknown_085A8028:: @ 85A8028
	.incbin "baserom.gba", 0x5a8028, 0x14

gUnknown_085A803C:: @ 85A803C
	.incbin "baserom.gba", 0x5a803c, 0x228

gUnknown_085A8264:: @ 85A8264
	.incbin "baserom.gba", 0x5a8264, 0x68

gUnknown_085A82CC:: @ 85A82CC
	.incbin "baserom.gba", 0x5a82cc, 0x68

gUnknown_085A8334:: @ 85A8334
	.incbin "baserom.gba", 0x5a8334, 0xb0

gUnknown_085A83E4:: @ 85A83E4
	.incbin "baserom.gba", 0x5a83e4, 0x24

gUnknown_085A8408:: @ 85A8408
	.incbin "baserom.gba", 0x5a8408, 0x14

gUnknown_085A841C:: @ 85A841C
	.incbin "baserom.gba", 0x5a841c, 0x14

gUnknown_085A8430:: @ 85A8430
	.incbin "baserom.gba", 0x5a8430, 0x5

gUnknown_085A8435:: @ 85A8435
	.incbin "baserom.gba", 0x5a8435, 0x6

gUnknown_085A843B:: @ 85A843B
	.incbin "baserom.gba", 0x5a843b, 0x65

gUnknown_085A84A0:: @ 85A84A0
	.incbin "baserom.gba", 0x5a84a0, 0xc

gUnknown_085A84AC:: @ 85A84AC
	.incbin "baserom.gba", 0x5a84ac, 0x64

gUnknown_085A8510:: @ 85A8510
	.incbin "baserom.gba", 0x5a8510, 0x10

gUnknown_085A8520:: @ 85A8520
	.incbin "baserom.gba", 0x5a8520, 0x4

gUnknown_085A8524:: @ 85A8524
	.incbin "baserom.gba", 0x5a8524, 0x20

gUnknown_085A8544:: @ 85A8544
	.incbin "baserom.gba", 0x5a8544, 0x48

gUnknown_085A858C:: @ 85A858C
	.incbin "baserom.gba", 0x5a858c, 0x1154

gUnknown_085A96E0:: @ 85A96E0
	.incbin "baserom.gba", 0x5a96e0, 0x1b8

gUnknown_085A9898:: @ 85A9898
	.incbin "baserom.gba", 0x5a9898, 0x4

gUnknown_085A989C:: @ 85A989C
	.incbin "baserom.gba", 0x5a989c, 0x200

gUnknown_085A9A9C:: @ 85A9A9C
	.incbin "baserom.gba", 0x5a9a9c, 0x1084

gUnknown_085AAB20:: @ 85AAB20
	.incbin "baserom.gba", 0x5aab20, 0xc30

gUnknown_085AB750:: @ 85AB750
	.incbin "baserom.gba", 0x5ab750, 0xb38

gUnknown_085AC288:: @ 85AC288
	.incbin "baserom.gba", 0x5ac288, 0xfb8

gUnknown_085AD240:: @ 85AD240
	.incbin "baserom.gba", 0x5ad240, 0x1130

gUnknown_085AE370:: @ 85AE370
	.incbin "baserom.gba", 0x5ae370, 0x604

gUnknown_085AE974:: @ 85AE974
	.incbin "baserom.gba", 0x5ae974, 0x50c

gUnknown_085AEE80:: @ 85AEE80
	.incbin "baserom.gba", 0x5aee80, 0x50c

gUnknown_085AF38C:: @ 85AF38C
	.incbin "baserom.gba", 0x5af38c, 0x50c

gUnknown_085AF898:: @ 85AF898
	.incbin "baserom.gba", 0x5af898, 0x50c

gUnknown_085AFDA4:: @ 85AFDA4
	.incbin "baserom.gba", 0x5afda4, 0x50c

gUnknown_085B02B0:: @ 85B02B0
	.incbin "baserom.gba", 0x5b02b0, 0x524

gUnknown_085B07D4:: @ 85B07D4
	.incbin "baserom.gba", 0x5b07d4, 0x14

gUnknown_085B07E8:: @ 85B07E8
	.incbin "baserom.gba", 0x5b07e8, 0x4

gUnknown_085B07EC:: @ 85B07EC
	.incbin "baserom.gba", 0x5b07ec, 0x8

gUnknown_085B07F4:: @ 85B07F4
	.incbin "baserom.gba", 0x5b07f4, 0x3c

gUnknown_085B0830:: @ 85B0830
	.incbin "baserom.gba", 0x5b0830, 0x8

gUnknown_085B0838:: @ 85B0838
	.incbin "baserom.gba", 0x5b0838, 0x4
