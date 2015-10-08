	thumb_func_start fboxes_set_ptr
@ void fboxes_set_ptr(struct fbox *ptr)
fboxes_set_ptr: @ 80045A4
	ldr r1, =0x03002f80
	str r0, [r1]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end fboxes_set_ptr

	thumb_func_start TextBox_ResetSomeField
@ void TextBox_ResetSomeField()
TextBox_ResetSomeField: @ 80045B0
	push {lr}
	ldr r1, =0x020201b0
	movs r2, 0
	ldr r3, =0x0000045c
	adds r0, r1, r3
_080045BA:
	strb r2, [r0, 0x1B]
	subs r0, 0x24
	cmp r0, r1
	bge _080045BA
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end TextBox_ResetSomeField

	thumb_func_start Print
@ int Print(u8 windowId, u8 fontId, int char_cursor, char x, char y, u8 a6, int a7)
Print: @ 80045D0
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
	bl remo_copy
	lsls r0, 16
	lsrs r0, 16
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end Print

	thumb_func_start remo_copy
@ int remo_copy(struct TextBox *x, u8 text_speed, int a3)
remo_copy: @ 800467C
	push {r4-r7,lr}
	adds r6, r0, 0
	mov r12, r2
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =0x03002f80
	ldr r0, [r0]
	cmp r0, 0
	bne _08004698
	movs r0, 0
	b _08004766
	.align 2, 0
	.pool
_08004698:
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
_080046AE:
	strb r2, [r0]
	subs r0, 0x1
	subs r1, 0x1
	cmp r1, 0
	bge _080046AE
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
	bl GenerateFontHalfRowLut
	cmp r5, 0xFF
	beq _08004718
	cmp r5, 0
	beq _08004718
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
	b _0800475E
	.align 2, 0
	.pool
_08004718:
	ldr r1, =0x0202018c
	movs r0, 0
	strb r0, [r1, 0x1D]
	movs r4, 0
	ldr r7, =0x000003ff
	b _08004732
	.align 2, 0
	.pool
_0800472C:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_08004732:
	cmp r4, r7
	bhi _08004740
	ldr r0, =0x0202018c
	bl fbox_exec
	cmp r0, 0x1
	bne _0800472C
_08004740:
	cmp r5, 0xFF
	beq _0800474E
	ldr r0, =0x0202018c
	ldrb r0, [r0, 0x4]
	movs r1, 0x2
	bl Window_CopyToVram
_0800474E:
	ldr r2, =0x020201b0
	ldrb r1, [r6, 0x4]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r1, 0
	strb r1, [r0, 0x1B]
_0800475E:
	ldr r1, =0x03002f84
	movs r0, 0
	strb r0, [r1]
	movs r0, 0x1
_08004766:
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end remo_copy

	thumb_func_start run_remoboxes
@ void run_remoboxes()
run_remoboxes: @ 8004778
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	ldr r0, =0x03002f84
	ldrb r0, [r0]
	cmp r0, 0
	bne _080047F6
	ldr r0, =0x020201b0
	movs r6, 0
	adds r5, r0, 0x4
	mov r8, r0
	movs r7, 0x1F
_08004790:
	ldrb r0, [r5, 0x17]
	cmp r0, 0
	beq _080047E8
	mov r0, r8
	bl fbox_exec
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x1
	beq _080047E4
	cmp r4, 0x1
	bgt _080047B8
	cmp r4, 0
	beq _080047BE
	b _080047E8
	.align 2, 0
	.pool
_080047B8:
	cmp r4, 0x3
	beq _080047C6
	b _080047E8
_080047BE:
	ldrb r0, [r5]
	movs r1, 0x2
	bl Window_CopyToVram
_080047C6:
	ldr r1, =0x020201b0
	adds r0, r1, 0
	adds r0, 0x10
	adds r0, r6, r0
	ldr r2, [r0]
	cmp r2, 0
	beq _080047E8
	adds r0, r6, r1
	adds r1, r4, 0
	bl _call_via_r2
	b _080047E8
	.align 2, 0
	.pool
_080047E4:
	movs r0, 0
	strb r0, [r5, 0x17]
_080047E8:
	adds r6, 0x24
	adds r5, 0x24
	movs r0, 0x24
	add r8, r0
	subs r7, 0x1
	cmp r7, 0
	bge _08004790
_080047F6:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end run_remoboxes

	thumb_func_start a_pressed_maybe
a_pressed_maybe: @ 8004800
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =0x020201b0
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x1B]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end a_pressed_maybe

	thumb_func_start fbox_exec
@ int fbox_exec(struct TextBox *x)
fbox_exec: @ 8004818
	push {r4,lr}
	adds r4, r0, 0
_0800481C:
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
	beq _0800481C
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end fbox_exec

	thumb_func_start GenerateFontHalfRowLut
GenerateFontHalfRowLut: @ 8004844
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
	.align 2, 0
	.pool
	thumb_func_end GenerateFontHalfRowLut

	thumb_func_start save_remo_colors
save_remo_colors: @ 8004BE0
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
	.align 2, 0
	.pool
	thumb_func_end save_remo_colors

	thumb_func_start restore_remo_colors
restore_remo_colors: @ 8004C00
	push {lr}
	ldrb r0, [r0]
	ldrb r1, [r1]
	ldrb r2, [r2]
	bl GenerateFontHalfRowLut
	pop {r0}
	bx r0
	thumb_func_end restore_remo_colors

	thumb_func_start DecompressGlyphTile
@ void DecompressGlyphTile(u16 *src, u32 *dest)
DecompressGlyphTile: @ 8004C10
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
	.align 2, 0
	.pool
	thumb_func_end DecompressGlyphTile

	thumb_func_start sub_8004D58
sub_8004D58: @ 8004D58
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x1
	beq _08004D8C
	cmp r0, 0x1
	bgt _08004D6E
	cmp r0, 0
	beq _08004D74
	b _08004D98
_08004D6E:
	cmp r1, 0x2
	beq _08004D80
	b _08004D98
_08004D74:
	ldr r0, =0x030009ec
	ldrb r0, [r0]
	b _08004D9A
	.align 2, 0
	.pool
_08004D80:
	ldr r0, =0x030009ea
	ldrb r0, [r0]
	b _08004D9A
	.align 2, 0
	.pool
_08004D8C:
	ldr r0, =0x030009ee
	ldrb r0, [r0]
	b _08004D9A
	.align 2, 0
	.pool
_08004D98:
	movs r0, 0
_08004D9A:
	pop {r1}
	bx r1
	thumb_func_end sub_8004D58

	thumb_func_start CopyGlyphToWindow
@ int CopyGlyphToWindow(struct TextBox *x)
CopyGlyphToWindow: @ 8004DA0
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
	ble _08004DD2
	adds r4, r0, 0
_08004DD2:
	ldrb r0, [r1, 0x4]
	lsls r0, 3
	ldrb r3, [r3, 0x9]
	subs r0, r3
	adds r1, r5, 0
	adds r1, 0x81
	ldrb r1, [r1]
	cmp r0, r1
	ble _08004DE6
	adds r0, r1, 0
_08004DE6:
	str r6, [sp]
	mov r8, r3
	adds r3, r5, 0
	ldr r2, [r2, 0x8]
	mov r9, r2
	lsls r1, r7, 5
	str r1, [sp, 0x4]
	cmp r4, 0x8
	ble _08004DFA
	b _08004F94
_08004DFA:
	cmp r0, 0x8
	bgt _08004E84
	mov r1, r8
	str r3, [sp, 0x8]
	adds r2, r6, 0
	adds r2, r4
	mov r8, r2
	adds r0, r1, r0
	str r0, [sp, 0xC]
	str r6, [sp, 0x10]
	cmp r1, r0
	bcc _08004E14
	b _080052AA
_08004E14:
	ldr r3, [sp, 0x8]
	ldm r3!, {r5}
	str r3, [sp, 0x8]
	ldr r4, [sp, 0x10]
	adds r0, r1, 0x1
	mov r10, r0
	cmp r4, r8
	bcs _08004E72
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
_08004E38:
	adds r3, r5, 0
	movs r0, 0xF
	ands r3, r0
	cmp r3, 0
	beq _08004E6A
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
_08004E6A:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc _08004E38
_08004E72:
	mov r1, r10
	ldr r2, [sp, 0xC]
	cmp r1, r2
	bcc _08004E14
	b _080052AA
	.align 2, 0
	.pool
_08004E84:
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
	bcs _08004F0E
_08004EA8:
	ldr r0, [sp, 0x14]
	ldm r0!, {r5}
	str r0, [sp, 0x14]
	ldr r4, [sp, 0x1C]
	adds r2, r1, 0x1
	mov r8, r2
	cmp r4, r12
	bcs _08004F06
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
_08004ECC:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq _08004EFE
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
_08004EFE:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r12
	bcc _08004ECC
_08004F06:
	mov r1, r8
	ldr r2, [sp, 0x18]
	cmp r1, r2
	bcc _08004EA8
_08004F0E:
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
	bcc _08004F28
	b _080052AA
_08004F28:
	ldr r0, [sp, 0x20]
	ldm r0!, {r5}
	str r0, [sp, 0x20]
	ldr r4, [sp, 0x28]
	adds r2, r1, 0x1
	mov r10, r2
	cmp r4, r8
	bcs _08004F86
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
_08004F4C:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq _08004F7E
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
_08004F7E:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc _08004F4C
_08004F86:
	mov r1, r10
	ldr r2, [sp, 0x24]
	cmp r1, r2
	bcc _08004F28
	b _080052AA
	.align 2, 0
	.pool
_08004F94:
	cmp r0, 0x8
	ble _08004F9A
	b _080050A4
_08004F9A:
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
	bcs _0800501C
_08004FBA:
	ldr r0, [sp, 0x2C]
	ldm r0!, {r5}
	str r0, [sp, 0x2C]
	ldr r4, [sp, 0x34]
	adds r2, r1, 0x1
	mov r10, r2
	cmp r4, r12
	bcs _08005014
	lsrs r0, r1, 3
	ldr r2, [sp, 0x4]
	adds r3, r0, 0
	muls r3, r2
	adds r7, r3, 0
	movs r3, 0x7
	ands r1, r3
	lsls r6, r1, 2
_08004FDA:
	adds r3, r5, 0
	movs r0, 0xF
	ands r3, r0
	cmp r3, 0
	beq _0800500C
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
_0800500C:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r12
	bcc _08004FDA
_08005014:
	mov r1, r10
	ldr r2, [sp, 0x30]
	cmp r1, r2
	bcc _08004FBA
_0800501C:
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
	bcc _08005038
	b _080052AA
_08005038:
	ldr r2, [sp, 0x38]
	ldm r2!, {r5}
	str r2, [sp, 0x38]
	ldr r4, [sp, 0x40]
	adds r3, r1, 0x1
	mov r10, r3
	cmp r4, r8
	bcs _08005096
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
_0800505C:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq _0800508E
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
_0800508E:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc _0800505C
_08005096:
	mov r1, r10
	ldr r2, [sp, 0x3C]
	cmp r1, r2
	bcc _08005038
	b _080052AA
	.align 2, 0
	.pool
_080050A4:
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
	bcs _0800512C
_080050CA:
	ldr r2, [sp, 0x44]
	ldm r2!, {r5}
	str r2, [sp, 0x44]
	ldr r4, [sp, 0x4C]
	adds r3, r1, 0x1
	mov r10, r3
	cmp r4, r12
	bcs _08005124
	lsrs r0, r1, 3
	ldr r3, [sp, 0x4]
	adds r2, r0, 0
	muls r2, r3
	adds r7, r2, 0
	movs r0, 0x7
	ands r1, r0
	lsls r6, r1, 2
_080050EA:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq _0800511C
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
_0800511C:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r12
	bcc _080050EA
_08005124:
	mov r1, r10
	ldr r2, [sp, 0x48]
	cmp r1, r2
	bcc _080050CA
_0800512C:
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
	bcs _080051AC
_08005146:
	ldr r2, [sp, 0x50]
	ldm r2!, {r5}
	str r2, [sp, 0x50]
	ldr r4, [sp, 0x58]
	adds r3, r1, 0x1
	mov r10, r3
	cmp r4, r8
	bcs _080051A4
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
_0800516A:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq _0800519C
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
_0800519C:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc _0800516A
_080051A4:
	mov r1, r10
	ldr r2, [sp, 0x54]
	cmp r1, r2
	bcc _08005146
_080051AC:
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
	bcs _0800522A
_080051C4:
	ldr r0, [sp, 0x5C]
	ldm r0!, {r5}
	str r0, [sp, 0x5C]
	ldr r4, [sp, 0x64]
	adds r2, r1, 0x1
	mov r10, r2
	cmp r4, r8
	bcs _08005222
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
_080051E8:
	adds r3, r5, 0
	movs r1, 0xF
	ands r3, r1
	cmp r3, 0
	beq _0800521A
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
_0800521A:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc _080051E8
_08005222:
	mov r1, r10
	ldr r2, [sp, 0x60]
	cmp r1, r2
	bcc _080051C4
_0800522A:
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
	bcs _080052AA
_08005244:
	ldr r3, [sp, 0x68]
	ldm r3!, {r5}
	str r3, [sp, 0x68]
	ldr r4, [sp, 0x70]
	adds r0, r1, 0x1
	mov r10, r0
	cmp r4, r8
	bcs _080052A2
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
_08005268:
	adds r3, r5, 0
	movs r0, 0xF
	ands r3, r0
	cmp r3, 0
	beq _0800529A
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
_0800529A:
	lsrs r5, 4
	adds r4, 0x1
	cmp r4, r8
	bcc _08005268
_080052A2:
	mov r1, r10
	ldr r2, [sp, 0x6C]
	cmp r1, r2
	bcc _08005244
_080052AA:
	add sp, 0x8C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end CopyGlyphToWindow

	thumb_func_start Text_ClearHorizontalSpan
@ void Text_ClearHorizontalSpan(TextBox *textBox, int width)
Text_ClearHorizontalSpan: @ 80052C8
	push {r4-r6,lr}
	sub sp, 0x10
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, =0x030009ea
	ldrh r5, [r0]
	cmp r5, 0
	beq _0800531E
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
	bl PixelBlock_FillRect4Bpp
_0800531E:
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end Text_ClearHorizontalSpan

	thumb_func_start Font0Func
@ int Font0Func(struct TextBox *x)
Font0Func: @ 800533C
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08005360
	ldrb r1, [r2, 0x14]
	movs r0, 0x10
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x14]
	ldrb r0, [r3, 0x1]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r3, 0x1]
_08005360:
	adds r0, r2, 0
	bl font_render_b
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font0Func

	thumb_func_start Font1Func
@ int Font1Func(struct TextBox *x)
Font1Func: @ 8005370
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08005398
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
_08005398:
	adds r0, r2, 0
	bl font_render_b
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font1Func

	thumb_func_start Font2Func
@ int Font2Func(struct TextBox *x)
Font2Func: @ 80053A8
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080053D0
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
_080053D0:
	adds r0, r2, 0
	bl font_render_b
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font2Func

	thumb_func_start Font3Func
@ int Font3Func(struct TextBox *x)
Font3Func: @ 80053E0
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08005408
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
_08005408:
	adds r0, r2, 0
	bl font_render_b
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font3Func

	thumb_func_start Font4Func
@ int Font4Func(struct TextBox *x)
Font4Func: @ 8005418
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08005440
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
_08005440:
	adds r0, r2, 0
	bl font_render_b
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font4Func

	thumb_func_start Font5Func
@ int Font5Func(struct TextBox *x)
Font5Func: @ 8005450
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _08005478
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
_08005478:
	adds r0, r2, 0
	bl font_render_b
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font5Func

	thumb_func_start Font7Func
@ int Font7Func(struct TextBox *x)
Font7Func: @ 8005488
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080054B0
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
_080054B0:
	adds r0, r2, 0
	bl font_render_b
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font7Func

	thumb_func_start Font8Func
@ int Font8Func(struct TextBox *x)
Font8Func: @ 80054C0
	push {lr}
	adds r2, r0, 0
	adds r3, r2, 0
	adds r3, 0x14
	ldrb r1, [r3, 0x1]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	bne _080054E8
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
_080054E8:
	adds r0, r2, 0
	bl font_render_b
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Font8Func

	thumb_func_start sub_80054F8
@ void sub_80054F8(TextBox *textBox)
sub_80054F8: @ 80054F8
	push {lr}
	adds r2, r0, 0
	adds r2, 0x14
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08005514
	movs r0, 0
	strb r0, [r2, 0x2]
	b _08005524
	.align 2, 0
	.pool
_08005514:
	ldrb r0, [r2, 0x1]
	movs r1, 0x61
	negs r1, r1
	ands r1, r0
	movs r0, 0x20
	negs r0, r0
	ands r1, r0
	strb r1, [r2, 0x1]
_08005524:
	pop {r0}
	bx r0
	thumb_func_end sub_80054F8

	thumb_func_start remo_draw_bouncing_down_arrow
@ int remo_draw_bouncing_down_arrow(TextBox *x)
remo_draw_bouncing_down_arrow: @ 8005528
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
	bne _080055EE
	ldrb r2, [r6, 0x1]
	movs r0, 0x1F
	ands r0, r2
	cmp r0, 0
	beq _08005560
	ldr r0, [r5, 0x14]
	lsls r0, 19
	lsrs r0, 27
	subs r0, 0x1
	movs r1, 0x1F
	ands r0, r1
	movs r1, 0x20
	negs r1, r1
	b _080055E8
	.align 2, 0
	.pool
_08005560:
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
	bl Window_FillPixelRect
	ldr r0, [r7]
	lsls r0, 30
	lsrs r0, 31
	cmp r0, 0
	beq _0800558A
	cmp r0, 0x1
	beq _08005594
_0800558A:
	ldr r7, =gDownArrowTiles
	b _08005596
	.align 2, 0
	.pool
_08005594:
	ldr r7, =gDarkDownArrowTiles
_08005596:
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
	bl Window_CopyPixelRectToWindow
	ldrb r0, [r5, 0x4]
	movs r1, 0x2
	bl Window_CopyToVram
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
_080055E8:
	ands r1, r2
	orrs r1, r0
	strb r1, [r6, 0x1]
_080055EE:
	add sp, 0x18
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end remo_draw_bouncing_down_arrow

	thumb_func_start remo_clear_down_arrow
@ int remo_clear_down_arrow(TextBox *x)
remo_clear_down_arrow: @ 8005600
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
	bl Window_FillPixelRect
	ldrb r0, [r5, 0x4]
	movs r1, 0x2
	bl Window_CopyToVram
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end remo_clear_down_arrow

	thumb_func_start remo_is_it_time_to_continue_autopilot
@ int remo_is_it_time_to_continue_autopilot(struct TextBox *x)
remo_is_it_time_to_continue_autopilot: @ 8005634
	push {lr}
	adds r1, r0, 0
	adds r1, 0x14
	ldrb r0, [r1, 0x2]
	cmp r0, 0x31
	beq _08005648
	adds r0, 0x1
	strb r0, [r1, 0x2]
	movs r0, 0
	b _0800564A
_08005648:
	movs r0, 0x1
_0800564A:
	pop {r1}
	bx r1
	thumb_func_end remo_is_it_time_to_continue_autopilot

	thumb_func_start remo_is_it_time_to_continue_plus_down_arrow
remo_is_it_time_to_continue_plus_down_arrow: @ 8005650
	push {r4,lr}
	adds r2, r0, 0
	movs r4, 0
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08005674
	adds r0, r2, 0
	bl remo_is_it_time_to_continue_autopilot
	lsls r0, 24
	lsrs r4, r0, 24
	b _0800568E
	.align 2, 0
	.pool
_08005674:
	adds r0, r2, 0
	bl remo_draw_bouncing_down_arrow
	ldr r0, =0x030022c0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0800568E
	movs r4, 0x1
	movs r0, 0x5
	bl audio_play
_0800568E:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end remo_is_it_time_to_continue_plus_down_arrow

	thumb_func_start remo_is_it_time_to_continue
remo_is_it_time_to_continue: @ 800569C
	push {r4,lr}
	adds r2, r0, 0
	movs r4, 0
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _080056C0
	adds r0, r2, 0
	bl remo_is_it_time_to_continue_autopilot
	lsls r0, 24
	lsrs r4, r0, 24
	b _080056D4
	.align 2, 0
	.pool
_080056C0:
	ldr r0, =0x030022c0
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _080056D4
	movs r4, 0x1
	movs r0, 0x5
	bl audio_play
_080056D4:
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end remo_is_it_time_to_continue

	thumb_func_start draw_bouncing_down_arrow_2
draw_bouncing_down_arrow_2: @ 80056E0
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
	beq _0800571A
	subs r0, 0x1
	strb r0, [r1]
	b _0800579A
_0800571A:
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
	bl Window_FillPixelRect
	cmp r4, 0
	bne _0800579A
	ldr r0, =0x03003014
	ldr r0, [r0]
	lsls r0, 30
	lsrs r0, 31
	cmp r0, 0
	beq _08005748
	cmp r0, 0x1
	beq _08005754
_08005748:
	ldr r6, =gDownArrowTiles
	b _08005756
	.align 2, 0
	.pool
_08005754:
	ldr r6, =gDarkDownArrowTiles
_08005756:
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
	bl Window_CopyPixelRectToWindow
	adds r0, r5, 0
	movs r1, 0x2
	bl Window_CopyToVram
	mov r1, r9
	strb r4, [r1]
	mov r5, r10
	ldrb r0, [r5]
	adds r0, 0x1
	strb r0, [r5]
_0800579A:
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end draw_bouncing_down_arrow_2

	thumb_func_start font_render_b
@ int font_render_b(struct TextBox *x)
font_render_b: @ 80057B4
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r4, r6, 0
	adds r4, 0x14
	ldrb r0, [r6, 0x1C]
	cmp r0, 0x6
	bls _080057C4
	b _08005D6C
_080057C4:
	lsls r0, 2
	ldr r1, =_080057D4
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_080057D4:
	.4byte _080057F0
	.4byte _08005C78
	.4byte _08005C8C
	.4byte _08005CB8
	.4byte _08005CF0
	.4byte _08005D48
	.4byte _08005D5A
_080057F0:
	ldr r2, =0x030022c0
	ldrh r1, [r2, 0x2C]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq _0800580A
	ldrb r1, [r4]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0800580A
	movs r0, 0
	strb r0, [r6, 0x1E]
_0800580A:
	ldrb r1, [r6, 0x1E]
	cmp r1, 0
	beq _0800584C
	ldrb r0, [r6, 0x1D]
	cmp r0, 0
	beq _0800584C
	subs r0, r1, 0x1
	strb r0, [r6, 0x1E]
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _08005828
	b _08005B56
_08005828:
	ldrh r1, [r2, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _08005834
	b _08005B56
_08005834:
	ldrb r0, [r4]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r4]
	movs r0, 0
	strb r0, [r6, 0x1E]
	b _08005B56
	.align 2, 0
	.pool
_0800584C:
	ldr r0, =0x02022fec
	ldr r0, [r0]
	movs r1, 0x80
	lsls r1, 17
	ands r0, r1
	cmp r0, 0
	bne _08005874
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _08005874
	movs r0, 0x3
	b _08005876
	.align 2, 0
	.pool
_08005874:
	ldrb r0, [r6, 0x1D]
_08005876:
	strb r0, [r6, 0x1E]
	ldr r0, [r6]
	ldrb r3, [r0]
	adds r0, 0x1
	str r0, [r6]
	adds r0, r3, 0
	subs r0, 0xF8
	cmp r0, 0x7
	bls _0800588A
	b _08005B90
_0800588A:
	lsls r0, 2
	ldr r1, =_08005898
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_08005898:
	.4byte _08005B6C
	.4byte _08005B5A
	.4byte _08005B4C
	.4byte _08005B48
	.4byte _080058E0
	.4byte _080058DC
	.4byte _080058B8
	.4byte _08005D6C
_080058B8:
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
	b _08005ABA
	.align 2, 0
	.pool
_080058DC:
	ldr r0, [r6]
	b _08005B30
_080058E0:
	ldr r0, [r6]
	ldrb r3, [r0]
	adds r0, 0x1
	str r0, [r6]
	subs r0, r3, 0x1
	cmp r0, 0x17
	bls _080058F0
	b _08005B90
_080058F0:
	lsls r0, 2
	ldr r1, =_08005900
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_08005900:
	.4byte _08005960
	.4byte _08005982
	.4byte _080059A6
	.4byte _080059C0
	.4byte _08005A0E
	.4byte _08005A12
	.4byte _08005A0A
	.4byte _08005A2A
	.4byte _08005A3A
	.4byte _08005A58
	.4byte _08005A5C
	.4byte _08005B5A
	.4byte _08005A90
	.4byte _08005A98
	.4byte _08005AA4
	.4byte _08005A76
	.4byte _08005AD8
	.4byte _08005AF2
	.4byte _08005B02
	.4byte _08005B26
	.4byte _08005B36
	.4byte _08005B3E
	.4byte _08005ABE
	.4byte _08005ACC
_08005960:
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
	b _08005A06
_08005982:
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
	b _08005A06
_080059A6:
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
	b _080059FE
_080059C0:
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
_080059FE:
	lsls r1, r2, 28
	lsrs r1, 28
	lsls r2, 24
	lsrs r2, 28
_08005A06:
	bl GenerateFontHalfRowLut
_08005A0A:
	movs r0, 0x2
	b _08005D6E
_08005A0E:
	ldr r0, [r6]
	b _08005B30
_08005A12:
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
	b _08005B30
_08005A2A:
	ldr r0, [r6]
	ldrb r1, [r0]
	strb r1, [r6, 0x1E]
	adds r0, 0x1
	str r0, [r6]
	movs r0, 0x6
	strb r0, [r6, 0x1C]
	b _08005A0A
_08005A3A:
	movs r0, 0x1
	strb r0, [r6, 0x1C]
	ldr r0, =0x03003014
	ldrb r1, [r0]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _08005A4C
	b _08005B56
_08005A4C:
	movs r0, 0
	strb r0, [r4, 0x2]
	b _08005B56
	.align 2, 0
	.pool
_08005A58:
	movs r0, 0x5
	b _08005D56
_08005A5C:
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
	b _08005A0A
_08005A76:
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
	b _08005A0A
_08005A90:
	ldr r1, [r6]
	ldrb r0, [r1]
	ldrb r3, [r6, 0x6]
	b _08005AF8
_08005A98:
	ldr r1, [r6]
	ldrb r0, [r1]
	ldrb r2, [r6, 0x7]
	adds r0, r2
	strb r0, [r6, 0x9]
	b _08005AFC
_08005AA4:
	ldrb r0, [r6, 0x4]
	ldrb r2, [r6, 0xD]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	bl Window_FastFillPixels
	ldrb r0, [r6, 0x6]
	strb r0, [r6, 0x8]
	ldrb r0, [r6, 0x7]
_08005ABA:
	strb r0, [r6, 0x9]
	b _08005A0A
_08005ABE:
	ldr r0, =0x03007420
	bl MPlayStop_rev01
	b _08005A0A
	.align 2, 0
	.pool
_08005ACC:
	ldr r0, =0x03007420
	bl m4aMPlayContinue
	b _08005A0A
	.align 2, 0
	.pool
_08005AD8:
	ldr r0, [r6]
	ldrb r4, [r0]
	adds r0, 0x1
	str r0, [r6]
	cmp r4, 0
	ble _08005A0A
	adds r0, r6, 0
	adds r1, r4, 0
	bl Text_ClearHorizontalSpan
	ldrb r0, [r6, 0x8]
	adds r0, r4
	b _08005C6E
_08005AF2:
	ldr r1, [r6]
	ldrb r0, [r6, 0x6]
	ldrb r3, [r1]
_08005AF8:
	adds r0, r3
	strb r0, [r6, 0x8]
_08005AFC:
	adds r1, 0x1
	str r1, [r6]
	b _08005A0A
_08005B02:
	ldr r0, [r6]
	ldrb r2, [r0]
	ldrb r1, [r6, 0x6]
	adds r2, r1
	adds r0, 0x1
	str r0, [r6]
	ldrb r0, [r6, 0x8]
	subs r4, r2, r0
	cmp r4, 0
	bgt _08005B18
	b _08005A0A
_08005B18:
	adds r0, r6, 0
	adds r1, r4, 0
	bl Text_ClearHorizontalSpan
	ldrb r0, [r6, 0x8]
	adds r0, r4
	b _08005C6E
_08005B26:
	ldr r0, [r6]
	ldrb r2, [r0]
	adds r1, r6, 0
	adds r1, 0x20
	strb r2, [r1]
_08005B30:
	adds r0, 0x1
	str r0, [r6]
	b _08005A0A
_08005B36:
	adds r1, r6, 0
	adds r1, 0x21
	movs r0, 0x1
	b _08005B44
_08005B3E:
	adds r1, r6, 0
	adds r1, 0x21
	movs r0, 0
_08005B44:
	strb r0, [r1]
	b _08005A0A
_08005B48:
	movs r0, 0x2
	b _08005B4E
_08005B4C:
	movs r0, 0x3
_08005B4E:
	strb r0, [r6, 0x1C]
	adds r0, r6, 0
	bl sub_80054F8
_08005B56:
	movs r0, 0x3
	b _08005D6E
_08005B5A:
	ldr r0, [r6]
	ldrb r3, [r0]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	orrs r3, r1
	adds r0, 0x1
	str r0, [r6]
	b _08005B90
_08005B6C:
	ldr r0, [r6]
	ldrb r3, [r0]
	adds r0, 0x1
	str r0, [r6]
	ldrb r0, [r6, 0x4]
	adds r1, r3, 0
	ldrb r2, [r6, 0x8]
	ldrb r3, [r6, 0x9]
	bl TextBox_DrawKeypadIcon
	ldr r1, =0x03002f90
	adds r1, 0x80
	strb r0, [r1]
	ldrb r3, [r6, 0xA]
	adds r0, r3
	b _08005C6A
	.align 2, 0
	.pool
_08005B90:
	ldr r0, [r4]
	lsls r0, 28
	lsrs r0, 28
	cmp r0, 0x8
	bhi _08005C10
	lsls r0, 2
	ldr r1, =_08005BA8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_08005BA8:
	.4byte _08005BCC
	.4byte _08005BDA
	.4byte _08005BE8
	.4byte _08005BE8
	.4byte _08005BE8
	.4byte _08005BE8
	.4byte _08005C10
	.4byte _08005BF6
	.4byte _08005C04
_08005BCC:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r1, [r0]
	adds r0, r3, 0
	bl DecompressGlyphFont0
	b _08005C10
_08005BDA:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r1, [r0]
	adds r0, r3, 0
	bl DecompressGlyphFont1
	b _08005C10
_08005BE8:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r1, [r0]
	adds r0, r3, 0
	bl DecompressGlyphFont2
	b _08005C10
_08005BF6:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r1, [r0]
	adds r0, r3, 0
	bl DecompressGlyphFont7
	b _08005C10
_08005C04:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r1, [r0]
	adds r0, r3, 0
	bl DecompressGlyphFont8
_08005C10:
	adds r0, r6, 0
	bl CopyGlyphToWindow
	adds r2, r6, 0
	adds r2, 0x20
	ldrb r0, [r2]
	cmp r0, 0
	beq _08005C48
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
	ble _08005C70
	adds r0, r6, 0
	adds r1, r4, 0
	bl Text_ClearHorizontalSpan
	ldrb r0, [r6, 0x8]
	adds r0, r4
	b _08005C6E
	.align 2, 0
	.pool
_08005C48:
	adds r0, r6, 0
	adds r0, 0x21
	ldrb r0, [r0]
	cmp r0, 0
	beq _08005C64
	ldr r0, =0x03002f90
	adds r0, 0x80
	ldrb r1, [r6, 0xA]
	ldrb r0, [r0]
	adds r1, r0
	ldrb r0, [r6, 0x8]
	b _08005C6C
	.align 2, 0
	.pool
_08005C64:
	ldr r0, =0x03002f90
	adds r0, 0x80
	ldrb r0, [r0]
_08005C6A:
	ldrb r1, [r6, 0x8]
_08005C6C:
	adds r0, r1
_08005C6E:
	strb r0, [r6, 0x8]
_08005C70:
	movs r0, 0
	b _08005D6E
	.align 2, 0
	.pool
_08005C78:
	adds r0, r6, 0
	bl remo_is_it_time_to_continue
	lsls r0, 16
	cmp r0, 0
	bne _08005C86
	b _08005B56
_08005C86:
	movs r0, 0
	strb r0, [r6, 0x1C]
	b _08005B56
_08005C8C:
	adds r0, r6, 0
	bl remo_is_it_time_to_continue_plus_down_arrow
	lsls r0, 16
	cmp r0, 0
	bne _08005C9A
	b _08005B56
_08005C9A:
	ldrb r0, [r6, 0x4]
	ldrb r2, [r6, 0xD]
	lsls r2, 28
	lsrs r1, r2, 4
	orrs r1, r2
	lsrs r1, 24
	bl Window_FastFillPixels
	ldrb r0, [r6, 0x6]
	movs r1, 0
	strb r0, [r6, 0x8]
	ldrb r0, [r6, 0x7]
	strb r0, [r6, 0x9]
	strb r1, [r6, 0x1C]
	b _08005B56
_08005CB8:
	adds r0, r6, 0
	bl remo_is_it_time_to_continue_plus_down_arrow
	lsls r0, 16
	cmp r0, 0
	bne _08005CC6
	b _08005B56
_08005CC6:
	adds r0, r6, 0
	bl remo_clear_down_arrow
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
	b _08005B56
	.align 2, 0
	.pool
_08005CF0:
	ldrb r0, [r6, 0x1F]
	cmp r0, 0
	beq _08005D44
	bl sub_8197964
	ldr r1, =gWindowVerticalScrollSpeeds
	adds r0, r1
	ldrb r4, [r0]
	ldrb r2, [r6, 0x1F]
	cmp r2, r4
	bge _08005D20
	ldrb r0, [r6, 0x4]
	ldrb r1, [r6, 0xD]
	lsls r1, 28
	lsrs r3, r1, 4
	orrs r3, r1
	lsrs r3, 24
	movs r1, 0
	bl Window_ScrollVertically
	movs r0, 0
	b _08005D38
	.align 2, 0
	.pool
_08005D20:
	ldrb r0, [r6, 0x4]
	ldrb r1, [r6, 0xD]
	lsls r1, 28
	lsrs r3, r1, 4
	orrs r3, r1
	lsrs r3, 24
	movs r1, 0
	adds r2, r4, 0
	bl Window_ScrollVertically
	ldrb r0, [r6, 0x1F]
	subs r0, r4
_08005D38:
	strb r0, [r6, 0x1F]
	ldrb r0, [r6, 0x4]
	movs r1, 0x2
	bl Window_CopyToVram
	b _08005B56
_08005D44:
	strb r0, [r6, 0x1C]
	b _08005B56
_08005D48:
	bl mplay_has_finished_maybe
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _08005D56
	b _08005B56
_08005D56:
	strb r0, [r6, 0x1C]
	b _08005B56
_08005D5A:
	ldrb r0, [r6, 0x1E]
	adds r1, r0, 0
	cmp r1, 0
	beq _08005D68
	subs r0, 0x1
	strb r0, [r6, 0x1E]
	b _08005B56
_08005D68:
	strb r1, [r6, 0x1C]
	b _08005B56
_08005D6C:
	movs r0, 0x1
_08005D6E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end font_render_b

	thumb_func_start sub_8005D74
sub_8005D74: @ 8005D74
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
_08005D8C:
	strb r2, [r1]
	subs r1, 0x1
	cmp r1, sp
	bge _08005D8C
	movs r5, 0
	movs r6, 0
	adds r4, r0, 0
	movs r2, 0
_08005D9C:
	adds r0, r4, r2
	ldrb r3, [r0]
	adds r2, 0x1
	adds r0, r3, 0
	subs r0, 0xF7
	cmp r0, 0x8
	bhi _08005E6A
	lsls r0, 2
	ldr r1, =_08005DB8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_08005DB8:
	.4byte _08005E64
	.4byte _08005E68
	.4byte _08005E68
	.4byte _08005E70
	.4byte _08005E70
	.4byte _08005DEC
	.4byte _08005E64
	.4byte _08005DDC
	.4byte _08005DDC
_08005DDC:
	mov r1, sp
	adds r0, r1, r6
	strb r5, [r0]
	movs r5, 0
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	b _08005E70
_08005DEC:
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r2, 0x1
	subs r0, 0x1
	cmp r0, 0x15
	bhi _08005E70
	lsls r0, 2
	ldr r1, =_08005E08
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_08005E08:
	.4byte _08005E64
	.4byte _08005E64
	.4byte _08005E64
	.4byte _08005E60
	.4byte _08005E64
	.4byte _08005E64
	.4byte _08005E70
	.4byte _08005E64
	.4byte _08005E70
	.4byte _08005E70
	.4byte _08005E62
	.4byte _08005E64
	.4byte _08005E64
	.4byte _08005E64
	.4byte _08005E70
	.4byte _08005E62
	.4byte _08005E64
	.4byte _08005E64
	.4byte _08005E64
	.4byte _08005E64
	.4byte _08005E70
	.4byte _08005E70
_08005E60:
	adds r2, 0x1
_08005E62:
	adds r2, 0x1
_08005E64:
	adds r2, 0x1
	b _08005E70
_08005E68:
	adds r2, 0x1
_08005E6A:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_08005E70:
	cmp r3, 0xFF
	bne _08005D9C
	movs r5, 0
	movs r2, 0
_08005E78:
	mov r1, sp
	adds r0, r1, r2
	ldrb r1, [r0]
	cmp r5, r1
	bcs _08005E84
	ldrb r5, [r0]
_08005E84:
	adds r2, 0x1
	cmp r2, 0x7
	ble _08005E78
	adds r0, r7, 0
	movs r1, 0
	bl fbox_get_field
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
	thumb_func_end sub_8005D74

	thumb_func_start GetFontWidthFunc
GetFontWidthFunc: @ 8005EA8
	push {r4,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	movs r3, 0
	ldr r0, =gGlyphWidthFuncs
	adds r2, r0, 0x4
	adds r1, r0, 0
_08005EB6:
	ldr r0, [r1]
	cmp r4, r0
	bne _08005EC4
	ldr r0, [r2]
	b _08005ED0
	.align 2, 0
	.pool
_08005EC4:
	adds r2, 0x8
	adds r1, 0x8
	adds r3, 0x1
	cmp r3, 0x8
	bls _08005EB6
	movs r0, 0
_08005ED0:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetFontWidthFunc

	thumb_func_start font_get_width_of_string
@ unsigned int font_get_width_of_string(u8 a1, u8 *s, u16 a3)
font_get_width_of_string: @ 8005ED8
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
	bne _08005F06
_08005F02:
	movs r0, 0
	b _0800612E
_08005F06:
	lsls r0, r5, 16
	asrs r2, r0, 16
	movs r1, 0x1
	negs r1, r1
	str r0, [sp, 0x4]
	cmp r2, r1
	bne _08005F24
	adds r0, r6, 0
	movs r1, 0x2
	bl fbox_get_field
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	b _08005F26
_08005F24:
	mov r10, r2
_08005F26:
	movs r2, 0
	str r2, [sp]
	movs r5, 0
	movs r6, 0
	b _0800611E
_08005F30:
	ldrb r1, [r4]
	adds r0, r1, 0
	subs r0, 0xF7
	cmp r0, 0x7
	bls _08005F3C
	b _080060F8
_08005F3C:
	lsls r0, 2
	ldr r1, =_08005F4C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_08005F4C:
	.4byte _08005FA2
	.4byte _080060BC
	.4byte _080060BC
	.4byte _0800611C
	.4byte _0800611C
	.4byte _08005FEA
	.4byte _08005F78
	.4byte _08005F6C
_08005F6C:
	ldr r0, [sp]
	cmp r5, r0
	bls _08005F74
	str r5, [sp]
_08005F74:
	movs r5, 0
	b _0800611C
_08005F78:
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, 0x3
	beq _08005F98
	cmp r0, 0x3
	bgt _08005F8A
	cmp r0, 0x2
	beq _08005F90
	b _08005F02
_08005F8A:
	cmp r0, 0x4
	beq _08005FA0
	b _08005F02
_08005F90:
	ldr r6, =0x02021cc4
	b _08005FA2
	.align 2, 0
	.pool
_08005F98:
	ldr r6, =0x02021dc4
	b _08005FA2
	.align 2, 0
	.pool
_08005FA0:
	ldr r6, =0x02021ec4
_08005FA2:
	cmp r6, 0
	bne _08005FE0
	adds r4, 0x1
	ldrb r0, [r4]
	bl sub_81AFC74
	adds r6, r0, 0
	b _08005FE0
	.align 2, 0
	.pool
_08005FB8:
	ldrb r0, [r6]
	adds r6, 0x1
	mov r1, r9
	bl _call_via_r8
	cmp r7, 0
	ble _08005FD0
	cmp r0, r7
	bge _08005FCC
	adds r0, r7, 0
_08005FCC:
	adds r5, r0
	b _08005FE0
_08005FD0:
	adds r5, r0
	mov r2, r9
	cmp r2, 0
	beq _08005FE0
	ldrb r0, [r4, 0x1]
	cmp r0, 0xFF
	beq _08005FE0
	add r5, r10
_08005FE0:
	ldrb r0, [r6]
	cmp r0, 0xFF
	bne _08005FB8
	movs r6, 0
	b _0800611C
_08005FEA:
	adds r4, 0x1
	ldrb r0, [r4]
	subs r0, 0x1
	cmp r0, 0x15
	bls _08005FF6
	b _0800611C
_08005FF6:
	lsls r0, 2
	ldr r1, =_08006004
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_08006004:
	.4byte _08006060
	.4byte _08006060
	.4byte _08006060
	.4byte _0800605C
	.4byte _08006060
	.4byte _08006064
	.4byte _0800611C
	.4byte _08006060
	.4byte _0800611C
	.4byte _0800611C
	.4byte _0800605E
	.4byte _08006060
	.4byte _08006060
	.4byte _08006060
	.4byte _0800611C
	.4byte _0800605E
	.4byte _08006090
	.4byte _08006098
	.4byte _0800609E
	.4byte _080060AA
	.4byte _080060B0
	.4byte _080060B6
_0800605C:
	adds r4, 0x1
_0800605E:
	adds r4, 0x1
_08006060:
	adds r4, 0x1
	b _0800611C
_08006064:
	adds r4, 0x1
	ldrb r0, [r4]
	bl GetFontWidthFunc
	mov r8, r0
	cmp r0, 0
	bne _08006074
	b _08005F02
_08006074:
	ldr r0, [sp, 0x4]
	asrs r1, r0, 16
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	bne _0800611C
	ldrb r0, [r4]
	movs r1, 0x2
	bl fbox_get_field
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	b _0800611C
_08006090:
	adds r4, 0x1
	ldrb r0, [r4]
_08006094:
	adds r5, r0
	b _0800611C
_08006098:
	adds r4, 0x1
	ldrb r5, [r4]
	b _0800611C
_0800609E:
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, r5
	bls _0800611C
	adds r5, r0, 0
	b _0800611C
_080060AA:
	adds r4, 0x1
	ldrb r7, [r4]
	b _0800611C
_080060B0:
	movs r2, 0x1
	mov r9, r2
	b _0800611C
_080060B6:
	movs r0, 0
	mov r9, r0
	b _0800611C
_080060BC:
	ldrb r0, [r4]
	cmp r0, 0xF9
	bne _080060D6
	adds r4, 0x1
	ldrb r0, [r4]
	movs r2, 0x80
	lsls r2, 1
	adds r1, r2, 0
	orrs r0, r1
	mov r1, r9
	bl _call_via_r8
	b _080060E2
_080060D6:
	adds r4, 0x1
	ldrb r0, [r4]
	bl Font_ReturnsValueFromLUT
	lsls r0, 24
	lsrs r0, 24
_080060E2:
	cmp r7, 0
	ble _080060EE
	cmp r0, r7
	bge _08006094
	adds r0, r7, 0
	b _08006094
_080060EE:
	adds r5, r0
	mov r0, r9
	cmp r0, 0
	beq _0800611C
	b _08006114
_080060F8:
	adds r0, r1, 0
	mov r1, r9
	bl _call_via_r8
	cmp r7, 0
	ble _0800610C
	cmp r0, r7
	bge _08006094
	adds r0, r7, 0
	b _08006094
_0800610C:
	adds r5, r0
	mov r2, r9
	cmp r2, 0
	beq _0800611C
_08006114:
	ldrb r0, [r4, 0x1]
	cmp r0, 0xFF
	beq _0800611C
	add r5, r10
_0800611C:
	adds r4, 0x1
_0800611E:
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _08006126
	b _08005F30
_08006126:
	ldr r0, [sp]
	cmp r5, r0
	bls _0800612E
	adds r0, r5, 0
_0800612E:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end font_get_width_of_string

	thumb_func_start font_render_some
@ int font_render_some(char *pixels, u8 font, int a3)
font_render_some: @ 8006140
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
	bl save_remo_colors
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	movs r0, 0x3
	mov r10, r0
	movs r0, 0x1
	movs r1, 0
	movs r2, 0x3
	bl GenerateFontHalfRowLut
	adds r7, r6, 0
	movs r6, 0
_08006182:
	adds r0, r7, r6
	ldrb r0, [r0]
	mov r8, r0
	adds r6, 0x1
	subs r0, 0xF7
	cmp r0, 0x8
	bhi _0800627E
	lsls r0, 2
	ldr r1, =_080061A0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_080061A0:
	.4byte _08006276
	.4byte _08006276
	.4byte _08006276
	.4byte _080062B8
	.4byte _080062B8
	.4byte _080061C4
	.4byte _08006276
	.4byte _080062B8
	.4byte _080062B8
_080061C4:
	adds r0, r7, r6
	ldrb r0, [r0]
	adds r6, 0x1
	subs r0, 0x1
	cmp r0, 0x15
	bhi _080062B8
	lsls r0, 2
	ldr r1, =_080061E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_080061E0:
	.4byte _0800624A
	.4byte _08006254
	.4byte _0800625C
	.4byte _08006238
	.4byte _08006276
	.4byte _08006270
	.4byte _080062B8
	.4byte _08006276
	.4byte _080062B8
	.4byte _080062B8
	.4byte _0800627A
	.4byte _08006276
	.4byte _08006276
	.4byte _08006276
	.4byte _080062B8
	.4byte _0800627A
	.4byte _08006276
	.4byte _08006276
	.4byte _08006276
	.4byte _08006276
	.4byte _080062B8
	.4byte _080062B8
_08006238:
	adds r0, r7, r6
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	adds r6, 0x1
	adds r0, r7, r6
	ldrb r0, [r0]
	str r0, [sp, 0xC]
	adds r6, 0x1
	b _0800625C
_0800624A:
	adds r0, r7, r6
	ldrb r0, [r0]
	str r0, [sp, 0x8]
	adds r6, 0x1
	b _08006266
_08006254:
	adds r0, r7, r6
	ldrb r0, [r0]
	str r0, [sp, 0xC]
	b _08006262
_0800625C:
	adds r0, r7, r6
	ldrb r0, [r0]
	mov r10, r0
_08006262:
	adds r6, 0x1
	ldr r0, [sp, 0x8]
_08006266:
	ldr r1, [sp, 0xC]
	mov r2, r10
	bl GenerateFontHalfRowLut
	b _080062B8
_08006270:
	adds r0, r7, r6
	ldrb r0, [r0]
	str r0, [sp, 0x4]
_08006276:
	adds r6, 0x1
	b _080062B8
_0800627A:
	adds r6, 0x1
	b _08006276
_0800627E:
	ldr r0, [sp, 0x4]
	cmp r0, 0x1
	beq _08006290
	cmp r0, 0x9
	bne _08006290
	mov r0, r8
	bl DecompressGlyphFont9
	b _08006298
_08006290:
	mov r0, r8
	movs r1, 0x1
	bl DecompressGlyphFont1
_08006298:
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
_080062B8:
	mov r0, r8
	cmp r0, 0xFF
	beq _080062C0
	b _08006182
_080062C0:
	mov r0, sp
	mov r1, sp
	adds r1, 0x1
	mov r2, sp
	adds r2, 0x2
	bl restore_remo_colors
	movs r0, 0x1
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end font_render_some

	thumb_func_start TextBox_DrawKeypadIcon
TextBox_DrawKeypadIcon: @ 80062E8
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
	bl Window_CopyPixelRectToWindow
	adds r0, r4, 0
	add sp, 0x18
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end TextBox_DrawKeypadIcon

	thumb_func_start sub_8006338
sub_8006338: @ 8006338
	lsls r0, 24
	ldr r1, =gKeypadIcons
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end sub_8006338

	thumb_func_start Font_ReturnsValueFromLUT
Font_ReturnsValueFromLUT: @ 8006348
	lsls r0, 24
	ldr r1, =gKeypadIcons
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0, 0x2]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end Font_ReturnsValueFromLUT

	thumb_func_start sub_8006358
sub_8006358: @ 8006358
	lsls r0, 24
	ldr r1, =gKeypadIcons
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0, 0x3]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end sub_8006358

	thumb_func_start fboxes_set_default_ptr
fboxes_set_default_ptr: @ 8006368
	push {lr}
	ldr r0, =gFontInfos
	bl fboxes_set_ptr
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end fboxes_set_default_ptr

	thumb_func_start fbox_get_field
fbox_get_field: @ 8006378
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	cmp r1, 0x7
	bhi _08006456
	lsls r0, r1, 2
	ldr r1, =_08006398
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
	.pool
	.align 2, 0
_08006398:
	.4byte _080063B8
	.4byte _080063CC
	.4byte _080063E0
	.4byte _080063F4
	.4byte _08006408
	.4byte _0800641C
	.4byte _08006430
	.4byte _08006448
_080063B8:
	ldr r1, =gFontInfos
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x4]
	b _08006456
	.align 2, 0
	.pool
_080063CC:
	ldr r1, =gFontInfos
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x5]
	b _08006456
	.align 2, 0
	.pool
_080063E0:
	ldr r1, =gFontInfos
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x6]
	b _08006456
	.align 2, 0
	.pool
_080063F4:
	ldr r1, =gFontInfos
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x7]
	b _08006456
	.align 2, 0
	.pool
_08006408:
	ldr r0, =gFontInfos
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x8]
	b _0800643C
	.align 2, 0
	.pool
_0800641C:
	ldr r0, =gFontInfos
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x8]
	b _08006454
	.align 2, 0
	.pool
_08006430:
	ldr r0, =gFontInfos
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x9]
_0800643C:
	lsls r0, 28
	lsrs r0, 28
	b _08006456
	.align 2, 0
	.pool
_08006448:
	ldr r0, =gFontInfos
	lsls r1, r2, 1
	adds r1, r2
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x9]
_08006454:
	lsrs r0, 4
_08006456:
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end fbox_get_field

	thumb_func_start GetMenuCursorDimensionByFont
@ u8 GetMenuCursorDimensionByFont(u8 fontId, u8 whichDimension)
GetMenuCursorDimensionByFont: @ 8006460
	lsls r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gMenuCursorDimensions
	lsrs r0, 23
	adds r1, r0
	adds r1, r2
	ldrb r0, [r1]
	bx lr
	.align 2, 0
	.pool
	thumb_func_end GetMenuCursorDimensionByFont

	thumb_func_start DecompressGlyphFont0
DecompressGlyphFont0: @ 8006478
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r1, 0x1
	bne _080064C4
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
	b _08006534
	.align 2, 0
	.pool
_080064C4:
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
	bhi _08006500
	adds r0, r5, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	b _0800652C
	.align 2, 0
	.pool
_08006500:
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
_0800652C:
	ldr r0, =0x03002f90
	adds r0, 0x81
	movs r1, 0xD
	strb r1, [r0]
_08006534:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end DecompressGlyphFont0

	thumb_func_start GetGlyphWidthFont0
GetGlyphWidthFont0: @ 8006540
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, 0x1
	beq _08006558
	ldr r0, =gFont0LatinGlyphWidths
	adds r0, r2, r0
	ldrb r0, [r0]
	b _0800655A
	.align 2, 0
	.pool
_08006558:
	movs r0, 0x8
_0800655A:
	pop {r1}
	bx r1
	thumb_func_end GetGlyphWidthFont0

	thumb_func_start DecompressGlyphFont7
DecompressGlyphFont7: @ 8006560
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r1, 0x1
	bne _080065AC
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
	b _0800661C
	.align 2, 0
	.pool
_080065AC:
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
	bhi _080065E8
	adds r0, r6, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r6, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	b _08006614
	.align 2, 0
	.pool
_080065E8:
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
_08006614:
	ldr r0, =0x03002f90
	adds r0, 0x81
	movs r1, 0xF
	strb r1, [r0]
_0800661C:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end DecompressGlyphFont7

	thumb_func_start GetGlyphWidthFont7
GetGlyphWidthFont7: @ 8006628
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, 0x1
	beq _08006640
	ldr r0, =gFont7LatinGlyphWidths
	adds r0, r2, r0
	ldrb r0, [r0]
	b _08006642
	.align 2, 0
	.pool
_08006640:
	movs r0, 0x8
_08006642:
	pop {r1}
	bx r1
	thumb_func_end GetGlyphWidthFont7

	thumb_func_start DecompressGlyphFont8
@ void DecompressGlyphFont8(u16 glyphIndex, bool japanese)
DecompressGlyphFont8: @ 8006648
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r1, 0x1
	bne _08006694
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
	b _08006704
	.align 2, 0
	.pool
_08006694:
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
	bhi _080066D0
	adds r0, r5, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r5, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	b _080066FC
	.align 2, 0
	.pool
_080066D0:
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
_080066FC:
	ldr r0, =0x03002f90
	adds r0, 0x81
	movs r1, 0xC
	strb r1, [r0]
_08006704:
	pop {r4,r5}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end DecompressGlyphFont8

	thumb_func_start GetGlyphWidthFont8
GetGlyphWidthFont8: @ 8006710
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, 0x1
	beq _08006728
	ldr r0, =gFont8LatinGlyphWidths
	adds r0, r2, r0
	ldrb r0, [r0]
	b _0800672A
	.align 2, 0
	.pool
_08006728:
	movs r0, 0x8
_0800672A:
	pop {r1}
	bx r1
	thumb_func_end GetGlyphWidthFont8

	thumb_func_start DecompressGlyphFont2
DecompressGlyphFont2: @ 8006730
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r1, 0x1
	bne _080067A0
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
	b _08006810
	.align 2, 0
	.pool
_080067A0:
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
	bhi _080067DC
	adds r0, r4, 0
	adds r1, r5, 0
	bl DecompressGlyphTile
	adds r0, r4, 0
	adds r0, 0x20
	adds r1, r5, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	b _08006808
	.align 2, 0
	.pool
_080067DC:
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
_08006808:
	ldr r0, =0x03002f90
	adds r0, 0x81
	movs r1, 0xE
	strb r1, [r0]
_08006810:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end DecompressGlyphFont2

	thumb_func_start GetGlyphWidthFont2
GetGlyphWidthFont2: @ 800681C
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, 0x1
	beq _08006830
	ldr r0, =gFont2LatinGlyphWidths
	b _08006832
	.align 2, 0
	.pool
_08006830:
	ldr r0, =gFont2JapaneseGlyphWidths
_08006832:
	adds r0, r2, r0
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
	.pool
	thumb_func_end GetGlyphWidthFont2

	thumb_func_start DecompressGlyphFont1
@ void DecompressGlyphFont1(int a1, int japanese)
DecompressGlyphFont1: @ 8006840
	push {r4-r6,lr}
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r1, 0x1
	bne _0800688C
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
	b _080068FC
	.align 2, 0
	.pool
_0800688C:
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
	bhi _080068C8
	adds r0, r6, 0
	adds r1, r4, 0
	bl DecompressGlyphTile
	adds r0, r6, 0
	adds r0, 0x20
	adds r1, r4, 0
	adds r1, 0x40
	bl DecompressGlyphTile
	b _080068F4
	.align 2, 0
	.pool
_080068C8:
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
_080068F4:
	ldr r0, =0x03002f90
	adds r0, 0x81
	movs r1, 0xF
	strb r1, [r0]
_080068FC:
	pop {r4-r6}
	pop {r0}
	bx r0
	.align 2, 0
	.pool
	thumb_func_end DecompressGlyphFont1

	thumb_func_start GetGlyphWidthFont1
GetGlyphWidthFont1: @ 8006908
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, 0x1
	beq _08006920
	ldr r0, =gFont1LatinGlyphWidths
	adds r0, r2, r0
	ldrb r0, [r0]
	b _08006922
	.align 2, 0
	.pool
_08006920:
	movs r0, 0x8
_08006922:
	pop {r1}
	bx r1
	thumb_func_end GetGlyphWidthFont1

	thumb_func_start DecompressGlyphFont9
DecompressGlyphFont9: @ 8006928
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r4, r0, 20
	lsls r4, 9
	movs r1, 0xF0
	lsls r1, 12
	ands r1, r0
	lsrs r1, 12
	ldr r0, =0x082ea61c
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
	.align 2, 0
	.pool
	thumb_func_end DecompressGlyphFont9
