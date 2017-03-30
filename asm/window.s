	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ScrollWindow
@ void ScrollWindow(u8 windowId, u8 direction, u8 distance, u8 fillValue)
ScrollWindow: @ 8003C94
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r8, r1
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp]
	lsls r3, 24
	lsrs r3, 24
	ldr r2, =gWindows
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r4, r1, r2
	adds r2, 0x8
	adds r1, r2
	ldr r5, [r1]
	lsls r7, r3, 24
	lsls r0, r3, 16
	orrs r7, r0
	lsls r0, r3, 8
	orrs r7, r0
	orrs r7, r3
	ldr r1, [r4]
	ldr r2, [r4, 0x4]
	ldrb r3, [r4, 0x4]
	lsrs r0, r1, 24
	muls r0, r3
	lsls r6, r0, 5
	lsrs r1, 24
	mov r12, r1
	mov r0, r8
	cmp r0, 0x1
	bne _08003CE8
	b _08003E9E
_08003CE8:
	cmp r0, 0x1
	ble _08003CEE
	b _08004046
_08003CEE:
	cmp r0, 0
	beq _08003CF4
	b _08004046
_08003CF4:
	movs r4, 0
	cmp r4, r6
	blt _08003CFC
	b _08004046
_08003CFC:
	movs r1, 0x8
	negs r1, r1
	mov r9, r1
	movs r2, 0x7
	mov r8, r2
	mov r10, r5
_08003D08:
	ldr r3, [sp]
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	adds r0, r3, 0
	mov r2, r8
	ands r0, r2
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003D34
	adds r0, r5, r1
	ldr r0, [r0]
	mov r1, r10
	str r0, [r1]
	b _08003D38
	.pool
_08003D34:
	mov r2, r10
	str r7, [r2]
_08003D38:
	adds r3, 0x1
	adds r2, r4, 0x4
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003D64
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003D68
_08003D64:
	adds r0, r5, r2
	str r7, [r0]
_08003D68:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x8
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003D96
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003D9A
_08003D96:
	adds r0, r5, r2
	str r7, [r0]
_08003D9A:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0xC
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003DC8
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003DCC
_08003DC8:
	adds r0, r5, r2
	str r7, [r0]
_08003DCC:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x10
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003DFA
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003DFE
_08003DFA:
	adds r0, r5, r2
	str r7, [r0]
_08003DFE:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x14
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003E2C
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003E30
_08003E2C:
	adds r0, r5, r2
	str r7, [r0]
_08003E30:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x18
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003E5E
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003E62
_08003E5E:
	adds r0, r5, r2
	str r7, [r0]
_08003E62:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x1C
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	adds r0, r1, 0
	mov r1, r8
	ands r3, r1
	orrs r0, r3
	lsls r0, 2
	adds r1, r4, r0
	cmp r1, r6
	bge _08003E8C
	adds r0, r5, r2
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003E90
_08003E8C:
	adds r0, r5, r2
	str r7, [r0]
_08003E90:
	movs r2, 0x20
	add r10, r2
	adds r4, 0x20
	cmp r4, r6
	bge _08003E9C
	b _08003D08
_08003E9C:
	b _08004046
_08003E9E:
	subs r0, r6, 0x4
	adds r5, r0
	movs r4, 0
	cmp r4, r6
	blt _08003EAA
	b _08004046
_08003EAA:
	movs r0, 0x8
	negs r0, r0
	mov r9, r0
	movs r1, 0x7
	mov r8, r1
	mov r10, r5
_08003EB6:
	ldr r3, [sp]
	adds r0, r3, 0
	mov r2, r9
	ands r0, r2
	mov r1, r12
	muls r1, r0
	adds r0, r3, 0
	mov r2, r8
	ands r0, r2
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003EDC
	subs r0, r5, r1
	ldr r0, [r0]
	mov r1, r10
	str r0, [r1]
	b _08003EE0
_08003EDC:
	mov r2, r10
	str r7, [r2]
_08003EE0:
	adds r3, 0x1
	adds r2, r4, 0x4
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003F0C
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003F10
_08003F0C:
	subs r0, r5, r2
	str r7, [r0]
_08003F10:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x8
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003F3E
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003F42
_08003F3E:
	subs r0, r5, r2
	str r7, [r0]
_08003F42:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0xC
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003F70
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003F74
_08003F70:
	subs r0, r5, r2
	str r7, [r0]
_08003F74:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x10
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003FA2
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003FA6
_08003FA2:
	subs r0, r5, r2
	str r7, [r0]
_08003FA6:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x14
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08003FD4
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08003FD8
_08003FD4:
	subs r0, r5, r2
	str r7, [r0]
_08003FD8:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x18
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	str r1, [sp, 0x4]
	adds r0, r3, 0
	mov r1, r8
	ands r0, r1
	ldr r1, [sp, 0x4]
	orrs r1, r0
	lsls r1, 2
	adds r1, r4, r1
	cmp r1, r6
	bge _08004006
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _0800400A
_08004006:
	subs r0, r5, r2
	str r7, [r0]
_0800400A:
	adds r3, 0x1
	adds r2, r4, 0
	adds r2, 0x1C
	adds r0, r3, 0
	mov r1, r9
	ands r0, r1
	mov r1, r12
	muls r1, r0
	adds r0, r1, 0
	mov r1, r8
	ands r3, r1
	orrs r0, r3
	lsls r0, 2
	adds r1, r4, r0
	cmp r1, r6
	bge _08004034
	subs r0, r5, r2
	subs r1, r5, r1
	ldr r1, [r1]
	str r1, [r0]
	b _08004038
_08004034:
	subs r0, r5, r2
	str r7, [r0]
_08004038:
	movs r2, 0x20
	negs r2, r2
	add r10, r2
	adds r4, 0x20
	cmp r4, r6
	bge _08004046
	b _08003EB6
_08004046:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ScrollWindow

	thumb_func_start CallWindowFunction
@ void CallWindowFunction(u8 windowId, void ( *func)(u8, u8, u8, u8, u8, u8))
CallWindowFunction: @ 8004058
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x8
	mov r8, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gWindows
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r5, [r1]
	ldr r6, [r1, 0x4]
	ldrb r0, [r1]
	lsrs r1, r5, 8
	lsls r1, 24
	lsrs r1, 24
	lsrs r2, r5, 16
	lsls r2, 24
	lsrs r2, 24
	lsrs r3, r5, 24
	lsls r4, r6, 24
	lsrs r4, 24
	str r4, [sp]
	lsrs r4, r6, 8
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x4]
	bl _call_via_r8
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CallWindowFunction

	thumb_func_start SetWindowAttribute
@ bool8 SetWindowAttribute(u8 windowId, u8 attributeId, u32 value)
SetWindowAttribute: @ 80040A8
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r0, r1, 24
	cmp r0, 0x7
	bhi _08004142
	lsls r0, 2
	ldr r1, =_080040C4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080040C4:
	.4byte _08004142
	.4byte _080040E4
	.4byte _080040F8
	.4byte _08004142
	.4byte _08004142
	.4byte _0800410C
	.4byte _08004120
	.4byte _08004134
_080040E4:
	ldr r1, =gWindows
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	strb r2, [r0, 0x1]
	movs r0, 0
	b _08004144
	.pool
_080040F8:
	ldr r1, =gWindows
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	strb r2, [r0, 0x2]
	movs r0, 0
	b _08004144
	.pool
_0800410C:
	ldr r1, =gWindows
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	strb r2, [r0, 0x5]
	movs r0, 0
	b _08004144
	.pool
_08004120:
	ldr r1, =gWindows
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r0, r1
	strh r2, [r0, 0x6]
	movs r0, 0
	b _08004144
	.pool
_08004134:
	ldr r1, =gWindows
	lsls r0, r3, 1
	adds r0, r3
	lsls r0, 2
	adds r1, 0x8
	adds r0, r1
	str r2, [r0]
_08004142:
	movs r0, 0x1
_08004144:
	pop {r1}
	bx r1
	.pool
	thumb_func_end SetWindowAttribute

	thumb_func_start GetWindowAttribute
@ u32 GetWindowAttribute(u8 windowId, u8 attributeId)
GetWindowAttribute: @ 800414C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r0, r1, 24
	cmp r0, 0x7
	bhi _08004228
	lsls r0, 2
	ldr r1, =_08004168
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08004168:
	.4byte _08004188
	.4byte _0800419C
	.4byte _080041B0
	.4byte _080041C4
	.4byte _080041D8
	.4byte _080041EC
	.4byte _08004200
	.4byte _08004214
_08004188:
	ldr r0, =gWindows
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1]
	b _0800422A
	.pool
_0800419C:
	ldr r0, =gWindows
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x1]
	b _0800422A
	.pool
_080041B0:
	ldr r0, =gWindows
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	b _0800422A
	.pool
_080041C4:
	ldr r0, =gWindows
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x3]
	b _0800422A
	.pool
_080041D8:
	ldr r0, =gWindows
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x4]
	b _0800422A
	.pool
_080041EC:
	ldr r0, =gWindows
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x5]
	b _0800422A
	.pool
_08004200:
	ldr r0, =gWindows
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x6]
	b _0800422A
	.pool
_08004214:
	ldr r0, =gWindows
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r0, 0x8
	adds r1, r0
	ldr r0, [r1]
	b _0800422A
	.pool
_08004228:
	movs r0, 0
_0800422A:
	pop {r1}
	bx r1
	thumb_func_end GetWindowAttribute

	thumb_func_start GetNumActiveWindowsOnBg
@ u8 GetNumActiveWindowsOnBg(u8 bgId)
GetNumActiveWindowsOnBg: @ 8004230
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r2, =gWindows
	movs r1, 0x1F
_0800423C:
	ldrb r0, [r2]
	cmp r0, r4
	bne _08004248
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
_08004248:
	adds r2, 0xC
	subs r1, 0x1
	cmp r1, 0
	bge _0800423C
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetNumActiveWindowsOnBg

	thumb_func_start nullsub_9
nullsub_9: @ 800425C
	bx lr
	thumb_func_end nullsub_9

	thumb_func_start AddWindow8Bit
@ u16 AddWindow8Bit(struct WindowTemplate *template)
AddWindow8Bit: @ 8004260
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r9, r0
	movs r6, 0
	ldr r1, =gWindows
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _0800428E
_08004276:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1F
	bhi _0800428E
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _08004276
_0800428E:
	cmp r6, 0x20
	beq _08004322
	mov r0, r9
	ldrb r7, [r0]
	ldr r1, =gUnknown_03002F70
	mov r10, r1
	lsls r2, r7, 2
	mov r8, r2
	mov r0, r8
	add r0, r10
	ldr r0, [r0]
	cmp r0, 0
	bne _080042EA
	adds r0, r7, 0
	movs r1, 0x8
	bl GetBgAttribute
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _080042EA
	adds r0, r5, 0
	bl Alloc
	adds r4, r0, 0
	cmp r4, 0
	beq _08004322
	movs r1, 0
	mov r12, r10
	mov r3, r8
	cmp r1, r5
	bge _080042DC
	movs r2, 0
_080042D2:
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, 0x1
	cmp r1, r5
	blt _080042D2
_080042DC:
	mov r1, r12
	adds r0, r3, r1
	str r4, [r0]
	adds r0, r7, 0
	adds r1, r4, 0
	bl SetBgTilemapBuffer
_080042EA:
	mov r2, r9
	ldrb r1, [r2, 0x3]
	ldrb r0, [r2, 0x4]
	muls r0, r1
	lsls r0, 22
	lsrs r0, 16
	bl Alloc
	adds r4, r0, 0
	cmp r4, 0
	bne _08004338
	adds r0, r7, 0
	bl GetNumActiveWindowsOnBg8Bit
	lsls r0, 24
	cmp r0, 0
	bne _08004322
	ldr r0, =gUnknown_03002F70
	lsls r1, r7, 2
	adds r5, r1, r0
	ldr r1, [r5]
	ldr r0, =nullsub_9
	cmp r1, r0
	beq _08004322
	adds r0, r1, 0
	bl Free
	str r4, [r5]
_08004322:
	movs r0, 0xFF
	b _08004356
	.pool
_08004338:
	ldr r1, =gWindows
	lsls r2, r6, 1
	adds r2, r6
	lsls r2, 2
	adds r0, r1, 0
	adds r0, 0x8
	adds r0, r2, r0
	str r4, [r0]
	adds r2, r1
	mov r3, r9
	ldr r0, [r3]
	ldr r1, [r3, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	adds r0, r6, 0
_08004356:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddWindow8Bit

	thumb_func_start FillWindowPixelBuffer8Bit
@ void FillWindowPixelBuffer8Bit(u8 windowId, u8 fillValue)
FillWindowPixelBuffer8Bit: @ 8004368
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r6, =gWindows
	lsls r1, r0, 1
	adds r1, r0
	lsls r4, r1, 2
	adds r0, r4, r6
	ldrb r1, [r0, 0x3]
	ldrb r0, [r0, 0x4]
	muls r0, r1
	lsls r0, 22
	lsrs r3, r0, 16
	movs r2, 0
	cmp r2, r3
	bge _0800439E
	adds r0, r6, 0
	adds r0, 0x8
	adds r1, r4, r0
_08004392:
	ldr r0, [r1]
	adds r0, r2
	strb r5, [r0]
	adds r2, 0x1
	cmp r2, r3
	blt _08004392
_0800439E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FillWindowPixelBuffer8Bit

	thumb_func_start FillWindowPixelRect8Bit
@ void FillWindowPixelRect8Bit(u8 windowId, u8 fillValue, u16 x, u16 y, u16 width, u16 height)
FillWindowPixelRect8Bit: @ 80043A8
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	mov r9, r3
	ldr r3, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	mov r8, r4
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 16
	lsrs r2, 16
	mov r4, r9
	lsls r4, 16
	lsrs r4, 16
	mov r9, r4
	lsls r3, 16
	lsrs r3, 16
	mov r4, r8
	lsls r4, 16
	lsrs r4, 16
	mov r8, r4
	ldr r5, =gWindows
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	adds r0, r5, 0
	adds r0, 0x8
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [sp, 0x8]
	adds r4, r5
	ldrb r0, [r4, 0x3]
	lsls r0, 3
	ldr r6, =0xffff0000
	ldr r5, [sp, 0xC]
	ands r5, r6
	orrs r5, r0
	str r5, [sp, 0xC]
	ldrb r4, [r4, 0x4]
	lsls r4, 19
	ldr r0, =0x0000ffff
	ands r0, r5
	orrs r0, r4
	str r0, [sp, 0xC]
	mov r0, r8
	str r0, [sp]
	str r1, [sp, 0x4]
	add r0, sp, 0x8
	adds r1, r2, 0
	mov r2, r9
	bl FillBitmapRect8Bit
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FillWindowPixelRect8Bit

	thumb_func_start BlitBitmapRectToWindow4BitTo8Bit
@ void BlitBitmapRectToWindow4BitTo8Bit(u8 rbox_id, u8 *pixels, u16 srcX, u16 srcY, u16 srcWidth, int srcHeight, u16 destX, u16 destY, u16 rectWidth, u16 rectHeight, u8 paletteOffset)
BlitBitmapRectToWindow4BitTo8Bit: @ 8004434
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	ldr r4, [sp, 0x4C]
	ldr r5, [sp, 0x50]
	ldr r6, [sp, 0x54]
	mov r8, r6
	ldr r7, [sp, 0x58]
	mov r9, r7
	ldr r6, [sp, 0x5C]
	mov r10, r6
	ldr r7, [sp, 0x60]
	mov r12, r7
	ldr r6, [sp, 0x64]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	mov r7, r8
	lsls r7, 16
	lsrs r7, 16
	mov r8, r7
	mov r7, r9
	lsls r7, 16
	lsrs r7, 16
	mov r9, r7
	mov r7, r10
	lsls r7, 16
	lsrs r7, 16
	mov r10, r7
	mov r7, r12
	lsls r7, 16
	lsrs r7, 16
	mov r12, r7
	lsls r6, 24
	lsrs r6, 24
	str r6, [sp, 0x28]
	str r1, [sp, 0x18]
	lsls r5, 16
	ldr r6, =0x0000ffff
	lsrs r4, 16
	orrs r4, r5
	str r4, [sp, 0x1C]
	ldr r1, =gWindows
	lsls r5, r0, 1
	adds r5, r0
	lsls r5, 2
	adds r0, r1, 0
	adds r0, 0x8
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [sp, 0x20]
	adds r5, r1
	ldrb r0, [r5, 0x3]
	lsls r0, 3
	add r1, sp, 0x20
	ldr r4, [r1, 0x4]
	ldr r7, =0xffff0000
	ands r4, r7
	orrs r4, r0
	str r4, [r1, 0x4]
	ldrb r0, [r5, 0x4]
	lsls r0, 19
	ands r6, r4
	orrs r6, r0
	str r6, [r1, 0x4]
	mov r0, r8
	str r0, [sp]
	mov r6, r9
	str r6, [sp, 0x4]
	mov r7, r10
	str r7, [sp, 0x8]
	mov r0, r12
	str r0, [sp, 0xC]
	movs r0, 0
	str r0, [sp, 0x10]
	ldr r6, [sp, 0x28]
	str r6, [sp, 0x14]
	add r0, sp, 0x18
	bl BlitBitmapRect4BitTo8Bit
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BlitBitmapRectToWindow4BitTo8Bit

	thumb_func_start CopyWindowToVram8Bit
@ void CopyWindowToVram8Bit(u8 windowId, u8 mode)
CopyWindowToVram8Bit: @ 8004500
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	adds r5, r2, 0
	ldr r6, =gUnknown_02020184
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	ldr r0, =gWindows
	adds r3, r1, r0
	str r3, [r6]
	ldr r4, =gUnknown_02020188
	ldrb r1, [r3, 0x3]
	ldrb r0, [r3, 0x4]
	muls r0, r1
	lsls r0, 6
	strh r0, [r4]
	cmp r2, 0x2
	beq _0800454E
	cmp r2, 0x2
	bgt _08004540
	cmp r2, 0x1
	beq _08004546
	b _08004570
	.pool
_08004540:
	cmp r5, 0x3
	beq _0800455C
	b _08004570
_08004546:
	ldrb r0, [r3]
	bl CopyBgTilemapBufferToVram
	b _08004570
_0800454E:
	ldrb r0, [r3]
	ldr r1, [r3, 0x8]
	ldrh r2, [r4]
	ldrh r3, [r3, 0x6]
	bl LoadBgTiles
	b _08004570
_0800455C:
	ldrb r0, [r3]
	ldr r1, [r3, 0x8]
	ldrh r2, [r4]
	ldrh r3, [r3, 0x6]
	bl LoadBgTiles
	ldr r0, [r6]
	ldrb r0, [r0]
	bl CopyBgTilemapBufferToVram
_08004570:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end CopyWindowToVram8Bit

	thumb_func_start GetNumActiveWindowsOnBg8Bit
@ int GetNumActiveWindowsOnBg8Bit(int bg_id)
GetNumActiveWindowsOnBg8Bit: @ 8004578
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r2, =gWindows
	movs r1, 0x1F
_08004584:
	ldrb r0, [r2]
	cmp r0, r4
	bne _08004590
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
_08004590:
	adds r2, 0xC
	subs r1, 0x1
	cmp r1, 0
	bge _08004584
	adds r0, r3, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetNumActiveWindowsOnBg8Bit

	.align 2, 0 @ Don't pad with nop.
