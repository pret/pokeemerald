#ifndef GUARD_EVENT_OBJECT_GRAPHICS_INFO_H
#define GUARD_EVENT_OBJECT_GRAPHICS_INFO_H

#define EVENT_OBJ_16x16(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo name = { \
    .tileTag = 0xFFFF,\
    .paletteTag1 = tag1,\
    .paletteTag2 = tag2,\
    .size = 128,\
    .width = 16,\
    .height = 16,\
    .paletteSlot = slot,\
    .shadowSize = shadow,\
    .inanimate = isInanimate,\
    .disableReflectionPaletteLoad = disableReflection,\
    .tracks = tracksType,\
    .oam = &gEventObjectBaseOam_16x16,\
    .subspriteTables = gEventObjectSpriteOamTables_16x16,\
    .anims = animTable,\
    .images = imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_16x32(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo name = { \
    .tileTag = 0xFFFF,\
    .paletteTag1 = tag1,\
    .paletteTag2 = tag2,\
    .size = 256,\
    .width = 16,\
    .height = 32,\
    .paletteSlot = slot,\
    .shadowSize = shadow,\
    .inanimate = isInanimate,\
    .disableReflectionPaletteLoad = disableReflection,\
    .tracks = tracksType,\
    .oam = &gEventObjectBaseOam_16x32,\
    .subspriteTables = gEventObjectSpriteOamTables_16x32,\
    .anims = animTable,\
    .images = imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_32x32(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo name = { \
    .tileTag = 0xFFFF,\
    .paletteTag1 = tag1,\
    .paletteTag2 = tag2,\
    .size = 512,\
    .width = 32,\
    .height = 32,\
    .paletteSlot = slot,\
    .shadowSize = shadow,\
    .inanimate = isInanimate,\
    .disableReflectionPaletteLoad = disableReflection,\
    .tracks = tracksType,\
    .oam = &gEventObjectBaseOam_32x32,\
    .subspriteTables = gEventObjectSpriteOamTables_32x32,\
    .anims = animTable,\
    .images = imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_64x64(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo name = { \
    .tileTag = 0xFFFF,\
    .paletteTag1 = tag1,\
    .paletteTag2 = tag2,\
    .size = 2048,\
    .width = 64,\
    .height = 64,\
    .paletteSlot = slot,\
    .shadowSize = shadow,\
    .inanimate = isInanimate,\
    .disableReflectionPaletteLoad = disableReflection,\
    .tracks = tracksType,\
    .oam = &gEventObjectBaseOam_64x64,\
    .subspriteTables = gEventObjectSpriteOamTables_64x64,\
    .anims = animTable,\
    .images = imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_SPECIAL(name, tag1, tag2, frameSize, frameWidth, frameHeight, slot, shadow, isInanimate, disableReflection, tracksType, oamTable, subsprite, animTable, imageTable, affineAnim) const struct EventObjectGraphicsInfo name = { \
    .tileTag = 0xFFFF,\
    .paletteTag1 = tag1,\
    .paletteTag2 = tag2,\
    .size = frameSize,\
    .width = frameWidth,\
    .height = frameHeight,\
    .paletteSlot = slot,\
    .shadowSize = shadow,\
    .inanimate = isInanimate,\
    .disableReflectionPaletteLoad = disableReflection,\
    .tracks = tracksType,\
    .oam = oamTable,\
    .subspriteTables = subsprite,\
    .anims = animTable,\
    .images = imageTable,\
    .affineAnims = affineAnim,\
}

// Could remove shadow from EVENT_OBJ_64x64() as they are all SHADOW_SIZE_M, however it's been kept for consistency.

EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_BrendanNormal,  EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10, 512, 16, 32, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_16x32, gEventObjectSpriteOamTables_16x32, gEventObjectImageAnimTable_BrendanMayNormal, gEventObjectPicTable_BrendanNormal, gDummySpriteAffineAnimTable); //size 512 rather than 256
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BrendanMachBike,  EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_BrendanMachBike);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BrendanAcroBike,  EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, gEventObjectImageAnimTable_AcroBike, gEventObjectPicTable_BrendanAcroBike);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BrendanSurfing,   EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_NONE, 0, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, gEventObjectImageAnimTable_Surfing, gEventObjectPicTable_BrendanSurfing);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BrendanFieldMove, EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_FieldMove, gEventObjectPicTable_BrendanFieldMove);

EVENT_OBJ_32x32(gEventObjectGraphicsInfo_QuintyPlump,        EVENT_OBJ_PAL_TAG_12, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_L, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_QuintyPlump, gEventObjectPicTable_QuintyPlump);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_LittleBoy1,         EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_LittleBoy1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_LittleGirl1,        EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_LittleGirl1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Boy1,               EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Boy1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Girl1,              EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Girl1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Boy2,               EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Boy2);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Girl2,              EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Girl2);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_LittleBoy2,         EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_LittleBoy2);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_LittleGirl2,        EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_LittleGirl2);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Boy3,               EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Boy3);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Girl3,              EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Girl3);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Boy4,               EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Boy4);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Woman1,             EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Woman1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_FatMan,             EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_FatMan);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Woman2,             EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Woman2);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Man1,               EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Man1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Woman3,             EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Woman3);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_OldMan1,            EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_OldMan1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_OldWoman1,          EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_OldWoman1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Man2,               EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Man2);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Woman4,             EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Woman4);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Man3,               EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Man3);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Woman5,             EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Woman5);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Cook,               EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Cook);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Woman6,             EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Woman6);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_OldMan2,            EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_OldMan2);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_OldWoman2,          EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_OldWoman2);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Camper,             EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Camper);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Picnicker,          EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Picnicker);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Man4,               EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Man4);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Woman7,             EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Woman7);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Youngster,          EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Youngster);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_BugCatcher,         EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_BugCatcher);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_PsychicM,           EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_PsychicM);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_SchoolKidM,         EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_SchoolKidM);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Maniac,             EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Maniac);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_HexManiac,          EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_HexManiac);
EVENT_OBJ_64x64(gEventObjectGraphicsInfo_Rayquaza1,          EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_RayquazaStill);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_SwimmerM,           EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_SwimmerM);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_SwimmerF,           EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_SwimmerF);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_BlackBelt,          EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_BlackBelt);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Beauty,             EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Beauty);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Scientist1,         EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Scientist1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Lass,               EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Lass);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Gentleman,          EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Gentleman);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Sailor,             EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Sailor);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Fisherman,          EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Fisherman);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_RunningTriathleteM, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_RunningTriathleteM);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_RunningTriathleteF, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_RunningTriathleteF);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_TuberF,             EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_TuberF);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_TuberM,             EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_TuberM);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Hiker,              EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Hiker);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_CyclingTriathleteM, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, gEventObjectImageAnimTable_AcroBike, gEventObjectPicTable_CyclingTriathleteM);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_CyclingTriathleteF, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, gEventObjectImageAnimTable_AcroBike, gEventObjectPicTable_CyclingTriathleteF);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Nurse,              EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Nurse, gEventObjectPicTable_Nurse);

EVENT_OBJ_16x16(gEventObjectGraphicsInfo_ItemBall,               EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_ItemBall);
EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_BerryTree,            EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 256, 16, 16, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_16x16, NULL, gEventObjectImageAnimTable_BerryTree, gEventObjectPicTable_PechaBerryTree, gDummySpriteAffineAnimTable);
EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_BerryTreeEarlyStages, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 256, 16, 16, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_16x16, gEventObjectSpriteOamTables_16x16, gEventObjectImageAnimTable_BerryTree, gEventObjectPicTable_PechaBerryTree, gDummySpriteAffineAnimTable);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_BerryTreeLateStages,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2,              SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_BerryTree, gEventObjectPicTable_PechaBerryTree);

EVENT_OBJ_16x32(gEventObjectGraphicsInfo_ProfBirch, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_ProfBirch);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Man5,      EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Man5);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Man6,      EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Man6);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_ReporterM, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_ReporterM);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_ReporterF, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_ReporterF);

EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Bard,        EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MauvilleOldMan1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Hipster,     EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MauvilleOldMan1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Trader,      EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MauvilleOldMan1);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Storyteller, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MauvilleOldMan2);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Giddy,       EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MauvilleOldMan2);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_UnusedMauvilleOldMan1, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MauvilleOldMan2);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_UnusedMauvilleOldMan2, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MauvilleOldMan2);
// Unused dolls
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_UnusedNatuDoll,      EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_UnusedNatuDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_UnusedMagnemiteDoll, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_UnusedMagnemiteDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_UnusedSquirtleDoll,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_UnusedSquirtleDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_UnusedWooperDoll,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_UnusedWooperDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_UnusedPikachuDoll,   EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_UnusedPikachuDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_UnusedPorygon2Doll,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_UnusedPorygon2Doll);

EVENT_OBJ_16x16(gEventObjectGraphicsInfo_CuttableTree,     EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_CuttableTree, gEventObjectPicTable_CuttableTree);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_MartEmployee,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MartEmployee);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_RooftopSaleWoman, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_RooftopSaleWoman);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Teala,            EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Teala);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_BreakableRock,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_BreakableRock, gEventObjectPicTable_BreakableRock);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_PushableBoulder,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_PushableBoulder);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_MrBrineysBoat,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MrBrineysBoat);
// May
EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_MayNormal,  EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 512, 16, 32, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_16x32, gEventObjectSpriteOamTables_16x32, gEventObjectImageAnimTable_BrendanMayNormal, gEventObjectPicTable_MayNormal, gDummySpriteAffineAnimTable); // size 512, rather than 256
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_MayMachBike,  EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MayMachBike);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_MayAcroBike,  EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, gEventObjectImageAnimTable_AcroBike, gEventObjectPicTable_MayAcroBike);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_MaySurfing,   EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_NONE, 0, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, gEventObjectImageAnimTable_Surfing, gEventObjectPicTable_MaySurfing);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_MayFieldMove, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_FieldMove, gEventObjectPicTable_MayFieldMove);

EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_Truck, EVENT_OBJ_PAL_TAG_14, EVENT_OBJ_PAL_TAG_NONE, 1152, 48, 48, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_Truck, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_Truck, gDummySpriteAffineAnimTable);

EVENT_OBJ_32x32(gEventObjectGraphicsInfo_VigorothCarryingBox, EVENT_OBJ_PAL_TAG_15, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_VigorothCarryingBox);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_VigorothFacingAway,  EVENT_OBJ_PAL_TAG_15, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_VigorothFacingAway);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_BirchsBag,      EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BirchsBag);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_EnemyZigzagoon, EVENT_OBJ_PAL_TAG_16, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_EnemyZigzagoon);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_Poochyena,      EVENT_OBJ_PAL_TAG_27, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Poochyena);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Artist,         EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Artist);
// Rival Brendan + May
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_RivalBrendanNormal,    EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT,      gEventObjectImageAnimTable_BrendanMayNormal, gEventObjectPicTable_BrendanNormal);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_RivalBrendanMachBike,  EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, gEventObjectImageAnimTable_Standard,         gEventObjectPicTable_BrendanMachBike);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_RivalBrendanAcroBike,  EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, gEventObjectImageAnimTable_AcroBike,         gEventObjectPicTable_BrendanAcroBike);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_RivalBrendanSurfing,   EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, TRUE,  TRACKS_FOOT,      gEventObjectImageAnimTable_Surfing,          gEventObjectPicTable_BrendanSurfing);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_RivalBrendanFieldMove, EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT,      gEventObjectImageAnimTable_FieldMove,        gEventObjectPicTable_BrendanFieldMove);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_RivalMayNormal,    EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT,      gEventObjectImageAnimTable_BrendanMayNormal, gEventObjectPicTable_MayNormal);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_RivalMayMachBike,  EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, gEventObjectImageAnimTable_Standard,         gEventObjectPicTable_MayMachBike);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_RivalMayAcroBike,  EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, gEventObjectImageAnimTable_AcroBike,         gEventObjectPicTable_MayAcroBike);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_RivalMaySurfing,   EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, TRUE,  TRACKS_FOOT,      gEventObjectImageAnimTable_Surfing,          gEventObjectPicTable_MaySurfing);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_RivalMayFieldMove, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT,      gEventObjectImageAnimTable_FieldMove,        gEventObjectPicTable_MayFieldMove);

EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Cameraman, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Cameraman);

EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BrendanUnderwater, EVENT_OBJ_PAL_TAG_11, EVENT_OBJ_PAL_TAG_NONE, 0, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_BrendanUnderwater);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_MayUnderwater,     EVENT_OBJ_PAL_TAG_11, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MayUnderwater);

EVENT_OBJ_16x16(gEventObjectGraphicsInfo_MovingBox, EVENT_OBJ_PAL_TAG_19, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_MovingBox);
EVENT_OBJ_64x64(gEventObjectGraphicsInfo_CableCar,  EVENT_OBJ_PAL_TAG_20, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_CableCar);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Scientist2,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Scientist2);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Man7,         EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Man7);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_AquaMemberM,  EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_AquaMemberM);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_AquaMemberF,  EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_AquaMemberF);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_MagmaMemberM, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MagmaMemberM);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_MagmaMemberF, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MagmaMemberF);
// Gym leaders, elite four
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Sidney, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Sidney);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Phoebe, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Phoebe);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Glacia, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Glacia);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Drake,  EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Drake);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Roxanne,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Roxanne);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Brawly,   EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Brawly);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Wattson,  EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Wattson);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Flannery, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Flannery);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Norman,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Norman);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Winona,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Winona);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Liza,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Liza);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Tate,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Tate);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Wallace,  EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Wallace);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Steven,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Steven);

EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Wally,                 EVENT_OBJ_PAL_TAG_0,  EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Wally);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_RubySapphireLittleBoy, EVENT_OBJ_PAL_TAG_0,  EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_RubySapphireLittleBoy);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BrendanFishing,        EVENT_OBJ_PAL_TAG_8,  EVENT_OBJ_PAL_TAG_10,   0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Fishing, gEventObjectPicTable_BrendanFishing);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_MayFishing,            EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,   0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Fishing, gEventObjectPicTable_MayFishing);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_HotSpringsOldWoman,    EVENT_OBJ_PAL_TAG_3,  EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_HotSpringsOldWoman);
// Submarine
EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_SSTidal,         EVENT_OBJ_PAL_TAG_21, EVENT_OBJ_PAL_TAG_NONE, 1920, 96, 40, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_8x8, gEventObjectSpriteOamTables_SSTidal,         gEventObjectImageAnimTable_Standard, gEventObjectPicTable_SSTidal, gDummySpriteAffineAnimTable);
EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_SubmarineShadow, EVENT_OBJ_PAL_TAG_26, EVENT_OBJ_PAL_TAG_NONE, 1408, 88, 32, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_8x8, gEventObjectSpriteOamTables_SubmarineShadow, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_SubmarineShadow, gDummySpriteAffineAnimTable);
// Dolls + cushions
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_PichuDoll,        EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_PichuDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_PikachuDoll,      EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_PikachuDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_MarillDoll,       EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_MarillDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_TogepiDoll,       EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_TogepiDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_CyndaquilDoll,    EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_CyndaquilDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_ChikoritaDoll,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_ChikoritaDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_TotodileDoll,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_TotodileDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_JigglypuffDoll,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_JigglypuffDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_MeowthDoll,       EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_MeowthDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_ClefairyDoll,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_ClefairyDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_DittoDoll,        EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_DittoDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_SmoochumDoll,     EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_SmoochumDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_TreeckoDoll,      EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_TreeckoDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_TorchicDoll,      EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_TorchicDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_MudkipDoll,       EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_MudkipDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_DuskullDoll,      EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_DuskullDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_WynautDoll,       EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_WynautDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_BaltoyDoll,       EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BaltoyDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_KecleonDoll,      EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_KecleonDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_AzurillDoll,      EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_AzurillDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_SkittyDoll,       EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_SkittyDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_SwabluDoll,       EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_SwabluDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_GulpinDoll,       EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_GulpinDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_LotadDoll,        EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_LotadDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_SeedotDoll,       EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_SeedotDoll);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_PikaCushion,      EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_PikaCushion);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_RoundCushion,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_RoundCushion);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_KissCushion,      EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_KissCushion);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_ZigzagCushion,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_ZigzagCushion);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_SpinCushion,      EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_SpinCushion);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_DiamondCushion,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_DiamondCushion);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_BallCushion,      EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BallCushion);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_GrassCushion,     EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_GrassCushion);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_FireCushion,      EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_FireCushion);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_WaterCushion,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_WaterCushion);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BigSnorlaxDoll,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BigSnorlaxDoll);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BigRhydonDoll,    EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BigRhydonDoll);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BigLaprasDoll,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BigLaprasDoll);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BigVenusaurDoll,  EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BigVenusaurDoll);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BigCharizardDoll, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BigCharizardDoll);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BigBlastoiseDoll, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BigBlastoiseDoll);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BigWailmerDoll,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BigWailmerDoll);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BigRegirockDoll,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BigRegirockDoll);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BigRegiceDoll,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BigRegiceDoll);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BigRegisteelDoll, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BigRegisteelDoll);

EVENT_OBJ_32x32(gEventObjectGraphicsInfo_Latias, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_LatiasLatios);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_Latios, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_LatiasLatios);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Boy5,          EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Boy5);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_ContestOldMan, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_ContestOldMan);

EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BrendanWatering,   EVENT_OBJ_PAL_TAG_8,  EVENT_OBJ_PAL_TAG_10, 0,  SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard,  gEventObjectPicTable_BrendanWatering);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_MayWatering,       EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 0,  SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard,  gEventObjectPicTable_MayWatering);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_BrendanDecorating, EVENT_OBJ_PAL_TAG_8,  EVENT_OBJ_PAL_TAG_10, 10, SHADOW_SIZE_M, TRUE,  FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BrendanDecorating);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_MayDecorating,     EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 10, SHADOW_SIZE_M, TRUE,  FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_MayDecorating);

EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Archie, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Archie);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Maxie,  EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Maxie);

EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_Kyogre1,  EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_KyogreFront, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_Groudon1, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_GroudonFront, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_Kyogre3,  EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_KyogreSide, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_Groudon3, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, gEventObjectImageAnimTable_Groudon3, gEventObjectPicTable_GroudonSide, gEventObjectRotScalAnimTable_KyogreGroudon);

EVENT_OBJ_16x16(gEventObjectGraphicsInfo_Fossil,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_Fossil);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_Regirock,  EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Regi);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_Regice,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Regi);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_Registeel, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Regi);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_Skitty,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Skitty);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_Kecleon1,  EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Kecleon);

EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_Kyogre2,  EVENT_OBJ_PAL_TAG_22, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_KyogreFront, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(gEventObjectGraphicsInfo_Groudon2, EVENT_OBJ_PAL_TAG_24, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_GroudonFront, gEventObjectRotScalAnimTable_KyogreGroudon);

EVENT_OBJ_64x64(gEventObjectGraphicsInfo_Rayquaza2,   EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, gEventObjectImageAnimTable_Rayquaza2, gEventObjectPicTable_Rayquaza);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_Zigzagoon,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Zigzagoon);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_Pikachu,     EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Pikachu);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_Azumarill,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Azumarill);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_Wingull,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Wingull);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_Kecleon2,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_10, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Kecleon);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_TuberMSwimming, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_TuberMSwimming);
EVENT_OBJ_16x16(gEventObjectGraphicsInfo_Azurill,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Azurill);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Mom,         EVENT_OBJ_PAL_TAG_3,  EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Mom);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_LinkBrendan, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,  10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_BrendanMayNormal, gEventObjectPicTable_BrendanNormal);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_LinkMay,     EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,  10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_BrendanMayNormal, gEventObjectPicTable_MayNormal);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Juan,        EVENT_OBJ_PAL_TAG_3,  EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Juan);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Scott,       EVENT_OBJ_PAL_TAG_0,  EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Scott);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_MysteryEventDeliveryman, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_MysteryEventDeliveryman);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Statue,      EVENT_OBJ_PAL_TAG_3,  EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_Statue);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Kirlia,      EVENT_OBJ_PAL_TAG_2,  EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Kirlia);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Dusclops,    EVENT_OBJ_PAL_TAG_3,  EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Dusclops);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_UnionRoomAttendant, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_UnionRoomAttendant);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Red,         EVENT_OBJ_PAL_TAG_28, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Red);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Leaf,        EVENT_OBJ_PAL_TAG_28, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Leaf);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Sudowoodo,   EVENT_OBJ_PAL_TAG_2,  EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Sudowoodo);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Mew,         EVENT_OBJ_PAL_TAG_0,  EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Mew);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_Deoxys,      EVENT_OBJ_PAL_TAG_29, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Deoxys);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_BirthIslandStone, EVENT_OBJ_PAL_TAG_30, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Inanimate, gEventObjectPicTable_BirthIslandStone);
// Frontier Brains
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Anabel,  EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Anabel);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Tucker,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Tucker);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Greta,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Greta);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Spenser, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Spenser);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Noland,  EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Noland);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Lucy,    EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Lucy);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_Brandon, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Brandon);

EVENT_OBJ_16x32(gEventObjectGraphicsInfo_RubySapphireBrendan, EVENT_OBJ_PAL_TAG_33, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_RubySapphireBrendan);
EVENT_OBJ_16x32(gEventObjectGraphicsInfo_RubySapphireMay,     EVENT_OBJ_PAL_TAG_34, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_RubySapphireMay);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_Lugia, EVENT_OBJ_PAL_TAG_32, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_Standard, gEventObjectPicTable_Lugia);
EVENT_OBJ_32x32(gEventObjectGraphicsInfo_HoOh,  EVENT_OBJ_PAL_TAG_31, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, gEventObjectImageAnimTable_HoOh, gEventObjectPicTable_HoOh);

#endif //GUARD_EVENT_OBJECT_GRAPHICS_INFO_H
