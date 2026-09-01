#include "graphics/gimmicks.h"

// Gimmick data

const struct GimmickInfo gGimmicksInfo[GIMMICKS_COUNT] =
{
    [GIMMICK_NONE] = {0},
    [GIMMICK_MEGA] =
    {
        .triggerSheet = &sSpriteSheet_MegaTrigger,
        .triggerPal = &sSpritePalette_MegaTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .indicatorData = sMegaIndicatorGfx,
        .indicatorPalTag = TAG_MEGA_INDICATOR_PAL,
        .CanActivate = CanMegaEvolve,
        .ActivateGimmick = ActivateMegaEvolution,
        .attackerSlideType = TRAINER_SLIDE_ATTACKER_MEGA_EVOLUTION,
        .opponentSlideType = TRAINER_SLIDE_OPPONENT_MEGA_EVOLUTION,
    },
    [GIMMICK_Z_MOVE] =
    {
        .triggerSheet = &sSpriteSheet_ZMoveTrigger,
        .triggerPal = &sSpritePalette_ZMoveTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .CanActivate = CanUseZMove,
        .ActivateGimmick = ActivateZMove,
        .attackerSlideType = TRAINER_SLIDE_ATTACKER_Z_MOVE,
        .opponentSlideType = TRAINER_SLIDE_OPPONENT_Z_MOVE,
    },
    [GIMMICK_ULTRA_BURST] =
    {
        .triggerSheet = &sSpriteSheet_BurstTrigger,
        .triggerPal = &sSpritePalette_BurstTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .CanActivate = CanUltraBurst,
        .ActivateGimmick = ActivateUltraBurst,
        .attackerSlideType = TRAINER_SLIDE_ATTACKER_MEGA_EVOLUTION,
        .opponentSlideType = TRAINER_SLIDE_OPPONENT_MEGA_EVOLUTION,
    },
    [GIMMICK_DYNAMAX] =
    {
        .triggerSheet = &sSpriteSheet_DynamaxTrigger,
        .triggerPal = &sSpritePalette_DynamaxTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .indicatorData = sDynamaxIndicatorGfx,
        .indicatorPalTag = TAG_MISC_INDICATOR_PAL,
        .CanActivate = CanDynamax,
        .ActivateGimmick = ActivateDynamax,
        .attackerSlideType = TRAINER_SLIDE_ATTACKER_DYNAMAX,
        .opponentSlideType = TRAINER_SLIDE_OPPONENT_DYNAMAX,
    },
    [GIMMICK_TERA] =
    {
        .triggerSheet = &sSpriteSheet_TeraTrigger,
        .triggerPal = &sSpritePalette_TeraTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .indicatorData = NULL, // handled separately
        .indicatorPalTag = TAG_TERA_INDICATOR_PAL,
        .CanActivate = CanTerastallize,
        .ActivateGimmick = ActivateTera,
        .attackerSlideType = TRAINER_SLIDE_ATTACKER_TERA,
        .opponentSlideType = TRAINER_SLIDE_OPPONENT_TERA,
    }
};
