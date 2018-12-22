	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_811ACDC
sub_811ACDC: @ 811ACDC
	push {r4-r6,lr}
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0811AD4A
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0x5]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x1
	beq _0811AD3E
	b _0811AD24
	.pool
_0811AD04:
	movs r0, 0x20
	ands r0, r2
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0
	bne _0811ADE0
	movs r0, 0x80
	ands r0, r2
	cmp r0, 0
	bne _0811ADD0
	movs r0, 0x10
	ands r0, r2
	cmp r0, 0
	bne _0811ADC0
	movs r0, 0
	b _0811AE32
_0811AD24:
	cmp r0, 0x1
	bgt _0811AD2E
	cmp r0, 0
	beq _0811AD38
	b _0811AD4A
_0811AD2E:
	cmp r0, 0x2
	beq _0811ADF6
	cmp r0, 0x3
	beq _0811AD44
	b _0811AD4A
_0811AD38:
	bl sub_811B184
	b _0811ADFA
_0811AD3E:
	bl sub_811B150
	b _0811ADFA
_0811AD44:
	bl sub_811B264
	b _0811ADFA
_0811AD4A:
	ldrh r2, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r2
	cmp r0, 0
	bne _0811ADF0
	movs r0, 0x8
	ands r0, r2
	cmp r0, 0
	bne _0811ADF6
	movs r0, 0x40
	ands r0, r2
	cmp r0, 0
	beq _0811AD04
	ldr r2, =gUnknown_0203A118
	ldr r1, [r2]
	ldrb r0, [r1, 0x6]
	subs r0, 0x1
	strb r0, [r1, 0x6]
_0811AD6E:
	adds r6, r2, 0
_0811AD70:
	adds r5, r6, 0
	ldr r4, [r5]
	movs r3, 0x6
	ldrsb r3, [r4, r3]
	ldr r2, =gUnknown_08597550
	ldrb r1, [r4, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r1, r0, r2
	ldrb r0, [r1, 0x2]
	cmp r3, r0
	bne _0811AE00
	bl sub_811BA3C
	movs r2, 0x3
	cmp r0, 0
	beq _0811AD96
	movs r2, 0x4
_0811AD96:
	ldr r1, [r5]
	movs r0, 0x5
	ldrsb r0, [r1, r0]
	cmp r0, 0
	bge _0811ADA4
	subs r0, r2, 0x1
	strb r0, [r1, 0x5]
_0811ADA4:
	ldr r1, [r5]
	movs r0, 0x5
	ldrsb r0, [r1, r0]
	cmp r0, r2
	blt _0811ADB2
	movs r0, 0
	strb r0, [r1, 0x5]
_0811ADB2:
	movs r0, 0x3
	b _0811AE32
	.pool
_0811ADC0:
	ldr r2, =gUnknown_0203A118
	ldr r1, [r2]
	ldrb r0, [r1, 0x5]
	adds r0, 0x1
	strb r0, [r1, 0x5]
	b _0811AD6E
	.pool
_0811ADD0:
	ldr r1, =gUnknown_0203A118
	ldr r0, [r1]
	strb r3, [r0, 0x6]
	adds r6, r1, 0
	b _0811AD70
	.pool
_0811ADE0:
	ldr r2, =gUnknown_0203A118
	ldr r1, [r2]
	ldrb r0, [r1, 0x5]
	subs r0, 0x1
	strb r0, [r1, 0x5]
	b _0811AD6E
	.pool
_0811ADF0:
	bl sub_811B150
	b _0811ADFA
_0811ADF6:
	bl sub_811B1B4
_0811ADFA:
	lsls r0, 16
	lsrs r0, 16
	b _0811AE32
_0811AE00:
	movs r0, 0x5
	ldrsb r0, [r4, r0]
	ldrb r1, [r1, 0x1]
	cmp r0, r1
	blt _0811AE0E
	subs r0, r1, 0x1
	strb r0, [r4, 0x5]
_0811AE0E:
	bl sub_811AB44
	cmp r0, 0
	beq _0811AE28
	ldr r2, [r6]
	ldr r0, [r2, 0x4]
	ldr r1, =0x00ffff00
	ands r0, r1
	ldr r1, =0x00040100
	cmp r0, r1
	bne _0811AE28
	movs r0, 0
	strb r0, [r2, 0x5]
_0811AE28:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x4]
	movs r0, 0x2
_0811AE32:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811ACDC

	thumb_func_start sub_811AE44
sub_811AE44: @ 811AE44
	push {lr}
	ldr r1, =gMain
	ldrh r2, [r1, 0x2E]
	movs r0, 0x2
	ands r0, r2
	adds r3, r1, 0
	cmp r0, 0
	beq _0811AE60
	bl sub_811B32C
	b _0811AEF6
	.pool
_0811AE60:
	movs r0, 0x1
	ands r0, r2
	cmp r0, 0
	beq _0811AEAE
	ldr r0, =gUnknown_0203A118
	ldr r2, [r0]
	movs r1, 0xA
	ldrsb r1, [r2, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0811AE84
	bl sub_811B2B0
	b _0811AEF6
	.pool
_0811AE84:
	movs r0, 0xB
	ldrsb r0, [r2, r0]
	cmp r0, 0x1
	beq _0811AEA2
	cmp r0, 0x1
	bgt _0811AE96
	cmp r0, 0
	beq _0811AE9C
	b _0811AEAE
_0811AE96:
	cmp r0, 0x2
	beq _0811AEA8
	b _0811AEAE
_0811AE9C:
	bl sub_811B33C
	b _0811AEF6
_0811AEA2:
	bl sub_811B368
	b _0811AEF6
_0811AEA8:
	bl sub_811B32C
	b _0811AEF6
_0811AEAE:
	ldrh r1, [r3, 0x2E]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0811AEBE
	bl sub_811B33C
	b _0811AEF6
_0811AEBE:
	ldrh r1, [r3, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0811AECC
	movs r0, 0x2
	b _0811AEF2
_0811AECC:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0811AED8
	movs r0, 0x3
	b _0811AEF2
_0811AED8:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0811AEE4
	movs r0, 0x1
	b _0811AEF2
_0811AEE4:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0811AEF0
	movs r0, 0
	b _0811AEFA
_0811AEF0:
	movs r0, 0
_0811AEF2:
	bl sub_811B528
_0811AEF6:
	lsls r0, 16
	lsrs r0, 16
_0811AEFA:
	pop {r1}
	bx r1
	thumb_func_end sub_811AE44

	thumb_func_start sub_811AF00
sub_811AF00: @ 811AF00
	push {lr}
	ldr r2, =gMain
	ldrh r1, [r2, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _0811AF24
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	movs r0, 0x2
	strb r0, [r1, 0x4]
	movs r0, 0xE
	b _0811AF86
	.pool
_0811AF24:
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0811AF32
	bl sub_811B394
	b _0811AF82
_0811AF32:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _0811AF3E
	movs r0, 0x4
	b _0811AF7E
_0811AF3E:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0811AF4A
	movs r0, 0x5
	b _0811AF7E
_0811AF4A:
	ldrh r1, [r2, 0x30]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _0811AF58
	movs r0, 0x2
	b _0811AF7E
_0811AF58:
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _0811AF64
	movs r0, 0x3
	b _0811AF7E
_0811AF64:
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _0811AF70
	movs r0, 0x1
	b _0811AF7E
_0811AF70:
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	bne _0811AF7C
	movs r0, 0
	b _0811AF86
_0811AF7C:
	movs r0, 0
_0811AF7E:
	bl sub_811B794
_0811AF82:
	lsls r0, 16
	lsrs r0, 16
_0811AF86:
	pop {r1}
	bx r1
	thumb_func_end sub_811AF00

	thumb_func_start sub_811AF8C
sub_811AF8C: @ 811AF8C
	push {lr}
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0811AFC0
	cmp r1, 0
	bgt _0811AFA8
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0811AFAC
	b _0811AFE4
_0811AFA8:
	cmp r1, 0x1
	bne _0811AFE4
_0811AFAC:
	bl sub_811B2A4
	ldr r1, =gUnknown_0203A118
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x7
	b _0811AFE6
	.pool
_0811AFC0:
	ldr r0, =gSpecialVar_Result
	strh r1, [r0]
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0]
	subs r0, 0x11
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0811AFD8
	bl sub_811B3E4
_0811AFD8:
	movs r0, 0x18
	b _0811AFE6
	.pool
_0811AFE4:
	movs r0, 0
_0811AFE6:
	pop {r1}
	bx r1
	thumb_func_end sub_811AF8C

	thumb_func_start sub_811AFEC
sub_811AFEC: @ 811AFEC
	push {r4,lr}
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0811B020
	cmp r1, 0
	bgt _0811B008
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0811B00C
	b _0811B038
_0811B008:
	cmp r1, 0x1
	bne _0811B038
_0811B00C:
	bl sub_811B2A4
	ldr r1, =gUnknown_0203A118
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x7
	b _0811B03A
	.pool
_0811B020:
	bl sub_811BE9C
	ldr r4, =gSpecialVar_Result
	bl sub_811B4EC
	strh r0, [r4]
	bl sub_811B3E4
	movs r0, 0x18
	b _0811B03A
	.pool
_0811B038:
	movs r0, 0
_0811B03A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811AFEC

	thumb_func_start sub_811B040
sub_811B040: @ 811B040
	push {lr}
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0811B070
	cmp r1, 0
	bgt _0811B05C
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0811B060
	b _0811B084
_0811B05C:
	cmp r1, 0x1
	bne _0811B084
_0811B060:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	movs r0, 0x7
	b _0811B086
	.pool
_0811B070:
	bl sub_811B418
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	movs r0, 0x1
	strb r0, [r1, 0x4]
	movs r0, 0x8
	b _0811B086
	.pool
_0811B084:
	movs r0, 0
_0811B086:
	pop {r1}
	bx r1
	thumb_func_end sub_811B040

	thumb_func_start sub_811B08C
sub_811B08C: @ 811B08C
	push {lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0811B0A4
	movs r0, 0x1A
	b _0811B0B8
	.pool
_0811B0A4:
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _0811B0B0
	movs r0, 0
	b _0811B0B8
_0811B0B0:
	bl sub_811B150
	lsls r0, 16
	lsrs r0, 16
_0811B0B8:
	pop {r1}
	bx r1
	thumb_func_end sub_811B08C

	thumb_func_start sub_811B0BC
sub_811B0BC: @ 811B0BC
	push {lr}
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	bne _0811B0D4
	movs r0, 0
	b _0811B0E0
	.pool
_0811B0D4:
	bl sub_811B2A4
	ldr r1, =gUnknown_0203A118
	ldr r1, [r1]
	strb r0, [r1, 0x4]
	movs r0, 0x7
_0811B0E0:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811B0BC

	thumb_func_start sub_811B0E8
sub_811B0E8: @ 811B0E8
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	movs r0, 0xA
	strb r0, [r1, 0x4]
	movs r0, 0x6
	bx lr
	.pool
	thumb_func_end sub_811B0E8

	thumb_func_start sub_811B0F8
sub_811B0F8: @ 811B0F8
	push {r4,lr}
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, 24
	asrs r1, r0, 24
	cmp r1, 0
	beq _0811B134
	cmp r1, 0
	bgt _0811B114
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0811B118
	b _0811B148
_0811B114:
	cmp r1, 0x1
	bne _0811B148
_0811B118:
	bl sub_811B454
	ldr r2, =gUnknown_0203A118
	ldr r1, [r2]
	movs r0, 0
	strb r0, [r1, 0x8]
	ldr r1, [r2]
	movs r0, 0x8
	strb r0, [r1, 0x4]
	movs r0, 0x1F
	b _0811B14A
	.pool
_0811B134:
	ldr r4, =gSpecialVar_Result
	bl sub_811B4EC
	strh r0, [r4]
	bl sub_811B3E4
	movs r0, 0x18
	b _0811B14A
	.pool
_0811B148:
	movs r0, 0
_0811B14A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811B0F8

	thumb_func_start sub_811B150
sub_811B150: @ 811B150
	push {lr}
	ldr r1, =gUnknown_0203A118
	ldr r2, [r1]
	ldrb r0, [r2]
	cmp r0, 0x13
	beq _0811B160
	cmp r0, 0xB
	bne _0811B174
_0811B160:
	ldrb r0, [r2, 0x4]
	strb r0, [r2, 0x8]
	ldr r1, [r1]
	movs r0, 0x8
	strb r0, [r1, 0x4]
	movs r0, 0x22
	b _0811B180
	.pool
_0811B174:
	ldrb r0, [r2, 0x4]
	strb r0, [r2, 0x8]
	ldr r1, [r1]
	movs r0, 0x4
	strb r0, [r1, 0x4]
	movs r0, 0x5
_0811B180:
	pop {r1}
	bx r1
	thumb_func_end sub_811B150

	thumb_func_start sub_811B184
sub_811B184: @ 811B184
	push {lr}
	ldr r2, =gUnknown_0203A118
	ldr r0, [r2]
	ldrb r1, [r0, 0x4]
	strb r1, [r0, 0x8]
	ldr r1, [r2]
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _0811B1A8
	ldrb r0, [r1, 0x4]
	strb r0, [r1, 0x8]
	ldr r1, [r2]
	movs r0, 0x8
	strb r0, [r1, 0x4]
	movs r0, 0x20
	b _0811B1AE
	.pool
_0811B1A8:
	movs r0, 0x5
	strb r0, [r1, 0x4]
	movs r0, 0x4
_0811B1AE:
	pop {r1}
	bx r1
	thumb_func_end sub_811B184

	thumb_func_start sub_811B1B4
sub_811B1B4: @ 811B1B4
	push {r4,lr}
	ldr r4, =gUnknown_0203A118
	ldr r1, [r4]
	ldrb r0, [r1, 0x4]
	strb r0, [r1, 0x8]
	ldr r1, [r4]
	ldrb r0, [r1]
	cmp r0, 0x11
	bne _0811B1DC
	bl sub_811BD64
	cmp r0, 0
	bne _0811B1FA
	bl sub_811BDB0
	cmp r0, 0
	bne _0811B1E8
	b _0811B256
	.pool
_0811B1DC:
	cmp r0, 0x12
	bne _0811B204
	bl sub_811BDB0
	cmp r0, 0
	beq _0811B1F2
_0811B1E8:
	ldr r1, [r4]
	movs r0, 0x8
	strb r0, [r1, 0x4]
	movs r0, 0x1E
	b _0811B25C
_0811B1F2:
	bl sub_811BD64
	cmp r0, 0
	beq _0811B256
_0811B1FA:
	ldr r1, [r4]
	movs r0, 0x8
	strb r0, [r1, 0x4]
	movs r0, 0x1D
	b _0811B25C
_0811B204:
	cmp r0, 0x9
	beq _0811B20C
	cmp r0, 0xD
	bne _0811B21E
_0811B20C:
	bl sub_811BD2C
	cmp r0, 0
	bne _0811B256
	ldr r1, [r4]
	movs r0, 0x8
	strb r0, [r1, 0x4]
	movs r0, 0x21
	b _0811B25C
_0811B21E:
	cmp r0, 0x13
	beq _0811B226
	cmp r0, 0xB
	bne _0811B238
_0811B226:
	bl sub_811BCF4
	cmp r0, 0
	beq _0811B256
	ldr r1, [r4]
	movs r0, 0x8
	strb r0, [r1, 0x4]
	movs r0, 0x22
	b _0811B25C
_0811B238:
	cmp r0, 0x14
	beq _0811B258
	bl sub_811BCF4
	cmp r0, 0x1
	beq _0811B24C
	bl sub_811B4EC
	cmp r0, 0
	bne _0811B256
_0811B24C:
	ldr r1, [r4]
	movs r0, 0x4
	strb r0, [r1, 0x4]
	movs r0, 0x5
	b _0811B25C
_0811B256:
	ldr r1, [r4]
_0811B258:
	movs r0, 0x6
	strb r0, [r1, 0x4]
_0811B25C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811B1B4

	thumb_func_start sub_811B264
sub_811B264: @ 811B264
	push {lr}
	ldr r2, =gUnknown_0203A118
	ldr r1, [r2]
	ldrb r0, [r1, 0x4]
	strb r0, [r1, 0x8]
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r0, 0x11
	beq _0811B28E
	cmp r0, 0x11
	bgt _0811B284
	cmp r0, 0xF
	beq _0811B28A
	b _0811B29E
	.pool
_0811B284:
	cmp r0, 0x12
	beq _0811B296
	b _0811B29E
_0811B28A:
	movs r0, 0x19
	b _0811B2A0
_0811B28E:
	bl sub_811B3E4
	movs r0, 0x1C
	b _0811B2A0
_0811B296:
	bl sub_811B3E4
	movs r0, 0x1B
	b _0811B2A0
_0811B29E:
	movs r0, 0
_0811B2A0:
	pop {r1}
	bx r1
	thumb_func_end sub_811B264

	thumb_func_start sub_811B2A4
sub_811B2A4: @ 811B2A4
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	bx lr
	.pool
	thumb_func_end sub_811B2A4

	thumb_func_start sub_811B2B0
sub_811B2B0: @ 811B2B0
	push {lr}
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0x9]
	cmp r0, 0
	bne _0811B2DC
	bl sub_811B8E8
	lsls r0, 24
	lsrs r0, 24
	bl sub_811F3B8
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	movs r0, 0
	bl sub_811F548
	b _0811B2EC
	.pool
_0811B2DC:
	bl sub_811B908
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	movs r0, 0x1
	bl sub_811F548
_0811B2EC:
	bl sub_811F5B0
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0
	beq _0811B324
	ldr r2, =gUnknown_0203A118
	ldr r3, [r2]
	subs r0, 0x1
	lsrs r1, r0, 31
	adds r0, r1
	asrs r0, 1
	movs r1, 0
	strb r0, [r3, 0xF]
	ldr r0, [r2]
	strb r1, [r0, 0xE]
	ldr r0, [r2]
	strb r1, [r0, 0x10]
	ldr r0, [r2]
	strb r1, [r0, 0x11]
	ldr r1, [r2]
	movs r0, 0x3
	strb r0, [r1, 0x4]
	movs r0, 0xB
	b _0811B326
	.pool
_0811B324:
	movs r0, 0
_0811B326:
	pop {r1}
	bx r1
	thumb_func_end sub_811B2B0

	thumb_func_start sub_811B32C
sub_811B32C: @ 811B32C
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x4]
	movs r0, 0xA
	bx lr
	.pool
	thumb_func_end sub_811B32C

	thumb_func_start sub_811B33C
sub_811B33C: @ 811B33C
	push {lr}
	ldr r1, =gUnknown_0203A118
	ldr r0, [r1]
	movs r2, 0
	strb r2, [r0, 0xA]
	ldr r0, [r1]
	strb r2, [r0, 0xB]
	ldr r0, [r1]
	strb r2, [r0, 0xC]
	ldr r1, [r1]
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	bne _0811B360
	movs r0, 0x1
	strb r0, [r1, 0x9]
	b _0811B362
	.pool
_0811B360:
	strb r2, [r1, 0x9]
_0811B362:
	movs r0, 0x17
	pop {r1}
	bx r1
	thumb_func_end sub_811B33C

	thumb_func_start sub_811B368
sub_811B368: @ 811B368
	push {lr}
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x6
	beq _0811B388
	ldr r0, =0x0000ffff
	bl sub_811B488
	movs r0, 0x1
	b _0811B390
	.pool
_0811B388:
	movs r0, 0x20
	bl PlaySE
	movs r0, 0
_0811B390:
	pop {r1}
	bx r1
	thumb_func_end sub_811B368

	thumb_func_start sub_811B394
sub_811B394: @ 811B394
	push {r4,r5,lr}
	bl sub_811B940
	lsls r0, 16
	lsrs r0, 16
	bl sub_811F578
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r4, 0
	bl sub_811BF88
	adds r5, r0, 0
	cmp r5, 0
	beq _0811B3BC
	movs r0, 0x20
	bl PlaySE
	movs r0, 0
	b _0811B3DC
_0811B3BC:
	adds r0, r4, 0
	bl sub_811B488
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, 0x6
	bne _0811B3D8
	movs r0, 0x9
	strb r0, [r1, 0x4]
	movs r0, 0xD
	b _0811B3DC
	.pool
_0811B3D8:
	strb r5, [r1, 0x4]
	movs r0, 0xC
_0811B3DC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811B394

	thumb_func_start sub_811B3E4
sub_811B3E4: @ 811B3E4
	push {r4,r5,lr}
	movs r4, 0
	ldr r3, =gUnknown_0203A118
	ldr r0, [r3]
	ldrb r0, [r0, 0x7]
	cmp r4, r0
	bge _0811B40E
	adds r5, r3, 0
_0811B3F4:
	ldr r3, [r5]
	ldr r1, [r3, 0x38]
	lsls r2, r4, 1
	adds r1, r2, r1
	adds r0, r3, 0
	adds r0, 0x3C
	adds r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r4, 0x1
	ldrb r3, [r3, 0x7]
	cmp r4, r3
	blt _0811B3F4
_0811B40E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811B3E4

	thumb_func_start sub_811B418
sub_811B418: @ 811B418
	push {r4,r5,lr}
	movs r3, 0
	ldr r2, =gUnknown_0203A118
	ldr r0, [r2]
	ldrb r0, [r0, 0x7]
	cmp r3, r0
	bge _0811B444
	adds r5, r2, 0
	ldr r0, =0x0000ffff
	adds r4, r0, 0
_0811B42C:
	ldr r2, [r5]
	lsls r0, r3, 1
	adds r1, r2, 0
	adds r1, 0x3C
	adds r1, r0
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r3, 0x1
	ldrb r2, [r2, 0x7]
	cmp r3, r2
	blt _0811B42C
_0811B444:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811B418

	thumb_func_start sub_811B454
sub_811B454: @ 811B454
	push {r4,r5,lr}
	movs r4, 0
	ldr r3, =gUnknown_0203A118
	ldr r0, [r3]
	ldrb r0, [r0, 0x7]
	cmp r4, r0
	bge _0811B47E
	adds r5, r3, 0
_0811B464:
	ldr r3, [r5]
	lsls r1, r4, 1
	adds r2, r3, 0
	adds r2, 0x3C
	adds r2, r1
	ldr r0, [r3, 0x38]
	adds r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
	adds r4, 0x1
	ldrb r3, [r3, 0x7]
	cmp r4, r3
	blt _0811B464
_0811B47E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811B454

	thumb_func_start sub_811B488
sub_811B488: @ 811B488
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	bl sub_811B8C8
	lsls r0, 16
	ldr r1, =gUnknown_0203A118
	ldr r1, [r1]
	lsrs r0, 15
	adds r1, 0x3C
	adds r1, r0
	strh r4, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811B488

	thumb_func_start sub_811B4AC
sub_811B4AC: @ 811B4AC
	push {r4,r5,lr}
	movs r2, 0
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r1, [r0, 0x7]
	cmp r2, r1
	bcs _0811B4E2
	adds r5, r1, 0
	adds r4, r0, 0
	adds r4, 0x3C
	ldr r3, [r0, 0x38]
_0811B4C2:
	lsls r0, r2, 1
	adds r1, r4, r0
	adds r0, r3
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _0811B4D8
	movs r0, 0x1
	b _0811B4E4
	.pool
_0811B4D8:
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, r5
	bcc _0811B4C2
_0811B4E2:
	movs r0, 0
_0811B4E4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811B4AC

	thumb_func_start sub_811B4EC
sub_811B4EC: @ 811B4EC
	push {lr}
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0]
	subs r0, 0x11
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bhi _0811B51C
	bl sub_811BD64
	cmp r0, 0
	bne _0811B50E
	bl sub_811BDB0
	cmp r0, 0
	beq _0811B518
_0811B50E:
	movs r0, 0
	b _0811B524
	.pool
_0811B518:
	movs r0, 0x1
	b _0811B524
_0811B51C:
	bl sub_811B4AC
	lsls r0, 24
	lsrs r0, 24
_0811B524:
	pop {r1}
	bx r1
	thumb_func_end sub_811B4EC

	thumb_func_start sub_811B528
sub_811B528: @ 811B528
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A118
	ldr r3, [r0]
	movs r1, 0xA
	ldrsb r1, [r3, r1]
	movs r0, 0x1
	negs r0, r0
	cmp r1, r0
	beq _0811B558
	ldrb r0, [r3, 0x9]
	cmp r0, 0
	bne _0811B550
	adds r0, r2, 0
	bl sub_811B568
	b _0811B55E
	.pool
_0811B550:
	adds r0, r2, 0
	bl sub_811B634
	b _0811B55E
_0811B558:
	adds r0, r2, 0
	bl sub_811B6C4
_0811B55E:
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_811B528

	thumb_func_start sub_811B568
sub_811B568: @ 811B568
	push {r4,lr}
	cmp r0, 0x1
	beq _0811B5DE
	cmp r0, 0x1
	bcc _0811B5FE
	cmp r0, 0x2
	beq _0811B57C
	cmp r0, 0x3
	beq _0811B5A4
	b _0811B62A
_0811B57C:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	movs r0, 0xB
	ldrsb r0, [r1, r0]
	ldrb r3, [r1, 0xC]
	cmn r0, r3
	beq _0811B62A
	ldrb r2, [r1, 0xB]
	cmp r0, 0
	beq _0811B59C
	subs r0, r2, 0x1
	strb r0, [r1, 0xB]
_0811B594:
	movs r0, 0xF
	b _0811B62C
	.pool
_0811B59C:
	subs r0, r3, 0x1
	strb r0, [r1, 0xC]
	movs r0, 0x11
	b _0811B62C
_0811B5A4:
	ldr r0, =gUnknown_0203A118
	ldr r2, [r0]
	movs r1, 0xB
	ldrsb r1, [r2, r1]
	ldrb r3, [r2, 0xC]
	adds r1, r3
	ldrb r0, [r2, 0xD]
	subs r0, 0x1
	cmp r1, r0
	bge _0811B62A
	ldrb r1, [r2, 0xB]
	movs r0, 0xB
	ldrsb r0, [r2, r0]
	cmp r0, 0x2
	bgt _0811B5D0
	adds r0, r1, 0x1
	strb r0, [r2, 0xB]
	movs r4, 0xF
	b _0811B5D6
	.pool
_0811B5D0:
	adds r0, r3, 0x1
	strb r0, [r2, 0xC]
	movs r4, 0x10
_0811B5D6:
	bl sub_811B978
	adds r0, r4, 0
	b _0811B62C
_0811B5DE:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r2, [r1, 0xA]
	movs r0, 0xA
	ldrsb r0, [r1, r0]
	cmp r0, 0
	beq _0811B5F8
	subs r0, r2, 0x1
	strb r0, [r1, 0xA]
	b _0811B594
	.pool
_0811B5F8:
	bl sub_811B744
	b _0811B594
_0811B5FE:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r2, [r1, 0xA]
	movs r0, 0xA
	ldrsb r0, [r1, r0]
	cmp r0, 0
	bgt _0811B624
	adds r0, r2, 0x1
	strb r0, [r1, 0xA]
	bl sub_811B9C8
	lsls r0, 24
	cmp r0, 0
	beq _0811B594
	bl sub_811B744
	b _0811B594
	.pool
_0811B624:
	bl sub_811B744
	b _0811B594
_0811B62A:
	movs r0, 0
_0811B62C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811B568

	thumb_func_start sub_811B634
sub_811B634: @ 811B634
	push {lr}
	cmp r0, 0x1
	beq _0811B6A0
	cmp r0, 0x1
	bcc _0811B684
	cmp r0, 0x2
	beq _0811B64A
	cmp r0, 0x3
	beq _0811B66A
	movs r0, 0
	b _0811B6BC
_0811B64A:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r2, [r1, 0xB]
	movs r0, 0xB
	ldrsb r0, [r1, r0]
	cmp r0, 0
	ble _0811B660
	subs r0, r2, 0x1
	b _0811B662
	.pool
_0811B660:
	movs r0, 0x3
_0811B662:
	strb r0, [r1, 0xB]
	bl sub_811B978
	b _0811B6BA
_0811B66A:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r2, [r1, 0xB]
	movs r0, 0xB
	ldrsb r0, [r1, r0]
	cmp r0, 0x2
	bgt _0811B680
	adds r0, r2, 0x1
	b _0811B662
	.pool
_0811B680:
	movs r0, 0
	b _0811B662
_0811B684:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r0, [r1, 0xA]
	adds r0, 0x1
	strb r0, [r1, 0xA]
	bl sub_811B9C8
	lsls r0, 24
	cmp r0, 0
	beq _0811B6BA
	b _0811B6B6
	.pool
_0811B6A0:
	ldr r2, =gUnknown_0203A118
	ldr r1, [r2]
	ldrb r0, [r1, 0xA]
	subs r0, 0x1
	strb r0, [r1, 0xA]
	ldr r0, [r2]
	ldrb r0, [r0, 0xA]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0
	bge _0811B6BA
_0811B6B6:
	bl sub_811B744
_0811B6BA:
	movs r0, 0xF
_0811B6BC:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811B634

	thumb_func_start sub_811B6C4
sub_811B6C4: @ 811B6C4
	push {lr}
	adds r2, r0, 0
	cmp r2, 0x1
	beq _0811B714
	cmp r2, 0x1
	bcc _0811B728
	cmp r2, 0x2
	beq _0811B6DC
	cmp r2, 0x3
	beq _0811B6F8
	movs r0, 0
	b _0811B73A
_0811B6DC:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r3, [r1, 0xB]
	movs r0, 0xB
	ldrsb r0, [r1, r0]
	cmp r0, 0
	beq _0811B6F4
	subs r0, r3, 0x1
	b _0811B736
	.pool
_0811B6F4:
	strb r2, [r1, 0xB]
	b _0811B738
_0811B6F8:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r2, [r1, 0xB]
	movs r0, 0xB
	ldrsb r0, [r1, r0]
	cmp r0, 0x1
	bgt _0811B710
	adds r0, r2, 0x1
	b _0811B736
	.pool
_0811B710:
	movs r0, 0
	b _0811B736
_0811B714:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r0, [r1, 0xB]
	adds r0, 0x1
	strb r0, [r1, 0xB]
	bl sub_811B768
	b _0811B738
	.pool
_0811B728:
	ldr r2, =gUnknown_0203A118
	ldr r1, [r2]
	movs r0, 0
	strb r0, [r1, 0xA]
	ldr r1, [r2]
	ldrb r0, [r1, 0xB]
	adds r0, 0x1
_0811B736:
	strb r0, [r1, 0xB]
_0811B738:
	movs r0, 0xF
_0811B73A:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811B6C4

	thumb_func_start sub_811B744
sub_811B744: @ 811B744
	push {lr}
	ldr r2, =gUnknown_0203A118
	ldr r1, [r2]
	movs r0, 0xFF
	strb r0, [r1, 0xA]
	ldr r2, [r2]
	ldrb r1, [r2, 0xB]
	movs r0, 0xB
	ldrsb r0, [r2, r0]
	cmp r0, 0
	beq _0811B75E
	subs r0, r1, 0x1
	strb r0, [r2, 0xB]
_0811B75E:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811B744

	thumb_func_start sub_811B768
sub_811B768: @ 811B768
	push {r4,lr}
	ldr r4, =gUnknown_0203A118
	ldr r1, [r4]
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	bne _0811B784
	movs r0, 0x1
	strb r0, [r1, 0xA]
	bl sub_811B978
	b _0811B78E
	.pool
_0811B784:
	ldrb r0, [r1, 0xB]
	bl sub_811B960
	ldr r1, [r4]
	strb r0, [r1, 0xA]
_0811B78E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811B768

	thumb_func_start sub_811B794
sub_811B794: @ 811B794
	push {r4,lr}
	cmp r0, 0x5
	bls _0811B79C
	b _0811B8C0
_0811B79C:
	lsls r0, 2
	ldr r1, =_0811B7AC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811B7AC:
	.4byte _0811B848
	.4byte _0811B826
	.4byte _0811B7C4
	.4byte _0811B7F0
	.4byte _0811B870
	.4byte _0811B890
_0811B7C4:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	movs r0, 0x11
	ldrsb r0, [r1, r0]
	ldrb r3, [r1, 0xE]
	adds r0, r3
	cmp r0, 0
	bgt _0811B7D6
	b _0811B8C0
_0811B7D6:
	ldrb r2, [r1, 0x11]
	movs r0, 0x11
	ldrsb r0, [r1, r0]
	cmp r0, 0
	ble _0811B7E8
	subs r0, r2, 0x1
	b _0811B80E
	.pool
_0811B7E8:
	subs r0, r3, 0x1
	strb r0, [r1, 0xE]
	movs r4, 0x13
	b _0811B81E
_0811B7F0:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	movs r0, 0x11
	ldrsb r0, [r1, r0]
	ldrb r3, [r1, 0xE]
	adds r0, r3
	ldrb r2, [r1, 0xF]
	cmp r0, r2
	bge _0811B8C0
	ldrb r2, [r1, 0x11]
	movs r0, 0x11
	ldrsb r0, [r1, r0]
	cmp r0, 0x2
	bgt _0811B818
	adds r0, r2, 0x1
_0811B80E:
	strb r0, [r1, 0x11]
	movs r4, 0x12
	b _0811B81E
	.pool
_0811B818:
	adds r0, r3, 0x1
	strb r0, [r1, 0xE]
	movs r4, 0x14
_0811B81E:
	bl sub_811B9A0
	adds r0, r4, 0
	b _0811B8C2
_0811B826:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r2, [r1, 0x10]
	movs r0, 0x10
	ldrsb r0, [r1, r0]
	cmp r0, 0
	ble _0811B83C
	subs r0, r2, 0x1
	b _0811B83E
	.pool
_0811B83C:
	movs r0, 0x1
_0811B83E:
	strb r0, [r1, 0x10]
	bl sub_811B9A0
_0811B844:
	movs r0, 0x12
	b _0811B8C2
_0811B848:
	ldr r4, =gUnknown_0203A118
	ldr r1, [r4]
	ldrb r2, [r1, 0x10]
	movs r0, 0x10
	ldrsb r0, [r1, r0]
	cmp r0, 0
	bgt _0811B866
	adds r0, r2, 0x1
	strb r0, [r1, 0x10]
	bl sub_811BA1C
	lsls r0, 24
	cmp r0, 0
	beq _0811B844
	ldr r1, [r4]
_0811B866:
	movs r0, 0
	strb r0, [r1, 0x10]
	b _0811B844
	.pool
_0811B870:
	ldr r0, =gUnknown_0203A118
	ldr r2, [r0]
	ldrb r0, [r2, 0xE]
	adds r1, r0, 0
	cmp r1, 0
	beq _0811B8C0
	cmp r1, 0x3
	bls _0811B888
	subs r0, 0x4
	b _0811B88A
	.pool
_0811B888:
	movs r0, 0
_0811B88A:
	strb r0, [r2, 0xE]
	movs r0, 0x15
	b _0811B8C2
_0811B890:
	ldr r3, =gUnknown_0203A118
	ldr r1, [r3]
	ldrb r2, [r1, 0xE]
	ldrb r0, [r1, 0xF]
	subs r0, 0x4
	cmp r2, r0
	bgt _0811B8C0
	adds r0, r2, 0x4
	strb r0, [r1, 0xE]
	ldr r2, [r3]
	ldrb r1, [r2, 0xE]
	ldrb r3, [r2, 0xF]
	subs r0, r3, 0x3
	cmp r1, r0
	ble _0811B8B4
	adds r0, r3, 0
	adds r0, 0xFD
	strb r0, [r2, 0xE]
_0811B8B4:
	bl sub_811B9A0
	movs r0, 0x16
	b _0811B8C2
	.pool
_0811B8C0:
	movs r0, 0
_0811B8C2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811B794

	thumb_func_start sub_811B8C8
sub_811B8C8: @ 811B8C8
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	movs r2, 0x6
	ldrsb r2, [r0, r2]
	ldrb r1, [r0, 0x2]
	muls r1, r2
	ldrb r0, [r0, 0x5]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end sub_811B8C8

	thumb_func_start sub_811B8E8
sub_811B8E8: @ 811B8E8
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	movs r1, 0xB
	ldrsb r1, [r0, r1]
	ldrb r2, [r0, 0xC]
	adds r1, r2
	lsls r1, 1
	ldrb r0, [r0, 0xA]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end sub_811B8E8

	thumb_func_start sub_811B908
sub_811B908: @ 811B908
	push {lr}
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r0, [r1, 0xA]
	movs r3, 0
	cmp r0, 0x6
	bhi _0811B91A
	movs r3, 0xA
	ldrsb r3, [r1, r3]
_0811B91A:
	ldrb r0, [r1, 0xB]
	movs r2, 0
	cmp r0, 0x3
	bhi _0811B926
	movs r2, 0xB
	ldrsb r2, [r1, r2]
_0811B926:
	ldr r0, =gUnknown_08597748
	lsls r1, r2, 3
	subs r1, r2
	adds r1, r3, r1
	adds r1, r0
	ldrb r0, [r1]
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811B908

	thumb_func_start sub_811B940
sub_811B940: @ 811B940
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	movs r1, 0x11
	ldrsb r1, [r0, r1]
	ldrb r2, [r0, 0xE]
	adds r1, r2
	lsls r1, 1
	ldrb r0, [r0, 0x10]
	lsls r0, 24
	asrs r0, 24
	adds r0, r1
	lsls r0, 16
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end sub_811B940

	thumb_func_start sub_811B960
sub_811B960: @ 811B960
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0811B96E
	cmp r0, 0x1
	beq _0811B972
_0811B96E:
	movs r0, 0x6
	b _0811B974
_0811B972:
	movs r0, 0x5
_0811B974:
	pop {r1}
	bx r1
	thumb_func_end sub_811B960

	thumb_func_start sub_811B978
sub_811B978: @ 811B978
	push {lr}
	b _0811B98E
_0811B97C:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r2, [r1, 0xA]
	movs r0, 0xA
	ldrsb r0, [r1, r0]
	cmp r0, 0
	beq _0811B998
	subs r0, r2, 0x1
	strb r0, [r1, 0xA]
_0811B98E:
	bl sub_811B9C8
	lsls r0, 24
	cmp r0, 0
	bne _0811B97C
_0811B998:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811B978

	thumb_func_start sub_811B9A0
sub_811B9A0: @ 811B9A0
	push {lr}
	b _0811B9B6
_0811B9A4:
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r2, [r1, 0x10]
	movs r0, 0x10
	ldrsb r0, [r1, r0]
	cmp r0, 0
	beq _0811B9C0
	subs r0, r2, 0x1
	strb r0, [r1, 0x10]
_0811B9B6:
	bl sub_811BA1C
	lsls r0, 24
	cmp r0, 0
	bne _0811B9A4
_0811B9C0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811B9A0

	thumb_func_start sub_811B9C8
sub_811B9C8: @ 811B9C8
	push {r4,lr}
	ldr r4, =gUnknown_0203A118
	ldr r1, [r4]
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	bne _0811B9F8
	bl sub_811B8E8
	adds r4, r0, 0
	bl sub_811F3AC
	movs r1, 0
	lsls r0, 24
	lsls r4, 16
	lsrs r4, 16
	lsrs r0, 24
	cmp r4, r0
	bcc _0811B9EE
	movs r1, 0x1
_0811B9EE:
	adds r0, r1, 0
	b _0811BA14
	.pool
_0811B9F8:
	ldrb r0, [r1, 0xB]
	bl sub_811B960
	movs r2, 0
	ldr r1, [r4]
	ldrb r1, [r1, 0xA]
	lsls r1, 24
	asrs r1, 24
	lsls r0, 24
	lsrs r0, 24
	cmp r1, r0
	ble _0811BA12
	movs r2, 0x1
_0811BA12:
	adds r0, r2, 0
_0811BA14:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811B9C8

	thumb_func_start sub_811BA1C
sub_811BA1C: @ 811BA1C
	push {r4,lr}
	bl sub_811B940
	adds r4, r0, 0
	bl sub_811F5B0
	movs r1, 0
	lsls r4, 16
	lsls r0, 16
	cmp r4, r0
	bcc _0811BA34
	movs r1, 0x1
_0811BA34:
	adds r0, r1, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811BA1C

	thumb_func_start sub_811BA3C
sub_811BA3C: @ 811BA3C
	ldr r2, =gUnknown_08597550
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x3]
	lsrs r0, 7
	bx lr
	.pool
	thumb_func_end sub_811BA3C

	thumb_func_start sub_811BA5C
sub_811BA5C: @ 811BA5C
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_811BA5C

	thumb_func_start sub_811BA68
sub_811BA68: @ 811BA68
	ldr r2, =gUnknown_08597550
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x3]
	lsls r0, 25
	lsrs r0, 25
	bx lr
	.pool
	thumb_func_end sub_811BA68

	thumb_func_start sub_811BA88
sub_811BA88: @ 811BA88
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldr r0, [r0, 0x34]
	bx lr
	.pool
	thumb_func_end sub_811BA88

	thumb_func_start sub_811BA94
sub_811BA94: @ 811BA94
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	adds r0, 0x3C
	bx lr
	.pool
	thumb_func_end sub_811BA94

	thumb_func_start sub_811BAA0
sub_811BAA0: @ 811BAA0
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0x3]
	bx lr
	.pool
	thumb_func_end sub_811BAA0

	thumb_func_start sub_811BAAC
sub_811BAAC: @ 811BAAC
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	bx lr
	.pool
	thumb_func_end sub_811BAAC

	thumb_func_start sub_811BAB8
sub_811BAB8: @ 811BAB8
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0x5]
	bx lr
	.pool
	thumb_func_end sub_811BAB8

	thumb_func_start sub_811BAC4
sub_811BAC4: @ 811BAC4
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0x6]
	bx lr
	.pool
	thumb_func_end sub_811BAC4

	thumb_func_start sub_811BAD0
sub_811BAD0: @ 811BAD0
	push {r4,r5,lr}
	ldr r4, =gUnknown_08597550
	ldr r2, =gUnknown_0203A118
	ldr r5, [r2]
	ldrb r3, [r5, 0x1]
	lsls r2, r3, 1
	adds r2, r3
	lsls r2, 3
	adds r3, r4, 0
	adds r3, 0x8
	adds r2, r3
	ldr r2, [r2]
	str r2, [r0]
	ldrb r2, [r5, 0x1]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r4, 0xC
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811BAD0

	thumb_func_start sub_811BB08
sub_811BB08: @ 811BB08
	push {r4,r5,lr}
	ldr r4, =gUnknown_08597550
	ldr r2, =gUnknown_0203A118
	ldr r5, [r2]
	ldrb r3, [r5, 0x1]
	lsls r2, r3, 1
	adds r2, r3
	lsls r2, 3
	adds r3, r4, 0
	adds r3, 0x10
	adds r2, r3
	ldr r2, [r2]
	str r2, [r0]
	ldrb r2, [r5, 0x1]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 3
	adds r4, 0x14
	adds r0, r4
	ldr r0, [r0]
	str r0, [r1]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811BB08

	thumb_func_start sub_811BB40
sub_811BB40: @ 811BB40
	push {lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x4
	bne _0811BB5C
	ldr r0, =gText_StopGivingPkmnMail
	b _0811BB7A
	.pool
_0811BB5C:
	cmp r0, 0x4
	blt _0811BB78
	cmp r0, 0x10
	bgt _0811BB78
	cmp r0, 0xF
	blt _0811BB78
	ldr r0, =gText_LikeToQuitQuiz
	str r0, [r2]
	ldr r0, =gText_ChallengeQuestionMark
	b _0811BB7E
	.pool
_0811BB78:
	ldr r0, =gText_QuitEditing
_0811BB7A:
	str r0, [r2]
	movs r0, 0
_0811BB7E:
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811BB40

	thumb_func_start sub_811BB88
sub_811BB88: @ 811BB88
	ldr r2, =gText_AllTextBeingEditedWill
	str r2, [r0]
	ldr r0, =gText_BeDeletedThatOkay
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_811BB88

	thumb_func_start sub_811BB9C
sub_811BB9C: @ 811BB9C
	ldr r2, =gUnknown_0203A118
	ldr r3, [r2]
	ldrb r2, [r3, 0xA]
	strb r2, [r0]
	ldrb r0, [r3, 0xB]
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_811BB9C

	thumb_func_start sub_811BBB0
sub_811BBB0: @ 811BBB0
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0x9]
	bx lr
	.pool
	thumb_func_end sub_811BBB0

	thumb_func_start sub_811BBBC
sub_811BBBC: @ 811BBBC
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0xC]
	bx lr
	.pool
	thumb_func_end sub_811BBBC

	thumb_func_start sub_811BBC8
sub_811BBC8: @ 811BBC8
	ldr r2, =gUnknown_0203A118
	ldr r3, [r2]
	ldrb r2, [r3, 0x10]
	strb r2, [r0]
	ldrb r0, [r3, 0x11]
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_811BBC8

	thumb_func_start sub_811BBDC
sub_811BBDC: @ 811BBDC
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0xE]
	bx lr
	.pool
	thumb_func_end sub_811BBDC

	thumb_func_start sub_811BBE8
sub_811BBE8: @ 811BBE8
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0xF]
	bx lr
	.pool
	thumb_func_end sub_811BBE8

	thumb_func_start sub_811BBF4
sub_811BBF4: @ 811BBF4
	movs r0, 0
	bx lr
	thumb_func_end sub_811BBF4

	thumb_func_start sub_811BBF8
sub_811BBF8: @ 811BBF8
	push {lr}
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	ldrb r0, [r1, 0x4]
	cmp r0, 0x2
	beq _0811BC10
	cmp r0, 0x3
	beq _0811BC1A
	b _0811BC24
	.pool
_0811BC10:
	ldrb r0, [r1, 0x9]
	cmp r0, 0
	bne _0811BC24
	ldrb r0, [r1, 0xC]
	b _0811BC1C
_0811BC1A:
	ldrb r0, [r1, 0xE]
_0811BC1C:
	cmp r0, 0
	beq _0811BC24
	movs r0, 0x1
	b _0811BC26
_0811BC24:
	movs r0, 0
_0811BC26:
	pop {r1}
	bx r1
	thumb_func_end sub_811BBF8

	thumb_func_start sub_811BC2C
sub_811BC2C: @ 811BC2C
	push {lr}
	ldr r0, =gUnknown_0203A118
	ldr r2, [r0]
	ldrb r0, [r2, 0x4]
	cmp r0, 0x2
	beq _0811BC44
	cmp r0, 0x3
	beq _0811BC5A
	b _0811BC68
	.pool
_0811BC44:
	ldrb r0, [r2, 0x9]
	cmp r0, 0
	bne _0811BC68
	ldrb r1, [r2, 0xC]
	adds r1, 0x4
	ldrb r0, [r2, 0xD]
	subs r0, 0x1
	cmp r1, r0
	bgt _0811BC68
	movs r0, 0x1
	b _0811BC6A
_0811BC5A:
	ldrb r0, [r2, 0xE]
	adds r0, 0x4
	ldrb r2, [r2, 0xF]
	cmp r0, r2
	bgt _0811BC68
	movs r0, 0x1
	b _0811BC6A
_0811BC68:
	movs r0, 0
_0811BC6A:
	pop {r1}
	bx r1
	thumb_func_end sub_811BC2C

	thumb_func_start sub_811BC70
sub_811BC70: @ 811BC70
	push {lr}
	bl sub_811BA3C
	pop {r1}
	bx r1
	thumb_func_end sub_811BC70

	thumb_func_start sub_811BC7C
sub_811BC7C: @ 811BC7C
	push {r4,r5,lr}
	adds r5, r0, 0
	lsls r1, 24
	lsrs r3, r1, 24
	movs r2, 0
	cmp r2, r3
	bcs _0811BCB2
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	adds r4, r0, 0
	adds r4, 0x3C
_0811BC92:
	lsls r0, r2, 1
	adds r1, r0, r5
	adds r0, r4, r0
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _0811BCA8
	movs r0, 0x1
	b _0811BCB4
	.pool
_0811BCA8:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, r3
	bcc _0811BC92
_0811BCB2:
	movs r0, 0
_0811BCB4:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811BC7C

	thumb_func_start sub_811BCBC
sub_811BCBC: @ 811BCBC
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0, 0x12]
	bx lr
	.pool
	thumb_func_end sub_811BCBC

	thumb_func_start sub_811BCC8
sub_811BCC8: @ 811BCC8
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r1, 0
	ldr r2, =gUnknown_08597550
_0811BCD2:
	ldrb r0, [r2]
	cmp r0, r3
	bne _0811BCE4
	lsls r0, r1, 24
	lsrs r0, 24
	b _0811BCEE
	.pool
_0811BCE4:
	adds r2, 0x18
	adds r1, 0x1
	cmp r1, 0x14
	bls _0811BCD2
	movs r0, 0
_0811BCEE:
	pop {r1}
	bx r1
	thumb_func_end sub_811BCC8

	thumb_func_start sub_811BCF4
sub_811BCF4: @ 811BCF4
	push {r4,lr}
	movs r2, 0
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r1, [r0, 0x7]
	cmp r2, r1
	bge _0811BD24
	ldr r4, =0x0000ffff
	adds r3, r1, 0
	adds r1, r0, 0
	adds r1, 0x3C
_0811BD0A:
	ldrh r0, [r1]
	cmp r0, r4
	beq _0811BD1C
	movs r0, 0
	b _0811BD26
	.pool
_0811BD1C:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, r3
	blt _0811BD0A
_0811BD24:
	movs r0, 0x1
_0811BD26:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811BCF4

	thumb_func_start sub_811BD2C
sub_811BD2C: @ 811BD2C
	push {r4,lr}
	movs r2, 0
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r1, [r0, 0x7]
	cmp r2, r1
	bge _0811BD5C
	ldr r4, =0x0000ffff
	adds r3, r1, 0
	adds r1, r0, 0
	adds r1, 0x3C
_0811BD42:
	ldrh r0, [r1]
	cmp r0, r4
	bne _0811BD54
	movs r0, 0
	b _0811BD5E
	.pool
_0811BD54:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, r3
	blt _0811BD42
_0811BD5C:
	movs r0, 0x1
_0811BD5E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811BD2C

	thumb_func_start sub_811BD64
sub_811BD64: @ 811BD64
	push {r4,lr}
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x11
	bne _0811BD80
	bl sub_811BCF4
	b _0811BD9C
	.pool
_0811BD7C:
	movs r0, 0
	b _0811BD9C
_0811BD80:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	movs r2, 0
	ldr r3, =0x0000ffff
	ldr r4, =0x00003b5a
	adds r1, r0, r4
_0811BD8C:
	ldrh r0, [r1]
	cmp r0, r3
	bne _0811BD7C
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0x8
	ble _0811BD8C
	movs r0, 0x1
_0811BD9C:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811BD64

	thumb_func_start sub_811BDB0
sub_811BDB0: @ 811BDB0
	push {lr}
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, 0x12
	bne _0811BDC8
	bl sub_811BCF4
	b _0811BDDE
	.pool
_0811BDC8:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00003b58
	adds r0, r1
	movs r2, 0
	ldrh r1, [r0, 0x14]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _0811BDDC
	movs r2, 0x1
_0811BDDC:
	adds r0, r2, 0
_0811BDDE:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811BDB0

	thumb_func_start sub_811BDF0
sub_811BDF0: @ 811BDF0
	push {r4-r6,lr}
	sub sp, 0x20
	adds r6, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r4, [r0]
	bl DynamicPlaceholderTextUtil_Reset
	ldr r0, =0x00003b70
	adds r5, r4, r0
	adds r0, r5, 0
	bl StringLength
	lsls r0, 16
	cmp r0, 0
	beq _0811BE34
	ldr r1, =0x00003b85
	adds r0, r4, r1
	ldrb r2, [r0]
	mov r0, sp
	adds r1, r5, 0
	bl TVShowConvertInternationalString
	movs r0, 0
	mov r1, sp
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	b _0811BE3C
	.pool
_0811BE34:
	ldr r1, =gText_Lady
	movs r0, 0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
_0811BE3C:
	ldr r1, =gText_F700sQuiz
	adds r0, r6, 0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	add sp, 0x20
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811BDF0

	thumb_func_start sub_811BE54
sub_811BE54: @ 811BE54
	push {r4,r5,lr}
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
	adds r4, r0, 0
	adds r4, 0x3C
	ldr r2, =gStringVar2
	movs r5, 0
	b _0811BE86
	.pool
_0811BE6C:
	ldrh r1, [r4]
	adds r0, r2, 0
	movs r2, 0
	bl CopyEasyChatWordPadded
	adds r2, r0, 0
	movs r0, 0
	strb r0, [r2]
	adds r2, 0x1
	adds r4, 0x2
	adds r5, 0x1
	ldr r0, =gUnknown_0203A118
	ldr r0, [r0]
_0811BE86:
	ldrb r0, [r0, 0x7]
	cmp r5, r0
	blt _0811BE6C
	subs r2, 0x1
	movs r0, 0xFF
	strb r0, [r2]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811BE54

	thumb_func_start sub_811BE9C
sub_811BE9C: @ 811BE9C
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203A118
	ldr r0, [r5]
	ldrb r0, [r0]
	cmp r0, 0x9
	beq _0811BEF0
	cmp r0, 0x9
	bgt _0811BEB8
	cmp r0, 0
	beq _0811BEC2
	b _0811BF14
	.pool
_0811BEB8:
	cmp r0, 0xD
	beq _0811BF0C
	cmp r0, 0x14
	beq _0811BED0
	b _0811BF14
_0811BEC2:
	ldr r0, =0x00000865
	bl FlagSet
	b _0811BF14
	.pool
_0811BED0:
	bl sub_811BF20
	adds r1, r0, 0
	cmp r1, 0
	beq _0811BEE4
	ldr r1, =gSpecialVar_0x8004
	movs r0, 0x2
	b _0811BF12
	.pool
_0811BEE4:
	ldr r0, =gSpecialVar_0x8004
	strh r1, [r0]
	b _0811BF14
	.pool
_0811BEF0:
	bl sub_811BE54
	ldr r4, =gSpecialVar_0x8004
	ldr r0, [r5]
	adds r0, 0x3C
	bl sub_81226D8
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4]
	b _0811BF14
	.pool
_0811BF0C:
	bl sub_811BF40
	ldr r1, =gSpecialVar_0x8004
_0811BF12:
	strh r0, [r1]
_0811BF14:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811BE9C

	thumb_func_start sub_811BF20
sub_811BF20: @ 811BF20
	push {lr}
	ldr r0, =gUnknown_08597764
	movs r1, 0x4
	bl sub_811BC7C
	movs r1, 0
	lsls r0, 24
	cmp r0, 0
	bne _0811BF34
	movs r1, 0x1
_0811BF34:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811BF20

	thumb_func_start sub_811BF40
sub_811BF40: @ 811BF40
	push {r4,r5,lr}
	movs r4, 0
	movs r5, 0x80
	lsls r5, 9
_0811BF48:
	lsls r0, r4, 2
	ldr r1, =gUnknown_0859776C
	adds r0, r1
	movs r1, 0x2
	bl sub_811BC7C
	lsls r0, 24
	cmp r0, 0
	bne _0811BF64
	lsrs r0, r5, 16
	b _0811BF72
	.pool
_0811BF64:
	movs r0, 0x80
	lsls r0, 9
	adds r5, r0
	adds r4, 0x1
	cmp r4, 0x4
	ble _0811BF48
	movs r0, 0
_0811BF72:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811BF40

	thumb_func_start sub_811BF78
sub_811BF78: @ 811BF78
	ldr r0, =gUnknown_0203A118
	ldr r1, [r0]
	movs r0, 0
	strb r0, [r1, 0x13]
	bx lr
	.pool
	thumb_func_end sub_811BF78

	thumb_func_start sub_811BF88
sub_811BF88: @ 811BF88
	movs r0, 0
	bx lr
	thumb_func_end sub_811BF88

	thumb_func_start sub_811BF8C
sub_811BF8C: @ 811BF8C
	push {lr}
	bl sub_811CE94
	lsls r0, 24
	cmp r0, 0
	beq _0811BF9C
	movs r0, 0x1
	b _0811BF9E
_0811BF9C:
	movs r0, 0
_0811BF9E:
	pop {r1}
	bx r1
	thumb_func_end sub_811BF8C

	thumb_func_start sub_811BFA4
sub_811BFA4: @ 811BFA4
	push {r4,lr}
	sub sp, 0x8
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x5
	bls _0811BFB4
	b _0811C120
_0811BFB4:
	lsls r0, 2
	ldr r1, =_0811BFC8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811BFC8:
	.4byte _0811BFE0
	.4byte _0811C044
	.4byte _0811C090
	.4byte _0811C0AC
	.4byte _0811C0BE
	.4byte _0811C0D4
_0811BFE0:
	movs r0, 0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, =gUnknown_08597C54
	movs r0, 0
	movs r2, 0x4
	bl InitBgsFromTemplates
	ldr r4, =gUnknown_0203A11C
	ldr r1, [r4]
	movs r0, 0xB0
	lsls r0, 4
	adds r1, r0
	movs r0, 0x3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r0, 0xC0
	lsls r0, 2
	adds r1, r0
	movs r0, 0x1
	bl SetBgTilemapBuffer
	ldr r0, =gUnknown_08597C64
	bl InitWindows
	bl DeactivateAllTextPrinters
	bl sub_811CF64
	bl sub_811CF04
	movs r0, 0
	str r0, [sp, 0x4]
	movs r1, 0xE0
	lsls r1, 19
	ldr r2, =0x01000100
	add r0, sp, 0x4
	bl CpuFastSet
	b _0811C124
	.pool
_0811C044:
	ldr r1, =gEasyChatWindow_Gfx
	movs r0, 0
	str r0, [sp]
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl DecompressAndLoadBgGfxUsingHeap
	ldr r1, =gEasyChatWindow_Tilemap
	movs r0, 0x3
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	bl sub_811D60C
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 2
	adds r0, r1
	bl sub_811D424
	bl sub_811D230
	bl sub_811E948
	movs r0, 0x3
	bl CopyBgTilemapBufferToVram
	b _0811C124
	.pool
_0811C090:
	ldr r1, =gUnknown_08597B54
	movs r0, 0
	str r0, [sp]
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl DecompressAndLoadBgGfxUsingHeap
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	b _0811C124
	.pool
_0811C0AC:
	bl sub_811CFCC
	bl sub_811D0BC
	bl sub_811D2C8
	bl sub_811D684
	b _0811C124
_0811C0BE:
	bl sub_811DE90
	bl sub_811BA5C
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x10
	beq _0811C124
	bl sub_811DEC4
	b _0811C124
_0811C0D4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811C12E
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_811DE5C
	movs r0, 0x48
	movs r1, 0x3F
	bl SetGpuReg
	movs r0, 0x4A
	movs r1, 0x3B
	bl SetGpuReg
	movs r0, 0x3
	bl ShowBg
	movs r0, 0x1
	bl ShowBg
	movs r0, 0x2
	bl ShowBg
	movs r0, 0
	bl ShowBg
	bl sub_811E5D4
	bl sub_811E720
	bl sub_811E828
	b _0811C124
_0811C120:
	movs r0, 0
	b _0811C130
_0811C124:
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811C12E:
	movs r0, 0x1
_0811C130:
	add sp, 0x8
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811BFA4

	thumb_func_start sub_811C13C
sub_811C13C: @ 811C13C
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	cmp r0, 0
	beq _0811C14E
	bl Free
	movs r0, 0
	str r0, [r4]
_0811C14E:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811C13C

	thumb_func_start sub_811C158
sub_811C158: @ 811C158
	push {lr}
	ldr r1, =gUnknown_0203A11C
	ldr r1, [r1]
	movs r2, 0
	strh r0, [r1, 0x4]
	strh r2, [r1]
	bl sub_811C170
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811C158

	thumb_func_start sub_811C170
sub_811C170: @ 811C170
	push {lr}
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrh r0, [r0, 0x4]
	cmp r0, 0x22
	bls _0811C17E
	b _0811C2CE
_0811C17E:
	lsls r0, 2
	ldr r1, =_0811C190
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811C190:
	.4byte _0811C2CE
	.4byte _0811C21C
	.4byte _0811C222
	.4byte _0811C228
	.4byte _0811C22E
	.4byte _0811C234
	.4byte _0811C23A
	.4byte _0811C240
	.4byte _0811C246
	.4byte _0811C24C
	.4byte _0811C252
	.4byte _0811C258
	.4byte _0811C25E
	.4byte _0811C264
	.4byte _0811C26A
	.4byte _0811C270
	.4byte _0811C276
	.4byte _0811C27C
	.4byte _0811C282
	.4byte _0811C288
	.4byte _0811C28E
	.4byte _0811C294
	.4byte _0811C29A
	.4byte _0811C2A0
	.4byte _0811C2CE
	.4byte _0811C2CE
	.4byte _0811C2CE
	.4byte _0811C2CE
	.4byte _0811C2CE
	.4byte _0811C2A6
	.4byte _0811C2AC
	.4byte _0811C2B2
	.4byte _0811C2B8
	.4byte _0811C2BE
	.4byte _0811C2C4
_0811C21C:
	bl sub_811C2D4
	b _0811C2C8
_0811C222:
	bl sub_811C30C
	b _0811C2C8
_0811C228:
	bl sub_811C3E4
	b _0811C2C8
_0811C22E:
	bl sub_811C48C
	b _0811C2C8
_0811C234:
	bl sub_811C404
	b _0811C2C8
_0811C23A:
	bl sub_811C448
	b _0811C2C8
_0811C240:
	bl sub_811C4D0
	b _0811C2C8
_0811C246:
	bl sub_811C518
	b _0811C2C8
_0811C24C:
	bl sub_811C554
	b _0811C2C8
_0811C252:
	bl sub_811C620
	b _0811C2C8
_0811C258:
	bl sub_811C830
	b _0811C2C8
_0811C25E:
	bl sub_811C8F0
	b _0811C2C8
_0811C264:
	bl sub_811C99C
	b _0811C2C8
_0811C26A:
	bl sub_811CA5C
	b _0811C2C8
_0811C270:
	bl sub_811C780
	b _0811C2C8
_0811C276:
	bl sub_811C78C
	b _0811C2C8
_0811C27C:
	bl sub_811C7D4
	b _0811C2C8
_0811C282:
	bl sub_811CB18
	b _0811C2C8
_0811C288:
	bl sub_811CB98
	b _0811C2C8
_0811C28E:
	bl sub_811CB24
	b _0811C2C8
_0811C294:
	bl sub_811CC90
	b _0811C2C8
_0811C29A:
	bl sub_811CC08
	b _0811C2C8
_0811C2A0:
	bl sub_811C6C0
	b _0811C2C8
_0811C2A6:
	bl sub_811CD14
	b _0811C2C8
_0811C2AC:
	bl sub_811CD54
	b _0811C2C8
_0811C2B2:
	bl sub_811CD94
	b _0811C2C8
_0811C2B8:
	bl sub_811CDD4
	b _0811C2C8
_0811C2BE:
	bl sub_811CE14
	b _0811C2C8
_0811C2C4:
	bl sub_811CE54
_0811C2C8:
	lsls r0, 24
	lsrs r0, 24
	b _0811C2D0
_0811C2CE:
	movs r0, 0
_0811C2D0:
	pop {r1}
	bx r1
	thumb_func_end sub_811C170

	thumb_func_start sub_811C2D4
sub_811C2D4: @ 811C2D4
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811C2EC
	cmp r0, 0x1
	beq _0811C2FA
	b _0811C304
	.pool
_0811C2EC:
	bl sub_811D2C8
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811C304
_0811C2FA:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811C306
_0811C304:
	movs r0, 0x1
_0811C306:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811C2D4

	thumb_func_start sub_811C30C
sub_811C30C: @ 811C30C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x40
	bl sub_811BA94
	adds r4, r0, 0
	bl sub_811BA68
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	bl sub_811BAB8
	lsls r0, 24
	lsrs r7, r0, 24
	bl sub_811BAC4
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	bl sub_811BAAC
	lsls r0, 24
	lsrs r0, 24
	mov r1, r9
	muls r1, r0
	adds r0, r1, 0
	lsls r0, 1
	adds r4, r0
	ldr r1, =gUnknown_08597C30
	mov r2, r10
	lsls r0, r2, 2
	adds r0, r1
	ldrb r0, [r0]
	lsls r0, 27
	lsrs r0, 8
	movs r1, 0xD0
	lsls r1, 12
	adds r0, r1
	lsrs r6, r0, 16
	movs r5, 0
	cmp r5, r7
	bcs _0811C3AA
	ldr r2, =0x0000ffff
	mov r8, r2
_0811C36C:
	ldrh r0, [r4]
	cmp r0, r8
	bne _0811C380
	movs r0, 0x48
	b _0811C392
	.pool
_0811C380:
	ldrh r1, [r4]
	mov r0, sp
	bl CopyEasyChatWord
	movs r0, 0x1
	mov r1, sp
	movs r2, 0
	bl GetStringWidth
_0811C392:
	adds r0, 0x11
	lsls r1, r6, 16
	asrs r1, 16
	adds r1, r0
	lsls r1, 16
	lsrs r6, r1, 16
	adds r4, 0x2
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, r7
	bcc _0811C36C
_0811C3AA:
	ldr r1, =gUnknown_08597C30
	mov r2, r10
	lsls r0, r2, 2
	adds r0, r1
	ldrb r1, [r0]
	lsrs r1, 5
	mov r2, r9
	lsls r0, r2, 1
	adds r1, r0
	lsls r1, 27
	lsls r0, r6, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 20
	adds r1, r2
	lsrs r1, 24
	bl sub_811DF60
	movs r0, 0
	add sp, 0x40
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811C30C

	thumb_func_start sub_811C3E4
sub_811C3E4: @ 811C3E4
	push {lr}
	bl sub_811BAB8
	lsls r0, 24
	lsrs r0, 24
	bl sub_811E920
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x60
	bl sub_811DF60
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_811C3E4

	thumb_func_start sub_811C404
sub_811C404: @ 811C404
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811C41C
	cmp r0, 0x1
	beq _0811C436
	b _0811C440
	.pool
_0811C41C:
	bl sub_811DF90
	movs r0, 0x2
	bl sub_811D104
	movs r0, 0x1
	bl sub_811D214
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811C440
_0811C436:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811C442
_0811C440:
	movs r0, 0x1
_0811C442:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811C404

	thumb_func_start sub_811C448
sub_811C448: @ 811C448
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811C460
	cmp r0, 0x1
	beq _0811C47A
	b _0811C484
	.pool
_0811C460:
	bl sub_811DF90
	movs r0, 0x3
	bl sub_811D104
	movs r0, 0
	bl sub_811D214
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811C484
_0811C47A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811C486
_0811C484:
	movs r0, 0x1
_0811C486:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811C448

	thumb_func_start sub_811C48C
sub_811C48C: @ 811C48C
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811C4A4
	cmp r0, 0x1
	beq _0811C4BE
	b _0811C4C8
	.pool
_0811C4A4:
	bl sub_811DF90
	movs r0, 0x1
	bl sub_811D104
	movs r0, 0x1
	bl sub_811D214
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811C4C8
_0811C4BE:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811C4CA
_0811C4C8:
	movs r0, 0x1
_0811C4CA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811C48C

	thumb_func_start sub_811C4D0
sub_811C4D0: @ 811C4D0
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811C4E8
	cmp r0, 0x1
	beq _0811C506
	b _0811C510
	.pool
_0811C4E8:
	bl sub_811DFB0
	movs r0, 0
	bl sub_811D104
	bl sub_811D2C8
	movs r0, 0
	bl ShowBg
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811C510
_0811C506:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811C512
_0811C510:
	movs r0, 0x1
_0811C512:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811C4D0

	thumb_func_start sub_811C518
sub_811C518: @ 811C518
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811C530
	cmp r0, 0x1
	beq _0811C546
	movs r0, 0x1
	b _0811C54E
	.pool
_0811C530:
	bl sub_811DFB0
	movs r0, 0
	bl sub_811D104
	bl sub_811D2C8
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811C546:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
_0811C54E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811C518

	thumb_func_start sub_811C554
sub_811C554: @ 811C554
	push {lr}
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _0811C60E
	lsls r0, 2
	ldr r1, =_0811C574
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811C574:
	.4byte _0811C588
	.4byte _0811C5A4
	.4byte _0811C5B6
	.4byte _0811C5CC
	.4byte _0811C5EC
_0811C588:
	bl sub_811DF90
	movs r0, 0
	bl HideBg
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl sub_811DE5C
	bl sub_811D6D4
	b _0811C5DA
_0811C5A4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811C618
	movs r0, 0
	bl sub_811D9CC
	b _0811C5DA
_0811C5B6:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811C618
	bl sub_811DAA4
	lsls r0, 24
	cmp r0, 0
	bne _0811C618
	b _0811C5DA
_0811C5CC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811C618
	bl sub_811E3AC
_0811C5DA:
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811C618
	.pool
_0811C5EC:
	bl sub_811E418
	lsls r0, 24
	cmp r0, 0
	bne _0811C618
	bl sub_811DFC8
	movs r0, 0
	bl sub_811E6E0
	bl sub_811E64C
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811C60E:
	movs r0, 0
	b _0811C61A
	.pool
_0811C618:
	movs r0, 0x1
_0811C61A:
	pop {r1}
	bx r1
	thumb_func_end sub_811C554

	thumb_func_start sub_811C620
sub_811C620: @ 811C620
	push {lr}
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _0811C6B8
	lsls r0, 2
	ldr r1, =_0811C640
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811C640:
	.4byte _0811C654
	.4byte _0811C662
	.4byte _0811C67E
	.4byte _0811C690
	.4byte _0811C6B4
_0811C654:
	bl sub_811E050
	bl sub_811E4AC
	bl sub_811E6B0
	b _0811C6A4
_0811C662:
	bl sub_811E4D0
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0811C6B8
	movs r0, 0x1
	bl sub_811D9CC
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811C67E:
	bl sub_811DAA4
	lsls r0, 24
	cmp r0, 0
	bne _0811C6B8
	b _0811C6A4
	.pool
_0811C690:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811C6B8
	bl sub_811DFB0
	movs r0, 0
	bl ShowBg
_0811C6A4:
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811C6B8
	.pool
_0811C6B4:
	movs r0, 0
	b _0811C6BA
_0811C6B8:
	movs r0, 0x1
_0811C6BA:
	pop {r1}
	bx r1
	thumb_func_end sub_811C620

	thumb_func_start sub_811C6C0
sub_811C6C0: @ 811C6C0
	push {lr}
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _0811C778
	lsls r0, 2
	ldr r1, =_0811C6E0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811C6E0:
	.4byte _0811C6F4
	.4byte _0811C708
	.4byte _0811C722
	.4byte _0811C748
	.4byte _0811C76E
_0811C6F4:
	bl sub_811E050
	bl sub_811E6B0
	bl sub_811E55C
	movs r0, 0x5
	bl sub_811D9CC
	b _0811C736
_0811C708:
	bl sub_811DAA4
	lsls r0, 24
	cmp r0, 0
	bne _0811C778
	bl sub_811E5B8
	lsls r0, 24
	cmp r0, 0
	bne _0811C778
	bl sub_811D6D4
	b _0811C736
_0811C722:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811C778
	movs r0, 0x6
	bl sub_811D9CC
	bl sub_811E578
_0811C736:
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811C778
	.pool
_0811C748:
	bl sub_811DAA4
	lsls r0, 24
	cmp r0, 0
	bne _0811C778
	bl sub_811E5B8
	lsls r0, 24
	cmp r0, 0
	bne _0811C778
	bl sub_811E64C
	bl sub_811DFC8
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811C76E:
	movs r0, 0
	b _0811C77A
	.pool
_0811C778:
	movs r0, 0x1
_0811C77A:
	pop {r1}
	bx r1
	thumb_func_end sub_811C6C0

	thumb_func_start sub_811C780
sub_811C780: @ 811C780
	push {lr}
	bl sub_811E088
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_811C780

	thumb_func_start sub_811C78C
sub_811C78C: @ 811C78C
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811C7A4
	cmp r0, 0x1
	beq _0811C7B4
	b _0811C7CA
	.pool
_0811C7A4:
	movs r0, 0x1
	movs r1, 0x4
	bl sub_811DDAC
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811C7B4:
	bl sub_811DE10
	lsls r0, 24
	cmp r0, 0
	bne _0811C7CA
	bl sub_811E088
	bl sub_811E64C
	movs r0, 0
	b _0811C7CC
_0811C7CA:
	movs r0, 0x1
_0811C7CC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811C78C

	thumb_func_start sub_811C7D4
sub_811C7D4: @ 811C7D4
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _0811C808
	cmp r0, 0x1
	bgt _0811C7F0
	cmp r0, 0
	beq _0811C7F6
	b _0811C828
	.pool
_0811C7F0:
	cmp r0, 0x2
	beq _0811C820
	b _0811C828
_0811C7F6:
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x4
	bl sub_811DDAC
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811C808:
	bl sub_811DE10
	lsls r0, 24
	cmp r0, 0
	bne _0811C828
	bl sub_811E64C
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811C820:
	movs r0, 0
	b _0811C82A
	.pool
_0811C828:
	movs r0, 0x1
_0811C82A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811C7D4

	thumb_func_start sub_811C830
sub_811C830: @ 811C830
	push {lr}
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x5
	bhi _0811C8E8
	lsls r0, 2
	ldr r1, =_0811C850
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811C850:
	.4byte _0811C868
	.4byte _0811C876
	.4byte _0811C886
	.4byte _0811C898
	.4byte _0811C8B8
	.4byte _0811C8DE
_0811C868:
	bl sub_811E050
	bl sub_811E4AC
	bl sub_811E6B0
	b _0811C8A8
_0811C876:
	bl sub_811E4D0
	lsls r0, 24
	cmp r0, 0
	bne _0811C8E8
	bl sub_811D9B4
	b _0811C8A8
_0811C886:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811C8E8
	movs r0, 0x2
	bl sub_811D9CC
	b _0811C8A8
_0811C898:
	bl sub_811DAA4
	lsls r0, 24
	cmp r0, 0
	bne _0811C8E8
	movs r0, 0x2
	bl sub_811D698
_0811C8A8:
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811C8E8
	.pool
_0811C8B8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811C8E8
	bl sub_811E288
	movs r0, 0x1
	bl sub_811E6E0
	bl sub_811E64C
	bl sub_811E794
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811C8DE:
	movs r0, 0
	b _0811C8EA
	.pool
_0811C8E8:
	movs r0, 0x1
_0811C8EA:
	pop {r1}
	bx r1
	thumb_func_end sub_811C830

	thumb_func_start sub_811C8F0
sub_811C8F0: @ 811C8F0
	push {lr}
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x5
	bhi _0811C994
	lsls r0, 2
	ldr r1, =_0811C910
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811C910:
	.4byte _0811C928
	.4byte _0811C92E
	.4byte _0811C940
	.4byte _0811C952
	.4byte _0811C974
	.4byte _0811C98C
_0811C928:
	bl sub_811D2C8
	b _0811C962
_0811C92E:
	bl sub_811E380
	bl sub_811E6B0
	bl sub_811E7F8
	bl sub_811D9B4
	b _0811C962
_0811C940:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811C994
	movs r0, 0x3
	bl sub_811D9CC
	b _0811C962
_0811C952:
	bl sub_811DAA4
	lsls r0, 24
	cmp r0, 0
	bne _0811C994
	movs r0, 0
	bl ShowBg
_0811C962:
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811C994
	.pool
_0811C974:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811C994
	bl sub_811DFB0
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811C98C:
	movs r0, 0
	b _0811C996
	.pool
_0811C994:
	movs r0, 0x1
_0811C996:
	pop {r1}
	bx r1
	thumb_func_end sub_811C8F0

	thumb_func_start sub_811C99C
sub_811C99C: @ 811C99C
	push {lr}
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x6
	bhi _0811CA54
	lsls r0, 2
	ldr r1, =_0811C9BC
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811C9BC:
	.4byte _0811C9D8
	.4byte _0811C9DE
	.4byte _0811C9F0
	.4byte _0811CA02
	.4byte _0811CA14
	.4byte _0811CA34
	.4byte _0811CA4C
_0811C9D8:
	bl sub_811D2C8
	b _0811CA24
_0811C9DE:
	bl sub_811E380
	bl sub_811E6B0
	bl sub_811E7F8
	bl sub_811D9B4
	b _0811CA24
_0811C9F0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811CA54
	movs r0, 0x3
	bl sub_811D9CC
	b _0811CA24
_0811CA02:
	bl sub_811DAA4
	lsls r0, 24
	cmp r0, 0
	bne _0811CA54
	movs r0, 0x3
	bl sub_811D104
	b _0811CA24
_0811CA14:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811CA54
	movs r0, 0
	bl ShowBg
_0811CA24:
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CA54
	.pool
_0811CA34:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811CA54
	bl sub_811DFB0
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811CA4C:
	movs r0, 0
	b _0811CA56
	.pool
_0811CA54:
	movs r0, 0x1
_0811CA56:
	pop {r1}
	bx r1
	thumb_func_end sub_811C99C

	thumb_func_start sub_811CA5C
sub_811CA5C: @ 811CA5C
	push {lr}
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _0811CB10
	lsls r0, 2
	ldr r1, =_0811CA7C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811CA7C:
	.4byte _0811CA90
	.4byte _0811CAA2
	.4byte _0811CAB4
	.4byte _0811CAC4
	.4byte _0811CAE4
_0811CA90:
	bl sub_811E380
	bl sub_811E6B0
	bl sub_811E7F8
	bl sub_811D9B4
	b _0811CAD2
_0811CAA2:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811CB10
	movs r0, 0x4
	bl sub_811D9CC
	b _0811CAD2
_0811CAB4:
	bl sub_811DAA4
	lsls r0, 24
	cmp r0, 0
	bne _0811CB10
	bl sub_811D6D4
	b _0811CAD2
_0811CAC4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811CB10
	bl sub_811E3AC
_0811CAD2:
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CB10
	.pool
_0811CAE4:
	bl sub_811E418
	lsls r0, 24
	cmp r0, 0
	bne _0811CB10
	bl sub_811DFC8
	movs r0, 0
	bl sub_811E6E0
	bl sub_811E64C
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	movs r0, 0
	b _0811CB12
	.pool
_0811CB10:
	movs r0, 0x1
_0811CB12:
	pop {r1}
	bx r1
	thumb_func_end sub_811CA5C

	thumb_func_start sub_811CB18
sub_811CB18: @ 811CB18
	push {lr}
	bl sub_811E30C
	movs r0, 0
	pop {r1}
	bx r1
	thumb_func_end sub_811CB18

	thumb_func_start sub_811CB24
sub_811CB24: @ 811CB24
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _0811CB50
	cmp r0, 0x1
	bgt _0811CB40
	cmp r0, 0
	beq _0811CB4A
	b _0811CB8E
	.pool
_0811CB40:
	cmp r0, 0x2
	beq _0811CB6C
	cmp r0, 0x3
	beq _0811CB8A
	b _0811CB8E
_0811CB4A:
	bl sub_811D7A4
	b _0811CB62
_0811CB50:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811CB8E
	movs r0, 0x1
	movs r1, 0x4
	bl sub_811DDAC
_0811CB62:
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CB8E
_0811CB6C:
	bl sub_811DE10
	lsls r0, 24
	cmp r0, 0
	bne _0811CB8E
	bl sub_811E30C
	bl sub_811E64C
	bl sub_811E794
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811CB8A:
	movs r0, 0
	b _0811CB90
_0811CB8E:
	movs r0, 0x1
_0811CB90:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811CB24

	thumb_func_start sub_811CB98
sub_811CB98: @ 811CB98
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _0811CBC4
	cmp r0, 0x1
	bgt _0811CBB4
	cmp r0, 0
	beq _0811CBBE
	b _0811CC00
	.pool
_0811CBB4:
	cmp r0, 0x2
	beq _0811CBE2
	cmp r0, 0x3
	beq _0811CBFC
	b _0811CC00
_0811CBBE:
	bl sub_811D7C8
	b _0811CBD8
_0811CBC4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811CC00
	movs r0, 0x1
	negs r0, r0
	movs r1, 0x4
	bl sub_811DDAC
_0811CBD8:
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CC00
_0811CBE2:
	bl sub_811DE10
	lsls r0, 24
	cmp r0, 0
	bne _0811CC00
	bl sub_811E64C
	bl sub_811E794
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811CBFC:
	movs r0, 0
	b _0811CC02
_0811CC00:
	movs r0, 0x1
_0811CC02:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811CB98

	thumb_func_start sub_811CC08
sub_811CC08: @ 811CC08
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203A11C
	ldr r0, [r5]
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _0811CC34
	cmp r0, 0x1
	bgt _0811CC24
	cmp r0, 0
	beq _0811CC2E
	b _0811CC86
	.pool
_0811CC24:
	cmp r0, 0x2
	beq _0811CC64
	cmp r0, 0x3
	beq _0811CC82
	b _0811CC86
_0811CC2E:
	bl sub_811D7EC
	b _0811CC5A
_0811CC34:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811CC86
	bl sub_811BBDC
	adds r4, r0, 0
	bl sub_811DE48
	lsls r4, 24
	lsrs r4, 24
	subs r4, r0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_811DDAC
_0811CC5A:
	ldr r1, [r5]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CC86
_0811CC64:
	bl sub_811DE10
	lsls r0, 24
	cmp r0, 0
	bne _0811CC86
	bl sub_811E30C
	bl sub_811E64C
	bl sub_811E794
	ldr r1, [r5]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811CC82:
	movs r0, 0
	b _0811CC88
_0811CC86:
	movs r0, 0x1
_0811CC88:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811CC08

	thumb_func_start sub_811CC90
sub_811CC90: @ 811CC90
	push {r4,r5,lr}
	ldr r5, =gUnknown_0203A11C
	ldr r0, [r5]
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _0811CCBC
	cmp r0, 0x1
	bgt _0811CCAC
	cmp r0, 0
	beq _0811CCB6
	b _0811CD0A
	.pool
_0811CCAC:
	cmp r0, 0x2
	beq _0811CCEC
	cmp r0, 0x3
	beq _0811CD06
	b _0811CD0A
_0811CCB6:
	bl sub_811D830
	b _0811CCE2
_0811CCBC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	cmp r0, 0
	bne _0811CD0A
	bl sub_811BBDC
	adds r4, r0, 0
	bl sub_811DE48
	lsls r4, 24
	lsrs r4, 24
	subs r4, r0
	lsls r4, 16
	asrs r4, 16
	adds r0, r4, 0
	movs r1, 0x8
	bl sub_811DDAC
_0811CCE2:
	ldr r1, [r5]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CD0A
_0811CCEC:
	bl sub_811DE10
	lsls r0, 24
	cmp r0, 0
	bne _0811CD0A
	bl sub_811E64C
	bl sub_811E794
	ldr r1, [r5]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
_0811CD06:
	movs r0, 0
	b _0811CD0C
_0811CD0A:
	movs r0, 0x1
_0811CD0C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811CC90

	thumb_func_start sub_811CD14
sub_811CD14: @ 811CD14
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811CD2C
	cmp r0, 0x1
	beq _0811CD40
	b _0811CD4A
	.pool
_0811CD2C:
	bl sub_811DF90
	movs r0, 0x4
	bl sub_811D104
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CD4A
_0811CD40:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811CD4C
_0811CD4A:
	movs r0, 0x1
_0811CD4C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811CD14

	thumb_func_start sub_811CD54
sub_811CD54: @ 811CD54
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811CD6C
	cmp r0, 0x1
	beq _0811CD80
	b _0811CD8A
	.pool
_0811CD6C:
	bl sub_811DF90
	movs r0, 0x5
	bl sub_811D104
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CD8A
_0811CD80:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811CD8C
_0811CD8A:
	movs r0, 0x1
_0811CD8C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811CD54

	thumb_func_start sub_811CD94
sub_811CD94: @ 811CD94
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811CDAC
	cmp r0, 0x1
	beq _0811CDC0
	b _0811CDCA
	.pool
_0811CDAC:
	bl sub_811DF90
	movs r0, 0x6
	bl sub_811D104
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CDCA
_0811CDC0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811CDCC
_0811CDCA:
	movs r0, 0x1
_0811CDCC:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811CD94

	thumb_func_start sub_811CDD4
sub_811CDD4: @ 811CDD4
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811CDEC
	cmp r0, 0x1
	beq _0811CE00
	b _0811CE0A
	.pool
_0811CDEC:
	bl sub_811DF90
	movs r0, 0x7
	bl sub_811D104
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CE0A
_0811CE00:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811CE0C
_0811CE0A:
	movs r0, 0x1
_0811CE0C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811CDD4

	thumb_func_start sub_811CE14
sub_811CE14: @ 811CE14
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811CE2C
	cmp r0, 0x1
	beq _0811CE40
	b _0811CE4A
	.pool
_0811CE2C:
	bl sub_811DF90
	movs r0, 0x8
	bl sub_811D104
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CE4A
_0811CE40:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811CE4C
_0811CE4A:
	movs r0, 0x1
_0811CE4C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811CE14

	thumb_func_start sub_811CE54
sub_811CE54: @ 811CE54
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, 0
	beq _0811CE6C
	cmp r0, 0x1
	beq _0811CE80
	b _0811CE8A
	.pool
_0811CE6C:
	bl sub_811DF90
	movs r0, 0x9
	bl sub_811D104
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, 0x1
	strh r0, [r1]
	b _0811CE8A
_0811CE80:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, 24
	lsrs r0, 24
	b _0811CE8C
_0811CE8A:
	movs r0, 0x1
_0811CE8C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811CE54

	thumb_func_start sub_811CE94
sub_811CE94: @ 811CE94
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	movs r0, 0x98
	lsls r0, 5
	bl Alloc
	adds r2, r0, 0
	str r2, [r4]
	cmp r2, 0
	beq _0811CEFC
	movs r1, 0
	strh r1, [r2]
	movs r3, 0xB6
	lsls r3, 2
	adds r0, r2, r3
	str r1, [r0]
	adds r3, 0x4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, 0x4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, 0x4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, 0x4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, 0x4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, 0x4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, 0x4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, 0x4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, 0x4
	adds r0, r2, r3
	str r1, [r0]
	bl sub_811BC70
	ldr r1, [r4]
	strb r0, [r1, 0xA]
	movs r0, 0x1
	b _0811CEFE
	.pool
_0811CEFC:
	movs r0, 0
_0811CEFE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811CE94

	thumb_func_start sub_811CF04
sub_811CF04: @ 811CF04
	push {lr}
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x3
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0x2
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgX
	movs r0, 0
	movs r1, 0
	movs r2, 0
	bl ChangeBgY
	movs r1, 0xC1
	lsls r1, 6
	movs r0, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_811CF04

	thumb_func_start sub_811CF64
sub_811CF64: @ 811CF64
	push {r4,lr}
	bl ResetPaletteFade
	ldr r0, =gEasyChatMode_Pal
	movs r1, 0
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_08597B14
	movs r1, 0x10
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_08597B34
	movs r1, 0x40
	movs r2, 0x20
	bl LoadPalette
	ldr r0, =gUnknown_08597C1C
	movs r1, 0xA0
	movs r2, 0x8
	bl LoadPalette
	ldr r4, =gUnknown_08597C24
	adds r0, r4, 0
	movs r1, 0xB0
	movs r2, 0xC
	bl LoadPalette
	adds r0, r4, 0
	movs r1, 0xF0
	movs r2, 0xC
	bl LoadPalette
	adds r0, r4, 0
	movs r1, 0x30
	movs r2, 0xC
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811CF64

	thumb_func_start sub_811CFCC
sub_811CFCC: @ 811CFCC
	push {r4,r5,lr}
	sub sp, 0x14
	bl sub_811BA88
	adds r5, r0, 0
	cmp r5, 0
	beq _0811D020
	movs r0, 0x1
	adds r1, r5, 0
	movs r2, 0x90
	bl GetStringCenterAlignXOffset
	adds r4, r0, 0
	movs r0, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r0, 0x2
	str r0, [sp, 0xC]
	movs r0, 0x3
	str r0, [sp, 0x10]
	movs r0, 0
	movs r1, 0x1
	adds r2, r5, 0
	adds r3, r4, 0
	bl sub_811D058
	movs r0, 0
	bl PutWindowTilemap
	movs r0, 0
	movs r1, 0x3
	bl CopyWindowToVram
_0811D020:
	add sp, 0x14
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_811CFCC

	thumb_func_start sub_811D028
sub_811D028: @ 811D028
	push {r4-r6,lr}
	sub sp, 0xC
	ldr r4, [sp, 0x1C]
	ldr r5, [sp, 0x20]
	ldr r6, [sp, 0x24]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	bl AddTextPrinterParameterized
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_811D028

	thumb_func_start sub_811D058
sub_811D058: @ 811D058
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	mov r9, r3
	ldr r3, [sp, 0x30]
	ldr r4, [sp, 0x34]
	mov r8, r4
	ldr r7, [sp, 0x38]
	mov r10, r7
	ldr r5, [sp, 0x3C]
	ldr r6, [sp, 0x40]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	mov r4, r9
	lsls r4, 24
	lsrs r4, 24
	mov r9, r4
	lsls r3, 24
	lsrs r3, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	add r4, sp, 0xC
	mov r7, r10
	strb r7, [r4]
	strb r5, [r4, 0x1]
	strb r6, [r4, 0x2]
	str r4, [sp]
	mov r4, r8
	lsls r4, 24
	asrs r4, 24
	str r4, [sp, 0x4]
	str r2, [sp, 0x8]
	mov r2, r9
	bl AddTextPrinterParameterized3
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_811D058

	thumb_func_start sub_811D0BC
sub_811D0BC: @ 811D0BC
	push {lr}
	sub sp, 0xC
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x14
	str r0, [sp, 0x4]
	movs r0, 0x11
	str r0, [sp, 0x8]
	movs r0, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0
	bl FillBgTilemapBufferRect
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0xE0
	bl LoadUserWindowBorderGfx
	movs r0, 0x1
	movs r1, 0x1
	movs r2, 0xE
	bl sub_8098858
	movs r0, 0
	bl sub_811D104
	movs r0, 0x1
	bl PutWindowTilemap
	movs r0, 0
	bl CopyBgTilemapBufferToVram
	add sp, 0xC
	pop {r0}
	bx r0
	thumb_func_end sub_811D0BC

	thumb_func_start sub_811D104
sub_811D104: @ 811D104
	push {lr}
	sub sp, 0x14
	lsls r0, 24
	lsrs r1, r0, 24
	movs r0, 0
	str r0, [sp, 0x10]
	str r0, [sp, 0xC]
	cmp r1, 0x9
	bhi _0811D1BC
	lsls r0, r1, 2
	ldr r1, =_0811D124
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811D124:
	.4byte _0811D14C
	.4byte _0811D16A
	.4byte _0811D156
	.4byte _0811D160
	.4byte _0811D174
	.4byte _0811D180
	.4byte _0811D18C
	.4byte _0811D19C
	.4byte _0811D1A8
	.4byte _0811D1B4
_0811D14C:
	add r1, sp, 0x10
	add r0, sp, 0xC
	bl sub_811BAD0
	b _0811D1BC
_0811D156:
	add r1, sp, 0x10
	add r0, sp, 0xC
	bl sub_811BB40
	b _0811D1BC
_0811D160:
	add r1, sp, 0x10
	add r0, sp, 0xC
	bl sub_811BB08
	b _0811D1BC
_0811D16A:
	add r1, sp, 0x10
	add r0, sp, 0xC
	bl sub_811BB88
	b _0811D1BC
_0811D174:
	ldr r0, =gText_CreateAQuiz
	str r0, [sp, 0xC]
	b _0811D1BC
	.pool
_0811D180:
	ldr r0, =gText_SelectTheAnswer
	str r0, [sp, 0xC]
	b _0811D1BC
	.pool
_0811D18C:
	ldr r0, =gText_OnlyOnePhrase
	str r0, [sp, 0xC]
	ldr r0, =gText_OriginalSongWillBeUsed
	b _0811D1BA
	.pool
_0811D19C:
	ldr r0, =gText_LyricsCantBeDeleted
	str r0, [sp, 0xC]
	b _0811D1BC
	.pool
_0811D1A8:
	ldr r0, =gText_CombineTwoWordsOrPhrases3
	str r0, [sp, 0xC]
	b _0811D1BC
	.pool
_0811D1B4:
	ldr r0, =gText_YouCannotQuitHere
	str r0, [sp, 0xC]
	ldr r0, =gText_SectionMustBeCompleted
_0811D1BA:
	str r0, [sp, 0x10]
_0811D1BC:
	movs r0, 0x1
	movs r1, 0x11
	bl FillWindowPixelBuffer
	ldr r2, [sp, 0xC]
	cmp r2, 0
	beq _0811D1E0
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0
	bl sub_811D028
_0811D1E0:
	ldr r2, [sp, 0x10]
	cmp r2, 0
	beq _0811D1FC
	movs r0, 0x11
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r0, 0x1
	movs r1, 0x1
	movs r3, 0
	bl sub_811D028
_0811D1FC:
	movs r0, 0x1
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x14
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811D104

	thumb_func_start sub_811D214
sub_811D214: @ 811D214
	push {lr}
	adds r3, r0, 0
	lsls r3, 24
	lsrs r3, 24
	ldr r0, =gUnknown_08597C84
	movs r1, 0x1
	movs r2, 0xE
	bl CreateYesNoMenu
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811D214

	thumb_func_start sub_811D230
sub_811D230: @ 811D230
	push {r4-r6,lr}
	sub sp, 0x8
	bl sub_811BA68
	lsls r0, 24
	ldr r6, =0xffffff00
	ldr r4, [sp]
	ands r4, r6
	movs r1, 0x3
	orrs r4, r1
	str r4, [sp]
	ldr r1, =gUnknown_08597C30
	lsrs r0, 22
	adds r0, r1
	ldrb r3, [r0]
	lsls r1, r3, 27
	lsrs r1, 19
	ldr r5, =0xffff00ff
	adds r2, r5, 0
	ands r2, r4
	orrs r2, r1
	lsrs r3, 5
	lsls r3, 16
	ldr r1, =0xff00ffff
	ands r2, r1
	orrs r2, r3
	str r2, [sp]
	ldrb r3, [r0, 0x1]
	lsls r3, 24
	ldr r1, =0x00ffffff
	ands r1, r2
	orrs r1, r3
	str r1, [sp]
	ldrb r1, [r0, 0x2]
	ldr r0, [sp, 0x4]
	ands r0, r6
	orrs r0, r1
	ands r0, r5
	movs r1, 0xB0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xD8
	lsls r1, 15
	orrs r0, r1
	str r0, [sp, 0x4]
	mov r0, sp
	bl AddWindow
	ldr r1, =gUnknown_0203A11C
	ldr r1, [r1]
	strh r0, [r1, 0x2]
	lsls r0, 24
	lsrs r0, 24
	bl PutWindowTilemap
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811D230

	thumb_func_start sub_811D2C8
sub_811D2C8: @ 811D2C8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	bl sub_811BA94
	adds r4, r0, 0
	bl sub_811BAAC
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x10]
	bl sub_811BAA0
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	bl sub_811BA68
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	mov r8, r0
	cmp r6, 0x7
	bne _0811D302
	movs r1, 0x1
	mov r8, r1
_0811D302:
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r7, 0
	ldr r0, [sp, 0x14]
	cmp r7, r0
	bge _0811D402
_0811D316:
	add r0, sp, 0xC
	ldr r1, =gUnknown_08597C8C
	movs r2, 0x4
	bl memcpy
	mov r1, r8
	cmp r1, 0
	beq _0811D32C
	add r1, sp, 0xC
	movs r0, 0x6
	strb r0, [r1, 0x2]
_0811D32C:
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	adds r2, r1, 0
	adds r2, 0xB
	movs r0, 0xFF
	strb r0, [r1, 0xB]
	adds r0, r2, 0
	add r1, sp, 0xC
	bl StringAppend
	adds r2, r0, 0
	movs r5, 0
	lsls r0, r7, 4
	mov r9, r0
	adds r1, r7, 0x1
	mov r10, r1
	b _0811D3CE
	.pool
_0811D358:
	ldrh r0, [r4]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _0811D374
	adds r1, r0, 0
	adds r0, r2, 0
	bl CopyEasyChatWord
	adds r2, r0, 0
	adds r4, 0x2
	b _0811D3A2
	.pool
_0811D374:
	adds r4, 0x2
	mov r0, r8
	cmp r0, 0
	bne _0811D3A8
	adds r0, r2, 0
	movs r1, 0
	movs r2, 0x4
	bl WriteColorChangeControlCode
	adds r2, r0, 0
	movs r1, 0xAE
	movs r0, 0xB
_0811D38C:
	strb r1, [r2]
	adds r2, 0x1
	subs r0, 0x1
	cmp r0, 0
	bge _0811D38C
	adds r0, r2, 0
	movs r1, 0
	movs r2, 0x2
	bl WriteColorChangeControlCode
	adds r2, r0, 0
_0811D3A2:
	mov r1, r8
	cmp r1, 0
	beq _0811D3AE
_0811D3A8:
	add r1, sp, 0xC
	movs r0, 0x3
	strb r0, [r1, 0x2]
_0811D3AE:
	adds r0, r2, 0
	add r1, sp, 0xC
	bl StringAppend
	adds r2, r0, 0
	cmp r6, 0x2
	beq _0811D3C4
	cmp r6, 0x7
	beq _0811D3C4
	cmp r6, 0x8
	bne _0811D3CC
_0811D3C4:
	cmp r5, 0
	bne _0811D3CC
	cmp r7, 0x4
	beq _0811D3D4
_0811D3CC:
	adds r5, 0x1
_0811D3CE:
	ldr r0, [sp, 0x10]
	cmp r5, r0
	blt _0811D358
_0811D3D4:
	movs r0, 0xFF
	strb r0, [r2]
	ldr r0, =gUnknown_0203A11C
	ldr r2, [r0]
	ldrb r0, [r2, 0x2]
	adds r2, 0xB
	mov r1, r9
	adds r1, 0x1
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp]
	movs r1, 0xFF
	str r1, [sp, 0x4]
	movs r1, 0
	str r1, [sp, 0x8]
	movs r1, 0x1
	movs r3, 0
	bl sub_811D028
	mov r7, r10
	ldr r1, [sp, 0x14]
	cmp r7, r1
	blt _0811D316
_0811D402:
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldrb r0, [r0, 0x2]
	movs r1, 0x3
	bl CopyWindowToVram
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811D2C8

	thumb_func_start sub_811D424
sub_811D424: @ 811D424
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	bl sub_811BA68
	lsls r0, 24
	lsrs r6, r0, 24
	movs r0, 0
	str r0, [sp]
	ldr r2, =0x01000200
	mov r0, sp
	mov r1, r8
	bl CpuFastSet
	cmp r6, 0x2
	beq _0811D450
	cmp r6, 0x8
	bne _0811D4D4
_0811D450:
	ldr r0, =gUnknown_08597C30
	lsls r2, r6, 2
	adds r2, r0
	ldrb r1, [r2]
	lsls r3, r1, 27
	lsrs r0, r3, 27
	ldrb r4, [r2, 0x1]
	adds r5, r0, r4
	lsls r1, 24
	lsrs r0, r1, 29
	ldrb r2, [r2, 0x2]
	adds r2, r0
	mov r12, r2
	adds r6, r0, 0
	cmp r6, r12
	blt _0811D472
	b _0811D5D6
_0811D472:
	mov r9, r3
_0811D474:
	mov r0, r9
	lsrs r3, r0, 27
	subs r7, r3, 0x1
	lsls r2, r6, 5
	adds r0, r2, r7
	lsls r0, 1
	add r0, r8
	ldr r4, =0x00001005
	adds r1, r4, 0
	strh r1, [r0]
	adds r7, r3, 0
	adds r3, r2, 0
	adds r4, r6, 0x1
	cmp r7, r5
	bge _0811D4AE
	movs r0, 0x80
	lsls r0, 5
	adds r2, r0, 0
	lsls r1, r7, 1
	lsls r0, r6, 6
	add r0, r8
	adds r0, r1, r0
	subs r7, r5, r7
_0811D4A2:
	strh r2, [r0]
	adds r0, 0x2
	subs r7, 0x1
	cmp r7, 0
	bne _0811D4A2
	adds r7, r5, 0
_0811D4AE:
	adds r0, r3, r7
	lsls r0, 1
	add r0, r8
	ldr r2, =0x00001007
	adds r1, r2, 0
	strh r1, [r0]
	adds r6, r4, 0
	cmp r6, r12
	blt _0811D474
	b _0811D5D6
	.pool
_0811D4D4:
	ldr r4, =gUnknown_08597C30
	mov r10, r4
	lsls r6, 2
	mov r9, r6
	mov r3, r9
	add r3, r10
	ldrb r0, [r3]
	lsls r2, r0, 24
	lsrs r1, r2, 29
	subs r6, r1, 0x1
	lsls r0, 27
	lsrs r4, r0, 27
	subs r7, r4, 0x1
	adds r0, r4, 0
	ldrb r1, [r3, 0x1]
	adds r5, r0, r1
	lsrs r2, 29
	ldrb r3, [r3, 0x2]
	adds r3, r2
	mov r12, r3
	lsls r0, r6, 5
	adds r0, r7
	lsls r0, 1
	add r0, r8
	ldr r2, =0x00001001
	adds r1, r2, 0
	strh r1, [r0]
	adds r7, r4, 0
	cmp r7, r5
	bge _0811D52A
	ldr r4, =0x00001002
	adds r2, r4, 0
	lsls r1, r7, 1
	lsls r0, r6, 6
	add r0, r8
	adds r1, r0
	subs r7, r5, r7
_0811D51E:
	strh r2, [r1]
	adds r1, 0x2
	subs r7, 0x1
	cmp r7, 0
	bne _0811D51E
	adds r7, r5, 0
_0811D52A:
	lsls r0, r6, 5
	adds r0, r7
	lsls r0, 1
	add r0, r8
	ldr r2, =0x00001003
	adds r1, r2, 0
	strh r1, [r0]
	adds r6, 0x1
	cmp r6, r12
	bge _0811D590
	ldr r0, =gUnknown_08597C30
	add r0, r9
	ldrb r0, [r0]
	lsls r3, r0, 27
_0811D546:
	lsrs r0, r3, 27
	subs r7, r0, 0x1
	lsls r1, r6, 5
	adds r1, r7
	lsls r1, 1
	add r1, r8
	ldr r4, =0x00001005
	adds r2, r4, 0
	strh r2, [r1]
	adds r7, r0, 0
	adds r4, r6, 0x1
	cmp r7, r5
	bge _0811D57C
	movs r0, 0x80
	lsls r0, 5
	adds r2, r0, 0
	lsls r1, r7, 1
	lsls r0, r6, 6
	add r0, r8
	adds r1, r0
	subs r7, r5, r7
_0811D570:
	strh r2, [r1]
	adds r1, 0x2
	subs r7, 0x1
	cmp r7, 0
	bne _0811D570
	adds r7, r5, 0
_0811D57C:
	lsls r0, r6, 5
	adds r0, r7
	lsls r0, 1
	add r0, r8
	ldr r2, =0x00001007
	adds r1, r2, 0
	strh r1, [r0]
	adds r6, r4, 0
	cmp r6, r12
	blt _0811D546
_0811D590:
	mov r0, r9
	add r0, r10
	ldrb r2, [r0]
	lsls r2, 27
	lsrs r2, 27
	subs r7, r2, 0x1
	lsls r3, r6, 5
	adds r0, r3, r7
	lsls r0, 1
	add r0, r8
	ldr r4, =0x00001009
	adds r1, r4, 0
	strh r1, [r0]
	adds r7, r2, 0
	cmp r7, r5
	bge _0811D5CA
	ldr r0, =0x0000100a
	adds r2, r0, 0
	lsls r1, r7, 1
	lsls r0, r6, 6
	add r0, r8
	adds r0, r1, r0
	subs r7, r5, r7
_0811D5BE:
	strh r2, [r0]
	adds r0, 0x2
	subs r7, 0x1
	cmp r7, 0
	bne _0811D5BE
	adds r7, r5, 0
_0811D5CA:
	adds r0, r3, r7
	lsls r0, 1
	add r0, r8
	ldr r2, =0x0000100b
	adds r1, r2, 0
	strh r1, [r0]
_0811D5D6:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811D424

	thumb_func_start sub_811D60C
sub_811D60C: @ 811D60C
	push {r4,lr}
	sub sp, 0x8
	movs r0, 0x3
	bl GetBgTilemapBuffer
	adds r4, r0, 0
	bl sub_811BA68
	lsls r0, 24
	ldr r1, =gUnknown_08597C30
	lsrs r0, 22
	adds r0, r1
	ldrb r1, [r0, 0x3]
	cmp r1, 0x2
	beq _0811D63E
	cmp r1, 0x2
	bgt _0811D638
	cmp r1, 0x1
	beq _0811D64C
	b _0811D67C
	.pool
_0811D638:
	cmp r1, 0x3
	beq _0811D668
	b _0811D67C
_0811D63E:
	movs r0, 0xA8
	lsls r0, 3
	adds r4, r0
	movs r0, 0x20
	str r0, [sp]
	str r1, [sp, 0x4]
	b _0811D65A
_0811D64C:
	movs r0, 0xC0
	lsls r0, 3
	adds r4, r0
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x2
	str r0, [sp, 0x4]
_0811D65A:
	movs r0, 0x3
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0xB
	bl CopyToBgTilemapBufferRect
	b _0811D67C
_0811D668:
	movs r0, 0x20
	str r0, [sp]
	movs r0, 0x4
	str r0, [sp, 0x4]
	movs r0, 0x3
	adds r1, r4, 0
	movs r2, 0
	movs r3, 0xA
	bl CopyToBgTilemapBufferRect
_0811D67C:
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811D60C

	thumb_func_start sub_811D684
sub_811D684: @ 811D684
	push {lr}
	movs r0, 0x2
	bl PutWindowTilemap
	movs r0, 0x2
	bl CopyBgTilemapBufferToVram
	pop {r0}
	bx r0
	thumb_func_end sub_811D684

	thumb_func_start sub_811D698
sub_811D698: @ 811D698
	push {r4,lr}
	adds r4, r0, 0
	bl sub_811DD84
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	cmp r4, 0x1
	beq _0811D6BC
	cmp r4, 0x1
	bcc _0811D6B6
	cmp r4, 0x2
	beq _0811D6C2
	b _0811D6C6
_0811D6B6:
	bl sub_811D6F4
	b _0811D6C6
_0811D6BC:
	bl sub_811D758
	b _0811D6C6
_0811D6C2:
	bl sub_811D794
_0811D6C6:
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811D698

	thumb_func_start sub_811D6D4
sub_811D6D4: @ 811D6D4
	push {lr}
	bl sub_811BBB0
	lsls r0, 24
	cmp r0, 0
	bne _0811D6E8
	movs r0, 0
	bl sub_811D698
	b _0811D6EE
_0811D6E8:
	movs r0, 0x1
	bl sub_811D698
_0811D6EE:
	pop {r0}
	bx r0
	thumb_func_end sub_811D6D4

	thumb_func_start sub_811D6F4
sub_811D6F4: @ 811D6F4
	push {r4-r7,lr}
	sub sp, 0xC
	movs r5, 0
	movs r7, 0x61
_0811D6FC:
	movs r4, 0
	lsls r0, r7, 24
	lsrs r6, r0, 24
_0811D702:
	lsls r0, r5, 24
	lsrs r0, 24
	adds r5, 0x1
	bl sub_811F3B8
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x16
	beq _0811D742
	bl sub_811F424
	adds r2, r0, 0
	movs r0, 0x54
	adds r3, r4, 0
	muls r3, r0
	adds r3, 0xA
	lsls r3, 24
	lsrs r3, 24
	str r6, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	bl sub_811D028
	adds r4, 0x1
	cmp r4, 0x1
	ble _0811D702
	adds r7, 0x10
	b _0811D6FC
_0811D742:
	bl sub_811BBBC
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0
	bl sub_811DDAC
	add sp, 0xC
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_811D6F4

	thumb_func_start sub_811D758
sub_811D758: @ 811D758
	push {r4-r6,lr}
	sub sp, 0xC
	movs r5, 0
	movs r4, 0xC2
	lsls r4, 23
	ldr r6, =gUnknown_08597C90
_0811D764:
	ldm r6!, {r2}
	lsrs r0, r4, 24
	str r0, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0
	str r0, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	movs r3, 0xA
	bl sub_811D028
	movs r0, 0x80
	lsls r0, 21
	adds r4, r0
	adds r5, 0x1
	cmp r5, 0x3
	bls _0811D764
	add sp, 0xC
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811D758

	thumb_func_start sub_811D794
sub_811D794: @ 811D794
	push {lr}
	movs r0, 0
	movs r1, 0x4
	bl sub_811D864
	pop {r0}
	bx r0
	thumb_func_end sub_811D794

	thumb_func_start sub_811D7A4
sub_811D7A4: @ 811D7A4
	push {r4,lr}
	bl sub_811BBDC
	adds r4, r0, 0
	adds r4, 0x3
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_811D950
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_811D864
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811D7A4

	thumb_func_start sub_811D7C8
sub_811D7C8: @ 811D7C8
	push {r4,lr}
	bl sub_811BBDC
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_811D950
	adds r0, r4, 0
	movs r1, 0x1
	bl sub_811D864
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811D7C8

	thumb_func_start sub_811D7EC
sub_811D7EC: @ 811D7EC
	push {r4,r5,lr}
	bl sub_811BBDC
	lsls r0, 24
	lsrs r0, 24
	adds r5, r0, 0
	adds r0, r5, 0x4
	lsls r0, 24
	lsrs r4, r0, 24
	bl sub_811BBE8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	cmp r4, r0
	bls _0811D80E
	adds r4, r0, 0
_0811D80E:
	cmp r5, r4
	bcs _0811D828
	subs r4, r5
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_811D950
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_811D864
_0811D828:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_811D7EC

	thumb_func_start sub_811D830
sub_811D830: @ 811D830
	push {r4,r5,lr}
	bl sub_811BBDC
	lsls r0, 24
	lsrs r5, r0, 24
	bl sub_811DE48
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	bcs _0811D85C
	subs r4, r0, r5
	lsls r4, 24
	lsrs r4, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_811D950
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_811D864
_0811D85C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_811D830

	thumb_func_start sub_811D864
sub_811D864: @ 811D864
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	str r1, [sp, 0x14]
	lsls r1, r0, 1
	mov r8, r1
	lsls r0, 4
	adds r1, r0, 0
	adds r1, 0x60
	movs r0, 0xFF
	ands r1, r0
	adds r1, 0x1
	movs r0, 0
	b _0811D930
_0811D88E:
	movs r6, 0
	movs r2, 0x10
	adds r2, r1
	mov r9, r2
	adds r0, 0x1
	mov r10, r0
	lsls r0, r1, 24
	lsrs r7, r0, 24
_0811D89E:
	mov r1, r8
	lsls r0, r1, 16
	lsrs r0, 16
	movs r2, 0x1
	add r8, r2
	bl sub_811F578
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _0811D926
	ldr r5, =gUnknown_0203A11C
	ldr r0, [r5]
	adds r0, 0xCC
	adds r1, r4, 0
	movs r2, 0
	bl CopyEasyChatWordPadded
	adds r0, r4, 0
	bl sub_811BF88
	adds r1, r0, 0
	cmp r1, 0
	bne _0811D8FC
	ldr r2, [r5]
	adds r2, 0xCC
	movs r0, 0xD
	adds r3, r6, 0
	muls r3, r0
	adds r3, 0x3
	lsls r3, 27
	lsrs r3, 24
	str r7, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	movs r0, 0x2
	movs r1, 0x1
	bl sub_811D028
	b _0811D926
	.pool
_0811D8FC:
	ldr r2, [r5]
	adds r2, 0xCC
	movs r0, 0xD
	adds r3, r6, 0
	muls r3, r0
	adds r3, 0x3
	lsls r3, 27
	lsrs r3, 24
	str r7, [sp]
	movs r0, 0xFF
	str r0, [sp, 0x4]
	movs r0, 0x1
	str r0, [sp, 0x8]
	movs r0, 0x5
	str r0, [sp, 0xC]
	movs r0, 0x3
	str r0, [sp, 0x10]
	movs r0, 0x2
	movs r1, 0x1
	bl sub_811D058
_0811D926:
	adds r6, 0x1
	cmp r6, 0x1
	ble _0811D89E
	mov r1, r9
	mov r0, r10
_0811D930:
	ldr r2, [sp, 0x14]
	cmp r0, r2
	blt _0811D88E
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_811D864

	thumb_func_start sub_811D950
sub_811D950: @ 811D950
	push {r4,r5,lr}
	sub sp, 0x8
	lsls r0, 24
	lsls r1, 24
	lsrs r0, 20
	adds r3, r0, 0
	adds r3, 0x60
	movs r0, 0xFF
	ands r3, r0
	lsrs r0, r1, 20
	adds r1, r3, r0
	cmp r1, 0xFF
	ble _0811D97C
	ldr r0, =0xffffff00
	adds r4, r1, r0
	movs r0, 0x80
	lsls r0, 1
	subs r0, r3
	b _0811D97E
	.pool
_0811D97C:
	movs r4, 0
_0811D97E:
	movs r5, 0xE0
	str r5, [sp]
	lsls r0, 16
	lsrs r0, 16
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x11
	movs r2, 0
	bl FillWindowPixelRect
	cmp r4, 0
	beq _0811D9AA
	str r5, [sp]
	lsls r0, r4, 16
	lsrs r0, 16
	str r0, [sp, 0x4]
	movs r0, 0x2
	movs r1, 0x11
	movs r2, 0
	movs r3, 0
	bl FillWindowPixelRect
_0811D9AA:
	add sp, 0x8
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_811D950

	thumb_func_start sub_811D9B4
sub_811D9B4: @ 811D9B4
	push {lr}
	movs r0, 0x2
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r0, 0x2
	movs r1, 0x2
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_811D9B4

	thumb_func_start sub_811D9CC
sub_811D9CC: @ 811D9CC
	push {lr}
	ldr r1, =gUnknown_0203A11C
	cmp r0, 0x6
	bhi _0811DA86
	lsls r0, 2
	ldr r1, =_0811D9E8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811D9E8:
	.4byte _0811DA04
	.4byte _0811DA18
	.4byte _0811DA28
	.4byte _0811DA3C
	.4byte _0811DA50
	.4byte _0811DA64
	.4byte _0811DA78
_0811DA04:
	ldr r1, =gUnknown_0203A11C
	ldr r2, [r1]
	movs r0, 0
	strb r0, [r2, 0x6]
	ldr r2, [r1]
	movs r0, 0xA
	b _0811DA84
	.pool
_0811DA18:
	ldr r1, =gUnknown_0203A11C
	ldr r2, [r1]
	movs r3, 0
	movs r0, 0x9
	b _0811DA44
	.pool
_0811DA28:
	ldr r1, =gUnknown_0203A11C
	ldr r2, [r1]
	movs r0, 0xB
	strb r0, [r2, 0x6]
	ldr r2, [r1]
	movs r0, 0x11
	b _0811DA84
	.pool
_0811DA3C:
	ldr r1, =gUnknown_0203A11C
	ldr r2, [r1]
	movs r3, 0
	movs r0, 0x11
_0811DA44:
	strb r0, [r2, 0x6]
	ldr r0, [r1]
	strb r3, [r0, 0x7]
	b _0811DA86
	.pool
_0811DA50:
	ldr r1, =gUnknown_0203A11C
	ldr r2, [r1]
	movs r0, 0x11
	strb r0, [r2, 0x6]
	ldr r2, [r1]
	movs r0, 0xA
	b _0811DA84
	.pool
_0811DA64:
	ldr r1, =gUnknown_0203A11C
	ldr r2, [r1]
	movs r0, 0x12
	strb r0, [r2, 0x6]
	ldr r2, [r1]
	movs r0, 0x16
	b _0811DA84
	.pool
_0811DA78:
	ldr r1, =gUnknown_0203A11C
	ldr r2, [r1]
	movs r0, 0x16
	strb r0, [r2, 0x6]
	ldr r2, [r1]
	movs r0, 0x12
_0811DA84:
	strb r0, [r2, 0x7]
_0811DA86:
	ldr r1, [r1]
	ldrb r0, [r1, 0x6]
	movs r3, 0x1
	negs r3, r3
	adds r2, r3, 0
	ldrb r3, [r1, 0x7]
	cmp r0, r3
	bcs _0811DA98
	movs r2, 0x1
_0811DA98:
	strb r2, [r1, 0x8]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811D9CC

	thumb_func_start sub_811DAA4
sub_811DAA4: @ 811DAA4
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r1, [r4]
	ldrb r2, [r1, 0x6]
	ldrb r0, [r1, 0x7]
	cmp r2, r0
	beq _0811DAD4
	ldrb r0, [r1, 0x8]
	adds r0, r2, r0
	strb r0, [r1, 0x6]
	ldr r0, [r4]
	ldrb r0, [r0, 0x6]
	bl sub_811DADC
	ldr r0, [r4]
	ldrb r1, [r0, 0x6]
	ldrb r0, [r0, 0x7]
	eors r1, r0
	negs r0, r1
	orrs r0, r1
	lsrs r0, 31
	b _0811DAD6
	.pool
_0811DAD4:
	movs r0, 0
_0811DAD6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811DAA4

	thumb_func_start sub_811DADC
sub_811DADC: @ 811DADC
	push {r4,lr}
	sub sp, 0x8
	lsls r0, 24
	lsrs r4, r0, 24
	movs r0, 0x1E
	str r0, [sp]
	movs r0, 0xA
	str r0, [sp, 0x4]
	movs r0, 0x1
	movs r1, 0
	movs r2, 0
	movs r3, 0xA
	bl FillBgTilemapBufferRect_Palette0
	cmp r4, 0x16
	bls _0811DAFE
	b _0811DC1A
_0811DAFE:
	lsls r0, r4, 2
	ldr r1, =_0811DB0C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811DB0C:
	.4byte _0811DC1A
	.4byte _0811DB68
	.4byte _0811DB70
	.4byte _0811DB78
	.4byte _0811DB80
	.4byte _0811DB88
	.4byte _0811DB90
	.4byte _0811DC00
	.4byte _0811DBF2
	.4byte _0811DBE4
	.4byte _0811DBD6
	.4byte _0811DB9E
	.4byte _0811DBA6
	.4byte _0811DBAE
	.4byte _0811DBB6
	.4byte _0811DBBE
	.4byte _0811DBC6
	.4byte _0811DBCE
	.4byte _0811DBD6
	.4byte _0811DBE4
	.4byte _0811DBF2
	.4byte _0811DC00
	.4byte _0811DC0E
_0811DB68:
	movs r0, 0xB
	movs r1, 0xE
	movs r2, 0x3
	b _0811DB96
_0811DB70:
	movs r0, 0x9
	movs r1, 0xE
	movs r2, 0x7
	b _0811DB96
_0811DB78:
	movs r0, 0x7
	movs r1, 0xE
	movs r2, 0xB
	b _0811DB96
_0811DB80:
	movs r0, 0x5
	movs r1, 0xE
	movs r2, 0xF
	b _0811DB96
_0811DB88:
	movs r0, 0x3
	movs r1, 0xE
	movs r2, 0x13
	b _0811DB96
_0811DB90:
	movs r0, 0x1
	movs r1, 0xE
	movs r2, 0x17
_0811DB96:
	movs r3, 0x2
	bl sub_811DC28
	b _0811DC1A
_0811DB9E:
	movs r0, 0x1
	movs r1, 0xA
	movs r2, 0x18
	b _0811DBDC
_0811DBA6:
	movs r0, 0x1
	movs r1, 0xA
	movs r2, 0x19
	b _0811DBDC
_0811DBAE:
	movs r0, 0x1
	movs r1, 0xA
	movs r2, 0x1A
	b _0811DBDC
_0811DBB6:
	movs r0, 0x1
	movs r1, 0xA
	movs r2, 0x1B
	b _0811DBDC
_0811DBBE:
	movs r0, 0x1
	movs r1, 0xA
	movs r2, 0x1C
	b _0811DBDC
_0811DBC6:
	movs r0, 0x1
	movs r1, 0xA
	movs r2, 0x1D
	b _0811DBDC
_0811DBCE:
	movs r0, 0
	movs r1, 0xA
	movs r2, 0x1E
	b _0811DBDC
_0811DBD6:
	movs r0, 0x1
	movs r1, 0xA
	movs r2, 0x17
_0811DBDC:
	movs r3, 0xA
	bl sub_811DC28
	b _0811DC1A
_0811DBE4:
	movs r0, 0x1
	movs r1, 0xB
	movs r2, 0x17
	movs r3, 0x8
	bl sub_811DC28
	b _0811DC1A
_0811DBF2:
	movs r0, 0x1
	movs r1, 0xC
	movs r2, 0x17
	movs r3, 0x6
	bl sub_811DC28
	b _0811DC1A
_0811DC00:
	movs r0, 0x1
	movs r1, 0xD
	movs r2, 0x17
	movs r3, 0x4
	bl sub_811DC28
	b _0811DC1A
_0811DC0E:
	movs r0, 0x1
	movs r1, 0xE
	movs r2, 0x17
	movs r3, 0x2
	bl sub_811DC28
_0811DC1A:
	movs r0, 0x1
	bl CopyBgTilemapBufferToVram
	add sp, 0x8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811DADC

	thumb_func_start sub_811DC28
sub_811DC28: @ 811DC28
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	mov r12, r0
	adds r7, r1, 0
	mov r9, r2
	mov r10, r3
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	movs r1, 0xC0
	lsls r1, 2
	adds r6, r0, r1
	mov r0, r12
	add r0, r9
	subs r5, r0, 0x1
	adds r0, r7, r3
	subs r0, 0x1
	mov r8, r0
	mov r2, r12
	adds r3, r7, 0
	lsls r0, r3, 5
	adds r0, r2
	lsls r0, 1
	adds r0, r6
	ldr r4, =0x00004001
	adds r1, r4, 0
	strh r1, [r0]
	adds r2, 0x1
	cmp r2, r5
	bge _0811DC84
	ldr r0, =0x00004002
	adds r4, r0, 0
	lsls r1, r2, 1
	lsls r0, r3, 6
	adds r0, r6
	adds r1, r0
	subs r2, r5, r2
_0811DC78:
	strh r4, [r1]
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _0811DC78
	adds r2, r5, 0
_0811DC84:
	lsls r0, r3, 5
	adds r0, r2
	lsls r0, 1
	adds r0, r6
	ldr r2, =0x00004003
	adds r1, r2, 0
	strh r1, [r0]
	adds r3, 0x1
	mov r4, r12
	adds r4, 0x1
	adds r0, r7, 0x1
	str r0, [sp, 0x4]
	mov r1, r9
	subs r1, 0x2
	str r1, [sp]
	movs r2, 0x2
	negs r2, r2
	add r10, r2
	cmp r3, r8
	bge _0811DCF4
	lsls r7, r4, 1
	mov r9, r7
_0811DCB0:
	lsls r0, r3, 5
	add r0, r12
	lsls r0, 1
	adds r0, r6
	ldr r2, =0x00004005
	adds r1, r2, 0
	strh r1, [r0]
	adds r2, r4, 0
	adds r7, r3, 0x1
	cmp r4, r5
	bge _0811DCE0
	movs r0, 0x80
	lsls r0, 7
	adds r1, r0, 0
	lsls r0, r3, 6
	adds r0, r6
	add r0, r9
	subs r2, r5, r4
_0811DCD4:
	strh r1, [r0]
	adds r0, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _0811DCD4
	adds r2, r5, 0
_0811DCE0:
	lsls r0, r3, 5
	adds r0, r2
	lsls r0, 1
	adds r0, r6
	ldr r2, =0x00004007
	adds r1, r2, 0
	strh r1, [r0]
	adds r3, r7, 0
	cmp r3, r8
	blt _0811DCB0
_0811DCF4:
	lsls r0, r3, 5
	mov r7, r12
	adds r1, r0, r7
	lsls r1, 1
	adds r1, r6
	ldr r7, =0x00004009
	adds r2, r7, 0
	strh r2, [r1]
	adds r2, r4, 0
	mov r12, r0
	cmp r4, r5
	bge _0811DD26
	ldr r0, =0x0000400a
	adds r7, r0, 0
	lsls r1, r4, 1
	lsls r0, r3, 6
	adds r0, r6
	adds r0, r1, r0
	subs r2, r5, r4
_0811DD1A:
	strh r7, [r0]
	adds r0, 0x2
	subs r2, 0x1
	cmp r2, 0
	bne _0811DD1A
	adds r2, r5, 0
_0811DD26:
	mov r1, r12
	adds r0, r1, r2
	lsls r0, 1
	adds r0, r6
	ldr r2, =0x0000400b
	adds r1, r2, 0
	strh r1, [r0]
	lsls r0, r4, 27
	lsrs r0, 24
	ldr r3, [sp, 0x4]
	lsls r1, r3, 27
	lsrs r1, 24
	ldr r4, [sp]
	lsls r2, r4, 27
	lsrs r2, 24
	mov r7, r10
	lsls r3, r7, 27
	lsrs r3, 24
	bl sub_811DE5C
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811DC28

	thumb_func_start sub_811DD84
sub_811DD84: @ 811DD84
	push {lr}
	movs r1, 0x80
	lsls r1, 4
	movs r0, 0x2
	movs r2, 0
	bl ChangeBgY
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldr r1, =0x000002ce
	adds r0, r1
	movs r1, 0
	strh r1, [r0]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811DD84

	thumb_func_start sub_811DDAC
sub_811DDAC: @ 811DDAC
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r1, 24
	lsrs r5, r1, 24
	movs r0, 0x2
	bl GetBgY
	adds r2, r0, 0
	ldr r0, =gUnknown_0203A11C
	ldr r3, [r0]
	ldr r0, =0x000002ce
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, r4
	strh r0, [r1]
	lsls r4, 20
	asrs r4, 16
	lsls r0, r4, 8
	adds r2, r0
	cmp r5, 0
	beq _0811DE00
	movs r1, 0xB4
	lsls r1, 2
	adds r0, r3, r1
	str r2, [r0]
	movs r0, 0xB5
	lsls r0, 2
	adds r1, r3, r0
	lsls r0, r5, 8
	str r0, [r1]
	cmp r4, 0
	bge _0811DE0A
	negs r0, r0
	str r0, [r1]
	b _0811DE0A
	.pool
_0811DE00:
	movs r0, 0x2
	adds r1, r2, 0
	movs r2, 0
	bl ChangeBgY
_0811DE0A:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_811DDAC

	thumb_func_start sub_811DE10
sub_811DE10: @ 811DE10
	push {lr}
	movs r0, 0x2
	bl GetBgY
	ldr r1, =gUnknown_0203A11C
	ldr r2, [r1]
	movs r3, 0xB4
	lsls r3, 2
	adds r1, r2, r3
	ldr r1, [r1]
	cmp r0, r1
	beq _0811DE40
	movs r1, 0xB5
	lsls r1, 2
	adds r0, r2, r1
	ldr r1, [r0]
	movs r0, 0x2
	movs r2, 0x1
	bl ChangeBgY
	movs r0, 0x1
	b _0811DE42
	.pool
_0811DE40:
	movs r0, 0
_0811DE42:
	pop {r1}
	bx r1
	thumb_func_end sub_811DE10

	thumb_func_start sub_811DE48
sub_811DE48: @ 811DE48
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	ldr r1, =0x000002ce
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_811DE48

	thumb_func_start sub_811DE5C
sub_811DE5C: @ 811DE5C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, r0, 8
	adds r0, r2
	orrs r4, r0
	lsls r5, r1, 8
	adds r1, r3
	orrs r5, r1
	movs r0, 0x40
	adds r1, r4, 0
	bl SetGpuReg
	movs r0, 0x44
	adds r1, r5, 0
	bl SetGpuReg
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_811DE5C

	thumb_func_start sub_811DE90
sub_811DE90: @ 811DE90
	push {r4,r5,lr}
	ldr r0, =gUnknown_08597CA0
	bl LoadSpriteSheets
	ldr r0, =gUnknown_08597CC0
	bl LoadSpritePalettes
	movs r5, 0
	ldr r4, =gUnknown_08597CE8
_0811DEA2:
	adds r0, r4, 0
	bl LoadCompressedSpriteSheet
	adds r4, 0x8
	adds r5, 0x1
	cmp r5, 0x3
	bls _0811DEA2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811DE90

	thumb_func_start sub_811DEC4
sub_811DEC4: @ 811DEC4
	push {lr}
	bl sub_811BA68
	lsls r0, 24
	ldr r1, =gUnknown_08597C30
	lsrs r0, 22
	adds r0, r1
	ldrb r2, [r0]
	lsls r1, r2, 27
	lsrs r1, 8
	lsrs r2, 5
	lsls r2, 19
	ldr r0, =gUnknown_08597D18
	movs r3, 0xD0
	lsls r3, 12
	adds r1, r3
	asrs r1, 16
	movs r3, 0x80
	lsls r3, 12
	adds r2, r3
	asrs r2, 16
	movs r3, 0x2
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203A11C
	ldr r2, [r1]
	movs r1, 0xB6
	lsls r1, 2
	adds r2, r1
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	movs r0, 0x1
	strh r0, [r1, 0x30]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811DEC4

	thumb_func_start sub_811DF28
sub_811DF28: @ 811DF28
	push {lr}
	adds r1, r0, 0
	movs r2, 0x30
	ldrsh r0, [r1, r2]
	cmp r0, 0
	beq _0811DF56
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _0811DF56
	movs r0, 0
	strh r0, [r1, 0x2E]
	ldrh r0, [r1, 0x24]
	adds r0, 0x1
	strh r0, [r1, 0x24]
	lsls r0, 16
	cmp r0, 0
	ble _0811DF56
	ldr r0, =0x0000fffa
	strh r0, [r1, 0x24]
_0811DF56:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811DF28

	thumb_func_start sub_811DF60
sub_811DF60: @ 811DF60
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gUnknown_0203A11C
	ldr r2, [r2]
	movs r3, 0xB6
	lsls r3, 2
	adds r2, r3
	ldr r3, [r2]
	movs r4, 0
	strh r0, [r3, 0x20]
	ldr r0, [r2]
	strh r1, [r0, 0x22]
	ldr r0, [r2]
	strh r4, [r0, 0x24]
	ldr r0, [r2]
	strh r4, [r0, 0x2E]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811DF60

	thumb_func_start sub_811DF90
sub_811DF90: @ 811DF90
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	movs r0, 0xB6
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	movs r2, 0
	strh r2, [r0, 0x2E]
	ldr r0, [r1]
	strh r2, [r0, 0x30]
	ldr r0, [r1]
	strh r2, [r0, 0x24]
	bx lr
	.pool
	thumb_func_end sub_811DF90

	thumb_func_start sub_811DFB0
sub_811DFB0: @ 811DFB0
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	movs r1, 0xB6
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	movs r0, 0x1
	strh r0, [r1, 0x30]
	bx lr
	.pool
	thumb_func_end sub_811DFB0

	thumb_func_start sub_811DFC8
sub_811DFC8: @ 811DFC8
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	ldr r6, =gUnknown_08597D68
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0203A11C
	ldr r2, [r5]
	movs r1, 0xB7
	lsls r1, 2
	mov r8, r1
	add r2, r8
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r4, =gSprites
	adds r1, r4
	str r1, [r2]
	movs r0, 0x20
	strh r0, [r1, 0x24]
	adds r0, r6, 0
	movs r1, 0
	movs r2, 0
	movs r3, 0x3
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	movs r1, 0xB8
	lsls r1, 2
	adds r3, r2, r1
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	str r1, [r3]
	ldr r0, =0x0000ffe0
	strh r0, [r1, 0x24]
	add r2, r8
	ldr r1, [r2]
	adds r1, 0x3F
	ldrb r0, [r1]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1]
	bl sub_811E088
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811DFC8

	thumb_func_start sub_811E050
sub_811E050: @ 811E050
	push {r4-r6,lr}
	ldr r5, =gUnknown_0203A11C
	ldr r0, [r5]
	movs r4, 0xB7
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	bl DestroySprite
	ldr r0, [r5]
	adds r4, r0, r4
	movs r6, 0
	str r6, [r4]
	movs r4, 0xB8
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	bl DestroySprite
	ldr r0, [r5]
	adds r0, r4
	str r6, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E050

	thumb_func_start sub_811E088
sub_811E088: @ 811E088
	push {r4,lr}
	sub sp, 0x4
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	movs r2, 0xB7
	lsls r2, 2
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _0811E0E4
	adds r2, 0x4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, 0
	beq _0811E0E4
	mov r4, sp
	adds r4, 0x1
	mov r0, sp
	adds r1, r4, 0
	bl sub_811BB9C
	bl sub_811BBB0
	lsls r0, 24
	cmp r0, 0
	bne _0811E0D4
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0
	ldrsb r1, [r4, r1]
	bl sub_811E0EC
	b _0811E0E4
	.pool
_0811E0D4:
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0
	ldrsb r1, [r4, r1]
	bl sub_811E1A4
_0811E0E4:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811E088

	thumb_func_start sub_811E0EC
sub_811E0EC: @ 811E0EC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r1, 24
	lsrs r7, r1, 24
	lsls r0, 24
	asrs r5, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r5, r0
	beq _0811E150
	ldr r0, =gUnknown_0203A11C
	mov r8, r0
	ldr r0, [r0]
	movs r4, 0xB7
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0
	bl StartSpriteAnim
	mov r2, r8
	ldr r1, [r2]
	adds r4, r1, r4
	ldr r2, [r4]
	movs r0, 0x54
	muls r5, r0
	adds r5, 0x3A
	strh r5, [r2, 0x20]
	ldr r0, [r4]
	lsls r4, r7, 24
	asrs r4, 20
	adds r4, 0x60
	strh r4, [r0, 0x22]
	movs r6, 0xB8
	lsls r6, 2
	adds r1, r6
	ldr r0, [r1]
	movs r1, 0
	bl StartSpriteAnim
	mov r1, r8
	ldr r0, [r1]
	adds r0, r6
	ldr r1, [r0]
	strh r5, [r1, 0x20]
	b _0811E192
	.pool
_0811E150:
	ldr r6, =gUnknown_0203A11C
	ldr r0, [r6]
	movs r4, 0xB7
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r1, [r6]
	adds r4, r1, r4
	ldr r0, [r4]
	movs r2, 0xD8
	mov r8, r2
	mov r2, r8
	strh r2, [r0, 0x20]
	ldr r0, [r4]
	lsls r4, r7, 24
	asrs r4, 20
	adds r4, 0x70
	strh r4, [r0, 0x22]
	movs r5, 0xB8
	lsls r5, 2
	adds r1, r5
	ldr r0, [r1]
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r0, [r6]
	adds r0, r5
	ldr r1, [r0]
	mov r2, r8
	strh r2, [r1, 0x20]
_0811E192:
	ldr r0, [r0]
	strh r4, [r0, 0x22]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E0EC

	thumb_func_start sub_811E1A4
sub_811E1A4: @ 811E1A4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsls r1, 24
	lsrs r5, r1, 24
	lsrs r4, r0, 24
	asrs r2, r0, 24
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _0811E234
	lsls r0, r5, 24
	asrs r1, r0, 24
	lsls r0, r1, 4
	adds r0, 0x60
	mov r8, r0
	movs r7, 0x20
	cmp r2, 0x6
	bne _0811E1D6
	cmp r1, 0
	bne _0811E1D6
	movs r7, 0x9E
	movs r6, 0x2
	b _0811E1EC
_0811E1D6:
	ldr r3, =gUnknown_08597D08
	lsls r1, r4, 24
	lsrs r0, r1, 24
	movs r2, 0
	cmp r0, 0x6
	bhi _0811E1E4
	asrs r2, r1, 24
_0811E1E4:
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r7, r0
	movs r6, 0x3
_0811E1EC:
	ldr r5, =gUnknown_0203A11C
	ldr r0, [r5]
	movs r4, 0xB7
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	adds r1, r6, 0
	bl StartSpriteAnim
	ldr r1, [r5]
	adds r4, r1, r4
	ldr r0, [r4]
	strh r7, [r0, 0x20]
	ldr r0, [r4]
	mov r2, r8
	strh r2, [r0, 0x22]
	movs r4, 0xB8
	lsls r4, 2
	adds r1, r4
	ldr r0, [r1]
	adds r1, r6, 0
	bl StartSpriteAnim
	ldr r0, [r5]
	adds r0, r4
	ldr r1, [r0]
	strh r7, [r1, 0x20]
	ldr r0, [r0]
	mov r1, r8
	strh r1, [r0, 0x22]
	b _0811E27A
	.pool
_0811E234:
	ldr r6, =gUnknown_0203A11C
	ldr r0, [r6]
	movs r4, 0xB7
	lsls r4, 2
	adds r0, r4
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r1, [r6]
	adds r4, r1, r4
	ldr r0, [r4]
	movs r2, 0xD8
	mov r8, r2
	mov r2, r8
	strh r2, [r0, 0x20]
	ldr r0, [r4]
	lsls r4, r5, 24
	asrs r4, 20
	adds r4, 0x70
	strh r4, [r0, 0x22]
	movs r5, 0xB8
	lsls r5, 2
	adds r1, r5
	ldr r0, [r1]
	movs r1, 0x1
	bl StartSpriteAnim
	ldr r0, [r6]
	adds r0, r5
	ldr r1, [r0]
	mov r2, r8
	strh r2, [r1, 0x20]
	ldr r0, [r0]
	strh r4, [r0, 0x22]
_0811E27A:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E1A4

	thumb_func_start sub_811E288
sub_811E288: @ 811E288
	push {lr}
	ldr r0, =gUnknown_08597D18
	movs r1, 0
	movs r2, 0
	movs r3, 0x4
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gUnknown_0203A11C
	ldr r2, [r1]
	movs r1, 0xB9
	lsls r1, 2
	adds r2, r1
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r0, =gSprites
	adds r1, r0
	str r1, [r2]
	ldr r0, =sub_811E2DC
	str r0, [r1, 0x1C]
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1, 0x5]
	bl sub_811E30C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E288

	thumb_func_start sub_811E2DC
sub_811E2DC: @ 811E2DC
	push {lr}
	adds r1, r0, 0
	ldrh r0, [r1, 0x2E]
	adds r0, 0x1
	strh r0, [r1, 0x2E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x2
	ble _0811E302
	movs r0, 0
	strh r0, [r1, 0x2E]
	ldrh r0, [r1, 0x24]
	adds r0, 0x1
	strh r0, [r1, 0x24]
	lsls r0, 16
	cmp r0, 0
	ble _0811E302
	ldr r0, =0x0000fffa
	strh r0, [r1, 0x24]
_0811E302:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E2DC

	thumb_func_start sub_811E30C
sub_811E30C: @ 811E30C
	push {r4,lr}
	sub sp, 0x4
	mov r4, sp
	adds r4, 0x1
	mov r0, sp
	adds r1, r4, 0
	bl sub_811BBC8
	mov r0, sp
	movs r1, 0
	ldrsb r1, [r0, r1]
	movs r0, 0xD
	muls r0, r1
	lsls r0, 27
	movs r1, 0
	ldrsb r1, [r4, r1]
	lsls r1, 28
	movs r2, 0xE0
	lsls r2, 21
	adds r0, r2
	lsrs r0, 24
	movs r2, 0xC0
	lsls r2, 23
	adds r1, r2
	lsrs r1, 24
	bl sub_811E34C
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_811E30C

	thumb_func_start sub_811E34C
sub_811E34C: @ 811E34C
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	movs r1, 0xB9
	lsls r1, 2
	adds r2, r0, r1
	ldr r0, [r2]
	cmp r0, 0
	beq _0811E376
	movs r1, 0
	strh r3, [r0, 0x20]
	ldr r0, [r2]
	strh r4, [r0, 0x22]
	ldr r0, [r2]
	strh r1, [r0, 0x24]
	ldr r0, [r2]
	strh r1, [r0, 0x2E]
_0811E376:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E34C

	thumb_func_start sub_811E380
sub_811E380: @ 811E380
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r0, [r4]
	movs r1, 0xB9
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	cmp r0, 0
	beq _0811E3A2
	bl DestroySprite
	ldr r0, [r4]
	movs r1, 0xB9
	lsls r1, 2
	adds r0, r1
	movs r1, 0
	str r1, [r0]
_0811E3A2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E380

	thumb_func_start sub_811E3AC
sub_811E3AC: @ 811E3AC
	push {r4-r6,lr}
	ldr r0, =gUnknown_08597DF0
	movs r1, 0xD0
	movs r2, 0x80
	movs r3, 0x6
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r5, =gUnknown_0203A11C
	ldr r2, [r5]
	movs r1, 0xBA
	lsls r1, 2
	adds r2, r1
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	ldr r4, =gSprites
	adds r1, r4
	str r1, [r2]
	movs r6, 0
	ldr r0, =0x0000ffc0
	strh r0, [r1, 0x24]
	ldr r0, =gUnknown_08597DD0
	movs r1, 0xD0
	movs r2, 0x50
	movs r3, 0x5
	bl CreateSprite
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [r5]
	movs r1, 0xBB
	lsls r1, 2
	adds r3, r2, r1
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r4
	str r1, [r3]
	strb r6, [r2, 0x9]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E3AC

	thumb_func_start sub_811E418
sub_811E418: @ 811E418
	push {r4,lr}
	ldr r4, =gUnknown_0203A11C
	ldr r2, [r4]
	ldrb r3, [r2, 0x9]
	cmp r3, 0
	beq _0811E430
	cmp r3, 0x1
	beq _0811E488
	movs r0, 0
	b _0811E4A6
	.pool
_0811E430:
	movs r0, 0xBA
	lsls r0, 2
	adds r2, r0
	ldr r1, [r2]
	ldrh r0, [r1, 0x24]
	adds r0, 0x8
	strh r0, [r1, 0x24]
	ldr r2, [r2]
	movs r1, 0x24
	ldrsh r0, [r2, r1]
	cmp r0, 0
	blt _0811E4A4
	strh r3, [r2, 0x24]
	bl sub_811BBB0
	lsls r0, 24
	cmp r0, 0
	bne _0811E466
	ldr r0, [r4]
	movs r1, 0xBB
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
	b _0811E476
_0811E466:
	ldr r0, [r4]
	movs r1, 0xBB
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
_0811E476:
	ldr r0, =gUnknown_0203A11C
	ldr r1, [r0]
	ldrb r0, [r1, 0x9]
	adds r0, 0x1
	strb r0, [r1, 0x9]
	b _0811E4A4
	.pool
_0811E488:
	movs r1, 0xBB
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0811E4A4
	movs r0, 0x2
	strb r0, [r2, 0x9]
	movs r0, 0
	b _0811E4A6
_0811E4A4:
	movs r0, 0x1
_0811E4A6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811E418

	thumb_func_start sub_811E4AC
sub_811E4AC: @ 811E4AC
	push {lr}
	ldr r2, =gUnknown_0203A11C
	ldr r1, [r2]
	movs r0, 0
	strb r0, [r1, 0x9]
	ldr r0, [r2]
	movs r1, 0xBB
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x3
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E4AC

	thumb_func_start sub_811E4D0
sub_811E4D0: @ 811E4D0
	push {r4-r6,lr}
	ldr r5, =gUnknown_0203A11C
	ldr r3, [r5]
	ldrb r0, [r3, 0x9]
	cmp r0, 0
	beq _0811E4E8
	cmp r0, 0x1
	beq _0811E502
	movs r0, 0
	b _0811E554
	.pool
_0811E4E8:
	movs r1, 0xBB
	lsls r1, 2
	adds r0, r3, r1
	ldr r0, [r0]
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _0811E552
	movs r0, 0x1
	strb r0, [r3, 0x9]
	b _0811E552
_0811E502:
	movs r0, 0xBA
	lsls r0, 2
	adds r2, r3, r0
	ldr r1, [r2]
	ldrh r0, [r1, 0x24]
	subs r0, 0x8
	movs r6, 0
	strh r0, [r1, 0x24]
	ldr r0, [r2]
	movs r2, 0x24
	ldrsh r1, [r0, r2]
	movs r0, 0x40
	negs r0, r0
	cmp r1, r0
	bgt _0811E552
	movs r4, 0xBB
	lsls r4, 2
	adds r0, r3, r4
	ldr r0, [r0]
	bl DestroySprite
	ldr r0, [r5]
	movs r1, 0xBA
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	bl DestroySprite
	ldr r1, [r5]
	adds r4, r1, r4
	str r6, [r4]
	movs r2, 0xBA
	lsls r2, 2
	adds r0, r1, r2
	str r6, [r0]
	ldrb r0, [r1, 0x9]
	adds r0, 0x1
	strb r0, [r1, 0x9]
	movs r0, 0
	b _0811E554
_0811E552:
	movs r0, 0x1
_0811E554:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end sub_811E4D0

	thumb_func_start sub_811E55C
sub_811E55C: @ 811E55C
	push {lr}
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	movs r1, 0xBB
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x4
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E55C

	thumb_func_start sub_811E578
sub_811E578: @ 811E578
	push {lr}
	bl sub_811BBB0
	lsls r0, 24
	cmp r0, 0
	bne _0811E59C
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	movs r1, 0xBB
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x1
	bl StartSpriteAnim
	b _0811E5AE
	.pool
_0811E59C:
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	movs r1, 0xBB
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	movs r1, 0x2
	bl StartSpriteAnim
_0811E5AE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E578

	thumb_func_start sub_811E5B8
sub_811E5B8: @ 811E5B8
	ldr r0, =gUnknown_0203A11C
	ldr r0, [r0]
	movs r1, 0xBB
	lsls r1, 2
	adds r0, r1
	ldr r0, [r0]
	adds r0, 0x3F
	ldrb r1, [r0]
	lsrs r1, 4
	movs r0, 0x1
	bics r0, r1
	bx lr
	.pool
	thumb_func_end sub_811E5B8

	thumb_func_start sub_811E5D4
sub_811E5D4: @ 811E5D4
	push {r4,lr}
	ldr r4, =gUnknown_08597E48
	adds r0, r4, 0
	movs r1, 0x60
	movs r2, 0x50
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0811E602
	ldr r0, =gUnknown_0203A11C
	ldr r2, [r0]
	movs r0, 0xBC
	lsls r0, 2
	adds r2, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
_0811E602:
	adds r0, r4, 0
	movs r1, 0x60
	movs r2, 0x9C
	movs r3, 0
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0811E636
	ldr r0, =gUnknown_0203A11C
	ldr r2, [r0]
	movs r0, 0xBD
	lsls r0, 2
	adds r2, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r2, 0x2
	orrs r1, r2
	strb r1, [r0]
_0811E636:
	bl sub_811E6B0
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E5D4

	thumb_func_start sub_811E64C
sub_811E64C: @ 811E64C
	push {r4-r6,lr}
	bl sub_811BBF8
	ldr r6, =gUnknown_0203A11C
	ldr r1, [r6]
	movs r2, 0xBC
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0
	cmp r0, 0
	bne _0811E666
	movs r2, 0x1
_0811E666:
	adds r3, r1, 0
	adds r3, 0x3E
	movs r4, 0x1
	lsls r2, 2
	ldrb r1, [r3]
	movs r5, 0x5
	negs r5, r5
	adds r0, r5, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	bl sub_811BC2C
	ldr r1, [r6]
	movs r2, 0xBD
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0
	cmp r0, 0
	bne _0811E692
	movs r2, 0x1
_0811E692:
	adds r3, r1, 0
	adds r3, 0x3E
	adds r1, r4, 0
	ands r1, r2
	lsls r1, 2
	ldrb r2, [r3]
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E64C

	thumb_func_start sub_811E6B0
sub_811E6B0: @ 811E6B0
	ldr r3, =gUnknown_0203A11C
	ldr r0, [r3]
	movs r1, 0xBC
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	movs r1, 0xBD
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_811E6B0

	thumb_func_start sub_811E6E0
sub_811E6E0: @ 811E6E0
	push {lr}
	cmp r0, 0
	bne _0811E6FC
	ldr r0, =gUnknown_0203A11C
	ldr r2, [r0]
	movs r1, 0xBC
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, 0x60
	b _0811E70A
	.pool
_0811E6FC:
	ldr r0, =gUnknown_0203A11C
	ldr r2, [r0]
	movs r1, 0xBC
	lsls r1, 2
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, 0x78
_0811E70A:
	strh r1, [r0, 0x20]
	movs r3, 0xBD
	lsls r3, 2
	adds r0, r2, r3
	ldr r0, [r0]
	strh r1, [r0, 0x20]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E6E0

	thumb_func_start sub_811E720
sub_811E720: @ 811E720
	push {r4,lr}
	ldr r4, =gUnknown_08597E30
	adds r0, r4, 0
	movs r1, 0xDC
	movs r2, 0x54
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0811E74E
	ldr r0, =gUnknown_0203A11C
	ldr r2, [r0]
	movs r0, 0xBE
	lsls r0, 2
	adds r2, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
_0811E74E:
	adds r0, r4, 0
	movs r1, 0xDC
	movs r2, 0x9C
	movs r3, 0x1
	bl CreateSprite
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x40
	beq _0811E77E
	ldr r0, =gUnknown_0203A11C
	ldr r2, [r0]
	movs r0, 0xBF
	lsls r0, 2
	adds r2, r0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	str r0, [r2]
	movs r1, 0x1
	bl StartSpriteAnim
_0811E77E:
	bl sub_811E7F8
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E720

	thumb_func_start sub_811E794
sub_811E794: @ 811E794
	push {r4-r6,lr}
	bl sub_811BBF8
	ldr r6, =gUnknown_0203A11C
	ldr r1, [r6]
	movs r2, 0xBE
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0
	cmp r0, 0
	bne _0811E7AE
	movs r2, 0x1
_0811E7AE:
	adds r3, r1, 0
	adds r3, 0x3E
	movs r4, 0x1
	lsls r2, 2
	ldrb r1, [r3]
	movs r5, 0x5
	negs r5, r5
	adds r0, r5, 0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	bl sub_811BC2C
	ldr r1, [r6]
	movs r2, 0xBF
	lsls r2, 2
	adds r1, r2
	ldr r1, [r1]
	movs r2, 0
	cmp r0, 0
	bne _0811E7DA
	movs r2, 0x1
_0811E7DA:
	adds r3, r1, 0
	adds r3, 0x3E
	adds r1, r4, 0
	ands r1, r2
	lsls r1, 2
	ldrb r2, [r3]
	adds r0, r5, 0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E794

	thumb_func_start sub_811E7F8
sub_811E7F8: @ 811E7F8
	ldr r3, =gUnknown_0203A11C
	ldr r0, [r3]
	movs r1, 0xBE
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r0, [r1]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	movs r1, 0xBF
	lsls r1, 2
	adds r0, r1
	ldr r1, [r0]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_811E7F8

	thumb_func_start sub_811E828
sub_811E828: @ 811E828
	push {r4,r5,lr}
	sub sp, 0x4
	bl sub_811BCBC
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _0811E84C
	cmp r0, 0x1
	bgt _0811E842
	cmp r0, 0
	beq _0811E848
	b _0811E8D0
_0811E842:
	cmp r0, 0x2
	beq _0811E850
	b _0811E8D0
_0811E848:
	movs r4, 0x43
	b _0811E852
_0811E84C:
	movs r4, 0x44
	b _0811E852
_0811E850:
	movs r4, 0x7
_0811E852:
	bl sub_811BA68
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x4
	bne _0811E8D0
	adds r0, r4, 0
	ldr r5, =SpriteCallbackDummy
	movs r4, 0
	str r4, [sp]
	adds r1, r5, 0
	movs r2, 0x4C
	movs r3, 0x28
	bl AddPseudoEventObject
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _0811E892
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0x2
	bl StartSpriteAnim
_0811E892:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x8]
	movs r1, 0x69
	cmp r0, 0
	bne _0811E8A0
	movs r1, 0x64
_0811E8A0:
	str r4, [sp]
	adds r0, r1, 0
	adds r1, r5, 0
	movs r2, 0x34
	movs r3, 0x28
	bl AddPseudoEventObject
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x40
	beq _0811E8D0
	ldr r1, =gSprites
	lsls r0, r2, 4
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r2, [r0, 0x5]
	movs r1, 0xD
	negs r1, r1
	ands r1, r2
	strb r1, [r0, 0x5]
	movs r1, 0x3
	bl StartSpriteAnim
_0811E8D0:
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E828

	thumb_func_start sub_811E8E4
sub_811E8E4: @ 811E8E4
	push {lr}
	bl sub_811BA68
	lsls r0, 24
	ldr r1, =gUnknown_08597C30
	lsrs r0, 22
	adds r0, r1
	ldrb r0, [r0, 0x3]
	cmp r0, 0x1
	beq _0811E90E
	cmp r0, 0x1
	bgt _0811E908
	cmp r0, 0
	beq _0811E916
	b _0811E91A
	.pool
_0811E908:
	cmp r0, 0x2
	beq _0811E912
	b _0811E91A
_0811E90E:
	movs r0, 0x1
	b _0811E91C
_0811E912:
	movs r0, 0x2
	b _0811E91C
_0811E916:
	movs r0, 0
	b _0811E91C
_0811E91A:
	movs r0, 0x3
_0811E91C:
	pop {r1}
	bx r1
	thumb_func_end sub_811E8E4

	thumb_func_start sub_811E920
sub_811E920: @ 811E920
	push {r4,lr}
	adds r4, r0, 0
	bl sub_811E8E4
	adds r1, r0, 0
	cmp r1, 0x2
	ble _0811E932
	movs r0, 0
	b _0811E93E
_0811E932:
	ldr r0, =gUnknown_08597E60
	lsls r1, 2
	adds r1, r4, r1
	adds r1, r0
	ldrb r0, [r1]
	adds r0, 0x4
_0811E93E:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811E920

	thumb_func_start sub_811E948
sub_811E948: @ 811E948
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	bl sub_811E8E4
	mov r8, r0
	cmp r0, 0x3
	beq _0811E9FA
	ldr r3, =0xffffff00
	ldr r0, [sp, 0xC]
	ands r0, r3
	movs r1, 0x3
	orrs r0, r1
	ldr r2, =0xffff00ff
	ands r0, r2
	adds r1, 0xFD
	orrs r0, r1
	ldr r1, =0xff00ffff
	ands r0, r1
	movs r1, 0xB0
	lsls r1, 12
	orrs r0, r1
	ldr r1, =0x00ffffff
	ands r0, r1
	movs r1, 0xE0
	lsls r1, 21
	orrs r0, r1
	str r0, [sp, 0xC]
	ldr r0, [sp, 0x10]
	ands r0, r3
	movs r1, 0x2
	orrs r0, r1
	ands r0, r2
	movs r1, 0xB0
	lsls r1, 4
	orrs r0, r1
	ldr r1, =0x0000ffff
	ands r0, r1
	movs r1, 0xD0
	lsls r1, 14
	orrs r0, r1
	str r0, [sp, 0x10]
	add r0, sp, 0xC
	bl AddWindow
	lsls r0, 16
	lsrs r7, r0, 16
	lsls r4, r7, 24
	lsrs r0, r4, 24
	movs r1, 0x11
	bl FillWindowPixelBuffer
	movs r6, 0
	mov r0, r8
	lsls r1, r0, 4
	ldr r0, =gUnknown_08597E6C
	adds r5, r1, r0
	ldr r1, =gUnknown_08597E60
	mov r10, r1
	mov r9, r4
_0811E9C6:
	ldr r2, [r5]
	lsls r4, r7, 24
	cmp r2, 0
	beq _0811E9EC
	mov r1, r8
	lsls r0, r1, 2
	adds r0, r6, r0
	add r0, r10
	ldrb r3, [r0]
	movs r0, 0x1
	str r0, [sp]
	movs r0, 0
	str r0, [sp, 0x4]
	str r0, [sp, 0x8]
	mov r1, r9
	lsrs r0, r1, 24
	movs r1, 0x1
	bl sub_811D028
_0811E9EC:
	adds r5, 0x4
	adds r6, 0x1
	cmp r6, 0x3
	ble _0811E9C6
	lsrs r0, r4, 24
	bl PutWindowTilemap
_0811E9FA:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811E948

	thumb_func_start sub_811EA28
sub_811EA28: @ 811EA28
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r1, r0, 0
	cmp r0, 0x14
	beq _0811EA4E
	cmp r0, 0x14
	bgt _0811EA48
	cmp r0, 0x11
	blt _0811EA66
	ldr r0, =0x00000864 @ = FLAG_SYS_GAME_CLEAR
	bl FlagGet
	b _0811EA60
	.pool
_0811EA48:
	cmp r1, 0x15
	beq _0811EA5C
	b _0811EA66
_0811EA4E:
	ldr r0, =0x00000866
	bl FlagGet
	b _0811EA60
	.pool
_0811EA5C:
	bl sub_811F0F8
_0811EA60:
	lsls r0, 24
	lsrs r0, 24
	b _0811EA68
_0811EA66:
	movs r0, 0x1
_0811EA68:
	pop {r1}
	bx r1
	thumb_func_end sub_811EA28

	thumb_func_start EasyChat_GetNumWordsInGroup
EasyChat_GetNumWordsInGroup: @ 811EA6C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	cmp r0, 0
	bne _0811EA84
	movs r0, 0
	bl GetNationalPokedexCount
	lsls r0, 16
	lsrs r0, 16
	b _0811EA9A
_0811EA84:
	bl sub_811EA28
	lsls r0, 24
	cmp r0, 0
	bne _0811EA92
	movs r0, 0
	b _0811EA9A
_0811EA92:
	ldr r0, =gEasyChatGroups
	lsls r1, r4, 3
	adds r1, r0
	ldrh r0, [r1, 0x6]
_0811EA9A:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end EasyChat_GetNumWordsInGroup

	thumb_func_start sub_811EAA4
sub_811EAA4: @ 811EAA4
	push {r4,r5,lr}
	lsls r2, r0, 16
	lsrs r1, r2, 16
	ldr r0, =0x0000ffff
	cmp r1, r0
	beq _0811EB04
	lsrs r3, r2, 25
	ldr r5, =0x000001ff
	ands r5, r1
	cmp r3, 0x15
	bhi _0811EB08
	ldr r0, =gEasyChatGroups
	lsls r2, r3, 3
	adds r1, r2, r0
	ldrh r4, [r1, 0x4]
	cmp r3, 0x13
	bgt _0811EADC
	cmp r3, 0x12
	bge _0811EAE0
	cmp r3, 0
	beq _0811EAE0
	b _0811EB00
	.pool
_0811EADC:
	cmp r3, 0x15
	bne _0811EB00
_0811EAE0:
	adds r0, r2, r0
	ldr r2, [r0]
	movs r1, 0
	cmp r1, r4
	bcs _0811EB08
_0811EAEA:
	lsls r0, r1, 1
	adds r0, r2
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811EB04
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r4
	bcc _0811EAEA
	b _0811EB08
_0811EB00:
	cmp r5, r4
	bcs _0811EB08
_0811EB04:
	movs r0, 0
	b _0811EB0A
_0811EB08:
	movs r0, 0x1
_0811EB0A:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811EAA4

	thumb_func_start ECWord_CheckIfOutsideOfValidRange
ECWord_CheckIfOutsideOfValidRange: @ 811EB10
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 25
	lsls r0, 7
	lsrs r3, r0, 23
	cmp r2, 0x15
	bhi _0811EB5C
	cmp r2, 0x13
	bgt _0811EB2C
	cmp r2, 0x12
	bge _0811EB3C
	cmp r2, 0
	beq _0811EB30
	b _0811EB48
_0811EB2C:
	cmp r2, 0x15
	bne _0811EB48
_0811EB30:
	ldr r0, =gUnknown_085F5490
	ldrh r0, [r0]
	b _0811EB50
	.pool
_0811EB3C:
	ldr r0, =gUnknown_085FA1D4
	ldrh r0, [r0]
	b _0811EB50
	.pool
_0811EB48:
	ldr r1, =gEasyChatGroups
	lsls r0, r2, 3
	adds r0, r1
	ldrh r0, [r0, 0x4]
_0811EB50:
	cmp r0, r3
	bls _0811EB5C
	movs r0, 0
	b _0811EB5E
	.pool
_0811EB5C:
	movs r0, 0x1
_0811EB5E:
	pop {r1}
	bx r1
	thumb_func_end ECWord_CheckIfOutsideOfValidRange

	thumb_func_start GetEasyChatWord
@ char *GetEasyChatWord(u8 groupId, u16 wordId)
GetEasyChatWord: @ 811EB64
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r2, r1, 16
	cmp r0, 0x13
	bgt _0811EB7C
	cmp r0, 0x12
	bge _0811EB90
	cmp r0, 0
	beq _0811EB80
	b _0811EBA0
_0811EB7C:
	cmp r0, 0x15
	bne _0811EBA0
_0811EB80:
	movs r0, 0xB
	muls r0, r2
	ldr r1, =gSpeciesNames
	adds r0, r1
	b _0811EBB2
	.pool
_0811EB90:
	movs r0, 0xD
	muls r0, r2
	ldr r1, =gMoveNames
	adds r0, r1
	b _0811EBB2
	.pool
_0811EBA0:
	ldr r1, =gEasyChatGroups
	lsls r0, 3
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r2, 1
	adds r0, r2
	lsls r0, 2
	adds r0, r1
	ldr r0, [r0]
_0811EBB2:
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetEasyChatWord

	thumb_func_start CopyEasyChatWord
@ char *CopyEasyChatWord(char *dest, u16 groupIdWordIdPair)
CopyEasyChatWord: @ 811EBBC
	push {r4-r6,lr}
	adds r5, r0, 0
	lsls r6, r1, 16
	lsrs r0, r6, 16
	adds r4, r0, 0
	bl sub_811EAA4
	lsls r0, 24
	cmp r0, 0
	beq _0811EBD8
	ldr r1, =gText_ThreeQuestionMarks
	b _0811EBEA
	.pool
_0811EBD8:
	ldr r0, =0x0000ffff
	cmp r4, r0
	beq _0811EBFC
	ldr r1, =0x000001ff
	ands r1, r4
	lsrs r0, r6, 25
	bl GetEasyChatWord
	adds r1, r0, 0
_0811EBEA:
	adds r0, r5, 0
	bl StringCopy
	b _0811EC02
	.pool
_0811EBFC:
	movs r0, 0xFF
	strb r0, [r5]
	adds r0, r5, 0
_0811EC02:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end CopyEasyChatWord

	thumb_func_start ConvertEasyChatWordsToString
ConvertEasyChatWordsToString: @ 811EC08
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 16
	lsls r3, 16
	lsrs r3, 16
	mov r9, r3
	ldr r0, =0xffff0000
	adds r2, r0
	lsrs r7, r2, 16
	movs r0, 0
	cmp r0, r9
	bcs _0811EC78
_0811EC2A:
	movs r6, 0
	adds r0, 0x1
	mov r8, r0
	cmp r6, r7
	bcs _0811EC5C
	ldr r2, =0x0000ffff
_0811EC36:
	ldrh r1, [r5]
	adds r0, r4, 0
	str r2, [sp]
	bl CopyEasyChatWord
	adds r4, r0, 0
	ldrh r0, [r5]
	ldr r2, [sp]
	cmp r0, r2
	beq _0811EC50
	movs r0, 0
	strb r0, [r4]
	adds r4, 0x1
_0811EC50:
	adds r5, 0x2
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, r7
	bcc _0811EC36
_0811EC5C:
	ldrh r1, [r5]
	adds r5, 0x2
	adds r0, r4, 0
	bl CopyEasyChatWord
	adds r4, r0, 0
	movs r0, 0xFE
	strb r0, [r4]
	adds r4, 0x1
	mov r1, r8
	lsls r0, r1, 16
	lsrs r0, 16
	cmp r0, r9
	bcc _0811EC2A
_0811EC78:
	subs r4, 0x1
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end ConvertEasyChatWordsToString

	thumb_func_start sub_811EC98
sub_811EC98: @ 811EC98
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	adds r4, r0, 0
	adds r5, r1, 0
	lsls r2, 16
	lsrs r2, 16
	mov r8, r2
	lsls r3, 16
	lsrs r3, 16
	str r3, [sp]
	mov r7, r8
	movs r0, 0
	str r0, [sp, 0x4]
	subs r0, r7, 0x1
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	movs r0, 0
	cmp r0, r3
	bcs _0811ED62
_0811ECC8:
	adds r3, r5, 0
	movs r2, 0
	movs r1, 0
	adds r0, 0x1
	mov r10, r0
	cmp r2, r7
	bcs _0811ECEE
	ldr r6, =0x0000ffff
_0811ECD8:
	lsls r0, r1, 1
	adds r0, r3
	ldrh r0, [r0]
	cmp r0, r6
	beq _0811ECE4
	movs r2, 0x1
_0811ECE4:
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r1, r7
	bcc _0811ECD8
_0811ECEE:
	cmp r2, 0
	bne _0811ECFC
	lsls r0, r7, 1
	adds r5, r0
	b _0811ED56
	.pool
_0811ECFC:
	movs r6, 0
	ldr r1, [sp, 0x4]
	adds r1, 0x1
	mov r9, r1
	cmp r6, r8
	bcs _0811ED30
	ldr r2, =0x0000ffff
_0811ED0A:
	ldrh r1, [r5]
	adds r0, r4, 0
	str r2, [sp, 0x8]
	bl CopyEasyChatWord
	adds r4, r0, 0
	ldrh r0, [r5]
	ldr r2, [sp, 0x8]
	cmp r0, r2
	beq _0811ED24
	movs r0, 0
	strb r0, [r4]
	adds r4, 0x1
_0811ED24:
	adds r5, 0x2
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, r8
	bcc _0811ED0A
_0811ED30:
	ldrh r1, [r5]
	adds r5, 0x2
	adds r0, r4, 0
	bl CopyEasyChatWord
	adds r4, r0, 0
	ldr r0, [sp, 0x4]
	cmp r0, 0
	bne _0811ED4C
	movs r0, 0xFE
	b _0811ED4E
	.pool
_0811ED4C:
	movs r0, 0xFA
_0811ED4E:
	strb r0, [r4]
	adds r4, 0x1
	mov r1, r9
	str r1, [sp, 0x4]
_0811ED56:
	mov r1, r10
	lsls r0, r1, 16
	lsrs r0, 16
	ldr r1, [sp]
	cmp r0, r1
	bcc _0811ECC8
_0811ED62:
	subs r4, 0x1
	movs r0, 0xFF
	strb r0, [r4]
	adds r0, r4, 0
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_811EC98

	thumb_func_start sub_811ED7C
sub_811ED7C: @ 811ED7C
	push {r4,r5,lr}
	lsls r5, r0, 16
	lsrs r0, r5, 16
	adds r4, r0, 0
	ldr r0, =0x0000ffff
	cmp r4, r0
	bne _0811ED94
	movs r0, 0
	b _0811EDBA
	.pool
_0811ED94:
	adds r0, r4, 0
	bl sub_811EAA4
	lsls r0, 24
	cmp r0, 0
	bne _0811EDB0
	ldr r1, =0x000001ff
	ands r1, r4
	lsrs r0, r5, 25
	bl GetEasyChatWord
	b _0811EDB2
	.pool
_0811EDB0:
	ldr r0, =gText_ThreeQuestionMarks
_0811EDB2:
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
_0811EDBA:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811ED7C

	thumb_func_start sub_811EDC4
sub_811EDC4: @ 811EDC4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	adds r6, r0, 0
	lsls r1, 24
	lsrs r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	lsls r3, 16
	lsrs r3, 16
	mov r10, r3
	movs r7, 0
	cmp r7, r8
	bcs _0811EE26
	subs r0, r1, 0x1
	lsls r0, 16
	mov r9, r0
_0811EDEE:
	mov r0, r9
	lsrs r4, r0, 16
	movs r5, 0
	cmp r5, r1
	bcs _0811EE14
_0811EDF8:
	ldrh r0, [r6]
	adds r6, 0x2
	str r1, [sp]
	bl sub_811ED7C
	adds r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, [sp]
	cmp r5, r1
	bcc _0811EDF8
_0811EE14:
	cmp r4, r10
	bls _0811EE1C
	movs r0, 0x1
	b _0811EE28
_0811EE1C:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, r8
	bcc _0811EDEE
_0811EE26:
	movs r0, 0
_0811EE28:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_811EDC4

	thumb_func_start sub_811EE38
sub_811EE38: @ 811EE38
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	bl Random
	ldr r2, =gEasyChatGroups
	lsls r1, r4, 3
	adds r1, r2
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r1, 0x4]
	bl __umodsi3
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r4, 0
	beq _0811EE66
	cmp r4, 0x15
	beq _0811EE66
	cmp r4, 0x12
	beq _0811EE66
	cmp r4, 0x13
	bne _0811EE74
_0811EE66:
	ldr r1, =gEasyChatGroups
	lsls r0, r4, 3
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r2, 1
	adds r0, r1
	ldrh r2, [r0]
_0811EE74:
	movs r0, 0x7F
	ands r0, r4
	lsls r0, 9
	ldr r1, =0x000001ff
	ands r2, r1
	orrs r0, r2
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811EE38

	thumb_func_start sub_811EE90
sub_811EE90: @ 811EE90
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	adds r4, r0, 0
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_811EA28
	lsls r0, 24
	cmp r0, 0
	bne _0811EEB0
	ldr r0, =0x0000ffff
	b _0811EEC4
	.pool
_0811EEB0:
	cmp r4, 0
	beq _0811EEBC
	adds r0, r4, 0
	bl sub_811EE38
	b _0811EEC0
_0811EEBC:
	bl sub_811F108
_0811EEC0:
	lsls r0, 16
	lsrs r0, 16
_0811EEC4:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811EE90

	thumb_func_start sub_811EECC
sub_811EECC: @ 811EECC
	push {r4,r5,lr}
	ldr r0, =gSpecialVar_0x8004
	ldrh r0, [r0]
	cmp r0, 0x1
	beq _0811EF04
	cmp r0, 0x1
	bgt _0811EEE4
	cmp r0, 0
	beq _0811EEEE
	b _0811EF58
	.pool
_0811EEE4:
	cmp r0, 0x2
	beq _0811EF2C
	cmp r0, 0x3
	beq _0811EF3C
	b _0811EF58
_0811EEEE:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002bb0
	adds r5, r0, r1
	movs r2, 0x2
	b _0811EF46
	.pool
_0811EF04:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002bbc
	adds r5, r0, r1
	adds r0, r5, 0
	movs r1, 0x3
	movs r2, 0x2
	movs r3, 0x12
	bl sub_811EDC4
	lsls r0, 24
	cmp r0, 0
	beq _0811EF44
	movs r2, 0x2
	movs r3, 0x3
	b _0811EF48
	.pool
_0811EF2C:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002bc8
	b _0811EF42
	.pool
_0811EF3C:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r1, =0x00002bd4
_0811EF42:
	adds r5, r0, r1
_0811EF44:
	movs r2, 0x3
_0811EF46:
	movs r3, 0x2
_0811EF48:
	ldr r4, =gStringVar4
	adds r0, r4, 0
	adds r1, r5, 0
	bl ConvertEasyChatWordsToString
	adds r0, r4, 0
	bl ShowFieldAutoScrollMessage
_0811EF58:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811EECC

	thumb_func_start sub_811EF6C
sub_811EF6C: @ 811EF6C
	push {lr}
	bl Random
	movs r1, 0x1
	ands r1, r0
	movs r0, 0xC
	cmp r1, 0
	beq _0811EF7E
	movs r0, 0xD
_0811EF7E:
	bl sub_811EE90
	adds r1, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r0, =gStringVar2
	bl CopyEasyChatWord
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811EF6C

	thumb_func_start sub_811EF98
sub_811EF98: @ 811EF98
	lsls r0, 24
	lsrs r2, r0, 27
	movs r1, 0xE0
	lsls r1, 19
	ands r1, r0
	lsrs r1, 24
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldr r3, =0x00002e20
	adds r0, r3
	adds r0, r2
	ldrb r0, [r0]
	asrs r0, r1
	movs r1, 0x1
	ands r0, r1
	bx lr
	.pool
	thumb_func_end sub_811EF98

	thumb_func_start sub_811EFC0
sub_811EFC0: @ 811EFC0
	push {lr}
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x20
	bhi _0811EFE4
	lsrs r3, r0, 27
	movs r2, 0x7
	ands r2, r1
	ldr r0, =gSaveBlock1Ptr
	ldr r1, [r0]
	ldr r0, =0x00002e20
	adds r1, r0
	adds r1, r3
	movs r0, 0x1
	lsls r0, r2
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
_0811EFE4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811EFC0

	thumb_func_start sub_811EFF0
sub_811EFF0: @ 811EFF0
	push {r4,r5,lr}
	movs r4, 0
	movs r5, 0
_0811EFF6:
	adds r0, r4, 0
	bl sub_811EF98
	lsls r0, 24
	cmp r0, 0
	beq _0811F008
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_0811F008:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x20
	bls _0811EFF6
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811EFF0

	thumb_func_start sub_811F01C
sub_811F01C: @ 811F01C
	push {r4-r6,lr}
	bl sub_811EFF0
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x21
	bne _0811F048
	b _0811F082
_0811F02C:
	adds r0, r5, 0
	bl sub_811EFC0
	ldr r0, =0x000001ff
	ands r4, r0
	movs r1, 0xA0
	lsls r1, 6
	adds r0, r1, 0
	orrs r4, r0
	adds r0, r4, 0
	b _0811F084
	.pool
_0811F048:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x21
	subs r1, r4
	bl __modsi3
	lsls r0, 16
	lsrs r6, r0, 16
	movs r4, 0
_0811F05E:
	lsls r0, r4, 24
	lsrs r5, r0, 24
	adds r0, r5, 0
	bl sub_811EF98
	lsls r0, 24
	cmp r0, 0
	bne _0811F078
	cmp r6, 0
	beq _0811F02C
	subs r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
_0811F078:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x20
	bls _0811F05E
_0811F082:
	ldr r0, =0x0000ffff
_0811F084:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F01C

	thumb_func_start sub_811F090
sub_811F090: @ 811F090
	push {r4,r5,lr}
	bl sub_811EFF0
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0
	bne _0811F0B4
	b _0811F0EA
_0811F0A0:
	ldr r0, =0x000001ff
	ands r4, r0
	movs r1, 0xA0
	lsls r1, 6
	adds r0, r1, 0
	orrs r4, r0
	adds r0, r4, 0
	b _0811F0EC
	.pool
_0811F0B4:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r5, r0, 16
	movs r4, 0
_0811F0C8:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_811EF98
	lsls r0, 24
	cmp r0, 0
	beq _0811F0E0
	cmp r5, 0
	beq _0811F0A0
	subs r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_0811F0E0:
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x20
	bls _0811F0C8
_0811F0EA:
	ldr r0, =0x0000ffff
_0811F0EC:
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F090

	thumb_func_start sub_811F0F8
sub_811F0F8: @ 811F0F8
	push {lr}
	bl IsNationalPokedexEnabled
	lsls r0, 24
	lsrs r0, 24
	pop {r1}
	bx r1
	thumb_func_end sub_811F0F8

	thumb_func_start sub_811F108
sub_811F108: @ 811F108
	push {r4-r7,lr}
	movs r0, 0
	bl EasyChat_GetNumWordsInGroup
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0
	bne _0811F128
	b _0811F172
_0811F11A:
	ldrh r1, [r5]
	ldr r0, =0x000001ff
	ands r0, r1
	b _0811F174
	.pool
_0811F128:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __umodsi3
	lsls r0, 16
	lsrs r4, r0, 16
	ldr r0, =gEasyChatGroups
	ldr r5, [r0]
	ldrh r7, [r0, 0x4]
	movs r6, 0
	cmp r6, r7
	bcs _0811F172
_0811F146:
	ldrh r0, [r5]
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetSetPokedexFlag
	lsls r0, 24
	cmp r0, 0
	beq _0811F166
	cmp r4, 0
	beq _0811F11A
	subs r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
_0811F166:
	adds r5, 0x2
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	cmp r6, r7
	bcc _0811F146
_0811F172:
	ldr r0, =0x0000ffff
_0811F174:
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F108

	thumb_func_start InitEasyChatPhrases
InitEasyChatPhrases: @ 811F184
	push {r4-r7,lr}
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x00002bb0
	ldr r3, =gUnknown_0859E62C
_0811F18E:
	ldr r1, [r5]
	lsls r0, r2, 1
	adds r1, r4
	adds r1, r0
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x3
	bls _0811F18E
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x00002bbc
	ldr r3, =gUnknown_0859E634
_0811F1AE:
	ldr r1, [r5]
	lsls r0, r2, 1
	adds r1, r4
	adds r1, r0
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x5
	bls _0811F1AE
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x00002bc8
	ldr r3, =gUnknown_0859E640
_0811F1CE:
	ldr r1, [r5]
	lsls r0, r2, 1
	adds r1, r4
	adds r1, r0
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x5
	bls _0811F1CE
	movs r2, 0
	ldr r5, =gSaveBlock1Ptr
	ldr r4, =0x00002bd4
	ldr r3, =gUnknown_0859E64C
_0811F1EE:
	ldr r1, [r5]
	lsls r0, r2, 1
	adds r1, r4
	adds r1, r0
	adds r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x5
	bls _0811F1EE
	movs r2, 0
	ldr r7, =gSaveBlock1Ptr
	ldr r6, =0x00002be0
	ldr r0, =0x0000ffff
	adds r5, r0, 0
_0811F210:
	movs r3, 0
	lsls r0, r2, 3
	adds r0, r2
	lsls r4, r0, 2
_0811F218:
	ldr r1, [r7]
	lsls r0, r3, 1
	adds r0, r4
	adds r1, r6
	adds r1, r0
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	adds r0, r3, 0x1
	lsls r0, 16
	lsrs r3, r0, 16
	cmp r3, 0x8
	bls _0811F218
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0xF
	bls _0811F210
	movs r2, 0
	ldr r4, =gSaveBlock1Ptr
	ldr r3, =0x00002e20
	movs r1, 0
_0811F244:
	ldr r0, [r4]
	adds r0, r3
	adds r0, r2
	strb r1, [r0]
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r2, 0x3F
	bls _0811F244
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitEasyChatPhrases

	thumb_func_start sub_811F28C
sub_811F28C: @ 811F28C
	push {r4,lr}
	ldr r4, =gUnknown_0203A120
	ldr r0, =0x00003ba4
	bl Alloc
	str r0, [r4]
	cmp r0, 0
	beq _0811F2B0
	bl sub_811F2D4
	bl sub_811F46C
	movs r0, 0x1
	b _0811F2B2
	.pool
_0811F2B0:
	movs r0, 0
_0811F2B2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811F28C

	thumb_func_start sub_811F2B8
sub_811F2B8: @ 811F2B8
	push {r4,lr}
	ldr r4, =gUnknown_0203A120
	ldr r0, [r4]
	cmp r0, 0
	beq _0811F2CA
	bl Free
	movs r0, 0
	str r0, [r4]
_0811F2CA:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811F2B8

	thumb_func_start sub_811F2D4
sub_811F2D4: @ 811F2D4
	push {r4,r5,lr}
	ldr r4, =gUnknown_0203A120
	ldr r0, [r4]
	movs r5, 0
	strh r5, [r0]
	movs r0, 0
	bl GetNationalPokedexCount
	lsls r0, 16
	cmp r0, 0
	beq _0811F2FC
	ldr r0, [r4]
	ldrh r1, [r0]
	adds r2, r1, 0x1
	strh r2, [r0]
	lsls r1, 16
	lsrs r1, 15
	adds r0, 0x2
	adds r0, r1
	strh r5, [r0]
_0811F2FC:
	movs r3, 0x1
_0811F2FE:
	ldr r0, [r4]
	ldrh r2, [r0]
	adds r1, r2, 0x1
	strh r1, [r0]
	lsls r2, 16
	lsrs r2, 15
	adds r0, 0x2
	adds r0, r2
	strh r3, [r0]
	adds r3, 0x1
	cmp r3, 0x10
	ble _0811F2FE
	ldr r0, =0x00000864 @ = FLAG_SYS_GAME_CLEAR
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0811F358
	ldr r0, =gUnknown_0203A120
	ldr r2, [r0]
	ldrh r0, [r2]
	adds r1, r0, 0x1
	strh r1, [r2]
	lsls r0, 16
	lsrs r0, 15
	adds r3, r2, 0x2
	adds r0, r3, r0
	movs r1, 0x11
	strh r1, [r0]
	ldrh r0, [r2]
	adds r1, r0, 0x1
	strh r1, [r2]
	lsls r0, 16
	lsrs r0, 15
	adds r0, r3, r0
	movs r1, 0x12
	strh r1, [r0]
	ldrh r0, [r2]
	adds r1, r0, 0x1
	strh r1, [r2]
	lsls r0, 16
	lsrs r0, 15
	adds r3, r0
	movs r0, 0x13
	strh r0, [r3]
_0811F358:
	ldr r0, =0x00000866
	bl FlagGet
	lsls r0, 24
	cmp r0, 0
	beq _0811F37A
	ldr r0, =gUnknown_0203A120
	ldr r0, [r0]
	ldrh r1, [r0]
	adds r2, r1, 0x1
	strh r2, [r0]
	lsls r1, 16
	lsrs r1, 15
	adds r0, 0x2
	adds r0, r1
	movs r1, 0x14
	strh r1, [r0]
_0811F37A:
	bl IsNationalPokedexEnabled
	cmp r0, 0
	beq _0811F398
	ldr r0, =gUnknown_0203A120
	ldr r0, [r0]
	ldrh r1, [r0]
	adds r2, r1, 0x1
	strh r2, [r0]
	lsls r1, 16
	lsrs r1, 15
	adds r0, 0x2
	adds r0, r1
	movs r1, 0x15
	strh r1, [r0]
_0811F398:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811F2D4

	thumb_func_start sub_811F3AC
sub_811F3AC: @ 811F3AC
	ldr r0, =gUnknown_0203A120
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_811F3AC

	thumb_func_start sub_811F3B8
sub_811F3B8: @ 811F3B8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0203A120
	ldr r1, [r0]
	ldrh r0, [r1]
	cmp r2, r0
	bcs _0811F3D8
	lsls r0, r2, 1
	adds r1, 0x2
	adds r1, r0
	ldrb r0, [r1]
	b _0811F3DA
	.pool
_0811F3D8:
	movs r0, 0x16
_0811F3DA:
	pop {r1}
	bx r1
	thumb_func_end sub_811F3B8

	thumb_func_start sub_811F3E0
sub_811F3E0: @ 811F3E0
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 24
	lsls r2, 16
	lsrs r5, r2, 16
	ldr r0, =gEasyChatGroupNamePointers
	lsrs r1, 22
	adds r1, r0
	ldr r1, [r1]
	adds r0, r4, 0
	bl StringCopy
	adds r1, r0, 0
	subs r4, r1, r4
	lsls r4, 16
	lsrs r0, r4, 16
	cmp r0, r5
	bcs _0811F414
	movs r2, 0
_0811F406:
	strb r2, [r1]
	adds r1, 0x1
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r5
	bcc _0811F406
_0811F414:
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F3E0

	thumb_func_start sub_811F424
sub_811F424: @ 811F424
	lsls r0, 24
	ldr r1, =gEasyChatGroupNamePointers
	lsrs r0, 22
	adds r0, r1
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_811F424

	thumb_func_start CopyEasyChatWordPadded
@ char *CopyEasyChatWordPadded(char *dest, u16 groupIdWordIdPair, u16 minLength)
CopyEasyChatWordPadded: @ 811F434
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 16
	lsrs r5, r2, 16
	bl CopyEasyChatWord
	adds r1, r0, 0
	subs r4, r1, r4
	lsls r4, 16
	lsrs r0, r4, 16
	cmp r0, r5
	bcs _0811F460
	movs r2, 0
_0811F452:
	strb r2, [r1]
	adds r1, 0x1
	adds r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r5
	bcc _0811F452
_0811F460:
	movs r0, 0xFF
	strb r0, [r1]
	adds r0, r1, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CopyEasyChatWordPadded

	thumb_func_start sub_811F46C
sub_811F46C: @ 811F46C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	movs r3, 0
_0811F47A:
	ldr r2, =gEasyChatWordsByLetterPointers
	lsls r1, r3, 3
	adds r0, r2, 0x4
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp]
	adds r1, r2
	ldr r7, [r1]
	ldr r0, =gUnknown_0203A120
	ldr r1, [r0]
	lsls r2, r3, 1
	adds r1, 0x2E
	adds r1, r2
	movs r0, 0
	strh r0, [r1]
	mov r10, r0
	movs r1, 0
	str r2, [sp, 0x4]
	adds r0, r3, 0x1
	str r0, [sp, 0x8]
	ldr r2, [sp]
	cmp r1, r2
	bge _0811F530
_0811F4A8:
	ldrh r0, [r7]
	ldr r2, =0x0000ffff
	cmp r0, r2
	bne _0811F4FC
	adds r7, 0x2
	ldrh r4, [r7]
	adds r7, 0x2
	adds r0, r1, 0x1
	adds r1, r0, r4
	b _0811F4FE
	.pool
_0811F4C8:
	ldr r0, =gUnknown_0203A120
	ldr r2, [r0]
	mov r0, r10
	lsls r1, r0, 1
	lsls r0, r3, 4
	adds r0, r3
	lsls r0, 3
	subs r0, r3
	lsls r0, 2
	adds r1, r0
	adds r0, r2, 0
	adds r0, 0x64
	adds r0, r1
	ldrh r1, [r5]
	strh r1, [r0]
	movs r0, 0x1
	add r10, r0
	adds r2, 0x2E
	ldr r0, [sp, 0x4]
	adds r2, r0
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	b _0811F526
	.pool
_0811F4FC:
	movs r4, 0x1
_0811F4FE:
	movs r6, 0
	adds r1, 0x1
	mov r9, r1
	lsls r2, r4, 1
	mov r8, r2
	cmp r6, r4
	bge _0811F526
	adds r5, r7, 0
_0811F50E:
	ldrh r0, [r5]
	str r3, [sp, 0xC]
	bl sub_811F860
	lsls r0, 24
	ldr r3, [sp, 0xC]
	cmp r0, 0
	bne _0811F4C8
	adds r5, 0x2
	adds r6, 0x1
	cmp r6, r4
	blt _0811F50E
_0811F526:
	add r7, r8
	mov r1, r9
	ldr r0, [sp]
	cmp r1, r0
	blt _0811F4A8
_0811F530:
	ldr r3, [sp, 0x8]
	cmp r3, 0x1A
	ble _0811F47A
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_811F46C

	thumb_func_start sub_811F548
sub_811F548: @ 811F548
	push {lr}
	lsls r1, 16
	lsrs r1, 16
	cmp r0, 0
	bne _0811F55A
	adds r0, r1, 0
	bl sub_811F5C4
	b _0811F560
_0811F55A:
	adds r0, r1, 0
	bl sub_811F6B8
_0811F560:
	ldr r1, =gUnknown_0203A120
	ldr r1, [r1]
	ldr r2, =0x00003ba0
	adds r1, r2
	strh r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811F548

	thumb_func_start sub_811F578
sub_811F578: @ 811F578
	push {lr}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gUnknown_0203A120
	ldr r1, [r0]
	ldr r3, =0x00003ba0
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r2, r0
	bcs _0811F5A4
	lsls r0, r2, 1
	ldr r2, =0x00003984
	adds r1, r2
	adds r1, r0
	ldrh r0, [r1]
	b _0811F5A6
	.pool
_0811F5A4:
	ldr r0, =0x0000ffff
_0811F5A6:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F578

	thumb_func_start sub_811F5B0
sub_811F5B0: @ 811F5B0
	ldr r0, =gUnknown_0203A120
	ldr r0, [r0]
	ldr r1, =0x00003ba0
	adds r0, r1
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_811F5B0

	thumb_func_start sub_811F5C4
sub_811F5C4: @ 811F5C4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r1, =gEasyChatGroups
	lsls r0, r2, 3
	adds r0, r1
	ldrh r3, [r0, 0x4]
	mov r8, r3
	cmp r2, 0
	beq _0811F5EC
	cmp r2, 0x15
	beq _0811F5EC
	cmp r2, 0x12
	beq _0811F5EC
	cmp r2, 0x13
	bne _0811F64C
_0811F5EC:
	lsls r0, r2, 3
	adds r0, r1
	ldr r1, [r0]
	movs r7, 0
	movs r5, 0
	cmp r5, r8
	bcs _0811F698
	movs r0, 0x7F
	ands r0, r2
	lsls r0, 9
	mov r9, r0
	adds r4, r1, 0
	lsls r6, r2, 24
_0811F606:
	ldrh r0, [r4]
	lsrs r1, r6, 24
	bl sub_811F764
	lsls r0, 24
	cmp r0, 0
	beq _0811F630
	ldr r0, =gUnknown_0203A120
	ldr r2, [r0]
	lsls r0, r5, 1
	ldr r1, =0x00003984
	adds r2, r1
	adds r2, r0
	ldrh r0, [r4]
	ldr r3, =0x000001ff
	adds r1, r3, 0
	ands r0, r1
	mov r1, r9
	orrs r0, r1
	strh r0, [r2]
	adds r5, 0x1
_0811F630:
	adds r4, 0x2
	adds r7, 0x1
	cmp r7, r8
	bcc _0811F606
	b _0811F698
	.pool
_0811F64C:
	ldr r1, [r0]
	movs r7, 0
	movs r5, 0
	cmp r5, r8
	bcs _0811F698
	movs r0, 0x7F
	ands r0, r2
	lsls r0, 9
	mov r10, r0
	adds r6, r1, 0
	lsls r2, 24
	mov r9, r2
_0811F664:
	ldrh r4, [r6, 0x4]
	adds r0, r4, 0
	mov r2, r9
	lsrs r1, r2, 24
	bl sub_811F764
	lsls r0, 24
	cmp r0, 0
	beq _0811F690
	ldr r0, =gUnknown_0203A120
	ldr r1, [r0]
	lsls r0, r5, 1
	ldr r3, =0x00003984
	adds r1, r3
	adds r1, r0
	ldr r2, =0x000001ff
	adds r0, r2, 0
	ands r4, r0
	mov r3, r10
	orrs r4, r3
	strh r4, [r1]
	adds r5, 0x1
_0811F690:
	adds r6, 0xC
	adds r7, 0x1
	cmp r7, r8
	bcc _0811F664
_0811F698:
	lsls r0, r5, 16
	lsrs r0, 16
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F5C4

	thumb_func_start sub_811F6B8
sub_811F6B8: @ 811F6B8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 16
	lsrs r1, r0, 16
	movs r4, 0
	movs r6, 0
	ldr r3, =gUnknown_0203A120
	ldr r0, [r3]
	lsls r5, r1, 1
	adds r0, 0x2E
	adds r0, r5
	ldrh r0, [r0]
	cmp r6, r0
	bcs _0811F718
	mov r8, r3
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 3
	subs r0, r1
	lsls r7, r0, 2
	ldr r0, =0x00003984
	mov r12, r0
_0811F6E6:
	mov r0, r8
	ldr r3, [r0]
	adds r1, r6, 0
	adds r0, r1, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	lsls r1, 1
	mov r0, r12
	adds r2, r3, r0
	adds r2, r1
	lsls r1, r4, 1
	adds r1, r7
	adds r0, r3, 0
	adds r0, 0x64
	adds r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	adds r3, 0x2E
	adds r3, r5
	ldrh r3, [r3]
	cmp r4, r3
	bcc _0811F6E6
_0811F718:
	adds r0, r6, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F6B8

	thumb_func_start sub_811F72C
sub_811F72C: @ 811F72C
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	movs r2, 0
	ldr r0, =gUnknown_0203A120
	ldr r0, [r0]
	ldrh r1, [r0]
	cmp r2, r1
	bge _0811F75C
	adds r4, r3, 0
	adds r3, r1, 0
	adds r1, r0, 0x2
_0811F744:
	ldrh r0, [r1]
	cmp r0, r4
	bne _0811F754
	movs r0, 0x1
	b _0811F75E
	.pool
_0811F754:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, r3
	blt _0811F744
_0811F75C:
	movs r0, 0
_0811F75E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_811F72C

	thumb_func_start sub_811F764
sub_811F764: @ 811F764
	push {r4,lr}
	lsls r0, 16
	lsrs r4, r0, 16
	lsls r1, 24
	lsrs r2, r1, 24
	cmp r2, 0x15
	bhi _0811F81A
	lsls r0, r2, 2
	ldr r1, =_0811F780
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0811F780:
	.4byte _0811F7D8
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F81A
	.4byte _0811F808
	.4byte _0811F808
	.4byte _0811F80C
	.4byte _0811F7EE
_0811F7D8:
	adds r0, r4, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetSetPokedexFlag
	lsls r0, 24
	lsrs r0, 24
	b _0811F82C
_0811F7EE:
	adds r0, r4, 0
	bl sub_811F838
	cmp r0, 0
	beq _0811F808
	adds r0, r4, 0
	bl SpeciesToNationalPokedexNum
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0
	bl GetSetPokedexFlag
_0811F808:
	movs r0, 0x1
	b _0811F82C
_0811F80C:
	lsls r0, r4, 24
	lsrs r0, 24
	bl sub_811EF98
	lsls r0, 24
	lsrs r0, 24
	b _0811F82C
_0811F81A:
	ldr r1, =gEasyChatGroups
	lsls r0, r2, 3
	adds r0, r1
	ldr r1, [r0]
	lsls r0, r4, 1
	adds r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x8]
_0811F82C:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_811F764

	thumb_func_start sub_811F838
sub_811F838: @ 811F838
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	movs r2, 0
	ldr r1, =gUnknown_0859E658
_0811F842:
	ldrh r0, [r1]
	cmp r0, r3
	bne _0811F850
	movs r0, 0x1
	b _0811F85A
	.pool
_0811F850:
	adds r1, 0x2
	adds r2, 0x1
	cmp r2, 0
	beq _0811F842
	movs r0, 0
_0811F85A:
	pop {r1}
	bx r1
	thumb_func_end sub_811F838

	thumb_func_start sub_811F860
sub_811F860: @ 811F860
	push {r4,r5,lr}
	lsls r0, 16
	lsrs r5, r0, 25
	lsls r0, 7
	lsrs r4, r0, 23
	adds r0, r5, 0
	bl sub_811F72C
	lsls r0, 24
	cmp r0, 0
	beq _0811F884
	adds r0, r4, 0
	adds r1, r5, 0
	bl sub_811F764
	lsls r0, 24
	lsrs r0, 24
	b _0811F886
_0811F884:
	movs r0, 0
_0811F886:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811F860

	thumb_func_start InitializeEasyChatWordArray
InitializeEasyChatWordArray: @ 811F88C
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	ldr r0, =0xffff0000
	adds r1, r0
	lsrs r0, r1, 16
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _0811F8AE
	adds r3, r1, 0
_0811F8A0:
	strh r3, [r2]
	adds r2, 0x2
	subs r0, 0x1
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r1
	bne _0811F8A0
_0811F8AE:
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitializeEasyChatWordArray

	thumb_func_start sub_811F8BC
sub_811F8BC: @ 811F8BC
	push {lr}
	bl sub_801B058
	ldr r1, =0x0000ffff
	adds r2, r1, 0
	adds r1, r0, 0x6
_0811F8C8:
	strh r2, [r1]
	subs r1, 0x2
	cmp r1, r0
	bge _0811F8C8
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_811F8BC

	thumb_func_start sub_811F8D8
sub_811F8D8: @ 811F8D8
	push {r4,r5,lr}
	asrs r4, r0, 9
	movs r1, 0x7F
	ldr r5, =0x000001ff
	ands r5, r0
	ands r4, r1
	adds r0, r4, 0
	bl sub_811EA28
	lsls r0, 24
	cmp r0, 0
	beq _0811F904
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_811F764
	lsls r0, 24
	lsrs r0, 24
	b _0811F906
	.pool
_0811F904:
	movs r0, 0
_0811F906:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_811F8D8

	.align 2, 0 @ Don't pad with nop.
