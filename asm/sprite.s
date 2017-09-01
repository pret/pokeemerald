	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start AffineAnimDelay
@ void AffineAnimDelay(u8 index, struct obj *object)
AffineAnimDelay: @ 8007BD8
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl DecrementAffineAnimDelayCounter
	lsls r0, 24
	cmp r0, 0
	bne _08007C02
	adds r0, r4, 0
	adds r1, r5, 0
	mov r2, sp
	bl GetAffineAnimFrame
	adds r0, r4, 0
	mov r1, sp
	bl ApplyAffineAnimFrameRelativeAndUpdateMatrix
_08007C02:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end AffineAnimDelay

	thumb_func_start AffineAnimCmd_loop
@ void AffineAnimCmd_loop(u8 index, struct obj *object)
AffineAnimCmd_loop: @ 8007C0C
	push {lr}
	adds r3, r1, 0
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =sAffineAnimStates
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x3]
	cmp r0, 0
	beq _08007C34
	adds r0, r2, 0
	adds r1, r3, 0
	bl ContinueAffineAnimLoop
	b _08007C3C
	.pool
_08007C34:
	adds r0, r2, 0
	adds r1, r3, 0
	bl BeginAffineAnimLoop
_08007C3C:
	pop {r0}
	bx r0
	thumb_func_end AffineAnimCmd_loop

	thumb_func_start BeginAffineAnimLoop
@ void BeginAffineAnimLoop(u8 index, struct obj *object)
BeginAffineAnimLoop: @ 8007C40
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =sAffineAnimStates
	lsls r3, r0, 1
	adds r3, r0
	lsls r3, 2
	adds r3, r1
	ldrb r2, [r3]
	ldr r1, [r4, 0x10]
	lsls r2, 2
	adds r2, r1
	ldrb r1, [r3, 0x1]
	ldr r2, [r2]
	lsls r1, 3
	adds r1, r2
	ldrh r1, [r1, 0x2]
	strb r1, [r3, 0x3]
	adds r1, r4, 0
	bl JumpToTopOfRotScalAnimLoop
	adds r0, r4, 0
	bl ContinueAffineAnim
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end BeginAffineAnimLoop

	thumb_func_start ContinueAffineAnimLoop
@ void ContinueAffineAnimLoop(u8 index, struct obj *object)
ContinueAffineAnimLoop: @ 8007C7C
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sAffineAnimStates
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x3]
	subs r2, 0x1
	strb r2, [r1, 0x3]
	adds r1, r4, 0
	bl JumpToTopOfRotScalAnimLoop
	adds r0, r4, 0
	bl ContinueAffineAnim
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ContinueAffineAnimLoop

	thumb_func_start JumpToTopOfRotScalAnimLoop
@ void JumpToTopOfRotScalAnimLoop(u8 index, struct obj *object)
JumpToTopOfRotScalAnimLoop: @ 8007CAC
	push {r4-r7,lr}
	mov r12, r1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =sAffineAnimStates
	lsls r3, r5, 1
	adds r0, r3, r5
	lsls r0, 2
	adds r2, r0, r1
	ldrb r0, [r2, 0x3]
	adds r6, r1, 0
	cmp r0, 0
	beq _08007D0C
	ldrb r0, [r2, 0x1]
	subs r0, 0x1
	strb r0, [r2, 0x1]
	adds r4, r3, 0
	b _08007CDC
	.pool
_08007CD4:
	cmp r2, 0
	beq _08007D00
	subs r0, r2, 0x1
	strb r0, [r3, 0x1]
_08007CDC:
	adds r0, r4, r5
	lsls r0, 2
	adds r3, r0, r6
	ldrb r0, [r3]
	mov r2, r12
	ldr r1, [r2, 0x10]
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r3, 0x1]
	ldr r1, [r0]
	lsls r0, r2, 3
	adds r0, r1
	subs r0, 0x8
	movs r7, 0
	ldrsh r1, [r0, r7]
	ldr r0, =0x00007ffd
	cmp r1, r0
	bne _08007CD4
_08007D00:
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r6
	ldrb r0, [r1, 0x1]
	subs r0, 0x1
	strb r0, [r1, 0x1]
_08007D0C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end JumpToTopOfRotScalAnimLoop

	thumb_func_start AffineAnimCmd_jump
@ void AffineAnimCmd_jump(u8 index, struct obj *object)
AffineAnimCmd_jump: @ 8007D18
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =sAffineAnimStates
	lsls r4, r5, 1
	adds r4, r5
	lsls r4, 2
	adds r4, r0
	ldrb r2, [r4]
	ldr r0, [r1, 0x10]
	lsls r2, 2
	adds r2, r0
	ldrb r0, [r4, 0x1]
	ldr r2, [r2]
	lsls r0, 3
	adds r0, r2
	ldrh r0, [r0, 0x2]
	strb r0, [r4, 0x1]
	mov r6, sp
	adds r0, r5, 0
	mov r2, sp
	bl GetAffineAnimFrame
	adds r0, r5, 0
	mov r1, sp
	bl ApplyAffineAnimFrame
	ldrb r0, [r6, 0x5]
	strb r0, [r4, 0x2]
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AffineAnimCmd_jump

	thumb_func_start AffineAnimCmd_end
@ void AffineAnimCmd_end(u8 index, struct obj *object)
AffineAnimCmd_end: @ 8007D64
	push {lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	movs r3, 0
	str r2, [sp]
	str r3, [sp, 0x4]
	adds r1, 0x3F
	ldrb r2, [r1]
	movs r3, 0x20
	orrs r2, r3
	strb r2, [r1]
	ldr r2, =sAffineAnimStates
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x1]
	subs r2, 0x1
	strb r2, [r1, 0x1]
	mov r1, sp
	bl ApplyAffineAnimFrameRelativeAndUpdateMatrix
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end AffineAnimCmd_end

	thumb_func_start AffineAnimCmd_frame
@ void AffineAnimCmd_frame(u8 index, struct obj *object)
AffineAnimCmd_frame: @ 8007DA0
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	mov r5, sp
	adds r0, r4, 0
	mov r2, sp
	bl GetAffineAnimFrame
	adds r0, r4, 0
	mov r1, sp
	bl ApplyAffineAnimFrame
	ldr r1, =sAffineAnimStates
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r5, 0x5]
	strb r1, [r0, 0x2]
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AffineAnimCmd_frame

	thumb_func_start CopyOamMatrix
@ void CopyOamMatrix(u8 rotscale_entry_index, s16 rotscale_data[])
CopyOamMatrix: @ 8007DD8
	lsls r0, 24
	ldr r2, =gOamMatrices
	lsrs r0, 21
	adds r0, r2
	ldrh r2, [r1]
	strh r2, [r0]
	ldrh r2, [r1, 0x2]
	strh r2, [r0, 0x2]
	ldrh r2, [r1, 0x4]
	strh r2, [r0, 0x4]
	ldrh r1, [r1, 0x6]
	strh r1, [r0, 0x6]
	bx lr
	.pool
	thumb_func_end CopyOamMatrix

	thumb_func_start GetSpriteMatrixNum
@ int GetSpriteMatrixNum(struct obj *obj)
GetSpriteMatrixNum: @ 8007DF8
	push {lr}
	adds r2, r0, 0
	movs r3, 0
	ldrb r0, [r2, 0x1]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08007E12
	ldrb r0, [r2, 0x3]
	lsls r0, 26
	lsrs r3, r0, 27
_08007E12:
	adds r0, r3, 0
	pop {r1}
	bx r1
	thumb_func_end GetSpriteMatrixNum

	thumb_func_start sub_8007E18
@ void sub_8007E18(struct obj *obj, s16 a2, s16 a3)
sub_8007E18: @ 8007E18
	strh r1, [r0, 0x3A]
	strh r2, [r0, 0x3C]
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end sub_8007E18

	thumb_func_start sub_8007E28
@ int sub_8007E28(int a1, int a2, int a3)
sub_8007E28: @ 8007E28
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r5, r2, 0
	subs r0, r1, r3
	cmp r0, 0
	bge _08007E3A
	negs r0, r0
	asrs r4, r0, 9
	b _08007E3E
_08007E3A:
	asrs r0, 9
	negs r4, r0
_08007E3E:
	adds r0, r5, 0
	muls r0, r1
	adds r1, r3, 0
	bl __udivsi3
	adds r0, r4
	subs r0, r5, r0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8007E28

	thumb_func_start obj_update_pos2
@ void obj_update_pos2(struct obj *obj, int a2, int a3)
obj_update_pos2: @ 8007E54
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	ldrb r1, [r5, 0x3]
	lsls r0, r1, 26
	lsrs r7, r0, 27
	movs r0, 0x80
	lsls r0, 4
	mov r9, r0
	cmp r6, r9
	beq _08007EA2
	ldr r2, =gUnknown_082EC6F4
	lsrs r1, 6
	lsls r1, 3
	ldrb r0, [r5, 0x1]
	lsrs r0, 6
	lsls r0, 5
	adds r1, r0
	adds r1, r2
	ldr r0, [r1]
	lsls r4, r0, 8
	lsls r0, 16
	ldr r2, =gOamMatrices
	lsls r1, r7, 3
	adds r1, r2
	movs r2, 0
	ldrsh r1, [r1, r2]
	bl __divsi3
	adds r1, r0, 0
	adds r0, r4, 0
	adds r2, r6, 0
	bl sub_8007E28
	strh r0, [r5, 0x24]
_08007EA2:
	cmp r8, r9
	beq _08007EDA
	ldr r2, =gUnknown_082EC6F4
	ldrb r1, [r5, 0x3]
	lsrs r1, 6
	lsls r1, 3
	ldrb r0, [r5, 0x1]
	lsrs r0, 6
	lsls r0, 5
	adds r1, r0
	adds r2, 0x4
	adds r1, r2
	ldr r0, [r1]
	lsls r4, r0, 8
	lsls r0, 16
	ldr r2, =gOamMatrices
	lsls r1, r7, 3
	adds r1, r2
	movs r2, 0x6
	ldrsh r1, [r1, r2]
	bl __divsi3
	adds r1, r0, 0
	adds r0, r4, 0
	mov r2, r8
	bl sub_8007E28
	strh r0, [r5, 0x26]
_08007EDA:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end obj_update_pos2

	thumb_func_start SetSpriteOamFlipBits
@ void SetSpriteOamFlipBits(struct obj *obj, u8 a2, char a3)
SetSpriteOamFlipBits: @ 8007EF0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldrb r6, [r0, 0x3]
	lsls r3, r6, 26
	lsrs r3, 27
	movs r4, 0x7
	ands r3, r4
	lsls r3, 1
	subs r4, 0x46
	mov r8, r4
	mov r5, r8
	ands r5, r6
	orrs r5, r3
	strb r5, [r0, 0x3]
	lsls r4, r5, 26
	lsrs r4, 27
	movs r6, 0x3F
	adds r6, r0
	mov r12, r6
	ldrb r3, [r6]
	lsls r3, 31
	lsrs r3, 31
	eors r1, r3
	movs r6, 0x1
	ands r1, r6
	lsls r1, 3
	orrs r4, r1
	lsls r4, 1
	mov r3, r8
	ands r3, r5
	orrs r3, r4
	strb r3, [r0, 0x3]
	lsls r4, r3, 26
	lsrs r4, 27
	mov r5, r12
	ldrb r1, [r5]
	lsls r1, 30
	lsrs r1, 31
	eors r2, r1
	ands r2, r6
	lsls r2, 4
	orrs r4, r2
	lsls r4, 1
	mov r6, r8
	ands r3, r6
	orrs r3, r4
	strb r3, [r0, 0x3]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end SetSpriteOamFlipBits

	thumb_func_start AffineAnimStateRestartAnim
@ void AffineAnimStateRestartAnim(u8 index)
AffineAnimStateRestartAnim: @ 8007F64
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sAffineAnimStates
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0
	strb r0, [r1, 0x1]
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x3]
	bx lr
	.pool
	thumb_func_end AffineAnimStateRestartAnim

	thumb_func_start rotscale_reset_full_1
@ void rotscale_reset_full_1(u8 index, u8 a2)
rotscale_reset_full_1: @ 8007F80
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =sAffineAnimStates
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	movs r3, 0
	strb r1, [r2]
	strb r3, [r2, 0x1]
	strb r3, [r2, 0x2]
	strb r3, [r2, 0x3]
	movs r0, 0x80
	lsls r0, 1
	strh r0, [r2, 0x4]
	strh r0, [r2, 0x6]
	strh r3, [r2, 0x8]
	bx lr
	.pool
	thumb_func_end rotscale_reset_full_1

	thumb_func_start rotscale_reset_full_2
@ void rotscale_reset_full_2(u8 index)
rotscale_reset_full_2: @ 8007FA8
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sAffineAnimStates
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	movs r0, 0
	strb r0, [r1]
	strb r0, [r1, 0x1]
	strb r0, [r1, 0x2]
	strb r0, [r1, 0x3]
	movs r2, 0x80
	lsls r2, 1
	strh r2, [r1, 0x4]
	strh r2, [r1, 0x6]
	strh r0, [r1, 0x8]
	bx lr
	.pool
	thumb_func_end rotscale_reset_full_2

	thumb_func_start rotscale_frame_apply_absolute
@ void rotscale_frame_apply_absolute(u8 index, int a2)
rotscale_frame_apply_absolute: @ 8007FD0
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =sAffineAnimStates
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	ldrh r0, [r1]
	strh r0, [r2, 0x4]
	ldrh r0, [r1, 0x2]
	strh r0, [r2, 0x6]
	ldrb r0, [r1, 0x4]
	lsls r0, 8
	strh r0, [r2, 0x8]
	bx lr
	.pool
	thumb_func_end rotscale_frame_apply_absolute

	thumb_func_start DecrementAnimDelayCounter
DecrementAnimDelayCounter: @ 8007FF4
	push {lr}
	adds r3, r0, 0
	adds r3, 0x2C
	ldrb r2, [r3]
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	bne _08008018
	lsls r0, r2, 26
	lsrs r0, 26
	subs r0, 0x1
	movs r1, 0x3F
	ands r0, r1
	movs r1, 0x40
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
_08008018:
	pop {r0}
	bx r0
	thumb_func_end DecrementAnimDelayCounter

	thumb_func_start DecrementAffineAnimDelayCounter
@ u8 DecrementAffineAnimDelayCounter(struct obj *object, u8 index)
DecrementAffineAnimDelayCounter: @ 800801C
	push {lr}
	lsls r1, 24
	lsrs r2, r1, 24
	adds r3, r0, 0
	adds r3, 0x2C
	ldrb r1, [r3]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08008040
	ldr r0, =sAffineAnimStates
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x2]
	subs r0, 0x1
	strb r0, [r1, 0x2]
_08008040:
	ldrb r0, [r3]
	lsrs r0, 7
	pop {r1}
	bx r1
	.pool
	thumb_func_end DecrementAffineAnimDelayCounter

	thumb_func_start ApplyAffineAnimFrameRelativeAndUpdateMatrix
@ void ApplyAffineAnimFrameRelativeAndUpdateMatrix(u8 index, int a2)
ApplyAffineAnimFrameRelativeAndUpdateMatrix: @ 800804C
	push {r4-r6,lr}
	sub sp, 0x10
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =sAffineAnimStates
	lsls r4, r5, 1
	adds r4, r5
	lsls r4, 2
	adds r4, r0
	ldrh r0, [r1]
	ldrh r2, [r4, 0x4]
	adds r0, r2
	strh r0, [r4, 0x4]
	ldrh r0, [r1, 0x2]
	ldrh r2, [r4, 0x6]
	adds r0, r2
	strh r0, [r4, 0x6]
	ldrb r0, [r1, 0x4]
	lsls r0, 8
	ldrh r1, [r4, 0x8]
	adds r0, r1
	ldr r2, =0xffffff00
	adds r1, r2, 0
	ands r0, r1
	strh r0, [r4, 0x8]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	bl divide_0x10000_by
	lsls r0, 16
	lsrs r0, 16
	ldr r6, =0xffff0000
	ldr r1, [sp]
	ands r1, r6
	orrs r1, r0
	str r1, [sp]
	movs r2, 0x6
	ldrsh r0, [r4, r2]
	bl divide_0x10000_by
	lsls r0, 16
	ldr r2, =0x0000ffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrh r1, [r4, 0x8]
	ldr r0, [sp, 0x4]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, 0x4]
	add r4, sp, 0x8
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ObjAffineSet
	adds r0, r5, 0
	adds r1, r4, 0
	bl CopyOamMatrix
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ApplyAffineAnimFrameRelativeAndUpdateMatrix

	thumb_func_start divide_0x10000_by
@ int divide_0x10000_by(int n)
divide_0x10000_by: @ 80080E4
	push {lr}
	adds r1, r0, 0
	movs r0, 0x80
	lsls r0, 9
	lsls r1, 16
	asrs r1, 16
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end divide_0x10000_by

	thumb_func_start GetAffineAnimFrame
@ void GetAffineAnimFrame(u8 index, struct obj *obj, rotscale_frame *a3)
GetAffineAnimFrame: @ 80080FC
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =sAffineAnimStates
	lsls r4, r0, 1
	adds r4, r0
	lsls r4, 2
	adds r4, r3
	ldrb r3, [r4]
	ldr r0, [r1, 0x10]
	lsls r3, 2
	adds r3, r0
	ldrb r0, [r4, 0x1]
	ldr r3, [r3]
	lsls r0, 3
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r2]
	ldrb r3, [r4]
	ldr r0, [r1, 0x10]
	lsls r3, 2
	adds r3, r0
	ldrb r0, [r4, 0x1]
	ldr r3, [r3]
	lsls r0, 3
	adds r0, r3
	ldrh r0, [r0, 0x2]
	strh r0, [r2, 0x2]
	ldrb r3, [r4]
	ldr r0, [r1, 0x10]
	lsls r3, 2
	adds r3, r0
	ldrb r0, [r4, 0x1]
	ldr r3, [r3]
	lsls r0, 3
	adds r0, r3
	ldrb r0, [r0, 0x4]
	strb r0, [r2, 0x4]
	ldrb r3, [r4]
	ldr r0, [r1, 0x10]
	lsls r3, 2
	adds r3, r0
	ldrb r0, [r4, 0x1]
	ldr r1, [r3]
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x5]
	strb r0, [r2, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetAffineAnimFrame

	thumb_func_start ApplyAffineAnimFrame
ApplyAffineAnimFrame: @ 8008168
	push {r4,lr}
	sub sp, 0x8
	adds r2, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	movs r1, 0
	str r0, [sp]
	str r1, [sp, 0x4]
	ldrb r0, [r2, 0x5]
	cmp r0, 0
	beq _0800818E
	subs r0, 0x1
	strb r0, [r2, 0x5]
	adds r0, r4, 0
	adds r1, r2, 0
	bl ApplyAffineAnimFrameRelativeAndUpdateMatrix
	b _0800819E
_0800818E:
	adds r0, r4, 0
	adds r1, r2, 0
	bl rotscale_frame_apply_absolute
	adds r0, r4, 0
	mov r1, sp
	bl ApplyAffineAnimFrameRelativeAndUpdateMatrix
_0800819E:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ApplyAffineAnimFrame

	thumb_func_start StartObjectImageAnim
@ void StartObjectImageAnim(struct obj *object, u8 whichAnim)
StartObjectImageAnim: @ 80081A8
	adds r2, r0, 0
	adds r2, 0x2A
	strb r1, [r2]
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	movs r2, 0x11
	negs r2, r2
	ands r1, r2
	strb r1, [r0]
	bx lr
	thumb_func_end StartObjectImageAnim

	thumb_func_start StartObjectImageAnimIfDifferent
@ void StartObjectImageAnimIfDifferent(struct obj *object, u8 whichAnim)
StartObjectImageAnimIfDifferent: @ 80081C0
	push {lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, 0x2A
	ldrb r0, [r0]
	cmp r0, r1
	beq _080081D6
	adds r0, r2, 0
	bl StartObjectImageAnim
_080081D6:
	pop {r0}
	bx r0
	thumb_func_end StartObjectImageAnimIfDifferent

	thumb_func_start SeekObjectImageAnim
@ void SeekObjectImageAnim(struct obj *object, u8 cmdIndex)
SeekObjectImageAnim: @ 80081DC
	push {r4-r7,lr}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r4, r3, 0
	adds r4, 0x2C
	ldrb r0, [r4]
	lsls r0, 25
	lsrs r6, r0, 31
	subs r1, 0x1
	adds r0, r3, 0
	adds r0, 0x2B
	strb r1, [r0]
	ldrb r1, [r4]
	movs r7, 0x40
	negs r7, r7
	adds r0, r7, 0
	ands r0, r1
	strb r0, [r4]
	adds r2, r3, 0
	adds r2, 0x3F
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r4]
	movs r5, 0x41
	negs r5, r5
	adds r0, r5, 0
	ands r0, r1
	strb r0, [r4]
	adds r0, r3, 0
	bl ContinueAnim
	ldrb r2, [r4]
	movs r0, 0x3F
	ands r0, r2
	cmp r0, 0
	beq _08008244
	lsls r0, r2, 26
	lsrs r0, 26
	adds r0, 0x1
	movs r1, 0x3F
	ands r0, r1
	adds r1, r7, 0
	ands r1, r2
	orrs r1, r0
	strb r1, [r4]
_08008244:
	lsls r2, r6, 6
	ldrb r1, [r4]
	adds r0, r5, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end SeekObjectImageAnim

	thumb_func_start StartObjectRotScalAnim
@ void StartObjectRotScalAnim(struct obj *object, u8 whichAnim)
StartObjectRotScalAnim: @ 8008258
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	bl GetSpriteMatrixNum
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl rotscale_reset_full_1
	adds r5, 0x3F
	ldrb r0, [r5]
	movs r1, 0x8
	orrs r0, r1
	movs r1, 0x21
	negs r1, r1
	ands r0, r1
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end StartObjectRotScalAnim

	thumb_func_start StartObjectRotScalAnimIfDifferent
@ void StartObjectRotScalAnimIfDifferent(struct obj *object, u8 whichAnim)
StartObjectRotScalAnimIfDifferent: @ 8008284
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	bl GetSpriteMatrixNum
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sAffineAnimStates
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1]
	cmp r0, r4
	beq _080082AC
	adds r0, r5, 0
	adds r1, r4, 0
	bl StartObjectRotScalAnim
_080082AC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end StartObjectRotScalAnimIfDifferent

	thumb_func_start sub_80082B8
sub_80082B8: @ 80082B8
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	bl GetSpriteMatrixNum
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sAffineAnimStates
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	strb r4, [r1]
	adds r5, 0x3F
	ldrb r0, [r5]
	movs r1, 0x8
	orrs r0, r1
	movs r1, 0x21
	negs r1, r1
	ands r0, r1
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80082B8

	thumb_func_start sub_80082F0
sub_80082F0: @ 80082F0
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	bl GetSpriteMatrixNum
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sAffineAnimStates
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1]
	cmp r0, r4
	beq _08008318
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_80082B8
_08008318:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80082F0

	thumb_func_start SetSpriteSheetFrameTileNum
SetSpriteSheetFrameTileNum: @ 8008324
	push {lr}
	adds r3, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _08008370
	adds r0, r3, 0
	adds r0, 0x2A
	ldrb r1, [r0]
	ldr r0, [r3, 0x8]
	lsls r1, 2
	adds r1, r0
	adds r0, r3, 0
	adds r0, 0x2B
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldrh r2, [r0]
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _08008358
	movs r2, 0
_08008358:
	adds r0, r3, 0
	adds r0, 0x40
	ldrh r1, [r0]
	adds r1, r2
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
_08008370:
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetSpriteSheetFrameTileNum

	thumb_func_start ResetAffineAnimData
@ void ResetAffineAnimData()
ResetAffineAnimData: @ 800837C
	push {r4,lr}
	ldr r1, =gAffineAnimsDisabled
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gUnknown_03003018
	movs r0, 0
	str r0, [r1]
	bl ResetOamMatrices
	movs r4, 0
_08008390:
	adds r0, r4, 0
	bl rotscale_reset_full_2
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1F
	bls _08008390
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetAffineAnimData

	thumb_func_start rotscale_alloc_entry
@ u8 rotscale_alloc_entry()
rotscale_alloc_entry: @ 80083B0
	push {r4,lr}
	movs r2, 0
	movs r1, 0x1
	ldr r0, =gUnknown_03003018
	ldr r4, [r0]
	adds r3, r0, 0
_080083BC:
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _080083D4
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	adds r0, r2, 0
	b _080083E2
	.pool
_080083D4:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 1
	cmp r2, 0x1F
	bls _080083BC
	movs r0, 0xFF
_080083E2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end rotscale_alloc_entry

	thumb_func_start FreeOamMatrix
@ void FreeOamMatrix(u8 rotscale_index)
FreeOamMatrix: @ 80083E8
	push {lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r2, r0, 24
	movs r0, 0
	movs r1, 0x1
	ldr r3, =gUnknown_03003018
	cmp r0, r2
	bcs _08008406
_080083FA:
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 1
	cmp r0, r2
	bcc _080083FA
_08008406:
	ldr r0, [r3]
	bics r0, r1
	str r0, [r3]
	movs r1, 0x80
	lsls r1, 1
	str r1, [sp]
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0
	bl SetOamMatrix
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeOamMatrix

	thumb_func_start InitSpriteAffineAnim
@ void InitSpriteAffineAnim(struct obj *obj)
InitSpriteAffineAnim: @ 8008428
	push {r4,r5,lr}
	adds r4, r0, 0
	bl rotscale_alloc_entry
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0xFF
	beq _08008470
	ldrb r3, [r4, 0x1]
	lsrs r1, r3, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	lsls r3, 30
	lsrs r3, 30
	adds r0, r4, 0
	bl CalcCenterToCornerVec
	movs r0, 0x1F
	adds r1, r5, 0
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r2, r4, 0
	adds r2, 0x3F
	ldrb r0, [r2]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2]
	adds r0, r5, 0
	bl rotscale_reset_full_2
_08008470:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end InitSpriteAffineAnim

	thumb_func_start sub_8008478
sub_8008478: @ 8008478
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x10
	adds r6, r0, 0
	adds r0, r1, 0
	adds r4, r2, 0
	adds r5, r3, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r0, 16
	asrs r0, 16
	bl divide_0x10000_by
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0xffff0000
	mov r8, r1
	ldr r1, [sp]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	bl divide_0x10000_by
	lsls r0, 16
	ldr r2, =0x0000ffff
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r0, [sp, 0x4]
	mov r1, r8
	ands r0, r1
	orrs r0, r5
	str r0, [sp, 0x4]
	add r4, sp, 0x8
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ObjAffineSet
	adds r0, r6, 0
	adds r1, r4, 0
	bl CopyOamMatrix
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8008478

	thumb_func_start LoadObjectPic
@ u16 LoadObjectPic(struct obj_tiles *pic)
LoadObjectPic: @ 80084F8
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x4]
	lsrs r0, 5
	bl AllocSpriteTiles
	lsls r4, r0, 16
	asrs r6, r4, 16
	cmp r6, 0
	blt _08008534
	ldrh r0, [r5, 0x6]
	lsrs r4, 16
	ldrh r2, [r5, 0x4]
	lsrs r2, 5
	adds r1, r4, 0
	bl CreateSpriteAtTileRange
	ldr r0, [r5]
	lsls r1, r6, 5
	ldr r2, =0x06010000
	adds r1, r2
	ldrh r2, [r5, 0x4]
	lsrs r2, 1
	bl CpuSet
	adds r0, r4, 0
	b _08008536
	.pool
_08008534:
	movs r0, 0
_08008536:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end LoadObjectPic

	thumb_func_start LoadObjectPics
@ void LoadObjectPics(struct obj_tiles *pics)
LoadObjectPics: @ 800853C
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
	ldr r0, [r5]
	cmp r0, 0
	beq _08008560
_08008548:
	lsls r0, r4, 3
	adds r0, r5, r0
	bl LoadObjectPic
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 3
	adds r0, r5
	ldr r0, [r0]
	cmp r0, 0
	bne _08008548
_08008560:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end LoadObjectPics

	thumb_func_start FreeSpriteTilesByTag
@ void FreeSpriteTilesByTag(u16 tag)
FreeSpriteTilesByTag: @ 8008568
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r0, 16
	bl IndexOfObjectTilesTag
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFF
	beq _080085C6
	ldr r0, =gUnknown_03000A70
	lsls r1, r4, 2
	adds r2, r1, r0
	adds r0, 0x2
	adds r1, r0
	ldrh r0, [r1]
	ldrh r3, [r2]
	adds r0, r3, r0
	ldr r1, =gUnknown_030009F0
	mov r8, r1
	lsls r5, r4, 1
	cmp r3, r0
	bge _080085BE
	ldr r1, =gSpriteTileAllocBitmap
	mov r12, r1
	movs r6, 0x7
	movs r7, 0x1
	adds r4, r0, 0
_080085A2:
	lsrs r2, r3, 3
	add r2, r12
	adds r0, r3, 0
	ands r0, r6
	adds r1, r7, 0
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r4
	blt _080085A2
_080085BE:
	mov r0, r8
	adds r1, r5, r0
	ldr r0, =0x0000ffff
	strh r0, [r1]
_080085C6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeSpriteTilesByTag

	thumb_func_start FreeSpriteTileRanges
@ void FreeSpriteTileRanges()
FreeSpriteTileRanges: @ 80085E0
	push {r4-r7,lr}
	movs r2, 0
	ldr r7, =gUnknown_030009F0
	ldr r0, =0x0000ffff
	adds r6, r0, 0
	ldr r4, =gUnknown_03000A70
	movs r3, 0
	adds r5, r4, 0x2
_080085F0:
	lsls r1, r2, 1
	adds r1, r7
	ldrh r0, [r1]
	orrs r0, r6
	strh r0, [r1]
	lsls r1, r2, 2
	adds r0, r1, r4
	strh r3, [r0]
	adds r1, r5
	strh r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3F
	bls _080085F0
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeSpriteTileRanges

	thumb_func_start GetSpriteTileStartByTag
@ u16 GetSpriteTileStartByTag(u16 tag)
GetSpriteTileStartByTag: @ 8008620
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl IndexOfObjectTilesTag
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _08008640
	ldr r0, =gUnknown_03000A70
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1]
	b _08008642
	.pool
_08008640:
	ldr r0, =0x0000ffff
_08008642:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetSpriteTileStartByTag

	thumb_func_start IndexOfObjectTilesTag
@ u8 IndexOfObjectTilesTag(u16 tag)
IndexOfObjectTilesTag: @ 800864C
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0
	ldr r3, =gUnknown_030009F0
_08008656:
	lsls r0, r1, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _08008668
	adds r0, r1, 0
	b _08008674
	.pool
_08008668:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3F
	bls _08008656
	movs r0, 0xFF
_08008674:
	pop {r1}
	bx r1
	thumb_func_end IndexOfObjectTilesTag

	thumb_func_start GetTagByObjectTileRangeStart
@ u16 GetTagByObjectTileRangeStart(u16 rangeStart)
GetTagByObjectTileRangeStart: @ 8008678
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r6, =gUnknown_030009F0
	ldr r5, =0x0000ffff
	ldr r4, =gUnknown_03000A70
_08008686:
	lsls r0, r2, 1
	adds r1, r0, r6
	ldrh r0, [r1]
	cmp r0, r5
	beq _080086AC
	lsls r0, r2, 2
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, r3
	bne _080086AC
	ldrh r0, [r1]
	b _080086B8
	.pool
_080086AC:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3F
	bls _08008686
	ldr r0, =0x0000ffff
_080086B8:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetTagByObjectTileRangeStart

	thumb_func_start CreateSpriteAtTileRange
@ void CreateSpriteAtTileRange(u16 tag, u16 start, u16 count)
CreateSpriteAtTileRange: @ 80086C4
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	ldr r0, =0x0000ffff
	bl IndexOfObjectTilesTag
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_030009F0
	lsls r1, r0, 1
	adds r1, r2
	strh r4, [r1]
	ldr r1, =gUnknown_03000A70
	lsls r0, 2
	adds r2, r0, r1
	strh r5, [r2]
	adds r1, 0x2
	adds r0, r1
	strh r6, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateSpriteAtTileRange

	thumb_func_start ResetObjectPaletteAllocator
@ void ResetObjectPaletteAllocator()
ResetObjectPaletteAllocator: @ 800870C
	push {r4,lr}
	ldr r1, =gUnknown_0300301C
	movs r0, 0
	strb r0, [r1]
	movs r2, 0
	ldr r4, =gUnknown_03000CF0
	ldr r0, =0x0000ffff
	adds r3, r0, 0
_0800871C:
	lsls r0, r2, 1
	adds r0, r4
	ldrh r1, [r0]
	orrs r1, r3
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _0800871C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetObjectPaletteAllocator

	thumb_func_start LoadTaggedObjectPalette
@ u8 LoadTaggedObjectPalette(struct TaggedObjectPalette *palette)
LoadTaggedObjectPalette: @ 8008744
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFF
	beq _0800875A
	adds r0, r4, 0
	b _0800878A
_0800875A:
	ldr r0, =0x0000ffff
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFF
	beq _08008788
	ldr r1, =gUnknown_03000CF0
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r5, 0x4]
	strh r1, [r0]
	ldr r0, [r5]
	lsls r1, r4, 4
	bl LoadObjectPalette
	adds r0, r4, 0
	b _0800878A
	.pool
_08008788:
	movs r0, 0xFF
_0800878A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end LoadTaggedObjectPalette

	thumb_func_start LoadTaggedObjectPalettes
@ void LoadTaggedObjectPalettes(struct TaggedObjectPalette *palettes)
LoadTaggedObjectPalettes: @ 8008790
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
	b _0800879E
_08008798:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_0800879E:
	lsls r0, r4, 3
	adds r1, r0, r5
	ldr r0, [r1]
	cmp r0, 0
	beq _080087B6
	adds r0, r1, 0
	bl LoadTaggedObjectPalette
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08008798
_080087B6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end LoadTaggedObjectPalettes

	thumb_func_start LoadObjectPalette
@ void LoadObjectPalette(void *src, u16 destOffset)
LoadObjectPalette: @ 80087BC
	push {lr}
	lsls r1, 16
	movs r2, 0x80
	lsls r2, 17
	adds r1, r2
	lsrs r1, 16
	movs r2, 0x20
	bl LoadPalette
	pop {r0}
	bx r0
	thumb_func_end LoadObjectPalette

	thumb_func_start AllocObjectPalette
@ u8 AllocObjectPalette(u16 tag)
AllocObjectPalette: @ 80087D4
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080087FC
	ldr r1, =gUnknown_03000CF0
	lsls r0, r2, 1
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	b _080087FE
	.pool
_080087FC:
	movs r0, 0xFF
_080087FE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end AllocObjectPalette

	thumb_func_start IndexOfSpritePaletteTag
@ u8 IndexOfSpritePaletteTag(u16 tag)
IndexOfSpritePaletteTag: @ 8008804
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gUnknown_0300301C
	ldrb r1, [r0]
	cmp r1, 0xF
	bhi _08008836
	ldr r3, =gUnknown_03000CF0
_08008814:
	lsls r0, r1, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _0800882C
	adds r0, r1, 0
	b _08008838
	.pool
_0800882C:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _08008814
_08008836:
	movs r0, 0xFF
_08008838:
	pop {r1}
	bx r1
	thumb_func_end IndexOfSpritePaletteTag

	thumb_func_start GetObjectPaletteTagBySlot
@ u16 GetObjectPaletteTagBySlot(u8 paletteSlot)
GetObjectPaletteTagBySlot: @ 800883C
	lsls r0, 24
	ldr r1, =gUnknown_03000CF0
	lsrs r0, 23
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end GetObjectPaletteTagBySlot

	thumb_func_start FreeSpritePaletteByTag
@ void FreeSpritePaletteByTag(int tag)
FreeSpritePaletteByTag: @ 800884C
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _08008868
	ldr r0, =gUnknown_03000CF0
	lsls r1, 1
	adds r1, r0
	ldr r0, =0x0000ffff
	strh r0, [r1]
_08008868:
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeSpritePaletteByTag

	thumb_func_start SetSpriteOamTables_NoPriorityFromTable
@ void SetSpriteOamTables_NoPriorityFromTable(struct obj *object, u32 spriteOamTables)
SetSpriteOamTables_NoPriorityFromTable: @ 8008874
	str r1, [r0, 0x18]
	adds r0, 0x42
	movs r1, 0x40
	strb r1, [r0]
	bx lr
	thumb_func_end SetSpriteOamTables_NoPriorityFromTable

	thumb_func_start AddSpriteToOamBuffer
@ u8 AddSpriteToOamBuffer(struct obj *obj, u8 *spriteIndex)
AddSpriteToOamBuffer: @ 8008880
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	ldr r1, =gOamLimit
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _08008898
	movs r0, 0x1
	b _080088E0
	.pool
_08008898:
	ldr r0, [r4, 0x18]
	cmp r0, 0
	beq _080088AC
	adds r0, r4, 0
	adds r0, 0x42
	ldrb r1, [r0]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	bne _080088CC
_080088AC:
	ldr r0, =gMain
	ldrb r2, [r3]
	lsls r2, 3
	adds r0, 0x38
	adds r2, r0
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	movs r0, 0
	b _080088E0
	.pool
_080088CC:
	ldrb r1, [r3]
	lsls r1, 3
	ldr r0, =gUnknown_030022F8
	adds r1, r0
	adds r0, r4, 0
	adds r2, r3, 0
	bl AddSubspritesToOamBuffer
	lsls r0, 24
	lsrs r0, 24
_080088E0:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddSpriteToOamBuffer

	thumb_func_start AddSubspritesToOamBuffer
@ u8 AddSubspritesToOamBuffer(struct obj *object, struct sprite *sprite, u8 *spriteIndex)
AddSubspritesToOamBuffer: @ 80088EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r3, r0, 0
	str r1, [sp]
	mov r8, r2
	ldr r0, =gOamLimit
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	bcc _08008910
_08008908:
	movs r0, 0x1
	b _08008AE6
	.pool
_08008910:
	adds r0, r3, 0
	adds r0, 0x42
	ldrb r1, [r0]
	lsls r1, 26
	lsrs r1, 23
	ldr r2, [r3, 0x18]
	adds r7, r2, r1
	mov r12, r3
	str r0, [sp, 0x18]
	cmp r7, 0
	beq _0800892C
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bne _08008942
_0800892C:
	mov r2, r12
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [sp]
	str r0, [r2]
	str r1, [r2, 0x4]
	mov r1, r8
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08008AE4
_08008942:
	mov r2, r12
	ldrh r0, [r2, 0x4]
	lsls r0, 22
	lsrs r0, 22
	str r0, [sp, 0x4]
	ldrb r0, [r7]
	str r0, [sp, 0xC]
	ldrb r0, [r2, 0x3]
	lsls r0, 26
	lsrs r0, 27
	asrs r1, r0, 3
	str r1, [sp, 0x10]
	movs r1, 0x1
	ldr r2, [sp, 0x10]
	ands r2, r1
	str r2, [sp, 0x10]
	asrs r0, 4
	mov r10, r0
	ands r0, r1
	mov r10, r0
	mov r1, r12
	ldrh r0, [r1, 0x2]
	lsls r0, 23
	lsrs r0, 23
	adds r1, 0x28
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	subs r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	mov r1, r12
	ldrb r0, [r1]
	adds r1, 0x29
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	subs r0, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	movs r0, 0
	mov r9, r0
	ldr r1, [sp, 0xC]
	cmp r9, r1
	bcc _080089A0
	b _08008AE4
_080089A0:
	lsls r0, r2, 16
	asrs r0, 16
	str r0, [sp, 0x14]
_080089A6:
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, =gOamLimit
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08008908
	ldr r0, [r7, 0x4]
	mov r2, r9
	lsls r6, r2, 2
	adds r2, r6, r0
	movs r0, 0
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, [sp, 0x10]
	cmp r0, 0
	beq _080089FC
	ldr r0, [r2]
	lsls r1, r0, 12
	lsrs r1, 30
	lsls r1, 2
	lsls r0, 14
	lsrs r0, 30
	lsls r0, 4
	adds r1, r0
	ldr r0, =gUnknown_082EC754
	adds r1, r0
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, r4, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	mvns r0, r4
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080089FC:
	mov r1, r10
	cmp r1, 0
	beq _08008A2E
	ldr r0, [r2]
	lsls r1, r0, 12
	lsrs r1, 30
	lsls r1, 2
	lsls r0, 14
	lsrs r0, 30
	lsls r0, 4
	adds r1, r0
	ldr r2, =gUnknown_082EC754
	adds r1, r2
	ldrb r1, [r1, 0x1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, r5, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	mvns r0, r5
	adds r0, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_08008A2E:
	mov r1, r9
	lsls r0, r1, 3
	ldr r2, [sp]
	adds r3, r0, r2
	mov r2, r12
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [r3]
	str r1, [r3, 0x4]
	ldr r0, [r7, 0x4]
	adds r0, r6, r0
	ldr r1, [r0]
	lsls r1, 14
	lsrs r1, 30
	lsls r1, 6
	ldrb r2, [r3, 0x1]
	movs r0, 0x3F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x1]
	ldr r0, [r7, 0x4]
	adds r0, r6, r0
	ldr r1, [r0]
	lsls r1, 12
	lsrs r1, 30
	lsls r1, 6
	ldrb r2, [r3, 0x3]
	movs r0, 0x3F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x3]
	lsls r1, r4, 16
	asrs r1, 16
	ldr r0, [sp, 0x14]
	adds r1, r0, r1
	ldr r2, =0x000001ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x2]
	ldr r0, =0xfffffe00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x2]
	ldr r1, [sp, 0x8]
	adds r0, r1, r5
	strb r0, [r3]
	ldr r0, [r7, 0x4]
	adds r0, r6, r0
	ldr r1, [r0]
	lsls r1, 2
	lsrs r1, 22
	ldr r2, [sp, 0x4]
	adds r1, r2, r1
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldr r0, [sp, 0x18]
	ldrb r1, [r0]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x80
	beq _08008ACA
	ldr r0, [r7, 0x4]
	adds r0, r6, r0
	ldr r1, [r0]
	lsrs r1, 30
	lsls r1, 2
	ldrb r2, [r3, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x5]
_08008ACA:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r1, r8
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r2, [sp, 0xC]
	cmp r9, r2
	bcs _08008AE4
	b _080089A6
_08008AE4:
	movs r0, 0
_08008AE6:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddSubspritesToOamBuffer

	.align 2, 0 @ Don't pad with nop.
