#ifndef GUARD_POKEMON_H
#define GUARD_POKEMON_H

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
    /*0x00*/ u8 pokerus;
    /*0x01*/ u8 metLocation;

    /*0x02*/ u16 metLevel:7;
    /*0x02*/ u16 metGame:4;
    /*0x03*/ u16 pokeball:4;
    /*0x03*/ u16 otGender:1;

    /*0x04*/ u32 hpIV:5;
    /*0x04*/ u32 attackIV:5;
    /*0x05*/ u32 defenseIV:5;
    /*0x05*/ u32 speedIV:5;
    /*0x05*/ u32 spAttackIV:5;
    /*0x06*/ u32 spDefenseIV:5;
    /*0x07*/ u32 isEgg:1;
    /*0x07*/ u32 altAbility:1;

    /*0x08*/ u32 coolRibbon:3;
    /*0x08*/ u32 beautyRibbon:3;
    /*0x08*/ u32 cuteRibbon:3;
    /*0x09*/ u32 smartRibbon:3;
    /*0x09*/ u32 toughRibbon:3;
    /*0x09*/ u32 championRibbon:1;
    /*0x0A*/ u32 winningRibbon:1;
    /*0x0A*/ u32 victoryRibbon:1;
    /*0x0A*/ u32 artistRibbon:1;
    /*0x0A*/ u32 effortRibbon:1;
    /*0x0A*/ u32 giftRibbon1:1;
    /*0x0A*/ u32 giftRibbon2:1;
    /*0x0A*/ u32 giftRibbon3:1;
    /*0x0A*/ u32 giftRibbon4:1;
    /*0x0B*/ u32 giftRibbon5:1;
    /*0x0B*/ u32 giftRibbon6:1;
    /*0x0B*/ u32 giftRibbon7:1;
    /*0x0B*/ u32 fatefulEncounter:5; // unused in Ruby/Sapphire, but the high bit must be set for Mew/Deoxys to obey in FR/LG/Emerald
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
    /*0x00*/ u32 personality;
    /*0x04*/ u32 otId;
    /*0x08*/ u8 nickname[POKEMON_NAME_LENGTH];
    /*0x12*/ u8 language;
    /*0x13*/ u8 isBadEgg:1;
             u8 hasSpecies:1;
             u8 isEgg:1;
    /*0x14*/ u8 otName[OT_NAME_LENGTH];
    /*0x1B*/ u8 markings;
    /*0x1C*/ u16 checksum;
    /*0x1E*/ u16 unknown;

    union
    {
        u32 raw[12];
        union PokemonSubstruct substructs[4];
    } secure;
}; /*size = 0x50*/

struct Pokemon
{
    /*0x00*/ struct BoxPokemon box;
    /*0x50*/ u32 status;
    /*0x54*/ u8 level;
    /*0x55*/ u8 mail;
    /*0x56*/ u16 hp;
    /*0x58*/ u16 maxHP;
    /*0x5A*/ u16 attack;
    /*0x5C*/ u16 defense;
    /*0x5E*/ u16 speed;
    /*0x60*/ u16 spAttack;
    /*0x62*/ u16 spDefense;
};

struct BattleTowerPokemon
{
    /*0x00*/u16 species;
    /*0x02*/u16 heldItem;
    /*0x04*/u16 moves[4];
    /*0x0C*/u8 level;
    /*0x0D*/u8 ppBonuses;
    /*0x0E*/u8 hpEV;
    /*0x0F*/u8 attackEV;
    /*0x10*/u8 defenseEV;
    /*0x11*/u8 speedEV;
    /*0x12*/u8 spAttackEV;
    /*0x13*/u8 spDefenseEV;
    /*0x14*/u32 otId;
    /*0x18*/u32 hpIV:5;
    /*0x18*/u32 attackIV:5;
    /*0x19*/u32 defenseIV:5;
    /*0x19*/u32 speedIV:5;
    /*0x1A*/u32 spAttackIV:5;
    /*0x1A*/u32 spDefenseIV:5;
    /*0x1B*/u32 gap:1;
    /*0x1B*/u32 altAbility:1;
    /*0x1C*/u32 personality;
    /*0x20*/u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x2B*/u8 friendship;
};

struct PokemonStorage
{
    /*0x0000*/ u8 currentBox;
    /*0x0004*/ struct BoxPokemon boxes[14][30];
    /*0x8344*/ u8 boxNames[14][9];
    /*0x83c2*/ u8 wallpaper[14];
};

#endif // GUARD_POKEMON_H
