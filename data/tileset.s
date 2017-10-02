	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_085105C4::
	.incbin "baserom.gba", 0x5105c4, 0x80

gUnknown_08510644::
	.incbin "baserom.gba", 0x510644, 0x80

gUnknown_085106C4::
	.incbin "baserom.gba", 0x5106c4, 0x80

	.space 0x20

gTilesetAnims_General0:: @ 8510764
@ replacing .incbin "baserom.gba", 0x00510764, 0x10
	.4byte gUnknown_08510644
	.4byte gUnknown_085105C4
	.4byte gUnknown_08510644
	.4byte gUnknown_085106C4

gUnknown_08510774::
	.incbin "baserom.gba", 0x510774, 0x3c0

gUnknown_08510B34::
	.incbin "baserom.gba", 0x510b34, 0x3c0

gUnknown_08510EF4::
	.incbin "baserom.gba", 0x510ef4, 0x3c0

gUnknown_085112B4::
	.incbin "baserom.gba", 0x5112b4, 0x3c0

gUnknown_08511674::
	.incbin "baserom.gba", 0x511674, 0x3c0

gUnknown_08511A34::
	.incbin "baserom.gba", 0x511a34, 0x3c0

gUnknown_08511DF4::
	.incbin "baserom.gba", 0x511df4, 0x3c0

gUnknown_085121B4::
	.incbin "baserom.gba", 0x5121b4, 0x3c0


gTilesetAnims_General1:: @ 8512574
@ replacing .incbin "baserom.gba", 0x00512574, 0x20
	.4byte gUnknown_08510774
	.4byte gUnknown_08510B34
	.4byte gUnknown_08510EF4
	.4byte gUnknown_085112B4
	.4byte gUnknown_08511674
	.4byte gUnknown_08511A34
	.4byte gUnknown_08511DF4
	.4byte gUnknown_085121B4

gUnknown_08512594::
	.incbin "baserom.gba", 0x512594, 0x140

gUnknown_085126D4::
	.incbin "baserom.gba", 0x5126d4, 0x140

gUnknown_08512814::
	.incbin "baserom.gba", 0x512814, 0x140

gUnknown_08512954::
	.incbin "baserom.gba", 0x512954, 0x140

gUnknown_08512A94::
	.incbin "baserom.gba", 0x512a94, 0x140

gUnknown_08512BD4::
	.incbin "baserom.gba", 0x512bd4, 0x140

gUnknown_08512D14::
	.incbin "baserom.gba", 0x512d14, 0x140


gTilesetAnims_General2:: @ 8512E54
@ replacing .incbin "baserom.gba", 0x00512e54, 0x20
	.4byte gUnknown_08512594
	.4byte gUnknown_085126D4
	.4byte gUnknown_08512814
	.4byte gUnknown_08512954
	.4byte gUnknown_08512A94
	.4byte gUnknown_08512BD4
	.4byte gUnknown_08512D14
	.4byte gUnknown_08512594

gUnknown_08512E74::
	.incbin "baserom.gba", 0x512e74, 0xc0

gUnknown_08512F34::
	.incbin "baserom.gba", 0x512f34, 0xc0

gUnknown_08512FF4::
	.incbin "baserom.gba", 0x512ff4, 0xc0

gUnknown_085130B4::
	.incbin "baserom.gba", 0x5130b4, 0xc0


gTilesetAnims_General3:: @ 8513174
@ replacing .incbin "baserom.gba", 0x00513174, 0x10
	.4byte gUnknown_08512E74
	.4byte gUnknown_08512F34
	.4byte gUnknown_08512FF4
	.4byte gUnknown_085130B4

gUnknown_08513184::
	.incbin "baserom.gba", 0x513184, 0x140

gUnknown_085132C4::
	.incbin "baserom.gba", 0x5132c4, 0x140

gUnknown_08513404::
	.incbin "baserom.gba", 0x513404, 0x140

gUnknown_08513544::
	.incbin "baserom.gba", 0x513544, 0x140


gTilesetAnims_General4:: @ 8513684
@ replacing .incbin "baserom.gba", 0x00513684, 0x10
	.4byte gUnknown_08513184
	.4byte gUnknown_085132C4
	.4byte gUnknown_08513404
	.4byte gUnknown_08513544

gUnknown_08513694::
	.incbin "baserom.gba", 0x513694, 0x80

gUnknown_08513714::
	.incbin "baserom.gba", 0x513714, 0x80

gUnknown_08513794::
	.incbin "baserom.gba", 0x513794, 0x80

gUnknown_08513814::
	.incbin "baserom.gba", 0x513814, 0x80


gTilesetAnims_Lavaridge0:: @ 8513894
@ replacing .incbin "baserom.gba", 0x00513894, 0x10
	.4byte gUnknown_08513694
	.4byte gUnknown_08513714
	.4byte gUnknown_08513794
	.4byte gUnknown_08513814

gUnknown_085138A4::
	.incbin "baserom.gba", 0x5138a4, 0x3c0

gUnknown_08513C64::
	.incbin "baserom.gba", 0x513c64, 0x3c0

gUnknown_08514024::
	.incbin "baserom.gba", 0x514024, 0x3c0


gTilesetAnims_Pacifidlog0:: @ 85143E4
@ replacing .incbin "baserom.gba", 0x005143e4, 0x10
	.4byte gUnknown_085138A4
	.4byte gUnknown_08513C64
	.4byte gUnknown_08514024
	.4byte gUnknown_08513C64

gUnknown_085143F4::
	.incbin "baserom.gba", 0x5143f4, 0x80

gUnknown_08514474::
	.incbin "baserom.gba", 0x514474, 0x80

gUnknown_085144F4::
	.incbin "baserom.gba", 0x5144f4, 0x80

gUnknown_08514574::
	.incbin "baserom.gba", 0x514574, 0x80


gTilesetAnims_Underwater0:: @ 85145F4
@ replacing .incbin "baserom.gba", 0x005145f4, 0x10
	.4byte gUnknown_085143F4
	.4byte gUnknown_08514474
	.4byte gUnknown_085144F4
	.4byte gUnknown_08514574

gUnknown_08514604::
	.incbin "baserom.gba", 0x514604, 0x100

gUnknown_08514704::
	.incbin "baserom.gba", 0x514704, 0x100

gUnknown_08514804::
	.incbin "baserom.gba", 0x514804, 0x100

gUnknown_08514904::
	.incbin "baserom.gba", 0x514904, 0x100

gUnknown_08514A04::
	.incbin "baserom.gba", 0x514a04, 0x100

gUnknown_08514B04::
	.incbin "baserom.gba", 0x514b04, 0x100

gUnknown_08514C04::
	.incbin "baserom.gba", 0x514c04, 0x100

gUnknown_08514D04::
	.incbin "baserom.gba", 0x514d04, 0x100


gTilesetAnims_Pacifidlog1:: @ 8514E04
@ replacing .incbin "baserom.gba", 0x00514e04, 0x20
	.4byte gUnknown_08514604
	.4byte gUnknown_08514704
	.4byte gUnknown_08514804
	.4byte gUnknown_08514904
	.4byte gUnknown_08514A04
	.4byte gUnknown_08514B04
	.4byte gUnknown_08514C04
	.4byte gUnknown_08514D04

gUnknown_08514E24::
	.incbin "baserom.gba", 0x514e24, 0x80

gUnknown_08514EA4::
	.incbin "baserom.gba", 0x514ea4, 0x80

gUnknown_08514F24::
	.incbin "baserom.gba", 0x514f24, 0x80

gUnknown_08514FA4::
	.incbin "baserom.gba", 0x514fa4, 0x80

gUnknown_08515024::
	.incbin "baserom.gba", 0x515024, 0x80

gUnknown_085150A4::
	.incbin "baserom.gba", 0x5150a4, 0x80

gUnknown_08515124::
	.incbin "baserom.gba", 0x515124, 0x80

gUnknown_085151A4::
	.incbin "baserom.gba", 0x5151a4, 0x80

gUnknown_08515224::
	.incbin "baserom.gba", 0x515224, 0x80

gUnknown_085152A4::
	.incbin "baserom.gba", 0x5152a4, 0x80

	.space 0x20

gTilesetAnims_MauvilleVDests0:: @ 8515344
@ replacing .incbin "baserom.gba", 0x00515344, 0x20
	.4byte BG_VRAM + 0x4c00
	.4byte BG_VRAM + 0x4c80
	.4byte BG_VRAM + 0x4d00
	.4byte BG_VRAM + 0x4d80
	.4byte BG_VRAM + 0x4e00
	.4byte BG_VRAM + 0x4e80
	.4byte BG_VRAM + 0x4f00
	.4byte BG_VRAM + 0x4f80

gTilesetAnims_MauvilleVDests1:: @ 8515364
@ replacing .incbin "baserom.gba", 0x00515364, 0x20
	.4byte BG_VRAM + 0x5000
	.4byte BG_VRAM + 0x5080
	.4byte BG_VRAM + 0x5100
	.4byte BG_VRAM + 0x5180
	.4byte BG_VRAM + 0x5200
	.4byte BG_VRAM + 0x5280
	.4byte BG_VRAM + 0x5300
	.4byte BG_VRAM + 0x5380

gTilesetAnims_Mauville0a:: @ 8515384
@ replacing .incbin "baserom.gba", 0x00515384, 0x30
	.4byte gUnknown_08514E24
	.4byte gUnknown_08514E24
	.4byte gUnknown_08514EA4
	.4byte gUnknown_08514F24
	.4byte gUnknown_08514FA4
	.4byte gUnknown_08514FA4
	.4byte gUnknown_08514FA4
	.4byte gUnknown_08514FA4
	.4byte gUnknown_08514FA4
	.4byte gUnknown_08514FA4
	.4byte gUnknown_08514F24
	.4byte gUnknown_08514EA4

gTilesetAnims_Mauville0b:: @ 85153B4
@ replacing .incbin "baserom.gba", 0x005153b4, 0x30
	.4byte gUnknown_085150A4
	.4byte gUnknown_085150A4
	.4byte gUnknown_08515124
	.4byte gUnknown_085151A4
	.4byte gUnknown_08515224
	.4byte gUnknown_08515224
	.4byte gUnknown_08515224
	.4byte gUnknown_08515224
	.4byte gUnknown_08515224
	.4byte gUnknown_08515224
	.4byte gUnknown_085151A4
	.4byte gUnknown_08515124

gTilesetAnims_Mauville1a:: @ 85153E4
@ replacing .incbin "baserom.gba", 0x005153e4, 0x10
	.4byte gUnknown_08514E24
	.4byte gUnknown_08514E24
	.4byte gUnknown_08515024
	.4byte gUnknown_08515024

gTilesetAnims_Mauville1b:: @ 85153F4
@ replacing .incbin "baserom.gba", 0x005153f4, 0x10
	.4byte gUnknown_085150A4
	.4byte gUnknown_085150A4
	.4byte gUnknown_085152A4
	.4byte gUnknown_085152A4

gUnknown_08515404::
	.incbin "baserom.gba", 0x515404, 0x80

gUnknown_08515484::
	.incbin "baserom.gba", 0x515484, 0x80

gUnknown_08515504::
	.incbin "baserom.gba", 0x515504, 0x80

gUnknown_08515584::
	.incbin "baserom.gba", 0x515584, 0x80

gUnknown_08515604::
	.incbin "baserom.gba", 0x515604, 0x80

gUnknown_08515684::
	.incbin "baserom.gba", 0x515684, 0x80

gUnknown_08515704::
	.incbin "baserom.gba", 0x515704, 0x80

gUnknown_08515784::
	.incbin "baserom.gba", 0x515784, 0x80


gTilesetAnims_RustboroVDests0:: @ 8515804
    .4byte BG_VRAM + 0x5000
	.4byte BG_VRAM + 0x5080
	.4byte BG_VRAM + 0x5100
	.4byte BG_VRAM + 0x5180
	.4byte BG_VRAM + 0x5200
	.4byte BG_VRAM + 0x5280
	.4byte BG_VRAM + 0x5300
	.4byte BG_VRAM + 0x5380

gTilesetAnims_Rustboro0:: @ 8515824
@ replacing .incbin "baserom.gba", 0x00515824, 0x20
	.4byte gUnknown_08515404
	.4byte gUnknown_08515484
	.4byte gUnknown_08515504
	.4byte gUnknown_08515584
	.4byte gUnknown_08515604
	.4byte gUnknown_08515684
	.4byte gUnknown_08515704
	.4byte gUnknown_08515784

gUnknown_08515844::
	.incbin "baserom.gba", 0x515844, 0x80

gUnknown_085158C4::
	.incbin "baserom.gba", 0x5158c4, 0x80

	.space 0x20


gTilesetAnims_Rustboro1:: @ 8515964
@ replacing .incbin "baserom.gba", 0x00515964, 0x8
	.4byte gUnknown_08515844
	.4byte gUnknown_085158C4

gUnknown_0851596C::
	.incbin "baserom.gba", 0x51596c, 0x80

gUnknown_085159EC::
	.incbin "baserom.gba", 0x5159ec, 0x80

gUnknown_08515A6C::
	.incbin "baserom.gba", 0x515a6c, 0x80

gUnknown_08515AEC::
	.incbin "baserom.gba", 0x515aec, 0x80

gUnknown_08515B6C::
	.incbin "baserom.gba", 0x515b6c, 0x80

gUnknown_08515BEC::
	.incbin "baserom.gba", 0x515bec, 0x80

gUnknown_08515C6C::
	.incbin "baserom.gba", 0x515c6c, 0x80

gUnknown_08515CEC::
	.incbin "baserom.gba", 0x515cec, 0x80

    .space 0x20


gTilesetAnims_Lavaridge1_Cave0:: @ 8515D8C
@ replacing .incbin "baserom.gba", 0x00515d8c, 0x10
	.4byte gUnknown_0851596C
	.4byte gUnknown_085159EC
	.4byte gUnknown_08515A6C
	.4byte gUnknown_08515AEC

gUnknown_08515D9C::
	.incbin "baserom.gba", 0x515d9c, 0x80

gUnknown_08515E1C::
	.incbin "baserom.gba", 0x515e1c, 0x80

gUnknown_08515E9C::
	.incbin "baserom.gba", 0x515e9c, 0x80

gUnknown_08515F1C::
	.incbin "baserom.gba", 0x515f1c, 0x80

gUnknown_08515F9C::
	.incbin "baserom.gba", 0x515f9c, 0x80

gUnknown_0851601C::
	.incbin "baserom.gba", 0x51601c, 0x80

gUnknown_0851609C::
	.incbin "baserom.gba", 0x51609c, 0x80

gUnknown_0851611C::
	.incbin "baserom.gba", 0x51611c, 0x80

	.space 0x20


gTilesetAnims_EverGrandeVDests0:: @ 85161BC
@ replacing .incbin "baserom.gba", 0x005161bc, 0x20
	.4byte BG_VRAM + 0x5c00
	.4byte BG_VRAM + 0x5c80
	.4byte BG_VRAM + 0x5d00
	.4byte BG_VRAM + 0x5d80
	.4byte BG_VRAM + 0x5e00
	.4byte BG_VRAM + 0x5e80
	.4byte BG_VRAM + 0x5f00
	.4byte BG_VRAM + 0x5f80

gTilesetAnims_EverGrande0:: @ 85161DC
@ replacing .incbin "baserom.gba", 0x005161dc, 0x20
	.4byte gUnknown_08515D9C
	.4byte gUnknown_08515E1C
	.4byte gUnknown_08515E9C
	.4byte gUnknown_08515F1C
	.4byte gUnknown_08515F9C
	.4byte gUnknown_0851601C
	.4byte gUnknown_0851609C
	.4byte gUnknown_0851611C

gUnknown_085161FC::
	.incbin "baserom.gba", 0x5161fc, 0xc0

gUnknown_085162BC::
	.incbin "baserom.gba", 0x5162bc, 0xc0

gUnknown_0851637C::
	.incbin "baserom.gba", 0x51637c, 0xc0

gUnknown_0851643C::
	.incbin "baserom.gba", 0x51643c, 0xc0


gTilesetAnims_Dewford0:: @ 85164FC
@ replacing .incbin "baserom.gba", 0x005164fc, 0x10
	.4byte gUnknown_085161FC
	.4byte gUnknown_085162BC
	.4byte gUnknown_0851637C
	.4byte gUnknown_0851643C

gUnknown_0851650C::
	.incbin "baserom.gba", 0x51650c, 0xc0

gUnknown_085165CC::
	.incbin "baserom.gba", 0x5165cc, 0xc0

gUnknown_0851668C::
	.incbin "baserom.gba", 0x51668c, 0xc0

gUnknown_0851674C::
	.incbin "baserom.gba", 0x51674c, 0xc0


gTilesetAnims_BattleFrontierOutsideWest0:: @ 851680C
@ replacing .incbin "baserom.gba", 0x0051680c, 0x10
	.4byte gUnknown_0851650C
	.4byte gUnknown_085165CC
	.4byte gUnknown_0851668C
	.4byte gUnknown_0851674C

gUnknown_0851681C:: @ 851680C
	.incbin "baserom.gba", 0x51681c, 0xc0

gUnknown_085168DC::
	.incbin "baserom.gba", 0x5168dc, 0xc0

gUnknown_0851699C::
	.incbin "baserom.gba", 0x51699c, 0xc0

gUnknown_08516A5C::
	.incbin "baserom.gba", 0x516a5c, 0xc0


gTilesetAnims_BattleFrontierOutsideEast0:: @ 8516B1C
@ replacing .incbin "baserom.gba", 0x00516b1c, 0x10
	.4byte gUnknown_0851681C
	.4byte gUnknown_085168DC
	.4byte gUnknown_0851699C
	.4byte gUnknown_08516A5C

gUnknown_08516B2C::
	.incbin "baserom.gba", 0x516b2c, 0x80

gUnknown_08516BAC::
	.incbin "baserom.gba", 0x516bac, 0x80

gUnknown_08516C2C::
	.incbin "baserom.gba", 0x516c2c, 0x80

gUnknown_08516CAC::
	.incbin "baserom.gba", 0x516cac, 0x80


gTilesetAnims_Slateport0:: @ 8516D2C
@ replacing .incbin "baserom.gba", 0x00516d2c, 0x10
	.4byte gUnknown_08516B2C
	.4byte gUnknown_08516BAC
	.4byte gUnknown_08516C2C
	.4byte gUnknown_08516CAC

gUnknown_08516D3C::
	.incbin "baserom.gba", 0x516d3c, 0x80

gUnknown_08516DBC::
	.incbin "baserom.gba", 0x516dbc, 0x80


gTilesetAnims_InsideBuilding0:: @ 8516E3C
@ replacing .incbin "baserom.gba", 0x00516e3c, 0x8
	.4byte gUnknown_08516D3C
	.4byte gUnknown_08516DBC

gUnknown_08516E44::
	.incbin "baserom.gba", 0x516e44, 0x180

gUnknown_08516FC4::
	.incbin "baserom.gba", 0x516fc4, 0x180

gUnknown_08517144::
	.incbin "baserom.gba", 0x517144, 0x180

gUnknown_085172C4::
	.incbin "baserom.gba", 0x5172c4, 0x280

gUnknown_08517544::
	.incbin "baserom.gba", 0x517544, 0x280

gUnknown_085177C4::
	.incbin "baserom.gba", 0x5177c4, 0x280


gTilesetAnims_SootopolisGym0:: @ 8517A44
@ replacing .incbin "baserom.gba", 0x00517a44, 0xc
	.4byte gUnknown_08516E44
	.4byte gUnknown_08516FC4
	.4byte gUnknown_08517144

gTilesetAnims_SootopolisGym1:: @ 8517A50
@ replacing .incbin "baserom.gba", 0x00517a50, 0xc
	.4byte gUnknown_085172C4
	.4byte gUnknown_08517544
	.4byte gUnknown_085177C4

gUnknown_08517A5C::
	.incbin "baserom.gba", 0x517a5c, 0x80

gUnknown_08517ADC::
	.incbin "baserom.gba", 0x517adc, 0x80

gUnknown_08517B5C::
	.incbin "baserom.gba", 0x517b5c, 0x20

gUnknown_08517B7C::
	.incbin "baserom.gba", 0x517b7c, 0x20

gUnknown_08517B9C::
	.incbin "baserom.gba", 0x517b9c, 0x20

gUnknown_08517BBC::
	.incbin "baserom.gba", 0x517bbc, 0x20

	.space 0x20


gTilesetAnims_EliteFour1:: @ 8517BFC
@ replacing .incbin "baserom.gba", 0x00517bfc, 0x10
	.4byte gUnknown_08517B5C
	.4byte gUnknown_08517B7C
	.4byte gUnknown_08517B9C
	.4byte gUnknown_08517BBC

gTilesetAnims_EliteFour0:: @ 8517C0C
@ replacing .incbin "baserom.gba", 0x00517c0c, 0x8
	.4byte gUnknown_08517A5C
	.4byte gUnknown_08517ADC

gUnknown_08517C14::
	.incbin "baserom.gba", 0x517c14, 0x200

gUnknown_08517E14::
	.incbin "baserom.gba", 0x517e14, 0x200

	.space 0x20


gTilesetAnims_MauvilleGym0:: @ 8518034
@ replacing .incbin "baserom.gba", 0x00518034, 0x8
	.4byte gUnknown_08517C14
	.4byte gUnknown_08517E14

gUnknown_0851803C::
	.incbin "baserom.gba", 0x51803c, 0x120

gUnknown_0851815C::
	.incbin "baserom.gba", 0x51815c, 0x120

	.space 0x20

gTilesetAnims_BikeShop0:: @ 851829C
@ replacing .incbin "baserom.gba", 0x0051829c, 0x8
	.4byte gUnknown_0851803C
	.4byte gUnknown_0851815C

gUnknown_085182A4::
	.incbin "baserom.gba", 0x5182a4, 0xc00

gUnknown_08518EA4::
	.incbin "baserom.gba", 0x518ea4, 0xc00

gUnknown_08519AA4::
	.incbin "baserom.gba", 0x519aa4, 0xc00

gUnknown_0851A6A4::
	.incbin "baserom.gba", 0x51a6a4, 0xc00

gUnknown_0851B2A4::
	.incbin "baserom.gba", 0x51b2a4, 0xc00

gUnknown_0851BEA4::
	.incbin "baserom.gba", 0x51bea4, 0xc00

gUnknown_0851CAA4::
	.incbin "baserom.gba", 0x51caa4, 0xc00

gUnknown_0851D6A4::
	.incbin "baserom.gba", 0x51d6a4, 0xc00

	.space 0x20

gUnknown_0851E2C4::
	.incbin "baserom.gba", 0x51e2c4, 0x800

gUnknown_0851EAC4::
	.incbin "baserom.gba", 0x51eac4, 0x800

gUnknown_0851F2C4::
	.incbin "baserom.gba", 0x51f2c4, 0x800

gUnknown_0851FAC4::
	.incbin "baserom.gba", 0x51fac4, 0x800

gTilesetAnims_Sootopolis0:: @ 85202C4
@ replacing .incbin "baserom.gba", 0x005202c4, 0x20
	.4byte gUnknown_085182A4
	.4byte gUnknown_08518EA4
	.4byte gUnknown_08519AA4
	.4byte gUnknown_0851A6A4
	.4byte gUnknown_0851B2A4
	.4byte gUnknown_0851BEA4
	.4byte gUnknown_0851CAA4
	.4byte gUnknown_0851D6A4

gUnknown_085202E4::
	.incbin "baserom.gba", 0x5202e4, 0x100

gUnknown_085203E4::
	.incbin "baserom.gba", 0x5203e4, 0x100

gUnknown_085204E4::
	.incbin "baserom.gba", 0x5204e4, 0x100

    .space 0x20

gUnknown_08520604::
	.incbin "baserom.gba", 0x520604, 0x100

gUnknown_08520704::
	.incbin "baserom.gba", 0x520704, 0x100

gUnknown_08520804::
	.incbin "baserom.gba", 0x520804, 0x100

	.space 0x3d00

gUnknown_08524604::
	.incbin "baserom.gba", 0x524604, 0x40

	.space 0x1c0

gUnknown_08524804::
	.incbin "baserom.gba", 0x524804, 0x60

gTilesetAnims_BattlePyramid0:: @ 8524864
@ replacing .incbin "baserom.gba", 0x00524864, 0xc
	.4byte gUnknown_085202E4
	.4byte gUnknown_085203E4
	.4byte gUnknown_085204E4

gTilesetAnims_BattlePyramid1:: @ 8524870
@ replacing .incbin "baserom.gba", 0x00524870, 0xc
	.4byte gUnknown_08520604
	.4byte gUnknown_08520704
	.4byte gUnknown_08520804

