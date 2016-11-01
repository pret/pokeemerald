	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start MultiBootInit
@ void MultiBootInit(MultiBootParam *mp)
MultiBootInit: @ 81BA6D0
	adds r2, r0, 0
	movs r1, 0
	strb r1, [r2, 0x1E]
	strb r1, [r2, 0x18]
	strb r1, [r2, 0x1D]
	adds r3, r2, 0
	adds r3, 0x4A
	movs r0, 0xF
	strb r0, [r3]
	adds r0, r2, 0
	adds r0, 0x48
	strb r1, [r0]
	strh r1, [r2, 0x16]
	ldr r0, =0x04000134
	strh r1, [r0]
	ldr r2, =0x04000128
	ldr r3, =0x00002003
	adds r0, r3, 0
	strh r0, [r2]
	ldr r0, =0x0400012a
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end MultiBootInit

	thumb_func_start MultiBootMain
@ int MultiBootMain(MultiBootParam *mp)
MultiBootMain: @ 81BA70C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	bl MultiBootCheckComplete
	cmp r0, 0
	beq _081BA722
	b _081BAAEA
_081BA722:
	adds r0, r7, 0
	adds r0, 0x4A
	ldrb r1, [r0]
	mov r10, r0
	cmp r1, 0xF
	bls _081BA736
	subs r0, r1, 0x1
	mov r1, r10
	strb r0, [r1]
	b _081BAAEA
_081BA736:
	adds r1, r7, 0
	adds r1, 0x48
	ldrb r0, [r1]
	cmp r0, 0
	beq _081BA760
	movs r0, 0
	strb r0, [r1]
	ldr r0, =0x04000128
	ldrh r0, [r0]
	movs r5, 0xFC
	ands r5, r0
	cmp r5, 0x8
	beq _081BA760
	adds r0, r7, 0
	bl MultiBootInit
	movs r0, 0x8
	eors r0, r5
	b _081BAAEC
	.pool
_081BA760:
	ldrb r0, [r7, 0x18]
	cmp r0, 0xDF
	bls _081BA7B2
	adds r0, r7, 0
	bl MultiBootHandShake
	adds r5, r0, 0
	cmp r5, 0
	beq _081BA774
	b _081BAAEC
_081BA774:
	adds r0, r7, 0
	adds r0, 0x4B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081BA790
	ldrb r0, [r7, 0x18]
	cmp r0, 0xE1
	bls _081BA790
	adds r0, r7, 0
	bl MultiBootCheckComplete
	cmp r0, 0
	bne _081BA790
	b _081BAADA
_081BA790:
	adds r0, r7, 0
	bl MultiBootCheckComplete
	cmp r0, 0
	beq _081BA79C
	b _081BAAEA
_081BA79C:
	ldrh r0, [r7, 0x16]
	cmp r0, 0
	bne _081BA7AC
	adds r0, r7, 0
	bl MultiBootInit
	movs r0, 0x71
	b _081BAAEC
_081BA7AC:
	subs r0, 0x1
	strh r0, [r7, 0x16]
	b _081BAAEA
_081BA7B2:
	ldrb r0, [r7, 0x18]
	cmp r0, 0x2
	bne _081BA7BA
	b _081BA8F0
_081BA7BA:
	cmp r0, 0x2
	bgt _081BA7C8
	cmp r0, 0
	beq _081BA7D6
	cmp r0, 0x1
	beq _081BA892
	b _081BAA28
_081BA7C8:
	cmp r0, 0xD0
	bne _081BA7CE
	b _081BA93C
_081BA7CE:
	cmp r0, 0xD1
	bne _081BA7D4
	b _081BA9D6
_081BA7D4:
	b _081BAA28
_081BA7D6:
	movs r3, 0xE
	movs r5, 0x3
	ldr r0, =0x04000120
	ldrh r0, [r0, 0x6]
	adds r1, r0, 0
	ldr r0, =0x0000ffff
	ldrb r2, [r7, 0x1E]
	adds r6, r2, 0
	cmp r1, r0
	bne _081BA7FE
	adds r4, r1, 0
	ldr r1, =0x04000126
_081BA7EE:
	asrs r3, 1
	subs r1, 0x2
	subs r5, 0x1
	cmp r5, 0
	beq _081BA7FE
	ldrh r0, [r1]
	cmp r0, r4
	beq _081BA7EE
_081BA7FE:
	movs r0, 0xE
	ands r3, r0
	strb r3, [r7, 0x1D]
	movs r5, 0x3
	ldr r0, =0x04000120
	ldrh r0, [r0, 0x6]
	adds r4, r0, 0
	asrs r0, r2, 3
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081BA82C
	ldr r0, =0x00007208
	b _081BA852
	.pool
_081BA82C:
	subs r5, 0x1
	cmp r5, 0
	beq _081BA858
	lsls r0, r5, 1
	ldr r1, =0x04000120
	adds r0, r1
	ldrh r0, [r0]
	adds r4, r0, 0
	adds r0, r2, 0
	asrs r0, r5
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081BA82C
	adds r0, r1, 0
	lsls r0, r5
	movs r1, 0xE4
	lsls r1, 7
	orrs r0, r1
_081BA852:
	cmp r4, r0
	beq _081BA82C
	movs r3, 0
_081BA858:
	adds r0, r3, 0
	ands r0, r6
	strb r0, [r7, 0x1E]
	cmp r3, 0
	bne _081BA868
	movs r0, 0xF
	mov r2, r10
	strb r0, [r2]
_081BA868:
	mov r1, r10
	ldrb r0, [r1]
	cmp r0, 0
	bne _081BA884
	ldrb r0, [r7, 0x1D]
	ldrb r2, [r7, 0x1E]
	cmp r0, r2
	beq _081BA88A
	adds r0, r7, 0
	bl MultiBootStartProbe
	b _081BA892
	.pool
_081BA884:
	subs r0, 0x1
	mov r1, r10
	strb r0, [r1]
_081BA88A:
	ldrb r1, [r7, 0x1E]
	movs r2, 0xC4
	lsls r2, 7
	b _081BA992
_081BA892:
	adds r1, r7, 0
	adds r1, 0x49
	movs r0, 0
	strb r0, [r1]
	movs r5, 0x3
	mov r12, r1
	ldr r3, =gUnknown_0300129C
_081BA8A0:
	lsls r0, r5, 1
	ldr r2, =0x04000120
	adds r0, r2
	ldrh r0, [r0]
	adds r4, r0, 0
	asrs r0, r4, 8
	subs r2, r5, 0x1
	cmp r0, 0x72
	bne _081BA8CA
	lsls r0, r2, 1
	adds r0, r3
	strh r4, [r0]
	movs r0, 0xFF
	ands r4, r0
	movs r0, 0x1
	lsls r0, r5
	cmp r4, r0
	bne _081BA8CA
	ldrb r0, [r1]
	orrs r4, r0
	strb r4, [r1]
_081BA8CA:
	adds r5, r2, 0
	cmp r5, 0
	bne _081BA8A0
	ldrb r0, [r7, 0x1D]
	mov r1, r12
	ldrb r1, [r1]
	cmp r0, r1
	bne _081BA88A
	movs r0, 0x2
	strb r0, [r7, 0x18]
	mov r2, r12
	ldrb r1, [r2]
	movs r2, 0xC2
	lsls r2, 7
	b _081BA992
	.pool
_081BA8F0:
	movs r5, 0x3
	movs r0, 0x49
	adds r0, r7
	mov r12, r0
	mov r4, r12
	movs r6, 0x1
	ldr r1, =gUnknown_0300129C
	mov r9, r1
	ldr r2, =0x04000120
	mov r8, r2
_081BA904:
	ldrb r3, [r4]
	adds r0, r3, 0
	asrs r0, r5
	ands r0, r6
	subs r2, r5, 0x1
	cmp r0, 0
	beq _081BA92A
	lsls r0, r5, 1
	add r0, r8
	ldrh r1, [r0]
	lsls r0, r2, 1
	add r0, r9
	ldrh r0, [r0]
	cmp r1, r0
	beq _081BA92A
	adds r0, r6, 0
	lsls r0, r5
	eors r3, r0
	strb r3, [r4]
_081BA92A:
	adds r5, r2, 0
	cmp r5, 0
	bne _081BA904
	b _081BAA90
	.pool
_081BA93C:
	movs r3, 0x1
	movs r5, 0x3
	movs r0, 0x49
	adds r0, r7
	mov r12, r0
	adds r6, r7, 0
	adds r6, 0x19
	ldr r1, =gUnknown_0300129C
	mov r8, r1
_081BA94E:
	lsls r0, r5, 1
	ldr r2, =0x04000120
	adds r0, r2
	ldrh r0, [r0]
	adds r4, r0, 0
	subs r2, r5, 0x1
	adds r0, r6, r2
	strb r4, [r0]
	mov r0, r12
	ldrb r1, [r0]
	asrs r1, r5
	movs r0, 0x1
	ands r1, r0
	cmp r1, 0
	beq _081BA982
	asrs r0, r4, 8
	subs r0, 0x72
	cmp r0, 0x1
	bls _081BA976
	b _081BAAE0
_081BA976:
	lsls r0, r2, 1
	add r0, r8
	ldrh r0, [r0]
	cmp r4, r0
	bne _081BA982
	movs r3, 0
_081BA982:
	adds r5, r2, 0
	cmp r5, 0
	bne _081BA94E
	cmp r3, 0
	bne _081BA9A8
	ldrb r1, [r7, 0x1C]
	movs r2, 0xC6
	lsls r2, 7
_081BA992:
	adds r0, r2, 0
	orrs r1, r0
	adds r0, r7, 0
	bl MultiBootSend
	b _081BAAEC
	.pool
_081BA9A8:
	movs r0, 0xD1
	strb r0, [r7, 0x18]
	movs r3, 0x11
	movs r5, 0x3
	adds r1, r6, 0x2
_081BA9B2:
	ldrb r0, [r1]
	adds r3, r0
	subs r1, 0x1
	subs r5, 0x1
	cmp r5, 0
	bne _081BA9B2
	strb r3, [r7, 0x14]
	movs r0, 0xFF
	ands r3, r0
	movs r1, 0xC8
	lsls r1, 7
	adds r0, r1, 0
	orrs r3, r0
	adds r0, r7, 0
	adds r1, r3, 0
	bl MultiBootSend
	b _081BAAEC
_081BA9D6:
	movs r5, 0x3
	movs r2, 0x49
	ldrb r1, [r2, r7]
	ldr r2, =0x04000126
	movs r3, 0x1
_081BA9E0:
	ldrh r0, [r2]
	adds r4, r0, 0
	adds r0, r1, 0
	asrs r0, r5
	ands r0, r3
	cmp r0, 0
	beq _081BA9F4
	asrs r0, r4, 8
	cmp r0, 0x73
	bne _081BAAE0
_081BA9F4:
	subs r2, 0x2
	subs r5, 0x1
	cmp r5, 0
	bne _081BA9E0
	adds r0, r7, 0
	bl MultiBoot
	adds r5, r0, 0
	cmp r5, 0
	bne _081BAA18
	movs r0, 0xE0
	strb r0, [r7, 0x18]
	adds r0, 0xB0
	strh r0, [r7, 0x16]
	b _081BAAEA
	.pool
_081BAA18:
	adds r0, r7, 0
	bl MultiBootInit
	movs r0, 0x1E
	mov r1, r10
	strb r0, [r1]
	movs r0, 0x70
	b _081BAAEC
_081BAA28:
	movs r5, 0x3
	movs r2, 0x49
	adds r2, r7
	mov r12, r2
	mov r8, r12
	movs r0, 0x1
	mov r9, r0
_081BAA36:
	mov r1, r8
	ldrb r6, [r1]
	adds r0, r6, 0
	asrs r0, r5
	mov r2, r9
	ands r0, r2
	cmp r0, 0
	beq _081BAA70
	lsls r0, r5, 1
	ldr r1, =0x04000120
	adds r0, r1
	ldrh r0, [r0]
	adds r4, r0, 0
	asrs r2, r4, 8
	ldrb r0, [r7, 0x18]
	lsrs r0, 1
	movs r1, 0x62
	subs r1, r0
	mov r3, r9
	lsls r3, r5
	cmp r2, r1
	bne _081BAA6A
	movs r0, 0xFF
	ands r4, r0
	cmp r4, r3
	beq _081BAA70
_081BAA6A:
	eors r6, r3
	mov r2, r8
	strb r6, [r2]
_081BAA70:
	subs r5, 0x1
	cmp r5, 0
	bne _081BAA36
	ldrb r0, [r7, 0x18]
	cmp r0, 0xC4
	bne _081BAA90
	mov r0, r12
	ldrb r1, [r0]
	movs r0, 0xE
	ands r0, r1
	strb r0, [r7, 0x1E]
	strb r5, [r7, 0x18]
	b _081BA88A
	.pool
_081BAA90:
	mov r1, r12
	ldrb r0, [r1]
	cmp r0, 0
	bne _081BAAA2
	adds r0, r7, 0
	bl MultiBootInit
	movs r0, 0x50
	b _081BAAEC
_081BAAA2:
	ldrb r0, [r7, 0x18]
	adds r0, 0x2
	strb r0, [r7, 0x18]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xC4
	bne _081BAAB2
	b _081BA88A
_081BAAB2:
	ldrb r0, [r7, 0x18]
	ldr r1, [r7, 0x28]
	adds r0, r1
	subs r1, r0, 0x3
	ldrb r2, [r1]
	lsls r2, 8
	subs r0, 0x4
	ldrb r1, [r0]
	orrs r1, r2
	adds r0, r7, 0
	bl MultiBootSend
	adds r5, r0, 0
	cmp r5, 0
	bne _081BAAEC
	adds r0, r7, 0
	adds r0, 0x4B
	ldrb r0, [r0]
	cmp r0, 0x1
	bne _081BAAEA
_081BAADA:
	bl MultiBootWaitSendDone
	b _081BA736
_081BAAE0:
	adds r0, r7, 0
	bl MultiBootInit
	movs r0, 0x60
	b _081BAAEC
_081BAAEA:
	movs r0, 0
_081BAAEC:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end MultiBootMain

	thumb_func_start MultiBootSend
@ int MultiBootSend(MultiBootParam *mp, u16 data)
MultiBootSend: @ 81BAAFC
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 16
	lsrs r1, 16
	ldr r3, =0x04000128
	ldrh r0, [r3]
	movs r4, 0x8C
	ands r4, r0
	cmp r4, 0x8
	bne _081BAB34
	ldr r0, =0x0400012a
	strh r1, [r0]
	ldr r1, =0x00002083
	adds r0, r1, 0
	strh r0, [r3]
	adds r1, r2, 0
	adds r1, 0x48
	movs r0, 0x1
	strb r0, [r1]
	movs r0, 0
	b _081BAB40
	.pool
_081BAB34:
	adds r0, r2, 0
	bl MultiBootInit
	movs r0, 0x8
	eors r4, r0
	adds r0, r4, 0
_081BAB40:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end MultiBootSend

	thumb_func_start MultiBootStartProbe
@ void MultiBootStartProbe(MultiBootParam *mp)
MultiBootStartProbe: @ 81BAB48
	push {lr}
	adds r1, r0, 0
	ldrb r0, [r1, 0x18]
	cmp r0, 0
	beq _081BAB5A
	adds r0, r1, 0
	bl MultiBootInit
	b _081BAB66
_081BAB5A:
	adds r2, r1, 0
	adds r2, 0x4A
	strb r0, [r2]
	strb r0, [r1, 0x1E]
	movs r0, 0x1
	strb r0, [r1, 0x18]
_081BAB66:
	pop {r0}
	bx r0
	thumb_func_end MultiBootStartProbe

	thumb_func_start MultiBootStartMaster
@ void MultiBootStartMaster(MultiBootParam *mp, u8 *srcp, int length, u8 palette_color, s8 palette_speed)
MultiBootStartMaster: @ 81BAB6C
	push {r4-r7,lr}
	adds r4, r0, 0
	adds r6, r1, 0
	ldr r0, [sp, 0x14]
	lsls r3, 24
	lsrs r5, r3, 24
	lsls r0, 24
	lsrs r7, r0, 24
	movs r3, 0
	ldrb r0, [r4, 0x18]
	cmp r0, 0
	bne _081BABA8
	ldrb r0, [r4, 0x1E]
	cmp r0, 0
	beq _081BABA8
	adds r0, r4, 0
	adds r0, 0x4A
	ldrb r0, [r0]
	cmp r0, 0
	bne _081BABA8
	str r6, [r4, 0x20]
	adds r2, 0xF
	movs r0, 0x10
	negs r0, r0
	ands r2, r0
	subs r0, 0xF0
	adds r1, r2, r0
	ldr r0, =0x0003ff00
	cmp r1, r0
	bls _081BABB4
_081BABA8:
	adds r0, r4, 0
	bl MultiBootInit
	b _081BAC28
	.pool
_081BABB4:
	adds r0, r6, r2
	str r0, [r4, 0x24]
	lsls r1, r7, 24
	movs r2, 0x80
	lsls r2, 19
	adds r0, r1, r2
	asrs r0, 24
	adds r2, r1, 0
	cmp r0, 0x8
	bhi _081BAC14
	lsls r0, 2
	ldr r1, =_081BABD8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081BABD8:
	.4byte _081BABFC
	.4byte _081BABFC
	.4byte _081BABFC
	.4byte _081BABFC
	.4byte _081BAC06
	.4byte _081BAC0C
	.4byte _081BAC0C
	.4byte _081BAC0C
	.4byte _081BAC0C
_081BABFC:
	lsls r3, r5, 3
	asrs r1, r2, 24
	movs r0, 0x3
	subs r0, r1
	b _081BAC12
_081BAC06:
	movs r0, 0x38
	adds r3, r5, 0
	b _081BAC12
_081BAC0C:
	lsls r3, r5, 3
	asrs r0, r2, 24
	subs r0, 0x1
_081BAC12:
	orrs r3, r0
_081BAC14:
	movs r0, 0x3F
	ands r3, r0
	lsls r0, r3, 1
	movs r2, 0x7F
	negs r2, r2
	adds r1, r2, 0
	orrs r0, r1
	strb r0, [r4, 0x1C]
	movs r0, 0xD0
	strb r0, [r4, 0x18]
_081BAC28:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end MultiBootStartMaster

	thumb_func_start MultiBootCheckComplete
@ s32 MultiBootCheckComplete(MultiBootParam *mp)
MultiBootCheckComplete: @ 81BAC30
	push {lr}
	ldrb r0, [r0, 0x18]
	cmp r0, 0xE9
	beq _081BAC3C
	movs r0, 0
	b _081BAC3E
_081BAC3C:
	movs r0, 0x1
_081BAC3E:
	pop {r1}
	bx r1
	thumb_func_end MultiBootCheckComplete

	thumb_func_start MultiBootHandShake
@ int MultiBootHandShake(MultiBootParam *mp)
MultiBootHandShake: @ 81BAC44
	push {r4-r6,lr}
	adds r3, r0, 0
	ldrb r0, [r3, 0x18]
	cmp r0, 0xE0
	beq _081BAC60
	cmp r0, 0xE0
	blt _081BAC70
	cmp r0, 0xE8
	bgt _081BAC70
	cmp r0, 0xE7
	blt _081BAC70
	movs r4, 0x3
	ldrb r5, [r3, 0x1E]
	b _081BACD0
_081BAC60:
	movs r1, 0
	movs r0, 0xE1
	strb r0, [r3, 0x18]
	str r1, [r3, 0x4]
	movs r0, 0x80
	lsls r0, 13
	str r0, [r3]
	b _081BACC2
_081BAC70:
	movs r4, 0x3
	ldrb r5, [r3, 0x1E]
	movs r6, 0x1
	ldr r1, =0x04000126
_081BAC78:
	ldrh r0, [r1]
	adds r2, r0, 0
	adds r0, r5, 0
	asrs r0, r4
	ands r0, r6
	cmp r0, 0
	beq _081BAC8C
	ldr r0, [r3, 0x4]
	cmp r2, r0
	bne _081BAC60
_081BAC8C:
	subs r1, 0x2
	subs r4, 0x1
	cmp r4, 0
	bne _081BAC78
	ldrb r0, [r3, 0x18]
	adds r0, 0x1
	strb r0, [r3, 0x18]
	ldr r1, [r3]
	ldrh r0, [r3]
	str r0, [r3, 0x4]
	cmp r1, 0
	bne _081BACBA
	ldr r0, [r3, 0x28]
	adds r1, r0, 0
	adds r1, 0xAC
	ldrb r1, [r1]
	adds r0, 0xAD
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	str r1, [r3, 0x4]
	lsls r1, 5
	str r1, [r3]
_081BACBA:
	ldr r0, [r3]
	lsrs r0, 5
	str r0, [r3]
_081BACC0:
	ldrh r1, [r3]
_081BACC2:
	adds r0, r3, 0
	bl MultiBootSend
	b _081BAD28
	.pool
_081BACD0:
	lsls r0, r4, 1
	ldr r1, =0x04000120
	adds r0, r1
	ldrh r0, [r0]
	adds r2, r0, 0
	adds r0, r5, 0
	asrs r0, r4
	movs r1, 0x1
	ands r0, r1
	cmp r0, 0
	beq _081BACEC
	ldr r0, [r3, 0x4]
	cmp r2, r0
	bne _081BAD1C
_081BACEC:
	subs r4, 0x1
	cmp r4, 0
	bne _081BACD0
	ldrb r0, [r3, 0x18]
	adds r0, 0x1
	strb r0, [r3, 0x18]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0xE9
	beq _081BAD26
	ldr r0, [r3, 0x28]
	adds r1, r0, 0
	adds r1, 0xAE
	ldrb r1, [r1]
	adds r0, 0xAF
	ldrb r0, [r0]
	lsls r0, 8
	orrs r1, r0
	str r1, [r3]
	str r1, [r3, 0x4]
	b _081BACC0
	.pool
_081BAD1C:
	adds r0, r3, 0
	bl MultiBootInit
	movs r0, 0x71
	b _081BAD28
_081BAD26:
	movs r0, 0
_081BAD28:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end MultiBootHandShake

	thumb_func_start MultiBootWaitCycles
@ void MultiBootWaitCycles(u32 cycles)
MultiBootWaitCycles: @ 81BAD30
	mov r2, pc
	lsrs r2, 24
	movs r1, 0xC
	cmp r2, 0x2
	beq _081BAD42
	movs r1, 0xD
	cmp r2, 0x8
	beq _081BAD42
	movs r1, 0x4
_081BAD42:
	subs r0, r1
	bgt _081BAD42
	bx lr
	thumb_func_end MultiBootWaitCycles

	thumb_func_start MultiBootWaitSendDone
@ void MultiBootWaitSendDone(void)
MultiBootWaitSendDone: @ 81BAD48
	push {r4,r5,lr}
	movs r2, 0
	ldr r3, =0x04000128
	ldrh r1, [r3]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _081BAD6C
	ldr r5, =0x0000795c
	movs r4, 0x80
_081BAD5C:
	adds r2, 0x1
	cmp r2, r5
	bgt _081BAD6C
	ldrh r1, [r3]
	adds r0, r4, 0
	ands r0, r1
	cmp r0, 0
	bne _081BAD5C
_081BAD6C:
	movs r0, 0x96
	lsls r0, 2
	bl MultiBootWaitCycles
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MultiBootWaitSendDone

	.align 2, 0 @ Don't pad with nop.
