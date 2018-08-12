#include "global.h"
#include "main.h"
#include "bg.h"
#include "data2.h"
#include "event_data.h"
#include "field_screen.h"
#include "gpu_regs.h"
#include "learn_move.h"
#include "list_menu.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon_summary_screen.h"
#include "pokenav.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "constants/rgb.h"
#include "constants/songs.h"

struct LearnMoveStruct
{
    u8 state;
    u8 spriteIds[16];           /*0x001*/
    u8 filler11;                /*0x011*/
    u16 movesToLearn[4];        /*0x012*/
    u8 filler1A[0x44 - 0x1A];   /*0x01A*/
    u8 partyMon;                /*0x044*/
    u8 unk045;                  /*0x045*/
    u8 filler46[2];             /*0x046*/
    struct ListMenuItem menuItems[4];            /*0x048*/
    u8 filler68[0x110 - 0x68];  /*0x068*/
    u8 numMenuChoices;          /*0x110*/
    u8 unk111;                  /*0x111*/
    u8 listMenuTask;            /*0x112*/
    u8 unk113;                  /*0x113*/
    u8 unk114;                  /*0x114*/
    u16 unk116;                 /*0x116*/
};

EWRAM_DATA struct LearnMoveStruct *sLearnMoveStruct = {0};
EWRAM_DATA struct {
    u16 listOffset;
    u16 listRow;
    u8 showContestInfo;
} gUnknown_0203BC38 = {0};

extern void (*gFieldCallback)(void);

const u16 gUnknown_085CE9F8[] = INCBIN_U16("graphics/interface/ui_learn_move.gbapal");
const u8 gUnknown_085CEA18[] = INCBIN_U8("graphics/interface/ui_learn_move.4bpp");

const struct OamData gUnknown_085CEB98 = 
{
    .y = 0,
    .affineMode = 0,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

const struct OamData gUnknown_085CEBA0 = 
{
    .y = 0,
    .affineMode = 0,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_V_RECTANGLE,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

const struct OamData gUnknown_085CEBA8 = 
{
    .y = 0,
    .affineMode = 0,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_H_RECTANGLE,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

const struct SpriteSheet gUnknown_085CEBB0 = 
{
    .data = gUnknown_085CEA18,
    .size = 0x180,
    .tag = 5525
};

const struct SpritePalette gUnknown_085CEBB8 = 
{
    .data = gUnknown_085CE9F8,
    .tag = 5526
};

const struct ScrollArrowsTemplate gUnknown_085CEBC0 = 
{
    .firstArrowType = 0,
    .firstX = 27,
    .firstY = 16,
    .secondArrowType = 1,
    .secondX = 117,
    .secondY = 16,
    .fullyUpThreshold = -1,
    .fullyDownThreshold = -1,
    .tileTag = 5325,
    .palTag = 5325,
    .palNum = 0,
};

const struct ScrollArrowsTemplate gUnknown_085CEBD0 = 
{
    .firstArrowType = 2,
    .firstX = 192,
    .firstY = 8,
    .secondArrowType = 3,
    .secondX = 192,
    .secondY = 104,
    .fullyUpThreshold = 0,
    .fullyDownThreshold = 0,
    .tileTag = 5425,
    .palTag = 5425,
    .palNum = 0,
};

const union AnimCmd gUnknown_085CEBE0[] = 
{
    ANIMCMD_FRAME(8, 5, FALSE, FALSE),
    ANIMCMD_END
};

const union AnimCmd gUnknown_085CEBE8[] = 
{
    ANIMCMD_FRAME(9, 5, FALSE, FALSE),
    ANIMCMD_END
};

const union AnimCmd gUnknown_085CEBF0[] = 
{
    ANIMCMD_FRAME(10, 5, FALSE, FALSE),
    ANIMCMD_END
};

const union AnimCmd gUnknown_085CEBF8[] = 
{
    ANIMCMD_FRAME(11, 5, FALSE, FALSE),
    ANIMCMD_END
};

const union AnimCmd *const gUnknown_085CEC00[] = 
{
    gUnknown_085CEBE0,
    gUnknown_085CEBE8,
    gUnknown_085CEBF0,
    gUnknown_085CEBF8,
};

const struct SpriteTemplate gUnknown_085CEC10 = 
{
    .tileTag = 5525,
    .paletteTag = 5526,
    .oam = &gUnknown_085CEB98,
    .anims = gUnknown_085CEC00,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

const struct BgTemplate gUnknown_085CEC28[] =
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
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

extern void sub_81D2824(u16);

void sub_8160868(void);
void sub_8161280(void);
void sub_81610B8(void);
void sub_816082C(void);

static void sub_8160664(u8 taskId);
void CB2_InitLearnMove(void);
void sub_8160740(void);
void sub_81607EC(void);
void sub_816082C(void);

void VBlankCB_LearnMove(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void TeachMoveTutorMove(void)
{
    ScriptContext2_Enable();
    CreateTask(sub_8160664, 0xA);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, 0);
}

void sub_8160664(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_InitLearnMove);
        gFieldCallback = sub_80AF168;
        DestroyTask(taskId);
    }
}

void CB2_InitLearnMove(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    clear_scheduled_bg_copies_to_vram();
    sLearnMoveStruct = AllocZeroed(sizeof(struct LearnMoveStruct));
    sLearnMoveStruct->partyMon = gSpecialVar_0x8004;
    SetVBlankCallback(VBlankCB_LearnMove);

    sub_81607EC();
    sub_81D2824(0);

    gUnknown_0203BC38.listOffset = 0;
    gUnknown_0203BC38.listRow = 0;
    gUnknown_0203BC38.showContestInfo = 0;

    sub_8161280();

    LoadSpriteSheet(&gUnknown_085CEBB0);
    LoadSpritePalette(&gUnknown_085CEBB8);
    sub_81610B8();

    sLearnMoveStruct->listMenuTask = ListMenuInit(&gMultiuseListMenuTemplate, gUnknown_0203BC38.listOffset, gUnknown_0203BC38.listRow);
    FillPalette(RGB_BLACK, 0, 2);
    SetMainCallback2(sub_816082C);
}

void sub_8160740(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    clear_scheduled_bg_copies_to_vram();
    sLearnMoveStruct = AllocZeroed(sizeof(struct LearnMoveStruct));
    sLearnMoveStruct->state = 28;
    sLearnMoveStruct->partyMon = gSpecialVar_0x8004;
    sLearnMoveStruct->unk045 = gSpecialVar_0x8005;
    SetVBlankCallback(VBlankCB_LearnMove);

    sub_81607EC();
    sub_81D2824(gUnknown_0203BC38.showContestInfo);
    sub_8161280();

    LoadSpriteSheet(&gUnknown_085CEBB0);
    LoadSpritePalette(&gUnknown_085CEBB8);
    sub_81610B8();

    sLearnMoveStruct->listMenuTask = ListMenuInit(&gMultiuseListMenuTemplate, gUnknown_0203BC38.listOffset, gUnknown_0203BC38.listRow);
    FillPalette(RGB_BLACK, 0, 2);
    SetMainCallback2(sub_816082C);
}

void sub_81607EC(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085CEC28, 2);
    ResetAllBgsCoordinates();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                  DISPCNT_OBJ_1D_MAP |
                                  DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(1);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

void sub_816082C(void)
{
    sub_8160868();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

void sub_816084C(const u8 *src)
{
    StringExpandPlaceholders(gStringVar4, src);
    sub_81D2BF4(gStringVar4);
}

void sub_81611AC(void);
void sub_8160F50(u8);
void sub_8161074(u8);
s32 sub_8161054(void);
void sub_8160EA0(void);
void sub_8161234(void);
void render_previous_quest_text(bool8);

void sub_8160868(void)
{
    switch (sLearnMoveStruct->state)
    {
    case 0:
        sLearnMoveStruct->state++;
        render_previous_quest_text(FALSE);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            sLearnMoveStruct->state = 4;
        }
        break;
    case 2:
        sLearnMoveStruct->state++;
        break;
    case 3:
        render_previous_quest_text(FALSE);
        sLearnMoveStruct->state++;
        sub_81611AC();
        break;
    case 4:
        sub_8160F50(0);
        return;
    case 5:
        sub_8161074(0);
        sLearnMoveStruct->state++;
        sub_81611AC();
        break;
    case 6:
        sub_8160F50(1);
        break;
    case 8:
        if (!sub_81D2C3C())
        {
            sub_81D2C50();
            sLearnMoveStruct->state++;
        }
        break;
    case 9:
        {
            s8 selection = Menu_ProcessInputNoWrap_();

            if (selection == 0)
            {
                if (GiveMoveToMon(&gPlayerParty[sLearnMoveStruct->partyMon], sub_8161054()) != 0xFFFF)
                {
                    sub_816084C(gText_PkmnLearnedMove4);
                    gSpecialVar_0x8004 = 1;
                    sLearnMoveStruct->state = 31;
                }
                else
                {
                    sLearnMoveStruct->state = 16;
                }
            }
            else if (selection == -1 || selection == 1)
            {
                if (gUnknown_0203BC38.showContestInfo == FALSE)
                {
                    sLearnMoveStruct->state = 3;
                }
                else if (gUnknown_0203BC38.showContestInfo == TRUE)
                {
                    sLearnMoveStruct->state = 5;
                }
            }
        }
        break;
    case 12:
        if (!sub_81D2C3C())
        {
            sub_81D2C50();
            sLearnMoveStruct->state++;
        }
        break;
    case 13:
        {
            s8 selection = Menu_ProcessInputNoWrap_();

            if (selection == 0)
            {
                gSpecialVar_0x8004 = selection;
                sLearnMoveStruct->state = 14;
            }
            else if (selection == -1 || selection == 1)
            {
                if (gUnknown_0203BC38.showContestInfo == FALSE)
                {
                    sLearnMoveStruct->state = 3;
                }
                else if (gUnknown_0203BC38.showContestInfo == TRUE)
                {
                    sLearnMoveStruct->state = 5;
                }
            }
        }
        break;
    case 16:
        sub_816084C(gText_PkmnTryingToLearnMove);
        sLearnMoveStruct->state++;
        break;
    case 17:
        if (!sub_81D2C3C())
        {
            sub_81D2C50();
            sLearnMoveStruct->state = 18;
        }
        break;
    case 18:
        {
            s8 var = Menu_ProcessInputNoWrap_();

            if (var == 0)
            {
                sub_816084C(gText_WhichMoveToForget2);
                sLearnMoveStruct->state = 19;
            }
            else if (var == -1 || var == 1)
            {
                sLearnMoveStruct->state = 24;
            }
        }
        break;
    case 24:
        StringCopy(gStringVar2, gMoveNames[sub_8161054()]);
        sub_816084C(gText_StopTryingToTeachMove);
        sLearnMoveStruct->state++;
        break;
    case 25:
        if (!sub_81D2C3C())
        {
            sub_81D2C50();
            sLearnMoveStruct->state++;
        }
        break;
    case 26:
        {
            s8 var = Menu_ProcessInputNoWrap_();

            if (var == 0)
            {
                sLearnMoveStruct->state = 27;
            }
            else if (var == -1 || var == 1)
            {
                // What's the point? It gets set to 16, anyway.
                if (gUnknown_0203BC38.showContestInfo == FALSE)
                {
                    sLearnMoveStruct->state = 3;
                }
                else if (gUnknown_0203BC38.showContestInfo == TRUE)
                {
                    sLearnMoveStruct->state = 5;
                }
                sLearnMoveStruct->state = 16;
            }
        }
        break;
    case 27:
        if (!sub_81D2C3C())
        {
            FillWindowPixelBuffer(3, 0x11);
            if (gUnknown_0203BC38.showContestInfo == FALSE)
            {
                sLearnMoveStruct->state = 3;
            }
            else if (gUnknown_0203BC38.showContestInfo == TRUE)
            {
                sLearnMoveStruct->state = 5;
            }
        }
        break;
    case 19:
        if (!sub_81D2C3C())
        {
            sLearnMoveStruct->state = 20;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        }
        break;
    case 20:
        if (!gPaletteFade.active)
        {
            ShowSelectMovePokemonSummaryScreen(gPlayerParty, sLearnMoveStruct->partyMon, gPlayerPartyCount - 1, sub_8160740, sub_8161054());
            sub_8160EA0();
        }
        break;
    case 21:
        if (!sub_81D2C3C())
        {
            sLearnMoveStruct->state = 14;
        }
        break;
    case 22:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        break;
    case 14:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        sLearnMoveStruct->state++;
        break;
    case 15:
        if (!gPaletteFade.active)
        {
            sub_8160EA0();
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    case 28:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        sLearnMoveStruct->state++;
        if (gUnknown_0203BC38.showContestInfo == FALSE)
        {
            render_previous_quest_text(TRUE);
        }
        else if (gUnknown_0203BC38.showContestInfo == TRUE)
        {
            sub_8161074(1);
        }
        sub_8161234();
        CopyWindowToVram(3, 2);
        break;
    case 29:
        if (!gPaletteFade.active)
        {
            if (sLearnMoveStruct->unk045 == 4)
            {
                sLearnMoveStruct->state = 24;
            }
            else
            {
                u16 moveId = GetMonData(&gPlayerParty[sLearnMoveStruct->partyMon], MON_DATA_MOVE1 + sLearnMoveStruct->unk045);

                StringCopy(gStringVar3, gMoveNames[moveId]);
                RemoveMonPPBonus(&gPlayerParty[sLearnMoveStruct->partyMon], sLearnMoveStruct->unk045);
                SetMonMoveSlot(&gPlayerParty[sLearnMoveStruct->partyMon], sub_8161054(), sLearnMoveStruct->unk045);
                StringCopy(gStringVar2, gMoveNames[sub_8161054()]);
                sub_816084C(gText_12AndPoof);
                sLearnMoveStruct->state = 30;
                gSpecialVar_0x8004 = 1;
            }
        }
        break;
    case 30:
        if (!sub_81D2C3C())
        {
            sub_816084C(gText_PkmnForgotMoveAndLearnedNew);
            sLearnMoveStruct->state = 31;
            PlayFanfare(MUS_FANFA1);
        }
        break;
    case 31:
        if (!sub_81D2C3C())
        {
            PlayFanfare(MUS_FANFA1);
            sLearnMoveStruct->state = 32;
        }
        break;
    case 32:
        if (IsFanfareTaskInactive())
        {
            sLearnMoveStruct->state = 33;
        }
        break;
    case 33:
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            sLearnMoveStruct->state = 14;
        }
        break;
    }
}

void sub_8160EA0(void)
{
    sub_8161234();
    DestroyListMenuTask(sLearnMoveStruct->listMenuTask, &gUnknown_0203BC38.listOffset, &gUnknown_0203BC38.listRow);
    FreeAllWindowBuffers();
    FREE_AND_SET_NULL(sLearnMoveStruct);
    ResetSpriteData();
    FreeAllSpritePalettes();
}

void render_previous_quest_text(bool8 a)
{
    s32 i;

    for (i = 0; i < 16; i++)
    {
        gSprites[sLearnMoveStruct->spriteIds[i]].invisible = TRUE;
    }

    if (!a)
    {
        StringExpandPlaceholders(gStringVar4, gText_TeachWhichMoveToPkmn);
        FillWindowPixelBuffer(3, 0x11);
        PrintTextOnWindow(3, 1, gStringVar4, 0, 1, 0, NULL);
    }
}

void sub_816137C(s32);

void sub_8160F50(u8 a0)
{
    s32 itemId = ListMenuHandleInputGetItemId(sLearnMoveStruct->listMenuTask);
    ListMenuGetScrollAndRow(sLearnMoveStruct->listMenuTask, &gUnknown_0203BC38.listOffset, &gUnknown_0203BC38.listRow);

    switch (itemId)
    {
    case LIST_NOTHING_CHOSEN:
        if (!(gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT)) && !GetLRKeysState())
        {
            break;
        }

        PlaySE(SE_SELECT);

        if (a0 == 0)
        {
            PutWindowTilemap(1);
            sLearnMoveStruct->state = 5;
            gUnknown_0203BC38.showContestInfo = TRUE;
        }
        else
        {
            PutWindowTilemap(0);
            sLearnMoveStruct->state = 3;
            gUnknown_0203BC38.showContestInfo = FALSE;
        }

        schedule_bg_copy_tilemap_to_vram(1);
        sub_816137C(sub_8161054());
        break;
    case LIST_B_PRESSED:
        PlaySE(SE_SELECT);
        sub_8161234();
        sLearnMoveStruct->state = 12;
        StringExpandPlaceholders(gStringVar4, gText_GiveUpTeachingNewMove);
        sub_81D2BF4(gStringVar4);
        break;
    default:
        PlaySE(SE_SELECT);
        sub_8161234();
        sLearnMoveStruct->state = 8;
        StringCopy(gStringVar2, gMoveNames[itemId]);
        StringExpandPlaceholders(gStringVar4, gText_TeachX);
        sub_81D2BF4(gStringVar4);
        break;
    }
}

s32 sub_8161054(void)
{
    return sLearnMoveStruct->menuItems[gUnknown_0203BC38.listRow + gUnknown_0203BC38.listOffset].id;
}

void sub_8161074(u8 a0)
{
    if (!a0)
    {
        StringExpandPlaceholders(gStringVar4, gText_TeachWhichMoveToPkmn);
        FillWindowPixelBuffer(3, 0x11);
        PrintTextOnWindow(3, 1, gStringVar4, 0, 1, 0, NULL);
    }
}

void sub_81610B8(void)
{
    int i;

    sLearnMoveStruct->unk114 = 0xFF;
    sLearnMoveStruct->unk113 = -1;
    sub_81611AC();
    
    for (i = 0; i < 8; i++)
    {
        sLearnMoveStruct->spriteIds[i] = CreateSprite(&gUnknown_085CEC10, (i - (i / 4) * 4) * 8 + 104, (i / 4) * 8 + 36, 0);
    }

    for (i = 0; i < 8; i++)
    {
        sLearnMoveStruct->spriteIds[i + 8] = CreateSprite(&gUnknown_085CEC10, (i - (i / 4) * 4) * 8 + 104, (i / 4) * 8 + 52, 0);
        StartSpriteAnim(&gSprites[sLearnMoveStruct->spriteIds[i + 8]], 2);
    }

    for (i = 0; i < 16; i++)
    {
        gSprites[sLearnMoveStruct->spriteIds[i]].invisible = TRUE;
    }
}

void sub_81611AC(void)
{
    if (sLearnMoveStruct->unk114 == 0xFF)
    {
        sLearnMoveStruct->unk114 = AddScrollIndicatorArrowPair(&gUnknown_085CEBC0, &sLearnMoveStruct->unk116);
    }

    if (sLearnMoveStruct->unk113 == 0xFF)
    {
        gTempScrollArrowTemplate = gUnknown_085CEBD0;
        gTempScrollArrowTemplate.fullyDownThreshold = sLearnMoveStruct->numMenuChoices - sLearnMoveStruct->unk111;
        sLearnMoveStruct->unk113 = AddScrollIndicatorArrowPair(&gTempScrollArrowTemplate, &gUnknown_0203BC38.listOffset);
    }
}

void sub_8161234(void)
{
    if (sLearnMoveStruct->unk114 != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sLearnMoveStruct->unk114);
        sLearnMoveStruct->unk114 = 0xFF;
    }

    if (sLearnMoveStruct->unk113 != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sLearnMoveStruct->unk113);
        sLearnMoveStruct->unk113 = 0xFF;
    }
}

void sub_8161280(void)
{
    s32 i;
    u8 nickname[POKEMON_NAME_LENGTH + 1];

    sLearnMoveStruct->numMenuChoices = GetMoveRelearnerMoves(&gPlayerParty[sLearnMoveStruct->partyMon], sLearnMoveStruct->movesToLearn);

    for (i = 0; i < sLearnMoveStruct->numMenuChoices; i++)
    {
        sLearnMoveStruct->menuItems[i].name = gMoveNames[sLearnMoveStruct->movesToLearn[i]];
        sLearnMoveStruct->menuItems[i].id = sLearnMoveStruct->movesToLearn[i];
    }

    GetMonData(&gPlayerParty[sLearnMoveStruct->partyMon], MON_DATA_NICKNAME, nickname);
    StringCopy10(gStringVar1, nickname);
    sLearnMoveStruct->menuItems[sLearnMoveStruct->numMenuChoices].name = gText_Cancel;
    sLearnMoveStruct->menuItems[sLearnMoveStruct->numMenuChoices].id = LIST_B_PRESSED;
    sLearnMoveStruct->numMenuChoices++;
    sLearnMoveStruct->unk111 = sub_81D28C8(sLearnMoveStruct->menuItems, sLearnMoveStruct->numMenuChoices);
}

void sub_816137C(s32 item)
{
    u16 i;

    if (!gUnknown_0203BC38.showContestInfo || item == LIST_NOTHING_CHOSEN)
    {
        for (i = 0; i < 16; i++)
        {
            gSprites[sLearnMoveStruct->spriteIds[i]].invisible = TRUE;
        }
    }
    else
    {
        u8 temp1 = gContestEffects[gContestMoves[item].effect].appeal / 10;
        
        if (temp1 == 0xFF)
        {
            temp1 = 0;
        }

        for (i = 0; i < 8; i++)
        {
            if (i < temp1)
            {
                StartSpriteAnim(&gSprites[sLearnMoveStruct->spriteIds[i]], 1);
            }
            else
            {
                StartSpriteAnim(&gSprites[sLearnMoveStruct->spriteIds[i]], 0);
            }
            gSprites[sLearnMoveStruct->spriteIds[i]].invisible = FALSE;
        }

        temp1 = gContestEffects[gContestMoves[item].effect].jam / 10;
        
        if (temp1 == 0xFF)
        {
            temp1 = 0;
        }

        for (i = 0; i < 8; i++)
        {
            if (i < temp1)
            {
                StartSpriteAnim(&gSprites[sLearnMoveStruct->spriteIds[i]], 3);
            }
            else
            {
                StartSpriteAnim(&gSprites[sLearnMoveStruct->spriteIds[i]], 2);
            }
            gSprites[sLearnMoveStruct->spriteIds[i]].invisible = FALSE;
        }
    }
}
