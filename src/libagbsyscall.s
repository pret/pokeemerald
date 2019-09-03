	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start ArcTan2
ArcTan2: @ 82E7078
	swi 0xA
	bx lr
	thumb_func_end ArcTan2

	thumb_func_start BgAffineSet
@ void BgAffineSet(BgAffineSet_src_data *src, BgAffineSet_dest_data *dest, int entry_count)
BgAffineSet: @ 82E707C
	swi 0xE
	bx lr
	thumb_func_end BgAffineSet

	thumb_func_start CpuFastSet
@ void CpuFastSet(void *src, void *dest, unsigned int mode)
CpuFastSet: @ 82E7080
	swi 0xC
	bx lr
	thumb_func_end CpuFastSet

	thumb_func_start CpuSet
@ void CpuSet(void *src, void *dest, unsigned int mode)
CpuSet: @ 82E7084
	swi 0xB
	bx lr
	thumb_func_end CpuSet

	thumb_func_start Div
Div: @ 82E7088
	swi 0x6
	bx lr
	thumb_func_end Div

	thumb_func_start LZ77UnCompVram
@ void LZ77UnCompVram(void *src, void *dest)
LZ77UnCompVram: @ 82E708C
	swi 0x12
	bx lr
	thumb_func_end LZ77UnCompVram

	thumb_func_start LZ77UnCompWram
@ void LZ77UnCompWram(void *src, void *dest)
LZ77UnCompWram: @ 82E7090
	swi 0x11
	bx lr
	thumb_func_end LZ77UnCompWram

	thumb_func_start MultiBoot
@ s32 MultiBoot(struct MultiBootParam *mp)
MultiBoot: @ 82E7094
	movs r1, 0x1
	swi 0x25
	bx lr
	thumb_func_end MultiBoot

	thumb_func_start ObjAffineSet
ObjAffineSet: @ 82E709C
	swi 0xF
	bx lr
	thumb_func_end ObjAffineSet

	thumb_func_start RLUnCompVram
RLUnCompVram: @ 82E70A0
	swi 0x15
	bx lr
	thumb_func_end RLUnCompVram

	thumb_func_start RLUnCompWram
RLUnCompWram: @ 82E70A4
	swi 0x14
	bx lr
	thumb_func_end RLUnCompWram

	thumb_func_start RegisterRamReset
@ void RegisterRamReset(int ResetFlags)
RegisterRamReset: @ 82E70A8
	swi 0x1
	bx lr
	thumb_func_end RegisterRamReset

	thumb_func_start SoftReset
@ void SoftReset()
SoftReset: @ 82E70AC
	ldr r3, =REG_IME
	movs r2, 0
	strb r2, [r3]
	ldr r1, =0x3007F00
	mov sp, r1
	swi 0x1
	swi 0
	.pool
	thumb_func_end SoftReset

	thumb_func_start Sqrt
@ s16 Sqrt(int)
Sqrt: @ 82E70C4
	swi 0x8
	bx lr
	thumb_func_end Sqrt

	thumb_func_start VBlankIntrWait
@ void VBlankIntrWait()
VBlankIntrWait: @ 82E70C8
	movs r2, 0
	swi 0x5
	bx lr
	thumb_func_end VBlankIntrWait

	.align 2, 0 @ Don't pad with nop.
