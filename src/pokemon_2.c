#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "event_data.h"
#include "rng.h"
#include "sprite.h"
#include "species.h"
#include "text.h"
#include "string_util.h"

struct Unknown_020249B4
{
    u8 unk0[0xC];
    struct SpriteTemplate* templates;
};

extern u8 gAbsentBankFlags;
extern u8 gActiveBank;
extern u8 gBankAttacker;
extern u8 gBankTarget;
extern u16 gTrainerBattleOpponent_A;
extern u32 gBattleTypeFlags;
extern struct SpriteTemplate gUnknown_0202499C;
extern struct Unknown_020249B4* gUnknown_020249B4[2];

extern const u32 gBitTable[];
extern const struct SpriteTemplate gUnknown_08329D98[];
extern const struct SpriteTemplate gUnknown_08329DF8[];
extern const struct SpriteTemplate gUnknown_08329D98[];
extern const union AnimCmd* gUnknown_082FF70C[];
extern const union AnimCmd* const * const gUnknown_08309AAC[];
extern const union AnimCmd* const * const gUnknown_08305D0C[];
extern const union AnimCmd* const * const gUnknown_0830536C[];
extern const u8 gBadEggNickname[];
extern const u8 gEggNickname[];

extern u8 GetBankSide(u8 bank);
extern u8 GetBankByPlayerAI(u8 bank);
extern u8 GetBankIdentity(u8 bank);

u8 CountAliveMonsInBattle(u8 caseId)
{
    s32 i;
    u8 retVal = 0;

    switch (caseId)
    {
    case BATTLE_ALIVE_EXCEPT_ACTIVE:
        for (i = 0; i < 4; i++)
        {
            if (i != gActiveBank && !(gAbsentBankFlags & gBitTable[i]))
                retVal++;
        }
        break;
    case BATTLE_ALIVE_ATK_SIDE:
        for (i = 0; i < 4; i++)
        {
            if (GetBankSide(i) == GetBankSide(gBankAttacker) && !(gAbsentBankFlags & gBitTable[i]))
                retVal++;
        }
        break;
    case BATTLE_ALIVE_DEF_SIDE:
        for (i = 0; i < 4; i++)
        {
            if (GetBankSide(i) == GetBankSide(gBankTarget) && !(gAbsentBankFlags & gBitTable[i]))
                retVal++;
        }
        break;
    }

    return retVal;
}

bool8 ShouldGetStatBadgeBoost(u16 badgeFlag, u8 bank)
{
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_x2000000 | BATTLE_TYPE_FRONTIER))
        return FALSE;
    if (GetBankSide(bank) != SIDE_PLAYER)
        return FALSE;
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && gTrainerBattleOpponent_A == SECRET_BASE_OPPONENT)
        return FALSE;
    if (FlagGet(badgeFlag))
        return TRUE;
    return FALSE;
}

u8 sub_8069F34(u8 bank)
{
    u8 status = GetBankIdentity(bank) & 1;

    status ^= 1;
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return GetBankByPlayerAI(status);
    if (CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_ACTIVE) > 1)
    {
        u8 val;

        if ((Random() & 1) == 0)
            val = status ^ 2;
        else
            val = status;
        return GetBankByPlayerAI(val);
    }
    else
    {
        if ((gAbsentBankFlags & gBitTable[status]))
            return GetBankByPlayerAI(status ^ 2);
        else
            return GetBankByPlayerAI(status);
    }
}

u8 GetMonGender(struct Pokemon *mon)
{
    return GetBoxMonGender(&mon->box);
}

u8 GetBoxMonGender(struct BoxPokemon *boxMon)
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    u32 personality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY, NULL);

    switch (gBaseStats[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        return gBaseStats[species].genderRatio;
    }

    if (gBaseStats[species].genderRatio > (personality & 0xFF))
        return MON_FEMALE;
    else
        return MON_MALE;
}

u8 GetGenderFromSpeciesAndPersonality(u16 species, u32 personality)
{
    switch (gBaseStats[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        return gBaseStats[species].genderRatio;
    }

    if (gBaseStats[species].genderRatio > (personality & 0xFF))
        return MON_FEMALE;
    else
        return MON_MALE;
}

void sub_806A068(u16 species, u8 bankIdentity)
{
    if (gBattleSpritesGfx != NULL)
        gUnknown_0202499C = gBattleSpritesGfx->templates[bankIdentity];
    else if (gUnknown_020249B4[0])
        gUnknown_0202499C = gUnknown_020249B4[0]->templates[bankIdentity];
    else if (gUnknown_020249B4[1])
        gUnknown_0202499C = gUnknown_020249B4[1]->templates[bankIdentity];
    else
        gUnknown_0202499C = gUnknown_08329D98[bankIdentity];

    gUnknown_0202499C.paletteTag = species;
    if (bankIdentity == 0 || bankIdentity == 2)
        gUnknown_0202499C.anims = gUnknown_082FF70C;
    else if (species > 500)
        gUnknown_0202499C.anims = gUnknown_08309AAC[species - 500];
    else
        gUnknown_0202499C.anims = gUnknown_08309AAC[species];
}

void sub_806A12C(u16 trainerSpriteId, u8 bankIdentity)
{
    gUnknown_0202499C.paletteTag = trainerSpriteId;
    if (bankIdentity == 0 || bankIdentity == 2)
    {
        gUnknown_0202499C = gUnknown_08329DF8[trainerSpriteId];
        gUnknown_0202499C.anims = gUnknown_08305D0C[trainerSpriteId];
    }
    else
    {
        if (gBattleSpritesGfx != NULL)
            gUnknown_0202499C = gBattleSpritesGfx->templates[bankIdentity];
        else
            gUnknown_0202499C = gUnknown_08329D98[bankIdentity];
        gUnknown_0202499C.anims = gUnknown_0830536C[trainerSpriteId];
    }
}

void sub_806A1C0(u16 arg0, u8 bankIdentity)
{
    if (gBattleSpritesGfx != NULL)
        gUnknown_0202499C = gBattleSpritesGfx->templates[bankIdentity];
    else
        gUnknown_0202499C = gUnknown_08329D98[bankIdentity];
    gUnknown_0202499C.paletteTag = arg0;
    gUnknown_0202499C.anims = gUnknown_0830536C[arg0];
}

void EncryptBoxMon(struct BoxPokemon *boxMon)
{
    u32 i;
    for (i = 0; i < 12; i++)
    {
        boxMon->secure.raw[i] ^= boxMon->personality;
        boxMon->secure.raw[i] ^= boxMon->otId;
    }
}

void DecryptBoxMon(struct BoxPokemon *boxMon)
{
    u32 i;
    for (i = 0; i < 12; i++)
    {
        boxMon->secure.raw[i] ^= boxMon->otId;
        boxMon->secure.raw[i] ^= boxMon->personality;
    }
}

#define SUBSTRUCT_CASE(n, v1, v2, v3, v4)                               \
case n:                                                                 \
    {                                                                   \
    union PokemonSubstruct *substructs0 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs1 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs2 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs3 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs4 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs5 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs6 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs7 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs8 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs9 = boxMon->secure.substructs;    \
    union PokemonSubstruct *substructs10 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs11 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs12 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs13 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs14 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs15 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs16 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs17 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs18 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs19 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs20 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs21 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs22 = boxMon->secure.substructs;   \
    union PokemonSubstruct *substructs23 = boxMon->secure.substructs;   \
                                                                        \
        switch (substructType)                                          \
        {                                                               \
        case 0:                                                         \
            substruct = &substructs ## n [v1];                          \
            break;                                                      \
        case 1:                                                         \
            substruct = &substructs ## n [v2];                          \
            break;                                                      \
        case 2:                                                         \
            substruct = &substructs ## n [v3];                          \
            break;                                                      \
        case 3:                                                         \
            substruct = &substructs ## n [v4];                          \
            break;                                                      \
        }                                                               \
        break;                                                          \
    }                                                                   \


union PokemonSubstruct *GetSubstruct(struct BoxPokemon *boxMon, u32 personality, u8 substructType)
{
    union PokemonSubstruct *substruct = NULL;

    switch (personality % 24)
    {
        SUBSTRUCT_CASE( 0,0,1,2,3)
        SUBSTRUCT_CASE( 1,0,1,3,2)
        SUBSTRUCT_CASE( 2,0,2,1,3)
        SUBSTRUCT_CASE( 3,0,3,1,2)
        SUBSTRUCT_CASE( 4,0,2,3,1)
        SUBSTRUCT_CASE( 5,0,3,2,1)
        SUBSTRUCT_CASE( 6,1,0,2,3)
        SUBSTRUCT_CASE( 7,1,0,3,2)
        SUBSTRUCT_CASE( 8,2,0,1,3)
        SUBSTRUCT_CASE( 9,3,0,1,2)
        SUBSTRUCT_CASE(10,2,0,3,1)
        SUBSTRUCT_CASE(11,3,0,2,1)
        SUBSTRUCT_CASE(12,1,2,0,3)
        SUBSTRUCT_CASE(13,1,3,0,2)
        SUBSTRUCT_CASE(14,2,1,0,3)
        SUBSTRUCT_CASE(15,3,1,0,2)
        SUBSTRUCT_CASE(16,2,3,0,1)
        SUBSTRUCT_CASE(17,3,2,0,1)
        SUBSTRUCT_CASE(18,1,2,3,0)
        SUBSTRUCT_CASE(19,1,3,2,0)
        SUBSTRUCT_CASE(20,2,1,3,0)
        SUBSTRUCT_CASE(21,3,1,2,0)
        SUBSTRUCT_CASE(22,2,3,1,0)
        SUBSTRUCT_CASE(23,3,2,1,0)
    }

    return substruct;
}

extern u16 GetDeoxysStat(struct Pokemon *mon, s32 statId);

#define TRY_GET_DEOXYS_STAT(mon, stat, LABEL)       \
{                                                   \
    u32 ret = GetDeoxysStat(mon, stat);             \
    if (ret)                                        \
        return ret;                                 \
    else                                            \
        goto LABEL;                                 \
}

u32 GetMonData(struct Pokemon *mon, s32 field, u8 *data)
{
    switch (field)
    {
    case MON_DATA_STATUS:
        return mon->status;
    case MON_DATA_LEVEL:
        return mon->level;
    case MON_DATA_HP:
        return mon->hp;
    case MON_DATA_MAX_HP:
        return mon->maxHP;
    case MON_DATA_ATK:
        TRY_GET_DEOXYS_STAT(mon, 1, GET_ATK)
    case MON_DATA_DEF:
        TRY_GET_DEOXYS_STAT(mon, 2, GET_DEF)
    case MON_DATA_SPD:
        TRY_GET_DEOXYS_STAT(mon, 3, GET_SPD)
    case MON_DATA_SPATK:
        TRY_GET_DEOXYS_STAT(mon, 4, GET_SPATK)
    case MON_DATA_SPDEF:
        TRY_GET_DEOXYS_STAT(mon, 5, GET_SPDEF)
    GET_ATK:
    case MON_DATA_ATK2:
        return mon->attack;
    GET_DEF:
    case MON_DATA_DEF2:
        return mon->defense;
    GET_SPD:
    case MON_DATA_SPD2:
        return mon->speed;
    GET_SPATK:
    case MON_DATA_SPATK2:
        return mon->spAttack;
    GET_SPDEF:
    case MON_DATA_SPDEF2:
        return mon->spDefense;
    case MON_DATA_MAIL:
        return mon->mail;
    default:
        return GetBoxMonData(&mon->box, field, data);
    }
}
