#include "global.h"
#include "main.h"
#include "pokeblock.h"
#include "malloc.h"

struct UsePokeblockSubStruct
{
    void *field_0;
    void (*callback)(void);
    struct Pokeblock *pokeblock;
};

struct UsePokeblockStruct1
{
    u8 field_0[0x7FD0];
    struct UsePokeblockSubStruct info;
};

extern struct UsePokeblockStruct1 *gUnknown_0203BCAC;
extern struct UsePokeblockSubStruct *gUnknown_0203BC90;

// this file's functions
void sub_816636C(void *arg0);
void sub_8166380(void);
void sub_816631C(void);

void sub_8166204(struct Pokeblock *pokeblock, void (*callback)(void))
{
    gUnknown_0203BCAC = AllocZeroed(0x806C);
    gUnknown_0203BC90 = &gUnknown_0203BCAC->info;
    gUnknown_0203BC90->pokeblock = pokeblock;
    gUnknown_0203BC90->callback = callback;
    sub_816636C(sub_8166380);
    SetMainCallback2(sub_816631C);
}
