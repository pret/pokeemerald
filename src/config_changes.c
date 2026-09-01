#include "global.h"
#include "config_changes.h"
#include "malloc.h"
#include "constants/config_changes.h"
#include "config/pokerus.h"
#include "config/ai.h"

#define UNPACK_BATTLE_CONFIG_GEN_CHANGES(_name, _field, ...) ._field = _name,
#define UNPACK_POKEMON_CONFIG_GEN_CHANGES(_name, _field, ...) ._field = P_##_name,
#define UNPACK_AI_CONFIG_CHANGES(_name, _field, ...) ._field = _name,

const struct ConfigChanges sConfigChanges =
{
    BATTLE_CONFIG_DEFINITIONS(UNPACK_BATTLE_CONFIG_GEN_CHANGES)
    POKEMON_CONFIG_DEFINITIONS(UNPACK_POKEMON_CONFIG_GEN_CHANGES)
    AI_CONFIG_DEFINITIONS(UNPACK_AI_CONFIG_CHANGES)
    /* Expands to:
    .critChance     = B_CRIT_CHANCE,
    .critMultiplier = B_CRIT_MULTIPLIER,
    */
};

#if TESTING
EWRAM_DATA struct ConfigChanges *gConfigChangesTestOverride = NULL;
#define UNPACK_CONFIG_OVERRIDE_GETTERS(_name, _field, ...)   case CONFIG_##_name: return gConfigChangesTestOverride->_field;
#define UNPACK_CONFIG_GETTERS(_name, _field, ...) case CONFIG_##_name: return sConfigChanges._field;
#define UNPACK_CONFIG_CLAMPER(_name, _field, _typeMaxValue, ...) case CONFIG_##_name: clampedValue = min(GET_CONFIG_MAXIMUM(_typeMaxValue), newValue); break;
#define UNPACK_CONFIG_SETTERS(_name, _field, _typeMaxValue, ...) case CONFIG_##_name: gConfigChangesTestOverride->_field = clampedValue; break;

#else

#define UNPACK_CONFIG_OVERRIDE_GETTERS(_name, _field, ...) case CONFIG_##_name: return sConfigChanges._field;
#define UNPACK_CONFIG_GETTERS(_name, _field, ...) case CONFIG_##_name: return sConfigChanges._field;
#define UNPACK_CONFIG_CLAMPER(_name, _field, ...) case CONFIG_##_name: return 0;
#define UNPACK_CONFIG_SETTERS(_name, _field, ...) case CONFIG_##_name: return;
#endif

// Gets the value of a volatile status flag for a certain battler
// Primarily used for the debug menu and scripts. Outside of it explicit references are preferred
ARM_FUNC u32 GetConfigInternal(enum ConfigTag _config)
{
#if TESTING
    if (gConfigChangesTestOverride == NULL)
    {
        switch (_config)
        {
        BATTLE_CONFIG_DEFINITIONS(UNPACK_CONFIG_GETTERS)
        POKEMON_CONFIG_DEFINITIONS(UNPACK_CONFIG_GETTERS)
        AI_CONFIG_DEFINITIONS(UNPACK_CONFIG_GETTERS)
        /* Expands to:
        case CONFIG_CRIT_CHANCE:
            return gConfigChangesTestOverride->critChance;
        */
        default:
            return 0;
        }
    }
    else
#endif
    {
        switch (_config)
        {
        BATTLE_CONFIG_DEFINITIONS(UNPACK_CONFIG_OVERRIDE_GETTERS)
        POKEMON_CONFIG_DEFINITIONS(UNPACK_CONFIG_OVERRIDE_GETTERS)
        AI_CONFIG_DEFINITIONS(UNPACK_CONFIG_OVERRIDE_GETTERS)
        /* Expands to:
        case CONFIG_CRIT_CHANCE:
            return sConfigChanges.critChance;
        */
        default: // Invalid config tag
            return 0;
        }
     }
}

#if TESTING
u32 GetClampedValue(enum ConfigTag _config, u32 newValue)
{
    u32 clampedValue = 0;
    switch (_config)
    {
    BATTLE_CONFIG_DEFINITIONS(UNPACK_CONFIG_CLAMPER)
    POKEMON_CONFIG_DEFINITIONS(UNPACK_CONFIG_CLAMPER)
    AI_CONFIG_DEFINITIONS(UNPACK_CONFIG_CLAMPER)
    default:
        return 0;
    }
    return clampedValue;
}
#endif

void SetConfig(enum ConfigTag _config, u32 _value)
{
#if TESTING
    // Clamping is done here instead of the switch due to an internal compiler error!
    u32 clampedValue = GetClampedValue(_config, _value);
    switch (_config)
    {
    BATTLE_CONFIG_DEFINITIONS(UNPACK_CONFIG_SETTERS)
    POKEMON_CONFIG_DEFINITIONS(UNPACK_CONFIG_SETTERS)
    AI_CONFIG_DEFINITIONS(UNPACK_CONFIG_SETTERS)
    /* Expands to:
    #if TESTING
    case CONFIG_CRIT_CHANCE:
        gConfigChangesTestOverride->critChance = clampedValue;
        break;
    #else
    case CONFIG_CRIT_CHANCE:
        return;
    #endif
    */
    default: // Invalid config tag
        return;
    }
#endif
}

#if TESTING
void TestInitConfigData(void)
{
    Free(gConfigChangesTestOverride);
    gConfigChangesTestOverride = Alloc(sizeof(sConfigChanges));
    memcpy(gConfigChangesTestOverride, &sConfigChanges, sizeof(sConfigChanges));
}

void TestFreeConfigData(void)
{
    FREE_AND_SET_NULL(gConfigChangesTestOverride);
}
#endif
