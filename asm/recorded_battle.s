	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text





	thumb_func_start GetAiScriptsInRecordedBattle
GetAiScriptsInRecordedBattle: @ 8186438
	ldr r0, =sRecordedBattle_AI_Scripts
	ldr r0, [r0]
	bx lr
	.pool
	thumb_func_end GetAiScriptsInRecordedBattle

	thumb_func_start sub_8186444
sub_8186444: @ 8186444
	ldr r1, =gUnknown_0203CCD0
	movs r0, 0x1
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end sub_8186444

	thumb_func_start sub_8186450
sub_8186450: @ 8186450
	push {lr}
	movs r1, 0
	ldr r0, =gUnknown_0203CCD0
	ldrb r0, [r0]
	cmp r0, 0
	bne _0818645E
	movs r1, 0x1
_0818645E:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_8186450

	thumb_func_start sub_8186468
sub_8186468: @ 8186468
	push {r4,r5,lr}
	adds r3, r0, 0
	movs r2, 0
	ldr r5, =gUnknown_03001278
	ldr r4, =gUnknown_0203CCD1
_08186472:
	adds r0, r3, r2
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, 0x1
	cmp r2, 0x7
	ble _08186472
	movs r0, 0xFF
	strb r0, [r3, 0x7]
	ldrb r1, [r5]
	adds r0, r3, 0
	bl ConvertInternationalString
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_8186468

	thumb_func_start sub_818649C
sub_818649C: @ 818649C
	ldr r0, =gUnknown_0203CCD9
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_818649C

	thumb_func_start sub_81864A8
sub_81864A8: @ 81864A8
	ldr r0, =gUnknown_0203CCDA
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81864A8

	thumb_func_start sub_81864B4
sub_81864B4: @ 81864B4
	ldr r0, =gUnknown_03001278
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81864B4

	thumb_func_start sub_81864C0
sub_81864C0: @ 81864C0
	ldr r0, =gUnknown_03001279
	ldrb r0, [r0]
	bx lr
	.pool
	thumb_func_end sub_81864C0

	thumb_func_start sub_81864CC
sub_81864CC: @ 81864CC
	ldr r0, =gUnknown_0203CCE8
	ldr r1, =gBattleOutcome
	ldrb r1, [r1]
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_81864CC

	thumb_func_start sub_81864E0
sub_81864E0: @ 81864E0
	ldr r0, =gUnknown_0203CCDC
	bx lr
	.pool
	thumb_func_end sub_81864E0

	.align 2, 0 @ Don't pad with nop.
