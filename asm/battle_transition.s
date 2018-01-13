	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	


	thumb_func_start Phase2Task_Rayquaza
Phase2Task_Rayquaza: @ 814927C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =sPhase2_Rayquaza_Funcs
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814928E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814928E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Phase2Task_Rayquaza

	thumb_func_start sub_81492B4
sub_81492B4: @ 81492B4
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	ldr r1, =0x00009a08
	movs r0, 0x8
	bl SetGpuReg
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	mov r0, sp
	bl CpuSet
	ldr r0, =gUnknown_085BF6A0
	ldr r1, [sp, 0x8]
	movs r2, 0x80
	lsls r2, 5
	bl CpuSet
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x20]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldr r0, =gUnknown_085BF4A0+0xA0
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r2, 0
	ldr r3, =gUnknown_02038C28
	movs r6, 0
	movs r0, 0xF0
	lsls r0, 3
	adds r5, r3, r0
	movs r4, 0x80
	lsls r4, 1
_08149316:
	lsls r1, r2, 1
	adds r0, r1, r3
	strh r6, [r0]
	adds r1, r5
	strh r4, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x9F
	bls _08149316
	ldr r0, =sub_8149508
	bl SetVBlankCallback
	movs r0, 0
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81492B4

	thumb_func_start sub_8149358
sub_8149358: @ 8149358
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	add r1, sp, 0x4
	mov r0, sp
	bl sub_8149F58
	ldr r0, =gUnknown_085C6BE0
	ldr r1, [sp]
	movs r2, 0x80
	lsls r2, 4
	bl CpuSet
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149358

	thumb_func_start sub_8149388
sub_8149388: @ 8149388
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0xA]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081493B4
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _081493A0
	adds r0, 0x3
_081493A0:
	lsls r0, 14
	lsrs r0, 16
	adds r0, 0x5
	lsls r0, 5
	ldr r1, =gUnknown_085BF4A0
	adds r0, r1
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
_081493B4:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x28
	ble _081493CC
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	strh r0, [r4, 0xA]
_081493CC:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149388

	thumb_func_start sub_81493D8
sub_81493D8: @ 81493D8
	push {lr}
	sub sp, 0x4
	adds r1, r0, 0
	ldrh r0, [r1, 0xA]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r1, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _08149402
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	strh r2, [r1, 0xA]
	ldr r0, =0xffff8000
	str r2, [sp]
	movs r1, 0x2
	movs r3, 0x10
	bl BeginNormalPaletteFade
_08149402:
	movs r0, 0
	add sp, 0x4
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81493D8

	thumb_func_start sub_8149410
sub_8149410: @ 8149410
	push {lr}
	adds r2, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0814942E
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	movs r0, 0x1
	strh r0, [r1, 0x20]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
_0814942E:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149410

	thumb_func_start sub_814943C
sub_814943C: @ 814943C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x00007fff
	movs r1, 0x8
	movs r2, 0
	bl BlendPalettes
	ldr r0, =0xffff8000
	movs r1, 0
	movs r2, 0
	bl BlendPalettes
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814943C

	thumb_func_start sub_814946C
sub_814946C: @ 814946C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r5, [r4, r0]
	adds r0, r5, 0
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _0814949A
	adds r0, r5, 0
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r0, 11
	ldr r1, =gUnknown_085BF4A0
	adds r0, r1
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
_0814949A:
	ldrh r0, [r4, 0xA]
	adds r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x27
	ble _081494F0
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	movs r0, 0
	strh r0, [r1, 0x2]
	movs r0, 0x3F
	strh r0, [r1, 0x4]
	movs r0, 0xF0
	strh r0, [r1, 0x6]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	movs r1, 0
	ldr r5, =VBlankCB1_Phase2_BigPokeball
	ldr r3, =gUnknown_020393A8
	movs r2, 0
_081494C4:
	lsls r0, r1, 1
	adds r0, r3
	strh r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x9F
	bls _081494C4
	adds r0, r5, 0
	bl SetVBlankCallback
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	movs r2, 0
	strh r0, [r4, 0x8]
	movs r1, 0x80
	lsls r1, 1
	strh r1, [r4, 0xC]
	strh r2, [r4, 0x16]
	movs r0, 0
	bl ClearGpuRegBits
_081494F0:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814946C

	thumb_func_start sub_8149508
sub_8149508: @ 8149508
	push {lr}
	ldr r1, =0x040000b0
	ldrh r2, [r1, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r2, [r1, 0xA]
	ldr r0, =0x00007fff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	bl VBlankCB_BattleTransition
	ldr r0, =sTransitionStructPtr
	ldr r0, [r0]
	movs r1, 0x20
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bne _08149548
	ldr r2, =gUnknown_02038C28
	b _08149554
	.pool
_08149548:
	ldr r2, =gUnknown_02038C28
	cmp r0, 0x1
	bne _08149554
	movs r0, 0xF0
	lsls r0, 3
	adds r2, r0
_08149554:
	ldr r1, =0x040000b0
	str r2, [r1]
	ldr r0, =0x04000012
	str r0, [r1, 0x4]
	ldr r0, =0xa2400001
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149508

	thumb_func_start Phase2Task_WhiteFade
Phase2Task_WhiteFade: @ 8149578
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C8D8C
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814958A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814958A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Phase2Task_WhiteFade

	thumb_func_start sub_81495B0
sub_81495B0: @ 81495B0
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	movs r2, 0
	movs r0, 0xBF
	strh r0, [r1, 0xE]
	strh r2, [r1, 0x12]
	movs r0, 0x1E
	strh r0, [r1, 0x2]
	movs r0, 0x3F
	strh r0, [r1, 0x4]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	movs r1, 0
	ldr r2, =gUnknown_020393A8
	movs r4, 0
	movs r3, 0xF0
_081495DC:
	lsls r0, r1, 1
	adds r0, r2
	strh r4, [r0]
	adds r0, r1, 0
	adds r0, 0xA0
	lsls r0, 1
	adds r0, r2
	strh r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x9F
	bls _081495DC
	movs r0, 0x2
	bl EnableInterrupts
	ldr r0, =sub_8149840
	bl SetHBlankCallback
	ldr r0, =sub_8149774
	bl SetVBlankCallback
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81495B0

	thumb_func_start sub_8149628
sub_8149628: @ 8149628
	push {r4-r6,lr}
	sub sp, 0x10
	adds r6, r0, 0
	ldr r1, =sUnknown_085C8DA0
	mov r0, sp
	movs r2, 0x10
	bl memcpy
	movs r5, 0
	movs r4, 0
_0814963C:
	ldr r0, =sub_8149864
	bl CreateInvisibleSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r2, r1, r0
	movs r0, 0xF0
	strh r0, [r2, 0x20]
	strh r4, [r2, 0x22]
	lsls r1, r5, 16
	asrs r1, 16
	lsls r0, r1, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r2, 0x38]
	adds r1, 0x1
	lsls r1, 16
	lsls r0, r4, 16
	movs r3, 0xA0
	lsls r3, 13
	adds r0, r3
	lsrs r4, r0, 16
	lsrs r5, r1, 16
	asrs r1, 16
	cmp r1, 0x7
	ble _0814963C
	ldrh r0, [r2, 0x3A]
	adds r0, 0x1
	strh r0, [r2, 0x3A]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149628

	thumb_func_start sub_814969C
sub_814969C: @ 814969C
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =sTransitionStructPtr
	ldr r1, [r2]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	ldr r0, [r2]
	movs r1, 0x20
	ldrsh r0, [r0, r1]
	cmp r0, 0x7
	ble _081496C6
	movs r0, 0x1
	negs r0, r0
	ldr r2, =0x00007fff
	movs r1, 0x10
	bl BlendPalettes
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_081496C6:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814969C

	thumb_func_start sub_81496D8
sub_81496D8: @ 81496D8
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r4, =sTransitionStructPtr
	ldr r0, [r4]
	ldrb r1, [r0]
	movs r5, 0
	strb r5, [r0]
	ldr r1, =0x040000b0
	ldrh r2, [r1, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r2, [r1, 0xA]
	ldr r0, =0x00007fff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	ldr r1, [r4]
	movs r0, 0xF0
	strh r0, [r1, 0x6]
	strh r5, [r1, 0x12]
	movs r0, 0xFF
	strh r0, [r1, 0xE]
	movs r0, 0x3F
	strh r0, [r1, 0x2]
	ldr r0, =sub_8149804
	bl SetVBlankCallback
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81496D8

	thumb_func_start sub_8149740
sub_8149740: @ 8149740
	push {lr}
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	ldrh r0, [r1, 0x12]
	adds r0, 0x1
	strh r0, [r1, 0x12]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x10
	bls _08149766
	bl sub_8149F84
	ldr r0, =Phase2Task_WhiteFade
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_08149766:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149740

	thumb_func_start sub_8149774
sub_8149774: @ 8149774
	push {r4,lr}
	ldr r4, =0x040000b0
	ldrh r1, [r4, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xA]
	bl VBlankCB_BattleTransition
	ldr r2, =0x04000050
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	ldrh r0, [r1, 0xE]
	strh r0, [r2]
	subs r2, 0x8
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	subs r2, 0x6
	ldrh r0, [r1, 0x8]
	strh r0, [r2]
	ldrb r0, [r1]
	cmp r0, 0
	beq _081497C4
	ldr r1, =0x040000d4
	ldr r0, =gUnknown_02038C28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x80000140
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_081497C4:
	ldr r0, =gUnknown_020394E8
	str r0, [r4]
	ldr r0, =0x04000040
	str r0, [r4, 0x4]
	ldr r0, =0xa2400001
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149774

	thumb_func_start sub_8149804
sub_8149804: @ 8149804
	push {lr}
	bl VBlankCB_BattleTransition
	ldr r1, =0x04000054
	ldr r0, =sTransitionStructPtr
	ldr r2, [r0]
	ldrh r0, [r2, 0x12]
	strh r0, [r1]
	subs r1, 0x4
	ldrh r0, [r2, 0xE]
	strh r0, [r1]
	subs r1, 0x8
	ldrh r0, [r2, 0x2]
	strh r0, [r1]
	adds r1, 0x2
	ldrh r0, [r2, 0x4]
	strh r0, [r1]
	subs r1, 0xA
	ldrh r0, [r2, 0x6]
	strh r0, [r1]
	adds r1, 0x4
	ldrh r0, [r2, 0x8]
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149804

	thumb_func_start sub_8149840
sub_8149840: @ 8149840
	ldr r2, =0x04000054
	ldr r1, =gUnknown_02038C28
	ldr r0, =0x04000006
	ldrh r0, [r0]
	lsls r0, 1
	movs r3, 0xF0
	lsls r3, 3
	adds r1, r3
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	bx lr
	.pool
	thumb_func_end sub_8149840

	thumb_func_start sub_8149864
sub_8149864: @ 8149864
	push {r4-r6,lr}
	adds r3, r0, 0
	ldrh r1, [r3, 0x38]
	movs r2, 0x38
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _08149890
	subs r0, r1, 0x1
	strh r0, [r3, 0x38]
	movs r1, 0x3A
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _0814994C
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	ldrb r0, [r1]
	movs r0, 0x1
	strb r0, [r1]
	b _0814994C
	.pool
_08149890:
	movs r2, 0x22
	ldrsh r1, [r3, r2]
	lsls r1, 1
	ldr r0, =gUnknown_02038C28
	adds r6, r1, r0
	movs r2, 0xA0
	lsls r2, 1
	adds r0, r2
	adds r5, r1, r0
	movs r4, 0
_081498A4:
	lsls r1, r4, 1
	adds r2, r1, r6
	ldrh r0, [r3, 0x2E]
	lsls r0, 16
	asrs r0, 24
	strh r0, [r2]
	adds r1, r5
	ldrh r0, [r3, 0x20]
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x13
	bls _081498A4
	movs r1, 0x20
	ldrsh r0, [r3, r1]
	ldrh r2, [r3, 0x20]
	cmp r0, 0
	bne _081498DE
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	movs r0, 0x80
	lsls r0, 5
	cmp r1, r0
	bne _081498DE
	movs r0, 0x1
	strh r0, [r3, 0x30]
_081498DE:
	adds r1, r2, 0
	subs r1, 0x10
	strh r1, [r3, 0x20]
	ldrh r0, [r3, 0x2E]
	adds r0, 0x80
	strh r0, [r3, 0x2E]
	lsls r1, 16
	cmp r1, 0
	bge _081498F4
	movs r0, 0
	strh r0, [r3, 0x20]
_081498F4:
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	movs r1, 0x80
	lsls r1, 5
	cmp r0, r1
	ble _08149902
	strh r1, [r3, 0x2E]
_08149902:
	movs r2, 0x3A
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _08149914
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	ldrb r0, [r1]
	movs r0, 0x1
	strb r0, [r1]
_08149914:
	movs r1, 0x30
	ldrsh r0, [r3, r1]
	cmp r0, 0
	beq _0814994C
	movs r2, 0x3A
	ldrsh r0, [r3, r2]
	ldr r2, =sTransitionStructPtr
	cmp r0, 0
	beq _0814993E
	ldr r0, [r2]
	movs r1, 0x20
	ldrsh r0, [r0, r1]
	cmp r0, 0x6
	ble _0814994C
	ldrh r0, [r3, 0x32]
	adds r1, r0, 0x1
	strh r1, [r3, 0x32]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _0814994C
_0814993E:
	ldr r1, [r2]
	ldrh r0, [r1, 0x20]
	adds r0, 0x1
	strh r0, [r1, 0x20]
	adds r0, r3, 0
	bl DestroySprite
_0814994C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149864

	thumb_func_start Phase2Task_GridSquares
Phase2Task_GridSquares: @ 814995C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =sUnknown_085C8DB0
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814996E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814996E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Phase2Task_GridSquares

	thumb_func_start sub_8149994
sub_8149994: @ 8149994
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	ldr r0, =sShrinkingBoxTileset
	ldr r1, [sp, 0x8]
	movs r2, 0x10
	bl CpuSet
	mov r1, sp
	movs r2, 0xF0
	lsls r2, 8
	adds r0, r2, 0
	strh r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	mov r0, sp
	bl CpuSet
	ldr r0, =gFieldEffectObjectPalette10
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149994

	thumb_func_start sub_81499E8
sub_81499E8: @ 81499E8
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _08149A2A
	mov r0, sp
	bl sub_8149F40
	movs r0, 0x3
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	lsls r0, 5
	ldr r1, =sShrinkingBoxTileset
	adds r0, r1
	ldr r1, [sp]
	movs r2, 0x10
	bl CpuSet
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0xD
	ble _08149A2A
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x10
	strh r0, [r4, 0xA]
_08149A2A:
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81499E8

	thumb_func_start sub_8149A40
sub_8149A40: @ 8149A40
	push {lr}
	ldrh r1, [r0, 0xA]
	subs r1, 0x1
	strh r1, [r0, 0xA]
	lsls r1, 16
	cmp r1, 0
	bne _08149A60
	bl sub_8149F84
	ldr r0, =Phase2Task_GridSquares
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_08149A60:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149A40

	thumb_func_start Phase2Task_Shards
Phase2Task_Shards: @ 8149A6C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =sPhase2_Shards_Funcs
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08149A7E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08149A7E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Phase2Task_Shards

	thumb_func_start sub_8149AA4
sub_8149AA4: @ 8149AA4
	push {r4,r5,lr}
	adds r5, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	movs r2, 0
	movs r0, 0x3F
	strh r0, [r1, 0x2]
	strh r2, [r1, 0x4]
	movs r0, 0xA0
	strh r0, [r1, 0x8]
	movs r1, 0
	ldr r2, =gUnknown_02038C28
	movs r3, 0xF0
	adds r4, r2, 0
_08149AC8:
	lsls r0, r1, 1
	adds r0, r2
	strh r3, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x9F
	bls _08149AC8
	movs r0, 0xF0
	lsls r0, 3
	adds r1, r4, r0
	adds r0, r4, 0
	movs r2, 0xA0
	bl CpuSet
	ldr r0, =sub_8149CE8
	bl SetVBlankCallback
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149AA4

	thumb_func_start sub_8149B08
sub_8149B08: @ 8149B08
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0xC
	mov r8, r0
	ldr r0, =sTransitionStructPtr
	ldr r0, [r0]
	adds r0, 0x24
	ldr r6, =sUnknown_085C8DD0
	mov r2, r8
	movs r3, 0xA
	ldrsh r1, [r2, r3]
	lsls r4, r1, 2
	adds r4, r1
	lsls r4, 1
	adds r1, r4, r6
	movs r5, 0
	ldrsh r1, [r1, r5]
	adds r2, r6, 0x2
	adds r2, r4, r2
	movs r3, 0
	ldrsh r2, [r2, r3]
	adds r3, r6, 0x4
	adds r3, r4, r3
	movs r5, 0
	ldrsh r3, [r3, r5]
	adds r5, r6, 0x6
	adds r4, r5
	movs r5, 0
	ldrsh r4, [r4, r5]
	str r4, [sp]
	movs r4, 0x1
	str r4, [sp, 0x4]
	str r4, [sp, 0x8]
	bl sub_814A1AC
	mov r0, r8
	movs r2, 0xA
	ldrsh r1, [r0, r2]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r6, 0x8
	adds r0, r6
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3, 0xC]
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	movs r0, 0x1
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149B08

	thumb_func_start sub_8149B84
sub_8149B84: @ 8149B84
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r6, r0, 0
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	ldrb r0, [r1]
	movs r0, 0
	strb r0, [r1]
	mov r8, r0
	movs r7, 0
	ldr r0, =gUnknown_02038C28
	mov r9, r0
_08149BA0:
	ldr r1, =gUnknown_02038C28
	ldr r0, =sTransitionStructPtr
	ldr r2, [r0]
	movs r3, 0x2A
	ldrsh r0, [r2, r3]
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	lsrs r3, r0, 8
	movs r5, 0xFF
	ands r5, r0
	movs r4, 0xC
	ldrsh r0, [r6, r4]
	cmp r0, 0
	bne _08149BDC
	movs r1, 0x28
	ldrsh r0, [r2, r1]
	cmp r3, r0
	bge _08149BC8
	ldrh r3, [r2, 0x28]
_08149BC8:
	lsls r0, r3, 16
	lsls r1, r5, 16
	cmp r0, r1
	ble _08149BF4
	lsrs r3, r1, 16
	b _08149BF4
	.pool
_08149BDC:
	lsls r0, r5, 16
	asrs r0, 16
	movs r4, 0x28
	ldrsh r1, [r2, r4]
	cmp r0, r1
	ble _08149BEA
	ldrh r5, [r2, 0x28]
_08149BEA:
	lsls r0, r5, 16
	lsls r1, r3, 16
	cmp r0, r1
	bgt _08149BF4
	lsrs r5, r1, 16
_08149BF4:
	ldr r0, =sTransitionStructPtr
	ldr r4, [r0]
	movs r0, 0x2A
	ldrsh r2, [r4, r0]
	lsls r2, 1
	add r2, r9
	lsls r1, r3, 16
	asrs r1, 8
	lsls r0, r5, 16
	asrs r0, 16
	orrs r0, r1
	strh r0, [r2]
	cmp r7, 0
	beq _08149C1C
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	b _08149C40
	.pool
_08149C1C:
	adds r0, r4, 0
	adds r0, 0x24
	movs r1, 0x1
	movs r2, 0x1
	bl sub_814A228
	lsls r0, 24
	lsrs r7, r0, 24
	mov r1, r8
	lsls r0, r1, 16
	movs r3, 0x80
	lsls r3, 9
	adds r0, r3
	lsrs r4, r0, 16
	mov r8, r4
	asrs r0, 16
	cmp r0, 0xF
	ble _08149BA0
_08149C40:
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149B84

	thumb_func_start sub_8149C60
sub_8149C60: @ 8149C60
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0xA]
	adds r0, 0x1
	strh r0, [r2, 0xA]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	ble _08149CAC
	ldr r1, =0x040000b0
	ldrh r2, [r1, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r2, [r1, 0xA]
	ldr r0, =0x00007fff
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	bl sub_8149F84
	ldr r0, =Phase2Task_Shards
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	b _08149CC4
	.pool
_08149CAC:
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	ldr r1, =sUnknown_085C8E16
	movs r3, 0xA
	ldrsh r0, [r2, r3]
	subs r0, 0x1
	lsls r0, 1
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2, 0xE]
	movs r0, 0x1
_08149CC4:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149C60

	thumb_func_start sub_8149CCC
sub_8149CCC: @ 8149CCC
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0xE]
	subs r0, 0x1
	strh r0, [r1, 0xE]
	lsls r0, 16
	cmp r0, 0
	beq _08149CE0
	movs r0, 0
	b _08149CE4
_08149CE0:
	movs r0, 0x1
	strh r0, [r1, 0x8]
_08149CE4:
	pop {r1}
	bx r1
	thumb_func_end sub_8149CCC

	thumb_func_start sub_8149CE8
sub_8149CE8: @ 8149CE8
	push {r4,lr}
	ldr r4, =0x040000b0
	ldrh r1, [r4, 0xA]
	ldr r0, =0x0000c5ff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r1, [r4, 0xA]
	ldr r0, =0x00007fff
	ands r0, r1
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xA]
	bl VBlankCB_BattleTransition
	ldr r3, =sTransitionStructPtr
	ldr r0, [r3]
	ldrb r0, [r0]
	cmp r0, 0
	beq _08149D20
	ldr r1, =0x040000d4
	ldr r0, =gUnknown_02038C28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_08149D20:
	ldr r2, =0x04000048
	ldr r1, [r3]
	ldrh r0, [r1, 0x2]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r1, 0x4]
	strh r0, [r2]
	subs r2, 0x6
	ldrh r0, [r1, 0x8]
	strh r0, [r2]
	subs r2, 0x4
	ldr r0, =gUnknown_02038C28
	movs r1, 0xF0
	lsls r1, 3
	adds r0, r1
	ldrh r1, [r0]
	strh r1, [r2]
	str r0, [r4]
	str r2, [r4, 0x4]
	ldr r0, =0xa2400001
	str r0, [r4, 0x8]
	ldr r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149CE8

	thumb_func_start CreatePhase1Task
CreatePhase1Task: @ 8149D78
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	ldr r3, [sp, 0x18]
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	lsls r3, 16
	lsrs r3, 16
	ldr r0, =sub_8149DFC
	movs r1, 0x3
	str r3, [sp]
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	mov r0, r8
	strh r0, [r1, 0xA]
	strh r4, [r1, 0xC]
	strh r5, [r1, 0xE]
	strh r6, [r1, 0x10]
	ldr r3, [sp]
	strh r3, [r1, 0x12]
	strh r0, [r1, 0x14]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreatePhase1Task

	thumb_func_start IsPhase1Done
IsPhase1Done: @ 8149DDC
	push {lr}
	ldr r0, =sub_8149DFC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	beq _08149DF4
	movs r0, 0
	b _08149DF6
	.pool
_08149DF4:
	movs r0, 0x1
_08149DF6:
	pop {r1}
	bx r1
	thumb_func_end IsPhase1Done

	thumb_func_start sub_8149DFC
sub_8149DFC: @ 8149DFC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =sPhase1_TransitionAll_Funcs
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_08149E0E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _08149E0E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149DFC

	thumb_func_start sub_8149E34
sub_8149E34: @ 8149E34
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x14]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08149E4C
	subs r0, r1, 0x1
	strh r0, [r4, 0x14]
	lsls r0, 16
	cmp r0, 0
	bne _08149E70
_08149E4C:
	ldrh r0, [r4, 0xA]
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x10]
	ldrh r1, [r4, 0x16]
	adds r0, r1
	strh r0, [r4, 0x16]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x10
	ble _08149E64
	movs r0, 0x10
	strh r0, [r4, 0x16]
_08149E64:
	movs r0, 0x1
	negs r0, r0
	ldrb r1, [r4, 0x16]
	ldr r2, =0x00002d6b
	bl BlendPalettes
_08149E70:
	movs r2, 0x16
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	ble _08149E82
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0x14]
_08149E82:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8149E34

	thumb_func_start sub_8149E90
sub_8149E90: @ 8149E90
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x14]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _08149EA8
	subs r0, r1, 0x1
	strh r0, [r4, 0x14]
	lsls r0, 16
	cmp r0, 0
	bne _08149ECA
_08149EA8:
	ldrh r0, [r4, 0xC]
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x16]
	ldrh r1, [r4, 0x12]
	subs r0, r1
	strh r0, [r4, 0x16]
	lsls r0, 16
	cmp r0, 0
	bge _08149EBE
	movs r0, 0
	strh r0, [r4, 0x16]
_08149EBE:
	movs r0, 0x1
	negs r0, r0
	ldrb r1, [r4, 0x16]
	ldr r2, =0x00002d6b
	bl BlendPalettes
_08149ECA:
	movs r0, 0x16
	ldrsh r1, [r4, r0]
	cmp r1, 0
	bne _08149EFE
	ldrh r0, [r4, 0xE]
	subs r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	cmp r0, 0
	bne _08149EF8
	ldr r0, =sub_8149DFC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	b _08149EFE
	.pool
_08149EF8:
	ldrh r0, [r4, 0xA]
	strh r0, [r4, 0x14]
	strh r1, [r4, 0x8]
_08149EFE:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8149E90

	thumb_func_start sub_8149F08
sub_8149F08: @ 8149F08
	push {r4,lr}
	ldr r4, =sTransitionStructPtr
	ldr r0, [r4]
	movs r1, 0
	movs r2, 0x3C
	bl memset
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x14
	adds r1, 0x16
	bl sub_8089C08
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149F08

	thumb_func_start VBlankCB_BattleTransition
VBlankCB_BattleTransition: @ 8149F2C
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end VBlankCB_BattleTransition

	thumb_func_start sub_8149F40
sub_8149F40: @ 8149F40
	ldr r1, =0x04000008
	ldrh r1, [r1]
	lsrs r1, 2
	lsls r1, 30
	lsrs r1, 16
	movs r2, 0xC0
	lsls r2, 19
	adds r1, r2
	str r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_8149F40

	thumb_func_start sub_8149F58
sub_8149F58: @ 8149F58
	push {r4,lr}
	ldr r3, =0x04000008
	ldrh r2, [r3]
	lsrs r2, 8
	ldrh r3, [r3]
	lsrs r3, 2
	lsls r2, 27
	lsrs r2, 16
	lsls r3, 30
	lsrs r3, 16
	movs r4, 0xC0
	lsls r4, 19
	adds r2, r4
	str r2, [r0]
	adds r3, r4
	str r3, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149F58

	thumb_func_start sub_8149F84
sub_8149F84: @ 8149F84
	push {lr}
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	pop {r0}
	bx r0
	thumb_func_end sub_8149F84

	thumb_func_start sub_8149F98
sub_8149F98: @ 8149F98
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r0
	ldr r0, [sp, 0x20]
	ldr r4, [sp, 0x24]
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r1, r0, 16
	lsls r4, 16
	movs r6, 0
	lsrs r5, r4, 16
	cmp r4, 0
	ble _0814A000
	lsls r0, r7, 16
	asrs r0, 16
	mov r9, r0
	lsls r1, 16
	mov r8, r1
	lsls r0, r3, 16
	asrs r7, r0, 16
_08149FD0:
	lsls r4, r2, 16
	asrs r4, 16
	movs r0, 0xFF
	ands r0, r4
	mov r2, r8
	asrs r1, r2, 16
	bl Sin
	lsls r1, r6, 1
	add r1, r10
	add r0, r9
	strh r0, [r1]
	lsls r1, r5, 16
	ldr r0, =0xffff0000
	adds r1, r0
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r4, r7
	lsls r4, 16
	lsrs r2, r4, 16
	lsrs r5, r1, 16
	cmp r1, 0
	bgt _08149FD0
_0814A000:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8149F98

	thumb_func_start sub_814A014
sub_814A014: @ 814A014
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	mov r9, r0
	adds r5, r2, 0
	adds r4, r3, 0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 16
	lsrs r4, 16
	movs r2, 0xA0
	lsls r2, 1
	movs r1, 0xA
	bl memset
	movs r1, 0
	lsls r4, 16
	asrs r4, 16
	str r4, [sp, 0x4]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x8]
_0814A04C:
	lsls r5, r1, 16
	asrs r0, r5, 16
	mov r10, r0
	ldr r1, [sp, 0x4]
	bl Sin
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, r10
	ldr r1, [sp, 0x4]
	bl Cos
	ldr r2, [sp]
	lsls r1, r2, 16
	asrs r1, 16
	lsls r4, 16
	asrs r4, 16
	subs r2, r1, r4
	lsls r2, 16
	adds r1, r4
	lsls r1, 16
	lsrs r6, r1, 16
	lsls r0, 16
	asrs r0, 16
	ldr r3, [sp, 0x8]
	subs r1, r3, r0
	lsls r1, 16
	lsrs r7, r1, 16
	adds r0, r3, r0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsrs r1, r2, 16
	str r5, [sp, 0x10]
	cmp r2, 0
	bge _0814A098
	movs r1, 0
_0814A098:
	lsls r0, r6, 16
	asrs r0, 16
	cmp r0, 0xF0
	ble _0814A0A2
	movs r6, 0xF0
_0814A0A2:
	lsls r0, r7, 16
	cmp r0, 0
	bge _0814A0AA
	movs r7, 0
_0814A0AA:
	mov r2, r8
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x9F
	ble _0814A0B8
	movs r3, 0x9F
	mov r8, r3
_0814A0B8:
	lsls r0, r1, 24
	lsrs r0, 16
	orrs r6, r0
	lsls r0, r7, 16
	asrs r0, 16
	str r0, [sp, 0xC]
	lsls r0, 1
	add r0, r9
	strh r6, [r0]
	mov r0, r8
	lsls r4, r0, 16
	asrs r0, r4, 15
	add r0, r9
	strh r6, [r0]
	mov r0, r10
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	ldr r1, [sp, 0x4]
	bl Cos
	lsls r0, 16
	asrs r0, 16
	ldr r2, [sp, 0x8]
	subs r1, r2, r0
	lsls r1, 16
	adds r0, r2, r0
	lsls r0, 16
	lsrs r2, r0, 16
	lsrs r3, r1, 16
	cmp r1, 0
	bge _0814A0FA
	movs r3, 0
_0814A0FA:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x9F
	ble _0814A104
	movs r2, 0x9F
_0814A104:
	lsls r0, r3, 16
	asrs r1, r0, 16
	adds r3, r0, 0
	lsls r5, r2, 16
	ldr r0, [sp, 0xC]
	cmp r0, r1
	ble _0814A128
	adds r2, r1, 0
_0814A114:
	lsls r1, r7, 16
	ldr r0, =0xffff0000
	adds r1, r0
	asrs r0, r1, 15
	add r0, r9
	strh r6, [r0]
	lsrs r7, r1, 16
	asrs r1, 16
	cmp r1, r2
	bgt _0814A114
_0814A128:
	lsls r1, r7, 16
	asrs r0, r3, 16
	cmp r1, r3
	bge _0814A146
	adds r2, r0, 0
_0814A132:
	movs r3, 0x80
	lsls r3, 9
	adds r0, r1, r3
	asrs r1, r0, 15
	add r1, r9
	strh r6, [r1]
	adds r1, r0, 0
	asrs r0, r1, 16
	cmp r0, r2
	blt _0814A132
_0814A146:
	asrs r0, r5, 16
	cmp r4, r5
	ble _0814A164
	adds r1, r0, 0
_0814A14E:
	ldr r2, =0xffff0000
	adds r0, r4, r2
	lsrs r3, r0, 16
	mov r8, r3
	asrs r0, 15
	add r0, r9
	strh r6, [r0]
	lsls r4, r3, 16
	asrs r0, r4, 16
	cmp r0, r1
	bgt _0814A14E
_0814A164:
	mov r0, r8
	lsls r4, r0, 16
	asrs r0, r5, 16
	cmp r4, r5
	bge _0814A184
	adds r2, r0, 0
_0814A170:
	movs r1, 0x80
	lsls r1, 9
	adds r0, r4, r1
	asrs r1, r0, 15
	add r1, r9
	strh r6, [r1]
	adds r4, r0, 0
	asrs r0, r4, 16
	cmp r0, r2
	blt _0814A170
_0814A184:
	ldr r2, [sp, 0x10]
	movs r3, 0x80
	lsls r3, 9
	adds r0, r2, r3
	lsrs r1, r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	bgt _0814A196
	b _0814A04C
_0814A196:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814A014

	thumb_func_start sub_814A1AC
sub_814A1AC: @ 814A1AC
	push {r4-r7,lr}
	adds r6, r0, 0
	ldr r0, [sp, 0x14]
	ldr r5, [sp, 0x18]
	ldr r4, [sp, 0x1C]
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r0, 16
	adds r7, r0, 0
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 16
	lsrs r4, 16
	strh r1, [r6]
	strh r2, [r6, 0x2]
	strh r1, [r6, 0x4]
	strh r2, [r6, 0x6]
	strh r3, [r6, 0x8]
	strh r7, [r6, 0xA]
	strh r5, [r6, 0xC]
	strh r4, [r6, 0xE]
	lsls r3, 16
	asrs r3, 16
	lsls r1, 16
	asrs r1, 16
	subs r3, r1
	strh r3, [r6, 0x10]
	lsls r0, r3, 16
	cmp r0, 0
	bge _0814A1FE
	negs r0, r3
	strh r0, [r6, 0x10]
	lsls r0, r5, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r6, 0xC]
_0814A1FE:
	lsls r0, r7, 16
	asrs r0, 16
	lsls r1, r2, 16
	asrs r1, 16
	subs r1, r0, r1
	strh r1, [r6, 0x12]
	lsls r0, r1, 16
	cmp r0, 0
	bge _0814A21C
	negs r0, r1
	strh r0, [r6, 0x12]
	lsls r0, r4, 16
	asrs r0, 16
	negs r0, r0
	strh r0, [r6, 0xE]
_0814A21C:
	movs r0, 0
	strh r0, [r6, 0x14]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_814A1AC

	thumb_func_start sub_814A228
sub_814A228: @ 814A228
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	ldrh r0, [r3, 0x10]
	mov r8, r0
	movs r1, 0x10
	ldrsh r6, [r3, r1]
	ldrh r2, [r3, 0x12]
	mov r12, r2
	movs r4, 0x12
	ldrsh r5, [r3, r4]
	cmp r6, r5
	ble _0814A278
	ldrh r0, [r3, 0xC]
	ldrh r2, [r3, 0x4]
	adds r1, r0, r2
	strh r1, [r3, 0x4]
	ldrh r2, [r3, 0x14]
	add r2, r12
	strh r2, [r3, 0x14]
	lsls r1, r2, 16
	asrs r1, 16
	adds r4, r0, 0
	ldrh r7, [r3, 0xE]
	cmp r1, r6
	ble _0814A29E
	ldrh r1, [r3, 0x6]
	adds r0, r7, r1
	strh r0, [r3, 0x6]
	mov r1, r8
	b _0814A29A
_0814A278:
	ldrh r0, [r3, 0xE]
	ldrh r2, [r3, 0x6]
	adds r1, r0, r2
	strh r1, [r3, 0x6]
	ldrh r2, [r3, 0x14]
	add r2, r8
	strh r2, [r3, 0x14]
	lsls r1, r2, 16
	asrs r1, 16
	ldrh r4, [r3, 0xC]
	adds r7, r0, 0
	cmp r1, r5
	ble _0814A29E
	ldrh r1, [r3, 0x4]
	adds r0, r4, r1
	strh r0, [r3, 0x4]
	mov r1, r12
_0814A29A:
	subs r0, r2, r1
	strh r0, [r3, 0x14]
_0814A29E:
	movs r5, 0
	lsls r0, r4, 16
	asrs r2, r0, 16
	cmp r2, 0
	ble _0814A2B6
	movs r4, 0x4
	ldrsh r1, [r3, r4]
	movs r4, 0x8
	ldrsh r0, [r3, r4]
	ldrh r4, [r3, 0x8]
	cmp r1, r0
	bge _0814A2C8
_0814A2B6:
	cmp r2, 0
	bge _0814A2D6
	movs r0, 0x4
	ldrsh r1, [r3, r0]
	movs r2, 0x8
	ldrsh r0, [r3, r2]
	ldrh r4, [r3, 0x8]
	cmp r1, r0
	bgt _0814A2D6
_0814A2C8:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r9
	cmp r0, 0
	beq _0814A2D6
	strh r4, [r3, 0x4]
_0814A2D6:
	lsls r0, r7, 16
	asrs r2, r0, 16
	cmp r2, 0
	ble _0814A2EC
	movs r4, 0x6
	ldrsh r1, [r3, r4]
	movs r4, 0xA
	ldrsh r0, [r3, r4]
	ldrh r4, [r3, 0xA]
	cmp r1, r0
	bge _0814A2FE
_0814A2EC:
	cmp r2, 0
	bge _0814A30C
	movs r0, 0x6
	ldrsh r1, [r3, r0]
	movs r2, 0xA
	ldrsh r0, [r3, r2]
	ldrh r4, [r3, 0xA]
	cmp r1, r0
	bgt _0814A30C
_0814A2FE:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r0, r10
	cmp r0, 0
	beq _0814A30C
	strh r4, [r3, 0x6]
_0814A30C:
	cmp r5, 0x2
	beq _0814A314
	movs r0, 0
	b _0814A316
_0814A314:
	movs r0, 0x1
_0814A316:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_814A228

	thumb_func_start sub_814A324
sub_814A324: @ 814A324
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	bl sub_814669C
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	mov r0, sp
	bl CpuSet
	ldr r0, =gUnknown_085C7C00
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085C7BE0
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A324

	thumb_func_start sub_814A374
sub_814A374: @ 814A374
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085C828C
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_02038C28
	movs r1, 0x10
	ldrsh r2, [r4, r1]
	movs r3, 0x12
	ldrsh r1, [r4, r3]
	str r1, [sp]
	movs r1, 0xA0
	str r1, [sp, 0x4]
	movs r1, 0
	movs r3, 0x84
	bl sub_8149F98
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	add sp, 0x10
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A374

	thumb_func_start Phase2Task_29
Phase2Task_29: @ 814A3BC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C99D0
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814A3CE:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814A3CE
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Phase2Task_29

	thumb_func_start Phase2Task_30
Phase2Task_30: @ 814A3F4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C99E8
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814A406:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814A406
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Phase2Task_30

	thumb_func_start sub_814A42C
sub_814A42C: @ 814A42C
	push {r4-r6,lr}
	sub sp, 0xC
	adds r4, r0, 0
	bl sub_8149F08
	bl dp12_8087EA4
	movs r1, 0xC0
	lsls r1, 7
	movs r0, 0
	bl ClearGpuRegBits
	movs r5, 0
	movs r0, 0x80
	lsls r0, 6
	strh r0, [r4, 0xC]
	ldr r0, =0x00007fff
	strh r0, [r4, 0xA]
	strh r5, [r4, 0x12]
	movs r0, 0x10
	strh r0, [r4, 0x14]
	movs r0, 0xA0
	lsls r0, 4
	strh r0, [r4, 0x16]
	ldr r6, =sTransitionStructPtr
	ldr r2, [r6]
	ldr r3, =0x00003f41
	strh r3, [r2, 0xE]
	ldrh r0, [r4, 0x14]
	lsls r0, 8
	ldrh r1, [r4, 0x12]
	orrs r0, r1
	strh r0, [r2, 0x10]
	ldr r0, =0x04000050
	strh r3, [r0]
	ldr r1, =0x04000052
	ldrh r0, [r2, 0x10]
	strh r0, [r1]
	add r0, sp, 0x4
	add r1, sp, 0x8
	bl sub_8149F58
	mov r0, sp
	strh r5, [r0]
	ldr r1, [sp, 0x4]
	ldr r2, =0x01000400
	bl CpuSet
	ldr r0, =gUnknown_085C7C00
	ldr r1, [sp, 0x8]
	bl LZ77UnCompVram
	ldr r0, =gUnknown_085C7BE0
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, [r6]
	strh r5, [r0, 0x16]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	add sp, 0xC
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A42C

	thumb_func_start sub_814A4D4
sub_814A4D4: @ 814A4D4
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	add r1, sp, 0x4
	mov r0, sp
	bl sub_8149F58
	ldr r0, =gUnknown_085C828C
	ldr r1, [sp]
	bl LZ77UnCompVram
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A4D4

	thumb_func_start sub_814A500
sub_814A500: @ 814A500
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r2, 0
	ldr r6, =sub_814A684
	ldr r4, =gUnknown_020393A8
	ldr r3, =sTransitionStructPtr
_0814A50C:
	lsls r1, r2, 1
	adds r1, r4
	ldr r0, [r3]
	ldrh r0, [r0, 0x16]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x9F
	bls _0814A50C
	adds r0, r6, 0
	bl SetVBlankCallback
	ldr r0, =sub_814A6CC
	bl SetHBlankCallback
	movs r0, 0x2
	bl EnableInterrupts
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x1
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A500

	thumb_func_start sub_814A550
sub_814A550: @ 814A550
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r1, =sTransitionStructPtr
	ldr r0, [r1]
	ldrb r2, [r0]
	movs r3, 0
	strb r3, [r0]
	ldrh r2, [r4, 0xC]
	lsls r0, r2, 16
	asrs r0, 24
	lsls r0, 16
	lsrs r7, r0, 16
	ldrh r6, [r4, 0xA]
	movs r0, 0xC0
	lsls r0, 1
	mov r8, r0
	ldrh r0, [r4, 0x16]
	subs r0, r6, r0
	strh r0, [r4, 0xA]
	movs r5, 0xE
	ldrsh r0, [r4, r5]
	adds r5, r1, 0
	cmp r0, 0x45
	ble _0814A5A2
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	ldr r1, =0xfffffe80
	adds r0, r1
	cmp r0, 0
	blt _0814A5A0
	adds r0, r2, r1
	strh r0, [r4, 0xC]
	b _0814A5A2
	.pool
_0814A5A0:
	strh r3, [r4, 0xC]
_0814A5A2:
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r0, 0
	blt _0814A5E0
	movs r1, 0x3
	bl __modsi3
	lsls r0, 16
	cmp r0, 0
	bne _0814A5E0
	ldrh r1, [r4, 0x12]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	cmp r0, 0xF
	bgt _0814A5C6
	adds r0, r1, 0x1
	strh r0, [r4, 0x12]
	b _0814A5D4
_0814A5C6:
	ldrh r1, [r4, 0x14]
	movs r2, 0x14
	ldrsh r0, [r4, r2]
	cmp r0, 0
	ble _0814A5D4
	subs r0, r1, 0x1
	strh r0, [r4, 0x14]
_0814A5D4:
	ldr r0, [r5]
	ldrh r1, [r4, 0x14]
	lsls r1, 8
	ldrh r2, [r4, 0x12]
	orrs r1, r2
	strh r1, [r0, 0x10]
_0814A5E0:
	movs r5, 0
	lsls r7, 16
_0814A5E4:
	lsrs r0, r6, 8
	asrs r1, r7, 16
	bl Sin
	ldr r1, =gUnknown_02038C28
	lsls r2, r5, 1
	adds r2, r1
	ldr r1, =sTransitionStructPtr
	ldr r1, [r1]
	ldrh r1, [r1, 0x16]
	adds r0, r1
	strh r0, [r2]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	mov r1, r8
	adds r0, r6, r1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r5, 0x9F
	bls _0814A5E4
	ldrh r0, [r4, 0xE]
	adds r0, 0x1
	strh r0, [r4, 0xE]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x65
	bne _0814A632
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
_0814A632:
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _0814A654
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0814A654
	ldr r0, =Phase2Task_30
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_0814A654:
	ldrh r0, [r4, 0x16]
	subs r0, 0x11
	strh r0, [r4, 0x16]
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, 0x1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, 0
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A550

	thumb_func_start sub_814A684
sub_814A684: @ 814A684
	push {lr}
	bl VBlankCB_BattleTransition
	ldr r2, =0x04000050
	ldr r0, =sTransitionStructPtr
	ldr r1, [r0]
	ldrh r0, [r1, 0xE]
	strh r0, [r2]
	adds r2, 0x2
	ldrh r0, [r1, 0x10]
	strh r0, [r2]
	ldrb r0, [r1]
	cmp r0, 0
	beq _0814A6B4
	ldr r1, =0x040000d4
	ldr r0, =gUnknown_02038C28
	str r0, [r1]
	movs r2, 0xF0
	lsls r2, 3
	adds r0, r2
	str r0, [r1, 0x4]
	ldr r0, =0x800000a0
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
_0814A6B4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814A684

	thumb_func_start sub_814A6CC
sub_814A6CC: @ 814A6CC
	ldr r1, =gUnknown_02038C28
	ldr r0, =0x04000006
	ldrh r0, [r0]
	lsls r0, 1
	movs r2, 0xF0
	lsls r2, 3
	adds r1, r2
	adds r0, r1
	ldrh r1, [r0]
	ldr r0, =0x04000012
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_814A6CC

	thumb_func_start Phase2Task_31
Phase2Task_31: @ 814A6F0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C99F8
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814A702:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814A702
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Phase2Task_31

	thumb_func_start Phase2Task_33
Phase2Task_33: @ 814A728
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C9A08
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814A73A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814A73A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Phase2Task_33

	thumb_func_start Phase2Task_32
Phase2Task_32: @ 814A760
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_085C9A1C
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_0814A772:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _0814A772
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Phase2Task_32

	thumb_func_start sub_814A798
sub_814A798: @ 814A798
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	mov r8, r0
	add r1, sp, 0x10
	add r0, sp, 0xC
	bl sub_8149F58
	ldr r0, =gUnknown_085C8598
	ldr r1, [sp, 0x10]
	bl LZ77UnCompVram
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r6, 0x1
	str r6, [sp]
	str r4, [sp, 0x4]
	movs r5, 0xF
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1D
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_085C8578
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0
	mov r1, r8
	strh r6, [r1, 0xC]
	strh r0, [r1, 0xE]
	strh r0, [r1, 0x10]
	movs r0, 0xA
	strh r0, [r1, 0x16]
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A798

	thumb_func_start sub_814A828
sub_814A828: @ 814A828
	push {r4,r5,lr}
	sub sp, 0x24
	adds r4, r0, 0
	ldr r1, =gUnknown_085C8928
	movs r2, 0x4
	str r2, [sp]
	str r2, [sp, 0x4]
	ldrb r0, [r4, 0xC]
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0xE]
	str r0, [sp, 0xC]
	str r2, [sp, 0x10]
	str r2, [sp, 0x14]
	movs r0, 0xF
	str r0, [sp, 0x18]
	movs r5, 0
	str r5, [sp, 0x1C]
	str r5, [sp, 0x20]
	movs r0, 0
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0xC]
	adds r0, 0x4
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	strh r0, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bne _0814A88A
	movs r0, 0x1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0xE]
	adds r0, 0x4
	strh r0, [r4, 0xE]
	strh r5, [r4, 0x10]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x13
	ble _0814A88A
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0814A88A:
	movs r0, 0
	add sp, 0x24
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A828

	thumb_func_start sub_814A898
sub_814A898: @ 814A898
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldrh r0, [r4, 0x14]
	adds r1, r0, 0x1
	strh r1, [r4, 0x14]
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x16
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _0814A956
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _0814A8FC
	cmp r0, 0x1
	bgt _0814A8CA
	cmp r0, 0
	beq _0814A8D4
	b _0814A92C
_0814A8CA:
	cmp r0, 0x2
	beq _0814A914
	cmp r0, 0x3
	beq _0814A91C
	b _0814A92C
_0814A8D4:
	movs r2, 0xFA
	ldr r6, =gPlttBufferUnfaded
	movs r3, 0
	ldr r5, =gPlttBufferFaded
_0814A8DC:
	lsls r1, r2, 1
	adds r0, r1, r6
	strh r3, [r0]
	adds r1, r5
	strh r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFE
	bls _0814A8DC
	b _0814A94C
	.pool
_0814A8FC:
	ldr r0, =0xffff7fff
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, =gUnknown_085C86F4
	b _0814A91E
	.pool
_0814A914:
	ldr r0, =gUnknown_085C87F4
	b _0814A91E
	.pool
_0814A91C:
	ldr r0, =gUnknown_085C88A4
_0814A91E:
	ldr r1, [sp, 0xC]
	bl LZ77UnCompVram
	b _0814A94C
	.pool
_0814A92C:
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	b _0814A956
_0814A94C:
	movs r0, 0
	strh r0, [r4, 0x14]
	ldrh r0, [r4, 0x12]
	adds r0, 0x1
	strh r0, [r4, 0x12]
_0814A956:
	movs r0, 0
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_814A898

	thumb_func_start sub_814A960
sub_814A960: @ 814A960
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	mov r8, r0
	add r1, sp, 0x10
	add r0, sp, 0xC
	bl sub_8149F58
	ldr r0, =gUnknown_085C8598
	ldr r1, [sp, 0x10]
	bl LZ77UnCompVram
	movs r4, 0x20
	str r4, [sp]
	str r4, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r6, 0x1
	str r6, [sp]
	str r4, [sp, 0x4]
	movs r5, 0xF
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	str r6, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0x1D
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r4, =gUnknown_085C8578
	adds r0, r4, 0
	movs r1, 0xE0
	movs r2, 0x20
	bl LoadPalette
	adds r0, r4, 0
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0xE0
	movs r1, 0x10
	movs r2, 0x8
	movs r3, 0
	bl BlendPalette
	movs r1, 0
	movs r0, 0x22
	mov r2, r8
	strh r0, [r2, 0xC]
	strh r1, [r2, 0xE]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	movs r0, 0
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814A960

	thumb_func_start sub_814AA04
sub_814AA04: @ 814AA04
	push {r4-r6,lr}
	sub sp, 0x24
	adds r6, r0, 0
	ldr r1, =gUnknown_085C9A30
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	adds r0, r1
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0x7
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x7
	bl __udivsi3
	ldr r1, =gUnknown_085C8928
	movs r2, 0x4
	str r2, [sp]
	str r2, [sp, 0x4]
	lsls r4, 2
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x8]
	lsls r0, 26
	lsrs r0, 24
	str r0, [sp, 0xC]
	str r2, [sp, 0x10]
	str r2, [sp, 0x14]
	movs r0, 0xF
	str r0, [sp, 0x18]
	movs r0, 0
	str r0, [sp, 0x1C]
	str r0, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r6, 0xC]
	subs r0, 0x1
	strh r0, [r6, 0xC]
	lsls r0, 16
	cmp r0, 0
	bge _0814AA70
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
_0814AA70:
	movs r0, 0
	add sp, 0x24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AA04

	thumb_func_start sub_814AA84
sub_814AA84: @ 814AA84
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xE0
	movs r1, 0x10
	movs r2, 0x3
	movs r3, 0
	bl BlendPalette
	ldr r0, =0xffff3fff
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	strh r0, [r4, 0xC]
	strh r0, [r4, 0xE]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AA84

	thumb_func_start sub_814AAB8
sub_814AAB8: @ 814AAB8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x24
	adds r7, r0, 0
	ldrh r0, [r7, 0xE]
	movs r1, 0x1
	eors r0, r1
	movs r6, 0
	strh r0, [r7, 0xE]
	cmp r0, 0
	beq _0814AB2C
	ldr r0, =gUnknown_085C8928
	mov r8, r0
	movs r4, 0x4
	str r4, [sp]
	str r4, [sp, 0x4]
	ldr r5, =gUnknown_085C9A30
	movs r1, 0xC
	ldrsh r0, [r7, r1]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x7
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 22
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	movs r2, 0xC
	ldrsh r0, [r7, r2]
	adds r0, r5
	ldrb r0, [r0]
	movs r1, 0x7
	bl __udivsi3
	lsls r0, 26
	lsrs r0, 24
	str r0, [sp, 0xC]
	str r4, [sp, 0x10]
	str r4, [sp, 0x14]
	movs r0, 0xE
	str r0, [sp, 0x18]
	str r6, [sp, 0x1C]
	str r6, [sp, 0x20]
	movs r0, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	b _0814AB78
	.pool
_0814AB2C:
	movs r1, 0xC
	ldrsh r0, [r7, r1]
	cmp r0, 0
	ble _0814AB72
	ldr r1, =gUnknown_085C9A30
	subs r0, 0x1
	adds r0, r1
	ldrb r5, [r0]
	adds r0, r5, 0
	movs r1, 0x7
	bl __umodsi3
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 22
	adds r4, 0x1
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x7
	bl __udivsi3
	adds r3, r0, 0
	lsls r3, 26
	lsrs r3, 24
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	adds r2, r4, 0
	bl FillBgTilemapBufferRect
_0814AB72:
	ldrh r0, [r7, 0xC]
	adds r0, 0x1
	strh r0, [r7, 0xC]
_0814AB78:
	movs r1, 0xC
	ldrsh r0, [r7, r1]
	cmp r0, 0x22
	ble _0814AB86
	ldrh r0, [r7, 0x8]
	adds r0, 0x1
	strh r0, [r7, 0x8]
_0814AB86:
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	add sp, 0x24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AAB8

	thumb_func_start sub_814ABA0
sub_814ABA0: @ 814ABA0
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, [r4]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_814ABA0

	thumb_func_start sub_814ABE4
sub_814ABE4: @ 814ABE4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r6, r1, r2
	ldrh r0, [r6, 0xC]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r6, 0xC]
	cmp r0, 0
	bne _0814AC24
	ldr r5, =gBattle_BG0_X
	ldrh r1, [r5]
	movs r0, 0x12
	bl SetGpuReg
	ldr r4, =gBattle_BG0_Y
	ldrh r1, [r4]
	movs r0, 0x10
	bl SetGpuReg
	ldrh r0, [r6, 0x8]
	ldrh r1, [r5]
	adds r0, r1
	strh r0, [r5]
	ldrh r0, [r6, 0xA]
	ldrh r1, [r4]
	adds r0, r1
	strh r0, [r4]
_0814AC24:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814ABE4

	thumb_func_start sub_814AC38
sub_814AC38: @ 814AC38
	push {r4-r6,lr}
	sub sp, 0x10
	adds r6, r0, 0
	movs r5, 0
	add r1, sp, 0xC
	add r0, sp, 0x8
	bl sub_8149F58
	ldr r0, =gUnknown_085C8598
	ldr r1, [sp, 0xC]
	bl LZ77UnCompVram
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldr r0, =gUnknown_085C8578
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gBattle_BG0_X
	strh r5, [r0]
	ldr r4, =gBattle_BG0_Y
	strh r5, [r4]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x10
	bl SetGpuReg
	strh r5, [r6, 0xC]
	ldr r0, =sub_814ABE4
	movs r1, 0x1
	bl CreateTask
	lsls r0, 24
	lsrs r5, r0, 24
	bl Random
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	lsrs r1, 16
	cmp r1, 0x1
	beq _0814ACE4
	cmp r1, 0x1
	bgt _0814ACC8
	cmp r1, 0
	beq _0814ACCE
	b _0814AD1C
	.pool
_0814ACC8:
	cmp r1, 0x2
	beq _0814AD00
	b _0814AD1C
_0814ACCE:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x8]
	strh r0, [r1, 0xA]
	b _0814AD2E
	.pool
_0814ACE4:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x8]
	movs r1, 0x1
	negs r1, r1
	b _0814AD2C
	.pool
_0814AD00:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	movs r1, 0x1
	strh r1, [r0, 0x8]
	ldr r1, =0x0000ffff
	b _0814AD2C
	.pool
_0814AD1C:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x8]
	movs r1, 0x1
_0814AD2C:
	strh r1, [r0, 0xA]
_0814AD2E:
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0
	add sp, 0x10
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AC38

	thumb_func_start sub_814AD48
sub_814AD48: @ 814AD48
	push {r4,lr}
	sub sp, 0x24
	adds r4, r0, 0
	ldr r1, =gUnknown_085C9A53
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r3, [r0]
	lsrs r2, r3, 3
	movs r0, 0x7
	ands r3, r0
	ldr r1, =gUnknown_085C8928
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	lsls r2, 2
	adds r2, 0x1
	str r2, [sp, 0x8]
	lsls r3, 2
	str r3, [sp, 0xC]
	str r0, [sp, 0x10]
	str r0, [sp, 0x14]
	movs r0, 0xF
	str r0, [sp, 0x18]
	movs r0, 0
	str r0, [sp, 0x1C]
	str r0, [sp, 0x20]
	movs r2, 0
	movs r3, 0
	bl CopyRectToBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _0814ADA0
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0814ADA0:
	movs r0, 0
	add sp, 0x24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AD48

	thumb_func_start sub_814ADB4
sub_814ADB4: @ 814ADB4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0xffff7fff
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	movs r0, 0
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814ADB4

	thumb_func_start sub_814ADD8
sub_814ADD8: @ 814ADD8
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	ldr r1, =gUnknown_085C9A53
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	adds r0, r1
	ldrb r3, [r0]
	lsrs r2, r3, 3
	movs r0, 0x7
	ands r3, r0
	lsls r2, 2
	adds r2, 0x1
	lsls r3, 2
	movs r0, 0x4
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xF
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	bl FillBgTilemapBufferRect
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x3F
	ble _0814AE2E
	ldr r0, =sub_814ABE4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_0814AE2E:
	movs r0, 0
	add sp, 0xC
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814ADD8

	thumb_func_start sub_814AE40
sub_814AE40: @ 814AE40
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r0, =gBattle_BG0_X
	movs r1, 0
	strh r1, [r0]
	ldr r4, =gBattle_BG0_Y
	strh r1, [r4]
	movs r0, 0x12
	movs r1, 0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x10
	bl SetGpuReg
	movs r0, 0x20
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0x1
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	ldr r0, [r5]
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_814AE40

	.align 2, 0 @ Don't pad with nop.
