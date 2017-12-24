	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_0857173C:: @ 857173C
	.incbin "baserom.gba", 0x57173c, 0x20

gUnknown_0857175C:: @ 857175C
	.incbin "baserom.gba", 0x57175c, 0x800

gUnknown_08571F5C:: @ 8571F5C
	.incbin "baserom.gba", 0x571f5c, 0x180

gUnknown_085720DC:: @ 85720DC
	.incbin "baserom.gba", 0x5720dc, 0x98

gUnknown_08572174:: @ 8572174
	.incbin "baserom.gba", 0x572174, 0x12c

gUnknown_085722A0:: @ 85722A0
	.incbin "baserom.gba", 0x5722a0, 0xfc

gUnknown_0857239C:: @ 857239C
	.incbin "baserom.gba", 0x57239c, 0x40

gUnknown_085723DC:: @ 85723DC
	.incbin "baserom.gba", 0x5723dc, 0x20

gUnknown_085723FC:: @ 85723FC
	.incbin "baserom.gba", 0x5723fc, 0x20

gUnknown_0857241C:: @ 857241C
	.incbin "baserom.gba", 0x57241c, 0x20

gUnknown_0857243C:: @ 857243C
	.incbin "baserom.gba", 0x57243c, 0x20

gUnknown_0857245C:: @ 857245C
	.incbin "baserom.gba", 0x57245c, 0x48

gUnknown_085724A4:: @ 85724A4
	.incbin "baserom.gba", 0x5724a4, 0x18

gUnknown_085724BC:: @ 85724BC
	.incbin "baserom.gba", 0x5724bc, 0x18
	
gUnknown_085724D4:: @ 85724D4
	.incbin "baserom.gba", 0x5724d4, 0x20
	
gUnknown_085724F4:: @ 85724F4
	.incbin "baserom.gba", 0x5724f4, 0x200

gUnknown_085726F4:: @ 85726F4
	.incbin "baserom.gba", 0x5726f4, 0x20

gUnknown_08572714:: @ 8572714
	.incbin "baserom.gba", 0x572714, 0x20

gUnknown_08572734:: @ 8572734
	.incbin "baserom.gba", 0x572734, 0x10

gUnknown_08572744:: @ 8572744
	obj_pal gUnknown_085724D4, 0xDACA

gUnknown_0857274C:: @ 857274C
	obj_tiles gUnknown_085724F4, 0x1C0, 5

gUnknown_08572754:: @ 8572754
	spr_template 2, 0xDAC6, gOamData_857286C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_0857276C:: @ 857276C
	.4byte gUnknown_085EB7EF, 0
	.4byte gUnknown_085EB802, 0
	.4byte gUnknown_085EB81A, 0
	.4byte gUnknown_085EB82F, 0
	.4byte gUnknown_085EB843, 1
	.4byte gUnknown_085EB853, 0
	.4byte gUnknown_085EB866, 0
	.4byte gUnknown_085EB87C, 1
	.4byte gUnknown_085EB88E, 0
	.4byte gUnknown_085EB89F, 0
	.4byte gUnknown_085EB8B5, 4
	.4byte gUnknown_085EB8C6, 6
	.4byte gUnknown_085EB8D3, 0
	.4byte gUnknown_085EB8E6, 0
	.4byte gUnknown_085EB900, 0
	.4byte gUnknown_085EB913, 0
	.4byte gUnknown_085EB92D, 0
	.4byte gUnknown_085EB946, 0
	.4byte gUnknown_085EB960, 0
	.4byte gUnknown_085EB979, 1
	.4byte gUnknown_085EB987, 0
	.4byte gUnknown_085EB9A1, 0
	.4byte gUnknown_085EB9AB, 0
	.4byte gUnknown_085EB843, 7
	.4byte gUnknown_085EB9C3, 0
	.4byte gUnknown_085EB9D6, 7
	.4byte gUnknown_085EB9EE, 0
	.4byte gUnknown_085EB9FF, 0
	.4byte gUnknown_085EBA19, 7
	.4byte gUnknown_085EBA29, 7
	.4byte gUnknown_085EBA38, 0

	.align 2

gUnknown_08572864:: @ 8572864
	window_template 0, 0x18, 0xB, 5, 4, 0xF, 0x5C
	
	.align 2
gOamData_857286C:: @ 857286C
	.2byte 0x0000
	.2byte 0xC000
	.2byte 0x0000

	.align 2
gOamData_8572874:: @ 8572874
	.2byte 0x4000
	.2byte 0x0000
	.2byte 0x0000

	.align 2
gSpriteAnim_857287C:: @ 857287C
	obj_image_anim_frame 0, 5
	obj_image_anim_end

	.align 2
gSpriteAnim_8572884:: @ 8572884
	obj_image_anim_frame 2, 8
	obj_image_anim_frame 4, 8
	obj_image_anim_frame 6, 8
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_8572894:: @ 8572894
	obj_image_anim_frame 8, 5
	obj_image_anim_end

	.align 2
gSpriteAnim_857289C:: @ 857289C
	obj_image_anim_frame 10, 8
	obj_image_anim_frame 4, 8
	obj_image_anim_frame 12, 8
	obj_image_anim_jump 0

	.align 2
gSpriteAnimTable_85728AC:: @ 85728AC
	.4byte gSpriteAnim_857287C
	.4byte gSpriteAnim_8572884
	.4byte gSpriteAnim_8572894
	.4byte gSpriteAnim_857289C

gUnknown_085728BC:: @ 85728BC
	spr_template 5, 0xDACA, gOamData_8572874, gSpriteAnimTable_85728AC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085728D4:: @ 85728D4
	spr_template 0x12, 0xDAC0, gOamData_85728EC, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gOamData_85728EC:: @ 85728EC
	.2byte 0x0000
	.2byte 0x8000
	.2byte 0x0000

	.align 2
gSpriteAffineAnim_85728F4:: @ 85728F4
	obj_rot_scal_anim_frame 0xFFFE, 0xFFFE, 0, 120
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnim_8572904:: @ 8572904
	obj_rot_scal_anim_frame 0x10, 0x10, 0, 0
	obj_rot_scal_anim_frame 0x10, 0x10, 0, 15
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnimTable_857291C:: @ 857291C
	.4byte gSpriteAffineAnim_85728F4
	.4byte gSpriteAffineAnim_8572904

gUnknown_08572924:: @ 8572924
	.incbin "baserom.gba", 0x572924, 0x4c50

gUnknown_08577574:: @ 8577574
	.incbin "baserom.gba", 0x577574, 0x44

gUnknown_085775B8:: @ 85775B8
	.incbin "baserom.gba", 0x5775b8, 0x398c

gUnknown_0857AF44:: @ 857AF44
	.incbin "baserom.gba", 0x57af44, 0xc0

gUnknown_0857B004:: @ 857B004
	.incbin "baserom.gba", 0x57b004, 0x7c

gUnknown_0857B080:: @ 857B080
	.incbin "baserom.gba", 0x57b080, 0x28

gUnknown_0857B0A8:: @ 857B0A8
	.incbin "baserom.gba", 0x57b0a8, 0x38

gUnknown_0857B0E0:: @ 857B0E0
	.incbin "baserom.gba", 0x57b0e0, 0x8b8

gUnknown_0857B998:: @ 857B998
	.incbin "baserom.gba", 0x57b998, 0xc

gUnknown_0857B9A4:: @ 857B9A4
	.incbin "baserom.gba", 0x57b9a4, 0x18

gUnknown_0857B9BC:: @ 857B9BC
	.incbin "baserom.gba", 0x57b9bc, 0x28

gUnknown_0857B9E4:: @ 857B9E4
	.incbin "baserom.gba", 0x57b9e4, 0x18

gUnknown_0857B9FC:: @ 857B9FC
	.incbin "baserom.gba", 0x57b9fc, 0x54

gUnknown_0857BA50:: @ 857BA50
	.incbin "baserom.gba", 0x57ba50, 0x18

gUnknown_0857BA68:: @ 857BA68
	.incbin "baserom.gba", 0x57ba68, 0x18

gUnknown_0857BA80:: @ 857BA80
	.incbin "baserom.gba", 0x57ba80, 0x9c

gUnknown_0857BB1C:: @ 857BB1C
	.incbin "baserom.gba", 0x57bb1c, 0x8

gUnknown_0857BB24:: @ 857BB24
	.incbin "baserom.gba", 0x57bb24, 0x14c

gUnknown_0857BC70:: @ 857BC70
	.incbin "baserom.gba", 0x57bc70, 0x18

gUnknown_0857BC88:: @ 857BC88
	.incbin "baserom.gba", 0x57bc88, 0x20
