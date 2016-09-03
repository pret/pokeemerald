	.include "asm/macros.s"

	.syntax unified

	.text

	thumb_func_start memcpy
@ void *memcpy(void *dest, void *src, int size)
memcpy: @ 82E93D4
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r5, 0
	adds r3, r1, 0
	cmp r2, 0xF
	bls _082E9414
	adds r0, r3, 0
	orrs r0, r5
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _082E9414
	adds r1, r5, 0
_082E93EE:
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, 0x10
	cmp r2, 0xF
	bhi _082E93EE
	cmp r2, 0x3
	bls _082E9412
_082E9408:
	ldm r3!, {r0}
	stm r1!, {r0}
	subs r2, 0x4
	cmp r2, 0x3
	bhi _082E9408
_082E9412:
	adds r4, r1, 0
_082E9414:
	subs r2, 0x1
	movs r0, 0x1
	negs r0, r0
	cmp r2, r0
	beq _082E942E
	adds r1, r0, 0
_082E9420:
	ldrb r0, [r3]
	strb r0, [r4]
	adds r3, 0x1
	adds r4, 0x1
	subs r2, 0x1
	cmp r2, r1
	bne _082E9420
_082E942E:
	adds r0, r5, 0
	pop {r4,r5,pc}
	thumb_func_end memcpy

	thumb_func_start memset
@ void *memset(void *dest, char c, int size)
memset: @ 82E9434
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	adds r3, r5, 0
	cmp r2, 0x3
	bls _082E947A
	movs r0, 0x3
	ands r0, r5
	cmp r0, 0
	bne _082E947A
	adds r1, r5, 0
	movs r0, 0xFF
	ands r4, r0
	lsls r3, r4, 8
	orrs r3, r4
	lsls r0, r3, 16
	orrs r3, r0
	cmp r2, 0xF
	bls _082E946E
_082E945A:
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	subs r2, 0x10
	cmp r2, 0xF
	bhi _082E945A
	b _082E946E
_082E946A:
	stm r1!, {r3}
	subs r2, 0x4
_082E946E:
	cmp r2, 0x3
	bhi _082E946A
	adds r3, r1, 0
	b _082E947A
_082E9476:
	strb r4, [r3]
	adds r3, 0x1
_082E947A:
	adds r0, r2, 0
	subs r2, 0x1
	cmp r0, 0
	bne _082E9476
	adds r0, r5, 0
	pop {r4,r5,pc}
	thumb_func_end memset

	thumb_func_start strcmp
@ int strcmp(char *s1, char *s2)
strcmp: @ 82E9488
	push {r4,r5,lr}
	adds r2, r0, 0
	adds r3, r1, 0
	orrs r0, r3
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _082E94CE
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	bne _082E94CE
	ldr r5, _082E94B4
	ldr r4, _082E94B8
_082E94A4:
	ldr r1, [r2]
	adds r0, r1, r5
	bics r0, r1
	ands r0, r4
	cmp r0, 0
	beq _082E94BC
	movs r0, 0
	b _082E94E0
	.align 2, 0
_082E94B4: .4byte 0xfefefeff
_082E94B8: .4byte 0x80808080
_082E94BC:
	adds r2, 0x4
	adds r3, 0x4
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	beq _082E94A4
	b _082E94CE
_082E94CA:
	adds r2, 0x1
	adds r3, 0x1
_082E94CE:
	ldrb r0, [r2]
	cmp r0, 0
	beq _082E94DA
	ldrb r1, [r3]
	cmp r0, r1
	beq _082E94CA
_082E94DA:
	ldrb r2, [r2]
	ldrb r3, [r3]
	subs r0, r2, r3
_082E94E0:
	pop {r4,r5,pc}
	thumb_func_end strcmp

	thumb_func_start strcat
strcat: @ 82E94E4
	push {r4-r6,lr}
	adds r6, r0, 0
	adds r3, r6, 0
	adds r2, r1, 0
	adds r0, r2, 0
	orrs r0, r6
	movs r1, 0x3
	ands r0, r1
	cmp r0, 0
	bne _082E951C
	ldr r1, [r2]
	ldr r5, _082E9504
	adds r0, r1, r5
	bics r0, r1
	ldr r4, _082E9508
	b _082E9516
	.align 2, 0
_082E9504: .4byte 0xfefefeff
_082E9508: .4byte 0x80808080
_082E950C:
	ldm r2!, {r0}
	stm r3!, {r0}
	ldr r1, [r2]
	adds r0, r1, r5
	bics r0, r1
_082E9516:
	ands r0, r4
	cmp r0, 0
	beq _082E950C
_082E951C:
	ldrb r0, [r2]
	strb r0, [r3]
	lsls r0, 24
	adds r2, 0x1
	adds r3, 0x1
	cmp r0, 0
	bne _082E951C
	adds r0, r6, 0
	pop {r4-r6,pc}

	.align 2, 0 @ Don't pad with nop.
