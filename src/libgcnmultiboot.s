@ This library can be used to download and execute a multi-boot image from
@ a GameCube using the JOY Bus protocol over the link cable.

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.equiv GCMB_STRUCT_BASE_DEST_PTR,       0x20
	.equiv GCMB_STRUCT_CUR_DEST_PTR,        0x24
	.equiv GCMB_STRUCT_SERIAL_INTR_HANDLER, 0x28

	.equiv ROM_HEADER_NINTENDO_LOGO_OFFSET, 0x4

	.syntax unified

	.text

	thumb_func_start GameCubeMultiBoot_Hash
GameCubeMultiBoot_Hash: @ 82DED70
	push {r4,lr}
	ldr r4, pool_HashVal
	eors r3, r1
	movs r2, 0x20

GameCubeMultiBoot_Hash_Loop:
	lsrs r3, #1
	bcc GameCubeMultiBoot_Hash_SkipEor

	eors r3, r4

GameCubeMultiBoot_Hash_SkipEor:
	subs r2, 0x1
	bne GameCubeMultiBoot_Hash_Loop

	pop {r4,pc}
	thumb_func_end GameCubeMultiBoot_Hash

	thumb_func_start GameCubeMultiBoot_Main
@ void GameCubeMultiBoot_Main(struct GameCubeMultiBoot *mb);
GameCubeMultiBoot_Main: @ 82DED84
	ldr r1, [r0, #GCMB_STRUCT_SERIAL_INTR_HANDLER]
	cmp r1, #0
	beq _082DEDAA
	ldrb r1, [r0, 0x1]
	adds r1, 0x1
	strb r1, [r0, 0x1]
	ldrb r1, [r0, 0x2]
	cmp r1, 0x2
	beq _082DEDF4
	ldr r3, pool_InterruptRegs
	ldrh r2, [r3, #OFFSET_REG_IME - 0x200]
	movs r1, 0
	strh r1, [r3, #OFFSET_REG_IME - 0x200]
	ldrb r1, [r0]
	cmp r1, 0xA
	bgt _082DEDA8
	adds r1, 0x1
	strb r1, [r0]
_082DEDA8:
	strh r2, [r3, #OFFSET_REG_IME - 0x200]
_082DEDAA:
	bcs GameCubeMultiBoot_Init
	ldrb r1, [r0, 0x2]
	cmp r1, 0
	bne _082DEDF6
	ldr r1, [r0, #GCMB_STRUCT_CUR_DEST_PTR]
	ldr r2, [r0, #GCMB_STRUCT_BASE_DEST_PTR]
	subs r1, r2
	beq _082DEE76
	cmp r1, 0xA0
	bcc _082DEE76
	push {r4-r6}
	movs r1, 0x98
	adds r2, #ROM_HEADER_NINTENDO_LOGO_OFFSET
	ldr r4, pool_NintendoLogo
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
	lsrs r5, #8
	str r2, [r0, #GCMB_STRUCT_BASE_DEST_PTR]
_082DEDDC:
	pop {r4-r6}
	bne GameCubeMultiBoot_Init
	movs r1, 0x1
	strb r1, [r0, 0x2]
	ldr r1, [r0, 0x4]
	ldr r2, [r0, 0x8]
	eors r1, r2
	str r1, [r0, 0x18]
	ldr r2, pool_Kawa
	muls r1, r2
	adds r1, 0x1
	str r1, [r0, 0x14]
_082DEDF4:
	bx lr
_082DEDF6:
	ldr r1, [r0, #GCMB_STRUCT_CUR_DEST_PTR]
	mov r12, r1
	ldr r3, [r0, 0x18]
	push {r4-r7}
	ldr r4, [r0, #GCMB_STRUCT_BASE_DEST_PTR]
	ldr r5, pool_Kawa
	ldr r6, [r0, 0x14]
	ldr r7, pool_HashVal
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
	lsrs r3, #1
	bcc _082DEE1C
	eors r3, r7
_082DEE1C:
	subs r2, 0x1
	bne _082DEE16
	muls r6, r5
	adds r6, 0x1
	b _082DEE06
_082DEE26:
	str r4, [r0, #GCMB_STRUCT_BASE_DEST_PTR]
	str r6, [r0, 0x14]
	pop {r4-r7}
	str r3, [r0, 0x18]
	ldrh r1, [r0, 0x12]
	cmp r1, #0
	bne _082DEE76
	ldr r1, [r0, #GCMB_STRUCT_CUR_DEST_PTR]
	ldr r2, [r0, #GCMB_STRUCT_BASE_DEST_PTR]
	cmp r1, r2
	bne _082DEE76
	ldr r1, [r0, 0xC]
	cmp r1, #0
	beq _082DEE60
	ldrh r1, [r0, 0x10]
	cmp r1, #0
	beq _082DEDF4
	mov r12, lr
	movs r1, 0xBB
	ldr r3, [r0, 0xC]
	bl GameCubeMultiBoot_Hash
	ldrh r1, [r0, 0x10]
	mov lr, r12
	subs r1, r3
	bne GameCubeMultiBoot_Init
	movs r1, 0x2
	strb r1, [r0, 0x2]
	bx lr
_082DEE60:
	mov r12, lr
	ldrb r1, [r0, 0x3]
	lsls r1, #24
	subs r1, 0x1
	str r1, [r0, 0xC]
	bl GameCubeMultiBoot_Hash
	lsls r3, #8
	adds r3, 0xFF
	str r3, [r0, 0x1C]
	bx r12
_082DEE76:
	bx lr
	thumb_func_end GameCubeMultiBoot_Main

	.align 2, 0

pool_HashVal: .4byte 0xa1c1

pool_Kawa: .ascii "Kawa" @ name of BIOS developer

pool_NintendoLogo: .4byte RomHeaderNintendoLogo

	thumb_func_start GameCubeMultiBoot_ExecuteProgram
@ void GameCubeMultiBoot_ExecuteProgram(struct GameCubeMultiBoot *mb);
GameCubeMultiBoot_ExecuteProgram: @ 82DEE84
	ldrb r1, [r0, 0x2]
	cmp r1, 0x2
	bne GameCubeMultiBoot_ExecuteProgram_Fail
	ldr r3, pool_InterruptRegs
	movs r1, #0
	strh r1, [r3, #OFFSET_REG_IME - 0x200]
	ldr r1, pool_MultiBootLoadAddr
	adds r1, 0xC0
	bx r1
GameCubeMultiBoot_ExecuteProgram_Fail:
	bx lr
	thumb_func_end GameCubeMultiBoot_ExecuteProgram

	thumb_func_start GameCubeMultiBoot_Init
@ void GameCubeMultiBoot_Init(struct GameCubeMultiBoot *mb);
GameCubeMultiBoot_Init: @ 82DEE98
	ldr r3, pool_InterruptRegs

@ Save IME register.
	ldrh r2, [r3, #OFFSET_REG_IME - 0x200]

@ Disable interrupts.
	movs r1, 0
	strh r1, [r3, #OFFSET_REG_IME - 0x200]

@ Set the handler to the "Stop" routine.
@ Unless the first command that is received is a device reset command, the
@ "Stop" routine will be executed and no further commands will be processed.
	adr r3, GcMbIntrHandler_Stop
	str r3, [r0, #GCMB_STRUCT_SERIAL_INTR_HANDLER]

	ldrb r3, [r0, 0x3]
	push {r3}
	ldrb r3, [r0, 0x1]
	push {r0,r3}

	adds r3, r0, #0
	adds r3, #GCMB_STRUCT_BASE_DEST_PTR

@ clear all but the last 3 fields of the struct
GameCubeMultiBoot_Init_ClearStructLoop:
	stm r0!, {r1}
	cmp r0, r3
	blo GameCubeMultiBoot_Init_ClearStructLoop

	pop {r0,r3}
	lsrs r3, 1
	strb r3, [r0, 0x3]
	pop {r3}
	strb r3, [r0, 0x1]

	ldr r3, pool_SerialRegs

@ Turn off JOY Bus mode.
	lsls r0, r3, 10
	strh r0, [r3, OFFSET_REG_RCNT - 0x120]

@ Turn on JOY Bus mode.
	movs r0, 0xC0
	lsls r0, 8
	strh r0, [r3, OFFSET_REG_RCNT - 0x120]

@ Init JOY Bus registers.
	movs r0, 0x47
	strh r0, [r3, OFFSET_REG_JOYCNT - 0x120]
	strh r1, [r3, OFFSET_REG_JOYSTAT - 0x120]

	ldr r3, pool_InterruptRegs

@ Acknowledge serial interrupt.
	movs r0, INTR_FLAG_SERIAL
	strh r0, [r3, OFFSET_REG_IF - 0x200]

@ Enable serial interrupt.
	ldrh r1, [r3, OFFSET_REG_IE - 0x200]
	orrs r1, r0
	strh r1, [r3, OFFSET_REG_IE - 0x200]

@ Restore IME register.
	strh r2, [r3, #OFFSET_REG_IME - 0x200]

	bx lr
	thumb_func_end GameCubeMultiBoot_Init

	non_word_aligned_thumb_func_start GameCubeMultiBoot_HandleSerialInterrupt
@ void GameCubeMultiBoot_HandleSerialInterrupt(struct GameCubeMultiBoot *mb);
GameCubeMultiBoot_HandleSerialInterrupt: @ 82DEEE2
	ldr r3, pool_SerialRegs

@ Acknowledge reset/receive/send flags.
	ldrh r1, [r3, OFFSET_REG_JOYCNT - 0x120]
	strh r1, [r3, OFFSET_REG_JOYCNT - 0x120]

	movs r2, #0
	strb r2, [r0]

	ldr r2, [r0, #GCMB_STRUCT_SERIAL_INTR_HANDLER]
	cmp r2, #0
	beq GameCubeMultiBoot_HandleSerialInterruptDone

	lsrs r1, 1 @ was a device reset command received?
	bcs GameCubeMultiBoot_BeginHandshake @ branch if so

	mov pc, r2

	.align 2, 0

@ Zero the status and the interrupt handler pointer.
@ Commands from the GameCube will not be processed after this is executed
@ unless GameCubeMultiBoot_Init() is called again.
GcMbIntrHandler_Stop:
	movs r2, 0
	strh r2, [r3, OFFSET_REG_JOYSTAT - 0x120]

GameCubeMultiBoot_SetInterruptHandler:
	str r2, [r0, #GCMB_STRUCT_SERIAL_INTR_HANDLER]

GameCubeMultiBoot_ReadVCount:
	ldr r3, pool_RegDispstat
	ldrh r1, [r3, OFFSET_REG_VCOUNT - OFFSET_REG_DISPSTAT]
	strb r1, [r0, 0x3]

GameCubeMultiBoot_HandleSerialInterruptDone:
	bx lr

GameCubeMultiBoot_BeginHandshake:
	ldr r1, [r3, OFFSET_REG_JOY_RECV - 0x120]
	ldr r1, pool_RubyUSAGameCode
	str r1, [r3, OFFSET_REG_JOY_TRANS - 0x120]
	movs r1, 0x10
	strh r1, [r3, OFFSET_REG_JOYSTAT - 0x120]
	ldrb r1, [r0, 0x3]
	strb r1, [r0, 0x9]
	ldrb r1, [r0, 0x2]
	cmp r1, 0
	bne GcMbIntrHandler_Stop
	ldr r1, pool_MultiBootLoadAddr
	str r1, [r0, #GCMB_STRUCT_BASE_DEST_PTR]
	str r1, [r0, #GCMB_STRUCT_CUR_DEST_PTR]
	adr r2, GcMbIntrHandler_CheckGameCodeSent
	b GameCubeMultiBoot_SetInterruptHandler

	.align 2, 0

GcMbIntrHandler_CheckGameCodeSent: @ 82DEF24
	lsls r1, 31
	bcc GcMbIntrHandler_Stop @ stop if send failed
	bmi GameCubeMultiBoot_CheckHandshakeResponse @ branch if receive is complete

@ If the response hasn't been fully received yet,
@ check again upon the next interrupt.
	adr r2, GcMbIntrHandler_CheckHandshakeResponse
	b GameCubeMultiBoot_SetInterruptHandler

	.align 2, 0

GcMbIntrHandler_CheckHandshakeResponse: @ 82DEF30
	lsrs r1, 1 @ is receive complete?
	bcc GcMbIntrHandler_Stop @ stop if not

GameCubeMultiBoot_CheckHandshakeResponse:
	ldr r1, [r3, OFFSET_REG_JOY_RECV - 0x120]
	ldr r2, pool_RubyUSAGameCode
	cmp r1, r2
	bne GcMbIntrHandler_Stop @ stop if the GameCube didn't reply with the same game code
	ldrb r1, [r0, 0x3]
	strb r1, [r0, 0xB]
	adr r2, GcMbIntrHandler_82DEF44
	b GameCubeMultiBoot_SetInterruptHandler

	.align 2, 0

GcMbIntrHandler_82DEF44: @ 82DEF44
	lsrs r1, 1 @ is receive complete?
	bcc GcMbIntrHandler_Stop @ branch if not
	ldr r1, [r3, OFFSET_REG_JOY_RECV - 0x120]
	lsrs r2, r1, 24
	cmp r2, 0xDD
	bne GcMbIntrHandler_Stop
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
	ldr r3, pool_SerialRegs
	str r1, [r3, OFFSET_REG_JOY_TRANS - 0x120]
	movs r1, 0x30
	strh r1, [r3, OFFSET_REG_JOYSTAT - 0x120]
	adr r2, GcMbIntrHandler_82DEF84
	b GameCubeMultiBoot_SetInterruptHandler

	.align 2, 0

GcMbIntrHandler_82DEF84: @ 82DEF84
	lsls r1, 31
	bcc GcMbIntrHandler_Stop @ stop if send failed
	bmi _082DEF94 @ branch if receive is complete
	adr r2, GcMbIntrHandler_82DEF90
	b GameCubeMultiBoot_SetInterruptHandler

	.align 2, 0

GcMbIntrHandler_82DEF90: @ 82DEF90
	lsrs r1, 1 @ is receive complete?
	bcc GcMbIntrHandler_Stop @ branch if not
_082DEF94:
	ldr r1, [r3, OFFSET_REG_JOY_RECV - 0x120]
	ldr r2, _082DF034
	cmp r1, r2
	bhs GcMbIntrHandler_Stop
	adds r1, 0x1
	adds r1, r1
	strh r1, [r0, 0x12]
	ldrb r1, [r0, 0x2]
	cmp r1, 0
_082DEFA6:
	bne GcMbIntrHandler_Stop
	ldr r1, pool_MultiBootLoadAddr
	str r1, [r0, #GCMB_STRUCT_BASE_DEST_PTR]
	str r1, [r0, #GCMB_STRUCT_CUR_DEST_PTR]
	adr r2, GcMbIntrHandler_82DEFB4
	b GameCubeMultiBoot_SetInterruptHandler

	.align 2, 0

GcMbIntrHandler_82DEFB4: @ 82DEFB4
	lsrs r1, 1 @ is receive complete?
	bcc GcMbIntrHandler_Stop @ branch if not
	ldr r2, [r0, #GCMB_STRUCT_CUR_DEST_PTR]
	movs r1, 0x4
	ands r1, r2
	adds r1, 0x8
	lsls r1, 2
	strh r1, [r3, OFFSET_REG_JOYSTAT - 0x120]
	ldr r1, [r3, OFFSET_REG_JOY_RECV - 0x120]
	stm r2!, {r1}
	str r2, [r0, #GCMB_STRUCT_CUR_DEST_PTR]
	ldrh r1, [r0, 0x12]
	subs r1, 0x1
	strh r1, [r0, 0x12]
	bne GameCubeMultiBoot_ReadVCount

_082DEFD2:
	ldrb r1, [r0, 0x1]
	lsls r1, 8
	adds r1, 0xCC
	str r1, [r3, OFFSET_REG_JOY_TRANS - 0x120]
	adr r2, _082DEFE0
	b GameCubeMultiBoot_SetInterruptHandler

	.align 2, 0

_082DEFE0:
	lsls r1, 31

_082DEFE2:
	bcc GcMbIntrHandler_Stop
	ldr r1, [r0, 0x1C]
	cmp r1, 0
	beq _082DEFD2
	str r1, [r3, OFFSET_REG_JOY_TRANS - 0x120]
	adr r2, GcMbIntrHandler_82DEFF0
	b GameCubeMultiBoot_SetInterruptHandler

	.align 2, 0

GcMbIntrHandler_82DEFF0: @ 82DEFF0
	lsls r1, 31
	bcc _082DEFE2 @ branch if send failed
	bmi _082DF000 @ branch if receive is complete
	adr r2, GcMbIntrHandler_82DEFFC
	b GameCubeMultiBoot_SetInterruptHandler

	.align 2, 0

GcMbIntrHandler_82DEFFC: @ 82DEFFC
	lsrs r1, 1 @ is receive complete?
	bcc _082DEFE2 @ branch if not

_082DF000:
	ldr r1, [r3, OFFSET_REG_JOY_RECV - 0x120]
	lsrs r2, r1, 24
	cmp r2, 0xBB
	bne _082DEFA6
	strh r1, [r0, 0x10]
	adr r2, GcMbIntrHandler_82DF010
	b GameCubeMultiBoot_SetInterruptHandler

	.align 2, 0

GcMbIntrHandler_82DF010: @ 82DF010
	b GcMbIntrHandler_Stop

	thumb_func_end GameCubeMultiBoot_HandleSerialInterrupt

	non_word_aligned_thumb_func_start GameCubeMultiBoot_Quit
@ void GameCubeMultiBoot_Quit();
GameCubeMultiBoot_Quit: @ 82DF012
	ldr r3, pool_InterruptRegs

@ Save IME register.
	ldrh r2, [r3, #OFFSET_REG_IME - 0x200]

@ Disable interrupts.
	movs r1, 0
	strh r1, [r3, #OFFSET_REG_IME - 0x200]

	ldr r3, pool_SerialRegs

@ Acknowledge all JOYCNT flags.
	movs r0, 0x7
	strh r0, [r3, OFFSET_REG_JOYCNT - 0x120]

@ Turn off JOY Bus mode.
	lsls r0, r3, 10
	strh r0, [r3, OFFSET_REG_RCNT - 0x120] @ store 0x8000

	ldr r3, pool_InterruptRegs

@ Acknowledge serial interrupt.
	movs r0, INTR_FLAG_SERIAL
	strh r0, [r3, OFFSET_REG_IF - 0x200]

@ Disable serial interrupt.
	ldrh r1, [r3, OFFSET_REG_IE - 0x200]
	bics r1, r0
	strh r1, [r3, OFFSET_REG_IE - 0x200]

@ Restore IME register.
	strh r2, [r3, #OFFSET_REG_IME - 0x200]

	bx lr
	thumb_func_end GameCubeMultiBoot_Quit

	.align 2, 0

_082DF034: .4byte 0x4000

pool_InterruptRegs: .4byte REG_BASE + 0x200

pool_SerialRegs: .4byte REG_BASE + 0x120

pool_RegDispstat: .4byte REG_DISPSTAT

pool_RubyUSAGameCode: .ascii "AXVE"

pool_MultiBootLoadAddr: .4byte EWRAM_START

	.align 2, 0 @ Don't pad with nop.
