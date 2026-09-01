#include "global.h"
#include "data.h"
#include "event_data.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_size_record.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "text.h"
#include "constants/party_menu.h"
#include "constants/pokemon_size_record.h"

#define DEFAULT_MAX_SIZE 0x8000 // was 0x8100 in Ruby/Sapphire
#define DEFAULT_MAX_SIZE_MAGIKARP 0
static u8* ReturnHeightStringNoWhitespace(u32 size);

struct UnknownStruct
{
    u16 unk0;
    u8 unk2;
    u16 unk4;
};

static const struct UnknownStruct sBigMonSizeTable[] =
{
    {  290,   1,      0 },
    {  300,   1,     10 },
    {  400,   2,    110 },
    {  500,   4,    310 },
    {  600,  20,    710 },
    {  700,  50,   2710 },
    {  800, 100,   7710 },
    {  900, 150,  17710 },
    { 1000, 150,  32710 },
    { 1100, 100, -17826 },
    { 1200,  50,  -7826 },
    { 1300,  20,  -2826 },
    { 1400,   5,   -826 },
    { 1500,   2,   -326 },
    { 1600,   1,   -126 },
    { 1700,   1,   -26 },
};

enum
{
    POKEMON_NONE,
    POKEMON_INCORRECT_SPECIES,
    POKEMON_SIZE_SMALLER,
    POKEMON_SIZE_LARGER
};

extern const u8 gText_DecimalPoint[];
extern const u8 gText_Marco[];

static u32 GetBoxMonSizeHash(struct BoxPokemon *pkmn)
{
    u16 personality = GetBoxMonData(pkmn, MON_DATA_PERSONALITY);
    u16 hpIV = GetBoxMonData(pkmn, MON_DATA_HP_IV) & 0xF;
    u16 attackIV = GetBoxMonData(pkmn, MON_DATA_ATK_IV) & 0xF;
    u16 defenseIV = GetBoxMonData(pkmn, MON_DATA_DEF_IV) & 0xF;
    u16 speedIV = GetBoxMonData(pkmn, MON_DATA_SPEED_IV) & 0xF;
    u16 spAtkIV = GetBoxMonData(pkmn, MON_DATA_SPATK_IV) & 0xF;
    u16 spDefIV = GetBoxMonData(pkmn, MON_DATA_SPDEF_IV) & 0xF;
    u32 hibyte = ((attackIV ^ defenseIV) * hpIV) ^ (personality & 0xFF);
    u32 lobyte = ((spAtkIV ^ spDefIV) * speedIV) ^ (personality >> 8);

    return (hibyte << 8) + lobyte;
}

static u8 TranslateBigMonSizeTableIndex(u16 a)
{
    u8 i;

    for (i = 1; i < 15; i++)
    {
        if (a < sBigMonSizeTable[i].unk4)
            return i - 1;
    }
    return i;
}

static u32 GetMonSize(enum Species species, u16 b)
{
    u64 unk2;
    u64 unk4;
    u64 unk0;
    u32 height;
    u32 var;

    height = GetSpeciesHeight(species);
    var = TranslateBigMonSizeTableIndex(b);
    unk0 = sBigMonSizeTable[var].unk0;
    unk2 = sBigMonSizeTable[var].unk2;
    unk4 = sBigMonSizeTable[var].unk4;
    unk0 += (b - unk4) / unk2;
    return height * unk0 / 10;
}

static void FormatMonSizeRecord(u8 *string, u32 size)
{
    size = (f64)(size / 100);
    StringCopy(string,ReturnHeightStringNoWhitespace(size));
}

static u8* ReturnHeightStringNoWhitespace(u32 size)
{
    u8* heightStr = ConvertMonHeightToString(size);
    u32 length = StringLength(heightStr);
    u32 i =  0, j =  0;

    while (i < length && !(heightStr[i] >= CHAR_0 && heightStr[i] <= CHAR_9))
        i++;

    while (i < length)
        heightStr[j++] = heightStr[i++];

    heightStr[j] = EOS;
    return heightStr;
}

static u8 CompareMonSize(enum Species species, u16 *sizeRecord)
{
    if (gSpecialVar_Result == PARTY_NOTHING_CHOSEN)
    {
        return POKEMON_NONE;
    }

    struct BoxPokemon *boxmon = GetSelectedBoxMonFromPcOrParty();
    if (GetBoxMonData(boxmon, MON_DATA_IS_EGG) == TRUE || GetBoxMonData(boxmon, MON_DATA_SPECIES) != species)
    {
        return POKEMON_INCORRECT_SPECIES;
    }
    else
    {
        u32 oldSize;
        u32 newSize;
        u16 sizeParams;

        *(&sizeParams) = GetBoxMonSizeHash(boxmon);
        newSize = GetMonSize(species, sizeParams);
        oldSize = GetMonSize(species, *sizeRecord);
        FormatMonSizeRecord(gStringVar2, newSize);
        if (newSize <= oldSize)
        {
            return POKEMON_SIZE_SMALLER;
        }
        else
        {
            *sizeRecord = sizeParams;
            return POKEMON_SIZE_LARGER;
        }
    }
}

// Stores species name in gStringVar1, trainer's name in gStringVar2, and size in gStringVar3
static void GetMonSizeRecordInfo(enum Species species, u16 *sizeRecord)
{
    u32 size = GetMonSize(species, *sizeRecord);

    FormatMonSizeRecord(gStringVar3, size);
    StringCopy(gStringVar1, GetSpeciesName(species));

    if (species == SPECIES_MAGIKARP)
        return;

    if (*sizeRecord == DEFAULT_MAX_SIZE)
        StringCopy(gStringVar2, gText_Marco);
    else
        StringCopy(gStringVar2, gSaveBlock2Ptr->playerName);
}

void InitSeedotSizeRecord(void)
{
    VarSet(VAR_SEEDOT_SIZE_RECORD, DEFAULT_MAX_SIZE);
}

void GetSeedotSizeRecordInfo(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_SEEDOT_SIZE_RECORD);

    GetMonSizeRecordInfo(SPECIES_SEEDOT, sizeRecord);
}

void CompareSeedotSize(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_SEEDOT_SIZE_RECORD);

    gSpecialVar_Result = CompareMonSize(SPECIES_SEEDOT, sizeRecord);
}

void InitLotadSizeRecord(void)
{
    VarSet(VAR_LOTAD_SIZE_RECORD, DEFAULT_MAX_SIZE);
}

void GetLotadSizeRecordInfo(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_LOTAD_SIZE_RECORD);

    GetMonSizeRecordInfo(SPECIES_LOTAD, sizeRecord);
}

void CompareLotadSize(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_LOTAD_SIZE_RECORD);

    gSpecialVar_Result = CompareMonSize(SPECIES_LOTAD, sizeRecord);
}

void GetHeracrossSizeRecordInfo(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_HERACROSS_SIZE_RECORD);

    GetMonSizeRecordInfo(SPECIES_HERACROSS, sizeRecord);
}

void CompareHeracrossSize(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_HERACROSS_SIZE_RECORD);

    gSpecialVar_Result = CompareMonSize(SPECIES_HERACROSS, sizeRecord);
}

void GetMagikarpSizeRecordInfo(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_MAGIKARP_SIZE_RECORD);

    GetMonSizeRecordInfo(SPECIES_MAGIKARP, sizeRecord);
}

void CompareMagikarpSize(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_MAGIKARP_SIZE_RECORD);

    gSpecialVar_Result = CompareMonSize(SPECIES_MAGIKARP, sizeRecord);
}
