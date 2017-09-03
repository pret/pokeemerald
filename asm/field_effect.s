	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start FieldEffectStart
@ u8 FieldEffectStart(u8 id)
FieldEffectStart: @ 80B5B18
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl FieldEffectActiveListAdd
	ldr r0, =gFieldEffectScriptPointers
	lsls r4, 2
	adds r4, r0
	ldr r0, [r4]
	str r0, [sp]
	add r4, sp, 0x4
	ldr r5, =gUnknown_0855C1F0
_080B5B36:
	ldr r0, [sp]
	ldrb r0, [r0]
	lsls r0, 2
	adds r0, r5
	ldr r2, [r0]
	mov r0, sp
	adds r1, r4, 0
	bl _call_via_r2
	lsls r0, 24
	cmp r0, 0
	bne _080B5B36
	ldr r0, [sp, 0x4]
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end FieldEffectStart

	thumb_func_start FieldEffectCmd_loadtiles
@ bool8 FieldEffectCmd_loadtiles(u8 **script, u8 *returnValue)
FieldEffectCmd_loadtiles: @ 80B5B60
	push {lr}
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	bl FieldEffectScript_LoadTiles
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end FieldEffectCmd_loadtiles

	thumb_func_start FieldEffectCmd_loadfadedpal
@ bool8 FieldEffectCmd_loadfadedpal(u8 **script, u8 *returnValue)
FieldEffectCmd_loadfadedpal: @ 80B5B74
	push {lr}
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	bl FieldEffectScript_LoadFadedPalette
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end FieldEffectCmd_loadfadedpal

	thumb_func_start FieldEffectCmd_loadpal
@ bool8 FieldEffectCmd_loadpal(u8 **script, u8 *returnValue)
FieldEffectCmd_loadpal: @ 80B5B88
	push {lr}
	ldr r1, [r0]
	adds r1, 0x1
	str r1, [r0]
	bl FieldEffectScript_LoadPalette
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end FieldEffectCmd_loadpal

	thumb_func_start FieldEffectCmd_callnative
@ bool8 FieldEffectCmd_callnative(u8 **script, u8 *returnValue)
FieldEffectCmd_callnative: @ 80B5B9C
	push {lr}
	ldr r2, [r0]
	adds r2, 0x1
	str r2, [r0]
	bl FieldEffectScript_CallNative
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end FieldEffectCmd_callnative

	thumb_func_start FieldEffectCmd_end
@ bool8 FieldEffectCmd_end(u8 **script, u8 *returnValue)
FieldEffectCmd_end: @ 80B5BB0
	movs r0, 0
	bx lr
	thumb_func_end FieldEffectCmd_end

	thumb_func_start FieldEffectCmd_loadgfx_callnative
@ bool8 FieldEffectCmd_loadgfx_callnative(u8 **script, u8 *returnValue)
FieldEffectCmd_loadgfx_callnative: @ 80B5BB4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	adds r0, r4, 0
	bl FieldEffectScript_LoadTiles
	adds r0, r4, 0
	bl FieldEffectScript_LoadFadedPalette
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldEffectScript_CallNative
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end FieldEffectCmd_loadgfx_callnative

	thumb_func_start FieldEffectCmd_loadtiles_callnative
@ bool8 FieldEffectCmd_loadtiles_callnative(u8 **script, u8 *returnValue)
FieldEffectCmd_loadtiles_callnative: @ 80B5BDC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	adds r0, r4, 0
	bl FieldEffectScript_LoadTiles
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldEffectScript_CallNative
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end FieldEffectCmd_loadtiles_callnative

	thumb_func_start FieldEffectCmd_loadfadedpal_callnative
@ bool8 FieldEffectCmd_loadfadedpal_callnative(u8 **script, u8 *returnValue)
FieldEffectCmd_loadfadedpal_callnative: @ 80B5C00
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, [r4]
	adds r0, 0x1
	str r0, [r4]
	adds r0, r4, 0
	bl FieldEffectScript_LoadFadedPalette
	adds r0, r4, 0
	adds r1, r5, 0
	bl FieldEffectScript_CallNative
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end FieldEffectCmd_loadfadedpal_callnative

	thumb_func_start FieldEffectScript_ReadWord
@ u32 FieldEffectScript_ReadWord(u8 **script)
FieldEffectScript_ReadWord: @ 80B5C24
	ldr r2, [r0]
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	adds r0, r1
	ldrb r1, [r2, 0x2]
	lsls r1, 16
	adds r0, r1
	ldrb r1, [r2, 0x3]
	lsls r1, 24
	adds r0, r1
	bx lr
	thumb_func_end FieldEffectScript_ReadWord

	thumb_func_start FieldEffectScript_LoadTiles
@ void FieldEffectScript_LoadTiles(u8 **script)
FieldEffectScript_LoadTiles: @ 80B5C3C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl FieldEffectScript_ReadWord
	adds r5, r0, 0
	ldrh r0, [r5, 0x6]
	bl GetSpriteTileStartByTag
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _080B5C5A
	adds r0, r5, 0
	bl LoadSpriteSheet
_080B5C5A:
	ldr r0, [r4]
	adds r0, 0x4
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldEffectScript_LoadTiles

	thumb_func_start FieldEffectScript_LoadFadedPalette
@ void FieldEffectScript_LoadFadedPalette(u8 **script)
FieldEffectScript_LoadFadedPalette: @ 80B5C6C
	push {r4,r5,lr}
	adds r5, r0, 0
	bl FieldEffectScript_ReadWord
	adds r4, r0, 0
	bl LoadSpritePalette
	ldrh r0, [r4, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	bl sub_80ABE18
	ldr r0, [r5]
	adds r0, 0x4
	str r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end FieldEffectScript_LoadFadedPalette

	thumb_func_start FieldEffectScript_LoadPalette
@ void FieldEffectScript_LoadPalette(u8 **script)
FieldEffectScript_LoadPalette: @ 80B5C94
	push {r4,lr}
	adds r4, r0, 0
	bl FieldEffectScript_ReadWord
	bl LoadSpritePalette
	ldr r0, [r4]
	adds r0, 0x4
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end FieldEffectScript_LoadPalette

	thumb_func_start FieldEffectScript_CallNative
@ void FieldEffectScript_CallNative(u8 **script, u8 *returnValue)
FieldEffectScript_CallNative: @ 80B5CAC
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl FieldEffectScript_ReadWord
	bl _call_via_r0
	str r0, [r5]
	ldr r0, [r4]
	adds r0, 0x4
	str r0, [r4]
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end FieldEffectScript_CallNative

	thumb_func_start FieldEffectFreeGraphicsResources
@ void FieldEffectFreeGraphicsResources(struct obj *object)
FieldEffectFreeGraphicsResources: @ 80B5CC8
	push {r4,r5,lr}
	adds r1, r0, 0
	adds r1, 0x40
	ldrh r5, [r1]
	ldrb r4, [r0, 0x5]
	lsrs r4, 4
	bl DestroySprite
	adds r0, r5, 0
	bl FieldEffectFreeTilesIfUnused
	adds r0, r4, 0
	bl FieldEffectFreePaletteIfUnused
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end FieldEffectFreeGraphicsResources

	thumb_func_start FieldEffectStop
@ void FieldEffectStop(struct obj *object, u8 id)
FieldEffectStop: @ 80B5CEC
	push {r4,lr}
	lsls r4, r1, 24
	lsrs r4, 24
	bl FieldEffectFreeGraphicsResources
	adds r0, r4, 0
	bl FieldEffectActiveListRemove
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end FieldEffectStop

	thumb_func_start FieldEffectFreeTilesIfUnused
@ void FieldEffectFreeTilesIfUnused(u16 tileRangeStart)
FieldEffectFreeTilesIfUnused: @ 80B5D04
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl GetSpriteTileTagByTileStart
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =0x0000ffff
	cmp r3, r0
	beq _080B5D58
	movs r2, 0
	ldr r5, =gSprites
_080B5D1E:
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r5
	adds r0, r1, 0
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	beq _080B5D48
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 25
	cmp r0, 0
	bge _080B5D48
	adds r0, r1, 0
	adds r0, 0x40
	ldrh r0, [r0]
	cmp r4, r0
	beq _080B5D58
_080B5D48:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3F
	bls _080B5D1E
	adds r0, r3, 0
	bl FreeSpriteTilesByTag
_080B5D58:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldEffectFreeTilesIfUnused

	thumb_func_start FieldEffectFreePaletteIfUnused
@ void FieldEffectFreePaletteIfUnused(u8 paletteSlot)
FieldEffectFreePaletteIfUnused: @ 80B5D68
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl GetSpritePaletteTagByPaletteNum
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _080B5DB0
	movs r2, 0
	ldr r6, =gSprites
	adds r3, r4, 0
_080B5D84:
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r1, r0, r6
	adds r0, r1, 0
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 31
	cmp r0, 0
	beq _080B5DA0
	ldrb r0, [r1, 0x5]
	lsrs r0, 4
	cmp r0, r3
	beq _080B5DB0
_080B5DA0:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3F
	bls _080B5D84
	adds r0, r5, 0
	bl FreeSpritePaletteByTag
_080B5DB0:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldEffectFreePaletteIfUnused

	thumb_func_start FieldEffectActiveListClear
@ void FieldEffectActiveListClear()
FieldEffectActiveListClear: @ 80B5DC0
	push {r4,lr}
	movs r2, 0
	ldr r4, =gUnknown_03000F58
	movs r3, 0xFF
_080B5DC8:
	adds r0, r2, r4
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1F
	bls _080B5DC8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FieldEffectActiveListClear

	thumb_func_start FieldEffectActiveListAdd
@ void FieldEffectActiveListAdd(u8 id)
FieldEffectActiveListAdd: @ 80B5DE4
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r4, =gUnknown_03000F58
_080B5DEE:
	adds r1, r2, r4
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _080B5E00
	strb r3, [r1]
	b _080B5E0A
	.pool
_080B5E00:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1F
	bls _080B5DEE
_080B5E0A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end FieldEffectActiveListAdd

	thumb_func_start FieldEffectActiveListRemove
@ void FieldEffectActiveListRemove(u8 id)
FieldEffectActiveListRemove: @ 80B5E10
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r4, =gUnknown_03000F58
	movs r5, 0xFF
_080B5E1C:
	adds r1, r2, r4
	ldrb r0, [r1]
	cmp r0, r3
	bne _080B5E30
	orrs r0, r5
	strb r0, [r1]
	b _080B5E3A
	.pool
_080B5E30:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1F
	bls _080B5E1C
_080B5E3A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end FieldEffectActiveListRemove

	thumb_func_start FieldEffectActiveListContains
@ void FieldEffectActiveListContains(u8 id)
FieldEffectActiveListContains: @ 80B5E40
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	movs r1, 0
	ldr r3, =gUnknown_03000F58
_080B5E4A:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _080B5E5C
	movs r0, 0x1
	b _080B5E68
	.pool
_080B5E5C:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1F
	bls _080B5E4A
	movs r0, 0
_080B5E68:
	pop {r1}
	bx r1
	thumb_func_end FieldEffectActiveListContains

	thumb_func_start sub_80B5E6C
sub_80B5E6C: @ 80B5E6C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x18
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	mov r9, r3
	ldr r7, [sp, 0x34]
	lsls r4, 24
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	lsrs r4, 21
	ldr r3, =gTrainerFrontPicPaletteTable
	mov r8, r3
	add r8, r4
	mov r0, r8
	adds r1, r7, 0
	bl LoadCompressedObjectPaletteOverrideBuffer
	ldr r0, =gTrainerFrontPicTable
	adds r4, r0
	adds r0, r4, 0
	adds r1, r7, 0
	bl LoadCompressedObjectPicOverrideBuffer
	mov r1, sp
	ldrh r0, [r4, 0x6]
	movs r2, 0
	strh r0, [r1]
	mov r3, r8
	ldrh r0, [r3, 0x4]
	strh r0, [r1, 0x2]
	ldr r0, =gNewGameBirchOamAttributes
	str r0, [sp, 0x4]
	ldr r0, =gDummySpriteAnimTable
	str r0, [sp, 0x8]
	str r2, [sp, 0xC]
	ldr r0, =gDummySpriteAffineAnimTable
	str r0, [sp, 0x10]
	ldr r0, =SpriteCallbackDummy
	str r0, [sp, 0x14]
	lsls r5, 16
	asrs r5, 16
	lsls r6, 16
	asrs r6, 16
	mov r0, sp
	adds r1, r5, 0
	adds r2, r6, 0
	mov r3, r9
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	add sp, 0x18
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B5E6C

	thumb_func_start sub_80B5F0C
sub_80B5F0C: @ 80B5F0C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r1, r2, 0
	lsls r4, 24
	lsls r5, 16
	lsrs r5, 16
	ldr r0, =gTrainerFrontPicTable
	lsrs r4, 21
	adds r0, r4, r0
	ldr r0, [r0]
	bl LZDecompressVram
	ldr r0, =gTrainerFrontPicPaletteTable
	adds r4, r0
	ldr r0, [r4]
	adds r1, r5, 0
	movs r2, 0x20
	bl LoadCompressedPalette
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B5F0C

	thumb_func_start AddNewGameBirchObject
AddNewGameBirchObject: @ 80B5F44
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 24
	lsrs r6, 24
	ldr r0, =gNewGameBirchObjectPaletteInfo
	bl LoadSpritePalette
	ldr r0, =gNewGameBirchObjectTemplate
	lsls r4, 16
	asrs r4, 16
	lsls r5, 16
	asrs r5, 16
	adds r1, r4, 0
	adds r2, r5, 0
	adds r3, r6, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddNewGameBirchObject

	thumb_func_start sub_80B5F84
sub_80B5F84: @ 80B5F84
	push {r4,r5,lr}
	sub sp, 0x10
	lsls r0, 16
	lsrs r0, 16
	movs r3, 0x80
	lsls r3, 8
	lsls r1, 16
	asrs r1, 16
	str r1, [sp]
	lsls r2, 16
	asrs r2, 16
	str r2, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	ldr r1, =gMonPaletteTable
	lsls r4, r0, 3
	adds r4, r1
	ldrh r1, [r4, 0x4]
	str r1, [sp, 0xC]
	movs r1, 0
	adds r2, r3, 0
	movs r3, 0x1
	bl sub_818D7D8
	lsls r0, 16
	lsrs r5, r0, 16
	ldrh r0, [r4, 0x4]
	bl IndexOfSpritePaletteTag
	adds r0, 0x10
	lsls r0, 24
	lsrs r0, 24
	bl sub_80AC3F8
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _080B5FDC
	lsls r0, r5, 24
	lsrs r0, 24
	b _080B5FDE
	.pool
_080B5FDC:
	movs r0, 0x40
_080B5FDE:
	add sp, 0x10
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B5F84

	thumb_func_start sub_80B5FE8
sub_80B5FE8: @ 80B5FE8
	push {r4-r6,lr}
	mov r6, r10
	mov r5, r9
	mov r4, r8
	push {r4-r6}
	sub sp, 0x10
	adds r6, r0, 0
	mov r9, r1
	mov r10, r2
	adds r4, r3, 0
	ldr r5, [sp, 0x2C]
	lsls r6, 16
	lsrs r6, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	adds r0, r6, 0
	bl sub_806E7CC
	mov r8, r0
	lsls r4, 16
	asrs r4, 16
	str r4, [sp]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	mov r1, r8
	ldrh r0, [r1, 0x4]
	str r0, [sp, 0xC]
	adds r0, r6, 0
	mov r1, r9
	mov r2, r10
	movs r3, 0x1
	bl sub_818D7D8
	lsls r0, 16
	lsrs r4, r0, 16
	mov r1, r8
	ldrh r0, [r1, 0x4]
	bl IndexOfSpritePaletteTag
	adds r0, 0x10
	lsls r0, 24
	lsrs r0, 24
	bl sub_80AC3F8
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _080B605C
	lsls r0, r4, 24
	lsrs r0, 24
	b _080B605E
	.pool
_080B605C:
	movs r0, 0x40
_080B605E:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80B5FE8

	thumb_func_start sub_80B6070
sub_80B6070: @ 80B6070
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	bl sub_80AC428
	ldrb r0, [r4, 0x1]
	lsls r0, 30
	cmp r0, 0
	beq _080B608E
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
_080B608E:
	adds r0, r5, 0
	bl sub_818D820
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80B6070

	thumb_func_start sub_80B609C
sub_80B609C: @ 80B609C
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 16
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r4, =gPlttBufferUnfaded
	lsrs r0, 15
	adds r4, r0, r4
	ldrh r4, [r4]
	movs r5, 0x1F
	mov r9, r5
	mov r8, r4
	mov r6, r8
	ands r6, r5
	mov r8, r6
	movs r6, 0xF8
	lsls r6, 2
	ands r6, r4
	lsrs r6, 5
	movs r5, 0xF8
	lsls r5, 7
	ands r4, r5
	lsrs r4, 10
	mov r7, r9
	mov r5, r8
	subs r7, r5
	mov r12, r7
	mov r7, r12
	muls r7, r1
	adds r1, r7, 0
	asrs r1, 4
	add r8, r1
	mov r5, r9
	subs r1, r5, r6
	muls r1, r2
	asrs r1, 4
	adds r6, r1
	subs r5, r4
	mov r9, r5
	mov r1, r9
	muls r1, r3
	asrs r1, 4
	adds r4, r1
	mov r7, r8
	lsls r7, 16
	lsls r6, 21
	orrs r6, r7
	lsls r4, 26
	orrs r4, r6
	lsrs r4, 16
	ldr r1, =gPlttBufferFaded
	adds r0, r1
	strh r4, [r0]
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B609C

	thumb_func_start sub_80B6128
sub_80B6128: @ 80B6128
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	lsls r0, 16
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	ldr r4, =gPlttBufferUnfaded
	lsrs r0, 15
	adds r4, r0, r4
	ldrh r4, [r4]
	movs r5, 0x1F
	mov r8, r5
	mov r6, r8
	ands r6, r4
	mov r8, r6
	movs r5, 0xF8
	lsls r5, 2
	ands r5, r4
	lsrs r5, 5
	movs r6, 0xF8
	lsls r6, 7
	ands r4, r6
	lsrs r4, 10
	mov r6, r8
	muls r6, r1
	adds r1, r6, 0
	asrs r1, 4
	mov r6, r8
	subs r6, r1
	adds r1, r5, 0
	muls r1, r2
	asrs r1, 4
	subs r5, r1
	adds r1, r4, 0
	muls r1, r3
	asrs r1, 4
	subs r4, r1
	lsls r6, 16
	lsls r5, 21
	orrs r5, r6
	lsls r4, 26
	orrs r4, r5
	lsrs r4, 16
	ldr r1, =gPlttBufferFaded
	adds r0, r1
	strh r4, [r0]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6128

	thumb_func_start sub_80B61A0
sub_80B61A0: @ 80B61A0
	push {r4,lr}
	bl calc_player_party_count
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80B61E4
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	strh r4, [r1, 0xA]
	movs r0, 0x5D
	strh r0, [r1, 0xC]
	movs r0, 0x24
	strh r0, [r1, 0xE]
	movs r0, 0x7C
	strh r0, [r1, 0x10]
	movs r0, 0x18
	strh r0, [r1, 0x12]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B61A0

	thumb_func_start sub_80B61E4
sub_80B61E4: @ 80B61E4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	ldr r2, =gUnknown_0855C364
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	lsls r0, 2
	adds r0, r2
	ldr r2, [r0]
	adds r0, r1, 0
	bl _call_via_r2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B61E4

	thumb_func_start sub_80B6214
sub_80B6214: @ 80B6214
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	movs r2, 0xC
	ldrsh r1, [r4, r2]
	movs r3, 0xE
	ldrsh r2, [r4, r3]
	movs r3, 0x1
	bl sub_80B646C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl sub_80B6850
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x16]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B6214

	thumb_func_start sub_80B6250
sub_80B6250: @ 80B6250
	push {r4,lr}
	adds r2, r0, 0
	ldr r3, =gSprites
	movs r1, 0x14
	ldrsh r0, [r2, r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	movs r4, 0x2E
	ldrsh r0, [r1, r4]
	cmp r0, 0x1
	ble _080B6282
	movs r0, 0x16
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r1, [r0, 0x2E]
	adds r1, 0x1
	strh r1, [r0, 0x2E]
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
_080B6282:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6250

	thumb_func_start sub_80B628C
sub_80B628C: @ 80B628C
	push {lr}
	adds r3, r0, 0
	ldr r2, =gSprites
	movs r0, 0x14
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2E
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	ble _080B62AC
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_080B62AC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B628C

	thumb_func_start sub_80B62B4
sub_80B62B4: @ 80B62B4
	push {lr}
	ldr r2, =gSprites
	movs r3, 0x14
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0x6
	ble _080B62E6
	adds r0, r1, 0
	bl DestroySprite
	movs r0, 0x19
	bl FieldEffectActiveListRemove
	ldr r0, =sub_80B61E4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B62E6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B62B4

	thumb_func_start sub_80B62F4
sub_80B62F4: @ 80B62F4
	push {r4,lr}
	bl calc_player_party_count
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80B6330
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	strh r4, [r1, 0xA]
	movs r0, 0x75
	strh r0, [r1, 0xC]
	movs r0, 0x34
	strh r0, [r1, 0xE]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B62F4

	thumb_func_start sub_80B6330
sub_80B6330: @ 80B6330
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r1, r0
	ldr r2, =gUnknown_0855C374
	movs r3, 0x8
	ldrsh r0, [r1, r3]
	lsls r0, 2
	adds r0, r2
	ldr r2, [r0]
	adds r0, r1, 0
	bl _call_via_r2
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6330

	thumb_func_start sub_80B6360
sub_80B6360: @ 80B6360
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	movs r2, 0xC
	ldrsh r1, [r4, r2]
	movs r3, 0xE
	ldrsh r2, [r4, r3]
	movs r3, 0
	bl sub_80B646C
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x14]
	ldr r0, =sub_80B6330
	bl FindTaskIdByFunc
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x78
	movs r2, 0x18
	movs r3, 0
	bl sub_80B68EC
	adds r0, r4, 0
	movs r1, 0x28
	movs r2, 0x8
	movs r3, 0x1
	bl sub_80B68EC
	adds r0, r4, 0
	movs r1, 0x48
	movs r2, 0x8
	movs r3, 0x1
	bl sub_80B68EC
	adds r0, r4, 0
	movs r1, 0xA8
	movs r2, 0x8
	movs r3, 0x1
	bl sub_80B68EC
	adds r0, r4, 0
	movs r1, 0xC8
	movs r2, 0x8
	movs r3, 0x1
	bl sub_80B68EC
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6360

	thumb_func_start sub_80B63D4
sub_80B63D4: @ 80B63D4
	push {lr}
	adds r3, r0, 0
	ldr r2, =gSprites
	movs r0, 0x14
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2E
	ldrsh r0, [r0, r1]
	cmp r0, 0x1
	ble _080B63FA
	ldrh r0, [r3, 0x26]
	adds r0, 0x1
	strh r0, [r3, 0x26]
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_080B63FA:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B63D4

	thumb_func_start sub_80B6404
sub_80B6404: @ 80B6404
	push {lr}
	adds r3, r0, 0
	ldr r2, =gSprites
	movs r0, 0x14
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2E
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	ble _080B6424
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_080B6424:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6404

	thumb_func_start sub_80B642C
sub_80B642C: @ 80B642C
	push {lr}
	ldr r2, =gSprites
	movs r3, 0x14
	ldrsh r1, [r0, r3]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0x6
	ble _080B645E
	adds r0, r1, 0
	bl DestroySprite
	movs r0, 0x3E
	bl FieldEffectActiveListRemove
	ldr r0, =sub_80B6330
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B645E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B642C

	thumb_func_start sub_80B646C
sub_80B646C: @ 80B646C
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	mov r8, r0
	adds r4, r1, 0
	adds r5, r2, 0
	adds r6, r3, 0
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	ldr r0, =sub_80B64C0
	bl CreateInvisibleSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r2, =gSprites
	adds r1, r2
	strh r4, [r1, 0x24]
	strh r5, [r1, 0x26]
	strh r6, [r1, 0x38]
	mov r2, r8
	strh r2, [r1, 0x3A]
	strh r0, [r1, 0x3C]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B646C

	thumb_func_start sub_80B64C0
sub_80B64C0: @ 80B64C0
	push {lr}
	ldr r2, =gUnknown_0855C384
	movs r3, 0x2E
	ldrsh r1, [r0, r3]
	lsls r1, 2
	adds r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B64C0

	thumb_func_start sub_80B64DC
sub_80B64DC: @ 80B64DC
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0x30]
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _080B64F4
	subs r0, r1, 0x1
	strh r0, [r4, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _080B6550
_080B64F4:
	movs r0, 0x19
	strh r0, [r4, 0x30]
	ldr r0, =gUnknown_0855C304
	ldr r1, =gUnknown_0855C3A4
	movs r2, 0x32
	ldrsh r3, [r4, r2]
	lsls r3, 2
	adds r3, r1
	ldrh r1, [r4, 0x24]
	ldrh r2, [r3]
	adds r1, r2
	lsls r1, 16
	asrs r1, 16
	ldrh r2, [r4, 0x26]
	ldrh r3, [r3, 0x2]
	adds r2, r3
	lsls r2, 16
	asrs r2, 16
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldrh r0, [r4, 0x3C]
	strh r0, [r1, 0x2E]
	ldrh r0, [r4, 0x32]
	adds r0, 0x1
	strh r0, [r4, 0x32]
	ldrh r0, [r4, 0x3A]
	subs r0, 0x1
	strh r0, [r4, 0x3A]
	movs r0, 0x17
	bl PlaySE
_080B6550:
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B6562
	movs r0, 0x20
	strh r0, [r4, 0x30]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080B6562:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B64DC

	thumb_func_start sub_80B6574
sub_80B6574: @ 80B6574
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	subs r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	asrs r2, r0, 16
	cmp r2, 0
	bne _080B65A4
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	movs r0, 0x8
	strh r0, [r1, 0x30]
	strh r2, [r1, 0x32]
	strh r2, [r1, 0x34]
	movs r2, 0x38
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080B65A4
	movs r0, 0xB8
	lsls r0, 1
	bl PlayFanfare
_080B65A4:
	pop {r0}
	bx r0
	thumb_func_end sub_80B6574

	thumb_func_start sub_80B65A8
sub_80B65A8: @ 80B65A8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	ldrh r0, [r7, 0x30]
	subs r0, 0x1
	strh r0, [r7, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _080B65D8
	movs r0, 0x8
	strh r0, [r7, 0x30]
	ldrh r0, [r7, 0x32]
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	strh r0, [r7, 0x32]
	cmp r0, 0
	bne _080B65D8
	ldrh r0, [r7, 0x34]
	adds r0, 0x1
	strh r0, [r7, 0x34]
_080B65D8:
	ldrh r4, [r7, 0x32]
	adds r4, 0x3
	movs r0, 0x3
	mov r8, r0
	mov r1, r8
	ands r4, r1
	ldr r3, =0x00001007
	mov r10, r3
	mov r0, r10
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	movs r1, 0x84
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	ldr r6, =gUnknown_0855C3BC
	adds r1, r4, r6
	ldrb r1, [r1]
	ldr r5, =gUnknown_0855C3C0
	adds r2, r4, r5
	ldrb r2, [r2]
	ldr r3, =gUnknown_0855C3C4
	mov r9, r3
	add r4, r9
	ldrb r3, [r4]
	bl sub_80B609C
	ldrh r4, [r7, 0x32]
	adds r4, 0x2
	mov r0, r8
	ands r4, r0
	mov r0, r10
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	movs r1, 0x83
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	adds r1, r4, r6
	ldrb r1, [r1]
	adds r2, r4, r5
	ldrb r2, [r2]
	add r4, r9
	ldrb r3, [r4]
	bl sub_80B609C
	ldrh r4, [r7, 0x32]
	adds r4, 0x1
	mov r3, r8
	ands r4, r3
	mov r0, r10
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	movs r1, 0x81
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	adds r1, r4, r6
	ldrb r1, [r1]
	adds r2, r4, r5
	ldrb r2, [r2]
	add r4, r9
	ldrb r3, [r4]
	bl sub_80B609C
	ldrh r4, [r7, 0x32]
	lsls r4, 24
	lsrs r4, 24
	mov r0, r10
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	ldr r3, =0x01050000
	adds r0, r3
	lsrs r0, 16
	adds r6, r4, r6
	ldrb r6, [r6]
	adds r5, r4, r5
	ldrb r5, [r5]
	add r4, r9
	ldrb r4, [r4]
	adds r1, r6, 0
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_80B609C
	mov r0, r10
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	ldr r1, =0x01030000
	adds r0, r1
	lsrs r0, 16
	adds r1, r6, 0
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_80B609C
	movs r3, 0x34
	ldrsh r0, [r7, r3]
	cmp r0, 0x2
	ble _080B66C2
	ldrh r0, [r7, 0x2E]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r7, 0x2E]
	movs r0, 0x8
	strh r0, [r7, 0x30]
	strh r1, [r7, 0x32]
_080B66C2:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B65A8

	thumb_func_start sub_80B66E8
sub_80B66E8: @ 80B66E8
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	subs r0, 0x1
	strh r0, [r2, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _080B6718
	movs r0, 0x8
	strh r0, [r2, 0x30]
	ldrh r0, [r2, 0x32]
	adds r0, 0x1
	movs r1, 0x3
	ands r0, r1
	strh r0, [r2, 0x32]
	cmp r0, 0x3
	bne _080B6718
	ldrh r0, [r2, 0x2E]
	adds r0, 0x1
	strh r0, [r2, 0x2E]
	movs r0, 0x1E
	strh r0, [r2, 0x30]
_080B6718:
	ldrh r4, [r2, 0x32]
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =0x00001007
	mov r8, r0
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	movs r1, 0x84
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	ldr r1, =gUnknown_0855C3BC
	adds r1, r4, r1
	ldrb r6, [r1]
	ldr r1, =gUnknown_0855C3C0
	adds r1, r4, r1
	ldrb r5, [r1]
	ldr r1, =gUnknown_0855C3C4
	adds r4, r1
	ldrb r4, [r4]
	adds r1, r6, 0
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_80B609C
	mov r0, r8
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	movs r1, 0x83
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	adds r1, r6, 0
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_80B609C
	mov r0, r8
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	movs r1, 0x81
	lsls r1, 17
	adds r0, r1
	lsrs r0, 16
	adds r1, r6, 0
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_80B609C
	mov r0, r8
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	ldr r1, =0x01050000
	adds r0, r1
	lsrs r0, 16
	adds r1, r6, 0
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_80B609C
	mov r0, r8
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 4
	ldr r1, =0x01030000
	adds r0, r1
	lsrs r0, 16
	adds r1, r6, 0
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_80B609C
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B66E8

	thumb_func_start sub_80B67DC
sub_80B67DC: @ 80B67DC
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	subs r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _080B67F2
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
_080B67F2:
	pop {r0}
	bx r0
	thumb_func_end sub_80B67DC

	thumb_func_start sub_80B67F8
sub_80B67F8: @ 80B67F8
	ldrh r1, [r0, 0x2E]
	adds r1, 0x1
	strh r1, [r0, 0x2E]
	bx lr
	thumb_func_end sub_80B67F8

	thumb_func_start sub_80B6800
sub_80B6800: @ 80B6800
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x38
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080B6816
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _080B681C
_080B6816:
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
_080B681C:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B6800

	thumb_func_start nullsub_97
nullsub_97: @ 80B6824
	bx lr
	thumb_func_end nullsub_97

	thumb_func_start sub_80B6828
sub_80B6828: @ 80B6828
	push {lr}
	adds r3, r0, 0
	ldr r2, =gSprites
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x2E
	ldrsh r0, [r0, r1]
	cmp r0, 0x4
	ble _080B6848
	adds r0, r3, 0
	bl FieldEffectFreeGraphicsResources
_080B6848:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6828

	thumb_func_start sub_80B6850
sub_80B6850: @ 80B6850
	push {r4,lr}
	adds r3, r0, 0
	adds r2, r1, 0
	ldr r0, =gUnknown_0855C31C
	lsls r3, 16
	asrs r3, 16
	lsls r2, 16
	asrs r2, 16
	adds r1, r3, 0
	movs r3, 0
	bl CreateSpriteAtEnd
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	movs r2, 0x8
	orrs r1, r2
	strb r1, [r0, 0x5]
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r3]
	ldr r1, =gUnknown_0855C2AC
	bl SetSubspriteTables
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B6850

	thumb_func_start sub_80B68AC
sub_80B68AC: @ 80B68AC
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080B68D0
	movs r0, 0
	strh r0, [r4, 0x2E]
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r1, [r2]
	subs r0, 0x5
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAnim
_080B68D0:
	adds r0, r4, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080B68E4
	adds r0, r4, 0
	bl FieldEffectFreeGraphicsResources
_080B68E4:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B68AC

	thumb_func_start sub_80B68EC
sub_80B68EC: @ 80B68EC
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 16
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 24
	cmp r3, 0
	bne _080B6934
	ldr r0, =gUnknown_0855C334
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldr r1, =gUnknown_0855C2C4
	bl SetSubspriteTables
	b _080B6948
	.pool
_080B6934:
	ldr r0, =gUnknown_0855C34C
	lsls r1, 16
	asrs r1, 16
	lsls r2, 16
	asrs r2, 16
	movs r3, 0
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r4, r0, 24
_080B6948:
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	adds r3, r0, 0
	adds r3, 0x3E
	ldrb r1, [r3]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r3]
	strh r5, [r0, 0x2E]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B68EC

	thumb_func_start sub_80B6970
sub_80B6970: @ 80B6970
	push {lr}
	adds r3, r0, 0
	ldr r2, =gTasks
	movs r0, 0x2E
	ldrsh r1, [r3, r0]
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r1, 0x26
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080B69C6
	ldrh r1, [r3, 0x30]
	movs r2, 0x30
	ldrsh r0, [r3, r2]
	cmp r0, 0
	beq _080B699E
	subs r0, r1, 0x1
	strh r0, [r3, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _080B69C0
_080B699E:
	movs r0, 0x10
	strh r0, [r3, 0x30]
	movs r0, 0x3E
	adds r0, r3
	mov r12, r0
	ldrb r2, [r0]
	lsls r0, r2, 29
	lsrs r0, 31
	movs r1, 0x1
	eors r1, r0
	lsls r1, 2
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	mov r1, r12
	strb r0, [r1]
_080B69C0:
	ldrh r0, [r3, 0x32]
	adds r0, 0x1
	strh r0, [r3, 0x32]
_080B69C6:
	movs r2, 0x32
	ldrsh r0, [r3, r2]
	cmp r0, 0x7F
	ble _080B69D4
	adds r0, r3, 0
	bl FieldEffectFreeGraphicsResources
_080B69D4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6970

	thumb_func_start sub_80B69DC
sub_80B69DC: @ 80B69DC
	push {lr}
	ldr r0, =c2_exit_to_overworld_2_switch
	bl SetMainCallback2
	ldr r1, =gUnknown_03005DAC
	ldr r0, =mapldr_080842E8
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B69DC

	thumb_func_start mapldr_080842E8
mapldr_080842E8: @ 80B69FC
	push {lr}
	bl pal_fill_black
	ldr r0, =task00_8084310
	movs r1, 0
	bl CreateTask
	bl script_env_2_enable
	bl player_bitmagic
	ldr r1, =gUnknown_03005DAC
	movs r0, 0
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapldr_080842E8

	thumb_func_start task00_8084310
task00_8084310: @ 80B6A24
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r0, 0x8
	ldrsh r6, [r4, r0]
	cmp r6, 0
	bne _080B6A64
	bl sub_80ABDFC
	lsls r0, 24
	cmp r0, 0
	beq _080B6A8A
	bl brm_get_pokemon_selection
	ldr r1, =gUnknown_02038C08
	lsls r0, 24
	lsrs r0, 24
	str r0, [r1]
	cmp r0, 0x5
	ble _080B6A58
	str r6, [r1]
_080B6A58:
	movs r0, 0x1F
	bl FieldEffectStart
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B6A64:
	movs r0, 0x1F
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080B6A8A
	bl flag_var_implications_of_teleport_
	bl warp_in
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	ldr r1, =gUnknown_03005DAC
	ldr r0, =mapldr_08084390
	str r0, [r1]
	adds r0, r5, 0
	bl DestroyTask
_080B6A8A:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task00_8084310

	thumb_func_start mapldr_08084390
mapldr_08084390: @ 80B6AA4
	push {r4,lr}
	bl sub_8085784
	bl pal_fill_black
	ldr r0, =c3_080843F8
	movs r1, 0
	bl CreateTask
	ldr r4, =gUnknown_02037350
	ldr r3, =gUnknown_02037590
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	ldrb r1, [r0, 0x1]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x1]
	ldrb r1, [r3]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080B6AE6
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r4
	movs r1, 0x3
	bl FieldObjectTurn
_080B6AE6:
	bl script_env_2_enable
	bl player_bitmagic
	ldr r1, =gUnknown_03005DAC
	movs r0, 0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapldr_08084390

	thumb_func_start c3_080843F8
c3_080843F8: @ 80B6B0C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks
	adds r4, r0, r1
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B6B3E
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080B6B58
	movs r0, 0x20
	bl FieldEffectStart
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B6B3E:
	movs r0, 0x20
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080B6B58
	bl script_env_2_disable
	bl sub_809757C
	adds r0, r5, 0
	bl DestroyTask
_080B6B58:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_080843F8

	thumb_func_start sub_80B6B68
sub_80B6B68: @ 80B6B68
	push {lr}
	bl sub_8085784
	bl pal_fill_for_maplights
	bl script_env_2_enable
	bl player_bitmagic
	ldr r0, =sub_80B6B94
	movs r1, 0
	bl CreateTask
	ldr r1, =gUnknown_03005DAC
	movs r0, 0
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6B68

	thumb_func_start sub_80B6B94
sub_80B6B94: @ 80B6B94
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r5, =gUnknown_0855C3C8
_080B6BA6:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _080B6BA6
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6B94

	thumb_func_start sub_80B6BCC
sub_80B6BCC: @ 80B6BCC
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	mov r9, r0
	ldr r6, =gUnknown_02037590
	ldrb r0, [r6, 0x5]
	lsls r5, r0, 3
	adds r5, r0
	lsls r5, 2
	ldr r0, =gUnknown_02037350
	mov r8, r0
	add r5, r8
	ldrb r0, [r6, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	bl CameraObjectReset2
	ldrb r1, [r6, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r8
	ldrb r1, [r0, 0x1]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x1]
	movs r0, 0x1
	strb r0, [r6, 0x6]
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	bl GetFaceDirectionAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl FieldObjectSetSpecialAnim
	adds r3, r4, 0
	adds r3, 0x42
	ldrb r0, [r3]
	lsrs r0, 6
	mov r1, r9
	strh r0, [r1, 0x10]
	ldrb r0, [r5, 0x3]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r5, 0x3]
	ldrb r1, [r4, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, 0x5]
	ldrb r1, [r3]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3]
	mov r1, r9
	ldrh r0, [r1, 0x8]
	adds r0, 0x1
	strh r0, [r1, 0x8]
	movs r0, 0x1
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B6BCC

	thumb_func_start sub_80B6C74
sub_80B6C74: @ 80B6C74
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80ABDFC
	lsls r0, 24
	cmp r0, 0
	beq _080B6C88
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B6C88:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B6C74

	thumb_func_start sub_80B6C90
sub_80B6C90: @ 80B6C90
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gUnknown_02037590
	ldrb r0, [r6, 0x4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r0, r2, 0
	adds r0, 0x29
	movs r4, 0
	ldrsb r4, [r0, r4]
	lsls r0, r4, 17
	negs r0, r0
	ldrh r1, [r2, 0x22]
	ldr r3, =gSpriteCoordOffsetY
	adds r1, r4
	ldrh r3, [r3]
	adds r1, r3
	asrs r0, 16
	adds r0, r1
	negs r0, r0
	movs r1, 0
	strh r0, [r2, 0x26]
	movs r0, 0x1
	strh r0, [r5, 0xA]
	strh r1, [r5, 0xC]
	ldr r2, =gUnknown_02037350
	ldrb r0, [r6, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r2, [r1, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x1]
	movs r0, 0x2B
	bl PlaySE
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B6C90

	thumb_func_start sub_80B6D04
sub_80B6D04: @ 80B6D04
	push {r4-r6,lr}
	adds r4, r0, 0
	ldr r2, =gUnknown_02037590
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r6, r0, r1
	ldrb r1, [r2, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r5, r0, r1
	ldrh r0, [r4, 0xA]
	ldrh r1, [r5, 0x26]
	adds r0, r1
	strh r0, [r5, 0x26]
	ldrh r2, [r4, 0xA]
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	bgt _080B6D46
	ldrh r1, [r4, 0xC]
	adds r0, r2, r1
	strh r0, [r4, 0xC]
	movs r1, 0xF
	ands r0, r1
	cmp r0, 0
	beq _080B6D46
	lsls r0, r2, 1
	strh r0, [r4, 0xA]
_080B6D46:
	ldrh r2, [r4, 0xE]
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B6D84
	movs r0, 0x26
	ldrsh r1, [r5, r0]
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	blt _080B6D84
	adds r0, r2, 0x1
	strh r0, [r4, 0xE]
	ldrb r1, [r6, 0x3]
	movs r0, 0x5
	negs r0, r0
	ands r0, r1
	strb r0, [r6, 0x3]
	ldrb r1, [r4, 0x10]
	adds r3, r5, 0
	adds r3, 0x42
	lsls r1, 6
	ldrb r2, [r3]
	movs r0, 0x3F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrb r0, [r6]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r6]
_080B6D84:
	movs r1, 0x26
	ldrsh r0, [r5, r1]
	cmp r0, 0
	blt _080B6DA8
	movs r0, 0xD6
	bl PlaySE
	ldrb r0, [r6]
	movs r1, 0x8
	orrs r0, r1
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r6]
	movs r0, 0
	strh r0, [r5, 0x26]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B6DA8:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B6D04

	thumb_func_start sub_80B6DBC
sub_80B6DBC: @ 80B6DBC
	push {lr}
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	movs r2, 0
	strh r1, [r0, 0x8]
	movs r1, 0x4
	strh r1, [r0, 0xA]
	strh r2, [r0, 0xC]
	movs r0, 0
	bl SetCameraPanningCallback
	movs r0, 0x1
	pop {r1}
	bx r1
	thumb_func_end sub_80B6DBC

	thumb_func_start sub_80B6DD8
sub_80B6DD8: @ 80B6DD8
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0
	bl SetCameraPanning
	ldrh r0, [r4, 0xA]
	negs r2, r0
	strh r2, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _080B6E00
	lsls r0, r2, 16
	asrs r0, 17
	strh r0, [r4, 0xA]
_080B6E00:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B6E0E
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B6E0E:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B6DD8

	thumb_func_start sub_80B6E18
sub_80B6E18: @ 80B6E18
	push {lr}
	ldr r1, =gUnknown_02037590
	movs r0, 0
	strb r0, [r1, 0x6]
	bl script_env_2_disable
	bl CameraObjectReset1
	bl sub_809757C
	bl InstallCameraPanAheadCallback
	ldr r0, =sub_80B6B94
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B6E18

	thumb_func_start sub_80B6E4C
sub_80B6E4C: @ 80B6E4C
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =sub_80B6E88
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0
	strh r0, [r1, 0xA]
	cmp r4, 0x6A
	bne _080B6E78
	movs r0, 0x1
	strh r0, [r1, 0xA]
_080B6E78:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6E4C

	thumb_func_start sub_80B6E88
sub_80B6E88: @ 80B6E88
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r5, =gUnknown_0855C3E4
_080B6E9A:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _080B6E9A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6E88

	thumb_func_start sub_80B6EC0
sub_80B6EC0: @ 80B6EC0
	push {r4,lr}
	adds r4, r0, 0
	bl player_bitmagic
	bl CameraObjectReset2
	ldrb r0, [r4, 0xA]
	bl sub_80E1558
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B6EC0

	thumb_func_start sub_80B6EE0
sub_80B6EE0: @ 80B6EE0
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B6F0A
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B6F3E
_080B6F0A:
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	bl GetFaceDirectionAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	movs r1, 0
	strh r0, [r5, 0x8]
	strh r1, [r5, 0xC]
	strh r1, [r5, 0xE]
	ldrb r0, [r5, 0xA]
	cmp r0, 0
	bne _080B6F38
	movs r0, 0x4
	strh r0, [r5, 0x8]
_080B6F38:
	movs r0, 0x50
	bl PlaySE
_080B6F3E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B6EE0

	thumb_func_start sub_80B6F50
sub_80B6F50: @ 80B6F50
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80B6FB8
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	ble _080B6F6A
	bl sub_80B7050
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B6F6A:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B6F50

	thumb_func_start sub_80B6F74
sub_80B6F74: @ 80B6F74
	push {lr}
	bl sub_80B6FB8
	bl sub_80B7060
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80B6F74

	thumb_func_start sub_80B6F84
sub_80B6F84: @ 80B6F84
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80B7004
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x3
	ble _080B6F9E
	bl sub_80B7050
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B6F9E:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B6F84

	thumb_func_start sub_80B6FA8
sub_80B6FA8: @ 80B6FA8
	push {lr}
	bl sub_80B7004
	bl sub_80B7060
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80B6FA8

	thumb_func_start sub_80B6FB8
sub_80B6FB8: @ 80B6FB8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	movs r0, 0x84
	bl Cos
	strh r0, [r4, 0x24]
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	movs r0, 0x94
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r5, 0xE]
	adds r0, 0x1
	strh r0, [r5, 0xE]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B6FF6
	ldrh r0, [r5, 0xC]
	adds r0, 0x1
	strh r0, [r5, 0xC]
_080B6FF6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B6FB8

	thumb_func_start sub_80B7004
sub_80B7004: @ 80B7004
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	movs r0, 0x7C
	bl Cos
	strh r0, [r4, 0x24]
	movs r0, 0xC
	ldrsh r1, [r5, r0]
	movs r0, 0x76
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r5, 0xE]
	adds r0, 0x1
	strh r0, [r5, 0xE]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B7042
	ldrh r0, [r5, 0xC]
	adds r0, 0x1
	strh r0, [r5, 0xC]
_080B7042:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7004

	thumb_func_start sub_80B7050
sub_80B7050: @ 80B7050
	push {lr}
	bl music_something
	bl sub_80AF0B4
	pop {r0}
	bx r0
	thumb_func_end sub_80B7050

	thumb_func_start sub_80B7060
sub_80B7060: @ 80B7060
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080B709C
	bl sub_80859A0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B709C
	bl sub_80E1570
	bl warp_in
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80B70B4
	str r0, [r1]
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	ldr r0, =sub_80B6E88
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B709C:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7060

	thumb_func_start sub_80B70B4
sub_80B70B4: @ 80B70B4
	push {lr}
	bl sub_8085784
	bl pal_fill_for_maplights
	bl script_env_2_enable
	ldr r0, =sub_80B70DC
	movs r1, 0
	bl CreateTask
	ldr r1, =gUnknown_03005DAC
	movs r0, 0
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B70B4

	thumb_func_start sub_80B70DC
sub_80B70DC: @ 80B70DC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	ldr r0, =gTasks
	adds r4, r1, r0
	ldr r5, =gUnknown_0855C3FC
_080B70EE:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _080B70EE
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B70DC

	thumb_func_start sub_80B7114
sub_80B7114: @ 80B7114
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	bl CameraObjectReset2
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gUnknown_02037350
	adds r4, r0
	movs r0, 0x4
	bl GetFaceDirectionAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	mov r4, sp
	adds r4, 0x2
	mov r0, sp
	adds r1, r4, 0
	bl PlayerGetDestCoords
	mov r0, sp
	movs r1, 0
	ldrsh r0, [r0, r1]
	movs r2, 0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r1, r0, 24
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x10
	strh r0, [r5, 0xA]
	cmp r1, 0x6B
	bne _080B717C
	movs r1, 0x1
	movs r0, 0x3
	strh r0, [r5, 0x8]
	b _080B717E
	.pool
_080B717C:
	movs r1, 0
_080B717E:
	adds r0, r1, 0
	bl sub_80E1558
	movs r0, 0x1
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B7114

	thumb_func_start sub_80B7190
sub_80B7190: @ 80B7190
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	movs r0, 0x84
	bl Cos
	strh r0, [r4, 0x24]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	movs r0, 0x94
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B7190

	thumb_func_start sub_80B71D0
sub_80B71D0: @ 80B71D0
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r5, r0, r1
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0x84
	bl Cos
	strh r0, [r5, 0x24]
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0x94
	bl Sin
	strh r0, [r5, 0x26]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B720E
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
_080B720E:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B721E
	strh r0, [r5, 0x24]
	strh r0, [r5, 0x26]
	movs r0, 0x5
	strh r0, [r4, 0x8]
_080B721E:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B71D0

	thumb_func_start sub_80B7230
sub_80B7230: @ 80B7230
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	movs r0, 0x7C
	bl Cos
	strh r0, [r4, 0x24]
	movs r0, 0xA
	ldrsh r1, [r5, r0]
	movs r0, 0x76
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B7230

	thumb_func_start sub_80B7270
sub_80B7270: @ 80B7270
	push {r4,r5,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r5, r0, r1
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0x7C
	bl Cos
	strh r0, [r5, 0x24]
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0x76
	bl Sin
	strh r0, [r5, 0x26]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B72AE
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
_080B72AE:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B72C0
	strh r0, [r5, 0x24]
	strh r0, [r5, 0x26]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B72C0:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B7270

	thumb_func_start sub_80B72D0
sub_80B72D0: @ 80B72D0
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80E1584
	lsls r0, 24
	cmp r0, 0
	bne _080B72EC
	bl sub_80E1570
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	b _080B72EE
_080B72EC:
	movs r0, 0
_080B72EE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B72D0

	thumb_func_start sub_80B72F4
sub_80B72F4: @ 80B72F4
	push {r4,lr}
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B7338
	bl CameraObjectReset1
	bl script_env_2_disable
	movs r0, 0x4
	bl GetGoSpeed0AnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	ldr r0, =sub_80B70DC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B7338:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B72F4

	thumb_func_start oei_waterfall
oei_waterfall: @ 80B734C
	push {r4,lr}
	ldr r4, =sub_80B7384
	adds r0, r4, 0
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r2, =gUnknown_02038C08
	ldr r2, [r2]
	strh r2, [r1, 0xA]
	bl _call_via_r4
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end oei_waterfall

	thumb_func_start sub_80B7384
sub_80B7384: @ 80B7384
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0855C418
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_080B7396:
	movs r0, 0x8
	ldrsh r2, [r4, r0]
	lsls r2, 2
	adds r2, r5
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_02037350
	adds r1, r0
	ldr r2, [r2]
	adds r0, r4, 0
	bl _call_via_r2
	lsls r0, 24
	cmp r0, 0
	bne _080B7396
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7384

	thumb_func_start sub_80B73D0
sub_80B73D0: @ 80B73D0
	push {r4,lr}
	adds r4, r0, 0
	bl script_env_2_enable
	ldr r1, =gUnknown_02037590
	movs r0, 0x1
	strb r0, [r1, 0x6]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B73D0

	thumb_func_start waterfall_1_do_anim_probably
waterfall_1_do_anim_probably: @ 80B73F0
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl script_env_2_enable
	adds r0, r5, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	bne _080B7420
	adds r0, r5, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	ldr r1, =gUnknown_02038C08
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	str r0, [r1]
	movs r0, 0x3B
	bl FieldEffectStart
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B7420:
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end waterfall_1_do_anim_probably

	thumb_func_start waterfall_2_wait_anim_finish_probably
waterfall_2_wait_anim_finish_probably: @ 80B742C
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080B7446
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	b _080B7448
_080B7446:
	movs r0, 0
_080B7448:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end waterfall_2_wait_anim_finish_probably

	thumb_func_start sub_80B7450
sub_80B7450: @ 80B7450
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	movs r0, 0x2
	bl GetSimpleGoAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B7450

	thumb_func_start sub_80B7478
sub_80B7478: @ 80B7478
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	bne _080B748E
	movs r0, 0
	b _080B74CA
_080B748E:
	ldrb r0, [r4, 0x1E]
	bl MetatileBehavior_IsWaterfall
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080B74C4
	bl script_env_2_disable
	ldr r0, =gUnknown_02037590
	strb r4, [r0, 0x6]
	ldr r0, =sub_80B7384
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0x2B
	bl FieldEffectActiveListRemove
	movs r0, 0
	b _080B74CA
	.pool
_080B74C4:
	movs r0, 0x3
	strh r0, [r5, 0x8]
	movs r0, 0x1
_080B74CA:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80B7478

	thumb_func_start sub_80B74D0
sub_80B74D0: @ 80B74D0
	push {r4,lr}
	ldr r4, =sub_80B750C
	adds r0, r4, 0
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r3, =gUnknown_02038C08
	ldr r2, [r3]
	strh r2, [r1, 0x26]
	ldr r2, [r3, 0x4]
	strh r2, [r1, 0x24]
	bl _call_via_r4
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B74D0

	thumb_func_start sub_80B750C
sub_80B750C: @ 80B750C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0855C42C
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_080B751E:
	movs r1, 0x8
	ldrsh r0, [r4, r1]
	lsls r0, 2
	adds r0, r5
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 24
	cmp r0, 0
	bne _080B751E
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B750C

	thumb_func_start dive_1_lock
dive_1_lock: @ 80B7544
	ldr r2, =gUnknown_02037590
	movs r1, 0x1
	strb r1, [r2, 0x6]
	ldrh r1, [r0, 0x8]
	adds r1, 0x1
	strh r1, [r0, 0x8]
	movs r0, 0
	bx lr
	.pool
	thumb_func_end dive_1_lock

	thumb_func_start dive_2_unknown
dive_2_unknown: @ 80B7558
	push {r4,lr}
	adds r4, r0, 0
	bl script_env_2_enable
	ldr r1, =gUnknown_02038C08
	movs r2, 0x26
	ldrsh r0, [r4, r2]
	str r0, [r1]
	movs r0, 0x3B
	bl FieldEffectStart
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end dive_2_unknown

	thumb_func_start dive_3_unknown
dive_3_unknown: @ 80B7580
	push {lr}
	sub sp, 0x8
	mov r1, sp
	adds r1, 0x2
	mov r0, sp
	bl PlayerGetDestCoords
	movs r0, 0x6
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080B75C4
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1E]
	mov r0, sp
	bl dive_warp
	ldr r0, =sub_80B750C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	movs r0, 0x2C
	bl FieldEffectActiveListRemove
_080B75C4:
	movs r0, 0
	add sp, 0x8
	pop {r1}
	bx r1
	.pool
	thumb_func_end dive_3_unknown

	thumb_func_start sub_80B75D8
sub_80B75D8: @ 80B75D8
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =sub_80B75F0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B75D8

	thumb_func_start sub_80B75F0
sub_80B75F0: @ 80B75F0
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gUnknown_0855C438
	ldr r2, =gTasks
	ldr r5, =gUnknown_02037590
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_080B7604:
	movs r0, 0x8
	ldrsh r3, [r4, r0]
	lsls r3, 2
	adds r3, r6
	ldrb r0, [r5, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_02037350
	adds r1, r0
	ldrb r0, [r5, 0x4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	ldr r3, [r3]
	adds r0, r4, 0
	bl _call_via_r3
	lsls r0, 24
	cmp r0, 0
	bne _080B7604
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B75F0

	thumb_func_start sub_80B764C
sub_80B764C: @ 80B764C
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	bl player_bitmagic
	bl CameraObjectReset2
	movs r0, 0
	bl SetCameraPanningCallback
	ldr r0, =gUnknown_02037590
	movs r2, 0x1
	strb r2, [r0, 0x6]
	ldrb r0, [r5, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x3]
	strh r2, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B764C

	thumb_func_start sub_80B7684
sub_80B7684: @ 80B7684
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0
	bl SetCameraPanning
	ldrh r0, [r4, 0xA]
	negs r0, r0
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _080B76B0
	movs r0, 0
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B76B0:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B7684

	thumb_func_start sub_80B76B8
sub_80B76B8: @ 80B76B8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0
	strh r0, [r2, 0x26]
	movs r0, 0x1
	strh r0, [r4, 0xE]
	ldr r3, =gUnknown_02038C08
	movs r5, 0x10
	ldrsh r0, [r1, r5]
	str r0, [r3]
	movs r5, 0x12
	ldrsh r0, [r1, r5]
	str r0, [r3, 0x4]
	adds r0, r2, 0
	adds r0, 0x43
	ldrb r0, [r0]
	subs r0, 0x1
	str r0, [r3, 0x8]
	ldrb r0, [r2, 0x5]
	lsls r0, 28
	lsrs r0, 30
	str r0, [r3, 0xC]
	movs r0, 0x32
	bl FieldEffectStart
	movs r0, 0xB2
	bl PlaySE
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B76B8

	thumb_func_start sub_80B7704
sub_80B7704: @ 80B7704
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	adds r5, r2, 0
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0
	bl SetCameraPanning
	ldrh r0, [r4, 0xA]
	negs r2, r0
	strh r2, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r1, r0, 0x1
	strh r1, [r4, 0xC]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x11
	bgt _080B773E
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	bne _080B7750
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x3
	bgt _080B7750
	lsls r0, r2, 1
	b _080B774E
_080B773E:
	movs r0, 0x4
	ands r1, r0
	cmp r1, 0
	bne _080B7750
	lsls r0, r2, 16
	cmp r0, 0
	ble _080B7750
	asrs r0, 17
_080B774E:
	strh r0, [r4, 0xA]
_080B7750:
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x6
	ble _080B779C
	adds r0, r5, 0
	adds r0, 0x29
	movs r1, 0
	ldrsb r1, [r0, r1]
	lsls r2, r1, 17
	negs r2, r2
	movs r7, 0x26
	ldrsh r3, [r5, r7]
	movs r7, 0x22
	ldrsh r0, [r5, r7]
	adds r0, r1
	ldr r1, =gSpriteCoordOffsetY
	movs r7, 0
	ldrsh r1, [r1, r7]
	adds r0, r1
	asrs r2, 16
	adds r0, r2
	cmn r3, r0
	ble _080B7798
	ldrh r0, [r5, 0x26]
	ldrh r1, [r4, 0xE]
	subs r0, r1
	strh r0, [r5, 0x26]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x7
	bgt _080B779C
	adds r0, r1, 0x1
	strh r0, [r4, 0xE]
	b _080B779C
	.pool
_080B7798:
	movs r0, 0x1
	strh r0, [r4, 0x10]
_080B779C:
	ldrh r2, [r4, 0x12]
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B77DA
	movs r7, 0x26
	ldrsh r1, [r5, r7]
	movs r0, 0x10
	negs r0, r0
	cmp r1, r0
	bge _080B77DA
	adds r0, r2, 0x1
	strh r0, [r4, 0x12]
	ldrb r0, [r6, 0x3]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r6, 0x3]
	ldrb r1, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, 0x5]
	adds r2, r5, 0
	adds r2, 0x42
	ldrb r1, [r2]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
_080B77DA:
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B77F0
	movs r7, 0x10
	ldrsh r0, [r4, r7]
	cmp r0, 0
	beq _080B77F0
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B77F0:
	movs r0, 0
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80B7704

	thumb_func_start sub_80B77F8
sub_80B77F8: @ 80B77F8
	push {r4,lr}
	adds r4, r0, 0
	bl music_something
	bl sub_80AF0B4
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B77F8

	thumb_func_start sub_80B7814
sub_80B7814: @ 80B7814
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080B784C
	bl sub_80859A0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B784C
	bl warp_in
	ldr r1, =gUnknown_03005DAC
	ldr r0, =mapldr_080851BC
	str r0, [r1]
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	ldr r0, =sub_80B75F0
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B784C:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B7814

	thumb_func_start mapldr_080851BC
mapldr_080851BC: @ 80B7868
	push {lr}
	bl sub_8085784
	bl pal_fill_for_maplights
	bl script_env_2_enable
	ldr r0, =gUnknown_03005DAC
	movs r1, 0
	str r1, [r0]
	ldr r0, =sub_80B7890
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapldr_080851BC

	thumb_func_start sub_80B7890
sub_80B7890: @ 80B7890
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gUnknown_0855C450
	ldr r2, =gTasks
	ldr r5, =gUnknown_02037590
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_080B78A4:
	movs r0, 0x8
	ldrsh r3, [r4, r0]
	lsls r3, 2
	adds r3, r6
	ldrb r0, [r5, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_02037350
	adds r1, r0
	ldrb r0, [r5, 0x4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	ldr r3, [r3]
	adds r0, r4, 0
	bl _call_via_r3
	lsls r0, 24
	cmp r0, 0
	bne _080B78A4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7890

	thumb_func_start sub_80B78EC
sub_80B78EC: @ 80B78EC
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl CameraObjectReset2
	bl player_bitmagic
	ldr r1, =gUnknown_02037590
	movs r0, 0x1
	strb r0, [r1, 0x6]
	ldrb r0, [r4, 0x1]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B78EC

	thumb_func_start sub_80B791C
sub_80B791C: @ 80B791C
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	bl sub_80ABDFC
	lsls r0, 24
	cmp r0, 0
	beq _080B795C
	ldr r1, =gUnknown_02038C08
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	str r0, [r1]
	movs r2, 0x12
	ldrsh r0, [r5, r2]
	str r0, [r1, 0x4]
	adds r0, r6, 0
	adds r0, 0x43
	ldrb r0, [r0]
	subs r0, 0x1
	str r0, [r1, 0x8]
	ldrb r0, [r6, 0x5]
	lsls r0, 28
	lsrs r0, 30
	str r0, [r1, 0xC]
	movs r0, 0x31
	bl FieldEffectStart
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B795C:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B791C

	thumb_func_start sub_80B7968
sub_80B7968: @ 80B7968
	push {r4,lr}
	adds r2, r0, 0
	adds r4, r1, 0
	movs r0, 0xA
	ldrsh r1, [r2, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x1
	bls _080B79B0
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	ldrb r1, [r4, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	bl CameraObjectReset1
	movs r0, 0xAF
	bl PlaySE
	movs r0, 0x4
	bl sub_8093514
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
_080B79B0:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B7968

	thumb_func_start sub_80B79BC
sub_80B79BC: @ 80B79BC
	push {lr}
	adds r0, r1, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B79E6
	ldr r1, =gUnknown_02037590
	movs r0, 0
	strb r0, [r1, 0x6]
	bl script_env_2_disable
	bl sub_809757C
	ldr r0, =sub_80B7890
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B79E6:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B79BC

	thumb_func_start sub_80B79F4
sub_80B79F4: @ 80B79F4
	push {r4,lr}
	ldr r4, =gUnknown_02038C08
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	adds r0, 0x84
	ldr r0, [r0]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	movs r1, 0x3
	ldrb r3, [r4, 0xC]
	ands r3, r1
	lsls r3, 2
	ldrb r4, [r2, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r4
	orrs r1, r3
	strb r1, [r2, 0x5]
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r3, 0x2
	orrs r1, r3
	strb r1, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B79F4

	thumb_func_start sub_80B7A58
sub_80B7A58: @ 80B7A58
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080B7A70
	adds r0, r2, 0
	movs r1, 0x32
	bl FieldEffectStop
_080B7A70:
	pop {r0}
	bx r0
	thumb_func_end sub_80B7A58

	thumb_func_start sub_80B7A74
sub_80B7A74: @ 80B7A74
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r0, =sub_80B7A8C
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7A74

	thumb_func_start sub_80B7A8C
sub_80B7A8C: @ 80B7A8C
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r6, =gUnknown_0855C460
	ldr r2, =gTasks
	ldr r5, =gUnknown_02037590
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
_080B7AA0:
	movs r0, 0x8
	ldrsh r3, [r4, r0]
	lsls r3, 2
	adds r3, r6
	ldrb r0, [r5, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gUnknown_02037350
	adds r1, r0
	ldrb r0, [r5, 0x4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	ldr r3, [r3]
	adds r0, r4, 0
	bl _call_via_r3
	lsls r0, 24
	cmp r0, 0
	bne _080B7AA0
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7A8C

	thumb_func_start sub_80B7AE8
sub_80B7AE8: @ 80B7AE8
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl player_bitmagic
	bl CameraObjectReset2
	ldr r1, =gUnknown_02037590
	movs r0, 0x1
	strb r0, [r1, 0x6]
	ldrb r0, [r4, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4, 0x3]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B7AE8

	thumb_func_start sub_80B7B18
sub_80B7B18: @ 80B7B18
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r6, r2, 0
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B7B8C
	ldrh r1, [r5, 0xA]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	cmp r0, 0x3
	ble _080B7B6C
	ldr r1, =gUnknown_02038C08
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	str r0, [r1]
	movs r2, 0x12
	ldrsh r0, [r4, r2]
	str r0, [r1, 0x4]
	adds r0, r6, 0
	adds r0, 0x43
	ldrb r0, [r0]
	subs r0, 0x1
	str r0, [r1, 0x8]
	ldrb r0, [r6, 0x5]
	lsls r0, 28
	lsrs r0, 30
	str r0, [r1, 0xC]
	movs r0, 0x31
	bl FieldEffectStart
	strh r0, [r5, 0xA]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	b _080B7B8C
	.pool
_080B7B6C:
	adds r0, r1, 0x1
	strh r0, [r5, 0xA]
	ldrb r0, [r4, 0x18]
	lsls r0, 28
	lsrs r0, 28
	bl GetStepInPlaceDelay4AnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	movs r0, 0x27
	bl PlaySE
_080B7B8C:
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_80B7B18

	thumb_func_start sub_80B7B94
sub_80B7B94: @ 80B7B94
	push {r4,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	ldr r2, =gSprites
	movs r0, 0xA
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x2B
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080B7BBE
	ldrb r0, [r4, 0x1]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_080B7BBE:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B7B94

	thumb_func_start sub_80B7BCC
sub_80B7BCC: @ 80B7BCC
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x31
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080B7BEA
	bl music_something
	bl sub_80AF0B4
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B7BEA:
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B7BCC

	thumb_func_start sub_80B7BF4
sub_80B7BF4: @ 80B7BF4
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080B7C2C
	bl sub_80859A0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B7C2C
	bl warp_in
	ldr r1, =gUnknown_03005DAC
	ldr r0, =sub_80B6B68
	str r0, [r1]
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	ldr r0, =sub_80B7A8C
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B7C2C:
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B7BF4

	thumb_func_start sub_80B7C48
sub_80B7C48: @ 80B7C48
	push {r4,lr}
	ldr r4, =gUnknown_02038C08
	adds r1, r4, 0x4
	adds r0, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	adds r0, 0x80
	ldr r0, [r0]
	movs r2, 0
	ldrsh r1, [r4, r2]
	movs r3, 0x4
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, 0x8]
	bl CreateSpriteAtEnd
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r1
	movs r1, 0x3
	ldrb r3, [r4, 0xC]
	ands r3, r1
	lsls r3, 2
	ldrb r4, [r2, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r4
	orrs r1, r3
	strb r1, [r2, 0x5]
	adds r2, 0x3E
	ldrb r1, [r2]
	movs r3, 0x2
	orrs r1, r3
	strb r1, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B7C48

	thumb_func_start sub_80B7CAC
sub_80B7CAC: @ 80B7CAC
	push {lr}
	adds r2, r0, 0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080B7CC4
	adds r0, r2, 0
	movs r1, 0x31
	bl FieldEffectStop
_080B7CC4:
	pop {r0}
	bx r0
	thumb_func_end sub_80B7CAC

	thumb_func_start sub_80B7CC8
sub_80B7CC8: @ 80B7CC8
	push {lr}
	bl script_env_2_enable
	bl player_bitmagic
	ldr r0, =sub_80B7CE4
	movs r1, 0x50
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7CC8

	thumb_func_start sub_80B7CE4
sub_80B7CE4: @ 80B7CE4
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0855C474
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7CE4

	thumb_func_start sub_80B7D14
sub_80B7D14: @ 80B7D14
	push {r4,lr}
	adds r4, r0, 0
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x40
	strh r0, [r4, 0x24]
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B7D14

	thumb_func_start sub_80B7D34
sub_80B7D34: @ 80B7D34
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, =gUnknown_0855C47C
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	ldrh r1, [r4, 0x24]
	movs r2, 0x24
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _080B7D60
	subs r0, r1, 0x1
	strh r0, [r4, 0x24]
	lsls r0, 16
	cmp r0, 0
	bne _080B7D60
	bl music_something
	bl sub_80AF0B4
_080B7D60:
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r5, r0, r1
	adds r0, r5, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B7D86
	adds r0, r5, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B7E40
_080B7D86:
	movs r1, 0x24
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B7DF8
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080B7DF8
	bl sub_80859A0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B7DF8
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl FieldObjectSetDirection
	bl sub_8084E14
	bl warp_in
	ldr r1, =gUnknown_03005DAC
	ldr r0, =mapldr_080859D4
	str r0, [r1]
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	ldr r0, =sub_80B7CE4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	b _080B7E40
	.pool
_080B7DF8:
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _080B7E0C
	subs r0, r1, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bne _080B7E40
_080B7E0C:
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	add r0, sp
	ldrb r0, [r0]
	bl GetFaceDirectionAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r5, 0
	bl FieldObjectSetSpecialAnim
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0xB
	bgt _080B7E34
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
_080B7E34:
	ldrh r1, [r4, 0xC]
	lsls r1, 16
	asrs r1, 18
	movs r0, 0x8
	asrs r0, r1
	strh r0, [r4, 0xA]
_080B7E40:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80B7D34

	thumb_func_start mapldr_080859D4
mapldr_080859D4: @ 80B7E48
	push {lr}
	bl sub_8085784
	bl pal_fill_for_maplights
	bl script_env_2_enable
	bl player_bitmagic
	ldr r1, =gUnknown_03005DAC
	movs r0, 0
	str r0, [r1]
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x1]
	ldr r0, =sub_80B7E94
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapldr_080859D4

	thumb_func_start sub_80B7E94
sub_80B7E94: @ 80B7E94
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0855C484
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7E94

	thumb_func_start sub_80B7EC4
sub_80B7EC4: @ 80B7EC4
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80ABDFC
	lsls r0, 24
	cmp r0, 0
	beq _080B7EE2
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
_080B7EE2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B7EC4

	thumb_func_start sub_80B7EE8
sub_80B7EE8: @ 80B7EE8
	push {r4-r6,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r1, =gUnknown_0855C47C
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r6, r0, r1
	ldrh r1, [r5, 0xA]
	movs r2, 0xA
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _080B7F1A
	subs r0, r1, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	cmp r0, 0
	bne _080B7FAC
_080B7F1A:
	adds r0, r6, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B7F32
	adds r0, r6, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B7FC0
_080B7F32:
	movs r1, 0xC
	ldrsh r0, [r5, r1]
	cmp r0, 0x1F
	ble _080B7F7C
	movs r2, 0x26
	ldrsh r4, [r5, r2]
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bne _080B7F7C
	ldrb r1, [r6, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r6, 0x1]
	bl script_env_2_disable
	bl sub_809757C
	ldr r0, =sub_80B7E94
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	b _080B7FC0
	.pool
_080B7F7C:
	ldrb r0, [r6, 0x18]
	lsls r0, 28
	lsrs r0, 28
	add r0, sp
	ldrb r0, [r0]
	bl GetFaceDirectionAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r6, 0
	bl FieldObjectSetSpecialAnim
	ldrh r1, [r5, 0xC]
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	cmp r0, 0x1F
	bgt _080B7FA4
	adds r0, r1, 0x1
	strh r0, [r5, 0xC]
_080B7FA4:
	ldrh r0, [r5, 0xC]
	lsls r0, 16
	asrs r0, 18
	strh r0, [r5, 0xA]
_080B7FAC:
	ldrb r2, [r6, 0x1]
	lsls r1, r2, 26
	lsrs r1, 31
	movs r0, 0x1
	eors r1, r0
	lsls r1, 5
	subs r0, 0x22
	ands r0, r2
	orrs r0, r1
	strb r0, [r6, 0x1]
_080B7FC0:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80B7EE8

	thumb_func_start sub_80B7FC8
sub_80B7FC8: @ 80B7FC8
	push {lr}
	ldr r0, =sub_80B7FDC
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7FC8

	thumb_func_start sub_80B7FDC
sub_80B7FDC: @ 80B7FDC
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0855C48C
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B7FDC

	thumb_func_start sub_80B800C
sub_80B800C: @ 80B800C
	push {r4,lr}
	adds r4, r0, 0
	bl script_env_2_enable
	bl player_bitmagic
	bl CameraObjectReset2
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B800C

	thumb_func_start sub_80B8034
sub_80B8034: @ 80B8034
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, =gUnknown_0855C47C
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r5, r0, r1
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _080B8066
	subs r0, r1, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bne _080B8080
_080B8066:
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	add r0, sp
	ldrb r1, [r0]
	adds r0, r5, 0
	bl FieldObjectTurn
	movs r0, 0x8
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
_080B8080:
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	cmp r0, 0x7
	ble _080B80AE
	movs r2, 0x26
	ldrsh r1, [r4, r2]
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	cmp r1, r0
	bne _080B80AE
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x4
	strh r0, [r4, 0xA]
	movs r0, 0x8
	strh r0, [r4, 0xC]
	movs r0, 0x1
	strh r0, [r4, 0xE]
	movs r0, 0x2D
	bl PlaySE
_080B80AE:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8034

	thumb_func_start sub_80B80C4
sub_80B80C4: @ 80B80C4
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, =gUnknown_0855C47C
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	ldr r2, =gUnknown_02037590
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r3, r0, r1
	ldrb r1, [r2, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r5, r0, r1
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bgt _080B810E
	movs r0, 0x4
	strh r0, [r4, 0xA]
	ldrb r0, [r3, 0x18]
	lsls r0, 28
	lsrs r0, 28
	add r0, sp
	ldrb r1, [r0]
	adds r0, r3, 0
	bl FieldObjectTurn
_080B810E:
	ldrh r0, [r5, 0x22]
	ldrh r1, [r4, 0xE]
	subs r0, r1
	strh r0, [r5, 0x22]
	ldrh r1, [r4, 0xE]
	ldrh r2, [r4, 0x10]
	adds r0, r1, r2
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bgt _080B813A
	movs r0, 0x4
	strh r0, [r4, 0xC]
	lsls r0, r1, 16
	asrs r0, 16
	cmp r0, 0x7
	bgt _080B813A
	lsls r0, r1, 1
	strh r0, [r4, 0xE]
_080B813A:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0x8
	ble _080B8168
	ldrb r1, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x5]
	adds r2, r5, 0
	adds r2, 0x42
	ldrb r1, [r2]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _080B8168
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
_080B8168:
	movs r2, 0x10
	ldrsh r0, [r4, r2]
	cmp r0, 0xA7
	ble _080B817E
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	bl music_something
	bl sub_80AF0B4
_080B817E:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B80C4

	thumb_func_start sub_80B8198
sub_80B8198: @ 80B8198
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080B81E6
	movs r1, 0x12
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B81B8
	bl sub_81BE72C
	movs r0, 0x1
	strh r0, [r4, 0x12]
_080B81B8:
	bl sub_80859A0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B81E6
	bl copy_saved_warp3_bank_and_enter_x_to_warp1
	bl warp_in
	ldr r0, =c2_load_new_map
	bl SetMainCallback2
	ldr r1, =gUnknown_03005DAC
	ldr r0, =mapldr_08085D88
	str r0, [r1]
	ldr r0, =sub_80B7FDC
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B81E6:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8198

	thumb_func_start mapldr_08085D88
mapldr_08085D88: @ 80B8200
	push {lr}
	bl sub_8085784
	bl pal_fill_for_maplights
	bl script_env_2_enable
	bl player_bitmagic
	ldr r1, =gUnknown_03005DAC
	movs r0, 0
	str r0, [r1]
	ldr r2, =gUnknown_02037350
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r0, 0x1]
	movs r2, 0x20
	orrs r1, r2
	strb r1, [r0, 0x1]
	bl CameraObjectReset2
	ldr r0, =sub_80B8250
	movs r1, 0
	bl CreateTask
	pop {r0}
	bx r0
	.pool
	thumb_func_end mapldr_08085D88

	thumb_func_start sub_80B8250
sub_80B8250: @ 80B8250
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0855C49C
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8250

	thumb_func_start sub_80B8280
sub_80B8280: @ 80B8280
	push {r4-r6,lr}
	adds r6, r0, 0
	bl sub_80ABDFC
	lsls r0, 24
	cmp r0, 0
	beq _080B82F6
	ldr r5, =gUnknown_02037590
	ldrb r0, [r5, 0x4]
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	adds r0, r2, 0
	adds r0, 0x29
	movs r4, 0
	ldrsb r4, [r0, r4]
	lsls r0, r4, 17
	negs r0, r0
	ldrh r1, [r2, 0x22]
	ldr r3, =gSpriteCoordOffsetY
	adds r1, r4
	ldrh r3, [r3]
	adds r1, r3
	asrs r0, 16
	adds r0, r1
	negs r0, r0
	strh r0, [r2, 0x26]
	ldr r3, =gUnknown_02037350
	ldrb r0, [r5, 0x5]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r3
	ldrb r3, [r1, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r3
	strb r0, [r1, 0x1]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	movs r0, 0x8
	strh r0, [r6, 0xA]
	movs r0, 0x1
	strh r0, [r6, 0xC]
	adds r2, 0x42
	ldrb r0, [r2]
	lsrs r0, 6
	strh r0, [r6, 0x24]
	bl player_get_direction_lower_nybble
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r6, 0x26]
	movs r0, 0x2D
	bl PlaySE
_080B82F6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8280

	thumb_func_start sub_80B830C
sub_80B830C: @ 80B830C
	push {r4-r7,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, =gUnknown_0855C47C
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	ldr r2, =gUnknown_02037590
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r6, r0, r1
	ldrb r1, [r2, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r5, r0, r1
	ldrh r0, [r4, 0xA]
	ldrh r1, [r5, 0x26]
	adds r0, r1
	strh r0, [r5, 0x26]
	lsls r0, 16
	asrs r0, 16
	movs r1, 0x8
	negs r1, r1
	cmp r0, r1
	blt _080B8384
	ldrh r1, [r4, 0x22]
	movs r2, 0x22
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _080B83AA
	adds r0, r1, 0x1
	strh r0, [r4, 0x22]
	ldrb r0, [r6]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r6]
	ldrh r1, [r4, 0x24]
	adds r3, r5, 0
	adds r3, 0x42
	lsls r1, 6
	ldrb r2, [r3]
	movs r0, 0x3F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _080B83AA
	.pool
_080B8384:
	ldrb r1, [r5, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x5]
	adds r2, r5, 0
	adds r2, 0x42
	ldrb r1, [r2]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _080B83AA
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2]
_080B83AA:
	ldrh r2, [r5, 0x26]
	movs r3, 0x26
	ldrsh r1, [r5, r3]
	movs r0, 0x30
	negs r0, r0
	cmp r1, r0
	blt _080B83CE
	ldrh r1, [r4, 0xA]
	movs r3, 0xA
	ldrsh r0, [r4, r3]
	cmp r0, 0x1
	ble _080B83CE
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	bne _080B83CE
	subs r0, r1, 0x1
	strh r0, [r4, 0xA]
_080B83CE:
	ldrh r0, [r4, 0xC]
	subs r0, 0x1
	movs r7, 0
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _080B83F0
	movs r0, 0x4
	strh r0, [r4, 0xC]
	ldrb r0, [r6, 0x18]
	lsls r0, 28
	lsrs r0, 28
	add r0, sp
	ldrb r1, [r0]
	adds r0, r6, 0
	bl FieldObjectTurn
_080B83F0:
	movs r1, 0x26
	ldrsh r0, [r5, r1]
	cmp r0, 0
	blt _080B8406
	strh r7, [r5, 0x26]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x1
	strh r0, [r4, 0xA]
	strh r7, [r4, 0xC]
_080B8406:
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80B830C

	thumb_func_start sub_80B8410
sub_80B8410: @ 80B8410
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r1, =gUnknown_0855C47C
	mov r0, sp
	movs r2, 0x5
	bl memcpy
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r5, r0, r1
	ldrh r0, [r4, 0xA]
	subs r0, 0x1
	strh r0, [r4, 0xA]
	lsls r0, 16
	cmp r0, 0
	bne _080B8484
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	add r0, sp
	ldrb r1, [r0]
	adds r0, r5, 0
	bl FieldObjectTurn
	movs r0, 0x8
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x4
	ble _080B8484
	movs r0, 0x24
	ldrsh r1, [r4, r0]
	ldrb r0, [r5, 0x18]
	lsls r0, 28
	lsrs r0, 28
	cmp r1, r0
	bne _080B8484
	bl script_env_2_disable
	bl CameraObjectReset1
	bl sub_809757C
	ldr r0, =sub_80B8250
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B8484:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8410

	thumb_func_start sub_80B849C
sub_80B849C: @ 80B849C
	push {r4,lr}
	bl sav1_map_get_light_level
	lsls r0, 24
	lsrs r0, 24
	bl is_light_level_1_2_3_5_or_6
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _080B84BC
	ldr r0, =sub_80B8554
	b _080B84BE
	.pool
_080B84BC:
	ldr r0, =sub_80B88B4
_080B84BE:
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gUnknown_02038C08
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [r2, 0x8]
	bl sub_80B8C60
	ldr r2, =gTasks
	lsls r1, r4, 2
	adds r1, r4
	lsls r1, 3
	adds r1, r2
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r1, 0x26]
	movs r0, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B849C

	thumb_func_start sub_80B84F8
sub_80B84F8: @ 80B84F8
	push {r4-r6,lr}
	ldr r5, =gUnknown_02038C08
	ldr r0, [r5]
	movs r6, 0x80
	lsls r6, 24
	ands r6, r0
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x64
	adds r4, r0, 0
	muls r4, r1
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0xB
	bl GetMonData
	str r0, [r5]
	adds r0, r4, 0
	movs r1, 0x1
	bl GetMonData
	str r0, [r5, 0x4]
	adds r0, r4, 0
	movs r1, 0
	bl GetMonData
	str r0, [r5, 0x8]
	ldr r0, [r5]
	orrs r0, r6
	str r0, [r5]
	movs r0, 0x6
	bl FieldEffectStart
	movs r0, 0x3B
	bl FieldEffectActiveListRemove
	movs r0, 0
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B84F8

	thumb_func_start sub_80B8554
sub_80B8554: @ 80B8554
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0855C4A8
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8554

	thumb_func_start sub_80B8584
sub_80B8584: @ 80B8584
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =0x04000048
	ldrh r0, [r0]
	strh r0, [r4, 0x1E]
	ldr r0, =0x0400004a
	ldrh r0, [r0]
	strh r0, [r4, 0x20]
	adds r0, r4, 0
	adds r0, 0x22
	ldr r1, =gMain
	ldr r1, [r1, 0xC]
	bl StoreWordInTwoHalfwords
	ldr r1, =0x0000f0f1
	strh r1, [r4, 0xA]
	ldr r0, =0x00005051
	strh r0, [r4, 0xC]
	movs r0, 0x3F
	strh r0, [r4, 0xE]
	movs r0, 0x3E
	strh r0, [r4, 0x10]
	movs r0, 0x40
	bl SetGpuReg
	ldrh r1, [r4, 0xC]
	movs r0, 0x44
	bl SetGpuReg
	ldrh r1, [r4, 0xE]
	movs r0, 0x48
	bl SetGpuReg
	ldrh r1, [r4, 0x10]
	movs r0, 0x4A
	bl SetGpuReg
	ldr r0, =sub_80B880C
	bl SetVBlankCallback
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8584

	thumb_func_start sub_80B85F8
sub_80B85F8: @ 80B85F8
	push {r4-r6,lr}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r0, =0x04000008
	ldrh r1, [r0]
	lsrs r1, 2
	lsls r1, 30
	lsrs r1, 16
	ldrh r4, [r0]
	lsrs r4, 8
	lsls r4, 27
	lsrs r4, 16
	ldr r0, =gUnknown_0855AE50
	movs r5, 0xC0
	lsls r5, 19
	adds r1, r5
	movs r2, 0x80
	lsls r2, 1
	bl CpuSet
	movs r0, 0
	str r0, [sp]
	adds r5, r4, r5
	ldr r2, =0x05000200
	mov r0, sp
	adds r1, r5, 0
	bl CpuSet
	ldr r0, =gUnknown_0855B050
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	adds r0, r4, 0
	bl sub_80B8874
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B85F8

	thumb_func_start sub_80B8660
sub_80B8660: @ 80B8660
	push {r4-r7,lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x12]
	subs r0, 0x10
	strh r0, [r3, 0x12]
	ldrh r6, [r3, 0xA]
	ldrh r2, [r3, 0xC]
	movs r7, 0xFF
	lsrs r1, r6, 8
	subs r1, 0x10
	lsls r1, 16
	lsrs r0, r2, 8
	subs r0, 0x2
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r7, 0
	ands r0, r2
	adds r5, r0, 0x2
	lsrs r2, r1, 16
	cmp r1, 0
	bge _080B868C
	movs r2, 0
_080B868C:
	lsls r0, r4, 16
	asrs r0, 16
	cmp r0, 0x27
	bgt _080B8696
	movs r4, 0x28
_080B8696:
	cmp r5, 0x78
	ble _080B869C
	movs r5, 0x78
_080B869C:
	lsls r2, 16
	asrs r2, 16
	lsls r1, r2, 8
	adds r0, r7, 0
	ands r0, r6
	orrs r1, r0
	strh r1, [r3, 0xA]
	lsls r0, r4, 16
	asrs r4, r0, 16
	lsls r0, r4, 8
	adds r1, r5, 0
	orrs r0, r1
	strh r0, [r3, 0xC]
	cmp r2, 0
	bne _080B86DC
	cmp r4, 0x28
	bne _080B86DC
	cmp r1, 0x78
	bne _080B86DC
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_80B8CC0
	str r1, [r0]
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_080B86DC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8660

	thumb_func_start sub_80B86EC
sub_80B86EC: @ 80B86EC
	push {lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x12]
	subs r0, 0x10
	strh r0, [r3, 0x12]
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3C
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080B8712
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_080B8712:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B86EC

	thumb_func_start sub_80B871C
sub_80B871C: @ 80B871C
	push {r4,lr}
	adds r3, r0, 0
	ldrh r0, [r3, 0x12]
	subs r0, 0x10
	strh r0, [r3, 0x12]
	ldrh r2, [r3, 0xC]
	lsls r1, r2, 16
	movs r0, 0xFF
	asrs r1, 24
	adds r1, 0x6
	lsls r1, 16
	ands r0, r2
	subs r0, 0x6
	lsls r0, 16
	lsrs r2, r0, 16
	lsrs r4, r1, 16
	asrs r1, 16
	cmp r1, 0x50
	ble _080B8744
	movs r4, 0x50
_080B8744:
	lsls r0, r2, 16
	asrs r0, 16
	cmp r0, 0x50
	bgt _080B874E
	movs r2, 0x51
_080B874E:
	lsls r0, r4, 16
	asrs r0, 16
	lsls r1, r0, 8
	lsls r2, 16
	asrs r2, 16
	orrs r1, r2
	strh r1, [r3, 0xC]
	cmp r0, 0x50
	bne _080B876A
	cmp r2, 0x51
	bne _080B876A
	ldrh r0, [r3, 0x8]
	adds r0, 0x1
	strh r0, [r3, 0x8]
_080B876A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B871C

	thumb_func_start sub_80B8770
sub_80B8770: @ 80B8770
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	ldr r0, =0x04000008
	ldrh r1, [r0]
	lsrs r1, 8
	lsls r1, 27
	lsrs r1, 16
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC0
	lsls r0, 19
	adds r1, r0
	ldr r2, =0x05000200
	mov r0, sp
	bl CpuSet
	movs r0, 0xF1
	strh r0, [r4, 0xA]
	movs r0, 0xA1
	strh r0, [r4, 0xC]
	ldrh r0, [r4, 0x1E]
	strh r0, [r4, 0xE]
	ldrh r0, [r4, 0x20]
	strh r0, [r4, 0x10]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8770

	thumb_func_start overworld_bg_setup_2
overworld_bg_setup_2: @ 80B87B8
	push {r4,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r0, 0x22
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	ldr r0, [sp]
	bl SetVBlankCallback
	bl sub_8197200
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	bl sub_80B6070
	movs r0, 0x6
	bl FieldEffectActiveListRemove
	ldr r0, =sub_80B8554
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end overworld_bg_setup_2

	thumb_func_start sub_80B880C
sub_80B880C: @ 80B880C
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =sub_80B8554
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	adds r0, r4, 0
	adds r0, 0x22
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	ldr r0, [sp]
	bl _call_via_r0
	ldrh r1, [r4, 0xA]
	movs r0, 0x40
	bl SetGpuReg
	ldrh r1, [r4, 0xC]
	movs r0, 0x44
	bl SetGpuReg
	ldrh r1, [r4, 0xE]
	movs r0, 0x48
	bl SetGpuReg
	ldrh r1, [r4, 0x10]
	movs r0, 0x4A
	bl SetGpuReg
	ldrh r1, [r4, 0x12]
	movs r0, 0x10
	bl SetGpuReg
	ldrh r1, [r4, 0x14]
	movs r0, 0x12
	bl SetGpuReg
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B880C

	thumb_func_start sub_80B8874
sub_80B8874: @ 80B8874
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x06000140
	adds r2, r0, r1
	movs r1, 0
	ldr r5, =gUnknown_0855B070
	movs r0, 0xF0
	lsls r0, 8
	adds r4, r0, 0
	ldr r3, =0x0000013f
_080B888A:
	lsls r0, r1, 1
	adds r0, r5
	ldrh r0, [r0]
	orrs r0, r4
	strh r0, [r2]
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	adds r2, 0x2
	cmp r1, r3
	bls _080B888A
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8874

	thumb_func_start sub_80B88B4
sub_80B88B4: @ 80B88B4
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0855C4C4
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B88B4

	thumb_func_start sub_80B88E4
sub_80B88E4: @ 80B88E4
	push {r4,lr}
	adds r4, r0, 0
	ldrh r1, [r4, 0xA]
	movs r0, 0x10
	bl SetGpuReg
	ldrh r1, [r4, 0xC]
	movs r0, 0x12
	bl SetGpuReg
	adds r0, r4, 0
	adds r0, 0x22
	ldr r1, =gMain
	ldr r1, [r1, 0xC]
	bl StoreWordInTwoHalfwords
	ldr r0, =sub_80B8AE0
	bl SetVBlankCallback
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B88E4

	thumb_func_start sub_80B8920
sub_80B8920: @ 80B8920
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r6, r0, 0
	ldr r0, =0x04000008
	ldrh r1, [r0]
	lsrs r1, 2
	lsls r1, 30
	lsrs r1, 16
	ldrh r4, [r0]
	lsrs r4, 8
	lsls r4, 27
	lsrs r4, 16
	movs r0, 0
	mov r8, r0
	strh r4, [r6, 0x20]
	ldr r0, =gUnknown_0855B2F0
	movs r5, 0xC0
	lsls r5, 19
	adds r1, r5
	movs r2, 0x40
	bl CpuSet
	mov r0, r8
	str r0, [sp]
	adds r4, r5
	ldr r2, =0x05000200
	mov r0, sp
	adds r1, r4, 0
	bl CpuSet
	ldr r0, =gUnknown_0855B370
	movs r1, 0xF0
	movs r2, 0x20
	bl LoadPalette
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8920

	thumb_func_start sub_80B898C
sub_80B898C: @ 80B898C
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80B8B38
	lsls r0, 24
	cmp r0, 0
	beq _080B89C4
	movs r0, 0x42
	movs r1, 0xF0
	bl SetGpuReg
	ldr r1, =0x00002878
	movs r0, 0x46
	bl SetGpuReg
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r2, 0x1C
	adds r0, r2
	ldr r1, =sub_80B8CC0
	str r1, [r0]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B89C4:
	adds r0, r4, 0
	bl sub_80B8B28
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B898C

	thumb_func_start sub_80B89DC
sub_80B89DC: @ 80B89DC
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80B8B28
	ldr r2, =gSprites
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0x3C
	ldrsh r0, [r0, r1]
	cmp r0, 0
	beq _080B8A00
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B8A00:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B89DC

	thumb_func_start sub_80B8A0C
sub_80B8A0C: @ 80B8A0C
	push {r4,r5,lr}
	adds r4, r0, 0
	bl sub_80B8B28
	ldrh r1, [r4, 0xA]
	movs r0, 0x7
	ands r0, r1
	movs r1, 0
	strh r0, [r4, 0xE]
	strh r1, [r4, 0x10]
	ldr r5, =0x0000ffff
	movs r0, 0x42
	adds r1, r5, 0
	bl SetGpuReg
	movs r0, 0x46
	adds r1, r5, 0
	bl SetGpuReg
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8A0C

	thumb_func_start sub_80B8A44
sub_80B8A44: @ 80B8A44
	push {r4,lr}
	adds r4, r0, 0
	bl sub_80B8B28
	adds r0, r4, 0
	bl sub_80B8BF0
	lsls r0, 24
	cmp r0, 0
	beq _080B8A5E
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B8A5E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B8A44

	thumb_func_start sub_80B8A64
sub_80B8A64: @ 80B8A64
	push {r4,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r0, =0x04000008
	ldrh r1, [r0]
	lsrs r1, 8
	lsls r1, 27
	lsrs r1, 16
	movs r0, 0
	str r0, [sp]
	movs r0, 0xC0
	lsls r0, 19
	adds r1, r0
	ldr r2, =0x05000200
	mov r0, sp
	bl CpuSet
	adds r0, r4, 0
	adds r0, 0x22
	add r1, sp, 0x4
	bl LoadWordFromTwoHalfwords
	ldr r0, [sp, 0x4]
	bl SetVBlankCallback
	bl sub_8197200
	movs r0, 0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	ldrh r1, [r4, 0x26]
	lsls r1, 24
	lsrs r1, 24
	bl sub_80B6070
	movs r0, 0x6
	bl FieldEffectActiveListRemove
	ldr r0, =sub_80B88B4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8A64

	thumb_func_start sub_80B8AE0
sub_80B8AE0: @ 80B8AE0
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =sub_80B88B4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks
	adds r4, r0
	adds r0, r4, 0
	adds r0, 0x22
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	ldr r0, [sp]
	bl _call_via_r0
	ldrh r1, [r4, 0xA]
	movs r0, 0x10
	bl SetGpuReg
	ldrh r1, [r4, 0xC]
	movs r0, 0x12
	bl SetGpuReg
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8AE0

	thumb_func_start sub_80B8B28
sub_80B8B28: @ 80B8B28
	ldrh r1, [r0, 0xA]
	subs r1, 0x10
	strh r1, [r0, 0xA]
	ldrh r1, [r0, 0xE]
	adds r1, 0x10
	strh r1, [r0, 0xE]
	bx lr
	thumb_func_end sub_80B8B28

	thumb_func_start sub_80B8B38
sub_80B8B38: @ 80B8B38
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r5, r0, 0
	ldrh r2, [r5, 0x10]
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	cmp r0, 0x1F
	ble _080B8B54
	movs r0, 0x1
	b _080B8BD8
_080B8B54:
	ldrh r0, [r5, 0xE]
	lsls r0, 16
	asrs r3, r0, 19
	movs r1, 0x1F
	ands r3, r1
	movs r4, 0x10
	ldrsh r0, [r5, r4]
	cmp r3, r0
	blt _080B8BD6
	movs r0, 0x20
	subs r3, r0, r3
	ands r3, r1
	subs r0, r2
	mov r12, r0
	mov r7, r12
	ands r7, r1
	mov r12, r7
	ldrh r0, [r5, 0x20]
	ldr r1, =0x06000140
	adds r1, r0
	mov r8, r1
	movs r4, 0
	ldr r7, =gUnknown_0855B390
	mov r10, r7
	movs r0, 0xF0
	lsls r0, 8
	mov r9, r0
	adds r1, r3, 0x1
	movs r0, 0x1F
	ands r1, r0
	str r1, [sp]
	mov r6, r12
	adds r6, 0x1
	ands r6, r0
_080B8B98:
	lsls r1, r4, 5
	adds r2, r1, r3
	lsls r2, 1
	add r2, r8
	mov r7, r12
	adds r0, r7, r1
	lsls r0, 1
	add r0, r10
	ldrh r0, [r0]
	mov r7, r9
	orrs r0, r7
	strh r0, [r2]
	ldr r0, [sp]
	adds r2, r1, r0
	lsls r2, 1
	add r2, r8
	adds r1, r6, r1
	lsls r1, 1
	add r1, r10
	ldrh r0, [r1]
	mov r1, r9
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x9
	bls _080B8B98
	ldrh r0, [r5, 0x10]
	adds r0, 0x2
	strh r0, [r5, 0x10]
_080B8BD6:
	movs r0, 0
_080B8BD8:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B8B38

	thumb_func_start sub_80B8BF0
sub_80B8BF0: @ 80B8BF0
	push {r4-r7,lr}
	adds r5, r0, 0
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	cmp r0, 0x1F
	ble _080B8C00
	movs r0, 0x1
	b _080B8C54
_080B8C00:
	ldrh r0, [r5, 0xE]
	lsls r0, 16
	asrs r0, 19
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	cmp r2, r0
	blt _080B8C52
	ldrh r0, [r5, 0xA]
	lsls r0, 16
	asrs r2, r0, 19
	movs r0, 0x1F
	ands r2, r0
	ldrh r0, [r5, 0x20]
	ldr r1, =0x06000140
	adds r6, r0, r1
	movs r3, 0
	movs r0, 0xF0
	lsls r0, 8
	adds r7, r0, 0
	adds r4, r2, 0x1
	movs r0, 0x1F
	ands r4, r0
_080B8C30:
	lsls r0, r3, 5
	adds r1, r0, r2
	lsls r1, 1
	adds r1, r6
	strh r7, [r1]
	adds r0, r4
	lsls r0, 1
	adds r0, r6
	strh r7, [r0]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x9
	bls _080B8C30
	ldrh r0, [r5, 0x10]
	adds r0, 0x2
	strh r0, [r5, 0x10]
_080B8C52:
	movs r0, 0
_080B8C54:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B8BF0

	thumb_func_start sub_80B8C60
sub_80B8C60: @ 80B8C60
	push {r4-r6,lr}
	sub sp, 0x8
	adds r6, r0, 0
	movs r5, 0x80
	lsls r5, 24
	ands r5, r6
	lsrs r5, 16
	lsls r5, 16
	lsrs r5, 16
	ldr r0, =0x7fffffff
	ands r6, r0
	lsls r0, r6, 16
	lsrs r0, 16
	movs r3, 0xA0
	lsls r3, 1
	movs r4, 0x50
	str r4, [sp]
	movs r4, 0
	str r4, [sp, 0x4]
	bl sub_80B5FE8
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r1, =gSprites
	adds r2, r1
	ldr r1, =SpriteCallbackDummy
	str r1, [r2, 0x1C]
	ldrb r3, [r2, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r3
	strb r1, [r2, 0x5]
	strh r6, [r2, 0x2E]
	strh r5, [r2, 0x3A]
	add sp, 0x8
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B8C60

	thumb_func_start sub_80B8CC0
sub_80B8CC0: @ 80B8CC0
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x20]
	subs r0, 0x14
	strh r0, [r1, 0x20]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x78
	bgt _080B8D00
	movs r0, 0x78
	strh r0, [r1, 0x20]
	movs r0, 0x1E
	strh r0, [r1, 0x30]
	ldr r0, =sub_80B8D04
	str r0, [r1, 0x1C]
	movs r2, 0x3A
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _080B8CF8
	ldrh r0, [r1, 0x2E]
	movs r1, 0
	movs r2, 0x7D
	movs r3, 0xA
	bl PlayCry2
	b _080B8D00
	.pool
_080B8CF8:
	ldrh r0, [r1, 0x2E]
	movs r1, 0
	bl PlayCry1
_080B8D00:
	pop {r0}
	bx r0
	thumb_func_end sub_80B8CC0

	thumb_func_start sub_80B8D04
sub_80B8D04: @ 80B8D04
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x30]
	subs r0, 0x1
	strh r0, [r1, 0x30]
	lsls r0, 16
	cmp r0, 0
	bne _080B8D18
	ldr r0, =sub_80B8D20
	str r0, [r1, 0x1C]
_080B8D18:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8D04

	thumb_func_start sub_80B8D20
sub_80B8D20: @ 80B8D20
	push {lr}
	adds r2, r0, 0
	ldrh r3, [r2, 0x20]
	movs r0, 0x20
	ldrsh r1, [r2, r0]
	movs r0, 0x40
	negs r0, r0
	cmp r1, r0
	bge _080B8D38
	movs r0, 0x1
	strh r0, [r2, 0x3C]
	b _080B8D3E
_080B8D38:
	adds r0, r3, 0
	subs r0, 0x14
	strh r0, [r2, 0x20]
_080B8D3E:
	pop {r0}
	bx r0
	thumb_func_end sub_80B8D20

	thumb_func_start sub_80B8D44
sub_80B8D44: @ 80B8D44
	push {lr}
	ldr r0, =sub_80B8D84
	movs r1, 0xFF
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =gUnknown_02038C08
	ldr r0, [r0]
	strh r0, [r1, 0x26]
	bl sav1_reset_battle_music_maybe
	ldr r0, =0x0000016d
	bl sub_80858C4
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B8D44

	thumb_func_start sub_80B8D84
sub_80B8D84: @ 80B8D84
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0855C4E0
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8D84

	thumb_func_start sub_80B8DB4
sub_80B8DB4: @ 80B8DB4
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	adds r4, r0, 0
	bl script_env_2_enable
	bl player_bitmagic
	ldr r5, =gUnknown_02037590
	movs r0, 0x1
	strb r0, [r5, 0x6]
	movs r0, 0x8
	bl SetPlayerAvatarStateMask
	adds r6, r4, 0
	adds r6, 0xA
	movs r0, 0xC
	adds r0, r4
	mov r8, r0
	adds r0, r6, 0
	mov r1, r8
	bl PlayerGetDestCoords
	ldr r2, =gUnknown_02037350
	ldrb r1, [r5, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x18]
	lsrs r0, 4
	adds r1, r6, 0
	mov r2, r8
	bl MoveCoords
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8DB4

	thumb_func_start sub_80B8E14
sub_80B8E14: @ 80B8E14
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B8E3E
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B8E50
_080B8E3E:
	bl sub_808C114
	adds r0, r4, 0
	movs r1, 0x39
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_080B8E50:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8E14

	thumb_func_start sub_80B8E60
sub_80B8E60: @ 80B8E60
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	bl FieldObjectCheckIfSpecialAnimFinishedOrInactive
	lsls r0, 24
	cmp r0, 0
	beq _080B8E96
	ldr r2, =gUnknown_02038C08
	movs r1, 0x26
	ldrsh r0, [r4, r1]
	movs r1, 0x80
	lsls r1, 24
	orrs r0, r1
	str r0, [r2]
	movs r0, 0x3B
	bl FieldEffectStart
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B8E96:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8E60

	thumb_func_start sub_80B8EA8
sub_80B8EA8: @ 80B8EA8
	push {r4-r6,lr}
	adds r6, r0, 0
	movs r0, 0x6
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080B8F12
	ldr r5, =gUnknown_02037590
	ldrb r0, [r5, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gUnknown_02037350
	adds r4, r0
	movs r0, 0x3
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetGraphicsId
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl sub_8093540
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	ldr r1, =gUnknown_02038C08
	movs r2, 0xA
	ldrsh r0, [r6, r2]
	str r0, [r1]
	movs r2, 0xC
	ldrsh r0, [r6, r2]
	str r0, [r1, 0x4]
	ldrb r0, [r5, 0x5]
	str r0, [r1, 0x8]
	movs r0, 0x8
	bl FieldEffectStart
	strb r0, [r4, 0x1A]
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
_080B8F12:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8EA8

	thumb_func_start sub_80B8F24
sub_80B8F24: @ 80B8F24
	push {r4,r5,lr}
	ldr r5, =gUnknown_02037590
	ldrb r1, [r5, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B8F84
	movs r0, 0
	strb r0, [r5, 0x6]
	ldrb r1, [r5]
	movs r0, 0xDF
	ands r0, r1
	strb r0, [r5]
	ldrb r0, [r4, 0x18]
	lsrs r0, 4
	bl GetFaceDirectionAnimId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetSpecialAnim
	ldrb r0, [r4, 0x1A]
	movs r1, 0x1
	bl sub_81555AC
	bl sub_809757C
	bl script_env_2_disable
	movs r0, 0x9
	bl FieldEffectActiveListRemove
	ldr r0, =sub_80B8D84
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B8F84:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B8F24

	thumb_func_start sub_80B8F98
sub_80B8F98: @ 80B8F98
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =gFieldEffectObjectTemplatePointers
	adds r0, 0x90
	ldr r0, [r0]
	movs r2, 0x18
	negs r2, r2
	movs r1, 0x78
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	lsls r1, r0, 4
	add r1, r8
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x4
	orrs r0, r2
	movs r2, 0xF
	ands r0, r2
	movs r2, 0x40
	orrs r0, r2
	strb r0, [r1, 0x5]
	movs r2, 0
	strh r2, [r1, 0x2E]
	strh r2, [r1, 0x30]
	strh r2, [r1, 0x32]
	ldr r0, =0x0000ffff
	strh r0, [r1, 0x34]
	ldrh r0, [r1, 0x22]
	strh r0, [r1, 0x36]
	strh r2, [r1, 0x38]
	ldr r1, =0x00003e41
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000e0e
	movs r0, 0x52
	bl SetGpuReg
	ldr r1, =0x00003f3f
	movs r0, 0x48
	bl SetGpuReg
	ldr r0, =gUnknown_0855B610
	movs r1, 0xC0
	movs r2, 0x20
	bl LoadPalette
	movs r0, 0x12
	movs r1, 0x78
	bl SetGpuReg
	movs r4, 0x3
	ldr r7, =0x0600f800
	ldr r0, =0x0000bff4
	adds r6, r0, 0
_080B901A:
	movs r2, 0xC
	lsls r0, r4, 1
	lsls r5, r4, 5
	adds r0, r4
	lsls r3, r0, 1
_080B9024:
	adds r0, r5, r2
	lsls r0, 1
	adds r0, r7
	adds r1, r2, r6
	adds r1, r3, r1
	adds r1, 0x1
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x11
	bls _080B9024
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xE
	bls _080B901A
	movs r0, 0
	ldr r5, =gUnknown_0855B630
_080B904A:
	movs r4, 0
	adds r7, r0, 0x1
	lsls r6, r0, 5
_080B9050:
	lsls r1, r4, 2
	adds r1, r6, r1
	ldr r0, =0x06008020
	adds r3, r1, r0
	adds r0, r1, 0x1
	adds r0, r5
	ldrb r2, [r0]
	lsls r2, 8
	adds r0, r1, r5
	ldrb r0, [r0]
	adds r0, r2
	strh r0, [r3]
	ldr r0, =0x06008022
	adds r3, r1, r0
	adds r0, r1, 0x3
	adds r0, r5
	ldrb r2, [r0]
	lsls r2, 8
	adds r1, 0x2
	adds r1, r5
	ldrb r0, [r1]
	adds r0, r2
	strh r0, [r3]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x7
	bls _080B9050
	lsls r0, r7, 24
	lsrs r0, 24
	cmp r0, 0x59
	bls _080B904A
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B8F98

	thumb_func_start sub_80B90CC
sub_80B90CC: @ 80B90CC
	push {r4,lr}
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x68]
	movs r1, 0x78
	movs r2, 0
	movs r3, 0x1
	bl CreateSprite
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r2, r4, 4
	adds r2, r4
	lsls r2, 2
	ldr r0, =gSprites
	adds r2, r0
	ldrb r1, [r2, 0x5]
	movs r0, 0xF
	ands r0, r1
	movs r1, 0xD
	negs r1, r1
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x5]
	ldr r0, =sub_80B9128
	str r0, [r2, 0x1C]
	ldr r0, =gUnknown_02038C08
	ldr r0, [r0]
	strh r0, [r2, 0x30]
	movs r0, 0x9E
	bl PlaySE
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B90CC

	thumb_func_start sub_80B9128
sub_80B9128: @ 80B9128
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r1, 0x8C
	bl Cos
	movs r5, 0
	strh r0, [r4, 0x24]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r1, 0x48
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x4
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x32]
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080B918A
	movs r2, 0x30
	ldrsh r0, [r4, r2]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r3]
	ldrh r0, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r1, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	subs r0, 0x8
	strh r0, [r1, 0x22]
	strh r5, [r1, 0x24]
	strh r5, [r1, 0x26]
_080B918A:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	ble _080B919A
	adds r0, r4, 0
	movs r1, 0x1E
	bl FieldEffectStop
_080B919A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9128

	thumb_func_start sub_80B91A4
sub_80B91A4: @ 80B91A4
	push {lr}
	ldr r0, =sub_80B91D4
	movs r1, 0xFE
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldr r0, =gUnknown_02038C08
	ldr r0, [r0]
	strh r0, [r1, 0xA]
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B91A4

	thumb_func_start sub_80B91D4
sub_80B91D4: @ 80B91D4
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0855C4F4
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B91D4

	thumb_func_start sub_80B9204
sub_80B9204: @ 80B9204
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gUnknown_02037590
	ldrb r1, [r6, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B922E
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B924C
_080B922E:
	ldrb r0, [r6]
	strh r0, [r5, 0x26]
	movs r0, 0x1
	strb r0, [r6, 0x6]
	bl SetPlayerAvatarStateMask
	bl sub_808C114
	adds r0, r4, 0
	movs r1, 0x39
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_080B924C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9204

	thumb_func_start sub_80B925C
sub_80B925C: @ 80B925C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B928C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldr r1, =gUnknown_02038C08
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	str r0, [r1]
	movs r0, 0x3B
	bl FieldEffectStart
_080B928C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B925C

	thumb_func_start sub_80B92A0
sub_80B92A0: @ 80B92A0
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r0, 0x6
	bl FieldEffectActiveListContains
	lsls r0, 24
	cmp r0, 0
	bne _080B92E8
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r5, r0, r1
	ldrh r1, [r4, 0x26]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080B92D8
	ldrb r0, [r5, 0x1A]
	movs r1, 0x2
	bl sub_81555AC
	ldrb r0, [r5, 0x1A]
	movs r1, 0
	bl sub_81555D8
_080B92D8:
	bl sub_80B94C4
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xA]
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B92E8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B92A0

	thumb_func_start sub_80B92F8
sub_80B92F8: @ 80B92F8
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0xA]
	bl sub_80B9508
	lsls r0, 24
	cmp r0, 0
	beq _080B932C
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x10
	strh r0, [r4, 0xC]
	movs r0, 0x1
	bl SetPlayerAvatarTransitionFlags
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	movs r1, 0x2
	bl FieldObjectSetSpecialAnim
_080B932C:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B92F8

	thumb_func_start sub_80B933C
sub_80B933C: @ 80B933C
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r2, r0, r1
	ldrh r1, [r4, 0xC]
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	cmp r0, 0
	beq _080B9362
	subs r0, r1, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _080B9380
_080B9362:
	adds r0, r2, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B9380
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x9E
	bl PlaySE
	ldrb r0, [r4, 0xA]
	bl sub_80B9524
_080B9380:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B933C

	thumb_func_start sub_80B9390
sub_80B9390: @ 80B9390
	push {r4-r6,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0xC]
	adds r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x7
	ble _080B9406
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r4, r0, r1
	movs r0, 0x3
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetGraphicsId
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r6, =gSprites
	adds r0, r6
	movs r1, 0x16
	bl StartSpriteAnim
	ldrb r0, [r4, 0x1]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4, 0x1]
	adds r0, r4, 0
	movs r1, 0x48
	bl FieldObjectSetSpecialAnim
	ldrh r1, [r5, 0x26]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080B93FC
	ldrb r1, [r4, 0x1A]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl DestroySprite
_080B93FC:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0
	strh r0, [r5, 0xC]
_080B9406:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9390

	thumb_func_start sub_80B9418
sub_80B9418: @ 80B9418
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0xC]
	adds r0, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x9
	ble _080B9464
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x5]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gUnknown_02037350
	adds r4, r0
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimActive
	ldrb r1, [r4, 0x1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	ldrb r1, [r4, 0x2]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x2]
	ldrb r0, [r5, 0xA]
	ldrb r1, [r4, 0x4]
	bl sub_80B9560
	bl CameraObjectReset2
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
_080B9464:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9418

	thumb_func_start sub_80B9474
sub_80B9474: @ 80B9474
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0xA]
	bl sub_80B9508
	lsls r0, 24
	cmp r0, 0
	beq _080B948E
	bl sub_80AF0B4
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B948E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80B9474

	thumb_func_start sub_80B9494
sub_80B9494: @ 80B9494
	push {lr}
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080B94B6
	movs r0, 0x1F
	bl FieldEffectActiveListRemove
	ldr r0, =sub_80B91D4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B94B6:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9494

	thumb_func_start sub_80B94C4
sub_80B94C4: @ 80B94C4
	push {lr}
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x68]
	movs r1, 0xFF
	movs r2, 0xB4
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	ldr r1, =gSprites
	adds r2, r1
	ldrb r3, [r2, 0x5]
	movs r1, 0xF
	ands r1, r3
	movs r3, 0xD
	negs r3, r3
	ands r1, r3
	movs r3, 0x4
	orrs r1, r3
	strb r1, [r2, 0x5]
	ldr r1, =sub_80B957C
	str r1, [r2, 0x1C]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B94C4

	thumb_func_start sub_80B9508
sub_80B9508: @ 80B9508
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gSprites
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrh r0, [r1, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	bx lr
	.pool
	thumb_func_end sub_80B9508

	thumb_func_start sub_80B9524
sub_80B9524: @ 80B9524
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	ldr r0, =sub_80B963C
	str r0, [r4, 0x1C]
	movs r1, 0
	movs r0, 0x78
	strh r0, [r4, 0x20]
	strh r1, [r4, 0x22]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x26]
	adds r0, r4, 0
	adds r0, 0x2E
	movs r2, 0x10
	bl memset
	movs r0, 0x40
	strh r0, [r4, 0x3A]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9524

	thumb_func_start sub_80B9560
sub_80B9560: @ 80B9560
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gSprites
	lsls r2, r0, 4
	adds r2, r0
	lsls r2, 2
	adds r2, r3
	strh r1, [r2, 0x3A]
	bx lr
	.pool
	thumb_func_end sub_80B9560

	thumb_func_start sub_80B957C
sub_80B957C: @ 80B957C
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B9628
	movs r1, 0x2E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B95C0
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldr r0, =gUnknown_0855C548
	str r0, [r4, 0x10]
	adds r0, r4, 0
	bl InitSpriteAffineAnim
	adds r0, r4, 0
	movs r1, 0
	bl StartSpriteAffineAnim
	movs r0, 0x76
	strh r0, [r4, 0x20]
	ldr r0, =0x0000ffd0
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0x40
	strh r0, [r4, 0x30]
	adds r0, 0xC0
	strh r0, [r4, 0x32]
_080B95C0:
	ldrh r0, [r4, 0x32]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r4, 0x30]
	adds r0, r1
	strh r0, [r4, 0x30]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x78
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x78
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r2, [r4, 0x32]
	movs r0, 0x32
	ldrsh r1, [r4, r0]
	ldr r0, =0x000007ff
	cmp r1, r0
	bgt _080B95F6
	adds r0, r2, 0
	adds r0, 0x60
	strh r0, [r4, 0x32]
_080B95F6:
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	cmp r0, 0x81
	ble _080B9628
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	ldrb r1, [r4, 0x1]
	lsrs r1, 6
	ldrb r2, [r4, 0x3]
	lsrs r2, 6
	adds r0, r4, 0
	movs r3, 0
	bl CalcCenterToCornerVec
_080B9628:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B957C

	thumb_func_start sub_80B963C
sub_80B963C: @ 80B963C
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	movs r1, 0x8C
	bl Cos
	movs r5, 0
	strh r0, [r4, 0x24]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r1, 0x48
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r0, [r4, 0x32]
	adds r0, 0x4
	movs r1, 0xFF
	ands r0, r1
	strh r0, [r4, 0x32]
	movs r1, 0x3A
	ldrsh r0, [r4, r1]
	cmp r0, 0x40
	beq _080B969A
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r2, [r3]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r3]
	ldrh r0, [r4, 0x24]
	ldrh r2, [r4, 0x20]
	adds r0, r2
	strh r0, [r1, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	subs r0, 0x8
	strh r0, [r1, 0x22]
	strh r5, [r1, 0x24]
	strh r5, [r1, 0x26]
_080B969A:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0x7F
	ble _080B96A6
	movs r0, 0x1
	strh r0, [r4, 0x3C]
_080B96A6:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B963C

	thumb_func_start sub_80B96B0
sub_80B96B0: @ 80B96B0
	push {r4,lr}
	adds r4, r0, 0
	movs r1, 0x3C
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B9784
	movs r2, 0x2E
	ldrsh r0, [r4, r2]
	cmp r0, 0
	bne _080B96FA
	ldrb r0, [r4, 0x1]
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r4, 0x1]
	ldr r0, =gUnknown_0855C548
	str r0, [r4, 0x10]
	adds r0, r4, 0
	bl InitSpriteAffineAnim
	adds r0, r4, 0
	movs r1, 0x1
	bl StartSpriteAffineAnim
	movs r0, 0x5E
	strh r0, [r4, 0x20]
	ldr r0, =0x0000ffe0
	strh r0, [r4, 0x22]
	ldrh r0, [r4, 0x2E]
	adds r0, 0x1
	strh r0, [r4, 0x2E]
	movs r0, 0xF0
	strh r0, [r4, 0x30]
	movs r0, 0x80
	lsls r0, 4
	strh r0, [r4, 0x32]
	movs r0, 0x80
	strh r0, [r4, 0x36]
_080B96FA:
	ldrh r1, [r4, 0x32]
	lsls r1, 16
	asrs r1, 24
	ldrh r2, [r4, 0x30]
	adds r2, r1
	ldrh r0, [r4, 0x34]
	adds r0, r1
	strh r0, [r4, 0x34]
	movs r0, 0xFF
	ands r2, r0
	strh r2, [r4, 0x30]
	movs r3, 0x30
	ldrsh r0, [r4, r3]
	movs r1, 0x20
	bl Cos
	strh r0, [r4, 0x24]
	movs r1, 0x30
	ldrsh r0, [r4, r1]
	movs r1, 0x78
	bl Sin
	strh r0, [r4, 0x26]
	ldrh r1, [r4, 0x32]
	movs r2, 0x32
	ldrsh r0, [r4, r2]
	movs r2, 0x80
	lsls r2, 1
	cmp r0, r2
	ble _080B973C
	ldrh r0, [r4, 0x36]
	subs r0, r1, r0
	strh r0, [r4, 0x32]
_080B973C:
	ldrh r1, [r4, 0x36]
	movs r3, 0x36
	ldrsh r0, [r4, r3]
	cmp r0, 0xFF
	bgt _080B974C
	adds r0, r1, 0
	adds r0, 0x18
	strh r0, [r4, 0x36]
_080B974C:
	movs r1, 0x32
	ldrsh r0, [r4, r1]
	cmp r0, 0xFF
	bgt _080B9756
	strh r2, [r4, 0x32]
_080B9756:
	movs r2, 0x34
	ldrsh r0, [r4, r2]
	cmp r0, 0x3B
	ble _080B9784
	ldrh r0, [r4, 0x3C]
	adds r0, 0x1
	strh r0, [r4, 0x3C]
	ldrb r1, [r4, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	ldrb r0, [r4, 0x3]
	lsls r0, 26
	lsrs r0, 27
	bl FreeOamMatrix
	adds r2, r4, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
_080B9784:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B96B0

	thumb_func_start sub_80B9794
sub_80B9794: @ 80B9794
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl sub_80B9524
	ldr r1, =gSprites
	lsls r0, r4, 4
	adds r0, r4
	lsls r0, 2
	adds r1, 0x1C
	adds r0, r1
	ldr r1, =sub_80B96B0
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9794

	thumb_func_start sub_80B97C0
sub_80B97C0: @ 80B97C0
	push {lr}
	ldr r0, =sub_80B97D4
	movs r1, 0xFE
	bl CreateTask
	movs r0, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B97C0

	thumb_func_start sub_80B97D4
sub_80B97D4: @ 80B97D4
	push {lr}
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	ldr r3, =gUnknown_0855C550
	ldr r2, =gTasks
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	movs r2, 0x8
	ldrsh r1, [r0, r2]
	lsls r1, 2
	adds r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B97D4

	thumb_func_start sub_80B9804
sub_80B9804: @ 80B9804
	push {r4-r6,lr}
	adds r5, r0, 0
	ldr r6, =gUnknown_02037590
	ldrb r1, [r6, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r4, r0, r1
	adds r0, r4, 0
	bl FieldObjectIsSpecialAnimOrDirectionSequenceAnimActive
	lsls r0, 24
	cmp r0, 0
	beq _080B982E
	adds r0, r4, 0
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B98A6
_080B982E:
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	movs r0, 0x11
	strh r0, [r5, 0xC]
	ldrb r0, [r6]
	strh r0, [r5, 0x26]
	movs r0, 0x1
	strb r0, [r6, 0x6]
	bl SetPlayerAvatarStateMask
	ldrh r1, [r5, 0x26]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080B9856
	ldrb r0, [r4, 0x1A]
	movs r1, 0
	bl sub_81555AC
_080B9856:
	movs r0, 0x3
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetGraphicsId
	bl CameraObjectReset2
	adds r0, r4, 0
	movs r1, 0x3
	bl FieldObjectTurn
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	movs r1, 0x16
	bl StartSpriteAnim
	ldrb r1, [r4, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r4, 0x1]
	bl sub_80B94C4
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r5, 0xA]
	bl sub_80B9524
	ldrb r0, [r5, 0xA]
	ldrb r1, [r4, 0x4]
	bl sub_80B9560
_080B98A6:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9804

	thumb_func_start sub_80B98B8
sub_80B98B8: @ 80B98B8
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r1, [r5, 0xC]
	movs r2, 0xC
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _080B98D0
	subs r0, r1, 0x1
	strh r0, [r5, 0xC]
	lsls r0, 16
	cmp r0, 0
	bne _080B9910
_080B98D0:
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	ldrb r0, [r0, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	ldrb r0, [r5, 0xA]
	movs r1, 0x40
	bl sub_80B9560
	ldrh r0, [r4, 0x24]
	ldrh r1, [r4, 0x20]
	adds r0, r1
	movs r1, 0
	strh r0, [r4, 0x20]
	ldrh r0, [r4, 0x26]
	ldrh r2, [r4, 0x22]
	adds r0, r2
	strh r0, [r4, 0x22]
	strh r1, [r4, 0x24]
	strh r1, [r4, 0x26]
	ldrh r0, [r5, 0x8]
	adds r0, 0x1
	strh r0, [r5, 0x8]
	strh r1, [r5, 0xC]
_080B9910:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B98B8

	thumb_func_start sub_80B9924
sub_80B9924: @ 80B9924
	push {r4,lr}
	sub sp, 0x24
	adds r4, r0, 0
	ldr r1, =gUnknown_0855C56C
	mov r0, sp
	movs r2, 0x24
	bl memcpy
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	lsls r0, 1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r1, 0x26]
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x11
	ble _080B9962
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
_080B9962:
	add sp, 0x24
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9924

	thumb_func_start sub_80B9978
sub_80B9978: @ 80B9978
	push {r4-r6,lr}
	adds r6, r0, 0
	ldrb r0, [r6, 0xA]
	bl sub_80B9508
	lsls r0, 24
	cmp r0, 0
	beq _080B99DC
	ldr r0, =gUnknown_02037590
	ldrb r0, [r0, 0x5]
	lsls r5, r0, 3
	adds r5, r0
	lsls r5, 2
	ldr r0, =gUnknown_02037350
	adds r5, r0
	ldrb r0, [r5, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	ldrb r1, [r5, 0x1]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x1]
	movs r0, 0x10
	ldrsh r1, [r5, r0]
	movs r0, 0x12
	ldrsh r2, [r5, r0]
	adds r0, r5, 0
	bl sub_808EB08
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	adds r4, 0x3E
	ldrb r0, [r4]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r4]
	bl sub_808C114
	adds r0, r5, 0
	movs r1, 0x39
	bl FieldObjectSetSpecialAnim
	ldrh r0, [r6, 0x8]
	adds r0, 0x1
	strh r0, [r6, 0x8]
_080B99DC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9978

	thumb_func_start sub_80B99F0
sub_80B99F0: @ 80B99F0
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, =gUnknown_02037590
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r0, r1
	bl FieldObjectClearAnimIfSpecialAnimFinished
	lsls r0, 24
	cmp r0, 0
	beq _080B9A18
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	ldrb r0, [r4, 0xA]
	bl sub_80B9794
_080B9A18:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B99F0

	thumb_func_start sub_80B9A28
sub_80B9A28: @ 80B9A28
	push {r4,lr}
	adds r4, r0, 0
	ldrb r0, [r4, 0xA]
	bl sub_80B9508
	lsls r0, 24
	cmp r0, 0
	beq _080B9A54
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
	ldrh r0, [r4, 0x8]
	adds r0, 0x1
	strh r0, [r4, 0x8]
	movs r0, 0x10
	strh r0, [r4, 0xA]
_080B9A54:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9A28

	thumb_func_start sub_80B9A60
sub_80B9A60: @ 80B9A60
	push {r4-r7,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0xA]
	subs r0, 0x1
	strh r0, [r5, 0xA]
	lsls r0, 16
	cmp r0, 0
	bne _080B9ACA
	ldr r6, =gUnknown_02037590
	ldrb r1, [r6, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	ldr r1, =gUnknown_02037350
	adds r4, r0, r1
	movs r7, 0
	ldrh r1, [r5, 0x26]
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _080B9A94
	movs r7, 0x3
	ldrb r0, [r4, 0x1A]
	movs r1, 0x1
	bl sub_81555AC
_080B9A94:
	adds r0, r7, 0
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl FieldObjectSetGraphicsId
	adds r0, r4, 0
	movs r1, 0x1
	bl FieldObjectTurn
	ldrh r0, [r5, 0x26]
	strb r0, [r6]
	movs r0, 0
	strb r0, [r6, 0x6]
	movs r0, 0x20
	bl FieldEffectActiveListRemove
	ldr r0, =sub_80B97D4
	bl FindTaskIdByFunc
	lsls r0, 24
	lsrs r0, 24
	bl DestroyTask
_080B9ACA:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9A60

	thumb_func_start sub_80B9ADC
sub_80B9ADC: @ 80B9ADC
	push {r4,lr}
	sub sp, 0x4
	ldr r4, =gUnknown_02038C08
	ldrb r0, [r4]
	ldrb r1, [r4, 0x4]
	ldrb r2, [r4, 0x8]
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _080B9B2C
	ldr r0, =sub_80B9BE8
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r1, 0xC]
	ldr r0, [r4]
	strh r0, [r1, 0x14]
	ldr r0, [r4, 0x4]
	strh r0, [r1, 0x16]
	ldr r0, [r4, 0x8]
	strh r0, [r1, 0x18]
	b _080B9B32
	.pool
_080B9B2C:
	movs r0, 0x41
	bl FieldEffectActiveListRemove
_080B9B32:
	movs r0, 0
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_80B9ADC

	thumb_func_start sub_80B9B3C
sub_80B9B3C: @ 80B9B3C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	movs r1, 0xE
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080B9B78
	ldrh r0, [r4, 0xC]
	adds r0, 0x1
	strh r0, [r4, 0xC]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _080B9B7C
	movs r0, 0
	strh r0, [r4, 0xC]
	ldrh r1, [r4, 0xA]
	movs r2, 0xA
	ldrsh r0, [r4, r2]
	cmp r0, 0
	beq _080B9B7C
	subs r0, r1, 0x1
	b _080B9B7A
	.pool
_080B9B78:
	movs r0, 0x4
_080B9B7A:
	strh r0, [r4, 0xA]
_080B9B7C:
	ldrh r0, [r4]
	adds r0, 0x1
	strh r0, [r4]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	ble _080B9BB6
	movs r0, 0
	strh r0, [r4]
	ldrh r0, [r4, 0x2]
	adds r0, 0x1
	strh r0, [r4, 0x2]
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080B9BAC
	ldrh r1, [r4, 0xA]
	negs r1, r1
	lsls r1, 16
	asrs r1, 16
	movs r0, 0
	bl SetCameraPanning
	b _080B9BB6
_080B9BAC:
	movs r0, 0xA
	ldrsh r1, [r4, r0]
	movs r0, 0
	bl SetCameraPanning
_080B9BB6:
	bl UpdateCameraPanning
	movs r1, 0xA
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080B9BC8
	adds r0, r5, 0
	bl DestroyTask
_080B9BC8:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80B9B3C

	thumb_func_start sub_80B9BD0
sub_80B9BD0: @ 80B9BD0
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	movs r0, 0x1
	strh r0, [r1, 0x16]
	bx lr
	.pool
	thumb_func_end sub_80B9BD0

	thumb_func_start sub_80B9BE8
sub_80B9BE8: @ 80B9BE8
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	bl InstallCameraPanAheadCallback
	movs r0, 0
	bl SetCameraPanningCallback
	ldr r1, =gUnknown_0855C590
	movs r2, 0x2
	ldrsh r0, [r4, r2]
	lsls r0, 2
	adds r0, r1
	ldr r2, [r0]
	adds r0, r4, 0
	adds r1, r5, 0
	bl _call_via_r2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9BE8

	thumb_func_start sub_80B9C28
sub_80B9C28: @ 80B9C28
	push {r4,r5,lr}
	adds r5, r0, 0
	ldr r0, =sub_80B9B3C
	movs r1, 0x5A
	bl CreateTask
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x58
	bl PlaySE
	strh r4, [r5, 0xA]
	ldrh r0, [r5, 0x2]
	adds r0, 0x1
	strh r0, [r5, 0x2]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9C28

	thumb_func_start sub_80B9C54
sub_80B9C54: @ 80B9C54
	push {r4-r7,lr}
	sub sp, 0x4
	adds r7, r0, 0
	ldrh r0, [r7, 0x6]
	adds r0, 0x1
	strh r0, [r7, 0x6]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x78
	ble _080B9CC2
	ldr r2, =gUnknown_02037350
	movs r1, 0x4
	ldrsh r0, [r7, r1]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x4]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	ldrb r0, [r1, 0x1]
	movs r2, 0x20
	orrs r0, r2
	strb r0, [r1, 0x1]
	ldr r6, =0x0000ffff
	ldr r5, =0x00007fff
	adds r0, r6, 0
	movs r1, 0x10
	adds r2, r5, 0
	bl BlendPalettes
	str r5, [sp]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0x10
	movs r3, 0
	bl BeginNormalPaletteFade
	adds r0, r4, 0
	bl sub_80B9D24
	movs r0, 0x57
	bl PlaySE
	ldrb r0, [r7, 0xA]
	bl sub_80B9BD0
	movs r0, 0
	strh r0, [r7, 0x6]
	ldrh r0, [r7, 0x2]
	adds r0, 0x1
	strh r0, [r7, 0x2]
_080B9CC2:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9C54

	thumb_func_start sub_80B9CDC
sub_80B9CDC: @ 80B9CDC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =gPaletteFade
	ldrb r1, [r0, 0x7]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080B9D16
	ldr r0, =sub_80B9B3C
	bl FuncIsActiveTask
	lsls r0, 24
	cmp r0, 0
	bne _080B9D16
	bl InstallCameraPanAheadCallback
	ldrb r0, [r4, 0xC]
	ldrb r1, [r4, 0xE]
	ldrb r2, [r4, 0x10]
	bl RemoveFieldObjectByLocalIdAndMap
	movs r0, 0x41
	bl FieldEffectActiveListRemove
	adds r0, r5, 0
	bl DestroyTask
_080B9D16:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9CDC

	thumb_func_start sub_80B9D24
sub_80B9D24: @ 80B9D24
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	ldr r0, =gUnknown_03005DEC
	movs r1, 0
	ldrsh r2, [r0, r1]
	movs r3, 0x20
	ldrsh r0, [r6, r3]
	adds r2, r0
	movs r1, 0x24
	ldrsh r0, [r6, r1]
	adds r2, r0
	ldr r0, =gUnknown_03005DE8
	movs r3, 0
	ldrsh r0, [r0, r3]
	movs r3, 0x22
	ldrsh r1, [r6, r3]
	adds r0, r1
	movs r3, 0x26
	ldrsh r1, [r6, r3]
	adds r0, r1
	subs r0, 0x4
	movs r5, 0
	lsls r2, 16
	mov r8, r2
	lsls r7, r0, 16
_080B9D5A:
	ldr r0, =gUnknown_0855C5EC
	mov r2, r8
	asrs r1, r2, 16
	asrs r2, r7, 16
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _080B9D96
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	lsls r1, r5, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl StartSpriteAnim
	strh r5, [r4, 0x2E]
	ldrb r1, [r6, 0x5]
	lsrs r1, 4
	lsls r1, 4
	ldrb r2, [r4, 0x5]
	movs r0, 0xF
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, 0x5]
_080B9D96:
	adds r5, 0x1
	cmp r5, 0x3
	ble _080B9D5A
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9D24

	thumb_func_start sub_80B9DB8
sub_80B9DB8: @ 80B9DB8
	push {lr}
	adds r1, r0, 0
	movs r2, 0x2E
	ldrsh r0, [r1, r2]
	cmp r0, 0x1
	beq _080B9DE4
	cmp r0, 0x1
	bgt _080B9DCE
	cmp r0, 0
	beq _080B9DD8
	b _080B9E02
_080B9DCE:
	cmp r0, 0x2
	beq _080B9DF0
	cmp r0, 0x3
	beq _080B9DF6
	b _080B9E02
_080B9DD8:
	ldrh r0, [r1, 0x20]
	subs r0, 0x10
	strh r0, [r1, 0x20]
	ldrh r0, [r1, 0x22]
	subs r0, 0xC
	b _080B9E00
_080B9DE4:
	ldrh r0, [r1, 0x20]
	adds r0, 0x10
	strh r0, [r1, 0x20]
	ldrh r0, [r1, 0x22]
	subs r0, 0xC
	b _080B9E00
_080B9DF0:
	ldrh r0, [r1, 0x20]
	subs r0, 0x10
	b _080B9DFA
_080B9DF6:
	ldrh r0, [r1, 0x20]
	adds r0, 0x10
_080B9DFA:
	strh r0, [r1, 0x20]
	ldrh r0, [r1, 0x22]
	adds r0, 0xC
_080B9E00:
	strh r0, [r1, 0x22]
_080B9E02:
	ldrh r0, [r1, 0x20]
	adds r0, 0x4
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0xF8
	bhi _080B9E1E
	movs r0, 0x22
	ldrsh r2, [r1, r0]
	movs r0, 0x4
	negs r0, r0
	cmp r2, r0
	blt _080B9E1E
	cmp r2, 0xA4
	ble _080B9E24
_080B9E1E:
	adds r0, r1, 0
	bl DestroySprite
_080B9E24:
	pop {r0}
	bx r0
	thumb_func_end sub_80B9DB8

	thumb_func_start sub_80B9E28
sub_80B9E28: @ 80B9E28
	push {r4-r7,lr}
	sub sp, 0x4
	ldr r7, =gUnknown_02038C08
	ldrb r0, [r7]
	ldrb r1, [r7, 0x4]
	ldrb r2, [r7, 0x8]
	mov r3, sp
	bl TryGetFieldObjectIdByLocalIdAndMap
	lsls r0, 24
	cmp r0, 0
	bne _080B9EBE
	mov r0, sp
	ldrb r0, [r0]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gUnknown_02037350
	adds r4, r0
	movs r0, 0x10
	ldrsh r5, [r4, r0]
	subs r5, 0x7
	movs r0, 0x12
	ldrsh r6, [r4, r0]
	subs r6, 0x7
	ldr r1, [r7, 0xC]
	subs r5, r1, r5
	lsls r5, 4
	ldr r2, [r7, 0x10]
	subs r6, r2, r6
	lsls r6, 4
	adds r1, 0x7
	lsls r1, 16
	asrs r1, 16
	adds r2, 0x7
	lsls r2, 16
	asrs r2, 16
	adds r0, r4, 0
	bl npc_coords_shift
	ldr r0, =sub_80B9EDC
	movs r1, 0x50
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gTasks
	lsls r2, r0, 2
	adds r2, r0
	lsls r2, 3
	adds r2, r1
	ldrb r0, [r4, 0x4]
	strh r0, [r2, 0xA]
	ldr r3, =gSprites
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0, 0x20]
	adds r0, r5
	strh r0, [r2, 0xC]
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldrh r0, [r0, 0x22]
	adds r0, r6
	strh r0, [r2, 0xE]
	ldr r0, [r7, 0x14]
	strh r0, [r2, 0x18]
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r2, 0x1A]
_080B9EBE:
	movs r0, 0
	add sp, 0x4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80B9E28

	thumb_func_start sub_80B9EDC
sub_80B9EDC: @ 80B9EDC
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r0, r7, 2
	adds r0, r7
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r5, r0, r1
	movs r0, 0x2
	ldrsh r1, [r5, r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r6, r0, r1
	movs r1, 0
	ldrsh r0, [r5, r1]
	cmp r0, 0
	beq _080B9F10
	cmp r0, 0x1
	beq _080B9F4E
	b _080B9FAC
	.pool
_080B9F10:
	ldrh r0, [r6, 0x20]
	lsls r0, 4
	strh r0, [r5, 0x8]
	ldrh r0, [r6, 0x22]
	lsls r0, 4
	strh r0, [r5, 0xA]
	movs r2, 0x4
	ldrsh r0, [r5, r2]
	lsls r0, 4
	movs r2, 0x8
	ldrsh r1, [r5, r2]
	subs r0, r1
	movs r2, 0x10
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r5, 0xC]
	movs r1, 0x6
	ldrsh r0, [r5, r1]
	lsls r0, 4
	movs r2, 0xA
	ldrsh r1, [r5, r2]
	subs r0, r1
	movs r2, 0x10
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r5, 0xE]
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
_080B9F4E:
	ldrh r1, [r5, 0x10]
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	cmp r0, 0
	beq _080B9F7C
	subs r0, r1, 0x1
	strh r0, [r5, 0x10]
	ldrh r1, [r5, 0xC]
	ldrh r0, [r5, 0x8]
	adds r1, r0
	strh r1, [r5, 0x8]
	ldrh r0, [r5, 0xE]
	ldrh r2, [r5, 0xA]
	adds r0, r2
	strh r0, [r5, 0xA]
	lsls r1, 16
	asrs r1, 20
	strh r1, [r6, 0x20]
	ldrh r0, [r5, 0xA]
	lsls r0, 16
	asrs r0, 20
	strh r0, [r6, 0x22]
	b _080B9FAC
_080B9F7C:
	movs r1, 0x12
	ldrsh r0, [r5, r1]
	lsls r4, r0, 3
	adds r4, r0
	lsls r4, 2
	ldr r0, =gUnknown_02037350
	adds r4, r0
	ldrh r0, [r5, 0x4]
	strh r0, [r6, 0x20]
	ldrh r0, [r5, 0x6]
	strh r0, [r6, 0x22]
	adds r0, r4, 0
	bl npc_coords_shift_still
	ldrb r0, [r4]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0x42
	bl FieldEffectActiveListRemove
	adds r0, r7, 0
	bl DestroyTask
_080B9FAC:
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80B9EDC

	.align 2, 0 @ Don't pad with nop.
