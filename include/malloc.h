#ifndef GUARD_MALLOC_H
#define GUARD_MALLOC_H

void *Alloc(u32 size);
void *AllocZeroed(u32 size);
void Free(void *pointer);

#endif // GUARD_MALLOC_H
