	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start RequestDma3Copy
@ int RequestDma3Copy(void *src, void *dest, u16 size, u8 mode)
RequestDma3Copy: @ 8000E68
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r12, r0
	mov r8, r1
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 24
	lsrs r4, r3, 24
	movs r5, 0
	ldr r1, =gDma3ManagerLocked
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =gDma3RequestCursor
	ldrb r2, [r0]
	mov r10, r1
	ldr r6, =gDma3Requests
	mov r9, r6
	lsls r0, r2, 4
	adds r1, r0, r6
_08000E94:
	lsls r3, r2, 4
	ldrh r0, [r1, 0x8]
	cmp r0, 0
	bne _08000ED4
	mov r0, r12
	str r0, [r1]
	mov r0, r9
	adds r0, 0x4
	adds r0, r3, r0
	mov r3, r8
	str r3, [r0]
	strh r7, [r1, 0x8]
	cmp r4, 0x1
	bne _08000EC0
	strh r4, [r1, 0xA]
	b _08000EC4
	.pool
_08000EC0:
	movs r0, 0x3
	strh r0, [r1, 0xA]
_08000EC4:
	movs r0, 0
	ldr r1, =gDma3ManagerLocked
	strb r0, [r1]
	lsls r0, r2, 16
	asrs r0, 16
	b _08000EF0
	.pool
_08000ED4:
	adds r1, 0x10
	adds r2, 0x1
	cmp r2, 0x7F
	ble _08000EE0
	adds r1, r6, 0
	movs r2, 0
_08000EE0:
	adds r5, 0x1
	cmp r5, 0x7F
	ble _08000E94
	movs r0, 0
	mov r3, r10
	strb r0, [r3]
	movs r0, 0x1
	negs r0, r0
_08000EF0:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end RequestDma3Copy

	thumb_func_start RequestDma3Fill
@ int RequestDma3Fill(s32 value, void *dest, u16 size, u8 mode)
RequestDma3Fill: @ 8000F00
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	mov r8, r1
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 24
	lsrs r5, r3, 24
	movs r6, 0
	ldr r0, =gDma3RequestCursor
	ldrb r2, [r0]
	ldr r1, =gDma3ManagerLocked
	movs r0, 0x1
	strb r0, [r1]
	mov r10, r1
	ldr r0, =gDma3Requests
	mov r12, r0
	mov r4, r12
	lsls r0, r2, 4
	adds r0, 0x8
	adds r1, r0, r4
_8000F30:
	lsls r3, r2, 4
	ldrh r0, [r1]
	cmp r0, 0
	bne _08000F78
	adds r0, r4, 0x4
	adds r0, r3, r0
	mov r6, r8
	str r6, [r0]
	strh r7, [r1]
	strh r5, [r1, 0x2]
	adds r0, r4, 0
	adds r0, 0xC
	adds r0, r3, r0
	mov r3, r9
	str r3, [r0]
	cmp r5, 0x1
	bne _08000F64
	movs r0, 0x2
	b _08000F66
	.pool
_08000F64:
	movs r0, 0x4
_08000F66:
	strh r0, [r1, 0x2]
	movs r0, 0
	ldr r6, =gDma3ManagerLocked
	strb r0, [r6]
	lsls r0, r2, 16
	asrs r0, 16
	b _08000F96
	.pool
_08000F78:
	adds r1, 0x10
	adds r2, 0x1
	cmp r2, 0x7F
	ble _08000F86
	mov r1, r12
	adds r1, 0x8
	movs r2, 0
_08000F86:
	adds r6, 0x1
	cmp r6, 0x7F
	ble _8000F30
	movs r0, 0
	mov r1, r10
	strb r0, [r1]
	movs r0, 0x1
	negs r0, r0
_08000F96:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end RequestDma3Fill

	thumb_func_start CheckForSpaceForDma3Request
@ int CheckForSpaceForDma3Request(s16 index)
CheckForSpaceForDma3Request: @ 8000FA4
	push {lr}
	movs r2, 0
	lsls r0, 16
	asrs r1, r0, 16
	movs r3, 0x1
	negs r3, r3
	cmp r1, r3
	bne _08000FCC
	ldr r1, =gDma3Requests
_08000FB6:
	ldrh r0, [r1, 0x8]
	cmp r0, 0
	bne _08000FD8
	adds r1, 0x10
	adds r2, 0x1
	cmp r2, 0x7F
	ble _08000FB6
_08000FC4:
	movs r0, 0
	b _08000FDC
	.pool
_08000FCC:
	ldr r0, =gDma3Requests
	lsls r1, 4
	adds r1, r0
	ldrh r0, [r1, 0x8]
	cmp r0, 0
	beq _08000FC4
_08000FD8:
	movs r0, 0x1
	negs r0, r0
_08000FDC:
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckForSpaceForDma3Request

	.align 2, 0 @ Don't pad with nop.
