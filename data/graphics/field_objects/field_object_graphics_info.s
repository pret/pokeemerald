	.align 2, 0

gFieldObjectGraphicsInfo_BrendanNormal: ; 8509954
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_BrendanMayNormal
	.4byte gFieldObjectPicTable_BrendanNormal
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BrendanMachBike: ; 8509978
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_BIKE_TIRE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_BrendanMachBike
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BrendanAcroBike: ; 850999C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_BIKE_TIRE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_AcroBike
	.4byte gFieldObjectPicTable_BrendanAcroBike
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BrendanSurfing: ; 85099C0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_DISABLE_REFLECTION_PALETTE_LOAD | (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Surfing
	.4byte gFieldObjectPicTable_BrendanSurfing
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BrendanFieldMove: ; 85099E4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_FieldMove
	.4byte gFieldObjectPicTable_BrendanFieldMove
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_QuintyPlump: ; 8509A08
	.2byte 0xFFFF ; tiles tag
	.2byte 0x110B ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_L << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_QuintyPlump
	.4byte gFieldObjectPicTable_QuintyPlump
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_LittleBoy1: ; 8509A2C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_LittleBoy1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_LittleGirl1: ; 8509A50
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_LittleGirl1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Boy1: ; 8509A74
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Boy1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Girl1: ; 8509A98
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Girl1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Boy2: ; 8509ABC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Boy2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Girl2: ; 8509AE0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Girl2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_LittleBoy2: ; 8509B04
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_LittleBoy2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_LittleGirl2: ; 8509B28
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_LittleGirl2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Boy3: ; 8509B4C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Boy3
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Girl3: ; 8509B70
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Girl3
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Boy4: ; 8509B94
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Boy4
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Woman1: ; 8509BB8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Woman1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_FatMan: ; 8509BDC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_FatMan
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Woman2: ; 8509C00
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Woman2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Man1: ; 8509C24
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Man1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Woman3: ; 8509C48
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Woman3
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_OldMan1: ; 8509C6C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_OldMan1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_OldWoman1: ; 8509C90
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_OldWoman1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Man2: ; 8509CB4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Man2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Woman4: ; 8509CD8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Woman4
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Man3: ; 8509CFC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Man3
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Woman5: ; 8509D20
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Woman5
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Cook: ; 8509D44
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Cook
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Woman6: ; 8509D68
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Woman6
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_OldMan2: ; 8509D8C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_OldMan2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_OldWoman2: ; 8509DB0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_OldWoman2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Camper: ; 8509DD4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Camper
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Picnicker: ; 8509DF8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Picnicker
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Man4: ; 8509E1C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Man4
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Woman7: ; 8509E40
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Woman7
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Youngster: ; 8509E64
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Youngster
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BugCatcher: ; 8509E88
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_BugCatcher
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_PsychicM: ; 8509EAC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_PsychicM
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_SchoolKidM: ; 8509ED0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_SchoolKidM
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Maniac: ; 8509EF4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Maniac
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_HexManiac: ; 8509F18
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_HexManiac
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Rayquaza1: ; 8509F3C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 2048 ; image size
	.2byte 64 ; width
	.2byte 64 ; height
	.byte F_DISABLE_REFLECTION_PALETTE_LOAD | (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_64x64
	.4byte gFieldObjectSpriteOamTables_64x64
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_RayquazaStill
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_SwimmerM: ; 8509F60
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_SwimmerM
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_SwimmerF: ; 8509F84
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_SwimmerF
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BlackBelt: ; 8509FA8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_BlackBelt
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Beauty: ; 8509FCC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Beauty
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Scientist1: ; 8509FF0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Scientist1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Lass: ; 850A014
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Lass
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Gentleman: ; 850A038
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Gentleman
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Sailor: ; 850A05C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Sailor
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Fisherman: ; 850A080
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Fisherman
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RunningTriathleteM: ; 850A0A4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_RunningTriathleteM
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RunningTriathleteF: ; 850A0C8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_RunningTriathleteF
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_TuberF: ; 850A0EC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_TuberF
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_TuberM: ; 850A110
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_TuberM
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Hiker: ; 850A134
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Hiker
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_CyclingTriathleteM: ; 850A158
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_BIKE_TIRE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_AcroBike
	.4byte gFieldObjectPicTable_CyclingTriathleteM
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_CyclingTriathleteF: ; 850A17C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_BIKE_TIRE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_AcroBike
	.4byte gFieldObjectPicTable_CyclingTriathleteF
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Nurse: ; 850A1A0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Nurse
	.4byte gFieldObjectPicTable_Nurse
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_ItemBall: ; 850A1C4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_ItemBall
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BerryTree: ; 850A1E8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte NULL ; sprite OAM tables
	.4byte gFieldObjectImageAnimTable_BerryTree
	.4byte gFieldObjectPicTable_PechaBerryTree
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BerryTreeEarlyStages: ; 850A20C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_BerryTree
	.4byte gFieldObjectPicTable_PechaBerryTree
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BerryTreeLateStages: ; 850A230
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_BerryTree
	.4byte gFieldObjectPicTable_PechaBerryTree
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_ProfBirch: ; 850A254
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_ProfBirch
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Man5: ; 850A278
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Man5
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Man6: ; 850A29C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Man6
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_ReporterM: ; 850A2C0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_ReporterM
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_ReporterF: ; 850A2E4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_ReporterF
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Bard: ; 850A308
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MauvilleOldMan1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Hipster: ; 850A32C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MauvilleOldMan1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Trader: ; 850A350
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MauvilleOldMan1
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Storyteller: ; 850A374
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MauvilleOldMan2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Giddy: ; 850A398
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MauvilleOldMan2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_UnusedMauvilleOldMan1: ; 850A3BC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MauvilleOldMan2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_UnusedMauvilleOldMan2: ; 850A3E0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MauvilleOldMan2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_UnusedNatuDoll: ; 850A404
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_UnusedNatuDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_UnusedMagnemiteDoll: ; 850A428
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_UnusedMagnemiteDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_UnusedSquirtleDoll: ; 850A44C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_UnusedSquirtleDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_UnusedWooperDoll: ; 850A470
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_UnusedWooperDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_UnusedPikachuDoll: ; 850A494
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_UnusedPikachuDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_UnusedPorygon2Doll: ; 850A4B8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_UnusedPorygon2Doll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_CuttableTree: ; 850A4DC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_CuttableTree
	.4byte gFieldObjectPicTable_CuttableTree
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MartEmployee: ; 850A500
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MartEmployee
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RooftopSaleWoman: ; 850A524
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_RooftopSaleWoman
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Teala: ; 850A548
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Teala
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BreakableRock: ; 850A56C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_BreakableRock
	.4byte gFieldObjectPicTable_BreakableRock
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_PushableBoulder: ; 850A590
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_PushableBoulder
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MrBrineysBoat: ; 850A5B4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MrBrineysBoat
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MayNormal: ; 850A5D8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_BrendanMayNormal
	.4byte gFieldObjectPicTable_MayNormal
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MayMachBike: ; 850A5FC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_BIKE_TIRE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MayMachBike
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MayAcroBike: ; 850A620
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_BIKE_TIRE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_AcroBike
	.4byte gFieldObjectPicTable_MayAcroBike
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MaySurfing: ; 850A644
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_DISABLE_REFLECTION_PALETTE_LOAD | (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Surfing
	.4byte gFieldObjectPicTable_MaySurfing
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MayFieldMove: ; 850A668
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_FieldMove
	.4byte gFieldObjectPicTable_MayFieldMove
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Truck: ; 850A68C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x110D ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 1152 ; image size
	.2byte 48 ; width
	.2byte 48 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_Truck
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_Truck
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_VigorothCarryingBox: ; 850A6B0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x110E ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_VigorothCarryingBox
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_VigorothFacingAway: ; 850A6D4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x110E ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_VigorothFacingAway
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BirchsBag: ; 850A6F8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BirchsBag
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_EnemyZigzagoon: ; 850A71C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x110F ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_EnemyZigzagoon
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Poochyena: ; 850A740
	.2byte 0xFFFF ; tiles tag
	.2byte 0x111C ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Poochyena
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Artist: ; 850A764
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Artist
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RivalBrendanNormal: ; 850A788
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_BrendanMayNormal
	.4byte gFieldObjectPicTable_BrendanNormal
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RivalBrendanMachBike: ; 850A7AC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_BIKE_TIRE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_BrendanMachBike
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RivalBrendanAcroBike: ; 850A7D0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_BIKE_TIRE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_AcroBike
	.4byte gFieldObjectPicTable_BrendanAcroBike
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RivalBrendanSurfing: ; 850A7F4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_DISABLE_REFLECTION_PALETTE_LOAD | (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Surfing
	.4byte gFieldObjectPicTable_BrendanSurfing
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RivalBrendanFieldMove: ; 850A818
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_FieldMove
	.4byte gFieldObjectPicTable_BrendanFieldMove
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RivalMayNormal: ; 850A83C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_BrendanMayNormal
	.4byte gFieldObjectPicTable_MayNormal
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RivalMayMachBike: ; 850A860
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_BIKE_TIRE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MayMachBike
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RivalMayAcroBike: ; 850A884
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_BIKE_TIRE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_AcroBike
	.4byte gFieldObjectPicTable_MayAcroBike
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RivalMaySurfing: ; 850A8A8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_DISABLE_REFLECTION_PALETTE_LOAD | (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Surfing
	.4byte gFieldObjectPicTable_MaySurfing
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RivalMayFieldMove: ; 850A8CC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_FieldMove
	.4byte gFieldObjectPicTable_MayFieldMove
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Cameraman: ; 850A8F0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Cameraman
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BrendanUnderwater: ; 850A914
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1115 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_DISABLE_REFLECTION_PALETTE_LOAD | (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_BrendanUnderwater
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MayUnderwater: ; 850A938
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1115 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_DISABLE_REFLECTION_PALETTE_LOAD | (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MayUnderwater
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MovingBox: ; 850A95C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1112 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_MovingBox
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_CableCar: ; 850A980
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1113 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 2048 ; image size
	.2byte 64 ; width
	.2byte 64 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_64x64
	.4byte gFieldObjectSpriteOamTables_64x64
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_CableCar
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Scientist2: ; 850A9A4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Scientist2
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Man7: ; 850A9C8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Man7
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_AquaMemberM: ; 850A9EC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_AquaMemberM
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_AquaMemberF: ; 850AA10
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_AquaMemberF
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MagmaMemberM: ; 850AA34
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MagmaMemberM
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MagmaMemberF: ; 850AA58
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MagmaMemberF
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Sidney: ; 850AA7C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Sidney
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Phoebe: ; 850AAA0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Phoebe
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Glacia: ; 850AAC4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Glacia
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Drake: ; 850AAE8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Drake
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Roxanne: ; 850AB0C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Roxanne
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Brawly: ; 850AB30
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Brawly
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Wattson: ; 850AB54
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Wattson
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Flannery: ; 850AB78
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Flannery
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Norman: ; 850AB9C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Norman
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Winona: ; 850ABC0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Winona
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Liza: ; 850ABE4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Liza
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Tate: ; 850AC08
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Tate
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Wallace: ; 850AC2C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Wallace
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Steven: ; 850AC50
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Steven
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Wally: ; 850AC74
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Wally
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RubySapphireLittleBoy: ; 850AC98
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_RubySapphireLittleBoy
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BrendanFishing: ; 850ACBC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Fishing
	.4byte gFieldObjectPicTable_BrendanFishing
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MayFishing: ; 850ACE0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Fishing
	.4byte gFieldObjectPicTable_MayFishing
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_HotSpringsOldWoman: ; 850AD04
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_HotSpringsOldWoman
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_SSTidal: ; 850AD28
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1114 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 1920 ; image size
	.2byte 96 ; width
	.2byte 40 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_8x8
	.4byte gFieldObjectSpriteOamTables_SSTidal
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_SSTidal
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_SubmarineShadow: ; 850AD4C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x111B ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 1408 ; image size
	.2byte 88 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_8x8
	.4byte gFieldObjectSpriteOamTables_SubmarineShadow
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_SubmarineShadow
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_PichuDoll: ; 850AD70
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_PichuDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_PikachuDoll: ; 850AD94
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_PikachuDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MarillDoll: ; 850ADB8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_MarillDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_TogepiDoll: ; 850ADDC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_TogepiDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_CyndaquilDoll: ; 850AE00
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_CyndaquilDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_ChikoritaDoll: ; 850AE24
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_ChikoritaDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_TotodileDoll: ; 850AE48
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_TotodileDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_JigglypuffDoll: ; 850AE6C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_JigglypuffDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MeowthDoll: ; 850AE90
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_MeowthDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_ClefairyDoll: ; 850AEB4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_ClefairyDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_DittoDoll: ; 850AED8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_DittoDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_SmoochumDoll: ; 850AEFC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_SmoochumDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_TreeckoDoll: ; 850AF20
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_TreeckoDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_TorchicDoll: ; 850AF44
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_TorchicDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MudkipDoll: ; 850AF68
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_MudkipDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_DuskullDoll: ; 850AF8C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_DuskullDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_WynautDoll: ; 850AFB0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_WynautDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BaltoyDoll: ; 850AFD4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BaltoyDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_KecleonDoll: ; 850AFF8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_KecleonDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_AzurillDoll: ; 850B01C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_AzurillDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_SkittyDoll: ; 850B040
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_SkittyDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_SwabluDoll: ; 850B064
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_SwabluDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_GulpinDoll: ; 850B088
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_GulpinDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_LotadDoll: ; 850B0AC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_LotadDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_SeedotDoll: ; 850B0D0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_SeedotDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_PikaCushion: ; 850B0F4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_PikaCushion
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RoundCushion: ; 850B118
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_RoundCushion
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_KissCushion: ; 850B13C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_KissCushion
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_ZigzagCushion: ; 850B160
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_ZigzagCushion
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_SpinCushion: ; 850B184
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_SpinCushion
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_DiamondCushion: ; 850B1A8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_DiamondCushion
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BallCushion: ; 850B1CC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BallCushion
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_GrassCushion: ; 850B1F0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_GrassCushion
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_FireCushion: ; 850B214
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_FireCushion
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_WaterCushion: ; 850B238
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_WaterCushion
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BigSnorlaxDoll: ; 850B25C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BigSnorlaxDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BigRhydonDoll: ; 850B280
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BigRhydonDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BigLaprasDoll: ; 850B2A4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BigLaprasDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BigVenusaurDoll: ; 850B2C8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BigVenusaurDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BigCharizardDoll: ; 850B2EC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BigCharizardDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BigBlastoiseDoll: ; 850B310
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BigBlastoiseDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BigWailmerDoll: ; 850B334
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BigWailmerDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BigRegirockDoll: ; 850B358
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BigRegirockDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BigRegiceDoll: ; 850B37C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BigRegiceDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BigRegisteelDoll: ; 850B3A0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BigRegisteelDoll
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Latias: ; 850B3C4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_LatiasLatios
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Latios: ; 850B3E8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_LatiasLatios
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Boy5: ; 850B40C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Boy5
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_ContestOldMan: ; 850B430
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_ContestOldMan
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BrendanWatering: ; 850B454
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_BrendanWatering
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MayWatering: ; 850B478
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 0 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MayWatering
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BrendanDecorating: ; 850B49C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1100 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BrendanDecorating
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MayDecorating: ; 850B4C0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_MayDecorating
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Archie: ; 850B4E4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Archie
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Maxie: ; 850B508
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Maxie
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Kyogre1: ; 850B52C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_KyogreFront
	.4byte gFieldObjectRotScalAnimTable_KyogreGroudon

	.align 2, 0

gFieldObjectGraphicsInfo_Groudon1: ; 850B550
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_GroudonFront
	.4byte gFieldObjectRotScalAnimTable_KyogreGroudon

	.align 2, 0

gFieldObjectGraphicsInfo_Kyogre3: ; 850B574
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_KyogreSide
	.4byte gFieldObjectRotScalAnimTable_KyogreGroudon

	.align 2, 0

gFieldObjectGraphicsInfo_Groudon3: ; 850B598
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Groudon3
	.4byte gFieldObjectPicTable_GroudonSide
	.4byte gFieldObjectRotScalAnimTable_KyogreGroudon

	.align 2, 0

gFieldObjectGraphicsInfo_Fossil: ; 850B5BC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_S << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_NONE
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_Fossil
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Regirock: ; 850B5E0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Regi
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Regice: ; 850B604
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Regi
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Registeel: ; 850B628
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Regi
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Skitty: ; 850B64C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Skitty
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Kecleon1: ; 850B670
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Kecleon
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Kyogre2: ; 850B694
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1116 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_KyogreFront
	.4byte gFieldObjectRotScalAnimTable_KyogreGroudon

	.align 2, 0

gFieldObjectGraphicsInfo_Groudon2: ; 850B6B8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1118 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_GroudonFront
	.4byte gFieldObjectRotScalAnimTable_KyogreGroudon

	.align 2, 0

gFieldObjectGraphicsInfo_Rayquaza2: ; 850B6DC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 2048 ; image size
	.2byte 64 ; width
	.2byte 64 ; height
	.byte F_DISABLE_REFLECTION_PALETTE_LOAD | (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_64x64
	.4byte gFieldObjectSpriteOamTables_64x64
	.4byte gFieldObjectImageAnimTable_Rayquaza2
	.4byte gFieldObjectPicTable_Rayquaza
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Zigzagoon: ; 850B700
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Zigzagoon
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Pikachu: ; 850B724
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Pikachu
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Azumarill: ; 850B748
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Azumarill
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Wingull: ; 850B76C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Wingull
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Kecleon2: ; 850B790
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Kecleon
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_TuberMSwimming: ; 850B7B4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1104 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 3 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_TuberMSwimming
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Azurill: ; 850B7D8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 128 ; image size
	.2byte 16 ; width
	.2byte 16 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x16
	.4byte gFieldObjectSpriteOamTables_16x16
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Azurill
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Mom: ; 850B7FC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Mom
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_LinkBrendan: ; 850B820
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_BrendanMayNormal
	.4byte gFieldObjectPicTable_BrendanNormal
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_LinkMay: ; 850B844
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1110 ; palette tag
	.2byte 0x1102 ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_BrendanMayNormal
	.4byte gFieldObjectPicTable_MayNormal
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Juan: ; 850B868
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Juan
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Scott: ; 850B88C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Scott
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_MysteryEventDeliveryman: ; 850B8B0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_MysteryEventDeliveryman
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Statue: ; 850B8D4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_Statue
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Kirlia: ; 850B8F8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_S << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Kirlia
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Dusclops: ; 850B91C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Dusclops
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_UnionRoomAttendant: ; 850B940
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_UnionRoomAttendant
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Red: ; 850B964
	.2byte 0xFFFF ; tiles tag
	.2byte 0x111D ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Red
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Leaf: ; 850B988
	.2byte 0xFFFF ; tiles tag
	.2byte 0x111D ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Leaf
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Sudowoodo: ; 850B9AC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Sudowoodo
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Mew: ; 850B9D0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Mew
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Deoxys: ; 850B9F4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x111E ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Deoxys
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_BirthIslandStone: ; 850BA18
	.2byte 0xFFFF ; tiles tag
	.2byte 0x111F ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte F_INANIMATE | (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Inanimate
	.4byte gFieldObjectPicTable_BirthIslandStone
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Anabel: ; 850BA3C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Anabel
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Tucker: ; 850BA60
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Tucker
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Greta: ; 850BA84
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Greta
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Spenser: ; 850BAA8
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1103 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 2 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Spenser
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Noland: ; 850BACC
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Noland
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Lucy: ; 850BAF0
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1106 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 5 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Lucy
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Brandon: ; 850BB14
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1105 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 4 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Brandon
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RubySapphireBrendan: ; 850BB38
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1122 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_RubySapphireBrendan
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_RubySapphireMay: ; 850BB5C
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1123 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 256 ; image size
	.2byte 16 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_16x32
	.4byte gFieldObjectSpriteOamTables_16x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_RubySapphireMay
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_Lugia: ; 850BB80
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1121 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_Standard
	.4byte gFieldObjectPicTable_Lugia
	.4byte gDummyObjectRotScalAnimTable

	.align 2, 0

gFieldObjectGraphicsInfo_HoOh: ; 850BBA4
	.2byte 0xFFFF ; tiles tag
	.2byte 0x1120 ; palette tag
	.2byte 0x11FF ; palette tag 2
	.2byte 512 ; image size
	.2byte 32 ; width
	.2byte 32 ; height
	.byte (SHADOW_SIZE_M << 4) | 10 ; flags, shadow size, palette slot
	.byte TRACKS_FOOT
	.2byte 0 ; padding
	.4byte gFieldObjectBaseOam_32x32
	.4byte gFieldObjectSpriteOamTables_32x32
	.4byte gFieldObjectImageAnimTable_HoOh
	.4byte gFieldObjectPicTable_HoOh
	.4byte gDummyObjectRotScalAnimTable
