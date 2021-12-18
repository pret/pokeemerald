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
    u32 seenOffset;
    u32 pokedexVar;
    u32 pokedexFlag;
    u32 mysteryEventFlag;
    u32 pokedexCount;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
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
    u32 unk18;
    const struct BaseStats * baseStats;
    const u8 (* abilityNames)[];
    const u8 * const * abilityDescriptions;
    const struct Item * items;
    const struct BattleMove * moves;
    const struct CompressedSpriteSheet * ballGfx;
    const struct CompressedSpritePalette * ballPalettes;
    u32 gcnLinkFlagsOffset;
    u32 gameClearFlag;
    u32 ribbonFlag;
    u8 bagCountItems;
    u8 bagCountKeyItems;
    u8 bagCountPokeballs;
    u8 bagCountTMHMs;
    u8 bagCountBerries;
    u8 pcItemsCount;
    u32 pcItemsOffset;
    u32 giftRibbonsOffset;
    u32 enigmaBerryOffset;
    u32 mapViewOffset;
    u32 unk19;
    u32 unk20;
};

// This seems to need to be in the text section for some reason.
// To avoid a changed section attributes warning it's put in a special .text.consts section.
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
    .seenOffset = offsetof(struct SaveBlock1, dexSeen),
    .pokedexVar = VAR_NATIONAL_DEX - VARS_START,
    .pokedexFlag = FLAG_RECEIVED_POKEDEX_FROM_BIRCH,
    .mysteryEventFlag = FLAG_SYS_MYSTERY_EVENT_ENABLE,
    .pokedexCount = NATIONAL_DEX_COUNT,
    .unk1 = 0x07,
    .unk2 = 0x0a,
    .unk3 = 0x0a,
    .unk4 = 0x0a,
    .unk5 = 0x0c,
    .unk6 = 0x0c,
    .unk7 = 0x06,
    .unk8 = 0x0c,
    .unk9 = 0x06,
    .unk10 = 0x10,
    .unk11 = 0x12,
    .unk12 = 0x0c,
    .unk13 = 0x0f,
    .unk14 = 0x0b,
    .unk15 = 0x01,
    .unk16 = 0x08,
    .unk17 = 0x0c,
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
    .unk18 = 0x00000000,
    .baseStats = gBaseStats,
    .abilityNames = gAbilityNames,
    .abilityDescriptions = gAbilityDescriptionPointers,
    .items = gItems,
    .moves = gBattleMoves,
    .ballGfx = gBallSpriteSheets,
    .ballPalettes = gBallSpritePalettes,
    .gcnLinkFlagsOffset = offsetof(struct SaveBlock2, gcnLinkFlags),
    .gameClearFlag = FLAG_SYS_GAME_CLEAR,
    .ribbonFlag = FLAG_SYS_RIBBON_GET,
    .bagCountItems = BAG_ITEMS_COUNT,
    .bagCountKeyItems = BAG_KEYITEMS_COUNT,
    .bagCountPokeballs = BAG_POKEBALLS_COUNT,
    .bagCountTMHMs = BAG_TMHM_COUNT,
    .bagCountBerries = BAG_BERRIES_COUNT,
    .pcItemsCount = PC_ITEMS_COUNT,
    .pcItemsOffset = offsetof(struct SaveBlock1, pcItems),
    .giftRibbonsOffset = offsetof(struct SaveBlock1, giftRibbons),
    .enigmaBerryOffset = offsetof(struct SaveBlock1, enigmaBerry),
    .mapViewOffset = offsetof(struct SaveBlock1, mapView),
    .unk19 = 0x00000000,
    .unk20 = 0x00000000, // 0xFFFFFFFF in FRLG
};
