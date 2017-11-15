#ifndef GUARD_CONTEST_H
#define GUARD_CONTEST_H

struct ContestStruct_02039E00
{
    u16 unk_00;
    u8 unk_02[11];
    u8 unk_0d[8];
    u8 filler_15[9];
    u8 filler_1E[34];
};

extern struct ContestStruct_02039E00 gUnknown_02039E00[4];
extern u8 gUnknown_02039F24;
extern u16 gSpecialVar_ContestCategory;
extern u8 gSpecialVar_ContestRank;
extern u8 gUnknown_02039F30;

struct ContestStruct_field_18
{
    // unknown size
    u16 field_0;
    u16 field_2;
    u16 field_4;
    u16 field_6;
    u32 field_8;
    u32 field_C;
    u32 field_10;
};

struct ContestResources
{
    void *field_0;
    void *field_4;
    void *field_8;
    void *field_C;
    void *field_10;
    void *field_14;
    struct ContestStruct_field_18 *field_18;
};

extern struct ContestResources *gContestResources;

bool8 IsSpeciesNotUnown(u16 species);
void LoadContestBgAfterMoveAnim(void);

#endif //GUARD_CONTEST_H
