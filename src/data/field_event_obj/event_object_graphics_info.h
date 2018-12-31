#define EVENT_OBJ_16x16(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_##name = { \
    .tileTag = 0xFFFF,\
    .paletteTag1 = EVENT_OBJ_##tag1,\
    .paletteTag2 = EVENT_OBJ_##tag2,\
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
    .images = gEventObjectPicTable_##imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_16x32(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_##name = { \
    .tileTag = 0xFFFF,\
    .paletteTag1 = EVENT_OBJ_##tag1,\
    .paletteTag2 = EVENT_OBJ_##tag2,\
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
    .images = gEventObjectPicTable_##imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_32x32(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_##name = { \
    .tileTag = 0xFFFF,\
    .paletteTag1 = EVENT_OBJ_##tag1,\
    .paletteTag2 = EVENT_OBJ_##tag2,\
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
    .images = gEventObjectPicTable_##imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_64x64(name, tag1, tag2, slot, shadow, isInanimate, disableReflection, tracksType, animTable, imageTable) const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_##name = { \
    .tileTag = 0xFFFF,\
    .paletteTag1 = EVENT_OBJ_##tag1,\
    .paletteTag2 = EVENT_OBJ_##tag2,\
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
    .images = gEventObjectPicTable_##imageTable,\
    .affineAnims = gDummySpriteAffineAnimTable,\
}

#define EVENT_OBJ_SPECIAL(name, tag1, tag2, frameSize, frameWidth, frameHeight, slot, shadow, isInanimate, disableReflection, tracksType, oamTable, subsprite, animTable, imageTable, affineAnim) const struct EventObjectGraphicsInfo gEventObjectGraphicsInfo_##name = { \
    .tileTag = 0xFFFF,\
    .paletteTag1 = EVENT_OBJ_##tag1,\
    .paletteTag2 = EVENT_OBJ_##tag2,\
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
    .images = gEventObjectPicTable_##imageTable,\
    .affineAnims = affineAnim,\
}

EVENT_OBJ_SPECIAL(BrendanNormal, PAL_TAG_8, PAL_TAG_10, 512, 16, 32, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_16x32, gEventObjectSpriteOamTables_16x32, BrendanMayNormal, BrendanNormal, gDummySpriteAffineAnimTable); //size 512 rather than 256
EVENT_OBJ_32x32(BrendanMachBike,  PAL_TAG_8, PAL_TAG_10,   0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, Standard, BrendanMachBike);
EVENT_OBJ_32x32(BrendanAcroBike,  PAL_TAG_8, PAL_TAG_10,   0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, BrendanAcroBike);
EVENT_OBJ_32x32(BrendanSurfing,   PAL_TAG_8, PAL_TAG_NONE, 0, SHADOW_SIZE_M, FALSE, TRUE,  TRACKS_FOOT,      Surfing, BrendanSurfing);
EVENT_OBJ_32x32(BrendanFieldMove, PAL_TAG_8, PAL_TAG_10,   0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT,      FieldMove, BrendanFieldMove);

EVENT_OBJ_32x32(QuintyPlump, PAL_TAG_12, PAL_TAG_NONE, 10, SHADOW_SIZE_L, FALSE, FALSE, TRACKS_FOOT, QuintyPlump, QuintyPlump);
EVENT_OBJ_16x16(NinjaBoy,    PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, NinjaBoy);
EVENT_OBJ_16x32(Twin,        PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Twin);
EVENT_OBJ_16x32(Boy1,        PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Boy1);
EVENT_OBJ_16x32(Girl1,       PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Girl1);
EVENT_OBJ_16x32(Boy2,        PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Boy2);
EVENT_OBJ_16x32(Girl2,       PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Girl2);
EVENT_OBJ_16x16(LittleBoy,   PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, LittleBoy);
EVENT_OBJ_16x16(LittleGirl,  PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, LittleGirl);
EVENT_OBJ_16x32(Boy3,        PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Boy3);
EVENT_OBJ_16x32(Girl3,       PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Girl3);
EVENT_OBJ_16x32(RichBoy,     PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, RichBoy);
EVENT_OBJ_16x32(Woman1,      PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Woman1);
EVENT_OBJ_16x32(FatMan,      PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, FatMan);
EVENT_OBJ_16x32(PokefanF,    PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, PokefanF);
EVENT_OBJ_16x32(Man1,        PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Man1);
EVENT_OBJ_16x32(Woman2,      PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Woman2);
EVENT_OBJ_16x32(ExpertM,     PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, ExpertM);
EVENT_OBJ_16x32(ExpertF,     PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, ExpertF);
EVENT_OBJ_16x32(Man2,        PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Man2);
EVENT_OBJ_16x32(Woman3,      PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Woman3);
EVENT_OBJ_16x32(PokefanM,    PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, PokefanM);
EVENT_OBJ_16x32(Woman4,      PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Woman4);
EVENT_OBJ_16x32(Cook,        PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Cook);
EVENT_OBJ_16x32(LinkReceptionist, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, LinkReceptionist);
EVENT_OBJ_16x32(OldMan,      PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, OldMan);
EVENT_OBJ_16x32(OldWoman,    PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, OldWoman);
EVENT_OBJ_16x32(Camper,      PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Camper);
EVENT_OBJ_16x32(Picnicker,   PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Picnicker);
EVENT_OBJ_16x32(Man3,        PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Man3);
EVENT_OBJ_16x32(Woman5,      PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Woman5);
EVENT_OBJ_16x32(Youngster,   PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Youngster);
EVENT_OBJ_16x32(BugCatcher,  PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, BugCatcher);
EVENT_OBJ_16x32(PsychicM,    PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, PsychicM);
EVENT_OBJ_16x32(SchoolKidM,  PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, SchoolKidM);
EVENT_OBJ_16x32(Maniac,      PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Maniac);
EVENT_OBJ_16x32(HexManiac,   PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, HexManiac);
EVENT_OBJ_64x64(Rayquaza1,   PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Standard, RayquazaStill);
EVENT_OBJ_16x32(SwimmerM,    PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, SwimmerM);
EVENT_OBJ_16x32(SwimmerF,    PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, SwimmerF);
EVENT_OBJ_16x32(BlackBelt,   PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, BlackBelt);
EVENT_OBJ_16x32(Beauty,      PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Beauty);
EVENT_OBJ_16x32(Scientist1,  PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Scientist1);
EVENT_OBJ_16x32(Lass,        PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Lass);
EVENT_OBJ_16x32(Gentleman,   PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Gentleman);
EVENT_OBJ_16x32(Sailor,      PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Sailor);
EVENT_OBJ_16x32(Fisherman,   PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Fisherman);
EVENT_OBJ_16x32(RunningTriathleteM, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, RunningTriathleteM);
EVENT_OBJ_16x32(RunningTriathleteF, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, RunningTriathleteF);
EVENT_OBJ_16x16(TuberF,     PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, TuberF);
EVENT_OBJ_16x16(TuberM,     PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, TuberM);
EVENT_OBJ_16x32(Hiker,      PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Hiker);
EVENT_OBJ_32x32(CyclingTriathleteM, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, CyclingTriathleteM);
EVENT_OBJ_32x32(CyclingTriathleteF, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, CyclingTriathleteF);
EVENT_OBJ_16x32(Nurse,     PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Nurse, Nurse);

EVENT_OBJ_16x16(ItemBall, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, ItemBall);
EVENT_OBJ_SPECIAL(BerryTree, PAL_TAG_0, PAL_TAG_NONE, 256, 16, 16, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_16x16, NULL, BerryTree, PechaBerryTree, gDummySpriteAffineAnimTable);
EVENT_OBJ_SPECIAL(BerryTreeEarlyStages, PAL_TAG_0, PAL_TAG_NONE, 256, 16, 16, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_16x16, gEventObjectSpriteOamTables_16x16, BerryTree, PechaBerryTree, gDummySpriteAffineAnimTable);
EVENT_OBJ_16x32(BerryTreeLateStages, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, BerryTree, PechaBerryTree);
EVENT_OBJ_16x32(ProfBirch, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, ProfBirch);
EVENT_OBJ_16x32(Man4,      PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Man4);
EVENT_OBJ_16x32(Man5,      PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Man5);
EVENT_OBJ_16x32(ReporterM, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, ReporterM);
EVENT_OBJ_16x32(ReporterF, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, ReporterF);

EVENT_OBJ_16x32(Bard,        PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MauvilleOldMan1);
EVENT_OBJ_16x32(Hipster,     PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MauvilleOldMan1);
EVENT_OBJ_16x32(Trader,      PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MauvilleOldMan1);
EVENT_OBJ_16x32(Storyteller, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MauvilleOldMan2);
EVENT_OBJ_16x32(Giddy,       PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MauvilleOldMan2);
EVENT_OBJ_16x32(UnusedMauvilleOldMan1, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MauvilleOldMan2);
EVENT_OBJ_16x32(UnusedMauvilleOldMan2, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MauvilleOldMan2);

EVENT_OBJ_16x16(UnusedNatuDoll, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, UnusedNatuDoll);
EVENT_OBJ_16x16(UnusedMagnemiteDoll, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, UnusedMagnemiteDoll);
EVENT_OBJ_16x16(UnusedSquirtleDoll, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, UnusedSquirtleDoll);
EVENT_OBJ_16x16(UnusedWooperDoll, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, UnusedWooperDoll);
EVENT_OBJ_16x16(UnusedPikachuDoll, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, UnusedPikachuDoll);
EVENT_OBJ_16x16(UnusedPorygon2Doll, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, UnusedPorygon2Doll);

EVENT_OBJ_16x16(CuttableTree, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, CuttableTree, CuttableTree);
EVENT_OBJ_16x32(MartEmployee, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MartEmployee);
EVENT_OBJ_16x32(RooftopSaleWoman, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, RooftopSaleWoman);
EVENT_OBJ_16x32(Teala, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Teala);
EVENT_OBJ_16x16(BreakableRock, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, BreakableRock, BreakableRock);
EVENT_OBJ_16x16(PushableBoulder, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, PushableBoulder);
EVENT_OBJ_32x32(MrBrineysBoat, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, Standard, MrBrineysBoat);
// May
EVENT_OBJ_SPECIAL(MayNormal, PAL_TAG_17, PAL_TAG_10, 512, 16, 32, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_16x32, gEventObjectSpriteOamTables_16x32, BrendanMayNormal, MayNormal, gDummySpriteAffineAnimTable);
EVENT_OBJ_32x32(MayMachBike, PAL_TAG_17, PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, Standard, MayMachBike);
EVENT_OBJ_32x32(MayAcroBike, PAL_TAG_17, PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, MayAcroBike);
EVENT_OBJ_32x32(MaySurfing, PAL_TAG_17, PAL_TAG_NONE, 0, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Surfing, MaySurfing);
EVENT_OBJ_32x32(MayFieldMove, PAL_TAG_17, PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, FieldMove, MayFieldMove);

EVENT_OBJ_SPECIAL(Truck, PAL_TAG_14, PAL_TAG_NONE, 1152, 48, 48, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_Truck, Inanimate, Truck, gDummySpriteAffineAnimTable);
EVENT_OBJ_32x32(VigorothCarryingBox, PAL_TAG_15, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, VigorothCarryingBox);
EVENT_OBJ_32x32(VigorothFacingAway, PAL_TAG_15, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, VigorothFacingAway);
EVENT_OBJ_16x16(BirchsBag, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, BirchsBag);
EVENT_OBJ_32x32(EnemyZigzagoon, PAL_TAG_16, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, EnemyZigzagoon);
EVENT_OBJ_32x32(Poochyena, PAL_TAG_27, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Poochyena);
EVENT_OBJ_16x32(Artist, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Artist);
// Rivals
EVENT_OBJ_16x32(RivalBrendanNormal,    PAL_TAG_8, PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, BrendanMayNormal, BrendanNormal);
EVENT_OBJ_32x32(RivalBrendanMachBike,  PAL_TAG_8, PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, Standard, BrendanMachBike);
EVENT_OBJ_32x32(RivalBrendanAcroBike,  PAL_TAG_8, PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, BrendanAcroBike);
EVENT_OBJ_32x32(RivalBrendanSurfing,   PAL_TAG_8, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Surfing, BrendanSurfing);
EVENT_OBJ_32x32(RivalBrendanFieldMove, PAL_TAG_8, PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, FieldMove, BrendanFieldMove);
EVENT_OBJ_16x32(RivalMayNormal,    PAL_TAG_17, PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, BrendanMayNormal, MayNormal);
EVENT_OBJ_32x32(RivalMayMachBike,  PAL_TAG_17, PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, Standard, MayMachBike);
EVENT_OBJ_32x32(RivalMayAcroBike,  PAL_TAG_17, PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_BIKE_TIRE, AcroBike, MayAcroBike);
EVENT_OBJ_32x32(RivalMaySurfing,   PAL_TAG_17, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Surfing, MaySurfing);
EVENT_OBJ_32x32(RivalMayFieldMove, PAL_TAG_17, PAL_TAG_10,   10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, FieldMove, MayFieldMove);

EVENT_OBJ_16x32(Cameraman, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Cameraman);
EVENT_OBJ_32x32(BrendanUnderwater, PAL_TAG_11, PAL_TAG_NONE, 0, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Standard, BrendanUnderwater);
EVENT_OBJ_32x32(MayUnderwater, PAL_TAG_11, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Standard, MayUnderwater);
EVENT_OBJ_16x16(MovingBox, PAL_TAG_19, PAL_TAG_NONE, 10, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, MovingBox);
EVENT_OBJ_64x64(CableCar, PAL_TAG_20, PAL_TAG_NONE, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, CableCar);
EVENT_OBJ_16x32(Scientist2, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Scientist2);
EVENT_OBJ_16x32(DevonEmployee, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, DevonEmployee);
EVENT_OBJ_16x32(AquaMemberM, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, AquaMemberM);
EVENT_OBJ_16x32(AquaMemberF, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, AquaMemberF);
EVENT_OBJ_16x32(MagmaMemberM, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MagmaMemberM);
EVENT_OBJ_16x32(MagmaMemberF, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MagmaMemberF);
// Gym leaders + Elite four
EVENT_OBJ_16x32(Sidney, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Sidney);
EVENT_OBJ_16x32(Phoebe, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Phoebe);
EVENT_OBJ_16x32(Glacia, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Glacia);
EVENT_OBJ_16x32(Drake, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Drake);
EVENT_OBJ_16x32(Roxanne, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Roxanne);
EVENT_OBJ_16x32(Brawly, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Brawly);
EVENT_OBJ_16x32(Wattson, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Wattson);
EVENT_OBJ_16x32(Flannery, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Flannery);
EVENT_OBJ_16x32(Norman, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Norman);
EVENT_OBJ_16x32(Winona, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Winona);
EVENT_OBJ_16x32(Liza, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Liza);
EVENT_OBJ_16x32(Tate, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Tate);
EVENT_OBJ_16x32(Wallace, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Wallace);
EVENT_OBJ_16x32(Steven, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Steven);

EVENT_OBJ_16x32(Wally, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Wally);
EVENT_OBJ_16x16(RubySapphireLittleBoy, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, RubySapphireLittleBoy);
EVENT_OBJ_32x32(BrendanFishing, PAL_TAG_8, PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Fishing, BrendanFishing);
EVENT_OBJ_32x32(MayFishing, PAL_TAG_17, PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Fishing, MayFishing);
EVENT_OBJ_16x32(HotSpringsOldWoman, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, HotSpringsOldWoman);

EVENT_OBJ_SPECIAL(SSTidal,         PAL_TAG_21, PAL_TAG_NONE, 1920, 96, 40, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_8x8, gEventObjectSpriteOamTables_SSTidal,         Standard, SSTidal, gDummySpriteAffineAnimTable);
EVENT_OBJ_SPECIAL(SubmarineShadow, PAL_TAG_26, PAL_TAG_NONE, 1408, 88, 32, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, &gEventObjectBaseOam_8x8, gEventObjectSpriteOamTables_SubmarineShadow, Standard, SubmarineShadow, gDummySpriteAffineAnimTable);
// Dolls + Cushions
EVENT_OBJ_16x16(PichuDoll,      PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, PichuDoll);
EVENT_OBJ_16x16(PikachuDoll,    PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, PikachuDoll);
EVENT_OBJ_16x16(MarillDoll,     PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, MarillDoll);
EVENT_OBJ_16x16(TogepiDoll,     PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, TogepiDoll);
EVENT_OBJ_16x16(CyndaquilDoll,  PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, CyndaquilDoll);
EVENT_OBJ_16x16(ChikoritaDoll,  PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, ChikoritaDoll);
EVENT_OBJ_16x16(TotodileDoll,   PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, TotodileDoll);
EVENT_OBJ_16x16(JigglypuffDoll, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, JigglypuffDoll);
EVENT_OBJ_16x16(MeowthDoll,     PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, MeowthDoll);
EVENT_OBJ_16x16(ClefairyDoll,   PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, ClefairyDoll);
EVENT_OBJ_16x16(DittoDoll,      PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, DittoDoll);
EVENT_OBJ_16x16(SmoochumDoll,   PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, SmoochumDoll);
EVENT_OBJ_16x16(TreeckoDoll,    PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, TreeckoDoll);
EVENT_OBJ_16x16(TorchicDoll,    PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, TorchicDoll);
EVENT_OBJ_16x16(MudkipDoll,     PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, MudkipDoll);
EVENT_OBJ_16x16(DuskullDoll,    PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, DuskullDoll);
EVENT_OBJ_16x16(WynautDoll,     PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, WynautDoll);
EVENT_OBJ_16x16(BaltoyDoll,     PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, BaltoyDoll);
EVENT_OBJ_16x16(KecleonDoll,    PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, KecleonDoll);
EVENT_OBJ_16x16(AzurillDoll,    PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, AzurillDoll);
EVENT_OBJ_16x16(SkittyDoll,     PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, SkittyDoll);
EVENT_OBJ_16x16(SwabluDoll,     PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, SwabluDoll);
EVENT_OBJ_16x16(GulpinDoll,     PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, GulpinDoll);
EVENT_OBJ_16x16(LotadDoll,      PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, LotadDoll);
EVENT_OBJ_16x16(SeedotDoll,     PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, SeedotDoll);
EVENT_OBJ_16x16(PikaCushion,    PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, PikaCushion);
EVENT_OBJ_16x16(RoundCushion,   PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, RoundCushion);
EVENT_OBJ_16x16(KissCushion,    PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, KissCushion);
EVENT_OBJ_16x16(ZigzagCushion,  PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, ZigzagCushion);
EVENT_OBJ_16x16(SpinCushion,    PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, SpinCushion);
EVENT_OBJ_16x16(DiamondCushion, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, DiamondCushion);
EVENT_OBJ_16x16(BallCushion,    PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, BallCushion);
EVENT_OBJ_16x16(GrassCushion,   PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, GrassCushion);
EVENT_OBJ_16x16(FireCushion,    PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, FireCushion);
EVENT_OBJ_16x16(WaterCushion,   PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, WaterCushion);

EVENT_OBJ_32x32(BigSnorlaxDoll,   PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, BigSnorlaxDoll);
EVENT_OBJ_32x32(BigRhydonDoll,    PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, BigRhydonDoll);
EVENT_OBJ_32x32(BigLaprasDoll,    PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, BigLaprasDoll);
EVENT_OBJ_32x32(BigVenusaurDoll,  PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, BigVenusaurDoll);
EVENT_OBJ_32x32(BigCharizardDoll, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, BigCharizardDoll);
EVENT_OBJ_32x32(BigBlastoiseDoll, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, BigBlastoiseDoll);
EVENT_OBJ_32x32(BigWailmerDoll,   PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, BigWailmerDoll);
EVENT_OBJ_32x32(BigRegirockDoll,  PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, BigRegirockDoll);
EVENT_OBJ_32x32(BigRegiceDoll,    PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, BigRegiceDoll);
EVENT_OBJ_32x32(BigRegisteelDoll, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_NONE, Inanimate, BigRegisteelDoll);

EVENT_OBJ_32x32(Latias, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, Standard, LatiasLatios);
EVENT_OBJ_32x32(Latios, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_NONE, Standard, LatiasLatios);
EVENT_OBJ_16x32(GameboyKid, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, GameboyKid);
EVENT_OBJ_16x32(ContestJudge, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, ContestJudge);
EVENT_OBJ_32x32(BrendanWatering, PAL_TAG_8, PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, BrendanWatering);
EVENT_OBJ_32x32(MayWatering, PAL_TAG_17, PAL_TAG_10, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MayWatering);
EVENT_OBJ_16x32(BrendanDecorating, PAL_TAG_8, PAL_TAG_10, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Inanimate, BrendanDecorating);
EVENT_OBJ_16x32(MayDecorating, PAL_TAG_17, PAL_TAG_10, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Inanimate, MayDecorating);
EVENT_OBJ_16x32(Archie, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Archie);
EVENT_OBJ_16x32(Maxie, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Maxie);

EVENT_OBJ_SPECIAL(Kyogre1,  PAL_TAG_3, PAL_TAG_NONE, 512, 32, 32, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Standard, KyogreFront, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(Groudon1, PAL_TAG_2, PAL_TAG_NONE, 512, 32, 32, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Standard, GroudonFront, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(Kyogre3,  PAL_TAG_3, PAL_TAG_NONE, 512, 32, 32, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Standard, KyogreSide, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(Groudon3, PAL_TAG_2, PAL_TAG_NONE, 512, 32, 32, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Groudon3, GroudonSide, gEventObjectRotScalAnimTable_KyogreGroudon);

EVENT_OBJ_16x16(Fossil, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_S, TRUE, FALSE, TRACKS_NONE, Inanimate, Fossil);
EVENT_OBJ_32x32(Regirock, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Standard, Regi);
EVENT_OBJ_32x32(Regice, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Standard, Regi);
EVENT_OBJ_32x32(Registeel, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Standard, Regi);
EVENT_OBJ_16x16(Skitty, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Skitty);
EVENT_OBJ_16x16(Kecleon1, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Kecleon);

EVENT_OBJ_SPECIAL(Kyogre2,  PAL_TAG_22, PAL_TAG_NONE, 512, 32, 32, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Standard, KyogreFront, gEventObjectRotScalAnimTable_KyogreGroudon);
EVENT_OBJ_SPECIAL(Groudon2, PAL_TAG_24, PAL_TAG_NONE, 512, 32, 32, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gEventObjectBaseOam_32x32, gEventObjectSpriteOamTables_32x32, Standard, GroudonFront, gEventObjectRotScalAnimTable_KyogreGroudon);

EVENT_OBJ_64x64(Rayquaza2, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, TRUE, TRACKS_FOOT, Rayquaza2, Rayquaza);
EVENT_OBJ_16x16(Zigzagoon, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Zigzagoon);
EVENT_OBJ_16x16(Pikachu, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Pikachu);
EVENT_OBJ_16x16(Azumarill, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Azumarill);
EVENT_OBJ_16x16(Wingull, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Wingull);
EVENT_OBJ_16x16(Kecleon2, PAL_TAG_2, PAL_TAG_10, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Kecleon);
EVENT_OBJ_16x16(TuberMSwimming, PAL_TAG_1, PAL_TAG_NONE, 3, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, TuberMSwimming);
EVENT_OBJ_16x16(Azurill, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Azurill);
EVENT_OBJ_16x32(Mom, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Mom);
EVENT_OBJ_16x32(LinkBrendan, PAL_TAG_17, PAL_TAG_10, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, BrendanMayNormal, BrendanNormal);
EVENT_OBJ_16x32(LinkMay, PAL_TAG_17, PAL_TAG_10, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, BrendanMayNormal, MayNormal);
EVENT_OBJ_16x32(Juan, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Juan);
EVENT_OBJ_16x32(Scott, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Scott);
EVENT_OBJ_16x32(MysteryEventDeliveryman, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, MysteryEventDeliveryman);
EVENT_OBJ_16x32(Statue, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Inanimate, Statue);
EVENT_OBJ_16x32(Kirlia, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_S, FALSE, FALSE, TRACKS_FOOT, Standard, Kirlia);
EVENT_OBJ_16x32(Dusclops, PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Dusclops);
EVENT_OBJ_16x32(UnionRoomAttendant, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, UnionRoomAttendant);
EVENT_OBJ_16x32(Red, PAL_TAG_28, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Red);
EVENT_OBJ_16x32(Leaf, PAL_TAG_28, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Leaf);
EVENT_OBJ_16x32(Sudowoodo, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Sudowoodo);
EVENT_OBJ_16x32(Mew, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Mew);
EVENT_OBJ_32x32(Deoxys, PAL_TAG_29, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Deoxys);
EVENT_OBJ_32x32(BirthIslandStone, PAL_TAG_30, PAL_TAG_NONE, 10, SHADOW_SIZE_M, TRUE, FALSE, TRACKS_FOOT, Inanimate, BirthIslandStone);
// Frontier Brains
EVENT_OBJ_16x32(Anabel,  PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Anabel);
EVENT_OBJ_16x32(Tucker,  PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Tucker);
EVENT_OBJ_16x32(Greta,   PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Greta);
EVENT_OBJ_16x32(Spenser, PAL_TAG_0, PAL_TAG_NONE, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Spenser);
EVENT_OBJ_16x32(Noland,  PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Noland);
EVENT_OBJ_16x32(Lucy,    PAL_TAG_3, PAL_TAG_NONE, 5, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Lucy);
EVENT_OBJ_16x32(Brandon, PAL_TAG_2, PAL_TAG_NONE, 4, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Brandon);

EVENT_OBJ_16x32(RubySapphireBrendan, PAL_TAG_33, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, RubySapphireBrendan);
EVENT_OBJ_16x32(RubySapphireMay, PAL_TAG_34, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, RubySapphireMay);
EVENT_OBJ_32x32(Lugia, PAL_TAG_32, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, Standard, Lugia);
EVENT_OBJ_32x32(HoOh, PAL_TAG_31, PAL_TAG_NONE, 10, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, HoOh, HoOh);
