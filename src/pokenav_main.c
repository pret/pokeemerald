#include "global.h"
#include "alloc.h"
#include "task.h"
#include "main.h"
#include "overworld.h"

/*

	thumb_func_start CB2_PokeNav
CB2_PokeNav: @ 81C7250
	push {r4,lr}
	ldr r4, =gUnknown_0203CF40
	movs r0, 0x5C
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	bne _081C7270
	ldr r0, =CB2_ReturnToFieldWithOpenMenu
	bl SetMainCallback2
	b _081C7292
	.pool
_081C7270:
	bl sub_81C7360
	bl ResetTasks
	movs r0, 0
	bl SetVBlankCallback
	ldr r0, =sub_81C742C
	movs r1, 0
	bl CreateTask
	ldr r0, =sub_81C7400
	bl SetMainCallback2
	ldr r0, =sub_81C7418
	bl SetVBlankCallback
_081C7292:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_PokeNav

*/

extern u8* gUnknown_0203CF40;
extern void sub_81C7360(void);
extern void sub_81C742C(u8 taskId);
extern void sub_81C7400(void);
extern void sub_81C7418(void);

/*
void CB2_PokeNav(void)
{
    gUnknown_0203CF40 = Alloc(0x5C);
    if (gUnknown_0203CF40 == NULL) {
        SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    } else {
        sub_81C7360();
        ResetTasks();
        SetVBlankCallback(NULL);
        CreateTask(sub_81C742C, 0);
        SetMainCallback2(sub_81C7400);
        SetVBlankCallback(sub_81C7418);
    }
}*/

extern u8 gUnknown_0203CF3C;
extern void sub_81C7170(u8 a0);
extern void sub_81C71E4(u8 a0);

u32 sub_81C7078(s32 a0, u32 a1)
{
    u16 taskId;

    if (!is_c1_link_related_active())
        taskId = CreateTask(sub_81C7170, a1);
	else
        taskId = CreateTask(sub_81C71E4, a1);

    SetWordTaskArg(taskId, 1, a0);

    gTasks[taskId].data[3] = gUnknown_0203CF3C;
    return ((gUnknown_0203CF3C++) << 16) | taskId;
}

bool32 sub_81C70D8(u32 a0, u32 unused) {
	u32 v1 = a0 & 0xFFFF;
	u32 v2 = a0 >> 16;
	if (gTasks[v1].isActive
		&& (gTasks[v1].func == sub_81C7170 || gTasks[v1].func == sub_81C71E4)
		&& gTasks[v1].data[3] == v2) {
	
		return TRUE;
	} else {
		return FALSE;
	}
}

