	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_085105C4::
	.incbin "data/tilesets/primary/general/anim/0/1.4bpp"

gUnknown_08510644::
	.incbin "data/tilesets/primary/general/anim/0/0.4bpp"

gUnknown_085106C4::
	.incbin "data/tilesets/primary/general/anim/0/2.4bpp"

	.space 0x20

gTilesetAnims_General0:: @ 8510764
	.4byte gUnknown_08510644
	.4byte gUnknown_085105C4
	.4byte gUnknown_08510644
	.4byte gUnknown_085106C4

gUnknown_08510774::
	.incbin "data/tilesets/primary/general/anim/1/0.4bpp"

gUnknown_08510B34::
	.incbin "data/tilesets/primary/general/anim/1/1.4bpp"

gUnknown_08510EF4::
	.incbin "data/tilesets/primary/general/anim/1/2.4bpp"

gUnknown_085112B4::
	.incbin "data/tilesets/primary/general/anim/1/3.4bpp"

gUnknown_08511674::
	.incbin "data/tilesets/primary/general/anim/1/4.4bpp"

gUnknown_08511A34::
	.incbin "data/tilesets/primary/general/anim/1/5.4bpp"

gUnknown_08511DF4::
	.incbin "data/tilesets/primary/general/anim/1/6.4bpp"

gUnknown_085121B4::
	.incbin "data/tilesets/primary/general/anim/1/7.4bpp"


gTilesetAnims_General1:: @ 8512574
	.4byte gUnknown_08510774
	.4byte gUnknown_08510B34
	.4byte gUnknown_08510EF4
	.4byte gUnknown_085112B4
	.4byte gUnknown_08511674
	.4byte gUnknown_08511A34
	.4byte gUnknown_08511DF4
	.4byte gUnknown_085121B4

gUnknown_08512594::
	.incbin "data/tilesets/primary/general/anim/2/0.4bpp"

gUnknown_085126D4::
	.incbin "data/tilesets/primary/general/anim/2/1.4bpp"

gUnknown_08512814::
	.incbin "data/tilesets/primary/general/anim/2/2.4bpp"

gUnknown_08512954::
	.incbin "data/tilesets/primary/general/anim/2/3.4bpp"

gUnknown_08512A94::
	.incbin "data/tilesets/primary/general/anim/2/4.4bpp"

gUnknown_08512BD4::
	.incbin "data/tilesets/primary/general/anim/2/5.4bpp"

gUnknown_08512D14::
	.incbin "data/tilesets/primary/general/anim/2/6.4bpp"


gTilesetAnims_General2:: @ 8512E54
	.4byte gUnknown_08512594
	.4byte gUnknown_085126D4
	.4byte gUnknown_08512814
	.4byte gUnknown_08512954
	.4byte gUnknown_08512A94
	.4byte gUnknown_08512BD4
	.4byte gUnknown_08512D14
	.4byte gUnknown_08512594

gUnknown_08512E74::
	.incbin "data/tilesets/primary/general/anim/3/0.4bpp"

gUnknown_08512F34::
	.incbin "data/tilesets/primary/general/anim/3/1.4bpp"

gUnknown_08512FF4::
	.incbin "data/tilesets/primary/general/anim/3/2.4bpp"

gUnknown_085130B4::
	.incbin "data/tilesets/primary/general/anim/3/3.4bpp"


gTilesetAnims_General3:: @ 8513174
	.4byte gUnknown_08512E74
	.4byte gUnknown_08512F34
	.4byte gUnknown_08512FF4
	.4byte gUnknown_085130B4

gUnknown_08513184::
	.incbin "data/tilesets/primary/general/anim/4/0.4bpp"

gUnknown_085132C4::
	.incbin "data/tilesets/primary/general/anim/4/1.4bpp"

gUnknown_08513404::
	.incbin "data/tilesets/primary/general/anim/4/2.4bpp"

gUnknown_08513544::
	.incbin "data/tilesets/primary/general/anim/4/3.4bpp"


gTilesetAnims_General4:: @ 8513684
	.4byte gUnknown_08513184
	.4byte gUnknown_085132C4
	.4byte gUnknown_08513404
	.4byte gUnknown_08513544

gUnknown_08513694::
	.incbin "data/tilesets/secondary/lavaridge/anim/0.4bpp"

gUnknown_08513714::
	.incbin "data/tilesets/secondary/lavaridge/anim/1.4bpp"

gUnknown_08513794::
	.incbin "data/tilesets/secondary/lavaridge/anim/2.4bpp"

gUnknown_08513814::
	.incbin "data/tilesets/secondary/lavaridge/anim/3.4bpp"


gTilesetAnims_Lavaridge0:: @ 8513894
	.4byte gUnknown_08513694
	.4byte gUnknown_08513714
	.4byte gUnknown_08513794
	.4byte gUnknown_08513814

gUnknown_085138A4::
	.incbin "data/tilesets/secondary/pacifidlog/anim/0/0.4bpp"

gUnknown_08513C64::
	.incbin "data/tilesets/secondary/pacifidlog/anim/0/1.4bpp"

gUnknown_08514024::
	.incbin "data/tilesets/secondary/pacifidlog/anim/0/2.4bpp"


gTilesetAnims_Pacifidlog0:: @ 85143E4
	.4byte gUnknown_085138A4
	.4byte gUnknown_08513C64
	.4byte gUnknown_08514024
	.4byte gUnknown_08513C64

gUnknown_085143F4::
	.incbin "data/tilesets/secondary/underwater/anim/0.4bpp"

gUnknown_08514474::
	.incbin "data/tilesets/secondary/underwater/anim/1.4bpp"

gUnknown_085144F4::
	.incbin "data/tilesets/secondary/underwater/anim/2.4bpp"

gUnknown_08514574::
	.incbin "data/tilesets/secondary/underwater/anim/3.4bpp"


gTilesetAnims_Underwater0:: @ 85145F4
	.4byte gUnknown_085143F4
	.4byte gUnknown_08514474
	.4byte gUnknown_085144F4
	.4byte gUnknown_08514574

gUnknown_08514604::
	.incbin "data/tilesets/secondary/pacifidlog/anim/1/0.4bpp"

gUnknown_08514704::
	.incbin "data/tilesets/secondary/pacifidlog/anim/1/1.4bpp"

gUnknown_08514804::
	.incbin "data/tilesets/secondary/pacifidlog/anim/1/2.4bpp"

gUnknown_08514904::
	.incbin "data/tilesets/secondary/pacifidlog/anim/1/3.4bpp"

gUnknown_08514A04::
	.incbin "data/tilesets/secondary/pacifidlog/anim/1/4.4bpp"

gUnknown_08514B04::
	.incbin "data/tilesets/secondary/pacifidlog/anim/1/5.4bpp"

gUnknown_08514C04::
	.incbin "data/tilesets/secondary/pacifidlog/anim/1/6.4bpp"

gUnknown_08514D04::
	.incbin "data/tilesets/secondary/pacifidlog/anim/1/7.4bpp"


gTilesetAnims_Pacifidlog1:: @ 8514E04
	.4byte gUnknown_08514604
	.4byte gUnknown_08514704
	.4byte gUnknown_08514804
	.4byte gUnknown_08514904
	.4byte gUnknown_08514A04
	.4byte gUnknown_08514B04
	.4byte gUnknown_08514C04
	.4byte gUnknown_08514D04

gUnknown_08514E24::
	.incbin "data/tilesets/secondary/mauville/anim/0/a/0.4bpp"

gUnknown_08514EA4::
	.incbin "data/tilesets/secondary/mauville/anim/0/a/1.4bpp"

gUnknown_08514F24::
	.incbin "data/tilesets/secondary/mauville/anim/0/a/2.4bpp"

gUnknown_08514FA4::
	.incbin "data/tilesets/secondary/mauville/anim/0/a/3.4bpp"

gUnknown_08515024::
	.incbin "data/tilesets/secondary/mauville/anim/1/a/1.4bpp"

gUnknown_085150A4::
	.incbin "data/tilesets/secondary/mauville/anim/0/b/0.4bpp"

gUnknown_08515124::
	.incbin "data/tilesets/secondary/mauville/anim/0/b/1.4bpp"

gUnknown_085151A4::
	.incbin "data/tilesets/secondary/mauville/anim/0/b/2.4bpp"

gUnknown_08515224::
	.incbin "data/tilesets/secondary/mauville/anim/0/b/3.4bpp"

gUnknown_085152A4::
	.incbin "data/tilesets/secondary/mauville/anim/1/b/1.4bpp"

	.space 0x20

gTilesetAnims_MauvilleVDests0:: @ 8515344
	.4byte BG_VRAM + 0x4c00
	.4byte BG_VRAM + 0x4c80
	.4byte BG_VRAM + 0x4d00
	.4byte BG_VRAM + 0x4d80
	.4byte BG_VRAM + 0x4e00
	.4byte BG_VRAM + 0x4e80
	.4byte BG_VRAM + 0x4f00
	.4byte BG_VRAM + 0x4f80

gTilesetAnims_MauvilleVDests1:: @ 8515364
	.4byte BG_VRAM + 0x5000
	.4byte BG_VRAM + 0x5080
	.4byte BG_VRAM + 0x5100
	.4byte BG_VRAM + 0x5180
	.4byte BG_VRAM + 0x5200
	.4byte BG_VRAM + 0x5280
	.4byte BG_VRAM + 0x5300
	.4byte BG_VRAM + 0x5380

gTilesetAnims_Mauville0a:: @ 8515384
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
	.4byte gUnknown_08514E24
	.4byte gUnknown_08514E24
	.4byte gUnknown_08515024
	.4byte gUnknown_08515024

gTilesetAnims_Mauville1b:: @ 85153F4
	.4byte gUnknown_085150A4
	.4byte gUnknown_085150A4
	.4byte gUnknown_085152A4
	.4byte gUnknown_085152A4

gUnknown_08515404::
	.incbin "data/tilesets/secondary/rustboro/anim/0/0.4bpp"

gUnknown_08515484::
	.incbin "data/tilesets/secondary/rustboro/anim/0/1.4bpp"

gUnknown_08515504::
	.incbin "data/tilesets/secondary/rustboro/anim/0/2.4bpp"

gUnknown_08515584::
	.incbin "data/tilesets/secondary/rustboro/anim/0/3.4bpp"

gUnknown_08515604::
	.incbin "data/tilesets/secondary/rustboro/anim/0/4.4bpp"

gUnknown_08515684::
	.incbin "data/tilesets/secondary/rustboro/anim/0/5.4bpp"

gUnknown_08515704::
	.incbin "data/tilesets/secondary/rustboro/anim/0/6.4bpp"

gUnknown_08515784::
	.incbin "data/tilesets/secondary/rustboro/anim/0/7.4bpp"


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
	.4byte gUnknown_08515404
	.4byte gUnknown_08515484
	.4byte gUnknown_08515504
	.4byte gUnknown_08515584
	.4byte gUnknown_08515604
	.4byte gUnknown_08515684
	.4byte gUnknown_08515704
	.4byte gUnknown_08515784

gUnknown_08515844::
	.incbin "data/tilesets/secondary/rustboro/anim/1/0.4bpp"

gUnknown_085158C4::
	.incbin "data/tilesets/secondary/rustboro/anim/1/1.4bpp"

	.space 0x20


gTilesetAnims_Rustboro1:: @ 8515964
	.4byte gUnknown_08515844
	.4byte gUnknown_085158C4

gUnknown_0851596C::
	.incbin "data/tilesets/secondary/cave/anim/0.4bpp"

gUnknown_085159EC::
	.incbin "data/tilesets/secondary/cave/anim/1.4bpp"

gUnknown_08515A6C::
	.incbin "data/tilesets/secondary/cave/anim/2.4bpp"

gUnknown_08515AEC::
	.incbin "data/tilesets/secondary/cave/anim/3.4bpp"

gUnknown_08515B6C::
	.incbin "data/tilesets/secondary/cave/anim/unused/0.4bpp"

gUnknown_08515BEC::
	.incbin "data/tilesets/secondary/cave/anim/unused/1.4bpp"

gUnknown_08515C6C::
	.incbin "data/tilesets/secondary/cave/anim/unused/2.4bpp"

gUnknown_08515CEC::
	.incbin "data/tilesets/secondary/cave/anim/unused/3.4bpp"

    .space 0x20


gTilesetAnims_Lavaridge1_Cave0:: @ 8515D8C
	.4byte gUnknown_0851596C
	.4byte gUnknown_085159EC
	.4byte gUnknown_08515A6C
	.4byte gUnknown_08515AEC

gUnknown_08515D9C::
	.incbin "data/tilesets/secondary/ever_grande/anim/0.4bpp"

gUnknown_08515E1C::
	.incbin "data/tilesets/secondary/ever_grande/anim/1.4bpp"

gUnknown_08515E9C::
	.incbin "data/tilesets/secondary/ever_grande/anim/2.4bpp"

gUnknown_08515F1C::
	.incbin "data/tilesets/secondary/ever_grande/anim/3.4bpp"

gUnknown_08515F9C::
	.incbin "data/tilesets/secondary/ever_grande/anim/4.4bpp"

gUnknown_0851601C::
	.incbin "data/tilesets/secondary/ever_grande/anim/5.4bpp"

gUnknown_0851609C::
	.incbin "data/tilesets/secondary/ever_grande/anim/6.4bpp"

gUnknown_0851611C::
	.incbin "data/tilesets/secondary/ever_grande/anim/7.4bpp"

	.space 0x20


gTilesetAnims_EverGrandeVDests0:: @ 85161BC
	.4byte BG_VRAM + 0x5c00
	.4byte BG_VRAM + 0x5c80
	.4byte BG_VRAM + 0x5d00
	.4byte BG_VRAM + 0x5d80
	.4byte BG_VRAM + 0x5e00
	.4byte BG_VRAM + 0x5e80
	.4byte BG_VRAM + 0x5f00
	.4byte BG_VRAM + 0x5f80

gTilesetAnims_EverGrande0:: @ 85161DC
	.4byte gUnknown_08515D9C
	.4byte gUnknown_08515E1C
	.4byte gUnknown_08515E9C
	.4byte gUnknown_08515F1C
	.4byte gUnknown_08515F9C
	.4byte gUnknown_0851601C
	.4byte gUnknown_0851609C
	.4byte gUnknown_0851611C

gUnknown_085161FC::
	.incbin "data/tilesets/secondary/dewford/anim/0.4bpp"

gUnknown_085162BC::
	.incbin "data/tilesets/secondary/dewford/anim/1.4bpp"

gUnknown_0851637C::
	.incbin "data/tilesets/secondary/dewford/anim/2.4bpp"

gUnknown_0851643C::
	.incbin "data/tilesets/secondary/dewford/anim/3.4bpp"


gTilesetAnims_Dewford0:: @ 85164FC
	.4byte gUnknown_085161FC
	.4byte gUnknown_085162BC
	.4byte gUnknown_0851637C
	.4byte gUnknown_0851643C

gUnknown_0851650C::
	.incbin "data/tilesets/secondary/battle_frontier_outside_west/anim/0.4bpp"

gUnknown_085165CC::
	.incbin "data/tilesets/secondary/battle_frontier_outside_west/anim/1.4bpp"

gUnknown_0851668C::
	.incbin "data/tilesets/secondary/battle_frontier_outside_west/anim/2.4bpp"

gUnknown_0851674C::
	.incbin "data/tilesets/secondary/battle_frontier_outside_west/anim/3.4bpp"


gTilesetAnims_BattleFrontierOutsideWest0:: @ 851680C
	.4byte gUnknown_0851650C
	.4byte gUnknown_085165CC
	.4byte gUnknown_0851668C
	.4byte gUnknown_0851674C

gUnknown_0851681C:: @ 851680C
	.incbin "data/tilesets/secondary/battle_frontier_outside_east/anim/0.4bpp"

gUnknown_085168DC::
	.incbin "data/tilesets/secondary/battle_frontier_outside_east/anim/1.4bpp"

gUnknown_0851699C::
	.incbin "data/tilesets/secondary/battle_frontier_outside_east/anim/2.4bpp"

gUnknown_08516A5C::
	.incbin "data/tilesets/secondary/battle_frontier_outside_east/anim/3.4bpp"


gTilesetAnims_BattleFrontierOutsideEast0:: @ 8516B1C
	.4byte gUnknown_0851681C
	.4byte gUnknown_085168DC
	.4byte gUnknown_0851699C
	.4byte gUnknown_08516A5C

gUnknown_08516B2C::
	.incbin "data/tilesets/secondary/slateport/anim/0.4bpp"

gUnknown_08516BAC::
	.incbin "data/tilesets/secondary/slateport/anim/1.4bpp"

gUnknown_08516C2C::
	.incbin "data/tilesets/secondary/slateport/anim/2.4bpp"

gUnknown_08516CAC::
	.incbin "data/tilesets/secondary/slateport/anim/3.4bpp"


gTilesetAnims_Slateport0:: @ 8516D2C
	.4byte gUnknown_08516B2C
	.4byte gUnknown_08516BAC
	.4byte gUnknown_08516C2C
	.4byte gUnknown_08516CAC

gUnknown_08516D3C::
	.incbin "data/tilesets/primary/building/anim/0.4bpp"

gUnknown_08516DBC::
	.incbin "data/tilesets/primary/building/anim/1.4bpp"


gTilesetAnims_InsideBuilding0:: @ 8516E3C
	.4byte gUnknown_08516D3C
	.4byte gUnknown_08516DBC

gUnknown_08516E44::
	.incbin "data/tilesets/secondary/sootopolis_gym/anim/0/0.4bpp"

gUnknown_08516FC4::
	.incbin "data/tilesets/secondary/sootopolis_gym/anim/0/1.4bpp"

gUnknown_08517144::
	.incbin "data/tilesets/secondary/sootopolis_gym/anim/0/2.4bpp"

gUnknown_085172C4::
	.incbin "data/tilesets/secondary/sootopolis_gym/anim/1/0.4bpp"

gUnknown_08517544::
	.incbin "data/tilesets/secondary/sootopolis_gym/anim/1/1.4bpp"

gUnknown_085177C4::
	.incbin "data/tilesets/secondary/sootopolis_gym/anim/1/2.4bpp"


gTilesetAnims_SootopolisGym0:: @ 8517A44
	.4byte gUnknown_08516E44
	.4byte gUnknown_08516FC4
	.4byte gUnknown_08517144

gTilesetAnims_SootopolisGym1:: @ 8517A50
	.4byte gUnknown_085172C4
	.4byte gUnknown_08517544
	.4byte gUnknown_085177C4

gUnknown_08517A5C::
	.incbin "data/tilesets/secondary/elite_four/anim/1/0.4bpp"

gUnknown_08517ADC::
	.incbin "data/tilesets/secondary/elite_four/anim/1/1.4bpp"

gUnknown_08517B5C::
	.incbin "data/tilesets/secondary/elite_four/anim/0/0.4bpp"

gUnknown_08517B7C::
	.incbin "data/tilesets/secondary/elite_four/anim/0/1.4bpp"

gUnknown_08517B9C::
	.incbin "data/tilesets/secondary/elite_four/anim/0/2.4bpp"

gUnknown_08517BBC::
	.incbin "data/tilesets/secondary/elite_four/anim/0/3.4bpp"

	.space 0x20


gTilesetAnims_EliteFour1:: @ 8517BFC
	.4byte gUnknown_08517B5C
	.4byte gUnknown_08517B7C
	.4byte gUnknown_08517B9C
	.4byte gUnknown_08517BBC

gTilesetAnims_EliteFour0:: @ 8517C0C
	.4byte gUnknown_08517A5C
	.4byte gUnknown_08517ADC

gUnknown_08517C14::
	.incbin "data/tilesets/secondary/mauville_gym/anim/0.4bpp"

gUnknown_08517E14::
	.incbin "data/tilesets/secondary/mauville_gym/anim/1.4bpp"

	.space 0x20


gTilesetAnims_MauvilleGym0:: @ 8518034
	.4byte gUnknown_08517C14
	.4byte gUnknown_08517E14

gUnknown_0851803C::
	.incbin "data/tilesets/secondary/bike_shop/anim/0.4bpp"

gUnknown_0851815C::
	.incbin "data/tilesets/secondary/bike_shop/anim/1.4bpp"

	.space 0x20

gTilesetAnims_BikeShop0:: @ 851829C
	.4byte gUnknown_0851803C
	.4byte gUnknown_0851815C

gUnknown_085182A4::
	.incbin "data/tilesets/secondary/sootopolis/anim/0.4bpp"

gUnknown_08518EA4::
	.incbin "data/tilesets/secondary/sootopolis/anim/1.4bpp"

gUnknown_08519AA4::
	.incbin "data/tilesets/secondary/sootopolis/anim/2.4bpp"

gUnknown_0851A6A4::
	.incbin "data/tilesets/secondary/sootopolis/anim/3.4bpp"

gUnknown_0851B2A4::
	.incbin "data/tilesets/secondary/sootopolis/anim/4.4bpp"

gUnknown_0851BEA4::
	.incbin "data/tilesets/secondary/sootopolis/anim/5.4bpp"

gUnknown_0851CAA4::
	.incbin "data/tilesets/secondary/sootopolis/anim/6.4bpp"

gUnknown_0851D6A4::
	.incbin "data/tilesets/secondary/sootopolis/anim/7.4bpp"

	.space 0x20

gUnknown_0851E2C4::
	.incbin "data/tilesets/secondary/unused_1/0.4bpp"

gUnknown_0851EAC4::
	.incbin "data/tilesets/secondary/unused_1/1.4bpp"

gUnknown_0851F2C4::
	.incbin "data/tilesets/secondary/unused_1/2.4bpp"

gUnknown_0851FAC4::
	.incbin "data/tilesets/secondary/unused_1/3.4bpp"

gTilesetAnims_Sootopolis0:: @ 85202C4
	.4byte gUnknown_085182A4
	.4byte gUnknown_08518EA4
	.4byte gUnknown_08519AA4
	.4byte gUnknown_0851A6A4
	.4byte gUnknown_0851B2A4
	.4byte gUnknown_0851BEA4
	.4byte gUnknown_0851CAA4
	.4byte gUnknown_0851D6A4

gUnknown_085202E4::
	.incbin "data/tilesets/secondary/battle_pyramid/anim/0/0.4bpp"

gUnknown_085203E4::
	.incbin "data/tilesets/secondary/battle_pyramid/anim/0/1.4bpp"

gUnknown_085204E4::
	.incbin "data/tilesets/secondary/battle_pyramid/anim/0/2.4bpp"

    .space 0x20

gUnknown_08520604::
	.incbin "data/tilesets/secondary/battle_pyramid/anim/1/0.4bpp"

gUnknown_08520704::
	.incbin "data/tilesets/secondary/battle_pyramid/anim/1/1.4bpp"

gUnknown_08520804::
	.incbin "data/tilesets/secondary/battle_pyramid/anim/1/2.4bpp"

	.space 0x3d00

gUnknown_08524604::
	.incbin "data/tilesets/secondary/unused_2/0.4bpp"

	.space 0x1c0

gUnknown_08524804::
	.incbin "data/tilesets/secondary/unused_2/1.4bpp"

gTilesetAnims_BattlePyramid0:: @ 8524864
	.4byte gUnknown_085202E4
	.4byte gUnknown_085203E4
	.4byte gUnknown_085204E4

gTilesetAnims_BattlePyramid1:: @ 8524870
	.4byte gUnknown_08520604
	.4byte gUnknown_08520704
	.4byte gUnknown_08520804

