#ifndef GUARD_CONTEST_LINK_H
#define GUARD_CONTEST_LINK_H

void Task_LinkContest_CommunicateAppealsState(u8);
void Task_LinkContest_CommunicateFinalStandings(u8);
void Task_LinkContest_Init(u8);
void Task_LinkContest_CommunicateMonsRS(u8);
void Task_LinkContest_CommunicateRngRS(u8);
void Task_LinkContest_CommunicateLeaderIdsRS(u8);
void Task_LinkContest_CommunicateCategoryRS(u8);
void Task_LinkContest_CommunicateMonIdxs(u8);
void Task_LinkContest_StartCommunicationEm(u8);
void Task_LinkContest_CommunicateRound1Points(u8);
void Task_LinkContest_CommunicateTurnOrder(u8);
void Task_LinkContest_FinalizeConnection(u8);
void Task_LinkContest_CommunicateMoveSelections(u8);
bool32 LinkContest_TryLinkStandby(s16 *);
bool32 LinkContest_SendBlock(void *, u16);
bool8 LinkContest_GetBlockReceivedFromAllPlayers(void);
bool8 LinkContest_GetBlockReceived(u8);
u8 LinkContest_GetLeaderIndex(u8 *);

#endif //GUARD_CONTEST_LINK_H
