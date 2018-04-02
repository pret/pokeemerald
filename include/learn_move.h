#ifndef GUARD_LEARN_MOVE_H
#define GUARD_LEARN_MOVE_H

//this struct is probably wrong
struct LearnMoveStruct
{
    u8 state;
    u8 filler1;
    u8 unk2;
    u8 spriteIDs[20];
    u8 filler17[1];
    u8 unk18;
    u8 unk19;
    u8 numMenuChoices;
    u8 menuSelection;
    u8 unk1C;
    bool8 unk1D;
    u8 unk1E;
    u8 filler1F;
    /*0x020*/ u16 movesToLearn[20];
    u8 filler48[0x52-0x48];
    u8 moveNames[6][0x19];
    u8 fillerE8[0x2C3-0xE8];
    bool8 unk2C3;
    bool8 showContestInfo;
    /*0x2C5*/ u8 partyMon;
    u8 unk2C6;
};

//struct LearnMoveStruct *gUnknown_0203BC34 = NULL;

//extern u8 *gUnknown_0203BC34;

void sub_8160624(void);
void sub_8160638(void);

// Ew, just copied from pokeruby...
//const u16 gDexArrows_Pal[] = INCBIN_U16("graphics/pokedex/arrows.gbapal");
//const u8 gDexArrows_Gfx[] = INCBIN_U8("graphics/pokedex/arrows.4bpp");
//const struct SpritePalette gUnknown_085CEBB8 = {gDexArrows_Pal, 5526};
//const struct SpriteSheet gUnknown_085CEBB0 = {gDexArrows_Gfx, sizeof(gDexArrows_Gfx), 5525};

//u8 *gUnknown_0203BC38 = (void*)0x0203BC38;
//extern u8 gUnknown_0203BC38[8];
//u8 gUnknown_0203BC38;

#endif //GUARD_LEARN_MOVE_H
