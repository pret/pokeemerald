#include "global.h"
#include "bg.h"
#include "window.h"
#include "task.h"
#include "sprite.h"

// Static type declarations

// Static RAM declarations
IWRAM_DATA void *berry_blender_c_unused_03000de4;
IWRAM_DATA s16 gUnknown_03000DE8[8];
IWRAM_DATA s16 gUnknown_03000DF8[6];
IWRAM_DATA s16 gUnknown_03000E04;
IWRAM_DATA s16 gUnknown_03000E06;

// graphics
extern const u8 gBerryBlenderArrowTiles[];
extern const u8 gBerryBlenderStartTiles[];
extern const u8 gBerryBlenderMarubatsuTiles[];
extern const u8 gBerryBlenderParticlesTiles[];
extern const u8 gBerryBlenderCountdownNumbersTiles[];
extern const u16 gBerryBlenderMiscPalette[];
extern const u16 gBerryBlenderArrowPalette[];

void sub_8080EA4(u8 taskId);
void sub_8080FD0(u8 taskId);
void sub_80810F8(u8 taskId);
void sub_80833F8(struct Sprite *sprite);
void sub_8082F68(struct Sprite *sprite);
void sub_8083010(struct Sprite *sprite);
void sub_80830C0(struct Sprite *sprite);

// .rodata
// TODO: make those static once the file is decompiled
const u16 sBlenderCenterPal[] = INCBIN_U16("graphics/berry_blender/center.gbapal");
const u8 sBlenderCenterMap[] = INCBIN_U8("graphics/berry_blender/center_map.bin");
const u16 sBlenderOuterPal[] = INCBIN_U16("graphics/berry_blender/outer.gbapal");

// unreferenced pals?
static const u16 sUnknownPal_0[] = INCBIN_U16("graphics/unknown/unknown_339514.gbapal");
static const u16 sUnknownArray_1[224] = {0};

// unused text?
static const u8 sUnusedText_YesNo[] = _("YES\nNO");
static const u8 sUnusedText_2[] = _("▶");
static const u8 sUnusedText_Space[] = _(" ");
static const u8 sUnusedText_Terminating[] = _("Terminating.");
static const u8 sUnusedText_LinkPartnerNotFound[] = _("Link partner(s) not found.\nPlease try again.\p");

const u8 gText_BerryBlenderStart[] = _("Starting up the BERRY BLENDER.\pPlease select a BERRY from your BAG\nto put in the BERRY BLENDER.\p");
const u8 gText_NewParagraph[] = _("\p");
const u8 gText_WasMade[] = _(" was made!");
static const u8 sText_Mister[] = _("MISTER");
static const u8 sText_Laddie[] = _("LADDIE");
static const u8 sText_Lassie[] = _("LASSIE");
static const u8 sText_Master[] = _("MASTER");
static const u8 sText_Dude[] = _("DUDE");
static const u8 sText_Miss[] = _("MISS");

const u8* const sBlenderOpponentsNames[] =
{
    sText_Mister,
    sText_Laddie,
    sText_Lassie,
    sText_Master,
    sText_Dude,
    sText_Miss
};

static const u8 sText_PressAToStart[] = _("Press the A Button to start.");
static const u8 sText_PleaseWaitAWhile[] = _("Please wait a while.");
const u8 sText_CommunicationStandby[] = _("Communication standby…");
const u8 sText_WouldLikeToBlendAnotherBerry[] = _("Would you like to blend another BERRY?");
const u8 sText_RunOutOfBerriesForBlending[] = _("You’ve run out of BERRIES for\nblending in the BERRY BLENDER.\p");
const u8 sText_YourPokeblockCaseIsFull[] = _("Your {POKEBLOCK} CASE is full.\p");
const u8 sText_HasNoBerriesToPut[] = _(" has no BERRIES to put in\nthe BERRY BLENDER.");
const u8 ApostropheSPokeblockCaseIsFull[] = _("’s {POKEBLOCK} CASE is full.\p");
const u8 sText_BlendingResults[] = _("RESULTS OF BLENDING");
static const u8 sText_BerryUsed[] = _("BERRY USED");
const u8 sText_SpaceBerry[] = _(" BERRY");
const u8 sText_Time[] = _("Time:");
const u8 sText_Min[] = _(" min. ");
const u8 sText_Sec[] = _(" sec.");
const u8 sText_MaximumSpeed[] = _("MAXIMUM SPEED");
const u8 sText_RPM[] = _(" RPM");
const u8 sText_Dot[] = _(".");
const u8 sText_NewLine[] = _("\n");
static const u8 sText_Space[] = _(" ");
const u8 sText_Ranking[] = _("RANKING");
const u8 sText_TheLevelIs[] = _("The level is ");
const u8 sText_TheFeelIs[] = _(", and the feel is ");
const u8 sText_Dot2[] = _(".");

const struct BgTemplate gUnknown_08339974[3] =
{
    {
        .bg = 0,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 8,
        .screenSize = 1,
        .paletteMode = 1,
        .priority = 0,
        .baseTile = 0,
    }
};

const struct WindowTemplate gUnknown_08339980[] =
{
    {0, 1, 6, 7, 2, 0xE, 0x28},
    {0, 0x16, 6, 7, 2, 0xE, 0x36},
    {0, 1, 0xC, 7, 2, 0xE, 0x44},
    {0, 0x16, 0xC, 7, 2, 0xE, 0x52},
    {0, 2, 0xF, 0x1B, 4, 0xE, 0x60},
    {0, 5, 3, 0x15, 0xE, 0xE, 0x60},
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gUnknown_083399B8 =
{
    0, 0x15, 9, 5, 4, 0xE, 0xCC
};

const s8 gUnknown_083399C0[][2] =
{
    {-1, -1}, {1, -1}, {-1, 1}, {1, 1}
};

const u8 sBlenderSyncArrowsPos[][2] =
{
    {72, 32}, {168, 32}, {72, 128}, {168, 128}
};

const u8 gUnknown_083399D0[3][4] =
{
    {-1, 0, 1, -1}, {-1, 0, 1, 2}, {0, 1, 2, 3}
};

const u16 gUnknown_083399DC[] = {0, 0xC000, 0x4000, 0x8000};
const u8 gUnknown_083399E4[] = {1, 1, 0};
const u8 gUnknown_083399E7[] = {32, 224, 96, 160, 0};

const TaskFunc gUnknown_083399EC[] =
{
    sub_8080EA4, sub_8080FD0, sub_80810F8
};

static const struct OamData sOamData_8216314 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_821631C[] =
{
    ANIMCMD_FRAME(16, 5, 1, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216324[] =
{
    ANIMCMD_FRAME(16, 5, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821632C[] =
{
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216334[] =
{
    ANIMCMD_FRAME(16, 5, 0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821633C[] =
{
    ANIMCMD_FRAME(48, 2, 1, 1),
    ANIMCMD_FRAME(32, 5, 1, 1),
    ANIMCMD_FRAME(48, 3, 1, 1),
    ANIMCMD_FRAME(16, 5, 1, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216350[] =
{
    ANIMCMD_FRAME(48, 2, .vFlip = TRUE),
    ANIMCMD_FRAME(32, 5, .vFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .vFlip = TRUE),
    ANIMCMD_FRAME(16, 5, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216364[] =
{
    ANIMCMD_FRAME(48, 2, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 5, .hFlip = TRUE),
    ANIMCMD_FRAME(48, 3, .hFlip = TRUE),
    ANIMCMD_FRAME(16, 5, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216378[] =
{
    ANIMCMD_FRAME(48, 2, 0, 0),
    ANIMCMD_FRAME(32, 5, 0, 0),
    ANIMCMD_FRAME(48, 3, 0, 0),
    ANIMCMD_FRAME(16, 5, 0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821638C[] =
{
    ANIMCMD_FRAME(0, 5, 1, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216394[] =
{
    ANIMCMD_FRAME(0, 5, .vFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821639C[] =
{
    ANIMCMD_FRAME(0, 5, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82163A4[] =
{
    ANIMCMD_FRAME(0, 5, 0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_82163AC[] =
{
    sSpriteAnim_821631C,
    sSpriteAnim_8216324,
    sSpriteAnim_821632C,
    sSpriteAnim_8216334,
    sSpriteAnim_821633C,
    sSpriteAnim_8216350,
    sSpriteAnim_8216364,
    sSpriteAnim_8216378,
    sSpriteAnim_821638C,
    sSpriteAnim_8216394,
    sSpriteAnim_821639C,
    sSpriteAnim_82163A4
};

const struct SpriteSheet sSpriteSheet_BlenderArrow =
{
    gBerryBlenderArrowTiles, 0x800, 46545
};

const struct SpritePalette sSpritePal_BlenderMisc =
{
    gBerryBlenderMiscPalette, 46546
};

const struct SpritePalette sSpritePal_BlenderArrow =
{
    gBerryBlenderArrowPalette, 12312
};

const struct SpriteTemplate sBlenderSyncArrow_SpriteTemplate =
{
    .tileTag = 46545,
    .paletteTag = 12312,
    .oam = &sOamData_8216314,
    .anims = sSpriteAnimTable_82163AC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80833F8
};

static const struct OamData sOamData_821640C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_8216414[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821641C[] =
{
    ANIMCMD_FRAME(4, 20, 1, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216424[] =
{
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821643C[] =
{
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8216444[] =
{
    sSpriteAnim_8216414,
    sSpriteAnim_821641C,
    sSpriteAnim_8216424,
    sSpriteAnim_821643C,
};

const struct SpriteSheet gUnknown_08339B38 =
{
    gBerryBlenderMarubatsuTiles, 0x200, 48888
};

const struct SpriteTemplate gUnknown_08339B40 =
{
    .tileTag = 48888,
    .paletteTag = 46546,
    .oam = &sOamData_821640C,
    .anims = sSpriteAnimTable_8216444,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8082F68
};

static const struct OamData sOamData_8216474 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_821647C[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216494[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(2, 4),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82164AC[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(3, 3),
    ANIMCMD_FRAME(2, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82164D0[] =
{
    ANIMCMD_FRAME(5, 5, 1, 1),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_82164D8[] =
{
    ANIMCMD_FRAME(6, 5, 1, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_82164E0[] =
{
    sSpriteAnim_821647C,
    sSpriteAnim_8216494,
    sSpriteAnim_82164AC,
    sSpriteAnim_82164D0,
    sSpriteAnim_82164D8,
};

const struct SpriteSheet gUnknown_08339BD8 =
{
    gBerryBlenderParticlesTiles, 0xE0, 23456
};

const struct SpriteTemplate gUnknown_08339BE0 =
{
    .tileTag = 23456,
    .paletteTag = 46546,
    .oam = &sOamData_8216474,
    .anims = sSpriteAnimTable_82164E0,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOamData_8216514 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_821651C[] =
{
    ANIMCMD_FRAME(32, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_8216524[] =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_821652C[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8216534[] =
{
    sSpriteAnim_821651C,
    sSpriteAnim_8216524,
    sSpriteAnim_821652C,
};

const struct SpriteSheet gUnknown_08339C24 =
{
    gBerryBlenderCountdownNumbersTiles, 0x600, 12345
};

const struct SpriteTemplate gUnknown_08339C2C =
{
    .tileTag = 12345,
    .paletteTag = 46546,
    .oam = &sOamData_8216514,
    .anims = sSpriteAnimTable_8216534,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8083010
};

static const struct OamData sOamData_8216560 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 3,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_8216568[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_8216570[] =
{
    sSpriteAnim_8216568,
};

const struct SpriteSheet gUnknown_08339C58 =
{
    gBerryBlenderStartTiles, 0x400, 12346
};

const struct SpriteTemplate gUnknown_08339C60 =
{
    .tileTag = 12346,
    .paletteTag = 46546,
    .oam = &sOamData_8216560,
    .anims = sSpriteAnimTable_8216570,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_80830C0
};

const s16 gUnknown_08339C78[][5] =
{
    {-10,  20,  10,   2,   1},
    {250,  20,  10,  -2,   1},
    {-10, 140,  10,   2,  -1},
    {250, 140,  10,  -2,  -1},
};

const u8 gUnknown_08339CA0[][3] =
{
    {4, 3, 2}, {0, 4, 3}, {1, 0, 4}, {2, 1, 0}, {3, 2, 1}, {0, 2, 3}, {1, 3, 4}, {2, 4, 0}, {3, 0, 1}, {4, 1, 2},
};

const u8 gUnknown_08339CBE[] = {30, 31, 32, 33, 34};

const u8 gUnknown_08339CC3[] = {1, 1, 2, 3, 4};

const u8 gUnknown_08339CC8[] = {0x1C, 0x16, 0x13, 0x1A, 0x19, 0x0E, 0x0D, 0x0B, 0x07, 0x15};

static const u8 gUnknown_08339CD2[] =
{
    0xfe, 0x02, 0x02, 0xce, 0xd0, 0x37, 0x44, 0x07, 0x1f, 0x0c, 0x10,
    0x00, 0xff, 0xfe, 0x91, 0x72, 0xce, 0xd0, 0x37, 0x44, 0x07, 0x1f,
    0x0c, 0x10, 0x00, 0xff, 0x06, 0x27, 0x02, 0xff, 0x00, 0x0c, 0x48,
    0x02, 0xff, 0x00, 0x01, 0x1f, 0x02, 0xff, 0x00, 0x16, 0x37, 0x02,
    0xff, 0x00, 0x0d, 0x50, 0x4b, 0x02, 0xff, 0x06, 0x06, 0x06, 0x06,
    0x05, 0x03, 0x03, 0x03, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02
};

const struct WindowTemplate gUnknown_08339D14[] = {0, 6, 4, 0x12, 0xB, 0xF, 8};

// .text
