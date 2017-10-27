#include "global.h"
//#include "evolution_graphics.h"
#include "sprite.h"
#include "trig.h"
#include "rng.h"
#include "decompress.h"
#include "task.h"
#include "sound.h"
#include "songs.h"
#include "palette.h"

static const s16 sEvoSparkleMatricies[] =
{
    0x3C0, 0x380, 0x340, 0x300, 0x2C0, 0x280, 0x240, 0x200, 0x1C0,
    0x180, 0x140, 0x100, -4, 0x10, -3, 0x30, -2, 0x50,
    -1, 0x70, 0x1, 0x70, 0x2, 0x50, 0x3, 0x30, 0x4, 0x10
};

void EvoSparkle_DummySpriteCb(struct Sprite *sprite)
{

}

void SetEvoSparklesMatrices(void)
{
    u16 i;
    for (i = 0; i < 12; i++)
    {
        SetOamMatrix(20 + i, sEvoSparkleMatricies[i], 0, 0, sEvoSparkleMatricies[i]);
    }
}
