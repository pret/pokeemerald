#ifndef GUARD_CREDITS_FRLG_H
#define GUARD_CREDITS_FRLG_H

extern bool8 gHasHallOfFameRecords;

#define CREDITSOVWLDCMD_FB 0xFB
#define CREDITSOVWLDCMD_FC 0xFC
#define CREDITSOVWLDCMD_END 0xFD
#define CREDITSOVWLDCMD_LOADMAP 0xFE
#define CREDITSOVWLDCMD_FF 0xFF

#define CREDITSOVWLDLOADMAP(_map, _x, _y, _delay)           \
    { CREDITSOVWLDCMD_LOADMAP, MAP_GROUP(_map), MAP_NUM(_map) }, \
    { _x, _y, _delay }

#define CREDITSOVWLDSCROLL(_xspeed, _yspeed, _length) \
    { _xspeed, _yspeed, _length }

#define CREDITSOVWLDEND \
    { CREDITSOVWLDCMD_END, CREDITSOVWLDCMD_END, CREDITSOVWLDCMD_END }

    
void CB2_StartCreditsSequence(void);

#endif //GUARD_CREDITS_FRLG_H
