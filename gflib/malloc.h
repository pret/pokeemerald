#ifndef GUARD_ALLOC_H
#define GUARD_ALLOC_H


#define FREE_AND_SET_NULL(ptr)          \
{                                       \
    Free(ptr);                          \
    ptr = NULL;                         \
}

#define TRY_FREE_AND_SET_NULL(ptr) if (ptr != NULL) FREE_AND_SET_NULL(ptr)

#define MALLOC_SYSTEM_ID 0xA3A3

struct MemBlock
{
    // Whether this block is currently allocated.
    u16 allocated:1;

    u16 unused_00:4;

    // High 11 bits of location pointer.
    u16 locationHi:11;

    // Magic number used for error checking. Should equal MALLOC_SYSTEM_ID.
    u16 magic;

    // Size of the block (not including this header struct).
    u32 size:18;

    // Low 14 bits of location pointer.
    u32 locationLo:14;

    // Previous block pointer. Equals sHeapStart if this is the first block.
    struct MemBlock *prev;

    // Next block pointer. Equals sHeapStart if this is the last block.
    struct MemBlock *next;

    // Data in the memory block. (Arrays of length 0 are a GNU extension.)
    u8 data[0];
};

#define HEAP_SIZE 0x1C000
extern u8 gHeap[HEAP_SIZE];

#if TESTING || !defined(NDEBUG)

#define Alloc(size) Alloc_(size, __FILE__ ":" STR(__LINE__))
#define AllocZeroed(size) AllocZeroed_(size, __FILE__ ":" STR(__LINE__))

#else

#define Alloc(size) Alloc_(size, NULL)
#define AllocZeroed(size) AllocZeroed_(size, NULL)

#endif

void *Alloc_(u32 size, const char *location);
void *AllocZeroed_(u32 size, const char *location);
void Free(void *pointer);
void InitHeap(void *pointer, u32 size);

const struct MemBlock *HeapHead(void);
const char *MemBlockLocation(const struct MemBlock *block);

#endif // GUARD_ALLOC_H
