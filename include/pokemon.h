#ifndef GUARD_POKEMON_H
#define GUARD_POKEMON_H

#include "contest_effect.h"
#include "sprite.h"
#include "wild_encounter_ow.h"
#include "constants/battle.h"
#include "constants/cries.h"
#include "constants/egg_ids.h"
#include "constants/form_change_types.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/map_groups.h"
#include "constants/regions.h"
#include "constants/region_map_sections.h"
#include "constants/map_groups.h"
#include "constants/battle.h"
#include "constants/abilities.h"
#include "contest_effect.h"
#include "constants/trainers.h"

#define GET_BASE_SPECIES_ID(speciesId) (GetFormSpeciesId(speciesId, 0))
#define FORM_SPECIES_END (0xffff)

// Property labels for Get(Box)MonData / Set(Box)MonData
enum MonData {
    MON_DATA_PERSONALITY,
    MON_DATA_STATUS,
    MON_DATA_OT_ID,
    MON_DATA_LANGUAGE,
    MON_DATA_SANITY_IS_BAD_EGG,
    MON_DATA_SANITY_HAS_SPECIES,
    MON_DATA_SANITY_IS_EGG,
    MON_DATA_OT_NAME,
    MON_DATA_MARKINGS,
    MON_DATA_CHECKSUM,
    MON_DATA_HP,
    MON_DATA_IS_SHINY,
    MON_DATA_HIDDEN_NATURE,
    MON_DATA_HP_LOST,
    MON_DATA_DAYS_SINCE_FORM_CHANGE,
    MON_DATA_ENCRYPT_SEPARATOR,
    MON_DATA_NICKNAME,
    MON_DATA_NICKNAME10,
    MON_DATA_SPECIES,
    MON_DATA_HELD_ITEM,
    MON_DATA_MOVE1,
    MON_DATA_MOVE2,
    MON_DATA_MOVE3,
    MON_DATA_MOVE4,
    MON_DATA_PP1,
    MON_DATA_PP2,
    MON_DATA_PP3,
    MON_DATA_PP4,
    MON_DATA_PP_BONUSES,
    MON_DATA_COOL,
    MON_DATA_BEAUTY,
    MON_DATA_CUTE,
    MON_DATA_EXP,
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPEED_EV,
    MON_DATA_SPATK_EV,
    MON_DATA_SPDEF_EV,
    MON_DATA_FRIENDSHIP,
    MON_DATA_SMART,
    MON_DATA_POKERUS,
    MON_DATA_POKERUS_STRAIN,
    MON_DATA_POKERUS_DAYS_LEFT,
    MON_DATA_MET_LOCATION,
    MON_DATA_MET_LEVEL,
    MON_DATA_MET_GAME,
    MON_DATA_POKEBALL,
    MON_DATA_HP_IV,
    MON_DATA_ATK_IV,
    MON_DATA_DEF_IV,
    MON_DATA_SPEED_IV,
    MON_DATA_SPATK_IV,
    MON_DATA_SPDEF_IV,
    MON_DATA_IS_EGG,
    MON_DATA_ABILITY_NUM,
    MON_DATA_TOUGH,
    MON_DATA_SHEEN,
    MON_DATA_OT_GENDER,
    MON_DATA_COOL_RIBBON,
    MON_DATA_BEAUTY_RIBBON,
    MON_DATA_CUTE_RIBBON,
    MON_DATA_SMART_RIBBON,
    MON_DATA_TOUGH_RIBBON,
    MON_DATA_LEVEL,
    MON_DATA_MAX_HP,
    MON_DATA_ATK,
    MON_DATA_DEF,
    MON_DATA_SPEED,
    MON_DATA_SPATK,
    MON_DATA_SPDEF,
    MON_DATA_MAIL,
    MON_DATA_SPECIES_OR_EGG,
    MON_DATA_IVS,
    MON_DATA_CHAMPION_RIBBON,
    MON_DATA_WINNING_RIBBON,
    MON_DATA_VICTORY_RIBBON,
    MON_DATA_ARTIST_RIBBON,
    MON_DATA_EFFORT_RIBBON,
    MON_DATA_MARINE_RIBBON,
    MON_DATA_LAND_RIBBON,
    MON_DATA_SKY_RIBBON,
    MON_DATA_COUNTRY_RIBBON,
    MON_DATA_NATIONAL_RIBBON,
    MON_DATA_EARTH_RIBBON,
    MON_DATA_WORLD_RIBBON,
    MON_DATA_MODERN_FATEFUL_ENCOUNTER,
    MON_DATA_KNOWN_MOVES,
    MON_DATA_RIBBON_COUNT,
    MON_DATA_RIBBONS,
    MON_DATA_HYPER_TRAINED_HP,
    MON_DATA_HYPER_TRAINED_ATK,
    MON_DATA_HYPER_TRAINED_DEF,
    MON_DATA_HYPER_TRAINED_SPEED,
    MON_DATA_HYPER_TRAINED_SPATK,
    MON_DATA_HYPER_TRAINED_SPDEF,
    MON_DATA_IS_SHADOW,
    MON_DATA_DYNAMAX_LEVEL,
    MON_DATA_GIGANTAMAX_FACTOR,
    MON_DATA_TERA_TYPE,
    MON_DATA_EVOLUTION_TRACKER,
};

#define BLOCK_AI_DYNAMAX 15 // Used as dynamax level value by the AI to indicate this mon shouldn't dynamax

struct PokemonSubstruct0
{
    enum Species species:11; // 2047 species.
    enum Type teraType:5; // 30 types.
    enum Item heldItem:10; // 1023 items.
    u16 unused_02:6;
    u32 experience:21;
    u32 nickname11:8; // 11th character of nickname.
    u32 unused_04:3;
    u8 ppBonuses;
    u8 friendship;
    u16 pokeball:6; // 63 balls.
    u16 nickname12:8; // 12th character of nickname.
    u16 unused_0A:2;
};

struct PokemonSubstruct1
{
    enum Move move1:11; // 2047 moves.
    u16 evolutionTracker1:5;
    enum Move move2:11; // 2047 moves.
    u16 evolutionTracker2:5;
    enum Move move3:11; // 2047 moves.
    u16 unused_04:5;
    enum Move move4:11; // 2047 moves.
    u16 unused_06:3;
    u16 hyperTrainedHP:1;
    u16 hyperTrainedAttack:1;
    u8 pp1:7; // 127 PP.
    u8 hyperTrainedDefense:1;
    u8 pp2:7; // 127 PP.
    u8 hyperTrainedSpeed:1;
    u8 pp3:7; // 127 PP.
    u8 hyperTrainedSpAttack:1;
    u8 pp4:7; // 127 PP.
    u8 hyperTrainedSpDefense:1;
};

struct PokemonSubstruct2
{
    u8 hpEV;
    u8 attackEV;
    u8 defenseEV;
    u8 speedEV;
    u8 spAttackEV;
    u8 spDefenseEV;
    u8 cool;
    u8 beauty;
    u8 cute;
    u8 smart;
    u8 tough;
    u8 sheen;
};

struct PokemonSubstruct3
{
    u8 pokerus;
    u8 metLocation;
    u16 metLevel:7;
    u16 metGame:4;
    u16 dynamaxLevel:4;
    u16 otGender:1;
    u32 hpIV:5;
    u32 attackIV:5;
    u32 defenseIV:5;
    u32 speedIV:5;
    u32 spAttackIV:5;
    u32 spDefenseIV:5;
    u32 isEgg:1;
    u32 gigantamaxFactor:1;
    u32 coolRibbon:3;     // Stores the highest contest rank achieved in the Cool category.
    u32 beautyRibbon:3;   // Stores the highest contest rank achieved in the Beauty category.
    u32 cuteRibbon:3;     // Stores the highest contest rank achieved in the Cute category.
    u32 smartRibbon:3;    // Stores the highest contest rank achieved in the Smart category.
    u32 toughRibbon:3;    // Stores the highest contest rank achieved in the Tough category.
    u32 championRibbon:1; // Given when defeating the Champion. Because both RSE and FRLG use it, later generations don't specify from which region it comes from.
    u32 winningRibbon:1;  // Given at the Battle Tower's Level 50 challenge by winning a set of seven battles that extends the current streak to 56 or more.
    u32 victoryRibbon:1;  // Given at the Battle Tower's Level 100 challenge by winning a set of seven battles that extends the current streak to 56 or more.
    u32 artistRibbon:1;   // Given at the Contest Hall by winning a Master Rank contest with at least 800 points, and agreeing to have the Pokémon's portrait placed in the museum after being offered.
    u32 effortRibbon:1;   // Given at Slateport's market to Pokémon with maximum EVs.
    u32 marineRibbon:1;   // Never distributed.
    u32 landRibbon:1;     // Never distributed.
    u32 skyRibbon:1;      // Never distributed.
    u32 countryRibbon:1;  // Distributed during Pokémon Festa '04 and '05 to tournament winners.
    u32 nationalRibbon:1; // Given to purified Shadow Pokémon in Colosseum/XD.
    u32 earthRibbon:1;    // Given to teams that have beaten Mt. Battle's 100-battle challenge in Colosseum/XD.
    u32 worldRibbon:1;    // Distributed during Pokémon Festa '04 and '05 to tournament winners.
    u32 isShadow:1;
    u32 unused_0B:1;
    u32 abilityNum:2;

    // The functionality of this bit changed in FRLG:
    // In RS, this bit does nothing, is never set, & is accidentally unset when hatching Eggs.
    // In FRLG & Emerald, this controls Mew & Deoxys obedience and whether they can be traded.
    // If set, a Pokémon is a fateful encounter in FRLG's summary screen if hatched & for all Pokémon in Gen 4+ summary screens.
    // Set for in-game event island legendaries, events distributed after a certain date, & Pokémon from XD: Gale of Darkness.
    // Not to be confused with METLOC_FATEFUL_ENCOUNTER.
    u32 modernFatefulEncounter:1;
};

// Number of bytes in the largest Pokémon substruct.
// They are assumed to be the same size, and will be padded to
// the largest size by the union.
// By default they are all 12 bytes.
#define NUM_SUBSTRUCT_BYTES (max(sizeof(struct PokemonSubstruct0),     \
                             max(sizeof(struct PokemonSubstruct1),     \
                             max(sizeof(struct PokemonSubstruct2),     \
                                 sizeof(struct PokemonSubstruct3)))))

enum SubstructType
{
    SUBSTRUCT_TYPE_0,
    SUBSTRUCT_TYPE_1,
    SUBSTRUCT_TYPE_2,
    SUBSTRUCT_TYPE_3,
};

union PokemonSubstruct
{
    struct PokemonSubstruct0 type0;
    struct PokemonSubstruct1 type1;
    struct PokemonSubstruct2 type2;
    struct PokemonSubstruct3 type3;
    u16 raw[NUM_SUBSTRUCT_BYTES / 2]; // /2 because it's u16, not u8
};

struct BoxPokemon
{
    u32 personality;
    u32 otId;
    u8 nickname[min(10, POKEMON_NAME_LENGTH)];
    u8 language:3;
    u8 hiddenNatureModifier:5; // 31 natures.
    u8 isBadEgg:1;
    u8 hasSpecies:1;
    u8 isEgg:1;
    u8 blockBoxRS:1; // Unused, but Pokémon Box Ruby & Sapphire will refuse to deposit a Pokémon with this flag set.
    u8 daysSinceFormChange:3; // 7 days.
    u8 unused_13:1;
    u8 otName[PLAYER_NAME_LENGTH];
    u8 markings:4;
    u8 compressedStatus:4;
    u16 checksum;
    u16 hpLost:14; // 16383 HP.
    u16 shinyModifier:1;
    u16 unused_1E:1;

    union
    {
        u32 raw[(NUM_SUBSTRUCT_BYTES * 4) / 4]; // *4 because there are 4 substructs, /4 because it's u32, not u8
        union PokemonSubstruct substructs[4];
    } secure;
};

struct Pokemon
{
    struct BoxPokemon box;
    u32 status;
    u8 level;
    u8 mail;
    u16 hp;
    u16 maxHP;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 spAttack;
    u16 spDefense;
};

struct MonSpritesGfxManager
{
    u32 numSprites:4;
    u32 numSprites2:4; // Never read
    u32 numFrames:8;
    u32 active:8;
    u32 dataSize:4;
    u32 mode:4; // MON_SPR_GFX_MODE_*
    void *spriteBuffer;
    u8 **spritePointers;
    struct SpriteTemplate *templates;
    struct SpriteFrameImage *frameImages;
};

enum {
    MON_SPR_GFX_MODE_NORMAL,
    MON_SPR_GFX_MODE_BATTLE,
    MON_SPR_GFX_MODE_FULL_PARTY,
};

enum {
    MON_SPR_GFX_MANAGER_A,
    MON_SPR_GFX_MANAGER_B, // Nothing ever sets up this manager.
    MON_SPR_GFX_MANAGERS_COUNT
};

#define UNPACK_VOLATILE_STRUCT(_enum, _fieldName, _typeMaxValue, ...) INVOKE_WITH_(UNPACK_VOLATILE_STRUCT_, _fieldName, UNPACK_B(_typeMaxValue));
#define UNPACK_VOLATILE_STRUCT_(_fieldName, _type, ...) _type FIRST(__VA_OPT__(_fieldName:BIT_SIZE(FIRST(__VA_ARGS__)),) _fieldName)

struct Volatiles
{
    VOLATILE_DEFINITIONS(UNPACK_VOLATILE_STRUCT)
    // Expands to:
    // u32 confusionTimer:3;
    // u32 flinched:1;
    // u32 uproarTurns:3;
    // etc.
};

struct BattlePokemon
{
    enum Species species;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 spAttack;
    u16 spDefense;
    enum Move moves[MAX_MON_MOVES];
    u32 hpIV:5;
    u32 attackIV:5;
    u32 defenseIV:5;
    u32 speedIV:5;
    u32 spAttackIV:5;
    u32 spDefenseIV:5;
    u32 abilityNum:2;
    s8 statStages[NUM_BATTLE_STATS];
    enum Ability ability;
    enum Type types[3];
    u8 pp[MAX_MON_MOVES];
    u16 hp;
    u8 level;
    u8 friendship;
    u16 maxHP;
    enum Item item;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u8 ppBonuses;
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u32 experience;
    u32 personality;
    u32 status1;
    struct Volatiles volatiles;
    u32 otId;
    u8 metLevel:7;
    u8 isShiny:1;
    u8 affectionHearts;
};

struct EvolutionParam
{
    u16 condition;
    u16 arg1;
    u16 arg2;
    u16 arg3;
};

struct Evolution
{
    u16 method;
    u16 param;
    enum Species targetSpecies;
    const struct EvolutionParam *params;
};

struct SpeciesInfo /*0xC4*/
{
    u8 baseHP;
    u8 baseAttack;
    u8 baseDefense;
    u8 baseSpeed;
    u8 baseSpAttack;
    u8 baseSpDefense;
    enum Type types[2];
    u8 catchRate;
    u8 forceTeraType;
    u16 expYield; // expYield was changed from u8 to u16 for the new Exp System.
    u16 evYield_HP:2;
    u16 evYield_Attack:2;
    u16 evYield_Defense:2;
    u16 evYield_Speed:2;
    u16 evYield_SpAttack:2;
    u16 evYield_SpDefense:2;
    u16 padding2:4;
    enum Item itemCommon;
    enum Item itemRare;
    u8 genderRatio;
    u8 eggCycles;
    u8 friendship;
    u8 growthRate;
    enum EggGroup eggGroups[EGG_GROUPS_PER_MON];
    enum Ability abilities[NUM_ABILITY_SLOTS]; // 3 abilities, no longer u8 because we have over 255 abilities now.
    u8 safariZoneFleeRate;

    // Pokédex data
    u8 categoryName[13];
    u8 speciesName[POKEMON_NAME_LENGTH + 1];
    enum PokemonCry cryId:16;
    enum NationalDexOrder natDexNum:16;
    u16 height; //in decimeters
    u16 weight; //in hectograms
    u16 pokemonScale;
    u16 pokemonOffset;
    u16 trainerScale;
    u16 trainerOffset;
    const u8 *description;
    enum BodyColor bodyColor:7;
    // Graphical Data
    u8 noFlip:1;
    u8 frontAnimDelay;
    u8 frontAnimId;
    u8 backAnimId;
    const union AnimCmd *const *frontAnimFrames;
    const u32 *frontPic;
    const u32 *backPic;
    const u16 *palette;
    const u16 *shinyPalette;
    const u8 *iconSprite;
#if P_GENDER_DIFFERENCES
    const u32 *frontPicFemale;
    const u32 *backPicFemale;
    const u16 *paletteFemale;
    const u16 *shinyPaletteFemale;
    const u8 *iconSpriteFemale;
#endif //P_GENDER_DIFFERENCES
#if P_FOOTPRINTS
    const u8 *footprint;
#endif
    // All Pokémon pics are 64x64, but this data table defines where in this 64x64 frame the sprite's non-transparent pixels actually are.
    u8 frontPicSize; // The dimensions of this drawn pixel area.
    u8 frontPicYOffset; // The number of pixels between the drawn pixel area and the bottom edge.
    u8 backPicSize; // The dimensions of this drawn pixel area.
    u8 backPicYOffset; // The number of pixels between the drawn pixel area and the bottom edge.
#if P_GENDER_DIFFERENCES
    u8 frontPicSizeFemale; // The dimensions of this drawn pixel area.
    u8 backPicSizeFemale; // The dimensions of this drawn pixel area.
#endif //P_GENDER_DIFFERENCES
    u8 iconPalIndex:3;
#if P_GENDER_DIFFERENCES
    u8 iconPalIndexFemale:3;
#else
    u8 paddingF:3;
#endif //P_GENDER_DIFFERENCES
    u8 pokemonJumpType:2; // According to the clerk, the Pokémon allowed in Pokémon Jump are all <= 28 inches/71 cm, and do not only swim, burrow, or fly.
    u8 enemyMonElevation; // This determines how much higher above the usual position the enemy Pokémon is during battle. Species that float or fly have nonzero values.
    // Flags
    u32 isRestrictedLegendary:1;
    u32 isSubLegendary:1;
    u32 isMythical:1;
    u32 isUltraBeast:1;
    u32 isParadox:1;
    u32 isTotem:1;
    u32 isMegaEvolution:1;
    u32 isPrimalReversion:1;
    u32 isUltraBurst:1;
    u32 isGigantamax:1;
    u32 isTeraForm:1;
    u32 isAlolanForm:1;
    u32 isGalarianForm:1;
    u32 isHisuianForm:1;
    u32 isPaldeanForm:1;
    u32 cannotBeTraded:1;
    u32 perfectIVCount:3;   // This species will always generate with the specified amount of perfect IVs.
    u32 dexForceRequired:1; // This species will be taken into account for Pokédex ratings even if they have the "isMythical" flag set.
    u32 teachingType:1; // Not used in the ROM but used in compilation (check constants/teaching_types.h for explanations)
    u32 isFrontierBanned:1; // This species is not allowed to participate in Battle Frontier facilities.
    u32 isSkyBattleBanned:1;
    u32 isTelekinesisBanned:1;
    u32 padding4:8;
    // Shadow settings
    s8 enemyShadowXOffset; // This determines the X-offset for an enemy Pokémon's shadow during battle; negative values point left, positive values point right.
    s8 enemyShadowYOffset; // This determines the Y-offset for an enemy Pokémon's shadow during battle; negative values point up, positive values point down.
    u16 enemyShadowSize:3; // This determines the size of the shadow sprite used for an enemy Pokémon's front sprite during battle.
    u16 suppressEnemyShadow:1; // If set to true, then a shadow will not be drawn beneath an enemy Pokémon's front sprite during battle.
    enum EggIds eggId:12;
    // Move Data
    const struct LevelUpMove *levelUpLearnset;
    const u16 *teachableLearnset;
    const u16 *eggMoveLearnset;
    const struct Evolution *evolutions;
    const u16 *formSpeciesIdTable;
    const struct FormChange *formChangeTable;
#if OW_POKEMON_OBJECT_EVENTS
    struct ObjectEventGraphicsInfo overworldData;
#if P_GENDER_DIFFERENCES
    struct ObjectEventGraphicsInfo overworldDataFemale;
#endif //P_GENDER_DIFFERENCES
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const void *overworldPalette;
    const void *overworldShinyPalette;
#if P_GENDER_DIFFERENCES
    const void *overworldPaletteFemale;
    const void *overworldShinyPaletteFemale;
#endif //P_GENDER_DIFFERENCES
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
    enum OverworldWildEncounterBehaviors overworldEncounterBehavior;
};

// This struct represent values from user input (createmon/givemon) that have not been sanitized
// The absence of enum and the use of large data types is there to reflect the full range of user input
struct PokemonTemplate
{
    u16 species;
    u16 heldItem;
    u16 level;
    u16 ball;
    u16 gender;
    u16 nature;
    bool16 isShiny;
    u16 abilityNum;
    u16 evs[NUM_STATS];
    u16 ivs[NUM_STATS];
    u16 moves[MAX_MON_MOVES];
    bool16 gmaxFactor;
    u16 teraType;
    u16 dmaxLevel;
    bool16 isEgg;
    enum GeneratedMonOrigin origin;
    u8 ignoreTotalEvCheck:1;
    u8 doNotUseDefaultShinyness:1;
    u8 doNotUseDefaultBall:1;
    u8 doNotUseDefaultAbility:1;
    u8 doNotUseDefaultTeraType:1;
    u8 padding:3;
};

struct EggData
{
    const u8 *eggIcon;
    const u32 *eggSprite;
    const u16 *eggPalette;
    const u32 *eggHatchGfx;
    const u16 *eggHatchPal;
    const u32 *eggShardsGfx;
    const u8 eggIconPalIndex;
};

struct AbilityInfo
{
    u8 name[ABILITY_NAME_LENGTH + 1];
    const u8 *description;
    s8 aiRating;
    u8 cantBeCopied:1; // cannot be copied by Role Play or Doodle
    u8 cantBeSwapped:1; // cannot be swapped with Skill Swap or Wandering Spirit
    u8 cantBeTraced:1; // cannot be copied by Trace - same as cantBeCopied except for Wonder Guard
    u8 cantBeSuppressed:1; // cannot be negated by Gastro Acid or Neutralizing Gas
    u8 cantBeOverwritten:1; // cannot be overwritten by Entrainment, Worry Seed or Simple Beam (but can be by Mummy) - same as cantBeSuppressed except for Truant
    u8 breakable:1; // can be bypassed by Mold Breaker and clones
    u8 failsOnImposter:1; // doesn't work on an Imposter mon; when can we actually use this?
};

enum {
    AFFINE_NONE,
    AFFINE_TURN_UP,
    AFFINE_TURN_UP_AND_DOWN,
    AFFINE_TURN_DOWN,
    AFFINE_TURN_DOWN_SLOW,
    AFFINE_TURN_DOWN_SLIGHT,
    AFFINE_TURN_UP_HIGH,
    AFFINE_UNUSED_1,
    AFFINE_UNUSED_2,
    AFFINE_UNUSED_3,
    NUM_MON_AFFINES,
};

// The animation the Pokémon does during the feeding scene depends on their nature.
// The below values are offsets into sMonPokeblockAnims of the animation data for that nature.
#define ANIM_HARDY   0
#define ANIM_LONELY  (ANIM_HARDY + 3)
#define ANIM_BRAVE   (ANIM_LONELY + 1)
#define ANIM_ADAMANT (ANIM_BRAVE + 1)
#define ANIM_NAUGHTY (ANIM_ADAMANT + 5)
#define ANIM_BOLD    (ANIM_NAUGHTY + 3)
#define ANIM_DOCILE  (ANIM_BOLD + 2)
#define ANIM_RELAXED (ANIM_DOCILE + 1)
#define ANIM_IMPISH  (ANIM_RELAXED + 2)
#define ANIM_LAX     (ANIM_IMPISH + 1)
#define ANIM_TIMID   (ANIM_LAX + 1)
#define ANIM_HASTY   (ANIM_TIMID + 5)
#define ANIM_SERIOUS (ANIM_HASTY + 2)
#define ANIM_JOLLY   (ANIM_SERIOUS + 1)
#define ANIM_NAIVE   (ANIM_JOLLY + 1)
#define ANIM_MODEST  (ANIM_NAIVE + 4)
#define ANIM_MILD    (ANIM_MODEST + 3)
#define ANIM_QUIET   (ANIM_MILD + 1)
#define ANIM_BASHFUL (ANIM_QUIET + 2)
#define ANIM_RASH    (ANIM_BASHFUL + 3)
#define ANIM_CALM    (ANIM_RASH + 3)
#define ANIM_GENTLE  (ANIM_CALM + 1)
#define ANIM_SASSY   (ANIM_GENTLE + 1)
#define ANIM_CAREFUL (ANIM_SASSY + 1)
#define ANIM_QUIRKY  (ANIM_CAREFUL + 5)

// In palace double battles, Pokémon have a target preference depending on nature
#define PALACE_TARGET_STRONGER 0
#define PALACE_TARGET_WEAKER   1
#define PALACE_TARGET_RANDOM   2

struct NatureInfo
{
    const u8 *name;
    enum Stat statUp;
    enum Stat statDown;
    u8 backAnim;
    u8 pokeBlockAnim[2];
    u8 battlePalacePercents[4];
    u8 battlePalaceFlavorText;
    u8 battlePalaceSmokescreen;
    const u8 *natureGirlMessage;
};

struct LevelUpMove
{
    enum Move move;
    u16 level;
};

struct FormChange
{
    enum FormChanges method:16;
    enum Species targetSpecies;
    u16 param1;
    u16 param2;
    u16 param3;
    u16 param4;
};

struct FormChangeContext
{
    enum FormChanges method:16;
    enum Species currentSpecies;
    enum Item partyItemUsed;
    u16 multichoiceSelection;
    enum Item heldItem;
    enum Ability ability;
    u16 learnedMove;
    u32 status;
    enum Move moves[MAX_MON_MOVES];
    u16 hp;
    u16 maxHP;
    u32 gmaxFactor:1;
    enum Type teraType;
    u32 level:7;
    u32 padding:8;
};

enum FusionExtraMoveHandling
{
    FORGET_EXTRA_MOVES,
    SWAP_EXTRA_MOVES_KYUREM_WHITE,
    SWAP_EXTRA_MOVES_KYUREM_BLACK
};

struct Fusion
{
    u16 fusionStorageIndex;
    enum Item itemId;
    enum Species targetSpecies1;
    enum Species targetSpecies2;
    enum Species fusingIntoMon;
    enum Move fusionMove;
    enum FusionExtraMoveHandling extraMoveHandling;
};

extern const struct Fusion *const gFusionTablePointers[NUM_SPECIES];

#if P_FUSION_FORMS
#if P_FAMILY_KYUREM
#if P_FAMILY_RESHIRAM
extern const u16 gKyuremWhiteSwapMoveTable[][2];
#endif //P_FAMILY_RESHIRAM
#if P_FAMILY_ZEKROM
extern const u16 gKyuremBlackSwapMoveTable[][2];
#endif //P_FAMILY_ZEKROM
#endif //P_FAMILY_KYUREM
#endif //P_FUSION_FORMS

#define NUM_UNOWN_FORMS 28
#define RANDOM_UNOWN_LETTER 0

#define GET_UNOWN_LETTER(personality) ((   \
      (((personality) & 0x03000000) >> 18) \
    | (((personality) & 0x00030000) >> 12) \
    | (((personality) & 0x00000300) >> 6)  \
    | (((personality) & 0x00000003) >> 0)  \
) % NUM_UNOWN_FORMS)

#define GET_SHINY_VALUE(otId, personality) (HIHALF(otId) ^ LOHALF(otId) ^ HIHALF(personality) ^ LOHALF(personality))

struct OriginalTrainerId
{
    enum OtIdMethod method;
    u32 value;
};

#define OTID_STRUCT_PLAYER_ID       ((struct OriginalTrainerId) {OT_ID_PLAYER_ID, 0})
#define OTID_STRUCT_PRESET(value)   ((struct OriginalTrainerId) {OT_ID_PRESET, value})
#define OTID_STRUCT_RANDOM_NO_SHINY ((struct OriginalTrainerId) {OT_ID_RANDOM_NO_SHINY, 0})

extern u8 gPartiesCount[MAX_BATTLE_TRAINERS];
extern struct Pokemon gParties[MAX_BATTLE_TRAINERS][PARTY_SIZE];

DEPRECATED("Use gParties[B_TRAINER_PLAYER] for player and gParties[B_TRAINER_PARTNER] for partner instead")
extern struct Pokemon (*const gPlayerPartyPtr)[6];
#define gPlayerParty (*gPlayerPartyPtr)
DEPRECATED("gPlayerPartyCount is deprecated. Use gPartiesCount[B_TRAINER_PLAYER] for player and gPartiesCount[B_TRAINER_PARTNER] for partner instead")
extern u8 (*const gPlayerPartyCountPtr);
#define gPlayerPartyCount (*gPlayerPartyCountPtr)

DEPRECATED("Will be removed in 1.17.0: use gParties[B_TRAINER_OPPONENT_A] for opponentA and gParties[B_TRAINER_OPPONENT_B] for opponentB instead")
extern struct Pokemon (*const gEnemyPartyPtr)[6];
#define gEnemyParty (*gEnemyPartyPtr)
DEPRECATED("gEnemyPartyCount is deprecated and will be removed in 1.17.0. Use gPartiesCount[B_TRAINER_OPPONENT_A] for opponentA and gPartiesCount[B_TRAINER_OPPONENT_B] for opponentB instead")
extern u8 (*const gEnemyPartyCountPtr);
#define gEnemyPartyCount (*gEnemyPartyCountPtr)

extern struct SpriteTemplate gMultiuseSpriteTemplate;
extern u16 gFollowerSteps;
extern bool32 consumeItem;
extern u32 removeBagItem;
extern u32 removeBagItemCount;
extern u8 gTriedEvolving;

extern const u16 gFacilityClassToPicIndex[];
extern const enum TrainerClassID gFacilityClassToTrainerClass[];
extern const struct SpeciesInfo gSpeciesInfo[];
extern const u32 gExperienceTables[][MAX_LEVEL + 1];
extern const u8 gPPUpGetMask[];
extern const u8 gPPUpClearMask[];
extern const u8 gPPUpAddValues[];
extern const u8 gStatStageRatios[MAX_STAT_STAGE + 1][2];
extern const u16 gUnionRoomFacilityClasses[];
extern const struct SpriteTemplate gBattlerSpriteTemplates[];
extern const u32 sExpCandyExperienceTable[];
extern const struct AbilityInfo gAbilitiesInfo[];
extern const struct NatureInfo gNaturesInfo[];
extern const struct BehaviorOWE gOWESpeciesBehavior[OWE_SPECIES_BEHAVIOR_COUNT];

void ZeroBoxMonData(struct BoxPokemon *boxMon);
void ZeroMonData(struct Pokemon *mon);
void ZeroPartyMons(struct Pokemon *party);
void ZeroPlayerPartyMons(void);
void ZeroEnemyPartyMons(void);
u32 GetMonPersonality(enum Species species, u8 gender, u8 nature, u8 unownLetter);
bool32 ComputePlayerShinyOdds(u32 personality, u32 value);
void CreateMon(struct Pokemon *mon, enum Species species, u8 level, u32 personality, struct OriginalTrainerId);
void CreateRandomMon(struct Pokemon *mon, enum Species species, u8 level);
void CreateRandomMonWithIVs(struct Pokemon *mon, enum Species species, u8 level, u8 fixedIv);
void CreateBoxMon(struct BoxPokemon *boxMon, enum Species species, u8 level, u32 personality, struct OriginalTrainerId);
void CreateMonWithIVs(struct Pokemon *mon, enum Species species, u8 level, u32 personality, struct OriginalTrainerId trainerId, u8 fixedIV);
void SetBoxMonIVs(struct BoxPokemon *mon, u8 fixedIV);
void SetBoxMonPerfectIVs(struct BoxPokemon *mon, u32 numPerfect);
void CreateMaleMon(struct Pokemon *mon, enum Species species, u8 level);
void CreateMonWithIVsPersonality(struct Pokemon *mon, enum Species species, u8 level, u32 ivs, u32 personality);
void CreateBattleTowerMon(struct Pokemon *mon, struct BattleTowerPokemon *src);
void CreateBattleTowerMon_HandleLevel(struct Pokemon *mon, struct BattleTowerPokemon *src, bool8 lvl50);
void CreateApprenticeMon(struct Pokemon *mon, const struct Apprentice *src, u8 monId);
void ConvertPokemonToBattleTowerPokemon(struct Pokemon *mon, struct BattleTowerPokemon *dest);
enum TrainerPicID GetUnionRoomTrainerPic(void);
enum TrainerClassID GetUnionRoomTrainerClass(void);
void CreateEnemyEventMon(void);
void CalculateMonStats(struct Pokemon *mon);
void CalculateMonStatsCont(struct Pokemon *mon, bool32 updateSpeedStat);
void BoxMonToMon(const struct BoxPokemon *src, struct Pokemon *dest);
u8 GetLevelFromMonExp(struct Pokemon *mon);
u8 GetLevelFromBoxMonExp(struct BoxPokemon *boxMon);
u16 GiveMoveToMon(struct Pokemon *mon, enum Move move);
u16 GiveMoveToBoxMon(struct BoxPokemon *boxMon, enum Move move);
u16 GiveMoveToBattleMon(struct BattlePokemon *mon, enum Move move);
void SetMonMoveSlot(struct Pokemon *mon, enum Move move, u8 slot);
void SetBoxMonMoveSlot(struct BoxPokemon *mon, enum Move move, u8 slot);
void SetBattleMonMoveSlot(struct BattlePokemon *mon, enum Move move, u8 slot);
void GiveMonInitialMoveset(struct Pokemon *mon);
void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon);
void GiveMonDefaultMove(struct Pokemon *mon, u32 slot);
void GiveBoxMonDefaultMove(struct BoxPokemon *boxMon, u32 slot);
enum Move MonTryLearningNewMoveAtLevel(struct Pokemon *mon, bool32 firstMove, u32 level);
enum Move MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove);
void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, enum Move move);
void DeleteFirstMoveAndGiveMoveToBoxMon(struct BoxPokemon *boxMon, enum Move move);
u32 CountAliveMonsInBattle(u8 caseId, enum BattlerId battler);
u8 GetMonGender(struct Pokemon *mon);
u8 GetBoxMonGender(struct BoxPokemon *boxMon);
u8 GetGenderFromSpeciesAndPersonality(enum Species species, u32 personality);
bool32 IsPersonalityFemale(enum Species species, u32 personality);
enum Species GetUnownSpeciesId(u32 personality);
void SetMultiuseSpriteTemplateToPokemon(enum Species speciesTag, enum BattlerPosition battlerPosition);
void SetMultiuseSpriteTemplateToTrainerBack(enum TrainerPicID trainerPicId, enum BattlerPosition battlerPosition);
void SetMultiuseSpriteTemplateToTrainerFront(enum TrainerPicID trainerPicId, enum BattlerPosition battlerPosition);

/* GameFreak called Get(Box)MonData with either 2 or 3 arguments, for
 * type safety we have a Get(Box)MonData macro which dispatches to
 * either Get(Box)MonData2 or Get(Box)MonData3 based on the number of
 * arguments. The two functions are aliases of each other, but they
 * differ for matching purposes in the caller's codegen. */
#define GetMonData(...) CAT(GetMonData, NARG_8(__VA_ARGS__))(__VA_ARGS__)
#define GetBoxMonData(...) CAT(GetBoxMonData, NARG_8(__VA_ARGS__))(__VA_ARGS__)
u32 GetMonData3(struct Pokemon *mon, s32 field, u8 *data);
u32 GetMonData2(struct Pokemon *mon, s32 field);
u32 GetBoxMonData3(struct BoxPokemon *boxMon, s32 field, u8 *data);
u32 GetBoxMonData2(struct BoxPokemon *boxMon, s32 field);

void SetMonData(struct Pokemon *mon, s32 field, const void *dataArg);
void SetBoxMonData(struct BoxPokemon *boxMon, s32 field, const void *dataArg);
void CopyMon(void *dest, void *src, size_t size);
u8 GiveCapturedMonToPlayer(struct Pokemon *mon);
u8 CopyMonToPC(struct Pokemon *mon);
u8 CalculatePlayerPartyCount(void);
u8 CalculatePartnerPartyCount(void);
u8 CalculateEnemyPartyCount(void);
u8 GetMonsStateToDoubles(void);
u8 GetMonsStateToDoubles_2(void);
enum Ability GetAbilityBySpecies(enum Species species, u8 abilityNum);
enum Ability GetMonAbility(struct Pokemon *mon);
void CreateSecretBaseEnemyParty(struct SecretBase *secretBaseRecord);
enum TrainerPicID GetSecretBaseTrainerPicIndex(void);
enum TrainerClassID GetSecretBaseTrainerClass(void);
bool8 IsPlayerPartyAndPokemonStorageFull(void);
bool8 IsPokemonStorageFull(void);
const u8 *GetSpeciesName(enum Species species);
const u8 *GetSpeciesCategory(enum Species species);
const u8 *GetSpeciesPokedexDescription(enum Species species);
u32 GetSpeciesHeight(enum Species species);
u32 GetSpeciesWeight(enum Species species);
enum Type GetSpeciesType(enum Species species, u8 slot);
enum Ability GetSpeciesAbility(enum Species species, u8 slot);
u32 GetSpeciesBaseHP(enum Species species);
u32 GetSpeciesBaseAttack(enum Species species);
u32 GetSpeciesBaseDefense(enum Species species);
u32 GetSpeciesBaseSpAttack(enum Species species);
u32 GetSpeciesBaseSpDefense(enum Species species);
u32 GetSpeciesBaseSpeed(enum Species species);
u32 GetSpeciesBaseStat(enum Species species, u32 statIndex);
u32 GetSpeciesBaseStatTotal(enum Species species);
const struct LevelUpMove *GetSpeciesLevelUpLearnset(enum Species species);
const u16 *GetSpeciesTeachableLearnset(enum Species species);
const u16 *GetSpeciesEggMoves(enum Species species);
bool32 SpeciesHasEggMove(enum Species species, enum Move move);
const struct Evolution *GetSpeciesEvolutions(enum Species species);
const u16 *GetSpeciesFormTable(enum Species species);
const struct FormChange *GetSpeciesFormChanges(enum Species species);
u8 CalculatePPWithBonus(enum Move move, u8 ppBonuses, u8 moveIndex);
void RemoveMonPPBonus(struct Pokemon *mon, u8 moveIndex);
void RemoveBoxMonPPBonus(struct BoxPokemon *mon, u8 moveIndex);
void RemoveBattleMonPPBonus(struct BattlePokemon *mon, u8 moveIndex);
void PokemonToBattleMon(struct Pokemon *src, struct BattlePokemon *dst);
bool8 ExecuteTableBasedItemEffect(struct Pokemon *mon, enum Item item, u8 partyIndex, u8 moveIndex);
bool8 PokemonUseItemEffects(struct Pokemon *mon, enum Item item, u8 partyIndex, u8 moveIndex, u8 usedByAI);
bool8 HealStatusConditions(struct Pokemon *mon, u32 healMask, enum BattlerId battler);
u8 GetItemEffectParamOffset(enum BattlerId battler, enum Item itemId, u8 effectByte, u8 effectBit);
u8 GetNature(struct Pokemon *mon);
u8 GetNatureFromPersonality(u32 personality);
enum Species GetGMaxTargetSpecies(enum Species species);
bool32 DoesMonMeetAdditionalConditions(struct Pokemon *mon, const struct EvolutionParam *params, struct Pokemon *tradePartner, u32 partyId, bool32 *canStopEvo, enum EvoState evoState);
enum Species GetEvolutionTargetSpecies(struct Pokemon *mon, enum EvolutionMode mode, enum Item evolutionItem, struct Pokemon *tradePartner, bool32 *canStopEvo, enum EvoState evoState);
bool8 IsMonPastEvolutionLevel(struct Pokemon *mon);
enum Species NationalPokedexNumToSpecies(enum NationalDexOrder nationalNum);
u32 NationalToRegionalOrder(enum NationalDexOrder nationalNum);
enum KantoDexOrder NationalToKantoOrder(enum NationalDexOrder nationalNum);
enum HoennDexOrder NationalToHoennOrder(enum NationalDexOrder nationalNum);
enum NationalDexOrder SpeciesToNationalPokedexNum(enum Species species);
u32 SpeciesToRegionalPokedexNum(enum Species species);
enum KantoDexOrder SpeciesToKantoPokedexNum(enum Species species);
enum HoennDexOrder SpeciesToHoennPokedexNum(enum Species species);
enum NationalDexOrder RegionalToNationalOrder(u32 regionNum);
enum NationalDexOrder KantoToNationalOrder(enum KantoDexOrder kantoNum);
enum NationalDexOrder HoennToNationalOrder(enum HoennDexOrder hoennNum);
void EvolutionRenameMon(struct Pokemon *mon, enum Species oldSpecies, enum Species newSpecies);
u8 GetPlayerFlankId(void);
u16 GetLinkTrainerFlankId(u8 linkPlayerId);
s32 GetBattlerMultiplayerId(u16 id);
u8 GetTrainerEncounterMusicId(u16 trainerOpponentId);
u16 ModifyStatByNature(u8 nature, u16 stat, enum Stat statIndex);
void AdjustFriendship(struct Pokemon *mon, u8 event);
s32 CalculateFriendshipBonuses(struct Pokemon *mon, s32 modifier, enum HoldEffect itemHoldEffect);
void MonGainEVs(struct Pokemon *mon, enum Species defeatedSpecies);
u16 GetMonEVCount(struct Pokemon *mon);
bool8 TryIncrementMonLevel(struct Pokemon *mon);
bool32 CanLearnTeachableMove(enum Species species, enum Move move);
u16 SpeciesToPokedexNum(enum Species species);
bool32 IsSpeciesInRegionalDex(enum Species species);
bool32 IsSpeciesInKantoDex(enum Species species);
bool32 IsSpeciesInHoennDex(enum Species species);
u16 GetBattleBGM(void);
void PlayBattleBGM(void);
void PlayMapChosenOrBattleBGM(u16 songId);
void CreateTask_PlayMapChosenOrBattleBGM(u16 songId);
const u16 *GetMonFrontSpritePal(struct Pokemon *mon);
const u16 *GetMonSpritePalFromSpeciesAndPersonality(enum Species species, bool32 isShiny, u32 personality);
const u16 *GetMonSpritePalFromSpeciesAndPersonalityIsEgg(enum Species species, bool32 isShiny, u32 personality, bool32 isEgg);
const u16 *GetMonSpritePalFromSpecies(enum Species species, bool32 isShiny, bool32 isFemale);
const u16 *GetMonSpritePalFromSpeciesIsEgg(enum Species species, bool32 isShiny, bool32 isFemale, bool32 isEgg);
bool32 IsMoveHM(enum Move move);
bool32 CannotForgetMove(enum Move move);
bool8 IsMonSpriteNotFlipped(enum Species species);
s8 GetMonFlavorRelation(struct Pokemon *mon, enum Flavor flavor);
s8 GetFlavorRelationByPersonality(u32 personality, enum Flavor flavor);
bool8 IsTradedMon(struct Pokemon *mon);
bool8 IsOtherTrainer(u32 otId, u8 *otName);
void MonRestorePP(struct Pokemon *mon);
void BoxMonRestorePP(struct BoxPokemon *boxMon);
void SetMonPreventsSwitchingString(void);
void SetWildMonHeldItem(void);
bool8 IsMonShiny(struct Pokemon *mon);
const u8 *GetTrainerPartnerName(void);
void BattleAnimateFrontSprite(struct Sprite *sprite, enum Species species, bool8 noCry, u8 panMode);
void DoMonFrontSpriteAnimation(struct Sprite *sprite, enum Species species, bool8 noCry, u8 panModeAnimFlag);
void PokemonSummaryDoMonAnimation(struct Sprite *sprite, enum Species species, bool8 oneFrame);
void StopPokemonAnimationDelayTask(void);
void BattleAnimateBackSprite(struct Sprite *sprite, enum Species species);
u8 GetOpposingLinkMultiBattlerId(bool8 rightSide, u8 multiplayerId);
enum TrainerPicID FacilityClassToPicIndex(u16 facilityClass);
enum TrainerPicID PlayerGenderToFrontTrainerPicId(enum Gender playerGender);
void HandleSetPokedexFlag(enum NationalDexOrder nationalNum, u8 caseId, u32 personality);
void HandleSetPokedexFlagFromMon(struct Pokemon *mon, u32 caseId);
bool8 HasTwoFramesAnimation(enum Species species);
struct MonSpritesGfxManager *CreateMonSpritesGfxManager(u8 managerId, u8 mode);
void DestroyMonSpritesGfxManager(u8 managerId);
u8 *MonSpritesGfxManager_GetSpritePtr(u8 managerId, u8 spriteNum);
enum Species GetFormSpeciesId(enum Species speciesId, u8 formId);
u8 GetFormIdFromFormSpeciesId(enum Species formSpeciesId);
enum Species GetFormChangeTargetSpecies_Internal(struct FormChangeContext ctx);
bool32 DoesSpeciesHaveFormChangeMethod(enum Species species, enum FormChanges method);
u16 MonTryLearningNewMoveEvolution(struct Pokemon *mon, bool8 firstMove);
void RemoveIVIndexFromList(u8 *ivs, u8 selectedIv);
void TrySpecialOverworldEvo(void);
bool32 SpeciesHasGenderDifferences(enum Species species);
bool32 TryFormChange(struct Pokemon *mon, enum FormChanges method, enum BattleTrainer trainer);
bool32 TryBoxMonFormChange(struct BoxPokemon *boxMon, enum FormChanges method);
void TryToSetBattleFormChangeMoves(struct Pokemon *mon, enum FormChanges method);
u32 GetMonFriendshipScore(struct Pokemon *pokemon);
u32 GetMonAffectionHearts(struct Pokemon *pokemon);
void UpdateMonPersonality(struct BoxPokemon *boxMon, u32 personality);
u8 CalculatePartyCount(enum BattleTrainer trainer);
u8 CalculatePartyCountOfSide(enum BattlerId battler);
enum Species SanitizeSpeciesId(enum Species species);
bool32 IsSpeciesEnabled(enum Species species);
enum PokemonCry GetCryIdBySpecies(enum Species species);
enum Species GetSpeciesPreEvolution(enum Species species);
void HealPokemon(struct Pokemon *mon);
void HealBoxPokemon(struct BoxPokemon *boxMon);
void UpdateDaysPassedSinceFormChange(u16 days);
void TrySetDayLimitToFormChange(struct Pokemon *mon);
enum Type CheckDynamicMoveType(struct Pokemon *mon, enum Move move, enum BattlerId battler, enum MonState state);
uq4_12_t GetDynamaxLevelHPMultiplier(u32 dynamaxLevel, bool32 inverseMultiplier);
enum Species GetRegionalFormByRegion(enum Species species, enum Region region);
bool32 IsSpeciesForeignRegionalForm(enum Species species, enum Region currentRegion);
enum Type GetTeraTypeFromPersonality(struct Pokemon *mon);
bool8 ShouldSkipFriendshipChange(void);
struct Pokemon *GetSavedPlayerPartyMon(u32 index);
u8 *GetSavedPlayerPartyCount(void);
void SavePlayerPartyMon(u32 index, struct Pokemon *mon);
bool32 IsSpeciesOfType(enum Species species, enum Type type);
struct BoxPokemon *GetSelectedBoxMonFromPcOrParty(void);
u32 GiveScriptedMonToPlayer(struct Pokemon *mon, u8 slot);
void ChangePokemonNicknameWithCallback(void (*callback)(void));
bool32 HasShedinjaHPHandling(enum Species species);
void ResolveEVs(const u16 *evsTemplate, u8 *evs, bool32 ignoreTotalEvCheck);
void CreateMonFromTemplate(struct Pokemon *mon, const struct PokemonTemplate *monTemplate);

static inline u32 OWE_GetMovementTypeFromSpecies(enum Species speciesId)
{
    speciesId = SanitizeSpeciesId(speciesId);
    enum OverworldWildEncounterBehaviors behavior = gSpeciesInfo[speciesId].overworldEncounterBehavior;
    return gOWESpeciesBehavior[behavior].movementType;
}

static inline u32 OWE_GetViewDistanceFromSpecies(enum Species speciesId)
{
    speciesId = SanitizeSpeciesId(speciesId);
    enum OverworldWildEncounterBehaviors behavior = gSpeciesInfo[speciesId].overworldEncounterBehavior;
    return gOWESpeciesBehavior[behavior].viewDistance;
}

static inline u32 OWE_GetViewWidthFromSpecies(enum Species speciesId)
{
    speciesId = SanitizeSpeciesId(speciesId);
    enum OverworldWildEncounterBehaviors behavior = gSpeciesInfo[speciesId].overworldEncounterBehavior;
    return gOWESpeciesBehavior[behavior].viewWidth;
}

static inline u32 OWE_GetViewActiveDistanceFromSpecies(enum Species speciesId)
{
    speciesId = SanitizeSpeciesId(speciesId);
    enum OverworldWildEncounterBehaviors behavior = gSpeciesInfo[speciesId].overworldEncounterBehavior;
    return gOWESpeciesBehavior[behavior].activeDistance;
}

static inline enum SpeedOWE OWE_GetIdleSpeedFromSpecies(enum Species speciesId)
{
    speciesId = SanitizeSpeciesId(speciesId);
    enum OverworldWildEncounterBehaviors behavior = gSpeciesInfo[speciesId].overworldEncounterBehavior;
    return gOWESpeciesBehavior[behavior].idleSpeed;
}

static inline enum SpeedOWE OWE_GetActiveSpeedFromSpecies(enum Species speciesId)
{
    speciesId = SanitizeSpeciesId(speciesId);
    enum OverworldWildEncounterBehaviors behavior = gSpeciesInfo[speciesId].overworldEncounterBehavior;
    return gOWESpeciesBehavior[behavior].activeSpeed;
}

static inline enum ReturnToIdleOWE OWE_GetReturnToIdleFromSpecies(enum Species speciesId)
{
    speciesId = SanitizeSpeciesId(speciesId);
    enum OverworldWildEncounterBehaviors behavior = gSpeciesInfo[speciesId].overworldEncounterBehavior;
    return gOWESpeciesBehavior[behavior].returnToIdle;
}

#endif // GUARD_POKEMON_H
