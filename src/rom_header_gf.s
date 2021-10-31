#include "constants/global.h"

@ 80000C0
    .word 0

    .global GPIOPortData
GPIOPortData: @ 80000C4
    .2byte 0

    .global GPIOPortDirection
GPIOPortDirection: @ 80000C6
    .2byte 0

    .global GPIOPortReadEnable
GPIOPortReadEnable: @ 80000C8
    .2byte 0

@ 80000CA
    .2byte 0

@ 80000CC
    .space 0x34

    .4byte GAME_VERSION
    .4byte GAME_LANGUAGE

    .ascii "pokemon emerald version"
    .space 9

    .4byte gMonFrontPicTable
    .4byte gMonBackPicTable
    .4byte gMonPaletteTable
    .4byte gMonShinyPaletteTable
    .4byte gMonIconTable
    .4byte gMonIconPaletteIndices
    .4byte gMonIconPaletteTable
    .4byte gSpeciesNames
    .4byte gMoveNames
    .4byte gDecorations

    .4byte 0x00001270 @ offsetof(struct SaveBlock1, flags)
    .4byte 0x0000139c @ offsetof(struct SaveBlock1, vars)
    .4byte 0x00000018 @ offsetof(struct SaveBlock2, pokedex)
    .4byte 0x00000988 @ offsetof(struct SaveBlock1, seen1)
    .4byte 0x00003b24 @ offsetof(struct SaveBlock1, seen2)
    .4byte 0x00000046 @ ?
    .4byte 0x000008e4 @ ?
    .4byte 0x000008ac @ ?
    .4byte 0x00000182 @ NATIONAL_DEX_COUNT?

    .byte 0x07, 0x0a, 0x0a, 0x0a, 0x0c, 0x0c, 0x06, 0x0c
    .byte 0x06, 0x10, 0x12, 0x0c, 0x0f, 0x0b, 0x01, 0x08

    .4byte 0x0000000c @ ?
    .4byte 0x00000f2c @ sizeof(struct SaveBlock2)
    .4byte 0x00003d88 @ sizeof(struct SaveBlock1)
    .4byte 0x00000234 @ offsetof(struct SaveBlock1, playerPartyCount)
    .4byte 0x00000238 @ offsetof(struct SaveBlock1, playerParty)
    .4byte 0x00000009 @ offsetof(struct SaveBlock2, specialSaveWarpFlags)
    .4byte 0x0000000a @ offsetof(struct SaveBlock2, playerTrainerId)
    .4byte 0x00000000 @ offsetof(struct SaveBlock2, playerName)
    .4byte 0x00000008 @ offsetof(struct SaveBlock2, playerGender)
    .4byte 0x00000ca8 @ offsetof(struct SaveBlock2, frontier.challengeStatus)
    .4byte 0x00000ca8 @ offsetof(struct SaveBlock2, frontier.challengeStatus)
    .4byte 0x000031c7 @ offsetof(struct SaveBlock1, externalEventFlags)
    .4byte 0x000031b3 @ offsetof(struct SaveBlock1, externalEventData)
    .4byte 0x00000000

    .4byte gBaseStats
    .4byte gAbilityNames
    .4byte gAbilityDescriptionPointers
    .4byte gItems
    .4byte gBattleMoves
    .4byte gBallSpriteSheets
    .4byte gBallSpritePalettes

    .4byte 0x000000a8 @ offsetof(struct SaveBlock2, gcnLinkFlags)
    .4byte 0x00000864 @ ?
    .4byte 0x0000089b @ ?

    .byte 0x1e, 0x1e, 0x10, 0x40

    .4byte 0x0000322e @ offsetof(struct SaveBlock1, ? part-way into mysteryGift)
    .4byte 0x00000498 @ offsetof(struct SaveBlock1, pcItems)
    .4byte 0x000031a8 @ offsetof(struct SaveBlock1, giftRibbons)
    .4byte 0x000031f8 @ offsetof(struct SaveBlock1, enigmaBerry)
    .4byte 0x00000034 @ offsetof(struct SaveBlock1, mapView)
    .4byte 0x00000000
    .4byte 0x00000000
