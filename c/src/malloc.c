#include "global.h"

extern void *gHeapStart;
extern u32 gHeapSize;

#define MALLOC_SYSTEM_ID 0xA3A3

struct MemBlock {
	bool16 flag;
	u16 magic;
	u32 size;
	struct MemBlock *prev;
	struct MemBlock *next;
};

void PutMemBlockHeader(void *block, struct MemBlock *prev, struct MemBlock *next, u32 size)
{
	struct MemBlock *header = (struct MemBlock *)block;

	header->flag = 0;
	header->magic = MALLOC_SYSTEM_ID;
	header->size = size;
	header->prev = prev;
	header->next = next;
}

void PutFirstMemBlockHeader(void *block, u32 size)
{
	PutMemBlockHeader(block, (struct MemBlock *)block, (struct MemBlock *)block, size - 16);
}

void *AllocInternal(struct MemBlock *pos, u32 size)
{
	struct MemBlock *head = pos;
	struct MemBlock *splitBlock;
	u32 foundBlockSize;

	if (size & 3)
		size = 4 * ((size / 4) + 1);

	for (;;) {
		// Loop through the blocks looking for unused block that's big enough.

		if (!pos->flag) {
			foundBlockSize = pos->size;

			if (foundBlockSize >= size) {
				if (foundBlockSize - size <= 31) {
					// The block isn't much bigger than the requested size,
					// so just use it.
					pos->flag = TRUE;
				} else {
					// The block is significantly bigger than the requested
					// size, so split the rest into a separate block.
					foundBlockSize -= sizeof(struct MemBlock);
					foundBlockSize -= size;
					
					splitBlock = (struct MemBlock *)((u8 *)(&pos[1]) + size);

					pos->flag = TRUE;
					pos->size = size;

					PutMemBlockHeader(splitBlock, pos, pos->next, foundBlockSize);

					pos->next = splitBlock;

					if (splitBlock->next != head)
						splitBlock->next->prev = splitBlock;

					return &pos[1];
				}
			}
		}

		if (pos->next == head)
			return NULL;

		pos = pos->next;
	}
}

void FreeInternal(void *heapStart, void *pointer)
{
	if (pointer) {
		struct MemBlock *head = (struct MemBlock *)heapStart;
		struct MemBlock *block = (struct MemBlock *)((u8 *)pointer - sizeof(struct MemBlock));
		block->flag = FALSE;

		// If the freed block isn't the last one, merge with the next block
		// if it's not in use.
		if (block->next != head) {
			if (!block->next->flag) {
				block->size += sizeof(struct MemBlock) + block->next->size;
				block->next->magic = 0;
				block->next = block->next->next;
				if (block->next != head)
					block->next->prev = block;
			}
		}

		// If the freed block isn't the first one, merge with the previous block
		// if it's not in use.
		if (block != head) {
			if (!block->prev->flag) {
				block->prev->next = block->next;

				if (block->next != head)
					block->next->prev = block->prev;

				block->magic = 0;
				block->prev->size += sizeof(struct MemBlock) + block->size;
			}
		}
	}
}

void *AllocZeroedInternal(void *heapStart, u32 size)
{
	void *mem = AllocInternal((struct MemBlock *)heapStart, size);

	if (mem != NULL) {
		u32 zero;
		u32 sizeInWords;

		if (size & 3)
			size = 4 * ((size / 4) + 1);

		zero = 0;
		sizeInWords = (size << 9) >> 11;

		CpuSet(&zero, mem, CPU_SET_32BIT | CPU_SET_SRC_FIX | sizeInWords);
	}

	return mem;
}

bool32 CheckMemBlockInternal(void *heapStart, void *pointer)
{
	struct MemBlock *head = (struct MemBlock *)heapStart;
	struct MemBlock *block = (struct MemBlock *)((u8 *)pointer - sizeof(struct MemBlock));

	if (block->magic != MALLOC_SYSTEM_ID)
		return FALSE;

	if (block->next->magic != MALLOC_SYSTEM_ID)
		return FALSE;

	if (block->next != head && block->next->prev != block)
		return FALSE;

	if (block->prev->magic != MALLOC_SYSTEM_ID)
		return FALSE;

	if (block->prev != head && block->prev->next != block)
		return FALSE;

	if (block->next != head && block->next != (struct MemBlock *)((u8 *)(&block[1]) + block->size))
		return FALSE;

	return TRUE;
}

void InitHeap(void *heapStart, u32 heapSize)
{
	gHeapStart = heapStart;
	gHeapSize = heapSize;
	PutFirstMemBlockHeader(heapStart, heapSize);
}

void *Alloc(u32 size)
{
	AllocInternal(gHeapStart, size);
}

void *AllocZeroed(u32 size)
{
	AllocZeroedInternal(gHeapStart, size);
}

void Free(void *pointer)
{
	FreeInternal(gHeapStart, pointer);
}

bool32 CheckMemBlock(void *pointer)
{
	return CheckMemBlockInternal(gHeapStart, pointer);
}

bool32 CheckHeap()
{
	struct MemBlock *pos = (struct MemBlock *)gHeapStart;

	do {
		if (!CheckMemBlockInternal(gHeapStart, &pos[1]))
			return FALSE;
		pos = pos->next;
	} while (pos != (struct MemBlock *)gHeapStart);

	return TRUE;
}
