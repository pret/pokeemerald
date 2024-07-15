#ifndef GUARD_POKEMON_H
#define GUARD_POKEMON_H

#include "sprite.h"
#include "constants/items.h"
#include "constants/region_map_sections.h"
#include "constants/map_groups.h"
#include "contest_effect.h"

#define GET_BASE_SPECIES_ID(speciesId) (GetFormSpeciesId(speciesId, 0))
#define FORM_SPECIES_END (0xffff)

// Property labels for Get(Box)MonData / Set(Box)MonData
enum {
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
    MON_DATA_ENCRYPT_SEPARATOR,
    MON_DATA_NICKNAME,
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
    MON_DATA_ATK2,
    MON_DATA_DEF2,
    MON_DATA_SPEED2,
    MON_DATA_SPATK2,
    MON_DATA_SPDEF2,
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

struct PokemonSubstruct0
{
    u16 species:11; // 2047 species.
    u16 teraType:5; // 30 types.
    u16 heldItem:10; // 1023 items.
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
    u16 move1:11; // 2047 moves.
    u16 evolutionTracker1:5;
    u16 move2:11; // 2047 moves.
    u16 evolutionTracker2:4;
    u16 unused_02:1;
    u16 move3:11; // 2047 moves.
    u16 unused_04:5;
    u16 move4:11; // 2047 moves.
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
    u8 unused_13:4;
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

struct BattlePokemon
{
    /*0x00*/ u16 species;
    /*0x02*/ u16 attack;
    /*0x04*/ u16 defense;
    /*0x06*/ u16 speed;
    /*0x08*/ u16 spAttack;
    /*0x0A*/ u16 spDefense;
    /*0x0C*/ u16 moves[MAX_MON_MOVES];
    /*0x14*/ u32 hpIV:5;
    /*0x14*/ u32 attackIV:5;
    /*0x15*/ u32 defenseIV:5;
    /*0x15*/ u32 speedIV:5;
    /*0x16*/ u32 spAttackIV:5;
    /*0x17*/ u32 spDefenseIV:5;
    /*0x17*/ u32 abilityNum:2;
    /*0x18*/ s8 statStages[NUM_BATTLE_STATS];
    /*0x20*/ u16 ability;
    /*0x22*/ u8 type1;
    /*0x23*/ u8 type2;
    /*0x24*/ u8 type3;
    /*0x25*/ u8 pp[MAX_MON_MOVES];
    /*0x29*/ u16 hp;
    /*0x2B*/ u8 level;
    /*0x2C*/ u8 friendship;
    /*0x2D*/ u16 maxHP;
    /*0x2F*/ u16 item;
    /*0x31*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x3C*/ u8 ppBonuses;
    /*0x3D*/ u8 otName[PLAYER_NAME_LENGTH + 1];
    /*0x45*/ u32 experience;
    /*0x49*/ u32 personality;
    /*0x4D*/ u32 status1;
    /*0x51*/ u32 status2;
    /*0x55*/ u32 otId;
    /*0x59*/ u8 metLevel;
    /*0x5A*/ bool8 isShiny;
};

struct Evolution
{
    u16 method;
    u16 param;
    u16 targetSpecies;
};

struct SpeciesInfo /*0x8C*/
{
 /* 0x00 */ u8 baseHP;
 /* 0x01 */ u8 baseAttack;
 /* 0x02 */ u8 baseDefense;
 /* 0x03 */ u8 baseSpeed;
 /* 0x04 */ u8 baseSpAttack;
 /* 0x05 */ u8 baseSpDefense;
 /* 0x06 */ u8 types[2];
 /* 0x08 */ u8 catchRate;
 /* 0x09 */ u8 padding1;
 /* 0x0A */ u16 expYield; // expYield was changed from u8 to u16 for the new Exp System.
 /* 0x0C */ u16 evYield_HP:2;
            u16 evYield_Attack:2;
            u16 evYield_Defense:2;
            u16 evYield_Speed:2;
 /* 0x0D */ u16 evYield_SpAttack:2;
            u16 evYield_SpDefense:2;
            u16 padding2:4;
 /* 0x0E */ u16 itemCommon;
 /* 0x10 */ u16 itemRare;
 /* 0x12 */ u8 genderRatio;
 /* 0x13 */ u8 eggCycles;
 /* 0x14 */ u8 friendship;
 /* 0x15 */ u8 growthRate;
 /* 0x16 */ u8 eggGroups[2];
 /* 0x18 */ u16 abilities[NUM_ABILITY_SLOTS]; // 3 abilities, no longer u8 because we have over 255 abilities now.
 /* 0x1E */ u8 safariZoneFleeRate;
            // Pokédex data
 /* 0x1F */ u8 categoryName[13];
 /* 0x1F */ u8 speciesName[POKEMON_NAME_LENGTH + 1];
 /* 0x2C */ u16 cryId;
 /* 0x2E */ u16 natDexNum;
 /* 0x30 */ u16 height; //in decimeters
 /* 0x32 */ u16 weight; //in hectograms
 /* 0x34 */ u16 pokemonScale;
 /* 0x36 */ u16 pokemonOffset;
 /* 0x38 */ u16 trainerScale;
 /* 0x3A */ u16 trainerOffset;
 /* 0x3C */ const u8 *description;
 /* 0x40 */ u8 bodyColor:7;
            // Graphical Data
            u8 noFlip:1;
 /* 0x41 */ u8 frontAnimDelay;
 /* 0x42 */ u8 frontAnimId;
 /* 0x43 */ u8 backAnimId;
 /* 0x44 */ const union AnimCmd *const *frontAnimFrames;
 /* 0x48 */ const u32 *frontPic;
 /* 0x4C */ const u32 *frontPicFemale;
 /* 0x50 */ const u32 *backPic;
 /* 0x54 */ const u32 *backPicFemale;
 /* 0x58 */ const u32 *palette;
 /* 0x5C */ const u32 *paletteFemale;
 /* 0x60 */ const u32 *shinyPalette;
 /* 0x64 */ const u32 *shinyPaletteFemale;
 /* 0x68 */ const u8 *iconSprite;
 /* 0x6C */ const u8 *iconSpriteFemale;
#if P_FOOTPRINTS
 /* 0x70 */ const u8 *footprint;
#endif
            // All Pokémon pics are 64x64, but this data table defines where in this 64x64 frame the sprite's non-transparent pixels actually are.
 /* 0x74 */ u8 frontPicSize; // The dimensions of this drawn pixel area.
 /* 0x74 */ u8 frontPicSizeFemale; // The dimensions of this drawn pixel area.
 /* 0x75 */ u8 frontPicYOffset; // The number of pixels between the drawn pixel area and the bottom edge.
 /* 0x76 */ u8 backPicSize; // The dimensions of this drawn pixel area.
 /* 0x76 */ u8 backPicSizeFemale; // The dimensions of this drawn pixel area.
 /* 0x77 */ u8 backPicYOffset; // The number of pixels between the drawn pixel area and the bottom edge.
 /* 0x78 */ u8 iconPalIndex:3;
            u8 iconPalIndexFemale:3;
            u8 padding3:2;
 /* 0x79 */ u8 enemyMonElevation; // This determines how much higher above the usual position the enemy Pokémon is during battle. Species that float or fly have nonzero values.
            // Flags
 /* 0x7A */ u32 isLegendary:1;
            u32 isMythical:1;
            u32 isUltraBeast:1;
            u32 isTotem:1;
            u32 isParadoxForm:1;
            u32 isMegaEvolution:1;
            u32 isPrimalReversion:1;
            u32 isUltraBurst:1;
            u32 isGigantamax:1;
            u32 isAlolanForm:1;
            u32 isGalarianForm:1;
            u32 isHisuianForm:1;
            u32 isPaldeanForm:1;
            u32 cannotBeTraded:1;
            u32 allPerfectIVs:1;
            u32 dexForceRequired:1; // This species will be taken into account for Pokédex ratings even if they have the "isMythical" flag set.
            u32 tmIlliterate:1; // This species will be unable to learn the universal moves.
            u32 padding4:15;
            // Move Data
 /* 0x80 */ const struct LevelUpMove *levelUpLearnset;
 /* 0x84 */ const u16 *teachableLearnset;
 /* 0x88 */ const struct Evolution *evolutions;
 /* 0x84 */ const u16 *formSpeciesIdTable;
 /* 0x84 */ const struct FormChange *formChangeTable;
};

struct MoveInfo
{
    const u8 *name;
    const u8 *description;
    u16 effect;
    u16 type:5;
    u16 category:2;
    u16 power:9; // up to 511
    u16 accuracy:7;
    u16 target:9;
    u8 pp;
    union {
        u8 effect;
        u8 powerOverride;
    } zMove;

    s32 priority:4;
    u32 recoil:7;
    u32 strikeCount:4; // Max 15 hits. Defaults to 1 if not set. May apply its effect on each hit.
    u32 criticalHitStage:2;
    u32 alwaysCriticalHit:1;
    u32 numAdditionalEffects:2; // limited to 3 - don't want to get too crazy
    // 12 bits left to complete this word - continues into flags

    // Flags
    u32 makesContact:1;
    u32 ignoresProtect:1;
    u32 magicCoatAffected:1;
    u32 snatchAffected:1;
    u32 ignoresKingsRock:1;
    u32 punchingMove:1;
    u32 bitingMove:1;
    u32 pulseMove:1;
    u32 soundMove:1;
    u32 ballisticMove:1;
    u32 powderMove:1;
    u32 danceMove:1;
    u32 windMove:1;
    u32 slicingMove:1; // end of word
    u32 healingMove:1;
    u32 minimizeDoubleDamage:1;
    u32 ignoresTargetAbility:1;
    u32 ignoresTargetDefenseEvasionStages:1;
    u32 damagesUnderground:1;
    u32 damagesUnderwater:1;
    u32 damagesAirborne:1;
    u32 damagesAirborneDoubleDamage:1;
    u32 ignoreTypeIfFlyingAndUngrounded:1;
    u32 thawsUser:1;
    u32 ignoresSubstitute:1;
    u32 forcePressure:1;
    u32 cantUseTwice:1;

    // Ban flags
    u32 gravityBanned:1;
    u32 mirrorMoveBanned:1;
    u32 meFirstBanned:1;
    u32 mimicBanned:1;
    u32 metronomeBanned:1;
    u32 copycatBanned:1;
    u32 assistBanned:1; // Matches same moves as copycatBanned + semi-invulnerable moves and Mirror Coat.
    u32 sleepTalkBanned:1;
    u32 instructBanned:1;
    u32 encoreBanned:1;
    u32 parentalBondBanned:1;
    u32 skyBattleBanned:1;
    u32 sketchBanned:1;
    u32 padding:5; // end of word

    u32 argument;

    // primary/secondary effects
    const struct AdditionalEffect *additionalEffects;

    // contest parameters
    u8 contestEffect;
    u8 contestCategory:3;
    u8 contestComboStarterId;
    u8 contestComboMoves[MAX_COMBO_MOVES];
};

#define EFFECTS_ARR(...) (const struct AdditionalEffect[]) {__VA_ARGS__}
#define ADDITIONAL_EFFECTS(...) EFFECTS_ARR( __VA_ARGS__ ), .numAdditionalEffects = ARRAY_COUNT(EFFECTS_ARR( __VA_ARGS__ ))

// Just a hack to make a move boosted by Sheer Force despite having no secondary effects affected
#define SHEER_FORCE_HACK { .moveEffect = 0, .chance = 100, }

struct AdditionalEffect
{
    u16 moveEffect;
    u8 self:1;
    u8 onlyIfTargetRaisedStats:1;
    u8 onChargeTurnOnly:1;
    u8 chance; // 0% = effect certain, primary effect
};

struct Ability
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

#define SPINDA_SPOT_WIDTH 16
#define SPINDA_SPOT_HEIGHT 16

struct SpindaSpot
{
    u8 x, y;
    u16 image[SPINDA_SPOT_HEIGHT];
};

struct LevelUpMove
{
    u16 move;
    u16 level;
};

struct FormChange
{
    u16 method;
    u16 targetSpecies;
    u16 param1;
    u16 param2;
    u16 param3;
};

struct Fusion
{
    u16 fusionStorageIndex;
    u16 itemId;
    u16 targetSpecies1;
    u16 targetSpecies2;
    u16 fusingIntoMon;
    u16 fusionMove;
    u16 unfuseForgetMove;
};

extern const struct Fusion *const gFusionTablePointers[NUM_SPECIES];

#define NUM_UNOWN_FORMS 28

#define GET_UNOWN_LETTER(personality) ((   \
      (((personality) & 0x03000000) >> 18) \
    | (((personality) & 0x00030000) >> 12) \
    | (((personality) & 0x00000300) >> 6)  \
    | (((personality) & 0x00000003) >> 0)  \
) % NUM_UNOWN_FORMS)

#define GET_SHINY_VALUE(otId, personality) (HIHALF(otId) ^ LOHALF(otId) ^ HIHALF(personality) ^ LOHALF(personality))

extern u8 gPlayerPartyCount;
extern struct Pokemon gPlayerParty[PARTY_SIZE];
extern u8 gEnemyPartyCount;
extern struct Pokemon gEnemyParty[PARTY_SIZE];
extern struct SpriteTemplate gMultiuseSpriteTemplate;

extern const struct MoveInfo gMovesInfo[];
extern const u8 gFacilityClassToPicIndex[];
extern const u8 gFacilityClassToTrainerClass[];
extern const struct SpeciesInfo gSpeciesInfo[];
extern const u32 gExperienceTables[][MAX_LEVEL + 1];
extern const u8 gPPUpGetMask[];
extern const u8 gPPUpClearMask[];
extern const u8 gPPUpAddValues[];
extern const u8 gStatStageRatios[MAX_STAT_STAGE + 1][2];
extern const u16 gUnionRoomFacilityClasses[];
extern const struct SpriteTemplate gBattlerSpriteTemplates[];
extern const s8 gNatureStatTable[][5];
extern const u32 sExpCandyExperienceTable[];
extern const struct Ability gAbilitiesInfo[];

void ZeroBoxMonData(struct BoxPokemon *boxMon);
void ZeroMonData(struct Pokemon *mon);
void ZeroPlayerPartyMons(void);
void ZeroEnemyPartyMons(void);
void CreateMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId);
void CreateBoxMon(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId);
void CreateMonWithNature(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 nature);
void CreateMonWithGenderNatureLetter(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 gender, u8 nature, u8 unownLetter);
void CreateMaleMon(struct Pokemon *mon, u16 species, u8 level);
void CreateMonWithIVsPersonality(struct Pokemon *mon, u16 species, u8 level, u32 ivs, u32 personality);
void CreateMonWithIVsOTID(struct Pokemon *mon, u16 species, u8 level, u8 *ivs, u32 otId);
void CreateMonWithEVSpread(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 evSpread);
void CreateBattleTowerMon(struct Pokemon *mon, struct BattleTowerPokemon *src);
void CreateBattleTowerMon_HandleLevel(struct Pokemon *mon, struct BattleTowerPokemon *src, bool8 lvl50);
void CreateApprenticeMon(struct Pokemon *mon, const struct Apprentice *src, u8 monId);
void CreateMonWithEVSpreadNatureOTID(struct Pokemon *mon, u16 species, u8 level, u8 nature, u8 fixedIV, u8 evSpread, u32 otId);
void ConvertPokemonToBattleTowerPokemon(struct Pokemon *mon, struct BattleTowerPokemon *dest);
bool8 ShouldIgnoreDeoxysForm(u8 caseId, u8 battlerId);
u16 GetUnionRoomTrainerPic(void);
u16 GetUnionRoomTrainerClass(void);
void CreateEnemyEventMon(void);
void CalculateMonStats(struct Pokemon *mon);
void BoxMonToMon(const struct BoxPokemon *src, struct Pokemon *dest);
u8 GetLevelFromMonExp(struct Pokemon *mon);
u8 GetLevelFromBoxMonExp(struct BoxPokemon *boxMon);
u16 GiveMoveToMon(struct Pokemon *mon, u16 move);
u16 GiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move);
u16 GiveMoveToBattleMon(struct BattlePokemon *mon, u16 move);
void SetMonMoveSlot(struct Pokemon *mon, u16 move, u8 slot);
void SetBattleMonMoveSlot(struct BattlePokemon *mon, u16 move, u8 slot);
void GiveMonInitialMoveset(struct Pokemon *mon);
void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon);
void GiveMonInitialMoveset_Fast(struct Pokemon *mon);
void GiveBoxMonInitialMoveset_Fast(struct BoxPokemon *boxMon);
u16 MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove);
void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, u16 move);
void DeleteFirstMoveAndGiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move);
u8 CountAliveMonsInBattle(u8 caseId, u32 battler);
u8 GetDefaultMoveTarget(u8 battlerId);
u8 GetMonGender(struct Pokemon *mon);
u8 GetBoxMonGender(struct BoxPokemon *boxMon);
u8 GetGenderFromSpeciesAndPersonality(u16 species, u32 personality);
bool32 IsPersonalityFemale(u16 species, u32 personality);
u32 GetUnownSpeciesId(u32 personality);
void SetMultiuseSpriteTemplateToPokemon(u16 speciesTag, u8 battlerPosition);
void SetMultiuseSpriteTemplateToTrainerBack(u16 trainerSpriteId, u8 battlerPosition);
void SetMultiuseSpriteTemplateToTrainerFront(u16 trainerPicId, u8 battlerPosition);

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
u8 GiveMonToPlayer(struct Pokemon *mon);
u8 CopyMonToPC(struct Pokemon *mon);
u8 CalculatePlayerPartyCount(void);
u8 CalculateEnemyPartyCount(void);
u8 GetMonsStateToDoubles(void);
u8 GetMonsStateToDoubles_2(void);
u16 GetAbilityBySpecies(u16 species, u8 abilityNum);
u16 GetMonAbility(struct Pokemon *mon);
void CreateSecretBaseEnemyParty(struct SecretBase *secretBaseRecord);
u8 GetSecretBaseTrainerPicIndex(void);
u8 GetSecretBaseTrainerClass(void);
bool8 IsPlayerPartyAndPokemonStorageFull(void);
bool8 IsPokemonStorageFull(void);
const u8 *GetSpeciesName(u16 species);
const u8 *GetSpeciesCategory(u16 species);
const u8 *GetSpeciesPokedexDescription(u16 species);
u16 GetSpeciesHeight(u16 species);
u16 GetSpeciesWeight(u16 species);
const struct LevelUpMove *GetSpeciesLevelUpLearnset(u16 species);
const u16 *GetSpeciesTeachableLearnset(u16 species);
const struct Evolution *GetSpeciesEvolutions(u16 species);
const u16 *GetSpeciesFormTable(u16 species);
const struct FormChange *GetSpeciesFormChanges(u16 species);
u8 CalculatePPWithBonus(u16 move, u8 ppBonuses, u8 moveIndex);
void RemoveMonPPBonus(struct Pokemon *mon, u8 moveIndex);
void RemoveBattleMonPPBonus(struct BattlePokemon *mon, u8 moveIndex);
void PokemonToBattleMon(struct Pokemon *src, struct BattlePokemon *dst);
void CopyPlayerPartyMonToBattleData(u8 battlerId, u8 partyIndex);
bool8 ExecuteTableBasedItemEffect(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex);
bool8 PokemonUseItemEffects(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex, u8 e);
bool8 HealStatusConditions(struct Pokemon *mon, u32 healMask, u8 battlerId);
u8 GetItemEffectParamOffset(u32 battler, u16 itemId, u8 effectByte, u8 effectBit);
u8 *UseStatIncreaseItem(u16 itemId);
u8 GetNature(struct Pokemon *mon);
u8 GetNatureFromPersonality(u32 personality);
u16 GetEvolutionTargetSpecies(struct Pokemon *mon, u8 type, u16 evolutionItem, struct Pokemon *tradePartner);
bool8 IsMonPastEvolutionLevel(struct Pokemon *mon);
u16 NationalPokedexNumToSpecies(u16 nationalNum);
u16 NationalToHoennOrder(u16 nationalNum);
u16 SpeciesToNationalPokedexNum(u16 species);
u16 SpeciesToHoennPokedexNum(u16 species);
u16 HoennToNationalOrder(u16 hoennNum);
void DrawSpindaSpots(u32 personality, u8 *dest, bool32 isSecondFrame);
void EvolutionRenameMon(struct Pokemon *mon, u16 oldSpecies, u16 newSpecies);
u8 GetPlayerFlankId(void);
u16 GetLinkTrainerFlankId(u8 id);
s32 GetBattlerMultiplayerId(u16 id);
u8 GetTrainerEncounterMusicId(u16 trainerOpponentId);
u16 ModifyStatByNature(u8 nature, u16 n, u8 statIndex);
void AdjustFriendship(struct Pokemon *mon, u8 event);
void MonGainEVs(struct Pokemon *mon, u16 defeatedSpecies);
u16 GetMonEVCount(struct Pokemon *mon);
void RandomlyGivePartyPokerus(struct Pokemon *party);
u8 CheckPartyPokerus(struct Pokemon *party, u8 selection);
u8 CheckPartyHasHadPokerus(struct Pokemon *party, u8 selection);
void UpdatePartyPokerusTime(u16 days);
void PartySpreadPokerus(struct Pokemon *party);
bool8 TryIncrementMonLevel(struct Pokemon *mon);
u8 CanLearnTeachableMove(u16 species, u16 move);
u8 GetMoveRelearnerMoves(struct Pokemon *mon, u16 *moves);
u8 GetLevelUpMovesBySpecies(u16 species, u16 *moves);
u8 GetNumberOfRelearnableMoves(struct Pokemon *mon);
u16 SpeciesToPokedexNum(u16 species);
bool32 IsSpeciesInHoennDex(u16 species);
u16 GetBattleBGM(void);
void PlayBattleBGM(void);
void PlayMapChosenOrBattleBGM(u16 songId);
void CreateTask_PlayMapChosenOrBattleBGM(u16 songId);
const u32 *GetMonFrontSpritePal(struct Pokemon *mon);
const u32 *GetMonSpritePalFromSpeciesAndPersonality(u16 species, bool32 isShiny, u32 personality);
bool8 IsMoveHM(u16 move);
bool8 IsMonSpriteNotFlipped(u16 species);
s8 GetMonFlavorRelation(struct Pokemon *mon, u8 flavor);
s8 GetFlavorRelationByPersonality(u32 personality, u8 flavor);
bool8 IsTradedMon(struct Pokemon *mon);
bool8 IsOtherTrainer(u32 otId, u8 *otName);
void MonRestorePP(struct Pokemon *mon);
void BoxMonRestorePP(struct BoxPokemon *boxMon);
void SetMonPreventsSwitchingString(void);
void SetWildMonHeldItem(void);
bool8 IsMonShiny(struct Pokemon *mon);
const u8 *GetTrainerPartnerName(void);
void BattleAnimateFrontSprite(struct Sprite *sprite, u16 species, bool8 noCry, u8 panMode);
void DoMonFrontSpriteAnimation(struct Sprite *sprite, u16 species, bool8 noCry, u8 panModeAnimFlag);
void PokemonSummaryDoMonAnimation(struct Sprite *sprite, u16 species, bool8 oneFrame);
void StopPokemonAnimationDelayTask(void);
void BattleAnimateBackSprite(struct Sprite *sprite, u16 species);
u8 GetOpposingLinkMultiBattlerId(bool8 rightSide, u8 multiplayerId);
u16 FacilityClassToPicIndex(u16 facilityClass);
u16 PlayerGenderToFrontTrainerPicId(u8 playerGender);
void HandleSetPokedexFlag(u16 nationalNum, u8 caseId, u32 personality);
bool8 HasTwoFramesAnimation(u16 species);
struct MonSpritesGfxManager *CreateMonSpritesGfxManager(u8 managerId, u8 mode);
void DestroyMonSpritesGfxManager(u8 managerId);
u8 *MonSpritesGfxManager_GetSpritePtr(u8 managerId, u8 spriteNum);
u16 GetFormSpeciesId(u16 speciesId, u8 formId);
u8 GetFormIdFromFormSpeciesId(u16 formSpeciesId);
u16 GetFormChangeTargetSpecies(struct Pokemon *mon, u16 method, u32 arg);
u16 GetFormChangeTargetSpeciesBoxMon(struct BoxPokemon *boxMon, u16 method, u32 arg);
bool32 DoesSpeciesHaveFormChangeMethod(u16 species, u16 method);
u16 MonTryLearningNewMoveEvolution(struct Pokemon *mon, bool8 firstMove);
bool32 SpeciesHasGenderDifferences(u16 species);
bool32 TryFormChange(u32 monId, u32 side, u16 method);
void TryToSetBattleFormChangeMoves(struct Pokemon *mon, u16 method);
u32 GetMonFriendshipScore(struct Pokemon *pokemon);
u32 GetMonAffectionHearts(struct Pokemon *pokemon);
void UpdateMonPersonality(struct BoxPokemon *boxMon, u32 personality);
u8 CalculatePartyCount(struct Pokemon *party);
u16 SanitizeSpeciesId(u16 species);
bool32 IsSpeciesEnabled(u16 species);
u16 GetCryIdBySpecies(u16 species);
u16 GetSpeciesPreEvolution(u16 species);
void HealPokemon(struct Pokemon *mon);
void HealBoxPokemon(struct BoxPokemon *boxMon);
const u8 *GetMoveName(u16 moveId);

#endif // GUARD_POKEMON_H
