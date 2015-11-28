	thumb_func_start lcd_io_copy_queue_clean
; void lcd_io_copy_queue_clean()
lcd_io_copy_queue_clean: ; 8000FE4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r2, 0
	ldr r7, =0x030008d8
	ldr r0, =0x030008d9
	mov r12, r0
	ldr r1, =0x030008da
	mov r8, r1
	ldr r6, =0x03000818
	movs r5, 0
	ldr r4, =0x03000878
	movs r3, 0xFF
@08000FFE:
	adds r0, r2, r6
	strb r5, [r0]
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x5F
	ble @08000FFE
	movs r0, 0
	strb r0, [r7]
	mov r1, r12
	strb r0, [r1]
	movs r0, 0
	mov r1, r8
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end lcd_io_copy_queue_clean

	thumb_func_start lcd_io_buffer_to_hardware
; void lcd_io_buffer_to_hardware(u8 reg)
lcd_io_buffer_to_hardware: ; 800103C
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x4
	bne @08001068
	ldr r2, =0x04000004
	ldrh r1, [r2]
	ldr r0, =0x0000ffe7
	ands r0, r1
	strh r0, [r2]
	ldr r1, =0x0300081c
	ldrh r0, [r2]
	ldrh r1, [r1]
	orrs r0, r1
	strh r0, [r2]
	b @08001076
	.pool
@08001068:
	movs r0, 0x80
	lsls r0, 19
	adds r0, r2, r0
	ldr r1, =0x03000818
	adds r1, r2, r1
	ldrh r1, [r1]
	strh r1, [r0]
@08001076:
	pop {r0}
	bx r0
	.pool
	thumb_func_end lcd_io_buffer_to_hardware

	thumb_func_start lcd_io_copy_queue_process
; void lcd_io_copy_queue_process()
lcd_io_copy_queue_process: ; 8001080
	push {r4,r5,lr}
	ldr r0, =0x030008d8
	ldrb r0, [r0]
	cmp r0, 0
	bne @080010A4
	movs r5, 0
@0800108C:
	ldr r0, =0x03000878
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq @080010A4
	bl lcd_io_buffer_to_hardware
	movs r0, 0xFF
	strb r0, [r4]
	adds r5, 0x1
	cmp r5, 0x5F
	ble @0800108C
@080010A4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end lcd_io_copy_queue_process

	thumb_func_start lcd_io_set
; void lcd_io_set(u8 reg, u16 value)
lcd_io_set: ; 80010B4
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	lsrs r1, 16
	cmp r4, 0x5F
	bhi @08001130
	ldr r0, =0x03000818
	adds r0, r4, r0
	strh r1, [r0]
	ldr r0, =0x04000006
	ldrh r1, [r0]
	movs r0, 0xFF
	ands r0, r1
	subs r0, 0xA1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x40
	bls @080010E8
	movs r0, 0x80
	lsls r0, 19
	ldrh r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq @080010FE
@080010E8:
	adds r0, r4, 0
	bl lcd_io_buffer_to_hardware
	b @08001130
	.pool
@080010F8:
	movs r0, 0
	strb r0, [r5]
	b @08001130
@080010FE:
	ldr r2, =0x030008d8
	movs r0, 0x1
	strb r0, [r2]
	movs r3, 0
	ldr r0, =0x03000878
	ldrb r1, [r0]
	adds r5, r2, 0
	adds r2, r0, 0
	cmp r1, 0xFF
	beq @08001128
	adds r1, r2, 0
@08001114:
	ldrb r0, [r1]
	cmp r0, r4
	beq @080010F8
	adds r1, 0x1
	adds r3, 0x1
	cmp r3, 0x5F
	bgt @08001128
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne @08001114
@08001128:
	adds r0, r3, r2
	movs r1, 0
	strb r4, [r0]
	strb r1, [r5]
@08001130:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end lcd_io_set

	thumb_func_start lcd_io_set_forced_blank
; void lcd_io_set_forced_blank(u8 reg, u16 value)
lcd_io_set_forced_blank: ; 8001140
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	lsls r1, 16
	lsrs r1, 16
	cmp r4, 0x5F
	bhi @080011A8
	ldr r0, =0x03000818
	adds r0, r4, r0
	strh r1, [r0]
	movs r0, 0x80
	lsls r0, 19
	ldrh r1, [r0]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq @08001176
	adds r0, r4, 0
	bl lcd_io_buffer_to_hardware
	b @080011A8
	.pool
@08001170:
	movs r0, 0
	strb r0, [r5]
	b @080011A8
@08001176:
	ldr r2, =0x030008d8
	movs r0, 0x1
	strb r0, [r2]
	movs r3, 0
	ldr r0, =0x03000878
	ldrb r1, [r0]
	adds r5, r2, 0
	adds r2, r0, 0
	cmp r1, 0xFF
	beq @080011A0
	adds r1, r2, 0
@0800118C:
	ldrb r0, [r1]
	cmp r0, r4
	beq @08001170
	adds r1, 0x1
	adds r3, 0x1
	cmp r3, 0x5F
	bgt @080011A0
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne @0800118C
@080011A0:
	adds r0, r3, r2
	movs r1, 0
	strb r4, [r0]
	strb r1, [r5]
@080011A8:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end lcd_io_set_forced_blank

	thumb_func_start lcd_io_get
; u16 lcd_io_get(u8 reg)
lcd_io_get: ; 80011B8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r1, 0x4
	bne @080011CC
	ldr r0, =0x04000004
	b @080011DE
	.pool
@080011CC:
	cmp r1, 0x6
	beq @080011DC
	ldr r0, =0x03000818
	adds r0, r1, r0
	ldrh r0, [r0]
	b @080011E0
	.pool
@080011DC:
	ldr r0, =0x04000006
@080011DE:
	ldrh r0, [r0]
@080011E0:
	pop {r1}
	bx r1
	.pool
	thumb_func_end lcd_io_get

	thumb_func_start lcd_io_set_bits
; void lcd_io_set_bits(u8 reg, u16 mask)
lcd_io_set_bits: ; 80011E8
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =0x03000818
	adds r1, r0, r1
	ldrh r1, [r1]
	orrs r1, r2
	lsls r1, 16
	lsrs r1, 16
	bl lcd_io_set
	pop {r0}
	bx r0
	.pool
	thumb_func_end lcd_io_set_bits

	thumb_func_start lcd_io_clear_bits
; void lcd_io_clear_bits(u8 reg, u16 mask)
lcd_io_clear_bits: ; 8001208
	push {lr}
	adds r2, r1, 0
	lsls r0, 24
	lsrs r0, 24
	lsls r2, 16
	ldr r1, =0x03000818
	adds r1, r0, r1
	ldrh r1, [r1]
	lsrs r2, 16
	bics r1, r2
	bl lcd_io_set
	pop {r0}
	bx r0
	.pool
	thumb_func_end lcd_io_clear_bits

	thumb_func_start update_hardware_IE
; void update_hardware_IE()
update_hardware_IE: ; 8001228
	push {r4,r5,lr}
	ldr r5, =0x030008d9
	ldrb r0, [r5]
	cmp r0, 0
	beq @08001246
	ldr r2, =0x04000208
	ldrh r1, [r2]
	movs r4, 0
	strh r4, [r2]
	ldr r3, =0x04000200
	ldr r0, =0x030008da
	ldrh r0, [r0]
	strh r0, [r3]
	strh r1, [r2]
	strb r4, [r5]
@08001246:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end update_hardware_IE

	thumb_func_start enable_irqs
; void enable_irqs(u16 value)
enable_irqs: ; 800125C
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =0x030008da
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r1, =0x030008d9
	movs r0, 0x1
	strb r0, [r1]
	bl update_hardware_IE
	ldrh r0, [r4]
	bl dispstat_set_vblank_hblank_irqs
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end enable_irqs

	thumb_func_start disable_irqs
; void disable_irqs(u16 value)
disable_irqs: ; 8001288
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r4, =0x030008da
	ldrh r1, [r4]
	bics r1, r0
	strh r1, [r4]
	ldr r1, =0x030008d9
	movs r0, 0x1
	strb r0, [r1]
	bl update_hardware_IE
	ldrh r0, [r4]
	bl dispstat_set_vblank_hblank_irqs
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end disable_irqs

	thumb_func_start dispstat_set_vblank_hblank_irqs
; void dispstat_set_vblank_hblank_irqs(u16 value)
dispstat_set_vblank_hblank_irqs: ; 80012B4
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	movs r0, 0x4
	bl lcd_io_get
	movs r2, 0x18
	ands r2, r0
	movs r1, 0x1
	ands r1, r4
	negs r0, r1
	orrs r0, r1
	asrs r1, r0, 31
	movs r0, 0x8
	ands r1, r0
	movs r0, 0x2
	ands r0, r4
	cmp r0, 0
	beq @080012E0
	movs r0, 0x10
	orrs r1, r0
@080012E0:
	cmp r2, r1
	beq @080012EA
	movs r0, 0x4
	bl lcd_io_set
@080012EA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end dispstat_set_vblank_hblank_irqs
