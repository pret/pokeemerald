#include "global.h"
#include "constants/decorations.h"
#include "decompress.h"
#include "alloc.h"
#include "text.h"
#include "string_util.h"
#include "international_string_util.h"
#include "script.h"
#include "task.h"
#include "main.h"
#include "palette.h"
#include "constants/songs.h"
#include "overworld.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "field_weather.h"
#include "field_player_avatar.h"
#include "field_camera.h"
#include "field_screen.h"
#include "event_object_movement.h"
#include "list_menu.h"
#include "menu_helpers.h"
#include "menu.h"
#include "sound.h"
#include "event_scripts.h"
#include "event_data.h"
#include "constants/region_map_sections.h"
#include "player_pc.h"
#include "strings.h"
#include "tv.h"
#include "secret_base.h"
#include "tilesets.h"
#include "item_icon.h"
#include "trader.h"
#include "constants/event_objects.h"
#include "decoration_inventory.h"
#include "decoration.h"
#include "graphics.h"

// Static type declarations

#define OVERWORLD_PLACE_DECOR_SELECTOR_PAL_TAG 0xbe5
#define OVERWORLD_PLACE_DECOR_PLAYER_PAL_TAG 0x008

struct DecorPCBuffer {
    struct ListMenuItem items[41];
    u8 names[41][24];
    u8 unk_520;
    u8 unk_521;
    u8 unk_522;
};

struct PlaceDecorationGraphicsDataBuffer {
    /*0x000; 0x0203a190*/ const struct Decoration *decoration;
    /*0x004; 0x0203a194*/ u16 tiles[0x40];
    /*0x084; 0x0203a214*/ u8 image[0x800];
    /*0x884; 0x0203aa14*/ u16 palette[16];
};

struct DecorRearrangementDataBuffer {
    u8 idx;
    u8 width;
    u8 height;
    u16 flagId;
};

// Static RAM declarations

EWRAM_DATA u8 *gCurDecorInventoryItems = NULL;
EWRAM_DATA static u8 sSecretBasePCMenuCursorPos = 0;
EWRAM_DATA static u8 sCurDecorCatCount = 0;
EWRAM_DATA static u8 sSecretBaseItemsIndicesBuffer[16] = {};
EWRAM_DATA static u8 sPlayerRoomItemsIndicesBuffer[12] = {};
EWRAM_DATA static u16 sSecretBasePCSelectDecorLineNo = 0;
EWRAM_DATA static u16 sSecretBasePCSelectDecorPageNo = 0;
EWRAM_DATA u8 gCurDecorationIndex = 0;
EWRAM_DATA static u8 sCurDecorationCategory = DECORCAT_DESK;
EWRAM_DATA static u32 filler_0203a174[2] = {};
EWRAM_DATA struct DecorPCPointers gUnknown_0203A17C = {};
EWRAM_DATA static u8 sDecorMenuWindowIndices[4] = {};
EWRAM_DATA struct DecorPCBuffer *sDecorPCBuffer = NULL;
EWRAM_DATA struct PlaceDecorationGraphicsDataBuffer sPlaceDecorationGraphicsDataBuffer = {};
EWRAM_DATA static u16 sCurDecorMapX = 0;
EWRAM_DATA static u16 sCurDecorMapY = 0;
EWRAM_DATA static u8 sDecor_CameraSpriteObjectIdx1 = 0;
EWRAM_DATA static u8 sDecor_CameraSpriteObjectIdx2 = 0;
EWRAM_DATA static u8 sDecorationLastDirectionMoved = 0;
EWRAM_DATA static struct OamData sDecorSelectorOam = {};
EWRAM_DATA static struct DecorRearrangementDataBuffer sDecorRearrangementDataBuffer[16] = {};
EWRAM_DATA static u8 sCurDecorSelectedInRearrangement = 0;

// Static ROM declarations

void sub_8126B80(u8 taskId);
void sub_8126C08(void);
void SecretBasePC_Decorate(u8 taskId);
void SecretBasePC_PutAway(u8 taskId);
void SecretBasePC_Toss(u8 taskId);
void sub_8126DA4(u8 taskId);
void SecretBasePC_Cancel(u8 taskId);
void SecretBasePC_PrepMenuForSelectingStoredDecors(u8 taskId);
void sub_8126DFC(u8 taskId);
void sub_8126E8C(u8 taskId);
void sub_8126F68(u8 winid, u8 decorCat, u8 x, u8 y, bool8 flag, u8 speed);
void sub_8127058(u8 *str, bool8 flag);
void sub_8127088(u8 taskId);
void sub_81270E8(u8 taskId);
void sub_8127180(u8 taskId);
void sub_812719C(u8 taskId);
void sub_81271CC(u8 taskId);
void sub_8127268(u8 taskId);
void sub_8127454(u8 *dest, u16 decorId);
void sub_8127480(s32 a0, bool8 flag, struct ListMenu *menu);
void sub_81274A0(u8 a0, s32 a1, u8 a2);
void sub_8127620(u8 taskId);
void sub_812764C(u8 taskId);
void sub_8127744(u32 a0);
void sub_81277A8(void);
bool8 sub_81277BC(u8 idx);
bool8 sub_81277E8(u8 idx);
void IdentifyOwnedDecorationsCurrentlyInUse(u8 taskId);
void sub_812759C(u8 taskId);
void sub_8127718(u8 decorCat);
void sub_8127A30(u8 taskId);
void sub_8127A8C(u8 taskId);
void sub_8127F68(u8 taskId);
void sub_8128060(u8 taskId);
void ConfigureCameraObjectForPlacingDecoration(struct PlaceDecorationGraphicsDataBuffer *data, u8 decor);
void SetUpPlacingDecorationPlayerAvatar(u8 taskId, struct PlaceDecorationGraphicsDataBuffer *data);
void sub_812826C(u8 taskId);
void sub_81283BC(u8 taskId);
void sub_8128414(u8 taskId);
void sub_8128950(u8 taskId);
void sub_81289D0(u8 taskId);
void sub_81289F0(u8 taskId);
void sub_8128AAC(u8 taskId);
void sub_8128B80(u8 taskId);
void sub_8128BA0(u8 taskId);
void sub_8128BBC(u8 taskId);
void c1_overworld_prev_quest(u8 taskId);
void sub_8128CD4(void);
void sub_8128DE0(void);
void sub_8128FD8(u8 taskId);
void sub_8129020(u8 taskId);
void sub_81292D0(struct Sprite *sprite);
void sub_81292E8(struct Sprite *sprite);
u8 gpu_pal_decompress_alloc_tag_and_upload(struct PlaceDecorationGraphicsDataBuffer *data, u8 decor);
const u32 *GetDecorationIconPicOrPalette(u16 decor, u8 mode);
bool8 sub_81299AC(u8 taskId);
void sub_8129ABC(u8 taskId);
void sub_8129B34(u8 taskId);
void sub_8129BCC(u8 taskId);
void sub_8129BF8(u8 taskId);
void sub_8129C74(u8 taskId);
void sub_8129D64(u8 taskId);
void sub_812A0E8(u8 taskId);
void sub_812A1A0(u8 taskId);
void sub_812A1C0(u8 taskId);
void sub_812A1F0(u8 taskId);
void sub_812A210(u8 taskId);
void sub_812A22C(u8 taskId);
void sub_812A25C(u8 taskId);
void sub_812A334(void);
void sub_812A36C(struct Sprite *sprite);
void sub_812A39C(void);
void sub_812A3C8(void);
void sub_812A3D4(u8 taskId);
void sub_812A458(u8 taskId);
void sub_812A478(u8 taskId);

// .rodata

#include "data/decoration/tiles.h"
#include "data/decoration/description.h"
#include "data/decoration/header.h"

const u8 *const sDecorCatNames[] = {
    gText_Desk,
    gText_Chair,
    gText_Plant,
    gText_Ornament,
    gText_Mat,
    gText_Poster,
    gText_Doll,
    gText_Cushion
};

const struct MenuAction sSecretBasePCMenuActions[] = {
    {
        gText_Decorate, {.void_u8=SecretBasePC_Decorate}
    }, {
        gText_PutAway, {.void_u8=SecretBasePC_PutAway}
    }, {
        gText_Toss2, {.void_u8=SecretBasePC_Toss}
    }, {
        gText_Cancel, {.void_u8=SecretBasePC_Cancel}
    }
};

const u8 *const sSecretBasePCMenuItemDescriptions[] = {
    gText_PutOutSelectedDecorItem,
    gText_StoreChosenDecorInPC,
    gText_ThrowAwayUnwantedDecors,
    gText_GoBackPrevMenu
};

void (*const SecretBasePC_SelectedDecorActions[][2])(u8 taskId) = {
   {
        sub_8127F68, sub_8127A8C
   }, {
        sub_812A3D4, sub_8127A8C
   }, {
        sub_8133DA0, sub_8127A8C
   }
};

const struct WindowTemplate gUnknown_085A6B90[4] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 18,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 0x0001
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 13,
        .height = 18,
        .paletteNum = 13,
        .baseBlock = 0x0091
    },
    {
        .bg = 0,
        .tilemapLeft = 17,
        .tilemapTop = 1,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x017b
    },
    {
        .bg = 0,
        .tilemapLeft = 16,
        .tilemapTop = 13,
        .width = 13,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0193
    }
};

const u16 gUnknown_085A6BB0[] = INCBIN_U16("graphics/decorations/unk_85a6bb0.gbapal");

const struct ListMenuTemplate gUnknown_085A6BD0 =
{
    .items = NULL,
    .moveCursorFunc = sub_8127480,
    .itemPrintFunc = sub_81274A0,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 9,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = FALSE,
    .itemVerticalPadding = 0,
    .scrollMultiple = FALSE,
    .fontId = 7
};

#include "data/decoration/icon.h"
#include "data/decoration/tilemaps.h"

const struct {
    u8 shape;
    u8 size;
    u8 x;
    u8 y;
} gUnknown_085A7250[] = {
    {0, 1, 0x78, 0x4e},
    {1, 2, 0x80, 0x4e},
    {1, 3, 0x90, 0x56},
    {1, 3, 0x90, 0x46},
    {0, 2, 0x80, 0x46},
    {2, 2, 0x78, 0x46},
    {2, 3, 0x80, 0x56},
    {2, 3, 0x80, 0x36},
    {0, 3, 0x90, 0x46},
    {1, 3, 0x90, 0x46}
};

const union AnimCmd gUnknown_085A7278[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};

const union AnimCmd *const sDecorSelectorAnims[] = {
    gUnknown_085A7278
};

const struct SpriteFrameImage sDecorSelectorSpriteFrameImages = {
    (const u8 *)&sPlaceDecorationGraphicsDataBuffer.image, 0x800
};

const struct SpriteTemplate sDecorSelectorSpriteTemplate = {
    0xFFFF,
    OVERWORLD_PLACE_DECOR_SELECTOR_PAL_TAG,
    &sDecorSelectorOam,
    sDecorSelectorAnims,
    &sDecorSelectorSpriteFrameImages,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

const struct SpriteTemplate sDecorWhilePlacingSpriteTemplate = {
    0x0000,
    0x0000,
    &sDecorSelectorOam,
    sDecorSelectorAnims,
    NULL,
    gDummySpriteAffineAnimTable,
    SpriteCallbackDummy
};

const struct SpritePalette gUnknown_085A72BC = {
    (const u16 *)&sPlaceDecorationGraphicsDataBuffer.palette, OVERWORLD_PLACE_DECOR_SELECTOR_PAL_TAG
};

const struct YesNoFuncTable gUnknown_085A72C4 = {
    sub_81289F0,
    sub_8128FD8
};

const struct YesNoFuncTable gUnknown_085A72CC = {
    sub_8128BA0,
    sub_8128FD8
};

const struct YesNoFuncTable gUnknown_085A72D4[] = {
    {
        sub_81283BC,
        sub_8128414
    }, {
        sub_8129BCC,
        sub_8129BF8
    }
};

const u8 gUnknown_085A72E4[] = {
    0x04, 0x04, 0x04, 0x04, 0x00, 0x03, 0x03, 0x00
};

const u8 gUnknown_085A72EC[] = {
    0x04, 0x04, 0x04, 0x04, 0x00, 0x04, 0x03, 0x00
};

const u16 gUnknown_085A72F4[] = {
    0x04, 0x08, 0x10, 0x20, 0x10, 0x08, 0x10, 0x20, 0x40, 0x20
};

const u16 Unknown_085A7308[] = INCBIN_U16("graphics/decorations/unk_85a7308.gbapal");

const u16 Unknown_085A7328[] = INCBIN_U16("graphics/decorations/unk_85a7328.gbapal");

const struct YesNoFuncTable gUnknown_085A7348 = {
    sub_812A1C0,
    sub_8129B34
};

const struct YesNoFuncTable gUnknown_085A7350 = {
    sub_812A210,
    sub_8129B34
};

const u8 Unknown_085A7358[] = INCBIN_U8("graphics/misc/decoration_unk_85a7358.4bpp");

const struct SpritePalette gUnknown_085A73D8 = {
    Unknown_085A7308, OVERWORLD_PLACE_DECOR_PLAYER_PAL_TAG
};

const struct SpritePalette gUnknown_085A73E0 = {
    Unknown_085A7328, OVERWORLD_PLACE_DECOR_PLAYER_PAL_TAG
};

const struct OamData Unknown_085A73E8 = {
    .size = 1, .priority = 1
};

const union AnimCmd Unknown_085A73F0[] = {
    ANIMCMD_FRAME(0, 0, 0),
    ANIMCMD_END
};

const union AnimCmd *const Unknown_085A73F8[] = {
    Unknown_085A73F0
};

const struct SpriteFrameImage Unknown_085A73FC = {
    Unknown_085A7358, 0x80
};

const struct SpriteTemplate gUnknown_085A7404 = {
    0xFFFF,
    OVERWORLD_PLACE_DECOR_PLAYER_PAL_TAG,
    &Unknown_085A73E8,
    Unknown_085A73F8,
    &Unknown_085A73FC,
    gDummySpriteAffineAnimTable,
    sub_812A36C
};

const struct YesNoFuncTable gUnknown_085A741C = {
    sub_812A478,
    sub_8127A30
};

// .text

void sub_8126968(void)
{
    if (sCurDecorationCategory < 8)
    {
        gCurDecorInventoryItems = gDecorationInventories[sCurDecorationCategory].items;
    }
    if (gUnknown_0203A17C.isPlayerRoom == FALSE)
    {
        gUnknown_0203A17C.items = gSaveBlock1Ptr->secretBases[0].decorations;
        gUnknown_0203A17C.pos = gSaveBlock1Ptr->secretBases[0].decorationPos;
    }
    if (gUnknown_0203A17C.isPlayerRoom == TRUE)
    {
        gUnknown_0203A17C.items = gSaveBlock1Ptr->playerRoomDecor;
        gUnknown_0203A17C.pos = gSaveBlock1Ptr->playerRoomDecorPos;
    }
}

u8 sub_81269D4(u8 idx)
{
    u8 *winidx;
    struct WindowTemplate template;

    winidx = &sDecorMenuWindowIndices[idx];
    if (idx == 0)
    {
        template = gUnknown_085A6B90[0];
        template.width = GetMaxWidthInMenuTable(sSecretBasePCMenuActions, 4);
        if (template.width > 18)
        {
            template.width = 18;
        }
        *winidx = AddWindow(&template);
    }
    else
    {
        *winidx = AddWindow(&gUnknown_085A6B90[idx]);
    }
    SetWindowBorderStyle(*winidx, 0, 0x214, 0xe);
    schedule_bg_copy_tilemap_to_vram(0);
    return *winidx;
}

void sub_8126A58(u8 idx)
{
    sub_8198070(sDecorMenuWindowIndices[idx], FALSE);
    ClearWindowTilemap(sDecorMenuWindowIndices[idx]);
    RemoveWindow(sDecorMenuWindowIndices[idx]);
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_8126A88(void)
{
    u8 idx;

    idx = sub_81269D4(0);
    PrintMenuTable(idx, 4, sSecretBasePCMenuActions);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(idx, 4, sSecretBasePCMenuCursorPos);
}

void sub_8126ABC(void)
{
    sSecretBasePCMenuCursorPos = 0;
    ScriptContext2_Enable();
    sub_8126A88();
    sub_8126C08();
}

void sub_8126AD8(u8 taskId)
{
    sub_8126ABC();
    gUnknown_0203A17C.items = gSaveBlock1Ptr->secretBases[0].decorations;
    gUnknown_0203A17C.pos = gSaveBlock1Ptr->secretBases[0].decorationPos;
    gUnknown_0203A17C.size = sizeof(gSaveBlock1Ptr->secretBases[0].decorations);
    gUnknown_0203A17C.isPlayerRoom = FALSE;
    gTasks[taskId].func = sub_8126B80;
}

void sub_8126B2C(u8 taskId)
{
    sub_8126ABC();
    gUnknown_0203A17C.items = gSaveBlock1Ptr->playerRoomDecor;
    gUnknown_0203A17C.pos = gSaveBlock1Ptr->playerRoomDecorPos;
    gUnknown_0203A17C.size = sizeof(gSaveBlock1Ptr->playerRoomDecor);
    gUnknown_0203A17C.isPlayerRoom = TRUE;
    gTasks[taskId].func = sub_8126B80;
}

void sub_8126B80(u8 taskId)
{
    u8 menuPos;

    if (!gPaletteFade.active)
    {
        menuPos = GetMenuCursorPos();
        switch (Menu_ProcessInput())
        {
            default:
                PlaySE(SE_SELECT);
                sSecretBasePCMenuActions[sSecretBasePCMenuCursorPos].func.void_u8(taskId);
                break;
            case -2:
                sSecretBasePCMenuCursorPos = GetMenuCursorPos();
                if ((s8)menuPos != sSecretBasePCMenuCursorPos)
                {
                    sub_8126C08();
                }
                break;
            case -1:
                PlaySE(SE_SELECT);
                SecretBasePC_Cancel(taskId);
                break;
        }
    }
}

void sub_8126C08(void)
{
    FillWindowPixelBuffer(0, 0x11);
    AddTextPrinterParameterized2(0, 1, sSecretBasePCMenuItemDescriptions[sSecretBasePCMenuCursorPos], 0, 0, 2, 1, 3);
}

void SecretBasePC_Decorate(u8 taskId)
{
    if (CountDecorations() == 0)
    {
        StringExpandPlaceholders(gStringVar4, gText_NoDecorations);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8126DA4);
    }
    else
    {
        gTasks[taskId].data[11] = 0;
        sCurDecorationCategory = DECORCAT_DESK;
        SecretBasePC_PrepMenuForSelectingStoredDecors(taskId);
    }
}

void SecretBasePC_PutAway(u8 taskId)
{
    if (!sub_81299AC(taskId))
    {
        StringExpandPlaceholders(gStringVar4, gText_NoDecorationsInUse);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8126DA4);
    }
    else
    {
        sub_8126A58(0);
        sub_8197434(0, 0);
        FadeScreen(1, 0);
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].func = sub_8129ABC;
    }
}

void SecretBasePC_Toss(u8 taskId)
{
    if (CountDecorations() == 0)
    {
        StringExpandPlaceholders(gStringVar4, gText_NoDecorations);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8126DA4);
    }
    else
    {
        gTasks[taskId].data[11] = 1;
        sCurDecorationCategory = DECORCAT_DESK;
        SecretBasePC_PrepMenuForSelectingStoredDecors(taskId);
    }
}

void SecretBasePC_Cancel(u8 taskId)
{
    sub_8126A58(0);
    if (!gUnknown_0203A17C.isPlayerRoom)
    {
        ScriptContext1_SetupScript(gUnknown_0823B4E8);
        DestroyTask(taskId);
    }
    else
    {
        ReshowPlayerPC(taskId);
    }
}

void sub_8126DA4(u8 taskId)
{
    sub_8126C08();
    gTasks[taskId].func = sub_8126B80;
}

void SecretBasePC_PrepMenuForSelectingStoredDecors(u8 taskId)
{
    LoadPalette(gUnknown_085A6BB0, 0xd0, 0x20);
    sub_8197434(0, 0);
    sub_8126A58(0);
    sub_8126DFC(taskId);
}

void sub_8126DFC(u8 taskId)
{
    u8 winIdx;

    winIdx = sub_81269D4(1);
    sub_8126E8C(taskId);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(winIdx, 9, sCurDecorationCategory);
    gTasks[taskId].func = sub_8127088;
}

void sub_8126E44(u8 taskId)
{
    FillWindowPixelBuffer(sDecorMenuWindowIndices[1], 0x11);
    sub_8126E8C(taskId);
    InitMenuInUpperLeftCornerPlaySoundWhenAPressed(sDecorMenuWindowIndices[1], 9, sCurDecorationCategory);
    gTasks[taskId].func = sub_8127088;
}

void sub_8126E8C(u8 taskId)
{
    s16 *data;
    u8 r5;
    bool8 r8;
    u8 i;
    bool8 fl;

    data = gTasks[taskId].data;
    r5 = sDecorMenuWindowIndices[1];
    fl = gUnknown_0203A17C.isPlayerRoom;
    r8 = FALSE;
    if (fl == TRUE && data[11] == 0)
    {
        r8 = TRUE;
    }
    for (i = 0; i < 8; i ++)
    {
        if (r8 == TRUE && i != DECORCAT_DOLL && i != DECORCAT_CUSHION)
        {
            sub_8126F68(r5, i, 8, i << 4, TRUE, 0xFF);
        }
        else
        {
            sub_8126F68(r5, i, 8, i << 4, FALSE, 0xFF);
        }
    }
    AddTextPrinterParameterized(r5, 1, gTasks[taskId].data[11] == 2 ? gText_Exit : gText_Cancel, 8, (i << 4) + 1, 0, 0);
    schedule_bg_copy_tilemap_to_vram(0);
}

void sub_8126F68(u8 winid, u8 decorCat, u8 x, u8 y, bool8 flag, u8 speed)
{
    u8 width;
    u8 *strbuf;

    width = x == 8 ? 0x68 : 0x60;
    y ++;
    sub_8127058(gStringVar4, flag);
    strbuf = StringLength(gStringVar4) + gStringVar4;
    StringCopy(strbuf, sDecorCatNames[decorCat]);
    AddTextPrinterParameterized(winid, 1, gStringVar4, x, y, speed, NULL);
    strbuf = ConvertIntToDecimalStringN(strbuf, CountDecorationCategoryN(decorCat), STR_CONV_MODE_RIGHT_ALIGN, 2);
    *strbuf++ = CHAR_SLASH;
    ConvertIntToDecimalStringN(strbuf, gDecorationInventories[decorCat].size, STR_CONV_MODE_RIGHT_ALIGN, 2);
    x = GetStringRightAlignXOffset(1, gStringVar4, width);
    AddTextPrinterParameterized(winid, 1, gStringVar4, x, y, speed, NULL);
}

void sub_8127058(u8 *str, bool8 flag)
{
    StringCopy(str, gText_Color161Shadow161);
    if (flag == TRUE)
    {
        str[2] = 0x04; // RED
        str[5] = 0x05; // LIGHT_RED
    }
    else
    {
        str[2] = 0x02; // DARK_GREY
        str[5] = 0x03; // LIGHT_GREY
    }
}

void sub_8127088(u8 taskId)
{
    s8 input;

    if (!gPaletteFade.active)
    {
        input = Menu_ProcessInput();
        switch (input)
        {
            case -1:
            case 8:
                PlaySE(SE_SELECT);
                sub_812719C(taskId);
                break;
            case -2:
                break;
            default:
                PlaySE(SE_SELECT);
                sCurDecorationCategory = input;
                sub_81270E8(taskId);
                break;
        }
    }
}

void sub_81270E8(u8 taskId)
{
    sCurDecorCatCount = CountDecorationCategoryN(sCurDecorationCategory);
    if (sCurDecorCatCount != 0)
    {
        CondenseDecorationCategoryN(sCurDecorationCategory);
        gCurDecorInventoryItems = gDecorationInventories[sCurDecorationCategory].items;
        IdentifyOwnedDecorationsCurrentlyInUse(taskId);
        sSecretBasePCSelectDecorPageNo = 0;
        sSecretBasePCSelectDecorLineNo = 0;
        gTasks[taskId].func = sub_8127620;
    }
    else
    {
        sub_8126A58(1);
        StringExpandPlaceholders(gStringVar4, gText_NoDecorations);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8127180);
    }
}

void sub_8127180(u8 taskId)
{
    sub_8197434(0, 0);
    sub_8126DFC(taskId);
}

void sub_812719C(u8 taskId)
{
    if (gTasks[taskId].data[11] != 2)
    {
        sub_81271CC(taskId);
    }
    else
    {
        sub_8127268(taskId);
    }
}

void sub_81271CC(u8 taskId)
{
    sub_8126A58(1);
    sub_8126A88();
    NewMenuHelpers_DrawDialogueFrame(0, 0);
    sub_8126C08();
    gTasks[taskId].func = sub_8126B80;
}

void sub_8127208(u8 taskId)
{
    LoadPalette(gUnknown_085A6BB0, 0xd0, 0x20);
    sub_8197434(0, 0);
    gTasks[taskId].data[11] = 2;
    sCurDecorationCategory = DECORCAT_DESK;
    sub_8126DFC(taskId);
}

void sub_8127250(u8 *dest, u8 decorCat)
{
    StringCopy(dest, sDecorCatNames[decorCat]);
}

void sub_8127268(u8 taskId)
{
    sub_8126A58(1);
    sub_8133E1C(taskId);
}

void sub_8127284(void)
{
    sDecorPCBuffer->unk_520 = sCurDecorCatCount + 1;
    if (sDecorPCBuffer->unk_520 > 8)
    {
        sDecorPCBuffer->unk_521 = 8;
    }
    else
    {
        sDecorPCBuffer->unk_521 = sDecorPCBuffer->unk_520;
    }
}

void sub_81272C8(void)
{
    sub_812225C(&sSecretBasePCSelectDecorPageNo, &sSecretBasePCSelectDecorLineNo, sDecorPCBuffer->unk_521, sDecorPCBuffer->unk_520);
}

void sub_81272F8(void)
{
    sub_8122298(&sSecretBasePCSelectDecorPageNo, &sSecretBasePCSelectDecorLineNo, sDecorPCBuffer->unk_521, sDecorPCBuffer->unk_520, 8);
}

void sub_8127330(u8 taskId)
{
    s16 *data;
    u16 i;

    data = gTasks[taskId].data;
    if ((sCurDecorationCategory < DECORCAT_DOLL || sCurDecorationCategory > DECORCAT_CUSHION) && gUnknown_0203A17C.isPlayerRoom == TRUE && data[11] == 0)
    {
        sub_8127058(gStringVar1, TRUE);
    }
    else
    {
        sub_8127058(gStringVar1, FALSE);
    }
    for (i = 0; i < sDecorPCBuffer->unk_520 - 1; i ++)
    {
        sub_8127454(sDecorPCBuffer->names[i], gCurDecorInventoryItems[i]);
        sDecorPCBuffer->items[i].name = sDecorPCBuffer->names[i];
        sDecorPCBuffer->items[i].id = i;
    }
    StringCopy(sDecorPCBuffer->names[i], gText_Cancel);
    sDecorPCBuffer->items[i].name = sDecorPCBuffer->names[i];
    sDecorPCBuffer->items[i].id = -2;
    gMultiuseListMenuTemplate = gUnknown_085A6BD0;
    gMultiuseListMenuTemplate.windowId = sDecorMenuWindowIndices[1];
    gMultiuseListMenuTemplate.totalItems = sDecorPCBuffer->unk_520;
    gMultiuseListMenuTemplate.items = sDecorPCBuffer->items;
    gMultiuseListMenuTemplate.maxShowed = sDecorPCBuffer->unk_521;
}

void sub_8127454(u8 *dest, u16 decorId)
{
    StringCopy(dest, gStringVar1);
    StringAppend(dest, gDecorations[decorId].name);
}

void sub_8127480(s32 a0, bool8 flag, struct ListMenu *menu)
{
    if (flag != TRUE)
    {
        PlaySE(SE_SELECT);
    }
    sub_8127744(a0);
}

void sub_81274A0(u8 a0, s32 a1, u8 a2)
{
    if (a1 != -2)
    {
        if (sub_81277BC(a1 + 1) == TRUE)
        {
            blit_move_info_icon(a0, 0x18, 0x5c, a2 + 2);
        }
        else if (sub_81277E8(a1 + 1) == TRUE)
        {
            blit_move_info_icon(a0, 0x19, 0x5c, a2 + 2);
        }
    }
}

void sub_8127500(void)
{
    if (sDecorPCBuffer->unk_522 == 0xFF)
    {
        sDecorPCBuffer->unk_522 = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, 0x3c, 0x0c, 0x94, sDecorPCBuffer->unk_520 - sDecorPCBuffer->unk_521, 0x6e, 0x6e, &sSecretBasePCSelectDecorPageNo);
    }
}

void sub_8127554(void)
{
    if (sDecorPCBuffer->unk_522 != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sDecorPCBuffer->unk_522);
        sDecorPCBuffer->unk_522 = 0xFF;
    }
}

void sub_8127580(u8 taskId)
{
    sub_81269D4(1);
    sub_812759C(taskId);
}

void sub_812759C(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    sub_81269D4(3);
    sub_8127718(sCurDecorationCategory);
    sDecorPCBuffer = calloc(1, sizeof(struct DecorPCBuffer));
    sDecorPCBuffer->unk_522 = 0xFF;
    sub_8127284();
    sub_81272C8();
    sub_81272F8();
    sub_8127330(taskId);
    data[13] = ListMenuInit(&gMultiuseListMenuTemplate, sSecretBasePCSelectDecorPageNo, sSecretBasePCSelectDecorLineNo);
    sub_8127500();
}

void sub_8127620(u8 taskId)
{
    sub_812759C(taskId);
    gTasks[taskId].func = sub_812764C;
}

void sub_812764C(u8 taskId)
{
    s16 *data;
    s32 input;

    data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        input = ListMenuHandleInputGetItemId(data[13]);
        ListMenuGetScrollAndRow(data[13], &sSecretBasePCSelectDecorPageNo, &sSecretBasePCSelectDecorLineNo);
        switch (input)
        {
            case -1:
                break;
            case -2:
                PlaySE(SE_SELECT);
                SecretBasePC_SelectedDecorActions[data[11]][1](taskId);
                break;
            default:
                PlaySE(SE_SELECT);
                gCurDecorationIndex = input;
                sub_8127554();
                DestroyListMenuTask(data[13], &sSecretBasePCSelectDecorPageNo, &sSecretBasePCSelectDecorLineNo);
                sub_8126A58(1);
                sub_81277A8();
                free(sDecorPCBuffer);
                SecretBasePC_SelectedDecorActions[data[11]][0](taskId);
                break;
        }
    }
}

void sub_8127718(u8 decorCat)
{
    sub_8126F68(sub_81269D4(2), decorCat, 0, 0, 0, 0);
}

void sub_8127744(u32 a0)
{
    u8 winidx;
    const u8 *txt;

    winidx = sDecorMenuWindowIndices[3];
    FillWindowPixelBuffer(winidx, 0x11);
    if (a0 >= sCurDecorCatCount)
    {
        txt = gText_GoBackPrevMenu;
    }
    else
    {
        txt = gDecorations[gCurDecorInventoryItems[a0]].description;
    }
    AddTextPrinterParameterized(winidx, 1, txt, 0, 1, 0, 0);
}

void sub_81277A8(void)
{
    sub_8126A58(3);
    sub_8126A58(2);
}

bool8 sub_81277BC(u8 idx)
{
    u8 i;

    for (i = 0; i < 16; i ++)
    {
        if (sSecretBaseItemsIndicesBuffer[i] == idx)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 sub_81277E8(u8 idx)
{
    u8 i;

    for (i = 0; i < 12; i ++)
    {
        if (sPlayerRoomItemsIndicesBuffer[i] == idx)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void IdentifyOwnedDecorationsCurrentlyInUseInternal(u8 taskId)
{
    u16 i;
    u16 j;
    u16 k;
    u16 cnt;

    cnt = 0;
    memset(sSecretBaseItemsIndicesBuffer, 0, 16);
    memset(sPlayerRoomItemsIndicesBuffer, 0, 12);
    for (i = 0; i < 16; i ++)
    {
        if (gSaveBlock1Ptr->secretBases[0].decorations[i] != DECOR_NONE)
        {
            for (j = 0; j < gDecorationInventories[sCurDecorationCategory].size; j ++)
            {
                if (gCurDecorInventoryItems[j] == gSaveBlock1Ptr->secretBases[0].decorations[i])
                {
                    for (k = 0; k < cnt && sSecretBaseItemsIndicesBuffer[k] != j + 1; k ++);
                    if (k == cnt)
                    {
                        sSecretBaseItemsIndicesBuffer[cnt] = j + 1;
                        cnt ++;
                        break;
                    }
                }
            }
        }
    }
    cnt = 0;
    for (i = 0; i < 12; i ++)
    {
        if (gSaveBlock1Ptr->playerRoomDecor[i] != DECOR_NONE)
        {
            for (j = 0; j < gDecorationInventories[sCurDecorationCategory].size; j ++)
            {
                if (gCurDecorInventoryItems[j] == gSaveBlock1Ptr->playerRoomDecor[i] && sub_81277BC(j + 1) != TRUE)
                {
                    for (k = 0; k < cnt && sPlayerRoomItemsIndicesBuffer[k] != j + 1; k ++);
                    if (k == cnt)
                    {
                        sPlayerRoomItemsIndicesBuffer[cnt] = j + 1;
                        cnt ++;
                        break;
                    }
                }
            }
        }
    }
}

void IdentifyOwnedDecorationsCurrentlyInUse(u8 taskId)
{
    IdentifyOwnedDecorationsCurrentlyInUseInternal(taskId);
}

bool8 IsSelectedDecorInThePC(void)
{
    u16 i;
    for (i = 0; i < 16; i ++)
    {
        if (sSecretBaseItemsIndicesBuffer[i] == sSecretBasePCSelectDecorPageNo + sSecretBasePCSelectDecorLineNo + 1)
        {
            return FALSE;
        }
        if (i < 12 && sPlayerRoomItemsIndicesBuffer[i] == sSecretBasePCSelectDecorPageNo + sSecretBasePCSelectDecorLineNo + 1)
        {
            return FALSE;
        }
    }
    return TRUE;
}

void sub_8127A14(u8 taskId)
{
    sub_81269D4(1);
    sub_8127620(taskId);
}

void sub_8127A30(u8 taskId)
{
    sub_8197434(0, 0);
    gTasks[taskId].func = sub_8127A14;
}

void sub_8127A5C(u8 taskId)
{
    if (gMain.newKeys & (A_BUTTON | B_BUTTON))
    {
        sub_8197434(0, 0);
        sub_81269D4(1);
        sub_8127620(taskId);
    }
}

void sub_8127A8C(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    sub_8127554();
    sub_81277A8();
    DestroyListMenuTask(data[13], NULL, NULL);
    free(sDecorPCBuffer);
    sub_8126E44(taskId);
}

void sub_8127ACC(u8 taskId)
{
    gTasks[taskId].data[3] = gSaveBlock1Ptr->pos.x;
    gTasks[taskId].data[4] = gSaveBlock1Ptr->pos.y;
    PlayerGetDestCoords(&gTasks[taskId].data[0], &gTasks[taskId].data[1]);
}

void sub_8127B04(u8 taskId)
{
    DrawWholeMapView();
    Overworld_SetWarpDestination(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1, gTasks[taskId].data[3], gTasks[taskId].data[4]);
    WarpIntoMap();
}

u16 sub_8127B54(u8 decor, u8 a1)
{
    u16 resp;

    resp = -1;
    switch (decor)
    {
        case DECOR_STAND:
            resp = gUnknown_085A72E4[a1] << 12;
            return resp;
        case DECOR_SLIDE:
            resp = gUnknown_085A72EC[a1] << 12;
            return resp;
        default:
            return resp;
    }
}

void sub_8127B90(u16 mapX, u16 mapY, u8 decWidth, u8 decHeight, u16 decor)
{
    u16 i;
    u16 j;
    u16 behavior;
    u16 flags;
    u16 v0;
    u16 v1;
    s16 decLeft;
    s16 decBottom;

    for (i = 0; i < decHeight; i ++)
    {
        decBottom = mapY - decHeight + 1 + i;
        for (j = 0; j < decWidth; j ++)
        {
            decLeft = mapX + j;
            behavior = GetBehaviorByMetatileId(0x200 + gDecorations[decor].tiles[i * decWidth + j]);
            if (MetatileBehavior_IsSecretBaseImpassable(behavior) == TRUE || (gDecorations[decor].permission != DECORPERM_PASS_FLOOR && (behavior >> 12)))
            {
                flags = 0xc00;
            }
            else
            {
                flags = 0x000;
            }
            if (gDecorations[decor].permission != DECORPERM_NA_WALL && MetatileBehavior_IsSecretBaseNorthWall(MapGridGetMetatileBehaviorAt(decLeft, decBottom)) == TRUE)
            {
                v0 = 1;
            }
            else
            {
                v0 = 0;
            }
            v1 = sub_8127B54(gDecorations[decor].id, i * decWidth + j);
            if (v1 != 0xFFFF)
            {
                MapGridSetMetatileEntryAt(decLeft, decBottom, (gDecorations[decor].tiles[i * decWidth + j] + (0x200 | v0)) | flags | v1);
            }
            else
            {
                MapGridSetMetatileIdAt(decLeft, decBottom, (gDecorations[decor].tiles[i * decWidth + j] + (0x200 | v0)) | flags);
            }
        }
    }
}

void sub_8127D38(u16 mapX, u16 mapY, u16 decor)
{
    switch (gDecorations[decor].shape)
    {
        case DECORSHAPE_1x1:
            sub_8127B90(mapX, mapY, 1, 1, decor);
            break;
        case DECORSHAPE_2x1:
            sub_8127B90(mapX, mapY, 2, 1, decor);
            break;
        case DECORSHAPE_3x1: // unused
            sub_8127B90(mapX, mapY, 3, 1, decor);
            break;
        case DECORSHAPE_4x2:
            sub_8127B90(mapX, mapY, 4, 2, decor);
            break;
        case DECORSHAPE_2x2:
            sub_8127B90(mapX, mapY, 2, 2, decor);
            break;
        case DECORSHAPE_1x2:
            sub_8127B90(mapX, mapY, 1, 2, decor);
            break;
        case DECORSHAPE_1x3: // unused
            sub_8127B90(mapX, mapY, 1, 3, decor);
            break;
        case DECORSHAPE_2x4:
            sub_8127B90(mapX, mapY, 2, 4, decor);
            break;
        case DECORSHAPE_3x3:
            sub_8127B90(mapX, mapY, 3, 3, decor);
            break;
        case DECORSHAPE_3x2:
            sub_8127B90(mapX, mapY, 3, 2, decor);
            break;
    }
}

void sub_8127E18(void)
{
    u8 i;
    u8 j;

    for (i = 0; i < 14; i ++)
    {
        if (FlagGet(0xAE + i) == TRUE)
        {
            FlagClear(0xAE + i);
            for (j = 0; j < gMapHeader.events->eventObjectCount; j ++)
            {
                if (gMapHeader.events->eventObjects[j].flagId == 0xAE + i)
                {
                    break;
                }
            }
            VarSet(0x3F20 + gMapHeader.events->eventObjects[j].graphicsId, sPlaceDecorationGraphicsDataBuffer.decoration->tiles[0]);
            gSpecialVar_0x8005 = gMapHeader.events->eventObjects[j].localId;
            gSpecialVar_0x8006 = sCurDecorMapX;
            gSpecialVar_0x8007 = sCurDecorMapY;
            show_sprite(gSpecialVar_0x8005, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            sub_808EBA8(gSpecialVar_0x8005, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, gSpecialVar_0x8006, gSpecialVar_0x8007);
            sub_808F254(gSpecialVar_0x8005, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            break;
        }
    }
}

bool8 sub_8127F38(void)
{
    u16 i;

    for (i = 0; i < gUnknown_0203A17C.size; i ++)
    {
        if (gUnknown_0203A17C.items[i] == DECOR_NONE)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_8127F68(u8 taskId)
{
    if (gUnknown_0203A17C.isPlayerRoom == TRUE && sCurDecorationCategory != DECORCAT_DOLL && sCurDecorationCategory != DECORCAT_CUSHION)
    {
        StringExpandPlaceholders(gStringVar4, gText_CantPlaceInRoom);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8127A5C);
    }
    else if (IsSelectedDecorInThePC() == TRUE)
    {
        if (sub_8127F38() == TRUE)
        {
            FadeScreen(1, 0);
            gTasks[taskId].data[2] = 0;
            gTasks[taskId].func = sub_8128060;
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gUnknown_0203A17C.size, STR_CONV_MODE_RIGHT_ALIGN, 2);
            if (gUnknown_0203A17C.isPlayerRoom == FALSE) {
                StringExpandPlaceholders(gStringVar4, gText_NoMoreDecorations);
            }
            else
            {
                StringExpandPlaceholders(gStringVar4, gText_NoMoreDecorations2);
            }
            DisplayItemMessageOnField(taskId, gStringVar4, sub_8127A5C);
        }
    }
    else
    {
        StringExpandPlaceholders(gStringVar4, gText_InUseAlready);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8127A5C);
    }
}

void sub_8128060(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_8127ACC(taskId);
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            gPaletteFade.bufferTransferDisabled = TRUE;
            ConfigureCameraObjectForPlacingDecoration(&sPlaceDecorationGraphicsDataBuffer, gCurDecorInventoryItems[gCurDecorationIndex]);
            sub_812826C(taskId);
            SetUpPlacingDecorationPlayerAvatar(taskId, &sPlaceDecorationGraphicsDataBuffer);
            pal_fill_black();
            gPaletteFade.bufferTransferDisabled = FALSE;
            gTasks[taskId].data[2] = 2;
            break;
        case 2:
            if (IsWeatherNotFadingIn() == TRUE)
            {
                gTasks[taskId].data[12] = 0;
                sub_8128FD8(taskId);
            }
            break;
    }
}

void ConfigureCameraObjectForPlacingDecoration(struct PlaceDecorationGraphicsDataBuffer *data, u8 decor)
{
    sDecor_CameraSpriteObjectIdx1 = gSprites[gFieldCamera.spriteId].data[0];
    gFieldCamera.spriteId = gpu_pal_decompress_alloc_tag_and_upload(data, decor);
    gSprites[gFieldCamera.spriteId].oam.priority = 1;
    gSprites[gFieldCamera.spriteId].callback = sub_81292D0;
    gSprites[gFieldCamera.spriteId].pos1.x = gUnknown_085A7250[data->decoration->shape].x;
    gSprites[gFieldCamera.spriteId].pos1.y = gUnknown_085A7250[data->decoration->shape].y;
}

void SetUpPlacingDecorationPlayerAvatar(u8 taskId, struct PlaceDecorationGraphicsDataBuffer *data)
{
    u8 v0;

    v0 = 16 * (u8)gTasks[taskId].data[5] + gUnknown_085A7250[data->decoration->shape].x - 8 * ((u8)gTasks[taskId].data[5] - 1);
    if (data->decoration->shape == DECORSHAPE_3x1 || data->decoration->shape == DECORSHAPE_3x3 || data->decoration->shape == DECORSHAPE_3x2)
    {
        v0 -= 8;
    }
    if (gSaveBlock2Ptr->playerGender == MALE)
    {
        sDecor_CameraSpriteObjectIdx2 = AddPseudoEventObject(0xC1, SpriteCallbackDummy, v0, 0x48, 0);
    }
    else
    {
        sDecor_CameraSpriteObjectIdx2 = AddPseudoEventObject(0xC2, SpriteCallbackDummy, v0, 0x48, 0);
    }
    gSprites[sDecor_CameraSpriteObjectIdx2].oam.priority = 1;
    DestroySprite(&gSprites[sDecor_CameraSpriteObjectIdx1]);
    sDecor_CameraSpriteObjectIdx1 = gFieldCamera.spriteId;
}

void sub_812826C(u8 taskId)
{
    switch (gDecorations[gCurDecorInventoryItems[gCurDecorationIndex]].shape)
    {
        case DECORSHAPE_1x1:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 1;
            break;
        case DECORSHAPE_2x1:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 1;
            break;
        case DECORSHAPE_3x1:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 1;
            break;
        case DECORSHAPE_4x2:
            gTasks[taskId].data[5] = 4;
            gTasks[taskId].data[6] = 2;
            break;
        case DECORSHAPE_2x2:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 2;
            break;
        case DECORSHAPE_1x2:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 2;
            break;
        case DECORSHAPE_1x3:
            gTasks[taskId].data[5] = 1;
            gTasks[taskId].data[6] = 3;
            gTasks[taskId].data[1]++;
            break;
        case DECORSHAPE_2x4:
            gTasks[taskId].data[5] = 2;
            gTasks[taskId].data[6] = 4;
            break;
        case DECORSHAPE_3x3:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 3;
            break;
        case DECORSHAPE_3x2:
            gTasks[taskId].data[5] = 3;
            gTasks[taskId].data[6] = 2;
            break;
    }
}

void sub_81283BC(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    gSprites[sDecor_CameraSpriteObjectIdx1].data[7] = 1;
    gSprites[sDecor_CameraSpriteObjectIdx2].data[7] = 1;
    sub_8128DE0();
    sub_8128950(taskId);
}

void sub_8128414(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    gSprites[sDecor_CameraSpriteObjectIdx1].data[7] = 1;
    gSprites[sDecor_CameraSpriteObjectIdx2].data[7] = 1;
    sub_8128DE0();
    StringExpandPlaceholders(gStringVar4, gText_CancelDecorating);
    DisplayItemMessageOnField(taskId, gStringVar4, sub_8128B80);
}

bool8 sub_8128484(u8 behaviorAt, u16 behaviorBy)
{
    if (MetatileBehavior_IsBlockDecoration(behaviorAt) != TRUE || behaviorBy != 0)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 sub_81284AC(u8 taskId, s16 x, s16 y, u16 decor)
{
    if (x == gTasks[taskId].data[3] + 7 && y == gTasks[taskId].data[4] + 7 && decor != DECOR_NONE)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 sub_81284F4(u16 behaviorAt, const struct Decoration *decoration)
{
    if (MetatileBehavior_IsBlockDecoration(behaviorAt) != TRUE)
    {
        if (decoration->id == DECOR_SOLID_BOARD && MetatileBehavior_IsSecretBaseHole(behaviorAt) == TRUE)
        {
            return TRUE;
        }
        if (MetatileBehavior_IsNormal(behaviorAt))
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 sub_812853C(u8 taskId, const struct Decoration *decoration)
{
    u8 i;
    u8 j;
    u8 behaviorAt;
    u16 behaviorBy;
    u8 mapY;
    u8 mapX;
    s16 curY;
    s16 curX;
    mapY = gTasks[taskId].data[6];
    mapX = gTasks[taskId].data[5];

    switch (decoration->permission)
    {
        case DECORPERM_SOLID_FLOOR:
        case DECORPERM_PASS_FLOOR:
            for (i=0; i<mapY; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                    behaviorBy = GetBehaviorByMetatileId(0x200 + decoration->tiles[(mapY - 1 - i) * mapX + j]) & 0xf000;
                    if (!sub_81284F4(behaviorAt, decoration))
                    {
                        return FALSE;
                    }
                    if (!sub_81284AC(taskId, curX, curY, behaviorBy))
                    {
                        return FALSE;
                    }
                    behaviorAt = GetEventObjectIdByXYZ(curX, curY, 0);
                    if (behaviorAt != 0 && behaviorAt != 16)
                    {
                        return FALSE;
                    }
                }
            }
            break;
        case DECORPERM_BEHIND_FLOOR:
            for (i=0; i<mapY-1; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                    behaviorBy = GetBehaviorByMetatileId(0x200 + decoration->tiles[(mapY - 1 - i) * mapX + j]) & 0xf000;
                    if (!MetatileBehavior_IsNormal(behaviorAt) && !sub_8128484(behaviorAt, behaviorBy))
                    {
                        return FALSE;
                    }
                    if (!sub_81284AC(taskId, curX, curY, behaviorBy))
                    {
                        return FALSE;
                    }
                    if (GetEventObjectIdByXYZ(curX, curY, 0) != 16)
                    {
                        return FALSE;
                    }
                }
            }
            curY = gTasks[taskId].data[1] - mapY + 1;
            for (j=0; j<mapX; j++)
            {
                curX = gTasks[taskId].data[0] + j;
                behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                behaviorBy = GetBehaviorByMetatileId(0x200 + decoration->tiles[j]) & 0xf000;
                if (!MetatileBehavior_IsNormal(behaviorAt) && !MetatileBehavior_IsSecretBaseNorthWall(behaviorAt))
                {
                    return FALSE;
                }
                if (!sub_81284AC(taskId, curX, curY, behaviorBy))
                {
                    return FALSE;
                }
                behaviorAt = GetEventObjectIdByXYZ(curX, curY, 0);
                if (behaviorAt != 0 && behaviorAt != 16)
                {
                    return FALSE;
                }
            }
            break;
        case DECORPERM_NA_WALL:
            for (i=0; i<mapY; i++)
            {
                curY = gTasks[taskId].data[1] - i;
                for (j=0; j<mapX; j++)
                {
                    curX = gTasks[taskId].data[0] + j;
                    if (!MetatileBehavior_IsSecretBaseNorthWall(MapGridGetMetatileBehaviorAt(curX, curY)))
                    {
                        return FALSE;
                    }
                    if (MapGridGetMetatileIdAt(curX, curY + 1) == 0x28c)
                    {
                        return FALSE;
                    }
                }
            }
            break;
        case DECORPERM_SOLID_MAT:
            curY = gTasks[taskId].data[1];
            for (j=0; j<mapX; j++)
            {
                curX = gTasks[taskId].data[0] + j;
                behaviorAt = MapGridGetMetatileBehaviorAt(curX, curY);
                if (decoration->shape == DECORSHAPE_1x2)
                {
                    if (!MetatileBehavior_IsLargeMatCenter(behaviorAt))
                    {
                        return FALSE;
                    }
                }
                else if (!MetatileBehavior_IsSecretBaseLargeMatEdge(behaviorAt))
                {
                    if (!MetatileBehavior_IsLargeMatCenter(behaviorAt))
                    {
                        return FALSE;
                    }
                }
                if (GetEventObjectIdByXYZ(curX, curY, 0) != 16)
                {
                    return FALSE;
                }
            }
            break;
    }
    return TRUE;
}

void sub_8128950(u8 taskId)
{
    if (sub_812853C(taskId, &gDecorations[gCurDecorInventoryItems[gCurDecorationIndex]]) == TRUE)
    {
        StringExpandPlaceholders(gStringVar4, gText_PlaceItHere);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_81289D0);
    }
    else
    {
        PlaySE(SE_HAZURE);
        StringExpandPlaceholders(gStringVar4, gText_CantBePlacedHere);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8129020);
    }
}

void sub_81289D0(u8 taskId)
{
    DisplayYesNoMenu();
    sub_8121F68(taskId, &gUnknown_085A72C4);
}

void sub_81289F0(u8 taskId)
{
    sub_8197434(0, 0);
    sub_8128AAC(taskId);
    if (gDecorations[gCurDecorInventoryItems[gCurDecorationIndex]].permission != DECORPERM_SOLID_MAT)
    {
        sub_8127D38(gTasks[taskId].data[0], gTasks[taskId].data[1], gCurDecorInventoryItems[gCurDecorationIndex]);
    }
    else
    {
        sCurDecorMapX = gTasks[taskId].data[0] - 7;
        sCurDecorMapY = gTasks[taskId].data[1] - 7;
        ScriptContext1_SetupScript(EventScript_275D1F);
    }
    gSprites[sDecor_CameraSpriteObjectIdx1].pos1.y += 2;
    if (gMapHeader.regionMapSectionId == MAPSEC_SECRET_BASE)
    {
        TV_PutSecretBaseVisitOnTheAir();
    }
    sub_8128BBC(taskId);
}

void sub_8128AAC(u8 taskId)
{
    u16 i;

    for (i = 0; i < gUnknown_0203A17C.size; i ++)
    {
        if (gUnknown_0203A17C.items[i] == DECOR_NONE)
        {
            gUnknown_0203A17C.items[i] = gCurDecorInventoryItems[gCurDecorationIndex];
            gUnknown_0203A17C.pos[i] = ((gTasks[taskId].data[0] - 7) << 4) + (gTasks[taskId].data[1] - 7);
            break;
        }
    }
    if (!gUnknown_0203A17C.isPlayerRoom)
    {
        for (i = 0; i < 16; i ++)
        {
            if (sSecretBaseItemsIndicesBuffer[i] == 0)
            {
                sSecretBaseItemsIndicesBuffer[i] = gCurDecorationIndex + 1;
                break;
            }
        }
    }
    else
    {
        for (i = 0; i < 12; i ++)
        {
            if (sPlayerRoomItemsIndicesBuffer[i] == 0)
            {
                sPlayerRoomItemsIndicesBuffer[i] = gCurDecorationIndex + 1;
                break;
            }
        }
    }
}

void sub_8128B80(u8 taskId)
{
    DisplayYesNoMenu();
    sub_8121F68(taskId, &gUnknown_085A72CC);
}

void sub_8128BA0(u8 taskId)
{
    sub_8197434(0, 0);
    sub_8128BBC(taskId);
}

void sub_8128BBC(u8 taskId)
{
    FadeScreen(1, 0);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = c1_overworld_prev_quest;
}

void c1_overworld_prev_quest(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            ScriptContext2_Enable();
            if (!gPaletteFade.active)
            {
                sub_8127B04(taskId);
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            sub_812A3C8();
            FreeSpritePaletteByTag(OVERWORLD_PLACE_DECOR_SELECTOR_PAL_TAG);
            gFieldCallback = sub_8128CD4;
            SetMainCallback2(CB2_ReturnToField);
            DestroyTask(taskId);
            break;
    }
}

void sub_8128C64(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[2])
    {
        case 0:
            sub_80E9578();
            data[2] ++;
            break;
        case 1:
            ScriptContext1_SetupScript(EventScript_275D0C);
            data[2] ++;
            break;
        case 2:
            ScriptContext2_Enable();
            data[2] ++;
            break;
        case 3:
            if (IsWeatherNotFadingIn() == TRUE)
            {
                gTasks[taskId].func = sub_812764C;
            }
            break;
    }
}

void sub_8128CD4(void)
{
    u8 taskId;

    ScriptContext2_Enable();
    pal_fill_black();
    taskId = CreateTask(sub_8128C64, 8);
    sub_8127580(taskId);
    gTasks[taskId].data[2] = 0;
}

bool8 sub_8128D10(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    if (sDecorationLastDirectionMoved == DIR_SOUTH && data[1] - data[6] - 6 < 0)
    {
        data[1] ++;
        return FALSE;
    }
    if (sDecorationLastDirectionMoved == DIR_NORTH && data[1] - 7 >= gMapHeader.mapLayout->height)
    {
        data[1] --;
        return FALSE;
    }
    if (sDecorationLastDirectionMoved == DIR_WEST && data[0] - 7 < 0)
    {
        data[0] ++;
        return FALSE;
    }
    if (sDecorationLastDirectionMoved == DIR_EAST && data[0] + data[5] - 8 >= gMapHeader.mapLayout->width)
    {
        data[0] --;
        return FALSE;
    }
    return TRUE;
}

bool8 sub_8128DB4(void)
{
    u16 heldKeys;

    heldKeys = gMain.heldKeys & 0x0F0;
    if (heldKeys != DPAD_UP && heldKeys != DPAD_DOWN && heldKeys != DPAD_LEFT && heldKeys != DPAD_RIGHT)
    {
        return FALSE;
    }
    return TRUE;
}

void sub_8128DE0(void)
{
    sDecorationLastDirectionMoved = 0;
    gSprites[sDecor_CameraSpriteObjectIdx1].data[2] = 0;
    gSprites[sDecor_CameraSpriteObjectIdx1].data[3] = 0;
}

void sub_8128E18(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    if (!gSprites[sDecor_CameraSpriteObjectIdx1].data[4])
    {
        if (data[10] == 1)
        {
            gUnknown_085A72D4[data[12]].yesFunc(taskId);
            return;
        } else if (data[10] == 2)
        {
            gUnknown_085A72D4[data[12]].noFunc(taskId);
            return;
        }
        if ((gMain.heldKeys & 0x0F0) == DPAD_UP)
        {
            sDecorationLastDirectionMoved = DIR_SOUTH;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[2] =  0;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[3] = -2;
            data[1]--;
        }
        if ((gMain.heldKeys & 0x0F0) == DPAD_DOWN)
        {
            sDecorationLastDirectionMoved = DIR_NORTH;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[2] =  0;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[3] =  2;
            data[1]++;
        }
        if ((gMain.heldKeys & 0x0F0) == DPAD_LEFT)
        {
            sDecorationLastDirectionMoved = DIR_WEST;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[2] = -2;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[3] =  0;
            data[0]--;
        }
        if ((gMain.heldKeys & 0x0F0) == DPAD_RIGHT)
        {
            sDecorationLastDirectionMoved = DIR_EAST;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[2] =  2;
            gSprites[sDecor_CameraSpriteObjectIdx1].data[3] =  0;
            data[0]++;
        }
        if (!sub_8128DB4() || !sub_8128D10(taskId))
        {
            sub_8128DE0();
        }
    }
    if (sDecorationLastDirectionMoved)
    {
        gSprites[sDecor_CameraSpriteObjectIdx1].data[4]++;
        gSprites[sDecor_CameraSpriteObjectIdx1].data[4] &= 7;
    }
    if (!data[10])
    {
        if (gMain.newKeys & A_BUTTON)
        {
            data[10] = A_BUTTON;
        }
        if (gMain.newKeys & B_BUTTON)
        {
            data[10] = B_BUTTON;
        }
    }
}

void sub_8128FD8(u8 taskId)
{
    sub_8197434(0, 1);
    gSprites[sDecor_CameraSpriteObjectIdx1].data[7] = 0;
    gTasks[taskId].data[10] = 0;
    gTasks[taskId].func = sub_8128E18;
}

void sub_8129020(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
    {
        sub_8128FD8(taskId);
    }
}

void sub_8129048(struct PlaceDecorationGraphicsDataBuffer *data)
{
    CpuFill16(0, data, sizeof(*data));
}

void sub_8129068(u16 *dest, u16 pal)
{
    CpuFastCopy(&((u16 *)gTilesetPointer_SecretBase->palettes)[pal << 4], dest, 32);
}

void sub_8129088(u8 *dest, u16 tile)
{
    u8 buffer[32];
    u16 mode;
    u16 i;

    mode = tile >> 10;
    if (tile != 0)
    {
        tile &= 0x03FF;
    }
    CpuFastCopy(&((u8 *)gTilesetPointer_SecretBase->tiles)[tile << 5], buffer, 32);
    switch (mode)
    {
        case 0:
            CpuFastCopy(buffer, dest, 32);
            break;
        case 1:
            for (i = 0; i < 8; i ++)
            {
                dest[4 * i] = (buffer[4 * (i + 1) - 1] >> 4) + ((buffer[4 * (i + 1) - 1] & 0x0F) << 4);
                dest[4 * i + 1] = (buffer[4 * (i + 1) - 2] >> 4) + ((buffer[4 * (i + 1) - 2] & 0x0F) << 4);
                dest[4 * i + 2] = (buffer[4 * (i + 1) - 3] >> 4) + ((buffer[4 * (i + 1) - 3] & 0x0F) << 4);
                dest[4 * i + 3] = (buffer[4 * (i + 1) - 4] >> 4) + ((buffer[4 * (i + 1) - 4] & 0x0F) << 4);
            }
            break;
        case 2:
            for (i = 0; i < 8; i ++)
            {
                dest[4 * i] = buffer[4 * (7 - i)];
                dest[4 * i + 1] = buffer[4 * (7 - i) + 1];
                dest[4 * i + 2] = buffer[4 * (7 - i) + 2];
                dest[4 * i + 3] = buffer[4 * (7 - i) + 3];
            }
            break;
        case 3:
            for (i = 0; i < 32; i ++)
            {
                dest[i] = (buffer[31 - i] >> 4) + ((buffer[31 - i] & 0x0F) << 4);
            }
            break;
    }
}

void sub_81291A4(struct PlaceDecorationGraphicsDataBuffer *data)
{
    u16 i;
    for (i = 0; i < 64; i ++)
    {
        sub_8129088(&data->image[i * 32], data->tiles[i]);
    }
}

u16 sub_81291CC(u16 tile)
{
    return ((u16 *)gTilesetPointer_SecretBaseRedCave->metatiles)[tile] & 0xFFF;
}

void sub_81291E8(struct PlaceDecorationGraphicsDataBuffer *data)
{
    u8 i;
    u8 shape;

    shape = data->decoration->shape;
    for (i = 0; i < gUnknown_085A71B0[shape].size; i ++)
    {
        data->tiles[gUnknown_085A71B0[shape].tiles[i]] = sub_81291CC(data->decoration->tiles[gUnknown_085A71B0[shape].y[i]] * 8 + gUnknown_085A71B0[shape].x[i]);
    }
}

void SetDecorSelectionBoxOamAttributes(u8 decorShape)
{
    sDecorSelectorOam.y = 0;
    sDecorSelectorOam.affineMode = ST_OAM_AFFINE_OFF;
    sDecorSelectorOam.objMode = ST_OAM_OBJ_NORMAL;
    sDecorSelectorOam.mosaic = 0;
    sDecorSelectorOam.bpp = ST_OAM_4BPP;
    sDecorSelectorOam.shape = gUnknown_085A7250[decorShape].shape;
    sDecorSelectorOam.x = 0;
    sDecorSelectorOam.matrixNum = 0;
    sDecorSelectorOam.size = gUnknown_085A7250[decorShape].size;
    sDecorSelectorOam.tileNum = 0;
    sDecorSelectorOam.priority = 0;
    sDecorSelectorOam.paletteNum = 0;
}

void sub_81292D0(struct Sprite *sprite)
{
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
    sprite->data[6] = 0;
    sprite->data[7] = 0;
    sprite->callback = sub_81292E8;
}

void sub_81292E8(struct Sprite *sprite)
{
    if (sprite->data[7] == 0)
    {
        if (sprite->data[6] < 15)
        {
            sprite->invisible = FALSE;
        }
        else
        {
            sprite->invisible = TRUE;
        }
        sprite->data[6] ++;
        sprite->data[6] &= 0x1F;
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

u8 gpu_pal_decompress_alloc_tag_and_upload(struct PlaceDecorationGraphicsDataBuffer *data, u8 decor)
{
    sub_8129048(data);
    data->decoration = &gDecorations[decor];
    if (data->decoration->permission == DECORPERM_SOLID_MAT)
    {
        return AddPseudoEventObject(data->decoration->tiles[0], SpriteCallbackDummy, 0, 0, 1);
    }
    FreeSpritePaletteByTag(OVERWORLD_PLACE_DECOR_SELECTOR_PAL_TAG);
    sub_81291E8(data);
    SetDecorSelectionBoxOamAttributes(data->decoration->shape);
    sub_81291A4(data);
    sub_8129068(data->palette, ((u16 *)gTilesetPointer_SecretBaseRedCave->metatiles)[(data->decoration->tiles[0] * 8) + 7] >> 12);
    LoadSpritePalette(&gUnknown_085A72BC);
    return CreateSprite(&sDecorSelectorSpriteTemplate, 0, 0, 0);
}

u8 AddDecorationIconObjectFromIconTable(u16 tilesTag, u16 paletteTag, u8 decor)
{
    struct SpriteSheet sheet;
    struct CompressedSpritePalette palette;
    struct SpriteTemplate *template;
    u8 spriteId;

    if (!AllocItemIconTemporaryBuffers())
    {
        return MAX_SPRITES;
    }
    LZDecompressWram(GetDecorationIconPicOrPalette(decor, 0), gItemIconDecompressionBuffer);
    CopyItemIconPicTo4x4Buffer(gItemIconDecompressionBuffer, gItemIcon4x4Buffer);
    sheet.data = gItemIcon4x4Buffer;
    sheet.size = 0x200;
    sheet.tag = tilesTag;
    LoadSpriteSheet(&sheet);
    palette.data = GetDecorationIconPicOrPalette(decor, 1);
    palette.tag = paletteTag;
    LoadCompressedObjectPalette(&palette);
    template = malloc(sizeof(struct SpriteTemplate));
    *template = gItemIconSpriteTemplate;
    template->tileTag = tilesTag;
    template->paletteTag = paletteTag;
    spriteId = CreateSprite(template, 0, 0, 0);
    FreeItemIconTemporaryBuffers();
    free(template);
    return spriteId;
}

const u32 *GetDecorationIconPicOrPalette(u16 decor, u8 mode)
{
    if (decor > 120)
    {
        decor = DECOR_NONE;
    }
    return gUnknown_085A6BE8[decor][mode];
}

u8 AddDecorationIconObjectFromEventObject(u16 tilesTag, u16 paletteTag, u8 decor)
{
    u8 spriteId;
    struct SpriteSheet sheet;
    struct SpritePalette palette;
    struct SpriteTemplate *template;

    sub_8129048(&sPlaceDecorationGraphicsDataBuffer);
    sPlaceDecorationGraphicsDataBuffer.decoration = &gDecorations[decor];
    if (sPlaceDecorationGraphicsDataBuffer.decoration->permission != DECORPERM_SOLID_MAT)
    {
        sub_81291E8(&sPlaceDecorationGraphicsDataBuffer);
        SetDecorSelectionBoxOamAttributes(sPlaceDecorationGraphicsDataBuffer.decoration->shape);
        sub_81291A4(&sPlaceDecorationGraphicsDataBuffer);
        sub_8129068(sPlaceDecorationGraphicsDataBuffer.palette, ((u16 *)gTilesetPointer_SecretBaseRedCave->metatiles)[(sPlaceDecorationGraphicsDataBuffer.decoration->tiles[0] * 8) + 7] >> 12);
        sheet.data = sPlaceDecorationGraphicsDataBuffer.image;
        sheet.size = gUnknown_085A72F4[sPlaceDecorationGraphicsDataBuffer.decoration->shape] << 5;
        sheet.tag = tilesTag;
        LoadSpriteSheet(&sheet);
        palette.data = sPlaceDecorationGraphicsDataBuffer.palette;
        palette.tag = paletteTag;
        LoadSpritePalette(&palette);
        template = Alloc(sizeof(struct SpriteTemplate));
        *template = sDecorWhilePlacingSpriteTemplate;
        template->tileTag = tilesTag;
        template->paletteTag = paletteTag;
        spriteId = CreateSprite(template, 0, 0, 0);
        free(template);
    }
    else
    {
        spriteId = AddPseudoEventObject(sPlaceDecorationGraphicsDataBuffer.decoration->tiles[0], SpriteCallbackDummy, 0, 0, 1);
    }
    return spriteId;
}

u8 AddDecorationIconObject(u8 decor, s16 x, s16 y, u8 priority, u16 tilesTag, u16 paletteTag)
{
    u8 spriteId;

    if (decor > 120)
    {
        spriteId = AddDecorationIconObjectFromIconTable(tilesTag, paletteTag, DECOR_NONE);
        if (spriteId == MAX_SPRITES)
        {
            return MAX_SPRITES;
        }
        gSprites[spriteId].pos2.x = x + 4;
        gSprites[spriteId].pos2.y = y + 4;
    }
    else if (gUnknown_085A6BE8[decor][0] == NULL)
    {
        spriteId = AddDecorationIconObjectFromEventObject(tilesTag, paletteTag, decor);
        if (spriteId == MAX_SPRITES)
        {
            return MAX_SPRITES;
        }
        gSprites[spriteId].pos2.x = x;
        if (decor == DECOR_SILVER_SHIELD || decor == DECOR_GOLD_SHIELD)
        {
            gSprites[spriteId].pos2.y = y - 4;
        }
        else
        {
            gSprites[spriteId].pos2.y = y;
        }
    }
    else
    {
        spriteId = AddDecorationIconObjectFromIconTable(tilesTag, paletteTag, decor);
        if (spriteId == MAX_SPRITES)
        {
            return MAX_SPRITES;
        }
        gSprites[spriteId].pos2.x = x + 4;
        gSprites[spriteId].pos2.y = y + 4;
    }
    gSprites[spriteId].oam.priority = priority;
    return spriteId;
}

void sub_81296EC(u8 idx)
{
    gUnknown_0203A17C.items[idx] = 0;
    gUnknown_0203A17C.pos[idx] = 0;
}

void sub_8129708(void)
{
    u16 i;

    gSpecialVar_0x8005 = 0;
    gSpecialVar_Result = 0;
    if (gSpecialVar_0x8004 == sCurDecorSelectedInRearrangement)
    {
        gSpecialVar_Result = 1;
    }
    else if (gDecorations[gUnknown_0203A17C.items[sDecorRearrangementDataBuffer[gSpecialVar_0x8004].idx]].permission == DECORPERM_SOLID_MAT)
    {
        gSpecialVar_0x8005 = sDecorRearrangementDataBuffer[gSpecialVar_0x8004].flagId;
        sub_81296EC(sDecorRearrangementDataBuffer[gSpecialVar_0x8004].idx);
        for (i = 0; i < gMapHeader.events->eventObjectCount; i ++)
        {
            if (gMapHeader.events->eventObjects[i].flagId == gSpecialVar_0x8005)
            {
                gSpecialVar_0x8006 = gMapHeader.events->eventObjects[i].localId;
                break;
            }
        }
    }
}

void sub_81297AC(void)
{
    u8 i;

    for (i = 0; i < gMapHeader.events->eventObjectCount; i ++)
    {
        if (gMapHeader.events->eventObjects[i].flagId == gSpecialVar_0x8004)
        {
            gSpecialVar_0x8005 = gMapHeader.events->eventObjects[i].localId;
            break;
        }
    }
}

void sub_81297F8(void)
{
    u8 i;
    u8 y;
    u8 x;
    int posX;
    int posY;
    u8 perm;

    for (i = 0; i < sCurDecorSelectedInRearrangement; i ++)
    {
        perm = gDecorations[gUnknown_0203A17C.items[sDecorRearrangementDataBuffer[i].idx]].permission;
        posX = gUnknown_0203A17C.pos[sDecorRearrangementDataBuffer[i].idx] >> 4;
        posY = gUnknown_0203A17C.pos[sDecorRearrangementDataBuffer[i].idx] & 0x0F;
        if (perm != DECORPERM_SOLID_MAT)
        {
            for (y = 0; y < sDecorRearrangementDataBuffer[i].height; y ++)
            {
                for (x = 0; x < sDecorRearrangementDataBuffer[i].width; x ++)
                {
                    MapGridSetMetatileEntryAt(posX + 7 + x, posY + 7 - y, gMapHeader.mapLayout->map[posX + x + gMapHeader.mapLayout->width * (posY - y)] | 0x3000);
                }
            }
            sub_81296EC(sDecorRearrangementDataBuffer[i].idx);
        }
    }
}

void sub_81298EC(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            sub_81297F8();
            gTasks[taskId].data[2] = 1;
            break;
        case 1:
            if (!gPaletteFade.active) {
                DrawWholeMapView();
                ScriptContext1_SetupScript(EventScript_275D2E);
                sub_8197434(0, 1);
                gTasks[taskId].data[2] = 2;
            }
            break;
        case 2:
            ScriptContext2_Enable();
            IdentifyOwnedDecorationsCurrentlyInUseInternal(taskId);
            pal_fill_black();
            gTasks[taskId].data[2] = 3;
            break;
        case 3:
            if (IsWeatherNotFadingIn() == TRUE)
            {
                StringExpandPlaceholders(gStringVar4, gText_DecorationReturnedToPC);
                DisplayItemMessageOnField(taskId, gStringVar4, sub_8129D64);
                if (gMapHeader.regionMapSectionId == MAPSEC_SECRET_BASE)
                {
                    TV_PutSecretBaseVisitOnTheAir();
                }
            }
            break;
    }
}


bool8 sub_81299AC(u8 taskId)
{
    u16 i;

    for (i = 0; i < gUnknown_0203A17C.size; i ++)
    {
        if (gUnknown_0203A17C.items[i] != DECOR_NONE)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void SetUpPuttingAwayDecorationPlayerAvatar(void)
{
    GetPlayerFacingDirection();
    sDecor_CameraSpriteObjectIdx1 = gSprites[gFieldCamera.spriteId].data[0];
    sub_812A39C();
    gFieldCamera.spriteId = CreateSprite(&gUnknown_085A7404, 0x78, 0x50, 0);
    if (gSaveBlock2Ptr->playerGender == MALE)
    {
        sDecor_CameraSpriteObjectIdx2 = AddPseudoEventObject(0xC1, SpriteCallbackDummy, 0x88, 0x48, 0);
    }
    else
    {
        sDecor_CameraSpriteObjectIdx2 = AddPseudoEventObject(0xC2, SpriteCallbackDummy, 0x88, 0x48, 0);
    }
    gSprites[sDecor_CameraSpriteObjectIdx2].oam.priority = 1;
    DestroySprite(&gSprites[sDecor_CameraSpriteObjectIdx1]);
    sDecor_CameraSpriteObjectIdx1 = gFieldCamera.spriteId;
    gSprites[sDecor_CameraSpriteObjectIdx1].oam.priority = 1;
}

void sub_8129ABC(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_8127ACC(taskId);
                data[2] = 1;
                data[6] = 1;
                data[5] = 1;
            }
            break;
        case 1:
            SetUpPuttingAwayDecorationPlayerAvatar();
            pal_fill_black();
            data[2] = 2;
            break;
        case 2:
            if (IsWeatherNotFadingIn() == TRUE)
            {
                data[12] = 1;
                sub_8129B34(taskId);
            }
            break;
    }
}

void sub_8129B34(u8 taskId)
{
    sub_8197434(0, 1);
    gSprites[sDecor_CameraSpriteObjectIdx1].data[7] = 0;
    gSprites[sDecor_CameraSpriteObjectIdx1].invisible = FALSE;
    gSprites[sDecor_CameraSpriteObjectIdx1].callback = sub_812A36C;
    gSprites[sDecor_CameraSpriteObjectIdx2].pos1.x = 0x88;
    gSprites[sDecor_CameraSpriteObjectIdx2].pos1.y = 0x48;
    gTasks[taskId].data[10] = 0;
    gTasks[taskId].func = sub_8128E18;
}

void sub_8129BCC(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    sub_8128DE0();
    sub_8129C74(taskId);
}

void sub_8129BF8(u8 taskId)
{
    gTasks[taskId].data[10] = 0;
    sub_8128DE0();
    gSprites[sDecor_CameraSpriteObjectIdx1].invisible = FALSE;
    gSprites[sDecor_CameraSpriteObjectIdx1].callback = SpriteCallbackDummy;
    StringExpandPlaceholders(gStringVar4, gText_StopPuttingAwayDecorations);
    DisplayItemMessageOnField(taskId, gStringVar4, sub_812A1F0);
}

void sub_8129C74(u8 taskId)
{
    s16 *data;
    u8 behavior;

    sub_812A0E8(taskId);
    if (sCurDecorSelectedInRearrangement != 0)
    {
        StringExpandPlaceholders(gStringVar4, gText_ReturnDecorationToPC);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_812A1A0);
    }
    else
    {
        data = gTasks[taskId].data;
        behavior = MapGridGetMetatileBehaviorAt(data[0], data[1]);
        if (MetatileBehavior_IsSecretBasePC(behavior) == TRUE || MetatileBehavior_IsPlayerRoomPCOn(behavior) == TRUE)
        {
            gSprites[sDecor_CameraSpriteObjectIdx1].invisible = FALSE;
            gSprites[sDecor_CameraSpriteObjectIdx1].callback = SpriteCallbackDummy;
            StringExpandPlaceholders(gStringVar4, gText_StopPuttingAwayDecorations);
            DisplayItemMessageOnField(taskId, gStringVar4, sub_812A1F0);
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, gText_NoDecorationHere);
            DisplayItemMessageOnField(taskId, gStringVar4, sub_8129D64);
        }
    }
}

void sub_8129D64(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON || gMain.newKeys & B_BUTTON)
    {
        sub_8129B34(taskId);
    }
}

void sub_8129D8C(u8 decor, struct DecorRearrangementDataBuffer *data)
{
    if (gDecorations[decor].shape == DECORSHAPE_1x1)
    {
        data->width = 1;
        data->height = 1;
    } else if (gDecorations[decor].shape == DECORSHAPE_2x1)
    {
        data->width = 2;
        data->height = 1;
    } else if (gDecorations[decor].shape == DECORSHAPE_3x1)
    {
        data->width = 3;
        data->height = 1;
    } else if (gDecorations[decor].shape == DECORSHAPE_4x2)
    {
        data->width = 4;
        data->height = 2;
    } else if (gDecorations[decor].shape == DECORSHAPE_2x2)
    {
        data->width = 2;
        data->height = 2;
    } else if (gDecorations[decor].shape == DECORSHAPE_1x2)
    {
        data->width = 1;
        data->height = 2;
    } else if (gDecorations[decor].shape == DECORSHAPE_1x3)
    {
        data->width = 1;
        data->height = 3;
    } else if (gDecorations[decor].shape == DECORSHAPE_2x4)
    {
        data->width = 2;
        data->height = 4;
    } else if (gDecorations[decor].shape == DECORSHAPE_3x3)
    {
        data->width = 3;
        data->height = 3;
    } else if (gDecorations[decor].shape == DECORSHAPE_3x2)
    {
        data->width = 3;
        data->height = 2;
    }
}

void sub_8129E0C(u8 x, u8 y)
{
    gSprites[sDecor_CameraSpriteObjectIdx1].invisible = TRUE;
    gSprites[sDecor_CameraSpriteObjectIdx1].callback = SpriteCallbackDummy;
    gSprites[sDecor_CameraSpriteObjectIdx2].pos1.x = (x << 4) + 0x88;
    gSprites[sDecor_CameraSpriteObjectIdx2].pos1.y = (y << 4) + 0x48;
}

bool8 sub_8129E74(u8 taskId, u8 idx, struct DecorRearrangementDataBuffer *data)
{
    u8 x;
    u8 y;
    u8 xOff;
    u8 yOff;
    u8 ht;

    x = gTasks[taskId].data[0] - 7;
    y = gTasks[taskId].data[1] - 7;
    xOff = gUnknown_0203A17C.pos[idx] >> 4;
    yOff = gUnknown_0203A17C.pos[idx] & 0x0F;
    ht = data->height;
    if (gUnknown_0203A17C.items[idx] == DECOR_SAND_ORNAMENT && MapGridGetMetatileIdAt(xOff + 7, yOff + 7) == 0x28C)
    {
        ht --;
    }
    if (x >= xOff && x < xOff + data->width && y > yOff - ht && y <= yOff)
    {
        sub_8129E0C(data->width - (x - xOff + 1), yOff - y);
        return TRUE;
    }
    return FALSE;
}

void sub_8129F20(void)
{
    u8 xOff;
    u8 yOff;
    u16 i;

    xOff = gUnknown_0203A17C.pos[sDecorRearrangementDataBuffer[sCurDecorSelectedInRearrangement].idx] >> 4;
    yOff = gUnknown_0203A17C.pos[sDecorRearrangementDataBuffer[sCurDecorSelectedInRearrangement].idx] & 0x0F;
    for (i = 0; i < 0x40; i ++)
    {
        if (gSaveBlock1Ptr->eventObjectTemplates[i].x == xOff && gSaveBlock1Ptr->eventObjectTemplates[i].y == yOff && !FlagGet(gSaveBlock1Ptr->eventObjectTemplates[i].flagId))
        {
            sDecorRearrangementDataBuffer[sCurDecorSelectedInRearrangement].flagId = gSaveBlock1Ptr->eventObjectTemplates[i].flagId;
            break;
        }
    }
}

bool8 sub_8129FC8(u8 taskId)
{
    u16 i;

    for (i = 0; i < gUnknown_0203A17C.size; i ++)
    {
        if (gUnknown_0203A17C.items[i] != 0)
        {
            if (gDecorations[gUnknown_0203A17C.items[i]].permission == DECORPERM_SOLID_MAT)
            {
                sub_8129D8C(gUnknown_0203A17C.items[i], sDecorRearrangementDataBuffer);
                if (sub_8129E74(taskId, i, sDecorRearrangementDataBuffer) == TRUE)
                {
                    sDecorRearrangementDataBuffer->idx = i;
                    sub_8129F20();
                    sCurDecorSelectedInRearrangement = 1;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void sub_812A040(u8 left, u8 top, u8 right, u8 bottom)
{
    u8 i;
    u8 xOff;
    u8 yOff;
    u8 decorIdx;

    for (i = 0; i < gUnknown_0203A17C.size; i ++)
    {
        decorIdx = gUnknown_0203A17C.items[i];
        xOff = gUnknown_0203A17C.pos[i] >> 4;
        yOff = gUnknown_0203A17C.pos[i] & 0x0F;
        if (decorIdx != 0 && gDecorations[decorIdx].permission == DECORPERM_SOLID_MAT && left <= xOff && top <= yOff && right >= xOff && bottom >= yOff)
        {
            sDecorRearrangementDataBuffer[sCurDecorSelectedInRearrangement].idx = i;
            sub_8129F20();
            sCurDecorSelectedInRearrangement++;
        }
    }
}

void sub_812A0E8(u8 taskId)
{
    u8 i;
    u8 xOff;
    u8 yOff;
    u8 var1;
    u32 var2;

    sCurDecorSelectedInRearrangement = 0;
    if (sub_8129FC8(taskId) != TRUE)
    {
        for (i = 0; i < gUnknown_0203A17C.size; i++)
        {
            var1 = gUnknown_0203A17C.items[i];
            if (var1 != DECOR_NONE)
            {
                sub_8129D8C(var1, &sDecorRearrangementDataBuffer[0]);
                if (sub_8129E74(taskId, i, &sDecorRearrangementDataBuffer[0]) == TRUE)
                {
                    sDecorRearrangementDataBuffer[0].idx = i;
                    sCurDecorSelectedInRearrangement++;
                    break;
                }
            }
        }
        if (sCurDecorSelectedInRearrangement != 0)
        {
            xOff = gUnknown_0203A17C.pos[sDecorRearrangementDataBuffer[0].idx] >> 4;
            yOff = gUnknown_0203A17C.pos[sDecorRearrangementDataBuffer[0].idx] & 0x0F;
            var1 = yOff - sDecorRearrangementDataBuffer[0].height + 1;
            var2 = sDecorRearrangementDataBuffer[0].width + xOff - 1;

            sub_812A040(xOff, var1, var2, yOff);
        }
    }
}

void sub_812A1A0(u8 taskId)
{
    DisplayYesNoMenu();
    sub_8121F68(taskId, &gUnknown_085A7348);
}

void sub_812A1C0(u8 taskId)
{
    FadeScreen(1, 0);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = sub_81298EC;
}

void sub_812A1F0(u8 taskId)
{
    DisplayYesNoMenu();
    sub_8121F68(taskId, &gUnknown_085A7350);
}

void sub_812A210(u8 taskId)
{
    sub_8197434(0, 0);
    sub_812A22C(taskId);
}

void sub_812A22C(u8 taskId)
{
    FadeScreen(1, 0);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = sub_812A25C;
}

void sub_812A25C(u8 taskId)
{
    switch (gTasks[taskId].data[2])
    {
        case 0:
            if (!gPaletteFade.active)
            {
                sub_8127B04(taskId);
                gTasks[taskId].data[2] = 1;
            }
            break;
        case 1:
            sub_812A3C8();
            gFieldCallback = sub_812A334;
            SetMainCallback2(CB2_ReturnToField);
            DestroyTask(taskId);
            break;
    }
}

void sub_812A2C4(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    switch (data[2])
    {
        case 0:
            sub_80E9578();
            data[2] ++;
            break;
        case 1:
            ScriptContext1_SetupScript(EventScript_275D0C);
            data[2] ++;
            break;
        case 2:
            ScriptContext2_Enable();
            data[2] ++;
            break;
        case 3:
            if (IsWeatherNotFadingIn() == TRUE)
            {
                gTasks[taskId].func = sub_8126B80;
            }
            break;
    }
}

void sub_812A334(void)
{
    u8 taskId;

    pal_fill_black();
    NewMenuHelpers_DrawDialogueFrame(0, 1);
    sub_8126ABC();
    taskId = CreateTask(sub_812A2C4, 8);
    gTasks[taskId].data[2] = 0;
}

void sub_812A36C(struct Sprite *sprite)
{
    sprite->data[0] ++;
    sprite->data[0] &= 0x1F;
    if (sprite->data[0] > 15)
    {
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

void sub_812A39C(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
    {
        LoadSpritePalette(&gUnknown_085A73D8);
    }
    else
    {
        LoadSpritePalette(&gUnknown_085A73E0);
    }
}

void sub_812A3C8(void)
{
    FreeSpritePaletteByTag(OVERWORLD_PLACE_DECOR_PLAYER_PAL_TAG);
}

void sub_812A3D4(u8 taskId)
{
    if (IsSelectedDecorInThePC() == TRUE)
    {
        StringCopy(gStringVar1, gDecorations[gCurDecorInventoryItems[gCurDecorationIndex]].name);
        StringExpandPlaceholders(gStringVar4, gText_DecorationWillBeDiscarded);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_812A458);
    }
    else
    {
        StringExpandPlaceholders(gStringVar4, gText_CantThrowAwayInUse);
        DisplayItemMessageOnField(taskId, gStringVar4, sub_8127A5C);
    }
}

void sub_812A458(u8 taskId)
{
    DisplayYesNoMenu();
    sub_8121F68(taskId, &gUnknown_085A741C);
}

void sub_812A478(u8 taskId)
{
    gCurDecorInventoryItems[gCurDecorationIndex] = DECOR_NONE;
    sCurDecorCatCount = CountDecorationCategoryN(sCurDecorationCategory);
    CondenseDecorationCategoryN(sCurDecorationCategory);
    IdentifyOwnedDecorationsCurrentlyInUseInternal(taskId);
    StringExpandPlaceholders(gStringVar4, gText_DecorationThrownAway);
    DisplayItemMessageOnField(taskId, gStringVar4, sub_8127A5C);
}
