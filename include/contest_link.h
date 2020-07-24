#ifndef GUARD_CONTEST_LINK_H
#define GUARD_CONTEST_LINK_H

void sub_80FCC88(u8);
void sub_80FCC88(u8);
void Task_LinkContest_CommunicateFinalStandings(u8);
void sub_80FC580(u8);
void sub_80FC6BC(u8);
void sub_80FC804(u8);
void sub_80FCE48(u8);
void sub_80FC894(u8);
void Task_LinkContest_CommunicateMonIdxs(u8 taskId);
void sub_81D9DE4(u8 taskId);
void Task_LinkContest_CommunicateRound1Points(u8);
void Task_LinkContest_CommunicateTurnOrder(u8);
void sub_80F8714(u8);
bool32 sub_80FC670(s16 *);
bool32 LinkContest_SendBlock(void *, u16);
bool8 LinkContest_GetBlockReceivedFromAllPlayers(void);
bool8 LinkContest_GetBlockReceived(u8);
u8 sub_80F86E0(u8 *);
void Task_LinkContest_CommunicateMoveSelections(u8 taskId);

#endif //GUARD_CONTEST_LINK_H
