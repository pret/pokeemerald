#ifndef GUARD_BATTLE_TOWER_H
#define GUARD_BATTLE_TOWER_H

struct RSBattleTowerRecord {
    /*0x00*/ u8 battleTowerLevelType; // 0 = level 50, 1 = level 100
    /*0x01*/ u8 trainerClass;
    /*0x02*/ u16 winStreak;
    /*0x04*/ u8 name[8];
    /*0x0C*/ u8 trainerId[4];
    /*0x10*/ struct {
        u16 easyChat[6];
    } greeting;
    /*0x1C*/ struct UnknownPokemonStruct party[3];
    /*0xA0*/ u32 checksum;
    /*0xA4*/ u16 unk_11c8;
};

struct EmeraldBattleTowerRecord {
    /*0x00*/ u8 battleTowerLevelType; // 0 = level 50, 1 = level 100
    /*0x01*/ u8 trainerClass;
    /*0x02*/ u16 winStreak;
    /*0x04*/ u8 name[8];
    /*0x0C*/ u8 trainerId[4];
    /*0x10*/ struct {
        u16 easyChat[6];
    } greeting;
    /*0x1C*/ u8 filler_1c[0x18];
    /*0x34*/ struct UnknownPokemonStruct party[4];
    /*0xe4*/ u8 language;
    u8 filler_e5[7];
};

union BattleTowerRecord {
    struct RSBattleTowerRecord ruby_sapphire;
    struct EmeraldBattleTowerRecord emerald;
};

u16 sub_8164FCC(u8, u8);
void sub_81659DC(union BattleTowerRecord *a0, union BattleTowerRecord *a1);
bool32 sub_816587C(union BattleTowerRecord *, union BattleTowerRecord *);
bool32 sub_8164F70(union BattleTowerRecord *);
void sub_81628A0(union BattleTowerRecord *);

#endif //GUARD_BATTLE_TOWER_H
