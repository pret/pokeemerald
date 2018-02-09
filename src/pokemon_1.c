#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "random.h"
#include "main.h"
#include "constants/species.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/trainers.h"
#include "constants/moves.h"
#include "string_util.h"
#include "text.h"
#include "link.h"
#include "event_data.h"

//Extracts the upper 16 bits of a 32-bit number
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)

//Extracts the lower 16 bits of a 32-bit number
#define LOHALF(n) ((n) & 0xFFFF)

extern u32 gBattleTypeFlags;
extern u8 gUnknown_0203C7B4;
extern u16 gMoveToLearn;

extern const struct UnknownPokemonStruct3 gUnknown_08610970[];
extern const u16 gUnknown_08329D48[];
extern const u16 gUnknown_08329D54[];
extern const struct BattleMove gBattleMoves[];

extern u8 sav1_map_get_name(void);
extern const u8 *sub_81A1650(u8, u8 language);
extern u8 BattleFrontierGetOpponentLvl(u8);
extern u16 sub_806EFF0(u16);

// this file's functions
union PokemonSubstruct *GetSubstruct(struct BoxPokemon *boxMon, u32 personality, u8 substructType);

// EWRAM vars
EWRAM_DATA u8 sLearningMoveTableID = 0;
EWRAM_DATA u8 gPlayerPartyCount = 0;
EWRAM_DATA u8 gEnemyPartyCount = 0;
EWRAM_DATA struct Pokemon gPlayerParty[PARTY_SIZE] = {0};
EWRAM_DATA struct Pokemon gEnemyParty[PARTY_SIZE] = {0};

// const rom data
const u16 gSpeciesToHoennPokedexNum[] = {203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 156, 157, 112, 113, 227, 228, 229, 230, 231, 232, 233, 234, 153, 154, 138, 139, 63, 64, 88, 89, 90, 235, 236, 237, 238, 239, 240, 241, 242, 158, 159, 243, 244, 245, 246, 247, 248, 249, 39, 40, 41, 73, 74, 75, 250, 251, 252, 66, 67, 57, 58, 59, 253, 254, 255, 256, 82, 83, 257, 92, 93, 258, 259, 106, 107, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 84, 85, 270, 271, 272, 273, 274, 275, 276, 108, 109, 169, 170, 277, 278, 279, 184, 185, 50, 51, 143, 144, 280, 281, 282, 283, 284, 167, 285, 52, 53, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 65, 181, 182, 155, 324, 137, 325, 326, 162, 163, 327, 328, 329, 91, 55, 56, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 161, 164, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 168, 357, 358, 359, 103, 104, 360, 361, 180, 362, 363, 364, 365, 115, 366, 367, 186, 165, 166, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 42, 43, 44, 25, 26, 34, 35, 114, 27, 28, 32, 33, 99, 100, 61, 62, 145, 131, 132, 60, 105, 68, 127, 128, 183, 129, 130, 140, 141, 97, 98, 116, 117, 118, 48, 49, 78, 79, 101, 102, 173, 174, 175, 119, 120, 171, 172, 125, 126, 54, 110, 111, 80, 81, 69, 76, 77, 121, 122, 160, 148, 149, 94, 36, 37, 38, 95, 96, 150, 45, 46, 47, 176, 177, 178, 152, 146, 147, 124, 123, 179, 70, 71, 72, 142, 86, 87, 133, 134, 135, 136, 29, 30, 31, 187, 188, 189, 190, 191, 192, 193, 194, 195, 198, 199, 200, 196, 197, 201, 202, 151};
const u16 gSpeciesToNationalPokedexNum[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 290, 291, 292, 276, 277, 285, 286, 327, 278, 279, 283, 284, 320, 321, 300, 301, 352, 343, 344, 299, 324, 302, 339, 340, 370, 341, 342, 349, 350, 318, 319, 328, 329, 330, 296, 297, 309, 310, 322, 323, 363, 364, 365, 331, 332, 361, 362, 337, 338, 298, 325, 326, 311, 312, 303, 307, 308, 333, 334, 360, 355, 356, 315, 287, 288, 289, 316, 317, 357, 293, 294, 295, 366, 367, 368, 359, 353, 354, 336, 335, 369, 304, 305, 306, 351, 313, 314, 345, 346, 347, 348, 280, 281, 282, 371, 372, 373, 374, 375, 376, 377, 378, 379, 382, 383, 384, 380, 381, 385, 386, 358};
const u16 gHoennToNationalOrder[] = {252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 63, 64, 65, 290, 291, 292, 293, 294, 295, 296, 297, 118, 119, 129, 130, 298, 183, 184, 74, 75, 76, 299, 300, 301, 41, 42, 169, 72, 73, 302, 303, 304, 305, 306, 66, 67, 68, 307, 308, 309, 310, 311, 312, 81, 82, 100, 101, 313, 314, 43, 44, 45, 182, 84, 85, 315, 316, 317, 318, 319, 320, 321, 322, 323, 218, 219, 324, 88, 89, 109, 110, 325, 326, 27, 28, 327, 227, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 174, 39, 40, 349, 350, 351, 120, 121, 352, 353, 354, 355, 356, 357, 358, 359, 37, 38, 172, 25, 26, 54, 55, 360, 202, 177, 178, 203, 231, 232, 127, 214, 111, 112, 361, 362, 363, 364, 365, 366, 367, 368, 369, 222, 170, 171, 370, 116, 117, 230, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 29, 30, 31, 32, 33, 34, 35, 36, 46, 47, 48, 49, 50, 51, 52, 53, 56, 57, 58, 59, 60, 61, 62, 69, 70, 71, 77, 78, 79, 80, 83, 86, 87, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 102, 103, 104, 105, 106, 107, 108, 113, 114, 115, 122, 123, 124, 125, 126, 128, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 173, 175, 176, 179, 180, 181, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 215, 216, 217, 220, 221, 223, 224, 225, 226, 228, 229, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411};

const struct SpindaSpot gSpindaSpotGraphics[] =
{
    {16, 7, INCBIN_U16("graphics/spinda_spots/spot_0.bin")},
    {40, 8, INCBIN_U16("graphics/spinda_spots/spot_1.bin")},
    {22, 25, INCBIN_U16("graphics/spinda_spots/spot_2.bin")},
    {34, 26, INCBIN_U16("graphics/spinda_spots/spot_3.bin")}
};

#include "data/pokemon/item_effects.h"

const s8 gNatureStatTable[][5] =
{
    // Atk Def Spd Sp.Atk Sp.Def
    {    0,  0,  0,     0,     0}, // Hardy
    {   +1, -1,  0,     0,     0}, // Lonely
    {   +1,  0, -1,     0,     0}, // Brave
    {   +1,  0,  0,    -1,     0}, // Adamant
    {   +1,  0,  0,     0,    -1}, // Naughty
    {   -1, +1,  0,     0,     0}, // Bold
    {    0,  0,  0,     0,     0}, // Docile
    {    0, +1, -1,     0,     0}, // Relaxed
    {    0, +1,  0,    -1,     0}, // Impish
    {    0, +1,  0,     0,    -1}, // Lax
    {   -1,  0, +1,     0,     0}, // Timid
    {    0, -1, +1,     0,     0}, // Hasty
    {    0,  0,  0,     0,     0}, // Serious
    {    0,  0, +1,    -1,     0}, // Jolly
    {    0,  0, +1,     0,    -1}, // Naive
    {   -1,  0,  0,    +1,     0}, // Modest
    {    0, -1,  0,    +1,     0}, // Mild
    {    0,  0, -1,    +1,     0}, // Quiet
    {    0,  0,  0,     0,     0}, // Bashful
    {    0,  0,  0,    +1,    -1}, // Rash
    {   -1,  0,  0,     0,    +1}, // Calm
    {    0, -1,  0,     0,    +1}, // Gentle
    {    0,  0, -1,     0,    +1}, // Sassy
    {    0,  0,  0,    -1,    +1}, // Careful
    {    0,  0,  0,     0,     0}, // Quirky
};

#include "data/pokemon/tmhm_learnsets.h"
#include "data/pokemon/trainer_class_lookups.h"
#include "data/pokemon/cry_ids.h"
#include "data/pokemon/experience_tables.h"
#include "data/pokemon/base_stats.h"
#include "data/pokemon/level_up_learnsets.h"
#include "data/pokemon/evolution.h"
#include "data/pokemon/level_up_learnset_pointers.h"

// code
void ZeroBoxMonData(struct BoxPokemon *boxMon)
{
    u8 *raw = (u8 *)boxMon;
    u32 i;
    for (i = 0; i < sizeof(struct BoxPokemon); i++)
        raw[i] = 0;
}

void ZeroMonData(struct Pokemon *mon)
{
    u32 arg;
    ZeroBoxMonData(&mon->box);
    arg = 0;
    SetMonData(mon, MON_DATA_STATUS, &arg);
    SetMonData(mon, MON_DATA_LEVEL, &arg);
    SetMonData(mon, MON_DATA_HP, &arg);
    SetMonData(mon, MON_DATA_MAX_HP, &arg);
    SetMonData(mon, MON_DATA_ATK, &arg);
    SetMonData(mon, MON_DATA_DEF, &arg);
    SetMonData(mon, MON_DATA_SPEED, &arg);
    SetMonData(mon, MON_DATA_SPATK, &arg);
    SetMonData(mon, MON_DATA_SPDEF, &arg);
    arg = 255;
    SetMonData(mon, MON_DATA_MAIL, &arg);
}

void ZeroPlayerPartyMons(void)
{
    s32 i;
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gPlayerParty[i]);
}

void ZeroEnemyPartyMons(void)
{
    s32 i;
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gEnemyParty[i]);
}

void CreateMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u32 arg;
    ZeroMonData(mon);
    CreateBoxMon(&mon->box, species, level, fixedIV, hasFixedPersonality, fixedPersonality, otIdType, fixedOtId);
    SetMonData(mon, MON_DATA_LEVEL, &level);
    arg = 255;
    SetMonData(mon, MON_DATA_MAIL, &arg);
    CalculateMonStats(mon);
}

void CreateBoxMon(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u8 speciesName[POKEMON_NAME_LENGTH + 1];
    u32 personality;
    u32 value;
    u16 checksum;

    ZeroBoxMonData(boxMon);

    if (hasFixedPersonality)
        personality = fixedPersonality;
    else
        personality = Random32();

    SetBoxMonData(boxMon, MON_DATA_PERSONALITY, &personality);

    //Determine original trainer ID
    if (otIdType == OT_ID_RANDOM_NO_SHINY) //Pokemon cannot be shiny
    {
        u32 shinyValue;
        do
        {
            value = Random32();
            shinyValue = HIHALF(value) ^ LOHALF(value) ^ HIHALF(personality) ^ LOHALF(personality);
        } while (shinyValue < 8);
    }
    else if (otIdType == OT_ID_PRESET) //Pokemon has a preset OT ID
    {
        value = fixedOtId;
    }
    else //Player is the OT
    {
        value = gSaveBlock2Ptr->playerTrainerId[0]
              | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
              | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
              | (gSaveBlock2Ptr->playerTrainerId[3] << 24);
    }

    SetBoxMonData(boxMon, MON_DATA_OT_ID, &value);

    checksum = CalculateBoxMonChecksum(boxMon);
    SetBoxMonData(boxMon, MON_DATA_CHECKSUM, &checksum);
    EncryptBoxMon(boxMon);
    GetSpeciesName(speciesName, species);
    SetBoxMonData(boxMon, MON_DATA_NICKNAME, speciesName);
    SetBoxMonData(boxMon, MON_DATA_LANGUAGE, &gGameLanguage);
    SetBoxMonData(boxMon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetBoxMonData(boxMon, MON_DATA_SPECIES, &species);
    SetBoxMonData(boxMon, MON_DATA_EXP, &gExperienceTables[gBaseStats[species].growthRate][level]);
    SetBoxMonData(boxMon, MON_DATA_FRIENDSHIP, &gBaseStats[species].friendship);
    value = sav1_map_get_name();
    SetBoxMonData(boxMon, MON_DATA_MET_LOCATION, &value);
    SetBoxMonData(boxMon, MON_DATA_MET_LEVEL, &level);
    SetBoxMonData(boxMon, MON_DATA_MET_GAME, &gGameVersion);
    value = ITEM_POKE_BALL;
    SetBoxMonData(boxMon, MON_DATA_POKEBALL, &value);
    SetBoxMonData(boxMon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);

    if (fixedIV < 32)
    {
        SetBoxMonData(boxMon, MON_DATA_HP_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_ATK_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_DEF_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPEED_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPATK_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPDEF_IV, &fixedIV);
    }
    else
    {
        u32 iv;
        value = Random();

        iv = value & 0x1F;
        SetBoxMonData(boxMon, MON_DATA_HP_IV, &iv);
        iv = (value & 0x3E0) >> 5;
        SetBoxMonData(boxMon, MON_DATA_ATK_IV, &iv);
        iv = (value & 0x7C00) >> 10;
        SetBoxMonData(boxMon, MON_DATA_DEF_IV, &iv);

        value = Random();

        iv = value & 0x1F;
        SetBoxMonData(boxMon, MON_DATA_SPEED_IV, &iv);
        iv = (value & 0x3E0) >> 5;
        SetBoxMonData(boxMon, MON_DATA_SPATK_IV, &iv);
        iv = (value & 0x7C00) >> 10;
        SetBoxMonData(boxMon, MON_DATA_SPDEF_IV, &iv);
    }

    if (gBaseStats[species].ability2)
    {
        value = personality & 1;
        SetBoxMonData(boxMon, MON_DATA_ALT_ABILITY, &value);
    }

    GiveBoxMonInitialMoveset(boxMon);
}

void CreateMonWithNature(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 nature)
{
    u32 personality;

    do
    {
        personality = Random32();
    }
    while (nature != GetNatureFromPersonality(personality));

    CreateMon(mon, species, level, fixedIV, 1, personality, OT_ID_PLAYER_ID, 0);
}

void CreateMonWithGenderNatureLetter(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 gender, u8 nature, u8 unownLetter)
{
    u32 personality;

    if ((u8)(unownLetter - 1) < 28)
    {
        u16 actualLetter;

        do
        {
            personality = Random32();
            actualLetter = ((((personality & 0x3000000) >> 18) | ((personality & 0x30000) >> 12) | ((personality & 0x300) >> 6) | (personality & 0x3)) % 28);
        }
        while (nature != GetNatureFromPersonality(personality)
            || gender != GetGenderFromSpeciesAndPersonality(species, personality)
            || actualLetter != unownLetter - 1);
    }
    else
    {
        do
        {
            personality = Random32();
        }
        while (nature != GetNatureFromPersonality(personality)
            || gender != GetGenderFromSpeciesAndPersonality(species, personality));
    }

    CreateMon(mon, species, level, fixedIV, 1, personality, OT_ID_PLAYER_ID, 0);
}

// This is only used to create Wally's Ralts.
void CreateMaleMon(struct Pokemon *mon, u16 species, u8 level)
{
    u32 personality;
    u32 otId;

    do
    {
        otId = Random32();
        personality = Random32();
    }
    while (GetGenderFromSpeciesAndPersonality(species, personality) != MON_MALE);
    CreateMon(mon, species, level, 32, 1, personality, OT_ID_PRESET, otId);
}

void CreateMonWithIVsPersonality(struct Pokemon *mon, u16 species, u8 level, u32 ivs, u32 personality)
{
    CreateMon(mon, species, level, 0, 1, personality, OT_ID_PLAYER_ID, 0);
    SetMonData(mon, MON_DATA_IVS, &ivs);
    CalculateMonStats(mon);
}

void CreateMonWithIVsOTID(struct Pokemon *mon, u16 species, u8 level, u8 *ivs, u32 otId)
{
    CreateMon(mon, species, level, 0, 0, 0, OT_ID_PRESET, otId);
    SetMonData(mon, MON_DATA_HP_IV, &ivs[0]);
    SetMonData(mon, MON_DATA_ATK_IV, &ivs[1]);
    SetMonData(mon, MON_DATA_DEF_IV, &ivs[2]);
    SetMonData(mon, MON_DATA_SPEED_IV, &ivs[3]);
    SetMonData(mon, MON_DATA_SPATK_IV, &ivs[4]);
    SetMonData(mon, MON_DATA_SPDEF_IV, &ivs[5]);
    CalculateMonStats(mon);
}

void CreateMonWithEVSpread(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 evSpread)
{
    s32 i;
    s32 statCount = 0;
    u16 evAmount;
    u8 evsBits;

    CreateMon(mon, species, level, fixedIV, 0, 0, 0, 0);

    evsBits = evSpread;

    for (i = 0; i < NUM_STATS; i++)
    {
        if (evsBits & 1)
            statCount++;
        evsBits >>= 1;
    }

    evAmount = MAX_TOTAL_EVS / statCount;

    evsBits = 1;

    for (i = 0; i < NUM_STATS; i++)
    {
        if (evSpread & evsBits)
            SetMonData(mon, MON_DATA_HP_EV + i, &evAmount);
        evsBits <<= 1;
    }

    CalculateMonStats(mon);
}

void sub_806819C(struct Pokemon *mon, struct UnknownPokemonStruct *src)
{
    s32 i;
    u8 nickname[30];
    u8 language;
    u8 value;

    CreateMon(mon, src->species, src->level, 0, 1, src->personality, 1, src->otId);

    for (i = 0; i < 4; i++)
        SetMonMoveSlot(mon, src->moves[i], i);

    SetMonData(mon, MON_DATA_PP_BONUSES, &src->ppBonuses);
    SetMonData(mon, MON_DATA_HELD_ITEM, &src->heldItem);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &src->friendship);

    StringCopy(nickname, src->nickname);

    if (nickname[0] == EXT_CTRL_CODE_BEGIN && nickname[1] == EXT_CTRL_CODE_JPN)
    {
        language = LANGUAGE_JAPANESE;
        StripExtCtrlCodes(nickname);
    }
    else
    {
        language = GAME_LANGUAGE;
    }

    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    SetMonData(mon, MON_DATA_NICKNAME, nickname);
    SetMonData(mon, MON_DATA_HP_EV, &src->hpEV);
    SetMonData(mon, MON_DATA_ATK_EV, &src->attackEV);
    SetMonData(mon, MON_DATA_DEF_EV, &src->defenseEV);
    SetMonData(mon, MON_DATA_SPEED_EV, &src->speedEV);
    SetMonData(mon, MON_DATA_SPATK_EV, &src->spAttackEV);
    SetMonData(mon, MON_DATA_SPDEF_EV, &src->spDefenseEV);
    value = src->altAbility;
    SetMonData(mon, MON_DATA_ALT_ABILITY, &value);
    value = src->hpIV;
    SetMonData(mon, MON_DATA_HP_IV, &value);
    value = src->attackIV;
    SetMonData(mon, MON_DATA_ATK_IV, &value);
    value = src->defenseIV;
    SetMonData(mon, MON_DATA_DEF_IV, &value);
    value = src->speedIV;
    SetMonData(mon, MON_DATA_SPEED_IV, &value);
    value = src->spAttackIV;
    SetMonData(mon, MON_DATA_SPATK_IV, &value);
    value = src->spDefenseIV;
    SetMonData(mon, MON_DATA_SPDEF_IV, &value);
    MonRestorePP(mon);
    CalculateMonStats(mon);
}

void sub_8068338(struct Pokemon *mon, struct UnknownPokemonStruct *src, bool8 lvl50)
{
    s32 i;
    u8 nickname[30];
    u8 level;
    u8 language;
    u8 value;

    if (gSaveBlock2Ptr->frontierChosenLvl != 0)
        level = BattleFrontierGetOpponentLvl(gSaveBlock2Ptr->frontierChosenLvl);
    else if (lvl50)
        level = 50;
    else
        level = src->level;

    CreateMon(mon, src->species, level, 0, 1, src->personality, 1, src->otId);

    for (i = 0; i < 4; i++)
        SetMonMoveSlot(mon, src->moves[i], i);

    SetMonData(mon, MON_DATA_PP_BONUSES, &src->ppBonuses);
    SetMonData(mon, MON_DATA_HELD_ITEM, &src->heldItem);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &src->friendship);

    StringCopy(nickname, src->nickname);

    if (nickname[0] == EXT_CTRL_CODE_BEGIN && nickname[1] == EXT_CTRL_CODE_JPN)
    {
        language = LANGUAGE_JAPANESE;
        StripExtCtrlCodes(nickname);
    }
    else
    {
        language = GAME_LANGUAGE;
    }

    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    SetMonData(mon, MON_DATA_NICKNAME, nickname);
    SetMonData(mon, MON_DATA_HP_EV, &src->hpEV);
    SetMonData(mon, MON_DATA_ATK_EV, &src->attackEV);
    SetMonData(mon, MON_DATA_DEF_EV, &src->defenseEV);
    SetMonData(mon, MON_DATA_SPEED_EV, &src->speedEV);
    SetMonData(mon, MON_DATA_SPATK_EV, &src->spAttackEV);
    SetMonData(mon, MON_DATA_SPDEF_EV, &src->spDefenseEV);
    value = src->altAbility;
    SetMonData(mon, MON_DATA_ALT_ABILITY, &value);
    value = src->hpIV;
    SetMonData(mon, MON_DATA_HP_IV, &value);
    value = src->attackIV;
    SetMonData(mon, MON_DATA_ATK_IV, &value);
    value = src->defenseIV;
    SetMonData(mon, MON_DATA_DEF_IV, &value);
    value = src->speedIV;
    SetMonData(mon, MON_DATA_SPEED_IV, &value);
    value = src->spAttackIV;
    SetMonData(mon, MON_DATA_SPATK_IV, &value);
    value = src->spDefenseIV;
    SetMonData(mon, MON_DATA_SPDEF_IV, &value);
    MonRestorePP(mon);
    CalculateMonStats(mon);
}

void sub_8068528(struct Pokemon *mon, const struct UnknownPokemonStruct2 *src, u8 monId)
{
    s32 i;
    u16 evAmount;
    u8 language;
    u32 otId = gUnknown_08610970[src->field_0_0].field_30;
    u32 personality = ((gUnknown_08610970[src->field_0_0].field_30 >> 8) | ((gUnknown_08610970[src->field_0_0].field_30 & 0xFF) << 8))
                    + src->mons[monId].species + src->field_2;

    CreateMon(mon,
              src->mons[monId].species,
              BattleFrontierGetOpponentLvl(src->field_0_1 - 1),
              0x1F,
              TRUE,
              personality,
              TRUE,
              otId);

    SetMonData(mon, MON_DATA_HELD_ITEM, &src->mons[monId].item);
    for (i = 0; i < 4; i++)
        SetMonMoveSlot(mon, src->mons[monId].moves[i], i);

    evAmount = MAX_TOTAL_EVS / NUM_STATS;
    for (i = 0; i < NUM_STATS; i++)
        SetMonData(mon, MON_DATA_HP_EV + i, &evAmount);

    language = src->language;
    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    SetMonData(mon, MON_DATA_OT_NAME, sub_81A1650(src->field_0_0, language));
    CalculateMonStats(mon);
}

void CreateMonWithEVSpreadPersonalityOTID(struct Pokemon *mon, u16 species, u8 level, u8 nature, u8 fixedIV, u8 evSpread, u32 otId)
{
    s32 i;
    s32 statCount = 0;
    u8 evsBits;
    u16 evAmount;

    // i is reused as personality value
    do
    {
        i = Random32();
    } while (nature != GetNatureFromPersonality(i));

    CreateMon(mon, species, level, fixedIV, TRUE, i, TRUE, otId);
    evsBits = evSpread;
    for (i = 0; i < NUM_STATS; i++)
    {
        if (evsBits & 1)
            statCount++;
        evsBits >>= 1;
    }

    evAmount = MAX_TOTAL_EVS / statCount;
    evsBits = 1;
    for (i = 0; i < NUM_STATS; i++)
    {
        if (evSpread & evsBits)
            SetMonData(mon, MON_DATA_HP_EV + i, &evAmount);
        evsBits <<= 1;
    }

    CalculateMonStats(mon);
}

void sub_80686FC(struct Pokemon *mon, struct UnknownPokemonStruct *dest)
{
    s32 i;
    u16 heldItem;

    dest->species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);

    if (heldItem == ITEM_ENIGMA_BERRY)
        heldItem = 0;

    dest->heldItem = heldItem;

    for (i = 0; i < 4; i++)
        dest->moves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, NULL);

    dest->level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    dest->ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
    dest->otId = GetMonData(mon, MON_DATA_OT_ID, NULL);
    dest->hpEV = GetMonData(mon, MON_DATA_HP_EV, NULL);
    dest->attackEV = GetMonData(mon, MON_DATA_ATK_EV, NULL);
    dest->defenseEV = GetMonData(mon, MON_DATA_DEF_EV, NULL);
    dest->speedEV = GetMonData(mon, MON_DATA_SPEED_EV, NULL);
    dest->spAttackEV = GetMonData(mon, MON_DATA_SPATK_EV, NULL);
    dest->spDefenseEV = GetMonData(mon, MON_DATA_SPDEF_EV, NULL);
    dest->friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
    dest->hpIV = GetMonData(mon, MON_DATA_HP_IV, NULL);
    dest->attackIV = GetMonData(mon, MON_DATA_ATK_IV, NULL);
    dest->defenseIV = GetMonData(mon, MON_DATA_DEF_IV, NULL);
    dest->speedIV  = GetMonData(mon, MON_DATA_SPEED_IV, NULL);
    dest->spAttackIV  = GetMonData(mon, MON_DATA_SPATK_IV, NULL);
    dest->spDefenseIV  = GetMonData(mon, MON_DATA_SPDEF_IV, NULL);
    dest->altAbility = GetMonData(mon, MON_DATA_ALT_ABILITY, NULL);
    dest->personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    GetMonData(mon, MON_DATA_NICKNAME, dest->nickname);
}

void CreateObedientMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    bool32 obedient = TRUE;

    CreateMon(mon, species, level, fixedIV, hasFixedPersonality, fixedPersonality, otIdType, fixedOtId);
    SetMonData(mon, MON_DATA_OBEDIENCE, &obedient);
}

bool8 sub_80688F8(u8 caseId, u8 battlerId)
{
    switch (caseId)
    {
    case 0:
    default:
        return FALSE;
    case 1:
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            return FALSE;
        if (!gMain.inBattle)
            return FALSE;
        if (gLinkPlayers[GetMultiplayerId()].lp_field_18 == battlerId)
            return FALSE;
        break;
    case 2:
        break;
    case 3:
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            return FALSE;
        if (!gMain.inBattle)
            return FALSE;
        if (battlerId == 1 || battlerId == 4 || battlerId == 5)
            return TRUE;
        return FALSE;
    case 4:
        break;
    case 5:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (!gMain.inBattle)
                return FALSE;
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                if (gLinkPlayers[GetMultiplayerId()].lp_field_18 == battlerId)
                    return FALSE;
            }
            else
            {
                if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
                    return FALSE;
            }
        }
        else
        {
            if (!gMain.inBattle)
                return FALSE;
            if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
                return FALSE;
        }
        break;
    }

    return TRUE;
}

s32 GetDeoxysStat(struct Pokemon *mon, s32 statId)
{
    s32 ivVal, evVal;
    s32 statValue;
    u8 nature, statId_;

    if (gBattleTypeFlags & BATTLE_TYPE_20)
        return 0;
    if (GetMonData(mon, MON_DATA_SPECIES, NULL) != SPECIES_DEOXYS)
        return 0;

    ivVal = GetMonData(mon, MON_DATA_HP_IV + statId, NULL);
    evVal = GetMonData(mon, MON_DATA_HP_EV + statId, NULL);
    statValue = (u16)(((gUnknown_08329D48[statId] * 2 + ivVal + evVal / 4) * mon->level) / 100 + 5);

    nature = GetNature(mon);
    statId_ = statId; // needed to match
    statValue = ModifyStatByNature(nature, statValue, statId_);

    return statValue;
}

void SetDeoxysStats(void)
{
    s32 i, value;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];

        if (GetMonData(mon, MON_DATA_SPECIES, NULL) != SPECIES_DEOXYS)
            continue;

        value = GetMonData(mon, MON_DATA_ATK, NULL);
        SetMonData(mon, MON_DATA_ATK, &value);

        value = GetMonData(mon, MON_DATA_DEF, NULL);
        SetMonData(mon, MON_DATA_DEF, &value);

        value = GetMonData(mon, MON_DATA_SPEED, NULL);
        SetMonData(mon, MON_DATA_SPEED, &value);

        value = GetMonData(mon, MON_DATA_SPATK, NULL);
        SetMonData(mon, MON_DATA_SPATK, &value);

        value = GetMonData(mon, MON_DATA_SPDEF, NULL);
        SetMonData(mon, MON_DATA_SPDEF, &value);
    }
}

u16 sub_8068B48(void)
{
    u8 linkId;
    u32 arrId;

    if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
        linkId = gUnknown_0203C7B4 ^ 1;
    else
        linkId = GetMultiplayerId() ^ 1;

    arrId = gLinkPlayers[linkId].trainerId & 7;
    arrId |= gLinkPlayers[linkId].gender << 3;
    return sub_806EFF0(gUnknown_08329D54[arrId]);
}

u16 sub_8068BB0(void)
{
    u8 linkId;
    u32 arrId;

    if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
        linkId = gUnknown_0203C7B4 ^ 1;
    else
        linkId = GetMultiplayerId() ^ 1;

    arrId = gLinkPlayers[linkId].trainerId & 7;
    arrId |= gLinkPlayers[linkId].gender << 3;
    return gFacilityClassToTrainerClass[gUnknown_08329D54[arrId]];
}

void CreateObedientEnemyMon(void)
{
    s32 species = gSpecialVar_0x8004;
    s32 level = gSpecialVar_0x8005;
    s32 itemId = gSpecialVar_0x8006;

    ZeroEnemyPartyMons();
    CreateObedientMon(&gEnemyParty[0], species, level, 32, 0, 0, 0, 0);
    if (itemId)
    {
        u8 heldItem[2];
        heldItem[0] = itemId;
        heldItem[1] = itemId >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }
}

u16 CalculateBoxMonChecksum(struct BoxPokemon *boxMon)
{
    u16 checksum = 0;
    union PokemonSubstruct *substruct0 = GetSubstruct(boxMon, boxMon->personality, 0);
    union PokemonSubstruct *substruct1 = GetSubstruct(boxMon, boxMon->personality, 1);
    union PokemonSubstruct *substruct2 = GetSubstruct(boxMon, boxMon->personality, 2);
    union PokemonSubstruct *substruct3 = GetSubstruct(boxMon, boxMon->personality, 3);
    s32 i;

    for (i = 0; i < 6; i++)
        checksum += substruct0->raw[i];

    for (i = 0; i < 6; i++)
        checksum += substruct1->raw[i];

    for (i = 0; i < 6; i++)
        checksum += substruct2->raw[i];

    for (i = 0; i < 6; i++)
        checksum += substruct3->raw[i];

    return checksum;
}

#define CALC_STAT(base, iv, ev, statIndex, field)               \
{                                                               \
    u8 baseStat = gBaseStats[species].base;                     \
    s32 n = (((2 * baseStat + iv + ev / 4) * level) / 100) + 5; \
    u8 nature = GetNature(mon);                                 \
    n = ModifyStatByNature(nature, n, statIndex);               \
    SetMonData(mon, field, &n);                                 \
}

void CalculateMonStats(struct Pokemon *mon)
{
    s32 oldMaxHP = GetMonData(mon, MON_DATA_MAX_HP, NULL);
    s32 currentHP = GetMonData(mon, MON_DATA_HP, NULL);
    s32 hpIV = GetMonData(mon, MON_DATA_HP_IV, NULL);
    s32 hpEV = GetMonData(mon, MON_DATA_HP_EV, NULL);
    s32 attackIV = GetMonData(mon, MON_DATA_ATK_IV, NULL);
    s32 attackEV = GetMonData(mon, MON_DATA_ATK_EV, NULL);
    s32 defenseIV = GetMonData(mon, MON_DATA_DEF_IV, NULL);
    s32 defenseEV = GetMonData(mon, MON_DATA_DEF_EV, NULL);
    s32 speedIV = GetMonData(mon, MON_DATA_SPEED_IV, NULL);
    s32 speedEV = GetMonData(mon, MON_DATA_SPEED_EV, NULL);
    s32 spAttackIV = GetMonData(mon, MON_DATA_SPATK_IV, NULL);
    s32 spAttackEV = GetMonData(mon, MON_DATA_SPATK_EV, NULL);
    s32 spDefenseIV = GetMonData(mon, MON_DATA_SPDEF_IV, NULL);
    s32 spDefenseEV = GetMonData(mon, MON_DATA_SPDEF_EV, NULL);
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    s32 level = GetLevelFromMonExp(mon);
    s32 newMaxHP;

    SetMonData(mon, MON_DATA_LEVEL, &level);

    if (species == SPECIES_SHEDINJA)
    {
        newMaxHP = 1;
    }
    else
    {
        s32 n = 2 * gBaseStats[species].baseHP + hpIV;
        newMaxHP = (((n + hpEV / 4) * level) / 100) + level + 10;
    }

    gBattleScripting.field_23 = newMaxHP - oldMaxHP;
    if (gBattleScripting.field_23 == 0)
        gBattleScripting.field_23 = 1;

    SetMonData(mon, MON_DATA_MAX_HP, &newMaxHP);

    CALC_STAT(baseAttack, attackIV, attackEV, 1, MON_DATA_ATK)
    CALC_STAT(baseDefense, defenseIV, defenseEV, 2, MON_DATA_DEF)
    CALC_STAT(baseSpeed, speedIV, speedEV, 3, MON_DATA_SPEED)
    CALC_STAT(baseSpAttack, spAttackIV, spAttackEV, 4, MON_DATA_SPATK)
    CALC_STAT(baseSpDefense, spDefenseIV, spDefenseEV, 5, MON_DATA_SPDEF)

    if (species == SPECIES_SHEDINJA)
    {
        if (currentHP != 0 || oldMaxHP == 0)
            currentHP = 1;
        else
            return;
    }
    else
    {
        if (currentHP == 0 && oldMaxHP == 0)
            currentHP = newMaxHP;
        else if (currentHP != 0)
            currentHP += newMaxHP - oldMaxHP;
        else
            return;
    }

    SetMonData(mon, MON_DATA_HP, &currentHP);
}

void BoxMonToMon(const struct BoxPokemon *src, struct Pokemon *dest)
{
    u32 value = 0;
    dest->box = *src;
    SetMonData(dest, MON_DATA_STATUS, &value);
    SetMonData(dest, MON_DATA_HP, &value);
    SetMonData(dest, MON_DATA_MAX_HP, &value);
    value = 255;
    SetMonData(dest, MON_DATA_MAIL, &value);
    CalculateMonStats(dest);
}

u8 GetLevelFromMonExp(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 exp = GetMonData(mon, MON_DATA_EXP, NULL);
    s32 level = 1;

    while (level <= MAX_MON_LEVEL && gExperienceTables[gBaseStats[species].growthRate][level] <= exp)
        level++;

    return level - 1;
}

u8 GetLevelFromBoxMonExp(struct BoxPokemon *boxMon)
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    u32 exp = GetBoxMonData(boxMon, MON_DATA_EXP, NULL);
    s32 level = 1;

    while (level <= MAX_MON_LEVEL && gExperienceTables[gBaseStats[species].growthRate][level] <= exp)
        level++;

    return level - 1;
}

u16 GiveMoveToMon(struct Pokemon *mon, u16 move)
{
    return GiveMoveToBoxMon(&mon->box, move);
}

u16 GiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move)
{
    s32 i;
    for (i = 0; i < 4; i++)
    {
        u16 existingMove = GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, NULL);
        if (!existingMove)
        {
            SetBoxMonData(boxMon, MON_DATA_MOVE1 + i, &move);
            SetBoxMonData(boxMon, MON_DATA_PP1 + i, &gBattleMoves[move].pp);
            return move;
        }
        if (existingMove == move)
            return -2;
    }
    return -1;
}

u16 GiveMoveToBattleMon(struct BattlePokemon *mon, u16 move)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (!mon->moves[i])
        {
            mon->moves[i] = move;
            mon->pp[i] = gBattleMoves[move].pp;
            return move;
        }
    }

    return -1;
}

void SetMonMoveSlot(struct Pokemon *mon, u16 move, u8 slot)
{
    SetMonData(mon, MON_DATA_MOVE1 + slot, &move);
    SetMonData(mon, MON_DATA_PP1 + slot, &gBattleMoves[move].pp);
}

void SetBattleMonMoveSlot(struct BattlePokemon *mon, u16 move, u8 slot)
{
    mon->moves[slot] = move;
    mon->pp[slot] = gBattleMoves[move].pp;
}

void GiveMonInitialMoveset(struct Pokemon *mon)
{
    GiveBoxMonInitialMoveset(&mon->box);
}

void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon)
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    s32 level = GetLevelFromBoxMonExp(boxMon);
    s32 i;

    for (i = 0; gLevelUpLearnsets[species][i] != (u16)-1; i++)
    {
        u16 moveLevel;
        u16 move;

        moveLevel = (gLevelUpLearnsets[species][i] & 0xFE00);

        if (moveLevel > (level << 9))
            break;

        move = (gLevelUpLearnsets[species][i] & 0x1FF);

        if (GiveMoveToBoxMon(boxMon, move) == (u16)-1)
            DeleteFirstMoveAndGiveMoveToBoxMon(boxMon, move);
    }
}

u16 MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove)
{
    u32 retVal = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);

    // since you can learn more than one move per level
    // the game needs to know whether you decided to
    // learn it or keep the old set to avoid asking
    // you to learn the same move over and over again
    if (firstMove)
    {
        sLearningMoveTableID = 0;

        while ((gLevelUpLearnsets[species][sLearningMoveTableID] & 0xFE00) != (level << 9))
        {
            sLearningMoveTableID++;
            if (gLevelUpLearnsets[species][sLearningMoveTableID] == 0xFFFF)
                return 0;
        }
    }

    if ((gLevelUpLearnsets[species][sLearningMoveTableID] & 0xFE00) == (level << 9))
    {
        gMoveToLearn = (gLevelUpLearnsets[species][sLearningMoveTableID] & 0x1FF);
        sLearningMoveTableID++;
        retVal = GiveMoveToMon(mon, gMoveToLearn);
    }

    return retVal;
}

void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, u16 move)
{
    s32 i;
    u16 moves[4];
    u8 pp[4];
    u8 ppBonuses;

    for (i = 0; i < 3; i++)
    {
        moves[i] = GetMonData(mon, MON_DATA_MOVE2 + i, NULL);
        pp[i] = GetMonData(mon, MON_DATA_PP2 + i, NULL);
    }

    ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
    ppBonuses >>= 2;
    moves[3] = move;
    pp[3] = gBattleMoves[move].pp;

    for (i = 0; i < 4; i++)
    {
        SetMonData(mon, MON_DATA_MOVE1 + i, &moves[i]);
        SetMonData(mon, MON_DATA_PP1 + i, &pp[i]);
    }

    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);
}

void DeleteFirstMoveAndGiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move)
{
    s32 i;
    u16 moves[4];
    u8 pp[4];
    u8 ppBonuses;

    for (i = 0; i < 3; i++)
    {
        moves[i] = GetBoxMonData(boxMon, MON_DATA_MOVE2 + i, NULL);
        pp[i] = GetBoxMonData(boxMon, MON_DATA_PP2 + i, NULL);
    }

    ppBonuses = GetBoxMonData(boxMon, MON_DATA_PP_BONUSES, NULL);
    ppBonuses >>= 2;
    moves[3] = move;
    pp[3] = gBattleMoves[move].pp;

    for (i = 0; i < 4; i++)
    {
        SetBoxMonData(boxMon, MON_DATA_MOVE1 + i, &moves[i]);
        SetBoxMonData(boxMon, MON_DATA_PP1 + i, &pp[i]);
    }

    SetBoxMonData(boxMon, MON_DATA_PP_BONUSES, &ppBonuses);
}
