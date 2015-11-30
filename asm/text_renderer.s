	thumb_func_start SetFontsPointer
; void SetFontsPointer(struct FontInfo *fonts)
SetFontsPointer: ; 80045A4
	ldr r1, =0x03002f80
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end SetFontsPointer

	thumb_func_start DeactivateAllTextPrinters
; void DeactivateAllTextPrinters()
DeactivateAllTextPrinters: ; 80045B0
	push {lr}
	ldr r1, =0x020201b0
	movs r2, 0
	ldr r3, =0x0000045c
	adds r0, r1, r3
@080045BA:
	strb r2, [r0, 0x1B]
	subs r0, 0x24
	cmp r0, r1
	bge @080045BA
	pop {r0}
	bx r0
	.pool
	thumb_func_end DeactivateAllTextPrinters

	thumb_func_start Print
; u16 Print(u8 windowId, u8 fontId, u8 *str, u8 x, u8 y, u8 speed, void ( *callback)(u16, struct TextPrinter *))
Print: ; 80045D0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	ldr r4, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	ldr r7, [sp, 0x30]
	lsls r1, 24
	lsrs r1, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	mov r8, r5
	str r2, [sp]
	mov r2, sp
	strb r0, [r2, 0x4]
	mov r0, sp
	strb r1, [r0, 0x5]
	strb r3, [r0, 0x6]
	strb r4, [r0, 0x7]
	strb r3, [r0, 0x8]
	strb r4, [r0, 0x9]
	ldr r0, =0x03002f80
	ldr r0, [r0]
	lsls r3, r1, 1
	adds r3, r1
	lsls r3, 2
	adds r3, r0
	ldrb r0, [r3, 0x6]
	strb r0, [r2, 0xA]
	mov r1, sp
	ldrb r0, [r3, 0x7]
	strb r0, [r1, 0xB]
	mov r5, sp
	ldrb r1, [r3, 0x8]
	lsls r1, 28
	movs r6, 0xF
	lsrs r1, 28
	ldrb r4, [r5, 0xC]
	movs r2, 0x10
	negs r2, r2
	adds r0, r2, 0
	ands r0, r4
	orrs r0, r1
	strb r0, [r5, 0xC]
	mov r4, sp
	ldrb r1, [r3, 0x8]
	lsrs r1, 4
	lsls r1, 4
	ands r0, r6
	orrs r0, r1
	strb r0, [r4, 0xC]
	ldrb r0, [r3, 0x9]
	lsls r0, 28
	lsrs r0, 28
	adds r1, r6, 0
	ands r1, r0
	ldrb r0, [r4, 0xD]
	ands r2, r0
	orrs r2, r1
	strb r2, [r4, 0xD]
	mov r1, sp
	ldrb r0, [r3, 0x9]
	lsrs r0, 4
	lsls r0, 4
	ands r2, r6
	orrs r2, r0
	strb r2, [r1, 0xD]
	mov r0, sp
	mov r1, r8
	adds r2, r7, 0
	bl AddTextPrinter
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Print

	thumb_func_start AddTextPrinter
; u16 AddTextPrinter(struct TextPrinter *textPrinter, u8 speed, void ( *callback)(u16, struct TextPrinter *))
AddTextPrinter: ; 800467C
	push {r4-r7,lr}
	adds r6, r0, 0
	mov r12, r2
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =0x03002f80
	ldr r0, [r0]
	cmp r0, 0
	bne @08004698
	movs r0, 0
	b @08004766
	.pool
@08004698:
	ldr r0, =0x0202018c
	movs r2, 0
	movs r1, 0x1
	strb r1, [r0, 0x1B]
	strb r2, [r0, 0x1C]
	strb r5, [r0, 0x1D]
	strb r2, [r0, 0x1E]
	strb r2, [r0, 0x1F]
	adds r4, r0, 0
	movs r1, 0x6
	adds r0, 0x1A
@080046AE:
	strb r2, [r0]
	subs r0, 0x1
	subs r1, 0x1
	cmp r1, 0
	bge @080046AE
	adds r1, r4, 0
	adds r0, r6, 0
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldr r0, [r0]
	str r0, [r1]
	mov r0, r12
	str r0, [r4, 0x10]
	adds r0, r4, 0
	adds r0, 0x20
	movs r1, 0
	strb r1, [r0]
	adds r0, 0x1
	strb r1, [r0]
	ldrb r0, [r6, 0xC]
	lsrs r0, 4
	ldrb r2, [r6, 0xD]
	lsls r1, r2, 28
	lsrs r1, 28
	lsrs r2, 4
	bl GenerateFontHalfRowLookupTable
	cmp r5, 0xFF
	beq @08004718
	cmp r5, 0
	beq @08004718
	ldrb r0, [r4, 0x1D]
	subs r0, 0x1
	strb r0, [r4, 0x1D]
	ldr r2, =0x020201b0
	ldrb r0, [r6, 0x4]
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	adds r0, r4, 0
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	ldm r0!, {r2,r3,r7}
	stm r1!, {r2,r3,r7}
	ldm r0!, {r2,r4,r7}
	stm r1!, {r2,r4,r7}
	b @0800475E
	.pool
@08004718:
	ldr r1, =0x0202018c
	movs r0, 0
	strb r0, [r1, 0x1D]
	movs r4, 0
	ldr r7, =0x000003ff
	b @08004732
	.pool
@0800472C:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
@08004732:
	cmp r4, r7
	bhi @08004740
	ldr r0, =0x0202018c
	bl RenderFont
	cmp r0, 0x1
	bne @0800472C
@08004740:
	cmp r5, 0xFF
	beq @0800474E
	ldr r0, =0x0202018c
	ldrb r0, [r0, 0x4]
	movs r1, 0x2
	bl CopyWindowToVram
@0800474E:
	ldr r2, =0x020201b0
	ldrb r1, [r6, 0x4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x1B]
@0800475E:
	ldr r1, =0x03002f84
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
@08004766:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end AddTextPrinter

	thumb_func_start RunTextPrinters
; void RunTextPrinters()
RunTextPrinters: ; 8004778
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =0x03002f84
	ldrb r0, [r0]
	cmp r0, 0
	bne @080047F6
	ldr r0, =0x020201b0
	movs r6, 0
	adds r5, r0, 0x4
	mov r8, r0
	movs r7, 0x1F
@08004790:
	ldrb r0, [r5, 0x17]
	cmp r0, 0
	beq @080047E8
	mov r0, r8
	bl RenderFont
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1
	beq @080047E4
	cmp r4, 0x1
	bgt @080047B8
	cmp r4, 0
	beq @080047BE
	b @080047E8
	.pool
@080047B8:
	cmp r4, 0x3
	beq @080047C6
	b @080047E8
@080047BE:
	ldrb r0, [r5]
	movs r1, 0x2
	bl CopyWindowToVram
@080047C6:
	ldr r1, =0x020201b0
	adds r0, r1, 0
	adds r0, 0x10
	adds r0, r6, r0
	ldr r2, [r0]
	cmp r2, 0
	beq @080047E8
	adds r0, r6, r1
	adds r1, r4, 0
	bl _call_via_r2
	b @080047E8
	.pool
@080047E4:
	movs r0, 0
	strb r0, [r5, 0x17]
@080047E8:
	adds r6, 0x24
	adds r5, 0x24
	movs r0, 0x24
	add r8, r0
	subs r7, 0x1
	cmp r7, 0
	bge @08004790
@080047F6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end RunTextPrinters

	thumb_func_start IsTextPrinterActive
; BOOL IsTextPrinterActive(u8 id)
IsTextPrinterActive: ; 8004800
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x020201b0
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x1B]
	bx lr
	.pool
	thumb_func_end IsTextPrinterActive

	thumb_func_start RenderFont
; u16 RenderFont(struct TextPrinter *textPrinter)
RenderFont: ; 8004818
	push {r4,lr}
	adds r4, r0, 0
@0800481C:
	ldrb r1, [r4, 0x5]
	ldr r0, =0x03002f80
	ldr r2, [r0]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldr r1, [r0]
	adds r0, r4, 0
	bl _call_via_r1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x2
	beq @0800481C
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end RenderFont

	thumb_func_start GenerateFontHalfRowLookupTable
; void GenerateFontHalfRowLookupTable(u8 fgColor, u8 bgColor, u8 shadowColor)
GenerateFontHalfRowLookupTable: ; 8004844
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x24
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	ldr r3, =0x03000948
	ldr r4, =0x030009ea
	strh r1, [r4]
	ldr r4, =0x030009ec
	strh r0, [r4]
	ldr r4, =0x030009ee
	strh r2, [r4]
	lsls r5, r1, 12
	lsls r6, r0, 12
	lsls r4, r2, 12
	mov r8, r4
	lsls r7, r1, 8
	str r7, [sp]
	lsls r4, r1, 4
	mov r9, r4
	orrs r7, r4
	str r7, [sp, 0x4]
	orrs r7, r1
	adds r4, r5, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	adds r4, r6, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	mov r4, r8
	orrs r7, r4
	strh r7, [r3]
	adds r3, 0x2
	lsls r7, r0, 8
	mov r10, r7
	mov r4, r10
	mov r7, r9
	orrs r4, r7
	str r4, [sp, 0x8]
	adds r7, r4, 0
	orrs r7, r1
	adds r4, r5, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	adds r4, r6, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	mov r4, r8
	orrs r7, r4
	strh r7, [r3]
	adds r3, 0x2
	lsls r7, r2, 8
	mov r12, r7
	mov r4, r12
	mov r7, r9
	orrs r4, r7
	str r4, [sp, 0xC]
	adds r7, r4, 0
	orrs r7, r1
	adds r4, r5, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	adds r4, r6, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	mov r4, r8
	orrs r7, r4
	strh r7, [r3]
	adds r3, 0x2
	lsls r7, r0, 4
	mov r9, r7
	ldr r4, [sp]
	orrs r4, r7
	str r4, [sp, 0x10]
	adds r7, r4, 0
	orrs r7, r1
	adds r4, r5, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	adds r4, r6, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	mov r4, r8
	orrs r7, r4
	strh r7, [r3]
	adds r3, 0x2
	mov r7, r10
	adds r4, r7, 0
	mov r7, r9
	orrs r4, r7
	str r4, [sp, 0x14]
	adds r7, r4, 0
	orrs r7, r1
	adds r4, r5, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	adds r4, r6, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	mov r4, r8
	orrs r7, r4
	strh r7, [r3]
	adds r3, 0x2
	mov r7, r12
	adds r4, r7, 0
	mov r7, r9
	orrs r4, r7
	str r4, [sp, 0x18]
	adds r7, r4, 0
	orrs r7, r1
	adds r4, r5, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	adds r4, r6, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	mov r4, r8
	orrs r7, r4
	strh r7, [r3]
	adds r3, 0x2
	lsls r7, r2, 4
	mov r9, r7
	mov r4, r9
	ldr r7, [sp]
	orrs r7, r4
	str r7, [sp, 0x1C]
	orrs r7, r1
	adds r4, r5, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	adds r4, r6, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	mov r4, r8
	orrs r7, r4
	strh r7, [r3]
	adds r3, 0x2
	mov r7, r9
	mov r4, r10
	orrs r4, r7
	str r4, [sp, 0x20]
	adds r7, r4, 0
	orrs r7, r1
	adds r4, r5, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	adds r4, r6, 0
	orrs r4, r7
	strh r4, [r3]
	adds r3, 0x2
	mov r4, r8
	orrs r7, r4
	strh r7, [r3]
	adds r3, 0x2
	mov r4, r12
	mov r7, r9
	orrs r4, r7
	adds r7, r4, 0
	orrs r7, r1
	adds r1, r5, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	adds r1, r6, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	mov r1, r8
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	ldr r7, [sp, 0x4]
	orrs r7, r0
	adds r1, r5, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	adds r1, r6, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	mov r1, r8
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	ldr r7, [sp, 0x8]
	orrs r7, r0
	adds r1, r5, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	adds r1, r6, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	mov r1, r8
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	ldr r7, [sp, 0xC]
	orrs r7, r0
	adds r1, r5, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	adds r1, r6, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	mov r1, r8
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	ldr r7, [sp, 0x10]
	orrs r7, r0
	adds r1, r5, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	adds r1, r6, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	mov r1, r8
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	ldr r7, [sp, 0x14]
	orrs r7, r0
	adds r1, r5, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	adds r1, r6, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	mov r1, r8
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	ldr r7, [sp, 0x18]
	orrs r7, r0
	adds r1, r5, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	adds r1, r6, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	mov r1, r8
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	ldr r7, [sp, 0x1C]
	orrs r7, r0
	adds r1, r5, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	adds r1, r6, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	mov r1, r8
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	ldr r7, [sp, 0x20]
	orrs r7, r0
	adds r1, r5, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	adds r1, r6, 0
	orrs r1, r7
	strh r1, [r3]
	adds r3, 0x2
	mov r1, r8
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	adds r7, r4, 0
	orrs r7, r0
	adds r0, r5, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	adds r0, r6, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	adds r7, r2, 0
	ldr r0, [sp, 0x4]
	orrs r7, r0
	adds r0, r5, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	adds r0, r6, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	orrs r7, r1
	strh r7, [r3]
	adds r3, 0x2
	adds r7, r2, 0
	ldr r1, [sp, 0x8]
	orrs r7, r1
	adds r0, r5, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	adds r0, r6, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	mov r0, r8
	orrs r7, r0
	strh r7, [r3]
	adds r3, 0x2
	adds r7, r2, 0
	ldr r1, [sp, 0xC]
	orrs r7, r1
	adds r0, r5, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	adds r0, r6, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	mov r0, r8
	orrs r7, r0
	strh r7, [r3]
	adds r3, 0x2
	adds r7, r2, 0
	ldr r1, [sp, 0x10]
	orrs r7, r1
	adds r0, r5, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	adds r0, r6, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	mov r0, r8
	orrs r7, r0
	strh r7, [r3]
	adds r3, 0x2
	adds r7, r2, 0
	ldr r1, [sp, 0x14]
	orrs r7, r1
	adds r0, r5, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	adds r0, r6, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	mov r0, r8
	orrs r7, r0
	strh r7, [r3]
	adds r3, 0x2
	adds r7, r2, 0
	ldr r1, [sp, 0x18]
	orrs r7, r1
	adds r0, r5, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	adds r0, r6, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	mov r0, r8
	orrs r7, r0
	strh r7, [r3]
	adds r3, 0x2
	adds r7, r2, 0
	ldr r1, [sp, 0x1C]
	orrs r7, r1
	adds r0, r5, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	adds r0, r6, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	mov r0, r8
	orrs r7, r0
	strh r7, [r3]
	adds r3, 0x2
	adds r7, r2, 0
	ldr r1, [sp, 0x20]
	orrs r7, r1
	adds r0, r5, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	adds r0, r6, 0
	orrs r0, r7
	strh r0, [r3]
	adds r3, 0x2
	mov r0, r8
	orrs r7, r0
	strh r7, [r3]
	adds r3, 0x2
	adds r7, r2, 0
	orrs r7, r4
	orrs r5, r7
	strh r5, [r3]
	adds r3, 0x2
	orrs r6, r7
	strh r6, [r3]
	orrs r0, r7
	strh r0, [r3, 0x2]
	add sp, 0x24
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GenerateFontHalfRowLookupTable

	thumb_func_start SaveTextColors
; void SaveTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor)
SaveTextColors: ; 8004BE0
	ldr r3, =0x030009ea
	ldrh r3, [r3]
	strb r3, [r1]
	ldr r1, =0x030009ec
	ldrh r1, [r1]
	strb r1, [r0]
	ldr r0, =0x030009ee
	ldrh r0, [r0]
	strb r0, [r2]
	bx lr
	.pool
	thumb_func_end SaveTextColors

	thumb_func_start RestoreTextColors
; void RestoreTextColors(u8 *fgColor, u8 *bgColor, u8 *shadowColor)
RestoreTextColors: ; 8004C00
	push {lr}
	ldrb r0, [r0]
	ldrb r1, [r1]
	ldrb r2, [r2]
	bl GenerateFontHalfRowLookupTable
	pop {r0}
	bx r0
	thumb_func_end RestoreTextColors

	thumb_func_start DecompressGlyphTile
; void DecompressGlyphTile(u16 *src, u32 *dest)
DecompressGlyphTile: ; 8004C10
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldrh r7, [r0]
	ldr r5, =0x03000948
	ldr r4, =gFontHalfRowOffsets
	movs r2, 0xFF
	mov r8, r2
	adds r2, r7, 0
	mov r3, r8
	ands r2, r3
	adds r2, r4
	ldrb r2, [r2]
	lsls r2, 1
	adds r2, r5
	ldrh r3, [r2]
	lsls r3, 16
	lsrs r2, r7, 8
	adds r2, r4
	ldrb r2, [r2]
	lsls r2, 1
	adds r2, r5
	ldrh r2, [r2]
	orrs r3, r2
	adds r6, r1, 0
	stm r6!, {r3}
	ldrh r7, [r0, 0x2]
	adds r0, 0x4
	adds r2, r7, 0
	mov r3, r8
	ands r2, r3
	adds r2, r4
	ldrb r2, [r2]
	lsls r2, 1
	adds r2, r5
	ldrh r3, [r2]
	lsls r3, 16
	lsrs r2, r7, 8
	adds r2, r4
	ldrb r2, [r2]
	lsls r2, 1
	adds r2, r5
	ldrh r2, [r2]
	orrs r3, r2
	str r3, [r1, 0x4]
	adds r6, 0x4
	ldrh r7, [r0]
	adds r0, 0x2
	adds r1, r7, 0
	mov r2, r8
	ands r1, r2
	adds r1, r4
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r5
	ldrh r2, [r1]
	lsls r2, 16
	lsrs r1, r7, 8
	adds r1, r4
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r5
	ldrh r1, [r1]
	orrs r2, r1
	stm r6!, {r2}
	ldrh r7, [r0]
	adds r0, 0x2
	adds r1, r7, 0
	mov r3, r8
	ands r1, r3
	adds r1, r4
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r5
	ldrh r2, [r1]
	lsls r2, 16
	lsrs r1, r7, 8
	adds r1, r4
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r5
	ldrh r1, [r1]
	orrs r2, r1
	stm r6!, {r2}
	ldrh r7, [r0]
	adds r0, 0x2
	adds r1, r7, 0
	ands r1, r3
	adds r1, r4
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r5
	ldrh r2, [r1]
	lsls r2, 16
	lsrs r1, r7, 8
	adds r1, r4
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r5
	ldrh r1, [r1]
	orrs r2, r1
	stm r6!, {r2}
	ldrh r7, [r0]
	adds r0, 0x2
	adds r1, r7, 0
	ands r1, r3
	adds r1, r4
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r5
	ldrh r2, [r1]
	lsls r2, 16
	lsrs r1, r7, 8
	adds r1, r4
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r5
	ldrh r1, [r1]
	orrs r2, r1
	stm r6!, {r2}
	ldrh r7, [r0]
	adds r1, r7, 0
	ands r1, r3
	adds r1, r4
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r5
	ldrh r2, [r1]
	lsls r2, 16
	lsrs r1, r7, 8
	adds r1, r4
	ldrb r1, [r1]
	lsls r1, 1
	adds r1, r5
	ldrh r1, [r1]
	orrs r2, r1
	stm r6!, {r2}
	ldrh r7, [r0, 0x2]
	adds r0, r7, 0
	ands r0, r3
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r5
	ldrh r1, [r0]
	lsls r1, 16
	lsrs r0, r7, 8
	adds r0, r4
	ldrb r0, [r0]
	lsls r0, 1
	adds r0, r5
	ldrh r0, [r0]
	orrs r1, r0
	str r1, [r6]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressGlyphTile

	thumb_func_start GetLastTextColor
; u8 GetLastTextColor(u8 colorType)
GetLastTextColor: ; 8004D58
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x1
	beq @08004D8C
	cmp r0, 0x1
	bgt @08004D6E
	cmp r0, 0
	beq @08004D74
	b @08004D98
@08004D6E:
	cmp r1, 0x2
	beq @08004D80
	b @08004D98
@08004D74:
	ldr r0, =0x030009ec
	ldrb r0, [r0]
	b @08004D9A
	.pool
@08004D80:
	ldr r0, =0x030009ea
	ldrb r0, [r0]
	b @08004D9A
	.pool
@08004D8C:
	ldr r0, =0x030009ee
	ldrb r0, [r0]
	b @08004D9A
	.pool
@08004D98:
	movs r0, 0
@08004D9A:
	pop {r1}
	bx r1
	thumb_func_end GetLastTextColor

	thumb_func_start CopyGlyphToWindow
; int CopyGlyphToWindow(struct TextPrinter *x)
CopyGlyphToWindow: ; 8004DA0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8C
	adds r3, r0, 0
	ldrb r1, [r3, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x02020004
	adds r1, r0, r1
	adds r2, r1, 0
	ldrb r7, [r1, 0x3]
	lsls r0, r7, 3
	ldrb r6, [r3, 0x8]
	subs r4, r0, r6
	ldr r5, =0x03002f90
	adds r0, r5, 0
	adds r0, 0x80
	ldrb r0, [r0]
	cmp r4, r0
	ble @08004DD2
	adds r4, r0, 0
@08004DD2:
	ldrb r0, [r1, 0x4]
	lsls r0, 3
	ldrb r3, [r3, 0x9]
	subs r0, r3
	adds r1, r5, 0
	adds r1, 0x81
	ldrb r1, [r1]
	cmp r0, r1
	ble @08004DE6
	adds r0, r1, 0
@08004DE6:
	str r6, [sp]
	mov r8, r3
	adds r3, r5, 0
	ldr r2, [r2, 0x8]
	mov r9, r2
	lsls r1, r7, 5
	str r1, [sp, 0x4]
	cmp r4, 0x8
	ble @08004DFA
	b @08004F94
@08004DFA:
	cmp r0, 0x8
	bgt @08004E84
	mov r1, r8
	str r3, [sp, 0x8]
	adds r2, r6, 0
	adds r2, r4
	mov r8, r2
	adds r0, r1, r0
	str r0, [sp, 0xC]
	str r6, [sp, 0x10]
	cmp r1, r0
	bcc @08004E14
	b @080052AA
@08004E14:
	ldr r3, [sp, 0x8]
	ldm r3!, {r5}
	str r3, [sp, 0x8]
	ldr r4, [sp, 0x10]
	adds r0, r1, 0x1
	mov r10, r0
	cmp r4, r8
	bcs @08004E72
	movs r2, 0x7
	mov r12, r2
	lsrs r0, r1, 3
	ldr r2, [sp, 0x4]
	adds r3, r0, 0
	muls r3, r2
	adds r7, r3, 0
	mov r3, r12
	ands r1, r3
	lsls r6, r1, 2
@08004E38:
	adds r3, r5, 0
	movs r0, 0xF
	ands r3, r0
	cmp r3, 0
	beq @08004E6A
	lsrs r2, r4, 3
	lsls r2, 5
	add r2, r9
	adds r0, r4, 0
	mov r1, r12
	ands r0, r1
	lsrs r0, 1
	adds r2, r0
	adds r2, r7
	adds r2, r6
	movs r1, 0x1
	ands r1, r4
	lsls r1, 2
	lsls r3, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r2]
	ands r0, r1
	orrs r3, r0
	strb r3, [r2]
@08004E6A:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc @08004E38
@08004E72:
	mov r1, r10
	ldr r2, [sp, 0xC]
	cmp r1, r2
	bcc @08004E14
	b @080052AA
	.pool
@08004E84:
	mov r1, r8
	str r3, [sp, 0x14]
	ldr r3, [sp]
	adds r3, r4
	mov r12, r3
	adds r2, r1, 0
	adds r2, 0x8
	str r2, [sp, 0x18]
	ldr r3, [sp]
	str r3, [sp, 0x1C]
	mov r2, r12
	str r2, [sp, 0x74]
	ldr r3, [sp, 0x18]
	str r3, [sp, 0x88]
	subs r0, 0x8
	str r0, [sp, 0x80]
	cmp r1, r3
	bcs @08004F0E
@08004EA8:
	ldr r0, [sp, 0x14]
	ldm r0!, {r5}
	str r0, [sp, 0x14]
	ldr r4, [sp, 0x1C]
	adds r2, r1, 0x1
	mov r8, r2
	cmp r4, r12
	bcs @08004F06
	movs r3, 0x7
	mov r10, r3
	lsrs r0, r1, 3
	ldr r3, [sp, 0x4]
	adds r2, r0, 0
	muls r2, r3
	adds r7, r2, 0
	mov r0, r10
	ands r1, r0
	lsls r6, r1, 2
@08004ECC:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq @08004EFE
	lsrs r2, r4, 3
	lsls r2, 5
	add r2, r9
	adds r0, r4, 0
	mov r1, r10
	ands r0, r1
	lsrs r0, 1
	adds r2, r0
	adds r2, r7
	adds r2, r6
	movs r1, 0x1
	ands r1, r4
	lsls r1, 2
	lsls r3, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r2]
	ands r0, r1
	orrs r3, r0
	strb r3, [r2]
@08004EFE:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r12
	bcc @08004ECC
@08004F06:
	mov r1, r8
	ldr r2, [sp, 0x18]
	cmp r1, r2
	bcc @08004EA8
@08004F0E:
	ldr r1, [sp, 0x88]
	ldr r3, =0x03002fd0
	str r3, [sp, 0x20]
	ldr r0, [sp, 0x74]
	mov r8, r0
	ldr r2, [sp, 0x80]
	adds r2, r1, r2
	str r2, [sp, 0x24]
	ldr r3, [sp]
	str r3, [sp, 0x28]
	cmp r1, r2
	bcc @08004F28
	b @080052AA
@08004F28:
	ldr r0, [sp, 0x20]
	ldm r0!, {r5}
	str r0, [sp, 0x20]
	ldr r4, [sp, 0x28]
	adds r2, r1, 0x1
	mov r10, r2
	cmp r4, r8
	bcs @08004F86
	movs r3, 0x7
	mov r12, r3
	lsrs r0, r1, 3
	ldr r3, [sp, 0x4]
	adds r2, r0, 0
	muls r2, r3
	adds r7, r2, 0
	mov r0, r12
	ands r1, r0
	lsls r6, r1, 2
@08004F4C:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq @08004F7E
	lsrs r2, r4, 3
	lsls r2, 5
	add r2, r9
	adds r0, r4, 0
	mov r1, r12
	ands r0, r1
	lsrs r0, 1
	adds r2, r0
	adds r2, r7
	adds r2, r6
	movs r1, 0x1
	ands r1, r4
	lsls r1, 2
	lsls r3, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r2]
	ands r0, r1
	orrs r3, r0
	strb r3, [r2]
@08004F7E:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc @08004F4C
@08004F86:
	mov r1, r10
	ldr r2, [sp, 0x24]
	cmp r1, r2
	bcc @08004F28
	b @080052AA
	.pool
@08004F94:
	cmp r0, 0x8
	ble @08004F9A
	b @080050A4
@08004F9A:
	mov r1, r8
	str r3, [sp, 0x2C]
	ldr r3, [sp]
	adds r3, 0x8
	mov r12, r3
	add r0, r8
	str r0, [sp, 0x30]
	ldr r0, [sp]
	str r0, [sp, 0x34]
	ldr r2, [sp, 0x30]
	str r2, [sp, 0x78]
	str r3, [sp, 0x84]
	subs r4, 0x8
	str r4, [sp, 0x7C]
	cmp r8, r2
	bcs @0800501C
@08004FBA:
	ldr r0, [sp, 0x2C]
	ldm r0!, {r5}
	str r0, [sp, 0x2C]
	ldr r4, [sp, 0x34]
	adds r2, r1, 0x1
	mov r10, r2
	cmp r4, r12
	bcs @08005014
	lsrs r0, r1, 3
	ldr r2, [sp, 0x4]
	adds r3, r0, 0
	muls r3, r2
	adds r7, r3, 0
	movs r3, 0x7
	ands r1, r3
	lsls r6, r1, 2
@08004FDA:
	adds r3, r5, 0
	movs r0, 0xF
	ands r3, r0
	cmp r3, 0
	beq @0800500C
	lsrs r2, r4, 3
	lsls r2, 5
	add r2, r9
	adds r0, r4, 0
	movs r1, 0x7
	ands r0, r1
	lsrs r0, 1
	adds r2, r0
	adds r2, r7
	adds r2, r6
	movs r1, 0x1
	ands r1, r4
	lsls r1, 2
	lsls r3, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r2]
	ands r0, r1
	orrs r3, r0
	strb r3, [r2]
@0800500C:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r12
	bcc @08004FDA
@08005014:
	mov r1, r10
	ldr r2, [sp, 0x30]
	cmp r1, r2
	bcc @08004FBA
@0800501C:
	mov r1, r8
	ldr r3, =0x03002fb0
	str r3, [sp, 0x38]
	ldr r0, [sp, 0x84]
	ldr r2, [sp, 0x7C]
	adds r0, r2
	mov r8, r0
	ldr r3, [sp, 0x78]
	str r3, [sp, 0x3C]
	ldr r0, [sp, 0x84]
	str r0, [sp, 0x40]
	cmp r1, r3
	bcc @08005038
	b @080052AA
@08005038:
	ldr r2, [sp, 0x38]
	ldm r2!, {r5}
	str r2, [sp, 0x38]
	ldr r4, [sp, 0x40]
	adds r3, r1, 0x1
	mov r10, r3
	cmp r4, r8
	bcs @08005096
	movs r0, 0x7
	mov r12, r0
	lsrs r0, r1, 3
	ldr r3, [sp, 0x4]
	adds r2, r0, 0
	muls r2, r3
	adds r7, r2, 0
	mov r0, r12
	ands r1, r0
	lsls r6, r1, 2
@0800505C:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq @0800508E
	lsrs r2, r4, 3
	lsls r2, 5
	add r2, r9
	adds r0, r4, 0
	mov r1, r12
	ands r0, r1
	lsrs r0, 1
	adds r2, r0
	adds r2, r7
	adds r2, r6
	movs r1, 0x1
	ands r1, r4
	lsls r1, 2
	lsls r3, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r2]
	ands r0, r1
	orrs r3, r0
	strb r3, [r2]
@0800508E:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc @0800505C
@08005096:
	mov r1, r10
	ldr r2, [sp, 0x3C]
	cmp r1, r2
	bcc @08005038
	b @080052AA
	.pool
@080050A4:
	mov r1, r8
	str r5, [sp, 0x44]
	ldr r3, [sp]
	adds r3, 0x8
	mov r12, r3
	mov r2, r8
	adds r2, 0x8
	str r2, [sp, 0x48]
	ldr r3, [sp]
	str r3, [sp, 0x4C]
	str r2, [sp, 0x88]
	subs r0, 0x8
	str r0, [sp, 0x80]
	mov r0, r12
	str r0, [sp, 0x84]
	subs r4, 0x8
	str r4, [sp, 0x7C]
	cmp r8, r2
	bcs @0800512C
@080050CA:
	ldr r2, [sp, 0x44]
	ldm r2!, {r5}
	str r2, [sp, 0x44]
	ldr r4, [sp, 0x4C]
	adds r3, r1, 0x1
	mov r10, r3
	cmp r4, r12
	bcs @08005124
	lsrs r0, r1, 3
	ldr r3, [sp, 0x4]
	adds r2, r0, 0
	muls r2, r3
	adds r7, r2, 0
	movs r0, 0x7
	ands r1, r0
	lsls r6, r1, 2
@080050EA:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq @0800511C
	lsrs r2, r4, 3
	lsls r2, 5
	add r2, r9
	adds r0, r4, 0
	movs r1, 0x7
	ands r0, r1
	lsrs r0, 1
	adds r2, r0
	adds r2, r7
	adds r2, r6
	movs r1, 0x1
	ands r1, r4
	lsls r1, 2
	lsls r3, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r2]
	ands r0, r1
	orrs r3, r0
	strb r3, [r2]
@0800511C:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r12
	bcc @080050EA
@08005124:
	mov r1, r10
	ldr r2, [sp, 0x48]
	cmp r1, r2
	bcc @080050CA
@0800512C:
	mov r1, r8
	ldr r3, =0x03002fb0
	str r3, [sp, 0x50]
	ldr r0, [sp, 0x84]
	ldr r2, [sp, 0x7C]
	adds r0, r2
	mov r8, r0
	ldr r3, [sp, 0x88]
	str r3, [sp, 0x54]
	ldr r0, [sp, 0x84]
	str r0, [sp, 0x58]
	cmp r1, r3
	bcs @080051AC
@08005146:
	ldr r2, [sp, 0x50]
	ldm r2!, {r5}
	str r2, [sp, 0x50]
	ldr r4, [sp, 0x58]
	adds r3, r1, 0x1
	mov r10, r3
	cmp r4, r8
	bcs @080051A4
	movs r0, 0x7
	mov r12, r0
	lsrs r0, r1, 3
	ldr r3, [sp, 0x4]
	adds r2, r0, 0
	muls r2, r3
	adds r7, r2, 0
	mov r0, r12
	ands r1, r0
	lsls r6, r1, 2
@0800516A:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq @0800519C
	lsrs r2, r4, 3
	lsls r2, 5
	add r2, r9
	adds r0, r4, 0
	mov r1, r12
	ands r0, r1
	lsrs r0, 1
	adds r2, r0
	adds r2, r7
	adds r2, r6
	movs r1, 0x1
	ands r1, r4
	lsls r1, 2
	lsls r3, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r2]
	ands r0, r1
	orrs r3, r0
	strb r3, [r2]
@0800519C:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc @0800516A
@080051A4:
	mov r1, r10
	ldr r2, [sp, 0x54]
	cmp r1, r2
	bcc @08005146
@080051AC:
	ldr r1, [sp, 0x88]
	ldr r3, =0x03002fd0
	str r3, [sp, 0x5C]
	ldr r0, [sp, 0x84]
	mov r8, r0
	ldr r2, [sp, 0x80]
	adds r2, r1, r2
	str r2, [sp, 0x60]
	ldr r3, [sp]
	str r3, [sp, 0x64]
	cmp r1, r2
	bcs @0800522A
@080051C4:
	ldr r0, [sp, 0x5C]
	ldm r0!, {r5}
	str r0, [sp, 0x5C]
	ldr r4, [sp, 0x64]
	adds r2, r1, 0x1
	mov r10, r2
	cmp r4, r8
	bcs @08005222
	movs r3, 0x7
	mov r12, r3
	lsrs r0, r1, 3
	ldr r3, [sp, 0x4]
	adds r2, r0, 0
	muls r2, r3
	adds r7, r2, 0
	mov r0, r12
	ands r1, r0
	lsls r6, r1, 2
@080051E8:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq @0800521A
	lsrs r2, r4, 3
	lsls r2, 5
	add r2, r9
	adds r0, r4, 0
	mov r1, r12
	ands r0, r1
	lsrs r0, 1
	adds r2, r0
	adds r2, r7
	adds r2, r6
	movs r1, 0x1
	ands r1, r4
	lsls r1, 2
	lsls r3, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r2]
	ands r0, r1
	orrs r3, r0
	strb r3, [r2]
@0800521A:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc @080051E8
@08005222:
	mov r1, r10
	ldr r2, [sp, 0x60]
	cmp r1, r2
	bcc @080051C4
@0800522A:
	ldr r4, [sp, 0x84]
	ldr r1, [sp, 0x88]
	ldr r3, =0x03002ff0
	str r3, [sp, 0x68]
	ldr r0, [sp, 0x7C]
	adds r0, r4
	mov r8, r0
	ldr r2, [sp, 0x80]
	adds r2, r1, r2
	str r2, [sp, 0x6C]
	str r4, [sp, 0x70]
	cmp r1, r2
	bcs @080052AA
@08005244:
	ldr r3, [sp, 0x68]
	ldm r3!, {r5}
	str r3, [sp, 0x68]
	ldr r4, [sp, 0x70]
	adds r0, r1, 0x1
	mov r10, r0
	cmp r4, r8
	bcs @080052A2
	movs r2, 0x7
	mov r12, r2
	lsrs r0, r1, 3
	ldr r2, [sp, 0x4]
	adds r3, r0, 0
	muls r3, r2
	adds r7, r3, 0
	mov r3, r12
	ands r1, r3
	lsls r6, r1, 2
@08005268:
	adds r3, r5, 0
	movs r0, 0xF
	ands r3, r0
	cmp r3, 0
	beq @0800529A
	lsrs r2, r4, 3
	lsls r2, 5
	add r2, r9
	adds r0, r4, 0
	mov r1, r12
	ands r0, r1
	lsrs r0, 1
	adds r2, r0
	adds r2, r7
	adds r2, r6
	movs r1, 0x1
	ands r1, r4
	lsls r1, 2
	lsls r3, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r2]
	ands r0, r1
	orrs r3, r0
	strb r3, [r2]
@0800529A:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc @08005268
@080052A2:
	mov r1, r10
	ldr r2, [sp, 0x6C]
	cmp r1, r2
	bcc @08005244
@080052AA:
	add sp, 0x8C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyGlyphToWindow

	thumb_func_start ClearTextSpan
; void ClearTextSpan(TextPrinter *textPrinter, u32 width)
ClearTextSpan: ; 80052C8
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, =0x030009ea
	ldrh r5, [r0]
	cmp r5, 0
	beq @0800531E
	ldrb r1, [r4, 0x4]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 2
	ldr r1, =0x02020004
	adds r0, r1
	ldr r1, [r0, 0x8]
	str r1, [sp, 0x8]
	ldrb r2, [r0, 0x3]
	lsls r2, 3
	ldr r3, =0xffff0000
	ldr r1, [sp, 0xC]
	ands r1, r3
	orrs r1, r2
	str r1, [sp, 0xC]
	ldrb r2, [r0, 0x4]
	lsls r2, 19
	ldr r0, =0x0000ffff
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0xC]
	ldr r0, =0x03002f90
	adds r0, 0x81
	ldrb r1, [r4, 0x8]
	ldrb r2, [r4, 0x9]
	lsls r3, r6, 16
	lsrs r3, 16
	ldrb r0, [r0]
	str r0, [sp]
	lsls r0, r5, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	add r0, sp, 0x8
	bl FillBitmapRect4Bit
@0800531E:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearTextSpan

	thumb_func_start Font0Func
; int Font0Func(struct TextPrinter *x)
Font0Func: ; 800533C
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @08005360
	ldrb r1, [r2, 0x14]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x1]
@08005360:
	adds r0, r2, 0
	bl RenderText
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font0Func

	thumb_func_start Font1Func
; int Font1Func(struct TextPrinter *x)
Font1Func: ; 8005370
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @08005398
	ldrb r1, [r2, 0x14]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x1]
@08005398:
	adds r0, r2, 0
	bl RenderText
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font1Func

	thumb_func_start Font2Func
; int Font2Func(struct TextPrinter *x)
Font2Func: ; 80053A8
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @080053D0
	ldrb r1, [r2, 0x14]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x1]
@080053D0:
	adds r0, r2, 0
	bl RenderText
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font2Func

	thumb_func_start Font3Func
; int Font3Func(struct TextPrinter *x)
Font3Func: ; 80053E0
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @08005408
	ldrb r1, [r2, 0x14]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x3
	orrs r0, r1
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x1]
@08005408:
	adds r0, r2, 0
	bl RenderText
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font3Func

	thumb_func_start Font4Func
; int Font4Func(struct TextPrinter *x)
Font4Func: ; 8005418
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @08005440
	ldrb r1, [r2, 0x14]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x1]
@08005440:
	adds r0, r2, 0
	bl RenderText
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font4Func

	thumb_func_start Font5Func
; int Font5Func(struct TextPrinter *x)
Font5Func: ; 8005450
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @08005478
	ldrb r1, [r2, 0x14]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x5
	orrs r0, r1
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x1]
@08005478:
	adds r0, r2, 0
	bl RenderText
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font5Func

	thumb_func_start Font7Func
; int Font7Func(struct TextPrinter *x)
Font7Func: ; 8005488
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @080054B0
	ldrb r1, [r2, 0x14]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x7
	orrs r0, r1
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x1]
@080054B0:
	adds r0, r2, 0
	bl RenderText
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font7Func

	thumb_func_start Font8Func
; int Font8Func(struct TextPrinter *x)
Font8Func: ; 80054C0
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne @080054E8
	ldrb r1, [r2, 0x14]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x1]
@080054E8:
	adds r0, r2, 0
	bl RenderText
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font8Func

	thumb_func_start TextPrinterInitDownArrowCounters
; void TextPrinterInitDownArrowCounters(struct TextPrinter *textPrinter)
TextPrinterInitDownArrowCounters: ; 80054F8
	push {lr}
	adds r2, r0, 0
	adds r2, 0x14
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq @08005514
	movs r0, 0
	strb r0, [r2, 0x2]
	b @08005524
	.pool
@08005514:
	ldrb r0, [r2, 0x1]
	movs r1, 0x61
	negs r1, r1
	ands r1, r0
	movs r0, 0x20
	negs r0, r0
	ands r1, r0
	strb r1, [r2, 0x1]
@08005524:
	pop {r0}
	bx r0
	thumb_func_end TextPrinterInitDownArrowCounters

	thumb_func_start TextPrinterDrawDownArrow
; void TextPrinterDrawDownArrow(struct TextPrinter *textPrinter)
TextPrinterDrawDownArrow: ; 8005528
	push {r4-r7,lr}
	sub sp, 0x18
	adds r5, r0, 0
	adds r6, r5, 0
	adds r6, 0x14
	ldr r7, =0x03003014
	ldrb r1, [r7]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne @080055EE
	ldrb r2, [r6, 0x1]
	movs r0, 0x1F
	ands r0, r2
	cmp r0, 0
	beq @08005560
	ldr r0, [r5, 0x14]
	lsls r0, 19
	lsrs r0, 27
	subs r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	movs r1, 0x20
	negs r1, r1
	b @080055E8
	.pool
@08005560:
	ldrb r0, [r5, 0x4]
	ldrb r2, [r5, 0xD]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	ldrb r2, [r5, 0x8]
	ldrb r3, [r5, 0x9]
	movs r4, 0x8
	str r4, [sp]
	movs r4, 0x10
	str r4, [sp, 0x4]
	bl FillWindowPixelRect
	ldr r0, [r7]
	lsls r0, 30
	lsrs r0, 31
	cmp r0, 0
	beq @0800558A
	cmp r0, 0x1
	beq @08005594
@0800558A:
	ldr r7, =gDownArrowTiles
	b @08005596
	.pool
@08005594:
	ldr r7, =gDarkDownArrowTiles
@08005596:
	ldrb r0, [r5, 0x4]
	ldr r2, =gDownArrowYCoords
	ldr r1, [r6]
	lsls r1, 17
	lsrs r1, 30
	adds r1, r2
	ldrb r3, [r1]
	movs r4, 0x8
	str r4, [sp]
	movs r2, 0x10
	str r2, [sp, 0x4]
	ldrb r1, [r5, 0x8]
	str r1, [sp, 0x8]
	ldrb r1, [r5, 0x9]
	str r1, [sp, 0xC]
	str r4, [sp, 0x10]
	str r2, [sp, 0x14]
	adds r1, r7, 0
	movs r2, 0
	bl BlitBitmapRectToWindow
	ldrb r0, [r5, 0x4]
	movs r1, 0x2
	bl CopyWindowToVram
	ldrb r0, [r6, 0x1]
	movs r1, 0x20
	negs r1, r1
	ands r1, r0
	movs r0, 0x8
	orrs r1, r0
	strb r1, [r6, 0x1]
	ldr r0, [r6]
	lsls r0, 17
	lsrs r0, 30
	adds r0, 0x1
	movs r2, 0x3
	ands r0, r2
	lsls r0, 5
	movs r2, 0x61
	negs r2, r2
@080055E8:
	ands r1, r2
	orrs r1, r0
	strb r1, [r6, 0x1]
@080055EE:
	add sp, 0x18
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end TextPrinterDrawDownArrow

	thumb_func_start TextPrinterClearDownArrow
; void TextPrinterClearDownArrow(struct TextPrinter *textPrinter)
TextPrinterClearDownArrow: ; 8005600
	push {r4,r5,lr}
	sub sp, 0x8
	adds r5, r0, 0
	ldrb r0, [r5, 0x4]
	ldrb r2, [r5, 0xD]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	ldrb r2, [r5, 0x8]
	ldrb r3, [r5, 0x9]
	movs r4, 0x8
	str r4, [sp]
	movs r4, 0x10
	str r4, [sp, 0x4]
	bl FillWindowPixelRect
	ldrb r0, [r5, 0x4]
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end TextPrinterClearDownArrow

	thumb_func_start TextPrinterWaitAutoMode
; BOOL TextPrinterWaitAutoMode(struct TextPrinter *textPrinter)
TextPrinterWaitAutoMode: ; 8005634
	push {lr}
	adds r1, r0, 0
	adds r1, 0x14
	ldrb r0, [r1, 0x2]
	cmp r0, 0x31
	beq @08005648
	adds r0, 0x1
	strb r0, [r1, 0x2]
	movs r0, 0
	b @0800564A
@08005648:
	movs r0, 0x1
@0800564A:
	pop {r1}
	bx r1
	thumb_func_end TextPrinterWaitAutoMode

	thumb_func_start TextPrinterWaitWithDownArrow
; BOOL TextPrinterWaitWithDownArrow(struct TextPrinter *textPrinter)
TextPrinterWaitWithDownArrow: ; 8005650
	push {r4,lr}
	adds r2, r0, 0
	movs r4, 0
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq @08005674
	adds r0, r2, 0
	bl TextPrinterWaitAutoMode
	lsls r0, 24
	lsrs r4, r0, 24
	b @0800568E
	.pool
@08005674:
	adds r0, r2, 0
	bl TextPrinterDrawDownArrow
	ldr r0, =0x030022c0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq @0800568E
	movs r4, 0x1
	movs r0, 0x5
	bl audio_play
@0800568E:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end TextPrinterWaitWithDownArrow

	thumb_func_start TextPrinterWait
; BOOL TextPrinterWait(struct TextPrinter *textPrinter)
TextPrinterWait: ; 800569C
	push {r4,lr}
	adds r2, r0, 0
	movs r4, 0
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq @080056C0
	adds r0, r2, 0
	bl TextPrinterWaitAutoMode
	lsls r0, 24
	lsrs r4, r0, 24
	b @080056D4
	.pool
@080056C0:
	ldr r0, =0x030022c0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq @080056D4
	movs r4, 0x1
	movs r0, 0x5
	bl audio_play
@080056D4:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end TextPrinterWait

	thumb_func_start DrawDownArrow
; void DrawDownArrow(u8 windowId, u16 x, u16 y, u8 bgColor, BOOL drawArrow, u8 *counter, u8 *yCoordIndex)
DrawDownArrow: ; 80056E0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	ldr r4, [sp, 0x38]
	ldr r5, [sp, 0x3C]
	mov r9, r5
	ldr r5, [sp, 0x40]
	mov r10, r5
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	mov r1, r9
	ldrb r0, [r1]
	cmp r0, 0
	beq @0800571A
	subs r0, 0x1
	strb r0, [r1]
	b @0800579A
@0800571A:
	lsls r1, r3, 4
	orrs r1, r3
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0x8
	str r0, [sp]
	movs r0, 0x10
	str r0, [sp, 0x4]
	adds r0, r5, 0
	mov r2, r8
	adds r3, r7, 0
	bl FillWindowPixelRect
	cmp r4, 0
	bne @0800579A
	ldr r0, =0x03003014
	ldr r0, [r0]
	lsls r0, 30
	lsrs r0, 31
	cmp r0, 0
	beq @08005748
	cmp r0, 0x1
	beq @08005754
@08005748:
	ldr r6, =gDownArrowTiles
	b @08005756
	.pool
@08005754:
	ldr r6, =gDarkDownArrowTiles
@08005756:
	ldr r2, =gDownArrowYCoords
	mov r0, r10
	ldrb r1, [r0]
	movs r0, 0x3
	ands r0, r1
	adds r0, r2
	ldrb r3, [r0]
	movs r4, 0x8
	str r4, [sp]
	movs r1, 0x10
	str r1, [sp, 0x4]
	mov r0, r8
	str r0, [sp, 0x8]
	subs r0, r7, 0x2
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	str r4, [sp, 0x10]
	str r1, [sp, 0x14]
	adds r0, r5, 0
	adds r1, r6, 0
	movs r2, 0
	bl BlitBitmapRectToWindow
	adds r0, r5, 0
	movs r1, 0x2
	bl CopyWindowToVram
	mov r1, r9
	strb r4, [r1]
	mov r5, r10
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
@0800579A:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DrawDownArrow

	thumb_func_start RenderText
; u16 RenderText(struct TextPrinter *textPrinter)
RenderText: ; 80057B4
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r6, 0
	adds r4, 0x14
	ldrb r0, [r6, 0x1C]
	cmp r0, 0x6
	bls @080057C4
	b @08005D6C
@080057C4:
	lsls r0, 2
	ldr r1, =@080057D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@080057D4:
	.4byte @080057F0
	.4byte @08005C78
	.4byte @08005C8C
	.4byte @08005CB8
	.4byte @08005CF0
	.4byte @08005D48
	.4byte @08005D5A
@080057F0:
	ldr r2, =0x030022c0
	ldrh r1, [r2, 0x2C]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq @0800580A
	ldrb r1, [r4]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq @0800580A
	movs r0, 0
	strb r0, [r6, 0x1E]
@0800580A:
	ldrb r1, [r6, 0x1E]
	cmp r1, 0
	beq @0800584C
	ldrb r0, [r6, 0x1D]
	cmp r0, 0
	beq @0800584C
	subs r0, r1, 0x1
	strb r0, [r6, 0x1E]
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne @08005828
	b @08005B56
@08005828:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne @08005834
	b @08005B56
@08005834:
	ldrb r0, [r4]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0
	strb r0, [r6, 0x1E]
	b @08005B56
	.pool
@0800584C:
	ldr r0, =0x02022fec
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	bne @08005874
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq @08005874
	movs r0, 0x3
	b @08005876
	.pool
@08005874:
	ldrb r0, [r6, 0x1D]
@08005876:
	strb r0, [r6, 0x1E]
	ldr r0, [r6]
	ldrb r3, [r0]
	adds r0, 0x1
	str r0, [r6]
	adds r0, r3, 0
	subs r0, 0xF8
	cmp r0, 0x7
	bls @0800588A
	b @08005B90
@0800588A:
	lsls r0, 2
	ldr r1, =@08005898
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08005898:
	.4byte @08005B6C
	.4byte @08005B5A
	.4byte @08005B4C
	.4byte @08005B48
	.4byte @080058E0
	.4byte @080058DC
	.4byte @080058B8
	.4byte @08005D6C
@080058B8:
	ldrb r0, [r6, 0x6]
	strb r0, [r6, 0x8]
	ldrb r1, [r6, 0x5]
	ldr r0, =0x03002f80
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
	b @08005ABA
	.pool
@080058DC:
	ldr r0, [r6]
	b @08005B30
@080058E0:
	ldr r0, [r6]
	ldrb r3, [r0]
	adds r0, 0x1
	str r0, [r6]
	subs r0, r3, 0x1
	cmp r0, 0x17
	bls @080058F0
	b @08005B90
@080058F0:
	lsls r0, 2
	ldr r1, =@08005900
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08005900:
	.4byte @08005960
	.4byte @08005982
	.4byte @080059A6
	.4byte @080059C0
	.4byte @08005A0E
	.4byte @08005A12
	.4byte @08005A0A
	.4byte @08005A2A
	.4byte @08005A3A
	.4byte @08005A58
	.4byte @08005A5C
	.4byte @08005B5A
	.4byte @08005A90
	.4byte @08005A98
	.4byte @08005AA4
	.4byte @08005A76
	.4byte @08005AD8
	.4byte @08005AF2
	.4byte @08005B02
	.4byte @08005B26
	.4byte @08005B36
	.4byte @08005B3E
	.4byte @08005ABE
	.4byte @08005ACC
@08005960:
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
	b @08005A06
@08005982:
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
	b @08005A06
@080059A6:
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
	b @080059FE
@080059C0:
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
@080059FE:
	lsls r1, r2, 28
	lsrs r1, 28
	lsls r2, 24
	lsrs r2, 28
@08005A06:
	bl GenerateFontHalfRowLookupTable
@08005A0A:
	movs r0, 0x2
	b @08005D6E
@08005A0E:
	ldr r0, [r6]
	b @08005B30
@08005A12:
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
	b @08005B30
@08005A2A:
	ldr r0, [r6]
	ldrb r1, [r0]
	strb r1, [r6, 0x1E]
	adds r0, 0x1
	str r0, [r6]
	movs r0, 0x6
	strb r0, [r6, 0x1C]
	b @08005A0A
@08005A3A:
	movs r0, 0x1
	strb r0, [r6, 0x1C]
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne @08005A4C
	b @08005B56
@08005A4C:
	movs r0, 0
	strb r0, [r4, 0x2]
	b @08005B56
	.pool
@08005A58:
	movs r0, 0x5
	b @08005D56
@08005A5C:
	ldr r0, [r6]
	ldrb r3, [r0]
	adds r1, r0, 0x1
	str r1, [r6]
	ldrb r0, [r0, 0x1]
	lsls r0, 8
	orrs r3, r0
	adds r1, 0x1
	str r1, [r6]
	adds r0, r3, 0
	bl song_play_for_text
	b @08005A0A
@08005A76:
	ldr r0, [r6]
	ldrb r3, [r0]
	adds r1, r0, 0x1
	str r1, [r6]
	ldrb r0, [r0, 0x1]
	lsls r0, 8
	orrs r3, r0
	adds r1, 0x1
	str r1, [r6]
	adds r0, r3, 0
	bl audio_play
	b @08005A0A
@08005A90:
	ldr r1, [r6]
	ldrb r0, [r1]
	ldrb r3, [r6, 0x6]
	b @08005AF8
@08005A98:
	ldr r1, [r6]
	ldrb r0, [r1]
	ldrb r2, [r6, 0x7]
	adds r0, r2
	strb r0, [r6, 0x9]
	b @08005AFC
@08005AA4:
	ldrb r0, [r6, 0x4]
	ldrb r2, [r6, 0xD]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	bl FillWindowPixelBuffer
	ldrb r0, [r6, 0x6]
	strb r0, [r6, 0x8]
	ldrb r0, [r6, 0x7]
@08005ABA:
	strb r0, [r6, 0x9]
	b @08005A0A
@08005ABE:
	ldr r0, =0x03007420
	bl MPlayStop_rev01
	b @08005A0A
	.pool
@08005ACC:
	ldr r0, =0x03007420
	bl m4aMPlayContinue
	b @08005A0A
	.pool
@08005AD8:
	ldr r0, [r6]
	ldrb r4, [r0]
	adds r0, 0x1
	str r0, [r6]
	cmp r4, 0
	ble @08005A0A
	adds r0, r6, 0
	adds r1, r4, 0
	bl ClearTextSpan
	ldrb r0, [r6, 0x8]
	adds r0, r4
	b @08005C6E
@08005AF2:
	ldr r1, [r6]
	ldrb r0, [r6, 0x6]
	ldrb r3, [r1]
@08005AF8:
	adds r0, r3
	strb r0, [r6, 0x8]
@08005AFC:
	adds r1, 0x1
	str r1, [r6]
	b @08005A0A
@08005B02:
	ldr r0, [r6]
	ldrb r2, [r0]
	ldrb r1, [r6, 0x6]
	adds r2, r1
	adds r0, 0x1
	str r0, [r6]
	ldrb r0, [r6, 0x8]
	subs r4, r2, r0
	cmp r4, 0
	bgt @08005B18
	b @08005A0A
@08005B18:
	adds r0, r6, 0
	adds r1, r4, 0
	bl ClearTextSpan
	ldrb r0, [r6, 0x8]
	adds r0, r4
	b @08005C6E
@08005B26:
	ldr r0, [r6]
	ldrb r2, [r0]
	adds r1, r6, 0
	adds r1, 0x20
	strb r2, [r1]
@08005B30:
	adds r0, 0x1
	str r0, [r6]
	b @08005A0A
@08005B36:
	adds r1, r6, 0
	adds r1, 0x21
	movs r0, 0x1
	b @08005B44
@08005B3E:
	adds r1, r6, 0
	adds r1, 0x21
	movs r0, 0
@08005B44:
	strb r0, [r1]
	b @08005A0A
@08005B48:
	movs r0, 0x2
	b @08005B4E
@08005B4C:
	movs r0, 0x3
@08005B4E:
	strb r0, [r6, 0x1C]
	adds r0, r6, 0
	bl TextPrinterInitDownArrowCounters
@08005B56:
	movs r0, 0x3
	b @08005D6E
@08005B5A:
	ldr r0, [r6]
	ldrb r3, [r0]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	orrs r3, r1
	adds r0, 0x1
	str r0, [r6]
	b @08005B90
@08005B6C:
	ldr r0, [r6]
	ldrb r3, [r0]
	adds r0, 0x1
	str r0, [r6]
	ldrb r0, [r6, 0x4]
	adds r1, r3, 0
	ldrb r2, [r6, 0x8]
	ldrb r3, [r6, 0x9]
	bl DrawKeypadIcon
	ldr r1, =0x03002f90
	adds r1, 0x80
	strb r0, [r1]
	ldrb r3, [r6, 0xA]
	adds r0, r3
	b @08005C6A
	.pool
@08005B90:
	ldr r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	cmp r0, 0x8
	bhi @08005C10
	lsls r0, 2
	ldr r1, =@08005BA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08005BA8:
	.4byte @08005BCC
	.4byte @08005BDA
	.4byte @08005BE8
	.4byte @08005BE8
	.4byte @08005BE8
	.4byte @08005BE8
	.4byte @08005C10
	.4byte @08005BF6
	.4byte @08005C04
@08005BCC:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r1, [r0]
	adds r0, r3, 0
	bl DecompressGlyphFont0
	b @08005C10
@08005BDA:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r1, [r0]
	adds r0, r3, 0
	bl DecompressGlyphFont1
	b @08005C10
@08005BE8:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r1, [r0]
	adds r0, r3, 0
	bl DecompressGlyphFont2
	b @08005C10
@08005BF6:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r1, [r0]
	adds r0, r3, 0
	bl DecompressGlyphFont7
	b @08005C10
@08005C04:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r1, [r0]
	adds r0, r3, 0
	bl DecompressGlyphFont8
@08005C10:
	adds r0, r6, 0
	bl CopyGlyphToWindow
	adds r2, r6, 0
	adds r2, 0x20
	ldrb r0, [r2]
	cmp r0, 0
	beq @08005C48
	ldr r1, =0x03002f90
	adds r1, 0x80
	ldrb r0, [r1]
	ldrb r3, [r6, 0x8]
	adds r0, r3
	strb r0, [r6, 0x8]
	ldrb r2, [r2]
	ldrb r0, [r1]
	subs r4, r2, r0
	cmp r4, 0
	ble @08005C70
	adds r0, r6, 0
	adds r1, r4, 0
	bl ClearTextSpan
	ldrb r0, [r6, 0x8]
	adds r0, r4
	b @08005C6E
	.pool
@08005C48:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0
	beq @08005C64
	ldr r0, =0x03002f90
	adds r0, 0x80
	ldrb r1, [r6, 0xA]
	ldrb r0, [r0]
	adds r1, r0
	ldrb r0, [r6, 0x8]
	b @08005C6C
	.pool
@08005C64:
	ldr r0, =0x03002f90
	adds r0, 0x80
	ldrb r0, [r0]
@08005C6A:
	ldrb r1, [r6, 0x8]
@08005C6C:
	adds r0, r1
@08005C6E:
	strb r0, [r6, 0x8]
@08005C70:
	movs r0, 0
	b @08005D6E
	.pool
@08005C78:
	adds r0, r6, 0
	bl TextPrinterWait
	lsls r0, 16
	cmp r0, 0
	bne @08005C86
	b @08005B56
@08005C86:
	movs r0, 0
	strb r0, [r6, 0x1C]
	b @08005B56
@08005C8C:
	adds r0, r6, 0
	bl TextPrinterWaitWithDownArrow
	lsls r0, 16
	cmp r0, 0
	bne @08005C9A
	b @08005B56
@08005C9A:
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
	b @08005B56
@08005CB8:
	adds r0, r6, 0
	bl TextPrinterWaitWithDownArrow
	lsls r0, 16
	cmp r0, 0
	bne @08005CC6
	b @08005B56
@08005CC6:
	adds r0, r6, 0
	bl TextPrinterClearDownArrow
	ldrb r1, [r6, 0x5]
	ldr r0, =0x03002f80
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
	b @08005B56
	.pool
@08005CF0:
	ldrb r0, [r6, 0x1F]
	cmp r0, 0
	beq @08005D44
	bl sub_8197964
	ldr r1, =gWindowVerticalScrollSpeeds
	adds r0, r1
	ldrb r4, [r0]
	ldrb r2, [r6, 0x1F]
	cmp r2, r4
	bge @08005D20
	ldrb r0, [r6, 0x4]
	ldrb r1, [r6, 0xD]
	lsls r1, 28
	lsrs r3, r1, 4
	orrs r3, r1
	lsrs r3, 24
	movs r1, 0
	bl ScrollWindow
	movs r0, 0
	b @08005D38
	.pool
@08005D20:
	ldrb r0, [r6, 0x4]
	ldrb r1, [r6, 0xD]
	lsls r1, 28
	lsrs r3, r1, 4
	orrs r3, r1
	lsrs r3, 24
	movs r1, 0
	adds r2, r4, 0
	bl ScrollWindow
	ldrb r0, [r6, 0x1F]
	subs r0, r4
@08005D38:
	strb r0, [r6, 0x1F]
	ldrb r0, [r6, 0x4]
	movs r1, 0x2
	bl CopyWindowToVram
	b @08005B56
@08005D44:
	strb r0, [r6, 0x1C]
	b @08005B56
@08005D48:
	bl mplay_has_finished_maybe
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq @08005D56
	b @08005B56
@08005D56:
	strb r0, [r6, 0x1C]
	b @08005B56
@08005D5A:
	ldrb r0, [r6, 0x1E]
	adds r1, r0, 0
	cmp r1, 0
	beq @08005D68
	subs r0, 0x1
	strb r0, [r6, 0x1E]
	b @08005B56
@08005D68:
	strb r1, [r6, 0x1C]
	b @08005B56
@08005D6C:
	movs r0, 0x1
@08005D6E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end RenderText

	thumb_func_start GetStringWidthFixedWidthFont
; u32 GetStringWidthFixedWidthFont(u8 *str, u8 fontId, u8 letterSpacing)
GetStringWidthFixedWidthFont: ; 8005D74
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	movs r2, 0
	mov r1, sp
	adds r1, 0x7
@08005D8C:
	strb r2, [r1]
	subs r1, 0x1
	cmp r1, sp
	bge @08005D8C
	movs r5, 0
	movs r6, 0
	adds r4, r0, 0
	movs r2, 0
@08005D9C:
	adds r0, r4, r2
	ldrb r3, [r0]
	adds r2, 0x1
	adds r0, r3, 0
	subs r0, 0xF7
	cmp r0, 0x8
	bhi @08005E6A
	lsls r0, 2
	ldr r1, =@08005DB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08005DB8:
	.4byte @08005E64
	.4byte @08005E68
	.4byte @08005E68
	.4byte @08005E70
	.4byte @08005E70
	.4byte @08005DEC
	.4byte @08005E64
	.4byte @08005DDC
	.4byte @08005DDC
@08005DDC:
	mov r1, sp
	adds r0, r1, r6
	strb r5, [r0]
	movs r5, 0
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	b @08005E70
@08005DEC:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r2, 0x1
	subs r0, 0x1
	cmp r0, 0x15
	bhi @08005E70
	lsls r0, 2
	ldr r1, =@08005E08
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08005E08:
	.4byte @08005E64
	.4byte @08005E64
	.4byte @08005E64
	.4byte @08005E60
	.4byte @08005E64
	.4byte @08005E64
	.4byte @08005E70
	.4byte @08005E64
	.4byte @08005E70
	.4byte @08005E70
	.4byte @08005E62
	.4byte @08005E64
	.4byte @08005E64
	.4byte @08005E64
	.4byte @08005E70
	.4byte @08005E62
	.4byte @08005E64
	.4byte @08005E64
	.4byte @08005E64
	.4byte @08005E64
	.4byte @08005E70
	.4byte @08005E70
@08005E60:
	adds r2, 0x1
@08005E62:
	adds r2, 0x1
@08005E64:
	adds r2, 0x1
	b @08005E70
@08005E68:
	adds r2, 0x1
@08005E6A:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
@08005E70:
	cmp r3, 0xFF
	bne @08005D9C
	movs r5, 0
	movs r2, 0
@08005E78:
	mov r1, sp
	adds r0, r1, r2
	ldrb r1, [r0]
	cmp r5, r1
	bcs @08005E84
	ldrb r5, [r0]
@08005E84:
	adds r2, 0x1
	cmp r2, 0x7
	ble @08005E78
	adds r0, r7, 0
	movs r1, 0
	bl GetFontAttribute
	add r0, r8
	lsls r0, 24
	lsrs r0, 24
	muls r0, r5
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GetStringWidthFixedWidthFont

	thumb_func_start GetFontWidthFunc
; u8 GetFontWidthFunc(u16 glyphId)
GetFontWidthFunc: ; 8005EA8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r0, =gGlyphWidthFuncs
	adds r2, r0, 0x4
	adds r1, r0, 0
@08005EB6:
	ldr r0, [r1]
	cmp r4, r0
	bne @08005EC4
	ldr r0, [r2]
	b @08005ED0
	.pool
@08005EC4:
	adds r2, 0x8
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x8
	bls @08005EB6
	movs r0, 0
@08005ED0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetFontWidthFunc

	thumb_func_start GetStringWidth
; u32 GetStringWidth(u8 fontId, u8 *str, u16 letterSpacing)
GetStringWidth: ; 8005ED8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r4, r1, 0
	lsls r0, 24
	lsrs r0, 24
	adds r6, r0, 0
	lsls r2, 16
	lsrs r5, r2, 16
	movs r0, 0
	mov r9, r0
	movs r7, 0
	adds r0, r6, 0
	bl GetFontWidthFunc
	mov r8, r0
	cmp r0, 0
	bne @08005F06
@08005F02:
	movs r0, 0
	b @0800612E
@08005F06:
	lsls r0, r5, 16
	asrs r2, r0, 16
	movs r1, 0x1
	negs r1, r1
	str r0, [sp, 0x4]
	cmp r2, r1
	bne @08005F24
	adds r0, r6, 0
	movs r1, 0x2
	bl GetFontAttribute
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	b @08005F26
@08005F24:
	mov r10, r2
@08005F26:
	movs r2, 0
	str r2, [sp]
	movs r5, 0
	movs r6, 0
	b @0800611E
@08005F30:
	ldrb r1, [r4]
	adds r0, r1, 0
	subs r0, 0xF7
	cmp r0, 0x7
	bls @08005F3C
	b @080060F8
@08005F3C:
	lsls r0, 2
	ldr r1, =@08005F4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08005F4C:
	.4byte @08005FA2
	.4byte @080060BC
	.4byte @080060BC
	.4byte @0800611C
	.4byte @0800611C
	.4byte @08005FEA
	.4byte @08005F78
	.4byte @08005F6C
@08005F6C:
	ldr r0, [sp]
	cmp r5, r0
	bls @08005F74
	str r5, [sp]
@08005F74:
	movs r5, 0
	b @0800611C
@08005F78:
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, 0x3
	beq @08005F98
	cmp r0, 0x3
	bgt @08005F8A
	cmp r0, 0x2
	beq @08005F90
	b @08005F02
@08005F8A:
	cmp r0, 0x4
	beq @08005FA0
	b @08005F02
@08005F90:
	ldr r6, =0x02021cc4
	b @08005FA2
	.pool
@08005F98:
	ldr r6, =0x02021dc4
	b @08005FA2
	.pool
@08005FA0:
	ldr r6, =0x02021ec4
@08005FA2:
	cmp r6, 0
	bne @08005FE0
	adds r4, 0x1
	ldrb r0, [r4]
	bl sub_81AFC74
	adds r6, r0, 0
	b @08005FE0
	.pool
@08005FB8:
	ldrb r0, [r6]
	adds r6, 0x1
	mov r1, r9
	bl _call_via_r8
	cmp r7, 0
	ble @08005FD0
	cmp r0, r7
	bge @08005FCC
	adds r0, r7, 0
@08005FCC:
	adds r5, r0
	b @08005FE0
@08005FD0:
	adds r5, r0
	mov r2, r9
	cmp r2, 0
	beq @08005FE0
	ldrb r0, [r4, 0x1]
	cmp r0, 0xFF
	beq @08005FE0
	add r5, r10
@08005FE0:
	ldrb r0, [r6]
	cmp r0, 0xFF
	bne @08005FB8
	movs r6, 0
	b @0800611C
@08005FEA:
	adds r4, 0x1
	ldrb r0, [r4]
	subs r0, 0x1
	cmp r0, 0x15
	bls @08005FF6
	b @0800611C
@08005FF6:
	lsls r0, 2
	ldr r1, =@08006004
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08006004:
	.4byte @08006060
	.4byte @08006060
	.4byte @08006060
	.4byte @0800605C
	.4byte @08006060
	.4byte @08006064
	.4byte @0800611C
	.4byte @08006060
	.4byte @0800611C
	.4byte @0800611C
	.4byte @0800605E
	.4byte @08006060
	.4byte @08006060
	.4byte @08006060
	.4byte @0800611C
	.4byte @0800605E
	.4byte @08006090
	.4byte @08006098
	.4byte @0800609E
	.4byte @080060AA
	.4byte @080060B0
	.4byte @080060B6
@0800605C:
	adds r4, 0x1
@0800605E:
	adds r4, 0x1
@08006060:
	adds r4, 0x1
	b @0800611C
@08006064:
	adds r4, 0x1
	ldrb r0, [r4]
	bl GetFontWidthFunc
	mov r8, r0
	cmp r0, 0
	bne @08006074
	b @08005F02
@08006074:
	ldr r0, [sp, 0x4]
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne @0800611C
	ldrb r0, [r4]
	movs r1, 0x2
	bl GetFontAttribute
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	b @0800611C
@08006090:
	adds r4, 0x1
	ldrb r0, [r4]
@08006094:
	adds r5, r0
	b @0800611C
@08006098:
	adds r4, 0x1
	ldrb r5, [r4]
	b @0800611C
@0800609E:
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, r5
	bls @0800611C
	adds r5, r0, 0
	b @0800611C
@080060AA:
	adds r4, 0x1
	ldrb r7, [r4]
	b @0800611C
@080060B0:
	movs r2, 0x1
	mov r9, r2
	b @0800611C
@080060B6:
	movs r0, 0
	mov r9, r0
	b @0800611C
@080060BC:
	ldrb r0, [r4]
	cmp r0, 0xF9
	bne @080060D6
	adds r4, 0x1
	ldrb r0, [r4]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	orrs r0, r1
	mov r1, r9
	bl _call_via_r8
	b @080060E2
@080060D6:
	adds r4, 0x1
	ldrb r0, [r4]
	bl GetKeypadIconWidth
	lsls r0, 24
	lsrs r0, 24
@080060E2:
	cmp r7, 0
	ble @080060EE
	cmp r0, r7
	bge @08006094
	adds r0, r7, 0
	b @08006094
@080060EE:
	adds r5, r0
	mov r0, r9
	cmp r0, 0
	beq @0800611C
	b @08006114
@080060F8:
	adds r0, r1, 0
	mov r1, r9
	bl _call_via_r8
	cmp r7, 0
	ble @0800610C
	cmp r0, r7
	bge @08006094
	adds r0, r7, 0
	b @08006094
@0800610C:
	adds r5, r0
	mov r2, r9
	cmp r2, 0
	beq @0800611C
@08006114:
	ldrb r0, [r4, 0x1]
	cmp r0, 0xFF
	beq @0800611C
	add r5, r10
@0800611C:
	adds r4, 0x1
@0800611E:
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq @08006126
	b @08005F30
@08006126:
	ldr r0, [sp]
	cmp r5, r0
	bls @0800612E
	adds r0, r5, 0
@0800612E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GetStringWidth

	thumb_func_start RenderTextFont9
; u8 RenderTextFont9(u8 *pixels, u8 fontId, u8 *str)
RenderTextFont9: ; 8006140
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r9, r0
	adds r6, r2, 0
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x4]
	mov r4, sp
	adds r4, 0x1
	mov r5, sp
	adds r5, 0x2
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	bl SaveTextColors
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x3
	mov r10, r0
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x3
	bl GenerateFontHalfRowLookupTable
	adds r7, r6, 0
	movs r6, 0
@08006182:
	adds r0, r7, r6
	ldrb r0, [r0]
	mov r8, r0
	adds r6, 0x1
	subs r0, 0xF7
	cmp r0, 0x8
	bhi @0800627E
	lsls r0, 2
	ldr r1, =@080061A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@080061A0:
	.4byte @08006276
	.4byte @08006276
	.4byte @08006276
	.4byte @080062B8
	.4byte @080062B8
	.4byte @080061C4
	.4byte @08006276
	.4byte @080062B8
	.4byte @080062B8
@080061C4:
	adds r0, r7, r6
	ldrb r0, [r0]
	adds r6, 0x1
	subs r0, 0x1
	cmp r0, 0x15
	bhi @080062B8
	lsls r0, 2
	ldr r1, =@080061E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@080061E0:
	.4byte @0800624A
	.4byte @08006254
	.4byte @0800625C
	.4byte @08006238
	.4byte @08006276
	.4byte @08006270
	.4byte @080062B8
	.4byte @08006276
	.4byte @080062B8
	.4byte @080062B8
	.4byte @0800627A
	.4byte @08006276
	.4byte @08006276
	.4byte @08006276
	.4byte @080062B8
	.4byte @0800627A
	.4byte @08006276
	.4byte @08006276
	.4byte @08006276
	.4byte @08006276
	.4byte @080062B8
	.4byte @080062B8
@08006238:
	adds r0, r7, r6
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	adds r6, 0x1
	adds r0, r7, r6
	ldrb r0, [r0]
	str r0, [sp, 0xC]
	adds r6, 0x1
	b @0800625C
@0800624A:
	adds r0, r7, r6
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	adds r6, 0x1
	b @08006266
@08006254:
	adds r0, r7, r6
	ldrb r0, [r0]
	str r0, [sp, 0xC]
	b @08006262
@0800625C:
	adds r0, r7, r6
	ldrb r0, [r0]
	mov r10, r0
@08006262:
	adds r6, 0x1
	ldr r0, [sp, 0x8]
@08006266:
	ldr r1, [sp, 0xC]
	mov r2, r10
	bl GenerateFontHalfRowLookupTable
	b @080062B8
@08006270:
	adds r0, r7, r6
	ldrb r0, [r0]
	str r0, [sp, 0x4]
@08006276:
	adds r6, 0x1
	b @080062B8
@0800627A:
	adds r6, 0x1
	b @08006276
@0800627E:
	ldr r0, [sp, 0x4]
	cmp r0, 0x1
	beq @08006290
	cmp r0, 0x9
	bne @08006290
	mov r0, r8
	bl DecompressGlyphFont9
	b @08006298
@08006290:
	mov r0, r8
	movs r1, 0x1
	bl DecompressGlyphFont1
@08006298:
	ldr r4, =0x03002f90
	ldr r5, =0x04000008
	adds r0, r4, 0
	mov r1, r9
	adds r2, r5, 0
	bl CpuSet
	adds r4, 0x40
	mov r1, r9
	adds r1, 0x20
	adds r0, r4, 0
	adds r2, r5, 0
	bl CpuSet
	movs r0, 0x40
	add r9, r0
@080062B8:
	mov r0, r8
	cmp r0, 0xFF
	beq @080062C0
	b @08006182
@080062C0:
	mov r0, sp
	mov r1, sp
	adds r1, 0x1
	mov r2, sp
	adds r2, 0x2
	bl RestoreTextColors
	movs r0, 0x1
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end RenderTextFont9

	thumb_func_start DrawKeypadIcon
; u8 DrawKeypadIcon(u8 windowId, u8 keypadIconId, u16 x, u16 y)
DrawKeypadIcon: ; 80062E8
	push {r4,r5,lr}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	ldr r4, =gKeypadIcons
	lsrs r1, 22
	adds r1, r4
	ldrh r5, [r1]
	lsls r5, 5
	ldr r4, =gKeypadIconTiles
	adds r5, r4
	movs r4, 0x80
	str r4, [sp]
	str r4, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	ldrb r4, [r1, 0x2]
	str r4, [sp, 0x10]
	ldrb r1, [r1, 0x3]
	str r1, [sp, 0x14]
	adds r1, r5, 0
	movs r2, 0
	movs r3, 0
	bl BlitBitmapRectToWindow
	adds r0, r4, 0
	add sp, 0x18
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end DrawKeypadIcon

	thumb_func_start GetKeypadIconTileOffset
; u8 GetKeypadIconTileOffset(u8 keypadIconId)
GetKeypadIconTileOffset: ; 8006338
	lsls r0, 24
	ldr r1, =gKeypadIcons
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end GetKeypadIconTileOffset

	thumb_func_start GetKeypadIconWidth
; u8 GetKeypadIconWidth(u8 keypadIconId)
GetKeypadIconWidth: ; 8006348
	lsls r0, 24
	ldr r1, =gKeypadIcons
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0, 0x2]
	bx lr
	.pool
	thumb_func_end GetKeypadIconWidth

	thumb_func_start GetKeypadIconHeight
; u8 GetKeypadIconHeight(u8 keypadIconId)
GetKeypadIconHeight: ; 8006358
	lsls r0, 24
	ldr r1, =gKeypadIcons
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0, 0x3]
	bx lr
	.pool
	thumb_func_end GetKeypadIconHeight

	thumb_func_start SetDefaultFontsPointer
; void SetDefaultFontsPointer()
SetDefaultFontsPointer: ; 8006368
	push {lr}
	ldr r0, =gFontInfos
	bl SetFontsPointer
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetDefaultFontsPointer

	thumb_func_start GetFontAttribute
; u8 GetFontAttribute(u8 fontId, u8 attributeId)
GetFontAttribute: ; 8006378
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	cmp r1, 0x7
	bhi @08006456
	lsls r0, r1, 2
	ldr r1, =@08006398
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08006398:
	.4byte @080063B8
	.4byte @080063CC
	.4byte @080063E0
	.4byte @080063F4
	.4byte @08006408
	.4byte @0800641C
	.4byte @08006430
	.4byte @08006448
@080063B8:
	ldr r1, =gFontInfos
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x4]
	b @08006456
	.pool
@080063CC:
	ldr r1, =gFontInfos
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x5]
	b @08006456
	.pool
@080063E0:
	ldr r1, =gFontInfos
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x6]
	b @08006456
	.pool
@080063F4:
	ldr r1, =gFontInfos
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x7]
	b @08006456
	.pool
@08006408:
	ldr r0, =gFontInfos
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x8]
	b @0800643C
	.pool
@0800641C:
	ldr r0, =gFontInfos
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x8]
	b @08006454
	.pool
@08006430:
	ldr r0, =gFontInfos
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x9]
@0800643C:
	lsls r0, 28
	lsrs r0, 28
	b @08006456
	.pool
@08006448:
	ldr r0, =gFontInfos
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x9]
@08006454:
	lsrs r0, 4
@08006456:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetFontAttribute

	thumb_func_start GetMenuCursorDimensionByFont
; u8 GetMenuCursorDimensionByFont(u8 fontId, u8 whichDimension)
GetMenuCursorDimensionByFont: ; 8006460
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gMenuCursorDimensions
	lsrs r0, 23
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	bx lr
	.pool
	thumb_func_end GetMenuCursorDimensionByFont

	thumb_func_start DecompressGlyphFont0
; void DecompressGlyphFont0(u16 glyphId, BOOL isJapanese)
DecompressGlyphFont0: ; 8006478
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r1, 0x1
	bne @080064C4
	lsrs r2, r0, 20
	lsls r2, 9
	movs r0, 0xF
	ands r0, r3
	lsls r0, 4
	ldr r1, =gFont0JapaneseGlyphs
	adds r0, r1
	adds r5, r2, r0
	ldr r4, =0x03002f90
	adds r0, r5, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	movs r1, 0x80
	lsls r1, 1
	adds r0, r5, r1
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x8
	strb r0, [r1]
	adds r4, 0x81
	movs r0, 0xC
	strb r0, [r4]
	b @08006534
	.pool
@080064C4:
	lsls r1, r3, 6
	ldr r0, =gFont0LatinGlyphs
	adds r5, r1, r0
	ldr r4, =0x03002f90
	ldr r0, =gFont0LatinGlyphWidths
	adds r0, r3, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	adds r0, 0x80
	strb r1, [r0]
	cmp r1, 0x8
	bhi @08006500
	adds r0, r5, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	b @0800652C
	.pool
@08006500:
	adds r0, r5, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x10
	adds r1, r4, 0
	adds r1, 0x20
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x30
	adds r1, r4, 0
	adds r1, 0x60
	bl DecompressGlyphTile
@0800652C:
	ldr r0, =0x03002f90
	adds r0, 0x81
	movs r1, 0xD
	strb r1, [r0]
@08006534:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressGlyphFont0

	thumb_func_start GetGlyphWidthFont0
; u8 GetGlyphWidthFont0(u16 glyphId, BOOL isJapanese)
GetGlyphWidthFont0: ; 8006540
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, 0x1
	beq @08006558
	ldr r0, =gFont0LatinGlyphWidths
	adds r0, r2, r0
	ldrb r0, [r0]
	b @0800655A
	.pool
@08006558:
	movs r0, 0x8
@0800655A:
	pop {r1}
	bx r1
	thumb_func_end GetGlyphWidthFont0

	thumb_func_start DecompressGlyphFont7
; void DecompressGlyphFont7(u16 glyphId, BOOL isJapanese)
DecompressGlyphFont7: ; 8006560
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r1, 0x1
	bne @080065AC
	lsrs r2, r0, 20
	lsls r2, 9
	movs r5, 0xF
	adds r0, r3, 0
	ands r0, r5
	lsls r0, 4
	ldr r1, =gFont1JapaneseGlyphs
	adds r0, r1
	adds r6, r2, r0
	ldr r4, =0x03002f90
	adds r0, r6, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	movs r1, 0x80
	lsls r1, 1
	adds r0, r6, r1
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x8
	strb r0, [r1]
	adds r4, 0x81
	strb r5, [r4]
	b @0800661C
	.pool
@080065AC:
	lsls r1, r3, 6
	ldr r0, =gFont7LatinGlyphs
	adds r6, r1, r0
	ldr r4, =0x03002f90
	ldr r0, =gFont7LatinGlyphWidths
	adds r0, r3, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	adds r0, 0x80
	strb r1, [r0]
	cmp r1, 0x8
	bhi @080065E8
	adds r0, r6, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r6, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	b @08006614
	.pool
@080065E8:
	adds r0, r6, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r6, 0
	adds r0, 0x10
	adds r1, r4, 0
	adds r1, 0x20
	bl DecompressGlyphTile
	adds r0, r6, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	adds r0, r6, 0
	adds r0, 0x30
	adds r1, r4, 0
	adds r1, 0x60
	bl DecompressGlyphTile
@08006614:
	ldr r0, =0x03002f90
	adds r0, 0x81
	movs r1, 0xF
	strb r1, [r0]
@0800661C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressGlyphFont7

	thumb_func_start GetGlyphWidthFont7
; u8 GetGlyphWidthFont7(u16 glyphId, BOOL isJapanese)
GetGlyphWidthFont7: ; 8006628
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, 0x1
	beq @08006640
	ldr r0, =gFont7LatinGlyphWidths
	adds r0, r2, r0
	ldrb r0, [r0]
	b @08006642
	.pool
@08006640:
	movs r0, 0x8
@08006642:
	pop {r1}
	bx r1
	thumb_func_end GetGlyphWidthFont7

	thumb_func_start DecompressGlyphFont8
; void DecompressGlyphFont8(u16 glyphId, BOOL isJapanese)
DecompressGlyphFont8: ; 8006648
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r1, 0x1
	bne @08006694
	lsrs r2, r0, 20
	lsls r2, 9
	movs r0, 0xF
	ands r0, r3
	lsls r0, 4
	ldr r1, =gFont0JapaneseGlyphs
	adds r0, r1
	adds r5, r2, r0
	ldr r4, =0x03002f90
	adds r0, r5, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	movs r1, 0x80
	lsls r1, 1
	adds r0, r5, r1
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x8
	strb r0, [r1]
	adds r4, 0x81
	movs r0, 0xC
	strb r0, [r4]
	b @08006704
	.pool
@08006694:
	lsls r1, r3, 6
	ldr r0, =gFont8LatinGlyphs
	adds r5, r1, r0
	ldr r4, =0x03002f90
	ldr r0, =gFont8LatinGlyphWidths
	adds r0, r3, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	adds r0, 0x80
	strb r1, [r0]
	cmp r1, 0x8
	bhi @080066D0
	adds r0, r5, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	b @080066FC
	.pool
@080066D0:
	adds r0, r5, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x10
	adds r1, r4, 0
	adds r1, 0x20
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x30
	adds r1, r4, 0
	adds r1, 0x60
	bl DecompressGlyphTile
@080066FC:
	ldr r0, =0x03002f90
	adds r0, 0x81
	movs r1, 0xC
	strb r1, [r0]
@08006704:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressGlyphFont8

	thumb_func_start GetGlyphWidthFont8
; u8 GetGlyphWidthFont8(u16 glyphId, BOOL isJapanese)
GetGlyphWidthFont8: ; 8006710
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, 0x1
	beq @08006728
	ldr r0, =gFont8LatinGlyphWidths
	adds r0, r2, r0
	ldrb r0, [r0]
	b @0800672A
	.pool
@08006728:
	movs r0, 0x8
@0800672A:
	pop {r1}
	bx r1
	thumb_func_end GetGlyphWidthFont8

	thumb_func_start DecompressGlyphFont2
; void DecompressGlyphFont2(u16 glyphId, BOOL isJapanese)
DecompressGlyphFont2: ; 8006730
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r1, 0x1
	bne @080067A0
	lsrs r2, r0, 19
	lsls r2, 9
	movs r0, 0x7
	ands r0, r6
	lsls r0, 5
	ldr r1, =gFont2JapaneseGlyphs
	adds r0, r1
	adds r4, r2, r0
	ldr r5, =0x03002f90
	adds r0, r4, 0
	adds r1, r5, 0
	bl DecompressGlyphTile
	adds r0, r4, 0
	adds r0, 0x10
	adds r1, r5, 0
	adds r1, 0x20
	bl DecompressGlyphTile
	movs r1, 0x80
	lsls r1, 1
	adds r0, r4, r1
	adds r1, r5, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	movs r1, 0x88
	lsls r1, 1
	adds r0, r4, r1
	adds r1, r5, 0
	adds r1, 0x60
	bl DecompressGlyphTile
	ldr r0, =gFont2JapaneseGlyphWidths
	adds r0, r6, r0
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x80
	strb r1, [r0]
	adds r1, r5, 0
	adds r1, 0x81
	movs r0, 0xE
	strb r0, [r1]
	b @08006810
	.pool
@080067A0:
	lsls r1, r6, 6
	ldr r0, =gFont2LatinGlyphs
	adds r4, r1, r0
	ldr r5, =0x03002f90
	ldr r0, =gFont2LatinGlyphWidths
	adds r0, r6, r0
	ldrb r1, [r0]
	adds r0, r5, 0
	adds r0, 0x80
	strb r1, [r0]
	cmp r1, 0x8
	bhi @080067DC
	adds r0, r4, 0
	adds r1, r5, 0
	bl DecompressGlyphTile
	adds r0, r4, 0
	adds r0, 0x20
	adds r1, r5, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	b @08006808
	.pool
@080067DC:
	adds r0, r4, 0
	adds r1, r5, 0
	bl DecompressGlyphTile
	adds r0, r4, 0
	adds r0, 0x10
	adds r1, r5, 0
	adds r1, 0x20
	bl DecompressGlyphTile
	adds r0, r4, 0
	adds r0, 0x20
	adds r1, r5, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	adds r0, r4, 0
	adds r0, 0x30
	adds r1, r5, 0
	adds r1, 0x60
	bl DecompressGlyphTile
@08006808:
	ldr r0, =0x03002f90
	adds r0, 0x81
	movs r1, 0xE
	strb r1, [r0]
@08006810:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressGlyphFont2

	thumb_func_start GetGlyphWidthFont2
; u8 GetGlyphWidthFont2(u16 glyphId, BOOL isJapanese)
GetGlyphWidthFont2: ; 800681C
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, 0x1
	beq @08006830
	ldr r0, =gFont2LatinGlyphWidths
	b @08006832
	.pool
@08006830:
	ldr r0, =gFont2JapaneseGlyphWidths
@08006832:
	adds r0, r2, r0
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetGlyphWidthFont2

	thumb_func_start DecompressGlyphFont1
; void DecompressGlyphFont1(u16 glyphId, BOOL isJapanese)
DecompressGlyphFont1: ; 8006840
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r1, 0x1
	bne @0800688C
	lsrs r2, r0, 20
	lsls r2, 9
	movs r5, 0xF
	adds r0, r3, 0
	ands r0, r5
	lsls r0, 4
	ldr r1, =gFont1JapaneseGlyphs
	adds r0, r1
	adds r6, r2, r0
	ldr r4, =0x03002f90
	adds r0, r6, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	movs r1, 0x80
	lsls r1, 1
	adds r0, r6, r1
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	adds r1, r4, 0
	adds r1, 0x80
	movs r0, 0x8
	strb r0, [r1]
	adds r4, 0x81
	strb r5, [r4]
	b @080068FC
	.pool
@0800688C:
	lsls r1, r3, 6
	ldr r0, =gFont1LatinGlyphs
	adds r6, r1, r0
	ldr r4, =0x03002f90
	ldr r0, =gFont1LatinGlyphWidths
	adds r0, r3, r0
	ldrb r1, [r0]
	adds r0, r4, 0
	adds r0, 0x80
	strb r1, [r0]
	cmp r1, 0x8
	bhi @080068C8
	adds r0, r6, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r6, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	b @080068F4
	.pool
@080068C8:
	adds r0, r6, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r6, 0
	adds r0, 0x10
	adds r1, r4, 0
	adds r1, 0x20
	bl DecompressGlyphTile
	adds r0, r6, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	adds r0, r6, 0
	adds r0, 0x30
	adds r1, r4, 0
	adds r1, 0x60
	bl DecompressGlyphTile
@080068F4:
	ldr r0, =0x03002f90
	adds r0, 0x81
	movs r1, 0xF
	strb r1, [r0]
@080068FC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressGlyphFont1

	thumb_func_start GetGlyphWidthFont1
; u8 GetGlyphWidthFont1(u16 glyphId, BOOL isJapanese)
GetGlyphWidthFont1: ; 8006908
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, 0x1
	beq @08006920
	ldr r0, =gFont1LatinGlyphWidths
	adds r0, r2, r0
	ldrb r0, [r0]
	b @08006922
	.pool
@08006920:
	movs r0, 0x8
@08006922:
	pop {r1}
	bx r1
	thumb_func_end GetGlyphWidthFont1

	thumb_func_start DecompressGlyphFont9
; void DecompressGlyphFont9(u16 glyphId)
DecompressGlyphFont9: ; 8006928
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 20
	lsls r4, 9
	movs r1, 0xF0
	lsls r1, 12
	ands r1, r0
	lsrs r1, 12
	ldr r0, =gFont9JapaneseGlyphs
	adds r1, r0
	adds r4, r1
	ldr r5, =0x03002f90
	adds r0, r4, 0
	adds r1, r5, 0
	bl DecompressGlyphTile
	movs r0, 0x80
	lsls r0, 1
	adds r4, r0
	adds r1, r5, 0
	adds r1, 0x40
	adds r0, r4, 0
	bl DecompressGlyphTile
	adds r1, r5, 0
	adds r1, 0x80
	movs r0, 0x8
	strb r0, [r1]
	adds r5, 0x81
	movs r0, 0xC
	strb r0, [r5]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DecompressGlyphFont9
