#ifndef GUARD_TRADE_H
#define GUARD_TRADE_H

#include "link_rfu.h"
#include "constants/trade.h"

// Indexes for sActionTexts
enum {
    TEXT_CANCEL,
    TEXT_CHOOSE_MON,
    TEXT_SUMMARY,
    TEXT_TRADE,
    TEXT_CANCEL_TRADE,
    TEXT_JP_QUIT,
};

// Indexes for sMessages
enum {
    MSG_STANDBY,
    MSG_CANCELED,
    MSG_ONLY_MON1,
    MSG_ONLY_MON2,
    MSG_WAITING_FOR_FRIEND,
    MSG_FRIEND_WANTS_TO_TRADE,
    MSG_MON_CANT_BE_TRADED,
    MSG_EGG_CANT_BE_TRADED,
    MSG_FRIENDS_MON_CANT_BE_TRADED,
};

struct InGameTrade {
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 species;
    u8 ivs[NUM_STATS];
    u8 abilityNum;
    u32 otId;
    u8 conditions[CONTEST_CATEGORIES_COUNT];
    u32 personality;
    u16 heldItem;
    u8 mailNum;
    u8 otName[TRAINER_NAME_LENGTH + 1];
    u8 otGender;
    u8 sheen;
    u16 requestedSpecies;
};

extern struct Mail gTradeMail[PARTY_SIZE];
extern u8 gSelectedTradeMonPositions[2];

extern const struct WindowTemplate gTradeEvolutionSceneYesNoWindowTemplate;

static void Task_DrawSelectionSummary(u8);
static void Task_DrawSelectionTrade(u8);
static void SpriteCB_LinkMonGlow(struct Sprite *);
static void SpriteCB_LinkMonShadow(struct Sprite *);
static void SpriteCB_CableEndSending(struct Sprite *);
static void SpriteCB_CableEndReceiving(struct Sprite *);
static void SpriteCB_GbaScreen(struct Sprite *);
static void SpriteCB_BouncingPokeball(struct Sprite *);
static void SpriteCB_BouncingPokeballDepart(struct Sprite *);
static void SpriteCB_BouncingPokeballDepartEnd(struct Sprite *);
static void SpriteCB_BouncingPokeballArrive(struct Sprite *);
s32 GetGameProgressForLinkTrade(void);
void CB2_StartCreateTradeMenu(void);
void CB2_LinkTrade(void);
int CanRegisterMonForTradingBoard(struct RfuGameCompatibilityData player, u16 species2, u16 species, bool8 isModernFatefulEncounter);
int GetUnionRoomTradeMessageId(struct RfuGameCompatibilityData player, struct RfuGameCompatibilityData partner, u16 playerSpecies2, u16 partnerSpecies, u8 requestedType, u16 playerSpecies, bool8 isModernFatefulEncounter);
int CanSpinTradeMon(struct Pokemon *, u16);
void InitTradeSequenceBgGpuRegs(void);
void LinkTradeDrawWindow(void);
void LoadTradeAnimGfx(void);
void DrawTextOnTradeWindow(u8, const u8 *, u8);

#endif //GUARD_TRADE_H
