#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "decompress.h"
#include "dma3.h"
#include "dynamic_placeholder_text_util.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "union_room_chat.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

struct UnionRoomChat
{
    u8 filler0[0x4];
    u16 unk4;
    u16 unk6;
    u8 filler8[0x2];
    u16 unkA;
    u8 fillerC[0x1];
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 currentPage;
    u8 unk11;
    u8 currentRow;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A[0x1F];
    u8 unk39[0x40];
    u8 unk79[0x40];
    u8 unkB9[UNION_ROOM_KB_ROW_COUNT][21];
    u8 filler18B[0x5];
    u8 unk190[0x28];
    u16 unk1B8;
};

struct UnionRoomChat2_Unk0
{
    bool32 (* unk0)(u8 *);
    u8 unk4;
    u8 unk5;
};

struct UnionRoomChat2
{
    struct UnionRoomChat2_Unk0 unk0[3];
    u16 unk18;
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
    s16 unk20;
    u8 unk22[0x106];
    u8 unk128[BG_SCREEN_SIZE];
    u8 unk928[BG_SCREEN_SIZE];
    u8 unk1128[BG_SCREEN_SIZE];
    u8 unk1928[BG_SCREEN_SIZE];
    u8 unk2128[0x20];
    u8 unk2148[0x20];
};

struct UnionRoomChat3
{
    struct Sprite *unk0;
    struct Sprite *unk4;
    struct Sprite *unk8;
    struct Sprite *unkC;
    struct Sprite *unk10;
    u16 unk14;
};

struct Unk82F2C98
{
    u16 unk0;
    bool32 (* unk4)(u8 *);
};

struct Unk82F2D40
{
    const u8 *unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
};

static void sub_801DDD0(struct UnionRoomChat *);
static void c2_081284E0(void);
static void sub_801DF20(void);
static void sub_801DF38(void);
static void sub_801DF54(u8 taskId);
static void sub_801DFAC(void);
static void sub_801E030(void);
static void sub_801E120(void);
static void sub_801E240(void);
static void sub_801E460(void);
static void sub_801E5C4(void);
static void sub_801E668(void);
static void sub_801E764(void);
static void sub_801E838(void);
static void sub_801E978(void);
static void sub_801EBD4(u16);
static bool32 sub_801EBE4(void);
static void sub_801EC94(void);
static void sub_801ED68(void);
static void sub_801ED94(void);
static bool32 sub_801EDC4(void);
static void sub_801EDE0(void);
static void sub_801EE10(void);
static void sub_801EE2C(void);
static u8 *sub_801EE84(void);
static u8 *sub_801EEA8(void);
static void sub_801EF1C(u8 *);
static void sub_801EF24(u8 *);
static void sub_801EF4C(u8 *);
static void sub_801EF7C(u8 *);
static void sub_801EFA8(u8 *);
static void sub_801EFD0(u8 *);
static u8 *sub_801F114(void);
static void sub_801F2B4(u8 taskId);
static bool8 sub_801F4D0(void);
static bool32 sub_801F534(void);
static void sub_801F544(void);
static void sub_801F5B8(void);
static void sub_801F5EC(u16, u8);
static bool8 sub_801F644(u8);
static s8 sub_801FF08(void);
static bool32 sub_8020890(void);
static void sub_8020770(void);
static void sub_801F574(struct UnionRoomChat2 *);
static void sub_801F580(void);
static void sub_80208D0(void);
static bool32 sub_801FDD8(u8 *);
static void sub_8020480(void);
static void sub_8020538(void);
static void sub_8020584(void);
static void sub_80205B4(void);
static void sub_8020604(void);
static void sub_8020680(void);
static void sub_80206A4(void);
static void sub_80206D0(void);
static void sub_8020740(void);
static void sub_80206E8(void);
static void sub_80208E8(void);
static void sub_8020A68(void);
static void sub_8020B20(void);
static void sub_80203B0(void);
static void sub_802040C(void);
static void sub_802091C(bool32);
static bool32 sub_8020320(void);
static void sub_80201A4(void);
static bool32 sub_8020368(void);
static void sub_802093C(void);
static void sub_8020B80(void);
static void sub_801FF18(int, u16);
static void sub_801FDDC(u8, u8, u8);
static void sub_8020094(void);
static void sub_801FEBC(void);
static void sub_80200C8(void);
static void sub_801FEE4(void);
static void sub_80200EC(u16, u16, u8);
static void sub_8020118(u16, u8 *, u8, u8, u8);
static void sub_80209AC(int);
static void sub_8020420(u16, u8 *, u8);
static void sub_80209E0(void);
static bool32 sub_8020A1C(void);
static void sub_80207C0(s16);
static void sub_8020818(s16);
static bool32 sub_801F658(u8 *state);
static bool32 sub_801F6F8(u8 *state);
static bool32 sub_801F730(u8 *state);
static bool32 sub_801F768(u8 *state);
static bool32 sub_801F7D4(u8 *state);
static bool32 sub_801F7E0(u8 *state);
static bool32 sub_801F82C(u8 *state);
static bool32 sub_801F870(u8 *state);
static bool32 sub_801F8DC(u8 *state);
static bool32 sub_801F984(u8 *state);
static bool32 sub_801FA2C(u8 *state);
static bool32 sub_801FA68(u8 *state);
static bool32 sub_801FB44(u8 *state);
static bool32 sub_801FB70(u8 *state);
static bool32 sub_801FBB4(u8 *state);
static bool32 sub_801FBF8(u8 *state);
static bool32 sub_801FC4C(u8 *state);
static bool32 sub_801FC9C(u8 *state);
static bool32 sub_801FCEC(u8 *state);
static bool32 sub_801FD30(u8 *state);
static bool32 sub_801FD88(u8 *state);
static void sub_8020ABC(struct Sprite *sprite);
static void sub_8020AF4(struct Sprite *sprite);

EWRAM_DATA struct UnionRoomChat *gUnknown_02022C84 = NULL;
EWRAM_DATA struct UnionRoomChat2 *gUnknown_02022C88 = NULL;
EWRAM_DATA struct UnionRoomChat3 *gUnknown_02022C8C = NULL;

void (*const gUnknown_082F2A7C[])(void) =
    {
        sub_801DFAC,
        sub_801E030,
        sub_801E120,
        sub_801E240,
        sub_801E764,
        sub_801E838,
        sub_801E460,
        sub_801E5C4,
        sub_801E668,
        sub_801E978,
    };

static const u8 sKeyboardPageMaxRow[] = 
{
    [UNION_ROOM_KB_PAGE_UPPER] = 9, 
    [UNION_ROOM_KB_PAGE_LOWER] = 9, 
    [UNION_ROOM_KB_PAGE_EMOJI] = 9, 
    9
};

static const u8 gUnknown_082F2AA8[] = {
    CHAR_SPACE, 0x16, 0x17, 0x68, 0x19, 0x1A, 0x1B, 0x1C,
    0x1D, 0x1E, CHAR_SPACE, 0x20, 0x21, 0x22, 0x23, 0x24,
    0x25, 0x26, 0x27, 0x28, 0x29, 0x15, 0x01, 0x02,
    CHAR_SPACE, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, CHAR_SPACE,
    0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12,
    0x13, 0x14, 0x2A, 0x2B, 0x2C, 0x2D, CHAR_SPACE, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, 0x35, 0x36, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, 0x53, 0x54, 0x55, 0x56, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, 0x6F, 0x5B, 0x5C, 0x5D, CHAR_SPACE, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE,
    0x03, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, 0x5A,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, 0x84, 0x85, 0x86, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE,
    0xA0, CHAR_0, CHAR_1, CHAR_2, CHAR_3, CHAR_4, CHAR_5, CHAR_6,
    CHAR_7, CHAR_8, CHAR_9, CHAR_EXCL_MARK, CHAR_QUESTION_MARK, CHAR_PERIOD, CHAR_HYPHEN, 0xAF,
    CHAR_ELLIPSIS, CHAR_DBL_QUOT_LEFT, CHAR_DBL_QUOT_RIGHT, CHAR_SGL_QUOT_LEFT, CHAR_SGL_QUOT_RIGHT, CHAR_MALE, CHAR_FEMALE, CHAR_CURRENCY,
    CHAR_COMMA, CHAR_MULT_SIGN, CHAR_SLASH, CHAR_a, CHAR_b, CHAR_c, CHAR_d, CHAR_e,
    CHAR_f, CHAR_g, CHAR_h, CHAR_i, CHAR_j, CHAR_k, CHAR_l, CHAR_m,
    CHAR_n, CHAR_o, CHAR_p, CHAR_q, CHAR_r, CHAR_s, CHAR_t, CHAR_u,
    CHAR_v, CHAR_w, CHAR_x, CHAR_y, CHAR_z, CHAR_A, CHAR_B, CHAR_C,
    CHAR_D, CHAR_E, CHAR_F, CHAR_G, CHAR_H, CHAR_I, CHAR_J, CHAR_K,
    CHAR_L, CHAR_M, CHAR_N, CHAR_O, CHAR_P, CHAR_Q, CHAR_R, CHAR_S,
    CHAR_T, CHAR_U, CHAR_V, CHAR_W, CHAR_X, CHAR_Y, CHAR_Z, 0xEF,
    CHAR_COLON, 0xF4, 0xF5, 0xF6, 0xF1, 0xF2, 0xF3, CHAR_SPACE,
    CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE, CHAR_SPACE
};

static const u8 *const sUnionRoomKeyboardText[UNION_ROOM_KB_PAGE_COUNT][UNION_ROOM_KB_ROW_COUNT] = 
{
    [UNION_ROOM_KB_PAGE_UPPER] = 
    {
        gText_UnionRoomChatKeyboard_ABCDE, 
        gText_UnionRoomChatKeyboard_FGHIJ, 
        gText_UnionRoomChatKeyboard_KLMNO, 
        gText_UnionRoomChatKeyboard_PQRST, 
        gText_UnionRoomChatKeyboard_UVWXY, 
        gText_UnionRoomChatKeyboard_Z, 
        gText_UnionRoomChatKeyboard_01234Upper, 
        gText_UnionRoomChatKeyboard_56789Upper, 
        gText_UnionRoomChatKeyboard_PunctuationUpper, 
        gText_UnionRoomChatKeyboard_SymbolsUpper
    },
    [UNION_ROOM_KB_PAGE_LOWER] = 
    {
        gText_UnionRoomChatKeyboard_abcde, 
        gText_UnionRoomChatKeyboard_fghij, 
        gText_UnionRoomChatKeyboard_klmno, 
        gText_UnionRoomChatKeyboard_pqrst, 
        gText_UnionRoomChatKeyboard_uvwxy, 
        gText_UnionRoomChatKeyboard_z, 
        gText_UnionRoomChatKeyboard_01234Lower, 
        gText_UnionRoomChatKeyboard_56789Lower, 
        gText_UnionRoomChatKeyboard_PunctuationLower, 
        gText_UnionRoomChatKeyboard_SymbolsLower
    },
    [UNION_ROOM_KB_PAGE_EMOJI] = 
    {
        gText_UnionRoomChatKeyboard_Emoji1, 
        gText_UnionRoomChatKeyboard_Emoji2, 
        gText_UnionRoomChatKeyboard_Emoji3, 
        gText_UnionRoomChatKeyboard_Emoji4, 
        gText_UnionRoomChatKeyboard_Emoji5, 
        gText_UnionRoomChatKeyboard_Emoji6, 
        gText_UnionRoomChatKeyboard_Emoji7, 
        gText_UnionRoomChatKeyboard_Emoji8, 
        gText_UnionRoomChatKeyboard_Emoji9, 
        gText_UnionRoomChatKeyboard_Emoji10
    }
};

const u16 gUnknown_082F2C20[] = INCBIN_U16("graphics/interface/unk_palette1.gbapal");
const u16 gUnknown_082F2C40[] = INCBIN_U16("graphics/interface/unk_palette2.gbapal");

const struct BgTemplate gUnknown_082F2C60[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }, {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 23,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }, {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 1
    }
};

const struct WindowTemplate gUnknown_082F2C70[] = {
    {
        .bg = 0x03,
        .tilemapLeft = 0x08,
        .tilemapTop = 0x01,
        .width = 0x15,
        .height = 0x13,
        .paletteNum = 0x0f,
        .baseBlock = 0x0001,
    }, {
        .bg = 0x01,
        .tilemapLeft = 0x09,
        .tilemapTop = 0x12,
        .width = 0x0f,
        .height = 0x02,
        .paletteNum = 0x0c,
        .baseBlock = 0x007a,
    }, {
        .bg = 0x01,
        .tilemapLeft = 0x00,
        .tilemapTop = 0x02,
        .width = 0x06,
        .height = 0x0f,
        .paletteNum = 0x07,
        .baseBlock = 0x0020,
    }, {
        .bg = 0x00,
        .tilemapLeft = 0x01,
        .tilemapTop = 0x02,
        .width = 0x07,
        .height = 0x09,
        .paletteNum = 0x0e,
        .baseBlock = 0x0013,
    }, { 0xFF }
};

const struct Unk82F2C98 gUnknown_082F2C98[] = {
    {0x00000000, sub_801F658},
    {0x00000003, sub_801F6F8},
    {0x00000004, sub_801F730},
    {0x00000005, sub_801F768},
    {0x00000001, sub_801F7D4},
    {0x00000006, sub_801F7E0},
    {0x00000007, sub_801F82C},
    {0x00000008, sub_801F870},
    {0x00000009, sub_801F8DC},
    {0x0000000a, sub_801F984},
    {0x0000000b, sub_801FA2C},
    {0x0000000c, sub_801FA68},
    {0x00000002, sub_801FB44},
    {0x0000000d, sub_801FB70},
    {0x00000012, sub_801FBB4},
    {0x00000013, sub_801FBF8},
    {0x0000000e, sub_801FC4C},
    {0x0000000f, sub_801FC9C},
    {0x00000010, sub_801FCEC},
    {0x00000011, sub_801FD30},
    {0x00000014, sub_801FD88}
};

const struct Unk82F2D40 gUnknown_082F2D40[] = {
    {gText_QuitChatting, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00},
    {gText_RegisterTextWhere, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00},
    {gText_RegisterTextHere, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00},
    {gText_InputText, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00},
    {gText_ExitingChat, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00},
    {gText_LeaderLeftEndingChat, 0x02, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00},
    {gText_RegisteredTextChanged, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01},
    {gText_AlreadySavedFile_Unused, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01},
    {gText_SavingDontTurnOff_Unused, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01},
    {gText_PlayerSavedGame_Unused, 0x02, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01},
    {gText_IfLeaderLeavesChatEnds, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01}
};

const u8 gText_Ellipsis[] = _("…");

const struct MenuAction gUnknown_082F2DC8[] = {
    {gText_Upper, NULL},
    {gText_Lower, NULL},
    {gText_Symbols, NULL},
    {gText_Register2, NULL},
    {gText_Exit2, NULL},
};

const u16 gUnknown_082F2DF0[] = INCBIN_U16("graphics/interface/unk_palette3.gbapal");
const u32 gUnknown_082F2E10[] = INCBIN_U32("graphics/interface/unk_cursor.4bpp.lz");
const u32 gUnknown_082F3094[] = INCBIN_U32("graphics/interface/unk_dash.4bpp.lz");
const u32 gUnknown_082F30B4[] = INCBIN_U32("graphics/interface/unk_cursor_arrow.4bpp.lz");
const u32 gUnknown_082F30E0[] = INCBIN_U32("graphics/interface/unk_rbutton.4bpp.lz");

const struct CompressedSpriteSheet gUnknown_082F3134[] = {
    {gUnknown_082F2E10, 0x1000, 0x0000},
    {gUnknown_082F30B4, 0x0040, 0x0001},
    {gUnknown_082F3094, 0x0040, 0x0002},
    {gUnknown_082F30E0, 0x0080, 0x0003},
    {gUnknown_08DD4CF8, 0x0400, 0x0004}
};

const struct SpritePalette gUnknown_082F315C = {
    gUnknown_082F2DF0, 0x0000
};

const struct OamData gUnknown_082F3164 = {
    .shape = ST_OAM_H_RECTANGLE,
    .size = 3,
    .priority = 1
};

const union AnimCmd gUnknown_082F316C[] = {
    ANIMCMD_FRAME(0x00, 30),
    ANIMCMD_END
};

const union AnimCmd gUnknown_082F3174[] = {
    ANIMCMD_FRAME(0x20, 30),
    ANIMCMD_END
};

const union AnimCmd gUnknown_082F317C[] = {
    ANIMCMD_FRAME(0x40, 30),
    ANIMCMD_END
};

const union AnimCmd gUnknown_082F3184[] = {
    ANIMCMD_FRAME(0x60, 30),
    ANIMCMD_END
};

const union AnimCmd *const gUnknown_082F318C[] = {
    gUnknown_082F316C,
    gUnknown_082F3174,
    gUnknown_082F317C,
    gUnknown_082F3184
};

const struct SpriteTemplate gUnknown_082F319C = {
    .tileTag = 0x0000,
    .paletteTag = 0x0000,
    .oam = &gUnknown_082F3164,
    .anims = gUnknown_082F318C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct OamData gUnknown_082F31B4 = {
    .shape = ST_OAM_V_RECTANGLE,
    .size = 0,
    .priority = 2
};

const struct SpriteTemplate gUnknown_082F31BC = {
    .tileTag = 0x0002,
    .paletteTag = 0x0000,
    .oam = &gUnknown_082F31B4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8020ABC
};

const struct SpriteTemplate gUnknown_082F31D4 = {
    .tileTag = 0x0001,
    .paletteTag = 0x0000,
    .oam = &gUnknown_082F31B4,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sub_8020AF4
};

const struct OamData gUnknown_082F31EC = {
    .shape = ST_OAM_SQUARE,
    .size = 1,
    .priority = 2
};

const struct OamData gUnknown_082F31F4 = {
    .shape = ST_OAM_H_RECTANGLE,
    .size = 2,
    .priority = 2
};

const union AnimCmd gUnknown_082F31FC[] = {
    ANIMCMD_FRAME(0x00, 2),
    ANIMCMD_END
};

const union AnimCmd gUnknown_082F3204[] = {
    ANIMCMD_FRAME(0x08, 2),
    ANIMCMD_END
};

const union AnimCmd gUnknown_082F320C[] = {
    ANIMCMD_FRAME(0x10, 2),
    ANIMCMD_END
};

const union AnimCmd gUnknown_082F3214[] = {
    ANIMCMD_FRAME(0x18, 2),
    ANIMCMD_END
};

const union AnimCmd *const gUnknown_082F321C[] = {
    gUnknown_082F31FC,
    gUnknown_082F3204,
    gUnknown_082F320C,
    gUnknown_082F3214
};

const struct SpriteTemplate gUnknown_082F322C = {
    .tileTag = 0x0003,
    .paletteTag = 0x0000,
    .oam = &gUnknown_082F31EC,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct SpriteTemplate gUnknown_082F3244 = {
    .tileTag = 0x0004,
    .paletteTag = 0x0000,
    .oam = &gUnknown_082F31F4,
    .anims = gUnknown_082F321C,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

void sub_801DD98(void)
{
    gUnknown_02022C84 = Alloc(sizeof(*gUnknown_02022C84));
    sub_801DDD0(gUnknown_02022C84);
    gKeyRepeatStartDelay = 20;
    SetVBlankCallback(NULL);
    SetMainCallback2(c2_081284E0);
}

static void sub_801DDD0(struct UnionRoomChat *unionRoomChat)
{
    int i;

    unionRoomChat->unk4 = 0;
    unionRoomChat->unk6 = 0;
    unionRoomChat->currentPage = 0;
    unionRoomChat->unk11 = 0;
    unionRoomChat->currentRow = 0;
    unionRoomChat->unk14 = 0;
    unionRoomChat->unk15 = 0;
    unionRoomChat->unk16 = 0;
    unionRoomChat->unk1A[0] = EOS;
    unionRoomChat->unkD = GetLinkPlayerCount();
    unionRoomChat->unk13 = GetMultiplayerId();
    unionRoomChat->unk17 = 0;
    unionRoomChat->unk18 = 0;
    sub_801EF1C(unionRoomChat->unk190);
    for (i = 0; i < UNION_ROOM_KB_ROW_COUNT; i++)
        StringCopy(unionRoomChat->unkB9[i], gSaveBlock1Ptr->unk3C88[i]);
}

void sub_801DE30(void)
{
    DestroyTask(gUnknown_02022C84->unkE);
    DestroyTask(gUnknown_02022C84->unkF);
    Free(gUnknown_02022C84);
}

static void c2_081284E0(void)
{
    switch (gMain.state)
    {
    case 0:
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        sub_801F4D0();
        gMain.state++;
        break;
    case 1:
        sub_801F5B8();
        if (!sub_801F534())
        {
            BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
            BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
            SetVBlankCallback(sub_801DF20);
            gMain.state++;
        }
        break;
    case 2:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            SetMainCallback2(sub_801DF38);
            gUnknown_02022C84->unkE = CreateTask(sub_801DF54, 8);
            gUnknown_02022C84->unkF = CreateTask(sub_801F2B4, 7);
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(232, 150);
        }
        break;
    }
}

static void sub_801DF20(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void sub_801DF38(void)
{
    RunTasks();
    sub_801F5B8();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void sub_801DF54(u8 taskId)
{
    switch (gUnknown_02022C84->unk17)
    {
    case 1:
        sub_801EBD4(6);
        gUnknown_02022C84->unk17 = 0;
        break;
    case 2:
        sub_801EBD4(7);
        gUnknown_02022C84->unk17 = 0;
        break;
    case 3:
        sub_801EBD4(8);
        gUnknown_02022C84->unk17 = 0;
        break;
    }

    gUnknown_082F2A7C[gUnknown_02022C84->unk4]();
}

static void sub_801DFAC(void)
{
    switch (gUnknown_02022C84->unk6)
    {
    case 0:
        sub_801EF24(gUnknown_02022C84->unk190);
        gUnknown_02022C84->unk6++;
        // fall through
    case 1:
        if (IsLinkTaskFinished() && !sub_8011A9C())
        {
            if (SendBlock(0, gUnknown_02022C84->unk190, sizeof(gUnknown_02022C84->unk190)))
                gUnknown_02022C84->unk6++;
        }
        break;
    case 2:
        if (IsLinkTaskFinished())
            sub_801EBD4(1);
        break;
    }
}

static void sub_801E030(void)
{
    bool8 var0, var1;

    switch (gUnknown_02022C84->unk6)
    {
    case 0:
        if (gMain.newKeys & START_BUTTON)
        {
            if (gUnknown_02022C84->unk15)
                sub_801EBD4(4);
        }
        else if (gMain.newKeys & SELECT_BUTTON)
        {
            sub_801EBD4(2);
        }
        else if (gMain.newAndRepeatedKeys & B_BUTTON)
        {
            if (gUnknown_02022C84->unk15)
            {
                sub_801ED68();
                sub_801F5EC(8, 0);
                gUnknown_02022C84->unk6 = 1;
            }
            else
            {
                sub_801EBD4(3);
            }
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            sub_801EC94();
            sub_801F5EC(8, 0);
            sub_801F5EC(2, 1);
            gUnknown_02022C84->unk6 = 1;
        }
        else if (gMain.newKeys & R_BUTTON)
        {
            if (gUnknown_02022C84->currentPage != UNION_ROOM_KB_PAGE_COUNT)
            {
                sub_801ED94();
                sub_801F5EC(8, 0);
                gUnknown_02022C84->unk6 = 1;
            }
            else
            {
                sub_801EBD4(5);
            }
        }
        else if (sub_801EBE4())
        {
            sub_801F5EC(1, 0);
            gUnknown_02022C84->unk6 = 1;
        }
        break;
    case 1:
        var0 = sub_801F644(0);
        var1 = sub_801F644(1);
        if (!var0 && !var1)
            gUnknown_02022C84->unk6 = 0;
        break;
    }
}

static void sub_801E120(void)
{
    s16 input;
    int var0;

    switch (gUnknown_02022C84->unk6)
    {
    case 0:
        sub_801F5EC(3, 0);
        gUnknown_02022C84->unk6++;
        break;
    case 1:
        if (!sub_801F644(0))
            gUnknown_02022C84->unk6++;
        break;
    case 2:
        input = Menu_ProcessInput();
        switch (input)
        {
        default:
            sub_801F5EC(4, 0);
            var0 = 1;
            if (gUnknown_02022C84->currentPage == input || input > UNION_ROOM_KB_PAGE_COUNT)
                var0 = 0;
            break;
        case MENU_NOTHING_CHOSEN:
            if (gMain.newKeys & SELECT_BUTTON)
            {
                PlaySE(SE_SELECT);
                Menu_MoveCursor(1);
            }
            return;
        case MENU_B_PRESSED:
            sub_801F5EC(4, 0);
            gUnknown_02022C84->unk6 = 3;
            return;
        }

        if (!var0)
        {
            gUnknown_02022C84->unk6 = 3;
            return;
        }

        gUnknown_02022C84->unk11 = 0;
        gUnknown_02022C84->currentRow = 0;
        sub_801F5EC(5, 1);
        gUnknown_02022C84->currentPage = input;
        gUnknown_02022C84->unk6 = 4;
        break;
    case 3:
        if (!sub_801F644(0))
            sub_801EBD4(1);
        break;
    case 4:
        if (!sub_801F644(0) && !sub_801F644(1))
            sub_801EBD4(1);
        break;
    }
}

static void sub_801E240(void)
{
    s8 input;

    switch (gUnknown_02022C84->unk6)
    {
    case 0:
        sub_801F5EC(6, 0);
        gUnknown_02022C84->unk6 = 1;
        break;
    case 1:
        if (!sub_801F644(0))
            gUnknown_02022C84->unk6 = 2;
        break;
    case 2:
        input = sub_801FF08();
        switch (input)
        {
        case -1:
        case 1:
            sub_801F5EC(7, 0);
            gUnknown_02022C84->unk6 = 3;
            break;
        case 0:
            if (gUnknown_02022C84->unk13 == 0)
            {
                sub_801EFD0(gUnknown_02022C84->unk190);
                sub_801F5EC(7, 0);
                gUnknown_02022C84->unk6 = 9;
            }
            else
            {
                sub_801EF7C(gUnknown_02022C84->unk190);
                gUnknown_02022C84->unk6 = 4;
            }
            break;
        }
        break;
    case 3:
        if (!sub_801F644(0))
            sub_801EBD4(1);
        break;
    case 9:
        if (!sub_801F644(0))
        {
            sub_801F5EC(20, 0);
            gUnknown_02022C84->unk6 = 10;
        }
        break;
    case 10:
        if (!sub_801F644(0))
            gUnknown_02022C84->unk6 = 8;
        break;
    case 8:
        input = sub_801FF08();
        switch (input)
        {
        case -1:
        case 1:
            sub_801F5EC(7, 0);
            gUnknown_02022C84->unk6 = 3;
            break;
        case 0:
            sub_80104B0();
            sub_801EFD0(gUnknown_02022C84->unk190);
            gUnknown_02022C84->unk6 = 4;
            gUnknown_02022C84->unk1B8 = 0;
            break;
        }
        break;
    case 4:
        if (IsLinkTaskFinished() && !sub_8011A9C() && SendBlock(0, gUnknown_02022C84->unk190, sizeof(gUnknown_02022C84->unk190)))
        {
            if (!gUnknown_02022C84->unk13)
                gUnknown_02022C84->unk6 = 6;
            else
                gUnknown_02022C84->unk6 = 5;
        }

        if (!gReceivedRemoteLinkPlayers)
            sub_801EBD4(9);
        break;
    case 5:
        if (!gReceivedRemoteLinkPlayers)
        {
            sub_801EBD4(9);
        }
        else if (++gUnknown_02022C84->unk1B8 > 300)
        {
            gUnknown_02022C84->unk1B8 = 0;
            gUnknown_02022C84->unk6 = 4;
        }
        break;
    }
}

static void sub_801E460(void)
{
    switch (gUnknown_02022C84->unk6)
    {
    case 0:
        if (!FuncIsActiveTask(sub_801F2B4))
        {
            sub_801F5EC(7, 0);
            gUnknown_02022C84->unk6++;
        }
        break;
    case 1:
        if (!sub_801F644(0))
        {
            sub_801F5EC(18, 0);
            gUnknown_02022C84->unk6++;
        }
        break;
    case 2:
        if (!sub_801F644(0))
        {
            sub_801EFA8(gUnknown_02022C84->unk190);
            gUnknown_02022C84->unk6++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished() && !sub_8011A9C() && SendBlock(0, gUnknown_02022C84->unk190, sizeof(gUnknown_02022C84->unk190)))
            gUnknown_02022C84->unk6++;
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 1) && !sub_8011A9C())
            gUnknown_02022C84->unk6++;
        break;
    case 5:
        if (IsLinkTaskFinished() && !sub_8011A9C())
        {
            sub_800AC34();
            gUnknown_02022C84->unkA = 0;
            gUnknown_02022C84->unk6++;
        }
        break;
    case 6:
        if (gUnknown_02022C84->unkA < 150)
            gUnknown_02022C84->unkA++;

        if (!gReceivedRemoteLinkPlayers)
            gUnknown_02022C84->unk6++;
        break;
    case 7:
        if (gUnknown_02022C84->unkA >= 150)
            sub_801EBD4(9);
        else
            gUnknown_02022C84->unkA++;
        break;
    }
}

static void sub_801E5C4(void)
{
    switch (gUnknown_02022C84->unk6)
    {
    case 0:
        if (!FuncIsActiveTask(sub_801F2B4))
        {
            sub_801F5EC(7, 0);
            gUnknown_02022C84->unk6++;
        }
        break;
    case 1:
        if (!sub_801F644(0) && IsLinkTaskFinished() && !sub_8011A9C())
        {
            sub_800AC34();
            gUnknown_02022C84->unkA = 0;
            gUnknown_02022C84->unk6++;
        }
        break;
    case 2:
        if (gUnknown_02022C84->unkA < 150)
            gUnknown_02022C84->unkA++;

        if (!gReceivedRemoteLinkPlayers)
            gUnknown_02022C84->unk6++;
        break;
    case 3:
        if (gUnknown_02022C84->unkA >= 150)
            sub_801EBD4(9);
        else
            gUnknown_02022C84->unkA++;
        break;
    }
}

static void sub_801E668(void)
{
    switch (gUnknown_02022C84->unk6)
    {
    case 0:
        if (!FuncIsActiveTask(sub_801F2B4))
        {
            if (gUnknown_02022C84->unk13)
                sub_801F5EC(7, 0);

            gUnknown_02022C84->unk6++;
        }
        break;
    case 1:
        if (!sub_801F644(0))
        {
            if (gUnknown_02022C84->unk13)
                sub_801F5EC(19, 0);

            gUnknown_02022C84->unk6++;
        }
        break;
    case 2:
        if (sub_801F644(0) != TRUE && IsLinkTaskFinished() && !sub_8011A9C())
        {
            sub_800AC34();
            gUnknown_02022C84->unkA = 0;
            gUnknown_02022C84->unk6++;
        }
        break;
    case 3:
        if (gUnknown_02022C84->unkA < 150)
            gUnknown_02022C84->unkA++;

        if (!gReceivedRemoteLinkPlayers)
            gUnknown_02022C84->unk6++;
        break;
    case 4:
        if (gUnknown_02022C84->unkA >= 150)
            sub_801EBD4(9);
        else
            gUnknown_02022C84->unkA++;
        break;
    }
}

static void sub_801E764(void)
{
    switch (gUnknown_02022C84->unk6)
    {
    case 0:
        if (!gReceivedRemoteLinkPlayers)
        {
            sub_801EBD4(1);
            break;
        }

        sub_801EF4C(gUnknown_02022C84->unk190);
        gUnknown_02022C84->unk6++;
        // fall through
    case 1:
        if (IsLinkTaskFinished() == TRUE && !sub_8011A9C() && SendBlock(0, gUnknown_02022C84->unk190, sizeof(gUnknown_02022C84->unk190)))
            gUnknown_02022C84->unk6++;
        break;
    case 2:
        sub_801EE10();
        sub_801F5EC(8, 0);
        gUnknown_02022C84->unk6++;
        break;
    case 3:
        if (!sub_801F644(0))
            gUnknown_02022C84->unk6++;
        break;
    case 4:
        if (IsLinkTaskFinished())
            sub_801EBD4(1);
        break;
    }
}

static void sub_801E838(void)
{
    switch (gUnknown_02022C84->unk6)
    {
    case 0:
        if (sub_801EDC4())
        {
            sub_801F5EC(9, 0);
            gUnknown_02022C84->unk6 = 2;
        }
        else
        {
            sub_801F5EC(13, 0);
            gUnknown_02022C84->unk6 = 5;
        }
        break;
    case 1:
        if (gMain.newKeys & A_BUTTON)
        {
            sub_801EDE0();
            sub_801F5EC(11, 0);
            gUnknown_02022C84->unk6 = 3;
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            sub_801F5EC(10, 0);
            gUnknown_02022C84->unk6 = 4;
        }
        else if (sub_801EBE4())
        {
            sub_801F5EC(1, 0);
            gUnknown_02022C84->unk6 = 2;
        }
        break;
    case 2:
        if (!sub_801F644(0))
            gUnknown_02022C84->unk6 = 1;
        break;
    case 3:
        if (!sub_801F644(0))
        {
            sub_801F5EC(10, 0);
            gUnknown_02022C84->unk6 = 4;
        }
        break;
    case 4:
        if (!sub_801F644(0))
            sub_801EBD4(1);
        break;
    case 5:
        if (!sub_801F644(0))
            gUnknown_02022C84->unk6 = 6;
        break;
    case 6:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            sub_801F5EC(7, 0);
            gUnknown_02022C84->unk6 = 4;
        }
        break;
    }
}

static void sub_801E978(void)
{
    s8 input;

    switch (gUnknown_02022C84->unk6)
    {
    case 0:
        if (!gUnknown_02022C84->unk18)
        {
            gUnknown_02022C84->unk6 = 12;
        }
        else
        {
            sub_801F5EC(7, 0);
            gUnknown_02022C84->unk6 = 1;
        }
        break;
    case 1:
        if (!sub_801F644(0))
        {
            sub_801F5EC(14, 0);
            gUnknown_02022C84->unk6 = 2;
        }
        break;
    case 2:
        input = sub_801FF08();
        switch (input)
        {
        case -1:
        case 1:
            gUnknown_02022C84->unk6 = 12;
            break;
        case 0:
            sub_801F5EC(7, 0);
            gUnknown_02022C84->unk6 = 3;
            break;
        }
        break;
    case 3:
        if (!sub_801F644(0))
        {
            sub_801F5EC(15, 0);
            gUnknown_02022C84->unk6 = 4;
        }
        break;
    case 4:
        if (!sub_801F644(0))
            gUnknown_02022C84->unk6 = 5;
        break;
    case 5:
        input = sub_801FF08();
        switch (input)
        {
        case -1:
        case 1:
            gUnknown_02022C84->unk6 = 12;
            break;
        case 0:
            sub_801F5EC(7, 0);
            gUnknown_02022C84->unk6 = 6;
            break;
        }
        break;
    case 6:
        if (!sub_801F644(0))
        {
            sub_801F5EC(16, 0);
            sub_801EE2C();
            gUnknown_02022C84->unk6 = 7;
        }
        break;
    case 7:
        if (!sub_801F644(0))
        {
            SetContinueGameWarpStatusToDynamicWarp();
            TrySavingData(SAVE_NORMAL);
            gUnknown_02022C84->unk6 = 8;
        }
        break;
    case 8:
        sub_801F5EC(17, 0);
        gUnknown_02022C84->unk6 = 9;
        break;
    case 9:
        if (!sub_801F644(0))
        {
            PlaySE(SE_SAVE);
            ClearContinueGameWarpStatus2();
            gUnknown_02022C84->unk6 = 10;
        }
        break;
    case 10:
        gUnknown_02022C84->unk19 = 0;
        gUnknown_02022C84->unk6 = 11;
        break;
    case 11:
        gUnknown_02022C84->unk19++;
        if (gUnknown_02022C84->unk19 > 120)
            gUnknown_02022C84->unk6 = 12;
        break;
    case 12:
        BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
        gUnknown_02022C84->unk6 = 13;
        break;
    case 13:
        if (!gPaletteFade.active)
        {
            sub_801F544();
            sub_801DE30();
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    }
}

static void sub_801EBD4(u16 arg0)
{
    gUnknown_02022C84->unk4 = arg0;
    gUnknown_02022C84->unk6 = 0;
}

static bool32 sub_801EBE4(void)
{
    if (!(gMain.newAndRepeatedKeys & DPAD_UP))
    {
        if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            if (gUnknown_02022C84->currentRow < sKeyboardPageMaxRow[gUnknown_02022C84->currentPage])
                gUnknown_02022C84->currentRow++;
            else
                gUnknown_02022C84->currentRow = 0;

            return TRUE;
        }

        if (gUnknown_02022C84->currentPage != UNION_ROOM_KB_PAGE_COUNT)
        {
            if (gMain.newAndRepeatedKeys & DPAD_LEFT)
            {
                if (gUnknown_02022C84->unk11)
                    gUnknown_02022C84->unk11--;
                else
                    gUnknown_02022C84->unk11 = 4;
            }
            else if (gMain.newAndRepeatedKeys & DPAD_RIGHT)
            {
                if (gUnknown_02022C84->unk11 > 3)
                    gUnknown_02022C84->unk11 = 0;
                else
                    gUnknown_02022C84->unk11++;
            }
            else
            {
                return FALSE;
            }

            return TRUE;
        }

        return FALSE;
    }
    else
    {
        if (gUnknown_02022C84->currentRow)
            gUnknown_02022C84->currentRow--;
        else
            gUnknown_02022C84->currentRow = sKeyboardPageMaxRow[gUnknown_02022C84->currentPage];

        return TRUE;
    }
}

static void sub_801EC94(void)
{
    int i;
    const u8 *charsStr;
    int strLength;
    u8 *str;
    u8 buffer[21];

    if (gUnknown_02022C84->currentPage != UNION_ROOM_KB_PAGE_COUNT)
    {
        charsStr = sUnionRoomKeyboardText[gUnknown_02022C84->currentPage][gUnknown_02022C84->currentRow];
        for (i = 0; i < gUnknown_02022C84->unk11; i++)
        {
            if (*charsStr == CHAR_SPECIAL_F9)
                charsStr++;
            charsStr++;
        }

        strLength = 1;
    }
    else
    {
        u8 *tempStr = StringCopy(buffer, gUnknown_02022C84->unkB9[gUnknown_02022C84->currentRow]);
        tempStr[0] = CHAR_SPACE;
        tempStr[1] = EOS;
        charsStr = buffer;
        strLength = StringLength_Multibyte(buffer);
    }

    gUnknown_02022C84->unk14 = gUnknown_02022C84->unk15;
    if (!charsStr)
        return;

    str = sub_801EE84();
    while (--strLength != -1 && gUnknown_02022C84->unk15 < 15)
    {
        if (*charsStr == CHAR_SPECIAL_F9)
        {
            *str = *charsStr;
            charsStr++;
            str++;
        }

        *str = *charsStr;
        charsStr++;
        str++;

        gUnknown_02022C84->unk15++;
    }

    *str = EOS;
}

static void sub_801ED68(void)
{
    gUnknown_02022C84->unk14 = gUnknown_02022C84->unk15;
    if (gUnknown_02022C84->unk15)
    {
        u8 *str = sub_801EEA8();
        *str = EOS;
        gUnknown_02022C84->unk15--;
    }
}

static void sub_801ED94(void)
{
    u8 *str;
    u8 character;

    gUnknown_02022C84->unk14 = gUnknown_02022C84->unk15 - 1;
    str = sub_801EEA8();
    if (*str != CHAR_SPECIAL_F9)
    {
        character = gUnknown_082F2AA8[*str];
        if (character)
            *str = character;
    }
}

static bool32 sub_801EDC4(void)
{
    if (gUnknown_02022C84->unk15)
        return TRUE;
    else
        return FALSE;
}

static void sub_801EDE0(void)
{
    u8 *src = sub_801F114();
    StringCopy(gUnknown_02022C84->unkB9[gUnknown_02022C84->currentRow], src);
    gUnknown_02022C84->unk18 = 1;
}

static void sub_801EE10(void)
{
    gUnknown_02022C84->unk1A[0] = EOS;
    gUnknown_02022C84->unk14 = 15;
    gUnknown_02022C84->unk15 = 0;
}

static void sub_801EE2C(void)
{
    int i;
    for (i = 0; i < UNION_ROOM_KB_ROW_COUNT; i++)
        StringCopy(gSaveBlock1Ptr->unk3C88[i], gUnknown_02022C84->unkB9[i]);
}

static u8 *sub_801EE6C(int arg0)
{
    return gUnknown_02022C84->unkB9[arg0];
}

static u8 *sub_801EE84(void)
{
    u8 *str = gUnknown_02022C84->unk1A;
    while (*str != EOS)
        str++;

    return str;
}

static u8 *sub_801EEA8(void)
{
    u8 *str = gUnknown_02022C84->unk1A;
    u8 *str2 = str;
    while (*str != EOS)
    {
        str2 = str;
        if (*str == CHAR_SPECIAL_F9)
            str++;
        str++;
    }

    return str2;
}

static u16 sub_801EED8(void)
{
    u8 *str;
    u32 i, numChars, strLength;

    strLength = StringLength_Multibyte(gUnknown_02022C84->unk1A);
    str = gUnknown_02022C84->unk1A;
    numChars = 0;
    if (strLength > 10)
    {
        strLength -= 10;
        for (i = 0; i < strLength; i++)
        {
            if (*str == CHAR_SPECIAL_F9)
                str++;

            str++;
            numChars++;
        }
    }

    return numChars;
}

static void sub_801EF1C(u8 *arg0)
{
    arg0[0] = CHAR_SPACE;
}

static void sub_801EF24(u8 *arg0)
{
    arg0[0] = 2;
    StringCopy(&arg0[1], gSaveBlock2Ptr->playerName);
    arg0[1 + (PLAYER_NAME_LENGTH + 1)] = gUnknown_02022C84->unk13;
}

static void sub_801EF4C(u8 *arg0)
{
    arg0[0] = 1;
    StringCopy(&arg0[1], gSaveBlock2Ptr->playerName);
    StringCopy(&arg0[1 + (PLAYER_NAME_LENGTH + 1)], gUnknown_02022C84->unk1A);
}

static void sub_801EF7C(u8 *arg0)
{
    arg0[0] = 3;
    StringCopy(&arg0[1], gSaveBlock2Ptr->playerName);
    arg0[1 + (PLAYER_NAME_LENGTH + 1)] = gUnknown_02022C84->unk13;
    sub_8011A50();
}

static void sub_801EFA8(u8 *arg0)
{
    arg0[0] = 4;
    StringCopy(&arg0[1], gSaveBlock2Ptr->playerName);
    arg0[1 + (PLAYER_NAME_LENGTH + 1)] = gUnknown_02022C84->unk13;
}

static void sub_801EFD0(u8 *arg0)
{
    arg0[0] = 5;
    StringCopy(&arg0[1], gSaveBlock2Ptr->playerName);
    arg0[1 + (PLAYER_NAME_LENGTH + 1)] = gUnknown_02022C84->unk13;
}

static bool32 sub_801EFF8(u8 *arg0, u8 *arg1)
{
    u8 *tempStr;
    u8 var0 = *arg1;
    u8 *str = arg1 + 1;
    arg1 = str;
    arg1 += 8;

    switch (var0)
    {
    case 2:
        if (gUnknown_02022C84->unk13 != str[8])
        {
            DynamicPlaceholderTextUtil_Reset();
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, str);
            DynamicPlaceholderTextUtil_ExpandPlaceholders(arg0, gText_F700JoinedChat);
            return TRUE;
        }
        break;
    case 1:
        tempStr = StringCopy(arg0, str);
        *(tempStr++) = EXT_CTRL_CODE_BEGIN;
        *(tempStr++) = EXT_CTRL_CODE_CLEAR_TO;
        *(tempStr++) = 42;
        *(tempStr++) = CHAR_COLON;
        StringCopy(tempStr, arg1);
        return TRUE;
    case 5:
        StringCopy(gUnknown_02022C84->unk79, str);
        // fall through
    case 3:
        if (gUnknown_02022C84->unk13 != *arg1)
        {
            DynamicPlaceholderTextUtil_Reset();
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, str);
            DynamicPlaceholderTextUtil_ExpandPlaceholders(arg0, gText_F700LeftChat);
            return TRUE;
        }
        break;
    }

    return FALSE;
}

static u8 GetCurrentKeyboardPage(void)
{
    return gUnknown_02022C84->currentPage;
}

static void sub_801F0BC(u8 *arg0, u8 *arg1)
{
    *arg0 = gUnknown_02022C84->unk11;
    *arg1 = gUnknown_02022C84->currentRow;
}

static u8 *sub_801F0D0(void)
{
    return gUnknown_02022C84->unk1A;
}

static int sub_801F0DC(void)
{
    u8 *str = sub_801F0D0();
    return StringLength_Multibyte(str);
}

static void sub_801F0EC(u32 *arg0, u32 *arg1)
{
    int diff = gUnknown_02022C84->unk15 - gUnknown_02022C84->unk14;
    if (diff < 0)
    {
        diff *= -1;
        *arg0 = gUnknown_02022C84->unk15;
    }
    else
    {
        *arg0 = gUnknown_02022C84->unk14;
    }

    *arg1 = diff;
}

static u8 *sub_801F114(void)
{
    int i;
    u16 numChars = sub_801EED8();
    u8 *str = gUnknown_02022C84->unk1A;
    for (i = 0; i < numChars; i++)
    {
        if (*str == CHAR_SPECIAL_F9)
            *str++;

        str++;
    }

    return str;
}

static u16 sub_801F144(void)
{
    u16 count;
    u32 i;
    u16 numChars = sub_801EED8();
    u8 *str = gUnknown_02022C84->unk1A;
    for (count = 0, i = 0; i < numChars; count++, i++)
    {
        if (*str == CHAR_SPECIAL_F9)
            str++;

        str++;
    }

    return count;
}

static u8 *sub_801F180(void)
{
    return gUnknown_02022C84->unk39;
}

static u8 sub_801F18C(void)
{
    return gUnknown_02022C84->unk16;
}

static int sub_801F198(void)
{
    return gUnknown_02022C84->unk15;
}

static int sub_801F1A4(void)
{
    u8 *str = sub_801EEA8();
    u32 character = *str;
    if (character > 0xFF || gUnknown_082F2AA8[character] == character || gUnknown_082F2AA8[character] == 0)
        return 3;
    else
        return 0;
}

static u8 *sub_801F1D0(void)
{
    return gUnknown_02022C84->unk79;
}

void copy_strings_to_sav1(void)
{
    StringCopy(gSaveBlock1Ptr->unk3C88[0], gText_Hello);
    StringCopy(gSaveBlock1Ptr->unk3C88[1], gText_Pokemon2);
    StringCopy(gSaveBlock1Ptr->unk3C88[2], gText_Trade);
    StringCopy(gSaveBlock1Ptr->unk3C88[3], gText_Battle);
    StringCopy(gSaveBlock1Ptr->unk3C88[4], gText_Lets);
    StringCopy(gSaveBlock1Ptr->unk3C88[5], gText_Ok);
    StringCopy(gSaveBlock1Ptr->unk3C88[6], gText_Sorry);
    StringCopy(gSaveBlock1Ptr->unk3C88[7], gText_YayUnkF9F9);
    StringCopy(gSaveBlock1Ptr->unk3C88[8], gText_ThankYou);
    StringCopy(gSaveBlock1Ptr->unk3C88[9], gText_ByeBye);
}

static void sub_801F2B4(u8 taskId)
{
    u8 *buffer;
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        if (!gReceivedRemoteLinkPlayers)
        {
            DestroyTask(taskId);
            return;
        }

        data[0] = 1;
        // fall through
    case 1:
        data[4] = GetLinkPlayerCount();
        if (gUnknown_02022C84->unkD != data[4])
        {
            data[0] = 2;
            gUnknown_02022C84->unkD = data[4];
            return;
        }

        data[3] = GetBlockReceivedStatus();
        if (!data[3] && sub_8011A9C())
            return;

        data[1] = 0;
        data[0] = 3;
        // fall through
    case 3:
        for (; data[1] < 5 && ((data[3] >> data[1]) & 1) == 0; data[1]++)
            ;

        if (data[1] == 5)
        {
            data[0] = 1;
            return;
        }

        data[2] = data[1];
        ResetBlockReceivedFlag(data[2]);
        buffer = (u8 *)gBlockRecvBuffer[data[1]];
        switch (buffer[0])
        {
            default:
            case 1: data[5] = 3; break;
            case 2: data[5] = 3; break;
            case 3: data[5] = 4; break;
            case 4: data[5] = 5; break;
            case 5: data[5] = 6; break;
        }

        if (sub_801EFF8(gUnknown_02022C84->unk39, (u8 *)gBlockRecvBuffer[data[1]]))
        {
            gUnknown_02022C84->unk16 = data[1];
            sub_801F5EC(12, 2);
            data[0] = 7;
        }
        else
        {
            data[0] = data[5];
        }

        data[1]++;
        break;
    case 7:
        if (!sub_801F644(2))
            data[0] = data[5];
        break;
    case 4:
        if (!gUnknown_02022C84->unk13 && data[2])
        {
            if (GetLinkPlayerCount() == 2)
            {
                sub_80104B0();
                gUnknown_02022C84->unk17 = 1;
                DestroyTask(taskId);
                return;
            }

            sub_8011DE0(data[2]);
        }

        data[0] = 3;
        break;
    case 5:
        if (gUnknown_02022C84->unk13)
            gUnknown_02022C84->unk17 = 2;

        DestroyTask(taskId);
        break;
    case 6:
        gUnknown_02022C84->unk17 = 3;
        DestroyTask(taskId);
        break;
    case 2:
        if (!sub_8011A9C())
        {
            if (!gUnknown_02022C84->unk13)
                sub_80110B8(gUnknown_02022C84->unkD);

            data[0] = 1;
        }
        break;
    }
}

static bool8 sub_801F4D0(void)
{
    gUnknown_02022C88 = Alloc(sizeof(*gUnknown_02022C88));
    if (gUnknown_02022C88 && sub_8020890())
    {
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_082F2C60, ARRAY_COUNT(gUnknown_082F2C60));
        InitWindows(gUnknown_082F2C70);
        reset_temp_tile_data_buffers();
        sub_8020770();
        sub_801F574(gUnknown_02022C88);
        sub_801F580();
        sub_801F5EC(0, 0);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool32 sub_801F534(void)
{
    return sub_801F644(0);
}

static void sub_801F544(void)
{
    sub_80208D0();
    if (gUnknown_02022C88)
        FREE_AND_SET_NULL(gUnknown_02022C88);

    FreeAllWindowBuffers();
    gScanlineEffect.state = 3;
}

static void sub_801F574(struct UnionRoomChat2 *arg0)
{
    arg0->unk18 = 0xFF;
    arg0->unk1E = 0xFF;
    arg0->unk1A = 0;
}

static void sub_801F580(void)
{
    int i;

    if (!gUnknown_02022C88)
        return;

    for (i = 0; i < 3; i++)
    {
        gUnknown_02022C88->unk0[i].unk0 = sub_801FDD8;
        gUnknown_02022C88->unk0[i].unk4 = 0;
        gUnknown_02022C88->unk0[i].unk5 = 0;
    }
}

static void sub_801F5B8(void)
{
    int i;

    if (!gUnknown_02022C88)
        return;

    for (i = 0; i < 3; i++)
    {
        gUnknown_02022C88->unk0[i].unk4 =
            gUnknown_02022C88->unk0[i].unk0(&gUnknown_02022C88->unk0[i].unk5);
    }
}

static void sub_801F5EC(u16 arg0, u8 arg1)
{
    u32 i;

    gUnknown_02022C88->unk0[arg1].unk0 = sub_801FDD8;
    for (i = 0; i < 21; i++)
    {
        if (gUnknown_082F2C98[i].unk0 == arg0)
        {
            gUnknown_02022C88->unk0[arg1].unk0 = gUnknown_082F2C98[i].unk4;
            gUnknown_02022C88->unk0[arg1].unk4 = 1;
            gUnknown_02022C88->unk0[arg1].unk5 = 0;
            break;
        }
    }
}

static bool8 sub_801F644(u8 arg0)
{
    return gUnknown_02022C88->unk0[arg0].unk4;
}

bool32 sub_801F658(u8 *state)
{
    if (free_temp_tile_data_buffers_if_possible() == TRUE)
        return TRUE;

    switch (*state)
    {
    case 0:
        sub_8020480();
        sub_8020538();
        break;
    case 1:
        sub_8020584();
        break;
    case 2:
        sub_80205B4();
        break;
    case 3:
        sub_8020604();
        break;
    case 4:
        sub_8020680();
        break;
    case 5:
        sub_80206A4();
        sub_80206D0();
        sub_8020740();
        sub_80206E8();
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_80208E8();
            sub_8020A68();
            sub_8020B20();
        }
        break;
    default:
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

bool32 sub_801F6F8(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_80203B0();
        CopyWindowToVram(3, 3);
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    (*state)++;
    return TRUE;
}

bool32 sub_801F730(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_802040C();
        CopyWindowToVram(3, 3);
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    (*state)++;
    return TRUE;
}

bool32 sub_801F768(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_802091C(TRUE);
        if (sub_8020320())
            return TRUE;

        sub_80201A4();
        CopyWindowToVram(2, 2);
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;
        break;
    case 2:
        if (sub_8020368())
            return TRUE;

        sub_802093C();
        sub_802091C(FALSE);
        sub_8020B80();
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

bool32 sub_801F7D4(u8 *state)
{
    sub_802093C();
    return FALSE;
}

bool32 sub_801F7E0(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_801FF18(0, 0);
        sub_801FDDC(23, 11, 1);
        CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    (*state)++;
    return TRUE;
}

bool32 sub_801F82C(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_8020094();
        sub_801FEBC();
        CopyBgTilemapBufferToVram(0);
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;

        sub_80200C8();
        sub_801FEE4();
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

bool32 sub_801F870(u8 *state)
{
    u32 var0, var1;
    u8 *str;

    switch (*state)
    {
    case 0:
        sub_801F0EC(&var0, &var1);
        sub_80200EC(var0, var1, 0);
        str = sub_801F0D0();
        sub_8020118(0, str, 3, 1, 2);
        CopyWindowToVram(1, 2);
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_8020B80();
            return FALSE;
        }
        return TRUE;
    }

    (*state)++;
    return TRUE;
}

bool32 sub_801F8DC(u8 *state)
{
    u16 var0;
    u8 *str;
    u16 length;

    switch (*state)
    {
    case 0:
        var0 = sub_801F144();
        str = sub_801F114();
        length = StringLength_Multibyte(str);
        sub_80200EC(var0, length, PIXEL_FILL(6));
        sub_8020118(var0, str, 0, 4, 5);
        CopyWindowToVram(1, 2);
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_801FF18(1, 16);
            CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        }
        else
        {
            return TRUE;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            sub_80209AC(1);
        else
            return TRUE;
        break;
    case 3:
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

bool32 sub_801F984(u8 *state)
{
    u16 var0;
    u8 *str;
    u16 length;

    switch (*state)
    {
    case 0:
        var0 = sub_801F144();
        str = sub_801F114();
        length = StringLength_Multibyte(str);
        sub_80200EC(var0, length, PIXEL_FILL(0));
        sub_8020118(var0, str, 3, 1, 2);
        CopyWindowToVram(1, 2);
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_8020094();
            CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        }
        else
        {
            return TRUE;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            sub_80209AC(0);
            sub_80200C8();
        }
        else
        {
            return TRUE;
        }
        break;
    case 3:
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

bool32 sub_801FA2C(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_80201A4();
        CopyWindowToVram(2, 2);
        (*state)++;
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;
        else
            return FALSE;
    }

    return TRUE;
}

bool32 sub_801FA68(u8 *state)
{
    u16 var0;
    u8 *str;
    u8 var1;

    switch (*state)
    {
    case 0:
        var0 = gUnknown_02022C88->unk1A;
        str = sub_801F180();
        var1 = sub_801F18C();
        sub_8020420(var0, str, var1);
        CopyWindowToVram(0, 2);
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;

        if (gUnknown_02022C88->unk1A < 9)
        {
            gUnknown_02022C88->unk1A++;
            *state = 4;
            return FALSE;
        }
        else
        {
            gUnknown_02022C88->unk1C = 0;
            (*state)++;
        }
        // fall through
    case 2:
        ScrollWindow(0, 0, 5, PIXEL_FILL(1));
        CopyWindowToVram(0, 2);
        gUnknown_02022C88->unk1C++;
        (*state)++;
        // fall through
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;

        if (gUnknown_02022C88->unk1C < 3)
        {
            (*state)--;
            return TRUE;
        }
        break;
    case 4:
        return FALSE;
    default:
        return TRUE;
    }

    (*state)++;
    return TRUE;
}

bool32 sub_801FB44(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_80209E0();
        (*state)++;
        break;
    case 1:
        return sub_8020A1C();
    }

    return TRUE;
}

bool32 sub_801FB70(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_801FF18(3, 16);
        CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 sub_801FBB4(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_801FF18(4, 0);
        CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 sub_801FBF8(u8 *state)
{
    u8 *str;

    switch (*state)
    {
    case 0:
        DynamicPlaceholderTextUtil_Reset();
        str = sub_801F1D0();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, str);
        sub_801FF18(5, 0);
        CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 sub_801FC4C(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_801FF18(6, 0);
        sub_801FDDC(23, 10, 1);
        CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 sub_801FC9C(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_801FF18(7, 0);
        sub_801FDDC(23, 10, 1);
        CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 sub_801FCEC(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_801FF18(8, 0);
        CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 sub_801FD30(u8 *state)
{
    switch (*state)
    {
    case 0:
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gSaveBlock2Ptr->playerName);
        sub_801FF18(9, 0);
        CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 sub_801FD88(u8 *state)
{
    switch (*state)
    {
    case 0:
        sub_801FF18(10, 0);
        sub_801FDDC(23, 10, 1);
        CopyWindowToVram(gUnknown_02022C88->unk1E, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool32 sub_801FDD8(u8 *arg0)
{
    return FALSE;
}

static void sub_801FDDC(u8 left, u8 top, u8 initialCursorPos)
{
    struct WindowTemplate template;
    template.bg = 0;
    template.tilemapLeft = left;
    template.tilemapTop = top;
    template.width = 6;
    template.height = 4;
    template.paletteNum = 14;
    template.baseBlock = 0x52;
    gUnknown_02022C88->unk18 = AddWindow(&template);
    if (gUnknown_02022C88->unk18 != 0xFF)
    {
        FillWindowPixelBuffer(gUnknown_02022C88->unk18, PIXEL_FILL(1));
        PutWindowTilemap(gUnknown_02022C88->unk18);
        AddTextPrinterParameterized(gUnknown_02022C88->unk18, 1, gText_Yes, 8, 1, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(gUnknown_02022C88->unk18, 1, gText_No, 8, 17, TEXT_SPEED_FF, NULL);
        DrawTextBorderOuter(gUnknown_02022C88->unk18, 1, 13);
        InitMenuInUpperLeftCornerPlaySoundWhenAPressed(gUnknown_02022C88->unk18, 2, initialCursorPos);
    }
}

static void sub_801FEBC(void)
{
    if (gUnknown_02022C88->unk18 != 0xFF)
    {
        ClearStdWindowAndFrameToTransparent(gUnknown_02022C88->unk18, FALSE);
        ClearWindowTilemap(gUnknown_02022C88->unk18);
    }
}

static void sub_801FEE4(void)
{
    if (gUnknown_02022C88->unk18 != 0xFF)
    {
        RemoveWindow(gUnknown_02022C88->unk18);
        gUnknown_02022C88->unk18 = 0xFF;
    }
}

static s8 sub_801FF08(void)
{
    return Menu_ProcessInput();
}

static void sub_801FF18(int arg0, u16 arg1)
{
    const u8 *str;
    int windowId;
    struct WindowTemplate template;
    template.bg = 0;
    template.tilemapLeft = 8;
    template.tilemapTop = 16;
    template.width = 21;
    template.height = 4;
    template.paletteNum = 14;
    template.baseBlock = 0x6A;
    if (gUnknown_082F2D40[arg0].unkA)
    {
        template.tilemapLeft -= 7;
        template.width += 7;
    }

    gUnknown_02022C88->unk1E = AddWindow(&template);
    windowId = gUnknown_02022C88->unk1E;
    if (gUnknown_02022C88->unk1E == 0xFF)
        return;

    if (gUnknown_082F2D40[arg0].unk9)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gUnknown_02022C88->unk22, gUnknown_082F2D40[arg0].unk0);
        str = gUnknown_02022C88->unk22;
    }
    else
    {
        str = gUnknown_082F2D40[arg0].unk0;
    }

    ChangeBgY(0, arg1 * 256, 0);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (gUnknown_082F2D40[arg0].unk4 == 1)
    {
        DrawTextBorderInner(windowId, 0xA, 2);
        AddTextPrinterParameterized5(
            windowId,
            1,
            str,
            gUnknown_082F2D40[arg0].unk5 + 8,
            gUnknown_082F2D40[arg0].unk6 + 8,
            TEXT_SPEED_FF,
            NULL,
            gUnknown_082F2D40[arg0].unk7,
            gUnknown_082F2D40[arg0].unk8);
    }
    else
    {
        DrawTextBorderOuter(windowId, 0xA, 2);
        AddTextPrinterParameterized5(
            windowId,
            1,
            str,
            gUnknown_082F2D40[arg0].unk5,
            gUnknown_082F2D40[arg0].unk6,
            TEXT_SPEED_FF,
            NULL,
            gUnknown_082F2D40[arg0].unk7,
            gUnknown_082F2D40[arg0].unk8);
    }

    gUnknown_02022C88->unk1E = windowId;
}

static void sub_8020094(void)
{
    if (gUnknown_02022C88->unk1E != 0xFF)
    {
        ClearStdWindowAndFrameToTransparent(gUnknown_02022C88->unk1E, FALSE);
        ClearWindowTilemap(gUnknown_02022C88->unk1E);
    }

    ChangeBgY(0, 0, 0);
}

static void sub_80200C8(void)
{
    if (gUnknown_02022C88->unk1E != 0xFF)
    {
        RemoveWindow(gUnknown_02022C88->unk1E);
        gUnknown_02022C88->unk1E = 0xFF;
    }
}

static void sub_80200EC(u16 x, u16 width, u8 fillValue)
{
    FillWindowPixelRect(1, fillValue, x * 8, 1, width * 8, 14);
}

static void sub_8020118(u16 x, u8 *str, u8 fillValue, u8 arg3, u8 arg4)
{
    u8 *str2;
    u8 sp[38];
    if (fillValue)
        sub_80200EC(x, sub_801F198() - x, fillValue);

    sp[0] = fillValue;
    sp[1] = arg3;
    sp[2] = arg4;
    str2 = &sp[4];
    str2[0] = EXT_CTRL_CODE_BEGIN;
    str2[1] = EXT_CTRL_CODE_MIN_LETTER_SPACING;
    str2[2] = 8;
    StringCopy(&str2[3], str);
    AddTextPrinterParameterized3(1, 2, x * 8, 1, sp, TEXT_SPEED_FF, str2);
}

static void sub_80201A4(void)
{
    u8 page;
    int i;
    int var1;
    u16 left;
    u16 top;
    u8 sp[52];
    u8 *str;
    u8 *str2;

    FillWindowPixelBuffer(2, PIXEL_FILL(15));
    page = GetCurrentKeyboardPage();
    sp[0] = 0;
    sp[1] = 14;
    sp[2] = 13;
    if (page != UNION_ROOM_KB_PAGE_COUNT)
    {
        str = &sp[4];
        str[0] = EXT_CTRL_CODE_BEGIN;
        str[1] = EXT_CTRL_CODE_MIN_LETTER_SPACING;
        var1 = 8;
        str[2] = var1;
        left = var1;
        if (page == UNION_ROOM_KB_PAGE_EMOJI)
            left = 6;

        for (i = 0, top = 0; i < UNION_ROOM_KB_ROW_COUNT; i++, top += 12)
        {
            if (!sUnionRoomKeyboardText[page][i])
                return;

            StringCopy(&sp[7], sUnionRoomKeyboardText[page][i]);
            AddTextPrinterParameterized3(2, 0, left, top, sp, TEXT_SPEED_FF, &sp[4]);
        }
    }
    else
    {
        left = 4;
        for (i = 0, top = 0; i < 10; i++, top += 12)
        {
            str2 = sub_801EE6C(i);
            if (GetStringWidth(0, str2, 0) <= 40)
            {
                AddTextPrinterParameterized3(2, 0, left, top, sp, TEXT_SPEED_FF, str2);
            }
            else
            {
                int length = StringLength_Multibyte(str2);
                do
                {
                    length--;
                    StringCopyN_Multibyte(&sp[4], str2, length);
                } while (GetStringWidth(0, &sp[4], 0) > 35);

                AddTextPrinterParameterized3(2, 0, left, top, sp, TEXT_SPEED_FF, &sp[4]);
                AddTextPrinterParameterized3(2, 0, left + 35, top, sp, TEXT_SPEED_FF, gText_Ellipsis);
            }
        }
    }
}

static bool32 sub_8020320(void)
{
    if (gUnknown_02022C88->unk20 < 56)
    {
        gUnknown_02022C88->unk20 += 12;
        if (gUnknown_02022C88->unk20 >= 56)
            gUnknown_02022C88->unk20 = 56;

        if (gUnknown_02022C88->unk20 < 56)
        {
            sub_80207C0(gUnknown_02022C88->unk20);
            return TRUE;
        }
    }

    sub_8020818(gUnknown_02022C88->unk20);
    return FALSE;
}

static bool32 sub_8020368(void)
{
    if (gUnknown_02022C88->unk20 > 0)
    {
        gUnknown_02022C88->unk20 -= 12;
        if (gUnknown_02022C88->unk20 <= 0)
            gUnknown_02022C88->unk20 = 0;

        if (gUnknown_02022C88->unk20 > 0)
        {
            sub_80207C0(gUnknown_02022C88->unk20);
            return TRUE;
        }
    }

    sub_8020818(gUnknown_02022C88->unk20);
    return FALSE;
}

static void sub_80203B0(void)
{
    FillWindowPixelBuffer(3, PIXEL_FILL(1));
    DrawTextBorderOuter(3, 1, 13);
    PrintTextArray(3, 2, 8, 1, 14, 5, gUnknown_082F2DC8);
    sub_81983AC(3, 2, 0, 1, 14, 5, GetCurrentKeyboardPage());
    PutWindowTilemap(3);
}

static void sub_802040C(void)
{
    ClearStdWindowAndFrameToTransparent(3, FALSE);
    ClearWindowTilemap(3);
}

static void sub_8020420(u16 row, u8 *str, u8 arg2)
{
    u8 color[3];
    color[0] = 1;
    color[1] = arg2 * 2 + 2;
    color[2] = arg2 * 2 + 3;
    FillWindowPixelRect(0, PIXEL_FILL(1), 0, row * 15, 168, 15);
    AddTextPrinterParameterized3(0, 2, 0, row * 15 + 1, color, TEXT_SPEED_FF, str);
}

static void sub_8020480(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJWIN_ON);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(64, 240));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, 144));
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_BG2 | WININ_WIN0_BG3
                              | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
}

static void sub_8020538(void)
{
    SetBgTilemapBuffer(0, gUnknown_02022C88->unk128);
    SetBgTilemapBuffer(1, gUnknown_02022C88->unk928);
    SetBgTilemapBuffer(3, gUnknown_02022C88->unk1128);
    SetBgTilemapBuffer(2, gUnknown_02022C88->unk1928);
}

static void sub_8020584(void)
{
    RequestDma3Fill(0, (void *)BG_CHAR_ADDR(0), 0x20, 1);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
    CopyBgTilemapBufferToVram(0);
}

static void sub_80205B4(void)
{
    LoadPalette(gUnknown_08DD4BD0, 0x70, 0x20);
    LoadPalette(gUnknown_08DD4BB0, 0xC0, 0x20);
    decompress_and_copy_tile_data_to_vram(1, gUnknown_08DD4BF0, 0, 0, 0);
    CopyToBgTilemapBuffer(1, gUnknown_08DD4C4C, 0, 0);
    CopyBgTilemapBufferToVram(1);
}

static void sub_8020604(void)
{
    u8 *ptr;

    LoadPalette(gLinkMiscMenu_Pal, 0, 0x20);
    ptr = decompress_and_copy_tile_data_to_vram(2, gLinkMiscMenu_Gfx, 0, 0, 0);
    if (ptr)
    {
        CpuFastCopy(&ptr[0x220], gUnknown_02022C88->unk2128, 0x20);
        CpuFastCopy(&ptr[0x420], gUnknown_02022C88->unk2148, 0x20);
    }

    CopyToBgTilemapBuffer(2, gLinkMiscMenu_Tilemap, 0, 0);
    CopyBgTilemapBufferToVram(2);
}

static void sub_8020680(void)
{
    LoadPalette(gUnknown_082F2C20, 0x80, 0x20);
    RequestDma3Fill(0, (void *)BG_CHAR_ADDR(1) + 0x20, 0x20, 1);
}

static void sub_80206A4(void)
{
    LoadPalette(gUnknown_082F2C40, 0xF0, 0x20);
    PutWindowTilemap(0);
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    CopyWindowToVram(0, 3);
}

static void sub_80206D0(void)
{
    PutWindowTilemap(2);
    sub_80201A4();
    CopyWindowToVram(2, 3);
}

static void sub_80206E8(void)
{
    int i;
    u8 var0[2];
    var0[0] = 0;
    var0[1] = 0xFF;

    for (i = 0; i < 15; i++)
        BlitBitmapToWindow(1, gUnknown_02022C88->unk2128, i * 8, 0, 8, 16);

    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PutWindowTilemap(1);
    CopyWindowToVram(1, 3);
}

static void sub_8020740(void)
{
    FillWindowPixelBuffer(3, PIXEL_FILL(1));
    LoadUserWindowBorderGfx(3, 1, 0xD0);
    LoadUserWindowBorderGfx_(3, 0xA, 0x20);
    LoadPalette(gUnknown_0860F074, 0xE0,  0x20);
}

static void sub_8020770(void)
{
    struct ScanlineEffectParams params;
    params.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
    params.dmaDest = &REG_BG1HOFS;
    params.initState = 1;
    params.unused9 = 0;
    gUnknown_02022C88->unk20 = 0;
    CpuFastFill(0, gScanlineEffectRegBuffers, sizeof(gScanlineEffectRegBuffers));
    ScanlineEffect_SetParams(params);
}

static void sub_80207C0(s16 arg0)
{
    CpuFill16(arg0, gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], 0x120);
    CpuFill16(0, gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer] + 0x90, 0x20);
}

static void sub_8020818(s16 arg0)
{
    CpuFill16(arg0, gScanlineEffectRegBuffers[0],         0x120);
    CpuFill16(0,    gScanlineEffectRegBuffers[0] +  0x90, 0x20);
    CpuFill16(arg0, gScanlineEffectRegBuffers[0] + 0x3C0, 0x120);
    CpuFill16(0,    gScanlineEffectRegBuffers[0] + 0x450, 0x20);
}

static bool32 sub_8020890(void)
{
    u32 i;
    for (i = 0; i < 5; i++)
        LoadCompressedSpriteSheet(&gUnknown_082F3134[i]);

    LoadSpritePalette(&gUnknown_082F315C);
    gUnknown_02022C8C = Alloc(0x18);
    if (!gUnknown_02022C8C)
        return FALSE;

    return TRUE;
}

static void sub_80208D0(void)
{
    if (gUnknown_02022C8C)
        Free(gUnknown_02022C8C);
}

static void sub_80208E8(void)
{
    u8 spriteId = CreateSprite(&gUnknown_082F319C, 10, 24, 0);
    gUnknown_02022C8C->unk0 = &gSprites[spriteId];
}

static void sub_802091C(bool32 invisible)
{
    gUnknown_02022C8C->unk0->invisible = invisible;
}

static void sub_802093C(void)
{
    u8 x, y;
    u8 page = GetCurrentKeyboardPage();
    sub_801F0BC(&x, &y);
    if (page != UNION_ROOM_KB_PAGE_COUNT)
    {
        StartSpriteAnim(gUnknown_02022C8C->unk0, 0);
        gUnknown_02022C8C->unk0->pos1.x = x * 8 + 10;
        gUnknown_02022C8C->unk0->pos1.y = y * 12 + 24;
    }
    else
    {
        StartSpriteAnim(gUnknown_02022C8C->unk0, 2);
        gUnknown_02022C8C->unk0->pos1.x = 24;
        gUnknown_02022C8C->unk0->pos1.y = y * 12 + 24;
    }
}

static void sub_80209AC(int arg0)
{
    const u16 *palette = &gUnknown_082F2DF0[arg0 * 2 + 1];
    u8 index = IndexOfSpritePaletteTag(0);
    LoadPalette(palette, index * 16 + 0x101, 4);
}

static void sub_80209E0(void)
{
    if (GetCurrentKeyboardPage() != UNION_ROOM_KB_PAGE_COUNT)
        StartSpriteAnim(gUnknown_02022C8C->unk0, 1);
    else
        StartSpriteAnim(gUnknown_02022C8C->unk0, 3);

    gUnknown_02022C8C->unk14 = 0;
}

static bool32 sub_8020A1C(void)
{
    if (gUnknown_02022C8C->unk14 > 3)
        return FALSE;

    if (++gUnknown_02022C8C->unk14 > 3)
    {
        if (GetCurrentKeyboardPage() != UNION_ROOM_KB_PAGE_COUNT)
            StartSpriteAnim(gUnknown_02022C8C->unk0, 0);
        else
            StartSpriteAnim(gUnknown_02022C8C->unk0, 2);

        return FALSE;
    }

    return TRUE;
}

static void sub_8020A68(void)
{
    u8 spriteId = CreateSprite(&gUnknown_082F31BC, 76, 152, 2);
    gUnknown_02022C8C->unk8 = &gSprites[spriteId];
    spriteId = CreateSprite(&gUnknown_082F31D4, 64, 152, 1);
    gUnknown_02022C8C->unk4 = &gSprites[spriteId];
}

static void sub_8020ABC(struct Sprite *sprite)
{
    int var0 = sub_801F198();
    if (var0 == 15)
    {
        sprite->invisible = 1;
    }
    else
    {
        sprite->invisible = 0;
        sprite->pos1.x = var0 * 8 + 76;
    }
}

static void sub_8020AF4(struct Sprite *sprite)
{
    if (++sprite->data[0] > 4)
    {
        sprite->data[0] = 0;
        if (++sprite->pos2.x > 4)
            sprite->pos2.x = 0;
    }
}

static void sub_8020B20(void)
{
    u8 spriteId = CreateSprite(&gUnknown_082F322C, 8, 152, 3);
    gUnknown_02022C8C->unkC = &gSprites[spriteId];
    spriteId = CreateSprite(&gUnknown_082F3244, 32, 152, 4);
    gUnknown_02022C8C->unk10 = &gSprites[spriteId];
    gUnknown_02022C8C->unk10->invisible = 1;
}

static void sub_8020B80(void)
{
    if (GetCurrentKeyboardPage() == UNION_ROOM_KB_PAGE_COUNT)
    {
        if (sub_801F0DC() != 0)
        {
            gUnknown_02022C8C->unk10->invisible = 0;
            StartSpriteAnim(gUnknown_02022C8C->unk10, 3);
        }
        else
        {
            gUnknown_02022C8C->unk10->invisible = 1;
        }
    }
    else
    {
        int anim = sub_801F1A4();
        if (anim == 3)
        {
            gUnknown_02022C8C->unk10->invisible = 1;
        }
        else
        {
            gUnknown_02022C8C->unk10->invisible = 0;
            StartSpriteAnim(gUnknown_02022C8C->unk10, anim);
        }
    }

}
