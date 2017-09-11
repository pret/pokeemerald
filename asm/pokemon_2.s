	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GetBoxMonData
@ int GetBoxMonData(pokemon *mon, enum pokemon_data_request req, void *data)
GetBoxMonData: @ 806A674
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r8, r0
	str r1, [sp]
	adds r6, r2, 0
	movs r4, 0
	mov r9, r4
	mov r10, r4
	movs r7, 0
	movs r5, 0
	cmp r1, 0xA
	ble _0806A6F2
	ldr r1, [r0]
	movs r2, 0
	bl GetSubstruct
	mov r9, r0
	mov r0, r8
	ldr r1, [r0]
	movs r2, 0x1
	bl GetSubstruct
	mov r10, r0
	mov r2, r8
	ldr r1, [r2]
	mov r0, r8
	movs r2, 0x2
	bl GetSubstruct
	adds r7, r0, 0
	mov r0, r8
	ldr r1, [r0]
	movs r2, 0x3
	bl GetSubstruct
	adds r5, r0, 0
	mov r0, r8
	bl DecryptBoxMon
	mov r0, r8
	bl CalculateBoxMonChecksum
	lsls r0, 16
	lsrs r0, 16
	mov r1, r8
	ldrh r1, [r1, 0x1C]
	cmp r0, r1
	beq _0806A6F2
	mov r2, r8
	ldrb r0, [r2, 0x13]
	movs r1, 0x1
	orrs r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x13]
	ldrb r0, [r5, 0x7]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r5, 0x7]
_0806A6F2:
	ldr r0, [sp]
	cmp r0, 0x53
	bls _0806A6FA
	b _0806AC8C
_0806A6FA:
	lsls r0, 2
	ldr r1, =_0806A708
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0806A708:
	.4byte _0806A858
	.4byte _0806A85E
	.4byte _0806A864
	.4byte _0806A918
	.4byte _0806A91E
	.4byte _0806A924
	.4byte _0806A92A
	.4byte _0806A930
	.4byte _0806A94C
	.4byte _0806A952
	.4byte _0806A958
	.4byte _0806A95E
	.4byte _0806A976
	.4byte _0806A98E
	.4byte _0806A98E
	.4byte _0806A98E
	.4byte _0806A98E
	.4byte _0806A99A
	.4byte _0806A99A
	.4byte _0806A99A
	.4byte _0806A99A
	.4byte _0806A982
	.4byte _0806A9BC
	.4byte _0806A9C0
	.4byte _0806A9C4
	.4byte _0806A97C
	.4byte _0806A9A4
	.4byte _0806A9A8
	.4byte _0806A9AC
	.4byte _0806A9B0
	.4byte _0806A9B4
	.4byte _0806A9B8
	.4byte _0806A988
	.4byte _0806A9C8
	.4byte _0806A9D4
	.4byte _0806A9D8
	.4byte _0806A9DC
	.4byte _0806A9E4
	.4byte _0806A9EC
	.4byte _0806A9F6
	.4byte _0806A9FE
	.4byte _0806AA06
	.4byte _0806AA0E
	.4byte _0806AA16
	.4byte _0806AA1E
	.4byte _0806AA26
	.4byte _0806AA2A
	.4byte _0806A9CC
	.4byte _0806A9D0
	.4byte _0806A9F0
	.4byte _0806AA30
	.4byte _0806AA38
	.4byte _0806AA40
	.4byte _0806AA48
	.4byte _0806AA50
	.4byte _0806AC8C
	.4byte _0806AC8C
	.4byte _0806AC8C
	.4byte _0806AC8C
	.4byte _0806AC8C
	.4byte _0806AC8C
	.4byte _0806AC8C
	.4byte _0806AC8C
	.4byte _0806AC8C
	.4byte _0806AC8C
	.4byte _0806AAB6
	.4byte _0806AADC
	.4byte _0806AA58
	.4byte _0806AA5E
	.4byte _0806AA62
	.4byte _0806AA66
	.4byte _0806AA6A
	.4byte _0806AA72
	.4byte _0806AA7A
	.4byte _0806AA82
	.4byte _0806AA8A
	.4byte _0806AA90
	.4byte _0806AA98
	.4byte _0806AAA0
	.4byte _0806AAA8
	.4byte _0806AAB0
	.4byte _0806AB16
	.4byte _0806AB70
	.4byte _0806ABF2
_0806A858:
	mov r1, r8
	ldr r4, [r1]
	b _0806AC8C
_0806A85E:
	mov r2, r8
	ldr r4, [r2, 0x4]
	b _0806AC8C
_0806A864:
	mov r0, r8
	ldrb r1, [r0, 0x13]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _0806A89C
	movs r4, 0
	ldr r0, =gBadEggNickname
	ldrb r1, [r0]
	adds r2, r0, 0
	cmp r1, 0xFF
	beq _0806A944
	adds r3, r2, 0
_0806A87E:
	adds r0, r6, r4
	adds r1, r4, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x9
	bhi _0806A944
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, 0xFF
	bne _0806A87E
	b _0806A944
	.pool
_0806A89C:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _0806A8BC
	ldr r1, =gEggNickname
	adds r0, r6, 0
	bl StringCopy
	adds r0, r6, 0
	bl StringLength
	lsls r0, 16
	lsrs r4, r0, 16
	b _0806AC8C
	.pool
_0806A8BC:
	mov r1, r8
	ldrb r0, [r1, 0x12]
	cmp r0, 0x1
	bne _0806A902
	movs r0, 0xFC
	strb r0, [r6]
	movs r0, 0x15
	strb r0, [r6, 0x1]
	movs r4, 0x2
	movs r3, 0
	ldrb r0, [r1, 0x8]
	cmp r0, 0xFF
	beq _0806A8F0
	mov r2, r8
	adds r2, 0x8
_0806A8DA:
	adds r1, r6, r4
	ldrb r0, [r2]
	strb r0, [r1]
	adds r4, 0x1
	adds r2, 0x1
	adds r3, 0x1
	cmp r3, 0x4
	bgt _0806A8F0
	ldrb r0, [r2]
	cmp r0, 0xFF
	bne _0806A8DA
_0806A8F0:
	adds r1, r6, r4
	movs r0, 0xFC
	strb r0, [r1]
	adds r4, 0x1
	adds r1, r6, r4
	movs r0, 0x16
	strb r0, [r1]
	adds r4, 0x1
	b _0806A944
_0806A902:
	movs r4, 0
	mov r2, r8
	adds r2, 0x8
_0806A908:
	adds r0, r6, r4
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x9
	bls _0806A908
	b _0806A944
_0806A918:
	mov r2, r8
	ldrb r4, [r2, 0x12]
	b _0806AC8C
_0806A91E:
	mov r6, r8
	ldrb r0, [r6, 0x13]
	b _0806AA92
_0806A924:
	mov r1, r8
	ldrb r0, [r1, 0x13]
	b _0806AA9A
_0806A92A:
	mov r2, r8
	ldrb r0, [r2, 0x13]
	b _0806AAA2
_0806A930:
	movs r4, 0
	mov r2, r8
	adds r2, 0x14
_0806A936:
	adds r0, r6, r4
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x6
	bls _0806A936
_0806A944:
	adds r1, r6, r4
	movs r0, 0xFF
	strb r0, [r1]
	b _0806AC8C
_0806A94C:
	mov r6, r8
	ldrb r4, [r6, 0x1B]
	b _0806AC8C
_0806A952:
	mov r0, r8
	ldrh r4, [r0, 0x1C]
	b _0806AC8C
_0806A958:
	mov r1, r8
	ldrh r4, [r1, 0x1E]
	b _0806AC8C
_0806A95E:
	mov r2, r8
	ldrb r1, [r2, 0x13]
	movs r0, 0x1
	ands r0, r1
	movs r4, 0xCE
	lsls r4, 1
	cmp r0, 0
	beq _0806A970
	b _0806AC8C
_0806A970:
	mov r6, r9
	ldrh r4, [r6]
	b _0806AC8C
_0806A976:
	mov r0, r9
	ldrh r4, [r0, 0x2]
	b _0806AC8C
_0806A97C:
	mov r1, r9
	ldr r4, [r1, 0x4]
	b _0806AC8C
_0806A982:
	mov r2, r9
	ldrb r4, [r2, 0x8]
	b _0806AC8C
_0806A988:
	mov r6, r9
	ldrb r4, [r6, 0x9]
	b _0806AC8C
_0806A98E:
	ldr r0, [sp]
	subs r0, 0xD
	lsls r0, 1
	add r0, r10
	ldrh r4, [r0]
	b _0806AC8C
_0806A99A:
	ldr r0, [sp]
	add r0, r10
	subs r0, 0x9
	ldrb r4, [r0]
	b _0806AC8C
_0806A9A4:
	ldrb r4, [r7]
	b _0806AC8C
_0806A9A8:
	ldrb r4, [r7, 0x1]
	b _0806AC8C
_0806A9AC:
	ldrb r4, [r7, 0x2]
	b _0806AC8C
_0806A9B0:
	ldrb r4, [r7, 0x3]
	b _0806AC8C
_0806A9B4:
	ldrb r4, [r7, 0x4]
	b _0806AC8C
_0806A9B8:
	ldrb r4, [r7, 0x5]
	b _0806AC8C
_0806A9BC:
	ldrb r4, [r7, 0x6]
	b _0806AC8C
_0806A9C0:
	ldrb r4, [r7, 0x7]
	b _0806AC8C
_0806A9C4:
	ldrb r4, [r7, 0x8]
	b _0806AC8C
_0806A9C8:
	ldrb r4, [r7, 0x9]
	b _0806AC8C
_0806A9CC:
	ldrb r4, [r7, 0xA]
	b _0806AC8C
_0806A9D0:
	ldrb r4, [r7, 0xB]
	b _0806AC8C
_0806A9D4:
	ldrb r4, [r5]
	b _0806AC8C
_0806A9D8:
	ldrb r4, [r5, 0x1]
	b _0806AC8C
_0806A9DC:
	ldrb r0, [r5, 0x2]
	lsls r0, 25
	lsrs r4, r0, 25
	b _0806AC8C
_0806A9E4:
	ldrh r0, [r5, 0x2]
	lsls r0, 21
	lsrs r4, r0, 28
	b _0806AC8C
_0806A9EC:
	ldrb r0, [r5, 0x3]
	b _0806AAAA
_0806A9F0:
	ldrb r0, [r5, 0x3]
	lsrs r4, r0, 7
	b _0806AC8C
_0806A9F6:
	ldrb r0, [r5, 0x4]
	lsls r0, 27
	lsrs r4, r0, 27
	b _0806AC8C
_0806A9FE:
	ldrh r0, [r5, 0x4]
	lsls r0, 22
	lsrs r4, r0, 27
	b _0806AC8C
_0806AA06:
	ldrb r0, [r5, 0x5]
	lsls r0, 25
	lsrs r4, r0, 27
	b _0806AC8C
_0806AA0E:
	ldr r0, [r5, 0x4]
	lsls r0, 12
	lsrs r4, r0, 27
	b _0806AC8C
_0806AA16:
	ldrh r0, [r5, 0x6]
	lsls r0, 23
	lsrs r4, r0, 27
	b _0806AC8C
_0806AA1E:
	ldrb r0, [r5, 0x7]
	lsls r0, 26
	lsrs r4, r0, 27
	b _0806AC8C
_0806AA26:
	ldrb r0, [r5, 0x7]
	b _0806AA84
_0806AA2A:
	ldrb r0, [r5, 0x7]
	lsrs r4, r0, 7
	b _0806AC8C
_0806AA30:
	ldrb r0, [r5, 0x8]
	lsls r0, 29
	lsrs r4, r0, 29
	b _0806AC8C
_0806AA38:
	ldrb r0, [r5, 0x8]
	lsls r0, 26
	lsrs r4, r0, 29
	b _0806AC8C
_0806AA40:
	ldrh r0, [r5, 0x8]
	lsls r0, 23
	lsrs r4, r0, 29
	b _0806AC8C
_0806AA48:
	ldrb r0, [r5, 0x9]
	lsls r0, 28
	lsrs r4, r0, 29
	b _0806AC8C
_0806AA50:
	ldrb r0, [r5, 0x9]
	lsls r0, 25
	lsrs r4, r0, 29
	b _0806AC8C
_0806AA58:
	ldrb r0, [r5, 0x9]
	lsrs r4, r0, 7
	b _0806AC8C
_0806AA5E:
	ldrb r0, [r5, 0xA]
	b _0806AA92
_0806AA62:
	ldrb r0, [r5, 0xA]
	b _0806AA9A
_0806AA66:
	ldrb r0, [r5, 0xA]
	b _0806AAA2
_0806AA6A:
	ldrb r0, [r5, 0xA]
	lsls r0, 28
	lsrs r4, r0, 31
	b _0806AC8C
_0806AA72:
	ldrb r0, [r5, 0xA]
	lsls r0, 27
	lsrs r4, r0, 31
	b _0806AC8C
_0806AA7A:
	ldrb r0, [r5, 0xA]
	lsls r0, 26
	lsrs r4, r0, 31
	b _0806AC8C
_0806AA82:
	ldrb r0, [r5, 0xA]
_0806AA84:
	lsls r0, 25
	lsrs r4, r0, 31
	b _0806AC8C
_0806AA8A:
	ldrb r0, [r5, 0xA]
	lsrs r4, r0, 7
	b _0806AC8C
_0806AA90:
	ldrb r0, [r5, 0xB]
_0806AA92:
	lsls r0, 31
	lsrs r4, r0, 31
	b _0806AC8C
_0806AA98:
	ldrb r0, [r5, 0xB]
_0806AA9A:
	lsls r0, 30
	lsrs r4, r0, 31
	b _0806AC8C
_0806AAA0:
	ldrb r0, [r5, 0xB]
_0806AAA2:
	lsls r0, 29
	lsrs r4, r0, 31
	b _0806AC8C
_0806AAA8:
	ldrb r0, [r5, 0xB]
_0806AAAA:
	lsls r0, 25
	lsrs r4, r0, 28
	b _0806AC8C
_0806AAB0:
	ldrb r0, [r5, 0xB]
	lsrs r4, r0, 7
	b _0806AC8C
_0806AAB6:
	mov r0, r9
	ldrh r4, [r0]
	cmp r4, 0
	bne _0806AAC0
	b _0806AC8C
_0806AAC0:
	ldrb r0, [r5, 0x7]
	lsls r0, 25
	cmp r0, 0
	blt _0806AAD6
	mov r2, r8
	ldrb r1, [r2, 0x13]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _0806AAD6
	b _0806AC8C
_0806AAD6:
	movs r4, 0xCE
	lsls r4, 1
	b _0806AC8C
_0806AADC:
	ldrb r0, [r5, 0x4]
	lsls r0, 27
	lsrs r4, r0, 27
	ldrh r1, [r5, 0x4]
	movs r0, 0xF8
	lsls r0, 2
	ands r0, r1
	orrs r4, r0
	ldrb r0, [r5, 0x5]
	lsls r0, 25
	lsrs r0, 27
	lsls r0, 10
	orrs r4, r0
	ldr r0, [r5, 0x4]
	movs r1, 0xF8
	lsls r1, 12
	ands r0, r1
	orrs r4, r0
	ldrh r0, [r5, 0x6]
	lsls r0, 23
	lsrs r0, 27
	lsls r0, 20
	orrs r4, r0
	ldrb r0, [r5, 0x7]
	lsls r0, 26
	lsrs r0, 27
	lsls r0, 25
	orrs r4, r0
	b _0806AC8C
_0806AB16:
	mov r1, r9
	ldrh r0, [r1]
	cmp r0, 0
	bne _0806AB20
	b _0806AC8C
_0806AB20:
	ldrb r0, [r5, 0x7]
	lsls r0, 25
	cmp r0, 0
	bge _0806AB2A
	b _0806AC8C
_0806AB2A:
	ldrh r0, [r6]
	ldr r1, =0x00000163
	cmp r0, r1
	bne _0806AB34
	b _0806AC8C
_0806AB34:
	mov r2, r10
	ldrh r5, [r2]
	adds r7, r1, 0
	adds r2, r6, 0
	ldr r1, =gBitTable
_0806AB3E:
	ldrh r3, [r2]
	cmp r5, r3
	beq _0806AB58
	mov r6, r10
	ldrh r0, [r6, 0x2]
	cmp r0, r3
	beq _0806AB58
	ldrh r0, [r6, 0x4]
	cmp r0, r3
	beq _0806AB58
	ldrh r0, [r6, 0x6]
	cmp r0, r3
	bne _0806AB5C
_0806AB58:
	ldr r0, [r1]
	orrs r4, r0
_0806AB5C:
	adds r2, 0x2
	adds r1, 0x4
	ldrh r0, [r2]
	cmp r0, r7
	bne _0806AB3E
	b _0806AC8C
	.pool
_0806AB70:
	movs r4, 0
	mov r1, r9
	ldrh r0, [r1]
	cmp r0, 0
	bne _0806AB7C
	b _0806AC8C
_0806AB7C:
	ldrb r0, [r5, 0x7]
	lsls r0, 25
	cmp r0, 0
	bge _0806AB86
	b _0806AC8C
_0806AB86:
	ldrb r0, [r5, 0x8]
	lsls r1, r0, 29
	lsrs r4, r1, 29
	lsls r0, 26
	lsrs r0, 29
	adds r4, r0
	ldrh r0, [r5, 0x8]
	lsls r0, 23
	lsrs r0, 29
	adds r4, r0
	ldrb r1, [r5, 0x9]
	lsls r0, r1, 28
	lsrs r0, 29
	adds r4, r0
	lsls r0, r1, 25
	lsrs r0, 29
	adds r4, r0
	lsrs r1, 7
	adds r4, r1
	ldrb r1, [r5, 0xA]
	lsls r0, r1, 31
	lsrs r0, 31
	adds r4, r0
	lsls r0, r1, 30
	lsrs r0, 31
	adds r4, r0
	lsls r0, r1, 29
	lsrs r0, 31
	adds r4, r0
	lsls r0, r1, 28
	lsrs r0, 31
	adds r4, r0
	lsls r0, r1, 27
	lsrs r0, 31
	adds r4, r0
	lsls r0, r1, 26
	lsrs r0, 31
	adds r4, r0
	lsls r0, r1, 25
	lsrs r0, 31
	adds r4, r0
	lsrs r1, 7
	adds r4, r1
	ldrb r1, [r5, 0xB]
	lsls r0, r1, 31
	lsrs r0, 31
	adds r4, r0
	lsls r0, r1, 30
	lsrs r0, 31
	adds r4, r0
	lsls r1, 29
	lsrs r1, 31
	adds r4, r1
	b _0806AC8C
_0806ABF2:
	movs r4, 0
	mov r2, r9
	ldrh r0, [r2]
	cmp r0, 0
	beq _0806AC8C
	ldrb r0, [r5, 0x7]
	lsls r0, 25
	cmp r0, 0
	blt _0806AC8C
	ldrb r2, [r5, 0x9]
	lsrs r4, r2, 7
	ldrb r1, [r5, 0x8]
	lsls r0, r1, 29
	lsrs r0, 28
	orrs r4, r0
	lsls r1, 26
	lsrs r1, 29
	lsls r1, 4
	orrs r4, r1
	ldrh r0, [r5, 0x8]
	lsls r0, 23
	lsrs r0, 29
	lsls r0, 7
	orrs r4, r0
	lsls r0, r2, 28
	lsrs r0, 29
	lsls r0, 10
	orrs r4, r0
	lsls r2, 25
	lsrs r2, 29
	lsls r2, 13
	orrs r4, r2
	ldrb r1, [r5, 0xA]
	lsls r0, r1, 31
	lsrs r0, 31
	lsls r0, 16
	orrs r4, r0
	lsls r0, r1, 30
	lsrs r0, 31
	lsls r0, 17
	orrs r4, r0
	lsls r0, r1, 29
	lsrs r0, 31
	lsls r0, 18
	orrs r4, r0
	lsls r0, r1, 28
	lsrs r0, 31
	lsls r0, 19
	orrs r4, r0
	lsls r0, r1, 27
	lsrs r0, 31
	lsls r0, 20
	orrs r4, r0
	lsls r0, r1, 26
	lsrs r0, 31
	lsls r0, 21
	orrs r4, r0
	lsls r0, r1, 25
	lsrs r0, 31
	lsls r0, 22
	orrs r4, r0
	lsrs r1, 7
	lsls r1, 23
	orrs r4, r1
	ldrb r1, [r5, 0xB]
	lsls r0, r1, 31
	lsrs r0, 31
	lsls r0, 24
	orrs r4, r0
	lsls r0, r1, 30
	lsrs r0, 31
	lsls r0, 25
	orrs r4, r0
	lsls r1, 29
	lsrs r1, 31
	lsls r1, 26
	orrs r4, r1
_0806AC8C:
	ldr r6, [sp]
	cmp r6, 0xA
	ble _0806AC98
	mov r0, r8
	bl EncryptBoxMon
_0806AC98:
	adds r0, r4, 0
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end GetBoxMonData

	thumb_func_start SetMonData
@ int SetMonData(pokemon *mon, enum pokemon_data_request req, void *data)
SetMonData: @ 806ACAC
	push {lr}
	adds r3, r0, 0
	adds r0, r1, 0
	subs r0, 0x37
	cmp r0, 0xA
	bhi _0806AD90
	lsls r0, 2
	ldr r1, =_0806ACC8
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0806ACC8:
	.4byte _0806ACF4
	.4byte _0806AD0C
	.4byte _0806AD16
	.4byte _0806AD26
	.4byte _0806AD36
	.4byte _0806AD46
	.4byte _0806AD56
	.4byte _0806AD66
	.4byte _0806AD76
	.4byte _0806AD86
	.4byte _0806AD96
_0806ACF4:
	ldrb r1, [r2]
	ldrb r0, [r2, 0x1]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r2, 0x2]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r2, 0x3]
	lsls r0, 24
	adds r1, r0
	str r1, [r3, 0x50]
	b _0806AD96
_0806AD0C:
	ldrb r1, [r2]
	adds r0, r3, 0
	adds r0, 0x54
	strb r1, [r0]
	b _0806AD96
_0806AD16:
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0x56
	strh r0, [r1]
	b _0806AD96
_0806AD26:
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0x58
	strh r0, [r1]
	b _0806AD96
_0806AD36:
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0x5A
	strh r0, [r1]
	b _0806AD96
_0806AD46:
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0x5C
	strh r0, [r1]
	b _0806AD96
_0806AD56:
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0x5E
	strh r0, [r1]
	b _0806AD96
_0806AD66:
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0x60
	strh r0, [r1]
	b _0806AD96
_0806AD76:
	ldrb r0, [r2]
	ldrb r1, [r2, 0x1]
	lsls r1, 8
	adds r0, r1
	adds r1, r3, 0
	adds r1, 0x62
	strh r0, [r1]
	b _0806AD96
_0806AD86:
	ldrb r1, [r2]
	adds r0, r3, 0
	adds r0, 0x55
	strb r1, [r0]
	b _0806AD96
_0806AD90:
	adds r0, r3, 0
	bl SetBoxMonData
_0806AD96:
	pop {r0}
	bx r0
	thumb_func_end SetMonData

	thumb_func_start SetBoxMonData
@ int SetBoxMonData(pokemon *mon, enum pokemon_data_request req, void *data)
SetBoxMonData: @ 806AD9C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	adds r7, r0, 0
	mov r10, r1
	adds r4, r2, 0
	movs r0, 0
	mov r8, r0
	mov r9, r0
	movs r6, 0
	movs r5, 0
	cmp r1, 0xA
	ble _0806AE1C
	ldr r1, [r7]
	adds r0, r7, 0
	movs r2, 0
	bl GetSubstruct
	mov r8, r0
	ldr r1, [r7]
	adds r0, r7, 0
	movs r2, 0x1
	bl GetSubstruct
	mov r9, r0
	ldr r1, [r7]
	adds r0, r7, 0
	movs r2, 0x2
	bl GetSubstruct
	adds r6, r0, 0
	ldr r1, [r7]
	adds r0, r7, 0
	movs r2, 0x3
	bl GetSubstruct
	adds r5, r0, 0
	adds r0, r7, 0
	bl DecryptBoxMon
	adds r0, r7, 0
	bl CalculateBoxMonChecksum
	lsls r0, 16
	lsrs r0, 16
	ldrh r1, [r7, 0x1C]
	cmp r0, r1
	beq _0806AE1C
	ldrb r0, [r7, 0x13]
	movs r1, 0x1
	orrs r0, r1
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r7, 0x13]
	ldrb r0, [r5, 0x7]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r5, 0x7]
	adds r0, r7, 0
	bl EncryptBoxMon
	b _0806B3EC
_0806AE1C:
	mov r0, r10
	cmp r0, 0x50
	bls _0806AE24
	b _0806B3D8
_0806AE24:
	lsls r0, 2
	ldr r1, =_0806AE34
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_0806AE34:
	.4byte _0806AF78
	.4byte _0806AF90
	.4byte _0806AFA8
	.4byte _0806AFBE
	.4byte _0806AFC4
	.4byte _0806AFD4
	.4byte _0806AFE6
	.4byte _0806AFF8
	.4byte _0806B00E
	.4byte _0806B014
	.4byte _0806B020
	.4byte _0806B02C
	.4byte _0806B04C
	.4byte _0806B084
	.4byte _0806B084
	.4byte _0806B084
	.4byte _0806B084
	.4byte _0806B098
	.4byte _0806B098
	.4byte _0806B098
	.4byte _0806B098
	.4byte _0806B074
	.4byte _0806B0C8
	.4byte _0806B0CE
	.4byte _0806B0D4
	.4byte _0806B05A
	.4byte _0806B0A4
	.4byte _0806B0AA
	.4byte _0806B0B0
	.4byte _0806B0B6
	.4byte _0806B0BC
	.4byte _0806B0C2
	.4byte _0806B07C
	.4byte _0806B0DA
	.4byte _0806B0EC
	.4byte _0806B0F2
	.4byte _0806B0F8
	.4byte _0806B10C
	.4byte _0806B124
	.4byte _0806B14A
	.4byte _0806B15E
	.4byte _0806B178
	.4byte _0806B18E
	.4byte _0806B1A8
	.4byte _0806B1C0
	.4byte _0806B1D4
	.4byte _0806B204
	.4byte _0806B0E0
	.4byte _0806B0E6
	.4byte _0806B13A
	.4byte _0806B214
	.4byte _0806B222
	.4byte _0806B238
	.4byte _0806B250
	.4byte _0806B260
	.4byte _0806B3D8
	.4byte _0806B3D8
	.4byte _0806B3D8
	.4byte _0806B3D8
	.4byte _0806B3D8
	.4byte _0806B3D8
	.4byte _0806B3D8
	.4byte _0806B3D8
	.4byte _0806B3D8
	.4byte _0806B3D8
	.4byte _0806B3D8
	.4byte _0806B35E
	.4byte _0806B276
	.4byte _0806B286
	.4byte _0806B294
	.4byte _0806B2A4
	.4byte _0806B2B4
	.4byte _0806B2C4
	.4byte _0806B2D4
	.4byte _0806B2E4
	.4byte _0806B2FA
	.4byte _0806B30A
	.4byte _0806B318
	.4byte _0806B328
	.4byte _0806B338
	.4byte _0806B34E
_0806AF78:
	ldrb r1, [r4]
	ldrb r0, [r4, 0x1]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r4, 0x2]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r4, 0x3]
	lsls r0, 24
	adds r1, r0
	str r1, [r7]
	b _0806B3D8
_0806AF90:
	ldrb r1, [r4]
	ldrb r0, [r4, 0x1]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r4, 0x2]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r4, 0x3]
	lsls r0, 24
	adds r1, r0
	str r1, [r7, 0x4]
	b _0806B3D8
_0806AFA8:
	movs r2, 0
	adds r3, r7, 0
	adds r3, 0x8
_0806AFAE:
	adds r0, r3, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x9
	ble _0806AFAE
	b _0806B3D8
_0806AFBE:
	ldrb r0, [r4]
	strb r0, [r7, 0x12]
	b _0806B3D8
_0806AFC4:
	ldrb r0, [r4]
	movs r1, 0x1
	ands r1, r0
	ldrb r2, [r7, 0x13]
	movs r0, 0x2
	negs r0, r0
	ands r0, r2
	b _0806B1F2
_0806AFD4:
	ldrb r0, [r4]
	movs r1, 0x1
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r7, 0x13]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	b _0806B1F2
_0806AFE6:
	ldrb r0, [r4]
	movs r1, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r7, 0x13]
	movs r0, 0x5
	negs r0, r0
	ands r0, r2
	b _0806B1F2
_0806AFF8:
	movs r2, 0
	adds r3, r7, 0
	adds r3, 0x14
_0806AFFE:
	adds r0, r3, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x6
	ble _0806AFFE
	b _0806B3D8
_0806B00E:
	ldrb r0, [r4]
	strb r0, [r7, 0x1B]
	b _0806B3D8
_0806B014:
	ldrb r1, [r4]
	ldrb r0, [r4, 0x1]
	lsls r0, 8
	adds r1, r0
	strh r1, [r7, 0x1C]
	b _0806B3D8
_0806B020:
	ldrb r1, [r4]
	ldrb r0, [r4, 0x1]
	lsls r0, 8
	adds r1, r0
	strh r1, [r7, 0x1E]
	b _0806B3D8
_0806B02C:
	ldrb r1, [r4]
	ldrb r0, [r4, 0x1]
	lsls r0, 8
	adds r1, r0
	mov r0, r8
	strh r1, [r0]
	lsls r1, 16
	cmp r1, 0
	beq _0806B044
	ldrb r0, [r7, 0x13]
	movs r1, 0x2
	b _0806B1F2
_0806B044:
	ldrb r1, [r7, 0x13]
	movs r0, 0x3
	negs r0, r0
	b _0806B1FE
_0806B04C:
	ldrb r1, [r4]
	ldrb r0, [r4, 0x1]
	lsls r0, 8
	adds r1, r0
	mov r0, r8
	strh r1, [r0, 0x2]
	b _0806B3D8
_0806B05A:
	ldrb r1, [r4]
	ldrb r0, [r4, 0x1]
	lsls r0, 8
	adds r1, r0
	ldrb r0, [r4, 0x2]
	lsls r0, 16
	adds r1, r0
	ldrb r0, [r4, 0x3]
	lsls r0, 24
	adds r1, r0
	mov r0, r8
	str r1, [r0, 0x4]
	b _0806B3D8
_0806B074:
	ldrb r0, [r4]
	mov r1, r8
	strb r0, [r1, 0x8]
	b _0806B3D8
_0806B07C:
	ldrb r0, [r4]
	mov r1, r8
	strb r0, [r1, 0x9]
	b _0806B3D8
_0806B084:
	mov r2, r10
	subs r2, 0xD
	lsls r2, 1
	add r2, r9
	ldrb r1, [r4]
	ldrb r0, [r4, 0x1]
	lsls r0, 8
	adds r1, r0
	strh r1, [r2]
	b _0806B3D8
_0806B098:
	mov r0, r9
	add r0, r10
	subs r0, 0x9
	ldrb r1, [r4]
	strb r1, [r0]
	b _0806B3D8
_0806B0A4:
	ldrb r0, [r4]
	strb r0, [r6]
	b _0806B3D8
_0806B0AA:
	ldrb r0, [r4]
	strb r0, [r6, 0x1]
	b _0806B3D8
_0806B0B0:
	ldrb r0, [r4]
	strb r0, [r6, 0x2]
	b _0806B3D8
_0806B0B6:
	ldrb r0, [r4]
	strb r0, [r6, 0x3]
	b _0806B3D8
_0806B0BC:
	ldrb r0, [r4]
	strb r0, [r6, 0x4]
	b _0806B3D8
_0806B0C2:
	ldrb r0, [r4]
	strb r0, [r6, 0x5]
	b _0806B3D8
_0806B0C8:
	ldrb r0, [r4]
	strb r0, [r6, 0x6]
	b _0806B3D8
_0806B0CE:
	ldrb r0, [r4]
	strb r0, [r6, 0x7]
	b _0806B3D8
_0806B0D4:
	ldrb r0, [r4]
	strb r0, [r6, 0x8]
	b _0806B3D8
_0806B0DA:
	ldrb r0, [r4]
	strb r0, [r6, 0x9]
	b _0806B3D8
_0806B0E0:
	ldrb r0, [r4]
	strb r0, [r6, 0xA]
	b _0806B3D8
_0806B0E6:
	ldrb r0, [r4]
	strb r0, [r6, 0xB]
	b _0806B3D8
_0806B0EC:
	ldrb r0, [r4]
	strb r0, [r5]
	b _0806B3D8
_0806B0F2:
	ldrb r0, [r4]
	strb r0, [r5, 0x1]
	b _0806B3D8
_0806B0F8:
	ldrb r1, [r4]
	movs r0, 0x7F
	ands r1, r0
	ldrb r2, [r5, 0x2]
	movs r0, 0x80
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x2]
	b _0806B3D8
_0806B10C:
	ldrb r1, [r4]
	movs r0, 0xF
	ands r1, r0
	lsls r1, 7
	ldrh r2, [r5, 0x2]
	ldr r0, =0xfffff87f
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x2]
	b _0806B3D8
	.pool
_0806B124:
	ldrb r1, [r4]
	movs r0, 0xF
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r5, 0x3]
	movs r0, 0x79
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x3]
	b _0806B3D8
_0806B13A:
	ldrb r0, [r4]
	lsls r0, 7
	ldrb r2, [r5, 0x3]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x3]
	b _0806B3D8
_0806B14A:
	ldrb r1, [r4]
	movs r0, 0x1F
	ands r1, r0
	ldrb r2, [r5, 0x4]
	movs r0, 0x20
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x4]
	b _0806B3D8
_0806B15E:
	ldrb r1, [r4]
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 5
	ldrh r2, [r5, 0x4]
	ldr r0, =0xfffffc1f
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	b _0806B3D8
	.pool
_0806B178:
	ldrb r1, [r4]
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0x7D
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	b _0806B3D8
_0806B18E:
	ldrb r2, [r4]
	movs r0, 0x1F
	ands r2, r0
	lsls r2, 15
	ldr r0, [r5, 0x4]
	ldr r1, =0xfff07fff
	ands r0, r1
	orrs r0, r2
	str r0, [r5, 0x4]
	b _0806B3D8
	.pool
_0806B1A8:
	ldrb r1, [r4]
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 4
	ldrh r2, [r5, 0x6]
	ldr r0, =0xfffffe0f
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x6]
	b _0806B3D8
	.pool
_0806B1C0:
	ldrb r1, [r4]
	movs r0, 0x1F
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r5, 0x7]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	b _0806B3D6
_0806B1D4:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	lsls r1, 6
	ldrb r2, [r5, 0x7]
	movs r0, 0x41
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x7]
	lsls r0, 25
	cmp r0, 0
	bge _0806B1F8
	ldrb r0, [r7, 0x13]
	movs r1, 0x4
_0806B1F2:
	orrs r0, r1
	strb r0, [r7, 0x13]
	b _0806B3D8
_0806B1F8:
	ldrb r1, [r7, 0x13]
	movs r0, 0x5
	negs r0, r0
_0806B1FE:
	ands r0, r1
	strb r0, [r7, 0x13]
	b _0806B3D8
_0806B204:
	ldrb r0, [r4]
	lsls r0, 7
	ldrb r2, [r5, 0x7]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x7]
	b _0806B3D8
_0806B214:
	ldrb r1, [r4]
	movs r0, 0x7
	ands r1, r0
	ldrb r2, [r5, 0x8]
	movs r0, 0x8
	negs r0, r0
	b _0806B230
_0806B222:
	ldrb r1, [r4]
	movs r0, 0x7
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r5, 0x8]
	movs r0, 0x39
	negs r0, r0
_0806B230:
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x8]
	b _0806B3D8
_0806B238:
	ldrb r1, [r4]
	movs r0, 0x7
	ands r1, r0
	lsls r1, 6
	ldrh r2, [r5, 0x8]
	ldr r0, =0xfffffe3f
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x8]
	b _0806B3D8
	.pool
_0806B250:
	ldrb r1, [r4]
	movs r0, 0x7
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r5, 0x9]
	movs r0, 0xF
	negs r0, r0
	b _0806B26E
_0806B260:
	ldrb r1, [r4]
	movs r0, 0x7
	ands r1, r0
	lsls r1, 4
	ldrb r2, [r5, 0x9]
	movs r0, 0x71
	negs r0, r0
_0806B26E:
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x9]
	b _0806B3D8
_0806B276:
	ldrb r0, [r4]
	lsls r0, 7
	ldrb r2, [r5, 0x9]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0x9]
	b _0806B3D8
_0806B286:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	ldrb r2, [r5, 0xA]
	movs r0, 0x2
	negs r0, r0
	b _0806B2F2
_0806B294:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r5, 0xA]
	movs r0, 0x3
	negs r0, r0
	b _0806B2F2
_0806B2A4:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0xA]
	movs r0, 0x5
	negs r0, r0
	b _0806B2F2
_0806B2B4:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r5, 0xA]
	movs r0, 0x9
	negs r0, r0
	b _0806B2F2
_0806B2C4:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	lsls r1, 4
	ldrb r2, [r5, 0xA]
	movs r0, 0x11
	negs r0, r0
	b _0806B2F2
_0806B2D4:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	lsls r1, 5
	ldrb r2, [r5, 0xA]
	movs r0, 0x21
	negs r0, r0
	b _0806B2F2
_0806B2E4:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	lsls r1, 6
	ldrb r2, [r5, 0xA]
	movs r0, 0x41
	negs r0, r0
_0806B2F2:
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0xA]
	b _0806B3D8
_0806B2FA:
	ldrb r0, [r4]
	lsls r0, 7
	ldrb r2, [r5, 0xA]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0xA]
	b _0806B3D8
_0806B30A:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	ldrb r2, [r5, 0xB]
	movs r0, 0x2
	negs r0, r0
	b _0806B346
_0806B318:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	lsls r1, 1
	ldrb r2, [r5, 0xB]
	movs r0, 0x3
	negs r0, r0
	b _0806B346
_0806B328:
	ldrb r1, [r4]
	movs r0, 0x1
	ands r1, r0
	lsls r1, 2
	ldrb r2, [r5, 0xB]
	movs r0, 0x5
	negs r0, r0
	b _0806B346
_0806B338:
	ldrb r1, [r4]
	movs r0, 0xF
	ands r1, r0
	lsls r1, 3
	ldrb r2, [r5, 0xB]
	movs r0, 0x79
	negs r0, r0
_0806B346:
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0xB]
	b _0806B3D8
_0806B34E:
	ldrb r0, [r4]
	lsls r0, 7
	ldrb r2, [r5, 0xB]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, 0xB]
	b _0806B3D8
_0806B35E:
	ldrb r3, [r4]
	ldrb r0, [r4, 0x1]
	lsls r0, 8
	orrs r3, r0
	ldrb r0, [r4, 0x2]
	lsls r0, 16
	orrs r3, r0
	ldrb r0, [r4, 0x3]
	lsls r0, 24
	orrs r3, r0
	movs r4, 0x1F
	adds r1, r3, 0
	ands r1, r4
	ldrb r2, [r5, 0x4]
	movs r0, 0x20
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x4]
	lsrs r1, r3, 5
	ands r1, r4
	lsls r1, 5
	ldrh r2, [r5, 0x4]
	ldr r0, =0xfffffc1f
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x4]
	lsrs r1, r3, 10
	ands r1, r4
	lsls r1, 2
	ldrb r2, [r5, 0x5]
	movs r0, 0x7D
	negs r0, r0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, 0x5]
	lsrs r1, r3, 15
	ands r1, r4
	lsls r1, 15
	ldr r0, [r5, 0x4]
	ldr r2, =0xfff07fff
	ands r0, r2
	orrs r0, r1
	str r0, [r5, 0x4]
	lsrs r1, r3, 20
	ands r1, r4
	lsls r1, 4
	ldrh r2, [r5, 0x6]
	ldr r0, =0xfffffe0f
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, 0x6]
	lsrs r3, 25
	ands r3, r4
	lsls r3, 1
	ldrb r1, [r5, 0x7]
	movs r0, 0x3F
	negs r0, r0
	ands r0, r1
	orrs r0, r3
_0806B3D6:
	strb r0, [r5, 0x7]
_0806B3D8:
	mov r0, r10
	cmp r0, 0xA
	ble _0806B3EC
	adds r0, r7, 0
	bl CalculateBoxMonChecksum
	strh r0, [r7, 0x1C]
	adds r0, r7, 0
	bl EncryptBoxMon
_0806B3EC:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SetBoxMonData

	thumb_func_start CopyMon
@ void *CopyMon(void *dest, void *src, unsigned int size)
CopyMon: @ 806B408
	push {lr}
	bl memcpy
	pop {r0}
	bx r0
	thumb_func_end CopyMon

	thumb_func_start GiveMonToPlayer
@ int GiveMonToPlayer(pokemon *mon)
GiveMonToPlayer: @ 806B414
	push {r4-r6,lr}
	adds r6, r0, 0
	ldr r4, =gSaveBlock2Ptr
	ldr r2, [r4]
	movs r1, 0x7
	bl SetMonData
	ldr r2, [r4]
	adds r2, 0x8
	adds r0, r6, 0
	movs r1, 0x31
	bl SetMonData
	ldr r2, [r4]
	adds r2, 0xA
	adds r0, r6, 0
	movs r1, 0x1
	bl SetMonData
	movs r5, 0
	b _0806B446
	.pool
_0806B444:
	adds r5, 0x1
_0806B446:
	cmp r5, 0x5
	bgt _0806B480
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	bne _0806B444
	adds r0, r4, 0
	adds r1, r6, 0
	movs r2, 0x64
	bl CopyMon
	ldr r1, =gPlayerPartyCount
	adds r0, r5, 0x1
	strb r0, [r1]
	movs r0, 0
	b _0806B48A
	.pool
_0806B480:
	adds r0, r6, 0
	bl SendMonToPC
	lsls r0, 24
	lsrs r0, 24
_0806B48A:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GiveMonToPlayer

	thumb_func_start SendMonToPC
@ int SendMonToPC(pokemon *mon)
SendMonToPC: @ 806B490
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r0, =0x00004036
	bl VarGet
	lsls r0, 24
	lsrs r0, 24
	bl set_unknown_box_id
	bl get_preferred_box
	lsls r0, 24
	lsrs r5, r0, 24
_0806B4AE:
	movs r6, 0
	lsls r7, r5, 24
_0806B4B2:
	lsls r1, r6, 24
	lsrs r1, 24
	lsrs r0, r7, 24
	bl get_pokemon_by_box_and_pos
	adds r4, r0, 0
	movs r1, 0xB
	movs r2, 0
	bl GetBoxMonData
	cmp r0, 0
	bne _0806B514
	mov r0, r8
	bl MonRestorePP
	adds r0, r4, 0
	mov r1, r8
	movs r2, 0x50
	bl CopyMon
	ldr r0, =gSpecialVar_0x8012
	strh r5, [r0]
	ldr r0, =gSpecialVar_0x8013
	strh r6, [r0]
	bl get_unknown_box_id
	lsls r0, 16
	lsrs r0, 16
	cmp r0, r5
	beq _0806B4F4
	ldr r0, =0x000008d7
	bl FlagReset
_0806B4F4:
	lsls r1, r5, 16
	ldr r0, =0x00004036
	lsrs r1, 16
	bl VarSet
	movs r0, 0x1
	b _0806B530
	.pool
_0806B514:
	adds r6, 0x1
	cmp r6, 0x1D
	ble _0806B4B2
	adds r5, 0x1
	cmp r5, 0xE
	bne _0806B522
	movs r5, 0
_0806B522:
	bl get_preferred_box
	lsls r0, 24
	lsrs r0, 24
	cmp r5, r0
	bne _0806B4AE
	movs r0, 0x2
_0806B530:
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end SendMonToPC

	thumb_func_start CalculatePlayerPartyCount
@ u8 CalculatePlayerPartyCount()
CalculatePlayerPartyCount: @ 806B53C
	push {r4,lr}
	ldr r0, =gPlayerPartyCount
	movs r1, 0
	strb r1, [r0]
	b _0806B554
	.pool
_0806B54C:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	adds r0, r4, 0
_0806B554:
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x5
	bhi _0806B572
	adds r1, r0, 0
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	bne _0806B54C
_0806B572:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CalculatePlayerPartyCount

	thumb_func_start CalculateEnemyPartyCount
@ u8 CalculateEnemyPartyCount()
CalculateEnemyPartyCount: @ 806B580
	push {r4,lr}
	ldr r0, =gUnknown_020244EA
	movs r1, 0
	strb r1, [r0]
	b _0806B598
	.pool
_0806B590:
	ldrb r0, [r4]
	adds r0, 0x1
	strb r0, [r4]
	adds r0, r4, 0
_0806B598:
	adds r4, r0, 0
	ldrb r0, [r4]
	cmp r0, 0x5
	bhi _0806B5B6
	adds r1, r0, 0
	movs r0, 0x64
	muls r0, r1
	ldr r1, =gEnemyParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	bne _0806B590
_0806B5B6:
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CalculateEnemyPartyCount

	thumb_func_start GetMonsStateToDoubles
GetMonsStateToDoubles: @ 806B5C4
	push {r4-r6,lr}
	movs r6, 0
	bl CalculatePlayerPartyCount
	ldr r1, =gPlayerPartyCount
	ldrb r0, [r1]
	cmp r0, 0x1
	beq _0806B628
	movs r5, 0
	ldrb r1, [r1]
	cmp r6, r1
	bge _0806B620
_0806B5DC:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	movs r1, 0xCE
	lsls r1, 1
	cmp r0, r1
	beq _0806B616
	adds r0, r4, 0
	movs r1, 0x39
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _0806B616
	adds r0, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _0806B616
	adds r6, 0x1
_0806B616:
	adds r5, 0x1
	ldr r0, =gPlayerPartyCount
	ldrb r0, [r0]
	cmp r5, r0
	blt _0806B5DC
_0806B620:
	movs r0, 0
	cmp r6, 0x1
	bgt _0806B628
	movs r0, 0x2
_0806B628:
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetMonsStateToDoubles

	thumb_func_start GetMonsStateToDoubles_2
@ u8 GetMonsStateToDoubles_2()
GetMonsStateToDoubles_2: @ 806B638
	push {r4-r6,lr}
	movs r6, 0
	movs r5, 0
_0806B63E:
	movs r0, 0x64
	adds r1, r5, 0
	muls r1, r0
	ldr r0, =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x41
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	movs r0, 0xCE
	lsls r0, 1
	cmp r1, r0
	beq _0806B670
	cmp r1, 0
	beq _0806B670
	adds r0, r4, 0
	movs r1, 0x39
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	beq _0806B670
	adds r6, 0x1
_0806B670:
	adds r5, 0x1
	cmp r5, 0x5
	ble _0806B63E
	cmp r6, 0x1
	bne _0806B684
	movs r0, 0x1
	b _0806B68C
	.pool
_0806B684:
	movs r0, 0
	cmp r6, 0x1
	bgt _0806B68C
	movs r0, 0x2
_0806B68C:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GetMonsStateToDoubles_2

	thumb_func_start GetAbilityBySpecies
@ int GetAbilityBySpecies(u16 a1, int a2)
GetAbilityBySpecies: @ 806B694
	push {lr}
	lsls r0, 16
	lsrs r3, r0, 16
	lsls r1, 24
	cmp r1, 0
	beq _0806B6B8
	ldr r2, =gLastUsedAbility
	ldr r1, =gBaseStats
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x17]
	b _0806B6C6
	.pool
_0806B6B8:
	ldr r2, =gLastUsedAbility
	ldr r1, =gBaseStats
	lsls r0, r3, 3
	subs r0, r3
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x16]
_0806B6C6:
	strb r0, [r2]
	ldrb r0, [r2]
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetAbilityBySpecies

	thumb_func_start GetMonAbility
@ u8 GetMonAbility(pokemon *mon)
GetMonAbility: @ 806B6D8
	push {r4,r5,lr}
	adds r5, r0, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	adds r0, r5, 0
	movs r1, 0x2E
	movs r2, 0
	bl GetMonData
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl GetAbilityBySpecies
	lsls r0, 24
	lsrs r0, 24
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end GetMonAbility

	thumb_func_start CreateSecretBaseEnemyParty
CreateSecretBaseEnemyParty: @ 806B70C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	adds r5, r0, 0
	bl ZeroEnemyPartyMons
	ldr r4, =gBattleResources
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r5, 0
	movs r2, 0xA0
	bl memcpy
	movs r0, 0
	mov r9, r0
_0806B730:
	ldr r1, =gBattleResources
	ldr r3, [r1]
	ldr r2, [r3]
	mov r4, r9
	lsls r7, r4, 1
	adds r0, r2, 0
	adds r0, 0x7C
	adds r1, r0, r7
	ldrh r0, [r1]
	adds r4, 0x1
	str r4, [sp, 0x10]
	cmp r0, 0
	beq _0806B80A
	movs r0, 0x64
	mov r6, r9
	muls r6, r0
	ldr r4, =gEnemyParty
	mov r8, r4
	adds r5, r6, r4
	ldrh r1, [r1]
	adds r0, r2, 0
	adds r0, 0x94
	add r0, r9
	ldrb r2, [r0]
	movs r0, 0x1
	str r0, [sp]
	ldr r0, [r3]
	mov r3, r9
	lsls r4, r3, 2
	adds r0, 0x34
	adds r0, r4
	ldr r0, [r0]
	str r0, [sp, 0x4]
	movs r0, 0x2
	str r0, [sp, 0x8]
	movs r0, 0
	str r0, [sp, 0xC]
	adds r0, r5, 0
	movs r3, 0xF
	bl CreateMon
	ldr r1, =gBattleResources
	ldr r0, [r1]
	adds r1, r7, 0
	adds r1, 0x88
	ldr r2, [r0]
	adds r2, r1
	adds r0, r5, 0
	movs r1, 0xC
	bl SetMonData
	movs r5, 0
	mov r10, r4
	mov r7, r9
	adds r7, 0x9A
	mov r4, r8
_0806B7A0:
	adds r1, r5, 0
	adds r1, 0x1A
	ldr r2, =gBattleResources
	ldr r0, [r2]
	ldr r2, [r0]
	adds r2, r7
	adds r0, r6, r4
	bl SetMonData
	adds r5, 0x1
	cmp r5, 0x5
	ble _0806B7A0
	movs r5, 0
	movs r3, 0x64
	mov r0, r9
	muls r0, r3
	ldr r1, =gEnemyParty
	adds r7, r0, r1
	mov r4, r10
	lsls r0, r4, 1
	adds r6, r0, 0
	adds r6, 0x4C
	adds r4, r0, 0
_0806B7CE:
	adds r1, r5, 0
	adds r1, 0xD
	ldr r2, =gBattleResources
	ldr r0, [r2]
	ldr r2, [r0]
	adds r2, r6
	adds r0, r7, 0
	bl SetMonData
	adds r1, r5, 0
	adds r1, 0x11
	ldr r3, =gBattleResources
	ldr r0, [r3]
	ldr r0, [r0]
	adds r0, 0x4C
	adds r0, r4
	ldrh r0, [r0]
	lsls r2, r0, 1
	adds r2, r0
	lsls r2, 2
	ldr r0, =gBattleMoves + 0x4 @ PP offset
	adds r2, r0
	adds r0, r7, 0
	bl SetMonData
	adds r6, 0x2
	adds r4, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _0806B7CE
_0806B80A:
	ldr r4, [sp, 0x10]
	mov r9, r4
	cmp r4, 0x5
	ble _0806B730
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CreateSecretBaseEnemyParty

	thumb_func_start GetSecretBaseTrainerPicIndex
GetSecretBaseTrainerPicIndex: @ 806B830
	push {r4,r5,lr}
	ldr r5, =gSecretBaseTrainerClasses
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r4, [r0]
	ldrb r0, [r4, 0x9]
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	ldrb r2, [r4, 0x1]
	lsls r2, 27
	lsrs r2, 31
	lsls r1, r2, 2
	adds r1, r2
	adds r0, r1
	adds r0, r5
	ldrb r0, [r0]
	ldr r1, =gTrainerPicIndices
	adds r0, r1
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetSecretBaseTrainerPicIndex

	thumb_func_start GetSecretBaseTrainerNameIndex
GetSecretBaseTrainerNameIndex: @ 806B870
	push {r4,r5,lr}
	ldr r5, =gSecretBaseTrainerClasses
	ldr r0, =gBattleResources
	ldr r0, [r0]
	ldr r4, [r0]
	ldrb r0, [r4, 0x9]
	movs r1, 0x5
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	ldrb r2, [r4, 0x1]
	lsls r2, 27
	lsrs r2, 31
	lsls r1, r2, 2
	adds r1, r2
	adds r0, r1
	adds r0, r5
	ldrb r0, [r0]
	ldr r1, =gTrainerClassNameIndices
	adds r0, r1
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GetSecretBaseTrainerNameIndex

	thumb_func_start PlayerPartyAndPokemonStorageFull
PlayerPartyAndPokemonStorageFull: @ 806B8B0
	push {r4,lr}
	movs r4, 0
_0806B8B4:
	movs r0, 0x64
	muls r0, r4
	ldr r1, =gPlayerParty
	adds r0, r1
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	cmp r0, 0
	bne _0806B8D0
	movs r0, 0
	b _0806B8DE
	.pool
_0806B8D0:
	adds r4, 0x1
	cmp r4, 0x5
	ble _0806B8B4
	bl PokemonStorageFull
	lsls r0, 24
	lsrs r0, 24
_0806B8DE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end PlayerPartyAndPokemonStorageFull

	thumb_func_start PokemonStorageFull
PokemonStorageFull: @ 806B8E4
	push {r4-r6,lr}
	movs r6, 0
_0806B8E8:
	movs r4, 0
	lsls r5, r6, 24
_0806B8EC:
	lsls r1, r4, 24
	lsrs r1, 24
	lsrs r0, r5, 24
	movs r2, 0xB
	bl GetBoxMonDataFromAnyBox
	cmp r0, 0
	bne _0806B900
	movs r0, 0
	b _0806B90E
_0806B900:
	adds r4, 0x1
	cmp r4, 0x1D
	ble _0806B8EC
	adds r6, 0x1
	cmp r6, 0xD
	ble _0806B8E8
	movs r0, 0x1
_0806B90E:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end PokemonStorageFull

	thumb_func_start GetSpeciesName
@ void GetSpeciesName(u8 *dest, u16 speciesId)
GetSpeciesName: @ 806B914
	push {r4-r7,lr}
	adds r6, r0, 0
	lsls r1, 16
	lsrs r5, r1, 16
	movs r1, 0
	movs r0, 0xCE
	lsls r0, 1
	mov r12, r0
	ldr r7, =gSpeciesNames
	movs r0, 0xB
	muls r0, r5
	adds r3, r0, r7
	adds r2, r6, 0
	b _0806B93A
	.pool
_0806B934:
	adds r3, 0x1
	adds r2, 0x1
	adds r1, 0x1
_0806B93A:
	adds r4, r6, r1
	cmp r1, 0xA
	bgt _0806B954
	cmp r5, r12
	bls _0806B94A
	adds r0, r1, r7
	ldrb r0, [r0]
	b _0806B94C
_0806B94A:
	ldrb r0, [r3]
_0806B94C:
	strb r0, [r2]
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _0806B934
_0806B954:
	movs r0, 0xFF
	strb r0, [r4]
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GetSpeciesName

	thumb_func_start CalculatePPWithBonus
@ u16 CalculatePPWithBonus(u16 moveId, s32 ppUpCounts, u8 monMoveIndex)
CalculatePPWithBonus: @ 806B960
	push {r4,lr}
	lsls r0, 16
	lsrs r0, 16
	lsls r2, 24
	lsrs r2, 24
	ldr r4, =gBattleMoves
	lsls r3, r0, 1
	adds r3, r0
	lsls r3, 2
	adds r3, r4
	ldrb r4, [r3, 0x4]
	ldr r0, =gUnknown_08329D22
	adds r0, r2, r0
	ldrb r3, [r0]
	ands r3, r1
	lsls r2, 1
	asrs r3, r2
	lsls r0, r3, 2
	adds r0, r3
	lsls r0, 2
	muls r0, r4
	movs r1, 0x64
	bl __divsi3
	adds r4, r0
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end CalculatePPWithBonus

	thumb_func_start RemoveMonPPBonus
RemoveMonPPBonus: @ 806B9A8
	push {r4,r5,lr}
	sub sp, 0x4
	adds r5, r0, 0
	lsls r4, r1, 24
	lsrs r4, 24
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	lsls r0, 24
	lsrs r0, 24
	mov r1, sp
	strb r0, [r1]
	ldr r1, =gUnknown_08329D26
	adds r4, r1
	ldrb r1, [r4]
	ands r1, r0
	mov r0, sp
	strb r1, [r0]
	adds r0, r5, 0
	movs r1, 0x15
	mov r2, sp
	bl SetMonData
	add sp, 0x4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end RemoveMonPPBonus

	thumb_func_start RemoveBattleMonPPBonus
RemoveBattleMonPPBonus: @ 806B9E4
	lsls r1, 24
	lsrs r1, 24
	adds r0, 0x3B
	ldr r2, =gUnknown_08329D26
	adds r1, r2
	ldrb r2, [r0]
	ldrb r1, [r1]
	ands r1, r2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end RemoveBattleMonPPBonus

	thumb_func_start CopyPlayerPartyMonToBattleData
CopyPlayerPartyMonToBattleData: @ 806B9FC
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x18
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp, 0x14]
	lsls r1, 24
	lsrs r1, 24
	mov r9, r1
	movs r0, 0x64
	mov r5, r9
	muls r5, r0
	ldr r0, =gPlayerParty
	adds r5, r0
	adds r0, r5, 0
	movs r1, 0xB
	movs r2, 0
	bl GetMonData
	ldr r1, =gBattleMons
	mov r8, r1
	movs r1, 0x58
	ldr r2, [sp, 0x14]
	adds r4, r2, 0
	muls r4, r1
	mov r3, r8
	adds r6, r4, r3
	strh r0, [r6]
	adds r0, r5, 0
	movs r1, 0xC
	movs r2, 0
	bl GetMonData
	strh r0, [r6, 0x2E]
	movs r6, 0
	mov r0, r8
	adds r0, 0x24
	adds r7, r4, r0
_0806BA4E:
	adds r1, r6, 0
	adds r1, 0xD
	adds r0, r5, 0
	movs r2, 0
	bl GetMonData
	movs r1, 0xC
	add r1, r8
	mov r10, r1
	adds r1, r4, r1
	strh r0, [r1]
	adds r1, r6, 0
	adds r1, 0x11
	adds r0, r5, 0
	movs r2, 0
	bl GetMonData
	strb r0, [r7]
	adds r7, 0x1
	adds r4, 0x2
	adds r6, 0x1
	cmp r6, 0x3
	ble _0806BA4E
	movs r0, 0x64
	mov r4, r9
	muls r4, r0
	ldr r0, =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x15
	movs r2, 0
	bl GetMonData
	movs r2, 0xC
	negs r2, r2
	add r2, r10
	mov r9, r2
	movs r1, 0x58
	ldr r3, [sp, 0x14]
	adds r5, r3, 0
	muls r5, r1
	adds r7, r5, r2
	adds r1, r7, 0
	adds r1, 0x3B
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x20
	movs r2, 0
	bl GetMonData
	adds r1, r7, 0
	adds r1, 0x2B
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x19
	movs r2, 0
	bl GetMonData
	mov r1, r10
	adds r1, 0x38
	adds r1, r5, r1
	str r0, [r1]
	adds r0, r4, 0
	movs r1, 0x27
	movs r2, 0
	bl GetMonData
	movs r6, 0x1F
	ands r0, r6
	ldrb r2, [r7, 0x14]
	movs r1, 0x20
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x14]
	adds r0, r4, 0
	movs r1, 0x28
	movs r2, 0
	bl GetMonData
	movs r1, 0x1F
	mov r8, r1
	mov r2, r8
	ands r0, r2
	lsls r0, 5
	ldrh r2, [r7, 0x14]
	ldr r1, =0xfffffc1f
	ands r1, r2
	orrs r1, r0
	strh r1, [r7, 0x14]
	adds r0, r4, 0
	movs r1, 0x29
	movs r2, 0
	bl GetMonData
	ands r0, r6
	lsls r0, 2
	ldrb r2, [r7, 0x15]
	movs r1, 0x7D
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x15]
	adds r0, r4, 0
	movs r1, 0x2A
	movs r2, 0
	bl GetMonData
	movs r1, 0x1F
	ands r1, r0
	lsls r1, 15
	ldr r0, [r7, 0x14]
	ldr r2, =0xfff07fff
	ands r0, r2
	orrs r0, r1
	str r0, [r7, 0x14]
	adds r0, r4, 0
	movs r1, 0x2B
	movs r2, 0
	bl GetMonData
	mov r3, r8
	ands r0, r3
	lsls r0, 4
	ldrh r2, [r7, 0x16]
	ldr r1, =0xfffffe0f
	ands r1, r2
	orrs r1, r0
	strh r1, [r7, 0x16]
	adds r0, r4, 0
	movs r1, 0x2C
	movs r2, 0
	bl GetMonData
	ands r0, r6
	lsls r0, 1
	ldrb r2, [r7, 0x17]
	movs r1, 0x3F
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x17]
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0
	bl GetMonData
	mov r1, r10
	adds r1, 0x3C
	adds r1, r5, r1
	str r0, [r1]
	adds r0, r4, 0
	movs r1, 0x37
	movs r2, 0
	bl GetMonData
	mov r1, r10
	adds r1, 0x40
	adds r1, r5, r1
	str r0, [r1]
	adds r0, r4, 0
	movs r1, 0x38
	movs r2, 0
	bl GetMonData
	adds r1, r7, 0
	adds r1, 0x2A
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x39
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x28]
	adds r0, r4, 0
	movs r1, 0x3A
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x2C]
	adds r0, r4, 0
	movs r1, 0x3B
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x2]
	adds r0, r4, 0
	movs r1, 0x3C
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x4]
	adds r0, r4, 0
	movs r1, 0x3D
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x6]
	adds r0, r4, 0
	movs r1, 0x3E
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0x8]
	adds r0, r4, 0
	movs r1, 0x3F
	movs r2, 0
	bl GetMonData
	strh r0, [r7, 0xA]
	adds r0, r4, 0
	movs r1, 0x2D
	movs r2, 0
	bl GetMonData
	movs r1, 0x1
	ands r0, r1
	lsls r0, 6
	ldrb r2, [r7, 0x17]
	movs r1, 0x41
	negs r1, r1
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x17]
	adds r0, r4, 0
	movs r1, 0x2E
	movs r2, 0
	bl GetMonData
	lsls r0, 7
	ldrb r2, [r7, 0x17]
	movs r1, 0x7F
	ands r1, r2
	orrs r1, r0
	strb r1, [r7, 0x17]
	adds r0, r4, 0
	movs r1, 0x1
	movs r2, 0
	bl GetMonData
	mov r1, r10
	adds r1, 0x48
	adds r1, r5, r1
	str r0, [r1]
	ldr r2, =gBaseStats
	ldrh r1, [r7]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x6]
	adds r1, r7, 0
	adds r1, 0x21
	strb r0, [r1]
	ldrh r1, [r7]
	lsls r0, r1, 3
	subs r0, r1
	lsls r0, 2
	adds r0, r2
	ldrb r0, [r0, 0x7]
	adds r1, r7, 0
	adds r1, 0x22
	strb r0, [r1]
	ldrh r0, [r7]
	ldrb r1, [r7, 0x17]
	lsrs r1, 7
	bl GetAbilityBySpecies
	adds r1, r7, 0
	adds r1, 0x20
	strb r0, [r1]
	adds r0, r4, 0
	movs r1, 0x2
	mov r2, sp
	bl GetMonData
	mov r0, r10
	adds r0, 0x24
	adds r0, r5, r0
	mov r1, sp
	bl StringCopy10
	mov r2, r10
	adds r2, 0x30
	adds r2, r5, r2
	adds r0, r4, 0
	movs r1, 0x7
	bl GetMonData
	ldr r0, [sp, 0x14]
	bl GetBankSide
	ldr r1, =gBattleStruct
	lsls r0, 24
	lsrs r0, 23
	adds r0, 0xA8
	ldr r1, [r1]
	adds r1, r0
	ldrh r0, [r7, 0x28]
	strh r0, [r1]
	movs r2, 0x6
	mov r1, r9
	movs r6, 0x7
	add r5, r10
	adds r0, r5, 0
	adds r0, 0x13
_0806BCB2:
	strb r2, [r0]
	subs r0, 0x1
	subs r6, 0x1
	cmp r6, 0
	bge _0806BCB2
	movs r2, 0
	movs r0, 0x58
	ldr r3, [sp, 0x14]
	muls r0, r3
	adds r1, 0x50
	adds r0, r1
	str r2, [r0]
	ldr r0, [sp, 0x14]
	bl sub_803FA70
	ldr r0, [sp, 0x14]
	movs r1, 0
	bl sub_805EF84
	add sp, 0x18
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CopyPlayerPartyMonToBattleData

	.align 2, 0 @ Don't pad with nop.
