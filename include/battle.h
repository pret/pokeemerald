#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

#define BATTLE_TYPE_DOUBLE          0x0001
#define BATTLE_TYPE_LINK            0x0002
#define BATTLE_TYPE_WILD            0x0004
#define BATTLE_TYPE_TRAINER         0x0008
#define BATTLE_TYPE_FIRST_BATTLE    0x0010
#define BATTLE_TYPE_20              0x0020
#define BATTLE_TYPE_40              0x0040
#define BATTLE_TYPE_SAFARI          0x0080
#define BATTLE_TYPE_BATTLE_TOWER    0x0100
#define BATTLE_TYPE_WALLY_TUTORIAL  0x0200
#define BATTLE_TYPE_ROAMER          0x0400
#define BATTLE_TYPE_EREADER_TRAINER 0x0800
#define BATTLE_TYPE_KYOGRE_GROUDON  0x1000
#define BATTLE_TYPE_LEGENDARY       0x2000
#define BATTLE_TYPE_REGI            0x4000

#define AI_ACTION_UNK1          0x0001
#define AI_ACTION_UNK2          0x0002
#define AI_ACTION_UNK3          0x0004
#define AI_ACTION_UNK4          0x0008
#define AI_ACTION_UNK5          0x0010
#define AI_ACTION_UNK6          0x0020
#define AI_ACTION_UNK7          0x0040
#define AI_ACTION_UNK8          0x0080

struct ProtectStruct
{
    /*field0*/
    u32 protected:1;
    u32 endured:1;
    u32 onlyStruggle:1;
    u32 helpingHand:1;
    u32 bounceMove:1;
    u32 stealMove:1;
    u32 flag0Unknown:1;
    u32 prlzImmobility:1;
    /*field1*/
    u32 confusionSelfDmg:1;
    u32 notEffective:1;
    u32 chargingTurn:1;
    u32 fleeFlag:2; //for RunAway and Smoke Ball
    u32 usedImprisionedMove:1;
    u32 loveImmobility:1;
    u32 usedDisabledMove:1;
    /*field2*/
    u32 usedTauntedMove:1;
    u32 flag2Unknown:1;
    u32 flinchImmobility:1;
    u32 notFirstStrike:1;
    u32 unk2_4:1;  // Probably related to the battle palace. I'm not sure.
    u32 free:3;
    /*field3*/
    u32 field3 : 8;
    u32 physicalDmg;
    u32 specialDmg;
    u8 physicalBank;
    u8 specialBank;
    u16 fieldE;
};

extern struct ProtectStruct gProtectStructs[];

struct DisableStruct
{
    /*0x00*/ u32 unk0;
    /*0x04*/ u16 disabledMove;
    /*0x06*/ u16 encoredMove;
    /*0x08*/ u8 protectUses;
    /*0x09*/ u8 stockpileCounter;
    /*0x0A*/ u8 substituteHP;
    /*0x0B*/ u8 disableTimer1 : 4;
    /*0x0B*/ u8 disableTimer2 : 4;
    /*0x0C*/ u8 encoredMovePos;
    /*0x0D*/ u8 unkD;
    /*0x0E*/ u8 encoreTimer1 : 4;
    /*0x0E*/ u8 encoreTimer2 : 4;
    /*0x0F*/ u8 perishSong1 : 4;
    /*0x0F*/ u8 perishSong2 : 4;
    /*0x10*/ u8 furyCutterCounter;
    /*0x11*/ u8 rolloutTimer1 : 4;
    /*0x11*/ u8 rolloutTimer2 : 4;
    /*0x12*/ u8 chargeTimer1 : 4;
    /*0x12*/ u8 chargeTimer2 : 4;
    /*0x13*/ u8 tauntTimer1:4;
    /*0x13*/ u8 tauntTimer2:4;
    /*0x14*/ u8 bankPreventingEscape;
    /*0x15*/ u8 bankWithSureHit;
    /*0x16*/ u8 isFirstTurn;
    /*0x17*/ u8 unk17;
    /*0x18*/ u8 truantCounter : 1;
    /*0x18*/ u8 unk18_a : 3;
    /*0x18*/ u8 unk18_b : 4;
    /*0x19*/ u8 rechargeCounter;
    /*0x1A*/ u8 unk1A[2];
};

extern struct DisableStruct gDisableStructs[];

struct FuncStack
{
    void* ptr[8];
    u8 size;
};

struct ScriptsStack
{
    u8* ptr[8];
    u8 size;
};

struct BattleStruct
{
    u8 unk0;
    u8 filler1[0x3];
    struct SimpleUnknownStruct *unk4;
    struct ScriptsStack *unk8;
    u8 fillerC[0x8];
    struct AI_ThinkingStruct *ai;
    struct UnknownStruct2 *unk18;
    struct UnknownStruct4 *unk1C;
};

extern struct BattleStruct *gBattleStruct;

#endif
