	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GameFreakRTC_ClearIME
@ void GameFreakRTC_ClearIME()
GameFreakRTC_ClearIME: @ 802F0CC
	ldr r2, =gUnknown_03000DCE
	ldr r1, =0x04000208
	ldrh r0, [r1]
	strh r0, [r2]
	movs r0, 0
	strh r0, [r1]
	bx lr
	.pool
	thumb_func_end GameFreakRTC_ClearIME

	thumb_func_start GameFreakRTC_RestoreIME
@ void GameFreakRTC_RestoreIME()
GameFreakRTC_RestoreIME: @ 802F0E4
	ldr r0, =0x04000208
	ldr r1, =gUnknown_03000DCE
	ldrh r1, [r1]
	strh r1, [r0]
	bx lr
	.pool
	thumb_func_end GameFreakRTC_RestoreIME

	thumb_func_start GameFreakRTC_ConvertFromBCD
@ u8 GameFreakRTC_ConvertFromBCD(u8 bcdByte)
GameFreakRTC_ConvertFromBCD: @ 802F0F8
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	cmp r2, 0x9F
	bhi _0802F10A
	movs r3, 0xF
	ands r3, r2
	cmp r3, 0x9
	bls _0802F10E
_0802F10A:
	movs r0, 0xFF
	b _0802F11C
_0802F10E:
	lsrs r1, r0, 28
	movs r0, 0xF
	ands r1, r0
	lsls r0, r1, 2
	adds r0, r1
	lsls r0, 1
	adds r0, r3
_0802F11C:
	pop {r1}
	bx r1
	thumb_func_end GameFreakRTC_ConvertFromBCD

	thumb_func_start GameFreakRTC_IsLeapYear
@ bool8 GameFreakRTC_IsLeapYear(u32 year)
GameFreakRTC_IsLeapYear: @ 802F120
	push {r4,lr}
	adds r4, r0, 0
	movs r0, 0x3
	ands r0, r4
	cmp r0, 0
	bne _0802F138
	adds r0, r4, 0
	movs r1, 0x64
	bl __umodsi3
	cmp r0, 0
	bne _0802F146
_0802F138:
	movs r1, 0xC8
	lsls r1, 1
	adds r0, r4, 0
	bl __umodsi3
	cmp r0, 0
	bne _0802F14A
_0802F146:
	movs r0, 0x1
	b _0802F14C
_0802F14A:
	movs r0, 0
_0802F14C:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GameFreakRTC_IsLeapYear

	thumb_func_start GameFreakRTC_ConvertYearMonthDayToNumDays
@ u16 GameFreakRTC_ConvertYearMonthDayToNumDays(u8 year, u8 month, u8 dayOfMonth)
GameFreakRTC_ConvertYearMonthDayToNumDays: @ 802F154
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r7, r0, 24
	lsls r1, 24
	lsrs r6, r1, 24
	lsls r2, 24
	lsrs r2, 24
	mov r8, r2
	movs r5, 0
	subs r4, r7, 0x1
	cmp r4, 0
	blt _0802F192
_0802F170:
	ldr r1, =0x0000016d
	adds r0, r5, r1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	bl GameFreakRTC_IsLeapYear
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0802F18C
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_0802F18C:
	subs r4, 0x1
	cmp r4, 0
	bge _0802F170
_0802F192:
	subs r0, r6, 0x1
	cmp r0, 0
	ble _0802F1AA
	ldr r1, =gDaysInEachMonth
	adds r4, r0, 0
_0802F19C:
	ldm r1!, {r0}
	adds r0, r5, r0
	lsls r0, 16
	lsrs r5, r0, 16
	subs r4, 0x1
	cmp r4, 0
	bne _0802F19C
_0802F1AA:
	cmp r6, 0x2
	bls _0802F1C2
	adds r0, r7, 0
	bl GameFreakRTC_IsLeapYear
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _0802F1C2
	adds r0, r5, 0x1
	lsls r0, 16
	lsrs r5, r0, 16
_0802F1C2:
	mov r1, r8
	adds r0, r5, r1
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r5, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GameFreakRTC_ConvertYearMonthDayToNumDays

	thumb_func_start GameFreakRTC_GetNumDaysInternal
@ u16 GameFreakRTC_GetNumDaysInternal(struct RTCInfo *rtc)
GameFreakRTC_GetNumDaysInternal: @ 802F1E0
	push {r4-r6,lr}
	adds r6, r0, 0
	ldrb r0, [r6]
	bl GameFreakRTC_ConvertFromBCD
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldrb r0, [r6, 0x1]
	bl GameFreakRTC_ConvertFromBCD
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldrb r0, [r6, 0x2]
	bl GameFreakRTC_ConvertFromBCD
	adds r2, r0, 0
	lsls r2, 24
	lsrs r2, 24
	adds r0, r5, 0
	adds r1, r4, 0
	bl GameFreakRTC_ConvertYearMonthDayToNumDays
	lsls r0, 16
	lsrs r0, 16
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end GameFreakRTC_GetNumDaysInternal

	thumb_func_start GameFreakRTC_Init
@ void GameFreakRTC_Init()
GameFreakRTC_Init: @ 802F21C
	push {r4,r5,lr}
	ldr r5, =gUnknown_03000DB8
	movs r0, 0
	strh r0, [r5]
	bl GameFreakRTC_ClearIME
	bl SiiRtcUnprotect
	bl SiiRtcProbe
	ldr r4, =gUnknown_03000DCC
	strb r0, [r4]
	bl GameFreakRTC_RestoreIME
	ldrb r4, [r4]
	movs r0, 0xF
	ands r0, r4
	cmp r0, 0x1
	beq _0802F250
	movs r0, 0x1
	strh r0, [r5]
	b _0802F26E
	.pool
_0802F250:
	movs r0, 0xF0
	ands r0, r4
	cmp r0, 0
	beq _0802F25A
	movs r0, 0x2
_0802F25A:
	strh r0, [r5]
	ldr r4, =gUnknown_03000DC0
	adds r0, r4, 0
	bl GameFreakRTC_GetControlRegAndRTCDateTime
	adds r0, r4, 0
	bl GameFreakRTC_TestForErrors
	ldr r1, =gUnknown_03000DB8
	strh r0, [r1]
_0802F26E:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GameFreakRTC_Init

	thumb_func_start GameFreakRTC_GetErrorFlags
@ u16 GameFreakRTC_GetErrorFlags()
GameFreakRTC_GetErrorFlags: @ 802F27C
	ldr r0, =gUnknown_03000DB8
	ldrh r0, [r0]
	bx lr
	.pool
	thumb_func_end GameFreakRTC_GetErrorFlags

	thumb_func_start GameFreakRTC_GetRTCDateTime
@ void GameFreakRTC_GetRTCDateTime(struct RTCInfo *rtc)
GameFreakRTC_GetRTCDateTime: @ 802F288
	push {r4,lr}
	adds r2, r0, 0
	ldr r0, =gUnknown_03000DB8
	ldrh r1, [r0]
	movs r0, 0xFF
	lsls r0, 4
	ands r0, r1
	cmp r0, 0
	beq _0802F2AC
	adds r1, r2, 0
	ldr r0, =gDefaultRTCInfo
	ldm r0!, {r2-r4}
	stm r1!, {r2-r4}
	b _0802F2B2
	.pool
_0802F2AC:
	adds r0, r2, 0
	bl GameFreakRTC_GetControlRegAndRTCDateTime
_0802F2B2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_GetRTCDateTime

	thumb_func_start GameFreakRTC_GetRTCDateTimeInternal
@ void GameFreakRTC_GetRTCDateTimeInternal(struct RTCInfo *rtc)
GameFreakRTC_GetRTCDateTimeInternal: @ 802F2B8
	push {r4,lr}
	adds r4, r0, 0
	bl GameFreakRTC_ClearIME
	adds r0, r4, 0
	bl SiiRtcGetDateTime
	bl GameFreakRTC_RestoreIME
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_GetRTCDateTimeInternal

	thumb_func_start GameFreakRTC_GetControlReg
@ void GameFreakRTC_GetControlReg(struct RTCInfo *rtc)
GameFreakRTC_GetControlReg: @ 802F2D0
	push {r4,lr}
	adds r4, r0, 0
	bl GameFreakRTC_ClearIME
	adds r0, r4, 0
	bl SiiRtcGetStatus
	bl GameFreakRTC_RestoreIME
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_GetControlReg

	thumb_func_start GameFreakRTC_GetControlRegAndRTCDateTime
@ void GameFreakRTC_GetControlRegAndRTCDateTime(struct RTCInfo *rtc)
GameFreakRTC_GetControlRegAndRTCDateTime: @ 802F2E8
	push {r4,lr}
	adds r4, r0, 0
	bl GameFreakRTC_GetControlReg
	adds r0, r4, 0
	bl GameFreakRTC_GetRTCDateTimeInternal
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_GetControlRegAndRTCDateTime

	thumb_func_start GameFreakRTC_TestForErrors
@ u16 GameFreakRTC_TestForErrors(struct RTCInfo *rtc)
GameFreakRTC_TestForErrors: @ 802F2FC
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	adds r7, r0, 0
	ldrb r1, [r7, 0x7]
	movs r0, 0x80
	ands r0, r1
	lsls r0, 24
	lsrs r0, 24
	negs r0, r0
	asrs r4, r0, 31
	movs r0, 0x20
	ands r4, r0
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _0802F322
	movs r0, 0x10
	orrs r4, r0
_0802F322:
	ldrb r0, [r7]
	bl GameFreakRTC_ConvertFromBCD
	mov r8, r0
	cmp r0, 0xFF
	bne _0802F336
	movs r0, 0x40
	orrs r4, r0
	lsls r0, r4, 16
	lsrs r4, r0, 16
_0802F336:
	ldrb r0, [r7, 0x1]
	bl GameFreakRTC_ConvertFromBCD
	adds r6, r0, 0
	cmp r6, 0xFF
	beq _0802F34A
	cmp r6, 0
	beq _0802F34A
	cmp r6, 0xC
	ble _0802F352
_0802F34A:
	movs r0, 0x80
	orrs r4, r0
	lsls r0, r4, 16
	lsrs r4, r0, 16
_0802F352:
	ldrb r0, [r7, 0x2]
	bl GameFreakRTC_ConvertFromBCD
	adds r5, r0, 0
	cmp r5, 0xFF
	bne _0802F36A
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	orrs r4, r0
	lsls r0, r4, 16
	lsrs r4, r0, 16
_0802F36A:
	cmp r6, 0x2
	bne _0802F384
	mov r0, r8
	bl GameFreakRTC_IsLeapYear
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gDaysInEachMonth
	ldr r1, [r1, 0x4]
	adds r0, r1
	b _0802F38E
	.pool
_0802F384:
	ldr r0, =gDaysInEachMonth
	subs r1, r6, 0x1
	lsls r1, 2
	adds r1, r0
	ldr r0, [r1]
_0802F38E:
	cmp r5, r0
	ble _0802F39E
	movs r1, 0x80
	lsls r1, 1
	adds r0, r1, 0
	orrs r4, r0
	lsls r0, r4, 16
	lsrs r4, r0, 16
_0802F39E:
	ldrb r0, [r7, 0x4]
	bl GameFreakRTC_ConvertFromBCD
	adds r5, r0, 0
	cmp r5, 0x18
	ble _0802F3B6
	movs r1, 0x80
	lsls r1, 2
	adds r0, r1, 0
	orrs r4, r0
	lsls r0, r4, 16
	lsrs r4, r0, 16
_0802F3B6:
	ldrb r0, [r7, 0x5]
	bl GameFreakRTC_ConvertFromBCD
	adds r5, r0, 0
	cmp r5, 0x3C
	ble _0802F3CE
	movs r1, 0x80
	lsls r1, 3
	adds r0, r1, 0
	orrs r4, r0
	lsls r0, r4, 16
	lsrs r4, r0, 16
_0802F3CE:
	ldrb r0, [r7, 0x6]
	bl GameFreakRTC_ConvertFromBCD
	adds r5, r0, 0
	cmp r5, 0x3C
	ble _0802F3E6
	movs r1, 0x80
	lsls r1, 4
	adds r0, r1, 0
	orrs r4, r0
	lsls r0, r4, 16
	lsrs r4, r0, 16
_0802F3E6:
	adds r0, r4, 0
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GameFreakRTC_TestForErrors

	thumb_func_start GameFreakRTC_Reset
@ void GameFreakRTC_Reset()
GameFreakRTC_Reset: @ 802F3F8
	push {lr}
	bl GameFreakRTC_ClearIME
	bl SiiRtcReset
	bl GameFreakRTC_RestoreIME
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_Reset

	thumb_func_start GameFreakRTC_FormatDecimalTimeString
@ void GameFreakRTC_FormatDecimalTimeString(u8 *dest, s32 hour, s32 minute, s32 second)
GameFreakRTC_FormatDecimalTimeString: @ 802F40C
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalString
	movs r4, 0xF0
	strb r4, [r0]
	adds r0, 0x1
	adds r1, r5, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalString
	strb r4, [r0]
	adds r0, 0x1
	adds r1, r6, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalString
	movs r1, 0xFF
	strb r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_FormatDecimalTimeString

	thumb_func_start GameFreakRTC_FormatHexTimeString
@ void GameFreakRTC_FormatHexTimeString(u8 *dest, s32 hour, s32 minute, s32 second)
GameFreakRTC_FormatHexTimeString: @ 802F444
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToHexString
	movs r4, 0xF0
	strb r4, [r0]
	adds r0, 0x1
	adds r1, r5, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToHexString
	strb r4, [r0]
	adds r0, 0x1
	adds r1, r6, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToHexString
	movs r1, 0xFF
	strb r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_FormatHexTimeString

	thumb_func_start GameFreakRTC_FormatHexTimeStringFromRTCInfo
@ void GameFreakRTC_FormatHexTimeStringFromRTCInfo()
GameFreakRTC_FormatHexTimeStringFromRTCInfo: @ 802F47C
	push {lr}
	ldr r3, =gUnknown_03000DC0
	ldrb r1, [r3, 0x4]
	ldrb r2, [r3, 0x5]
	ldrb r3, [r3, 0x6]
	bl GameFreakRTC_FormatHexTimeString
	pop {r0}
	bx r0
	.pool
	thumb_func_end GameFreakRTC_FormatHexTimeStringFromRTCInfo

	thumb_func_start GameFreakRTC_FormatDecimalYearMonthDayString
@ void GameFreakRTC_FormatDecimalYearMonthDayString(u8 *dest, s32 year, s32 month, s32 dayOfMonth)
GameFreakRTC_FormatDecimalYearMonthDayString: @ 802F494
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	movs r2, 0x2
	movs r3, 0x4
	bl ConvertIntToDecimalString
	movs r4, 0xAE
	strb r4, [r0]
	adds r0, 0x1
	adds r1, r5, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalString
	strb r4, [r0]
	adds r0, 0x1
	adds r1, r6, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToDecimalString
	movs r1, 0xFF
	strb r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_FormatDecimalYearMonthDayString

	thumb_func_start GameFreakRTC_FormatHexYearMonthDayString
@ void GameFreakRTC_FormatHexYearMonthDayString(u8 *dest, s32 year, s32 month, s32 dayOfMonth)
GameFreakRTC_FormatHexYearMonthDayString: @ 802F4CC
	push {r4-r6,lr}
	adds r5, r2, 0
	adds r6, r3, 0
	movs r2, 0x2
	movs r3, 0x4
	bl ConvertIntToHexString
	movs r4, 0xAE
	strb r4, [r0]
	adds r0, 0x1
	adds r1, r5, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToHexString
	strb r4, [r0]
	adds r0, 0x1
	adds r1, r6, 0
	movs r2, 0x2
	movs r3, 0x2
	bl ConvertIntToHexString
	movs r1, 0xFF
	strb r1, [r0]
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_FormatHexYearMonthDayString

	thumb_func_start GameFreakRTC_GetRTCDelta
@ void GameFreakRTC_GetRTCDelta(RTCInfo *rtc, GameDateTime *delta, GameDateTime *dateTime)
GameFreakRTC_GetRTCDelta: @ 802F504
	push {r4-r7,lr}
	adds r5, r0, 0
	adds r7, r1, 0
	adds r6, r2, 0
	bl GameFreakRTC_GetNumDaysInternal
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	ldrb r0, [r5, 0x6]
	bl GameFreakRTC_ConvertFromBCD
	ldrb r1, [r6, 0x4]
	subs r0, r1
	strb r0, [r7, 0x4]
	ldrb r0, [r5, 0x5]
	bl GameFreakRTC_ConvertFromBCD
	ldrb r1, [r6, 0x3]
	subs r0, r1
	strb r0, [r7, 0x3]
	ldrb r0, [r5, 0x4]
	bl GameFreakRTC_ConvertFromBCD
	ldrb r1, [r6, 0x2]
	subs r0, r1
	strb r0, [r7, 0x2]
	ldrh r0, [r6]
	subs r4, r0
	strh r4, [r7]
	ldrb r1, [r7, 0x4]
	movs r0, 0x4
	ldrsb r0, [r7, r0]
	cmp r0, 0
	bge _0802F556
	adds r0, r1, 0
	adds r0, 0x3C
	strb r0, [r7, 0x4]
	ldrb r0, [r7, 0x3]
	subs r0, 0x1
	strb r0, [r7, 0x3]
_0802F556:
	ldrb r1, [r7, 0x3]
	movs r0, 0x3
	ldrsb r0, [r7, r0]
	cmp r0, 0
	bge _0802F56C
	adds r0, r1, 0
	adds r0, 0x3C
	strb r0, [r7, 0x3]
	ldrb r0, [r7, 0x2]
	subs r0, 0x1
	strb r0, [r7, 0x2]
_0802F56C:
	ldrb r1, [r7, 0x2]
	movs r0, 0x2
	ldrsb r0, [r7, r0]
	cmp r0, 0
	bge _0802F582
	adds r0, r1, 0
	adds r0, 0x18
	strb r0, [r7, 0x2]
	ldrh r0, [r7]
	subs r0, 0x1
	strh r0, [r7]
_0802F582:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_GetRTCDelta

	thumb_func_start GameFreakRTC_CalcLocalDateTime
@ void GameFreakRTC_CalcLocalDateTime()
GameFreakRTC_CalcLocalDateTime: @ 802F588
	push {r4,lr}
	ldr r4, =gUnknown_03000DC0
	adds r0, r4, 0
	bl GameFreakRTC_GetRTCDateTime
	ldr r1, =gUnknown_03005CF8
	ldr r0, =gUnknown_03005D90
	ldr r2, [r0]
	adds r2, 0x98
	adds r0, r4, 0
	bl GameFreakRTC_GetRTCDelta
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GameFreakRTC_CalcLocalDateTime

	thumb_func_start GameFreakRTC_CalcRTCToLocalDelta_DayZero
@ void GameFreakRTC_CalcRTCToLocalDelta_DayZero(u8 hour, u8 minute)
GameFreakRTC_CalcRTCToLocalDelta_DayZero: @ 802F5B4
	push {lr}
	adds r3, r0, 0
	adds r2, r1, 0
	movs r0, 0
	adds r1, r3, 0
	movs r3, 0
	bl GameFreakRTC_CalcRTCToLocalDelta
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_CalcRTCToLocalDelta_DayZero

	thumb_func_start GameFreakRTC_CalcRTCToLocalDelta
@ void GameFreakRTC_CalcRTCToLocalDelta(u16 numDays, u8 hour, u8 minute, u8 second)
GameFreakRTC_CalcRTCToLocalDelta: @ 802F5C8
	push {r4,r5,lr}
	ldr r4, =gUnknown_03005CF8
	strh r0, [r4]
	strb r1, [r4, 0x2]
	strb r2, [r4, 0x3]
	strb r3, [r4, 0x4]
	ldr r5, =gUnknown_03000DC0
	adds r0, r5, 0
	bl GameFreakRTC_GetRTCDateTime
	ldr r0, =gUnknown_03005D90
	ldr r1, [r0]
	adds r1, 0x98
	adds r0, r5, 0
	adds r2, r4, 0
	bl GameFreakRTC_GetRTCDelta
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end GameFreakRTC_CalcRTCToLocalDelta

	thumb_func_start GameFreakRTC_GetDelta
@ void GameFreakRTC_GetDelta(GameDateTime *delta, GameDateTime *dateTime1, GameDateTime *dateTime2)
GameFreakRTC_GetDelta: @ 802F5FC
	push {r4-r6,lr}
	adds r4, r0, 0
	ldrb r3, [r2, 0x4]
	ldrb r0, [r1, 0x4]
	subs r5, r3, r0
	strb r5, [r4, 0x4]
	ldrb r3, [r2, 0x3]
	ldrb r0, [r1, 0x3]
	subs r6, r3, r0
	strb r6, [r4, 0x3]
	ldrb r0, [r2, 0x2]
	ldrb r3, [r1, 0x2]
	subs r0, r3
	strb r0, [r4, 0x2]
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r1
	strh r0, [r4]
	lsls r0, r5, 24
	cmp r0, 0
	bge _0802F630
	adds r0, r5, 0
	adds r0, 0x3C
	strb r0, [r4, 0x4]
	subs r0, r6, 0x1
	strb r0, [r4, 0x3]
_0802F630:
	ldrb r1, [r4, 0x3]
	movs r0, 0x3
	ldrsb r0, [r4, r0]
	cmp r0, 0
	bge _0802F646
	adds r0, r1, 0
	adds r0, 0x3C
	strb r0, [r4, 0x3]
	ldrb r0, [r4, 0x2]
	subs r0, 0x1
	strb r0, [r4, 0x2]
_0802F646:
	ldrb r1, [r4, 0x2]
	movs r0, 0x2
	ldrsb r0, [r4, r0]
	cmp r0, 0
	bge _0802F65C
	adds r0, r1, 0
	adds r0, 0x18
	strb r0, [r4, 0x2]
	ldrh r0, [r4]
	subs r0, 0x1
	strh r0, [r4]
_0802F65C:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end GameFreakRTC_GetDelta

	thumb_func_start GameFreakRTC_GetNumMinutes
@ u16 GameFreakRTC_GetNumMinutes()
GameFreakRTC_GetNumMinutes: @ 802F664
	push {r4,lr}
	ldr r4, =gUnknown_03000DC0
	adds r0, r4, 0
	bl GameFreakRTC_GetRTCDateTime
	adds r0, r4, 0
	bl GameFreakRTC_GetNumDaysInternal
	lsls r0, 16
	lsrs r0, 16
	lsls r1, r0, 1
	adds r1, r0
	lsls r0, r1, 4
	subs r0, r1
	lsls r0, 5
	ldrb r2, [r4, 0x4]
	lsls r1, r2, 4
	subs r1, r2
	lsls r1, 2
	adds r0, r1
	ldrb r4, [r4, 0x5]
	adds r0, r4
	pop {r4}
	pop {r1}
	bx r1
	.pool
	thumb_func_end GameFreakRTC_GetNumMinutes

	thumb_func_start GameFreakRTC_GetNumDays
@ u16 GameFreakRTC_GetNumDays()
GameFreakRTC_GetNumDays: @ 802F69C
	push {lr}
	ldr r0, =gUnknown_03000DC0
	bl GameFreakRTC_GetNumDaysInternal
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	.pool
	thumb_func_end GameFreakRTC_GetNumDays

	.align 2, 0 @ Don't pad with nop.
