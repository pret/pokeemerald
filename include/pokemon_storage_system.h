#ifndef GUARD_POKEMON_STORAGE_SYSTEM_H
#define GUARD_POKEMON_STORAGE_SYSTEM_H

#define TOTAL_BOXES_COUNT       14
#define IN_BOX_COUNT            30

#include "pc_screen_effect.h"
#include "mon_markings.h"

struct PokemonStorageSystemFunc
{
    u8 (*func)(void);
    s8 unk4;
};

struct StorageAction
{
    const u8 *text;
    u8 format;
};

struct StorageText
{
    const u8 *text;
    int textId;
};

struct PSS_MenuStringPtrs
{
    const u8 *text;
    const u8 *desc;
};

struct UnkStruct_2000028
{
    const u8 *unk_00;
    u8 *unk_04;
    u16 unk_08;
    u16 unk_0a;
    void (*unk_0c)(struct UnkStruct_2000028 *data);
};

struct UnkStruct_2000020
{
    struct UnkStruct_2000028 *unk_00;
    u8 unk_04;
    u8 unk_05;
};

struct UnkPSSStruct_2002370
{
    struct Sprite *unk_0000;
    struct Sprite *unk_0004[4];
    u32 unk_0014[3];
    struct Sprite *unk_0020[2];
    u8 filler_0028[0x214];
    u32 unk_023c;
    u16 unk_0240;
    u16 unk_0242;
    u8 curBox;
    u8 unk_0245;
    u8 unk_0246;
};

struct PokemonStorageSystemData
{
    u8 state;
    u8 boxOption;
    u8 unk_0002;
    u8 unk_0003;
    u8 taskId;
    u8 unk_0005[710];
    u16 bg2_X;
};

extern struct UnkPSSStruct_2002370 *gUnknown_02039D04;
extern struct PokemonStorageSystemData *gUnknown_02039D08;

u8* GetBoxNamePtr(u8 boxNumber);
struct BoxPokemon *GetBoxedMonPtr(u8, u8);
void SetBoxMonNickFromAnyBox(u8, u8, u8 *);
void CompactPartySlots(void);
u32 GetBoxMonDataFromAnyBox(u8 boxId, u8 monPosition, u32 request);
bool8 CheckFreePokemonStorageSpace(void);
u8 StorageGetCurrentBox(void);
u8 sub_80D214C(struct BoxPokemon *a, u8 b, u8 c, u8 d);

#endif // GUARD_POKEMON_STORAGE_SYSTEM_H
