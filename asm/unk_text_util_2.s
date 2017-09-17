	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start Font6Func
@ int Font6Func(struct TextPrinter *x)
Font6Func: @ 81BA250
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r6, 0
	adds r4, 0x14
	ldrb r0, [r6, 0x1C]
	cmp r0, 0x6
	bls _081BA260
	b _081BA660
_081BA260:
	lsls r0, 2
	ldr r1, =_081BA270
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BA270:
	.4byte _081BA28C
	.4byte _081BA554
	.4byte _081BA566
	.4byte _081BA590
	.4byte _081BA5C8
	.4byte _081BA63C
	.4byte _081BA64E
_081BA28C:
	ldr r2, =gMain
	ldrh r1, [r2, 0x2C]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _081BA2A6
	ldrb r1, [r4]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _081BA2A6
	movs r0, 0
	strb r0, [r6, 0x1E]
_081BA2A6:
	ldrb r1, [r6, 0x1E]
	cmp r1, 0
	beq _081BA2E8
	ldrb r0, [r6, 0x1D]
	cmp r0, 0
	beq _081BA2E8
	subs r0, r1, 0x1
	strb r0, [r6, 0x1E]
	ldr r0, =gTextFlags
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _081BA2C4
	b _081BA50E
_081BA2C4:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _081BA2D0
	b _081BA50E
_081BA2D0:
	ldrb r0, [r4]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0
	strb r0, [r6, 0x1E]
	b _081BA50E
	.pool
_081BA2E8:
	ldr r2, =gTextFlags
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081BA2FC
	movs r0, 0x3
	b _081BA2FE
	.pool
_081BA2FC:
	ldrb r0, [r6, 0x1D]
_081BA2FE:
	strb r0, [r6, 0x1E]
	ldr r0, [r6]
	ldrb r3, [r0]
	adds r0, 0x1
	str r0, [r6]
	adds r0, r3, 0
	subs r0, 0xF8
	cmp r0, 0x7
	bls _081BA312
	b _081BA52E
_081BA312:
	lsls r0, 2
	ldr r1, =_081BA320
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BA320:
	.4byte _081BA524
	.4byte _081BA512
	.4byte _081BA504
	.4byte _081BA500
	.4byte _081BA36E
	.4byte _081BA368
	.4byte _081BA340
	.4byte _081BA660
_081BA340:
	ldrb r0, [r6, 0x6]
	strb r0, [r6, 0x8]
	ldrb r1, [r6, 0x5]
	ldr r0, =gFonts
	ldr r2, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r6, 0xB]
	ldrb r0, [r0, 0x5]
	adds r1, r0
	ldrb r0, [r6, 0x9]
	adds r0, r1
	strb r0, [r6, 0x9]
_081BA35E:
	movs r0, 0x2
	b _081BA662
	.pool
_081BA368:
	ldr r0, [r6]
	adds r0, 0x1
	b _081BA4C4
_081BA36E:
	ldr r0, [r6]
	ldrb r3, [r0]
	adds r0, 0x1
	str r0, [r6]
	subs r0, r3, 0x1
	cmp r0, 0xF
	bls _081BA37E
	b _081BA52E
_081BA37E:
	lsls r0, 2
	ldr r1, =_081BA38C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BA38C:
	.4byte _081BA3CC
	.4byte _081BA3EE
	.4byte _081BA412
	.4byte _081BA42C
	.4byte _081BA478
	.4byte _081BA47E
	.4byte _081BA35E
	.4byte _081BA498
	.4byte _081BA4A8
	.4byte _081BA4BC
	.4byte _081BA4C0
	.4byte _081BA4C8
	.4byte _081BA4D2
	.4byte _081BA4DE
	.4byte _081BA4EE
	.4byte _081BA4C0
_081BA3CC:
	ldr r2, [r6]
	ldrb r1, [r2]
	lsls r1, 4
	ldrb r3, [r6, 0xC]
	movs r0, 0xF
	ands r0, r3
	orrs r0, r1
	strb r0, [r6, 0xC]
	adds r2, 0x1
	str r2, [r6]
	lsls r0, 24
	lsrs r0, 28
	ldrb r2, [r6, 0xD]
	lsls r1, r2, 28
	lsrs r1, 28
	lsrs r2, 4
	b _081BA472
_081BA3EE:
	ldr r1, [r6]
	ldrb r2, [r1]
	movs r0, 0xF
	ands r0, r2
	ldrb r3, [r6, 0xD]
	movs r2, 0x10
	negs r2, r2
	ands r2, r3
	orrs r2, r0
	strb r2, [r6, 0xD]
	adds r1, 0x1
	str r1, [r6]
	ldrb r0, [r6, 0xC]
	lsrs r0, 4
	lsls r1, r2, 28
	lsrs r1, 28
	lsrs r2, 4
	b _081BA472
_081BA412:
	ldr r1, [r6]
	ldrb r0, [r1]
	lsls r0, 4
	ldrb r3, [r6, 0xD]
	movs r2, 0xF
	ands r2, r3
	orrs r2, r0
	strb r2, [r6, 0xD]
	adds r1, 0x1
	str r1, [r6]
	ldrb r0, [r6, 0xC]
	lsrs r0, 4
	b _081BA46A
_081BA42C:
	ldr r3, [r6]
	ldrb r1, [r3]
	lsls r1, 4
	ldrb r4, [r6, 0xC]
	movs r2, 0xF
	adds r0, r2, 0
	ands r0, r4
	orrs r0, r1
	strb r0, [r6, 0xC]
	adds r5, r3, 0x1
	str r5, [r6]
	ldrb r3, [r3, 0x1]
	adds r1, r2, 0
	ands r1, r3
	ldrb r4, [r6, 0xD]
	movs r3, 0x10
	negs r3, r3
	ands r3, r4
	orrs r3, r1
	strb r3, [r6, 0xD]
	adds r4, r5, 0x1
	str r4, [r6]
	ldrb r1, [r5, 0x1]
	lsls r1, 4
	ands r2, r3
	orrs r2, r1
	strb r2, [r6, 0xD]
	adds r4, 0x1
	str r4, [r6]
	lsls r0, 24
	lsrs r0, 28
_081BA46A:
	lsls r1, r2, 28
	lsrs r1, 28
	lsls r2, 24
	lsrs r2, 28
_081BA472:
	bl GenerateFontHalfRowLookupTable
	b _081BA35E
_081BA478:
	ldr r0, [r6]
	adds r0, 0x1
	b _081BA4C4
_081BA47E:
	ldr r0, [r6]
	ldrb r0, [r0]
	movs r1, 0xF
	ands r1, r0
	ldrb r2, [r4]
	movs r0, 0x10
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4]
	ldr r0, [r6]
	adds r0, 0x1
	b _081BA4C4
_081BA498:
	ldr r0, [r6]
	ldrb r1, [r0]
	strb r1, [r6, 0x1E]
	adds r0, 0x1
	str r0, [r6]
	movs r0, 0x6
	strb r0, [r6, 0x1C]
	b _081BA35E
_081BA4A8:
	movs r0, 0x1
	strb r0, [r6, 0x1C]
	ldrb r1, [r2]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081BA50E
	movs r0, 0
	strb r0, [r4, 0x2]
	b _081BA50E
_081BA4BC:
	movs r0, 0x5
	b _081BA64A
_081BA4C0:
	ldr r0, [r6]
	adds r0, 0x2
_081BA4C4:
	str r0, [r6]
	b _081BA35E
_081BA4C8:
	ldr r1, [r6]
	adds r0, r1, 0x1
	str r0, [r6]
	ldrb r3, [r1, 0x1]
	b _081BA52E
_081BA4D2:
	ldr r1, [r6]
	ldrb r0, [r1]
	ldrb r2, [r6, 0x6]
	adds r0, r2
	strb r0, [r6, 0x8]
	b _081BA4E8
_081BA4DE:
	ldr r1, [r6]
	ldrb r0, [r1]
	ldrb r2, [r6, 0x7]
	adds r0, r2
	strb r0, [r6, 0x9]
_081BA4E8:
	adds r1, 0x1
	str r1, [r6]
	b _081BA35E
_081BA4EE:
	ldrb r0, [r6, 0x4]
	ldrb r2, [r6, 0xD]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	bl FillWindowPixelBuffer
	b _081BA35E
_081BA500:
	movs r0, 0x2
	b _081BA506
_081BA504:
	movs r0, 0x3
_081BA506:
	strb r0, [r6, 0x1C]
	adds r0, r6, 0
	bl TextPrinterInitDownArrowCounters
_081BA50E:
	movs r0, 0x3
	b _081BA662
_081BA512:
	ldr r0, [r6]
	ldrb r3, [r0]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	orrs r3, r1
	adds r0, 0x1
	str r0, [r6]
	b _081BA52E
_081BA524:
	ldr r0, [r6]
	adds r0, 0x1
	str r0, [r6]
	movs r0, 0
	b _081BA662
_081BA52E:
	adds r0, r3, 0
	bl DecompressGlyphFont6
	adds r0, r6, 0
	bl CopyGlyphToWindow
	ldr r0, =gUnknown_03002F90
	adds r0, 0x80
	ldrb r1, [r6, 0xA]
	ldrb r0, [r0]
	adds r1, r0
	ldrb r0, [r6, 0x8]
	adds r0, r1
	strb r0, [r6, 0x8]
	movs r0, 0
	b _081BA662
	.pool
_081BA554:
	adds r0, r6, 0
	bl TextPrinterWait
	lsls r0, 16
	cmp r0, 0
	beq _081BA50E
	movs r0, 0
	strb r0, [r6, 0x1C]
	b _081BA50E
_081BA566:
	adds r0, r6, 0
	bl TextPrinterWaitWithDownArrow
	lsls r0, 16
	cmp r0, 0
	beq _081BA50E
	ldrb r0, [r6, 0x4]
	ldrb r2, [r6, 0xD]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	bl FillWindowPixelBuffer
	ldrb r0, [r6, 0x6]
	movs r1, 0
	strb r0, [r6, 0x8]
	ldrb r0, [r6, 0x7]
	strb r0, [r6, 0x9]
	strb r1, [r6, 0x1C]
	b _081BA50E
_081BA590:
	adds r0, r6, 0
	bl TextPrinterWaitWithDownArrow
	lsls r0, 16
	cmp r0, 0
	beq _081BA50E
	adds r0, r6, 0
	bl TextPrinterClearDownArrow
	ldrb r1, [r6, 0x5]
	ldr r0, =gFonts
	ldr r2, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r1, [r6, 0xB]
	ldrb r0, [r0, 0x5]
	adds r1, r0
	strb r1, [r6, 0x1F]
	ldrb r0, [r6, 0x6]
	strb r0, [r6, 0x8]
	movs r0, 0x4
	strb r0, [r6, 0x1C]
	b _081BA50E
	.pool
_081BA5C8:
	ldrb r2, [r6, 0x1F]
	cmp r2, 0
	beq _081BA638
	ldr r4, =gUnknown_08616124
	ldr r5, =gSaveBlock2Ptr
	ldr r0, [r5]
	ldrb r0, [r0, 0x14]
	lsls r1, r0, 29
	lsrs r0, r1, 29
	adds r0, r4
	ldrb r0, [r0]
	cmp r2, r0
	bcs _081BA604
	ldrb r0, [r6, 0x4]
	ldrb r1, [r6, 0xD]
	lsls r1, 28
	lsrs r3, r1, 4
	orrs r3, r1
	lsrs r3, 24
	movs r1, 0
	bl ScrollWindow
	movs r0, 0
	strb r0, [r6, 0x1F]
	b _081BA62E
	.pool
_081BA604:
	ldrb r0, [r6, 0x4]
	lsrs r1, 29
	adds r1, r4
	ldrb r2, [r1]
	ldrb r1, [r6, 0xD]
	lsls r1, 28
	lsrs r3, r1, 4
	orrs r3, r1
	lsrs r3, 24
	movs r1, 0
	bl ScrollWindow
	ldr r0, [r5]
	ldrb r0, [r0, 0x14]
	lsls r0, 29
	lsrs r0, 29
	adds r0, r4
	ldrb r1, [r6, 0x1F]
	ldrb r0, [r0]
	subs r1, r0
	strb r1, [r6, 0x1F]
_081BA62E:
	ldrb r0, [r6, 0x4]
	movs r1, 0x2
	bl CopyWindowToVram
	b _081BA50E
_081BA638:
	strb r2, [r6, 0x1C]
	b _081BA50E
_081BA63C:
	bl IsSEPlaying
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _081BA64A
	b _081BA50E
_081BA64A:
	strb r0, [r6, 0x1C]
	b _081BA50E
_081BA64E:
	ldrb r0, [r6, 0x1E]
	adds r1, r0, 0
	cmp r1, 0
	beq _081BA65C
	subs r0, 0x1
	strb r0, [r6, 0x1E]
	b _081BA50E
_081BA65C:
	strb r1, [r6, 0x1C]
	b _081BA50E
_081BA660:
	movs r0, 0x1
_081BA662:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end Font6Func

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
