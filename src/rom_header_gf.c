#include "global.h"
#include "data.h"
#include "pokemon_icon.h"
#include "decoration.h"
#include "battle_main.h"
#include "item.h"
#include "pokeball.h"

struct GFRomHeader
{
    u32 version;
    u32 language;
    u8 gameName[32];
    const struct CompressedSpriteSheet * monFrontPics;
    const struct CompressedSpriteSheet * monBackPics;
    const struct CompressedSpritePalette * monNormalPalettes;
    const struct CompressedSpritePalette * monShinyPalettes;
    const u8 * const * monIcons;
    const u8 * monIconPaletteIds;
    const struct SpritePalette * monIconPalettes;
    const u8 (* monSpeciesNames)[];
    const u8 (* moveNames)[];
    const struct Decoration * decorations;
    u32 flagsOffset;
    u32 varsOffset;
    u32 pokedexOffset;
    u32 seen1Offset;
    u32 seen2Offset;
    u32 unk_01;
    u32 unk_02;
    u32 unk_03;
    u32 dexCount;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    u8 unk_10;
    u8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u32 saveBlock2Size;
    u32 saveBlock1Size;
    u32 partyCountOffset;
    u32 partyOffset;
    u32 warpFlagsOffset;
    u32 trainerIdOffset;
    u32 playerNameOffset;
    u32 playerGenderOffset;
    u32 frontierStatusOffset;
    u32 frontierStatusOffset2;
    u32 externalEventFlagsOffset;
    u32 externalEventDataOffset;
    u32 unk_15;
    const struct BaseStats * baseStats;
    const u8 (* abilityNames)[];
    const u8 * const * abilityDescriptions;
    const struct Item * items;
    const struct BattleMove * moves;
    const struct CompressedSpriteSheet * ballGfx;
    const struct CompressedSpritePalette * ballPalettes;
    u32 gcnLinkFlagsOffset;
    u32 unk_16;
    u32 unk_17;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1A;
    u8 unk_1B;
    u32 unk_1C;
    u32 pcItemsOffset;
    u32 giftRibbonsOffset;
    u32 enigmaBerryOffset;
    u32 mapViewOffset;
    u32 unk_1D;
    u32 unk_1E;
};

// This seems to need to be in the text section for some reason.
// To avoid a changed section warning it's put in a special .text.consts section instead of .text.
__attribute__((section(".text.consts")))
static const struct GFRomHeader sGFRomHeader = {
    .version = GAME_VERSION,
    .language = GAME_LANGUAGE,
    .gameName = "pokemon emerald version",
    .monFrontPics = gMonFrontPicTable,
    .monBackPics = gMonBackPicTable,
    .monNormalPalettes = gMonPaletteTable,
    .monShinyPalettes = gMonShinyPaletteTable,
    .monIcons = gMonIconTable,
    .monIconPaletteIds = gMonIconPaletteIndices,
    .monIconPalettes = gMonIconPaletteTable,
    .monSpeciesNames = gSpeciesNames,
    .moveNames = gMoveNames,
    .decorations = gDecorations,
    .flagsOffset = offsetof(struct SaveBlock1, flags),
    .varsOffset = offsetof(struct SaveBlock1, vars),
    .pokedexOffset = offsetof(struct SaveBlock2, pokedex),
    .seen1Offset = offsetof(struct SaveBlock1, seen1),
    .seen2Offset = offsetof(struct SaveBlock1, seen2),
    .unk_01 = 0x00000046,
    .unk_02 = 0x000008e4,
    .unk_03 = 0x000008ac,
    .dexCount = NATIONAL_DEX_COUNT,
    .unk_04 = 0x07,
    .unk_05 = 0x0a,
    .unk_06 = 0x0a,
    .unk_07 = 0x0a,
    .unk_08 = 0x0c,
    .unk_09 = 0x0c,
    .unk_0A = 0x06,
    .unk_0B = 0x0c,
    .unk_0C = 0x06,
    .unk_0D = 0x10,
    .unk_0E = 0x12,
    .unk_0F = 0x0c,
    .unk_10 = 0x0f,
    .unk_11 = 0x0b,
    .unk_12 = 0x01,
    .unk_13 = 0x08,
    .unk_14 = 0x0c,
    .saveBlock2Size = sizeof(struct SaveBlock2),
    .saveBlock1Size = sizeof(struct SaveBlock1),
    .partyCountOffset = offsetof(struct SaveBlock1, playerPartyCount),
    .partyOffset = offsetof(struct SaveBlock1, playerParty),
    .warpFlagsOffset = offsetof(struct SaveBlock2, specialSaveWarpFlags),
    .trainerIdOffset = offsetof(struct SaveBlock2, playerTrainerId),
    .playerNameOffset = offsetof(struct SaveBlock2, playerName),
    .playerGenderOffset = offsetof(struct SaveBlock2, playerGender),
    .frontierStatusOffset = offsetof(struct SaveBlock2, frontier.challengeStatus),
    .frontierStatusOffset2 = offsetof(struct SaveBlock2, frontier.challengeStatus),
    .externalEventFlagsOffset = offsetof(struct SaveBlock1, externalEventFlags),
    .externalEventDataOffset = offsetof(struct SaveBlock1, externalEventData),
    .unk_15 = 0x00000000,
    .baseStats = gBaseStats,
    .abilityNames = gAbilityNames,
    .abilityDescriptions = gAbilityDescriptionPointers,
    .items = gItems,
    .moves = gBattleMoves,
    .ballGfx = gBallSpriteSheets,
    .ballPalettes = gBallSpritePalettes,
    .gcnLinkFlagsOffset = offsetof(struct SaveBlock2, gcnLinkFlags),
    .unk_16 = 0x00000864,
    .unk_17 = 0x0000089b,
    .unk_18 = 0x1e,
    .unk_19 = 0x1e,
    .unk_1A = 0x10,
    .unk_1B = 0x40,
    .unk_1C = 0x0000322e, // offsetof(struct SaveBlock1, ? part-way into mysteryGift)
    .pcItemsOffset = offsetof(struct SaveBlock1, pcItems),
    .giftRibbonsOffset = offsetof(struct SaveBlock1, giftRibbons),
    .enigmaBerryOffset = offsetof(struct SaveBlock1, enigmaBerry),
    .mapViewOffset = offsetof(struct SaveBlock1, mapView),
    .unk_1D = 0x00000000,
    .unk_1E = 0x00000000,
};

