#ifndef GUARD_unknown_task_H
#define GUARD_unknown_task_H

// Exported type declarations
struct UnknownTaskStruct
{
    volatile void *dest;
    u32 control;
    u8 unk8;
    u8 unk9;
};

extern struct UnknownTaskStruct gUnknown_0831AC70;

// Exported RAM declarations

// Exported ROM declarations
void remove_some_task(void);
void sub_80BA038(struct UnknownTaskStruct arg0);

#endif // GUARD_unknown_task_H
