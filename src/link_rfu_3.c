#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "link_rfu.h"
#include "string_util.h"
#include "random.h"
#include "text.h"
#include "event_data.h"

enum {
    WIRELESS_STATUS_ANIM_3_BARS,
    WIRELESS_STATUS_ANIM_2_BARS,
    WIRELESS_STATUS_ANIM_1_BAR,
    WIRELESS_STATUS_ANIM_SEARCHING,
    WIRELESS_STATUS_ANIM_ERROR,
};

#define TAG_GFX_STATUS_INDICATOR 0xD431
#define TAG_PAL_STATUS_INDICATOR 0xD432

#define UNUSED_QUEUE_NUM_SLOTS 2
#define UNUSED_QUEUE_SLOT_LENGTH 256

struct RfuUnusedQueue
{
    u8 slots[UNUSED_QUEUE_NUM_SLOTS][UNUSED_QUEUE_SLOT_LENGTH];
    vu8 recvSlot;
    vu8 sendSlot;
    vu8 count;
    vu8 full;
};

EWRAM_DATA u8 gWirelessStatusIndicatorSpriteId = 0;

static u8 sSequenceArrayValOffset;

static const u16 sWirelessLinkIconPalette[] = INCBIN_U16("graphics/link/wireless_icon.gbapal");
static const u32 sWirelessLinkIconPic[] = INCBIN_U32("graphics/link/wireless_icon.4bpp.lz");

// Most of the below two tables won't make sense with ASCII encoding.
static const u8 sWireless_ASCIItoRSETable[256] = {
    EOS,
    0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x37,
    0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
    0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
    [' '] = CHAR_SPACE,
    ['!'] = CHAR_EXCL_MARK,
    0xb5, 0xb6, 0xb1, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xb2, 0xf1, 0x00,
    ['-'] = CHAR_HYPHEN,
    ['.'] = CHAR_PERIOD,
    ['/'] = CHAR_SLASH,
    ['0'] = CHAR_0,
    ['1'] = CHAR_1,
    ['2'] = CHAR_2,
    ['3'] = CHAR_3,
    ['4'] = CHAR_4,
    ['5'] = CHAR_5,
    ['6'] = CHAR_6,
    ['7'] = CHAR_7,
    ['8'] = CHAR_8,
    ['9'] = CHAR_9,
    0x00, 0x9b, 0x9c, 0x9d, 0x9e, 0x9f, 0x00,
    ['A'] = CHAR_A,
    ['B'] = CHAR_B,
    ['C'] = CHAR_C,
    ['D'] = CHAR_D,
    ['E'] = CHAR_E,
    ['F'] = CHAR_F,
    ['G'] = CHAR_G,
    ['H'] = CHAR_H,
    ['I'] = CHAR_I,
    ['J'] = CHAR_J,
    ['K'] = CHAR_K,
    ['L'] = CHAR_L,
    ['M'] = CHAR_M,
    ['N'] = CHAR_N,
    ['O'] = CHAR_O,
    ['P'] = CHAR_P,
    ['Q'] = CHAR_Q,
    ['R'] = CHAR_R,
    ['S'] = CHAR_S,
    ['T'] = CHAR_T,
    ['U'] = CHAR_U,
    ['V'] = CHAR_V,
    ['W'] = CHAR_W,
    ['X'] = CHAR_X,
    ['Y'] = CHAR_Y,
    ['Z'] = CHAR_Z,
    0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0x00,
    ['a'] = CHAR_a,
    ['b'] = CHAR_b,
    ['c'] = CHAR_c,
    ['d'] = CHAR_d,
    ['e'] = CHAR_e,
    ['f'] = CHAR_f,
    ['g'] = CHAR_g,
    ['h'] = CHAR_h,
    ['i'] = CHAR_i,
    ['j'] = CHAR_j,
    ['k'] = CHAR_k,
    ['l'] = CHAR_l,
    ['m'] = CHAR_m,
    ['n'] = CHAR_n,
    ['o'] = CHAR_o,
    ['p'] = CHAR_p,
    ['q'] = CHAR_q,
    ['r'] = CHAR_r,
    ['s'] = CHAR_s,
    ['t'] = CHAR_t,
    ['u'] = CHAR_u,
    ['v'] = CHAR_v,
    ['w'] = CHAR_w,
    ['x'] = CHAR_x,
    ['y'] = CHAR_y,
    ['z'] = CHAR_z,
    0x2d, 0x2f, 0x30, 0x31, 0x32,
    0x33, 0x34, 0x35, 0x36, 0x50, 0x00, 0x01, 0x02,
    0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
    0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12,
    0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a,
    0x1b, 0xad, 0xb3, 0xb4, 0x00, 0xaf, 0x7d, 0x7f,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0xa0,
    0xae, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
    0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
    0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
    0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7e, 0xb0, 0xac,
    0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23,
    0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b,
    0x2c, 0x2e, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c,
    0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94
};

static const u8 sWireless_RSEtoASCIITable[256] = {
    [CHAR_SPACE] = ' ',
    0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d,
    0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95,
    0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0x9d,
    0x9e, 0x9f, 0xa0, 0xe0, 0xe1, 0xe2, 0xe3, 0xe4,
    0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0xec,
    0xed, 0xee, 0xef, 0xf0, 0x7b, 0xf1, 0x7c, 0x7d,
    0x7e, 0x7f, 0x80, 0x81, 0x82, 0x83, 0x07, 0x08,
    0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
    0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
    0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x84,
    0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8,
    0xb9, 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0,
    0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8,
    0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0,
    0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8,
    0xd9, 0xda, 0xdb, 0xdc, 0xa6, 0xdd, 0xa7, 0xa8,
    0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xf2, 0xf3,
    0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb,
    0xfc, 0xfd, 0xfe, 0xff, 0x01, 0x02, 0x03, 0x04,
    0x05, 0x06, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0xaf,
    [CHAR_0] = '0',
    [CHAR_1] = '1',
    [CHAR_2] = '2',
    [CHAR_3] = '3',
    [CHAR_4] = '4',
    [CHAR_5] = '5',
    [CHAR_6] = '6',
    [CHAR_7] = '7',
    [CHAR_8] = '8',
    [CHAR_9] = '9',
    [CHAR_EXCL_MARK] = '!',
    0xdf, 0xa1, 0xb0, 0xa5, 0xde, 0x24, 0x2a,
    0xa2, 0xa3, 0x22, 0x23, 0x20, 0xa4, 0x20,
    [CHAR_SLASH] = '/',
    [CHAR_A] = 'A',
    [CHAR_B] = 'B',
    [CHAR_C] = 'C',
    [CHAR_D] = 'D',
    [CHAR_E] = 'E',
    [CHAR_F] = 'F',
    [CHAR_G] = 'G',
    [CHAR_H] = 'H',
    [CHAR_I] = 'I',
    [CHAR_J] = 'J',
    [CHAR_K] = 'K',
    [CHAR_L] = 'L',
    [CHAR_M] = 'M',
    [CHAR_N] = 'N',
    [CHAR_O] = 'O',
    [CHAR_P] = 'P',
    [CHAR_Q] = 'Q',
    [CHAR_R] = 'R',
    [CHAR_S] = 'S',
    [CHAR_T] = 'T',
    [CHAR_U] = 'U',
    [CHAR_V] = 'V',
    [CHAR_W] = 'W',
    [CHAR_X] = 'X',
    [CHAR_Y] = 'Y',
    [CHAR_Z] = 'Z',
    [CHAR_a] = 'a',
    [CHAR_b] = 'b',
    [CHAR_c] = 'c',
    [CHAR_d] = 'd',
    [CHAR_e] = 'e',
    [CHAR_f] = 'f',
    [CHAR_g] = 'g',
    [CHAR_h] = 'h',
    [CHAR_i] = 'i',
    [CHAR_j] = 'j',
    [CHAR_k] = 'k',
    [CHAR_l] = 'l',
    [CHAR_m] = 'm',
    [CHAR_n] = 'n',
    [CHAR_o] = 'o',
    [CHAR_p] = 'p',
    [CHAR_q] = 'q',
    [CHAR_r] = 'r',
    [CHAR_s] = 's',
    [CHAR_t] = 't',
    [CHAR_u] = 'u',
    [CHAR_v] = 'v',
    [CHAR_w] = 'w',
    [CHAR_x] = 'x',
    [CHAR_y] = 'y',
    [CHAR_z] = 'z',
    0x20, 0x20, 0x2b, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
    [CHAR_DYNAMIC] = ' ',
    [CHAR_KEYPAD_ICON] = ' ',
    [CHAR_EXTRA_SYMBOL] = ' ',
    [CHAR_PROMPT_SCROLL] = ' ',
    [CHAR_PROMPT_CLEAR] = ' ',
    [EXT_CTRL_CODE_BEGIN] = ' ',
    [PLACEHOLDER_BEGIN] = ' ',
    [CHAR_NEWLINE] = ' ',
    [EOS] = 0
};

static const struct OamData sWirelessStatusIndicatorOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const union AnimCmd sWirelessStatusIndicator_3Bars[] = {
    ANIMCMD_FRAME( 4,  5),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_FRAME(12,  5),
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_FRAME(12,  5),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sWirelessStatusIndicator_2Bars[] = {
    ANIMCMD_FRAME( 4,  5),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_FRAME(12, 10),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sWirelessStatusIndicator_1Bar[] = {
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sWirelessStatusIndicator_Searching[] = {
    ANIMCMD_FRAME( 4, 10),
    ANIMCMD_FRAME(20, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sWirelessStatusIndicator_Error[] = {
    ANIMCMD_FRAME(24, 10),
    ANIMCMD_FRAME( 4, 10),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sWirelessStatusIndicatorAnims[] = {
    [WIRELESS_STATUS_ANIM_3_BARS]    = sWirelessStatusIndicator_3Bars,
    [WIRELESS_STATUS_ANIM_2_BARS]    = sWirelessStatusIndicator_2Bars,
    [WIRELESS_STATUS_ANIM_1_BAR]     = sWirelessStatusIndicator_1Bar,
    [WIRELESS_STATUS_ANIM_SEARCHING] = sWirelessStatusIndicator_Searching,
    [WIRELESS_STATUS_ANIM_ERROR]     = sWirelessStatusIndicator_Error
};

static const struct CompressedSpriteSheet sWirelessStatusIndicatorSpriteSheet = {
    sWirelessLinkIconPic, 0x0380, TAG_GFX_STATUS_INDICATOR
};

static const struct SpritePalette sWirelessStatusIndicatorSpritePalette = {
    sWirelessLinkIconPalette, TAG_PAL_STATUS_INDICATOR
};

static const struct SpriteTemplate sWirelessStatusIndicatorSpriteTemplate = {
    .tileTag = TAG_GFX_STATUS_INDICATOR,
    .paletteTag = TAG_PAL_STATUS_INDICATOR,
    .oam = &sWirelessStatusIndicatorOamData,
    .anims = sWirelessStatusIndicatorAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

void RfuRecvQueue_Reset(struct RfuRecvQueue *queue)
{
    s32 i;
    s32 j;

    for (i = 0; i < RECV_QUEUE_NUM_SLOTS; i++)
    {
        for (j = 0; j < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; j++)
            queue->slots[i][j] = 0;
    }
    queue->sendSlot = 0;
    queue->recvSlot = 0;
    queue->count = 0;
    queue->full = FALSE;
}

void RfuSendQueue_Reset(struct RfuSendQueue *queue)
{
    s32 i;
    s32 j;

    for (i = 0; i < SEND_QUEUE_NUM_SLOTS; i++)
    {
        for (j = 0; j < COMM_SLOT_LENGTH; j++)
            queue->slots[i][j] = 0;
    }
    queue->sendSlot = 0;
    queue->recvSlot = 0;
    queue->count = 0;
    queue->full = FALSE;
}

static void RfuUnusedQueue_Reset(struct RfuUnusedQueue *queue)
{
    s32 i;
    s32 j;

    for (i = 0; i < UNUSED_QUEUE_NUM_SLOTS; i++)
    {
        for (j = 0; j < UNUSED_QUEUE_SLOT_LENGTH; j++)
            queue->slots[i][j] = 0;
    }
    queue->sendSlot = 0;
    queue->recvSlot = 0;
    queue->count = 0;
    queue->full = FALSE;
}

void RfuRecvQueue_Enqueue(struct RfuRecvQueue *queue, u8 *data)
{
    s32 i;
    u16 imeBak;
    u8 count;

    if (queue->count < RECV_QUEUE_NUM_SLOTS)
    {
        imeBak = REG_IME;
        REG_IME = 0;
        count = 0;
        for (i = 0; i < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; i += COMM_SLOT_LENGTH)
        {
            if (data[i] == 0 && data[i + 1] == 0)
                count++;
        }
        if (count != MAX_RFU_PLAYERS)
        {
            for (i = 0; i < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; i++)
                queue->slots[queue->recvSlot][i] = data[i];

            queue->recvSlot++;
            queue->recvSlot %= RECV_QUEUE_NUM_SLOTS;
            queue->count++;

            for (i = 0; i < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; i++)
                data[i] = 0;
        }
        REG_IME = imeBak;
    }
    else
    {
        queue->full = TRUE;
    }
}

void RfuSendQueue_Enqueue(struct RfuSendQueue *queue, u8 *data)
{
    s32 i;
    u16 imeBak;

    if (queue->count < SEND_QUEUE_NUM_SLOTS)
    {
        imeBak = REG_IME;
        REG_IME = 0;
        for (i = 0; i < COMM_SLOT_LENGTH; i++)
        {
            if (data[i] != 0)
                break;
        }
        if (i != COMM_SLOT_LENGTH)
        {
            for (i = 0; i < COMM_SLOT_LENGTH; i++)
                queue->slots[queue->recvSlot][i] = data[i];
            queue->recvSlot++;
            queue->recvSlot %= SEND_QUEUE_NUM_SLOTS;
            queue->count++;

            for (i = 0; i < COMM_SLOT_LENGTH; i++)
                data[i] = 0;
        }
        REG_IME = imeBak;
    }
    else
    {
        queue->full = TRUE;
    }
}

bool8 RfuRecvQueue_Dequeue(struct RfuRecvQueue *queue, u8 *src)
{
    u16 imeBak;
    s32 i;

    imeBak = REG_IME;
    REG_IME = 0;
    if (queue->recvSlot == queue->sendSlot || queue->full)
    {
        for (i = 0; i < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; i++)
            src[i] = 0;

        REG_IME = imeBak;
        return FALSE;
    }
    for (i = 0; i < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; i++)
    {
        src[i] = queue->slots[queue->sendSlot][i];
    }
    queue->sendSlot++;
    queue->sendSlot %= RECV_QUEUE_NUM_SLOTS;
    queue->count--;
    REG_IME = imeBak;
    return TRUE;
}

bool8 RfuSendQueue_Dequeue(struct RfuSendQueue *queue, u8 *src)
{
    s32 i;
    u16 imeBak;

    if (queue->recvSlot == queue->sendSlot || queue->full)
        return FALSE;

    imeBak = REG_IME;
    REG_IME = 0;
    for (i = 0; i < COMM_SLOT_LENGTH; i++)
        src[i] = queue->slots[queue->sendSlot][i];

    queue->sendSlot++;
    queue->sendSlot %= SEND_QUEUE_NUM_SLOTS;
    queue->count--;
    REG_IME = imeBak;
    return TRUE;
}

void RfuBackupQueue_Enqueue(struct RfuBackupQueue *queue, const u8 *data)
{
    s32 i;

    if (data[1] == 0)
    {
        RfuBackupQueue_Dequeue(queue, NULL);
    }
    else
    {
        for (i = 0; i < COMM_SLOT_LENGTH; i++)
            queue->slots[queue->recvSlot][i] = data[i];

        queue->recvSlot++;
        queue->recvSlot %= BACKUP_QUEUE_NUM_SLOTS;

        if (queue->count < BACKUP_QUEUE_NUM_SLOTS)
            queue->count++;
        else
            queue->sendSlot = queue->recvSlot;
    }
}

bool8 RfuBackupQueue_Dequeue(struct RfuBackupQueue *queue, u8 *src)
{
    s32 i;

    if (queue->count == 0)
        return FALSE;

    if (src != NULL)
    {
        for (i = 0; i < COMM_SLOT_LENGTH; i++)
            src[i] = queue->slots[queue->sendSlot][i];
    }
    queue->sendSlot++;
    queue->sendSlot %= BACKUP_QUEUE_NUM_SLOTS;
    queue->count--;
    return TRUE;
}

static void RfuUnusedQueue_Enqueue(struct RfuUnusedQueue *queue, u8 *data)
{
    s32 i;

    if (queue->count < UNUSED_QUEUE_NUM_SLOTS)
    {
        for (i = 0; i < UNUSED_QUEUE_SLOT_LENGTH; i++)
            queue->slots[queue->recvSlot][i] = data[i];

        queue->recvSlot++;
        queue->recvSlot %= UNUSED_QUEUE_NUM_SLOTS;
        queue->count++;
    }
    else
    {
        queue->full = TRUE;
    }
}

static bool8 RfuUnusedQueue_Dequeue(struct RfuUnusedQueue *queue, u8 *dest)
{
    s32 i;

    if (queue->recvSlot == queue->sendSlot || queue->full)
        return FALSE;

    for (i = 0; i < UNUSED_QUEUE_SLOT_LENGTH; i++)
        dest[i] = queue->slots[queue->sendSlot][i];

    queue->sendSlot++;
    queue->sendSlot %= UNUSED_QUEUE_NUM_SLOTS;
    queue->count--;
    return TRUE;
}

// Unused
// Populates an array with a sequence of numbers (which numbers depends on the mode)
// and sets the final element to the total of the other elements
#define SEQ_ARRAY_MAX_SIZE 200
static void PopulateArrayWithSequence(u8 *arr, u8 mode)
{
    s32 i;
    u8 rval;
    u16 total = 0;
    switch (mode)
    {
    case 0:
        // Populate with numbers 1-200
        // Total will be 20100
        for (i = 0; i < SEQ_ARRAY_MAX_SIZE; i++)
        {
            arr[i] = i + 1;
            total += i + 1;
        }
        *((u16 *)(arr + i)) = total;
        break;
    case 1:
        // Populate with numbers 1-100
        // Total will be 5050
        for (i = 0; i < 100; i++)
        {
            arr[i] = i + 1;
            total += i + 1;
        }
        *((u16 *)(arr + SEQ_ARRAY_MAX_SIZE)) = total;
        break;
    case 2:
        // Populate with random numbers 0-255
        // Total will be a number 0-51000
        for (i = 0; i < SEQ_ARRAY_MAX_SIZE; i++)
        {
            rval = Random();
            arr[i] = rval;
            total += rval;
        }
        *((u16 *)(arr + i)) = total;
        break;
    case 3:
        // Populate with numbers 1-200 + sSequenceArrayValOffset
        // Total will be a number 20100-51000
        for (i = 0; i < SEQ_ARRAY_MAX_SIZE; i++)
        {
            arr[i] = i + 1 + sSequenceArrayValOffset;
            total += (i + 1 + sSequenceArrayValOffset) & 0xFF;
        }
        *((u16 *)(arr + i)) = total;
        sSequenceArrayValOffset++;
        break;
    }
}

// File boundary here maybe?

static void PkmnStrToASCII(u8 *asciiStr, const u8 *pkmnStr)
{
    s32 i;

    for (i = 0; pkmnStr[i] != EOS; i++)
        asciiStr[i] = sWireless_RSEtoASCIITable[pkmnStr[i]];
    asciiStr[i] = 0;
}

static void ASCIIToPkmnStr(u8 *pkmnStr, const u8 *asciiStr)
{
    s32 i;

    for (i = 0; asciiStr[i] != 0; i++)
        pkmnStr[i] = sWireless_ASCIItoRSETable[asciiStr[i]];
    pkmnStr[i] = EOS;
}

static u8 GetConnectedChildStrength(u8 maxFlags)
{
    u8 flagCount = 0;
    u32 flags = gRfuLinkStatus->connSlotFlag;
    u8 i;

    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        for (i = 0; i < 4; flags >>= 1, i++)
        {
            if (flags & 1)
            {
                if (maxFlags == flagCount + 1)
                {
                    return gRfuLinkStatus->strength[i];
                    break;
                }
                flagCount++;
            }
        }
    }
    else
    {
        for (i = 0; i < 4; flags >>= 1, i++)
        {
            if (flags & 1)
                return gRfuLinkStatus->strength[i];
        }
    }
    return 0;
}

void InitHostRfuGameData(struct RfuGameData *data, u8 activity, bool32 startedActivity, s32 partnerInfo)
{
    s32 i;

    for (i = 0; i < (s32)ARRAY_COUNT(data->compatibility.playerTrainerId); i++)
        data->compatibility.playerTrainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        data->partnerInfo[i] = partnerInfo;
        partnerInfo >>= 8; // Each element is 1 byte
    }
    data->playerGender = gSaveBlock2Ptr->playerGender;
    data->activity = activity;
    data->startedActivity = startedActivity;
    data->compatibility.language = GAME_LANGUAGE;
    data->compatibility.version = GAME_VERSION;
    data->compatibility.hasNews = FALSE;
    data->compatibility.hasCard = FALSE;
    data->compatibility.unknown = FALSE;
    data->compatibility.canLinkNationally = FlagGet(FLAG_IS_CHAMPION);
    data->compatibility.hasNationalDex = IsNationalPokedexEnabled();
    data->compatibility.gameClear = FlagGet(FLAG_SYS_GAME_CLEAR);
}

bool8 Rfu_GetCompatiblePlayerData(struct RfuGameData *gameData, u8 *username, u8 idx)
{
    bool8 retVal;

    if (lman.parent_child == MODE_PARENT)
    {
        retVal = TRUE;
        if (IsRfuSerialNumberValid(gRfuLinkStatus->partner[idx].serialNo) && ((gRfuLinkStatus->getNameFlag >> idx) & 1))
        {
            memcpy(gameData, gRfuLinkStatus->partner[idx].gname, RFU_GAME_NAME_LENGTH);
            memcpy(username, gRfuLinkStatus->partner[idx].uname, RFU_USER_NAME_LENGTH);
        }
        else
        {
            memset(gameData, 0, RFU_GAME_NAME_LENGTH);
            memset(username, 0, RFU_USER_NAME_LENGTH);
        }
    }
    else
    {
        retVal = FALSE;
        if (IsRfuSerialNumberValid(gRfuLinkStatus->partner[idx].serialNo))
        {
            memcpy(gameData, gRfuLinkStatus->partner[idx].gname, RFU_GAME_NAME_LENGTH);
            memcpy(username, gRfuLinkStatus->partner[idx].uname, RFU_USER_NAME_LENGTH);
        }
        else
        {
            memset(gameData, 0, RFU_GAME_NAME_LENGTH);
            memset(username, 0, RFU_USER_NAME_LENGTH);
        }
    }
    return retVal;
}

bool8 Rfu_GetWonderDistributorPlayerData(struct RfuGameData *gameData, u8 *username, u8 idx)
{
    bool8 retVal = FALSE;
    if (gRfuLinkStatus->partner[idx].serialNo == RFU_SERIAL_WONDER_DISTRIBUTOR)
    {
        memcpy(gameData, gRfuLinkStatus->partner[idx].gname, RFU_GAME_NAME_LENGTH);
        memcpy(username, gRfuLinkStatus->partner[idx].uname, RFU_USER_NAME_LENGTH);
        retVal = TRUE;
    }
    else
    {
        memset(gameData, 0, RFU_GAME_NAME_LENGTH);
        memset(username, 0, RFU_USER_NAME_LENGTH);
    }
    return retVal;
}

void CopyHostRfuGameDataAndUsername(struct RfuGameData *gameData, u8 *username)
{
    memcpy(gameData, &gHostRfuGameData, RFU_GAME_NAME_LENGTH);
    memcpy(username, gHostRfuUsername, RFU_USER_NAME_LENGTH);
}

#define sNextAnimNum  data[0]
#define sSavedAnimNum data[1]
#define sCurrAnimNum  data[2]
#define sFrameDelay   data[3]
#define sFrameIdx     data[4]
#define sTileStart    data[6]
#define sValidator    data[7]
#define STATUS_INDICATOR_ACTIVE 0x1234 // Used to validate active indicator

void CreateWirelessStatusIndicatorSprite(u8 x, u8 y)
{
    u8 sprId;

    if (x == 0 && y == 0)
    {
        x = 231;
        y = 8;
    }
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        sprId = CreateSprite(&sWirelessStatusIndicatorSpriteTemplate, x, y, 0);
        gSprites[sprId].sValidator = STATUS_INDICATOR_ACTIVE;
        gSprites[sprId].sTileStart = GetSpriteTileStartByTag(sWirelessStatusIndicatorSpriteSheet.tag);
        gSprites[sprId].invisible = TRUE;
        gWirelessStatusIndicatorSpriteId = sprId;
    }
    else
    {
        gWirelessStatusIndicatorSpriteId = CreateSprite(&sWirelessStatusIndicatorSpriteTemplate, x, y, 0);
        gSprites[gWirelessStatusIndicatorSpriteId].sValidator = STATUS_INDICATOR_ACTIVE;
        gSprites[gWirelessStatusIndicatorSpriteId].sTileStart = GetSpriteTileStartByTag(sWirelessStatusIndicatorSpriteSheet.tag);
        gSprites[gWirelessStatusIndicatorSpriteId].invisible = TRUE;
    }
}

void DestroyWirelessStatusIndicatorSprite(void)
{
    if (gSprites[gWirelessStatusIndicatorSpriteId].sValidator == STATUS_INDICATOR_ACTIVE)
    {
        gSprites[gWirelessStatusIndicatorSpriteId].sValidator = 0;
        DestroySprite(&gSprites[gWirelessStatusIndicatorSpriteId]);
        gMain.oamBuffer[125] = gDummyOamData;
        CpuCopy16(&gDummyOamData, (struct OamData *)OAM + 125, sizeof(struct OamData));
    }
}

void LoadWirelessStatusIndicatorSpriteGfx(void)
{
    if (GetSpriteTileStartByTag(sWirelessStatusIndicatorSpriteSheet.tag) == 0xFFFF)
        LoadCompressedSpriteSheet(&sWirelessStatusIndicatorSpriteSheet);
    LoadSpritePalette(&sWirelessStatusIndicatorSpritePalette);
    gWirelessStatusIndicatorSpriteId = SPRITE_NONE;
}

static u8 GetParentSignalStrength(void)
{
    u8 i;
    u8 flags = gRfuLinkStatus->connSlotFlag;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (flags & 1)
            return gRfuLinkStatus->strength[i];
        flags >>= 1;
    }
    return 0;
}

static void SetWirelessStatusIndicatorAnim(struct Sprite *sprite, s32 animNum)
{
    if (sprite->sCurrAnimNum != animNum)
    {
        sprite->sCurrAnimNum = animNum;
        sprite->sFrameDelay = 0;
        sprite->sFrameIdx = 0;
    }
}

void UpdateWirelessStatusIndicatorSprite(void)
{
    if (gWirelessStatusIndicatorSpriteId != SPRITE_NONE && gSprites[gWirelessStatusIndicatorSpriteId].sValidator == STATUS_INDICATOR_ACTIVE)
    {
        struct Sprite *sprite = &gSprites[gWirelessStatusIndicatorSpriteId];
        u8 signalStrength = RFU_LINK_ICON_LEVEL4_MAX;
        u8 i = 0;

        // Get weakest signal strength
        if (gRfuLinkStatus->parentChild == MODE_PARENT)
        {
            for (i = 0; i < GetLinkPlayerCount() - 1; i++)
            {
                if (signalStrength >= GetConnectedChildStrength(i + 1))
                    signalStrength = GetConnectedChildStrength(i + 1);
            }
        }
        else
        {
            signalStrength = GetParentSignalStrength();
        }

        // Set signal strength sprite anim number
        if (IsRfuRecoveringFromLinkLoss() == TRUE)
            sprite->sNextAnimNum = WIRELESS_STATUS_ANIM_ERROR;
        else if (signalStrength <= RFU_LINK_ICON_LEVEL1_MAX)
            sprite->sNextAnimNum = WIRELESS_STATUS_ANIM_SEARCHING;
        else if (signalStrength >= RFU_LINK_ICON_LEVEL2_MIN && signalStrength <= RFU_LINK_ICON_LEVEL2_MAX)
            sprite->sNextAnimNum = WIRELESS_STATUS_ANIM_1_BAR;
        else if (signalStrength >= RFU_LINK_ICON_LEVEL3_MIN && signalStrength <= RFU_LINK_ICON_LEVEL3_MAX)
            sprite->sNextAnimNum = WIRELESS_STATUS_ANIM_2_BARS;
        else if (signalStrength >= RFU_LINK_ICON_LEVEL4_MIN)
            sprite->sNextAnimNum = WIRELESS_STATUS_ANIM_3_BARS;

        if (sprite->sNextAnimNum != sprite->sSavedAnimNum)
        {
            SetWirelessStatusIndicatorAnim(sprite, sprite->sNextAnimNum);
            sprite->sSavedAnimNum = sprite->sNextAnimNum;
        }
        if (sprite->anims[sprite->sCurrAnimNum][sprite->sFrameIdx].frame.duration < sprite->sFrameDelay)
        {
            sprite->sFrameIdx++;
            sprite->sFrameDelay = 0;
            if (sprite->anims[sprite->sCurrAnimNum][sprite->sFrameIdx].type == -2)
                sprite->sFrameIdx = 0;
        }
        else
        {
            sprite->sFrameDelay++;
        }
        gMain.oamBuffer[125] = sWirelessStatusIndicatorOamData;
        gMain.oamBuffer[125].x = sprite->x + sprite->centerToCornerVecX;
        gMain.oamBuffer[125].y = sprite->y + sprite->centerToCornerVecY;
        gMain.oamBuffer[125].paletteNum = sprite->oam.paletteNum;
        gMain.oamBuffer[125].tileNum = sprite->sTileStart + sprite->anims[sprite->sCurrAnimNum][sprite->sFrameIdx].frame.imageValue;
        CpuCopy16(&gMain.oamBuffer[125], (struct OamData *)OAM + 125, sizeof(struct OamData));
        if (RfuGetStatus() == RFU_STATUS_FATAL_ERROR)
            DestroyWirelessStatusIndicatorSprite();
    }
}

#undef sNextAnimNum
#undef sSavedAnimNum
#undef sCurrAnimNum
#undef sFrameDelay
#undef sFrameIdx
#undef sTileStart
#undef sValidator

static void CopyTrainerRecord(struct TrainerNameRecord *dest, u32 trainerId, const u8 *name)
{
    dest->trainerId = trainerId;
    StringCopy(dest->trainerName, name);
}

static bool32 NameIsNotEmpty(const u8 *name)
{
    s32 i;

    for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
    {
        if (name[i] != 0)
            return TRUE;
    }
    return FALSE;
}

// Save the currently connected players into the trainer records, shifting all previous records down.
void SaveLinkTrainerNames(void)
{
    if (gWirelessCommType != 0)
    {
        s32 i;
        s32 j;
        s32 nextSpace;
        s32 connectedTrainerRecordIndices[MAX_RFU_PLAYERS];
        struct TrainerNameRecord *newRecords = AllocZeroed(sizeof(gSaveBlock1Ptr->trainerNameRecords));

        // Check if we already have a record saved for connected trainers.
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            connectedTrainerRecordIndices[i] = -1;
            for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock1Ptr->trainerNameRecords); j++)
            {
                if ((u16)gLinkPlayers[i].trainerId ==  gSaveBlock1Ptr->trainerNameRecords[j].trainerId && StringCompare(gLinkPlayers[i].name, gSaveBlock1Ptr->trainerNameRecords[j].trainerName) == 0)
                    connectedTrainerRecordIndices[i] = j;
            }
        }

        // Save the connected trainers first, at the top of the list.
        nextSpace = 0;
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            if (i != GetMultiplayerId() && gLinkPlayers[i].language != LANGUAGE_JAPANESE)
            {
                CopyTrainerRecord(&newRecords[nextSpace], (u16)gLinkPlayers[i].trainerId, gLinkPlayers[i].name);

                // If we already had a record for this trainer, wipe it so that the next step doesn't duplicate it.
                if (connectedTrainerRecordIndices[i] >= 0)
                    memset(gSaveBlock1Ptr->trainerNameRecords[connectedTrainerRecordIndices[i]].trainerName, 0, PLAYER_NAME_LENGTH + 1);
                nextSpace++;
            }
        }

        // Copy all non-empty records to the new list, in the order they appear on the old list. If the list is full,
        // the last (oldest) records will be dropped.
        for (i = 0; i < (int)ARRAY_COUNT(gSaveBlock1Ptr->trainerNameRecords); i++)
        {
            if (NameIsNotEmpty(gSaveBlock1Ptr->trainerNameRecords[i].trainerName))
            {
                CopyTrainerRecord(&newRecords[nextSpace], gSaveBlock1Ptr->trainerNameRecords[i].trainerId, gSaveBlock1Ptr->trainerNameRecords[i].trainerName);
                if (++nextSpace >= (int)ARRAY_COUNT(gSaveBlock1Ptr->trainerNameRecords))
                    break;
            }
        }

        // Finalize the new list, and clean up.
        memcpy(gSaveBlock1Ptr->trainerNameRecords, newRecords, sizeof(gSaveBlock1Ptr->trainerNameRecords));
        Free(newRecords);
    }
}

bool32 PlayerHasMetTrainerBefore(u16 id, u8 *name)
{
    s32 i;

    for (i = 0; i < (int)ARRAY_COUNT(gSaveBlock1Ptr->trainerNameRecords); i++)
    {
        if (StringCompare(gSaveBlock1Ptr->trainerNameRecords[i].trainerName, name) == 0 && gSaveBlock1Ptr->trainerNameRecords[i].trainerId == id)
            return TRUE;

        if (!NameIsNotEmpty(gSaveBlock1Ptr->trainerNameRecords[i].trainerName))
            return FALSE;
    }
    return FALSE;
}

void WipeTrainerNameRecords(void)
{
    s32 i;

    for (i = 0; i < (int)ARRAY_COUNT(gSaveBlock1Ptr->trainerNameRecords); i++)
    {
        gSaveBlock1Ptr->trainerNameRecords[i].trainerId = 0;
        CpuFill16(0, gSaveBlock1Ptr->trainerNameRecords[i].trainerName, PLAYER_NAME_LENGTH + 1);
    }
}
