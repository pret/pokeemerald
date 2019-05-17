#ifndef GUARD_PARTY_MENU_H
#define GUARD_PARTY_MENU_H

#include "main.h"
#include "task.h"

enum
{
    AILMENT_NONE,
    AILMENT_PSN,
    AILMENT_PRZ,
    AILMENT_SLP,
    AILMENT_FRZ,
    AILMENT_BRN,
    AILMENT_PKRS,
    AILMENT_FNT
};

enum
{
    PARTY_CHOOSE_MON,
    PARTY_MUST_CHOOSE_MON,
    PARTY_CANT_SWITCH,
    PARTY_USE_ITEM_ON,
    PARTY_ABILITY_PREVENTS,
    PARTY_GIVE_ITEM,
};

struct Struct203CEC8
{
    MainCallback exitCallback;
    TaskFunc unk4;
    u8 unk8_0:4;
    u8 mode:2;
    u8 unk8_2:2;
    s8 slotId;
    s8 unkA;
    u8 unkB;
    u16 unkC;
    s16 unkE;
    s16 unk10;
};

extern struct Struct203CEC8 gUnknown_0203CEC8;
extern u8 gUnknown_0203CEE8;
extern u8 gUnknown_0203CEE9;
extern MainCallback gPostMenuFieldCallback;
extern u8 gSelectedOrderFromParty[4];
extern u8 gUnknown_0203CF00[3];

extern void (*gUnknown_03006328)(u8, TaskFunc);

extern const u16 gTutorMoves[];

void sub_81B0FCC(u8 slot, u8 b);
bool8 IsMultiBattle(void);
u8 GetCursorSelectionMonId(void);
u8 sub_81B1360(void);
void sub_81B1370(u8 taskId);
u8* GetMonNickname(struct Pokemon *mon, u8 *dest);
u8 sub_81B1B5C(const u8* str, u8 b);
bool8 sub_81B1BD4(void);
void sub_81B1F18(u8 taskId, u8 slot, s8 c, s16 HPDifference, TaskFunc func);
u8 pokemon_ailments_get_primary(u32 status);
u8 GetMonAilment(struct Pokemon *mon);
void display_pokemon_menu_message(u32 stringID);
void sub_81B47E0(u8 taskId);
bool8 FieldCallback_PrepareFadeInFromMenu(void);
void sub_81B58A8(void);
void LoadHeldItemIcons(void);
void sub_81B5D4C(u8 *a, u8 *b, u8 c);
void sub_81B617C(void);
void ItemUseCB_Medicine(u8 taskId, TaskFunc task);
void sub_81B67C8(u8 taskId, TaskFunc task);
void dp05_ether(u8 taskId, TaskFunc task);
void dp05_pp_up(u8 taskId, TaskFunc task);
u16 ItemIdToBattleMoveId(u16 item);
bool8 IsMoveHm(u16 move);
bool8 MonKnowsMove(struct Pokemon *mon, u16 move);
void sub_81B6DC4(u8 taskId, TaskFunc task);
void dp05_rare_candy(u8 taskId, TaskFunc task);
void sub_81B79E8(u8 taskId, TaskFunc task);
void sub_81B7C74(u8 taskId, TaskFunc task);
u8 GetItemEffectType(u16 item);
void CB2_PartyMenuFromStartMenu(void);
void sub_81B7F60(void);
void sub_81B8448(void);
void InitChooseHalfPartyForBattle(u8 unused);
void sub_81B8558(void);
void sub_81B8904(u8 initArg, MainCallback callback);
void sub_81B892C(void);
void sub_81B8958(void);
void OpenPartyMenuInBattle(u8 arg);
void sub_81B89F0(void);
void sub_81B8C68(void);
void sub_81B8D64(u8 battlerId, u8 multiplayerFlag);
void sub_81B8E80(u8 battlerId, u8 unk, u8 arrayIndex);
void sub_81B8FB0(u8 slot, u8 slot2);
u8 pokemon_order_func(u8 slot);
void sub_81B9150(void);
void sub_81B9328(void);
bool8 hm_add_c3_without_phase_2(void);
void sub_81B9404(void);
void sub_81B94B0(void);
void sub_81B951C(void);
void sub_81B9620(void);
void sub_81B95E0(void);
void sub_81B98DC(void);
void sub_81B9918(void);
void sub_81B9770(void);
void sub_81B9718(void);
void sub_81B96D0(void);
void sub_81B968C(void);

#endif // GUARD_PARTY_MENU_H
