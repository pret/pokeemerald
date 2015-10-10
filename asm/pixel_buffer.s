	thumb_func_start sub_8002BDC
sub_8002BDC: ; 8002BDC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x14
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	ldr r7, [sp, 0x38]
	lsls r2, 16
	lsrs r2, 16
	lsls r3, 16
	lsrs r3, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 16
	lsrs r6, 16
	lsls r7, 16
	lsrs r7, 16
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	str r7, [sp, 0xC]
	movs r4, 0xFF
	str r4, [sp, 0x10]
	bl PixelBlock_CopyRect4Bpp
	add sp, 0x14
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8002BDC

	thumb_func_start PixelBlock_CopyRect4Bpp
; void PixelBlock_CopyRect4Bpp(struct PixelBlock *src_pixels_data, struct PixelBlock *dest_pixels_data, u16 src_x, u16 src_y, u16 dest_x, u16 dest_y, u16 dest_w, u16 dest_h, u8 a9)
PixelBlock_CopyRect4Bpp: ; 8002C20
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x2C
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [sp, 0x4C]
	ldr r1, [sp, 0x50]
	ldr r4, [sp, 0x54]
	ldr r5, [sp, 0x58]
	ldr r6, [sp, 0x5C]
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x8]
	lsls r3, 16
	lsrs r7, r3, 16
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	lsls r1, 16
	lsrs r1, 16
	mov r9, r1
	lsls r4, 16
	lsrs r4, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r6, 24
	lsrs r6, 24
	str r6, [sp, 0x10]
	ldr r0, [sp, 0x4]
	ldrh r3, [r0, 0x4]
	ldr r1, [sp, 0xC]
	subs r0, r3, r1
	adds r2, r4
	mov r8, r2
	cmp r0, r4
	bge @08002C74
	ldr r2, [sp, 0x8]
	adds r0, r2
	mov r8, r0
@08002C74:
	ldr r4, [sp, 0x4]
	ldrh r0, [r4, 0x6]
	mov r1, r9
	subs r0, r1
	adds r2, r5, r7
	str r2, [sp, 0x14]
	cmp r0, r5
	bge @08002C88
	adds r0, r7
	str r0, [sp, 0x14]
@08002C88:
	ldr r4, [sp]
	ldrh r1, [r4, 0x4]
	movs r2, 0x7
	adds r0, r1, 0
	ands r0, r2
	adds r1, r0
	asrs r1, 3
	str r1, [sp, 0x18]
	adds r0, r3, 0
	ands r0, r2
	adds r0, r3, r0
	asrs r0, 3
	str r0, [sp, 0x1C]
	ldr r0, [sp, 0x10]
	cmp r0, 0xFF
	bne @08002D46
	adds r3, r7, 0
	mov r1, r9
	ldr r2, [sp, 0x14]
	cmp r3, r2
	blt @08002CB4
	b @08002DEE
@08002CB4:
	ldr r5, [sp, 0x8]
	ldr r6, [sp, 0xC]
	adds r4, r3, 0x1
	str r4, [sp, 0x24]
	adds r0, r1, 0x1
	str r0, [sp, 0x28]
	cmp r5, r8
	bge @08002D3A
	movs r7, 0x3
	asrs r0, r3, 3
	ldr r2, [sp, 0x18]
	muls r0, r2
	lsls r0, 5
	mov r10, r0
	lsls r0, r3, 29
	lsrs r0, 27
	mov r9, r0
	asrs r0, r1, 3
	ldr r4, [sp, 0x1C]
	muls r0, r4
	lsls r0, 5
	mov r12, r0
	lsls r0, r1, 29
	lsrs r3, r0, 27
@08002CE4:
	asrs r0, r5, 1
	ands r0, r7
	ldr r2, [sp]
	ldr r1, [r2]
	adds r1, r0
	asrs r0, r5, 3
	lsls r0, 5
	adds r1, r0
	add r1, r10
	mov r4, r9
	adds r2, r1, r4
	asrs r0, r6, 1
	ands r0, r7
	ldr r4, [sp, 0x4]
	ldr r1, [r4]
	adds r1, r0
	asrs r0, r6, 3
	lsls r0, 5
	adds r1, r0
	add r1, r12
	adds r4, r1, r3
	ldrb r2, [r2]
	adds r0, r5, 0
	movs r1, 0x1
	ands r0, r1
	lsls r0, 2
	asrs r2, r0
	movs r0, 0xF
	ands r2, r0
	adds r0, r6, 0
	ands r0, r1
	lsls r1, r0, 2
	lsls r2, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r4]
	ands r0, r1
	orrs r2, r0
	strb r2, [r4]
	adds r5, 0x1
	adds r6, 0x1
	cmp r5, r8
	blt @08002CE4
@08002D3A:
	ldr r3, [sp, 0x24]
	ldr r1, [sp, 0x28]
	ldr r2, [sp, 0x14]
	cmp r3, r2
	blt @08002CB4
	b @08002DEE
@08002D46:
	adds r3, r7, 0
	mov r1, r9
	ldr r4, [sp, 0x14]
	cmp r3, r4
	bge @08002DEE
@08002D50:
	ldr r5, [sp, 0x8]
	ldr r6, [sp, 0xC]
	adds r0, r3, 0x1
	str r0, [sp, 0x24]
	adds r2, r1, 0x1
	str r2, [sp, 0x28]
	cmp r5, r8
	bge @08002DE4
	movs r4, 0x3
	mov r9, r4
	asrs r0, r3, 3
	ldr r2, [sp, 0x18]
	muls r0, r2
	lsls r0, 5
	str r0, [sp, 0x20]
	lsls r0, r3, 29
	lsrs r0, 27
	mov r10, r0
	movs r3, 0x1
	asrs r0, r1, 3
	ldr r4, [sp, 0x1C]
	muls r0, r4
	lsls r0, 5
	mov r12, r0
	lsls r0, r1, 29
	lsrs r7, r0, 27
@08002D84:
	asrs r0, r5, 1
	mov r1, r9
	ands r0, r1
	ldr r2, [sp]
	ldr r1, [r2]
	adds r1, r0
	asrs r0, r5, 3
	lsls r0, 5
	adds r1, r0
	ldr r4, [sp, 0x20]
	adds r1, r4
	mov r0, r10
	adds r2, r1, r0
	asrs r0, r6, 1
	mov r1, r9
	ands r0, r1
	ldr r4, [sp, 0x4]
	ldr r1, [r4]
	adds r1, r0
	asrs r0, r6, 3
	lsls r0, 5
	adds r1, r0
	add r1, r12
	adds r4, r1, r7
	ldrb r2, [r2]
	adds r0, r5, 0
	ands r0, r3
	lsls r0, 2
	asrs r2, r0
	movs r0, 0xF
	ands r2, r0
	ldr r0, [sp, 0x10]
	cmp r2, r0
	beq @08002DDC
	adds r0, r6, 0
	ands r0, r3
	lsls r1, r0, 2
	lsls r2, r1
	movs r0, 0xF0
	asrs r0, r1
	ldrb r1, [r4]
	ands r0, r1
	orrs r2, r0
	strb r2, [r4]
@08002DDC:
	adds r5, 0x1
	adds r6, 0x1
	cmp r5, r8
	blt @08002D84
@08002DE4:
	ldr r3, [sp, 0x24]
	ldr r1, [sp, 0x28]
	ldr r2, [sp, 0x14]
	cmp r3, r2
	blt @08002D50
@08002DEE:
	add sp, 0x2C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end PixelBlock_CopyRect4Bpp

	thumb_func_start PixelBlock_FillRect4Bpp
; int PixelBlock_FillRect4Bpp(struct PixelBlock *pixels_data, u16 x, u16 y, u16 w, u16 h, u8 fill_value)
PixelBlock_FillRect4Bpp: ; 8002E00
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r9, r0
	ldr r0, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	lsls r1, 16
	lsrs r1, 16
	str r1, [sp]
	lsls r2, 16
	lsrs r2, 16
	adds r6, r2, 0
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 24
	lsrs r5, r4, 24
	adds r4, r1, r3
	mov r3, r9
	ldrh r1, [r3, 0x4]
	cmp r4, r1
	ble @08002E36
	adds r4, r1, 0
@08002E36:
	adds r2, r0
	mov r12, r2
	mov r2, r9
	ldrh r0, [r2, 0x6]
	cmp r12, r0
	ble @08002E44
	mov r12, r0
@08002E44:
	movs r0, 0x7
	ands r0, r1
	adds r0, r1, r0
	asrs r0, 3
	str r0, [sp, 0x4]
	lsls r0, r5, 28
	lsrs r0, 24
	mov r8, r0
	movs r3, 0xF
	mov r10, r3
	mov r0, r10
	ands r0, r5
	mov r10, r0
	adds r1, r6, 0
	cmp r1, r12
	bge @08002EB6
@08002E64:
	ldr r3, [sp]
	adds r7, r1, 0x1
	cmp r3, r4
	bge @08002EB0
	asrs r0, r1, 3
	ldr r2, [sp, 0x4]
	muls r0, r2
	lsls r6, r0, 5
	lsls r0, r1, 29
	lsrs r5, r0, 27
@08002E78:
	asrs r2, r3, 1
	movs r0, 0x3
	ands r2, r0
	mov r0, r9
	ldr r1, [r0]
	adds r1, r2
	asrs r0, r3, 3
	lsls r0, 5
	adds r1, r0
	adds r1, r6
	adds r2, r1, r5
	lsls r0, r3, 31
	cmp r0, 0
	beq @08002E9E
	ldrb r1, [r2]
	movs r0, 0xF
	ands r0, r1
	mov r1, r8
	b @08002EA6
@08002E9E:
	ldrb r1, [r2]
	movs r0, 0xF0
	ands r0, r1
	mov r1, r10
@08002EA6:
	orrs r0, r1
	strb r0, [r2]
	adds r3, 0x1
	cmp r3, r4
	blt @08002E78
@08002EB0:
	adds r1, r7, 0
	cmp r1, r12
	blt @08002E64
@08002EB6:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end PixelBlock_FillRect4Bpp

	thumb_func_start PixelBlock_CopyRect4BppTo8Bpp
; void PixelBlock_CopyRect4BppTo8Bpp(struct PixelBlock *src_pixels_data, struct PixelBlock *dest_pixels_data, u16 src_x, u16 src_y, u16 dest_x, u16 dest_y, u16 dest_w, u16 dest_h, int a9, int a10)
PixelBlock_CopyRect4BppTo8Bpp: ; 8002EC8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x3C
	str r0, [sp]
	str r1, [sp, 0x4]
	ldr r0, [sp, 0x5C]
	ldr r1, [sp, 0x60]
	ldr r5, [sp, 0x64]
	ldr r4, [sp, 0x68]
	ldr r6, [sp, 0x6C]
	ldr r7, [sp, 0x70]
	mov r8, r7
	lsls r2, 16
	lsrs r2, 16
	str r2, [sp, 0x8]
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0xC]
	lsls r1, 16
	lsrs r7, r1, 16
	lsls r5, 16
	lsrs r5, 16
	lsls r4, 16
	lsrs r4, 16
	lsls r6, 24
	lsrs r6, 24
	str r6, [sp, 0x10]
	mov r0, r8
	lsls r0, 28
	lsrs r0, 24
	str r0, [sp, 0x14]
	lsls r0, r6, 28
	lsrs r0, 24
	str r0, [sp, 0x28]
	ldr r1, [sp, 0x4]
	ldrh r0, [r1, 0x4]
	ldr r2, [sp, 0xC]
	subs r0, r2
	ldr r1, [sp, 0x8]
	adds r1, r5, r1
	str r1, [sp, 0x18]
	cmp r0, r5
	bge @08002F2E
	ldr r2, [sp, 0x8]
	adds r0, r2
	str r0, [sp, 0x18]
@08002F2E:
	ldr r5, [sp, 0x4]
	ldrh r1, [r5, 0x6]
	subs r0, r1, r7
	cmp r0, r4
	bge @08002F40
	adds r0, r3, r1
	subs r0, r7
	str r0, [sp, 0x1C]
	b @08002F44
@08002F40:
	adds r4, r3, r4
	str r4, [sp, 0x1C]
@08002F44:
	ldr r0, [sp]
	ldrh r1, [r0, 0x4]
	movs r2, 0x7
	adds r0, r1, 0
	ands r0, r2
	adds r1, r0
	asrs r1, 3
	str r1, [sp, 0x20]
	ldr r5, [sp, 0x4]
	ldrh r1, [r5, 0x4]
	adds r0, r1, 0
	ands r0, r2
	adds r1, r0
	asrs r1, 3
	str r1, [sp, 0x24]
	ldr r0, [sp, 0x10]
	cmp r0, 0xFF
	bne @08003024
	adds r2, r3, 0
	adds r5, r7, 0
	ldr r1, [sp, 0x1C]
	cmp r2, r1
	blt @08002F74
	b @08003106
@08002F74:
	ldr r3, [sp, 0x8]
	lsrs r3, 1
	str r3, [sp, 0x2C]
	movs r0, 0x3
	ands r3, r0
	str r3, [sp, 0x2C]
	ldr r7, [sp, 0x8]
	lsrs r0, r7, 3
	lsls r0, 5
	str r0, [sp, 0x30]
@08002F88:
	ldr r0, [sp]
	ldr r1, [r0]
	ldr r3, [sp, 0x2C]
	adds r1, r3
	ldr r7, [sp, 0x30]
	adds r1, r7
	asrs r0, r2, 3
	ldr r3, [sp, 0x20]
	muls r0, r3
	lsls r0, 5
	mov r8, r0
	add r1, r8
	lsls r0, r2, 29
	lsrs r7, r0, 27
	adds r6, r1, r7
	ldr r3, [sp, 0x8]
	ldr r4, [sp, 0xC]
	adds r2, 0x1
	mov r10, r2
	adds r0, r5, 0x1
	str r0, [sp, 0x38]
	ldr r1, [sp, 0x18]
	cmp r3, r1
	bge @08003018
	asrs r0, r5, 3
	ldr r2, [sp, 0x24]
	muls r0, r2
	lsls r0, 6
	mov r12, r0
	lsls r0, r5, 29
	lsrs r0, 26
	mov r9, r0
@08002FC8:
	movs r0, 0x7
	ands r0, r4
	ldr r5, [sp, 0x4]
	ldr r1, [r5]
	adds r1, r0
	asrs r0, r4, 3
	lsls r0, 6
	adds r1, r0
	add r1, r12
	mov r0, r9
	adds r5, r1, r0
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq @08002FEC
	ldrb r0, [r6]
	lsrs r0, 4
	b @08003008
@08002FEC:
	asrs r2, r3, 1
	movs r0, 0x3
	ands r2, r0
	ldr r0, [sp]
	ldr r1, [r0]
	adds r1, r2
	asrs r0, r3, 3
	lsls r0, 5
	adds r1, r0
	add r1, r8
	adds r6, r1, r7
	ldrb r1, [r6]
	movs r0, 0xF
	ands r0, r1
@08003008:
	ldr r1, [sp, 0x14]
	adds r0, r1, r0
	strb r0, [r5]
	adds r3, 0x1
	adds r4, 0x1
	ldr r2, [sp, 0x18]
	cmp r3, r2
	blt @08002FC8
@08003018:
	mov r2, r10
	ldr r5, [sp, 0x38]
	ldr r3, [sp, 0x1C]
	cmp r2, r3
	blt @08002F88
	b @08003106
@08003024:
	adds r2, r3, 0
	adds r5, r7, 0
	ldr r7, [sp, 0x1C]
	cmp r2, r7
	bge @08003106
	ldr r0, [sp, 0x8]
	lsrs r0, 1
	str r0, [sp, 0x34]
	movs r0, 0x3
	ldr r1, [sp, 0x34]
	ands r1, r0
	str r1, [sp, 0x34]
@0800303C:
	ldr r3, [sp]
	ldr r1, [r3]
	ldr r7, [sp, 0x34]
	adds r1, r7
	ldr r3, [sp, 0x8]
	lsrs r0, r3, 3
	lsls r0, 5
	adds r1, r0
	asrs r0, r2, 3
	ldr r7, [sp, 0x20]
	muls r0, r7
	lsls r0, 5
	mov r8, r0
	add r1, r8
	lsls r0, r2, 29
	lsrs r7, r0, 27
	adds r6, r1, r7
	ldr r4, [sp, 0xC]
	adds r2, 0x1
	mov r10, r2
	adds r0, r5, 0x1
	str r0, [sp, 0x38]
	ldr r1, [sp, 0x18]
	cmp r3, r1
	bge @080030FC
	asrs r0, r5, 3
	ldr r2, [sp, 0x24]
	muls r0, r2
	lsls r0, 6
	mov r9, r0
	lsls r0, r5, 29
	lsrs r0, 26
	mov r12, r0
@0800307E:
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	beq @080030B2
	ldrb r2, [r6]
	movs r0, 0xF0
	ands r0, r2
	ldr r5, [sp, 0x28]
	cmp r0, r5
	beq @080030F2
	adds r0, r4, 0
	movs r1, 0x7
	ands r0, r1
	ldr r5, [sp, 0x4]
	ldr r1, [r5]
	adds r1, r0
	asrs r0, r4, 3
	lsls r0, 6
	adds r1, r0
	add r1, r9
	mov r0, r12
	adds r5, r1, r0
	lsrs r0, r2, 4
	ldr r1, [sp, 0x14]
	adds r0, r1, r0
	b @080030F0
@080030B2:
	asrs r2, r3, 1
	movs r0, 0x3
	ands r2, r0
	ldr r5, [sp]
	ldr r1, [r5]
	adds r1, r2
	asrs r0, r3, 3
	lsls r0, 5
	adds r1, r0
	add r1, r8
	adds r6, r1, r7
	ldrb r0, [r6]
	movs r2, 0xF
	ands r2, r0
	ldr r0, [sp, 0x10]
	cmp r2, r0
	beq @080030F2
	adds r0, r4, 0
	movs r1, 0x7
	ands r0, r1
	ldr r5, [sp, 0x4]
	ldr r1, [r5]
	adds r1, r0
	asrs r0, r4, 3
	lsls r0, 6
	adds r1, r0
	add r1, r9
	mov r0, r12
	adds r5, r1, r0
	ldr r1, [sp, 0x14]
	adds r0, r1, r2
@080030F0:
	strb r0, [r5]
@080030F2:
	adds r3, 0x1
	adds r4, 0x1
	ldr r2, [sp, 0x18]
	cmp r3, r2
	blt @0800307E
@080030FC:
	mov r2, r10
	ldr r5, [sp, 0x38]
	ldr r3, [sp, 0x1C]
	cmp r2, r3
	blt @0800303C
@08003106:
	add sp, 0x3C
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end PixelBlock_CopyRect4BppTo8Bpp

	thumb_func_start PixelBlock_FillRect8Bpp
; void PixelBlock_FillRect8Bpp(struct PixelBlock *pixels_data, u16 x, u16 y, u16 w, u16 h, char fill_value)
PixelBlock_FillRect8Bpp: ; 8003118
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r8, r0
	ldr r0, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	lsls r1, 16
	lsrs r1, 16
	mov r10, r1
	lsls r2, 16
	lsrs r2, 16
	adds r6, r2, 0
	lsls r3, 16
	lsrs r3, 16
	lsls r0, 16
	lsrs r0, 16
	lsls r4, 24
	lsrs r4, 24
	mov r9, r4
	adds r5, r1, r3
	mov r3, r8
	ldrh r1, [r3, 0x4]
	cmp r5, r1
	ble @08003150
	adds r5, r1, 0
@08003150:
	adds r7, r2, r0
	mov r2, r8
	ldrh r0, [r2, 0x6]
	cmp r7, r0
	ble @0800315C
	adds r7, r0, 0
@0800315C:
	movs r0, 0x7
	ands r0, r1
	adds r0, r1, r0
	asrs r0, 3
	str r0, [sp]
	adds r1, r6, 0
	cmp r1, r7
	bge @080031AC
@0800316C:
	mov r3, r10
	adds r6, r1, 0x1
	str r6, [sp, 0x4]
	cmp r3, r5
	bge @080031A6
	movs r0, 0x7
	mov r12, r0
	asrs r0, r1, 3
	ldr r2, [sp]
	muls r0, r2
	lsls r4, r0, 6
	lsls r0, r1, 29
	lsrs r2, r0, 26
@08003186:
	adds r0, r3, 0
	mov r6, r12
	ands r0, r6
	mov r6, r8
	ldr r1, [r6]
	adds r1, r0
	asrs r0, r3, 3
	lsls r0, 6
	adds r1, r0
	adds r1, r4
	adds r1, r2
	mov r0, r9
	strb r0, [r1]
	adds r3, 0x1
	cmp r3, r5
	blt @08003186
@080031A6:
	ldr r1, [sp, 0x4]
	cmp r1, r7
	blt @0800316C
@080031AC:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end PixelBlock_FillRect8Bpp
