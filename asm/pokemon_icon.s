	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start CreateMonIcon
@ int CreateMonIcon(u16 speciesId, int a2, u16 a3, u16 a4, u8 a5, u32 personality, int a7)
CreateMonIcon: @ 80D2CC4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x30
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, [sp, 0x4C]
	ldr r1, [sp, 0x50]
	ldr r5, [sp, 0x54]
	lsls r4, 16
	lsrs r4, 16
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	lsls r3, 16
	lsrs r7, r3, 16
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r0, =sMonIconOamData
	str r0, [sp, 0x18]
	adds r0, r4, 0
	adds r2, r5, 0
	bl GetMonIconPtr
	str r0, [sp, 0x1C]
	ldr r0, =sMonIconAnims
	str r0, [sp, 0x20]
	ldr r0, =sMonIconAffineAnims
	str r0, [sp, 0x24]
	str r6, [sp, 0x28]
	ldr r0, =gMonIconPaletteIndices
	adds r0, r4, r0
	ldr r1, =0x0000dac0
	adds r5, r1, 0
	ldrb r0, [r0]
	adds r1, r5, r0
	add r0, sp, 0x2C
	strh r1, [r0]
	add r1, sp, 0x18
	mov r0, sp
	movs r2, 0x18
	bl memcpy
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	bls _080D2D2A
	mov r0, sp
	strh r5, [r0, 0x14]
_080D2D2A:
	mov r0, r8
	lsls r1, r0, 16
	asrs r1, 16
	lsls r2, r7, 16
	asrs r2, 16
	mov r0, sp
	mov r3, r9
	bl sub_80D31B4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80D30DC
	adds r0, r4, 0
	add sp, 0x30
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CreateMonIcon

	thumb_func_start sub_80D2D78
sub_80D2D78: @ 80D2D78
	push {r4-r7,lr}
	sub sp, 0x18
	adds r4, r2, 0
	adds r5, r3, 0
	ldr r6, [sp, 0x2C]
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 24
	lsrs r6, 24
	mov r3, sp
	ldr r2, =sMonIconOamData
	str r2, [sp]
	movs r2, 0
	str r2, [sp, 0x4]
	ldr r2, =sMonIconAnims
	str r2, [sp, 0x8]
	ldr r2, =sMonIconAffineAnims
	str r2, [sp, 0xC]
	str r1, [sp, 0x10]
	ldr r2, =gMonIconPaletteIndices
	adds r2, r0, r2
	ldr r7, =0x0000dac0
	adds r1, r7, 0
	ldrb r2, [r2]
	adds r1, r2
	strh r1, [r3, 0x14]
	ldr r1, [sp, 0x30]
	bl GetMonIconTiles
	str r0, [sp, 0x4]
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl sub_80D31B4
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl sub_80D30DC
	adds r0, r4, 0
	add sp, 0x18
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D2D78

	thumb_func_start mon_icon_convert_unown_species_id
@ u16 mon_icon_convert_unown_species_id(u16 speciesId, u32 personality)
mon_icon_convert_unown_species_id: @ 80D2E08
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0xC9
	bne _080D2E32
	adds r0, r1, 0
	bl GetUnownLetterByPersonality
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	bne _080D2E24
	movs r0, 0xC9
	b _080D2E2E
_080D2E24:
	movs r1, 0xCE
	lsls r1, 1
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
_080D2E2E:
	adds r1, r0, 0
	b _080D2E40
_080D2E32:
	movs r0, 0xCE
	lsls r0, 1
	adds r1, r2, 0
	cmp r1, r0
	bls _080D2E40
	movs r1, 0x82
	lsls r1, 1
_080D2E40:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end mon_icon_convert_unown_species_id

	thumb_func_start GetUnownLetterByPersonality
GetUnownLetterByPersonality: @ 80D2E48
	push {lr}
	adds r2, r0, 0
	cmp r2, 0
	beq _080D2E7E
	movs r0, 0xC0
	lsls r0, 18
	ands r0, r2
	lsrs r0, 18
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r2
	lsrs r1, 12
	orrs r0, r1
	movs r1, 0xC0
	lsls r1, 2
	ands r1, r2
	lsrs r1, 6
	orrs r0, r1
	movs r1, 0x3
	ands r1, r2
	orrs r0, r1
	movs r1, 0x1C
	bl __umodsi3
	lsls r0, 16
	lsrs r0, 16
	b _080D2E80
_080D2E7E:
	movs r0, 0
_080D2E80:
	pop {r1}
	bx r1
	thumb_func_end GetUnownLetterByPersonality

	thumb_func_start sub_80D2E84
sub_80D2E84: @ 80D2E84
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	mov r1, sp
	bl MailSpeciesToSpecies
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xC9
	bne _080D2EBA
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, 0
	bne _080D2EAA
	mov r1, sp
	adds r0, 0xC9
	b _080D2EB2
_080D2EAA:
	mov r1, sp
	movs r2, 0xCE
	lsls r2, 1
	adds r0, r2
_080D2EB2:
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	b _080D2ED2
_080D2EBA:
	movs r0, 0xCE
	lsls r0, 1
	cmp r4, r0
	bls _080D2EC6
	movs r4, 0x82
	lsls r4, 1
_080D2EC6:
	adds r0, r4, 0
	movs r1, 0
	bl mon_icon_convert_unown_species_id
	lsls r0, 16
	lsrs r0, 16
_080D2ED2:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80D2E84

	thumb_func_start GetMonIconPtr
@ void *GetMonIconPtr(u16 speciesId, u32 personality, bool32)
GetMonIconPtr: @ 80D2EDC
	push {r4,lr}
	adds r4, r2, 0
	lsls r0, 16
	lsrs r0, 16
	bl mon_icon_convert_unown_species_id
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl GetMonIconTiles
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetMonIconPtr

	thumb_func_start sub_80D2EF8
sub_80D2EF8: @ 80D2EF8
	push {lr}
	bl sub_80D328C
	pop {r0}
	bx r0
	thumb_func_end sub_80D2EF8

	thumb_func_start sub_80D2F04
sub_80D2F04: @ 80D2F04
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gMonIconPaletteTable
_080D2F0A:
	lsls r0, r4, 3
	adds r0, r5
	bl LoadSpritePalette
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _080D2F0A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2F04

	thumb_func_start sub_80D2F28
sub_80D2F28: @ 80D2F28
	push {r4,lr}
	lsls r0, 16
	lsrs r1, r0, 16
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	bls _080D2F3A
	movs r1, 0x82
	lsls r1, 1
_080D2F3A:
	ldr r0, =gMonIconPaletteIndices
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r1, =gMonIconPaletteTable
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080D2F5A
	adds r0, r4, 0
	bl LoadSpritePalette
_080D2F5A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2F28

	thumb_func_start sub_80D2F68
sub_80D2F68: @ 80D2F68
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gMonIconPaletteIndices
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gMonIconPaletteTable
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _080D2F8E
	adds r0, r4, 0
	bl LoadSpritePalette
_080D2F8E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2F68

	thumb_func_start sub_80D2F9C
sub_80D2F9C: @ 80D2F9C
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =gMonIconPaletteTable
_080D2FA2:
	lsls r0, r4, 3
	adds r0, r5
	ldrh r0, [r0, 0x4]
	bl FreeSpritePaletteByTag
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x5
	bls _080D2FA2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2F9C

	thumb_func_start sub_80D2FC0
sub_80D2FC0: @ 80D2FC0
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	bls _080D2FD2
	movs r1, 0x82
	lsls r1, 1
_080D2FD2:
	ldr r0, =gMonIconPaletteIndices
	adds r0, r1, r0
	ldrb r0, [r0]
	ldr r1, =gMonIconPaletteTable
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2FC0

	thumb_func_start sub_80D2FF0
sub_80D2FF0: @ 80D2FF0
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gMonIconPaletteIndices
	adds r0, r1
	ldrb r0, [r0]
	ldr r1, =gMonIconPaletteTable
	lsls r0, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
	bl FreeSpritePaletteByTag
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D2FF0

	thumb_func_start sub_80D3014
sub_80D3014: @ 80D3014
	push {lr}
	bl sub_80D30DC
	pop {r0}
	bx r0
	thumb_func_end sub_80D3014

	thumb_func_start GetMonIconTiles
@ void *GetMonIconTiles(u16 speciesId, bool32)
GetMonIconTiles: @ 80D3020
	push {lr}
	adds r3, r1, 0
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gMonIconTable
	lsls r1, r0, 2
	adds r1, r2
	ldr r2, [r1]
	movs r1, 0xCD
	lsls r1, 1
	cmp r0, r1
	bne _080D3042
	cmp r3, 0x1
	bne _080D3042
	movs r0, 0x80
	lsls r0, 3
	adds r2, r0
_080D3042:
	adds r0, r2, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetMonIconTiles

	thumb_func_start sub_80D304C
sub_80D304C: @ 80D304C
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0xA0
	bhi _080D3074
	ldr r6, =gMonIconPaletteTable
	movs r5, 0x5
_080D305A:
	ldr r0, [r6]
	adds r1, r4, 0
	movs r2, 0x20
	bl LoadPalette
	adds r0, r4, 0
	adds r0, 0x10
	lsls r0, 16
	lsrs r4, r0, 16
	adds r6, 0x8
	subs r5, 0x1
	cmp r5, 0
	bge _080D305A
_080D3074:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D304C

	thumb_func_start sub_80D3080
sub_80D3080: @ 80D3080
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	bls _080D3092
	movs r1, 0x82
	lsls r1, 1
_080D3092:
	ldr r0, =gMonIconPaletteIndices
	adds r0, r1, r0
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D3080

	thumb_func_start sub_80D30A0
sub_80D30A0: @ 80D30A0
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =gMonIconPaletteIndices
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_80D30A0

	thumb_func_start GetValidMonIconPalettePtr
GetValidMonIconPalettePtr: @ 80D30B0
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r0, 0xCE
	lsls r0, 1
	cmp r2, r0
	bls _080D30C2
	movs r2, 0x82
	lsls r2, 1
_080D30C2:
	ldr r1, =gMonIconPaletteTable
	ldr r0, =gMonIconPaletteIndices
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, 3
	adds r0, r1
	ldr r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetValidMonIconPalettePtr

	thumb_func_start sub_80D30DC
sub_80D30DC: @ 80D30DC
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	adds r4, r0, 0
	movs r7, 0
	adds r6, r4, 0
	adds r6, 0x2C
	ldrb r2, [r6]
	movs r0, 0x3F
	mov r9, r0
	ands r0, r2
	cmp r0, 0
	bne _080D3190
	movs r1, 0x2A
	adds r1, r4
	mov r8, r1
	ldrb r1, [r1]
	ldr r0, [r4, 0x8]
	lsls r1, 2
	adds r1, r0
	adds r5, r4, 0
	adds r5, 0x2B
	ldrb r0, [r5]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	movs r1, 0
	ldrsh r3, [r0, r1]
	movs r0, 0x2
	negs r0, r0
	cmp r3, r0
	beq _080D3126
	adds r0, 0x1
	cmp r3, r0
	bne _080D312A
	b _080D31A4
_080D3126:
	strb r7, [r5]
	b _080D31A4
_080D312A:
	ldr r2, =sSpriteImageSizes
	ldrb r1, [r4, 0x3]
	lsrs r1, 6
	lsls r1, 1
	ldrb r0, [r4, 0x1]
	lsrs r0, 6
	lsls r0, 3
	adds r1, r0
	adds r1, r2
	ldrh r2, [r1]
	adds r1, r2, 0
	muls r1, r3
	ldr r0, [r4, 0xC]
	adds r0, r1
	ldrh r1, [r4, 0x4]
	lsls r1, 22
	lsrs r1, 17
	ldr r3, =0x06010000
	adds r1, r3
	bl RequestSpriteCopy
	mov r0, r8
	ldrb r1, [r0]
	ldr r0, [r4, 0x8]
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r5]
	ldr r1, [r1]
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
	lsls r0, 10
	lsrs r0, 26
	mov r1, r9
	ands r1, r0
	ldrb r2, [r6]
	movs r0, 0x40
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r6]
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
	ldrb r7, [r5]
	b _080D31A4
	.pool
_080D3190:
	lsls r0, r2, 26
	lsrs r0, 26
	subs r0, 0x1
	movs r1, 0x3F
	ands r0, r1
	movs r1, 0x40
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r6]
_080D31A4:
	adds r0, r7, 0
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80D30DC

	thumb_func_start sub_80D31B4
sub_80D31B4: @ 80D31B4
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	sub sp, 0x38
	mov r9, r0
	adds r4, r1, 0
	adds r5, r2, 0
	mov r8, r3
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	mov r0, r8
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r0, 0
	str r0, [sp, 0x30]
	ldr r2, =sSpriteImageSizes
	mov r0, r9
	ldr r6, [r0]
	ldrb r1, [r6, 0x3]
	lsrs r1, 6
	lsls r1, 1
	ldrb r0, [r6, 0x1]
	lsrs r0, 6
	lsls r0, 3
	adds r1, r0
	adds r1, r2
	ldrh r2, [r1]
	ldr r1, =0xffff0000
	add r3, sp, 0x30
	ldr r0, [r3, 0x4]
	ands r0, r1
	orrs r0, r2
	str r0, [r3, 0x4]
	add r1, sp, 0x18
	ldr r0, =0x0000ffff
	strh r0, [r1]
	mov r0, r9
	ldrh r2, [r0, 0x14]
	mov r0, sp
	adds r0, 0x1A
	strh r2, [r0]
	str r6, [sp, 0x1C]
	mov r2, r9
	ldr r0, [r2, 0x8]
	str r0, [sp, 0x20]
	str r3, [sp, 0x24]
	ldr r0, [r2, 0xC]
	str r0, [sp, 0x28]
	ldr r0, [r2, 0x10]
	str r0, [sp, 0x2C]
	mov r0, sp
	movs r2, 0x18
	bl memcpy
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	mov r3, r8
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gSprites
	lsls r3, r0, 4
	adds r3, r0
	lsls r3, 2
	adds r4, r3, r6
	adds r5, r4, 0
	adds r5, 0x2C
	ldrb r1, [r5]
	movs r2, 0x40
	orrs r1, r2
	strb r1, [r5]
	adds r4, 0x3F
	ldrb r2, [r4]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r4]
	adds r6, 0xC
	adds r3, r6
	mov r2, r9
	ldr r1, [r2, 0x4]
	str r1, [r3]
	add sp, 0x38
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80D31B4

	thumb_func_start sub_80D328C
sub_80D328C: @ 80D328C
	push {lr}
	sub sp, 0x8
	movs r1, 0
	str r1, [sp]
	ldr r3, =sSpriteImageSizes
	ldrb r2, [r0, 0x3]
	lsrs r2, 6
	lsls r2, 1
	ldrb r1, [r0, 0x1]
	lsrs r1, 6
	lsls r1, 3
	adds r2, r1
	adds r2, r3
	ldrh r3, [r2]
	ldr r2, =0xffff0000
	ldr r1, [sp, 0x4]
	ands r1, r2
	orrs r1, r3
	str r1, [sp, 0x4]
	mov r1, sp
	str r1, [r0, 0xC]
	bl DestroySprite
	add sp, 0x8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80D328C

	thumb_func_start sub_80D32C8
sub_80D32C8: @ 80D32C8
	mov r12, r0
	adds r0, 0x2A
	movs r3, 0
	strb r1, [r0]
	mov r2, r12
	adds r2, 0x2C
	ldrb r1, [r2]
	movs r0, 0x40
	negs r0, r0
	ands r0, r1
	strb r0, [r2]
	mov r0, r12
	adds r0, 0x2B
	strb r3, [r0]
	bx lr
	thumb_func_end sub_80D32C8

	.align 2, 0 @ Don't pad with nop.
