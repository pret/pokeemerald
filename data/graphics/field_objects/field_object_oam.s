	.align 2, 0

gFieldObjectBaseOam_8x8: @ 85094EC
	.4byte OAM_SIZE_8x8
	.2byte 2 << 10 @ priority

	.align 2, 0

gFieldObjectBaseOam_16x8: @ 85094F4
	.4byte OAM_SIZE_16x8
	.2byte 2 << 10 @ priority

	.align 2, 0

gFieldObjectBaseOam_16x16: @ 85094FC
	.4byte OAM_SIZE_16x16
	.2byte 2 << 10 @ priority

	.align 2, 0

gFieldObjectBaseOam_32x8: @ 8509504
	.4byte OAM_SIZE_32x8
	.2byte 2 << 10 @ priority

	.align 2, 0

gFieldObjectBaseOam_64x32: @ 850950C
	.4byte OAM_SIZE_64x32
	.2byte 2 << 10 @ priority

	.align 2, 0

gFieldObjectBaseOam_16x32: @ 8509514
	.4byte OAM_SIZE_16x32
	.2byte 2 << 10 @ priority

	.align 2, 0

gFieldObjectBaseOam_32x32: @ 850951C
	.4byte OAM_SIZE_32x32
	.2byte 2 << 10 @ priority

	.align 2, 0

gFieldObjectBaseOam_64x64: @ 8509524
	.4byte OAM_SIZE_64x64
	.2byte 2 << 10 @ priority

	.align 2, 0

gFieldObjectSpriteOamTable_16x16_0: @ 850952C
	sprite_oam  -8,  -8, 2,  0, 16x16

	.align 2, 0

gFieldObjectSpriteOamTable_16x16_1: @ 8509530
	sprite_oam  -8,  -8, 1,  0, 16x16

	.align 2, 0

gFieldObjectSpriteOamTable_16x16_2: @ 8509534
	sprite_oam  -8,  -8, 2,  0, 16x8
	sprite_oam  -8,   0, 3,  2, 16x8

	.align 2, 0

gFieldObjectSpriteOamTable_16x16_3: @ 850953C
	sprite_oam  -8,  -8, 2,  0, 16x16
	sprite_oam  -8,  -8, 3,  0, 16x16

	.align 2, 0

gFieldObjectSpriteOamTable_16x16_4: @ 8509544
	sprite_oam  -8,  -8, 1,  0, 16x16
	sprite_oam  -8,  -8, 3,  0, 16x16

	.align 2, 0

gFieldObjectSpriteOamTables_16x16: @ 850954C
	.4byte 0 @ number of sprites
	.4byte NULL @ unknown

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_16x16_0 @ below high bridge

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_16x16_1 @ above high bridge

	.4byte 2 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_16x16_2 @ unknown

	.4byte 2 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_16x16_3 @ long grass below high bridge

	.4byte 2 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_16x16_4 @ long grass above high bridge

	.align 2, 0

gFieldObjectSpriteOamTable_16x32_0: @ 850957C
	sprite_oam  -8, -16, 2,  0, 16x32

	.align 2, 0

gFieldObjectSpriteOamTable_16x32_1: @ 8509580
	sprite_oam  -8, -16, 1,  0, 16x32

	.align 2, 0

gFieldObjectSpriteOamTable_16x32_2: @ 8509584
	sprite_oam  -8, -16, 2,  0, 16x16
	sprite_oam  -8,   0, 2,  4, 16x8
	sprite_oam  -8,   8, 3,  6, 16x8

	.align 2, 0

gFieldObjectSpriteOamTable_16x32_3: @ 8509590
	sprite_oam  -8, -16, 2,  0, 16x16
	sprite_oam  -8,   0, 3,  4, 16x16

	.align 2, 0

gFieldObjectSpriteOamTable_16x32_4: @ 8509598
	sprite_oam  -8, -16, 1,  0, 16x16
	sprite_oam  -8,   0, 3,  4, 16x16

	.align 2, 0

gFieldObjectSpriteOamTables_16x32: @ 85095A0
	.4byte 0 @ number of sprites
	.4byte NULL @ unknown

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_16x32_0 @ below high bridge

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_16x32_1 @ above high bridge

	.4byte 3 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_16x32_2 @ unknown

	.4byte 2 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_16x32_3 @ long grass below high bridge

	.4byte 2 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_16x32_4 @ long grass above high bridge

	.align 2, 0

gFieldObjectSpriteOamTable_32x32_0: @ 85095D0
	sprite_oam -16, -16, 2,  0, 32x32

	.align 2, 0

gFieldObjectSpriteOamTable_32x32_1: @ 85095D4
	sprite_oam -16, -16, 1,  0, 32x32

	.align 2, 0

gFieldObjectSpriteOamTable_32x32_2: @ 85095D8
	sprite_oam -16, -16, 2,  0, 32x16
	sprite_oam -16,   0, 2,  8, 32x8
	sprite_oam -16,   8, 3, 12, 32x8

	.align 2, 0

gFieldObjectSpriteOamTable_32x32_3: @ 85095E4
	sprite_oam -16, -16, 2,  0, 32x16
	sprite_oam -16,   0, 3,  8, 32x16

	.align 2, 0

gFieldObjectSpriteOamTable_32x32_4: @ 85095EC
	sprite_oam -16, -16, 1,  0, 32x16
	sprite_oam -16,   0, 3,  8, 32x16

	.align 2, 0

gFieldObjectSpriteOamTables_32x32: @ 85095F4
	.4byte 0 @ number of sprites
	.4byte NULL @ unknown

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_32x32_0 @ below high bridge

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_32x32_1 @ above high bridge

	.4byte 3 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_32x32_2 @ unknown

	.4byte 2 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_32x32_3 @ long grass below high bridge

	.4byte 2 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_32x32_4 @ long grass above high bridge

	.align 2, 0

gFieldObjectSpriteOamTable_Truck_0: @ 8509624
	sprite_oam -24, -24, 2,  0, 32x8
	sprite_oam   8, -24, 2,  4, 16x8
	sprite_oam -24, -16, 2,  6, 32x8
	sprite_oam   8, -16, 2, 10, 16x8
	sprite_oam -24,  -8, 2, 12, 32x8
	sprite_oam   8,  -8, 2, 16, 16x8
	sprite_oam -24,   0, 2, 18, 32x8
	sprite_oam   8,   0, 2, 22, 16x8
	sprite_oam -24,   8, 2, 24, 32x8
	sprite_oam   8,   8, 2, 28, 16x8
	sprite_oam -24,  16, 2, 30, 32x8
	sprite_oam   8,  16, 2, 34, 16x8

	.align 2, 0

gFieldObjectSpriteOamTables_Truck: @ 8509654
	.4byte 12 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Truck_0 @ unknown

	.4byte 12 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Truck_0 @ below high bridge

	.4byte 12 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Truck_0 @ above high bridge

	.4byte 12 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Truck_0 @ unknown

	.4byte 12 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Truck_0 @ long grass below high bridge

	.4byte 12 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Truck_0 @ long grass above high bridge

	.align 2, 0

gFieldObjectSpriteOamTable_Unused_0: @ 8509684
	sprite_oam -32, -16, 2,  0, 64x32

	.align 2, 0

gFieldObjectSpriteOamTable_Unused_1: @ 8509688
	sprite_oam -32, -16, 1,  0, 64x32

	.align 2, 0

gFieldObjectSpriteOamTable_Unused_2: @ 850968C
	sprite_oam -32, -16, 2,  0, 64x32

	.align 2, 0

gFieldObjectSpriteOamTable_Unused_3: @ 8509690
	sprite_oam -32, -16, 2,  0, 64x32

	.align 2, 0

gFieldObjectSpriteOamTables_Unused: @ 8509694
	.4byte 0 @ number of sprites
	.4byte NULL @ unknown

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Unused_0 @ below high bridge

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Unused_1 @ above high bridge

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Unused_2 @ unknown

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Unused_3 @ long grass below high bridge

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_Unused_3 @ long grass above high bridge

	.align 2, 0

gFieldObjectSpriteOamTable_64x64_0: @ 85096C4
	sprite_oam -32, -32, 2,  0, 64x64

	.align 2, 0

gFieldObjectSpriteOamTable_64x64_1: @ 85096C8
	sprite_oam -32, -32, 1,  0, 64x64

	.align 2, 0

gFieldObjectSpriteOamTable_64x64_2: @ 85096CC
	sprite_oam -32, -32, 2,  0, 64x64

	.align 2, 0

gFieldObjectSpriteOamTable_64x64_3: @ 85096D0
	sprite_oam -32, -32, 2,  0, 64x64

	.align 2, 0

gFieldObjectSpriteOamTables_64x64: @ 85096D4
	.4byte 0 @ number of sprites
	.4byte NULL @ unknown

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_64x64_0 @ below high bridge

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_64x64_1 @ above high bridge

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_64x64_2 @ unknown

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_64x64_3 @ long grass below high bridge

	.4byte 1 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_64x64_3 @ long grass above high bridge

	.align 2, 0

gFieldObjectSpriteOamTable_SSTidal_0: @ 8509704
	sprite_oam -48, -20, 2,  0, 32x8
	sprite_oam -16, -20, 2,  4, 32x8
	sprite_oam  16, -20, 2,  8, 32x8
	sprite_oam -48, -12, 2, 12, 32x8
	sprite_oam -16, -12, 2, 16, 32x8
	sprite_oam  16, -12, 2, 20, 32x8
	sprite_oam -48,  -4, 2, 24, 32x8
	sprite_oam -16,  -4, 2, 28, 32x8
	sprite_oam  16,  -4, 2, 32, 32x8
	sprite_oam -48,   4, 2, 36, 32x8
	sprite_oam -16,   4, 2, 40, 32x8
	sprite_oam  16,   4, 2, 44, 32x8
	sprite_oam -48,  12, 2, 48, 32x8
	sprite_oam -16,  12, 2, 52, 32x8
	sprite_oam  16,  12, 2, 56, 32x8

	.align 2, 0

gFieldObjectSpriteOamTable_SSTidal_1: @ 8509740
	sprite_oam -48, -20, 1,  0, 32x8
	sprite_oam -16, -20, 1,  4, 32x8
	sprite_oam  16, -20, 1,  8, 32x8
	sprite_oam -48, -12, 1, 12, 32x8
	sprite_oam -16, -12, 1, 16, 32x8
	sprite_oam  16, -12, 1, 20, 32x8
	sprite_oam -48,  -4, 1, 24, 32x8
	sprite_oam -16,  -4, 1, 28, 32x8
	sprite_oam  16,  -4, 1, 32, 32x8
	sprite_oam -48,   4, 1, 36, 32x8
	sprite_oam -16,   4, 1, 40, 32x8
	sprite_oam  16,   4, 1, 44, 32x8
	sprite_oam -48,  12, 1, 48, 32x8
	sprite_oam -16,  12, 1, 52, 32x8
	sprite_oam  16,  12, 1, 56, 32x8

	.align 2, 0

gFieldObjectSpriteOamTable_SSTidal_2: @ 850977C
	sprite_oam -48, -20, 2,  0, 32x8
	sprite_oam -16, -20, 2,  4, 32x8
	sprite_oam  16, -20, 2,  8, 32x8
	sprite_oam -48, -12, 2, 12, 32x8
	sprite_oam -16, -12, 2, 16, 32x8
	sprite_oam  16, -12, 2, 20, 32x8
	sprite_oam -48,  -4, 2, 24, 32x8
	sprite_oam -16,  -4, 2, 28, 32x8
	sprite_oam  16,  -4, 2, 32, 32x8
	sprite_oam -48,   4, 2, 36, 32x8
	sprite_oam -16,   4, 2, 40, 32x8
	sprite_oam  16,   4, 2, 44, 32x8
	sprite_oam -48,  12, 2, 48, 32x8
	sprite_oam -16,  12, 2, 52, 32x8
	sprite_oam  16,  12, 2, 56, 32x8

	.align 2, 0

gFieldObjectSpriteOamTable_SSTidal_3: @ 85097B8
	sprite_oam -48, -20, 1,  0, 32x8
	sprite_oam -16, -20, 1,  4, 32x8
	sprite_oam  16, -20, 1,  8, 32x8
	sprite_oam -48, -12, 1, 12, 32x8
	sprite_oam -16, -12, 1, 16, 32x8
	sprite_oam  16, -12, 1, 20, 32x8
	sprite_oam -48,  -4, 2, 24, 32x8
	sprite_oam -16,  -4, 2, 28, 32x8
	sprite_oam  16,  -4, 2, 32, 32x8
	sprite_oam -48,   4, 2, 36, 32x8
	sprite_oam -16,   4, 2, 40, 32x8
	sprite_oam  16,   4, 2, 44, 32x8
	sprite_oam -48,  12, 2, 48, 32x8
	sprite_oam -16,  12, 2, 52, 32x8
	sprite_oam  16,  12, 2, 56, 32x8

	.align 2, 0

gFieldObjectSpriteOamTables_SSTidal: @ 85097F4
	.4byte 15 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SSTidal_0 @ unknown

	.4byte 15 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SSTidal_0 @ below high bridge

	.4byte 15 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SSTidal_1 @ above high bridge

	.4byte 15 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SSTidal_2 @ unknown

	.4byte 15 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SSTidal_3 @ long grass below high bridge

	.4byte 15 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SSTidal_3 @ long grass above high bridge

	.align 2, 0

gFieldObjectSpriteOamTable_SubmarineShadow_0: @ 8509824
	sprite_oam -48, -20, 2,  0, 32x8
	sprite_oam -16, -20, 2,  4, 32x8
	sprite_oam  16, -20, 2,  8, 16x8
	sprite_oam  32, -20, 2, 10,  8x8
	sprite_oam -48, -12, 2, 11, 32x8
	sprite_oam -16, -12, 2, 15, 32x8
	sprite_oam  16, -12, 2, 19, 16x8
	sprite_oam  32, -12, 2, 21,  8x8
	sprite_oam -48,  -4, 2, 22, 32x8
	sprite_oam -16,  -4, 2, 26, 32x8
	sprite_oam  16,  -4, 2, 30, 16x8
	sprite_oam  32,  -4, 2, 32,  8x8
	sprite_oam -48,   4, 2, 33, 32x8
	sprite_oam -16,   4, 2, 37, 32x8
	sprite_oam  16,   4, 2, 41, 16x8
	sprite_oam  32,   4, 2, 43,  8x8

	.align 2, 0

gFieldObjectSpriteOamTable_SubmarineShadow_1: @ 8509864
	sprite_oam -48, -20, 1,  0, 32x8
	sprite_oam -16, -20, 1,  4, 32x8
	sprite_oam  16, -20, 1,  8, 16x8
	sprite_oam  32, -20, 1, 10,  8x8
	sprite_oam -48, -12, 1, 11, 32x8
	sprite_oam -16, -12, 1, 15, 32x8
	sprite_oam  16, -12, 1, 19, 16x8
	sprite_oam  32, -12, 1, 21,  8x8
	sprite_oam -48,  -4, 1, 22, 32x8
	sprite_oam -16,  -4, 1, 26, 32x8
	sprite_oam  16,  -4, 1, 30, 16x8
	sprite_oam  32,  -4, 1, 32,  8x8
	sprite_oam -48,   4, 1, 33, 32x8
	sprite_oam -16,   4, 1, 37, 32x8
	sprite_oam  16,   4, 1, 41, 16x8
	sprite_oam  32,   4, 1, 43,  8x8

	.align 2, 0

gFieldObjectSpriteOamTable_SubmarineShadow_2: @ 85098A4
	sprite_oam -48, -20, 2,  0, 32x8
	sprite_oam -16, -20, 2,  4, 32x8
	sprite_oam  16, -20, 2,  8, 16x8
	sprite_oam  32, -20, 2, 10,  8x8
	sprite_oam -48, -12, 2, 11, 32x8
	sprite_oam -16, -12, 2, 15, 32x8
	sprite_oam  16, -12, 2, 19, 16x8
	sprite_oam  32, -12, 2, 21,  8x8
	sprite_oam -48,  -4, 2, 22, 32x8
	sprite_oam -16,  -4, 2, 26, 32x8
	sprite_oam  16,  -4, 2, 30, 16x8
	sprite_oam  32,  -4, 2, 32,  8x8
	sprite_oam -48,   4, 2, 33, 32x8
	sprite_oam -16,   4, 2, 37, 32x8
	sprite_oam  16,   4, 2, 41, 16x8
	sprite_oam  32,   4, 2, 43,  8x8

	.align 2, 0

gFieldObjectSpriteOamTable_SubmarineShadow_3: @ 85098E4
	sprite_oam -48, -20, 1,  0, 32x8
	sprite_oam -16, -20, 1,  4, 32x8
	sprite_oam  16, -20, 1,  8, 16x8
	sprite_oam  32, -20, 1, 10,  8x8
	sprite_oam -48, -12, 1, 11, 32x8
	sprite_oam -16, -12, 1, 15, 32x8
	sprite_oam  16, -12, 1, 19, 16x8
	sprite_oam  32, -12, 1, 21,  8x8
	sprite_oam -48,  -4, 2, 22, 32x8
	sprite_oam -16,  -4, 2, 26, 32x8
	sprite_oam  16,  -4, 2, 30, 16x8
	sprite_oam  32,  -4, 2, 32,  8x8
	sprite_oam -48,   4, 2, 33, 32x8
	sprite_oam -16,   4, 2, 37, 32x8
	sprite_oam  16,   4, 2, 41, 16x8
	sprite_oam  32,   4, 2, 43,  8x8

	.align 2, 0

gFieldObjectSpriteOamTables_SubmarineShadow: @ 8509924
	.4byte 16 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SubmarineShadow_0 @ unknown

	.4byte 16 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SubmarineShadow_0 @ below high bridge

	.4byte 16 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SubmarineShadow_1 @ above high bridge

	.4byte 16 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SubmarineShadow_2 @ unknown

	.4byte 16 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SubmarineShadow_3 @ long grass below high bridge

	.4byte 16 @ number of sprites
	.4byte gFieldObjectSpriteOamTable_SubmarineShadow_3 @ long grass above high bridge
