	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	thumb_func_start sub_81D0450
sub_81D0450: @ 81D0450
	push {r4,lr}
	movs r0, 0xD
	movs r1, 0x9C
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081D0498
	movs r0, 0x12
	bl GetSubstructPtr
	str r0, [r4, 0x8]
	cmp r0, 0
	beq _081D0498
	adds r0, r4, 0
	bl sub_81D0814
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D04C4
	str r0, [r1]
	ldr r1, =gKeyRepeatContinueDelay
	movs r0, 0x3
	strh r0, [r1]
	ldr r1, =gKeyRepeatStartDelay
	movs r0, 0xA
	strh r0, [r1]
	movs r0, 0x1
	b _081D049A
	.pool
_081D0498:
	movs r0, 0
_081D049A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0450

	thumb_func_start sub_81D04A0
sub_81D04A0: @ 81D04A0
	push {lr}
	movs r0, 0xD
	bl GetSubstructPtr
	adds r1, r0, 0
	adds r1, 0x98
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	thumb_func_end sub_81D04A0

	thumb_func_start sub_81D04B8
sub_81D04B8: @ 81D04B8
	push {lr}
	movs r0, 0xD
	bl FreePokenavSubstruct
	pop {r0}
	bx r0
	thumb_func_end sub_81D04B8

	thumb_func_start sub_81D04C4
sub_81D04C4: @ 81D04C4
	push {r4,lr}
	adds r4, r0, 0
	ldr r2, =gMain
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081D04E4
	ldr r3, [r4, 0x8]
	ldrh r0, [r3, 0x2]
	cmp r0, 0
	beq _081D04E4
	subs r0, 0x1
	b _081D04FC
	.pool
_081D04E4:
	ldrh r1, [r2, 0x30]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081D050C
	ldr r3, [r4, 0x8]
	ldrh r1, [r3, 0x2]
	ldrh r0, [r3]
	subs r0, 0x1
	cmp r1, r0
	bge _081D050C
	adds r0, r1, 0x1
_081D04FC:
	movs r1, 0
	strh r0, [r3, 0x2]
	strh r1, [r4, 0xC]
	adds r0, r4, 0
	bl sub_81D0814
	movs r0, 0x1
	b _081D053E
_081D050C:
	ldrh r2, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _081D0528
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D0548
	str r0, [r1]
	movs r0, 0x2
	b _081D053E
	.pool
_081D0528:
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _081D0534
	movs r0, 0
	b _081D053E
_081D0534:
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D05D4
	str r0, [r1]
	movs r0, 0x5
_081D053E:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D04C4

	thumb_func_start sub_81D0548
sub_81D0548: @ 81D0548
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081D0562
	adds r0, r4, 0
	bl sub_81D05DC
	cmp r0, 0
	bne _081D05A4
_081D0562:
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081D0578
	adds r0, r4, 0
	bl sub_81D061C
	cmp r0, 0
	bne _081D05A4
_081D0578:
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081D058E
	adds r0, r4, 0
	bl sub_81D0664
	cmp r0, 0
	bne _081D05A4
_081D058E:
	ldr r0, =gMain
	ldrh r1, [r0, 0x30]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081D05AC
	adds r0, r4, 0
	bl sub_81D0688
	cmp r0, 0
	beq _081D05AC
_081D05A4:
	movs r0, 0x3
	b _081D05CA
	.pool
_081D05AC:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081D05C0
	movs r0, 0
	b _081D05CA
	.pool
_081D05C0:
	adds r1, r4, 0
	adds r1, 0x98
	ldr r0, =sub_81D04C4
	str r0, [r1]
	movs r0, 0x4
_081D05CA:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D0548

	thumb_func_start sub_81D05D4
sub_81D05D4: @ 81D05D4
	ldr r0, =0x000186ae
	bx lr
	.pool
	thumb_func_end sub_81D05D4

	thumb_func_start sub_81D05DC
sub_81D05DC: @ 81D05DC
	push {r4,lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0xC]
	adds r2, r0, 0
	cmp r2, 0x18
	bhi _081D05F0
	cmp r2, 0x8
	bls _081D0612
	subs r0, 0x9
	b _081D060C
_081D05F0:
	ldrh r3, [r1, 0x10]
	adds r2, r3, 0
	cmp r2, 0
	beq _081D0612
	ldrh r0, [r1, 0xC]
	subs r0, 0x1B
	ldrh r4, [r1, 0xE]
	adds r0, r4
	strh r0, [r1, 0xC]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r2
	bcc _081D060E
	subs r0, r3, 0x1
_081D060C:
	strh r0, [r1, 0xC]
_081D060E:
	movs r0, 0x1
	b _081D0614
_081D0612:
	movs r0, 0
_081D0614:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D05DC

	thumb_func_start sub_81D061C
sub_81D061C: @ 81D061C
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0xC]
	adds r1, r0, 0
	cmp r1, 0x18
	bhi _081D065C
	ldrh r3, [r2, 0xE]
	cmp r1, r3
	bcs _081D0640
	adds r0, 0x9
	strh r0, [r2, 0xC]
	ldrh r1, [r2, 0x10]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r1
	bcc _081D0658
	subs r0, r1, 0x1
	b _081D0656
_081D0640:
	ldrh r0, [r2, 0x12]
	cmp r0, 0
	beq _081D065C
	ldrh r1, [r2, 0xC]
	ldrh r0, [r2, 0xE]
	subs r0, r1, r0
	ldrh r1, [r2, 0x12]
	cmp r0, r1
	blt _081D0654
	subs r0, r1, 0x1
_081D0654:
	adds r0, 0x1B
_081D0656:
	strh r0, [r2, 0xC]
_081D0658:
	movs r0, 0x1
	b _081D065E
_081D065C:
	movs r0, 0
_081D065E:
	pop {r1}
	bx r1
	thumb_func_end sub_81D061C

	thumb_func_start sub_81D0664
sub_81D0664: @ 81D0664
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r4, [r5, 0xC]
	adds r0, r4, 0
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _081D067C
	movs r0, 0
	b _081D0682
_081D067C:
	subs r0, r4, 0x1
	strh r0, [r5, 0xC]
	movs r0, 0x1
_081D0682:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0664

	thumb_func_start sub_81D0688
sub_81D0688: @ 81D0688
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r4, [r5, 0xC]
	adds r0, r4, 0
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0x7
	bgt _081D06BC
	cmp r4, 0x1A
	bhi _081D06AC
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	cmp r4, r0
	bge _081D06BC
	b _081D06B4
_081D06AC:
	ldrh r0, [r5, 0x12]
	subs r0, 0x1
	cmp r1, r0
	bge _081D06BC
_081D06B4:
	adds r0, r4, 0x1
	strh r0, [r5, 0xC]
	movs r0, 0x1
	b _081D06BE
_081D06BC:
	movs r0, 0
_081D06BE:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0688

	thumb_func_start sub_81D06C4
sub_81D06C4: @ 81D06C4
	push {lr}
	movs r0, 0xD
	bl GetSubstructPtr
	ldr r0, [r0, 0x8]
	ldrh r0, [r0, 0x2]
	pop {r1}
	bx r1
	thumb_func_end sub_81D06C4

	thumb_func_start sub_81D06D4
sub_81D06D4: @ 81D06D4
	push {lr}
	movs r0, 0xD
	bl GetSubstructPtr
	ldr r0, [r0, 0x8]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_81D06D4

	thumb_func_start sub_81D06E4
sub_81D06E4: @ 81D06E4
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	movs r0, 0xD
	bl GetSubstructPtr
	ldr r1, [r0, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 2
	adds r0, 0x4
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xE
	bne _081D0730
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r5, 0
	bl GetMonData
	adds r0, r4, 0
	bl GetLevelFromMonExp
	strb r0, [r7]
	adds r0, r4, 0
	bl GetMonGender
	strb r0, [r6]
	b _081D0752
	.pool
_081D0730:
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	bl GetBoxedMonPtr
	adds r4, r0, 0
	bl GetBoxMonGender
	strb r0, [r6]
	adds r0, r4, 0
	bl GetLevelFromBoxMonExp
	strb r0, [r7]
	adds r0, r4, 0
	movs r1, 0x2
	adds r2, r5, 0
	bl GetBoxMonData
_081D0752:
	adds r0, r5, 0
	bl StringGetEnd10
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D06E4

	thumb_func_start sub_81D0760
sub_81D0760: @ 81D0760
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r7, r2, 0
	movs r0, 0xD
	bl GetSubstructPtr
	ldr r1, [r0, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 2
	adds r0, 0x4
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xE
	bne _081D07AC
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [r6]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	b _081D07D0
	.pool
_081D07AC:
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	bl GetBoxedMonPtr
	adds r4, r0, 0
	movs r1, 0xB
	bl GetBoxMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0
	bl GetBoxMonData
	str r0, [r6]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBoxMonData
_081D07D0:
	str r0, [r7]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D0760

	thumb_func_start sub_81D07D8
sub_81D07D8: @ 81D07D8
	push {lr}
	movs r0, 0xD
	bl GetSubstructPtr
	ldr r1, [r0, 0x8]
	ldrh r0, [r1, 0x2]
	lsls r0, 2
	adds r0, 0x4
	adds r1, r0
	ldrb r0, [r1]
	cmp r0, 0xE
	beq _081D07FA
	ldrb r1, [r1, 0x1]
	movs r2, 0x52
	bl GetBoxMonDataAt
	b _081D080A
_081D07FA:
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x52
	bl GetMonData
_081D080A:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D07D8

	thumb_func_start sub_81D0814
sub_81D0814: @ 81D0814
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r5, r0, 0
	ldr r0, [r5, 0x8]
	ldrh r1, [r0, 0x2]
	lsls r1, 2
	adds r1, 0x4
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, 0xE
	bne _081D0848
	ldrb r1, [r1, 0x1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x53
	bl GetMonData
	b _081D0852
	.pool
_081D0848:
	ldrb r0, [r1]
	ldrb r1, [r1, 0x1]
	movs r2, 0x53
	bl GetBoxMonDataAt
_081D0852:
	mov r12, r0
	movs r0, 0
	strh r0, [r5, 0x10]
	strh r0, [r5, 0x12]
	movs r6, 0
	ldr r0, =gUnknown_086237F8
	mov r9, r0
	mov r10, r9
_081D0862:
	lsls r2, r6, 2
	mov r3, r9
	adds r1, r2, r3
	movs r0, 0x1
	ldrb r3, [r1]
	lsls r0, r3
	subs r4, r0, 0x1
	mov r0, r12
	ands r4, r0
	ldrb r0, [r1, 0x3]
	adds r7, r2, 0
	cmp r0, 0
	bne _081D08AC
	movs r3, 0
	adds r6, 0x1
	mov r8, r6
	cmp r3, r4
	bge _081D08D6
	adds r6, r5, 0
	adds r6, 0x14
	mov r1, r10
	adds r0, r7, r1
	ldrb r2, [r0, 0x2]
_081D0890:
	ldrh r0, [r5, 0x10]
	adds r1, r0, 0x1
	strh r1, [r5, 0x10]
	lsls r0, 16
	lsrs r0, 14
	adds r0, r6, r0
	adds r1, r2, r3
	str r1, [r0]
	adds r3, 0x1
	cmp r3, r4
	blt _081D0890
	b _081D08D6
	.pool
_081D08AC:
	movs r3, 0
	adds r6, 0x1
	mov r8, r6
	cmp r3, r4
	bge _081D08D6
	adds r6, r5, 0
	adds r6, 0x78
	mov r1, r10
	adds r0, r7, r1
	ldrb r2, [r0, 0x2]
_081D08C0:
	ldrh r0, [r5, 0x12]
	adds r1, r0, 0x1
	strh r1, [r5, 0x12]
	lsls r0, 16
	lsrs r0, 14
	adds r0, r6, r0
	adds r1, r2, r3
	str r1, [r0]
	adds r3, 0x1
	cmp r3, r4
	blt _081D08C0
_081D08D6:
	mov r3, r9
	adds r0, r7, r3
	mov r1, r12
	ldrb r0, [r0]
	lsrs r1, r0
	mov r12, r1
	mov r6, r8
	cmp r6, 0x10
	bls _081D0862
	ldrh r0, [r5, 0x10]
	cmp r0, 0
	beq _081D0900
	subs r0, 0x1
	movs r1, 0x9
	bl __divsi3
	lsls r1, r0, 3
	adds r1, r0
	movs r0, 0
	strh r1, [r5, 0xE]
	b _081D0904
_081D0900:
	strh r0, [r5, 0xE]
	movs r0, 0x1B
_081D0904:
	strh r0, [r5, 0xC]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81D0814

	thumb_func_start sub_81D0914
sub_81D0914: @ 81D0914
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xD
	bl GetSubstructPtr
	ldrh r1, [r0, 0x10]
	str r1, [r4]
	adds r0, 0x14
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0914

	thumb_func_start sub_81D092C
sub_81D092C: @ 81D092C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xD
	bl GetSubstructPtr
	ldrh r1, [r0, 0x12]
	str r1, [r4]
	adds r0, 0x78
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D092C

	thumb_func_start sub_81D0944
sub_81D0944: @ 81D0944
	push {lr}
	movs r0, 0xD
	bl GetSubstructPtr
	ldrh r0, [r0, 0xC]
	pop {r1}
	bx r1
	thumb_func_end sub_81D0944

	thumb_func_start sub_81D0954
sub_81D0954: @ 81D0954
	push {lr}
	movs r0, 0xD
	bl GetSubstructPtr
	adds r1, r0, 0
	ldrh r0, [r1, 0xC]
	cmp r0, 0x18
	ble _081D096C
	subs r0, 0x1B
	lsls r0, 2
	adds r1, 0x78
	b _081D0970
_081D096C:
	lsls r0, 2
	adds r1, 0x14
_081D0970:
	adds r1, r0
	ldr r0, [r1]
	pop {r1}
	bx r1
	thumb_func_end sub_81D0954

	thumb_func_start sub_81D0978
sub_81D0978: @ 81D0978
	push {r4,lr}
	ldr r1, =0x0000101c
	movs r0, 0xE
	bl AllocSubstruct
	adds r4, r0, 0
	cmp r4, 0
	beq _081D09A8
	ldr r0, =sub_81D0A6C
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r4, 0x4]
	ldr r0, =sub_81D0A58
	str r0, [r4]
	movs r0, 0x1
	b _081D09AA
	.pool
_081D09A8:
	movs r0, 0
_081D09AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0978

	thumb_func_start sub_81D09B0
sub_81D09B0: @ 81D09B0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl GetSubstructPtr
	adds r5, r0, 0
	ldr r0, =gUnknown_08624BA0
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	movs r1, 0x1
	bl CreateLoopedTask
	str r0, [r5, 0x4]
	ldr r0, =sub_81D0A58
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D09B0

	thumb_func_start sub_81D09E0
sub_81D09E0: @ 81D09E0
	push {lr}
	movs r0, 0xE
	bl GetSubstructPtr
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	bx r1
	thumb_func_end sub_81D09E0

	thumb_func_start sub_81D09F4
sub_81D09F4: @ 81D09F4
	push {r4,lr}
	movs r0, 0xE
	bl GetSubstructPtr
	adds r4, r0, 0
	ldrb r0, [r4, 0xA]
	bl RemoveWindow
	ldrb r0, [r4, 0x8]
	bl RemoveWindow
	ldrb r0, [r4, 0xC]
	bl RemoveWindow
	ldrb r0, [r4, 0xE]
	bl RemoveWindow
	adds r0, r4, 0
	bl sub_81D1178
	movs r0, 0x9
	bl FreeSpriteTilesByTag
	movs r0, 0xF
	bl FreeSpritePaletteByTag
	movs r0, 0x10
	bl FreeSpritePaletteByTag
	movs r0, 0x11
	bl FreeSpritePaletteByTag
	movs r0, 0x12
	bl FreeSpritePaletteByTag
	movs r0, 0x13
	bl FreeSpritePaletteByTag
	ldr r0, [r4, 0x14]
	bl FreeSpriteOamMatrix
	ldr r0, [r4, 0x14]
	bl DestroySprite
	movs r0, 0xE
	bl FreePokenavSubstruct
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D09F4

	thumb_func_start sub_81D0A58
sub_81D0A58: @ 81D0A58
	push {lr}
	movs r0, 0xE
	bl GetSubstructPtr
	ldr r0, [r0, 0x4]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	thumb_func_end sub_81D0A58

	thumb_func_start sub_81D0A6C
sub_81D0A6C: @ 81D0A6C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	movs r0, 0xE
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x9
	bls _081D0A80
	b _081D0C48
_081D0A80:
	lsls r0, r4, 2
	ldr r1, =_081D0A90
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D0A90:
	.4byte _081D0AB8
	.4byte _081D0B04
	.4byte _081D0B74
	.4byte _081D0B88
	.4byte _081D0B9C
	.4byte _081D0BB0
	.4byte _081D0BC4
	.4byte _081D0BD8
	.4byte _081D0BE8
	.4byte _081D0C3C
_081D0AB8:
	ldr r0, =gUnknown_08624B98
	movs r1, 0x2
	bl InitBgTemplates
	ldr r1, =gUnknown_08DDE030
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	adds r1, r5, 0
	adds r1, 0x1C
	movs r0, 0x2
	bl SetBgTilemapBuffer
	ldr r1, =gUnknown_08DDE12C
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	ldr r0, =gUnknown_08DDE010
	movs r1, 0x10
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	b _081D0BBA
	.pool
_081D0B04:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	beq _081D0B12
	b _081D0C44
_081D0B12:
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_8199DF0
	ldr r1, =gUnknown_086240B8
	str r4, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0x1
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, =0x0000081c
	adds r1, r5, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect_Palette0
	ldr r0, =gUnknown_08623FF8
	movs r1, 0x20
	movs r2, 0xA0
	bl CopyPaletteIntoBufferUnfaded
	ldr r0, =gUnknown_08624098
	movs r1, 0xA0
	movs r2, 0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, 0x1
	b _081D0BBC
	.pool
_081D0B74:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D0E60
	movs r0, 0
	b _081D0C4A
_081D0B88:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D0FCC
	movs r0, 0
	b _081D0C4A
_081D0B9C:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D10A4
	movs r0, 0
	b _081D0C4A
_081D0BB0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
_081D0BBA:
	movs r0, 0x2
_081D0BBC:
	bl CopyBgTilemapBufferToVram
	movs r0, 0
	b _081D0C4A
_081D0BC4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D1148
	movs r0, 0x1
	b _081D0C4A
_081D0BD8:
	adds r0, r5, 0
	bl sub_81D12D8
	movs r0, 0xA
	bl sub_81C7BA4
	movs r0, 0
	b _081D0C4A
_081D0BE8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0C44
	adds r0, r5, 0
	bl sub_81D13FC
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x3
	bl HideBg
	movs r0, 0x1
	bl sub_81C7AC0
	movs r0, 0
	b _081D0C4A
_081D0C3C:
	bl IsPaletteFadeActive
	cmp r0, 0
	beq _081D0C48
_081D0C44:
	movs r0, 0x2
	b _081D0C4A
_081D0C48:
	movs r0, 0x4
_081D0C4A:
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0A6C

	thumb_func_start sub_81D0C54
sub_81D0C54: @ 81D0C54
	push {lr}
	cmp r0, 0
	beq _081D0C60
	cmp r0, 0x1
	beq _081D0C70
	b _081D0C7C
_081D0C60:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C7AC0
	movs r0, 0
	b _081D0C7E
_081D0C70:
	bl IsPaletteFadeActive
	cmp r0, 0
	beq _081D0C7C
	movs r0, 0x2
	b _081D0C7E
_081D0C7C:
	movs r0, 0x4
_081D0C7E:
	pop {r1}
	bx r1
	thumb_func_end sub_81D0C54

	thumb_func_start sub_81D0C84
sub_81D0C84: @ 81D0C84
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r0, 0xE
	bl GetSubstructPtr
	adds r4, r0, 0
	cmp r5, 0x6
	bhi _081D0D24
	lsls r0, r5, 2
	ldr r1, =_081D0CA4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D0CA4:
	.4byte _081D0CC0
	.4byte _081D0CD0
	.4byte _081D0CE4
	.4byte _081D0CEE
	.4byte _081D0CF8
	.4byte _081D0D02
	.4byte _081D0D16
_081D0CC0:
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81D11D8
	movs r0, 0
	b _081D0D26
_081D0CD0:
	adds r0, r4, 0
	bl sub_81D1234
	cmp r0, 0
	bne _081D0D20
	adds r0, r4, 0
	bl sub_81D0FF0
	movs r0, 0x1
	b _081D0D26
_081D0CE4:
	adds r0, r4, 0
	bl sub_81D12D8
	movs r0, 0x1
	b _081D0D26
_081D0CEE:
	adds r0, r4, 0
	bl sub_81D10D0
	movs r0, 0x1
	b _081D0D26
_081D0CF8:
	adds r0, r4, 0
	bl sub_81D0E84
	movs r0, 0x1
	b _081D0D26
_081D0D02:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _081D0D20
	adds r0, r4, 0
	bl sub_81D11FC
	movs r0, 0
	b _081D0D26
_081D0D16:
	adds r0, r4, 0
	bl sub_81D1234
	cmp r0, 0
	beq _081D0D24
_081D0D20:
	movs r0, 0x2
	b _081D0D26
_081D0D24:
	movs r0, 0x4
_081D0D26:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0C84

	thumb_func_start sub_81D0D2C
sub_81D0D2C: @ 81D0D2C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D0D5C
	cmp r4, 0x1
	bgt _081D0D46
	cmp r4, 0
	beq _081D0D4C
	b _081D0D84
_081D0D46:
	cmp r4, 0x2
	beq _081D0D76
	b _081D0D84
_081D0D4C:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81D1448
	movs r0, 0
	b _081D0D86
_081D0D5C:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0D80
	adds r0, r5, 0
	bl sub_81D0EFC
	movs r0, 0xB
	bl sub_81C7BA4
	movs r0, 0
	b _081D0D86
_081D0D76:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D0D84
_081D0D80:
	movs r0, 0x2
	b _081D0D86
_081D0D84:
	movs r0, 0x4
_081D0D86:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0D2C

	thumb_func_start sub_81D0D8C
sub_81D0D8C: @ 81D0D8C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D0DC0
	cmp r4, 0x1
	bgt _081D0DA6
	cmp r4, 0
	beq _081D0DB0
	b _081D0DF6
_081D0DA6:
	cmp r4, 0x2
	beq _081D0DD4
	cmp r4, 0x3
	beq _081D0DE8
	b _081D0DF6
_081D0DB0:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81D1500
	movs r0, 0
	b _081D0DF8
_081D0DC0:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0DF2
	adds r0, r5, 0
	bl sub_81D1448
	movs r0, 0
	b _081D0DF8
_081D0DD4:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0DF2
	adds r0, r5, 0
	bl sub_81D0EFC
	movs r0, 0
	b _081D0DF8
_081D0DE8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D0DF6
_081D0DF2:
	movs r0, 0x2
	b _081D0DF8
_081D0DF6:
	movs r0, 0x4
_081D0DF8:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0D8C

	thumb_func_start sub_81D0E00
sub_81D0E00: @ 81D0E00
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0xE
	bl GetSubstructPtr
	adds r5, r0, 0
	cmp r4, 0x1
	beq _081D0E30
	cmp r4, 0x1
	bgt _081D0E1A
	cmp r4, 0
	beq _081D0E20
	b _081D0E58
_081D0E1A:
	cmp r4, 0x2
	beq _081D0E4A
	b _081D0E58
_081D0E20:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81D1500
	movs r0, 0
	b _081D0E5A
_081D0E30:
	adds r0, r5, 0
	bl sub_81D1524
	cmp r0, 0
	bne _081D0E54
	adds r0, r5, 0
	bl sub_81D0E84
	movs r0, 0xA
	bl sub_81C7BA4
	movs r0, 0
	b _081D0E5A
_081D0E4A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	beq _081D0E58
_081D0E54:
	movs r0, 0x2
	b _081D0E5A
_081D0E58:
	movs r0, 0x4
_081D0E5A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D0E00


	.align 2, 0 @ Don't pad with nop.
