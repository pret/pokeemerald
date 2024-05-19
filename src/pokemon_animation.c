#include "global.h"
#include "battle.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_animation.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "data.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"

/*
    This file handles the movements of the Pokémon intro animations.

    Each animation type is identified by an ANIM_* constant that
    refers to a sprite callback to start the animation. These functions
    are named Anim_<name> or Anim_<name>_<variant>. Many of these
    functions share additional movement functions to do a variation of the
    same movement (e.g. a faster or larger movement).
    Vertical and Horizontal are frequently shortened to V and H.

    Every front animation uses 1 of these ANIMs, and every back animation
    uses a BACK_ANIM_* that refers to a set of 3 ANIM functions. Which of the
    3 that gets used depends on the Pokémon's nature (see sBackAnimationIds).

    The gSpeciesInfo table links to both BACK_ANIM and ANIM in its frontAnimId and backAnimId fields.

    These are the functions that will start an animation:
    - LaunchAnimationTaskForFrontSprite
    - LaunchAnimationTaskForBackSprite
    - StartMonSummaryAnimation
*/

#define sDontFlip data[1]  // TRUE if a normal animation, FALSE if Summary Screen animation

struct PokemonAnimData
{
    u16 delay;
    s16 speed; // Only used by 2 sets of animations
    s16 runs; // Number of times to do the animation
    s16 rotation;
    s16 data; // General use
};

struct YellowFlashData
{
    bool8 isYellow;
    u8 time;
};

static void Anim_VerticalSquishBounce(struct Sprite *sprite);
static void Anim_CircularStretchTwice(struct Sprite *sprite);
static void Anim_HorizontalVibrate(struct Sprite *sprite);
static void Anim_HorizontalSlide(struct Sprite *sprite);
static void Anim_VerticalSlide(struct Sprite *sprite);
static void Anim_BounceRotateToSides(struct Sprite *sprite);
static void Anim_VerticalJumpsHorizontalJumps(struct Sprite *sprite);
static void Anim_RotateToSides(struct Sprite *sprite);
static void Anim_RotateToSides_Twice(struct Sprite *sprite);
static void Anim_GrowVibrate(struct Sprite *sprite);
static void Anim_ZigzagFast(struct Sprite *sprite);
static void Anim_SwingConcave(struct Sprite *sprite);
static void Anim_SwingConcave_Fast(struct Sprite *sprite);
static void Anim_SwingConvex(struct Sprite *sprite);
static void Anim_SwingConvex_Fast(struct Sprite *sprite);
static void Anim_HorizontalShake(struct Sprite *sprite);
static void Anim_VerticalShake(struct Sprite *sprite);
static void Anim_CircularVibrate(struct Sprite *sprite);
static void Anim_Twist(struct Sprite *sprite);
static void Anim_ShrinkGrow(struct Sprite *sprite);
static void Anim_CircleCounterclockwise(struct Sprite *sprite);
static void Anim_GlowBlack(struct Sprite *sprite);
static void Anim_HorizontalStretch(struct Sprite *sprite);
static void Anim_VerticalStretch(struct Sprite *sprite);
static void Anim_RisingWobble(struct Sprite *sprite);
static void Anim_VerticalShakeTwice(struct Sprite *sprite);
static void Anim_TipMoveForward(struct Sprite *sprite);
static void Anim_HorizontalPivot(struct Sprite *sprite);
static void Anim_VerticalSlideWobble(struct Sprite *sprite);
static void Anim_HorizontalSlideWobble(struct Sprite *sprite);
static void Anim_VerticalJumps_Big(struct Sprite *sprite);
static void Anim_Spin_Long(struct Sprite *sprite);
static void Anim_GlowOrange(struct Sprite *sprite);
static void Anim_GlowRed(struct Sprite *sprite);
static void Anim_GlowBlue(struct Sprite *sprite);
static void Anim_GlowYellow(struct Sprite *sprite);
static void Anim_GlowPurple(struct Sprite *sprite);
static void Anim_BackAndLunge(struct Sprite *sprite);
static void Anim_BackFlip(struct Sprite *sprite);
static void Anim_Flicker(struct Sprite *sprite);
static void Anim_BackFlipBig(struct Sprite *sprite);
static void Anim_FrontFlip(struct Sprite *sprite);
static void Anim_TumblingFrontFlip(struct Sprite *sprite);
static void Anim_Figure8(struct Sprite *sprite);
static void Anim_FlashYellow(struct Sprite *sprite);
static void Anim_SwingConcave_FastShort(struct Sprite *sprite);
static void Anim_SwingConvex_FastShort(struct Sprite *sprite);
static void Anim_RotateUpSlamDown(struct Sprite *sprite);
static void Anim_DeepVerticalSquishBounce(struct Sprite *sprite);
static void Anim_HorizontalJumps(struct Sprite *sprite);
static void Anim_HorizontalJumpsVerticalStretch(struct Sprite *sprite);
static void Anim_RotateToSides_Fast(struct Sprite *sprite);
static void Anim_RotateUpToSides(struct Sprite *sprite);
static void Anim_FlickerIncreasing(struct Sprite *sprite);
static void Anim_TipHopForward(struct Sprite *sprite);
static void Anim_PivotShake(struct Sprite *sprite);
static void Anim_TipAndShake(struct Sprite *sprite);
static void Anim_VibrateToCorners(struct Sprite *sprite);
static void Anim_GrowInStages(struct Sprite *sprite);
static void Anim_VerticalSpring(struct Sprite *sprite);
static void Anim_VerticalRepeatedSpring(struct Sprite *sprite);
static void Anim_SpringRising(struct Sprite *sprite);
static void Anim_HorizontalSpring(struct Sprite *sprite);
static void Anim_HorizontalRepeatedSpring_Slow(struct Sprite *sprite);
static void Anim_HorizontalSlideShrink(struct Sprite *sprite);
static void Anim_LungeGrow(struct Sprite *sprite);
static void Anim_CircleIntoBackground(struct Sprite *sprite);
static void Anim_RapidHorizontalHops(struct Sprite *sprite);
static void Anim_FourPetal(struct Sprite *sprite);
static void Anim_VerticalSquishBounce_Slow(struct Sprite *sprite);
static void Anim_HorizontalSlide_Slow(struct Sprite *sprite);
static void Anim_VerticalSlide_Slow(struct Sprite *sprite);
static void Anim_BounceRotateToSides_Small(struct Sprite *sprite);
static void Anim_BounceRotateToSides_Slow(struct Sprite *sprite);
static void Anim_BounceRotateToSides_SmallSlow(struct Sprite *sprite);
static void Anim_ZigzagSlow(struct Sprite *sprite);
static void Anim_HorizontalShake_Slow(struct Sprite *sprite);
static void Anim_VertialShake_Slow(struct Sprite *sprite);
static void Anim_Twist_Twice(struct Sprite *sprite);
static void Anim_CircleCounterclockwise_Slow(struct Sprite *sprite);
static void Anim_VerticalShakeTwice_Slow(struct Sprite *sprite);
static void Anim_VerticalSlideWobble_Small(struct Sprite *sprite);
static void Anim_VerticalJumps_Small(struct Sprite *sprite);
static void Anim_Spin(struct Sprite *sprite);
static void Anim_TumblingFrontFlip_Twice(struct Sprite *sprite);
static void Anim_DeepVerticalSquishBounce_Twice(struct Sprite *sprite);
static void Anim_HorizontalJumpsVerticalStretch_Twice(struct Sprite *sprite);
static void Anim_VerticalShakeBack(struct Sprite *sprite);
static void Anim_VerticalShakeBack_Slow(struct Sprite *sprite);
static void Anim_VerticalShakeHorizontalSlide_Slow(struct Sprite *sprite);
static void Anim_VerticalStretchBothEnds_Slow(struct Sprite *sprite);
static void Anim_HorizontalStretchFar_Slow(struct Sprite *sprite);
static void Anim_VerticalShakeLowTwice(struct Sprite *sprite);
static void Anim_HorizontalShake_Fast(struct Sprite *sprite);
static void Anim_HorizontalSlide_Fast(struct Sprite *sprite);
static void Anim_HorizontalVibrate_Fast(struct Sprite *sprite);
static void Anim_HorizontalVibrate_Fastest(struct Sprite *sprite);
static void Anim_VerticalShakeBack_Fast(struct Sprite *sprite);
static void Anim_VerticalShakeLowTwice_Slow(struct Sprite *sprite);
static void Anim_VerticalShakeLowTwice_Fast(struct Sprite *sprite);
static void Anim_CircleCounterclockwise_Long(struct Sprite *sprite);
static void Anim_GrowStutter_Slow(struct Sprite *sprite);
static void Anim_VerticalShakeHorizontalSlide(struct Sprite *sprite);
static void Anim_VerticalShakeHorizontalSlide_Fast(struct Sprite *sprite);
static void Anim_TriangleDown_Slow(struct Sprite *sprite);
static void Anim_TriangleDown(struct Sprite *sprite);
static void Anim_TriangleDown_Fast(struct Sprite *sprite);
static void Anim_Grow(struct Sprite *sprite);
static void Anim_Grow_Twice(struct Sprite *sprite);
static void Anim_HorizontalSpring_Fast(struct Sprite *sprite);
static void Anim_HorizontalSpring_Slow(struct Sprite *sprite);
static void Anim_HorizontalRepeatedSpring_Fast(struct Sprite *sprite);
static void Anim_HorizontalRepeatedSpring(struct Sprite *sprite);
static void Anim_ShrinkGrow_Fast(struct Sprite *sprite);
static void Anim_ShrinkGrow_Slow(struct Sprite *sprite);
static void Anim_VerticalStretchBothEnds(struct Sprite *sprite);
static void Anim_VerticalStretchBothEnds_Twice(struct Sprite *sprite);
static void Anim_HorizontalStretchFar_Twice(struct Sprite *sprite);
static void Anim_HorizontalStretchFar(struct Sprite *sprite);
static void Anim_GrowStutter_Twice(struct Sprite *sprite);
static void Anim_GrowStutter(struct Sprite *sprite);
static void Anim_ConcaveArcLarge_Slow(struct Sprite *sprite);
static void Anim_ConcaveArcLarge(struct Sprite *sprite);
static void Anim_ConcaveArcLarge_Twice(struct Sprite *sprite);
static void Anim_ConvexDoubleArc_Slow(struct Sprite *sprite);
static void Anim_ConvexDoubleArc(struct Sprite *sprite);
static void Anim_ConvexDoubleArc_Twice(struct Sprite *sprite);
static void Anim_ConcaveArcSmall_Slow(struct Sprite *sprite);
static void Anim_ConcaveArcSmall(struct Sprite *sprite);
static void Anim_ConcaveArcSmall_Twice(struct Sprite *sprite);
static void Anim_HorizontalDip(struct Sprite *sprite);
static void Anim_HorizontalDip_Fast(struct Sprite *sprite);
static void Anim_HorizontalDip_Twice(struct Sprite *sprite);
static void Anim_ShrinkGrowVibrate_Fast(struct Sprite *sprite);
static void Anim_ShrinkGrowVibrate(struct Sprite *sprite);
static void Anim_ShrinkGrowVibrate_Slow(struct Sprite *sprite);
static void Anim_JoltRight_Fast(struct Sprite *sprite);
static void Anim_JoltRight(struct Sprite *sprite);
static void Anim_JoltRight_Slow(struct Sprite *sprite);
static void Anim_ShakeFlashYellow_Fast(struct Sprite *sprite);
static void Anim_ShakeFlashYellow(struct Sprite *sprite);
static void Anim_ShakeFlashYellow_Slow(struct Sprite *sprite);
static void Anim_ShakeGlowRed_Fast(struct Sprite *sprite);
static void Anim_ShakeGlowRed(struct Sprite *sprite);
static void Anim_ShakeGlowRed_Slow(struct Sprite *sprite);
static void Anim_ShakeGlowGreen_Fast(struct Sprite *sprite);
static void Anim_ShakeGlowGreen(struct Sprite *sprite);
static void Anim_ShakeGlowGreen_Slow(struct Sprite *sprite);
static void Anim_ShakeGlowBlue_Fast(struct Sprite *sprite);
static void Anim_ShakeGlowBlue(struct Sprite *sprite);
static void Anim_ShakeGlowBlue_Slow(struct Sprite *sprite);
static void Anim_ShakeGlowBlack_Slow(struct Sprite *sprite);
static void Anim_ShakeGlowWhite_Slow(struct Sprite *sprite);
static void Anim_ShakeGlowPurple_Slow(struct Sprite *sprite);

static void WaitAnimEnd(struct Sprite *sprite);

static struct PokemonAnimData sAnims[MAX_BATTLERS_COUNT];
static u8 sAnimIdx;
static bool32 sIsSummaryAnim;

// Equivalent to struct YellowFlashData, but doesn't match as a struct
static const u8 sYellowFlashData[][2] =
{
    {FALSE,  5},
    { TRUE,  1},
    {FALSE, 15},
    { TRUE,  4},
    {FALSE,  2},
    { TRUE,  2},
    {FALSE,  2},
    { TRUE,  2},
    {FALSE,  2},
    { TRUE,  2},
    {FALSE,  2},
    { TRUE,  2},
    {FALSE,  2},
    {FALSE, -1}
};

static const u8 sVerticalShakeData[][2] =
{
    { 6,  30},
    {-2,  15},
    { 6,  30},
    {-1,   0}
};

static void (* const sMonAnimFunctions[])(struct Sprite *sprite) =
{
    [ANIM_V_SQUISH_AND_BOUNCE]               = Anim_VerticalSquishBounce,
    [ANIM_CIRCULAR_STRETCH_TWICE]            = Anim_CircularStretchTwice,
    [ANIM_H_VIBRATE]                         = Anim_HorizontalVibrate,
    [ANIM_H_SLIDE]                           = Anim_HorizontalSlide,
    [ANIM_V_SLIDE]                           = Anim_VerticalSlide,
    [ANIM_BOUNCE_ROTATE_TO_SIDES]            = Anim_BounceRotateToSides,
    [ANIM_V_JUMPS_H_JUMPS]                   = Anim_VerticalJumpsHorizontalJumps,
    [ANIM_ROTATE_TO_SIDES]                   = Anim_RotateToSides, // Unused
    [ANIM_ROTATE_TO_SIDES_TWICE]             = Anim_RotateToSides_Twice,
    [ANIM_GROW_VIBRATE]                      = Anim_GrowVibrate,
    [ANIM_ZIGZAG_FAST]                       = Anim_ZigzagFast,
    [ANIM_SWING_CONCAVE]                     = Anim_SwingConcave,
    [ANIM_SWING_CONCAVE_FAST]                = Anim_SwingConcave_Fast,
    [ANIM_SWING_CONVEX]                      = Anim_SwingConvex,
    [ANIM_SWING_CONVEX_FAST]                 = Anim_SwingConvex_Fast,
    [ANIM_H_SHAKE]                           = Anim_HorizontalShake,
    [ANIM_V_SHAKE]                           = Anim_VerticalShake,
    [ANIM_CIRCULAR_VIBRATE]                  = Anim_CircularVibrate,
    [ANIM_TWIST]                             = Anim_Twist,
    [ANIM_SHRINK_GROW]                       = Anim_ShrinkGrow,
    [ANIM_CIRCLE_C_CLOCKWISE]                = Anim_CircleCounterclockwise,
    [ANIM_GLOW_BLACK]                        = Anim_GlowBlack,
    [ANIM_H_STRETCH]                         = Anim_HorizontalStretch,
    [ANIM_V_STRETCH]                         = Anim_VerticalStretch,
    [ANIM_RISING_WOBBLE]                     = Anim_RisingWobble,
    [ANIM_V_SHAKE_TWICE]                     = Anim_VerticalShakeTwice,
    [ANIM_TIP_MOVE_FORWARD]                  = Anim_TipMoveForward,
    [ANIM_H_PIVOT]                           = Anim_HorizontalPivot,
    [ANIM_V_SLIDE_WOBBLE]                    = Anim_VerticalSlideWobble,
    [ANIM_H_SLIDE_WOBBLE]                    = Anim_HorizontalSlideWobble,
    [ANIM_V_JUMPS_BIG]                       = Anim_VerticalJumps_Big,
    [ANIM_SPIN_LONG]                         = Anim_Spin_Long, // Unused
    [ANIM_GLOW_ORANGE]                       = Anim_GlowOrange,
    [ANIM_GLOW_RED]                          = Anim_GlowRed, // Unused
    [ANIM_GLOW_BLUE]                         = Anim_GlowBlue,
    [ANIM_GLOW_YELLOW]                       = Anim_GlowYellow, // Unused
    [ANIM_GLOW_PURPLE]                       = Anim_GlowPurple, // Unused
    [ANIM_BACK_AND_LUNGE]                    = Anim_BackAndLunge,
    [ANIM_BACK_FLIP]                         = Anim_BackFlip, // Unused
    [ANIM_FLICKER]                           = Anim_Flicker, // Unused
    [ANIM_BACK_FLIP_BIG]                     = Anim_BackFlipBig, // Unused
    [ANIM_FRONT_FLIP]                        = Anim_FrontFlip,
    [ANIM_TUMBLING_FRONT_FLIP]               = Anim_TumblingFrontFlip, // Unused
    [ANIM_FIGURE_8]                          = Anim_Figure8,
    [ANIM_FLASH_YELLOW]                      = Anim_FlashYellow,
    [ANIM_SWING_CONCAVE_FAST_SHORT]          = Anim_SwingConcave_FastShort,
    [ANIM_SWING_CONVEX_FAST_SHORT]           = Anim_SwingConvex_FastShort, // Unused
    [ANIM_ROTATE_UP_SLAM_DOWN]               = Anim_RotateUpSlamDown,
    [ANIM_DEEP_V_SQUISH_AND_BOUNCE]          = Anim_DeepVerticalSquishBounce,
    [ANIM_H_JUMPS]                           = Anim_HorizontalJumps,
    [ANIM_H_JUMPS_V_STRETCH]                 = Anim_HorizontalJumpsVerticalStretch,
    [ANIM_ROTATE_TO_SIDES_FAST]              = Anim_RotateToSides_Fast, // Unused
    [ANIM_ROTATE_UP_TO_SIDES]                = Anim_RotateUpToSides,
    [ANIM_FLICKER_INCREASING]                = Anim_FlickerIncreasing,
    [ANIM_TIP_HOP_FORWARD]                   = Anim_TipHopForward, // Unused
    [ANIM_PIVOT_SHAKE]                       = Anim_PivotShake, // Unused
    [ANIM_TIP_AND_SHAKE]                     = Anim_TipAndShake, // Unused
    [ANIM_VIBRATE_TO_CORNERS]                = Anim_VibrateToCorners, // Unused
    [ANIM_GROW_IN_STAGES]                    = Anim_GrowInStages,
    [ANIM_V_SPRING]                          = Anim_VerticalSpring, // Unused
    [ANIM_V_REPEATED_SPRING]                 = Anim_VerticalRepeatedSpring, // Unused
    [ANIM_SPRING_RISING]                     = Anim_SpringRising, // Unused
    [ANIM_H_SPRING]                          = Anim_HorizontalSpring,
    [ANIM_H_REPEATED_SPRING_SLOW]            = Anim_HorizontalRepeatedSpring_Slow,
    [ANIM_H_SLIDE_SHRINK]                    = Anim_HorizontalSlideShrink, // Unused
    [ANIM_LUNGE_GROW]                        = Anim_LungeGrow,
    [ANIM_CIRCLE_INTO_BG]                    = Anim_CircleIntoBackground,
    [ANIM_RAPID_H_HOPS]                      = Anim_RapidHorizontalHops,
    [ANIM_FOUR_PETAL]                        = Anim_FourPetal,
    [ANIM_V_SQUISH_AND_BOUNCE_SLOW]          = Anim_VerticalSquishBounce_Slow,
    [ANIM_H_SLIDE_SLOW]                      = Anim_HorizontalSlide_Slow,
    [ANIM_V_SLIDE_SLOW]                      = Anim_VerticalSlide_Slow,
    [ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL]      = Anim_BounceRotateToSides_Small,
    [ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW]       = Anim_BounceRotateToSides_Slow,
    [ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW] = Anim_BounceRotateToSides_SmallSlow,
    [ANIM_ZIGZAG_SLOW]                       = Anim_ZigzagSlow,
    [ANIM_H_SHAKE_SLOW]                      = Anim_HorizontalShake_Slow,
    [ANIM_V_SHAKE_SLOW]                      = Anim_VertialShake_Slow, // Unused
    [ANIM_TWIST_TWICE]                       = Anim_Twist_Twice,
    [ANIM_CIRCLE_C_CLOCKWISE_SLOW]           = Anim_CircleCounterclockwise_Slow,
    [ANIM_V_SHAKE_TWICE_SLOW]                = Anim_VerticalShakeTwice_Slow, // Unused
    [ANIM_V_SLIDE_WOBBLE_SMALL]              = Anim_VerticalSlideWobble_Small,
    [ANIM_V_JUMPS_SMALL]                     = Anim_VerticalJumps_Small,
    [ANIM_SPIN]                              = Anim_Spin,
    [ANIM_TUMBLING_FRONT_FLIP_TWICE]         = Anim_TumblingFrontFlip_Twice,
    [ANIM_DEEP_V_SQUISH_AND_BOUNCE_TWICE]    = Anim_DeepVerticalSquishBounce_Twice, // Unused
    [ANIM_H_JUMPS_V_STRETCH_TWICE]           = Anim_HorizontalJumpsVerticalStretch_Twice,
    [ANIM_V_SHAKE_BACK]                      = Anim_VerticalShakeBack,
    [ANIM_V_SHAKE_BACK_SLOW]                 = Anim_VerticalShakeBack_Slow,
    [ANIM_V_SHAKE_H_SLIDE_SLOW]              = Anim_VerticalShakeHorizontalSlide_Slow,
    [ANIM_V_STRETCH_BOTH_ENDS_SLOW]          = Anim_VerticalStretchBothEnds_Slow,
    [ANIM_H_STRETCH_FAR_SLOW]                = Anim_HorizontalStretchFar_Slow,
    [ANIM_V_SHAKE_LOW_TWICE]                 = Anim_VerticalShakeLowTwice,
    [ANIM_H_SHAKE_FAST]                      = Anim_HorizontalShake_Fast,
    [ANIM_H_SLIDE_FAST]                      = Anim_HorizontalSlide_Fast,
    [ANIM_H_VIBRATE_FAST]                    = Anim_HorizontalVibrate_Fast,
    [ANIM_H_VIBRATE_FASTEST]                 = Anim_HorizontalVibrate_Fastest,
    [ANIM_V_SHAKE_BACK_FAST]                 = Anim_VerticalShakeBack_Fast,
    [ANIM_V_SHAKE_LOW_TWICE_SLOW]            = Anim_VerticalShakeLowTwice_Slow,
    [ANIM_V_SHAKE_LOW_TWICE_FAST]            = Anim_VerticalShakeLowTwice_Fast,
    [ANIM_CIRCLE_C_CLOCKWISE_LONG]           = Anim_CircleCounterclockwise_Long,
    [ANIM_GROW_STUTTER_SLOW]                 = Anim_GrowStutter_Slow,
    [ANIM_V_SHAKE_H_SLIDE]                   = Anim_VerticalShakeHorizontalSlide,
    [ANIM_V_SHAKE_H_SLIDE_FAST]              = Anim_VerticalShakeHorizontalSlide_Fast,
    [ANIM_TRIANGLE_DOWN_SLOW]                = Anim_TriangleDown_Slow,
    [ANIM_TRIANGLE_DOWN]                     = Anim_TriangleDown,
    [ANIM_TRIANGLE_DOWN_TWICE]               = Anim_TriangleDown_Fast,
    [ANIM_GROW]                              = Anim_Grow,
    [ANIM_GROW_TWICE]                        = Anim_Grow_Twice,
    [ANIM_H_SPRING_FAST]                     = Anim_HorizontalSpring_Fast,
    [ANIM_H_SPRING_SLOW]                     = Anim_HorizontalSpring_Slow,
    [ANIM_H_REPEATED_SPRING_FAST]            = Anim_HorizontalRepeatedSpring_Fast,
    [ANIM_H_REPEATED_SPRING]                 = Anim_HorizontalRepeatedSpring,
    [ANIM_SHRINK_GROW_FAST]                  = Anim_ShrinkGrow_Fast,
    [ANIM_SHRINK_GROW_SLOW]                  = Anim_ShrinkGrow_Slow,
    [ANIM_V_STRETCH_BOTH_ENDS]               = Anim_VerticalStretchBothEnds,
    [ANIM_V_STRETCH_BOTH_ENDS_TWICE]         = Anim_VerticalStretchBothEnds_Twice,
    [ANIM_H_STRETCH_FAR_TWICE]               = Anim_HorizontalStretchFar_Twice,
    [ANIM_H_STRETCH_FAR]                     = Anim_HorizontalStretchFar,
    [ANIM_GROW_STUTTER_TWICE]                = Anim_GrowStutter_Twice,
    [ANIM_GROW_STUTTER]                      = Anim_GrowStutter,
    [ANIM_CONCAVE_ARC_LARGE_SLOW]            = Anim_ConcaveArcLarge_Slow,
    [ANIM_CONCAVE_ARC_LARGE]                 = Anim_ConcaveArcLarge,
    [ANIM_CONCAVE_ARC_LARGE_TWICE]           = Anim_ConcaveArcLarge_Twice,
    [ANIM_CONVEX_DOUBLE_ARC_SLOW]            = Anim_ConvexDoubleArc_Slow,
    [ANIM_CONVEX_DOUBLE_ARC]                 = Anim_ConvexDoubleArc,
    [ANIM_CONVEX_DOUBLE_ARC_TWICE]           = Anim_ConvexDoubleArc_Twice,
    [ANIM_CONCAVE_ARC_SMALL_SLOW]            = Anim_ConcaveArcSmall_Slow,
    [ANIM_CONCAVE_ARC_SMALL]                 = Anim_ConcaveArcSmall,
    [ANIM_CONCAVE_ARC_SMALL_TWICE]           = Anim_ConcaveArcSmall_Twice,
    [ANIM_H_DIP]                             = Anim_HorizontalDip,
    [ANIM_H_DIP_FAST]                        = Anim_HorizontalDip_Fast,
    [ANIM_H_DIP_TWICE]                       = Anim_HorizontalDip_Twice,
    [ANIM_SHRINK_GROW_VIBRATE_FAST]          = Anim_ShrinkGrowVibrate_Fast,
    [ANIM_SHRINK_GROW_VIBRATE]               = Anim_ShrinkGrowVibrate,
    [ANIM_SHRINK_GROW_VIBRATE_SLOW]          = Anim_ShrinkGrowVibrate_Slow,
    [ANIM_JOLT_RIGHT_FAST]                   = Anim_JoltRight_Fast,
    [ANIM_JOLT_RIGHT]                        = Anim_JoltRight,
    [ANIM_JOLT_RIGHT_SLOW]                   = Anim_JoltRight_Slow,
    [ANIM_SHAKE_FLASH_YELLOW_FAST]           = Anim_ShakeFlashYellow_Fast,
    [ANIM_SHAKE_FLASH_YELLOW]                = Anim_ShakeFlashYellow,
    [ANIM_SHAKE_FLASH_YELLOW_SLOW]           = Anim_ShakeFlashYellow_Slow,
    [ANIM_SHAKE_GLOW_RED_FAST]               = Anim_ShakeGlowRed_Fast,
    [ANIM_SHAKE_GLOW_RED]                    = Anim_ShakeGlowRed,
    [ANIM_SHAKE_GLOW_RED_SLOW]               = Anim_ShakeGlowRed_Slow,
    [ANIM_SHAKE_GLOW_GREEN_FAST]             = Anim_ShakeGlowGreen_Fast,
    [ANIM_SHAKE_GLOW_GREEN]                  = Anim_ShakeGlowGreen,
    [ANIM_SHAKE_GLOW_GREEN_SLOW]             = Anim_ShakeGlowGreen_Slow,
    [ANIM_SHAKE_GLOW_BLUE_FAST]              = Anim_ShakeGlowBlue_Fast,
    [ANIM_SHAKE_GLOW_BLUE]                   = Anim_ShakeGlowBlue,
    [ANIM_SHAKE_GLOW_BLUE_SLOW]              = Anim_ShakeGlowBlue_Slow,
    [ANIM_SHAKE_GLOW_BLACK_SLOW]             = Anim_ShakeGlowBlack_Slow,
    [ANIM_SHAKE_GLOW_WHITE_SLOW]             = Anim_ShakeGlowWhite_Slow,
    [ANIM_SHAKE_GLOW_PURPLE_SLOW]            = Anim_ShakeGlowPurple_Slow
};

// Each back anim set has 3 possible animations depending on nature
// Each of the 3 animations is a slight variation of the others
// BACK_ANIM_NONE is skipped below. GetSpeciesBackAnimSet subtracts 1 from the back anim id
static const u8 sBackAnimationIds[] =
{
    [(BACK_ANIM_H_VIBRATE - 1) * 3]               = ANIM_H_VIBRATE_FASTEST, ANIM_H_VIBRATE_FAST, ANIM_H_VIBRATE,
    [(BACK_ANIM_H_SLIDE - 1) * 3]                 = ANIM_H_SLIDE_FAST, ANIM_H_SLIDE, ANIM_H_SLIDE_SLOW,
    [(BACK_ANIM_H_SPRING - 1) * 3]                = ANIM_H_SPRING_FAST, ANIM_H_SPRING, ANIM_H_SPRING_SLOW,
    [(BACK_ANIM_H_SPRING_REPEATED - 1) * 3]       = ANIM_H_REPEATED_SPRING_FAST, ANIM_H_REPEATED_SPRING, ANIM_H_REPEATED_SPRING_SLOW,
    [(BACK_ANIM_SHRINK_GROW - 1) * 3]             = ANIM_SHRINK_GROW_FAST, ANIM_SHRINK_GROW, ANIM_SHRINK_GROW_SLOW,
    [(BACK_ANIM_GROW - 1) * 3]                    = ANIM_GROW_TWICE, ANIM_GROW, ANIM_GROW_IN_STAGES,
    [(BACK_ANIM_CIRCLE_COUNTERCLOCKWISE - 1) * 3] = ANIM_CIRCLE_C_CLOCKWISE_LONG, ANIM_CIRCLE_C_CLOCKWISE, ANIM_CIRCLE_C_CLOCKWISE_SLOW,
    [(BACK_ANIM_H_SHAKE - 1) * 3]                 = ANIM_H_SHAKE_FAST, ANIM_H_SHAKE, ANIM_H_SHAKE_SLOW,
    [(BACK_ANIM_V_SHAKE - 1) * 3]                 = ANIM_V_SHAKE_BACK_FAST, ANIM_V_SHAKE_BACK, ANIM_V_SHAKE_BACK_SLOW,
    [(BACK_ANIM_V_SHAKE_H_SLIDE - 1) * 3]         = ANIM_V_SHAKE_H_SLIDE_FAST, ANIM_V_SHAKE_H_SLIDE, ANIM_V_SHAKE_H_SLIDE_SLOW,
    [(BACK_ANIM_V_STRETCH - 1) * 3]               = ANIM_V_STRETCH_BOTH_ENDS_TWICE, ANIM_V_STRETCH_BOTH_ENDS, ANIM_V_STRETCH_BOTH_ENDS_SLOW,
    [(BACK_ANIM_H_STRETCH - 1) * 3]               = ANIM_H_STRETCH_FAR_TWICE, ANIM_H_STRETCH_FAR, ANIM_H_STRETCH_FAR_SLOW,
    [(BACK_ANIM_GROW_STUTTER - 1) * 3]            = ANIM_GROW_STUTTER_TWICE, ANIM_GROW_STUTTER, ANIM_GROW_STUTTER_SLOW,
    [(BACK_ANIM_V_SHAKE_LOW - 1) * 3]             = ANIM_V_SHAKE_LOW_TWICE_FAST, ANIM_V_SHAKE_LOW_TWICE, ANIM_V_SHAKE_LOW_TWICE_SLOW,
    [(BACK_ANIM_TRIANGLE_DOWN - 1) * 3]           = ANIM_TRIANGLE_DOWN_TWICE, ANIM_TRIANGLE_DOWN, ANIM_TRIANGLE_DOWN_SLOW,
    [(BACK_ANIM_CONCAVE_ARC_LARGE - 1) * 3]       = ANIM_CONCAVE_ARC_LARGE_TWICE, ANIM_CONCAVE_ARC_LARGE, ANIM_CONCAVE_ARC_LARGE_SLOW,
    [(BACK_ANIM_CONVEX_DOUBLE_ARC - 1) * 3]       = ANIM_CONVEX_DOUBLE_ARC_TWICE, ANIM_CONVEX_DOUBLE_ARC, ANIM_CONVEX_DOUBLE_ARC_SLOW,
    [(BACK_ANIM_CONCAVE_ARC_SMALL - 1) * 3]       = ANIM_CONCAVE_ARC_SMALL_TWICE, ANIM_CONCAVE_ARC_SMALL, ANIM_CONCAVE_ARC_SMALL_SLOW,
    [(BACK_ANIM_DIP_RIGHT_SIDE - 1) * 3]          = ANIM_H_DIP_TWICE, ANIM_H_DIP, ANIM_H_DIP_FAST,
    [(BACK_ANIM_SHRINK_GROW_VIBRATE - 1) * 3]     = ANIM_SHRINK_GROW_VIBRATE_FAST, ANIM_SHRINK_GROW_VIBRATE, ANIM_SHRINK_GROW_VIBRATE_SLOW,
    [(BACK_ANIM_JOLT_RIGHT - 1) * 3]              = ANIM_JOLT_RIGHT_FAST, ANIM_JOLT_RIGHT, ANIM_JOLT_RIGHT_SLOW,
    [(BACK_ANIM_SHAKE_FLASH_YELLOW - 1) * 3]      = ANIM_SHAKE_FLASH_YELLOW_FAST, ANIM_SHAKE_FLASH_YELLOW, ANIM_SHAKE_FLASH_YELLOW_SLOW,
    [(BACK_ANIM_SHAKE_GLOW_RED - 1) * 3]          = ANIM_SHAKE_GLOW_RED_FAST, ANIM_SHAKE_GLOW_RED, ANIM_SHAKE_GLOW_RED_SLOW,
    [(BACK_ANIM_SHAKE_GLOW_GREEN - 1) * 3]        = ANIM_SHAKE_GLOW_GREEN_FAST, ANIM_SHAKE_GLOW_GREEN, ANIM_SHAKE_GLOW_GREEN_SLOW,
    [(BACK_ANIM_SHAKE_GLOW_BLUE - 1) * 3]         = ANIM_SHAKE_GLOW_BLUE_FAST, ANIM_SHAKE_GLOW_BLUE, ANIM_SHAKE_GLOW_BLUE_SLOW,
};

static const union AffineAnimCmd sMonAffineAnim_0[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    {AFFINEANIMCMDTYPE_END}
};

static const union AffineAnimCmd sMonAffineAnim_1[] =
{
    AFFINEANIMCMD_FRAME(-256, 256, 0, 0),
    {AFFINEANIMCMDTYPE_END}
};

static const union AffineAnimCmd *const sMonAffineAnims[] =
{
    sMonAffineAnim_0,
    sMonAffineAnim_1
};

static void MonAnimDummySpriteCallback(struct Sprite *sprite)
{
}

static void SetPosForRotation(struct Sprite *sprite, u16 index, s16 amplitudeX, s16 amplitudeY)
{
    s16 xAdder, yAdder;

    amplitudeX *= -1;
    amplitudeY *= -1;

    xAdder = Cos(index, amplitudeX) - Sin(index, amplitudeY);
    yAdder = Cos(index, amplitudeY) + Sin(index, amplitudeX);

    amplitudeX *= -1;
    amplitudeY *= -1;

    sprite->x2 = xAdder + amplitudeX;
    sprite->y2 = yAdder + amplitudeY;
}

u8 GetSpeciesBackAnimSet(u16 species)
{
    if (gSpeciesInfo[species].backAnimId != BACK_ANIM_NONE)
        return gSpeciesInfo[species].backAnimId - 1;
    else
        return BACK_ANIM_NONE;
}

#define tState  data[0]
#define tPtrHi  data[1]
#define tPtrLo  data[2]
#define tAnimId data[3]
#define tBattlerId data[4]
#define tSpeciesId data[5]

// BUG: In vanilla, tPtrLo is read as an s16, so if bit 15 of the
// address were to be set it would cause the pointer to be read
// as 0xFFFFXXXX instead of the desired 0x02YYXXXX.
// By dumb luck, this is not an issue in vanilla. However,
// changing the link order revealed this bug.
#if MODERN || defined(BUGFIX)
#define ANIM_SPRITE(taskId)   ((struct Sprite *)((gTasks[taskId].tPtrHi << 16) | ((u16)gTasks[taskId].tPtrLo)))
#else
#define ANIM_SPRITE(taskId)   ((struct Sprite *)((gTasks[taskId].tPtrHi << 16) | (gTasks[taskId].tPtrLo)))
#endif //MODERN || BUGFIX

static void Task_HandleMonAnimation(u8 taskId)
{
    u32 i;
    struct Sprite *sprite = ANIM_SPRITE(taskId);

    if (gTasks[taskId].tState == 0)
    {
        gTasks[taskId].tBattlerId = sprite->data[0];
        gTasks[taskId].tSpeciesId = sprite->data[2];
        sprite->sDontFlip = TRUE;
        sprite->data[0] = 0;

        for (i = 2; i < ARRAY_COUNT(sprite->data); i++)
            sprite->data[i] = 0;

        sprite->callback = sMonAnimFunctions[gTasks[taskId].tAnimId];
        sIsSummaryAnim = FALSE;

        gTasks[taskId].tState++;
    }
    if (sprite->callback == SpriteCallbackDummy)
    {
        sprite->data[0] = gTasks[taskId].tBattlerId;
        sprite->data[2] = gTasks[taskId].tSpeciesId;
        sprite->data[1] = 0;

        DestroyTask(taskId);
    }
}

void LaunchAnimationTaskForFrontSprite(struct Sprite *sprite, u8 frontAnimId)
{
    u8 taskId = CreateTask(Task_HandleMonAnimation, 128);
    gTasks[taskId].tPtrHi = (u32)(sprite) >> 16;
    gTasks[taskId].tPtrLo = (u32)(sprite);
    gTasks[taskId].tAnimId = frontAnimId;
}

void StartMonSummaryAnimation(struct Sprite *sprite, u8 frontAnimId)
{
    // sDontFlip is expected to still be FALSE here, not explicitly cleared
    sIsSummaryAnim = TRUE;
    sprite->callback = sMonAnimFunctions[frontAnimId];
}

void LaunchAnimationTaskForBackSprite(struct Sprite *sprite, u8 backAnimSet)
{
    u8 nature, taskId, animId, battlerId;

    taskId = CreateTask(Task_HandleMonAnimation, 128);
    gTasks[taskId].tPtrHi = (u32)(sprite) >> 16;
    gTasks[taskId].tPtrLo = (u32)(sprite);

    battlerId = sprite->data[0];
    nature = GetNature(&gPlayerParty[gBattlerPartyIndexes[battlerId]]);

    // * 3 below because each back anim has 3 variants depending on nature
    animId = 3 * backAnimSet + gNaturesInfo[nature].backAnim;
    gTasks[taskId].tAnimId = sBackAnimationIds[animId];
}

#undef tState
#undef tPtrHi
#undef tPtrLo
#undef tAnimId
#undef tBattlerId
#undef tSpeciesId

void SetSpriteCB_MonAnimDummy(struct Sprite *sprite)
{
    sprite->callback = MonAnimDummySpriteCallback;
}

static void SetAffineData(struct Sprite *sprite, s16 xScale, s16 yScale, u16 rotation)
{
    u8 matrixNum;
    struct ObjAffineSrcData affineSrcData;
    struct OamMatrix dest;

    affineSrcData.xScale = xScale;
    affineSrcData.yScale = yScale;
    affineSrcData.rotation = rotation;

    matrixNum = sprite->oam.matrixNum;

    ObjAffineSet(&affineSrcData, &dest, 1, 2);
    gOamMatrices[matrixNum].a = dest.a;
    gOamMatrices[matrixNum].b = dest.b;
    gOamMatrices[matrixNum].c = dest.c;
    gOamMatrices[matrixNum].d = dest.d;
}

static void HandleStartAffineAnim(struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    sprite->affineAnims = sMonAffineAnims;

    if (sIsSummaryAnim == TRUE)
        InitSpriteAffineAnim(sprite);

    if (!sprite->sDontFlip)
        StartSpriteAffineAnim(sprite, 1);
    else
        StartSpriteAffineAnim(sprite, 0);

    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
    sprite->affineAnimPaused = TRUE;
}

static void HandleSetAffineData(struct Sprite *sprite, s16 xScale, s16 yScale, u16 rotation)
{
    if (!sprite->sDontFlip)
    {
        xScale *= -1;
        rotation *= -1;
    }

    SetAffineData(sprite, xScale, yScale, rotation);
}

static void TryFlipX(struct Sprite *sprite)
{
    if (!sprite->sDontFlip)
        sprite->x2 *= -1;
}

static bool32 InitAnimData(u8 id)
{
    if (id >= MAX_BATTLERS_COUNT)
    {
        return FALSE;
    }
    else
    {
        sAnims[id].rotation = 0;
        sAnims[id].delay = 0;
        sAnims[id].runs = 1;
        sAnims[id].speed = 0;
        sAnims[id].data = 0;
        return TRUE;
    }
}

static u8 AddNewAnim(void)
{
    sAnimIdx = (sAnimIdx + 1) % MAX_BATTLERS_COUNT;
    InitAnimData(sAnimIdx);
    return sAnimIdx;
}

static void ResetSpriteAfterAnim(struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);

    if (sIsSummaryAnim == TRUE)
    {
        if (!sprite->sDontFlip)
            sprite->hFlip = TRUE;
        else
            sprite->hFlip = FALSE;

        FreeOamMatrix(sprite->oam.matrixNum);
        sprite->oam.matrixNum |= (sprite->hFlip << 3);
        sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
    }
#ifdef BUGFIX
    else
    {
        // FIX: Reset these back to normal after they were changed so Poké Ball catch/release
        // animations without a screen transition in between don't break
        sprite->affineAnims = gAffineAnims_BattleSpriteOpponentSide;
    }
#endif // BUGFIX
}

static void Anim_CircularStretchTwice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 var = (sprite->data[2] * 512 / 40) % 256;

        sprite->data[4] = Sin(var, 32) + 256;
        sprite->data[5] = Cos(var, 32) + 256;
        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

static void Anim_HorizontalVibrate(struct Sprite *sprite)
{
    if (sprite->data[2] > 40)
    {
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
    }
    else
    {
        s8 sign;
        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        sprite->x2 = Sin((sprite->data[2] * 128 / 40) % 256, 6) * sign;
    }

    sprite->data[2]++;
}

static void HorizontalSlide(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[2] > sprite->data[0])
    {
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
    }
    else
    {
        sprite->x2 = Sin((sprite->data[2] * 384 / sprite->data[0]) % 256, 6);
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

static void Anim_HorizontalSlide(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    HorizontalSlide(sprite);
    sprite->callback = HorizontalSlide;
}

static void VerticalSlide(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[2] > sprite->data[0])
    {
        sprite->callback = WaitAnimEnd;
        sprite->y2 = 0;
    }
    else
    {
        sprite->y2 = -(Sin((sprite->data[2] * 384 / sprite->data[0]) % 256, 6));
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

static void Anim_VerticalSlide(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    VerticalSlide(sprite);
    sprite->callback = VerticalSlide;
}

static void VerticalJumps(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];
    if (counter > 384)
    {
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        s16 divCounter = counter / 128;
        switch (divCounter)
        {
        case 0:
        case 1:
            sprite->y2 = -(Sin(counter % 128, sprite->data[0] * 2));
            break;
        case 2:
        case 3:
            counter -= 256;
            sprite->y2 = -(Sin(counter, sprite->data[0] * 3));
            break;
        }
    }

    sprite->data[2] += 12;
}

static void Anim_VerticalJumps_Big(struct Sprite *sprite)
{
    sprite->data[0] = 4;
    VerticalJumps(sprite);
    sprite->callback = VerticalJumps;
}

static void Anim_VerticalJumpsHorizontalJumps(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 768)
    {
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        s16 divCounter = counter / 128;

        switch (divCounter)
        {
        case 0:
        case 1:
            sprite->x2 = 0;
            break;
        case 2:
            counter = 0;
            break;
        case 3:
            sprite->x2 = -(counter % 128 * 8) / 128;
            break;
        case 4:
            sprite->x2 = (counter % 128) / 8 - 8;
            break;
        case 5:
            sprite->x2 = -(counter % 128 * 8) / 128 + 8;
            break;
        }

        sprite->y2 = -(Sin(counter % 128, 8));
    }

    sprite->data[2] += 12;
}

static void Anim_GrowVibrate(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] * 256 / 40) % 256;

        if (sprite->data[2] % 2 == 0)
        {
            sprite->data[4] = Sin(index, 32) + 256;
            sprite->data[5] = Sin(index, 32) + 256;
        }
        else
        {
            sprite->data[4] = Sin(index, 8) + 256;
            sprite->data[5] = Sin(index, 8) + 256;
        }

        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

// x delta, y delta, time
static const s8 sZigzagData[][3] =
{
    {-1, -1, 6},
    { 2,  0, 6},
    {-2,  2, 6},
    { 2,  0, 6},
    {-2, -2, 6},
    { 2,  0, 6},
    {-2,  2, 6},
    { 2,  0, 6},
    {-1, -1, 6},
    { 0,  0, 0},
};

static void Zigzag(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[2] == 0)
        sprite->data[3] = 0;

    if (sZigzagData[sprite->data[3]][2] == sprite->data[2])
    {
        if (sZigzagData[sprite->data[3]][2] == 0)
        {
            sprite->callback = WaitAnimEnd;
        }
        else
        {
            sprite->data[3]++;
            sprite->data[2] = 0;
        }
    }

    if (sZigzagData[sprite->data[3]][2] == 0)
    {
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        sprite->x2 += sZigzagData[sprite->data[3]][0];
        sprite->y2 += sZigzagData[sprite->data[3]][1];
        sprite->data[2]++;
        TryFlipX(sprite);
    }
}

static void Anim_ZigzagFast(struct Sprite *sprite)
{
    Zigzag(sprite);
    sprite->callback = Zigzag;
}

static void HorizontalShake(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 2304)
    {
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
    }
    else
    {
        sprite->x2 = Sin(counter % 256, sprite->data[7]);
    }

    sprite->data[2] += sprite->data[0];
}

static void Anim_HorizontalShake(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    sprite->data[7] = 3;
    HorizontalShake(sprite);
    sprite->callback = HorizontalShake;
}

static void VerticalShake(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 2304)
    {
        sprite->callback = WaitAnimEnd;
        sprite->y2 = 0;
    }
    else
    {
        sprite->y2 = Sin(counter % 256, 3);
    }

    sprite->data[2] += sprite->data[0];
}

static void Anim_VerticalShake(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    VerticalShake(sprite);
    sprite->callback = VerticalShake;
}

static void Anim_CircularVibrate(struct Sprite *sprite)
{
    if (sprite->data[2] > 512)
    {
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        s8 sign;
        s32 index, amplitude;

        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        amplitude = Sin(sprite->data[2] / 4, 8);
        index = sprite->data[2] % 256;

        sprite->y2 = Sin(index, amplitude) * sign;
        sprite->x2 = Cos(index, amplitude) * sign;
    }

    sprite->data[2] += 9;
}

static void Twist(struct Sprite *sprite)
{
    s16 id = sprite->data[0];

    if (sAnims[id].delay != 0)
    {
        sAnims[id].delay--;
    }
    else
    {
        if (sprite->data[2] == 0 && sAnims[id].data == 0)
        {
            HandleStartAffineAnim(sprite);
            sAnims[id].data++;
        }

        if (sprite->data[2] > sAnims[id].rotation)
        {
            HandleSetAffineData(sprite, 256, 256, 0);

            if (sAnims[id].runs > 1)
            {
                sAnims[id].runs--;
                sAnims[id].delay = 10;
                sprite->data[2] = 0;
            }
            else
            {
                ResetSpriteAfterAnim(sprite);
                sprite->callback = WaitAnimEnd;
            }
        }
        else
        {
            sprite->data[6] = Sin(sprite->data[2] % 256, 4096);
            HandleSetAffineData(sprite, 256, 256, sprite->data[6]);
        }

        sprite->data[2] += 16;
    }
}

static void Anim_Twist(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].rotation = 512;
    sAnims[id].delay = 0;
    Twist(sprite);
    sprite->callback = Twist;
}

static void Spin(struct Sprite *sprite)
{
    u8 id = sprite->data[0];

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > sAnims[id].delay)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        sprite->data[6] = (65536 / sAnims[id].data) * sprite->data[2];
        HandleSetAffineData(sprite, 256, 256, sprite->data[6]);
    }

    sprite->data[2]++;
}

static void Anim_Spin_Long(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].delay = 60;
    sAnims[id].data = 20;
    Spin(sprite);
    sprite->callback = Spin;
}

static void CircleCounterclockwise(struct Sprite *sprite)
{
    u8 id = sprite->data[0];

    TryFlipX(sprite);

    if (sprite->data[2] > sAnims[id].rotation)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] + 192) % 256;

        sprite->x2 = -(Cos(index, sAnims[id].data * 2));
        sprite->y2 = Sin(index, sAnims[id].data) + sAnims[id].data;
    }

    sprite->data[2] += sAnims[id].speed;
    TryFlipX(sprite);
}

static void Anim_CircleCounterclockwise(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].rotation = 512;
    sAnims[id].data = 6;
    sAnims[id].speed = 24;
    CircleCounterclockwise(sprite);
    sprite->callback = CircleCounterclockwise;
}

#define GlowColor(color, colorIncrement, speed)                         \
{                                                                       \
    if (sprite->data[2] == 0)                                           \
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);          \
                                                                        \
    if (sprite->data[2] > 128)                                          \
    {                                                                   \
        BlendPalette(sprite->data[7], 16, 0, (color));                  \
        sprite->callback = WaitAnimEnd;                                 \
    }                                                                   \
    else                                                                \
    {                                                                   \
        sprite->data[6] = Sin(sprite->data[2], (colorIncrement));       \
        BlendPalette(sprite->data[7], 16, sprite->data[6], (color));    \
    }                                                                   \
    sprite->data[2] += (speed);                                         \
}

static void Anim_GlowBlack(struct Sprite *sprite)
{
    GlowColor(RGB_BLACK, 16, 1);
}

static void Anim_HorizontalStretch(struct Sprite *sprite)
{
    s16 index1 = 0, index2 = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        index2 = (sprite->data[2] * 128) / 40;

        if (sprite->data[2] >= 10 && sprite->data[2] <= 29)
        {
            sprite->data[7] += 51;
            index1 = 0xFF & sprite->data[7];
        }

        if (!sprite->sDontFlip)
            sprite->data[4] = (Sin(index2, 40) - 256) + Sin(index1, 16);
        else
            sprite->data[4] = (256 - Sin(index2, 40)) - Sin(index1, 16);

        sprite->data[5] = Sin(index2, 16) + 256;
        SetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

static void Anim_VerticalStretch(struct Sprite *sprite)
{
    s16 posY = 0, index1 = 0, index2 = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
        sprite->y2 = posY;
    }
    else
    {
        index2 = (sprite->data[2] * 128) / 40;

        if (sprite->data[2] >= 10 && sprite->data[2] <= 29)
        {
            sprite->data[7] += 51;
            index1 = 0xFF & sprite->data[7];
        }

        if (!sprite->sDontFlip)
            sprite->data[4] = -(Sin(index2, 16)) - 256;
        else
            sprite->data[4] = Sin(index2, 16) + 256;

        sprite->data[5] = (256 - Sin(index2, 40)) - Sin(index1, 8);

        if (sprite->data[5] != 256)
            posY = (256 - sprite->data[5]) / 8;

        sprite->y2 = -(posY);
        SetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

static void VerticalShakeTwice(struct Sprite *sprite)
{
    u8 index = sprite->data[2];
    u8 var7 = sprite->data[6];
    u8 var5 = sVerticalShakeData[sprite->data[5]][0];
    u8 var6 = sVerticalShakeData[sprite->data[5]][1];
    u8 amplitude = 0;

    if (var5 != (u8)-2)
        amplitude = (var6 - var7) * var5 / var6;
    else
        amplitude = 0;

    if (var5 == (u8)-1)
    {
        sprite->callback = WaitAnimEnd;
        sprite->y2 = 0;
    }
    else
    {
        sprite->y2 = Sin(index, amplitude);

        if (var7 == var6)
        {
            sprite->data[5]++;
            sprite->data[6] = 0;
        }
        else
        {
            sprite->data[2] += sprite->data[0];
            sprite->data[6]++;
        }
    }
}

static void Anim_VerticalShakeTwice(struct Sprite *sprite)
{
    sprite->data[0] = 48;
    VerticalShakeTwice(sprite);
    sprite->callback = VerticalShakeTwice;
}

static void Anim_TipMoveForward(struct Sprite *sprite)
{
    u8 counter = 0;

    TryFlipX(sprite);
    counter = sprite->data[2];

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 35)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
    }
    else
    {
        s16 index = ((counter - 10) * 128) / 20;

        if (counter < 10)
            HandleSetAffineData(sprite, 256, 256, counter / 2 * 512);
        else if (counter >= 10 && counter <= 29)
            sprite->x2 = -(Sin(index, 5));
        else
            HandleSetAffineData(sprite, 256, 256, (35 - counter) / 2 * 1024);
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

static void Anim_HorizontalPivot(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] * 256) / 100;
        sprite->y2 = Sin(index, 10);
        HandleSetAffineData(sprite, 256, 256, Sin(index, 3276));
    }

    sprite->data[2]++;
}

static void VerticalSlideWobble(struct Sprite *sprite)
{
    s32 var = 0;
    s16 index = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        index = (sprite->data[2] * 256) / 100;
        var = (sprite->data[2] * 512) / 100;
        var &= 0xFF;
        sprite->y2 = Sin(index, sprite->data[0]);
        HandleSetAffineData(sprite, 256, 256, Sin(var, 3276));
    }

    sprite->data[2]++;
}

static void Anim_VerticalSlideWobble(struct Sprite *sprite)
{
    sprite->data[0] = 10;
    VerticalSlideWobble(sprite);
    sprite->callback = VerticalSlideWobble;
}

static void RisingWobble(struct Sprite *sprite)
{
    s32 var = 0;
    s16 index = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        index = (sprite->data[2] * 256) / 100;
        var = (sprite->data[2] * 512) / 100;
        var &= 0xFF;
        sprite->y2 = -(Sin(index / 2, sprite->data[0] * 2));
        HandleSetAffineData(sprite, 256, 256, Sin(var, 3276));
    }

    sprite->data[2]++;
}

static void Anim_RisingWobble(struct Sprite *sprite)
{
    sprite->data[0] = 5;
    RisingWobble(sprite);
    sprite->callback = RisingWobble;
}

static void Anim_HorizontalSlideWobble(struct Sprite *sprite)
{
    s32 var;
    s16 index = 0;

    TryFlipX(sprite);
    var = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        index = (sprite->data[2] * 256) / 100;
        var = (sprite->data[2] * 512) / 100;
        var &= 0xFF;
        sprite->x2 = Sin(index, 8);
        HandleSetAffineData(sprite, 256, 256, Sin(var, 3276));
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

static void VerticalSquishBounce(struct Sprite *sprite)
{
    s16 posY = 0;

    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[3] = 0;
    }

    TryFlipX(sprite);

    if (sprite->data[2] > sprite->data[0] * 3)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 yScale = Sin(sprite->data[4], 32) + 256;

        if (sprite->data[2] > sprite->data[0] && sprite->data[2] < sprite->data[0] * 2)
            sprite->data[3] += (128 / sprite->data[0]);
        if (yScale > 256)
            posY = (256 - yScale) / 8;

        sprite->y2 = -(Sin(sprite->data[3], 10)) - posY;
        HandleSetAffineData(sprite, 256 - Sin(sprite->data[4], 32), yScale, 0);
        sprite->data[2]++;
        sprite->data[4] = (sprite->data[4] + 128 / sprite->data[0]) & 0xFF;
    }

    TryFlipX(sprite);
}

static void Anim_VerticalSquishBounce(struct Sprite *sprite)
{
    sprite->data[0] = 16;
    VerticalSquishBounce(sprite);
    sprite->callback = VerticalSquishBounce;
}

static void ShrinkGrow(struct Sprite *sprite)
{
    s16 posY = 0;

    if (sprite->data[2] > (128 / sprite->data[6]) * sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 yScale = Sin(sprite->data[4], 32) + 256;

        if (yScale > 256)
            posY = (256 - yScale) / 8;

        sprite->y2 = -(posY);
        HandleSetAffineData(sprite, Sin(sprite->data[4], 48) + 256, yScale, 0);
        sprite->data[2]++;
        sprite->data[4] = (sprite->data[4] + sprite->data[6]) & 0xFF;
    }
}

static void Anim_ShrinkGrow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 3;
        sprite->data[6] = 8;
    }

    ShrinkGrow(sprite);
}

static const s8 sBounceRotateToSidesData[][8][3] =
{
    {
        { 0,  8,  8},
        { 8, -8, 12},
        {-8,  8, 12},
        { 8, -8, 12},
        {-8,  8, 12},
        { 8, -8, 12},
        {-8,  0, 12},
        { 0,  0,  0}
    },
    {
        { 0,  8, 16},
        { 8, -8, 24},
        {-8,  8, 24},
        { 8, -8, 24},
        {-8,  8, 24},
        { 8, -8, 24},
        {-8,  0, 24},
        { 0,  0,  0}
    },
};

static void BounceRotateToSides(struct Sprite *sprite)
{
    s16 var;
    u8 structId;
    s8 r9;
    s16 r10;
    s16 r7;
    u32 arrId;

    TryFlipX(sprite);
    structId = sprite->data[0];
    var = sAnims[structId].rotation;
    r9 = sBounceRotateToSidesData[sAnims[structId].data][sprite->data[4]][0];
    r10 = sBounceRotateToSidesData[sAnims[structId].data][sprite->data[4]][1] - r9;
    arrId = sAnims[structId].data;
    r7 = sprite->data[3];

    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
    }

    if (sBounceRotateToSidesData[arrId][sprite->data[4]][2] == 0)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        u16 rotation;

        sprite->y2 = -(Sin(r7 * 128 / sBounceRotateToSidesData[arrId][sprite->data[4]][2], 10));
        sprite->x2 = (r10 * r7 / sBounceRotateToSidesData[arrId][sprite->data[4]][2]) + r9;

        rotation = -(var * sprite->x2) / 8;
        HandleSetAffineData(sprite, 256, 256, rotation);

        if (r7 == sBounceRotateToSidesData[arrId][sprite->data[4]][2])
        {
            sprite->data[4]++;
            sprite->data[3] = 0;
        }
        else
        {
            sprite->data[3]++;
        }
    }

    TryFlipX(sprite);
}

static void Anim_BounceRotateToSides(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();
    sAnims[id].rotation = 4096;
    sAnims[id].data = sprite->data[6];
    BounceRotateToSides(sprite);
    sprite->callback = BounceRotateToSides;
}

static void Anim_GlowOrange(struct Sprite *sprite)
{
    GlowColor(RGB(31, 22, 0), 12, 2);
}

static void Anim_GlowRed(struct Sprite *sprite)
{
    GlowColor(RGB_RED, 12, 2);
}

static void Anim_GlowBlue(struct Sprite *sprite)
{
    GlowColor(RGB_BLUE, 12, 2);
}

static void Anim_GlowYellow(struct Sprite *sprite)
{
    GlowColor(RGB_YELLOW, 12, 2);
}

static void Anim_GlowPurple(struct Sprite *sprite)
{
    GlowColor(RGB_PURPLE, 12, 2);
}

static void BackAndLunge_0(struct Sprite *sprite);
static void BackAndLunge_1(struct Sprite *sprite);
static void BackAndLunge_2(struct Sprite *sprite);
static void BackAndLunge_3(struct Sprite *sprite);
static void BackAndLunge_4(struct Sprite *sprite);

static void Anim_BackAndLunge(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = BackAndLunge_0;
}

static void BackAndLunge_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (++sprite->x2 > 7)
    {
        sprite->x2 = 8;
        sprite->data[7] = 2;
        sprite->callback = BackAndLunge_1;
    }
    TryFlipX(sprite);
}

static void BackAndLunge_1(struct Sprite *sprite)
{
    TryFlipX(sprite);

    sprite->x2 -= sprite->data[7];
    sprite->data[7]++;
    if (sprite->x2 <= 0)
    {
        s16 subResult;
        u8 var = sprite->data[7];
        sprite->data[6] = 0;
        subResult = sprite->x2;

        do
        {
            subResult -= var;
            sprite->data[6]++;
            var++;
        }
        while (subResult > -8);

        sprite->data[5] = 1;
        sprite->callback = BackAndLunge_2;
    }

    TryFlipX(sprite);
}

static void BackAndLunge_2(struct Sprite *sprite)
{
    u8 rotation;

    TryFlipX(sprite);
    sprite->x2 -= sprite->data[7];
    sprite->data[7]++;
    rotation = (sprite->data[5] * 6) / sprite->data[6];

    if (++sprite->data[5] > sprite->data[6])
        sprite->data[5] = sprite->data[6];

    HandleSetAffineData(sprite, 256, 256, rotation * 256);

    if (sprite->x2 < -8)
    {
        sprite->x2 = -8;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[2] = rotation;
        sprite->callback = BackAndLunge_3;
    }

    TryFlipX(sprite);
}

static void BackAndLunge_3(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[3] > 11)
    {
        sprite->data[2] -= 2;
        if (sprite->data[2] < 0)
            sprite->data[2] = 0;

        HandleSetAffineData(sprite, 256, 256, sprite->data[2] << 8);
        if (sprite->data[2] == 0)
            sprite->callback = BackAndLunge_4;
    }
    else
    {
        sprite->x2 += sprite->data[4];
        sprite->data[4] *= -1;
        sprite->data[3]++;
    }

    TryFlipX(sprite);
}

static void BackAndLunge_4(struct Sprite *sprite)
{
    TryFlipX(sprite);

    sprite->x2 += 2;
    if (sprite->x2 > 0)
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }

    TryFlipX(sprite);
}

static void BackFlip_0(struct Sprite *sprite);
static void BackFlip_1(struct Sprite *sprite);
static void BackFlip_2(struct Sprite *sprite);

static void Anim_BackFlip(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[3] = 0;
    sprite->callback = BackFlip_0;
}

static void BackFlip_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2++;
    sprite->y2--;

    if (sprite->x2 % 2 == 0 && sprite->data[3] <= 0)
        sprite->data[3] = 10;
    if (sprite->x2 > 7)
    {
        sprite->x2 = 8;
        sprite->y2 = -8;
        sprite->data[4] = 0;
        sprite->callback = BackFlip_1;
    }

    TryFlipX(sprite);
}

static void BackFlip_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 = Cos(sprite->data[4], 16) - 8;
    sprite->y2 = Sin(sprite->data[4], 16) - 8;

    if (sprite->data[4] > 63)
    {
        sprite->data[2] = 160;
        sprite->data[3] = 10;
        sprite->callback = BackFlip_2;
    }
    sprite->data[4] += 8;
    if (sprite->data[4] > 64)
        sprite->data[4] = 64;

    TryFlipX(sprite);
}

static void BackFlip_2(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[3] > 0)
    {
        sprite->data[3]--;
    }
    else
    {
        u32 rotation;

        sprite->x2 = Cos(sprite->data[2], 5) - 4;
        sprite->y2 = -(Sin(sprite->data[2], 5)) + 4;
        sprite->data[2] -= 4;
        rotation = sprite->data[2] - 32;
        HandleSetAffineData(sprite, 256, 256, rotation * 512);

        if (sprite->data[2] <= 32)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
        }
    }

    TryFlipX(sprite);
}

static void Anim_Flicker(struct Sprite *sprite)
{
    if (sprite->data[3] > 0)
    {
        sprite->data[3]--;
    }
    else
    {
        sprite->data[4] = (sprite->data[4] == 0) ? TRUE : FALSE;
        sprite->invisible = sprite->data[4];
        if (++sprite->data[2] > 19)
        {
            sprite->invisible = FALSE;
            sprite->callback = WaitAnimEnd;
        }
        sprite->data[3] = 2;
    }
}

static void BackFlipBig_0(struct Sprite *sprite);
static void BackFlipBig_1(struct Sprite *sprite);
static void BackFlipBig_2(struct Sprite *sprite);

static void Anim_BackFlipBig(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = BackFlipBig_0;
}

static void BackFlipBig_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2--;
    sprite->y2++;

    if (sprite->x2 <= -16)
    {
        sprite->x2 = -16;
        sprite->y2 = 16;
        sprite->callback = BackFlipBig_1;
        sprite->data[2] = 160;
    }

    TryFlipX(sprite);
}

static void BackFlipBig_1(struct Sprite *sprite)
{
    u32 rotation;

    TryFlipX(sprite);
    sprite->data[2] -= 4;
    sprite->x2 = Cos(sprite->data[2], 22);
    sprite->y2 = -(Sin(sprite->data[2], 22));
    rotation = sprite->data[2] - 32;
    HandleSetAffineData(sprite, 256, 256, rotation * 512);

    if (sprite->data[2] <= 32)
        sprite->callback = BackFlipBig_2;

    TryFlipX(sprite);
}

static void BackFlipBig_2(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2--;
    sprite->y2++;

    if (sprite->x2 <= 0)
    {
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }

    TryFlipX(sprite);
}

static void FrontFlip_0(struct Sprite *sprite);
static void FrontFlip_1(struct Sprite *sprite);
static void FrontFlip_2(struct Sprite *sprite);

static void Anim_FrontFlip(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = FrontFlip_0;
}

static void FrontFlip_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2++;
    sprite->y2--;

    if (sprite->x2 > 15)
    {
        sprite->data[2] = 0;
        sprite->callback = FrontFlip_1;
    }

    TryFlipX(sprite);
}

static void FrontFlip_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->data[2] += 16;

    if (sprite->x2 <= -16)
    {
        sprite->x2 = -16;
        sprite->y2 = 16;
        sprite->data[2] = 0;
        sprite->callback = FrontFlip_2;
    }
    else
    {
        sprite->x2 -= 2;
        sprite->y2 += 2;
    }

    HandleSetAffineData(sprite, 256, 256, sprite->data[2] << 8);
    TryFlipX(sprite);
}

static void FrontFlip_2(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2++;
    sprite->y2--;;

    if (sprite->x2 >= 0)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }

    TryFlipX(sprite);
}

static void TumblingFrontFlip(struct Sprite *sprite);

static void Anim_TumblingFrontFlip(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();
    sAnims[id].speed = 2;
    TumblingFrontFlip(sprite);
    sprite->callback = TumblingFrontFlip;
}

static void TumblingFrontFlip(struct Sprite *sprite)
{
    if (sAnims[sprite->data[0]].delay != 0)
    {
        sAnims[sprite->data[0]].delay--;
    }
    else
    {
        TryFlipX(sprite);
        if (sprite->data[2] == 0)
        {
            sprite->data[2]++;
            HandleStartAffineAnim(sprite);
            sprite->data[7] = sAnims[sprite->data[0]].speed;
            sprite->data[3] = -1;
            sprite->data[4] = -1;
            sprite->data[5] = 0;
            sprite->data[6] = 0;
        }

        sprite->x2 += (sprite->data[7] * 2 * sprite->data[3]);
        sprite->y2 += (sprite->data[7] * sprite->data[4]);
        sprite->data[6] += 8;
        if (sprite->x2 <= -16 || sprite->x2 >= 16)
        {
            sprite->x2 = sprite->data[3] * 16;
            sprite->data[3] *= -1;
            sprite->data[5]++;
        }
        else if (sprite->y2 <= -16 || sprite->y2 >= 16)
        {
            sprite->y2 = sprite->data[4] * 16;
            sprite->data[4] *= -1;
            sprite->data[5]++;
        }

        if (sprite->data[5] > 5 && sprite->x2 <= 0)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            if (sAnims[sprite->data[0]].runs > 1)
            {
                sAnims[sprite->data[0]].runs--;
                sprite->data[5] = 0;
                sprite->data[6] = 0;
                sAnims[sprite->data[0]].delay = 10;
            }
            else
            {
                ResetSpriteAfterAnim(sprite);
                sprite->callback = WaitAnimEnd;
            }
        }

        HandleSetAffineData(sprite, 256, 256, sprite->data[6] << 8);
        TryFlipX(sprite);
    }
}

static void Figure8(struct Sprite *sprite);

static void Anim_Figure8(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[6] = 0;
    sprite->data[7] = 0;
    sprite->callback = Figure8;
}

static void Figure8(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->data[6] += 4;
    sprite->x2 = -(Sin(sprite->data[6], 16));
    sprite->y2 = -(Sin((sprite->data[6] * 2) & 0xFF, 8));
    if (sprite->data[6] > 192 && sprite->data[7] == 1)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->data[7]++;
    }
    else if (sprite->data[6] > 64 && sprite->data[7] == 0)
    {
        HandleSetAffineData(sprite, -256, 256, 0);
        sprite->data[7]++;
    }

    if (sprite->data[6] > 255)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    TryFlipX(sprite);
}

static void Anim_FlashYellow(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
    }

    if (sYellowFlashData[sprite->data[6]][1] == (u8)-1)
    {
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        if (sprite->data[4] == 1)
        {
            if (sYellowFlashData[sprite->data[6]][0])
                BlendPalette(sprite->data[7], 16, 16, RGB_YELLOW);
            else
                BlendPalette(sprite->data[7], 16, 0, RGB_YELLOW);

            sprite->data[4] = 0;
        }

        if (sYellowFlashData[sprite->data[6]][1] == sprite->data[5])
        {
            sprite->data[4] = 1;
            sprite->data[5] = 0;
            sprite->data[6]++;
        }
        else
        {
            sprite->data[5]++;
        }
    }
}

static void SwingConcave(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    TryFlipX(sprite);
    if (sprite->data[2] > sAnims[sprite->data[0]].data)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        if (sAnims[sprite->data[0]].runs > 1)
        {
            sAnims[sprite->data[0]].runs--;
            sprite->data[2] = 0;
        }
        else
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
        }
    }
    else
    {
        s16 index = (sprite->data[2] * 256) / sAnims[sprite->data[0]].data;
        sprite->x2 = -(Sin(index, 10));
        HandleSetAffineData(sprite, 256, 256, Sin(index, 3276));
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

static void Anim_SwingConcave_FastShort(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();
    sAnims[id].data = 50;
    SwingConcave(sprite);
    sprite->callback = SwingConcave;
}

static void SwingConvex(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    TryFlipX(sprite);
    if (sprite->data[2] > sAnims[sprite->data[0]].data)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        if (sAnims[sprite->data[0]].runs > 1)
        {
            sAnims[sprite->data[0]].runs--;
            sprite->data[2] = 0;
        }
        else
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
        }
    }
    else
    {
        s16 index = (sprite->data[2] * 256) / sAnims[sprite->data[0]].data;
        sprite->x2 = -(Sin(index, 10));
        HandleSetAffineData(sprite, 256, 256, -(Sin(index, 3276)));
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

static void Anim_SwingConvex_FastShort(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();
    sAnims[id].data = 50;
    SwingConvex(sprite);
    sprite->callback = SwingConvex;
}

static void RotateUpSlamDown_0(struct Sprite *sprite);
static void RotateUpSlamDown_1(struct Sprite *sprite);
static void RotateUpSlamDown_2(struct Sprite *sprite);

static void Anim_RotateUpSlamDown(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[6] = -(14 * sprite->centerToCornerVecX / 10);
    sprite->data[7] = 128;
    sprite->callback = RotateUpSlamDown_0;
}

static void RotateUpSlamDown_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->data[7]--;
    sprite->x2 = sprite->data[6] + Cos(sprite->data[7], sprite->data[6]);

    sprite->y2 = -(Sin(sprite->data[7], sprite->data[6]));

    HandleSetAffineData(sprite, 256, 256, (sprite->data[7] - 128) << 8);
    if (sprite->data[7] <= 120)
    {
        sprite->data[7] = 120;
        sprite->data[3] = 0;
        sprite->callback = RotateUpSlamDown_1;
    }

    TryFlipX(sprite);
}

static void RotateUpSlamDown_1(struct Sprite *sprite)
{
    if (sprite->data[3] == 20)
    {
        sprite->callback = RotateUpSlamDown_2;
        sprite->data[3] = 0;
    }

    sprite->data[3]++;
}

static void RotateUpSlamDown_2(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->data[7] += 2;
    sprite->x2 = sprite->data[6] + Cos(sprite->data[7], sprite->data[6]);

    sprite->y2 = -(Sin(sprite->data[7], sprite->data[6]));

    HandleSetAffineData(sprite, 256, 256, (sprite->data[7] - 128) << 8);
    if (sprite->data[7] >= 128)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->data[2] = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = Anim_VerticalShake;
    }

    TryFlipX(sprite);
}

static void DeepVerticalSquishBounce(struct Sprite *sprite)
{
    if (sAnims[sprite->data[0]].delay != 0)
    {
        sAnims[sprite->data[0]].delay--;
    }
    else
    {
        if (sprite->data[2] == 0)
        {
            HandleStartAffineAnim(sprite);
            sprite->data[4] = 0;
            sprite->data[5] = 0;
            sprite->data[2] = 1;
        }

        if (sprite->data[5] == 0)
        {
            sprite->data[7] = Sin(sprite->data[4], 256);
            sprite->y2 = Sin(sprite->data[4], 16);
            sprite->data[6] = Sin(sprite->data[4], 32);
            HandleSetAffineData(sprite, 256 - sprite->data[6], 256 + sprite->data[7], 0);
            if (sprite->data[4] == 128)
            {
                sprite->data[4] = 0;
                sprite->data[5] = 1;
            }
        }
        else if (sprite->data[5] == 1)
        {
            sprite->data[7] = Sin(sprite->data[4], 32);
            sprite->y2 = -(Sin(sprite->data[4], 8));
            sprite->data[6] = Sin(sprite->data[4], 128);
            HandleSetAffineData(sprite, 256 + sprite->data[6], 256 - sprite->data[7], 0);
            if (sprite->data[4] == 128)
            {
                if (sAnims[sprite->data[0]].runs > 1)
                {
                    sAnims[sprite->data[0]].runs--;
                    sAnims[sprite->data[0]].delay = 10;
                    sprite->data[4] = 0;
                    sprite->data[5] = 0;
                }
                else
                {
                    HandleSetAffineData(sprite, 256, 256, 0);
                    ResetSpriteAfterAnim(sprite);
                    sprite->callback = WaitAnimEnd;
                }
            }
        }

        sprite->data[4] += sAnims[sprite->data[0]].rotation;
    }
}

static void Anim_DeepVerticalSquishBounce(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();
    sAnims[id].rotation = 4;
    DeepVerticalSquishBounce(sprite);
    sprite->callback = DeepVerticalSquishBounce;
}

static void Anim_HorizontalJumps(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];
    TryFlipX(sprite);
    if (counter > 512)
    {
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        switch (sprite->data[2] / 128)
        {
        case 0:
            sprite->x2 = -(counter % 128 * 8) / 128;
            break;
        case 1:
            sprite->x2 = (counter % 128 / 16) - 8;
            break;
        case 2:
            sprite->x2 = (counter % 128 / 16);
            break;
        case 3:
            sprite->x2 = -(counter % 128 * 8) / 128 + 8;
            break;
        }

        sprite->y2 = -(Sin(counter % 128, 8));
    }

    sprite->data[2] += 12;
    TryFlipX(sprite);
}

static void HorizontalJumpsVerticalStretch_0(struct Sprite *sprite);
static void HorizontalJumpsVerticalStretch_1(struct Sprite *sprite);
static void HorizontalJumpsVerticalStretch_2(struct Sprite *sprite);

static void Anim_HorizontalJumpsVerticalStretch(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();
    sAnims[id].data = -1;
    HandleStartAffineAnim(sprite);
    sprite->data[3] = 0;
    HorizontalJumpsVerticalStretch_0(sprite);
    sprite->callback = HorizontalJumpsVerticalStretch_0;
}

static void HorizontalJumpsVerticalStretch_0(struct Sprite *sprite)
{
    if (sAnims[sprite->data[0]].delay != 0)
    {
        sAnims[sprite->data[0]].delay--;
    }
    else
    {
        s32 counter;

        TryFlipX(sprite);
        counter = sprite->data[2];
        if (sprite->data[2] > 128)
        {
            sprite->data[2] = 0;
            sprite->callback = HorizontalJumpsVerticalStretch_1;
        }
        else
        {
            s32 var = 8 * sAnims[sprite->data[0]].data;
            sprite->x2 = var * (counter % 128) / 128;
            sprite->y2 = -(Sin(counter % 128, 8));
            sprite->data[2] += 12;
        }

        TryFlipX(sprite);
    }
}

static void HorizontalJumpsVerticalStretch_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 48)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        sprite->data[2] = 0;
        sprite->callback = HorizontalJumpsVerticalStretch_2;
    }
    else
    {
        s16 yDelta;
        s16 yScale = Sin(sprite->data[4], 64) + 256;
        if (sprite->data[2] >= 16 && sprite->data[2] <= 31)
        {
            sprite->data[3] += 8;
            sprite->x2 -= sAnims[sprite->data[0]].data;
        }

        yDelta = 0;
        if (yScale > 256)
            yDelta = (256 - yScale) / 8;

        sprite->y2 = -(Sin(sprite->data[3], 20)) - yDelta;
        HandleSetAffineData(sprite, 256 - Sin(sprite->data[4], 32), yScale, 0);
        sprite->data[2]++;
        sprite->data[4] += 8;
        sprite->data[4] &= 0xFF;
    }

    TryFlipX(sprite);
}

static void HorizontalJumpsVerticalStretch_2(struct Sprite *sprite)
{
    s32 counter;

    TryFlipX(sprite);
    counter = sprite->data[2];
    if (counter > 128)
    {
        if (sAnims[sprite->data[0]].runs > 1)
        {
            sAnims[sprite->data[0]].runs--;
            sAnims[sprite->data[0]].delay = 10;
            sprite->data[3] = 0;
            sprite->data[2] = 0;
            sprite->data[4] = 0;
            sprite->callback = HorizontalJumpsVerticalStretch_0;
        }
        else
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
        }

        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        s32 var = sAnims[sprite->data[0]].data;

        sprite->x2 = var * ((counter % 128) * 8) / 128 + 8 * -var;
        sprite->y2 = -(Sin(counter % 128, 8));
    }

    sprite->data[2] += 12;
    TryFlipX(sprite);
}

static void RotateToSides(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
    }

    TryFlipX(sprite);
    if (sprite->data[7] > 254)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sAnims[sprite->data[0]].runs > 1)
        {
            sAnims[sprite->data[0]].runs--;
            sprite->data[2] = 0;
            sprite->data[7] = 0;
        }
        else
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
        }

        TryFlipX(sprite);
    }
    else
    {
        u16 rotation;

        sprite->x2 = -(Sin(sprite->data[7], 16));
        rotation = Sin(sprite->data[7], 32);
        HandleSetAffineData(sprite, 256, 256, rotation << 8);
        sprite->data[7] += sAnims[sprite->data[0]].rotation;
        TryFlipX(sprite);
    }
}

static void Anim_RotateToSides_Fast(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();
    sAnims[id].rotation = 4;
    RotateToSides(sprite);
    sprite->callback = RotateToSides;
}

static void Anim_RotateUpToSides(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
    }

    TryFlipX(sprite);
    if (sprite->data[7] > 254)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
        TryFlipX(sprite);
    }
    else
    {
        u16 rotation;

        sprite->x2 = -(Sin(sprite->data[7], 16));
        sprite->y2 = -(Sin(sprite->data[7] % 128, 16));
        rotation = Sin(sprite->data[7], 32);
        HandleSetAffineData(sprite, 256, 256, rotation << 8);
        sprite->data[7] += 8;
        TryFlipX(sprite);
    }
}

static void Anim_FlickerIncreasing(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = 0;

    if (sprite->data[2] == sprite->data[7])
    {
        sprite->data[7] = 0;
        sprite->data[2]++;
        sprite->invisible = FALSE;
    }
    else
    {
        sprite->data[7]++;
        sprite->invisible = TRUE;
    }

    if (sprite->data[2] > 10)
    {
        sprite->invisible = FALSE;
        sprite->callback = WaitAnimEnd;
    }
}

static void TipHopForward_0(struct Sprite *sprite);
static void TipHopForward_1(struct Sprite *sprite);
static void TipHopForward_2(struct Sprite *sprite);

static void Anim_TipHopForward(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 0;
    sprite->callback = TipHopForward_0;
}

static void TipHopForward_0(struct Sprite *sprite)
{
    if (sprite->data[7] > 31)
    {
        sprite->data[7] = 32;
        sprite->data[2] = 0;
        sprite->callback = TipHopForward_1;
    }
    else
    {
        sprite->data[7] += 4;
    }

    HandleSetAffineData(sprite, 256, 256, sprite->data[7] << 8);
}

static void TipHopForward_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 512)
    {
        sprite->callback = TipHopForward_2;
        sprite->data[6] = 0;
    }
    else
    {
        sprite->x2 = -(sprite->data[2] * 16) / 512;
        sprite->y2 = -(Sin(sprite->data[2] % 128, 4));
        sprite->data[2] += 12;
    }

    TryFlipX(sprite);
}

static void TipHopForward_2(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->data[7] -= 2;
    if (sprite->data[7] < 0)
    {
        sprite->data[7] = 0;
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        sprite->x2 = -(Sin(sprite->data[7] * 2, 16));
    }

    HandleSetAffineData(sprite, 256, 256, sprite->data[7] << 8);
    TryFlipX(sprite);
}

static void Anim_PivotShake(struct Sprite *sprite)
{
    u16 rotation;

    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    TryFlipX(sprite);
    if (sprite->data[7] > 255)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[7] = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        sprite->data[7] += 16;
        sprite->x2 = -(Sin(sprite->data[7] % 128, 8));
        sprite->y2 = -(Sin(sprite->data[7] % 128, 8));
    }

    rotation = Sin(sprite->data[7] % 128, 16);
    HandleSetAffineData(sprite, 256, 256, rotation << 8);
    TryFlipX(sprite);
}

static void TipAndShake_0(struct Sprite *sprite);
static void TipAndShake_1(struct Sprite *sprite);
static void TipAndShake_2(struct Sprite *sprite);
static void TipAndShake_3(struct Sprite *sprite);

static void Anim_TipAndShake(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 0;
    sprite->data[4] = 0;
    sprite->callback = TipAndShake_0;
}

static void TipAndShake_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[7] > 24)
    {
        if (++sprite->data[4] > 4)
        {
            sprite->data[4] = 0;
            sprite->callback = TipAndShake_1;
        }
    }
    else
    {
        sprite->data[7] += 2;
        sprite->x2 = Sin(sprite->data[7], 8);
        sprite->y2 = -(Sin(sprite->data[7], 8));
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    TryFlipX(sprite);
}

static void TipAndShake_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[7] > 32)
    {
        sprite->data[6] = 1;
        sprite->callback = TipAndShake_2;
    }
    else
    {
        sprite->data[7] += 2;
        sprite->x2 = Sin(sprite->data[7], 8);
        sprite->y2 = -(Sin(sprite->data[7], 8));
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    TryFlipX(sprite);
}

static void TipAndShake_2(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->data[7] += (sprite->data[6] * 4);
    if (sprite->data[5] > 9)
    {
        sprite->data[7] = 32;
        sprite->callback = TipAndShake_3;
    }

    sprite->x2 = Sin(sprite->data[7], 8);
    sprite->y2 = -(Sin(sprite->data[7], 8));
    if (sprite->data[7] <= 28 || sprite->data[7] >= 36)
    {
        sprite->data[6] *= -1;
        sprite->data[5]++;
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    TryFlipX(sprite);
}

static void TipAndShake_3(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[7] <= 0)
    {
        sprite->data[7] = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        sprite->data[7] -= 2;
        sprite->x2 = Sin(sprite->data[7], 8);
        sprite->y2 = -(Sin(sprite->data[7], 8));
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    TryFlipX(sprite);
}

static void Anim_VibrateToCorners(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 40)
    {
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
    }
    else
    {
        s8 sign;
        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        if ((sprite->data[2] % 4) / 2 == 0)
        {
            sprite->x2 = Sin((sprite->data[2] * 128 / 40) % 256, 16) * sign;
            sprite->y2 = -(sprite->x2);
        }
        else
        {
            sprite->x2 = -(Sin((sprite->data[2] * 128 / 40) % 256, 16)) * sign;
            sprite->y2 = sprite->x2;
        }
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

static void Anim_GrowInStages(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[5] = 0;
        sprite->data[6] = 0;
        sprite->data[7] = 0;
        sprite->data[2]++;
    }

    if (sprite->data[6] > 0)
    {
        sprite->data[6]--;
        if (sprite->data[5] != 3)
        {
            s16 scale = (8 * sprite->data[6]) / 20;
            scale = Sin(sprite->data[7] - scale, 64);
            HandleSetAffineData(sprite, 256 - scale, 256 - scale, 0);
        }
    }
    else
    {
        s16 var;

        if (sprite->data[5] == 3)
        {
            if (sprite->data[7] > 63)
            {
                sprite->data[7] = 64;
                HandleSetAffineData(sprite, 256, 256, 0);
                ResetSpriteAfterAnim(sprite);
                sprite->callback = WaitAnimEnd;
            }
            var = Cos(sprite->data[7], 64);
        }
        else
        {
            var = Sin(sprite->data[7], 64);
            if (sprite->data[7] > 63)
            {
                sprite->data[5] = 3;
                sprite->data[6] = 10;
                sprite->data[7] = 0;
            }
            else
            {
                if (var > 48 && sprite->data[5] == 1)
                {
                    sprite->data[5] = 2;
                    sprite->data[6] = 20;
                }
                else if (var > 16 && sprite->data[5] == 0)
                {
                    sprite->data[5] = 1;
                    sprite->data[6] = 20;
                }
            }
        }

        sprite->data[7] += 2;
        HandleSetAffineData(sprite, 256 - var, 256 - var, 0);
    }

    TryFlipX(sprite);
}

static void Anim_VerticalSpring(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 yScale;

        sprite->y2 = Sin(sprite->data[7] % 256, 8);
        sprite->data[7] += 8;
        yScale = Sin(sprite->data[7] % 128, 96);
        HandleSetAffineData(sprite, 256, yScale + 256, 0);
    }
}

static void Anim_VerticalRepeatedSpring(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 256)
    {
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 yScale;

        sprite->y2 = Sin(sprite->data[7], 16);
        sprite->data[7] += 4;
        yScale = Sin((sprite->data[7] % 64) * 2, 128);
        HandleSetAffineData(sprite, 256, yScale + 256, 0);
    }
}

static void SpringRising_0(struct Sprite *sprite);
static void SpringRising_1(struct Sprite *sprite);
static void SpringRising_2(struct Sprite *sprite);

static void Anim_SpringRising(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = SpringRising_0;
    sprite->data[7] = 0;
}

static void SpringRising_0(struct Sprite *sprite)
{
    s16 yScale;

    sprite->data[7] += 8;
    if (sprite->data[7] > 63)
    {
        sprite->data[7] = 0;
        sprite->data[6] = 0;
        sprite->callback = SpringRising_1;
        yScale = Sin(64, 128); // 128 * 1 = 128
    }
    else
    {
        yScale = Sin(sprite->data[7], 128);
    }

    HandleSetAffineData(sprite, 256, 256 + yScale, 0);
}

static void SpringRising_1(struct Sprite *sprite)
{
    s16 yScale;

    sprite->data[7] += 4;
    if (sprite->data[7] > 95)
    {
        yScale = Cos(0, 128); // 128 * (-1) = -128
        sprite->data[7] = 0;
        sprite->data[6]++;
    }
    else
    {
        s16 sign, index;

        sprite->y2 = -(sprite->data[6] * 4) - Sin(sprite->data[7], 8);
        if (sprite->data[7] > 63)
        {
            sign = -1;
            index = sprite->data[7] - 64;
        }
        else
        {
            sign = 1;
            index = 0;
        }

        yScale = Cos((index * 2) + sprite->data[7], 128) * sign;
    }

    HandleSetAffineData(sprite, 256, 256 + yScale, 0);
    if (sprite->data[6] == 3)
    {
        sprite->data[7] = 0;
        sprite->callback = SpringRising_2;
    }
}

static void SpringRising_2(struct Sprite *sprite)
{
    s16 yScale;

    sprite->data[7] += 8;
    yScale = Cos(sprite->data[7], 128);
    sprite->y2 = -(Cos(sprite->data[7], 12));
    if (sprite->data[7] > 63)
    {
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
    }

    HandleSetAffineData(sprite, 256, 256 + yScale, 0);
}

static void HorizontalSpring(struct Sprite *sprite)
{
    if (sprite->data[7] > sprite->data[5])
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
        HandleSetAffineData(sprite, 256, 256, 0);
    }
    else
    {
        s16 xScale;

        sprite->x2 = Sin(sprite->data[7] % 256, sprite->data[4]);
        sprite->data[7] += sprite->data[6];
        xScale = Sin(sprite->data[7] % 128, 96);
        HandleSetAffineData(sprite, 256 + xScale, 256, 0);
    }
}

static void Anim_HorizontalSpring(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 8;
    }

    HorizontalSpring(sprite);
}

static void HorizontalRepeatedSpring(struct Sprite *sprite)
{
    if (sprite->data[7] > sprite->data[5])
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
        HandleSetAffineData(sprite, 256, 256, 0);
    }
    else
    {
        s16 xScale;

        sprite->x2 = Sin(sprite->data[7] % 256, sprite->data[4]);
        sprite->data[7] += sprite->data[6];
        xScale = Sin((sprite->data[7] % 64) * 2, 128);
        HandleSetAffineData(sprite, 256 + xScale, 256, 0);
    }
}

static void Anim_HorizontalRepeatedSpring_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 4;
        sprite->data[5] = 256;
        sprite->data[4] = 16;
    }

    HorizontalRepeatedSpring(sprite);
}

static void Anim_HorizontalSlideShrink(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 scale;

        sprite->x2 = Sin(sprite->data[7] % 256, 8);
        sprite->data[7] += 8;
        scale = Sin(sprite->data[7] % 128, 96);
        HandleSetAffineData(sprite, 256 + scale, 256 + scale, 0);
    }

    TryFlipX(sprite);
}

static void Anim_LungeGrow(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 scale;

        sprite->x2 = -(Sin((sprite->data[7] % 256) / 2, 16));
        sprite->data[7] += 8;
        scale = -(Sin((sprite->data[7] % 256) / 2, 64));
        HandleSetAffineData(sprite, 256 + scale, 256 + scale, 0);
    }

    TryFlipX(sprite);
}

static void Anim_CircleIntoBackground(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s16 scale;

        sprite->x2 = -(Sin(sprite->data[7] % 256 , 8));
        sprite->data[7] += 8;
        scale = Sin((sprite->data[7] % 256) / 2, 96);
        HandleSetAffineData(sprite, 256 + scale, 256 + scale, 0);
    }

    TryFlipX(sprite);
}

static void Anim_RapidHorizontalHops(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = WaitAnimEnd;
        sprite->data[6] = 0;
    }
    else
    {
        s16 caseVar = (sprite->data[2] / 512) % 4;
        switch (caseVar)
        {
        case 0:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->x2 = (sprite->data[2] % 512 / 32) - 16;
            break;
        case 2:
            sprite->x2 = (sprite->data[2] % 512) / 32;
            break;
        case 3:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        }

        sprite->y2 = -(Sin(sprite->data[2] % 128, 4));
        sprite->data[2] += 24;
    }

    TryFlipX(sprite);
}

static void Anim_FourPetal(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        sprite->data[6] = 0;
        sprite->data[7] = 64;
        sprite->data[2]++;
    }

    sprite->data[7] += 8;
    if (sprite->data[6] == 4)
    {
        if (sprite->data[7] > 63)
        {
            sprite->data[7] = 0;
            sprite->data[6]++;
        }
    }
    else
    {
        if (sprite->data[7] > 127)
        {
            sprite->data[7] = 0;
            sprite->data[6]++;
        }
    }

    switch (sprite->data[6])
    {
    case 1:
        sprite->x2 = -(Cos(sprite->data[7], 8));
        sprite->y2 = Sin(sprite->data[7], 8) - 8;
        break;
    case 2:
        sprite->x2 = Sin(sprite->data[7] + 128, 8) + 8;
        sprite->y2 = -(Cos(sprite->data[7], 8));
        break;
    case 3:
        sprite->x2 = Cos(sprite->data[7], 8);
        sprite->y2 = Sin(sprite->data[7] + 128, 8) + 8;
        break;
    case 0:
    case 4:
        sprite->x2 = Sin(sprite->data[7], 8) - 8;
        sprite->y2 = Cos(sprite->data[7], 8);
        break;
    default:
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->callback = WaitAnimEnd;
        break;
    }

    TryFlipX(sprite);
}

static void Anim_VerticalSquishBounce_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 32;
    VerticalSquishBounce(sprite);
    sprite->callback = VerticalSquishBounce;
}

static void Anim_HorizontalSlide_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 80;
    HorizontalSlide(sprite);
    sprite->callback = HorizontalSlide;
}

static void Anim_VerticalSlide_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 80;
    VerticalSlide(sprite);
    sprite->callback = VerticalSlide;
}

static void Anim_BounceRotateToSides_Small(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].rotation = 2048;
    sAnims[id].data = sprite->data[6];
    BounceRotateToSides(sprite);
    sprite->callback = BounceRotateToSides;
}

static void Anim_BounceRotateToSides_Slow(struct Sprite *sprite)
{
    sprite->data[6] = 1;
    Anim_BounceRotateToSides(sprite);
}

static void Anim_BounceRotateToSides_SmallSlow(struct Sprite *sprite)
{
    sprite->data[6] = 1;
    Anim_BounceRotateToSides_Small(sprite);
}

static void Anim_ZigzagSlow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[0] = 0;

    if (sprite->data[0] <= 0)
    {
        Zigzag(sprite);
        sprite->data[0] = 1;
    }
    else
    {
        sprite->data[0]--;
    }
}

static void Anim_HorizontalShake_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 30;
    sprite->data[7] = 3;
    HorizontalShake(sprite);
    sprite->callback = HorizontalShake;
}

static void Anim_VertialShake_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 30;
    VerticalShake(sprite);
    sprite->callback = VerticalShake;
}

static void Anim_Twist_Twice(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].rotation = 1024;
    sAnims[id].delay = 0;
    sAnims[id].runs = 2;
    Twist(sprite);
    sprite->callback = Twist;
}

static void Anim_CircleCounterclockwise_Slow(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].rotation = 512;
    sAnims[id].data = 3;
    sAnims[id].speed = 12;
    CircleCounterclockwise(sprite);
    sprite->callback = CircleCounterclockwise;
}

static void Anim_VerticalShakeTwice_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 24;
    VerticalShakeTwice(sprite);
    sprite->callback = VerticalShakeTwice;
}

static void Anim_VerticalSlideWobble_Small(struct Sprite *sprite)
{
    sprite->data[0] = 5;
    VerticalSlideWobble(sprite);
    sprite->callback = VerticalSlideWobble;
}

static void Anim_VerticalJumps_Small(struct Sprite *sprite)
{
    sprite->data[0] = 3;
    VerticalJumps(sprite);
    sprite->callback = VerticalJumps;
}

static void Anim_Spin(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].delay = 60;
    sAnims[id].data = 30;
    Spin(sprite);
    sprite->callback = Spin;
}

static void Anim_TumblingFrontFlip_Twice(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].speed = 1;
    sAnims[id].runs = 2;
    TumblingFrontFlip(sprite);
    sprite->callback = TumblingFrontFlip;
}

static void Anim_DeepVerticalSquishBounce_Twice(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].rotation = 4;
    sAnims[id].runs = 2;
    DeepVerticalSquishBounce(sprite);
    sprite->callback = DeepVerticalSquishBounce;
}

static void Anim_HorizontalJumpsVerticalStretch_Twice(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].data = 1;
    sAnims[id].runs = 2;
    HandleStartAffineAnim(sprite);
    sprite->data[3] = 0;
    HorizontalJumpsVerticalStretch_0(sprite);
    sprite->callback = HorizontalJumpsVerticalStretch_0;
}

static void Anim_RotateToSides(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].rotation = 2;
    RotateToSides(sprite);
    sprite->callback = RotateToSides;
}

static void Anim_RotateToSides_Twice(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].rotation = 4;
    sAnims[id].runs = 2;
    RotateToSides(sprite);
    sprite->callback = RotateToSides;
}

static void Anim_SwingConcave(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].data = 100;
    SwingConcave(sprite);
    sprite->callback = SwingConcave;
}

static void Anim_SwingConcave_Fast(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].data = 50;
    sAnims[id].runs = 2;
    SwingConcave(sprite);
    sprite->callback = SwingConcave;
}

static void Anim_SwingConvex(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].data = 100;
    SwingConvex(sprite);
    sprite->callback = SwingConvex;
}

static void Anim_SwingConvex_Fast(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].data = 50;
    sAnims[id].runs = 2;
    SwingConvex(sprite);
    sprite->callback = SwingConvex;
}

// Very similar to VerticalShake, used by back animations only
static void VerticalShakeBack(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];
    if (counter > 2304)
    {
        sprite->callback = WaitAnimEnd;
        sprite->y2 = 0;
    }
    else
    {
        sprite->y2 = Sin((counter + 192) % 256, sprite->data[7]) + sprite->data[7];
    }

    sprite->data[2] += sprite->data[0];
}

static void Anim_VerticalShakeBack(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    sprite->data[7] = 3;
    VerticalShakeBack(sprite);
    sprite->callback = VerticalShakeBack;
}

static void Anim_VerticalShakeBack_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 30;
    sprite->data[7] = 3;
    VerticalShakeBack(sprite);
    sprite->callback = VerticalShakeBack;
}

static void Anim_VerticalShakeHorizontalSlide_Slow(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = WaitAnimEnd;
        sprite->data[6] = 0;
    }
    else
    {
        s16 divCase = (sprite->data[2] / 512) % 4;
        switch (divCase)
        {
        case 0:
            sprite->x2 = (sprite->data[2] % 512) / 32;
            break;
        case 2:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        case 3:
            sprite->x2 = (sprite->data[2] % 512) / 32 - 16;
            break;
        }

        sprite->y2 = Sin(sprite->data[2] % 128, 4);
        sprite->data[2] += 24;
    }

    TryFlipX(sprite);
}

static void VerticalStretchBothEnds(struct Sprite *sprite)
{
    s16 index1 = 0, index2 = 0;

    if (sprite->data[5] > sprite->data[6])
    {
        sprite->y2 = 0;
        sprite->data[5] = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sprite->data[4] <= 1)
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
        }
        else
        {
            sprite->data[4]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        u8 amplitude, cmpVal1, cmpVal2;
        s16 xScale, yScale;

        index2 = (sprite->data[5] * 128) / sprite->data[6];
        cmpVal1 = sprite->data[6] / 4;
        cmpVal2 = cmpVal1 * 3;
        if (sprite->data[5] >= cmpVal1 && sprite->data[5] < cmpVal2)
        {
            sprite->data[7] += 51;
            index1 = sprite->data[7] & 0xFF;
        }

        if (!sprite->sDontFlip)
            xScale = -256 - Sin(index2, 16);
        else
            xScale = 256 + Sin(index2, 16);

        amplitude = sprite->data[3];
        yScale = 256 - Sin(index2, amplitude) - Sin(index1, amplitude / 5);
        SetAffineData(sprite, xScale, yScale, 0);
        sprite->data[5]++;
    }
}

static void Anim_VerticalStretchBothEnds_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 40;
        sprite->data[3] = 40;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    VerticalStretchBothEnds(sprite);
}

static void HorizontalStretchFar(struct Sprite *sprite)
{
    s16 index1 = 0, index2;

    if (sprite->data[5] > sprite->data[6])
    {
        sprite->data[5] = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sprite->data[4] <= 1)
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
        }
        else
        {
            sprite->data[4]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        u8 amplitude, cmpVal1, cmpVal2;
        s16 xScale;

        index2 = (sprite->data[5] * 128) / sprite->data[6];
        cmpVal1 = sprite->data[6] / 4;
        cmpVal2 = cmpVal1 * 3;
        if (sprite->data[5] >= cmpVal1 && sprite->data[5] < cmpVal2)
        {
            sprite->data[7] += 51;
            index1 = sprite->data[7] & 0xFF;
        }

        amplitude = sprite->data[3];

        if (!sprite->sDontFlip)
            xScale = -256 + Sin(index2, amplitude) + Sin(index1, amplitude / 5 * 2);
        else
            xScale = 256 - Sin(index2, amplitude) - Sin(index1, amplitude / 5 * 2);

        SetAffineData(sprite, xScale, 256, 0);
        sprite->data[5]++;
    }
}

static void Anim_HorizontalStretchFar_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 40;
        sprite->data[3] = 40;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    HorizontalStretchFar(sprite);
}

static void VerticalShakeLowTwice(struct Sprite *sprite)
{
    u8 var6, var7;
    u8 var8 = sprite->data[2];
    u8 var9 = sprite->data[6];
    u8 var5 = sVerticalShakeData[sprite->data[5]][0];
    if (var5 != (u8)-1)
        var5 = sprite->data[7];

    var6 = sVerticalShakeData[sprite->data[5]][1];
    var7 = 0;
    if (sVerticalShakeData[sprite->data[5]][0] != (u8)-2)
        var7 = (var6 - var9) * var5 / var6;
    else
        var7 = 0;

    if (var5 == (u8)-1)
    {
        sprite->callback = WaitAnimEnd;
        sprite->y2 = 0;
    }
    else
    {
        sprite->y2 = Sin((var8 + 192) % 256, var7) + var7;
        if (var9 == var6)
        {
            sprite->data[5]++;
            sprite->data[6] = 0;
        }
        else
        {
            sprite->data[2] += sprite->data[0];
            sprite->data[6]++;
        }
    }
}

// Very similar in appearance to Anim_VerticalShakeTwice (especially the fast variant), but deeper
static void Anim_VerticalShakeLowTwice(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    sprite->data[7] = 6;
    VerticalShakeLowTwice(sprite);
    sprite->callback = VerticalShakeLowTwice;
}

static void Anim_HorizontalShake_Fast(struct Sprite *sprite)
{
    sprite->data[0] = 70;
    sprite->data[7] = 6;
    HorizontalShake(sprite);
    sprite->callback = HorizontalShake;
}

static void Anim_HorizontalSlide_Fast(struct Sprite *sprite)
{
    sprite->data[0] = 20;
    HorizontalSlide(sprite);
    sprite->callback = HorizontalSlide;
}

static void Anim_HorizontalVibrate_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] > 40)
    {
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
    }
    else
    {
        s8 sign;
        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        sprite->x2 = Sin((sprite->data[2] * 128 / 40) % 256, 9) * sign;
    }

    sprite->data[2]++;
}

static void Anim_HorizontalVibrate_Fastest(struct Sprite *sprite)
{
    if (sprite->data[2] > 40)
    {
        sprite->callback = WaitAnimEnd;
        sprite->x2 = 0;
    }
    else
    {
        s8 sign;
        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        sprite->x2 = Sin((sprite->data[2] * 128 / 40) % 256, 12) * sign;
    }

    sprite->data[2]++;
}

static void Anim_VerticalShakeBack_Fast(struct Sprite *sprite)
{
    sprite->data[0] = 70;
    sprite->data[7] = 6;
    VerticalShakeBack(sprite);
    sprite->callback = VerticalShakeBack;
}

static void Anim_VerticalShakeLowTwice_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 24;
    sprite->data[7] = 6;
    VerticalShakeLowTwice(sprite);
    sprite->callback = VerticalShakeLowTwice;
}

static void Anim_VerticalShakeLowTwice_Fast(struct Sprite *sprite)
{
    sprite->data[0] = 56;
    sprite->data[7] = 9;
    VerticalShakeLowTwice(sprite);
    sprite->callback = VerticalShakeLowTwice;
}

static void Anim_CircleCounterclockwise_Long(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    sAnims[id].rotation = 1024;
    sAnims[id].data = 6;
    sAnims[id].speed = 24;
    CircleCounterclockwise(sprite);
    sprite->callback = CircleCounterclockwise;
}

static void GrowStutter(struct Sprite *sprite)
{
    s16 index1 = 0, index2 = 0;
    if (sprite->data[5] > sprite->data[6])
    {
        sprite->y2 = 0;
        sprite->data[5] = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sprite->data[4] <= 1)
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
        }
        else
        {
            sprite->data[4]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        u8 amplitude, cmpVal1, cmpVal2;
        s16 xScale, yScale;

        index2 = (sprite->data[5] * 128) / sprite->data[6];
        cmpVal1 = sprite->data[6] / 4;
        cmpVal2 = cmpVal1 * 3;
        if (sprite->data[5] >= cmpVal1 && sprite->data[5] < cmpVal2)
        {
            sprite->data[7] += 51;
            index1 = sprite->data[7] & 0xFF;
        }

        amplitude = sprite->data[3];

        if (!sprite->sDontFlip)
            xScale = Sin(index2, amplitude) + (Sin(index1, amplitude / 5 * 2) - 256);
        else
            xScale = 256 - Sin(index1, amplitude / 5 * 2) - Sin(index2, amplitude);

        yScale = 256 - Sin(index1, amplitude / 5) - Sin(index2, amplitude);
        SetAffineData(sprite, xScale, yScale, 0);
        sprite->data[5]++;
    }
}

static void Anim_GrowStutter_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 40;
        sprite->data[3] = 40;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    GrowStutter(sprite);
}

static void Anim_VerticalShakeHorizontalSlide(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = WaitAnimEnd;
        sprite->data[6] = 0;
    }
    else
    {
        s16 divCase = (sprite->data[2] / 512) % 4;
        switch (divCase)
        {
        case 0:
            sprite->x2 = (sprite->data[2] % 512) / 32;
            break;
        case 2:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        case 3:
            sprite->x2 = (sprite->data[2] % 512) / 32 - 16;
            break;
        }

        sprite->y2 = Sin(sprite->data[2] % 128, 4);
        sprite->data[2] += 48;
    }

    TryFlipX(sprite);
}

static void Anim_VerticalShakeHorizontalSlide_Fast(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = WaitAnimEnd;
        sprite->data[6] = 0;
    }
    else
    {
        s16 divCase = (sprite->data[2] / 512) % 4;
        switch (divCase)
        {
        case 0:
            sprite->x2 = (sprite->data[2] % 512) / 32;
            break;
        case 2:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        case 3:
            sprite->x2 = (sprite->data[2] % 512) / 32 - 16;
            break;
        }

        sprite->y2 = Sin(sprite->data[2] % 96, 4);
        sprite->data[2] += 64;
    }

    TryFlipX(sprite);
}

static const s8 sTriangleDownData[][3] =
{
//   x    y   timer
    {1,   1, 12},
    {-2,  0, 12},
    {1,  -1, 12},
    {0,  0,  0}
};

static void TriangleDown(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
        sprite->data[3] = 0;

    if (sTriangleDownData[sprite->data[3]][2] / sprite->data[5] == sprite->data[2])
    {
        sprite->data[3]++;
        sprite->data[2] = 0;
    }

    if (sTriangleDownData[sprite->data[3]][2] / sprite->data[5] == 0)
    {
        if (--sprite->data[6] == 0)
            sprite->callback = WaitAnimEnd;
        else
            sprite->data[2] = 0;
    }
    else
    {
        s32 amplitude = sprite->data[5];
        sprite->x2 += (sTriangleDownData[sprite->data[3]][0] * amplitude);
        sprite->y2 += (sTriangleDownData[sprite->data[3]][1] * sprite->data[5]); // Not using amplitude here. No reason for this.
        sprite->data[2]++;
        TryFlipX(sprite);
    }
}

static void Anim_TriangleDown_Slow(struct Sprite *sprite)
{
    sprite->data[5] = 1;
    sprite->data[6] = 1;
    TriangleDown(sprite);
    sprite->callback = TriangleDown;
}

static void Anim_TriangleDown(struct Sprite *sprite)
{
    sprite->data[5] = 2;
    sprite->data[6] = 1;
    TriangleDown(sprite);
    sprite->callback = TriangleDown;
}

static void Anim_TriangleDown_Fast(struct Sprite *sprite)
{
    sprite->data[5] = 2;
    sprite->data[6] = 2;
    TriangleDown(sprite);
    sprite->callback = TriangleDown;
}

static void Grow(struct Sprite *sprite)
{
    if (sprite->data[7] > 255)
    {
        if (sprite->data[5] <= 1)
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
            HandleSetAffineData(sprite, 256, 256, 0);
        }
        else
        {
            sprite->data[5]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        s16 scale;

        sprite->data[7] += sprite->data[6];
        if (sprite->data[7] > 256)
            sprite->data[7] = 256;

        scale = Sin(sprite->data[7] / 2, 64);
        HandleSetAffineData(sprite, 256 - scale, 256 - scale, 0);
    }
}

static void Anim_Grow(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 4;
        sprite->data[5] = 1;
    }

    Grow(sprite);
    TryFlipX(sprite);
}

static void Anim_Grow_Twice(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 2;
    }

    Grow(sprite);
    TryFlipX(sprite);
}

static void Anim_HorizontalSpring_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 16;
    }

    HorizontalSpring(sprite);
}

static void Anim_HorizontalSpring_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 4;
        sprite->data[5] = 256;
        sprite->data[4] = 16;
    }

    HorizontalSpring(sprite);
}

static void Anim_HorizontalRepeatedSpring_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 16;
    }

    HorizontalRepeatedSpring(sprite);
}

static void Anim_HorizontalRepeatedSpring(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 8;
    }

    HorizontalRepeatedSpring(sprite);
}

static void Anim_ShrinkGrow_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 5;
        sprite->data[6] = 8;
    }

    ShrinkGrow(sprite);
}

static void Anim_ShrinkGrow_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 3;
        sprite->data[6] = 4;
    }

    ShrinkGrow(sprite);
}

static void Anim_VerticalStretchBothEnds(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 30;
        sprite->data[3] = 60;
        sprite->data[7] = 0;
    }

    VerticalStretchBothEnds(sprite);
}

static void Anim_VerticalStretchBothEnds_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 2;
        sprite->data[6] = 20;
        sprite->data[3] = 70;
        sprite->data[7] = 0;
    }

    VerticalStretchBothEnds(sprite);
}

static void Anim_HorizontalStretchFar_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 2;
        sprite->data[6] = 20;
        sprite->data[3] = 70;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    HorizontalStretchFar(sprite);
}

static void Anim_HorizontalStretchFar(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 30;
        sprite->data[3] = 60;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    HorizontalStretchFar(sprite);
}

static void Anim_GrowStutter_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 2;
        sprite->data[6] = 20;
        sprite->data[3] = 70;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    GrowStutter(sprite);
}

static void Anim_GrowStutter(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 30;
        sprite->data[3] = 60;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    GrowStutter(sprite);
}

static void ConcaveArc(struct Sprite *sprite)
{
    if (sprite->data[7] > 255)
    {
        if (sprite->data[6] <= 1)
        {
            sprite->callback = WaitAnimEnd;
            sprite->x2 = 0;
            sprite->y2 = 0;
        }
        else
        {
            sprite->data[7] %= 256;
            sprite->data[6]--;
        }
    }
    else
    {
        sprite->x2 = -(Sin(sprite->data[7], sprite->data[5]));
        sprite->y2 = Sin((sprite->data[7] + 192) % 256, sprite->data[4]);
        if (sprite->y2 > 0)
            sprite->y2 *= -1;

        sprite->y2 += sprite->data[4];
        sprite->data[7] += sprite->data[3];
    }
}

static void Anim_ConcaveArcLarge_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 12;
        sprite->data[4] = 12;
        sprite->data[3] = 4;
    }

    ConcaveArc(sprite);
}

static void Anim_ConcaveArcLarge(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 12;
        sprite->data[4] = 12;
        sprite->data[3] = 6;
    }

    ConcaveArc(sprite);
}

static void Anim_ConcaveArcLarge_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 12;
        sprite->data[4] = 12;
        sprite->data[3] = 8;
    }

    ConcaveArc(sprite);
}

static void ConvexDoubleArc(struct Sprite *sprite)
{
    if (sprite->data[7] > 256)
    {
        if (sprite->data[6] <= sprite->data[4])
        {
            sprite->callback = WaitAnimEnd;
        }
        else
        {
            sprite->data[4]++;
            sprite->data[7] = 0;
        }

        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        s16 posX;

        if (sprite->data[7] > 159)
        {
            if (sprite->data[7] > 256)
                sprite->data[7] = 256;

            sprite->y2 = -(Sin(sprite->data[7] % 256, 8));
        }
        else if (sprite->data[7] > 95)
        {
            sprite->y2 = Sin(96, 6) - Sin((sprite->data[7] - 96) * 2, 4);
        }
        else
        {
            sprite->y2 = Sin(sprite->data[7], 6);
        }

        posX = -(Sin(sprite->data[7] / 2, sprite->data[5]));
        if (sprite->data[4] % 2 == 0)
            posX *= -1;

        sprite->x2 = posX;
        sprite->data[7] += sprite->data[3];
    }
}

static void Anim_ConvexDoubleArc_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 16;
        sprite->data[4] = 1;
        sprite->data[3] = 4;
    }

    ConvexDoubleArc(sprite);
}

static void Anim_ConvexDoubleArc(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 16;
        sprite->data[4] = 1;
        sprite->data[3] = 6;
    }

    ConvexDoubleArc(sprite);
}

static void Anim_ConvexDoubleArc_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 3;
        sprite->data[7] = 0;
        sprite->data[5] = 16;
        sprite->data[4] = 1;
        sprite->data[3] = 8;
    }

    ConvexDoubleArc(sprite);
}

static void Anim_ConcaveArcSmall_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 4;
        sprite->data[4] = 6;
        sprite->data[3] = 4;
    }

    ConcaveArc(sprite);
}

static void Anim_ConcaveArcSmall(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 4;
        sprite->data[4] = 6;
        sprite->data[3] = 6;
    }

    ConcaveArc(sprite);
}

static void Anim_ConcaveArcSmall_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 4;
        sprite->data[4] = 6;
        sprite->data[3] = 8;
    }

    ConcaveArc(sprite);
}

static void SetHorizontalDip(struct Sprite *sprite)
{
    u16 index = Sin((sprite->data[2] * 128) / sprite->data[7], sprite->data[5]);
    sprite->data[6] = -(index << 8);
    SetPosForRotation(sprite, index, sprite->data[4], 0);
    HandleSetAffineData(sprite, 256, 256, sprite->data[6]);
}

static void Anim_HorizontalDip(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 60;
        sprite->data[5] = 8;
        sprite->data[4] = -32;
        sprite->data[3] = 1;
        sprite->data[0] = 0;
    }

    if (sprite->data[2] > sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0]++;
        if (sprite->data[3] <= sprite->data[0])
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
            return;
        }
        else
        {
            sprite->data[2] = 0;
        }
    }
    else
    {
        SetHorizontalDip(sprite);
    }

    sprite->data[2]++;
}

static void Anim_HorizontalDip_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 90;
        sprite->data[5] = 8;
        sprite->data[4] = -32;
        sprite->data[3] = 1;
        sprite->data[0] = 0;
    }

    if (sprite->data[2] > sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0]++;
        if (sprite->data[3] <= sprite->data[0])
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
            return;
        }
        else
        {
            sprite->data[2] = 0;
        }
    }
    else
    {
        SetHorizontalDip(sprite);
    }

    sprite->data[2]++;
}

static void Anim_HorizontalDip_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 30;
        sprite->data[5] = 8;
        sprite->data[4] = -32;
        sprite->data[3] = 2;
        sprite->data[0] = 0;
    }

    if (sprite->data[2] > sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0]++;
        if (sprite->data[3] <= sprite->data[0])
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = WaitAnimEnd;
            return;
        }
        else
        {
            sprite->data[2] = 0;
        }
    }
    else
    {
        SetHorizontalDip(sprite);
    }

    sprite->data[2]++;
}

static void ShrinkGrowVibrate(struct Sprite *sprite)
{
    if (sprite->data[2] > sprite->data[7])
    {
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        s8 sinY;
        u16 y;
        s16 index = ((u16)(sprite->data[2] % sprite->data[6] * 256) / sprite->data[6]) % 256;
        if (sprite->data[2] % 2 == 0)
        {
            sprite->data[4] = Sin(index, 32) + 256;
            sprite->data[5] = Sin(index, 32) + 256;
            sinY = Sin(index, 32);
        }
        else
        {
            sprite->data[4] = Sin(index, 8) + 256;
            sprite->data[5] = Sin(index, 8) + 256;
            sinY = Sin(index, 8);
        }

        y = sinY / 8;
        sprite->y2 = y;
        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

static void Anim_ShrinkGrowVibrate_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->y2 += 2;
        sprite->data[6] = 40;
        sprite->data[7] = 80;
    }

    ShrinkGrowVibrate(sprite);
}

static void Anim_ShrinkGrowVibrate(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->y2 += 2;
        sprite->data[6] = 40;
        sprite->data[7] = 40;
    }

    ShrinkGrowVibrate(sprite);
}

static void Anim_ShrinkGrowVibrate_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->y2 += 2;
        sprite->data[6] = 80;
        sprite->data[7] = 80;
    }

    ShrinkGrowVibrate(sprite);
}

static void JoltRight_0(struct Sprite *sprite);
static void JoltRight_1(struct Sprite *sprite);
static void JoltRight_2(struct Sprite *sprite);
static void JoltRight_3(struct Sprite *sprite);

static void JoltRight(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 -= sprite->data[2];
    if (sprite->x2 <= -sprite->data[6])
    {
        sprite->x2 = -sprite->data[6];
        sprite->data[7] = 2;
        sprite->callback = JoltRight_0;
    }

    TryFlipX(sprite);
}

static void JoltRight_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 += sprite->data[7];
    sprite->data[7]++;
    if (sprite->x2 >= 0)
        sprite->callback = JoltRight_1;

    TryFlipX(sprite);
}

static void JoltRight_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 += sprite->data[7];
    sprite->data[7]++;
    if (sprite->x2 > sprite->data[6])
    {
        sprite->x2 = sprite->data[6];
        sprite->callback = JoltRight_2;
    }

    TryFlipX(sprite);
}

static void JoltRight_2(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[3] >= sprite->data[5])
    {
        sprite->callback = JoltRight_3;
    }
    else
    {
        sprite->x2 += sprite->data[4];
        sprite->data[4] *= -1;
        sprite->data[3]++;
    }

    TryFlipX(sprite);
}

static void JoltRight_3(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 -= 2;
    if (sprite->x2 <= 0)
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = WaitAnimEnd;
    }

    TryFlipX(sprite);
}

static void Anim_JoltRight_Fast(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 4;
    sprite->data[6] = 12;
    sprite->data[5] = 16;
    sprite->data[4] = 4;
    sprite->data[3] = 0;
    sprite->data[2] = 2;
    sprite->callback = JoltRight;
}

static void Anim_JoltRight(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 2;
    sprite->data[6] = 8;
    sprite->data[5] = 12;
    sprite->data[4] = 2;
    sprite->data[3] = 0;
    sprite->data[2] = 1;
    sprite->callback = JoltRight;
}

static void Anim_JoltRight_Slow(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 0;
    sprite->data[6] = 6;
    sprite->data[5] = 6;
    sprite->data[4] = 2;
    sprite->data[3] = 0;
    sprite->data[2] = 1;
    sprite->callback = JoltRight;
}

static void SetShakeFlashYellowPos(struct Sprite *sprite)
{
    sprite->x2 = sprite->data[1];
    if (sprite->data[0] > 1)
    {
        sprite->data[1] *= -1;
        sprite->data[0] = 0;
    }
    else
    {
        sprite->data[0]++;
    }
}

static const struct YellowFlashData sShakeYellowFlashData_Fast[] =
{
    {FALSE,  1},
    { TRUE,  2},
    {FALSE, 15},
    { TRUE,  1},
    {FALSE, 15},
    { TRUE,  1},
    {FALSE, 15},
    { TRUE,  1},
    {FALSE,  1},
    { TRUE,  1},
    {FALSE,  1},
    { TRUE,  1},
    {FALSE,  1},
    { TRUE,  1},
    {FALSE,  1},
    { TRUE,  1},
    {FALSE,  1},
    { TRUE,  1},
    {FALSE,  1},
    {FALSE, -1}
};

static const struct YellowFlashData sShakeYellowFlashData_Normal[] =
{
    {FALSE,  5},
    { TRUE,  1},
    {FALSE, 15},
    { TRUE,  4},
    {FALSE,  2},
    { TRUE,  2},
    {FALSE,  2},
    { TRUE,  2},
    {FALSE,  2},
    { TRUE,  2},
    {FALSE,  2},
    { TRUE,  2},
    {FALSE,  2},
    {FALSE, -1}
};

static const struct YellowFlashData sShakeYellowFlashData_Slow[] =
{
    {FALSE,  1},
    { TRUE,  1},
    {FALSE, 20},
    { TRUE,  1},
    {FALSE, 20},
    { TRUE,  1},
    {FALSE, 20},
    { TRUE,  1},
    {FALSE,  1},
    {FALSE, -1}
};

static const struct YellowFlashData *const sShakeYellowFlashData[] =
{
    sShakeYellowFlashData_Fast,
    sShakeYellowFlashData_Normal,
    sShakeYellowFlashData_Slow
};

static void ShakeFlashYellow(struct Sprite *sprite)
{
    const struct YellowFlashData *array = sShakeYellowFlashData[sprite->data[3]];
    SetShakeFlashYellowPos(sprite);
    if (array[sprite->data[6]].time == (u8)-1)
    {
        sprite->x2 = 0;
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        if (sprite->data[4] == 1)
        {
            if (array[sprite->data[6]].isYellow)
                BlendPalette(sprite->data[7], 16, 16, RGB_YELLOW);
            else
                BlendPalette(sprite->data[7], 16, 0, RGB_YELLOW);

            sprite->data[4] = 0;
        }

        if (array[sprite->data[6]].time == sprite->data[5])
        {
            sprite->data[4] = 1;
            sprite->data[5] = 0;
            sprite->data[6]++;
        }
        else
        {
            sprite->data[5]++;
        }
    }
}

static void Anim_ShakeFlashYellow_Fast(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 0;
    }

    ShakeFlashYellow(sprite);
}

static void Anim_ShakeFlashYellow(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 1;
    }

    ShakeFlashYellow(sprite);
}

static void Anim_ShakeFlashYellow_Slow(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 2;
    }

    ShakeFlashYellow(sprite);
}

enum {
    SHAKEGLOW_RED,
    SHAKEGLOW_GREEN,
    SHAKEGLOW_BLUE,
    SHAKEGLOW_BLACK,
    SHAKEGLOW_WHITE,
    SHAKEGLOW_PURPLE
};

static void ShakeGlow_Blend(struct Sprite *sprite)
{
    static const u16 sColors[] =
    {
        [SHAKEGLOW_RED]   = RGB_RED,
        [SHAKEGLOW_GREEN] = RGB_GREEN,
        [SHAKEGLOW_BLUE]  = RGB_BLUE,
        [SHAKEGLOW_BLACK] = RGB_BLACK,
        [SHAKEGLOW_WHITE] = RGB_WHITE,
        [SHAKEGLOW_PURPLE] = RGB_PURPLE
    };

    if (sprite->data[2] > 127)
    {
        BlendPalette(sprite->data[7], 16, 0, RGB_RED);
        sprite->callback = WaitAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette(sprite->data[7], 16, sprite->data[6], sColors[sprite->data[1]]);
    }
}

static void ShakeGlow_Move(struct Sprite *sprite)
{
    if (sprite->data[3] < sprite->data[4])
    {
        TryFlipX(sprite);
        if (sprite->data[5] > sprite->data[0])
        {
            if (++sprite->data[3] < sprite->data[4])
                sprite->data[5] = 0;

            sprite->x2 = 0;
        }
        else
        {
            s8 sign = 1 - (sprite->data[3] % 2 * 2);
            sprite->x2 = sign * Sin((sprite->data[5] * 384 / sprite->data[0]) % 256, 6);
            sprite->data[5]++;
        }

        TryFlipX(sprite);
    }
}

static void Anim_ShakeGlowRed_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[0] = 10;
        sprite->data[5] = 0;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_RED;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowRed(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[0] = 20;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_RED;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowRed_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_RED;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowGreen_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[0] = 10;
        sprite->data[5] = 0;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_GREEN;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowGreen(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[0] = 20;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_GREEN;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowGreen_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_GREEN;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowBlue_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[0] = 10;
        sprite->data[5] = 0;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_BLUE;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowBlue(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[0] = 20;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_BLUE;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowBlue_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = OBJ_PLTT_ID(sprite->oam.paletteNum);
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_BLUE;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowBlack_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_BLACK;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowWhite_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_WHITE;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void Anim_ShakeGlowPurple_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = SHAKEGLOW_PURPLE;
    }

    if (sprite->data[2] % 2 == 0)
        ShakeGlow_Blend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        ShakeGlow_Move(sprite);

    sprite->data[2]++;
}

static void WaitAnimEnd(struct Sprite *sprite)
{
    if (sprite->animEnded)
        sprite->callback = SpriteCallbackDummy;
}
