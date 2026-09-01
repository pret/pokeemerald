#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_gfx_sfx_util.h"
#include "battle_environment.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
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
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_animation.h"
#include "pokemon_sprite_visualizer.h"
#include "pokemon_icon.h"
#include "reset_rtc_screen.h"
#include "scanline_effect.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"

#include "constants/global.h"
#include "constants/battle_anim.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"

extern const struct BattleEnvironment gBattleEnvironmentInfo[BATTLE_ENVIRONMENT_COUNT];
extern const struct CompressedSpriteSheet gSpriteSheet_EnemyShadow;
extern const struct CompressedSpriteSheet gSpriteSheet_EnemyShadowsSized;
extern const struct SpriteTemplate gSpriteTemplate_EnemyShadow;
extern const struct SpritePalette sSpritePalettes_HealthBoxHealthBar[2];
extern const struct UCoords8 sBattlerCoords[][MAX_BATTLERS_COUNT] ;
static const u16 sBgColor[] = {RGB_WHITE};

static struct PokemonSpriteVisualizer *GetStructPtr(u8 taskId)
{
    u8 *taskDataPtr = (u8 *)(&gTasks[taskId].data[0]);

    return (struct PokemonSpriteVisualizer*)(T1_READ_PTR(taskDataPtr));
}

//BgTemplates
static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = BACKGROUND_1_CHAR_BASE,
        .mapBaseIndex = BACKGROUND_1_MAP_BASE,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
   {
        .bg = 3,
        .charBaseIndex = BACKGROUND_3_CHAR_BASE,
        .mapBaseIndex = BACKGROUND_3_MAP_BASE,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

#define TEXT_AREA_Y      14
#define TEXT_AREA_HEIGHT  6

//WindowTemplates
static const struct WindowTemplate sPokemonSpriteVisualizerWindowTemplate[] =
{
    [WIN_NAME_NUMBERS] =
    {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 12,
        .width = 15,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 1
    },
    [WIN_INSTRUCTIONS] =
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 15,
        .height = 4,
        .paletteNum = 0xF,
        .baseBlock = 1 + 30
    },
    [WIN_BOTTOM_LEFT] =
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = TEXT_AREA_Y,
        .width = 6,
        .height = TEXT_AREA_HEIGHT,
        .paletteNum = 0xF,
        .baseBlock = 1 + 30 + 60
    },
    [WIN_BOTTOM_RIGHT] =
    {
        .bg = 0,
        .tilemapLeft = 7,
        .tilemapTop = TEXT_AREA_Y,
        .width = 24,
        .height = TEXT_AREA_HEIGHT,
        .paletteNum = 0xF,
        .baseBlock = 1 + 30 + 60 + 36
    },
    [WIN_FOOTPRINT] =
    {
        .bg = 0,
        .tilemapLeft = 27,
        .tilemapTop = TEXT_AREA_Y,
        .width = 2,
        .height = 2,
        .paletteNum = 0xF,
        .baseBlock = 1 + 30 + 60 + 36 + 144,
    },
    DUMMY_WIN_TEMPLATE,
};

//Lookup tables
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

#define MOVE_BACKGROUND_NAME_LENGTH 28
const u8 gMoveBackgroundNames[BG_COUNT][MOVE_BACKGROUND_NAME_LENGTH] =
{
    [BG_NONE]                      = _("None"),
    [BG_DARK]                      = _("Dark"),
    [BG_GHOST]                     = _("Ghost"),
    [BG_PSYCHIC]                   = _("Psychic"),
    [BG_IMPACT_OPPONENT]           = _("Impact - Opponent"),
    [BG_IMPACT_PLAYER]             = _("Impact - Player"),
    [BG_IMPACT_CONTESTS]           = _("Impact - Contests"),
    [BG_DRILL]                     = _("Drill"),
    [BG_DRILL_CONTESTS]            = _("Drill - Contests"),
    [BG_HIGHSPEED_OPPONENT]        = _("High-Speed - Opponent"),
    [BG_HIGHSPEED_PLAYER]          = _("High-Speed - Player"),
    [BG_THUNDER]                   = _("Thunder"),
    [BG_GUILLOTINE_OPPONENT]       = _("Guillotine - Opponent"),
    [BG_GUILLOTINE_PLAYER]         = _("Guillotine - Player"),
    [BG_GUILLOTINE_CONTESTS]       = _("Guillotine - Contests"),
    [BG_ICE]                       = _("Ice"),
    [BG_COSMIC]                    = _("Cosmic"),
    [BG_IN_AIR]                    = _("In Air"),
    [BG_SKY]                       = _("Sky"),
    [BG_SKY_CONTESTS]              = _("Sky - Contests"),
    [BG_AURORA]                    = _("Aurora"),
    [BG_FISSURE]                   = _("Fissure"),
    [BG_BUG_OPPONENT]              = _("Bug - Opponent"),
    [BG_BUG_PLAYER]                = _("Bug - Player"),
    [BG_SOLAR_BEAM_OPPONENT]       = _("Solar Beam - Opponent"),
    [BG_SOLAR_BEAM_PLAYER]         = _("Solar Beam - Player"),
    [BG_SOLAR_BEAM_CONTESTS]       = _("Solar Beam - Contests"),
    [BG_MAGMA_STORM]               = _("Magma Storm"),
    [BG_GIGA_IMPACT_OPPONENT]      = _("Giga Impact - Opponent"),
    [BG_GIGA_IMPACT_PLAYER]        = _("Giga Impact - Player"),
    [BG_GIGA_IMPACT_CONTESTS]      = _("Giga Impact - Contests"),
    [BG_TRICK_ROOM]                = _("Trick Room"),
    [BG_ROCK_WRECKER]              = _("Rock Wrecker"),
    [BG_SPACIAL_REND_OPPONENT]     = _("Spacial Rend - Opponent"),
    [BG_SPACIAL_REND_PLAYER]       = _("Spacial Rend - Player"),
    [BG_DARK_VOID]                 = _("Dark Void"),
    [BG_WATER]                     = _("Water"),
    [BG_NIGHTMARE]                 = _("Nightmare"),
    [BG_LEAF_STORM]                = _("Leaf Storm"),
    [BG_FIRE]                      = _("Fire"),
    [BG_FIRE_2]                    = _("Fire 2"),
    [BG_WATER_2]                   = _("Water 2"),
    [BG_POISON]                    = _("Poison"),
    [BG_AEROBLAST]                 = _("Aeroblast"),
    [BG_HURRICANE]                 = _("Hurricane"),
    [BG_ELECTRIC_TERRAIN]          = _("Electric Terrain"),
    [BG_GRASSY_TERRAIN]            = _("Grassy Terrain"),
    [BG_MISTY_TERRAIN]             = _("Misty Terrain"),
    [BG_PSYCHIC_TERRAIN]           = _("Psychic Terrain"),
    [BG_FOCUS_BLAST]               = _("Focus Blast"),
    [BG_GUNK_SHOT]                 = _("Gunk Shot"),
    [BG_HYDRO_CANNON]              = _("Hydro Cannon"),
    [BG_WONDER_ROOM]               = _("Wonder Room"),
    [BG_MAGIC_ROOM]                = _("Magic Room"),
    [BG_HYPERSPACE_FURY]           = _("Hyperspace Fury"),
    [BG_BOLT_STRIKE]               = _("Bolt Strike"),
    [BG_ZMOVE_ACTIVATE]            = _("Z-Move Activate"),
    [BG_TECTONIC_RAGE]             = _("Tectonic Rage"),
    [BG_ROCK_FIELD_DAY]            = _("Rock Field - Day"),
    [BG_ROCK_FIELD_AFTERNOON]      = _("Rock Field - Afternoon"),
    [BG_ROCK_FIELD_NIGHT]          = _("Rock Field - Night"),
    [BG_ZMOVE_MOUNTAIN]            = _("Z-Move Mountain"),
    [BG_NEVERENDING_NIGHTMARE]     = _("Never-Ending Nightmare"),
    [BG_WATER_PULSE]               = _("Water Pulse"),
    [BG_INFERNO_OVERDRIVE]         = _("Inferno Overdrive"),
    [BG_BLOOM_DOOM]                = _("Bloom Doom"),
    [BG_SHATTERED_PSYCHE]          = _("Shattered Psyche"),
    [BG_TWINKLE_TACKLE]            = _("Twinkle Tackle"),
    [BG_BLACK_HOLE_ECLIPSE]        = _("Black Hole Eclipse"),
    [BG_SOULSTEALING_7STAR_STRIKE] = _("Soul-Stealing 7-Star Strike"),
    [BG_MALICIOUS_MOONSAULT]       = _("Malicious Moonsault"),
    [BG_CLANGOROUS_SOULBLAZE]      = _("Clangorous Soulblaze"),
    [BG_SNUGGLE_FOREVER]           = _("Snuggle Forever"),
    [BG_MAX_LIGHTNING]             = _("Max Lightning"),
    [BG_GARBAGE_FALLS]             = _("Garbage Falls"),
    [BG_HYPER_BEAM]                = _("Hyper Beam"),
    [BG_DYNAMAX_CANNON]            = _("Dynamax Cannon"),
    [BG_AURA_SPHERE]               = _("Aura Sphere"),
    [BG_STEEL_BEAM_OPPONENT]       = _("Steel Beam - Opponent"),
    [BG_STEEL_BEAM_PLAYER]         = _("Steel Beam - Player"),
    [BG_CHLOROBLAST]               = _("Chloroblast"),
    [BG_RAINBOW_PLAYER]            = _("Rainbow - Player"),
    [BG_RAINBOW_OPPONENT]          = _("Rainbow - Opponent"),
    [BG_SWAMP]                     = _("Swamp"),
};

const u8 sShadowSizeLabels[][4] =
{
    [SHADOW_SIZE_S]                 = _(" S"),
    [SHADOW_SIZE_M]                 = _(" M"),
    [SHADOW_SIZE_L]                 = _(" L"),
    [SHADOW_SIZE_XL_BATTLE_ONLY]    = _(" XL"),
};

//Function declarations
static void PrintDigitChars(struct PokemonSpriteVisualizer *data);
static void SetUpModifyArrows(struct PokemonSpriteVisualizer *data);
static void UpdateBattlerValue(struct PokemonSpriteVisualizer *data);
static void ValueToCharDigits(u8 *charDigits, u32 newValue, u8 maxDigits);
static bool32 TryMoveDigit(struct PokemonSpriteVisualizerModifyArrows *modArrows, bool32 moveUp);
static void CB2_PokemonSpriteVisualizerRunner(void);
static void ResetBGs_PokemonSpriteVisualizer(u16);
static void HandleInput_PokemonSpriteVisualizer(u8);
static void ReloadPokemonSprites(struct PokemonSpriteVisualizer *data);
static void Exit_PokemonSpriteVisualizer(u8);

//Text handling functions
static void UNUSED PadString(const u8 *src, u8 *dst)
{
    u32 i;

    for (i = 0; i < 17 && src[i] != EOS; i++)
        dst[i] = src[i];

    for (; i < 17; i++)
        dst[i] = CHAR_SPACE;

    dst[i] = EOS;
}

static const struct SubmenuText sSubmenuText[] =
{
    [SUBMENU_SPECIES] =
    {
        .instructions = COMPOUND_STRING("{START_BUTTON} Shiny\n{B_BUTTON} Exit  {A_BUTTON} Anims and BG$"),
        .instructionsGender = COMPOUND_STRING("{START_BUTTON} Shiny {SELECT_BUTTON} Gender\n{B_BUTTON} Exit  {A_BUTTON} Anims and BG$"),
    },

    [SUBMENU_ANIMS_BG] =
    {
        .instructions = COMPOUND_STRING("{START_BUTTON} Shiny\n{B_BUTTON} Back  {A_BUTTON} Sprite Coords$"),
        .instructionsGender = COMPOUND_STRING("{START_BUTTON} Shiny {SELECT_BUTTON} Gender\n{B_BUTTON} Back  {A_BUTTON} Sprite Coords$"),
    },

    [SUBMENU_SPRITE_COORDS] =
    {
#if B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE
        .instructions = COMPOUND_STRING("{START_BUTTON} Shiny\n{B_BUTTON} Back  {A_BUTTON} Shadow Coords$"),
        .instructionsGender = COMPOUND_STRING("{START_BUTTON} Shiny {SELECT_BUTTON} Gender\n{B_BUTTON} Back  {A_BUTTON} Shadow Coords$"),
#else
        .instructions = COMPOUND_STRING("{START_BUTTON} Shiny\n{B_BUTTON} Back  {A_BUTTON} Move BGs$"),
        .instructionsGender = COMPOUND_STRING("{START_BUTTON} Shiny {SELECT_BUTTON} Gender\n{B_BUTTON} Back  {A_BUTTON} Move BGs$"),
#endif
        .bottomLeft = COMPOUND_STRING("B coords:\nF coords:\nF elev:"),
    },

    [SUBMENU_SHADOW_COORDS] =
    {
#if B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE
        .instructions = COMPOUND_STRING("{START_BUTTON} Shiny\n{B_BUTTON} Back  {A_BUTTON} Move BGs$"),
        .instructionsGender = COMPOUND_STRING("{START_BUTTON} Shiny\n{B_BUTTON} Back  {A_BUTTON} Move BGs$"),
#else
        .instructions = COMPOUND_STRING("$"),
        .instructionsGender = COMPOUND_STRING("$"),
#endif
        .bottomLeft = COMPOUND_STRING("X coords:\nY coords:\nSize:"),
    },

    [SUBMENU_MOVE_BACKGROUNDS] =
    {
        .instructions = COMPOUND_STRING("{START_BUTTON} Shiny\n{B_BUTTON} Back$"),
        .instructionsGender = COMPOUND_STRING("{START_BUTTON} Shiny {SELECT_BUTTON} Gender\n{B_BUTTON} Back$"),
        .bottomLeft = COMPOUND_STRING("Move BG:"),
    },
};

static void PrintInstructionsOnWindow(struct PokemonSpriteVisualizer *data)
{
    u8 fontId = FONT_SMALL;
    u8 x = 2;
    enum Species species = IsSpeciesEnabled(data->modifyArrows.currValue) ? SanitizeSpeciesId(data->modifyArrows.currValue) : SPECIES_NONE;

    u8 textBottom[] = _("BACK:\nFRONT:\nBG:$");
    u8 textBottomForms[] = _("BACK:\nFRONT:\nBG:\nFORMS:$");

    u8 textL[] = _("{L_BUTTON}");
    u8 textR[] = _("{R_BUTTON}");

    //Instruction window
    FillWindowPixelBuffer(WIN_INSTRUCTIONS, 0x11);

    if (SpeciesHasGenderDifferences(species))
        AddTextPrinterParameterized(WIN_INSTRUCTIONS, fontId, sSubmenuText[data->currentSubmenu].instructionsGender, x, 0, 0, NULL);
    else
        AddTextPrinterParameterized(WIN_INSTRUCTIONS, fontId, sSubmenuText[data->currentSubmenu].instructions, x, 0, 0, NULL);

    CopyWindowToVram(WIN_INSTRUCTIONS, COPYWIN_FULL);

    //Bottom left text
    FillWindowPixelBuffer(WIN_BOTTOM_LEFT, PIXEL_FILL(0));
    if ((data->currentSubmenu == SUBMENU_SPECIES) || (data->currentSubmenu == SUBMENU_ANIMS_BG))
    {
        AddTextPrinterParameterized(WIN_BOTTOM_LEFT, fontId, textL, 30, 0, 0, NULL);
        AddTextPrinterParameterized(WIN_BOTTOM_LEFT, fontId, textR, 30, 12, 0, NULL);
        if (GetSpeciesFormTable(species) != NULL)
            AddTextPrinterParameterized(WIN_BOTTOM_LEFT, fontId, textBottomForms, 0, 0, 0, NULL);
        else
            AddTextPrinterParameterized(WIN_BOTTOM_LEFT, fontId, textBottom, 0, 0, 0, NULL);
    }
    else
        AddTextPrinterParameterized(WIN_BOTTOM_LEFT, fontId, sSubmenuText[data->currentSubmenu].bottomLeft, 0, 0, 0, NULL);
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
    u8 *taskDataPtr = (u8 *)(&gTasks[taskId].data[0]);

    taskDataPtr[0] = structPtr >> 0;
    taskDataPtr[1] = structPtr >> 8;
    taskDataPtr[2] = structPtr >> 16;
    taskDataPtr[3] = structPtr >> 24;
}

//Digit and arrow functions
#define VAL_U16     0
static void PrintDigitChars(struct PokemonSpriteVisualizer *data)
{
    s32 i;
    enum Species species = IsSpeciesEnabled(data->modifyArrows.currValue) ? data->modifyArrows.currValue : SPECIES_NONE;

    u8 text[MODIFY_DIGITS_MAX + POKEMON_NAME_LENGTH + 8];

    for (i = 0; i < data->modifyArrows.maxDigits; i++)
        text[i] = data->modifyArrows.charDigits[i];

    text[i++] = CHAR_SPACE;
    text[i++] = CHAR_HYPHEN;

    if (SpeciesHasGenderDifferences(species))
    {
        if (data->isFemale)
            text[i++] = CHAR_FEMALE;
        else
            text[i++] = CHAR_MALE;
        text[i++] = CHAR_HYPHEN;
    }

    text[i++] = CHAR_SPACE;
    StringCopy(&text[i], GetSpeciesName(species));

    FillWindowPixelBuffer(WIN_NAME_NUMBERS, 0x11);
    AddTextPrinterParameterized(WIN_NAME_NUMBERS, FONT_NORMAL, text, 6, 0, 0, NULL);
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

static void SetArrowInvisibility(struct PokemonSpriteVisualizer *data)
{
    switch (data->currentSubmenu)
    {
    case SUBMENU_SPECIES:
        gSprites[data->modifyArrows.arrowSpriteId[0]].invisible = FALSE;
        gSprites[data->modifyArrows.arrowSpriteId[1]].invisible = FALSE;
        gSprites[data->optionArrows.arrowSpriteId[0]].invisible = TRUE;
        gSprites[data->yPosModifyArrows.arrowSpriteId[0]].invisible = TRUE;
        break;
    case SUBMENU_ANIMS_BG:
    case SUBMENU_MOVE_BACKGROUNDS:
        gSprites[data->modifyArrows.arrowSpriteId[0]].invisible = TRUE;
        gSprites[data->modifyArrows.arrowSpriteId[1]].invisible = TRUE;
        gSprites[data->optionArrows.arrowSpriteId[0]].invisible = FALSE;
        gSprites[data->yPosModifyArrows.arrowSpriteId[0]].invisible = TRUE;
        break;
    case SUBMENU_SPRITE_COORDS:
    case SUBMENU_SHADOW_COORDS:
        gSprites[data->modifyArrows.arrowSpriteId[0]].invisible = TRUE;
        gSprites[data->modifyArrows.arrowSpriteId[1]].invisible = TRUE;
        gSprites[data->optionArrows.arrowSpriteId[0]].invisible = TRUE;
        gSprites[data->yPosModifyArrows.arrowSpriteId[0]].invisible = FALSE;
        break;
    }
}

static void SetUpModifyArrows(struct PokemonSpriteVisualizer *data)
{
    LoadSpritePalette(&gSpritePalette_Arrow);
    data->modifyArrows.arrowSpriteId[0] = CreateSprite(&gSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X, MODIFY_DIGITS_ARROW1_Y, 0);
    data->modifyArrows.arrowSpriteId[1] = CreateSprite(&gSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X, MODIFY_DIGITS_ARROW2_Y, 0);
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

static void SetUpOptionArrows(struct PokemonSpriteVisualizer *data)
{
    LoadSpritePalette(&gSpritePalette_Arrow);
    data->optionArrows.arrowSpriteId[0] = CreateSprite(&gSpriteTemplate_Arrow, OPTIONS_ARROW_1_X, OPTIONS_ARROW_Y, 0);
    gSprites[data->optionArrows.arrowSpriteId[0]].animNum = 2;

    data->optionArrows.currentDigit = 0;

    gSprites[data->optionArrows.arrowSpriteId[0]].invisible = TRUE;
}

static void SetUpYPosModifyArrows(struct PokemonSpriteVisualizer *data)
{
    LoadSpritePalette(&gSpritePalette_Arrow);
    data->yPosModifyArrows.arrowSpriteId[0] = CreateSprite(&gSpriteTemplate_Arrow, OPTIONS_ARROW_1_X, OPTIONS_ARROW_Y, 0);
    gSprites[data->yPosModifyArrows.arrowSpriteId[0]].animNum = 2;

    data->yPosModifyArrows.currentDigit = 0;

    gSprites[data->yPosModifyArrows.arrowSpriteId[0]].invisible = TRUE;
}

static bool32 TryMoveDigit(struct PokemonSpriteVisualizerModifyArrows *modArrows, bool32 moveUp)
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

static void UpdateBattlerValue(struct PokemonSpriteVisualizer *data)
{
    switch (data->modifyArrows.typeOfVal)
    {
    case VAL_U16:
        *(u16*)(data->modifyArrows.modifiedValPtr) = data->modifyArrows.currValue;
        break;
    }
}

static void BattleLoadOpponentMonSpriteGfxCustom(enum Species species, bool8 isFemale, bool8 isShiny, enum BattlerId battler)
{
    const u16 *palette = GetMonSpritePalFromSpecies(species, isShiny, isFemale);
    u16 paletteOffset = OBJ_PLTT_ID(battler);

    LoadPalette(palette, paletteOffset, PLTT_SIZE_4BPP);
    LoadPalette(palette, BG_PLTT_ID(8) + BG_PLTT_ID(battler), PLTT_SIZE_4BPP);
}

static void SetConstSpriteValues(struct PokemonSpriteVisualizer *data)
{
    enum Species species = IsSpeciesEnabled(data->currentmonId) ? SanitizeSpeciesId(data->currentmonId) : SPECIES_NONE;
    data->constSpriteValues.frontPicCoords = gSpeciesInfo[species].frontPicYOffset;
    data->constSpriteValues.frontElevation = gSpeciesInfo[species].enemyMonElevation;
    data->constSpriteValues.backPicCoords = gSpeciesInfo[species].backPicYOffset;
}

static void ResetOffsetSpriteValues(struct PokemonSpriteVisualizer *data)
{
    data->offsetsSpriteValues.offset_back_picCoords = 0;
    data->offsetsSpriteValues.offset_front_picCoords = 0;
    data->offsetsSpriteValues.offset_front_elevation = 0;
}

static void ResetShadowSettings(struct PokemonSpriteVisualizer *data)
{
    if (B_ENEMY_MON_SHADOW_STYLE <= GEN_3 || P_GBA_STYLE_SPECIES_GFX == TRUE)
        return;
    enum Species species = IsSpeciesEnabled(data->currentmonId) ? SanitizeSpeciesId(data->currentmonId) : SPECIES_NONE;
    data->shadowSettings.definedX = gSpeciesInfo[species].enemyShadowXOffset;
    data->shadowSettings.definedY = gSpeciesInfo[species].enemyShadowYOffset;
    data->shadowSettings.definedSize = gSpeciesInfo[species].enemyShadowSize;

    data->shadowSettings.overrideX = data->shadowSettings.definedX;
    data->shadowSettings.overrideY = data->shadowSettings.definedY;
    data->shadowSettings.overrideSize = data->shadowSettings.definedSize;
}

static u8 GetBattlerSpriteFinal_YCustom(enum Species species, s8 offset_picCoords, s8 offset_elevation)
{
    u16 offset;
    u8 y;
    species = SanitizeSpeciesId(species);

    //FrontPicCoords
    offset = gSpeciesInfo[species].frontPicYOffset + offset_picCoords;

    //Elevation
    offset -= gSpeciesInfo[species].enemyMonElevation + offset_elevation;

    //Main position
    y = offset + sBattlerCoords[0][1].y;

    if (y > DISPLAY_HEIGHT - MON_PIC_HEIGHT + 8)
        y = DISPLAY_HEIGHT - MON_PIC_HEIGHT + 8;

    return y;
}

static void UpdateShadowSpriteInvisible(struct PokemonSpriteVisualizer *data)
{
    if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
        return;

    if (data->constSpriteValues.frontElevation + data->offsetsSpriteValues.offset_front_elevation == 0)
        gSprites[data->frontShadowSpriteIdPrimary].invisible = TRUE;
    else
        gSprites[data->frontShadowSpriteIdPrimary].invisible = FALSE;
}

#define tFrontSpriteId  data[0]
#define tSpriteSide     data[1]
#define tShadowXOffset  data[2]
#define tShadowYOffset  data[3]

#define SPRITE_SIDE_LEFT    0
#define SPRITE_SIDE_RIGHT   1


static void SpriteCB_EnemyShadowCustom(struct Sprite *shadowSprite)
{
    u8 frontSpriteId = shadowSprite->tFrontSpriteId;
    struct Sprite *battlerSprite = &gSprites[frontSpriteId];

    s8 xOffset = 0, yOffset = 0;
    if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
    {
        xOffset = shadowSprite->tShadowXOffset + (shadowSprite->tSpriteSide == SPRITE_SIDE_LEFT ? -16 : 16);
        yOffset = shadowSprite->tShadowYOffset + 16;

        shadowSprite->y = battlerSprite->y + yOffset;
    }

    shadowSprite->x = battlerSprite->x + xOffset;
    shadowSprite->x2 = battlerSprite->x2;
}

static void SpriteCB_Follower(struct Sprite *sprite)
{
    if (sprite->data[3] == 0)
    {
        sprite->data[3] = 120;
        switch (sprite->animNum)
        {
        case 4:
            StartSpriteAnim(sprite, GetMoveDirectionAnimNum(DIR_NORTH));
            break;
        case 5:
            StartSpriteAnim(sprite, GetMoveDirectionAnimNum(DIR_WEST));
            break;
        case 6:
            StartSpriteAnim(sprite, GetMoveDirectionAnimNum(DIR_EAST));
            break;
        default:
        case 7:
            StartSpriteAnim(sprite, GetMoveDirectionAnimNum(DIR_SOUTH));
            break;
        }
    }
    else
    {
        sprite->data[3]--;
    }
}

static void LoadAndCreateEnemyShadowSpriteCustom(struct PokemonSpriteVisualizer *data)
{
    bool8 invisible = FALSE;
    enum Species species = IsSpeciesEnabled(data->currentmonId) ? SanitizeSpeciesId(data->currentmonId) : SPECIES_NONE;

    if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
    {
        invisible = gSpeciesInfo[species].suppressEnemyShadow;

        LoadCompressedSpriteSheet(&gSpriteSheet_EnemyShadowsSized);
        LoadSpritePalette(&sSpritePalettes_HealthBoxHealthBar[0]);
        u8 x = sBattlerCoords[0][1].x;
        u8 y = sBattlerCoords[0][1].y;
        s8 xOffset = data->shadowSettings.overrideX;
        s8 yOffset = data->shadowSettings.overrideY;
        u8 size = data->shadowSettings.overrideSize;

        data->frontShadowSpriteIdPrimary = CreateSprite(&gSpriteTemplate_EnemyShadow, x, y, 0xC8);
        gSprites[data->frontShadowSpriteIdPrimary].tFrontSpriteId = data->frontspriteId;
        gSprites[data->frontShadowSpriteIdPrimary].tSpriteSide = SPRITE_SIDE_LEFT;
        gSprites[data->frontShadowSpriteIdPrimary].tShadowXOffset = (u8)xOffset;
        gSprites[data->frontShadowSpriteIdPrimary].tShadowYOffset = (u8)yOffset;
        gSprites[data->frontShadowSpriteIdPrimary].callback = SpriteCB_EnemyShadowCustom;
        gSprites[data->frontShadowSpriteIdPrimary].oam.priority = 0;
        gSprites[data->frontShadowSpriteIdPrimary].oam.tileNum += 8 * size;
        gSprites[data->frontShadowSpriteIdPrimary].invisible = invisible;

        data->frontShadowSpriteIdSecondary = CreateSprite(&gSpriteTemplate_EnemyShadow, x, y, 0xC8);
        gSprites[data->frontShadowSpriteIdSecondary].tFrontSpriteId = data->frontspriteId;
        gSprites[data->frontShadowSpriteIdSecondary].tSpriteSide = SPRITE_SIDE_RIGHT;
        gSprites[data->frontShadowSpriteIdSecondary].tShadowXOffset = (u8)xOffset;
        gSprites[data->frontShadowSpriteIdSecondary].tShadowYOffset = (u8)yOffset;
        gSprites[data->frontShadowSpriteIdSecondary].callback = SpriteCB_EnemyShadowCustom;
        gSprites[data->frontShadowSpriteIdSecondary].oam.priority = 0;
        gSprites[data->frontShadowSpriteIdSecondary].oam.tileNum += (8 * size) + 4;
        gSprites[data->frontShadowSpriteIdSecondary].invisible = invisible;
    }
    else
    {
        if (gSpeciesInfo[species].enemyMonElevation == 0)
            invisible = TRUE;

        LoadCompressedSpriteSheet(&gSpriteSheet_EnemyShadow);
        LoadSpritePalette(&sSpritePalettes_HealthBoxHealthBar[0]);
        u8 x = sBattlerCoords[0][1].x;
        u8 y = sBattlerCoords[0][1].y;

        data->frontShadowSpriteIdPrimary = CreateSprite(&gSpriteTemplate_EnemyShadow, x, y + 29, 0xC8);
        gSprites[data->frontShadowSpriteIdPrimary].data[0] = data->frontspriteId;

        gSprites[data->frontShadowSpriteIdPrimary].callback = SpriteCB_EnemyShadowCustom;
        gSprites[data->frontShadowSpriteIdPrimary].oam.priority = 0;
        gSprites[data->frontShadowSpriteIdPrimary].invisible = invisible;
    }
}

//Battle background functions
static void LoadBattleBg(enum BattleEnvironments battleEnvironment)
{
    DecompressDataWithHeaderVram(gBattleEnvironmentInfo[battleEnvironment].background.tileset, (void *)(BG_CHAR_ADDR(BACKGROUND_3_CHAR_BASE)));
    DecompressDataWithHeaderVram(gBattleEnvironmentInfo[battleEnvironment].background.tilemap, (void *)(BG_SCREEN_ADDR(BACKGROUND_3_MAP_BASE)));
    LoadPalette(gBattleEnvironmentInfo[battleEnvironment].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
}

static void PrintBattleBgName(u8 battleEnvironment)
{
    u8 fontId = FONT_SMALL;
    FillWindowPixelRect(WIN_BOTTOM_RIGHT, PIXEL_FILL(0), 0, 24, 80, gFonts[fontId].maxLetterHeight);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, gBattleEnvironmentInfo[battleEnvironment].name, 0, 24, 0, NULL);
}

static void UpdateBattleBg(u8 taskId, bool8 increment)
{
    struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);

    if (increment) {
        data->battleEnvironment = (data->battleEnvironment + 1) % (BATTLE_ENVIRONMENT_RAYQUAZA + 1); // Can use BATTLE_ENVIRONMENT_COUNT once the remaining environments have sprites
    }
    else
    {
        if (data->battleEnvironment == BATTLE_ENVIRONMENT_GRASS)
            data->battleEnvironment = BATTLE_ENVIRONMENT_RAYQUAZA;
        else
            data->battleEnvironment -= 1;
    }

    PrintBattleBgName(data->battleEnvironment);
    LoadBattleBg(data->battleEnvironment);
}

//Move background functions
static void LoadMoveBackground(u8 moveBackground)
{
    DecompressDataWithHeaderVram(gBattleAnimBackgroundTable[moveBackground].tilemap, (void *)BG_SCREEN_ADDR(BACKGROUND_3_MAP_BASE));
    DecompressDataWithHeaderVram(gBattleAnimBackgroundTable[moveBackground].image, (void *)BG_CHAR_ADDR(BACKGROUND_3_CHAR_BASE));
    LoadPalette(gBattleAnimBackgroundTable[moveBackground].palette, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
    //Fill text area with white to avoid overlap with backgrounds
    CpuFill32(0x11111111, (void *)(BG_CHAR_ADDR(BACKGROUND_1_CHAR_BASE) + TILE_OFFSET_4BPP(1)), TILE_SIZE_4BPP);
    CpuFill32(0xF001F001, (void *)(BG_SCREEN_ADDR(BACKGROUND_1_MAP_BASE) + sizeof(u16) * 32 * TEXT_AREA_Y), sizeof(u16) * 32 * TEXT_AREA_HEIGHT);
}

static void PrintMoveBackgroundName(u8 moveBackground)
{
    FillWindowPixelBuffer(WIN_BOTTOM_RIGHT, PIXEL_FILL(0));
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, FONT_SMALL, gMoveBackgroundNames[moveBackground], 0, 0, 0, NULL);
}

static void UpdateMoveBackground(u8 taskId, bool8 increment)
{
    struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);

    if (increment)
    {
        data->moveBackground = (data->moveBackground + 1) % BG_COUNT;
        if (data->moveBackground == BG_NONE)
            data->moveBackground = BG_DARK;
    }
    else
    {
        data->moveBackground -= 1;
        if (data->moveBackground == BG_NONE)
            data->moveBackground = BG_SWAMP;
    }

    PrintMoveBackgroundName(data->moveBackground);
    LoadMoveBackground(data->moveBackground);
}

static void DrawFollowerSprite(struct PokemonSpriteVisualizer *data)
{
    if (!OW_POKEMON_OBJECT_EVENTS)
        return;

    enum Species species = IsSpeciesEnabled(data->currentmonId) ? SanitizeSpeciesId(data->currentmonId) : SPECIES_NONE;
    u16 graphicsId = species + OBJ_EVENT_MON;
    if (data->isShiny)
        graphicsId += OBJ_EVENT_MON_SHINY;
    if (data->isFemale)
        graphicsId += OBJ_EVENT_MON_FEMALE;
    data->followerspriteId = CreateObjectGraphicsSprite(graphicsId,
                                                        SpriteCB_Follower,
                                                        VISUALIZER_FOLLOWER_X,
                                                        VISUALIZER_FOLLOWER_Y,
                                                        0);
    gSprites[data->followerspriteId].oam.priority = 0;

    const struct ObjectEventGraphicsInfo *graphicsInfo = SpeciesToGraphicsInfo(species, data->isShiny, data->isFemale);
    gSprites[data->followerspriteId].oam.shape = graphicsInfo->oam->shape;
    gSprites[data->followerspriteId].oam.size = graphicsInfo->oam->size;
    gSprites[data->followerspriteId].images = graphicsInfo->images;
    gSprites[data->followerspriteId].anims = graphicsInfo->anims;
    gSprites[data->followerspriteId].subspriteTables = graphicsInfo->subspriteTables;
}

// *******************************
// Main functions
static void UpdateMonAnimNames(u8 taskId)
{
    struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);
    u8 frontAnim = data->animIdFront;
    u8 backAnim = data->animIdBack;
    u8 text[34];
    u8 fontId = FONT_SMALL;
    u8 textNum[4];

    FillWindowPixelBuffer(WIN_BOTTOM_RIGHT, PIXEL_FILL(0));

    //Back
    StringCopy(text, gBackAnimNames[backAnim]);
    ConvertIntToDecimalStringN(textNum, backAnim, STR_CONV_MODE_LEADING_ZEROS, 3);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textNum, 0, 0, 0, NULL);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, 18, 0, 0, NULL);
    //Front
    StringCopy(text, gFrontAnimNames[frontAnim]);
    ConvertIntToDecimalStringN(textNum, frontAnim, STR_CONV_MODE_LEADING_ZEROS, 3);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textNum, 0, 12, 0, NULL);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, 18, 12, 0, NULL);

    PrintBattleBgName(data->battleEnvironment);
}

static void UpdateYPosOffsetText(struct PokemonSpriteVisualizer *data)
{
    u8 text[34];
    u8 fontId = FONT_SMALL;
    u8 textConst[] = _("const val:");
    u8 textNew[] = _("new val:");
    u8 x_const_val = 50;
    u8 x_new_text = 70;
    u8 x_new_val = 110;
    u8 y = 0;

    u8 backPicCoords    = data->constSpriteValues.backPicCoords;
    u8 frontPicCoords   = data->constSpriteValues.frontPicCoords;
    u8 frontElevation   = data->constSpriteValues.frontElevation;

    s8 offset_back_picCoords    = data->offsetsSpriteValues.offset_back_picCoords;
    s8 offset_front_picCoords   = data->offsetsSpriteValues.offset_front_picCoords;
    s8 offset_front_elevation   = data->offsetsSpriteValues.offset_front_elevation;

    u8 newBackPicCoords    = backPicCoords   +  offset_back_picCoords;
    u8 newFrontPicCoords   = frontPicCoords  +  offset_front_picCoords;
    u8 newFrontElevation   = frontElevation  +  offset_front_elevation;

    FillWindowPixelBuffer(WIN_BOTTOM_RIGHT, PIXEL_FILL(0));

    //Back
    y = 0;
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textConst, 0, y, 0, NULL);
    ConvertIntToDecimalStringN(text, backPicCoords , STR_CONV_MODE_LEFT_ALIGN, 2);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, x_const_val, y, 0, NULL);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textNew, x_new_text, y, 0, NULL);
    ConvertIntToDecimalStringN(text, newBackPicCoords , STR_CONV_MODE_LEFT_ALIGN, 2);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, x_new_val, y, 0, NULL);
    //Front picCoords
    y = 12;
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textConst, 0, y, 0, NULL);
    ConvertIntToDecimalStringN(text, frontPicCoords , STR_CONV_MODE_LEFT_ALIGN, 2);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, x_const_val, y, 0, NULL);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textNew, x_new_text, y, 0, NULL);
    ConvertIntToDecimalStringN(text, newFrontPicCoords , STR_CONV_MODE_LEFT_ALIGN, 2);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, x_new_val, y, 0, NULL);
    //Front elevation
    y = 24;
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textConst, 0, y, 0, NULL);
    ConvertIntToDecimalStringN(text, frontElevation , STR_CONV_MODE_LEFT_ALIGN, 2);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, x_const_val, y, 0, NULL);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textNew, x_new_text, y, 0, NULL);
    ConvertIntToDecimalStringN(text, newFrontElevation , STR_CONV_MODE_LEFT_ALIGN, 2);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, x_new_val, y, 0, NULL);
}

#define ABS(val)    (val < 0 ? val * -1 : val)
#define ITOA_SIGNED(buf, val)                                                       \
{                                                                                   \
    buf[0] = val < 0 ? CHAR_HYPHEN : CHAR_SPACER;                                   \
    ConvertIntToDecimalStringN(&text[1], ABS(val), STR_CONV_MODE_LEFT_ALIGN, 2);    \
}

static void UpdateShadowSettingsText(struct PokemonSpriteVisualizer *data)
{
    if (B_ENEMY_MON_SHADOW_STYLE <= GEN_3 || P_GBA_STYLE_SPECIES_GFX == TRUE)
        return;

    u8 text[16];
    u8 fontId = FONT_SMALL;
    u8 textConst[] = _("const val:");
    u8 textNew[] = _("new val:");
    u8 x_const_val = 50;
    u8 x_new_text = 70;
    u8 x_new_val = 110;
    u8 y = 0;

    FillWindowPixelBuffer(WIN_BOTTOM_RIGHT, PIXEL_FILL(0));

    // X offset
    y = 0;
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textConst, 0, y, 0, NULL);
    ITOA_SIGNED(text, data->shadowSettings.definedX);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, x_const_val, y, 0, NULL);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textNew, x_new_text, y, 0, NULL);
    ITOA_SIGNED(text, data->shadowSettings.overrideX);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, x_new_val, y, 0, NULL);

    // Y offset
    y = 12;
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textConst, 0, y, 0, NULL);
    ITOA_SIGNED(text, data->shadowSettings.definedY);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, x_const_val, y, 0, NULL);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textNew, x_new_text, y, 0, NULL);
    ITOA_SIGNED(text, data->shadowSettings.overrideY);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, text, x_new_val, y, 0, NULL);

    // Shadow Size
    y = 24;
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textConst, 0, y, 0, NULL);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, sShadowSizeLabels[data->shadowSettings.definedSize], x_const_val, y, 0, NULL);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, textNew, x_new_text, y, 0, NULL);
    AddTextPrinterParameterized(WIN_BOTTOM_RIGHT, fontId, sShadowSizeLabels[data->shadowSettings.overrideSize], x_new_val, y, 0, NULL);
}

static void ResetPokemonSpriteVisualizerWindows(void)
{
    u8 i;

    FreeAllWindowBuffers();
    InitWindows(sPokemonSpriteVisualizerWindowTemplate);

    for (i = 0; i < WIN_END + 1; i++)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
}

#define MALE_PERSONALITY 0xFE
#define FEMALE_PERSONALITY 0X0

void CB2_Pokemon_Sprite_Visualizer(void)
{
    u8 taskId;
    const u16 *palette;
    struct PokemonSpriteVisualizer *data;
    enum Species species;
    s16 offset_y;
    u8 front_x = sBattlerCoords[0][1].x;
    u8 front_y;

    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        FreeMonSpritesGfx();
        ResetBGs_PokemonSpriteVisualizer(0);
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
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        LoadPalette(GetTextWindowPalette(0), BG_PLTT_ID(15), 2 * PLTT_SIZE_4BPP);

        FillBgTilemapBufferRect(0, 0, 0, 0, 32, 20, 15);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        LoadBattleBg(BATTLE_ENVIRONMENT_GRASS);

        gMain.state++;
        break;
    case 2:
        ResetPokemonSpriteVisualizerWindows();
        gMain.state++;
        break;
    case 3:
        AllocateMonSpritesGfx();

        LoadPalette(sBgColor, BG_PLTT_ID(0), 2);
        LoadMonIconPalette(SPECIES_BULBASAUR);

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);

        //input task handler
        taskId = CreateTask(HandleInput_PokemonSpriteVisualizer, 0);

        data = AllocZeroed(sizeof(struct PokemonSpriteVisualizer));
        SetStructPtr(taskId, data);

        data->currentmonId = SPECIES_BULBASAUR;
        species = IsSpeciesEnabled(data->currentmonId) ? SanitizeSpeciesId(data->currentmonId) : SPECIES_NONE;

        //Print instructions
        PrintInstructionsOnWindow(data);

        //Palettes
        palette = GetMonSpritePalFromSpecies(species, data->isShiny, data->isFemale);
        LoadSpritePaletteWithTag(palette, species);
        //Front
        HandleLoadSpecialPokePic(TRUE, gMonSpritesGfxPtr->spritesGfx[1], species, (data->isFemale ? FEMALE_PERSONALITY : MALE_PERSONALITY));
        BattleLoadOpponentMonSpriteGfxCustom(species, data->isFemale, data->isShiny, 1);
        SetMultiuseSpriteTemplateToPokemon(species, 1);
        gMultiuseSpriteTemplate.paletteTag = species;
        front_y = GetBattlerSpriteFinal_YCustom(species, 0, 0);
        data->frontspriteId = CreateSprite(&gMultiuseSpriteTemplate, front_x, front_y, 0);
        gSprites[data->frontspriteId].oam.paletteNum = 1;
        gSprites[data->frontspriteId].callback = SpriteCallbackDummy;
        gSprites[data->frontspriteId].oam.priority = 0;
        //Front Shadow
        LoadAndCreateEnemyShadowSpriteCustom(data);

        //Back
        HandleLoadSpecialPokePic(FALSE, gMonSpritesGfxPtr->spritesGfx[2], species, (data->isFemale ? FEMALE_PERSONALITY : MALE_PERSONALITY));
        BattleLoadOpponentMonSpriteGfxCustom(species, data->isFemale, data->isShiny, 5);
        SetMultiuseSpriteTemplateToPokemon(species, 2);
        offset_y = gSpeciesInfo[species].backPicYOffset;
        data->backspriteId = CreateSprite(&gMultiuseSpriteTemplate, VISUALIZER_MON_BACK_X, VISUALIZER_MON_BACK_Y + offset_y, 0);
        gSprites[data->backspriteId].oam.paletteNum = 5;
        gSprites[data->backspriteId].callback = SpriteCallbackDummy;
        gSprites[data->backspriteId].oam.priority = 0;

        //Icon Sprite
        data->iconspriteId = CreateMonIcon(species, SpriteCB_MonIcon, VISUALIZER_ICON_X, VISUALIZER_ICON_Y, 4, (data->isFemale ? FEMALE_PERSONALITY : MALE_PERSONALITY));
        gSprites[data->iconspriteId].oam.priority = 0;

        //Follower Sprite
        DrawFollowerSprite(data);

        //Modify Arrows
        SetUpModifyArrows(data);
        PrintDigitChars(data);

        //Option Arrow
        SetUpOptionArrows(data);

        //Modify Y Pos Arrow
        SetUpYPosModifyArrows(data);

        //Anim names
        data->animIdBack = GetSpeciesBackAnimSet(species) + 1;
        data->animIdFront = gSpeciesInfo[species].frontAnimId;
        UpdateMonAnimNames(taskId);

        //Footprint
        DrawFootprint(WIN_FOOTPRINT, species);
        CopyWindowToVram(WIN_FOOTPRINT, COPYWIN_GFX);

        gMain.state++;
        break;
    case 4:
        EnableInterrupts(1);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(CB2_PokemonSpriteVisualizerRunner);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x80);
        break;
    }
}

static void CB2_PokemonSpriteVisualizerRunner(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void ResetBGs_PokemonSpriteVisualizer(u16 a)
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

static void ApplyOffsetSpriteValues(struct PokemonSpriteVisualizer *data)
{
    enum Species species = IsSpeciesEnabled(data->currentmonId) ? SanitizeSpeciesId(data->currentmonId) : SPECIES_NONE;
    //Back
    gSprites[data->backspriteId].y = VISUALIZER_MON_BACK_Y + gSpeciesInfo[species].backPicYOffset + data->offsetsSpriteValues.offset_back_picCoords;
    //Front
    gSprites[data->frontspriteId].y = GetBattlerSpriteFinal_YCustom(species, data->offsetsSpriteValues.offset_front_picCoords, data->offsetsSpriteValues.offset_front_elevation);

    if (data->currentSubmenu == SUBMENU_SPRITE_COORDS)
        UpdateShadowSpriteInvisible(data);
}

static void UpdateSubmenuOneOptionValue(u8 taskId, bool8 increment)
{
    struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);
    enum Species species = IsSpeciesEnabled(data->currentmonId) ? SanitizeSpeciesId(data->currentmonId) : SPECIES_NONE;
    u8 option = data->submenuYpos[1];

    switch (option)
    {
    case 0:
        if (increment)
        {
            if (data->animIdBack >= BACK_ANIM_SHAKE_GLOW_BLUE)
                data->animIdBack = 1;
            else
                data->animIdBack += 1;
        }
        else
        {
            if (data->animIdBack <= 1)
                data->animIdBack = BACK_ANIM_SHAKE_GLOW_BLUE;
            else
                data->animIdBack -= 1;
        }
        UpdateMonAnimNames(taskId);
        break;
    case 1:
        if (increment)
            data->animIdFront = (data->animIdFront + 1) % ANIM_COUNT;
        else
        {
            if (data->animIdFront == ANIM_V_SQUISH_AND_BOUNCE)
                data->animIdFront = ANIM_SHAKE_GLOW_PURPLE_SLOW;
            else
                data->animIdFront -= 1;
        }
        UpdateMonAnimNames(taskId);
        break;
    case 2:
        UpdateBattleBg(taskId, increment);
        break;
    case 3:
        if (GetSpeciesFormTable(species) != NULL)
        {
            struct PokemonSpriteVisualizerModifyArrows *modArrows = &data->modifyArrows;
            u8 formId = GetFormIdFromFormSpeciesId(species);
            const u16 *formTable = GetSpeciesFormTable(species);
            if (increment)
            {
                if (formTable[formId + 1] != FORM_SPECIES_END)
                    modArrows->currValue = GetFormSpeciesId(species, formId + 1);
                else
                    modArrows->currValue = formTable[0];
            }
            else
            {
                if (formTable[formId] == formTable[0])
                {
                    u8 lastForm;
                    for (lastForm = 0; formTable[lastForm] != FORM_SPECIES_END; lastForm++)
                    {
                        if (formTable[lastForm + 1] == FORM_SPECIES_END)
                            break;
                    }
                    modArrows->currValue = formTable[lastForm];
                }
                else
                    modArrows->currValue = GetFormSpeciesId(species, formId - 1);
            }
            data->animIdBack = GetSpeciesBackAnimSet(modArrows->currValue) + 1;
            data->animIdFront = gSpeciesInfo[modArrows->currValue].frontAnimId;
            UpdateMonAnimNames(taskId);
            ResetOffsetSpriteValues(data);
            ResetShadowSettings(data);

            UpdateBattlerValue(data);
            ReloadPokemonSprites(data);
            VBlankIntrWait();
            PlaySE(SE_DEX_SCROLL);
        }
        break;
    default:
        break;
    }
}

static void UpdateSubmenuTwoOptionValue(u8 taskId, bool8 increment)
{
    struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);
    enum Species species = IsSpeciesEnabled(data->currentmonId) ? SanitizeSpeciesId(data->currentmonId) : SPECIES_NONE;
    u8 option = data->submenuYpos[2];
    s8 offset;
    u8 y;

    switch (option)
    {
    case 0: //Back picCoords
        offset = data->offsetsSpriteValues.offset_back_picCoords;
        if (increment)
        {
            if (offset == MAX_Y_OFFSET)
                offset = -data->constSpriteValues.backPicCoords;
            else
                offset += 1;
        }
        else
        {
            if (offset == -data->constSpriteValues.backPicCoords)
                offset = MAX_Y_OFFSET;
            else
                offset -= 1;
        }
        data->offsetsSpriteValues.offset_back_picCoords = offset;
        gSprites[data->backspriteId].y = VISUALIZER_MON_BACK_Y + gSpeciesInfo[species].backPicYOffset + offset;
        break;
    case 1: //Front picCoords
        offset = data->offsetsSpriteValues.offset_front_picCoords;
        if (increment)
        {
            if (offset == MAX_Y_OFFSET)
                offset = -data->constSpriteValues.frontPicCoords;
            else
                offset += 1;
        }
        else
        {
            if (offset == -data->constSpriteValues.frontPicCoords)
                offset = MAX_Y_OFFSET;
            else
                offset -= 1;
        }
        data->offsetsSpriteValues.offset_front_picCoords = offset;
        y = GetBattlerSpriteFinal_YCustom(species, offset, data->offsetsSpriteValues.offset_front_elevation);
        gSprites[data->frontspriteId].y = y;
        break;
    case 2: //Front elevation
        offset = data->offsetsSpriteValues.offset_front_elevation;
        if (increment)
        {
            if (offset == MAX_Y_OFFSET)
                offset = -data->constSpriteValues.frontElevation;
            else
                offset += 1;
        }
        else
        {
            if (offset == -data->constSpriteValues.frontElevation)
                offset = MAX_Y_OFFSET;
            else
                offset -= 1;
        }
        data->offsetsSpriteValues.offset_front_elevation = offset;
        y = GetBattlerSpriteFinal_YCustom(species, data->offsetsSpriteValues.offset_front_picCoords, offset);
        gSprites[data->frontspriteId].y = y;
        UpdateShadowSpriteInvisible(data);
        break;
    }

    UpdateYPosOffsetText(data);
}

static void UpdateShadowSettingsValue(u8 taskId, bool8 increment)
{
    if (B_ENEMY_MON_SHADOW_STYLE <= GEN_3 || P_GBA_STYLE_SPECIES_GFX == TRUE)
        return;

    struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);
    u8 option = data->submenuYpos[2];
    s8 *offset;
    s16 *leftTarget, *rightTarget;
    if (option == 0)
    {
        offset = &data->shadowSettings.overrideX;
        leftTarget = &gSprites[data->frontShadowSpriteIdPrimary].tShadowXOffset;
        rightTarget = &gSprites[data->frontShadowSpriteIdSecondary].tShadowXOffset;
    }
    else
    {
        offset = &data->shadowSettings.overrideY;
        leftTarget = &gSprites[data->frontShadowSpriteIdPrimary].tShadowYOffset;
        rightTarget = &gSprites[data->frontShadowSpriteIdSecondary].tShadowYOffset;
    }

    *offset = *offset + (increment ? 1 : -1);
    if (*offset > 20)
        *offset = -20;
    else if (*offset < -20)
        *offset = 20;
    UpdateShadowSettingsText(data);

    *leftTarget = (s16)*offset;
    *rightTarget = (s16)*offset;
}

static void UpdateShadowSizeValue(u8 taskId, bool8 increment)
{
    if (B_ENEMY_MON_SHADOW_STYLE <= GEN_3 || P_GBA_STYLE_SPECIES_GFX == TRUE)
        return;

    struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);
    s8 update;

    if (increment)
    {
        if (data->shadowSettings.overrideSize == SHADOW_SIZE_XL_BATTLE_ONLY)
        {
            update = -data->shadowSettings.overrideSize;
            data->shadowSettings.overrideSize = SHADOW_SIZE_S;
        }
        else
        {
            update = 1;
            data->shadowSettings.overrideSize += 1;
        }
    }
    else
    {
        if (data->shadowSettings.overrideSize == SHADOW_SIZE_S)
        {
            update = SHADOW_SIZE_XL_BATTLE_ONLY;
            data->shadowSettings.overrideSize = update;
        }
        else
        {
            update = -1;
            data->shadowSettings.overrideSize -= 1;
        }
    }

    UpdateShadowSettingsText(data);
    gSprites[data->frontShadowSpriteIdPrimary].oam.tileNum += (8 * update);
    gSprites[data->frontShadowSpriteIdSecondary].oam.tileNum += (8 * update);
}

static void UpdateSubmenuFourOptionValue(u8 taskId, bool8 increment)
{
    struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);

    switch (data->submenuYpos[1])
    {
    case 0:
        UpdateMoveBackground(taskId, increment);
        break;
    default:
        break;
    }
}

#define READ_PTR_FROM_TASK(taskId, dataId)              \
    (void *)(                                           \
    ((u16)(gTasks[taskId].data[dataId]) |               \
    ((u16)(gTasks[taskId].data[dataId + 1]) << 16)))

#define STORE_PTR_IN_TASK(ptr, taskId, dataId)          \
{                                                       \
    gTasks[taskId].data[dataId] = (u32)(ptr);           \
    gTasks[taskId].data[dataId + 1] = (u32)(ptr) >> 16; \
}

#define sAnimId    data[2]
#define sAnimDelay data[3]

static void Task_AnimateAfterDelay(u8 taskId)
{
    if (--gTasks[taskId].sAnimDelay == 0)
    {
        LaunchAnimationTaskForFrontSprite(READ_PTR_FROM_TASK(taskId, 0), gTasks[taskId].sAnimId);
        DestroyTask(taskId);
    }
}

static void OpenSubmenu(u32 submenu, u8 taskId)
{
    struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);
    data->currentSubmenu = submenu;
    PrintInstructionsOnWindow(data);
    SetArrowInvisibility(data);

    switch (submenu)
    {
    case SUBMENU_SPECIES:
    case SUBMENU_ANIMS_BG:
        break;
    case SUBMENU_SPRITE_COORDS:
        SetConstSpriteValues(data);
        UpdateYPosOffsetText(data);
        break;
    case SUBMENU_SHADOW_COORDS:
        UpdateShadowSettingsText(data);
        break;
    case SUBMENU_MOVE_BACKGROUNDS:
        if (data->submenuYpos[1] > 0)
            data->submenuYpos[1] = 0;

        data->optionArrows.currentDigit = data->submenuYpos[1];
        gSprites[data->optionArrows.arrowSpriteId[0]].y = OPTIONS_ARROW_Y + data->optionArrows.currentDigit * 12;
        data->moveBackground = BG_DARK;
        PrintMoveBackgroundName(data->moveBackground);
        LoadMoveBackground(data->moveBackground);
        break;
    default:
        errorf("Invalid submenu index %d", submenu);
        break;
    }
}

static void HandleInput_PokemonSpriteVisualizer(u8 taskId)
{
    struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);
    enum Species species = IsSpeciesEnabled(data->currentmonId) ? SanitizeSpeciesId(data->currentmonId) : SPECIES_NONE;
    struct Sprite *Frontsprite = &gSprites[data->frontspriteId];
    struct Sprite *Backsprite = &gSprites[data->backspriteId];

    if (JOY_NEW(L_BUTTON)  && (Backsprite->callback == SpriteCallbackDummy))
    {
        PlayCryInternal(species, 0, 120, 10, CRY_MODE_NORMAL);
        LaunchAnimationTaskForBackSprite(Backsprite, data->animIdBack-1);
    }
    if (JOY_NEW(R_BUTTON) && (Frontsprite->callback == SpriteCallbackDummy))
    {
        PlayCryInternal(species, 0, 120, 10, CRY_MODE_NORMAL);
        if (HasTwoFramesAnimation(species))
            StartSpriteAnim(Frontsprite, 1);

        if (gSpeciesInfo[species].frontAnimDelay != 0)
        {
            // Animation has delay, start delay task
            u8 taskId = CreateTask(Task_AnimateAfterDelay, 0);
            STORE_PTR_IN_TASK(Frontsprite, taskId, 0);
            gTasks[taskId].sAnimId = data->animIdFront;
            gTasks[taskId].sAnimDelay = gSpeciesInfo[species].frontAnimDelay;
        }
        else
        {
            // No delay, start animation
            LaunchAnimationTaskForFrontSprite(Frontsprite, data->animIdFront);
        }
    }

    if (JOY_NEW(START_BUTTON))
    {
        data->isShiny = !data->isShiny;

        if (data->isShiny)
            PlaySE(SE_SHINY);

        ReloadPokemonSprites(data);
        ApplyOffsetSpriteValues(data);
    }
    if (JOY_NEW(SELECT_BUTTON) && SpeciesHasGenderDifferences(species))
    {
        data->isFemale = !data->isFemale;
        PrintDigitChars(data);
        UpdateBattlerValue(data);
        ReloadPokemonSprites(data);
        VBlankIntrWait();
        PlaySE(SE_DEX_SCROLL);
    }

    if (data->currentSubmenu == SUBMENU_SPECIES)
    {
        if (JOY_NEW(A_BUTTON))
        {
            OpenSubmenu(SUBMENU_ANIMS_BG, taskId);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
            gTasks[taskId].func = Exit_PokemonSpriteVisualizer;
            PlaySE(SE_PC_OFF);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (TryMoveDigit(&data->modifyArrows, FALSE))
            {
                data->isFemale = FALSE;
                PrintDigitChars(data);
                UpdateBattlerValue(data);
                ResetShadowSettings(data);
                ReloadPokemonSprites(data);
                data->animIdBack = GetSpeciesBackAnimSet(species) + 1;
                data->animIdFront = gSpeciesInfo[species].frontAnimId;
                UpdateMonAnimNames(taskId);
                ResetOffsetSpriteValues(data);
            }
            PlaySE(SE_DEX_SCROLL);
            VBlankIntrWait();
        }
        else if (JOY_NEW(DPAD_UP))
        {
            if (TryMoveDigit(&data->modifyArrows, TRUE))
            {
                data->isFemale = FALSE;
                PrintDigitChars(data);
                UpdateBattlerValue(data);
                ResetShadowSettings(data);
                ReloadPokemonSprites(data);
                data->animIdBack = GetSpeciesBackAnimSet(species) + 1;
                data->animIdFront = gSpeciesInfo[species].frontAnimId;
                UpdateMonAnimNames(taskId);
                ResetOffsetSpriteValues(data);
            }

            PlaySE(SE_DEX_SCROLL);
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            if (data->modifyArrows.currentDigit != 0)
            {
                data->modifyArrows.currentDigit--;
                gSprites[data->modifyArrows.arrowSpriteId[0]].x2 -= 6;
                gSprites[data->modifyArrows.arrowSpriteId[1]].x2 -= 6;
            }
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            if (data->modifyArrows.currentDigit != (data->modifyArrows.maxDigits - 1))
            {
                data->modifyArrows.currentDigit++;
                gSprites[data->modifyArrows.arrowSpriteId[0]].x2 += 6;
                gSprites[data->modifyArrows.arrowSpriteId[1]].x2 += 6;
            }
        }
    }
    else if (data->currentSubmenu == SUBMENU_ANIMS_BG)
    {
        if (JOY_NEW(A_BUTTON))
        {
            OpenSubmenu(SUBMENU_SPRITE_COORDS, taskId);

            if (data->followerspriteId != 0)
                gSprites[data->followerspriteId].invisible = TRUE;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            OpenSubmenu(SUBMENU_SPECIES, taskId);
            if (data->submenuYpos[1] == 3)
            {
                data->submenuYpos[1] = 2;
                data->optionArrows.currentDigit = data->submenuYpos[1];
                gSprites[data->optionArrows.arrowSpriteId[0]].y = OPTIONS_ARROW_Y + data->optionArrows.currentDigit * 12;
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data->submenuYpos[1] += 1;
            if (data->submenuYpos[1] >= 3)
            {
                if ((GetSpeciesFormTable(species) == NULL) || (data->submenuYpos[1] >= 4))
                    data->submenuYpos[1] = 0;
            }
            data->optionArrows.currentDigit = data->submenuYpos[1];
            gSprites[data->optionArrows.arrowSpriteId[0]].y = OPTIONS_ARROW_Y + data->optionArrows.currentDigit * 12;
        }
        else if (JOY_NEW(DPAD_UP))
        {
            if (data->submenuYpos[1] == 0)
            {
                if (GetSpeciesFormTable(species) != NULL)
                    data->submenuYpos[1] = 3;
                else
                    data->submenuYpos[1] = 2;
            }
            else
                data->submenuYpos[1] -= 1;

            data->optionArrows.currentDigit = data->submenuYpos[1];
            gSprites[data->optionArrows.arrowSpriteId[0]].y = OPTIONS_ARROW_Y + data->optionArrows.currentDigit * 12;
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            UpdateSubmenuOneOptionValue(taskId, FALSE);
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            UpdateSubmenuOneOptionValue(taskId, TRUE);
        }
    }
    else if (data->currentSubmenu == SUBMENU_SPRITE_COORDS)
    {
        if (JOY_NEW(A_BUTTON))
        {
            if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
                OpenSubmenu(SUBMENU_SHADOW_COORDS, taskId);
            else
                OpenSubmenu(SUBMENU_MOVE_BACKGROUNDS, taskId);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            OpenSubmenu(SUBMENU_ANIMS_BG, taskId);
            UpdateMonAnimNames(taskId);

            if (data->followerspriteId != 0)
                gSprites[data->followerspriteId].invisible = FALSE;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data->submenuYpos[2] += 1;
            if (data->submenuYpos[2] >= 3)
                data->submenuYpos[2] = 0;

            data->yPosModifyArrows.currentDigit = data->submenuYpos[2];
            gSprites[data->yPosModifyArrows.arrowSpriteId[0]].y = OPTIONS_ARROW_Y + data->yPosModifyArrows.currentDigit * 12;
        }
        else if (JOY_NEW(DPAD_UP))
        {
            if (data->submenuYpos[2] == 0)
                data->submenuYpos[2] = 2;
            else
                data->submenuYpos[2] -= 1;

            data->yPosModifyArrows.currentDigit = data->submenuYpos[2];
            gSprites[data->yPosModifyArrows.arrowSpriteId[0]].y = OPTIONS_ARROW_Y + data->yPosModifyArrows.currentDigit * 12;
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            UpdateSubmenuTwoOptionValue(taskId, FALSE);
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            UpdateSubmenuTwoOptionValue(taskId, TRUE);
        }
    }
    else if (data->currentSubmenu == SUBMENU_SHADOW_COORDS)
    {
        if (JOY_NEW(A_BUTTON))
        {
            OpenSubmenu(SUBMENU_MOVE_BACKGROUNDS, taskId);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            OpenSubmenu(SUBMENU_SPRITE_COORDS, taskId);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data->submenuYpos[2] += 1;
            if (data->submenuYpos[2] >= 3)
                data->submenuYpos[2] = 0;

            data->yPosModifyArrows.currentDigit = data->submenuYpos[2];
            gSprites[data->yPosModifyArrows.arrowSpriteId[0]].y = OPTIONS_ARROW_Y + data->yPosModifyArrows.currentDigit * 12;
        }
        else if (JOY_NEW(DPAD_UP))
        {
            if (data->submenuYpos[2] == 0)
                data->submenuYpos[2] = 2;
            else
                data->submenuYpos[2] -= 1;

            data->yPosModifyArrows.currentDigit = data->submenuYpos[2];
            gSprites[data->yPosModifyArrows.arrowSpriteId[0]].y = OPTIONS_ARROW_Y + data->yPosModifyArrows.currentDigit * 12;
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            if (data->submenuYpos[2] < 2)
                UpdateShadowSettingsValue(taskId, FALSE);
            else
                UpdateShadowSizeValue(taskId, FALSE);
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            if (data->submenuYpos[2] < 2)
                UpdateShadowSettingsValue(taskId, TRUE);
            else
                UpdateShadowSizeValue(taskId, TRUE);
        }
    }
    else if (data->currentSubmenu == SUBMENU_MOVE_BACKGROUNDS)
    {
        if (JOY_NEW(B_BUTTON))
        {
            if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
                OpenSubmenu(SUBMENU_SHADOW_COORDS, taskId);
            else
                OpenSubmenu(SUBMENU_SPRITE_COORDS, taskId);
            LoadBattleBg(data->battleEnvironment);
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            UpdateSubmenuFourOptionValue(taskId, FALSE);
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            UpdateSubmenuFourOptionValue(taskId, TRUE);
        }
    }
}
#undef sDelay
#undef sAnimId

static void ReloadPokemonSprites(struct PokemonSpriteVisualizer *data)
{
    const u16 *palette;
    enum Species species = IsSpeciesEnabled(data->currentmonId) ? SanitizeSpeciesId(data->currentmonId) : SPECIES_NONE;
    s16 offset_y;
    u8 front_x = sBattlerCoords[0][1].x;
    u8 front_y;

    DestroySprite(&gSprites[data->frontspriteId]);
    DestroySprite(&gSprites[data->backspriteId]);
    DestroySprite(&gSprites[data->iconspriteId]);

    if (data->followerspriteId != 0)
        DestroySprite(&gSprites[data->followerspriteId]);

    DestroySprite(&gSprites[data->frontShadowSpriteIdPrimary]);
    if (B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE)
        DestroySprite(&gSprites[data->frontShadowSpriteIdSecondary]);

    FreeMonSpritesGfx();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    FreeMonIconPalettes();

    AllocateMonSpritesGfx();
    LoadMonIconPalettePersonality(species, (data->isFemale ? FEMALE_PERSONALITY : MALE_PERSONALITY));

    //Update instructions
    PrintInstructionsOnWindow(data);

    //Palettes
    palette = GetMonSpritePalFromSpecies(species, data->isShiny, data->isFemale);
    LoadSpritePaletteWithTag(palette, species);
    //Front
    HandleLoadSpecialPokePic(TRUE, gMonSpritesGfxPtr->spritesGfx[1], species, (data->isFemale ? FEMALE_PERSONALITY : MALE_PERSONALITY));
    BattleLoadOpponentMonSpriteGfxCustom(species, data->isFemale, data->isShiny, 1);
    SetMultiuseSpriteTemplateToPokemon(species, 1);
    gMultiuseSpriteTemplate.paletteTag = species;
    front_y = GetBattlerSpriteFinal_YCustom(species, 0, 0);
    data->frontspriteId = CreateSprite(&gMultiuseSpriteTemplate, front_x, front_y, 0);
    gSprites[data->frontspriteId].oam.paletteNum = 1;
    gSprites[data->frontspriteId].callback = SpriteCallbackDummy;
    gSprites[data->frontspriteId].oam.priority = 0;
    //Front Shadow
    LoadAndCreateEnemyShadowSpriteCustom(data);

    //Back
    HandleLoadSpecialPokePic(FALSE, gMonSpritesGfxPtr->spritesGfx[2], species, (data->isFemale ? FEMALE_PERSONALITY : MALE_PERSONALITY));
    BattleLoadOpponentMonSpriteGfxCustom(species, data->isFemale, data->isShiny, 5);
    SetMultiuseSpriteTemplateToPokemon(species, 2);
    offset_y = gSpeciesInfo[species].backPicYOffset;
    data->backspriteId = CreateSprite(&gMultiuseSpriteTemplate, VISUALIZER_MON_BACK_X, VISUALIZER_MON_BACK_Y + offset_y, 0);
    gSprites[data->backspriteId].oam.paletteNum = 5;
    gSprites[data->backspriteId].callback = SpriteCallbackDummy;
    gSprites[data->backspriteId].oam.priority = 0;

    //Icon Sprite
    data->iconspriteId = CreateMonIcon(species, SpriteCB_MonIcon, VISUALIZER_ICON_X, VISUALIZER_ICON_Y, 4, (data->isFemale ? FEMALE_PERSONALITY : MALE_PERSONALITY));
    gSprites[data->iconspriteId].oam.priority = 0;

    //Follower Sprite
    DrawFollowerSprite(data);

    //Modify Arrows
    LoadSpritePalette(&gSpritePalette_Arrow);
    data->modifyArrows.arrowSpriteId[0] = CreateSprite(&gSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X + (data->modifyArrows.currentDigit * 6), MODIFY_DIGITS_ARROW1_Y, 0);
    data->modifyArrows.arrowSpriteId[1] = CreateSprite(&gSpriteTemplate_Arrow, MODIFY_DIGITS_ARROW_X + (data->modifyArrows.currentDigit * 6), MODIFY_DIGITS_ARROW2_Y, 0);
    gSprites[data->modifyArrows.arrowSpriteId[1]].animNum = 1;

    //Option Arrow
    LoadSpritePalette(&gSpritePalette_Arrow);
    data->optionArrows.arrowSpriteId[0] = CreateSprite(&gSpriteTemplate_Arrow, OPTIONS_ARROW_1_X, OPTIONS_ARROW_Y + data->optionArrows.currentDigit * 12, 0);
    gSprites[data->optionArrows.arrowSpriteId[0]].animNum = 2;

    //Y Pos Modify Arrow
    LoadSpritePalette(&gSpritePalette_Arrow);
    data->yPosModifyArrows.arrowSpriteId[0] = CreateSprite(&gSpriteTemplate_Arrow, OPTIONS_ARROW_1_X, OPTIONS_ARROW_Y + data->yPosModifyArrows.currentDigit * 12, 0);
    gSprites[data->yPosModifyArrows.arrowSpriteId[0]].animNum = 2;

    //Arrow invisibility
    SetArrowInvisibility(data);

    //Footprint
    DrawFootprint(WIN_FOOTPRINT, species);
    CopyWindowToVram(WIN_FOOTPRINT, COPYWIN_GFX);
}

static void Exit_PokemonSpriteVisualizer(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        struct PokemonSpriteVisualizer *data = GetStructPtr(taskId);
        Free(data);
        FreeMonSpritesGfx();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
    }
}
