	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start LZDecompressWram
@ void LZDecompressWram(void *src, void *dest)
LZDecompressWram: @ 8034518
	push {lr}
	bl LZ77UnCompWram
	pop {r0}
	bx r0
	thumb_func_end LZDecompressWram

	thumb_func_start LZDecompressVram
@ void LZDecompressVram(void *src, void *dest)
LZDecompressVram: @ 8034524
	push {lr}
	bl LZ77UnCompVram
	pop {r0}
	bx r0
	thumb_func_end LZDecompressVram

	thumb_func_start LoadCompressedObjectPic
@ u16 LoadCompressedObjectPic(struct obj_tiles *pic)
LoadCompressedObjectPic: @ 8034530
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r0, [r4]
	ldr r5, =0x0201c000
	adds r1, r5, 0
	bl LZ77UnCompWram
	str r5, [sp]
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	ldrh r0, [r4, 0x4]
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end LoadCompressedObjectPic

	thumb_func_start LoadCompressedObjectPicOverrideBuffer
@ void LoadCompressedObjectPicOverrideBuffer(struct obj_tiles *pic, void *tempBuffer)
LoadCompressedObjectPicOverrideBuffer: @ 8034564
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	adds r5, r1, 0
	ldr r0, [r4]
	bl LZ77UnCompWram
	str r5, [sp]
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	ldrh r0, [r4, 0x4]
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end LoadCompressedObjectPicOverrideBuffer

	thumb_func_start LoadCompressedObjectPalette
@ void LoadCompressedObjectPalette(struct TaggedObjectPalette *palette)
LoadCompressedObjectPalette: @ 803458C
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldr r0, [r5]
	ldr r4, =0x0201c000
	adds r1, r4, 0
	bl LZ77UnCompWram
	str r4, [sp]
	ldrh r2, [r5, 0x4]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadTaggedObjectPalette
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end LoadCompressedObjectPalette

	thumb_func_start LoadCompressedObjectPaletteOverrideBuffer
@ void LoadCompressedObjectPaletteOverrideBuffer(struct TaggedObjectPalette *palette, void *tempBuffer)
LoadCompressedObjectPaletteOverrideBuffer: @ 80345C0
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	adds r4, r1, 0
	ldr r0, [r5]
	bl LZ77UnCompWram
	str r4, [sp]
	ldrh r2, [r5, 0x4]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadTaggedObjectPalette
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end LoadCompressedObjectPaletteOverrideBuffer

	thumb_func_start DecompressPicFromTable
@ void DecompressPicFromTable(void **picTable, void *dest, u32 index)
DecompressPicFromTable: @ 80345F0
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _08034610
	ldr r0, =gMonFrontPicTable
	ldr r0, [r0]
	bl LZ77UnCompWram
	b _08034618
	.pool
_08034610:
	ldr r0, [r3]
	adds r1, r4, 0
	bl LZ77UnCompWram
_08034618:
	adds r0, r4, 0
	adds r1, r5, 0
	bl DuplicateDeoxysTiles
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end DecompressPicFromTable

	thumb_func_start DecompressMonPic_DetectFrontOrBack
@ void DecompressMonPic_DetectFrontOrBack(void **picTable, void *dest, u32 speciesId, u32 personality)
DecompressMonPic_DetectFrontOrBack: @ 8034628
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	movs r1, 0
	cmp r4, r0
	bne _0803463E
	movs r1, 0x1
_0803463E:
	str r1, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	bl DecompressMonPic_2
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressMonPic_DetectFrontOrBack

	thumb_func_start DecompressMonPic
@ void DecompressMonPic(void **picTable, void *dest, u32 speciesId, u32 personality, bool8 isFrontPic)
DecompressMonPic: @ 8034654
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r7, r2, 0
	adds r5, r3, 0
	ldr r0, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r7, 0xC9
	bne _080346D0
	movs r0, 0xC0
	lsls r0, 18
	ands r0, r5
	lsrs r0, 18
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r5
	lsrs r1, 12
	orrs r0, r1
	movs r1, 0xC0
	lsls r1, 2
	ands r1, r5
	lsrs r1, 6
	orrs r0, r1
	movs r1, 0x3
	ands r1, r5
	orrs r0, r1
	movs r1, 0x1C
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _080346A2
	movs r1, 0xC9
	b _080346AC
_080346A2:
	movs r2, 0xCE
	lsls r2, 1
	adds r0, r1, r2
	lsls r0, 16
	lsrs r1, r0, 16
_080346AC:
	mov r0, r8
	cmp r0, 0
	bne _080346C0
	ldr r0, =gMonBackPicTable
	lsls r1, 3
	adds r1, r0
	ldr r0, [r1]
	b _080346DC
	.pool
_080346C0:
	ldr r0, =gMonFrontPicTable
	lsls r1, 3
	adds r1, r0
	ldr r0, [r1]
	b _080346DC
	.pool
_080346D0:
	movs r0, 0xCE
	lsls r0, 1
	cmp r7, r0
	ble _080346E8
	ldr r0, =gMonFrontPicTable
	ldr r0, [r0]
_080346DC:
	adds r1, r4, 0
	bl LZ77UnCompWram
	b _080346F0
	.pool
_080346E8:
	ldr r0, [r6]
	adds r1, r4, 0
	bl LZ77UnCompWram
_080346F0:
	adds r0, r4, 0
	adds r1, r7, 0
	bl DuplicateDeoxysTiles
	lsls r0, r7, 16
	lsrs r0, 16
	adds r1, r5, 0
	adds r2, r4, 0
	mov r3, r8
	bl DrawSpindaSpots
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end DecompressMonPic

	thumb_func_start Unused_LZDecompressWramIndirect
@ void Unused_LZDecompressWramIndirect(void **src)
Unused_LZDecompressWramIndirect: @ 8034710
	push {lr}
	ldr r0, [r0]
	bl LZ77UnCompWram
	pop {r0}
	bx r0
	thumb_func_end Unused_LZDecompressWramIndirect

	thumb_func_start sub_803471C
sub_803471C: @ 803471C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	mov r9, r0
	str r1, [sp]
	str r2, [sp, 0x4]
	adds r5, r3, 0
	movs r0, 0x1
	mov r1, r9
	ands r0, r1
	cmp r0, 0
	bne _0803473C
	b _080348D4
_0803473C:
	asrs r0, r1, 1
	adds r0, 0x4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x8]
	movs r0, 0
	ldr r2, [sp]
	cmp r0, r2
	blt _08034750
	b _08034964
_08034750:
	movs r4, 0x8
	subs r1, r4, r1
	str r1, [sp, 0x10]
_08034756:
	movs r7, 0
	adds r0, 0x1
	str r0, [sp, 0x14]
	ldr r0, [sp, 0x10]
	cmp r7, r0
	bge _080347D2
	ldr r1, [sp, 0x8]
	lsls r1, 8
	str r1, [sp, 0x18]
	movs r2, 0
	mov r10, r2
	mov r0, r9
	movs r4, 0x8
	subs r0, r4, r0
	str r0, [sp, 0xC]
_08034774:
	movs r3, 0
	asrs r0, r7, 1
	adds r1, r7, 0
	movs r2, 0x1
	ands r1, r2
	str r1, [sp, 0x20]
	lsls r0, 8
	mov r8, r0
	mov r12, r5
_08034786:
	lsls r1, r3, 5
	ldr r4, [sp, 0x18]
	adds r0, r5, r4
	adds r0, r1
	mov r1, r8
	adds r2, r0, r1
	mov r1, r12
	add r1, r8
	movs r6, 0xF
_08034798:
	ldr r4, [sp, 0x20]
	cmp r4, 0
	bne _080347A8
	strb r4, [r1]
	add r4, sp, 0x20
	ldrb r4, [r4]
	strb r4, [r2, 0x10]
	b _080347B6
_080347A8:
	mov r0, r10
	strb r0, [r1, 0x10]
	movs r4, 0x80
	lsls r4, 1
	adds r4, r2, r4
	str r4, [sp, 0x1C]
	strb r0, [r4]
_080347B6:
	adds r2, 0x1
	adds r1, 0x1
	subs r6, 0x1
	cmp r6, 0
	bge _08034798
	movs r0, 0x20
	add r12, r0
	adds r3, 0x1
	cmp r3, 0x7
	ble _08034786
	adds r7, 0x1
	ldr r1, [sp, 0xC]
	cmp r7, r1
	blt _08034774
_080347D2:
	movs r7, 0
	movs r2, 0
_080347D6:
	movs r6, 0
	adds r4, r7, 0x1
	mov r8, r4
	lsls r4, r7, 5
_080347DE:
	adds r0, r6, 0x1
	mov r10, r0
	lsls r1, r6, 8
	adds r0, r1, 0
	adds r0, 0xC0
	adds r0, r5, r0
	adds r0, r4
	adds r1, r5, r1
	adds r1, r4
	movs r3, 0x1F
_080347F2:
	strb r2, [r1]
	strb r2, [r0]
	adds r0, 0x1
	adds r1, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _080347F2
	mov r6, r10
	cmp r6, 0x7
	ble _080347DE
	mov r7, r8
	cmp r7, 0x1
	ble _080347D6
	mov r1, r9
	cmp r1, 0x5
	bne _08034818
	movs r2, 0x90
	lsls r2, 1
	adds r5, r2
_08034818:
	movs r7, 0
	cmp r7, r9
	bge _080348AE
_0803481E:
	movs r3, 0
	adds r7, 0x1
	mov r8, r7
	cmp r3, r9
	bge _0803488E
_08034828:
	adds r3, 0x1
	mov r10, r3
	ldr r4, [sp, 0x4]
	adds r4, 0x20
	adds r7, r5, 0
	adds r7, 0x20
	movs r0, 0x12
	adds r0, r5
	mov r12, r0
	ldr r2, [sp, 0x4]
	adds r3, r5, 0
	movs r6, 0x3
_08034840:
	ldrb r0, [r2]
	mov r1, r12
	strb r0, [r1]
	ldrb r0, [r2, 0x1]
	strb r0, [r1, 0x1]
	ldrb r0, [r2, 0x2]
	strb r0, [r1, 0x1E]
	ldrb r0, [r2, 0x3]
	strb r0, [r1, 0x1F]
	movs r0, 0x81
	lsls r0, 1
	adds r1, r3, r0
	ldrb r0, [r2, 0x10]
	strb r0, [r1]
	ldr r0, =0x00000103
	adds r1, r3, r0
	ldrb r0, [r2, 0x11]
	strb r0, [r1]
	movs r0, 0x90
	lsls r0, 1
	adds r1, r3, r0
	ldrb r0, [r2, 0x12]
	strb r0, [r1]
	ldr r0, =0x00000121
	adds r1, r3, r0
	ldrb r0, [r2, 0x13]
	strb r0, [r1]
	movs r1, 0x4
	add r12, r1
	adds r2, 0x4
	adds r3, 0x4
	subs r6, 0x1
	cmp r6, 0
	bge _08034840
	str r4, [sp, 0x4]
	adds r5, r7, 0
	mov r3, r10
	cmp r3, r9
	blt _08034828
_0803488E:
	mov r2, r9
	cmp r2, 0x7
	bne _080348A0
	adds r5, 0x20
	b _080348A8
	.pool
_080348A0:
	mov r4, r9
	cmp r4, 0x5
	bne _080348A8
	adds r5, 0x60
_080348A8:
	mov r7, r8
	cmp r7, r9
	blt _0803481E
_080348AE:
	mov r0, r9
	cmp r0, 0x7
	bne _080348BC
	movs r1, 0x80
	lsls r1, 1
	adds r5, r1
	b _080348C8
_080348BC:
	mov r2, r9
	cmp r2, 0x5
	bne _080348C8
	movs r4, 0xF0
	lsls r4, 1
	adds r5, r4
_080348C8:
	ldr r0, [sp, 0x14]
	ldr r1, [sp]
	cmp r0, r1
	bge _080348D2
	b _08034756
_080348D2:
	b _08034964
_080348D4:
	movs r6, 0
	ldr r2, [sp]
	cmp r6, r2
	bge _08034964
_080348DC:
	adds r6, 0x1
	mov r10, r6
	mov r4, r9
	cmp r4, 0x6
	bne _080348F4
	movs r0, 0
	movs r3, 0xFF
_080348EA:
	strb r0, [r5]
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _080348EA
_080348F4:
	movs r7, 0
	cmp r7, r9
	bge _08034948
_080348FA:
	adds r7, 0x1
	mov r8, r7
	mov r1, r9
	lsls r0, r1, 5
	cmp r1, 0x6
	bne _08034914
	movs r1, 0
	movs r3, 0x1F
_0803490A:
	strb r1, [r5]
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _0803490A
_08034914:
	adds r1, r0, 0
	cmp r1, 0
	ble _0803492E
	adds r3, r1, 0
_0803491C:
	ldr r2, [sp, 0x4]
	ldrb r0, [r2]
	strb r0, [r5]
	adds r2, 0x1
	str r2, [sp, 0x4]
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bne _0803491C
_0803492E:
	mov r4, r9
	cmp r4, 0x6
	bne _08034942
	movs r0, 0
	movs r3, 0x1F
_08034938:
	strb r0, [r5]
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _08034938
_08034942:
	mov r7, r8
	cmp r7, r9
	blt _080348FA
_08034948:
	mov r0, r9
	cmp r0, 0x6
	bne _0803495C
	movs r0, 0
	movs r3, 0xFF
_08034952:
	strb r0, [r5]
	adds r5, 0x1
	subs r3, 0x1
	cmp r3, 0
	bge _08034952
_0803495C:
	mov r6, r10
	ldr r1, [sp]
	cmp r6, r1
	blt _080348DC
_08034964:
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_803471C

	thumb_func_start sub_8034974
sub_8034974: @ 8034974
	adds r2, r0, 0
	ldrb r0, [r2, 0x3]
	lsls r0, 16
	ldrb r1, [r2, 0x2]
	lsls r1, 8
	orrs r0, r1
	ldrb r1, [r2, 0x1]
	orrs r0, r1
	bx lr
	thumb_func_end sub_8034974

	thumb_func_start LoadCompressedObjectPicUsingHeap
@ u32 LoadCompressedObjectPicUsingHeap(struct obj_tiles *pic)
LoadCompressedObjectPicUsingHeap: @ 8034988
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r0, [r4]
	ldr r0, [r0]
	lsrs r0, 8
	bl AllocZeroed
	adds r5, r0, 0
	ldr r0, [r4]
	adds r1, r5, 0
	bl LZ77UnCompWram
	str r5, [sp]
	ldrh r1, [r4, 0x6]
	lsls r1, 16
	ldrh r0, [r4, 0x4]
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadSpriteSheet
	adds r0, r5, 0
	bl Free
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end LoadCompressedObjectPicUsingHeap

	thumb_func_start LoadCompressedObjectPaletteUsingHeap
@ u32 LoadCompressedObjectPaletteUsingHeap(struct TaggedObjectPalette *palette)
LoadCompressedObjectPaletteUsingHeap: @ 80349C4
	push {r4,r5,lr}
	sub sp, 0x8
	adds r4, r0, 0
	ldr r0, [r4]
	ldr r0, [r0]
	lsrs r0, 8
	bl AllocZeroed
	adds r5, r0, 0
	ldr r0, [r4]
	adds r1, r5, 0
	bl LZ77UnCompWram
	str r5, [sp]
	ldrh r2, [r4, 0x4]
	ldr r1, =0xffff0000
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	mov r0, sp
	bl LoadTaggedObjectPalette
	adds r0, r5, 0
	bl Free
	movs r0, 0
	add sp, 0x8
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end LoadCompressedObjectPaletteUsingHeap

	thumb_func_start DecompressPicFromTable_2
@ void DecompressPicFromTable_2(void **picTable, void *dest, u32 index)
DecompressPicFromTable_2: @ 8034A08
	push {r4,r5,lr}
	adds r3, r0, 0
	adds r4, r1, 0
	adds r5, r2, 0
	movs r0, 0xCE
	lsls r0, 1
	cmp r5, r0
	ble _08034A28
	ldr r0, =gMonFrontPicTable
	ldr r0, [r0]
	bl LZ77UnCompWram
	b _08034A30
	.pool
_08034A28:
	ldr r0, [r3]
	adds r1, r4, 0
	bl LZ77UnCompWram
_08034A30:
	adds r0, r4, 0
	adds r1, r5, 0
	bl DuplicateDeoxysTiles
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end DecompressPicFromTable_2

	thumb_func_start DecompressMonPic_2
@ void DecompressMonPic_2(void **picTable, void *dest, u32 speciesId, u32 personality, bool8 isFrontPic)
DecompressMonPic_2: @ 8034A40
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r4, r1, 0
	adds r7, r2, 0
	adds r5, r3, 0
	ldr r0, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r7, 0xC9
	bne _08034ABC
	movs r0, 0xC0
	lsls r0, 18
	ands r0, r5
	lsrs r0, 18
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r5
	lsrs r1, 12
	orrs r0, r1
	movs r1, 0xC0
	lsls r1, 2
	ands r1, r5
	lsrs r1, 6
	orrs r0, r1
	movs r1, 0x3
	ands r1, r5
	orrs r0, r1
	movs r1, 0x1C
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _08034A8E
	movs r1, 0xC9
	b _08034A98
_08034A8E:
	movs r2, 0xCE
	lsls r2, 1
	adds r0, r1, r2
	lsls r0, 16
	lsrs r1, r0, 16
_08034A98:
	mov r0, r8
	cmp r0, 0
	bne _08034AAC
	ldr r0, =gMonBackPicTable
	lsls r1, 3
	adds r1, r0
	ldr r0, [r1]
	b _08034AC8
	.pool
_08034AAC:
	ldr r0, =gMonFrontPicTable
	lsls r1, 3
	adds r1, r0
	ldr r0, [r1]
	b _08034AC8
	.pool
_08034ABC:
	movs r0, 0xCE
	lsls r0, 1
	cmp r7, r0
	ble _08034AD4
	ldr r0, =gMonFrontPicTable
	ldr r0, [r0]
_08034AC8:
	adds r1, r4, 0
	bl LZ77UnCompWram
	b _08034ADC
	.pool
_08034AD4:
	ldr r0, [r6]
	adds r1, r4, 0
	bl LZ77UnCompWram
_08034ADC:
	adds r0, r4, 0
	adds r1, r7, 0
	bl DuplicateDeoxysTiles
	lsls r0, r7, 16
	lsrs r0, 16
	adds r1, r5, 0
	adds r2, r4, 0
	mov r3, r8
	bl DrawSpindaSpots
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end DecompressMonPic_2

	thumb_func_start DecompressMonPic_DetectFrontOrBack_2
@ void DecompressMonPic_DetectFrontOrBack_2(void **picTable, void *dest, u32 speciesId, u32 personality)
DecompressMonPic_DetectFrontOrBack_2: @ 8034AFC
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	movs r1, 0
	cmp r4, r0
	bne _08034B12
	movs r1, 0x1
_08034B12:
	str r1, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	bl DecompressMonPic_2
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressMonPic_DetectFrontOrBack_2

	thumb_func_start sub_8034B28
sub_8034B28: @ 8034B28
	push {lr}
	adds r3, r0, 0
	movs r0, 0xCE
	lsls r0, 1
	cmp r2, r0
	ble _08034B44
	ldr r0, =gMonFrontPicTable
	ldr r0, [r0]
	bl LZ77UnCompWram
	b _08034B4A
	.pool
_08034B44:
	ldr r0, [r3]
	bl LZ77UnCompWram
_08034B4A:
	pop {r0}
	bx r0
	thumb_func_end sub_8034B28

	thumb_func_start DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack
@ void DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack(void **picTable, void *dest, u32 speciesId, u32 personality)
DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack: @ 8034B50
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r0, r2, 3
	ldr r1, =gMonFrontPicTable
	adds r0, r1
	movs r1, 0
	cmp r4, r0
	bne _08034B66
	movs r1, 0x1
_08034B66:
	str r1, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	bl DecompressMonPicWithoutDuplicatingDeoxysTiles
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressMonPicWithoutDuplicatingDeoxysTiles_DetectFrontOrBack

	thumb_func_start DecompressMonPicWithoutDuplicatingDeoxysTiles
@ void DecompressMonPicWithoutDuplicatingDeoxysTiles(void **picTable, void *dest, u32 speciesId, u32 personality, bool8 isFrontPic)
DecompressMonPicWithoutDuplicatingDeoxysTiles: @ 8034B7C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r6, r0, 0
	adds r5, r1, 0
	adds r7, r2, 0
	adds r4, r3, 0
	ldr r0, [sp, 0x18]
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r7, 0xC9
	bne _08034BF8
	movs r0, 0xC0
	lsls r0, 18
	ands r0, r4
	lsrs r0, 18
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r4
	lsrs r1, 12
	orrs r0, r1
	movs r1, 0xC0
	lsls r1, 2
	ands r1, r4
	lsrs r1, 6
	orrs r0, r1
	movs r1, 0x3
	ands r1, r4
	orrs r0, r1
	movs r1, 0x1C
	bl __umodsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, 0
	bne _08034BCA
	movs r1, 0xC9
	b _08034BD4
_08034BCA:
	movs r2, 0xCE
	lsls r2, 1
	adds r0, r1, r2
	lsls r0, 16
	lsrs r1, r0, 16
_08034BD4:
	mov r0, r8
	cmp r0, 0
	bne _08034BE8
	ldr r0, =gMonBackPicTable
	lsls r1, 3
	adds r1, r0
	ldr r0, [r1]
	b _08034C04
	.pool
_08034BE8:
	ldr r0, =gMonFrontPicTable
	lsls r1, 3
	adds r1, r0
	ldr r0, [r1]
	b _08034C04
	.pool
_08034BF8:
	movs r0, 0xCE
	lsls r0, 1
	cmp r7, r0
	ble _08034C10
	ldr r0, =gMonFrontPicTable
	ldr r0, [r0]
_08034C04:
	adds r1, r5, 0
	bl LZ77UnCompWram
	b _08034C18
	.pool
_08034C10:
	ldr r0, [r6]
	adds r1, r5, 0
	bl LZ77UnCompWram
_08034C18:
	lsls r0, r7, 16
	lsrs r0, 16
	adds r1, r4, 0
	adds r2, r5, 0
	mov r3, r8
	bl DrawSpindaSpots
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end DecompressMonPicWithoutDuplicatingDeoxysTiles

	thumb_func_start DuplicateDeoxysTiles
@ void DuplicateDeoxysTiles(void *pointer, u32 speciesId)
DuplicateDeoxysTiles: @ 8034C30
	push {lr}
	adds r3, r0, 0
	movs r0, 0xCD
	lsls r0, 1
	cmp r1, r0
	bne _08034C4A
	movs r1, 0x80
	lsls r1, 4
	adds r0, r3, r1
	ldr r2, =0x04000200
	adds r1, r3, 0
	bl CpuSet
_08034C4A:
	pop {r0}
	bx r0
	.pool
	thumb_func_end DuplicateDeoxysTiles

	.align 2, 0 @ Don't pad with nop.
