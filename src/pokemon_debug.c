//Credits: Gamer2020, AsparagusEduardo, TheXaman, ShinyDragonHunter
#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "data.h"
#include "decompress.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "item.h"
#include "item_icon.h"
#include "list_menu.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "palette_util.h"
#include "pokemon.h"
#include "pokemon_animation.h"
#include "pokemon_debug.h"
#include "pokemon_icon.h"
#include "reset_rtc_screen.h"
#include "scanline_effect.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trainer_pokemon_sprites.h"

#include "constants/items.h"

//Defines
#define DEBUG_MON_X 144 + 32
#define DEBUG_MON_Y 11 + 40
#define DEBUG_MON_BACK_X 62
#define DEBUG_MON_BACK_Y 80
#define DEBUG_ICON_X 19
#define DEBUG_ICON_Y 19
#define DEBUG_MON_SHINY 0
#define DEBUG_MON_NORMAL 9

#define MODIFY_DIGITS_MAX 4
#define MODIFY_DIGITS_ARROW_X 41
#define MODIFY_DIGITS_ARROW1_Y 12
#define MODIFY_DIGITS_ARROW2_Y 36

#define GENDER_MALE 0
#define GENDER_FEMALE 1
#define MON_PIC_BACK 0
#define MON_PIC_FRONT 1

static const u16 sBgColor[] = {RGB_WHITE};

//Structs
struct PokemonDebugModifyArrows
{
    u8 arrowSpriteId[2];
    u16 minValue;
    u16 maxValue;
    int currValue;
    u8 currentDigit;
    u8 maxDigits;
    u8 charDigits[MODIFY_DIGITS_MAX];
    void *modifiedValPtr;
    u8 typeOfVal;
};

struct PokemonDebugMenu
{
    u16 currentmonId;
    u8 currentmonWindowId;
    u8 InstructionsWindowId;
    u8 frontspriteId;
    u8 backspriteId;
    u8 iconspriteId;
    bool8 isShiny;
    bool8 isFemale;
    struct PokemonDebugModifyArrows modifyArrows;
    u8 animIdBack;
    u8 animIdFront;
};

//WindowTemplates
#define WIN_NAME_NUMBERS 0
#define WIN_INSTRUCTIONS 1
#define WIN_BACK_SPRITE_LINE 2
#define WIN_ANIM_INFORMATION_FRONT 3
#define WIN_ANIM_INFORMATION_BACK 4
#define WIN_END 5
static const struct WindowTemplate sPokemonDebugWindowTemplate[] =
{
    [WIN_NAME_NUMBERS] = {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 2,
        .width = 14,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 1
    },
    [WIN_INSTRUCTIONS] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 15,
        .height = 5,
        .paletteNum = 0xF,
        .baseBlock = 1 + 28
    },
    [WIN_BACK_SPRITE_LINE] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 14,
        .width = 11,
        .height = 1,
        .paletteNum = 0xF,
        .baseBlock = 1 + 28 + 75
    },
    [WIN_ANIM_INFORMATION_FRONT] = {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 12,
        .width = 16,
        .height = 3,
        .paletteNum = 0xF,
        .baseBlock = 1 + 28 + 75 + 11
    },
    [WIN_ANIM_INFORMATION_BACK] = {
        .bg = 0,
        .tilemapLeft = 14,
        .tilemapTop = 15,
        .width = 16,
        .height = 3,
        .paletteNum = 0xF,
        .baseBlock = 1 + 28 + 75 + 11 + 48
    },
    DUMMY_WIN_TEMPLATE,
};

#if P_ENABLE_DEBUG
extern const u8 sMonFrontAnimIdsTable[NUM_SPECIES - 1];
const u8 gBackAnimNames[][23 + 1] =
{
    [BACK_ANIM_NONE]                    = _("NONE"),
    [BACK_ANIM_H_VIBRATE]               = _("H VIBRATE"),
    [BACK_ANIM_H_SLIDE]                 = _("H SLIDE"),
    [BACK_ANIM_H_SPRING]                = _("H SPRING"),
    [BACK_ANIM_H_SPRING_REPEATED]       = _("H SPRING REPEATED"),
    [BACK_ANIM_SHRINK_GROW]             = _("SHRINK GROW"),
    [BACK_ANIM_GROW]                    = _("GROW"),
    [BACK_ANIM_CIRCLE_COUNTERCLOCKWISE] = _("CIRCLE COUNTERCLOCKWISE"),
    [BACK_ANIM_H_SHAKE]                 = _("H SHAKE"),
    [BACK_ANIM_V_SHAKE]                 = _("V SHAKE"),
    [BACK_ANIM_V_SHAKE_H_SLIDE]         = _("V SHAKE H SLIDE"),
    [BACK_ANIM_V_STRETCH]               = _("V STRETCH"),
    [BACK_ANIM_H_STRETCH]               = _("H STRETCH"),
    [BACK_ANIM_GROW_STUTTER]            = _("GROW STUTTER"),
    [BACK_ANIM_V_SHAKE_LOW]             = _("V SHAKE LOW"),
    [BACK_ANIM_TRIANGLE_DOWN]           = _("TRIANGLE DOWN"),
    [BACK_ANIM_CONCAVE_ARC_LARGE]       = _("CONCAVE ARC LARGE"),
    [BACK_ANIM_CONVEX_DOUBLE_ARC]       = _("CONVEX DOUBLE ARC"),
    [BACK_ANIM_CONCAVE_ARC_SMALL]       = _("CONCAVE ARC SMALL"),
    [BACK_ANIM_DIP_RIGHT_SIDE]          = _("DIP RIGHT SIDE"),
    [BACK_ANIM_SHRINK_GROW_VIBRATE]     = _("SHRINK GROW VIBRATE"),
    [BACK_ANIM_JOLT_RIGHT]              = _("JOLT RIGHT"),
    [BACK_ANIM_SHAKE_FLASH_YELLOW]      = _("SHAKE FLASH YELLOW"),
    [BACK_ANIM_SHAKE_GLOW_RED]          = _("SHAKE GLOW RED"),
    [BACK_ANIM_SHAKE_GLOW_GREEN]        = _("SHAKE GLOW GREEN"),
    [BACK_ANIM_SHAKE_GLOW_BLUE]         = _("SHAKE GLOW BLUE"),
};
const u8 gFrontAnimNames[][34] =
{
    [ANIM_V_SQUISH_AND_BOUNCE]               = _("V SQUISH AND BOUNCE"),
    [ANIM_CIRCULAR_STRETCH_TWICE]            = _("CIRCULAR STRETCH TWICE"),
    [ANIM_H_VIBRATE]                         = _("H VIBRATE"),
    [ANIM_H_SLIDE]                           = _("H SLIDE"),
    [ANIM_V_SLIDE]                           = _("V SLIDE"),
    [ANIM_BOUNCE_ROTATE_TO_SIDES]            = _("BOUNCE ROTATE TO SIDES"),
    [ANIM_V_JUMPS_H_JUMPS]                   = _("V JUMPS H JUMPS"),
    [ANIM_ROTATE_TO_SIDES]                   = _("ROTATE TO SIDES"),
    [ANIM_ROTATE_TO_SIDES_TWICE]             = _("ROTATE TO SIDES TWICE"),
    [ANIM_GROW_VIBRATE]                      = _("GROW VIBRATE"),
    [ANIM_ZIGZAG_FAST]                       = _("ZIGZAG FAST"),
    [ANIM_SWING_CONCAVE]                     = _("SWING CONCAVE"),
    [ANIM_SWING_CONCAVE_FAST]                = _("SWING CONCAVE FAST"),
    [ANIM_SWING_CONVEX]                      = _("SWING CONVEX"),
    [ANIM_SWING_CONVEX_FAST]                 = _("SWING CONVEX FAST"),
    [ANIM_H_SHAKE]                           = _("H SHAKE"),
    [ANIM_V_SHAKE]                           = _("V SHAKE"),
    [ANIM_CIRCULAR_VIBRATE]                  = _("CIRCULAR VIBRATE"),
    [ANIM_TWIST]                             = _("TWIST"),
    [ANIM_SHRINK_GROW]                       = _("SHRINK GROW"),
    [ANIM_CIRCLE_C_CLOCKWISE]                = _("CIRCLE C CLOCKWISE"),
    [ANIM_GLOW_BLACK]                        = _("GLOW BLACK"),
    [ANIM_H_STRETCH]                         = _("H STRETCH"),
    [ANIM_V_STRETCH]                         = _("V STRETCH"),
    [ANIM_RISING_WOBBLE]                     = _("RISING WOBBLE"),
    [ANIM_V_SHAKE_TWICE]                     = _("V SHAKE TWICE"),
    [ANIM_TIP_MOVE_FORWARD]                  = _("TIP MOVE FORWARD"),
    [ANIM_H_PIVOT]                           = _("H PIVOT"),
    [ANIM_V_SLIDE_WOBBLE]                    = _("V SLIDE WOBBLE"),
    [ANIM_H_SLIDE_WOBBLE]                    = _("H SLIDE WOBBLE"),
    [ANIM_V_JUMPS_BIG]                       = _("V JUMPS BIG"),
    [ANIM_SPIN_LONG]                         = _("SPIN LONG"),
    [ANIM_GLOW_ORANGE]                       = _("GLOW ORANGE"),
    [ANIM_GLOW_RED]                          = _("GLOW RED"),
    [ANIM_GLOW_BLUE]                         = _("GLOW BLUE"),
    [ANIM_GLOW_YELLOW]                       = _("GLOW YELLOW"),
    [ANIM_GLOW_PURPLE]                       = _("GLOW PURPLE"),
    [ANIM_BACK_AND_LUNGE]                    = _("BACK AND LUNGE"),
    [ANIM_BACK_FLIP]                         = _("BACK FLIP"),
    [ANIM_FLICKER]                           = _("FLICKER"),
    [ANIM_BACK_FLIP_BIG]                     = _("BACK FLIP BIG"),
    [ANIM_FRONT_FLIP]                        = _("FRONT FLIP"),
    [ANIM_TUMBLING_FRONT_FLIP]               = _("TUMBLING FRONT FLIP"),
    [ANIM_FIGURE_8]                          = _("FIGURE 8"),
    [ANIM_FLASH_YELLOW]                      = _("FLASH YELLOW"),
    [ANIM_SWING_CONCAVE_FAST_SHORT]          = _("SWING CONCAVE FAST SHORT"),
    [ANIM_SWING_CONVEX_FAST_SHORT]           = _("SWING CONVEX FAST SHORT"),
    [ANIM_ROTATE_UP_SLAM_DOWN]               = _("ROTATE UP SLAM DOWN"),
    [ANIM_DEEP_V_SQUISH_AND_BOUNCE]          = _("DEEP V SQUISH AND BOUNCE"),
    [ANIM_H_JUMPS]                           = _("H JUMPS"),
    [ANIM_H_JUMPS_V_STRETCH]                 = _("H JUMPS V STRETCH"),
    [ANIM_ROTATE_TO_SIDES_FAST]              = _("ROTATE TO SIDES FAST"),
    [ANIM_ROTATE_UP_TO_SIDES]                = _("ROTATE UP TO SIDES"),
    [ANIM_FLICKER_INCREASING]                = _("FLICKER INCREASING"),
    [ANIM_TIP_HOP_FORWARD]                   = _("TIP HOP FORWARD"),
    [ANIM_PIVOT_SHAKE]                       = _("PIVOT SHAKE"),
    [ANIM_TIP_AND_SHAKE]                     = _("TIP AND SHAKE"),
    [ANIM_VIBRATE_TO_CORNERS]                = _("VIBRATE TO CORNERS"),
    [ANIM_GROW_IN_STAGES]                    = _("GROW IN STAGES"),
    [ANIM_V_SPRING]                          = _("V SPRING"),
    [ANIM_V_REPEATED_SPRING]                 = _("V REPEATED SPRING"),
    [ANIM_SPRING_RISING]                     = _("SPRING RISING"),
    [ANIM_H_SPRING]                          = _("H SPRING"),
    [ANIM_H_REPEATED_SPRING_SLOW]            = _("H REPEATED SPRING SLOW"),
    [ANIM_H_SLIDE_SHRINK]                    = _("H SLIDE SHRINK"),
    [ANIM_LUNGE_GROW]                        = _("LUNGE GROW"),
    [ANIM_CIRCLE_INTO_BG]                    = _("CIRCLE INTO BG"),
    [ANIM_RAPID_H_HOPS]                      = _("RAPID H HOPS"),
    [ANIM_FOUR_PETAL]                        = _("FOUR PETAL"),
    [ANIM_V_SQUISH_AND_BOUNCE_SLOW]          = _("V SQUISH AND BOUNCE SLOW"),
    [ANIM_H_SLIDE_SLOW]                      = _("H SLIDE SLOW"),
    [ANIM_V_SLIDE_SLOW]                      = _("V SLIDE SLOW"),
    [ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL]      = _("BOUNCE ROTATE TO SIDES SMALL"),
    [ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW]       = _("BOUNCE ROTATE TO SIDES SLOW"),
    [ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW] = _("BOUNCE ROTATE TO SIDES SMALL SLOW"),
    [ANIM_ZIGZAG_SLOW]                       = _("ZIGZAG SLOW"),
    [ANIM_H_SHAKE_SLOW]                      = _("H SHAKE SLOW"),
    [ANIM_V_SHAKE_SLOW]                      = _("V SHAKE SLOW"),
    [ANIM_TWIST_TWICE]                       = _("TWIST TWICE"),
    [ANIM_CIRCLE_C_CLOCKWISE_SLOW]           = _("CIRCLE C CLOCKWISE SLOW"),
    [ANIM_V_SHAKE_TWICE_SLOW]                = _("V SHAKE TWICE SLOW"),
    [ANIM_V_SLIDE_WOBBLE_SMALL]              = _("V SLIDE WOBBLE SMALL"),
    [ANIM_V_JUMPS_SMALL]                     = _("V JUMPS SMALL"),
    [ANIM_SPIN]                              = _("SPIN"),
    [ANIM_TUMBLING_FRONT_FLIP_TWICE]         = _("TUMBLING FRONT FLIP TWICE"),
    [ANIM_DEEP_V_SQUISH_AND_BOUNCE_TWICE]    = _("DEEP V SQUISH AND BOUNCE TWICE"),
    [ANIM_H_JUMPS_V_STRETCH_TWICE]           = _("H JUMPS V STRETCH TWICE"),
    [ANIM_V_SHAKE_BACK]                      = _("V SHAKE BACK"),
    [ANIM_V_SHAKE_BACK_SLOW]                 = _("V SHAKE BACK SLOW"),
    [ANIM_V_SHAKE_H_SLIDE_SLOW]              = _("V SHAKE H SLIDE SLOW"),
    [ANIM_V_STRETCH_BOTH_ENDS_SLOW]          = _("V STRETCH BOTH ENDS SLOW"),
    [ANIM_H_STRETCH_FAR_SLOW]                = _("H STRETCH FAR SLOW"),
    [ANIM_V_SHAKE_LOW_TWICE]                 = _("V SHAKE LOW TWICE"),
    [ANIM_H_SHAKE_FAST]                      = _("H SHAKE FAST"),
    [ANIM_H_SLIDE_FAST]                      = _("H SLIDE FAST"),
    [ANIM_H_VIBRATE_FAST]                    = _("H VIBRATE FAST"),
    [ANIM_H_VIBRATE_FASTEST]                 = _("H VIBRATE FASTEST"),
    [ANIM_V_SHAKE_BACK_FAST]                 = _("V SHAKE BACK FAST"),
    [ANIM_V_SHAKE_LOW_TWICE_SLOW]            = _("V SHAKE LOW TWICE SLOW"),
    [ANIM_V_SHAKE_LOW_TWICE_FAST]            = _("V SHAKE LOW TWICE FAST"),
    [ANIM_CIRCLE_C_CLOCKWISE_LONG]           = _("CIRCLE C CLOCKWISE LONG"),
    [ANIM_GROW_STUTTER_SLOW]                 = _("GROW STUTTER SLOW"),
    [ANIM_V_SHAKE_H_SLIDE]                   = _("V SHAKE H SLIDE"),
    [ANIM_V_SHAKE_H_SLIDE_FAST]              = _("V SHAKE H SLIDE FAST"),
    [ANIM_TRIANGLE_DOWN_SLOW]                = _("TRIANGLE DOWN SLOW"),
    [ANIM_TRIANGLE_DOWN]                     = _("TRIANGLE DOWN"),
    [ANIM_TRIANGLE_DOWN_TWICE]               = _("TRIANGLE DOWN TWICE"),
    [ANIM_GROW]                              = _("GROW"),
    [ANIM_GROW_TWICE]                        = _("GROW TWICE"),
    [ANIM_H_SPRING_FAST]                     = _("H SPRING FAST"),
    [ANIM_H_SPRING_SLOW]                     = _("H SPRING SLOW"),
    [ANIM_H_REPEATED_SPRING_FAST]            = _("H REPEATED SPRING FAST"),
    [ANIM_H_REPEATED_SPRING]                 = _("H REPEATED SPRING"),
    [ANIM_SHRINK_GROW_FAST]                  = _("SHRINK GROW FAST"),
    [ANIM_SHRINK_GROW_SLOW]                  = _("SHRINK GROW SLOW"),
    [ANIM_V_STRETCH_BOTH_ENDS]               = _("V STRETCH BOTH ENDS"),
    [ANIM_V_STRETCH_BOTH_ENDS_TWICE]         = _("V STRETCH BOTH ENDS TWICE"),
    [ANIM_H_STRETCH_FAR_TWICE]               = _("H STRETCH FAR TWICE"),
    [ANIM_H_STRETCH_FAR]                     = _("H STRETCH FAR"),
    [ANIM_GROW_STUTTER_TWICE]                = _("GROW STUTTER TWICE"),
    [ANIM_GROW_STUTTER]                      = _("GROW STUTTER"),
    [ANIM_CONCAVE_ARC_LARGE_SLOW]            = _("CONCAVE ARC LARGE SLOW"),
    [ANIM_CONCAVE_ARC_LARGE]                 = _("CONCAVE ARC LARGE"),
    [ANIM_CONCAVE_ARC_LARGE_TWICE]           = _("CONCAVE ARC LARGE TWICE"),
    [ANIM_CONVEX_DOUBLE_ARC_SLOW]            = _("CONVEX DOUBLE ARC SLOW"),
    [ANIM_CONVEX_DOUBLE_ARC]                 = _("CONVEX DOUBLE ARC"),
    [ANIM_CONVEX_DOUBLE_ARC_TWICE]           = _("CONVEX DOUBLE ARC TWICE"),
    [ANIM_CONCAVE_ARC_SMALL_SLOW]            = _("CONCAVE ARC SMALL SLOW"),
    [ANIM_CONCAVE_ARC_SMALL]                 = _("CONCAVE ARC SMALL"),
    [ANIM_CONCAVE_ARC_SMALL_TWICE]           = _("CONCAVE ARC SMALL TWICE"),
    [ANIM_H_DIP]                             = _("H DIP"),
    [ANIM_H_DIP_FAST]                        = _("H DIP FAST"),
    [ANIM_H_DIP_TWICE]                       = _("H DIP TWICE"),
    [ANIM_SHRINK_GROW_VIBRATE_FAST]          = _("SHRINK GROW VIBRATE FAST"),
    [ANIM_SHRINK_GROW_VIBRATE]               = _("SHRINK GROW VIBRATE"),
    [ANIM_SHRINK_GROW_VIBRATE_SLOW]          = _("SHRINK GROW VIBRATE SLOW"),
    [ANIM_JOLT_RIGHT_FAST]                   = _("JOLT RIGHT FAST"),
    [ANIM_JOLT_RIGHT]                        = _("JOLT RIGHT"),
    [ANIM_JOLT_RIGHT_SLOW]                   = _("JOLT RIGHT SLOW"),
    [ANIM_SHAKE_FLASH_YELLOW_FAST]           = _("SHAKE FLASH YELLOW FAST"),
    [ANIM_SHAKE_FLASH_YELLOW]                = _("SHAKE FLASH YELLOW"),
    [ANIM_SHAKE_FLASH_YELLOW_SLOW]           = _("SHAKE FLASH YELLOW SLOW"),
    [ANIM_SHAKE_GLOW_RED_FAST]               = _("SHAKE GLOW RED FAST"),
    [ANIM_SHAKE_GLOW_RED]                    = _("SHAKE GLOW RED"),
    [ANIM_SHAKE_GLOW_RED_SLOW]               = _("SHAKE GLOW RED SLOW"),
    [ANIM_SHAKE_GLOW_GREEN_FAST]             = _("SHAKE GLOW GREEN FAST"),
    [ANIM_SHAKE_GLOW_GREEN]                  = _("SHAKE GLOW GREEN"),
    [ANIM_SHAKE_GLOW_GREEN_SLOW]             = _("SHAKE GLOW GREEN SLOW"),
    [ANIM_SHAKE_GLOW_BLUE_FAST]              = _("SHAKE GLOW BLUE FAST"),
    [ANIM_SHAKE_GLOW_BLUE]                   = _("SHAKE GLOW BLUE"),
    [ANIM_SHAKE_GLOW_BLUE_SLOW]              = _("SHAKE GLOW BLUE SLOW"),
    [ANIM_SHAKE_GLOW_BLACK_SLOW]             = _("SHAKE GLOW BLACK SLOW"),
    [ANIM_SHAKE_GLOW_WHITE_SLOW]             = _("SHAKE GLOW WHITE SLOW"),
    [ANIM_SHAKE_GLOW_PURPLE_SLOW]            = _("SHAKE GLOW PURPLE SLOW"),
};

//Function declarations
static void PrintDigitChars(struct PokemonDebugMenu *data);
static void SetUpModifyArrows(struct PokemonDebugMenu *data);
static void UpdateBattlerValue(struct PokemonDebugMenu *data);
static void ValueToCharDigits(u8 *charDigits, u32 newValue, u8 maxDigits);
static bool32 TryMoveDigit(struct PokemonDebugModifyArrows *modArrows, bool32 moveUp);
static void CB2_Debug_Runner(void);
static void ResetBGs_Debug_Menu(u16);
static void Handle_Input_Debug_Pokemon(u8);
static void ReloadPokemonSprites(struct PokemonDebugMenu *data);
static void Exit_Debug_Pokemon(u8);

static struct PokemonDebugMenu *GetStructPtr(u8 taskId)
{
    u8 *taskDataPtr = (u8*)(&gTasks[taskId].data[0]);

    return (struct PokemonDebugMenu*)(T1_READ_PTR(taskDataPtr));
}

//Text handling functions
static void PadString(const u8 *src, u8 *dst)
{
    u32 i;

    for (i = 0; i < 17 && src[i] != EOS; i++)
        dst[i] = src[i];

    for (; i < 17; i++)
        dst[i] = CHAR_SPACE;

    dst[i] = EOS;
}

static void PrintInstructionsOnWindow(u8 windowId, struct PokemonDebugMenu *data)
{
    u8 text[] = _("{L_BUTTON} Back  {R_BUTTON} Front\n{A_BUTTON} Shiny$");
    u8 textGender[] = _("{L_BUTTON} Back  {R_BUTTON} Front\n{A_BUTTON} Shiny\n{SELECT_BUTTON} Gender$");
    u8 textForms[] = _("{L_BUTTON} Back  {R_BUTTON} Front\n{A_BUTTON} Shiny  {START_BUTTON} Forms$");
    u8 textGenderForms[] = _("{L_BUTTON} Back  {R_BUTTON} Front\n{A_BUTTON} Shiny  {START_BUTTON} Forms\n{SELECT_BUTTON} Gender$");
    u16 species = data->modifyArrows.currValue;
    

    FillWindowPixelBuffer(windowId, 0x11);
    if (SpeciesHasGenderDifference[species])
    {
        if (gFormSpeciesIdTables[data->currentmonId] != NULL)
            AddTextPrinterParameterized(windowId, 0, textGenderForms, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(windowId, 0, textGender, 0, 0, 0, NULL);
    }
    else
    {
        if (gFormSpeciesIdTables[data->currentmonId] != NULL)
            AddTextPrinterParameterized(windowId, 0, textForms, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(windowId, 0, text, 0, 0, 0, NULL);
    }
    CopyWindowToVram(windowId, 3);
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void SetStructPtr(u8 taskId, void *ptr)
{
    u32 structPtr = (u32)(ptr);
    u8 *taskDataPtr = (u8*)(&gTasks[taskId].data[0]);

    taskDataPtr[0] = structPtr >> 0;
    taskDataPtr[1] = structPtr >> 8;
    taskDataPtr[2] = structPtr >> 16;
    taskDataPtr[3] = structPtr >> 24;
}

//Digit and arrow functions
#define VAL_U16     0
static void PrintDigitChars(struct PokemonDebugMenu *data)
{
    s32 i;
    u16 species = data->modifyArrows.currValue;
    u8 text[MODIFY_DIGITS_MAX + POKEMON_NAME_LENGTH + 8];

    for (i = 0; i < data->modifyArrows.maxDigits; i++)
        text[i] = data->modifyArrows.charDigits[i];
    
    text[i++] = CHAR_SPACE;
    text[i++] = CHAR_HYPHEN;

    if (SpeciesHasGenderDifference[species])
    {
        if (data->isFemale)
            text[i++] = CHAR_FEMALE;
        else
            text[i++] = CHAR_MALE;   
        text[i++] = CHAR_HYPHEN;
    }

    text[i++] = CHAR_SPACE;
    StringCopy(&text[i], gSpeciesNames[species]);

    FillWindowPixelBuffer(WIN_NAME_NUMBERS, 0x11);
    AddTextPrinterParameterized(WIN_NAME_NUMBERS, 1, text, 6, 0, 0, NULL);
}

static u32 CharDigitsToValue(u8 *charDigits, u8 maxDigits)
{
    s32 i;
    u8 id = 0;
    u32 newValue = 0;
    u8 valueDigits[MODIFY_DIGITS_MAX];

    for (i = 0; i < MODIFY_DIGITS_MAX; i++)
        valueDigits[i] = charDigits[i] - CHAR_0;

    if (maxDigits >= MODIFY_DIGITS_MAX)
        newValue += valueDigits[id++] * 1000;
    if (maxDigits >= MODIFY_DIGITS_MAX - 1)
        newValue += valueDigits[id++] * 100;
    if (maxDigits >= MODIFY_DIGITS_MAX - 2)
        newValue += valueDigits[id++] * 10;
    if (maxDigits >= MODIFY_DIGITS_MAX - 3)
        newValue += valueDigits[id++];

    return newValue;
}

static void ValueToCharDigits(u8 *charDigits, u32 newValue, u8 maxDigits)
{
    s32 i;
    u8 valueDigits[MODIFY_DIGITS_MAX];
    u8 id = 0;

    if (maxDigits >= MODIFY_DIGITS_MAX)
        valueDigits[id++] = newValue / 1000;
    if (maxDigits >= MODIFY_DIGITS_MAX - 1)
        valueDigits[id++] = (newValue % 1000) / 100;
    if (maxDigits >= MODIFY_DIGITS_MAX - 2)
        valueDigits[id++] = (newValue % 100) / 10;
    if (maxDigits >= MODIFY_DIGITS_MAX - 3)
        valueDigits[id++] = newValue % 10;

    for (i = 0; i < MODIFY_DIGITS_MAX; i++)
        charDigits[i] = valueDigits[i] + CHAR_0;
}

static void SetUpModifyArrows(struct PokemonDebugMenu *data)
{
    LoadSpritePalette(&sSpritePalette_Arrow);
    data->modifyArrows.arrowSpriteId[0] = CreateSprite(&sSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X, MODIFY_DIGITS_ARROW1_Y, 0);
    data->modifyArrows.arrowSpriteId[1] = CreateSprite(&sSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X, MODIFY_DIGITS_ARROW2_Y, 0);
    gSprites[data->modifyArrows.arrowSpriteId[1]].animNum = 1;

    data->modifyArrows.minValue = 1;
    data->modifyArrows.maxValue = NUM_SPECIES - 1;
    data->modifyArrows.maxDigits = 4;
    data->modifyArrows.modifiedValPtr = &data->currentmonId;
    data->modifyArrows.typeOfVal = VAL_U16;
    data->modifyArrows.currValue = data->currentmonId;

    data->modifyArrows.currentDigit = 0;
    ValueToCharDigits(data->modifyArrows.charDigits, data->modifyArrows.currValue, data->modifyArrows.maxDigits);
}

static bool32 TryMoveDigit(struct PokemonDebugModifyArrows *modArrows, bool32 moveUp)
{
    s32 i;
    u8 charDigits[MODIFY_DIGITS_MAX];
    u32 newValue;

    for (i = 0; i < MODIFY_DIGITS_MAX; i++)
        charDigits[i] = modArrows->charDigits[i];

    if (moveUp)
    {
        if (charDigits[modArrows->currentDigit] == CHAR_9)
        {
            charDigits[modArrows->currentDigit] = CHAR_0;
            for (i = modArrows->currentDigit - 1; i >= 0; i--)
            {
                if (charDigits[i] == CHAR_9)
                    charDigits[i] = CHAR_0;
                else
                {
                    charDigits[i]++;
                    break;
                }
            }
        }
        else
            charDigits[modArrows->currentDigit]++;
    }
    else
    {
        if (charDigits[modArrows->currentDigit] == CHAR_0)
        {
            charDigits[modArrows->currentDigit] = CHAR_9;
            
            for (i = modArrows->currentDigit - 1; i >= 0; i--)
            {
                if (charDigits[i] == CHAR_0)
                    charDigits[i] = CHAR_9;
                else
                {
                    charDigits[i]--;
                    break;
                }
            }
        }

        else
            charDigits[modArrows->currentDigit]--;
    }

    newValue = CharDigitsToValue(charDigits, modArrows->maxDigits);
    if (newValue > modArrows->maxValue || newValue < modArrows->minValue)
    {
        return FALSE;
    }
    else
    {
        modArrows->currValue = newValue;
        for (i = 0; i < MODIFY_DIGITS_MAX; i++)
             modArrows->charDigits[i] = charDigits[i];
        return TRUE;
    }
}

static void UpdateBattlerValue(struct PokemonDebugMenu *data)
{
    u32 i;
    switch (data->modifyArrows.typeOfVal)
    {
    case VAL_U16:
        *(u16*)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    }
}

//Sprite functions
static const struct CompressedSpritePalette *GetMonSpritePalStructCustom(u16 species, bool8 isFemale, bool8 isShiny)
{
    if (isShiny)
    {
        if (SpeciesHasGenderDifference[species] && isFemale)
            return &gMonShinyPaletteTableFemale[species];
        else
            return &gMonShinyPaletteTable[species];
    }
    else
    {
        if (SpeciesHasGenderDifference[species] && isFemale)
            return &gMonPaletteTableFemale[species];
        else
            return &gMonPaletteTable[species];
    }
}

void BattleLoadOpponentMonSpriteGfxCustom(u16 species, bool8 isFemale, bool8 isShiny, u8 battlerId)
{
    u16 paletteOffset;
    const void *lzPaletteData;
    const struct CompressedSpritePalette *palette;

    paletteOffset = 0x100 + battlerId * 16;

    palette = GetMonSpritePalStructCustom(species, isFemale, isShiny);

    if (isShiny)
    {
        if (SpeciesHasGenderDifference[species] && isFemale)
            lzPaletteData = gMonShinyPaletteTableFemale[species].data;
        else
            lzPaletteData = gMonShinyPaletteTable[species].data;
    }
    else
    {
        if (SpeciesHasGenderDifference[species] && isFemale)
            lzPaletteData = gMonPaletteTableFemale[species].data;
        else
            lzPaletteData = gMonPaletteTable[species].data;
    }

    LZDecompressWram(lzPaletteData, gDecompressionBuffer);
    LoadPalette(gDecompressionBuffer, paletteOffset, 0x20);
    LoadPalette(gDecompressionBuffer, 0x80 + battlerId * 16, 0x20);
}

// *******************************
// Main functions
static void UpdateMonAnimNames(u8 taskId)
{
    struct PokemonDebugMenu *data = GetStructPtr(taskId);
    u8 frontAnim = data->animIdFront;
    u8 backAnim = data->animIdBack;
    u8 textFront[] = _("FRONT {R_BUTTON} + {DPAD_LEFTRIGHT}$");
    u8 textBack[] = _("BACK {L_BUTTON} + {DPAD_LEFTRIGHT}$");
    u8 text[34];
    u8 fontId = 0;

    //Front
    FillWindowPixelBuffer(WIN_ANIM_INFORMATION_FRONT, PIXEL_FILL(0));
    AddTextPrinterParameterized(WIN_ANIM_INFORMATION_FRONT, fontId, textFront, 0, 0, 0, NULL);
    StringCopy(text, gFrontAnimNames[frontAnim]);
    AddTextPrinterParameterized(WIN_ANIM_INFORMATION_FRONT, fontId, text, 4, 12, 0, NULL);

    //Back
    FillWindowPixelBuffer(WIN_ANIM_INFORMATION_BACK, PIXEL_FILL(0));
    AddTextPrinterParameterized(WIN_ANIM_INFORMATION_BACK, fontId, textBack, 0, 0, 0, NULL);
    StringCopy(text, gBackAnimNames[backAnim]);
    AddTextPrinterParameterized(WIN_ANIM_INFORMATION_BACK, fontId, text, 4, 12, 0, NULL);
}

static void ResetPokemonDebugWindows(void)
{
    u8 i;

    FreeAllWindowBuffers();
    InitWindows(sPokemonDebugWindowTemplate);

    for (i = 0; i < WIN_END + 1; i++)
    {
        if (i == WIN_BACK_SPRITE_LINE)
            continue;
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        PutWindowTilemap(i);
        CopyWindowToVram(i, 3);
    }
}
void CB2_Debug_Pokemon(void)
{
    u8 taskId;
    const struct CompressedSpritePalette *palette;
    struct PokemonDebugMenu *data;
    s16 offset_x, offset_y;
    u16 species;

    switch (gMain.state)
    {
        case 0:
        default:
            SetVBlankCallback(NULL);
            FreeMonSpritesGfx();
            ResetBGs_Debug_Menu(0);
            DmaFillLarge16(3, 0, (u8 *)VRAM, VRAM_SIZE, 0x1000)
            DmaClear32(3, OAM, OAM_SIZE);
            DmaClear16(3, PLTT, PLTT_SIZE);
            gMain.state = 1;
            break;
        case 1:
            ScanlineEffect_Stop();
            ResetTasks();
            ResetSpriteData();
            ResetPaletteFade();
            FreeAllSpritePalettes();
            gReservedSpritePaletteCount = 8;
            ResetAllPicSprites();
            gMain.state++;
            break;
        case 2:
            FillBgTilemapBufferRect(0, 0, 0, 0, 32, 20, 15);
            ResetPokemonDebugWindows();
            gMain.state++;
            break;
        case 3:
            AllocateMonSpritesGfx();

            LoadPalette(sBgColor, 0, 2);
            LoadMonIconPalette(SPECIES_BULBASAUR);

            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
            ShowBg(0);
            ShowBg(1);

            //input task handler
            taskId = CreateTask(Handle_Input_Debug_Pokemon, 0);

            data = AllocZeroed(sizeof(struct PokemonDebugMenu));
            SetStructPtr(taskId, data);

            data->currentmonId = SPECIES_BULBASAUR;
            species = data->currentmonId;

            //Print instructions
            PrintInstructionsOnWindow(WIN_INSTRUCTIONS, data);

            //Palettes
            palette = GetMonSpritePalStructCustom(species, data->isFemale, data->isShiny);
            LoadCompressedSpritePalette(palette);
            //Front
            HandleLoadSpecialPokePicCustom(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites.ptr[1], species, 0, data->isFemale);
            data->isShiny = FALSE;
            data->isFemale = FALSE;
            BattleLoadOpponentMonSpriteGfxCustom(species, data->isFemale, data->isShiny, 1);
            SetMultiuseSpriteTemplateToPokemon(species, 1);
            gMultiuseSpriteTemplate.paletteTag = palette->tag;
            data->frontspriteId = CreateSprite(&gMultiuseSpriteTemplate, DEBUG_MON_X, DEBUG_MON_Y, 0);
            gSprites[data->frontspriteId].oam.paletteNum = 1;
            gSprites[data->frontspriteId].callback = SpriteCallbackDummy;
            gSprites[data->frontspriteId].oam.priority = 0;

            //Back
            HandleLoadSpecialPokePicCustom(&gMonBackPicTable[species], gMonSpritesGfxPtr->sprites.ptr[2], species, 0, data->isFemale);
            BattleLoadOpponentMonSpriteGfxCustom(species, data->isFemale, data->isShiny, 4);
            SetMultiuseSpriteTemplateToPokemon(species, 2);
            offset_y = gMonBackPicCoords[species].y_offset;
            data->backspriteId = CreateSprite(&gMultiuseSpriteTemplate, DEBUG_MON_BACK_X, DEBUG_MON_BACK_Y + offset_y, 0);
            gSprites[data->backspriteId].oam.paletteNum = 4;
            gSprites[data->backspriteId].callback = SpriteCallbackDummy;
            gSprites[data->backspriteId].oam.priority = 0;

            //Icon Sprite
            data->iconspriteId = CreateMonIconCustom(species, SpriteCB_MonIcon, DEBUG_ICON_X, DEBUG_ICON_Y, 4, data->isShiny, data->isFemale, data->isShiny);
            gSprites[data->iconspriteId].oam.priority = 0;

            //Modify Arrows
            SetUpModifyArrows(data);
            PrintDigitChars(data);

            //MessageBox line
            PutWindowTilemap(WIN_BACK_SPRITE_LINE);
            FillWindowPixelRect(WIN_BACK_SPRITE_LINE, PIXEL_FILL(0x2), 0, 0, 90, 4);
            CopyWindowToVram(WIN_BACK_SPRITE_LINE, 3);

            //Anim names
            data->animIdBack = GetSpeciesBackAnimSet(species) + 1;
            data->animIdFront = sMonFrontAnimIdsTable[data->currentmonId - 1];
            UpdateMonAnimNames(taskId);

            gMain.state++;
            break;
        case 4:
            EnableInterrupts(1);
            SetVBlankCallback(VBlankCB);
            SetMainCallback2(CB2_Debug_Runner);
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x80);
            break;
    }
}

static void CB2_Debug_Runner(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void ResetBGs_Debug_Menu(u16 a)
{
    if (!(a & DISPCNT_BG0_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG0_ON);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    }
    if (!(a & DISPCNT_BG1_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG1_ON);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    }
    if (!(a & DISPCNT_BG2_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG2_ON);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    }
    if (!(a & DISPCNT_BG3_ON))
    {
        ClearGpuRegBits(0, DISPCNT_BG3_ON);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    }
    if (!(a & DISPCNT_OBJ_ON))
    {
        ClearGpuRegBits(0, DISPCNT_OBJ_ON);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
    }
}

static void Handle_Input_Debug_Pokemon(u8 taskId)
{
    struct PokemonDebugMenu *data = GetStructPtr(taskId);
    struct Sprite *Frontsprite = &gSprites[data->frontspriteId];
    struct Sprite *Backsprite = &gSprites[data->backspriteId];
    
    //Back
    if (JOY_HELD(L_BUTTON) && JOY_NEW(DPAD_LEFT))
    {
        if (data->animIdBack <= 1)
            data->animIdBack = BACK_ANIM_SHAKE_GLOW_BLUE;
        else
            data->animIdBack -= 1;
        UpdateMonAnimNames(taskId);
    }
    else if (JOY_HELD(L_BUTTON) && JOY_NEW(DPAD_RIGHT))
    {
        if (data->animIdBack >= BACK_ANIM_SHAKE_GLOW_BLUE)
            data->animIdBack = 1;
        else
            data->animIdBack += 1;
        UpdateMonAnimNames(taskId);
    }
    else if (JOY_NEW(L_BUTTON)  && (Backsprite->callback == SpriteCallbackDummy))
    {
        PlayCryInternal(data->currentmonId, 0, 120, 10, 0);
        LaunchAnimationTaskForBackSprite(Backsprite, data->animIdBack-1);
    }
    //Front
    else if (JOY_HELD(R_BUTTON) && JOY_NEW(DPAD_LEFT))
    {
        if (data->animIdFront <= 0)
            data->animIdFront = ANIM_SHAKE_GLOW_PURPLE_SLOW;
        else
            data->animIdFront -= 1;
        UpdateMonAnimNames(taskId);
    }
    else if (JOY_HELD(R_BUTTON) && JOY_NEW(DPAD_RIGHT))
    {
        if (data->animIdFront >= ANIM_SHAKE_GLOW_PURPLE_SLOW)
            data->animIdFront = 0;
        else
            data->animIdFront += 1;
        UpdateMonAnimNames(taskId);
    }
    else if (JOY_NEW(R_BUTTON) && (Frontsprite->callback == SpriteCallbackDummy))
    {
        PlayCryInternal(data->currentmonId, 0, 120, 10, 0);
        if (HasTwoFramesAnimation(data->currentmonId))
            StartSpriteAnim(Frontsprite, 1);
        LaunchAnimationTaskForFrontSprite(Frontsprite, data->animIdFront);
    }
    //Rest
    else if (JOY_NEW(A_BUTTON))
    {
        data->isShiny = !data->isShiny;
        
        if(data->isShiny)
            PlaySE(SE_SHINY);

        ReloadPokemonSprites(data);

    }
    else if (JOY_NEW(B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = Exit_Debug_Pokemon;
        PlaySE(SE_PC_OFF);
    }
    else if (JOY_NEW(START_BUTTON))
    {
        if (gFormSpeciesIdTables[data->currentmonId] != NULL)
        {
            struct PokemonDebugModifyArrows *modArrows = &data->modifyArrows;
            u8 formId = GetFormIdFromFormSpeciesId(data->currentmonId);
            if (gFormSpeciesIdTables[data->currentmonId][formId + 1] != FORM_SPECIES_END)
                modArrows->currValue = GetFormSpeciesId(data->currentmonId, formId + 1);
            else
                modArrows->currValue = gFormSpeciesIdTables[data->currentmonId][0];
                
            PrintDigitChars(data);
            UpdateBattlerValue(data);
            ReloadPokemonSprites(data);
            while (!(gMain.intrCheck & INTR_FLAG_VBLANK));
            PlaySE(SE_DEX_SCROLL);
        }
    }
    else if (JOY_NEW(SELECT_BUTTON) && SpeciesHasGenderDifference[data->currentmonId])
    {
        data->isFemale = !data->isFemale;
        PrintDigitChars(data);
        UpdateBattlerValue(data);
        ReloadPokemonSprites(data);
        while (!(gMain.intrCheck & INTR_FLAG_VBLANK));
        PlaySE(SE_DEX_SCROLL);
    }
    else if (JOY_NEW(DPAD_DOWN)) // || gMain.heldKeys & DPAD_DOWN)
    {
        if (TryMoveDigit(&data->modifyArrows, FALSE))
        {
            data->isFemale = FALSE;
            PrintDigitChars(data);
            UpdateBattlerValue(data);
            ReloadPokemonSprites(data);
            data->animIdBack = GetSpeciesBackAnimSet(data->currentmonId) + 1;
            data->animIdFront = sMonFrontAnimIdsTable[data->currentmonId - 1];
            UpdateMonAnimNames(taskId);
        }

        PlaySE(SE_DEX_SCROLL);

        while (!(gMain.intrCheck & INTR_FLAG_VBLANK));
    }
    else if (JOY_NEW(DPAD_UP)) // || gMain.heldKeys & DPAD_UP)
    {
        if (TryMoveDigit(&data->modifyArrows, TRUE))
        {
            data->isFemale = FALSE;
            PrintDigitChars(data);
            UpdateBattlerValue(data);
            ReloadPokemonSprites(data);
            data->animIdBack = GetSpeciesBackAnimSet(data->currentmonId) + 1;
            data->animIdFront = sMonFrontAnimIdsTable[data->currentmonId - 1];
            UpdateMonAnimNames(taskId);
        }

        PlaySE(SE_DEX_SCROLL);
    }
    else if (JOY_NEW(DPAD_LEFT)) // || gMain.heldKeys & DPAD_LEFT)
    {
        if (data->modifyArrows.currentDigit != 0)
        {
            data->modifyArrows.currentDigit--;
            gSprites[data->modifyArrows.arrowSpriteId[0]].x2 -= 6;
            gSprites[data->modifyArrows.arrowSpriteId[1]].x2 -= 6;
        }
    }
    else if (JOY_NEW(DPAD_RIGHT)) // || gMain.heldKeys & DPAD_RIGHT)
    {
        if (data->modifyArrows.currentDigit != (data->modifyArrows.maxDigits - 1))
        {
            data->modifyArrows.currentDigit++;
            gSprites[data->modifyArrows.arrowSpriteId[0]].x2 += 6;
            gSprites[data->modifyArrows.arrowSpriteId[1]].x2 += 6;
        }
    }
}

static void ReloadPokemonSprites(struct PokemonDebugMenu *data)
{
    s16 offset_x = 0; 
    s16 offset_y = 0;
    u16 species = data->currentmonId;
    const struct CompressedSpritePalette *palette;

    DestroySprite(&gSprites[data->frontspriteId]);
    DestroySprite(&gSprites[data->backspriteId]);
    DestroySprite(&gSprites[data->iconspriteId]);

    FreeMonSpritesGfx();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    FreeMonIconPalettes();

    AllocateMonSpritesGfx();
    LoadMonIconPalette(species);

    //Update instructions
    PrintInstructionsOnWindow(WIN_INSTRUCTIONS, data);

    //Palettes
    palette = GetMonSpritePalStructCustom(species, data->isFemale, data->isShiny);
    LoadCompressedSpritePalette(palette);
    //Front
    HandleLoadSpecialPokePicCustom(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites.ptr[1], species, 0, data->isFemale);
    BattleLoadOpponentMonSpriteGfxCustom(species, data->isFemale, data->isShiny, 1);
    SetMultiuseSpriteTemplateToPokemon(species, 1);
    gMultiuseSpriteTemplate.paletteTag = palette->tag;
    data->frontspriteId = CreateSprite(&gMultiuseSpriteTemplate, DEBUG_MON_X, DEBUG_MON_Y, 0);
    gSprites[data->frontspriteId].oam.paletteNum = 1;
    gSprites[data->frontspriteId].callback = SpriteCallbackDummy;
    gSprites[data->frontspriteId].oam.priority = 0;
    
    //Back
    HandleLoadSpecialPokePicCustom(&gMonBackPicTable[species], gMonSpritesGfxPtr->sprites.ptr[2], species, 0, data->isFemale);
    BattleLoadOpponentMonSpriteGfxCustom(species, data->isFemale, data->isShiny, 4);
    SetMultiuseSpriteTemplateToPokemon(species, 2);
    offset_y = gMonBackPicCoords[species].y_offset;
    data->backspriteId = CreateSprite(&gMultiuseSpriteTemplate, DEBUG_MON_BACK_X, DEBUG_MON_BACK_Y + offset_y, 0);
    gSprites[data->backspriteId].oam.paletteNum = 4;
    gSprites[data->backspriteId].callback = SpriteCallbackDummy;
    gSprites[data->backspriteId].oam.priority = 0;

    //Icon Sprite
    data->iconspriteId = CreateMonIconCustom(species, SpriteCB_MonIcon, DEBUG_ICON_X, DEBUG_ICON_Y, 4, data->isShiny, data->isFemale, data->isShiny);
    gSprites[data->iconspriteId].oam.priority = 0;
    
    //Modify Arrows
    LoadSpritePalette(&sSpritePalette_Arrow);
    data->modifyArrows.arrowSpriteId[0] = CreateSprite(&sSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X + (data->modifyArrows.currentDigit * 6), MODIFY_DIGITS_ARROW1_Y, 0);
    data->modifyArrows.arrowSpriteId[1] = CreateSprite(&sSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X + (data->modifyArrows.currentDigit * 6), MODIFY_DIGITS_ARROW2_Y, 0);
    gSprites[data->modifyArrows.arrowSpriteId[1]].animNum = 1;
}

static void Exit_Debug_Pokemon(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        struct PokemonDebugMenu *data = GetStructPtr(taskId);
        Free(data);
        FreeMonSpritesGfx();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
    }
}

#endif
