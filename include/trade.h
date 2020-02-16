#ifndef GUARD_TRADE_H
#define GUARD_TRADE_H

#include "link_rfu.h"
#include "constants/trade.h"

// Exported type declarations

// Exported RAM declarations
extern struct MailStruct gTradeMail[PARTY_SIZE];
extern u8 gSelectedTradeMonPositions[2];

// Exported ROM declarations
extern const struct WindowTemplate gTradeEvolutionSceneYesNoWindowTemplate;

s32 GetGameProgressForLinkTrade(void);
void CB2_StartCreateTradeMenu(void);
void CB2_LinkTrade(void);
int CanRegisterMonForTradingBoard(struct GFtgtGnameSub a0, u16, u16, u8);
int GetUnionRoomTradeMessageId(struct GFtgtGnameSub a0, struct GFtgtGnameSub a1, u16 a2, u16 a3, u8 a4, u16 a5, u8 a6);
int CanSpinTradeMon(struct Pokemon*, u16);
void InitTradeSequenceBgGpuRegs(void);
void LinkTradeDrawWindow(void);
void InitTradeBg(void);
void DrawTextOnTradeWindow(u8, const u8 *, u8);

#endif //GUARD_TRADE_H
