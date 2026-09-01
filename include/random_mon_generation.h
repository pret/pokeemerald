#ifndef GUARD_RANDOM_MON_GENERATION_H
#define GUARD_RANDOM_MON_GENERATION_H

#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokeball.h"
#include "constants/species.h"

#define FILTER_FUNC_ARG_NONE 0xFFFF
#define RANDOM_MON_MAX_FORMS 70

struct FilterFuncArgs
{
    u16 arg1;
    u16 arg2;
};

enum Species GetRandomSpecies(u32 optionId, const struct FilterFuncArgs *filterFuncArgs);
enum Item GetRandomItem(u32 optionId, const struct FilterFuncArgs *filterFuncArgs);
enum PokeBall GetRandomBall(void);
void ResolveMoves(enum Species species, u32 level, const u16 *movesTemplate, enum Move *moves);

#endif // GUARD_RANDOM_MON_GENERATION_H
