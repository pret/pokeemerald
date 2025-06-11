#ifndef GUARD_CONTEST_LINK_H
#define GUARD_CONTEST_LINK_H

void Task_LinkContest_CommunicateAppealsState(u8 taskId);
void Task_LinkContest_CommunicateFinalStandings(u8 taskId);
void Task_LinkContest_Init(u8 taskId);
void Task_LinkContest_CommunicateMonsRS(u8 taskId);
void Task_LinkContest_CommunicateRngRS(u8 taskId);
void Task_LinkContest_CommunicateLeaderIdsRS(u8 taskId);
void Task_LinkContest_CommunicateCategoryRS(u8 taskId);
void Task_LinkContest_CommunicateMonIdxs(u8 taskId);
void Task_LinkContest_StartCommunicationEm(u8 taskId);
void Task_LinkContest_CommunicateRound1Points(u8 taskId);
void Task_LinkContest_CommunicateTurnOrder(u8 taskId);
void Task_LinkContest_FinalizeConnection(u8 taskId);
void Task_LinkContest_CommunicateMoveSelections(u8 taskId);
bool32 LinkContest_TryLinkStandby(s16 *state);
bool32 LinkContest_SendBlock(void *src, u16 size);
bool8 LinkContest_GetBlockReceivedFromAllPlayers(void);
bool8 LinkContest_GetBlockReceived(u8 flag);
u8 LinkContest_GetLeaderIndex(u8 *ids);

#endif //GUARD_CONTEST_LINK_H
