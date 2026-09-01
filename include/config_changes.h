#ifndef GUARD_CONFIG_CHANGES_H
#define GUARD_CONFIG_CHANGES_H

#include "constants/config_changes.h"
#include "config/battle.h"
#include "config/pokerus.h"
#include "config/ai.h"

#define UNPACK_CONFIG_STRUCT(_name, _field, _typeMaxValue, ...) INVOKE_WITH_(UNPACK_CONFIG_STRUCT_, _field, UNPACK_B(_typeMaxValue));
#define UNPACK_CONFIG_STRUCT_(_field, _type, ...) _type FIRST(__VA_OPT__(_field:BIT_SIZE(FIRST(__VA_ARGS__)),) _field)

struct ConfigChanges
{
    BATTLE_CONFIG_DEFINITIONS(UNPACK_CONFIG_STRUCT)
    POKEMON_CONFIG_DEFINITIONS(UNPACK_CONFIG_STRUCT)
    AI_CONFIG_DEFINITIONS(UNPACK_CONFIG_STRUCT)
    // Expands to:
    // u32 critChance:4;
    // u32 critMultiplier:4;
    // ...
};

#define GetConfig(name) GetConfigInternal(CONFIG_##name)

ARM_FUNC u32 GetConfigInternal(enum ConfigTag configTag);
void SetConfig(enum ConfigTag configTag, u32 value);

#if TESTING
void TestInitConfigData(void);
void TestFreeConfigData(void);
#endif

#endif // GUARD_CONFIG_CHANGES_H
