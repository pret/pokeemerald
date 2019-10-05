#ifndef GUARD_TRADE_H
#define GUARD_TRADE_H

#include "link_rfu.h"
#include "constants/trade.h"

// Exported type declarations

// Exported RAM declarations
extern struct MailStruct gTradeMail[PARTY_SIZE];
extern u8 gSelectedTradeMonPositions[2];

// Exported ROM declarations
extern const struct WindowTemplate gUnknown_0833900C;

s32 sub_807A728(void);
void sub_80773AC(void);
void CB2_LinkTrade(void);
int CanRegisterMonForTradingBoard(struct UnkLinkRfuStruct_02022B14Substruct a0, u16, u16, u8);
int GetUnionRoomTradeMessageId(struct UnkLinkRfuStruct_02022B14Substruct a0, struct UnkLinkRfuStruct_02022B14Substruct a1, u16 a2, u16 a3, u8 a4, u16 a5, u8 a6);
int sub_807A918(struct Pokemon*, u16);
void sub_807B140(void);
void sub_807B154(void);
void InitTradeBg(void);
void DrawTextOnTradeWindow(u8, const u8 *, u8);

#endif //GUARD_TRADE_H
