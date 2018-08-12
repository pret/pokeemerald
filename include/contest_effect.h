#ifndef GUARD_CONTEST_EFFECT_H
#define GUARD_CONTEST_EFFECT_H

struct ContestMove
{
    u8 effect;
    u8 contestCategory:3;
    u8 comboStarterId;
    u8 comboMoves[4];
};

struct ContestEffect
{
    u8 effectType;
    u8 appeal;
    u8 jam;
};

extern const struct ContestMove gContestMoves[];
extern const struct ContestEffect gContestEffects[];

#endif //GUARD_CONTEST_EFFECT_H
