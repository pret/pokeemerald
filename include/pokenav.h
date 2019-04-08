#ifndef GUARD_POKENAV_H
#define GUARD_POKENAV_H

#include "bg.h"

typedef u32 (*LoopedTask)(s32 state);

// Return values of LoopedTask functions.
#define LT_INC_AND_PAUSE 0
#define LT_INC_AND_CONTINUE 1
#define LT_PAUSE 2
#define LT_CONTINUE 3
#define LT_FINISH 4
#define LT_SET_STATE(newState) (newState + 5)

void InitBgTemplates(const struct BgTemplate *templates, s32 count);
void CopyPaletteIntoBufferUnfaded(const u16 *palette, u32 a1, u32 a2);
void sub_81C7AC0(s32 a0);
void LoadLeftHeaderGfxForIndex(u32 arg0);
bool32 IsPaletteFadeActive(void);
void sub_81C7FA0(u32 arg0, bool32 arg1, bool32 arg2);
bool32 sub_81C8010(void);

// pokenav.c
extern void sub_81C99D4(void);

void CB2_InitPokeNav(void);
u32 CreateLoopedTask(LoopedTask loopedTask, u32 priority);
bool32 FuncIsActiveLoopedTask(LoopedTask func);
void *GetSubstructPtr(u32 index);
void FreePokenavSubstruct(u32 index);
void *AllocSubstruct(u32 index, u32 size);
void Pokenav_AllocAndLoadPalettes(const struct SpritePalette *palettes);
bool32 IsLoopedTaskActive(u32 taskId);

// pokenav_match_call_ui.c

#endif //GUARD_POKENAV_H
