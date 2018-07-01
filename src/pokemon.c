#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_message.h"
#include "random.h"
#include "main.h"
#include "constants/species.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/trainers.h"
#include "constants/moves.h"
#include "constants/hold_effects.h"
#include "constants/battle_move_effects.h"
#include "constants/songs.h"
#include "string_util.h"
#include "text.h"
#include "link.h"
#include "event_data.h"
#include "item.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "evolution_scene.h"
#include "pokemon_animation.h"
#include "pokedex.h"
#include "pokeblock.h"
#include "sound.h"
#include "task.h"
#include "rtc.h"
#include "m4a.h"
#include "malloc.h"
#include "util.h"
#include "strings.h"
#include "pokenav.h"
#include "pokemon_storage_system.h"
#include "recorded_battle.h"

struct SpeciesItem
{
    u16 species;
    u16 item;
};

// Extracts the upper 16 bits of a 32-bit number
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)

// Extracts the lower 16 bits of a 32-bit number
#define LOHALF(n) ((n) & 0xFFFF)

extern const struct OamData gUnknown_0831ACB0;
extern const struct OamData gUnknown_0831ACA8;
extern const struct SpriteFrameImage gUnknown_082FF3A8[];
extern const struct SpriteFrameImage gUnknown_082FF3C8[];
extern const struct SpriteFrameImage gUnknown_082FF3E8[];
extern const struct SpriteFrameImage gUnknown_082FF408[];
extern const struct SpriteFrameImage gUnknown_082FF428[];
extern const struct SpriteFrameImage gUnknown_082FF448[];
extern const struct SpriteFrameImage gUnknown_082FF468[];
extern const struct SpriteFrameImage gUnknown_082FF490[];
extern const struct SpriteFrameImage gUnknown_082FF4B8[];
extern const struct SpriteFrameImage gUnknown_082FF4D8[];
extern const struct SpriteFrameImage gUnknown_082FF4F8[];
extern const struct SpriteFrameImage gUnknown_082FF518[];
extern const union AffineAnimCmd *const gUnknown_082FF618[];
extern const union AffineAnimCmd *const gUnknown_082FF694[];
extern const union AnimCmd *gPlayerMonSpriteAnimsTable[];
extern const union AnimCmd *const *const gMonAnimationsSpriteAnimsPtrTable[];
extern const union AnimCmd *const *const gUnknown_08305D0C[];
extern const union AnimCmd *const *const gUnknown_0830536C[];
extern const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1];
extern const struct UnknownPokemonStruct3 gUnknown_08610970[];
extern const struct CompressedSpritePalette gMonPaletteTable[];
extern const struct CompressedSpritePalette gMonShinyPaletteTable[];
extern const u8 gTrainerClassNames[][13];

extern u8 pokemon_order_func(u8);
extern u16 get_unknown_box_id(void);
extern u8 StorageGetCurrentBox(void);
extern void set_unknown_box_id(u8);
extern void sub_803FA70(u8 battlerId);
extern u8 sav1_map_get_name(void);
extern const u8 *sub_81A1650(u8, u8 language);
extern u8 BattleFrontierGetOpponentLvl(u8);
extern u16 FacilityClassToPicIndex(u16);
extern bool8 InBattlePyramid(void);
extern bool8 InBattlePike(void);
extern bool8 sub_806F104(void);
extern u8 GetTrainerEncounterMusicIdInBattlePyramind(u16 trainerOpponentId);
extern u8 sub_81D63C8(u16 trainerOpponentId);
extern u8 GetFrontierOpponentClass(u16 trainerId);
extern void GetFrontierTrainerName(u8* dest, u16 trainerId);
extern void sub_81C488C(u8);

// this file's functions
static u16 CalculateBoxMonChecksum(struct BoxPokemon *boxMon);
static union PokemonSubstruct *GetSubstruct(struct BoxPokemon *boxMon, u32 personality, u8 substructType);
static void EncryptBoxMon(struct BoxPokemon *boxMon);
static void DecryptBoxMon(struct BoxPokemon *boxMon);
static void sub_806E6CC(u8 taskId);
static bool8 ShouldGetStatBadgeBoost(u16 flagId, u8 battlerId);

// EWRAM vars
EWRAM_DATA static u8 sLearningMoveTableID = 0;
EWRAM_DATA u8 gPlayerPartyCount = 0;
EWRAM_DATA u8 gEnemyPartyCount = 0;
EWRAM_DATA struct Pokemon gPlayerParty[PARTY_SIZE] = {0};
EWRAM_DATA struct Pokemon gEnemyParty[PARTY_SIZE] = {0};
EWRAM_DATA struct SpriteTemplate gMultiuseSpriteTemplate = {0};
EWRAM_DATA struct Unknown_806F160_Struct *gUnknown_020249B4[2] = {NULL};

// const rom data
#include "data/battle_moves.h"
static const u8 sUnreferencedData[] = {0x34, 0x00, 0x10, 0x00, 0x01, 0x01, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00};

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

static const u8 sMonFrontAnimIdsTable[] =
{
    0x06, // SPECIES_BULBASAUR
    0x17, // SPECIES_IVYSAUR
    0x2f, // SPECIES_VENUSAUR
    0x52, // SPECIES_CHARMANDER
    0x25, // SPECIES_CHARMELEON
    0x10, // SPECIES_CHARIZARD
    0x0b, // SPECIES_SQUIRTLE
    0x13, // SPECIES_WARTORTLE
    0x19, // SPECIES_BLASTOISE
    0x0b, // SPECIES_CATERPIE
    0x0b, // SPECIES_METAPOD
    0x1d, // SPECIES_BUTTERFREE
    0x46, // SPECIES_WEEDLE
    0x20, // SPECIES_KAKUNA
    0x02, // SPECIES_BEEDRILL
    0x47, // SPECIES_PIDGEY
    0x17, // SPECIES_PIDGEOTTO
    0x29, // SPECIES_PIDGEOT
    0x43, // SPECIES_RATTATA
    0x2b, // SPECIES_RATICATE
    0x18, // SPECIES_SPEAROW
    0x2b, // SPECIES_FEAROW
    0x16, // SPECIES_EKANS
    0x17, // SPECIES_ARBOK
    0x2c, // SPECIES_PIKACHU
    0x17, // SPECIES_RAICHU
    0x2d, // SPECIES_SANDSHREW
    0x17, // SPECIES_SANDSLASH
    0x00, // SPECIES_NIDORAN_F
    0x17, // SPECIES_NIDORINA
    0x0f, // SPECIES_NIDOQUEEN
    0x09, // SPECIES_NIDORAN_M
    0x13, // SPECIES_NIDORINO
    0x0f, // SPECIES_NIDOKING
    0x00, // SPECIES_CLEFAIRY
    0x4a, // SPECIES_CLEFABLE
    0x17, // SPECIES_VULPIX
    0x10, // SPECIES_NINETALES
    0x48, // SPECIES_JIGGLYPUFF
    0x31, // SPECIES_WIGGLYTUFF
    0x00, // SPECIES_ZUBAT
    0x1d, // SPECIES_GOLBAT
    0x00, // SPECIES_ODDISH
    0x45, // SPECIES_GLOOM
    0x49, // SPECIES_VILEPLUME
    0x46, // SPECIES_PARAS
    0x0f, // SPECIES_PARASECT
    0x06, // SPECIES_VENONAT
    0x4b, // SPECIES_VENOMOTH
    0x10, // SPECIES_DIGLETT
    0x4c, // SPECIES_DUGTRIO
    0x52, // SPECIES_MEOWTH
    0x17, // SPECIES_PERSIAN
    0x06, // SPECIES_PSYDUCK
    0x4c, // SPECIES_GOLDUCK
    0x32, // SPECIES_MANKEY
    0x48, // SPECIES_PRIMEAPE
    0x25, // SPECIES_GROWLITHE
    0x02, // SPECIES_ARCANINE
    0x00, // SPECIES_POLIWAG
    0x32, // SPECIES_POLIWHIRL
    0x19, // SPECIES_POLIWRATH
    0x31, // SPECIES_ABRA
    0x09, // SPECIES_KADABRA
    0x17, // SPECIES_ALAKAZAM
    0x00, // SPECIES_MACHOP
    0x10, // SPECIES_MACHOKE
    0x31, // SPECIES_MACHAMP
    0x17, // SPECIES_BELLSPROUT
    0x0d, // SPECIES_WEEPINBELL
    0x32, // SPECIES_VICTREEBEL
    0x00, // SPECIES_TENTACOOL
    0x00, // SPECIES_TENTACRUEL
    0x48, // SPECIES_GEODUDE
    0x48, // SPECIES_GRAVELER
    0x2f, // SPECIES_GOLEM
    0x20, // SPECIES_PONYTA
    0x11, // SPECIES_RAPIDASH
    0x45, // SPECIES_SLOWPOKE
    0x0b, // SPECIES_SLOWBRO
    0x54, // SPECIES_MAGNEMITE
    0x2c, // SPECIES_MAGNETON
    0x48, // SPECIES_FARFETCHD
    0x4c, // SPECIES_DODUO
    0x41, // SPECIES_DODRIO
    0x0b, // SPECIES_SEEL
    0x45, // SPECIES_DEWGONG
    0x46, // SPECIES_GRIMER
    0x30, // SPECIES_MUK
    0x12, // SPECIES_SHELLDER
    0x1d, // SPECIES_CLOYSTER
    0x15, // SPECIES_GASTLY
    0x35, // SPECIES_HAUNTER
    0x3a, // SPECIES_GENGAR
    0x43, // SPECIES_ONIX
    0x4f, // SPECIES_DROWZEE
    0x09, // SPECIES_HYPNO
    0x03, // SPECIES_KRABBY
    0x4b, // SPECIES_KINGLER
    0x00, // SPECIES_VOLTORB
    0x00, // SPECIES_ELECTRODE
    0x46, // SPECIES_EXEGGCUTE
    0x32, // SPECIES_EXEGGUTOR
    0x48, // SPECIES_CUBONE
    0x05, // SPECIES_MAROWAK
    0x16, // SPECIES_HITMONLEE
    0x09, // SPECIES_HITMONCHAN
    0x45, // SPECIES_LICKITUNG
    0x13, // SPECIES_KOFFING
    0x04, // SPECIES_WEEZING
    0x10, // SPECIES_RHYHORN
    0x13, // SPECIES_RHYDON
    0x45, // SPECIES_CHANSEY
    0x48, // SPECIES_TANGELA
    0x17, // SPECIES_KANGASKHAN
    0x12, // SPECIES_HORSEA
    0x04, // SPECIES_SEADRA
    0x0d, // SPECIES_GOLDEEN
    0x1c, // SPECIES_SEAKING
    0x4e, // SPECIES_STARYU
    0x12, // SPECIES_STARMIE
    0x46, // SPECIES_MR_MIME
    0x02, // SPECIES_SCYTHER
    0x17, // SPECIES_JYNX
    0x2c, // SPECIES_ELECTABUZZ
    0x0f, // SPECIES_MAGMAR
    0x09, // SPECIES_PINSIR
    0x19, // SPECIES_TAUROS
    0x05, // SPECIES_MAGIKARP
    0x48, // SPECIES_GYARADOS
    0x17, // SPECIES_LAPRAS
    0x01, // SPECIES_DITTO
    0x17, // SPECIES_EEVEE
    0x17, // SPECIES_VAPOREON
    0x00, // SPECIES_JOLTEON
    0x17, // SPECIES_FLAREON
    0x52, // SPECIES_PORYGON
    0x51, // SPECIES_OMANYTE
    0x09, // SPECIES_OMASTAR
    0x1d, // SPECIES_KABUTO
    0x0f, // SPECIES_KABUTOPS
    0x47, // SPECIES_AERODACTYL
    0x0b, // SPECIES_SNORLAX
    0x09, // SPECIES_ARTICUNO
    0x2c, // SPECIES_ZAPDOS
    0x45, // SPECIES_MOLTRES
    0x00, // SPECIES_DRATINI
    0x10, // SPECIES_DRAGONAIR
    0x47, // SPECIES_DRAGONITE
    0x09, // SPECIES_MEWTWO
    0x0d, // SPECIES_MEW
    0x00, // SPECIES_CHIKORITA
    0x00, // SPECIES_BAYLEEF
    0x17, // SPECIES_MEGANIUM
    0x52, // SPECIES_CYNDAQUIL
    0x17, // SPECIES_QUILAVA
    0x10, // SPECIES_TYPHLOSION
    0x31, // SPECIES_TOTODILE
    0x0f, // SPECIES_CROCONAW
    0x0f, // SPECIES_FERALIGATR
    0x00, // SPECIES_SENTRET
    0x32, // SPECIES_FURRET
    0x47, // SPECIES_HOOTHOOT
    0x17, // SPECIES_NOCTOWL
    0x52, // SPECIES_LEDYBA
    0x47, // SPECIES_LEDIAN
    0x4f, // SPECIES_SPINARAK
    0x0f, // SPECIES_ARIADOS
    0x00, // SPECIES_CROBAT
    0x45, // SPECIES_CHINCHOU
    0x51, // SPECIES_LANTURN
    0x1e, // SPECIES_PICHU
    0x52, // SPECIES_CLEFFA
    0x0c, // SPECIES_IGGLYBUFF
    0x0b, // SPECIES_TOGEPI
    0x00, // SPECIES_TOGETIC
    0x31, // SPECIES_NATU
    0x09, // SPECIES_XATU
    0x00, // SPECIES_MAREEP
    0x1e, // SPECIES_FLAAFFY
    0x2c, // SPECIES_AMPHAROS
    0x0b, // SPECIES_BELLOSSOM
    0x00, // SPECIES_MARILL
    0x4a, // SPECIES_AZUMARILL
    0x46, // SPECIES_SUDOWOODO
    0x32, // SPECIES_POLITOED
    0x1c, // SPECIES_HOPPIP
    0x18, // SPECIES_SKIPLOOM
    0x51, // SPECIES_JUMPLUFF
    0x32, // SPECIES_AIPOM
    0x52, // SPECIES_SUNKERN
    0x00, // SPECIES_SUNFLORA
    0x2b, // SPECIES_YANMA
    0x00, // SPECIES_WOOPER
    0x16, // SPECIES_QUAGSIRE
    0x09, // SPECIES_ESPEON
    0x10, // SPECIES_UMBREON
    0x00, // SPECIES_MURKROW
    0x13, // SPECIES_SLOWKING
    0x1c, // SPECIES_MISDREAVUS
    0x0a, // SPECIES_UNOWN
    0x30, // SPECIES_WOBBUFFET
    0x1e, // SPECIES_GIRAFARIG
    0x0b, // SPECIES_PINECO
    0x10, // SPECIES_FORRETRESS
    0x00, // SPECIES_DUNSPARCE
    0x13, // SPECIES_GLIGAR
    0x0f, // SPECIES_STEELIX
    0x17, // SPECIES_SNUBBULL
    0x10, // SPECIES_GRANBULL
    0x3a, // SPECIES_QWILFISH
    0x02, // SPECIES_SCIZOR
    0x0b, // SPECIES_SHUCKLE
    0x41, // SPECIES_HERACROSS
    0x16, // SPECIES_SNEASEL
    0x17, // SPECIES_TEDDIURSA
    0x10, // SPECIES_URSARING
    0x17, // SPECIES_SLUGMA
    0x17, // SPECIES_MAGCARGO
    0x00, // SPECIES_SWINUB
    0x0f, // SPECIES_PILOSWINE
    0x03, // SPECIES_CORSOLA
    0x52, // SPECIES_REMORAID
    0x17, // SPECIES_OCTILLERY
    0x52, // SPECIES_DELIBIRD
    0x0d, // SPECIES_MANTINE
    0x17, // SPECIES_SKARMORY
    0x17, // SPECIES_HOUNDOUR
    0x10, // SPECIES_HOUNDOOM
    0x42, // SPECIES_KINGDRA
    0x32, // SPECIES_PHANPY
    0x19, // SPECIES_DONPHAN
    0x00, // SPECIES_PORYGON2
    0x00, // SPECIES_STANTLER
    0x31, // SPECIES_SMEARGLE
    0x16, // SPECIES_TYROGUE
    0x02, // SPECIES_HITMONTOP
    0x09, // SPECIES_SMOOCHUM
    0x2c, // SPECIES_ELEKID
    0x00, // SPECIES_MAGBY
    0x45, // SPECIES_MILTANK
    0x00, // SPECIES_BLISSEY
    0x2c, // SPECIES_RAIKOU
    0x09, // SPECIES_ENTEI
    0x10, // SPECIES_SUICUNE
    0x52, // SPECIES_LARVITAR
    0x10, // SPECIES_PUPITAR
    0x0f, // SPECIES_TYRANITAR
    0x3a, // SPECIES_LUGIA
    0x09, // SPECIES_HO_OH
    0x18, // SPECIES_CELEBI
    0x00, // 252
    0x00, // 253
    0x00, // 254
    0x00, // 255
    0x00, // 256
    0x00, // 257
    0x00, // 258
    0x00, // 259
    0x00, // 260
    0x00, // 261
    0x00, // 262
    0x00, // 263
    0x00, // 264
    0x00, // 265
    0x00, // 266
    0x00, // 267
    0x00, // 268
    0x00, // 269
    0x00, // 270
    0x00, // 271
    0x00, // 272
    0x00, // 273
    0x00, // 274
    0x00, // 275
    0x00, // 276
    0x00, // SPECIES_TREECKO
    0x17, // SPECIES_GROVYLE
    0x10, // SPECIES_SCEPTILE
    0x16, // SPECIES_TORCHIC
    0x06, // SPECIES_COMBUSKEN
    0x0f, // SPECIES_BLAZIKEN
    0x01, // SPECIES_MUDKIP
    0x04, // SPECIES_MARSHTOMP
    0x1e, // SPECIES_SWAMPERT
    0x10, // SPECIES_POOCHYENA
    0x10, // SPECIES_MIGHTYENA
    0x03, // SPECIES_ZIGZAGOON
    0x09, // SPECIES_LINOONE
    0x00, // SPECIES_WURMPLE
    0x00, // SPECIES_SILCOON
    0x04, // SPECIES_BEAUTIFLY
    0x04, // SPECIES_CASCOON
    0x06, // SPECIES_DUSTOX
    0x00, // SPECIES_LOTAD
    0x00, // SPECIES_LOMBRE
    0x49, // SPECIES_LUDICOLO
    0x05, // SPECIES_SEEDOT
    0x00, // SPECIES_NUZLEAF
    0x02, // SPECIES_SHIFTRY
    0x00, // SPECIES_NINCADA
    0x46, // SPECIES_NINJASK
    0x1c, // SPECIES_SHEDINJA
    0x1e, // SPECIES_TAILLOW
    0x01, // SPECIES_SWELLOW
    0x00, // SPECIES_SHROOMISH
    0x00, // SPECIES_BRELOOM
    0x31, // SPECIES_SPINDA
    0x1b, // SPECIES_WINGULL
    0x1c, // SPECIES_PELIPPER
    0x00, // SPECIES_SURSKIT
    0x00, // SPECIES_MASQUERAIN
    0x01, // SPECIES_WAILMER
    0x1c, // SPECIES_WAILORD
    0x00, // SPECIES_SKITTY
    0x17, // SPECIES_DELCATTY
    0x35, // SPECIES_KECLEON
    0x1d, // SPECIES_BALTOY
    0x51, // SPECIES_CLAYDOL
    0x49, // SPECIES_NOSEPASS
    0x17, // SPECIES_TORKOAL
    0x15, // SPECIES_SABLEYE
    0x49, // SPECIES_BARBOACH
    0x49, // SPECIES_WHISCASH
    0x1d, // SPECIES_LUVDISC
    0x10, // SPECIES_CORPHISH
    0x09, // SPECIES_CRAWDAUNT
    0x49, // SPECIES_FEEBAS
    0x22, // SPECIES_MILOTIC
    0x49, // SPECIES_CARVANHA
    0x56, // SPECIES_SHARPEDO
    0x10, // SPECIES_TRAPINCH
    0x0f, // SPECIES_VIBRAVA
    0x4b, // SPECIES_FLYGON
    0x0b, // SPECIES_MAKUHITA
    0x34, // SPECIES_HARIYAMA
    0x00, // SPECIES_ELECTRIKE
    0x00, // SPECIES_MANECTRIC
    0x04, // SPECIES_NUMEL
    0x10, // SPECIES_CAMERUPT
    0x53, // SPECIES_SPHEAL
    0x17, // SPECIES_SEALEO
    0x0f, // SPECIES_WALREIN
    0x49, // SPECIES_CACNEA
    0x04, // SPECIES_CACTURNE
    0x45, // SPECIES_SNORUNT
    0x0a, // SPECIES_GLALIE
    0x0e, // SPECIES_LUNATONE
    0x08, // SPECIES_SOLROCK
    0x00, // SPECIES_AZURILL
    0x56, // SPECIES_SPOINK
    0x32, // SPECIES_GRUMPIG
    0x00, // SPECIES_PLUSLE
    0x01, // SPECIES_MINUN
    0x00, // SPECIES_MAWILE
    0x05, // SPECIES_MEDITITE
    0x45, // SPECIES_MEDICHAM
    0x04, // SPECIES_SWABLU
    0x16, // SPECIES_ALTARIA
    0x32, // SPECIES_WYNAUT
    0x0a, // SPECIES_DUSKULL
    0x02, // SPECIES_DUSCLOPS
    0x45, // SPECIES_ROSELIA
    0x45, // SPECIES_SLAKOTH
    0x31, // SPECIES_VIGOROTH
    0x45, // SPECIES_SLAKING
    0x00, // SPECIES_GULPIN
    0x45, // SPECIES_SWALOT
    0x10, // SPECIES_TROPIUS
    0x03, // SPECIES_WHISMUR
    0x49, // SPECIES_LOUDRED
    0x19, // SPECIES_EXPLOUD
    0x12, // SPECIES_CLAMPERL
    0x09, // SPECIES_HUNTAIL
    0x1c, // SPECIES_GOREBYSS
    0x11, // SPECIES_ABSOL
    0x1c, // SPECIES_SHUPPET
    0x0d, // SPECIES_BANETTE
    0x17, // SPECIES_SEVIPER
    0x09, // SPECIES_ZANGOOSE
    0x1a, // SPECIES_RELICANTH
    0x45, // SPECIES_ARON
    0x00, // SPECIES_LAIRON
    0x19, // SPECIES_AGGRON
    0x1d, // SPECIES_CASTFORM
    0x00, // SPECIES_VOLBEAT
    0x05, // SPECIES_ILLUMISE
    0x17, // SPECIES_LILEEP
    0x19, // SPECIES_CRADILY
    0x12, // SPECIES_ANORITH
    0x10, // SPECIES_ARMALDO
    0x45, // SPECIES_RALTS
    0x00, // SPECIES_KIRLIA
    0x00, // SPECIES_GARDEVOIR
    0x19, // SPECIES_BAGON
    0x04, // SPECIES_SHELGON
    0x0f, // SPECIES_SALAMENCE
    0x0f, // SPECIES_BELDUM
    0x04, // SPECIES_METANG
    0x10, // SPECIES_METAGROSS
    0x01, // SPECIES_REGIROCK
    0x44, // SPECIES_REGICE
    0x09, // SPECIES_REGISTEEL
    0x2d, // SPECIES_KYOGRE
    0x10, // SPECIES_GROUDON
    0x0f, // SPECIES_RAYQUAZA
    0x2d, // SPECIES_LATIAS
    0x10, // SPECIES_LATIOS
    0x0d, // SPECIES_JIRACHI
    0x1b, // SPECIES_DEOXYS
    0x1d, // SPECIES_CHIMECHO
};

static const u8 sMonAnimationDelayTable[] =
{
    0x00, // SPECIES_BULBASAUR
    0x00, // SPECIES_IVYSAUR
    0x00, // SPECIES_VENUSAUR
    0x00, // SPECIES_CHARMANDER
    0x00, // SPECIES_CHARMELEON
    0x00, // SPECIES_CHARIZARD
    0x00, // SPECIES_SQUIRTLE
    0x00, // SPECIES_WARTORTLE
    0x32, // SPECIES_BLASTOISE
    0x00, // SPECIES_CATERPIE
    0x00, // SPECIES_METAPOD
    0x00, // SPECIES_BUTTERFREE
    0x0a, // SPECIES_WEEDLE
    0x14, // SPECIES_KAKUNA
    0x23, // SPECIES_BEEDRILL
    0x00, // SPECIES_PIDGEY
    0x19, // SPECIES_PIDGEOTTO
    0x00, // SPECIES_PIDGEOT
    0x00, // SPECIES_RATTATA
    0x00, // SPECIES_RATICATE
    0x00, // SPECIES_SPEAROW
    0x02, // SPECIES_FEAROW
    0x1e, // SPECIES_EKANS
    0x00, // SPECIES_ARBOK
    0x00, // SPECIES_PIKACHU
    0x00, // SPECIES_RAICHU
    0x00, // SPECIES_SANDSHREW
    0x00, // SPECIES_SANDSLASH
    0x1c, // SPECIES_NIDORAN_F
    0x00, // SPECIES_NIDORINA
    0x00, // SPECIES_NIDOQUEEN
    0x00, // SPECIES_NIDORAN_M
    0x00, // SPECIES_NIDORINO
    0x19, // SPECIES_NIDOKING
    0x00, // SPECIES_CLEFAIRY
    0x00, // SPECIES_CLEFABLE
    0x00, // SPECIES_VULPIX
    0x00, // SPECIES_NINETALES
    0x00, // SPECIES_JIGGLYPUFF
    0x00, // SPECIES_WIGGLYTUFF
    0x00, // SPECIES_ZUBAT
    0x00, // SPECIES_GOLBAT
    0x00, // SPECIES_ODDISH
    0x00, // SPECIES_GLOOM
    0x00, // SPECIES_VILEPLUME
    0x0a, // SPECIES_PARAS
    0x2d, // SPECIES_PARASECT
    0x14, // SPECIES_VENONAT
    0x00, // SPECIES_VENOMOTH
    0x19, // SPECIES_DIGLETT
    0x23, // SPECIES_DUGTRIO
    0x28, // SPECIES_MEOWTH
    0x14, // SPECIES_PERSIAN
    0x00, // SPECIES_PSYDUCK
    0x00, // SPECIES_GOLDUCK
    0x14, // SPECIES_MANKEY
    0x00, // SPECIES_PRIMEAPE
    0x1e, // SPECIES_GROWLITHE
    0x28, // SPECIES_ARCANINE
    0x00, // SPECIES_POLIWAG
    0x05, // SPECIES_POLIWHIRL
    0x00, // SPECIES_POLIWRATH
    0x00, // SPECIES_ABRA
    0x00, // SPECIES_KADABRA
    0x00, // SPECIES_ALAKAZAM
    0x00, // SPECIES_MACHOP
    0x00, // SPECIES_MACHOKE
    0x00, // SPECIES_MACHAMP
    0x00, // SPECIES_BELLSPROUT
    0x03, // SPECIES_WEEPINBELL
    0x00, // SPECIES_VICTREEBEL
    0x00, // SPECIES_TENTACOOL
    0x00, // SPECIES_TENTACRUEL
    0x00, // SPECIES_GEODUDE
    0x00, // SPECIES_GRAVELER
    0x00, // SPECIES_GOLEM
    0x00, // SPECIES_PONYTA
    0x00, // SPECIES_RAPIDASH
    0x00, // SPECIES_SLOWPOKE
    0x00, // SPECIES_SLOWBRO
    0x00, // SPECIES_MAGNEMITE
    0x00, // SPECIES_MAGNETON
    0x00, // SPECIES_FARFETCHD
    0x00, // SPECIES_DODUO
    0x00, // SPECIES_DODRIO
    0x00, // SPECIES_SEEL
    0x00, // SPECIES_DEWGONG
    0x00, // SPECIES_GRIMER
    0x2d, // SPECIES_MUK
    0x14, // SPECIES_SHELLDER
    0x00, // SPECIES_CLOYSTER
    0x00, // SPECIES_GASTLY
    0x17, // SPECIES_HAUNTER
    0x00, // SPECIES_GENGAR
    0x00, // SPECIES_ONIX
    0x30, // SPECIES_DROWZEE
    0x28, // SPECIES_HYPNO
    0x00, // SPECIES_KRABBY
    0x00, // SPECIES_KINGLER
    0x00, // SPECIES_VOLTORB
    0x00, // SPECIES_ELECTRODE
    0x00, // SPECIES_EXEGGCUTE
    0x00, // SPECIES_EXEGGUTOR
    0x00, // SPECIES_CUBONE
    0x00, // SPECIES_MAROWAK
    0x00, // SPECIES_HITMONLEE
    0x19, // SPECIES_HITMONCHAN
    0x00, // SPECIES_LICKITUNG
    0x00, // SPECIES_KOFFING
    0x00, // SPECIES_WEEZING
    0x00, // SPECIES_RHYHORN
    0x00, // SPECIES_RHYDON
    0x00, // SPECIES_CHANSEY
    0x00, // SPECIES_TANGELA
    0x00, // SPECIES_KANGASKHAN
    0x00, // SPECIES_HORSEA
    0x00, // SPECIES_SEADRA
    0x00, // SPECIES_GOLDEEN
    0x00, // SPECIES_SEAKING
    0x00, // SPECIES_STARYU
    0x00, // SPECIES_STARMIE
    0x00, // SPECIES_MR_MIME
    0x0a, // SPECIES_SCYTHER
    0x00, // SPECIES_JYNX
    0x00, // SPECIES_ELECTABUZZ
    0x00, // SPECIES_MAGMAR
    0x00, // SPECIES_PINSIR
    0x0a, // SPECIES_TAUROS
    0x00, // SPECIES_MAGIKARP
    0x00, // SPECIES_GYARADOS
    0x00, // SPECIES_LAPRAS
    0x00, // SPECIES_DITTO
    0x00, // SPECIES_EEVEE
    0x00, // SPECIES_VAPOREON
    0x00, // SPECIES_JOLTEON
    0x00, // SPECIES_FLAREON
    0x00, // SPECIES_PORYGON
    0x00, // SPECIES_OMANYTE
    0x00, // SPECIES_OMASTAR
    0x00, // SPECIES_KABUTO
    0x00, // SPECIES_KABUTOPS
    0x00, // SPECIES_AERODACTYL
    0x00, // SPECIES_SNORLAX
    0x00, // SPECIES_ARTICUNO
    0x00, // SPECIES_ZAPDOS
    0x00, // SPECIES_MOLTRES
    0x00, // SPECIES_DRATINI
    0x00, // SPECIES_DRAGONAIR
    0x00, // SPECIES_DRAGONITE
    0x00, // SPECIES_MEWTWO
    0x00, // SPECIES_MEW
    0x00, // SPECIES_CHIKORITA
    0x00, // SPECIES_BAYLEEF
    0x00, // SPECIES_MEGANIUM
    0x00, // SPECIES_CYNDAQUIL
    0x00, // SPECIES_QUILAVA
    0x14, // SPECIES_TYPHLOSION
    0x00, // SPECIES_TOTODILE
    0x00, // SPECIES_CROCONAW
    0x05, // SPECIES_FERALIGATR
    0x00, // SPECIES_SENTRET
    0x00, // SPECIES_FURRET
    0x00, // SPECIES_HOOTHOOT
    0x00, // SPECIES_NOCTOWL
    0x00, // SPECIES_LEDYBA
    0x00, // SPECIES_LEDIAN
    0x00, // SPECIES_SPINARAK
    0x00, // SPECIES_ARIADOS
    0x00, // SPECIES_CROBAT
    0x00, // SPECIES_CHINCHOU
    0x00, // SPECIES_LANTURN
    0x00, // SPECIES_PICHU
    0x00, // SPECIES_CLEFFA
    0x00, // SPECIES_IGGLYBUFF
    0x00, // SPECIES_TOGEPI
    0x00, // SPECIES_TOGETIC
    0x1e, // SPECIES_NATU
    0x00, // SPECIES_XATU
    0x32, // SPECIES_MAREEP
    0x00, // SPECIES_FLAAFFY
    0x0a, // SPECIES_AMPHAROS
    0x00, // SPECIES_BELLOSSOM
    0x00, // SPECIES_MARILL
    0x00, // SPECIES_AZUMARILL
    0x00, // SPECIES_SUDOWOODO
    0x28, // SPECIES_POLITOED
    0x00, // SPECIES_HOPPIP
    0x00, // SPECIES_SKIPLOOM
    0x00, // SPECIES_JUMPLUFF
    0x00, // SPECIES_AIPOM
    0x00, // SPECIES_SUNKERN
    0x00, // SPECIES_SUNFLORA
    0x00, // SPECIES_YANMA
    0x00, // SPECIES_WOOPER
    0x00, // SPECIES_QUAGSIRE
    0x00, // SPECIES_ESPEON
    0x00, // SPECIES_UMBREON
    0x00, // SPECIES_MURKROW
    0x00, // SPECIES_SLOWKING
    0x00, // SPECIES_MISDREAVUS
    0x00, // SPECIES_UNOWN
    0x00, // SPECIES_WOBBUFFET
    0x00, // SPECIES_GIRAFARIG
    0x00, // SPECIES_PINECO
    0x00, // SPECIES_FORRETRESS
    0x0a, // SPECIES_DUNSPARCE
    0x00, // SPECIES_GLIGAR
    0x2d, // SPECIES_STEELIX
    0x00, // SPECIES_SNUBBULL
    0x00, // SPECIES_GRANBULL
    0x27, // SPECIES_QWILFISH
    0x13, // SPECIES_SCIZOR
    0x00, // SPECIES_SHUCKLE
    0x00, // SPECIES_HERACROSS
    0x00, // SPECIES_SNEASEL
    0x00, // SPECIES_TEDDIURSA
    0x00, // SPECIES_URSARING
    0x00, // SPECIES_SLUGMA
    0x00, // SPECIES_MAGCARGO
    0x00, // SPECIES_SWINUB
    0x00, // SPECIES_PILOSWINE
    0x00, // SPECIES_CORSOLA
    0x00, // SPECIES_REMORAID
    0x14, // SPECIES_OCTILLERY
    0x00, // SPECIES_DELIBIRD
    0x00, // SPECIES_MANTINE
    0x00, // SPECIES_SKARMORY
    0x00, // SPECIES_HOUNDOUR
    0x00, // SPECIES_HOUNDOOM
    0x00, // SPECIES_KINGDRA
    0x00, // SPECIES_PHANPY
    0x00, // SPECIES_DONPHAN
    0x00, // SPECIES_PORYGON2
    0x00, // SPECIES_STANTLER
    0x00, // SPECIES_SMEARGLE
    0x00, // SPECIES_TYROGUE
    0x00, // SPECIES_HITMONTOP
    0x28, // SPECIES_SMOOCHUM
    0x00, // SPECIES_ELEKID
    0x00, // SPECIES_MAGBY
    0x00, // SPECIES_MILTANK
    0x00, // SPECIES_BLISSEY
    0x00, // SPECIES_RAIKOU
    0x00, // SPECIES_ENTEI
    0x00, // SPECIES_SUICUNE
    0x00, // SPECIES_LARVITAR
    0x00, // SPECIES_PUPITAR
    0x0a, // SPECIES_TYRANITAR
    0x14, // SPECIES_LUGIA
    0x00, // SPECIES_HO_OH
    0x00, // SPECIES_CELEBI
    0x00, // 252
    0x00, // 253
    0x00, // 254
    0x00, // 255
    0x00, // 256
    0x00, // 257
    0x00, // 258
    0x00, // 259
    0x00, // 260
    0x00, // 261
    0x00, // 262
    0x00, // 263
    0x00, // 264
    0x00, // 265
    0x00, // 266
    0x00, // 267
    0x00, // 268
    0x00, // 269
    0x00, // 270
    0x00, // 271
    0x00, // 272
    0x00, // 273
    0x00, // 274
    0x00, // 275
    0x00, // 276
    0x00, // SPECIES_TREECKO
    0x00, // SPECIES_GROVYLE
    0x00, // SPECIES_SCEPTILE
    0x00, // SPECIES_TORCHIC
    0x00, // SPECIES_COMBUSKEN
    0x00, // SPECIES_BLAZIKEN
    0x00, // SPECIES_MUDKIP
    0x00, // SPECIES_MARSHTOMP
    0x00, // SPECIES_SWAMPERT
    0x00, // SPECIES_POOCHYENA
    0x00, // SPECIES_MIGHTYENA
    0x00, // SPECIES_ZIGZAGOON
    0x00, // SPECIES_LINOONE
    0x00, // SPECIES_WURMPLE
    0x00, // SPECIES_SILCOON
    0x00, // SPECIES_BEAUTIFLY
    0x00, // SPECIES_CASCOON
    0x00, // SPECIES_DUSTOX
    0x00, // SPECIES_LOTAD
    0x00, // SPECIES_LOMBRE
    0x00, // SPECIES_LUDICOLO
    0x00, // SPECIES_SEEDOT
    0x00, // SPECIES_NUZLEAF
    0x00, // SPECIES_SHIFTRY
    0x00, // SPECIES_NINCADA
    0x00, // SPECIES_NINJASK
    0x00, // SPECIES_SHEDINJA
    0x00, // SPECIES_TAILLOW
    0x00, // SPECIES_SWELLOW
    0x00, // SPECIES_SHROOMISH
    0x00, // SPECIES_BRELOOM
    0x00, // SPECIES_SPINDA
    0x00, // SPECIES_WINGULL
    0x00, // SPECIES_PELIPPER
    0x00, // SPECIES_SURSKIT
    0x00, // SPECIES_MASQUERAIN
    0x00, // SPECIES_WAILMER
    0x0a, // SPECIES_WAILORD
    0x00, // SPECIES_SKITTY
    0x00, // SPECIES_DELCATTY
    0x1e, // SPECIES_KECLEON
    0x00, // SPECIES_BALTOY
    0x00, // SPECIES_CLAYDOL
    0x00, // SPECIES_NOSEPASS
    0x00, // SPECIES_TORKOAL
    0x00, // SPECIES_SABLEYE
    0x00, // SPECIES_BARBOACH
    0x00, // SPECIES_WHISCASH
    0x00, // SPECIES_LUVDISC
    0x00, // SPECIES_CORPHISH
    0x00, // SPECIES_CRAWDAUNT
    0x00, // SPECIES_FEEBAS
    0x2d, // SPECIES_MILOTIC
    0x00, // SPECIES_CARVANHA
    0x00, // SPECIES_SHARPEDO
    0x00, // SPECIES_TRAPINCH
    0x00, // SPECIES_VIBRAVA
    0x00, // SPECIES_FLYGON
    0x00, // SPECIES_MAKUHITA
    0x00, // SPECIES_HARIYAMA
    0x00, // SPECIES_ELECTRIKE
    0x00, // SPECIES_MANECTRIC
    0x00, // SPECIES_NUMEL
    0x00, // SPECIES_CAMERUPT
    0x0f, // SPECIES_SPHEAL
    0x00, // SPECIES_SEALEO
    0x00, // SPECIES_WALREIN
    0x00, // SPECIES_CACNEA
    0x00, // SPECIES_CACTURNE
    0x14, // SPECIES_SNORUNT
    0x00, // SPECIES_GLALIE
    0x00, // SPECIES_LUNATONE
    0x00, // SPECIES_SOLROCK
    0x00, // SPECIES_AZURILL
    0x00, // SPECIES_SPOINK
    0x0f, // SPECIES_GRUMPIG
    0x00, // SPECIES_PLUSLE
    0x00, // SPECIES_MINUN
    0x00, // SPECIES_MAWILE
    0x00, // SPECIES_MEDITITE
    0x00, // SPECIES_MEDICHAM
    0x00, // SPECIES_SWABLU
    0x00, // SPECIES_ALTARIA
    0x0f, // SPECIES_WYNAUT
    0x00, // SPECIES_DUSKULL
    0x1e, // SPECIES_DUSCLOPS
    0x00, // SPECIES_ROSELIA
    0x00, // SPECIES_SLAKOTH
    0x00, // SPECIES_VIGOROTH
    0x00, // SPECIES_SLAKING
    0x00, // SPECIES_GULPIN
    0x00, // SPECIES_SWALOT
    0x00, // SPECIES_TROPIUS
    0x00, // SPECIES_WHISMUR
    0x00, // SPECIES_LOUDRED
    0x00, // SPECIES_EXPLOUD
    0x00, // SPECIES_CLAMPERL
    0x00, // SPECIES_HUNTAIL
    0x00, // SPECIES_GOREBYSS
    0x2d, // SPECIES_ABSOL
    0x00, // SPECIES_SHUPPET
    0x00, // SPECIES_BANETTE
    0x00, // SPECIES_SEVIPER
    0x00, // SPECIES_ZANGOOSE
    0x00, // SPECIES_RELICANTH
    0x00, // SPECIES_ARON
    0x00, // SPECIES_LAIRON
    0x00, // SPECIES_AGGRON
    0x00, // SPECIES_CASTFORM
    0x00, // SPECIES_VOLBEAT
    0x00, // SPECIES_ILLUMISE
    0x00, // SPECIES_LILEEP
    0x00, // SPECIES_CRADILY
    0x00, // SPECIES_ANORITH
    0x00, // SPECIES_ARMALDO
    0x00, // SPECIES_RALTS
    0x00, // SPECIES_KIRLIA
    0x00, // SPECIES_GARDEVOIR
    0x00, // SPECIES_BAGON
    0x00, // SPECIES_SHELGON
    0x46, // SPECIES_SALAMENCE
    0x00, // SPECIES_BELDUM
    0x00, // SPECIES_METANG
    0x00, // SPECIES_METAGROSS
    0x00, // SPECIES_REGIROCK
    0x00, // SPECIES_REGICE
    0x00, // SPECIES_REGISTEEL
    0x3c, // SPECIES_KYOGRE
    0x00, // SPECIES_GROUDON
    0x3c, // SPECIES_RAYQUAZA
    0x00, // SPECIES_LATIAS
    0x00, // SPECIES_LATIOS
    0x00, // SPECIES_JIRACHI
    0x00, // SPECIES_DEOXYS
    0x00, // SPECIES_CHIMECHO
};

const u8 gUnknown_08329D22[] = {0x03, 0x0c, 0x30, 0xc0}; // Masks for getting PP Up count, also PP Max values
const u8 gUnknown_08329D26[] = {0xfc, 0xf3, 0xcf, 0x3f}; // Masks for setting PP Up count
const u8 gUnknown_08329D2A[] = {0x01, 0x04, 0x10, 0x40}; // Values added to PP Up count

const u8 gStatStageRatios[][2] =
{
    {10, 40}, // -6
    {10, 35}, // -5
    {10, 30}, // -4
    {10, 25}, // -3
    {10, 20}, // -2
    {10, 15}, // -1
    {10, 10}, //  0
    {15, 10}, // +1
    {20, 10}, // +2
    {25, 10}, // +3
    {30, 10}, // +4
    {35, 10}, // +5
    {40, 10}, // +6
};

static const u16 sDeoxysBaseStats[] =
{
    50, // Hp
    95, // Attack
    90, // Defense
    180, // Speed
    95, // Sp.Attack
    90, // Sp.Defense
};

const u16 gUnknown_08329D54[] =
{
    FACILITY_CLASS_COOLTRAINER_M, FACILITY_CLASS_BLACK_BELT, FACILITY_CLASS_CAMPER,
    FACILITY_CLASS_YOUNGSTER, FACILITY_CLASS_PSYCHIC_M, FACILITY_CLASS_BUG_CATCHER,
    FACILITY_CLASS_PKMN_BREEDER_2, FACILITY_CLASS_GUITARIST, FACILITY_CLASS_COOLTRAINER_F,
    FACILITY_CLASS_HEX_MANIAC, FACILITY_CLASS_PICNICKER, FACILITY_CLASS_LASS,
    FACILITY_CLASS_PSYCHIC_F, FACILITY_CLASS_BATTLE_GIRL, FACILITY_CLASS_PKMN_BREEDER_1,
    FACILITY_CLASS_BEAUTY
};

static const u8 sHoldEffectToType[][2] =
{
    {HOLD_EFFECT_BUG_POWER, TYPE_BUG},
    {HOLD_EFFECT_STEEL_POWER, TYPE_STEEL},
    {HOLD_EFFECT_GROUND_POWER, TYPE_GROUND},
    {HOLD_EFFECT_ROCK_POWER, TYPE_ROCK},
    {HOLD_EFFECT_GRASS_POWER, TYPE_GRASS},
    {HOLD_EFFECT_DARK_POWER, TYPE_DARK},
    {HOLD_EFFECT_FIGHTING_POWER, TYPE_FIGHTING},
    {HOLD_EFFECT_ELECTRIC_POWER, TYPE_ELECTRIC},
    {HOLD_EFFECT_WATER_POWER, TYPE_WATER},
    {HOLD_EFFECT_FLYING_POWER, TYPE_FLYING},
    {HOLD_EFFECT_POISON_POWER, TYPE_POISON},
    {HOLD_EFFECT_ICE_POWER, TYPE_ICE},
    {HOLD_EFFECT_GHOST_POWER, TYPE_GHOST},
    {HOLD_EFFECT_PSYCHIC_POWER, TYPE_PSYCHIC},
    {HOLD_EFFECT_FIRE_POWER, TYPE_FIRE},
    {HOLD_EFFECT_DRAGON_POWER, TYPE_DRAGON},
    {HOLD_EFFECT_NORMAL_POWER, TYPE_NORMAL},
};

const struct SpriteTemplate gUnknown_08329D98[MAX_BATTLERS_COUNT] =
{
    {   // B_POSITION_PLAYER_LEFT
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACB0,
        .anims = NULL,
        .images = gUnknown_082FF3A8,
        .affineAnims = gUnknown_082FF618,
        .callback = sub_8039BB4,
    },
    {   // B_POSITION_OPPONENT_LEFT
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACA8,
        .anims = NULL,
        .images = gUnknown_082FF3C8,
        .affineAnims = gUnknown_082FF694,
        .callback = oac_poke_opponent,
    },
    {   // B_POSITION_PLAYER_RIGHT
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACB0,
        .anims = NULL,
        .images = gUnknown_082FF3E8,
        .affineAnims = gUnknown_082FF618,
        .callback = sub_8039BB4,
    },
    {   // B_POSITION_OPPONENT_RIGHT
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACA8,
        .anims = NULL,
        .images = gUnknown_082FF408,
        .affineAnims = gUnknown_082FF694,
        .callback = oac_poke_opponent
    },
};

static const struct SpriteTemplate gUnknown_08329DF8[] =
{
    {
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACB0,
        .anims = NULL,
        .images = gUnknown_082FF428,
        .affineAnims = gUnknown_082FF618,
        .callback = sub_8039BB4,
    },
    {
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACB0,
        .anims = NULL,
        .images = gUnknown_082FF448,
        .affineAnims = gUnknown_082FF618,
        .callback = sub_8039BB4,
    },
    {
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACB0,
        .anims = NULL,
        .images = gUnknown_082FF468,
        .affineAnims = gUnknown_082FF618,
        .callback = sub_8039BB4,
    },
    {
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACB0,
        .anims = NULL,
        .images = gUnknown_082FF490,
        .affineAnims = gUnknown_082FF618,
        .callback = sub_8039BB4,
    },
    {
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACB0,
        .anims = NULL,
        .images = gUnknown_082FF4B8,
        .affineAnims = gUnknown_082FF618,
        .callback = sub_8039BB4,
    },
    {
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACB0,
        .anims = NULL,
        .images = gUnknown_082FF4D8,
        .affineAnims = gUnknown_082FF618,
        .callback = sub_8039BB4,
    },
    {
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACB0,
        .anims = NULL,
        .images = gUnknown_082FF4F8,
        .affineAnims = gUnknown_082FF618,
        .callback = sub_8039BB4,
    },
    {
        .tileTag = 0xFFFF,
        .paletteTag = 0,
        .oam = &gUnknown_0831ACB0,
        .anims = NULL,
        .images = gUnknown_082FF518,
        .affineAnims = gUnknown_082FF618,
        .callback = sub_8039BB4,
    },
};

static const u8 sSecretBaseFacilityClasses[2][5] =
{
    {FACILITY_CLASS_YOUNGSTER, FACILITY_CLASS_BUG_CATCHER, FACILITY_CLASS_RICH_BOY, FACILITY_CLASS_CAMPER, FACILITY_CLASS_COOLTRAINER_M},
    {FACILITY_CLASS_LASS, FACILITY_CLASS_SCHOOL_KID_F, FACILITY_CLASS_LADY, FACILITY_CLASS_PICNICKER, FACILITY_CLASS_COOLTRAINER_F}
};

static const u8 sGetMonDataEVConstants[] =
{
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPEED_EV,
    MON_DATA_SPDEF_EV,
    MON_DATA_SPATK_EV
};

static const u8 gUnknown_08329EC8[] =
{
    STAT_ATK, STAT_ATK, STAT_SPEED, STAT_DEF, STAT_SPATK, STAT_ACC
};

static const s8 gUnknown_08329ECE[][3] =
{
    { 5,  3,  2},
    { 5,  3,  2},
    { 1,  1,  0},
    { 3,  2,  1},
    { 1,  1,  0},
    { 1,  1,  1},
    {-1, -1, -1},
    {-5, -5, -10},
    {-5, -5, -10},
};

static const u16 sHMMoves[] =
{
    MOVE_CUT, MOVE_FLY, MOVE_SURF, MOVE_STRENGTH, MOVE_FLASH,
    MOVE_ROCK_SMASH, MOVE_WATERFALL, MOVE_DIVE, 0xFFFF
};

static const struct SpeciesItem sAlteringCaveWildMonHeldItems[] =
{
    {SPECIES_NONE,      ITEM_NONE},
    {SPECIES_MAREEP,    ITEM_GANLON_BERRY},
    {SPECIES_PINECO,	ITEM_APICOT_BERRY},
    {SPECIES_HOUNDOUR,	ITEM_BIG_MUSHROOM},
    {SPECIES_TEDDIURSA,	ITEM_PETAYA_BERRY},
    {SPECIES_AIPOM,		ITEM_BERRY_JUICE},
    {SPECIES_SHUCKLE,	ITEM_BERRY_JUICE},
    {SPECIES_STANTLER,	ITEM_PETAYA_BERRY},
    {SPECIES_SMEARGLE,	ITEM_SALAC_BERRY},
};

static const struct OamData sOamData_8329F20 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct SpriteTemplate gUnknown_08329F28 =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0xFFFF,
    .oam = &sOamData_8329F20,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

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

    if (gSaveBlock2Ptr->frontier.chosenLvl != 0)
        level = BattleFrontierGetOpponentLvl(gSaveBlock2Ptr->frontier.chosenLvl);
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

static s32 GetDeoxysStat(struct Pokemon *mon, s32 statId)
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
    statValue = (u16)(((sDeoxysBaseStats[statId] * 2 + ivVal + evVal / 4) * mon->level) / 100 + 5);

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
    return FacilityClassToPicIndex(gUnknown_08329D54[arrId]);
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

static u16 CalculateBoxMonChecksum(struct BoxPokemon *boxMon)
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

    CALC_STAT(baseAttack, attackIV, attackEV, STAT_ATK, MON_DATA_ATK)
    CALC_STAT(baseDefense, defenseIV, defenseEV, STAT_DEF, MON_DATA_DEF)
    CALC_STAT(baseSpeed, speedIV, speedEV, STAT_SPEED, MON_DATA_SPEED)
    CALC_STAT(baseSpAttack, spAttackIV, spAttackEV, STAT_SPATK, MON_DATA_SPATK)
    CALC_STAT(baseSpDefense, spDefenseIV, spDefenseEV, STAT_SPDEF, MON_DATA_SPDEF)

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

#define APPLY_STAT_MOD(var, mon, stat, statIndex)                                   \
{                                                                                   \
    (var) = (stat) * (gStatStageRatios)[(mon)->statStages[(statIndex)]][0];         \
    (var) /= (gStatStageRatios)[(mon)->statStages[(statIndex)]][1];                 \
}

s32 CalculateBaseDamage(struct BattlePokemon *attacker, struct BattlePokemon *defender, u32 move, u16 sideStatus, u16 powerOverride, u8 typeOverride, u8 battlerIdAtk, u8 battlerIdDef)
{
    u32 i;
    s32 damage = 0;
    s32 damageHelper;
    u8 type;
    u16 attack, defense;
    u16 spAttack, spDefense;
    u8 defenderHoldEffect;
    u8 defenderHoldEffectParam;
    u8 attackerHoldEffect;
    u8 attackerHoldEffectParam;

    if (!powerOverride)
        gBattleMovePower = gBattleMoves[move].power;
    else
        gBattleMovePower = powerOverride;

    if (!typeOverride)
        type = gBattleMoves[move].type;
    else
        type = typeOverride & 0x3F;

    attack = attacker->attack;
    defense = defender->defense;
    spAttack = attacker->spAttack;
    spDefense = defender->spDefense;

    if (attacker->item == ITEM_ENIGMA_BERRY)
    {
        attackerHoldEffect = gEnigmaBerries[battlerIdAtk].holdEffect;
        attackerHoldEffectParam = gEnigmaBerries[battlerIdAtk].holdEffectParam;
    }
    else
    {
        attackerHoldEffect = ItemId_GetHoldEffect(attacker->item);
        attackerHoldEffectParam = ItemId_GetHoldEffectParam(attacker->item);
    }

    if (defender->item == ITEM_ENIGMA_BERRY)
    {
        defenderHoldEffect = gEnigmaBerries[battlerIdDef].holdEffect;
        defenderHoldEffectParam = gEnigmaBerries[battlerIdDef].holdEffectParam;
    }
    else
    {
        defenderHoldEffect = ItemId_GetHoldEffect(defender->item);
        defenderHoldEffectParam = ItemId_GetHoldEffectParam(defender->item);
    }

    if (attacker->ability == ABILITY_HUGE_POWER || attacker->ability == ABILITY_PURE_POWER)
        attack *= 2;

    if (ShouldGetStatBadgeBoost(FLAG_BADGE01_GET, battlerIdAtk))
        attack = (110 * attack) / 100;
    if (ShouldGetStatBadgeBoost(FLAG_BADGE05_GET, battlerIdDef))
        defense = (110 * defense) / 100;
    if (ShouldGetStatBadgeBoost(FLAG_BADGE07_GET, battlerIdAtk))
        spAttack = (110 * spAttack) / 100;
    if (ShouldGetStatBadgeBoost(FLAG_BADGE07_GET, battlerIdDef))
        spDefense = (110 * spDefense) / 100;

    for (i = 0; i < ARRAY_COUNT(sHoldEffectToType); i++)
    {
        if (attackerHoldEffect == sHoldEffectToType[i][0]
            && type == sHoldEffectToType[i][1])
        {
            if (type <= 8)
                attack = (attack * (attackerHoldEffectParam + 100)) / 100;
            else
                spAttack = (spAttack * (attackerHoldEffectParam + 100)) / 100;
            break;
        }
    }

    if (attackerHoldEffect == HOLD_EFFECT_CHOICE_BAND)
        attack = (150 * attack) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_SOUL_DEW && !(gBattleTypeFlags & (BATTLE_TYPE_FRONTIER)) && (attacker->species == SPECIES_LATIAS || attacker->species == SPECIES_LATIOS))
        spAttack = (150 * spAttack) / 100;
    if (defenderHoldEffect == HOLD_EFFECT_SOUL_DEW && !(gBattleTypeFlags & (BATTLE_TYPE_FRONTIER)) && (defender->species == SPECIES_LATIAS || defender->species == SPECIES_LATIOS))
        spDefense = (150 * spDefense) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_DEEP_SEA_TOOTH && attacker->species == SPECIES_CLAMPERL)
        spAttack *= 2;
    if (defenderHoldEffect == HOLD_EFFECT_DEEP_SEA_SCALE && defender->species == SPECIES_CLAMPERL)
        spDefense *= 2;
    if (attackerHoldEffect == HOLD_EFFECT_LIGHT_BALL && attacker->species == SPECIES_PIKACHU)
        spAttack *= 2;
    if (defenderHoldEffect == HOLD_EFFECT_METAL_POWDER && defender->species == SPECIES_DITTO)
        defense *= 2;
    if (attackerHoldEffect == HOLD_EFFECT_THICK_CLUB && (attacker->species == SPECIES_CUBONE || attacker->species == SPECIES_MAROWAK))
        attack *= 2;
    if (defender->ability == ABILITY_THICK_FAT && (type == TYPE_FIRE || type == TYPE_ICE))
        spAttack /= 2;
    if (attacker->ability == ABILITY_HUSTLE)
        attack = (150 * attack) / 100;
    if (attacker->ability == ABILITY_PLUS && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_MINUS, 0, 0))
        spAttack = (150 * spAttack) / 100;
    if (attacker->ability == ABILITY_MINUS && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_PLUS, 0, 0))
        spAttack = (150 * spAttack) / 100;
    if (attacker->ability == ABILITY_GUTS && attacker->status1)
        attack = (150 * attack) / 100;
    if (defender->ability == ABILITY_MARVEL_SCALE && defender->status1)
        defense = (150 * defense) / 100;
    if (type == TYPE_ELECTRIC && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, 0, 0xFD, 0))
        gBattleMovePower /= 2;
    if (type == TYPE_FIRE && AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, 0, 0xFE, 0))
        gBattleMovePower /= 2;
    if (type == TYPE_GRASS && attacker->ability == ABILITY_OVERGROW && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (type == TYPE_FIRE && attacker->ability == ABILITY_BLAZE && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (type == TYPE_WATER && attacker->ability == ABILITY_TORRENT && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (type == TYPE_BUG && attacker->ability == ABILITY_SWARM && attacker->hp <= (attacker->maxHP / 3))
        gBattleMovePower = (150 * gBattleMovePower) / 100;
    if (gBattleMoves[gCurrentMove].effect == EFFECT_EXPLOSION)
        defense /= 2;

    if (type < TYPE_MYSTERY) // is physical
    {
        if (gCritMultiplier == 2)
        {
            if (attacker->statStages[STAT_ATK] > 6)
                APPLY_STAT_MOD(damage, attacker, attack, STAT_ATK)
            else
                damage = attack;
        }
        else
            APPLY_STAT_MOD(damage, attacker, attack, STAT_ATK)

        damage = damage * gBattleMovePower;
        damage *= (2 * attacker->level / 5 + 2);

        if (gCritMultiplier == 2)
        {
            if (defender->statStages[STAT_DEF] < 6)
                APPLY_STAT_MOD(damageHelper, defender, defense, STAT_DEF)
            else
                damageHelper = defense;
        }
        else
            APPLY_STAT_MOD(damageHelper, defender, defense, STAT_DEF)

        damage = damage / damageHelper;
        damage /= 50;

        if ((attacker->status1 & STATUS1_BURN) && attacker->ability != ABILITY_GUTS)
            damage /= 2;

        if ((sideStatus & SIDE_STATUS_REFLECT) && gCritMultiplier == 1)
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && CountAliveMonsInBattle(2) == 2)
                damage = 2 * (damage / 3);
            else
                damage /= 2;
        }

        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && gBattleMoves[move].target == 8 && CountAliveMonsInBattle(2) == 2)
            damage /= 2;

        // moves always do at least 1 damage.
        if (damage == 0)
            damage = 1;
    }

    if (type == TYPE_MYSTERY)
        damage = 0; // is ??? type. does 0 damage.

    if (type > TYPE_MYSTERY) // is special?
    {
        if (gCritMultiplier == 2)
        {
            if (attacker->statStages[STAT_SPATK] > 6)
                APPLY_STAT_MOD(damage, attacker, spAttack, STAT_SPATK)
            else
                damage = spAttack;
        }
        else
            APPLY_STAT_MOD(damage, attacker, spAttack, STAT_SPATK)

        damage = damage * gBattleMovePower;
        damage *= (2 * attacker->level / 5 + 2);

        if (gCritMultiplier == 2)
        {
            if (defender->statStages[STAT_SPDEF] < 6)
                APPLY_STAT_MOD(damageHelper, defender, spDefense, STAT_SPDEF)
            else
                damageHelper = spDefense;
        }
        else
            APPLY_STAT_MOD(damageHelper, defender, spDefense, STAT_SPDEF)

        damage = (damage / damageHelper);
        damage /= 50;

        if ((sideStatus & SIDE_STATUS_LIGHTSCREEN) && gCritMultiplier == 1)
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && CountAliveMonsInBattle(2) == 2)
                damage = 2 * (damage / 3);
            else
                damage /= 2;
        }

        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && gBattleMoves[move].target == 8 && CountAliveMonsInBattle(2) == 2)
            damage /= 2;

        // are effects of weather negated with cloud nine or air lock
        if (!AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_CLOUD_NINE, 0, 0)
            && !AbilityBattleEffects(ABILITYEFFECT_FIELD_SPORT, 0, ABILITY_AIR_LOCK, 0, 0))
        {
            if (gBattleWeather & WEATHER_RAIN_TEMPORARY)
            {
                switch (type)
                {
                case TYPE_FIRE:
                    damage /= 2;
                    break;
                case TYPE_WATER:
                    damage = (15 * damage) / 10;
                    break;
                }
            }

            // any weather except sun weakens solar beam
            if ((gBattleWeather & (WEATHER_RAIN_ANY | WEATHER_SANDSTORM_ANY | WEATHER_HAIL)) && gCurrentMove == MOVE_SOLAR_BEAM)
                damage /= 2;

            // sunny
            if (gBattleWeather & WEATHER_SUN_ANY)
            {
                switch (type)
                {
                case TYPE_FIRE:
                    damage = (15 * damage) / 10;
                    break;
                case TYPE_WATER:
                    damage /= 2;
                    break;
                }
            }
        }

        // flash fire triggered
        if ((gBattleResources->flags->flags[battlerIdAtk] & UNKNOWN_FLAG_FLASH_FIRE) && type == TYPE_FIRE)
            damage = (15 * damage) / 10;
    }

    return damage + 2;
}

u8 CountAliveMonsInBattle(u8 caseId)
{
    s32 i;
    u8 retVal = 0;

    switch (caseId)
    {
    case BATTLE_ALIVE_EXCEPT_ACTIVE:
        for (i = 0; i < 4; i++)
        {
            if (i != gActiveBattler && !(gAbsentBattlerFlags & gBitTable[i]))
                retVal++;
        }
        break;
    case BATTLE_ALIVE_ATK_SIDE:
        for (i = 0; i < 4; i++)
        {
            if (GetBattlerSide(i) == GetBattlerSide(gBattlerAttacker) && !(gAbsentBattlerFlags & gBitTable[i]))
                retVal++;
        }
        break;
    case BATTLE_ALIVE_DEF_SIDE:
        for (i = 0; i < 4; i++)
        {
            if (GetBattlerSide(i) == GetBattlerSide(gBattlerTarget) && !(gAbsentBattlerFlags & gBitTable[i]))
                retVal++;
        }
        break;
    }

    return retVal;
}

static bool8 ShouldGetStatBadgeBoost(u16 badgeFlag, u8 battlerId)
{
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_x2000000 | BATTLE_TYPE_FRONTIER))
        return FALSE;
    else if (GetBattlerSide(battlerId) != B_SIDE_PLAYER)
        return FALSE;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && gTrainerBattleOpponent_A == TRAINER_SECRET_BASE)
        return FALSE;
    else if (FlagGet(badgeFlag))
        return TRUE;
    else
        return FALSE;
}

u8 GetDefaultMoveTarget(u8 battlerId)
{
    u8 opposing = BATTLE_OPPOSITE(GetBattlerPosition(battlerId) & BIT_SIDE);

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return GetBattlerAtPosition(opposing);
    if (CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_ACTIVE) > 1)
    {
        u8 position;

        if ((Random() & 1) == 0)
            position = BATTLE_PARTNER(opposing);
        else
            position = opposing;

        return GetBattlerAtPosition(position);
    }
    else
    {
        if ((gAbsentBattlerFlags & gBitTable[opposing]))
            return GetBattlerAtPosition(BATTLE_PARTNER(opposing));
        else
            return GetBattlerAtPosition(opposing);
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

void SetMultiuseSpriteTemplateToPokemon(u16 species, u8 battlerPosition)
{
    if (gMonSpritesGfxPtr != NULL)
        gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
    else if (gUnknown_020249B4[0])
        gMultiuseSpriteTemplate = gUnknown_020249B4[0]->templates[battlerPosition];
    else if (gUnknown_020249B4[1])
        gMultiuseSpriteTemplate = gUnknown_020249B4[1]->templates[battlerPosition];
    else
        gMultiuseSpriteTemplate = gUnknown_08329D98[battlerPosition];

    gMultiuseSpriteTemplate.paletteTag = species;
    if (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_PLAYER_RIGHT)
        gMultiuseSpriteTemplate.anims = gPlayerMonSpriteAnimsTable;
    else if (species > 500)
        gMultiuseSpriteTemplate.anims = gMonAnimationsSpriteAnimsPtrTable[species - 500];
    else
        gMultiuseSpriteTemplate.anims = gMonAnimationsSpriteAnimsPtrTable[species];
}

void SetMultiuseSpriteTemplateToTrainerBack(u16 trainerSpriteId, u8 battlerPosition)
{
    gMultiuseSpriteTemplate.paletteTag = trainerSpriteId;
    if (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_PLAYER_RIGHT)
    {
        gMultiuseSpriteTemplate = gUnknown_08329DF8[trainerSpriteId];
        gMultiuseSpriteTemplate.anims = gUnknown_08305D0C[trainerSpriteId];
    }
    else
    {
        if (gMonSpritesGfxPtr != NULL)
            gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
        else
            gMultiuseSpriteTemplate = gUnknown_08329D98[battlerPosition];
        gMultiuseSpriteTemplate.anims = gUnknown_0830536C[trainerSpriteId];
    }
}

void SetMultiuseSpriteTemplateToTrainerFront(u16 arg0, u8 battlerPosition)
{
    if (gMonSpritesGfxPtr != NULL)
        gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
    else
        gMultiuseSpriteTemplate = gUnknown_08329D98[battlerPosition];

    gMultiuseSpriteTemplate.paletteTag = arg0;
    gMultiuseSpriteTemplate.anims = gUnknown_0830536C[arg0];
}

static void EncryptBoxMon(struct BoxPokemon *boxMon)
{
    u32 i;
    for (i = 0; i < 12; i++)
    {
        boxMon->secure.raw[i] ^= boxMon->personality;
        boxMon->secure.raw[i] ^= boxMon->otId;
    }
}

static void DecryptBoxMon(struct BoxPokemon *boxMon)
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


static union PokemonSubstruct *GetSubstruct(struct BoxPokemon *boxMon, u32 personality, u8 substructType)
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
        ret = (u16)GetDeoxysStat(mon, STAT_ATK);
        if (!ret)
            ret = mon->attack;
        break;
    case MON_DATA_DEF:
        ret = (u16)GetDeoxysStat(mon, STAT_DEF);
        if (!ret)
            ret = mon->defense;
        break;
    case MON_DATA_SPEED:
        ret = (u16)GetDeoxysStat(mon, STAT_SPEED);
        if (!ret)
            ret = mon->speed;
        break;
    case MON_DATA_SPATK:
        ret = (u16)GetDeoxysStat(mon, STAT_SPATK);
        if (!ret)
            ret = mon->spAttack;
        break;
    case MON_DATA_SPDEF:
        ret = (u16)GetDeoxysStat(mon, STAT_SPDEF);
        if (!ret)
            ret = mon->spDefense;
        break;
    case MON_DATA_ATK2:
        ret = mon->attack;
        break;
    case MON_DATA_DEF2:
        ret = mon->defense;
        break;
    case MON_DATA_SPEED2:
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
    const u8 *data = dataArg;

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
    const u8 *data = dataArg;

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

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;
    }

    if (i >= PARTY_SIZE)
        return SendMonToPC(mon);

    CopyMon(&gPlayerParty[i], mon, sizeof(*mon));
    gPlayerPartyCount = i + 1;
    return MON_GIVEN_TO_PARTY;
}

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
                gSpecialVar_MonBoxId = boxNo;
                gSpecialVar_MonBoxPos = boxPos;
                if (get_unknown_box_id() != boxNo)
                    FlagClear(FLAG_SYS_STORAGE_UNKNOWN_FLAG);
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

    for (i = 0; i < PARTY_SIZE; i++)
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

void CreateSecretBaseEnemyParty(struct SecretBaseRecord *secretBaseRecord)
{
    s32 i, j;

    ZeroEnemyPartyMons();
    *gBattleResources->secretBase = *secretBaseRecord;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gBattleResources->secretBase->party.species[i])
        {
            CreateMon(&gEnemyParty[i],
                gBattleResources->secretBase->party.species[i],
                gBattleResources->secretBase->party.levels[i],
                15,
                1,
                gBattleResources->secretBase->party.personality[i],
                2,
                0);

            SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleResources->secretBase->party.heldItems[i]);

            for (j = 0; j < 6; j++)
                SetMonData(&gEnemyParty[i], MON_DATA_HP_EV + j, &gBattleResources->secretBase->party.EVs[i]);

            for (j = 0; j < 4; j++)
            {
                SetMonData(&gEnemyParty[i], MON_DATA_MOVE1 + j, &gBattleResources->secretBase->party.moves[i * 4 + j]);
                SetMonData(&gEnemyParty[i], MON_DATA_PP1 + j, &gBattleMoves[gBattleResources->secretBase->party.moves[i * 4 + j]].pp);
            }
        }
    }
}

u8 GetSecretBaseTrainerPicIndex(void)
{
    u8 facilityClass = sSecretBaseFacilityClasses[gBattleResources->secretBase->gender][gBattleResources->secretBase->trainerId[0] % 5];
    return gFacilityClassToPicIndex[facilityClass];
}

u8 GetSecretBaseTrainerClass(void)
{
    u8 facilityClass = sSecretBaseFacilityClasses[gBattleResources->secretBase->gender][gBattleResources->secretBase->trainerId[0] % 5];
    return gFacilityClassToTrainerClass[facilityClass];
}

bool8 IsPlayerPartyAndPokemonStorageFull(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            return FALSE;

    return IsPokemonStorageFull();
}

bool8 IsPokemonStorageFull(void)
{
    s32 i, j;

    for (i = 0; i < 14; i++)
        for (j = 0; j < 30; j++)
            if (GetBoxMonDataFromAnyBox(i, j, MON_DATA_SPECIES) == SPECIES_NONE)
                return FALSE;

    return TRUE;
}

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

void CopyPlayerPartyMonToBattleData(u8 battlerId, u8 partyIndex)
{
    u16* hpSwitchout;
    s32 i;
    u8 nickname[POKEMON_NAME_LENGTH * 2];

    gBattleMons[battlerId].species = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES, NULL);
    gBattleMons[battlerId].item = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HELD_ITEM, NULL);

    for (i = 0; i < 4; i++)
    {
        gBattleMons[battlerId].moves[i] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE1 + i, NULL);
        gBattleMons[battlerId].pp[i] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PP1 + i, NULL);
    }

    gBattleMons[battlerId].ppBonuses = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PP_BONUSES, NULL);
    gBattleMons[battlerId].friendship = GetMonData(&gPlayerParty[partyIndex], MON_DATA_FRIENDSHIP, NULL);
    gBattleMons[battlerId].experience = GetMonData(&gPlayerParty[partyIndex], MON_DATA_EXP, NULL);
    gBattleMons[battlerId].hpIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HP_IV, NULL);
    gBattleMons[battlerId].attackIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_ATK_IV, NULL);
    gBattleMons[battlerId].defenseIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_DEF_IV, NULL);
    gBattleMons[battlerId].speedIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPEED_IV, NULL);
    gBattleMons[battlerId].spAttackIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPATK_IV, NULL);
    gBattleMons[battlerId].spDefenseIV = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPDEF_IV, NULL);
    gBattleMons[battlerId].personality = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PERSONALITY, NULL);
    gBattleMons[battlerId].status1 = GetMonData(&gPlayerParty[partyIndex], MON_DATA_STATUS, NULL);
    gBattleMons[battlerId].level = GetMonData(&gPlayerParty[partyIndex], MON_DATA_LEVEL, NULL);
    gBattleMons[battlerId].hp = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HP, NULL);
    gBattleMons[battlerId].maxHP = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MAX_HP, NULL);
    gBattleMons[battlerId].attack = GetMonData(&gPlayerParty[partyIndex], MON_DATA_ATK, NULL);
    gBattleMons[battlerId].defense = GetMonData(&gPlayerParty[partyIndex], MON_DATA_DEF, NULL);
    gBattleMons[battlerId].speed = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPEED, NULL);
    gBattleMons[battlerId].spAttack = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPATK, NULL);
    gBattleMons[battlerId].spDefense = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPDEF, NULL);
    gBattleMons[battlerId].isEgg = GetMonData(&gPlayerParty[partyIndex], MON_DATA_IS_EGG, NULL);
    gBattleMons[battlerId].altAbility = GetMonData(&gPlayerParty[partyIndex], MON_DATA_ALT_ABILITY, NULL);
    gBattleMons[battlerId].otId = GetMonData(&gPlayerParty[partyIndex], MON_DATA_OT_ID, NULL);
    gBattleMons[battlerId].type1 = gBaseStats[gBattleMons[battlerId].species].type1;
    gBattleMons[battlerId].type2 = gBaseStats[gBattleMons[battlerId].species].type2;
    gBattleMons[battlerId].ability = GetAbilityBySpecies(gBattleMons[battlerId].species, gBattleMons[battlerId].altAbility);
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_NICKNAME, nickname);
    StringCopy10(gBattleMons[battlerId].nickname, nickname);
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_OT_NAME, gBattleMons[battlerId].otName);

    hpSwitchout = &gBattleStruct->hpOnSwitchout[GetBattlerSide(battlerId)];
    *hpSwitchout = gBattleMons[battlerId].hp;

    for (i = 0; i < 8; i++)
        gBattleMons[battlerId].statStages[i] = 6;

    gBattleMons[battlerId].status2 = 0;
    sub_803FA70(battlerId);
    ClearTemporarySpeciesSpriteData(battlerId, FALSE);
}

bool8 ExecuteTableBasedItemEffect(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex)
{
    return PokemonUseItemEffects(mon, item, partyIndex, moveIndex, 0);
}

bool8 PokemonUseItemEffects(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex, u8 e)
{
    u32 dataUnsigned;
    s32 dataSigned;
    s32 friendship;
    s32 cmdIndex;
    bool8 retVal = TRUE;
    const u8 *itemEffect;
    u8 var_3C = 6;
    u32 var_38;
    s8 var_34 = 0;
    u8 holdEffect;
    u8 battlerId = 4;
    u32 var_28 = 0;
    u16 heldItem;
    u8 r10;
    u32 r4;
    u32 r5;
    s8 r2;
    u16 evCount;

    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    if (heldItem == ITEM_ENIGMA_BERRY)
    {
        if (gMain.inBattle)
            holdEffect = gEnigmaBerries[gBattlerInMenuId].holdEffect;
        else
            holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(heldItem);
    }

    gPotentialItemEffectBattler = gBattlerInMenuId;
    if (gMain.inBattle)
    {
        gActiveBattler = gBattlerInMenuId;
        cmdIndex = (GetBattlerSide(gActiveBattler) != B_SIDE_PLAYER);
        while (cmdIndex < gBattlersCount)
        {
            if (gBattlerPartyIndexes[cmdIndex] == partyIndex)
            {
                battlerId = cmdIndex;
                break;
            }
            cmdIndex += 2;
        }
    }
    else
    {
        gActiveBattler = 0;
        battlerId = MAX_BATTLERS_COUNT;
    }

    if (!IS_POKEMON_ITEM(item))
        return TRUE;
    if (gItemEffectTable[item - 13] == NULL && item != ITEM_ENIGMA_BERRY)
        return TRUE;

    if (item == ITEM_ENIGMA_BERRY)
    {
        if (gMain.inBattle)
            itemEffect = gEnigmaBerries[gActiveBattler].itemEffect;
        else
            itemEffect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
    }
    else
    {
        itemEffect = gItemEffectTable[item - 13];
    }

    for (cmdIndex = 0; cmdIndex < 6; cmdIndex++)
    {
        switch (cmdIndex)
        {
        // status healing effects
        case 0:
            if ((itemEffect[cmdIndex] & 0x80)
             && gMain.inBattle && battlerId != 4 && (gBattleMons[battlerId].status2 & STATUS2_INFATUATION))
            {
                gBattleMons[battlerId].status2 &= ~STATUS2_INFATUATION;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & 0x30)
             && !(gBattleMons[gActiveBattler].status2 & STATUS2_FOCUS_ENERGY))
            {
                gBattleMons[gActiveBattler].status2 |= STATUS2_FOCUS_ENERGY;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & 0xF)
             && gBattleMons[gActiveBattler].statStages[STAT_ATK] < 12)
            {
                gBattleMons[gActiveBattler].statStages[STAT_ATK] += itemEffect[cmdIndex] & 0xF;
                if (gBattleMons[gActiveBattler].statStages[STAT_ATK] > 12)
                    gBattleMons[gActiveBattler].statStages[STAT_ATK] = 12;
                retVal = FALSE;
            }
            break;
        // in-battle stat boosting effects?
        case 1:
            if ((itemEffect[cmdIndex] & 0xF0)
             && gBattleMons[gActiveBattler].statStages[STAT_DEF] < 12)
            {
                gBattleMons[gActiveBattler].statStages[STAT_DEF] += (itemEffect[cmdIndex] & 0xF0) >> 4;
                if (gBattleMons[gActiveBattler].statStages[STAT_DEF] > 12)
                    gBattleMons[gActiveBattler].statStages[STAT_DEF] = 12;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & 0xF)
             && gBattleMons[gActiveBattler].statStages[STAT_SPEED] < 12)
            {
                gBattleMons[gActiveBattler].statStages[STAT_SPEED] += itemEffect[cmdIndex] & 0xF;
                if (gBattleMons[gActiveBattler].statStages[STAT_SPEED] > 12)
                    gBattleMons[gActiveBattler].statStages[STAT_SPEED] = 12;
                retVal = FALSE;
            }
            break;
        // more stat boosting effects?
        case 2:
            if ((itemEffect[cmdIndex] & 0xF0)
             && gBattleMons[gActiveBattler].statStages[STAT_ACC] < 12)
            {
                gBattleMons[gActiveBattler].statStages[STAT_ACC] += (itemEffect[cmdIndex] & 0xF0) >> 4;
                if (gBattleMons[gActiveBattler].statStages[STAT_ACC] > 12)
                    gBattleMons[gActiveBattler].statStages[STAT_ACC] = 12;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & 0xF)
             && gBattleMons[gActiveBattler].statStages[STAT_SPATK] < 12)
            {
                gBattleMons[gActiveBattler].statStages[STAT_SPATK] += itemEffect[cmdIndex] & 0xF;
                if (gBattleMons[gActiveBattler].statStages[STAT_SPATK] > 12)
                    gBattleMons[gActiveBattler].statStages[STAT_SPATK] = 12;
                retVal = FALSE;
            }
            break;
        case 3:
            if ((itemEffect[cmdIndex] & 0x80)
             && gSideTimers[GetBattlerSide(gActiveBattler)].mistTimer == 0)
            {
                gSideTimers[GetBattlerSide(gActiveBattler)].mistTimer = 5;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & 0x40)  // raise level
             && GetMonData(mon, MON_DATA_LEVEL, NULL) != MAX_MON_LEVEL)
            {
                dataUnsigned = gExperienceTables[gBaseStats[GetMonData(mon, MON_DATA_SPECIES, NULL)].growthRate][GetMonData(mon, MON_DATA_LEVEL, NULL) + 1];
                SetMonData(mon, MON_DATA_EXP, &dataUnsigned);
                CalculateMonStats(mon);
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & 0x20)
             && HealStatusConditions(mon, partyIndex, 7, battlerId) == 0)
            {
                if (battlerId != 4)
                    gBattleMons[battlerId].status2 &= ~STATUS2_NIGHTMARE;
                retVal = FALSE;
            }
            if ((itemEffect[cmdIndex] & 0x10) && HealStatusConditions(mon, partyIndex, STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER, battlerId) == 0)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & 8) && HealStatusConditions(mon, partyIndex, STATUS1_BURN, battlerId) == 0)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & 4) && HealStatusConditions(mon, partyIndex, STATUS1_FREEZE, battlerId) == 0)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & 2) && HealStatusConditions(mon, partyIndex, STATUS1_PARALYSIS, battlerId) == 0)
                retVal = FALSE;
            if ((itemEffect[cmdIndex] & 1)  // heal confusion
             && gMain.inBattle && battlerId != 4 && (gBattleMons[battlerId].status2 & STATUS2_CONFUSION))
            {
                gBattleMons[battlerId].status2 &= ~STATUS2_CONFUSION;
                retVal = FALSE;
            }
            break;
        // EV, HP, and PP raising effects
        case 4:
            r10 = itemEffect[cmdIndex];
            if (r10 & 0x20)
            {
                r10 &= ~0x20;
                dataUnsigned = (GetMonData(mon, MON_DATA_PP_BONUSES, NULL) & gUnknown_08329D22[moveIndex]) >> (moveIndex * 2);
                var_38 = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);
                if (dataUnsigned <= 2 && var_38 > 4)
                {
                    dataUnsigned = GetMonData(mon, MON_DATA_PP_BONUSES, NULL) + gUnknown_08329D2A[moveIndex];
                    SetMonData(mon, MON_DATA_PP_BONUSES, &dataUnsigned);

                    dataUnsigned = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), dataUnsigned, moveIndex) - var_38;
                    dataUnsigned = GetMonData(mon, MON_DATA_PP1 + moveIndex, NULL) + dataUnsigned;
                    SetMonData(mon, MON_DATA_PP1 + moveIndex, &dataUnsigned);
                    retVal = FALSE;
                }
            }
            var_38 = 0;
            while (r10 != 0)
            {
                if (r10 & 1)
                {
                    switch (var_38)
                    {
                    case 0:
                    case 1:
                        evCount = GetMonEVCount(mon);
                        r5 = itemEffect[var_3C];
                        dataSigned = GetMonData(mon, sGetMonDataEVConstants[var_38], NULL);
                        r2 = r5;
                        if (r2 > 0)
                        {
                            if (evCount >= MAX_TOTAL_EVS)
                                return TRUE;
                            if (dataSigned >= 100)
                                break;

                            if (dataSigned + r2 > 100)
                                r5 = 100 - (dataSigned + r2) + r2;
                            else
                                r5 = r2;

                            if (evCount + r5 > MAX_TOTAL_EVS)
                                r5 += MAX_TOTAL_EVS - (evCount + r5);
                            dataSigned += r5;
                        }
                        else
                        {
                            if (dataSigned == 0)
                            {
                                var_28 = 1;
                                var_3C++;
                                break;
                            }
                            dataSigned += r2;
                            if (dataSigned < 0)
                                dataSigned = 0;
                        }
                        SetMonData(mon, sGetMonDataEVConstants[var_38], &dataSigned);
                        CalculateMonStats(mon);
                        var_3C++;
                        retVal = FALSE;
                        break;
                    case 2:
                        // revive?
                        if (r10 & 0x10)
                        {
                            if (GetMonData(mon, MON_DATA_HP, NULL) != 0)
                            {
                                var_3C++;
                                break;
                            }
                            if (gMain.inBattle)
                            {
                                if (battlerId != 4)
                                {
                                    gAbsentBattlerFlags &= ~gBitTable[battlerId];
                                    CopyPlayerPartyMonToBattleData(battlerId, pokemon_order_func(gBattlerPartyIndexes[battlerId]));
                                    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER && gBattleResults.unk4 < 255)
                                        gBattleResults.unk4++;
                                }
                                else
                                {
                                    gAbsentBattlerFlags &= ~gBitTable[gActiveBattler ^ 2];
                                    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER && gBattleResults.unk4 < 255)
                                        gBattleResults.unk4++;
                                }
                            }
                        }
                        else
                        {
                            if (GetMonData(mon, MON_DATA_HP, NULL) == 0)
                            {
                                var_3C++;
                                break;
                            }
                        }
                        dataUnsigned = itemEffect[var_3C++];
                        switch (dataUnsigned)
                        {
                        case 0xFF:
                            dataUnsigned = GetMonData(mon, MON_DATA_MAX_HP, NULL) - GetMonData(mon, MON_DATA_HP, NULL);
                            break;
                        case 0xFE:
                            dataUnsigned = GetMonData(mon, MON_DATA_MAX_HP, NULL) / 2;
                            if (dataUnsigned == 0)
                                dataUnsigned = 1;
                            break;
                        case 0xFD:
                            dataUnsigned = gBattleScripting.field_23;
                            break;
                        }
                        if (GetMonData(mon, MON_DATA_MAX_HP, NULL) != GetMonData(mon, MON_DATA_HP, NULL))
                        {
                            if (e == 0)
                            {
                                dataUnsigned = GetMonData(mon, MON_DATA_HP, NULL) + dataUnsigned;
                                if (dataUnsigned > GetMonData(mon, MON_DATA_MAX_HP, NULL))
                                    dataUnsigned = GetMonData(mon, MON_DATA_MAX_HP, NULL);
                                SetMonData(mon, MON_DATA_HP, &dataUnsigned);
                                if (gMain.inBattle && battlerId != 4)
                                {
                                    gBattleMons[battlerId].hp = dataUnsigned;
                                    if (!(r10 & 0x10) && GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
                                    {
                                        if (gBattleResults.unk3 < 255)
                                            gBattleResults.unk3++;
                                        // I have to re-use this variable to match.
                                        r5 = gActiveBattler;
                                        gActiveBattler = battlerId;
                                        BtlController_EmitGetMonData(0, 0, 0);
                                        MarkBattlerForControllerExec(gActiveBattler);
                                        gActiveBattler = r5;
                                    }
                                }
                            }
                            else
                            {
                                gBattleMoveDamage = -dataUnsigned;
                            }
                            retVal = FALSE;
                        }
                        r10 &= 0xEF;
                        break;
                    case 3:
                        if (!(r10 & 2))
                        {
                            for (r5 = 0; (signed)(r5) < (signed)(4); r5++)
                            {
                                u16 moveId;

                                dataUnsigned = GetMonData(mon, MON_DATA_PP1 + r5, NULL);
                                moveId = GetMonData(mon, MON_DATA_MOVE1 + r5, NULL);
                                if (dataUnsigned != CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), r5))
                                {
                                    dataUnsigned += itemEffect[var_3C];
                                    moveId = GetMonData(mon, MON_DATA_MOVE1 + r5, NULL);
                                    if (dataUnsigned > CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), r5))
                                    {
                                        moveId = GetMonData(mon, MON_DATA_MOVE1 + r5, NULL);
                                        dataUnsigned = CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), r5);
                                    }
                                    SetMonData(mon, MON_DATA_PP1 + r5, &dataUnsigned);
                                    if (gMain.inBattle
                                     && battlerId != 4 && !(gBattleMons[battlerId].status2 & STATUS2_TRANSFORMED)
                                     && !(gDisableStructs[battlerId].unk18_b & gBitTable[r5]))
                                        gBattleMons[battlerId].pp[r5] = dataUnsigned;
                                    retVal = FALSE;
                                }
                            }
                            var_3C++;
                        }
                        else
                        {
                            u16 moveId;

                            dataUnsigned = GetMonData(mon, MON_DATA_PP1 + moveIndex, NULL);
                            moveId = GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL);
                            if (dataUnsigned != CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex))
                            {
                                dataUnsigned += itemEffect[var_3C++];
                                moveId = GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL);
                                if (dataUnsigned > CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex))
                                {
                                    moveId = GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL);
                                    dataUnsigned = CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);
                                }
                                SetMonData(mon, MON_DATA_PP1 + moveIndex, &dataUnsigned);
                                if (gMain.inBattle
                                 && battlerId != 4 && !(gBattleMons[battlerId].status2 & STATUS2_TRANSFORMED)
                                 && !(gDisableStructs[battlerId].unk18_b & gBitTable[moveIndex]))
                                    gBattleMons[battlerId].pp[moveIndex] = dataUnsigned;
                                retVal = FALSE;
                            }
                        }
                        break;
                    case 7:
                        {
                            u16 targetSpecies = GetEvolutionTargetSpecies(mon, 2, item);

                            if (targetSpecies != SPECIES_NONE)
                            {
                                BeginEvolutionScene(mon, targetSpecies, 0, partyIndex);
                                return FALSE;
                            }
                        }
                        break;
                    }
                }
                var_38++;
                r10 >>= 1;
            }
            break;
        case 5:
            r10 = itemEffect[cmdIndex];
            var_38 = 0;
            while (r10 != 0)
            {
                if (r10 & 1)
                {
                    switch (var_38)
                    {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                        evCount = GetMonEVCount(mon);
                        r5 = itemEffect[var_3C];
                        dataSigned = GetMonData(mon, sGetMonDataEVConstants[var_38 + 2], NULL);
                        r2 = r5;
                        if (r2 > 0)
                        {
                            if (evCount >= MAX_TOTAL_EVS)
                                return TRUE;
                            if (dataSigned >= 100)
                                break;

                            if (dataSigned + r2 > 100)
                                r5 = 100 - (dataSigned + r2) + r2;
                            else
                                r5 = r2;

                            if (evCount + r5 > MAX_TOTAL_EVS)
                                r5 += MAX_TOTAL_EVS - (evCount + r5);
                            dataSigned += r5;
                        }
                        else
                        {
                            if (dataSigned == 0)
                            {
                                var_28 = 1;
                                var_3C++;
                                break;
                            }
                            dataSigned += r2;
                            if (dataSigned < 0)
                                dataSigned = 0;
                        }
                        SetMonData(mon, sGetMonDataEVConstants[var_38 + 2], &dataSigned);
                        CalculateMonStats(mon);
                        retVal = FALSE;
                        var_3C++;
                        break;
                    case 4:
                        dataUnsigned = (GetMonData(mon, MON_DATA_PP_BONUSES, NULL) & gUnknown_08329D22[moveIndex]) >> (moveIndex * 2);
                        r5 = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);
                        if (dataUnsigned < 3 && r5 > 4)
                        {
                            dataUnsigned = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
                            dataUnsigned &= gUnknown_08329D26[moveIndex];
                            dataUnsigned += gUnknown_08329D2A[moveIndex] * 3;

                            SetMonData(mon, MON_DATA_PP_BONUSES, &dataUnsigned);
                            dataUnsigned = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), dataUnsigned, moveIndex) - r5;
                            dataUnsigned = GetMonData(mon, MON_DATA_PP1 + moveIndex, NULL) + dataUnsigned;
                            SetMonData(mon, MON_DATA_PP1 + moveIndex, &dataUnsigned);
                            retVal = FALSE;
                        }
                        break;
                    case 5:
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) < 100 && (retVal == 0 || var_28 != 0) && !sub_806F104() && var_34 == 0)
                        {
                            var_34 = itemEffect[var_3C];
                            friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
                            if (var_34 > 0 && holdEffect == HOLD_EFFECT_HAPPINESS_UP)
                                friendship += 150 * var_34 / 100;
                            else
                                friendship += var_34;
                            if (var_34 > 0)
                            {
                                if (GetMonData(mon, MON_DATA_POKEBALL, NULL) == 11)
                                    friendship++;
                                if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == sav1_map_get_name())
                                    friendship++;
                            }
                            if (friendship < 0)
                                friendship = 0;
                            if (friendship > 255)
                                friendship = 255;
                            SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
                            retVal = FALSE;
                        }
                        var_3C++;
                        break;
                    case 6:
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) >= 100 && GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) < 200
                         && (retVal == 0 || var_28 != 0) && !sub_806F104() && var_34 == 0)
                        {
                            var_34 = itemEffect[var_3C];
                            friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
                            if ((s8)(var_34) > 0 && holdEffect == HOLD_EFFECT_HAPPINESS_UP)
                                friendship += 150 * var_34 / 100;
                            else
                                friendship += var_34;
                            if (var_34 > 0)
                            {
                                if (GetMonData(mon, MON_DATA_POKEBALL, NULL) == 11)
                                    friendship++;
                                if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == sav1_map_get_name())
                                    friendship++;
                            }
                            if (friendship < 0)
                                friendship = 0;
                            if (friendship > 255)
                                friendship = 255;
                            SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
                            retVal = FALSE;
                        }
                        var_3C++;
                        break;
                    case 7:
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) >= 200 && (retVal == 0 || var_28 != 0) && !sub_806F104() && var_34 == 0)
                        {
                            var_34 = itemEffect[var_3C];
                            friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
                            if ((s8)(var_34) > 0 && holdEffect == HOLD_EFFECT_HAPPINESS_UP)
                                friendship += 150 * var_34 / 100;
                            else
                                friendship += var_34;
                            if (var_34 > 0)
                            {
                                if (GetMonData(mon, MON_DATA_POKEBALL, NULL) == 11)
                                    friendship++;
                                if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == sav1_map_get_name())
                                    friendship++;
                            }
                            if (friendship < 0)
                                friendship = 0;
                            if (friendship > 255)
                                friendship = 255;
                            SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
                            retVal = FALSE;
                        }
                        var_3C++;
                        break;
                    }
                }
                var_38++;
                r10 >>= 1;
            }
            break;
        }
    }
    return retVal;
}

bool8 HealStatusConditions(struct Pokemon *mon, u32 battlePartyId, u32 healMask, u8 battlerId)
{
    u32 status = GetMonData(mon, MON_DATA_STATUS, 0);

    if (status & healMask)
    {
        status &= ~healMask;
        SetMonData(mon, MON_DATA_STATUS, &status);
        if (gMain.inBattle && battlerId != MAX_BATTLERS_COUNT)
            gBattleMons[battlerId].status1 &= ~healMask;
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

u8 GetItemEffectParamOffset(u16 itemId, u8 effectByte, u8 effectBit)
{
    const u8 *temp;
    const u8 *itemEffect;
    u8 offset;
    int i;
    u8 j;
    u8 val;

    offset = 6;

    temp = gItemEffectTable[itemId - 13];

    if (!temp && itemId != ITEM_ENIGMA_BERRY)
        return 0;

    if (itemId == ITEM_ENIGMA_BERRY)
    {
        temp = gEnigmaBerries[gActiveBattler].itemEffect;
    }

    itemEffect = temp;

    for (i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
        case 1:
        case 2:
        case 3:
            if (i == effectByte)
                return 0;
            break;
        case 4:
            val = itemEffect[4];
            if (val & 0x20)
                val &= 0xDF;
            j = 0;
            while (val)
            {
                if (val & 1)
                {
                    switch (j)
                    {
                    case 2:
                        if (val & 0x10)
                            val &= 0xEF;
                    case 0:
                        if (i == effectByte && (val & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 1:
                        if (i == effectByte && (val & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 3:
                        if (i == effectByte && (val & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 7:
                        if (i == effectByte)
                            return 0;
                        break;
                    }
                }
                j++;
                val >>= 1;
                if (i == effectByte)
                    effectBit >>= 1;
            }
            break;
        case 5:
            val = itemEffect[5];
            j = 0;
            while (val)
            {
                if (val & 1)
                {
                    switch (j)
                    {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                        if (i == effectByte && (val & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 7:
                        if (i == effectByte)
                            return 0;
                        break;
                    }
                }
                j++;
                val >>= 1;
                if (i == effectByte)
                    effectBit >>= 1;
            }
            break;
        }
    }

    return offset;
}

static void sub_806CF24(s32 arg0)
{
    gBattlerTarget = gBattlerInMenuId;
    StringCopy(gBattleTextBuff1, gStatNamesTable[gUnknown_08329EC8[arg0]]);
    StringCopy(gBattleTextBuff2, gText_StatRose);
    BattleStringExpandPlaceholdersToDisplayedString(gText_PkmnsStatChanged2);
}

u8 *sub_806CF78(u16 itemId)
{
    int i;
    const u8 *itemEffect;

    if (itemId == ITEM_ENIGMA_BERRY)
    {
        if (gMain.inBattle)
            itemEffect = gEnigmaBerries[gBattlerInMenuId].itemEffect;
        else
            itemEffect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
    }
    else
    {
        itemEffect = gItemEffectTable[itemId - 13];
    }

    gPotentialItemEffectBattler = gBattlerInMenuId;

    for (i = 0; i < 3; i++)
    {
        if (itemEffect[i] & 0xF)
            sub_806CF24(i * 2);
        if (itemEffect[i] & 0xF0)
        {
            if (i)
            {
                sub_806CF24(i * 2 + 1);
            }
            else
            {
                gBattlerAttacker = gBattlerInMenuId;
                BattleStringExpandPlaceholdersToDisplayedString(gText_PkmnGettingPumped);
            }
        }
    }

    if (itemEffect[3] & 0x80)
    {
        gBattlerAttacker = gBattlerInMenuId;
        BattleStringExpandPlaceholdersToDisplayedString(gText_PkmnShroudedInMist);
    }

    return gDisplayedStringBattle;
}

u8 GetNature(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_PERSONALITY, 0) % 25;
}

u8 GetNatureFromPersonality(u32 personality)
{
    return personality % 25;
}

u16 GetEvolutionTargetSpecies(struct Pokemon *mon, u8 type, u16 evolutionItem)
{
    int i;
    u16 targetSpecies = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u16 heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, 0);
    u8 level;
    u16 friendship;
    u8 beauty = GetMonData(mon, MON_DATA_BEAUTY, 0);
    u16 upperPersonality = personality >> 16;
    u8 holdEffect;

    if (heldItem == ITEM_ENIGMA_BERRY)
        holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(heldItem);

    if (holdEffect == HOLD_EFFECT_PREVENT_EVOLVE && type != 3)
        return 0;

    switch (type)
    {
    case 0:
        level = GetMonData(mon, MON_DATA_LEVEL, 0);
        friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, 0);

        for (i = 0; i < 5; i++)
        {
            switch (gEvolutionTable[species][i].method)
            {
            case EVO_FRIENDSHIP:
                if (friendship >= 220)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_FRIENDSHIP_DAY:
                RtcCalcLocalTime();
                if (gLocalTime.hours >= 12 && gLocalTime.hours < 24 && friendship >= 220)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_FRIENDSHIP_NIGHT:
                RtcCalcLocalTime();
                if (gLocalTime.hours >= 0 && gLocalTime.hours < 12 && friendship >= 220)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL:
                if (gEvolutionTable[species][i].param <= level)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_ATK_GT_DEF:
                if (gEvolutionTable[species][i].param <= level)
                    if (GetMonData(mon, MON_DATA_ATK, 0) > GetMonData(mon, MON_DATA_DEF, 0))
                        targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_ATK_EQ_DEF:
                if (gEvolutionTable[species][i].param <= level)
                    if (GetMonData(mon, MON_DATA_ATK, 0) == GetMonData(mon, MON_DATA_DEF, 0))
                        targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_ATK_LT_DEF:
                if (gEvolutionTable[species][i].param <= level)
                    if (GetMonData(mon, MON_DATA_ATK, 0) < GetMonData(mon, MON_DATA_DEF, 0))
                        targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_SILCOON:
                if (gEvolutionTable[species][i].param <= level && (upperPersonality % 10) <= 4)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_CASCOON:
                if (gEvolutionTable[species][i].param <= level && (upperPersonality % 10) > 4)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_LEVEL_NINJASK:
                if (gEvolutionTable[species][i].param <= level)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_BEAUTY:
                if (gEvolutionTable[species][i].param <= beauty)
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            }
        }
        break;
    case 1:
        for (i = 0; i < 5; i++)
        {
            switch (gEvolutionTable[species][i].method)
            {
            case EVO_TRADE:
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            case EVO_TRADE_ITEM:
                if (gEvolutionTable[species][i].param == heldItem)
                {
                    heldItem = 0;
                    SetMonData(mon, MON_DATA_HELD_ITEM, (u8 *)&heldItem);
                    targetSpecies = gEvolutionTable[species][i].targetSpecies;
                }
                break;
            }
        }
        break;
    case 2:
    case 3:
        for (i = 0; i < 5; i++)
        {
            if (gEvolutionTable[species][i].method == EVO_ITEM
             && gEvolutionTable[species][i].param == evolutionItem)
            {
                targetSpecies = gEvolutionTable[species][i].targetSpecies;
                break;
            }
        }
        break;
    }

    return targetSpecies;
}

u16 HoennPokedexNumToSpecies(u16 hoennNum)
{
    u16 species;

    if (!hoennNum)
        return 0;

    species = 0;

    while (species < 411 && gSpeciesToHoennPokedexNum[species] != hoennNum)
        species++;

    if (species == 411)
        return 0;

    return species + 1;
}

u16 NationalPokedexNumToSpecies(u16 nationalNum)
{
    u16 species;

    if (!nationalNum)
        return 0;

    species = 0;

    while (species < 411 && gSpeciesToNationalPokedexNum[species] != nationalNum)
        species++;

    if (species == 411)
        return 0;

    return species + 1;
}

u16 NationalToHoennOrder(u16 nationalNum)
{
    u16 hoennNum;

    if (!nationalNum)
        return 0;

    hoennNum = 0;

    while (hoennNum < 411 && gHoennToNationalOrder[hoennNum] != nationalNum)
        hoennNum++;

    if (hoennNum == 411)
        return 0;

    return hoennNum + 1;
}

u16 SpeciesToNationalPokedexNum(u16 species)
{
    if (!species)
        return 0;

    return gSpeciesToNationalPokedexNum[species - 1];
}

u16 SpeciesToHoennPokedexNum(u16 species)
{
    if (!species)
        return 0;

    return gSpeciesToHoennPokedexNum[species - 1];
}

u16 HoennToNationalOrder(u16 hoennNum)
{
    if (!hoennNum)
        return 0;

    return gHoennToNationalOrder[hoennNum - 1];
}

u16 SpeciesToCryId(u16 species)
{
    if (species <= 250)
        return species;

    if (species < 276)
        return 200;

    return gSpeciesIdToCryId[species - 276];
}

void sub_806D544(u16 species, u32 personality, u8 *dest)
{
    if (species == SPECIES_SPINDA
        && dest != gMonSpritesGfxPtr->sprites[0]
        && dest != gMonSpritesGfxPtr->sprites[2])
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            int j;
            u8 x = gSpindaSpotGraphics[i].x + ((personality & 0x0F) - 8);
            u8 y = gSpindaSpotGraphics[i].y + (((personality & 0xF0) >> 4) - 8);

            for (j = 0; j < 16; j++)
            {
                int k;
                s32 row = gSpindaSpotGraphics[i].image[j];

                for (k = x; k < x + 16; k++)
                {
                    u8 *val = dest + ((k / 8) * 32) + ((k % 8) / 2) + ((y >> 3) << 8) + ((y & 7) << 2);

                    if (row & 1)
                    {
                        if (k & 1)
                        {
                            if ((u8)((*val & 0xF0) - 0x10) <= 0x20)
                                *val += 0x40;
                        }
                        else
                        {
                            if ((u8)((*val & 0xF) - 0x01) <= 0x02)
                                *val += 0x04;
                        }
                    }

                    row >>= 1;
                }

                y++;
            }

            personality >>= 8;
        }
    }
}

void DrawSpindaSpots(u16 species, u32 personality, u8 *dest, u8 a4)
{
    if (species == SPECIES_SPINDA && a4)
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            int j;
            u8 x = gSpindaSpotGraphics[i].x + ((personality & 0x0F) - 8);
            u8 y = gSpindaSpotGraphics[i].y + (((personality & 0xF0) >> 4) - 8);

            for (j = 0; j < 16; j++)
            {
                int k;
                s32 row = gSpindaSpotGraphics[i].image[j];

                for (k = x; k < x + 16; k++)
                {
                    u8 *val = dest + ((k / 8) * 32) + ((k % 8) / 2) + ((y >> 3) << 8) + ((y & 7) << 2);

                    if (row & 1)
                    {
                        if (k & 1)
                        {
                            if ((u8)((*val & 0xF0) - 0x10) <= 0x20)
                                *val += 0x40;
                        }
                        else
                        {
                            if ((u8)((*val & 0xF) - 0x01) <= 0x02)
                                *val += 0x04;
                        }
                    }

                    row >>= 1;
                }

                y++;
            }

            personality >>= 8;
        }
    }
}

void EvolutionRenameMon(struct Pokemon *mon, u16 oldSpecies, u16 newSpecies)
{
    u8 language;
    GetMonData(mon, MON_DATA_NICKNAME, gStringVar1);
    language = GetMonData(mon, MON_DATA_LANGUAGE, &language);
    if (language == GAME_LANGUAGE && !StringCompare(gSpeciesNames[oldSpecies], gStringVar1))
        SetMonData(mon, MON_DATA_NICKNAME, gSpeciesNames[newSpecies]);
}

bool8 sub_806D7EC(void)
{
    bool8 retVal = FALSE;
    switch (gLinkPlayers[GetMultiplayerId()].lp_field_18)
    {
    case 0:
    case 3:
        retVal = FALSE;
        break;
    case 1:
    case 2:
        retVal = TRUE;
        break;
    }
    return retVal;
}

u16 GetLinkTrainerFlankId(u8 linkPlayerId)
{
    u16 flankId = 0;
    switch (gLinkPlayers[linkPlayerId].lp_field_18)
    {
    case 0:
    case 3:
        flankId = 0;
        break;
    case 1:
    case 2:
        flankId = 1;
        break;
    }
    return flankId;
}

s32 GetBattlerMultiplayerId(u16 a1)
{
    s32 id;
    for (id = 0; id < MAX_LINK_PLAYERS; id++)
        if (gLinkPlayers[id].lp_field_18 == a1)
            break;
    return id;
}

u8 GetTrainerEncounterMusicId(u16 trainerOpponentId)
{
    if (InBattlePyramid())
        return GetTrainerEncounterMusicIdInBattlePyramind(trainerOpponentId);
    else if (sub_81D5C18())
        return sub_81D63C8(trainerOpponentId);
    else
        return TRAINER_ENCOUNTER_MUSIC(trainerOpponentId);
}

u16 ModifyStatByNature(u8 nature, u16 n, u8 statIndex)
{
    if (statIndex < 1 || statIndex > 5)
    {
        // Should just be "return n", but it wouldn't match without this.
        u16 retVal = n;
        retVal++;
        retVal--;
        return retVal;
    }

    switch (gNatureStatTable[nature][statIndex - 1])
    {
    case 1:
        return (u16)(n * 110) / 100;
    case -1:
        return (u16)(n * 90) / 100;
    }

    return n;
}

void AdjustFriendship(struct Pokemon *mon, u8 event)
{
    u16 species, heldItem;
    u8 holdEffect;

    if (sub_806F104())
        return;

    species = GetMonData(mon, MON_DATA_SPECIES2, 0);
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);

    if (heldItem == ITEM_ENIGMA_BERRY)
    {
        if (gMain.inBattle)
            holdEffect = gEnigmaBerries[0].holdEffect;
        else
            holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(heldItem);
    }

    if (species && species != SPECIES_EGG)
    {
        u8 friendshipLevel = 0;
        s16 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, 0);
        if (friendship > 99)
            friendshipLevel++;
        if (friendship > 199)
            friendshipLevel++;
        if ((event != 5 || !(Random() & 1))
         && (event != 3
          || ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
           && (gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_ELITE_FOUR
            || gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_LEADER
            || gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_CHAMPION))))
        {
            s8 mod = gUnknown_08329ECE[event][friendshipLevel];
            if (mod > 0 && holdEffect == HOLD_EFFECT_HAPPINESS_UP)
                mod = (150 * mod) / 100;
            friendship += mod;
            if (mod > 0)
            {
                if (GetMonData(mon, MON_DATA_POKEBALL, 0) == ITEM_LUXURY_BALL)
                    friendship++;
                if (GetMonData(mon, MON_DATA_MET_LOCATION, 0) == sav1_map_get_name())
                    friendship++;
            }
            if (friendship < 0)
                friendship = 0;
            if (friendship > 255)
                friendship = 255;
            SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
        }
    }
}

void MonGainEVs(struct Pokemon *mon, u16 defeatedSpecies)
{
    u8 evs[NUM_STATS];
    u16 evIncrease = 0;
    u16 totalEVs = 0;
    u16 heldItem;
    u8 holdEffect;
    int i;

    for (i = 0; i < NUM_STATS; i++)
    {
        evs[i] = GetMonData(mon, MON_DATA_HP_EV + i, 0);
        totalEVs += evs[i];
    }

    for (i = 0; i < NUM_STATS; i++)
    {
        u8 hasHadPokerus;
        int multiplier;

        if (totalEVs >= MAX_TOTAL_EVS)
            break;

        hasHadPokerus = CheckPartyHasHadPokerus(mon, 0);

        if (hasHadPokerus)
            multiplier = 2;
        else
            multiplier = 1;

        switch (i)
        {
        case 0:
            evIncrease = gBaseStats[defeatedSpecies].evYield_HP * multiplier;
            break;
        case 1:
            evIncrease = gBaseStats[defeatedSpecies].evYield_Attack * multiplier;
            break;
        case 2:
            evIncrease = gBaseStats[defeatedSpecies].evYield_Defense * multiplier;
            break;
        case 3:
            evIncrease = gBaseStats[defeatedSpecies].evYield_Speed * multiplier;
            break;
        case 4:
            evIncrease = gBaseStats[defeatedSpecies].evYield_SpAttack * multiplier;
            break;
        case 5:
            evIncrease = gBaseStats[defeatedSpecies].evYield_SpDefense * multiplier;
            break;
        }

        heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);

        if (heldItem == ITEM_ENIGMA_BERRY)
        {
            if (gMain.inBattle)
                holdEffect = gEnigmaBerries[0].holdEffect;
            else
                holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
        }
        else
        {
            holdEffect = ItemId_GetHoldEffect(heldItem);
        }

        if (holdEffect == HOLD_EFFECT_MACHO_BRACE)
            evIncrease *= 2;

        if (totalEVs + (s16)evIncrease > MAX_TOTAL_EVS)
            evIncrease = ((s16)evIncrease + MAX_TOTAL_EVS) - (totalEVs + evIncrease);

        if (evs[i] + (s16)evIncrease > 255)
        {
            int val1 = (s16)evIncrease + 255;
            int val2 = evs[i] + evIncrease;
            evIncrease = val1 - val2;
        }

        evs[i] += evIncrease;
        totalEVs += evIncrease;
        SetMonData(mon, MON_DATA_HP_EV + i, &evs[i]);
    }
}

u16 GetMonEVCount(struct Pokemon *mon)
{
    int i;
    u16 count = 0;

    for (i = 0; i < NUM_STATS; i++)
        count += GetMonData(mon, MON_DATA_HP_EV + i, 0);

    return count;
}

void RandomlyGivePartyPokerus(struct Pokemon *party)
{
    u16 rnd = Random();
    if (rnd == 0x4000 || rnd == 0x8000 || rnd == 0xC000)
    {
        struct Pokemon *mon;

        do
        {
            do
            {
                rnd = Random() % PARTY_SIZE;
                mon = &party[rnd];
            }
            while (!GetMonData(mon, MON_DATA_SPECIES, 0));
        }
        while (GetMonData(mon, MON_DATA_IS_EGG, 0));

        if (!(CheckPartyHasHadPokerus(party, gBitTable[rnd])))
        {
            u8 rnd2;

            do
            {
                rnd2 = Random();
            }
            while ((rnd2 & 0x7) == 0);

            if (rnd2 & 0xF0)
                rnd2 &= 0x7;

            rnd2 |= (rnd2 << 4);
            rnd2 &= 0xF3;
            rnd2++;

            SetMonData(&party[rnd], MON_DATA_POKERUS, &rnd2);
        }
    }
}

u8 CheckPartyPokerus(struct Pokemon *party, u8 selection)
{
    u8 retVal;

    int partyIndex = 0;
    unsigned curBit = 1;
    retVal = 0;

    if (selection)
    {
        do
        {
            if ((selection & 1) && (GetMonData(&party[partyIndex], MON_DATA_POKERUS, 0) & 0xF))
                retVal |= curBit;
            partyIndex++;
            curBit <<= 1;
            selection >>= 1;
        }
        while (selection);
    }
    else if (GetMonData(&party[0], MON_DATA_POKERUS, 0) & 0xF)
    {
        retVal = 1;
    }

    return retVal;
}

u8 CheckPartyHasHadPokerus(struct Pokemon *party, u8 selection)
{
    u8 retVal;

    int partyIndex = 0;
    unsigned curBit = 1;
    retVal = 0;

    if (selection)
    {
        do
        {
            if ((selection & 1) && GetMonData(&party[partyIndex], MON_DATA_POKERUS, 0))
                retVal |= curBit;
            partyIndex++;
            curBit <<= 1;
            selection >>= 1;
        }
        while (selection);
    }
    else if (GetMonData(&party[0], MON_DATA_POKERUS, 0))
    {
        retVal = 1;
    }

    return retVal;
}

void UpdatePartyPokerusTime(u16 days)
{
    int i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, 0))
        {
            u8 pokerus = GetMonData(&gPlayerParty[i], MON_DATA_POKERUS, 0);
            if (pokerus & 0xF)
            {
                if ((pokerus & 0xF) < days || days > 4)
                    pokerus &= 0xF0;
                else
                    pokerus -= days;

                if (pokerus == 0)
                    pokerus = 0x10;

                SetMonData(&gPlayerParty[i], MON_DATA_POKERUS, &pokerus);
            }
        }
    }
}

void PartySpreadPokerus(struct Pokemon *party)
{
    if ((Random() % 3) == 0)
    {
        int i;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES, 0))
            {
                u8 pokerus = GetMonData(&party[i], MON_DATA_POKERUS, 0);
                u8 curPokerus = pokerus;
                if (pokerus)
                {
                    if (pokerus & 0xF)
                    {
                        // Spread to adjacent party members.
                        if (i != 0 && !(GetMonData(&party[i - 1], MON_DATA_POKERUS, 0) & 0xF0))
                            SetMonData(&party[i - 1], MON_DATA_POKERUS, &curPokerus);
                        if (i != (PARTY_SIZE - 1) && !(GetMonData(&party[i + 1], MON_DATA_POKERUS, 0) & 0xF0))
                        {
                            SetMonData(&party[i + 1], MON_DATA_POKERUS, &curPokerus);
                            i++;
                        }
                    }
                }
            }
        }
    }
}

bool8 TryIncrementMonLevel(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u8 nextLevel = GetMonData(mon, MON_DATA_LEVEL, 0) + 1;
    u32 expPoints = GetMonData(mon, MON_DATA_EXP, 0);
    if (expPoints > gExperienceTables[gBaseStats[species].growthRate][MAX_MON_LEVEL])
    {
        expPoints = gExperienceTables[gBaseStats[species].growthRate][MAX_MON_LEVEL];
        SetMonData(mon, MON_DATA_EXP, &expPoints);
    }
    if (nextLevel > MAX_MON_LEVEL || expPoints < gExperienceTables[gBaseStats[species].growthRate][nextLevel])
    {
        return FALSE;
    }
    else
    {
        SetMonData(mon, MON_DATA_LEVEL, &nextLevel);
        return TRUE;
    }
}

u32 CanMonLearnTMHM(struct Pokemon *mon, u8 tm)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES2, 0);
    if (species == SPECIES_EGG)
    {
        return 0;
    }
    else if (tm < 32)
    {
        u32 mask = 1 << tm;
        return gTMHMLearnsets[species][0] & mask;
    }
    else
    {
        u32 mask = 1 << (tm - 32);
        return gTMHMLearnsets[species][1] & mask;
    }
}

u32 CanSpeciesLearnTMHM(u16 species, u8 tm)
{
    if (species == SPECIES_EGG)
    {
        return 0;
    }
    else if (tm < 32)
    {
        u32 mask = 1 << tm;
        return gTMHMLearnsets[species][0] & mask;
    }
    else
    {
        u32 mask = 1 << (tm - 32);
        return gTMHMLearnsets[species][1] & mask;
    }
}

u8 GetMoveRelearnerMoves(struct Pokemon *mon, u16 *moves)
{
    u16 learnedMoves[4];
    u8 numMoves = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, 0);
    int i, j, k;

    for (i = 0; i < 4; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, 0);

    for (i = 0; i < 20; i++)
    {
        u16 moveLevel;

        if (gLevelUpLearnsets[species][i] == 0xFFFF)
            break;

        moveLevel = gLevelUpLearnsets[species][i] & 0xFE00;

        if (moveLevel <= (level << 9))
        {
            for (j = 0; j < 4 && learnedMoves[j] != (gLevelUpLearnsets[species][i] & 0x1FF); j++)
                ;

            if (j == 4)
            {
                for (k = 0; k < numMoves && moves[k] != (gLevelUpLearnsets[species][i] & 0x1FF); k++)
                    ;

                if (k == numMoves)
                    moves[numMoves++] = gLevelUpLearnsets[species][i] & 0x1FF;
            }
        }
    }

    return numMoves;
}

u8 GetLevelUpMovesBySpecies(u16 species, u16 *moves)
{
    u8 numMoves = 0;
    int i;

    for (i = 0; i < 20 && gLevelUpLearnsets[species][i] != 0xFFFF; i++)
         moves[numMoves++] = gLevelUpLearnsets[species][i] & 0x1FF;

     return numMoves;
}

u8 GetNumberOfRelearnableMoves(struct Pokemon *mon)
{
    u16 learnedMoves[4];
    u16 moves[20];
    u8 numMoves = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES2, 0);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, 0);
    int i, j, k;

    if (species == SPECIES_EGG)
        return 0;

    for (i = 0; i < 4; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, 0);

    for (i = 0; i < 20; i++)
    {
        u16 moveLevel;

        if (gLevelUpLearnsets[species][i] == 0xFFFF)
            break;

        moveLevel = gLevelUpLearnsets[species][i] & 0xFE00;

        if (moveLevel <= (level << 9))
        {
            for (j = 0; j < 4 && learnedMoves[j] != (gLevelUpLearnsets[species][i] & 0x1FF); j++)
                ;

            if (j == 4)
            {
                for (k = 0; k < numMoves && moves[k] != (gLevelUpLearnsets[species][i] & 0x1FF); k++)
                    ;

                if (k == numMoves)
                    moves[numMoves++] = gLevelUpLearnsets[species][i] & 0x1FF;
            }
        }
    }

    return numMoves;
}

u16 SpeciesToPokedexNum(u16 species)
{
    if (IsNationalPokedexEnabled())
    {
        return SpeciesToNationalPokedexNum(species);
    }
    else
    {
        species = SpeciesToHoennPokedexNum(species);
        if (species <= 202)
            return species;
        return 0xFFFF;
    }
}

bool32 sub_806E3F8(u16 species)
{
    if (SpeciesToHoennPokedexNum(species) > 202)
        return FALSE;
    else
        return TRUE;
}

void ClearBattleMonForms(void)
{
    int i;
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        gBattleMonForms[i] = 0;
}

u16 GetBattleBGM(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON)
        return MUS_BATTLE34;
    else if (gBattleTypeFlags & BATTLE_TYPE_REGI)
        return MUS_BATTLE36;
    else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000))
        return MUS_BATTLE20;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        u8 trainerClass;

        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
            trainerClass = GetFrontierOpponentClass(gTrainerBattleOpponent_A);
        else if (gBattleTypeFlags & BATTLE_TYPE_x4000000)
            trainerClass = TRAINER_CLASS_EXPERT;
        else
            trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;

        switch (trainerClass)
        {
        case TRAINER_CLASS_AQUA_LEADER:
        case TRAINER_CLASS_MAGMA_LEADER:
            return MUS_BATTLE30;
        case TRAINER_CLASS_TEAM_AQUA:
        case TRAINER_CLASS_TEAM_MAGMA:
        case TRAINER_CLASS_AQUA_ADMIN:
        case TRAINER_CLASS_MAGMA_ADMIN:
            return MUS_BATTLE31;
        case TRAINER_CLASS_LEADER:
            return MUS_BATTLE32;
        case TRAINER_CLASS_CHAMPION:
            return MUS_BATTLE33;
        case TRAINER_CLASS_PKMN_TRAINER_3:
            if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                return MUS_BATTLE35;
            if (!StringCompare(gTrainers[gTrainerBattleOpponent_A].trainerName, gText_BattleWallyName))
                return MUS_BATTLE20;
            return MUS_BATTLE35;
        case TRAINER_CLASS_ELITE_FOUR:
            return MUS_BATTLE38;
        case TRAINER_CLASS_SALON_MAIDEN:
        case TRAINER_CLASS_DOME_ACE:
        case TRAINER_CLASS_PALACE_MAVEN:
        case TRAINER_CLASS_ARENA_TYCOON:
        case TRAINER_CLASS_FACTORY_HEAD:
        case TRAINER_CLASS_PIKE_QUEEN:
        case TRAINER_CLASS_PYRAMID_KING:
            return MUS_VS_FRONT;
        default:
            return MUS_BATTLE20;
        }
    }
    else
        return MUS_BATTLE27;
}

void PlayBattleBGM(void)
{
    ResetMapMusic();
    m4aMPlayAllStop();
    PlayBGM(GetBattleBGM());
}

void PlayMapChosenOrBattleBGM(u16 songId)
{
    ResetMapMusic();
    m4aMPlayAllStop();
    if (songId)
        PlayNewMapMusic(songId);
    else
        PlayNewMapMusic(GetBattleBGM());
}

void sub_806E694(u16 songId)
{
    u8 taskId;

    ResetMapMusic();
    m4aMPlayAllStop();

    taskId = CreateTask(sub_806E6CC, 0);
    gTasks[taskId].data[0] = songId;
}

static void sub_806E6CC(u8 taskId)
{
    if (gTasks[taskId].data[0])
        PlayNewMapMusic(gTasks[taskId].data[0]);
    else
        PlayNewMapMusic(GetBattleBGM());
    DestroyTask(taskId);
}

const u8 *GetMonFrontSpritePal(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES2, 0);
    u32 otId = GetMonData(mon, MON_DATA_OT_ID, 0);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, 0);
    return GetFrontSpritePalFromSpeciesAndPersonality(species, otId, personality);
}

// Extracts the upper 16 bits of a 32-bit number
#define HIHALF(n) (((n) & 0xFFFF0000) >> 16)

// Extracts the lower 16 bits of a 32-bit number
#define LOHALF(n) ((n) & 0xFFFF)

const u8 *GetFrontSpritePalFromSpeciesAndPersonality(u16 species, u32 otId, u32 personality)
{
    u32 shinyValue;

    if (species > SPECIES_EGG)
        return gMonPaletteTable[0].data;

    shinyValue = HIHALF(otId) ^ LOHALF(otId) ^ HIHALF(personality) ^ LOHALF(personality);
    if (shinyValue < 8)
        return gMonShinyPaletteTable[species].data;
    else
        return gMonPaletteTable[species].data;
}

const struct CompressedSpritePalette *GetMonSpritePalStruct(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES2, 0);
    u32 otId = GetMonData(mon, MON_DATA_OT_ID, 0);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, 0);
    return GetMonSpritePalStructFromOtIdPersonality(species, otId, personality);
}

const struct CompressedSpritePalette *GetMonSpritePalStructFromOtIdPersonality(u16 species, u32 otId , u32 personality)
{
    u32 shinyValue;

    shinyValue = HIHALF(otId) ^ LOHALF(otId) ^ HIHALF(personality) ^ LOHALF(personality);
    if (shinyValue < 8)
        return &gMonShinyPaletteTable[species];
    else
        return &gMonPaletteTable[species];
}

bool32 IsHMMove2(u16 move)
{
    int i = 0;
    while (sHMMoves[i] != 0xFFFF)
    {
        if (sHMMoves[i++] == move)
            return TRUE;
    }
    return FALSE;
}

bool8 IsMonSpriteNotFlipped(u16 species)
{
    return gBaseStats[species].noFlip;
}

s8 GetMonFlavorRelation(struct Pokemon *mon, u8 flavor)
{
    u8 nature = GetNature(mon);
    return gPokeblockFlavorCompatibilityTable[nature * 5 + flavor];
}

s8 GetFlavorRelationByPersonality(u32 personality, u8 flavor)
{
    u8 nature = GetNatureFromPersonality(personality);
    return gPokeblockFlavorCompatibilityTable[nature * 5 + flavor];
}

bool8 IsTradedMon(struct Pokemon *mon)
{
    u8 otName[OT_NAME_LENGTH + 1];
    u32 otId;
    GetMonData(mon, MON_DATA_OT_NAME, otName);
    otId = GetMonData(mon, MON_DATA_OT_ID, 0);
    return IsOtherTrainer(otId, otName);
}

bool8 IsOtherTrainer(u32 otId, u8 *otName)
{
    if (otId ==
        (gSaveBlock2Ptr->playerTrainerId[0]
         | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
         | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
         | (gSaveBlock2Ptr->playerTrainerId[3] << 24)))
    {
        int i;

        for (i = 0; otName[i] != EOS; i++)
            if (otName[i] != gSaveBlock2Ptr->playerName[i])
                return TRUE;
        return FALSE;
    }

    return TRUE;
}

void MonRestorePP(struct Pokemon *mon)
{
    BoxMonRestorePP(&mon->box);
}

void BoxMonRestorePP(struct BoxPokemon *boxMon)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, 0))
        {
            u16 move = GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, 0);
            u16 bonus = GetBoxMonData(boxMon, MON_DATA_PP_BONUSES, 0);
            u8 pp = CalculatePPWithBonus(move, bonus, i);
            SetBoxMonData(boxMon, MON_DATA_PP1 + i, &pp);
        }
    }
}

void sub_806E994(void)
{
    gLastUsedAbility = gBattleStruct->field_B0;

    gBattleTextBuff1[0] = B_BUFF_PLACEHOLDER_BEGIN;
    gBattleTextBuff1[1] = B_BUFF_MON_NICK_WITH_PREFIX;
    gBattleTextBuff1[2] = gBattleStruct->field_49;
    gBattleTextBuff1[4] = B_BUFF_EOS;

    if (!GetBattlerSide(gBattleStruct->field_49))
        gBattleTextBuff1[3] = pokemon_order_func(gBattlerPartyIndexes[gBattleStruct->field_49]);
    else
        gBattleTextBuff1[3] = gBattlerPartyIndexes[gBattleStruct->field_49];

    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff2, gBattlerInMenuId, pokemon_order_func(gBattlerPartyIndexes[gBattlerInMenuId]))

    BattleStringExpandPlaceholders(gText_PkmnsXPreventsSwitching, gStringVar4);
}

static s32 GetWildMonTableIdInAlteringCave(u16 species)
{
    s32 i;
    for (i = 0; i < (s32) ARRAY_COUNT(sAlteringCaveWildMonHeldItems); i++)
        if (sAlteringCaveWildMonHeldItems[i].species == species)
            return i;
    return 0;
}

void SetWildMonHeldItem(void)
{
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_TRAINER | BATTLE_TYPE_PYRAMID | BATTLE_TYPE_PIKE)))
    {
        u16 rnd = Random() % 100;
        u16 species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, 0);
        u16 var1 = 45;
        u16 var2 = 95;
        if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_BIT3, 0)
            && GetMonAbility(&gPlayerParty[0]) == ABILITY_COMPOUND_EYES)
        {
            var1 = 20;
            var2 = 80;
        }
        if (gMapHeader.mapLayoutId == 0x1A4)
        {
            s32 alteringCaveId = GetWildMonTableIdInAlteringCave(species);
            if (alteringCaveId != 0)
            {
                if (rnd < var2)
                    return;
                SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &sAlteringCaveWildMonHeldItems[alteringCaveId].item);
            }
            else
            {
                if (rnd < var1)
                    return;
                if (rnd < var2)
                    SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &gBaseStats[species].item1);
                else
                    SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &gBaseStats[species].item2);
            }
        }
        else
        {
            if (gBaseStats[species].item1 == gBaseStats[species].item2 && gBaseStats[species].item1 != 0)
            {
                SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &gBaseStats[species].item1);
            }
            else
            {
                if (rnd < var1)
                    return;
                if (rnd < var2)
                    SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &gBaseStats[species].item1);
                else
                    SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &gBaseStats[species].item2);
            }
        }
    }
}

bool8 IsMonShiny(struct Pokemon *mon)
{
    u32 otId = GetMonData(mon, MON_DATA_OT_ID, 0);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, 0);
    return IsShinyOtIdPersonality(otId, personality);
}

bool8 IsShinyOtIdPersonality(u32 otId, u32 personality)
{
    bool8 retVal = FALSE;
    u32 shinyValue = HIHALF(otId) ^ LOHALF(otId) ^ HIHALF(personality) ^ LOHALF(personality);
    if (shinyValue < 8)
        retVal = TRUE;
    return retVal;
}

const u8 *GetTrainerPartnerName(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        if (gPartnerTrainerId == TRAINER_STEVEN_PARTNER)
        {
            return gTrainers[TRAINER_STEVEN].trainerName;
        }
        else
        {
            GetFrontierTrainerName(gStringVar1, gPartnerTrainerId);
            return gStringVar1;
        }
    }
    else
    {
        u8 id = GetMultiplayerId();
        return gLinkPlayers[GetBattlerMultiplayerId(gLinkPlayers[id].lp_field_18 ^ 2)].name;
    }
}

#define READ_PTR_FROM_TASK(taskId, dataId)                      \
    (void*)(                                                    \
    ((u16)(gTasks[taskId].data[dataId]) |                       \
    ((u16)(gTasks[taskId].data[dataId + 1]) << 0x10)))

#define STORE_PTR_IN_TASK(ptr, taskId, dataId)                 \
{                                                              \
    gTasks[taskId].data[dataId] = (u32)(ptr);                  \
    gTasks[taskId].data[dataId + 1] = (u32)(ptr) >> 0x10;      \
}

static void Task_AnimateAfterDelay(u8 taskId)
{
    if (--gTasks[taskId].data[3] == 0)
    {
        LaunchAnimationTaskForFrontSprite(READ_PTR_FROM_TASK(taskId, 0), gTasks[taskId].data[2]);
        DestroyTask(taskId);
    }
}

static void Task_PokemonSummaryAnimateAfterDelay(u8 taskId)
{
    if (--gTasks[taskId].data[3] == 0)
    {
        StartMonSummaryAnimation(READ_PTR_FROM_TASK(taskId, 0), gTasks[taskId].data[2]);
        sub_81C488C(0xFF);
        DestroyTask(taskId);
    }
}

void BattleAnimateFrontSprite(struct Sprite* sprite, u16 species, bool8 noCry, u8 arg3)
{
    if (gHitMarker & HITMARKER_NO_ANIMATIONS && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000)))
        DoMonFrontSpriteAnimation(sprite, species, noCry, arg3 | 0x80);
    else
        DoMonFrontSpriteAnimation(sprite, species, noCry, arg3);
}

void DoMonFrontSpriteAnimation(struct Sprite* sprite, u16 species, bool8 noCry, u8 arg3)
{
    s8 pan;
    switch (arg3 & 0x7F)
    {
    case 0:
        pan = -25;
        break;
    case 1:
        pan = 25;
        break;
    default:
        pan = 0;
        break;
    }
    if (arg3 & 0x80)
    {
        if (!noCry)
            PlayCry1(species, pan);
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (!noCry)
        {
            PlayCry1(species, pan);
            if (HasTwoFramesAnimation(species))
                StartSpriteAnim(sprite, 1);
        }
        if (sMonAnimationDelayTable[species - 1] != 0)
        {
            u8 taskId = CreateTask(Task_AnimateAfterDelay, 0);
            STORE_PTR_IN_TASK(sprite, taskId, 0);
            gTasks[taskId].data[2] = sMonFrontAnimIdsTable[species - 1];
            gTasks[taskId].data[3] = sMonAnimationDelayTable[species - 1];
        }
        else
        {
            LaunchAnimationTaskForFrontSprite(sprite, sMonFrontAnimIdsTable[species - 1]);
        }
        sprite->callback = SpriteCallbackDummy_2;
    }
}

void PokemonSummaryDoMonAnimation(struct Sprite* sprite, u16 species, bool8 oneFrame)
{
    if (!oneFrame && HasTwoFramesAnimation(species))
        StartSpriteAnim(sprite, 1);
    if (sMonAnimationDelayTable[species - 1] != 0)
    {
        u8 taskId = CreateTask(Task_PokemonSummaryAnimateAfterDelay, 0);
        STORE_PTR_IN_TASK(sprite, taskId, 0);
        gTasks[taskId].data[2] = sMonFrontAnimIdsTable[species - 1];
        gTasks[taskId].data[3] = sMonAnimationDelayTable[species - 1];
        sub_81C488C(taskId);
        SetSpriteCB_MonAnimDummy(sprite);
    }
    else
    {
        StartMonSummaryAnimation(sprite, sMonFrontAnimIdsTable[species - 1]);
    }
}

void sub_806EE98(void)
{
    u8 delayTaskId = FindTaskIdByFunc(Task_PokemonSummaryAnimateAfterDelay);
    if (delayTaskId != 0xFF)
        DestroyTask(delayTaskId);
}

void BattleAnimateBackSprite(struct Sprite* sprite, u16 species)
{
    if (gHitMarker & HITMARKER_NO_ANIMATIONS && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000)))
    {
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        LaunchAnimationTaskForBackSprite(sprite, GetSpeciesBackAnimSet(species));
        sprite->callback = SpriteCallbackDummy_2;
    }
}

u8 sub_806EF08(u8 arg0)
{
    s32 i;
    s32 var = 0;
    u8 multiplayerId = GetMultiplayerId();
    switch (gLinkPlayers[multiplayerId].lp_field_18)
    {
    case 0:
    case 2:
        var = (arg0 != 0) ? 1 : 3;
        break;
    case 1:
    case 3:
        var = (arg0 != 0) ? 2 : 0;
        break;
    }
    for (i = 0; i < 4; i++)
    {
        if (gLinkPlayers[i].lp_field_18 == (s16)(var))
            break;
    }
    return i;
}

u8 sub_806EF84(u8 arg0, u8 arg1)
{
    s32 i;
    s32 var = 0;
    switch (gLinkPlayers[arg1].lp_field_18)
    {
    case 0:
    case 2:
        var = (arg0 != 0) ? 1 : 3;
        break;
    case 1:
    case 3:
        var = (arg0 != 0) ? 2 : 0;
        break;
    }
    for (i = 0; i < 4; i++)
    {
        if (gLinkPlayers[i].lp_field_18 == (s16)(var))
            break;
    }
    return i;
}

u16 FacilityClassToPicIndex(u16 facilityClass)
{
    return gFacilityClassToPicIndex[facilityClass];
}

u16 PlayerGenderToFrontTrainerPicId(u8 playerGender)
{
    if (playerGender != MALE)
        return FacilityClassToPicIndex(FACILITY_CLASS_PKMN_TRAINER_BRENDAN);
    else
        return FacilityClassToPicIndex(FACILITY_CLASS_PKMN_TRAINER_MAY);
}

void HandleSetPokedexFlag(u16 nationalNum, u8 caseId, u32 personality)
{
    u8 getFlagCaseId = (caseId == FLAG_SET_SEEN) ? FLAG_GET_SEEN : FLAG_GET_CAUGHT;
    if (!GetSetPokedexFlag(nationalNum, getFlagCaseId)) // don't set if it's already set
    {
        GetSetPokedexFlag(nationalNum, caseId);
        if (NationalPokedexNumToSpecies(nationalNum) == SPECIES_UNOWN)
            gSaveBlock2Ptr->pokedex.unownPersonality = personality;
        if (NationalPokedexNumToSpecies(nationalNum) == SPECIES_SPINDA)
            gSaveBlock2Ptr->pokedex.spindaPersonality = personality;
    }
}

const u8 *GetTrainerClassNameFromId(u16 trainerId)
{
    if (trainerId >= TRAINERS_COUNT)
        trainerId = TRAINER_NONE;
    return gTrainerClassNames[gTrainers[trainerId].trainerClass];
}

const u8 *GetTrainerNameFromId(u16 trainerId)
{
    if (trainerId >= TRAINERS_COUNT)
        trainerId = TRAINER_NONE;
    return gTrainers[trainerId].trainerName;
}

bool8 HasTwoFramesAnimation(u16 species)
{
    return (species != SPECIES_CASTFORM
            && species != SPECIES_DEOXYS
            && species != SPECIES_SPINDA
            && species != SPECIES_UNOWN);
}

bool8 sub_806F104(void)
{
    if (gMain.inBattle && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER))
        return TRUE;
    if (!gMain.inBattle && (InBattlePike() || InBattlePyramid()))
        return TRUE;
    return FALSE;
}

#define FORCE_SIGNED(x)(-(x * (-1)))

static void sub_806F160(struct Unknown_806F160_Struct* structPtr)
{
    u16 i, j;
    for (i = 0; i < FORCE_SIGNED(structPtr->field_0_0); i++)
    {
        structPtr->templates[i] = gUnknown_08329D98[i];
        for (j = 0; j < structPtr->field_1; j++)
        {
            asm("");
            structPtr->frameImages[i * structPtr->field_1 + j].data = &structPtr->byteArrays[i][j * 0x800];
        }
        structPtr->templates[i].images = &structPtr->frameImages[i * structPtr->field_1];
    }
}

static void sub_806F1FC(struct Unknown_806F160_Struct* structPtr)
{
    u16 i, j;
    for (i = 0; i < FORCE_SIGNED(structPtr->field_0_0); i++)
    {
        structPtr->templates[i] = gUnknown_08329F28;
        for (j = 0; j < structPtr->field_1; j++)
        {
            structPtr->frameImages[i * structPtr->field_0_0 + j].data = &structPtr->byteArrays[i][j * 0x800];
        }
        structPtr->templates[i].images = &structPtr->frameImages[i * structPtr->field_0_0];
        structPtr->templates[i].anims = gPlayerMonSpriteAnimsTable;
        structPtr->templates[i].paletteTag = i;
    }
}

struct Unknown_806F160_Struct *sub_806F2AC(u8 id, u8 arg1)
{
    u8 i;
    u8 flags;
    struct Unknown_806F160_Struct *structPtr;

    flags = 0;
    id %= 2;
    structPtr = AllocZeroed(sizeof(*structPtr));
    if (structPtr == NULL)
        return NULL;

    switch (arg1)
    {
    case 2:
        structPtr->field_0_0 = 7;
        structPtr->field_0_1 = 7;
        structPtr->field_1 = 4;
        structPtr->field_3_0 = 1;
        structPtr->field_3_1 = 2;
        break;
    case 0:
    default:
        structPtr->field_0_0 = 4;
        structPtr->field_0_1 = 4;
        structPtr->field_1 = 4;
        structPtr->field_3_0 = 1;
        structPtr->field_3_1 = 0;
        break;
    }

    structPtr->bytes = AllocZeroed(structPtr->field_3_0 * 0x800 * 4 * structPtr->field_0_0);
    structPtr->byteArrays = AllocZeroed(structPtr->field_0_0 * 32);
    if (structPtr->bytes == NULL || structPtr->byteArrays == NULL)
    {
        flags |= 1;
    }
    else
    {
        for (i = 0; i < FORCE_SIGNED(structPtr->field_0_0); i++)
            structPtr->byteArrays[i] = structPtr->bytes + (structPtr->field_3_0 * (i << 0xD));
    }

    structPtr->templates = AllocZeroed(sizeof(struct SpriteTemplate) * structPtr->field_0_0);
    structPtr->frameImages = AllocZeroed(sizeof(struct SpriteFrameImage) * structPtr->field_0_0 * structPtr->field_1);
    if (structPtr->templates == NULL || structPtr->frameImages == NULL)
    {
        flags |= 2;
    }
    else
    {
        for (i = 0; i < structPtr->field_1 * structPtr->field_0_0; i++)
            structPtr->frameImages[i].size = 0x800;

        switch (structPtr->field_3_1)
        {
        case 2:
            sub_806F1FC(structPtr);
            break;
        case 0:
        case 1:
        default:
            sub_806F160(structPtr);
            break;
        }
    }

    if (flags & 2)
    {
        if (structPtr->frameImages != NULL)
            FREE_AND_SET_NULL(structPtr->frameImages);
        if (structPtr->templates != NULL)
            FREE_AND_SET_NULL(structPtr->templates);
    }
    if (flags & 1)
    {
        if (structPtr->byteArrays != NULL)
            FREE_AND_SET_NULL(structPtr->byteArrays);
        if (structPtr->bytes != NULL)
            FREE_AND_SET_NULL(structPtr->bytes);
    }

    if (flags)
    {
        memset(structPtr, 0, sizeof(*structPtr));
        Free(structPtr);
    }
    else
    {
        structPtr->magic = 0xA3;
        gUnknown_020249B4[id] = structPtr;
    }

    return gUnknown_020249B4[id];
}

void sub_806F47C(u8 id)
{
    struct Unknown_806F160_Struct *structPtr;

    id %= 2;
    structPtr = gUnknown_020249B4[id];
    if (structPtr == NULL)
        return;

    if (structPtr->magic != 0xA3)
    {
        memset(structPtr, 0, sizeof(struct Unknown_806F160_Struct));
    }
    else
    {

        if (structPtr->frameImages != NULL)
            FREE_AND_SET_NULL(structPtr->frameImages);
        if (structPtr->templates != NULL)
            FREE_AND_SET_NULL(structPtr->templates);
        if (structPtr->byteArrays != NULL)
            FREE_AND_SET_NULL(structPtr->byteArrays);
        if (structPtr->bytes != NULL)
            FREE_AND_SET_NULL(structPtr->bytes);

        memset(structPtr, 0, sizeof(struct Unknown_806F160_Struct));
        Free(structPtr);
    }
}

u8 *sub_806F4F8(u8 id, u8 arg1)
{
    struct Unknown_806F160_Struct *structPtr = gUnknown_020249B4[id % 2];
    if (structPtr->magic != 0xA3)
    {
        return NULL;
    }
    else
    {
        if (arg1 >= FORCE_SIGNED(structPtr->field_0_0))
            arg1 = 0;

        return structPtr->byteArrays[arg1];
    }
}
