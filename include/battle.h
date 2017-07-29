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
