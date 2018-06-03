#ifndef GUARD_FIELDCONTROLAVATAR_H
#define GUARD_FIELDCONTROLAVATAR_H

struct FieldInput
{
    u8 pressedAButton:1;
    u8 input_field_0_1:1;
    u8 pressedStartButton:1;
    u8 pressedSelectButton:1;
    u8 input_field_0_4:1;
    u8 input_field_0_5:1;
    u8 input_field_0_6:1;
    u8 pressedBButton:1;
    u8 input_field_1_0:1;
    u8 input_field_1_1:1;
    u8 input_field_1_2:1;
    u8 input_field_1_3:1;
    u8 input_field_1_4:1;
    u8 input_field_1_5:1;
    u8 input_field_1_6:1;
    u8 input_field_1_7:1;
    u8 dpadDirection;
    u8 input_field_3;
};

void FieldClearPlayerInput(struct FieldInput *pStruct);
void FieldGetPlayerInput(struct FieldInput *pStruct, u16 keys, u16 heldKeys);
int sub_809C014(struct FieldInput *pStruct);
u8 *sub_80682A8(struct MapPosition *, u8, u8);
void overworld_poison_timer_set(void);
void prev_quest_postbuffer_cursor_backup_reset(void);
u8 *sub_8068E24(struct MapPosition *);
u8 *GetFieldObjectScriptPointerPlayerFacing(void);
bool8 mapheader_trigger_activate_at__run_now(struct MapPosition *);
bool8 sub_8068870(u16 a);
bool8 sub_8068894(void);
bool8 sub_8068A64(struct MapPosition *, u16);
u8 sub_8068F18(void);
bool8 dive_warp(struct MapPosition *position, u16 b);
void sub_809D2BC(void);

#endif // GUARD_FIELDCONTROLAVATAR_H
