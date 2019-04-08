#ifndef GUARD_POKENAV_H
#define GUARD_POKENAV_H

typedef u32 (*LoopedTask)(s32 state);

// Return values of LoopedTask functions.
#define LT_INC_AND_PAUSE 0
#define LT_INC_AND_CONTINUE 1
#define LT_PAUSE 2
#define LT_CONTINUE 3
#define LT_FINISH 4
#define LT_SET_STATE(newState) (newState + 5)

#define UNKNOWN_POKENAV_OFFSET 100000

// pokenav.c
extern u32 sub_81C99D4(void);

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

// pokenav_unk_1.c
u32 sub_81C9298(void);
u32 sub_81C92CC(void);
u32 sub_81C9304(void);
u32 sub_81C9338(void);
u32 sub_81C9368(void);
u32 sub_81C941C(void);
void sub_81C9430(void);


#endif //GUARD_POKENAV_H
