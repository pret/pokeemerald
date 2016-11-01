	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8124F2C
sub_8124F2C: @ 8124F2C
	push {lr}
	ldr r2, =gUnknown_03006168
	ldr r1, [r0, 0x4]
	str r1, [r2]
	ldr r2, =gUnknown_0300617C
	ldrb r1, [r0, 0x1F]
	strb r1, [r2]
	ldr r2, =gUnknown_03006164
	ldrb r1, [r0, 0x19]
	strb r1, [r2]
	ldr r2, =gUnknown_03006178
	ldrb r1, [r0, 0x1A]
	strb r1, [r2]
	ldr r2, =gUnknown_03006174
	ldrb r1, [r0, 0x1B]
	strb r1, [r2]
	ldr r2, =gUnknown_0300616C
	ldrb r1, [r0, 0x1C]
	strb r1, [r2]
	ldr r2, =gUnknown_03006180
	ldrb r1, [r0, 0x1D]
	strb r1, [r2]
	ldr r2, =gUnknown_03006170
	ldrb r1, [r0, 0x1E]
	strb r1, [r2]
	ldrb r0, [r0]
	subs r0, 0x2
	cmp r0, 0x22
	bls _08124F68
	b _081250B4
_08124F68:
	lsls r0, 2
	ldr r1, =_08124F98
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08124F98:
	.4byte _08125024
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _08125084
	.4byte _081250B4
	.4byte _0812502A
	.4byte _08125030
	.4byte _08125044
	.4byte _08125056
	.4byte _081250B4
	.4byte _0812506C
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _081250B4
	.4byte _08125072
	.4byte _08125050
	.4byte _08125078
	.4byte _0812507E
	.4byte _081250B4
	.4byte _081250B4
	.4byte _08125090
_08125024:
	bl sub_8125230
	b _081250B4
_0812502A:
	bl sub_81252E8
	b _081250B4
_08125030:
	bl sub_81254E0
	ldr r0, =gUnknown_0300617C
	ldrb r0, [r0]
	bl sub_81253A4
	b _081250B4
	.pool
_08125044:
	bl sub_81254E0
	bl sub_8125630
	bl sub_8125448
_08125050:
	bl sub_8125630
	b _081250B4
_08125056:
	bl sub_81254E0
	bl sub_81257F8
	bl sub_81257F8
	bl sub_81258A0
	bl sub_8125448
	b _081250B4
_0812506C:
	bl sub_81256C8
	b _081250B4
_08125072:
	bl sub_81254E0
	b _081250B4
_08125078:
	bl sub_81257F8
	b _081250B4
_0812507E:
	bl sub_81258A0
	b _081250B4
_08125084:
	bl sub_8125250
	movs r0, 0x3
	bl sub_81250B8
	b _081250B4
_08125090:
	bl sub_81254E0
	bl sub_81257F8
	bl sub_81258A0
	bl sub_8125448
	bl sub_81252E8
	bl sub_81252E8
	movs r0, 0x2
	bl sub_81250B8
	movs r0, 0x4
	bl sub_8125170
_081250B4:
	pop {r0}
	bx r0
	thumb_func_end sub_8124F2C

	thumb_func_start sub_81250B8
sub_81250B8: @ 81250B8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r7, r0, 24
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	mov r8, r0
	ldrb r0, [r0]
	cmp r2, r0
	bcs _0812514A
	ldr r1, =gUnknown_03006174
	mov r12, r1
	ldr r3, =gUnknown_03006180
	mov r10, r3
	ldr r0, =gUnknown_03006164
	mov r9, r0
_081250DE:
	ldr r1, =gUnknown_03006178
	ldrb r0, [r1]
	adds r0, r2
	mov r3, r10
	ldrb r1, [r3]
	muls r0, r1
	lsls r0, 1
	ldr r3, =gUnknown_03006168
	ldr r1, [r3]
	adds r1, r0
	mov r3, r9
	ldrb r0, [r3]
	lsls r0, 1
	adds r3, r1, r0
	movs r4, 0
	adds r5, r2, 0x1
	mov r0, r12
	ldrb r0, [r0]
	cmp r4, r0
	bcs _0812513E
	movs r6, 0x80
	lsls r6, 8
_0812510A:
	ldrh r1, [r3]
	adds r0, r6, 0
	ands r0, r1
	cmp r0, 0
	bne _0812512E
	movs r0, 0x1F
	ands r0, r1
	adds r0, r7
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x1F
	bls _08125124
	movs r2, 0x1F
_08125124:
	lsls r0, r2, 10
	lsls r1, r2, 5
	orrs r0, r1
	orrs r0, r2
	strh r0, [r3]
_0812512E:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	adds r3, 0x2
	mov r1, r12
	ldrb r1, [r1]
	cmp r4, r1
	bcc _0812510A
_0812513E:
	lsls r0, r5, 24
	lsrs r2, r0, 24
	mov r3, r8
	ldrb r3, [r3]
	cmp r2, r3
	bcc _081250DE
_0812514A:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81250B8

	thumb_func_start sub_8125170
sub_8125170: @ 8125170
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _08125208
	ldr r1, =gUnknown_03006174
	mov r10, r1
_0812518E:
	ldr r3, =gUnknown_03006178
	ldrb r0, [r3]
	adds r0, r2
	ldr r3, =gUnknown_03006180
	ldrb r1, [r3]
	muls r0, r1
	lsls r0, 1
	ldr r3, =gUnknown_03006168
	ldr r1, [r3]
	adds r1, r0
	ldr r3, =gUnknown_03006164
	ldrb r0, [r3]
	lsls r0, 1
	adds r3, r1, r0
	movs r5, 0
	adds r7, r2, 0x1
	mov r0, r10
	ldrb r0, [r0]
	cmp r5, r0
	bcs _081251FC
	movs r1, 0x80
	lsls r1, 8
	mov r9, r1
	movs r0, 0x1F
	mov r12, r0
	mov r1, r8
	subs r6, r0, r1
_081251C4:
	ldrh r1, [r3]
	mov r0, r9
	ands r0, r1
	cmp r0, 0
	bne _081251EC
	movs r4, 0x1F
	mov r2, r12
	ands r2, r1
	cmp r2, r6
	ble _081251E2
	mov r1, r8
	lsrs r0, r1, 1
	subs r0, r4, r0
	lsls r0, 24
	lsrs r2, r0, 24
_081251E2:
	lsls r0, r2, 10
	lsls r1, r2, 5
	orrs r0, r1
	orrs r0, r2
	strh r0, [r3]
_081251EC:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r3, 0x2
	mov r0, r10
	ldrb r0, [r0]
	cmp r5, r0
	bcc _081251C4
_081251FC:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	ldr r1, =gUnknown_0300616C
	ldrb r1, [r1]
	cmp r2, r1
	bcc _0812518E
_08125208:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8125170

	thumb_func_start sub_8125230
sub_8125230: @ 8125230
	push {r4,r5,lr}
	movs r4, 0
	ldr r5, =0x00000c7f
_08125236:
	lsls r0, r4, 16
	lsrs r0, 16
	bl sub_8125954
	adds r4, 0x1
	cmp r4, r5
	bls _08125236
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8125230

	thumb_func_start sub_8125250
sub_8125250: @ 8125250
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _081252C2
	ldr r0, =gUnknown_03006168
	mov r8, r0
	ldr r3, =gUnknown_03006174
_08125268:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r4, r8
	ldr r1, [r4]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r5, 0
	adds r6, r2, 0x1
	ldrb r0, [r3]
	cmp r5, r0
	bcs _081252B6
	movs r0, 0x80
	lsls r0, 8
	adds r7, r0, 0
_08125294:
	ldrh r0, [r4]
	ands r0, r7
	cmp r0, 0
	bne _081252A8
	adds r0, r4, 0
	str r3, [sp]
	bl sub_8125B28
	strh r0, [r4]
	ldr r3, [sp]
_081252A8:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldrb r0, [r3]
	cmp r5, r0
	bcc _08125294
_081252B6:
	lsls r0, r6, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _08125268
_081252C2:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8125250

	thumb_func_start sub_81252E8
sub_81252E8: @ 81252E8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r2, 0
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r2, r0
	bcs _0812537E
	ldr r0, =gUnknown_03006168
	mov r8, r0
	ldr r3, =gUnknown_03006180
_08125300:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	ldrb r0, [r3]
	muls r0, r1
	lsls r0, 1
	mov r4, r8
	ldr r1, [r4]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	adds r0, r2
	lsls r0, 1
	adds r4, r1, r0
	ldrh r1, [r4]
	mov r0, sp
	strh r1, [r0]
	movs r5, 0x1
	ldrb r0, [r3]
	lsls r0, 1
	adds r4, r0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	subs r0, 0x1
	adds r7, r2, 0x1
	cmp r5, r0
	bge _08125372
	ldr r6, =gUnknown_03006180
_08125336:
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _0812535C
	ldrb r2, [r6]
	lsls r2, 1
	adds r2, r4, r2
	mov r0, sp
	adds r1, r4, 0
	str r3, [sp, 0x4]
	bl sub_8125E18
	strh r0, [r4]
	mov r1, sp
	strh r0, [r1]
	ldr r3, [sp, 0x4]
_0812535C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r6]
	lsls r0, 1
	adds r4, r0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r5, r0
	blt _08125336
_08125372:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r2, r0
	bcc _08125300
_0812537E:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81252E8

	thumb_func_start sub_81253A4
sub_81253A4: @ 81253A4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _08125420
	ldr r0, =gUnknown_03006168
	mov r9, r0
	ldr r3, =gUnknown_03006174
_081253C4:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r4, r9
	ldr r1, [r4]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r5, 0
	adds r6, r2, 0x1
	ldrb r0, [r3]
	cmp r5, r0
	bcs _08125414
	movs r0, 0x80
	lsls r0, 8
	adds r7, r0, 0
_081253F0:
	ldrh r0, [r4]
	ands r0, r7
	cmp r0, 0
	bne _08125406
	adds r0, r4, 0
	mov r1, r8
	str r3, [sp]
	bl sub_8125B5C
	strh r0, [r4]
	ldr r3, [sp]
_08125406:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldrb r0, [r3]
	cmp r5, r0
	bcc _081253F0
_08125414:
	lsls r0, r6, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _081253C4
_08125420:
	add sp, 0x4
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81253A4

	thumb_func_start sub_8125448
sub_8125448: @ 8125448
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _081254BA
	ldr r0, =gUnknown_03006168
	mov r8, r0
	ldr r3, =gUnknown_03006174
_08125460:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r4, r8
	ldr r1, [r4]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r5, 0
	adds r6, r2, 0x1
	ldrb r0, [r3]
	cmp r5, r0
	bcs _081254AE
	movs r0, 0x80
	lsls r0, 8
	adds r7, r0, 0
_0812548C:
	ldrh r0, [r4]
	ands r0, r7
	cmp r0, 0
	bne _081254A0
	adds r0, r4, 0
	str r3, [sp]
	bl sub_8125C68
	strh r0, [r4]
	ldr r3, [sp]
_081254A0:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldrb r0, [r3]
	cmp r5, r0
	bcc _0812548C
_081254AE:
	lsls r0, r6, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _08125460
_081254BA:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8125448

	thumb_func_start sub_81254E0
sub_81254E0: @ 81254E0
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r7, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r7, r0
	bcs _0812556C
	ldr r0, =gUnknown_03006168
	mov r8, r0
_081254F6:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r7
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r2, r8
	ldr r1, [r2]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r5, r1, r0
	adds r4, r5, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8125C98
	strh r0, [r5]
	movs r6, 0x1
	adds r5, r4, 0
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	subs r0, 0x1
	adds r7, 0x1
	cmp r6, r0
	bge _08125556
_0812552E:
	adds r4, r5, 0x2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8125C98
	strh r0, [r5]
	subs r1, r5, 0x2
	adds r0, r5, 0
	bl sub_8125C98
	strh r0, [r5]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r5, r4, 0
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r6, r0
	blt _0812552E
_08125556:
	subs r1, r5, 0x2
	adds r0, r5, 0
	bl sub_8125C98
	strh r0, [r5]
	lsls r0, r7, 24
	lsrs r7, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r7, r0
	bcc _081254F6
_0812556C:
	movs r6, 0
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r6, r0
	bcs _0812560C
	ldr r3, =gUnknown_03006168
	mov r9, r3
	ldr r0, =gUnknown_03006180
	mov r8, r0
_0812557E:
	ldr r0, =gUnknown_03006178
	ldrb r0, [r0]
	mov r2, r8
	ldrb r1, [r2]
	muls r0, r1
	lsls r0, 1
	mov r3, r9
	ldr r2, [r3]
	adds r2, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	adds r0, r6
	lsls r0, 1
	adds r5, r2, r0
	lsls r1, 1
	adds r1, r5, r1
	adds r0, r5, 0
	bl sub_8125C98
	strh r0, [r5]
	movs r7, 0x1
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, 1
	adds r5, r0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	subs r0, 0x1
	adds r6, 0x1
	cmp r7, r0
	bge _081255F0
	ldr r4, =gUnknown_03006180
_081255BE:
	ldrb r1, [r4]
	lsls r1, 1
	adds r1, r5, r1
	adds r0, r5, 0
	bl sub_8125C98
	strh r0, [r5]
	ldrb r1, [r4]
	lsls r1, 1
	subs r1, r5, r1
	adds r0, r5, 0
	bl sub_8125C98
	strh r0, [r5]
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	ldrb r0, [r4]
	lsls r0, 1
	adds r5, r0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r7, r0
	blt _081255BE
_081255F0:
	mov r2, r8
	ldrb r1, [r2]
	lsls r1, 1
	subs r1, r5, r1
	adds r0, r5, 0
	bl sub_8125C98
	strh r0, [r5]
	lsls r0, r6, 24
	lsrs r6, r0, 24
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r6, r0
	bcc _0812557E
_0812560C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81254E0

	thumb_func_start sub_8125630
sub_8125630: @ 8125630
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _081256A2
	ldr r0, =gUnknown_03006168
	mov r8, r0
	ldr r3, =gUnknown_03006174
_08125648:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r4, r8
	ldr r1, [r4]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r5, 0
	adds r6, r2, 0x1
	ldrb r0, [r3]
	cmp r5, r0
	bcs _08125696
	movs r0, 0x80
	lsls r0, 8
	adds r7, r0, 0
_08125674:
	ldrh r0, [r4]
	ands r0, r7
	cmp r0, 0
	bne _08125688
	adds r0, r4, 0
	str r3, [sp]
	bl sub_8125CC8
	strh r0, [r4]
	ldr r3, [sp]
_08125688:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldrb r0, [r3]
	cmp r5, r0
	bcc _08125674
_08125696:
	lsls r0, r6, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _08125648
_081256A2:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8125630

	thumb_func_start sub_81256C8
sub_81256C8: @ 81256C8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	ldr r0, =gUnknown_03006168
	ldr r4, [r0]
	movs r6, 0
	movs r0, 0x80
	lsls r0, 8
	adds r5, r0, 0
_081256E0:
	movs r7, 0
_081256E2:
	ldrh r0, [r4]
	ands r0, r5
	cmp r0, 0
	bne _081256F2
	adds r0, r4, 0
	bl sub_8125CC8
	strh r0, [r4]
_081256F2:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	adds r4, 0x2
	cmp r7, 0x3F
	bls _081256E2
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, 0x3F
	bls _081256E0
	movs r7, 0
	ldr r1, =gUnknown_03006168
	mov r10, r1
	mov r3, sp
	movs r2, 0x80
	lsls r2, 8
	mov r9, r2
_08125716:
	lsls r0, r7, 1
	mov r2, r10
	ldr r1, [r2]
	adds r4, r1, r0
	ldrh r1, [r4]
	strh r1, [r3]
	mov r1, r9
	strh r1, [r4]
	movs r6, 0x1
	adds r4, 0x80
	adds r5, r0, 0
_0812572C:
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 8
	ands r0, r2
	cmp r0, 0
	bne _0812574C
	adds r2, r4, 0
	adds r2, 0x80
	mov r0, sp
	adds r1, r4, 0
	str r3, [sp, 0x4]
	bl sub_8125F38
	strh r0, [r4]
	ldr r3, [sp, 0x4]
	strh r0, [r3]
_0812574C:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r4, 0x80
	cmp r6, 0x3E
	bls _0812572C
	mov r0, r9
	strh r0, [r4]
	mov r1, r10
	ldr r0, [r1]
	adds r4, r0, r5
	ldrh r0, [r4]
	strh r0, [r3]
	mov r2, r9
	strh r2, [r4]
	movs r6, 0x1
	adds r4, 0x80
	movs r0, 0x80
	lsls r0, 8
	mov r8, r0
_08125774:
	ldrh r0, [r4]
	mov r1, r8
	ands r0, r1
	adds r5, r4, 0
	adds r5, 0x80
	cmp r0, 0
	bne _08125794
	mov r0, sp
	adds r1, r4, 0
	adds r2, r5, 0
	str r3, [sp, 0x4]
	bl sub_8125F38
	strh r0, [r4]
	ldr r3, [sp, 0x4]
	strh r0, [r3]
_08125794:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r4, r5, 0
	cmp r6, 0x3E
	bls _08125774
	mov r2, r9
	strh r2, [r4]
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3F
	bls _08125716
	ldr r0, =gUnknown_03006168
	ldr r4, [r0]
	movs r6, 0
	movs r0, 0x80
	lsls r0, 8
	mov r8, r0
_081257BA:
	movs r7, 0
	adds r5, r6, 0x1
_081257BE:
	ldrh r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, 0
	bne _081257D0
	adds r0, r4, 0
	bl sub_8125CC8
	strh r0, [r4]
_081257D0:
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	adds r4, 0x2
	cmp r7, 0x3F
	bls _081257BE
	lsls r0, r5, 24
	lsrs r6, r0, 24
	cmp r6, 0x3F
	bls _081257BA
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81256C8

	thumb_func_start sub_81257F8
sub_81257F8: @ 81257F8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _0812587A
	ldr r0, =gUnknown_03006168
	mov r8, r0
_0812580E:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	ldrh r1, [r4]
	mov r0, sp
	strh r1, [r0]
	movs r5, 0x1
	adds r4, 0x2
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	subs r0, 0x1
	adds r6, r2, 0x1
	cmp r5, r0
	bge _0812586E
	movs r0, 0x80
	lsls r0, 8
	adds r7, r0, 0
_08125846:
	ldrh r0, [r4]
	ands r0, r7
	cmp r0, 0
	bne _0812585C
	mov r0, sp
	adds r1, r4, 0
	bl sub_8125CF4
	strh r0, [r4]
	mov r1, sp
	strh r0, [r1]
_0812585C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r5, r0
	blt _08125846
_0812586E:
	lsls r0, r6, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _0812580E
_0812587A:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81257F8

	thumb_func_start sub_81258A0
sub_81258A0: @ 81258A0
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x8
	movs r2, 0
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r2, r0
	bcs _0812592E
	ldr r0, =gUnknown_03006168
	mov r8, r0
	ldr r7, =gUnknown_03006180
_081258B8:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	ldrb r0, [r7]
	muls r0, r1
	lsls r0, 1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	adds r0, r2
	lsls r0, 1
	adds r4, r1, r0
	ldrh r1, [r4]
	mov r0, sp
	strh r1, [r0]
	movs r5, 0x1
	ldrb r0, [r7]
	lsls r0, 1
	adds r4, r0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	subs r0, 0x1
	adds r6, r2, 0x1
	cmp r5, r0
	bge _08125922
	movs r0, 0x80
	lsls r0, 8
	adds r2, r0, 0
_081258F2:
	ldrh r0, [r4]
	ands r0, r2
	cmp r0, 0
	bne _0812590C
	mov r0, sp
	adds r1, r4, 0
	str r2, [sp, 0x4]
	bl sub_8125CF4
	strh r0, [r4]
	mov r1, sp
	strh r0, [r1]
	ldr r2, [sp, 0x4]
_0812590C:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	ldrb r0, [r7]
	lsls r0, 1
	adds r4, r0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	subs r0, 0x1
	cmp r5, r0
	blt _081258F2
_08125922:
	lsls r0, r6, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r2, r0
	bcc _081258B8
_0812592E:
	add sp, 0x8
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81258A0

	thumb_func_start sub_8125954
sub_8125954: @ 8125954
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x20
	lsls r0, 16
	lsrs r0, 16
	mov r10, r0
	mov r2, sp
	ldr r3, =gUnknown_085A1F94
	lsls r1, r0, 1
	add r1, r10
	adds r0, r1, r3
	ldrb r0, [r0]
	strb r0, [r2]
	adds r0, r3, 0x1
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r2, 0x1]
	mov r5, sp
	adds r0, r3, 0x2
	adds r1, r0
	ldrb r4, [r1]
	lsls r2, r4, 24
	lsrs r1, r2, 27
	movs r0, 0x7
	ands r1, r0
	strh r1, [r5, 0x2]
	lsrs r2, 25
	mov r9, r2
	movs r0, 0x3
	ands r2, r0
	mov r9, r2
	movs r5, 0x1
	ands r5, r4
	movs r4, 0x1
	mov r8, r4
	cmp r8, r1
	bcs _08125A06
	mov r3, sp
_081259A6:
	cmp r5, 0
	bne _081259C4
	mov r0, r8
	lsls r2, r0, 2
	mov r4, sp
	adds r1, r4, r2
	ldrb r0, [r3]
	mov r4, r8
	subs r0, r4
	strb r0, [r1]
	ldrb r0, [r3, 0x1]
	add r0, r8
	b _081259D6
	.pool
_081259C4:
	mov r0, r8
	lsls r2, r0, 2
	mov r4, sp
	adds r1, r4, r2
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r1]
	ldrb r0, [r3, 0x1]
	subs r0, 0x1
_081259D6:
	strb r0, [r1, 0x1]
	add r2, sp
	ldrb r0, [r2]
	cmp r0, 0x3F
	bhi _081259E6
	ldrb r0, [r2, 0x1]
	cmp r0, 0x3F
	bls _081259EE
_081259E6:
	mov r0, r8
	subs r0, 0x1
	strh r0, [r3, 0x2]
	b _08125A06
_081259EE:
	ldrh r0, [r3, 0x2]
	mov r1, r8
	subs r0, r1
	strh r0, [r2, 0x2]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	ldrh r0, [r3, 0x2]
	cmp r8, r0
	bcc _081259A6
_08125A06:
	movs r2, 0
	mov r8, r2
	mov r0, sp
	ldrh r0, [r0, 0x2]
	cmp r8, r0
	bcc _08125A14
	b _08125B16
_08125A14:
	movs r3, 0x1F
_08125A16:
	ldr r1, =gUnknown_03006168
	mov r4, r8
	lsls r0, r4, 2
	mov r2, sp
	adds r6, r2, r0
	ldrb r0, [r6, 0x1]
	lsls r0, 7
	ldr r1, [r1]
	adds r1, r0
	ldrb r0, [r6]
	lsls r0, 1
	adds r2, r1, r0
	ldrh r1, [r2]
	movs r4, 0x80
	lsls r4, 8
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _08125B02
	movs r7, 0x1F
	ands r7, r1
	lsls r0, r1, 16
	lsrs r5, r0, 21
	ands r5, r3
	lsrs r4, r0, 26
	ands r4, r3
	mov r0, r9
	cmp r0, 0
	blt _08125AF8
	cmp r0, 0x1
	ble _08125A78
	cmp r0, 0x3
	bgt _08125AF8
	ldrh r0, [r6, 0x2]
	adds r1, r7, r0
	lsls r1, 16
	lsrs r7, r1, 16
	adds r1, r5, r0
	lsls r1, 16
	lsrs r5, r1, 16
	adds r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r7, 0x1F
	bls _08125AEC
	movs r7, 0x1F
	b _08125AEC
	.pool
_08125A78:
	mov r1, r10
	lsls r0, r1, 1
	add r0, r10
	ldr r1, =gUnknown_085A1F94
	adds r1, 0x2
	adds r0, r1
	ldrb r0, [r0]
	lsrs r0, 3
	movs r1, 0x7
	ands r0, r1
	movs r1, 0x3
	str r2, [sp, 0x18]
	str r3, [sp, 0x1C]
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	ldr r2, [sp, 0x18]
	ldr r3, [sp, 0x1C]
	cmp r0, 0x1
	beq _08125AC8
	cmp r0, 0x1
	bgt _08125AB0
	cmp r0, 0
	beq _08125AB6
	b _08125AF8
	.pool
_08125AB0:
	cmp r0, 0x2
	beq _08125ADA
	b _08125AF8
_08125AB6:
	ldrh r0, [r6, 0x2]
	cmp r7, r0
	bcc _08125AC4
	subs r0, r7, r0
	lsls r0, 16
	lsrs r7, r0, 16
	b _08125AF8
_08125AC4:
	movs r7, 0
	b _08125AF8
_08125AC8:
	ldrh r0, [r6, 0x2]
	cmp r5, r0
	bcc _08125AD6
	subs r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	b _08125AF8
_08125AD6:
	movs r5, 0
	b _08125AF8
_08125ADA:
	ldrh r0, [r6, 0x2]
	cmp r4, r0
	bcc _08125AE8
	subs r0, r4, r0
	lsls r0, 16
	lsrs r4, r0, 16
	b _08125AF8
_08125AE8:
	movs r4, 0
	b _08125AF8
_08125AEC:
	cmp r5, 0x1F
	bls _08125AF2
	movs r5, 0x1F
_08125AF2:
	cmp r4, 0x1F
	bls _08125AF8
	movs r4, 0x1F
_08125AF8:
	lsls r0, r4, 10
	lsls r1, r5, 5
	orrs r0, r1
	orrs r7, r0
	strh r7, [r2]
_08125B02:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	mov r0, sp
	ldrh r0, [r0, 0x2]
	cmp r8, r0
	bcs _08125B16
	b _08125A16
_08125B16:
	add sp, 0x20
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8125954

	thumb_func_start sub_8125B28
sub_8125B28: @ 8125B28
	ldrh r2, [r0]
	movs r0, 0x1F
	adds r1, r2, 0
	ands r1, r0
	asrs r3, r2, 5
	ands r3, r0
	asrs r2, 10
	ands r2, r0
	movs r0, 0x4C
	muls r1, r0
	movs r0, 0x97
	muls r0, r3
	adds r1, r0
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r2
	adds r1, r0
	asrs r1, 8
	lsls r0, r1, 10
	lsls r2, r1, 5
	orrs r0, r2
	orrs r0, r1
	lsls r0, 16
	lsrs r0, 16
	bx lr
	thumb_func_end sub_8125B28

	thumb_func_start sub_8125B5C
sub_8125B5C: @ 8125B5C
	push {r4,lr}
	lsls r1, 24
	lsrs r4, r1, 24
	ldrh r0, [r0]
	movs r2, 0x1F
	movs r1, 0x1F
	ands r1, r0
	lsls r0, 16
	lsrs r3, r0, 21
	ands r3, r2
	lsrs r0, 26
	ands r0, r2
	cmp r1, 0x10
	bhi _08125B8C
	cmp r3, 0x10
	bhi _08125B8C
	cmp r0, 0x10
	bhi _08125B8C
	adds r0, r4, 0
	bl sub_8125B98
	lsls r0, 16
	lsrs r0, 16
	b _08125B8E
_08125B8C:
	ldr r0, =0x00007fff
_08125B8E:
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8125B5C

	thumb_func_start sub_8125B98
sub_8125B98: @ 8125B98
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	movs r0, 0
	mov r8, r0
	movs r6, 0
	movs r7, 0
	adds r0, r4, 0
	movs r1, 0x6
	bl __udivsi3
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 24
	lsrs r5, r0, 24
	adds r0, r4, 0
	movs r1, 0x6
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x5
	bhi _08125C50
	lsls r0, 2
	ldr r1, =_08125BE0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_08125BE0:
	.4byte _08125BF8
	.4byte _08125C08
	.4byte _08125C18
	.4byte _08125C26
	.4byte _08125C34
	.4byte _08125C42
_08125BF8:
	movs r0, 0x15
	subs r0, r5
	lsls r0, 16
	lsrs r6, r0, 16
	adds r7, r6, 0
	movs r1, 0
	mov r8, r1
	b _08125C50
_08125C08:
	movs r7, 0
	movs r0, 0x15
	subs r0, r5
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	mov r6, r8
	b _08125C50
_08125C18:
	movs r0, 0x15
	subs r0, r5
	lsls r0, 16
	lsrs r7, r0, 16
	movs r6, 0
	mov r8, r7
	b _08125C50
_08125C26:
	movs r7, 0
	movs r6, 0
	movs r0, 0x17
	subs r0, r5
	lsls r0, 16
	lsrs r0, 16
	b _08125C4E
_08125C34:
	movs r0, 0x17
	subs r0, r5
	lsls r0, 16
	lsrs r7, r0, 16
	movs r6, 0
	mov r8, r6
	b _08125C50
_08125C42:
	movs r7, 0
	movs r0, 0x17
	subs r0, r5
	lsls r0, 16
	lsrs r6, r0, 16
	movs r0, 0
_08125C4E:
	mov r8, r0
_08125C50:
	lsls r0, r7, 10
	lsls r1, r6, 5
	orrs r0, r1
	mov r1, r8
	orrs r1, r0
	lsls r0, r1, 16
	lsrs r0, 16
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8125B98

	thumb_func_start sub_8125C68
sub_8125C68: @ 8125C68
	push {lr}
	ldrh r0, [r0]
	movs r2, 0x1F
	movs r1, 0x1F
	ands r1, r0
	lsls r0, 16
	lsrs r3, r0, 21
	ands r3, r2
	lsrs r0, 26
	ands r0, r2
	cmp r1, 0x10
	bhi _08125C8C
	cmp r3, 0x10
	bhi _08125C8C
	cmp r0, 0x10
	bhi _08125C8C
	movs r0, 0
	b _08125C8E
_08125C8C:
	ldr r0, =0x00007fff
_08125C8E:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8125C68

	thumb_func_start sub_8125C98
sub_8125C98: @ 8125C98
	push {r4,lr}
	adds r4, r0, 0
	ldrh r3, [r4]
	cmp r3, 0
	beq _08125CC0
	movs r2, 0x80
	lsls r2, 8
	adds r0, r2, 0
	ands r0, r3
	cmp r0, 0
	beq _08125CB2
	adds r0, r2, 0
	b _08125CC2
_08125CB2:
	ldrh r1, [r1]
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	bne _08125CC0
	ldrh r0, [r4]
	b _08125CC2
_08125CC0:
	movs r0, 0
_08125CC2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8125C98

	thumb_func_start sub_8125CC8
sub_8125CC8: @ 8125CC8
	push {r4,lr}
	ldrh r1, [r0]
	movs r0, 0x1F
	movs r3, 0x1F
	ands r3, r1
	lsls r1, 16
	lsrs r2, r1, 21
	lsrs r1, 26
	subs r3, r0, r3
	adds r4, r0, 0
	bics r4, r2
	adds r2, r4, 0
	bics r0, r1
	lsls r0, 10
	lsls r2, 5
	orrs r0, r2
	orrs r0, r3
	lsls r0, 16
	lsrs r0, 16
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_8125CC8

	thumb_func_start sub_8125CF4
sub_8125CF4: @ 8125CF4
	push {r4-r7,lr}
	sub sp, 0x14
	adds r7, r1, 0
	ldrh r4, [r0]
	ldrh r5, [r7]
	lsls r6, r4, 16
	lsls r0, r5, 16
	mov r12, r0
	cmp r4, r5
	beq _08125D66
	mov r2, sp
	movs r3, 0x1F
	movs r1, 0x1F
	adds r0, r1, 0
	ands r0, r4
	strh r0, [r2]
	lsrs r0, r6, 21
	ands r0, r3
	strh r0, [r2, 0x2]
	lsrs r0, r6, 26
	ands r0, r3
	strh r0, [r2, 0x4]
	mov r0, sp
	ands r1, r5
	strh r1, [r0, 0x6]
	mov r1, sp
	mov r2, r12
	lsrs r0, r2, 21
	ands r0, r3
	strh r0, [r1, 0x8]
	lsrs r0, r2, 26
	ands r0, r3
	strh r0, [r1, 0xA]
	mov r0, sp
	ldrh r0, [r0]
	cmp r0, 0x19
	bls _08125D4E
	mov r0, sp
	ldrh r0, [r0, 0x2]
	cmp r0, 0x19
	bls _08125D4E
	mov r0, sp
	ldrh r0, [r0, 0x4]
	cmp r0, 0x19
	bhi _08125D66
_08125D4E:
	mov r0, sp
	ldrh r0, [r0, 0x6]
	cmp r0, 0x19
	bls _08125D6A
	mov r0, sp
	ldrh r0, [r0, 0x8]
	cmp r0, 0x19
	bls _08125D6A
	mov r0, sp
	ldrh r0, [r0, 0xA]
	cmp r0, 0x19
	bls _08125D6A
_08125D66:
	ldrh r0, [r7]
	b _08125E10
_08125D6A:
	movs r4, 0
	add r6, sp, 0xC
	mov r7, sp
	adds r7, 0x6
	adds r5, r6, 0
_08125D74:
	lsls r2, r4, 1
	mov r1, sp
	adds r0, r1, r2
	adds r1, r7, r2
	ldrh r3, [r0]
	ldrh r0, [r1]
	cmp r3, r0
	bls _08125D8A
	adds r1, r5, r2
	subs r0, r3, r0
	b _08125D8E
_08125D8A:
	adds r1, r5, r2
	subs r0, r3
_08125D8E:
	strh r0, [r1]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0x2
	bls _08125D74
	adds r1, r6, 0
	ldrh r0, [r1, 0x2]
	ldrh r3, [r1]
	cmp r3, r0
	bcc _08125DB4
	ldrh r2, [r1, 0x4]
	cmp r3, r2
	bcc _08125DAE
	adds r2, r3, 0
	b _08125DC8
_08125DAE:
	cmp r0, r2
	bcs _08125DBA
	b _08125DC2
_08125DB4:
	ldrh r2, [r1, 0x4]
	cmp r0, r2
	bcc _08125DBE
_08125DBA:
	ldrh r2, [r1, 0x2]
	b _08125DC8
_08125DBE:
	cmp r2, r3
	bcc _08125DC6
_08125DC2:
	ldrh r2, [r1, 0x4]
	b _08125DC8
_08125DC6:
	ldrh r2, [r6]
_08125DC8:
	mov r0, sp
	ldrh r1, [r0, 0x6]
	lsrs r0, r2, 1
	movs r6, 0x1F
	subs r6, r0
	adds r0, r1, 0
	muls r0, r6
	movs r1, 0x1F
	bl __divsi3
	adds r5, r0, 0
	lsls r5, 16
	lsrs r5, 16
	mov r0, sp
	ldrh r0, [r0, 0x8]
	muls r0, r6
	movs r1, 0x1F
	bl __divsi3
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	mov r0, sp
	ldrh r0, [r0, 0xA]
	muls r0, r6
	movs r1, 0x1F
	bl __divsi3
	lsls r0, 16
	lsrs r0, 6
	lsls r4, 5
	orrs r0, r4
	orrs r5, r0
	lsls r5, 16
	lsrs r5, 16
	adds r0, r5, 0
_08125E10:
	add sp, 0x14
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8125CF4

	thumb_func_start sub_8125E18
sub_8125E18: @ 8125E18
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r3, r0, 0
	mov r10, r1
	str r2, [sp]
	ldrh r1, [r3]
	mov r0, r10
	ldrh r0, [r0]
	cmp r1, r0
	bne _08125E40
	ldrh r0, [r2]
	cmp r0, r1
	bne _08125E40
	mov r1, r10
	ldrh r0, [r1]
	b _08125F28
_08125E40:
	mov r2, r10
	ldrh r0, [r2]
	movs r1, 0x1F
	mov r9, r1
	movs r4, 0x1F
	adds r5, r4, 0
	ands r5, r0
	lsls r0, 16
	lsrs r2, r0, 21
	mov r1, r9
	ands r1, r2
	mov r8, r1
	lsrs r0, 26
	mov r2, r9
	ands r2, r0
	str r2, [sp, 0x4]
	ldrh r2, [r3]
	adds r0, r4, 0
	ands r0, r2
	lsls r2, 16
	lsrs r1, r2, 21
	mov r3, r9
	ands r1, r3
	adds r0, r1
	lsrs r2, 26
	ands r2, r3
	adds r0, r2
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r7, r0, 16
	mov r1, r8
	adds r0, r5, r1
	ldr r2, [sp, 0x4]
	adds r0, r2
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r3, [sp]
	ldrh r1, [r3]
	ands r4, r1
	lsls r1, 16
	lsrs r0, r1, 21
	mov r2, r9
	ands r0, r2
	adds r4, r0
	lsrs r1, 26
	ands r1, r2
	adds r4, r1
	adds r0, r4, 0
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r7, r6
	bne _08125EC2
	cmp r1, r6
	bne _08125EC2
	mov r3, r10
	ldrh r0, [r3]
	b _08125F28
_08125EC2:
	cmp r7, r6
	bls _08125ECA
	subs r0, r7, r6
	b _08125ECC
_08125ECA:
	subs r0, r6, r7
_08125ECC:
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, r6
	bls _08125ED8
	subs r0, r1, r6
	b _08125EDA
_08125ED8:
	subs r0, r6, r1
_08125EDA:
	lsls r0, 16
	lsrs r0, 16
	cmp r2, r0
	bcc _08125EE4
	adds r0, r2, 0
_08125EE4:
	lsrs r0, 1
	movs r4, 0x1F
	subs r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	muls r0, r4
	movs r1, 0x1F
	bl __divsi3
	lsls r0, 16
	lsrs r5, r0, 16
	mov r0, r8
	muls r0, r4
	movs r1, 0x1F
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r1, [sp, 0x4]
	adds r0, r1, 0
	muls r0, r4
	movs r1, 0x1F
	bl __divsi3
	lsls r0, 16
	lsrs r0, 6
	mov r2, r8
	lsls r1, r2, 5
	orrs r0, r1
	orrs r5, r0
	lsls r0, r5, 16
	lsrs r0, 16
_08125F28:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8125E18

	thumb_func_start sub_8125F38
sub_8125F38: @ 8125F38
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x8
	adds r3, r0, 0
	mov r10, r1
	str r2, [sp]
	ldrh r1, [r3]
	mov r0, r10
	ldrh r0, [r0]
	cmp r1, r0
	bne _08125F60
	ldrh r0, [r2]
	cmp r0, r1
	bne _08125F60
	mov r1, r10
	ldrh r0, [r1]
	b _08126046
_08125F60:
	mov r2, r10
	ldrh r0, [r2]
	movs r1, 0x1F
	mov r9, r1
	movs r4, 0x1F
	adds r5, r4, 0
	ands r5, r0
	lsls r0, 16
	lsrs r2, r0, 21
	mov r1, r9
	ands r1, r2
	mov r8, r1
	lsrs r0, 26
	mov r2, r9
	ands r2, r0
	str r2, [sp, 0x4]
	ldrh r2, [r3]
	adds r0, r4, 0
	ands r0, r2
	lsls r2, 16
	lsrs r1, r2, 21
	mov r3, r9
	ands r1, r3
	adds r0, r1
	lsrs r2, 26
	ands r2, r3
	adds r0, r2
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r7, r0, 16
	mov r1, r8
	adds r0, r5, r1
	ldr r2, [sp, 0x4]
	adds r0, r2
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r3, [sp]
	ldrh r1, [r3]
	ands r4, r1
	lsls r1, 16
	lsrs r0, r1, 21
	mov r2, r9
	ands r0, r2
	adds r4, r0
	lsrs r1, 26
	ands r1, r2
	adds r4, r1
	adds r0, r4, 0
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	lsrs r1, r0, 16
	cmp r7, r6
	bne _08125FE2
	cmp r1, r6
	bne _08125FE2
	mov r3, r10
	ldrh r0, [r3]
	b _08126046
_08125FE2:
	cmp r7, r6
	bls _08125FEA
	subs r0, r7, r6
	b _08125FEC
_08125FEA:
	subs r0, r6, r7
_08125FEC:
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r1, r6
	bls _08125FF8
	subs r0, r1, r6
	b _08125FFA
_08125FF8:
	subs r0, r6, r1
_08125FFA:
	lsls r0, 16
	lsrs r0, 16
	cmp r2, r0
	bcc _08126004
	adds r0, r2, 0
_08126004:
	movs r4, 0x1F
	subs r4, r0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	muls r0, r4
	movs r1, 0x1F
	bl __divsi3
	lsls r0, 16
	lsrs r5, r0, 16
	mov r0, r8
	muls r0, r4
	movs r1, 0x1F
	bl __divsi3
	lsls r0, 16
	lsrs r0, 16
	mov r8, r0
	ldr r1, [sp, 0x4]
	adds r0, r1, 0
	muls r0, r4
	movs r1, 0x1F
	bl __divsi3
	lsls r0, 16
	lsrs r0, 6
	mov r2, r8
	lsls r1, r2, 5
	orrs r0, r1
	orrs r5, r0
	lsls r0, r5, 16
	lsrs r0, 16
_08126046:
	add sp, 0x8
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_8125F38

	thumb_func_start sub_8126058
sub_8126058: @ 8126058
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldrb r1, [r0, 0x1D]
	lsrs r5, r1, 3
	ldrb r1, [r0, 0x1E]
	lsrs r1, 3
	str r1, [sp, 0x8]
	ldr r1, [r0, 0x4]
	str r1, [sp]
	ldr r2, [r0, 0x10]
	str r2, [sp, 0x4]
	ldrh r0, [r0, 0x16]
	cmp r0, 0x2
	bne _08126108
	movs r1, 0
	ldr r0, [sp, 0x8]
	cmp r1, r0
	bcc _08126086
	b _08126194
_08126086:
	movs r0, 0
	adds r2, r1, 0x1
	mov r10, r2
	cmp r0, r5
	bcs _081260FA
	adds r2, r1, 0
	muls r2, r5
	mov r9, r2
	lsls r1, 3
	mov r8, r1
_0812609A:
	movs r4, 0
	lsls r6, r0, 4
	adds r7, r0, 0x1
	add r0, r9
	lsls r0, 6
	ldr r1, [sp, 0x4]
	adds r1, r0
	mov r12, r1
_081260AA:
	lsls r0, r4, 3
	mov r2, r12
	adds r3, r2, r0
	mov r1, r8
	adds r0, r1, r4
	lsls r0, 3
	muls r0, r5
	lsls r0, 1
	ldr r2, [sp]
	adds r0, r2, r0
	adds r2, r0, r6
	ldrh r0, [r2, 0x2]
	lsls r0, 8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r3]
	ldrh r0, [r2, 0x6]
	lsls r0, 8
	ldrh r1, [r2, 0x4]
	orrs r0, r1
	strh r0, [r3, 0x2]
	ldrh r0, [r2, 0xA]
	lsls r0, 8
	ldrh r1, [r2, 0x8]
	orrs r0, r1
	strh r0, [r3, 0x4]
	ldrh r0, [r2, 0xE]
	lsls r0, 8
	ldrh r1, [r2, 0xC]
	orrs r0, r1
	strh r0, [r3, 0x6]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x7
	bls _081260AA
	lsls r0, r7, 16
	lsrs r0, 16
	cmp r0, r5
	bcc _0812609A
_081260FA:
	mov r1, r10
	lsls r0, r1, 16
	lsrs r1, r0, 16
	ldr r2, [sp, 0x8]
	cmp r1, r2
	bcc _08126086
	b _08126194
_08126108:
	movs r1, 0
	ldr r0, [sp, 0x8]
	cmp r1, r0
	bcs _08126194
_08126110:
	movs r0, 0
	adds r2, r1, 0x1
	mov r10, r2
	cmp r0, r5
	bcs _08126188
	adds r2, r1, 0
	muls r2, r5
	mov r9, r2
	lsls r1, 3
	mov r8, r1
_08126124:
	movs r4, 0
	lsls r6, r0, 4
	adds r7, r0, 0x1
	add r0, r9
	lsls r0, 5
	ldr r1, [sp, 0x4]
	adds r1, r0
	mov r12, r1
_08126134:
	lsls r0, r4, 2
	mov r2, r12
	adds r3, r2, r0
	mov r1, r8
	adds r0, r1, r4
	lsls r0, 3
	muls r0, r5
	lsls r0, 1
	ldr r2, [sp]
	adds r0, r2, r0
	adds r2, r0, r6
	ldrh r1, [r2, 0x2]
	lsls r1, 4
	ldrh r0, [r2]
	orrs r1, r0
	ldrh r0, [r2, 0x4]
	lsls r0, 8
	orrs r1, r0
	ldrh r0, [r2, 0x6]
	lsls r0, 12
	orrs r1, r0
	strh r1, [r3]
	ldrh r1, [r2, 0xA]
	lsls r1, 4
	ldrh r0, [r2, 0x8]
	orrs r1, r0
	ldrh r0, [r2, 0xC]
	lsls r0, 8
	orrs r1, r0
	ldrh r0, [r2, 0xE]
	lsls r0, 12
	orrs r1, r0
	strh r1, [r3, 0x2]
	adds r0, r4, 0x1
	lsls r0, 16
	lsrs r4, r0, 16
	cmp r4, 0x7
	bls _08126134
	lsls r0, r7, 16
	lsrs r0, 16
	cmp r0, r5
	bcc _08126124
_08126188:
	mov r1, r10
	lsls r0, r1, 16
	lsrs r1, r0, 16
	ldr r2, [sp, 0x8]
	cmp r1, r2
	bcc _08126110
_08126194:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8126058

	thumb_func_start sub_81261A4
sub_81261A4: @ 81261A4
	push {lr}
	ldr r2, =gUnknown_03006188
	ldrb r1, [r0, 0x18]
	lsls r1, 4
	strh r1, [r2]
	ldr r3, =gUnknown_03006184
	ldrh r2, [r2]
	lsls r2, 1
	ldr r1, [r0, 0x8]
	adds r1, r2
	str r1, [r3]
	ldr r2, =gUnknown_03006168
	ldr r1, [r0, 0x4]
	str r1, [r2]
	ldr r2, =gUnknown_03006164
	ldrb r1, [r0, 0x19]
	strb r1, [r2]
	ldr r2, =gUnknown_03006178
	ldrb r1, [r0, 0x1A]
	strb r1, [r2]
	ldr r2, =gUnknown_03006174
	ldrb r1, [r0, 0x1B]
	strb r1, [r2]
	ldr r2, =gUnknown_0300616C
	ldrb r1, [r0, 0x1C]
	strb r1, [r2]
	ldr r2, =gUnknown_03006180
	ldrb r1, [r0, 0x1D]
	strb r1, [r2]
	ldr r2, =gUnknown_03006170
	ldrb r1, [r0, 0x1E]
	strb r1, [r2]
	ldrh r0, [r0, 0x14]
	cmp r0, 0x5
	bhi _0812626A
	lsls r0, 2
	ldr r1, =_0812621C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0812621C:
	.4byte _08126234
	.4byte _0812623C
	.4byte _08126244
	.4byte _0812624E
	.4byte _08126258
	.4byte _08126262
_08126234:
	movs r0, 0
	bl sub_81263A4
	b _0812626A
_0812623C:
	movs r0, 0x1
	bl sub_81263A4
	b _0812626A
_08126244:
	bl sub_8126270
	bl sub_8126714
	b _0812626A
_0812624E:
	bl sub_8126370
	bl sub_8126664
	b _0812626A
_08126258:
	bl sub_8126334
	bl sub_81265B4
	b _0812626A
_08126262:
	bl sub_8126318
	bl sub_81264FC
_0812626A:
	pop {r0}
	bx r0
	thumb_func_end sub_81261A4

	thumb_func_start sub_8126270
sub_8126270: @ 8126270
	ldr r2, =gUnknown_03006184
	ldr r1, [r2]
	movs r0, 0
	strh r0, [r1]
	ldr r0, [r2]
	ldr r2, =0x000018c6
	adds r1, r2, 0
	strh r1, [r0, 0x2]
	ldr r2, =0x000077bd
	adds r1, r2, 0
	strh r1, [r0, 0x4]
	ldr r2, =0x00002d6b
	adds r1, r2, 0
	strh r1, [r0, 0x6]
	ldr r2, =0x000018dd
	adds r1, r2, 0
	strh r1, [r0, 0x8]
	ldr r2, =0x00001ba6
	adds r1, r2, 0
	strh r1, [r0, 0xA]
	ldr r2, =0x000074c6
	adds r1, r2, 0
	strh r1, [r0, 0xC]
	ldr r2, =0x00001bbd
	adds r1, r2, 0
	strh r1, [r0, 0xE]
	ldr r2, =0x000074dd
	adds r1, r2, 0
	strh r1, [r0, 0x10]
	ldr r2, =0x000077a6
	adds r1, r2, 0
	strh r1, [r0, 0x12]
	ldr r2, =0x0000197d
	adds r1, r2, 0
	strh r1, [r0, 0x14]
	ldr r2, =0x00001bab
	adds r1, r2, 0
	strh r1, [r0, 0x16]
	ldr r2, =0x00007566
	adds r1, r2, 0
	strh r1, [r0, 0x18]
	ldr r2, =0x00002cdd
	adds r1, r2, 0
	strh r1, [r0, 0x1A]
	ldr r2, =0x00002fa6
	adds r1, r2, 0
	strh r1, [r0, 0x1C]
	ldr r2, =0x000074cb
	adds r1, r2, 0
	strh r1, [r0, 0x1E]
	bx lr
	.pool
	thumb_func_end sub_8126270

	thumb_func_start sub_8126318
sub_8126318: @ 8126318
	ldr r2, =gUnknown_03006184
	ldr r0, [r2]
	movs r1, 0
	strh r1, [r0]
	ldr r2, [r2]
	strh r1, [r2, 0x2]
	ldr r1, =0x00007fff
	adds r0, r1, 0
	strh r0, [r2, 0x4]
	bx lr
	.pool
	thumb_func_end sub_8126318

	thumb_func_start sub_8126334
sub_8126334: @ 8126334
	push {r4,r5,lr}
	ldr r1, =gUnknown_03006184
	ldr r0, [r1]
	movs r2, 0
	strh r2, [r0]
	ldr r0, [r1]
	strh r2, [r0, 0x2]
	movs r4, 0
	adds r5, r1, 0
_08126346:
	ldr r0, [r5]
	lsls r2, r4, 1
	adds r2, r0
	adds r0, r4, 0x2
	lsls r3, r0, 1
	lsls r1, r0, 11
	lsls r0, 6
	orrs r1, r0
	orrs r1, r3
	strh r1, [r2, 0x4]
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0xD
	bls _08126346
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8126334

	thumb_func_start sub_8126370
sub_8126370: @ 8126370
	push {r4,lr}
	ldr r2, =gUnknown_03006184
	ldr r1, [r2]
	movs r0, 0
	strh r0, [r1]
	movs r3, 0
	adds r4, r2, 0
_0812637E:
	ldr r0, [r4]
	lsls r2, r3, 1
	adds r2, r0
	lsls r0, r3, 10
	lsls r1, r3, 5
	orrs r0, r1
	orrs r0, r3
	strh r0, [r2, 0x2]
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0x1F
	bls _0812637E
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8126370

	thumb_func_start sub_81263A4
sub_81263A4: @ 81263A4
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	movs r1, 0xDF
	mov r9, r1
	cmp r0, 0
	bne _081263BC
	movs r2, 0xFF
	mov r9, r2
_081263BC:
	movs r6, 0
	ldr r3, =gUnknown_03006184
	mov r12, r3
	mov r0, r9
	lsls r4, r0, 1
	ldr r5, =gUnknown_0300616C
	cmp r6, r9
	bcs _081263E0
	movs r2, 0
_081263CE:
	ldr r0, [r3]
	lsls r1, r6, 1
	adds r1, r0
	strh r2, [r1]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	cmp r6, r9
	bcc _081263CE
_081263E0:
	mov r1, r12
	ldr r0, [r1]
	adds r0, r4, r0
	ldr r2, =0x00003def
	adds r1, r2, 0
	strh r1, [r0]
	movs r3, 0
	ldrb r5, [r5]
	cmp r3, r5
	bcs _081264E4
_081263F4:
	ldr r2, =gUnknown_03006168
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r3
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	ldr r1, [r2]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r6, 0
	ldr r0, =gUnknown_03006174
	adds r2, r0, 0
	adds r3, 0x1
	mov r10, r3
	ldrb r3, [r2]
	cmp r6, r3
	bcs _081264D6
	ldr r0, =gUnknown_03006188
	mov r8, r0
_08126424:
	ldrh r0, [r4]
	movs r3, 0x80
	lsls r3, 8
	adds r1, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08126464
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r4]
	adds r6, 0x1
	adds r7, r4, 0x2
	b _081264CA
	.pool
_08126464:
	adds r0, r4, 0
	bl sub_81267C4
	lsls r0, 16
	lsrs r5, r0, 16
	movs r3, 0x1
	adds r6, 0x1
	adds r7, r4, 0x2
	cmp r3, r9
	bcs _081264C0
	ldr r0, =gUnknown_03006184
	ldr r2, [r0]
	ldrh r1, [r2, 0x2]
	mov r12, r0
	cmp r1, 0
	bne _08126494
	strh r5, [r2, 0x2]
	mov r2, r8
	ldrh r0, [r2]
	adds r0, 0x1
	b _081264BE
	.pool
_08126494:
	mov r2, r12
	ldr r1, [r2]
	lsls r0, r3, 1
	adds r0, r1
	ldrh r0, [r0]
	cmp r0, r5
	beq _081264B8
	adds r0, r3, 0x1
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, r9
	bcs _081264C0
	lsls r0, r3, 1
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, 0
	bne _08126494
	strh r5, [r1]
_081264B8:
	mov r1, r8
	ldrh r0, [r1]
	adds r0, r3
_081264BE:
	strh r0, [r4]
_081264C0:
	ldr r2, =gUnknown_03006174
	cmp r3, r9
	bne _081264CA
	mov r3, r9
	strh r3, [r4]
_081264CA:
	lsls r0, r6, 24
	lsrs r6, r0, 24
	adds r4, r7, 0
	ldrb r0, [r2]
	cmp r6, r0
	bcc _08126424
_081264D6:
	mov r1, r10
	lsls r0, r1, 24
	lsrs r3, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r3, r0
	bcc _081263F4
_081264E4:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81263A4

	thumb_func_start sub_81264FC
sub_81264FC: @ 81264FC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _081265A0
	ldr r0, =gUnknown_03006168
	mov r8, r0
_08126510:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r6, 0
	ldr r0, =gUnknown_03006174
	adds r3, r0, 0
	adds r7, r2, 0x1
	ldrb r0, [r3]
	cmp r6, r0
	bcs _08126594
	ldr r5, =gUnknown_03006188
_0812653C:
	ldrh r0, [r4]
	movs r2, 0x80
	lsls r2, 8
	adds r1, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _0812656C
	ldrh r0, [r5]
	strh r0, [r4]
	b _08126586
	.pool
_0812656C:
	adds r0, r4, 0
	bl sub_8125C68
	lsls r0, 16
	cmp r0, 0
	bne _0812657E
	ldrh r0, [r5]
	adds r0, 0x1
	b _08126582
_0812657E:
	ldrh r0, [r5]
	adds r0, 0x2
_08126582:
	strh r0, [r4]
	ldr r3, =gUnknown_03006174
_08126586:
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	adds r4, 0x2
	ldrb r0, [r3]
	cmp r6, r0
	bcc _0812653C
_08126594:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _08126510
_081265A0:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81264FC

	thumb_func_start sub_81265B4
sub_81265B4: @ 81265B4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _08126650
	ldr r0, =gUnknown_03006168
	mov r8, r0
_081265CA:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r5, 0
	ldr r0, =gUnknown_03006174
	adds r7, r2, 0x1
	ldrb r0, [r0]
	cmp r5, r0
	bcs _08126644
	ldr r6, =gUnknown_03006188
	movs r0, 0x80
	lsls r0, 8
	adds r2, r0, 0
_081265FA:
	ldrh r0, [r4]
	ands r0, r2
	cmp r0, 0
	beq _08126624
	ldrh r0, [r6]
	strh r0, [r4]
	b _08126634
	.pool
_08126624:
	adds r0, r4, 0
	str r2, [sp]
	bl sub_8126908
	ldrh r1, [r6]
	adds r0, r1
	strh r0, [r4]
	ldr r2, [sp]
_08126634:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r5, r0
	bcc _081265FA
_08126644:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _081265CA
_08126650:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81265B4

	thumb_func_start sub_8126664
sub_8126664: @ 8126664
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _08126700
	ldr r0, =gUnknown_03006168
	mov r8, r0
_0812667A:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r5, 0
	ldr r0, =gUnknown_03006174
	adds r7, r2, 0x1
	ldrb r0, [r0]
	cmp r5, r0
	bcs _081266F4
	ldr r6, =gUnknown_03006188
	movs r0, 0x80
	lsls r0, 8
	adds r2, r0, 0
_081266AA:
	ldrh r0, [r4]
	ands r0, r2
	cmp r0, 0
	beq _081266D4
	ldrh r0, [r6]
	strh r0, [r4]
	b _081266E4
	.pool
_081266D4:
	adds r0, r4, 0
	str r2, [sp]
	bl sub_812693C
	ldrh r1, [r6]
	adds r0, r1
	strh r0, [r4]
	ldr r2, [sp]
_081266E4:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r5, r0
	bcc _081266AA
_081266F4:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _0812667A
_08126700:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8126664

	thumb_func_start sub_8126714
sub_8126714: @ 8126714
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x4
	movs r2, 0
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcs _081267B0
	ldr r0, =gUnknown_03006168
	mov r8, r0
_0812672A:
	ldr r0, =gUnknown_03006178
	ldrb r1, [r0]
	adds r1, r2
	ldr r0, =gUnknown_03006180
	ldrb r0, [r0]
	muls r0, r1
	lsls r0, 1
	mov r3, r8
	ldr r1, [r3]
	adds r1, r0
	ldr r0, =gUnknown_03006164
	ldrb r0, [r0]
	lsls r0, 1
	adds r4, r1, r0
	movs r5, 0
	ldr r0, =gUnknown_03006174
	adds r7, r2, 0x1
	ldrb r0, [r0]
	cmp r5, r0
	bcs _081267A4
	ldr r6, =gUnknown_03006188
	movs r0, 0x80
	lsls r0, 8
	adds r2, r0, 0
_0812675A:
	ldrh r0, [r4]
	ands r0, r2
	cmp r0, 0
	beq _08126784
	ldrh r0, [r6]
	strh r0, [r4]
	b _08126794
	.pool
_08126784:
	adds r0, r4, 0
	str r2, [sp]
	bl sub_8126838
	ldrh r1, [r6]
	adds r0, r1
	strh r0, [r4]
	ldr r2, [sp]
_08126794:
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	adds r4, 0x2
	ldr r0, =gUnknown_03006174
	ldrb r0, [r0]
	cmp r5, r0
	bcc _0812675A
_081267A4:
	lsls r0, r7, 24
	lsrs r2, r0, 24
	ldr r0, =gUnknown_0300616C
	ldrb r0, [r0]
	cmp r2, r0
	bcc _0812672A
_081267B0:
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8126714

	thumb_func_start sub_81267C4
sub_81267C4: @ 81267C4
	push {r4,lr}
	ldrh r0, [r0]
	movs r1, 0x1F
	movs r4, 0x1F
	ands r4, r0
	lsls r0, 16
	lsrs r3, r0, 21
	ands r3, r1
	lsrs r2, r0, 26
	ands r2, r1
	movs r1, 0x3
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	beq _081267E8
	movs r0, 0x1C
	ands r0, r4
	adds r4, r0, 0x4
_081267E8:
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _081267F6
	movs r0, 0x1C
	ands r0, r3
	adds r3, r0, 0x4
_081267F6:
	adds r0, r2, 0
	ands r0, r1
	cmp r0, 0
	beq _08126804
	movs r0, 0x1C
	ands r0, r2
	adds r2, r0, 0x4
_08126804:
	cmp r4, 0x5
	bhi _0812680A
	movs r4, 0x6
_0812680A:
	cmp r4, 0x1E
	bls _08126810
	movs r4, 0x1E
_08126810:
	cmp r3, 0x5
	bhi _08126816
	movs r3, 0x6
_08126816:
	cmp r3, 0x1E
	bls _0812681C
	movs r3, 0x1E
_0812681C:
	cmp r2, 0x5
	bhi _08126822
	movs r2, 0x6
_08126822:
	cmp r2, 0x1E
	bls _08126828
	movs r2, 0x1E
_08126828:
	lsls r0, r2, 10
	lsls r1, r3, 5
	orrs r0, r1
	orrs r4, r0
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81267C4

	thumb_func_start sub_8126838
sub_8126838: @ 8126838
	push {lr}
	ldrh r0, [r0]
	movs r1, 0x1F
	movs r3, 0x1F
	ands r3, r0
	lsls r0, 16
	lsrs r2, r0, 21
	ands r2, r1
	lsrs r0, 26
	ands r0, r1
	cmp r3, 0xB
	bhi _0812685C
	cmp r2, 0xA
	bhi _0812685C
	cmp r0, 0xA
	bhi _0812685C
	movs r0, 0x1
	b _08126902
_0812685C:
	cmp r3, 0x13
	bls _08126880
	cmp r2, 0x13
	bls _08126868
	cmp r0, 0x13
	bhi _0812688C
_08126868:
	cmp r3, 0x13
	bls _08126880
	cmp r2, 0x13
	bls _08126876
	cmp r0, 0xE
	bhi _0812688C
	b _081268C4
_08126876:
	cmp r0, 0x13
	bls _08126880
	cmp r2, 0xE
	bhi _0812688C
	b _081268A0
_08126880:
	cmp r2, 0x13
	bls _08126890
	cmp r0, 0x13
	bls _08126890
	cmp r3, 0xE
	bls _081268E8
_0812688C:
	movs r0, 0x2
	b _08126902
_08126890:
	cmp r3, 0x13
	bls _081268B4
	cmp r2, 0xB
	bls _081268A8
	cmp r0, 0xB
	bls _081268A4
	cmp r2, r0
	bcs _081268C4
_081268A0:
	movs r0, 0x8
	b _08126902
_081268A4:
	movs r0, 0xA
	b _08126902
_081268A8:
	cmp r0, 0xB
	bls _081268B0
	movs r0, 0xD
	b _08126902
_081268B0:
	movs r0, 0x4
	b _08126902
_081268B4:
	cmp r2, 0x13
	bls _081268D8
	cmp r3, 0xB
	bls _081268CC
	cmp r0, 0xB
	bls _081268C8
	cmp r3, r0
	bcc _081268E8
_081268C4:
	movs r0, 0x7
	b _08126902
_081268C8:
	movs r0, 0xB
	b _08126902
_081268CC:
	cmp r0, 0xB
	bls _081268D4
	movs r0, 0xE
	b _08126902
_081268D4:
	movs r0, 0x5
	b _08126902
_081268D8:
	cmp r0, 0x13
	bls _08126900
	cmp r3, 0xB
	bls _081268EC
	cmp r2, 0xB
	bls _081268F4
	cmp r3, r2
	bcs _081268A0
_081268E8:
	movs r0, 0x9
	b _08126902
_081268EC:
	cmp r2, 0xB
	bls _081268F4
	movs r0, 0xC
	b _08126902
_081268F4:
	cmp r0, 0xB
	bls _081268FC
	movs r0, 0xF
	b _08126902
_081268FC:
	movs r0, 0x6
	b _08126902
_08126900:
	movs r0, 0x3
_08126902:
	pop {r1}
	bx r1
	thumb_func_end sub_8126838

	thumb_func_start sub_8126908
sub_8126908: @ 8126908
	push {lr}
	ldrh r1, [r0]
	movs r3, 0x1F
	movs r0, 0x1F
	ands r0, r1
	lsls r1, 16
	lsrs r2, r1, 21
	ands r2, r3
	lsrs r1, 26
	ands r1, r3
	adds r0, r2
	adds r0, r1
	movs r1, 0x3
	bl __divsi3
	movs r1, 0x1E
	ands r0, r1
	lsls r0, 16
	cmp r0, 0
	beq _08126934
	lsrs r0, 17
	b _08126936
_08126934:
	movs r0, 0x1
_08126936:
	pop {r1}
	bx r1
	thumb_func_end sub_8126908

	thumb_func_start sub_812693C
sub_812693C: @ 812693C
	push {lr}
	ldrh r1, [r0]
	movs r3, 0x1F
	movs r0, 0x1F
	ands r0, r1
	lsls r1, 16
	lsrs r2, r1, 21
	ands r2, r3
	lsrs r1, 26
	ands r1, r3
	adds r0, r2
	adds r0, r1
	movs r1, 0x3
	bl __divsi3
	lsls r0, 16
	movs r1, 0x80
	lsls r1, 9
	adds r0, r1
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_812693C

	.align 2, 0 @ Don't pad with nop.
