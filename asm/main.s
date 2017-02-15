	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start StartFlashMemoryTimer
@ void StartFlashMemoryTimer()
StartFlashMemoryTimer: @ 8000800
	push {lr}
	ldr r1, =gIntrTable + 0x1C
	movs r0, 0x2
	bl SetFlashTimerIntr
	pop {r0}
	bx r0
	.pool
	thumb_func_end StartFlashMemoryTimer

	thumb_func_start HBlankIntr
@ void HBlankIntr()
HBlankIntr: @ 8000814
	push {r4,lr}
	ldr r4, =gMain
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _08000822
	bl _call_via_r0
_08000822:
	ldr r2, =gIntrCheck
	ldrh r0, [r2]
	movs r1, 0x2
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1C]
	orrs r1, r0
	strh r1, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end HBlankIntr

	thumb_func_start VCountIntr
@ void VCountIntr()
VCountIntr: @ 8000844
	push {r4,lr}
	ldr r4, =gMain
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _08000852
	bl _call_via_r0
_08000852:
	bl m4aSoundVSync
	ldr r2, =gIntrCheck
	ldrh r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1C]
	orrs r1, r0
	strh r1, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end VCountIntr

	thumb_func_start SerialIntr
@ void SerialIntr()
SerialIntr: @ 8000878
	push {r4,lr}
	ldr r4, =gMain
	ldr r0, [r4, 0x18]
	cmp r0, 0
	beq _08000886
	bl _call_via_r0
_08000886:
	ldr r2, =gIntrCheck
	ldrh r0, [r2]
	movs r1, 0x80
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r4, 0x1C]
	ldrh r2, [r4, 0x1C]
	orrs r1, r0
	strh r1, [r4, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SerialIntr

	thumb_func_start IntrDummy
@ void IntrDummy()
IntrDummy: @ 80008A8
	bx lr
	thumb_func_end IntrDummy

	thumb_func_start WaitForVBlank
@ void WaitForVBlankIntr()
WaitForVBlank: @ 80008AC
	push {lr}
	ldr r2, =gMain
	ldrh r1, [r2, 0x1C]
	ldr r0, =0x0000fffe
	ands r0, r1
	ldrh r1, [r2, 0x1C]
	strh r0, [r2, 0x1C]
	ldrh r1, [r2, 0x1C]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080008D0
	movs r3, 0x1
_080008C6:
	ldrh r1, [r2, 0x1C]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080008C6
_080008D0:
	pop {r0}
	bx r0
	.pool
	thumb_func_end WaitForVBlank

	thumb_func_start sub_80008DC
sub_80008DC: @ 80008DC
	ldr r1, =gUnknown_0203CF5C
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80008DC

	thumb_func_start sub_80008E8
sub_80008E8: @ 80008E8
	ldr r1, =gUnknown_0203CF5C
	movs r0, 0
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_80008E8

	thumb_func_start DoSoftReset
@ void Reset()
DoSoftReset: @ 80008F4
	push {r4,lr}
	ldr r1, =0x04000208
	movs r0, 0
	strh r0, [r1]
	bl m4aSoundVSyncOff
	bl remove_some_task
	ldr r1, =0x040000bc
	ldrh r2, [r1, 0xA]
	ldr r3, =0x0000c5ff
	adds r0, r3, 0
	ands r0, r2
	strh r0, [r1, 0xA]
	ldrh r4, [r1, 0xA]
	ldr r2, =0x00007fff
	adds r0, r2, 0
	ands r0, r4
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	adds r1, 0xC
	ldrh r4, [r1, 0xA]
	adds r0, r3, 0
	ands r0, r4
	strh r0, [r1, 0xA]
	ldrh r4, [r1, 0xA]
	adds r0, r2, 0
	ands r0, r4
	strh r0, [r1, 0xA]
	ldrh r0, [r1, 0xA]
	ldr r0, =0x040000d4
	ldrh r1, [r0, 0xA]
	ands r3, r1
	strh r3, [r0, 0xA]
	ldrh r1, [r0, 0xA]
	ands r2, r1
	strh r2, [r0, 0xA]
	ldrh r0, [r0, 0xA]
	bl SiiRtcProtect
	movs r0, 0xFF
	bl SoftReset
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end DoSoftReset

	thumb_func_start ClearPokemonCrySongs
ClearPokemonCrySongs: @ 8000964
	push {lr}
	sub sp, 0x4
	mov r1, sp
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gPokemonCrySongs
	ldr r2, =0x01000034
	mov r0, sp
	bl CpuSet
	add sp, 0x4
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearPokemonCrySongs

	.align 2, 0 @ Don't pad with nop.
