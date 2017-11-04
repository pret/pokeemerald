#ifndef GUARD_LIBC_H
#define GUARD_LIBC_H

void *memset(void *dst, int val, size_t size);
void *memcpy(void *dst, const void *src, size_t size);
int strcmp(const char *s1, const char *s2);
char *strcpy(char *dst0, const char *src0);
#define abs(x) ((x) >= 0 ? (x) : -(x))

#endif //GUARD_LIBC_H
