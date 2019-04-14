#ifndef GUARD_POKENAV_H
#define GUARD_POKENAV_H

typedef u32 (*LoopedTask)(int state);

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

// pokenav_match_call_ui.c

// pokenav_main_menu.c
bool32 InitPokenavMainMenu(void);
void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 bufferOffset, u32 size);
void sub_81C7850(u32 a0);
u32 sub_81C786C(void);

// pokenav_unk_1.c
bool32 sub_81C9298(void);
bool32 sub_81C92CC(void);
bool32 sub_81C9304(void);
bool32 sub_81C9338(void);
bool32 sub_81C9368(void);
u32 sub_81C941C(void);
void sub_81C9430(void);
int sub_81C9894(void);

// pokenav_unk_2.c
u32 sub_81C99D4(void);
void sub_81CAADC(void);

// pokenav_unk_3.c
bool32 sub_81CAAE8(void);
u32 sub_81CAB24(void);
void sub_81CAB38(void);

#endif //GUARD_POKENAV_H
