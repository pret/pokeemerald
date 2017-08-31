	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start nullsub_67
nullsub_67: @ 817BA40
	bx lr
	thumb_func_end nullsub_67

	thumb_func_start sub_817BA44
sub_817BA44: @ 817BA44
	push {r4,r5,lr}
	sub sp, 0x4
	movs r4, 0
	ldr r5, =gUnknown_085F5458
_0817BA4C:
	adds r0, r4, 0
	adds r0, 0x14
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r4, 1
	adds r1, r5
	ldrh r1, [r1]
	str r1, [sp]
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0xB
	bls _0817BA4C
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817BA44

	thumb_func_start sub_817BA7C
sub_817BA7C: @ 817BA7C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	cmp r0, 0x8
	ble _0817BB2A
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	adds r1, r0, 0
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0x50
	bl __divsi3
	movs r1, 0x58
	subs r1, r0
	strh r1, [r4, 0x22]
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0817BAB6
	adds r0, 0x3
_0817BAB6:
	asrs r0, 2
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x4
	strh r0, [r4, 0x3A]
	ldrh r1, [r4, 0x3C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0817BAE0
	ldrh r0, [r4, 0x38]
	subs r0, 0x1
	strh r0, [r4, 0x38]
_0817BAE0:
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _0817BAF6
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1
	b _0817BAFC
_0817BAF6:
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x14
_0817BAFC:
	strb r0, [r1]
	movs r2, 0x38
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bge _0817BB08
	adds r0, 0x3
_0817BB08:
	asrs r0, 2
	adds r0, 0x14
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1F
	bls _0817BB16
	movs r2, 0x1F
_0817BB16:
	movs r0, 0x1F
	ands r2, r0
	lsls r2, 1
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x3]
	b _0817BB30
_0817BB2A:
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_0817BB30:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_817BA7C

	thumb_func_start sub_817BB38
sub_817BB38: @ 817BB38
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_085F5440
	movs r1, 0x78
	movs r2, 0x58
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _0817BB82
	ldr r4, =gSprites
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r2, r3, r4
	movs r1, 0
	movs r0, 0x30
	strh r0, [r2, 0x38]
	strh r5, [r2, 0x3A]
	strh r1, [r2, 0x3C]
	ldrb r1, [r2, 0x1]
	subs r0, 0x34
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldrb r0, [r2, 0x3]
	movs r1, 0x3E
	orrs r0, r1
	strb r0, [r2, 0x3]
	adds r4, 0x1C
	adds r3, r4
	ldr r0, =sub_817BA7C
	str r0, [r3]
_0817BB82:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817BB38

	thumb_func_start sub_817BB94
sub_817BB94: @ 817BB94
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x22
	ldrsh r0, [r4, r1]
	cmp r0, 0x57
	bgt _0817BBFA
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	adds r1, r0, 0
	muls r1, r0
	adds r0, r1, 0
	movs r1, 0x5
	bl __divsi3
	adds r0, 0x8
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0
	bge _0817BBCC
	adds r0, 0x3
_0817BBCC:
	asrs r0, 2
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	lsls r0, 26
	lsrs r0, 24
	movs r1, 0x28
	bl Sin
	adds r0, 0x8
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	b _0817BC00
_0817BBFA:
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_0817BC00:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_817BB94

	thumb_func_start sub_817BC08
sub_817BC08: @ 817BC08
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_085F5440
	movs r1, 0x78
	movs r2, 0x8
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _0817BC5E
	ldr r4, =gSprites
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r2, r3, r4
	movs r1, 0
	movs r0, 0x8
	strh r0, [r2, 0x38]
	strh r5, [r2, 0x3A]
	strh r1, [r2, 0x3C]
	ldrb r1, [r2, 0x1]
	subs r0, 0xC
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldrb r1, [r2, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x32
	orrs r0, r1
	strb r0, [r2, 0x3]
	adds r2, 0x43
	movs r0, 0x1
	strb r0, [r2]
	adds r4, 0x1C
	adds r3, r4
	ldr r0, =sub_817BB94
	str r0, [r3]
_0817BC5E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817BC08

	thumb_func_start sub_817BC70
sub_817BC70: @ 817BC70
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0x8
	ble _0817BCAC
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x3A]
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x38
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, 0x24]
	ldrh r0, [r4, 0x38]
	ldrh r1, [r4, 0x34]
	subs r0, r1
	strh r0, [r4, 0x38]
	ldrh r0, [r4, 0x3A]
	adds r0, 0x4
	strh r0, [r4, 0x3A]
	b _0817BCB2
_0817BCAC:
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_0817BCB2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_817BC70

	thumb_func_start sub_817BCB8
sub_817BCB8: @ 817BCB8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gUnknown_085F5440
	movs r1, 0x78
	movs r2, 0x38
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _0817BD0E
	ldr r4, =gSprites
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r2, r3, r4
	movs r1, 0
	strh r5, [r2, 0x34]
	movs r0, 0x78
	strh r0, [r2, 0x38]
	strh r6, [r2, 0x3A]
	strh r1, [r2, 0x3C]
	ldrb r1, [r2, 0x1]
	subs r0, 0x7C
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldrb r0, [r2, 0x3]
	movs r1, 0x3E
	orrs r0, r1
	strb r0, [r2, 0x3]
	adds r2, 0x43
	movs r0, 0x1
	strb r0, [r2]
	adds r4, 0x1C
	adds r3, r4
	ldr r0, =sub_817BC70
	str r0, [r3]
_0817BD0E:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817BCB8

	thumb_func_start sub_817BD20
sub_817BD20: @ 817BD20
	push {r4,r5,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x3C]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0817BD34
	ldrh r0, [r4, 0x22]
	adds r0, 0x1
	strh r0, [r4, 0x22]
_0817BD34:
	ldrh r1, [r4, 0x3A]
	movs r2, 0x3A
	ldrsh r0, [r4, r2]
	cmp r0, 0x7F
	bgt _0817BDE4
	lsls r0, r1, 24
	lsrs r0, 24
	movs r5, 0x38
	ldrsh r1, [r4, r5]
	bl Sin
	negs r0, r0
	strh r0, [r4, 0x26]
	movs r0, 0x34
	ldrsh r1, [r4, r0]
	movs r2, 0x3C
	ldrsh r0, [r4, r2]
	muls r0, r1
	movs r1, 0x3
	bl __divsi3
	adds r0, 0x78
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x3A]
	adds r3, r0, 0x1
	strh r3, [r4, 0x3A]
	movs r5, 0x3A
	ldrsh r1, [r4, r5]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	cmp r0, 0
	bge _0817BD78
	adds r0, 0x7F
_0817BD78:
	asrs r0, 7
	movs r1, 0x1F
	subs r1, r0
	lsls r1, 24
	lsrs r2, r1, 24
	lsls r0, r3, 16
	asrs r0, 16
	cmp r0, 0x40
	ble _0817BD94
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x1
	strb r0, [r1]
	b _0817BDC4
_0817BD94:
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	adds r1, r4, 0
	adds r1, 0x43
	movs r0, 0x14
	strb r0, [r1]
	ldrh r1, [r4, 0x3A]
	movs r5, 0x3A
	ldrsh r0, [r4, r5]
	cmp r0, 0x70
	ble _0817BDC4
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0817BDC4
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
_0817BDC4:
	cmp r2, 0x13
	bhi _0817BDCA
	movs r2, 0x14
_0817BDCA:
	movs r0, 0x1F
	ands r2, r0
	lsls r2, 1
	ldrb r1, [r4, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x3]
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	b _0817BDEA
_0817BDE4:
	adds r0, r4, 0
	bl RemoveObjectAndFreeTiles
_0817BDEA:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_817BD20

	thumb_func_start sub_817BDF0
sub_817BDF0: @ 817BDF0
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gUnknown_085F5440
	movs r1, 0x78
	movs r2, 0x38
	movs r3, 0
	bl AddObjectToFront
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x40
	beq _0817BE60
	bl Random
	ldr r6, =gSprites
	lsls r5, r4, 4
	adds r5, r4
	lsls r5, 2
	adds r4, r5, r6
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x7
	bl __umodsi3
	movs r1, 0x3
	subs r1, r0
	movs r0, 0
	mov r8, r0
	strh r1, [r4, 0x34]
	bl Random
	movs r1, 0x3F
	ands r1, r0
	adds r1, 0x30
	strh r1, [r4, 0x38]
	mov r0, r8
	strh r0, [r4, 0x3C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	movs r1, 0x3E
	orrs r0, r1
	strb r0, [r4, 0x3]
	adds r4, 0x43
	movs r0, 0x14
	strb r0, [r4]
	adds r6, 0x1C
	adds r5, r6
	ldr r0, =sub_817BD20
	str r0, [r5]
_0817BE60:
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817BDF0

	thumb_func_start sub_817BE78
sub_817BE78: @ 817BE78
	push {lr}
	ldr r0, =gUnknown_085F540C
	bl LoadCompressedObjectPicUsingHeap
	ldr r0, =gUnknown_085F541C
	bl LoadTaggedObjectPalettes
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817BE78

	thumb_func_start sub_817BE94
sub_817BE94: @ 817BE94
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =sub_817BEC4
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xA]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817BE94

	thumb_func_start sub_817BEC4
sub_817BEC4: @ 817BEC4
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_817BA44
	ldr r0, =gTasks
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	adds r5, r0
	movs r0, 0
	strh r0, [r5, 0x26]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	movs r0, 0x3
	lsls r0, r1
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0xA
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_817BF14
	str r0, [r5]
	movs r0, 0x8C
	bl audio_play
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817BEC4

	thumb_func_start sub_817BF14
sub_817BF14: @ 817BF14
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r3, r5, 2
	adds r0, r3, r5
	lsls r0, 3
	adds r1, r0, r1
	ldrh r2, [r1, 0x26]
	movs r4, 0x26
	ldrsh r0, [r1, r4]
	cmp r0, 0x3F
	bgt _0817BF70
	movs r0, 0x7
	ands r0, r2
	adds r7, r3, 0
	cmp r0, 0
	bne _0817BF5A
	movs r4, 0
	adds r6, r1, 0
_0817BF3C:
	ldrh r1, [r6, 0x26]
	movs r0, 0x78
	ands r0, r1
	lsls r0, 1
	lsls r1, r4, 6
	adds r0, r1
	lsls r0, 24
	lsrs r0, 24
	bl sub_817BB38
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _0817BF3C
_0817BF5A:
	ldr r0, =gTasks
	adds r1, r7, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _0817BF78
	.pool
_0817BF70:
	movs r0, 0x60
	strh r0, [r1, 0x26]
	ldr r0, =sub_817BF84
	str r0, [r1]
_0817BF78:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817BF14

	thumb_func_start sub_817BF84
sub_817BF84: @ 817BF84
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r1, r0, r1
	ldrh r3, [r1, 0x26]
	movs r4, 0x26
	ldrsh r0, [r1, r4]
	cmp r0, 0
	beq _0817BFA8
	subs r0, r3, 0x1
	strh r0, [r1, 0x26]
	b _0817BFAE
	.pool
_0817BFA8:
	adds r0, r2, 0
	bl DestroyTask
_0817BFAE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_817BF84

	thumb_func_start sub_817BFB4
sub_817BFB4: @ 817BFB4
	push {lr}
	ldr r0, =sub_817BFCC
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817BFB4

	thumb_func_start sub_817BFCC
sub_817BFCC: @ 817BFCC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_817BA44
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x26]
	ldr r1, =sub_817C000
	str r1, [r0]
	movs r0, 0xB7
	bl audio_play
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817BFCC

	thumb_func_start sub_817C000
sub_817C000: @ 817C000
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	adds r1, r0, r1
	movs r3, 0x26
	ldrsh r0, [r1, r3]
	cmp r0, 0x5F
	bgt _0817C048
	adds r6, r2, 0
	cmp r0, 0x5
	bgt _0817C032
	movs r4, 0
_0817C020:
	lsls r0, r4, 28
	lsrs r0, 24
	bl sub_817BC08
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x8
	bls _0817C020
_0817C032:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _0817C04C
	.pool
_0817C048:
	ldr r0, =sub_817C058
	str r0, [r1]
_0817C04C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C000

	thumb_func_start sub_817C058
sub_817C058: @ 817C058
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	pop {r0}
	bx r0
	thumb_func_end sub_817C058

	thumb_func_start sub_817C068
sub_817C068: @ 817C068
	push {lr}
	ldr r0, =sub_817C080
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817C068

	thumb_func_start sub_817C080
sub_817C080: @ 817C080
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_817BA44
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	movs r1, 0
	strh r1, [r0, 0x26]
	ldr r1, =sub_817C0B4
	str r1, [r0]
	movs r0, 0x66
	bl audio_play
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C080

	thumb_func_start sub_817C0B4
sub_817C0B4: @ 817C0B4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r2, r5, 2
	adds r0, r2, r5
	lsls r0, 3
	adds r1, r0, r1
	movs r3, 0x26
	ldrsh r0, [r1, r3]
	cmp r0, 0x2F
	bgt _0817C124
	adds r6, r2, 0
	cmp r0, 0
	bne _0817C0E8
	movs r4, 0
_0817C0D4:
	lsls r0, r4, 28
	lsrs r0, 24
	movs r1, 0x4
	bl sub_817BCB8
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _0817C0D4
_0817C0E8:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	movs r2, 0x26
	ldrsh r0, [r1, r2]
	cmp r0, 0x20
	bne _0817C10E
	movs r4, 0
_0817C0FA:
	lsls r0, r4, 28
	lsrs r0, 24
	movs r1, 0x8
	bl sub_817BCB8
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xF
	bls _0817C0FA
_0817C10E:
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _0817C128
	.pool
_0817C124:
	ldr r0, =sub_817C134
	str r0, [r1]
_0817C128:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C0B4

	thumb_func_start sub_817C134
sub_817C134: @ 817C134
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	pop {r0}
	bx r0
	thumb_func_end sub_817C134

	thumb_func_start sub_817C144
sub_817C144: @ 817C144
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =sub_817C174
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xC]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817C144

	thumb_func_start sub_817C174
sub_817C174: @ 817C174
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_817BA44
	ldr r0, =gTasks
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	adds r5, r0
	movs r0, 0
	strh r0, [r5, 0x26]
	ldr r0, =gPlttBufferFaded + 0x40
	ldr r1, =gPlttBufferUnfaded + 0x40
	movs r2, 0x30
	bl CpuSet
	ldr r0, =0xfff9041c
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_817C1D4
	str r0, [r5]
	movs r0, 0xCA
	bl audio_play
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C174

	thumb_func_start sub_817C1D4
sub_817C1D4: @ 817C1D4
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r5, r6, 2
	adds r0, r5, r6
	lsls r0, 3
	adds r1, r0, r1
	movs r0, 0x26
	ldrsh r2, [r1, r0]
	cmp r2, 0x7F
	bgt _0817C250
	adds r0, r2, 0
	cmp r0, 0
	beq _0817C210
	cmp r0, 0x20
	beq _0817C224
	cmp r2, 0x31
	bgt _0817C234
	bl Random
	movs r1, 0x7
	ands r0, r1
	bl sub_817BDF0
	b _0817C234
	.pool
_0817C210:
	movs r4, 0
_0817C212:
	adds r0, r4, 0
	bl sub_817BDF0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _0817C212
	b _0817C234
_0817C224:
	ldr r0, =0xffff041c
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0x10
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_0817C234:
	ldr r0, =gTasks
	adds r1, r5, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _0817C254
	.pool
_0817C250:
	ldr r0, =sub_817C260
	str r0, [r1]
_0817C254:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C1D4

	thumb_func_start sub_817C260
sub_817C260: @ 817C260
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0817C278
	adds r0, r2, 0
	bl DestroyTask
_0817C278:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C260

	thumb_func_start sub_817C280
sub_817C280: @ 817C280
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r0, =sub_817C2B0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0xC]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817C280

	thumb_func_start sub_817C2B0
sub_817C2B0: @ 817C2B0
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_817BA44
	ldr r0, =gTasks
	lsls r5, r4, 2
	adds r5, r4
	lsls r5, 3
	adds r5, r0
	movs r0, 0
	strh r0, [r5, 0x26]
	ldr r0, =gPlttBufferFaded + 0x40
	ldr r1, =gPlttBufferUnfaded + 0x40
	movs r2, 0x30
	bl CpuSet
	ldr r0, =0xfff90400
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	ldr r0, =sub_817C310
	str r0, [r5]
	movs r0, 0xCA
	bl audio_play
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C2B0

	thumb_func_start sub_817C310
sub_817C310: @ 817C310
	push {r4-r6,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r1, =gTasks
	lsls r5, r6, 2
	adds r0, r5, r6
	lsls r0, 3
	adds r1, r0, r1
	movs r0, 0x26
	ldrsh r2, [r1, r0]
	cmp r2, 0x7F
	bgt _0817C38C
	adds r0, r2, 0
	cmp r0, 0
	beq _0817C34C
	cmp r0, 0x20
	beq _0817C360
	cmp r2, 0x31
	bgt _0817C370
	bl Random
	movs r1, 0x7
	ands r0, r1
	bl sub_817BDF0
	b _0817C370
	.pool
_0817C34C:
	movs r4, 0
_0817C34E:
	adds r0, r4, 0
	bl sub_817BDF0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _0817C34E
	b _0817C370
_0817C360:
	ldr r0, =0xffff0400
	ldr r1, =0x00007fff
	str r1, [sp]
	movs r1, 0x10
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
_0817C370:
	ldr r0, =gTasks
	adds r1, r5, r6
	lsls r1, 3
	adds r1, r0
	ldrh r0, [r1, 0x26]
	adds r0, 0x1
	strh r0, [r1, 0x26]
	b _0817C390
	.pool
_0817C38C:
	ldr r0, =sub_817C260
	str r0, [r1]
_0817C390:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C310

	thumb_func_start nullsub_68
nullsub_68: @ 817C39C
	bx lr
	thumb_func_end nullsub_68

	thumb_func_start sub_817C3A0
sub_817C3A0: @ 817C3A0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	movs r1, 0
	ldr r3, =sub_817C4EC
	ldr r2, =0x00007fff
_0817C3BA:
	lsls r0, r1, 1
	add r0, sp
	adds r0, 0x4
	strh r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0xF
	bls _0817C3BA
	adds r0, r3, 0
	movs r1, 0
	bl CreateTask
	mov r8, r0
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gTasks
	mov r1, r8
	lsls r6, r1, 2
	add r6, r8
	lsls r6, 3
	adds r6, r0
	strh r5, [r6, 0xA]
	strh r7, [r6, 0xC]
	movs r1, 0x80
	lsls r1, 1
	strh r1, [r6, 0xE]
	movs r0, 0x10
	strh r0, [r6, 0x10]
	movs r4, 0x80
	lsls r4, 9
	str r1, [sp]
	movs r0, 0x1E
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	movs r0, 0x10
	ldrsh r1, [r6, r0]
	adds r0, r4, 0
	bl __divsi3
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r0, 0x1F
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	ldr r1, =gSprites
	mov r9, r1
	lsls r2, r5, 4
	adds r2, r5
	lsls r2, 2
	mov r3, r9
	adds r3, 0x1C
	adds r0, r2, r3
	ldr r1, =nullsub_68
	str r1, [r0]
	add r2, r9
	ldrb r1, [r2, 0x1]
	movs r4, 0x4
	negs r4, r4
	adds r0, r4, 0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldrb r1, [r2, 0x3]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	movs r1, 0x3C
	orrs r0, r1
	strb r0, [r2, 0x3]
	movs r0, 0x3E
	adds r0, r2
	mov r10, r0
	ldrb r1, [r0]
	movs r5, 0x5
	negs r5, r5
	adds r0, r5, 0
	ands r0, r1
	mov r1, r10
	strb r0, [r1]
	ldrb r1, [r2, 0x5]
	lsrs r1, 4
	lsls r1, 5
	ldr r0, =gPlttBufferFaded + 0x200
	mov r10, r0
	add r1, r10
	add r0, sp, 0x4
	movs r2, 0x10
	str r3, [sp, 0x24]
	bl CpuSet
	lsls r1, r7, 4
	adds r1, r7
	lsls r1, 2
	ldr r3, [sp, 0x24]
	adds r3, r1, r3
	ldr r0, =nullsub_68
	str r0, [r3]
	add r1, r9
	ldrb r0, [r1, 0x1]
	ands r4, r0
	movs r0, 0x1
	orrs r4, r0
	strb r4, [r1, 0x1]
	ldrb r0, [r1, 0x3]
	movs r2, 0x3E
	orrs r0, r2
	strb r0, [r1, 0x3]
	adds r2, r1, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	ands r5, r0
	strb r5, [r2]
	ldrb r1, [r1, 0x5]
	lsrs r1, 4
	lsls r1, 5
	add r1, r10
	add r0, sp, 0x4
	movs r2, 0x10
	bl CpuSet
	movs r1, 0
	strh r1, [r6, 0x18]
	mov r0, r8
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_817C3A0

	thumb_func_start sub_817C4EC
sub_817C4EC: @ 817C4EC
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0x12]
	movs r0, 0x8
	strh r0, [r1, 0x14]
	ldr r0, =sub_817C510
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_817C4EC

	thumb_func_start sub_817C510
sub_817C510: @ 817C510
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gTasks
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 3
	adds r2, r0, r1
	movs r1, 0x18
	ldrsh r0, [r2, r1]
	cmp r0, 0
	beq _0817C534
	adds r0, r3, 0
	bl sub_817C72C
	b _0817C556
	.pool
_0817C534:
	ldrh r1, [r2, 0x14]
	movs r4, 0x14
	ldrsh r0, [r2, r4]
	cmp r0, 0x80
	bne _0817C546
	adds r0, r3, 0
	bl sub_817C67C
	b _0817C556
_0817C546:
	adds r0, r1, 0x2
	strh r0, [r2, 0x14]
	ldrh r0, [r2, 0x12]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r2, 0x12]
	ldr r0, =sub_817C560
	str r0, [r2]
_0817C556:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C510

	thumb_func_start sub_817C560
sub_817C560: @ 817C560
	push {r4-r7,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r2, r0, r1
	movs r3, 0x18
	ldrsh r0, [r2, r3]
	adds r5, r1, 0
	cmp r0, 0
	beq _0817C58C
	ldr r0, =sub_817C72C
	str r0, [r2]
	b _0817C670
	.pool
_0817C58C:
	movs r6, 0
	movs r7, 0x12
	ldrsh r0, [r2, r7]
	cmp r0, 0
	bne _0817C5DC
	movs r0, 0xE
	ldrsh r1, [r2, r0]
	movs r3, 0x14
	ldrsh r0, [r2, r3]
	movs r3, 0x80
	lsls r3, 1
	subs r0, r3, r0
	cmp r1, r0
	bge _0817C5B2
	ldrh r0, [r2, 0x14]
	ldrh r7, [r2, 0xE]
	adds r0, r7
	strh r0, [r2, 0xE]
	b _0817C5B6
_0817C5B2:
	strh r3, [r2, 0xE]
	movs r6, 0x1
_0817C5B6:
	lsls r2, r4, 2
	adds r0, r2, r4
	lsls r0, 3
	adds r3, r0, r5
	movs r0, 0x10
	ldrsh r1, [r3, r0]
	movs r7, 0x14
	ldrsh r0, [r3, r7]
	adds r0, 0x10
	cmp r1, r0
	ble _0817C5D6
	ldrh r0, [r3, 0x10]
	ldrh r1, [r3, 0x14]
	subs r0, r1
	strh r0, [r3, 0x10]
	b _0817C626
_0817C5D6:
	movs r0, 0x10
	strh r0, [r3, 0x10]
	b _0817C620
_0817C5DC:
	movs r0, 0x10
	ldrsh r1, [r2, r0]
	movs r3, 0x14
	ldrsh r0, [r2, r3]
	movs r3, 0x80
	lsls r3, 1
	subs r0, r3, r0
	cmp r1, r0
	bge _0817C5F8
	ldrh r0, [r2, 0x14]
	ldrh r7, [r2, 0x10]
	adds r0, r7
	strh r0, [r2, 0x10]
	b _0817C5FC
_0817C5F8:
	strh r3, [r2, 0x10]
	movs r6, 0x1
_0817C5FC:
	lsls r2, r4, 2
	adds r0, r2, r4
	lsls r0, 3
	adds r3, r0, r5
	movs r0, 0xE
	ldrsh r1, [r3, r0]
	movs r7, 0x14
	ldrsh r0, [r3, r7]
	adds r0, 0x10
	cmp r1, r0
	ble _0817C61C
	ldrh r0, [r3, 0xE]
	ldrh r1, [r3, 0x14]
	subs r0, r1
	strh r0, [r3, 0xE]
	b _0817C626
_0817C61C:
	movs r0, 0x10
	strh r0, [r3, 0xE]
_0817C620:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_0817C626:
	adds r0, r2, r4
	lsls r0, 3
	adds r5, r0, r5
	movs r0, 0xE
	ldrsh r1, [r5, r0]
	movs r4, 0x80
	lsls r4, 9
	adds r0, r4, 0
	bl __divsi3
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r0, 0x1E
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	movs r3, 0x10
	ldrsh r1, [r5, r3]
	adds r0, r4, 0
	bl __divsi3
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	movs r0, 0x1F
	movs r2, 0
	movs r3, 0
	bl SetSpriteTransformationMatrix
	cmp r6, 0x2
	bne _0817C670
	ldr r0, =sub_817C510
	str r0, [r5]
_0817C670:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C560

	thumb_func_start sub_817C67C
sub_817C67C: @ 817C67C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	mov r8, r1
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	add r2, r8
	ldrb r3, [r2, 0x1]
	movs r6, 0x4
	negs r6, r6
	adds r1, r6, 0
	ands r1, r3
	strb r1, [r2, 0x1]
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	add r2, r8
	ldrb r3, [r2, 0x3]
	movs r5, 0x3F
	negs r5, r5
	adds r1, r5, 0
	ands r1, r3
	strb r1, [r2, 0x3]
	movs r1, 0xA
	ldrsh r2, [r4, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r3, 0x4
	orrs r2, r3
	strb r2, [r1]
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x1]
	ands r6, r2
	strb r6, [r1, 0x1]
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x3]
	ands r5, r2
	strb r5, [r1, 0x3]
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	ands r2, r3
	strb r2, [r1]
	bl DestroyTask
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C67C

	thumb_func_start sub_817C72C
sub_817C72C: @ 817C72C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	mov r8, r1
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	add r2, r8
	ldrb r3, [r2, 0x1]
	movs r6, 0x4
	negs r6, r6
	adds r1, r6, 0
	ands r1, r3
	strb r1, [r2, 0x1]
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	lsls r2, r1, 4
	adds r2, r1
	lsls r2, 2
	add r2, r8
	ldrb r3, [r2, 0x3]
	movs r5, 0x3F
	negs r5, r5
	adds r1, r5, 0
	ands r1, r3
	strb r1, [r2, 0x3]
	movs r1, 0xA
	ldrsh r2, [r4, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	adds r1, 0x3E
	ldrb r3, [r1]
	movs r2, 0x5
	negs r2, r2
	ands r2, r3
	strb r2, [r1]
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x1]
	ands r6, r2
	strb r6, [r1, 0x1]
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	ldrb r2, [r1, 0x3]
	ands r5, r2
	strb r5, [r1, 0x3]
	movs r1, 0xC
	ldrsh r2, [r4, r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r8
	adds r1, 0x3E
	ldrb r2, [r1]
	movs r3, 0x4
	orrs r2, r3
	strb r2, [r1]
	bl DestroyTask
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_817C72C

	.align 2, 0 @ Don't pad with nop.
