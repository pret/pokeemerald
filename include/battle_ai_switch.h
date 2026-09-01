#ifndef GUARD_BATTLE_AI_SWITCH_H
#define GUARD_BATTLE_AI_SWITCH_H

enum ShouldSwitchScenario
{
    SHOULD_SWITCH_WONDER_GUARD,
    SHOULD_SWITCH_ABSORBS_MOVE,
    SHOULD_SWITCH_TRAPPER,
    SHOULD_SWITCH_FREE_TURN,
    SHOULD_SWITCH_TRUANT,
    SHOULD_SWITCH_ALL_MOVES_BAD,
    SHOULD_SWITCH_PERISH_SONG,
    SHOULD_SWITCH_YAWN,
    SHOULD_SWITCH_BADLY_POISONED,
    SHOULD_SWITCH_BADLY_POISONED_STATS_RAISED,
    SHOULD_SWITCH_CURSED,
    SHOULD_SWITCH_CURSED_STATS_RAISED,
    SHOULD_SWITCH_NIGHTMARE,
    SHOULD_SWITCH_NIGHTMARE_STATS_RAISED,
    SHOULD_SWITCH_SEEDED,
    SHOULD_SWITCH_SEEDED_STATS_RAISED,
    SHOULD_SWITCH_INFATUATION,
    SHOULD_SWITCH_HASBADODDS,
    SHOULD_SWITCH_NATURAL_CURE_STRONG,
    SHOULD_SWITCH_NATURAL_CURE_STRONG_STATS_RAISED,
    SHOULD_SWITCH_NATURAL_CURE_WEAK,
    SHOULD_SWITCH_NATURAL_CURE_WEAK_STATS_RAISED,
    SHOULD_SWITCH_REGENERATOR,
    SHOULD_SWITCH_REGENERATOR_STATS_RAISED,
    SHOULD_SWITCH_INTIMIDATE,
    SHOULD_SWITCH_INTIMIDATE_STATS_RAISED,
    SHOULD_SWITCH_ENCORE_STATUS,
    SHOULD_SWITCH_ENCORE_DAMAGE,
    SHOULD_SWITCH_CHOICE_LOCKED,
    SHOULD_SWITCH_ATTACKING_STAT_MINUS_TWO,
    SHOULD_SWITCH_ATTACKING_STAT_MINUS_THREE_PLUS,
    SHOULD_SWITCH_ALL_SCORES_BAD,
    SHOULD_SWITCH_DYN_FUNC,
    SHOULD_SWITCH_WISH_PASSING,
    SHOULD_SWITCH_LOSES_1V1,
};

enum SwitchType
{
    SWITCH_AFTER_KO,
    SWITCH_MID_BATTLE_FORCED,
    SWITCH_MID_BATTLE_OPTIONAL,
};

struct SwitchAiContext
{
    enum BattlerId battler:3;
    enum BattlerId opposingBattler:3;
    enum Move incomingMove:16;
    u32 lastId:6;
    u32 padding1:4;

    enum BattlerId battlerIn1;
    enum BattlerId battlerIn2;
    struct Pokemon *party;
    uq4_12_t typeMatchup;

    // Flags
    u32 canBattlerWin1v1:1;
    u32 hasEffectiveMove:1;
    u32 hasImportantStatusMove:1;
    u32 battlerGetsOHKOd:1;
    u32 hasStatRaised:1;

    // Party mon flags
    u32 eligiblePartyMons:6;

    u32 padding2:21;
};

// Dynamic switch function
typedef bool32 (*AiSwitchFunc)(struct SwitchAiContext*);
extern AiSwitchFunc gDynamicAiSwitchFunc;

u32 GetMostSuitableMonToSwitchInto(enum BattlerId battler, enum SwitchType switchType);
bool32 ShouldSwitch(enum BattlerId battler);
void ModifySwitchAfterMoveScoring(enum BattlerId battler);
u32 AI_SelectRevivalBlessingMon(enum BattlerId battler);
bool32 IsSwitchinValid(enum BattlerId battler);
bool32 IsAceMon(enum BattlerId battler, u32 monPartyId);

#endif // GUARD_BATTLE_AI_SWITCH_H
