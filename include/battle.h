#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

#define BATTLE_BANKS_COUNT  4

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
#define BATTLE_TYPE_TWO_OPPONENTS   0x8000
#define BATTLE_TYPE_DOME            0x10000
#define BATTLE_TYPE_PALACE          0x20000
#define BATTLE_TYPE_ARENA           0x40000
#define BATTLE_TYPE_FACTORY         0x80000
#define BATTLE_TYPE_x100000         0x100000
#define BATTLE_TYPE_PYRAMID         0x200000
#define BATTLE_TYPE_INGAME_PARTNER  0x400000
#define BATTLE_TYPE_x800000         0x800000
#define BATTLE_TYPE_RECORDED        0x1000000
#define BATTLE_TYPE_x2000000        0x2000000
#define BATTLE_TYPE_x4000000        0x4000000
#define BATTLE_TYPE_SECRET_BASE     0x8000000
#define BATTLE_TYPE_GROUDON         0x10000000
#define BATTLE_TYPE_KYORGE          0x20000000
#define BATTLE_TYPE_RAYQUAZA        0x40000000

#define STEVEN_PARTNER_ID           0xC03
#define SECRET_BASE_OPPONENT        0x400

#define BATTLE_TYPE_FRONTIER        (BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOME | BATTLE_TYPE_PALACE | BATTLE_TYPE_ARENA | BATTLE_TYPE_FACTORY | BATTLE_TYPE_x100000 | BATTLE_TYPE_PYRAMID)

#define SIDE_PLAYER     0x0
#define SIDE_OPPONENT   0x1

#define BATTLE_WON                  0x1
#define BATTLE_LOST                 0x2
#define BATTLE_DREW                 0x3
#define BATTLE_RAN                  0x4
#define BATTLE_PLAYER_TELEPORTED    0x5
#define BATTLE_POKE_FLED            0x6
#define BATTLE_CAUGHT               0x7
#define BATTLE_OPPONENT_TELEPORTED  0xA

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

#define ABILITYEFFECT_ON_SWITCHIN               0x0
#define ABILITYEFFECT_ENDTURN                   0x1
#define ABILITYEFFECT_MOVES_BLOCK               0x2
#define ABILITYEFFECT_ABSORBING                 0x3
#define ABILITYEFFECT_CONTACT                   0x4
#define ABILITYEFFECT_IMMUNITY                  0x5
#define ABILITYEFFECT_FORECAST                  0x6
#define ABILITYEFFECT_SYNCHRONIZE               0x7
#define ABILITYEFFECT_ATK_SYNCHRONIZE           0x8
#define ABILITYEFFECT_INTIMIDATE1               0x9
#define ABILITYEFFECT_INTIMIDATE2               0xA
#define ABILITYEFFECT_TRACE                     0xB
#define ABILITYEFFECT_CHECK_OTHER_SIDE          0xC
#define ABILITYEFFECT_CHECK_BANK_SIDE           0xD
#define ABILITYEFFECT_FIELD_SPORT               0xE
#define ABILITYEFFECT_CHECK_FIELD_EXCEPT_BANK   0xF
#define ABILITYEFFECT_COUNT_OTHER_SIZE          0x10
#define ABILITYEFFECT_COUNT_BANK_SIDE           0x11
#define ABILITYEFFECT_COUNT_ON_FIELD            0x12
#define ABILITYEFFECT_CHECK_ON_FIELD            0x13

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
#define WEATHER_HAIL_ANY ((WEATHER_HAIL))

#define REQUEST_ALL_BATTLE      0x0
#define REQUEST_SPECIES_BATTLE  0x1
#define REQUEST_HELDITEM_BATTLE 0x2
#define REQUEST_MOVES_PP_BATTLE 0x3
#define REQUEST_PPMOVE1_BATTLE  0x9
#define REQUEST_PPMOVE2_BATTLE  0xA
#define REQUEST_PPMOVE3_BATTLE  0xB
#define REQUEST_PPMOVE4_BATTLE  0xC
#define REQUEST_STATUS_BATTLE   0x28
#define REQUEST_HP_BATTLE 0x2A

// array entries for battle communication
#define MOVE_EFFECT_BYTE    0x3
#define MULTISTRING_CHOOSER 0x5
#define MSG_DISPLAY         0x7

// functions

extern u8 AbilityBattleEffects(u8 caseID, u8 bank, u8 ability, u8 special, u16 moveArg);
extern u8 GetBankSide(u8 bank);

struct Trainer
{
    /*0x00*/ u8 partyFlags;
    /*0x01*/ u8 trainerClass;
    /*0x02*/ u8 encounterMusic_gender; // last bit is gender
    /*0x03*/ u8 trainerPic;
    /*0x04*/ u8 trainerName[12];
    /*0x10*/ u16 items[4];
    /*0x18*/ bool8 doubleBattle;
    /*0x1C*/ u32 aiFlags;
    /*0x20*/ u8 partySize;
    /*0x24*/ void *party;
};

extern const struct Trainer gTrainers[];

#define TRAINER_ENCOUNTER_MUSIC(trainer)((gTrainers[trainer].encounterMusic_gender & 0x7F))

struct UnknownFlags
{
    u32 flags[4];
};

#define UNKNOWN_FLAG_FLASH_FIRE 1

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

extern struct DisableStruct gDisableStructs[BATTLE_BANKS_COUNT];

struct ProtectStruct
{
    /* field_0 */
    u32 protected:1;
    u32 endured:1;
    u32 onlyStruggle:1;
    u32 helpingHand:1;
    u32 bounceMove:1;
    u32 stealMove:1;
    u32 flag0Unknown:1;
    u32 prlzImmobility:1;
    /* field_1 */
    u32 confusionSelfDmg:1;
    u32 notEffective:1;
    u32 chargingTurn:1;
    u32 fleeFlag:2; // for RunAway and Smoke Ball
    u32 usedImprisionedMove:1;
    u32 loveImmobility:1;
    u32 usedDisabledMove:1;
    /* field_2 */
    u32 usedTauntedMove:1;      // 0x1
    u32 flag2Unknown:1;         // 0x2
    u32 flinchImmobility:1;     // 0x4
    u32 notFirstStrike:1;       // 0x8
    u32 flag_x10 : 1;           // 0x10
    u32 flag_x20 : 1;           // 0x20
    u32 flag_x40 : 1;           // 0x40
    u32 flag_x80 : 1;           // 0x80
    /* field_3 */
    u32 field3 : 8;

    /* field_4 */ u32 physicalDmg;
    /* field_8 */ u32 specialDmg;
    /* field_C */ u8 physicalBank;
    /* field_D */ u8 specialBank;
    /* field_E */ u16 fieldE;
};

extern struct ProtectStruct gProtectStructs[BATTLE_BANKS_COUNT];

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

extern struct SpecialStatus gSpecialStatuses[BATTLE_BANKS_COUNT];

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

extern struct SideTimer gSideTimers[];

struct WishFutureKnock
{
    u8 futureSightCounter[BATTLE_BANKS_COUNT];
    u8 futureSightAttacker[BATTLE_BANKS_COUNT];
    s32 futureSightDmg[BATTLE_BANKS_COUNT];
    u16 futureSightMove[BATTLE_BANKS_COUNT];
    u8 wishCounter[BATTLE_BANKS_COUNT];
    u8 wishUserID[BATTLE_BANKS_COUNT];
    u8 weatherDuration;
    u16 knockedOffPokes;
};

extern struct WishFutureKnock gWishFutureKnock;

struct AI_ThinkingStruct
{
    u8 aiState;
    u8 movesetIndex;
    u16 moveConsidered;
    s8 score[4];
    u32 funcResult;
    u32 aiFlags;
    u8 aiAction;
    u8 aiLogicId;
    u8 filler12[6];
    u8 simulatedRNG[4];
};

struct UsedMoves
{
    u16 moves[BATTLE_BANKS_COUNT];
    u16 unknown[BATTLE_BANKS_COUNT];
};

struct BattleHistory
{
    struct UsedMoves usedMoves[BATTLE_BANKS_COUNT];
    u8 abilities[BATTLE_BANKS_COUNT];
    u8 itemEffects[BATTLE_BANKS_COUNT];
    u16 TrainerItems[BATTLE_BANKS_COUNT];
    u8 itemsNo;
};

struct BattleScriptsStack
{
    const u8 *ptr[8];
    u8 size;
};

struct BattleResources
{
    struct SecretBaseRecord* secretBase;
    struct UnknownFlags *flags;
    struct BattleScriptsStack* battleScriptsStack;
    void* battleCallbackStack;
    void* statsBeforeLvlUp;
    struct AI_ThinkingStruct *ai;
    struct BattleHistory *battleHistory;
    struct BattleScriptsStack *AI_ScriptsStack;
};

extern struct BattleResources* gBattleResources;

#define BATTLESCRIPTS_STACK (gBattleResources->battleScriptsStack)

struct BattleResults
{
    u8 playerFaintCounter;    // 0x0
    u8 opponentFaintCounter;  // 0x1
    u8 unk2;                  // 0x2
    u8 unk3;                  // 0x3
    u8 unk4;                  // 0x4
    u8 unk5_0:1;              // 0x5
    u8 unk5_1:1;              // 0x5
    u16 poke1Species;         // 0x6
    u8 pokeString1[10];       // 0x8
    u8 unk12;
    u8 battleTurnCounter;     // 0x13
    u8 pokeString2[10];       // 0x14
    u8 field_1E;              // 0x1E
    u8 field_1F;              // 0x1F
    u16 lastOpponentSpecies;  // 0x20
    u16 lastUsedMove;         // 0x22
    u16 opponentMove;         // 0x24
    u16 opponentSpecies;      // 0x26
    u16 caughtPoke;           // 0x28
    u8 caughtNick[10];        // 0x2A
    u8 filler34[2];
    u8 unk36[10];  // usedBalls?
};

extern struct BattleResults gBattleResults;

struct BattleStruct
{
    u8 turnEffectsTracker;
    u8 turnEffectsBank;
    u8 filler2;
    u8 turncountersTracker;
    u8 wrappedMove[8]; // ask gamefreak why they declared it that way
    u8 moveTarget[4];
    u8 expGetterId;
    u8 field_11;
    u8 wildVictorySong;
    u8 dynamicMoveType;
    u8 wrappedBy[4];
    u8 field_18;
    u8 field_19;
    u8 field_1A;
    u8 field_1B;
    u8 field_1C;
    u8 field_1D;
    u8 field_1E;
    u8 field_1F;
    u8 field_20;
    u8 field_21;
    u8 field_22;
    u8 field_23;
    u8 field_24;
    u8 field_25;
    u8 field_26;
    u8 field_27;
    u8 field_28;
    u8 field_29;
    u8 field_2A;
    u8 field_2B;
    u8 field_2C;
    u8 field_2D;
    u8 field_2E;
    u8 field_2F;
    u8 field_30;
    u8 field_31;
    u8 field_32;
    u8 field_33;
    u8 field_34;
    u8 field_35;
    u8 field_36;
    u8 field_37;
    u8 field_38;
    u8 field_39;
    u8 field_3A;
    u8 field_3B;
    u8 field_3C;
    u8 field_3D;
    u8 field_3E;
    u8 field_3F;
    u8 field_40;
    u8 field_41;
    u8 field_42;
    u8 field_43;
    u8 field_44;
    u8 field_45;
    u8 field_46;
    u8 field_47;
    u8 field_48;
    u8 field_49;
    u8 field_4A;
    u8 field_4B;
    u8 field_4C;
    u8 field_4D;
    u8 field_4E;
    u8 field_4F;
    u8 field_50;
    u8 field_51;
    u8 field_52;
    u8 field_53;
    u8 field_54;
    u8 field_55;
    u8 field_56;
    u8 field_57;
    u8 field_58;
    u8 field_59;
    u8 field_5A;
    u8 field_5B;
    u8 field_5C[4];
    u8 field_60;
    u8 field_61;
    u8 field_62;
    u8 field_63;
    u8 field_64;
    u8 field_65;
    u8 field_66;
    u8 field_67;
    u8 field_68;
    u8 field_69;
    u8 field_6A;
    u8 field_6B;
    u8 field_6C;
    u8 field_6D;
    u8 field_6E;
    u8 field_6F;
    u8 field_70;
    u8 field_71;
    u8 field_72;
    u8 field_73;
    u8 field_74;
    u8 field_75;
    u8 field_76;
    u8 field_77;
    u8 field_78;
    u8 field_79;
    u8 field_7A;
    u8 field_7B;
    u8 field_7C;
    u8 field_7D;
    u8 field_7E;
    u8 formToChangeInto;
    u8 chosenMovesIds[4];
    u8 field_84;
    u8 field_85;
    u8 field_86;
    u8 field_87;
    u8 field_88;
    u8 field_89;
    u8 field_8A;
    u8 field_8B;
    u8 field_8C;
    u8 field_8D;
    u8 field_8E;
    u8 expGetterBank;
    u8 field_90;
    u8 field_91;
    u8 field_92;
    u8 field_93;
    u8 field_94;
    u8 field_95;
    u8 field_96;
    u8 field_97;
    u8 field_98;
    u8 field_99;
    u8 field_9A;
    u8 field_9B;
    u8 field_9C;
    u8 field_9D;
    u8 field_9E;
    u8 field_9F;
    u8 field_A0;
    u8 field_A1;
    u8 field_A2;
    u8 field_A3;
    u8 field_A4;
    u8 field_A5;
    u8 field_A6;
    u8 field_A7;
    u16 hpOnSwitchout[4];
    u8 field_B0;
    u8 hpScale;
    u8 synchronizeMoveEffect;
    u8 field_B3;
    u8 field_B4;
    u8 field_B5;
    u8 field_B6;
    u8 field_B7;
    u16 usedHeldItems[4];
    u8 field_C0[8];
    u16 choicedMove[4];
    u8 field_D0[8];
    u8 intimidateBank;
    u8 fillerD9[0xDA-0xD9];
    u8 field_DA;
    u8 turnSideTracker;
    u8 fillerDC[0xDF-0xDC];
    u8 field_DF;
    u8 fillerE0[0x1A0-0xE0];
    u8 field_1A0;
    u8 field_1A1;
    u8 filler1A2;
    u8 atkCancellerTracker;
};

extern struct BattleStruct* gBattleStruct;

struct BattleScripting
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u32 bideDmg;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
    u8 field_C;
    u8 field_D;
    u8 dmgMultiplier;
    u8 field_F;
    u8 animArg1;
    u8 animArg2;
    u8 field_12;
    u8 field_13;
    u8 atk49_state;
    u8 field_15;
    u8 field_16;
    u8 bank;
};

extern struct BattleScripting gBattleScripting;

#include "sprite.h"

struct BattleSpritesGfx
{
    void* firstDecompressed; // ptr to the decompressed sprite of the first pokemon
    void* sprites[4];
    struct SpriteTemplate templates[4];
};

extern struct BattleSpritesGfx* gBattleSpritesGfx;

#endif // GUARD_BATTLE_H
