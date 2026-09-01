#ifndef GUARD_BATTLE_HOLD_EFFECTS
#define GUARD_BATTLE_HOLD_EFFECTS

struct HoldEffectInfo
{
    u32 onSwitchIn:1;
    u32 mirrorHerb:1;
    u32 whiteHerb:1;
    u32 onStatusChange:1;
    u32 onHpThreshold:1;
    u32 keeMarangaBerry:1;
    u32 MentalHerb:1;
    u32 onTargetAfterHit:1;
    u32 onAttackerAfterHit:1;
    u32 sprayLeppaBlunder:1;
    u32 lifeOrbShellBell:1;
    u32 leftovers:1;
    u32 orbs:1;
    u32 onEffect:1;
    u32 onFling:1;
    u32 boosterEnergy:1;
    u32 orbsWhiteHerbActivation:1;
    u32 padding:15;
};

extern const struct HoldEffectInfo gHoldEffectsInfo[];

typedef bool32 (*ActivationTiming)(enum HoldEffect holdEffect);
enum ItemEffect ItemBattleEffects(enum BattlerId itemBattler, enum BattlerId battler, enum HoldEffect holdEffect, ActivationTiming timing);

bool32 IsOnSwitchInActivation(enum HoldEffect holdEffect);
bool32 IsMirrorHerbActivation(enum HoldEffect holdEffect);
bool32 IsWhiteHerbActivation(enum HoldEffect holdEffect);
bool32 IsOnStatusChangeActivation(enum HoldEffect holdEffect);
bool32 IsOnHpThresholdActivation(enum HoldEffect holdEffect);
bool32 IsKeeMarangaBerryActivation(enum HoldEffect holdEffect);
bool32 IsOnTargetHitActivation(enum HoldEffect holdEffect);
bool32 IsOnAttackerAfterHitActivation(enum HoldEffect holdEffect);
bool32 IsSprayLeppaBlunderActivation(enum HoldEffect holdEffect);
bool32 IsLifeOrbShellBellActivation(enum HoldEffect holdEffect);
bool32 IsLeftoversActivation(enum HoldEffect holdEffect);
bool32 IsOrbsActivation(enum HoldEffect holdEffect);
bool32 IsOnEffectActivation(enum HoldEffect holdEffect);
bool32 IsForceTriggerItemActivation(enum HoldEffect holdEffect);
bool32 IsOnBerryActivation(enum HoldEffect holdEffect);
bool32 IsOnFlingActivation(enum HoldEffect holdEffect);
bool32 IsBoosterEnergyActivation(enum HoldEffect holdEffect);
bool32 IsOrbsWhiteHerbActivation(enum HoldEffect holdEffect);

#endif // GUARD_BATTLE_HOLD_EFFECTS
