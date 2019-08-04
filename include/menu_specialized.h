#ifndef GUARD_MENU_SPECIALIZED_H
#define GUARD_MENU_SPECIALIZED_H

#include "sprite.h"
#include "player_pc.h"
#include "list_menu.h"
#include "pokemon.h"

struct UnknownSubStruct_81D1ED4
{
    u16 unk0;
    u16 unk2;
};

struct UnknownStruct_81D1ED4
{
    /*0x000*/ u8 unk0[4][5];
    /*0x014*/ struct UnknownSubStruct_81D1ED4 unk14[4][5];
    /*0x064*/ struct UnknownSubStruct_81D1ED4 unk64[10][5];
    /*0x12C*/ struct UnknownSubStruct_81D1ED4 unk12C[5];
    /*0x140*/ u16 unk140[66][2];
    /*0x248*/ u16 unk248[66][2];
    /*0x350*/ u16 unk350;
    /*0x352*/ u16 unk352;
    /*0x354*/ u8 unk354;
    /*0x355*/ u8 unk355;
};

bool8 sub_81D1C44(u8 count);
u8 sub_81D1C84(u8 a0);
u8 sub_81D1DC0(struct PlayerPCItemPageStruct *page);
void sub_81D1E90(struct PlayerPCItemPageStruct *page);
void sub_81D1EC0(void);
void sub_81D1D04(u8 a0);
void sub_81D1ED4(struct UnknownStruct_81D1ED4 *a0);
void sub_81D2108(struct UnknownStruct_81D1ED4 *arg0);
void sub_81D21DC(u8 bg);
void sub_81D20AC(struct UnknownStruct_81D1ED4 *arg0);
void sub_81D2230(struct UnknownStruct_81D1ED4 *arg0);
bool8 sub_81D20BC(struct UnknownStruct_81D1ED4 *arg0);
bool32 sub_81D2074(struct UnknownStruct_81D1ED4 *a0);
void sub_81D2754(u8 *arg0, struct UnknownSubStruct_81D1ED4 *arg1);
void sub_81D1F84(struct UnknownStruct_81D1ED4 *arg0, struct UnknownSubStruct_81D1ED4 *arg1, struct UnknownSubStruct_81D1ED4 *arg2);
void MoveRelearnerPrintText(u8 *str);
bool16 MoveRelearnerRunTextPrinters(void);
void MoveRelearnerCreateYesNoMenu(void);
u8 LoadMoveRelearnerMovesList(const struct ListMenuItem *items, u16 numChoices);
void InitMoveRelearnerWindows(bool8 useContextWindow);
s32 GetBoxOrPartyMonData(u16 boxId, u16 monId, s32 request, u8 *dst);
void sub_81D2ED4(u8 *dst, u8 *nameDst, u16 boxId, u16 monId, u16 arg5, u16 arg6, bool8 arg7);
void sub_81D2F78(struct UnknownStruct_81D1ED4 *arg0, u8 *sheen, u16 boxId, u16 monId, u16 arg5, u16 id, u16 arg7, bool8 arg8);
void sub_81D3094(void *tilesDst, void *palDst, u16 boxId, u16 monId, u16 arg5, u16 arg6, bool8 arg7);
bool8 sub_81D312C(s16 *var);
bool8 sub_81D3150(s16 *var);
bool8 sub_81D3178(struct UnknownStruct_81D1ED4 *arg0, s16 *arg1);
bool8 sub_81D31A4(struct UnknownStruct_81D1ED4 *arg0, s16 *arg1);
void sub_81D31D0(struct SpriteSheet *sheet, struct SpriteTemplate *template, struct SpritePalette *pal);
void sub_81D321C(struct SpriteSheet *sheets, struct SpriteTemplate * template, struct SpritePalette *pals);
void sub_81D32B0(struct SpriteSheet *sheet, struct SpritePalette *pal);
void sub_81D3464(struct Sprite **sprites);
void sub_81D3480(struct Sprite **sprites, u8 arg1, u8 arg2);
void sub_81D3520(struct Sprite **sprites);
void sub_81D354C(struct Sprite **sprites);
void DrawLevelUpWindowPg1(u16 windowId, u16 *statsBefore, u16 *statsAfter, u8 bgClr, u8 fgClr, u8 shadowClr);
void DrawLevelUpWindowPg2(u16 windowId, u16 *currStats, u8 bgClr, u8 fgClr, u8 shadowClr);
void GetMonLevelUpWindowStats(struct Pokemon *mon, u16 *currStats);

#endif // GUARD_MENU_SPECIALIZED_H
