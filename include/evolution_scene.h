#ifndef GUARD_EVOLUTION_SCENE_H
#define GUARD_EVOLUTION_SCENE_H

#include "constants/species.h"

void BeginEvolutionScene(struct Pokemon *mon, enum Species postEvoSpecies, bool32 canStopEvo, u8 partyId);
void EvolutionScene(struct Pokemon *mon, enum Species postEvoSpecies, bool32 canStopEvo, u8 partyId);
void TradeEvolutionScene(struct Pokemon *mon, enum Species postEvoSpecies, u8 preEvoSpriteId, u8 partyId);

extern void (*gCB2_AfterEvolution)(void);

#endif // GUARD_EVOLUTION_SCENE_H
