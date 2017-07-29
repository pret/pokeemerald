#define MON_DATA_PERSONALITY        0
#define MON_DATA_OT_ID              1
#define MON_DATA_NICKNAME           2
#define MON_DATA_LANGUAGE           3
#define MON_DATA_SANITY_BIT1        4
#define MON_DATA_SANITY_BIT2        5
#define MON_DATA_SANITY_BIT3        6
#define MON_DATA_OT_NAME            7
#define MON_DATA_MARKINGS           8
#define MON_DATA_CHECKSUM           9
#define MON_DATA_10                10
#define MON_DATA_SPECIES           11
#define MON_DATA_HELD_ITEM         12
#define MON_DATA_MOVE1             13
#define MON_DATA_MOVE2             14
#define MON_DATA_MOVE3             15
#define MON_DATA_MOVE4             16
#define MON_DATA_PP1               17
#define MON_DATA_PP2               18
#define MON_DATA_PP3               19
#define MON_DATA_PP4               20
#define MON_DATA_PP_BONUSES        21
#define MON_DATA_COOL              22
#define MON_DATA_BEAUTY            23
#define MON_DATA_CUTE              24
#define MON_DATA_EXP               25
#define MON_DATA_HP_EV             26
#define MON_DATA_ATK_EV            27
#define MON_DATA_DEF_EV            28
#define MON_DATA_SPD_EV            29
#define MON_DATA_SPATK_EV          30
#define MON_DATA_SPDEF_EV          31
#define MON_DATA_FRIENDSHIP        32
#define MON_DATA_SMART             33
#define MON_DATA_POKERUS           34
#define MON_DATA_MET_LOCATION      35
#define MON_DATA_MET_LEVEL         36
#define MON_DATA_MET_GAME          37
#define MON_DATA_POKEBALL          38
#define MON_DATA_HP_IV             39
#define MON_DATA_ATK_IV            40
#define MON_DATA_DEF_IV            41
#define MON_DATA_SPD_IV            42
#define MON_DATA_SPATK_IV          43
#define MON_DATA_SPDEF_IV          44
#define MON_DATA_IS_EGG            45
#define MON_DATA_ALT_ABILITY       46
#define MON_DATA_TOUGH             47
#define MON_DATA_SHEEN             48
#define MON_DATA_OT_GENDER         49
#define MON_DATA_COOL_RIBBON       50
#define MON_DATA_BEAUTY_RIBBON     51
#define MON_DATA_CUTE_RIBBON       52
#define MON_DATA_SMART_RIBBON      53
#define MON_DATA_TOUGH_RIBBON      54
#define MON_DATA_STATUS            55
#define MON_DATA_LEVEL             56
#define MON_DATA_HP                57
#define MON_DATA_MAX_HP            58
#define MON_DATA_ATK               59
#define MON_DATA_DEF               60
#define MON_DATA_SPD               61
#define MON_DATA_SPATK             62
#define MON_DATA_SPDEF             63
#define MON_DATA_64                64
#define MON_DATA_SPECIES2          65
#define MON_DATA_IVS               66
#define MON_DATA_CHAMPION_RIBBON   67
#define MON_DATA_WINNING_RIBBON    68
#define MON_DATA_VICTORY_RIBBON    69
#define MON_DATA_ARTIST_RIBBON     70
#define MON_DATA_EFFORT_RIBBON     71
#define MON_DATA_GIFT_RIBBON_1     72
#define MON_DATA_GIFT_RIBBON_2     73
#define MON_DATA_GIFT_RIBBON_3     74
#define MON_DATA_GIFT_RIBBON_4     75
#define MON_DATA_GIFT_RIBBON_5     76
#define MON_DATA_GIFT_RIBBON_6     77
#define MON_DATA_GIFT_RIBBON_7     78
#define MON_DATA_FATEFUL_ENCOUNTER 79
#define MON_DATA_KNOWN_MOVES       80
#define MON_DATA_RIBBON_COUNT      81
#define MON_DATA_RIBBONS           82
#define MON_DATA_83                83
#define MON_DATA_ATK2              84
#define MON_DATA_DEF2              85
#define MON_DATA_SPD2              86
#define MON_DATA_SPATK2            87
#define MON_DATA_SPDEF2            88

#define MON_MALE       0x00
#define MON_FEMALE     0xFE
#define MON_GENDERLESS 0xFF

#define TYPE_NORMAL   0x00
#define TYPE_FIGHTING 0x01
#define TYPE_FLYING   0x02
#define TYPE_POISON   0x03
#define TYPE_GROUND   0x04
#define TYPE_ROCK     0x05
#define TYPE_BUG      0x06
#define TYPE_GHOST    0x07
#define TYPE_STEEL    0x08
#define TYPE_MYSTERY  0x09
#define TYPE_FIRE     0x0a
#define TYPE_WATER    0x0b
#define TYPE_GRASS    0x0c
#define TYPE_ELECTRIC 0x0d
#define TYPE_PSYCHIC  0x0e
#define TYPE_ICE      0x0f
#define TYPE_DRAGON   0x10
#define TYPE_DARK     0x11

enum {
    NATURE_HARDY,
    NATURE_LONELY,
    NATURE_BRAVE,
    NATURE_ADAMANT,
    NATURE_NAUGHTY,
    NATURE_BOLD,
    NATURE_DOCILE,
    NATURE_RELAXED,
    NATURE_IMPISH,
    NATURE_LAX,
    NATURE_TIMID,
    NATURE_HASTY,
    NATURE_SERIOUS,
    NATURE_JOLLY,
    NATURE_NAIVE,
    NATURE_MODEST,
    NATURE_MILD,
    NATURE_QUIET,
    NATURE_BASHFUL,
    NATURE_RASH,
    NATURE_CALM,
    NATURE_GENTLE,
    NATURE_SASSY,
    NATURE_CAREFUL,
    NATURE_QUIRKY,
};

struct PokemonSubstruct0
{
    u16 species;
    u16 heldItem;
    u32 experience;
    u8 ppBonuses;
    u8 friendship;
};

struct PokemonSubstruct1
{
    u16 moves[4];
    u8 pp[4];
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
 /* 0x00 */ u8 pokerus;
 /* 0x01 */ u8 metLocation;

 /* 0x02 */ u16 metLevel:7;
 /* 0x02 */ u16 metGame:4;
 /* 0x03 */ u16 pokeball:4;
 /* 0x03 */ u16 otGender:1;

 /* 0x04 */ u32 hpIV:5;
 /* 0x04 */ u32 attackIV:5;
 /* 0x05 */ u32 defenseIV:5;
 /* 0x05 */ u32 speedIV:5;
 /* 0x05 */ u32 spAttackIV:5;
 /* 0x06 */ u32 spDefenseIV:5;
 /* 0x07 */ u32 isEgg:1;
 /* 0x07 */ u32 altAbility:1;

 /* 0x08 */ u32 coolRibbon:3;
 /* 0x08 */ u32 beautyRibbon:3;
 /* 0x08 */ u32 cuteRibbon:3;
 /* 0x09 */ u32 smartRibbon:3;
 /* 0x09 */ u32 toughRibbon:3;
 /* 0x09 */ u32 championRibbon:1;
 /* 0x0A */ u32 winningRibbon:1;
 /* 0x0A */ u32 victoryRibbon:1;
 /* 0x0A */ u32 artistRibbon:1;
 /* 0x0A */ u32 effortRibbon:1;
 /* 0x0A */ u32 giftRibbon1:1;
 /* 0x0A */ u32 giftRibbon2:1;
 /* 0x0A */ u32 giftRibbon3:1;
 /* 0x0A */ u32 giftRibbon4:1;
 /* 0x0B */ u32 giftRibbon5:1;
 /* 0x0B */ u32 giftRibbon6:1;
 /* 0x0B */ u32 giftRibbon7:1;
 /* 0x0B */ u32 fatefulEncounter:5; // unused in Ruby/Sapphire, but the high bit must be set for Mew/Deoxys to obey in FR/LG/Emerald
};

union PokemonSubstruct
{
    struct PokemonSubstruct0 type0;
    struct PokemonSubstruct1 type1;
    struct PokemonSubstruct2 type2;
    struct PokemonSubstruct3 type3;
    u16 raw[6];
};

struct BoxPokemon
{
    u32 personality;
    u32 otId;
    u8 nickname[POKEMON_NAME_LENGTH];
    u8 language;
    u8 isBadEgg:1;
    u8 hasSpecies:1;
    u8 isEgg:1;
    u8 unused:5;
    u8 otName[OT_NAME_LENGTH];
    u8 markings;
    u16 checksum;
    u16 unknown;

    union
    {
        u32 raw[12];
        union PokemonSubstruct substructs[4];
    } secure;
};

struct Pokemon
{
    struct BoxPokemon box;
    u32 status;
    u8 level;
    u8 pokerus;
    u16 hp;
    u16 maxHP;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 spAttack;
    u16 spDefense;
};

extern struct Pokemon gPlayerParty[6];
extern struct Pokemon gEnemyParty[6];

struct BaseStats
{
 /* 0x00 */ u8 baseHP;
 /* 0x01 */ u8 baseAttack;
 /* 0x02 */ u8 baseDefense;
 /* 0x03 */ u8 baseSpeed;
 /* 0x04 */ u8 baseSpAttack;
 /* 0x05 */ u8 baseSpDefense;
 /* 0x06 */ u8 type1;
 /* 0x07 */ u8 type2;
 /* 0x08 */ u8 catchRate;
 /* 0x09 */ u8 expYield;
 /* 0x0A */ u16 evYield_HP:2;
 /* 0x0A */ u16 evYield_Attack:2;
 /* 0x0A */ u16 evYield_Defense:2;
 /* 0x0A */ u16 evYield_Speed:2;
 /* 0x0B */ u16 evYield_SpAttack:2;
 /* 0x0B */ u16 evYield_SpDefense:2;
 /* 0x0C */ u16 item1;
 /* 0x0E */ u16 item2;
 /* 0x10 */ u8 genderRatio;
 /* 0x11 */ u8 eggCycles;
 /* 0x12 */ u8 friendship;
 /* 0x13 */ u8 growthRate;
 /* 0x14 */ u8 eggGroup1;
 /* 0x15 */ u8 eggGroup2;
 /* 0x16 */ u8 ability1;
 /* 0x17 */ u8 ability2;
 /* 0x18 */ u8 safariZoneFleeRate;
 /* 0x19 */ u8 bodyColor;
};

struct BattleMove
{
    u8 effect;
    u8 power;
    u8 type;
    u8 accuracy;
    u8 pp;
    u8 secondaryEffectChance;
    u8 target;
    u8 priority;
    u32 flags;
};

#define POKEMON_NAME_LENGTH 10

struct BattlePokemon
{
 /* 0x00 */ u16 species;
 /* 0x02 */ u16 attack;
 /* 0x04 */ u16 defense;
 /* 0x06 */ u16 speed;
 /* 0x08 */ u16 spAttack;
 /* 0x0A */ u16 spDefense;
 /* 0x0C */ u16 moves[4];
 /* 0x14 */ u32 hpIV:5;
 /* 0x14 */ u32 attackIV:5;
 /* 0x15 */ u32 defenseIV:5;
 /* 0x15 */ u32 speedIV:5;
 /* 0x16 */ u32 spAttackIV:5;
 /* 0x17 */ u32 spDefenseIV:5;
 /* 0x17 */ u32 isEgg:1;
 /* 0x17 */ u32 altAbility:1;
 /* 0x18 */ s8 statStages[8];
 /* 0x20 */ u8 ability;
 /* 0x21 */ u8 type1;
 /* 0x22 */ u8 type2;
 /* 0x23 */ u8 unknown;
 /* 0x24 */ u8 pp[4];
 /* 0x28 */ u16 hp;
 /* 0x2A */ u8 level;
 /* 0x2B */ u8 friendship;
 /* 0x2C */ u16 maxHP;
 /* 0x2E */ u16 item;
 /* 0x30 */ u8 nickname[POKEMON_NAME_LENGTH + 1];
 /* 0x3B */ u8 ppBonuses;
 /* 0x3C */ u8 otName[8];
 /* 0x44 */ u32 experience;
 /* 0x48 */ u32 personality;
 /* 0x4C */ u32 status1;
 /* 0x50 */ u32 status2;
 /* 0x54 */ u32 otId;
};

// These are full type signatures for GetMonData() and GetBoxMonData(),
// but they are not used since some code erroneously omits the third arg.
// u32 GetMonData(struct Pokemon *mon, s32 field, u8 *data);
u32 GetMonData();

u8 pokemon_species_get_gender_info(u16 species, u32 personality);