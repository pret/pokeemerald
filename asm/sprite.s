	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text


	thumb_func_start FreeSpriteTilesByTag
@ void FreeSpriteTilesByTag(u16 tag)
FreeSpriteTilesByTag: @ 8008568
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r0, 16
	bl IndexOfObjectTilesTag
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFF
	beq _080085C6
	ldr r0, =gUnknown_03000A70
	lsls r1, r4, 2
	adds r2, r1, r0
	adds r0, 0x2
	adds r1, r0
	ldrh r0, [r1]
	ldrh r3, [r2]
	adds r0, r3, r0
	ldr r1, =gUnknown_030009F0
	mov r8, r1
	lsls r5, r4, 1
	cmp r3, r0
	bge _080085BE
	ldr r1, =gSpriteTileAllocBitmap
	mov r12, r1
	movs r6, 0x7
	movs r7, 0x1
	adds r4, r0, 0
_080085A2:
	lsrs r2, r3, 3
	add r2, r12
	adds r0, r3, 0
	ands r0, r6
	adds r1, r7, 0
	lsls r1, r0
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, r4
	blt _080085A2
_080085BE:
	mov r0, r8
	adds r1, r5, r0
	ldr r0, =0x0000ffff
	strh r0, [r1]
_080085C6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeSpriteTilesByTag

	thumb_func_start FreeSpriteTileRanges
@ void FreeSpriteTileRanges()
FreeSpriteTileRanges: @ 80085E0
	push {r4-r7,lr}
	movs r2, 0
	ldr r7, =gUnknown_030009F0
	ldr r0, =0x0000ffff
	adds r6, r0, 0
	ldr r4, =gUnknown_03000A70
	movs r3, 0
	adds r5, r4, 0x2
_080085F0:
	lsls r1, r2, 1
	adds r1, r7
	ldrh r0, [r1]
	orrs r0, r6
	strh r0, [r1]
	lsls r1, r2, 2
	adds r0, r1, r4
	strh r3, [r0]
	adds r1, r5
	strh r3, [r1]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3F
	bls _080085F0
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeSpriteTileRanges

	thumb_func_start GetSpriteTileStartByTag
@ u16 GetSpriteTileStartByTag(u16 tag)
GetSpriteTileStartByTag: @ 8008620
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl IndexOfObjectTilesTag
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _08008640
	ldr r0, =gUnknown_03000A70
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1]
	b _08008642
	.pool
_08008640:
	ldr r0, =0x0000ffff
_08008642:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetSpriteTileStartByTag

	thumb_func_start IndexOfObjectTilesTag
@ u8 IndexOfObjectTilesTag(u16 tag)
IndexOfObjectTilesTag: @ 800864C
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	movs r1, 0
	ldr r3, =gUnknown_030009F0
_08008656:
	lsls r0, r1, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _08008668
	adds r0, r1, 0
	b _08008674
	.pool
_08008668:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3F
	bls _08008656
	movs r0, 0xFF
_08008674:
	pop {r1}
	bx r1
	thumb_func_end IndexOfObjectTilesTag

	thumb_func_start GetTagByObjectTileRangeStart
@ u16 GetTagByObjectTileRangeStart(u16 rangeStart)
GetTagByObjectTileRangeStart: @ 8008678
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r6, =gUnknown_030009F0
	ldr r5, =0x0000ffff
	ldr r4, =gUnknown_03000A70
_08008686:
	lsls r0, r2, 1
	adds r1, r0, r6
	ldrh r0, [r1]
	cmp r0, r5
	beq _080086AC
	lsls r0, r2, 2
	adds r0, r4
	ldrh r0, [r0]
	cmp r0, r3
	bne _080086AC
	ldrh r0, [r1]
	b _080086B8
	.pool
_080086AC:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x3F
	bls _08008686
	ldr r0, =0x0000ffff
_080086B8:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetTagByObjectTileRangeStart

	thumb_func_start AllocSpriteTileRange
@ void AllocSpriteTileRange(u16 tag, u16 start, u16 count)
AllocSpriteTileRange: @ 80086C4
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	adds r6, r2, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	ldr r0, =0x0000ffff
	bl IndexOfObjectTilesTag
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gUnknown_030009F0
	lsls r1, r0, 1
	adds r1, r2
	strh r4, [r1]
	ldr r1, =gUnknown_03000A70
	lsls r0, 2
	adds r2, r0, r1
	strh r5, [r2]
	adds r1, 0x2
	adds r0, r1
	strh r6, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end AllocSpriteTileRange

	thumb_func_start ResetObjectPaletteAllocator
@ void ResetObjectPaletteAllocator()
ResetObjectPaletteAllocator: @ 800870C
	push {r4,lr}
	ldr r1, =gUnknown_0300301C
	movs r0, 0
	strb r0, [r1]
	movs r2, 0
	ldr r4, =gUnknown_03000CF0
	ldr r0, =0x0000ffff
	adds r3, r0, 0
_0800871C:
	lsls r0, r2, 1
	adds r0, r4
	ldrh r1, [r0]
	orrs r1, r3
	strh r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xF
	bls _0800871C
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetObjectPaletteAllocator

	thumb_func_start LoadTaggedObjectPalette
@ u8 LoadTaggedObjectPalette(struct TaggedObjectPalette *palette)
LoadTaggedObjectPalette: @ 8008744
	push {r4,r5,lr}
	adds r5, r0, 0
	ldrh r0, [r5, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFF
	beq _0800875A
	adds r0, r4, 0
	b _0800878A
_0800875A:
	ldr r0, =0x0000ffff
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xFF
	beq _08008788
	ldr r1, =gUnknown_03000CF0
	lsls r0, r4, 1
	adds r0, r1
	ldrh r1, [r5, 0x4]
	strh r1, [r0]
	ldr r0, [r5]
	lsls r1, r4, 4
	bl LoadObjectPalette
	adds r0, r4, 0
	b _0800878A
	.pool
_08008788:
	movs r0, 0xFF
_0800878A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end LoadTaggedObjectPalette

	thumb_func_start LoadTaggedObjectPalettes
@ void LoadTaggedObjectPalettes(struct TaggedObjectPalette *palettes)
LoadTaggedObjectPalettes: @ 8008790
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r4, 0
	b _0800879E
_08008798:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_0800879E:
	lsls r0, r4, 3
	adds r1, r0, r5
	ldr r0, [r1]
	cmp r0, 0
	beq _080087B6
	adds r0, r1, 0
	bl LoadTaggedObjectPalette
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xFF
	bne _08008798
_080087B6:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end LoadTaggedObjectPalettes

	thumb_func_start LoadObjectPalette
@ void LoadObjectPalette(void *src, u16 destOffset)
LoadObjectPalette: @ 80087BC
	push {lr}
	lsls r1, 16
	movs r2, 0x80
	lsls r2, 17
	adds r1, r2
	lsrs r1, 16
	movs r2, 0x20
	bl LoadPalette
	pop {r0}
	bx r0
	thumb_func_end LoadObjectPalette

	thumb_func_start AllocObjectPalette
@ u8 AllocObjectPalette(u16 tag)
AllocObjectPalette: @ 80087D4
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0xFF
	beq _080087FC
	ldr r1, =gUnknown_03000CF0
	lsls r0, r2, 1
	adds r0, r1
	strh r4, [r0]
	adds r0, r2, 0
	b _080087FE
	.pool
_080087FC:
	movs r0, 0xFF
_080087FE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end AllocObjectPalette

	thumb_func_start IndexOfSpritePaletteTag
@ u8 IndexOfSpritePaletteTag(u16 tag)
IndexOfSpritePaletteTag: @ 8008804
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gUnknown_0300301C
	ldrb r1, [r0]
	cmp r1, 0xF
	bhi _08008836
	ldr r3, =gUnknown_03000CF0
_08008814:
	lsls r0, r1, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _0800882C
	adds r0, r1, 0
	b _08008838
	.pool
_0800882C:
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xF
	bls _08008814
_08008836:
	movs r0, 0xFF
_08008838:
	pop {r1}
	bx r1
	thumb_func_end IndexOfSpritePaletteTag

	thumb_func_start GetObjectPaletteTagBySlot
@ u16 GetObjectPaletteTagBySlot(u8 paletteSlot)
GetObjectPaletteTagBySlot: @ 800883C
	lsls r0, 24
	ldr r1, =gUnknown_03000CF0
	lsrs r0, 23
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end GetObjectPaletteTagBySlot

	thumb_func_start FreeSpritePaletteByTag
@ void FreeSpritePaletteByTag(int tag)
FreeSpritePaletteByTag: @ 800884C
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0xFF
	beq _08008868
	ldr r0, =gUnknown_03000CF0
	lsls r1, 1
	adds r1, r0
	ldr r0, =0x0000ffff
	strh r0, [r1]
_08008868:
	pop {r0}
	bx r0
	.pool
	thumb_func_end FreeSpritePaletteByTag

	thumb_func_start SetSpriteOamTables_NoPriorityFromTable
@ void SetSpriteOamTables_NoPriorityFromTable(struct obj *object, u32 spriteOamTables)
SetSpriteOamTables_NoPriorityFromTable: @ 8008874
	str r1, [r0, 0x18]
	adds r0, 0x42
	movs r1, 0x40
	strb r1, [r0]
	bx lr
	thumb_func_end SetSpriteOamTables_NoPriorityFromTable

	thumb_func_start AddSpriteToOamBuffer
@ u8 AddSpriteToOamBuffer(struct obj *obj, u8 *spriteIndex)
AddSpriteToOamBuffer: @ 8008880
	push {r4,lr}
	adds r4, r0, 0
	adds r3, r1, 0
	ldr r1, =gOamLimit
	ldrb r0, [r3]
	ldrb r1, [r1]
	cmp r0, r1
	bcc _08008898
	movs r0, 0x1
	b _080088E0
	.pool
_08008898:
	ldr r0, [r4, 0x18]
	cmp r0, 0
	beq _080088AC
	adds r0, r4, 0
	adds r0, 0x42
	ldrb r1, [r0]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	bne _080088CC
_080088AC:
	ldr r0, =gMain
	ldrb r2, [r3]
	lsls r2, 3
	adds r0, 0x38
	adds r2, r0
	ldr r0, [r4]
	ldr r1, [r4, 0x4]
	str r0, [r2]
	str r1, [r2, 0x4]
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
	movs r0, 0
	b _080088E0
	.pool
_080088CC:
	ldrb r1, [r3]
	lsls r1, 3
	ldr r0, =gUnknown_030022F8
	adds r1, r0
	adds r0, r4, 0
	adds r2, r3, 0
	bl AddSubspritesToOamBuffer
	lsls r0, 24
	lsrs r0, 24
_080088E0:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddSpriteToOamBuffer

	thumb_func_start AddSubspritesToOamBuffer
@ u8 AddSubspritesToOamBuffer(struct obj *object, struct sprite *sprite, u8 *spriteIndex)
AddSubspritesToOamBuffer: @ 80088EC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x1C
	adds r3, r0, 0
	str r1, [sp]
	mov r8, r2
	ldr r0, =gOamLimit
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	bcc _08008910
_08008908:
	movs r0, 0x1
	b _08008AE6
	.pool
_08008910:
	adds r0, r3, 0
	adds r0, 0x42
	ldrb r1, [r0]
	lsls r1, 26
	lsrs r1, 23
	ldr r2, [r3, 0x18]
	adds r7, r2, r1
	mov r12, r3
	str r0, [sp, 0x18]
	cmp r7, 0
	beq _0800892C
	ldr r0, [r7, 0x4]
	cmp r0, 0
	bne _08008942
_0800892C:
	mov r2, r12
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	ldr r2, [sp]
	str r0, [r2]
	str r1, [r2, 0x4]
	mov r1, r8
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	b _08008AE4
_08008942:
	mov r2, r12
	ldrh r0, [r2, 0x4]
	lsls r0, 22
	lsrs r0, 22
	str r0, [sp, 0x4]
	ldrb r0, [r7]
	str r0, [sp, 0xC]
	ldrb r0, [r2, 0x3]
	lsls r0, 26
	lsrs r0, 27
	asrs r1, r0, 3
	str r1, [sp, 0x10]
	movs r1, 0x1
	ldr r2, [sp, 0x10]
	ands r2, r1
	str r2, [sp, 0x10]
	asrs r0, 4
	mov r10, r0
	ands r0, r1
	mov r10, r0
	mov r1, r12
	ldrh r0, [r1, 0x2]
	lsls r0, 23
	lsrs r0, 23
	adds r1, 0x28
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	subs r0, r1
	lsls r0, 16
	lsrs r2, r0, 16
	mov r1, r12
	ldrb r0, [r1]
	adds r1, 0x29
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	subs r0, r1
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x8]
	movs r0, 0
	mov r9, r0
	ldr r1, [sp, 0xC]
	cmp r9, r1
	bcc _080089A0
	b _08008AE4
_080089A0:
	lsls r0, r2, 16
	asrs r0, 16
	str r0, [sp, 0x14]
_080089A6:
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, =gOamLimit
	ldrb r1, [r1]
	cmp r0, r1
	bcs _08008908
	ldr r0, [r7, 0x4]
	mov r2, r9
	lsls r6, r2, 2
	adds r2, r6, r0
	movs r0, 0
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x1
	ldrsb r0, [r2, r0]
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r0, [sp, 0x10]
	cmp r0, 0
	beq _080089FC
	ldr r0, [r2]
	lsls r1, r0, 12
	lsrs r1, 30
	lsls r1, 2
	lsls r0, 14
	lsrs r0, 30
	lsls r0, 4
	adds r1, r0
	ldr r0, =gUnknown_082EC754
	adds r1, r0
	ldrb r1, [r1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, r4, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r4, r0, 16
	mvns r0, r4
	adds r0, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_080089FC:
	mov r1, r10
	cmp r1, 0
	beq _08008A2E
	ldr r0, [r2]
	lsls r1, r0, 12
	lsrs r1, 30
	lsls r1, 2
	lsls r0, 14
	lsrs r0, 30
	lsls r0, 4
	adds r1, r0
	ldr r2, =gUnknown_082EC754
	adds r1, r2
	ldrb r1, [r1, 0x1]
	lsls r1, 24
	asrs r1, 24
	lsls r0, r5, 16
	asrs r0, 16
	adds r0, r1
	lsls r0, 16
	lsrs r5, r0, 16
	mvns r0, r5
	adds r0, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_08008A2E:
	mov r1, r9
	lsls r0, r1, 3
	ldr r2, [sp]
	adds r3, r0, r2
	mov r2, r12
	ldr r0, [r2]
	ldr r1, [r2, 0x4]
	str r0, [r3]
	str r1, [r3, 0x4]
	ldr r0, [r7, 0x4]
	adds r0, r6, r0
	ldr r1, [r0]
	lsls r1, 14
	lsrs r1, 30
	lsls r1, 6
	ldrb r2, [r3, 0x1]
	movs r0, 0x3F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x1]
	ldr r0, [r7, 0x4]
	adds r0, r6, r0
	ldr r1, [r0]
	lsls r1, 12
	lsrs r1, 30
	lsls r1, 6
	ldrb r2, [r3, 0x3]
	movs r0, 0x3F
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x3]
	lsls r1, r4, 16
	asrs r1, 16
	ldr r0, [sp, 0x14]
	adds r1, r0, r1
	ldr r2, =0x000001ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x2]
	ldr r0, =0xfffffe00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x2]
	ldr r1, [sp, 0x8]
	adds r0, r1, r5
	strb r0, [r3]
	ldr r0, [r7, 0x4]
	adds r0, r6, r0
	ldr r1, [r0]
	lsls r1, 2
	lsrs r1, 22
	ldr r2, [sp, 0x4]
	adds r1, r2, r1
	ldr r2, =0x000003ff
	adds r0, r2, 0
	ands r1, r0
	ldrh r2, [r3, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldr r0, [sp, 0x18]
	ldrb r1, [r0]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x80
	beq _08008ACA
	ldr r0, [r7, 0x4]
	adds r0, r6, r0
	ldr r1, [r0]
	lsrs r1, 30
	lsls r1, 2
	ldrb r2, [r3, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, 0x5]
_08008ACA:
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	mov r1, r8
	ldrb r0, [r1]
	adds r0, 0x1
	strb r0, [r1]
	ldr r2, [sp, 0xC]
	cmp r9, r2
	bcs _08008AE4
	b _080089A6
_08008AE4:
	movs r0, 0
_08008AE6:
	add sp, 0x1C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddSubspritesToOamBuffer

	.align 2, 0 @ Don't pad with nop.
