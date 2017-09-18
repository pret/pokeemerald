#ifndef GUARD_bg_H
#define GUARD_bg_H

struct BgTemplate {
    u32 bg:2;
    u32 charBaseIndex:2;
    u32 mapBaseIndex:5;
    u32 screenSize:2;
    u32 paletteMode:1;
    u32 priority:2;
    u32 baseTile:10;
};

void ResetBgsAndClearDma3BusyFlags(u32);
void InitBgsFromTemplates(u8, const struct BgTemplate *, u8);
u32 ChangeBgX(u8, u32, u8);
u32 ChangeBgY(u8, u32, u8);

#endif //GUARD_bg_H
