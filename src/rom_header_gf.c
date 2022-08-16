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
    u32 pokedexVar;
    u32 pokedexFlag;
    u32 mysteryEventFlag;
    u32 pokedexCount;
    u8 playerNameLength;
    u8 trainerNameLength;
    u8 pokemonNameLength1;
    u8 pokemonNameLength2;
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
    u32 enigmaBerrySize;
    const u8 * moveDescriptions;
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
    .seen1Offset = offsetof(struct SaveBlock1, seen1),
    .seen2Offset = offsetof(struct SaveBlock1, seen2),
    .pokedexVar = VAR_NATIONAL_DEX - VARS_START,
    .pokedexFlag = FLAG_RECEIVED_POKEDEX_FROM_BIRCH,
    .mysteryEventFlag = FLAG_SYS_MYSTERY_EVENT_ENABLE,
    .pokedexCount = NATIONAL_DEX_COUNT,
    .playerNameLength = PLAYER_NAME_LENGTH,
    .trainerNameLength = TRAINER_NAME_LENGTH,
    .pokemonNameLength1 = POKEMON_NAME_LENGTH,
    .pokemonNameLength2 = POKEMON_NAME_LENGTH,
    // Two of the below 12s are likely move/ability name length, given their presence in this header
    .unk5 = 12,
    .unk6 = 12,
    .unk7 = 6,
    .unk8 = 12,
    .unk9 = 6,
    .unk10 = 16,
    .unk11 = 18,
    .unk12 = 12,
    .unk13 = 15,
    .unk14 = 11,
    .unk15 = 1,
    .unk16 = 8,
    .unk17 = 12,
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
    .enigmaBerrySize = sizeof(struct EnigmaBerry),
    .moveDescriptions = NULL,
    .unk20 = 0x00000000, // 0xFFFFFFFF in FRLG
};
