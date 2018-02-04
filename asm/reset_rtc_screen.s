	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_809E8E8
sub_809E8E8: @ 809E8E8
	push {lr}
	adds r3, r0, 0
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0xC
	ldrsh r1, [r0, r2]
	movs r2, 0x30
	ldrsh r0, [r3, r2]
	cmp r1, r0
	beq _0809E9FE
	strh r1, [r3, 0x30]
	subs r0, r1, 0x1
	cmp r0, 0x5
	bhi _0809E9FE
	lsls r0, 2
	ldr r1, =_0809E920
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0809E920:
	.4byte _0809E938
	.4byte _0809E95C
	.4byte _0809E980
	.4byte _0809E9A4
	.4byte _0809E9CE
	.4byte _0809E9F8
_0809E938:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, 0
	adds r1, 0x2A
	movs r0, 0x1
	strb r0, [r1]
	subs r2, 0x12
	ldrb r1, [r2]
	subs r0, 0x41
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x35
	b _0809E9C6
_0809E95C:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, 0
	adds r1, 0x2A
	movs r0, 0x1
	strb r0, [r1]
	subs r2, 0x12
	ldrb r1, [r2]
	subs r0, 0x41
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x56
	b _0809E9C6
_0809E980:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, 0
	adds r1, 0x2A
	movs r0, 0x1
	strb r0, [r1]
	subs r2, 0x12
	ldrb r1, [r2]
	subs r0, 0x41
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x65
	b _0809E9C6
_0809E9A4:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, 0
	adds r1, 0x2A
	movs r0, 0x1
	strb r0, [r1]
	subs r2, 0x12
	ldrb r1, [r2]
	subs r0, 0x41
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x74
_0809E9C6:
	strh r0, [r3, 0x20]
	movs r0, 0x44
	strh r0, [r3, 0x22]
	b _0809E9FE
_0809E9CE:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, 0
	adds r1, 0x2A
	movs r0, 0x2
	strb r0, [r1]
	subs r2, 0x12
	ldrb r1, [r2]
	subs r0, 0x42
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x99
	strh r0, [r3, 0x20]
	movs r0, 0x50
	strh r0, [r3, 0x22]
	b _0809E9FE
_0809E9F8:
	adds r0, r3, 0
	bl DestroySprite
_0809E9FE:
	pop {r0}
	bx r0
	thumb_func_end sub_809E8E8

	thumb_func_start sub_809EA04
sub_809EA04: @ 809EA04
	push {lr}
	adds r3, r0, 0
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0xC
	ldrsh r1, [r0, r2]
	movs r2, 0x30
	ldrsh r0, [r3, r2]
	cmp r1, r0
	beq _0809EAFE
	strh r1, [r3, 0x30]
	subs r0, r1, 0x1
	cmp r0, 0x5
	bhi _0809EAFE
	lsls r0, 2
	ldr r1, =_0809EA3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0809EA3C:
	.4byte _0809EA54
	.4byte _0809EA78
	.4byte _0809EA9C
	.4byte _0809EAC0
	.4byte _0809EAEA
	.4byte _0809EAF8
_0809EA54:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, 0
	adds r1, 0x2A
	movs r0, 0
	strb r0, [r1]
	subs r2, 0x12
	ldrb r1, [r2]
	subs r0, 0x40
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x35
	b _0809EAE2
_0809EA78:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, 0
	adds r1, 0x2A
	movs r0, 0
	strb r0, [r1]
	subs r2, 0x12
	ldrb r1, [r2]
	subs r0, 0x40
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x56
	b _0809EAE2
_0809EA9C:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, 0
	adds r1, 0x2A
	movs r0, 0
	strb r0, [r1]
	subs r2, 0x12
	ldrb r1, [r2]
	subs r0, 0x40
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x65
	b _0809EAE2
_0809EAC0:
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	adds r1, r3, 0
	adds r1, 0x2A
	movs r0, 0
	strb r0, [r1]
	subs r2, 0x12
	ldrb r1, [r2]
	subs r0, 0x40
	ands r0, r1
	strb r0, [r2]
	movs r0, 0x74
_0809EAE2:
	strh r0, [r3, 0x20]
	movs r0, 0x5C
	strh r0, [r3, 0x22]
	b _0809EAFE
_0809EAEA:
	adds r0, r3, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _0809EAFE
_0809EAF8:
	adds r0, r3, 0
	bl DestroySprite
_0809EAFE:
	pop {r0}
	bx r0
	thumb_func_end sub_809EA04

	thumb_func_start sub_809EB04
sub_809EB04: @ 809EB04
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_085104C4
	bl LoadSpritePalette
	ldr r0, =gSpriteTemplate_85104F0
	mov r8, r0
	movs r1, 0x35
	movs r2, 0x44
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r6, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r6, 0
	adds r4, 0x1C
	adds r2, r0, r4
	ldr r1, =sub_809E8E8
	str r1, [r2]
	adds r0, r6
	strh r5, [r0, 0x2E]
	ldr r1, =0x0000ffff
	strh r1, [r0, 0x30]
	mov r0, r8
	movs r1, 0x35
	movs r2, 0x44
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r4, r0, r4
	ldr r1, =sub_809EA04
	str r1, [r4]
	adds r0, r6
	strh r5, [r0, 0x2E]
	movs r1, 0x1
	negs r1, r1
	strh r1, [r0, 0x30]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809EB04

	thumb_func_start sub_809EB8C
sub_809EB8C: @ 809EB8C
	push {lr}
	ldr r0, =gUnknown_085104C4
	ldrh r0, [r0, 0x4]
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809EB8C

	thumb_func_start sub_809EBA0
sub_809EBA0: @ 809EBA0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0
	bl sub_8198070
	adds r0, r4, 0
	bl RemoveWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_809EBA0

	thumb_func_start sub_809EBC4
sub_809EBC4: @ 809EBC4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r10, r0
	adds r0, r1, 0
	mov r9, r2
	adds r1, r3, 0
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	ldr r2, [sp, 0x38]
	mov r8, r2
	mov r2, r10
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	lsls r3, r0, 24
	lsrs r3, 24
	str r3, [sp, 0xC]
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsls r1, 16
	lsrs r1, 16
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	mov r2, r8
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	ldr r7, =gStringVar4
	ldr r4, =gStringVar1
	adds r0, r4, 0
	movs r2, 0x1
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	adds r0, r7, 0
	adds r1, r4, 0
	bl StringCopy
	adds r7, r0, 0
	ldr r1, =gText_Day
	bl StringCopy
	adds r7, r0, 0
	adds r0, r4, 0
	adds r1, r5, 0
	movs r2, 0x1
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	adds r0, r7, 0
	adds r1, r4, 0
	bl StringCopy
	adds r7, r0, 0
	ldr r5, =gText_Colon3
	adds r1, r5, 0
	bl StringCopy
	adds r7, r0, 0
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	adds r0, r7, 0
	adds r1, r4, 0
	bl StringCopy
	adds r7, r0, 0
	adds r1, r5, 0
	bl StringCopy
	adds r7, r0, 0
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalStringN
	adds r0, r7, 0
	adds r1, r4, 0
	bl StringCopy
	ldr r2, =gStringVar4
	mov r0, r9
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	mov r0, r10
	movs r1, 0x1
	ldr r3, [sp, 0xC]
	bl PrintTextOnWindow
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809EBC4

	thumb_func_start sub_809ECB4
sub_809ECB4: @ 809ECB4
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0xC
	adds r4, r0, 0
	mov r9, r1
	adds r5, r2, 0
	adds r6, r3, 0
	ldr r0, [sp, 0x24]
	mov r8, r0
	lsls r4, 24
	lsrs r4, 24
	mov r0, r9
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r2, 0x85
	lsls r2, 2
	adds r0, r4, 0
	movs r1, 0
	movs r3, 0xE
	bl SetWindowBorderStyle
	str r5, [sp]
	str r6, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x1
	mov r3, r9
	bl sub_809EBC4
	ldr r2, =gText_Confirm2
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	adds r0, r4, 0
	movs r1, 0x1
	movs r3, 0x7E
	bl PrintTextOnWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0xC
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809ECB4

	thumb_func_start sub_809ED38
sub_809ED38: @ 809ED38
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r3, 16
	lsrs r3, 16
	adds r1, r3, 0
	movs r0, 0x80
	ands r0, r3
	cmp r0, 0
	beq _0809ED52
	ldrh r0, [r4]
	subs r0, 0x1
	b _0809ED6C
_0809ED52:
	movs r0, 0x40
	ands r0, r3
	cmp r0, 0
	beq _0809ED60
	ldrh r0, [r4]
	adds r0, 0x1
	b _0809ED8A
_0809ED60:
	movs r0, 0x20
	ands r0, r3
	cmp r0, 0
	beq _0809ED7A
	ldrh r0, [r4]
	subs r0, 0xA
_0809ED6C:
	strh r0, [r4]
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, r5
	bge _0809ED96
	strh r2, [r4]
	b _0809ED96
_0809ED7A:
	movs r0, 0x10
	ands r1, r0
	cmp r1, 0
	bne _0809ED86
	movs r0, 0
	b _0809ED98
_0809ED86:
	ldrh r0, [r4]
	adds r0, 0xA
_0809ED8A:
	strh r0, [r4]
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, r2
	ble _0809ED96
	strh r5, [r4]
_0809ED96:
	movs r0, 0x1
_0809ED98:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_809ED38

	thumb_func_start sub_809EDA0
sub_809EDA0: @ 809EDA0
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x8]
	bx lr
	.pool
	thumb_func_end sub_809EDA0

	thumb_func_start sub_809EDB8
sub_809EDB8: @ 809EDB8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r5, =gTasks + 0x8
	adds r0, r4, r5
	ldrb r0, [r0, 0x10]
	bl sub_809EBA0
	bl sub_809EB8C
	subs r5, 0x8
	adds r4, r5
	ldr r0, =sub_809EDA0
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809EDB8

	thumb_func_start sub_809EDE8
sub_809EDE8: @ 809EDE8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r0, r6, 2
	adds r0, r6
	lsls r7, r0, 3
	ldr r0, =gTasks + 0x8
	mov r8, r0
	adds r5, r7, r0
	ldrb r4, [r5, 0x4]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	ldr r1, =gUnknown_08510420 - 0x4
	adds r2, r0, r1
	ldr r1, =gMain
	ldrh r3, [r1, 0x2E]
	movs r0, 0x2
	ands r0, r3
	mov r12, r1
	cmp r0, 0
	beq _0809EE3C
	mov r0, r8
	subs r0, 0x8
	adds r0, r7, r0
	ldr r1, =sub_809EDB8
	str r1, [r0]
	movs r0, 0
	strh r0, [r5, 0x2]
	movs r0, 0x6
	b _0809EE5C
	.pool
_0809EE3C:
	movs r0, 0x10
	ands r0, r3
	cmp r0, 0
	beq _0809EE4A
	ldrb r0, [r2, 0x7]
	cmp r0, 0
	bne _0809EE5C
_0809EE4A:
	mov r3, r12
	ldrh r1, [r3, 0x2E]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0809EE66
	ldrb r0, [r2, 0x6]
	cmp r0, 0
	beq _0809EE66
_0809EE5C:
	strh r0, [r5, 0x4]
	movs r0, 0x5
	bl PlaySE
	b _0809EEF4
_0809EE66:
	cmp r4, 0x5
	bne _0809EEB4
	mov r0, r12
	ldrh r1, [r0, 0x2E]
	movs r4, 0x1
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _0809EEF4
	ldr r1, =gLocalTime
	ldrh r0, [r5, 0x6]
	strh r0, [r1]
	ldrh r0, [r5, 0x8]
	strb r0, [r1, 0x2]
	ldrh r0, [r5, 0xA]
	strb r0, [r1, 0x3]
	ldrh r0, [r5, 0xC]
	strb r0, [r1, 0x4]
	movs r0, 0x5
	bl PlaySE
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_809EDB8
	str r1, [r0]
	strh r4, [r5, 0x2]
	movs r0, 0x6
	strh r0, [r5, 0x4]
	b _0809EEF4
	.pool
_0809EEB4:
	ldrb r0, [r2]
	lsls r0, 1
	adds r0, r5, r0
	ldrh r1, [r2, 0x2]
	ldrh r2, [r2, 0x4]
	mov r3, r12
	ldrh r4, [r3, 0x30]
	movs r3, 0xC0
	ands r3, r4
	bl sub_809ED38
	cmp r0, 0
	beq _0809EEF4
	movs r0, 0x5
	bl PlaySE
	ldrb r0, [r5, 0x10]
	ldrh r3, [r5, 0x6]
	ldrb r1, [r5, 0x8]
	str r1, [sp]
	ldrb r1, [r5, 0xA]
	str r1, [sp, 0x4]
	ldrb r1, [r5, 0xC]
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0x1
	bl sub_809EBC4
	ldrb r0, [r5, 0x10]
	movs r1, 0x2
	bl CopyWindowToVram
_0809EEF4:
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809EDE8

	thumb_func_start sub_809EF00
sub_809EF00: @ 809EF00
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x4
	mov r8, r0
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r6, r0, 2
	add r6, r8
	lsls r6, 3
	ldr r0, =gTasks + 0x8
	mov r9, r0
	adds r5, r6, r0
	movs r0, 0
	strh r0, [r5]
	ldr r1, =gLocalTime
	ldrh r0, [r1]
	strh r0, [r5, 0x6]
	movs r0, 0x2
	ldrsb r0, [r1, r0]
	strh r0, [r5, 0x8]
	movs r0, 0x3
	ldrsb r0, [r1, r0]
	strh r0, [r5, 0xA]
	movs r0, 0x4
	ldrsb r0, [r1, r0]
	strh r0, [r5, 0xC]
	ldr r0, =gUnknown_08510420
	bl AddWindow
	strh r0, [r5, 0x10]
	lsls r0, 24
	lsrs r0, 24
	ldrh r1, [r5, 0x6]
	ldrb r2, [r5, 0x8]
	ldrb r3, [r5, 0xA]
	ldrb r4, [r5, 0xC]
	str r4, [sp]
	bl sub_809ECB4
	mov r0, r8
	bl sub_809EB04
	movs r0, 0x2
	strh r0, [r5, 0x4]
	movs r0, 0x8
	negs r0, r0
	add r9, r0
	add r6, r9
	ldr r0, =sub_809EDE8
	str r0, [r6]
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809EF00

	thumb_func_start CB2_InitResetRtcScreen
CB2_InitResetRtcScreen: @ 809EF88
	push {r4-r7,lr}
	sub sp, 0x4
	movs r0, 0
	movs r1, 0
	bl SetGpuReg
	movs r0, 0
	bl SetVBlankCallback
	movs r2, 0xA0
	lsls r2, 19
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =0x040000d4
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	ldr r0, =0x81000200
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r2, 0xC0
	lsls r2, 19
	movs r3, 0xC0
	lsls r3, 9
	mov r4, sp
	movs r6, 0
	movs r5, 0x80
	lsls r5, 5
	ldr r7, =0x81000800
	movs r0, 0x81
	lsls r0, 24
	mov r12, r0
_0809EFCA:
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	str r7, [r1, 0x8]
	ldr r0, [r1, 0x8]
	adds r2, r5
	subs r3, r5
	cmp r3, r5
	bhi _0809EFCA
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, 0x4]
	lsrs r0, r3, 1
	mov r2, r12
	orrs r0, r2
	str r0, [r1, 0x8]
	ldr r0, [r1, 0x8]
	movs r0, 0
	movs r1, 0x80
	bl ResetOamRange
	bl LoadOam
	bl ScanlineEffect_Stop
	bl ScanlineEffect_Clear
	bl ResetSpriteData
	bl ResetTasks
	bl ResetPaletteFade
	bl sub_809F048
	ldr r0, =sub_809F0AC
	bl SetVBlankCallback
	ldr r0, =sub_809F090
	bl SetMainCallback2
	ldr r0, =sub_809F200
	movs r1, 0x50
	bl CreateTask
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_InitResetRtcScreen

	thumb_func_start sub_809F048
sub_809F048: @ 809F048
	push {lr}
	bl clear_scheduled_bg_copies_to_vram
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_08510404
	movs r0, 0
	movs r2, 0x1
	bl InitBgsFromTemplates
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	movs r1, 0x82
	lsls r1, 5
	movs r0, 0
	bl SetGpuReg
	movs r0, 0
	bl ShowBg
	ldr r0, =gUnknown_08510408
	bl InitWindows
	bl DeactivateAllTextPrinters
	bl sub_81973A4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809F048

	thumb_func_start sub_809F090
sub_809F090: @ 809F090
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl do_scheduled_bg_tilemap_copies_to_vram
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	thumb_func_end sub_809F090

	thumb_func_start sub_809F0AC
sub_809F0AC: @ 809F0AC
	push {lr}
	bl ProcessSpriteCopyRequests
	bl LoadOam
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	thumb_func_end sub_809F0AC

	thumb_func_start sub_809F0C0
sub_809F0C0: @ 809F0C0
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	movs r2, 0x80
	lsls r2, 2
	movs r0, 0x1
	movs r1, 0
	movs r3, 0xF
	bl sub_8197B1C
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl PrintTextOnWindow
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_809F0C0

	thumb_func_start sub_809F0F8
sub_809F0F8: @ 809F0F8
	push {r4-r7,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r6, r0, r1
	movs r0, 0
	ldrsh r5, [r6, r0]
	cmp r5, 0
	beq _0809F11C
	cmp r5, 0x1
	beq _0809F1B2
	b _0809F1F8
	.pool
_0809F11C:
	movs r2, 0x85
	lsls r2, 2
	movs r0, 0
	movs r1, 0
	movs r3, 0xE
	bl SetWindowBorderStyle
	ldr r2, =gText_PresentTime
	movs r0, 0x1
	str r0, [sp]
	movs r4, 0xFF
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	ldr r1, =gLocalTime
	ldrh r3, [r1]
	ldrb r0, [r1, 0x2]
	str r0, [sp]
	ldrb r0, [r1, 0x3]
	str r0, [sp, 0x4]
	ldrb r0, [r1, 0x4]
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x11
	bl sub_809EBC4
	ldr r2, =gText_PreviousTime
	movs r0, 0x21
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	movs r0, 0
	movs r1, 0x1
	movs r3, 0
	bl PrintTextOnWindow
	ldr r0, =gSaveBlock2Ptr
	ldr r1, [r0]
	adds r0, r1, 0
	adds r0, 0xA0
	ldrh r3, [r0]
	adds r0, 0x2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r1, 0
	adds r0, 0xA3
	ldrb r0, [r0]
	str r0, [sp, 0x4]
	adds r0, r1, 0
	adds r0, 0xA4
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x31
	bl sub_809EBC4
	ldr r0, =gText_ResetRTCConfirmCancel
	bl sub_809F0C0
	movs r0, 0
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	ldrh r0, [r6]
	adds r0, 0x1
	strh r0, [r6]
_0809F1B2:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0809F1E4
	adds r0, r7, 0
	bl DestroyTask
	bl DoSoftReset
	b _0809F1F8
	.pool
_0809F1E4:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809F1F8
	movs r0, 0x5
	bl PlaySE
	adds r0, r7, 0
	bl DestroyTask
_0809F1F8:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_809F0F8

	thumb_func_start sub_809F200
sub_809F200: @ 809F200
	push {r4,r5,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0x6
	bls _0809F21C
	b _0809F404
_0809F21C:
	lsls r0, 2
	ldr r1, =_0809F230
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0809F230:
	.4byte _0809F24C
	.4byte _0809F268
	.4byte _0809F2B4
	.4byte _0809F310
	.4byte _0809F398
	.4byte _0809F3C8
	.4byte _0809F3EA
_0809F24C:
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0x1
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	movs r0, 0x1
	strh r0, [r5]
	b _0809F404
	.pool
_0809F268:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0809F276
	b _0809F404
_0809F276:
	ldr r0, =gSaveFileStatus
	ldrh r0, [r0]
	cmp r0, 0
	beq _0809F282
	cmp r0, 0x2
	bne _0809F29C
_0809F282:
	ldr r0, =gText_NoSaveFileCantSetTime
	bl sub_809F0C0
	movs r0, 0x5
	strh r0, [r5]
	b _0809F404
	.pool
_0809F29C:
	bl RtcCalcLocalTime
	ldr r0, =sub_809F0F8
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x2]
	b _0809F334
	.pool
_0809F2B4:
	ldr r2, =gTasks
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x4]
	cmp r0, 0x1
	bne _0809F2CA
	b _0809F404
_0809F2CA:
	movs r0, 0
	movs r1, 0
	bl sub_8198070
	ldr r0, =gText_PleaseResetTime
	bl sub_809F0C0
	ldr r2, =gLocalTime
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	adds r0, 0xA0
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r0, =sub_809EF00
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0x2]
	movs r0, 0x3
	strh r0, [r5]
	b _0809F404
	.pool
_0809F310:
	ldr r2, =gTasks
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r1, r0, r2
	movs r2, 0x8
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0809F404
	movs r2, 0xA
	ldrsh r0, [r1, r2]
	cmp r0, 0
	bne _0809F340
	ldrb r0, [r5, 0x2]
	bl DestroyTask
_0809F334:
	movs r0, 0x2
	strh r0, [r5]
	b _0809F404
	.pool
_0809F340:
	ldrb r0, [r5, 0x2]
	bl DestroyTask
	bl RtcReset
	ldr r4, =gLocalTime
	movs r1, 0
	ldrsh r0, [r4, r1]
	movs r1, 0x2
	ldrsb r1, [r4, r1]
	movs r2, 0x3
	ldrsb r2, [r4, r2]
	movs r3, 0x4
	ldrsb r3, [r4, r3]
	bl RtcCalcLocalTimeOffset
	ldr r0, =gSaveBlock2Ptr
	ldr r2, [r0]
	adds r2, 0xA0
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldr r0, =0x00004040
	ldrh r1, [r4]
	bl VarSet
	bl DisableResetRTC
	ldr r0, =gText_ClockHasBeenReset
	bl sub_809F0C0
	movs r0, 0x4
	strh r0, [r5]
	b _0809F404
	.pool
_0809F398:
	movs r0, 0
	bl TrySavingData
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0809F3B8
	ldr r0, =gText_SaveCompleted
	bl sub_809F0C0
	movs r0, 0x49
	bl PlaySE
	b _0809F3C4
	.pool
_0809F3B8:
	ldr r0, =gText_SaveFailed
	bl sub_809F0C0
	movs r0, 0x16
	bl PlaySE
_0809F3C4:
	movs r0, 0x5
	strh r0, [r5]
_0809F3C8:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0809F404
	movs r0, 0x1
	negs r0, r0
	ldr r1, =0x0000ffff
	str r1, [sp]
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x10
	bl BeginNormalPaletteFade
	movs r0, 0x6
	strh r0, [r5]
_0809F3EA:
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _0809F404
	adds r0, r4, 0
	bl DestroyTask
	bl FreeAllWindowBuffers
	bl DoSoftReset
_0809F404:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809F200

	thumb_func_start sub_809F41C
sub_809F41C: @ 809F41C
	push {lr}
	ldr r0, =0x00000861
	bl FlagSet
	movs r0, 0x86
	lsls r0, 4
	bl FlagSet
	ldr r0, =0x00000862
	bl FlagSet
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_809F41C

	.align 2, 0 @ Don't pad with nop.
