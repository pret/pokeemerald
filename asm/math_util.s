	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_8151624
sub_8151624: @ 8151624
	push {lr}
	adds r1, r0, 0
	movs r0, 0x80
	lsls r0, 9
	lsls r1, 16
	asrs r1, 16
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_8151624

	thumb_func_start sub_815163C
sub_815163C: @ 815163C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0x80
	lsls r2, 1
	lsls r2, r0
	lsls r1, 16
	asrs r1, 16
	adds r0, r2, 0
	bl __divsi3
	lsls r0, 16
	asrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end sub_815163C

	thumb_func_start sub_815165C
sub_815165C: @ 815165C
	push {lr}
	adds r2, r0, 0
	ldr r1, _08151674
	ldr r0, _08151670
	asrs r3, r2, 31
	bl __divdi3
	pop {r1}
	bx r1
	.align 2, 0
_08151670: .4byte 0x00010000
_08151674: .4byte 0x00000000
	thumb_func_end sub_815165C

	.align 2, 0 @ Don't pad with nop.
