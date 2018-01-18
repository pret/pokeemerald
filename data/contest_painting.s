@ the third big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_085A989C:: @ 85A989C
	.incbin "graphics/picture_frame/bg.gbapal"

	.align 2
gUnknown_085A9A9C:: @ 85A9A9C
	.incbin "graphics/picture_frame/frame0.4bpp.rl"

	.align 2
gUnknown_085AAB20:: @ 85AAB20
	.incbin "graphics/picture_frame/frame1.4bpp.rl"

	.align 2
gUnknown_085AB750:: @ 85AB750
	.incbin "graphics/picture_frame/frame2.4bpp.rl"

	.align 2
gUnknown_085AC288:: @ 85AC288
	.incbin "graphics/picture_frame/frame3.4bpp.rl"

	.align 2
gUnknown_085AD240:: @ 85AD240
	.incbin "graphics/picture_frame/frame4.4bpp.rl"

	.align 2
gUnknown_085AE370:: @ 85AE370
	.incbin "graphics/picture_frame/frame5.4bpp.rl"

	.align 2
gUnknown_085AE974:: @ 85AE974
	.incbin "graphics/picture_frame/frame0_map.bin.rl"

	.align 2
gUnknown_085AEE80:: @ 85AEE80
	.incbin "graphics/picture_frame/frame1_map.bin.rl"

	.align 2
gUnknown_085AF38C:: @ 85AF38C
	.incbin "graphics/picture_frame/frame2_map.bin.rl"

	.align 2
gUnknown_085AF898:: @ 85AF898
	.incbin "graphics/picture_frame/frame3_map.bin.rl"

	.align 2
gUnknown_085AFDA4:: @ 85AFDA4
	.incbin "graphics/picture_frame/frame4_map.bin.rl"

	.align 2
gUnknown_085B02B0:: @ 85B02B0
	.incbin "graphics/picture_frame/frame5_map.bin.rl"

	.align 2
gUnknown_085B07C0:: @ 85B07C0
    .4byte gContestCoolness
    .4byte gContestBeauty
    .4byte gContestCuteness
    .4byte gContestSmartness
    .4byte gContestToughness

	.align 2
gContestRankTextPointers:: @ 85B07D4
	.4byte gContestRankNormal
	.4byte gContestRankSuper
	.4byte gContestRankHyper
	.4byte gContestRankMaster
	.4byte gContestLink

	.align 2
gUnknown_085B07E8:: @ 85B07E8
	.4byte 0x000010a5

	.align 2
gUnknown_085B07EC:: @ 85B07EC
	window_template 0x01, 0x02, 0x0e, 0x1a, 0x04, 0x0f, 0x0001

	.align 2
gContestPaintingDescriptionPointers:: @ 85B07F4
	.4byte gContestPaintingCool1
	.4byte gContestPaintingCool2
	.4byte gContestPaintingCool3
	.4byte gContestPaintingBeauty1
	.4byte gContestPaintingBeauty2
	.4byte gContestPaintingBeauty3
	.4byte gContestPaintingCute1
	.4byte gContestPaintingCute2
	.4byte gContestPaintingCute3
	.4byte gContestPaintingSmart1
	.4byte gContestPaintingSmart2
	.4byte gContestPaintingSmart3
	.4byte gContestPaintingTough1
	.4byte gContestPaintingTough2
	.4byte gContestPaintingTough3

gUnknown_085B0830:: @ 85B0830
	.4byte 0xc0003000, 0x00000000

gUnknown_085B0838:: @ 85B0838
	.2byte 0x0000, 0x0000
