#ifndef GUARD_PARTY_MENU_H
#define GUARD_PARTY_MENU_H

enum
{
    AILMENT_NONE,
    AILMENT_PSN,
    AILMENT_PRZ,
    AILMENT_SLP,
    AILMENT_FRZ,
    AILMENT_BRN
};

struct Struct203CEC8
{
    u8 filler[0x9];
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 filler2[0x2];
};

extern struct Struct203CEC8 gUnknown_0203CEC8;

bool8 pokemon_has_move(struct Pokemon *, u16);
void sub_81B58A8(void);
void DoWallyTutorialBagMenu(void);
u8 pokemon_ailments_get_primary(u32 status);
u8 *GetMonNickname(struct Pokemon *mon, u8 *dst);
u8 GetCursorSelectionMonId(void);
bool8 FieldCallback_Teleport(void);
void sub_81B7F60(void);

void sub_81B0FCC(u8 partyMonId, u8 a);
void sub_81B1370(u8 taskId);
void display_pokemon_menu_message(u8 windowBorderId);

#endif // GUARD_PARTY_MENU_H
