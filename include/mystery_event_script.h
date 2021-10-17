#ifndef GUARD_MYSTERY_EVENT_SCRIPT_H
#define GUARD_MYSTERY_EVENT_SCRIPT_H

void InitMysteryEventScriptContext(u8 *script);
bool32 RunMysteryEventScriptContextCommand(u32 *script);
u32 RunMysteryEventScript(u8 *script);
void SetMysteryEventScriptStatus(u32 val);
u16 GetRecordMixingGift(void);

#endif // GUARD_MYSTERY_EVENT_SCRIPT_H
