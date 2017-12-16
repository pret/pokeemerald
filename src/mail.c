#include "global.h"
#include "constants/items.h"
#include "main.h"
#include "overworld.h"
#include "task.h"
#include "unknown_task.h"
#include "palette.h"
#include "text.h"
#include "menu.h"
#include "menu_helpers.h"
#include "text_window.h"
#include "string_util.h"
#include "international_string_util.h"
#include "strings.h"
#include "gpu_regs.h"
#include "bg.h"
#include "pokemon_icon.h"
#include "constants/species.h"
#include "malloc.h"
#include "easy_chat.h"
#include "mail_data.h"
#include "mail.h"

// Static type declarations

struct UnkMailStruct
{
    u32 numEasyChatWords:2;
    u32 xOffset:6;
    u32 lineHeight:8;
};

struct MailLayout
{
    u8 numSubStructs;
    u8 signatureYPos;
    u8 signatureWidth;
    u8 wordsXPos;
    u8 wordsYPos;
    const struct UnkMailStruct *var8;
};

struct MailGraphics
{
    const u16 *palette;
    const u8 *tiles;
    const u8 *tileMap;
    u16 var0C;
    u16 var0E;
    u16 color10;
    u16 color12;
};

// Static RAM declarations

static EWRAM_DATA struct
{
    /*0x0000*/ u8 strbuf[8][64];
    /*0x0200*/ u8 playerName[12];
    /*0x020C*/ MainCallback callback;
    /*0x0210*/ MainCallback callback2;
    /*0x0214*/ struct MailStruct *mail;
    /*0x0218*/ bool8 flag;
    /*0x0219*/ u8 signatureWidth;
    /*0x021a*/ u8 mailType;
    /*0x021b*/ u8 animsActive;
    /*0x021c*/ u8 monIconSprite;
    /*0x021d*/ u8 language;
    /*0x021e*/ bool8 playerIsSender;
    /*0x0220*/ void (*parserSingle)(u8 *dest, u16 word);
    /*0x0224*/ void (*parserMultiple)(u8 *dest, const u16 *src, u16 length1, u16 length2);
    /*0x0228*/ const struct MailLayout *layout;
    /*0x022c*/ u8 bg1TilemapBuffer[0x1000];
    /*0x122c*/ u8 bg2TilemapBuffer[0x1000];
} *gUnknown_0203A134 = NULL;

// Static ROM declarations

void sub_81219F0(void);
void sub_8121A1C(void);
void sub_8121B1C(void);
void sub_8121C50(void);
void sub_8121C64(void);
void sub_8121C98(void);
void sub_8121CC0(void);
void sub_8121D00(void);

// .rodata

const struct BgTemplate gUnknown_0859F290[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .priority = 0
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .priority = 1
    }, {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .priority = 2
    }
};

const struct WindowTemplate gUnknown_0859F29C[] = {
    {
        .priority = 0,
        .tilemapLeft = 2,
        .tilemapTop = 3,
        .width = 26,
        .height = 15,
        .paletteNum = 15,
        .baseBlock = 1
    },
    DUMMY_WIN_TEMPLATE
};

const u8 gUnknown_0859F2AC[] = {
     0,
    10,
    11
};

const u16 gUnknown_0859F2B0[][2] = {
    { 0x6ACD, 0x51A5 },
    { 0x45FC, 0x38D4 }
};

extern const u16 gUnknown_08DBE818[];
extern const u16 gUnknown_08DBE838[];
extern const u16 gUnknown_08DBE858[];
extern const u16 gUnknown_08DBE878[];
extern const u16 gUnknown_08DBE898[];
extern const u16 gUnknown_08DBE8B8[];
extern const u16 gUnknown_08DBE8D8[];
extern const u16 gUnknown_08DBE8F8[];
extern const u16 gUnknown_08DBE918[];
extern const u16 gUnknown_08DBE938[];
extern const u16 gUnknown_08DBE958[];
extern const u16 gUnknown_08DBE978[];
extern const u8 gUnknown_08DBE998[];
extern const u8 gUnknown_08DBFBA4[];
extern const u8 gUnknown_08DBEB38[];
extern const u8 gUnknown_08DBFC7C[];
extern const u8 gUnknown_08DBEC74[];
extern const u8 gUnknown_08DBFD5C[];
extern const u8 gUnknown_08DBEE84[];
extern const u8 gUnknown_08DBFE68[];
extern const u8 gUnknown_08DBEF5C[];
extern const u8 gUnknown_08DBFF44[];
extern const u8 gUnknown_08DBF154[];
extern const u8 gUnknown_08DC0034[];
extern const u8 gUnknown_08DBF2D4[];
extern const u8 gUnknown_08DC0114[];
extern const u8 gUnknown_08DBF37C[];
extern const u8 gUnknown_08DC01F4[];
extern const u8 gUnknown_08DBF50C[];
extern const u8 gUnknown_08DC0300[];
extern const u8 gUnknown_08DBF64C[];
extern const u8 gUnknown_08DC03F0[];
extern const u8 gUnknown_08DBF7B4[];
extern const u8 gUnknown_08DC04E8[];
extern const u8 gUnknown_08DBF904[];
extern const u8 gUnknown_08DC0600[];

const struct MailGraphics gUnknown_0859F2B8[] = {
    {
        gUnknown_08DBE818, gUnknown_08DBE998, gUnknown_08DBFBA4, 0x02c0, 0x0000, 0x294a, 0x6739
    }, {
        gUnknown_08DBE838, gUnknown_08DBEB38, gUnknown_08DBFC7C, 0x02e0, 0x0000, 0x7fff, 0x4631
    }, {
        gUnknown_08DBE858, gUnknown_08DBEC74, gUnknown_08DBFD5C, 0x0400, 0x0000, 0x294a, 0x6739
    }, {
        gUnknown_08DBE878, gUnknown_08DBEE84, gUnknown_08DBFE68, 0x01e0, 0x0000, 0x7fff, 0x4631
    }, {
        gUnknown_08DBE898, gUnknown_08DBEF5C, gUnknown_08DBFF44, 0x02e0, 0x0000, 0x7fff, 0x4631
    }, {
        gUnknown_08DBE8B8, gUnknown_08DBF154, gUnknown_08DC0034, 0x0300, 0x0000, 0x294a, 0x6739
    }, {
        gUnknown_08DBE8D8, gUnknown_08DBF2D4, gUnknown_08DC0114, 0x0140, 0x0000, 0x7fff, 0x4631
    }, {
        gUnknown_08DBE8F8, gUnknown_08DBF37C, gUnknown_08DC01F4, 0x0300, 0x0000, 0x7fff, 0x4631
    }, {
        gUnknown_08DBE918, gUnknown_08DBF50C, gUnknown_08DC0300, 0x0220, 0x0000, 0x294a, 0x6739
    }, {
        gUnknown_08DBE938, gUnknown_08DBF64C, gUnknown_08DC03F0, 0x0340, 0x0000, 0x294a, 0x6739
    }, {
        gUnknown_08DBE958, gUnknown_08DBF7B4, gUnknown_08DC04E8, 0x02a0, 0x0000, 0x294a, 0x6739
    }, {
        gUnknown_08DBE978, gUnknown_08DBF904, gUnknown_08DC0600, 0x0520, 0x0000, 0x294a, 0x6739
    }
};

const struct UnkMailStruct Unknown_0859F3A8[] = {
    { .numEasyChatWords = 3, .lineHeight = 16 },
    { .numEasyChatWords = 3, .lineHeight = 16 },
    { .numEasyChatWords = 3, .lineHeight = 16 }
};

const struct MailLayout gUnknown_0859F3B4[] = {
    { 0x03, 0x00, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x00, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x00, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x00, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x00, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x00, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x00, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x00, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x00, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x00, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x08, 0x00, 0x02, 0x04, Unknown_0859F3A8 },
    { 0x03, 0x00, 0x00, 0x02, 0x00, Unknown_0859F3A8 }
};

const struct UnkMailStruct Unknown_0859F444[] = {
    { .numEasyChatWords = 2, .lineHeight = 16 },
    { .numEasyChatWords = 2, .lineHeight = 16 },
    { .numEasyChatWords = 2, .lineHeight = 16 },
    { .numEasyChatWords = 2, .lineHeight = 16 },
    { .numEasyChatWords = 1, .lineHeight = 16 }
};

const struct MailLayout gUnknown_0859F458[] = {
    { 0x05, 0x07, 0x58, 0x0b, 0x1e, Unknown_0859F444 },
    { 0x05, 0x0a, 0x60, 0x09, 0x1e, Unknown_0859F444 },
    { 0x05, 0x0c, 0x68, 0x05, 0x1e, Unknown_0859F444 },
    { 0x05, 0x05, 0x60, 0x08, 0x1e, Unknown_0859F444 },
    { 0x05, 0x0a, 0x60, 0x09, 0x1e, Unknown_0859F444 },
    { 0x05, 0x09, 0x70, 0x05, 0x1e, Unknown_0859F444 },
    { 0x05, 0x0c, 0x68, 0x09, 0x1e, Unknown_0859F444 },
    { 0x05, 0x0d, 0x68, 0x0d, 0x1e, Unknown_0859F444 },
    { 0x05, 0x09, 0x60, 0x09, 0x1e, Unknown_0859F444 },
    { 0x05, 0x09, 0x60, 0x09, 0x1e, Unknown_0859F444 },
    { 0x05, 0x11, 0x68, 0x0f, 0x1e, Unknown_0859F444 },
    { 0x05, 0x09, 0x60, 0x05, 0x1e, Unknown_0859F444 }
};

// What the heck are these meant to be? Call them u16 for now.

const u16 Unknown_0859F4E8[] = {
    0x00, 0x4000, 0x00, 0x00
};

const u16 Unknown_0859F4F0[] = {
    0x00, 0x00, -1, 0x00
};

const u16 Unknown_0859F4F8[] = {
    0x04, 0x00, -1, 0x00
};

const u16 Unknown_0859F500[] = {
    0x00, 0x40, -1, 0x00
};

const u16 *const gUnknown_0859F508[] = {
    Unknown_0859F4F0,
    Unknown_0859F4F8,
    Unknown_0859F500
};

// .text

void sub_8121478(struct MailStruct *mail, MainCallback callback, bool8 flag) {
    u16 buffer[2];
    u16 species;

    gUnknown_0203A134 = calloc(1, sizeof(*gUnknown_0203A134));
    gUnknown_0203A134->language = LANGUAGE_ENGLISH;
    gUnknown_0203A134->playerIsSender = TRUE;
    gUnknown_0203A134->parserSingle = CopyEasyChatWord;
    gUnknown_0203A134->parserMultiple = ConvertEasyChatWordsToString;
    if (mail->itemId >= ITEM_ORANGE_MAIL && mail->itemId <= ITEM_RETRO_MAIL) {
        gUnknown_0203A134->mailType = mail->itemId - ITEM_ORANGE_MAIL;
    }
    else
    {
        gUnknown_0203A134->mailType = 0;
        flag = FALSE;
    }
    switch (gUnknown_0203A134->playerIsSender)
    {
        case FALSE:
        default:
            gUnknown_0203A134->layout = &gUnknown_0859F3B4[gUnknown_0203A134->mailType];
            break;
        case TRUE:
            gUnknown_0203A134->layout = &gUnknown_0859F458[gUnknown_0203A134->mailType];
            break;
    }
    species = sub_80D45E8(mail->species, buffer);
    if (species >= SPECIES_BULBASAUR && species < NUM_SPECIES)
    {
        switch (gUnknown_0203A134->mailType)
        {
            default:
                gUnknown_0203A134->animsActive = 0;
                break;
            case ITEM_BEAD_MAIL - ITEM_ORANGE_MAIL:
                gUnknown_0203A134->animsActive = 1;
                break;
            case ITEM_DREAM_MAIL - ITEM_ORANGE_MAIL:
                gUnknown_0203A134->animsActive = 2;
                break;
        }
    }
    else
    {
        gUnknown_0203A134->animsActive = 0;
    }
    gUnknown_0203A134->mail = mail;
    gUnknown_0203A134->callback = callback;
    gUnknown_0203A134->flag = flag;
    SetMainCallback2(sub_81219F0);
}

bool8 sub_81215EC(void)
{
    u16 icon;

    switch (gMain.state)
    {
        case 0:
            SetVBlankCallback(NULL);
            remove_some_task();
            SetGpuReg(REG_OFFSET_DISPCNT, 0x0000);
            break;
        case 1:
            CpuFill16(0, (void *)OAM, OAM_SIZE);
            break;
        case 2:
            ResetPaletteFade();
            break;
        case 3:
            ResetTasks();
            break;
        case 4:
            ResetSpriteData();
            break;
        case 5:
            FreeAllSpritePalettes();
            reset_temp_tile_data_buffers();
            SetGpuReg(REG_OFFSET_BG0HOFS, 0x0000);
            SetGpuReg(REG_OFFSET_BG0VOFS, 0x0000);
            SetGpuReg(REG_OFFSET_BG1HOFS, 0x0000);
            SetGpuReg(REG_OFFSET_BG1VOFS, 0x0000);
            SetGpuReg(REG_OFFSET_BG2VOFS, 0x0000);
            SetGpuReg(REG_OFFSET_BG2HOFS, 0x0000);
            SetGpuReg(REG_OFFSET_BG3HOFS, 0x0000);
            SetGpuReg(REG_OFFSET_BG3VOFS, 0x0000);
            SetGpuReg(REG_OFFSET_BLDCNT, 0x0000);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0x0000);
            break;
        case 6:
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, gUnknown_0859F290, 3);
            SetBgTilemapBuffer(1, gUnknown_0203A134->bg1TilemapBuffer);
            SetBgTilemapBuffer(2, gUnknown_0203A134->bg2TilemapBuffer);
            break;
        case 7:
            InitWindows(gUnknown_0859F29C);
            DeactivateAllTextPrinters();
            break;
        case 8:
            decompress_and_copy_tile_data_to_vram(1, gUnknown_0859F2B8[gUnknown_0203A134->mailType].tiles, 0, 0, 0);
            break;
        case 9:
            if (free_temp_tile_data_buffers_if_possible())
            {
                return FALSE;
            }
            break;
        case 10:
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
            FillBgTilemapBufferRect_Palette0(2, 1, 0, 0, 30, 20);
            CopyToBgTilemapBuffer(1, gUnknown_0859F2B8[gUnknown_0203A134->mailType].tileMap, 0, 0);
            break;
        case 11:
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            break;
        case 12:
            LoadPalette(GetOverworldTextboxPalettePtr(), 240, 32);
            gPlttBufferUnfaded[250] = gUnknown_0859F2B8[gUnknown_0203A134->mailType].color10;
            gPlttBufferFaded[250] = gUnknown_0859F2B8[gUnknown_0203A134->mailType].color10;
            gPlttBufferUnfaded[251] = gUnknown_0859F2B8[gUnknown_0203A134->mailType].color12;
            gPlttBufferFaded[251] = gUnknown_0859F2B8[gUnknown_0203A134->mailType].color12;
            LoadPalette(gUnknown_0859F2B8[gUnknown_0203A134->mailType].palette, 0, 32);
            gPlttBufferUnfaded[10] = gUnknown_0859F2B0[gSaveBlock2Ptr->playerGender][0];
            gPlttBufferFaded[10] = gUnknown_0859F2B0[gSaveBlock2Ptr->playerGender][0];
            gPlttBufferUnfaded[11] = gUnknown_0859F2B0[gSaveBlock2Ptr->playerGender][1];
            gPlttBufferFaded[11] = gUnknown_0859F2B0[gSaveBlock2Ptr->playerGender][1];
            break;
        case 13:
            if (gUnknown_0203A134->flag)
            {
                sub_8121A1C();
            }
            break;
        case 14:
            if (gUnknown_0203A134->flag)
            {
                sub_8121B1C();
                RunTextPrinters();
            }
            break;
        case 15:
            if (sub_8087598() == TRUE)
            {
                return FALSE;
            }
            break;
        case 16:
            SetVBlankCallback(sub_8121C50);
            gPaletteFade.bufferTransferDisabled = TRUE;
            break;
        case 17:
            icon = sub_80D2E84(gUnknown_0203A134->mail->species);
            switch (gUnknown_0203A134->animsActive)
            {
                case 1:
                    sub_80D2F68(icon);
                    gUnknown_0203A134->monIconSprite = sub_80D2D78(icon, SpriteCallbackDummy, 0x60, 0x80, 0, 0);
                    break;
                case 2:
                    sub_80D2F68(icon);
                    gUnknown_0203A134->monIconSprite = sub_80D2D78(icon, SpriteCallbackDummy, 0x28, 0x80, 0, 0);
                    break;
            }
            break;
        case 18:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            BeginNormalPaletteFade(-1, 0, 16, 0, 0);
            gPaletteFade.bufferTransferDisabled = FALSE;
            gUnknown_0203A134->callback2 = sub_8121C98;
            return TRUE;
        default:
            return FALSE;
    }
    gMain.state ++;
    return FALSE;
}

void sub_81219F0(void)
{
    do
    {
        if (sub_81215EC() == TRUE)
        {
            SetMainCallback2(sub_8121C64);
            break;
        }
    } while (sub_81221AC() != TRUE);
}

void sub_8121A1C(void)
{
    u16 i;
    u8 total;
    u8 *ptr;

    total = 0;
    for (i = 0; i < gUnknown_0203A134->layout->numSubStructs; i ++)
    {
        ConvertEasyChatWordsToString(gUnknown_0203A134->strbuf[i], &gUnknown_0203A134->mail->words[total], gUnknown_0203A134->layout->var8[i].numEasyChatWords, 1);
        total += gUnknown_0203A134->layout->var8[i].numEasyChatWords;
    }
    ptr = StringCopy(gUnknown_0203A134->playerName, gUnknown_0203A134->mail->playerName);
    if (!gUnknown_0203A134->playerIsSender)
    {
        StringCopy(ptr, gText_FromSpace);
        gUnknown_0203A134->signatureWidth = gUnknown_0203A134->layout->signatureWidth - (StringLength(gUnknown_0203A134->playerName) * 8 - 0x60);
    }
    else
    {
        sub_81DB52C(gUnknown_0203A134->playerName);
        gUnknown_0203A134->signatureWidth = gUnknown_0203A134->layout->signatureWidth;
    }
}

void sub_8121B1C(void)
{
    u16 i;
    u8 strbuf[0x20];
    u8 y;
    u8 *bufptr;
    s32 box_x;
    s32 box_y;

    y = 0;
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    FillWindowPixelBuffer(0, 0);
    FillWindowPixelBuffer(1, 0);
    for (i = 0; i < gUnknown_0203A134->layout->numSubStructs; i ++)
    {
        if (gUnknown_0203A134->strbuf[i][0] == EOS || gUnknown_0203A134->strbuf[i][0] == CHAR_SPACE)
        {
            continue;
        }
        box_print(0, 1, gUnknown_0203A134->layout->var8[i].xOffset + gUnknown_0203A134->layout->wordsYPos, y + gUnknown_0203A134->layout->wordsXPos, gUnknown_0859F2AC, 0, gUnknown_0203A134->strbuf[i]);
        y += gUnknown_0203A134->layout->var8[i].lineHeight;
    }
    bufptr = StringCopy(strbuf, gText_FromSpace);
    StringCopy(bufptr, gUnknown_0203A134->playerName);
    box_x = GetStringCenterAlignXOffset(1, strbuf, gUnknown_0203A134->signatureWidth) + 0x68;
    box_y = gUnknown_0203A134->layout->signatureYPos + 0x58;
    box_print(0, 1, box_x, box_y, gUnknown_0859F2AC, 0, strbuf);
    CopyWindowToVram(0, 3);
    CopyWindowToVram(1, 3);
}

void sub_8121C50(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void sub_8121C64(void)
{
    if (gUnknown_0203A134->animsActive != 0)
    {
        AnimateSprites();
        BuildOamBuffer();
    }
    gUnknown_0203A134->callback2();
}

void sub_8121C98(void)
{
    if (!UpdatePaletteFade())
    {
        gUnknown_0203A134->callback2 = sub_8121CC0;
    }
}

void sub_8121CC0(void)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(-1, 0, 0, 16, 0);
        gUnknown_0203A134->callback2 = sub_8121D00;
    }
}

void sub_8121D00(void)
{
    if (!UpdatePaletteFade())
    {
        SetMainCallback2(gUnknown_0203A134->callback);
        switch (gUnknown_0203A134->animsActive)
        {
            case 1:
            case 2:
                sub_80D2FF0(sub_80D2E84(gUnknown_0203A134->mail->species));
                sub_80D2EF8(&gSprites[gUnknown_0203A134->monIconSprite]);
        }
        memset(gUnknown_0203A134, 0, sizeof(*gUnknown_0203A134));
        ResetPaletteFade();
        UnsetBgTilemapBuffer(0);
        UnsetBgTilemapBuffer(1);
        ResetBgsAndClearDma3BusyFlags(0);
        FreeAllWindowBuffers();
        free(gUnknown_0203A134);
        gUnknown_0203A134 = NULL;
    }
}
