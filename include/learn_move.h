#ifndef GUARD_LEAN_MOVE_H
#define GUARD_LEAN_MOVE_H

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

struct LearnMoveStruct *gUnknown_0203BC34 = NULL;

void sub_8160624(void);
void sub_8160638(void);

const struct SpritePalette gUnknown_08402D88 = {gDexArrows_Pal, 5526};

#endif //GUARD_LEAN_MOVE_H
