	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start Main
Main: @ 80003A4
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r0, 0xFF
	bl RegisterRamReset
	movs r1, 0xA0
	lsls r1, 19
	ldr r2, =0x00007fff
	adds r0, r2, 0
	strh r0, [r1]
	bl InitGpuRegManager
	ldr r1, =0x04000204
	ldr r3, =0x00004014
	adds r0, r3, 0
	strh r0, [r1]
	bl InitKeypadData
	bl InitIntrHandlers
	bl m4aSoundInit
	bl EnableVCountIntrAtLine150
	bl sub_800E6D0
	bl GameFreakRTC_Init
	bl CheckForFlashMemory
	bl InitVariablesAndSetCopyrightScreenCallback
	bl sound_sources_off
	bl ClearDma3Requests
	bl ResetBgs
	bl SetDefaultFontsPointer
	ldr r0, =0x02000000
	movs r1, 0xE0
	lsls r1, 9
	bl InitHeap
	ldr r0, =gUnknown_03002700
	movs r4, 0
	strb r4, [r0]
	ldr r0, =gUnknown_03005D88
	ldr r0, [r0]
	cmp r0, 0x1
	beq _08000414
	movs r0, 0
	bl SetMainCallback2
_08000414:
	ldr r2, =gUnknown_030022B4
	strb r4, [r2]
	ldr r1, =gUnknown_03000000
	movs r3, 0xFC
	lsls r3, 4
	adds r0, r3, 0
	strh r0, [r1]
	ldr r7, =gUnknown_030022C0
	movs r0, 0
	mov r8, r0
	adds r6, r2, 0
_0800042A:
	bl ReadKeypad
	ldr r0, =gUnknown_03002700
	ldrb r0, [r0]
	cmp r0, 0
	bne _08000454
	ldrh r1, [r7, 0x28]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _08000454
	movs r0, 0xE
	ands r0, r1
	cmp r0, 0xE
	bne _08000454
	bl rfu_REQ_stopMode
	bl rfu_waitREQComplete
	bl Reset
_08000454:
	bl sub_8087634
	cmp r0, 0x1
	bne _0800048C
	strb r0, [r6]
	bl HandleLinkConnectionAndCallMainCallbacks
	movs r0, 0
	strb r0, [r6]
	b _080004B2
	.pool
_0800048C:
	ldr r5, =gUnknown_030022B4
	movs r0, 0
	strb r0, [r5]
	bl HandleLinkConnectionAndCallMainCallbacks
	bl sub_80875C8
	adds r4, r0, 0
	cmp r4, 0x1
	bne _080004B2
	movs r0, 0
	strh r0, [r7, 0x2E]
	bl ClearObjectCopyRequests
	strb r4, [r5]
	bl HandleLinkConnectionAndCallMainCallbacks
	mov r2, r8
	strb r2, [r5]
_080004B2:
	bl gametime_increment
	bl sound_something
	bl WaitForVBlankIntr
	b _0800042A
	.pool
	thumb_func_end Main

	thumb_func_start HandleLinkConnectionAndCallMainCallbacks
@ void HandleLinkConnectionAndCallMainCallbacks()
HandleLinkConnectionAndCallMainCallbacks: @ 80004C4
	push {lr}
	bl HandleLinkConnection
	lsls r0, 24
	cmp r0, 0
	bne _080004D4
	bl CallMainCallbacks
_080004D4:
	pop {r0}
	bx r0
	thumb_func_end HandleLinkConnectionAndCallMainCallbacks

	thumb_func_start InitVariablesAndSetCopyrightScreenCallback
@ void InitVariablesAndSetCopyrightScreenCallback()
InitVariablesAndSetCopyrightScreenCallback: @ 80004D8
	push {lr}
	ldr r2, =gUnknown_030022C0
	movs r0, 0
	str r0, [r2, 0x20]
	ldr r1, =gUnknown_0203CF5C
	str r0, [r1]
	str r0, [r2, 0x24]
	str r0, [r2]
	ldr r0, =c2_copyright_1
	bl SetMainCallback2
	ldr r1, =gUnknown_03005D90
	ldr r0, =gUnknown_02024A54
	str r0, [r1]
	ldr r1, =gUnknown_03005D94
	ldr r0, =gUnknown_02029808
	str r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitVariablesAndSetCopyrightScreenCallback

	thumb_func_start CallMainCallbacks
@ void CallMainCallbacks()
CallMainCallbacks: @ 800051C
	push {r4,lr}
	ldr r4, =gUnknown_030022C0
	ldr r0, [r4]
	cmp r0, 0
	beq _0800052A
	bl _call_via_r0
_0800052A:
	ldr r0, [r4, 0x4]
	cmp r0, 0
	beq _08000534
	bl _call_via_r0
_08000534:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end CallMainCallbacks

	thumb_func_start SetMainCallback2
@ void SetMainCallback2(void ( *func)())
SetMainCallback2: @ 8000540
	ldr r1, =gUnknown_030022C0
	str r0, [r1, 0x4]
	movs r0, 0x87
	lsls r0, 3
	adds r1, r0
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end SetMainCallback2

	thumb_func_start StartTimer1
@ void StartTimer1()
StartTimer1: @ 8000554
	ldr r1, =0x04000106
	movs r0, 0x80
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end StartTimer1

	thumb_func_start SeedRngAndSetTrainerId
@ void SeedRngAndSetTrainerId()
SeedRngAndSetTrainerId: @ 8000560
	push {r4,lr}
	ldr r0, =0x04000104
	ldrh r4, [r0]
	adds r0, r4, 0
	bl SeedRng
	ldr r1, =0x04000106
	movs r0, 0
	strh r0, [r1]
	ldr r0, =gUnknown_02020000
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end SeedRngAndSetTrainerId

	thumb_func_start GetTrainerId
@ u16 GetTrainerId()
GetTrainerId: @ 8000588
	ldr r0, =gUnknown_02020000
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end GetTrainerId

	thumb_func_start EnableVCountIntrAtLine150
@ void EnableVCountIntrAtLine150()
EnableVCountIntrAtLine150: @ 8000594
	push {lr}
	movs r0, 0x4
	bl GetGpuReg
	movs r1, 0xFF
	ands r1, r0
	movs r2, 0x96
	lsls r2, 8
	adds r0, r2, 0
	orrs r1, r0
	movs r0, 0x20
	orrs r1, r0
	movs r0, 0x4
	bl SetGpuReg
	movs r0, 0x4
	bl EnableInterrupts
	pop {r0}
	bx r0
	thumb_func_end EnableVCountIntrAtLine150

	thumb_func_start InitKeypadData
@ void InitKeypadData()
InitKeypadData: @ 80005BC
	ldr r1, =gUnknown_030026FC
	movs r0, 0x5
	strh r0, [r1]
	ldr r1, =gUnknown_030022B0
	movs r0, 0x28
	strh r0, [r1]
	ldr r1, =gUnknown_030022C0
	movs r0, 0
	strh r0, [r1, 0x2C]
	strh r0, [r1, 0x2E]
	strh r0, [r1, 0x30]
	strh r0, [r1, 0x28]
	strh r0, [r1, 0x2A]
	bx lr
	.pool
	thumb_func_end InitKeypadData

	thumb_func_start ReadKeypad
@ void ReadKeypad()
ReadKeypad: @ 80005E4
	push {lr}
	ldr r0, =0x04000130
	ldrh r1, [r0]
	ldr r2, =0x000003ff
	adds r0, r2, 0
	adds r3, r0, 0
	eors r3, r1
	ldr r1, =gUnknown_030022C0
	ldrh r2, [r1, 0x28]
	adds r0, r3, 0
	bics r0, r2
	strh r0, [r1, 0x2A]
	strh r0, [r1, 0x2E]
	strh r0, [r1, 0x30]
	adds r2, r1, 0
	cmp r3, 0
	beq _08000630
	ldrh r0, [r2, 0x2C]
	cmp r0, r3
	bne _08000630
	ldrh r0, [r2, 0x32]
	subs r0, 0x1
	strh r0, [r2, 0x32]
	lsls r0, 16
	cmp r0, 0
	bne _08000636
	strh r3, [r2, 0x30]
	ldr r0, =gUnknown_030026FC
	b _08000632
	.pool
_08000630:
	ldr r0, =gUnknown_030022B0
_08000632:
	ldrh r0, [r0]
	strh r0, [r2, 0x32]
_08000636:
	strh r3, [r2, 0x28]
	strh r3, [r2, 0x2C]
	ldr r0, =gUnknown_03005D90
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	cmp r0, 0x2
	bne _08000668
	ldrh r1, [r2, 0x2E]
	movs r3, 0x80
	lsls r3, 2
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08000658
	movs r0, 0x1
	orrs r0, r1
	strh r0, [r2, 0x2E]
_08000658:
	ldrh r1, [r2, 0x2C]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _08000668
	movs r0, 0x1
	orrs r0, r1
	strh r0, [r2, 0x2C]
_08000668:
	ldrh r1, [r2, 0x2E]
	ldrh r0, [r2, 0x36]
	ands r0, r1
	cmp r0, 0
	beq _08000676
	movs r0, 0x1
	strh r0, [r2, 0x34]
_08000676:
	pop {r0}
	bx r0
	.pool
	thumb_func_end ReadKeypad

	thumb_func_start InitIntrHandlers
@ void InitIntrHandlers()
InitIntrHandlers: @ 8000684
	push {r4,r5,lr}
	ldr r5, =InterruptMain
	ldr r4, =gUnknown_03002750
	ldr r3, =gRomInterruptTable
	ldr r2, =gUnknown_03002710
	movs r1, 0xD
_08000690:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, 0x1
	cmp r1, 0
	bge _08000690
	ldr r0, =0x040000d4
	str r5, [r0]
	str r4, [r0, 0x4]
	ldr r1, =0x84000200
	str r1, [r0, 0x8]
	ldr r0, [r0, 0x8]
	ldr r0, =gUnknown_03007FFC
	str r4, [r0]
	movs r0, 0
	bl SetVBlankCallback
	movs r0, 0
	bl SetHBlankCallback
	movs r0, 0
	bl SetSerialCallback
	ldr r1, =0x04000208
	movs r0, 0x1
	strh r0, [r1]
	movs r0, 0x1
	bl EnableInterrupts
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitIntrHandlers

	thumb_func_start SetVBlankCallback
@ void SetVBlankCallback(void ( *func)())
SetVBlankCallback: @ 80006F0
	ldr r1, =gUnknown_030022C0
	str r0, [r1, 0xC]
	bx lr
	.pool
	thumb_func_end SetVBlankCallback

	thumb_func_start SetHBlankCallback
@ void SetHBlankCallback(void ( *func)())
SetHBlankCallback: @ 80006FC
	ldr r1, =gUnknown_030022C0
	str r0, [r1, 0x10]
	bx lr
	.pool
	thumb_func_end SetHBlankCallback

	thumb_func_start SetVCountCallback
@ void SetVCountCallback(void ( *func)())
SetVCountCallback: @ 8000708
	ldr r1, =gUnknown_030022C0
	str r0, [r1, 0x14]
	bx lr
	.pool
	thumb_func_end SetVCountCallback

	thumb_func_start RestoreSerialTimer3IntrHandlers
@ void RestoreSerialTimer3IntrHandlers()
RestoreSerialTimer3IntrHandlers: @ 8000714
	ldr r0, =gUnknown_03002710
	ldr r1, =SerialIntr
	str r1, [r0, 0x4]
	ldr r1, =Timer3Intr
	str r1, [r0, 0x8]
	bx lr
	.pool
	thumb_func_end RestoreSerialTimer3IntrHandlers

	thumb_func_start SetSerialCallback
@ void SetSerialCallback(void ( *func)())
SetSerialCallback: @ 800072C
	ldr r1, =gUnknown_030022C0
	str r0, [r1, 0x18]
	bx lr
	.pool
	thumb_func_end SetSerialCallback

	thumb_func_start VBlankIntr
@ void VBlankIntr()
VBlankIntr: @ 8000738
	push {r4,lr}
	ldr r0, =gUnknown_030030FC
	ldrb r0, [r0]
	cmp r0, 0
	beq _0800074C
	bl rfu_syncVBlank__
	b _08000758
	.pool
_0800074C:
	ldr r0, =gUnknown_03002748
	ldrb r0, [r0]
	cmp r0, 0
	bne _08000758
	bl sub_800B9B8
_08000758:
	ldr r0, =gUnknown_030022C0
	ldr r1, [r0, 0x20]
	adds r1, 0x1
	str r1, [r0, 0x20]
	ldr r1, =gUnknown_0203CF5C
	ldr r1, [r1]
	adds r4, r0, 0
	cmp r1, 0
	beq _08000778
	ldr r2, [r1]
	movs r0, 0x2
	negs r0, r0
	cmp r2, r0
	bhi _08000778
	adds r0, r2, 0x1
	str r0, [r1]
_08000778:
	ldr r0, [r4, 0xC]
	cmp r0, 0
	beq _08000782
	bl _call_via_r0
_08000782:
	ldr r0, [r4, 0x24]
	adds r0, 0x1
	str r0, [r4, 0x24]
	bl CopyBufferedValuesToGpuRegs
	bl ProcessDma3Requests
	ldr r1, =gUnknown_03002F50
	ldr r0, =gSoundInfo
	ldrb r0, [r0, 0x4]
	strb r0, [r1]
	bl m4aSoundMain
	bl sub_8033648
	ldr r1, =0x00000439
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _080007BA
	ldr r0, =gUnknown_02022FEC
	ldr r0, [r0]
	ldr r1, =0x013f0102
	ands r0, r1
	cmp r0, 0
	bne _080007BE
_080007BA:
	bl GenerateRandomNumber
_080007BE:
	bl sub_800E174
	ldr r2, =gUnknown_03007FF8
	ldrh r0, [r2]
	movs r1, 0x1
	orrs r0, r1
	strh r0, [r2]
	ldr r0, =gUnknown_030022C0
	ldrh r2, [r0, 0x1C]
	ldrh r3, [r0, 0x1C]
	orrs r1, r2
	strh r1, [r0, 0x1C]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end VBlankIntr

	thumb_func_start StartFlashMemoryTimer
@ void StartFlashMemoryTimer()
StartFlashMemoryTimer: @ 8000800
	push {lr}
	ldr r1, =gUnknown_0300272C
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
	ldr r4, =gUnknown_030022C0
	ldr r0, [r4, 0x10]
	cmp r0, 0
	beq _08000822
	bl _call_via_r0
_08000822:
	ldr r2, =gUnknown_03007FF8
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
	ldr r4, =gUnknown_030022C0
	ldr r0, [r4, 0x14]
	cmp r0, 0
	beq _08000852
	bl _call_via_r0
_08000852:
	bl m4aSoundVSync
	ldr r2, =gUnknown_03007FF8
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
	ldr r4, =gUnknown_030022C0
	ldr r0, [r4, 0x18]
	cmp r0, 0
	beq _08000886
	bl _call_via_r0
_08000886:
	ldr r2, =gUnknown_03007FF8
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

	thumb_func_start DummyIntrHandler
@ void DummyIntrHandler()
DummyIntrHandler: @ 80008A8
	bx lr
	thumb_func_end DummyIntrHandler

	thumb_func_start WaitForVBlankIntr
@ void WaitForVBlankIntr()
WaitForVBlankIntr: @ 80008AC
	push {lr}
	ldr r2, =gUnknown_030022C0
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
	thumb_func_end WaitForVBlankIntr

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

	thumb_func_start Reset
@ void Reset()
Reset: @ 80008F4
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
	bl RTC_SetReadOnly
	movs r0, 0xFF
	bl SoftReset
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end Reset

	thumb_func_start sub_8000964
sub_8000964: @ 8000964
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
	thumb_func_end sub_8000964

	.align 2, 0 @ Don't pad with nop.
