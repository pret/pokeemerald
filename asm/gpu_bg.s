	thumb_func_start ResetBgs
; void ResetBgs()
ResetBgs: ; 80012F0
	push {lr}
	bl ResetWramBgControlStructs
	ldr r1, =0x030008e0
	movs r0, 0
	strh r0, [r1, 0x10]
	bl SetTextModeAndHideBgs
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetBgs

	thumb_func_start SetBgModeInternal
; void SetBgModeInternal(u8 bgMode)
SetBgModeInternal: ; 8001308
	lsls r0, 24
	lsrs r0, 24
	ldr r3, =0x030008e0
	ldrh r2, [r3, 0x10]
	ldr r1, =0x0000fff8
	ands r1, r2
	orrs r1, r0
	strh r1, [r3, 0x10]
	bx lr
	.pool
	thumb_func_end SetBgModeInternal

	thumb_func_start GetBgMode
; u8 GetBgMode()
GetBgMode: ; 8001324
	ldr r0, =0x030008e0
	ldrb r1, [r0, 0x10]
	movs r0, 0x7
	ands r0, r1
	bx lr
	.pool
	thumb_func_end GetBgMode

	thumb_func_start ResetWramBgControlStructs
; void ResetWramBgControlStructs()
ResetWramBgControlStructs: ; 8001334
	push {lr}
	ldr r2, =0x030008e0
	ldr r0, =gBgConfigZeroValue
	ldr r0, [r0]
	adds r1, r2, 0
	adds r1, 0xC
@08001340:
	str r0, [r1]
	subs r1, 0x4
	cmp r1, r2
	bge @08001340
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetWramBgControlStructs

	thumb_func_start Unused_ResetWramBgControlStruct
; void Unused_ResetWramBgControlStruct(u8 bg)
Unused_ResetWramBgControlStruct: ; 8001354
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl IsInvalidBg
	lsls r0, 24
	cmp r0, 0
	bne @08001372
	ldr r1, =0x030008e0
	lsls r0, r4, 2
	adds r0, r1
	ldr r1, =gBgConfigZeroValue
	ldr r1, [r1]
	str r1, [r0]
@08001372:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Unused_ResetWramBgControlStruct

	thumb_func_start SetBgControlAttributes
; void SetBgControlAttributes(u8 bg, u8 tilesBaseBlock, u8 tileMapBaseBlock, u8 screenSize, u8 paletteMode, u8 priority, u8 mosaic, u8 wraparound)
SetBgControlAttributes: ; 8001380
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	ldr r4, [sp, 0x30]
	ldr r5, [sp, 0x34]
	ldr r6, [sp, 0x38]
	mov r12, r6
	ldr r6, [sp, 0x3C]
	mov r8, r6
	lsls r0, 24
	lsrs r7, r0, 24
	str r7, [sp]
	lsls r1, 24
	lsrs r1, 24
	mov r10, r1
	lsls r2, 24
	lsrs r6, r2, 24
	lsls r3, 24
	lsrs r3, 24
	mov r9, r3
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x4]
	lsls r5, 24
	lsrs r5, 24
	mov r0, r12
	lsls r0, 24
	lsrs r4, r0, 24
	mov r1, r8
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0xC]
	adds r0, r7, 0
	bl IsInvalidBg
	lsls r0, 24
	lsrs r0, 24
	mov r12, r0
	cmp r0, 0
	bne @08001498
	ldr r2, =0x030008e0
	mov r8, r2
	mov r0, r10
	cmp r0, 0xFF
	beq @080013F4
	lsls r2, r7, 2
	add r2, r8
	movs r1, 0x3
	ands r1, r0
	ldrb r3, [r2, 0x1]
	movs r0, 0x4
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0x1]
@080013F4:
	cmp r6, 0xFF
	beq @0800140C
	lsls r1, r7, 2
	add r1, r8
	movs r0, 0x1F
	ands r6, r0
	lsls r3, r6, 2
	ldrb r2, [r1, 0x1]
	subs r0, 0x9C
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x1]
@0800140C:
	mov r1, r9
	cmp r1, 0xFF
	beq @08001428
	lsls r1, r7, 2
	add r1, r8
	movs r0, 0x3
	mov r2, r9
	ands r2, r0
	lsls r3, r2, 2
	ldrb r2, [r1]
	subs r0, 0x10
	ands r0, r2
	orrs r0, r3
	strb r0, [r1]
@08001428:
	ldr r6, [sp, 0x4]
	cmp r6, 0xFF
	beq @0800143E
	lsls r1, r7, 2
	add r1, r8
	lsls r3, r6, 7
	ldrb r2, [r1, 0x1]
	movs r0, 0x7F
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, 0x1]
@0800143E:
	cmp r5, 0xFF
	beq @08001456
	lsls r1, r7, 2
	add r1, r8
	movs r0, 0x3
	ands r5, r0
	lsls r3, r5, 4
	ldrb r2, [r1]
	subs r0, 0x34
	ands r0, r2
	orrs r0, r3
	strb r0, [r1]
@08001456:
	cmp r4, 0xFF
	beq @0800146E
	lsls r1, r7, 2
	add r1, r8
	movs r0, 0x1
	ands r4, r0
	lsls r3, r4, 6
	ldrb r2, [r1]
	subs r0, 0x42
	ands r0, r2
	orrs r0, r3
	strb r0, [r1]
@0800146E:
	ldr r0, [sp, 0xC]
	cmp r0, 0xFF
	beq @08001484
	lsls r1, r7, 2
	add r1, r8
	lsls r3, r0, 7
	ldrb r2, [r1]
	movs r0, 0x7F
	ands r0, r2
	orrs r0, r3
	strb r0, [r1]
@08001484:
	ldr r1, [sp]
	lsls r0, r1, 2
	add r0, r8
	mov r2, r12
	strb r2, [r0, 0x2]
	strb r2, [r0, 0x3]
	ldrb r1, [r0]
	movs r2, 0x1
	orrs r1, r2
	strb r1, [r0]
@08001498:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBgControlAttributes

	thumb_func_start GetBgControlAttribute
; u8 GetBgControlAttribute(u8 bg, u8 attributeId)
GetBgControlAttribute: ; 80014AC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	adds r0, r4, 0
	bl IsInvalidBg
	lsls r0, 24
	cmp r0, 0
	bne @08001558
	ldr r1, =0x030008e0
	lsls r2, r4, 2
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, 31
	adds r3, r1, 0
	cmp r0, 0
	beq @08001558
	subs r0, r5, 0x1
	cmp r0, 0x7
	bhi @08001558
	lsls r0, 2
	ldr r1, =@080014EC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@080014EC:
	.4byte @0800150C
	.4byte @08001516
	.4byte @08001520
	.4byte @0800152A
	.4byte @08001534
	.4byte @0800153C
	.4byte @08001546
	.4byte @08001550
@0800150C:
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 31
	lsrs r0, 31
	b @0800155A
@08001516:
	adds r0, r2, r3
	ldrb r0, [r0, 0x1]
	lsls r0, 30
	lsrs r0, 30
	b @0800155A
@08001520:
	adds r0, r2, r3
	ldrb r0, [r0, 0x1]
	lsls r0, 25
	lsrs r0, 27
	b @0800155A
@0800152A:
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 28
	lsrs r0, 30
	b @0800155A
@08001534:
	adds r0, r2, r3
	ldrb r0, [r0, 0x1]
	lsrs r0, 7
	b @0800155A
@0800153C:
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 26
	lsrs r0, 30
	b @0800155A
@08001546:
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, 25
	lsrs r0, 31
	b @0800155A
@08001550:
	adds r0, r2, r3
	ldrb r0, [r0]
	lsrs r0, 7
	b @0800155A
@08001558:
	movs r0, 0xFF
@0800155A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetBgControlAttribute

	thumb_func_start LoadBgVram
; u8 LoadBgVram(u8, void *src, u16 size, u16 destOffset, u8 mode)
LoadBgVram: ; 8001560
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	ldr r1, [sp, 0x18]
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r2, 16
	lsrs r7, r2, 16
	lsls r3, 16
	lsrs r6, r3, 16
	lsls r1, 24
	lsrs r5, r1, 24
	adds r0, r4, 0
	bl IsInvalidBg
	lsls r0, 24
	cmp r0, 0
	bne @080015D8
	ldr r1, =0x030008e0
	lsls r0, r4, 2
	adds r1, r0, r1
	ldrb r0, [r1]
	lsls r0, 31
	cmp r0, 0
	beq @080015D8
	cmp r5, 0x1
	beq @080015A4
	cmp r5, 0x2
	beq @080015AC
	movs r2, 0xFF
	b @080015DC
	.pool
@080015A4:
	ldrb r0, [r1, 0x1]
	lsls r0, 30
	lsrs r0, 16
	b @080015B4
@080015AC:
	ldrb r0, [r1, 0x1]
	lsls r0, 25
	lsrs r0, 27
	lsls r0, 11
@080015B4:
	adds r0, r6, r0
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0xC0
	lsls r1, 19
	adds r1, r0, r1
	mov r0, r8
	adds r2, r7, 0
	movs r3, 0
	bl RequestDma3Copy
	lsls r0, 24
	lsrs r2, r0, 24
	asrs r0, 24
	movs r1, 0x1
	negs r1, r1
	cmp r0, r1
	bne @080015DC
@080015D8:
	movs r0, 0xFF
	b @080015DE
@080015DC:
	adds r0, r2, 0
@080015DE:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end LoadBgVram

	thumb_func_start ShowBgInternal
; void ShowBgInternal(u8 bg)
ShowBgInternal: ; 80015E8
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl IsInvalidBg
	lsls r0, 24
	cmp r0, 0
	bne @08001656
	ldr r5, =0x030008e0
	lsls r0, r4, 2
	adds r2, r0, r5
	ldrb r3, [r2]
	lsls r0, r3, 31
	cmp r0, 0
	beq @08001656
	lsls r1, r3, 26
	lsrs r1, 30
	ldrb r2, [r2, 0x1]
	lsls r0, r2, 30
	lsrs r0, 28
	orrs r1, r0
	movs r0, 0x40
	ands r0, r3
	orrs r1, r0
	lsrs r0, r2, 7
	lsls r0, 7
	orrs r1, r0
	lsls r2, 25
	lsrs r2, 27
	lsls r2, 8
	orrs r1, r2
	lsrs r0, r3, 7
	lsls r0, 13
	orrs r1, r0
	lsls r0, r3, 28
	lsrs r0, 30
	lsls r0, 14
	orrs r1, r0
	lsls r0, r4, 25
	movs r2, 0x80
	lsls r2, 20
	adds r0, r2
	lsrs r0, 24
	bl SetGpuReg
	adds r1, r4, 0
	adds r1, 0x8
	movs r0, 0x1
	lsls r0, r1
	ldrh r1, [r5, 0x10]
	orrs r0, r1
	ldr r1, =0x00000f07
	ands r0, r1
	strh r0, [r5, 0x10]
@08001656:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ShowBgInternal

	thumb_func_start HideBgInternal
; void HideBgInternal(u8 bg)
HideBgInternal: ; 8001664
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl IsInvalidBg
	lsls r0, 24
	cmp r0, 0
	bne @0800168A
	ldr r2, =0x030008e0
	adds r0, r4, 0
	adds r0, 0x8
	movs r1, 0x1
	lsls r1, r0
	ldrh r0, [r2, 0x10]
	bics r0, r1
	ldr r1, =0x00000f07
	ands r0, r1
	strh r0, [r2, 0x10]
@0800168A:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end HideBgInternal

	thumb_func_start SyncBgVisibilityAndMode
; void SyncBgVisibilityAndMode()
SyncBgVisibilityAndMode: ; 8001698
	push {lr}
	movs r0, 0
	bl GetGpuReg
	ldr r1, =0x0000f0f8
	ands r1, r0
	ldr r0, =0x030008e0
	ldrh r0, [r0, 0x10]
	orrs r1, r0
	movs r0, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end SyncBgVisibilityAndMode

	thumb_func_start SetTextModeAndHideBgs
; void SetTextModeAndHideBgs()
SetTextModeAndHideBgs: ; 80016BC
	push {lr}
	movs r0, 0
	bl GetGpuReg
	ldr r1, =0x0000f0f8
	ands r1, r0
	movs r0, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetTextModeAndHideBgs

	thumb_func_start SetBgAffineInternal
; void SetBgAffineInternal(u8 bg, u16 srcCenterX, u16 srcCenterY, u16 dispCenterX, u16 dispCenterY, u16 scaleX, u16 scaleY, u16 rotationAngle)
SetBgAffineInternal: ; 80016D8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x24
	mov r12, r1
	mov r8, r2
	ldr r1, [sp, 0x3C]
	ldr r2, [sp, 0x40]
	ldr r4, [sp, 0x44]
	ldr r5, [sp, 0x48]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r3, 16
	lsrs r3, 16
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r2, 16
	lsrs r2, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	ldr r0, =0x030008e0
	ldrh r0, [r0, 0x10]
	movs r1, 0x7
	ands r1, r0
	cmp r1, 0x1
	beq @08001720
	cmp r1, 0x1
	ble @08001796
	cmp r1, 0x2
	beq @08001726
	b @08001796
	.pool
@08001720:
	cmp r6, 0x2
	bne @08001796
	b @08001730
@08001726:
	subs r0, r6, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi @08001796
@08001730:
	mov r0, r12
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r0, sp
	strh r3, [r0, 0x8]
	strh r7, [r0, 0xA]
	strh r2, [r0, 0xC]
	strh r4, [r0, 0xE]
	strh r5, [r0, 0x10]
	add r4, sp, 0x14
	adds r1, r4, 0
	movs r2, 0x1
	bl BgAffineSet
	ldrh r1, [r4]
	movs r0, 0x20
	bl SetGpuReg
	ldrh r1, [r4, 0x2]
	movs r0, 0x22
	bl SetGpuReg
	ldrh r1, [r4, 0x4]
	movs r0, 0x24
	bl SetGpuReg
	ldrh r1, [r4, 0x6]
	movs r0, 0x26
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x20
	bl SetGpuReg
	ldrh r1, [r4, 0x8]
	movs r0, 0x28
	bl SetGpuReg
	ldrh r1, [r4, 0xA]
	movs r0, 0x2A
	bl SetGpuReg
	ldrh r1, [r4, 0xC]
	movs r0, 0x2C
	bl SetGpuReg
	ldrh r1, [r4, 0xE]
	movs r0, 0x2E
	bl SetGpuReg
@08001796:
	add sp, 0x24
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end SetBgAffineInternal

	thumb_func_start IsInvalidBg
; BOOL IsInvalidBg(u8 bg)
IsInvalidBg: ; 80017A4
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi @080017B2
	movs r0, 0
	b @080017B4
@080017B2:
	movs r0, 0x1
@080017B4:
	pop {r1}
	bx r1
	thumb_func_end IsInvalidBg

	thumb_func_start DummiedOutFireRedLeafGreenTileAllocFunc
; int DummiedOutFireRedLeafGreenTileAllocFunc()
DummiedOutFireRedLeafGreenTileAllocFunc: ; 80017B8
	movs r0, 0
	bx lr
	thumb_func_end DummiedOutFireRedLeafGreenTileAllocFunc

	thumb_func_start ResetBgsAndClearDma3BusyFlags
; void ResetBgsAndClearDma3BusyFlags(u32 leftoverFireRedLeafGreenVariable)
ResetBgsAndClearDma3BusyFlags: ; 80017BC
	push {r4,lr}
	adds r4, r0, 0
	bl ResetBgs
	ldr r1, =0x03000938
	movs r2, 0
	adds r0, r1, 0
	adds r0, 0xC
@080017CC:
	str r2, [r0]
	subs r0, 0x4
	cmp r0, r1
	bge @080017CC
	ldr r0, =0x03002f54
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetBgsAndClearDma3BusyFlags

	thumb_func_start InitBgsFromTemplates
; void InitBgsFromTemplates(u8 bgMode, struct BgTemplate *templates, u8 numTemplates)
InitBgsFromTemplates: ; 80017E8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	adds r5, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r4, r2, 24
	bl SetBgModeInternal
	bl ResetWramBgControlStructs
	cmp r4, 0
	beq @08001894
	movs r7, 0
	ldr r0, =0x030008f8
	mov r9, r0
	movs r2, 0xC
	add r2, r9
	mov r10, r2
	adds r6, r5, 0
	mov r8, r4
@0800181A:
	ldr r4, [r6]
	lsls r0, r4, 30
	lsrs r5, r0, 30
	cmp r5, 0x3
	bhi @08001886
	lsls r1, r4, 28
	lsrs r1, 30
	lsls r2, r4, 23
	lsrs r2, 27
	lsls r3, r4, 21
	lsrs r3, 30
	lsls r0, r4, 20
	lsrs r0, 31
	str r0, [sp]
	lsls r0, r4, 18
	lsrs r0, 30
	str r0, [sp, 0x4]
	str r7, [sp, 0x8]
	str r7, [sp, 0xC]
	adds r0, r5, 0
	bl SetBgControlAttributes
	lsls r4, r5, 4
	mov r5, r9
	adds r3, r4, r5
	ldr r2, [r6]
	lsls r2, 8
	lsrs r2, 22
	ldrh r0, [r3]
	ldr r5, =0xfffffc00
	adds r1, r5, 0
	ands r0, r1
	orrs r0, r2
	strh r0, [r3]
	ldrb r0, [r3, 0x1]
	movs r2, 0x3D
	negs r2, r2
	adds r1, r2, 0
	ands r0, r1
	strb r0, [r3, 0x1]
	ldr r0, [r3]
	ldr r1, =0x00003fff
	ands r0, r1
	str r0, [r3]
	mov r0, r9
	adds r0, 0x4
	adds r0, r4, r0
	str r7, [r0]
	mov r0, r9
	adds r0, 0x8
	adds r0, r4, r0
	str r7, [r0]
	add r4, r10
	str r7, [r4]
@08001886:
	adds r6, 0x4
	movs r5, 0x1
	negs r5, r5
	add r8, r5
	mov r0, r8
	cmp r0, 0
	bne @0800181A
@08001894:
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitBgsFromTemplates

	thumb_func_start InitBgFromTemplate
; void InitBgFromTemplate(struct BgTemplate *templates)
InitBgFromTemplate: ; 80018B0
	push {r4-r7,lr}
	sub sp, 0x10
	adds r7, r0, 0
	ldr r4, [r7]
	lsls r0, r4, 30
	lsrs r5, r0, 30
	cmp r5, 0x3
	bhi @08001920
	lsls r1, r4, 28
	lsrs r1, 30
	lsls r2, r4, 23
	lsrs r2, 27
	lsls r3, r4, 21
	lsrs r3, 30
	lsls r0, r4, 20
	lsrs r0, 31
	str r0, [sp]
	lsls r0, r4, 18
	lsrs r0, 30
	str r0, [sp, 0x4]
	movs r6, 0
	str r6, [sp, 0x8]
	str r6, [sp, 0xC]
	adds r0, r5, 0
	bl SetBgControlAttributes
	ldr r4, =0x030008f8
	lsls r5, 4
	adds r3, r5, r4
	ldr r1, [r7]
	lsls r1, 8
	lsrs r1, 22
	ldrh r2, [r3]
	ldr r0, =0xfffffc00
	ands r0, r2
	orrs r0, r1
	strh r0, [r3]
	ldrb r1, [r3, 0x1]
	movs r0, 0x3D
	negs r0, r0
	ands r0, r1
	strb r0, [r3, 0x1]
	ldr r0, [r3]
	ldr r1, =0x00003fff
	ands r0, r1
	str r0, [r3]
	adds r0, r4, 0x4
	adds r0, r5, r0
	str r6, [r0]
	adds r0, r4, 0
	adds r0, 0x8
	adds r0, r5, r0
	str r6, [r0]
	adds r4, 0xC
	adds r5, r4
	str r6, [r5]
@08001920:
	add sp, 0x10
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitBgFromTemplate

	thumb_func_start SetBgMode
; void SetBgMode(u8 bgMode)
SetBgMode: ; 8001934
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl SetBgModeInternal
	pop {r0}
	bx r0
	thumb_func_end SetBgMode

	thumb_func_start LoadBgTiles
; u8 LoadBgTiles(u8 bg, void *src, u16 size, u16 destOffset)
LoadBgTiles: ; 8001944
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	adds r7, r1, 0
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	lsls r3, 16
	lsrs r4, r3, 16
	adds r0, r5, 0
	movs r1, 0x5
	bl GetBgControlAttribute
	lsls r0, 16
	cmp r0, 0
	bne @08001980
	ldr r1, =0x030008f8
	lsls r0, r5, 4
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	adds r0, r4
	lsls r0, 21
	b @08001990
	.pool
@08001980:
	ldr r1, =0x030008f8
	lsls r0, r5, 4
	adds r0, r1
	ldrh r0, [r0]
	lsls r0, 22
	lsrs r0, 22
	adds r0, r4
	lsls r0, 22
@08001990:
	lsrs r4, r0, 16
	movs r6, 0x1
	str r6, [sp]
	adds r0, r5, 0
	adds r1, r7, 0
	mov r2, r8
	adds r3, r4, 0
	bl LoadBgVram
	lsls r2, r0, 24
	lsrs r1, r2, 24
	adds r7, r1, 0
	cmp r1, 0xFF
	bne @080019B8
	ldr r0, =0x0000ffff
	b @080019E6
	.pool
@080019B8:
	ldr r0, =0x03000938
	lsrs r2, 29
	lsls r2, 2
	adds r2, r0
	movs r0, 0x1F
	ands r0, r1
	adds r1, r6, 0
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, =0x03002f54
	ldr r0, [r0]
	cmp r0, 0x1
	bne @080019E4
	lsrs r1, r4, 5
	mov r0, r8
	lsrs r2, r0, 5
	adds r0, r5, 0
	movs r3, 0x1
	bl DummiedOutFireRedLeafGreenTileAllocFunc
@080019E4:
	adds r0, r7, 0
@080019E6:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end LoadBgTiles

	thumb_func_start LoadBgTileMap
; u8 LoadBgTileMap(u8 bg, void *src, u16 size, u16 destOffset)
LoadBgTileMap: ; 80019FC
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 17
	lsrs r3, 16
	movs r4, 0x2
	str r4, [sp]
	bl LoadBgVram
	lsls r2, r0, 24
	lsrs r3, r2, 24
	cmp r3, 0xFF
	beq @08001A3C
	ldr r0, =0x03000938
	lsrs r2, 29
	lsls r2, 2
	adds r2, r0
	movs r0, 0x1F
	ands r0, r3
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r3, 0
	b @08001A3E
	.pool
@08001A3C:
	ldr r0, =0x0000ffff
@08001A3E:
	add sp, 0x4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end LoadBgTileMap

	thumb_func_start Unused_LoadBgPalette
; u8 Unused_LoadBgPalette(u8 bg, void *src, u16 size, u16 destOffset)
Unused_LoadBgPalette: ; 8001A4C
	push {r4-r7,lr}
	adds r7, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r2, 16
	lsrs r6, r2, 16
	lsls r3, 16
	lsrs r5, r3, 16
	adds r0, r4, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @08001A98
	ldr r1, =0x030008f8
	lsls r0, r4, 4
	adds r0, r1
	ldrb r1, [r0, 0x1]
	lsls r1, 26
	lsrs r1, 28
	lsls r1, 5
	lsls r0, r5, 1
	adds r1, r0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0xA0
	lsls r0, 19
	adds r1, r0
	adds r0, r7, 0
	adds r2, r6, 0
	movs r3, 0
	bl RequestDma3Copy
	lsls r3, r0, 24
	asrs r1, r3, 24
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne @08001AA4
@08001A98:
	ldr r0, =0x0000ffff
	b @08001AC8
	.pool
@08001AA4:
	ldr r4, =0x03000938
	adds r0, r1, 0
	cmp r1, 0
	bge @08001AAE
	adds r0, 0x1F
@08001AAE:
	asrs r0, 5
	lsls r2, r0, 2
	adds r2, r4
	lsls r0, 5
	subs r0, r1, r0
	lsls r0, 24
	asrs r0, 24
	movs r1, 0x1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	lsrs r0, r3, 24
@08001AC8:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end Unused_LoadBgPalette

	thumb_func_start IsDma3ManagerBusyWithBgCopy
; BOOL IsDma3ManagerBusyWithBgCopy()
IsDma3ManagerBusyWithBgCopy: ; 8001AD4
	push {r4-r7,lr}
	movs r5, 0
	movs r7, 0x1
	negs r7, r7
@08001ADC:
	adds r0, r5, 0
	cmp r5, 0
	bge @08001AE4
	adds r0, 0x1F
@08001AE4:
	asrs r0, 5
	lsls r2, r0, 24
	lsls r0, 5
	subs r0, r5, r0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x03000938
	lsrs r2, 22
	adds r4, r2, r1
	movs r6, 0x1
	lsls r6, r0
	ldr r0, [r4]
	ands r0, r6
	cmp r0, 0
	beq @08001B22
	lsls r0, r5, 16
	asrs r0, 16
	bl CheckForSpaceForDma3Request
	lsls r0, 24
	asrs r0, 24
	cmp r0, r7
	bne @08001B1C
	movs r0, 0x1
	b @08001B2A
	.pool
@08001B1C:
	ldr r0, [r4]
	bics r0, r6
	str r0, [r4]
@08001B22:
	adds r5, 0x1
	cmp r5, 0x7F
	ble @08001ADC
	movs r0, 0
@08001B2A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end IsDma3ManagerBusyWithBgCopy

	thumb_func_start ShowBg
; void ShowBg(u8 bg)
ShowBg: ; 8001B30
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl ShowBgInternal
	bl SyncBgVisibilityAndMode
	pop {r0}
	bx r0
	thumb_func_end ShowBg

	thumb_func_start HideBg
; void HideBg(u8 bg)
HideBg: ; 8001B44
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	bl HideBgInternal
	bl SyncBgVisibilityAndMode
	pop {r0}
	bx r0
	thumb_func_end HideBg

	thumb_func_start SetBgAttribute
; void SetBgAttribute(u8 bg, u8 attributeId, u8 value)
SetBgAttribute: ; 8001B58
	push {r4,lr}
	sub sp, 0x10
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r3, r2, 24
	subs r0, r1, 0x1
	cmp r0, 0x6
	bhi @08001C12
	lsls r0, 2
	ldr r1, =@08001B7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08001B7C:
	.4byte @08001B98
	.4byte @08001BA8
	.4byte @08001BBA
	.4byte @08001BD0
	.4byte @08001BE4
	.4byte @08001BFC
	.4byte @08001BDA
@08001B98:
	movs r0, 0xFF
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	adds r0, r4, 0
	adds r1, r3, 0
	b @08001BF2
@08001BA8:
	movs r0, 0xFF
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0xFF
	adds r2, r3, 0
	b @08001BF4
@08001BBA:
	movs r0, 0xFF
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r0, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0xFF
	movs r2, 0xFF
	bl SetBgControlAttributes
	b @08001C12
@08001BD0:
	str r3, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	b @08001BEC
@08001BDA:
	movs r0, 0xFF
	str r0, [sp]
	str r3, [sp, 0x4]
	str r0, [sp, 0x8]
	b @08001BEC
@08001BE4:
	movs r0, 0xFF
	str r0, [sp]
	str r0, [sp, 0x4]
	str r3, [sp, 0x8]
@08001BEC:
	str r0, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0xFF
@08001BF2:
	movs r2, 0xFF
@08001BF4:
	movs r3, 0xFF
	bl SetBgControlAttributes
	b @08001C12
@08001BFC:
	movs r0, 0xFF
	str r0, [sp]
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	str r3, [sp, 0xC]
	adds r0, r4, 0
	movs r1, 0xFF
	movs r2, 0xFF
	movs r3, 0xFF
	bl SetBgControlAttributes
@08001C12:
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end SetBgAttribute

	thumb_func_start GetBgAttribute
; u8 GetBgAttribute(u8 bg, u8 attributeId)
GetBgAttribute: ; 8001C1C
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r1, 24
	subs r0, r1, 0x1
	cmp r0, 0x9
	bhi @08001CF8
	lsls r0, 2
	ldr r1, =@08001C3C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@08001C3C:
	.4byte @08001C64
	.4byte @08001C6E
	.4byte @08001C78
	.4byte @08001C82
	.4byte @08001C96
	.4byte @08001CA0
	.4byte @08001C8C
	.4byte @08001CAA
	.4byte @08001CD8
	.4byte @08001CE4
@08001C64:
	adds r0, r4, 0
	movs r1, 0x2
	bl GetBgControlAttribute
	b @08001CDE
@08001C6E:
	adds r0, r4, 0
	movs r1, 0x3
	bl GetBgControlAttribute
	b @08001CDE
@08001C78:
	adds r0, r4, 0
	movs r1, 0x4
	bl GetBgControlAttribute
	b @08001CDE
@08001C82:
	adds r0, r4, 0
	movs r1, 0x5
	bl GetBgControlAttribute
	b @08001CDE
@08001C8C:
	adds r0, r4, 0
	movs r1, 0x6
	bl GetBgControlAttribute
	b @08001CDE
@08001C96:
	adds r0, r4, 0
	movs r1, 0x7
	bl GetBgControlAttribute
	b @08001CDE
@08001CA0:
	adds r0, r4, 0
	movs r1, 0x8
	bl GetBgControlAttribute
	b @08001CDE
@08001CAA:
	adds r0, r4, 0
	bl GetBgType
	cmp r0, 0
	beq @08001CBC
	cmp r0, 0x1
	beq @08001CCA
	movs r0, 0
	b @08001CFA
@08001CBC:
	adds r0, r4, 0
	movs r1, 0
	bl GetBgMetricTextMode
	lsls r0, 27
	lsrs r0, 16
	b @08001CFA
@08001CCA:
	adds r0, r4, 0
	movs r1, 0
	bl GetBgMetricAffineMode
	lsls r0, 24
	lsrs r0, 16
	b @08001CFA
@08001CD8:
	adds r0, r4, 0
	bl GetBgType
@08001CDE:
	lsls r0, 16
	lsrs r0, 16
	b @08001CFA
@08001CE4:
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r1, r0
	ldrh r0, [r1]
	lsls r0, 22
	lsrs r0, 22
	b @08001CFA
	.pool
@08001CF8:
	ldr r0, =0x0000ffff
@08001CFA:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBgAttribute

	thumb_func_start ChangeBgX
; u32 ChangeBgX(u8 bg, u32 value, u8 op)
ChangeBgX: ; 8001D04
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r4, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @08001D28
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBgControlAttribute
	lsls r0, 16
	cmp r0, 0
	bne @08001D2E
@08001D28:
	movs r0, 0x1
	negs r0, r0
	b @08001E34
@08001D2E:
	cmp r5, 0x1
	beq @08001D4C
	cmp r5, 0x1
	ble @08001D3A
	cmp r5, 0x2
	beq @08001D60
@08001D3A:
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r0, 0x8
	adds r0, r1, r0
	str r6, [r0]
	adds r5, r1, 0
	b @08001D70
	.pool
@08001D4C:
	ldr r0, =0x030008f8
	lsls r2, r4, 4
	adds r0, 0x8
	adds r0, r2, r0
	ldr r1, [r0]
	adds r1, r6
	b @08001D6C
	.pool
@08001D60:
	ldr r0, =0x030008f8
	lsls r2, r4, 4
	adds r0, 0x8
	adds r0, r2, r0
	ldr r1, [r0]
	subs r1, r6
@08001D6C:
	str r1, [r0]
	adds r5, r2, 0
@08001D70:
	bl GetBgMode
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0x1
	beq @08001DAC
	cmp r4, 0x1
	bgt @08001D8C
	cmp r4, 0
	beq @08001D96
	b @08001E2C
	.pool
@08001D8C:
	cmp r4, 0x2
	beq @08001DC0
	cmp r4, 0x3
	beq @08001DF8
	b @08001E2C
@08001D96:
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x8]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x10
	bl SetGpuReg
	b @08001E2C
	.pool
@08001DAC:
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x18]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x14
	bl SetGpuReg
	b @08001E2C
	.pool
@08001DC0:
	cmp r0, 0
	bne @08001DD8
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x28]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x18
	bl SetGpuReg
	b @08001E2C
	.pool
@08001DD8:
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x28]
	lsrs r1, r0, 16
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x2A
	bl SetGpuReg
	movs r0, 0x28
	adds r1, r4, 0
	bl SetGpuReg
	b @08001E2C
	.pool
@08001DF8:
	cmp r0, 0
	bne @08001E10
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x38]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x1C
	bl SetGpuReg
	b @08001E2C
	.pool
@08001E10:
	cmp r0, 0x2
	bne @08001E2C
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x38]
	lsrs r1, r0, 16
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x3A
	bl SetGpuReg
	movs r0, 0x38
	adds r1, r4, 0
	bl SetGpuReg
@08001E2C:
	ldr r0, =0x030008f8
	adds r0, 0x8
	adds r0, r5, r0
	ldr r0, [r0]
@08001E34:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ChangeBgX

	thumb_func_start GetBgX
; u32 GetBgX(u8 bg)
GetBgX: ; 8001E40
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @08001E70
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBgControlAttribute
	lsls r0, 16
	cmp r0, 0
	beq @08001E70
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r0, 0x8
	adds r1, r0
	ldr r0, [r1]
	b @08001E74
	.pool
@08001E70:
	movs r0, 0x1
	negs r0, r0
@08001E74:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetBgX

	thumb_func_start ChangeBgY
; u32 ChangeBgY(u8 bg, u32 value, u8 op)
ChangeBgY: ; 8001E7C
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r4, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @08001EA0
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBgControlAttribute
	lsls r0, 16
	cmp r0, 0
	bne @08001EA6
@08001EA0:
	movs r0, 0x1
	negs r0, r0
	b @08001FAC
@08001EA6:
	cmp r5, 0x1
	beq @08001EC4
	cmp r5, 0x1
	ble @08001EB2
	cmp r5, 0x2
	beq @08001ED8
@08001EB2:
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r0, 0xC
	adds r0, r1, r0
	str r6, [r0]
	adds r5, r1, 0
	b @08001EE8
	.pool
@08001EC4:
	ldr r0, =0x030008f8
	lsls r2, r4, 4
	adds r0, 0xC
	adds r0, r2, r0
	ldr r1, [r0]
	adds r1, r6
	b @08001EE4
	.pool
@08001ED8:
	ldr r0, =0x030008f8
	lsls r2, r4, 4
	adds r0, 0xC
	adds r0, r2, r0
	ldr r1, [r0]
	subs r1, r6
@08001EE4:
	str r1, [r0]
	adds r5, r2, 0
@08001EE8:
	bl GetBgMode
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0x1
	beq @08001F24
	cmp r4, 0x1
	bgt @08001F04
	cmp r4, 0
	beq @08001F0E
	b @08001FA4
	.pool
@08001F04:
	cmp r4, 0x2
	beq @08001F38
	cmp r4, 0x3
	beq @08001F70
	b @08001FA4
@08001F0E:
	ldr r0, =0x030008f8
	ldr r0, [r0, 0xC]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x12
	bl SetGpuReg
	b @08001FA4
	.pool
@08001F24:
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x1C]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x16
	bl SetGpuReg
	b @08001FA4
	.pool
@08001F38:
	cmp r0, 0
	bne @08001F50
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x2C]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x1A
	bl SetGpuReg
	b @08001FA4
	.pool
@08001F50:
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x2C]
	lsrs r1, r0, 16
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x2E
	bl SetGpuReg
	movs r0, 0x2C
	adds r1, r4, 0
	bl SetGpuReg
	b @08001FA4
	.pool
@08001F70:
	cmp r0, 0
	bne @08001F88
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x3C]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x1E
	bl SetGpuReg
	b @08001FA4
	.pool
@08001F88:
	cmp r0, 0x2
	bne @08001FA4
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x3C]
	lsrs r1, r0, 16
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x3E
	bl SetGpuReg
	movs r0, 0x3C
	adds r1, r4, 0
	bl SetGpuReg
@08001FA4:
	ldr r0, =0x030008f8
	adds r0, 0xC
	adds r0, r5, r0
	ldr r0, [r0]
@08001FAC:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ChangeBgY

	thumb_func_start ChangeBgY_ScreenOff
; u32 ChangeBgY_ScreenOff(u8 bg, u32 value, u8 op)
ChangeBgY_ScreenOff: ; 8001FB8
	push {r4-r6,lr}
	adds r6, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r2, 24
	lsrs r5, r2, 24
	adds r0, r4, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @08001FDC
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBgControlAttribute
	lsls r0, 16
	cmp r0, 0
	bne @08001FE2
@08001FDC:
	movs r0, 0x1
	negs r0, r0
	b @080020E8
@08001FE2:
	cmp r5, 0x1
	beq @08002000
	cmp r5, 0x1
	ble @08001FEE
	cmp r5, 0x2
	beq @08002014
@08001FEE:
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r0, 0xC
	adds r0, r1, r0
	str r6, [r0]
	adds r5, r1, 0
	b @08002024
	.pool
@08002000:
	ldr r0, =0x030008f8
	lsls r2, r4, 4
	adds r0, 0xC
	adds r0, r2, r0
	ldr r1, [r0]
	adds r1, r6
	b @08002020
	.pool
@08002014:
	ldr r0, =0x030008f8
	lsls r2, r4, 4
	adds r0, 0xC
	adds r0, r2, r0
	ldr r1, [r0]
	subs r1, r6
@08002020:
	str r1, [r0]
	adds r5, r2, 0
@08002024:
	bl GetBgMode
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0x1
	beq @08002060
	cmp r4, 0x1
	bgt @08002040
	cmp r4, 0
	beq @0800204A
	b @080020E0
	.pool
@08002040:
	cmp r4, 0x2
	beq @08002074
	cmp r4, 0x3
	beq @080020AC
	b @080020E0
@0800204A:
	ldr r0, =0x030008f8
	ldr r0, [r0, 0xC]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x12
	bl SetGpuReg_ScreenOff
	b @080020E0
	.pool
@08002060:
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x1C]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x16
	bl SetGpuReg_ScreenOff
	b @080020E0
	.pool
@08002074:
	cmp r0, 0
	bne @0800208C
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x2C]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x1A
	bl SetGpuReg_ScreenOff
	b @080020E0
	.pool
@0800208C:
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x2C]
	lsrs r1, r0, 16
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x2E
	bl SetGpuReg_ScreenOff
	movs r0, 0x2C
	adds r1, r4, 0
	bl SetGpuReg_ScreenOff
	b @080020E0
	.pool
@080020AC:
	cmp r0, 0
	bne @080020C4
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x3C]
	lsls r0, 8
	lsrs r1, r0, 16
	movs r0, 0x1E
	bl SetGpuReg_ScreenOff
	b @080020E0
	.pool
@080020C4:
	cmp r0, 0x2
	bne @080020E0
	ldr r0, =0x030008f8
	ldr r0, [r0, 0x3C]
	lsrs r1, r0, 16
	lsls r0, 16
	lsrs r4, r0, 16
	movs r0, 0x3E
	bl SetGpuReg_ScreenOff
	movs r0, 0x3C
	adds r1, r4, 0
	bl SetGpuReg_ScreenOff
@080020E0:
	ldr r0, =0x030008f8
	adds r0, 0xC
	adds r0, r5, r0
	ldr r0, [r0]
@080020E8:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ChangeBgY_ScreenOff

	thumb_func_start GetBgY
; u32 GetBgY(u8 bg)
GetBgY: ; 80020F4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @08002124
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBgControlAttribute
	lsls r0, 16
	cmp r0, 0
	beq @08002124
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r0, 0xC
	adds r1, r0
	ldr r0, [r1]
	b @08002128
	.pool
@08002124:
	movs r0, 0x1
	negs r0, r0
@08002128:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetBgY

	thumb_func_start SetBgAffine
; void SetBgAffine(u8 bg, u16 srcCenterX, u16 srcCenterY, s16 dispCenterX, s16 dispCenterY, s16 scaleX, s16 scaleY, u16 rotationAngle)
SetBgAffine: ; 8002130
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	ldr r4, [sp, 0x28]
	ldr r5, [sp, 0x2C]
	ldr r6, [sp, 0x30]
	ldr r7, [sp, 0x34]
	lsls r0, 24
	lsrs r0, 24
	lsls r7, 16
	lsrs r7, 16
	lsls r3, 16
	asrs r3, 16
	lsls r4, 16
	asrs r4, 16
	str r4, [sp]
	lsls r5, 16
	asrs r5, 16
	str r5, [sp, 0x4]
	lsls r6, 16
	asrs r6, 16
	str r6, [sp, 0x8]
	str r7, [sp, 0xC]
	bl SetBgAffineInternal
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end SetBgAffine

	thumb_func_start Unused_AdjustBgMosaic
; u8 Unused_AdjustBgMosaic(u8 a1, u8 a2)
Unused_AdjustBgMosaic: ; 8002170
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	movs r0, 0x4C
	bl GetGpuReg
	lsls r0, 16
	lsrs r5, r0, 16
	movs r1, 0xF
	movs r3, 0xF
	ands r3, r5
	lsrs r2, r0, 20
	ands r2, r1
	movs r0, 0xFF
	lsls r0, 8
	ands r5, r0
	cmp r6, 0x6
	bhi @080021C4
	lsls r0, r6, 2
	ldr r1, =@080021A8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
@080021A8:
	.4byte @080021C4
	.4byte @080021CC
	.4byte @080021D2
	.4byte @080021E4
	.4byte @080021FA
	.4byte @08002200
	.4byte @08002212
@080021C4:
	movs r3, 0xF
	ands r3, r4
	lsrs r2, r4, 4
	b @08002226
@080021CC:
	movs r3, 0xF
	ands r3, r4
	b @08002226
@080021D2:
	lsls r0, r3, 16
	asrs r0, 16
	adds r0, r4
	cmp r0, 0xF
	ble @080021E0
	movs r3, 0xF
	b @08002226
@080021E0:
	adds r0, r3, r4
	b @080021F4
@080021E4:
	lsls r0, r3, 16
	asrs r0, 16
	subs r0, r4
	cmp r0, 0
	bge @080021F2
	movs r3, 0
	b @08002226
@080021F2:
	subs r0, r3, r4
@080021F4:
	lsls r0, 16
	lsrs r3, r0, 16
	b @08002226
@080021FA:
	movs r2, 0xF
	ands r2, r4
	b @08002226
@08002200:
	lsls r0, r2, 16
	asrs r0, 16
	adds r0, r4
	cmp r0, 0xF
	ble @0800220E
	movs r2, 0xF
	b @08002226
@0800220E:
	adds r0, r2, r4
	b @08002222
@08002212:
	lsls r0, r2, 16
	asrs r0, 16
	subs r0, r4
	cmp r0, 0
	bge @08002220
	movs r2, 0
	b @08002226
@08002220:
	subs r0, r2, r4
@08002222:
	lsls r0, 16
	lsrs r2, r0, 16
@08002226:
	lsls r0, r2, 16
	asrs r0, 12
	movs r1, 0xF0
	ands r0, r1
	orrs r5, r0
	lsls r0, r3, 16
	asrs r0, 16
	movs r1, 0xF
	ands r0, r1
	orrs r5, r0
	lsls r0, r5, 16
	lsrs r5, r0, 16
	movs r0, 0x4C
	adds r1, r5, 0
	bl SetGpuReg
	lsls r0, r5, 24
	lsrs r0, 24
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end Unused_AdjustBgMosaic

	thumb_func_start SetBgTileMap
; void SetBgTileMap(u8 bg, void *tileMap)
SetBgTileMap: ; 8002250
	push {r4,r5,lr}
	adds r5, r1, 0
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @0800227A
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBgControlAttribute
	lsls r0, 16
	cmp r0, 0
	beq @0800227A
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r0, 0x4
	adds r1, r0
	str r5, [r1]
@0800227A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBgTileMap

	thumb_func_start UnsetBgTileMap
; void UnsetBgTileMap(u8 bg)
UnsetBgTileMap: ; 8002284
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl IsInvalidBg_
	adds r5, r0, 0
	cmp r5, 0
	bne @080022AE
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBgControlAttribute
	lsls r0, 16
	cmp r0, 0
	beq @080022AE
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r0, 0x4
	adds r1, r0
	str r5, [r1]
@080022AE:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end UnsetBgTileMap

	thumb_func_start GetBgTileMap
; void *GetBgTileMap(u8 bg)
GetBgTileMap: ; 80022B8
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @080022E8
	adds r0, r4, 0
	movs r1, 0x1
	bl GetBgControlAttribute
	lsls r0, 16
	cmp r0, 0
	beq @080022E8
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r0, 0x4
	adds r1, r0
	ldr r0, [r1]
	b @080022EA
	.pool
@080022E8:
	movs r0, 0
@080022EA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetBgTileMap

	thumb_func_start CopyToBgTileMapBuffer
; void CopyToBgTileMapBuffer(u8 bg, void *src, u16 mode, u16 destOffset)
CopyToBgTileMapBuffer: ; 80022F0
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	mov r10, r1
	lsls r0, 24
	lsrs r4, r0, 24
	mov r9, r4
	lsls r7, r2, 16
	lsrs r6, r7, 16
	lsls r3, 16
	lsrs r5, r3, 16
	mov r8, r5
	adds r0, r4, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @08002358
	adds r0, r4, 0
	bl IsTileMapOutsideWram
	cmp r0, 0
	bne @08002358
	cmp r6, 0
	beq @08002340
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r0, 0x4
	adds r1, r0
	lsls r0, r5, 1
	ldr r1, [r1]
	adds r1, r0
	lsrs r2, r7, 17
	mov r0, r10
	bl CpuSet
	b @08002358
	.pool
@08002340:
	ldr r0, =0x030008f8
	mov r2, r9
	lsls r1, r2, 4
	adds r0, 0x4
	adds r1, r0
	mov r2, r8
	lsls r0, r2, 1
	ldr r1, [r1]
	adds r1, r0
	mov r0, r10
	bl LZ77UnCompWram
@08002358:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyToBgTileMapBuffer

	thumb_func_start CopyBgTileMapBufferToVram
; void CopyBgTileMapBufferToVram(u8 bg)
CopyBgTileMapBufferToVram: ; 800236C
	push {r4,lr}
	sub sp, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @080023C8
	adds r0, r4, 0
	bl IsTileMapOutsideWram
	cmp r0, 0
	bne @080023C8
	adds r0, r4, 0
	bl GetBgType
	cmp r0, 0
	beq @0800239A
	cmp r0, 0x1
	beq @080023A6
	movs r2, 0
	b @080023B2
@0800239A:
	adds r0, r4, 0
	movs r1, 0
	bl GetBgMetricTextMode
	lsls r0, 27
	b @080023B0
@080023A6:
	adds r0, r4, 0
	movs r1, 0
	bl GetBgMetricAffineMode
	lsls r0, 24
@080023B0:
	lsrs r2, r0, 16
@080023B2:
	ldr r0, =0x030008f8
	lsls r1, r4, 4
	adds r0, 0x4
	adds r1, r0
	ldr r1, [r1]
	movs r0, 0x2
	str r0, [sp]
	adds r0, r4, 0
	movs r3, 0
	bl LoadBgVram
@080023C8:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyBgTileMapBufferToVram

	thumb_func_start CopyToBgTileMapBufferRect
; void CopyToBgTileMapBufferRect(u8 bg, void *src, u8 destX, u8 destY, u8 width, u8 height)
CopyToBgTileMapBufferRect: ; 80023D4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r1
	ldr r1, [sp, 0x24]
	ldr r4, [sp, 0x28]
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	lsls r4, 24
	lsrs r6, r4, 24
	adds r0, r5, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @080024C4
	adds r0, r5, 0
	bl IsTileMapOutsideWram
	cmp r0, 0
	bne @080024C4
	adds r0, r5, 0
	bl GetBgType
	cmp r0, 0
	beq @08002422
	cmp r0, 0x1
	beq @08002470
	b @080024C4
@08002422:
	mov r4, r8
	adds r3, r7, 0
	adds r0, r3, r6
	cmp r3, r0
	bge @080024C4
	mov r12, r0
	lsls r1, r5, 4
	ldr r0, =0x030008fc
	adds r1, r0
	mov r8, r1
@08002436:
	mov r2, r10
	mov r1, r9
	adds r0, r2, r1
	adds r7, r3, 0x1
	cmp r2, r0
	bge @08002460
	mov r1, r8
	ldr r6, [r1]
	lsls r5, r3, 5
	adds r3, r0, 0
@0800244A:
	adds r0, r5, r2
	lsls r0, 1
	adds r0, r6
	ldrh r1, [r4]
	strh r1, [r0]
	adds r4, 0x2
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r3
	blt @0800244A
@08002460:
	lsls r0, r7, 16
	lsrs r3, r0, 16
	cmp r3, r12
	blt @08002436
	b @080024C4
	.pool
@08002470:
	mov r4, r8
	adds r0, r5, 0
	movs r1, 0x1
	bl GetBgMetricAffineMode
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	adds r3, r7, 0
	adds r0, r3, r6
	cmp r3, r0
	bge @080024C4
	mov r12, r0
	lsls r5, 4
	mov r8, r5
@0800248E:
	mov r2, r10
	mov r1, r9
	adds r0, r2, r1
	adds r7, r3, 0x1
	cmp r2, r0
	bge @080024BC
	ldr r6, =0x030008fc
	add r6, r8
	ldr r1, [sp]
	adds r5, r3, 0
	muls r5, r1
	adds r3, r0, 0
@080024A6:
	ldr r1, [r6]
	adds r0, r5, r2
	adds r1, r0
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, 0x1
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r3
	blt @080024A6
@080024BC:
	lsls r0, r7, 16
	lsrs r3, r0, 16
	cmp r3, r12
	blt @0800248E
@080024C4:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyToBgTileMapBufferRect

	thumb_func_start CopyToBgTileMapBufferRect_ChangePalette
; void CopyToBgTileMapBufferRect_ChangePalette(u8 bg, void *src, u8 destX, u8 destY, u8 rectWidth, u8 rectHeight, u8 palette)
CopyToBgTileMapBufferRect_ChangePalette: ; 80024D8
	push {r4-r6,lr}
	sub sp, 0x24
	ldr r4, [sp, 0x34]
	ldr r5, [sp, 0x38]
	ldr r6, [sp, 0x3C]
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r2, [sp, 0x8]
	str r3, [sp, 0xC]
	str r4, [sp, 0x10]
	str r5, [sp, 0x14]
	str r6, [sp, 0x18]
	movs r2, 0
	str r2, [sp, 0x1C]
	str r2, [sp, 0x20]
	movs r3, 0
	bl CopyRectToBgTileMapBufferRect
	add sp, 0x24
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end CopyToBgTileMapBufferRect_ChangePalette

	thumb_func_start CopyRectToBgTileMapBufferRect
; void CopyRectToBgTileMapBufferRect(u8 bg, void *src, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 destX, u8 destY, u8 rectWidth, u8 rectHeight, u8 palette1, u16 tileOffset, u16 palette2)
CopyRectToBgTileMapBufferRect: ; 800251C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	str r1, [sp, 0x8]
	ldr r1, [sp, 0x60]
	ldr r4, [sp, 0x68]
	ldr r5, [sp, 0x6C]
	ldr r6, [sp, 0x70]
	ldr r7, [sp, 0x74]
	mov r8, r7
	ldr r7, [sp, 0x78]
	mov r9, r7
	ldr r7, [sp, 0x7C]
	mov r10, r7
	ldr r7, [sp, 0x80]
	mov r12, r7
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x4]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0xC]
	lsls r3, 24
	lsrs r3, 24
	str r3, [sp, 0x10]
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r4, 24
	lsrs r4, 24
	str r4, [sp, 0x14]
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	str r6, [sp, 0x18]
	mov r0, r8
	lsls r0, 24
	lsrs r4, r0, 24
	mov r1, r9
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x1C]
	mov r2, r10
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x20]
	mov r0, r12
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x24]
	ldr r0, [sp, 0x4]
	bl IsInvalidBg_
	cmp r0, 0
	beq @08002592
	b @080026EE
@08002592:
	ldr r0, [sp, 0x4]
	bl IsTileMapOutsideWram
	cmp r0, 0
	beq @0800259E
	b @080026EE
@0800259E:
	ldr r0, [sp, 0x4]
	movs r1, 0x4
	bl GetBgControlAttribute
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x30]
	ldr r0, [sp, 0x4]
	movs r1, 0x1
	bl GetBgMetricTextMode
	lsls r0, 21
	lsrs r0, 16
	str r0, [sp, 0x28]
	ldr r0, [sp, 0x4]
	movs r1, 0x2
	bl GetBgMetricTextMode
	lsls r0, 21
	lsrs r0, 16
	str r0, [sp, 0x2C]
	ldr r0, [sp, 0x4]
	bl GetBgType
	cmp r0, 0
	beq @080025D8
	cmp r0, 0x1
	beq @08002674
	b @080026EE
@080025D8:
	ldr r1, [sp, 0x10]
	adds r0, r1, 0
	muls r0, r7
	ldr r2, [sp, 0xC]
	adds r0, r2
	lsls r0, 1
	ldr r1, [sp, 0x8]
	adds r6, r1, r0
	adds r0, r5, r4
	cmp r5, r0
	blt @080025F0
	b @080026EE
@080025F0:
	ldr r2, [sp, 0x18]
	subs r2, r7, r2
	str r2, [sp, 0x34]
	str r0, [sp, 0x38]
@080025F8:
	ldr r4, [sp, 0x14]
	ldr r7, [sp, 0x18]
	adds r0, r4, r7
	adds r1, r5, 0x1
	str r1, [sp, 0x3C]
	cmp r4, r0
	bge @0800265A
	ldr r2, [sp, 0x4]
	lsls r0, r2, 4
	ldr r1, =0x030008fc
	adds r0, r1
	mov r10, r0
	ldr r7, [sp, 0x20]
	lsls r7, 16
	mov r9, r7
	ldr r1, [sp, 0x24]
	lsls r0, r1, 16
	asrs r0, 16
	mov r8, r0
@0800261E:
	ldr r2, [sp, 0x2C]
	str r2, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	ldr r2, [sp, 0x30]
	ldr r3, [sp, 0x28]
	bl GetTileMapIndexFromCoords
	lsls r0, 16
	lsrs r0, 15
	mov r7, r10
	ldr r1, [r7]
	adds r1, r0
	mov r0, r8
	str r0, [sp]
	adds r0, r6, 0
	ldr r2, [sp, 0x1C]
	mov r7, r9
	asrs r3, r7, 16
	bl CopyTileMapEntry
	adds r6, 0x2
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r1, [sp, 0x14]
	ldr r2, [sp, 0x18]
	adds r0, r1, r2
	cmp r4, r0
	blt @0800261E
@0800265A:
	ldr r5, [sp, 0x34]
	lsls r0, r5, 1
	adds r6, r0
	ldr r7, [sp, 0x3C]
	lsls r0, r7, 16
	lsrs r5, r0, 16
	ldr r0, [sp, 0x38]
	cmp r5, r0
	blt @080025F8
	b @080026EE
	.pool
@08002674:
	ldr r1, [sp, 0x10]
	adds r0, r1, 0
	muls r0, r7
	ldr r2, [sp, 0xC]
	adds r0, r2
	ldr r1, [sp, 0x8]
	adds r6, r1, r0
	ldr r0, [sp, 0x4]
	movs r1, 0x1
	bl GetBgMetricAffineMode
	lsls r0, 16
	lsrs r0, 16
	mov r9, r0
	adds r0, r5, r4
	cmp r5, r0
	bge @080026EE
	ldr r2, [sp, 0x18]
	subs r2, r7, r2
	str r2, [sp, 0x34]
	str r0, [sp, 0x38]
	ldr r7, =0x030008fc
	mov r10, r7
	ldr r0, [sp, 0x4]
	lsls r0, 4
	mov r8, r0
@080026A8:
	ldr r4, [sp, 0x14]
	ldr r1, [sp, 0x18]
	adds r0, r4, r1
	adds r2, r5, 0x1
	str r2, [sp, 0x3C]
	cmp r4, r0
	bge @080026DE
	mov r3, r8
	add r3, r10
	mov r7, r9
	muls r7, r5
	mov r12, r7
	adds r2, r0, 0
@080026C2:
	ldr r1, [r3]
	mov r5, r12
	adds r0, r5, r4
	adds r1, r0
	ldrb r0, [r6]
	ldr r7, [sp, 0x20]
	adds r0, r7
	strb r0, [r1]
	adds r6, 0x1
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r2
	blt @080026C2
@080026DE:
	ldr r0, [sp, 0x34]
	adds r6, r0
	ldr r1, [sp, 0x3C]
	lsls r0, r1, 16
	lsrs r5, r0, 16
	ldr r2, [sp, 0x38]
	cmp r5, r2
	blt @080026A8
@080026EE:
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyRectToBgTileMapBufferRect

	thumb_func_start FillBgTileMapBufferRect_Palette0
; void FillBgTileMapBufferRect_Palette0(u8 bg, u16 tileNum, u8 x, u8 y, u8 width, u8 height)
FillBgTileMapBufferRect_Palette0: ; 8002704
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	ldr r4, [sp, 0x24]
	ldr r5, [sp, 0x28]
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r1, 16
	lsrs r1, 16
	mov r8, r1
	lsls r2, 24
	lsrs r2, 24
	mov r10, r2
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r4, 24
	lsrs r4, 24
	mov r9, r4
	lsls r5, 24
	lsrs r5, 24
	adds r0, r6, 0
	bl IsInvalidBg_
	cmp r0, 0
	bne @080027F0
	adds r0, r6, 0
	bl IsTileMapOutsideWram
	cmp r0, 0
	bne @080027F0
	adds r0, r6, 0
	bl GetBgType
	cmp r0, 0
	beq @08002756
	cmp r0, 0x1
	beq @080027A0
	b @080027F0
@08002756:
	adds r3, r7, 0
	adds r5, r3, r5
	cmp r3, r5
	bge @080027F0
	adds r7, r5, 0
	lsls r1, r6, 4
	ldr r0, =0x030008fc
	adds r1, r0
	mov r12, r1
@08002768:
	mov r2, r10
	mov r1, r9
	adds r0, r2, r1
	adds r6, r3, 0x1
	cmp r2, r0
	bge @08002790
	mov r5, r12
	ldr r4, [r5]
	lsls r3, 5
	adds r1, r0, 0
@0800277C:
	adds r0, r3, r2
	lsls r0, 1
	adds r0, r4
	mov r5, r8
	strh r5, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r1
	blt @0800277C
@08002790:
	lsls r0, r6, 16
	lsrs r3, r0, 16
	cmp r3, r7
	blt @08002768
	b @080027F0
	.pool
@080027A0:
	adds r0, r6, 0
	movs r1, 0x1
	bl GetBgMetricAffineMode
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp]
	adds r3, r7, 0
	adds r5, r3, r5
	cmp r3, r5
	bge @080027F0
	adds r7, r5, 0
	lsls r6, 4
	mov r12, r6
@080027BC:
	mov r2, r10
	mov r1, r9
	adds r0, r2, r1
	adds r6, r3, 0x1
	cmp r2, r0
	bge @080027E8
	ldr r5, =0x030008fc
	add r5, r12
	ldr r1, [sp]
	adds r4, r3, 0
	muls r4, r1
	adds r3, r0, 0
@080027D4:
	ldr r0, [r5]
	adds r1, r4, r2
	adds r0, r1
	mov r1, r8
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r3
	blt @080027D4
@080027E8:
	lsls r0, r6, 16
	lsrs r3, r0, 16
	cmp r3, r7
	blt @080027BC
@080027F0:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end FillBgTileMapBufferRect_Palette0

	thumb_func_start FillBgTileMapBufferRect
; void FillBgTileMapBufferRect(u8 bg, u16 tileNum, u8 x, u8 y, u8 width, u8 height, u8 palette)
FillBgTileMapBufferRect: ; 8002804
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r4, [sp, 0x20]
	ldr r5, [sp, 0x24]
	ldr r6, [sp, 0x28]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r4, 0
	str r4, [sp, 0xC]
	bl WriteSequenceToBgTileMapBuffer
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end FillBgTileMapBufferRect

	thumb_func_start WriteSequenceToBgTileMapBuffer
; void WriteSequenceToBgTileMapBuffer(u8 bg, u16 firstTileNum, u8 x, u8 y, u8 width, u8 height, u8 paletteSlot, u16 tileNumDelta)
WriteSequenceToBgTileMapBuffer: ; 8002840
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	ldr r4, [sp, 0x4C]
	ldr r5, [sp, 0x50]
	ldr r6, [sp, 0x54]
	ldr r7, [sp, 0x58]
	mov r8, r7
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	add r0, sp, 0x4
	strh r1, [r0]
	lsls r2, 24
	lsrs r2, 24
	str r2, [sp, 0x8]
	lsls r3, 24
	lsrs r7, r3, 24
	lsls r4, 24
	lsrs r4, 24
	mov r10, r4
	lsls r5, 24
	lsrs r4, r5, 24
	lsls r6, 24
	lsrs r6, 24
	str r6, [sp, 0xC]
	mov r0, r8
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x10]
	mov r0, r9
	bl IsInvalidBg_
	cmp r0, 0
	beq @0800288E
	b @080029D4
@0800288E:
	mov r0, r9
	bl IsTileMapOutsideWram
	cmp r0, 0
	beq @0800289A
	b @080029D4
@0800289A:
	mov r0, r9
	movs r1, 0x4
	bl GetBgControlAttribute
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x1C]
	mov r0, r9
	movs r1, 0x1
	bl GetBgMetricTextMode
	lsls r0, 21
	lsrs r0, 16
	str r0, [sp, 0x14]
	mov r0, r9
	movs r1, 0x2
	bl GetBgMetricTextMode
	lsls r0, 21
	lsrs r0, 16
	str r0, [sp, 0x18]
	mov r0, r9
	bl GetBgType
	cmp r0, 0
	beq @080028D4
	cmp r0, 0x1
	beq @0800295C
	b @080029D4
@080028D4:
	adds r5, r7, 0
	adds r0, r5, r4
	cmp r5, r0
	bge @080029D4
	str r0, [sp, 0x24]
	add r7, sp, 0x4
@080028E0:
	ldr r4, [sp, 0x8]
	mov r1, r10
	adds r0, r4, r1
	adds r2, r5, 0x1
	mov r8, r2
	cmp r4, r0
	bge @08002944
	mov r3, r9
	lsls r1, r3, 4
	ldr r0, =0x030008fc
	adds r6, r1, r0
@080028F6:
	ldr r0, [sp, 0x18]
	str r0, [sp]
	adds r0, r4, 0
	adds r1, r5, 0
	ldr r2, [sp, 0x1C]
	ldr r3, [sp, 0x14]
	bl GetTileMapIndexFromCoords
	lsls r0, 16
	lsrs r0, 15
	ldr r1, [r6]
	adds r1, r0
	movs r0, 0
	str r0, [sp]
	add r0, sp, 0x4
	ldr r2, [sp, 0xC]
	movs r3, 0
	bl CopyTileMapEntry
	ldrh r0, [r7]
	movs r2, 0xFC
	lsls r2, 8
	adds r1, r2, 0
	adds r2, r0, 0
	ands r2, r1
	ldr r3, [sp, 0x10]
	adds r0, r3
	ldr r3, =0x000003ff
	adds r1, r3, 0
	ands r0, r1
	adds r2, r0
	strh r2, [r7]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, [sp, 0x8]
	add r0, r10
	cmp r4, r0
	blt @080028F6
@08002944:
	mov r1, r8
	lsls r0, r1, 16
	lsrs r5, r0, 16
	ldr r2, [sp, 0x24]
	cmp r5, r2
	blt @080028E0
	b @080029D4
	.pool
@0800295C:
	mov r0, r9
	movs r1, 0x1
	bl GetBgMetricAffineMode
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x20]
	adds r5, r7, 0
	adds r0, r5, r4
	cmp r5, r0
	bge @080029D4
	str r0, [sp, 0x24]
	mov r3, r9
	lsls r3, 4
	mov r12, r3
@0800297A:
	ldr r4, [sp, 0x8]
	mov r7, r10
	adds r0, r4, r7
	adds r1, r5, 0x1
	mov r8, r1
	cmp r4, r0
	bge @080029C8
	ldr r2, =0x030008fc
	add r2, r12
	str r2, [sp, 0x28]
	ldr r7, [sp, 0x20]
	adds r3, r5, 0
	muls r3, r7
	add r2, sp, 0x4
	movs r1, 0xFC
	lsls r1, 8
	mov r9, r1
	ldr r7, =0x000003ff
	adds r5, r7, 0
	adds r6, r0, 0
@080029A2:
	ldr r0, [sp, 0x28]
	ldr r1, [r0]
	adds r0, r3, r4
	adds r1, r0
	ldrh r0, [r2]
	strb r0, [r1]
	ldrh r0, [r2]
	mov r1, r9
	ands r1, r0
	ldr r7, [sp, 0x10]
	adds r0, r7
	ands r0, r5
	adds r1, r0
	strh r1, [r2]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, r6
	blt @080029A2
@080029C8:
	mov r1, r8
	lsls r0, r1, 16
	lsrs r5, r0, 16
	ldr r2, [sp, 0x24]
	cmp r5, r2
	blt @0800297A
@080029D4:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end WriteSequenceToBgTileMapBuffer

	thumb_func_start GetBgMetricTextMode
; u16 GetBgMetricTextMode(u8 bg, u8 whichMetric)
GetBgMetricTextMode: ; 80029EC
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	adds r5, r4, 0
	movs r1, 0x4
	bl GetBgControlAttribute
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0x1
	beq @08002A2C
	cmp r4, 0x1
	bgt @08002A10
	cmp r4, 0
	beq @08002A16
	b @08002A52
@08002A10:
	cmp r5, 0x2
	beq @08002A3E
	b @08002A52
@08002A16:
	cmp r0, 0x2
	bgt @08002A24
	cmp r0, 0x1
	bge @08002A4E
@08002A1E:
	cmp r0, 0
	beq @08002A46
	b @08002A52
@08002A24:
	cmp r0, 0x3
	bne @08002A52
	movs r0, 0x4
	b @08002A54
@08002A2C:
	cmp r0, 0x1
	beq @08002A4E
	cmp r0, 0x1
	ble @08002A1E
	cmp r0, 0x2
	beq @08002A46
	cmp r0, 0x3
	bne @08002A52
	b @08002A4E
@08002A3E:
	cmp r0, 0
	blt @08002A52
	cmp r0, 0x1
	bgt @08002A4A
@08002A46:
	movs r0, 0x1
	b @08002A54
@08002A4A:
	cmp r0, 0x3
	bgt @08002A52
@08002A4E:
	movs r0, 0x2
	b @08002A54
@08002A52:
	movs r0, 0
@08002A54:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetBgMetricTextMode

	thumb_func_start GetBgMetricAffineMode
; u16 GetBgMetricAffineMode(u8 bg, u8 whichMetric)
GetBgMetricAffineMode: ; 8002A5C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	movs r1, 0x4
	bl GetBgControlAttribute
	lsls r0, 24
	lsrs r1, r0, 24
	adds r0, r1, 0
	cmp r4, 0
	beq @08002A84
	cmp r4, 0
	blt @08002AAC
	cmp r4, 0x2
	bgt @08002AAC
	movs r0, 0x10
	lsls r0, r1
	b @08002AAE
@08002A84:
	cmp r1, 0x1
	beq @08002AA0
	cmp r1, 0x1
	bgt @08002A92
	cmp r1, 0
	beq @08002A9C
	b @08002AAC
@08002A92:
	cmp r0, 0x2
	beq @08002AA4
	cmp r0, 0x3
	beq @08002AA8
	b @08002AAC
@08002A9C:
	movs r0, 0x1
	b @08002AAE
@08002AA0:
	movs r0, 0x4
	b @08002AAE
@08002AA4:
	movs r0, 0x10
	b @08002AAE
@08002AA8:
	movs r0, 0x40
	b @08002AAE
@08002AAC:
	movs r0, 0
@08002AAE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetBgMetricAffineMode

	thumb_func_start GetTileMapIndexFromCoords
; u32 GetTileMapIndexFromCoords(u32 x, u32 y, u32 screenSize, u32 screenWidth, u32 screenHeight)
GetTileMapIndexFromCoords: ; 8002AB4
	push {r4,lr}
	adds r4, r0, 0
	ldr r0, [sp, 0x8]
	subs r3, 0x1
	ands r4, r3
	subs r0, 0x1
	ands r1, r0
	cmp r2, 0x1
	beq @08002AD8
	cmp r2, 0x1
	ble @08002AE0
	cmp r2, 0x2
	beq @08002AE0
	cmp r2, 0x3
	bne @08002AE0
	cmp r1, 0x1F
	ble @08002AD8
	adds r1, 0x20
@08002AD8:
	cmp r4, 0x1F
	ble @08002AE0
	subs r4, 0x20
	adds r1, 0x20
@08002AE0:
	lsls r0, r1, 5
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetTileMapIndexFromCoords

	thumb_func_start CopyTileMapEntry
; void CopyTileMapEntry(u16 *src, u16 *dest, s32 palette1, u16 tileOffset, u32 palette2)
CopyTileMapEntry: ; 8002AEC
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r5, [sp, 0x10]
	cmp r2, 0x10
	beq @08002B14
	cmp r2, 0x10
	bgt @08002B34
	cmp r2, 0
	blt @08002B34
	ldrh r0, [r4]
	adds r0, r3
	ldr r3, =0x00000fff
	adds r1, r3, 0
	ands r0, r1
	adds r1, r2, r5
	lsls r1, 12
	b @08002B3A
	.pool
@08002B14:
	ldrh r1, [r6]
	movs r0, 0xFC
	lsls r0, 8
	ands r1, r0
	lsls r2, r5, 12
	adds r2, r1, r2
	ldrh r0, [r4]
	adds r0, r3
	ldr r3, =0x000003ff
	adds r1, r3, 0
	ands r0, r1
	orrs r0, r2
	b @08002B3C
	.pool
@08002B34:
	ldrh r0, [r4]
	adds r0, r3
	lsls r1, r5, 12
@08002B3A:
	adds r0, r1
@08002B3C:
	lsls r0, 16
	lsrs r1, r0, 16
	strh r1, [r6]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end CopyTileMapEntry

	thumb_func_start GetBgType
; u16 GetBgType(u8 bg)
GetBgType: ; 8002B48
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	adds r5, r4, 0
	bl GetBgMode
	lsls r0, 24
	lsrs r0, 24
	cmp r4, 0x2
	beq @08002B76
	cmp r4, 0x2
	ble @08002B66
	cmp r4, 0x3
	beq @08002B86
	b @08002B8E
@08002B66:
	cmp r5, 0
	blt @08002B8E
	cmp r0, 0x1
	bgt @08002B8E
	cmp r0, 0
	blt @08002B8E
@08002B72:
	movs r0, 0
	b @08002B90
@08002B76:
	cmp r0, 0
	beq @08002B72
	cmp r0, 0
	blt @08002B8E
	cmp r0, 0x2
	bgt @08002B8E
@08002B82:
	movs r0, 0x1
	b @08002B90
@08002B86:
	cmp r0, 0
	beq @08002B72
	cmp r0, 0x2
	beq @08002B82
@08002B8E:
	ldr r0, =0x0000ffff
@08002B90:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetBgType

	thumb_func_start IsInvalidBg_
; BOOL IsInvalidBg_(u8 bg)
IsInvalidBg_: ; 8002B9C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x3
	bhi @08002BAA
	movs r0, 0
	b @08002BAC
@08002BAA:
	movs r0, 0x1
@08002BAC:
	pop {r1}
	bx r1
	thumb_func_end IsInvalidBg_

	thumb_func_start IsTileMapOutsideWram
; BOOL IsTileMapOutsideWram(u8 bg)
IsTileMapOutsideWram: ; 8002BB0
	push {lr}
	lsls r0, 24
	ldr r1, =0x030008f8
	lsrs r0, 20
	adds r1, 0x4
	adds r0, r1
	ldr r1, [r0]
	ldr r0, =0x03008000
	cmp r1, r0
	bhi @08002BD4
	cmp r1, 0
	beq @08002BD4
	movs r0, 0
	b @08002BD6
	.pool
@08002BD4:
	movs r0, 0x1
@08002BD6:
	pop {r1}
	bx r1
	thumb_func_end IsTileMapOutsideWram
