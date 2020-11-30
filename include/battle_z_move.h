#ifndef GUARD_BATTLE_Z_MOVE_H
#define GUARD_BATTLE_Z_MOVE_H

#include "constants/z_move_effects.h"

struct SignatureZMove
{
    u16 species;
    u16 item;
    u16 move;
    u16 zmove;
};

bool32 IsViableZMove(u8 battlerId, u16 move);
bool32 TryChangeZIndicator(u8 battlerId, u16 move);
void CreateZMoveTriggerSprite(u8, bool8);
void HideZMoveTriggerSprite(void);
bool32 IsZMoveTriggerSpriteActive(void);
void DestroyZMoveTriggerSprite(void);
bool32 MoveSelectionDisplayZMove(u16 zmove);
const u8* GetZMoveName(u16 move);
void SetZEffect(void);

#endif // GUARD_BATTLE_Z_MOVE_H