#ifndef GUARD_MENU_INDICATORS_H
#define GUARD_MENU_INDICATORS_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations

struct ArrowStruct
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u16 unk6;
    u16 unk8;
    u16 tileTag;
    u16 palTag;
    u8 palNum;
};

struct CursorStruct
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u8 unkA;
};

void Task_ScrollIndicatorArrowPairOnMainMenu(u8);
void RemoveScrollIndicatorArrowPair(u8);
void sub_81AF15C(u8, u8, s32);
void ListMenuRemoveCursorObject(u8 taskId, u32 cursorKind);
void ListMenuUpdateCursorObject(u8 taskId, u16 x, u16 y, u32 cursorKind);
u8 ListMenuAddCursorObjectInternal(struct CursorStruct *cursor, u32 cursorKind);

#endif //GUARD_MENU_INDICATORS_H
