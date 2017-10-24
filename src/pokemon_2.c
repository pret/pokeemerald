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
extern u8 gLastUsedAbility;
extern u16 gTrainerBattleOpponent_A;
extern u32 gBattleTypeFlags;
extern struct SpriteTemplate gUnknown_0202499C;
extern struct Unknown_020249B4* gUnknown_020249B4[2];

extern const u32 gBitTable[];
extern const struct SpriteTemplate gUnknown_08329D98[];
extern const struct SpriteTemplate gUnknown_08329DF8[];
extern const union AnimCmd* gUnknown_082FF70C[];
extern const union AnimCmd* const * const gMonAnimationsSpriteAnimsPtrTable[];
extern const union AnimCmd* const * const gUnknown_08305D0C[];
extern const union AnimCmd* const * const gUnknown_0830536C[];
extern const u8 gText_BadEgg[];
extern const u8 gText_EggNickname[];

extern u8 GetBankSide(u8 bank);
extern u8 GetBankByIdentity(u8 bank);
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

u8 GetDefaultMoveTarget(u8 bank)
{
    u8 status = GetBankIdentity(bank) & 1;

    status ^= 1;
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return GetBankByIdentity(status);
    if (CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_ACTIVE) > 1)
    {
        u8 val;

        if ((Random() & 1) == 0)
            val = status ^ 2;
        else
            val = status;
        return GetBankByIdentity(val);
    }
    else
    {
        if ((gAbsentBankFlags & gBitTable[status]))
            return GetBankByIdentity(status ^ 2);
        else
            return GetBankByIdentity(status);
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
    if (gMonSpritesGfxPtr != NULL)
        gUnknown_0202499C = gMonSpritesGfxPtr->templates[bankIdentity];
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
        gUnknown_0202499C.anims = gMonAnimationsSpriteAnimsPtrTable[species - 500];
    else
        gUnknown_0202499C.anims = gMonAnimationsSpriteAnimsPtrTable[species];
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
        if (gMonSpritesGfxPtr != NULL)
            gUnknown_0202499C = gMonSpritesGfxPtr->templates[bankIdentity];
        else
            gUnknown_0202499C = gUnknown_08329D98[bankIdentity];
        gUnknown_0202499C.anims = gUnknown_0830536C[trainerSpriteId];
    }
}

void sub_806A1C0(u16 arg0, u8 bankIdentity)
{
    if (gMonSpritesGfxPtr != NULL)
        gUnknown_0202499C = gMonSpritesGfxPtr->templates[bankIdentity];
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

u32 GetMonData(struct Pokemon *mon, s32 field, u8* data)
{
    u32 ret;

    switch (field)
    {
    case MON_DATA_STATUS:
        ret = mon->status;
        break;
    case MON_DATA_LEVEL:
        ret = mon->level;
        break;
    case MON_DATA_HP:
        ret = mon->hp;
        break;
    case MON_DATA_MAX_HP:
        ret = mon->maxHP;
        break;
    case MON_DATA_ATK:
        ret = GetDeoxysStat(mon, STAT_ATK);
        if (!ret)
            ret = mon->attack;
        break;
    case MON_DATA_DEF:
        ret = GetDeoxysStat(mon, STAT_DEF);
        if (!ret)
            ret = mon->defense;
        break;
    case MON_DATA_SPEED:
        ret = GetDeoxysStat(mon, STAT_SPD);
        if (!ret)
            ret = mon->speed;
        break;
    case MON_DATA_SPATK:
        ret = GetDeoxysStat(mon, STAT_SPATK);
        if (!ret)
            ret = mon->spAttack;
        break;
    case MON_DATA_SPDEF:
        ret = GetDeoxysStat(mon, STAT_SPDEF);
        if (!ret)
            ret = mon->spDefense;
        break;
    case MON_DATA_ATK2:
        ret = mon->attack;
        break;
    case MON_DATA_DEF2:
        ret = mon->defense;
        break;
    case MON_DATA_SPD2:
        ret = mon->speed;
        break;
    case MON_DATA_SPATK2:
        ret = mon->spAttack;
        break;
    case MON_DATA_SPDEF2:
        ret = mon->spDefense;
        break;
    case MON_DATA_MAIL:
        ret = mon->mail;
        break;
    default:
        ret = GetBoxMonData(&mon->box, field, data);
        break;
    }
    return ret;
}

u32 GetBoxMonData(struct BoxPokemon *boxMon, s32 field, u8 *data)
{
    s32 i;
    u32 retVal = 0;
    struct PokemonSubstruct0 *substruct0 = NULL;
    struct PokemonSubstruct1 *substruct1 = NULL;
    struct PokemonSubstruct2 *substruct2 = NULL;
    struct PokemonSubstruct3 *substruct3 = NULL;

    if (field > MON_DATA_10)
    {
        substruct0 = &(GetSubstruct(boxMon, boxMon->personality, 0)->type0);
        substruct1 = &(GetSubstruct(boxMon, boxMon->personality, 1)->type1);
        substruct2 = &(GetSubstruct(boxMon, boxMon->personality, 2)->type2);
        substruct3 = &(GetSubstruct(boxMon, boxMon->personality, 3)->type3);

        DecryptBoxMon(boxMon);

        if (CalculateBoxMonChecksum(boxMon) != boxMon->checksum)
        {
            boxMon->isBadEgg = 1;
            boxMon->isEgg = 1;
            substruct3->isEgg = 1;
        }
    }

    switch (field)
    {
    case MON_DATA_PERSONALITY:
        retVal = boxMon->personality;
        break;
    case MON_DATA_OT_ID:
        retVal = boxMon->otId;
        break;
    case MON_DATA_NICKNAME:
    {
        if (boxMon->isBadEgg)
        {
            for (retVal = 0;
                retVal < POKEMON_NAME_LENGTH && gText_BadEgg[retVal] != EOS;
                data[retVal] = gText_BadEgg[retVal], retVal++) {}

            data[retVal] = EOS;
        }
        else if (boxMon->isEgg)
        {
            StringCopy(data, gText_EggNickname);
            retVal = StringLength(data);
        }
        else if (boxMon->language == LANGUAGE_JAPANESE)
        {
            data[0] = EXT_CTRL_CODE_BEGIN;
            data[1] = EXT_CTRL_CODE_JPN;

            for (retVal = 2, i = 0;
                i < 5 && boxMon->nickname[i] != EOS;
                data[retVal] = boxMon->nickname[i], retVal++, i++) {}

            data[retVal++] = EXT_CTRL_CODE_BEGIN;
            data[retVal++] = EXT_CTRL_CODE_ENG;
            data[retVal] = EOS;
        }
        else
        {
            for (retVal = 0;
                retVal < POKEMON_NAME_LENGTH;
                data[retVal] = boxMon->nickname[retVal], retVal++){}

            data[retVal] = EOS;
        }
        break;
    }
    case MON_DATA_LANGUAGE:
        retVal = boxMon->language;
        break;
    case MON_DATA_SANITY_BIT1:
        retVal = boxMon->isBadEgg;
        break;
    case MON_DATA_SANITY_BIT2:
        retVal = boxMon->hasSpecies;
        break;
    case MON_DATA_SANITY_BIT3:
        retVal = boxMon->isEgg;
        break;
    case MON_DATA_OT_NAME:
    {
        retVal = 0;

        while (retVal < OT_NAME_LENGTH)
        {
            data[retVal] = boxMon->otName[retVal];
            retVal++;
        }

        data[retVal] = EOS;
        break;
    }
    case MON_DATA_MARKINGS:
        retVal = boxMon->markings;
        break;
    case MON_DATA_CHECKSUM:
        retVal = boxMon->checksum;
        break;
    case MON_DATA_10:
        retVal = boxMon->unknown;
        break;
    case MON_DATA_SPECIES:
        retVal = boxMon->isBadEgg ? SPECIES_EGG : substruct0->species;
        break;
    case MON_DATA_HELD_ITEM:
        retVal = substruct0->heldItem;
        break;
    case MON_DATA_EXP:
        retVal = substruct0->experience;
        break;
    case MON_DATA_PP_BONUSES:
        retVal = substruct0->ppBonuses;
        break;
    case MON_DATA_FRIENDSHIP:
        retVal = substruct0->friendship;
        break;
    case MON_DATA_MOVE1:
    case MON_DATA_MOVE2:
    case MON_DATA_MOVE3:
    case MON_DATA_MOVE4:
        retVal = substruct1->moves[field - MON_DATA_MOVE1];
        break;
    case MON_DATA_PP1:
    case MON_DATA_PP2:
    case MON_DATA_PP3:
    case MON_DATA_PP4:
        retVal = substruct1->pp[field - MON_DATA_PP1];
        break;
    case MON_DATA_HP_EV:
        retVal = substruct2->hpEV;
        break;
    case MON_DATA_ATK_EV:
        retVal = substruct2->attackEV;
        break;
    case MON_DATA_DEF_EV:
        retVal = substruct2->defenseEV;
        break;
    case MON_DATA_SPEED_EV:
        retVal = substruct2->speedEV;
        break;
    case MON_DATA_SPATK_EV:
        retVal = substruct2->spAttackEV;
        break;
    case MON_DATA_SPDEF_EV:
        retVal = substruct2->spDefenseEV;
        break;
    case MON_DATA_COOL:
        retVal = substruct2->cool;
        break;
    case MON_DATA_BEAUTY:
        retVal = substruct2->beauty;
        break;
    case MON_DATA_CUTE:
        retVal = substruct2->cute;
        break;
    case MON_DATA_SMART:
        retVal = substruct2->smart;
        break;
    case MON_DATA_TOUGH:
        retVal = substruct2->tough;
        break;
    case MON_DATA_SHEEN:
        retVal = substruct2->sheen;
        break;
    case MON_DATA_POKERUS:
        retVal = substruct3->pokerus;
        break;
    case MON_DATA_MET_LOCATION:
        retVal = substruct3->metLocation;
        break;
    case MON_DATA_MET_LEVEL:
        retVal = substruct3->metLevel;
        break;
    case MON_DATA_MET_GAME:
        retVal = substruct3->metGame;
        break;
    case MON_DATA_POKEBALL:
        retVal = substruct3->pokeball;
        break;
    case MON_DATA_OT_GENDER:
        retVal = substruct3->otGender;
        break;
    case MON_DATA_HP_IV:
        retVal = substruct3->hpIV;
        break;
    case MON_DATA_ATK_IV:
        retVal = substruct3->attackIV;
        break;
    case MON_DATA_DEF_IV:
        retVal = substruct3->defenseIV;
        break;
    case MON_DATA_SPEED_IV:
        retVal = substruct3->speedIV;
        break;
    case MON_DATA_SPATK_IV:
        retVal = substruct3->spAttackIV;
        break;
    case MON_DATA_SPDEF_IV:
        retVal = substruct3->spDefenseIV;
        break;
    case MON_DATA_IS_EGG:
        retVal = substruct3->isEgg;
        break;
    case MON_DATA_ALT_ABILITY:
        retVal = substruct3->altAbility;
        break;
    case MON_DATA_COOL_RIBBON:
        retVal = substruct3->coolRibbon;
        break;
    case MON_DATA_BEAUTY_RIBBON:
        retVal = substruct3->beautyRibbon;
        break;
    case MON_DATA_CUTE_RIBBON:
        retVal = substruct3->cuteRibbon;
        break;
    case MON_DATA_SMART_RIBBON:
        retVal = substruct3->smartRibbon;
        break;
    case MON_DATA_TOUGH_RIBBON:
        retVal = substruct3->toughRibbon;
        break;
    case MON_DATA_CHAMPION_RIBBON:
        retVal = substruct3->championRibbon;
        break;
    case MON_DATA_WINNING_RIBBON:
        retVal = substruct3->winningRibbon;
        break;
    case MON_DATA_VICTORY_RIBBON:
        retVal = substruct3->victoryRibbon;
        break;
    case MON_DATA_ARTIST_RIBBON:
        retVal = substruct3->artistRibbon;
        break;
    case MON_DATA_EFFORT_RIBBON:
        retVal = substruct3->effortRibbon;
        break;
    case MON_DATA_GIFT_RIBBON_1:
        retVal = substruct3->giftRibbon1;
        break;
    case MON_DATA_GIFT_RIBBON_2:
        retVal = substruct3->giftRibbon2;
        break;
    case MON_DATA_GIFT_RIBBON_3:
        retVal = substruct3->giftRibbon3;
        break;
    case MON_DATA_GIFT_RIBBON_4:
        retVal = substruct3->giftRibbon4;
        break;
    case MON_DATA_GIFT_RIBBON_5:
        retVal = substruct3->giftRibbon5;
        break;
    case MON_DATA_GIFT_RIBBON_6:
        retVal = substruct3->giftRibbon6;
        break;
    case MON_DATA_GIFT_RIBBON_7:
        retVal = substruct3->giftRibbon7;
        break;
    case MON_DATA_FATEFUL_ENCOUNTER:
        retVal = substruct3->fatefulEncounter;
        break;
    case MON_DATA_OBEDIENCE:
        retVal = substruct3->obedient;
        break;
    case MON_DATA_SPECIES2:
        retVal = substruct0->species;
        if (substruct0->species && (substruct3->isEgg || boxMon->isBadEgg))
            retVal = SPECIES_EGG;
        break;
    case MON_DATA_IVS:
        retVal = substruct3->hpIV | (substruct3->attackIV << 5) | (substruct3->defenseIV << 10) | (substruct3->speedIV << 15) | (substruct3->spAttackIV << 20) | (substruct3->spDefenseIV << 25);
        break;
    case MON_DATA_KNOWN_MOVES:
        if (substruct0->species && !substruct3->isEgg)
        {
            u16 *moves = (u16 *)data;
            s32 i = 0;

            while (moves[i] != 355)
            {
                u16 move = moves[i];
                if (substruct1->moves[0] == move
                    || substruct1->moves[1] == move
                    || substruct1->moves[2] == move
                    || substruct1->moves[3] == move)
                    retVal |= gBitTable[i];
                i++;
            }
        }
        break;
    case MON_DATA_RIBBON_COUNT:
        retVal = 0;
        if (substruct0->species && !substruct3->isEgg)
        {
            retVal += substruct3->coolRibbon;
            retVal += substruct3->beautyRibbon;
            retVal += substruct3->cuteRibbon;
            retVal += substruct3->smartRibbon;
            retVal += substruct3->toughRibbon;
            retVal += substruct3->championRibbon;
            retVal += substruct3->winningRibbon;
            retVal += substruct3->victoryRibbon;
            retVal += substruct3->artistRibbon;
            retVal += substruct3->effortRibbon;
            retVal += substruct3->giftRibbon1;
            retVal += substruct3->giftRibbon2;
            retVal += substruct3->giftRibbon3;
            retVal += substruct3->giftRibbon4;
            retVal += substruct3->giftRibbon5;
            retVal += substruct3->giftRibbon6;
            retVal += substruct3->giftRibbon7;
        }
        break;
    case MON_DATA_RIBBONS:
        retVal = 0;
        if (substruct0->species && !substruct3->isEgg)
        {
            retVal = substruct3->championRibbon
                | (substruct3->coolRibbon << 1)
                | (substruct3->beautyRibbon << 4)
                | (substruct3->cuteRibbon << 7)
                | (substruct3->smartRibbon << 10)
                | (substruct3->toughRibbon << 13)
                | (substruct3->winningRibbon << 16)
                | (substruct3->victoryRibbon << 17)
                | (substruct3->artistRibbon << 18)
                | (substruct3->effortRibbon << 19)
                | (substruct3->giftRibbon1 << 20)
                | (substruct3->giftRibbon2 << 21)
                | (substruct3->giftRibbon3 << 22)
                | (substruct3->giftRibbon4 << 23)
                | (substruct3->giftRibbon5 << 24)
                | (substruct3->giftRibbon6 << 25)
                | (substruct3->giftRibbon7 << 26);
        }
        break;
    default:
        break;
    }

    if (field > MON_DATA_10)
        EncryptBoxMon(boxMon);

    return retVal;
}

#define SET8(lhs) (lhs) = *data
#define SET16(lhs) (lhs) = data[0] + (data[1] << 8)
#define SET32(lhs) (lhs) = data[0] + (data[1] << 8) + (data[2] << 16) + (data[3] << 24)

void SetMonData(struct Pokemon *mon, s32 field, const void *dataArg)
{
    const u8* data = dataArg;
    switch (field)
    {
    case MON_DATA_STATUS:
        SET32(mon->status);
        break;
    case MON_DATA_LEVEL:
        SET8(mon->level);
        break;
    case MON_DATA_HP:
        SET16(mon->hp);
        break;
    case MON_DATA_MAX_HP:
        SET16(mon->maxHP);
        break;
    case MON_DATA_ATK:
        SET16(mon->attack);
        break;
    case MON_DATA_DEF:
        SET16(mon->defense);
        break;
    case MON_DATA_SPEED:
        SET16(mon->speed);
        break;
    case MON_DATA_SPATK:
        SET16(mon->spAttack);
        break;
    case MON_DATA_SPDEF:
        SET16(mon->spDefense);
        break;
    case MON_DATA_MAIL:
        SET8(mon->mail);
        break;
    case MON_DATA_SPECIES2:
        break;
    default:
        SetBoxMonData(&mon->box, field, data);
        break;
    }
}

void SetBoxMonData(struct BoxPokemon *boxMon, s32 field, const void *dataArg)
{
    const u8* data = dataArg;

    struct PokemonSubstruct0 *substruct0 = NULL;
    struct PokemonSubstruct1 *substruct1 = NULL;
    struct PokemonSubstruct2 *substruct2 = NULL;
    struct PokemonSubstruct3 *substruct3 = NULL;

    if (field > MON_DATA_10)
    {
        substruct0 = &(GetSubstruct(boxMon, boxMon->personality, 0)->type0);
        substruct1 = &(GetSubstruct(boxMon, boxMon->personality, 1)->type1);
        substruct2 = &(GetSubstruct(boxMon, boxMon->personality, 2)->type2);
        substruct3 = &(GetSubstruct(boxMon, boxMon->personality, 3)->type3);

        DecryptBoxMon(boxMon);

        if (CalculateBoxMonChecksum(boxMon) != boxMon->checksum)
        {
            boxMon->isBadEgg = 1;
            boxMon->isEgg = 1;
            substruct3->isEgg = 1;
            EncryptBoxMon(boxMon);
            return;
        }
    }

    switch (field)
    {
    case MON_DATA_PERSONALITY:
        SET32(boxMon->personality);
        break;
    case MON_DATA_OT_ID:
        SET32(boxMon->otId);
        break;
    case MON_DATA_NICKNAME:
    {
        s32 i;
        for (i = 0; i < POKEMON_NAME_LENGTH; i++)
            boxMon->nickname[i] = data[i];
        break;
    }
    case MON_DATA_LANGUAGE:
        SET8(boxMon->language);
        break;
    case MON_DATA_SANITY_BIT1:
        SET8(boxMon->isBadEgg);
        break;
    case MON_DATA_SANITY_BIT2:
        SET8(boxMon->hasSpecies);
        break;
    case MON_DATA_SANITY_BIT3:
        SET8(boxMon->isEgg);
        break;
    case MON_DATA_OT_NAME:
    {
        s32 i;
        for (i = 0; i < OT_NAME_LENGTH; i++)
            boxMon->otName[i] = data[i];
        break;
    }
    case MON_DATA_MARKINGS:
        SET8(boxMon->markings);
        break;
    case MON_DATA_CHECKSUM:
        SET16(boxMon->checksum);
        break;
    case MON_DATA_10:
        SET16(boxMon->unknown);
        break;
    case MON_DATA_SPECIES:
    {
        SET16(substruct0->species);
        if (substruct0->species)
            boxMon->hasSpecies = 1;
        else
            boxMon->hasSpecies = 0;
        break;
    }
    case MON_DATA_HELD_ITEM:
        SET16(substruct0->heldItem);
        break;
    case MON_DATA_EXP:
        SET32(substruct0->experience);
        break;
    case MON_DATA_PP_BONUSES:
        SET8(substruct0->ppBonuses);
        break;
    case MON_DATA_FRIENDSHIP:
        SET8(substruct0->friendship);
        break;
    case MON_DATA_MOVE1:
    case MON_DATA_MOVE2:
    case MON_DATA_MOVE3:
    case MON_DATA_MOVE4:
        SET16(substruct1->moves[field - MON_DATA_MOVE1]);
        break;
    case MON_DATA_PP1:
    case MON_DATA_PP2:
    case MON_DATA_PP3:
    case MON_DATA_PP4:
        SET8(substruct1->pp[field - MON_DATA_PP1]);
        break;
    case MON_DATA_HP_EV:
        SET8(substruct2->hpEV);
        break;
    case MON_DATA_ATK_EV:
        SET8(substruct2->attackEV);
        break;
    case MON_DATA_DEF_EV:
        SET8(substruct2->defenseEV);
        break;
    case MON_DATA_SPEED_EV:
        SET8(substruct2->speedEV);
        break;
    case MON_DATA_SPATK_EV:
        SET8(substruct2->spAttackEV);
        break;
    case MON_DATA_SPDEF_EV:
        SET8(substruct2->spDefenseEV);
        break;
    case MON_DATA_COOL:
        SET8(substruct2->cool);
        break;
    case MON_DATA_BEAUTY:
        SET8(substruct2->beauty);
        break;
    case MON_DATA_CUTE:
        SET8(substruct2->cute);
        break;
    case MON_DATA_SMART:
        SET8(substruct2->smart);
        break;
    case MON_DATA_TOUGH:
        SET8(substruct2->tough);
        break;
    case MON_DATA_SHEEN:
        SET8(substruct2->sheen);
        break;
    case MON_DATA_POKERUS:
        SET8(substruct3->pokerus);
        break;
    case MON_DATA_MET_LOCATION:
        SET8(substruct3->metLocation);
        break;
    case MON_DATA_MET_LEVEL:
    {
        u8 metLevel = *data;
        substruct3->metLevel = metLevel;
        break;
    }
    case MON_DATA_MET_GAME:
        SET8(substruct3->metGame);
        break;
    case MON_DATA_POKEBALL:
    {
        u8 pokeball = *data;
        substruct3->pokeball = pokeball;
        break;
    }
    case MON_DATA_OT_GENDER:
        SET8(substruct3->otGender);
        break;
    case MON_DATA_HP_IV:
        SET8(substruct3->hpIV);
        break;
    case MON_DATA_ATK_IV:
        SET8(substruct3->attackIV);
        break;
    case MON_DATA_DEF_IV:
        SET8(substruct3->defenseIV);
        break;
    case MON_DATA_SPEED_IV:
        SET8(substruct3->speedIV);
        break;
    case MON_DATA_SPATK_IV:
        SET8(substruct3->spAttackIV);
        break;
    case MON_DATA_SPDEF_IV:
        SET8(substruct3->spDefenseIV);
        break;
    case MON_DATA_IS_EGG:
        SET8(substruct3->isEgg);
        if (substruct3->isEgg)
            boxMon->isEgg = 1;
        else
            boxMon->isEgg = 0;
        break;
    case MON_DATA_ALT_ABILITY:
        SET8(substruct3->altAbility);
        break;
    case MON_DATA_COOL_RIBBON:
        SET8(substruct3->coolRibbon);
        break;
    case MON_DATA_BEAUTY_RIBBON:
        SET8(substruct3->beautyRibbon);
        break;
    case MON_DATA_CUTE_RIBBON:
        SET8(substruct3->cuteRibbon);
        break;
    case MON_DATA_SMART_RIBBON:
        SET8(substruct3->smartRibbon);
        break;
    case MON_DATA_TOUGH_RIBBON:
        SET8(substruct3->toughRibbon);
        break;
    case MON_DATA_CHAMPION_RIBBON:
        SET8(substruct3->championRibbon);
        break;
    case MON_DATA_WINNING_RIBBON:
        SET8(substruct3->winningRibbon);
        break;
    case MON_DATA_VICTORY_RIBBON:
        SET8(substruct3->victoryRibbon);
        break;
    case MON_DATA_ARTIST_RIBBON:
        SET8(substruct3->artistRibbon);
        break;
    case MON_DATA_EFFORT_RIBBON:
        SET8(substruct3->effortRibbon);
        break;
    case MON_DATA_GIFT_RIBBON_1:
        SET8(substruct3->giftRibbon1);
        break;
    case MON_DATA_GIFT_RIBBON_2:
        SET8(substruct3->giftRibbon2);
        break;
    case MON_DATA_GIFT_RIBBON_3:
        SET8(substruct3->giftRibbon3);
        break;
    case MON_DATA_GIFT_RIBBON_4:
        SET8(substruct3->giftRibbon4);
        break;
    case MON_DATA_GIFT_RIBBON_5:
        SET8(substruct3->giftRibbon5);
        break;
    case MON_DATA_GIFT_RIBBON_6:
        SET8(substruct3->giftRibbon6);
        break;
    case MON_DATA_GIFT_RIBBON_7:
        SET8(substruct3->giftRibbon7);
        break;
    case MON_DATA_FATEFUL_ENCOUNTER:
        SET8(substruct3->fatefulEncounter);
        break;
    case MON_DATA_OBEDIENCE:
        SET8(substruct3->obedient);
        break;
    case MON_DATA_IVS:
    {
        u32 ivs = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
        substruct3->hpIV = ivs & 0x1F;
        substruct3->attackIV = (ivs >> 5) & 0x1F;
        substruct3->defenseIV = (ivs >> 10) & 0x1F;
        substruct3->speedIV = (ivs >> 15) & 0x1F;
        substruct3->spAttackIV = (ivs >> 20) & 0x1F;
        substruct3->spDefenseIV = (ivs >> 25) & 0x1F;
        break;
    }
    default:
        break;
    }

    if (field > MON_DATA_10)
    {
        boxMon->checksum = CalculateBoxMonChecksum(boxMon);
        EncryptBoxMon(boxMon);
    }
}

void CopyMon(void *dest, void *src, size_t size)
{
    memcpy(dest, src, size);
}

u8 GiveMonToPlayer(struct Pokemon *mon)
{
    s32 i;

    SetMonData(mon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetMonData(mon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);
    SetMonData(mon, MON_DATA_OT_ID, gSaveBlock2Ptr->playerTrainerId);

    i = 0;

    while (i < 6 && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) != SPECIES_NONE)
        i++;

    if (i >= 6)
        return SendMonToPC(mon);

    CopyMon(&gPlayerParty[i], mon, sizeof(*mon));
    gPlayerPartyCount = i + 1;
    return MON_GIVEN_TO_PARTY;
}

extern u16 get_unknown_box_id(void);
extern u8 StorageGetCurrentBox(void);
extern void set_unknown_box_id(u8);
extern struct BoxPokemon* GetBoxedMonPtr(u8 boxNumber, u8 boxPosition);

u8 SendMonToPC(struct Pokemon* mon)
{
    s32 boxNo, boxPos;

    set_unknown_box_id(VarGet(VAR_STORAGE_UNKNOWN));

    boxNo = StorageGetCurrentBox();

    do
    {
        for (boxPos = 0; boxPos < 30; boxPos++)
        {
            struct BoxPokemon* checkingMon = GetBoxedMonPtr(boxNo, boxPos);
            if (GetBoxMonData(checkingMon, MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            {
                MonRestorePP(mon);
                CopyMon(checkingMon, &mon->box, sizeof(mon->box));
                gSpecialVar_0x8012 = boxNo;
                gSpecialVar_0x8013 = boxPos;
                if (get_unknown_box_id() != boxNo)
                    FlagClear(SYS_STORAGE_UNKNOWN_FLAG);
                VarSet(VAR_STORAGE_UNKNOWN, boxNo);
                return MON_GIVEN_TO_PC;
            }
        }

        boxNo++;
        if (boxNo == 14)
            boxNo = 0;
    } while (boxNo != StorageGetCurrentBox());

    return MON_CANT_GIVE;
}

u8 CalculatePlayerPartyCount(void)
{
    gPlayerPartyCount = 0;

    while (gPlayerPartyCount < 6
        && GetMonData(&gPlayerParty[gPlayerPartyCount], MON_DATA_SPECIES, NULL) != SPECIES_NONE)
    {
        gPlayerPartyCount++;
    }

    return gPlayerPartyCount;
}

u8 CalculateEnemyPartyCount(void)
{
    gEnemyPartyCount = 0;

    while (gEnemyPartyCount < 6
        && GetMonData(&gEnemyParty[gEnemyPartyCount], MON_DATA_SPECIES, NULL) != SPECIES_NONE)
    {
        gEnemyPartyCount++;
    }

    return gEnemyPartyCount;
}

u8 GetMonsStateToDoubles(void)
{
    s32 aliveCount = 0;
    s32 i;
    CalculatePlayerPartyCount();

    if (gPlayerPartyCount == 1)
        return gPlayerPartyCount; // PLAYER_HAS_ONE_MON

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) != SPECIES_EGG
         && GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL) != 0
         && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL) != SPECIES_NONE)
            aliveCount++;
    }

    return (aliveCount > 1) ? PLAYER_HAS_TWO_USABLE_MONS : PLAYER_HAS_ONE_USABLE_MON;
}

u8 GetMonsStateToDoubles_2(void)
{
    s32 aliveCount = 0;
    s32 i;

    for (i = 0; i < 6; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2, NULL);
        if (species != SPECIES_EGG && species != SPECIES_NONE
         && GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL) != 0)
            aliveCount++;
    }

    if (aliveCount == 1)
        return PLAYER_HAS_ONE_MON; // may have more than one, but only one is alive

    return (aliveCount > 1) ? PLAYER_HAS_TWO_USABLE_MONS : PLAYER_HAS_ONE_USABLE_MON;
}

u8 GetAbilityBySpecies(u16 species, bool8 altAbility)
{
    if (altAbility)
        gLastUsedAbility = gBaseStats[species].ability2;
    else
        gLastUsedAbility = gBaseStats[species].ability1;

    return gLastUsedAbility;
}

u8 GetMonAbility(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 altAbility = GetMonData(mon, MON_DATA_ALT_ABILITY, NULL);
    return GetAbilityBySpecies(species, altAbility);
}

extern const struct BattleMove gBattleMoves[];

void CreateSecretBaseEnemyParty(struct SecretBaseRecord *secretBaseRecord)
{
    s32 i, j;

    ZeroEnemyPartyMons();
    *gBattleResources->secretBase = *secretBaseRecord;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gBattleResources->secretBase->partySpecies[i])
        {
            CreateMon(&gEnemyParty[i],
                gBattleResources->secretBase->partySpecies[i],
                gBattleResources->secretBase->partyLevels[i],
                15,
                1,
                gBattleResources->secretBase->partyPersonality[i],
                2,
                0);

            SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleResources->secretBase->partyHeldItems[i]);

            for (j = 0; j < 6; j++)
                SetMonData(&gEnemyParty[i], MON_DATA_HP_EV + j, &gBattleResources->secretBase->partyEVs[i]);

            for (j = 0; j < 4; j++)
            {
                SetMonData(&gEnemyParty[i], MON_DATA_MOVE1 + j, &gBattleResources->secretBase->partyMoves[i * 4 + j]);
                SetMonData(&gEnemyParty[i], MON_DATA_PP1 + j, &gBattleMoves[gBattleResources->secretBase->partyMoves[i * 4 + j]].pp);
            }
        }
    }
}

extern const u8 gUnknown_0831F578[];
extern const u8 gTrainerClassToNameIndex[];
extern const u8 gSecretBaseTrainerClasses[][5];

u8 GetSecretBaseTrainerPicIndex(void)
{
    u8 trainerClass = gSecretBaseTrainerClasses[gBattleResources->secretBase->gender][gBattleResources->secretBase->trainerId[0] % 5];
    return gUnknown_0831F578[trainerClass];
}

u8 GetSecretBaseTrainerNameIndex(void)
{
    u8 trainerClass = gSecretBaseTrainerClasses[gBattleResources->secretBase->gender][gBattleResources->secretBase->trainerId[0] % 5];
    return gTrainerClassToNameIndex[trainerClass];
}

bool8 IsPlayerPartyAndPokemonStorageFull(void)
{
    s32 i;

    for (i = 0; i < 6; i++)
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            return FALSE;

    return IsPokemonStorageFull();
}

extern u32 GetBoxMonDataFromAnyBox(u8 boxNo, u8 boxPos, s32 field);

bool8 IsPokemonStorageFull(void)
{
    s32 i, j;

    for (i = 0; i < 14; i++)
        for (j = 0; j < 30; j++)
            if (GetBoxMonDataFromAnyBox(i, j, MON_DATA_SPECIES) == SPECIES_NONE)
                return FALSE;

    return TRUE;
}

extern const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1];

void GetSpeciesName(u8 *name, u16 species)
{
    s32 i;

    for (i = 0; i <= POKEMON_NAME_LENGTH; i++)
    {
        if (species > NUM_SPECIES)
            name[i] = gSpeciesNames[0][i];
        else
            name[i] = gSpeciesNames[species][i];

        if (name[i] == EOS)
            break;
    }

    name[i] = EOS;
}

extern const u8 gUnknown_08329D22[];
extern const u8 gUnknown_08329D26[];

u8 CalculatePPWithBonus(u16 move, u8 ppBonuses, u8 moveIndex)
{
    u8 basePP = gBattleMoves[move].pp;
    return basePP + ((basePP * 20 * ((gUnknown_08329D22[moveIndex] & ppBonuses) >> (2 * moveIndex))) / 100);
}

void RemoveMonPPBonus(struct Pokemon *mon, u8 moveIndex)
{
    u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
    ppBonuses &= gUnknown_08329D26[moveIndex];
    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);
}

void RemoveBattleMonPPBonus(struct BattlePokemon *mon, u8 moveIndex)
{
    mon->ppBonuses &= gUnknown_08329D26[moveIndex];
}

void sub_803FA70(u8 bank);
void ClearTemporarySpeciesSpriteData(u8 bank, bool8);

extern struct BattlePokemon gBattleMons[4];

void CopyPlayerPartyMonToBattleData(u8 bank, u8 partyIndex)
{
    u16* hpSwitchout;
    s32 i;
    u8 nickname[POKEMON_NAME_LENGTH * 2];

    gBattleMons[bank].species = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES, NULL);
    gBattleMons[bank].item = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HELD_ITEM, NULL);

    for (i = 0; i < 4; i++)
    {
        gBattleMons[bank].moves[i] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE1 + i, NULL);
        gBattleMons[bank].pp[i] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PP1 + i, NULL);
    }

    gBattleMons[bank].ppBonuses = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PP_BONUSES, NULL);
    gBattleMons[bank].friendship = GetMonData(&gPlayerParty[partyIndex], MON_DATA_FRIENDSHIP, NULL);
    gBattleMons[bank].experience = GetMonData(&gPlayerParty[partyIndex], MON_DATA_EXP, NULL);
    gBattleMons[bank].hpIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HP_IV, NULL);
    gBattleMons[bank].attackIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_ATK_IV, NULL);
    gBattleMons[bank].defenseIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_DEF_IV, NULL);
    gBattleMons[bank].speedIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPEED_IV, NULL);
    gBattleMons[bank].spAttackIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPATK_IV, NULL);
    gBattleMons[bank].spDefenseIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPDEF_IV, NULL);
    gBattleMons[bank].personality = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PERSONALITY, NULL);
    gBattleMons[bank].status1 = GetMonData(&gPlayerParty[partyIndex], MON_DATA_STATUS, NULL);
    gBattleMons[bank].level = GetMonData(&gPlayerParty[partyIndex], MON_DATA_LEVEL, NULL);
    gBattleMons[bank].hp = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HP, NULL);
    gBattleMons[bank].maxHP = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MAX_HP, NULL);
    gBattleMons[bank].attack = GetMonData(&gPlayerParty[partyIndex], MON_DATA_ATK, NULL);
    gBattleMons[bank].defense = GetMonData(&gPlayerParty[partyIndex], MON_DATA_DEF, NULL);
    gBattleMons[bank].speed = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPEED, NULL);
    gBattleMons[bank].spAttack = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPATK, NULL);
    gBattleMons[bank].spDefense = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPDEF, NULL);
    gBattleMons[bank].isEgg = GetMonData(&gPlayerParty[partyIndex], MON_DATA_IS_EGG, NULL);
    gBattleMons[bank].altAbility = GetMonData(&gPlayerParty[partyIndex], MON_DATA_ALT_ABILITY, NULL);
    gBattleMons[bank].otId = GetMonData(&gPlayerParty[partyIndex], MON_DATA_OT_ID, NULL);
    gBattleMons[bank].type1 = gBaseStats[gBattleMons[bank].species].type1;
    gBattleMons[bank].type2 = gBaseStats[gBattleMons[bank].species].type2;
    gBattleMons[bank].ability = GetAbilityBySpecies(gBattleMons[bank].species, gBattleMons[bank].altAbility);
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_NICKNAME, nickname);
    StringCopy10(gBattleMons[bank].nickname, nickname);
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_OT_NAME, gBattleMons[bank].otName);

    hpSwitchout = &gBattleStruct->hpOnSwitchout[GetBankSide(bank)];
    *hpSwitchout = gBattleMons[bank].hp;

    for (i = 0; i < 8; i++)
        gBattleMons[bank].statStages[i] = 6;

    gBattleMons[bank].status2 = 0;
    sub_803FA70(bank);
    ClearTemporarySpeciesSpriteData(bank, FALSE);
}
