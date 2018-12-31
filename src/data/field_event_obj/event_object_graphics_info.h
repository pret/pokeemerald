#define EVENT_OBJ_16x16(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_##name = { \
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
    .anims = gEventObjectImageAnimTable_##animTable,\
    .images = imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_16x32(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_##name = { \
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
    .anims = gEventObjectImageAnimTable_##animTable,\
    .images = imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_32x32(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_##name = { \
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
    .anims = gEventObjectImageAnimTable_##animTable,\
    .images = imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_64x64(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_##name = { \
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
    .anims = gEventObjectImageAnimTable_##animTable,\
    .images = imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_SPECIAL(name, tag1, tag2, frameSize, frameWidth, frameHeight, slot, shadow, isInanimate, disableReflection, tracksType, oamTable, subsprite, animTable, imageTable, affineAnim) const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_##name = { \
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
    .anims = gEventObjectImageAnimTable_##animTable,\
    .images = imageTable,\
    .affineAnims = affineAnim,\
}

EVENT_OBJ_SPECIAL(BrendanNormal, EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10, 512, 16, 32, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_16x32, gEventObjectSpriteOamTables_16x32, BrendanMayNormal, gEventObjectPicTable_BrendanNormal, gDummySpriteAffineAnimTable); //size 512 rather than 256
EVENT_OBJ_32x32(BrendanMachBike,  EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, Standard, gEventObjectPicTable_BrendanMachBike);
EVENT_OBJ_32x32(BrendanAcroBike,  EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, gEventObjectPicTable_BrendanAcroBike);
EVENT_OBJ_32x32(BrendanSurfing,   EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_NONE, 0, SHADOW_SIZE_M, FALSE, TRUE,  TRACKS_FOOT,      Surfing, gEventObjectPicTable_BrendanSurfing);
EVENT_OBJ_32x32(BrendanFieldMove, EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT,      FieldMove, gEventObjectPicTable_BrendanFieldMove);

EVENT_OBJ_32x32(QuintyPlump, EVENT_OBJ_PAL_TAG_12, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_L, FALSE, FALSE, TRACKS_FOOT, QuintyPlump, gEventObjectPicTable_QuintyPlump);
EVENT_OBJ_16x16(NinjaBoy,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_NinjaBoy);
EVENT_OBJ_16x32(Twin,        EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Twin);
EVENT_OBJ_16x32(Boy1,        EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Boy1);
EVENT_OBJ_16x32(Girl1,       EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Girl1);
EVENT_OBJ_16x32(Boy2,        EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Boy2);
EVENT_OBJ_16x32(Girl2,       EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Girl2);
EVENT_OBJ_16x16(LittleBoy,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_LittleBoy);
EVENT_OBJ_16x16(LittleGirl,  EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_LittleGirl);
EVENT_OBJ_16x32(Boy3,        EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Boy3);
EVENT_OBJ_16x32(Girl3,       EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Girl3);
EVENT_OBJ_16x32(RichBoy,     EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_RichBoy);
EVENT_OBJ_16x32(Woman1,      EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Woman1);
EVENT_OBJ_16x32(FatMan,      EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_FatMan);
EVENT_OBJ_16x32(PokefanF,    EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_PokefanF);
EVENT_OBJ_16x32(Man1,        EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Man1);
EVENT_OBJ_16x32(Woman2,      EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Woman2);
EVENT_OBJ_16x32(ExpertM,     EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_ExpertM);
EVENT_OBJ_16x32(ExpertF,     EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_ExpertF);
EVENT_OBJ_16x32(Man2,        EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Man2);
EVENT_OBJ_16x32(Woman3,      EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Woman3);
EVENT_OBJ_16x32(PokefanM,    EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_PokefanM);
EVENT_OBJ_16x32(Woman4,      EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Woman4);
EVENT_OBJ_16x32(Cook,        EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Cook);
EVENT_OBJ_16x32(LinkReceptionist, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_LinkReceptionist);
EVENT_OBJ_16x32(OldMan,      EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_OldMan);
EVENT_OBJ_16x32(OldWoman,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_OldWoman);
EVENT_OBJ_16x32(Camper,      EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Camper);
EVENT_OBJ_16x32(Picnicker,   EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Picnicker);
EVENT_OBJ_16x32(Man3,        EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Man3);
EVENT_OBJ_16x32(Woman5,      EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Woman5);
EVENT_OBJ_16x32(Youngster,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Youngster);
EVENT_OBJ_16x32(BugCatcher,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_BugCatcher);
EVENT_OBJ_16x32(PsychicM,    EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_PsychicM);
EVENT_OBJ_16x32(SchoolKidM,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_SchoolKidM);
EVENT_OBJ_16x32(Maniac,      EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Maniac);
EVENT_OBJ_16x32(HexManiac,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_HexManiac);
EVENT_OBJ_64x64(Rayquaza1,   EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Standard, gEventObjectPicTable_RayquazaStill);
EVENT_OBJ_16x32(SwimmerM,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_SwimmerM);
EVENT_OBJ_16x32(SwimmerF,    EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_SwimmerF);
EVENT_OBJ_16x32(BlackBelt,   EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_BlackBelt);
EVENT_OBJ_16x32(Beauty,      EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Beauty);
EVENT_OBJ_16x32(Scientist1,  EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Scientist1);
EVENT_OBJ_16x32(Lass,        EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Lass);
EVENT_OBJ_16x32(Gentleman,   EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Gentleman);
EVENT_OBJ_16x32(Sailor,      EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Sailor);
EVENT_OBJ_16x32(Fisherman,   EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Fisherman);
EVENT_OBJ_16x32(RunningTriathleteM, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_RunningTriathleteM);
EVENT_OBJ_16x32(RunningTriathleteF, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_RunningTriathleteF);
EVENT_OBJ_16x16(TuberF,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_TuberF);
EVENT_OBJ_16x16(TuberM,     EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_TuberM);
EVENT_OBJ_16x32(Hiker,      EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Hiker);
EVENT_OBJ_32x32(CyclingTriathleteM, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, gEventObjectPicTable_CyclingTriathleteM);
EVENT_OBJ_32x32(CyclingTriathleteF, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, gEventObjectPicTable_CyclingTriathleteF);
EVENT_OBJ_16x32(Nurse,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Nurse, gEventObjectPicTable_Nurse);

EVENT_OBJ_16x16(ItemBall, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_ItemBall);
EVENT_OBJ_SPECIAL(BerryTree, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 256, 16, 16, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_16x16, NULL, BerryTree, gEventObjectPicTable_PechaBerryTree, gDummySpriteAffineAnimTable);
EVENT_OBJ_SPECIAL(BerryTreeEarlyStages, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 256, 16, 16, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_16x16, gEventObjectSpriteOamTables_16x16, BerryTree, gEventObjectPicTable_PechaBerryTree, gDummySpriteAffineAnimTable);
EVENT_OBJ_16x32(BerryTreeLateStages, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, BerryTree, gEventObjectPicTable_PechaBerryTree);
EVENT_OBJ_16x32(ProfBirch, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_ProfBirch);
EVENT_OBJ_16x32(Man4,      EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Man4);
EVENT_OBJ_16x32(Man5,      EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Man5);
EVENT_OBJ_16x32(ReporterM, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_ReporterM);
EVENT_OBJ_16x32(ReporterF, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_ReporterF);

EVENT_OBJ_16x32(Bard,        EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MauvilleOldMan1);
EVENT_OBJ_16x32(Hipster,     EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MauvilleOldMan1);
EVENT_OBJ_16x32(Trader,      EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MauvilleOldMan1);
EVENT_OBJ_16x32(Storyteller, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MauvilleOldMan2);
EVENT_OBJ_16x32(Giddy,       EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MauvilleOldMan2);
EVENT_OBJ_16x32(UnusedMauvilleOldMan1, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MauvilleOldMan2);
EVENT_OBJ_16x32(UnusedMauvilleOldMan2, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MauvilleOldMan2);

EVENT_OBJ_16x16(UnusedNatuDoll, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_UnusedNatuDoll);
EVENT_OBJ_16x16(UnusedMagnemiteDoll, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_UnusedMagnemiteDoll);
EVENT_OBJ_16x16(UnusedSquirtleDoll, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_UnusedSquirtleDoll);
EVENT_OBJ_16x16(UnusedWooperDoll, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_UnusedWooperDoll);
EVENT_OBJ_16x16(UnusedPikachuDoll, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_UnusedPikachuDoll);
EVENT_OBJ_16x16(UnusedPorygon2Doll, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_UnusedPorygon2Doll);

EVENT_OBJ_16x16(CuttableTree, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, CuttableTree, gEventObjectPicTable_CuttableTree);
EVENT_OBJ_16x32(MartEmployee, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MartEmployee);
EVENT_OBJ_16x32(RooftopSaleWoman, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_RooftopSaleWoman);
EVENT_OBJ_16x32(Teala, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Teala);
EVENT_OBJ_16x16(BreakableRock, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, BreakableRock, gEventObjectPicTable_BreakableRock);
EVENT_OBJ_16x16(PushableBoulder, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_PushableBoulder);
EVENT_OBJ_32x32(MrBrineysBoat, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, Standard, gEventObjectPicTable_MrBrineysBoat);
// May
EVENT_OBJ_SPECIAL(MayNormal, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 512, 16, 32, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_16x32, gEventObjectSpriteOamTables_16x32, BrendanMayNormal, gEventObjectPicTable_MayNormal, gDummySpriteAffineAnimTable);
EVENT_OBJ_32x32(MayMachBike, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, Standard, gEventObjectPicTable_MayMachBike);
EVENT_OBJ_32x32(MayAcroBike, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, gEventObjectPicTable_MayAcroBike);
EVENT_OBJ_32x32(MaySurfing, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_NONE, 0, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Surfing, gEventObjectPicTable_MaySurfing);
EVENT_OBJ_32x32(MayFieldMove, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, FieldMove, gEventObjectPicTable_MayFieldMove);

EVENT_OBJ_SPECIAL(Truck, EVENT_OBJ_PAL_TAG_14, EVENT_OBJ_PAL_TAG_NONE, 1152, 48, 48, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_Truck, Inanimate, gEventObjectPicTable_Truck, gDummySpriteAffineAnimTable);
EVENT_OBJ_32x32(VigorothCarryingBox, EVENT_OBJ_PAL_TAG_15, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_VigorothCarryingBox);
EVENT_OBJ_32x32(VigorothFacingAway, EVENT_OBJ_PAL_TAG_15, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_VigorothFacingAway);
EVENT_OBJ_16x16(BirchsBag, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BirchsBag);
EVENT_OBJ_32x32(EnemyZigzagoon, EVENT_OBJ_PAL_TAG_16, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_EnemyZigzagoon);
EVENT_OBJ_32x32(Poochyena, EVENT_OBJ_PAL_TAG_27, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Poochyena);
EVENT_OBJ_16x32(Artist, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Artist);
// Rivals
EVENT_OBJ_16x32(RivalBrendanNormal,    EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, BrendanMayNormal, gEventObjectPicTable_BrendanNormal);
EVENT_OBJ_32x32(RivalBrendanMachBike,  EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, Standard, gEventObjectPicTable_BrendanMachBike);
EVENT_OBJ_32x32(RivalBrendanAcroBike,  EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, gEventObjectPicTable_BrendanAcroBike);
EVENT_OBJ_32x32(RivalBrendanSurfing,   EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Surfing, gEventObjectPicTable_BrendanSurfing);
EVENT_OBJ_32x32(RivalBrendanFieldMove, EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, FieldMove, gEventObjectPicTable_BrendanFieldMove);
EVENT_OBJ_16x32(RivalMayNormal,    EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, BrendanMayNormal, gEventObjectPicTable_MayNormal);
EVENT_OBJ_32x32(RivalMayMachBike,  EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, Standard, gEventObjectPicTable_MayMachBike);
EVENT_OBJ_32x32(RivalMayAcroBike,  EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, gEventObjectPicTable_MayAcroBike);
EVENT_OBJ_32x32(RivalMaySurfing,   EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Surfing, gEventObjectPicTable_MaySurfing);
EVENT_OBJ_32x32(RivalMayFieldMove, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, FieldMove, gEventObjectPicTable_MayFieldMove);

EVENT_OBJ_16x32(Cameraman, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Cameraman);
EVENT_OBJ_32x32(BrendanUnderwater, EVENT_OBJ_PAL_TAG_11, EVENT_OBJ_PAL_TAG_NONE, 0, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Standard, gEventObjectPicTable_BrendanUnderwater);
EVENT_OBJ_32x32(MayUnderwater, EVENT_OBJ_PAL_TAG_11, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Standard, gEventObjectPicTable_MayUnderwater);
EVENT_OBJ_16x16(MovingBox, EVENT_OBJ_PAL_TAG_19, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_MovingBox);
EVENT_OBJ_64x64(CableCar, EVENT_OBJ_PAL_TAG_20, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_CableCar);
EVENT_OBJ_16x32(Scientist2, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Scientist2);
EVENT_OBJ_16x32(DevonEmployee, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_DevonEmployee);
EVENT_OBJ_16x32(AquaMemberM, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_AquaMemberM);
EVENT_OBJ_16x32(AquaMemberF, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_AquaMemberF);
EVENT_OBJ_16x32(MagmaMemberM, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MagmaMemberM);
EVENT_OBJ_16x32(MagmaMemberF, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MagmaMemberF);
// Gym leaders + Elite four
EVENT_OBJ_16x32(Sidney, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Sidney);
EVENT_OBJ_16x32(Phoebe, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Phoebe);
EVENT_OBJ_16x32(Glacia, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Glacia);
EVENT_OBJ_16x32(Drake, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Drake);
EVENT_OBJ_16x32(Roxanne, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Roxanne);
EVENT_OBJ_16x32(Brawly, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Brawly);
EVENT_OBJ_16x32(Wattson, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Wattson);
EVENT_OBJ_16x32(Flannery, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Flannery);
EVENT_OBJ_16x32(Norman, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Norman);
EVENT_OBJ_16x32(Winona, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Winona);
EVENT_OBJ_16x32(Liza, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Liza);
EVENT_OBJ_16x32(Tate, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Tate);
EVENT_OBJ_16x32(Wallace, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Wallace);
EVENT_OBJ_16x32(Steven, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Steven);

EVENT_OBJ_16x32(Wally, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Wally);
EVENT_OBJ_16x16(RubySapphireLittleBoy, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_RubySapphireLittleBoy);
EVENT_OBJ_32x32(BrendanFishing, EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Fishing, gEventObjectPicTable_BrendanFishing);
EVENT_OBJ_32x32(MayFishing, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Fishing, gEventObjectPicTable_MayFishing);
EVENT_OBJ_16x32(HotSpringsOldWoman, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_HotSpringsOldWoman);

EVENT_OBJ_SPECIAL(SSTidal,         EVENT_OBJ_PAL_TAG_21, EVENT_OBJ_PAL_TAG_NONE, 1920, 96, 40, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_8x8, gEventObjectSpriteOamTables_SSTidal,         Standard, gEventObjectPicTable_SSTidal, gDummySpriteAffineAnimTable);
EVENT_OBJ_SPECIAL(SubmarineShadow, EVENT_OBJ_PAL_TAG_26, EVENT_OBJ_PAL_TAG_NONE, 1408, 88, 32, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_8x8, gEventObjectSpriteOamTables_SubmarineShadow, Standard, gEventObjectPicTable_SubmarineShadow, gDummySpriteAffineAnimTable);
// Dolls + Cushions
EVENT_OBJ_16x16(PichuDoll,      EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_PichuDoll);
EVENT_OBJ_16x16(PikachuDoll,    EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_PikachuDoll);
EVENT_OBJ_16x16(MarillDoll,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_MarillDoll);
EVENT_OBJ_16x16(TogepiDoll,     EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_TogepiDoll);
EVENT_OBJ_16x16(CyndaquilDoll,  EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_CyndaquilDoll);
EVENT_OBJ_16x16(ChikoritaDoll,  EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_ChikoritaDoll);
EVENT_OBJ_16x16(TotodileDoll,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_TotodileDoll);
EVENT_OBJ_16x16(JigglypuffDoll, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_JigglypuffDoll);
EVENT_OBJ_16x16(MeowthDoll,     EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_MeowthDoll);
EVENT_OBJ_16x16(ClefairyDoll,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_ClefairyDoll);
EVENT_OBJ_16x16(DittoDoll,      EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_DittoDoll);
EVENT_OBJ_16x16(SmoochumDoll,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_SmoochumDoll);
EVENT_OBJ_16x16(TreeckoDoll,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_TreeckoDoll);
EVENT_OBJ_16x16(TorchicDoll,    EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_TorchicDoll);
EVENT_OBJ_16x16(MudkipDoll,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_MudkipDoll);
EVENT_OBJ_16x16(DuskullDoll,    EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_DuskullDoll);
EVENT_OBJ_16x16(WynautDoll,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_WynautDoll);
EVENT_OBJ_16x16(BaltoyDoll,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BaltoyDoll);
EVENT_OBJ_16x16(KecleonDoll,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_KecleonDoll);
EVENT_OBJ_16x16(AzurillDoll,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_AzurillDoll);
EVENT_OBJ_16x16(SkittyDoll,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_SkittyDoll);
EVENT_OBJ_16x16(SwabluDoll,     EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_SwabluDoll);
EVENT_OBJ_16x16(GulpinDoll,     EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_GulpinDoll);
EVENT_OBJ_16x16(LotadDoll,      EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_LotadDoll);
EVENT_OBJ_16x16(SeedotDoll,     EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_SeedotDoll);
EVENT_OBJ_16x16(PikaCushion,    EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_PikaCushion);
EVENT_OBJ_16x16(RoundCushion,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_RoundCushion);
EVENT_OBJ_16x16(KissCushion,    EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_KissCushion);
EVENT_OBJ_16x16(ZigzagCushion,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_ZigzagCushion);
EVENT_OBJ_16x16(SpinCushion,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_SpinCushion);
EVENT_OBJ_16x16(DiamondCushion, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_DiamondCushion);
EVENT_OBJ_16x16(BallCushion,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BallCushion);
EVENT_OBJ_16x16(GrassCushion,   EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_GrassCushion);
EVENT_OBJ_16x16(FireCushion,    EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_FireCushion);
EVENT_OBJ_16x16(WaterCushion,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_WaterCushion);

EVENT_OBJ_32x32(BigSnorlaxDoll,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BigSnorlaxDoll);
EVENT_OBJ_32x32(BigRhydonDoll,    EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BigRhydonDoll);
EVENT_OBJ_32x32(BigLaprasDoll,    EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BigLaprasDoll);
EVENT_OBJ_32x32(BigVenusaurDoll,  EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BigVenusaurDoll);
EVENT_OBJ_32x32(BigCharizardDoll, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BigCharizardDoll);
EVENT_OBJ_32x32(BigBlastoiseDoll, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BigBlastoiseDoll);
EVENT_OBJ_32x32(BigWailmerDoll,   EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BigWailmerDoll);
EVENT_OBJ_32x32(BigRegirockDoll,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BigRegirockDoll);
EVENT_OBJ_32x32(BigRegiceDoll,    EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BigRegiceDoll);
EVENT_OBJ_32x32(BigRegisteelDoll, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_BigRegisteelDoll);

EVENT_OBJ_32x32(Latias, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, Standard, gEventObjectPicTable_LatiasLatios);
EVENT_OBJ_32x32(Latios, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, Standard, gEventObjectPicTable_LatiasLatios);
EVENT_OBJ_16x32(GameboyKid, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_GameboyKid);
EVENT_OBJ_16x32(ContestJudge, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_ContestJudge);
EVENT_OBJ_32x32(BrendanWatering, EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_BrendanWatering);
EVENT_OBJ_32x32(MayWatering, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MayWatering);
EVENT_OBJ_16x32(BrendanDecorating, EVENT_OBJ_PAL_TAG_8, EVENT_OBJ_PAL_TAG_10, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Inanimate, gEventObjectPicTable_BrendanDecorating);
EVENT_OBJ_16x32(MayDecorating, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Inanimate, gEventObjectPicTable_MayDecorating);
EVENT_OBJ_16x32(Archie, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Archie);
EVENT_OBJ_16x32(Maxie, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Maxie);

EVENT_OBJ_SPECIAL(Kyogre1,  EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Standard, gEventObjectPicTable_KyogreFront, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(Groudon1, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Standard, gEventObjectPicTable_GroudonFront, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(Kyogre3,  EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Standard, gEventObjectPicTable_KyogreSide, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(Groudon3, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Groudon3, gEventObjectPicTable_GroudonSide, gEventObjectRotScalAnimTable_KyogreGroudon);

EVENT_OBJ_16x16(Fossil, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, gEventObjectPicTable_Fossil);
EVENT_OBJ_32x32(Regirock, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Regi);
EVENT_OBJ_32x32(Regice, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Regi);
EVENT_OBJ_32x32(Registeel, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Regi);
EVENT_OBJ_16x16(Skitty, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Skitty);
EVENT_OBJ_16x16(Kecleon1, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Kecleon);

EVENT_OBJ_SPECIAL(Kyogre2,  EVENT_OBJ_PAL_TAG_22, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Standard, gEventObjectPicTable_KyogreFront, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(Groudon2, EVENT_OBJ_PAL_TAG_24, EVENT_OBJ_PAL_TAG_NONE, 512, 32, 32, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Standard, gEventObjectPicTable_GroudonFront, gEventObjectRotScalAnimTable_KyogreGroudon);

EVENT_OBJ_64x64(Rayquaza2, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Rayquaza2, gEventObjectPicTable_Rayquaza);
EVENT_OBJ_16x16(Zigzagoon, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Zigzagoon);
EVENT_OBJ_16x16(Pikachu, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Pikachu);
EVENT_OBJ_16x16(Azumarill, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Azumarill);
EVENT_OBJ_16x16(Wingull, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Wingull);
EVENT_OBJ_16x16(Kecleon2, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_10, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Kecleon);
EVENT_OBJ_16x16(TuberMSwimming, EVENT_OBJ_PAL_TAG_1, EVENT_OBJ_PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_TuberMSwimming);
EVENT_OBJ_16x16(Azurill, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Azurill);
EVENT_OBJ_16x32(Mom, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Mom);
EVENT_OBJ_16x32(LinkBrendan, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, BrendanMayNormal, gEventObjectPicTable_BrendanNormal);
EVENT_OBJ_16x32(LinkMay, EVENT_OBJ_PAL_TAG_17, EVENT_OBJ_PAL_TAG_10, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, BrendanMayNormal, gEventObjectPicTable_MayNormal);
EVENT_OBJ_16x32(Juan, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Juan);
EVENT_OBJ_16x32(Scott, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Scott);
EVENT_OBJ_16x32(MysteryEventDeliveryman, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_MysteryEventDeliveryman);
EVENT_OBJ_16x32(Statue, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Inanimate, gEventObjectPicTable_Statue);
EVENT_OBJ_16x32(Kirlia, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_S, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Kirlia);
EVENT_OBJ_16x32(Dusclops, EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Dusclops);
EVENT_OBJ_16x32(UnionRoomAttendant, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_UnionRoomAttendant);
EVENT_OBJ_16x32(Red, EVENT_OBJ_PAL_TAG_28, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Red);
EVENT_OBJ_16x32(Leaf, EVENT_OBJ_PAL_TAG_28, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Leaf);
EVENT_OBJ_16x32(Sudowoodo, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Sudowoodo);
EVENT_OBJ_16x32(Mew, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Mew);
EVENT_OBJ_32x32(Deoxys, EVENT_OBJ_PAL_TAG_29, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Deoxys);
EVENT_OBJ_32x32(BirthIslandStone, EVENT_OBJ_PAL_TAG_30, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Inanimate, gEventObjectPicTable_BirthIslandStone);
// Frontier Brains
EVENT_OBJ_16x32(Anabel,  EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Anabel);
EVENT_OBJ_16x32(Tucker,  EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Tucker);
EVENT_OBJ_16x32(Greta,   EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Greta);
EVENT_OBJ_16x32(Spenser, EVENT_OBJ_PAL_TAG_0, EVENT_OBJ_PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Spenser);
EVENT_OBJ_16x32(Noland,  EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Noland);
EVENT_OBJ_16x32(Lucy,    EVENT_OBJ_PAL_TAG_3, EVENT_OBJ_PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Lucy);
EVENT_OBJ_16x32(Brandon, EVENT_OBJ_PAL_TAG_2, EVENT_OBJ_PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Brandon);

EVENT_OBJ_16x32(RubySapphireBrendan, EVENT_OBJ_PAL_TAG_33, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_RubySapphireBrendan);
EVENT_OBJ_16x32(RubySapphireMay, EVENT_OBJ_PAL_TAG_34, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_RubySapphireMay);
EVENT_OBJ_32x32(Lugia, EVENT_OBJ_PAL_TAG_32, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, gEventObjectPicTable_Lugia);
EVENT_OBJ_32x32(HoOh, EVENT_OBJ_PAL_TAG_31, EVENT_OBJ_PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, HoOh, gEventObjectPicTable_HoOh);
