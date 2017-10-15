#ifndef GUARD_MALLOC_H
#define GUARD_MALLOC_H

#define malloc Alloc
#define calloc(ct, sz) AllocZeroed((ct) * (sz))
#define free Free

extern u8 gHeap[];
void *Alloc(u32 size);
void *AllocZeroed(u32 size);
void Free(void *pointer);
void InitHeap(void *pointer, u32 size);

#endif // GUARD_MALLOC_H
