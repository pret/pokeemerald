	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start DecompressGlyphFont6
DecompressGlyphFont6: @ 81BA668
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r2, r0, 19
	lsls r2, 9
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	lsrs r1, 11
	ldr r0, =gFont6BrailleGlyphs
	adds r1, r0
	adds r5, r2, r1
	ldr r4, =gUnknown_03002F90
	adds r0, r5, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x10
	adds r1, r4, 0
	adds r1, 0x20
	bl DecompressGlyphTile
	movs r1, 0x80
	lsls r1, 1
	adds r0, r5, r1
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	movs r1, 0x88
	lsls r1, 1
	adds r0, r5, r1
	adds r1, r4, 0
	adds r1, 0x60
	bl DecompressGlyphTile
	adds r0, r4, 0
	adds r0, 0x80
	movs r1, 0x10
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressGlyphFont6

	thumb_func_start GetGlyphWidthFont6
GetGlyphWidthFont6: @ 81BA6CC
	movs r0, 0x10
	bx lr
	thumb_func_end GetGlyphWidthFont6

	.align 2, 0 @ Don't pad with nop.
