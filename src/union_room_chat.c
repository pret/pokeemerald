#include "global.h"
#include "alloc.h"
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
#include "task.h"
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
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A[0x9F];
    u8 unkB9[10][21];
    u8 filler18B[0x5];
    u8 unk190[0x28];
    u16 unk1B8;
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
u8 *sub_801EEA8(void);
static void sub_801EF1C(u8 *);
static void sub_801EF24(u8 *);
static void sub_801EF4C(u8 *);
static void sub_801EF7C(u8 *);
static void sub_801EFA8(u8 *);
static void sub_801EFD0(u8 *);
u8 *sub_801F114(void);
void sub_801F2B4(u8 taskId);
bool8 sub_801F4D0(void);
int sub_801F534(void);
void sub_801F544(void);
void sub_801F5B8(void);
void sub_801F5EC(u16, u8);
bool8 sub_801F644(u8);
s8 sub_801FF08(void);

extern struct UnionRoomChat *gUnknown_02022C84;

extern const u8 *const gUnknown_082F2BA8[][10];
extern const u8 gUnknown_082F2AA8[];


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
    unionRoomChat->unk10 = 0;
    unionRoomChat->unk11 = 0;
    unionRoomChat->unk12 = 0;
    unionRoomChat->unk14 = 0;
    unionRoomChat->unk15 = 0;
    unionRoomChat->unk16 = 0;
    unionRoomChat->unk1A[0] = EOS;
    unionRoomChat->unkD = GetLinkPlayerCount();
    unionRoomChat->unk13 = GetMultiplayerId();
    unionRoomChat->unk17 = 0;
    unionRoomChat->unk18 = 0;
    sub_801EF1C(unionRoomChat->unk190);
    for (i = 0; i < 10; i++)
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
            sub_800E0E8();
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
            if (gUnknown_02022C84->unk10 != 3)
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
            if (gUnknown_02022C84->unk10 == input || input > 3)
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
        gUnknown_02022C84->unk12 = 0;
        sub_801F5EC(5, 1);
        gUnknown_02022C84->unk10 = input;
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

static const u8 sUnknown_082F2AA4[] = {9, 9, 9, 9};

static bool32 sub_801EBE4(void)
{
    if (!(gMain.newAndRepeatedKeys & DPAD_UP))
    {
        if (gMain.newAndRepeatedKeys & DPAD_DOWN)
        {
            if (gUnknown_02022C84->unk12 < sUnknown_082F2AA4[gUnknown_02022C84->unk10])
                gUnknown_02022C84->unk12++;
            else
                gUnknown_02022C84->unk12 = 0;

            return TRUE;
        }

        if (gUnknown_02022C84->unk10 != 3)
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
        if (gUnknown_02022C84->unk12)
            gUnknown_02022C84->unk12--;
        else
            gUnknown_02022C84->unk12 = sUnknown_082F2AA4[gUnknown_02022C84->unk10];

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

    if (gUnknown_02022C84->unk10 != 3)
    {
        charsStr = gUnknown_082F2BA8[gUnknown_02022C84->unk10][gUnknown_02022C84->unk12];
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
        u8 *tempStr = StringCopy(buffer, gUnknown_02022C84->unkB9[gUnknown_02022C84->unk12]);
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
    StringCopy(gUnknown_02022C84->unkB9[gUnknown_02022C84->unk12], src);
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
    for (i = 0; i < 10; i++)
        StringCopy(gSaveBlock1Ptr->unk3C88[i], gUnknown_02022C84->unkB9[i]);
}

u8 *sub_801EE6C(int arg0)
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

u8 *sub_801EEA8(void)
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

u16 sub_801EED8(void)
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
