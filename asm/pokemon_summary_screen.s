	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81C0604
sub_81C0604: @ 81C0604
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	adds r4, r5, 0
	ldr r1, =gUnknown_0203CF1C
	ldr r3, [r1]
	ldr r2, =0x000040c3
	adds r0, r3, r2
	ldrb r0, [r0]
	adds r6, r1, 0
	cmp r0, 0
	bne _081C06EE
	ldr r1, =0x000040bd
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, 0x1
	bne _081C0678
	adds r1, 0x3
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C0654
	lsls r1, r5, 24
	asrs r1, 24
	movs r4, 0x2
	eors r1, r2
	negs r0, r1
	orrs r0, r1
	asrs r0, 31
	ands r4, r0
	b _081C065C
	.pool
_081C0654:
	movs r4, 0x3
	cmp r5, 0x1
	bne _081C065C
	movs r4, 0x1
_081C065C:
	ldr r2, [r6]
	ldr r0, [r2]
	ldr r3, =0x000040be
	adds r1, r2, r3
	ldrb r1, [r1]
	adds r3, 0x1
	adds r2, r3
	ldrb r2, [r2]
	adds r3, r4, 0
	bl sub_80D214C
	b _081C0696
	.pool
_081C0678:
	bl sub_81B1250
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C068E
	lsls r0, r5, 24
	asrs r0, 24
	bl sub_81C09B4
	b _081C0696
_081C068E:
	lsls r0, r4, 24
	asrs r0, 24
	bl sub_81C08F8
_081C0696:
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	beq _081C06EE
	movs r0, 0x5
	bl PlaySE
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	adds r0, 0x77
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C06D4
	movs r0, 0x2
	movs r1, 0x1
	bl sub_81C4204
	movs r0, 0xD
	bl ClearWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0
	movs r1, 0x2
	bl sub_81C2074
_081C06D4:
	ldr r0, [r5]
	ldr r1, =0x000040be
	adds r0, r1
	movs r2, 0
	strb r4, [r0]
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	strh r2, [r0, 0x8]
	ldr r1, =sub_81C0704
	str r1, [r0]
_081C06EE:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0604

	thumb_func_start sub_81C0704
sub_81C0704: @ 81C0704
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r4, r1, 3
	ldr r6, =gTasks + 0x8
	adds r5, r4, r6
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0xC
	bls _081C071E
	b _081C08BC
_081C071E:
	lsls r0, 2
	ldr r1, =_081C0730
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C0730:
	.4byte _081C0764
	.4byte _081C076A
	.4byte _081C0780
	.4byte _081C07A8
	.4byte _081C07C8
	.4byte _081C07E0
	.4byte _081C07F0
	.4byte _081C0800
	.4byte _081C0828
	.4byte _081C086C
	.4byte _081C0872
	.4byte _081C0878
	.4byte _081C0894
_081C0764:
	bl StopCryAndClearCrySongs
	b _081C08EC
_081C076A:
	bl sub_81C4898
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d3
	b _081C0786
	.pool
_081C0780:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d4
_081C0786:
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySpriteAndFreeResources
	b _081C08EC
	.pool
_081C07A8:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_81C0098
	ldr r0, [r4]
	ldr r1, =0x000040f0
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	b _081C08EC
	.pool
_081C07C8:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81C00F0
	lsls r0, 24
	cmp r0, 0
	bne _081C07DA
	b _081C08F2
_081C07DA:
	b _081C08EC
	.pool
_081C07E0:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81C49E0
	b _081C08EC
	.pool
_081C07F0:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81C4A08
	b _081C08EC
	.pool
_081C0800:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0x77
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C0816
	movs r1, 0x2
	negs r1, r1
	movs r0, 0xA
	bl sub_81C2074
_081C0816:
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_81C2228
	movs r0, 0
	strh r0, [r5, 0x2]
	b _081C08EC
	.pool
_081C0828:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0xC
	adds r1, r5, 0x2
	bl sub_81C45F4
	ldr r1, [r4]
	ldr r2, =0x000040d3
	adds r1, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081C08F2
	ldr r2, =gSprites
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x1
	strh r1, [r0, 0x32]
	bl sub_81C0E24
	movs r0, 0
	strh r0, [r5, 0x2]
	b _081C08EC
	.pool
_081C086C:
	bl sub_81C4280
	b _081C08EC
_081C0872:
	bl sub_81C25E8
	b _081C08EC
_081C0878:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81C2D9C
	bl sub_81C2524
	b _081C08EC
	.pool
_081C0894:
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d3
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strh r1, [r0, 0x32]
	b _081C08EC
	.pool
_081C08BC:
	bl sub_81221EC
	lsls r0, 24
	cmp r0, 0
	bne _081C08F2
	ldr r0, =sub_81C20F0
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _081C08F2
	strh r0, [r5]
	adds r0, r6, 0
	subs r0, 0x8
	adds r0, r4, r0
	ldr r1, =sub_81C0510
	str r1, [r0]
	b _081C08F2
	.pool
_081C08EC:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_081C08F2:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C0704

	thumb_func_start sub_81C08F8
sub_81C08F8: @ 81C08F8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gUnknown_0203CF1C
	ldr r2, [r1]
	ldr r7, [r2]
	ldr r3, =0x000040c0
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r5, r1, 0
	cmp r0, 0
	bne _081C0960
	lsls r0, r4, 24
	asrs r3, r0, 24
	movs r1, 0x1
	negs r1, r1
	adds r6, r0, 0
	cmp r3, r1
	bne _081C0928
	ldr r1, =0x000040be
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C0988
_081C0928:
	asrs r0, r6, 24
	cmp r0, 0x1
	bne _081C0940
	ldr r0, [r5]
	ldr r2, =0x000040be
	adds r1, r0, r2
	ldr r3, =0x000040bf
	adds r0, r3
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bcs _081C0988
_081C0940:
	ldr r0, [r5]
	ldr r1, =0x000040be
	adds r0, r1
	ldrb r0, [r0]
	adds r0, r4
	lsls r0, 24
	asrs r0, 24
	b _081C09AE
	.pool
_081C0960:
	ldr r3, =0x000040be
	adds r0, r2, r3
	ldrb r5, [r0]
	lsls r6, r4, 24
_081C0968:
	lsls r0, r5, 24
	asrs r0, 24
	asrs r1, r6, 24
	adds r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	asrs r4, r0, 24
	cmp r4, 0
	blt _081C0988
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040bf
	adds r0, r1
	ldrb r0, [r0]
	cmp r4, r0
	ble _081C099C
_081C0988:
	movs r0, 0x1
	negs r0, r0
	b _081C09AE
	.pool
_081C099C:
	movs r0, 0x64
	muls r0, r4
	adds r0, r7, r0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _081C0968
	adds r0, r4, 0
_081C09AE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C08F8

	thumb_func_start sub_81C09B4
sub_81C09B4: @ 81C09B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	ldr r6, =gUnknown_0203CF1C
	ldr r0, [r6]
	ldr r1, [r0]
	mov r8, r1
	movs r5, 0
	movs r2, 0
	ldr r3, =gUnknown_0861CC1C
	movs r1, 0
	ldrsb r1, [r3, r1]
	ldr r4, =0x000040be
	adds r0, r4
	ldrb r0, [r0]
	cmp r1, r0
	beq _081C09FC
	adds r7, r3, 0
	adds r3, r4, 0
_081C09E0:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x5
	bhi _081C09FC
	adds r0, r2, r7
	movs r1, 0
	ldrsb r1, [r0, r1]
	ldr r0, [r6]
	adds r0, r3
	ldrb r0, [r0]
	cmp r1, r0
	bne _081C09E0
	adds r5, r2, 0
_081C09FC:
	mov r0, r12
	lsls r6, r0, 24
	ldr r7, =gUnknown_0861CC1C
_081C0A02:
	lsls r0, r5, 24
	asrs r0, 24
	asrs r1, r6, 24
	adds r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, r5, 24
	lsrs r0, r1, 24
	cmp r0, 0x5
	bhi _081C0A40
	asrs r0, r1, 24
	adds r0, r7
	movs r4, 0
	ldrsb r4, [r0, r4]
	movs r0, 0x64
	muls r0, r4
	add r0, r8
	bl sub_81C0A50
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C0A02
	adds r0, r4, 0
	b _081C0A44
	.pool
_081C0A40:
	movs r0, 0x1
	negs r0, r0
_081C0A44:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C09B4

	thumb_func_start sub_81C0A50
sub_81C0A50: @ 81C0A50
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _081C0A84
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040be
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0A78
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _081C0A84
_081C0A78:
	movs r0, 0x1
	b _081C0A86
	.pool
_081C0A84:
	movs r0, 0
_081C0A86:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C0A50

	thumb_func_start sub_81C0A8C
sub_81C0A8C: @ 81C0A8C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	str r6, [sp]
	lsls r1, 24
	lsrs r3, r1, 24
	str r3, [sp, 0x4]
	ldr r0, =gUnknown_0203CF1C
	mov r8, r0
	ldr r2, [r0]
	adds r1, r2, 0
	adds r1, 0x70
	lsls r0, r6, 2
	adds r0, r6
	lsls r7, r0, 3
	ldr r0, =gTasks + 0x8
	mov r9, r0
	adds r0, r7, r0
	str r0, [sp, 0x8]
	ldrb r1, [r1, 0x4]
	mov r10, r1
	cmp r1, 0
	bne _081C0B6E
	lsls r0, r3, 24
	asrs r5, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	bne _081C0AE0
	ldr r1, =0x000040c0
	adds r0, r2, r1
	ldr r3, =0x000040c1
	adds r1, r2, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081C0B6E
_081C0AE0:
	cmp r5, 0x1
	bne _081C0AF4
	ldr r1, =0x000040c0
	adds r0, r2, r1
	ldr r3, =0x000040c2
	adds r1, r2, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081C0B6E
_081C0AF4:
	movs r0, 0x5
	bl PlaySE
	mov r1, r8
	ldr r0, [r1]
	ldr r4, =0x000040c0
	adds r0, r4
	ldrb r0, [r0]
	bl sub_81C2C38
	mov r2, r8
	ldr r1, [r2]
	adds r1, r4
	ldrb r0, [r1]
	ldr r3, [sp, 0x4]
	adds r0, r3
	strb r0, [r1]
	mov r1, r10
	ldr r0, [sp, 0x8]
	strh r1, [r0]
	cmp r5, 0x1
	bne _081C0B4C
	ldr r1, =sub_81C0B8C
	mov r0, r9
	subs r0, 0x8
	adds r0, r7, r0
	ldr r2, [r0]
	adds r0, r6, 0
	bl SetTaskFuncWithFollowupFunc
	b _081C0B5C
	.pool
_081C0B4C:
	ldr r1, =sub_81C0CC4
	mov r0, r9
	subs r0, 0x8
	adds r0, r7, r0
	ldr r2, [r0]
	ldr r0, [sp]
	bl SetTaskFuncWithFollowupFunc
_081C0B5C:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r2, =0x000040c0
	adds r0, r2
	ldrb r0, [r0]
	bl sub_81C2DE4
	bl sub_81C424C
_081C0B6E:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0A8C

	thumb_func_start sub_81C0B8C
sub_81C0B8C: @ 81C0B8C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081C0C2A
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r3, =0x000040c9
	adds r0, r3
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0BE0
	movs r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	b _081C0BFE
	.pool
_081C0BE0:
	movs r0, 0x2
	strh r0, [r4, 0x2]
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
_081C0BFE:
	ldrb r0, [r4, 0x2]
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	ldrb r0, [r4, 0x2]
	ldr r1, =gUnknown_0203CF1C
	ldr r1, [r1]
	ldr r3, =0x000040c0
	adds r2, r1, r3
	ldrb r2, [r2]
	lsls r2, 12
	adds r2, 0xBC
	adds r1, r2
	bl SetBgTilemapBuffer
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
_081C0C2A:
	ldrb r0, [r4, 0x2]
	movs r1, 0x80
	lsls r1, 6
	movs r2, 0x1
	bl ChangeBgX
	ldrh r0, [r4]
	adds r0, 0x20
	strh r0, [r4]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _081C0C52
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C0C68
	str r0, [r1]
_081C0C52:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0B8C

	thumb_func_start sub_81C0C68
sub_81C0C68: @ 81C0C68
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 3
	ldr r0, =gTasks + 0x8
	adds r2, r0
	ldr r5, =gUnknown_0203CF1C
	ldr r3, [r5]
	ldr r0, =0x000040c9
	adds r3, r0
	ldrb r0, [r3]
	movs r1, 0x1
	eors r0, r1
	movs r1, 0
	strb r0, [r3]
	strh r1, [r2, 0x2]
	strh r1, [r2]
	bl sub_81C1BA0
	ldr r0, [r5]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81C2AFC
	bl sub_81C4280
	bl sub_81C0E24
	adds r0, r4, 0
	bl SwitchTaskToFollowupFunc
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0C68

	thumb_func_start sub_81C0CC4
sub_81C0CC4: @ 81C0CC4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081C0D0C
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c9
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0CFC
	movs r0, 0x2
	b _081C0CFE
	.pool
_081C0CFC:
	movs r0, 0x1
_081C0CFE:
	strh r0, [r4, 0x2]
	ldrb r0, [r4, 0x2]
	movs r1, 0x80
	lsls r1, 9
	movs r2, 0
	bl ChangeBgX
_081C0D0C:
	ldrb r0, [r4, 0x2]
	movs r1, 0x80
	lsls r1, 6
	movs r2, 0x2
	bl ChangeBgX
	ldrh r0, [r4]
	adds r0, 0x20
	strh r0, [r4]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xFF
	ble _081C0D34
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C0D44
	str r0, [r1]
_081C0D34:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0CC4

	thumb_func_start sub_81C0D44
sub_81C0D44: @ 81C0D44
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c9
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0D8C
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	b _081C0DA6
	.pool
_081C0D8C:
	movs r0, 0x2
	movs r1, 0x7
	movs r2, 0x1
	bl SetBgAttribute
	movs r0, 0x1
	movs r1, 0x7
	movs r2, 0x2
	bl SetBgAttribute
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
_081C0DA6:
	ldr r6, =gUnknown_0203CF1C
	ldr r2, [r6]
	ldr r7, =0x000040c0
	adds r1, r2, r7
	ldrb r0, [r1]
	cmp r0, 0x1
	bls _081C0DD0
	ldrb r0, [r4, 0x2]
	ldrb r1, [r1]
	lsls r1, 12
	ldr r3, =0xfffff0bc
	adds r1, r3
	adds r1, r2, r1
	bl SetBgTilemapBuffer
	ldrb r0, [r4, 0x2]
	movs r1, 0x80
	lsls r1, 9
	movs r2, 0
	bl ChangeBgX
_081C0DD0:
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	ldr r2, [r6]
	ldr r0, =0x000040c9
	adds r2, r0
	ldrb r0, [r2]
	movs r1, 0x1
	eors r0, r1
	movs r1, 0
	strb r0, [r2]
	strh r1, [r4, 0x2]
	strh r1, [r4]
	bl sub_81C1BA0
	ldr r0, [r6]
	adds r0, r7
	ldrb r0, [r0]
	bl sub_81C2AFC
	bl sub_81C4280
	bl sub_81C0E24
	adds r0, r5, 0
	bl SwitchTaskToFollowupFunc
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0D44

	thumb_func_start sub_81C0E24
sub_81C0E24: @ 81C0E24
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040c0
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C0E3C
	adds r0, r1, 0
	adds r0, 0xC
	bl sub_81C22CC
_081C0E3C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0E24

	thumb_func_start sub_81C0E48
sub_81C0E48: @ 81C0E48
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	ldr r2, =0x000040c6
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	ldr r1, [r5]
	adds r2, r1, r2
	ldrb r0, [r2]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r6, [r1]
	mov r8, r6
	movs r0, 0x13
	bl ClearWindowTilemap
	ldr r2, =gSprites
	ldr r0, [r5]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C0E96
	movs r0, 0xD
	bl ClearWindowTilemap
_081C0E96:
	movs r4, 0x3
	negs r4, r4
	movs r0, 0x9
	adds r1, r4, 0
	bl sub_81C1DA4
	movs r0, 0x9
	adds r1, r4, 0
	adds r2, r6, 0
	bl sub_81C1EFC
	ldr r0, [r5]
	ldr r1, =0x000040c8
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C0EC4
	movs r0, 0x5
	bl ClearWindowTilemap
	movs r0, 0x6
	bl PutWindowTilemap
_081C0EC4:
	ldr r0, [r5]
	ldr r1, =0x000020bc
	adds r0, r1
	movs r1, 0x3
	movs r2, 0
	bl sub_81C2194
	ldr r0, [r5]
	ldr r1, =0x000030bc
	adds r0, r1
	movs r1, 0x1
	movs r2, 0
	bl sub_81C2194
	mov r0, r8
	bl sub_81C3E9C
	bl sub_81C3F44
	bl sub_81C44F0
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x8
	bl sub_81C4AF8
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C0F44
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C0E48

	thumb_func_start sub_81C0F44
sub_81C0F44: @ 81C0F44
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C103A
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081C0F98
	movs r0, 0x4
	strh r0, [r4]
	movs r1, 0x1
	negs r1, r1
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c6
	adds r2, r0
	adds r0, r4, 0
	bl sub_81C1070
	b _081C103A
	.pool
_081C0F98:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C0FC0
	movs r0, 0x4
	strh r0, [r4]
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c6
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C1070
	b _081C103A
	.pool
_081C0FC0:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C1026
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040c8
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081C0FE8
	subs r2, 0x4
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	bne _081C1004
_081C0FE8:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81C11F4
	b _081C103A
	.pool
_081C1004:
	bl sub_81C1040
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C101E
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81C129C
	b _081C103A
_081C101E:
	movs r0, 0x20
	bl PlaySE
	b _081C103A
_081C1026:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C103A
	movs r0, 0x5
	bl PlaySE
	adds r0, r6, 0
	bl sub_81C11F4
_081C103A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C0F44

	thumb_func_start sub_81C1040
sub_81C1040: @ 81C1040
	push {lr}
	movs r1, 0x1
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0x84
_081C104C:
	lsls r0, r1, 1
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r0, 0
	beq _081C1060
	movs r0, 0x1
	b _081C106C
	.pool
_081C1060:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081C104C
	movs r0, 0
_081C106C:
	pop {r1}
	bx r1
	thumb_func_end sub_81C1040

	thumb_func_start sub_81C1070
sub_81C1070: @ 81C1070
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r7, r0, 0
	adds r4, r1, 0
	mov r8, r2
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x5
	bl PlaySE
	mov r0, r8
	ldrb r6, [r0]
	movs r2, 0
	lsls r4, 24
	asrs r4, 24
	mov r12, r4
	movs r1, 0
	ldrsh r4, [r7, r1]
	ldrb r0, [r7]
	lsls r3, r0, 24
_081C109C:
	lsls r0, r6, 24
	asrs r0, 24
	add r0, r12
	lsls r0, 24
	lsrs r6, r0, 24
	asrs r0, 24
	cmp r0, r4
	ble _081C10B0
	movs r6, 0
	b _081C10B6
_081C10B0:
	cmp r0, 0
	bge _081C10B6
	lsrs r6, r3, 24
_081C10B6:
	lsls r0, r6, 24
	asrs r1, r0, 24
	mov r9, r0
	cmp r1, 0x4
	bne _081C10C2
	b _081C11CC
_081C10C2:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	lsls r1, 1
	adds r0, 0x84
	adds r0, r1
	ldrh r5, [r0]
	cmp r5, 0
	bne _081C10E2
	lsls r0, r2, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r2, r0, 24
	asrs r0, 24
	cmp r0, 0x3
	ble _081C109C
_081C10E2:
	adds r0, r5, 0
	bl sub_81C240C
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r5, 0
	bl sub_81C3E9C
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0x4
	bne _081C1110
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	beq _081C1118
_081C1110:
	movs r1, 0x2
	ldrsh r0, [r7, r1]
	cmp r0, 0x1
	bne _081C115E
_081C1118:
	movs r0, 0x13
	bl ClearWindowTilemap
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C1142
	movs r0, 0xD
	bl ClearWindowTilemap
_081C1142:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r4, 0x3
	negs r4, r4
	movs r0, 0x9
	adds r1, r4, 0
	bl sub_81C1DA4
	movs r0, 0x9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81C1EFC
_081C115E:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _081C11A0
	mov r1, r9
	asrs r0, r1, 24
	cmp r0, 0x4
	bne _081C11A0
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c4
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, 0
	bne _081C11A0
	movs r0, 0xE
	bl ClearWindowTilemap
	movs r0, 0xF
	bl ClearWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0
	movs r1, 0x3
	bl sub_81C1DA4
	movs r0, 0
	movs r1, 0x3
	movs r2, 0
	bl sub_81C1EFC
_081C11A0:
	mov r0, r8
	strb r6, [r0]
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c6
	adds r0, r1
	cmp r8, r0
	bne _081C11E0
	movs r0, 0x8
	bl sub_81C4D18
	b _081C11E6
	.pool
_081C11CC:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c4
	adds r0, r1
	ldrh r5, [r0]
	b _081C10E2
	.pool
_081C11E0:
	movs r0, 0x12
	bl sub_81C4D18
_081C11E6:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C1070

	thumb_func_start sub_81C11F4
sub_81C11F4: @ 81C11F4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x8
	bl sub_81C4C60
	movs r0, 0x6
	bl ClearWindowTilemap
	movs r0, 0x5
	bl PutWindowTilemap
	movs r0, 0
	bl sub_81C3E9C
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r1, =0x000020bc
	adds r0, r1
	movs r1, 0x3
	movs r2, 0x1
	bl sub_81C2194
	ldr r0, [r4]
	ldr r1, =0x000030bc
	adds r0, r1
	movs r1, 0x1
	movs r2, 0x1
	bl sub_81C2194
	bl sub_81C4064
	ldr r0, [r4]
	ldr r1, =0x000040c6
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x4
	beq _081C125E
	movs r0, 0xE
	bl ClearWindowTilemap
	movs r0, 0xF
	bl ClearWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl sub_81C1DA4
	movs r0, 0
	movs r1, 0x3
	movs r2, 0
	bl sub_81C1EFC
_081C125E:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C0510
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C11F4

	thumb_func_start sub_81C129C
sub_81C129C: @ 81C129C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r2, =0x000040c6
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r2, 0x1
	adds r0, r2
	strb r1, [r0]
	movs r0, 0x1
	bl sub_81C4C84
	movs r0, 0x12
	bl sub_81C4AF8
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C12E4
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C129C

	thumb_func_start sub_81C12E4
sub_81C12E4: @ 81C12E4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C13AA
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081C1338
	movs r0, 0x3
	strh r0, [r4]
	movs r1, 0x1
	negs r1, r1
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c7
	adds r2, r0
	adds r0, r4, 0
	bl sub_81C1070
	b _081C13AA
	.pool
_081C1338:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C1360
	movs r0, 0x3
	strh r0, [r4]
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c7
	adds r2, r0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C1070
	b _081C13AA
	.pool
_081C1360:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C139A
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r2, =0x000040c6
	adds r1, r0, r2
	adds r2, 0x1
	adds r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _081C1390
	adds r0, r5, 0
	movs r1, 0
	bl sub_81C13B0
	b _081C13AA
	.pool
_081C1390:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81C13B0
	b _081C13AA
_081C139A:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C13AA
	adds r0, r6, 0
	movs r1, 0
	bl sub_81C13B0
_081C13AA:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C12E4

	thumb_func_start sub_81C13B0
sub_81C13B0: @ 81C13B0
	push {r4-r7,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl sub_81C4C84
	movs r0, 0x12
	bl sub_81C4C60
	cmp r4, 0x1
	bne _081C1464
	ldr r0, =gUnknown_0203CF1C
	ldr r3, [r0]
	ldr r1, =0x000040bd
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C1410
	ldr r0, [r3]
	ldr r2, =0x000040be
	adds r1, r3, r2
	ldrb r2, [r1]
	movs r1, 0x64
	muls r1, r2
	adds r0, r1
	ldr r4, =0x000040c6
	adds r1, r3, r4
	ldrb r1, [r1]
	adds r4, 0x1
	adds r2, r3, r4
	ldrb r2, [r2]
	bl sub_81C14BC
	b _081C1430
	.pool
_081C1410:
	ldr r0, [r3]
	ldr r2, =0x000040be
	adds r1, r3, r2
	ldrb r2, [r1]
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 4
	adds r0, r1
	ldr r4, =0x000040c6
	adds r1, r3, r4
	ldrb r1, [r1]
	adds r4, 0x1
	adds r2, r3, r4
	ldrb r2, [r2]
	bl sub_81C15EC
_081C1430:
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	adds r0, 0xC
	bl sub_81C0098
	ldr r1, [r5]
	ldr r6, =0x000040c6
	adds r0, r1, r6
	ldrb r0, [r0]
	ldr r4, =0x000040c7
	adds r1, r4
	ldrb r1, [r1]
	bl sub_81C40A0
	ldr r1, [r5]
	adds r0, r1, r6
	ldrb r0, [r0]
	adds r1, r4
	ldrb r1, [r1]
	bl sub_81C4568
	ldr r0, [r5]
	adds r4, r0, r4
	ldrb r1, [r4]
	adds r0, r6
	strb r1, [r0]
_081C1464:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040c6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r4, [r1]
	adds r0, r4, 0
	bl sub_81C3E9C
	adds r0, r4, 0
	bl sub_81C240C
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C0F44
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C13B0

	thumb_func_start sub_81C14BC
sub_81C14BC: @ 81C14BC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	lsls r0, r4, 1
	mov r10, r0
	adds r1, r2, 0
	adds r1, 0x84
	adds r0, r1, r0
	str r0, [sp, 0x8]
	ldrh r0, [r0]
	mov r3, sp
	adds r3, 0x2
	str r3, [sp, 0x1C]
	strh r0, [r3]
	lsls r0, r6, 1
	mov r9, r0
	add r1, r9
	str r1, [sp, 0xC]
	ldrh r1, [r1]
	mov r0, sp
	strh r1, [r0]
	adds r1, r2, 0
	adds r1, 0x8C
	adds r3, r1, r4
	str r3, [sp, 0x10]
	ldrb r0, [r3]
	mov r3, sp
	adds r3, 0x5
	str r3, [sp, 0x24]
	strb r0, [r3]
	adds r1, r6
	str r1, [sp, 0x14]
	ldrb r0, [r1]
	mov r1, sp
	adds r1, 0x4
	str r1, [sp, 0x20]
	strb r0, [r1]
	adds r2, 0xA4
	str r2, [sp, 0x18]
	ldrb r0, [r2]
	mov r5, sp
	adds r5, 0x6
	strb r0, [r5]
	ldr r1, =gUnknown_08329D22
	adds r0, r4, r1
	ldrb r0, [r0]
	mov r8, r0
	ldrb r0, [r5]
	adds r2, r0, 0
	mov r3, r8
	ands r2, r3
	mov r3, r10
	asrs r2, r3
	lsls r2, 24
	lsrs r2, 24
	adds r1, r6, r1
	ldrb r1, [r1]
	mov r12, r1
	adds r1, r0, 0
	mov r3, r12
	ands r1, r3
	mov r3, r9
	asrs r1, r3
	lsls r1, 24
	lsrs r1, 24
	mov r3, r8
	bics r0, r3
	strb r0, [r5]
	ldrb r0, [r5]
	mov r3, r12
	bics r0, r3
	strb r0, [r5]
	mov r0, r9
	lsls r2, r0
	mov r3, r10
	lsls r1, r3
	adds r2, r1
	ldrb r0, [r5]
	orrs r0, r2
	strb r0, [r5]
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r7, 0
	mov r2, sp
	bl SetMonData
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r7, 0
	ldr r2, [sp, 0x1C]
	bl SetMonData
	adds r4, 0x11
	adds r0, r7, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x20]
	bl SetMonData
	adds r6, 0x11
	adds r0, r7, 0
	adds r1, r6, 0
	ldr r2, [sp, 0x24]
	bl SetMonData
	adds r0, r7, 0
	movs r1, 0x15
	adds r2, r5, 0
	bl SetMonData
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, [sp, 0x8]
	strh r0, [r1]
	ldr r3, [sp, 0x1C]
	ldrh r0, [r3]
	ldr r1, [sp, 0xC]
	strh r0, [r1]
	ldr r3, [sp, 0x20]
	ldrb r0, [r3]
	ldr r1, [sp, 0x10]
	strb r0, [r1]
	ldr r3, [sp, 0x24]
	ldrb r0, [r3]
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	ldrb r0, [r5]
	ldr r3, [sp, 0x18]
	strb r0, [r3]
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C14BC

	thumb_func_start sub_81C15EC
sub_81C15EC: @ 81C15EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x28
	adds r7, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	lsls r0, r4, 1
	mov r10, r0
	adds r1, r2, 0
	adds r1, 0x84
	adds r0, r1, r0
	str r0, [sp, 0x8]
	ldrh r0, [r0]
	mov r3, sp
	adds r3, 0x2
	str r3, [sp, 0x1C]
	strh r0, [r3]
	lsls r0, r6, 1
	mov r9, r0
	add r1, r9
	str r1, [sp, 0xC]
	ldrh r1, [r1]
	mov r0, sp
	strh r1, [r0]
	adds r1, r2, 0
	adds r1, 0x8C
	adds r3, r1, r4
	str r3, [sp, 0x10]
	ldrb r0, [r3]
	mov r3, sp
	adds r3, 0x5
	str r3, [sp, 0x24]
	strb r0, [r3]
	adds r1, r6
	str r1, [sp, 0x14]
	ldrb r0, [r1]
	mov r1, sp
	adds r1, 0x4
	str r1, [sp, 0x20]
	strb r0, [r1]
	adds r2, 0xA4
	str r2, [sp, 0x18]
	ldrb r0, [r2]
	mov r5, sp
	adds r5, 0x6
	strb r0, [r5]
	ldr r1, =gUnknown_08329D22
	adds r0, r4, r1
	ldrb r0, [r0]
	mov r8, r0
	ldrb r0, [r5]
	adds r2, r0, 0
	mov r3, r8
	ands r2, r3
	mov r3, r10
	asrs r2, r3
	lsls r2, 24
	lsrs r2, 24
	adds r1, r6, r1
	ldrb r1, [r1]
	mov r12, r1
	adds r1, r0, 0
	mov r3, r12
	ands r1, r3
	mov r3, r9
	asrs r1, r3
	lsls r1, 24
	lsrs r1, 24
	mov r3, r8
	bics r0, r3
	strb r0, [r5]
	ldrb r0, [r5]
	mov r3, r12
	bics r0, r3
	strb r0, [r5]
	mov r0, r9
	lsls r2, r0
	mov r3, r10
	lsls r1, r3
	adds r2, r1
	ldrb r0, [r5]
	orrs r0, r2
	strb r0, [r5]
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r7, 0
	mov r2, sp
	bl SetBoxMonData
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r7, 0
	ldr r2, [sp, 0x1C]
	bl SetBoxMonData
	adds r4, 0x11
	adds r0, r7, 0
	adds r1, r4, 0
	ldr r2, [sp, 0x20]
	bl SetBoxMonData
	adds r6, 0x11
	adds r0, r7, 0
	adds r1, r6, 0
	ldr r2, [sp, 0x24]
	bl SetBoxMonData
	adds r0, r7, 0
	movs r1, 0x15
	adds r2, r5, 0
	bl SetBoxMonData
	mov r0, sp
	ldrh r0, [r0]
	ldr r1, [sp, 0x8]
	strh r0, [r1]
	ldr r3, [sp, 0x1C]
	ldrh r0, [r3]
	ldr r1, [sp, 0xC]
	strh r0, [r1]
	ldr r3, [sp, 0x20]
	ldrb r0, [r3]
	ldr r1, [sp, 0x10]
	strb r0, [r1]
	ldr r3, [sp, 0x24]
	ldrb r0, [r3]
	ldr r1, [sp, 0x14]
	strb r0, [r1]
	ldrb r0, [r5]
	ldr r3, [sp, 0x18]
	strb r0, [r3]
	add sp, 0x28
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C15EC

	thumb_func_start sub_81C171C
sub_81C171C: @ 81C171C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81C44F0
	movs r0, 0x8
	bl sub_81C4AF8
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C174C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C171C

	thumb_func_start sub_81C174C
sub_81C174C: @ 81C174C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C176A
	b _081C189A
_081C176A:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r2, 0x80
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _081C177A
	b _081C189A
_081C177A:
	ldr r6, =gMain
	ldrh r1, [r6, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081C17B4
	movs r0, 0x4
	strh r0, [r4]
	movs r1, 0x1
	negs r1, r1
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c6
	adds r2, r0
	adds r0, r4, 0
	bl sub_81C1070
	b _081C189A
	.pool
_081C17B4:
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _081C17DC
	movs r0, 0x4
	strh r0, [r4]
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r1, =0x000040c6
	adds r2, r1
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C1070
	b _081C189A
	.pool
_081C17DC:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081C17F0
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C17FC
_081C17F0:
	movs r1, 0x1
	negs r1, r1
	adds r0, r5, 0
	bl sub_81C0A8C
	b _081C189A
_081C17FC:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081C1812
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081C181C
_081C1812:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81C0A8C
	b _081C189A
_081C181C:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C1876
	bl sub_81C18A8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C1868
	bl sub_81C48F0
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gUnknown_0203CF21
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c6
	adds r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r1, =gSpecialVar_0x8005
	ldrb r0, [r2]
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_81C044C
	b _081C189A
	.pool
_081C1868:
	movs r0, 0x20
	bl PlaySE
	adds r0, r5, 0
	bl sub_81C18F4
	b _081C189A
_081C1876:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C189A
	bl sub_81C48F0
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gUnknown_0203CF21
	movs r0, 0x4
	strb r0, [r1]
	ldr r1, =gSpecialVar_0x8005
	movs r0, 0x4
	strh r0, [r1]
	adds r0, r5, 0
	bl sub_81C044C
_081C189A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C174C

	thumb_func_start sub_81C18A8
sub_81C18A8: @ 81C18A8
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c6
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, 0x4
	beq _081C18DA
	ldr r3, =0x000040c4
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, 0
	beq _081C18DA
	ldrb r1, [r1]
	lsls r1, 1
	adds r0, r2, 0
	adds r0, 0x84
	adds r0, r1
	ldrh r0, [r0]
	bl sub_81B6D14
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C18EC
_081C18DA:
	movs r0, 0x1
	b _081C18EE
	.pool
_081C18EC:
	movs r0, 0
_081C18EE:
	pop {r1}
	bx r1
	thumb_func_end sub_81C18A8

	thumb_func_start sub_81C18F4
sub_81C18F4: @ 81C18F4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0xE
	bl ClearWindowTilemap
	movs r0, 0xF
	bl ClearWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0
	movs r1, 0x3
	bl sub_81C1DA4
	movs r0, 0
	movs r1, 0x3
	movs r2, 0
	bl sub_81C1EFC
	bl sub_81C4154
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C1940
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C18F4

	thumb_func_start sub_81C1940
sub_81C1940: @ 81C1940
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	mov r8, r0
	ldr r0, =gTasks + 0x8
	mov r9, r0
	mov r4, r8
	add r4, r9
	ldr r0, =sub_81C1E20
	bl FuncIsActiveTask
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C196C
	b _081C1B74
_081C196C:
	ldr r6, =gMain
	ldrh r1, [r6, 0x2E]
	movs r0, 0x40
	ands r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _081C19B0
	movs r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x4
	strh r0, [r4]
	movs r1, 0x1
	negs r1, r1
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r0, =0x000040c6
	adds r2, r0
	adds r0, r4, 0
	bl sub_81C1070
	movs r0, 0
	strh r0, [r4, 0x2]
	b _081C1B6A
	.pool
_081C19B0:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C19DC
	movs r0, 0x1
	strh r0, [r4, 0x2]
	movs r0, 0x4
	strh r0, [r4]
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r1, =0x000040c6
	adds r2, r1
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C1070
	strh r5, [r4, 0x2]
	b _081C1B6A
	.pool
_081C19DC:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081C19F0
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C1A64
_081C19F0:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r2, =0x000040c0
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081C1A00
	b _081C1B74
_081C1A00:
	movs r0, 0x13
	bl ClearWindowTilemap
	ldr r2, =gSprites
	ldr r0, [r4]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C1A28
	movs r0, 0xD
	bl ClearWindowTilemap
_081C1A28:
	ldr r1, [r4]
	ldr r2, =0x000040c6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r5, [r1]
	mov r0, r9
	subs r0, 0x8
	add r0, r8
	ldr r1, =sub_81C174C
	str r1, [r0]
	movs r1, 0x1
	negs r1, r1
	adds r0, r7, 0
	b _081C1ACE
	.pool
_081C1A64:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081C1A7A
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081C1B04
_081C1A7A:
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	beq _081C1B74
	movs r0, 0x13
	bl ClearWindowTilemap
	ldr r2, =gSprites
	ldr r0, [r4]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C1AB0
	movs r0, 0xD
	bl ClearWindowTilemap
_081C1AB0:
	ldr r1, [r4]
	ldr r2, =0x000040c6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r5, [r1]
	mov r0, r9
	subs r0, 0x8
	add r0, r8
	ldr r1, =sub_81C174C
	str r1, [r0]
	adds r0, r7, 0
	movs r1, 0x1
_081C1ACE:
	bl sub_81C0A8C
	movs r4, 0x2
	negs r4, r4
	movs r0, 0x9
	adds r1, r4, 0
	bl sub_81C1DA4
	movs r0, 0x9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81C1EFC
	b _081C1B74
	.pool
_081C1B04:
	ldrh r1, [r6, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081C1B74
	movs r0, 0x13
	bl ClearWindowTilemap
	ldr r2, =gSprites
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C1B38
	movs r0, 0xD
	bl ClearWindowTilemap
_081C1B38:
	ldr r1, [r4]
	ldr r2, =0x000040c6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r5, [r1]
	adds r0, r5, 0
	bl sub_81C3E9C
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r4, 0x3
	negs r4, r4
	movs r0, 0x9
	adds r1, r4, 0
	bl sub_81C1DA4
	movs r0, 0x9
	adds r1, r4, 0
	adds r2, r5, 0
	bl sub_81C1EFC
_081C1B6A:
	mov r0, r9
	subs r0, 0x8
	add r0, r8
	ldr r1, =sub_81C174C
	str r1, [r0]
_081C1B74:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C1940

	thumb_func_start sub_81C1B94
sub_81C1B94: @ 81C1B94
	ldr r0, =gUnknown_0203CF21
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81C1B94

	thumb_func_start sub_81C1BA0
sub_81C1BA0: @ 81C1BA0
	push {r4-r7,lr}
	sub sp, 0xC
	movs r0, 0x20
	bl Alloc
	adds r4, r0, 0
	movs r5, 0
_081C1BAE:
	lsls r0, r5, 25
	lsrs r1, r0, 24
	adds r6, r1, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r3, [r0]
	ldr r2, =0x000040c1
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r5, r0
	bcs _081C1BD8
	lsls r0, r1, 1
	adds r0, r4
	movs r1, 0x40
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r1, 0x50
	b _081C1BEE
	.pool
_081C1BD8:
	ldr r7, =0x000040c2
	adds r0, r3, r7
	ldrb r2, [r0]
	cmp r5, r2
	bls _081C1BF8
	lsls r0, r1, 1
	adds r0, r4
	movs r1, 0x4A
	strh r1, [r0]
	strh r1, [r0, 0x2]
	movs r1, 0x5A
_081C1BEE:
	strh r1, [r0, 0x10]
	strh r1, [r0, 0x12]
	b _081C1C78
	.pool
_081C1BF8:
	ldr r7, =0x000040c0
	adds r0, r3, r7
	ldrb r0, [r0]
	cmp r5, r0
	bcs _081C1C1C
	lsls r1, 1
	adds r1, r4
	movs r0, 0x46
	strh r0, [r1]
	movs r0, 0x47
	strh r0, [r1, 0x2]
	movs r0, 0x56
	strh r0, [r1, 0x10]
	movs r0, 0x57
	b _081C1C76
	.pool
_081C1C1C:
	cmp r5, r0
	bne _081C1C4C
	cmp r5, r2
	beq _081C1C38
	lsls r1, 1
	adds r1, r4
	movs r0, 0x41
	strh r0, [r1]
	movs r0, 0x42
	strh r0, [r1, 0x2]
	movs r0, 0x51
	strh r0, [r1, 0x10]
	movs r0, 0x52
	b _081C1C76
_081C1C38:
	lsls r1, 1
	adds r1, r4
	movs r0, 0x4B
	strh r0, [r1]
	movs r0, 0x4C
	strh r0, [r1, 0x2]
	movs r0, 0x5B
	strh r0, [r1, 0x10]
	movs r0, 0x5C
	b _081C1C76
_081C1C4C:
	cmp r5, r2
	beq _081C1C64
	lsls r1, 1
	adds r1, r4
	movs r0, 0x43
	strh r0, [r1]
	movs r0, 0x44
	strh r0, [r1, 0x2]
	movs r0, 0x53
	strh r0, [r1, 0x10]
	movs r0, 0x54
	b _081C1C76
_081C1C64:
	lsls r1, r6, 1
	adds r1, r4
	movs r0, 0x48
	strh r0, [r1]
	movs r0, 0x49
	strh r0, [r1, 0x2]
	movs r0, 0x58
	strh r0, [r1, 0x10]
	movs r0, 0x59
_081C1C76:
	strh r0, [r1, 0x12]
_081C1C78:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _081C1BAE
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
	movs r0, 0x10
	str r0, [sp, 0x8]
	movs r0, 0x3
	adds r1, r4, 0
	movs r2, 0xB
	movs r3, 0
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r4, 0
	bl Free
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C1BA0

	thumb_func_start sub_81C1CB0
sub_81C1CB0: @ 81C1CB0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r4, r0, 0
	mov r8, r1
	lsls r2, 24
	lsrs r6, r2, 24
	lsls r3, 24
	lsrs r5, r3, 24
	ldrb r1, [r4, 0x6]
	ldrb r0, [r4, 0x7]
	lsls r0, 1
	muls r0, r1
	bl Alloc
	adds r7, r0, 0
	mov r1, sp
	ldrh r0, [r4, 0x4]
	strh r0, [r1]
	ldrb r1, [r4, 0x7]
	ldrb r0, [r4, 0x6]
	adds r2, r1, 0
	muls r2, r0
	movs r0, 0x80
	lsls r0, 17
	orrs r2, r0
	mov r0, sp
	adds r1, r7, 0
	bl CpuSet
	ldrb r0, [r4, 0x6]
	cmp r0, r6
	beq _081C1D60
	cmp r5, 0
	bne _081C1D30
	movs r5, 0
	ldrb r0, [r4, 0x7]
	cmp r5, r0
	bcs _081C1D60
_081C1D00:
	ldrb r2, [r4, 0x6]
	adds r1, r2, 0
	muls r1, r5
	adds r3, r6, r1
	lsls r3, 1
	ldr r0, [r4]
	adds r0, r3
	lsls r1, 1
	adds r1, r7, r1
	subs r2, r6
	ldr r3, =0x001fffff
	ands r2, r3
	bl CpuSet
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r3, [r4, 0x7]
	cmp r5, r3
	bcc _081C1D00
	b _081C1D60
	.pool
_081C1D30:
	movs r5, 0
	ldrb r0, [r4, 0x7]
	cmp r5, r0
	bcs _081C1D60
_081C1D38:
	ldrb r2, [r4, 0x6]
	adds r1, r2, 0
	muls r1, r5
	lsls r3, r1, 1
	ldr r0, [r4]
	adds r0, r3
	adds r1, r6, r1
	lsls r1, 1
	adds r1, r7, r1
	subs r2, r6
	ldr r3, =0x001fffff
	ands r2, r3
	bl CpuSet
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r3, [r4, 0x7]
	cmp r5, r3
	bcc _081C1D38
_081C1D60:
	movs r5, 0
	b _081C1D8A
	.pool
_081C1D68:
	ldrb r2, [r4, 0x6]
	adds r0, r2, 0
	muls r0, r5
	lsls r0, 1
	adds r0, r7, r0
	ldrb r1, [r4, 0x9]
	adds r1, r5
	lsls r1, 5
	ldrb r3, [r4, 0x8]
	adds r1, r3
	lsls r1, 1
	add r1, r8
	bl CpuSet
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_081C1D8A:
	ldrb r0, [r4, 0x7]
	cmp r5, r0
	bcc _081C1D68
	adds r0, r7, 0
	bl Free
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C1CB0

	thumb_func_start sub_81C1DA4
sub_81C1DA4: @ 81C1DA4
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	asrs r1, 16
	ldr r3, =gUnknown_0861CC04
	ldrb r2, [r3, 0x6]
	cmp r1, r2
	ble _081C1DBA
	adds r4, r2, 0
_081C1DBA:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0
	beq _081C1DC6
	cmp r0, r2
	bne _081C1DE8
_081C1DC6:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r0, =0x000020bc
	adds r1, r0
	lsls r2, r4, 24
	lsrs r2, 24
	adds r0, r3, 0
	movs r3, 0x1
	bl sub_81C1CB0
	b _081C1E12
	.pool
_081C1DE8:
	ldr r5, =sub_81C1E20
	adds r0, r5, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _081C1E04
	adds r0, r5, 0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
_081C1E04:
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x8]
	strh r6, [r0, 0xA]
_081C1E12:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C1DA4

	thumb_func_start sub_81C1E20
sub_81C1E20: @ 81C1E20
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bge _081C1E50
	movs r0, 0
	strh r0, [r4, 0x2]
	ldr r7, =gUnknown_0861CC04
	b _081C1E60
	.pool
_081C1E50:
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldr r0, =gUnknown_0861CC04
	ldrb r2, [r0, 0x6]
	adds r7, r0, 0
	cmp r1, r2
	ble _081C1E60
	strh r2, [r4, 0x2]
_081C1E60:
	ldr r5, =gUnknown_0203CF1C
	ldr r1, [r5]
	ldr r0, =0x000020bc
	adds r1, r0
	ldrb r2, [r4, 0x2]
	adds r0, r7, 0
	movs r3, 0x1
	bl sub_81C1CB0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _081C1E80
	ldrb r7, [r7, 0x6]
	cmp r0, r7
	blt _081C1EE0
_081C1E80:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _081C1EAC
	ldr r0, [r5]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081C1ED4
	movs r0, 0xE
	bl PutWindowTilemap
	b _081C1ED4
	.pool
_081C1EAC:
	ldr r2, =gSprites
	ldr r0, [r5]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C1ECE
	movs r0, 0xD
	bl PutWindowTilemap
_081C1ECE:
	movs r0, 0x13
	bl PutWindowTilemap
_081C1ED4:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r6, 0
	bl DestroyTask
_081C1EE0:
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C1E20

	thumb_func_start sub_81C1EFC
sub_81C1EFC: @ 81C1EFC
	push {r4-r7,lr}
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r1, 16
	lsls r2, 16
	lsrs r6, r2, 16
	lsrs r4, r1, 16
	asrs r1, 16
	ldr r3, =gUnknown_0861CC10
	ldrb r2, [r3, 0x6]
	cmp r1, r2
	ble _081C1F16
	adds r4, r2, 0
_081C1F16:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0
	beq _081C1F22
	cmp r0, r2
	bne _081C1F44
_081C1F22:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r0, =0x000030bc
	adds r1, r0
	lsls r2, r4, 24
	lsrs r2, 24
	adds r0, r3, 0
	movs r3, 0x1
	bl sub_81C1CB0
	b _081C1F70
	.pool
_081C1F44:
	ldr r5, =sub_81C1F80
	adds r0, r5, 0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	bne _081C1F60
	adds r0, r5, 0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r2, r0, 24
_081C1F60:
	ldr r1, =gTasks
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	adds r0, r1
	strh r4, [r0, 0x8]
	strh r7, [r0, 0xA]
	strh r6, [r0, 0xC]
_081C1F70:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C1EFC

	thumb_func_start sub_81C1F80
sub_81C1F80: @ 81C1F80
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	ldrh r1, [r4, 0x2]
	adds r0, r1
	strh r0, [r4, 0x2]
	lsls r0, 16
	cmp r0, 0
	bge _081C1FB0
	movs r0, 0
	strh r0, [r4, 0x2]
	ldr r7, =gUnknown_0861CC10
	b _081C1FC0
	.pool
_081C1FB0:
	movs r0, 0x2
	ldrsh r1, [r4, r0]
	ldr r0, =gUnknown_0861CC10
	ldrb r2, [r0, 0x6]
	adds r7, r0, 0
	cmp r1, r2
	ble _081C1FC0
	strh r2, [r4, 0x2]
_081C1FC0:
	ldr r5, =gUnknown_0203CF1C
	ldr r1, [r5]
	ldr r0, =0x000030bc
	adds r1, r0
	ldrb r2, [r4, 0x2]
	adds r0, r7, 0
	movs r3, 0x1
	bl sub_81C1CB0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	cmp r0, 0
	ble _081C1FE0
	ldrb r7, [r7, 0x6]
	cmp r0, r7
	blt _081C2058
_081C1FE0:
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bge _081C2024
	ldr r0, [r5]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C2006
	ldr r0, =sub_81C0B8C
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _081C2006
	movs r0, 0xF
	bl PutWindowTilemap
_081C2006:
	ldrh r0, [r4, 0x4]
	bl sub_81C240C
	b _081C204C
	.pool
_081C2024:
	ldr r2, =gSprites
	ldr r0, [r5]
	ldr r1, =0x000040d5
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	blt _081C2046
	movs r0, 0xD
	bl PutWindowTilemap
_081C2046:
	movs r0, 0x13
	bl PutWindowTilemap
_081C204C:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r6, 0
	bl DestroyTask
_081C2058:
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C1F80

	thumb_func_start sub_81C2074
sub_81C2074: @ 81C2074
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	asrs r1, 16
	ldr r3, =gUnknown_0861CBEC
	ldrb r2, [r3, 0x6]
	cmp r1, r2
	ble _081C208A
	adds r4, r2, 0
_081C208A:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0
	beq _081C2096
	cmp r0, r2
	bne _081C20C8
_081C2096:
	ldr r5, =gUnknown_0203CF1C
	ldr r1, [r5]
	adds r1, 0xBC
	lsls r4, 24
	lsrs r4, 24
	adds r0, r3, 0
	adds r2, r4, 0
	movs r3, 0
	bl sub_81C1CB0
	ldr r0, =gUnknown_0861CBF8
	ldr r1, [r5]
	adds r1, 0xBC
	adds r2, r4, 0
	movs r3, 0
	bl sub_81C1CB0
	b _081C20E2
	.pool
_081C20C8:
	ldr r0, =sub_81C20F0
	movs r1, 0x8
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	strh r4, [r1, 0x8]
	strh r5, [r1, 0xA]
_081C20E2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2074

	thumb_func_start sub_81C20F0
sub_81C20F0: @ 81C20F0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldrh r0, [r5]
	ldrh r1, [r5, 0x2]
	adds r0, r1
	strh r0, [r5, 0x2]
	lsls r0, 16
	cmp r0, 0
	bge _081C2120
	movs r0, 0
	strh r0, [r5, 0x2]
	ldr r7, =gUnknown_0861CBEC
	b _081C2130
	.pool
_081C2120:
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	ldr r0, =gUnknown_0861CBEC
	ldrb r2, [r0, 0x6]
	adds r7, r0, 0
	cmp r1, r2
	ble _081C2130
	strh r2, [r5, 0x2]
_081C2130:
	ldr r4, =gUnknown_0203CF1C
	ldr r1, [r4]
	adds r1, 0xBC
	ldrb r2, [r5, 0x2]
	adds r0, r7, 0
	movs r3, 0
	bl sub_81C1CB0
	ldr r0, =gUnknown_0861CBF8
	ldr r1, [r4]
	adds r1, 0xBC
	ldrb r2, [r5, 0x2]
	movs r3, 0
	bl sub_81C1CB0
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x2
	ldrsh r0, [r5, r1]
	cmp r0, 0
	ble _081C2162
	ldrb r7, [r7, 0x6]
	cmp r0, r7
	blt _081C2180
_081C2162:
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	bge _081C217A
	bl sub_81C4A88
	movs r0, 0xD
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
_081C217A:
	adds r0, r6, 0
	bl DestroyTask
_081C2180:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C20F0

	thumb_func_start sub_81C2194
sub_81C2194: @ 81C2194
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r2, 24
	lsls r1, 28
	lsrs r4, r1, 16
	ldr r7, =0x0000056a
	cmp r2, 0
	bne _081C21E4
	movs r3, 0
	ldr r5, =gUnknown_08DC3CD4
_081C21A8:
	adds r2, r7, r3
	lsls r2, 1
	adds r2, r6
	lsls r0, r3, 1
	adds r0, r5
	ldrh r1, [r0]
	adds r1, r4, r1
	strh r1, [r2]
	adds r0, r2, 0
	adds r0, 0x40
	strh r1, [r0]
	adds r2, 0x80
	adds r0, r3, 0
	adds r0, 0x14
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	adds r0, r4, r0
	strh r0, [r2]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x13
	bls _081C21A8
	b _081C221C
	.pool
_081C21E4:
	movs r3, 0
	ldr r5, =gUnknown_08DC3CD4
_081C21E8:
	adds r1, r7, r3
	lsls r1, 1
	adds r1, r6
	adds r0, r3, 0
	adds r0, 0x14
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	adds r0, r4, r0
	strh r0, [r1]
	adds r2, r1, 0
	adds r2, 0x40
	adds r0, r3, 0
	adds r0, 0x28
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	adds r0, r4, r0
	strh r0, [r2]
	adds r1, 0x80
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x13
	bls _081C21E8
_081C221C:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2194

	thumb_func_start sub_81C2228
sub_81C2228: @ 81C2228
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0
	bl CheckPartyPokerus
	lsls r0, 24
	cmp r0, 0
	bne _081C225C
	adds r0, r4, 0
	movs r1, 0
	bl CheckPartyHasHadPokerus
	lsls r0, 24
	cmp r0, 0
	beq _081C225C
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r2, =0x00000502
	adds r1, r0, r2
	movs r2, 0x2C
	b _081C2266
	.pool
_081C225C:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r2, =0x00000502
	adds r1, r0, r2
	ldr r2, =0x0000081a
_081C2266:
	strh r2, [r1]
	ldr r1, =0x00000d02
	adds r0, r1
	strh r2, [r0]
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2228

	thumb_func_start sub_81C228C
sub_81C228C: @ 81C228C
	push {lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _081C22AC
	movs r0, 0x8
	str r0, [sp]
	str r1, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x4
	movs r3, 0x8
	bl sub_8199C30
	b _081C22C0
_081C22AC:
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x5
	str r0, [sp, 0x4]
	movs r0, 0x3
	movs r1, 0x1
	movs r2, 0x4
	movs r3, 0x8
	bl sub_8199C30
_081C22C0:
	movs r0, 0x3
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_81C228C

	thumb_func_start sub_81C22CC
sub_81C22CC: @ 81C22CC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r6, r1, 0
	adds r6, 0x70
	ldrb r1, [r6, 0x5]
	mov r8, r0
	cmp r1, 0x63
	bhi _081C2340
	ldr r5, =gExperienceTables
	adds r2, r1, 0
	adds r1, r2, 0x1
	lsls r1, 2
	ldr r4, =gBaseStats
	ldrh r3, [r6]
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r4
	ldrb r3, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r3
	adds r1, r0
	adds r1, r5
	lsls r2, 2
	adds r2, r0
	adds r2, r5
	ldr r1, [r1]
	ldr r2, [r2]
	subs r1, r2
	ldr r0, [r6, 0x10]
	subs r4, r0, r2
	lsls r0, r4, 6
	bl __udivsi3
	adds r6, r0, 0
	movs r7, 0
	adds r0, r7, 0
	orrs r0, r6
	cmp r0, 0
	bne _081C2344
	cmp r4, 0
	beq _081C2344
	movs r6, 0x1
	movs r7, 0
	b _081C2344
	.pool
_081C2340:
	movs r6, 0
	movs r7, 0
_081C2344:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, =0x00001d66
	adds r2, r0
	mov r9, r2
	movs r0, 0
	mov r12, r0
	ldr r1, =0x00002062
	mov r10, r1
_081C2356:
	cmp r7, 0
	bgt _081C2362
	cmp r7, 0
	bne _081C237C
	cmp r6, 0x7
	bls _081C237C
_081C2362:
	mov r2, r12
	lsls r0, r2, 1
	add r0, r9
	ldr r2, =0x0000206a
	adds r1, r2, 0
	strh r1, [r0]
	b _081C23B6
	.pool
_081C237C:
	mov r1, r12
	lsls r0, r1, 1
	add r0, r9
	mov r8, r0
	adds r5, r7, 0
	adds r4, r6, 0
	cmp r7, 0
	bge _081C2394
	movs r4, 0x7
	movs r5, 0
	adds r4, r6
	adcs r5, r7
_081C2394:
	lsls r3, r5, 29
	lsrs r2, r4, 3
	adds r0, r3, 0
	orrs r0, r2
	asrs r1, r5, 3
	lsrs r5, r0, 29
	lsls r4, r1, 3
	adds r3, r5, 0
	orrs r3, r4
	lsls r2, r0, 3
	adds r1, r7, 0
	adds r0, r6, 0
	subs r0, r2
	sbcs r1, r3
	add r0, r10
	mov r2, r8
	strh r0, [r2]
_081C23B6:
	movs r0, 0x8
	negs r0, r0
	asrs r1, r0, 31
	adds r6, r0
	adcs r7, r1
	cmp r7, 0
	bge _081C23C8
	movs r6, 0
	movs r7, 0
_081C23C8:
	mov r0, r12
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	cmp r0, 0x7
	bls _081C2356
	movs r0, 0x1
	bl GetBgTilemapBuffer
	ldr r1, =gUnknown_0203CF1C
	ldr r1, [r1]
	ldr r2, =0x000010bc
	adds r1, r2
	cmp r0, r1
	bne _081C23F8
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	b _081C23FE
	.pool
_081C23F8:
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
_081C23FE:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C22CC

	thumb_func_start sub_81C240C
sub_81C240C: @ 81C240C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000038bc
	adds r5, r0, r1
	cmp r3, 0
	beq _081C2510
	ldr r1, =gContestEffects
	ldr r2, =gContestMoves
	lsls r3, 3
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldrb r4, [r0, 0x1]
	mov r9, r1
	mov r8, r2
	mov r10, r3
	cmp r4, 0xFF
	beq _081C244C
	adds r0, r4, 0
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r4, r0, 24
_081C244C:
	movs r2, 0
	movs r6, 0x3
	movs r3, 0xF3
	lsls r3, 2
_081C2454:
	cmp r4, 0xFF
	beq _081C2484
	cmp r2, r4
	bcs _081C2484
	lsrs r0, r2, 2
	adds r1, r2, 0
	ands r1, r6
	lsls r0, 5
	adds r0, r1
	lsls r0, 1
	adds r0, r5
	adds r0, r3
	ldr r7, =0x0000103a
	b _081C2496
	.pool
_081C2484:
	lsrs r0, r2, 2
	adds r1, r2, 0
	ands r1, r6
	lsls r0, 5
	adds r0, r1
	lsls r0, 1
	adds r0, r5
	adds r0, r3
	ldr r7, =0x00001039
_081C2496:
	adds r1, r7, 0
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _081C2454
	mov r0, r10
	add r0, r8
	ldrb r0, [r0]
	lsls r0, 2
	add r0, r9
	ldrb r4, [r0, 0x2]
	cmp r4, 0xFF
	beq _081C24C0
	adds r0, r4, 0
	movs r1, 0xA
	bl __udivsi3
	lsls r0, 24
	lsrs r4, r0, 24
_081C24C0:
	movs r2, 0
	movs r6, 0x3
	ldr r3, =0x0000044c
_081C24C6:
	cmp r4, 0xFF
	beq _081C24F0
	cmp r2, r4
	bcs _081C24F0
	lsrs r0, r2, 2
	adds r1, r2, 0
	ands r1, r6
	lsls r0, 5
	adds r0, r1
	lsls r0, 1
	adds r0, r5
	adds r0, r3
	ldr r7, =0x0000103c
	b _081C2502
	.pool
_081C24F0:
	lsrs r0, r2, 2
	adds r1, r2, 0
	ands r1, r6
	lsls r0, 5
	adds r0, r1
	lsls r0, 1
	adds r0, r5
	adds r0, r3
	ldr r7, =0x0000103d
_081C2502:
	adds r1, r7, 0
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x7
	bls _081C24C6
_081C2510:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C240C

	thumb_func_start sub_81C2524
sub_81C2524: @ 81C2524
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x74
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C2544
	movs r1, 0x80
	lsls r1, 9
	movs r0, 0x3
	movs r2, 0
	bl ChangeBgX
	b _081C254E
	.pool
_081C2544:
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
_081C254E:
	pop {r0}
	bx r0
	thumb_func_end sub_81C2524

	thumb_func_start sub_81C2554
sub_81C2554: @ 81C2554
	push {r4,r5,lr}
	ldr r0, =gUnknown_0861CC24
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r4, 0
_081C2562:
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x13
	bls _081C2562
	movs r4, 0
	ldr r5, =gUnknown_0203CF1C
	ldr r3, =0x000040cb
	movs r2, 0xFF
_081C257C:
	ldr r0, [r5]
	adds r0, r3
	adds r0, r4
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081C257C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2554

	thumb_func_start sub_81C25A4
sub_81C25A4: @ 81C25A4
	push {r4-r6,lr}
	sub sp, 0x14
	ldr r4, [sp, 0x24]
	ldr r5, [sp, 0x28]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	movs r6, 0
	str r6, [sp]
	str r4, [sp, 0x4]
	lsls r4, r5, 1
	adds r4, r5
	ldr r5, =gUnknown_0861CD2C
	adds r4, r5
	str r4, [sp, 0x8]
	str r6, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x1
	bl AddTextPrinterParametrized2
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C25A4

	thumb_func_start sub_81C25E8
sub_81C25E8: @ 81C25E8
	push {lr}
	movs r0, 0x11
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x12
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0x13
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x74
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C2618
	bl sub_81C2628
	b _081C261C
	.pool
_081C2618:
	bl sub_81C2794
_081C261C:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_81C25E8

	thumb_func_start sub_81C2628
sub_81C2628: @ 81C2628
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x18
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	movs r1, 0xC
	adds r1, r0
	mov r8, r1
	adds r7, r0, 0
	adds r7, 0x70
	ldrh r0, [r7]
	bl SpeciesToPokedexNum
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _081C26CE
	ldr r6, =gStringVar1
	ldr r1, =gText_UnkCtrlF908Clear01
	adds r0, r6, 0
	bl StringCopy
	ldr r4, =gStringVar2
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x2
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r6, 0
	adds r1, r4, 0
	bl StringAppend
	mov r0, r8
	bl IsMonShiny
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	bne _081C26AC
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x11
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	movs r0, 0
	bl sub_81C228C
	b _081C26C6
	.pool
_081C26AC:
	movs r0, 0
	str r0, [sp]
	movs r0, 0x7
	str r0, [sp, 0x4]
	movs r0, 0x11
	adds r1, r6, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	movs r0, 0x1
	bl sub_81C228C
_081C26C6:
	movs r0, 0x11
	bl PutWindowTilemap
	b _081C26EE
_081C26CE:
	movs r0, 0x11
	bl ClearWindowTilemap
	mov r0, r8
	bl IsMonShiny
	lsls r0, 24
	cmp r0, 0
	bne _081C26E8
	movs r0, 0
	bl sub_81C228C
	b _081C26EE
_081C26E8:
	movs r0, 0x1
	bl sub_81C228C
_081C26EE:
	ldr r4, =gStringVar1
	ldr r1, =gText_LevelSymbol
	adds r0, r4, 0
	bl StringCopy
	ldr r5, =gStringVar2
	ldrb r1, [r7, 0x5]
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r4, 0
	adds r1, r5, 0
	bl StringAppend
	movs r6, 0
	str r6, [sp]
	movs r5, 0x1
	str r5, [sp, 0x4]
	movs r0, 0x13
	adds r1, r4, 0
	movs r2, 0x18
	movs r3, 0x11
	bl sub_81C25A4
	mov r0, r8
	adds r1, r4, 0
	bl GetMonNickname
	str r6, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x12
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	add r1, sp, 0x8
	movs r0, 0xBA
	strb r0, [r1]
	mov r0, sp
	adds r0, 0x9
	ldrh r2, [r7, 0x2]
	movs r1, 0xB
	muls r1, r2
	ldr r2, =gSpeciesNames
	adds r1, r2
	bl StringCopy
	str r6, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x13
	add r1, sp, 0x8
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldrh r1, [r7, 0x2]
	mov r0, r8
	bl sub_81C27DC
	movs r0, 0x12
	bl PutWindowTilemap
	movs r0, 0x13
	bl PutWindowTilemap
	add sp, 0x18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2628

	thumb_func_start sub_81C2794
sub_81C2794: @ 81C2794
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0xC
	ldr r4, =gStringVar1
	adds r1, r4, 0
	bl GetMonNickname
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	movs r0, 0x12
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	movs r0, 0x12
	bl PutWindowTilemap
	movs r0, 0x11
	bl ClearWindowTilemap
	movs r0, 0x13
	bl ClearWindowTilemap
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2794

	thumb_func_start sub_81C27DC
sub_81C27DC: @ 81C27DC
	push {lr}
	sub sp, 0x8
	lsls r1, 16
	lsrs r1, 16
	cmp r1, 0x20
	beq _081C282C
	cmp r1, 0x1D
	beq _081C282C
	bl GetMonGender
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081C27FE
	cmp r0, 0xFE
	beq _081C2818
	b _081C282C
_081C27FE:
	ldr r1, =gText_MaleSymbol
	str r0, [sp]
	movs r0, 0x3
	str r0, [sp, 0x4]
	movs r0, 0x13
	movs r2, 0x39
	movs r3, 0x11
	bl sub_81C25A4
	b _081C282C
	.pool
_081C2818:
	ldr r1, =gText_FemaleSymbol
	movs r0, 0
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0x13
	movs r2, 0x39
	movs r3, 0x11
	bl sub_81C25A4
_081C282C:
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C27DC

	thumb_func_start sub_81C2838
sub_81C2838: @ 81C2838
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	ldr r3, =gUnknown_0861CDD3
	cmp r1, 0
	bne _081C284A
	subs r3, 0x80
_081C284A:
	lsls r2, 16
	lsrs r2, 16
	movs r0, 0x10
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	adds r1, r3, 0
	movs r3, 0
	bl BlitBitmapToWindow
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2838

	thumb_func_start sub_81C286C
sub_81C286C: @ 81C286C
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r1, =gUnknown_085EA3CF
	movs r5, 0
	str r5, [sp]
	movs r6, 0x1
	str r6, [sp, 0x4]
	movs r0, 0
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA3DC
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0x1
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA3EB
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0x2
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA3F8
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0x3
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	ldr r7, =gText_Cancel2
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x3E
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	adds r2, r4, 0
	subs r2, 0x10
	cmp r2, 0
	bge _081C28CC
	movs r2, 0
_081C28CC:
	movs r0, 0x4
	movs r1, 0
	bl sub_81C2838
	lsls r2, r4, 24
	lsrs r2, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x4
	adds r1, r7, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r7, =gUnknown_085EA406
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x3E
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	adds r2, r4, 0
	subs r2, 0x10
	cmp r2, 0
	bge _081C28FE
	movs r2, 0
_081C28FE:
	movs r0, 0x5
	movs r1, 0
	bl sub_81C2838
	lsls r2, r4, 24
	lsrs r2, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x5
	adds r1, r7, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r7, =gUnknown_085EA3C8
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x3E
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	adds r2, r4, 0
	subs r2, 0x10
	cmp r2, 0
	bge _081C2930
	movs r2, 0
_081C2930:
	movs r0, 0x6
	movs r1, 0
	bl sub_81C2838
	lsls r2, r4, 24
	lsrs r2, 24
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x6
	adds r1, r7, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA369
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0x8
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA378
	str r5, [sp]
	str r5, [sp, 0x4]
	movs r0, 0x9
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA361
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2A
	bl GetStringCenterAlignXOffset
	adds r0, 0x6
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xA
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA33C
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2A
	bl GetStringCenterAlignXOffset
	adds r0, 0x6
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xA
	adds r1, r4, 0
	movs r3, 0x11
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA343
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2A
	bl GetStringCenterAlignXOffset
	adds r0, 0x6
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xA
	adds r1, r4, 0
	movs r3, 0x21
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA34B
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x24
	bl GetStringCenterAlignXOffset
	adds r0, 0x2
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xB
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA353
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x24
	bl GetStringCenterAlignXOffset
	adds r0, 0x2
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xB
	adds r1, r4, 0
	movs r3, 0x11
	bl sub_81C25A4
	ldr r4, =gUnknown_085EA35B
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x24
	bl GetStringCenterAlignXOffset
	adds r0, 0x2
	lsls r2, r0, 24
	lsrs r2, 24
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xB
	adds r1, r4, 0
	movs r3, 0x21
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA39F
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xC
	movs r2, 0x6
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA3AB
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xC
	movs r2, 0x6
	movs r3, 0x11
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA398
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xD
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA37E
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xE
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA384
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xE
	movs r2, 0
	movs r3, 0x11
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA38D
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xF
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gUnknown_085EA394
	str r5, [sp]
	str r6, [sp, 0x4]
	movs r0, 0xF
	movs r2, 0
	movs r3, 0x11
	bl sub_81C25A4
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C286C

	thumb_func_start sub_81C2AFC
sub_81C2AFC: @ 81C2AFC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	movs r0, 0
	bl ClearWindowTilemap
	movs r0, 0x1
	bl ClearWindowTilemap
	movs r0, 0x2
	bl ClearWindowTilemap
	movs r0, 0x3
	bl ClearWindowTilemap
	cmp r4, 0x1
	beq _081C2B66
	cmp r4, 0x1
	bgt _081C2B2A
	cmp r4, 0
	beq _081C2B34
	b _081C2C06
_081C2B2A:
	cmp r5, 0x2
	beq _081C2B80
	cmp r5, 0x3
	beq _081C2BC4
	b _081C2C06
_081C2B34:
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x4
	bl PutWindowTilemap
	bl sub_81A6BF4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2B58
	bl sub_81B9E94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C2B5E
_081C2B58:
	movs r0, 0x8
	bl PutWindowTilemap
_081C2B5E:
	movs r0, 0x9
	bl PutWindowTilemap
	b _081C2C06
_081C2B66:
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0xA
	bl PutWindowTilemap
	movs r0, 0xB
	bl PutWindowTilemap
	movs r0, 0xC
	bl PutWindowTilemap
	b _081C2C06
_081C2B80:
	movs r0, 0x2
	bl PutWindowTilemap
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C2BBC
	adds r2, 0x8
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C2C06
	movs r0, 0xE
	bl PutWindowTilemap
	b _081C2C06
	.pool
_081C2BBC:
	movs r0, 0x5
	bl PutWindowTilemap
	b _081C2C06
_081C2BC4:
	movs r0, 0x3
	bl PutWindowTilemap
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C2C00
	adds r2, 0x8
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C2C06
	movs r0, 0xF
	bl PutWindowTilemap
	b _081C2C06
	.pool
_081C2C00:
	movs r0, 0x5
	bl PutWindowTilemap
_081C2C06:
	movs r4, 0
	ldr r5, =gUnknown_0203CF1C
_081C2C0A:
	ldr r0, [r5]
	ldr r1, =0x000040cb
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081C2C0A
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2AFC

	thumb_func_start sub_81C2C38
sub_81C2C38: @ 81C2C38
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x1
	beq _081C2C84
	cmp r0, 0x1
	bgt _081C2C4E
	cmp r0, 0
	beq _081C2C58
	b _081C2D0E
_081C2C4E:
	cmp r1, 0x2
	beq _081C2C98
	cmp r1, 0x3
	beq _081C2CD4
	b _081C2D0E
_081C2C58:
	movs r0, 0x4
	bl ClearWindowTilemap
	bl sub_81A6BF4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2C76
	bl sub_81B9E94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C2C7C
_081C2C76:
	movs r0, 0x8
	bl ClearWindowTilemap
_081C2C7C:
	movs r0, 0x9
	bl ClearWindowTilemap
	b _081C2D0E
_081C2C84:
	movs r0, 0xA
	bl ClearWindowTilemap
	movs r0, 0xB
	bl ClearWindowTilemap
	movs r0, 0xC
	bl ClearWindowTilemap
	b _081C2D0E
_081C2C98:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C2CCC
	adds r2, 0x8
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C2D0E
	movs r0, 0xE
	bl ClearWindowTilemap
	b _081C2D0E
	.pool
_081C2CCC:
	movs r0, 0x5
	bl ClearWindowTilemap
	b _081C2D0E
_081C2CD4:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C2D08
	adds r2, 0x8
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C2D0E
	movs r0, 0xF
	bl ClearWindowTilemap
	b _081C2D0E
	.pool
_081C2D08:
	movs r0, 0x5
	bl ClearWindowTilemap
_081C2D0E:
	movs r4, 0
_081C2D10:
	adds r0, r4, 0
	bl sub_81C2D68
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081C2D10
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C2C38

	thumb_func_start sub_81C2D2C
sub_81C2D2C: @ 81C2D2C
	push {r4,lr}
	adds r3, r0, 0
	lsls r1, 24
	lsrs r2, r1, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r4, =0x000040cb
	adds r1, r2, r4
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081C2D56
	lsls r0, r2, 3
	adds r0, r3, r0
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	bl FillWindowPixelBuffer
_081C2D56:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C2D2C

	thumb_func_start sub_81C2D68
sub_81C2D68: @ 81C2D68
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF1C
	ldr r2, =0x000040cb
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _081C2D8C
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0xFF
	strb r0, [r4]
_081C2D8C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2D68

	thumb_func_start sub_81C2D9C
sub_81C2D9C: @ 81C2D9C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
_081C2DA4:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040cb
	adds r0, r1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081C2DBA
	movs r1, 0
	bl FillWindowPixelBuffer
_081C2DBA:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x7
	bls _081C2DA4
	ldr r0, =gUnknown_0861CE54
	lsls r1, r5, 2
	adds r1, r0
	ldr r0, [r1]
	bl _call_via_r0
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2D9C

	thumb_func_start sub_81C2DE4
sub_81C2DE4: @ 81C2DE4
	push {lr}
	lsls r0, 24
	ldr r1, =gUnknown_0861CE64
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x10
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2DE4

	thumb_func_start sub_81C2E00
sub_81C2E00: @ 81C2E00
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x74
	ldrb r0, [r0]
	cmp r0, 0
	beq _081C2E24
	bl sub_81C335C
	bl sub_81C33CC
	bl sub_81C3428
	bl sub_81C349C
	b _081C2E3C
	.pool
_081C2E24:
	bl sub_81C2EC4
	bl sub_81C2F5C
	bl sub_81C2FD8
	bl sub_81C302C
	bl sub_81C307C
	bl sub_81C3194
_081C2E3C:
	pop {r0}
	bx r0
	thumb_func_end sub_81C2E00

	thumb_func_start sub_81C2E40
sub_81C2E40: @ 81C2E40
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bhi _081C2EB8
	lsls r0, 2
	ldr r1, =_081C2E70
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C2E70:
	.4byte _081C2E8C
	.4byte _081C2E92
	.4byte _081C2E98
	.4byte _081C2E9E
	.4byte _081C2EA4
	.4byte _081C2EAA
	.4byte _081C2EB0
_081C2E8C:
	bl sub_81C2EC4
	b _081C2EB8
_081C2E92:
	bl sub_81C2F5C
	b _081C2EB8
_081C2E98:
	bl sub_81C2FD8
	b _081C2EB8
_081C2E9E:
	bl sub_81C302C
	b _081C2EB8
_081C2EA4:
	bl sub_81C307C
	b _081C2EB8
_081C2EAA:
	bl sub_81C3194
	b _081C2EB8
_081C2EB0:
	adds r0, r2, 0
	bl DestroyTask
	b _081C2EBE
_081C2EB8:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081C2EBE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C2E40

	thumb_func_start sub_81C2EC4
sub_81C2EC4: @ 81C2EC4
	push {r4-r6,lr}
	sub sp, 0x8
	bl sub_81A6BF4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2F54
	bl sub_81B9E94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2F54
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gUnknown_085EA365
	movs r6, 0
	str r6, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0
	bl GetStringWidth
	adds r2, r0, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xA2
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C2F40
	adds r1, 0xA6
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	movs r0, 0x5
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r3, 0x1
	bl sub_81C25A4
	b _081C2F54
	.pool
_081C2F40:
	adds r1, 0xA6
	lsls r2, 24
	lsrs r2, 24
	str r6, [sp]
	movs r0, 0x6
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r3, 0x1
	bl sub_81C25A4
_081C2F54:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C2EC4

	thumb_func_start sub_81C2F5C
sub_81C2F5C: @ 81C2F5C
	push {r4,r5,lr}
	sub sp, 0x8
	bl sub_81A6BF4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2FC0
	bl sub_81B9E94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C2FC0
	ldr r5, =gStringVar1
	ldr r1, =gText_UnkCtrlF907F908
	adds r0, r5, 0
	bl StringCopy
	ldr r1, =gUnknown_0203CF1C
	ldr r1, [r1]
	adds r1, 0xB8
	ldrh r1, [r1]
	movs r2, 0x2
	movs r3, 0x5
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x38
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x1
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
_081C2FC0:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2F5C

	thumb_func_start sub_81C2FD8
sub_81C2FD8: @ 81C2FD8
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x70
	ldrh r0, [r0]
	adds r1, 0x78
	ldrb r1, [r1]
	bl GetAbilityBySpecies
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0xD
	muls r1, r4
	ldr r2, =gAbilityNames
	adds r1, r2
	movs r2, 0
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C2FD8

	thumb_func_start sub_81C302C
sub_81C302C: @ 81C302C
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0x70
	ldrh r0, [r0]
	adds r1, 0x78
	ldrb r1, [r1]
	bl GetAbilityBySpecies
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gAbilityDescriptionPointers
	lsls r4, 2
	adds r4, r1
	ldr r1, [r4]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r3, 0x11
	bl sub_81C25A4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C302C

	thumb_func_start sub_81C307C
sub_81C307C: @ 81C307C
	push {r4-r6,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r4, r0, 0
	adds r4, 0x70
	bl sub_81AFBF0
	ldr r1, =gUnknown_0861CE74
	movs r0, 0
	bl sub_81AFC0C
	ldr r1, =gUnknown_0861CE7B
	movs r0, 0x1
	bl sub_81AFC0C
	bl sub_81C31C0
	bl sub_81A6BF4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C30C2
	bl sub_81B9E94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C30C2
	bl sub_81C3304
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C30E0
_081C30C2:
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_085EA5DB
	bl sub_81AFC28
	b _081C3182
	.pool
_081C30E0:
	movs r0, 0x20
	bl Alloc
	adds r6, r0, 0
	movs r0, 0x20
	bl Alloc
	adds r5, r0, 0
	adds r0, r6, 0
	bl sub_81C31F0
	ldrb r0, [r4, 0x9]
	cmp r0, 0xD4
	bhi _081C310C
	adds r1, r0, 0
	adds r0, r5, 0
	bl sub_8124610
	movs r0, 0x4
	adds r1, r5, 0
	bl sub_81AFC0C
_081C310C:
	bl sub_81C3220
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C3148
	ldrb r0, [r4, 0xA]
	cmp r0, 0
	bne _081C3134
	ldrb r0, [r4, 0x9]
	ldr r1, =gUnknown_085EA516
	cmp r0, 0xD4
	bls _081C3170
	ldr r1, =gUnknown_085EA617
	b _081C3170
	.pool
_081C3134:
	ldrb r0, [r4, 0x9]
	ldr r1, =gUnknown_085EA4EC
	cmp r0, 0xD4
	bls _081C3170
	ldr r1, =gUnknown_085EA5EB
	b _081C3170
	.pool
_081C3148:
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFF
	bne _081C3158
	ldr r1, =gUnknown_085EA56A
	b _081C3170
	.pool
_081C3158:
	cmp r0, 0xFE
	beq _081C316E
	bl sub_81C32BC
	lsls r0, 24
	cmp r0, 0
	beq _081C316E
	ldrb r0, [r4, 0x9]
	ldr r1, =gUnknown_085EA5A8
	cmp r0, 0xD4
	bls _081C3170
_081C316E:
	ldr r1, =gUnknown_085EA544
_081C3170:
	ldr r0, =gStringVar4
	bl sub_81AFC28
	adds r0, r6, 0
	bl Free
	adds r0, r5, 0
	bl Free
_081C3182:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C307C

	thumb_func_start sub_81C3194
sub_81C3194: @ 81C3194
	push {lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x3
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gStringVar4
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3194

	thumb_func_start sub_81C31C0
sub_81C31C0: @ 81C31C0
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =gNatureNamePointers
	adds r0, 0xA3
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x2
	bl sub_81AFC0C
	ldr r1, =gUnknown_085EA3C0
	movs r0, 0x5
	bl sub_81AFC0C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C31C0

	thumb_func_start sub_81C31F0
sub_81C31F0: @ 81C31F0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x7A
	ldrb r1, [r0]
	cmp r1, 0
	bne _081C3202
	movs r1, 0x5
_081C3202:
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	movs r0, 0x3
	adds r1, r4, 0
	bl sub_81AFC0C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C31F0

	thumb_func_start sub_81C3220
sub_81C3220: @ 81C3220
	push {r4-r6,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r6, r0, 0
	adds r6, 0x70
	ldr r1, [r0]
	ldr r0, =gEnemyParty
	cmp r1, r0
	bne _081C326C
	bl GetMultiplayerId
	movs r1, 0x1
	eors r0, r1
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gLinkPlayers
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r0, r2, 0x4
	adds r0, r1, r0
	ldrh r4, [r0]
	adds r0, r1, r2
	ldrb r5, [r0, 0x13]
	ldr r0, =gStringVar1
	adds r2, 0x8
	adds r1, r2
	bl StringCopy
	b _081C3282
	.pool
_081C326C:
	bl sub_80F0020
	adds r4, r0, 0
	ldr r0, =0x0000ffff
	ands r4, r0
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	ldrb r5, [r1, 0x8]
	ldr r0, =gStringVar1
	bl StringCopy
_081C3282:
	adds r0, r6, 0
	adds r0, 0x32
	ldrb r0, [r0]
	cmp r5, r0
	bne _081C32A4
	ldr r0, [r6, 0x48]
	ldr r1, =0x0000ffff
	ands r0, r1
	cmp r4, r0
	bne _081C32A4
	ldr r0, =gStringVar1
	adds r1, r6, 0
	adds r1, 0x36
	bl StringCompareWithoutExtCtrlCodes
	cmp r0, 0
	beq _081C32B4
_081C32A4:
	movs r0, 0
	b _081C32B6
	.pool
_081C32B4:
	movs r0, 0x1
_081C32B6:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C3220

	thumb_func_start sub_81C32BC
sub_81C32BC: @ 81C32BC
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x70
	ldrb r0, [r0, 0xB]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bls _081C32D8
	movs r0, 0
	b _081C32DA
	.pool
_081C32D8:
	movs r0, 0x1
_081C32DA:
	pop {r1}
	bx r1
	thumb_func_end sub_81C32BC

	thumb_func_start sub_81C32E0
sub_81C32E0: @ 81C32E0
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r0, 0x70
	ldrb r0, [r0, 0xB]
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bls _081C32FC
	movs r0, 0
	b _081C32FE
	.pool
_081C32FC:
	movs r0, 0x1
_081C32FE:
	pop {r1}
	bx r1
	thumb_func_end sub_81C32E0

	thumb_func_start sub_81C3304
sub_81C3304: @ 81C3304
	push {lr}
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 15
	ands r0, r1
	cmp r0, 0
	beq _081C3354
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C3354
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040be
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081C333A
	cmp r0, 0x4
	beq _081C333A
	cmp r0, 0x5
	bne _081C3354
_081C333A:
	movs r0, 0x1
	b _081C3356
	.pool
_081C3354:
	movs r0, 0
_081C3356:
	pop {r1}
	bx r1
	thumb_func_end sub_81C3304

	thumb_func_start sub_81C335C
sub_81C335C: @ 81C335C
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0
	bl sub_81C2D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_085EA365
	mov r8, r0
	movs r0, 0x1
	mov r1, r8
	movs r2, 0
	bl GetStringWidth
	adds r5, r0, 0
	movs r0, 0
	mov r9, r0
	str r0, [sp]
	movs r6, 0x1
	str r6, [sp, 0x4]
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gText_FiveMarks
	lsls r5, 24
	lsrs r5, 24
	mov r0, r9
	str r0, [sp]
	str r6, [sp, 0x4]
	adds r0, r4, 0
	adds r2, r5, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C335C

	thumb_func_start sub_81C33CC
sub_81C33CC: @ 81C33CC
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r5, =gStringVar1
	ldr r1, =gText_UnkCtrlF907F908
	adds r0, r5, 0
	bl StringCopy
	ldr r1, =gText_FiveMarks
	adds r0, r5, 0
	bl StringAppend
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x38
	bl GetStringRightAlignXOffset
	adds r4, r0, 0
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x1
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	str r1, [sp]
	movs r1, 0x1
	str r1, [sp, 0x4]
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C33CC

	thumb_func_start sub_81C3428
sub_81C3428: @ 81C3428
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x70
	adds r0, 0xA5
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C3448
	ldr r4, =gUnknown_085EA40B
	b _081C346C
	.pool
_081C3448:
	ldrh r0, [r1, 0x30]
	cmp r0, 0x5
	bhi _081C3458
	ldr r4, =gUnknown_085EA4A2
	b _081C346C
	.pool
_081C3458:
	cmp r0, 0xA
	bhi _081C3464
	ldr r4, =gUnknown_085EA475
	b _081C346C
	.pool
_081C3464:
	ldr r4, =gUnknown_085EA40B
	cmp r0, 0x28
	bhi _081C346C
	ldr r4, =gUnknown_085EA442
_081C346C:
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3428

	thumb_func_start sub_81C349C
sub_81C349C: @ 81C349C
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r4, r0, 0
	adds r4, 0x70
	adds r0, 0xA5
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081C3500
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFF
	bne _081C34C4
	ldr r4, =gUnknown_085EA678
	b _081C3502
	.pool
_081C34C4:
	bl sub_81C32BC
	lsls r0, 24
	cmp r0, 0
	beq _081C34D8
	bl sub_81C3220
	lsls r0, 24
	cmp r0, 0
	bne _081C34E0
_081C34D8:
	ldr r4, =gUnknown_085EA6AB
	b _081C3502
	.pool
_081C34E0:
	ldrb r0, [r4, 0x9]
	cmp r0, 0xFD
	bne _081C3500
	bl sub_81C32E0
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gUnknown_085EA702
	cmp r0, 0x1
	bne _081C3502
	ldr r4, =gUnknown_085EA6D7
	b _081C3502
	.pool
_081C3500:
	ldr r4, =gUnknown_085EA647
_081C3502:
	ldr r0, =gUnknown_0861CCCC
	movs r1, 0x3
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C349C

	thumb_func_start sub_81C3530
sub_81C3530: @ 81C3530
	push {lr}
	bl sub_81C35E4
	bl sub_81C3690
	bl sub_81C3710
	bl sub_81C37D8
	bl sub_81C3808
	bl sub_81C3890
	bl sub_81C38C0
	pop {r0}
	bx r0
	thumb_func_end sub_81C3530

	thumb_func_start sub_81C3554
sub_81C3554: @ 81C3554
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _081C35D6
	lsls r0, 2
	ldr r1, =_081C3584
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C3584:
	.4byte _081C35A4
	.4byte _081C35AA
	.4byte _081C35B0
	.4byte _081C35B6
	.4byte _081C35BC
	.4byte _081C35C2
	.4byte _081C35C8
	.4byte _081C35CE
_081C35A4:
	bl sub_81C35E4
	b _081C35D6
_081C35AA:
	bl sub_81C3690
	b _081C35D6
_081C35B0:
	bl sub_81C3710
	b _081C35D6
_081C35B6:
	bl sub_81C37D8
	b _081C35D6
_081C35BC:
	bl sub_81C3808
	b _081C35D6
_081C35C2:
	bl sub_81C3890
	b _081C35D6
_081C35C8:
	bl sub_81C38C0
	b _081C35D6
_081C35CE:
	adds r0, r2, 0
	bl DestroyTask
	b _081C35DC
_081C35D6:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081C35DC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C3554

	thumb_func_start sub_81C35E4
sub_81C35E4: @ 81C35E4
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0x9E
	ldrh r0, [r0]
	cmp r0, 0xAF
	bne _081C3628
	bl sub_81B1250
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C3628
	ldr r0, [r4]
	ldr r1, =0x000040be
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	beq _081C3614
	cmp r0, 0x4
	beq _081C3614
	cmp r0, 0x5
	bne _081C3628
_081C3614:
	movs r0, 0xAF
	bl ItemId_GetItem
	adds r5, r0, 0
	b _081C3650
	.pool
_081C3628:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x9E
	ldrh r0, [r1]
	cmp r0, 0
	bne _081C3644
	ldr r5, =gText_None
	b _081C3650
	.pool
_081C3644:
	ldrh r0, [r1]
	ldr r4, =gStringVar1
	adds r1, r4, 0
	bl CopyItemName
	adds r5, r4, 0
_081C3650:
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x48
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	adds r4, 0x6
	ldr r0, =gUnknown_0861CCEC
	movs r1, 0
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C35E4

	thumb_func_start sub_81C3690
sub_81C3690: @ 81C3690
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x76
	ldrb r0, [r1]
	cmp r0, 0
	bne _081C36B0
	ldr r5, =gText_None
	b _081C36C8
	.pool
_081C36B0:
	ldr r0, =gStringVar1
	ldrb r1, [r1]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_085EA3B4
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r5, r4, 0
_081C36C8:
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x46
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	adds r4, 0x6
	ldr r0, =gUnknown_0861CCEC
	movs r1, 0x1
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	adds r1, r5, 0
	adds r2, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3690

	thumb_func_start sub_81C3710
sub_81C3710: @ 81C3710
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	movs r0, 0x8
	bl Alloc
	mov r9, r0
	movs r0, 0x8
	bl Alloc
	mov r8, r0
	movs r0, 0x8
	bl Alloc
	adds r6, r0, 0
	movs r0, 0x8
	bl Alloc
	adds r5, r0, 0
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0x90
	ldrh r1, [r0]
	mov r0, r9
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	adds r0, 0x92
	ldrh r1, [r0]
	mov r0, r8
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	adds r0, 0x94
	ldrh r1, [r0]
	adds r0, r6, 0
	movs r2, 0x1
	movs r3, 0x7
	bl ConvertIntToDecimalStringN
	ldr r0, [r4]
	adds r0, 0x96
	ldrh r1, [r0]
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0x7
	bl ConvertIntToDecimalStringN
	bl sub_81AFBF0
	movs r0, 0
	mov r1, r9
	bl sub_81AFC0C
	movs r0, 0x1
	mov r1, r8
	bl sub_81AFC0C
	movs r0, 0x2
	adds r1, r6, 0
	bl sub_81AFC0C
	movs r0, 0x3
	adds r1, r5, 0
	bl sub_81AFC0C
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_0861CE82
	bl sub_81AFC28
	mov r0, r9
	bl Free
	mov r0, r8
	bl Free
	adds r0, r6, 0
	bl Free
	adds r0, r5, 0
	bl Free
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3710

	thumb_func_start sub_81C37D8
sub_81C37D8: @ 81C37D8
	push {lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CCEC
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gStringVar4
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x4
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C37D8

	thumb_func_start sub_81C3808
sub_81C3808: @ 81C3808
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gStringVar1
	mov r8, r0
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	adds r0, 0x98
	ldrh r1, [r0]
	mov r0, r8
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r6, =gStringVar2
	ldr r0, [r4]
	adds r0, 0x9A
	ldrh r1, [r0]
	adds r0, r6, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r5, =gStringVar3
	ldr r0, [r4]
	adds r0, 0x9C
	ldrh r1, [r0]
	adds r0, r5, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	bl sub_81AFBF0
	movs r0, 0
	mov r1, r8
	bl sub_81AFC0C
	movs r0, 0x1
	adds r1, r6, 0
	bl sub_81AFC0C
	movs r0, 0x2
	adds r1, r5, 0
	bl sub_81AFC0C
	ldr r0, =gStringVar4
	ldr r1, =gUnknown_0861CE8E
	bl sub_81AFC28
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3808

	thumb_func_start sub_81C3890
sub_81C3890: @ 81C3890
	push {lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CCEC
	movs r1, 0x3
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gStringVar4
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x2
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3890

	thumb_func_start sub_81C38C0
sub_81C38C0: @ 81C38C0
	push {r4-r6,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0x70
	ldr r0, =gUnknown_0861CCEC
	movs r1, 0x4
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gStringVar1
	ldr r1, [r5, 0x10]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x7
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2A
	bl GetStringRightAlignXOffset
	adds r0, 0x2
	lsls r2, r0, 24
	lsrs r2, 24
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_81C25A4
	ldrb r0, [r5, 0x5]
	cmp r0, 0x63
	bhi _081C3948
	ldr r4, =gExperienceTables
	adds r1, r0, 0
	adds r1, 0x1
	lsls r1, 2
	ldr r3, =gBaseStats
	ldrh r2, [r5]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r3
	ldrb r2, [r0, 0x13]
	movs r0, 0xCA
	lsls r0, 1
	muls r0, r2
	adds r1, r0
	adds r1, r4
	ldr r1, [r1]
	ldr r0, [r5, 0x10]
	subs r1, r0
	b _081C394A
	.pool
_081C3948:
	movs r1, 0
_081C394A:
	ldr r4, =gStringVar1
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x6
	bl ConvertIntToDecimalStringN
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2A
	bl GetStringRightAlignXOffset
	adds r0, 0x2
	lsls r2, r0, 24
	lsrs r2, 24
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r6, 0
	adds r1, r4, 0
	movs r3, 0x11
	bl sub_81C25A4
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C38C0

	thumb_func_start sub_81C3984
sub_81C3984: @ 81C3984
	push {r4,lr}
	movs r0, 0
	bl sub_81C3B08
	movs r0, 0x1
	bl sub_81C3B08
	movs r0, 0x2
	bl sub_81C3B08
	movs r0, 0x3
	bl sub_81C3B08
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r1, =0x000040bc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C39EA
	bl sub_81C3F44
	ldr r1, [r4]
	ldr r0, =0x000040c6
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, 0x4
	bne _081C39DC
	ldr r0, =0x000040c4
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _081C39EA
	bl sub_81C3E9C
	b _081C39EA
	.pool
_081C39DC:
	ldrb r0, [r2]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r0, [r1]
	bl sub_81C3E9C
_081C39EA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C3984

	thumb_func_start sub_81C39F0
sub_81C39F0: @ 81C39F0
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	bhi _081C3AFC
	lsls r0, 2
	ldr r1, =_081C3A20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C3A20:
	.4byte _081C3A40
	.4byte _081C3A48
	.4byte _081C3A50
	.4byte _081C3A58
	.4byte _081C3A60
	.4byte _081C3A7C
	.4byte _081C3ABE
	.4byte _081C3AF4
_081C3A40:
	movs r0, 0
	bl sub_81C3B08
	b _081C3AFC
_081C3A48:
	movs r0, 0x1
	bl sub_81C3B08
	b _081C3AFC
_081C3A50:
	movs r0, 0x2
	bl sub_81C3B08
	b _081C3AFC
_081C3A58:
	movs r0, 0x3
	bl sub_81C3B08
	b _081C3AFC
_081C3A60:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040bc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3AFC
	bl sub_81C3F44
	b _081C3AFC
	.pool
_081C3A7C:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3AFC
	ldr r0, =0x000040c6
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, 0x4
	bne _081C3AB0
	ldr r2, =0x000040c4
	adds r0, r1, r2
	ldrh r0, [r0]
	strh r0, [r4, 0x2]
	b _081C3AFC
	.pool
_081C3AB0:
	ldrb r0, [r2]
	lsls r0, 1
	adds r1, 0x84
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r4, 0x2]
	b _081C3AFC
_081C3ABE:
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040bc
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3AFC
	adds r2, 0x8
	adds r0, r1, r2
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C3AFC
	ldrh r0, [r4, 0x2]
	bl sub_81C3E9C
	b _081C3AFC
	.pool
_081C3AF4:
	adds r0, r2, 0
	bl DestroyTask
	b _081C3B02
_081C3AFC:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081C3B02:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C39F0

	thumb_func_start sub_81C3B08
sub_81C3B08: @ 81C3B08
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	mov r10, r0
	ldr r4, =gUnknown_0861CD14
	adds r0, r4, 0
	movs r1, 0
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	lsls r1, r7, 1
	mov r0, r10
	adds r0, 0x84
	adds r0, r1
	ldrh r5, [r0]
	cmp r5, 0
	beq _081C3C00
	mov r0, r10
	adds r0, 0xA4
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r2, r7, 0
	bl CalculatePPWithBonus
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0xD
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	lsls r0, r7, 4
	mov r9, r0
	mov r3, r9
	adds r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	mov r0, r8
	movs r2, 0
	bl sub_81C25A4
	ldr r0, =gStringVar1
	mov r8, r0
	mov r5, r10
	adds r5, 0x8C
	adds r5, r7
	ldrb r1, [r5]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar2
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	bl sub_81AFBF0
	movs r0, 0
	mov r1, r8
	bl sub_81AFC0C
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_81AFC0C
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0861CE97
	adds r0, r4, 0
	bl sub_81AFC28
	adds r7, r4, 0
	ldrb r0, [r5]
	adds r1, r6, 0
	bl sub_814FC20
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	adds r5, 0x9
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x2C
	bl GetStringRightAlignXOffset
	mov r4, r9
	b _081C3C26
	.pool
_081C3C00:
	ldr r1, =gText_OneDash
	lsls r4, r7, 4
	adds r3, r4, 0x1
	lsls r3, 24
	lsrs r3, 24
	str r5, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	mov r0, r8
	movs r2, 0
	bl sub_81C25A4
	ldr r7, =gText_TwoDashes
	movs r5, 0xC
	movs r0, 0x1
	adds r1, r7, 0
	movs r2, 0x2C
	bl GetStringCenterAlignXOffset
_081C3C26:
	lsls r2, r0, 24
	lsrs r2, 24
	adds r3, r4, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0
	str r0, [sp]
	lsls r0, r5, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	ldr r0, [sp, 0x8]
	adds r1, r7, 0
	bl sub_81C25A4
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3B08

	thumb_func_start sub_81C3C5C
sub_81C3C5C: @ 81C3C5C
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 16
	lsrs r5, r0, 16
	cmp r5, 0
	beq _081C3CFC
	movs r0, 0x13
	str r0, [sp]
	movs r0, 0x20
	str r0, [sp, 0x4]
	movs r0, 0xE
	movs r1, 0
	movs r2, 0x35
	movs r3, 0
	bl FillWindowPixelRect
	ldr r2, =gBattleMoves
	lsls r1, r5, 1
	adds r0, r1, r5
	lsls r0, 2
	adds r2, r0, r2
	ldrb r0, [r2, 0x1]
	adds r6, r1, 0
	cmp r0, 0x1
	bhi _081C3C9C
	ldr r1, =gText_ThreeDashes
	b _081C3CAC
	.pool
_081C3C9C:
	ldr r4, =gStringVar1
	ldrb r1, [r2, 0x1]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r1, r4, 0
_081C3CAC:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xE
	movs r2, 0x35
	movs r3, 0x1
	bl sub_81C25A4
	ldr r1, =gBattleMoves
	adds r0, r6, r5
	lsls r0, 2
	adds r1, r0, r1
	ldrb r0, [r1, 0x3]
	cmp r0, 0
	bne _081C3CDC
	ldr r1, =gText_ThreeDashes
	b _081C3CEC
	.pool
_081C3CDC:
	ldr r4, =gStringVar1
	ldrb r1, [r1, 0x3]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r1, r4, 0
_081C3CEC:
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	movs r0, 0xE
	movs r2, 0x35
	movs r3, 0x11
	bl sub_81C25A4
_081C3CFC:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3C5C

	thumb_func_start sub_81C3D08
sub_81C3D08: @ 81C3D08
	push {r4,lr}
	movs r0, 0
	bl sub_81C3B08
	movs r0, 0x1
	bl sub_81C3B08
	movs r0, 0x2
	bl sub_81C3B08
	movs r0, 0x3
	bl sub_81C3B08
	ldr r4, =gUnknown_0203CF1C
	ldr r0, [r4]
	ldr r1, =0x000040bc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3D40
	bl sub_81C3F44
	ldr r0, [r4]
	ldr r1, =0x000040c6
	adds r0, r1
	ldrb r0, [r0]
	bl sub_81C3E2C
_081C3D40:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3D08

	thumb_func_start sub_81C3D54
sub_81C3D54: @ 81C3D54
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrh r0, [r4]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	bhi _081C3E20
	lsls r0, 2
	ldr r1, =_081C3D84
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C3D84:
	.4byte _081C3DA0
	.4byte _081C3DA8
	.4byte _081C3DB0
	.4byte _081C3DB8
	.4byte _081C3DC0
	.4byte _081C3DDC
	.4byte _081C3E18
_081C3DA0:
	movs r0, 0
	bl sub_81C3B08
	b _081C3E20
_081C3DA8:
	movs r0, 0x1
	bl sub_81C3B08
	b _081C3E20
_081C3DB0:
	movs r0, 0x2
	bl sub_81C3B08
	b _081C3E20
_081C3DB8:
	movs r0, 0x3
	bl sub_81C3B08
	b _081C3E20
_081C3DC0:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040bc
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3E20
	bl sub_81C3F44
	b _081C3E20
	.pool
_081C3DDC:
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	ldr r1, =0x000040bc
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x3
	bne _081C3E20
	adds r1, 0x8
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0x80
	lsls r1, 11
	cmp r0, r1
	beq _081C3E20
	ldr r1, =0x000040c6
	adds r0, r2, r1
	ldrb r0, [r0]
	bl sub_81C3E2C
	b _081C3E20
	.pool
_081C3E18:
	adds r0, r2, 0
	bl DestroyTask
	b _081C3E26
_081C3E20:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
_081C3E26:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C3D54

	thumb_func_start sub_81C3E2C
sub_81C3E2C: @ 81C3E2C
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x4
	bne _081C3E48
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c4
	b _081C3E50
	.pool
_081C3E48:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	lsls r1, 1
	adds r0, 0x84
_081C3E50:
	adds r0, r1
	ldrh r4, [r0]
	cmp r4, 0
	beq _081C3E82
	ldr r0, =gUnknown_0861CD14
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =gContestEffectDescriptionPointers
	ldr r2, =gContestMoves
	lsls r1, r4, 3
	adds r1, r2
	ldrb r1, [r1]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	movs r2, 0
	str r2, [sp]
	str r2, [sp, 0x4]
	movs r2, 0x6
	movs r3, 0x1
	bl sub_81C25A4
_081C3E82:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3E2C

	thumb_func_start sub_81C3E9C
sub_81C3E9C: @ 81C3E9C
	push {r4-r6,lr}
	sub sp, 0x8
	lsls r0, 16
	lsrs r4, r0, 16
	adds r6, r4, 0
	ldr r0, =gUnknown_0861CD14
	movs r1, 0x2
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	cmp r4, 0
	beq _081C3F30
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081C3F00
	adds r0, r4, 0
	bl sub_81C3C5C
	ldr r1, =gMoveDescriptionPointers
	subs r0, r4, 0x1
	lsls r0, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r2, 0x6
	movs r3, 0x1
	bl sub_81C25A4
	b _081C3F20
	.pool
_081C3F00:
	ldr r2, =gContestEffectDescriptionPointers
	ldr r1, =gContestMoves
	lsls r0, r6, 3
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0]
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r2, 0x6
	movs r3, 0x1
	bl sub_81C25A4
_081C3F20:
	adds r0, r5, 0
	bl PutWindowTilemap
	b _081C3F36
	.pool
_081C3F30:
	adds r0, r5, 0
	bl ClearWindowTilemap
_081C3F36:
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C3E9C

	thumb_func_start sub_81C3F44
sub_81C3F44: @ 81C3F44
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	ldr r4, =gUnknown_0861CD14
	adds r0, r4, 0
	movs r1, 0
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r6, r0, 24
	adds r7, r6, 0
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C2D2C
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r2, =0x000040c4
	adds r0, r1, r2
	ldrh r2, [r0]
	cmp r2, 0
	bne _081C3F9C
	ldr r1, =gText_Cancel
	str r2, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x41
	bl sub_81C25A4
	b _081C4044
	.pool
_081C3F9C:
	ldrh r5, [r0]
	ldr r2, =0x000040c0
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081C3FD0
	movs r0, 0xD
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x6
	str r0, [sp, 0x4]
	adds r0, r6, 0
	movs r2, 0
	movs r3, 0x41
	bl sub_81C25A4
	b _081C3FEC
	.pool
_081C3FD0:
	movs r0, 0xD
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gMoveNames
	adds r1, r0
	movs r0, 0
	str r0, [sp]
	movs r0, 0x5
	str r0, [sp, 0x4]
	adds r0, r7, 0
	movs r2, 0
	movs r3, 0x41
	bl sub_81C25A4
_081C3FEC:
	ldr r4, =gStringVar1
	ldr r1, =gBattleMoves
	lsls r0, r5, 1
	adds r0, r5
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x4]
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	bl sub_81AFBF0
	movs r0, 0
	adds r1, r4, 0
	bl sub_81AFC0C
	movs r0, 0x1
	adds r1, r4, 0
	bl sub_81AFC0C
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_0861CE97
	adds r0, r4, 0
	bl sub_81AFC28
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x2C
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC
	str r0, [sp, 0x4]
	mov r0, r8
	adds r1, r4, 0
	movs r3, 0x41
	bl sub_81C25A4
_081C4044:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C3F44

	thumb_func_start sub_81C4064
sub_81C4064: @ 81C4064
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CD14
	movs r1, 0
	bl sub_81C2D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x48
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x42
	bl FillWindowPixelRect
	adds r0, r4, 0
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4064

	thumb_func_start sub_81C40A0
sub_81C40A0: @ 81C40A0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	mov r10, r1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r0, r10
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r5, =gUnknown_0861CD14
	adds r0, r5, 0
	movs r1, 0
	bl sub_81C2D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81C2D2C
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	mov r0, r9
	lsls r6, r0, 4
	movs r0, 0x48
	mov r8, r0
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	adds r3, r6, 0
	bl FillWindowPixelRect
	mov r0, r10
	lsls r7, r0, 4
	mov r0, r8
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	adds r3, r7, 0
	bl FillWindowPixelRect
	movs r4, 0x30
	str r4, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	adds r3, r6, 0
	bl FillWindowPixelRect
	str r4, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r5, 0
	movs r1, 0
	movs r2, 0
	adds r3, r7, 0
	bl FillWindowPixelRect
	mov r0, r9
	bl sub_81C3B08
	mov r0, r10
	bl sub_81C3B08
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C40A0

	thumb_func_start sub_81C4154
sub_81C4154: @ 81C4154
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0861CD14
	movs r1, 0x2
	bl sub_81C2D2C
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	ldr r1, =gUnknown_085EA4CB
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	adds r0, r4, 0
	movs r2, 0x6
	movs r3, 0x1
	bl sub_81C25A4
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4154

	thumb_func_start sub_81C4190
sub_81C4190: @ 81C4190
	push {r4,r5,lr}
	movs r2, 0
	ldr r5, =gUnknown_0203CF1C
	ldr r4, =0x000040d3
	movs r3, 0xFF
_081C419A:
	ldr r0, [r5]
	adds r0, r4
	adds r0, r2
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1B
	bls _081C419A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4190

	thumb_func_start sub_81C41C0
sub_81C41C0: @ 81C41C0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	ldr r1, =0x000040d3
	adds r0, r1
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081C41F2
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	ldr r0, [r5]
	ldr r1, =0x000040d3
	adds r0, r1
	adds r0, r4
	movs r1, 0xFF
	strb r1, [r0]
_081C41F2:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C41C0

	thumb_func_start sub_81C4204
sub_81C4204: @ 81C4204
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gSprites
	ldr r2, =gUnknown_0203CF1C
	ldr r2, [r2]
	ldr r4, =0x000040d3
	adds r2, r4
	adds r2, r0
	ldrb r0, [r2]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	adds r2, 0x3E
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r3, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4204

	thumb_func_start sub_81C424C
sub_81C424C: @ 81C424C
	push {r4,lr}
	movs r4, 0x3
_081C4250:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d3
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0xFF
	beq _081C4268
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C4204
_081C4268:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x1B
	bls _081C4250
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C424C

	thumb_func_start sub_81C4280
sub_81C4280: @ 81C4280
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _081C42B0
	cmp r0, 0x2
	bgt _081C42A4
	cmp r0, 0
	beq _081C42AA
	b _081C42C2
	.pool
_081C42A4:
	cmp r0, 0x3
	beq _081C42BA
	b _081C42C2
_081C42AA:
	bl sub_81C43A0
	b _081C42C2
_081C42B0:
	bl sub_81C4420
	bl sub_81C44F0
	b _081C42C2
_081C42BA:
	bl sub_81C4484
	bl sub_81C44F0
_081C42C2:
	pop {r0}
	bx r0
	thumb_func_end sub_81C4280

	thumb_func_start sub_81C42C8
sub_81C42C8: @ 81C42C8
	push {r4,r5,lr}
	movs r4, 0x3
	ldr r5, =gUnknown_0203CF1C
_081C42CE:
	ldr r0, [r5]
	ldr r1, =0x000040d3
	adds r0, r1
	adds r0, r4
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081C42F2
	ldr r0, =gUnknown_0861CFC4
	movs r1, 0
	movs r2, 0
	movs r3, 0x2
	bl CreateSprite
	ldr r1, [r5]
	ldr r2, =0x000040d3
	adds r1, r2
	adds r1, r4
	strb r0, [r1]
_081C42F2:
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81C4204
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _081C42CE
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C42C8

	thumb_func_start sub_81C4318
sub_81C4318: @ 81C4318
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d3
	adds r0, r1
	adds r0, r3
	ldrb r0, [r0]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	adds r0, r4, 0
	adds r1, r5, 0
	str r3, [sp]
	bl StartSpriteAnim
	ldr r0, =gUnknown_0861CFDC
	adds r5, r0
	ldrb r1, [r5]
	lsls r1, 4
	ldrb r2, [r4, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
	adds r6, 0x10
	strh r6, [r4, 0x20]
	movs r0, 0x8
	add r8, r0
	mov r1, r8
	strh r1, [r4, 0x22]
	ldr r3, [sp]
	adds r0, r3, 0
	movs r1, 0
	bl sub_81C4204
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4318

	thumb_func_start sub_81C43A0
sub_81C43A0: @ 81C43A0
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0x70
	ldrb r0, [r5, 0x4]
	cmp r0, 0
	beq _081C43CC
	movs r0, 0x9
	movs r1, 0x78
	movs r2, 0x30
	movs r3, 0x3
	bl sub_81C4318
	movs r0, 0x4
	movs r1, 0x1
	bl sub_81C4204
	b _081C4418
	.pool
_081C43CC:
	ldr r4, =gBaseStats
	ldrh r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r0, [r0, 0x6]
	movs r1, 0x78
	movs r2, 0x30
	movs r3, 0x3
	bl sub_81C4318
	ldrh r1, [r5]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r1, r0, r4
	ldrb r0, [r1, 0x6]
	ldrb r2, [r1, 0x7]
	cmp r0, r2
	beq _081C4410
	ldrb r0, [r1, 0x7]
	movs r1, 0xA0
	movs r2, 0x30
	movs r3, 0x4
	bl sub_81C4318
	movs r0, 0x4
	movs r1, 0
	bl sub_81C4204
	b _081C4418
	.pool
_081C4410:
	movs r0, 0x4
	movs r1, 0x1
	bl sub_81C4204
_081C4418:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C43A0

	thumb_func_start sub_81C4420
sub_81C4420: @ 81C4420
	push {r4-r6,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0x70
	movs r4, 0
	ldr r6, =gBattleMoves
_081C442E:
	lsls r0, r4, 1
	adds r1, r5, 0
	adds r1, 0x14
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _081C4468
	adds r1, r0, 0
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x2]
	lsls r2, r4, 28
	movs r1, 0x80
	lsls r1, 22
	adds r2, r1
	lsrs r2, 24
	adds r3, r4, 0x3
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x55
	bl sub_81C4318
	b _081C4474
	.pool
_081C4468:
	adds r0, r4, 0x3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_81C4204
_081C4474:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081C442E
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4420

	thumb_func_start sub_81C4484
sub_81C4484: @ 81C4484
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0x70
	movs r4, 0
_081C4490:
	lsls r0, r4, 1
	adds r1, r5, 0
	adds r1, 0x14
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, 0
	beq _081C44D4
	ldr r1, =gContestMoves
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	lsrs r0, 5
	movs r1, 0x90
	lsls r1, 21
	adds r0, r1
	lsrs r0, 24
	lsls r2, r4, 28
	movs r1, 0x80
	lsls r1, 22
	adds r2, r1
	lsrs r2, 24
	adds r3, r4, 0x3
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0x55
	bl sub_81C4318
	b _081C44E0
	.pool
_081C44D4:
	adds r0, r4, 0x3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	bl sub_81C4204
_081C44E0:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081C4490
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4484

	thumb_func_start sub_81C44F0
sub_81C44F0: @ 81C44F0
	push {lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	ldr r0, =0x000040c4
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, 0
	bne _081C4514
	movs r0, 0x7
	movs r1, 0x1
	bl sub_81C4204
	b _081C4560
	.pool
_081C4514:
	ldr r2, =0x000040c0
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _081C4540
	ldr r2, =gBattleMoves
	ldrh r1, [r3]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x2]
	movs r1, 0x55
	movs r2, 0x60
	movs r3, 0x7
	bl sub_81C4318
	b _081C4560
	.pool
_081C4540:
	ldr r1, =gContestMoves
	ldrh r0, [r3]
	lsls r0, 3
	adds r0, r1
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	lsrs r0, 5
	movs r1, 0x90
	lsls r1, 21
	adds r0, r1
	lsrs r0, 24
	movs r1, 0x55
	movs r2, 0x60
	movs r3, 0x7
	bl sub_81C4318
_081C4560:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C44F0

	thumb_func_start sub_81C4568
sub_81C4568: @ 81C4568
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_0203CF1C
	ldr r2, [r2]
	adds r0, 0x3
	ldr r3, =0x000040d3
	adds r2, r3
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r5, =gSprites
	adds r4, r5
	adds r1, 0x3
	adds r2, r1
	ldrb r0, [r2]
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r3, r5
	adds r5, r4, 0
	adds r5, 0x2A
	ldrb r1, [r5]
	adds r2, r3, 0
	adds r2, 0x2A
	ldrb r0, [r2]
	strb r0, [r5]
	strb r1, [r2]
	ldrb r6, [r4, 0x5]
	lsrs r5, r6, 4
	ldrb r2, [r3, 0x5]
	lsrs r2, 4
	lsls r2, 4
	movs r1, 0xF
	adds r0, r1, 0
	ands r0, r6
	orrs r0, r2
	strb r0, [r4, 0x5]
	lsls r5, 4
	ldrb r0, [r3, 0x5]
	ands r1, r0
	orrs r1, r5
	strb r1, [r3, 0x5]
	adds r4, 0x3F
	ldrb r0, [r4]
	movs r2, 0x4
	orrs r0, r2
	movs r1, 0x11
	negs r1, r1
	ands r0, r1
	strb r0, [r4]
	adds r3, 0x3F
	ldrb r0, [r3]
	orrs r0, r2
	ands r0, r1
	strb r0, [r3]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4568

	thumb_func_start sub_81C45F4
sub_81C45F4: @ 81C45F4
	push {r4-r6,lr}
	adds r3, r0, 0
	adds r6, r1, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r2, [r0]
	adds r5, r2, 0
	adds r5, 0x70
	movs r1, 0
	ldrsh r0, [r6, r1]
	cmp r0, 0
	beq _081C4620
	cmp r0, 0x1
	bne _081C4610
	b _081C4750
_081C4610:
	adds r0, r3, 0
	bl sub_81C47B4
	lsls r0, 24
	lsrs r0, 24
	b _081C4770
	.pool
_081C4620:
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C4680
	ldr r1, =0x000040be
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, 0x3
	bl sub_80688F8
	lsls r0, 24
	cmp r0, 0
	beq _081C4668
	ldrh r2, [r5, 0x2]
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gBattleSpritesGfx
	ldr r1, [r1]
	ldr r1, [r1, 0x8]
	b _081C46D6
	.pool
_081C4668:
	ldrh r2, [r5, 0x2]
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, =gBattleSpritesGfx
	ldr r1, [r1]
	b _081C46B0
	.pool
_081C4680:
	ldr r0, =gBattleSpritesGfx
	ldr r3, [r0]
	adds r4, r0, 0
	cmp r3, 0
	beq _081C46E4
	ldr r1, [r2]
	ldr r0, =gPlayerParty
	cmp r1, r0
	beq _081C46A6
	ldr r1, =0x000040bc
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _081C46A6
	adds r1, 0x33
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C46CC
_081C46A6:
	ldrh r2, [r5, 0x2]
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, [r4]
_081C46B0:
	ldr r1, [r1, 0x8]
	ldr r3, [r5, 0xC]
	bl HandleLoadSpecialPokePic_2
	b _081C4768
	.pool
_081C46CC:
	ldrh r2, [r5, 0x2]
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	ldr r1, [r3, 0x8]
_081C46D6:
	ldr r3, [r5, 0xC]
	bl HandleLoadSpecialPokePic_DontHandleDeoxys
	b _081C4768
	.pool
_081C46E4:
	ldr r1, [r2]
	ldr r0, =gPlayerParty
	cmp r1, r0
	beq _081C4700
	ldr r1, =0x000040bc
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	beq _081C4700
	adds r1, 0x33
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C472C
_081C4700:
	ldrh r4, [r5, 0x2]
	lsls r4, 3
	ldr r0, =gMonFrontPicTable
	adds r4, r0
	movs r0, 0
	movs r1, 0x1
	bl sub_806F4F8
	adds r1, r0, 0
	ldrh r2, [r5, 0x2]
	ldr r3, [r5, 0xC]
	adds r0, r4, 0
	bl HandleLoadSpecialPokePic_2
	b _081C4768
	.pool
_081C472C:
	ldrh r4, [r5, 0x2]
	lsls r4, 3
	ldr r0, =gMonFrontPicTable
	adds r4, r0
	movs r0, 0
	movs r1, 0x1
	bl sub_806F4F8
	adds r1, r0, 0
	ldrh r2, [r5, 0x2]
	ldr r3, [r5, 0xC]
	adds r0, r4, 0
	bl HandleLoadSpecialPokePic_DontHandleDeoxys
	b _081C4768
	.pool
_081C4750:
	ldrh r0, [r5, 0x2]
	ldr r1, [r5, 0x48]
	ldr r2, [r5, 0xC]
	bl sub_806E7CC
	adds r4, r0, 0
	bl LoadCompressedObjectPalette
	ldrh r0, [r4, 0x4]
	movs r1, 0x1
	bl sub_806A068
_081C4768:
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
	movs r0, 0xFF
_081C4770:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C45F4

	thumb_func_start sub_81C4778
sub_81C4778: @ 81C4778
	push {r4,lr}
	ldr r0, =gUnknown_0203CF1C
	ldr r1, [r0]
	adds r4, r1, 0
	adds r4, 0x70
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	bne _081C47AE
	adds r0, r1, 0
	adds r0, 0xC
	bl sub_805F110
	cmp r0, 0x1
	bne _081C47A4
	ldrh r0, [r4, 0x2]
	movs r1, 0
	movs r2, 0
	bl PlayCry3
	b _081C47AE
	.pool
_081C47A4:
	ldrh r0, [r4, 0x2]
	movs r1, 0
	movs r2, 0xB
	bl PlayCry3
_081C47AE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4778

	thumb_func_start sub_81C47B4
sub_81C47B4: @ 81C47B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gUnknown_0203CF1C
	ldr r6, [r0]
	adds r6, 0x70
	ldr r0, =gUnknown_0202499C
	movs r1, 0x28
	movs r2, 0x40
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r4, r0, 4
	add r4, r8
	lsls r4, 2
	ldr r5, =gSprites
	adds r7, r4, r5
	adds r0, r7, 0
	bl FreeSpriteOamMatrix
	ldrh r0, [r6, 0x2]
	movs r1, 0
	strh r0, [r7, 0x2E]
	strh r1, [r7, 0x32]
	adds r5, 0x1C
	adds r4, r5
	ldr r0, =sub_81C4844
	str r0, [r4]
	ldrb r1, [r7, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	strb r0, [r7, 0x5]
	ldrh r0, [r6, 0x2]
	bl IsPokeSpriteNotFlipped
	lsls r0, 24
	cmp r0, 0
	bne _081C4828
	adds r0, r7, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
	b _081C4836
	.pool
_081C4828:
	adds r2, r7, 0
	adds r2, 0x3F
	ldrb r1, [r2]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
_081C4836:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_81C47B4

	thumb_func_start sub_81C4844
sub_81C4844: @ 81C4844
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	adds r5, r0, 0
	adds r5, 0x70
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081C487E
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _081C487E
	ldrh r0, [r4, 0x2E]
	bl IsPokeSpriteNotFlipped
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x30]
	bl sub_81C4778
	ldrh r1, [r4, 0x2E]
	ldrb r2, [r5, 0x4]
	adds r0, r4, 0
	bl PokemonSummaryDoMonAnimation
_081C487E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4844

	thumb_func_start sub_81C488C
sub_81C488C: @ 81C488C
	ldr r1, =gUnknown_0203CF24
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81C488C

	thumb_func_start sub_81C4898
sub_81C4898: @ 81C4898
	push {r4,lr}
	ldr r4, =gUnknown_0203CF24
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _081C48AA
	bl DestroyTask
	movs r0, 0xFF
	strb r0, [r4]
_081C48AA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4898

	thumb_func_start sub_81C48B4
sub_81C48B4: @ 81C48B4
	push {lr}
	ldr r2, =gSprites
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040d3
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, [r0]
	ldr r0, =SpriteCallbackDummy
	cmp r1, r0
	beq _081C48E8
	movs r0, 0x1
	b _081C48EA
	.pool
_081C48E8:
	movs r0, 0
_081C48EA:
	pop {r1}
	bx r1
	thumb_func_end sub_81C48B4

	thumb_func_start sub_81C48F0
sub_81C48F0: @ 81C48F0
	push {r4-r6,lr}
	ldr r6, =gSprites
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	ldr r4, =0x000040d3
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x2C
	ldrb r1, [r0]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	bl sub_806EE98
	ldr r0, [r5]
	adds r0, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r0, [r0, 0x5]
	lsrs r0, 4
	lsls r3, r0, 4
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	orrs r3, r0
	movs r2, 0
	ldr r5, =gPlttBufferUnfaded
	ldr r4, =gPlttBufferFaded
_081C494C:
	adds r0, r2, r3
	lsls r0, 16
	lsrs r0, 15
	adds r1, r0, r5
	adds r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0xF
	bls _081C494C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C48F0

	thumb_func_start sub_81C4984
sub_81C4984: @ 81C4984
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r1, =0x00007533
	ldr r2, =gUnknown_0861D120
	adds r0, r1, 0
	bl sub_811FF94
	adds r4, r0, 0
	ldr r6, =gUnknown_0203CF1C
	ldr r0, [r6]
	str r4, [r0, 0x8]
	cmp r4, 0
	beq _081C49CE
	adds r0, r5, 0
	movs r1, 0x8
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	ldr r1, [r6]
	ldr r2, [r1, 0x8]
	movs r0, 0x3C
	strh r0, [r2, 0x20]
	ldr r2, [r1, 0x8]
	movs r0, 0x1A
	strh r0, [r2, 0x22]
	ldr r2, [r1, 0x8]
	ldrb r1, [r2, 0x5]
	subs r0, 0x27
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
_081C49CE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4984

	thumb_func_start sub_81C49E0
sub_81C49E0: @ 81C49E0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl DestroySprite
	ldr r0, =0x00007533
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl sub_81C4984
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C49E0

	thumb_func_start sub_81C4A08
sub_81C4A08: @ 81C4A08
	push {r4,lr}
	movs r1, 0x26
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	bl ball_number_to_ball_processing_index
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_8076A78
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 3
	ldr r1, =gUnknown_0832C588
	adds r0, r1
	movs r1, 0x10
	movs r2, 0x88
	movs r3, 0
	bl CreateSprite
	ldr r2, =gUnknown_0203CF1C
	ldr r1, [r2]
	ldr r3, =0x000040d4
	adds r1, r3
	strb r0, [r1]
	ldr r4, =gSprites
	ldr r2, [r2]
	adds r2, r3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r4, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =SpriteCallbackDummy
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x5]
	movs r2, 0xC
	orrs r1, r2
	strb r1, [r0, 0x5]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4A08

	thumb_func_start sub_81C4A88
sub_81C4A88: @ 81C4A88
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203CF1C
	ldr r0, [r5]
	ldr r1, =0x000040d5
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081C4AA6
	ldr r0, =gUnknown_0861D108
	movs r1, 0x40
	movs r2, 0x98
	movs r3, 0
	bl CreateSprite
	strb r0, [r4]
_081C4AA6:
	ldr r0, [r5]
	adds r0, 0xC
	bl sub_81B205C
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _081C4AE8
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	subs r1, r2, 0x1
	lsls r1, 24
	lsrs r1, 24
	bl StartSpriteAnim
	movs r0, 0x2
	movs r1, 0
	bl sub_81C4204
	b _081C4AF0
	.pool
_081C4AE8:
	movs r0, 0x2
	movs r1, 0x1
	bl sub_81C4204
_081C4AF0:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4A88

	thumb_func_start sub_81C4AF8
sub_81C4AF8: @ 81C4AF8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldr r0, =gUnknown_0203CF1C
	ldr r1, =0x000040d3
	add r1, r8
	ldr r0, [r0]
	adds r7, r0, r1
	ldr r1, =0x000040c0
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _081C4BD2
	movs r0, 0
	mov r9, r0
	mov r1, r8
	cmp r1, 0x8
	bne _081C4B2A
	movs r0, 0x1
	mov r9, r0
_081C4B2A:
	movs r5, 0
	ldr r6, =gSprites
	mov r10, r5
_081C4B30:
	lsls r1, r5, 20
	movs r0, 0xB2
	lsls r0, 15
	adds r1, r0
	asrs r1, 16
	ldr r0, =gUnknown_0861D084
	movs r2, 0x28
	mov r3, r9
	bl CreateSprite
	adds r1, r7, r5
	strb r0, [r1]
	adds r4, r1, 0
	cmp r5, 0
	bne _081C4B74
	ldrb r1, [r7]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x4
	bl StartSpriteAnim
	b _081C4B9A
	.pool
_081C4B74:
	cmp r5, 0x9
	bne _081C4B8A
	ldrb r1, [r7, 0x9]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x5
	bl StartSpriteAnim
	b _081C4B9A
_081C4B8A:
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	movs r1, 0x6
	bl StartSpriteAnim
_081C4B9A:
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r6, 0
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_81C4BE4
	str r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r1, r8
	strh r1, [r0, 0x2E]
	ldrb r1, [r4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r1, r10
	strh r1, [r0, 0x30]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _081C4B30
_081C4BD2:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4AF8

	thumb_func_start sub_81C4BE4
sub_81C4BE4: @ 81C4BE4
	push {lr}
	adds r3, r0, 0
	adds r0, 0x2A
	ldrb r0, [r0]
	subs r0, 0x4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _081C4C1C
	ldrh r0, [r3, 0x30]
	adds r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	strh r0, [r3, 0x30]
	cmp r0, 0x18
	ble _081C4C10
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	b _081C4C2A
_081C4C10:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	b _081C4C28
_081C4C1C:
	movs r0, 0
	strh r0, [r3, 0x30]
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	subs r0, 0x5
_081C4C28:
	ands r0, r1
_081C4C2A:
	strb r0, [r2]
	movs r1, 0x2E
	ldrsh r0, [r3, r1]
	cmp r0, 0x8
	bne _081C4C44
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c6
	b _081C4C4A
	.pool
_081C4C44:
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040c7
_081C4C4A:
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 4
	strh r0, [r3, 0x26]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4BE4

	thumb_func_start sub_81C4C60
sub_81C4C60: @ 81C4C60
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r4, 0
_081C4C68:
	adds r0, r5, r4
	lsls r0, 24
	lsrs r0, 24
	bl sub_81C41C0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _081C4C68
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4C60

	thumb_func_start sub_81C4C84
sub_81C4C84: @ 81C4C84
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_0203CF1C
	ldr r0, [r0]
	ldr r1, =0x000040db
	adds r5, r0, r1
	lsls r0, r6, 1
	adds r0, r6
	lsls r0, 24
	movs r4, 0
	ldr r7, =gSprites
	movs r2, 0x80
	lsls r2, 19
	adds r2, r0
	mov r9, r2
	lsrs r6, r0, 24
	movs r1, 0xA0
	lsls r1, 19
	adds r1, r0
	mov r8, r1
_081C4CB4:
	cmp r4, 0
	bne _081C4CD4
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	mov r2, r9
	b _081C4CE4
	.pool
_081C4CD4:
	cmp r4, 0x9
	bne _081C4CEC
	ldrb r1, [r5, 0x9]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	mov r2, r8
_081C4CE4:
	lsrs r1, r2, 24
	bl StartSpriteAnim
	b _081C4D02
_081C4CEC:
	adds r0, r5, r4
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r7
	adds r1, r6, 0x6
	lsls r1, 24
	lsrs r1, 24
	bl StartSpriteAnim
_081C4D02:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _081C4CB4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C4C84

	thumb_func_start sub_81C4D18
sub_81C4D18: @ 81C4D18
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF1C
	ldr r2, =0x000040d3
	adds r0, r2
	ldr r1, [r1]
	adds r5, r1, r0
	movs r3, 0
	ldr r4, =gSprites
	movs r7, 0x5
	negs r7, r7
	movs r6, 0
_081C4D32:
	adds r2, r5, r3
	ldrb r1, [r2]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	strh r6, [r0, 0x30]
	ldrb r0, [r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	adds r1, 0x3E
	ldrb r2, [r1]
	adds r0, r7, 0
	ands r0, r2
	strb r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x9
	bls _081C4D32
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4D18

	thumb_func_start sub_81C4D70
sub_81C4D70: @ 81C4D70
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	ldr r4, =gUnknown_0203CF28
	movs r0, 0x4
	bl Alloc
	str r0, [r4]
	ldr r1, [r5]
	lsls r0, r1, 20
	lsrs r4, r0, 30
	cmp r4, 0
	bne _081C4DDC
	lsls r0, r1, 30
	lsrs r0, 30
	movs r1, 0x8
	movs r2, 0
	bl SetBgAttribute
	ldr r3, [r5]
	lsls r0, r3, 30
	lsrs r0, 30
	ldr r1, =gUnknown_0861D1A0
	lsls r3, 22
	lsrs r3, 24
	str r4, [sp]
	movs r2, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	ldr r1, =gUnknown_0861DEF4
	movs r2, 0x1
	str r2, [sp]
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, [r5]
	lsls r1, 22
	lsrs r1, 24
	str r4, [sp]
	movs r2, 0x20
	movs r3, 0x20
	bl sub_8199D3C
	b _081C4E2E
	.pool
_081C4DDC:
	lsls r0, r1, 30
	lsrs r0, 30
	movs r1, 0x8
	movs r2, 0x2
	bl SetBgAttribute
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0x9
	movs r2, 0x1
	bl SetBgAttribute
	ldr r3, [r5]
	lsls r0, r3, 30
	lsrs r0, 30
	ldr r1, =gUnknown_0861E208
	lsls r3, 22
	lsrs r3, 24
	movs r2, 0
	str r2, [sp]
	bl decompress_and_copy_tile_data_to_vram
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	ldr r1, =gUnknown_0861EF64
	movs r4, 0x1
	str r4, [sp]
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	ldr r1, [r5]
	lsls r1, 22
	lsrs r1, 24
	str r4, [sp]
	movs r2, 0x40
	movs r3, 0x40
	bl sub_8199D3C
_081C4E2E:
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	movs r1, 0x4
	movs r2, 0x1
	bl SetBgAttribute
	ldr r0, =gUnknown_0861D140
	ldr r1, =gPlttBufferUnfaded + 0xE0
	ldr r2, =0x04000018
	bl CpuSet
	ldr r0, =gUnknown_0203CF28
	ldr r1, [r0]
	ldr r0, [r5]
	lsls r0, 30
	lsrs r0, 30
	strb r0, [r1]
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4D70

	thumb_func_start sub_81C4E90
sub_81C4E90: @ 81C4E90
	push {lr}
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	cmp r0, 0
	beq _081C4EA0
	movs r0, 0x1
	b _081C4EAC
_081C4EA0:
	ldr r0, =gUnknown_0203CF28
	ldr r0, [r0]
	ldrb r0, [r0]
	bl ShowBg
	movs r0, 0
_081C4EAC:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C4E90

	thumb_func_start sub_81C4EB4
sub_81C4EB4: @ 81C4EB4
	push {r4,lr}
	ldr r4, =gUnknown_0203CF28
	ldr r0, [r4]
	cmp r0, 0
	beq _081C4EC6
	bl Free
	movs r0, 0
	str r0, [r4]
_081C4EC6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4EB4

	thumb_func_start sub_81C4ED0
sub_81C4ED0: @ 81C4ED0
	push {lr}
	adds r1, r0, 0
	ldr r0, =gUnknown_0203CF28
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r1, 8
	movs r2, 0
	bl ChangeBgY
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4ED0

	thumb_func_start sub_81C4EEC
sub_81C4EEC: @ 81C4EEC
	ldr r1, =gUnknown_0203CF30
	movs r0, 0
	strh r0, [r1, 0x6]
	strh r0, [r1, 0x8]
	bx lr
	.pool
	thumb_func_end sub_81C4EEC

	thumb_func_start sub_81C4EFC
sub_81C4EFC: @ 81C4EFC
	push {lr}
	ldr r1, =sub_8086194
	movs r0, 0
	bl sub_81C4F98
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4EFC

	thumb_func_start sub_81C4F10
sub_81C4F10: @ 81C4F10
	push {lr}
	ldr r1, =sub_8059D50
	movs r0, 0x1
	bl sub_81C4F98
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4F10

	thumb_func_start sub_81C4F24
sub_81C4F24: @ 81C4F24
	push {lr}
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl fade_screen
	ldr r0, =sub_81C4F44
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4F24

	thumb_func_start sub_81C4F44
sub_81C4F44: @ 81C4F44
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081C4F6E
	bl overworld_free_bg_tilemaps
	ldr r0, =gUnknown_03005DB0
	ldr r1, =hm_add_c3_without_phase_2
	str r1, [r0]
	ldr r1, =c2_exit_to_overworld_2_switch
	movs r0, 0x3
	bl sub_81C4F98
	adds r0, r4, 0
	bl DestroyTask
_081C4F6E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4F44

	thumb_func_start sub_81C4F84
sub_81C4F84: @ 81C4F84
	push {lr}
	ldr r0, =gUnknown_0203CF30
	ldr r1, [r0]
	movs r0, 0x4
	bl sub_81C4F98
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4F84

	thumb_func_start sub_81C4F98
sub_81C4F98: @ 81C4F98
	push {r4-r6,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r6, =gUnknown_0203CF2C
	ldr r0, =0x0000098c
	bl AllocZeroed
	str r0, [r6]
	cmp r4, 0x4
	beq _081C4FB2
	ldr r0, =gUnknown_0203CF30
	strb r4, [r0, 0x4]
_081C4FB2:
	cmp r5, 0
	beq _081C4FBA
	ldr r0, =gUnknown_0203CF30
	str r5, [r0]
_081C4FBA:
	ldr r0, [r6]
	movs r1, 0
	str r1, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, =0x00000816
	adds r0, r1
	movs r1, 0x1
	negs r1, r1
	strb r1, [r0]
	ldr r0, [r6]
	ldr r1, =0x00000804
	adds r0, r1
	movs r1, 0xFF
	movs r2, 0xB
	bl memset
	ldr r0, [r6]
	ldr r1, =0x0000080f
	adds r0, r1
	movs r1, 0xFF
	movs r2, 0x5
	bl memset
	ldr r0, =sub_81C504C
	bl SetMainCallback2
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C4F98

	thumb_func_start sub_81C501C
sub_81C501C: @ 81C501C
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_81C501C

	thumb_func_start sub_81C5038
sub_81C5038: @ 81C5038
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_81C5038

	thumb_func_start sub_81C504C
sub_81C504C: @ 81C504C
	push {lr}
_081C504E:
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C5072
	bl sub_81C5078
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C5072
	bl sub_81221AC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C504E
_081C5072:
	pop {r0}
	bx r0
	thumb_func_end sub_81C504C

	thumb_func_start sub_81C5078
sub_81C5078: @ 81C5078
	push {lr}
	sub sp, 0x4
	ldr r0, =gMain
	movs r1, 0x87
	lsls r1, 3
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x10
	bls _081C508C
	b _081C51BC
_081C508C:
	lsls r0, 2
	ldr r1, =_081C50A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C50A0:
	.4byte _081C50E4
	.4byte _081C50EE
	.4byte _081C50F4
	.4byte _081C50FA
	.4byte _081C510C
	.4byte _081C5112
	.4byte _081C5122
	.4byte _081C513C
	.4byte _081C5148
	.4byte _081C514E
	.4byte _081C515C
	.4byte _081C5162
	.4byte _081C5168
	.4byte _081C516E
	.4byte _081C5174
	.4byte _081C517A
	.4byte _081C5188
_081C50E4:
	bl SetVBlankHBlankCallbacksToNull
	bl clear_scheduled_bg_copies_to_vram
	b _081C51A2
_081C50EE:
	bl remove_some_task
	b _081C51A2
_081C50F4:
	bl FreeAllSpritePalettes
	b _081C51A2
_081C50FA:
	bl ResetPaletteFade
	ldr r2, =gPaletteFade
	ldrb r0, [r2, 0x8]
	movs r1, 0x80
	orrs r0, r1
	b _081C51A0
	.pool
_081C510C:
	bl ResetSpriteData
	b _081C51A2
_081C5112:
	bl sub_81221AC
	lsls r0, 24
	cmp r0, 0
	bne _081C51A2
	bl ResetTasks
	b _081C51A2
_081C5122:
	bl sub_81C51DC
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000984
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	b _081C51A2
	.pool
_081C513C:
	bl sub_81C5238
	lsls r0, 24
	cmp r0, 0
	beq _081C51D4
	b _081C51A2
_081C5148:
	bl sub_81C6BD8
	b _081C51A2
_081C514E:
	bl sub_81C5924
	bl sub_81C59BC
	bl sub_81C5A20
	b _081C51A2
_081C515C:
	bl sub_81C5314
	b _081C51A2
_081C5162:
	bl sub_81C56F8
	b _081C51A2
_081C5168:
	bl sub_81C6EF4
	b _081C51A2
_081C516E:
	bl sub_81C5674
	b _081C51A2
_081C5174:
	bl sub_81C700C
	b _081C51A2
_081C517A:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x10
	movs r2, 0
	bl BlendPalettes
	b _081C51A2
_081C5188:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0
	str r1, [sp]
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	ldr r2, =gPaletteFade
	ldrb r1, [r2, 0x8]
	movs r0, 0x7F
	ands r0, r1
_081C51A0:
	strb r0, [r2, 0x8]
_081C51A2:
	ldr r1, =gMain
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _081C51D4
	.pool
_081C51BC:
	ldr r0, =sub_81C5038
	bl SetVBlankCallback
	ldr r0, =sub_81C501C
	bl SetMainCallback2
	movs r0, 0x1
	b _081C51D6
	.pool
_081C51D4:
	movs r0, 0
_081C51D6:
	add sp, 0x4
	pop {r1}
	bx r1
	thumb_func_end sub_81C5078

	thumb_func_start sub_81C51DC
sub_81C51DC: @ 81C51DC
	push {lr}
	bl sub_8121DA0
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_0861F2B4
	movs r0, 0
	movs r2, 0x3
	bl InitBgsFromTemplates
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	adds r1, 0x4
	movs r0, 0x2
	bl SetBgTilemapBuffer
	bl sub_8121E10
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C51DC

	thumb_func_start sub_81C5238
sub_81C5238: @ 81C5238
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_0203CF2C
	ldr r0, [r4]
	ldr r1, =0x00000984
	adds r0, r1
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	bhi _081C52F0
	lsls r0, 2
	ldr r1, =_081C5264
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C5264:
	.4byte _081C5278
	.4byte _081C5294
	.4byte _081C52B8
	.4byte _081C52C8
	.4byte _081C52D4
_081C5278:
	bl reset_temp_tile_data_buffers
	ldr r1, =gUnknown_08D9A620
	movs r0, 0
	str r0, [sp]
	movs r0, 0x2
	movs r2, 0
	movs r3, 0
	bl decompress_and_copy_tile_data_to_vram
	b _081C52D8
	.pool
_081C5294:
	bl free_temp_tile_data_buffers_if_possible
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C5308
	ldr r0, =gUnknown_08D9AE04
	ldr r4, =gUnknown_0203CF2C
	ldr r1, [r4]
	adds r1, 0x4
	bl LZDecompressWram
	ldr r1, [r4]
	b _081C52DC
	.pool
_081C52B8:
	ldr r0, =gUnknown_08D9AF44
	movs r1, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	b _081C52D8
	.pool
_081C52C8:
	ldr r0, =gUnknown_0861F3CC
	bl LoadCompressedObjectPic
	b _081C52D8
	.pool
_081C52D4:
	bl sub_81C6E98
_081C52D8:
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
_081C52DC:
	ldr r0, =0x00000984
	adds r1, r0
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _081C5308
	.pool
_081C52F0:
	bl sub_8122328
	ldr r0, [r4]
	ldr r1, =0x00000984
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	movs r0, 0x1
	b _081C530A
	.pool
_081C5308:
	movs r0, 0
_081C530A:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81C5238

	thumb_func_start sub_81C5314
sub_81C5314: @ 81C5314
	push {r4-r7,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r3, =0x00000e2c
	adds r0, r3
	adds r7, r2, r0
	movs r6, 0
	ldr r1, =gUnknown_0203CF2C
	ldr r0, [r1]
	ldr r4, =0x00000821
	adds r0, r4
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	bge _081C5382
	adds r5, r1, 0
_081C5344:
	lsls r1, r6, 1
	adds r4, r1, r6
	lsls r4, 3
	ldr r0, =0x0000087c
	adds r4, r0
	ldr r0, [r5]
	adds r0, r4
	adds r1, r7
	ldrh r1, [r1]
	bl sub_81C540C
	ldr r1, [r5]
	lsls r2, r6, 3
	ldr r3, =0x00000824
	adds r0, r1, r3
	adds r0, r2
	adds r4, r1, r4
	str r4, [r0]
	ldr r4, =0x00000828
	adds r0, r1, r4
	adds r0, r2
	str r6, [r0]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, =0x00000821
	adds r1, r0
	ldrb r0, [r1]
	subs r0, 0x1
	cmp r6, r0
	blt _081C5344
_081C5382:
	ldr r5, =gUnknown_0203CF2C
	lsls r4, r6, 1
	adds r4, r6
	lsls r4, 3
	ldr r1, =0x0000087c
	adds r4, r1
	ldr r0, [r5]
	adds r0, r4
	ldr r1, =gText_CloseBag
	bl StringCopy
	ldr r1, [r5]
	lsls r2, r6, 3
	ldr r3, =0x00000824
	adds r0, r1, r3
	adds r0, r2
	adds r4, r1, r4
	str r4, [r0]
	ldr r4, =0x00000828
	adds r1, r4
	adds r1, r2
	movs r0, 0x2
	negs r0, r0
	str r0, [r1]
	ldr r2, =gUnknown_03006310
	adds r1, r2, 0
	ldr r0, =gUnknown_0861F2C0
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldm r0!, {r4,r6,r7}
	stm r1!, {r4,r6,r7}
	ldr r1, [r5]
	ldr r6, =0x00000821
	adds r0, r1, r6
	ldrb r0, [r0]
	strh r0, [r2, 0xC]
	adds r3, r1, r3
	str r3, [r2]
	ldr r7, =0x00000822
	adds r1, r7
	ldrb r0, [r1]
	strh r0, [r2, 0xE]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5314

	thumb_func_start sub_81C540C
sub_81C540C: @ 81C540C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 16
	lsrs r4, r1, 16
	adds r0, r4, 0
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _081C5450
	ldr r0, =gStringVar1
	adds r1, r4, 0
	subs r1, 0x84
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r1, =gStringVar2
	adds r0, r4, 0
	bl CopyItemName
	ldr r1, =gUnknown_085E9210
	adds r0, r5, 0
	bl StringExpandPlaceholders
	b _081C5458
	.pool
_081C5450:
	adds r0, r4, 0
	adds r1, r5, 0
	bl CopyItemName
_081C5458:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C540C

	thumb_func_start sub_81C5460
sub_81C5460: @ 81C5460
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	cmp r1, 0x1
	beq _081C5476
	movs r0, 0x5
	bl PlaySE
	bl sub_81C6F20
_081C5476:
	ldr r5, =gUnknown_0203CF2C
	ldr r1, [r5]
	ldr r2, =0x00000814
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081C5504
	adds r2, 0x1
	adds r0, r1, r2
	ldrb r1, [r0]
	movs r0, 0x1
	eors r0, r1
	bl sub_81C6FF8
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081C54E0
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	lsls r3, r4, 1
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	ldr r0, =0x00000e2c
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	ldr r1, [r5]
	ldr r2, =0x00000815
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81C6F90
	b _081C54EE
	.pool
_081C54E0:
	ldr r0, =0x0000ffff
	ldr r1, [r5]
	ldr r2, =0x00000815
	adds r1, r2
	ldrb r1, [r1]
	bl sub_81C6F90
_081C54EE:
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000815
	adds r1, r0
	ldrb r0, [r1]
	movs r2, 0x1
	eors r0, r2
	strb r0, [r1]
	adds r0, r4, 0
	bl sub_81C55D8
_081C5504:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5460

	thumb_func_start sub_81C5518
sub_81C5518: @ 81C5518
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r1, 0
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081C55B8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	ldrb r1, [r0]
	cmp r1, 0xFF
	beq _081C5560
	lsls r0, r4, 24
	lsrs r0, 24
	cmp r1, r0
	bne _081C5558
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81C5AB8
	b _081C5560
	.pool
_081C5558:
	adds r0, r5, 0
	movs r1, 0xFF
	bl sub_81C5AB8
_081C5560:
	ldr r0, =gStringVar1
	ldr r1, =gSaveBlock2Ptr
	ldr r3, [r1]
	ldr r2, =0x00000ca9
	adds r1, r3, r2
	ldrb r2, [r1]
	lsls r2, 30
	lsrs r2, 30
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 1
	adds r1, r4, r1
	ldr r2, =0x00000e54
	adds r3, r2
	adds r3, r1
	ldrb r1, [r3]
	movs r2, 0x1
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x7
	adds r1, r4, 0
	movs r2, 0x77
	bl GetStringRightAlignXOffset
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	movs r1, 0
	str r1, [sp]
	str r1, [sp, 0x4]
	movs r0, 0xFF
	str r0, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r0, r6, 0
	adds r1, r4, 0
	adds r3, r5, 0
	bl sub_81C6C94
_081C55B8:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5518

	thumb_func_start sub_81C55D8
sub_81C55D8: @ 81C55D8
	push {r4,lr}
	sub sp, 0x10
	adds r3, r0, 0
	movs r0, 0x2
	negs r0, r0
	cmp r3, r0
	beq _081C561C
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	lsls r3, 1
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	ldr r0, =0x00000e2c
	adds r2, r0
	adds r2, r3
	ldrh r0, [r2]
	bl ItemId_GetDescription
	adds r4, r0, 0
	b _081C5638
	.pool
_081C561C:
	ldr r0, =gStringVar1
	ldr r2, =gUnknown_085E91B0
	ldr r1, =gUnknown_0203CF30
	ldrb r1, [r1, 0x4]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_ReturnToVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
_081C5638:
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C55D8

	thumb_func_start sub_81C5674
sub_81C5674: @ 81C5674
	push {r4,lr}
	sub sp, 0x10
	ldr r4, =gUnknown_0203CF2C
	ldr r1, [r4]
	ldr r2, =0x00000816
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _081C56B4
	adds r2, 0xB
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, 0x1
	adds r1, r2
	ldrb r1, [r1]
	subs r0, r1
	str r0, [sp]
	ldr r0, =0x00000b5e
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_0203CF38
	str r0, [sp, 0xC]
	movs r0, 0x2
	movs r1, 0xAC
	movs r2, 0xC
	movs r3, 0x94
	bl AddScrollIndicatorArrowPairParametrized
	ldr r1, [r4]
	ldr r2, =0x00000816
	adds r1, r2
	strb r0, [r1]
_081C56B4:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5674

	thumb_func_start sub_81C56CC
sub_81C56CC: @ 81C56CC
	push {r4,lr}
	ldr r4, =gUnknown_0203CF2C
	ldr r0, [r4]
	ldr r2, =0x00000816
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, 0xFF
	beq _081C56EA
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	ldr r1, =0x00000816
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
_081C56EA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C56CC

	thumb_func_start sub_81C56F8
sub_81C56F8: @ 81C56F8
	push {r4,lr}
	ldr r0, =sub_81C5BC8
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r0, =gUnknown_03006310
	ldr r2, =gUnknown_0203CF30
	ldrh r1, [r2, 0x8]
	ldrh r2, [r2, 0x6]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C56F8

	thumb_func_start sub_81C5738
sub_81C5738: @ 81C5738
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSaveBlock2Ptr
	ldr r6, [r2]
	ldr r3, =0x00000ca9
	adds r2, r6, r3
	ldrb r3, [r2]
	lsls r3, 30
	lsrs r2, r3, 30
	lsls r4, r2, 2
	adds r4, r2
	lsls r4, 2
	ldr r2, =0x00000e2c
	adds r4, r2
	adds r4, r6, r4
	lsrs r3, 30
	lsls r2, r3, 2
	adds r2, r3
	lsls r2, 1
	ldr r3, =0x00000e54
	adds r2, r3
	adds r6, r2
	lsls r5, r0, 1
	adds r5, r4
	ldrh r2, [r5]
	mov r8, r2
	lsls r2, r1, 1
	adds r2, r4
	ldrh r3, [r2]
	strh r3, [r5]
	mov r3, r8
	strh r3, [r2]
	adds r0, r6, r0
	ldrb r2, [r0]
	adds r6, r1
	ldrb r1, [r6]
	strb r1, [r0]
	strb r2, [r6]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5738

	thumb_func_start sub_81C57A8
sub_81C57A8: @ 81C57A8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r7, r4, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r2, r1, 30
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	ldr r2, =0x00000e2c
	adds r0, r2
	adds r6, r3, r0
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	ldr r1, =0x00000e54
	adds r0, r1
	adds r3, r0
	cmp r4, r5
	beq _081C5862
	lsls r0, r4, 1
	adds r0, r6
	ldrh r0, [r0]
	mov r12, r0
	adds r0, r3, r4
	ldrb r0, [r0]
	mov r8, r0
	cmp r5, r4
	bls _081C5830
	subs r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r2, r4, 16
	cmp r4, r5
	bge _081C5854
_081C5802:
	asrs r2, 16
	lsls r0, r2, 1
	adds r0, r6
	ldrh r1, [r0, 0x2]
	strh r1, [r0]
	adds r1, r3, r2
	ldrb r0, [r1, 0x1]
	strb r0, [r1]
	adds r2, 0x1
	lsls r2, 16
	asrs r0, r2, 16
	cmp r0, r5
	blt _081C5802
	b _081C5854
	.pool
_081C5830:
	lsls r2, r7, 16
	cmp r7, r5
	ble _081C5854
_081C5836:
	asrs r2, 16
	lsls r1, r2, 1
	adds r1, r6
	subs r0, r1, 0x2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, r3, r2
	subs r0, r1, 0x1
	ldrb r0, [r0]
	strb r0, [r1]
	subs r2, 0x1
	lsls r2, 16
	asrs r0, r2, 16
	cmp r0, r5
	bgt _081C5836
_081C5854:
	lsls r0, r5, 1
	adds r0, r6
	mov r2, r12
	strh r2, [r0]
	adds r0, r3, r5
	mov r1, r8
	strb r1, [r0]
_081C5862:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C57A8

	thumb_func_start sub_81C586C
sub_81C586C: @ 81C586C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r2, r1, 30
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 2
	ldr r2, =0x00000e2c
	adds r0, r2
	adds r0, r3
	mov r9, r0
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	ldr r4, =0x00000e54
	adds r0, r4
	adds r3, r0
	mov r8, r3
	movs r5, 0
	movs r3, 0
_081C58A4:
	lsls r0, r5, 1
	mov r1, r9
	adds r2, r0, r1
	ldrh r0, [r2]
	mov r4, r8
	adds r1, r4, r5
	cmp r0, 0
	beq _081C58BA
	ldrb r0, [r1]
	cmp r0, 0
	bne _081C58BE
_081C58BA:
	strh r3, [r2]
	strb r3, [r1]
_081C58BE:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x9
	bls _081C58A4
	movs r5, 0
_081C58CA:
	adds r1, r5, 0x1
	lsls r0, r1, 24
	lsrs r4, r0, 24
	adds r7, r1, 0
	cmp r4, 0x9
	bhi _081C58FE
	lsls r0, r5, 1
	mov r1, r9
	adds r6, r0, r1
_081C58DC:
	ldrh r0, [r6]
	cmp r0, 0
	beq _081C58EC
	mov r2, r8
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _081C58F4
_081C58EC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81C5738
_081C58F4:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x9
	bls _081C58DC
_081C58FE:
	lsls r0, r7, 24
	lsrs r5, r0, 24
	cmp r5, 0x8
	bls _081C58CA
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C586C

	thumb_func_start sub_81C5924
sub_81C5924: @ 81C5924
	push {r4-r6,lr}
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	ldr r1, =0x00000ca9
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x00000e2c
	adds r0, r1
	adds r5, r2, r0
	bl sub_81C586C
	ldr r3, =gUnknown_0203CF2C
	ldr r0, [r3]
	ldr r2, =0x00000821
	adds r0, r2
	movs r1, 0
	strb r1, [r0]
	movs r4, 0
	adds r6, r3, 0
_081C5954:
	lsls r0, r4, 1
	adds r0, r5
	ldrh r0, [r0]
	ldr r3, =gUnknown_0203CF2C
	cmp r0, 0
	beq _081C596A
	ldr r1, [r6]
	adds r1, r2
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
_081C596A:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x9
	bls _081C5954
	ldr r0, [r3]
	ldr r2, =0x00000821
	adds r0, r2
	ldrb r1, [r0]
	adds r1, 0x1
	strb r1, [r0]
	ldr r0, [r3]
	adds r2, r0, r2
	ldrb r2, [r2]
	cmp r2, 0x8
	bls _081C59AC
	ldr r2, =0x00000822
	adds r1, r0, r2
	movs r0, 0x8
	strb r0, [r1]
	b _081C59B2
	.pool
_081C59AC:
	ldr r1, =0x00000822
	adds r0, r1
	strb r2, [r0]
_081C59B2:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5924

	thumb_func_start sub_81C59BC
sub_81C59BC: @ 81C59BC
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203CF30
	ldrh r1, [r0, 0x8]
	adds r3, r0, 0
	ldr r4, =gUnknown_0203CF2C
	cmp r1, 0
	beq _081C59E4
	ldrh r0, [r3, 0x8]
	ldr r1, [r4]
	ldr r5, =0x00000822
	adds r2, r1, r5
	ldrb r2, [r2]
	adds r0, r2
	subs r5, 0x1
	adds r1, r5
	ldrb r1, [r1]
	cmp r0, r1
	ble _081C59E4
	subs r0, r1, r2
	strh r0, [r3, 0x8]
_081C59E4:
	adds r2, r3, 0
	ldrh r1, [r2, 0x8]
	ldrh r0, [r2, 0x6]
	adds r1, r0
	ldr r0, [r4]
	ldr r4, =0x00000821
	adds r0, r4
	ldrb r0, [r0]
	cmp r1, r0
	blt _081C5A18
	adds r1, r0, 0
	cmp r1, 0
	bne _081C5A14
	strh r1, [r2, 0x6]
	b _081C5A18
	.pool
_081C5A14:
	subs r0, 0x1
	strh r0, [r3, 0x6]
_081C5A18:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C59BC

	thumb_func_start sub_81C5A20
sub_81C5A20: @ 81C5A20
	push {r4-r7,lr}
	ldr r0, =gUnknown_0203CF30
	ldrh r1, [r0, 0x6]
	adds r5, r0, 0
	cmp r1, 0x4
	bls _081C5A80
	movs r4, 0
	ldrh r0, [r5, 0x6]
	subs r0, 0x4
	cmp r4, r0
	bgt _081C5A80
	ldrh r2, [r5, 0x8]
	ldr r6, =gUnknown_0203CF2C
	ldr r0, [r6]
	ldr r3, =0x00000822
	adds r1, r0, r3
	ldrb r1, [r1]
	adds r2, r1
	ldr r7, =0x00000821
	adds r0, r7
	ldrb r0, [r0]
	cmp r2, r0
	beq _081C5A80
	adds r3, r5, 0
_081C5A50:
	ldrh r0, [r3, 0x6]
	subs r0, 0x1
	strh r0, [r3, 0x6]
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	ldrh r0, [r3, 0x6]
	subs r0, 0x4
	cmp r4, r0
	bgt _081C5A80
	ldrh r2, [r5, 0x8]
	ldr r1, [r6]
	ldr r7, =0x00000822
	adds r0, r1, r7
	ldrb r0, [r0]
	adds r2, r0
	ldr r0, =0x00000821
	adds r1, r0
	ldrb r1, [r1]
	cmp r2, r1
	bne _081C5A50
_081C5A80:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5A20

	thumb_func_start sub_81C5A98
sub_81C5A98: @ 81C5A98
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	bl ListMenuGetYCoordForPrintingArrowCursor
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl sub_81C5AB8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81C5A98

	thumb_func_start sub_81C5AB8
sub_81C5AB8: @ 81C5AB8
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r2, 0xFF
	bne _081C5AF4
	movs r0, 0x1
	movs r1, 0
	bl GetMenuCursorDimensionByFont
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	movs r1, 0x1
	bl GetMenuCursorDimensionByFont
	lsls r0, 24
	lsrs r0, 24
	str r4, [sp]
	str r0, [sp, 0x4]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	adds r3, r5, 0
	bl FillWindowPixelRect
	b _081C5B08
_081C5AF4:
	ldr r1, =gText_SelectorArrow2
	movs r0, 0
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r2, [sp, 0xC]
	movs r2, 0
	adds r3, r5, 0
	bl sub_81C6C3C
_081C5B08:
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5AB8

	thumb_func_start sub_81C5B14
sub_81C5B14: @ 81C5B14
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
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
	ldr r1, =sub_81C5B4C
	str r1, [r0]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5B14

	thumb_func_start sub_81C5B4C
sub_81C5B4C: @ 81C5B4C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r2, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081C5BBC
	ldrb r0, [r2]
	ldr r4, =gUnknown_0203CF38
	subs r2, r4, 0x2
	adds r1, r4, 0
	bl sub_81AE6C8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, 0
	beq _081C5B94
	bl SetMainCallback2
	b _081C5B9E
	.pool
_081C5B94:
	adds r0, r4, 0
	subs r0, 0x8
	ldr r0, [r0]
	bl SetMainCallback2
_081C5B9E:
	bl sub_81C56CC
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl FreeAllWindowBuffers
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
_081C5BBC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5B4C

	thumb_func_start sub_81C5BC8
sub_81C5BC8: @ 81C5BC8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r7, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C5BEA
	b _081C5D16
_081C5BEA:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C5BF8
	b _081C5D16
_081C5BF8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x4
	ands r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _081C5C5C
	ldr r4, =gUnknown_0203CF30
	ldrb r0, [r4, 0x4]
	cmp r0, 0x2
	bne _081C5C12
	b _081C5D16
_081C5C12:
	ldrb r0, [r7]
	adds r1, r4, 0
	adds r1, 0x8
	adds r2, r4, 0x6
	bl get_coro_args_x18_x1A
	ldrh r1, [r4, 0x8]
	ldrh r0, [r4, 0x6]
	adds r1, r0
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r2, =0x00000821
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r1, r0
	beq _081C5D16
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81C67CC
	b _081C5D16
	.pool
_081C5C5C:
	ldrb r0, [r7]
	bl ListMenuHandleInput
	adds r6, r0, 0
	ldrb r0, [r7]
	ldr r1, =gUnknown_0203CF38
	mov r8, r1
	mov r2, r8
	subs r2, 0x2
	bl get_coro_args_x18_x1A
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _081C5C88
	adds r0, 0x1
	cmp r6, r0
	bne _081C5CA0
	b _081C5D16
	.pool
_081C5C88:
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gScriptItemId
	strh r4, [r0]
	adds r0, r5, 0
	bl sub_81C5B14
	b _081C5D16
	.pool
_081C5CA0:
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gScriptItemId
	mov r12, r2
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	lsls r3, r6, 1
	ldr r0, =0x00000ca9
	adds r4, r2, r0
	ldrb r1, [r4]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r3, r0
	ldr r1, =0x00000e2c
	adds r0, r2, r1
	adds r0, r3
	ldrh r0, [r0]
	mov r1, r12
	strh r0, [r1]
	strh r6, [r7, 0x2]
	ldrb r1, [r4]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, r6, r0
	ldr r1, =0x00000e54
	adds r2, r1
	adds r2, r0
	ldrb r0, [r2]
	strh r0, [r7, 0x4]
	mov r0, r8
	subs r0, 0x8
	ldrb r0, [r0, 0x4]
	cmp r0, 0x2
	bne _081C5D10
	adds r0, r5, 0
	bl sub_81C674C
	b _081C5D16
	.pool
_081C5D10:
	adds r0, r5, 0
	bl sub_81C5D20
_081C5D16:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C5BC8

	thumb_func_start sub_81C5D20
sub_81C5D20: @ 81C5D20
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_81C56CC
	ldrb r0, [r4]
	movs r1, 0x1
	bl sub_81C5A98
	ldr r0, =gUnknown_0203CF30
	ldrb r4, [r0, 0x4]
	cmp r4, 0x1
	beq _081C5D74
	cmp r4, 0x3
	beq _081C5DC4
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000818
	adds r2, r1, r0
	ldr r0, =gUnknown_0861F308
	str r0, [r2]
	movs r0, 0x82
	lsls r0, 4
	adds r1, r0
	movs r0, 0x4
	b _081C5DD8
	.pool
_081C5D74:
	ldr r0, =gScriptItemId
	ldrh r0, [r0]
	bl ItemId_GetBattleUsage
	lsls r0, 24
	cmp r0, 0
	beq _081C5DA0
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000818
	adds r2, r1, r0
	ldr r0, =gUnknown_0861F30E
	b _081C5DCE
	.pool
_081C5DA0:
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000818
	adds r2, r0, r1
	ldr r1, =gUnknown_0861F310
	str r1, [r2]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	strb r4, [r0]
	b _081C5DDA
	.pool
_081C5DC4:
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =0x00000818
	adds r2, r1, r0
	ldr r0, =gUnknown_0861F30C
_081C5DCE:
	str r0, [r2]
	movs r0, 0x82
	lsls r0, 4
	adds r1, r0
	movs r0, 0x2
_081C5DD8:
	strb r0, [r1]
_081C5DDA:
	ldr r0, =gScriptItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r4, =gStringVar4
	ldr r1, =gText_Var1IsSelected
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C5E3C
	movs r0, 0
	b _081C5E42
	.pool
_081C5E3C:
	cmp r0, 0x2
	bne _081C5E50
	movs r0, 0x1
_081C5E42:
	bl sub_81C6D24
	lsls r0, 24
	lsrs r0, 24
	bl sub_81C5EAC
	b _081C5E62
_081C5E50:
	movs r0, 0x2
	bl sub_81C6D24
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x2
	movs r2, 0x2
	bl sub_81C5F08
_081C5E62:
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _081C5E8C
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C5FE4
	b _081C5E98
	.pool
_081C5E8C:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81C5F68
_081C5E98:
	str r0, [r1]
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5D20

	thumb_func_start sub_81C5EAC
sub_81C5EAC: @ 81C5EAC
	push {r4-r6,lr}
	sub sp, 0x14
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	ldr r6, =gUnknown_0203CF2C
	ldr r1, [r6]
	movs r5, 0x82
	lsls r5, 4
	adds r0, r1, r5
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	ldr r0, =gUnknown_0861F2D8
	str r0, [sp, 0xC]
	ldr r0, =0x00000818
	adds r1, r0
	ldr r0, [r1]
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0x8
	movs r3, 0x1
	bl AddItemMenuActionTextPrinters
	ldr r0, [r6]
	adds r0, r5
	ldrb r1, [r0]
	adds r0, r4, 0
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5EAC

	thumb_func_start sub_81C5F08
sub_81C5F08: @ 81C5F08
	push {r4-r6,lr}
	sub sp, 0x14
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	movs r0, 0x38
	str r0, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	ldr r0, =gUnknown_0861F2D8
	str r0, [sp, 0xC]
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000818
	adds r0, r1
	ldr r0, [r0]
	str r0, [sp, 0x10]
	adds r0, r4, 0
	movs r1, 0x7
	movs r2, 0x8
	movs r3, 0x1
	bl sub_8198DBC
	movs r0, 0
	str r0, [sp]
	adds r0, r4, 0
	movs r1, 0x38
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_8199944
	add sp, 0x14
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5F08

	thumb_func_start sub_81C5F68
sub_81C5F68: @ 81C5F68
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C5FD0
	bl ProcessMenuInputNoWrapAround
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r4, r0
	beq _081C5FD0
	adds r0, 0x1
	cmp r4, r0
	bne _081C5FA8
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0861F2D8
	ldr r1, [r0, 0x1C]
	adds r0, r5, 0
	bl _call_via_r1
	b _081C5FD0
	.pool
_081C5FA8:
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gUnknown_0861F2D8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r2, =0x00000818
	adds r0, r2
	ldr r0, [r0]
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 3
	adds r1, 0x4
	adds r0, r1
	ldr r1, [r0]
	cmp r1, 0
	beq _081C5FD0
	adds r0, r6, 0
	bl _call_via_r1
_081C5FD0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5F68

	thumb_func_start sub_81C5FE4
sub_81C5FE4: @ 81C5FE4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C5FF8
	b _081C6160
_081C5FF8:
	bl GetMenuCursorPos
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gMain
	ldrh r1, [r5, 0x2E]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _081C6040
	lsls r0, r4, 24
	asrs r0, 24
	cmp r0, 0
	bgt _081C6016
	b _081C6160
_081C6016:
	subs r0, 0x2
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	bne _081C6028
	b _081C6160
_081C6028:
	movs r0, 0x5
	bl PlaySE
	movs r1, 0x1
	negs r1, r1
	movs r0, 0
	bl sub_8199134
	b _081C6160
	.pool
_081C6040:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081C6084
	lsls r0, r4, 24
	asrs r1, r0, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r2, 0x82
	lsls r2, 4
	adds r0, r2
	ldrb r0, [r0]
	subs r0, 0x2
	cmp r1, r0
	blt _081C6060
	b _081C6160
_081C6060:
	adds r0, r1, 0x2
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	movs r1, 0x1
	bl sub_8199134
	b _081C6160
	.pool
_081C6084:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	bne _081C6098
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C60C0
_081C6098:
	lsls r0, r4, 24
	asrs r1, r0, 24
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C6160
	subs r0, r1, 0x1
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
	negs r0, r0
	b _081C60FA
_081C60C0:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _081C60D6
	bl GetLRKeysState
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081C6102
_081C60D6:
	lsls r0, r4, 24
	asrs r1, r0, 24
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081C6160
	adds r0, r1, 0x1
	lsls r0, 24
	asrs r0, 24
	bl sub_81C616C
	lsls r0, 24
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x1
_081C60FA:
	movs r1, 0
	bl sub_8199134
	b _081C6160
_081C6102:
	ldrh r1, [r5, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C6148
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gUnknown_0861F2D8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	lsls r1, r4, 24
	asrs r1, 24
	ldr r3, =0x00000818
	adds r0, r3
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 3
	adds r2, 0x4
	adds r0, r2
	ldr r1, [r0]
	cmp r1, 0
	beq _081C6160
	adds r0, r6, 0
	bl _call_via_r1
	b _081C6160
	.pool
_081C6148:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C6160
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gUnknown_0861F2D8
	ldr r1, [r0, 0x1C]
	adds r0, r6, 0
	bl _call_via_r1
_081C6160:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C5FE4

	thumb_func_start sub_81C616C
sub_81C616C: @ 81C616C
	push {lr}
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	blt _081C61A0
	ldr r0, =gUnknown_0203CF2C
	ldr r2, [r0]
	movs r3, 0x82
	lsls r3, 4
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r1, r0
	bgt _081C61A0
	ldr r3, =0x00000818
	adds r0, r2, r3
	ldr r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x5
	beq _081C61A0
	movs r0, 0x1
	b _081C61A2
	.pool
_081C61A0:
	movs r0, 0
_081C61A2:
	pop {r1}
	bx r1
	thumb_func_end sub_81C616C

	thumb_func_start sub_81C61A8
sub_81C61A8: @ 81C61A8
	push {lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	movs r1, 0x82
	lsls r1, 4
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081C61C8
	movs r0, 0
	bl sub_81C6D6C
	b _081C61DA
	.pool
_081C61C8:
	cmp r0, 0x2
	bne _081C61D4
	movs r0, 0x1
	bl sub_81C6D6C
	b _081C61DA
_081C61D4:
	movs r0, 0x2
	bl sub_81C6D6C
_081C61DA:
	pop {r0}
	bx r0
	thumb_func_end sub_81C61A8

	thumb_func_start sub_81C61E0
sub_81C61E0: @ 81C61E0
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gScriptItemId
	ldrh r0, [r4]
	bl ItemId_GetPocket
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	beq _081C620C
	cmp r0, 0x2
	beq _081C620C
	cmp r0, 0x3
	beq _081C620C
	ldrh r0, [r4]
	bl itemid_is_mail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C6228
_081C620C:
	bl sub_81C61A8
	ldr r1, =gText_DadsAdvice
	ldr r2, =sub_81C6714
	adds r0, r5, 0
	bl DisplayItemMessageInBattlePyramid
	b _081C6252
	.pool
_081C6228:
	ldrh r0, [r4]
	bl ItemId_GetFieldFunc
	cmp r0, 0
	beq _081C6252
	bl sub_81C61A8
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldrh r0, [r4]
	bl ItemId_GetFieldFunc
	adds r1, r0, 0
	adds r0, r5, 0
	bl _call_via_r1
_081C6252:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C61E0

	thumb_func_start sub_81C6258
sub_81C6258: @ 81C6258
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_81C61A8
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_81C55D8
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	ldrb r0, [r4]
	movs r1, 0
	bl sub_81C5A98
	adds r0, r5, 0
	bl sub_81C629C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6258

	thumb_func_start sub_81C629C
sub_81C629C: @ 81C629C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81C5674
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81C5BC8
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C629C

	thumb_func_start sub_81C62C4
sub_81C62C4: @ 81C62C4
	push {r4-r7,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r6, r0, 3
	ldr r7, =gTasks + 0x8
	adds r4, r6, r7
	bl sub_81C61A8
	movs r0, 0x1
	strh r0, [r4, 0x10]
	movs r1, 0x4
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	bne _081C62F4
	adds r0, r5, 0
	bl sub_81C6350
	b _081C6334
	.pool
_081C62F4:
	ldr r0, =gScriptItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r4, =gStringVar4
	ldr r1, =gText_TossHowManyVar1s
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	bl sub_81C6404
	adds r0, r7, 0
	subs r0, 0x8
	adds r0, r6, r0
	ldr r1, =sub_81C64B4
	str r1, [r0]
_081C6334:
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C62C4

	thumb_func_start sub_81C6350
sub_81C6350: @ 81C6350
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	ldr r0, =gScriptItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x10
	ldrsh r1, [r4, r2]
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_ConfirmTossItems
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r4, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	ldr r1, =gUnknown_0861F314
	adds r0, r5, 0
	bl sub_81C6DAC
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6350

	thumb_func_start sub_81C63D0
sub_81C63D0: @ 81C63D0
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_81C55D8
	ldrb r0, [r4]
	movs r1, 0
	bl sub_81C5A98
	adds r0, r5, 0
	bl sub_81C629C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C63D0

	thumb_func_start sub_81C6404
sub_81C6404: @ 81C6404
	push {r4,lr}
	sub sp, 0xC
	ldr r0, =gStringVar1
	movs r1, 0x1
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x3
	bl sub_81C6CEC
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x28
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6404

	thumb_func_start sub_81C645C
sub_81C645C: @ 81C645C
	push {r4,lr}
	sub sp, 0xC
	adds r1, r0, 0
	ldr r0, =gStringVar1
	lsls r1, 16
	asrs r1, 16
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_xVar1
	adds r0, r4, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	adds r1, r4, 0
	movs r2, 0x28
	bl GetStringCenterAlignXOffset
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	movs r0, 0x2
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0x1
	adds r2, r4, 0
	bl PrintTextOnWindow
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C645C

	thumb_func_start sub_81C64B4
sub_81C64B4: @ 81C64B4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r6, r5, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0x10
	ldrh r1, [r4, 0x4]
	bl AdjustQuantityAccordingToDPadInput
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C64E8
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	bl sub_81C645C
	b _081C6544
	.pool
_081C64E8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C651C
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x3
	movs r1, 0
	bl sub_8198070
	movs r0, 0x3
	bl ClearWindowTilemap
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r5, 0
	bl sub_81C6350
	b _081C6544
	.pool
_081C651C:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081C6544
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x3
	movs r1, 0
	bl sub_8198070
	movs r0, 0x3
	bl ClearWindowTilemap
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r6, 0
	bl sub_81C63D0
_081C6544:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C64B4

	thumb_func_start sub_81C654C
sub_81C654C: @ 81C654C
	push {r4-r6,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r6, r4, r5
	ldr r0, =gScriptItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r0, =gStringVar2
	movs r2, 0x10
	ldrsh r1, [r6, r2]
	movs r2, 0
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	ldr r6, =gStringVar4
	ldr r1, =gText_ThrewAwayVar2Var1s
	adds r0, r6, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	movs r1, 0
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r6, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_81C65CC
	str r0, [r4]
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C654C

	thumb_func_start sub_81C65CC
sub_81C65CC: @ 81C65CC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r6, =gUnknown_0203CF38
	subs r7, r6, 0x2
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081C662E
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gScriptItemId
	ldrh r0, [r0]
	ldrh r1, [r4, 0x10]
	bl RemovePyramidBagItem
	ldrb r0, [r4]
	adds r1, r6, 0
	adds r2, r7, 0
	bl sub_81AE6C8
	bl sub_81C5924
	bl sub_81C59BC
	bl sub_81C5314
	ldr r0, =gUnknown_03006310
	ldrh r1, [r6]
	ldrh r2, [r7]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	adds r0, r5, 0
	bl sub_81C629C
_081C662E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C65CC

	thumb_func_start sub_81C6648
sub_81C6648: @ 81C6648
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	bl sub_81C61A8
	ldr r5, =gScriptItemId
	ldrh r0, [r5]
	bl itemid_is_mail
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081C667C
	ldr r1, =gText_CantWriteMail
	ldr r2, =sub_81C66EC
	adds r0, r4, 0
	bl DisplayItemMessageInBattlePyramid
	b _081C66A6
	.pool
_081C667C:
	ldrh r0, [r5]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _081C66A0
	ldr r0, =gUnknown_0203CF2C
	ldr r1, [r0]
	ldr r0, =sub_81B7F60
	str r0, [r1]
	adds r0, r4, 0
	bl sub_81C5B14
	b _081C66A6
	.pool
_081C66A0:
	adds r0, r6, 0
	bl sub_81C66AC
_081C66A6:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C6648

	thumb_func_start sub_81C66AC
sub_81C66AC: @ 81C66AC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gScriptItemId
	ldrh r0, [r0]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r5, =gStringVar4
	ldr r1, =gText_Var1CantBeHeld
	adds r0, r5, 0
	bl StringExpandPlaceholders
	ldr r2, =sub_81C66EC
	adds r0, r4, 0
	adds r1, r5, 0
	bl DisplayItemMessageInBattlePyramid
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C66AC

	thumb_func_start sub_81C66EC
sub_81C66EC: @ 81C66EC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C670A
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81C6714
_081C670A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C66EC

	thumb_func_start sub_81C6714
sub_81C6714: @ 81C6714
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl sub_81C6E1C
	movs r1, 0x2
	ldrsh r0, [r4, r1]
	bl sub_81C55D8
	ldrb r0, [r4]
	movs r1, 0
	bl sub_81C5A98
	adds r0, r5, 0
	bl sub_81C629C
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6714

	thumb_func_start sub_81C674C
sub_81C674C: @ 81C674C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	ldr r5, =gScriptItemId
	ldrh r0, [r5]
	bl itemid_80BF6D8_mail_related
	lsls r0, 24
	cmp r0, 0
	bne _081C677C
	ldr r1, =gText_CantWriteMail
	ldr r2, =sub_81C66EC
	adds r0, r4, 0
	bl DisplayItemMessageInBattlePyramid
	b _081C6796
	.pool
_081C677C:
	ldrh r0, [r5]
	bl itemid_is_unique
	lsls r0, 24
	cmp r0, 0
	bne _081C6790
	adds r0, r4, 0
	bl sub_81C5B14
	b _081C6796
_081C6790:
	adds r0, r6, 0
	bl sub_81C66AC
_081C6796:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81C674C

	thumb_func_start sub_81C679C
sub_81C679C: @ 81C679C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r4, =gScriptItemId
	ldrh r0, [r4]
	bl ItemId_GetBattleFunc
	cmp r0, 0
	beq _081C67C0
	bl sub_81C61A8
	ldrh r0, [r4]
	bl ItemId_GetBattleFunc
	adds r1, r0, 0
	adds r0, r5, 0
	bl _call_via_r1
_081C67C0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C679C

	thumb_func_start sub_81C67CC
sub_81C67CC: @ 81C67CC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x10
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	mov r9, r0
	adds r5, r4, r0
	ldr r0, =gUnknown_0203CF30
	ldrh r1, [r0, 0x6]
	ldrh r0, [r0, 0x8]
	adds r1, r0
	strh r1, [r5, 0x2]
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r2, =0x00000814
	adds r0, r2
	movs r2, 0
	mov r8, r2
	strb r1, [r0]
	ldrb r0, [r5]
	movs r1, 0x10
	movs r2, 0x1
	bl sub_81AF15C
	ldr r0, =gSaveBlock2Ptr
	ldr r3, [r0]
	movs r0, 0x2
	ldrsh r2, [r5, r0]
	lsls r2, 1
	ldr r1, =0x00000ca9
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r2, r0
	ldr r0, =0x00000e2c
	adds r3, r0
	adds r3, r2
	ldrh r0, [r3]
	ldr r1, =gStringVar1
	bl CopyItemName
	ldr r6, =gStringVar4
	ldr r1, =gText_MoveVar1Where
	adds r0, r6, 0
	bl StringExpandPlaceholders
	movs r0, 0x1
	movs r1, 0
	bl FillWindowPixelBuffer
	mov r1, r8
	str r1, [sp]
	movs r0, 0x1
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	str r1, [sp, 0xC]
	adds r1, r6, 0
	movs r2, 0x3
	movs r3, 0
	bl sub_81C6C3C
	ldrb r0, [r5]
	movs r1, 0x1
	bl sub_81C5A98
	ldrb r0, [r5, 0x2]
	bl sub_81C704C
	movs r2, 0x8
	negs r2, r2
	add r9, r2
	add r4, r9
	ldr r0, =sub_81C68B0
	str r0, [r4]
	add sp, 0x10
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C67CC

	thumb_func_start sub_81C68B0
sub_81C68B0: @ 81C68B0
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	bl sub_81221EC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081C695C
	ldr r7, =gMain
	ldrh r1, [r7, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081C68F8
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r4]
	ldr r1, =gUnknown_0203CF38
	subs r2, r1, 0x2
	bl get_coro_args_x18_x1A
	b _081C6940
	.pool
_081C68F8:
	ldrb r0, [r4]
	bl ListMenuHandleInput
	adds r6, r0, 0
	ldrb r0, [r4]
	ldr r4, =gUnknown_0203CF38
	subs r2, r4, 0x2
	adds r1, r4, 0
	bl get_coro_args_x18_x1A
	movs r0, 0
	bl sub_81C7028
	subs r4, 0x8
	ldrb r0, [r4, 0x6]
	bl sub_81C704C
	movs r0, 0x2
	negs r0, r0
	cmp r6, r0
	beq _081C6930
	adds r0, 0x1
	cmp r6, r0
	bne _081C6950
	b _081C695C
	.pool
_081C6930:
	movs r0, 0x5
	bl PlaySE
	ldrh r1, [r7, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081C6948
_081C6940:
	adds r0, r5, 0
	bl sub_81C6964
	b _081C695C
_081C6948:
	adds r0, r5, 0
	bl sub_81C6A14
	b _081C695C
_081C6950:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81C6964
_081C695C:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C68B0

	thumb_func_start sub_81C6964
sub_81C6964: @ 81C6964
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	ldr r7, =gUnknown_0203CF38
	subs r0, r7, 0x2
	mov r8, r0
	ldrh r0, [r0]
	ldrh r1, [r7]
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	movs r3, 0x2
	ldrsh r1, [r5, r3]
	cmp r1, r4
	beq _081C6996
	subs r0, r4, 0x1
	cmp r1, r0
	bne _081C69A8
_081C6996:
	adds r0, r6, 0
	bl sub_81C6A14
	b _081C69FC
	.pool
_081C69A8:
	ldrb r0, [r5, 0x2]
	lsls r1, r4, 24
	lsrs r1, 24
	bl sub_81C57A8
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	movs r0, 0x1
	bl sub_81C7028
	ldrb r0, [r5]
	adds r1, r7, 0
	mov r2, r8
	bl sub_81AE6C8
	movs r3, 0x2
	ldrsh r0, [r5, r3]
	cmp r0, r4
	bge _081C69E0
	adds r1, r7, 0
	subs r1, 0x8
	ldrh r0, [r1, 0x6]
	subs r0, 0x1
	strh r0, [r1, 0x6]
_081C69E0:
	bl sub_81C5314
	ldr r0, =gUnknown_03006310
	ldrh r1, [r7]
	mov r3, r8
	ldrh r2, [r3]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	adds r0, r6, 0
	bl sub_81C629C
_081C69FC:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6964

	thumb_func_start sub_81C6A14
sub_81C6A14: @ 81C6A14
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r5, =gUnknown_0203CF38
	subs r7, r5, 0x2
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000814
	adds r0, r1
	movs r1, 0xFF
	strb r1, [r0]
	movs r0, 0x1
	bl sub_81C7028
	ldrb r0, [r4]
	adds r1, r5, 0
	adds r2, r7, 0
	bl sub_81AE6C8
	movs r0, 0x2
	ldrsh r2, [r4, r0]
	ldrh r0, [r5]
	ldrh r1, [r7]
	adds r0, r1
	cmp r2, r0
	bge _081C6A5E
	adds r1, r5, 0
	subs r1, 0x8
	ldrh r0, [r1, 0x6]
	subs r0, 0x1
	strh r0, [r1, 0x6]
_081C6A5E:
	bl sub_81C5314
	ldr r0, =gUnknown_03006310
	ldrh r1, [r5]
	ldrh r2, [r7]
	bl ListMenuInit
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	adds r0, r6, 0
	bl sub_81C629C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6A14

	thumb_func_start sub_81C6A94
sub_81C6A94: @ 81C6A94
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	ldr r0, =gPlayerParty
	mov r9, r0
	movs r0, 0x14
	bl Alloc
	adds r7, r0, 0
	movs r0, 0xA
	bl Alloc
	adds r5, r0, 0
	ldr r1, =gSaveBlock2Ptr
	mov r8, r1
	ldr r2, [r1]
	ldr r4, =0x00000ca9
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldr r0, =0x00000e2c
	adds r1, r0
	adds r0, r7, 0
	movs r2, 0x14
	bl memcpy
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 30
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	adds r1, r2
	ldr r0, =0x00000e54
	adds r1, r0
	adds r0, r5, 0
	movs r2, 0xA
	bl memcpy
	movs r6, 0
_081C6AF8:
	movs r0, 0x64
	muls r0, r6
	add r0, r9
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r1, sp
	strh r0, [r1]
	cmp r0, 0
	beq _081C6B88
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	cmp r0, 0
	bne _081C6B88
	mov r1, r8
	ldr r2, [r1]
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, =0x00000e2c
	adds r0, r1
	adds r1, r7, 0
	movs r2, 0x14
	bl memcpy
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, r4
	ldrb r1, [r0]
	lsls r1, 30
	lsrs r1, 30
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, r2
	ldr r1, =0x00000e54
	adds r0, r1
	adds r1, r5, 0
	movs r2, 0xA
	bl memcpy
	adds r0, r7, 0
	bl Free
	adds r0, r5, 0
	bl Free
	ldr r1, =gScriptResult
	movs r0, 0x1
	strh r0, [r1]
	b _081C6BC6
	.pool
_081C6B88:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bls _081C6AF8
	movs r1, 0
	mov r0, sp
	strh r1, [r0]
	movs r6, 0
	movs r4, 0x64
_081C6B9C:
	adds r0, r6, 0
	muls r0, r4
	add r0, r9
	movs r1, 0xC
	mov r2, sp
	bl SetMonData
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x2
	bls _081C6B9C
	ldr r1, =gScriptResult
	movs r0, 0
	strh r0, [r1]
	adds r0, r7, 0
	bl Free
	adds r0, r5, 0
	bl Free
_081C6BC6:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6A94

	thumb_func_start sub_81C6BD8
sub_81C6BD8: @ 81C6BD8
	push {r4,lr}
	ldr r0, =gUnknown_0861F328
	bl InitWindows
	bl DeactivateAllTextPrinters
	movs r0, 0
	movs r1, 0x1
	movs r2, 0xE0
	bl sub_809882C
	movs r0, 0
	movs r1, 0xA
	movs r2, 0xD0
	bl copy_textbox_border_tile_patterns_to_vram
	ldr r0, =gUnknown_0860F074
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	movs r4, 0
_081C6C04:
	adds r0, r4, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x4
	bls _081C6C04
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6BD8

	thumb_func_start sub_81C6C3C
sub_81C6C3C: @ 81C6C3C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	ldr r4, [sp, 0x28]
	ldr r6, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	mov r8, r5
	ldr r5, [sp, 0x34]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r5, 24
	lsrs r5, 24
	str r4, [sp]
	str r6, [sp, 0x4]
	lsls r4, r5, 1
	adds r4, r5
	ldr r5, =gUnknown_0861F31C
	adds r4, r5
	str r4, [sp, 0x8]
	mov r4, r8
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x1
	bl AddTextPrinterParametrized2
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6C3C

	thumb_func_start sub_81C6C94
sub_81C6C94: @ 81C6C94
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x14
	ldr r4, [sp, 0x28]
	ldr r6, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	mov r8, r5
	ldr r5, [sp, 0x34]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r6, 24
	lsrs r6, 24
	lsls r5, 24
	lsrs r5, 24
	str r4, [sp]
	str r6, [sp, 0x4]
	lsls r4, r5, 1
	adds r4, r5
	ldr r5, =gUnknown_0861F31C
	adds r4, r5
	str r4, [sp, 0x8]
	mov r4, r8
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0xC]
	str r1, [sp, 0x10]
	movs r1, 0x7
	bl AddTextPrinterParametrized2
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6C94

	thumb_func_start sub_81C6CEC
sub_81C6CEC: @ 81C6CEC
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_81C6CEC

	thumb_func_start sub_81C6D08
sub_81C6D08: @ 81C6D08
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF2C
	ldr r1, [r1]
	ldr r2, =0x0000080f
	adds r1, r2
	adds r1, r0
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_81C6D08

	thumb_func_start sub_81C6D24
sub_81C6D24: @ 81C6D24
	push {r4,lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r3, =0x0000080f
	adds r1, r2, r3
	ldr r0, [r0]
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _081C6D58
	lsls r0, r2, 3
	ldr r1, =gUnknown_0861F350
	adds r0, r1
	bl AddWindow
	strb r0, [r4]
	ldrb r0, [r4]
	movs r1, 0
	movs r2, 0x1
	movs r3, 0xE
	bl SetWindowBorderStyle
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
_081C6D58:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C6D24

	thumb_func_start sub_81C6D6C
sub_81C6D6C: @ 81C6D6C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CF2C
	ldr r2, =0x0000080f
	adds r0, r2
	ldr r1, [r1]
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _081C6D9E
	movs r1, 0
	bl sub_8198070
	ldrb r0, [r4]
	bl ClearWindowTilemap
	ldrb r0, [r4]
	bl RemoveWindow
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	movs r0, 0xFF
	strb r0, [r4]
_081C6D9E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6D6C

	thumb_func_start sub_81C6DAC
sub_81C6DAC: @ 81C6DAC
	push {lr}
	sub sp, 0x10
	adds r3, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0861F370
	movs r2, 0x2
	str r2, [sp]
	movs r2, 0x1
	str r2, [sp, 0x4]
	movs r2, 0xE
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	movs r2, 0x1
	movs r3, 0
	bl CreateYesNoMenuWithCallbacks
	add sp, 0x10
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6DAC

	thumb_func_start DisplayItemMessageInBattlePyramid
@ void DisplayItemMessageInBattlePyramid(u8 taskId, u8 *str, void ( *callback)(u8 taskId))
DisplayItemMessageInBattlePyramid: @ 81C6DD8
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	bl sav2_get_text_speed
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1
	str r1, [sp]
	str r0, [sp, 0x4]
	str r5, [sp, 0x8]
	str r6, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0x2
	movs r2, 0xA
	movs r3, 0xD
	bl DisplayMessageAndContinueTask
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end DisplayItemMessageInBattlePyramid

	thumb_func_start sub_81C6E1C
sub_81C6E1C: @ 81C6E1C
	push {lr}
	movs r0, 0x2
	movs r1, 0
	bl sub_8197DF8
	movs r0, 0x2
	bl ClearWindowTilemap
	movs r0, 0x1
	bl schedule_bg_copy_tilemap_to_vram
	pop {r0}
	bx r0
	thumb_func_end sub_81C6E1C

	thumb_func_start sub_81C6E38
sub_81C6E38: @ 81C6E38
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r2, =0x00000804
	adds r1, r4, r2
	ldr r0, [r0]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	beq _081C6E80
	ldr r0, =0x00001024
	adds r4, r0
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	bl FreeSpriteOamMatrix
	ldrb r1, [r5]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	bl DestroySprite
	movs r0, 0xFF
	strb r0, [r5]
_081C6E80:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6E38

	thumb_func_start sub_81C6E98
sub_81C6E98: @ 81C6E98
	push {r4,lr}
	sub sp, 0x8
	movs r0, 0x40
	bl Alloc
	adds r4, r0, 0
	ldr r0, =gUnknown_08D9ADD0
	adds r1, r4, 0
	bl LZDecompressWram
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldr r1, =0x00000ca9
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 30
	lsrs r0, 25
	adds r0, r4, r0
	str r0, [sp]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	ldr r1, =0x00001024
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpritePalette
	adds r0, r4, 0
	bl Free
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6E98

	thumb_func_start sub_81C6EF4
sub_81C6EF4: @ 81C6EF4
	push {r4,lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r4, [r0]
	ldr r0, =0x00000804
	adds r4, r0
	ldr r0, =gUnknown_0861F3D4
	movs r1, 0x44
	movs r2, 0x38
	movs r3, 0
	bl CreateSprite
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6EF4

	thumb_func_start sub_81C6F20
sub_81C6F20: @ 81C6F20
	push {r4,lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000804
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r4, r0, r1
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081C6F50
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	ldr r0, =sub_81C6F68
	str r0, [r4, 0x1C]
_081C6F50:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6F20

	thumb_func_start sub_81C6F68
sub_81C6F68: @ 81C6F68
	push {r4,lr}
	adds r4, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _081C6F84
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	ldr r0, =SpriteCallbackDummy
	str r0, [r4, 0x1C]
_081C6F84:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6F68

	thumb_func_start sub_81C6F90
sub_81C6F90: @ 81C6F90
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r2, =0x00000805
	adds r1, r4, r2
	ldr r0, [r0]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, 0xFF
	bne _081C6FE0
	ldr r0, =0x00001025
	adds r4, r0
	adds r0, r4, 0
	bl FreeSpriteTilesByTag
	adds r0, r4, 0
	bl FreeSpritePaletteByTag
	adds r0, r4, 0
	adds r1, r4, 0
	adds r2, r6, 0
	bl AddItemIconObject
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _081C6FE0
	strb r2, [r5]
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	movs r1, 0x18
	strh r1, [r0, 0x24]
	movs r1, 0x58
	strh r1, [r0, 0x26]
_081C6FE0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C6F90

	thumb_func_start sub_81C6FF8
sub_81C6FF8: @ 81C6FF8
	push {lr}
	lsls r0, 24
	movs r1, 0x80
	lsls r1, 17
	adds r0, r1
	lsrs r0, 24
	bl sub_81C6E38
	pop {r0}
	bx r0
	thumb_func_end sub_81C6FF8

	thumb_func_start sub_81C700C
sub_81C700C: @ 81C700C
	push {lr}
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000807
	adds r0, r1
	movs r1, 0x8
	bl sub_8122344
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C700C

	thumb_func_start sub_81C7028
sub_81C7028: @ 81C7028
	push {lr}
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000807
	adds r0, r1
	movs r1, 0x8
	bl sub_81223FC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C7028

	thumb_func_start sub_81C704C
sub_81C704C: @ 81C704C
	push {lr}
	adds r3, r0, 0
	lsls r3, 24
	ldr r0, =gUnknown_0203CF2C
	ldr r0, [r0]
	ldr r1, =0x00000807
	adds r0, r1
	lsrs r3, 4
	movs r1, 0x80
	lsls r1, 13
	adds r3, r1
	lsrs r3, 16
	movs r1, 0x88
	movs r2, 0x78
	bl sub_8122448
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81C704C

	thumb_func_start sub_81C7078
sub_81C7078: @ 81C7078
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl is_c1_link_related_active
	cmp r0, 0
	bne _081C7090
	ldr r0, =sub_81C7170
	b _081C7092
	.pool
_081C7090:
	ldr r0, =sub_81C71E4
_081C7092:
	lsls r1, r4, 24
	lsrs r1, 24
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	movs r1, 0x1
	adds r2, r5, 0
	bl SetWordTaskArg
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r2, =gUnknown_0203CF3C
	ldrb r1, [r2]
	strh r1, [r0, 0xE]
	ldrb r0, [r2]
	adds r1, r0, 0x1
	strb r1, [r2]
	lsls r0, 24
	lsrs r0, 8
	orrs r0, r4
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81C7078

	thumb_func_start sub_81C70D8
sub_81C70D8: @ 81C70D8
	push {lr}
	ldr r1, =0x0000ffff
	ands r1, r0
	lsrs r3, r0, 16
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r1, r0, r2
	ldrb r0, [r1, 0x4]
	cmp r0, 0
	beq _081C711C
	ldr r2, [r1]
	ldr r0, =sub_81C7170
	cmp r2, r0
	beq _081C70FE
	ldr r0, =sub_81C71E4
	cmp r2, r0
	bne _081C711C
_081C70FE:
	movs r2, 0xE
	ldrsh r0, [r1, r2]
	cmp r0, r3
	bne _081C711C
	movs r0, 0x1
	b _081C711E
	.pool
_081C711C:
	movs r0, 0
_081C711E:
	pop {r1}
	bx r1
	thumb_func_end sub_81C70D8

	thumb_func_start sub_81C7124
sub_81C7124: @ 81C7124
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r5, 0
	ldr r4, =gTasks
_081C712C:
	ldrb r0, [r4, 0x4]
	cmp r0, 0
	beq _081C7160
	ldr r1, [r4]
	ldr r0, =sub_81C7170
	cmp r1, r0
	beq _081C7140
	ldr r0, =sub_81C71E4
	cmp r1, r0
	bne _081C7160
_081C7140:
	lsls r0, r5, 24
	lsrs r0, 24
	movs r1, 0x1
	bl GetWordTaskArg
	cmp r0, r6
	bne _081C7160
	movs r0, 0x1
	b _081C716A
	.pool
_081C7160:
	adds r4, 0x28
	adds r5, 0x1
	cmp r5, 0xF
	ble _081C712C
	movs r0, 0
_081C716A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_81C7124

	thumb_func_start sub_81C7170
sub_81C7170: @ 81C7170
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r6, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r7, 0
_081C718C:
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl _call_via_r6
	cmp r0, 0x4
	bhi _081C71D6
	lsls r0, 2
	ldr r1, =_081C71AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C71AC:
	.4byte _081C71C6
	.4byte _081C71C0
	.4byte _081C71DE
	.4byte _081C71DA
	.4byte _081C71CE
_081C71C0:
	ldrh r0, [r4]
	adds r0, 0x1
	b _081C71D8
_081C71C6:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	b _081C71DE
_081C71CE:
	adds r0, r5, 0
	bl DestroyTask
	b _081C71DE
_081C71D6:
	subs r0, 0x5
_081C71D8:
	strh r0, [r4]
_081C71DA:
	cmp r7, 0
	beq _081C718C
_081C71DE:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81C7170

	thumb_func_start sub_81C71E4
sub_81C71E4: @ 81C71E4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_8087598
	cmp r0, 0
	bne _081C724A
	adds r0, r5, 0
	movs r1, 0x1
	bl GetWordTaskArg
	adds r2, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0
	ldrsh r0, [r4, r1]
	bl _call_via_r2
	cmp r0, 0x4
	bhi _081C7246
	lsls r0, 2
	ldr r1, =_081C7224
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081C7224:
	.4byte _081C7238
	.4byte _081C7238
	.4byte _081C724A
	.4byte _081C724A
	.4byte _081C723E
_081C7238:
	ldrh r0, [r4]
	adds r0, 0x1
	b _081C7248
_081C723E:
	adds r0, r5, 0
	bl DestroyTask
	b _081C724A
_081C7246:
	subs r0, 0x5
_081C7248:
	strh r0, [r4]
_081C724A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81C71E4

	.align 2, 0 @ Don't pad with nop.
