	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ClearDma3Requests
@ void ClearDma3Requests()
ClearDma3Requests: @ 8000BB8
	push {lr}
	ldr r2, =gDma3ManagerLocked
	movs r0, 0x1
	strb r0, [r2]
	ldr r1, =gDma3RequestCursor
	movs r0, 0
	strb r0, [r1]
	movs r3, 0
	ldr r0, =gDma3Requests
	movs r1, 0x7F
_8000BCC:
	strh r3, [r0, 0x8]
	str r3, [r0]
	str r3, [r0, 0x4]
	adds r0, 0x10
	subs r1, 0x1
	cmp r1, 0
	bge _8000BCC
	movs r0, 0
	strb r0, [r2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearDma3Requests

	thumb_func_start ProcessDma3Requests
@ void ProcessDma3Requests()
ProcessDma3Requests: @ 8000BF0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r0, =gDma3ManagerLocked
	ldrb r0, [r0]
	cmp r0, 0
	beq _08000C06
	b _08000E46
_08000C06:
	movs r0, 0
	str r0, [sp, 0x8]
	ldr r1, =gDma3Requests
	ldr r2, =gDma3RequestCursor
	ldrb r0, [r2]
	lsls r0, 4
	adds r0, r1
	ldrh r0, [r0, 0x8]
	mov r12, r2
	cmp r0, 0
	bne _08000C1E
	b _08000E46
_08000C1E:
	mov r8, r1
	adds r1, 0x4
	mov r10, r1
	movs r6, 0x80
	lsls r6, 5
	ldr r7, =REG_DMA3
	movs r2, 0
	mov r9, r2
_08000C2E:
	mov r3, r12
	ldrb r0, [r3]
	lsls r5, r0, 4
	mov r0, r8
	adds r1, r5, r0
	ldrh r0, [r1, 0x8]
	ldr r2, [sp, 0x8]
	adds r0, r2, r0
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	movs r0, 0xA0
	lsls r0, 8
	ldr r3, [sp, 0x8]
	cmp r3, r0
	bls _08000C50
	b _08000E46
_08000C50:
	ldr r0, =REG_VCOUNT
	ldrb r0, [r0]
	cmp r0, 0xE0
	bls _08000C5A
	b _08000E46
_08000C5A:
	ldrh r0, [r1, 0xA]
	cmp r0, 0x2
	beq _08000CD0
	cmp r0, 0x2
	bgt _08000C80
	cmp r0, 0x1
	beq _08000C8C
	b _08000DF0
	.pool
_08000C80:
	cmp r0, 0x3
	beq _08000D3C
	cmp r0, 0x4
	bne _08000C8A
	b _08000D88
_08000C8A:
	b _08000DF0
_08000C8C:
	ldr r3, [r1]
	mov r2, r10
	adds r0, r5, r2
	ldr r2, [r0]
	ldrh r1, [r1, 0x8]
	cmp r1, r6
	bhi _08000CA6
	str r3, [r7]
	str r2, [r7, 0x4]
	lsrs r0, r1, 2
	movs r1, 0x84
	lsls r1, 24
	b _08000DAA
_08000CA6:
	ldr r4, =REG_DMA3
	str r3, [r4]
	str r2, [r4, 0x4]
	ldr r0, =0x84000400
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	adds r3, r6
	adds r2, r6
	subs r1, r6
	cmp r1, r6
	bhi _08000CA6
	str r3, [r4]
	str r2, [r4, 0x4]
	lsrs r0, r1, 2
	movs r1, 0x84
	lsls r1, 24
	b _08000D76
	.pool
_08000CD0:
	mov r3, r10
	adds r0, r5, r3
	ldr r4, [r0]
	ldrh r1, [r1, 0x8]
	cmp r1, r6
	bhi _08000CF4
	mov r0, r8
	adds r0, 0xC
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [sp]
	mov r5, sp
	str r5, [r7]
	str r4, [r7, 0x4]
	lsrs r0, r1, 2
	movs r1, 0x85
	lsls r1, 24
	b _08000DAA
_08000CF4:
	mov r2, r12
	ldrb r0, [r2]
	lsls r0, 4
	mov r5, r8
	adds r5, 0xC
	adds r0, r5
	ldr r0, [r0]
	str r0, [sp]
	ldr r3, =REG_DMA3
	mov r0, sp
	str r0, [r3]
	str r4, [r3, 0x4]
	ldr r0, =0x85000400
	str r0, [r3, 0x8]
	ldr r0, [r3, 0x8]
	adds r4, r6
	subs r1, r6
	cmp r1, r6
	bhi _08000CF4
	ldrb r0, [r2]
	lsls r0, 4
	adds r0, r5
	ldr r0, [r0]
	str r0, [sp]
	mov r2, sp
	str r2, [r3]
	str r4, [r3, 0x4]
	lsrs r0, r1, 2
	movs r1, 0x85
	lsls r1, 24
	b _08000DEA
	.pool
_08000D3C:
	ldr r3, [r1]
	mov r2, r10
	adds r0, r5, r2
	ldr r2, [r0]
	ldrh r1, [r1, 0x8]
	cmp r1, r6
	bhi _08000D56
	str r3, [r7]
	str r2, [r7, 0x4]
	lsrs r0, r1, 1
	movs r1, 0x80
	lsls r1, 24
	b _08000DAA
_08000D56:
	ldr r4, =REG_DMA3
	str r3, [r4]
	str r2, [r4, 0x4]
	ldr r0, =0x80000800
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	adds r3, r6
	adds r2, r6
	subs r1, r6
	cmp r1, r6
	bhi _08000D56
	str r3, [r4]
	str r2, [r4, 0x4]
	lsrs r0, r1, 1
	movs r1, 0x80
	lsls r1, 24
_08000D76:
	orrs r0, r1
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	b _08000DF0
	.pool
_08000D88:
	mov r3, r10
	adds r0, r5, r3
	ldr r2, [r0]
	ldrh r4, [r1, 0x8]
	add r1, sp, 0x4
	cmp r4, r6
	bhi _08000DB2
	mov r0, r8
	adds r0, 0xC
	adds r0, r5, r0
	ldr r0, [r0]
	strh r0, [r1]
	str r1, [r7]
	str r2, [r7, 0x4]
	lsrs r0, r4, 1
	movs r1, 0x81
	lsls r1, 24
_08000DAA:
	orrs r0, r1
	str r0, [r7, 0x8]
	ldr r0, [r7, 0x8]
	b _08000DF0
_08000DB2:
	mov r5, r12
	ldrb r0, [r5]
	lsls r0, 4
	ldr r3, =0x0300001c
	adds r0, r3
	ldr r0, [r0]
	strh r0, [r1]
	ldr r3, =REG_DMA3
	str r1, [r3]
	str r2, [r3, 0x4]
	ldr r0, =0x81000800
	str r0, [r3, 0x8]
	ldr r0, [r3, 0x8]
	adds r2, r6
	subs r4, r6
	cmp r4, r6
	bhi _08000DB2
	ldrb r0, [r5]
	lsls r0, 4
	ldr r5, =0x0300001c
	adds r0, r5
	ldr r0, [r0]
	strh r0, [r1]
	str r1, [r3]
	str r2, [r3, 0x4]
	lsrs r0, r4, 1
	movs r1, 0x81
	lsls r1, 24
_08000DEA:
	orrs r0, r1
	str r0, [r3, 0x8]
	ldr r0, [r3, 0x8]
_08000DF0:
	ldr r1, =gDma3Requests
	mov r3, r12
	ldrb r0, [r3]
	lsls r0, 4
	adds r0, r1
	mov r2, r9
	str r2, [r0]
	ldrb r0, [r3]
	lsls r0, 4
	add r0, r10
	str r2, [r0]
	ldrb r0, [r3]
	lsls r0, 4
	adds r0, r1
	movs r4, 0
	strh r2, [r0, 0x8]
	ldrb r0, [r3]
	lsls r0, 4
	adds r0, r1
	mov r5, r9
	strh r5, [r0, 0xA]
	ldrb r0, [r3]
	lsls r0, 4
	adds r1, 0xC
	adds r0, r1
	mov r1, r9
	str r1, [r0]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	lsls r0, 24
	cmp r0, 0
	bge _08000E34
	strb r4, [r3]
_08000E34:
	mov r2, r12
	ldrb r0, [r2]
	lsls r0, 4
	ldr r3, =gDma3Requests
	adds r0, r3
	ldrh r0, [r0, 0x8]
	cmp r0, 0
	beq _08000E46
	b _08000C2E
_08000E46:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ProcessDma3Requests

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
