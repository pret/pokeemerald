#ifndef GUARD_BATTLE_ENVIRONMENT_H
#define GUARD_BATTLE_ENVIRONMENT_H

#include "constants/battle.h"
#include "battle_bg.h"
#include "task.h"

struct BattleEnvironment
{
    u8 name[26];
    u16 naturePower;
    const void *secretPowerAnimation;
    u16 secretPowerEffect;
    enum Type camouflageType;
    u16 camouflageBlend;
    struct BattleBackgroundEntry entry;
    struct BattleBackground background;
    const void *palette;
    TaskFunc battleIntroSlide;
};

extern const struct BattleEnvironment gBattleEnvironmentInfo[BATTLE_ENVIRONMENT_COUNT];

#endif // GUARD_BATTLE_ENVIRONMENT_H
