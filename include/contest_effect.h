#ifndef GUARD_CONTEST_EFFECT_H
#define GUARD_CONTEST_EFFECT_H

struct ContestMove
{
    u8 effect;
    u8 contestCategory:3;
    u8 comboStarterId;
    u8 comboMoves[4];
};

extern const struct ContestMove gContestMoves[];

#endif //GUARD_CONTEST_EFFECT_H
