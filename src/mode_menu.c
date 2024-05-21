#include "gba/types.h"
#include "gba/defines.h"
#include "global.h"
#include "main.h"
#include "bg.h"
#include "text_window.h"
#include "window.h"
#include "characters.h"
#include "palette.h"
#include "task.h"
#include "overworld.h"
#include "malloc.h"
#include "gba/macro.h"
#include "menu_helpers.h"
#include "menu.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "data.h"
#include "pokedex.h"
#include "gpu_regs.h"
#include "mode_menu.h"

// This code is based on Ghoulslash's excellent UI tutorial:
// https://www.pokecommunity.com/showpost.php?p=10441093

/*
 * Glossary of acronyms and abbreviations -- because sometimes I go crazy with these
 *
 * BG = background
 * GF = Game Freak
 * DMA = Direct Memory Access
 * GBA = Game Boy Advance
 */

/*
 * Some general resources you should bookmark:
 * TONC GBA tutorial: https://www.coranac.com/tonc/text/toc.htm
 * Computer systems course with focus on GBA: https://ianfinlayson.net/class/cpsc305/
 * GBATEK reference docs: https://problemkaputt.de/gbatek.htm
 * Copetti GBA Architecture: https://www.copetti.org/writings/consoles/game-boy-advance/
 */

/*
 * The meat of the menu code lives in this file. The tutorial comments assume the following:
 *
 * 1) You understand the basics of GBA graphics i.e. the multiple BG layers and how they are controlled, the various
 *    GBA graphics modes, the basics of hardware sprites, etc
 *
 * 2) You are familiar with the concept of tiles (tilesets) vs tilemaps. These are two distinct concepts and you need to
 *    understand them to understand any UI code.
 *
 * 3) You are familiar with the concept of a charblock and a screenblock, which are crucial to proper VRAM layout.
 *
 * 4) You understand the basics of the pokeemerald Callback and Task systems, which structure the menu's control flow.
 *
 * 5) You have a basic grasp of the GBA memory layout -- you know the difference between VRAM, EWRAM, IWRAM, etc.
 *
 * 6) Some of the UI code makes use of DMA (Direct Memory Access). This assumes you are familiar with what DMA is and
 *    how it works on the GBA. Also note that a lot of the GF library code does not perform DMA directly, rather it
 *    schedules a DMA copy to occur during the next VBlank using a circle buffer of DMA transfer request objects. See
 *    the code in `gflib/dma3_manager.{h,c} for more details.
 *
 * If you are unsure about any of these concepts, please check the following resources:
 *
 * GBA graphics basics:
 *     + https://www.coranac.com/tonc/text/video.htm
 *     + https://ianfinlayson.net/class/cpsc305/notes/06-gba1
 *
 * Tiles, tilemaps, charblocks, screenblocks:
 *     + https://www.coranac.com/tonc/text/objbg.htm
 *     + https://www.coranac.com/tonc/text/regbg.htm
 *     + https://ianfinlayson.net/class/cpsc305/notes/13-tiles <--- this is a highly recommended resource
 *
 * Callbacks and Tasks:
 *     + https://github.com/pret/pokeemerald/wiki/Overview%E2%88%B6-The-Game-Loop
 *     + https://github.com/pret/pokeemerald/wiki/Overview%E2%88%B6-The-Task-System
 *
 * GBA Memory Layout:
 *     + https://www.coranac.com/tonc/text/hardware.htm#sec-memory
 *     + https://problemkaputt.de/gbatek.htm#gbamemorymap
 *
 * DMA:
 *     + https://www.coranac.com/tonc/text/dma.htm
 *     + https://ianfinlayson.net/class/cpsc305/notes/14-memory
 */

/*
 * Basic Code Flow
 * A summary of the basic control flow path for this code. This may help aid in understanding which functions get
 * called, and when.
 *
 * 1) Any code that would like to launch this menu must include `sample_ui.h' so it has the right hook-in, specifically
 *    `Task_OpenModeMenu_Simple'. It must then setup the transition (however is relevant based on its context) and set
 *    the active task to `Task_OpenModeMenu_Simple'. In our case, `start_menu.c' is the caller of this task.
 *
 * 2) `Task_OpenModeMenu_Simple' waits for any active fades to finish, then it calls our init code in `ModeMenu_Init'
 *    which changes the gMainCallback2 to our `ModeMenu_SetupCB'.
 *
 * 3) `ModeMenu_SetupCB' runs each frame, bit-by-bit getting our menu initialized. Once initialization has finished,
 *    this callback:
 *       1) Sets up a new task `Task_ModeMenuWaitFadeIn' which waits until we fade back in before hotswapping itself for
 *          `Task_ModeMenuMainInput' which reads input and updates the menu state.
 *       2) Starts a palette fade to bring the screen from black back to regular colors
 *       3) Sets our VBlank callback to `ModeMenu_VBlankCB' (which is called every VBlank as part of the VBlank
 *          interrupt service routine). This callback transfers our OAM and palette buffers into VRAM, among other
 *          things
 *       4) Sets gMainCallback2 to our menu's main callback `ModeMenu_MainCB', which does the standard processing of
 *          tasks, animating of sprites, etc.
 *
 * 4) We have reached our standard menu state. Every frame `ModeMenu_MainCB' runs, which calls `Task_ModeMenuMainInput`
 *    to get input from the user and update menu state and backing graphics buffers. `ModeMenu_MainCB' also updates
 *    other important gamestate. Then, when VBlank occurs, our `ModeMenu_VBlankCB' copies palettes and OAM into VRAM
 *    before pending DMA transfers fire and copy any screen graphics updates into VRAM.
 */

/*
 * Various state for the UI -- we'll allocate this on the heap since none of it needs to be preserved after we exit the
 * menu.
 */
struct ModeMenuState
{
    // Save the callback to run when we exit: i.e. where do we want to go after closing the menu
    MainCallback savedCallback;
    // We will use this later to track some loading state
    u8 loadState;
    // Store the current dex mode, we'll have a mode that shows dex number/description as well as a few others
    u8 mode;
    // The sprite ID of the current mon icon, we need this so we can destroy the sprite when the user scrolls
    u8 monIconSpriteId;
    // The dex num of the currently displayed mon
    u16 monIconDexNum;
};

// GF window system passes window IDs around, so define this to avoid using magic numbers everywhere
enum WindowIds
{
    WIN_UI_HINTS,
    WIN_MON_INFO
};

/*
 * Both of these can be pointers that live in EWRAM -- allocating the actual data on the heap will save precious WRAM
 * space since none of this data matters outside the context of our menu. We can easily cleanup when we're done. It's
 * worth noting that every time the game re-loads into the overworld, the heap gets nuked from orbit. However, it is
 * still good practice to clean up after oneself, so we will be sure to free everything before exiting.
 */
static EWRAM_DATA struct ModeMenuState *sModeMenuState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

/*
 * Defines and read-only data for on-screen dex.
 */
#define MON_ICON_X     39
#define MON_ICON_Y     36
static const u8 sRegionNameKanto[] =  _("Kanto");
/*
 * Dex mode defines. Info mode shows dex number and description. Stats and Other modes will show placeholder text, but
 * you can change this to show whatever info you want.
 */
#define MODE_INFO   0
#define MODE_STATS  1
#define MODE_OTHER  2
static const u8 sModeNameInfo[] =  _("Info");
static const u8 sModeNameStats[] =  _("Stats");
static const u8 sModeNameOther[] =  _("Other");
static const u8 *const sModeNames[3] = {
    [MODE_INFO]   = sModeNameInfo,
    [MODE_STATS]  = sModeNameStats,
    [MODE_OTHER]  = sModeNameOther
};

/*
 * BgTemplates are just a nice way to setup various BG attributes without having to deal with manually writing to the
 * various display and BG control registers that the Game Boy actually cares about. GF handles that for you with lots of
 * clever BG management code. All you have to do is tell it what you want. If you want to see the gory details of BG
 * control registers, check out this resource and the code in `gflib/bg.{h,c}':
 * https://problemkaputt.de/gbatek.htm#lcdiobgcontrol
 */
static const struct BgTemplate sModeMenuBgTemplates[] =
{
    {
        // We will use BG0 for the text windows
        .bg = 0,
        // Use charblock 0 for BG0 tiles
        .charBaseIndex = 0,
        // Use screenblock 31 for BG0 tilemap
        // (It has become customary to put tilemaps in the final few screenblocks)
        .mapBaseIndex = 31,
        // Draw the text windows on top of the main BG
        .priority = 1
    },
    {
        // The Main BG: we will use BG1 for the menu graphics
        .bg = 1,
        // Use charblock 3 for BG1 tiles
        .charBaseIndex = 3,
        // Use screenblock 30 for BG1 tilemap
        .mapBaseIndex = 30,
        // Draw this BG below BG0, since we want text drawn on top of the menu graphics
        .priority = 2
    }
    /*
     * I encourage you to open the mGBA Tools/Game State Views/View Tiles menu to see how this above code gets
     * translated into an actual VRAM layout. Quiz yourself by changing the charBaseIndex and mapBaseIndex and guessing
     * what will happen before looking at the Tile Viewer.
     */
};

/*
 * Like the above BgTemplates, WindowTemplates are just an easy way to setup some software windows (which are provided
 * by the GameFreak library). GF's window system is used primarily for drawing dynamic text on the background layers.
 * Their inner workings are quite confusing, so hopefully this tutorial clears some things up.
 *
 * One big thing to note is that GF windows use a technique called tile rendering to draw text. With normal BG
 * rendering, you have a pre-drawn tileset, and then you dynamically update the tilemap, based on gamestate, to change
 * what's shown on screen. With tile rendering, this process is basically flipped on its head. GF tile-rendered windows
 * instead write a preset increasing sequence of tile indexes into the parts of the BG tilemap that represent a given
 * window. Then, to draw text, it dynamically draws to a backing pixel buffer (the `u8 *tileData' in the Window struct)
 * that is copied into VRAM just like regular tile data. This effectively allows the text rendering code to treat the
 * window BG as a pseudo-framebuffer, as if we were in a simple bitmap mode like Mode 3. This technique is advantageous
 * because it allows for maximum flexibility with font sizing and spacing. You aren't locked into 8x8 tiles for each
 * character.
 *
 * For more information about tile rendering and text rendering sytems in general, check out the TTE TONC tutorial and
 * the tile rendering section specifically. You can also consult Game Freak's code in `gflib/window.c' and
 * `gflib/text.c'.
 * https://www.coranac.com/tonc/text/tte.htm#sec-chr
 */
static const struct WindowTemplate sModeMenuWindowTemplates[] =
{
    [WIN_UI_HINTS] =
    {
        // This window will print on BG0
        .bg = 0,
        /*
         * The tilemap position for this window, if we imagine the tilemap as a 2D matrix. These positions refer to
         * tiles, so to get the actual pixel position you should multiply by 8.
         */
        .tilemapLeft = 14,
        .tilemapTop = 0,
        /*
         * The tilemap dimensions for this window, if we imagine the tilemap as a 2D matrix. These dimensions refer to
         * tiles, so to get the actual pixel dimensions you should multiply by 8.
         */
        .width = 16,
        .height = 7,
        /*
         * Use BG palette 15 for all tilemap entries that fall within this window. Tilemap entries store the palette for
         * the given tile in bits F, E, D, C (top four) of the entry. We'll need to load the right palette into BG
         * palette slot 15.
         */
        .paletteNum = 15,

        /*
         * This next parameter is where things get interesting. The window base block is the tile offset, relative to
         * the window BG's charblock, where the window's graphics live in VRAM. Since we might be cramming multiple
         * windows into the same BG, we need to tell the engine where exactly to place each window's graphics, lest they
         * overlap.
         *
         * Typically, you want each subsequent window's baseBlock to be at least:
         *     previousBaseBlock + (prevWindowWidth * prevWindowHeight)
         * which makes sense if you think about it. (Try changing the second window's baseBlock to see how important
         * this parameter is!)
         *
         * And another thing -- why is this value set to 1 and not 0? You will understand this better once you finish
         * going through the tutorial code, but I will put the explanation here:
         *
         * It's because this window lives on BG0. If we set the baseBlock to 0, then the text writing code will draw the
         * first section of window text into tile 0 of charblock 0 (because baseBlock=0 and BG0_charblock=0). When we
         * init our window, BG0's tilemap buffer is zeroed out (because it gets AllocZeroed'd by the window init code).
         * But since the tilemap buffer ultimately gets copied into BG0's screenblock, it is effectively telling the
         * hardware to draw tile 0 across the entire screen. And since we put some text in tile 0, you are going to end
         * up seeing a small bit of text drawn across the screen, which looks really bad.
         *
         * We obviously don't want that, so we offset the window text by one so that tile 0 of charblock 0 is empty. And
         * as a result our zeroed BG tilemap draws transparent tiles instead of the text fragment. (Recall that the
         * value in each tilemap buffer entry is basically a pointer into our charblock, so `tilemapBuffer[i] == 0'
         * means draw `tile 0' onto wherever `tilemap position i' maps on the LCD. The various LCD register settings
         * will define where on the LCD that `tilemap position i' is actually drawn. And technically, it's actually a
         * tad more complicated than this. See here for details: https://www.coranac.com/tonc/text/regbg.htm#sec-map)
         *
         * If this is confusing, try changing this value to 0, rebuild and see what the menu does. Looking at the mGBA
         * tile viewer will illuminate what is happening.
         */
        .baseBlock = 1
        /*
         * Just like with the BgTemplates, I encourage you to open:
         *     "mGBA Tools/Game State Views/View Tiles"
         * to see how this above code gets translated into an actual VRAM layout. In this case, try changing the
         * baseBlock value for this window and see where in VRAM the text gets drawn. If you want to really work your
         * brain, change the charblock base for BG0 *and* the baseBlock for this window and try to guess where in VRAM
         * your window text will show up.
         */
    },
    [WIN_MON_INFO] =
    {
        // This window will also print on BG0
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 9,
        .width = 26,
        .height = 10,
        // We will use the same palette for this window, since it's also just regular text
        .paletteNum = 15,
        /*
         * Here we will set the baseBlock to the previous window's baseblock + the width*height in tiles of the previous
         * window. Try changing this value around and use the mGBA tile viewer to see what happens.
         */
        .baseBlock = 1 + (16 * 7)
    },
    // Mark the end of the templates so the `InitWindow' library function doesn't run past the end
    DUMMY_WIN_TEMPLATE
};


/*
 * The tile file is generated from properly a indexed tile PNG image. You MUST use an indexed PNG with 4bpp indexing
 * (you can technically get away with 8bpp indexing as long as each individual index is between 0-15). The easiest way
 * to make indexed PNGs is using a program like GraphicsGale or Aseprite (in Index mode).
 */
static const u32 sModeMenuTiles[] = INCBIN_U32("graphics/sample_ui/tiles.4bpp.lz");

/*
 * I created this tilemap in TilemapStudio using the above tile PNG. I highly recommend TilemapStudio for exporting maps
 * like this.
 */
static const u32 sModeMenuTilemap[] = INCBIN_U32("graphics/sample_ui/tilemap.bin.lz");

/*
 * This palette was built from a JASC palette file that you can export using GraphicsGale or Aseprite. Please note: the
 * palette conversion tool REQUIRES that JASC palette files end in CRLF, the standard Windows line ending. If you are
 * using the Mac/Linux version of a tool like Aseprite, you may get errors complaining that your lines end in LF and not
 * CRLF. To remedy this, run your JASC palette file through a tool like unix2dos and you shouldn't have any more
 * problems.
 */
static const u16 sModeMenuPalette[] = INCBIN_U16("graphics/sample_ui/00.gbapal");

// Define some font color values that will index into our font color table below.
enum FontColor
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sModeMenuWindowFontColors[][3] =
{
    /*
     * The TEXT_COLOR_X macros here are just palette indexes. Specifically, these indexes match the colors in
     * `gMessageBox_Pal', so we will need to make sure that palette is loaded. Since our window is set to use
     * palette 15, we'll load it into BG palette slot 15 in the menu loading code.
     */
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]   = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GRAY},
};

// Callbacks for the sample UI
static void ModeMenu_SetupCB(void);
static void ModeMenu_MainCB(void);
static void ModeMenu_VBlankCB(void);

// Sample UI tasks
static void Task_ModeMenuWaitFadeIn(u8 taskId);
static void Task_ModeMenuMainInput(u8 taskId);
static void Task_ModeMenuWaitFadeAndBail(u8 taskId);
static void Task_ModeMenuWaitFadeAndExitGracefully(u8 taskId);

// Sample UI helper functions
void ModeMenu_Init(MainCallback callback);
static bool8 ModeMenu_InitBgs(void);
static void ModeMenu_FadeAndBail(void);
static bool8 ModeMenu_LoadGraphics(void);
static void ModeMenu_InitWindows(void);
static void ModeMenu_PrintUiButtonHints(void);
static void ModeMenu_PrintUiMonInfo(void);
static void ModeMenu_DrawMonIcon(u16 dexNum);
static void ModeMenu_FreeResources(void);

void Task_OpenModeMenu(u8 taskId)
{
    /*
     * We are still in the overworld callback, so wait until the palette fade is finished (i.e. the screen is entirely
     * black) before we start cleaning things up and changing callbacks (which might affect displayed graphics and cause
     * artifacting)
     */
    if (!gPaletteFade.active)
    {
        /*
         * Free overworld related heap stuff -- if you are entering this menu from somewhere else you may want to do
         * other cleanup. We're entering from overworld start menu so this works for us.
         */
        CleanupOverworldWindowsAndTilemaps();
        // Allocate heap space for menu state and set up callbacks
        ModeMenu_Init(CB2_ReturnToFieldWithOpenMenu);
        // Our setup is done, so destroy ourself.
        DestroyTask(taskId);
    }
}

void ModeMenu_Init(MainCallback callback)
{
    sModeMenuState = AllocZeroed(sizeof(struct ModeMenuState));
    if (sModeMenuState == NULL)
    {
        /*
         * If the heap allocation failed for whatever reason, then set the callback to just return to the overworld.
         * This really shouldn't ever happen but if it does, this is better than hard crashing and making the user think
         * you bricked their Game Boy.
         */
        SetMainCallback2(callback);
        return;
    }

    sModeMenuState->loadState = 0;
    sModeMenuState->savedCallback = callback;

    /*
     * Next frame start running UI setup code. SetMainCallback2 also resets gMain.state to zero, which we will need for
     * the SetupCB
     */
    SetMainCallback2(ModeMenu_SetupCB);
}

static void ModeMenu_SetupCB(void)
{
    /*
     * You may ask: why are these tasks in a giant switch statement? For one thing, it is because this is how GameFreak
     * does things, and cargo cult programming is a glorious institution. On a more serious note, the intention is to
     * control how much work is done each frame, and to prevent our setup code from getting interrupted in the middle of
     * something important. So ideally, we do a small bit of work in each case statement, exit the function, and then
     * wait for VBlank. Then next frame, we come back around and complete the work in the subsequent case statement.
     *
     * You may ask further: how can we be sure that the code in each case finishes before the end of the frame? The
     * short answer is (besides counting cycles, which is really hard to do given the complexity of the code being
     * called) we can't. The size of each case is generally a best guess, a crude attempt at doing a small amount of
     * work before stopping and letting the next frame handle the next bit.
     */
    switch (gMain.state)
    {
    case 0:
        // Use DMA to completely clear VRAM
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        // Null out V/H blanking callbacks since we are not drawing anything atm
        SetVBlankHBlankCallbacksToNull();
        /*
         * If previous game state had scheduled any copies to VRAM, cancel these now so we don't accidentally draw
         * garbage to the screen.
         */
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        /*
         * Unclear on what this does, I think it is related to some of the screen transition effects. In any case, we
         * don't want any of those since this is a menu, dammit
         */
        ScanlineEffect_Stop();
        /*
         * Clear all sprite palette tags in the sprite system. Sprite palette tags will be explained in more detail in
         * the next tutorial. For now, just accept that we need to clear them for things to work properly.
         */
        FreeAllSpritePalettes();
        /*
         * Reset palette fade settings -- we are currently in a fade-to-black initiated by whatever code opened this
         * menu screen. Since we don't know what they were doing with the palettes, just reset everything so we can do a
         * simple fade-in when we're done loading.
         */
        ResetPaletteFade();
        // Completely clear all sprite buffers and settings
        ResetSpriteData();
        /*
         * Completely clear all task data. There should be no tasks running right now so make sure nothing is hanging
         * around from whatever code got us into this menu.
         */
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        // Try to run the BG init code
        if (ModeMenu_InitBgs())
        {
            // If we successfully init the BGs, we can move on
            sModeMenuState->loadState = 0;
            gMain.state++;
        }
        else
        {
            /*
             * Otherwise, fade out, free the heap data, and return to main menu. Like before, this shouldn't ever really
             * happen but it's better to handle it then have a surprise hard-crash.
             */
            ModeMenu_FadeAndBail();
            return;
        }
        break;
    case 3:
        // `ModeMenu_LoadGraphics' has its own giant switch statement, so keep calling until it returns TRUE at the end
        if (ModeMenu_LoadGraphics() == TRUE)
        {
            // Only advance the state of this load switch statment once all the LoadGraphics logic has finished.
            gMain.state++;
        }
        break;
    case 4:
        // Set up our text windows
        ModeMenu_InitWindows();
        gMain.state++;
        break;
    case 5:
        // Setup initial draw of Pokemon icon sprite
        sModeMenuState->monIconDexNum = NATIONAL_DEX_BULBASAUR;

        /*
         * Free all mon icon palettes just to make sure nothing is left over from previous screen. The sprite system
         * uses a technique called palette tagging to help the game keep track of which palettes are in use, and by
         * which sprites. As mentioned above, we will cover palette tags in more detail in the next tutorial.
         */
        FreeMonIconPalettes();

        /*
         * Since this is a small demo without many sprites, we can just load all 6 default mon icon palettes at once.
         * If you have a more complex UI with lots of unique-palette sprites in addition to mon icons, you may instead
         * want to manage mon icon palettes dynamically based on which mon icons are currently on screen. You can do
         * this with the more granular `LoadMonIconPalette(u16 species)' and `FreeMonIconPalette(u16 species)'
         * functions.
         */
        LoadMonIconPalettes();

        // Draw the mon icon
        ModeMenu_DrawMonIcon(sModeMenuState->monIconDexNum);

        // Print the UI button hints in the top-right
        ModeMenu_PrintUiButtonHints();

        // Print the mon info in the main text box
        ModeMenu_PrintUiMonInfo();

        // Create a task that does nothing until the palette fade is done. We will start the palette fade next frame.
        CreateTask(Task_ModeMenuWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        /*
         * Fade screen in from black, this will take multiple frames to finish so we'll want the above active task poll
         * the fade to completion before continuing processing.
         */
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        // Finally we can set our main callbacks since loading is finished
        SetVBlankCallback(ModeMenu_VBlankCB);
        SetMainCallback2(ModeMenu_MainCB);
        break;
    }
}

static void ModeMenu_MainCB(void)
{
    // Iterate through the Tasks list and run any active task callbacks
    RunTasks();
    // For all active sprites, call their callbacks and update their animation state
    AnimateSprites();
    /*
     * After all sprite state is updated, we need to sort their information into the OAM buffer which will be copied
     * into actual OAM during VBlank. This makes sure sprites are drawn at the correct positions and in the correct
     * order (recall sprite draw order determines which sprites appear on top of each other).
     */
    BuildOamBuffer();
    /*
     * This one is a little confusing because there are actually two layers of scheduling. Regular game code can call
     * `ScheduleBgCopyTilemapToVram(u8 bgId)' which will simply mark the tilemap for `bgId' as "ready to be copied".
     * Then, calling `DoScheduledBgTilemapCopiesToVram' here does not actually perform the copy. Rather it simply adds a
     * DMA transfer request to the DMA manager for this buffer copy. Only during VBlank when DMA transfers are processed
     * does the copy into VRAM actually occur.
     */
    DoScheduledBgTilemapCopiesToVram();
    // If a palette fade is active, tick the udpate
    UpdatePaletteFade();
}

static void ModeMenu_VBlankCB(void)
{
    /*
     * Handle direct CPU copies here during the VBlank period. All of these transfers affect what is displayed on
     * screen, so we wait until VBlank to make the copies from the backbuffers.
     */

    // Transfer OAM buffer into VRAM OAM area
    LoadOam();
    /*
     * Sprite animation code may have updated frame image for sprites, so copy all these updated frames into the correct
     * VRAM location.
     */
    ProcessSpriteCopyRequests();
    // Transfer the processed palette buffer into VRAM palette area
    TransferPlttBuffer();
}

static void Task_ModeMenuWaitFadeIn(u8 taskId)
{
     // Do nothing until the palette fade finishes, then replace ourself with the main menu task.
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_ModeMenuMainInput;
    }
}

static void Task_ModeMenuMainInput(u8 taskId)
{
    // Exit the menu when the player presses B
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        // Fade screen to black
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        // Replace ourself with the "exit gracefully" task function
        gTasks[taskId].func = Task_ModeMenuWaitFadeAndExitGracefully;
    }
    // User pressed or held DPAD_DOWN, scroll down through dex list
    if (JOY_REPEAT(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        // Destroy the old mon sprite, update the selected dex num, and draw the new sprite
        FreeAndDestroyMonIconSprite(&gSprites[sModeMenuState->monIconSpriteId]);
        if (sModeMenuState->monIconDexNum < NATIONAL_DEX_MEW)
        {
            sModeMenuState->monIconDexNum++;
        }
        else
        {
            // Wrap dex number around to Bulbasaur when user presses down on Mew
            sModeMenuState->monIconDexNum = NATIONAL_DEX_BULBASAUR;
        }
        ModeMenu_DrawMonIcon(sModeMenuState->monIconDexNum);
        ModeMenu_PrintUiMonInfo();
    }
    // User pressed or held DPAD_UP, scroll up through dex list
    if (JOY_REPEAT(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        // Destroy the old mon sprite, update the selected dex num, and draw the new sprite
        FreeAndDestroyMonIconSprite(&gSprites[sModeMenuState->monIconSpriteId]);
        if (sModeMenuState->monIconDexNum > NATIONAL_DEX_BULBASAUR)
        {
            sModeMenuState->monIconDexNum--;
        }
        else
        {
            // Wrap dex number around to Mew when user presses Up on Bulbasaur
            sModeMenuState->monIconDexNum = NATIONAL_DEX_MEW;
        }
        ModeMenu_DrawMonIcon(sModeMenuState->monIconDexNum);
        ModeMenu_PrintUiMonInfo();
    }
    // User pressed A, cycle to next dex mode
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (sModeMenuState->mode == MODE_OTHER)
        {
            // Wrap back around to Info after the last mode
            sModeMenuState->mode = MODE_INFO;
        }
        else
        {
            sModeMenuState->mode++;
        }
        ModeMenu_PrintUiButtonHints();
        ModeMenu_PrintUiMonInfo();
    }
}

static void Task_ModeMenuWaitFadeAndBail(u8 taskId)
{
    // Wait until the screen fades to black before we start doing cleanup
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sModeMenuState->savedCallback);
        ModeMenu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_ModeMenuWaitFadeAndExitGracefully(u8 taskId)
{
    /*
     * This function is basically the same as Task_ModeMenuWaitFadeAndBail. However, for this sample we broke it out
     * because typically you might want to do something different if the user gracefully exits a menu vs if you got
     * booted from a menu due to heap allocation failure.
     */

    // E.g. you could do some other processing here

    // Wait until the screen fades to black before we start doing final cleanup
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sModeMenuState->savedCallback);
        ModeMenu_FreeResources();
        DestroyTask(taskId);
    }
}

static bool8 ModeMenu_InitBgs(void)
{
    /*
     * 1 screenblock is 2 KiB, so that should be a good size for our tilemap buffer. We don't need more than one
     * screenblock since BG1's size setting is 0, which tells the GBA we are using a 32x32 tile background:
     *      (32 tile * 32 tile * 2 bytes/tile = 2048)
     * For more info on tilemap entries and how they work:
     * https://www.coranac.com/tonc/text/regbg.htm#sec-map
     */
    const u32 TILEMAP_BUFFER_SIZE = (1024 * 2);

    // BG registers may have scroll values left over from the previous screen. Reset all scroll values to 0.
    ResetAllBgsCoordinates();

    // Allocate our tilemap buffer on the heap
    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        // Bail if the allocation fails
        return FALSE;
    }

    /*
     * Clear all BG-related data buffers and mark DMAs as ready. Also resets the BG and mode bits of reg DISPCNT to 0.
     * This will effectively turn off all BGs and activate Mode 0.
     * LTODO explain the underlying sDmaBusyBitfield here
     */
    ResetBgsAndClearDma3BusyFlags(0);

    /*
     * Use the BG templates defined at the top of the file to init various cached BG attributes. These attributes will
     * be used by the various load methods to correctly setup VRAM per the user template. Some of the attributes can
     * also be pushed into relevant video regs using the provided functions in `bg.h'
     */
    InitBgsFromTemplates(0, sModeMenuBgTemplates, NELEMS(sModeMenuBgTemplates));

    // Set the BG manager to use our newly allocated tilemap buffer for BG1's tilemap
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);

    /*
     * Schedule to copy the tilemap buffer contents (remember we zeroed it out earlier) into VRAM on the next VBlank.
     * Right now, BG1 will just use Tile 0 for every tile. We will change this once we load in our true tilemap
     * values from sModeMenuTilemap.
     */
    ScheduleBgCopyTilemapToVram(1);

    // Set reg DISPCNT to show BG0, BG1. Try commenting these out to see what happens.
    ShowBg(0);
    ShowBg(1);

    return TRUE;
}

static void ModeMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_ModeMenuWaitFadeAndBail, 0);

    /*
     * Set callbacks to ours while we wait for the fade to finish, then our above task will cleanup and swap the
     * callbacks back to the one we saved earlier (which should re-load the overworld)
     */
    SetVBlankCallback(ModeMenu_VBlankCB);
    SetMainCallback2(ModeMenu_MainCB);
}

static bool8 ModeMenu_LoadGraphics(void)
{
    switch (sModeMenuState->loadState)
    {
    case 0:
        /*
         * Reset leftover temp buffers from any previous code that used them to load graphics. The loading code in
         * `menu.c' basically saves pointers to the decompression buffers after it copies to VRAM. Here, we just reset
         * all the pointers to NULL and set the tracking index to 0. This obviously assumes the previous screen freed
         * the buffers for us.
         */
        ResetTempTileDataBuffers();

        /*
         * Decompress our tileset and copy it into VRAM using the parameters we set in the BgTemplates at the top -- we
         * pass 1 for the bgId so it uses the charblock setting from the BG1 template.
         * The size, offset, mode parameters are set to 0:
         *
         *      Size is 0 because that tells the function to set the size dynamically based on the decompressed data.
         *
         *      Offset is 0 because we want to tiles loaded right at whatever charblock we set in the BgTemplate.
         *
         *      Mode is 0 because we are copying tiles and not a tilemap, and 0 tells the bg library to use the tile
         *      loading code as opposed to the tilemap loading code (unfortunately GameFreak didn't provide a mode
         *      enum -- it was probably a preprocessor define in the original game code. So you have to look at the
         *      library functions to figure out what the mode values mean).
         *
         * `menu.c' also has a alternative function `DecompressAndLoadBgGfxUsingHeap', which does the same thing but
         * automatically frees the decompression buffer for you. If you want, you can use that here instead and remove
         * the `ResetTempTileDataBuffers' call above, since it doesn't use the temp tile data buffers.
         */
        DecompressAndCopyTileDataToVram(1, sModeMenuTiles, 0, 0, 0);
        sModeMenuState->loadState++;
        break;
    case 1:
        /*
         * Each frame, keep trying to free the temp data buffer we used last frame to copy the tile data into VRAM. We
         * have to do a poll here because this free may not occur depending on the state of the DMA manager. If instead
         * you chose to load graphics using the alternative `DecompressAndLoadBgGfxUsingHeap', you can remove this call
         * and wrapping if statement since the polling/freeing is handled for you under the hood.
         * LTODO explain this better, like above sDmaBusyBitfield is being used here, this might be confusing
         */
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            /*
             * This basically just wraps the LZ77UnCompWram system call. It reads and decompresses whatever data is
             * provided in the `src' (argument 1), and writes the decompressed data to a WRAM location given in `dest'
             * (argument 2). In our case `dest' is just the tilemap buffer we heap-allocated earlier.
             */
            LZDecompressWram(sModeMenuTilemap, sBg1TilemapBuffer);
            sModeMenuState->loadState++;
        }
        break;
    case 2:
        /*
         * Copy our palette into the game's BG palette buffer, slot 0 -- this step does not directly get the palette
         * into VRAM. That only happens during VBlank if the current callback specifies a buffer transfer.
         */
        LoadPalette(sModeMenuPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        /*
         * Copy the message box palette into BG palette buffer, slot 15. Our window is set to use palette 15 and our
         * text color constants are defined assuming we are indexing into this palette.
         */
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sModeMenuState->loadState++;
    default:
        sModeMenuState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void ModeMenu_InitWindows(void)
{
    /*
     * Initialize windows from the window templates we specified above. This makes two important allocations:
     *
     * 1) It allocates a tilemap buffer for the window tilemap, the size of which is based on the screen size setting
     *    specified in the BgTemplate (we didn't set one, so it defaults to 0, see BGXCNT register documentation for
     *    more details on screen sizes). For this UI, the size setting is 0 which just means use a single screen. We
     *    only allocate a single tilemap for the entire BG layer. So if you have multiple windows on the same BG, they
     *    will all share the same tilemap buffer.
     *
     * 2) It allocates one `tileData' buffer (often also called the pixel buffer in the code) for each window. *Each
     *    window has its own pixel buffer.* This is the buffer into which we actually draw text, and it gets copied upon
     *    request to the tile area of VRAM based on the BG charblock and window baseblock.
     *
     * It's also worth noting that the window API allows you to allocate and set your own tilemap buffer for the window
     * BG layer, just like we did earlier for BG1. However, it's better to just let the window API do the allocation and
     * setup for you through `InitWindows()' -- just make sure to call `FreeAllWindowBuffers()' before closing up shop
     * to return your memory.
     */
    InitWindows(sModeMenuWindowTemplates);

    // Marks all text printers as inactive. Basically just setting flags. That's it.
    DeactivateAllTextPrinters();

    /*
     * Schedule a copy of BG0 tilemap buffer to VRAM. This buffer was allocated for us by `InitWindows()' since we
     * specified a window on BG0 and had not yet set that layer's tilemap buffer. Note that the buffer was also zeroed
     * for us by `InitWindows()'
     */
    ScheduleBgCopyTilemapToVram(0);

    /*
     * Fill each entire window pixel buffer (i.e. window.tileData) with the given value. In this case, fill it with 0s
     * to make the window completely transparent. We will draw text into the window pixel buffer later.
     */
    FillWindowPixelBuffer(WIN_UI_HINTS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    FillWindowPixelBuffer(WIN_MON_INFO, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    /*
     * Write an increasing sequence of tile indexes into each window's tilemap buffer, based on the offset provided by
     * the window.baseBlock. Why? Because the window text will be drawn onto the tiles themselves. So we just want each
     * subsequent tilemap entry to point to the next tile in VRAM. That way, we can treat the tiles as a
     * pseudo-framebuffer and render our text however we want. If you dive deeper into the implementation of
     * `PutWindowTilemap', you will see that it takes some fancy calculation to determine which entries in the
     * tilemap buffer we actually need to modify (because we are mapping from GameFreak windows, which are logically 2D,
     * to VRAM locations, which in reality is basically a 1D array). I will leave exploration of the inner-workings of
     * this function as an exercise to the reader.
     */
    PutWindowTilemap(WIN_UI_HINTS);
    PutWindowTilemap(WIN_MON_INFO);

    /*
     * Copy (well, schedule to copy) each window into VRAM using DMA3 under the hood. The COPYWIN_FULL argument means we
     * copy BOTH the tilemap buffer (which recall is just an incrementing sequence of references into our tile canvas)
     * and the tiles themselves. Typically when updating text on a window, you only need to copy the tile canvas (i.e.
     * using COPYWIN_GFX) since the tilemap should never change. But to init the window we need to get both into VRAM.
     */
    CopyWindowToVram(WIN_UI_HINTS, COPYWIN_FULL);
    CopyWindowToVram(WIN_MON_INFO, COPYWIN_FULL);
}

static const u8 sText_ModeMenuButtonHint1[] = _("{DPAD_UPDOWN}Change POKéMON");
static const u8 sText_ModeMenuButtonHint2[] = _("{A_BUTTON}Mode: {STR_VAR_1}");
static const u8 sText_ModeMenuButtonHint3[] = _("{B_BUTTON}Exit");
static void ModeMenu_PrintUiButtonHints(void)
{
    /*
     * Fill the window with transparent. You normally want to do this before drawing new text to remove the old text
     * from the window (otherwise you'll see strange remnants of the previous text's pixels underneath your new text).
     */
    FillWindowPixelBuffer(WIN_UI_HINTS, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    // Copy the current mode name into a temp string variable
    StringCopy(gStringVar1, sModeNames[sModeMenuState->mode]);

    /*
     * `StringExpandPlaceholders' takes the src string, expands all placeholders (i.e. those bits in braces that look
     * like {FOO}), then copies the expanded string into dest. The {STR_VAR_1} placeholder will expand to the current
     * contents of temp string gStringVar1, which is very useful for constructing dynamic strings. Note that above we
     * saved the mode name into gStringVar1.
     */
    StringExpandPlaceholders(gStringVar2, sText_ModeMenuButtonHint2);

    /*
     * Use the text printing system to add text to this window. We set the speed value to TEXT_SKIP_DRAW to tell the
     * printer to draw into the pixel buffer but skip the actual VRAM copy. Why? Because we want to wait until all the
     * text is rendered before we actually copy to VRAM and make the text visible. This prevents flickering from
     * occuring (for a technical reason explained below). Try changing the speed parameter TEXT_SKIP_DRAW to 0 (which
     * tells the text printer to copy to VRAM on the next VBlank) and observe the slight flicker that occurs.
     *
     * The reason you see flickering when drawing lots of text without setting TEXT_SKIP_DRAW is because without this,
     * each `AddTextPrinterX' call actually schedules a separate DMA transfer of the partially draw window pixel buffer.
     * Since the each transfer is transfering the entire buffer, if you queue up a lot of these by calling
     * `AddTextPrinterX' a lot of separate times, getting everything into VRAM is going to take multiple frames, and you
     * will see the partially drawn text show up as each subsequent DMA transfer finishes.
     */
    AddTextPrinterParameterized4(WIN_UI_HINTS, FONT_NORMAL, 0, 3, 0, 0, sModeMenuWindowFontColors[FONT_WHITE],
        TEXT_SKIP_DRAW, sRegionNameKanto);
    AddTextPrinterParameterized4(WIN_UI_HINTS, FONT_SMALL, 47, 0, 0, 0, sModeMenuWindowFontColors[FONT_WHITE],
        TEXT_SKIP_DRAW, sText_ModeMenuButtonHint1);
    AddTextPrinterParameterized4(WIN_UI_HINTS, FONT_SMALL, 47, 10, 0, 0, sModeMenuWindowFontColors[FONT_WHITE],
        TEXT_SKIP_DRAW, gStringVar2);
    AddTextPrinterParameterized4(WIN_UI_HINTS, FONT_SMALL, 47, 20, 0, 0, sModeMenuWindowFontColors[FONT_WHITE],
        TEXT_SKIP_DRAW, sText_ModeMenuButtonHint3);

    /*
     * Explicitly copy to VRAM now that all text is drawn into the window pixel buffer. We use COPYWIN_GFX here since no
     * changes were made to the BG tilemap, so no need to copy it again (recall that GF windows use tile rendering).
     */
    CopyWindowToVram(WIN_UI_HINTS, COPYWIN_GFX);
}

static const u8 sText_ModeMenuMonInfoSpecies[] = _("{NO}{STR_VAR_1} {STR_VAR_2}");
static const u8 sText_ModeMenuMonStats[] = _("Put stats info here");
static const u8 sText_ModeMenuMonOther[] = _("Put other info here");
static void ModeMenu_PrintUiMonInfo(void)
{
    u16 speciesId = NationalPokedexNumToSpecies(sModeMenuState->monIconDexNum);

    // Clear the window before drawing new text
    FillWindowPixelBuffer(WIN_MON_INFO, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    switch (sModeMenuState->mode)
    {
    case MODE_INFO:
        /*
         * Use the string manipulation library to put the National Dex num, species name, and dex description into
         * strings, ready to be drawn.
         */
        ConvertIntToDecimalStringN(gStringVar1, sModeMenuState->monIconDexNum, STR_CONV_MODE_LEADING_ZEROS, 3);
        StringCopy(gStringVar2, GetSpeciesName(speciesId));
        StringExpandPlaceholders(gStringVar3, sText_ModeMenuMonInfoSpecies);
        StringCopy(gStringVar4, GetSpeciesPokedexDescription(speciesId));

        // The window drawing code here works just like in `ModeMenu_PrintUiButtonHints'
        AddTextPrinterParameterized4(WIN_MON_INFO, FONT_SHORT, 5, 3, 0, 0, sModeMenuWindowFontColors[FONT_BLACK],
            TEXT_SKIP_DRAW, gStringVar3);
        AddTextPrinterParameterized4(WIN_MON_INFO, FONT_SMALL, 5, 25, 0, 0, sModeMenuWindowFontColors[FONT_BLACK],
            TEXT_SKIP_DRAW, gStringVar4);
        break;
    case MODE_STATS:
        AddTextPrinterParameterized4(WIN_MON_INFO, FONT_SHORT, 5, 3, 0, 0, sModeMenuWindowFontColors[FONT_BLACK],
            TEXT_SKIP_DRAW, sText_ModeMenuMonStats);
        break;
    case MODE_OTHER:
        AddTextPrinterParameterized4(WIN_MON_INFO, FONT_SHORT, 5, 3, 0, 0, sModeMenuWindowFontColors[FONT_BLACK],
            TEXT_SKIP_DRAW, sText_ModeMenuMonOther);
        break;
    default:
        break;
    }

    // Copy pixel buffer to VRAM now that we are done drawing text
    CopyWindowToVram(WIN_MON_INFO, COPYWIN_GFX);
}

static void ModeMenu_DrawMonIcon(u16 dexNum)
{
    // Convert the dex number to a species ID.
    u16 speciesId = NationalPokedexNumToSpecies(dexNum);

    /*
     * Create a new mon icon sprite and save off its sprite ID so we can easily free it when we need to update which
     * icon is displayed. We set the sprite callback to a preset supplied by the GF's mon icon code. This callback
     * updates the little bounce animation of the icon. `CreateMonIcon' handles all the details of sprite initialization
     * for us. Feel free to dive into the implementation to see the gory details.
     */
    sModeMenuState->monIconSpriteId = CreateMonIcon(speciesId, SpriteCB_MonIcon, MON_ICON_X, MON_ICON_Y, 4, 0);
    // Set prio to 0 so the icon sprite draws on top of everything
    gSprites[sModeMenuState->monIconSpriteId].oam.priority = 0;
}

static void ModeMenu_FreeResources(void)
{
    // Free our data struct and our BG1 tilemap buffer
    if (sModeMenuState != NULL)
    {
        Free(sModeMenuState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }
    // Free all allocated tilemap and pixel buffers associated with the windows.
    FreeAllWindowBuffers();
    // Reset all sprite data
    ResetSpriteData();
}