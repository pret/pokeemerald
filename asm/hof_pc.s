	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start AccessHallOfFamePC
AccessHallOfFamePC: @ 8137C28
	push {lr}
	ldr r0, =CB2_DoHallOfFamePC
	bl SetMainCallback2
	bl ScriptContext2_Enable
	pop {r0}
	bx r0
	.pool
	thumb_func_end AccessHallOfFamePC

	thumb_func_start ReturnFromHallOfFamePC
ReturnFromHallOfFamePC: @ 8137C3C
	push {lr}
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	ldr r1, =gFieldCallback
	ldr r0, =ReshowPCMenuAfterHallOfFamePC
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end ReturnFromHallOfFamePC

	thumb_func_start ReshowPCMenuAfterHallOfFamePC
ReshowPCMenuAfterHallOfFamePC: @ 8137C5C
	push {lr}
	sub sp, 0x4
	bl ScriptContext2_Enable
	bl sub_8085784
	bl sp109_CreatePCMenu
	bl sub_80E2514
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r0, =Task_WaitForPaletteFade
	movs r1, 0xA
	bl CreateTask
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ReshowPCMenuAfterHallOfFamePC

	thumb_func_start Task_WaitForPaletteFade
Task_WaitForPaletteFade: @ 8137C94
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08137CAC
	adds r0, r2, 0
	bl DestroyTask
_08137CAC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_WaitForPaletteFade
