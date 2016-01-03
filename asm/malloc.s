	thumb_func_start PutMemBlockHeader
; void PutMemBlockHeader(void *block, struct MemBlock *prev, struct MemBlock *next, u32 size)
PutMemBlockHeader: ; 8000988
	push {r4,lr}
	movs r4, 0
	strh r4, [r0]
	ldr r4, =0x0000a3a3
	strh r4, [r0, 0x2]
	str r3, [r0, 0x4]
	str r1, [r0, 0x8]
	str r2, [r0, 0xC]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end PutMemBlockHeader

	thumb_func_start PutFirstMemBlockHeader
; void PutFirstMemBlockHeader(void *block, u32 size)
PutFirstMemBlockHeader: ; 80009A4
	push {lr}
	adds r2, r0, 0
	adds r3, r1, 0
	subs r3, 0x10
	adds r1, r2, 0
	bl PutMemBlockHeader
	pop {r0}
	bx r0
	thumb_func_end PutFirstMemBlockHeader

	thumb_func_start AllocInternal
; void *AllocInternal(struct MemBlock *head, u32 size)
AllocInternal: ; 80009B8
	push {r4-r6,lr}
	adds r4, r0, 0
	adds r6, r4, 0
	movs r0, 0x3
	ands r0, r1
	cmp r0, 0
	beq @080009CC
	lsrs r0, r1, 2
	adds r0, 0x1
	lsls r1, r0, 2
@080009CC:
	movs r2, 0x1
@080009CE:
	ldrh r0, [r4]
	cmp r0, 0
	bne @08000A0C
	ldr r3, [r4, 0x4]
	cmp r3, r1
	bcc @08000A0C
	subs r0, r3, r1
	cmp r0, 0x1F
	bhi @080009E4
	strh r2, [r4]
	b @08000A06
@080009E4:
	subs r3, 0x10
	subs r3, r1
	adds r0, r1, 0
	adds r0, 0x10
	adds r5, r4, r0
	strh r2, [r4]
	str r1, [r4, 0x4]
	ldr r2, [r4, 0xC]
	adds r0, r5, 0
	adds r1, r4, 0
	bl PutMemBlockHeader
	str r5, [r4, 0xC]
	ldr r0, [r5, 0xC]
	cmp r0, r6
	beq @08000A06
	str r5, [r0, 0x8]
@08000A06:
	adds r0, r4, 0
	adds r0, 0x10
	b @08000A18
@08000A0C:
	ldr r0, [r4, 0xC]
	cmp r0, r6
	beq @08000A16
	adds r4, r0, 0
	b @080009CE
@08000A16:
	movs r0, 0
@08000A18:
	pop {r4-r6}
	pop {r1}
	bx r1
	thumb_func_end AllocInternal

	thumb_func_start FreeInternal
; void FreeInternal(void *heapStart, void *pointer)
FreeInternal: ; 8000A20
	push {r4,r5,lr}
	cmp r1, 0
	beq @08000A7C
	adds r5, r0, 0
	adds r2, r1, 0
	subs r2, 0x10
	movs r0, 0
	strh r0, [r2]
	ldr r3, [r2, 0xC]
	cmp r3, r5
	beq @08000A54
	ldrh r4, [r3]
	cmp r4, 0
	bne @08000A54
	ldr r0, [r2, 0x4]
	adds r0, 0x10
	ldr r1, [r3, 0x4]
	adds r0, r1
	str r0, [r2, 0x4]
	strh r4, [r3, 0x2]
	ldr r0, [r2, 0xC]
	ldr r0, [r0, 0xC]
	str r0, [r2, 0xC]
	cmp r0, r5
	beq @08000A54
	str r2, [r0, 0x8]
@08000A54:
	cmp r2, r5
	beq @08000A7C
	ldr r1, [r2, 0x8]
	ldrh r3, [r1]
	cmp r3, 0
	bne @08000A7C
	ldr r0, [r2, 0xC]
	str r0, [r1, 0xC]
	ldr r1, [r2, 0xC]
	cmp r1, r5
	beq @08000A6E
	ldr r0, [r2, 0x8]
	str r0, [r1, 0x8]
@08000A6E:
	strh r3, [r2, 0x2]
	ldr r0, [r2, 0x8]
	ldr r1, [r0, 0x4]
	adds r1, 0x10
	ldr r2, [r2, 0x4]
	adds r1, r2
	str r1, [r0, 0x4]
@08000A7C:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end FreeInternal

	thumb_func_start AllocZeroedInternal
; void *AllocZeroedInternal(void *heapStart, u32 size)
AllocZeroedInternal: ; 8000A84
	push {r4,r5,lr}
	sub sp, 0x4
	adds r4, r1, 0
	bl AllocInternal
	adds r5, r0, 0
	cmp r5, 0
	beq @08000AB8
	movs r0, 0x3
	ands r0, r4
	cmp r0, 0
	beq @08000AA2
	lsrs r0, r4, 2
	adds r0, 0x1
	lsls r4, r0, 2
@08000AA2:
	movs r0, 0
	str r0, [sp]
	lsls r2, r4, 9
	lsrs r2, 11
	movs r0, 0xA0
	lsls r0, 19
	orrs r2, r0
	mov r0, sp
	adds r1, r5, 0
	bl CpuSet
@08000AB8:
	adds r0, r5, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end AllocZeroedInternal

	thumb_func_start CheckMemBlockInternal
; BOOL CheckMemBlockInternal(struct MemBlock *head, struct MemBlock *node)
CheckMemBlockInternal: ; 8000AC4
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r3, r1, 0
	subs r3, 0x10
	ldrh r2, [r3, 0x2]
	ldr r0, =0x0000a3a3
	cmp r2, r0
	bne @08000B0A
	ldr r0, [r3, 0xC]
	ldrh r1, [r0, 0x2]
	adds r4, r0, 0
	cmp r1, r2
	bne @08000B0A
	cmp r4, r5
	beq @08000AE8
	ldr r0, [r4, 0x8]
	cmp r0, r3
	bne @08000B0A
@08000AE8:
	ldr r2, [r3, 0x8]
	ldrh r1, [r2, 0x2]
	ldr r0, =0x0000a3a3
	cmp r1, r0
	bne @08000B0A
	cmp r2, r5
	beq @08000AFC
	ldr r0, [r2, 0xC]
	cmp r0, r3
	bne @08000B0A
@08000AFC:
	cmp r4, r5
	beq @08000B14
	ldr r0, [r3, 0x4]
	adds r0, 0x10
	adds r0, r3, r0
	cmp r4, r0
	beq @08000B14
@08000B0A:
	movs r0, 0
	b @08000B16
	.pool
@08000B14:
	movs r0, 0x1
@08000B16:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CheckMemBlockInternal

	thumb_func_start InitHeap
; void InitHeap(void *heapStart, u32 heapSize)
InitHeap: ; 8000B1C
	push {lr}
	ldr r2, =0x03000004
	str r0, [r2]
	ldr r2, =0x03000008
	str r1, [r2]
	bl PutFirstMemBlockHeader
	pop {r0}
	bx r0
	.pool
	thumb_func_end InitHeap

	thumb_func_start Alloc
; void *Alloc(u32 size)
Alloc: ; 8000B38
	push {lr}
	adds r1, r0, 0
	ldr r0, =0x03000004
	ldr r0, [r0]
	bl AllocInternal
	pop {r1}
	bx r1
	.pool
	thumb_func_end Alloc

	thumb_func_start AllocZeroed
; void *AllocZeroed(u32 size)
AllocZeroed: ; 8000B4C
	push {lr}
	adds r1, r0, 0
	ldr r0, =0x03000004
	ldr r0, [r0]
	bl AllocZeroedInternal
	pop {r1}
	bx r1
	.pool
	thumb_func_end AllocZeroed

	thumb_func_start Free
; void Free(void *pointer)
Free: ; 8000B60
	push {lr}
	adds r1, r0, 0
	ldr r0, =0x03000004
	ldr r0, [r0]
	bl FreeInternal
	pop {r0}
	bx r0
	.pool
	thumb_func_end Free

	thumb_func_start CheckMemBlock
; BOOL CheckMemBlock(void *pointer)
CheckMemBlock: ; 8000B74
	push {lr}
	adds r1, r0, 0
	ldr r0, =0x03000004
	ldr r0, [r0]
	bl CheckMemBlockInternal
	pop {r1}
	bx r1
	.pool
	thumb_func_end CheckMemBlock

	thumb_func_start CheckHeap
; BOOL CheckHeap()
CheckHeap: ; 8000B88
	push {r4,r5,lr}
	ldr r0, =0x03000004
	ldr r4, [r0]
	adds r5, r0, 0
@08000B90:
	ldr r0, [r5]
	adds r1, r4, 0
	adds r1, 0x10
	bl CheckMemBlockInternal
	cmp r0, 0
	beq @08000BB0
	ldr r4, [r4, 0xC]
	ldr r0, [r5]
	cmp r4, r0
	bne @08000B90
	movs r0, 0x1
	b @08000BB2
	.pool
@08000BB0:
	movs r0, 0
@08000BB2:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end CheckHeap
