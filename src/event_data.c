#include "global.h"
#include "event_data.h"

#define TEMP_FLAGS_SIZE 0x4
#define TEMP_UPPER_FLAGS_SIZE 0x8
#define TEMP_VARS_SIZE 0x20

EWRAM_DATA u16 gSpecialVar_0x8000 = 0;
EWRAM_DATA u16 gSpecialVar_0x8001 = 0;
EWRAM_DATA u16 gSpecialVar_0x8002 = 0;
EWRAM_DATA u16 gSpecialVar_0x8003 = 0;
EWRAM_DATA u16 gSpecialVar_0x8004 = 0;
EWRAM_DATA u16 gSpecialVar_0x8005 = 0;
EWRAM_DATA u16 gSpecialVar_0x8006 = 0;
EWRAM_DATA u16 gSpecialVar_0x8007 = 0;
EWRAM_DATA u16 gSpecialVar_0x8008 = 0;
EWRAM_DATA u16 gSpecialVar_0x8009 = 0;
EWRAM_DATA u16 gSpecialVar_0x800A = 0;
EWRAM_DATA u16 gSpecialVar_0x800B = 0;
EWRAM_DATA u16 gSpecialVar_ScriptResult = 0;
EWRAM_DATA u16 gSpecialVar_ScriptLastTalked = 0;
EWRAM_DATA u16 gSpecialVar_ScriptFacing = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxId = 0;
EWRAM_DATA u16 gSpecialVar_MonBoxPos = 0;
EWRAM_DATA u16 gSpecialVar_0x8014 = 0;
EWRAM_DATA static u8 gUnknown_020375FC[16] = {0};

extern u16 * const gSpecialVars[];

extern void sub_80BB358(void);

void InitEventData(void)
{
    memset(gSaveBlock1Ptr->flags, 0, sizeof(gSaveBlock1Ptr->flags));
    memset(gSaveBlock1Ptr->vars, 0, sizeof(gSaveBlock1Ptr->vars));
    memset(gUnknown_020375FC, 0, sizeof(gUnknown_020375FC));
}

void ClearTempFieldEventData(void)
{
    memset(gSaveBlock1Ptr->flags, 0, TEMP_FLAGS_SIZE);
    memset(gSaveBlock1Ptr->vars, 0, TEMP_VARS_SIZE);
    FlagClear(FLAG_SYS_ENC_UP_ITEM);
    FlagClear(FLAG_SYS_ENC_DOWN_ITEM);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_CTRL_OBJ_DELETE);
    FlagClear(FLAG_SYS_UNKNOWN_880);
}

// probably had different flag splits at one point.
void ClearUpperFlags(void)
{
    memset(gSaveBlock1Ptr->flags + 0x124, 0, TEMP_UPPER_FLAGS_SIZE);
}

void DisableNationalPokedex(void)
{
    u16 *nationalDexVar = GetVarPointer(VAR_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.nationalMagic = 0;
    *nationalDexVar = 0;
    FlagClear(FLAG_SYS_NATIONAL_DEX);
}

void EnableNationalPokedex(void)
{
    u16 *nationalDexVar = GetVarPointer(VAR_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.nationalMagic = 0xDA;
    *nationalDexVar = 0x302;
    FlagSet(FLAG_SYS_NATIONAL_DEX);
    gSaveBlock2Ptr->pokedex.unknown1 = 1;
    gSaveBlock2Ptr->pokedex.order = 0;
    sub_80BB358();
}

bool32 IsNationalPokedexEnabled(void)
{
    if (gSaveBlock2Ptr->pokedex.nationalMagic == 0xDA && VarGet(VAR_NATIONAL_DEX) == 0x302 && FlagGet(FLAG_SYS_NATIONAL_DEX))
        return TRUE;
    else
        return FALSE;
}

void DisableMysteryEvent(void)
{
    FlagClear(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void EnableMysteryEvent(void)
{
    FlagSet(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

bool32 IsMysteryEventEnabled(void)
{
    return FlagGet(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void DisableMysteryGift(void)
{
    FlagClear(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

void EnableMysteryGift(void)
{
    FlagSet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

bool32 IsMysteryGiftEnabled(void)
{
    return FlagGet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

void sub_809D4D8(void)
{
    FlagClear(0x1E4);
    FlagClear(0x1E5);
    FlagClear(0x1E6);
    FlagClear(0x1E7);
    FlagClear(0x1E8);
    FlagClear(0x1E9);
    FlagClear(0x1EA);
    FlagClear(0x1EB);
    FlagClear(0x1EC);
    FlagClear(0x1ED);
    FlagClear(0x1EE);
    FlagClear(0x1EF);
    FlagClear(0x1F0);
    FlagClear(0x1F1);
    FlagClear(0x1F2);
    FlagClear(0x1F3);
}

void sub_809D570(void)
{
    VarSet(0x40DD, 0);
    VarSet(0x40DE, 0);
    VarSet(0x40DF, 0);
    VarSet(0x40E0, 0);
    VarSet(0x40E1, 0);
    VarSet(0x40E2, 0);
    VarSet(0x40E3, 0);
    VarSet(0x40E4, 0);
}

void DisableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0);
    FlagClear(FLAG_SYS_RESET_RTC_ENABLE);
}

void EnableResetRTC(void)
{
    VarSet(VAR_RESET_RTC_ENABLE, 0x920);
    FlagSet(FLAG_SYS_RESET_RTC_ENABLE);
}

bool32 CanResetRTC(void)
{
    if (FlagGet(FLAG_SYS_RESET_RTC_ENABLE) && VarGet(VAR_RESET_RTC_ENABLE) == 0x920)
        return TRUE;
    else
        return FALSE;
}

u16 *GetVarPointer(u16 id)
{
    if (id < 0x4000)
        return NULL;

    if ((s16)id >= 0)
        return &gSaveBlock1Ptr->vars[id - 0x4000];

    return gSpecialVars[id - 0x8000];
}

u16 VarGet(u16 id)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return id;
    return *ptr;
}

bool8 VarSet(u16 id, u16 value)
{
    u16 *ptr = GetVarPointer(id);
    if (!ptr)
        return FALSE;
    *ptr = value;
    return TRUE;
}

u8 VarGetFieldObjectGraphicsId(u8 id)
{
    return VarGet(0x4010 + id);
}

u8 *GetFlagPointer(u16 id)
{
    if (id == 0)
        return 0;

    if (id < 0x4000)
        return &gSaveBlock1Ptr->flags[id / 8];

    return &gUnknown_020375FC[(id - 0x4000) / 8];
}

u8 FlagSet(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr |= 1 << (id & 7);
    return 0;
}

u8 FlagClear(u16 id)
{
    u8 *ptr = GetFlagPointer(id);
    if (ptr)
        *ptr &= ~(1 << (id & 7));
    return 0;
}

bool8 FlagGet(u16 id)
{
    u8 *ptr = GetFlagPointer(id);

    if (!ptr)
        return FALSE;

    if (!(((*ptr) >> (id & 7)) & 1))
        return FALSE;

    return TRUE;
}
