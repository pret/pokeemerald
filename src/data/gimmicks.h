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
        .indicatorSheet = &sSpriteSheet_MegaIndicator,
        .indicatorPal = &sSpritePalette_MegaIndicator,
        .CanActivate = CanMegaEvolve,
        .ActivateGimmick = ActivateMegaEvolution,
    },
    [GIMMICK_Z_MOVE] = 
    {
        .triggerSheet = &sSpriteSheet_ZMoveTrigger,
        .triggerPal = &sSpritePalette_ZMoveTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .CanActivate = CanUseZMove,
        .ActivateGimmick = ActivateZMove,
    },
    [GIMMICK_ULTRA_BURST] = 
    {
        .triggerSheet = &sSpriteSheet_BurstTrigger,
        .triggerPal = &sSpritePalette_BurstTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .CanActivate = CanUltraBurst,
        .ActivateGimmick = ActivateUltraBurst,
    },
    [GIMMICK_DYNAMAX] = 
    {
        .triggerSheet = &sSpriteSheet_DynamaxTrigger,
        .triggerPal = &sSpritePalette_DynamaxTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .indicatorSheet = &sSpriteSheet_DynamaxIndicator,
        .indicatorPal = &sSpritePalette_MiscIndicator,
        .CanActivate = CanDynamax,
        .ActivateGimmick = ActivateDynamax,
    },
    [GIMMICK_TERA] =
    {
        .triggerSheet = &sSpriteSheet_TeraTrigger,
        .triggerPal = &sSpritePalette_TeraTrigger,
        .triggerTemplate = &sSpriteTemplate_GimmickTrigger,
        .indicatorSheet = NULL, // handled separately
        .indicatorPal = &sSpritePalette_TeraIndicator,
        .CanActivate = CanTerastallize,
        .ActivateGimmick = ActivateTera,
    }
};
