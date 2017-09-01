	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8145354
sub_8145354: @ 8145354
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	movs r0, 0
	mov r8, r0
	ldr r0, =gUnknown_030061EC
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081453F8
	cmp r0, 0x1
	bgt _0814537C
	cmp r0, 0
	beq _08145382
	b _0814544A
	.pool
_0814537C:
	cmp r0, 0x2
	beq _08145434
	b _0814544A
_08145382:
	ldr r5, =gUnknown_0203AB90
	ldr r0, [r5]
	cmp r0, 0
	bne _0814539E
	movs r0, 0x1C
	bl AllocZeroed
	str r0, [r5]
	ldr r4, =gUnknown_0203AB94
	adds r0, r7, 0
	movs r1, 0x7
	bl GetWindowAttribute
	str r0, [r4]
_0814539E:
	ldr r1, [r5]
	ldrh r0, [r6]
	movs r2, 0
	strh r0, [r1, 0x14]
	ldrb r0, [r6, 0x5]
	strb r0, [r1, 0x16]
	ldr r0, [r5]
	strb r2, [r0, 0x1A]
	ldr r0, [r5]
	strb r2, [r0, 0x1B]
	ldr r0, [r5]
	strb r2, [r0, 0x10]
	ldr r1, [r5]
	movs r0, 0x1C
	strb r0, [r1, 0x12]
	ldr r0, [r5]
	strb r2, [r0, 0x11]
	ldrb r1, [r6, 0x4]
	lsls r1, 19
	negs r1, r1
	asrs r1, 16
	adds r0, r7, 0
	movs r2, 0x1
	bl sub_8145824
	movs r4, 0
_081453D2:
	adds r0, r7, 0
	ldr r1, =gUnknown_085B8C10
	movs r2, 0x20
	adds r3, r4, 0
	bl CopyToWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xDF
	bls _081453D2
	b _08145420
	.pool
_081453F8:
	movs r4, 0
	ldr r1, =gUnknown_0203AB90
	ldr r0, [r1]
	ldrb r0, [r0, 0x16]
	lsls r0, 3
	cmp r8, r0
	bge _08145420
	adds r5, r1, 0
_08145408:
	adds r0, r4, 0
	movs r1, 0
	bl sub_81456A8
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, [r5]
	ldrb r0, [r0, 0x16]
	lsls r0, 3
	cmp r4, r0
	blt _08145408
_08145420:
	ldr r1, =gUnknown_030061EC
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _0814544A
	.pool
_08145434:
	adds r0, r7, 0
	bl sub_8145814
	ldr r0, =gUnknown_085B8BF0
	ldrb r1, [r6, 0x3]
	lsls r1, 4
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x1
	mov r8, r0
_0814544A:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8145354

	thumb_func_start sub_814545C
sub_814545C: @ 814545C
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_8145814
	adds r0, r4, 0
	bl sub_8145648
	ldr r2, =gUnknown_0203AB90
	ldr r1, [r2]
	ldrb r0, [r1, 0x1B]
	cmp r0, 0
	beq _0814547E
	subs r0, 0x1
	strb r0, [r1, 0x1B]
_0814547E:
	ldr r1, [r2]
	ldrb r0, [r1, 0x1A]
	cmp r0, 0
	beq _081454A4
	subs r0, 0x1
	strb r0, [r1, 0x1A]
	ldr r1, [r2]
	ldrb r0, [r1, 0x1A]
	cmp r0, 0
	bne _081454A4
	ldrh r0, [r1, 0x18]
	bl sub_8145588
	bl sub_814560C
	b _0814552A
	.pool
_081454A4:
	ldr r5, =gUnknown_0203AB90
	ldr r0, [r5]
	ldrb r0, [r0, 0x10]
	cmp r0, 0
	bne _081454B8
	bl sub_814560C
	b _0814552A
	.pool
_081454B8:
	cmp r0, 0x1
	bne _081454C2
	bl sub_81455A8
	b _081454E6
_081454C2:
	cmp r0, 0x8
	bls _081454E6
	bl sub_80A36EC
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081454DC
	bl sub_814560C
	ldr r0, [r5]
	strb r4, [r0, 0x10]
	b _0814552A
_081454DC:
	bl sub_81455A8
	ldr r1, [r5]
	movs r0, 0x1
	strb r0, [r1, 0x10]
_081454E6:
	ldr r5, =gUnknown_0203AB90
	ldr r1, [r5]
	ldrb r4, [r1, 0x10]
	subs r4, 0x1
	lsls r4, 25
	lsrs r4, 24
	ldrb r0, [r1, 0x16]
	lsls r0, 3
	ldrb r2, [r1, 0x11]
	adds r0, r2
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4
	ldrb r1, [r1]
	bl sub_81456A8
	ldr r1, [r5]
	ldrb r0, [r1, 0x16]
	lsls r0, 3
	ldrb r2, [r1, 0x11]
	adds r0, r2
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	adds r4, 0x1
	adds r1, r4
	ldrb r1, [r1]
	bl sub_81456A8
	ldr r1, [r5]
	ldrb r0, [r1, 0x10]
	adds r0, 0x1
	strb r0, [r1, 0x10]
_0814552A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814545C

	thumb_func_start sub_8145534
sub_8145534: @ 8145534
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r5, r4, 0
	ldr r0, =gMPlay_BGM
	ldr r0, [r0, 0x4]
	cmp r0, 0
	bge _08145582
	ldr r6, =gUnknown_0203AB90
	ldr r1, [r6]
	ldrb r0, [r1, 0x1A]
	cmp r0, 0
	bne _08145582
	ldrb r0, [r1, 0x1B]
	cmp r0, 0
	bne _08145582
	movs r0, 0x4
	strb r0, [r1, 0x1B]
	bl sub_80A36EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0814557C
	bl sub_80A36B4
	ldr r1, [r6]
	strh r4, [r1, 0x18]
	movs r0, 0x2
	strb r0, [r1, 0x1A]
	b _08145582
	.pool
_0814557C:
	adds r0, r5, 0
	bl sub_8145588
_08145582:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8145534

	thumb_func_start sub_8145588
sub_8145588: @ 8145588
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	movs r2, 0x7D
	movs r3, 0xA
	bl sub_80A32C0
	ldr r0, =gUnknown_0203AB90
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x10]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145588

	thumb_func_start sub_81455A8
sub_81455A8: @ 81455A8
	push {r4,lr}
	ldr r3, =gPcmDmaCounter
	movs r0, 0
	ldrsb r0, [r3, r0]
	cmp r0, 0x1
	bgt _081455C0
	ldr r0, =gSoundInfo + 0x350
	b _081455D8
	.pool
_081455C0:
	ldr r2, =gSoundInfo
	ldrb r1, [r2, 0xB]
	movs r0, 0
	ldrsb r0, [r3, r0]
	subs r0, 0x1
	subs r1, r0
	ldr r0, [r2, 0x10]
	muls r0, r1
	movs r1, 0xD4
	lsls r1, 2
	adds r2, r1
	adds r0, r2
_081455D8:
	movs r1, 0xC6
	lsls r1, 3
	adds r3, r0, r1
	movs r2, 0
	ldr r4, =gUnknown_0203AB90
_081455E2:
	ldr r1, [r4]
	adds r1, r2
	lsls r0, r2, 1
	adds r0, r3
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	lsls r0, 1
	strb r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _081455E2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81455A8

	thumb_func_start sub_814560C
sub_814560C: @ 814560C
	push {r4,lr}
	ldr r4, =gUnknown_0203AB90
	ldr r1, [r4]
	ldrb r0, [r1, 0x16]
	lsls r0, 3
	ldrb r1, [r1, 0x11]
	adds r0, r1
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_81456A8
	ldr r1, [r4]
	ldrb r0, [r1, 0x16]
	lsls r0, 3
	ldrb r1, [r1, 0x11]
	adds r0, r1
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_81456A8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814560C

	thumb_func_start sub_8145648
sub_8145648: @ 8145648
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gUnknown_0203AB90
	ldr r0, [r4]
	ldrb r1, [r0, 0x11]
	adds r0, r6, 0
	movs r2, 0
	bl sub_8145824
	ldr r1, [r4]
	ldrb r0, [r1, 0x11]
	adds r0, 0x2
	strb r0, [r1, 0x11]
	ldr r1, [r4]
	ldrb r0, [r1, 0x11]
	lsrs r0, 3
	ldrb r1, [r1, 0x16]
	adds r1, r0, r1
	adds r2, r1, 0x1
	adds r0, r2, 0
	asrs r0, 5
	lsls r0, 5
	subs r0, r2, r0
	lsls r0, 16
	lsrs r5, r0, 16
	movs r4, 0
_0814567E:
	lsls r3, r4, 5
	adds r3, r5, r3
	lsls r3, 16
	lsrs r3, 16
	adds r0, r6, 0
	ldr r1, =gUnknown_085B8C10
	movs r2, 0x20
	bl CopyToWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x6
	bls _0814567E
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145648

	thumb_func_start sub_81456A8
sub_81456A8: @ 81456A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	lsls r7, r0, 24
	lsrs r4, r7, 24
	lsls r1, 24
	movs r0, 0xFE
	lsls r0, 23
	adds r1, r0
	lsrs r1, 16
	adds r0, r1, 0
	bl __floatsidf
	ldr r3, _08145768
	ldr r2, _08145764
	bl __divdf3
	bl __fixunsdfsi
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x37
	bls _081456DE
	movs r5, 0x37
_081456DE:
	str r5, [sp]
	movs r6, 0x1
	ands r6, r4
	ldr r0, _0814576C
	ldr r1, [r0]
	lsrs r7, 27
	mov r8, r7
	ldr r0, _08145770
	ldrb r1, [r1, 0x12]
	cmp r5, r1
	bls _08145780
	ldr r3, _08145774
	adds r0, r6, r0
	ldrb r0, [r0]
	mov r9, r0
	movs r7, 0x7
	ands r7, r4
_08145700:
	lsls r1, r5, 1
	lsls r0, r7, 3
	adds r0, r7
	lsls r0, 4
	adds r1, r0
	ldr r2, _08145778
	adds r1, r2
	mov r4, r8
	lsls r0, r4, 5
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, [r3]
	adds r1, r2
	ldrb r0, [r1]
	mov r4, r9
	ands r0, r4
	strb r0, [r1]
	ldr r4, [r3]
	adds r4, r2
	adds r0, r5, 0
	movs r1, 0x3
	str r3, [sp, 0x4]
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	movs r1, 0xF
	ands r0, r1
	lsls r1, r6, 4
	adds r0, r1
	ldr r1, _0814577C
	adds r0, r1
	ldrb r1, [r4]
	ldrb r0, [r0]
	orrs r1, r0
	strb r1, [r4]
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, _0814576C
	ldr r0, [r2]
	ldr r3, [sp, 0x4]
	ldrb r0, [r0, 0x12]
	cmp r5, r0
	bhi _08145700
	b _081457EA
	.align 2, 0
_08145764: .4byte 0x40920000
_08145768: .4byte 0x00000000
_0814576C: .4byte gUnknown_0203AB90
_08145770: .4byte gUnknown_085B8C30
_08145774: .4byte gUnknown_0203AB94
_08145778: .4byte gUnknown_085B8770
_0814577C: .4byte gUnknown_085B8C32
_08145780:
	lsls r3, r6, 4
	mov r10, r3
	ldr r7, _08145804
	adds r0, r6, r0
	ldrb r0, [r0]
	mov r9, r0
	movs r6, 0x7
	ands r6, r4
_08145790:
	lsls r1, r5, 1
	lsls r0, r6, 3
	adds r0, r6
	lsls r0, 4
	adds r1, r0
	ldr r4, _08145808
	adds r1, r4
	mov r2, r8
	lsls r0, r2, 5
	ldrh r1, [r1]
	adds r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, [r7]
	adds r1, r2
	ldrb r0, [r1]
	mov r3, r9
	ands r0, r3
	strb r0, [r1]
	ldr r4, [r7]
	adds r4, r2
	adds r0, r5, 0
	movs r1, 0x3
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x1
	movs r1, 0xF
	ands r0, r1
	add r0, r10
	ldr r1, _0814580C
	adds r0, r1
	ldrb r1, [r4]
	ldrb r0, [r0]
	orrs r1, r0
	strb r1, [r4]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, _08145810
	ldr r0, [r2]
	ldrb r0, [r0, 0x12]
	cmp r5, r0
	bcc _08145790
_081457EA:
	ldr r3, _08145810
	ldr r0, [r3]
	mov r4, sp
	ldrb r4, [r4]
	strb r4, [r0, 0x12]
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_08145804: .4byte gUnknown_0203AB94
_08145808: .4byte gUnknown_085B8770
_0814580C: .4byte gUnknown_085B8C32
_08145810: .4byte gUnknown_0203AB90
	thumb_func_end sub_81456A8

	thumb_func_start sub_8145814
sub_8145814: @ 8145814
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_8145814

	thumb_func_start sub_8145824
sub_8145824: @ 8145824
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r4, r1, 16
	lsls r2, 24
	cmp r2, 0
	bne _08145848
	movs r1, 0
	bl GetWindowAttribute
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 16
	asrs r1, 8
	movs r2, 0
	bl ChangeBgX
_08145848:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8145824

	thumb_func_start sub_8145850
sub_8145850: @ 8145850
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r7, r1, 24
	movs r0, 0
	mov r8, r0
	ldr r6, =gUnknown_030061EC
	ldrb r0, [r6]
	cmp r0, 0
	beq _08145874
	cmp r0, 0x1
	beq _081458B0
	b _081458F8
	.pool
_08145874:
	ldr r5, =gUnknown_0203AB98
	ldr r0, [r5]
	cmp r0, 0
	bne _08145884
	movs r0, 0x8
	bl AllocZeroed
	str r0, [r5]
_08145884:
	ldr r1, =gUnknown_085B8438
	adds r0, r7, 0
	movs r2, 0
	movs r3, 0
	bl CopyToWindowPixelBuffer
	ldr r0, =gUnknown_085B8418
	ldrb r1, [r4, 0x3]
	lsls r1, 4
	movs r2, 0x20
	bl LoadPalette
	ldrb r0, [r6]
	adds r0, 0x1
	strb r0, [r6]
	b _081458F8
	.pool
_081458B0:
	ldr r0, =gUnknown_085B8C80
	bl LoadObjectPics
	ldr r0, =gUnknown_085B8C90
	bl LoadTaggedObjectPalettes
	ldr r0, =gUnknown_085B8C68
	ldrb r1, [r4, 0x4]
	lsls r1, 19
	movs r2, 0xA0
	lsls r2, 14
	adds r1, r2
	asrs r1, 16
	ldrb r2, [r4, 0x5]
	lsls r2, 19
	movs r3, 0xE0
	lsls r3, 14
	adds r2, r3
	asrs r2, 16
	movs r3, 0x1
	bl CreateSprite
	ldr r2, =gUnknown_0203AB98
	ldr r3, [r2]
	lsls r0, 24
	lsrs r0, 24
	movs r4, 0
	strh r0, [r3, 0x4]
	movs r1, 0x20
	strb r1, [r3]
	ldr r0, [r2]
	strb r1, [r0, 0x1]
	ldr r0, [r2]
	strb r4, [r0, 0x2]
	movs r0, 0x1
	mov r8, r0
_081458F8:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8145850

	thumb_func_start sub_8145914
sub_8145914: @ 8145914
	push {r4-r6,lr}
	ldr r4, =gSprites
	ldr r6, =gUnknown_0203AB98
	ldr r0, [r6]
	ldrh r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	bl GetObjectPaletteTagBySlot
	lsls r0, 16
	lsrs r0, 16
	bl FreeObjectPaletteByTag
	ldr r0, [r6]
	ldrh r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	ldr r4, =gUnknown_0203AB90
	ldr r0, [r4]
	bl Free
	movs r5, 0
	str r5, [r4]
	ldr r0, [r6]
	bl Free
	str r5, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145914

	thumb_func_start sub_814596C
sub_814596C: @ 814596C
	push {r4-r7,lr}
	sub sp, 0x14
	adds r7, r0, 0
	ldr r3, =gSprites
	ldr r4, =gUnknown_0203AB98
	ldr r0, [r4]
	ldrh r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrb r2, [r0, 0x1]
	movs r1, 0x4
	negs r1, r1
	ands r1, r2
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0, 0x1]
	ldr r2, [r4]
	ldrh r1, [r2, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x6]
	ldr r0, =gUnknown_0203AB90
	ldr r0, [r0]
	ldrb r1, [r0, 0x10]
	cmp r1, 0x2
	beq _081459E8
	cmp r1, 0x2
	bgt _081459C0
	cmp r1, 0
	beq _081459C6
	b _08145A2E
	.pool
_081459C0:
	cmp r1, 0x6
	beq _08145A20
	b _08145A2E
_081459C6:
	movs r0, 0x20
	strb r0, [r2, 0x1]
	ldr r1, [r4]
	movs r0, 0
	ldrsb r0, [r1, r0]
	cmp r0, 0
	ble _081459E2
	ldrb r0, [r1, 0x2]
	add r4, sp, 0xC
	cmp r0, 0x1
	beq _08145A30
	subs r0, 0x1
	strb r0, [r1, 0x2]
	b _08145A30
_081459E2:
	movs r0, 0x5
	strb r0, [r1, 0x2]
	b _08145A2E
_081459E8:
	movs r3, 0
	movs r2, 0
	add r4, sp, 0xC
	adds r5, r0, 0
_081459F0:
	lsls r1, r3, 24
	asrs r1, 24
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r1, r0
	bge _081459FE
	adds r3, r0, 0
_081459FE:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0xF
	bls _081459F0
	lsls r0, r3, 24
	asrs r0, 24
	movs r1, 0xD0
	muls r0, r1
	cmp r0, 0
	bge _08145A16
	adds r0, 0xFF
_08145A16:
	lsls r0, 16
	asrs r0, 24
	bl sub_8145B24
	b _08145A30
_08145A20:
	ldrb r1, [r0, 0xA]
	movs r0, 0xD0
	muls r0, r1
	lsls r0, 16
	asrs r0, 24
	bl sub_8145B24
_08145A2E:
	add r4, sp, 0xC
_08145A30:
	ldr r0, =gUnknown_0203AB98
	ldr r2, [r0]
	ldrb r5, [r2]
	movs r1, 0
	ldrsb r1, [r2, r1]
	movs r3, 0x1
	ldrsb r3, [r2, r3]
	adds r6, r0, 0
	cmp r1, r3
	beq _08145A82
	cmp r1, r3
	bge _08145A64
	ldrb r0, [r2, 0x2]
	adds r0, r5, r0
	strb r0, [r2]
	ldr r2, [r6]
	movs r1, 0
	ldrsb r1, [r2, r1]
	ldrb r3, [r2, 0x1]
	movs r0, 0x1
	ldrsb r0, [r2, r0]
	cmp r1, r0
	ble _08145A82
	b _08145A7A
	.pool
_08145A64:
	ldrb r0, [r2, 0x2]
	subs r0, r5, r0
	strb r0, [r2]
	ldr r2, [r6]
	movs r1, 0
	ldrsb r1, [r2, r1]
	ldrb r3, [r2, 0x1]
	movs r0, 0x1
	ldrsb r0, [r2, r0]
	cmp r1, r0
	bge _08145A82
_08145A7A:
	strb r3, [r2]
	ldr r1, [r6]
	movs r0, 0
	strb r0, [r1, 0x1]
_08145A82:
	ldr r2, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r2
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 17
	orrs r0, r1
	str r0, [sp, 0x4]
	ldr r0, [r6]
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r1, 24
	lsrs r1, 16
	ldr r0, [sp, 0x8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x8]
	add r0, sp, 0x4
	adds r1, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ObjAffineSet
	add r0, sp, 0xC
	ldrh r1, [r0]
	ldrh r2, [r4, 0x2]
	ldrh r3, [r4, 0x4]
	ldrh r0, [r4, 0x6]
	str r0, [sp]
	movs r0, 0
	bl SetSpriteTransformationMatrix
	ldr r2, =gSineTable
	ldr r0, [r6]
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	adds r0, 0x7F
	movs r1, 0xFF
	ands r0, r1
	lsls r1, r0, 1
	adds r1, r2
	adds r0, 0x40
	lsls r0, 1
	adds r0, r2
	ldrh r2, [r0]
	movs r0, 0
	ldrsh r1, [r1, r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	cmp r0, 0
	bge _08145AF6
	adds r0, 0xFF
_08145AF6:
	asrs r0, 8
	strh r0, [r7, 0x24]
	lsls r1, r2, 16
	asrs r1, 16
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	cmp r0, 0
	bge _08145B0A
	adds r0, 0xFF
_08145B0A:
	asrs r0, 8
	strh r0, [r7, 0x26]
	add sp, 0x14
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_814596C

	thumb_func_start sub_8145B24
sub_8145B24: @ 8145B24
	push {lr}
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x20
	subs r2, r1, r0
	movs r0, 0xFF
	ands r2, r0
	adds r0, r2, 0
	subs r0, 0x21
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xBE
	bhi _08145B40
	movs r2, 0xE0
_08145B40:
	ldr r1, =gUnknown_0203AB98
	ldr r0, [r1]
	strb r2, [r0, 0x1]
	ldr r1, [r1]
	movs r0, 0x5
	strb r0, [r1, 0x2]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8145B24

	.align 2, 0 @ Don't pad with nop.
