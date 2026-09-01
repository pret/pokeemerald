#ifndef GUARD_TRADE_H
#define GUARD_TRADE_H

#include "link_rfu.h"
#include "constants/trade.h"

#define TRADEMON_FROM_PC 1

extern struct Mail gTradeMail[PARTY_SIZE];
extern u8 gSelectedTradeMonPositions[2];

extern const u16 gTradePlatform_Tilemap[];
extern const struct WindowTemplate gTradeEvolutionSceneYesNoWindowTemplate;

s32 GetGameProgressForLinkTrade(void);
void CB2_StartCreateTradeMenu(void);
void CB2_LinkTrade(void);
int CanRegisterMonForTradingBoard(struct RfuGameCompatibilityData player, enum Species species2, enum Species species, bool8 isModernFatefulEncounter);
int GetUnionRoomTradeMessageId(struct RfuGameCompatibilityData player, struct RfuGameCompatibilityData partner, enum Species playerSpecies2, enum Species partnerSpecies, enum Type requestedType, enum Species playerSpecies, bool8 isModernFatefulEncounter);
enum CanTradeMon CanSpinTradeMon(struct Pokemon *mon, u16 monIdx);
void InitTradeSequenceBgGpuRegs(void);
void LinkTradeDrawWindow(void);
void LoadTradeAnimGfx(void);
void DrawTextOnTradeWindow(u8 windowId, const u8 *str, u8 speed);

#endif //GUARD_TRADE_H
