#ifndef GUARD_FIELDCONTROLAVATAR_H
#define GUARD_FIELDCONTROLAVATAR_H

struct FieldInput
{
    bool8 pressedAButton:1;
    bool8 checkStandardWildEncounter:1;
    bool8 pressedStartButton:1;
    bool8 pressedSelectButton:1;
    bool8 heldDirection:1;
    bool8 heldDirection2:1;
    bool8 tookStep:1;
    bool8 pressedBButton:1;
    bool8 pressedRButton:1;
    bool8 input_field_1_1:1;
    bool8 input_field_1_2:1;
    bool8 input_field_1_3:1;
    bool8 input_field_1_4:1;
    bool8 input_field_1_5:1;
    bool8 input_field_1_6:1;
    bool8 input_field_1_7:1;
    u8 dpadDirection;
};

void GetPlayerPosition(struct MapPosition *);
void FieldClearPlayerInput(struct FieldInput *pStruct);
void FieldGetPlayerInput(struct FieldInput *pStruct, u16 keys, u16 heldKeys);
int ProcessPlayerFieldInput(struct FieldInput *pStruct);
void RestartWildEncounterImmunitySteps(void);
const u8 *GetObjectEventScriptPointerPlayerFacing(void);
bool8 TryDoDiveWarp(struct MapPosition *position, u16 metatileBehavior);
int SetCableClubWarp(void);
u8 TrySetDiveWarp(void);
const u8 *GetInteractedLinkPlayerScript(struct MapPosition *position, u8 metatileBehavior, enum Direction direction);
const u8 *GetCoordEventScriptAtMapPosition(struct MapPosition *position);
void ClearPoisonStepCounter(void);
void CancelSignPostMessageBox(struct FieldInput *input);
void HandleBoulderFallThroughHole(struct ObjectEvent *object);
void HandleBoulderActivateVictoryRoadSwitch(u16 x, u16 y);
bool8 TryStartStepBasedScript(struct MapPosition *, u16, enum Direction);

#define NOT_SIGNPOST 0
#define WALK_AWAY_SIGNPOST_FRAMES 6

#endif // GUARD_FIELDCONTROLAVATAR_H
