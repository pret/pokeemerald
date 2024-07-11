#ifndef GUARD_POKEMON_SPRITE_VISUALIZER_H
#define GUARD_POKEMON_SPRITE_VISUALIZER_H

#include "constants/pokemon_sprite_visualizer.h"

//Structs
struct PokemonSpriteVisualizerModifyArrows
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

struct PokemonSpriteVisualizerOptionArrows
{
    u8 arrowSpriteId[1];
    u8 currentDigit;
};

struct PokemonSpriteVisualizerYPosModifiyArrows
{
    u8 arrowSpriteId[1];
    u8 currentDigit;
};

struct PokemonSpriteConstValues
{
    u8 backPicCoords;
    u8 frontPicCoords;
    u8 frontElevation;
};

struct PokemonSpriteOffsets
{
    s8 offset_back_picCoords;
    s8 offset_front_picCoords;
    s8 offset_front_elevation;
};

struct PokemonSpriteVisualizer
{
    u16 currentmonId;
    u8 currentmonWindowId;
    u8 InstructionsWindowId;
    u8 frontspriteId;
    u8 backspriteId;
    u8 iconspriteId;
    u8 followerspriteId;
    u8 frontShadowSpriteId;
    bool8 isShiny;
    bool8 isFemale;
    struct PokemonSpriteVisualizerModifyArrows modifyArrows;
    struct PokemonSpriteVisualizerOptionArrows optionArrows;
    struct PokemonSpriteVisualizerYPosModifiyArrows yPosModifyArrows;
    struct PokemonSpriteConstValues constSpriteValues;
    struct PokemonSpriteOffsets offsetsSpriteValues;
    u8 animIdBack;
    u8 animIdFront;
    u8 battleBgType;
    u8 battleTerrain;
    u8 currentSubmenu;
    u8 submenuYpos[3];
};

void CB2_Pokemon_Sprite_Visualizer(void);


#endif // GUARD_POKEMON_SPRITE_VISUALIZER_H
