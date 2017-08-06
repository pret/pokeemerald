#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

#define BATTLE_TYPE_DOUBLE          0x0001
#define BATTLE_TYPE_LINK            0x0002
#define BATTLE_TYPE_WILD            0x0004
#define BATTLE_TYPE_TRAINER         0x0008
#define BATTLE_TYPE_FIRST_BATTLE    0x0010
#define BATTLE_TYPE_20              0x0020
#define BATTLE_TYPE_MULTI           0x0040
#define BATTLE_TYPE_SAFARI          0x0080
#define BATTLE_TYPE_BATTLE_TOWER    0x0100
#define BATTLE_TYPE_WALLY_TUTORIAL  0x0200
#define BATTLE_TYPE_ROAMER          0x0400
#define BATTLE_TYPE_EREADER_TRAINER 0x0800
#define BATTLE_TYPE_KYOGRE_GROUDON  0x1000
#define BATTLE_TYPE_LEGENDARY       0x2000
#define BATTLE_TYPE_REGI            0x4000
#define BATTLE_TYPE_8000            0x8000
#define BATTLE_TYPE_20000           0x20000  // Battle Palace?
#define BATTLE_TYPE_40000           0x40000
#define BATTLE_TYPE_400000          0x400000
#define BATTLE_TYPE_800000          0x800000
#define BATTLE_TYPE_10000000        0x10000000
#define BATTLE_TYPE_20000000        0x20000000

#define AI_ACTION_UNK1          0x0001
#define AI_ACTION_UNK2          0x0002
#define AI_ACTION_UNK3          0x0004
#define AI_ACTION_UNK4          0x0008
#define AI_ACTION_UNK5          0x0010
#define AI_ACTION_UNK6          0x0020
#define AI_ACTION_UNK7          0x0040
#define AI_ACTION_UNK8          0x0080

#define STATUS_SLEEP            0x7
#define STATUS_POISON           0x8
#define STATUS_BURN             0x10
#define STATUS_FREEZE           0x20
#define STATUS_PARALYSIS        0x40
#define STATUS_TOXIC_POISON     0x80
#define STATUS_TOXIC_COUNTER    0xF00

#define STATUS_PSN_ANY          ((STATUS_POISON | STATUS_TOXIC_POISON))
#define STATUS_ANY              ((STATUS_SLEEP | STATUS_POISON | STATUS_BURN | STATUS_FREEZE | STATUS_PARALYSIS | STATUS_TOXIC_POISON))

#define STATUS2_CONFUSION           0x00000007
#define STATUS2_FLINCHED            0x00000008
#define STATUS2_UPROAR              0x00000070
#define STATUS2_BIDE                0x00000300  //two bits 0x100 0x200
#define STATUS2_LOCK_CONFUSE        0x00000C00
#define STATUS2_MULTIPLETURNS       0x00001000
#define STATUS2_WRAPPED             0x0000E000
#define STATUS2_INFATUATION         0x000F0000
#define STATUS2_FOCUS_ENERGY        0x00100000
#define STATUS2_TRANSFORMED         0x00200000
#define STATUS2_RECHARGE            0x00400000
#define STATUS2_RAGE                0x00800000
#define STATUS2_SUBSTITUTE          0x01000000
#define STATUS2_DESTINY_BOND        0x02000000
#define STATUS2_ESCAPE_PREVENTION   0x04000000
#define STATUS2_NIGHTMARE           0x08000000
#define STATUS2_CURSED              0x10000000
#define STATUS2_FORESIGHT           0x20000000
#define STATUS2_DEFENSE_CURL        0x40000000
#define STATUS2_TORMENT             0x80000000

#define STATUS3_LEECHSEED_BANK          0x3
#define STATUS3_LEECHSEED               0x4
#define STATUS3_ALWAYS_HITS             0x18    //two bits
#define STATUS3_PERISH_SONG             0x20
#define STATUS3_ON_AIR                  0x40
#define STATUS3_UNDERGROUND             0x80
#define STATUS3_MINIMIZED               0x100
#define STATUS3_ROOTED                  0x400
#define STATUS3_CHARGED_UP              0x200
#define STATUS3_YAWN                    0x1800  //two bits
#define STATUS3_IMPRISIONED             0x2000
#define STATUS3_GRUDGE                  0x4000
#define STATUS3_CANT_SCORE_A_CRIT       0x8000
#define STATUS3_MUDSPORT                0x10000
#define STATUS3_WATERSPORT              0x20000
#define STATUS3_UNDERWATER              0x40000
#define STATUS3_INTIMIDATE_POKES        0x80000
#define STATUS3_TRACE                   0x100000

#define STATUS3_SEMI_INVULNERABLE       ((STATUS3_UNDERGROUND | STATUS3_ON_AIR | STATUS3_UNDERWATER))

#define HITMARKER_x20                   0x00000020
#define HITMARKER_DESTINYBOND           0x00000040
#define HITMARKER_NO_ANIMATIONS         0x00000080
#define HITMARKER_IGNORE_SUBSTITUTE     0x00000100
#define HITMARKER_NO_ATTACKSTRING       0x00000200
#define HITMARKER_ATTACKSTRING_PRINTED  0x00000400
#define HITMARKER_NO_PPDEDUCT           0x00000800
#define HITMARKER_PURSUIT_TRAP          0x00001000
#define HITMARKER_IGNORE_SAFEGUARD      0x00002000
#define HITMARKER_SYNCHRONISE_EFFECT    0x00004000
#define HITMARKER_IGNORE_ON_AIR         0x00010000
#define HITMARKER_IGNORE_UNDERGROUND    0x00020000
#define HITMARKER_IGNORE_UNDERWATER     0x00040000
#define HITMARKER_UNABLE_TO_USE_MOVE    0x00080000
#define HITMARKER_x100000               0x00100000
#define HITMARKER_x200000               0x00200000
#define HITMARKER_x400000               0x00400000
#define HITMARKER_x800000               0x00800000
#define HITMARKER_GRUDGE                0x01000000
#define HITMARKER_OBEYS                 0x02000000
#define HITMARKER_x8000000              0x08000000
#define HITMARKER_FAINTED(bank)         ((gBitTable[bank] << 0x1C))
#define HITMARKER_UNK(bank)             ((0x10000000 << bank))

#define SIDE_STATUS_REFLECT          (1 << 0)
#define SIDE_STATUS_LIGHTSCREEN      (1 << 1)
#define SIDE_STATUS_X4               (1 << 2)
#define SIDE_STATUS_SPIKES           (1 << 4)
#define SIDE_STATUS_SAFEGUARD        (1 << 5)
#define SIDE_STATUS_FUTUREATTACK     (1 << 6)
#define SIDE_STATUS_MIST             (1 << 8)
#define SIDE_STATUS_SPIKES_DAMAGED   (1 << 9)

#define ABILITYEFFECT_ON_SWITCHIN         0x0
#define ABILITYEFFECT_ENDTURN             0x1
#define ABILITYEFFECT_MOVES_BLOCK         0x2
#define ABILITYEFFECT_ABSORBING           0x3
#define ABILITYEFFECT_CONTACT             0x4
#define ABILITYEFFECT_IMMUNITY            0x5
#define ABILITYEFFECT_FORECAST            0x6
#define ABILITYEFFECT_SYNCHRONIZE         0x7
#define ABILITYEFFECT_ATK_SYNCHRONIZE     0x8
#define ABILITYEFFECT_INTIMIDATE1         0x9
#define ABILITYEFFECT_INTIMIDATE2         0xA
#define ABILITYEFFECT_TRACE               0xB
#define ABILITYEFFECT_CHECK_OTHER_SIDE    0xC
#define ABILITYEFFECT_CHECK_BANK_SIDE     0xD
#define ABILITYEFFECT_FIELD_SPORT         0xE
#define ABILITYEFFECT_CHECK_FIELD_EXCEPT_BANK   0xF
#define ABILITYEFFECT_COUNT_OTHER_SIZE    0x10
#define ABILITYEFFECT_COUNT_BANK_SIDE     0x11
#define ABILITYEFFECT_COUNT_ON_FIELD      0x12
#define ABILITYEFFECT_CHECK_ON_FIELD      0x13

#define WEATHER_HAS_EFFECT ((!AbilityBattleEffects(ABILITYEFFECT_CHECK_ON_FIELD, 0, ABILITY_CLOUD_NINE, 0, 0) && !AbilityBattleEffects(ABILITYEFFECT_CHECK_ON_FIELD, 0, ABILITY_AIR_LOCK, 0, 0)))

#define MOVESTATUS_MISSED             (1 << 0)
#define MOVESTATUS_SUPEREFFECTIVE     (1 << 1)
#define MOVESTATUS_NOTVERYEFFECTIVE   (1 << 2)
#define MOVESTATUS_NOTAFFECTED        (1 << 3)
#define MOVESTATUS_ONEHITKO           (1 << 4)
#define MOVESTATUS_FAILED             (1 << 5)
#define MOVESTATUS_ENDURED            (1 << 6)
#define MOVESTATUS_HUNGON             (1 << 7)

#define MOVESTATUS_NOEFFECT ((MOVESTATUS_MISSED | MOVESTATUS_NOTAFFECTED | MOVESTATUS_FAILED))

#define MAX_TRAINER_ITEMS 4
#define MAX_MON_MOVES 4
#define MAX_BANKS_BATTLE 4

#define WEATHER_RAIN_TEMPORARY      (1 << 0)
#define WEATHER_RAIN_DOWNPOUR       (1 << 1)
#define WEATHER_RAIN_PERMANENT      (1 << 2)
#define WEATHER_RAIN_ANY ((WEATHER_RAIN_TEMPORARY | WEATHER_RAIN_DOWNPOUR | WEATHER_RAIN_PERMANENT))
#define WEATHER_SANDSTORM_TEMPORARY (1 << 3)
#define WEATHER_SANDSTORM_PERMANENT (1 << 4)
#define WEATHER_SANDSTORM_ANY ((WEATHER_SANDSTORM_TEMPORARY | WEATHER_SANDSTORM_PERMANENT))
#define WEATHER_SUN_TEMPORARY       (1 << 5)
#define WEATHER_SUN_PERMANENT       (1 << 6)
#define WEATHER_SUN_ANY ((WEATHER_SUN_TEMPORARY | WEATHER_SUN_PERMANENT))
#define WEATHER_HAIL                (1 << 7)

#define REQUEST_ALL_BATTLE      0x0
#define REQUEST_SPECIES_BATTLE  0x1
#define REQUEST_HELDITEM_BATTLE 0x2
#define REQUEST_MOVES_PP_BATTLE 0x3
#define REQUEST_PPMOVE1_BATTLE  0x9
#define REQUEST_PPMOVE2_BATTLE  0xA
#define REQUEST_PPMOVE3_BATTLE  0xB
#define REQUEST_PPMOVE4_BATTLE  0xC
#define REQUEST_STATUS_BATTLE   0x28
#define REQUEST_HP_BATTLE       0x2A

struct WishFutureKnock
{
    u8 futureSightCounter[MAX_BANKS_BATTLE];
    u8 futureSightAttacker[MAX_BANKS_BATTLE];
    s32 futureSightDmg[MAX_BANKS_BATTLE];
    u16 futureSightMove[MAX_BANKS_BATTLE];
    u8 wishCounter[MAX_BANKS_BATTLE];
    u8 wishUserID[MAX_BANKS_BATTLE];
    u8 weatherDuration;
    u16 knockedOffPokes;
};

extern struct WishFutureKnock gWishFutureKnock;

struct SideTimer
{
    /*0x00*/ u8 reflectTimer;
    /*0x01*/ u8 reflectBank;
    /*0x02*/ u8 lightscreenTimer;
    /*0x03*/ u8 lightscreenBank;
    /*0x04*/ u8 mistTimer;
    /*0x05*/ u8 mistBank;
    /*0x06*/ u8 safeguardTimer;
    /*0x07*/ u8 safeguardBank;
    /*0x08*/ u8 followmeTimer;
    /*0x09*/ u8 followmeTarget;
    /*0x0A*/ u8 spikesAmount;
    /*0x0B*/ u8 fieldB;
};

extern struct SideTimer gSideTimer[];

struct BattleEnigmaBerry
{
    /*0x00*/ u8 name[7];
    /*0x07*/ u8 holdEffect;
    /*0x08*/ u8 itemEffect[18];
    /*0x1A*/ u8 holdEffectParam;
};

extern struct BattleEnigmaBerry gEnigmaBerries[];

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

struct SpecialStatus
{
    u8 statLowered : 1;
    u8 lightningRodRedirected : 1;
    u8 restoredBankSprite: 1;
    u8 intimidatedPoke : 1;
    u8 traced : 1;
    u8 flag20 : 1;
    u8 flag40 : 1;
    u8 focusBanded : 1;
    u8 field1[3];
    s32 moveturnLostHP;
    s32 moveturnLostHP_physical;
    s32 moveturnLostHP_special;
    u8 moveturnPhysicalBank;
    u8 moveturnSpecialBank;
    u8 field12;
    u8 field13;
};

extern struct SpecialStatus gSpecialStatuses[];

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
