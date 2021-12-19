#ifndef GUARD_MYSTERY_EVENT_SCRIPT_H
#define GUARD_MYSTERY_EVENT_SCRIPT_H

enum {
    MEVENT_STATUS_LOAD_OK,
    MEVENT_STATUS_LOAD_ERROR,
    MEVENT_STATUS_SUCCESS,
    MEVENT_STATUS_FAILURE,
    MEVENT_STATUS_FF = 0xFF
};

void InitMysteryEventScriptContext(u8 *script);
bool32 RunMysteryEventScriptContextCommand(u32 *status);
u32 RunMysteryEventScript(u8 *script);
void SetMysteryEventScriptStatus(u32 val);
u16 GetRecordMixingGift(void);

#endif // GUARD_MYSTERY_EVENT_SCRIPT_H
