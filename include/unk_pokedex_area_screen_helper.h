#ifndef GUARD_UNK_POKEDEX_AREA_SCREEN_HELPER_H
#define GUARD_UNK_POKEDEX_AREA_SCREEN_HELPER_H

struct UnkStruct_1C4D70
{
    u32 bg:2;
    u32 unk2:8;
    u32 unk10:2;
    u32 unk12:20;
};

void sub_81C4D70(const struct UnkStruct_1C4D70 *);
bool32 sub_81C4E90(void);
void sub_81C4ED0(u32);
void sub_81C4EB4(void);

#endif // GUARD_UNK_POKEDEX_AREA_SCREEN_HELPER_H
