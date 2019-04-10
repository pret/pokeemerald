#include "global.h"
#include "alloc.h"
#include "berry_powder.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item_icon.h"
#include "item_menu.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "math_util.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "rom_8034C54.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "window.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"

struct BerryCrushGame_Player
{
    u16 unk0;
    u8 filler2[0x12];
    u8 unk14[0xC];
};

struct BerryCrushGame_PlayersSeparate
{
    struct BerryCrushGame_Player player;
    struct BerryCrushGame_Player others[4];
};

typedef union BerryCrushGame_Players
{
    struct BerryCrushGame_Player players[5];
    struct BerryCrushGame_PlayersSeparate separate;
} BerryCrushGame_Players;

struct BerryCrushGame_138_C
{
    u8 filler0[0x8];
    s16 unk8;
    u16 unkA;
};

struct BerryCrushGame_138
{
    u8 filler0[0xC];
    struct BerryCrushGame_138_C *unkC[5];
    u8 filler1C[0x4];
    struct Sprite *unk24[5];
    struct Sprite *unk38[5];
    struct Sprite *unk4C[5];
    struct Sprite *unk60[5];
    struct Sprite *unk74[5];
};

struct BerryCrushGame_4E
{
    u8 filler0[0x4];
    u8 unk4;
    u8 filler5[0x5];
    u16 unkA;
    u16 unkC;
};

struct __attribute__((packed)) BerryCrushGame_40
{
    u8 filler0[0xE];
    struct BerryCrushGame_4E unkE;
};

struct BerryCrushGame
{
    MainCallback unk0;
    void (* unk4)(struct BerryCrushGame *, u8 *);
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 fillerD[0x1];
    u8 unkE;
    u8 unkF;
    u8 filler10[0x2];
    u16 unk12;
    u8 filler14[0x2];
    u16 unk16;
    u8 filler18[0x4];
    int unk1C;
    u8 filler20[0x5];
    u8 unk25_0:1;
    u8 unk25_1:1;
    u8 unk25_2:1;
    u8 filler26[0x2];
    u16 unk28;
    u16 unk2A;
    u16 unk2C;
    u8 filler2E[0x8];
    u8 unk36[0xA];
    struct BerryCrushGame_40 unk40;
    u8 filler60[0x8];
    int unk68;
    u16 unk6C;
    u8 filler6E[0x4];
    u16 unk72;
    u8 filler74[0x10];
    BerryCrushGame_Players unk84;
    u8 filler124[0x14];
    struct BerryCrushGame_138 unk138;
    u8 unk1C0[0x1000];
    u8 unk11C0[0x1000];
    u8 unk21C0[0x1000];
    u8 unk31C0[0x1000];
};

static void sub_8020F74(void);
static void sub_8020F88(void);
static void sub_8020FA0(u8);
void sub_8020FC4(struct BerryCrushGame *);
void sub_8022BEC(u16, u8, u8 *);
void sub_8024604(u8 *, u8, s8, u8, u8, u8, u8);
static int sub_8021450(struct BerryCrushGame *);
void sub_8022588(struct BerryCrushGame *);
void sub_8022600(struct BerryCrushGame *);
void sub_80226D0(struct BerryCrushGame *);
void sub_8022730(struct BerryCrushGame *);
void sub_8022960(struct BerryCrushGame *);
void sub_8022524(struct BerryCrushGame_138 *, u16);
void sub_8022B28(struct Sprite *);

static EWRAM_DATA struct BerryCrushGame *gUnknown_02022C90 = NULL;

extern const struct BgTemplate gUnknown_082F32C8[4];
extern const u8 gBerryCrushGrinderTopTilemap[];
extern const u8 gBerryCrushContainerCapTilemap[];
extern const u8 gBerryCrushBackgroundTilemap[];
extern const struct SpriteTemplate gUnknown_082F436C;
extern const u16 gUnknown_082F41E8[];
extern const s8 gUnknown_082F41CC[][2];
extern const s8 gUnknown_082F41D2[][2];

struct BerryCrushGame *sub_8020C00(void)
{
    return gUnknown_02022C90;
}

int sub_8020C0C(MainCallback callback)
{
    if (!gUnknown_02022C90)
        return 2;

    if (!callback)
        callback = gUnknown_02022C90->unk0;

    DestroyTask(gUnknown_02022C90->unkA);
    FREE_AND_SET_NULL(gUnknown_02022C90);
    SetMainCallback2(callback);
    if (callback == CB2_ReturnToField)
    {
        gTextFlags.autoScroll = 1;
        PlayNewMapMusic(MUS_POKECEN);
        SetMainCallback1(CB1_Overworld);
    }

    return 0;
}

void sub_8020C70(MainCallback callback)
{
    u8 playerCount = 0;
    u8 multiplayerId;

    if (!gReceivedRemoteLinkPlayers || gWirelessCommType == 0)
    {
        SetMainCallback2(callback);
        gUnknown_03005000.unk_10 = 0;
        gUnknown_03005000.unk_12 = 0;
        gUnknown_03005000.unk_ee = 1;
        return;
    }

    playerCount = GetLinkPlayerCount();
    multiplayerId = GetMultiplayerId();
    if (playerCount < 2 || multiplayerId >= playerCount)
    {
        SetMainCallback2(callback);
        gUnknown_03005000.unk_10 = 0;
        gUnknown_03005000.unk_12 = 0;
        gUnknown_03005000.unk_ee = 1;
        return;
    }

    gUnknown_02022C90 = AllocZeroed(sizeof(*gUnknown_02022C90));
    if (!gUnknown_02022C90)
    {
        SetMainCallback2(callback);
        gUnknown_03005000.unk_10 = 0;
        gUnknown_03005000.unk_12 = 0;
        gUnknown_03005000.unk_ee = 1;
        return;
    }

    gUnknown_02022C90->unk0 = callback;
    gUnknown_02022C90->unk8 = multiplayerId;
    gUnknown_02022C90->unk9 = playerCount;
    sub_8020FC4(gUnknown_02022C90);
    gUnknown_02022C90->unk12 = 1;
    gUnknown_02022C90->unkE = 1;
    gUnknown_02022C90->unkF = 6;
    sub_8024604(gUnknown_02022C90->unk36, 1, -1, 0, 16, 0, 0);
    sub_8022BEC(4, 1, gUnknown_02022C90->unk36);
    SetMainCallback2(sub_8020F88);
    gUnknown_02022C90->unkA = CreateTask(sub_8020FA0, 8);
    gTextFlags.autoScroll = 0;
}

static void sub_8020D8C(void)
{
    if (gSpecialVar_ItemId < FIRST_BERRY_INDEX || gSpecialVar_ItemId > LAST_BERRY_INDEX + 1)
        gSpecialVar_ItemId = ITEM_CHERI_BERRY;
    else
        RemoveBagItem(gSpecialVar_ItemId, 1);

    gUnknown_02022C90->unk84.separate.others[gUnknown_02022C90->unk8].unk0 = gSpecialVar_ItemId - FIRST_BERRY_INDEX;
    gUnknown_02022C90->unkE = 1;
    gUnknown_02022C90->unkF = 9;
    sub_8024604(gUnknown_02022C90->unk36, 0, -1, 0, 16, 0, 0);
    sub_8022BEC(4, 1, gUnknown_02022C90->unk36);
    gUnknown_02022C90->unkA = CreateTask(sub_8020FA0, 8);
    SetMainCallback2(sub_8020F88);
}

void sub_8020E1C(void)
{
    DestroyTask(gUnknown_02022C90->unkA);
    sub_81AABF0(sub_8020D8C);
}

static void sub_8020E3C(void)
{
    SetVBlankCallback(sub_8020F74);
}

void sub_8020E4C(void)
{
    SetVBlankCallback(NULL);
}

void sub_8020E58(void)
{
    u32 var0, var1;

    var0 = gUnknown_02022C90->unk6C;
    var0 <<= 8;
    var0 = sub_81515FC(var0, 60 << 8);
    var1 = gUnknown_02022C90->unk72;
    var1 <<= 8;
    var1 = sub_81515FC(var1, var0) & 0xFFFF;
    gUnknown_02022C90->unk16 = var1;
    switch (gUnknown_02022C90->unk9)
    {
    case 2:
        if (gUnknown_02022C90->unk16 > gSaveBlock2Ptr->berryCrush.berryCrushResults[0])
        {
            gUnknown_02022C90->unk25_1 = 1;
            gSaveBlock2Ptr->berryCrush.berryCrushResults[0] = gUnknown_02022C90->unk16;
        }
        break;
    case 3:
        if (gUnknown_02022C90->unk16 > gSaveBlock2Ptr->berryCrush.berryCrushResults[1])
        {
            gUnknown_02022C90->unk25_1 = 1;
            gSaveBlock2Ptr->berryCrush.berryCrushResults[1] = gUnknown_02022C90->unk16;
        }
        break;
    case 4:
        if (gUnknown_02022C90->unk16 > gSaveBlock2Ptr->berryCrush.berryCrushResults[2])
        {
            gUnknown_02022C90->unk25_1 = 1;
            gSaveBlock2Ptr->berryCrush.berryCrushResults[2] = gUnknown_02022C90->unk16;
        }
        break;
    case 5:
        if (gUnknown_02022C90->unk16 > gSaveBlock2Ptr->berryCrush.berryCrushResults[3])
        {
            gUnknown_02022C90->unk25_1 = 1;
            gSaveBlock2Ptr->berryCrush.berryCrushResults[3] = gUnknown_02022C90->unk16;
        }
        break;
    }

    gUnknown_02022C90->unk1C = gUnknown_02022C90->unk68;
    if (GiveBerryPowder(gUnknown_02022C90->unk1C))
        return;

    gUnknown_02022C90->unk25_0 = 1;
}

static void sub_8020F74(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

static void sub_8020F88(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
}

static void sub_8020FA0(u8 taskId)
{
    if (gUnknown_02022C90->unk4)
        gUnknown_02022C90->unk4(gUnknown_02022C90, gUnknown_02022C90->unk36);

    sub_8021450(gUnknown_02022C90);
}

#ifdef NONMATCHING
void sub_8020FC4(struct BerryCrushGame *arg0)
{
    u8 i;

    for (i = 0; i < arg0->unk9; i++)
        StringCopy(arg0->unk84.players[i].unk14, gLinkPlayers[i].name);

    for (; i < 5; i++)
    {
        memset(arg0->unk84.players[i].unk14, 1, PLAYER_NAME_LENGTH);
        arg0->unk84.players[i].unk14[PLAYER_NAME_LENGTH] = EOS;
    }

    switch (gSaveBlock2Ptr->optionsTextSpeed)
    {
    case OPTIONS_TEXT_SPEED_SLOW:
        arg0->unkB = 8;
        break;
    case OPTIONS_TEXT_SPEED_MID:
        arg0->unkB = 4;
        break;
    case OPTIONS_TEXT_SPEED_FAST:
        arg0->unkB = 1;
        break;
    }
}
#else
NAKED
void sub_8020FC4(struct BerryCrushGame *arg0)
{
    asm_unified("\n\
    push {r4-r6,lr}\n\
    adds r6, r0, 0\n\
    movs r5, 0\n\
    b _08020FE6\n\
LOOP_1:\n\
    lsls r0, r5, 5\n\
    adds r0, 0x98\n\
    adds r0, r6, r0\n\
    lsls r1, r5, 3\n\
    subs r1, r5\n\
    lsls r1, 2\n\
    ldr r2, =gLinkPlayers + 8\n\
    adds r1, r2\n\
    bl StringCopy\n\
    adds r0, r5, 0x1\n\
    lsls r0, 24\n\
    lsrs r5, r0, 24\n\
_08020FE6:\n\
    ldrb r0, [r6, 0x9]\n\
    cmp r5, r0\n\
    bcc LOOP_1\n\
    cmp r5, 0x4\n\
    bhi _08021012\n\
_08020FF0:\n\
    lsls r4, r5, 5\n\
    adds r0, r4, 0\n\
    adds r0, 0x98\n\
    adds r0, r6, r0\n\
    movs r1, 0x1\n\
    movs r2, 0x7\n\
    bl memset\n\
    adds r4, r6, r4\n\
    adds r4, 0x9F\n\
    movs r0, 0xFF\n\
    strb r0, [r4]\n\
    adds r0, r5, 0x1\n\
    lsls r0, 24\n\
    lsrs r5, r0, 24\n\
    cmp r5, 0x4\n\
    bls _08020FF0\n\
_08021012:\n\
    ldr r0, =gSaveBlock2Ptr\n\
    ldr r0, [r0]\n\
    ldrb r0, [r0, 0x14]\n\
    lsls r0, 29\n\
    lsrs r0, 29\n\
    cmp r0, 0x1\n\
    beq _0802103E\n\
    cmp r0, 0x1\n\
    bgt _08021034\n\
    cmp r0, 0\n\
    beq _0802103A\n\
    b _08021046\n\
    .pool\n\
_08021034:\n\
    cmp r0, 0x2\n\
    beq _08021042\n\
    b _08021046\n\
_0802103A:\n\
    movs r0, 0x8\n\
    b _08021044\n\
_0802103E:\n\
    movs r0, 0x4\n\
    b _08021044\n\
_08021042:\n\
    movs r0, 0x1\n\
_08021044:\n\
    strb r0, [r6, 0xB]\n\
_08021046:\n\
    pop {r4-r6}\n\
    pop {r0}\n\
    bx r0");
}
#endif // NONMATCHING

int sub_802104C(void)
{
    struct BerryCrushGame *var0 = sub_8020C00();
    if (!var0)
        return -1;

    switch (var0->unkC)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetHBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ScanlineEffect_Stop();
        reset_temp_tile_data_buffers();
        break;
    case 1:
        CpuFill16(0, (void *)OAM, OAM_SIZE);
        gReservedSpritePaletteCount = 0;
        sub_8034C54(3);
        break;
    case 2:
        ResetPaletteFade();
        ResetSpriteData();
        FreeAllSpritePalettes();
        break;
    case 3:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_082F32C8, ARRAY_COUNT(gUnknown_082F32C8));
        SetBgTilemapBuffer(1, var0->unk1C0);
        SetBgTilemapBuffer(2, var0->unk21C0);
        SetBgTilemapBuffer(3, var0->unk31C0);
        ChangeBgX(0, 0, 0);
        ChangeBgY(0, 0, 0);
        ChangeBgX(2, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgX(3, 0, 0);
        ChangeBgY(3, 0, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 64);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
        break;
    case 5:
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        decompress_and_copy_tile_data_to_vram(1, gUnknown_08DE34B8, 0, 0, 0);
        break;
    case 6:
        if (free_temp_tile_data_buffers_if_possible())
            return 0;

        InitStandardTextBoxWindows();
        sub_8197200();
        sub_8022588(var0);
        sub_8022600(var0);
        gPaletteFade.bufferTransferDisabled = 1;
        break;
    case 7:
        LoadPalette(gUnknown_08DE3398, 0, 0x180);
        CopyToBgTilemapBuffer(1, gBerryCrushGrinderTopTilemap, 0, 0);
        CopyToBgTilemapBuffer(2, gBerryCrushContainerCapTilemap, 0, 0);
        CopyToBgTilemapBuffer(3, gBerryCrushBackgroundTilemap, 0, 0);
        sub_80226D0(var0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        break;
    case 8:
        LoadWirelessStatusIndicatorSpriteGfx();
        CreateWirelessStatusIndicatorSprite(0,  0);
        sub_8022730(var0);
        SetGpuReg(REG_OFFSET_BG1VOFS, -gSpriteCoordOffsetY);
        ChangeBgX(1, 0, 0);
        ChangeBgY(1, 0, 0);
        break;
    case 9:
        gPaletteFade.bufferTransferDisabled = 0;
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        sub_8020E3C();
        var0->unkC = 0;
        return 1;
    }

    var0->unkC++;
    return 0;
}

int sub_802130C(void)
{
    struct BerryCrushGame *var0 = sub_8020C00();
    if (!var0)
        return -1;

    switch (var0->unkC)
    {
    case 0:
        sub_8010434();
        break;
    case 1:
        if (!IsLinkTaskFinished())
            return 0;
        // fall through. The original author forgot to use "break" here
        // because this will call BeginNormalPaletteFade() twice.
    case 2:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        UpdatePaletteFade();
        break;
    case 3:
        if (UpdatePaletteFade())
            return 0;
        break;
    case 4:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 32, 32);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 32, 32);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        break;
    case 5:
        FreeAllWindowBuffers();
        HideBg(0);
        UnsetBgTilemapBuffer(0);
        HideBg(1);
        UnsetBgTilemapBuffer(1);
        HideBg(2);
        UnsetBgTilemapBuffer(2);
        HideBg(3);
        UnsetBgTilemapBuffer(3);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        break;
    case 6:
        DestroyWirelessStatusIndicatorSprite();
        sub_8022960(var0);
        sub_8034CC8();
        break;
    case 7:
        var0->unkC = 0;
        return 1;
    }

    var0->unkC++;
    return 0;
}

static int sub_8021450(struct BerryCrushGame *arg0)
{
    gSpriteCoordOffsetY = arg0->unk2A + arg0->unk2C;
    SetGpuReg(REG_OFFSET_BG1VOFS, -gSpriteCoordOffsetY);
    if (arg0->unk12 == 7)
    {
        sub_8022524(&arg0->unk138, arg0->unk28);
    }

    return 0;
}

void sub_8021488(struct BerryCrushGame *arg0)
{
    arg0->unk2A = -104;
    arg0->unk2C = 0;
    gSpriteCoordOffsetX = 0;
    gSpriteCoordOffsetY = -104;
}

void sub_80214A8(struct BerryCrushGame *arg0, struct BerryCrushGame_138 *arg1)
{
    u8 i;
    u8 spriteId;
    s16 var0, var1;
    s16 *data;
    int var3;
    s16 var5;
    u32 var6;

    for (i = 0; i < arg0->unk9; i++)
    {
        spriteId = AddCustomItemIconSprite(
            &gUnknown_082F436C,
            gUnknown_082F41E8[i],
            gUnknown_082F41E8[i],
            arg0->unk84.separate.others[i].unk0 + 133);
        arg1->unk38[i] = &gSprites[spriteId];
        arg1->unk38[i]->oam.priority = 3;
        arg1->unk38[i]->affineAnimPaused = 1;
        arg1->unk38[i]->pos1.x = arg1->unkC[i]->unk8 + 120;
        arg1->unk38[i]->pos1.y = -16;
        data = arg1->unk38[i]->data;
        var5 = 512;
        data[1] = var5;
        data[2] = 32;
        data[7] = 112;
        var0 = arg1->unkC[i]->unkA - arg1->unkC[i]->unk8;
        var3 = var0;
        if (var0 < 0)
            var3 += 3;

        data[6] = var3 >> 2;
        var0 *= 128;
        var6 = var5 + 32;
        var6 = var6 / 2;
        var1 = sub_81515D4(7, 0x3F80, var6);
        data[0] = (u16)arg1->unk38[i]->pos1.x * 128;
        data[3] = sub_81515D4(7, var0, var1);
        var1 = sub_8151550(7, var1, 85);
        data[4] = 0;
        data[5] = sub_81515D4(7, 0x3F80, var1);
        data[7] |= 0x8000;
        if (arg1->unkC[i]->unk8 < 0)
            StartSpriteAffineAnim(arg1->unk38[i], 1);
    }
}

void sub_8021608(struct Sprite *sprite)
{
    s16 *data = sprite->data;

    data[1] += data[2];
    sprite->pos2.y += data[1] >> 8;
    if (data[7] & 0x8000)
    {
        sprite->data[0] += data[3];
        data[4] += data[5];
        sprite->pos2.x = Sin(data[4] >> 7, data[6]);
        if ((data[7] & 0x8000) && (data[4] >> 7) > 126)
        {
            sprite->pos2.x = 0;
            data[7] &= 0x7FFF;
        }
    }

    sprite->pos1.x = data[0] >> 7;
    if (sprite->pos1.y + sprite->pos2.y >= (data[7] & 0x7FFF))
    {
        sprite->callback = SpriteCallbackDummy;
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void sub_80216A8(struct BerryCrushGame *arg0)
{
    u8 i;
    for (i = 0; i < arg0->unk9; i++)
    {
        FreeSpritePaletteByTag(gUnknown_082F41E8[i]);
        FreeSpriteTilesByTag(gUnknown_082F41E8[i]);
    }
}

// void sub_80216E0(struct BerryCrushGame *arg0, struct BerryCrushGame_138 *arg1)
// {
//     u8 sp4;
//     struct BerryCrushGame_4E *var4E;
//     u8 i;
//     u16 var0;

//     sp4 = 0;
//     var4E = &arg0->unk40.unkE;
//     for (i = 0; i < arg0->unk9; i++)
//     {
//         var0 = var4E->unkA >> (i * 3);
//         var0 &= 7;
//         if (var0)
//         {
//             int offset;
//             sp4++;
//             if (var0 & 0x4)
//                 StartSpriteAnim(arg1->unk24[i], 1);
//             else
//                 StartSpriteAnim(arg1->unk24[i], 0);

//             arg1->unk24[i]->invisible = 0;
//             arg1->unk24[i]->animPaused = 0;
//             offset = (var0 % 4) - 1;
//             arg1->unk24[i]->pos2.x = gUnknown_082F41CC[offset][0];
//             arg1->unk24[i]->pos2.y = gUnknown_082F41CC[offset][1];
//         }
//     }

//     if (sp4 == 0)
//     {
//         arg0->unk25_2 = 0;
//     }
//     else
//     {
//         u8 var3 = arg0->unk28 % 3;
//         u16 var2 = var3;
//         for (i = 0; i < var4E->unkC * 2 + 3; i++)
//         {
//             if (arg1->unk4C[i]->invisible)
//             {
//                 arg1->unk4C[i]->callback = sub_8022B28;
//                 arg1->unk4C[i]->pos1.x = gUnknown_082F41D2[i][0] + 120;
//                 arg1->unk4C[i]->pos1.y = gUnknown_082F41D2[i][1] + (136 - var2 * 4);
//                 arg1->unk4C[i]->pos2.x = gUnknown_082F41D2[i][0] / (var3 * 4);
//                 arg1->unk4C[i]->pos2.y = gUnknown_082F41D2[i][1];
//                 if (var4E->unk4 & 0x2)
//                     StartSpriteAnim(arg1->unk4C[i], 1);
//                 else
//                     StartSpriteAnim(arg1->unk4C[i], 0);

//                 var2++;
//                 if (var2 > 3)
//                     var2 = 0;
//             }
//         }

//         if (arg0->unk25_2)
//         {
//             arg0->unk25_2 = 0;
//         }
//         else
//         {
//             if (sp4 == 1)
//                 PlaySE(SE_TOY_DANGO);
//             else
//                 PlaySE(SE_TOY_KABE);

//             arg0->unk25_2 = 1;
//         }
//     }
// }
