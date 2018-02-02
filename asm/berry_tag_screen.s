	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text




	thumb_func_start sub_817836C
sub_817836C: @ 817836C
	push {lr}
	ldr r0, =sBerryTag
	ldr r0, [r0]
	ldr r1, =0x00001802
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	bl sub_80D510C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817836C

	thumb_func_start sub_817839C
sub_817839C: @ 817839C
	push {r4,lr}
	movs r0, 0x40
	bl sub_80D518C
	ldr r4, =sBerryTag
	ldr r1, [r4]
	ldr r2, =0x00001803
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x68
	bl sub_80D518C
	ldr r1, [r4]
	ldr r2, =0x00001804
	adds r1, r2
	strb r0, [r1]
	movs r0, 0x90
	bl sub_80D518C
	ldr r1, [r4]
	ldr r2, =0x00001805
	adds r1, r2
	strb r0, [r1]
	movs r0, 0xB8
	bl sub_80D518C
	ldr r1, [r4]
	ldr r2, =0x00001806
	adds r1, r2
	strb r0, [r1]
	movs r0, 0xE0
	bl sub_80D518C
	ldr r1, [r4]
	ldr r2, =0x00001807
	adds r1, r2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817839C

	thumb_func_start sub_8178404
sub_8178404: @ 8178404
	push {r4,r5,lr}
	ldr r4, =sBerryTag
	ldr r0, [r4]
	movs r1, 0xC0
	lsls r1, 5
	adds r0, r1
	ldrb r0, [r0]
	bl GetBerryInfo
	adds r5, r0, 0
	ldrb r0, [r5, 0x15]
	cmp r0, 0
	beq _08178448
	ldr r3, =gSprites
	ldr r0, [r4]
	ldr r1, =0x00001803
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	b _08178462
	.pool
_08178448:
	ldr r3, =gSprites
	ldr r0, [r4]
	ldr r1, =0x00001803
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
_08178462:
	strb r1, [r0]
	adds r4, r3, 0
	ldrb r0, [r5, 0x16]
	cmp r0, 0
	beq _0817849C
	ldr r3, =sBerryTag
	ldr r0, [r3]
	ldr r1, =0x00001804
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	b _081784B6
	.pool
_0817849C:
	ldr r3, =sBerryTag
	ldr r0, [r3]
	ldr r1, =0x00001804
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
_081784B6:
	strb r1, [r0]
	ldrb r0, [r5, 0x17]
	cmp r0, 0
	beq _081784E8
	ldr r0, [r3]
	ldr r1, =0x00001805
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	b _08178500
	.pool
_081784E8:
	ldr r0, [r3]
	ldr r1, =0x00001805
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
_08178500:
	strb r1, [r0]
	ldrb r0, [r5, 0x18]
	cmp r0, 0
	beq _0817852C
	ldr r0, [r3]
	ldr r1, =0x00001806
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	b _08178544
	.pool
_0817852C:
	ldr r0, [r3]
	ldr r1, =0x00001806
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
_08178544:
	strb r1, [r0]
	ldrb r0, [r5, 0x19]
	cmp r0, 0
	beq _08178570
	ldr r0, [r3]
	ldr r1, =0x00001807
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	b _08178588
	.pool
_08178570:
	ldr r0, [r3]
	ldr r1, =0x00001807
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
_08178588:
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8178404

	thumb_func_start sub_8178594
sub_8178594: @ 8178594
	push {r4,lr}
	movs r4, 0
_08178598:
	ldr r0, =sBerryTag
	ldr r0, [r0]
	ldr r1, =0x00001803
	adds r0, r1
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _08178598
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8178594

	thumb_func_start sub_81785D0
sub_81785D0: @ 81785D0
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8178610
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81785D0

	thumb_func_start sub_8178610
sub_8178610: @ 8178610
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08178642
	bl sub_817836C
	bl sub_8178594
	ldr r0, =sBerryTag
	ldr r0, [r0]
	bl Free
	bl FreeAllWindowBuffers
	ldr r0, =bag_menu_mail_related
	bl SetMainCallback2
	adds r0, r4, 0
	bl DestroyTask
_08178642:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8178610

	thumb_func_start sub_8178654
sub_8178654: @ 8178654
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	adds r4, r2, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081786A6
	ldr r3, =gMain
	ldrh r0, [r3, 0x30]
	movs r1, 0xF0
	ands r1, r0
	cmp r1, 0x40
	bne _08178688
	movs r1, 0x1
	negs r1, r1
	adds r0, r2, 0
	bl sub_81786AC
	b _081786A6
	.pool
_08178688:
	cmp r1, 0x80
	bne _08178696
	adds r0, r2, 0
	movs r1, 0x1
	bl sub_81786AC
	b _081786A6
_08178696:
	ldrh r1, [r3, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081786A6
	adds r0, r4, 0
	bl sub_81785D0
_081786A6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8178654

	thumb_func_start sub_81786AC
sub_81786AC: @ 81786AC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r2, =gTasks + 0x8
	adds r4, r0, r2
	ldr r2, =gUnknown_0203CE58
	ldrh r0, [r2, 0xE]
	ldrh r2, [r2, 0x18]
	adds r0, r2
	lsls r0, 16
	asrs r0, 16
	lsrs r7, r1, 24
	asrs r6, r1, 24
	adds r0, r6
	cmp r0, 0x2D
	bhi _08178718
	lsls r1, r0, 16
	lsrs r1, 16
	movs r0, 0x4
	bl BagGetItemIdByPocketPosition
	lsls r0, 16
	cmp r0, 0
	beq _08178718
	cmp r6, 0
	bge _081786F4
	movs r0, 0x2
	b _081786F6
	.pool
_081786F4:
	movs r0, 0x1
_081786F6:
	strh r0, [r4, 0x2]
	movs r0, 0
	strh r0, [r4]
	movs r0, 0x5
	bl PlaySE
	lsls r0, r7, 24
	asrs r0, 24
	bl sub_8178728
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81787AC
	str r1, [r0]
_08178718:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81786AC

	thumb_func_start sub_8178728
sub_8178728: @ 8178728
	push {r4-r6,lr}
	ldr r5, =gUnknown_0203CE70
	adds r6, r5, 0
	subs r6, 0xA
	lsls r0, 24
	asrs r4, r0, 24
	cmp r4, 0
	ble _08178764
	ldrh r0, [r6]
	cmp r0, 0x3
	bls _08178752
	ldrh r1, [r5]
	adds r1, 0x8
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4
	bl BagGetItemIdByPocketPosition
	lsls r0, 16
	cmp r0, 0
	bne _08178760
_08178752:
	ldrh r0, [r6]
	adds r0, r4
	strh r0, [r6]
	b _0817877A
	.pool
_08178760:
	ldrh r0, [r5]
	b _08178776
_08178764:
	ldrh r1, [r6]
	cmp r1, 0x3
	bhi _08178770
	ldrh r0, [r5]
	cmp r0, 0
	bne _08178776
_08178770:
	adds r0, r1, r4
	strh r0, [r6]
	b _0817877A
_08178776:
	adds r0, r4
	strh r0, [r5]
_0817877A:
	ldrh r1, [r6]
	ldrh r5, [r5]
	adds r1, r5
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x4
	bl BagGetItemIdByPocketPosition
	lsls r0, 16
	lsrs r0, 16
	bl ItemIdToBerryType
	ldr r1, =sBerryTag
	ldr r1, [r1]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0xC0
	lsls r2, 5
	adds r1, r2
	strh r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8178728

	thumb_func_start sub_81787AC
sub_81787AC: @ 81787AC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	ldrh r0, [r6]
	adds r0, 0x10
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r6]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	cmp r0, 0x1
	bne _08178828
	movs r2, 0
	ldrsh r0, [r6, r2]
	cmp r0, 0x70
	beq _08178888
	cmp r0, 0x70
	bgt _081787FE
	cmp r0, 0x40
	beq _0817881A
	cmp r0, 0x40
	bgt _081787F4
	cmp r0, 0x30
	beq _08178898
	b _081788A6
	.pool
_081787F4:
	cmp r0, 0x50
	beq _0817888E
	cmp r0, 0x60
	beq _08178820
	b _081788A6
_081787FE:
	cmp r0, 0xA0
	beq _08178824
	cmp r0, 0xA0
	bgt _08178810
	cmp r0, 0x80
	beq _08178882
	cmp r0, 0x90
	beq _08178878
	b _081788A6
_08178810:
	cmp r0, 0xB0
	beq _08178872
	cmp r0, 0xC0
	beq _0817886C
	b _081788A6
_0817881A:
	bl sub_8178110
	b _081788A6
_08178820:
	movs r0, 0x1
	b _0817889A
_08178824:
	movs r0, 0x2
	b _0817889A
_08178828:
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0x70
	beq _0817887E
	cmp r0, 0x70
	bgt _0817884C
	cmp r0, 0x40
	beq _0817886C
	cmp r0, 0x40
	bgt _08178842
	cmp r0, 0x30
	beq _08178868
	b _081788A6
_08178842:
	cmp r0, 0x50
	beq _08178872
	cmp r0, 0x60
	beq _08178878
	b _081788A6
_0817884C:
	cmp r0, 0xA0
	beq _0817888E
	cmp r0, 0xA0
	bgt _0817885E
	cmp r0, 0x80
	beq _08178882
	cmp r0, 0x90
	beq _08178888
	b _081788A6
_0817885E:
	cmp r0, 0xB0
	beq _08178898
	cmp r0, 0xC0
	beq _081788A2
	b _081788A6
_08178868:
	movs r0, 0x2
	b _0817889A
_0817886C:
	bl sub_8178304
	b _081788A6
_08178872:
	bl sub_81782D0
	b _081788A6
_08178878:
	bl sub_8178404
	b _081788A6
_0817887E:
	movs r0, 0x1
	b _0817889A
_08178882:
	bl sub_8178250
	b _081788A6
_08178888:
	bl sub_8178174
	b _081788A6
_0817888E:
	bl sub_817836C
	bl sub_8178338
	b _081788A6
_08178898:
	movs r0, 0
_0817889A:
	movs r1, 0
	bl FillWindowPixelBuffer
	b _081788A6
_081788A2:
	bl sub_8178110
_081788A6:
	movs r2, 0x2
	ldrsh r0, [r6, r2]
	cmp r0, 0x1
	bne _081788B8
	ldrh r0, [r6]
	negs r0, r0
	lsls r0, 16
	lsrs r5, r0, 16
	b _081788BA
_081788B8:
	ldrh r5, [r6]
_081788BA:
	ldr r2, =gSprites
	ldr r3, =sBerryTag
	ldr r0, [r3]
	ldr r1, =0x00001802
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	strh r5, [r0, 0x26]
	movs r4, 0
	adds r7, r2, 0
	ldr r2, =0x00001803
_081788D6:
	ldr r0, [r3]
	adds r0, r2
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	strh r5, [r0, 0x26]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x4
	bls _081788D6
	movs r4, 0x80
	lsls r4, 5
	ldrb r2, [r6, 0x2]
	movs r0, 0x1
	adds r1, r4, 0
	bl ChangeBgY
	ldrb r2, [r6, 0x2]
	movs r0, 0x2
	adds r1, r4, 0
	bl ChangeBgY
	movs r2, 0
	ldrsh r0, [r6, r2]
	cmp r0, 0
	bne _08178922
	ldr r0, =gTasks
	mov r2, r8
	lsls r1, r2, 2
	add r1, r8
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_8178654
	str r0, [r1]
_08178922:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81787AC

	.align 2, 0 @ Don't pad with nop.
