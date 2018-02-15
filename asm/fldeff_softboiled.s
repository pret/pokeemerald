	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

//	thumb_func_start hm_prepare_dive_probably
//hm_prepare_dive_probably: @ 8161508
//	push {r4-r6,lr}
//	bl GetCursorSelectionMonId
//	lsls r0, 24
//	lsrs r0, 24
//	movs r6, 0x64
//	muls r0, r6
//	ldr r4, =gPlayerParty
//	adds r0, r4
//	movs r1, 0x3A
//	bl GetMonData
//	adds r5, r0, 0
//	lsls r5, 16
//	lsrs r5, 16
//	bl GetCursorSelectionMonId
//	lsls r0, 24
//	lsrs r0, 24
//	muls r0, r6
//	adds r0, r4
//	movs r1, 0x39
//	bl GetMonData
//	adds r4, r0, 0
//	lsls r4, 16
//	lsrs r4, 16
//	adds r0, r5, 0
//	movs r1, 0x5
//	bl __udivsi3
//	lsls r0, 16
//	lsrs r0, 16
//	cmp r4, r0
//	bhi _08161558
//	movs r0, 0
//	b _0816155A
//	.pool
//_08161558:
//	movs r0, 0x1
//_0816155A:
//	pop {r4-r6}
//	pop {r1}
//	bx r1
//	thumb_func_end hm_prepare_dive_probably

//	thumb_func_start sub_8161560
//sub_8161560: @ 8161560
//	push {r4,lr}
//	adds r4, r0, 0
//	lsls r4, 24
//	lsrs r4, 24
//	ldr r0, =gUnknown_0203CEC8
//	movs r1, 0xA
//	strb r1, [r0, 0xB]
//	ldrb r1, [r0, 0x9]
//	strb r1, [r0, 0xA]
//	bl GetCursorSelectionMonId
//	lsls r0, 24
//	lsrs r0, 24
//	movs r1, 0x1
//	bl sub_81B0FCC
//	movs r0, 0x5
//	bl display_pokemon_menu_message
//	ldr r1, =gTasks
//	lsls r0, r4, 2
//	adds r0, r4
//	lsls r0, 3
//	adds r0, r1
//	ldr r1, =sub_81B1370
//	str r1, [r0]
//	pop {r4}
//	pop {r0}
//	bx r0
//	.pool
//	thumb_func_end sub_8161560

//	thumb_func_start sub_81615A8
//sub_81615A8: @ 81615A8
//	push {r4-r7,lr}
//	mov r7, r10
//	mov r6, r9
//	mov r5, r8
//	push {r5-r7}
//	sub sp, 0x8
//	lsls r0, 24
//	lsrs r4, r0, 24
//	str r4, [sp, 0x4]
//	ldr r1, =gUnknown_0203CEC8
//	ldrb r7, [r1, 0x9]
//	mov r8, r7
//	ldrb r0, [r1, 0xA]
//	adds r5, r0, 0
//	cmp r5, 0x6
//	bls _081615EC
//	movs r0, 0
//	strb r0, [r1, 0xB]
//	bl display_pokemon_menu_message
//	ldr r1, =gTasks
//	lsls r0, r4, 2
//	adds r0, r4
//	lsls r0, 3
//	adds r0, r1
//	ldr r1, =sub_81B1370
//	str r1, [r0]
//	b _08161658
//	.pool
//_081615EC:
//	movs r0, 0x64
//	mov r10, r0
//	mov r0, r10
//	muls r0, r5
//	ldr r1, =gPlayerParty
//	mov r9, r1
//	adds r6, r0, r1
//	adds r0, r6, 0
//	movs r1, 0x39
//	bl GetMonData
//	lsls r0, 16
//	lsrs r4, r0, 16
//	cmp r4, 0
//	beq _0816161A
//	cmp r7, r5
//	beq _0816161A
//	adds r0, r6, 0
//	movs r1, 0x3A
//	bl GetMonData
//	cmp r0, r4
//	bne _08161628
//_0816161A:
//	ldr r0, [sp, 0x4]
//	bl sub_81617B8
//	b _08161658
//	.pool
//_08161628:
//	movs r0, 0x1
//	bl PlaySE
//	mov r1, r10
//	mov r0, r8
//	muls r0, r1
//	add r0, r9
//	movs r1, 0x3A
//	bl GetMonData
//	movs r1, 0x5
//	bl __udivsi3
//	adds r3, r0, 0
//	lsls r3, 16
//	asrs r3, 16
//	movs r2, 0x1
//	negs r2, r2
//	ldr r0, =sub_816166C
//	str r0, [sp]
//	ldr r0, [sp, 0x4]
//	mov r1, r8
//	bl sub_81B1F18
//_08161658:
//	add sp, 0x8
//	pop {r3-r5}
//	mov r8, r3
//	mov r9, r4
//	mov r10, r5
//	pop {r4-r7}
//	pop {r0}
//	bx r0
//	.pool
//	thumb_func_end sub_81615A8

//	thumb_func_start sub_816166C
//sub_816166C: @ 816166C
//	push {r4,r5,lr}
//	sub sp, 0x4
//	adds r4, r0, 0
//	lsls r4, 24
//	lsrs r4, 24
//	movs r0, 0x1
//	bl PlaySE
//	ldr r5, =gUnknown_0203CEC8
//	movs r1, 0x9
//	ldrsb r1, [r5, r1]
//	movs r0, 0x64
//	muls r0, r1
//	ldr r1, =gPlayerParty
//	adds r0, r1
//	movs r1, 0x3A
//	bl GetMonData
//	movs r1, 0x5
//	bl __udivsi3
//	adds r3, r0, 0
//	lsls r3, 16
//	asrs r3, 16
//	ldrb r1, [r5, 0xA]
//	ldr r0, =sub_81616C0
//	str r0, [sp]
//	adds r0, r4, 0
//	movs r2, 0x1
//	bl sub_81B1F18
//	add sp, 0x4
//	pop {r4,r5}
//	pop {r0}
//	bx r0
//	.pool
//	thumb_func_end sub_816166C

	thumb_func_start sub_81616C0
sub_81616C0: @ 81616C0
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0xA
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gStringVar1
	bl GetMonNickname
	ldr r4, =gStringVar4
	ldr r1, =gText_PkmnHPRestoredByVar2
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8161724
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81616C0

	thumb_func_start sub_8161724
sub_8161724: @ 8161724
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _08161772
	ldr r4, =gUnknown_0203CEC8
	movs r0, 0
	strb r0, [r4, 0xB]
	ldrb r0, [r4, 0x9]
	movs r1, 0
	bl sub_81B0FCC
	ldrb r0, [r4, 0xA]
	strb r0, [r4, 0x9]
	ldrb r0, [r4, 0xA]
	movs r1, 0x1
	bl sub_81B0FCC
	movs r0, 0x6
	movs r1, 0
	bl sub_8198070
	movs r0, 0x6
	bl ClearWindowTilemap
	movs r0, 0
	bl display_pokemon_menu_message
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B1370
	str r1, [r0]
_08161772:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161724

	thumb_func_start sub_8161784
sub_8161784: @ 8161784
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081617AA
	movs r0, 0x5
	bl display_pokemon_menu_message
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B1370
	str r0, [r1]
_081617AA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8161784

	thumb_func_start sub_81617B8
sub_81617B8: @ 81617B8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gText_CantBeUsedOnPkmn
	movs r1, 0
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_8161784
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81617B8

	.align 2, 0 @ Don't pad with nop.
