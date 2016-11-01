	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start GenerateRandomNumber
@ u16 GenerateRandomNumber()
GenerateRandomNumber: @ 806F5CC
	ldr r2, =0x03005d80
	ldr r1, [r2]
	ldr r0, =0x41c64e6d
	muls r0, r1
	ldr r1, =0x00006073
	adds r0, r1
	str r0, [r2]
	ldr r2, =0x020249c0
	ldr r1, [r2]
	adds r1, 0x1
	str r1, [r2]
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end GenerateRandomNumber

	thumb_func_start SeedRng
@ void SeedRng(u16 seed)
SeedRng: @ 806F5F8
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x03005d80
	str r0, [r1]
	ldr r1, =0x020249bc
	movs r0, 0
	strb r0, [r1]
	bx lr
	.pool
	thumb_func_end SeedRng

	thumb_func_start SeedRng2
SeedRng2: @ 806F610
	lsls r0, 16
	lsrs r0, 16
	ldr r1, =0x03005d84
	str r0, [r1]
	bx lr
	.pool
	thumb_func_end SeedRng2

	thumb_func_start GenerateRandomNumber2
GenerateRandomNumber2: @ 806F620
	ldr r2, =0x03005d84
	ldr r1, [r2]
	ldr r0, =0x41c64e6d
	muls r0, r1
	ldr r1, =0x00006073
	adds r0, r1
	str r0, [r2]
	lsrs r0, 16
	bx lr
	.pool
	thumb_func_end GenerateRandomNumber2

	.align 2, 0 @ Don't pad with nop.
