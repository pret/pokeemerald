#include "global.h"
#include <stddef.h>

#define LBLOCKSIZE (sizeof(long))

// Nonzero if (long)X contains a NULL byte.
#define CONTAINSNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)

// Nonzero if X is not aligned on a "long" boundary.
#define UNALIGNED(X) ((long)X & (LBLOCKSIZE - 1))

void *memcpy(void *dst0, const void *src0, size_t len0)
{
	char *dst = dst0;
	const char *src = src0;
	long *aligned_dst;
	const long *aligned_src;
	unsigned int len = len0;
	
	// If the size is small, or either src or dst is unaligned,
	// then go to the byte copy loop. This should be rare.
	if(len >= 16 && !(UNALIGNED(src) | UNALIGNED(dst)))
	{
		aligned_dst = (long *)dst;
		aligned_src = (long *)src;
		
		// Copy 4X long words at a time if possible.
		while(len >= 16)
		{
			*aligned_dst++ = *aligned_src++;
			*aligned_dst++ = *aligned_src++;
			*aligned_dst++ = *aligned_src++;
			*aligned_dst++ = *aligned_src++;
			len -= 16;
		}
		
		// Copy one long word at a time if possible
		while(len >= 4)
		{
			*aligned_dst++ = *aligned_src++;
			len -= 4;
		}
		
		dst = (char *)aligned_dst;
		src = (char *)aligned_src;
	}
	
	// Pick up any remaining bytes with a byte copier.
	while(len--)
		*dst++ = *src++;
	
	return dst0;
}

void *memset(void *m, int c, size_t n)
{
	char *s = (char *)m;
	int count, i;
	unsigned long buffer;
	unsigned long *aligned_addr;
	unsigned char *unaligned_addr;
	
	// If the size is small or m is unaligned,
	// then go to the byte copy loop. This should be rare.
	if(n >= LBLOCKSIZE && !UNALIGNED(m))
	{
		// We know that n is large and m is word-aligned.
		aligned_addr = (unsigned long *)m;
		
		// Store C into each char sized location in buffer so that
		// we can set large blocks quickly.
		c &= 0xFF;
		if(LBLOCKSIZE == 4)
		{
			buffer = (c << 8) | c;
			buffer |= (buffer << 16);
		}
		else
		{
			buffer = 0;
			for(i = 0; i < LBLOCKSIZE; i++)
				buffer = (buffer << 8) | c;
		}
		
		while(n >= LBLOCKSIZE * 4)
		{
			*aligned_addr++ = buffer;
			*aligned_addr++ = buffer;
			*aligned_addr++ = buffer;
			*aligned_addr++ = buffer;
			n -= LBLOCKSIZE * 4;
		}
		while(n >= LBLOCKSIZE)
		{
			*aligned_addr++ = buffer;
			n -= LBLOCKSIZE;
		}
		
		s = (char *)aligned_addr;
	}
	
	// Pick up the remainder with a bytewise loop.
	while(n--)
		*s++ = (char)c;
	
	return m;
}

int strcmp(const char *s1, const char *s2)
{
	unsigned long *a1;
	unsigned long *a2;
	
	// If s1 or s2 are unaligned, then skip this and compare bytes.
	if(!(UNALIGNED(s1) | UNALIGNED(s2)))
	{
		// Compare them a word at a time.
		a1 = (unsigned long *)s1;
		a2 = (unsigned long *)s2;
		while(*a1 == *a2)
		{
			// If *a1 == *a2, and we find a null in *a1,
			// then the strings must be equal, so return zero.
			if(CONTAINSNULL(*a1))
				return 0;
			
			a1++;
			a2++;
		}
		
		s1 = (char *)a1;
		s2 = (char *)a2;
	}
	
	// Check the remaining few bytes.
	while(*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	
	return (*(unsigned char *) s1) - (*(unsigned char *) s2);
}

char* strcpy(char *dst0, const char *src0)
{
  char *dst = dst0;
  const char *src = src0;
	unsigned long *a1;
	const unsigned long *a2;
	
  /* If SRC or DEST is unaligned, then copy bytes.  */
	if(!(UNALIGNED(src) | UNALIGNED(dst)))
	{
		/* SRC and DEST are both "long int" aligned, try to do "long int"
         sized copies.  */
		a1 = (unsigned long *)dst;
		a2 = (unsigned long *)src;
		while(!CONTAINSNULL(*a2))
		{
      *a1++ = *a2++;
		}
		
		dst = (char *)a1;
		src = (char *)a2;
	}
	
	// Copy the remaining few bytes.
	while(*dst++ = *src++);
	
	return dst0;
}

