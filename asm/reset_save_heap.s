	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81700F8
sub_81700F8: @ 81700F8
	push {r4,r5,lr}
	ldr r5, =0x04000208
	ldrh r4, [r5]
	movs r0, 0
	strh r0, [r5]
	movs r0, 0x1
	bl RegisterRamReset
	movs r0, 0
	movs r1, 0x80
	bl ClearGpuRegBits
	strh r4, [r5]
	ldr r1, =gMain
	ldr r0, =0x00000439
	adds r1, r0
	ldrb r2, [r1]
	movs r0, 0x3
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	bl sub_815355C
	lsls r0, 16
	lsrs r0, 16
	bl SetSaveBlocksPointers
	bl sub_808447C
	bl ResetSaveCounters
	movs r0, 0
	bl sub_81534D0
	ldr r0, =gSaveFileStatus
	ldrh r0, [r0]
	cmp r0, 0
	beq _08170148
	cmp r0, 0x2
	bne _0817014C
_08170148:
	bl Sav2_ClearSetDefault
_0817014C:
	ldr r0, =gSaveBlock2Ptr
	ldr r0, [r0]
	ldrb r0, [r0, 0x15]
	lsls r0, 31
	lsrs r0, 31
	bl SetPokemonCryStereo
	ldr r0, =0x02000000
	movs r1, 0xE0
	lsls r1, 9
	bl InitHeap
	ldr r0, =sub_8086230
	bl SetMainCallback2
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81700F8

	.align 2, 0 @ Don't pad with nop.
