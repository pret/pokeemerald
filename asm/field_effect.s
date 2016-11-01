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
	bl GetObjectTileRangeStartByTag
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	bne _080B5C5A
	adds r0, r5, 0
	bl LoadObjectPic
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
	bl LoadTaggedObjectPalette
	ldrh r0, [r4, 0x4]
	bl IndexOfObjectPaletteTag
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
	bl LoadTaggedObjectPalette
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
	bl RemoveObjectAndFreeTiles
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
	bl GetTagByObjectTileRangeStart
	lsls r0, 16
	lsrs r3, r0, 16
	ldr r0, =0x0000ffff
	cmp r3, r0
	beq _080B5D58
	movs r2, 0
	ldr r5, =gUnknown_02020630
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
	bl FreeObjectTilesByTag
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
	bl GetObjectPaletteTagBySlot
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, =0x0000ffff
	cmp r5, r0
	beq _080B5DB0
	movs r2, 0
	ldr r6, =gUnknown_02020630
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
	bl FreeObjectPaletteByTag
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

	.align 2, 0 @ Don't pad with nop.
