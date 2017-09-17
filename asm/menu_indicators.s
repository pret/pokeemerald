	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81AF08C
sub_81AF08C: @ 81AF08C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r3, r1, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r2, r1, r0
	cmp r3, 0x10
	bhi _081AF154
	lsls r0, r3, 2
	ldr r1, =_081AF0B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081AF0B8:
	.4byte _081AF0FC
	.4byte _081AF0FC
	.4byte _081AF100
	.4byte _081AF104
	.4byte _081AF108
	.4byte _081AF10C
	.4byte _081AF110
	.4byte _081AF114
	.4byte _081AF118
	.4byte _081AF11C
	.4byte _081AF122
	.4byte _081AF12A
	.4byte _081AF130
	.4byte _081AF138
	.4byte _081AF140
	.4byte _081AF146
	.4byte _081AF14E
_081AF0FC:
	ldr r0, [r2, 0x4]
	b _081AF158
_081AF100:
	ldrh r0, [r2, 0xC]
	b _081AF158
_081AF104:
	ldrh r0, [r2, 0xE]
	b _081AF158
_081AF108:
	ldrb r0, [r2, 0x10]
	b _081AF158
_081AF10C:
	ldrb r0, [r2, 0x11]
	b _081AF158
_081AF110:
	ldrb r0, [r2, 0x12]
	b _081AF158
_081AF114:
	ldrb r0, [r2, 0x13]
	b _081AF158
_081AF118:
	ldrb r0, [r2, 0x14]
	b _081AF124
_081AF11C:
	ldrb r0, [r2, 0x14]
	lsrs r0, 4
	b _081AF158
_081AF122:
	ldrb r0, [r2, 0x15]
_081AF124:
	lsls r0, 28
	lsrs r0, 28
	b _081AF158
_081AF12A:
	ldrb r0, [r2, 0x15]
	lsrs r0, 4
	b _081AF158
_081AF130:
	ldrb r0, [r2, 0x16]
	lsls r0, 29
	lsrs r0, 29
	b _081AF158
_081AF138:
	ldrb r0, [r2, 0x16]
	lsls r0, 26
	lsrs r0, 29
	b _081AF158
_081AF140:
	ldrb r0, [r2, 0x16]
	lsrs r0, 6
	b _081AF158
_081AF146:
	ldrb r0, [r2, 0x17]
	lsls r0, 26
	lsrs r0, 26
	b _081AF158
_081AF14E:
	ldrb r0, [r2, 0x17]
	lsrs r0, 6
	b _081AF158
_081AF154:
	movs r0, 0x1
	negs r0, r0
_081AF158:
	pop {r1}
	bx r1
	thumb_func_end sub_81AF08C

	thumb_func_start sub_81AF15C
sub_81AF15C: @ 81AF15C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r3, r1, r0
	cmp r4, 0x10
	bhi _081AF25C
	lsls r0, r4, 2
	ldr r1, =_081AF188
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081AF188:
	.4byte _081AF1CC
	.4byte _081AF1CC
	.4byte _081AF1D0
	.4byte _081AF1D4
	.4byte _081AF1D8
	.4byte _081AF1DC
	.4byte _081AF1E0
	.4byte _081AF1E4
	.4byte _081AF1E8
	.4byte _081AF1F4
	.4byte _081AF202
	.4byte _081AF20E
	.4byte _081AF21C
	.4byte _081AF228
	.4byte _081AF236
	.4byte _081AF244
	.4byte _081AF250
_081AF1CC:
	str r2, [r3, 0x4]
	b _081AF25C
_081AF1D0:
	strh r2, [r3, 0xC]
	b _081AF25C
_081AF1D4:
	strh r2, [r3, 0xE]
	b _081AF25C
_081AF1D8:
	strb r2, [r3, 0x10]
	b _081AF25C
_081AF1DC:
	strb r2, [r3, 0x11]
	b _081AF25C
_081AF1E0:
	strb r2, [r3, 0x12]
	b _081AF25C
_081AF1E4:
	strb r2, [r3, 0x13]
	b _081AF25C
_081AF1E8:
	movs r0, 0xF
	ands r2, r0
	ldrb r1, [r3, 0x14]
	movs r0, 0x10
	negs r0, r0
	b _081AF1FA
_081AF1F4:
	lsls r2, 4
	ldrb r1, [r3, 0x14]
	movs r0, 0xF
_081AF1FA:
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x14]
	b _081AF25C
_081AF202:
	movs r0, 0xF
	ands r2, r0
	ldrb r1, [r3, 0x15]
	movs r0, 0x10
	negs r0, r0
	b _081AF214
_081AF20E:
	lsls r2, 4
	ldrb r1, [r3, 0x15]
	movs r0, 0xF
_081AF214:
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x15]
	b _081AF25C
_081AF21C:
	movs r0, 0x7
	ands r2, r0
	ldrb r1, [r3, 0x16]
	movs r0, 0x8
	negs r0, r0
	b _081AF23C
_081AF228:
	movs r0, 0x7
	ands r2, r0
	lsls r2, 3
	ldrb r1, [r3, 0x16]
	movs r0, 0x39
	negs r0, r0
	b _081AF23C
_081AF236:
	lsls r2, 6
	ldrb r1, [r3, 0x16]
	movs r0, 0x3F
_081AF23C:
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x16]
	b _081AF25C
_081AF244:
	movs r0, 0x3F
	ands r2, r0
	ldrb r1, [r3, 0x17]
	movs r0, 0x40
	negs r0, r0
	b _081AF256
_081AF250:
	lsls r2, 6
	ldrb r1, [r3, 0x17]
	movs r0, 0x3F
_081AF256:
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, 0x17]
_081AF25C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81AF15C

	thumb_func_start sub_81AF264
sub_81AF264: @ 81AF264
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081AF276
	cmp r0, 0x1
	beq _081AF28A
	b _081AF2E4
_081AF276:
	ldrh r1, [r4, 0x30]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	b _081AF2E4
_081AF28A:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081AF29A
	cmp r0, 0x1
	beq _081AF2C0
	ldrh r2, [r4, 0x38]
	b _081AF2DE
_081AF29A:
	movs r0, 0x34
	ldrsh r3, [r4, r0]
	ldr r1, =gSineTable
	ldrh r2, [r4, 0x38]
	lsls r0, r2, 24
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	muls r0, r3
	cmp r0, 0
	bge _081AF2B4
	adds r0, 0xFF
_081AF2B4:
	asrs r0, 8
	strh r0, [r4, 0x24]
	b _081AF2DE
	.pool
_081AF2C0:
	movs r0, 0x34
	ldrsh r3, [r4, r0]
	ldr r1, =gSineTable
	ldrh r2, [r4, 0x38]
	lsls r0, r2, 24
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	muls r0, r3
	cmp r0, 0
	bge _081AF2DA
	adds r0, 0xFF
_081AF2DA:
	asrs r0, 8
	strh r0, [r4, 0x26]
_081AF2DE:
	ldrh r0, [r4, 0x36]
	adds r0, r2, r0
	strh r0, [r4, 0x38]
_081AF2E4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81AF264

	thumb_func_start AddScrollIndicatorArrowObject
AddScrollIndicatorArrowObject: @ 81AF2F0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	adds r6, r0, 0
	ldr r5, [sp, 0x30]
	lsls r6, 24
	lsrs r6, 24
	mov r8, r6
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r5, 16
	lsrs r5, 16
	mov r12, r5
	mov r4, sp
	ldr r0, =gUnknown_08614244
	ldm r0!, {r5-r7}
	stm r4!, {r5-r7}
	ldm r0!, {r5-r7}
	stm r4!, {r5-r7}
	mov r0, sp
	movs r4, 0
	strh r3, [r0]
	mov r3, r12
	strh r3, [r0, 0x2]
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r3, r1
	adds r5, r3, 0
	adds r5, 0x3E
	ldrb r1, [r5]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r5]
	strh r4, [r3, 0x2E]
	ldr r1, =gUnknown_086141FC
	mov r5, r8
	lsls r6, r5, 2
	adds r6, r1
	ldrb r2, [r6]
	lsls r1, r2, 28
	lsrs r1, 28
	strh r1, [r3, 0x30]
	lsrs r2, 4
	strh r2, [r3, 0x32]
	ldrb r1, [r6, 0x1]
	strh r1, [r3, 0x34]
	ldrh r1, [r6, 0x2]
	strh r1, [r3, 0x36]
	strh r4, [r3, 0x38]
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddScrollIndicatorArrowObject

	thumb_func_start AddScrollIndicatorArrowPair
AddScrollIndicatorArrowPair: @ 81AF380
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x14
	adds r6, r0, 0
	mov r9, r1
	ldr r0, =gUnknown_086142C8
	str r0, [sp, 0x4]
	ldr r5, =0xffff0000
	ldr r0, [sp, 0x8]
	ands r0, r5
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	ldrh r1, [r6, 0xA]
	lsls r1, 16
	ldr r4, =0x0000ffff
	ands r0, r4
	orrs r0, r1
	str r0, [sp, 0x8]
	add r0, sp, 0x4
	bl LoadCompressedObjectPic
	ldrh r2, [r6, 0xC]
	cmp r2, r4
	bne _081AF3DC
	ldr r0, =gUnknown_086142A8
	ldrb r1, [r6, 0xE]
	lsls r1, 20
	movs r2, 0x80
	lsls r2, 17
	adds r1, r2
	lsrs r1, 16
	movs r2, 0x20
	bl LoadPalette
	b _081AF3EE
	.pool
_081AF3DC:
	ldr r0, =gUnknown_086142A8
	str r0, [sp, 0xC]
	add r0, sp, 0xC
	ldr r1, [r0, 0x4]
	ands r1, r5
	orrs r1, r2
	str r1, [r0, 0x4]
	bl LoadSpritePalette
_081AF3EE:
	ldr r0, =Task_ScrollIndicatorArrowPair
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r0, 2
	add r0, r8
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	movs r0, 0
	strb r0, [r7]
	mov r0, r9
	str r0, [r7, 0x4]
	ldrh r0, [r6, 0x6]
	strh r0, [r7, 0x8]
	ldrh r0, [r6, 0x8]
	strh r0, [r7, 0xA]
	ldrh r0, [r6, 0xA]
	strh r0, [r7, 0xE]
	ldrh r0, [r6, 0xC]
	strh r0, [r7, 0x10]
	ldrb r0, [r6]
	ldrb r1, [r6, 0x1]
	ldrb r2, [r6, 0x2]
	ldrh r3, [r6, 0xA]
	ldrh r4, [r6, 0xC]
	str r4, [sp]
	bl AddScrollIndicatorArrowObject
	strb r0, [r7, 0xC]
	ldrb r0, [r6, 0x3]
	ldrb r1, [r6, 0x4]
	ldrb r2, [r6, 0x5]
	ldrh r3, [r6, 0xA]
	ldrh r4, [r6, 0xC]
	str r4, [sp]
	bl AddScrollIndicatorArrowObject
	strb r0, [r7, 0xD]
	ldrh r1, [r6, 0xC]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _081AF47C
	ldr r5, =gSprites
	ldrb r0, [r7, 0xC]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r5
	ldrb r3, [r6, 0xE]
	lsls r3, 4
	ldrb r4, [r1, 0x5]
	movs r2, 0xF
	adds r0, r2, 0
	ands r0, r4
	orrs r0, r3
	strb r0, [r1, 0x5]
	ldrb r1, [r7, 0xD]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	ldrb r1, [r6, 0xE]
	lsls r1, 4
	ldrb r3, [r0, 0x5]
	ands r2, r3
	orrs r2, r1
	strb r2, [r0, 0x5]
_081AF47C:
	mov r0, r8
	add sp, 0x14
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddScrollIndicatorArrowPair

	thumb_func_start AddScrollIndicatorArrowPairParametrized
AddScrollIndicatorArrowPairParametrized: @ 81AF4A0
	push {r4,lr}
	adds r4, r1, 0
	subs r0, 0x2
	cmp r0, 0x1
	bhi _081AF4C4
	ldr r0, =gUnknown_0203CE8C
	movs r1, 0x2
	strb r1, [r0]
	strb r4, [r0, 0x1]
	strb r2, [r0, 0x2]
	movs r1, 0x3
	strb r1, [r0, 0x3]
	strb r4, [r0, 0x4]
	strb r3, [r0, 0x5]
	b _081AF4D6
	.pool
_081AF4C4:
	ldr r0, =gUnknown_0203CE8C
	movs r1, 0
	strb r1, [r0]
	strb r2, [r0, 0x1]
	strb r4, [r0, 0x2]
	movs r1, 0x1
	strb r1, [r0, 0x3]
	strb r3, [r0, 0x4]
	strb r4, [r0, 0x5]
_081AF4D6:
	adds r2, r0, 0
	movs r1, 0
	movs r0, 0
	strh r0, [r2, 0x6]
	ldr r0, [sp, 0x8]
	strh r0, [r2, 0x8]
	ldr r0, [sp, 0xC]
	strh r0, [r2, 0xA]
	ldr r0, [sp, 0x10]
	strh r0, [r2, 0xC]
	strb r1, [r2, 0xE]
	adds r0, r2, 0
	ldr r1, [sp, 0x14]
	bl AddScrollIndicatorArrowPair
	lsls r0, 24
	lsrs r0, 24
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddScrollIndicatorArrowPairParametrized

	thumb_func_start Task_ScrollIndicatorArrowPair
Task_ScrollIndicatorArrowPair: @ 81AF504
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	ldr r0, [r4, 0x4]
	ldrh r5, [r0]
	ldrh r0, [r4, 0x8]
	cmp r5, r0
	bne _081AF548
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _081AF548
	ldr r3, =gSprites
	ldrb r1, [r4, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	b _081AF55E
	.pool
_081AF548:
	ldr r3, =gSprites
	ldrb r1, [r4, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
_081AF55E:
	strb r1, [r0]
	ldrh r0, [r4, 0xA]
	cmp r5, r0
	bne _081AF580
	ldrb r1, [r4, 0xD]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	b _081AF594
	.pool
_081AF580:
	ldrb r1, [r4, 0xD]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
_081AF594:
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end Task_ScrollIndicatorArrowPair

	thumb_func_start Task_ScrollIndicatorArrowPairOnMainMenu
Task_ScrollIndicatorArrowPairOnMainMenu: @ 81AF59C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r4, r1, r0
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _081AF5E8
	ldr r3, =gSprites
	ldrb r1, [r4, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrb r1, [r4, 0xD]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	b _081AF612
	.pool
_081AF5E8:
	ldr r3, =gSprites
	ldrb r1, [r4, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r4, 0xD]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
_081AF612:
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Task_ScrollIndicatorArrowPairOnMainMenu

	thumb_func_start RemoveScrollIndicatorArrowPair
RemoveScrollIndicatorArrowPair: @ 81AF620
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldrh r0, [r5, 0xE]
	ldr r4, =0x0000ffff
	cmp r0, r4
	beq _081AF63E
	bl FreeSpriteTilesByTag
_081AF63E:
	ldrh r0, [r5, 0x10]
	cmp r0, r4
	beq _081AF648
	bl FreeSpritePaletteByTag
_081AF648:
	ldrb r1, [r5, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl DestroySprite
	ldrb r1, [r5, 0xD]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	adds r0, r6, 0
	bl DestroyTask
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveScrollIndicatorArrowPair

	thumb_func_start ListMenuAddCursorObjectInternal
ListMenuAddCursorObjectInternal: @ 81AF680
	push {lr}
	cmp r1, 0
	beq _081AF68A
	cmp r1, 0x1
	beq _081AF690
_081AF68A:
	bl ListMenuAddRedOutlineCursorObject
	b _081AF694
_081AF690:
	bl ListMenuAddRedArrowCursorObject
_081AF694:
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end ListMenuAddCursorObjectInternal

	thumb_func_start ListMenuUpdateCursorObject
@ void ListMenuUpdateCursorObject(u8 taskId, u16 x, u16 y, u32 a4)
ListMenuUpdateCursorObject: @ 81AF69C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	cmp r3, 0
	beq _081AF6B4
	cmp r3, 0x1
	beq _081AF6BA
	b _081AF6BE
_081AF6B4:
	bl ListMenuUpdateRedOutlineCursorObject
	b _081AF6BE
_081AF6BA:
	bl ListMenuUpdateRedArrowCursorObject
_081AF6BE:
	pop {r0}
	bx r0
	thumb_func_end ListMenuUpdateCursorObject

	thumb_func_start ListMenuRemoveCursorObject
ListMenuRemoveCursorObject: @ 81AF6C4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r1, 0
	beq _081AF6D4
	cmp r1, 0x1
	beq _081AF6DA
	b _081AF6DE
_081AF6D4:
	bl ListMenuRemoveRedOutlineCursorObject
	b _081AF6DE
_081AF6DA:
	bl ListMenuRemoveRedArrowCursorObject
_081AF6DE:
	pop {r0}
	bx r0
	thumb_func_end ListMenuRemoveCursorObject

	thumb_func_start Task_RedOutlineCursor
Task_RedOutlineCursor: @ 81AF6E4
	bx lr
	thumb_func_end Task_RedOutlineCursor

	thumb_func_start ListMenuGetRedOutlineCursorSpriteCount
ListMenuGetRedOutlineCursorSpriteCount: @ 81AF6E8
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r1, 16
	lsrs r1, 16
	movs r3, 0x4
	cmp r0, 0x10
	bls _081AF708
	movs r2, 0x8
	subs r0, 0x8
	cmp r2, r0
	bge _081AF708
_081AF700:
	adds r3, 0x2
	adds r2, 0x8
	cmp r2, r0
	blt _081AF700
_081AF708:
	cmp r1, 0x10
	bls _081AF71C
	movs r2, 0x8
	subs r1, 0x8
	cmp r2, r1
	bge _081AF71C
_081AF714:
	adds r3, 0x2
	adds r2, 0x8
	cmp r2, r1
	blt _081AF714
_081AF71C:
	lsls r0, r3, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end ListMenuGetRedOutlineCursorSpriteCount

	thumb_func_start ListMenuSetUpRedOutlineCursorSpriteOamTable
ListMenuSetUpRedOutlineCursorSpriteOamTable: @ 81AF724
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r3, r2, 0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	ldr r0, =gUnknown_0861425C
	ldr r0, [r0]
	str r0, [r3]
	movs r1, 0x88
	strb r1, [r3]
	strb r1, [r3, 0x1]
	ldr r0, =gUnknown_08614260
	ldr r0, [r0]
	str r0, [r3, 0x4]
	mov r2, r8
	adds r2, 0x80
	strb r2, [r3, 0x4]
	strb r1, [r3, 0x5]
	ldr r0, =gUnknown_08614274
	ldr r0, [r0]
	str r0, [r3, 0x8]
	strb r1, [r3, 0x8]
	mov r4, r9
	adds r4, 0x80
	strb r4, [r3, 0x9]
	ldr r0, =gUnknown_08614278
	ldr r0, [r0]
	str r0, [r3, 0xC]
	strb r2, [r3, 0xC]
	strb r4, [r3, 0xD]
	movs r0, 0x4
	mov r12, r0
	mov r2, r8
	cmp r2, 0x10
	bls _081AF7B8
	movs r2, 0x8
	mov r5, r8
	subs r5, 0x8
	cmp r2, r5
	bge _081AF7B8
	ldr r0, =gUnknown_08614264
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, =gUnknown_08614270
	ldr r6, [r0]
	adds r1, r3, 0
	adds r1, 0x10
	movs r7, 0x88
	mov r10, r7
_081AF796:
	ldr r0, [sp]
	str r0, [r1]
	adds r0, r2, 0
	subs r0, 0x78
	strb r0, [r1]
	mov r7, r10
	strb r7, [r1, 0x1]
	adds r1, 0x4
	str r6, [r1]
	strb r0, [r1]
	strb r4, [r1, 0x1]
	adds r1, 0x4
	movs r0, 0x2
	add r12, r0
	adds r2, 0x8
	cmp r2, r5
	blt _081AF796
_081AF7B8:
	mov r2, r9
	cmp r2, 0x10
	bls _081AF7F6
	movs r1, 0x8
	mov r4, r9
	subs r4, 0x8
	cmp r1, r4
	bge _081AF7F6
	ldr r0, =gUnknown_08614268
	ldr r6, [r0]
	ldr r0, =gUnknown_0861426C
	ldr r5, [r0]
	mov r7, r12
	lsls r0, r7, 2
	adds r2, r0, r3
	movs r7, 0x88
	mov r3, r8
	adds r3, 0x80
_081AF7DC:
	str r6, [r2]
	strb r7, [r2]
	adds r0, r1, 0
	subs r0, 0x78
	strb r0, [r2, 0x1]
	adds r2, 0x4
	str r5, [r2]
	strb r3, [r2]
	strb r0, [r2, 0x1]
	adds r2, 0x4
	adds r1, 0x8
	cmp r1, r4
	blt _081AF7DC
_081AF7F6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ListMenuSetUpRedOutlineCursorSpriteOamTable

	thumb_func_start ListMenuAddRedOutlineCursorObject
ListMenuAddRedOutlineCursorObject: @ 81AF828
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x28
	adds r6, r0, 0
	ldr r0, =gUnknown_08614338
	str r0, [sp, 0x18]
	ldr r5, =0xffff0000
	add r0, sp, 0x18
	ldr r1, [r0, 0x4]
	ands r1, r5
	movs r2, 0x80
	lsls r2, 1
	orrs r1, r2
	ldrh r2, [r6, 0x6]
	lsls r2, 16
	ldr r3, =0x0000ffff
	ands r1, r3
	orrs r1, r2
	str r1, [r0, 0x4]
	bl LoadCompressedObjectPic
	ldrh r2, [r6, 0x8]
	ldr r7, =0x0000ffff
	cmp r2, r7
	bne _081AF884
	ldr r0, =gUnknown_086142A8
	ldrb r1, [r6, 0xA]
	lsls r1, 20
	movs r2, 0x80
	lsls r2, 17
	adds r1, r2
	lsrs r1, 16
	movs r2, 0x20
	bl LoadPalette
	b _081AF896
	.pool
_081AF884:
	ldr r0, =gUnknown_086142A8
	str r0, [sp, 0x20]
	add r0, sp, 0x20
	ldr r1, [r0, 0x4]
	ands r1, r5
	orrs r1, r2
	str r1, [r0, 0x4]
	bl LoadSpritePalette
_081AF896:
	ldr r0, =Task_RedOutlineCursor
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldrh r0, [r6, 0x6]
	movs r3, 0
	mov r8, r3
	strh r0, [r5, 0xE]
	ldrh r0, [r6, 0x8]
	strh r0, [r5, 0x10]
	ldrh r0, [r6, 0x2]
	ldrh r1, [r6, 0x4]
	bl ListMenuGetRedOutlineCursorSpriteCount
	strb r0, [r5]
	ldrb r0, [r5]
	lsls r0, 2
	bl Alloc
	adds r2, r0, 0
	str r2, [r5, 0x8]
	str r2, [r5, 0x4]
	ldrh r0, [r6, 0x2]
	ldrh r1, [r6, 0x4]
	bl ListMenuSetUpRedOutlineCursorSpriteOamTable
	mov r1, sp
	ldr r0, =gDummySpriteTemplate
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	mov r1, sp
	ldrh r0, [r6, 0x6]
	strh r0, [r1]
	ldrh r0, [r6, 0x8]
	strh r0, [r1, 0x2]
	ldrb r1, [r6]
	adds r1, 0x78
	ldrb r2, [r6, 0x1]
	adds r2, 0x78
	mov r0, sp
	movs r3, 0
	bl CreateSprite
	strb r0, [r5, 0xC]
	ldrb r1, [r5, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r7, =gSprites
	adds r0, r7
	adds r1, r5, 0
	bl SetSubspriteTables
	ldrb r0, [r5, 0xC]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldrb r1, [r5, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x43
	mov r1, r8
	strb r1, [r0]
	ldrb r1, [r5, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r0, 0x42
	ldrb r2, [r0]
	movs r1, 0x40
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldrh r1, [r6, 0x8]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _081AF96E
	ldrb r0, [r5, 0xC]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r6, 0xA]
	lsls r2, 4
	ldrb r3, [r1, 0x5]
	movs r0, 0xF
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0x5]
_081AF96E:
	adds r0, r4, 0
	add sp, 0x28
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ListMenuAddRedOutlineCursorObject

	thumb_func_start ListMenuUpdateRedOutlineCursorObject
@ void ListMenuUpdateRedOutlineCursorObject(u8 taskId, u16 x, u16 y)
ListMenuUpdateRedOutlineCursorObject: @ 81AF994
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, r0, 2
	adds r3, r0
	lsls r3, 3
	ldr r0, =gTasks + 0x8
	adds r3, r0
	ldr r5, =gSprites
	ldrb r4, [r3, 0xC]
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r5
	adds r1, 0x78
	strh r1, [r0, 0x20]
	ldrb r1, [r3, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r2, 0x78
	strh r2, [r0, 0x22]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ListMenuUpdateRedOutlineCursorObject

	thumb_func_start ListMenuRemoveRedOutlineCursorObject
ListMenuRemoveRedOutlineCursorObject: @ 81AF9D8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r0, [r4, 0x8]
	bl Free
	ldrh r0, [r4, 0xE]
	ldr r6, =0x0000ffff
	cmp r0, r6
	beq _081AF9FC
	bl FreeSpriteTilesByTag
_081AF9FC:
	ldrh r0, [r4, 0x10]
	cmp r0, r6
	beq _081AFA06
	bl FreeSpritePaletteByTag
_081AFA06:
	ldrb r1, [r4, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r5, 0
	bl DestroyTask
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ListMenuRemoveRedOutlineCursorObject

	thumb_func_start ObjectCB_RedArrowCursor
ObjectCB_RedArrowCursor: @ 81AFA30
	push {lr}
	adds r2, r0, 0
	ldr r1, =gSineTable
	ldrh r3, [r2, 0x2E]
	lsls r0, r3, 24
	lsrs r0, 23
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _081AFA48
	adds r0, 0x3F
_081AFA48:
	asrs r0, 6
	strh r0, [r2, 0x24]
	adds r0, r3, 0
	adds r0, 0x8
	strh r0, [r2, 0x2E]
	pop {r0}
	bx r0
	.pool
	thumb_func_end ObjectCB_RedArrowCursor

	thumb_func_start Task_RedArrowCursor
Task_RedArrowCursor: @ 81AFA5C
	bx lr
	thumb_func_end Task_RedArrowCursor

	thumb_func_start ListMenuAddRedArrowCursorObject
ListMenuAddRedArrowCursorObject: @ 81AFA60
	push {r4-r7,lr}
	sub sp, 0x28
	adds r5, r0, 0
	ldr r0, =gUnknown_08614378
	str r0, [sp, 0x18]
	ldr r6, =0xffff0000
	add r0, sp, 0x18
	ldr r1, [r0, 0x4]
	ands r1, r6
	movs r2, 0x80
	orrs r1, r2
	ldrh r2, [r5, 0x6]
	lsls r2, 16
	ldr r4, =0x0000ffff
	ands r1, r4
	orrs r1, r2
	str r1, [r0, 0x4]
	bl LoadCompressedObjectPic
	ldrh r2, [r5, 0x8]
	cmp r2, r4
	bne _081AFAB4
	ldr r0, =gUnknown_086142A8
	ldrb r1, [r5, 0xA]
	lsls r1, 20
	movs r2, 0x80
	lsls r2, 17
	adds r1, r2
	lsrs r1, 16
	movs r2, 0x20
	bl LoadPalette
	b _081AFAC6
	.pool
_081AFAB4:
	ldr r0, =gUnknown_086142A8
	str r0, [sp, 0x20]
	add r0, sp, 0x20
	ldr r1, [r0, 0x4]
	ands r1, r6
	orrs r1, r2
	str r1, [r0, 0x4]
	bl LoadSpritePalette
_081AFAC6:
	ldr r0, =Task_RedArrowCursor
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r5, 0x6]
	strh r0, [r4, 0x2]
	ldrh r0, [r5, 0x8]
	strh r0, [r4, 0x4]
	mov r1, sp
	ldr r0, =gUnknown_08614290
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	mov r1, sp
	ldrh r0, [r5, 0x6]
	strh r0, [r1]
	ldrh r0, [r5, 0x8]
	strh r0, [r1, 0x2]
	ldrb r1, [r5]
	ldrb r2, [r5, 0x1]
	mov r0, sp
	movs r3, 0
	bl CreateSprite
	strb r0, [r4]
	ldr r3, =gSprites
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r2, 0x8
	strh r2, [r0, 0x24]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	strh r2, [r0, 0x26]
	ldrh r1, [r5, 0x8]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _081AFB46
	ldrb r0, [r4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r2, [r5, 0xA]
	lsls r2, 4
	ldrb r3, [r1, 0x5]
	movs r0, 0xF
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, 0x5]
_081AFB46:
	adds r0, r6, 0
	add sp, 0x28
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ListMenuAddRedArrowCursorObject

	thumb_func_start ListMenuUpdateRedArrowCursorObject
@ void ListMenuUpdateRedArrowCursorObject(u8 taskId, u16 x, u16 y)
ListMenuUpdateRedArrowCursorObject: @ 81AFB68
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r3, r0, 2
	adds r3, r0
	lsls r3, 3
	ldr r0, =gTasks + 0x8
	adds r3, r0
	ldr r5, =gSprites
	ldrb r4, [r3]
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r5
	strh r1, [r0, 0x20]
	ldrb r1, [r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	strh r2, [r0, 0x22]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ListMenuUpdateRedArrowCursorObject

	thumb_func_start ListMenuRemoveRedArrowCursorObject
ListMenuRemoveRedArrowCursorObject: @ 81AFBA0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4, 0x2]
	ldr r6, =0x0000ffff
	cmp r0, r6
	beq _081AFBBE
	bl FreeSpriteTilesByTag
_081AFBBE:
	ldrh r0, [r4, 0x4]
	cmp r0, r6
	beq _081AFBC8
	bl FreeSpritePaletteByTag
_081AFBC8:
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	adds r0, r5, 0
	bl DestroyTask
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ListMenuRemoveRedArrowCursorObject

	.align 2, 0 @ Don't pad with nop.
