#ifndef GUARD_BATTLE_RECORDS_H
#define GUARD_BATTLE_RECORDS_H

extern u8 gRecordsWindowId;

void ClearPlayerLinkBattleRecords(void);
void UpdatePlayerLinkBattleRecords(s32 battler);
void ShowLinkBattleRecords(void);
void RemoveRecordsWindow(void);
void ShowTrainerHillRecords(void);

#endif // GUARD_BATTLE_RECORDS_H
