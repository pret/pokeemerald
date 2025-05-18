#ifndef GUARD_TRADE_H
#define GUARD_TRADE_H

#include "link_rfu.h"
#include "constants/trade.h"

extern struct Mail gTradeMail[PARTY_SIZE];
extern u8 gSelectedTradeMonPositions[2];

extern const struct WindowTemplate gTradeEvolutionSceneYesNoWindowTemplate;

s32 GetGameProgressForLinkTrade(void);
void CB2_StartCreateTradeMenu(void);
void CB2_LinkTrade(void);
int CanRegisterMonForTradingBoard(struct RfuGameCompatibilityData player, u16 species2, u16 species, bool8 isModernFatefulEncounter);
int GetUnionRoomTradeMessageId(struct RfuGameCompatibilityData player, struct RfuGameCompatibilityData partner, u16 playerSpecies2, u16 partnerSpecies, u8 requestedType, u16 playerSpecies, bool8 isModernFatefulEncounter);
int CanSpinTradeMon(struct Pokemon *mon, u16 monIdx);
void InitTradeSequenceBgGpuRegs(void);
void LinkTradeDrawWindow(void);
void LoadTradeAnimGfx(void);
void DrawTextOnTradeWindow(u8 windowId, const u8 *str, u8 speed);

#endif //GUARD_TRADE_H
