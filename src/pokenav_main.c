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

/*
thumb_func_start sub_81C7078
sub_81C7078: @ 81C7078
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl is_c1_link_related_active
	cmp r0, 0
	bne _081C7090
	ldr r0, =sub_81C7170
	b _081C7092
	.pool
_081C7090:
	ldr r0, =sub_81C71E4
_081C7092:
	lsls r1, r4, 24
	lsrs r1, 24
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r2, =gUnknown_0203CF3C
	ldrb r1, [r2]
	strh r1, [r0, 0xE]
	ldrb r0, [r2]
	adds r1, r0, 0x1
	strb r1, [r2]
	lsls r0, 24
	lsrs r0, 8
	orrs r0, r4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C7078
    */

extern u8 gUnknown_0203CF3C;
extern void sub_81C7170(u8 a0);
extern void sub_81C71E4(u8 a0);

u32 sub_81C7078(s32 a0, u32 a1)
{
    u16 taskId;
    u32 old;

    if (is_c1_link_related_active() == FALSE)
        taskId = CreateTask(sub_81C7170, a1);
	else
        taskId = CreateTask(sub_81C71E4, a1);

    //taskId = CreateTask(temp, a1);

    SetWordTaskArg(taskId, 1, a0);

    gTasks[taskId].data[3] = gUnknown_0203CF3C;
    //old = gUnknown_0203CF3C;
    //gUnknown_0203CF3C = old + 1;
    return ((gUnknown_0203CF3C++) << 16) | taskId;
}

// nonce