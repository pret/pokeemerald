#ifndef GUARD_POKEMON_DEBUG_H
#define GUARD_POKEMON_DEBUG_H

#include "constants/pokemon_debug.h"

//Structs
struct PokemonDebugModifyArrows
{
    u8 arrowSpriteId[2];
    u16 minValue;
    u16 maxValue;
    int currValue;
    u8 currentDigit;
    u8 maxDigits;
    u8 charDigits[MODIFY_DIGITS_MAX];
    void *modifiedValPtr;
    u8 typeOfVal;
};

struct PokemonDebugOptionArrows
{
    u8 arrowSpriteId[2];
    u8 currentDigit;
    void *modifiedValPtr;
};

struct PokemonDebugMenu
{
    u16 currentmonId;
    u8 currentmonWindowId;
    u8 InstructionsWindowId;
    u8 frontspriteId;
    u8 backspriteId;
    u8 iconspriteId;
    bool8 isShiny;
    bool8 isFemale;
    struct PokemonDebugModifyArrows modifyArrows;
    struct PokemonDebugOptionArrows optionArrows;
    u8 animIdBack;
    u8 animIdFront;
    u8 battleBgType;
    u8 battleTerrain;
    bool8 inSubmenu;
    u8 submenuYpos;
};

void CB2_Debug_Pokemon(void);


#endif // GUARD_POKEMON_DEBUG_H