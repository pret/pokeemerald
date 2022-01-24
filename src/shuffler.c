#include "global.h"
#include "shuffler.h"
#include "random.h"
#include "tinymt32.h"

#include "printf.h"
#include "mgba.h"

void Shuffle() {
    mgba_printf(MGBA_LOG_INFO, "hello from Shuffle()!");
    tinymt32_t tinymt;
    tinymt.mat1 = 0x8f7011ee;
    tinymt.mat2 = 0xfc78ff1f;
    tinymt.tmat = 0x3793fdff;
    int seed = Random32();
    tinymt32_init(&tinymt, seed);
    mgba_printf(MGBA_LOG_INFO, "seed: %u", seed);
    for (int i = 0; i < 10; i++) {
        mgba_printf(MGBA_LOG_INFO, "%u", tinymt32_generate_uint32(&tinymt));
    }
}
