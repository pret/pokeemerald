# How to add new AI Flags

The battle engine upgrade has rewritten the AI battle scripts to C functions to easily add new logic. This tutorial explains how to add a new AI logic flag.

## 1. Define your flag

Open `include/constants/battle_ai.h`. We have many unused flags, but you can add a new one after `AI_FLAG_SMART_SWITCHING` like so:

`#define AI_FLAG_SUPPORT   (1 << 16)`

## 2. Make your new function

Open `src/battle_ai_main.c`. Search for the array `static s16 (*const sBattleAiFuncTable[])(u8, u8, u16, s16)`. We want to add our new function to this table. Since we have defined our flag as `(1 << 16)`, find the 16th entry in the table (identifiable by the initializer, `[16]`), and replace it with:

`[16] = AI_Support,   // AI_FLAG_SUPPORT`

Define your function above the table as `static s16 AI_Support(u8 battlerAtk, u8 battlerDef, u16 move, s16 score);`

## Make your function do something

at the bottom of the file, add:
```c
static s16 AI_Support(u8 battlerAtk, u8 battlerDef, u16 move, s16 score)
{
    // Add your logic here!
}
```

## Give your trainer the correct AI flag!

And that's it!
