#ifndef GUARD_POKEMON_STORAGE_SYSTEM_H
#define GUARD_POKEMON_STORAGE_SYSTEM_H

#define TOTAL_BOXES_COUNT       14
#define IN_BOX_ROWS             6
#define IN_BOX_COLUMS           5
#define IN_BOX_COUNT            (IN_BOX_ROWS * IN_BOX_COLUMS)

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

struct StorageMenu
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
    struct UnkStruct_2000020 unk_0020;
    struct UnkStruct_2000028 unk_0028[8];
    u16 field_90[16];
    u16 field_B0[528 / 2];
    u16 field_2C0;
    u16 field_2C2;
    u8 field_2C4;
    u8 field_2C5;
    u8 showPartyMenuState;
    u8 unk_02C7;
    u8 unk_02C8;
    bool8 unk_02C9;
    s16 newCurrBoxId;
    u16 bg2_X;
    s16 field_2CE;
    u16 field_2D0;
    u8 field_2D2;
    u8 field_2D3;
    u8 field_2D4;
    u8 field_2D5;
    u16 field_2D6;
    s16 field_2D8;
    u16 field_2DA;
    u16 field_2DC;
    u16 field_2DE;
    u16 field_2E0;
    u8 field_2E2;
    u8 field_2E3;
    u8 field_2E4[20];
    u8 field_2F8[1024];
    u8 field_6F8;
    u8 field_6F9;
    u8 field_6FA;
    s8 field_6FB;
    u16 field_6FC[16];
    u16 field_71C;
    u16 field_71E;
    struct Sprite *field_720[2];
    struct Sprite *field_728[2];
    struct Sprite *field_730[2];
    u32 field_738;
    u8 field_73C[80];
    u16 field_78C;
    s16 wallpaperSetId;
    s16 wallpaperId;
    u16 field_792[360];
    u8 wallpaperChangeState;
    u8 field_A63;
    u8 field_A64;
    s8 field_A65;
    u8 field_A66;
    u8 field_A67;
    u8 *wallpaperTiles;
    struct Sprite *movingMonSprite;
    struct Sprite *partySprites[PARTY_SIZE];
    struct Sprite *boxMonsSprites[IN_BOX_COUNT];
    struct Sprite **field_B00;
    struct Sprite **field_B04;
    u16 field_B08[40];
    u16 field_B58[40];
    u16 boxSpecies[IN_BOX_COUNT];
    u32 boxPersonalities[IN_BOX_COUNT];
    u8 field_C5C;
    u8 field_C5D;
    u8 field_C5E;
    u8 field_C5F;
    u16 field_C60;
    s16 field_C62;
    s16 field_C64;
    u16 field_C66;
    u8 field_C68;
    s8 field_C69;
    u8 field_C6A;
    u8 field_C6B;
    struct WindowTemplate menuWindow;
    struct StorageMenu menuItems[7];
    u8 menuItemsCount;
    u8 menuWidth;
    u8 field_CAE;
    u8 field_CAF;
    u16 field_CB0;
    u8 field_CB2;
    u8 field_CB3;
    struct Sprite *field_CB4;
    struct Sprite *field_CB8;
    s32 field_CBC;
    s32 field_CC0;
    u32 field_CC4;
    u32 field_CC8;
    s16 field_CCC;
    s16 field_CCE;
    u16 field_CD0;
    s8 field_CD2;
    s8 field_CD3;
    u8 field_CD4;
    u8 field_CD5;
    u8 field_CD6;
    u8 field_CD7;
    u8 field_CD8[2];
    u8 field_CDA;
    u8 field_CDB;
    const u32 *cursorMonPalette;
    u32 cursorMonPersonality;
    u16 cursorMonSpecies;
    u16 cursorMonItem;
    u16 field_CE8;
    u8 field_CEA;
    u8 cursorMonMarkings;
    u8 cursorMonLevel;
    bool8 cursorMonIsEgg;
    u8 cursorMonNick[POKEMON_NAME_LENGTH + 1];
    u8 cursorMonNickText[36];
    u8 cursorMonSpeciesName[36];
    u8 cursorMonGenderLvlText[36];
    u8 cursorMonItemName[36];
    bool8 (*monPlaceChangeFunc)(void);
    u8 monPlaceChangeState;
    u8 field_D91;
    struct Sprite *field_D94;
    struct Sprite *field_D98[2];
    u16 *field_DA0;
    struct PokemonMarkMenu field_DA4;
    struct UnkPSSStruct_2002370 field_1E5C;
    struct Pokemon movingMon;
    struct Pokemon field_2108;
    s8 field_216C;
    u8 field_216D;
    s8 field_216E;
    s8 field_216F;
    s8 field_2170;
    s8 field_2171;
    u16 field_2172;
    u16 field_2174;
    u16 field_2176[5];
    u8 field_2180;
    u8 field_2181;
    u8 field_2182;
    u8 field_2183;
    u8 field_2184;
    u8 field_2185;
    u8 field_2186;
    u8 field_2187;
    u8 field_2188;
    union
    {
        struct Pokemon *mon;
        struct BoxPokemon *box;
    } field_218C;
    u8 field_2190[40];
    u8 field_21B8[40];
    u8 field_21E0[POKEMON_NAME_LENGTH + 1];
    u8 field_21EB[15]; // TODO: ITEM NAME LENGTH + 1
    u8 field_21FA;
    u8 field_21FB;
    u8 field_21FC;
    u8 field_21FD;
    u8 field_21FE;
    u8 inBoxMovingMode;
    u8 field_2200;
    u8 field_2201[51];
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
    u8 field_2AC4[8192];
    u8 field_4AC4[0x1000];
    u8 field_5AC4[0x800];
};

extern struct UnkPSSStruct_2002370 *gUnknown_02039D04;
extern struct PokemonStorageSystemData *gUnknown_02039D08;

u8* GetBoxNamePtr(u8 boxNumber);
struct BoxPokemon *GetBoxedMonPtr(u8, u8);
void SetBoxMonNickFromAnyBox(u8, u8, u8 *);
s16 CompactPartySlots(void);
u32 GetBoxMonDataAt(u8 boxId, u8 monPosition, u32 request);
bool8 CheckFreePokemonStorageSpace(void);
u8 StorageGetCurrentBox(void);
u8 sub_80D214C(struct BoxPokemon *a, u8 b, u8 c, u8 d);

#endif // GUARD_POKEMON_STORAGE_SYSTEM_H
