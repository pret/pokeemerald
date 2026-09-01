#include "global.h"
#include "decompress_error_handler.h"

void DecompressionError(const u32 *src, enum CompressionError error)
{
    errorf("Decompression failed.\nAddress: 0x%p\nError: 0x%x\n", src, error);
}
