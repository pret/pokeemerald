#include "global.h"
#include "alloc.h"
#include "bg.h"
#include "dynamic_placeholder_text_util.h"
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
    u8 unk1A[0x1F];
    u8 unk39[0x40];
    u8 unk79[0x40];
    u8 unkB9[10][21];
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
    u8 filler20[0x2];
    u8 unk22[0x2146];
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
u8 *sub_801EEA8(void);
static void sub_801EF1C(u8 *);
static void sub_801EF24(u8 *);
static void sub_801EF4C(u8 *);
static void sub_801EF7C(u8 *);
static void sub_801EFA8(u8 *);
static void sub_801EFD0(u8 *);
u8 *sub_801F114(void);
static void sub_801F2B4(u8 taskId);
static bool8 sub_801F4D0(void);
static bool32 sub_801F534(void);
static void sub_801F544(void);
static void sub_801F5B8(void);
static void sub_801F5EC(u16, u8);
static bool8 sub_801F644(u8);
static s8 sub_801FF08(void);
bool32 sub_8020890(void);
void sub_8020770(void);
static void sub_801F574(struct UnionRoomChat2 *);
static void sub_801F580(void);
void sub_80208D0(void);
static bool32 sub_801FDD8(u8 *);
void sub_8020480(void);
void sub_8020538(void);
void sub_8020584(void);
void sub_80205B4(void);
void task_tutorial_story_unknown(void);
void sub_8020680(void);
void sub_80206A4(void);
void sub_80206D0(void);
void sub_8020740(void);
void sub_80206E8(void);
void sub_80208E8(void);
void sub_8020A68(void);
void sub_8020B20(void);
void sub_80203B0(void);
void sub_802040C(void);
void sub_802091C(int);
bool32 sub_8020320(void);
void sub_80201A4(void);
bool32 sub_8020368(void);
void sub_802093C(void);
void sub_8020B80(void);
static void sub_801FF18(int, u16);
static void sub_801FDDC(u8, u8, u8);
static void sub_8020094(void);
static void sub_801FEBC(void);
static void sub_80200C8(void);
static void sub_801FEE4(void);
static void sub_80200EC(u16, u16, u8);
static void sub_8020118(u16, u8 *, u8, u8, u8);
void sub_80209AC(int);
void sub_8020420(u16, u8 *, u8);
void sub_80209E0(void);
bool32 sub_8020A1C(void);

extern struct UnionRoomChat *gUnknown_02022C84;
extern struct UnionRoomChat2 *gUnknown_02022C88;

extern const u8 *const gUnknown_082F2BA8[][10];
extern const u8 gUnknown_082F2AA8[];
extern const struct BgTemplate gUnknown_082F2C60[4];
extern const struct WindowTemplate gUnknown_082F2C70[];
extern const struct Unk82F2C98 gUnknown_082F2C98[];
extern const struct Unk82F2D40 gUnknown_082F2D40[];


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

bool32 sub_801EFF8(u8 *arg0, u8 *arg1)
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

u8 sub_801F0B0(void)
{
    return gUnknown_02022C84->unk10;
}

void sub_801F0BC(u8 *arg0, u8 *arg1)
{
    *arg0 = gUnknown_02022C84->unk11;
    *arg1 = gUnknown_02022C84->unk12;
}

static u8 *sub_801F0D0(void)
{
    return gUnknown_02022C84->unk1A;
}

int sub_801F0DC(void)
{
    u8 *str = sub_801F0D0();
    return StringLength_Multibyte(str);
}

void sub_801F0EC(u32 *arg0, u32 *arg1)
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

u8 *sub_801F114(void)
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

u16 sub_801F144(void)
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

u8 *sub_801F180(void)
{
    return gUnknown_02022C84->unk39;
}

u8 sub_801F18C(void)
{
    return gUnknown_02022C84->unk16;
}

int sub_801F198(void)
{
    return gUnknown_02022C84->unk15;
}

int sub_801F1A4(void)
{
    u8 *str = sub_801EEA8();
    u32 character = *str;
    if (character > 0xFF || gUnknown_082F2AA8[character] == character || gUnknown_082F2AA8[character] == 0)
        return 3;
    else
        return 0;
}

u8 *sub_801F1D0(void)
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
        task_tutorial_story_unknown();
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
        sub_802091C(1);
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
        sub_802091C(0);
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
        sub_8098858(gUnknown_02022C88->unk18, 1, 13);
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
        sub_80989E0(windowId, 0xA, 2);
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
        sub_8098858(windowId, 0xA, 2);
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
