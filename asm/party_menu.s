	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81B5B38
sub_81B5B38: @ 81B5B38
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	movs r1, 0x39
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r6, 0
	movs r1, 0x3A
	bl GetMonData
	adds r2, r0, 0
	lsls r2, 16
	lsrs r2, 16
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81B5A8C
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81B5B38

	thumb_func_start sub_81B5B6C
sub_81B5B6C: @ 81B5B6C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	ldr r5, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r6, r0, 2
	adds r2, r6, r5
	movs r7, 0
	movs r3, 0
	strh r3, [r2, 0x2E]
	mov r12, r5
	cmp r1, 0
	bne _081B5BC4
	movs r1, 0x20
	ldrsh r0, [r2, r1]
	cmp r0, 0x10
	bne _081B5BA4
	strh r3, [r2, 0x24]
	ldr r0, =0x0000fffc
	strh r0, [r2, 0x26]
	b _081B5BAA
	.pool
_081B5BA4:
	ldr r0, =0x0000fffc
	strh r0, [r2, 0x24]
	strh r3, [r2, 0x26]
_081B5BAA:
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	mov r1, r12
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_81B5C08
	b _081B5BD0
	.pool
_081B5BC4:
	strh r3, [r2, 0x24]
	strh r3, [r2, 0x26]
	adds r0, r5, 0
	adds r0, 0x1C
	adds r0, r6, r0
	ldr r1, =sub_81B5BDC
_081B5BD0:
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B5B6C

	thumb_func_start sub_81B5BDC
sub_81B5BDC: @ 81B5BDC
	push {r4,lr}
	adds r4, r0, 0
	bl UpdateMonIconFrame
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081B5C02
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081B5C00
	ldr r0, =0x0000fffd
	strh r0, [r4, 0x26]
	b _081B5C02
	.pool
_081B5C00:
	strh r1, [r4, 0x26]
_081B5C02:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81B5BDC

	thumb_func_start sub_81B5C08
sub_81B5C08: @ 81B5C08
	push {lr}
	bl UpdateMonIconFrame
	pop {r0}
	bx r0
	thumb_func_end sub_81B5C08

	thumb_func_start party_menu_held_item_object
party_menu_held_item_object: @ 81B5C14
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _081B5C3C
	ldr r0, =gSpriteTemplate_8615EC0
	ldr r2, [r4, 0x4]
	ldrb r1, [r2, 0x2]
	ldrb r2, [r2, 0x3]
	movs r3, 0
	bl CreateSprite
	strb r0, [r4, 0xA]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81B5C94
_081B5C3C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end party_menu_held_item_object

	thumb_func_start party_menu_link_mon_held_item_object
party_menu_link_mon_held_item_object: @ 81B5C48
	push {r4,r5,lr}
	adds r4, r2, 0
	lsls r0, 16
	lsls r1, 16
	lsrs r5, r1, 16
	cmp r0, 0
	beq _081B5C84
	ldr r0, =gSpriteTemplate_8615EC0
	ldr r2, [r4, 0x4]
	ldrb r1, [r2, 0x2]
	ldrb r2, [r2, 0x3]
	movs r3, 0
	bl CreateSprite
	strb r0, [r4, 0xA]
	ldr r2, =gSprites
	ldrb r0, [r4, 0xA]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81B5CB0
_081B5C84:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end party_menu_link_mon_held_item_object

	thumb_func_start sub_81B5C94
sub_81B5C94: @ 81B5C94
	push {r4,lr}
	adds r4, r1, 0
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl sub_81B5CB0
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81B5C94

	thumb_func_start sub_81B5CB0
sub_81B5CB0: @ 81B5CB0
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _081B5CD8
	ldr r2, =gSprites
	ldrb r1, [r4, 0xA]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	b _081B5D24
	.pool
_081B5CD8:
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	beq _081B5CFC
	ldrb r1, [r4, 0xA]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x1
	bl StartSpriteAnim
	b _081B5D0E
	.pool
_081B5CFC:
	ldrb r1, [r4, 0xA]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0
	bl StartSpriteAnim
_081B5D0E:
	ldr r2, =gSprites
	ldrb r1, [r4, 0xA]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
_081B5D24:
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B5CB0

	thumb_func_start sub_81B5D30
sub_81B5D30: @ 81B5D30
	push {lr}
	ldr r0, =gUnknown_08615EB0
	bl LoadSpriteSheet
	ldr r0, =gUnknown_08615EB8
	bl LoadSpritePalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B5D30

	thumb_func_start sub_81B5D4C
sub_81B5D4C: @ 81B5D4C
	push {r4-r7,lr}
	adds r6, r0, 0
	adds r7, r1, 0
	lsls r2, 24
	lsrs r2, 24
	cmp r2, 0
	beq _081B5D60
	cmp r2, 0x1
	beq _081B5DA8
	b _081B5DE4
_081B5D60:
	movs r5, 0
	ldrb r0, [r6]
	cmp r5, r0
	bcs _081B5DE4
_081B5D68:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _081B5D94
	adds r0, r7, r5
	ldrb r4, [r0]
	adds r0, r1, 0
	bl ItemIsMail
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_81B5DF0
_081B5D94:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
	ldrb r0, [r6]
	cmp r5, r0
	bcc _081B5D68
	b _081B5DE4
	.pool
_081B5DA8:
	movs r5, 0
	b _081B5DDE
_081B5DAC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	beq _081B5DD8
	adds r0, r5, r7
	ldrb r4, [r0, 0x6]
	adds r0, r1, 0
	bl ItemIsMail
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_81B5DF0
_081B5DD8:
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_081B5DDE:
	ldrb r0, [r6, 0x1]
	cmp r5, r0
	bcc _081B5DAC
_081B5DE4:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B5D4C

	thumb_func_start sub_81B5DF0
sub_81B5DF0: @ 81B5DF0
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	adds r6, r0, 0
	mov r9, r1
	lsls r6, 24
	lsrs r6, 24
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =gSprites
	mov r8, r0
	lsls r0, r6, 4
	adds r0, r6
	lsls r0, 2
	add r0, r8
	adds r0, 0x43
	ldrb r3, [r0]
	ldr r0, =gSpriteTemplate_8615EC0
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	movs r1, 0xFA
	movs r2, 0xAA
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	mov r0, r8
	adds r5, r4, r0
	movs r0, 0x4
	strh r0, [r5, 0x24]
	movs r0, 0xA
	strh r0, [r5, 0x26]
	movs r0, 0x1C
	add r8, r0
	add r4, r8
	ldr r0, =sub_81B5E74
	str r0, [r4]
	strh r6, [r5, 0x3C]
	adds r0, r5, 0
	mov r1, r9
	bl StartSpriteAnim
	ldr r1, [r4]
	adds r0, r5, 0
	bl _call_via_r1
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B5DF0

	thumb_func_start sub_81B5E74
sub_81B5E74: @ 81B5E74
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x3C]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	adds r0, r2, 0
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _081B5EA8
	adds r0, r4, 0
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	b _081B5EC6
	.pool
_081B5EA8:
	adds r3, r4, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r3]
	ldrh r0, [r2, 0x24]
	ldrh r1, [r2, 0x20]
	adds r0, r1
	strh r0, [r4, 0x20]
	ldrh r0, [r2, 0x26]
	ldrh r2, [r2, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
_081B5EC6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81B5E74

	thumb_func_start party_menu_pokeball_object
party_menu_pokeball_object: @ 81B5ECC
	push {r4,lr}
	adds r4, r1, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _081B5EEA
	ldr r0, =gSpriteTemplate_8615F08
	ldr r2, [r4, 0x4]
	ldrb r1, [r2, 0x6]
	ldrb r2, [r2, 0x7]
	movs r3, 0x8
	bl CreateSprite
	strb r0, [r4, 0xB]
_081B5EEA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end party_menu_pokeball_object

	thumb_func_start party_menu_link_mon_pokeball_object
party_menu_link_mon_pokeball_object: @ 81B5EF4
	push {r4,lr}
	adds r4, r1, 0
	lsls r0, 16
	cmp r0, 0
	beq _081B5F24
	ldr r0, =gSpriteTemplate_8615F08
	ldr r2, [r4, 0x4]
	ldrb r1, [r2, 0x6]
	ldrb r2, [r2, 0x7]
	movs r3, 0x8
	bl CreateSprite
	strb r0, [r4, 0xB]
	ldr r2, =gSprites
	ldrb r0, [r4, 0xB]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
_081B5F24:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end party_menu_link_mon_pokeball_object

	thumb_func_start sub_81B5F34
sub_81B5F34: @ 81B5F34
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gSpriteTemplate_8615F08
	adds r1, r3, 0
	movs r3, 0x8
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r3, [r1, 0x5]
	movs r2, 0xD
	negs r2, r2
	ands r2, r3
	movs r3, 0x8
	orrs r2, r3
	strb r2, [r1, 0x5]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B5F34

	thumb_func_start sub_81B5F74
sub_81B5F74: @ 81B5F74
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	lsls r3, 24
	lsrs r3, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r0, =gSpriteTemplate_8615F78
	adds r1, r3, 0
	movs r3, 0x8
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B5F74

	thumb_func_start sub_81B5F98
sub_81B5F98: @ 81B5F98
	push {lr}
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	ldr r2, =gSprites
	adds r0, r2
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B5F98

	thumb_func_start sub_81B5FBC
sub_81B5FBC: @ 81B5FBC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	cmp r6, 0
	bne _081B6000
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	mov r8, r0
	add r4, r8
	adds r0, r4, 0
	movs r1, 0x2
	bl StartSpriteAnim
	lsls r5, r7, 4
	adds r5, r7
	lsls r5, 2
	add r5, r8
	adds r0, r5, 0
	movs r1, 0x4
	bl StartSpriteAnim
	strh r6, [r4, 0x26]
	strh r6, [r5, 0x26]
	b _081B602C
	.pool
_081B6000:
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	ldr r0, =gSprites
	mov r8, r0
	add r5, r8
	adds r0, r5, 0
	movs r1, 0x3
	bl StartSpriteAnim
	lsls r4, r7, 4
	adds r4, r7
	lsls r4, 2
	add r4, r8
	adds r0, r4, 0
	movs r1, 0x5
	bl StartSpriteAnim
	ldr r0, =0x0000fffc
	strh r0, [r5, 0x26]
	movs r0, 0x4
	strh r0, [r4, 0x26]
_081B602C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B5FBC

	thumb_func_start sub_81B6040
sub_81B6040: @ 81B6040
	push {lr}
	ldr r0, =gUnknown_08615EF8
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08615F70
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08615F00
	bl LoadCompressedObjectPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6040

	thumb_func_start party_menu_status_condition_object
party_menu_status_condition_object: @ 81B6064
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _081B608C
	ldr r0, =gSpriteTemplate_8616008
	ldr r2, [r4, 0x4]
	ldrb r1, [r2, 0x4]
	ldrb r2, [r2, 0x5]
	movs r3, 0
	bl CreateSprite
	strb r0, [r4, 0xC]
	adds r0, r5, 0
	adds r1, r4, 0
	bl party_menu_get_status_condition_and_update_object
_081B608C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end party_menu_status_condition_object

	thumb_func_start party_menu_link_mon_status_condition_object
party_menu_link_mon_status_condition_object: @ 81B6098
	push {r4,r5,lr}
	adds r4, r2, 0
	lsls r0, 16
	lsls r1, 24
	lsrs r5, r1, 24
	cmp r0, 0
	beq _081B60D4
	ldr r0, =gSpriteTemplate_8616008
	ldr r2, [r4, 0x4]
	ldrb r1, [r2, 0x4]
	ldrb r2, [r2, 0x5]
	movs r3, 0
	bl CreateSprite
	strb r0, [r4, 0xC]
	adds r0, r5, 0
	adds r1, r4, 0
	bl party_menu_update_status_condition_object
	ldr r2, =gSprites
	ldrb r0, [r4, 0xC]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x5]
_081B60D4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end party_menu_link_mon_status_condition_object

	thumb_func_start party_menu_get_status_condition_and_update_object
@ void party_menu_get_status_condition_and_update_object(struct pokemon *mon, void *a2, void *a3)
party_menu_get_status_condition_and_update_object: @ 81B60E4
	push {r4,lr}
	adds r4, r1, 0
	bl sub_81B205C
	lsls r0, 24
	lsrs r0, 24
	adds r1, r4, 0
	bl party_menu_update_status_condition_object
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end party_menu_get_status_condition_and_update_object

	thumb_func_start party_menu_update_status_condition_object
@ void party_menu_update_status_condition_object(u8 a1, void *a2)
party_menu_update_status_condition_object: @ 81B60FC
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0
	beq _081B610C
	cmp r2, 0x6
	bne _081B6128
_081B610C:
	ldr r2, =gSprites
	ldrb r1, [r5, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	b _081B6152
	.pool
_081B6128:
	ldrb r1, [r5, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r4, =gSprites
	adds r0, r4
	subs r1, r2, 0x1
	lsls r1, 24
	lsrs r1, 24
	bl StartSpriteAnim
	ldrb r1, [r5, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
_081B6152:
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end party_menu_update_status_condition_object

	thumb_func_start sub_81B6160
sub_81B6160: @ 81B6160
	push {lr}
	ldr r0, =gUnknown_08615FF8
	bl LoadCompressedObjectPic
	ldr r0, =gUnknown_08616000
	bl LoadCompressedObjectPalette
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6160

	thumb_func_start sub_81B617C
sub_81B617C: @ 81B617C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	ldr r0, =c2_815ABFC
	mov r8, r0
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081B61BC
	movs r7, 0x1
	bl sub_81B8984
	lsls r0, 24
	lsrs r6, r0, 24
	b _081B61C0
	.pool
_081B61B0:
	ldr r0, =gUnknown_0203CEC8
	strb r5, [r0, 0x9]
	b _081B6204
	.pool
_081B61BC:
	movs r7, 0
	movs r6, 0
_081B61C0:
	ldr r4, =gSpecialVar_ItemId
	ldrh r0, [r4]
	bl GetItemEffectType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xA
	bne _081B621C
	ldr r1, =gUnknown_0203CEC8
	movs r0, 0
	strb r0, [r1, 0x9]
	movs r5, 0
_081B61D8:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _081B61FA
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _081B61B0
_081B61FA:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x5
	bls _081B61D8
_081B6204:
	ldr r0, =sub_81B6280
	movs r1, 0x7F
	b _081B6230
	.pool
_081B621C:
	ldrh r0, [r4]
	bl GetPocketByItemId
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x5
	cmp r0, 0x3
	bne _081B622E
	movs r1, 0x4
_081B622E:
	ldr r0, =sub_81B1370
_081B6230:
	str r1, [sp]
	str r0, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	adds r0, r7, 0
	adds r1, r6, 0
	movs r2, 0x3
	movs r3, 0x1
	bl sub_81B0038
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B617C

	thumb_func_start c2_815ABFC
c2_815ABFC: @ 81B6254
	push {lr}
	bl InBattlePyramid
	lsls r0, 24
	cmp r0, 0
	bne _081B626C
	movs r0, 0xC
	movs r1, 0x5
	movs r2, 0
	bl GoToBagMenu
	b _081B6276
_081B626C:
	ldr r0, =gPyramidBagCursorData
	ldr r1, [r0]
	movs r0, 0x4
	bl sub_81C4F98
_081B6276:
	pop {r0}
	bx r0
	.pool
	thumb_func_end c2_815ABFC

	thumb_func_start sub_81B6280
sub_81B6280: @ 81B6280
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081B62B2
	ldr r0, =gUnknown_0203CEC8
	ldrb r1, [r0, 0x8]
	movs r0, 0xF
	ands r0, r1
	cmp r0, 0x1
	bne _081B62A6
	ldr r0, =gUnknown_0203CEC4
	ldr r1, [r0]
	ldr r0, =sub_81B9140
	str r0, [r1, 0x4]
_081B62A6:
	ldr r0, =gUnknown_03006328
	ldr r1, =sub_81B6794
	ldr r2, [r0]
	adds r0, r3, 0
	bl _call_via_r2
_081B62B2:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6280

	thumb_func_start IsHPRecoveryItem
@ bool8 IsHPRecoveryItem(u16 itemId)
IsHPRecoveryItem: @ 81B62D0
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xAF
	bne _081B62EC
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003214
	adds r0, r1
	b _081B62F6
	.pool
_081B62EC:
	ldr r1, =gItemEffectTable
	subs r0, 0xD
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
_081B62F6:
	ldrb r1, [r0, 0x4]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _081B6308
	movs r0, 0
	b _081B630A
	.pool
_081B6308:
	movs r0, 0x1
_081B630A:
	pop {r1}
	bx r1
	thumb_func_end IsHPRecoveryItem

	thumb_func_start GetMedicineItemEffectMessage
@ void GetMedicineItemEffectMessage(u16 itemId)
GetMedicineItemEffectMessage: @ 81B6310
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl GetItemEffectType
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0x3
	cmp r0, 0x12
	bls _081B6326
	b _081B64BC
_081B6326:
	lsls r0, 2
	ldr r1, =_081B6334
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081B6334:
	.4byte _081B6380
	.4byte _081B6394
	.4byte _081B63A8
	.4byte _081B63BC
	.4byte _081B63D0
	.4byte _081B63E4
	.4byte _081B63F8
	.4byte _081B64BC
	.4byte _081B640C
	.4byte _081B6430
	.4byte _081B6420
	.4byte _081B6460
	.4byte _081B6470
	.4byte _081B6450
	.4byte _081B6440
	.4byte _081B64BC
	.4byte _081B6494
	.4byte _081B6494
	.4byte _081B64A8
_081B6380:
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnCuredOfPoison
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B6394:
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnWokeUp2
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B63A8:
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnBurnHealed
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B63BC:
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnThawedOut
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B63D0:
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnCuredOfParalysis
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B63E4:
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnSnappedOutOfConfusion
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B63F8:
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnGotOverInfatuation
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B640C:
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnBecameHealthy
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B6420:
	ldr r0, =gStringVar2
	ldr r1, =gText_HP3
	b _081B6474
	.pool
_081B6430:
	ldr r0, =gStringVar2
	ldr r1, =gText_Attack3
	b _081B6474
	.pool
_081B6440:
	ldr r0, =gStringVar2
	ldr r1, =gText_Defense3
	b _081B6474
	.pool
_081B6450:
	ldr r0, =gStringVar2
	ldr r1, =gText_Speed2
	b _081B6474
	.pool
_081B6460:
	ldr r0, =gStringVar2
	ldr r1, =gText_SpAtk3
	b _081B6474
	.pool
_081B6470:
	ldr r0, =gStringVar2
	ldr r1, =gText_SpDef3
_081B6474:
	bl StringCopy
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnBaseVar2StatIncreased
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B6494:
	ldr r0, =gStringVar4
	ldr r1, =gText_MovesPPIncreased
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B64A8:
	ldr r0, =gStringVar4
	ldr r1, =gText_PPWasRestored
	bl StringExpandPlaceholders
	b _081B64C4
	.pool
_081B64BC:
	ldr r0, =gStringVar4
	ldr r1, =gText_WontHaveEffect
	bl StringExpandPlaceholders
_081B64C4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end GetMedicineItemEffectMessage

	thumb_func_start UsingHPEVItemOnShedinja
@ bool8 UsingHPEVItemOnShedinja(struct pokemon *mon, u16 itemId)
UsingHPEVItemOnShedinja: @ 81B64D0
	push {r4,lr}
	adds r4, r0, 0
	lsls r0, r1, 16
	lsrs r0, 16
	bl GetItemEffectType
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xD
	bne _081B64FC
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	ldr r1, =0x0000012f
	cmp r0, r1
	bne _081B64FC
	movs r0, 0
	b _081B64FE
	.pool
_081B64FC:
	movs r0, 0x1
_081B64FE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end UsingHPEVItemOnShedinja

	thumb_func_start IsBlueYellowRedFlute
@ bool8 IsBlueYellowRedFlute(u16 itemId)
IsBlueYellowRedFlute: @ 81B6504
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x27
	beq _081B6516
	cmp r0, 0x29
	beq _081B6516
	cmp r0, 0x28
	bne _081B651A
_081B6516:
	movs r0, 0x1
	b _081B651C
_081B651A:
	movs r0, 0
_081B651C:
	pop {r1}
	bx r1
	thumb_func_end IsBlueYellowRedFlute

	thumb_func_start ExecuteTableBasedItemEffect__
@ bool8 ExecuteTableBasedItemEffect__(u8 partyMonIndex, u16 itemId, u8 monMoveIndex)
ExecuteTableBasedItemEffect__: @ 81B6520
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 16
	lsrs r5, r1, 16
	lsls r2, 24
	lsrs r6, r2, 24
	ldr r0, =gMain
	ldr r1, =0x00000439
	adds r0, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081B6558
	movs r0, 0x64
	muls r0, r3
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r5, 0
	adds r2, r3, 0
	b _081B6572
	.pool
_081B6558:
	movs r0, 0x64
	adds r4, r3, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r3, 0
	bl sub_81B8F38
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
_081B6572:
	adds r3, r6, 0
	bl ExecuteTableBasedItemEffect
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ExecuteTableBasedItemEffect__

	thumb_func_start ItemUseCB_Medicine
ItemUseCB_Medicine: @ 81B6588
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	str r1, [sp, 0x4]
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	movs r0, 0
	mov r10, r0
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	ldr r0, =gSpecialVar_ItemId
	ldrh r6, [r0]
	adds r0, r5, 0
	adds r1, r6, 0
	bl UsingHPEVItemOnShedinja
	lsls r0, 24
	cmp r0, 0
	beq _081B6600
	adds r0, r6, 0
	bl IsHPRecoveryItem
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x1
	bne _081B65EE
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	adds r0, r5, 0
	movs r1, 0x3A
	bl GetMonData
	cmp r10, r0
	bne _081B65EE
	movs r1, 0
	mov r8, r1
_081B65EE:
	ldr r4, =gUnknown_0203CEC8
	ldrb r0, [r4, 0x9]
	adds r1, r6, 0
	movs r2, 0
	bl ExecuteTableBasedItemEffect__
	lsls r0, 24
	cmp r0, 0
	beq _081B6624
_081B6600:
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gText_WontHaveEffect
	b _081B66F4
	.pool
_081B6624:
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0x1
	strb r0, [r1]
	adds r0, r6, 0
	bl IsBlueYellowRedFlute
	lsls r0, 24
	cmp r0, 0
	bne _081B6650
	movs r0, 0x1
	bl PlaySE
	ldrb r0, [r4, 0xB]
	cmp r0, 0xE
	beq _081B6656
	adds r0, r6, 0
	movs r1, 0x1
	bl RemoveBagItem
	b _081B6656
	.pool
_081B6650:
	movs r0, 0x75
	bl PlaySE
_081B6656:
	ldr r4, =gUnknown_0203CEDC
	ldr r7, =gUnknown_0203CEC8
	movs r0, 0x9
	ldrsb r0, [r7, r0]
	lsls r0, 4
	ldr r1, [r4]
	adds r1, r0
	adds r0, r5, 0
	bl party_menu_get_status_condition_and_update_object
	ldr r2, =gSprites
	movs r0, 0x9
	ldrsb r0, [r7, r0]
	ldr r1, [r4]
	lsls r0, 4
	adds r3, r0, r1
	ldrb r1, [r3, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _081B6694
	adds r0, r5, 0
	adds r1, r3, 0
	movs r2, 0x1
	bl sub_81B2AC8
_081B6694:
	mov r2, r8
	cmp r2, 0x1
	bne _081B66E4
	mov r0, r10
	cmp r0, 0
	bne _081B66A8
	ldrb r0, [r7, 0x9]
	movs r1, 0x1
	bl sub_81B0FCC
_081B66A8:
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	adds r3, r0, 0
	mov r1, r10
	subs r3, r1
	lsls r3, 16
	asrs r3, 16
	ldrb r1, [r7, 0x9]
	ldr r0, =sub_81B672C
	str r0, [sp]
	mov r0, r9
	movs r2, 0x1
	bl sub_81B1F18
	mov r0, r9
	movs r1, 0
	mov r2, r10
	bl sub_81B1FA8
	b _081B6710
	.pool
_081B66E4:
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetMonNickname
	adds r0, r6, 0
	bl GetMedicineItemEffectMessage
	ldr r0, =gStringVar4
_081B66F4:
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	mov r2, r9
	lsls r0, r2, 2
	add r0, r9
	lsls r0, 3
	adds r0, r1
	ldr r1, [sp, 0x4]
	str r1, [r0]
_081B6710:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ItemUseCB_Medicine

	thumb_func_start sub_81B672C
sub_81B672C: @ 81B672C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0x9
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
	bl HandleBattleLowHpMusicChange
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6794
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B672C

	thumb_func_start sub_81B6794
sub_81B6794: @ 81B6794
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B67BA
	ldr r0, =gUnknown_0203CEE8
	ldrb r1, [r0]
	cmp r1, 0
	bne _081B67B4
	ldr r0, =gUnknown_0203CEC4
	ldr r0, [r0]
	str r1, [r0, 0x4]
_081B67B4:
	adds r0, r4, 0
	bl sub_81B12C0
_081B67BA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6794

	thumb_func_start sub_81B67C8
sub_81B67C8: @ 81B67C8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	str r1, [sp]
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	ldr r4, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r4, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	ldr r0, =gSpecialVar_ItemId
	ldrh r6, [r0]
	adds r0, r6, 0
	bl GetItemEffectType
	lsls r0, 24
	lsrs r7, r0, 24
	adds r0, r5, 0
	movs r1, 0x20
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x4]
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_81B691C
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	ldrb r0, [r4, 0x9]
	adds r1, r6, 0
	movs r2, 0
	bl ExecuteTableBasedItemEffect__
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	movs r1, 0x20
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	adds r0, r5, 0
	adds r1, r7, 0
	bl sub_81B691C
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r4, 0
	bne _081B6850
	ldr r0, [sp, 0x4]
	cmp r0, r9
	bne _081B6874
	ldr r1, [sp, 0x8]
	cmp r1, r8
	bne _081B6874
_081B6850:
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gText_WontHaveEffect
	b _081B68E2
	.pool
_081B6874:
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0x1
	bl PlaySE
	adds r0, r6, 0
	movs r1, 0x1
	bl RemoveBagItem
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetMonNickname
	ldr r1, =gStringVar2
	adds r0, r7, 0
	bl option_menu_get_string
	ldr r2, [sp, 0x4]
	cmp r2, r9
	beq _081B68D8
	ldr r0, [sp, 0x8]
	cmp r0, r8
	beq _081B68C4
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnFriendlyBaseVar2Fell
	bl StringExpandPlaceholders
	b _081B68E0
	.pool
_081B68C4:
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnFriendlyBaseVar2CantFall
	bl StringExpandPlaceholders
	b _081B68E0
	.pool
_081B68D8:
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnAdoresBaseVar2Fell
	bl StringExpandPlaceholders
_081B68E0:
	ldr r0, =gStringVar4
_081B68E2:
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	mov r2, r10
	lsls r0, r2, 2
	add r0, r10
	lsls r0, 3
	adds r0, r1
	ldr r1, [sp]
	str r1, [r0]
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B67C8

	thumb_func_start sub_81B691C
sub_81B691C: @ 81B691C
	push {r4,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r1, 0
	subs r0, 0xC
	cmp r0, 0x5
	bhi _081B6992
	lsls r0, 2
	ldr r1, =_081B693C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081B693C:
	.4byte _081B696C
	.4byte _081B6954
	.4byte _081B697E
	.4byte _081B6984
	.4byte _081B6978
	.4byte _081B6972
_081B6954:
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	ldr r1, =0x0000012f
	cmp r0, r1
	beq _081B6992
	adds r0, r4, 0
	movs r1, 0x1A
	b _081B6988
	.pool
_081B696C:
	adds r0, r4, 0
	movs r1, 0x1B
	b _081B6988
_081B6972:
	adds r0, r4, 0
	movs r1, 0x1C
	b _081B6988
_081B6978:
	adds r0, r4, 0
	movs r1, 0x1D
	b _081B6988
_081B697E:
	adds r0, r4, 0
	movs r1, 0x1E
	b _081B6988
_081B6984:
	adds r0, r4, 0
	movs r1, 0x1F
_081B6988:
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	b _081B6994
_081B6992:
	movs r0, 0
_081B6994:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81B691C

	thumb_func_start option_menu_get_string
option_menu_get_string: @ 81B699C
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	subs r0, 0xC
	cmp r0, 0x5
	bhi _081B6A08
	lsls r0, 2
	ldr r1, =_081B69B8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081B69B8:
	.4byte _081B69D8
	.4byte _081B69D0
	.4byte _081B69F0
	.4byte _081B6A00
	.4byte _081B69E8
	.4byte _081B69E0
_081B69D0:
	ldr r1, =gText_HP3
	b _081B69F2
	.pool
_081B69D8:
	ldr r1, =gText_Attack3
	b _081B69F2
	.pool
_081B69E0:
	ldr r1, =gText_Defense3
	b _081B69F2
	.pool
_081B69E8:
	ldr r1, =gText_Speed2
	b _081B69F2
	.pool
_081B69F0:
	ldr r1, =gText_SpAtk3
_081B69F2:
	adds r0, r2, 0
	bl StringCopy
	b _081B6A08
	.pool
_081B6A00:
	ldr r1, =gText_SpDef3
	adds r0, r2, 0
	bl StringCopy
_081B6A08:
	pop {r0}
	bx r0
	.pool
	thumb_func_end option_menu_get_string

	thumb_func_start sub_81B6A10
sub_81B6A10: @ 81B6A10
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r7, 0
	movs r0, 0x1
	mov r10, r0
	movs r0, 0x3
	bl sub_81B31B0
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	movs r0, 0x64
	adds r1, r4, 0
	muls r1, r0
	mov r8, r1
	ldr r0, =gPlayerParty
	mov r9, r0
_081B6A40:
	adds r1, r5, 0
	adds r1, 0xD
	mov r0, r8
	add r0, r9
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0xD
	adds r2, r4, 0
	muls r2, r0
	ldr r0, =gMoveNames
	adds r2, r0
	lsls r0, r5, 4
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	adds r0, r6, 0
	mov r1, r10
	movs r3, 0x8
	bl AddTextPrinterParameterized
	cmp r4, 0
	beq _081B6A82
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
_081B6A82:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _081B6A40
	adds r0, r6, 0
	adds r1, r7, 0
	movs r2, 0
	bl InitMenuInUpperLeftCornerPlaySoundWhenAPressed
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6A10

	thumb_func_start ether_effect_related_3
ether_effect_related_3: @ 81B6AB4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	bl Menu_ProcessInput
	lsls r0, 24
	asrs r1, r0, 24
	movs r0, 0x2
	negs r0, r0
	cmp r1, r0
	beq _081B6AF0
	adds r0, 0x1
	cmp r1, r0
	bne _081B6AE0
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81B6BB4
	b _081B6AF0
_081B6AE0:
	ldr r0, =gUnknown_0203CEC4
	ldr r0, [r0]
	adds r0, 0xD
	bl sub_81B302C
	adds r0, r5, 0
	bl ether_effect_related_2
_081B6AF0:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ether_effect_related_3

	thumb_func_start dp05_ether
dp05_ether: @ 81B6AFC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	cmp r0, 0xAF
	bne _081B6B20
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003214
	adds r0, r1
	b _081B6B2A
	.pool
_081B6B20:
	ldr r1, =gItemEffectTable
	subs r0, 0xD
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
_081B6B2A:
	ldrb r1, [r0, 0x4]
	movs r0, 0x10
	ands r0, r1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0
	bne _081B6B4C
	ldr r0, =gUnknown_0203CEC8
	strh r1, [r0, 0xE]
	adds r0, r4, 0
	bl ether_effect_related
	b _081B6B6E
	.pool
_081B6B4C:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x16
	bl display_pokemon_menu_message
	ldr r0, =gUnknown_0203CEC8
	ldrb r0, [r0, 0x9]
	bl sub_81B6A10
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =ether_effect_related_3
	str r1, [r0]
_081B6B6E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp05_ether

	thumb_func_start ether_effect_related_2
ether_effect_related_2: @ 81B6B80
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gUnknown_0203CEC4
	ldr r0, [r0]
	adds r0, 0xC
	bl sub_81B302C
	bl GetMenuCursorPos
	ldr r1, =gUnknown_0203CEC8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0xE]
	adds r0, r4, 0
	bl ether_effect_related
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ether_effect_related_2

	thumb_func_start sub_81B6BB4
sub_81B6BB4: @ 81B6BB4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =sub_81B1370
	str r0, [r1]
	ldr r0, =gUnknown_0203CEC4
	ldr r0, [r0]
	movs r1, 0
	str r1, [r0, 0x4]
	adds r0, 0xC
	bl sub_81B302C
	movs r0, 0x5
	bl display_pokemon_menu_message
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6BB4

	thumb_func_start ether_effect_related
ether_effect_related: @ 81B6BEC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r4, 0
	ldr r7, =gUnknown_0203CED6
	ldr r0, =gSpecialVar_ItemId
	ldrh r5, [r0]
	movs r0, 0xE
	negs r0, r0
	adds r0, r7
	mov r8, r0
	ldrb r0, [r0, 0x9]
	ldrb r2, [r7]
	adds r1, r5, 0
	bl ExecuteTableBasedItemEffect__
	lsls r0, 24
	cmp r0, 0
	beq _081B6C34
	ldr r0, =gUnknown_0203CEE8
	strb r4, [r0]
	movs r0, 0x5
	bl PlaySE
	ldr r0, =gText_WontHaveEffect
	b _081B6C7E
	.pool
_081B6C34:
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0x1
	strb r0, [r1]
	mov r0, r8
	movs r1, 0x9
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	movs r0, 0x1
	bl PlaySE
	adds r0, r5, 0
	movs r1, 0x1
	bl RemoveBagItem
	movs r0, 0
	ldrsh r1, [r7, r0]
	adds r1, 0xD
	adds r0, r4, 0
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gStringVar1
	movs r1, 0xD
	muls r1, r4
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	adds r0, r5, 0
	bl GetMedicineItemEffectMessage
	ldr r0, =gStringVar4
_081B6C7E:
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6794
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ether_effect_related

	thumb_func_start dp05_pp_up
dp05_pp_up: @ 81B6CC0
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x5
	bl PlaySE
	movs r0, 0x17
	bl display_pokemon_menu_message
	ldr r0, =gUnknown_0203CEC8
	ldrb r0, [r0, 0x9]
	bl sub_81B6A10
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =ether_effect_related_3
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp05_pp_up

	thumb_func_start ItemIdToBattleMoveId
ItemIdToBattleMoveId: @ 81B6CFC
	lsls r0, 16
	ldr r1, =0xfedf0000
	adds r0, r1
	ldr r1, =gUnknown_08616040
	lsrs r0, 15
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end ItemIdToBattleMoveId

	thumb_func_start sub_81B6D14
sub_81B6D14: @ 81B6D14
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0
	ldr r3, =gUnknown_08616040
_081B6D1E:
	adds r0, r1, 0
	adds r0, 0x32
	lsls r0, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _081B6D34
	movs r0, 0x1
	b _081B6D40
	.pool
_081B6D34:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x7
	bls _081B6D1E
	movs r0, 0
_081B6D40:
	pop {r1}
	bx r1
	thumb_func_end sub_81B6D14

	thumb_func_start pokemon_has_move
pokemon_has_move: @ 81B6D44
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	movs r4, 0
_081B6D4E:
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r6, 0
	bl GetMonData
	cmp r0, r5
	bne _081B6D60
	movs r0, 0x1
	b _081B6D6C
_081B6D60:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081B6D4E
	movs r0, 0
_081B6D6C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end pokemon_has_move

	thumb_func_start sub_81B6D74
sub_81B6D74: @ 81B6D74
	push {r4,lr}
	adds r1, r0, 0
	ldr r4, =gStringVar4
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6D74

	thumb_func_start sub_81B6D98
sub_81B6D98: @ 81B6D98
	push {r4,lr}
	adds r4, r0, 0
	adds r0, r1, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81B6D74
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6794
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6D98

	thumb_func_start sub_81B6DC4
sub_81B6DC4: @ 81B6DC4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0x5
	bl PlaySE
	ldr r7, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r7, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	movs r0, 0xE
	adds r0, r7
	mov r8, r0
	ldr r0, =gSpecialVar_ItemId
	ldrh r4, [r0]
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetMonNickname
	adds r0, r4, 0
	bl ItemIdToBattleMoveId
	strh r0, [r7, 0xE]
	ldr r0, =gStringVar2
	movs r1, 0xE
	ldrsh r2, [r7, r1]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	movs r0, 0
	mov r1, r8
	strh r0, [r1, 0x2]
	adds r0, r5, 0
	adds r1, r4, 0
	movs r2, 0
	bl sub_81B22D8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B6E70
	cmp r0, 0x2
	beq _081B6E78
	ldrh r1, [r7, 0xE]
	adds r0, r5, 0
	bl GiveMoveToMon
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	beq _081B6E88
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B6EB4
	str r0, [r1]
	b _081B6E9C
	.pool
_081B6E70:
	ldr r1, =gText_PkmnCantLearnMove
	b _081B6E7A
	.pool
_081B6E78:
	ldr r1, =gText_PkmnAlreadyKnows
_081B6E7A:
	adds r0, r6, 0
	bl sub_81B6D98
	b _081B6E9C
	.pool
_081B6E88:
	ldr r0, =gText_PkmnNeedsToReplaceMove
	bl sub_81B6D74
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6FF4
	str r1, [r0]
_081B6E9C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6DC4

	thumb_func_start sub_81B6EB4
sub_81B6EB4: @ 81B6EB4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r2, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r2, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	adds r6, r2, 0
	adds r6, 0xE
	ldr r0, =gSpecialVar_ItemId
	ldrh r4, [r0]
	movs r1, 0x2
	ldrsh r0, [r6, r1]
	cmp r0, 0
	bne _081B6EF0
	adds r0, r5, 0
	movs r1, 0x4
	bl AdjustFriendship
	movs r0, 0xA9
	lsls r0, 1
	cmp r4, r0
	bhi _081B6EF0
	adds r0, r4, 0
	movs r1, 0x1
	bl RemoveBagItem
_081B6EF0:
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetMonNickname
	ldr r0, =gStringVar2
	movs r1, 0
	ldrsh r2, [r6, r1]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_PkmnLearnedMove3
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6F60
	str r1, [r0]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6EB4

	thumb_func_start sub_81B6F60
sub_81B6F60: @ 81B6F60
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B6F86
	ldr r0, =0x0000016f
	bl PlayFanfare
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6F98
	str r1, [r0]
_081B6F86:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6F60

	thumb_func_start sub_81B6F98
sub_81B6F98: @ 81B6F98
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _081B6FEA
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r2, 0x1
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _081B6FC0
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081B6FEA
_081B6FC0:
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0x10
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	bne _081B6FDC
	adds r0, r4, 0
	bl sub_81B77AC
	b _081B6FEA
	.pool
_081B6FDC:
	cmp r0, 0x2
	bne _081B6FE4
	ldr r0, =gSpecialVar_Result
	strh r2, [r0]
_081B6FE4:
	adds r0, r5, 0
	bl sub_81B12C0
_081B6FEA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6F98

	thumb_func_start sub_81B6FF4
sub_81B6FF4: @ 81B6FF4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B7018
	bl sub_81B334C
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B7028
	str r0, [r1]
_081B7018:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B6FF4

	thumb_func_start sub_81B7028
sub_81B7028: @ 81B7028
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _081B704E
	cmp r1, 0
	bgt _081B7048
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _081B7074
	b _081B7080
_081B7048:
	cmp r1, 0x1
	beq _081B707A
	b _081B7080
_081B704E:
	ldr r0, =gText_WhichMoveToForget
	movs r1, 0x1
	bl sub_81B1B5C
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B7088
	str r1, [r0]
	b _081B7080
	.pool
_081B7074:
	movs r0, 0x5
	bl PlaySE
_081B707A:
	adds r0, r4, 0
	bl sub_81B7230
_081B7080:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81B7028

	thumb_func_start sub_81B7088
sub_81B7088: @ 81B7088
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B70A8
	ldr r0, =gUnknown_0203CEC4
	ldr r1, [r0]
	ldr r0, =sub_81B70B8
	str r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_81B12C0
_081B70A8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7088

	thumb_func_start sub_81B70B8
sub_81B70B8: @ 81B70B8
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gPlayerParty
	ldr r4, =gUnknown_0203CEC8
	ldrb r1, [r4, 0x9]
	ldr r2, =gPlayerPartyCount
	ldrb r2, [r2]
	subs r2, 0x1
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =sub_81B70F0
	ldrh r4, [r4, 0xE]
	str r4, [sp]
	bl ShowSelectMovePokemonSummaryScreen
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B70B8

	thumb_func_start sub_81B70F0
sub_81B70F0: @ 81B70F0
	push {lr}
	sub sp, 0xC
	movs r0, 0x7F
	str r0, [sp]
	ldr r0, =sub_81B711C
	str r0, [sp, 0x4]
	ldr r0, =gUnknown_0203CEC8
	ldr r0, [r0]
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B70F0

	thumb_func_start sub_81B711C
sub_81B711C: @ 81B711C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081B714E
	bl sub_81C1B94
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	beq _081B7148
	adds r0, r4, 0
	bl sub_81B7154
	b _081B714E
	.pool
_081B7148:
	adds r0, r5, 0
	bl sub_81B7230
_081B714E:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81B711C

	thumb_func_start sub_81B7154
sub_81B7154: @ 81B7154
	push {r4-r6,lr}
	adds r6, r0, 0
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	adds r5, r1, 0
	muls r5, r0
	ldr r0, =gPlayerParty
	adds r5, r0
	bl sub_81C1B94
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r1, 0xD
	adds r0, r5, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetMonNickname
	ldr r0, =gStringVar2
	movs r1, 0xD
	muls r1, r4
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gText_12PoofForgotMove
	bl sub_81B6D74
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B71D4
	str r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7154

	thumb_func_start sub_81B71D4
sub_81B71D4: @ 81B71D4
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B7220
	ldr r5, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r5, r1]
	movs r0, 0x64
	adds r4, r1, 0
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	bl sub_81C1B94
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl RemoveMonPPBonus
	ldrh r5, [r5, 0xE]
	bl sub_81C1B94
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl SetMonMoveSlot
	adds r0, r6, 0
	bl sub_81B6EB4
_081B7220:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B71D4

	thumb_func_start sub_81B7230
sub_81B7230: @ 81B7230
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gStringVar2
	ldr r1, =gUnknown_0203CEC8
	movs r3, 0xE
	ldrsh r2, [r1, r3]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_StopLearningMove2
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B7294
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7230

	thumb_func_start sub_81B7294
sub_81B7294: @ 81B7294
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B72B8
	bl sub_81B334C
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B72C8
	str r0, [r1]
_081B72B8:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7294

	thumb_func_start sub_81B72C8
sub_81B72C8: @ 81B72C8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r7, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r7, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r5, r0, 24
	cmp r5, 0
	beq _081B7306
	cmp r5, 0
	bgt _081B7300
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _081B738C
	b _081B73C2
	.pool
_081B7300:
	cmp r5, 0x1
	beq _081B7392
	b _081B73C2
_081B7306:
	ldr r1, =gStringVar1
	adds r0, r4, 0
	bl GetMonNickname
	ldr r0, =gStringVar2
	movs r1, 0xE
	ldrsh r2, [r7, r1]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_MoveNotLearned
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81B1B5C
	movs r3, 0x10
	ldrsh r0, [r7, r3]
	cmp r0, 0x1
	bne _081B7368
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B73E4
	str r0, [r1]
	b _081B73C2
	.pool
_081B7368:
	cmp r0, 0x2
	bne _081B7370
	ldr r0, =gSpecialVar_Result
	strh r5, [r0]
_081B7370:
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B6794
	str r0, [r1]
	b _081B73C2
	.pool
_081B738C:
	movs r0, 0x5
	bl PlaySE
_081B7392:
	ldr r1, =gStringVar1
	adds r0, r4, 0
	bl GetMonNickname
	ldr r0, =gStringVar2
	ldr r1, =gUnknown_0203CEC8
	movs r3, 0xE
	ldrsh r2, [r1, r3]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r0, =gText_PkmnNeedsToReplaceMove
	bl sub_81B6D74
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6FF4
	str r1, [r0]
_081B73C2:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B72C8

	thumb_func_start sub_81B73E4
sub_81B73E4: @ 81B73E4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B73FC
	adds r0, r4, 0
	bl sub_81B77AC
_081B73FC:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81B73E4

	thumb_func_start dp05_rare_candy
dp05_rare_candy: @ 81B7404
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r1
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_0203CEC8
	mov r9, r0
	movs r1, 0x9
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	ldr r0, =gUnknown_0203CEC4
	ldr r6, [r0]
	movs r1, 0x86
	lsls r1, 2
	adds r4, r6, r1
	ldr r2, =gSpecialVar_ItemId
	mov r8, r2
	adds r0, r5, 0
	movs r1, 0x38
	bl GetMonData
	cmp r0, 0x64
	beq _081B7478
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_81B79A0
	mov r1, r9
	ldrb r0, [r1, 0x9]
	mov r2, r8
	ldrh r1, [r2]
	movs r2, 0
	bl ExecuteTableBasedItemEffect__
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x89
	lsls r0, 2
	adds r1, r6, r0
	adds r0, r5, 0
	bl sub_81B79A0
	b _081B747A
	.pool
_081B7478:
	movs r4, 0x1
_081B747A:
	movs r0, 0x5
	bl PlaySE
	cmp r4, 0
	beq _081B74B4
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gText_WontHaveEffect
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	mov r1, r10
	b _081B7516
	.pool
_081B74B4:
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0
	bl PlayFanfareByFanfareNum
	ldr r0, =gUnknown_0203CEC8
	ldrb r0, [r0, 0x9]
	adds r1, r5, 0
	bl sub_81B754C
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	movs r1, 0x1
	bl RemoveBagItem
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetMonNickname
	ldr r4, =gStringVar2
	adds r0, r5, 0
	movs r1, 0x38
	bl GetMonData
	adds r1, r0, 0
	adds r0, r4, 0
	movs r2, 0
	movs r3, 0x3
	bl ConvertIntToDecimalStringN
	ldr r4, =gStringVar4
	ldr r1, =gText_PkmnElevatedToLvVar2
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B75D4
_081B7516:
	str r1, [r0]
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end dp05_rare_candy

	thumb_func_start sub_81B754C
sub_81B754C: @ 81B754C
	push {r4-r7,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r0, 24
	adds r7, r0, 0
	ldr r6, =gUnknown_0203CEDC
	lsls r4, r7, 4
	ldr r1, [r6]
	adds r1, r4
	adds r0, r5, 0
	bl party_menu_get_status_condition_and_update_object
	ldr r2, =gSprites
	ldr r0, [r6]
	adds r3, r4, r0
	ldrb r1, [r3, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _081B7588
	adds r0, r5, 0
	adds r1, r3, 0
	movs r2, 0x1
	bl sub_81B2AC8
_081B7588:
	ldr r1, [r6]
	adds r1, r4
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_81B2CD4
	ldr r1, [r6]
	adds r1, r4
	adds r0, r5, 0
	movs r2, 0x1
	bl sub_81B2D74
	ldr r1, [r6]
	adds r1, r4
	adds r0, r5, 0
	bl sub_81B2E28
	ldr r0, [r6]
	adds r0, r4, r0
	ldrb r0, [r0, 0x9]
	adds r1, r5, 0
	bl sub_81B5B38
	adds r0, r7, 0
	movs r1, 0x1
	bl sub_81B0FCC
	movs r0, 0
	bl schedule_bg_copy_tilemap_to_vram
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B754C

	thumb_func_start sub_81B75D4
sub_81B75D4: @ 81B75D4
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0
	bl WaitFanfare
	lsls r0, 24
	cmp r0, 0
	beq _081B7620
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B7620
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081B7606
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081B7620
_081B7606:
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81B767C
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B7634
	str r0, [r1]
_081B7620:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B75D4

	thumb_func_start sub_81B7634
sub_81B7634: @ 81B7634
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081B764E
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081B7668
_081B764E:
	movs r0, 0x5
	bl PlaySE
	adds r0, r4, 0
	bl sub_81B76C8
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B7704
	str r0, [r1]
_081B7668:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7634

	thumb_func_start sub_81B767C
sub_81B767C: @ 81B767C
	push {r4,r5,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203CEC4
	ldr r5, [r0]
	movs r0, 0x86
	lsls r0, 2
	adds r4, r5, r0
	bl sub_81B3364
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x18]
	ldrh r0, [r4, 0x18]
	movs r1, 0x89
	lsls r1, 2
	adds r2, r5, r1
	movs r1, 0x2
	str r1, [sp]
	movs r1, 0x3
	str r1, [sp, 0x4]
	adds r1, r4, 0
	movs r3, 0x1
	bl sub_81D3640
	ldrb r0, [r4, 0x18]
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B767C

	thumb_func_start sub_81B76C8
sub_81B76C8: @ 81B76C8
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_0203CEC4
	ldr r1, [r0]
	movs r0, 0x86
	lsls r0, 2
	adds r4, r1, r0
	ldrh r0, [r4, 0x18]
	movs r2, 0x89
	lsls r2, 2
	adds r1, r2
	movs r2, 0x3
	str r2, [sp]
	movs r2, 0x1
	movs r3, 0x2
	bl sub_81D3784
	ldrb r0, [r4, 0x18]
	movs r1, 0x2
	bl CopyWindowToVram
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B76C8

	thumb_func_start sub_81B7704
sub_81B7704: @ 81B7704
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0
	bl WaitFanfare
	lsls r0, 24
	cmp r0, 0
	beq _081B77A6
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r6, 0x1
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _081B772C
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081B77A6
_081B772C:
	bl sub_81B3394
	ldr r4, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r4, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x1
	bl MonTryLearningNewMove
	lsls r0, 16
	lsrs r1, r0, 16
	strh r6, [r4, 0x10]
	ldr r0, =0x0000fffe
	cmp r1, r0
	beq _081B7788
	cmp r1, r0
	bgt _081B776C
	cmp r1, 0
	beq _081B7778
	b _081B77A0
	.pool
_081B776C:
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _081B7780
	b _081B77A0
	.pool
_081B7778:
	adds r0, r5, 0
	bl sub_81B7810
	b _081B77A6
_081B7780:
	adds r0, r5, 0
	bl sub_81B787C
	b _081B77A6
_081B7788:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B77AC
	str r0, [r1]
	b _081B77A6
	.pool
_081B77A0:
	adds r0, r5, 0
	bl sub_81B7910
_081B77A6:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81B7704

	thumb_func_start sub_81B77AC
sub_81B77AC: @ 81B77AC
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0
	bl MonTryLearningNewMove
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x0000fffe
	cmp r1, r0
	beq _081B780A
	cmp r1, r0
	bgt _081B77E8
	cmp r1, 0
	beq _081B77F4
	b _081B7804
	.pool
_081B77E8:
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _081B77FC
	b _081B7804
	.pool
_081B77F4:
	adds r0, r4, 0
	bl sub_81B7810
	b _081B780A
_081B77FC:
	adds r0, r4, 0
	bl sub_81B787C
	b _081B780A
_081B7804:
	adds r0, r4, 0
	bl sub_81B7910
_081B780A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81B77AC

	thumb_func_start sub_81B7810
sub_81B7810: @ 81B7810
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r6, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r6, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r7, r1, r0
	adds r0, r7, 0
	movs r1, 0
	movs r2, 0
	bl GetEvolutionTargetSpecies
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	beq _081B7860
	bl sub_81B06F4
	ldr r0, =gCB2_AfterEvolution
	ldr r1, [r6]
	str r1, [r0]
	ldrb r3, [r6, 0x9]
	adds r0, r7, 0
	adds r1, r4, 0
	movs r2, 0x1
	bl BeginEvolutionScene
	adds r0, r5, 0
	bl DestroyTask
	b _081B786E
	.pool
_081B7860:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B6794
	str r0, [r1]
_081B786E:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7810

	thumb_func_start sub_81B787C
sub_81B787C: @ 81B787C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0203CEC8
	mov r8, r0
	movs r1, 0x9
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gStringVar1
	bl GetMonNickname
	ldr r0, =gStringVar2
	ldr r6, =gMoveToLearn
	ldrh r2, [r6]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_PkmnNeedsToReplaceMove
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldrh r0, [r6]
	mov r1, r8
	strh r0, [r1, 0xE]
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6FF4
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B787C

	thumb_func_start sub_81B7910
sub_81B7910: @ 81B7910
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r6, r0, 0
	adds r5, r1, 0
	lsls r6, 24
	lsrs r6, 24
	lsls r5, 16
	lsrs r5, 16
	ldr r0, =gUnknown_0203CEC8
	mov r8, r0
	movs r1, 0x9
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gStringVar1
	bl GetMonNickname
	ldr r0, =gStringVar2
	movs r1, 0xD
	muls r1, r5
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r4, =gStringVar4
	ldr r1, =gText_PkmnLearnedMove3
	adds r0, r4, 0
	bl StringExpandPlaceholders
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	mov r0, r8
	strh r5, [r0, 0xE]
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6F60
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7910

	thumb_func_start sub_81B79A0
sub_81B79A0: @ 81B79A0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	movs r1, 0x3A
	bl GetMonData
	strh r0, [r5]
	adds r0, r4, 0
	movs r1, 0x3B
	bl GetMonData
	strh r0, [r5, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	bl GetMonData
	strh r0, [r5, 0x4]
	adds r0, r4, 0
	movs r1, 0x3E
	bl GetMonData
	strh r0, [r5, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	bl GetMonData
	strh r0, [r5, 0xA]
	adds r0, r4, 0
	movs r1, 0x3D
	bl GetMonData
	strh r0, [r5, 0x6]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81B79A0

	thumb_func_start sub_81B79E8
sub_81B79E8: @ 81B79E8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203CEC4
	ldr r2, [r1]
	movs r3, 0x86
	lsls r3, 2
	adds r1, r2, r3
	movs r3, 0
	strh r3, [r1]
	ldr r4, =0x0000021a
	adds r1, r2, r4
	strh r3, [r1]
	ldr r1, =gUnknown_0203CEC8
	ldrb r1, [r1, 0x9]
	lsls r1, 24
	asrs r1, 24
	movs r3, 0x87
	lsls r3, 2
	adds r2, r3
	strh r1, [r2]
	bl sub_81B7A28
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B79E8

	thumb_func_start sub_81B7A28
sub_81B7A28: @ 81B7A28
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	mov r8, r4
	ldr r6, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r6, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _081B7A6E
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r7, r0, 16
	ldrb r0, [r6, 0x9]
	ldr r1, =gSpecialVar_ItemId
	ldrh r1, [r1]
	movs r2, 0
	bl ExecuteTableBasedItemEffect__
	lsls r0, 24
	cmp r0, 0
	beq _081B7A94
_081B7A6E:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =task_intro_gamefreak
	str r0, [r1]
	b _081B7B2A
	.pool
_081B7A94:
	movs r0, 0x1
	bl PlaySE
	ldr r4, =gUnknown_0203CEDC
	movs r0, 0x9
	ldrsb r0, [r6, r0]
	lsls r0, 4
	ldr r1, [r4]
	adds r1, r0
	adds r0, r5, 0
	bl party_menu_get_status_condition_and_update_object
	ldr r2, =gSprites
	movs r0, 0x9
	ldrsb r0, [r6, r0]
	ldr r1, [r4]
	lsls r0, 4
	adds r3, r0, r1
	ldrb r1, [r3, 0xC]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _081B7AD6
	adds r0, r5, 0
	adds r1, r3, 0
	movs r2, 0x1
	bl sub_81B2AC8
_081B7AD6:
	ldr r4, =gUnknown_0203CEC4
	ldr r0, [r4]
	movs r1, 0x87
	lsls r1, 2
	adds r0, r1
	ldrb r0, [r0]
	movs r1, 0
	bl sub_81B0FCC
	ldrb r0, [r6, 0x9]
	movs r1, 0x1
	bl sub_81B0FCC
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	adds r3, r0, 0
	subs r3, r7
	lsls r3, 16
	asrs r3, 16
	ldrb r1, [r6, 0x9]
	ldr r0, =sub_81B7C10
	str r0, [sp]
	mov r0, r8
	movs r2, 0x1
	bl sub_81B1F18
	mov r0, r8
	movs r1, 0
	adds r2, r7, 0
	bl sub_81B1FA8
	ldr r0, [r4]
	movs r2, 0x86
	lsls r2, 2
	adds r1, r0, r2
	movs r2, 0x1
	strh r2, [r1]
	ldr r1, =0x0000021a
	adds r0, r1
	strh r2, [r0]
_081B7B2A:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7A28

	thumb_func_start task_intro_gamefreak
task_intro_gamefreak: @ 81B7B4C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B7C0A
	ldr r5, =gUnknown_0203CEC4
	ldr r2, [r5]
	movs r0, 0x86
	lsls r0, 2
	adds r1, r2, r0
	movs r3, 0
	ldrsh r0, [r1, r3]
	ldr r3, =gUnknown_0203CEC8
	cmp r0, 0x1
	bne _081B7B82
	movs r0, 0
	strh r0, [r1]
	movs r1, 0x9
	ldrsb r1, [r3, r1]
	movs r6, 0x87
	lsls r6, 2
	adds r0, r2, r6
	strh r1, [r0]
_081B7B82:
	ldrb r0, [r3, 0x9]
	adds r0, 0x1
	strb r0, [r3, 0x9]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x6
	bne _081B7C04
	ldr r0, [r5]
	ldr r1, =0x0000021a
	adds r0, r1
	movs r2, 0
	ldrsh r1, [r0, r2]
	cmp r1, 0
	bne _081B7BC8
	ldr r0, =gUnknown_0203CEE8
	strb r1, [r0]
	ldr r0, =gText_WontHaveEffect
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	b _081B7BD8
	.pool
_081B7BC8:
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0x1
	strb r0, [r1]
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	movs r1, 0x1
	bl RemoveBagItem
_081B7BD8:
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6794
	str r1, [r0]
	ldr r1, =gUnknown_0203CEC8
	movs r0, 0
	strb r0, [r1, 0x9]
	b _081B7C0A
	.pool
_081B7C04:
	adds r0, r4, 0
	bl sub_81B7A28
_081B7C0A:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end task_intro_gamefreak

	thumb_func_start sub_81B7C10
sub_81B7C10: @ 81B7C10
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0x9
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
	ldr r1, =task_intro_gamefreak
	str r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7C10

	thumb_func_start sub_81B7C74
sub_81B7C74: @ 81B7C74
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	movs r0, 0x5
	bl PlaySE
	ldr r2, =gCB2_AfterEvolution
	ldr r1, =gUnknown_0203CEC8
	ldr r0, [r1]
	str r0, [r2]
	ldrb r0, [r1, 0x9]
	ldr r4, =gSpecialVar_ItemId
	ldrh r1, [r4]
	movs r2, 0
	bl ExecuteTableBasedItemEffect__
	lsls r0, 24
	cmp r0, 0
	beq _081B7CD8
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0
	strb r0, [r1]
	ldr r0, =gText_WontHaveEffect
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	str r6, [r0]
	b _081B7CE4
	.pool
_081B7CD8:
	ldrh r0, [r4]
	movs r1, 0x1
	bl RemoveBagItem
	bl sub_81B06F4
_081B7CE4:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81B7C74

	thumb_func_start GetItemEffectType
@ u8 GetItemEffectType(u16 itemId)
GetItemEffectType: @ 81B7CEC
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, r1, 0
	subs r2, 0xD
	lsls r0, r2, 16
	lsrs r0, 16
	cmp r0, 0xA5
	bls _081B7D00
	b _081B7E40
_081B7D00:
	cmp r1, 0xAF
	bne _081B7D18
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003214
	adds r4, r0, r1
	b _081B7D20
	.pool
_081B7D18:
	ldr r1, =gItemEffectTable
	lsls r0, r2, 2
	adds r0, r1
	ldr r4, [r0]
_081B7D20:
	ldrb r1, [r4]
	movs r5, 0x3F
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _081B7D42
	ldrb r0, [r4, 0x1]
	cmp r0, 0
	bne _081B7D42
	ldrb r0, [r4, 0x2]
	cmp r0, 0
	bne _081B7D42
	ldrb r3, [r4, 0x3]
	movs r0, 0x80
	ands r0, r3
	cmp r0, 0
	beq _081B7D4C
_081B7D42:
	movs r0, 0
	b _081B7E46
	.pool
_081B7D4C:
	movs r2, 0x40
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _081B7D5A
	movs r0, 0xA
	b _081B7E46
_081B7D5A:
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	beq _081B7D66
	movs r0, 0x1
	b _081B7E46
_081B7D66:
	adds r2, r5, 0
	ands r2, r3
	cmp r2, 0
	bne _081B7D74
	lsrs r0, r1, 7
	cmp r0, 0
	beq _081B7DB6
_081B7D74:
	cmp r2, 0x20
	bne _081B7D7C
	movs r0, 0x4
	b _081B7E46
_081B7D7C:
	cmp r2, 0x10
	bne _081B7D84
	movs r0, 0x3
	b _081B7E46
_081B7D84:
	cmp r2, 0x8
	bne _081B7D8C
	movs r0, 0x5
	b _081B7E46
_081B7D8C:
	cmp r2, 0x4
	bne _081B7D94
	movs r0, 0x6
	b _081B7E46
_081B7D94:
	cmp r2, 0x2
	bne _081B7D9C
	movs r0, 0x7
	b _081B7E46
_081B7D9C:
	cmp r2, 0x1
	bne _081B7DA4
	movs r0, 0x8
	b _081B7E46
_081B7DA4:
	lsrs r0, r1, 7
	cmp r0, 0
	beq _081B7DB2
	cmp r2, 0
	bne _081B7DB2
	movs r0, 0x9
	b _081B7E46
_081B7DB2:
	movs r0, 0xB
	b _081B7E46
_081B7DB6:
	ldrb r1, [r4, 0x4]
	movs r0, 0x44
	ands r0, r1
	adds r2, r1, 0
	cmp r0, 0
	beq _081B7DC6
	movs r0, 0x2
	b _081B7E46
_081B7DC6:
	movs r5, 0x2
	adds r0, r5, 0
	ands r0, r2
	cmp r0, 0
	beq _081B7DD4
	movs r0, 0xC
	b _081B7E46
_081B7DD4:
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r2
	cmp r0, 0
	beq _081B7DE2
	movs r0, 0xD
	b _081B7E46
_081B7DE2:
	ldrb r1, [r4, 0x5]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081B7DF0
	movs r0, 0xE
	b _081B7E46
_081B7DF0:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081B7DFC
	movs r0, 0xF
	b _081B7E46
_081B7DFC:
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _081B7E08
	movs r0, 0x10
	b _081B7E46
_081B7E08:
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _081B7E14
	movs r0, 0x11
	b _081B7E46
_081B7E14:
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	beq _081B7E20
	movs r0, 0x12
	b _081B7E46
_081B7E20:
	movs r0, 0x20
	ands r0, r2
	cmp r0, 0
	beq _081B7E2C
	movs r0, 0x13
	b _081B7E46
_081B7E2C:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081B7E38
	movs r0, 0x14
	b _081B7E46
_081B7E38:
	movs r0, 0x18
	ands r0, r2
	cmp r0, 0
	bne _081B7E44
_081B7E40:
	movs r0, 0x16
	b _081B7E46
_081B7E44:
	movs r0, 0x15
_081B7E46:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetItemEffectType

	thumb_func_start sub_81B7E4C
sub_81B7E4C: @ 81B7E4C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081B7F1C
	ldr r7, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r7, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	movs r0, 0xE
	adds r0, r7
	mov r8, r0
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetMonNickname
	ldr r4, =gSpecialVar_0x8005
	ldrb r0, [r4]
	bl sub_81B2360
	strh r0, [r7, 0xE]
	ldr r0, =gStringVar2
	movs r1, 0xE
	ldrsh r2, [r7, r1]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	movs r0, 0x2
	mov r1, r8
	strh r0, [r1, 0x2]
	ldrb r2, [r4]
	adds r0, r5, 0
	movs r1, 0
	bl sub_81B22D8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B7EF0
	cmp r0, 0x2
	beq _081B7EF8
	ldrh r1, [r7, 0xE]
	adds r0, r5, 0
	bl GiveMoveToMon
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	beq _081B7F08
	adds r0, r6, 0
	bl sub_81B6EB4
	b _081B7F1C
	.pool
_081B7EF0:
	ldr r1, =gText_PkmnCantLearnMove
	b _081B7EFA
	.pool
_081B7EF8:
	ldr r1, =gText_PkmnAlreadyKnows
_081B7EFA:
	adds r0, r6, 0
	bl sub_81B6D98
	b _081B7F1C
	.pool
_081B7F08:
	ldr r0, =gText_PkmnNeedsToReplaceMove
	bl sub_81B6D74
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B6FF4
	str r1, [r0]
_081B7F1C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7E4C

	thumb_func_start CB2_PartyMenuFromStartMenu
CB2_PartyMenuFromStartMenu: @ 81B7F34
	push {lr}
	sub sp, 0xC
	movs r0, 0
	str r0, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =CB2_ReturnToFieldWithOpenMenu
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end CB2_PartyMenuFromStartMenu

	thumb_func_start sub_81B7F60
sub_81B7F60: @ 81B7F60
	push {lr}
	sub sp, 0xC
	bl InBattlePyramid
	lsls r0, 24
	ldr r1, =sub_81C4F84
	cmp r0, 0
	bne _081B7F72
	ldr r1, =c2_815ABFC
_081B7F72:
	movs r0, 0x6
	str r0, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x5
	movs r3, 0
	bl sub_81B0038
	ldr r1, =gUnknown_0203CEC8
	ldr r0, =gSpecialVar_ItemId
	ldrh r0, [r0]
	strh r0, [r1, 0xC]
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7F60

	thumb_func_start sub_81B7FAC
sub_81B7FAC: @ 81B7FAC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r6, r4, 0
	ldr r5, =gUnknown_0203CEFC
	ldr r0, =gUnknown_0203CEC8
	mov r9, r0
	ldrb r0, [r0, 0x9]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	ldr r7, =gPlayerParty
	adds r0, r7
	movs r1, 0xC
	bl GetMonData
	strh r0, [r5]
	lsls r0, 16
	cmp r0, 0
	bne _081B7FF8
	adds r0, r4, 0
	bl sub_81B8044
	b _081B8030
	.pool
_081B7FF8:
	ldrh r0, [r5]
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	beq _081B800C
	adds r0, r4, 0
	bl sub_81B83B8
	b _081B8030
_081B800C:
	mov r1, r9
	movs r0, 0x9
	ldrsb r0, [r1, r0]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r7
	ldrh r1, [r5]
	movs r2, 0x1
	bl sub_81B1D1C
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B82A0
	str r1, [r0]
_081B8030:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B7FAC

	thumb_func_start sub_81B8044
sub_81B8044: @ 81B8044
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r5, =gUnknown_0203CEC8
	ldrh r0, [r5, 0xC]
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	beq _081B807C
	ldrh r0, [r5, 0xC]
	bl sub_81B83F0
	ldr r0, =gUnknown_0203CEC4
	ldr r1, [r0]
	ldr r0, =sub_81B814C
	str r0, [r1, 0x4]
	adds r0, r4, 0
	bl sub_81B12C0
	b _081B8082
	.pool
_081B807C:
	adds r0, r4, 0
	bl sub_81B8088
_081B8082:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81B8044

	thumb_func_start sub_81B8088
sub_81B8088: @ 81B8088
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081B80E4
	ldr r4, =gUnknown_0203CEC8
	ldrh r5, [r4, 0xC]
	movs r0, 0x9
	ldrsb r0, [r4, r0]
	movs r1, 0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	ldr r6, =gPlayerParty
	adds r0, r6
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl sub_81B1C84
	movs r0, 0x9
	ldrsb r0, [r4, r0]
	mov r1, r8
	muls r1, r0
	adds r0, r1, 0
	adds r0, r6
	adds r1, r5, 0
	bl sub_81B1DB8
	adds r0, r5, 0
	bl sub_81B83F0
	ldr r1, =gTasks
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B8104
	str r1, [r0]
_081B80E4:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8088

	thumb_func_start sub_81B8104
sub_81B8104: @ 81B8104
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gUnknown_0203CEC8
	ldrb r4, [r0, 0x9]
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B8138
	lsls r2, r4, 24
	asrs r2, 24
	movs r0, 0x64
	muls r0, r2
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gUnknown_0203CEDC
	lsls r2, 4
	ldr r1, [r1]
	adds r1, r2
	bl sub_81B5C94
	adds r0, r5, 0
	bl sub_81B12C0
_081B8138:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8104

	thumb_func_start sub_81B814C
sub_81B814C: @ 81B814C
	push {r4-r6,lr}
	ldr r4, =gUnknown_0203CEC8
	movs r0, 0x9
	ldrsb r0, [r4, r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	ldrh r1, [r4, 0xC]
	bl sub_81B1DB8
	movs r0, 0x9
	ldrsb r0, [r4, r0]
	muls r0, r6
	adds r0, r5
	movs r1, 0x40
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSaveBlock1Ptr
	lsls r2, r0, 3
	adds r2, r0
	lsls r2, 2
	ldr r0, =0x00002be0
	adds r2, r0
	ldr r1, [r1]
	adds r1, r2
	ldr r2, =sub_81B81A8
	movs r0, 0x4
	movs r3, 0x3
	bl sub_811A20C
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B814C

	thumb_func_start sub_81B81A8
sub_81B81A8: @ 81B81A8
	push {r4-r7,lr}
	sub sp, 0xC
	ldr r6, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r6, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	adds r0, r5, 0
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r7, r0, 16
	ldr r0, =gSpecialVar_Result
	ldrh r0, [r0]
	cmp r0, 0
	bne _081B8208
	adds r0, r5, 0
	bl TakeMailFromMon
	ldr r4, =gUnknown_0203CEFC
	adds r0, r5, 0
	movs r1, 0xC
	adds r2, r4, 0
	bl SetMonData
	ldrh r0, [r4]
	movs r1, 0x1
	bl RemoveBagItem
	adds r0, r7, 0
	bl sub_81B841C
	ldr r0, [r6]
	bl SetMainCallback2
	b _081B8224
	.pool
_081B8208:
	ldrb r0, [r6, 0x8]
	lsls r0, 28
	lsrs r0, 28
	ldrb r2, [r6, 0xB]
	movs r1, 0x7F
	str r1, [sp]
	ldr r1, =sub_81B8230
	str r1, [sp, 0x4]
	ldr r1, [r6]
	str r1, [sp, 0x8]
	movs r1, 0xFF
	movs r3, 0x1
	bl sub_81B0038
_081B8224:
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B81A8

	thumb_func_start sub_81B8230
sub_81B8230: @ 81B8230
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081B828A
	ldr r1, =gUnknown_0203CEFC
	ldrh r0, [r1]
	cmp r0, 0
	beq _081B8264
	ldr r0, =gUnknown_0203CEC8
	ldrh r0, [r0, 0xC]
	ldrh r1, [r1]
	movs r2, 0
	bl sub_81B1D68
	b _081B827C
	.pool
_081B8264:
	ldr r2, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r2, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldrh r1, [r2, 0xC]
	movs r2, 0
	movs r3, 0x1
	bl sub_81B1C84
_081B827C:
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B8104
	str r0, [r1]
_081B828A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8230

	thumb_func_start sub_81B82A0
sub_81B82A0: @ 81B82A0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_81B1BD4
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B82C4
	bl sub_81B334C
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B82D4
	str r0, [r1]
_081B82C4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B82A0

	thumb_func_start sub_81B82D4
sub_81B82D4: @ 81B82D4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _081B82FA
	cmp r1, 0
	bgt _081B82F4
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _081B8394
	b _081B83A8
_081B82F4:
	cmp r1, 0x1
	beq _081B839A
	b _081B83A8
_081B82FA:
	ldr r7, =gUnknown_0203CEC8
	ldrh r4, [r7, 0xC]
	adds r0, r4, 0
	bl sub_81B83F0
	ldr r6, =gUnknown_0203CEFC
	ldrh r0, [r6]
	movs r1, 0x1
	bl AddBagItem
	lsls r0, 24
	cmp r0, 0
	bne _081B8338
	adds r0, r4, 0
	bl sub_81B841C
	ldrh r0, [r6]
	bl pokemon_item_not_removed
	ldr r0, =gStringVar4
	movs r1, 0
	bl sub_81B1B5C
	b _081B8378
	.pool
_081B8338:
	adds r0, r4, 0
	bl ItemIsMail
	lsls r0, 24
	cmp r0, 0
	beq _081B835C
	ldr r0, =gUnknown_0203CEC4
	ldr r1, [r0]
	ldr r0, =sub_81B814C
	str r0, [r1, 0x4]
	adds r0, r5, 0
	bl sub_81B12C0
	b _081B83A8
	.pool
_081B835C:
	movs r1, 0x9
	ldrsb r1, [r7, r1]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	bl sub_81B1DB8
	ldrh r1, [r6]
	adds r0, r4, 0
	movs r2, 0x1
	bl sub_81B1D68
_081B8378:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B8104
	str r1, [r0]
	b _081B83A8
	.pool
_081B8394:
	movs r0, 0x5
	bl PlaySE
_081B839A:
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B8104
	str r0, [r1]
_081B83A8:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B82D4

	thumb_func_start sub_81B83B8
sub_81B83B8: @ 81B83B8
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =gText_RemoveMailBeforeItem
	movs r1, 0x1
	bl sub_81B1B5C
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_81B8104
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B83B8

	thumb_func_start sub_81B83F0
sub_81B83F0: @ 81B83F0
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =gUnknown_0203CEC8
	ldrb r0, [r0, 0xB]
	cmp r0, 0x6
	bne _081B8410
	lsls r0, r1, 24
	lsrs r0, 24
	movs r1, 0x1
	bl RemovePCItem
	b _081B8418
	.pool
_081B8410:
	adds r0, r1, 0
	movs r1, 0x1
	bl RemoveBagItem
_081B8418:
	pop {r0}
	bx r0
	thumb_func_end sub_81B83F0

	thumb_func_start sub_81B841C
sub_81B841C: @ 81B841C
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =gUnknown_0203CEC8
	ldrb r0, [r0, 0xB]
	cmp r0, 0x5
	beq _081B8438
	adds r0, r1, 0
	movs r1, 0x1
	bl AddPCItem
	b _081B8440
	.pool
_081B8438:
	adds r0, r1, 0
	movs r1, 0x1
	bl AddBagItem
_081B8440:
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_81B841C

	thumb_func_start sub_81B8448
sub_81B8448: @ 81B8448
	push {lr}
	sub sp, 0xC
	movs r0, 0x6
	str r0, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =Mailbox_ReturnToMailListAfterDeposit
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0x7
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8448

	thumb_func_start sub_81B8474
sub_81B8474: @ 81B8474
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_0203CEC8
	movs r1, 0x9
	ldrsb r1, [r0, r1]
	movs r0, 0x64
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r5, r1, r0
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0
	strb r0, [r1]
	ldr r2, =gSaveBlock1Ptr
	ldr r0, =playerPCItemPageInfo
	ldrh r1, [r0]
	adds r1, 0x6
	ldrh r0, [r0, 0x2]
	adds r1, r0
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x00002be0
	adds r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	adds r0, r5, 0
	movs r1, 0xC
	bl GetMonData
	cmp r0, 0
	beq _081B84DC
	ldr r0, =gText_PkmnHoldingItemCantHoldMail
	movs r1, 0x1
	bl sub_81B1B5C
	b _081B84F2
	.pool
_081B84DC:
	adds r0, r5, 0
	adds r1, r4, 0
	bl GiveMailToMon2
	adds r0, r4, 0
	bl ClearMailStruct
	ldr r0, =gText_MailTransferredFromMailbox
	movs r1, 0x1
	bl sub_81B1B5C
_081B84F2:
	movs r0, 0x2
	bl schedule_bg_copy_tilemap_to_vram
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B8104
	str r0, [r1]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8474

	thumb_func_start sub_81B8518
sub_81B8518: @ 81B8518
	push {lr}
	sub sp, 0xC
	bl sub_81B8558
	movs r0, 0
	str r0, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	str r0, [sp, 0x8]
	movs r0, 0x4
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_81B0038
	ldr r1, =gUnknown_0203CEC8
	ldr r0, =sub_81B879C
	str r0, [r1, 0x4]
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8518

	thumb_func_start sub_81B8558
sub_81B8558: @ 81B8558
	push {lr}
	ldr r0, =gSelectedOrderFromParty
	movs r1, 0
	movs r2, 0x4
	bl memset
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8558

	thumb_func_start sub_81B856C
sub_81B856C: @ 81B856C
	push {r4,lr}
	lsls r0, 24
	asrs r4, r0, 24
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	bl sub_81B85AC
	lsls r0, 24
	cmp r0, 0
	bne _081B858C
	movs r0, 0x2
	b _081B85A4
	.pool
_081B858C:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r0, 24
	bl sub_81B8770
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B85A2
	movs r0, 0
	b _081B85A4
_081B85A2:
	movs r0, 0x1
_081B85A4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81B856C

	thumb_func_start sub_81B85AC
sub_81B85AC: @ 81B85AC
	push {r4-r6,lr}
	adds r5, r0, 0
	movs r6, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _081B8608
	adds r0, r5, 0
	movs r1, 0x38
	bl GetMonData
	adds r4, r0, 0
	bl sub_81B8888
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bhi _081B8608
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000191a
	cmp r1, r0
	bne _081B85EA
	adds r0, r5, 0
	movs r1, 0xC
	bl GetMonData
	cmp r0, 0
	bne _081B8608
_081B85EA:
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x8
	beq _081B864A
	cmp r0, 0x9
	bne _081B8618
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	bne _081B864A
_081B8608:
	movs r0, 0
	b _081B864C
	.pool
_081B8618:
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r3, =gFrontierBannedSpecies
	lsls r1, r6, 1
	adds r0, r1, r3
	ldrh r0, [r0]
	ldr r2, =0x0000ffff
	cmp r0, r2
	beq _081B864A
_081B8632:
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, r4
	beq _081B8608
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, r6, 1
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _081B8632
_081B864A:
	movs r0, 0x1
_081B864C:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B85AC

	thumb_func_start sub_81B865C
sub_81B865C: @ 81B865C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	bl sub_81B885C
	lsls r0, 24
	lsrs r2, r0, 24
	adds r1, r2, 0
	ldr r3, =gSelectedOrderFromParty
	adds r0, r2, r3
	subs r0, 0x1
	ldrb r0, [r0]
	cmp r0, 0
	bne _081B869C
	cmp r2, 0x1
	bne _081B8688
	movs r0, 0xE
	b _081B8758
	.pool
_081B8688:
	ldr r0, =gStringVar1
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	movs r0, 0x11
	b _081B8758
	.pool
_081B869C:
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 24
	movs r1, 0xF8
	lsls r1, 24
	adds r0, r1
	lsrs r0, 24
	cmp r0, 0x1
	bhi _081B86C0
	b _081B8756
	.pool
_081B86B8:
	movs r0, 0x12
	b _081B8758
_081B86BC:
	movs r0, 0x13
	b _081B8758
_081B86C0:
	bl sub_81B8830
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0
	b _081B8750
_081B86CE:
	ldr r3, =gSelectedOrderFromParty
	adds r4, r3, r5
	ldrb r0, [r4]
	movs r1, 0x64
	muls r0, r1
	subs r0, 0x64
	ldr r3, =gPlayerParty
	adds r0, r3, r0
	movs r1, 0xB
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	ldrb r0, [r4]
	movs r1, 0x64
	muls r0, r1
	subs r0, 0x64
	ldr r3, =gPlayerParty
	adds r0, r3, r0
	movs r1, 0xC
	bl GetMonData
	lsls r0, 16
	lsrs r6, r0, 16
	adds r1, r5, 0x1
	lsls r0, r1, 24
	lsrs r4, r0, 24
	mov r9, r1
	cmp r4, r8
	bcs _081B8748
	movs r7, 0x64
_081B870E:
	ldr r0, =gSelectedOrderFromParty
	adds r5, r0, r4
	ldrb r0, [r5]
	muls r0, r7
	subs r0, 0x64
	ldr r1, =gPlayerParty
	adds r0, r1, r0
	movs r1, 0xB
	bl GetMonData
	cmp r10, r0
	beq _081B86B8
	cmp r6, 0
	beq _081B873E
	ldrb r0, [r5]
	muls r0, r7
	subs r0, 0x64
	ldr r3, =gPlayerParty
	adds r0, r3, r0
	movs r1, 0xC
	bl GetMonData
	cmp r6, r0
	beq _081B86BC
_081B873E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r8
	bcc _081B870E
_081B8748:
	mov r1, r9
	lsls r0, r1, 24
	lsrs r5, r0, 24
	mov r0, r8
_081B8750:
	subs r0, 0x1
	cmp r5, r0
	blt _081B86CE
_081B8756:
	movs r0, 0xFF
_081B8758:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B865C

	thumb_func_start sub_81B8770
sub_81B8770: @ 81B8770
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gSelectedOrderFromParty
_081B877A:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081B878C
	movs r0, 0x1
	b _081B8798
	.pool
_081B878C:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081B877A
	movs r0, 0
_081B8798:
	pop {r1}
	bx r1
	thumb_func_end sub_81B8770

	thumb_func_start sub_81B879C
sub_81B879C: @ 81B879C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_81B865C
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFF
	beq _081B87D4
	movs r0, 0x20
	bl PlaySE
	adds r0, r4, 0
	bl display_pokemon_menu_message
	ldr r0, =gTasks
	lsls r1, r5, 2
	adds r1, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B87E8
	str r0, [r1]
	b _081B87E0
	.pool
_081B87D4:
	movs r0, 0x5
	bl PlaySE
	adds r0, r5, 0
	bl sub_81B12C0
_081B87E0:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_81B879C

	thumb_func_start sub_81B87E8
sub_81B87E8: @ 81B87E8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081B8802
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081B881C
_081B8802:
	movs r0, 0x5
	bl PlaySE
	movs r0, 0
	bl display_pokemon_menu_message
	ldr r0, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B1370
	str r0, [r1]
_081B881C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B87E8

	thumb_func_start sub_81B8830
sub_81B8830: @ 81B8830
	push {lr}
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x8
	beq _081B884C
	cmp r0, 0x9
	bne _081B8850
	movs r0, 0x3
	b _081B8854
	.pool
_081B884C:
	movs r0, 0x2
	b _081B8854
_081B8850:
	ldr r0, =gSpecialVar_0x8005
	ldrb r0, [r0]
_081B8854:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B8830

	thumb_func_start sub_81B885C
sub_81B885C: @ 81B885C
	push {lr}
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x8
	beq _081B8878
	cmp r0, 0x9
	bne _081B887C
	movs r0, 0x1
	b _081B8880
	.pool
_081B8878:
	movs r0, 0x2
	b _081B8880
_081B887C:
	ldr r0, =gSpecialVar_0x8005
	ldrb r0, [r0]
_081B8880:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B885C

	thumb_func_start sub_81B8888
sub_81B8888: @ 81B8888
	push {lr}
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x8
	beq _081B88A4
	cmp r0, 0x9
	bne _081B88A8
_081B889C:
	movs r0, 0x64
	b _081B88B2
	.pool
_081B88A4:
	movs r0, 0x1E
	b _081B88B2
_081B88A8:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0
	bne _081B889C
	movs r0, 0x32
_081B88B2:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B8888

	thumb_func_start sub_81B88BC
sub_81B88BC: @ 81B88BC
	push {lr}
	ldr r0, =0x000040cf
	bl VarGet
	lsls r0, 24
	lsrs r1, r0, 24
	movs r2, 0xF8
	lsls r2, 24
	adds r0, r2
	lsrs r0, 24
	cmp r0, 0x1
	bhi _081B88E0
	ldr r0, =gText_CancelBattle
	b _081B88FA
	.pool
_081B88E0:
	cmp r1, 0x1
	bne _081B88F8
	ldr r0, =gSpecialVar_0x8005
	ldrh r0, [r0]
	cmp r0, 0x2
	bne _081B88F8
	ldr r0, =gText_ReturnToWaitingRoom
	b _081B88FA
	.pool
_081B88F8:
	ldr r0, =gText_CancelChallenge
_081B88FA:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B88BC

	thumb_func_start sub_81B8904
sub_81B8904: @ 81B8904
	push {lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	str r2, [sp]
	ldr r2, =sub_81B1370
	str r2, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8904

	thumb_func_start sub_81B892C
sub_81B892C: @ 81B892C
	push {lr}
	sub sp, 0xC
	movs r0, 0x4
	str r0, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =CB2_ReturnToFieldContinueScriptPlayMapMusic
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0xC
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B892C

	thumb_func_start sub_81B8958
sub_81B8958: @ 81B8958
	push {lr}
	sub sp, 0xC
	movs r0, 0x1
	str r0, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =CB2_ReturnToFieldContinueScriptPlayMapMusic
	str r0, [sp, 0x8]
	movs r0, 0xB
	movs r1, 0
	movs r2, 0xD
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8958

	thumb_func_start sub_81B8984
sub_81B8984: @ 81B8984
	push {lr}
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _081B8994
	movs r0, 0
	b _081B89A6
_081B8994:
	bl sub_81B1250
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081B89A4
	movs r0, 0x1
	b _081B89A6
_081B89A4:
	movs r0, 0x2
_081B89A6:
	pop {r1}
	bx r1
	thumb_func_end sub_81B8984

	thumb_func_start OpenPartyMenuInBattle
OpenPartyMenuInBattle: @ 81B89AC
	push {r4,lr}
	sub sp, 0xC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	bl sub_81B8984
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	str r0, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =SetCB2ToReshowScreenAfterMenu
	str r0, [sp, 0x8]
	movs r0, 0x1
	adds r2, r4, 0
	movs r3, 0
	bl sub_81B0038
	bl nullsub_35
	bl pokemon_change_order
	add sp, 0xC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end OpenPartyMenuInBattle

	thumb_func_start sub_81B89F0
sub_81B89F0: @ 81B89F0
	push {lr}
	sub sp, 0xC
	bl sub_81B8984
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x5
	str r0, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =c2_815ABFC
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r2, 0x3
	movs r3, 0
	bl sub_81B0038
	bl nullsub_35
	bl pokemon_change_order
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B89F0

	thumb_func_start sub_81B8A2C
sub_81B8A2C: @ 81B8A2C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gPlayerParty + 0x64
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _081B8A74
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	bne _081B8A74
	ldr r0, =gUnknown_0203CEC8
	ldrb r0, [r0, 0xB]
	cmp r0, 0x1
	bne _081B8A5C
	movs r0, 0x3
	b _081B8A76
	.pool
_081B8A5C:
	ldr r0, =gBattleTypeFlags
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 11
	ands r0, r1
	cmp r0, 0
	bne _081B8A74
	movs r0, 0x2
	b _081B8A76
	.pool
_081B8A74:
	movs r0, 0x7
_081B8A76:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81B8A2C

	thumb_func_start sub_81B8A7C
sub_81B8A7C: @ 81B8A7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	bl GetCursorSelectionMonId
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_81B1250
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081B8AC4
	cmp r5, 0x1
	beq _081B8AA2
	cmp r5, 0x4
	beq _081B8AA2
	cmp r5, 0x5
	bne _081B8AC4
_081B8AA2:
	ldr r4, =gStringVar1
	bl GetTrainerPartnerName
	adds r1, r0, 0
	adds r0, r4, 0
	bl StringCopy
	ldr r0, =gStringVar4
	ldr r1, =gText_CantSwitchWithAlly
	b _081B8C42
	.pool
_081B8AC4:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	bne _081B8AF8
	ldr r1, =gStringVar1
	adds r0, r4, 0
	bl GetMonNickname
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnHasNoEnergy
	b _081B8C42
	.pool
_081B8AF8:
	movs r4, 0
	b _081B8B24
_081B8AFC:
	adds r0, r4, 0
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _081B8B1E
	adds r0, r5, 0
	bl sub_81B8F38
	lsls r0, 24
	ldr r2, =gBattlerPartyIndexes
	lsls r1, r4, 1
	adds r1, r2
	lsrs r0, 24
	ldrh r1, [r1]
	cmp r0, r1
	beq _081B8BFC
_081B8B1E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_081B8B24:
	ldr r0, =gBattlersCount
	ldrb r0, [r0]
	cmp r4, r0
	bcc _081B8AFC
	movs r7, 0x64
	adds r0, r5, 0
	muls r0, r7
	ldr r1, =gPlayerParty
	mov r8, r1
	adds r6, r0, r1
	adds r0, r6, 0
	movs r1, 0x2D
	bl GetMonData
	cmp r0, 0
	beq _081B8B60
	ldr r0, =gStringVar4
	ldr r1, =gText_EggCantBattle
	b _081B8C42
	.pool
_081B8B60:
	adds r0, r5, 0
	bl sub_81B8F38
	ldr r1, =gBattleStruct
	ldr r1, [r1]
	adds r1, 0x8B
	lsls r0, 24
	lsrs r0, 24
	ldrb r1, [r1]
	cmp r0, r1
	bne _081B8B94
	ldr r1, =gStringVar1
	adds r0, r6, 0
	bl GetMonNickname
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnAlreadySelected
	b _081B8C42
	.pool
_081B8B94:
	ldr r0, =gUnknown_0203CEC8
	ldrb r0, [r0, 0xB]
	cmp r0, 0x4
	bne _081B8BA8
	bl SetMonPreventsSwitchingString
	b _081B8C46
	.pool
_081B8BA8:
	cmp r0, 0x2
	beq _081B8C20
	adds r0, r5, 0
	bl sub_81B8F38
	ldr r1, =gUnknown_0203CEE9
	strb r0, [r1]
	ldr r1, =gUnknown_0203CEE8
	movs r0, 0x1
	strb r0, [r1]
	ldr r1, =gBattlerPartyIndexes
	ldr r0, =gBattlerInMenuId
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r1
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_81B8FB0
	adds r0, r4, 0
	muls r0, r7
	add r0, r8
	adds r1, r6, 0
	bl sub_81B1288
	movs r0, 0x1
	b _081B8C48
	.pool
_081B8BFC:
	movs r0, 0x64
	muls r0, r5
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gStringVar1
	bl GetMonNickname
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnAlreadyInBattle
	b _081B8C42
	.pool
_081B8C20:
	ldr r0, =gBattlerInMenuId
	ldrb r0, [r0]
	ldr r1, =gBattlerPartyIndexes
	lsls r0, 1
	adds r0, r1
	ldrb r0, [r0]
	bl pokemon_order_func
	lsls r0, 24
	lsrs r0, 24
	muls r0, r7
	add r0, r8
	ldr r1, =gStringVar1
	bl GetMonNickname
	ldr r0, =gStringVar4
	ldr r1, =gText_PkmnCantSwitchOut
_081B8C42:
	bl StringExpandPlaceholders
_081B8C46:
	movs r0, 0
_081B8C48:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B8A7C

	thumb_func_start sub_81B8C68
sub_81B8C68: @ 81B8C68
	push {r4,lr}
	ldr r4, =gUnknown_0203CF00
	bl sub_806D7EC
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl sub_81B8C88
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8C68

	thumb_func_start sub_81B8C88
sub_81B8C88: @ 81B8C88
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	bl sub_81B1250
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081B8CBE
	cmp r4, 0
	beq _081B8CB0
	movs r0, 0x30
	strb r0, [r6]
	movs r0, 0x45
	strb r0, [r6, 0x1]
	movs r0, 0x12
	strb r0, [r6, 0x2]
	b _081B8D58
_081B8CB0:
	movs r0, 0x3
	strb r0, [r6]
	movs r0, 0x12
	strb r0, [r6, 0x1]
	movs r0, 0x45
	strb r0, [r6, 0x2]
	b _081B8D58
_081B8CBE:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _081B8CFC
	movs r5, 0x1
	movs r0, 0
	bl GetBattlerAtPosition
	mov r2, sp
	ldr r1, =gBattlerPartyIndexes
	lsls r0, 24
	lsrs r0, 23
	adds r0, r1
	ldrh r0, [r0]
	strb r0, [r2]
	movs r4, 0
	mov r1, sp
_081B8CE2:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8CF0
	mov r2, sp
	adds r0, r2, r5
	strb r4, [r0]
	adds r5, 0x1
_081B8CF0:
	adds r4, 0x1
	cmp r4, 0x5
	ble _081B8CE2
	b _081B8D40
	.pool
_081B8CFC:
	movs r5, 0x2
	movs r0, 0
	bl GetBattlerAtPosition
	mov r1, sp
	ldr r4, =gBattlerPartyIndexes
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	ldrh r0, [r0]
	strb r0, [r1]
	movs r0, 0x2
	bl GetBattlerAtPosition
	mov r1, sp
	lsls r0, 24
	lsrs r0, 23
	adds r0, r4
	ldrh r0, [r0]
	strb r0, [r1, 0x1]
	movs r4, 0
_081B8D26:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8D3A
	ldrb r0, [r1, 0x1]
	cmp r4, r0
	beq _081B8D3A
	mov r2, sp
	adds r0, r2, r5
	strb r4, [r0]
	adds r5, 0x1
_081B8D3A:
	adds r4, 0x1
	cmp r4, 0x5
	ble _081B8D26
_081B8D40:
	movs r4, 0
	mov r3, sp
_081B8D44:
	adds r0, r6, r4
	ldrb r1, [r3]
	lsls r1, 4
	ldrb r2, [r3, 0x1]
	orrs r1, r2
	strb r1, [r0]
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x2
	ble _081B8D44
_081B8D58:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8C88

	thumb_func_start sub_81B8D64
sub_81B8D64: @ 81B8D64
	push {lr}
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =gBattleStruct
	lsls r3, r2, 1
	adds r3, r2
	adds r3, 0x60
	ldr r0, [r0]
	adds r0, r3
	bl sub_81B8D88
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8D64

	thumb_func_start sub_81B8D88
sub_81B8D88: @ 81B8D88
	push {r4-r7,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r0, r2, 0
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r0, 24
	lsrs r0, 24
	bl GetBattlerSide
	lsls r0, 24
	cmp r0, 0
	bne _081B8DB0
	movs r0, 0
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x2
	b _081B8DBC
_081B8DB0:
	movs r0, 0x1
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x3
_081B8DBC:
	bl GetBattlerAtPosition
	lsls r0, 24
	lsrs r6, r0, 24
	bl sub_81B1250
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081B8DF0
	cmp r7, 0
	beq _081B8DE2
	movs r0, 0x30
	strb r0, [r5]
	movs r0, 0x45
	strb r0, [r5, 0x1]
	movs r0, 0x12
	strb r0, [r5, 0x2]
	b _081B8E72
_081B8DE2:
	movs r0, 0x3
	strb r0, [r5]
	movs r0, 0x12
	strb r0, [r5, 0x1]
	movs r0, 0x45
	strb r0, [r5, 0x2]
	b _081B8E72
_081B8DF0:
	bl IsDoubleBattle
	lsls r0, 24
	cmp r0, 0
	bne _081B8E28
	movs r3, 0x1
	mov r2, sp
	ldr r1, =gBattlerPartyIndexes
	lsls r0, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	strb r0, [r2]
	movs r4, 0
	mov r1, sp
_081B8E0C:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8E1A
	mov r2, sp
	adds r0, r2, r3
	strb r4, [r0]
	adds r3, 0x1
_081B8E1A:
	adds r4, 0x1
	cmp r4, 0x5
	ble _081B8E0C
	b _081B8E5A
	.pool
_081B8E28:
	movs r3, 0x2
	mov r1, sp
	ldr r2, =gBattlerPartyIndexes
	lsls r0, r4, 1
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	lsls r0, r6, 1
	adds r0, r2
	ldrh r0, [r0]
	strb r0, [r1, 0x1]
	movs r4, 0
_081B8E40:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8E54
	ldrb r0, [r1, 0x1]
	cmp r4, r0
	beq _081B8E54
	mov r2, sp
	adds r0, r2, r3
	strb r4, [r0]
	adds r3, 0x1
_081B8E54:
	adds r4, 0x1
	cmp r4, 0x5
	ble _081B8E40
_081B8E5A:
	movs r4, 0
	mov r3, sp
_081B8E5E:
	adds r0, r5, r4
	ldrb r1, [r3]
	lsls r1, 4
	ldrb r2, [r3, 0x1]
	orrs r1, r2
	strb r1, [r0]
	adds r3, 0x2
	adds r4, 0x1
	cmp r4, 0x2
	ble _081B8E5E
_081B8E72:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8D88

	thumb_func_start sub_81B8E80
sub_81B8E80: @ 81B8E80
	push {r4-r7,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsls r2, 24
	lsrs r6, r2, 24
	movs r7, 0
	bl sub_81B1250
	lsls r0, 24
	cmp r0, 0
	beq _081B8F2E
	ldr r0, =gBattleStruct
	lsls r1, r4, 1
	adds r1, r4
	adds r1, 0x60
	ldr r0, [r0]
	adds r4, r0, r1
	movs r2, 0
	add r6, sp
	mov r12, r6
	movs r6, 0xF
	mov r3, sp
_081B8EB2:
	adds r1, r4, r2
	ldrb r0, [r1]
	lsrs r0, 4
	strb r0, [r3]
	adds r3, 0x1
	ldrb r1, [r1]
	adds r0, r6, 0
	ands r0, r1
	strb r0, [r3]
	adds r3, 0x1
	adds r2, 0x1
	cmp r2, 0x2
	ble _081B8EB2
	mov r0, r12
	ldrb r3, [r0]
	movs r2, 0
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, r5
	bne _081B8EE8
	mov r0, sp
	ldrb r7, [r0]
	strb r3, [r0]
	b _081B8EFC
	.pool
_081B8EE8:
	adds r2, 0x1
	cmp r2, 0x5
	bgt _081B8EFC
	mov r0, sp
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, r5
	bne _081B8EE8
	adds r7, r0, 0
	strb r3, [r1]
_081B8EFC:
	cmp r2, 0x6
	beq _081B8F2E
	mov r0, r12
	strb r7, [r0]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, 4
	mov r1, sp
	ldrb r1, [r1, 0x1]
	orrs r0, r1
	strb r0, [r4]
	mov r0, sp
	ldrb r0, [r0, 0x2]
	lsls r0, 4
	mov r1, sp
	ldrb r1, [r1, 0x3]
	orrs r0, r1
	strb r0, [r4, 0x1]
	mov r0, sp
	ldrb r0, [r0, 0x4]
	lsls r0, 4
	mov r1, sp
	ldrb r1, [r1, 0x5]
	orrs r0, r1
	strb r0, [r4, 0x2]
_081B8F2E:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81B8E80

	thumb_func_start sub_81B8F38
sub_81B8F38: @ 81B8F38
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0x1
	ands r1, r2
	lsrs r2, r0, 25
	cmp r1, 0
	beq _081B8F58
	ldr r0, =gUnknown_0203CF00
	adds r0, r2, r0
	ldrb r0, [r0]
	movs r1, 0xF
	ands r1, r0
	b _081B8F60
	.pool
_081B8F58:
	ldr r0, =gUnknown_0203CF00
	adds r0, r2, r0
	ldrb r0, [r0]
	lsrs r1, r0, 4
_081B8F60:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81B8F38

	thumb_func_start sub_81B8F6C
sub_81B8F6C: @ 81B8F6C
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	movs r1, 0x1
	ands r1, r3
	lsrs r3, r0, 25
	cmp r1, 0
	beq _081B8F94
	ldr r0, =gUnknown_0203CF00
	adds r0, r3, r0
	ldrb r2, [r0]
	movs r1, 0xF0
	ands r1, r2
	orrs r1, r4
	strb r1, [r0]
	b _081B8FA4
	.pool
_081B8F94:
	ldr r2, =gUnknown_0203CF00
	adds r2, r3, r2
	ldrb r1, [r2]
	movs r0, 0xF
	ands r0, r1
	lsls r1, r4, 4
	orrs r0, r1
	strb r0, [r2]
_081B8FA4:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B8F6C

	thumb_func_start sub_81B8FB0
sub_81B8FB0: @ 81B8FB0
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	adds r0, r5, 0
	bl sub_81B8F38
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r6, 0
	bl sub_81B8F38
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl sub_81B8F6C
	adds r0, r6, 0
	adds r1, r4, 0
	bl sub_81B8F6C
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_81B8FB0

	thumb_func_start pokemon_order_func
pokemon_order_func: @ 81B8FEC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	movs r2, 0
	ldr r5, =gUnknown_0203CF00
_081B8FF8:
	adds r0, r3, r5
	ldrb r1, [r0]
	lsrs r0, r1, 4
	cmp r0, r4
	beq _081B9010
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	movs r0, 0xF
	ands r0, r1
	cmp r0, r4
	bne _081B9018
_081B9010:
	adds r0, r2, 0
	b _081B902A
	.pool
_081B9018:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x2
	bls _081B8FF8
	movs r0, 0
_081B902A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end pokemon_order_func

	thumb_func_start pokemon_change_order
pokemon_change_order: @ 81B9030
	push {r4-r6,lr}
	movs r4, 0x96
	lsls r4, 2
	adds r0, r4, 0
	bl Alloc
	adds r5, r0, 0
	ldr r1, =gPlayerParty
	adds r2, r4, 0
	bl memcpy
	movs r4, 0
	movs r6, 0x64
_081B904A:
	adds r0, r4, 0
	bl pokemon_order_func
	lsls r0, 24
	lsrs r0, 24
	muls r0, r6
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	muls r1, r6
	adds r1, r5
	movs r2, 0x64
	bl memcpy
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _081B904A
	adds r0, r5, 0
	bl Free
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end pokemon_change_order

	thumb_func_start sub_81B9080
sub_81B9080: @ 81B9080
	push {r4-r6,lr}
	movs r4, 0x96
	lsls r4, 2
	adds r0, r4, 0
	bl Alloc
	adds r5, r0, 0
	ldr r1, =gPlayerParty
	adds r2, r4, 0
	bl memcpy
	movs r4, 0
	movs r6, 0x64
_081B909A:
	adds r0, r4, 0
	bl sub_81B8F38
	lsls r0, 24
	lsrs r0, 24
	muls r0, r6
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	muls r1, r6
	adds r1, r5
	movs r2, 0x64
	bl memcpy
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _081B909A
	adds r0, r5, 0
	bl Free
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9080

	thumb_func_start sub_81B90D0
sub_81B90D0: @ 81B90D0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r6, 0x1
	movs r7, 0x64
	ldr r0, =gPlayerParty
	mov r8, r0
_081B90DE:
	adds r0, r6, 0
	bl sub_81B8F38
	lsls r0, 24
	lsrs r0, 24
	muls r0, r7
	mov r1, r8
	adds r5, r0, r1
	adds r0, r5, 0
	movs r1, 0xB
	bl GetMonData
	cmp r0, 0
	beq _081B912C
	adds r0, r5, 0
	movs r1, 0x39
	bl GetMonData
	cmp r0, 0
	beq _081B912C
	movs r0, 0
	bl sub_81B8F38
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	adds r1, r6, 0
	bl sub_81B8FB0
	adds r0, r4, 0
	muls r0, r7
	add r0, r8
	adds r1, r5, 0
	bl sub_81B1288
	b _081B9136
	.pool
_081B912C:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x5
	bls _081B90DE
_081B9136:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_81B90D0

	thumb_func_start sub_81B9140
sub_81B9140: @ 81B9140
	push {lr}
	ldr r0, =SetCB2ToReshowScreenAfterMenu
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9140

	thumb_func_start sub_81B9150
sub_81B9150: @ 81B9150
	push {lr}
	sub sp, 0xC
	movs r0, 0x7F
	str r0, [sp]
	ldr r0, =sub_81B917C
	str r0, [sp, 0x4]
	ldr r0, =gMain
	ldr r0, [r0, 0x8]
	str r0, [sp, 0x8]
	movs r0, 0x5
	movs r1, 0x3
	movs r2, 0
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9150

	thumb_func_start sub_81B917C
sub_81B917C: @ 81B917C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	adds r4, r1
	movs r1, 0x80
	lsls r1, 1
	strh r1, [r4, 0x8]
	bl sub_81B9294
	movs r1, 0x80
	lsls r1, 9
	movs r0, 0x2
	movs r2, 0
	bl ChangeBgX
	ldr r0, =sub_81B91B4
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B917C

	thumb_func_start sub_81B91B4
sub_81B91B4: @ 81B91B4
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r6, r5, 2
	adds r0, r6, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _081B9220
	ldrh r0, [r4]
	subs r0, 0x8
	strh r0, [r4]
	adds r0, r5, 0
	bl sub_81B9294
	movs r1, 0
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _081B9220
	movs r4, 0x3
	ldr r7, =gUnknown_02022FF8
_081B91E8:
	subs r0, r4, 0x3
	lsls r0, 5
	adds r0, r7
	ldrh r0, [r0]
	cmp r0, 0
	beq _081B9204
	ldr r0, =gUnknown_0203CEDC
	ldr r1, [r0]
	lsls r0, r4, 4
	adds r0, r1
	ldrb r0, [r0, 0x9]
	movs r1, 0
	bl sub_81B5B6C
_081B9204:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _081B91E8
	movs r0, 0x78
	bl PlaySE
	ldr r0, =gTasks
	adds r1, r6, r5
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_81B9240
	str r0, [r1]
_081B9220:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B91B4

	thumb_func_start sub_81B9240
sub_81B9240: @ 81B9240
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r0, r2, 2
	adds r0, r2
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r0, r1
	ldrh r1, [r0]
	adds r1, 0x1
	strh r1, [r0]
	lsls r1, 16
	movs r0, 0x80
	lsls r0, 17
	cmp r1, r0
	bne _081B9266
	adds r0, r2, 0
	bl sub_81B12C0
_081B9266:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9240

	thumb_func_start sub_81B9270
sub_81B9270: @ 81B9270
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 16
	lsrs r3, r1, 16
	cmp r1, 0
	blt _081B928A
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	strh r3, [r0, 0x24]
_081B928A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9270

	thumb_func_start sub_81B9294
sub_81B9294: @ 81B9294
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks + 0x8
	adds r5, r1, r0
	movs r6, 0x3
	ldr r7, =gUnknown_0203CEDC
_081B92A8:
	ldr r0, =gUnknown_02022FF8
	subs r1, r6, 0x3
	lsls r1, 5
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	beq _081B9300
	ldr r0, [r7]
	lsls r4, r6, 4
	adds r0, r4, r0
	ldrb r0, [r0, 0x9]
	ldrh r1, [r5]
	subs r1, 0x8
	lsls r1, 16
	asrs r1, 16
	bl sub_81B9270
	ldr r0, [r7]
	adds r0, r4, r0
	ldrb r0, [r0, 0xA]
	ldrh r1, [r5]
	subs r1, 0x8
	lsls r1, 16
	asrs r1, 16
	bl sub_81B9270
	ldr r0, [r7]
	adds r0, r4, r0
	ldrb r0, [r0, 0xB]
	ldrh r1, [r5]
	subs r1, 0x8
	lsls r1, 16
	asrs r1, 16
	bl sub_81B9270
	ldr r0, [r7]
	adds r4, r0
	ldrb r0, [r4, 0xC]
	ldrh r1, [r5]
	subs r1, 0x8
	lsls r1, 16
	asrs r1, 16
	bl sub_81B9270
_081B9300:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x5
	bls _081B92A8
	movs r1, 0x80
	lsls r1, 4
	movs r0, 0x2
	movs r2, 0x1
	bl ChangeBgX
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9294

	thumb_func_start sub_81B9328
sub_81B9328: @ 81B9328
	push {lr}
	sub sp, 0xC
	movs r0, 0xF
	str r0, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =sub_81B9390
	str r0, [sp, 0x8]
	movs r0, 0x6
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9328

	thumb_func_start sub_81B9354
sub_81B9354: @ 81B9354
	push {lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gFieldCallback2
	ldr r1, =hm_add_c3_without_phase_2
	str r1, [r2]
	movs r1, 0
	str r1, [sp]
	ldr r1, =sub_81B1370
	str r1, [sp, 0x4]
	ldr r1, =CB2_ReturnToField
	str r1, [sp, 0x8]
	movs r1, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81B0038
	add sp, 0xC
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9354

	thumb_func_start sub_81B9390
sub_81B9390: @ 81B9390
	push {r4,lr}
	ldr r4, =gSpecialVar_0x8004
	bl GetCursorSelectionMonId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	cmp r0, 0x5
	bls _081B93A6
	movs r0, 0xFF
	strh r0, [r4]
_081B93A6:
	ldr r0, =gFieldCallback2
	ldr r1, =hm_add_c3_without_phase_2
	str r1, [r0]
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9390

	thumb_func_start hm_add_c3_without_phase_2
hm_add_c3_without_phase_2: @ 81B93C8
	push {lr}
	bl pal_fill_black
	ldr r0, =task_hm_without_phase_2
	movs r1, 0xA
	bl CreateTask
	movs r0, 0x1
	pop {r1}
	bx r1
	.pool
	thumb_func_end hm_add_c3_without_phase_2

	thumb_func_start task_hm_without_phase_2
task_hm_without_phase_2: @ 81B93E0
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	bl IsWeatherNotFadingIn
	lsls r0, 24
	cmp r0, 0
	beq _081B93FE
	adds r0, r4, 0
	bl DestroyTask
	bl ScriptContext2_Disable
	bl EnableBothScriptContexts
_081B93FE:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end task_hm_without_phase_2

	thumb_func_start sub_81B9404
sub_81B9404: @ 81B9404
	push {lr}
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl FadeScreen
	ldr r0, =sub_81B9424
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9404

	thumb_func_start sub_81B9424
sub_81B9424: @ 81B9424
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081B945C
	bl overworld_free_bg_tilemaps
	str r4, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =sub_81B9470
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81B0038
	adds r0, r5, 0
	bl DestroyTask
_081B945C:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9424

	thumb_func_start sub_81B9470
sub_81B9470: @ 81B9470
	push {lr}
	bl GetCursorSelectionMonId
	ldr r2, =gUnknown_02039F24
	strb r0, [r2]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bls _081B9486
	movs r0, 0xFF
	strb r0, [r2]
_081B9486:
	ldr r1, =gSpecialVar_0x8004
	ldrb r0, [r2]
	strh r0, [r1]
	ldr r1, =gFieldCallback2
	ldr r0, =hm_add_c3_without_phase_2
	str r0, [r1]
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9470

	thumb_func_start sub_81B94B0
sub_81B94B0: @ 81B94B0
	push {lr}
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl FadeScreen
	ldr r0, =sub_81B94D0
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B94B0

	thumb_func_start sub_81B94D0
sub_81B94D0: @ 81B94D0
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081B9508
	bl overworld_free_bg_tilemaps
	str r4, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =sub_81B9390
	str r0, [sp, 0x8]
	movs r0, 0x3
	movs r1, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81B0038
	adds r0, r5, 0
	bl DestroyTask
_081B9508:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B94D0

	thumb_func_start sub_81B951C
sub_81B951C: @ 81B951C
	push {lr}
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl FadeScreen
	ldr r0, =sub_81B953C
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B951C

	thumb_func_start sub_81B953C
sub_81B953C: @ 81B953C
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081B9574
	bl overworld_free_bg_tilemaps
	str r4, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =sub_81B9588
	str r0, [sp, 0x8]
	movs r0, 0x7
	movs r1, 0
	movs r2, 0xB
	movs r3, 0
	bl sub_81B0038
	adds r0, r5, 0
	bl DestroyTask
_081B9574:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B953C

	thumb_func_start sub_81B9588
sub_81B9588: @ 81B9588
	push {r4,r5,lr}
	ldr r5, =gSpecialVar_0x8004
	bl GetCursorSelectionMonId
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5]
	cmp r0, 0x5
	bls _081B95A4
	movs r0, 0xFF
	strh r0, [r5]
	b _081B95BA
	.pool
_081B95A4:
	ldr r4, =gSpecialVar_0x8005
	ldrh r1, [r5]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	bl GetNumberOfRelearnableMoves
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
_081B95BA:
	ldr r0, =gFieldCallback2
	ldr r1, =hm_add_c3_without_phase_2
	str r1, [r0]
	ldr r0, =CB2_ReturnToField
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9588

	thumb_func_start sub_81B95E0
sub_81B95E0: @ 81B95E0
	push {r4,r5,lr}
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	movs r4, 0
	adds r5, r1, 0
	b _081B95FA
	.pool
_081B95F4:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_081B95FA:
	cmp r4, 0x2
	bhi _081B9614
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xC
	bl GetMonData
	cmp r0, 0
	beq _081B95F4
	movs r0, 0x1
	strh r0, [r5]
_081B9614:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B95E0

	thumb_func_start sub_81B9620
sub_81B9620: @ 81B9620
	push {lr}
	bl ScriptContext2_Enable
	movs r0, 0x1
	movs r1, 0
	bl FadeScreen
	ldr r0, =sub_81B9640
	movs r1, 0xA
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9620

	thumb_func_start sub_81B9640
sub_81B9640: @ 81B9640
	push {r4,r5,lr}
	sub sp, 0xC
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _081B9678
	bl overworld_free_bg_tilemaps
	str r4, [sp]
	ldr r0, =sub_81B1370
	str r0, [sp, 0x4]
	ldr r0, =sub_81B9390
	str r0, [sp, 0x8]
	movs r0, 0xC
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_81B0038
	adds r0, r5, 0
	bl DestroyTask
_081B9678:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9640

	thumb_func_start sub_81B968C
sub_81B968C: @ 81B968C
	push {lr}
	sub sp, 0x4
	ldr r1, =gPlayerParty
	ldr r0, =gSpecialVar_0x8004
	ldrb r2, [r0]
	ldr r0, =gPlayerPartyCount
	ldrb r3, [r0]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =CB2_ReturnToField
	str r0, [sp]
	movs r0, 0x3
	bl ShowPokemonSummaryScreen
	ldr r1, =gFieldCallback
	ldr r0, =sub_80AF168
	str r0, [r1]
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B968C

	thumb_func_start sub_81B96D0
sub_81B96D0: @ 81B96D0
	push {r4,r5,lr}
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	movs r4, 0
	adds r5, r1, 0
_081B96DC:
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	adds r1, r4, 0
	adds r1, 0xD
	bl GetMonData
	cmp r0, 0
	beq _081B96FA
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_081B96FA:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x3
	bls _081B96DC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B96D0

	thumb_func_start sub_81B9718
sub_81B9718: @ 81B9718
	push {r4,r5,lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	adds r5, r1, 0
	muls r5, r0
	ldr r0, =gPlayerParty
	adds r5, r0
	ldr r0, =gSpecialVar_0x8005
	ldrh r1, [r0]
	adds r1, 0xD
	adds r0, r5, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldr r1, =gStringVar1
	adds r0, r5, 0
	bl GetMonNickname
	ldr r0, =gStringVar2
	movs r1, 0xD
	muls r1, r4
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9718

	thumb_func_start sub_81B9770
sub_81B9770: @ 81B9770
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r0, =gSpecialVar_0x8004
	mov r8, r0
	ldrh r0, [r0]
	movs r6, 0x64
	muls r0, r6
	ldr r5, =gPlayerParty
	adds r0, r5
	ldr r4, =gSpecialVar_0x8005
	ldrb r2, [r4]
	movs r1, 0
	bl SetMonMoveSlot
	mov r1, r8
	ldrh r0, [r1]
	muls r0, r6
	adds r0, r5
	ldrb r1, [r4]
	bl RemoveMonPPBonus
	ldrh r4, [r4]
	cmp r4, 0x2
	bhi _081B97C4
_081B97A2:
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	lsls r1, r4, 24
	lsrs r1, 24
	adds r4, 0x1
	lsls r2, r4, 24
	lsrs r2, 24
	bl sub_81B97DC
	lsls r4, 16
	lsrs r4, 16
	cmp r4, 0x2
	bls _081B97A2
_081B97C4:
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9770

	thumb_func_start sub_81B97DC
sub_81B97DC: @ 81B97DC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	mov r8, r0
	adds r5, r1, 0
	adds r4, r2, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r0, 0xD
	str r0, [sp, 0x8]
	mov r0, r8
	ldr r1, [sp, 0x8]
	bl GetMonData
	mov r1, sp
	adds r1, 0x2
	str r1, [sp, 0x14]
	strh r0, [r1]
	adds r3, r4, 0
	adds r3, 0xD
	str r3, [sp, 0xC]
	mov r0, r8
	adds r1, r3, 0
	bl GetMonData
	mov r1, sp
	strh r0, [r1]
	adds r7, r5, 0
	adds r7, 0x11
	str r7, [sp, 0x10]
	mov r0, r8
	adds r1, r7, 0
	bl GetMonData
	mov r1, sp
	adds r1, 0x5
	str r1, [sp, 0x18]
	strb r0, [r1]
	adds r3, r4, 0
	adds r3, 0x11
	str r3, [sp, 0x1C]
	mov r0, r8
	adds r1, r3, 0
	bl GetMonData
	add r7, sp, 0x4
	mov r10, r7
	strb r0, [r7]
	mov r0, r8
	movs r1, 0x15
	bl GetMonData
	mov r6, sp
	adds r6, 0x6
	strb r0, [r6]
	ldr r1, =gUnknown_08329D22
	adds r0, r5, r1
	ldrb r0, [r0]
	mov r9, r0
	ldrb r0, [r6]
	adds r2, r0, 0
	mov r3, r9
	ands r2, r3
	lsls r5, 1
	asrs r2, r5
	lsls r2, 24
	lsrs r2, 24
	adds r1, r4, r1
	ldrb r3, [r1]
	adds r1, r0, 0
	ands r1, r3
	lsls r4, 1
	asrs r1, r4
	lsls r1, 24
	lsrs r1, 24
	mov r7, r9
	bics r0, r7
	strb r0, [r6]
	ldrb r0, [r6]
	bics r0, r3
	strb r0, [r6]
	lsls r2, r4
	lsls r1, r5
	adds r2, r1
	ldrb r0, [r6]
	orrs r0, r2
	strb r0, [r6]
	mov r0, r8
	ldr r1, [sp, 0x8]
	mov r2, sp
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, 0xC]
	ldr r2, [sp, 0x14]
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, 0x10]
	mov r2, r10
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, 0x1C]
	ldr r2, [sp, 0x18]
	bl SetMonData
	mov r0, r8
	movs r1, 0x15
	adds r2, r6, 0
	bl SetMonData
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B97DC

	thumb_func_start sub_81B98DC
sub_81B98DC: @ 81B98DC
	push {lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0x2D
	bl GetMonData
	adds r1, r0, 0
	cmp r1, 0
	beq _081B990C
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
	b _081B9910
	.pool
_081B990C:
	ldr r0, =gSpecialVar_Result
	strh r1, [r0]
_081B9910:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B98DC

	thumb_func_start sub_81B9918
sub_81B9918: @ 81B9918
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r1, =gSpecialVar_Result
	movs r0, 0
	strh r0, [r1]
	ldr r0, =gSpecialVar_0x8004
	ldrh r1, [r0]
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	ldr r1, =gSpecialVar_0x8005
	ldrh r1, [r1]
	adds r1, 0xD
	bl GetMonData
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	cmp r0, 0x39
	bne _081B999C
	movs r6, 0
	b _081B9980
	.pool
_081B9958:
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r6, r0
	beq _081B997E
	movs r4, 0
	movs r0, 0x64
	adds r5, r6, 0
	muls r5, r0
	ldr r7, =gPlayerParty
_081B996A:
	adds r1, r4, 0
	adds r1, 0xD
	adds r0, r5, r7
	bl GetMonData
	cmp r0, 0x39
	beq _081B999C
	adds r4, 0x1
	cmp r4, 0x3
	bls _081B996A
_081B997E:
	adds r6, 0x1
_081B9980:
	bl CalculatePlayerPartyCount
	lsls r0, 24
	lsrs r0, 24
	cmp r6, r0
	bcc _081B9958
	mov r0, r8
	bl sub_80D23A8
	cmp r0, 0x1
	beq _081B999C
	ldr r1, =gSpecialVar_Result
	movs r0, 0x1
	strh r0, [r1]
_081B999C:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81B9918

	.align 2, 0 @ Don't pad with nop.
