#ifndef GUARD_PARTY_MENU_H
#define GUARD_PARTY_MENU_H

#include "main.h"
#include "task.h"

enum PartyMenuLayout
{
    PARTY_LAYOUT_SINGLE,
    PARTY_LAYOUT_DOUBLE,
    PARTY_LAYOUT_MULTI,
    PARTY_LAYOUT_MULTI_SHOWCASE,                // The layout during the screen that appears just before a multi battle
    PARTY_LAYOUT_MULTI_FULL,
    PARTY_LAYOUT_MULTI_FULL_PARTNER,
    PARTY_LAYOUT_MULTI_FULL_SHOWCASE,           // The layout used to present player team in full-teams multi battle
    PARTY_LAYOUT_MULTI_FULL_SHOWCASE_PARTNER,   // The layout used to present partner team in full-teams multi battle
    PARTY_LAYOUT_COUNT,
    KEEP_PARTY_LAYOUT
};

enum PartyMenuType
{
    PARTY_MENU_TYPE_FIELD,
    PARTY_MENU_TYPE_IN_BATTLE,
    PARTY_MENU_TYPE_CONTEST,
    PARTY_MENU_TYPE_CHOOSE_MON,
    PARTY_MENU_TYPE_CHOOSE_HALF,                // multi battles, eReader battles, and some battle facilities
    PARTY_MENU_TYPE_MULTI_SHOWCASE,
    PARTY_MENU_TYPE_DAYCARE,
    PARTY_MENU_TYPE_MOVE_RELEARNER,
    PARTY_MENU_TYPE_UNION_ROOM_REGISTER,        // trading board
    PARTY_MENU_TYPE_UNION_ROOM_TRADE,           // trading board
    PARTY_MENU_TYPE_SPIN_TRADE,                 // Unused beta for Gen IV's Spin Trade
    PARTY_MENU_TYPE_MINIGAME,
    PARTY_MENU_TYPE_STORE_PYRAMID_HELD_ITEMS,
    PARTY_MENU_TYPE_MULTI_FULL_SHOWCASE
};

// seems like the last two fields may have been left as all-purpose vars
// and the second of the two just happens to only be used in one case
struct PartyMenu
{
    MainCallback exitCallback;
    TaskFunc task;
    enum PartyMenuType menuType:4;
    enum PartyMenuLayout layout:4;
    s8 slotId;
    s8 slotId2;
    u8 action;
    u16 bagItem;
    s16 data1;           // used variously as a move, counter, moveSlotId, cursorPos, or indicator that the menu is opened from the field
    s16 learnMoveState;  // data2, used only as a learn move state
};

#define DATA1_PARTY_MENU_FROM_FIELD -1

extern struct PartyMenu gPartyMenu;
extern bool8 gPartyMenuUseExitCallback;
extern u8 gSelectedMonPartyId;
extern MainCallback gPostMenuFieldCallback;
extern u8 gSelectedOrderFromParty[MAX_FRONTIER_PARTY_SIZE];
extern u8 gBattlePartyCurrentOrder[PARTY_SIZE / 2];

extern const struct SpriteSheet gSpriteSheet_HeldItem;
extern const u16 gHeldItemPalette[];

extern void (*gItemUseCB)(u8, TaskFunc);
extern const struct SpriteTemplate gSpriteTemplate_StatusIcons;

void AnimatePartySlot(u8 slot, u8 animNum);
bool8 IsMultiBattle(void);
u8 GetCursorSelectionMonId(void);
u8 GetPartyMenuType(void);
void Task_HandleChooseMonInput(u8 taskId);
u8 *GetMonNickname(struct Pokemon *mon, u8 *dest);
u8 DisplayPartyMenuMessage(const u8 *str, bool8 keepOpen);
bool8 IsPartyMenuTextPrinterActive(void);
void PartyMenuModifyHP(u8 taskId, u8 slot, s8 hpIncrement, s16 hpDifference, TaskFunc task);
u8 GetAilmentFromStatus(u32 status);
u8 GetMonAilment(struct Pokemon *mon);
void DisplayPartyMenuStdMessage(u32 stringId);
bool8 FieldCallback_PrepareFadeInFromMenu(void);
bool8 FieldCallback_PrepareFadeInForTeleport(void);
void CB2_ReturnToPartyMenuFromFlyMap(void);
void LoadHeldItemIcons(void);
void DrawHeldItemIconsForTrade(u8 *partyCounts, u8 *partySpriteIds, u8 whichParty);
void LoadPartyMenuAilmentGfx(void);
void CB2_ShowPartyMenuForItemUse(void);
void ItemUseCB_BattleScript(u8 taskId, TaskFunc task);
void ItemUseCB_BattleChooseMove(u8 taskId, TaskFunc task);
void ItemUseCB_Medicine(u8 taskId, TaskFunc task);
void ItemUseCB_AbilityCapsule(u8 taskId, TaskFunc task);
void ItemUseCB_AbilityPatch(u8 taskId, TaskFunc task);
void ItemUseCB_Mint(u8 taskId, TaskFunc task);
void ItemUseCB_ResetEVs(u8 taskId, TaskFunc task);
void ItemUseCB_ReduceEV(u8 taskId, TaskFunc task);
void ItemUseCB_PPRecovery(u8 taskId, TaskFunc task);
void ItemUseCB_PPUp(u8 taskId, TaskFunc task);
enum Move ItemIdToBattleMoveId(enum Item item);
bool8 MonKnowsMove(struct Pokemon *mon, enum Move move);
bool8 BoxMonKnowsMove(struct BoxPokemon *boxMon, enum Move move);
void ItemUseCB_TMHM(u8 taskId, TaskFunc task);
void ItemUseCB_RareCandy(u8 taskId, TaskFunc task);
void ItemUseCB_DynamaxCandy(u8 taskId, TaskFunc task);
void ItemUseCB_SacredAsh(u8 taskId, TaskFunc task);
void ItemUseCB_EvolutionStone(u8 taskId, TaskFunc task);
void ItemUseCB_FormChange(u8 taskId, TaskFunc task);
void ItemUseCB_FormChange_ConsumedOnUse(u8 taskId, TaskFunc task);
void ItemUseCB_RotomCatalog(u8 taskId, TaskFunc task);
void ItemUseCB_ZygardeCube(u8 taskId, TaskFunc task);
void ItemUseCB_Fusion(u8 taskId, TaskFunc task);
enum ItemEffectType GetItemEffectType(enum Item item);
void CB2_PartyMenuFromStartMenu(void);
void CB2_ChooseMonToGiveItem(void);
void ChooseMonToGiveMailFromMailbox(void);
void InitChooseHalfPartyForBattle(u8 unused);
void ClearSelectedPartyOrder(void);
void ChooseMonForTradingBoard(enum PartyMenuType menuType, MainCallback callback);
void ChooseMonForMoveTutor(void);
void ChooseMonForWirelessMinigame(void);
void OpenPartyMenuInBattle(u8 partyAction);
void ChooseMonForInBattleItem(void);
void BufferBattlePartyCurrentOrder(void);
void BufferBattlePartyCurrentOrderBySide(enum BattlerId battler, u8 flankId);
void SwitchPartyOrderLinkMulti(enum BattlerId battler, u8 slot, u8 slot2);
void SwitchPartyMonSlots(u8 slot, u8 slot2);
u8 GetPartyIdFromBattlePartyId(u8 battlePartyId);
void ShowPartyMenuToShowcaseMultiBattleParty(void);
void ChooseMonForDaycare(void);
bool8 CB2_FadeFromPartyMenu(void);
void CB2_ReturnToPartyMenuFromSummaryScreen(void);
void ChooseContestMon(void);
void ChoosePartyMon(void);
void ChooseMonForMoveRelearner(void);
void BattlePyramidChooseMonHeldItems(void);
void DoBattlePyramidMonsHaveHeldItem(void);
void IsSelectedMonEgg(void);
void IsLastMonThatKnowsSurf(void);
void MoveDeleterForgetMove(void);
void BufferMoveDeleterNicknameAndMove(void);
void GetNumMovesSelectedMonHas(void);
void MoveDeleterChooseMoveToForget(void);

bool32 SetUpFieldMove_Surf(void);
bool32 SetUpFieldMove_Fly(void);
bool32 SetUpFieldMove_Waterfall(void);
bool32 SetUpFieldMove_Dive(void);
bool32 SetUpFieldMove_RockClimb(void);

#if TESTING
s8 Test_UpdatePartySelectionSingleLayout(s8 slotId, s8 movementDir, bool8 chooseHalf, u8 lastSelectedSlot);
#endif

#endif // GUARD_PARTY_MENU_H
