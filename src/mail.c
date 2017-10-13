
// Includes
#include "global.h"
#include "main.h"
#include "rom4.h"
#include "task.h"
#include "unknown_task.h"
#include "palette.h"
#include "menu.h"
#include "menu_helpers.h"
#include "text.h"
#include "text_window.h"
#include "gpu_regs.h"
#include "bg.h"
#include "pokemon_icon.h"
#include "species.h"
#include "malloc.h"
#include "easy_chat.h"
#include "mail_data.h"
#include "mail.h"

// Static type declarations

struct UnkMailStruct
{
    u8 unk_0_0:2;
    u8 unk_0_2:2;
    u8 unk_0_4:4;
};

struct MailLayout
{
    u8 var0;
    u8 var1;
    u8 var2;
    u8 var3_0:4;
    u8 var3_4:4;
    struct UnkMailStruct *var4;
    u32 var8;
};

struct Unk203A134
{
    /*0x0000*/ u8 filler_0000[0x20c];
    /*0x020C*/ MainCallback callback;
    /*0x0210*/ MainCallback callback2;
    /*0x0214*/ struct MailStruct *mail;
    /*0x0218*/ bool8 flag;
    /*0x0219*/ u8 filler_0219[1];
    /*0x021a*/ u8 mailType;
    /*0x021b*/ u8 unk_021b;
    /*0x021c*/ u8 unk_021c;
    /*0x021d*/ u8 language;
    /*0x021e*/ bool8 playerIsSender;
    /*0x0220*/ void (*parserSingle)(u8 *dest, u16 word);
    /*0x0224*/ void (*parserMultiple)(u8 *dest, const u16 *src, u16 length1, u16 length2);
    /*0x0228*/ const struct MailLayout *layout;
    /*0x022c*/ u8 bg1TilemapBuffer[0x1000];
    /*0x122c*/ u8 bg2TilemapBuffer[0x1000];
};

struct MailGraphics
{
    u16 (*palette)[];
    u8 (*tiles)[];
    u8 (*tileMap)[];
    u16 var0C;
    u16 var0E;
    u16 color10;
    u16 color12;
};

// Static RAM declarations

EWRAM_DATA struct Unk203A134 *gUnknown_0203A134;

// Static ROM declarations

void sub_81219F0(void);
void sub_8121A1C(void);
void sub_8121B1C(void);
void sub_8121C50(void);
void sub_8121C64(void);
void sub_8121C98(void);

// .rodata

extern const struct BgTemplate gUnknown_0859F290[];
extern const struct WindowTemplate gUnknown_0859F29C;
extern const u16 gUnknown_0859F2B0[][2];
extern const struct MailGraphics gUnknown_0859F2B8[];
extern const struct MailLayout gUnknown_0859F3B4[];
extern const struct MailLayout gUnknown_0859F458[];

// .text

void sub_8121478(struct MailStruct *mail, MainCallback callback, bool8 flag) {
    u16 buffer[2];
    u16 species;

    gUnknown_0203A134 = calloc(1, sizeof(struct Unk203A134));
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
                gUnknown_0203A134->unk_021b = 0;
                break;
            case ITEM_BEAD_MAIL - ITEM_ORANGE_MAIL:
                gUnknown_0203A134->unk_021b = 1;
                break;
            case ITEM_DREAM_MAIL - ITEM_ORANGE_MAIL:
                gUnknown_0203A134->unk_021b = 2;
                break;
        }
    }
    else
    {
        gUnknown_0203A134->unk_021b = 0;
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
            InitWindows(&gUnknown_0859F29C);
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
            LoadPalette(sub_8098C64(), 240, 32);
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
            switch (gUnknown_0203A134->unk_021b)
            {
                case 1:
                    sub_80D2F68(icon);
                    gUnknown_0203A134->unk_021c = sub_80D2D78(icon, SpriteCallbackDummy, 0x60, 0x80, 0, 0);
                    break;
                case 2:
                    sub_80D2F68(icon);
                    gUnknown_0203A134->unk_021c = sub_80D2D78(icon, SpriteCallbackDummy, 0x28, 0x80, 0, 0);
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
