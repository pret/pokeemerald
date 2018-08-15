#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_frontier_2.h"
#include "battle_message.h"
#include "battle_tent.h"
#include "bg.h"
#include "contest.h"
#include "contest_effect.h"
#include "data2.h"
#include "daycare.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "m4a.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "mon_markings.h"
#include "party_menu.h"
#include "palette.h"
#include "pokeball.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "region_map.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "window.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/species.h"

static EWRAM_DATA struct UnkSummaryStruct
{
    /*0x00*/ union {
        struct Pokemon *mons;
        struct BoxPokemon *boxMons;
    } monList;
    /*0x04*/ MainCallback callback;
    /*0x08*/ struct Sprite *markingsSprite;
    /*0x0C*/ struct Pokemon currentMon;
    /*0x70*/ struct PokeSummary
    {
        u16 species; // 0x0
        u16 species2; // 0x2
        u8 isEgg; // 0x4
        u8 level; // 0x5
        u8 ribbonCount; // 0x6
        u8 unk7; // 0x7
        u8 altAbility; // 0x8
        u8 metLocation; // 0x9
        u8 metLevel; // 0xA
        u8 metGame; // 0xB
        u32 pid; // 0xC
        u32 exp; // 0x10
        u16 moves[4]; // 0x14
        u8 pp[4]; // 0x1C
        u16 currentHP; // 0x20
        u16 maxHP; // 0x22
        u16 atk; // 0x24
        u16 def; // 0x26
        u16 spatk; // 0x28
        u16 spdef; // 0x2A
        u16 speed; // 0x2C
        u16 item; // 0x2E
        u16 friendship; // 0x30
        u8 OTGender; // 0x32
        u8 nature; // 0x33
        u8 ppBonuses; // 0x34
        u8 sanity; // 0x35
        u8 OTName[8]; // 0x36
        u8 unk3E[9]; // 0x3E
        u32 OTID; // 0x48
    } summary;
    u16 bgTilemapBuffers[4][2][0x400];
    u8 mode;
    bool8 isBoxMon;
    u8 curMonIndex;
    u8 maxMonIndex;
    u8 currPageIndex;
    u8 minPageIndex;
    u8 maxPageIndex;
    bool8 unk40C3;
    u16 newMove;
    u8 firstMoveIndex;
    u8 secondMoveIndex;
    bool8 unk40C8;
    u8 unk40C9;
    u8 filler40CA;
    u8 windowIds[8];
    u8 spriteIds[28];
    bool8 unk40EF;
    s16 unk40F0;
    u8 unk_filler4[6];
} *gUnknown_0203CF1C = NULL;
EWRAM_DATA u8 gUnknown_0203CF20 = 0;
static EWRAM_DATA u8 gUnknown_0203CF21 = 0;
static EWRAM_DATA u8 gFiller_0203CF22[2] = {0};
static EWRAM_DATA u8 sUnknownTaskId = 0;
static EWRAM_DATA u8 gFiller_0203CF25[3] = {0};

extern const struct CompressedSpriteSheet gMonFrontPicTable[];

struct UnkStruct_61CC04
{
    const u16 *ptr;
    u16 field_4;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
};

// forward declarations
bool8 sub_81B1250(void);
static bool8 SummaryScreen_LoadGraphics(void);
static void SummaryScreen_LoadingCB2(void);
static void InitBGs(void);
u8 sub_81BFEB0(void);
void CopyMonToSummaryStruct(struct Pokemon* a);
bool8 ExtractMonDataToSummaryStruct(struct Pokemon* a);
void sub_81C0348(void);
void sub_81C0484(u8 taskId);
void sub_81C0510(u8 taskId);
void sub_81C0604(u8 taskId, s8 a);
void sub_81C0704(u8 taskId);
s8 sub_81C08F8(s8 a);
s8 sub_81C09B4(s8 a);
bool8 sub_81C0A50(struct Pokemon* mon);
void sub_81C0A8C(u8 taskId, s8 a);
void sub_81C0B8C(u8 taskId);
void sub_81C0C68(u8 taskId);
void sub_81C0CC4(u8 taskId);
void sub_81C0D44(u8 taskId);
void sub_81C0E24(void);
void sub_81C0E48(u8 taskId);
void sub_81C0F44(u8 taskId);
bool8 sub_81C1040(void);
void sub_81C1070(s16* a, s8 b, u8* c);
void sub_81C11F4(u8 a);
void sub_81C129C(u8 a);
void sub_81C12E4(u8 taskId);
void sub_81C13B0(u8 taskId, bool8 b);
void sub_81C14BC(struct Pokemon *mon, u8 a, u8 b);
void sub_81C15EC(struct BoxPokemon *mon, u8 a, u8 b);
void sub_81C171C(u8 taskId);
void sub_81C174C(u8 taskId);
bool8 sub_81C18A8(void);
void sub_81C18F4(u8 a);
void sub_81C1940(u8 taskId);
void sub_81C1BA0(void);
void sub_81C1DA4(u16 a, s16 b);
void sub_81C1E20(u8 taskId);
void sub_81C1EFC(u16 a, s16 b, u16 c);
void sub_81C1F80(u8 taskId);
void sub_81C2074(u16 a, s16 b);
void sub_81C20F0(u8 taskId);
void sub_81C2194(u16 *a, u16 b, u8 c);
void sub_81C2228(struct Pokemon* mon);
void sub_81C22CC(struct Pokemon* mon);
void sub_81C240C(u16 a);
void sub_81C2524(void);
void sub_81C2554(void);
void sub_81C25E8(void);
void sub_81C2628(void);
void sub_81C2794(void);
void sub_81C27DC(struct Pokemon *mon, u16 a);
static void PrintPageNamesAndStatsPage(void);
void sub_81C2AFC(u8 a);
void sub_81C2C38(u8 a);
void SummaryScreen_RemoveWindowByIndex(u8 a);
void sub_81C2D9C(u8 a);
void sub_81C2DE4(u8 a);
void sub_81C2E00(void);
void sub_81C2E40(u8 taskId);
void PrintMonOTName(void);
void PrintMonOTID(void);
void PrintMonAbilityName(void);
void PrintMonAbilityDescription(void);
void BufferMonTrainerMemo(void);
void PrintMonTrainerMemo(void);
void BufferNatureString(void);
void GetMetLevelString(u8 *a);
bool8 DoesMonOTMatchOwner(void);
bool8 MonCameFromGBAGames(void);
bool8 IsInGamePartnerMon(void);
void PrintEggOTName(void);
void PrintEggOTID(void);
void PrintEggState(void);
void PrintEggMemo(void);
void sub_81C3554(u8 taskId);
void PrintHeldItemName(void);
void sub_81C3530(void);
void PrintRibbonCount(void);
void BufferLeftColumnStats(void);
void PrintLeftColumnStats(void);
void BufferRightColumnStats(void);
void PrintRightColumnStats(void);
void PrintExpPointsNextLevel(void);
void sub_81C3984(void);
void sub_81C39F0(u8 taskId);
void PrintMoveNameAndPP(u8 a);
void sub_81C3D08(void);
void sub_81C3D54(u8 taskId);
void PrintContestMoveDescription(u8 a);
void PrintMoveDetails(u16 a);
void PrintNewMoveDetailsOrCancelText(void);
void sub_81C4064(void);
void sub_81C40A0(u8 a, u8 b);
void sub_81C4154(void);
void sub_81C4190(void);
void sub_81C4204(u8 a, u8 b);
void sub_81C424C(void);
void sub_81C4280(void);
void sub_81C42C8(void);
void sub_81C43A0(void);
void sub_81C4420(void);
void sub_81C4484(void);
void sub_81C44F0(void);
void sub_81C4568(u8 a, u8 b);
u8 sub_81C45F4(struct Pokemon *a, s16 *b);
u8 sub_81C47B4(struct Pokemon *unused);
void sub_81C4844(struct Sprite *);
void SummaryScreen_SetUnknownTaskId(u8 a);
void SummaryScreen_DestroyUnknownTask(void);
void sub_81C48F0(void);
void CreateMonMarkingsSprite(struct Pokemon *mon);
void RemoveAndCreateMonMarkingsSprite(struct Pokemon *mon);
void CreateCaughtBallSprite(struct Pokemon *mon);
void CreateSetStatusSprite(void);
void sub_81C4AF8(u8 a);
void sub_81C4BE4(struct Sprite *sprite);
void sub_81C4C60(u8 a);
void sub_81C4C84(u8 a);
void sub_81C4D18(u8 a);

// const rom data
#include "data/text/move_descriptions.h"
#include "data/text/nature_names.h"

static const struct BgTemplate gUnknown_0861CBB4[] = 
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 25,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

static const u16 gUnknown_0861CBC4[] = INCBIN_U16("graphics/interface/unk_tilemap2.bin");
static const struct UnkStruct_61CC04 gUnknown_0861CBEC =
{
    gUnknown_0861CBC4, 1, 10, 2, 0, 18
};
static const struct UnkStruct_61CC04 gUnknown_0861CBF8 =
{
    gUnknown_0861CBC4, 1, 10, 2, 0, 50
};
static const struct UnkStruct_61CC04 gUnknown_0861CC04 =
{
    gSummaryScreenPowAcc_Tilemap, 0, 10, 7, 0, 45
};
static const struct UnkStruct_61CC04 gUnknown_0861CC10 =
{
    gUnknown_08DC3C34, 0, 10, 7, 0, 45
};
static const s8 gUnknown_0861CC1C[] = {0, 2, 3, 1, 4, 5};
static const struct WindowTemplate gUnknown_0861CC24[] =
{
    { 0x00, 0x00, 0x00, 0x0b, 0x02, 0x06, 0x0001 },
    { 0x00, 0x00, 0x00, 0x0b, 0x02, 0x06, 0x0017 },
    { 0x00, 0x00, 0x00, 0x0b, 0x02, 0x06, 0x002d },
    { 0x00, 0x00, 0x00, 0x0b, 0x02, 0x06, 0x0043 },
    { 0x00, 0x16, 0x00, 0x08, 0x02, 0x07, 0x0059 },
    { 0x00, 0x16, 0x00, 0x08, 0x02, 0x07, 0x0069 },
    { 0x00, 0x16, 0x00, 0x08, 0x02, 0x07, 0x0079 },
    { 0x00, 0x0b, 0x04, 0x00, 0x02, 0x06, 0x0089 },
    { 0x00, 0x0b, 0x04, 0x12, 0x02, 0x06, 0x0089 },
    { 0x00, 0x0b, 0x06, 0x12, 0x02, 0x06, 0x00ad },
    { 0x00, 0x0a, 0x07, 0x06, 0x06, 0x06, 0x00d1 },
    { 0x00, 0x16, 0x07, 0x05, 0x06, 0x06, 0x00f5 },
    { 0x00, 0x0a, 0x0e, 0x0b, 0x04, 0x06, 0x0113 },
    { 0x00, 0x00, 0x12, 0x06, 0x02, 0x06, 0x013f },
    { 0x00, 0x01, 0x0f, 0x09, 0x04, 0x06, 0x014b },
    { 0x00, 0x01, 0x0f, 0x05, 0x04, 0x06, 0x016f },
    { 0x00, 0x16, 0x04, 0x00, 0x02, 0x06, 0x0183 },
    { 0x00, 0x01, 0x02, 0x04, 0x02, 0x07, 0x0183 },
    { 0x00, 0x01, 0x0c, 0x09, 0x02, 0x06, 0x018b },
    { 0x00, 0x01, 0x0e, 0x09, 0x04, 0x06, 0x019d },
    DUMMY_WIN_TEMPLATE
};
static const struct WindowTemplate gUnknown_0861CCCC[] =
{
    { 0x00, 0x0b, 0x04, 0x0b, 0x02, 0x06, 0x01c1 },
    { 0x00, 0x16, 0x04, 0x07, 0x02, 0x06, 0x01d7 },
    { 0x00, 0x0b, 0x09, 0x12, 0x04, 0x06, 0x01e5 },
    { 0x00, 0x0b, 0x0e, 0x12, 0x06, 0x06, 0x022d },
};
static const struct WindowTemplate gUnknown_0861CCEC[] =
{
    { 0x00, 0x0a, 0x04, 0x0a, 0x02, 0x06, 0x01c1 },
    { 0x00, 0x14, 0x04, 0x0a, 0x02, 0x06, 0x01d5 },
    { 0x00, 0x10, 0x07, 0x06, 0x06, 0x06, 0x01e9 },
    { 0x00, 0x1b, 0x07, 0x03, 0x06, 0x06, 0x020d },
    { 0x00, 0x18, 0x0e, 0x06, 0x04, 0x06, 0x021f },
};
static const struct WindowTemplate gUnknown_0861CD14[] =
{
    { 0x00, 0x0f, 0x04, 0x09, 0x0a, 0x06, 0x01c1 },
    { 0x00, 0x18, 0x04, 0x06, 0x0a, 0x08, 0x021b },
    { 0x00, 0x0a, 0x0f, 0x14, 0x04, 0x06, 0x0257 },
};
static const u8 sTextColors_861CD2C[][3] =
{
    {0, 1, 2},
    {0, 3, 4},
    {0, 5, 6},
    {0, 7, 8},
    {0, 9, 10},
    {0, 11, 12},
    {0, 13, 14},
    {0, 7, 8},
    {13, 15, 14},
    {0, 1, 2},
    {0, 3, 4},
    {0, 5, 6},
    {0, 7, 8}
};
static const u8 gUnknown_0861CD53[] = INCBIN_U8("graphics/interface/summary_a_button.4bpp");
static const u8 gUnknown_0861CDD3[] = INCBIN_U8("graphics/interface/summary_b_button.4bpp");
static void (*const gUnknown_0861CE54[])(void) =
{
    sub_81C2E00,
    sub_81C3530,
    sub_81C3984,
    sub_81C3D08
};
static void (*const gUnknown_0861CE64[])(u8 taskId) =
{
    sub_81C2E40,
    sub_81C3554,
    sub_81C39F0,
    sub_81C3D54
};
static const u8 gUnknown_0861CE74[] = _("{COLOR LIGHT_RED}{SHADOW GREEN}");
static const u8 gUnknown_0861CE7B[] = _("{COLOR WHITE}{SHADOW DARK_GREY}");
static const u8 gUnknown_0861CE82[] = _("{SPECIAL_F7 0x00}/{SPECIAL_F7 0x01}\n{SPECIAL_F7 0x02}\n{SPECIAL_F7 0x03}");
static const u8 gUnknown_0861CE8E[] = _("{SPECIAL_F7 0x00}\n{SPECIAL_F7 0x01}\n{SPECIAL_F7 0x02}");
static const u8 gUnknown_0861CE97[] = _("{PP}{SPECIAL_F7 0x00}/{SPECIAL_F7 0x01}");
static const struct OamData gOamData_861CEA0 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_861CEA8[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CEB0[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CEB8[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CEC0[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CEC8[] = {
    ANIMCMD_FRAME(32, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CED0[] = {
    ANIMCMD_FRAME(40, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CED8[] = {
    ANIMCMD_FRAME(48, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CEE0[] = {
    ANIMCMD_FRAME(56, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CEE8[] = {
    ANIMCMD_FRAME(64, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CEF0[] = {
    ANIMCMD_FRAME(72, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CEF8[] = {
    ANIMCMD_FRAME(80, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF00[] = {
    ANIMCMD_FRAME(88, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF08[] = {
    ANIMCMD_FRAME(96, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF10[] = {
    ANIMCMD_FRAME(104, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF18[] = {
    ANIMCMD_FRAME(112, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF20[] = {
    ANIMCMD_FRAME(120, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF28[] = {
    ANIMCMD_FRAME(128, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF30[] = {
    ANIMCMD_FRAME(136, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF38[] = {
    ANIMCMD_FRAME(144, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF40[] = {
    ANIMCMD_FRAME(152, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF48[] = {
    ANIMCMD_FRAME(160, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF50[] = {
    ANIMCMD_FRAME(168, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861CF58[] = {
    ANIMCMD_FRAME(176, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const gSpriteAnimTable_861CF60[] = {
    gSpriteAnim_861CEA8,
    gSpriteAnim_861CEB0,
    gSpriteAnim_861CEB8,
    gSpriteAnim_861CEC0,
    gSpriteAnim_861CEC8,
    gSpriteAnim_861CED0,
    gSpriteAnim_861CED8,
    gSpriteAnim_861CEE0,
    gSpriteAnim_861CEE8,
    gSpriteAnim_861CEF0,
    gSpriteAnim_861CEF8,
    gSpriteAnim_861CF00,
    gSpriteAnim_861CF08,
    gSpriteAnim_861CF10,
    gSpriteAnim_861CF18,
    gSpriteAnim_861CF20,
    gSpriteAnim_861CF28,
    gSpriteAnim_861CF30,
    gSpriteAnim_861CF38,
    gSpriteAnim_861CF40,
    gSpriteAnim_861CF48,
    gSpriteAnim_861CF50,
    gSpriteAnim_861CF58,
};
static const struct CompressedSpriteSheet gUnknown_0861CFBC = 
{
    .data = gMoveTypes_Gfx,
    .size = 0x1700,
    .tag = 30002
};
static const struct SpriteTemplate gUnknown_0861CFC4 = 
{
    .tileTag = 30002,
    .paletteTag = 30002,
    .oam = &gOamData_861CEA0,
    .anims = gSpriteAnimTable_861CF60,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const u8 gUnknown_0861CFDC[] = {13, 13, 14, 14, 13, 13, 15, 14, 13, 15, 13, 14, 15, 13, 14, 14, 15, 13, 13, 14, 14, 15, 13};
static const struct OamData gOamData_861CFF4 =
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
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_861CFFC[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D004[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D00C[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D014[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D01C[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D024[] = {
    ANIMCMD_FRAME(16, 0, TRUE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D02C[] = {
    ANIMCMD_FRAME(20, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D034[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D03C[] = {
    ANIMCMD_FRAME(24, 0, TRUE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D044[] = {
    ANIMCMD_FRAME(28, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const gSpriteAnimTable_861D04C[] = {
    gSpriteAnim_861CFFC,
    gSpriteAnim_861D004,
    gSpriteAnim_861D00C,
    gSpriteAnim_861D014,
    gSpriteAnim_861D01C,
    gSpriteAnim_861D024,
    gSpriteAnim_861D02C,
    gSpriteAnim_861D034,
    gSpriteAnim_861D03C,
    gSpriteAnim_861D044,
};
static const struct CompressedSpriteSheet gUnknown_0861D074 =
{
    .data = gUnknown_08D97BEC,
    .size = 0x400,
    .tag = 30000
};
static const struct CompressedSpritePalette gUnknown_0861D07C =
{
    .data = gUnknown_08D97CF4,
    .tag = 30000
};
static const struct SpriteTemplate gUnknown_0861D084 = 
{
    .tileTag = 30000,
    .paletteTag = 30000,
    .oam = &gOamData_861CFF4,
    .anims = gSpriteAnimTable_861D04C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const struct OamData gOamData_861D09C =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 1,
    .x = 0,
    .matrixNum = 0,
    .size = 1,
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd gSpriteAnim_861D0A4[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D0AC[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D0B4[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D0BC[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D0C4[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D0CC[] = {
    ANIMCMD_FRAME(20, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd gSpriteAnim_861D0D4[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const gSpriteAnimTable_861D0DC[] = {
    gSpriteAnim_861D0A4,
    gSpriteAnim_861D0AC,
    gSpriteAnim_861D0B4,
    gSpriteAnim_861D0BC,
    gSpriteAnim_861D0C4,
    gSpriteAnim_861D0CC,
    gSpriteAnim_861D0D4,
};
static const struct CompressedSpriteSheet gUnknown_0861D0F8 =
{
    .data = gStatusGfx_Icons,
    .size = 0x380,
    .tag = 30001
};
static const struct CompressedSpritePalette gUnknown_0861D100 =
{
    .data = gStatusPal_Icons,
    .tag = 30001
};
static const struct SpriteTemplate gUnknown_0861D108 = 
{
    .tileTag = 30001,
    .paletteTag = 30001,
    .oam = &gOamData_861D09C,
    .anims = gSpriteAnimTable_861D0DC,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const u16 gUnknown_0861D120[] = INCBIN_U16("graphics/interface/summary_markings.gbapal");

// code
void ShowPokemonSummaryScreen(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    gUnknown_0203CF1C = AllocZeroed(sizeof(*gUnknown_0203CF1C));
    gUnknown_0203CF1C->mode = mode;
    gUnknown_0203CF1C->monList.mons = mons;
    gUnknown_0203CF1C->curMonIndex = monIndex;
    gUnknown_0203CF1C->maxMonIndex = maxMonIndex;
    gUnknown_0203CF1C->callback = callback;

    if (mode == PSS_MODE_UNK2)
        gUnknown_0203CF1C->isBoxMon = TRUE;
    else
        gUnknown_0203CF1C->isBoxMon = FALSE;
    
    switch (mode)
    {
    case PSS_MODE_NORMAL:
    case PSS_MODE_UNK2:
        gUnknown_0203CF1C->minPageIndex = 0;
        gUnknown_0203CF1C->maxPageIndex = 3;
        break;
    case PSS_MODE_UNK1:
        gUnknown_0203CF1C->minPageIndex = 0;
        gUnknown_0203CF1C->maxPageIndex = 3;
        gUnknown_0203CF1C->unk40C8 = TRUE;
        break;
    case PSS_MODE_SELECT_MOVE:
        gUnknown_0203CF1C->minPageIndex = 2;
        gUnknown_0203CF1C->maxPageIndex = 3;
        gUnknown_0203CF1C->unk40C3 = TRUE;
        break;
    }

    gUnknown_0203CF1C->currPageIndex = gUnknown_0203CF1C->minPageIndex;
    SummaryScreen_SetUnknownTaskId(-1);

    if (gMonSpritesGfxPtr == 0)
        sub_806F2AC(0, 0);
    
    SetMainCallback2(SummaryScreen_LoadingCB2);
}

void ShowSelectMovePokemonSummaryScreen(struct Pokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void), u16 newMove)
{
    ShowPokemonSummaryScreen(PSS_MODE_SELECT_MOVE, mons, monIndex, maxMonIndex, callback);
    gUnknown_0203CF1C->newMove = newMove;
}

void ShowPokemonSummaryScreenSet40EF(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    ShowPokemonSummaryScreen(mode, mons, monIndex, maxMonIndex, callback);
    gUnknown_0203CF1C->unk40EF = TRUE;
}

static void SummaryScreen_MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

static void SummaryScreen_VBlank(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void SummaryScreen_LoadingCB2(void)
{
    while (sub_81221EC() != TRUE && SummaryScreen_LoadGraphics() != TRUE && sub_81221AC() != TRUE);
}

static bool8 SummaryScreen_LoadGraphics(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        clear_scheduled_bg_copies_to_vram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = 1;
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        gMain.state++;
        break;
    case 4:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 5:
        InitBGs();
        gUnknown_0203CF1C->unk40F0 = 0;
        gMain.state++;
        break;
    case 6:
        if (sub_81BFEB0() != FALSE)
            gMain.state++;
        break;
    case 7:
        sub_81C2554();
        gMain.state++;
        break;
    case 8:
        sub_81C1BA0();
        gMain.state++;
        break;
    case 9:
        CopyMonToSummaryStruct(&gUnknown_0203CF1C->currentMon);
        gUnknown_0203CF1C->unk40F0 = 0;
        gMain.state++;
        break;
    case 10:
        if (ExtractMonDataToSummaryStruct(&gUnknown_0203CF1C->currentMon) != 0)
            gMain.state++;
        break;
    case 11:
        sub_81C25E8();
        gMain.state++;
        break;
    case 12:
        PrintPageNamesAndStatsPage();
        gMain.state++;
        break;
    case 13:
        sub_81C2D9C(gUnknown_0203CF1C->currPageIndex);
        gMain.state++;
        break;
    case 14:
        sub_81C0348();
        gMain.state++;
        break;
    case 15:
        sub_81C2AFC(gUnknown_0203CF1C->currPageIndex);
        gMain.state++;
        break;
    case 16:
        sub_81C4190();
        sub_81C42C8();
        gUnknown_0203CF1C->unk40F0 = 0;
        gMain.state++;
        break;
    case 17:
        gUnknown_0203CF1C->spriteIds[0] = sub_81C45F4(&gUnknown_0203CF1C->currentMon, &gUnknown_0203CF1C->unk40F0);
        if (gUnknown_0203CF1C->spriteIds[0] != 0xFF)
        {
            gUnknown_0203CF1C->unk40F0 = 0;
            gMain.state++;
        }
        break;
    case 18:
        CreateMonMarkingsSprite(&gUnknown_0203CF1C->currentMon);
        gMain.state++;
        break;
    case 19:
        CreateCaughtBallSprite(&gUnknown_0203CF1C->currentMon);
        gMain.state++;
        break;
    case 20:
        CreateSetStatusSprite();
        gMain.state++;
        break;
    case 21:
        sub_81C4280();
        gMain.state++;
        break;
    case 22:
        if (gUnknown_0203CF1C->mode != PSS_MODE_SELECT_MOVE)
            CreateTask(sub_81C0510, 0);
        else
            CreateTask(sub_81C171C, 0);
        gMain.state++;
        break;
    case 23:
        BlendPalettes(-1, 16, 0);
        gMain.state++;
        break;
    case 24:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, 0);
        gPaletteFade.bufferTransferDisabled = 0;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(SummaryScreen_VBlank);
        SetMainCallback2(SummaryScreen_MainCB2);
        return TRUE;
    }
    return FALSE;
}

static void InitBGs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0861CBB4, ARRAY_COUNT(gUnknown_0861CBB4));
    SetBgTilemapBuffer(1, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0]);
    SetBgTilemapBuffer(2, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_SKILLS][0]);
    SetBgTilemapBuffer(3, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][0]);
    ResetAllBgsCoordinates();
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    schedule_bg_copy_tilemap_to_vram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, 0x1040);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

bool8 sub_81BFEB0(void)
{
    switch (gUnknown_0203CF1C->unk40F0)
    {
    case 0:
        reset_temp_tile_data_buffers();
        decompress_and_copy_tile_data_to_vram(1, &gUnknown_08D97D0C, 0, 0, 0);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 1:
        if (free_temp_tile_data_buffers_if_possible() != 1)
        {
            LZDecompressWram(&gUnknown_08D9862C, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][0]);
            gUnknown_0203CF1C->unk40F0++;
        }
        break;
    case 2:
        LZDecompressWram(&gUnknown_08D98CC8, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][1]);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 3:
        LZDecompressWram(&gUnknown_08D987FC, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_SKILLS][1]);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 4:
        LZDecompressWram(&gUnknown_08D9898C, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][1]);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 5:
        LZDecompressWram(&gUnknown_08D98B28, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][1]);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 6:
        LoadCompressedPalette(&gUnknown_08D9853C, 0, 0x100);
        LoadPalette(&gUnknown_08D85620, 0x81, 0x1E);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 7:
        LoadCompressedObjectPic(&gUnknown_0861CFBC);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 8:
        LoadCompressedObjectPic(&gUnknown_0861D074);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 9:
        LoadCompressedObjectPic(&gUnknown_0861D0F8);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 10:
        LoadCompressedObjectPalette(&gUnknown_0861D100);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 11:
        LoadCompressedObjectPalette(&gUnknown_0861D07C);
        gUnknown_0203CF1C->unk40F0++;
        break;
    case 12:
        LoadCompressedPalette(&gMoveTypes_Pal, 0x1D0, 0x60);
        gUnknown_0203CF1C->unk40F0 = 0;
        return TRUE;
    }
    return FALSE;
}

void CopyMonToSummaryStruct(struct Pokemon *mon)
{
    if (!gUnknown_0203CF1C->isBoxMon)
    {
        struct Pokemon *partyMon = gUnknown_0203CF1C->monList.mons;
        *mon = partyMon[gUnknown_0203CF1C->curMonIndex];
    }
    else
    {
        struct BoxPokemon *boxMon = gUnknown_0203CF1C->monList.boxMons;
        BoxMonToMon(&boxMon[gUnknown_0203CF1C->curMonIndex], mon);
    }
}

bool8 ExtractMonDataToSummaryStruct(struct Pokemon *a)
{
    u32 i;
    struct PokeSummary *sum = &gUnknown_0203CF1C->summary;
    switch (gUnknown_0203CF1C->unk40F0)
    {
    case 0:
        sum->species = GetMonData(a, MON_DATA_SPECIES);
        sum->species2 = GetMonData(a, MON_DATA_SPECIES2);
        sum->exp = GetMonData(a, MON_DATA_EXP);
        sum->level = GetMonData(a, MON_DATA_LEVEL);
        sum->altAbility = GetMonData(a, MON_DATA_ALT_ABILITY);
        sum->item = GetMonData(a, MON_DATA_HELD_ITEM);
        sum->pid = GetMonData(a, MON_DATA_PERSONALITY);
        sum->sanity = GetMonData(a, MON_DATA_SANITY_BIT1);

        if (sum->sanity)
            sum->isEgg = TRUE;
        else
            sum->isEgg = GetMonData(a, MON_DATA_IS_EGG);
        
        break;
    case 1:
        for (i = 0; i < 4; i++)
        {
            sum->moves[i] = GetMonData(a, MON_DATA_MOVE1+i);
            sum->pp[i] = GetMonData(a, MON_DATA_PP1+i);
        }
        sum->ppBonuses = GetMonData(a, MON_DATA_PP_BONUSES);
        break;
    case 2:
        if (gUnknown_0203CF1C->monList.mons == gPlayerParty || gUnknown_0203CF1C->mode == PSS_MODE_UNK2 || gUnknown_0203CF1C->unk40EF == TRUE)
        {
            sum->nature = GetNature(a);
            sum->currentHP = GetMonData(a, MON_DATA_HP);
            sum->maxHP = GetMonData(a, MON_DATA_MAX_HP);
            sum->atk = GetMonData(a, MON_DATA_ATK);
            sum->def = GetMonData(a, MON_DATA_DEF);
            sum->spatk = GetMonData(a, MON_DATA_SPATK);
            sum->spdef = GetMonData(a, MON_DATA_SPDEF);
            sum->speed = GetMonData(a, MON_DATA_SPEED);
        }
        else
        {
            sum->nature = GetNature(a);
            sum->currentHP = GetMonData(a, MON_DATA_HP);
            sum->maxHP = GetMonData(a, MON_DATA_MAX_HP);
            sum->atk = GetMonData(a, MON_DATA_ATK2);
            sum->def = GetMonData(a, MON_DATA_DEF2);
            sum->spatk = GetMonData(a, MON_DATA_SPATK2);
            sum->spdef = GetMonData(a, MON_DATA_SPDEF2);
            sum->speed = GetMonData(a, MON_DATA_SPEED2);
        }
        break;
    case 3:
        GetMonData(a, MON_DATA_OT_NAME, &sum->OTName);
        ConvertInternationalString((u8*)&sum->OTName, GetMonData(a, MON_DATA_LANGUAGE));
        sum->unk7 = sub_81B205C(a);
        sum->OTGender = GetMonData(a, MON_DATA_OT_GENDER);
        sum->OTID = GetMonData(a, MON_DATA_OT_ID);
        sum->metLocation = GetMonData(a, MON_DATA_MET_LOCATION);
        sum->metLevel = GetMonData(a, MON_DATA_MET_LEVEL);
        sum->metGame = GetMonData(a, MON_DATA_MET_GAME);
        sum->friendship = GetMonData(a, MON_DATA_FRIENDSHIP);
        break;
    default:
        sum->ribbonCount = GetMonData(a, MON_DATA_RIBBON_COUNT);
        return TRUE;
    }
    gUnknown_0203CF1C->unk40F0++;
    return FALSE;
}

void sub_81C0348(void)
{
    if (gUnknown_0203CF1C->currPageIndex != PSS_PAGE_BATTLE_MOVES && gUnknown_0203CF1C->currPageIndex != PSS_PAGE_CONTEST_MOVES)
    {
        sub_81C1DA4(0, 255);
        sub_81C1EFC(0, 255, 0);
    }
    else
    {
        sub_81C240C(gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->firstMoveIndex]);
        sub_81C2194(gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0], 3, 0);
        sub_81C2194(gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][0], 1, 0);
        SetBgTilemapBuffer(1, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][0]);
        SetBgTilemapBuffer(2, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0]);
        ChangeBgX(2, 0x10000, 1);
        ClearWindowTilemap(19);
        ClearWindowTilemap(13);
    }
    if (gUnknown_0203CF1C->summary.unk7 == 0)
    {
        sub_81C2074(0, 0xFF);
    }
    else
    {
        if (gUnknown_0203CF1C->currPageIndex != PSS_PAGE_BATTLE_MOVES && gUnknown_0203CF1C->currPageIndex != PSS_PAGE_CONTEST_MOVES)
            PutWindowTilemap(13);
    }
    sub_81C2524();
    sub_81C2228(&gUnknown_0203CF1C->currentMon);
}

void sub_81C0434(void)
{
    FreeAllWindowBuffers();
    Free(gUnknown_0203CF1C);
}

void sub_81C044C(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
    gTasks[taskId].func = sub_81C0484;
}

void sub_81C0484(u8 taskId)
{
    if (sub_81221EC() != 1 && !gPaletteFade.active)
    {
        SetMainCallback2(gUnknown_0203CF1C->callback);
        gUnknown_0203CF20 = gUnknown_0203CF1C->curMonIndex;
        SummaryScreen_DestroyUnknownTask();
        ResetSpriteData();
        FreeAllSpritePalettes();
        StopCryAndClearCrySongs();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
        if (gMonSpritesGfxPtr == 0)
            sub_806F47C(0);
        sub_81C0434();
        DestroyTask(taskId);
    }
}

void sub_81C0510(u8 taskId)
{
    if (sub_81221EC() != 1 && !gPaletteFade.active)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            sub_81C0604(taskId, -1);
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            sub_81C0604(taskId, 1);
        }
        else if ((gMain.newKeys & DPAD_LEFT) || GetLRKeysState() == 1)
        {
            sub_81C0A8C(taskId, -1);
        }
        else if ((gMain.newKeys & DPAD_RIGHT) || GetLRKeysState() == 2)
        {
            sub_81C0A8C(taskId, 1);
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            if (gUnknown_0203CF1C->currPageIndex != PSS_PAGE_SKILLS)
            {
                if (gUnknown_0203CF1C->currPageIndex == PSS_PAGE_INFO)
                {
                    sub_81C48F0();
                    PlaySE(SE_SELECT);
                    sub_81C044C(taskId);
                }
                else
                {
                    PlaySE(SE_SELECT);
                    sub_81C0E48(taskId);
                }
            }
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            sub_81C48F0();
            PlaySE(SE_SELECT);
            sub_81C044C(taskId);
        }
    }
}

void sub_81C0604(u8 taskId, s8 a)
{
    s8 r4_2;

    if (!gUnknown_0203CF1C->unk40C3)
    {
        if (gUnknown_0203CF1C->isBoxMon == TRUE)
        {
            if (gUnknown_0203CF1C->currPageIndex != PSS_PAGE_INFO)
            {
                if (a == 1)
                    a = 0;
                else
                    a = 2;
            }
            else
            {
                if (a == 1)
                    a = 1;
                else
                    a = 3;
            }
            r4_2 = sub_80D214C(gUnknown_0203CF1C->monList.boxMons, gUnknown_0203CF1C->curMonIndex, gUnknown_0203CF1C->maxMonIndex, a);
        }
        else if (sub_81B1250() == 1)
        {
            r4_2 = sub_81C09B4(a);
        }
        else
        {
            r4_2 = sub_81C08F8(a);
        }

        if (r4_2 != -1)
        {
            PlaySE(SE_SELECT);
            if (gUnknown_0203CF1C->summary.unk7 != 0)
            {
                sub_81C4204(2, 1);
                ClearWindowTilemap(13);
                schedule_bg_copy_tilemap_to_vram(0);
                sub_81C2074(0, 2);
            }
            gUnknown_0203CF1C->curMonIndex = r4_2;
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = sub_81C0704;
        }
    }
}

void sub_81C0704(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        StopCryAndClearCrySongs();
        break;
    case 1:
        SummaryScreen_DestroyUnknownTask();
        DestroySpriteAndFreeResources(&gSprites[gUnknown_0203CF1C->spriteIds[0]]);
        break;
    case 2:
        DestroySpriteAndFreeResources(&gSprites[gUnknown_0203CF1C->spriteIds[1]]);
        break;
    case 3:
        CopyMonToSummaryStruct(&gUnknown_0203CF1C->currentMon);
        gUnknown_0203CF1C->unk40F0 = 0;
        break;
    case 4:
        if (ExtractMonDataToSummaryStruct(&gUnknown_0203CF1C->currentMon) == FALSE)
            return;
        break;
    case 5:
        RemoveAndCreateMonMarkingsSprite(&gUnknown_0203CF1C->currentMon);
        break;
    case 6:
        CreateCaughtBallSprite(&gUnknown_0203CF1C->currentMon);
        break;
    case 7:
        if (gUnknown_0203CF1C->summary.unk7)
            sub_81C2074(10, -2);
        sub_81C2228(&gUnknown_0203CF1C->currentMon);
        data[1] = 0;
        break;
    case 8:
        gUnknown_0203CF1C->spriteIds[0] = sub_81C45F4(&gUnknown_0203CF1C->currentMon, &data[1]);
        if (gUnknown_0203CF1C->spriteIds[0] == 0xFF)
            return;
        gSprites[gUnknown_0203CF1C->spriteIds[0]].data[2] = 1;
        sub_81C0E24();
        data[1] = 0;
        break;
    case 9:
        sub_81C4280();
        break;
    case 10:
        sub_81C25E8();
        break;
    case 11:
        sub_81C2D9C(gUnknown_0203CF1C->currPageIndex);
        sub_81C2524();
        break;
    case 12:
        gSprites[gUnknown_0203CF1C->spriteIds[0]].data[2] = 0;
        break;
    default:
        if (sub_81221EC() == 0 && FuncIsActiveTask(sub_81C20F0) == 0)
        {
            data[0] = 0;
            gTasks[taskId].func = sub_81C0510;
        }
        return;
    }
    data[0]++;
}

s8 sub_81C08F8(s8 a)
{
    struct Pokemon *mon = gUnknown_0203CF1C->monList.mons;

    if (gUnknown_0203CF1C->currPageIndex == PSS_PAGE_INFO)
    {
        if (a == -1 && gUnknown_0203CF1C->curMonIndex == 0)
            return -1;
        else if (a == 1 && gUnknown_0203CF1C->curMonIndex >= gUnknown_0203CF1C->maxMonIndex)
            return -1;
        else
            return gUnknown_0203CF1C->curMonIndex + a;
    }
    else
    {
        s8 index = gUnknown_0203CF1C->curMonIndex;

        do
        {
            index += a;
            if (index < 0 || index > gUnknown_0203CF1C->maxMonIndex)
                return -1;
        } while (GetMonData(&mon[index], MON_DATA_IS_EGG) != 0);
        return index;
    }
}

s8 sub_81C09B4(s8 a)
{
    struct Pokemon *mon = gUnknown_0203CF1C->monList.mons;
    s8 r5 = 0;
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (gUnknown_0861CC1C[i] == gUnknown_0203CF1C->curMonIndex)
        {
            r5 = i;
            break;
        }
    }

    while (TRUE)
    {
        int b;
        const s8* c = gUnknown_0861CC1C;

        r5 += a;
        if (r5 < 0 || r5 >= 6)
            return -1;
        b = c[r5];
        if (sub_81C0A50(&mon[b]) == TRUE)
            return b;
    }
}

bool8 sub_81C0A50(struct Pokemon* mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES) == 0)
        return FALSE;
    else if (gUnknown_0203CF1C->curMonIndex != 0 || GetMonData(mon, MON_DATA_IS_EGG) == 0)
        return TRUE;
    else
        return FALSE;
}

void sub_81C0A8C(u8 taskId, s8 b)
{
    struct PokeSummary *summary = &gUnknown_0203CF1C->summary;
    s16 *data = gTasks[taskId].data;

    if (summary->isEgg)
        return;
    else if (b == -1 && gUnknown_0203CF1C->currPageIndex == gUnknown_0203CF1C->minPageIndex)
        return;
    else if (b == 1 && gUnknown_0203CF1C->currPageIndex == gUnknown_0203CF1C->maxPageIndex)
        return;
    
    PlaySE(SE_SELECT);
    sub_81C2C38(gUnknown_0203CF1C->currPageIndex);
    gUnknown_0203CF1C->currPageIndex += b;
    data[0] = 0;
    if (b == 1)
        SetTaskFuncWithFollowupFunc(taskId, sub_81C0B8C, gTasks[taskId].func);
    else
        SetTaskFuncWithFollowupFunc(taskId, sub_81C0CC4, gTasks[taskId].func);
    sub_81C2DE4(gUnknown_0203CF1C->currPageIndex);
    sub_81C424C();
}

void sub_81C0B8C(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (data[0] == 0)
    {
        if (gUnknown_0203CF1C->unk40C9 == 0)
        {
            data[1] = 1;
            SetBgAttribute(1, 7, 1);
            SetBgAttribute(2, 7, 2);
            schedule_bg_copy_tilemap_to_vram(1);
        }
        else
        {
            data[1] = 2;
            SetBgAttribute(2, 7, 1);
            SetBgAttribute(1, 7, 2);
            schedule_bg_copy_tilemap_to_vram(2);
        }
        ChangeBgX(data[1], 0, 0);
        SetBgTilemapBuffer(data[1], gUnknown_0203CF1C->bgTilemapBuffers[gUnknown_0203CF1C->currPageIndex][0]);
        ShowBg(1);
        ShowBg(2);
    }
    ChangeBgX(data[1], 0x2000, 1);
    data[0] += 32;
    if (data[0] > 0xFF)
        gTasks[taskId].func = sub_81C0C68;
}

void sub_81C0C68(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    gUnknown_0203CF1C->unk40C9 ^= 1;
    data[1] = 0;
    data[0] = 0;
    sub_81C1BA0();
    sub_81C2AFC(gUnknown_0203CF1C->currPageIndex);
    sub_81C4280();
    sub_81C0E24();
    SwitchTaskToFollowupFunc(taskId);
}

void sub_81C0CC4(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (data[0] == 0)
    {
        if (gUnknown_0203CF1C->unk40C9 == 0)
            data[1] = 2;
        else
            data[1] = 1;
        ChangeBgX(data[1], 0x10000, 0);
    }
    ChangeBgX(data[1], 0x2000, 2);
    data[0] += 32;
    if (data[0] > 0xFF)
        gTasks[taskId].func = sub_81C0D44;
}

void sub_81C0D44(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (gUnknown_0203CF1C->unk40C9 == 0)
    {
        SetBgAttribute(1, 7, 1);
        SetBgAttribute(2, 7, 2);
        schedule_bg_copy_tilemap_to_vram(2);
    }
    else
    {
        SetBgAttribute(2, 7, 1);
        SetBgAttribute(1, 7, 2);
        schedule_bg_copy_tilemap_to_vram(1);
    }
    if (gUnknown_0203CF1C->currPageIndex > 1)
    {
        SetBgTilemapBuffer(data[1], (u8*)gUnknown_0203CF1C + ((gUnknown_0203CF1C->currPageIndex << 12) + 0xFFFFF0BC));
        ChangeBgX(data[1], 0x10000, 0);
    }
    ShowBg(1);
    ShowBg(2);
    gUnknown_0203CF1C->unk40C9 ^= 1;
    data[1] = 0;
    data[0] = 0;
    sub_81C1BA0();
    sub_81C2AFC(gUnknown_0203CF1C->currPageIndex);
    sub_81C4280();
    sub_81C0E24();
    SwitchTaskToFollowupFunc(taskId);
}

void sub_81C0E24(void)
{
    if (gUnknown_0203CF1C->currPageIndex == 1)
        sub_81C22CC(&gUnknown_0203CF1C->currentMon);
}

void sub_81C0E48(u8 taskId)
{
    u16 move;
    gUnknown_0203CF1C->firstMoveIndex = 0;
    move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->firstMoveIndex];
    ClearWindowTilemap(0x13);
    if (gSprites[gUnknown_0203CF1C->spriteIds[2]].invisible == 0)
        ClearWindowTilemap(0xD);
    sub_81C1DA4(9, -3);
    sub_81C1EFC(9, -3, move);
    if (!gUnknown_0203CF1C->unk40C8)
    {
        ClearWindowTilemap(5);
        PutWindowTilemap(6);
    }
    sub_81C2194(gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0], 3, 0);
    sub_81C2194(gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][0], 1, 0);
    PrintMoveDetails(move);
    PrintNewMoveDetailsOrCancelText();
    sub_81C44F0();
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    sub_81C4AF8(8);
    gTasks[taskId].func = sub_81C0F44;
}

void sub_81C0F44(u8 taskId)
{
    u8 id = taskId;
    s16 *data = gTasks[taskId].data;

    if (sub_81221EC() != 1)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            data[0] = 4;
            sub_81C1070(data, -1, &gUnknown_0203CF1C->firstMoveIndex);
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            data[0] = 4;
            sub_81C1070(data, 1, &gUnknown_0203CF1C->firstMoveIndex);
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            if (gUnknown_0203CF1C->unk40C8 == TRUE
             || (gUnknown_0203CF1C->newMove == MOVE_NONE && gUnknown_0203CF1C->firstMoveIndex == MAX_MON_MOVES))
            {
                PlaySE(SE_SELECT);
                sub_81C11F4(taskId);
            }
            else if (sub_81C1040() == TRUE)
            {
                PlaySE(SE_SELECT);
                sub_81C129C(taskId);
            }
            else
            {
                PlaySE(SE_HAZURE);
            }
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            sub_81C11F4(id);
        }
    }
}

bool8 sub_81C1040(void)
{
    u8 i;
    for (i = 1; i < 4; i++)
    {
        if (gUnknown_0203CF1C->summary.moves[i] != 0)
            return TRUE;
    }
    return FALSE;
}

void sub_81C1070(s16 *a, s8 b, u8 *c)
{
    s8 i;
    s8 moveIndex;
    u16 move;

    PlaySE(SE_SELECT);
    moveIndex = *c;
    for (i = 0; i < 4; i++)
    {
        moveIndex += b;
        if (moveIndex > a[0])
            moveIndex = 0;
        else if (moveIndex < 0)
            moveIndex = a[0];
        if (moveIndex == 4)
        {
            move = gUnknown_0203CF1C->newMove;
            break;
        }
        move = gUnknown_0203CF1C->summary.moves[moveIndex];
        if (move != 0)
            break;
    }
    sub_81C240C(move);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    PrintMoveDetails(move);
    if ((*c == 4 && gUnknown_0203CF1C->newMove == MOVE_NONE) || a[1] == 1)
    {
        ClearWindowTilemap(19);
        if (!gSprites[gUnknown_0203CF1C->spriteIds[2]].invisible)
            ClearWindowTilemap(13);
        schedule_bg_copy_tilemap_to_vram(0);
        sub_81C1DA4(9, -3);
        sub_81C1EFC(9, -3, move);
    }
    if (*c != 4 && moveIndex == 4 && gUnknown_0203CF1C->newMove == MOVE_NONE)
    {
        ClearWindowTilemap(14);
        ClearWindowTilemap(15);
        schedule_bg_copy_tilemap_to_vram(0);
        sub_81C1DA4(0, 3);
        sub_81C1EFC(0, 3, 0);
    }
    *c = moveIndex;
    if (c == &gUnknown_0203CF1C->firstMoveIndex)
        sub_81C4D18(8);
    else
        sub_81C4D18(18);
}

void sub_81C11F4(u8 taskId)
{
    sub_81C4C60(8);
    ClearWindowTilemap(6);
    PutWindowTilemap(5);
    PrintMoveDetails(0);
    sub_81C2194(gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0], 3, 1);
    sub_81C2194(gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][0], 1, 1);
    sub_81C4064();
    if (gUnknown_0203CF1C->firstMoveIndex != MAX_MON_MOVES)
    {
        ClearWindowTilemap(14);
        ClearWindowTilemap(15);
        sub_81C1DA4(0, 3);
        sub_81C1EFC(0, 3, 0);
    }
    schedule_bg_copy_tilemap_to_vram(0);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81C0510;
}

void sub_81C129C(u8 taskId)
{
    gUnknown_0203CF1C->secondMoveIndex = gUnknown_0203CF1C->firstMoveIndex;
    sub_81C4C84(1);
    sub_81C4AF8(18);
    gTasks[taskId].func = sub_81C12E4;
}

void sub_81C12E4(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (sub_81221EC() != TRUE)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            data[0] = 3;
            sub_81C1070(&data[0], -1, &gUnknown_0203CF1C->secondMoveIndex);
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            data[0] = 3;
            sub_81C1070(&data[0], 1, &gUnknown_0203CF1C->secondMoveIndex);
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            if (gUnknown_0203CF1C->firstMoveIndex == gUnknown_0203CF1C->secondMoveIndex)
            {
                sub_81C13B0(taskId, 0);
            }
            else
            {
                sub_81C13B0(taskId, 1);
            }
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            sub_81C13B0(taskId, 0);
        }
    }
}

void sub_81C13B0(u8 taskId, bool8 b)
{
    u16 move;

    PlaySE(SE_SELECT);
    sub_81C4C84(0);
    sub_81C4C60(18);

    if (b == TRUE)
    {
        if (!gUnknown_0203CF1C->isBoxMon)
        {
            struct Pokemon *why = gUnknown_0203CF1C->monList.mons;
            sub_81C14BC(&why[gUnknown_0203CF1C->curMonIndex], gUnknown_0203CF1C->firstMoveIndex, gUnknown_0203CF1C->secondMoveIndex);
        }
        else
        {
            struct BoxPokemon *why = gUnknown_0203CF1C->monList.boxMons;
            sub_81C15EC(&why[gUnknown_0203CF1C->curMonIndex], gUnknown_0203CF1C->firstMoveIndex, gUnknown_0203CF1C->secondMoveIndex);
        }
        CopyMonToSummaryStruct(&gUnknown_0203CF1C->currentMon);
        sub_81C40A0(gUnknown_0203CF1C->firstMoveIndex, gUnknown_0203CF1C->secondMoveIndex);
        sub_81C4568(gUnknown_0203CF1C->firstMoveIndex, gUnknown_0203CF1C->secondMoveIndex);
        gUnknown_0203CF1C->firstMoveIndex = gUnknown_0203CF1C->secondMoveIndex;
    }

    move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->firstMoveIndex];
    PrintMoveDetails(move);
    sub_81C240C(move);
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
    gTasks[taskId].func = sub_81C0F44;
}


#ifdef NONMATCHING
void sub_81C14BC(struct Pokemon *mon, u8 swappingFromId, u8 swappingToId)
{
    u16 localMoveTo;
    u16 localMoveFrom;
    u8 localPpTo;
    u8 localPpFrom;
    u8 localPpBonuses;
    u16* moveFromPtr;
    u16* moveToPtr;
    u8* ppFromPtr;
    u8* ppToPtr;
    u8* ppBonusesPtr;

    moveFromPtr = &gUnknown_0203CF1C->summary.moves[swappingFromId];
    localMoveFrom = *moveFromPtr;

    moveToPtr = &gUnknown_0203CF1C->summary.moves[swappingToId];
    localMoveTo = *moveToPtr;

    ppFromPtr = &gUnknown_0203CF1C->summary.pp[swappingFromId];
    localPpFrom = *ppFromPtr;

    ppToPtr = &gUnknown_0203CF1C->summary.pp[swappingToId];
    localPpTo = *ppToPtr;

    ppBonusesPtr = &gUnknown_0203CF1C->summary.ppBonuses;
    localPpBonuses = *ppBonusesPtr;

{
    u8 bitsFrom, bitsTo;

    bitsFrom = (localPpBonuses & gUnknown_08329D22[swappingFromId]) >> (swappingFromId << 1);
    bitsTo = (localPpBonuses & gUnknown_08329D22[swappingToId]) >> (swappingToId << 1);


    localPpBonuses &= ~(gUnknown_08329D22[swappingFromId]);
    localPpBonuses &= ~(gUnknown_08329D22[swappingToId]);

    localPpBonuses |= ((bitsFrom << (swappingToId << 1)) + (bitsTo << (swappingToId << 1)));
}

    SetMonData(mon, swappingFromId + MON_DATA_MOVE1, &localMoveTo);
    SetMonData(mon, swappingToId + MON_DATA_MOVE1, &localMoveFrom);

    SetMonData(mon, swappingFromId + MON_DATA_PP1, &localPpTo);
    SetMonData(mon, swappingToId + MON_DATA_PP1, &localPpFrom);

    SetMonData(mon, MON_DATA_PP_BONUSES, &localPpBonuses);

    *moveFromPtr = localMoveTo;
    *moveToPtr = localMoveFrom;

    *ppFromPtr = localPpTo;
    *ppToPtr = localPpFrom;

    *ppBonusesPtr = localPpBonuses;
}
#else
NAKED
void sub_81C14BC(struct Pokemon *mon, u8 swappingFromId, u8 swappingToId)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x28\n\
	adds r7, r0, 0\n\
	adds r4, r1, 0\n\
	adds r6, r2, 0\n\
	lsls r4, 24\n\
	lsrs r4, 24\n\
	lsls r6, 24\n\
	lsrs r6, 24\n\
	ldr r0, =gUnknown_0203CF1C\n\
	ldr r2, [r0]\n\
	lsls r0, r4, 1\n\
	mov r10, r0\n\
	adds r1, r2, 0\n\
	adds r1, 0x84\n\
	adds r0, r1, r0\n\
	str r0, [sp, 0x8]\n\
	ldrh r0, [r0]\n\
	mov r3, sp\n\
	adds r3, 0x2\n\
	str r3, [sp, 0x1C]\n\
	strh r0, [r3]\n\
	lsls r0, r6, 1\n\
	mov r9, r0\n\
	add r1, r9\n\
	str r1, [sp, 0xC]\n\
	ldrh r1, [r1]\n\
	mov r0, sp\n\
	strh r1, [r0]\n\
	adds r1, r2, 0\n\
	adds r1, 0x8C\n\
	adds r3, r1, r4\n\
	str r3, [sp, 0x10]\n\
	ldrb r0, [r3]\n\
	mov r3, sp\n\
	adds r3, 0x5\n\
	str r3, [sp, 0x24]\n\
	strb r0, [r3]\n\
	adds r1, r6\n\
	str r1, [sp, 0x14]\n\
	ldrb r0, [r1]\n\
	mov r1, sp\n\
	adds r1, 0x4\n\
	str r1, [sp, 0x20]\n\
	strb r0, [r1]\n\
	adds r2, 0xA4\n\
	str r2, [sp, 0x18]\n\
	ldrb r0, [r2]\n\
	mov r5, sp\n\
	adds r5, 0x6\n\
	strb r0, [r5]\n\
	ldr r1, =gUnknown_08329D22\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	mov r8, r0\n\
	ldrb r0, [r5]\n\
	adds r2, r0, 0\n\
	mov r3, r8\n\
	ands r2, r3\n\
	mov r3, r10\n\
	asrs r2, r3\n\
	lsls r2, 24\n\
	lsrs r2, 24\n\
	adds r1, r6, r1\n\
	ldrb r1, [r1]\n\
	mov r12, r1\n\
	adds r1, r0, 0\n\
	mov r3, r12\n\
	ands r1, r3\n\
	mov r3, r9\n\
	asrs r1, r3\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	mov r3, r8\n\
	bics r0, r3\n\
	strb r0, [r5]\n\
	ldrb r0, [r5]\n\
	mov r3, r12\n\
	bics r0, r3\n\
	strb r0, [r5]\n\
	mov r0, r9\n\
	lsls r2, r0\n\
	mov r3, r10\n\
	lsls r1, r3\n\
	adds r2, r1\n\
	ldrb r0, [r5]\n\
	orrs r0, r2\n\
	strb r0, [r5]\n\
	adds r1, r4, 0\n\
	adds r1, 0xD\n\
	adds r0, r7, 0\n\
	mov r2, sp\n\
	bl SetMonData\n\
	adds r1, r6, 0\n\
	adds r1, 0xD\n\
	adds r0, r7, 0\n\
	ldr r2, [sp, 0x1C]\n\
	bl SetMonData\n\
	adds r4, 0x11\n\
	adds r0, r7, 0\n\
	adds r1, r4, 0\n\
	ldr r2, [sp, 0x20]\n\
	bl SetMonData\n\
	adds r6, 0x11\n\
	adds r0, r7, 0\n\
	adds r1, r6, 0\n\
	ldr r2, [sp, 0x24]\n\
	bl SetMonData\n\
	adds r0, r7, 0\n\
	movs r1, 0x15\n\
	adds r2, r5, 0\n\
	bl SetMonData\n\
	mov r0, sp\n\
	ldrh r0, [r0]\n\
	ldr r1, [sp, 0x8]\n\
	strh r0, [r1]\n\
	ldr r3, [sp, 0x1C]\n\
	ldrh r0, [r3]\n\
	ldr r1, [sp, 0xC]\n\
	strh r0, [r1]\n\
	ldr r3, [sp, 0x20]\n\
	ldrb r0, [r3]\n\
	ldr r1, [sp, 0x10]\n\
	strb r0, [r1]\n\
	ldr r3, [sp, 0x24]\n\
	ldrb r0, [r3]\n\
	ldr r1, [sp, 0x14]\n\
	strb r0, [r1]\n\
	ldrb r0, [r5]\n\
	ldr r3, [sp, 0x18]\n\
	strb r0, [r3]\n\
	add sp, 0x28\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
	.syntax divided\n");
}
#endif

#ifdef NONMATCHING
void sub_81C15EC(struct BoxPokemon *mon, u8 swappingFromId, u8 swappingToId)
{
    u16 localMoveTo;
    u16 localMoveFrom;
    u8 localPpTo;
    u8 localPpFrom;
    u8 localPpBonuses;
    u16* moveFromPtr;
    u16* moveToPtr;
    u8* ppFromPtr;
    u8* ppToPtr;
    u8* ppBonusesPtr;

    moveFromPtr = &gUnknown_0203CF1C->summary.moves[swappingFromId];
    localMoveFrom = *moveFromPtr;

    moveToPtr = &gUnknown_0203CF1C->summary.moves[swappingToId];
    localMoveTo = *moveToPtr;

    ppFromPtr = &gUnknown_0203CF1C->summary.pp[swappingFromId];
    localPpFrom = *ppFromPtr;

    ppToPtr = &gUnknown_0203CF1C->summary.pp[swappingToId];
    localPpTo = *ppToPtr;

    ppBonusesPtr = &gUnknown_0203CF1C->summary.ppBonuses;
    localPpBonuses = *ppBonusesPtr;

{
    u8 bitsFrom, bitsTo;

    bitsFrom = (localPpBonuses & gUnknown_08329D22[swappingFromId]) >> (swappingFromId << 1);
    bitsTo = (localPpBonuses & gUnknown_08329D22[swappingToId]) >> (swappingToId << 1);


    localPpBonuses &= ~(gUnknown_08329D22[swappingFromId]);
    localPpBonuses &= ~(gUnknown_08329D22[swappingToId]);

    localPpBonuses |= ((bitsFrom << (swappingToId << 1)) + (bitsTo << (swappingToId << 1)));
}

    SetBoxMonData(mon, swappingFromId + MON_DATA_MOVE1, &localMoveTo);
    SetBoxMonData(mon, swappingToId + MON_DATA_MOVE1, &localMoveFrom);

    SetBoxMonData(mon, swappingFromId + MON_DATA_PP1, &localPpTo);
    SetBoxMonData(mon, swappingToId + MON_DATA_PP1, &localPpFrom);

    SetBoxMonData(mon, MON_DATA_PP_BONUSES, &localPpBonuses);

    *moveFromPtr = localMoveTo;
    *moveToPtr = localMoveFrom;

    *ppFromPtr = localPpTo;
    *ppToPtr = localPpFrom;

    *ppBonusesPtr = localPpBonuses;
}
#else
NAKED
void sub_81C15EC(struct BoxPokemon *mon, u8 swappingFromId, u8 swappingToId)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x28\n\
	adds r7, r0, 0\n\
	adds r4, r1, 0\n\
	adds r6, r2, 0\n\
	lsls r4, 24\n\
	lsrs r4, 24\n\
	lsls r6, 24\n\
	lsrs r6, 24\n\
	ldr r0, =gUnknown_0203CF1C\n\
	ldr r2, [r0]\n\
	lsls r0, r4, 1\n\
	mov r10, r0\n\
	adds r1, r2, 0\n\
	adds r1, 0x84\n\
	adds r0, r1, r0\n\
	str r0, [sp, 0x8]\n\
	ldrh r0, [r0]\n\
	mov r3, sp\n\
	adds r3, 0x2\n\
	str r3, [sp, 0x1C]\n\
	strh r0, [r3]\n\
	lsls r0, r6, 1\n\
	mov r9, r0\n\
	add r1, r9\n\
	str r1, [sp, 0xC]\n\
	ldrh r1, [r1]\n\
	mov r0, sp\n\
	strh r1, [r0]\n\
	adds r1, r2, 0\n\
	adds r1, 0x8C\n\
	adds r3, r1, r4\n\
	str r3, [sp, 0x10]\n\
	ldrb r0, [r3]\n\
	mov r3, sp\n\
	adds r3, 0x5\n\
	str r3, [sp, 0x24]\n\
	strb r0, [r3]\n\
	adds r1, r6\n\
	str r1, [sp, 0x14]\n\
	ldrb r0, [r1]\n\
	mov r1, sp\n\
	adds r1, 0x4\n\
	str r1, [sp, 0x20]\n\
	strb r0, [r1]\n\
	adds r2, 0xA4\n\
	str r2, [sp, 0x18]\n\
	ldrb r0, [r2]\n\
	mov r5, sp\n\
	adds r5, 0x6\n\
	strb r0, [r5]\n\
	ldr r1, =gUnknown_08329D22\n\
	adds r0, r4, r1\n\
	ldrb r0, [r0]\n\
	mov r8, r0\n\
	ldrb r0, [r5]\n\
	adds r2, r0, 0\n\
	mov r3, r8\n\
	ands r2, r3\n\
	mov r3, r10\n\
	asrs r2, r3\n\
	lsls r2, 24\n\
	lsrs r2, 24\n\
	adds r1, r6, r1\n\
	ldrb r1, [r1]\n\
	mov r12, r1\n\
	adds r1, r0, 0\n\
	mov r3, r12\n\
	ands r1, r3\n\
	mov r3, r9\n\
	asrs r1, r3\n\
	lsls r1, 24\n\
	lsrs r1, 24\n\
	mov r3, r8\n\
	bics r0, r3\n\
	strb r0, [r5]\n\
	ldrb r0, [r5]\n\
	mov r3, r12\n\
	bics r0, r3\n\
	strb r0, [r5]\n\
	mov r0, r9\n\
	lsls r2, r0\n\
	mov r3, r10\n\
	lsls r1, r3\n\
	adds r2, r1\n\
	ldrb r0, [r5]\n\
	orrs r0, r2\n\
	strb r0, [r5]\n\
	adds r1, r4, 0\n\
	adds r1, 0xD\n\
	adds r0, r7, 0\n\
	mov r2, sp\n\
	bl SetBoxMonData\n\
	adds r1, r6, 0\n\
	adds r1, 0xD\n\
	adds r0, r7, 0\n\
	ldr r2, [sp, 0x1C]\n\
	bl SetBoxMonData\n\
	adds r4, 0x11\n\
	adds r0, r7, 0\n\
	adds r1, r4, 0\n\
	ldr r2, [sp, 0x20]\n\
	bl SetBoxMonData\n\
	adds r6, 0x11\n\
	adds r0, r7, 0\n\
	adds r1, r6, 0\n\
	ldr r2, [sp, 0x24]\n\
	bl SetBoxMonData\n\
	adds r0, r7, 0\n\
	movs r1, 0x15\n\
	adds r2, r5, 0\n\
	bl SetBoxMonData\n\
	mov r0, sp\n\
	ldrh r0, [r0]\n\
	ldr r1, [sp, 0x8]\n\
	strh r0, [r1]\n\
	ldr r3, [sp, 0x1C]\n\
	ldrh r0, [r3]\n\
	ldr r1, [sp, 0xC]\n\
	strh r0, [r1]\n\
	ldr r3, [sp, 0x20]\n\
	ldrb r0, [r3]\n\
	ldr r1, [sp, 0x10]\n\
	strb r0, [r1]\n\
	ldr r3, [sp, 0x24]\n\
	ldrb r0, [r3]\n\
	ldr r1, [sp, 0x14]\n\
	strb r0, [r1]\n\
	ldrb r0, [r5]\n\
	ldr r3, [sp, 0x18]\n\
	strb r0, [r3]\n\
	add sp, 0x28\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
    .syntax divided\n");
}
#endif

void sub_81C171C(u8 taskId)
{
    sub_81C44F0();
    sub_81C4AF8(8);
    gTasks[taskId].func = sub_81C174C;
}

void sub_81C174C(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (sub_81221EC() != 1)
    {
        if (gPaletteFade.active != 1)
        {
            if (gMain.newKeys & DPAD_UP)
            {
                data[0] = 4;
                sub_81C1070(data, -1, &gUnknown_0203CF1C->firstMoveIndex);
            }
            else if (gMain.newKeys & DPAD_DOWN)
            {
                data[0] = 4;
                sub_81C1070(data, 1, &gUnknown_0203CF1C->firstMoveIndex);
            }
            else if (gMain.newKeys & DPAD_LEFT || GetLRKeysState() == 1)
            {
                sub_81C0A8C(taskId, -1);
            }
            else if (gMain.newKeys & DPAD_RIGHT || GetLRKeysState() == 2)
            {
                sub_81C0A8C(taskId, 1);
            }
            else if (gMain.newKeys & A_BUTTON)
            {
                if (sub_81C18A8() == TRUE)
                {
                    sub_81C48F0();
                    PlaySE(SE_SELECT);
                    gUnknown_0203CF21 = gUnknown_0203CF1C->firstMoveIndex;
                    gSpecialVar_0x8005 = gUnknown_0203CF21;
                    sub_81C044C(taskId);
                }
                else
                {
                    PlaySE(SE_HAZURE);
                    sub_81C18F4(taskId);
                }
            }
            else if (gMain.newKeys & B_BUTTON)
            {
                u32 var1;
                sub_81C48F0();
                PlaySE(SE_SELECT);
                gUnknown_0203CF21 = 4;
                gSpecialVar_0x8005 = 4;
                sub_81C044C(taskId);
            }
        }
    }
}

bool8 sub_81C18A8(void)
{
    if (gUnknown_0203CF1C->firstMoveIndex == MAX_MON_MOVES || gUnknown_0203CF1C->newMove == MOVE_NONE || sub_81B6D14(gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->firstMoveIndex]) != 1)
        return TRUE;
    else
        return FALSE;
}

void sub_81C18F4(u8 taskId)
{
    ClearWindowTilemap(14);
    ClearWindowTilemap(15);
    schedule_bg_copy_tilemap_to_vram(0);
    sub_81C1DA4(0, 3);
    sub_81C1EFC(0, 3, 0);
    sub_81C4154();
    gTasks[taskId].func = sub_81C1940;
}

void sub_81C1940(u8 taskId)
{
    s16* data = gTasks[taskId].data;
    u16 move;
    if (FuncIsActiveTask(sub_81C1E20) != 1)
    {
        if (gMain.newKeys & DPAD_UP)
        {
            data[1] = 1;
            data[0] = 4;
            sub_81C1070(&data[0], -1, &gUnknown_0203CF1C->firstMoveIndex);
            data[1] = 0;
            gTasks[taskId].func = sub_81C174C;
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            data[1] = 1;
            data[0] = 4;
            sub_81C1070(&data[0], 1, &gUnknown_0203CF1C->firstMoveIndex);
            data[1] = 0;
            gTasks[taskId].func = sub_81C174C;
        }
        else if (gMain.newKeys & DPAD_LEFT || GetLRKeysState() == 1)
        {
            if (gUnknown_0203CF1C->currPageIndex != 2)
            {
                ClearWindowTilemap(19);
                if (!gSprites[gUnknown_0203CF1C->spriteIds[2]].invisible)
                    ClearWindowTilemap(13);
                move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->firstMoveIndex];
                gTasks[taskId].func = sub_81C174C;
                sub_81C0A8C(taskId, -1);
                sub_81C1DA4(9, -2);
                sub_81C1EFC(9, -2, move);
            }
        }
        else if (gMain.newKeys & DPAD_RIGHT || GetLRKeysState() == 2)
        {
            if (gUnknown_0203CF1C->currPageIndex != 3)
            {
                ClearWindowTilemap(19);
                if (!gSprites[gUnknown_0203CF1C->spriteIds[2]].invisible)
                    ClearWindowTilemap(13);
                move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->firstMoveIndex];
                gTasks[taskId].func = sub_81C174C;
                sub_81C0A8C(taskId, 1);
                sub_81C1DA4(9, -2);
                sub_81C1EFC(9, -2, move);
            }
        }
        else if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            ClearWindowTilemap(19);
            if (!gSprites[gUnknown_0203CF1C->spriteIds[2]].invisible)
                ClearWindowTilemap(13);
            move = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->firstMoveIndex];
            PrintMoveDetails(move);
            schedule_bg_copy_tilemap_to_vram(0);
            sub_81C1DA4(9, -3);
            sub_81C1EFC(9, -3, move);
            gTasks[taskId].func = sub_81C174C;
        }
    }
}

u8 sub_81C1B94(void)
{
    return gUnknown_0203CF21;
}

void sub_81C1BA0(void)
{
    u16 *alloced = Alloc(32);
    u8 i;
    for (i = 0; i < 4; i++)
    {
        u8 j = i << 1;
        if (i < gUnknown_0203CF1C->minPageIndex)
        {
            alloced[j+0] = 0x40;
            alloced[j+1] = 0x40;
            alloced[j+8] = 0x50;
            alloced[j+9] = 0x50;
        }
        else if (i > gUnknown_0203CF1C->maxPageIndex)
        {
            alloced[j+0] = 0x4A;
            alloced[j+1] = 0x4A;
            alloced[j+8] = 0x5A;
            alloced[j+9] = 0x5A;
        }
        else if (i < gUnknown_0203CF1C->currPageIndex)
        {
            alloced[j+0] = 0x46;
            alloced[j+1] = 0x47;
            alloced[j+8] = 0x56;
            alloced[j+9] = 0x57;
        }
        else if (i == gUnknown_0203CF1C->currPageIndex)
        {
            if (i != gUnknown_0203CF1C->maxPageIndex)
            {
                alloced[j+0] = 0x41;
                alloced[j+1] = 0x42;
                alloced[j+8] = 0x51;
                alloced[j+9] = 0x52;
            }
            else
            {
                alloced[j+0] = 0x4B;
                alloced[j+1] = 0x4C;
                alloced[j+8] = 0x5B;
                alloced[j+9] = 0x5C;
            }
        }
        else if (i != gUnknown_0203CF1C->maxPageIndex)
        {
            alloced[j+0] = 0x43;
            alloced[j+1] = 0x44;
            alloced[j+8] = 0x53;
            alloced[j+9] = 0x54;
        }
        else
        {
            alloced[j+0] = 0x48;
            alloced[j+1] = 0x49;
            alloced[j+8] = 0x58;
            alloced[j+9] = 0x59;
        }
    }
    CopyToBgTilemapBufferRect_ChangePalette(3, alloced, 11, 0, 8, 2, 16);
    schedule_bg_copy_tilemap_to_vram(3);
    Free(alloced);
}

void sub_81C1CB0(const struct UnkStruct_61CC04 *unkStruct, u16 *dest, u8 c, bool8 d)
{
    u16 i;
    u16 *alloced = Alloc(unkStruct->field_6 * 2 * unkStruct->field_7);
    CpuFill16(unkStruct->field_4, alloced, unkStruct->field_6 * 2 * unkStruct->field_7);
    if (unkStruct->field_6 != c)
    {
        if (!d)
        {
            for (i = 0; i < unkStruct->field_7; i++)
            {
                CpuCopy16(&unkStruct->ptr[c + unkStruct->field_6 * i], &alloced[unkStruct->field_6 * i], (unkStruct->field_6 - c) * 2);
            }
        }
        else
        {
            for (i = 0; i < unkStruct->field_7; i++)
            {
                CpuCopy16(&unkStruct->ptr[unkStruct->field_6 * i], &alloced[c + unkStruct->field_6 * i], (unkStruct->field_6 - c) * 2);
            }
        }
    }
    for (i = 0; i < unkStruct->field_7; i++)
    {
        CpuCopy16(&alloced[unkStruct->field_6 * i], &dest[(unkStruct->field_9 + i) * 32 + unkStruct->field_8], unkStruct->field_6 * 2);
    }
    Free(alloced);
}

void sub_81C1DA4(u16 a, s16 b)
{
    if (b > gUnknown_0861CC04.field_6)
        b = gUnknown_0861CC04.field_6;
    if (b == 0 || b == gUnknown_0861CC04.field_6)
    {
        sub_81C1CB0(&gUnknown_0861CC04, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0], b, 1);
    }
    else
    {
        u8 taskId = FindTaskIdByFunc(sub_81C1E20);
        if (taskId == 0xFF)
        {
            taskId = CreateTask(sub_81C1E20, 8);
        }
        gTasks[taskId].data[0] = b;
        gTasks[taskId].data[1] = a;
    }
}

void sub_81C1E20(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1] += data[0];
    if (data[1] < 0)
    {
        data[1] = 0;
    }
    else if (data[1] > gUnknown_0861CC04.field_6)
    {
        data[1] = gUnknown_0861CC04.field_6;
    }
    sub_81C1CB0(&gUnknown_0861CC04, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_BATTLE_MOVES][0], data[1], 1);
    if (data[1] <= 0 || data[1] >= gUnknown_0861CC04.field_6)
    {
        if (data[0] < 0)
        {
            if (gUnknown_0203CF1C->currPageIndex == 2)
                PutWindowTilemap(14);
        }
        else
        {
            if (!gSprites[gUnknown_0203CF1C->spriteIds[2]].invisible)
                PutWindowTilemap(13);
            PutWindowTilemap(19);
        }
        schedule_bg_copy_tilemap_to_vram(0);
        DestroyTask(taskId);
    }
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81C1EFC(u16 a, s16 b, u16 move)
{
    if (b > gUnknown_0861CC10.field_6)
        b = gUnknown_0861CC10.field_6;
    if (b == 0 || b == gUnknown_0861CC10.field_6)
        sub_81C1CB0(&gUnknown_0861CC10, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][0], b, 1);
    else
    {
        u8 taskId = FindTaskIdByFunc(sub_81C1F80);
        if (taskId == 0xFF)
            taskId = CreateTask(sub_81C1F80, 8);
        gTasks[taskId].data[0] = b;
        gTasks[taskId].data[1] = a;
        gTasks[taskId].data[2] = move;
    }
}

void sub_81C1F80(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1] += data[0];
    if (data[1] < 0)
    {
        data[1] = 0;
    }
    else if (data[1] > gUnknown_0861CC10.field_6)
    {
        data[1] = gUnknown_0861CC10.field_6;
    }
    sub_81C1CB0(&gUnknown_0861CC10, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][0], data[1], 1);
    if (data[1] <= 0 || data[1] >= gUnknown_0861CC10.field_6)
    {
        if (data[0] < 0)
        {
            if (gUnknown_0203CF1C->currPageIndex == 3 && FuncIsActiveTask(sub_81C0B8C) == 0)
                PutWindowTilemap(15);
            sub_81C240C(data[2]);
        }
        else
        {
            if (!gSprites[gUnknown_0203CF1C->spriteIds[2]].invisible)
            {
                PutWindowTilemap(13);
            }
            PutWindowTilemap(19);
        }
        schedule_bg_copy_tilemap_to_vram(0);
        DestroyTask(taskId);
    }
    schedule_bg_copy_tilemap_to_vram(1);
    schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81C2074(u16 a, s16 b)
{
    if (b > gUnknown_0861CBEC.field_6)
        b = gUnknown_0861CBEC.field_6;
    if (b == 0 || b == gUnknown_0861CBEC.field_6)
    {
        sub_81C1CB0(&gUnknown_0861CBEC, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][0], b, 0);
        sub_81C1CB0(&gUnknown_0861CBF8, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][0], b, 0);
    }
    else
    {
        u8 taskId = CreateTask(sub_81C20F0, 8);
        gTasks[taskId].data[0] = b;
        gTasks[taskId].data[1] = a;
    }
}

void sub_81C20F0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    data[1] += data[0];
    if (data[1] < 0)
        data[1] = 0;
    else if (data[1] > gUnknown_0861CBEC.field_6)
        data[1] = gUnknown_0861CBEC.field_6;
    sub_81C1CB0(&gUnknown_0861CBEC, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][0], data[1], 0);
    sub_81C1CB0(&gUnknown_0861CBF8, gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][0], data[1], 0);
    schedule_bg_copy_tilemap_to_vram(3);
    if (data[1] <= 0 || data[1] >= gUnknown_0861CBEC.field_6)
    {
        if (data[0] < 0)
        {
            CreateSetStatusSprite();
            PutWindowTilemap(13);
            schedule_bg_copy_tilemap_to_vram(0);
        }
        DestroyTask(taskId);
    }
}

void sub_81C2194(u16 *output, u16 palette, bool8 c)
{
    u16 i;
    u32 var;
    palette <<= 12;
    var = 0x56A;

    if (c == 0)
    {
        for (i = 0; i < 20; i++)
        {
            output[var + i] = gSummaryScreenWindow_Tilemap[i] + palette;
            output[var + i + 0x20] = gSummaryScreenWindow_Tilemap[i] + palette;
            output[var + i + 0x40] = gSummaryScreenWindow_Tilemap[i + 20] + palette;
        }
    }
    else
    {
        for (i = 0; i < 20; i++)
        {
            output[var + i] = gSummaryScreenWindow_Tilemap[i + 20] + palette;
            output[var + i + 0x20] = gSummaryScreenWindow_Tilemap[i + 40] + palette;
            output[var + i + 0x40] = gSummaryScreenWindow_Tilemap[i + 40] + palette;
        }
    }
}

void sub_81C2228(struct Pokemon *mon)
{
    if (!CheckPartyPokerus(mon, 0) && CheckPartyHasHadPokerus(mon, 0))
    {
        gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][0][0x223] = 0x2C;
        gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][1][0x223] = 0x2C;
    }
    else
    {
        gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][0][0x223] = 0x81A;
        gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_INFO][1][0x223] = 0x81A;
    }
    schedule_bg_copy_tilemap_to_vram(3);
}

void sub_81C228C(bool8 isMonShiny)
{
    if (!isMonShiny)
        sub_8199C30(3, 1, 4, 8, 8, 0);
    else
        sub_8199C30(3, 1, 4, 8, 8, 5);
    schedule_bg_copy_tilemap_to_vram(3);
}

void sub_81C22CC(struct Pokemon *unused)
{
    s64 r6r7;
    struct PokeSummary *summary = &gUnknown_0203CF1C->summary;
    u16 *r9;
    u8 i;

    if (summary->level < MAX_MON_LEVEL)
    {
        u32 r1 = gExperienceTables[gBaseStats[summary->species].growthRate][summary->level + 1] - gExperienceTables[gBaseStats[summary->species].growthRate][summary->level];
        u32 r4 = summary->exp - gExperienceTables[gBaseStats[summary->species].growthRate][summary->level];

        r6r7 = r4 * 64 / r1;
        if (r6r7 == 0 && r4 != 0)
            r6r7 = 1;
    }
    else
    {
        r6r7 = 0;
    }

    r9 = &gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_SKILLS][1][0x255];
    for (i = 0; i < 8; i++)
    {
        if (r6r7 > 7)
            r9[i] = 0x206A;
        else
            r9[i] = 0x2062 + (r6r7 % 8);
        r6r7 -= 8;
        if (r6r7 < 0)
            r6r7 = 0;
    }

    if (GetBgTilemapBuffer(1) == gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_SKILLS][0])
        schedule_bg_copy_tilemap_to_vram(1);
    else
        schedule_bg_copy_tilemap_to_vram(2);
}

void sub_81C240C(u16 move)
{
    u16 *tilemap = gUnknown_0203CF1C->bgTilemapBuffers[PSS_PAGE_CONTEST_MOVES][1];
    u8 i;
    u8 effectValue;

    if (move != MOVE_NONE)
    {
        effectValue = gContestEffects[gContestMoves[move].effect].appeal;
        
        if (effectValue != 0xFF)
            effectValue /= 10;
        
        for (i = 0; i < 8; i++)
        {
            if (effectValue != 0xFF && i < effectValue)
            {
                tilemap[(i / 4 * 32) + (i & 3) + 0x1E6] = 0x103A;
            }
            else
            {
                tilemap[(i / 4 * 32) + (i & 3) + 0x1E6] = 0x1039;
            }
        }

        effectValue = gContestEffects[gContestMoves[move].effect].jam;

        if (effectValue != 0xFF)
            effectValue /= 10;
        
        for (i = 0; i < 8; i++)
        {
            if (effectValue != 0xFF && i < effectValue)
            {
                tilemap[(i / 4 * 32) + (i & 3) + 0x226] = 0x103C;
            }
            else
            {
                tilemap[(i / 4 * 32) + (i & 3) + 0x226] = 0x103D;
            }
        }
    }
}

void sub_81C2524(void)
{
    if (gUnknown_0203CF1C->summary.isEgg)
        ChangeBgX(3, 0x10000, 0);
    else
        ChangeBgX(3, 0, 0);
}

void sub_81C2554(void)
{
    u8 i;
    InitWindows(gUnknown_0861CC24);
    DeactivateAllTextPrinters();

    for (i = 0; i < 20; i++)
    {
        FillWindowPixelBuffer(i, 0);
    }
    for (i = 0; i < 8; i++)
    {
        gUnknown_0203CF1C->windowIds[i] = 0xFF;
    }
}

static void SummaryScreen_PrintTextOnWindow(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId)
{
    AddTextPrinterParameterized2(windowId, 1, x, y, 0, lineSpacing, sTextColors_861CD2C[colorId], 0, string);
}

void sub_81C25E8(void)
{
    FillWindowPixelBuffer(17, 0);
    FillWindowPixelBuffer(18, 0);
    FillWindowPixelBuffer(19, 0);
    if (!gUnknown_0203CF1C->summary.isEgg)
        sub_81C2628();
    else
        sub_81C2794();
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_81C2628(void)
{
    u8 strArray[16];
    struct Pokemon *mon = &gUnknown_0203CF1C->currentMon;
    struct PokeSummary *summary = &gUnknown_0203CF1C->summary;
    u16 dexNum = SpeciesToPokedexNum(summary->species);
    if (dexNum != 0xFFFF)
    {
        StringCopy(gStringVar1, &gText_UnkCtrlF908Clear01[0]);
        ConvertIntToDecimalStringN(gStringVar2, dexNum, 2, 3);
        StringAppend(gStringVar1, gStringVar2);
        if (!IsMonShiny(mon))
        {
            SummaryScreen_PrintTextOnWindow(17, gStringVar1, 0, 1, 0, 1);
            sub_81C228C(FALSE);
        }
        else
        {
            SummaryScreen_PrintTextOnWindow(17, gStringVar1, 0, 1, 0, 7);
            sub_81C228C(TRUE);
        }
        PutWindowTilemap(17);
    }
    else
    {
        ClearWindowTilemap(17);
        if (!IsMonShiny(mon))
            sub_81C228C(FALSE);
        else
            sub_81C228C(TRUE);
    }
    StringCopy(gStringVar1, &gText_LevelSymbol[0]);
    ConvertIntToDecimalStringN(gStringVar2, summary->level, 0, 3);
    StringAppend(gStringVar1, gStringVar2);
    SummaryScreen_PrintTextOnWindow(19, gStringVar1, 0x18, 17, 0, 1);
    GetMonNickname(mon, gStringVar1);
    SummaryScreen_PrintTextOnWindow(18, gStringVar1, 0, 1, 0, 1);
    strArray[0] = CHAR_SLASH;
    StringCopy(&strArray[1], &gSpeciesNames[summary->species2][0]);
    SummaryScreen_PrintTextOnWindow(19, &strArray[0], 0, 1, 0, 1);
    sub_81C27DC(mon, summary->species2);
    PutWindowTilemap(18);
    PutWindowTilemap(19);
}

void sub_81C2794(void)
{
    GetMonNickname(&gUnknown_0203CF1C->currentMon, gStringVar1);
    SummaryScreen_PrintTextOnWindow(18, gStringVar1, 0, 1, 0, 1);
    PutWindowTilemap(18);
    ClearWindowTilemap(17);
    ClearWindowTilemap(19);
}

void sub_81C27DC(struct Pokemon *mon, u16 a)
{
    if (a != SPECIES_NIDORAN_M && a != SPECIES_NIDORAN_F)
    {
        u8 gender = GetMonGender(mon);
        switch (gender)
        {
            case MON_MALE:
                SummaryScreen_PrintTextOnWindow(19, &gText_MaleSymbol[0], 57, 17, 0, 3);
                break;
            case MON_FEMALE:
                SummaryScreen_PrintTextOnWindow(19, &gText_FemaleSymbol[0], 57, 17, 0, 4);
                break;
        }
    }
}

void PrintAOrBButtonIcon(u8 windowId, bool8 bButton, u32 x)
{
    BlitBitmapToWindow(windowId, (bButton) ? gUnknown_0861CDD3 : gUnknown_0861CDD3 - 0x80, x, 0, 16, 16);
}

static void PrintPageNamesAndStatsPage(void)
{
    int stringXPos;
    int iconXPos;
    int statsXPos;

    SummaryScreen_PrintTextOnWindow(0, gText_PkmnInfo, 2, 1, 0, 1);
    SummaryScreen_PrintTextOnWindow(1, gText_PkmnSkills, 2, 1, 0, 1);
    SummaryScreen_PrintTextOnWindow(2, gText_BattleMoves, 2, 1, 0, 1);
    SummaryScreen_PrintTextOnWindow(3, gText_ContestMoves, 2, 1, 0, 1);

    stringXPos = GetStringRightAlignXOffset(1, gText_Cancel2, 62);
    iconXPos = stringXPos - 16;
    if (iconXPos < 0)
        iconXPos = 0;
    PrintAOrBButtonIcon(4, FALSE, iconXPos);
    SummaryScreen_PrintTextOnWindow(4, gText_Cancel2, stringXPos, 1, 0, 0);
    
    stringXPos = GetStringRightAlignXOffset(1, gText_Info, 0x3E);
    iconXPos = stringXPos - 16;
    if (iconXPos < 0)
        iconXPos = 0;
    PrintAOrBButtonIcon(5, FALSE, iconXPos);
    SummaryScreen_PrintTextOnWindow(5, gText_Info, stringXPos, 1, 0, 0);
    
    stringXPos = GetStringRightAlignXOffset(1, gText_Switch, 0x3E);
    iconXPos = stringXPos - 16;
    if (iconXPos < 0)
        iconXPos = 0;
    PrintAOrBButtonIcon(6, FALSE, iconXPos);
    SummaryScreen_PrintTextOnWindow(6, gText_Switch, stringXPos, 1, 0, 0);
    
    SummaryScreen_PrintTextOnWindow(8, gText_RentalPkmn, 0, 1, 0, 1);
    SummaryScreen_PrintTextOnWindow(9, gText_TypeSlash, 0, 1, 0, 0);
    statsXPos = 6 + GetStringCenterAlignXOffset(1, gText_HP4, 42);
    SummaryScreen_PrintTextOnWindow(10, gText_HP4, statsXPos, 1, 0, 1);
    statsXPos = 6 + GetStringCenterAlignXOffset(1, gText_Attack3, 42);
    SummaryScreen_PrintTextOnWindow(10, gText_Attack3, statsXPos, 17, 0, 1);
    statsXPos = 6 + GetStringCenterAlignXOffset(1, gText_Defense3, 42);
    SummaryScreen_PrintTextOnWindow(10, gText_Defense3, statsXPos, 33, 0, 1);
    statsXPos = 2 + GetStringCenterAlignXOffset(1, gText_SpAtk4, 36);
    SummaryScreen_PrintTextOnWindow(11, gText_SpAtk4, statsXPos, 1, 0, 1);
    statsXPos = 2 + GetStringCenterAlignXOffset(1, gText_SpDef4, 36);
    SummaryScreen_PrintTextOnWindow(11, gText_SpDef4, statsXPos, 17, 0, 1);
    statsXPos = 2 + GetStringCenterAlignXOffset(1, gText_Speed2, 36);
    SummaryScreen_PrintTextOnWindow(11, gText_Speed2, statsXPos, 33, 0, 1);
    SummaryScreen_PrintTextOnWindow(12, gText_ExpPoints, 6, 1, 0, 1);
    SummaryScreen_PrintTextOnWindow(12, gText_NextLv, 6, 17, 0, 1);
    SummaryScreen_PrintTextOnWindow(13, gText_Status, 2, 1, 0, 1);
    SummaryScreen_PrintTextOnWindow(14, gText_Power, 0, 1, 0, 1);
    SummaryScreen_PrintTextOnWindow(14, gText_Accuracy2, 0, 17, 0, 1);
    SummaryScreen_PrintTextOnWindow(15, gText_Appeal, 0, 1, 0, 1);
    SummaryScreen_PrintTextOnWindow(15, gText_Jam, 0, 17, 0, 1);
}

void sub_81C2AFC(u8 a)
{
    u8 i;

    ClearWindowTilemap(0);
    ClearWindowTilemap(1);
    ClearWindowTilemap(2);
    ClearWindowTilemap(3);

    switch (a)
    {
        case 0:
            PutWindowTilemap(0);
            PutWindowTilemap(4);
            if (sub_81A6BF4() == TRUE || sub_81B9E94() == TRUE)
                PutWindowTilemap(8);
            PutWindowTilemap(9);
            break;
        case 1:
            PutWindowTilemap(1);
            PutWindowTilemap(10);
            PutWindowTilemap(11);
            PutWindowTilemap(12);
            break;
        case 2:
            PutWindowTilemap(2);
            if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
            {
                if (gUnknown_0203CF1C->newMove != MOVE_NONE || gUnknown_0203CF1C->firstMoveIndex != MAX_MON_MOVES)
                    PutWindowTilemap(14);
            }
            else
            {
                PutWindowTilemap(5);
            }
            break;
        case 3:
            PutWindowTilemap(3);
            if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
            {
                if (gUnknown_0203CF1C->newMove != MOVE_NONE || gUnknown_0203CF1C->firstMoveIndex != MAX_MON_MOVES)
                    PutWindowTilemap(15);
            }
            else
            {
                PutWindowTilemap(5);
            }
            break;
    }

    for (i = 0; i < 8; i++)
    {
        PutWindowTilemap(gUnknown_0203CF1C->windowIds[i]);
    }

    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_81C2C38(u8 a)
{
    u8 i;
    switch (a)
    {
        case 0:
            ClearWindowTilemap(4);
            if (sub_81A6BF4() == TRUE || sub_81B9E94() == TRUE)
                ClearWindowTilemap(8);
            ClearWindowTilemap(9);
            break;
        case 1:
            ClearWindowTilemap(10);
            ClearWindowTilemap(11);
            ClearWindowTilemap(12);
            break;
        case 2:
            if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
            {
                if (gUnknown_0203CF1C->newMove != MOVE_NONE || gUnknown_0203CF1C->firstMoveIndex != MAX_MON_MOVES)
                    ClearWindowTilemap(14);
            }
            else
            {
                ClearWindowTilemap(5);
            }
            break;
        case 3:
            if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
            {
                if (gUnknown_0203CF1C->newMove != MOVE_NONE || gUnknown_0203CF1C->firstMoveIndex != MAX_MON_MOVES)
                    ClearWindowTilemap(15);
            }
            else
            {
                ClearWindowTilemap(5);
            }
            break;
    }

    for (i = 0; i < 8; i++)
    {
        SummaryScreen_RemoveWindowByIndex(i);
    }

    schedule_bg_copy_tilemap_to_vram(0);
}

u8 AddWindowFromTemplateList(const struct WindowTemplate *template, u8 templateId)
{
    u8 *windowIdPtr = &(gUnknown_0203CF1C->windowIds[templateId]);
    if (*windowIdPtr == 0xFF)
    {
        *windowIdPtr = AddWindow(&template[templateId]);
        FillWindowPixelBuffer(*windowIdPtr, 0);
    }
    return *windowIdPtr;
}

void SummaryScreen_RemoveWindowByIndex(u8 windowIndex)
{
    u8 *windowIdPtr = &(gUnknown_0203CF1C->windowIds[windowIndex]);
    if (*windowIdPtr != 0xFF)
    {
        ClearWindowTilemap(*windowIdPtr);
        RemoveWindow(*windowIdPtr);
        *windowIdPtr = 0xFF;
    }
}

void sub_81C2D9C(u8 pageIndex)
{
    u16 i;
    for (i = 0; i < 8; i++)
    {
        if (gUnknown_0203CF1C->windowIds[i] != 0xFF)
            FillWindowPixelBuffer(gUnknown_0203CF1C->windowIds[i], 0);
    }
    gUnknown_0861CE54[pageIndex]();
}

void sub_81C2DE4(u8 pageIndex)
{
    CreateTask(gUnknown_0861CE64[pageIndex], 16);
}

void sub_81C2E00(void)
{
    if (gUnknown_0203CF1C->summary.isEgg)
    {
        PrintEggOTName();
        PrintEggOTID();
        PrintEggState();
        PrintEggMemo();
    }
    else
    {
        PrintMonOTName();
        PrintMonOTID();
        PrintMonAbilityName();
        PrintMonAbilityDescription();
        BufferMonTrainerMemo();
        PrintMonTrainerMemo();
    }
}

void sub_81C2E40(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
        case 1:
            PrintMonOTName();
            break;
        case 2:
            PrintMonOTID();
            break;
        case 3:
            PrintMonAbilityName();
            break;
        case 4:
            PrintMonAbilityDescription();
            break;
        case 5:
            BufferMonTrainerMemo();
            break;
        case 6:
            PrintMonTrainerMemo();
            break;
        case 7:
            DestroyTask(taskId);
            return;
    }
    data[0]++;
}

void PrintMonOTName(void)
{
    u8 windowId;
    int x;
    if (sub_81A6BF4() != TRUE && sub_81B9E94() != TRUE)
    {
        windowId = AddWindowFromTemplateList(gUnknown_0861CCCC, 0);
        SummaryScreen_PrintTextOnWindow(windowId, gText_OTSlash, 0, 1, 0, 1);
        x = GetStringWidth(1, gText_OTSlash, 0);
        if (gUnknown_0203CF1C->summary.OTGender == 0)
            SummaryScreen_PrintTextOnWindow(windowId, gUnknown_0203CF1C->summary.OTName, x, 1, 0, 5);
        else
            SummaryScreen_PrintTextOnWindow(windowId, gUnknown_0203CF1C->summary.OTName, x, 1, 0, 6);
    }
}

void PrintMonOTID(void)
{
    int xPos;
    if (sub_81A6BF4() != TRUE && sub_81B9E94() != TRUE)
    {
        ConvertIntToDecimalStringN(StringCopy(gStringVar1, gText_UnkCtrlF907F908), (u16)gUnknown_0203CF1C->summary.OTID, 2, 5);
        xPos = GetStringRightAlignXOffset(1, gStringVar1, 56);
        SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCCC, 1), gStringVar1, xPos, 1, 0, 1);
    }
}

void PrintMonAbilityName(void)
{
    u8 ability = GetAbilityBySpecies(gUnknown_0203CF1C->summary.species, gUnknown_0203CF1C->summary.altAbility);
    SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCCC, 2), gAbilityNames[ability], 0, 1, 0, 1);
}

void PrintMonAbilityDescription(void)
{
    u8 ability = GetAbilityBySpecies(gUnknown_0203CF1C->summary.species, gUnknown_0203CF1C->summary.altAbility);
    SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCCC, 2), gAbilityDescriptionPointers[ability], 0, 17, 0, 0);
}

void BufferMonTrainerMemo(void)
{
    struct PokeSummary *sum = &gUnknown_0203CF1C->summary;
    const u8 *text;
    
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gUnknown_0861CE74);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gUnknown_0861CE7B);
    BufferNatureString();

    if (sub_81A6BF4() == TRUE || sub_81B9E94() == TRUE || IsInGamePartnerMon() == TRUE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_XNature);
    }
    else
    {
        u8 *metLevelString = Alloc(32);
        u8 *metLocationString = Alloc(32);
        GetMetLevelString(metLevelString);

        if (sum->metLocation < MAPSEC_NONE)
        {
            sub_8124610(metLocationString, sum->metLocation);
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
        }

        if (DoesMonOTMatchOwner() == TRUE)
        {
            if (sum->metLevel == 0)
                text = (sum->metLocation >= MAPSEC_NONE) ? gText_XNatureHatchedSomewhereAt : gText_XNatureHatchedAtYZ;
            else
                text = (sum->metLocation >= MAPSEC_NONE) ? gText_XNatureMetSomewhereAt : gText_XNatureMetAtYZ;
        }
        else if (sum->metLocation == MAPSEC_FATEFUL_ENCOUNTER)
        {
            text = gText_XNatureFatefulEncounter;
        }
        else if (sum->metLocation != MAPSEC_IN_GAME_TRADE && MonCameFromGBAGames())
        {
            text = (sum->metLocation >= MAPSEC_NONE) ? gText_XNatureObtainedInTrade : gText_XNatureProbablyMetAt;
        }
        else
        {
            text = gText_XNatureObtainedInTrade;
        }

        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, text);
        Free(metLevelString);
        Free(metLocationString);
    }
}

void PrintMonTrainerMemo(void)
{
    SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCCC, 3), gStringVar4, 0, 1, 0, 0);
}

void BufferNatureString(void)
{
    struct UnkSummaryStruct *sumStruct = gUnknown_0203CF1C;
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gNatureNamePointers[sumStruct->summary.nature]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(5, gText_EmptyString5);
}

void GetMetLevelString(u8 *output)
{
    u8 level = gUnknown_0203CF1C->summary.metLevel;
    if (level == 0)
        level = EGG_HATCH_LEVEL;
    ConvertIntToDecimalStringN(output, level, 0, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, output);
}

bool8 DoesMonOTMatchOwner(void)
{
    struct PokeSummary *sum = &gUnknown_0203CF1C->summary;
    u32 trainerId;
    u8 gender;

    if (gUnknown_0203CF1C->monList.mons == gEnemyParty)
    {
        u8 multiID = GetMultiplayerId() ^ 1;
        trainerId = (u16)gLinkPlayers[multiID].trainerId;
        gender = gLinkPlayers[multiID].gender;
        StringCopy(gStringVar1, gLinkPlayers[multiID].name);
    }
    else
    {
        trainerId = GetPlayerIDAsU32() & 0xFFFF;
        gender = gSaveBlock2Ptr->playerGender;
        StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    }
    if (gender != sum->OTGender || trainerId != (sum->OTID & 0xFFFF) || StringCompareWithoutExtCtrlCodes(gStringVar1, sum->OTName))
    {
        return FALSE;
    }
    return TRUE;
}

bool8 MonCameFromGBAGames(void)
{
    struct PokeSummary *sum = &gUnknown_0203CF1C->summary;
    if (sum->metGame > 0 && sum->metGame <= VERSION_LEAF_GREEN)
        return TRUE;
    return FALSE;
}

bool8 MonCameFromRSE(void)
{
    struct PokeSummary *sum = &gUnknown_0203CF1C->summary;
    if (sum->metGame > 0 && sum->metGame <= VERSION_EMERALD)
        return TRUE;
    return FALSE;
}

bool8 IsInGamePartnerMon(void)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && gMain.inBattle)
    {
        if (gUnknown_0203CF1C->curMonIndex == 1 || gUnknown_0203CF1C->curMonIndex == 4 || gUnknown_0203CF1C->curMonIndex == 5)
            return TRUE;
    }
    return FALSE;
}

void PrintEggOTName(void)
{
    u32 windowId = AddWindowFromTemplateList(gUnknown_0861CCCC, 0);
    u32 width = GetStringWidth(1, gText_OTSlash, 0);
    SummaryScreen_PrintTextOnWindow(windowId, gText_OTSlash, 0, 1, 0, 1);
    SummaryScreen_PrintTextOnWindow(windowId, gText_FiveMarks, width, 1, 0, 1);
}

void PrintEggOTID(void)
{
    int x;
    StringCopy(gStringVar1, gText_UnkCtrlF907F908);
    StringAppend(gStringVar1, gText_FiveMarks);
    x = GetStringRightAlignXOffset(1, gStringVar1, 56);
    SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCCC, 1), gStringVar1, x, 1, 0, 1);
}

void PrintEggState(void)
{
    const u8 *text;
    struct PokeSummary *sum = &gUnknown_0203CF1C->summary;

    if (gUnknown_0203CF1C->summary.sanity == TRUE)
        text = gText_EggWillTakeALongTime;
    else if (sum->friendship <= 5)
        text = gText_EggAboutToHatch;
    else if (sum->friendship <= 10)
        text = gText_EggWillHatchSoon;
    else if (sum->friendship <= 40)
        text = gText_EggWillTakeSomeTime;
    else
        text = gText_EggWillTakeALongTime;
    
    SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCCC, 2), text, 0, 1, 0, 0);
}

void PrintEggMemo(void)
{
    const u8 *text;
    struct PokeSummary *sum = &gUnknown_0203CF1C->summary;

    if (gUnknown_0203CF1C->summary.sanity != 1)
    {
        if (sum->metLocation == MAPSEC_FATEFUL_ENCOUNTER)
            text = gText_PeculiarEggNicePlace;
        else if (MonCameFromGBAGames() == FALSE || DoesMonOTMatchOwner() == FALSE)
            text = gText_PeculiarEggTrade;
        else if (sum->metLocation == MAPSEC_SPECIAL_EGG)
            text = (MonCameFromRSE() == TRUE) ? gText_EggFromHotSprings : gText_EggFromTraveler;
        else
            text = gText_OddEggFoundByCouple;
    }
    else
    {
        text = gText_OddEggFoundByCouple;
    }

    SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCCC, 3), text, 0, 1, 0, 0);
}

void sub_81C3530(void)
{
    PrintHeldItemName();
    PrintRibbonCount();
    BufferLeftColumnStats();
    PrintLeftColumnStats();
    BufferRightColumnStats();
    PrintRightColumnStats();
    PrintExpPointsNextLevel();
}

void sub_81C3554(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 1:
            PrintHeldItemName();
            break;
        case 2:
            PrintRibbonCount();
            break;
        case 3:
            BufferLeftColumnStats();
            break;
        case 4:
            PrintLeftColumnStats();
            break;
        case 5:
            BufferRightColumnStats();
            break;
        case 6:
            PrintRightColumnStats();
            break;
        case 7:
            PrintExpPointsNextLevel();
            break;
        case 8:
            DestroyTask(taskId);
            return;
    }
    data[0]++;
}

void PrintHeldItemName(void)
{
    const u8 *text;
    int offset;

    if (gUnknown_0203CF1C->summary.item == ITEM_ENIGMA_BERRY && sub_81B1250() == TRUE && (gUnknown_0203CF1C->curMonIndex == 1 || gUnknown_0203CF1C->curMonIndex == 4 || gUnknown_0203CF1C->curMonIndex == 5))
    {
        text = ItemId_GetName(ITEM_ENIGMA_BERRY);
    }
    else if (gUnknown_0203CF1C->summary.item == ITEM_NONE)
    {
        text = gText_None;
    }
    else
    {
        CopyItemName(gUnknown_0203CF1C->summary.item, gStringVar1);
        text = gStringVar1;
    }

    offset = GetStringCenterAlignXOffset(1, text, 72) + 6;
    SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCEC, 0), text, offset, 1, 0, 0);
}

void PrintRibbonCount(void)
{
    const u8 *text;
    int offset;

    if (gUnknown_0203CF1C->summary.ribbonCount == 0)
    {
        text = gText_None;
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, gUnknown_0203CF1C->summary.ribbonCount, 1, 2);
        StringExpandPlaceholders(gStringVar4, gText_RibbonsVar1);
        text = gStringVar4;
    }

    offset = GetStringCenterAlignXOffset(1, text, 70) + 6;
    SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCEC, 1), text, offset, 1, 0, 0);
}

void BufferLeftColumnStats(void)
{
    u8 *currentHPString = Alloc(8);
    u8 *maxHPString = Alloc(8);
    u8 *attackString = Alloc(8);
    u8 *defenseString = Alloc(8);

    ConvertIntToDecimalStringN(currentHPString, gUnknown_0203CF1C->summary.currentHP, 1, 3);
    ConvertIntToDecimalStringN(maxHPString, gUnknown_0203CF1C->summary.maxHP, 1, 3);
    ConvertIntToDecimalStringN(attackString, gUnknown_0203CF1C->summary.atk, 1, 7);
    ConvertIntToDecimalStringN(defenseString, gUnknown_0203CF1C->summary.def, 1, 7);
    
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, currentHPString);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, maxHPString);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, attackString);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, defenseString);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gUnknown_0861CE82);
    
    Free(currentHPString);
    Free(maxHPString);
    Free(attackString);
    Free(defenseString);
}

void PrintLeftColumnStats(void)
{
    SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCEC, 2), gStringVar4, 4, 1, 0, 0);
}

void BufferRightColumnStats(void)
{
    ConvertIntToDecimalStringN(gStringVar1, gUnknown_0203CF1C->summary.spatk, 1, 3);
    ConvertIntToDecimalStringN(gStringVar2, gUnknown_0203CF1C->summary.spdef, 1, 3);
    ConvertIntToDecimalStringN(gStringVar3, gUnknown_0203CF1C->summary.speed, 1, 3);
    
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar2);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gStringVar3);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gUnknown_0861CE8E);
}

void PrintRightColumnStats(void)
{
    SummaryScreen_PrintTextOnWindow(AddWindowFromTemplateList(gUnknown_0861CCEC, 3), gStringVar4, 2, 1, 0, 0);
}

void PrintExpPointsNextLevel(void)
{
    struct PokeSummary *sum = &gUnknown_0203CF1C->summary;
    u8 windowId = AddWindowFromTemplateList(gUnknown_0861CCEC, 4);
    int offset;
    u32 expToNextLevel;

    ConvertIntToDecimalStringN(gStringVar1, sum->exp, 1, 7);
    offset = GetStringRightAlignXOffset(1, gStringVar1, 42) + 2;
    SummaryScreen_PrintTextOnWindow(windowId, gStringVar1, offset, 1, 0, 0);

    if (sum->level < MAX_MON_LEVEL)
        expToNextLevel = gExperienceTables[gBaseStats[sum->species].growthRate][sum->level + 1] - sum->exp;
    else
        expToNextLevel = 0;
    
    ConvertIntToDecimalStringN(gStringVar1, expToNextLevel, 1, 6);
    offset = GetStringRightAlignXOffset(1, gStringVar1, 42) + 2;
    SummaryScreen_PrintTextOnWindow(windowId, gStringVar1, offset, 17, 0, 0);
}

void sub_81C3984(void)
{
    PrintMoveNameAndPP(0);
    PrintMoveNameAndPP(1);
    PrintMoveNameAndPP(2);
    PrintMoveNameAndPP(3);

    if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
    {
        PrintNewMoveDetailsOrCancelText();
        if (gUnknown_0203CF1C->firstMoveIndex == MAX_MON_MOVES)
        {
            if (gUnknown_0203CF1C->newMove != MOVE_NONE)
                PrintMoveDetails(gUnknown_0203CF1C->newMove);
        }
        else
        {
            PrintMoveDetails(gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->firstMoveIndex]);
        }
    }
}

void sub_81C39F0(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 1:
            PrintMoveNameAndPP(0);
            break;
        case 2:
            PrintMoveNameAndPP(1);
            break;
        case 3:
            PrintMoveNameAndPP(2);
            break;
        case 4:
            PrintMoveNameAndPP(3);
            break;
        case 5:
            if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
                PrintNewMoveDetailsOrCancelText();
            break;
        case 6:
            if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
            {
                if (gUnknown_0203CF1C->firstMoveIndex == MAX_MON_MOVES)
                    data[1] = gUnknown_0203CF1C->newMove;
                else
                    data[1] = gUnknown_0203CF1C->summary.moves[gUnknown_0203CF1C->firstMoveIndex];
            }
            break;
        case 7:
            if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
            {
                if (gUnknown_0203CF1C->newMove != MOVE_NONE || gUnknown_0203CF1C->firstMoveIndex != MAX_MON_MOVES)
                    PrintMoveDetails(data[1]);
            }
            break;
        case 8:
            DestroyTask(taskId);
            return;
    }
    data[0]++;
}

void PrintMoveNameAndPP(u8 moveIndex)
{
    u8 pp;
    u32 ppState;
    const u8 *text;
    u32 offset;
    struct UnkSummaryStruct *summaryStruct = gUnknown_0203CF1C;
    u8 moveNameWindowId = AddWindowFromTemplateList(gUnknown_0861CD14, 0);
    u8 ppValueWindowId = AddWindowFromTemplateList(gUnknown_0861CD14, 1);
    u16 move = summaryStruct->summary.moves[moveIndex];

    if (move != 0)
    {
        pp = CalculatePPWithBonus(move, summaryStruct->summary.ppBonuses, moveIndex);
        SummaryScreen_PrintTextOnWindow(moveNameWindowId, gMoveNames[move], 0, moveIndex * 16 + 1, 0, 1);
        ConvertIntToDecimalStringN(gStringVar1, summaryStruct->summary.pp[moveIndex], 1, 2);
        ConvertIntToDecimalStringN(gStringVar2, pp, 1, 2);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar2);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gUnknown_0861CE97);
        text = gStringVar4;
        ppState = GetCurrentPpToMaxPpState(summaryStruct->summary.pp[moveIndex], pp) + 9;
        offset = GetStringRightAlignXOffset(1, text, 44);
    }
    else
    {
        SummaryScreen_PrintTextOnWindow(moveNameWindowId, gText_OneDash, 0, moveIndex * 16 + 1, 0, 1);
        text = gText_TwoDashes;
        ppState = 12;
        offset = GetStringCenterAlignXOffset(1, text, 44);
    }

    SummaryScreen_PrintTextOnWindow(ppValueWindowId, text, offset, moveIndex * 16 + 1, 0, ppState);
}

void PrintMovePowerAndAccuracy(u16 moveIndex)
{
    const u8 *text;
    if (moveIndex != 0)
    {
        FillWindowPixelRect(14, 0, 53, 0, 19, 32);

        if (gBattleMoves[moveIndex].power < 2)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveIndex].power, 1, 3);
            text = gStringVar1;
        }

        SummaryScreen_PrintTextOnWindow(14, text, 53, 1, 0, 0);

        if (gBattleMoves[moveIndex].accuracy == 0)
        {
            text = gText_ThreeDashes;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[moveIndex].accuracy, 1, 3);
            text = gStringVar1;
        }

        SummaryScreen_PrintTextOnWindow(14, text, 53, 17, 0, 0);
    }
}

void sub_81C3D08(void)
{
    PrintMoveNameAndPP(0);
    PrintMoveNameAndPP(1);
    PrintMoveNameAndPP(2);
    PrintMoveNameAndPP(3);

    if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
    {
        PrintNewMoveDetailsOrCancelText();
        PrintContestMoveDescription(gUnknown_0203CF1C->firstMoveIndex);
    }
}

void sub_81C3D54(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s16 dataa = data[0] - 1;

    switch (dataa)
    {
        case 0:
            PrintMoveNameAndPP(0);
            break;
        case 1:
            PrintMoveNameAndPP(1);
            break;
        case 2:
            PrintMoveNameAndPP(2);
            break;
        case 3:
            PrintMoveNameAndPP(3);
            break;
        case 4:
            if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
                PrintNewMoveDetailsOrCancelText();
            break;
        case 5:
            if (gUnknown_0203CF1C->mode == PSS_MODE_SELECT_MOVE)
            {
                if (gUnknown_0203CF1C->newMove != MOVE_NONE || gUnknown_0203CF1C->firstMoveIndex != MAX_MON_MOVES)
                    PrintContestMoveDescription(gUnknown_0203CF1C->firstMoveIndex);
            }
            break;
        case 6:
            DestroyTask(taskId);
            return;
    }
    data[0]++;
}

void PrintContestMoveDescription(u8 moveSlot)
{
    u16 move;

    if (moveSlot == 4)
        move = gUnknown_0203CF1C->newMove;
    else
        move = gUnknown_0203CF1C->summary.moves[moveSlot];

    if (move != MOVE_NONE)
    {
        u8 windowId = AddWindowFromTemplateList(gUnknown_0861CD14, 2);
        SummaryScreen_PrintTextOnWindow(windowId, gContestEffectDescriptionPointers[gContestMoves[move].effect], 6, 1, 0, 0);
    }
}

void PrintMoveDetails(u16 move)
{
    u8 windowId = AddWindowFromTemplateList(gUnknown_0861CD14, 2);
    FillWindowPixelBuffer(windowId, 0);
    if (move != MOVE_NONE)
    {
        if (gUnknown_0203CF1C->currPageIndex == 2)
        {
            PrintMovePowerAndAccuracy(move);
            SummaryScreen_PrintTextOnWindow(windowId, gMoveDescriptionPointers[move - 1], 6, 1, 0, 0);
        }
        else
        {
            SummaryScreen_PrintTextOnWindow(windowId, gContestEffectDescriptionPointers[gContestMoves[move].effect], 6, 1, 0, 0);
        }
        PutWindowTilemap(windowId);
    }
    else
    {
        ClearWindowTilemap(windowId);
    }

    schedule_bg_copy_tilemap_to_vram(0);
}

void PrintNewMoveDetailsOrCancelText(void)
{
    u8 windowId1 = AddWindowFromTemplateList(gUnknown_0861CD14, 0);
    u8 windowId2 = AddWindowFromTemplateList(gUnknown_0861CD14, 1);

    if (gUnknown_0203CF1C->newMove == MOVE_NONE)
    {
        SummaryScreen_PrintTextOnWindow(windowId1, gText_Cancel, 0, 65, 0, 1);
    }
    else
    {
        u16 move = gUnknown_0203CF1C->newMove;

        if (gUnknown_0203CF1C->currPageIndex == 2)
            SummaryScreen_PrintTextOnWindow(windowId1, gMoveNames[move], 0, 65, 0, 6);
        else
            SummaryScreen_PrintTextOnWindow(windowId1, gMoveNames[move], 0, 65, 0, 5);

        ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].pp, 1, 2);
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar1);
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gUnknown_0861CE97);
        SummaryScreen_PrintTextOnWindow(windowId2, gStringVar4, GetStringRightAlignXOffset(1, gStringVar4, 0x2C), 0x41, 0, 12);
    }
}

void sub_81C4064(void)
{
    u8 windowId = AddWindowFromTemplateList(gUnknown_0861CD14, 0);
    FillWindowPixelRect(windowId, 0, 0, 66, 72, 16);
    CopyWindowToVram(windowId, 2);
}

void sub_81C40A0(u8 moveIndex1, u8 moveIndex2)
{
    u8 windowId1 = AddWindowFromTemplateList(gUnknown_0861CD14, 0);
    u8 windowId2 = AddWindowFromTemplateList(gUnknown_0861CD14, 1);

    FillWindowPixelRect(windowId1, 0, 0, moveIndex1 * 16, 0x48, 0x10);
    FillWindowPixelRect(windowId1, 0, 0, moveIndex2 * 16, 0x48, 0x10);

    FillWindowPixelRect(windowId2, 0, 0, moveIndex1 * 16, 0x30, 0x10);
    FillWindowPixelRect(windowId2, 0, 0, moveIndex2 * 16, 0x30, 0x10);

    PrintMoveNameAndPP(moveIndex1);
    PrintMoveNameAndPP(moveIndex2);
}

void sub_81C4154(void)
{
    u8 windowId = AddWindowFromTemplateList(gUnknown_0861CD14, 2);
    FillWindowPixelBuffer(windowId, 0);
    SummaryScreen_PrintTextOnWindow(windowId, gText_HMMovesCantBeForgotten2, 6, 1, 0, 0);
}

void sub_81C4190(void)
{
    u8 i;

    for (i = 0; i < 28; i++)
        gUnknown_0203CF1C->spriteIds[i] |= 0xFF;
}

void DestroySpriteInArray(u8 spriteArrayId)
{
    if (gUnknown_0203CF1C->spriteIds[spriteArrayId] != 0xFF)
    {
        DestroySprite(&gSprites[gUnknown_0203CF1C->spriteIds[spriteArrayId]]);
        gUnknown_0203CF1C->spriteIds[spriteArrayId] = 0xFF;
    }
}

void sub_81C4204(u8 spriteArrayId, bool8 invisible)
{
    gSprites[gUnknown_0203CF1C->spriteIds[spriteArrayId]].invisible = invisible;
}

void sub_81C424C(void)
{
    u8 i;

    for (i = 3; i < 28; i++)
    {
        if (gUnknown_0203CF1C->spriteIds[i] != 0xFF)
            sub_81C4204(i, TRUE);
    }
}

void sub_81C4280(void)
{
    switch (gUnknown_0203CF1C->currPageIndex)
    {
    case 0:
        sub_81C43A0();
        break;
    case 2:
        sub_81C4420();
        sub_81C44F0();
        break;
    case 3:
        sub_81C4484();
        sub_81C44F0();
        break;
    }
}

void sub_81C42C8(void)
{
    u8 i;

    for (i = 3; i < 8; i++)
    {
        if (gUnknown_0203CF1C->spriteIds[i] == 0xFF)
            gUnknown_0203CF1C->spriteIds[i] = CreateSprite(&gUnknown_0861CFC4, 0, 0, 2);

        sub_81C4204(i, TRUE);
    }
}

void sub_81C4318(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite = &gSprites[gUnknown_0203CF1C->spriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    sprite->oam.paletteNum = gUnknown_0861CFDC[typeId];
    sprite->pos1.x = x + 16;
    sprite->pos1.y = y + 8;
    sub_81C4204(spriteArrayId, FALSE);
}

void sub_81C43A0(void)
{
    struct PokeSummary *summary = &gUnknown_0203CF1C->summary;
    if (summary->isEgg)
    {
        sub_81C4318(TYPE_MYSTERY, 0x78, 0x30, 3);
        sub_81C4204(4, TRUE);
    }
    else
    {
        sub_81C4318(gBaseStats[summary->species].type1, 0x78, 0x30, 3);
        if (gBaseStats[summary->species].type1 != gBaseStats[summary->species].type2)
        {
            sub_81C4318(gBaseStats[summary->species].type2, 0xA0, 0x30, 4);
            sub_81C4204(4, FALSE);
        }
        else
        {
            sub_81C4204(4, TRUE);
        }
    }
}

void sub_81C4420(void)
{
    u8 i;
    struct PokeSummary *summary = &gUnknown_0203CF1C->summary;
    for (i = 0; i < 4; i++)
    {
        if (summary->moves[i] != MOVE_NONE)
            sub_81C4318(gBattleMoves[summary->moves[i]].type, 0x55, 0x20 + (i * 0x10), i + 3);
        else
            sub_81C4204(i + 3, TRUE);
    }
}

void sub_81C4484(void)
{
    u8 i;
    struct PokeSummary *summary = &gUnknown_0203CF1C->summary;
    for (i = 0; i < 4; i++)
    {
        if (summary->moves[i] != MOVE_NONE)
            sub_81C4318(NUMBER_OF_MON_TYPES + gContestMoves[summary->moves[i]].contestCategory, 0x55, 0x20 + (i * 0x10), i + 3);
        else
            sub_81C4204(i + 3, TRUE);
    }
}

void sub_81C44F0(void)
{
    if (gUnknown_0203CF1C->newMove == MOVE_NONE)
    {
        sub_81C4204(7, TRUE);
    }
    else
    {
        if (gUnknown_0203CF1C->currPageIndex == 2)
            sub_81C4318(gBattleMoves[gUnknown_0203CF1C->newMove].type, 0x55, 0x60, 7);
        else
            sub_81C4318(NUMBER_OF_MON_TYPES + gContestMoves[gUnknown_0203CF1C->newMove].contestCategory, 0x55, 0x60, 7);
    }
}

void sub_81C4568(u8 a0, u8 a1)
{
    struct Sprite *sprite1 = &gSprites[gUnknown_0203CF1C->spriteIds[a0 + 3]];
    struct Sprite *sprite2 = &gSprites[gUnknown_0203CF1C->spriteIds[a1 + 3]];

    u8 temp = sprite1->animNum;
    sprite1->animNum = sprite2->animNum;
    sprite2->animNum = temp;

    temp = sprite1->oam.paletteNum;
    sprite1->oam.paletteNum = sprite2->oam.paletteNum;
    sprite2->oam.paletteNum = temp;

    sprite1->animBeginning = TRUE;
    sprite1->animEnded = FALSE;
    sprite2->animBeginning = TRUE;
    sprite2->animEnded = FALSE;
}

u8 sub_81C45F4(struct Pokemon *mon, s16 *a1)
{
    const struct CompressedSpritePalette *pal;
    struct PokeSummary *summary = &gUnknown_0203CF1C->summary;

    switch (*a1)
    {
        default:
            return sub_81C47B4(mon);
        case 0:
            if (gMain.inBattle)
            {
                if (sub_80688F8(3, gUnknown_0203CF1C->curMonIndex))
                {
                    HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites[1], summary->species2, summary->pid);
                }
                else
                {
                    HandleLoadSpecialPokePic_2(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites[1], summary->species2, summary->pid);
                }
            }
            else
            {
                if (gMonSpritesGfxPtr != NULL)
                {
                    if (gUnknown_0203CF1C->monList.mons == gPlayerParty || gUnknown_0203CF1C->mode == PSS_MODE_UNK2 || gUnknown_0203CF1C->unk40EF == TRUE)
                    {
                        HandleLoadSpecialPokePic_2(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites[1], summary->species2, summary->pid);
                    }
                    else
                    {
                        HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites[1], summary->species2, summary->pid);
                    }
                }
                else
                {
                    if (gUnknown_0203CF1C->monList.mons == gPlayerParty || gUnknown_0203CF1C->mode == PSS_MODE_UNK2 || gUnknown_0203CF1C->unk40EF == TRUE)
                    {
                        HandleLoadSpecialPokePic_2(&gMonFrontPicTable[summary->species2], sub_806F4F8(0, 1), summary->species2, summary->pid);
                    }
                    else
                    {
                        HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[summary->species2], sub_806F4F8(0, 1), summary->species2, summary->pid);
                    }
                }
            }
            (*a1)++;
            return -1;
        case 1:
            pal = GetMonSpritePalStructFromOtIdPersonality(summary->species2, summary->OTID, summary->pid);
            LoadCompressedObjectPalette(pal);
            SetMultiuseSpriteTemplateToPokemon(pal->tag, 1);
            (*a1)++;
            return -1;
    }
}

void sub_81C4778(void)
{
    struct PokeSummary *summary = &gUnknown_0203CF1C->summary;
    if (!summary->isEgg)
    {
        if (ShouldPlayNormalMonCry(&gUnknown_0203CF1C->currentMon) == TRUE)
        {
            PlayCry3(summary->species2, 0, 0);
        }
        else
        {
            PlayCry3(summary->species2, 0, 11);
        }
    }
}

u8 sub_81C47B4(struct Pokemon *unused)
{
    struct PokeSummary *summary = &gUnknown_0203CF1C->summary;
    u8 spriteId = CreateSprite(&gMultiuseSpriteTemplate, 40, 64, 5);
    struct Sprite *sprite = &gSprites[spriteId];

    FreeSpriteOamMatrix(sprite);

    sprite->data[0] = summary->species2;
    sprite->data[2] = 0;
    gSprites[spriteId].callback = sub_81C4844;
    sprite->oam.priority = 0;

    if (!IsMonSpriteNotFlipped(summary->species2))
    {
        sprite->hFlip = TRUE;
    }
    else
    {
        sprite->hFlip = FALSE;
    }

    return spriteId;
}

void sub_81C4844(struct Sprite *sprite)
{
    struct PokeSummary *summary = &gUnknown_0203CF1C->summary;

    if (!gPaletteFade.active && sprite->data[2] != 1)
    {
        sprite->data[1] = IsMonSpriteNotFlipped(sprite->data[0]);
        sub_81C4778();
        PokemonSummaryDoMonAnimation(sprite, sprite->data[0], summary->isEgg);
    }
}

void SummaryScreen_SetUnknownTaskId(u8 a0)
{
    sUnknownTaskId = a0;
}

void SummaryScreen_DestroyUnknownTask(void)
{
    if (sUnknownTaskId != 0xFF)
    {
        DestroyTask(sUnknownTaskId);
        sUnknownTaskId = 0xFF;
    }
}

bool32 DoesSpriteHaveCallback(void)
{
    if (gSprites[gUnknown_0203CF1C->spriteIds[0]].callback == SpriteCallbackDummy)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void sub_81C48F0(void)
{
    u16 i;
    u16 paletteIndex;

    gSprites[gUnknown_0203CF1C->spriteIds[0]].animPaused = TRUE;
    gSprites[gUnknown_0203CF1C->spriteIds[0]].callback = SpriteCallbackDummy;
    sub_806EE98();

    paletteIndex = (gSprites[gUnknown_0203CF1C->spriteIds[0]].oam.paletteNum * 16) | 0x100;
    
    for (i = 0; i < 16; i++)
    {
        gPlttBufferUnfaded[(u16)(i + paletteIndex)] = gPlttBufferFaded[(u16)(i + paletteIndex)];
    }
}

void CreateMonMarkingsSprite(struct Pokemon *mon)
{
    struct Sprite *sprite = sub_811FF94(30003, 30003, gUnknown_0861D120);

    gUnknown_0203CF1C->markingsSprite = sprite;

    if (sprite != NULL)
    {
        StartSpriteAnim(sprite, GetMonData(mon, MON_DATA_MARKINGS));
        gUnknown_0203CF1C->markingsSprite->pos1.x = 60;
        gUnknown_0203CF1C->markingsSprite->pos1.y = 26;
        gUnknown_0203CF1C->markingsSprite->oam.priority = 1;
    }
}

void RemoveAndCreateMonMarkingsSprite(struct Pokemon *mon)
{
    DestroySprite(gUnknown_0203CF1C->markingsSprite);
    FreeSpriteTilesByTag(30003);
    CreateMonMarkingsSprite(mon);
}

void CreateCaughtBallSprite(struct Pokemon *mon)
{
    u8 ball = ItemIdToBallId(GetMonData(mon, MON_DATA_POKEBALL));

    LoadBallGfx(ball);
    gUnknown_0203CF1C->spriteIds[1] = CreateSprite(&gBallSpriteTemplates[ball], 16, 136, 0);
    gSprites[gUnknown_0203CF1C->spriteIds[1]].callback = SpriteCallbackDummy;
    gSprites[gUnknown_0203CF1C->spriteIds[1]].oam.priority = 3;
}

void CreateSetStatusSprite(void)
{
    u8 *spriteId = &gUnknown_0203CF1C->spriteIds[2];
    u8 anim;

    if (*spriteId == 0xFF)
    {
        *spriteId = CreateSprite(&gUnknown_0861D108, 64, 152, 0);
    }

    anim = sub_81B205C(&gUnknown_0203CF1C->currentMon);

    if (anim != 0)
    {
        StartSpriteAnim(&gSprites[*spriteId], anim - 1);
        sub_81C4204(2, FALSE);
    }
    else
    {
        sub_81C4204(2, TRUE);
    }
}

void sub_81C4AF8(u8 a0)
{
    u8 i;
    u8 *spriteIds = &gUnknown_0203CF1C->spriteIds[a0];

    if (gUnknown_0203CF1C->currPageIndex > 1)
    {
        u8 subsprite = 0;
        if (a0 == 8)
        {
            subsprite = 1;
        }

        for (i = 0; i < 10; i++)
        {
            spriteIds[i] = CreateSprite(&gUnknown_0861D084, i * 16 + 89, 40, subsprite);
            if (i == 0)
            {
                StartSpriteAnim(&gSprites[spriteIds[0]], 4);
            }
            else if (i == 9)
            {
                StartSpriteAnim(&gSprites[spriteIds[9]], 5);
            }
            else
            {
                StartSpriteAnim(&gSprites[spriteIds[i]], 6);
            }
            gSprites[spriteIds[i]].callback = sub_81C4BE4;
            gSprites[spriteIds[i]].data[0] = a0;
            gSprites[spriteIds[i]].data[1] = 0;
        }
    }
}

void sub_81C4BE4(struct Sprite *sprite)
{
    if (sprite->animNum > 3 && sprite->animNum < 7)
    {
        sprite->data[1] = (sprite->data[1] + 1) & 0x1F;
        if (sprite->data[1] > 24)
        {
            sprite->invisible = TRUE;
        }
        else
        {
            sprite->invisible = FALSE;
        }
    }
    else
    {
        sprite->data[1] = 0;
        sprite->invisible = FALSE;
    }

    if (sprite->data[0] == 8)
    {
        sprite->pos2.y = gUnknown_0203CF1C->firstMoveIndex * 16;
    }
    else
    {
        sprite->pos2.y = gUnknown_0203CF1C->secondMoveIndex * 16;
    }
}

void sub_81C4C60(u8 a0)
{
    u8 i;
    for (i = 0; i < 10; i++)
    {
        DestroySpriteInArray(a0 + i);
    }
}

void sub_81C4C84(u8 a0)
{
    u8 i;
    u8 *spriteIds = &gUnknown_0203CF1C->spriteIds[8];
    a0 *= 3;

    for (i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            StartSpriteAnim(&gSprites[spriteIds[0]], a0 + 4);
        }
        else if (i == 9)
        {
            StartSpriteAnim(&gSprites[spriteIds[9]], a0 + 5);
        }
        else
        {
            StartSpriteAnim(&gSprites[spriteIds[i]], a0 + 6);
        }
    }
}

void sub_81C4D18(u8 a0)
{
    u8 i;
    u8 *spriteIds = &gUnknown_0203CF1C->spriteIds[a0];

    for (i = 0; i < 10; i++)
    {
        gSprites[spriteIds[i]].data[1] = 0;
        gSprites[spriteIds[i]].invisible = FALSE;
    }
}
