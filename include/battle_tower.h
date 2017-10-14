#ifndef GUARD_BATTLE_TOWER_H
#define GUARD_BATTLE_TOWER_H

struct BattleFrontierTrainer {
    u32 trainerClass;
    u8 trainerName[8];
    u16 speechBefore[6];
    u16 speechWin[6];
    u16 speechLose[6];
    u16 *btMonPool;
};

extern struct BattleFrontierTrainer *gUnknown_0203BC88;

u16 sub_8164FCC(u8, u8);
void sub_8162614(u16, u8);
void ConvertBattleFrontierTrainerSpeechToString(u16 *words);

#endif //GUARD_BATTLE_TOWER_H
