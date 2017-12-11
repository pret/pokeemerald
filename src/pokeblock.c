#include "global.h"
#include "pokeblock.h"
#include "bg.h"
#include "strings.h"
#include "text.h"
#include "menu.h"
#include "task.h"
#include "menu_helpers.h"
#include "pokemon.h"
#include "graphics.h"

enum
{
    PKBL_USE_ON_FIELD,
    PKBL_TOSS,
    PKBL_CANCEL,
    PKBL_USE_IN_BATTLE,
    PKBL_USE_ON_FEEDER,
    PKBL_GIVE_TO_LADY
};

// this file's functions
void PokeblockAction_UseOnField(u8 taskId);
void PokeblockAction_Toss(u8 taskId);
void PokeblockAction_Cancel(u8 taskId);
void PokeblockAction_UseInBattle(u8 taskId);
void PokeblockAction_UseOnPokeblockFeeder(u8 taskId);
void PokeblockAction_GiveToContestLady(u8 taskId);
void TossPokeblockChoice_Yes(u8 taskId);
void TossPokeblockChoice_No(u8 taskId);

// const rom data
const s8 gPokeblockFlavorCompatibilityTable[] =
{
    // Cool, Beauty, Cute, Smart, Tough
          0,      0,    0,     0,     0, // Hardy
          1,      0,    0,     0,    -1, // Lonely
          1,      0,   -1,     0,     0, // Brave
          1,     -1,    0,     0,     0, // Adamant
          1,      0,    0,    -1,     0, // Naughty
         -1,      0,    0,     0,     1, // Bold
          0,      0,    0,     0,     0, // Docile
          0,      0,   -1,     0,     1, // Relaxed
          0,     -1,    0,     0,     1, // Impish
          0,      0,    0,    -1,     1, // Lax
         -1,      0,    1,     0,     0, // Timid
          0,      0,    1,     0,    -1, // Hasty
          0,      0,    0,     0,     0, // Serious
          0,     -1,    1,     0,     0, // Jolly
          0,      0,    1,    -1,     0, // Naive
         -1,      1,    0,     0,     0, // Modest
          0,      1,    0,     0,    -1, // Mild
          0,      1,   -1,     0,     0, // Quiet
          0,      0,    0,     0,     0, // Bashful
          0,      1,    0,    -1,     0, // Rash
         -1,      0,    0,     1,     0, // Calm
          0,      0,    0,     1,    -1, // Gentle
          0,      0,   -1,     1,     0, // Sassy
          0,     -1,    0,     1,     0, // Careful
          0,      0,    0,     0,     0  // Quirky
};

const struct BgTemplate gUnknown_085B2620[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }
};

const u8 *const gPokeblockNames[] =
{
    NULL,
    gText_RedPokeblock,
    gText_BluePokeblock,
    gText_PinkPokeblock,
    gText_GreenPokeblock,
    gText_YellowPokeblock,
    gText_PurplePokeblock,
    gText_IndigoPokeblock,
    gText_BrownPokeblock,
    gText_LiteBluePokeblock,
    gText_OlivePokeblock,
    gText_GrayPokeblock,
    gText_BlackPokeblock,
    gText_WhitePokeblock,
    gText_GoldPokeblock
};

const struct MenuAction sPokeblockMenuActions[] =
{
    {gMenuText_Use, PokeblockAction_UseOnField},
    {gMenuText_Toss, PokeblockAction_Toss},
    {gText_Cancel2, PokeblockAction_Cancel},
    {gMenuText_Use, PokeblockAction_UseInBattle},
    {gMenuText_Use, PokeblockAction_UseOnPokeblockFeeder},
    {gMenuText_Give2, PokeblockAction_GiveToContestLady},
};

const u8 sActionsOnField[] = {PKBL_USE_ON_FIELD, PKBL_TOSS, PKBL_CANCEL};
const u8 sActionsInBattle[] = {PKBL_USE_IN_BATTLE, PKBL_CANCEL};
const u8 sActionsOnPokeblockFeeder[] = {PKBL_USE_ON_FEEDER, PKBL_CANCEL};
const u8 sActionsWhenGivingToLady[] = {PKBL_GIVE_TO_LADY, PKBL_CANCEL};

const struct YesNoFuncTable sTossYesNoFuncTable = {TossPokeblockChoice_Yes, TossPokeblockChoice_No};

static const u8 sContestStatsMonData[] = {MON_DATA_COOL, MON_DATA_BEAUTY, MON_DATA_CUTE, MON_DATA_SMART, MON_DATA_TOUGH};

static const struct OamData sOamData_PokeblockCase =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_PokeblockCase[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_PokeblockCase[] =
{
    sSpriteAnim_PokeblockCase
};

static const union AffineAnimCmd gSpriteAffineAnim_85B26C8[] =
{
    AFFINEANIMCMD_FRAME(0, 0, -2,  2),
    AFFINEANIMCMD_FRAME(0, 0,  2,  4),
    AFFINEANIMCMD_FRAME(0, 0, -2,  4),
    AFFINEANIMCMD_FRAME(0, 0,  2,  2),
    AFFINEANIMCMD_END
};

const union AffineAnimCmd *const sSpriteAffineAnimTable_85B26F0[] =
{
    gSpriteAffineAnim_85B26C8
};

const struct CompressedSpriteSheet gPokeblockCase_SpriteSheet =
{
    gMenuPokeblockDevice_Gfx, 0x800, GFX_TAG_POKEBLOCK_CASE
};

const struct CompressedSpritePalette gPokeblockCase_SpritePal =
{
    gMenuPokeblockDevice_Pal, GFX_TAG_POKEBLOCK_CASE
};

const struct SpriteTemplate sSpriteTemplate_PokeblockCase =
{
    GFX_TAG_POKEBLOCK_CASE,
    GFX_TAG_POKEBLOCK_CASE,
    &sOamData_PokeblockCase,
    sSpriteAnimTable_PokeblockCase,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

const struct TextColor sTextColorInPokeblockMenu = {0, 2, 3};

const struct Pokeblock sFavoritePokeblocksTable[] =
{
    { PBLOCK_CLR_RED,    20,  0,  0,  0,  0, 20},
    { PBLOCK_CLR_BLUE,    0, 20,  0,  0,  0, 20},
    { PBLOCK_CLR_PINK,    0,  0, 20,  0,  0, 20},
    { PBLOCK_CLR_GREEN,   0,  0,  0, 20,  0, 20},
    { PBLOCK_CLR_YELLOW,  0,  0,  0,  0, 20, 20}
};
