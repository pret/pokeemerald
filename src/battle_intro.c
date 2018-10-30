#include "global.h"
#include "task.h"

extern void task_battle_intro_80BC47C(u8);
extern void task00_battle_intro_80BC6C8(u8);
extern void task_battle_intro_80BC47C(u8);
extern void task_battle_intro_anim(u8);

const TaskFunc gUnknown_08597424[] =
{
    task_battle_intro_80BC47C,
    task_battle_intro_80BC47C,
    task00_battle_intro_80BC6C8,
    task00_battle_intro_80BC6C8,
    task00_battle_intro_80BC6C8,
    task_battle_intro_80BC47C,
    task_battle_intro_80BC47C,
    task_battle_intro_80BC47C,
    task_battle_intro_anim,
    task_battle_intro_anim,
};
