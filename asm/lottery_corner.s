	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ResetLotteryCorner
ResetLotteryCorner: @ 8177558
	push {r4,lr}
	bl Random
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl Random
	lsls r0, 16
	orrs r0, r4
	bl sub_8177814
	ldr r0, =0x00004045
	movs r1, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetLotteryCorner

	thumb_func_start sub_8177584
sub_8177584: @ 8177584
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl Random
	lsls r0, 16
	lsrs r1, r0, 16
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _081775B4
	ldr r5, =0x41c64e6d
	ldr r3, =0x00003039
	adds r2, r0, 0
_081775A4:
	adds r0, r1, 0
	muls r0, r5
	adds r1, r0, r3
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r2
	bne _081775A4
_081775B4:
	adds r0, r1, 0
	bl sub_8177814
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8177584

	thumb_func_start sub_81775CC
sub_81775CC: @ 81775CC
	push {lr}
	bl sub_817783C
	ldr r1, =gScriptResult
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81775CC

	thumb_func_start sub_81775E0
sub_81775E0: @ 81775E0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0
	strh r0, [r1]
	movs r0, 0
	str r0, [sp, 0x4]
	movs r1, 0
	str r1, [sp]
	movs r7, 0
_081775FC:
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _08177658
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _0817764E
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	adds r1, r0, 0
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	lsls r1, 16
	lsrs r1, 16
	bl sub_817778C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSpecialVar_0x8004
	ldrh r2, [r1]
	cmp r0, r2
	bls _0817764E
	cmp r0, 0x1
	bls _0817764E
	subs r0, 0x1
	strh r0, [r1]
	movs r0, 0xE
	str r0, [sp]
	str r7, [sp, 0x4]
_0817764E:
	adds r0, r7, 0x1
	lsls r0, 16
	lsrs r7, r0, 16
	cmp r7, 0x5
	bls _081775FC
_08177658:
	movs r7, 0
	ldr r1, =gPokemonStoragePtr
	mov r9, r1
_0817765E:
	movs r6, 0
	adds r2, r7, 0x1
	mov r10, r2
	lsls r0, r7, 2
	adds r0, r7
	mov r8, r0
_0817766A:
	mov r1, r8
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	adds r5, r0, 0x4
	mov r2, r9
	ldr r0, [r2]
	adds r0, r5
	lsls r1, r6, 2
	adds r1, r6
	lsls r4, r1, 4
	adds r0, r4
	movs r1, 0xB
	bl pokemon_getattr_encrypted
	cmp r0, 0
	beq _081776D2
	mov r1, r9
	ldr r0, [r1]
	adds r0, r5
	adds r0, r4
	movs r1, 0x2D
	bl pokemon_getattr_encrypted
	cmp r0, 0
	bne _081776D2
	mov r2, r9
	ldr r0, [r2]
	adds r0, r5
	adds r0, r4
	movs r1, 0x1
	bl pokemon_getattr_encrypted
	adds r1, r0, 0
	ldr r0, =gScriptResult
	ldrh r0, [r0]
	lsls r1, 16
	lsrs r1, 16
	bl sub_817778C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSpecialVar_0x8004
	ldrh r2, [r1]
	cmp r0, r2
	bls _081776D2
	cmp r0, 0x1
	bls _081776D2
	subs r0, 0x1
	strh r0, [r1]
	str r7, [sp]
	str r6, [sp, 0x4]
_081776D2:
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, 0x1D
	bls _0817766A
	mov r1, r10
	lsls r0, r1, 16
	lsrs r7, r0, 16
	cmp r7, 0xD
	bls _0817765E
	ldr r3, =gSpecialVar_0x8004
	ldrh r0, [r3]
	cmp r0, 0
	beq _0817776E
	ldr r2, =gSpecialVar_0x8005
	ldr r1, =gUnknown_085E7080
	subs r0, 0x1
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r2, [sp]
	cmp r2, 0xE
	bne _0817773C
	ldr r1, =gSpecialVar_0x8006
	movs r0, 0
	strh r0, [r1]
	movs r0, 0x64
	ldr r1, [sp, 0x4]
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r2, =gStringVar1
	movs r1, 0x2
	bl GetMonData
	b _08177768
	.pool
_0817773C:
	ldr r1, =gSpecialVar_0x8006
	movs r0, 0x1
	strh r0, [r1]
	ldr r2, =gPokemonStoragePtr
	ldr r1, [sp]
	lsls r0, r1, 2
	adds r0, r1
	lsls r1, r0, 4
	subs r1, r0
	lsls r1, 5
	adds r1, 0x4
	ldr r0, [r2]
	adds r0, r1
	ldr r2, [sp, 0x4]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 4
	adds r0, r1
	ldr r2, =gStringVar1
	movs r1, 0x2
	bl pokemon_getattr_encrypted
_08177768:
	ldr r0, =gStringVar1
	bl StringGetEnd10
_0817776E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81775E0

	thumb_func_start sub_817778C
sub_817778C: @ 817778C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 16
	lsrs r5, r1, 16
	movs r0, 0
	mov r8, r0
	movs r7, 0
	ldr r1, =gUnknown_0203BCEC
	mov r10, r1
	ldr r0, =gUnknown_0203BCEE
	mov r9, r0
_081777AC:
	adds r0, r6, 0
	movs r1, 0xA
	bl __umodsi3
	adds r4, r0, 0
	mov r1, r10
	strh r4, [r1]
	adds r0, r5, 0
	movs r1, 0xA
	bl __umodsi3
	mov r1, r9
	strh r0, [r1]
	lsls r4, 16
	lsls r0, 16
	cmp r4, r0
	bne _081777FA
	adds r0, r6, 0
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 16
	lsrs r6, r0, 16
	adds r0, r5, 0
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 16
	lsrs r5, r0, 16
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x4
	bls _081777AC
_081777FA:
	mov r0, r8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817778C

	thumb_func_start sub_8177814
sub_8177814: @ 8177814
	push {r4,lr}
	adds r1, r0, 0
	lsrs r4, r1, 16
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =0x0000404b
	bl VarSet
	ldr r0, =0x0000404c
	adds r1, r4, 0
	bl VarSet
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8177814

	thumb_func_start sub_817783C
sub_817783C: @ 817783C
	push {r4,lr}
	ldr r0, =0x0000404b
	bl VarGet
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =0x0000404c
	bl VarGet
	lsls r0, 16
	orrs r0, r4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817783C

	thumb_func_start sub_8177864
sub_8177864: @ 8177864
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl sub_8177814
	pop {r0}
	bx r0
	thumb_func_end sub_8177864

	.align 2, 0 @ Don't pad with nop.
