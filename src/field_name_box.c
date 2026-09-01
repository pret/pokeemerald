#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "window.h"
#include "text.h"
#include "string_util.h"
#include "international_string_util.h"
#include "script_menu.h"
#include "field_message_box.h"
#include "graphics.h"
#include "script.h"
#include "field_name_box.h"
#include "event_data.h"
#include "match_call.h"
#include "malloc.h"
#include "constants/speaker_names.h"
#include "data/speaker_names.h"

static EWRAM_INIT u8 sNameboxWindowId = WINDOW_NONE;
EWRAM_DATA const u8 *gSpeakerName = NULL;

static const u32 sNameBoxDefaultGfx[] = INCGFX_U32("graphics/text_window/name_box.png", ".4bpp");
static const u32 sNameBoxPokenavGfx[] = INCGFX_U32("graphics/pokenav/name_box.png", ".4bpp");

static void DestroyNameboxFrame(void);
static void WindowFunc_DrawNamebox(u32, u32, u32, u32, u32, u32, u32);
static void WindowFunc_ClearNamebox(u8, u8, u8, u8, u8, u8);

void PrepareNamebox(u32 tileNum)
{
    u8 *strbuf = AllocZeroed(32 * sizeof(u8));
    if (FlagGet(OW_FLAG_SUPPRESS_NAME_BOX) || !gSpeakerName || !strbuf)
    {
        // Re-check again in case anything but !strbuf is TRUE.
        if (strbuf)
            Free(strbuf);

        DestroyNamebox();
        RedrawDialogueFrame();
        return;
    }

    StringExpandPlaceholders(strbuf, gSpeakerName);

    u32 fontId = FONT_SMALL;
    u32 winWidth = OW_NAME_BOX_DEFAULT_WIDTH;

    if (OW_NAME_BOX_USE_DYNAMIC_WIDTH)
    {
        winWidth = ConvertPixelWidthToTileWidth(GetStringWidth(fontId, strbuf, -1));
        if (winWidth > OW_NAME_BOX_DEFAULT_WIDTH)
            winWidth = OW_NAME_BOX_DEFAULT_WIDTH;
    }

    if (sNameboxWindowId != WINDOW_NONE)
    {
        DestroyNameboxFrame();
        RedrawDialogueFrame();
    }

    bool32 matchCall = IsMatchCallTaskActive();

    struct WindowTemplate template =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 13,
        .width = winWidth,
        .height = OW_NAME_BOX_DEFAULT_HEIGHT,
        .paletteNum = matchCall ? 14 : DLG_WINDOW_PALETTE_NUM,
        .baseBlock = tileNum,
    };

    sNameboxWindowId = AddWindow(&template);
    FillNamebox();

    u8 colors[3] = {TEXT_COLOR_TRANSPARENT, OW_NAME_BOX_FOREGROUND_COLOR, OW_NAME_BOX_SHADOW_COLOR};
    int strX = GetStringCenterAlignXOffset(fontId, strbuf, (winWidth * 8));
    if (matchCall)
    {
        colors[1] = 1;
        colors[2] = 0;
    }

    union TextColor savedTextColors = SaveTextColors();
    AddTextPrinterParameterized3(sNameboxWindowId, fontId, strX, 0, colors, TEXT_SKIP_DRAW, strbuf);
    RestoreTextColors(savedTextColors);
    Free(strbuf);
}

u32 GetNameboxWindowId(void)
{
    return sNameboxWindowId;
}

void ResetNameboxData(void)
{
    sNameboxWindowId = WINDOW_NONE;
    gSpeakerName = NULL;
}

static void DestroyNameboxFrame(void)
{
    ClearNamebox(sNameboxWindowId, FALSE);
    ClearWindowTilemap(sNameboxWindowId);
    RemoveWindow(sNameboxWindowId);
}

void DestroyNamebox(void)
{
    if (sNameboxWindowId == WINDOW_NONE)
        return;

    DestroyNameboxFrame();
    ResetNameboxData();
}

u32 GetNameboxWidth(void)
{
    return gWindows[sNameboxWindowId].window.width;
}

static const u32 *GetNameboxGraphics(void)
{
    if (IsMatchCallTaskActive())
        return sNameBoxPokenavGfx;
    else
        return sNameBoxDefaultGfx;
}

void FillNamebox(void)
{
    u32 winSize = GetNameboxWidth();
    const u32 *gfx = GetNameboxGraphics();

    for (u32 i = 0; i < winSize; i++)
    {
        #define TILE(x) (8 * x)
        CopyToWindowPixelBuffer(sNameboxWindowId, &gfx[TILE(1)], TILE_SIZE_4BPP, i);
        CopyToWindowPixelBuffer(sNameboxWindowId, &gfx[TILE(4)], TILE_SIZE_4BPP, i + winSize);
        #undef TILE
    }
}

void DrawNamebox(u32 windowId, u32 tileNum, bool32 copyToVram)
{
    // manual instead of using CallWindowFunction for extra tileNum param
    struct WindowTemplate *w = &gWindows[windowId].window;
    u32 size = TILE_OFFSET_4BPP(NAME_BOX_BASE_TILES_TOTAL);

    LoadBgTiles(GetWindowAttribute(sNameboxWindowId, WINDOW_BG), GetNameboxGraphics(), size, tileNum);
    WindowFunc_DrawNamebox(w->bg, w->tilemapLeft, w->tilemapTop, w->width, w->height, w->paletteNum, tileNum);
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

void ClearNamebox(u32 windowId, bool32 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_ClearNamebox);
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void WindowFunc_DrawNamebox(u32 bg, u32 L, u32 T, u32 w, u32 h, u32 p, u32 tileNum)
{
    // left-most
    FillBgTilemapBufferRect(bg, tileNum,     L - 1, T,     1, 1, p);
    FillBgTilemapBufferRect(bg, tileNum + 3, L - 1, T + 1, 1, 1, p);

    // right-most
    FillBgTilemapBufferRect(bg, tileNum + 2, L + w, T,     1, 1, p);
    FillBgTilemapBufferRect(bg, tileNum + 5, L + w, T + 1, 1, 1, p);
}

static void WindowFunc_ClearNamebox(u8 bg, u8 L, u8 T, u8 w, u8 h, u8 p)
{
    FillBgTilemapBufferRect(bg, 0, L - 1, T, w + 2, h, 0); // palette doesn't matter
}

void SetSpeaker(struct ScriptContext *ctx)
{
    u32 arg = ScriptReadWord(ctx);
    const u8 *speaker = NULL;

    if (arg < SP_NAME_COUNT)
        speaker = gSpeakerNamesTable[arg];
    else if (arg >= ROM_START && arg < ROM_END)
        speaker = (const u8 *)arg;

    gSpeakerName = speaker;
}

// useful for other context e.g. match call
void TrySpawnAndShowNamebox(const u8 *speaker, u32 tileNum)
{
    gSpeakerName = speaker;
    if (sNameboxWindowId != WINDOW_NONE && gSpeakerName == NULL)
    {
        ClearNamebox(sNameboxWindowId, TRUE);
        DestroyNamebox();
        RedrawDialogueFrame();
        return;
    }
    else if (gSpeakerName == NULL)
    {
        return;
    }

    PrepareNamebox(tileNum);
    DrawNamebox(sNameboxWindowId, tileNum - NAME_BOX_BASE_TILES_TOTAL, TRUE);
}

bool32 IsSpeakerBuffered(const u8 *str)
{
    if (str[0] == EXT_CTRL_CODE_BEGIN
     && str[1] == EXT_CTRL_CODE_SPEAKER
     && str[2] >= SP_NAME_NONE)
    {
        gSpeakerName = gSpeakerNamesTable[str[2]];
    }

    u32 res = FALSE;
    if (gSpeakerName)
        res = TRUE;

    return res;
}
