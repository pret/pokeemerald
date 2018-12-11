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
    u8 screenChangeType;
    bool8 isReshowingPSS;
    u8 taskId;
    u8 unk_0005;
    struct UnkStruct_2000020 unk_0020;
    struct UnkStruct_2000028 unk_0028[8];
    u8 unk_90[567];
    u8 unk_02C7;
    u8 unk_02C8;
    u8 unk_02C9;
    s16 newCurrBoxId;
    u16 bg2_X;
    u8 field_2CE;
    u8 field_2CF[1215];
    s16 wallpaperSetId;
    s16 wallpaperId;
    u8 wallpaperTilemap[180 * 4];
    u8 wallpaperChangeState;
    u8 field_A63;
    u8 field_A64;
    u8 field_A65;
    u8 field_A66;
    u8 field_A67;
    u8 *wallpaperTilemapPtr;
    u8 field_A6C;
    u8 field_A6D[623];
    u32 *field_CDC;
    u32 cursorMonPersonality;
    u16 cursorMonSpecies;
    u16 selectedItem;
    u16 field_CE8;
    u8 field_CEA;
    u8 field_CEB;
    u8 field_CEC;
    u8 field_CED;
    u8 field_CEE;
    u8 field_CEF;
    u8 field_CF0;
    u8 field_CF1;
    u8 field_CF2;
    u8 field_CF3;
    u8 field_CF4;
    u8 field_CF5;
    u8 field_CF6;
    u8 field_CF7;
    u8 field_CF8;
    u8 cursorMonNick[36];
    u8 cursorMonSpeciesName[36];
    u8 cursorMonGenderLvlText[36];
    u8 cursorMonItemName[47];
    struct Sprite *field_D94;
    struct Sprite *field_D98[2];
    u16 *field_DA0;
    struct PokemonMarkMenu field_DA4;
    struct UnkPSSStruct_2002370 field_1E5C;
    u8 field_20A4[220];
    u8 field_2180;
    u8 field_2181;
    u8 field_2182;
    u8 field_2183;
    u8 field_2184;
    u8 field_2185;
    u8 field_2186;
    u8 field_2187;
    u8 field_2188;
    struct BoxPokemon *field_218C;
    u8 field_2190[164];
    u16 movingItem;
    u8 field_2236;
    u8 field_2237;
    u8 field_2238;
    u8 field_2239;
    u16 field_223A;
    u16 *field_223C;
    struct Sprite *cursorMonSprite;
    u16 field_2244[16];
    u8 field_2264[96];
    u8 field_22C4[0x800];
    u8 field_2AC4[12288];
    u8 field_5AC4[0x800];
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
