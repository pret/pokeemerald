#ifndef GUARD_HALL_OF_FAME_H
#define GUARD_HALL_OF_FAME_H

struct HallofFameMon
{
    u32 tid;
    u32 personality;
    u16 isShiny:1;
    enum Species species:15;
    u8 lvl;
    u8 nickname[POKEMON_NAME_LENGTH];
};

struct HallofFameTeam
{
    struct HallofFameMon mon[PARTY_SIZE];
};

extern struct HallofFameTeam *gHoFSaveBuffer;

void CB2_DoHallOfFameScreen(void);
void CB2_DoHallOfFameScreenDontSaveData(void);
void CB2_DoHallOfFamePC(void);

// hof_pc.c
void ReturnFromHallOfFamePC(void);

#endif // GUARD_HALL_OF_FAME_H
