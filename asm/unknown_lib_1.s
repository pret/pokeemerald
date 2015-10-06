	thumb_func_start sub_82DED70
sub_82DED70: @ 82DED70
	push {r4,lr}
	ldr r4, _082DEE78
	eors r3, r1
	movs r2, 0x20
_082DED78:
	lsrs r3, 1
	bcc _082DED7E
	eors r3, r4
_082DED7E:
	subs r2, 0x1
	bne _082DED78
	pop {r4,pc}
	thumb_func_end sub_82DED70

	thumb_func_start sub_82DED84
sub_82DED84: @ 82DED84
	ldr r1, [r0, 0x28]
	cmp r1, 0
	beq _082DEDAA
	ldrb r1, [r0, 0x1]
	adds r1, 0x1
	strb r1, [r0, 0x1]
	ldrb r1, [r0, 0x2]
	cmp r1, 0x2
	beq _082DEDF4
	ldr r3, _082DF038
	ldrh r2, [r3, 0x8]
	movs r1, 0
	strh r1, [r3, 0x8]
	ldrb r1, [r0]
	cmp r1, 0xA
	bgt _082DEDA8
	adds r1, 0x1
	strb r1, [r0]
_082DEDA8:
	strh r2, [r3, 0x8]
_082DEDAA:
	bcs sub_82DEE98
	ldrb r1, [r0, 0x2]
	cmp r1, 0
	bne _082DEDF6
	ldr r1, [r0, 0x24]
	ldr r2, [r0, 0x20]
	subs r1, r2
	beq _082DEE76
	cmp r1, 0xA0
	bcc _082DEE76
	push {r4-r6}
	movs r1, 0x98
	adds r2, 0x4
	ldr r4, _082DEE80
_082DEDC6:
	ldm r2!, {r5}
	ldm r4!, {r6}
	cmp r5, r6
	bne _082DEDDC
	subs r1, 0x4
	bne _082DEDC6
	ldm r2!, {r5}
	ldm r4!, {r6}
	eors r5, r6
	lsrs r5, 8
	str r2, [r0, 0x20]
_082DEDDC:
	pop {r4-r6}
	bne sub_82DEE98
	movs r1, 0x1
	strb r1, [r0, 0x2]
	ldr r1, [r0, 0x4]
	ldr r2, [r0, 0x8]
	eors r1, r2
	str r1, [r0, 0x18]
	ldr r2, _082DEE7C
	muls r1, r2
	adds r1, 0x1
	str r1, [r0, 0x14]
_082DEDF4:
	bx lr
_082DEDF6:
	ldr r1, [r0, 0x24]
	mov r12, r1
	ldr r3, [r0, 0x18]
	push {r4-r7}
	ldr r4, [r0, 0x20]
	ldr r5, _082DEE7C
	ldr r6, [r0, 0x14]
	ldr r7, _082DEE78
_082DEE06:
	cmp r4, r12
	bcs _082DEE26
	ldr r1, [r4]
	eors r1, r6
	adds r1, r3
	stm r4!, {r1}
	eors r3, r1
	movs r2, 0x20
_082DEE16:
	lsrs r3, 1
	bcc _082DEE1C
	eors r3, r7
_082DEE1C:
	subs r2, 0x1
	bne _082DEE16
	muls r6, r5
	adds r6, 0x1
	b _082DEE06
_082DEE26:
	str r4, [r0, 0x20]
	str r6, [r0, 0x14]
	pop {r4-r7}
	str r3, [r0, 0x18]
	ldrh r1, [r0, 0x12]
	cmp r1, 0
	bne _082DEE76
	ldr r1, [r0, 0x24]
	ldr r2, [r0, 0x20]
	cmp r1, r2
	bne _082DEE76
	ldr r1, [r0, 0xC]
	cmp r1, 0
	beq _082DEE60
	ldrh r1, [r0, 0x10]
	cmp r1, 0
	beq _082DEDF4
	mov r12, lr
	movs r1, 0xBB
	ldr r3, [r0, 0xC]
	bl sub_82DED70
	ldrh r1, [r0, 0x10]
	mov lr, r12
	subs r1, r3
	bne sub_82DEE98
	movs r1, 0x2
	strb r1, [r0, 0x2]
	bx lr
_082DEE60:
	mov r12, lr
	ldrb r1, [r0, 0x3]
	lsls r1, 24
	subs r1, 0x1
	str r1, [r0, 0xC]
	bl sub_82DED70
	lsls r3, 8
	adds r3, 0xFF
	str r3, [r0, 0x1C]
	bx r12
_082DEE76:
	bx lr
	.align 2, 0
_082DEE78: .4byte 0x0000a1c1
_082DEE7C: .4byte 0x6177614b
_082DEE80: .4byte RomHeaderNintendoLogo
	thumb_func_end sub_82DED84

	thumb_func_start sub_82DEE84
sub_82DEE84: @ 82DEE84
	ldrb r1, [r0, 0x2]
	cmp r1, 0x2
	bne _082DEE96
	ldr r3, _082DF038
	movs r1, 0
	strh r1, [r3, 0x8]
	ldr r1, _082DF048
	adds r1, 0xC0
	bx r1
_082DEE96:
	bx lr
	thumb_func_end sub_82DEE84

	thumb_func_start sub_82DEE98
sub_82DEE98: @ 82DEE98
	ldr r3, _082DF038
	ldrh r2, [r3, 0x8]
	movs r1, 0
	strh r1, [r3, 0x8]
	adr r3, _082DEEF8
	str r3, [r0, 0x28]
	ldrb r3, [r0, 0x3]
	push {r3}
	ldrb r3, [r0, 0x1]
	push {r0,r3}
	adds r3, r0, 0
	adds r3, 0x20
_082DEEB0:
	stm r0!, {r1}
	cmp r0, r3
	bcc _082DEEB0
	pop {r0,r3}
	lsrs r3, 1
	strb r3, [r0, 0x3]
	pop {r3}
	strb r3, [r0, 0x1]
	ldr r3, _082DF03C
	lsls r0, r3, 10
	strh r0, [r3, 0x14]
	movs r0, 0xC0
	lsls r0, 8
	strh r0, [r3, 0x14]
	movs r0, 0x47
	strh r0, [r3, 0x20]
	strh r1, [r3, 0x38]
	ldr r3, _082DF038
	movs r0, 0x80
	strh r0, [r3, 0x2]
	ldrh r1, [r3]
	orrs r1, r0
	strh r1, [r3]
	strh r2, [r3, 0x8]
	bx lr
	thumb_func_end sub_82DEE98

	non_word_aligned_thumb_func_start sub_82DEEE2
sub_82DEEE2: @ 82DEEE2
	ldr r3, _082DF03C
	ldrh r1, [r3, 0x20]
	strh r1, [r3, 0x20]
	movs r2, 0
	strb r2, [r0]
	ldr r2, [r0, 0x28]
	cmp r2, 0
	beq _082DEF04
	lsrs r1, 1
	bcs _082DEF06
	mov pc, r2
_082DEEF8:
	movs r2, 0
	strh r2, [r3, 0x38]
_082DEEFC:
	str r2, [r0, 0x28]
_082DEEFE:
	ldr r3, _082DF040
	ldrh r1, [r3, 0x2]
	strb r1, [r0, 0x3]
_082DEF04:
	bx lr
_082DEF06:
	ldr r1, [r3, 0x30]
	ldr r1, _082DF044
	str r1, [r3, 0x34]
	movs r1, 0x10
	strh r1, [r3, 0x38]
	ldrb r1, [r0, 0x3]
	strb r1, [r0, 0x9]
	ldrb r1, [r0, 0x2]
	cmp r1, 0
	bne _082DEEF8
	ldr r1, _082DF048
	str r1, [r0, 0x20]
	str r1, [r0, 0x24]
	adr r2, .Lsub_82DEF24
	b _082DEEFC
	thumb_func_end sub_82DEEE2

	thumb_func_start sub_82DEF24
.Lsub_82DEF24:
sub_82DEF24: @ 82DEF24
	lsls r1, 31
	bcc _082DEEF8
	bmi _082DEF34
	adr r2, .Lsub_82DEF30
	b _082DEEFC
	thumb_func_end sub_82DEF24

	thumb_func_start sub_82DEF30
.Lsub_82DEF30:
sub_82DEF30: @ 82DEF30
	lsrs r1, 1
	bcc _082DEEF8
_082DEF34:
	ldr r1, [r3, 0x30]
	ldr r2, _082DF044
	cmp r1, r2
	bne _082DEEF8
	ldrb r1, [r0, 0x3]
	strb r1, [r0, 0xB]
	adr r2, .Lsub_82DEF44
	b _082DEEFC
	thumb_func_end sub_82DEF30

	thumb_func_start sub_82DEF44
.Lsub_82DEF44:
sub_82DEF44: @ 82DEF44
	lsrs r1, 1
	bcc _082DEEF8
	ldr r1, [r3, 0x30]
	lsrs r2, r1, 24
	cmp r2, 0xDD
	bne _082DEEF8
	str r1, [r0, 0x4]
	ldrb r1, [r0, 0x1]
	strb r1, [r0, 0xA]
	movs r2, 0
	movs r3, 0
	ldr r1, [r0, 0x8]
	lsrs r1, 8
_082DEF5E:
	lsrs r1, 1
	adcs r2, r3
	cmp r1, 0
	bne _082DEF5E
	cmp r2, 0xE
	bgt _082DEF70
	cmp r2, 0x7
	bge _082DEF72
	movs r1, 0xFF
_082DEF70:
	strb r1, [r0, 0xA]
_082DEF72:
	ldr r1, [r0, 0x8]
	adds r1, 0xEE
	ldr r3, _082DF03C
	str r1, [r3, 0x34]
	movs r1, 0x30
	strh r1, [r3, 0x38]
	adr r2, .Lsub_82DEF84
	b _082DEEFC
	thumb_func_end sub_82DEF44

	thumb_func_start sub_82DEF84
.Lsub_82DEF84:
sub_82DEF84: @ 82DEF84
	lsls r1, 31
	bcc _082DEEF8
	bmi _082DEF94
	adr r2, .Lsub_82DEF90
	b _082DEEFC
	thumb_func_end sub_82DEF84

	thumb_func_start sub_82DEF90
.Lsub_82DEF90:
sub_82DEF90: @ 82DEF90
	lsrs r1, 1
	bcc _082DEEF8
_082DEF94:
	ldr r1, [r3, 0x30]
	ldr r2, _082DF034
	cmp r1, r2
	bcs _082DEEF8
	adds r1, 0x1
	adds r1, r1
	strh r1, [r0, 0x12]
	ldrb r1, [r0, 0x2]
	cmp r1, 0
_082DEFA6:
	bne _082DEEF8
	ldr r1, _082DF048
	str r1, [r0, 0x20]
	str r1, [r0, 0x24]
	adr r2, .Lsub_82DEFB4
	b _082DEEFC
	thumb_func_end sub_82DEF90

	thumb_func_start sub_82DEFB4
.Lsub_82DEFB4:
sub_82DEFB4: @ 82DEFB4
	lsrs r1, 1
	bcc _082DEEF8
	ldr r2, [r0, 0x24]
	movs r1, 0x4
	ands r1, r2
	adds r1, 0x8
	lsls r1, 2
	strh r1, [r3, 0x38]
	ldr r1, [r3, 0x30]
	stm r2!, {r1}
	str r2, [r0, 0x24]
	ldrh r1, [r0, 0x12]
	subs r1, 0x1
	strh r1, [r0, 0x12]
	bne _082DEEFE
_082DEFD2:
	ldrb r1, [r0, 0x1]
	lsls r1, 8
	adds r1, 0xCC
	str r1, [r3, 0x34]
	adr r2, _082DEFE0
	b _082DEEFC
	.align 2, 0
_082DEFE0:
	lsls r1, 31
_082DEFE2:
	bcc _082DEEF8
	ldr r1, [r0, 0x1C]
	cmp r1, 0
	beq _082DEFD2
	str r1, [r3, 0x34]
	adr r2, .Lsub_82DEFF0
	b _082DEEFC
	thumb_func_end sub_82DEFB4

	thumb_func_start sub_82DEFF0
.Lsub_82DEFF0:
sub_82DEFF0: @ 82DEFF0
	lsls r1, 31
	bcc _082DEFE2
	bmi _082DF000
	adr r2, .L_082DEFFC
	b _082DEEFC
	.align 2, 0
.L_082DEFFC:
_082DEFFC:
	lsrs r1, 1
	bcc _082DEFE2
_082DF000:
	ldr r1, [r3, 0x30]
	lsrs r2, r1, 24
	cmp r2, 0xBB
	bne _082DEFA6
	strh r1, [r0, 0x10]
	adr r2, .Lsub_82DF010
	b _082DEEFC
	thumb_func_end sub_82DEFF0

	thumb_func_start sub_82DF010
.Lsub_82DF010:
sub_82DF010: @ 82DF010
	b _082DEEF8
	thumb_func_end sub_82DF010

	non_word_aligned_thumb_func_start sub_82DF012
sub_82DF012: @ 82DF012
	ldr r3, _082DF038
	ldrh r2, [r3, 0x8]
	movs r1, 0
	strh r1, [r3, 0x8]
	ldr r3, _082DF03C
	movs r0, 0x7
	strh r0, [r3, 0x20]
	lsls r0, r3, 10
	strh r0, [r3, 0x14]
	ldr r3, _082DF038
	movs r0, 0x80
	strh r0, [r3, 0x2]
	ldrh r1, [r3]
	bics r1, r0
	strh r1, [r3]
	strh r2, [r3, 0x8]
	bx lr
	.align 2, 0
_082DF034: .4byte 0x00004000
_082DF038: .4byte 0x04000200
_082DF03C: .4byte 0x04000120
_082DF040: .4byte 0x04000004
_082DF044: .4byte 0x45565841
_082DF048: .4byte 0x02000000
	thumb_func_end sub_82DF012
