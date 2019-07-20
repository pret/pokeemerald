#ifndef GUARD_POKENAV_H
#define GUARD_POKENAV_H

#include "bg.h"
#include "main.h"

typedef u32 (*LoopedTask)(s32 state);

// Return values of LoopedTask functions.
#define LT_INC_AND_PAUSE 0
#define LT_INC_AND_CONTINUE 1
#define LT_PAUSE 2
#define LT_CONTINUE 3
#define LT_FINISH 4
#define LT_SET_STATE(newState) (newState + 5)

enum
{
    POKENAV_MODE_NORMAL, // Chosen from Start menu.
    POKENAV_MODE_FORCE_CALL_1, // Used for the script's special. Has to choose Match Call and make a call.
    POKENAV_MODE_FORCE_CALL_2, // Set after making a call, has to exit Pokenav.
};

#define POKENAV_MENU_IDS_START 100000
enum
{
	POKENAV_MENU_0 = POKENAV_MENU_IDS_START,
	POKENAV_MENU_1,
	POKENAV_MENU_2,
	POKENAV_MENU_3,
	POKENAV_MENU_4,
	POKENAV_MENU_5,
	POKENAV_MENU_6,
	POKENAV_MENU_7,
	POKENAV_MENU_8,
	POKENAV_MENU_9,
	POKENAV_MENU_A,
	POKENAV_MENU_B,
	POKENAV_MENU_C,
	POKENAV_MENU_D,
	POKENAV_MENU_E,
};

// pokenav.c
void sub_81C7694(u32);
u16 sub_81C76AC(void);

void CB2_InitPokeNav(void);
u32 CreateLoopedTask(LoopedTask loopedTask, u32 priority);
bool32 FuncIsActiveLoopedTask(LoopedTask func);
void *GetSubstructPtr(u32 index);
void FreePokenavSubstruct(u32 index);
void *AllocSubstruct(u32 index, u32 size);
void Pokenav_AllocAndLoadPalettes(const struct SpritePalette *palettes);
bool32 IsLoopedTaskActive(u32 taskId);
void SetPokenavMode(u16 mode);
u32 GetPokenavMode(void);
bool32 CanViewRibbonsMenu(void);
void SetPokenavVBlankCallback(void);
void SetVBlankCallback_(IntrCallback callback);

// pokenav_match_call_ui.c
struct MatchCallListTemplate
{
    u32 unk0;
    u16 unk4;
    u16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    void (*unk10)(u32, u8 *a1);
    void (*unk14)(u16 a0, u32 a1, u32 a2);
};
u32 GetSelectedMatchCall(void);
bool32 sub_81C8224(void);
int MatchCall_MoveCursorUp(void);
int MatchCall_MoveCursorDown(void);
int MatchCall_PageDown(void);
int MatchCall_PageUp(void);
bool32 sub_81C8630(void);
void ToggleMatchCallVerticalArrows(bool32 shouldHide);
void sub_81C8838(void);
void sub_81C877C(void);
bool32 sub_81C8820(void);
void sub_81C87AC(s16 a0);
u32 GetMatchCallListTopIndex(void);
void sub_81C87F0(void);
bool32 sub_81C81D4(const struct BgTemplate *arg0, struct MatchCallListTemplate *arg1, s32 arg2);
void sub_81C8234(void);

// pokenav_match_call_data.c
bool32 sub_81D17E8(u32 idx);
u8 sub_81D16DC(u32 idx);
bool32 sub_81D1BF8(u32 idx);
bool32 MatchCallFlagGetByIndex(u32 idx);
u32 MatchCall_GetRematchTableIdx(u32 idx);
u32 GetTrainerIdxByRematchIdx(u32 rematchIdx);
int sub_81D1BD0(u32 idx);
void MatchCall_GetMessage(u32 idx, u8 *dest);
const u8 *sub_81D1B40(u32 idx, u32 offset);
void sub_81D1A78(u32 idx, const u8 **desc, const u8 **name);

// pokenav_main_menu.c
bool32 InitPokenavMainMenu(void);
void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 bufferOffset, u32 size);
void sub_81C7850(u32 a0);
u32 sub_81C786C(void);
void LoadLeftHeaderGfxForIndex(u32 arg0);
void sub_81C7FA0(u32 arg0, bool32 arg1, bool32 arg2);
void sub_81C7AC0(s32 a0);
bool32 sub_81C8010(void);
void InitBgTemplates(const struct BgTemplate *templates, int count);
bool32 IsPaletteFadeActive(void);
void sub_81C7BA4(u32 helpBarIndex);
bool32 IsDma3ManagerBusyWithBgCopy_(void);
void sub_81C78A0(void);
bool32 MainMenuLoopedTaskIsBusy(void);
void sub_81C7FDC(void);
void sub_81C79BC(const u16 *a0, const u16 *a1, u32 a2, u32 a3, u32 a4, u16 *a5);
void sub_81C7B40(void);
struct Sprite *PauseSpinningPokenavSprite(void);
void ResumeSpinningPokenavSprite(void);
void sub_81C7E14(u32 arg0);
void sub_81C7990(u32 a0, u16 a1);

// pokenav_unk_1.c
bool32 sub_81C9298(void);
bool32 sub_81C92CC(void);
bool32 sub_81C9304(void);
bool32 sub_81C9338(void);
bool32 sub_81C9368(void);
u32 sub_81C941C(void);
void sub_81C9430(void);
int sub_81C9894(void);
const u8 *sub_81CAF78(int index, u8 *arg1);

// pokenav_unk_2.c
void sub_81C99D4(void);
void sub_81CAADC(void);

// pokenav_unk_3.c
struct Pokenav3Struct_Unk1C
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
};
bool32 sub_81CAAE8(void);
u32 sub_81CAB24(void);
void sub_81CAB38(void);
int sub_81CAE28(void);
int sub_81CAE38(void);
int sub_81CAE48(void);
struct Pokenav3Struct_Unk1C *sub_81CAE94(void);
u16 sub_81CAEA4(int);
bool32 sub_81CAEBC(int index);
int sub_81CAF04(int index);
const u8 *sub_81CAFD8(int index, int textType);
u16 sub_81CB01C(void);
u16 sub_81CB02C(int arg0);
void sub_81CB050(u32 arg0, u8 *str);
u8 sub_81CB0C8(int rematchIndex);
int sub_81CB0E4(int index);
bool32 sub_81CAE08(int);
int sub_81CB128(int index);

// pokenav_unk_4.c
bool32 sub_81CB260(void);
void sub_81CB29C(int index);
u32 sub_81CB2CC(void);
void sub_81CB2E0(void);
void sub_81CBD48(u16 windowId, u32 a1);

// pokenav_unk_5.c
u32 sub_81CC4D4(void);
void sub_81CC524(void);
u32 sub_81CC554(void);
bool32 sub_81CC5F4(void);
void sub_81CC62C(int);
u32 sub_81CC65C(void);
void sub_81CC670(void);

#endif //GUARD_POKENAV_H
