
	.align 2
gFieldEffectObjectPaletteInfo0:: @ 850C9C0
	obj_pal gFieldEffectObjectPalette0, 0x1004

	.align 2
gFieldEffectObjectPaletteInfo1:: @ 850C9C8
	obj_pal gFieldEffectObjectPalette1, 0x1005

	.align 2
gFieldEffectObjectImageAnim_850C9D0:: @ 850C9D0
	obj_image_anim_frame 0, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_Shadow:: @ 850C9D8
	.4byte gFieldEffectObjectImageAnim_850C9D0

	.align 2
gFieldEffectObjectPicTable_ShadowSmall:: @ 850C9DC
	obj_tiles gFieldEffectObjectPic_ShadowSmall, 0x20

	.align 2
gFieldEffectObjectPicTable_ShadowMedium:: @ 850C9E4
	obj_tiles gFieldEffectObjectPic_ShadowMedium, 0x40

	.align 2
gFieldEffectObjectPicTable_ShadowLarge:: @ 850C9EC
	obj_tiles gFieldEffectObjectPic_ShadowLarge, 0x80

	.align 2
gFieldEffectObjectPicTable_ShadowExtraLarge:: @ 850C9F4
	obj_tiles gFieldEffectObjectPic_ShadowExtraLarge, 0x400

	.align 2
gFieldEffectObjectTemplate_ShadowSmall:: @ 850C9FC
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_8x8
	.4byte gFieldEffectObjectImageAnimTable_Shadow
	.4byte gFieldEffectObjectPicTable_ShadowSmall
	.4byte gDummyObjectRotScalAnimTable
	.4byte oamc_shadow

	.align 2
gFieldEffectObjectTemplate_ShadowMedium:: @ 850CA14
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_16x8
	.4byte gFieldEffectObjectImageAnimTable_Shadow
	.4byte gFieldEffectObjectPicTable_ShadowMedium
	.4byte gDummyObjectRotScalAnimTable
	.4byte oamc_shadow

	.align 2
gFieldEffectObjectTemplate_ShadowLarge:: @ 850CA2C
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_32x8
	.4byte gFieldEffectObjectImageAnimTable_Shadow
	.4byte gFieldEffectObjectPicTable_ShadowLarge
	.4byte gDummyObjectRotScalAnimTable
	.4byte oamc_shadow

	.align 2
gFieldEffectObjectTemplate_ShadowExtraLarge:: @ 850CA44
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_64x32
	.4byte gFieldEffectObjectImageAnimTable_Shadow
	.4byte gFieldEffectObjectPicTable_ShadowExtraLarge
	.4byte gDummyObjectRotScalAnimTable
	.4byte oamc_shadow

	.align 2
gFieldEffectObjectPicTable_TallGrass:: @ 850CA5C
	obj_tiles gFieldEffectObjectPic_TallGrass_0, 0x80
	obj_tiles gFieldEffectObjectPic_TallGrass_1, 0x80
	obj_tiles gFieldEffectObjectPic_TallGrass_2, 0x80
	obj_tiles gFieldEffectObjectPic_TallGrass_3, 0x80
	obj_tiles gFieldEffectObjectPic_TallGrass_4, 0x80

	.align 2
gFieldEffectObjectImageAnim_850CA84:: @ 850CA84
	obj_image_anim_frame 1, 10
	obj_image_anim_frame 2, 10
	obj_image_anim_frame 3, 10
	obj_image_anim_frame 4, 10
	obj_image_anim_frame 0, 10
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_TallGrass:: @ 850CA9C
	.4byte gFieldEffectObjectImageAnim_850CA84

	.align 2
gFieldEffectObjectTemplate_TallGrass:: @ 850CAA0
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1005 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_TallGrass
	.4byte gFieldEffectObjectPicTable_TallGrass
	.4byte gDummyObjectRotScalAnimTable
	.4byte unc_grass_normal

	.align 2
gFieldEffectObjectPicTable_Ripple:: @ 850CAB8
	obj_tiles gFieldEffectObjectPic_Ripple_0, 0x80
	obj_tiles gFieldEffectObjectPic_Ripple_1, 0x80
	obj_tiles gFieldEffectObjectPic_Ripple_2, 0x80
	obj_tiles gFieldEffectObjectPic_Ripple_3, 0x80
	obj_tiles gFieldEffectObjectPic_Ripple_4, 0x80

	.align 2
gFieldEffectObjectImageAnim_850CAE0:: @ 850CAE0
	obj_image_anim_frame 0, 12
	obj_image_anim_frame 1, 9
	obj_image_anim_frame 2, 9
	obj_image_anim_frame 3, 9
	obj_image_anim_frame 0, 9
	obj_image_anim_frame 1, 9
	obj_image_anim_frame 2, 11
	obj_image_anim_frame 4, 11
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_Ripple:: @ 850CB04
	.4byte gFieldEffectObjectImageAnim_850CAE0

	.align 2
gFieldEffectObjectTemplate_Ripple:: @ 850CB08
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1005 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_Ripple
	.4byte gFieldEffectObjectPicTable_Ripple
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_81561D0

	.align 2
gFieldEffectObjectPicTable_Ash:: @ 850CB20
	obj_tiles gFieldEffectObjectPic_Ash_0, 0x80
	obj_tiles gFieldEffectObjectPic_Ash_1, 0x80
	obj_tiles gFieldEffectObjectPic_Ash_2, 0x80
	obj_tiles gFieldEffectObjectPic_Ash_3, 0x80
	obj_tiles gFieldEffectObjectPic_Ash_4, 0x80

	.align 2
gFieldEffectObjectImageAnim_850CB48:: @ 850CB48
	obj_image_anim_frame 0, 12
	obj_image_anim_frame 1, 12
	obj_image_anim_frame 2, 8
	obj_image_anim_frame 3, 12
	obj_image_anim_frame 4, 12
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_Ash:: @ 850CB60
	.4byte gFieldEffectObjectImageAnim_850CB48

	.align 2
gFieldEffectObjectTemplate_Ash:: @ 850CB64
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1005 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_Ash
	.4byte gFieldEffectObjectPicTable_Ash
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8155460

	.align 2
gFieldEffectObjectPicTable_SurfBlob:: @ 850CB7C
	obj_tiles gFieldEffectObjectPic_SurfBlob_0, 0x200
	obj_tiles gFieldEffectObjectPic_SurfBlob_1, 0x200
	obj_tiles gFieldEffectObjectPic_SurfBlob_2, 0x200

	.align 2
gFieldEffectObjectImageAnim_850CB94:: @ 850CB94
	obj_image_anim_frame 0, 1
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnim_850CB9C:: @ 850CB9C
	obj_image_anim_frame 1, 1
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnim_850CBA4:: @ 850CBA4
	obj_image_anim_frame 2, 1
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnim_850CBAC:: @ 850CBAC
	obj_image_anim_frame 2, 1, OBJ_IMAGE_ANIM_H_FLIP
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnimTable_SurfBlob:: @ 850CBB4
	.4byte gFieldEffectObjectImageAnim_850CB94
	.4byte gFieldEffectObjectImageAnim_850CB9C
	.4byte gFieldEffectObjectImageAnim_850CBA4
	.4byte gFieldEffectObjectImageAnim_850CBAC

	.align 2
gFieldEffectObjectTemplate_SurfBlob:: @ 850CBC4
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldEffectObjectImageAnimTable_SurfBlob
	.4byte gFieldEffectObjectPicTable_SurfBlob
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8155658

	.align 2
gFieldEffectObjectPicTable_Arrow:: @ 850CBDC
	obj_tiles gFieldEffectObjectPic_Arrow_0, 0x80
	obj_tiles gFieldEffectObjectPic_Arrow_1, 0x80
	obj_tiles gFieldEffectObjectPic_Arrow_2, 0x80
	obj_tiles gFieldEffectObjectPic_Arrow_3, 0x80
	obj_tiles gFieldEffectObjectPic_Arrow_4, 0x80
	obj_tiles gFieldEffectObjectPic_Arrow_5, 0x80
	obj_tiles gFieldEffectObjectPic_Arrow_6, 0x80
	obj_tiles gFieldEffectObjectPic_Arrow_7, 0x80

	.align 2
gFieldEffectObjectImageAnim_850CC1C:: @ 850CC1C
	obj_image_anim_frame 3, 32
	obj_image_anim_frame 7, 32
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnim_850CC28:: @ 850CC28
	obj_image_anim_frame 0, 32
	obj_image_anim_frame 4, 32
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnim_850CC34:: @ 850CC34
	obj_image_anim_frame 1, 32
	obj_image_anim_frame 5, 32
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnim_850CC40:: @ 850CC40
	obj_image_anim_frame 2, 32
	obj_image_anim_frame 6, 32
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnimTable_Arrow:: @ 850CC4C
	.4byte gFieldEffectObjectImageAnim_850CC1C
	.4byte gFieldEffectObjectImageAnim_850CC28
	.4byte gFieldEffectObjectImageAnim_850CC34
	.4byte gFieldEffectObjectImageAnim_850CC40

	.align 2
gFieldEffectObjectTemplate_Arrow:: @ 850CC5C
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_Arrow
	.4byte gFieldEffectObjectPicTable_Arrow
	.4byte gDummyObjectRotScalAnimTable
	.4byte SpriteCallbackDummy

	.align 2
gFieldEffectObjectPicTable_GroundImpactDust:: @ 850CC74
	obj_tiles gFieldEffectObjectPic_GroundImpactDust_0, 0x40
	obj_tiles gFieldEffectObjectPic_GroundImpactDust_1, 0x40
	obj_tiles gFieldEffectObjectPic_GroundImpactDust_2, 0x40

	.align 2
gFieldEffectObjectImageAnim_850CC8C:: @ 850CC8C
	obj_image_anim_frame 0, 8
	obj_image_anim_frame 1, 8
	obj_image_anim_frame 2, 8
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_GroundImpactDust:: @ 850CC9C
	.4byte gFieldEffectObjectImageAnim_850CC8C

	.align 2
gFieldEffectObjectTemplate_GroundImpactDust:: @ 850CCA0
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x8
	.4byte gFieldEffectObjectImageAnimTable_GroundImpactDust
	.4byte gFieldEffectObjectPicTable_GroundImpactDust
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8156194

	.align 2
gFieldEffectObjectPicTable_BikeHopTallGrass:: @ 850CCB8
	obj_tiles gFieldEffectObjectPic_BikeHopTallGrass_0, 0x40
	obj_tiles gFieldEffectObjectPic_BikeHopTallGrass_1, 0x40
	obj_tiles gFieldEffectObjectPic_BikeHopTallGrass_2, 0x40
	obj_tiles gFieldEffectObjectPic_BikeHopTallGrass_3, 0x40

	.align 2
gFieldEffectObjectImageAnim_850CCD8:: @ 850CCD8
	obj_image_anim_frame 0, 8
	obj_image_anim_frame 1, 8
	obj_image_anim_frame 2, 8
	obj_image_anim_frame 3, 8
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_BikeHopTallGrass:: @ 850CCEC
	.4byte gFieldEffectObjectImageAnim_850CCD8

	.align 2
gFieldEffectObjectTemplate_BikeHopTallGrass:: @ 850CCF0
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1005 @ palette tag
	.4byte gFieldObjectBaseOam_16x8
	.4byte gFieldEffectObjectImageAnimTable_BikeHopTallGrass
	.4byte gFieldEffectObjectPicTable_BikeHopTallGrass
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8156194

	.align 2
gFieldEffectObjectPicTable_SandFootprints:: @ 850CD08
	obj_tiles gFieldEffectObjectPic_SandFootprints_0, 0x80
	obj_tiles gFieldEffectObjectPic_SandFootprints_1, 0x80

	.align 2
gFieldEffectObjectImageAnim_850CD18:: @ 850CD18
	obj_image_anim_frame 0, 1, OBJ_IMAGE_ANIM_V_FLIP
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CD20:: @ 850CD20
	obj_image_anim_frame 0, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CD28:: @ 850CD28
	obj_image_anim_frame 1, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CD30:: @ 850CD30
	obj_image_anim_frame 1, 1, OBJ_IMAGE_ANIM_H_FLIP
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_SandFootprints:: @ 850CD38
	.4byte gFieldEffectObjectImageAnim_850CD18
	.4byte gFieldEffectObjectImageAnim_850CD18
	.4byte gFieldEffectObjectImageAnim_850CD20
	.4byte gFieldEffectObjectImageAnim_850CD28
	.4byte gFieldEffectObjectImageAnim_850CD30

	.align 2
gFieldEffectObjectTemplate_SandFootprints:: @ 850CD4C
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_SandFootprints
	.4byte gFieldEffectObjectPicTable_SandFootprints
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8154C60

	.align 2
gFieldEffectObjectPicTable_DeepSandFootprints:: @ 850CD64
	obj_tiles gFieldEffectObjectPic_DeepSandFootprints_0, 0x80
	obj_tiles gFieldEffectObjectPic_DeepSandFootprints_1, 0x80

	.align 2
gFieldEffectObjectImageAnim_850CD74:: @ 850CD74
	obj_image_anim_frame 0, 1, OBJ_IMAGE_ANIM_V_FLIP
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CD7C:: @ 850CD7C
	obj_image_anim_frame 0, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CD84:: @ 850CD84
	obj_image_anim_frame 1, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CD8C:: @ 850CD8C
	obj_image_anim_frame 1, 1, OBJ_IMAGE_ANIM_H_FLIP
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_DeepSandFootprints:: @ 850CD94
	.4byte gFieldEffectObjectImageAnim_850CD74
	.4byte gFieldEffectObjectImageAnim_850CD74
	.4byte gFieldEffectObjectImageAnim_850CD7C
	.4byte gFieldEffectObjectImageAnim_850CD84
	.4byte gFieldEffectObjectImageAnim_850CD8C

	.align 2
gFieldEffectObjectTemplate_DeepSandFootprints:: @ 850CDA8
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_DeepSandFootprints
	.4byte gFieldEffectObjectPicTable_DeepSandFootprints
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8154C60

	.align 2
gFieldEffectObjectPicTable_BikeTireTracks:: @ 850CDC0
	obj_tiles gFieldEffectObjectPic_BikeTireTracks_0, 0x80
	obj_tiles gFieldEffectObjectPic_BikeTireTracks_1, 0x80
	obj_tiles gFieldEffectObjectPic_BikeTireTracks_2, 0x80
	obj_tiles gFieldEffectObjectPic_BikeTireTracks_3, 0x80

	.align 2
gFieldEffectObjectImageAnim_850CDE0:: @ 850CDE0
	obj_image_anim_frame 2, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CDE8:: @ 850CDE8
	obj_image_anim_frame 2, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CDF0:: @ 850CDF0
	obj_image_anim_frame 1, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CDF8:: @ 850CDF8
	obj_image_anim_frame 1, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CE00:: @ 850CE00
	obj_image_anim_frame 0, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CE08:: @ 850CE08
	obj_image_anim_frame 0, 1, OBJ_IMAGE_ANIM_H_FLIP
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CE10:: @ 850CE10
	obj_image_anim_frame 3, 1, OBJ_IMAGE_ANIM_H_FLIP
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CE18:: @ 850CE18
	obj_image_anim_frame 3, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_BikeTireTracks:: @ 850CE20
	.4byte gFieldEffectObjectImageAnim_850CDE0
	.4byte gFieldEffectObjectImageAnim_850CDE0
	.4byte gFieldEffectObjectImageAnim_850CDE8
	.4byte gFieldEffectObjectImageAnim_850CDF0
	.4byte gFieldEffectObjectImageAnim_850CDF8
	.4byte gFieldEffectObjectImageAnim_850CE00
	.4byte gFieldEffectObjectImageAnim_850CE08
	.4byte gFieldEffectObjectImageAnim_850CE10
	.4byte gFieldEffectObjectImageAnim_850CE18

	.align 2
gFieldEffectObjectTemplate_BikeTireTracks:: @ 850CE44
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_BikeTireTracks
	.4byte gFieldEffectObjectPicTable_BikeTireTracks
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8154C60

	.align 2
gFieldEffectObjectPicTable_BikeHopBigSplash:: @ 850CE5C
	obj_tiles gFieldEffectObjectPic_BikeHopBigSplash_0, 0x80
	obj_tiles gFieldEffectObjectPic_BikeHopBigSplash_1, 0x80
	obj_tiles gFieldEffectObjectPic_BikeHopBigSplash_2, 0x80
	obj_tiles gFieldEffectObjectPic_BikeHopBigSplash_3, 0x80

	.align 2
gFieldEffectObjectImageAnim_850CE7C:: @ 850CE7C
	obj_image_anim_frame 0, 8
	obj_image_anim_frame 1, 8
	obj_image_anim_frame 2, 8
	obj_image_anim_frame 3, 8
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_BikeHopBigSplash:: @ 850CE90
	.4byte gFieldEffectObjectImageAnim_850CE7C

	.align 2
gFieldEffectObjectTemplate_BikeHopBigSplash:: @ 850CE94
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_BikeHopBigSplash
	.4byte gFieldEffectObjectPicTable_BikeHopBigSplash
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8156194

	.align 2
gFieldEffectObjectPicTable_Splash:: @ 850CEAC
	obj_tiles gFieldEffectObjectPic_Splash_0, 0x40
	obj_tiles gFieldEffectObjectPic_Splash_1, 0x40

	.align 2
gFieldEffectObjectImageAnim_850CEBC:: @ 850CEBC
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850CEC8:: @ 850CEC8
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 0, 6
	obj_image_anim_frame 1, 6
	obj_image_anim_frame 0, 8
	obj_image_anim_frame 1, 8
	obj_image_anim_frame 0, 6
	obj_image_anim_frame 1, 6
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnimTable_Splash:: @ 850CEEC
	.4byte gFieldEffectObjectImageAnim_850CEBC
	.4byte gFieldEffectObjectImageAnim_850CEC8

	.align 2
gFieldEffectObjectTemplate_Splash:: @ 850CEF4
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x8
	.4byte gFieldEffectObjectImageAnimTable_Splash
	.4byte gFieldEffectObjectPicTable_Splash
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8154D90

	.align 2
gFieldEffectObjectPicTable_BikeHopSmallSplash:: @ 850CF0C
	obj_tiles gFieldEffectObjectPic_BikeHopSmallSplash_0, 0x40
	obj_tiles gFieldEffectObjectPic_BikeHopSmallSplash_1, 0x40
	obj_tiles gFieldEffectObjectPic_BikeHopSmallSplash_2, 0x40

	.align 2
gFieldEffectObjectImageAnim_850CF24:: @ 850CF24
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_BikeHopSmallSplash:: @ 850CF34
	.4byte gFieldEffectObjectImageAnim_850CF24

	.align 2
gFieldEffectObjectTemplate_BikeHopSmallSplash:: @ 850CF38
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x8
	.4byte gFieldEffectObjectImageAnimTable_BikeHopSmallSplash
	.4byte gFieldEffectObjectPicTable_BikeHopSmallSplash
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8156194

	.align 2
gFieldEffectObjectPicTable_LongGrass:: @ 850CF50
	obj_tiles gFieldEffectObjectPic_LongGrass_0, 0x80
	obj_tiles gFieldEffectObjectPic_LongGrass_1, 0x80
	obj_tiles gFieldEffectObjectPic_LongGrass_2, 0x80
	obj_tiles gFieldEffectObjectPic_LongGrass_3, 0x80

	.align 2
gFieldEffectObjectImageAnim_850CF70:: @ 850CF70
	obj_image_anim_frame 1, 3
	obj_image_anim_frame 2, 3
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 3, 4
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 3, 4
	obj_image_anim_frame 0, 4
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_LongGrass:: @ 850CF90
	.4byte gFieldEffectObjectImageAnim_850CF70

	.align 2
gFieldEffectObjectTemplate_LongGrass:: @ 850CF94
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1005 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_LongGrass
	.4byte gFieldEffectObjectPicTable_LongGrass
	.4byte gDummyObjectRotScalAnimTable
	.4byte unc_grass_tall

	.align 2
gFieldEffectObjectPicTable_Unknown16:: @ 850CFAC
	obj_tiles gFieldEffectObjectPic_Unknown16_0, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown16_1, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown16_2, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown16_3, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown16_4, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown16_5, 0x80

	.align 2
gFieldEffectObjectImageAnim_850CFDC:: @ 850CFDC
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 8
	obj_image_anim_frame 3, 8
	obj_image_anim_frame 4, 8
	obj_image_anim_frame 5, 8
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_Unknown16:: @ 850CFF8
	.4byte gFieldEffectObjectImageAnim_850CFDC

	.align 2
gFieldEffectObjectTemplate_Unknown16:: @ 850CFFC
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1005 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_Unknown16
	.4byte gFieldEffectObjectPicTable_Unknown16
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8156194

	.align 2
gFieldEffectObjectPicTable_Unknown17:: @ 850D014
	obj_tiles gFieldEffectObjectPic_Unknown16_5, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown17_0, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown17_1, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown17_2, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown17_3, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown17_4, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown17_5, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown17_6, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown17_7, 0x80

	.align 2
gFieldEffectObjectImageAnim_850D05C:: @ 850D05C
	obj_image_anim_frame 0, 10
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_frame 3, 4
	obj_image_anim_frame 4, 4
	obj_image_anim_frame 5, 4
	obj_image_anim_frame 6, 4
	obj_image_anim_frame 7, 4
	obj_image_anim_frame 8, 4
	obj_image_anim_jump 7

	.align 2
gFieldEffectObjectImageAnimTable_Unknown17:: @ 850D084
	.4byte gFieldEffectObjectImageAnim_850D05C

	.align 2
gFieldEffectObjectTemplate_Unknown17:: @ 850D088
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1005 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_Unknown17
	.4byte gFieldEffectObjectPicTable_Unknown17
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_81561D0

	.align 2
gFieldEffectObjectPicTable_Unknown18:: @ 850D0A0
	obj_tiles gFieldEffectObjectPic_Unknown18_0, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown18_1, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown18_2, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown18_3, 0x80

	.align 2
gFieldEffectObjectImageAnim_850D0C0:: @ 850D0C0
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_frame 3, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnimTable_Unknown18:: @ 850D0DC
	.4byte gFieldEffectObjectImageAnim_850D0C0

	.align 2
gFieldEffectObjectTemplate_Unknown18:: @ 850D0E0
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1005 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_Unknown18
	.4byte gFieldEffectObjectPicTable_Unknown18
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_81561D0

	.align 2
gFieldEffectObjectPicTable_Unknown19:: @ 850D0F8
	obj_tiles gFieldEffectObjectPic_Unknown19_0, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown19_1, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown19_2, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown19_3, 0x80

	.align 2
gFieldEffectObjectImageAnim_850D118:: @ 850D118
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_frame 3, 4
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnimTable_Unknown19:: @ 850D12C
	.4byte gFieldEffectObjectImageAnim_850D118

	.align 2
gFieldEffectObjectTemplate_Unknown19:: @ 850D130
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_Unknown19
	.4byte gFieldEffectObjectPicTable_Unknown19
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_81561D0

	.align 2
gFieldEffectObjectPicTable_Unknown29:: @ 850D148
	obj_tiles gFieldEffectObjectPic_Unknown29_0, 0x40
	obj_tiles gFieldEffectObjectPic_Unknown29_1, 0x40
	obj_tiles gFieldEffectObjectPic_Unknown29_2, 0x40

	.align 2
gFieldEffectObjectImageAnim_850D160:: @ 850D160
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_Unknown29:: @ 850D170
	.4byte gFieldEffectObjectImageAnim_850D160

	.align 2
gFieldEffectObjectTemplate_Unknown29:: @ 850D174
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x8
	.4byte gFieldEffectObjectImageAnimTable_Unknown29
	.4byte gFieldEffectObjectPicTable_Unknown29
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_81559BC

	.align 2
gFieldEffectObjectPicTable_Unknown20:: @ 850D18C
	obj_tiles gFieldEffectObjectPic_Unknown20_0, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown20_1, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown20_2, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown20_3, 0x80

	.align 2
gFieldEffectObjectImageAnim_850D1AC:: @ 850D1AC
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_frame 3, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_jump 0

	.align 2
gFieldEffectObjectImageAnimTable_Unknown20:: @ 850D1C8
	.4byte gFieldEffectObjectImageAnim_850D1AC

	.align 2
gFieldEffectObjectTemplate_Unknown20:: @ 850D1CC
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_Unknown20
	.4byte gFieldEffectObjectPicTable_Unknown20
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_81561D0

	.align 2
gFieldEffectObjectRotScalAnim_850D1E4:: @ 850D1E4
	obj_rot_scal_anim_frame 0xFF00, 0x100, -128, 0
	obj_rot_scal_anim_frame 0x1, 0x0, 0, 4
	obj_rot_scal_anim_frame 0x0, 0x0, 0, 8
	obj_rot_scal_anim_frame 0xFFFF, 0x0, 0, 4
	obj_rot_scal_anim_frame 0x0, 0x0, 0, 8
	obj_rot_scal_anim_frame 0xFFFF, 0x0, 0, 4
	obj_rot_scal_anim_frame 0x0, 0x0, 0, 8
	obj_rot_scal_anim_frame 0x1, 0x0, 0, 4
	obj_rot_scal_anim_frame 0x0, 0x0, 0, 8
	obj_rot_scal_anim_jump 1

	.align 2
gFieldEffectObjectRotScalAnim_850D234:: @ 850D234
	obj_rot_scal_anim_frame 0x100, 0x100, -128, 0
	obj_rot_scal_anim_frame 0xFFFF, 0x0, 0, 4
	obj_rot_scal_anim_frame 0x0, 0x0, 0, 8
	obj_rot_scal_anim_frame 0x1, 0x0, 0, 4
	obj_rot_scal_anim_frame 0x0, 0x0, 0, 8
	obj_rot_scal_anim_frame 0x1, 0x0, 0, 4
	obj_rot_scal_anim_frame 0x0, 0x0, 0, 8
	obj_rot_scal_anim_frame 0xFFFF, 0x0, 0, 4
	obj_rot_scal_anim_frame 0x0, 0x0, 0, 8
	obj_rot_scal_anim_jump 1

	.align 2
gFieldEffectObjectRotScalAnimTable_Unknown21:: @ 850D284
	.4byte gFieldEffectObjectRotScalAnim_850D1E4
	.4byte gFieldEffectObjectRotScalAnim_850D234

	.align 2
gFieldEffectObjectTemplate_Unknown21:: @ 850D28C
	.2byte 0x0 @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gDefaultOamAttributes
	.4byte gDummyObjectImageAnimTable
	.4byte NULL
	.4byte gFieldEffectObjectRotScalAnimTable_Unknown21
	.4byte SpriteCallbackDummy

	.align 2
gFieldEffectObjectPicTable_BerryTreeGrowthSparkle:: @ 850D2A4
	obj_tiles gFieldEffectObjectPic_BerryTreeGrowthSparkle_0, 0x80
	obj_tiles gFieldEffectObjectPic_BerryTreeGrowthSparkle_1, 0x80
	obj_tiles gFieldEffectObjectPic_BerryTreeGrowthSparkle_2, 0x80
	obj_tiles gFieldEffectObjectPic_BerryTreeGrowthSparkle_3, 0x80
	obj_tiles gFieldEffectObjectPic_BerryTreeGrowthSparkle_4, 0x80
	obj_tiles gFieldEffectObjectPic_BerryTreeGrowthSparkle_5, 0x80

	.align 2
gFieldEffectObjectImageAnim_850D2D4:: @ 850D2D4
	obj_image_anim_frame 0, 8
	obj_image_anim_frame 1, 8
	obj_image_anim_frame 2, 8
	obj_image_anim_frame 3, 8
	obj_image_anim_frame 4, 8
	obj_image_anim_frame 5, 8
	obj_image_anim_loop 0
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_frame 3, 4
	obj_image_anim_frame 4, 4
	obj_image_anim_frame 5, 4
	obj_image_anim_loop 3
	obj_image_anim_frame 0, 8
	obj_image_anim_frame 1, 8
	obj_image_anim_frame 2, 8
	obj_image_anim_frame 3, 8
	obj_image_anim_frame 4, 8
	obj_image_anim_frame 5, 8
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_BerryTreeGrowthSparkle:: @ 850D328
	.4byte gFieldEffectObjectImageAnim_850D2D4

	.align 2
gFieldEffectObjectTemplate_BerryTreeGrowthSparkle:: @ 850D32C
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_BerryTreeGrowthSparkle
	.4byte gFieldEffectObjectPicTable_BerryTreeGrowthSparkle
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_81561D0

	.align 2
gFieldEffectObjectPicTable_TreeDisguise:: @ 850D344
	obj_tiles gFieldEffectObjectPic_TreeDisguise_0, 0x100
	obj_tiles gFieldEffectObjectPic_TreeDisguise_1, 0x100
	obj_tiles gFieldEffectObjectPic_TreeDisguise_2, 0x100
	obj_tiles gFieldEffectObjectPic_TreeDisguise_3, 0x100
	obj_tiles gFieldEffectObjectPic_TreeDisguise_4, 0x100
	obj_tiles gFieldEffectObjectPic_TreeDisguise_5, 0x100
	obj_tiles gFieldEffectObjectPic_TreeDisguise_6, 0x100

	.align 2
gFieldEffectObjectImageAnim_850D37C:: @ 850D37C
	obj_image_anim_frame 0, 16
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850D384:: @ 850D384
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_frame 3, 4
	obj_image_anim_frame 4, 4
	obj_image_anim_frame 5, 4
	obj_image_anim_frame 6, 4
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_TreeDisguise:: @ 850D3A4
	.4byte gFieldEffectObjectImageAnim_850D37C
	.4byte gFieldEffectObjectImageAnim_850D384

	.align 2
gFieldEffectObjectTemplate_TreeDisguise:: @ 850D3AC
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldEffectObjectImageAnimTable_TreeDisguise
	.4byte gFieldEffectObjectPicTable_TreeDisguise
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8155C88

	.align 2
gFieldEffectObjectPicTable_MountainDisguise:: @ 850D3C4
	obj_tiles gFieldEffectObjectPic_MountainDisguise_0, 0x100
	obj_tiles gFieldEffectObjectPic_MountainDisguise_1, 0x100
	obj_tiles gFieldEffectObjectPic_MountainDisguise_2, 0x100
	obj_tiles gFieldEffectObjectPic_MountainDisguise_3, 0x100
	obj_tiles gFieldEffectObjectPic_MountainDisguise_4, 0x100
	obj_tiles gFieldEffectObjectPic_MountainDisguise_5, 0x100
	obj_tiles gFieldEffectObjectPic_MountainDisguise_6, 0x100

	.align 2
gFieldEffectObjectImageAnim_850D3FC:: @ 850D3FC
	obj_image_anim_frame 0, 16
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnim_850D404:: @ 850D404
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_frame 3, 4
	obj_image_anim_frame 4, 4
	obj_image_anim_frame 5, 4
	obj_image_anim_frame 6, 4
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_MountainDisguise:: @ 850D424
	.4byte gFieldEffectObjectImageAnim_850D3FC
	.4byte gFieldEffectObjectImageAnim_850D404

	.align 2
gFieldEffectObjectTemplate_MountainDisguise:: @ 850D42C
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldEffectObjectImageAnimTable_MountainDisguise
	.4byte gFieldEffectObjectPicTable_MountainDisguise
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8155C88

	.align 2
gFieldEffectObjectPicTable_SandDisguisePlaceholder:: @ 850D444
	obj_tiles gFieldEffectObjectPic_SandDisguisePlaceholder_0, 0x100
	obj_tiles gFieldEffectObjectPic_SandDisguisePlaceholder_1, 0x100
	obj_tiles gFieldEffectObjectPic_SandDisguisePlaceholder_2, 0x100
	obj_tiles gFieldEffectObjectPic_SandDisguisePlaceholder_3, 0x100
	obj_tiles gFieldEffectObjectPic_SandDisguisePlaceholder_4, 0x100
	obj_tiles gFieldEffectObjectPic_SandDisguisePlaceholder_5, 0x100
	obj_tiles gFieldEffectObjectPic_SandDisguisePlaceholder_6, 0x100

	.align 2
gFieldEffectObjectTemplate_SandDisguisePlaceholder:: @ 850D47C
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldEffectObjectImageAnimTable_TreeDisguise
	.4byte gFieldEffectObjectPicTable_SandDisguisePlaceholder
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8155C88

	.align 2
gFieldEffectObjectPicTable_Bird:: @ 850D494
	obj_tiles gFieldEffectObjectPic_Bird, 0x200

	.align 2
gFieldEffectObjectImageAnim_850D49C:: @ 850D49C
	obj_image_anim_frame 0, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_Bird:: @ 850D4A4
	.4byte gFieldEffectObjectImageAnim_850D49C

	.align 2
gFieldEffectObjectTemplate_Bird:: @ 850D4A8
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldEffectObjectImageAnimTable_Bird
	.4byte gFieldEffectObjectPicTable_Bird
	.4byte gDummyObjectRotScalAnimTable
	.4byte SpriteCallbackDummy

	.align 2
gFieldEffectObjectPicTable_ShortGrass:: @ 850D4C0
	obj_tiles gFieldEffectObjectPic_ShortGrass_0, 0x80
	obj_tiles gFieldEffectObjectPic_ShortGrass_1, 0x80

	.align 2
gFieldEffectObjectImageAnim_850D4D0:: @ 850D4D0
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_ShortGrass:: @ 850D4DC
	.4byte gFieldEffectObjectImageAnim_850D4D0

	.align 2
gFieldEffectObjectTemplate_ShortGrass:: @ 850D4E0
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1005 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_ShortGrass
	.4byte gFieldEffectObjectPicTable_ShortGrass
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8154A10

	.align 2
gFieldEffectObjectPicTable_HotSpringsWater:: @ 850D4F8
	obj_tiles gFieldEffectObjectPic_HotSpringsWater, 0x80

	.align 2
gFieldEffectObjectImageAnim_850D500:: @ 850D500
	obj_image_anim_frame 0, 4
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_HotSpringsWater:: @ 850D508
	.4byte gFieldEffectObjectImageAnim_850D500

	.align 2
gFieldEffectObjectTemplate_HotSpringsWater:: @ 850D50C
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1005 @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_HotSpringsWater
	.4byte gFieldEffectObjectPicTable_HotSpringsWater
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8155158

	.align 2
gFieldEffectObjectPicTable_JumpOutOfAsh:: @ 850D524
	obj_tiles gFieldEffectObjectPic_JumpOutOfAsh_0, 0x80
	obj_tiles gFieldEffectObjectPic_JumpOutOfAsh_1, 0x80
	obj_tiles gFieldEffectObjectPic_JumpOutOfAsh_2, 0x80
	obj_tiles gFieldEffectObjectPic_JumpOutOfAsh_3, 0x80
	obj_tiles gFieldEffectObjectPic_JumpOutOfAsh_4, 0x80

	.align 2
gFieldEffectObjectImageAnim_850D54C:: @ 850D54C
	obj_image_anim_frame 0, 6
	obj_image_anim_frame 1, 6
	obj_image_anim_frame 2, 6
	obj_image_anim_frame 3, 6
	obj_image_anim_frame 4, 6
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_JumpOutOfAsh:: @ 850D564
	.4byte gFieldEffectObjectImageAnim_850D54C

	.align 2
gFieldEffectObjectTemplate_JumpOutOfAsh:: @ 850D568
	.2byte 0xFFFF @ tiles tag
	.2byte 0x100D @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_JumpOutOfAsh
	.4byte gFieldEffectObjectPicTable_JumpOutOfAsh
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_80B7CAC

	.align 2
gFieldEffectObjectPaletteInfo2:: @ 850D580
	obj_pal gFieldEffectObjectPalette2, 0x100D

	.align 2
gFieldEffectObjectPicTable_Unknown33:: @ 850D588
	obj_tiles gFieldEffectObjectPic_Unknown33_0, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown33_1, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown33_2, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown33_3, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown33_4, 0x80

	.align 2
gFieldEffectObjectImageAnim_850D5B0:: @ 850D5B0
	obj_image_anim_frame 0, 6
	obj_image_anim_frame 1, 6
	obj_image_anim_frame 2, 6
	obj_image_anim_frame 3, 6
	obj_image_anim_frame 4, 6
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_Unknown33:: @ 850D5C8
	.4byte gFieldEffectObjectImageAnim_850D5B0

	.align 2
gFieldEffectObjectTemplate_Unknown33:: @ 850D5CC
	.2byte 0xFFFF @ tiles tag
	.2byte 0x100D @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_Unknown33
	.4byte gFieldEffectObjectPicTable_Unknown33
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_80B7A58

	.align 2
gFieldEffectObjectPicTable_Bubbles:: @ 850D5E4
	obj_tiles gFieldEffectObjectPic_Bubbles_0, 0x100
	obj_tiles gFieldEffectObjectPic_Bubbles_1, 0x100
	obj_tiles gFieldEffectObjectPic_Bubbles_2, 0x100
	obj_tiles gFieldEffectObjectPic_Bubbles_3, 0x100
	obj_tiles gFieldEffectObjectPic_Bubbles_4, 0x100
	obj_tiles gFieldEffectObjectPic_Bubbles_5, 0x100
	obj_tiles gFieldEffectObjectPic_Bubbles_6, 0x100
	obj_tiles gFieldEffectObjectPic_Bubbles_7, 0x100

	.align 2
gFieldEffectObjectImageAnim_850D624:: @ 850D624
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 1, 4
	obj_image_anim_frame 2, 4
	obj_image_anim_frame 3, 6
	obj_image_anim_frame 4, 6
	obj_image_anim_frame 5, 4
	obj_image_anim_frame 6, 4
	obj_image_anim_frame 7, 4
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_Bubbles:: @ 850D648
	.4byte gFieldEffectObjectImageAnim_850D624

	.align 2
gFieldEffectObjectTemplate_Bubbles:: @ 850D64C
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1004 @ palette tag
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldEffectObjectImageAnimTable_Bubbles
	.4byte gFieldEffectObjectPicTable_Bubbles
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8155AEC

	.align 2
gFieldEffectObjectPicTable_Unknown35:: @ 850D664
	obj_tiles gFieldEffectObjectPic_Unknown35_0, 0x80
	obj_tiles gFieldEffectObjectPic_Unknown35_1, 0x80

	.align 2
gFieldEffectObjectImageAnim_850D674:: @ 850D674
	obj_image_anim_frame 0, 3
	obj_image_anim_frame 1, 5
	obj_image_anim_frame 0, 5
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_Unknown35:: @ 850D684
	.4byte gFieldEffectObjectImageAnim_850D674

	.align 2
gFieldEffectObjectTemplate_Unknown35:: @ 850D688
	.2byte 0xFFFF @ tiles tag
	.2byte 0x100F @ palette tag
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldEffectObjectImageAnimTable_Unknown35
	.4byte gFieldEffectObjectPicTable_Unknown35
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8155E50

	.align 2
gFieldEffectObjectPaletteInfo3:: @ 850D6A0
	obj_pal gFieldEffectObjectPalette3, 0x100F

	.align 2
gFieldEffectObjectImageAnim_850D6A8:: @ 850D6A8
	obj_image_anim_frame 0, 1
	obj_image_anim_end

	.align 2
gFieldEffectObjectImageAnimTable_Rayquaza:: @ 850D6B0
	.4byte gFieldEffectObjectImageAnim_850D6A8

	.align 2
gFieldEffectObjectPicTable_Rayquaza:: @ 850D6B4
	obj_tiles gFieldObjectPic_Rayquaza_0, 0x200

	.align 2
gFieldEffectObjectTemplate_Rayquaza:: @ 850D6BC
	.2byte 0xFFFF @ tiles tag
	.2byte 0xFFFF @ palette tag
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldEffectObjectImageAnimTable_Rayquaza
	.4byte gFieldEffectObjectPicTable_Rayquaza
	.4byte gDummyObjectRotScalAnimTable
	.4byte sub_8155F80
