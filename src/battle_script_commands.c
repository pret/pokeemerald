#include "global.h"
#include "battle.h"
#include "battle_message.h"
#include "battle_anim.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_scripts.h"
#include "battle_z_move.h"
#include "constants/moves.h"
#include "constants/abilities.h"
#include "item.h"
#include "util.h"
#include "pokemon.h"
#include "random.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "text.h"
#include "sound.h"
#include "pokedex.h"
#include "recorded_battle.h"
#include "window.h"
#include "reshow_battle_screen.h"
#include "main.h"
#include "palette.h"
#include "money.h"
#include "malloc.h"
#include "bg.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "level_caps.h"
#include "m4a.h"
#include "mail.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "task.h"
#include "naming_screen.h"
#include "battle_setup.h"
#include "overworld.h"
#include "wild_encounter.h"
#include "rtc.h"
#include "party_menu.h"
#include "battle_arena.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "field_specials.h"
#include "pokemon_summary_screen.h"
#include "pokenav.h"
#include "menu_specialized.h"
#include "data.h"
#include "constants/abilities.h"
#include "constants/battle_anim.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_partner.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/item_effects.h"
#include "constants/map_types.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "battle_util.h"
#include "constants/pokemon.h"
#include "config/battle.h"
#include "data/battle_move_effects.h"

// table to avoid ugly powing on gba (courtesy of doesnt)
// this returns (i^2.5)/4
// the quarters cancel so no need to re-quadruple them in actual calculation
static const s32 sExperienceScalingFactors[] =
{
    0,
    0,
    1,
    3,
    8,
    13,
    22,
    32,
    45,
    60,
    79,
    100,
    124,
    152,
    183,
    217,
    256,
    297,
    343,
    393,
    447,
    505,
    567,
    634,
    705,
    781,
    861,
    946,
    1037,
    1132,
    1232,
    1337,
    1448,
    1563,
    1685,
    1811,
    1944,
    2081,
    2225,
    2374,
    2529,
    2690,
    2858,
    3031,
    3210,
    3396,
    3587,
    3786,
    3990,
    4201,
    4419,
    4643,
    4874,
    5112,
    5357,
    5608,
    5866,
    6132,
    6404,
    6684,
    6971,
    7265,
    7566,
    7875,
    8192,
    8515,
    8847,
    9186,
    9532,
    9886,
    10249,
    10619,
    10996,
    11382,
    11776,
    12178,
    12588,
    13006,
    13433,
    13867,
    14310,
    14762,
    15222,
    15690,
    16167,
    16652,
    17146,
    17649,
    18161,
    18681,
    19210,
    19748,
    20295,
    20851,
    21417,
    21991,
    22574,
    23166,
    23768,
    24379,
    25000,
    25629,
    26268,
    26917,
    27575,
    28243,
    28920,
    29607,
    30303,
    31010,
    31726,
    32452,
    33188,
    33934,
    34689,
    35455,
    36231,
    37017,
    37813,
    38619,
    39436,
    40262,
    41099,
    41947,
    42804,
    43673,
    44551,
    45441,
    46340,
    47251,
    48172,
    49104,
    50046,
    50999,
    51963,
    52938,
    53924,
    54921,
    55929,
    56947,
    57977,
    59018,
    60070,
    61133,
    62208,
    63293,
    64390,
    65498,
    66618,
    67749,
    68891,
    70045,
    71211,
    72388,
    73576,
    74777,
    75989,
    77212,
    78448,
    79695,
    80954,
    82225,
    83507,
    84802,
    86109,
    87427,
    88758,
    90101,
    91456,
    92823,
    94202,
    95593,
    96997,
    98413,
    99841,
    101282,
    102735,
    104201,
    105679,
    107169,
    108672,
    110188,
    111716,
    113257,
    114811,
    116377,
    117956,
    119548,
    121153,
    122770,
    124401,
    126044,
    127700,
    129369,
    131052,
    132747,
    134456,
    136177,
    137912,
    139660,
    141421,
    143195,
    144983,
    146784,
    148598,
    150426,
    152267,
    154122,
    155990,
    157872,
    159767,
};

static const u16 sTrappingMoves[NUM_TRAPPING_MOVES] =
{
    MOVE_BIND,
    MOVE_WRAP,
    MOVE_FIRE_SPIN,
    MOVE_CLAMP,
    MOVE_WHIRLPOOL,
    MOVE_SAND_TOMB,
    MOVE_MAGMA_STORM,
    MOVE_INFESTATION,
    MOVE_SNAP_TRAP,
    MOVE_THUNDER_CAGE
};

static const u16 sBadgeFlags[8] = {
    FLAG_BADGE01_GET, FLAG_BADGE02_GET, FLAG_BADGE03_GET, FLAG_BADGE04_GET,
    FLAG_BADGE05_GET, FLAG_BADGE06_GET, FLAG_BADGE07_GET, FLAG_BADGE08_GET,
};

static const u16 sWhiteOutBadgeMoney[9] = { 8, 16, 24, 36, 48, 64, 80, 100, 120 };

#define STAT_CHANGE_WORKED      0
#define STAT_CHANGE_DIDNT_WORK  1

#define LEVEL_UP_BANNER_START 416
#define LEVEL_UP_BANNER_END   512

#define TAG_LVLUP_BANNER_MON_ICON 55130

static void TrySetDestinyBondToHappen(void);
static u32 ChangeStatBuffs(s8 statValue, u32 statId, u32 flags, const u8 *BS_ptr);
static bool32 IsMonGettingExpSentOut(void);
static void InitLevelUpBanner(void);
static bool8 SlideInLevelUpBanner(void);
static bool8 SlideOutLevelUpBanner(void);
static void DrawLevelUpWindow1(void);
static void DrawLevelUpWindow2(void);
static void PutMonIconOnLvlUpBanner(void);
static void DrawLevelUpBannerText(void);
static void SpriteCB_MonIconOnLvlUpBanner(struct Sprite *sprite);
static bool32 CriticalCapture(u32 odds);
static void BestowItem(u32 battlerAtk, u32 battlerDef);
static bool8 IsFinalStrikeEffect(u32 moveEffect);
static void TryUpdateRoundTurnOrder(void);
static bool32 ChangeOrderTargetAfterAttacker(void);
void ApplyExperienceMultipliers(s32 *expAmount, u8 expGetterMonId, u8 faintedBattler);
static void RemoveAllWeather(void);
static void RemoveAllTerrains(void);
static bool8 CanAbilityPreventStatLoss(u16 abilityDef);
static bool8 CanBurnHitThaw(u16 move);
static u32 GetNextTarget(u32 moveTarget, bool32 excludeCurrent);
static void TryUpdateEvolutionTracker(u32 evolutionMethod, u32 upAmount, u16 usedMove);
static void AccuracyCheck(bool32 recalcDragonDarts, const u8 *nextInstr, const u8 *failInstr, u16 move);
static void SaveBattlerAttacker(u32 battler);
static void SaveBattlerTarget(u32 battler);

static void Cmd_attackcanceler(void);
static void Cmd_accuracycheck(void);
static void Cmd_attackstring(void);
static void Cmd_ppreduce(void);
static void Cmd_critcalc(void);
static void Cmd_damagecalc(void);
static void Cmd_typecalc(void);
static void Cmd_adjustdamage(void);
static void Cmd_multihitresultmessage(void);
static void Cmd_attackanimation(void);
static void Cmd_waitanimation(void);
static void Cmd_healthbarupdate(void);
static void Cmd_datahpupdate(void);
static void Cmd_critmessage(void);
static void Cmd_effectivenesssound(void);
static void Cmd_resultmessage(void);
static void Cmd_printstring(void);
static void Cmd_printselectionstring(void);
static void Cmd_waitmessage(void);
static void Cmd_printfromtable(void);
static void Cmd_printselectionstringfromtable(void);
static void Cmd_setadditionaleffects(void);
static void Cmd_seteffectprimary(void);
static void Cmd_seteffectsecondary(void);
static void Cmd_clearstatusfromeffect(void);
static void Cmd_tryfaintmon(void);
static void Cmd_dofaintanimation(void);
static void Cmd_cleareffectsonfaint(void);
static void Cmd_jumpifstatus(void);
static void Cmd_jumpifstatus2(void);
static void Cmd_jumpifability(void);
static void Cmd_jumpifsideaffecting(void);
static void Cmd_jumpifstat(void);
static void Cmd_jumpifstatus3condition(void);
static void Cmd_jumpbasedontype(void);
static void Cmd_getexp(void);
static void Cmd_checkteamslost(void);
static void Cmd_movevaluescleanup(void);
static void Cmd_setmultihit(void);
static void Cmd_decrementmultihit(void);
static void Cmd_goto(void);
static void Cmd_jumpifbyte(void);
static void Cmd_jumpifhalfword(void);
static void Cmd_jumpifword(void);
static void Cmd_jumpifarrayequal(void);
static void Cmd_jumpifarraynotequal(void);
static void Cmd_setbyte(void);
static void Cmd_addbyte(void);
static void Cmd_subbyte(void);
static void Cmd_copyarray(void);
static void Cmd_copyarraywithindex(void);
static void Cmd_orbyte(void);
static void Cmd_orhalfword(void);
static void Cmd_orword(void);
static void Cmd_bicbyte(void);
static void Cmd_bichalfword(void);
static void Cmd_bicword(void);
static void Cmd_pause(void);
static void Cmd_waitstate(void);
static void Cmd_healthbar_update(void);
static void Cmd_return(void);
static void Cmd_end(void);
static void Cmd_end2(void);
static void Cmd_end3(void);
static void Cmd_unused5(void);
static void Cmd_call(void);
static void Cmd_setroost(void);
static void Cmd_jumpifabilitypresent(void);
static void Cmd_endselectionscript(void);
static void Cmd_playanimation(void);
static void Cmd_playanimation_var(void);
static void Cmd_setgraphicalstatchangevalues(void);
static void Cmd_playstatchangeanimation(void);
static void Cmd_moveend(void);
static void Cmd_sethealblock(void);
static void Cmd_returnatktoball(void);
static void Cmd_getswitchedmondata(void);
static void Cmd_switchindataupdate(void);
static void Cmd_switchinanim(void);
static void Cmd_jumpifcantswitch(void);
static void Cmd_openpartyscreen(void);
static void Cmd_switchhandleorder(void);
static void Cmd_switchineffects(void);
static void Cmd_trainerslidein(void);
static void Cmd_playse(void);
static void Cmd_fanfare(void);
static void Cmd_playfaintcry(void);
static void Cmd_endlinkbattle(void);
static void Cmd_returntoball(void);
static void Cmd_handlelearnnewmove(void);
static void Cmd_yesnoboxlearnmove(void);
static void Cmd_yesnoboxstoplearningmove(void);
static void Cmd_hitanimation(void);
static void Cmd_getmoneyreward(void);
static void Cmd_updatebattlermoves(void);
static void Cmd_swapattackerwithtarget(void);
static void Cmd_incrementgamestat(void);
static void Cmd_drawpartystatussummary(void);
static void Cmd_hidepartystatussummary(void);
static void Cmd_jumptocalledmove(void);
static void Cmd_statusanimation(void);
static void Cmd_status2animation(void);
static void Cmd_chosenstatusanimation(void);
static void Cmd_yesnobox(void);
static void Cmd_cancelallactions(void);
static void Cmd_setgravity(void);
static void Cmd_removeitem(void);
static void Cmd_atknameinbuff1(void);
static void Cmd_drawlvlupbox(void);
static void Cmd_resetsentmonsvalue(void);
static void Cmd_setatktoplayer0(void);
static void Cmd_makevisible(void);
static void Cmd_recordability(void);
static void Cmd_buffermovetolearn(void);
static void Cmd_jumpifplayerran(void);
static void Cmd_hpthresholds(void);
static void Cmd_hpthresholds2(void);
static void Cmd_useitemonopponent(void);
static void Cmd_various(void);
static void Cmd_setprotectlike(void);
static void Cmd_tryexplosion(void);
static void Cmd_setatkhptozero(void);
static void Cmd_jumpifnexttargetvalid(void);
static void Cmd_tryhealhalfhealth(void);
static void Cmd_trymirrormove(void);
static void Cmd_setfieldweather(void);
static void Cmd_setreflect(void);
static void Cmd_setseeded(void);
static void Cmd_manipulatedamage(void);
static void Cmd_trysetrest(void);
static void Cmd_jumpifnotfirstturn(void);
static void Cmd_setmiracleeye(void);
static void Cmd_jumpifuproarwakes(void);
static void Cmd_stockpile(void);
static void Cmd_stockpiletobasedamage(void);
static void Cmd_stockpiletohpheal(void);
static void Cmd_setdrainedhp(void);
static void Cmd_statbuffchange(void);
static void Cmd_normalisebuffs(void);
static void Cmd_setbide(void);
static void Cmd_twoturnmoveschargestringandanimation(void);
static void Cmd_setmultihitcounter(void);
static void Cmd_initmultihitstring(void);
static void Cmd_forcerandomswitch(void);
static void Cmd_tryconversiontypechange(void);
static void Cmd_givepaydaymoney(void);
static void Cmd_setlightscreen(void);
static void Cmd_tryKO(void);
static void Cmd_damagetohalftargethp(void);
static void Cmd_unused_95(void);
static void Cmd_unused_96(void);
static void Cmd_tryinfatuating(void);
static void Cmd_updatestatusicon(void);
static void Cmd_setmist(void);
static void Cmd_setfocusenergy(void);
static void Cmd_transformdataexecution(void);
static void Cmd_setsubstitute(void);
static void Cmd_mimicattackcopy(void);
static void Cmd_metronome(void);
static void Cmd_dmgtolevel(void);
static void Cmd_psywavedamageeffect(void);
static void Cmd_counterdamagecalculator(void);
static void Cmd_mirrorcoatdamagecalculator(void);
static void Cmd_disablelastusedattack(void);
static void Cmd_trysetencore(void);
static void Cmd_painsplitdmgcalc(void);
static void Cmd_settypetorandomresistance(void);
static void Cmd_setalwayshitflag(void);
static void Cmd_copymovepermanently(void);
static void Cmd_trychoosesleeptalkmove(void);
static void Cmd_setdestinybond(void);
static void Cmd_trysetdestinybondtohappen(void);
static void Cmd_settailwind(void);
static void Cmd_tryspiteppreduce(void);
static void Cmd_healpartystatus(void);
static void Cmd_cursetarget(void);
static void Cmd_trysetspikes(void);
static void Cmd_setforesight(void);
static void Cmd_trysetperishsong(void);
static void Cmd_handlerollout(void);
static void Cmd_jumpifconfusedandstatmaxed(void);
static void Cmd_handlefurycutter(void);
static void Cmd_setembargo(void);
static void Cmd_presentdamagecalculation(void);
static void Cmd_setsafeguard(void);
static void Cmd_magnitudedamagecalculation(void);
static void Cmd_jumpifnopursuitswitchdmg(void);
static void Cmd_unused_bb(void);
static void Cmd_halvehp(void);
static void Cmd_copyfoestats(void);
static void Cmd_rapidspinfree(void);
static void Cmd_setdefensecurlbit(void);
static void Cmd_recoverbasedonsunlight(void);
static void Cmd_setstickyweb(void);
static void Cmd_selectfirstvalidtarget(void);
static void Cmd_trysetfutureattack(void);
static void Cmd_trydobeatup(void);
static void Cmd_setsemiinvulnerablebit(void);
static void Cmd_tryfiretwoturnmovenowbyeffect(void);
static void Cmd_setminimize(void);
static void Cmd_unused_c8(void);
static void Cmd_trymemento(void);
static void Cmd_setforcedtarget(void);
static void Cmd_setcharge(void);
static void Cmd_callterrainattack(void);
static void Cmd_cureifburnedparalysedorpoisoned(void);
static void Cmd_settorment(void);
static void Cmd_jumpifnodamage(void);
static void Cmd_settaunt(void);
static void Cmd_trysethelpinghand(void);
static void Cmd_tryswapitems(void);
static void Cmd_trycopyability(void);
static void Cmd_trywish(void);
static void Cmd_settoxicspikes(void);
static void Cmd_setgastroacid(void);
static void Cmd_setyawn(void);
static void Cmd_setdamagetohealthdifference(void);
static void Cmd_setroom(void);
static void Cmd_tryswapabilities(void);
static void Cmd_tryimprison(void);
static void Cmd_setstealthrock(void);
static void Cmd_setuserstatus3(void);
static void Cmd_assistattackselect(void);
static void Cmd_trysetmagiccoat(void);
static void Cmd_trysetsnatch(void);
static void Cmd_unused2(void);
static void Cmd_switchoutabilities(void);
static void Cmd_jumpifhasnohp(void);
static void Cmd_jumpifnotcurrentmoveargtype(void);
static void Cmd_pickup(void);
static void Cmd_unused3(void);
static void Cmd_unused4(void);
static void Cmd_settypebasedhalvers(void);
static void Cmd_jumpifsubstituteblocks(void);
static void Cmd_tryrecycleitem(void);
static void Cmd_settypetoterrain(void);
static void Cmd_pursuitdoubles(void);
static void Cmd_snatchsetbattlers(void);
static void Cmd_removelightscreenreflect(void);
static void Cmd_handleballthrow(void);
static void Cmd_givecaughtmon(void);
static void Cmd_trysetcaughtmondexflags(void);
static void Cmd_displaydexinfo(void);
static void Cmd_trygivecaughtmonnick(void);
static void Cmd_subattackerhpbydmg(void);
static void Cmd_removeattackerstatus1(void);
static void Cmd_finishaction(void);
static void Cmd_finishturn(void);
static void Cmd_trainerslideout(void);
static void Cmd_settelekinesis(void);
static void Cmd_swapstatstages(void);
static void Cmd_averagestats(void);
static void Cmd_jumpifoppositegenders(void);
static void Cmd_unused(void);
static void Cmd_tryworryseed(void);
static void Cmd_callnative(void);

void (* const gBattleScriptingCommandsTable[])(void) =
{
    Cmd_attackcanceler,                          //0x0
    Cmd_accuracycheck,                           //0x1
    Cmd_attackstring,                            //0x2
    Cmd_ppreduce,                                //0x3
    Cmd_critcalc,                                //0x4
    Cmd_damagecalc,                              //0x5
    Cmd_typecalc,                                //0x6
    Cmd_adjustdamage,                            //0x7
    Cmd_multihitresultmessage,                   //0x8
    Cmd_attackanimation,                         //0x9
    Cmd_waitanimation,                           //0xA
    Cmd_healthbarupdate,                         //0xB
    Cmd_datahpupdate,                            //0xC
    Cmd_critmessage,                             //0xD
    Cmd_effectivenesssound,                      //0xE
    Cmd_resultmessage,                           //0xF
    Cmd_printstring,                             //0x10
    Cmd_printselectionstring,                    //0x11
    Cmd_waitmessage,                             //0x12
    Cmd_printfromtable,                          //0x13
    Cmd_printselectionstringfromtable,           //0x14
    Cmd_setadditionaleffects,                    //0x15
    Cmd_seteffectprimary,                        //0x16
    Cmd_seteffectsecondary,                      //0x17
    Cmd_clearstatusfromeffect,                   //0x18
    Cmd_tryfaintmon,                             //0x19
    Cmd_dofaintanimation,                        //0x1A
    Cmd_cleareffectsonfaint,                     //0x1B
    Cmd_jumpifstatus,                            //0x1C
    Cmd_jumpifstatus2,                           //0x1D
    Cmd_jumpifability,                           //0x1E
    Cmd_jumpifsideaffecting,                     //0x1F
    Cmd_jumpifstat,                              //0x20
    Cmd_jumpifstatus3condition,                  //0x21
    Cmd_jumpbasedontype,                         //0x22
    Cmd_getexp,                                  //0x23
    Cmd_checkteamslost,                          //0x24
    Cmd_movevaluescleanup,                       //0x25
    Cmd_setmultihit,                             //0x26
    Cmd_decrementmultihit,                       //0x27
    Cmd_goto,                                    //0x28
    Cmd_jumpifbyte,                              //0x29
    Cmd_jumpifhalfword,                          //0x2A
    Cmd_jumpifword,                              //0x2B
    Cmd_jumpifarrayequal,                        //0x2C
    Cmd_jumpifarraynotequal,                     //0x2D
    Cmd_setbyte,                                 //0x2E
    Cmd_addbyte,                                 //0x2F
    Cmd_subbyte,                                 //0x30
    Cmd_copyarray,                               //0x31
    Cmd_copyarraywithindex,                      //0x32
    Cmd_orbyte,                                  //0x33
    Cmd_orhalfword,                              //0x34
    Cmd_orword,                                  //0x35
    Cmd_bicbyte,                                 //0x36
    Cmd_bichalfword,                             //0x37
    Cmd_bicword,                                 //0x38
    Cmd_pause,                                   //0x39
    Cmd_waitstate,                               //0x3A
    Cmd_healthbar_update,                        //0x3B
    Cmd_return,                                  //0x3C
    Cmd_end,                                     //0x3D
    Cmd_end2,                                    //0x3E
    Cmd_end3,                                    //0x3F
    Cmd_unused5,                                 //0x40
    Cmd_call,                                    //0x41
    Cmd_setroost,                                //0x42
    Cmd_jumpifabilitypresent,                    //0x43
    Cmd_endselectionscript,                      //0x44
    Cmd_playanimation,                           //0x45
    Cmd_playanimation_var,                       //0x46
    Cmd_setgraphicalstatchangevalues,            //0x47
    Cmd_playstatchangeanimation,                 //0x48
    Cmd_moveend,                                 //0x49
    Cmd_sethealblock,                            //0x4A
    Cmd_returnatktoball,                         //0x4B
    Cmd_getswitchedmondata,                      //0x4C
    Cmd_switchindataupdate,                      //0x4D
    Cmd_switchinanim,                            //0x4E
    Cmd_jumpifcantswitch,                        //0x4F
    Cmd_openpartyscreen,                         //0x50
    Cmd_switchhandleorder,                       //0x51
    Cmd_switchineffects,                         //0x52
    Cmd_trainerslidein,                          //0x53
    Cmd_playse,                                  //0x54
    Cmd_fanfare,                                 //0x55
    Cmd_playfaintcry,                            //0x56
    Cmd_endlinkbattle,                           //0x57
    Cmd_returntoball,                            //0x58
    Cmd_handlelearnnewmove,                      //0x59
    Cmd_yesnoboxlearnmove,                       //0x5A
    Cmd_yesnoboxstoplearningmove,                //0x5B
    Cmd_hitanimation,                            //0x5C
    Cmd_getmoneyreward,                          //0x5D
    Cmd_updatebattlermoves,                      //0x5E
    Cmd_swapattackerwithtarget,                  //0x5F
    Cmd_incrementgamestat,                       //0x60
    Cmd_drawpartystatussummary,                  //0x61
    Cmd_hidepartystatussummary,                  //0x62
    Cmd_jumptocalledmove,                        //0x63
    Cmd_statusanimation,                         //0x64
    Cmd_status2animation,                        //0x65
    Cmd_chosenstatusanimation,                   //0x66
    Cmd_yesnobox,                                //0x67
    Cmd_cancelallactions,                        //0x68
    Cmd_setgravity,                              //0x69
    Cmd_removeitem,                              //0x6A
    Cmd_atknameinbuff1,                          //0x6B
    Cmd_drawlvlupbox,                            //0x6C
    Cmd_resetsentmonsvalue,                      //0x6D
    Cmd_setatktoplayer0,                         //0x6E
    Cmd_makevisible,                             //0x6F
    Cmd_recordability,                           //0x70
    Cmd_buffermovetolearn,                       //0x71
    Cmd_jumpifplayerran,                         //0x72
    Cmd_hpthresholds,                            //0x73
    Cmd_hpthresholds2,                           //0x74
    Cmd_useitemonopponent,                       //0x75
    Cmd_various,                                 //0x76
    Cmd_setprotectlike,                          //0x77
    Cmd_tryexplosion,                            //0x78
    Cmd_setatkhptozero,                          //0x79
    Cmd_jumpifnexttargetvalid,                   //0x7A
    Cmd_tryhealhalfhealth,                       //0x7B
    Cmd_trymirrormove,                           //0x7C
    Cmd_setfieldweather,                         //0x7D
    Cmd_setreflect,                              //0x7E
    Cmd_setseeded,                               //0x7F
    Cmd_manipulatedamage,                        //0x80
    Cmd_trysetrest,                              //0x81
    Cmd_jumpifnotfirstturn,                      //0x82
    Cmd_setmiracleeye,                           //0x83
    Cmd_jumpifuproarwakes,                       //0x84
    Cmd_stockpile,                               //0x85
    Cmd_stockpiletobasedamage,                   //0x86
    Cmd_stockpiletohpheal,                       //0x87
    Cmd_setdrainedhp,                            //0x88
    Cmd_statbuffchange,                          //0x89
    Cmd_normalisebuffs,                          //0x8A
    Cmd_setbide,                                 //0x8B
    Cmd_twoturnmoveschargestringandanimation,    //0x8C
    Cmd_setmultihitcounter,                      //0x8D
    Cmd_initmultihitstring,                      //0x8E
    Cmd_forcerandomswitch,                       //0x8F
    Cmd_tryconversiontypechange,                 //0x90
    Cmd_givepaydaymoney,                         //0x91
    Cmd_setlightscreen,                          //0x92
    Cmd_tryKO,                                   //0x93
    Cmd_damagetohalftargethp,                    //0x94
    Cmd_unused_95,                               //0x95
    Cmd_unused_96,                               //0x96
    Cmd_tryinfatuating,                          //0x97
    Cmd_updatestatusicon,                        //0x98
    Cmd_setmist,                                 //0x99
    Cmd_setfocusenergy,                          //0x9A
    Cmd_transformdataexecution,                  //0x9B
    Cmd_setsubstitute,                           //0x9C
    Cmd_mimicattackcopy,                         //0x9D
    Cmd_metronome,                               //0x9E
    Cmd_dmgtolevel,                              //0x9F
    Cmd_psywavedamageeffect,                     //0xA0
    Cmd_counterdamagecalculator,                 //0xA1
    Cmd_mirrorcoatdamagecalculator,              //0xA2
    Cmd_disablelastusedattack,                   //0xA3
    Cmd_trysetencore,                            //0xA4
    Cmd_painsplitdmgcalc,                        //0xA5
    Cmd_settypetorandomresistance,               //0xA6
    Cmd_setalwayshitflag,                        //0xA7
    Cmd_copymovepermanently,                     //0xA8
    Cmd_trychoosesleeptalkmove,                  //0xA9
    Cmd_setdestinybond,                          //0xAA
    Cmd_trysetdestinybondtohappen,               //0xAB
    Cmd_settailwind,                             //0xAC
    Cmd_tryspiteppreduce,                        //0xAD
    Cmd_healpartystatus,                         //0xAE
    Cmd_cursetarget,                             //0xAF
    Cmd_trysetspikes,                            //0xB0
    Cmd_setforesight,                            //0xB1
    Cmd_trysetperishsong,                        //0xB2
    Cmd_handlerollout,                           //0xB3
    Cmd_jumpifconfusedandstatmaxed,              //0xB4
    Cmd_handlefurycutter,                        //0xB5
    Cmd_setembargo,                              //0xB6
    Cmd_presentdamagecalculation,                //0xB7
    Cmd_setsafeguard,                            //0xB8
    Cmd_magnitudedamagecalculation,              //0xB9
    Cmd_jumpifnopursuitswitchdmg,                //0xBA
    Cmd_unused_bb,                               //0xBB
    Cmd_halvehp,                                 //0xBC
    Cmd_copyfoestats,                            //0xBD
    Cmd_rapidspinfree,                           //0xBE
    Cmd_setdefensecurlbit,                       //0xBF
    Cmd_recoverbasedonsunlight,                  //0xC0
    Cmd_setstickyweb,                            //0xC1
    Cmd_selectfirstvalidtarget,                  //0xC2
    Cmd_trysetfutureattack,                      //0xC3
    Cmd_trydobeatup,                             //0xC4
    Cmd_setsemiinvulnerablebit,                  //0xC5
    Cmd_tryfiretwoturnmovenowbyeffect,           //0xC6
    Cmd_setminimize,                             //0xC7
    Cmd_unused_c8,                               //0xC8
    Cmd_trymemento,                              //0xC9
    Cmd_setforcedtarget,                         //0xCA
    Cmd_setcharge,                               //0xCB
    Cmd_callterrainattack,                       //0xCC
    Cmd_cureifburnedparalysedorpoisoned,         //0xCD
    Cmd_settorment,                              //0xCE
    Cmd_jumpifnodamage,                          //0xCF
    Cmd_settaunt,                                //0xD0
    Cmd_trysethelpinghand,                       //0xD1
    Cmd_tryswapitems,                            //0xD2
    Cmd_trycopyability,                          //0xD3
    Cmd_trywish,                                 //0xD4
    Cmd_settoxicspikes,                          //0xD5
    Cmd_setgastroacid,                           //0xD6
    Cmd_setyawn,                                 //0xD7
    Cmd_setdamagetohealthdifference,             //0xD8
    Cmd_setroom,                                 //0xD9
    Cmd_tryswapabilities,                        //0xDA
    Cmd_tryimprison,                             //0xDB
    Cmd_setstealthrock,                          //0xDC
    Cmd_setuserstatus3,                          //0xDD
    Cmd_assistattackselect,                      //0xDE
    Cmd_trysetmagiccoat,                         //0xDF
    Cmd_trysetsnatch,                            //0xE0
    Cmd_unused2,                                 //0xE1
    Cmd_switchoutabilities,                      //0xE2
    Cmd_jumpifhasnohp,                           //0xE3
    Cmd_jumpifnotcurrentmoveargtype,             //0xE4
    Cmd_pickup,                                  //0xE5
    Cmd_unused3,                                 //0xE6
    Cmd_unused4,                                 //0xE7
    Cmd_settypebasedhalvers,                     //0xE8
    Cmd_jumpifsubstituteblocks,                  //0xE9
    Cmd_tryrecycleitem,                          //0xEA
    Cmd_settypetoterrain,                        //0xEB
    Cmd_pursuitdoubles,                          //0xEC
    Cmd_snatchsetbattlers,                       //0xED
    Cmd_removelightscreenreflect,                //0xEE
    Cmd_handleballthrow,                         //0xEF
    Cmd_givecaughtmon,                           //0xF0
    Cmd_trysetcaughtmondexflags,                 //0xF1
    Cmd_displaydexinfo,                          //0xF2
    Cmd_trygivecaughtmonnick,                    //0xF3
    Cmd_subattackerhpbydmg,                      //0xF4
    Cmd_removeattackerstatus1,                   //0xF5
    Cmd_finishaction,                            //0xF6
    Cmd_finishturn,                              //0xF7
    Cmd_trainerslideout,                         //0xF8
    Cmd_settelekinesis,                          //0xF9
    Cmd_swapstatstages,                          //0xFA
    Cmd_averagestats,                            //0xFB
    Cmd_jumpifoppositegenders,                   //0xFC
    Cmd_unused,                                  //0xFD
    Cmd_tryworryseed,                            //0xFE
    Cmd_callnative,                              //0xFF
};

const struct StatFractions gAccuracyStageRatios[] =
{
    { 33, 100}, // -6
    { 36, 100}, // -5
    { 43, 100}, // -4
    { 50, 100}, // -3
    { 60, 100}, // -2
    { 75, 100}, // -1
    {  1,   1}, //  0
    {133, 100}, // +1
    {166, 100}, // +2
    {  2,   1}, // +3
    {233, 100}, // +4
    {133,  50}, // +5
    {  3,   1}, // +6
};

static const u32 sStatusFlagsForMoveEffects[NUM_MOVE_EFFECTS] =
{
    [MOVE_EFFECT_SLEEP]          = STATUS1_SLEEP,
    [MOVE_EFFECT_POISON]         = STATUS1_POISON,
    [MOVE_EFFECT_BURN]           = STATUS1_BURN,
    [MOVE_EFFECT_FREEZE]         = STATUS1_FREEZE,
    [MOVE_EFFECT_PARALYSIS]      = STATUS1_PARALYSIS,
    [MOVE_EFFECT_TOXIC]          = STATUS1_TOXIC_POISON,
    [MOVE_EFFECT_FROSTBITE]      = STATUS1_FROSTBITE,
    [MOVE_EFFECT_CONFUSION]      = STATUS2_CONFUSION,
    [MOVE_EFFECT_FLINCH]         = STATUS2_FLINCHED,
    [MOVE_EFFECT_UPROAR]         = STATUS2_UPROAR,
    [MOVE_EFFECT_CHARGING]       = STATUS2_MULTIPLETURNS,
    [MOVE_EFFECT_WRAP]           = STATUS2_WRAPPED,
    [MOVE_EFFECT_RECHARGE]       = STATUS2_RECHARGE,
    [MOVE_EFFECT_PREVENT_ESCAPE] = STATUS2_ESCAPE_PREVENTION,
    [MOVE_EFFECT_NIGHTMARE]      = STATUS2_NIGHTMARE,
    [MOVE_EFFECT_THRASH]         = STATUS2_LOCK_CONFUSE,
};

static const u8 *const sMoveEffectBS_Ptrs[] =
{
    [MOVE_EFFECT_SLEEP]            = BattleScript_MoveEffectSleep,
    [MOVE_EFFECT_POISON]           = BattleScript_MoveEffectPoison,
    [MOVE_EFFECT_BURN]             = BattleScript_MoveEffectBurn,
    [MOVE_EFFECT_FREEZE]           = BattleScript_MoveEffectFreeze,
    [MOVE_EFFECT_PARALYSIS]        = BattleScript_MoveEffectParalysis,
    [MOVE_EFFECT_TOXIC]            = BattleScript_MoveEffectToxic,
    [MOVE_EFFECT_CONFUSION]        = BattleScript_MoveEffectConfusion,
    [MOVE_EFFECT_UPROAR]           = BattleScript_MoveEffectUproar,
    [MOVE_EFFECT_PAYDAY]           = BattleScript_MoveEffectPayDay,
    [MOVE_EFFECT_WRAP]             = BattleScript_MoveEffectWrap,
    [MOVE_EFFECT_FROSTBITE]        = BattleScript_MoveEffectFrostbite,
};

static const struct WindowTemplate sUnusedWinTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 7,
    .height = 15,
    .paletteNum = 31,
    .baseBlock = 0x3F
};

static const u16 sLevelUpBanner_Pal[] = INCBIN_U16("graphics/battle_interface/level_up_banner.gbapal");
static const u32 sLevelUpBanner_Gfx[] = INCBIN_U32("graphics/battle_interface/level_up_banner.4bpp.lz");

static const struct OamData sOamData_MonIconOnLvlUpBanner =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_MonIconOnLvlUpBanner =
{
    .tileTag = TAG_LVLUP_BANNER_MON_ICON,
    .paletteTag = TAG_LVLUP_BANNER_MON_ICON,
    .oam = &sOamData_MonIconOnLvlUpBanner,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MonIconOnLvlUpBanner
};

static const u16 sProtectSuccessRates[] = {USHRT_MAX, USHRT_MAX / 2, USHRT_MAX / 4, USHRT_MAX / 8};

static const u16 sFinalStrikeOnlyEffects[] =
{
    MOVE_EFFECT_BUG_BITE,
    MOVE_EFFECT_STEAL_ITEM,
    MOVE_EFFECT_REMOVE_ARG_TYPE,
    MOVE_EFFECT_SMACK_DOWN,
    MOVE_EFFECT_REMOVE_STATUS,
    MOVE_EFFECT_RECOIL_HP_25,
    MOVE_EFFECT_PREVENT_ESCAPE,
    MOVE_EFFECT_WRAP,
};

static const u16 sNaturePowerMoves[BATTLE_TERRAIN_COUNT] =
{
#if B_NATURE_POWER_MOVES >= GEN_7
    [BATTLE_TERRAIN_GRASS]      = MOVE_ENERGY_BALL,
    [BATTLE_TERRAIN_LONG_GRASS] = MOVE_ENERGY_BALL,
    [BATTLE_TERRAIN_SAND]       = MOVE_EARTH_POWER,
    [BATTLE_TERRAIN_WATER]      = MOVE_HYDRO_PUMP,
    [BATTLE_TERRAIN_POND]       = MOVE_HYDRO_PUMP,
    [BATTLE_TERRAIN_MOUNTAIN]   = MOVE_EARTH_POWER,
    [BATTLE_TERRAIN_CAVE]       = MOVE_EARTH_POWER,
    [BATTLE_TERRAIN_BUILDING]   = MOVE_TRI_ATTACK,
    [BATTLE_TERRAIN_PLAIN]      = MOVE_TRI_ATTACK,
    [BATTLE_TERRAIN_SNOW]       = MOVE_ICE_BEAM,
#elif B_NATURE_POWER_MOVES == GEN_6
    [BATTLE_TERRAIN_GRASS]      = MOVE_ENERGY_BALL,
    [BATTLE_TERRAIN_LONG_GRASS] = MOVE_ENERGY_BALL,
    [BATTLE_TERRAIN_SAND]       = MOVE_EARTH_POWER,
    [BATTLE_TERRAIN_WATER]      = MOVE_HYDRO_PUMP,
    [BATTLE_TERRAIN_POND]       = MOVE_HYDRO_PUMP,
    [BATTLE_TERRAIN_MOUNTAIN]   = MOVE_EARTH_POWER,
    [BATTLE_TERRAIN_CAVE]       = MOVE_EARTH_POWER,
    [BATTLE_TERRAIN_BUILDING]   = MOVE_TRI_ATTACK,
    [BATTLE_TERRAIN_PLAIN]      = MOVE_TRI_ATTACK,
    [BATTLE_TERRAIN_SNOW]       = MOVE_FROST_BREATH,
#elif B_NATURE_POWER_MOVES == GEN_5
    [BATTLE_TERRAIN_GRASS]      = MOVE_SEED_BOMB,
    [BATTLE_TERRAIN_LONG_GRASS] = MOVE_SEED_BOMB,
    [BATTLE_TERRAIN_SAND]       = MOVE_EARTHQUAKE,
    [BATTLE_TERRAIN_WATER]      = MOVE_HYDRO_PUMP,
    [BATTLE_TERRAIN_POND]       = MOVE_HYDRO_PUMP,
    [BATTLE_TERRAIN_MOUNTAIN]   = MOVE_EARTHQUAKE,
    [BATTLE_TERRAIN_CAVE]       = MOVE_EARTHQUAKE,
    [BATTLE_TERRAIN_BUILDING]   = MOVE_TRI_ATTACK,
    [BATTLE_TERRAIN_PLAIN]      = MOVE_EARTHQUAKE,
    [BATTLE_TERRAIN_SNOW]       = MOVE_BLIZZARD,
#elif B_NATURE_POWER_MOVES == GEN_4
    [BATTLE_TERRAIN_GRASS]      = MOVE_SEED_BOMB,
    [BATTLE_TERRAIN_LONG_GRASS] = MOVE_SEED_BOMB,
    [BATTLE_TERRAIN_SAND]       = MOVE_EARTHQUAKE,
    [BATTLE_TERRAIN_WATER]      = MOVE_HYDRO_PUMP,
    [BATTLE_TERRAIN_POND]       = MOVE_HYDRO_PUMP,
    [BATTLE_TERRAIN_MOUNTAIN]   = MOVE_ROCK_SLIDE,
    [BATTLE_TERRAIN_CAVE]       = MOVE_ROCK_SLIDE,
    [BATTLE_TERRAIN_BUILDING]   = MOVE_TRI_ATTACK,
    [BATTLE_TERRAIN_PLAIN]      = MOVE_EARTHQUAKE,
    [BATTLE_TERRAIN_SNOW]       = MOVE_BLIZZARD,
#else // Gen 1-3
    [BATTLE_TERRAIN_GRASS]      = MOVE_STUN_SPORE,
    [BATTLE_TERRAIN_LONG_GRASS] = MOVE_RAZOR_LEAF,
    [BATTLE_TERRAIN_SAND]       = MOVE_EARTHQUAKE,
    [BATTLE_TERRAIN_WATER]      = MOVE_SURF,
    [BATTLE_TERRAIN_POND]       = MOVE_BUBBLE_BEAM,
    [BATTLE_TERRAIN_MOUNTAIN]   = MOVE_ROCK_SLIDE,
    [BATTLE_TERRAIN_CAVE]       = MOVE_SHADOW_BALL,
    [BATTLE_TERRAIN_BUILDING]   = MOVE_SWIFT,
    [BATTLE_TERRAIN_PLAIN]      = MOVE_SWIFT,
    [BATTLE_TERRAIN_SNOW]       = MOVE_BLIZZARD,
#endif
    [BATTLE_TERRAIN_UNDERWATER]       = MOVE_HYDRO_PUMP,
    [BATTLE_TERRAIN_SOARING]          = MOVE_AIR_SLASH,
    [BATTLE_TERRAIN_SKY_PILLAR]       = MOVE_AIR_SLASH,
    [BATTLE_TERRAIN_BURIAL_GROUND]    = MOVE_SHADOW_BALL,
    [BATTLE_TERRAIN_PUDDLE]           = MOVE_MUD_BOMB,
    [BATTLE_TERRAIN_MARSH]            = MOVE_MUD_BOMB,
    [BATTLE_TERRAIN_SWAMP]            = MOVE_MUD_BOMB,
    [BATTLE_TERRAIN_ICE]              = MOVE_ICE_BEAM,
    [BATTLE_TERRAIN_VOLCANO]          = MOVE_LAVA_PLUME,
    [BATTLE_TERRAIN_DISTORTION_WORLD] = MOVE_TRI_ATTACK,
    [BATTLE_TERRAIN_SPACE]            = MOVE_DRACO_METEOR,
    [BATTLE_TERRAIN_ULTRA_SPACE]      = MOVE_PSYSHOCK,
};

#define _ 0

static const struct PickupItem sPickupTable[] =
{//   Item                      1+  11+  21+  31+  41+  51+  61+  71+  81+  91+   Levels
    { ITEM_POTION,          {  35,   _,   _,   _,   _,   _,   _,   _,   _,   _, } },
    { ITEM_TINY_MUSHROOM,   {  25,  10,   _,   _,   _,   _,   _,   _,   _,   _, } },
    { ITEM_REPEL,           {   8,  30,   _,   _,   _,   _,   _,   _,   _,   _, } },
    { ITEM_SUPER_POTION,    {   8,  10,  30,   _,   _,   _,   _,   _,   _,   _, } },
    { ITEM_POKE_DOLL,       {   8,  10,   9,  30,   _,   _,   _,   _,   _,   _, } },
    { ITEM_BIG_MUSHROOM,    {   3,  10,   9,   _,   _,   _,   _,   _,   _,   _, } },
    { ITEM_SUPER_REPEL,     {   3,  10,   9,   9,  30,   _,   _,   _,   _,   _, } },
    { ITEM_FULL_HEAL,       {   3,   3,   9,   8,   9,  30,   _,   _,   _,   _, } },
    { ITEM_REVIVE,          {   3,   3,   3,   8,   8,   9,  30,   _,   _,   _, } },
    { ITEM_HYPER_POTION,    {   3,   3,   3,   4,   8,   9,   8,  30,   _,   _, } },
    { ITEM_ETHER,           {   1,   1,   3,   4,   4,   _,   _,   _,   _,   _, } },
    { ITEM_MAX_REPEL,       {   _,   3,   3,   4,   4,   9,   8,   8,  30,   _, } },
    { ITEM_MOON_STONE,      {   _,   3,   3,   4,   4,   4,   4,   5,   9,  10, } },
    { ITEM_SUN_STONE,       {   _,   3,   3,   4,   4,   4,   4,   5,   9,  10, } },
    { ITEM_RARE_CANDY,      {   _,   1,   1,   1,   1,   4,   4,   5,   4,   5, } },
    { ITEM_NUGGET,          {   _,   _,   3,   4,   4,   4,   4,   5,   4,   5, } },
    { ITEM_MAX_POTION,      {   _,   _,   3,   4,   4,   4,   8,   8,   9,  30, } },
    { ITEM_MAX_ETHER,       {   _,   _,   1,   1,   4,   4,   4,   _,   _,   _, } },
    { ITEM_PP_UP,           {   _,   _,   1,   1,   1,   4,   4,   5,   4,   5, } },
    { ITEM_BIG_NUGGET,      {   _,   _,   1,   1,   1,   1,   4,   5,   4,   5, } },
    { ITEM_DESTINY_KNOT,    {   _,   _,   1,   1,   1,   1,   1,   1,   1,   1, } },
    { ITEM_LEFTOVERS,       {   _,   _,   1,   1,   1,   1,   1,   1,   1,   1, } },
    { ITEM_MENTAL_HERB,     {   _,   _,   1,   1,   1,   1,   1,   1,   1,   1, } },
    { ITEM_POWER_HERB,      {   _,   _,   1,   1,   1,   1,   1,   1,   1,   1, } },
    { ITEM_WHITE_HERB,      {   _,   _,   1,   1,   1,   1,   1,   1,   1,   1, } },
    { ITEM_BALM_MUSHROOM,   {   _,   _,   1,   4,   4,   4,   4,   5,   4,   5, } },
    { ITEM_MAX_REVIVE,      {   _,   _,   _,   4,   4,   4,   4,   7,   9,   9, } },
    { ITEM_ELIXIR,          {   _,   _,   _,   _,   1,   1,   4,   5,   4,   5, } },
    { ITEM_MAX_ELIXIR,      {   _,   _,   _,   _,   _,   _,   1,   1,   4,   5, } },
    { ITEM_BOTTLE_CAP,      {   _,   _,   _,   _,   _,   _,   _,   1,   1,   1, } },
};

#undef _

static const u8 sTerrainToType[BATTLE_TERRAIN_COUNT] =
{
    [BATTLE_TERRAIN_GRASS]            = TYPE_GRASS,
    [BATTLE_TERRAIN_LONG_GRASS]       = TYPE_GRASS,
    [BATTLE_TERRAIN_SAND]             = TYPE_GROUND,
    [BATTLE_TERRAIN_UNDERWATER]       = TYPE_WATER,
    [BATTLE_TERRAIN_WATER]            = TYPE_WATER,
    [BATTLE_TERRAIN_POND]             = TYPE_WATER,
    [BATTLE_TERRAIN_CAVE]             = TYPE_ROCK,
    [BATTLE_TERRAIN_BUILDING]         = TYPE_NORMAL,
    [BATTLE_TERRAIN_SOARING]          = TYPE_FLYING,
    [BATTLE_TERRAIN_SKY_PILLAR]       = TYPE_FLYING,
    [BATTLE_TERRAIN_BURIAL_GROUND]    = TYPE_GHOST,
    [BATTLE_TERRAIN_PUDDLE]           = TYPE_GROUND,
    [BATTLE_TERRAIN_MARSH]            = TYPE_GROUND,
    [BATTLE_TERRAIN_SWAMP]            = TYPE_GROUND,
    [BATTLE_TERRAIN_SNOW]             = TYPE_ICE,
    [BATTLE_TERRAIN_ICE]              = TYPE_ICE,
    [BATTLE_TERRAIN_VOLCANO]          = TYPE_FIRE,
    [BATTLE_TERRAIN_DISTORTION_WORLD] = TYPE_NORMAL,
    [BATTLE_TERRAIN_SPACE]            = TYPE_DRAGON,
    [BATTLE_TERRAIN_ULTRA_SPACE]      = TYPE_PSYCHIC,
    [BATTLE_TERRAIN_MOUNTAIN]         = (B_CAMOUFLAGE_TYPES >= GEN_5 ? TYPE_GROUND : TYPE_ROCK),
    [BATTLE_TERRAIN_PLAIN]            = (B_CAMOUFLAGE_TYPES >= GEN_4 ? TYPE_GROUND : TYPE_NORMAL),
};

static bool32 NoTargetPresent(u8 battler, u32 move)
{
    if (!IsBattlerAlive(gBattlerTarget))
        gBattlerTarget = GetMoveTarget(move, NO_TARGET_OVERRIDE);

    switch (GetBattlerMoveTargetType(battler, move))
    {
    case MOVE_TARGET_SELECTED:
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_RANDOM:
        if (!IsBattlerAlive(gBattlerTarget))
            return TRUE;
        break;
    case MOVE_TARGET_BOTH:
        if (!IsBattlerAlive(gBattlerTarget) && !IsBattlerAlive(BATTLE_PARTNER(gBattlerTarget)))
            return TRUE;
        break;
    case MOVE_TARGET_FOES_AND_ALLY:
        if (!IsBattlerAlive(gBattlerTarget) && !IsBattlerAlive(BATTLE_PARTNER(gBattlerTarget)) && !IsBattlerAlive(BATTLE_PARTNER(gBattlerAttacker)))
            return TRUE;
        break;
    }

    return FALSE;
}

// TODO: Convert this to a proper FORM_CHANGE type.
static bool32 TryAegiFormChange(void)
{
    // Only Aegislash with Stance Change can transform, transformed mons cannot.
    if (GetBattlerAbility(gBattlerAttacker) != ABILITY_STANCE_CHANGE
        || gBattleMons[gBattlerAttacker].status2 & STATUS2_TRANSFORMED)
        return FALSE;

    switch (gBattleMons[gBattlerAttacker].species)
    {
    default:
        return FALSE;
    case SPECIES_AEGISLASH_SHIELD: // Shield -> Blade
        if (IS_MOVE_STATUS(gCurrentMove))
            return FALSE;
        gBattleMons[gBattlerAttacker].species = SPECIES_AEGISLASH_BLADE;
        break;
    case SPECIES_AEGISLASH_BLADE: // Blade -> Shield
        if (gCurrentMove != MOVE_KINGS_SHIELD)
            return FALSE;
        gBattleMons[gBattlerAttacker].species = SPECIES_AEGISLASH_SHIELD;
        break;
    }

    BattleScriptPushCursor();
    gBattlescriptCurrInstr = BattleScript_AttackerFormChange;
    return TRUE;
}

bool32 ProteanTryChangeType(u32 battler, u32 ability, u32 move, u32 moveType)
{
      if ((ability == ABILITY_PROTEAN || ability == ABILITY_LIBERO)
         && !gDisableStructs[gBattlerAttacker].usedProteanLibero
         && (gBattleMons[battler].types[0] != moveType || gBattleMons[battler].types[1] != moveType
             || (gBattleMons[battler].types[2] != moveType && gBattleMons[battler].types[2] != TYPE_MYSTERY))
         && move != MOVE_STRUGGLE
         && GetActiveGimmick(battler) != GIMMICK_TERA)
    {
        SET_BATTLER_TYPE(battler, moveType);
        return TRUE;
    }
    return FALSE;
}

bool32 ShouldTeraShellDistortTypeMatchups(u32 move, u32 battlerDef)
{
    if (!(gBattleStruct->distortedTypeMatchups & gBitTable[battlerDef])
     && GetBattlerAbility(battlerDef) == ABILITY_TERA_SHELL
     && gBattleMons[battlerDef].species == SPECIES_TERAPAGOS_TERASTAL
     && !IS_MOVE_STATUS(move)
     && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
     && gBattleMons[battlerDef].hp == gBattleMons[battlerDef].maxHP)
        return TRUE;

    return FALSE;
}

bool32 IsMoveNotAllowedInSkyBattles(u32 move)
{
    return ((gBattleStruct->isSkyBattle) && (gMovesInfo[gCurrentMove].skyBattleBanned));
}

static void Cmd_attackcanceler(void)
{
    CMD_ARGS();

    s32 i, moveType;
    u16 attackerAbility = GetBattlerAbility(gBattlerAttacker);
    GET_MOVE_TYPE(gCurrentMove, moveType);

    // Weight-based moves are blocked by Dynamax.
    if ((GetActiveGimmick(gBattlerTarget) == GIMMICK_DYNAMAX) && IsMoveBlockedByDynamax(gCurrentMove))
    {
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_MoveBlockedByDynamax;
        return;
    }

    if (gBattleOutcome != 0)
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }
    if (!IsBattlerAlive(gBattlerAttacker) && gMovesInfo[gCurrentMove].effect != EFFECT_EXPLOSION && !(gHitMarker & HITMARKER_NO_ATTACKSTRING))
    {
        gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
        return;
    }
    if (B_STANCE_CHANGE_FAIL < GEN_7 && TryAegiFormChange())
        return;
    if (AtkCanceller_UnableToUseMove(moveType))
        return;

    if (WEATHER_HAS_EFFECT && gMovesInfo[gCurrentMove].power)
    {
        if (moveType == TYPE_FIRE && (gBattleWeather & B_WEATHER_RAIN_PRIMAL))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PRIMAL_WEATHER_FIZZLED_BY_RAIN;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_PrimalWeatherBlocksMove;
            return;
        }
        else if (moveType == TYPE_WATER && (gBattleWeather & B_WEATHER_SUN_PRIMAL))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PRIMAL_WEATHER_EVAPORATED_IN_SUN;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_PrimalWeatherBlocksMove;
            return;
        }
    }

    if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_OFF
     && GetBattlerAbility(gBattlerAttacker) == ABILITY_PARENTAL_BOND
     && IsMoveAffectedByParentalBond(gCurrentMove, gBattlerAttacker)
     && !(gAbsentBattlerFlags & gBitTable[gBattlerTarget])
     && GetActiveGimmick(gBattlerAttacker) != GIMMICK_Z_MOVE)
    {
        gSpecialStatuses[gBattlerAttacker].parentalBondState = PARENTAL_BOND_1ST_HIT;
        gMultiHitCounter = 2;
        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
        return;
    }

    // Check Protean activation.
    if (ProteanTryChangeType(gBattlerAttacker, attackerAbility, gCurrentMove, moveType))
    {
        if (B_PROTEAN_LIBERO == GEN_9)
            gDisableStructs[gBattlerAttacker].usedProteanLibero = TRUE;
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
        gBattlerAbility = gBattlerAttacker;
        BattleScriptPushCursor();
        PrepareStringBattle(STRINGID_EMPTYSTRING3, gBattlerAttacker);
        gBattleCommunication[MSG_DISPLAY] = 1;
        gBattlescriptCurrInstr = BattleScript_ProteanActivates;
        return;
    }

    if (AtkCanceller_UnableToUseMove2())
        return;
    if (AbilityBattleEffects(ABILITYEFFECT_MOVES_BLOCK, gBattlerTarget, 0, 0, 0))
        return;
    if (!gBattleMons[gBattlerAttacker].pp[gCurrMovePos] && gCurrentMove != MOVE_STRUGGLE
     && !(gHitMarker & (HITMARKER_ALLOW_NO_PP | HITMARKER_NO_ATTACKSTRING | HITMARKER_NO_PPDEDUCT))
     && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))
    {
        gBattlescriptCurrInstr = BattleScript_NoPPForMove;
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        return;
    }
    if (B_STANCE_CHANGE_FAIL >= GEN_7 && TryAegiFormChange())
        return;

    gHitMarker &= ~HITMARKER_ALLOW_NO_PP;

    if (!(gHitMarker & HITMARKER_OBEYS) && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))
    {
        switch (gBattleStruct->obedienceResult)
        {
        case OBEYS:
            break;
        case DISOBEYS_LOAFS:
            // Randomly select, then print a disobedient string
            // B_MSG_LOAFING, B_MSG_WONT_OBEY, B_MSG_TURNED_AWAY, or B_MSG_PRETEND_NOT_NOTICE
            gBattleCommunication[MULTISTRING_CHOOSER] = MOD(Random(), NUM_LOAF_STRINGS);
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            return;
        case DISOBEYS_HITS_SELF:
            gBattlerTarget = gBattlerAttacker;
            gBattleMoveDamage = CalculateMoveDamage(MOVE_NONE, gBattlerAttacker, gBattlerAttacker, TYPE_MYSTERY, 40, FALSE, FALSE, TRUE);
            gBattlescriptCurrInstr = BattleScript_IgnoresAndHitsItself;
            gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
            gHitMarker |= HITMARKER_OBEYS;
            return;
        case DISOBEYS_FALL_ASLEEP:
            gBattlescriptCurrInstr = BattleScript_IgnoresAndFallsAsleep;
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            return;
        case DISOBEYS_WHILE_ASLEEP:
            gBattlescriptCurrInstr = BattleScript_IgnoresWhileAsleep;
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            return;
        case DISOBEYS_RANDOM_MOVE:
            gCalledMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
            SetAtkCancellerForCalledMove();
            gBattlescriptCurrInstr = BattleScript_IgnoresAndUsesRandomMove;
            gBattlerTarget = GetMoveTarget(gCalledMove, NO_TARGET_OVERRIDE);
            gHitMarker |= HITMARKER_DISOBEDIENT_MOVE;
            gHitMarker |= HITMARKER_OBEYS;
            return;
        }
    }

    gHitMarker |= HITMARKER_OBEYS;
    // Check if no available target present on the field or if Sky Battles ban the move
    if ((NoTargetPresent(gBattlerAttacker, gCurrentMove)
        && (!gBattleMoveEffects[gMovesInfo[gCurrentMove].effect].twoTurnEffect || (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)))
        || (IsMoveNotAllowedInSkyBattles(gCurrentMove)))
    {
        if (gMovesInfo[gCurrentMove].effect == EFFECT_FLING) // Edge case for removing a mon's item when there is no target available after using Fling.
            gBattlescriptCurrInstr = BattleScript_FlingFailConsumeItem;
        else
            gBattlescriptCurrInstr = BattleScript_FailedFromAtkString;

        if (!gBattleMoveEffects[gMovesInfo[gCurrentMove].effect].twoTurnEffect || (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))
            CancelMultiTurnMoves(gBattlerAttacker);
        return;
    }

    if (gProtectStructs[gBattlerTarget].bounceMove
        && gMovesInfo[gCurrentMove].magicCoatAffected
        && !gBattleStruct->bouncedMoveIsUsed)
    {
        gBattleStruct->bouncedMoveIsUsed = TRUE;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        // Edge case for bouncing a powder move against a grass type pokemon.
        SetAtkCancellerForCalledMove();
        if (BlocksPrankster(gCurrentMove, gBattlerTarget, gBattlerAttacker, TRUE))
        {
            // Opponent used a prankster'd magic coat -> reflected status move should fail against a dark-type attacker
            gBattlerTarget = gBattlerAttacker;
            gBattlescriptCurrInstr = BattleScript_MagicCoatBouncePrankster;
        }
        else
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_MagicCoatBounce;
        }
        return;
    }
    else if (gMovesInfo[gCurrentMove].magicCoatAffected && !gBattleStruct->bouncedMoveIsUsed)
    {
        u32 battler = gBattlerTarget;

        if (GetBattlerAbility(gBattlerTarget) == ABILITY_MAGIC_BOUNCE)
        {
            battler = gBattlerTarget;
            gBattleStruct->bouncedMoveIsUsed = TRUE;
        }
        else if (IsDoubleBattle()
              && gMovesInfo[gCurrentMove].target == MOVE_TARGET_OPPONENTS_FIELD
              && GetBattlerAbility(BATTLE_PARTNER(gBattlerTarget)) == ABILITY_MAGIC_BOUNCE)
        {
            gBattlerTarget = battler = BATTLE_PARTNER(gBattlerTarget);
            gBattleStruct->bouncedMoveIsUsed = TRUE;
        }

        if (gBattleStruct->bouncedMoveIsUsed)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            // Edge case for bouncing a powder move against a grass type pokemon.
            SetAtkCancellerForCalledMove();
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_MagicCoatBounce;
            gBattlerAbility = battler;
            return;
        }
    }

    // Z-moves and Max Moves bypass protection, but deal reduced damage (factored in AccumulateOtherModifiers)
    if ((IsZMove(gCurrentMove) || IsMaxMove(gCurrentMove))
     && IS_BATTLER_PROTECTED(gBattlerTarget))
    {
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_CouldntFullyProtect;
        return;
    }

    for (i = 0; i < gBattlersCount; i++)
    {
        if ((gProtectStructs[gBattlerByTurnOrder[i]].stealMove) && gMovesInfo[gCurrentMove].snatchAffected)
        {
            gProtectStructs[gBattlerByTurnOrder[i]].stealMove = FALSE;
            gBattleStruct->snatchedMoveIsUsed = TRUE;
            gBattleScripting.battler = gBattlerByTurnOrder[i];
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_SnatchedMove;
            return;
        }
    }

    if (gSpecialStatuses[gBattlerTarget].lightningRodRedirected)
    {
        gSpecialStatuses[gBattlerTarget].lightningRodRedirected = FALSE;
        gLastUsedAbility = ABILITY_LIGHTNING_ROD;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_TookAttack;
        RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
    }
    else if (gSpecialStatuses[gBattlerTarget].stormDrainRedirected)
    {
        gSpecialStatuses[gBattlerTarget].stormDrainRedirected = FALSE;
        gLastUsedAbility = ABILITY_STORM_DRAIN;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_TookAttack;
        RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
    }
    else if (IsBattlerProtected(gBattlerAttacker, gBattlerTarget, gCurrentMove)
     && (gCurrentMove != MOVE_CURSE || IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
     && (!gBattleMoveEffects[gMovesInfo[gCurrentMove].effect].twoTurnEffect || (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))
     && gMovesInfo[gCurrentMove].effect != EFFECT_SUCKER_PUNCH
     && gMovesInfo[gCurrentMove].effect != EFFECT_UPPER_HAND)
    {
        if (IsMoveMakingContact(gCurrentMove, gBattlerAttacker))
            gProtectStructs[gBattlerAttacker].touchedProtectLike = TRUE;
        CancelMultiTurnMoves(gBattlerAttacker);
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gLastLandedMoves[gBattlerTarget] = 0;
        gLastHitByType[gBattlerTarget] = 0;

        if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_1ST_HIT)
        {
            gSpecialStatuses[gBattlerAttacker].parentalBondState = PARENTAL_BOND_OFF; // No second hit if first hit was blocked
            gSpecialStatuses[gBattlerAttacker].multiHitOn = 0;
            gMultiHitCounter = 0;
        }
        gBattleCommunication[MISS_TYPE] = B_MSG_PROTECTED;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (gProtectStructs[gBattlerTarget].beakBlastCharge && IsMoveMakingContact(gCurrentMove, gBattlerAttacker))
    {
        gProtectStructs[gBattlerAttacker].touchedProtectLike = TRUE;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static bool32 JumpIfMoveFailed(u8 adder, u16 move)
{
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        gLastLandedMoves[gBattlerTarget] = 0;
        gLastHitByType[gBattlerTarget] = 0;
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        return TRUE;
    }
    else
    {
        TrySetDestinyBondToHappen();
        if (AbilityBattleEffects(ABILITYEFFECT_ABSORBING, gBattlerTarget, 0, 0, move))
            return TRUE;
    }
    gBattlescriptCurrInstr += adder;
    return FALSE;
}

static void Cmd_unused5(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (IsBattlerProtected(gBattlerAttacker, gBattlerTarget, gCurrentMove))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(sizeof(*cmd), MOVE_NONE);
        gBattleCommunication[MISS_TYPE] = B_MSG_PROTECTED;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static bool8 JumpIfMoveAffectedByProtect(u16 move)
{
    bool8 affected = FALSE;
    if (IsBattlerProtected(gBattlerAttacker, gBattlerTarget, move))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        gBattleCommunication[MISS_TYPE] = B_MSG_PROTECTED;
        affected = TRUE;
    }
    return affected;
}

static bool32 AccuracyCalcHelper(u16 move)
{
    if ((gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBattlerTarget].battlerWithSureHit == gBattlerAttacker)
     || (B_TOXIC_NEVER_MISS >= GEN_6 && gMovesInfo[move].effect == EFFECT_TOXIC && IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_POISON))
     || gStatuses4[gBattlerTarget] & STATUS4_GLAIVE_RUSH)
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }
    // If the attacker has the ability No Guard and they aren't targeting a Pokemon involved in a Sky Drop with the move Sky Drop, move hits.
    else if (GetBattlerAbility(gBattlerAttacker) == ABILITY_NO_GUARD && (move != MOVE_SKY_DROP || gBattleStruct->skyDropTargets[gBattlerTarget] == 0xFF))
    {
        if (!JumpIfMoveFailed(7, move))
            RecordAbilityBattle(gBattlerAttacker, ABILITY_NO_GUARD);
        return TRUE;
    }
    // If the target has the ability No Guard and they aren't involved in a Sky Drop or the current move isn't Sky Drop, move hits.
    else if (GetBattlerAbility(gBattlerTarget) == ABILITY_NO_GUARD && (move != MOVE_SKY_DROP || gBattleStruct->skyDropTargets[gBattlerTarget] == 0xFF))
    {
        if (!JumpIfMoveFailed(7, move))
            RecordAbilityBattle(gBattlerTarget, ABILITY_NO_GUARD);
        return TRUE;
    }
    // If the target is under the effects of Telekinesis, and the move isn't a OH-KO move, move hits.
    else if (gStatuses3[gBattlerTarget] & STATUS3_TELEKINESIS
             && !(gStatuses3[gBattlerTarget] & STATUS3_SEMI_INVULNERABLE)
             && gMovesInfo[move].effect != EFFECT_OHKO)
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE && !(gStatuses3[gBattlerTarget] & STATUS3_SEMI_INVULNERABLE))
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    if ((gStatuses3[gBattlerTarget] & STATUS3_PHANTOM_FORCE)
    || ((gStatuses3[gBattlerTarget] & STATUS3_ON_AIR) && !(gMovesInfo[move].damagesAirborne || gMovesInfo[move].damagesAirborneDoubleDamage))
    || ((gStatuses3[gBattlerTarget] & STATUS3_UNDERGROUND) && !gMovesInfo[move].damagesUnderground)
    || ((gStatuses3[gBattlerTarget] & STATUS3_UNDERWATER) && !gMovesInfo[move].damagesUnderwater))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    if (WEATHER_HAS_EFFECT)
    {
        if ((gMovesInfo[move].effect == EFFECT_THUNDER || gMovesInfo[move].effect == EFFECT_RAIN_ALWAYS_HIT)
            && IsBattlerWeatherAffected(gBattlerTarget, B_WEATHER_RAIN))
        {
            // thunder/hurricane/genie moves ignore acc checks in rain unless target is holding utility umbrella
            JumpIfMoveFailed(7, move);
            return TRUE;
        }
        else if ((gBattleWeather & (B_WEATHER_HAIL | B_WEATHER_SNOW)) && gMovesInfo[move].effect == EFFECT_BLIZZARD)
        {
            // Blizzard ignores acc checks in Hail in Gen4+
            JumpIfMoveFailed(7, move);
            return TRUE;
        }
    }

    if (B_MINIMIZE_DMG_ACC >= GEN_6
     && (gStatuses3[gBattlerTarget] & STATUS3_MINIMIZED)
     && gMovesInfo[move].minimizeDoubleDamage)
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    if (gMovesInfo[move].accuracy == 0)
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    return FALSE;
}

u32 GetTotalAccuracy(u32 battlerAtk, u32 battlerDef, u32 move, u32 atkAbility, u32 defAbility, u32 atkHoldEffect, u32 defHoldEffect)
{
    u32 calc, moveAcc;
    s8 buff, accStage, evasionStage;
    u32 atkParam = GetBattlerHoldEffectParam(battlerAtk);
    u32 defParam = GetBattlerHoldEffectParam(battlerDef);
    u32 atkAlly = BATTLE_PARTNER(battlerAtk);
    u32 atkAllyAbility = GetBattlerAbility(atkAlly);

    gPotentialItemEffectBattler = battlerDef;
    accStage = gBattleMons[battlerAtk].statStages[STAT_ACC];
    evasionStage = gBattleMons[battlerDef].statStages[STAT_EVASION];
    if (atkAbility == ABILITY_UNAWARE || atkAbility == ABILITY_KEEN_EYE || atkAbility == ABILITY_MINDS_EYE
            || (B_ILLUMINATE_EFFECT >= GEN_9 && atkAbility == ABILITY_ILLUMINATE))
        evasionStage = DEFAULT_STAT_STAGE;
    if (gMovesInfo[move].ignoresTargetDefenseEvasionStages)
        evasionStage = DEFAULT_STAT_STAGE;
    if (defAbility == ABILITY_UNAWARE)
        accStage = DEFAULT_STAT_STAGE;

    if (gBattleMons[battlerDef].status2 & STATUS2_FORESIGHT || gStatuses3[battlerDef] & STATUS3_MIRACLE_EYED)
        buff = accStage;
    else
        buff = accStage + DEFAULT_STAT_STAGE - evasionStage;

    if (buff < MIN_STAT_STAGE)
        buff = MIN_STAT_STAGE;
    if (buff > MAX_STAT_STAGE)
        buff = MAX_STAT_STAGE;

    moveAcc = gMovesInfo[move].accuracy;
    // Check Thunder and Hurricane on sunny weather.
    if (IsBattlerWeatherAffected(battlerDef, B_WEATHER_SUN) && gMovesInfo[move].effect == EFFECT_THUNDER)
        moveAcc = 50;
    // Check Wonder Skin.
    if (defAbility == ABILITY_WONDER_SKIN && IS_MOVE_STATUS(move) && moveAcc > 50)
        moveAcc = 50;

    calc = gAccuracyStageRatios[buff].dividend * moveAcc;
    calc /= gAccuracyStageRatios[buff].divisor;

    // Attacker's ability
    switch (atkAbility)
    {
    case ABILITY_COMPOUND_EYES:
        calc = (calc * 130) / 100; // 1.3 compound eyes boost
        break;
    case ABILITY_VICTORY_STAR:
        calc = (calc * 110) / 100; // 1.1 victory star boost
        break;
    case ABILITY_HUSTLE:
        if (IS_MOVE_PHYSICAL(move))
            calc = (calc * 80) / 100; // 1.2 hustle loss
        break;
    }

    // Target's ability
    switch (defAbility)
    {
    case ABILITY_SAND_VEIL:
        if (WEATHER_HAS_EFFECT && gBattleWeather & B_WEATHER_SANDSTORM)
            calc = (calc * 80) / 100; // 1.2 sand veil loss
        break;
    case ABILITY_SNOW_CLOAK:
        if (WEATHER_HAS_EFFECT && (gBattleWeather & (B_WEATHER_HAIL | B_WEATHER_SNOW)))
            calc = (calc * 80) / 100; // 1.2 snow cloak loss
        break;
    case ABILITY_TANGLED_FEET:
        if (gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
            calc = (calc * 50) / 100; // 1.5 tangled feet loss
        break;
    }

    // Attacker's ally's ability
    switch (atkAllyAbility)
    {
    case ABILITY_VICTORY_STAR:
        if (IsBattlerAlive(atkAlly))
            calc = (calc * 110) / 100; // 1.1 ally's victory star boost
        break;
    }

    // Attacker's hold effect
    switch (atkHoldEffect)
    {
    case HOLD_EFFECT_WIDE_LENS:
        calc = (calc * (100 + atkParam)) / 100;
        break;
    case HOLD_EFFECT_ZOOM_LENS:
        if (GetBattlerTurnOrderNum(battlerAtk) > GetBattlerTurnOrderNum(battlerDef))
            calc = (calc * (100 + atkParam)) / 100;
        break;
    }

    // Target's hold effect
    switch (defHoldEffect)
    {
    case HOLD_EFFECT_EVASION_UP:
        calc = (calc * (100 - defParam)) / 100;
        break;
    }

    if (gBattleStruct->usedMicleBerry & 1u << battlerAtk)
    {
        if (atkAbility == ABILITY_RIPEN)
            calc = (calc * 140) / 100;  // ripen gives 40% acc boost
        else
            calc = (calc * 120) / 100;  // 20% acc boost
    }

    if (gFieldStatuses & STATUS_FIELD_GRAVITY)
        calc = (calc * 5) / 3; // 1.66 Gravity acc boost

    if (B_AFFECTION_MECHANICS == TRUE && GetBattlerAffectionHearts(battlerDef) == AFFECTION_FIVE_HEARTS)
        calc = (calc * 90) / 100;

    if (WEATHER_HAS_EFFECT && gBattleWeather & B_WEATHER_FOG)
        calc = (calc * 60) / 100; // modified by 3/5

    return calc;
}

static void AccuracyCheck(bool32 recalcDragonDarts, const u8 *nextInstr, const u8 *failInstr, u16 move)
{
    u32 type;
    u32 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, move);
    u32 abilityAtk = GetBattlerAbility(gBattlerAttacker);
    u32 abilityDef = GetBattlerAbility(gBattlerTarget);
    u32 holdEffectAtk = GetBattlerHoldEffect(gBattlerAttacker, TRUE);

    if (move == ACC_CURR_MOVE)
        move = gCurrentMove;

    if (move == NO_ACC_CALC_CHECK_LOCK_ON)
    {
        if (gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBattlerTarget].battlerWithSureHit == gBattlerAttacker)
            gBattlescriptCurrInstr = nextInstr;
        else if (gStatuses3[gBattlerTarget] & (STATUS3_SEMI_INVULNERABLE))
            gBattlescriptCurrInstr = failInstr;
        else if (!JumpIfMoveAffectedByProtect(gCurrentMove))
            gBattlescriptCurrInstr = nextInstr;
        if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_DYNAMAX)
        {
            if (gProtectStructs[gBattlerTarget].maxGuarded)
                gBattlescriptCurrInstr = nextInstr;
            else
                AbilityBattleEffects(ABILITYEFFECT_ABSORBING, gBattlerTarget, 0, 0, gCurrentMove);
        }
    }
    else if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_2ND_HIT
        || (gSpecialStatuses[gBattlerAttacker].multiHitOn
        && (abilityAtk == ABILITY_SKILL_LINK || holdEffectAtk == HOLD_EFFECT_LOADED_DICE
        || !(gMovesInfo[move].effect == EFFECT_TRIPLE_KICK || gMovesInfo[move].effect == EFFECT_POPULATION_BOMB))))
    {
        // No acc checks for second hit of Parental Bond or multi hit moves, except Triple Kick/Triple Axel/Population Bomb
        gBattlescriptCurrInstr = nextInstr;
    }
    else
    {
        u32 accuracy;

        GET_MOVE_TYPE(move, type);
        if (JumpIfMoveAffectedByProtect(move))
            return;
        if (AccuracyCalcHelper(move))
            return;

        accuracy = GetTotalAccuracy(
            gBattlerAttacker,
            gBattlerTarget,
            move,
            abilityAtk,
            abilityDef,
            holdEffectAtk,
            GetBattlerHoldEffect(gBattlerTarget, TRUE)
        );

        if (!RandomPercentage(RNG_ACCURACY, accuracy))
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            if (holdEffectAtk == HOLD_EFFECT_BLUNDER_POLICY)
                gBattleStruct->blunderPolicy = TRUE;    // Only activates from missing through acc/evasion checks

            if (gMovesInfo[gCurrentMove].effect == EFFECT_DRAGON_DARTS
                && !recalcDragonDarts // So we don't jump back and forth between targets
                && CanTargetPartner(gBattlerAttacker, gBattlerTarget)
                && !TargetFullyImmuneToCurrMove(gBattlerAttacker, BATTLE_PARTNER(gBattlerTarget)))
            {
                // Smart target to partner if miss
                gBattlerTarget = BATTLE_PARTNER(gBattlerTarget);
                gMoveResultFlags &= ~MOVE_RESULT_MISSED;
                AccuracyCheck(TRUE, nextInstr, failInstr, move);
                return;
            }

            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE &&
                (moveTarget == MOVE_TARGET_BOTH || moveTarget == MOVE_TARGET_FOES_AND_ALLY))
                gBattleCommunication[MISS_TYPE] = B_MSG_AVOIDED_ATK;
            else
                gBattleCommunication[MISS_TYPE] = B_MSG_MISSED;

            if (gMovesInfo[move].power)
                CalcTypeEffectivenessMultiplier(move, type, gBattlerAttacker, gBattlerTarget, abilityDef, TRUE);
        }
        JumpIfMoveFailed(7, move);
    }
}

static void Cmd_accuracycheck(void)
{
    CMD_ARGS(const u8 *failInstr, u16 move);

    // The main body of this function has been moved to AccuracyCheck() to accomodate
    // Dragon Darts' multiple accuracy checks on a single attack;
    // each dart can try to re-target once after missing.
    AccuracyCheck(FALSE, cmd->nextInstr, cmd->failInstr, cmd->move);
}

static void Cmd_attackstring(void)
{
    CMD_ARGS();

    if (gBattleControllerExecFlags)
        return;

    if (!(gHitMarker & (HITMARKER_NO_ATTACKSTRING | HITMARKER_ATTACKSTRING_PRINTED)))
    {
        PrepareStringBattle(STRINGID_USEDMOVE, gBattlerAttacker);
        gHitMarker |= HITMARKER_ATTACKSTRING_PRINTED;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
    gBattleCommunication[MSG_DISPLAY] = 0;
}

static void Cmd_ppreduce(void)
{
    CMD_ARGS();

    s32 i, ppToDeduct = 1;
    u32 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);

    if (gBattleControllerExecFlags)
        return;

    if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
        gHitMarker |= HITMARKER_NO_PPDEDUCT;

    if (moveTarget == MOVE_TARGET_BOTH
        || moveTarget == MOVE_TARGET_FOES_AND_ALLY
        || moveTarget == MOVE_TARGET_ALL_BATTLERS
        || gMovesInfo[gCurrentMove].forcePressure)
    {
        for (i = 0; i < gBattlersCount; i++)
        {
            if (GetBattlerSide(i) != GetBattlerSide(gBattlerAttacker) && IsBattlerAlive(i))
                ppToDeduct += (GetBattlerAbility(i) == ABILITY_PRESSURE);
        }
    }
    else if (moveTarget != MOVE_TARGET_OPPONENTS_FIELD)
    {
        if (gBattlerAttacker != gBattlerTarget && GetBattlerAbility(gBattlerTarget) == ABILITY_PRESSURE)
             ppToDeduct++;
    }

    if (!(gHitMarker & (HITMARKER_NO_PPDEDUCT | HITMARKER_NO_ATTACKSTRING)) && gBattleMons[gBattlerAttacker].pp[gCurrMovePos])
    {
        gProtectStructs[gBattlerAttacker].notFirstStrike = TRUE;

        // For item Metronome, echoed voice
        if (gCurrentMove != gLastResultingMoves[gBattlerAttacker] || WasUnableToUseMove(gBattlerAttacker))
            gBattleStruct->sameMoveTurns[gBattlerAttacker] = 0;

        if (gBattleMons[gBattlerAttacker].pp[gCurrMovePos] > ppToDeduct)
            gBattleMons[gBattlerAttacker].pp[gCurrMovePos] -= ppToDeduct;
        else
            gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = 0;

        if (MOVE_IS_PERMANENT(gBattlerAttacker, gCurrMovePos))
        {
            BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_PPMOVE1_BATTLE + gCurrMovePos, 0,
                                         sizeof(gBattleMons[gBattlerAttacker].pp[gCurrMovePos]),
                                         &gBattleMons[gBattlerAttacker].pp[gCurrMovePos]);
            MarkBattlerForControllerExec(gBattlerAttacker);
        }
    }

    gHitMarker &= ~HITMARKER_NO_PPDEDUCT;
    gBattlescriptCurrInstr = cmd->nextInstr;

    if (ShouldTeraShellDistortTypeMatchups(gCurrentMove, gBattlerTarget))
    {
        gBattleStruct->distortedTypeMatchups |= gBitTable[gBattlerTarget];
        gBattlerAbility = gBattlerTarget;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_TeraShellDistortingTypeMatchups;
    }
}

// The chance is 1/N for each stage.
#if B_CRIT_CHANCE >= GEN_7
    static const u8 sCriticalHitOdds[] = {24, 8, 2, 1, 1};
#elif B_CRIT_CHANCE == GEN_6
    static const u8 sCriticalHitOdds[] = {16, 8, 2, 1, 1};
#else
    static const u8 sCriticalHitOdds[] = {16, 8, 4, 3, 2}; // Gens 2,3,4,5
#endif // B_CRIT_CHANCE

#define BENEFITS_FROM_LEEK(battler, holdEffect)((holdEffect == HOLD_EFFECT_LEEK) && (GET_BASE_SPECIES_ID(gBattleMons[battler].species) == SPECIES_FARFETCHD || gBattleMons[battler].species == SPECIES_SIRFETCHD))
s32 CalcCritChanceStageArgs(u32 battlerAtk, u32 battlerDef, u32 move, bool32 recordAbility, u32 abilityAtk, u32 abilityDef, u32 holdEffectAtk)
{
    s32 critChance = 0;

    if (gSideStatuses[battlerDef] & SIDE_STATUS_LUCKY_CHANT)
    {
        critChance = -1;
    }
    else if (gStatuses3[battlerAtk] & STATUS3_LASER_FOCUS
        || gMovesInfo[move].alwaysCriticalHit
        || (abilityAtk == ABILITY_MERCILESS && gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY))
    {
        critChance = -2;
    }
    else
    {
        critChance  = 2 * ((gBattleMons[battlerAtk].status2 & STATUS2_FOCUS_ENERGY) != 0)
                    + 1 * ((gBattleMons[battlerAtk].status2 & STATUS2_DRAGON_CHEER) != 0)
                    + gMovesInfo[move].criticalHitStage
                    + (holdEffectAtk == HOLD_EFFECT_SCOPE_LENS)
                    + 2 * (holdEffectAtk == HOLD_EFFECT_LUCKY_PUNCH && gBattleMons[battlerAtk].species == SPECIES_CHANSEY)
                    + 2 * BENEFITS_FROM_LEEK(battlerAtk, holdEffectAtk)
                    + 2 * (B_AFFECTION_MECHANICS == TRUE && GetBattlerAffectionHearts(battlerAtk) == AFFECTION_FIVE_HEARTS)
                    + (abilityAtk == ABILITY_SUPER_LUCK)
                    + gBattleStruct->bonusCritStages[gBattlerAttacker];

        if (critChance >= ARRAY_COUNT(sCriticalHitOdds))
            critChance = ARRAY_COUNT(sCriticalHitOdds) - 1;
    }

    if (critChance != -1 && (abilityDef == ABILITY_BATTLE_ARMOR || abilityDef == ABILITY_SHELL_ARMOR))
    {
        // Record ability only if move had 100% chance to get a crit
        if (recordAbility)
        {
            if (critChance == -2)
                RecordAbilityBattle(battlerDef, abilityDef);
            else if (sCriticalHitOdds[critChance] == 1)
                RecordAbilityBattle(battlerDef, abilityDef);
        }
        critChance = -1;
    }

    return critChance;
}

s32 CalcCritChanceStage(u32 battlerAtk, u32 battlerDef, u32 move, bool32 recordAbility)
{
    u32 abilityAtk = GetBattlerAbility(gBattlerAttacker);
    u32 abilityDef = GetBattlerAbility(gBattlerTarget);
    u32 holdEffectAtk = GetBattlerHoldEffect(battlerAtk, TRUE);
    return CalcCritChanceStageArgs(battlerAtk, battlerDef, move, recordAbility, abilityAtk, abilityDef, holdEffectAtk);
}
#undef BENEFITS_FROM_LEEK

s32 GetCritHitOdds(s32 critChanceIndex)
{
    if (critChanceIndex < 0)
        return -1;
    else
        return sCriticalHitOdds[critChanceIndex];
}

static void Cmd_critcalc(void)
{
    CMD_ARGS();

    u16 partySlot;
    s32 critChance = CalcCritChanceStage(gBattlerAttacker, gBattlerTarget, gCurrentMove, TRUE);
    gPotentialItemEffectBattler = gBattlerAttacker;

    if (gBattleTypeFlags & (BATTLE_TYPE_WALLY_TUTORIAL | BATTLE_TYPE_FIRST_BATTLE))
        gIsCriticalHit = FALSE;
    else if (critChance == -1)
        gIsCriticalHit = FALSE;
    else if (critChance == -2)
        gIsCriticalHit = TRUE;
    else
        gIsCriticalHit = RandomChance(RNG_CRITICAL_HIT, 1, sCriticalHitOdds[critChance]);

    // Counter for EVO_CRITICAL_HITS.
    partySlot = gBattlerPartyIndexes[gBattlerAttacker];
    if (gIsCriticalHit && GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER
        && !(gBattleTypeFlags & BATTLE_TYPE_MULTI && GetBattlerPosition(gBattlerAttacker) == B_POSITION_PLAYER_LEFT))
        gPartyCriticalHits[partySlot]++;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_damagecalc(void)
{
    CMD_ARGS();

    u8 moveType;

    GET_MOVE_TYPE(gCurrentMove, moveType);
    if (gMovesInfo[gCurrentMove].effect == EFFECT_SHELL_SIDE_ARM)
        gBattleStruct->swapDamageCategory = (gBattleStruct->shellSideArmCategory[gBattlerAttacker][gBattlerTarget] != gMovesInfo[gCurrentMove].category);
    gBattleMoveDamage = CalculateMoveDamage(gCurrentMove, gBattlerAttacker, gBattlerTarget, moveType, 0, gIsCriticalHit, TRUE, TRUE);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_typecalc(void)
{
    CMD_ARGS();

    u8 moveType;

    GET_MOVE_TYPE(gCurrentMove, moveType);
    CalcTypeEffectivenessMultiplier(gCurrentMove, moveType, gBattlerAttacker, gBattlerTarget, GetBattlerAbility(gBattlerTarget), TRUE);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_adjustdamage(void)
{
    CMD_ARGS();

    u8 holdEffect, param;
    u32 moveType;
    u32 affectionScore = GetBattlerAffectionHearts(gBattlerTarget);
    u32 rand = Random() % 100;

    GET_MOVE_TYPE(gCurrentMove, moveType);

    if (DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
        goto END;
    if (DoesDisguiseBlockMove(gBattlerTarget, gCurrentMove))
    {
        gBattleStruct->enduredDamage |= gBitTable[gBattlerTarget];
        goto END;
    }
    if (GetBattlerAbility(gBattlerTarget) == ABILITY_ICE_FACE && IS_MOVE_PHYSICAL(gCurrentMove) && gBattleMons[gBattlerTarget].species == SPECIES_EISCUE)
    {
        // Damage deals typeless 0 HP.
        gMoveResultFlags &= ~(MOVE_RESULT_SUPER_EFFECTIVE | MOVE_RESULT_NOT_VERY_EFFECTIVE);
        gBattleMoveDamage = 0;
        RecordAbilityBattle(gBattlerTarget, ABILITY_ICE_FACE);
        gBattleResources->flags->flags[gBattlerTarget] |= RESOURCE_FLAG_ICE_FACE;
        // Form change will be done after attack animation in Cmd_resultmessage.
        goto END;
    }
    if (gBattleMons[gBattlerTarget].hp > gBattleMoveDamage)
        goto END;

    holdEffect = GetBattlerHoldEffect(gBattlerTarget, TRUE);
    param = GetBattlerHoldEffectParam(gBattlerTarget);

    gPotentialItemEffectBattler = gBattlerTarget;

    if (holdEffect == HOLD_EFFECT_FOCUS_BAND && rand < param)
    {
        RecordItemEffectBattle(gBattlerTarget, holdEffect);
        gSpecialStatuses[gBattlerTarget].focusBanded = TRUE;
    }
    else if (B_STURDY >= GEN_5 && GetBattlerAbility(gBattlerTarget) == ABILITY_STURDY && BATTLER_MAX_HP(gBattlerTarget))
    {
        RecordAbilityBattle(gBattlerTarget, ABILITY_STURDY);
        gSpecialStatuses[gBattlerTarget].sturdied = TRUE;
    }
    else if (holdEffect == HOLD_EFFECT_FOCUS_SASH && BATTLER_MAX_HP(gBattlerTarget))
    {
        RecordItemEffectBattle(gBattlerTarget, holdEffect);
        gSpecialStatuses[gBattlerTarget].focusSashed = TRUE;
    }
    else if (B_AFFECTION_MECHANICS == TRUE && GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER && affectionScore >= AFFECTION_THREE_HEARTS)
    {
        if ((affectionScore == AFFECTION_FIVE_HEARTS && rand < 20)
         || (affectionScore == AFFECTION_FOUR_HEARTS && rand < 15)
         || (affectionScore == AFFECTION_THREE_HEARTS && rand < 10))
            gSpecialStatuses[gBattlerTarget].affectionEndured = TRUE;
    }

    if (gMovesInfo[gCurrentMove].effect != EFFECT_FALSE_SWIPE
        && !gProtectStructs[gBattlerTarget].endured
        && !gSpecialStatuses[gBattlerTarget].focusBanded
        && !gSpecialStatuses[gBattlerTarget].focusSashed
        && (B_AFFECTION_MECHANICS == FALSE || !gSpecialStatuses[gBattlerTarget].affectionEndured)
        && !gSpecialStatuses[gBattlerTarget].sturdied)
        goto END;

    // Handle reducing the dmg to 1 hp.
    gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - 1;
    gBattleStruct->enduredDamage |= gBitTable[gBattlerTarget];

    if (gProtectStructs[gBattlerTarget].endured)
    {
        gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED;
    }
    else if (gSpecialStatuses[gBattlerTarget].focusBanded || gSpecialStatuses[gBattlerTarget].focusSashed)
    {
        gMoveResultFlags |= MOVE_RESULT_FOE_HUNG_ON;
        gLastUsedItem = gBattleMons[gBattlerTarget].item;
        gSpecialStatuses[gBattlerTarget].focusBanded = FALSE;
        gSpecialStatuses[gBattlerTarget].focusSashed = FALSE;

    }
    else if (gSpecialStatuses[gBattlerTarget].sturdied)
    {
        gMoveResultFlags |= MOVE_RESULT_STURDIED;
        gLastUsedAbility = ABILITY_STURDY;
    }
    else if (B_AFFECTION_MECHANICS == TRUE && gSpecialStatuses[gBattlerTarget].affectionEndured)
    {
        gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED_AFFECTION;
    }

END:
    gBattlescriptCurrInstr = cmd->nextInstr;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) && gBattleMoveDamage >= 1)
        gSpecialStatuses[gBattlerAttacker].damagedMons |= gBitTable[gBattlerTarget];

    // Check gems and damage reducing berries.
    if (gSpecialStatuses[gBattlerTarget].berryReduced
        && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        && gBattleMons[gBattlerTarget].item)
    {
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_BerryReduceDmg;
        gLastUsedItem = gBattleMons[gBattlerTarget].item;
    }
    if (gSpecialStatuses[gBattlerAttacker].gemBoost
        && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        && gBattleMons[gBattlerAttacker].item
        && gMovesInfo[gCurrentMove].effect != EFFECT_PLEDGE
        && gCurrentMove != MOVE_STRUGGLE)
    {
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_GemActivates;
        gLastUsedItem = gBattleMons[gBattlerAttacker].item;
    }

    // B_WEATHER_STRONG_WINDS prints a string when it's about to reduce the power
    // of a move that is Super Effective against a Flying-type Pokémon.
    if (gBattleWeather & B_WEATHER_STRONG_WINDS)
    {
        if ((GetBattlerType(gBattlerTarget, 0, FALSE) == TYPE_FLYING
         && GetTypeModifier(moveType, GetBattlerType(gBattlerTarget, 0, FALSE)) >= UQ_4_12(2.0))
         || (GetBattlerType(gBattlerTarget, 1, FALSE) == TYPE_FLYING
         && GetTypeModifier(moveType, GetBattlerType(gBattlerTarget, 1, FALSE)) >= UQ_4_12(2.0))
         || (GetBattlerType(gBattlerTarget, 2, FALSE) == TYPE_FLYING
         && GetTypeModifier(moveType, GetBattlerType(gBattlerTarget, 2, FALSE)) >= UQ_4_12(2.0)))
        {
            gBattlerAbility = gBattlerTarget;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_AttackWeakenedByStrongWinds;
        }
    }
}

static void Cmd_multihitresultmessage(void)
{
    CMD_ARGS();

    if (gBattleControllerExecFlags)
        return;

    if (!(gMoveResultFlags & MOVE_RESULT_FAILED) && !(gMoveResultFlags & MOVE_RESULT_FOE_ENDURED))
    {
        if (gMoveResultFlags & MOVE_RESULT_STURDIED)
        {
            gMoveResultFlags &= ~(MOVE_RESULT_STURDIED | MOVE_RESULT_FOE_HUNG_ON);
            gSpecialStatuses[gBattlerTarget].sturdied = FALSE; // Delete this line to make Sturdy last for the duration of the whole move turn.
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_SturdiedMsg;
            return;
        }
        else if (gMoveResultFlags & MOVE_RESULT_FOE_HUNG_ON)
        {
            gLastUsedItem = gBattleMons[gBattlerTarget].item;
            gPotentialItemEffectBattler = gBattlerTarget;
            gMoveResultFlags &= ~(MOVE_RESULT_STURDIED | MOVE_RESULT_FOE_HUNG_ON);
            gSpecialStatuses[gBattlerTarget].focusBanded = FALSE; // Delete this line to make Focus Band last for the duration of the whole move turn.
            gSpecialStatuses[gBattlerTarget].focusSashed = FALSE; // Delete this line to make Focus Sash last for the duration of the whole move turn.
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_HangedOnMsg;
            return;
        }
    }
    gBattlescriptCurrInstr = cmd->nextInstr;

    // Print berry reducing message after result message.
    if (gSpecialStatuses[gBattlerTarget].berryReduced
        && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        gBattleStruct->ateBerry[gBattlerTarget & BIT_SIDE] |= gBitTable[gBattlerPartyIndexes[gBattlerTarget]];
        gSpecialStatuses[gBattlerTarget].berryReduced = FALSE;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_PrintBerryReduceString;
    }
}

static void Cmd_attackanimation(void)
{
    CMD_ARGS();

    u16 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);

    if (gBattleControllerExecFlags)
        return;

    if ((gHitMarker & (HITMARKER_NO_ANIMATIONS | HITMARKER_DISABLE_ANIMATION))
        && gCurrentMove != MOVE_TRANSFORM
        && gCurrentMove != MOVE_SUBSTITUTE
        && gCurrentMove != MOVE_ALLY_SWITCH
        // In a wild double battle gotta use the teleport animation if two wild pokemon are alive.
        && !(gCurrentMove == MOVE_TELEPORT && WILD_DOUBLE_BATTLE && GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT && IsBattlerAlive(BATTLE_PARTNER(gBattlerAttacker))))
    {
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_Pausex20;
        gBattleScripting.animTurn++;
        gBattleScripting.animTargetsHit++;
    }
    else
    {
        if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_2ND_HIT) // No animation on second hit
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }

        if ((moveTarget & MOVE_TARGET_BOTH
             || moveTarget & MOVE_TARGET_FOES_AND_ALLY
             || moveTarget & MOVE_TARGET_DEPENDS)
            && gBattleScripting.animTargetsHit)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }
        if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            u8 multihit;

            if (gBattleMons[gBattlerTarget].status2 & STATUS2_SUBSTITUTE)
                multihit = gMultiHitCounter;
            else if (gMultiHitCounter != 0 && gMultiHitCounter != 1)
            {
                if (gBattleMons[gBattlerTarget].hp <= gBattleMoveDamage)
                    multihit = 1;
                else
                    multihit = gMultiHitCounter;
            }
            else
                multihit = gMultiHitCounter;

            BtlController_EmitMoveAnimation(gBattlerAttacker, BUFFER_A, gCurrentMove, gBattleScripting.animTurn, gBattleMovePower, gBattleMoveDamage, gBattleMons[gBattlerAttacker].friendship, &gDisableStructs[gBattlerAttacker], multihit);
            gBattleScripting.animTurn++;
            gBattleScripting.animTargetsHit++;
            MarkBattlerForControllerExec(gBattlerAttacker);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_Pausex20;
        }
    }
}

static void Cmd_waitanimation(void)
{
    CMD_ARGS();

    if (gBattleControllerExecFlags == 0)
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_healthbarupdate(void)
{
    CMD_ARGS(u8 battler);

    if (gBattleControllerExecFlags)
        return;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) || (gHitMarker & HITMARKER_PASSIVE_DAMAGE))
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);

        if (DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove) && gDisableStructs[battler].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            PrepareStringBattle(STRINGID_SUBSTITUTEDAMAGED, battler);
        }
        else if (!DoesDisguiseBlockMove(battler, gCurrentMove))
        {
            s16 healthValue = min(gBattleMoveDamage, 10000); // Max damage (10000) not present in R/S, ensures that huge damage values don't change sign

            BtlController_EmitHealthBarUpdate(battler, BUFFER_A, healthValue);
            MarkBattlerForControllerExec(battler);

            if (GetBattlerSide(battler) == B_SIDE_PLAYER && gBattleMoveDamage > 0)
                gBattleResults.playerMonWasDamaged = TRUE;
        }
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Update the active battler's HP and various HP trackers (Substitute, Bide, etc.)
static void Cmd_datahpupdate(void)
{
    CMD_ARGS(u8 battler);

    u32 battler;

    if (gBattleControllerExecFlags)
        return;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) || (gHitMarker & HITMARKER_PASSIVE_DAMAGE))
    {
        battler = GetBattlerForBattleScript(cmd->battler);
        if (DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove) && gDisableStructs[battler].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            if (gDisableStructs[battler].substituteHP >= gBattleMoveDamage)
            {
                if (gSpecialStatuses[battler].shellBellDmg == 0)
                    gSpecialStatuses[battler].shellBellDmg = gBattleMoveDamage;
                gDisableStructs[battler].substituteHP -= gBattleMoveDamage;
                gHpDealt = gBattleMoveDamage;
            }
            else
            {
                if (gSpecialStatuses[battler].shellBellDmg == 0)
                    gSpecialStatuses[battler].shellBellDmg = gDisableStructs[battler].substituteHP;
                gHpDealt = gDisableStructs[battler].substituteHP;
                gDisableStructs[battler].substituteHP = 0;
            }
            // check substitute fading
            if (gDisableStructs[battler].substituteHP == 0)
            {
                gBattlescriptCurrInstr = cmd->nextInstr;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SubstituteFade;
                return;
            }
        }
        else if (DoesDisguiseBlockMove(battler, gCurrentMove))
        {
            // TODO: Convert this to a proper FORM_CHANGE type.
            u32 side = GetBattlerSide(battler);
            gBattleScripting.battler = battler;
            if (gBattleStruct->changedSpecies[side][gBattlerPartyIndexes[battler]] == SPECIES_NONE)
                gBattleStruct->changedSpecies[side][gBattlerPartyIndexes[battler]] = gBattleMons[battler].species;
            if (gBattleMons[battler].species == SPECIES_MIMIKYU_TOTEM_DISGUISED)
                gBattleMons[battler].species = SPECIES_MIMIKYU_TOTEM_BUSTED;
            else
                gBattleMons[battler].species = SPECIES_MIMIKYU_BUSTED;
            if (B_DISGUISE_HP_LOSS >= GEN_8)
                gBattleMoveDamage = GetNonDynamaxMaxHP(battler) / 8;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_TargetFormChange;
            return;
        }
        else
        {
            gHitMarker &= ~HITMARKER_IGNORE_SUBSTITUTE;
            if (gBattleMoveDamage < 0)
            {
                // Negative damage is HP gain
                gBattleMons[battler].hp += -gBattleMoveDamage;
                if (gBattleMons[battler].hp > gBattleMons[battler].maxHP)
                    gBattleMons[battler].hp = gBattleMons[battler].maxHP;
            }
            else
            {
                if (gHitMarker & HITMARKER_IGNORE_BIDE)
                {
                    gHitMarker &= ~HITMARKER_IGNORE_BIDE;
                }
                else
                {
                    gBideDmg[battler] += gBattleMoveDamage;
                    if (cmd->battler == BS_TARGET)
                        gBideTarget[battler] = gBattlerAttacker;
                    else
                        gBideTarget[battler] = gBattlerTarget;
                }

                // Deal damage to the battler
                if (gBattleMons[battler].hp > gBattleMoveDamage)
                {
                    gBattleMons[battler].hp -= gBattleMoveDamage;
                    gHpDealt = gBattleMoveDamage;
                }
                else
                {
                    gHpDealt = gBattleMons[battler].hp;
                    gBattleMons[battler].hp = 0;
                }

                // Record damage for Shell Bell
                if (gSpecialStatuses[battler].shellBellDmg == 0 && !(gHitMarker & HITMARKER_PASSIVE_DAMAGE))
                    gSpecialStatuses[battler].shellBellDmg = gHpDealt;

                // Note: While physicalDmg/specialDmg below are only distinguished between for Counter/Mirror Coat, they are
                //       used in combination as general damage trackers for other purposes. specialDmg is additionally used
                //       to help determine if a fire move should defrost the target.
                if (IS_MOVE_PHYSICAL(gCurrentMove) && !(gHitMarker & HITMARKER_PASSIVE_DAMAGE) && gMovesInfo[gCurrentMove].effect != EFFECT_PAIN_SPLIT)
                {
                    gProtectStructs[battler].physicalDmg = gHpDealt;
                    gSpecialStatuses[battler].physicalDmg = gHpDealt;
                    if (cmd->battler == BS_TARGET)
                    {
                        gProtectStructs[battler].physicalBattlerId = gBattlerAttacker;
                        gSpecialStatuses[battler].physicalBattlerId = gBattlerAttacker;
                    }
                    else
                    {
                        gProtectStructs[battler].physicalBattlerId = gBattlerTarget;
                        gSpecialStatuses[battler].physicalBattlerId = gBattlerTarget;
                    }
                }
                else if (!IS_MOVE_PHYSICAL(gCurrentMove) && !(gHitMarker & HITMARKER_PASSIVE_DAMAGE) && gMovesInfo[gCurrentMove].effect != EFFECT_PAIN_SPLIT)
                {
                    // Record special damage/attacker for Mirror Coat
                    gProtectStructs[battler].specialDmg = gHpDealt;
                    gSpecialStatuses[battler].specialDmg = gHpDealt;
                    if (cmd->battler == BS_TARGET)
                    {
                        gProtectStructs[battler].specialBattlerId = gBattlerAttacker;
                        gSpecialStatuses[battler].specialBattlerId = gBattlerAttacker;
                    }
                    else
                    {
                        gProtectStructs[battler].specialBattlerId = gBattlerTarget;
                        gSpecialStatuses[battler].specialBattlerId = gBattlerTarget;
                    }
                }
            }
            gHitMarker &= ~HITMARKER_PASSIVE_DAMAGE;

            // Send updated HP
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_HP_BATTLE, 0, sizeof(gBattleMons[battler].hp), &gBattleMons[battler].hp);
            MarkBattlerForControllerExec(battler);
        }
    }
    else
    {
        // MOVE_RESULT_NO_EFFECT was set
        battler = GetBattlerForBattleScript(cmd->battler);
        if (gSpecialStatuses[battler].shellBellDmg == 0)
            gSpecialStatuses[battler].shellBellDmg = IGNORE_SHELL_BELL;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_critmessage(void)
{
    CMD_ARGS();

    if (gBattleControllerExecFlags == 0)
    {
        if (gIsCriticalHit == TRUE && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            PrepareStringBattle(STRINGID_CRITICALHIT, gBattlerAttacker);

            // Signal for the trainer slide-in system.
            if (GetBattlerSide(gBattlerTarget) != B_SIDE_PLAYER && gBattleStruct->trainerSlideFirstCriticalHitMsgState != 2)
                gBattleStruct->trainerSlideFirstCriticalHitMsgState = 1;

            gBattleCommunication[MSG_DISPLAY] = 1;
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_effectivenesssound(void)
{
    CMD_ARGS();

    if (gBattleControllerExecFlags)
        return;

    if (!(gMoveResultFlags & MOVE_RESULT_MISSED))
    {
        switch (gMoveResultFlags & ~MOVE_RESULT_MISSED)
        {
        case MOVE_RESULT_SUPER_EFFECTIVE:
            BtlController_EmitPlaySE(gBattlerTarget, BUFFER_A, SE_SUPER_EFFECTIVE);
            MarkBattlerForControllerExec(gBattlerTarget);
            break;
        case MOVE_RESULT_NOT_VERY_EFFECTIVE:
            BtlController_EmitPlaySE(gBattlerTarget, BUFFER_A, SE_NOT_EFFECTIVE);
            MarkBattlerForControllerExec(gBattlerTarget);
            break;
        case MOVE_RESULT_DOESNT_AFFECT_FOE:
        case MOVE_RESULT_FAILED:
            // no sound
            break;
        case MOVE_RESULT_FOE_ENDURED:
        case MOVE_RESULT_ONE_HIT_KO:
        case MOVE_RESULT_FOE_HUNG_ON:
        case MOVE_RESULT_STURDIED:
        default:
            if (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                BtlController_EmitPlaySE(gBattlerTarget, BUFFER_A, SE_SUPER_EFFECTIVE);
                MarkBattlerForControllerExec(gBattlerTarget);
            }
            else if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
            {
                BtlController_EmitPlaySE(gBattlerTarget, BUFFER_A, SE_NOT_EFFECTIVE);
                MarkBattlerForControllerExec(gBattlerTarget);
            }
            else if (!(gMoveResultFlags & (MOVE_RESULT_DOESNT_AFFECT_FOE | MOVE_RESULT_FAILED)))
            {
                BtlController_EmitPlaySE(gBattlerTarget, BUFFER_A, SE_EFFECTIVE);
                MarkBattlerForControllerExec(gBattlerTarget);
            }
            break;
        }
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_resultmessage(void)
{
    CMD_ARGS();

    u32 stringId = 0;

    if (gBattleControllerExecFlags)
        return;

    // TODO: Convert this to a proper FORM_CHANGE type.
    // Do Ice Face form change which was set up in Cmd_adjustdamage.
    if (gBattleResources->flags->flags[gBattlerTarget] & RESOURCE_FLAG_ICE_FACE)
    {
        gBattleResources->flags->flags[gBattlerTarget] &= ~(RESOURCE_FLAG_ICE_FACE);
        gBattleMons[gBattlerTarget].species = SPECIES_EISCUE_NOICE_FACE;
        gBattleScripting.battler = gBattlerTarget; // For STRINGID_PKMNTRANSFORMED
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_IceFaceNullsDamage;
        return;
    }

    if (gMoveResultFlags & MOVE_RESULT_MISSED && (!(gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE) || gBattleCommunication[MISS_TYPE] > B_MSG_AVOIDED_ATK))
    {
        if (gBattleCommunication[MISS_TYPE] > B_MSG_AVOIDED_ATK) // Wonder Guard or Levitate - show the ability pop-up
            CreateAbilityPopUp(gBattlerTarget, gBattleMons[gBattlerTarget].ability, (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) != 0);
        stringId = gMissStringIds[gBattleCommunication[MISS_TYPE]];
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
    else
    {
        gBattleCommunication[MSG_DISPLAY] = 1;
        switch (gMoveResultFlags & ~MOVE_RESULT_MISSED)
        {
        case MOVE_RESULT_SUPER_EFFECTIVE:
            if (!gMultiHitCounter)  // Don't print effectiveness on each hit in a multi hit attack
            {
                // Signal for the trainer slide-in system.
                if (GetBattlerSide(gBattlerTarget) != B_SIDE_PLAYER && gBattleStruct->trainerSlideFirstSuperEffectiveHitMsgState != 2)
                    gBattleStruct->trainerSlideFirstSuperEffectiveHitMsgState = 1;

                stringId = STRINGID_SUPEREFFECTIVE;
            }
            break;
        case MOVE_RESULT_NOT_VERY_EFFECTIVE:
            if (!gMultiHitCounter)
                stringId = STRINGID_NOTVERYEFFECTIVE;
            break;
        case MOVE_RESULT_ONE_HIT_KO:
            stringId = STRINGID_ONEHITKO;
            break;
        case MOVE_RESULT_FOE_ENDURED:
            stringId = STRINGID_PKMNENDUREDHIT;
            break;
        case MOVE_RESULT_FAILED:
            stringId = STRINGID_BUTITFAILED;
            break;
        case MOVE_RESULT_DOESNT_AFFECT_FOE:
            stringId = STRINGID_ITDOESNTAFFECT;
            break;
        case MOVE_RESULT_FOE_HUNG_ON:
            gLastUsedItem = gBattleMons[gBattlerTarget].item;
            gPotentialItemEffectBattler = gBattlerTarget;
            gMoveResultFlags &= ~(MOVE_RESULT_FOE_ENDURED | MOVE_RESULT_FOE_HUNG_ON);
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_HangedOnMsg;
            return;
        default:
            if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
            {
                stringId = STRINGID_ITDOESNTAFFECT;
            }
            else if (gMoveResultFlags & MOVE_RESULT_ONE_HIT_KO)
            {
                gMoveResultFlags &= ~MOVE_RESULT_ONE_HIT_KO;
                gMoveResultFlags &= ~MOVE_RESULT_SUPER_EFFECTIVE;
                gMoveResultFlags &= ~MOVE_RESULT_NOT_VERY_EFFECTIVE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_OneHitKOMsg;
                return;
            }
            else if (gMoveResultFlags & MOVE_RESULT_STURDIED)
            {
                gMoveResultFlags &= ~(MOVE_RESULT_STURDIED | MOVE_RESULT_FOE_ENDURED | MOVE_RESULT_FOE_HUNG_ON);
                gSpecialStatuses[gBattlerTarget].sturdied = FALSE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SturdiedMsg;
                return;
            }
            else if (gMoveResultFlags & MOVE_RESULT_FOE_ENDURED)
            {
                gMoveResultFlags &= ~(MOVE_RESULT_FOE_ENDURED | MOVE_RESULT_FOE_HUNG_ON);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_EnduredMsg;
                return;
            }
            else if (gMoveResultFlags & MOVE_RESULT_FOE_HUNG_ON)
            {
                gLastUsedItem = gBattleMons[gBattlerTarget].item;
                gPotentialItemEffectBattler = gBattlerTarget;
                gMoveResultFlags &= ~(MOVE_RESULT_FOE_ENDURED | MOVE_RESULT_FOE_HUNG_ON);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_HangedOnMsg;
                return;
            }
            else if (gMoveResultFlags & MOVE_RESULT_FAILED)
            {
                stringId = STRINGID_BUTITFAILED;
            }
            else if (B_AFFECTION_MECHANICS == TRUE && (gMoveResultFlags & MOVE_RESULT_FOE_ENDURED_AFFECTION))
            {
                gSpecialStatuses[gBattlerTarget].affectionEndured = FALSE;
                gMoveResultFlags &= ~MOVE_RESULT_FOE_ENDURED_AFFECTION;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AffectionBasedEndurance;
                return;
            }
            else
            {
                gBattleCommunication[MSG_DISPLAY] = 0;
            }
        }
    }

    if (stringId)
        PrepareStringBattle(stringId, gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;

    // Print berry reducing message after result message.
    if (gSpecialStatuses[gBattlerTarget].berryReduced
        && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        gBattleStruct->ateBerry[gBattlerTarget & BIT_SIDE] |= gBitTable[gBattlerPartyIndexes[gBattlerTarget]];
        gSpecialStatuses[gBattlerTarget].berryReduced = FALSE;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_PrintBerryReduceString;
    }
}

static void Cmd_printstring(void)
{
    CMD_ARGS(u16 id);

    if (gBattleControllerExecFlags == 0)
    {
        u16 id = (cmd->id == 0 ? gBattleScripting.savedStringId : cmd->id);

        gBattlescriptCurrInstr = cmd->nextInstr;
        PrepareStringBattle(id, gBattlerAttacker);
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

static void Cmd_printselectionstring(void)
{
    CMD_ARGS(u16 id);

    BtlController_EmitPrintSelectionString(gBattlerAttacker, BUFFER_A, cmd->id);
    MarkBattlerForControllerExec(gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;
    gBattleCommunication[MSG_DISPLAY] = 1;
}

static void Cmd_waitmessage(void)
{
    CMD_ARGS(u16 time);

    if (gBattleControllerExecFlags == 0)
    {
        if (!gBattleCommunication[MSG_DISPLAY])
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            u16 toWait = cmd->time;
            if (++gPauseCounterBattle >= toWait)
            {
                gPauseCounterBattle = 0;
                gBattlescriptCurrInstr = cmd->nextInstr;
                gBattleCommunication[MSG_DISPLAY] = 0;
            }
        }
    }
}

static void Cmd_printfromtable(void)
{
    CMD_ARGS(const u16 *ptr);

    if (gBattleControllerExecFlags == 0)
    {
        const u16 *ptr = cmd->ptr;
        ptr += gBattleCommunication[MULTISTRING_CHOOSER];

        gBattlescriptCurrInstr = cmd->nextInstr;
        PrepareStringBattle(*ptr, gBattlerAttacker);
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

static void Cmd_printselectionstringfromtable(void)
{
    CMD_ARGS(const u16 *ptr);

    if (gBattleControllerExecFlags == 0)
    {
        const u16 *ptr = cmd->ptr;
        ptr += gBattleCommunication[MULTISTRING_CHOOSER];

        BtlController_EmitPrintSelectionString(gBattlerAttacker, BUFFER_A, *ptr);
        MarkBattlerForControllerExec(gBattlerAttacker);

        gBattlescriptCurrInstr = cmd->nextInstr;
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

u8 GetBattlerTurnOrderNum(u8 battler)
{
    s32 i;
    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBattlerByTurnOrder[i] == battler)
            break;
    }
    return i;
}

static void CheckSetUnburden(u8 battler)
{
    if (GetBattlerAbility(battler) == ABILITY_UNBURDEN)
    {
        gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_UNBURDEN;
        RecordAbilityBattle(battler, ABILITY_UNBURDEN);
    }
}

// battlerStealer steals the item of battlerItem
void StealTargetItem(u8 battlerStealer, u8 battlerItem)
{
    gLastUsedItem = gBattleMons[battlerItem].item;
    gBattleMons[battlerItem].item = 0;

    RecordItemEffectBattle(battlerItem, 0);
    RecordItemEffectBattle(battlerStealer, ItemId_GetHoldEffect(gLastUsedItem));
    gBattleMons[battlerStealer].item = gLastUsedItem;

    CheckSetUnburden(battlerItem);
    gBattleResources->flags->flags[battlerStealer] &= ~RESOURCE_FLAG_UNBURDEN;

    BtlController_EmitSetMonData(battlerStealer, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gLastUsedItem), &gLastUsedItem); // set attacker item
    MarkBattlerForControllerExec(battlerStealer);

    BtlController_EmitSetMonData(battlerItem, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].item), &gBattleMons[battlerItem].item);  // remove target item
    MarkBattlerForControllerExec(battlerItem);

    gBattleStruct->choicedMove[battlerItem] = 0;

    TrySaveExchangedItem(battlerItem, gLastUsedItem);
}

#define INCREMENT_RESET_RETURN                  \
{                                               \
    gBattlescriptCurrInstr++;                   \
    gBattleScripting.moveEffect = 0;            \
    return;                                     \
}

#define RESET_RETURN                            \
{                                               \
    gBattleScripting.moveEffect = 0;            \
    return;                                     \
}

void SetMoveEffect(bool32 primary, bool32 certain)
{
    s32 i, affectsUser = 0;
    bool32 statusChanged = FALSE;
    bool32 mirrorArmorReflected = (GetBattlerAbility(gBattlerTarget) == ABILITY_MIRROR_ARMOR);
    u32 flags = 0;
    u16 battlerAbility;
    bool8 activateAfterFaint = FALSE;

    // NULL move effect
    if (gBattleScripting.moveEffect == 0)
        return;

    if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_1ST_HIT
        && IsBattlerAlive(gBattlerTarget)
        && IsFinalStrikeEffect(gBattleScripting.moveEffect))
    {
        gBattlescriptCurrInstr++;
        return;
    }

    switch (gBattleScripting.moveEffect) // Set move effects which happen later on
    {
    case MOVE_EFFECT_KNOCK_OFF:
    case MOVE_EFFECT_SMACK_DOWN:
    case MOVE_EFFECT_REMOVE_STATUS:
    case MOVE_EFFECT_STOCKPILE_WORE_OFF:
        gBattleStruct->moveEffect2 = gBattleScripting.moveEffect;
        gBattlescriptCurrInstr++;
        return;
    case MOVE_EFFECT_STEALTH_ROCK:
    case MOVE_EFFECT_SPIKES:
    case MOVE_EFFECT_PAYDAY:
    case MOVE_EFFECT_STEAL_ITEM:
    case MOVE_EFFECT_BUG_BITE:
        activateAfterFaint = TRUE;
        break;
    }

    if (gBattleScripting.moveEffect & MOVE_EFFECT_AFFECTS_USER)
    {
        gEffectBattler = gBattlerAttacker; // battler that effects get applied on
        gBattleScripting.moveEffect &= ~MOVE_EFFECT_AFFECTS_USER;
        affectsUser = MOVE_EFFECT_AFFECTS_USER;
        gBattleScripting.battler = gBattlerTarget; // theoretically the attacker
    }
    else
    {
        gEffectBattler = gBattlerTarget;
        gBattleScripting.battler = gBattlerAttacker;
    }

    battlerAbility = GetBattlerAbility(gEffectBattler);

     // Just in case this flag is still set
    gBattleScripting.moveEffect &= ~MOVE_EFFECT_CERTAIN;

    if (!primary && affectsUser != MOVE_EFFECT_AFFECTS_USER
      && !(gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
      && (battlerAbility == ABILITY_SHIELD_DUST || GetBattlerHoldEffect(gEffectBattler, TRUE) == HOLD_EFFECT_COVERT_CLOAK))
    {
        if (battlerAbility == ABILITY_SHIELD_DUST)
            RecordAbilityBattle(gEffectBattler, battlerAbility);
        else
            RecordItemEffectBattle(gEffectBattler, HOLD_EFFECT_COVERT_CLOAK);
        INCREMENT_RESET_RETURN
    }

    if (gSideStatuses[GetBattlerSide(gEffectBattler)] & SIDE_STATUS_SAFEGUARD && !(gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
        && !primary && gBattleScripting.moveEffect <= MOVE_EFFECT_CONFUSION)
        INCREMENT_RESET_RETURN

    if (!(gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
      && TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove)
      && !primary
      && gBattleScripting.moveEffect != MOVE_EFFECT_CHARGING)
        INCREMENT_RESET_RETURN

    if (!IsBattlerAlive(gEffectBattler) && !activateAfterFaint)
        INCREMENT_RESET_RETURN

    if (DoesSubstituteBlockMove(gBattlerAttacker, gEffectBattler, gCurrentMove) && affectsUser != MOVE_EFFECT_AFFECTS_USER)
        INCREMENT_RESET_RETURN

    if (gBattleScripting.moveEffect <= PRIMARY_STATUS_MOVE_EFFECT) // status change
    {
        const u8 *cancelMultiTurnMovesResult = NULL;
        switch (sStatusFlagsForMoveEffects[gBattleScripting.moveEffect])
        {
        case STATUS1_SLEEP:
            // check active uproar
            if (battlerAbility != ABILITY_SOUNDPROOF || B_UPROAR_IGNORE_SOUNDPROOF >= GEN_5)
            {
                for (i = 0; i < gBattlersCount && !(gBattleMons[i].status2 & STATUS2_UPROAR); i++)
                    ;
            }
            else
            {
                i = gBattlersCount;
            }

            if (i != gBattlersCount)
                break;
            if (!CanBeSlept(gEffectBattler, GetBattlerAbility(gEffectBattler)))
                break;

            cancelMultiTurnMovesResult = CancelMultiTurnMoves(gEffectBattler);
            if (cancelMultiTurnMovesResult)
                gBattlescriptCurrInstr = cancelMultiTurnMovesResult;
            statusChanged = TRUE;
            break;
        case STATUS1_POISON:
            if ((battlerAbility == ABILITY_IMMUNITY || battlerAbility == ABILITY_PASTEL_VEIL)
                && (primary == TRUE || certain == TRUE))
            {
                gLastUsedAbility = battlerAbility;
                RecordAbilityBattle(gEffectBattler, battlerAbility);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                if (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                    gHitMarker &= ~HITMARKER_STATUS_ABILITY_EFFECT;
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                }
                RESET_RETURN
            }
            if (!CanPoisonType(gBattleScripting.battler, gEffectBattler)
                && (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                && (primary == TRUE || certain == TRUE))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STATUS_HAD_NO_EFFECT;
                RESET_RETURN
            }
            if (!CanBePoisoned(gBattleScripting.battler, gEffectBattler, GetBattlerAbility(gEffectBattler)))
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_BURN:
            if ((battlerAbility == ABILITY_WATER_VEIL || battlerAbility == ABILITY_WATER_BUBBLE)
              && (primary == TRUE || certain == TRUE))
            {
                gLastUsedAbility = battlerAbility;
                RecordAbilityBattle(gEffectBattler, battlerAbility);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;
                if (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                    gHitMarker &= ~HITMARKER_STATUS_ABILITY_EFFECT;
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                }
                RESET_RETURN
            }
            if (IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_FIRE)
                && (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                && (primary == TRUE || certain == TRUE))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STATUS_HAD_NO_EFFECT;
                RESET_RETURN
            }

            if (B_STATUS_TYPE_IMMUNITY == GEN_1)
            {
                u8 moveType = 0;
                GET_MOVE_TYPE(gCurrentMove, moveType);
                if (primary == FALSE && certain == FALSE && IS_BATTLER_OF_TYPE(gEffectBattler, moveType))
                    break;
            }

            if (!CanBeBurned(gEffectBattler, GetBattlerAbility(gEffectBattler)))
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_FREEZE:
            if (B_STATUS_TYPE_IMMUNITY == GEN_1)
            {
                u8 moveType = 0;
                GET_MOVE_TYPE(gCurrentMove, moveType);
                if (primary == FALSE && certain == FALSE && IS_BATTLER_OF_TYPE(gEffectBattler, moveType))
                    break;
            }
            if (!CanBeFrozen(gEffectBattler))
                break;

            cancelMultiTurnMovesResult = CancelMultiTurnMoves(gEffectBattler);
            if (cancelMultiTurnMovesResult)
                gBattlescriptCurrInstr = cancelMultiTurnMovesResult;
            statusChanged = TRUE;
            break;
        case STATUS1_PARALYSIS:
            if (battlerAbility == ABILITY_LIMBER)
            {
                if (primary == TRUE || certain == TRUE)
                {
                    gLastUsedAbility = ABILITY_LIMBER;
                    RecordAbilityBattle(gEffectBattler, ABILITY_LIMBER);

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_PRLZPrevention;

                    if (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                        gHitMarker &= ~HITMARKER_STATUS_ABILITY_EFFECT;
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                    }
                    RESET_RETURN
                }
                else
                    break;
            }
            if (B_STATUS_TYPE_IMMUNITY == GEN_1)
            {
                u8 moveType = 0;
                GET_MOVE_TYPE(gCurrentMove, moveType);
                if (primary == FALSE && certain == FALSE && IS_BATTLER_OF_TYPE(gEffectBattler, moveType))
                    break;
            }
            if (!CanParalyzeType(gBattleScripting.battler, gEffectBattler)
                && (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                && (primary == TRUE || certain == TRUE))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PRLZPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                RESET_RETURN
            }
            if (!CanParalyzeType(gBattleScripting.battler, gEffectBattler))
                break;
            if (!CanBeParalyzed(gEffectBattler, GetBattlerAbility(gEffectBattler)))
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_TOXIC_POISON:
            if ((battlerAbility == ABILITY_IMMUNITY || battlerAbility == ABILITY_PASTEL_VEIL)
             && (primary == TRUE || certain == TRUE))
            {
                gLastUsedAbility = battlerAbility;
                RecordAbilityBattle(gEffectBattler, battlerAbility);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                if (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                    gHitMarker &= ~HITMARKER_STATUS_ABILITY_EFFECT;
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                }
                RESET_RETURN
            }
            if (!CanPoisonType(gBattleScripting.battler, gEffectBattler)
                && (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
                && (primary == TRUE || certain == TRUE))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STATUS_HAD_NO_EFFECT;
                RESET_RETURN
            }
            if (gBattleMons[gEffectBattler].status1)
                break;
            if (CanBePoisoned(gBattleScripting.battler, gEffectBattler, GetBattlerAbility(gEffectBattler)))
            {
                // It's redundant, because at this point we know the status1 value is 0.
                gBattleMons[gEffectBattler].status1 &= ~STATUS1_TOXIC_POISON;
                gBattleMons[gEffectBattler].status1 &= ~STATUS1_POISON;
                statusChanged = TRUE;
                break;
            }
            else
            {
                gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
            }
            break;
        case STATUS1_FROSTBITE:
            if (B_STATUS_TYPE_IMMUNITY == GEN_1)
            {
                u8 moveType = 0;
                GET_MOVE_TYPE(gCurrentMove, moveType);
                if (primary == FALSE && certain == FALSE && IS_BATTLER_OF_TYPE(gEffectBattler, moveType))
                    break;
            }
            if (!CanGetFrostbite(gEffectBattler))
                break;

            statusChanged = TRUE;
            break;
        }
        if (statusChanged == TRUE)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);

            if (sStatusFlagsForMoveEffects[gBattleScripting.moveEffect] == STATUS1_SLEEP)
            {
                if (B_SLEEP_TURNS >= GEN_5)
                    gBattleMons[gEffectBattler].status1 |= STATUS1_SLEEP_TURN(1 + RandomUniform(RNG_SLEEP_TURNS, 1, 3));
                else
                    gBattleMons[gEffectBattler].status1 |= STATUS1_SLEEP_TURN(1 + RandomUniform(RNG_SLEEP_TURNS, 2, 5));
            }
            else
            {
                gBattleMons[gEffectBattler].status1 |= sStatusFlagsForMoveEffects[gBattleScripting.moveEffect];
            }

            gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];

            BtlController_EmitSetMonData(gEffectBattler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].status1), &gBattleMons[gEffectBattler].status1);
            MarkBattlerForControllerExec(gEffectBattler);

            if (gHitMarker & HITMARKER_STATUS_ABILITY_EFFECT)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STATUSED_BY_ABILITY;
                gHitMarker &= ~HITMARKER_STATUS_ABILITY_EFFECT;
            }
            else
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STATUSED;
            }

            // for synchronize
            if (gBattleScripting.moveEffect == MOVE_EFFECT_POISON
             || gBattleScripting.moveEffect == MOVE_EFFECT_TOXIC
             || gBattleScripting.moveEffect == MOVE_EFFECT_PARALYSIS
             || gBattleScripting.moveEffect == MOVE_EFFECT_BURN)
             {
                gBattleStruct->synchronizeMoveEffect = gBattleScripting.moveEffect;
                gHitMarker |= HITMARKER_SYNCHRONISE_EFFECT;
             }

            if (gBattleScripting.moveEffect == MOVE_EFFECT_POISON || gBattleScripting.moveEffect == MOVE_EFFECT_TOXIC)
                gBattleStruct->poisonPuppeteerConfusion = TRUE;

            return;
        }
        else if (statusChanged == FALSE)
        {
            gBattleScripting.moveEffect = 0;
            gBattlescriptCurrInstr++;
            return;
        }
        return;
    }
    else
    {
        if (gBattleMons[gEffectBattler].status2 & sStatusFlagsForMoveEffects[gBattleScripting.moveEffect])
        {
            gBattlescriptCurrInstr++;
        }
        else
        {
            switch (gBattleScripting.moveEffect)
            {
            case MOVE_EFFECT_CONFUSION:
                if (!CanBeConfused(gEffectBattler))
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gEffectBattler].status2 |= STATUS2_CONFUSION_TURN(((Random()) % 4) + 2); // 2-5 turns

                    // If the confusion is activating due to being released from Sky Drop, go to "confused due to fatigue" script.
                    // Otherwise, do normal confusion script.
                    if (gCurrentMove == MOVE_SKY_DROP)
                    {
                        gBattleMons[gEffectBattler].status2 &= ~(STATUS2_LOCK_CONFUSE);
                        gBattlerAttacker = gEffectBattler;
                        gBattlescriptCurrInstr = BattleScript_ThrashConfuses;
                    }
                    else
                    {
                        BattleScriptPush(gBattlescriptCurrInstr + 1);
                        gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];
                    }
                }
                break;
            case MOVE_EFFECT_FLINCH:
                if (battlerAbility == ABILITY_INNER_FOCUS)
                {
                    // Inner Focus ALWAYS prevents flinching but only activates
                    // on a move that's supposed to flinch, like Fake Out
                    if (primary == TRUE || certain == TRUE)
                    {
                        gLastUsedAbility = ABILITY_INNER_FOCUS;
                        gBattlerAbility = gEffectBattler;
                        RecordAbilityBattle(gEffectBattler, ABILITY_INNER_FOCUS);
                        gBattlescriptCurrInstr = BattleScript_FlinchPrevention;
                    }
                    else
                    {
                        gBattlescriptCurrInstr++;
                    }
                }
                else if (GetBattlerTurnOrderNum(gEffectBattler) > gCurrentTurnActionNumber
                        && !(GetActiveGimmick(gEffectBattler) == GIMMICK_DYNAMAX))
                {
                    gBattleMons[gEffectBattler].status2 |= sStatusFlagsForMoveEffects[gBattleScripting.moveEffect];
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_UPROAR:
                if (!(gBattleMons[gEffectBattler].status2 & STATUS2_UPROAR))
                {
                    gBattleMons[gEffectBattler].status2 |= STATUS2_MULTIPLETURNS;
                    gLockedMoves[gEffectBattler] = gCurrentMove;
                    gBattleMons[gEffectBattler].status2 |= STATUS2_UPROAR_TURN(B_UPROAR_TURNS >= GEN_5 ? 3 : (Random() & 3) + 2);

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];
                }
                else
                {
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_PAYDAY:
                // Don't scatter coins on the second hit of Parental Bond
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER && gSpecialStatuses[gBattlerAttacker].parentalBondState!= PARENTAL_BOND_2ND_HIT)
                {
                    u16 payday = gPaydayMoney;
                    u16 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);
                    gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 5);
                    if (payday > gPaydayMoney)
                        gPaydayMoney = 0xFFFF;

                    // For a move that hits multiple targets (i.e. Make it Rain)
                    // we only want to print the message on the final hit
                    if (!((moveTarget == MOVE_TARGET_BOTH || moveTarget == MOVE_TARGET_FOES_AND_ALLY)
                        && GetNextTarget(moveTarget, TRUE) != MAX_BATTLERS_COUNT))
                    {
                        BattleScriptPush(gBattlescriptCurrInstr + 1);
                        gBattlescriptCurrInstr = BattleScript_MoveEffectPayDay;
                    }
                    else
                        gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_HAPPY_HOUR:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER && !gBattleStruct->moneyMultiplierMove)
                {
                    gBattleStruct->moneyMultiplier *= 2;
                    gBattleStruct->moneyMultiplierMove = 1;
                }
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_TRI_ATTACK:
                if (gBattleMons[gEffectBattler].status1)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    static const u8 sTriAttackEffects[] =
                    {
                        MOVE_EFFECT_BURN,
                        MOVE_EFFECT_FREEZE_OR_FROSTBITE,
                        MOVE_EFFECT_PARALYSIS
                    };
                    gBattleScripting.moveEffect = RandomElement(RNG_TRI_ATTACK, sTriAttackEffects);
                    SetMoveEffect(primary, certain);
                }
                break;
            case MOVE_EFFECT_CHARGING:
                gBattleMons[gEffectBattler].status2 |= STATUS2_MULTIPLETURNS;
                gLockedMoves[gEffectBattler] = gCurrentMove;
                gProtectStructs[gEffectBattler].chargingTurn = TRUE;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_WRAP:
                if (gBattleMons[gEffectBattler].status2 & STATUS2_WRAPPED)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gEffectBattler].status2 |= STATUS2_WRAPPED;
                    if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_GRIP_CLAW)
                        gDisableStructs[gEffectBattler].wrapTurns = B_BINDING_TURNS >= GEN_5 ? 7 : 5;
                    else
                        gDisableStructs[gEffectBattler].wrapTurns = B_BINDING_TURNS >= GEN_5 ? (Random() % 2) + 4 : (Random() % 4) + 2;

                    gBattleStruct->wrappedMove[gEffectBattler] = gCurrentMove;
                    gBattleStruct->wrappedBy[gEffectBattler] = gBattlerAttacker;

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];

                    for (gBattleCommunication[MULTISTRING_CHOOSER] = 0; gBattleCommunication[MULTISTRING_CHOOSER] < NUM_TRAPPING_MOVES; gBattleCommunication[MULTISTRING_CHOOSER]++)
                    {
                        if (sTrappingMoves[gBattleCommunication[MULTISTRING_CHOOSER]] == gCurrentMove)
                            break;
                    }
                }
                break;
            case MOVE_EFFECT_ATK_PLUS_1:
            case MOVE_EFFECT_DEF_PLUS_1:
            case MOVE_EFFECT_SPD_PLUS_1:
            case MOVE_EFFECT_SP_ATK_PLUS_1:
            case MOVE_EFFECT_SP_DEF_PLUS_1:
            case MOVE_EFFECT_ACC_PLUS_1:
            case MOVE_EFFECT_EVS_PLUS_1:
                if (NoAliveMonsForEitherParty()
                  || ChangeStatBuffs(SET_STAT_BUFF_VALUE(1),
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_PLUS_1 + 1,
                                    affectsUser | STAT_CHANGE_UPDATE_MOVE_EFFECT, 0) == STAT_CHANGE_DIDNT_WORK)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleScripting.moveEffect & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StatUp;
                }
                break;
            case MOVE_EFFECT_ATK_MINUS_1:
            case MOVE_EFFECT_DEF_MINUS_1:
            case MOVE_EFFECT_SPD_MINUS_1:
            case MOVE_EFFECT_SP_ATK_MINUS_1:
            case MOVE_EFFECT_SP_DEF_MINUS_1:
            case MOVE_EFFECT_ACC_MINUS_1:
            case MOVE_EFFECT_EVS_MINUS_1:
                if (affectsUser == MOVE_EFFECT_AFFECTS_USER)
                    flags = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN;
                else
                    flags = 0;
                if (mirrorArmorReflected)
                    flags |= (STAT_CHANGE_ALLOW_PTR * !affectsUser);
                else
                    flags |= STAT_CHANGE_UPDATE_MOVE_EFFECT;

                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(1) | STAT_BUFF_NEGATIVE,
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_MINUS_1 + 1,
                                    flags, gBattlescriptCurrInstr + 1) == STAT_CHANGE_DIDNT_WORK)
                {
                    if (!mirrorArmorReflected)
                        gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleScripting.moveEffect & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StatDown;
                }
                break;
            case MOVE_EFFECT_ATK_PLUS_2:
            case MOVE_EFFECT_DEF_PLUS_2:
            case MOVE_EFFECT_SPD_PLUS_2:
            case MOVE_EFFECT_SP_ATK_PLUS_2:
            case MOVE_EFFECT_SP_DEF_PLUS_2:
            case MOVE_EFFECT_ACC_PLUS_2:
            case MOVE_EFFECT_EVS_PLUS_2:
                if (NoAliveMonsForEitherParty()
                  || ChangeStatBuffs(SET_STAT_BUFF_VALUE(2),
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_PLUS_2 + 1,
                                    affectsUser | STAT_CHANGE_UPDATE_MOVE_EFFECT, 0) == STAT_CHANGE_DIDNT_WORK)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleScripting.moveEffect & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StatUp;
                }
                break;
            case MOVE_EFFECT_ATK_MINUS_2:
            case MOVE_EFFECT_DEF_MINUS_2:
            case MOVE_EFFECT_SPD_MINUS_2:
            case MOVE_EFFECT_SP_ATK_MINUS_2:
            case MOVE_EFFECT_SP_DEF_MINUS_2:
            case MOVE_EFFECT_ACC_MINUS_2:
            case MOVE_EFFECT_EVS_MINUS_2:
                if (affectsUser == MOVE_EFFECT_AFFECTS_USER)
                    flags = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN;
                else
                    flags = 0;
                if (mirrorArmorReflected && !affectsUser)
                    flags |= STAT_CHANGE_ALLOW_PTR;
                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(2) | STAT_BUFF_NEGATIVE,
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_MINUS_2 + 1,
                                    flags | STAT_CHANGE_UPDATE_MOVE_EFFECT, gBattlescriptCurrInstr + 1) == STAT_CHANGE_DIDNT_WORK)
                {
                    if (!mirrorArmorReflected)
                        gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleScripting.moveEffect & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StatDown;
                }
                break;
            case MOVE_EFFECT_RECHARGE:
                gBattleMons[gEffectBattler].status2 |= STATUS2_RECHARGE;
                gDisableStructs[gEffectBattler].rechargeTimer = 2;
                gLockedMoves[gEffectBattler] = gCurrentMove;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_RAGE:
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_RAGE;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_STEAL_ITEM:
                {
                    if (!CanStealItem(gBattlerAttacker, gBattlerTarget, gBattleMons[gBattlerTarget].item)
                        || gBattleMons[gBattlerAttacker].item != ITEM_NONE
                        || gBattleMons[gBattlerTarget].item == ITEM_NONE)
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else if (GetBattlerAbility(gBattlerTarget) == ABILITY_STICKY_HOLD)
                    {
                        BattleScriptPush(gBattlescriptCurrInstr + 1);
                        gBattlescriptCurrInstr = BattleScript_NoItemSteal;

                        gLastUsedAbility = gBattleMons[gBattlerTarget].ability;
                        RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
                    }
                    else
                    {
                        StealTargetItem(gBattlerAttacker, gBattlerTarget);  // Attacker steals target item
                        gBattleMons[gBattlerAttacker].item = ITEM_NONE; // Item assigned later on with thief (see MOVEEND_CHANGED_ITEMS)
                        gBattleStruct->changedItems[gBattlerAttacker] = gLastUsedItem; // Stolen item to be assigned later
                        BattleScriptPush(gBattlescriptCurrInstr + 1);
                        gBattlescriptCurrInstr = BattleScript_ItemSteal;
                    }
                }
                break;
            case MOVE_EFFECT_PREVENT_ESCAPE:
                gBattleMons[gBattlerTarget].status2 |= STATUS2_ESCAPE_PREVENTION;
                gDisableStructs[gBattlerTarget].battlerPreventingEscape = gBattlerAttacker;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_NIGHTMARE:
                gBattleMons[gBattlerTarget].status2 |= STATUS2_NIGHTMARE;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_ALL_STATS_UP:
                if (!NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_AllStatsUp;
                }
                break;
            case MOVE_EFFECT_RAPID_SPIN:
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_RapidSpinAway;
                break;
            case MOVE_EFFECT_ATK_DEF_DOWN: // SuperPower
                if (!NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_AtkDefDown;
                }
                break;
            case MOVE_EFFECT_DEF_SPDEF_DOWN: // Close Combat
                if (!NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_DefSpDefDown;
                }
                break;
            case MOVE_EFFECT_RECOIL_HP_25: // Struggle
                gBattleMoveDamage = (gBattleMons[gEffectBattler].maxHP) / 4;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                if (GetBattlerAbility(gEffectBattler) == ABILITY_PARENTAL_BOND)
                    gBattleMoveDamage *= 2;

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_MoveEffectRecoil;
                break;
            case MOVE_EFFECT_THRASH:
                // Petal Dance doesn't lock mons that copy the move with Dancer
                if (gSpecialStatuses[gEffectBattler].dancerUsedMove)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gEffectBattler].status2 |= STATUS2_MULTIPLETURNS;
                    gLockedMoves[gEffectBattler] = gCurrentMove;
                    gBattleMons[gEffectBattler].status2 |= STATUS2_LOCK_CONFUSE_TURN(RandomUniform(RNG_RAMPAGE_TURNS, 2, 3));
                }
                break;
            case MOVE_EFFECT_CLEAR_SMOG:
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[gEffectBattler].statStages[i] != DEFAULT_STAT_STAGE)
                        break;
                }
                if ((gSpecialStatuses[gEffectBattler].physicalDmg || gSpecialStatuses[gEffectBattler].specialDmg) && i != NUM_BATTLE_STATS)
                {
                    for (i = 0; i < NUM_BATTLE_STATS; i++)
                        gBattleMons[gEffectBattler].statStages[i] = DEFAULT_STAT_STAGE;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectClearSmog;
                }
                break;
            case MOVE_EFFECT_FLAME_BURST:
                if (IsBattlerAlive(BATTLE_PARTNER(gBattlerTarget))
                        && !(gStatuses3[BATTLE_PARTNER(gBattlerTarget)] & STATUS3_SEMI_INVULNERABLE)
                        && GetBattlerAbility(BATTLE_PARTNER(gBattlerTarget)) != ABILITY_MAGIC_GUARD)
                {
                    gBattleScripting.savedBattler = BATTLE_PARTNER(gBattlerTarget);
                    gBattleMoveDamage = gBattleMons[BATTLE_PARTNER(gBattlerTarget)].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattlescriptCurrInstr = BattleScript_MoveEffectFlameBurst;
                }
                break;
            case MOVE_EFFECT_FEINT:
                if (IS_BATTLER_PROTECTED(gBattlerTarget))
                {
                    gProtectStructs[gBattlerTarget].protected = FALSE;
                    gSideStatuses[GetBattlerSide(gBattlerTarget)] &= ~SIDE_STATUS_WIDE_GUARD;
                    gSideStatuses[GetBattlerSide(gBattlerTarget)] &= ~SIDE_STATUS_QUICK_GUARD;
                    gSideStatuses[GetBattlerSide(gBattlerTarget)] &= ~SIDE_STATUS_CRAFTY_SHIELD;
                    gSideStatuses[GetBattlerSide(gBattlerTarget)] &= ~SIDE_STATUS_MAT_BLOCK;
                    gProtectStructs[gBattlerTarget].spikyShielded = FALSE;
                    gProtectStructs[gBattlerTarget].kingsShielded = FALSE;
                    gProtectStructs[gBattlerTarget].banefulBunkered = FALSE;
                    gProtectStructs[gBattlerTarget].obstructed = FALSE;
                    gProtectStructs[gBattlerTarget].silkTrapped = FALSE;
                    gProtectStructs[gBattlerAttacker].burningBulwarked = FALSE;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    if (gCurrentMove == MOVE_HYPERSPACE_FURY)
                        gBattlescriptCurrInstr = BattleScript_HyperspaceFuryRemoveProtect;
                    else
                        gBattlescriptCurrInstr = BattleScript_MoveEffectFeint;
                }
                break;
            case MOVE_EFFECT_SPECTRAL_THIEF:
                if (!NoAliveMonsForEitherParty())
                {
                    bool32 contrary = (GetBattlerAbility(gBattlerAttacker) == ABILITY_CONTRARY);
                    gBattleStruct->stolenStats[0] = 0; // Stats to steal.
                    gBattleScripting.animArg1 = 0;
                    for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                    {
                        if (gBattleMons[gBattlerTarget].statStages[i] > DEFAULT_STAT_STAGE && gBattleMons[gBattlerAttacker].statStages[i] != MAX_STAT_STAGE)
                        {
                            bool32 byTwo = FALSE;

                            gBattleStruct->stolenStats[0] |= gBitTable[i];
                            // Store by how many stages to raise the stat.
                            gBattleStruct->stolenStats[i] = gBattleMons[gBattlerTarget].statStages[i] - DEFAULT_STAT_STAGE;
                            while (gBattleMons[gBattlerAttacker].statStages[i] + gBattleStruct->stolenStats[i] > MAX_STAT_STAGE)
                                gBattleStruct->stolenStats[i]--;
                            gBattleMons[gBattlerTarget].statStages[i] = DEFAULT_STAT_STAGE;

                            if (gBattleStruct->stolenStats[i] >= 2)
                                byTwo++;

                            if (gBattleScripting.animArg1 == 0)
                            {
                                if (byTwo)
                                    gBattleScripting.animArg1 = (contrary ? STAT_ANIM_MINUS2 : STAT_ANIM_PLUS2) + i;
                                else
                                    gBattleScripting.animArg1 = (contrary ? STAT_ANIM_MINUS1 : STAT_ANIM_PLUS1) + i;
                            }
                            else
                            {
                                if (byTwo)
                                    gBattleScripting.animArg1 = (contrary ? STAT_ANIM_MULTIPLE_MINUS2 : STAT_ANIM_MULTIPLE_PLUS2);
                                else
                                    gBattleScripting.animArg1 = (contrary ? STAT_ANIM_MULTIPLE_MINUS1 : STAT_ANIM_MULTIPLE_PLUS1);
                            }
                        }
                    }

                    if (gBattleStruct->stolenStats[0] != 0)
                    {
                        BattleScriptPush(gBattlescriptCurrInstr + 1);
                        gBattlescriptCurrInstr = BattleScript_SpectralThiefSteal;
                    }
                }
                break;
            case MOVE_EFFECT_V_CREATE:
                if (!NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_VCreateStatLoss;
                }
                break;
            case MOVE_EFFECT_CORE_ENFORCER:
                if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget)
                 && !NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectCoreEnforcer;
                }
                break;
            case MOVE_EFFECT_THROAT_CHOP:
                gDisableStructs[gEffectBattler].throatChopTimer = 2;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_INCINERATE:
                if ((gBattleMons[gEffectBattler].item >= FIRST_BERRY_INDEX && gBattleMons[gEffectBattler].item <= LAST_BERRY_INDEX)
                 || (B_INCINERATE_GEMS >= GEN_6 && GetBattlerHoldEffect(gEffectBattler, FALSE) == HOLD_EFFECT_GEMS))
                {
                    gLastUsedItem = gBattleMons[gEffectBattler].item;
                    gBattleMons[gEffectBattler].item = 0;
                    CheckSetUnburden(gEffectBattler);

                    BtlController_EmitSetMonData(gEffectBattler, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].item), &gBattleMons[gEffectBattler].item);
                    MarkBattlerForControllerExec(gEffectBattler);
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectIncinerate;
                }
                break;
            case MOVE_EFFECT_BUG_BITE:
                if (ItemId_GetPocket(gBattleMons[gEffectBattler].item) == POCKET_BERRIES
                    && battlerAbility != ABILITY_STICKY_HOLD)
                {
                    // target loses their berry
                    gLastUsedItem = gBattleMons[gEffectBattler].item;
                    gBattleMons[gEffectBattler].item = 0;
                    CheckSetUnburden(gEffectBattler);

                    BtlController_EmitSetMonData(gEffectBattler, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].item), &gBattleMons[gEffectBattler].item);
                    MarkBattlerForControllerExec(gEffectBattler);
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectBugBite;
                }
                break;
            case MOVE_EFFECT_TRAP_BOTH:
                if (!(gBattleMons[gBattlerTarget].status2 & STATUS2_ESCAPE_PREVENTION) && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_ESCAPE_PREVENTION))
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_BothCanNoLongerEscape;
                }
                if (!(gBattleMons[gBattlerTarget].status2 & STATUS2_ESCAPE_PREVENTION))
                    gDisableStructs[gBattlerTarget].battlerPreventingEscape = gBattlerAttacker;

                if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_ESCAPE_PREVENTION))
                    gDisableStructs[gBattlerAttacker].battlerPreventingEscape = gBattlerTarget;

                gBattleMons[gBattlerTarget].status2 |= STATUS2_ESCAPE_PREVENTION;
                gBattleMons[gBattlerAttacker].status2 |= STATUS2_ESCAPE_PREVENTION;
                break;
            case MOVE_EFFECT_REMOVE_ARG_TYPE:
                // This seems unnecessary but is done to make it work properly with Parental Bond
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                switch (gMovesInfo[gCurrentMove].argument)
                {
                    case TYPE_FIRE: // Burn Up
                        gBattlescriptCurrInstr = BattleScript_RemoveFireType;
                        break;
                    case TYPE_ELECTRIC: // Double Shot
                        gBattlescriptCurrInstr = BattleScript_RemoveElectricType;
                        break;
                    default:
                        gBattlescriptCurrInstr = BattleScript_RemoveGenericType;
                        break;
                }
                RemoveBattlerType(gEffectBattler, gMovesInfo[gCurrentMove].argument);
                break;
            case MOVE_EFFECT_ROUND:
                TryUpdateRoundTurnOrder(); // If another Pokémon uses Round before the user this turn, the user will use Round directly after it
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_DIRE_CLAW:
                if (!gBattleMons[gEffectBattler].status1)
                {
                    static const u8 sDireClawEffects[] = { MOVE_EFFECT_POISON, MOVE_EFFECT_PARALYSIS, MOVE_EFFECT_SLEEP };
                    gBattleScripting.moveEffect = RandomElement(RNG_DIRE_CLAW, sDireClawEffects);
                    SetMoveEffect(primary, certain);
                }
                break;
            case MOVE_EFFECT_STEALTH_ROCK:
                if (!(gSideStatuses[GetBattlerSide(gEffectBattler)] & SIDE_STATUS_STEALTH_ROCK))
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_POINTEDSTONESFLOAT;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StealthRockActivates;
                }
                break;
            case MOVE_EFFECT_SPIKES:
                if (gSideTimers[GetBattlerSide(gEffectBattler)].spikesAmount < 3)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SPIKESSCATTERED;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);

                    if (gBattleStruct->isSkyBattle)
                        gBattlescriptCurrInstr++;
                    else
                        gBattlescriptCurrInstr = BattleScript_SpikesActivates;
                }
                break;
            case MOVE_EFFECT_SYRUP_BOMB:
                if (!(gStatuses4[gEffectBattler] & STATUS4_SYRUP_BOMB))
                {
                    struct Pokemon *party = GetBattlerParty(gBattlerAttacker);

                    gStatuses4[gEffectBattler] |= STATUS4_SYRUP_BOMB;
                    gDisableStructs[gEffectBattler].syrupBombTimer = 3;
                    gDisableStructs[gEffectBattler].syrupBombIsShiny = IsMonShiny(&party[gBattlerPartyIndexes[gBattlerAttacker]]);
                    gBattleStruct->stickySyrupdBy[gEffectBattler] = gBattlerAttacker;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_SyrupBombActivates;
                }
                break;
            case MOVE_EFFECT_SECRET_POWER:
                if (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
                {
                    switch (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
                    {
                    case STATUS_FIELD_MISTY_TERRAIN:
                        gBattleScripting.moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1;
                        break;
                    case STATUS_FIELD_GRASSY_TERRAIN:
                        gBattleScripting.moveEffect = MOVE_EFFECT_SLEEP;
                        break;
                    case STATUS_FIELD_ELECTRIC_TERRAIN:
                        gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                        break;
                    case STATUS_FIELD_PSYCHIC_TERRAIN:
                        gBattleScripting.moveEffect = MOVE_EFFECT_SPD_MINUS_1;
                        break;
                    default:
                        gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                        break;
                    }
                }
                else
                {
                    switch (gBattleTerrain)
                    {
                    case BATTLE_TERRAIN_GRASS:
                        gBattleScripting.moveEffect = (B_SECRET_POWER_EFFECT >= GEN_4 ? MOVE_EFFECT_SLEEP : MOVE_EFFECT_POISON);
                        break;
                    case BATTLE_TERRAIN_UNDERWATER:
                        gBattleScripting.moveEffect = (B_SECRET_POWER_EFFECT >= GEN_6 ? MOVE_EFFECT_ATK_MINUS_1 : MOVE_EFFECT_DEF_MINUS_1);
                        break;
                    case BATTLE_TERRAIN_POND:
                        gBattleScripting.moveEffect = (B_SECRET_POWER_EFFECT >= GEN_4 ? MOVE_EFFECT_ATK_MINUS_1 : MOVE_EFFECT_SPD_MINUS_1);
                        break;
                    case BATTLE_TERRAIN_MOUNTAIN:
                        if (B_SECRET_POWER_EFFECT >= GEN_5)
                            gBattleScripting.moveEffect = MOVE_EFFECT_ACC_MINUS_1;
                        else if (B_SECRET_POWER_EFFECT >= GEN_4)
                            gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                        else
                            gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION;
                        break;
                    case BATTLE_TERRAIN_PUDDLE:
                        gBattleScripting.moveEffect = (B_SECRET_POWER_EFFECT >= GEN_5 ? MOVE_EFFECT_SPD_MINUS_1 : MOVE_EFFECT_ACC_MINUS_1);
                        break;
                    case BATTLE_TERRAIN_LONG_GRASS:
                        gBattleScripting.moveEffect = MOVE_EFFECT_SLEEP;
                        break;
                    case BATTLE_TERRAIN_SAND:
                        gBattleScripting.moveEffect = MOVE_EFFECT_ACC_MINUS_1;
                        break;
                    case BATTLE_TERRAIN_WATER:
                        gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_1;
                        break;
                    case BATTLE_TERRAIN_CAVE:
                    case BATTLE_TERRAIN_BURIAL_GROUND:
                    case BATTLE_TERRAIN_SPACE:
                        gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                        break;
                    case BATTLE_TERRAIN_SOARING:
                    case BATTLE_TERRAIN_SKY_PILLAR:
                    case BATTLE_TERRAIN_MARSH:
                    case BATTLE_TERRAIN_SWAMP:
                        gBattleScripting.moveEffect = MOVE_EFFECT_SPD_MINUS_1;
                        break;
                    case BATTLE_TERRAIN_SNOW:
                    case BATTLE_TERRAIN_ICE:
                        gBattleScripting.moveEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE;
                        break;
                    case BATTLE_TERRAIN_VOLCANO:
                        gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
                        break;
                    case BATTLE_TERRAIN_ULTRA_SPACE:
                        gBattleScripting.moveEffect = MOVE_EFFECT_DEF_MINUS_1;
                        break;
                    default:
                        gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
                        break;
                    }
                }
                SetMoveEffect(primary, certain);
                break;
            case MOVE_EFFECT_PSYCHIC_NOISE:
                battlerAbility = IsAbilityOnSide(gEffectBattler, ABILITY_AROMA_VEIL);

                if (battlerAbility)
                {
                    gBattlerAbility = battlerAbility - 1;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_AromaVeilProtectsRet;
                }
                else if (!(gStatuses3[gEffectBattler] & STATUS3_HEAL_BLOCK))
                {
                    gStatuses3[gEffectBattler] |= STATUS3_HEAL_BLOCK;
                    gDisableStructs[gEffectBattler].healBlockTimer = 2;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_EffectPsychicNoise;
                }
                break;
            case MOVE_EFFECT_TERA_BLAST:
                if (GetActiveGimmick(gEffectBattler) == GIMMICK_TERA
                    && GetBattlerTeraType(gEffectBattler) == TYPE_STELLAR
                    && !NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_LowerAtkSpAtk;
                }
                break;
            }
        }
    }

    gBattleScripting.moveEffect = 0;
}

static bool32 CanApplyAdditionalEffect(const struct AdditionalEffect *additionalEffect)
{
    // Self-targeting move effects only apply after the last mon has been hit
    u16 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);
    if (additionalEffect->self
      && (moveTarget == MOVE_TARGET_BOTH || moveTarget == MOVE_TARGET_FOES_AND_ALLY)
      && GetNextTarget(moveTarget, TRUE) != MAX_BATTLERS_COUNT)
        return FALSE;

    // Certain move effects only apply if the target raised stats this turn (e.g. Burning Jealousy)
    if (additionalEffect->onlyIfTargetRaisedStats && !gProtectStructs[gBattlerTarget].statRaised)
        return FALSE;

    // Certain additional effects only apply on a two-turn move's charge turn
    if (additionalEffect->onChargeTurnOnly != gProtectStructs[gBattlerAttacker].chargingTurn)
        return FALSE;

    return TRUE;
}

static void Cmd_setadditionaleffects(void)
{
    CMD_ARGS();

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        if (gMovesInfo[gCurrentMove].numAdditionalEffects > gBattleStruct->additionalEffectsCounter)
        {
            u32 percentChance;
            const struct AdditionalEffect *additionalEffect = &gMovesInfo[gCurrentMove].additionalEffects[gBattleStruct->additionalEffectsCounter];
            const u8 *currentPtr = gBattlescriptCurrInstr;

            // Various checks for if this move effect can be applied this turn
            if (CanApplyAdditionalEffect(additionalEffect))
            {
                percentChance = CalcSecondaryEffectChance(gBattlerAttacker, GetBattlerAbility(gBattlerAttacker), additionalEffect);

                // Activate effect if it's primary (chance == 0) or if RNGesus says so
                if ((percentChance == 0) || RandomPercentage(RNG_SECONDARY_EFFECT + gBattleStruct->additionalEffectsCounter, percentChance))
                {
                    gBattleScripting.moveEffect = additionalEffect->moveEffect | (MOVE_EFFECT_AFFECTS_USER * (additionalEffect->self));

                    SetMoveEffect(
                        percentChance == 0, // a primary effect
                        percentChance >= 100 // certain to happen
                    );
                }
            }

            // Move script along if we haven't jumped elsewhere
            if (gBattlescriptCurrInstr == currentPtr)
                gBattlescriptCurrInstr = cmd->nextInstr;

            // Call setadditionaleffects again in the case of a move with multiple effects
            gBattleStruct->additionalEffectsCounter++;
            if (gMovesInfo[gCurrentMove].numAdditionalEffects > gBattleStruct->additionalEffectsCounter)
                gBattleScripting.moveEffect = MOVE_EFFECT_CONTINUE;
            else
                gBattleScripting.moveEffect = gBattleStruct->additionalEffectsCounter = 0;
        }
        else
        {
            gBattleScripting.moveEffect = 0;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
    else
    {
        gBattleScripting.moveEffect = 0;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }

    gBattleScripting.multihitMoveEffect = 0;
}

static void Cmd_seteffectprimary(void)
{
    CMD_ARGS();

    SetMoveEffect(TRUE, FALSE);
}

static void Cmd_seteffectsecondary(void)
{
    CMD_ARGS();

    SetMoveEffect(FALSE, FALSE);
}

static void Cmd_clearstatusfromeffect(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);

    if (gBattleScripting.moveEffect <= PRIMARY_STATUS_MOVE_EFFECT)
        gBattleMons[battler].status1 &= (~sStatusFlagsForMoveEffects[gBattleScripting.moveEffect]);
    else
    {
        gBattleMons[battler].status2 &= (~sStatusFlagsForMoveEffects[gBattleScripting.moveEffect]);
        if (gBattleScripting.moveEffect == MOVE_EFFECT_CHARGING)
            gProtectStructs[battler].chargingTurn = FALSE;
    }

    gBattleScripting.moveEffect = 0;
    gBattlescriptCurrInstr = cmd->nextInstr;
    gBattleScripting.multihitMoveEffect = 0;
}

static void Cmd_tryfaintmon(void)
{
    CMD_ARGS(u8 battler, bool8 isSpikes, const u8 *instr);
    u32 battler, destinyBondBattler;
    const u8 *faintScript;

    battler = GetBattlerForBattleScript(cmd->battler);
    if (cmd->isSpikes != 0)
    {
        if (gHitMarker & HITMARKER_FAINTED(battler))
        {
            BattleScriptPop();
            gBattlescriptCurrInstr = cmd->instr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
    else
    {
        if (cmd->battler == BS_ATTACKER)
        {
            destinyBondBattler = gBattlerTarget;
            faintScript = BattleScript_FaintAttacker;
        }
        else
        {
            destinyBondBattler = gBattlerAttacker;
            faintScript = BattleScript_FaintTarget;
        }
        if (!(gAbsentBattlerFlags & gBitTable[battler])
         && !IsBattlerAlive(battler))
        {
            gHitMarker |= HITMARKER_FAINTED(battler);
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = faintScript;
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            {
                gHitMarker |= HITMARKER_PLAYER_FAINTED;
                if (gBattleResults.playerFaintCounter < 255)
                    gBattleResults.playerFaintCounter++;
                AdjustFriendshipOnBattleFaint(battler);
                gSideTimers[B_SIDE_PLAYER].retaliateTimer = 2;
            }
            else
            {
                if (gBattleResults.opponentFaintCounter < 255)
                    gBattleResults.opponentFaintCounter++;
                gBattleResults.lastOpponentSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES, NULL);
                gSideTimers[B_SIDE_OPPONENT].retaliateTimer = 2;
            }
            if ((gHitMarker & HITMARKER_DESTINYBOND) && IsBattlerAlive(gBattlerAttacker)
                 && !(GetActiveGimmick(gBattlerAttacker) == GIMMICK_DYNAMAX))
            {
                gHitMarker &= ~HITMARKER_DESTINYBOND;
                BattleScriptPush(gBattlescriptCurrInstr);
                gBattleMoveDamage = gBattleMons[destinyBondBattler].hp;
                gBattlescriptCurrInstr = BattleScript_DestinyBondTakesLife;
            }
            if ((gStatuses3[gBattlerTarget] & STATUS3_GRUDGE)
             && !(gHitMarker & HITMARKER_GRUDGE)
             && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget)
             && IsBattlerAlive(gBattlerAttacker)
             && gCurrentMove != MOVE_STRUGGLE)
            {
                u8 moveIndex = *(gBattleStruct->chosenMovePositions + gBattlerAttacker);

                gBattleMons[gBattlerAttacker].pp[moveIndex] = 0;
                BattleScriptPush(gBattlescriptCurrInstr);
                gBattlescriptCurrInstr = BattleScript_GrudgeTakesPp;
                BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, moveIndex + REQUEST_PPMOVE1_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].pp[moveIndex]), &gBattleMons[gBattlerAttacker].pp[moveIndex]);
                MarkBattlerForControllerExec(gBattlerAttacker);

                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].moves[moveIndex])
            }
        }
        else
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
}

static void Cmd_dofaintanimation(void)
{
    CMD_ARGS(u8 battler);

    if (gBattleControllerExecFlags == 0)
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        BtlController_EmitFaintAnimation(battler, BUFFER_A);
        MarkBattlerForControllerExec(battler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_cleareffectsonfaint(void)
{
    CMD_ARGS(u8 battler);

    if (gBattleControllerExecFlags == 0)
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        const u8 *clearDataResult = NULL;
        if (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || !IsBattlerAlive(battler))
        {
            gBattleMons[battler].status1 = 0;
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[battler].status1), &gBattleMons[battler].status1);
            MarkBattlerForControllerExec(battler);
        }

        clearDataResult = FaintClearSetData(battler); // Effects like attractions, trapping, etc.
        if (clearDataResult)
            gBattlescriptCurrInstr = clearDataResult;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifstatus(void)
{
    CMD_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    u32 flags = cmd->flags;
    const u8 *jumpInstr = cmd->jumpInstr;

    if (gBattleMons[battler].status1 & flags && IsBattlerAlive(battler))
        gBattlescriptCurrInstr = jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifstatus2(void)
{
    CMD_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    u32 flags = cmd->flags;
    const u8 *jumpInstr = cmd->jumpInstr;

    if (gBattleMons[battler].status2 & flags && IsBattlerAlive(battler))
        gBattlescriptCurrInstr = jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifability(void)
{
    CMD_ARGS(u8 battler, u16 ability, const u8 *jumpInstr);

    u32 battler;
    bool32 hasAbility = FALSE;
    u32 ability = cmd->ability;

    switch (cmd->battler)
    {
    default:
        battler = GetBattlerForBattleScript(cmd->battler);
        if (GetBattlerAbility(battler) == ability)
            hasAbility = TRUE;
        break;
    case BS_ATTACKER_SIDE:
        battler = IsAbilityOnSide(gBattlerAttacker, ability);
        if (battler)
        {
            battler--;
            hasAbility = TRUE;
        }
        break;
    case BS_TARGET_SIDE:
        battler = IsAbilityOnOpposingSide(gBattlerAttacker, ability);
        if (battler)
        {
            battler--;
            hasAbility = TRUE;
        }
        break;
    }

    if (hasAbility)
    {
        gLastUsedAbility = ability;
        gBattlescriptCurrInstr = cmd->jumpInstr;
        RecordAbilityBattle(battler, gLastUsedAbility);
        gBattlerAbility = battler;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifsideaffecting(void)
{
    CMD_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);

    u32 side = GetBattlerSide(GetBattlerForBattleScript(cmd->battler));

    if (gSideStatuses[side] & cmd->flags)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifstat(void)
{
    CMD_ARGS(u8 battler, u8 comparison, u8 stat, u8 value, const u8 *jumpInstr);

    bool32 ret = 0;
    u8 battler = GetBattlerForBattleScript(cmd->battler);
    u8 stat = cmd->stat;
    u8 value = cmd->value;
    u8 comparison = cmd->comparison;

    ret = CompareStat(battler, stat, value, comparison);

    if (ret)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifstatus3condition(void)
{
    CMD_ARGS(u8 battler, u32 flags, bool8 jumpIfTrue, const u8 *jumpInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (cmd->jumpIfTrue)
    {
        if ((gStatuses3[battler] & cmd->flags) != 0)
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
    {
        if ((gStatuses3[battler] & cmd->flags) != 0)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpbasedontype(void)
{
    CMD_ARGS(u8 battler, u8 type, u8 jumpIfType, const u8 *jumpInstr);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    u8 type = cmd->type;
    const u8 *jumpInstr = cmd->jumpInstr;

    // jumpiftype
    if (cmd->jumpIfType)
    {
        if (IS_BATTLER_OF_TYPE(battler, type))
            gBattlescriptCurrInstr = jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
    // jumpifnottype
    else
    {
        if (!IS_BATTLER_OF_TYPE(battler, type))
            gBattlescriptCurrInstr = jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

FEATURE_FLAG_ASSERT(I_EXP_SHARE_FLAG, YouNeedToSetTheExpShareFlagToAnUnusedFlag);

static bool32 BattleTypeAllowsExp(void)
{
    if (RECORDED_WILD_BATTLE)
        return TRUE;
    else if (gBattleTypeFlags &
              ( BATTLE_TYPE_LINK
              | BATTLE_TYPE_RECORDED_LINK
              | BATTLE_TYPE_TRAINER_HILL
              | BATTLE_TYPE_FRONTIER
              | BATTLE_TYPE_SAFARI
              | BATTLE_TYPE_BATTLE_TOWER
              | BATTLE_TYPE_EREADER_TRAINER))
        return FALSE;
    else
        return TRUE;
}

static u32 GetMonHoldEffect(struct Pokemon *mon)
{
    u32 holdEffect;
    u32 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    if (item == ITEM_ENIGMA_BERRY_E_READER)
    #if FREE_ENIGMA_BERRY == FALSE
        holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
    #else
        holdEffect = 0;
    #endif //FREE_ENIGMA_BERRY
    else
        holdEffect = ItemId_GetHoldEffect(item);

    return holdEffect;
}

static void Cmd_getexp(void)
{
    CMD_ARGS(u8 battler);

    u32 holdEffect;
    s32 i; // also used as stringId
    u8 *expMonId = &gBattleStruct->expGetterMonId;

    gBattlerFainted = GetBattlerForBattleScript(cmd->battler);

    switch (gBattleScripting.getexpState)
    {
    case 0: // check if should receive exp at all
        if (GetBattlerSide(gBattlerFainted) != B_SIDE_OPPONENT
            || IsAiVsAiBattle()
            || !BattleTypeAllowsExp())
        {
            gBattleScripting.getexpState = 6; // goto last case
        }
        else
        {
            gBattleScripting.getexpState++;
            gBattleStruct->givenExpMons |= gBitTable[gBattlerPartyIndexes[gBattlerFainted]];
        }
        break;
    case 1: // calculate experience points to redistribute
        {
            u32 orderId = 0;
            u32 calculatedExp = 0;
            u32 *exp = &gBattleStruct->expValue;
            u32 sentInBits = gSentPokesToOpponent[(gBattlerFainted & 2) >> 1];
            u32 expShareBits = 0;
            s32 viaSentIn = 0;
            s32 viaExpShare = 0;

            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (!IsValidForBattle(&gPlayerParty[i]))
                    continue;
                if (gBitTable[i] & sentInBits)
                    viaSentIn++;

                holdEffect = GetMonHoldEffect(&gPlayerParty[i]);
                if (holdEffect == HOLD_EFFECT_EXP_SHARE || IsGen6ExpShareEnabled())
                {
                    expShareBits |= gBitTable[i];
                    viaExpShare++;
                }
            }
            // Get order of mons getting exp: 1. all mons via sent in, 2. all mons via exp share
            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (gBitTable[i] & sentInBits)
                    gBattleStruct->expGettersOrder[orderId++] = i;
            }
            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (!(gBitTable[i] & sentInBits) && gBitTable[i] & expShareBits)
                    gBattleStruct->expGettersOrder[orderId++] = i;
            }
            if (orderId < PARTY_SIZE)
                gBattleStruct->expGettersOrder[orderId] = PARTY_SIZE;

            calculatedExp = gSpeciesInfo[gBattleMons[gBattlerFainted].species].expYield * gBattleMons[gBattlerFainted].level;
            if (B_SCALED_EXP >= GEN_5 && B_SCALED_EXP != GEN_6)
                calculatedExp /= 5;
            else
                calculatedExp /= 7;

            if (B_TRAINER_EXP_MULTIPLIER <= GEN_7 && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                calculatedExp = (calculatedExp * 150) / 100;

            if (B_SPLIT_EXP < GEN_6)
            {
                if (viaExpShare) // at least one mon is getting exp via exp share
                {
                    *exp = SAFE_DIV(calculatedExp / 2, viaSentIn);
                    if (*exp == 0)
                        *exp = 1;

                    gBattleStruct->expShareExpValue = calculatedExp / 2 / viaExpShare;
                    if (gBattleStruct->expShareExpValue == 0)
                        gBattleStruct->expShareExpValue = 1;
                }
                else
                {
                    *exp = SAFE_DIV(calculatedExp, viaSentIn);
                    if (*exp == 0)
                        *exp = 1;
                    gBattleStruct->expShareExpValue = 0;
                }
            }
            else
            {
                *exp = calculatedExp;
                gBattleStruct->expShareExpValue = calculatedExp / 2;
                if (gBattleStruct->expShareExpValue == 0)
                    gBattleStruct->expShareExpValue = 1;
            }

            gBattleScripting.getexpState++;
            gBattleStruct->expOrderId = 0;
            *expMonId = gBattleStruct->expGettersOrder[0];
            gBattleStruct->expSentInMons = sentInBits;
        }
        // fall through
    case 2: // set exp value to the poke in expgetter_id and print message
        if (gBattleControllerExecFlags == 0)
        {
            bool32 wasSentOut = ((gBattleStruct->expSentInMons & gBitTable[*expMonId]) != 0);
            holdEffect = GetMonHoldEffect(&gPlayerParty[*expMonId]);

            if ((holdEffect != HOLD_EFFECT_EXP_SHARE && !wasSentOut && !IsGen6ExpShareEnabled())
             || GetMonData(&gPlayerParty[*expMonId], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
            {
                gBattleScripting.getexpState = 5;
                gBattleMoveDamage = 0; // used for exp
            }
            else if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && *expMonId >= 3)
                  || GetMonData(&gPlayerParty[*expMonId], MON_DATA_LEVEL) == MAX_LEVEL)
            {
                gBattleScripting.getexpState = 5;
                gBattleMoveDamage = 0; // used for exp
                if (B_MAX_LEVEL_EV_GAINS >= GEN_5)
                    MonGainEVs(&gPlayerParty[*expMonId], gBattleMons[gBattlerFainted].species);
            }
            else
            {
                // Music change in a wild battle after fainting opposing pokemon.
                if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    && (gBattleMons[0].hp || (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && gBattleMons[2].hp))
                    && !IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT))
                    && !IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))
                    && !gBattleStruct->wildVictorySong)
                {
                    BattleStopLowHpSound();
                    PlayBGM(MUS_VICTORY_WILD);
                    gBattleStruct->wildVictorySong++;
                }

                if (IsValidForBattle(&gPlayerParty[*expMonId]))
                {
                    if (wasSentOut)
                        gBattleMoveDamage = GetSoftLevelCapExpValue(gPlayerParty[*expMonId].level, gBattleStruct->expValue);
                    else
                        gBattleMoveDamage = 0;

                    if ((holdEffect == HOLD_EFFECT_EXP_SHARE || IsGen6ExpShareEnabled())
                        && (B_SPLIT_EXP < GEN_6 || gBattleMoveDamage == 0)) // only give exp share bonus in later gens if the mon wasn't sent out
                    {
                        gBattleMoveDamage += GetSoftLevelCapExpValue(gPlayerParty[*expMonId].level, gBattleStruct->expShareExpValue);;
                    }

                    ApplyExperienceMultipliers(&gBattleMoveDamage, *expMonId, gBattlerFainted);

                    if (B_EXP_CAP_TYPE == EXP_CAP_HARD && gBattleMoveDamage != 0)
                    {
                        u32 growthRate = gSpeciesInfo[GetMonData(&gPlayerParty[*expMonId], MON_DATA_SPECIES)].growthRate;
                        u32 currentExp = GetMonData(&gPlayerParty[*expMonId], MON_DATA_EXP);
                        u32 levelCap = GetCurrentLevelCap();

                        if (GetMonData(&gPlayerParty[*expMonId], MON_DATA_LEVEL) >= levelCap)
                            gBattleMoveDamage = 0;
                        else if (gExperienceTables[growthRate][levelCap] < currentExp + gBattleMoveDamage)
                            gBattleMoveDamage = gExperienceTables[growthRate][levelCap] - currentExp;
                    }

                    if (IsTradedMon(&gPlayerParty[*expMonId]))
                    {
                        // check if the Pokémon doesn't belong to the player
                        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && *expMonId >= 3)
                            i = STRINGID_EMPTYSTRING4;
                        else
                            i = STRINGID_ABOOSTED;
                    }
                    else
                    {
                        i = STRINGID_EMPTYSTRING4;
                    }

                    // get exp getter battler
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                    {
                        if (gBattlerPartyIndexes[2] == *expMonId && !(gAbsentBattlerFlags & gBitTable[2]))
                            gBattleStruct->expGetterBattlerId = 2;
                        else
                        {
                            if (!(gAbsentBattlerFlags & gBitTable[0]))
                                gBattleStruct->expGetterBattlerId = 0;
                            else
                                gBattleStruct->expGetterBattlerId = 2;
                        }
                    }
                    else
                    {
                        gBattleStruct->expGetterBattlerId = 0;
                    }

                    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gBattleStruct->expGetterBattlerId, *expMonId);
                    // buffer 'gained' or 'gained a boosted'
                    PREPARE_STRING_BUFFER(gBattleTextBuff2, i);
                    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff3, 6, gBattleMoveDamage);

                    if (wasSentOut || holdEffect == HOLD_EFFECT_EXP_SHARE)
                    {
                        PrepareStringBattle(STRINGID_PKMNGAINEDEXP, gBattleStruct->expGetterBattlerId);
                    }
                    else if (IsGen6ExpShareEnabled() && !gBattleStruct->teamGotExpMsgPrinted) // Print 'the rest of your team got exp' message once, when all of the sent-in mons were given experience
                    {
                        gLastUsedItem = ITEM_EXP_SHARE;
                        PrepareStringBattle(STRINGID_TEAMGAINEDEXP, gBattleStruct->expGetterBattlerId);
                        gBattleStruct->teamGotExpMsgPrinted = TRUE;
                    }

                    MonGainEVs(&gPlayerParty[*expMonId], gBattleMons[gBattlerFainted].species);
                }
                gBattleScripting.getexpState++;
            }
        }
        break;
    case 3: // Set stats and give exp
        if (gBattleControllerExecFlags == 0)
        {
            gBattleResources->bufferB[gBattleStruct->expGetterBattlerId][0] = 0;
            if (GetMonData(&gPlayerParty[*expMonId], MON_DATA_HP) && GetMonData(&gPlayerParty[*expMonId], MON_DATA_LEVEL) != MAX_LEVEL)
            {
                gBattleResources->beforeLvlUp->stats[STAT_HP]    = GetMonData(&gPlayerParty[*expMonId], MON_DATA_MAX_HP);
                gBattleResources->beforeLvlUp->stats[STAT_ATK]   = GetMonData(&gPlayerParty[*expMonId], MON_DATA_ATK);
                gBattleResources->beforeLvlUp->stats[STAT_DEF]   = GetMonData(&gPlayerParty[*expMonId], MON_DATA_DEF);
                gBattleResources->beforeLvlUp->stats[STAT_SPEED] = GetMonData(&gPlayerParty[*expMonId], MON_DATA_SPEED);
                gBattleResources->beforeLvlUp->stats[STAT_SPATK] = GetMonData(&gPlayerParty[*expMonId], MON_DATA_SPATK);
                gBattleResources->beforeLvlUp->stats[STAT_SPDEF] = GetMonData(&gPlayerParty[*expMonId], MON_DATA_SPDEF);

                BtlController_EmitExpUpdate(gBattleStruct->expGetterBattlerId, BUFFER_A, *expMonId, gBattleMoveDamage);
                MarkBattlerForControllerExec(gBattleStruct->expGetterBattlerId);
            }
            gBattleScripting.getexpState++;
        }
        break;
    case 4: // lvl up if necessary
        if (gBattleControllerExecFlags == 0)
        {
            u32 expBattler = gBattleStruct->expGetterBattlerId;
            if (gBattleResources->bufferB[expBattler][0] == CONTROLLER_TWORETURNVALUES && gBattleResources->bufferB[expBattler][1] == RET_VALUE_LEVELED_UP)
            {
                u16 temp, battler = 0xFF;
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && gBattlerPartyIndexes[expBattler] == *expMonId)
                    HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[expBattler]], expBattler);

                PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, expBattler, *expMonId);
                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 3, GetMonData(&gPlayerParty[*expMonId], MON_DATA_LEVEL));

                BattleScriptPushCursor();
                gLeveledUpInBattle |= gBitTable[*expMonId];
                gBattlescriptCurrInstr = BattleScript_LevelUp;
                gBattleMoveDamage = T1_READ_32(&gBattleResources->bufferB[expBattler][2]);
                AdjustFriendship(&gPlayerParty[*expMonId], FRIENDSHIP_EVENT_GROW_LEVEL);

                // update battle mon structure after level up
                if (gBattlerPartyIndexes[0] == *expMonId && gBattleMons[0].hp)
                    battler = 0;
                else if (gBattlerPartyIndexes[2] == *expMonId && gBattleMons[2].hp && (gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                    battler = 2;

                if (battler != 0xFF)
                {
                    CopyMonLevelAndBaseStatsToBattleMon(battler, &gPlayerParty[*expMonId]);
                    if (gStatuses3[battler] & STATUS3_POWER_TRICK)
                        SWAP(gBattleMons[battler].attack, gBattleMons[battler].defense, temp);
                }

                gBattleScripting.getexpState = 5;
            }
            else
            {
                gBattleMoveDamage = 0;
                gBattleScripting.getexpState = 5;
            }
        }
        break;
    case 5: // looper increment
        if (gBattleMoveDamage) // there is exp to give, goto case 3 that gives exp
        {
            gBattleScripting.getexpState = 3;
        }
        else
        {
            if ((++gBattleStruct->expOrderId) < PARTY_SIZE)
            {
                *expMonId = gBattleStruct->expGettersOrder[gBattleStruct->expOrderId];
                if (*expMonId < PARTY_SIZE)
                {
                    gBattleScripting.getexpState = 2; // loop again
                    break;
                }
            }
            gBattleScripting.getexpState = 6; // we're done
        }
        break;
    case 6: // increment instruction
        if (gBattleControllerExecFlags == 0)
        {
            // not sure why gf clears the item and ability here
            gBattleStruct->expOrderId = 0;
            gBattleStruct->teamGotExpMsgPrinted = FALSE;
            gBattleMons[gBattlerFainted].item = ITEM_NONE;
            gBattleMons[gBattlerFainted].ability = ABILITY_NONE;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        break;
    }
}

bool32 NoAliveMonsForPlayer(void)
{
    u32 i;
    u32 maxI = PARTY_SIZE;
    u32 HP_count = 0;

    if (B_MULTI_BATTLE_WHITEOUT < GEN_4 && gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
        maxI = MULTI_PARTY_SIZE;

    // Get total HP for the player's party to determine if the player has lost
    for (i = 0; i < maxI; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG)
            && (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || !(gBattleStruct->arenaLostPlayerMons & gBitTable[i])))
        {
            HP_count += GetMonData(&gPlayerParty[i], MON_DATA_HP);
        }
    }

    return (HP_count == 0);
}

static bool32 NoAliveMonsForOpponent(void)
{
    u32 i;
    u32 HP_count = 0;

    // Get total HP for the enemy's party to determine if the player has won
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES) && !GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG)
         && (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || !(gBattleStruct->arenaLostOpponentMons & gBitTable[i])))
        {
            HP_count += GetMonData(&gEnemyParty[i], MON_DATA_HP);
        }
    }

    return (HP_count == 0);
}

bool32 NoAliveMonsForEitherParty(void)
{
    return (NoAliveMonsForPlayer() || NoAliveMonsForOpponent());
}

// For battles that aren't BATTLE_TYPE_LINK or BATTLE_TYPE_RECORDED_LINK or trainer battles, the only thing this
// command does is check whether the player has won/lost by totaling each team's HP. It then
// sets gBattleOutcome accordingly, if necessary.
static void Cmd_checkteamslost(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (gBattleControllerExecFlags)
        return;

    if (NoAliveMonsForPlayer())
        gBattleOutcome |= B_OUTCOME_LOST;

    if (NoAliveMonsForOpponent())
        gBattleOutcome |= B_OUTCOME_WON;

    // Fair switching - everyone has to switch in most at the same time, without knowing which pokemon the other trainer selected.
    // In vanilla Emerald this was only used for link battles, in expansion it's also used for regular trainer battles.
    // For battles that haven't ended, count number of empty battler spots
    // In multi battles, jump to pointer if more than 1 spot empty
    // In non-multi battles, jump to pointer if 1 spot is missing on both sides
    if (gBattleOutcome == 0 && (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK | BATTLE_TYPE_TRAINER)))
    {
        s32 i, emptyPlayerSpots, emptyOpponentSpots;

        for (emptyPlayerSpots = 0, i = 0; i < gBattlersCount; i += 2)
        {
            if ((gHitMarker & HITMARKER_FAINTED2(i)) && (!gSpecialStatuses[i].faintedHasReplacement))
                emptyPlayerSpots++;
        }

        emptyOpponentSpots = 0;
        for (i = 1; i < gBattlersCount; i += 2)
        {
            if ((gHitMarker & HITMARKER_FAINTED2(i)) && (!gSpecialStatuses[i].faintedHasReplacement))
                emptyOpponentSpots++;
        }

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (emptyOpponentSpots + emptyPlayerSpots > 1)
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            if (emptyOpponentSpots != 0 && emptyPlayerSpots != 0)
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void MoveValuesCleanUp(void)
{
    gMoveResultFlags = 0;
    gIsCriticalHit = FALSE;
    gBattleScripting.moveEffect = 0;
    gBattleCommunication[MISS_TYPE] = 0;
    if (!gMultiHitCounter)
        gHitMarker &= ~HITMARKER_DESTINYBOND;
    gHitMarker &= ~HITMARKER_SYNCHRONISE_EFFECT;
}

static void Cmd_movevaluescleanup(void)
{
    CMD_ARGS();

    MoveValuesCleanUp();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setmultihit(void)
{
    CMD_ARGS(u8 value);

    gMultiHitCounter = cmd->value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_decrementmultihit(void)
{
    CMD_ARGS(const u8 *loopInstr);

    if (--gMultiHitCounter == 0)
        gBattlescriptCurrInstr = cmd->nextInstr;
    else
        gBattlescriptCurrInstr = cmd->loopInstr;
}

static void Cmd_goto(void)
{
    CMD_ARGS(const u8 *instr);

    gBattlescriptCurrInstr = cmd->instr;
}

static void Cmd_jumpifbyte(void)
{
    CMD_ARGS(u8 comparison, const u8 *bytePtr, u8 value, const u8 *jumpInstr);

    u8 comparison = cmd->comparison;
    const u8 *bytePtr = cmd->bytePtr;
    u8 value = cmd->value;
    const u8 *jumpInstr = cmd->jumpInstr;

    gBattlescriptCurrInstr = cmd->nextInstr;

    switch (comparison)
    {
    case CMP_EQUAL:
        if (*bytePtr == value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_NOT_EQUAL:
        if (*bytePtr != value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_GREATER_THAN:
        if (*bytePtr > value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_LESS_THAN:
        if (*bytePtr < value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_COMMON_BITS:
        if (*bytePtr & value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(*bytePtr & value))
            gBattlescriptCurrInstr = jumpInstr;
        break;
    }
}

static void Cmd_jumpifhalfword(void)
{
    CMD_ARGS(u8 comparison, const u16 *halfwordPtr, u16 value, const u8 *jumpInstr);

    u8 comparison = cmd->comparison;
    const u16 *halfwordPtr = cmd->halfwordPtr;
    u16 value = cmd->value;
    const u8 *jumpInstr = cmd->jumpInstr;

    gBattlescriptCurrInstr = cmd->nextInstr;

    switch (comparison)
    {
    case CMP_EQUAL:
        if (*halfwordPtr == value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_NOT_EQUAL:
        if (*halfwordPtr != value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_GREATER_THAN:
        if (*halfwordPtr > value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_LESS_THAN:
        if (*halfwordPtr < value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_COMMON_BITS:
        if (*halfwordPtr & value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(*halfwordPtr & value))
            gBattlescriptCurrInstr = jumpInstr;
        break;
    }
}

static void Cmd_jumpifword(void)
{
    CMD_ARGS(u8 comparison, const u32 *wordPtr, u32 value, const u8 *jumpInstr);

    u8 comparison = cmd->comparison;
    const u32 *wordPtr = cmd->wordPtr;
    u32 value = cmd->value;
    const u8 *jumpInstr = cmd->jumpInstr;

    gBattlescriptCurrInstr = cmd->nextInstr;

    switch (comparison)
    {
    case CMP_EQUAL:
        if (*wordPtr == value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_NOT_EQUAL:
        if (*wordPtr != value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_GREATER_THAN:
        if (*wordPtr > value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_LESS_THAN:
        if (*wordPtr < value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_COMMON_BITS:
        if (*wordPtr & value)
            gBattlescriptCurrInstr = jumpInstr;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(*wordPtr & value))
            gBattlescriptCurrInstr = jumpInstr;
        break;
    }
}

static void Cmd_jumpifarrayequal(void)
{
    CMD_ARGS(const u8 *array1, const u8 *array2, u8 size, const u8 *jumpInstr);

    const u8 *array1 = cmd->array1;
    const u8 *array2 = cmd->array2;
    u32 size = cmd->size;
    const u8 *jumpInstr = cmd->jumpInstr;

    u8 i;
    for (i = 0; i < size; i++)
    {
        if (*array1 != *array2)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
            break;
        }
        array1++, array2++;
    }

    if (i == size)
        gBattlescriptCurrInstr = jumpInstr;
}

static void Cmd_jumpifarraynotequal(void)
{
    CMD_ARGS(const u8 *array1, const u8 *array2, u8 size, const u8 *jumpInstr);

    u8 equalBytes = 0;
    const u8 *array1 = cmd->array1;
    const u8 *array2 = cmd->array2;
    u32 size = cmd->size;
    const u8 *jumpInstr = cmd->jumpInstr;

    u8 i;
    for (i = 0; i < size; i++)
    {
        if (*array1 == *array2)
            equalBytes++;
        array1++, array2++;
    }

    if (equalBytes != size)
        gBattlescriptCurrInstr = jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setbyte(void)
{
    CMD_ARGS(u8 *bytePtr, u8 value);

    u8 *bytePtr = cmd->bytePtr;
    *bytePtr = cmd->value;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_addbyte(void)
{
    CMD_ARGS(u8 *bytePtr, u8 value);

    u8 *bytePtr = cmd->bytePtr;
    *bytePtr += cmd->value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_subbyte(void)
{
    CMD_ARGS(u8 *bytePtr, u8 value);

    u8 *bytePtr = cmd->bytePtr;
    *bytePtr -= cmd->value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_copyarray(void)
{
    CMD_ARGS(u8 *dest, const u8 *src, u8 size);

    u8 *dest = cmd->dest;
    const u8 *src = cmd->src;
    s32 size = cmd->size;

    s32 i;
    for (i = 0; i < size; i++)
        dest[i] = src[i];

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_copyarraywithindex(void)
{
    CMD_ARGS(u8 *dest, const u8 *src, const u8 *indexPtr, u8 size);

    u8 *dest = cmd->dest;
    const u8 *src = cmd->src;
    const u8 *indexPtr = cmd->indexPtr;
    s32 size = cmd->size;

    s32 i;
    for (i = 0; i < size; i++)
        dest[i] = src[i + *indexPtr];

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_orbyte(void)
{
    CMD_ARGS(u8 *bytePtr, u8 value);

    u8 *bytePtr = cmd->bytePtr;
    *bytePtr |= cmd->value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_orhalfword(void)
{
    CMD_ARGS(u16 *halfwordPtr, u16 value);

    u16 *halfwordPtr = cmd->halfwordPtr;
    u16 value = cmd->value;

    *halfwordPtr |= value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_orword(void)
{
    CMD_ARGS(u32 *wordPtr, u32 value);

    u32 *wordPtr = cmd->wordPtr;
    u32 value = cmd->value;

    *wordPtr |= value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_bicbyte(void)
{
    CMD_ARGS(u8 *bytePtr, u8 value);

    u8 *bytePtr = cmd->bytePtr;
    *bytePtr &= ~cmd->value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_bichalfword(void)
{
    CMD_ARGS(u16 *halfwordPtr, u16 value);

    u16 *halfwordPtr = cmd->halfwordPtr;
    u16 value = cmd->value;

    *halfwordPtr &= ~value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_bicword(void)
{
    CMD_ARGS(u32 *wordPtr, u32 value);

    u32 *wordPtr = cmd->wordPtr;
    u32 value = cmd->value;

    *wordPtr &= ~value;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_pause(void)
{
    CMD_ARGS(u16 frames);

    if (gBattleControllerExecFlags == 0)
    {
        u16 value = cmd->frames;
        if (++gPauseCounterBattle >= value)
        {
            gPauseCounterBattle = 0;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
}

static void Cmd_waitstate(void)
{
    CMD_ARGS();

    if (gBattleControllerExecFlags == 0)
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_healthbar_update(void)
{
    CMD_ARGS(u8 battler);
    u32 battler;

    if (cmd->battler == BS_TARGET)
        battler = gBattlerTarget;
    else
        battler = gBattlerAttacker;

    BtlController_EmitHealthBarUpdate(battler, BUFFER_A, gBattleMoveDamage);
    MarkBattlerForControllerExec(battler);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_return(void)
{
    BattleScriptPop();
}

static void Cmd_end(void)
{
    CMD_ARGS();

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        BattleArena_AddSkillPoints(gBattlerAttacker);

    gMoveResultFlags = 0;
    gCurrentActionFuncId = B_ACTION_TRY_FINISH;
}

static void Cmd_end2(void)
{
    CMD_ARGS();

    gCurrentActionFuncId = B_ACTION_TRY_FINISH;
}

// Pops the main function stack
static void Cmd_end3(void)
{
    CMD_ARGS();

    BattleScriptPop();
    if (gBattleResources->battleCallbackStack->size != 0)
        gBattleResources->battleCallbackStack->size--;
    gBattleMainFunc = gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size];
}

static void Cmd_call(void)
{
    CMD_ARGS(const u8 *instr);

    BattleScriptPush(cmd->nextInstr);
    gBattlescriptCurrInstr = cmd->instr;
}

static void Cmd_setroost(void)
{
    CMD_ARGS();

    gBattleResources->flags->flags[gBattlerAttacker] |= RESOURCE_FLAG_ROOST;
    gBattleStruct->roostTypes[gBattlerAttacker][0] = gBattleMons[gBattlerAttacker].types[0];
    gBattleStruct->roostTypes[gBattlerAttacker][1] = gBattleMons[gBattlerAttacker].types[1];

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifabilitypresent(void)
{
    CMD_ARGS(u16 ability, const u8 *jumpInstr);

    u16 ability = cmd->ability;
    u32 abilityBattler = IsAbilityOnField(ability);
    if (abilityBattler)
    {
        gBattlerAbility = abilityBattler - 1;
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_endselectionscript(void)
{
    CMD_ARGS();

    *(gBattlerAttacker + gBattleStruct->selectionScriptFinished) = TRUE;
}

static void PlayAnimation(u32 battler, u8 animId, const u16 *argPtr, const u8 *nextInstr)
{
    if (B_TERRAIN_BG_CHANGE == FALSE && animId == B_ANIM_RESTORE_BG)
    {
        // workaround for .if not working
        gBattlescriptCurrInstr = nextInstr;
        return;
    }

    if (animId == B_ANIM_STATS_CHANGE
     || animId == B_ANIM_SNATCH_MOVE
     || animId == B_ANIM_MEGA_EVOLUTION
     || animId == B_ANIM_ILLUSION_OFF
     || animId == B_ANIM_FORM_CHANGE
     || animId == B_ANIM_SUBSTITUTE_FADE
     || animId == B_ANIM_PRIMAL_REVERSION
     || animId == B_ANIM_ULTRA_BURST
     || animId == B_ANIM_TERA_CHARGE
     || animId == B_ANIM_TERA_ACTIVATE)
    {
        BtlController_EmitBattleAnimation(battler, BUFFER_A, animId, &gDisableStructs[battler], *argPtr);
        MarkBattlerForControllerExec(battler);
        gBattlescriptCurrInstr = nextInstr;
    }
    else if (gHitMarker & (HITMARKER_NO_ANIMATIONS | HITMARKER_DISABLE_ANIMATION) && animId != B_ANIM_RESTORE_BG)
    {
        BattleScriptPush(nextInstr);
        gBattlescriptCurrInstr = BattleScript_Pausex20;
    }
    else if (animId == B_ANIM_RAIN_CONTINUES
          || animId == B_ANIM_SUN_CONTINUES
          || animId == B_ANIM_SANDSTORM_CONTINUES
          || animId == B_ANIM_HAIL_CONTINUES
          || animId == B_ANIM_SNOW_CONTINUES
          || animId == B_ANIM_FOG_CONTINUES)
    {
        BtlController_EmitBattleAnimation(battler, BUFFER_A, animId, &gDisableStructs[battler], *argPtr);
        MarkBattlerForControllerExec(battler);
        gBattlescriptCurrInstr = nextInstr;
    }
    else if (gStatuses3[battler] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr = nextInstr;
    }
    else
    {
        BtlController_EmitBattleAnimation(battler, BUFFER_A, animId, &gDisableStructs[battler], *argPtr);
        MarkBattlerForControllerExec(battler);
        gBattlescriptCurrInstr = nextInstr;
    }
}

static void Cmd_playanimation(void)
{
    CMD_ARGS(u8 battler, u8 animId, const u16 *argPtr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    PlayAnimation(battler, cmd->animId, cmd->argPtr, cmd->nextInstr);
}

// Same as playanimation, except it takes a pointer to some animation id, instead of taking the value directly
static void Cmd_playanimation_var(void)
{
    CMD_ARGS(u8 battler, const u8 *animIdPtr, const u16 *argPtr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    PlayAnimation(battler, *(cmd->animIdPtr), cmd->argPtr, cmd->nextInstr);
}

static void Cmd_setgraphicalstatchangevalues(void)
{
    CMD_ARGS();

    u8 value = GET_STAT_BUFF_VALUE_WITH_SIGN(gBattleScripting.statChanger);

    switch (value)
    {
    case SET_STAT_BUFF_VALUE(1): // +1
        value = STAT_ANIM_PLUS1 + 1;
        break;
    case SET_STAT_BUFF_VALUE(2): // +2
        value = STAT_ANIM_PLUS2 + 1;
        break;
    case SET_STAT_BUFF_VALUE(3): // +3
        value = STAT_ANIM_PLUS2 + 1;
        break;
    case SET_STAT_BUFF_VALUE(1) | STAT_BUFF_NEGATIVE: // -1
        value = STAT_ANIM_MINUS1 + 1;
        break;
    case SET_STAT_BUFF_VALUE(2) | STAT_BUFF_NEGATIVE: // -2
        value = STAT_ANIM_MINUS2 + 1;
        break;
    case SET_STAT_BUFF_VALUE(3) | STAT_BUFF_NEGATIVE: // -3
        value = STAT_ANIM_MINUS2 + 1;
        break;
    default: // <-12,-4> and <4, 12>
        if (value & STAT_BUFF_NEGATIVE)
            value = STAT_ANIM_MINUS2 + 1;
        else
            value = STAT_ANIM_PLUS2 + 1;
        break;
    }
    gBattleScripting.animArg1 = GET_STAT_BUFF_ID(gBattleScripting.statChanger) + value - 1;
    gBattleScripting.animArg2 = 0;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_playstatchangeanimation(void)
{
    CMD_ARGS(u8 battler, u8 stats, u8 flags);

    u32 currStat = 0;
    u32 statAnimId = 0;
    u32 changeableStatsCount = 0;
    u32 startingStatAnimId = 0;
    u32 flags = cmd->flags;
    u32 battler = GetBattlerForBattleScript(cmd->battler);
    u32 ability = GetBattlerAbility(battler);
    u32 stats = cmd->stats;

    // Handle Contrary and Simple
    if (ability == ABILITY_CONTRARY)
    {
        flags ^= STAT_CHANGE_NEGATIVE;
        RecordAbilityBattle(battler, ability);
    }
    else if (ability == ABILITY_SIMPLE)
    {
        flags |= STAT_CHANGE_BY_TWO;
        RecordAbilityBattle(battler, ability);
    }

    if (flags & STAT_CHANGE_NEGATIVE) // goes down
    {
        if (flags & STAT_CHANGE_BY_TWO)
            startingStatAnimId = STAT_ANIM_MINUS2;
        else
            startingStatAnimId = STAT_ANIM_MINUS1;

        while (stats != 0)
        {
            if (stats & 1)
            {
                if (flags & STAT_CHANGE_CANT_PREVENT)
                {
                    if (gBattleMons[battler].statStages[currStat] > MIN_STAT_STAGE)
                    {
                        statAnimId = startingStatAnimId + currStat;
                        changeableStatsCount++;
                    }
                }
                else if (!gSideTimers[GetBattlerSide(battler)].mistTimer
                        && GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_CLEAR_AMULET
                        && ability != ABILITY_CLEAR_BODY
                        && ability != ABILITY_FULL_METAL_BODY
                        && ability != ABILITY_WHITE_SMOKE
                        && !((ability == ABILITY_KEEN_EYE || ability == ABILITY_MINDS_EYE) && currStat == STAT_ACC)
                        && !(B_ILLUMINATE_EFFECT >= GEN_9 && ability == ABILITY_ILLUMINATE && currStat == STAT_ACC)
                        && !(ability == ABILITY_HYPER_CUTTER && currStat == STAT_ATK)
                        && !(ability == ABILITY_BIG_PECKS && currStat == STAT_DEF))
                {
                    if (gBattleMons[battler].statStages[currStat] > MIN_STAT_STAGE)
                    {
                        statAnimId = startingStatAnimId + currStat;
                        changeableStatsCount++;
                    }
                }
            }
            stats >>= 1, currStat++;
        }

        if (changeableStatsCount > 1) // more than one stat, so the color is gray
        {
            if (flags & STAT_CHANGE_BY_TWO)
                statAnimId = STAT_ANIM_MULTIPLE_MINUS2;
            else
                statAnimId = STAT_ANIM_MULTIPLE_MINUS1;
        }
    }
    else // goes up
    {
        if (flags & STAT_CHANGE_BY_TWO)
            startingStatAnimId = STAT_ANIM_PLUS2;
        else
            startingStatAnimId = STAT_ANIM_PLUS1;

        while (stats != 0)
        {
            if (stats & 1 && gBattleMons[battler].statStages[currStat] < MAX_STAT_STAGE)
            {
                statAnimId = startingStatAnimId + currStat;
                changeableStatsCount++;
            }
            stats >>= 1, currStat++;
        }

        if (changeableStatsCount > 1) // more than one stat, so the color is gray
        {
            if (flags & STAT_CHANGE_BY_TWO)
                statAnimId = STAT_ANIM_MULTIPLE_PLUS2;
            else
                statAnimId = STAT_ANIM_MULTIPLE_PLUS1;
        }
    }

    if (flags & STAT_CHANGE_MULTIPLE_STATS && changeableStatsCount < 2)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (changeableStatsCount != 0 && !gBattleScripting.statAnimPlayed)
    {
        BtlController_EmitBattleAnimation(battler, BUFFER_A, B_ANIM_STATS_CHANGE, &gDisableStructs[battler], statAnimId);
        MarkBattlerForControllerExec(battler);
        if (flags & STAT_CHANGE_MULTIPLE_STATS && changeableStatsCount > 1)
            gBattleScripting.statAnimPlayed = TRUE;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static bool32 TryKnockOffBattleScript(u32 battlerDef)
{
    if (gBattleMons[battlerDef].item != 0
        && CanBattlerGetOrLoseItem(battlerDef, gBattleMons[battlerDef].item)
        && !NoAliveMonsForEitherParty())
    {
        if (GetBattlerAbility(battlerDef) == ABILITY_STICKY_HOLD && IsBattlerAlive(battlerDef))
        {
            gBattlerAbility = battlerDef;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_StickyHoldActivates;
        }
        else
        {
            u32 side = GetBattlerSide(battlerDef);

            gLastUsedItem = gBattleMons[battlerDef].item;
            gBattleMons[battlerDef].item = 0;
            if (gBattleMons[battlerDef].ability != ABILITY_GORILLA_TACTICS)
                gBattleStruct->choicedMove[battlerDef] = 0;
            CheckSetUnburden(battlerDef);

            // In Gen 5+, Knock Off removes the target's item rather than rendering it unusable.
            if (B_KNOCK_OFF_REMOVAL >= GEN_5)
            {
                BtlController_EmitSetMonData(battlerDef, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battlerDef].item), &gBattleMons[battlerDef].item);
                MarkBattlerForControllerExec(battlerDef);
            }
            else
            {
                gWishFutureKnock.knockedOffMons[side] |= gBitTable[gBattlerPartyIndexes[battlerDef]];
            }

            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_KnockedOff;
        }
        return TRUE;
    }
    return FALSE;
}

#define SYMBIOSIS_CHECK(battler, ally)                             \
    GetBattlerAbility(ally) == ABILITY_SYMBIOSIS                   \
    && gBattleMons[battler].item == ITEM_NONE                      \
    && gBattleMons[ally].item != ITEM_NONE                         \
    && CanBattlerGetOrLoseItem(battler, gBattleMons[ally].item)    \
    && CanBattlerGetOrLoseItem(ally, gBattleMons[ally].item)       \
    && IsBattlerAlive(battler)                                     \
    && IsBattlerAlive(ally)

static u32 GetNextTarget(u32 moveTarget, bool32 excludeCurrent)
{
    u32 i;
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (i != gBattlerAttacker
            && !(excludeCurrent && i == gBattlerTarget)
            && IsBattlerAlive(i)
            && !(gBattleStruct->targetsDone[gBattlerAttacker] & gBitTable[i])
            && (GetBattlerSide(i) != GetBattlerSide(gBattlerAttacker) || moveTarget == MOVE_TARGET_FOES_AND_ALLY))
                break;
    }
    return i;
}

static void Cmd_moveend(void)
{
    CMD_ARGS(u8 endMode, u8 endState);

    s32 i;
    bool32 effect = FALSE;
    u32 moveType = 0;
    u32 holdEffectAtk = 0;
    u32 endMode, endState;
    u32 originallyUsedMove;

    if (gChosenMove == MOVE_UNAVAILABLE)
        originallyUsedMove = MOVE_NONE;
    else
        originallyUsedMove = gChosenMove;

    endMode = cmd->endMode;
    endState = cmd->endState;

    holdEffectAtk = GetBattlerHoldEffect(gBattlerAttacker, TRUE);
    GET_MOVE_TYPE(gCurrentMove, moveType);

    do
    {
        switch (gBattleScripting.moveendState)
        {
        case MOVEEND_SUM_DAMAGE: // Sum and store damage dealt for multi strike recoil
            gBattleScripting.savedDmg += gHpDealt;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_PROTECT_LIKE_EFFECT:
            if (gProtectStructs[gBattlerAttacker].touchedProtectLike)
            {
                if (gProtectStructs[gBattlerTarget].spikyShielded
                 && gMovesInfo[gCurrentMove].effect != EFFECT_COUNTER
                 && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
                    gProtectStructs[gBattlerAttacker].touchedProtectLike = FALSE;
                    gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_SPIKY_SHIELD);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_SpikyShieldEffect;
                    effect = 1;
                }
                else if (gProtectStructs[gBattlerTarget].kingsShielded)
                {
                    gProtectStructs[gBattlerAttacker].touchedProtectLike = FALSE;
                    i = gBattlerAttacker;
                    gBattlerAttacker = gBattlerTarget;
                    gBattlerTarget = i; // gBattlerTarget and gBattlerAttacker are swapped in order to activate Defiant, if applicable
                    if (B_KINGS_SHIELD_LOWER_ATK >= GEN_8)
                        gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_1;
                    else
                        gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_2;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_KingsShieldEffect;
                    effect = 1;
                }
                else if (gProtectStructs[gBattlerTarget].banefulBunkered)
                {
                    gProtectStructs[gBattlerAttacker].touchedProtectLike = FALSE;
                    gBattleScripting.moveEffect = MOVE_EFFECT_POISON | MOVE_EFFECT_AFFECTS_USER;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_BANEFUL_BUNKER);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BanefulBunkerEffect;
                    effect = 1;
                }
                else if (gProtectStructs[gBattlerTarget].obstructed && gMovesInfo[gCurrentMove].effect != EFFECT_SUCKER_PUNCH && gMovesInfo[gCurrentMove].effect != EFFECT_UPPER_HAND)
                {
                    gProtectStructs[gBattlerAttacker].touchedProtectLike = FALSE;
                    i = gBattlerAttacker;
                    gBattlerAttacker = gBattlerTarget;
                    gBattlerTarget = i; // gBattlerTarget and gBattlerAttacker are swapped in order to activate Defiant, if applicable
                    gBattleScripting.moveEffect = MOVE_EFFECT_DEF_MINUS_2;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_KingsShieldEffect;
                    effect = 1;
                }
                else if (gProtectStructs[gBattlerTarget].silkTrapped)
                {
                    gProtectStructs[gBattlerAttacker].touchedProtectLike = FALSE;
                    i = gBattlerAttacker;
                    gBattlerAttacker = gBattlerTarget;
                    gBattlerTarget = i; // gBattlerTarget and gBattlerAttacker are swapped in order to activate Defiant, if applicable
                    gBattleScripting.moveEffect = MOVE_EFFECT_SPD_MINUS_1;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_KingsShieldEffect;
                    effect = 1;
                }
                else if (gProtectStructs[gBattlerTarget].burningBulwarked)
                {
                    gProtectStructs[gBattlerAttacker].touchedProtectLike = FALSE;
                    gBattleScripting.moveEffect = MOVE_EFFECT_BURN | MOVE_EFFECT_AFFECTS_USER;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_BURNING_BULWARK);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BanefulBunkerEffect;
                    effect = 1;
                }
                // Not strictly a protect effect, but works the same way
                else if (gProtectStructs[gBattlerTarget].beakBlastCharge
                         && CanBeBurned(gBattlerAttacker, GetBattlerAbility(gBattlerAttacker))
                         && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
                {
                    gProtectStructs[gBattlerAttacker].touchedProtectLike = FALSE;
                    gBattleMons[gBattlerAttacker].status1 = STATUS1_BURN;
                    BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].status1), &gBattleMons[gBattlerAttacker].status1);
                    MarkBattlerForControllerExec(gBattlerAttacker);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BeakBlastBurn;
                    effect = 1;
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_RAGE: // rage check
            if (gBattleMons[gBattlerTarget].status2 & STATUS2_RAGE
                && IsBattlerAlive(gBattlerTarget)
                && gBattlerAttacker != gBattlerTarget
                && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget)
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                && TARGET_TURN_DAMAGED
                && gMovesInfo[gCurrentMove].power != 0
                && CompareStat(gBattlerTarget, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_ATK, 1, FALSE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_RageIsBuilding;
                effect = TRUE;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_DEFROST: // defrosting check
            if (gBattleMons[gBattlerTarget].status1 & STATUS1_FREEZE
                && IsBattlerAlive(gBattlerTarget)
                && gBattlerAttacker != gBattlerTarget
                && (moveType == TYPE_FIRE || CanBurnHitThaw(gCurrentMove))
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
            {
                gBattleMons[gBattlerTarget].status1 &= ~STATUS1_FREEZE;
                BtlController_EmitSetMonData(gBattlerTarget, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].status1), &gBattleMons[gBattlerTarget].status1);
                MarkBattlerForControllerExec(gBattlerTarget);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_DefrostedViaFireMove;
                effect = TRUE;
            }
            if (gBattleMons[gBattlerTarget].status1 & STATUS1_FROSTBITE
                && IsBattlerAlive(gBattlerTarget)
                && gBattlerAttacker != gBattlerTarget
                && gMovesInfo[originallyUsedMove].thawsUser
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
            {
                gBattleMons[gBattlerTarget].status1 &= ~STATUS1_FROSTBITE;
                BtlController_EmitSetMonData(gBattlerTarget, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].status1), &gBattleMons[gBattlerTarget].status1);
                MarkBattlerForControllerExec(gBattlerTarget);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_FrostbiteHealedViaFireMove;
                effect = TRUE;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_RECOIL:
            if (gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE)
            {
                gBattleScripting.moveendState++;
                break;
            }
            else if (gMovesInfo[gCurrentMove].recoil > 0
                  && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                  && IsBattlerAlive(gBattlerAttacker)
                  && gBattleScripting.savedDmg != 0) // Some checks may be redundant alongside this one
            {
                gBattleMoveDamage = max(1, gBattleScripting.savedDmg * max(1, gMovesInfo[gCurrentMove].recoil) / 100);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_MoveEffectRecoil;
                effect = TRUE;
            }
            else if (gMovesInfo[gCurrentMove].effect == EFFECT_EXPLOSION && !IsAbilityOnField(ABILITY_DAMP))
            {
                gBattleMoveDamage = 0;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_FaintAttackerForExplosion;
                effect = TRUE;
            }
            else if ((gMovesInfo[gCurrentMove].effect == EFFECT_MAX_HP_50_RECOIL
                   || gMovesInfo[gCurrentMove].effect == EFFECT_MIND_BLOWN)
                  && IsBattlerAlive(gBattlerAttacker)
                  && !(gMoveResultFlags & MOVE_RESULT_FAILED)
                  && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
            {
                gBattleMoveDamage = (GetNonDynamaxMaxHP(gBattlerAttacker) + 1) / 2; // Half of Max HP Rounded UP
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_MaxHp50Recoil;
                effect = TRUE;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_SYNCHRONIZE_TARGET: // target synchronize
            if (AbilityBattleEffects(ABILITYEFFECT_SYNCHRONIZE, gBattlerTarget, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_ABILITIES: // Such as abilities activating on contact(Poison Spore, Rough Skin, etc.).
            if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END, gBattlerTarget, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_ABILITIES_ATTACKER: // Poison Touch, possibly other in the future
            if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END_ATTACKER, gBattlerAttacker, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_OPPORTUNIST:
            if (AbilityBattleEffects(ABILITYEFFECT_OPPORTUNIST, 0, 0, 0, 0))
                effect = TRUE; // it loops through all battlers, so we increment after its done with all battlers
            else
                gBattleScripting.moveendState++;
            break;
        case MOVEEND_STATUS_IMMUNITY_ABILITIES: // status immunities
            if (AbilityBattleEffects(ABILITYEFFECT_IMMUNITY, 0, 0, 0, 0))
                effect = TRUE; // it loops through all battlers, so we increment after its done with all battlers
            else
                gBattleScripting.moveendState++;
            break;
        case MOVEEND_SYNCHRONIZE_ATTACKER: // attacker synchronize
            if (AbilityBattleEffects(ABILITYEFFECT_ATK_SYNCHRONIZE, gBattlerAttacker, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_CHOICE_MOVE: // update choice band move
            {
                u16 *choicedMoveAtk = &gBattleStruct->choicedMove[gBattlerAttacker];
                if (gHitMarker & HITMARKER_OBEYS
                 && (HOLD_EFFECT_CHOICE(holdEffectAtk) || GetBattlerAbility(gBattlerAttacker) == ABILITY_GORILLA_TACTICS)
                 && gChosenMove != MOVE_STRUGGLE
                 && (*choicedMoveAtk == MOVE_NONE || *choicedMoveAtk == MOVE_UNAVAILABLE))
                {
                    if ((gMovesInfo[gChosenMove].effect == EFFECT_BATON_PASS
                     || gMovesInfo[gChosenMove].effect == EFFECT_HEALING_WISH)
                     && !(gMoveResultFlags & MOVE_RESULT_FAILED))
                    {
                        gBattleScripting.moveendState++;
                        break;
                    }
                    *choicedMoveAtk = gChosenMove;
                }
                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    if (gBattleMons[gBattlerAttacker].moves[i] == *choicedMoveAtk)
                        break;
                }
                if (i == MAX_MON_MOVES)
                {
                    *choicedMoveAtk = MOVE_NONE;
                }
                gBattleScripting.moveendState++;
                break;
            }
        case MOVEEND_CHANGED_ITEMS: // changed held items
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleStruct->changedItems[i] != ITEM_NONE)
                {
                    gBattleMons[i].item = gBattleStruct->changedItems[i];
                    gBattleStruct->changedItems[i] = ITEM_NONE;
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_ITEM_EFFECTS_TARGET:
            if (ItemBattleEffects(ITEMEFFECT_TARGET, gBattlerTarget, FALSE))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_MOVE_EFFECTS2: // For effects which should happen after target items, for example Knock Off after damage from Rocky Helmet.
        {
            switch (gBattleStruct->moveEffect2)
            {
            case MOVE_EFFECT_KNOCK_OFF:
                if (!DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
                {
                    effect = TryKnockOffBattleScript(gBattlerTarget);
                }
                break;
            case MOVE_EFFECT_STOCKPILE_WORE_OFF:
                if (gDisableStructs[gBattlerAttacker].stockpileCounter != 0)
                {
                    gDisableStructs[gBattlerAttacker].stockpileCounter = 0;
                    effect = TRUE;
                    BattleScriptPush(gBattlescriptCurrInstr);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectStockpileWoreOff;
                }
                break;
            case MOVE_EFFECT_SMACK_DOWN:
                if (!IsBattlerGrounded(gBattlerTarget)
                 && IsBattlerAlive(gBattlerTarget)
                 && !DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
                {
                    gStatuses3[gBattlerTarget] |= STATUS3_SMACKED_DOWN;
                    gStatuses3[gBattlerTarget] &= ~(STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS | STATUS3_ON_AIR);
                    effect = TRUE;
                    BattleScriptPush(gBattlescriptCurrInstr);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectSmackDown;
                }
                break;
            case MOVE_EFFECT_REMOVE_STATUS: // Smelling salts, Wake-Up Slap, Sparkling Aria
                if ((gBattleMons[gBattlerTarget].status1 & gMovesInfo[gCurrentMove].argument)
                 && IsBattlerAlive(gBattlerTarget)
                 && !DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
                {
                    gBattleMons[gBattlerTarget].status1 &= ~(gMovesInfo[gCurrentMove].argument);

                    BtlController_EmitSetMonData(gBattlerTarget, 0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBattlerTarget].status1);
                    MarkBattlerForControllerExec(gBattlerTarget);
                    effect = TRUE;
                    BattleScriptPush(gBattlescriptCurrInstr);
                    switch (gMovesInfo[gCurrentMove].argument)
                    {
                    case STATUS1_PARALYSIS:
                        gBattlescriptCurrInstr = BattleScript_TargetPRLZHeal;
                        break;
                    case STATUS1_SLEEP:
                        gBattlescriptCurrInstr = BattleScript_TargetWokeUp;
                        break;
                    case STATUS1_BURN:
                        gBattlescriptCurrInstr = BattleScript_TargetBurnHeal;
                        break;
                    case STATUS1_FREEZE:
                        gBattlescriptCurrInstr = BattleScript_DefrostedViaFireMove;
                        break;
                    case STATUS1_FROSTBITE:
                        gBattlescriptCurrInstr = BattleScript_FrostbiteHealedViaFireMove;
                        break;
                    case STATUS1_POISON:
                    case STATUS1_TOXIC_POISON:
                    case STATUS1_PSN_ANY:
                        gBattlescriptCurrInstr = BattleScript_TargetPoisonHealed;
                        break;
                    }
                }
                break; // MOVE_EFFECT_REMOVE_STATUS
            }
            gBattleStruct->moveEffect2 = 0;
            gBattleScripting.moveendState++;
            break; // MOVEEND_MOVE_EFFECTS2
        }
        case MOVEEND_ITEM_EFFECTS_ALL: // item effects for all battlers
            if (ItemBattleEffects(ITEMEFFECT_MOVE_END, 0, FALSE))
                effect = TRUE;
            else
                gBattleScripting.moveendState++;
            break;
        case MOVEEND_KINGSROCK: // King's rock
            // These effects will occur at each hit in a multi-strike move
            if (ItemBattleEffects(ITEMEFFECT_KINGSROCK, 0, FALSE))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_ATTACKER_INVISIBLE: // make attacker sprite invisible
            if (gStatuses3[gBattlerAttacker] & (STATUS3_SEMI_INVULNERABLE)
                && gHitMarker & (HITMARKER_NO_ANIMATIONS | HITMARKER_DISABLE_ANIMATION))
            {
                BtlController_EmitSpriteInvisibility(gBattlerAttacker, BUFFER_A, TRUE);
                MarkBattlerForControllerExec(gBattlerAttacker);
                gBattleScripting.moveendState++;
                return;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_ATTACKER_VISIBLE: // make attacker sprite visible
            if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT
                || !(gStatuses3[gBattlerAttacker] & (STATUS3_SEMI_INVULNERABLE))
                || WasUnableToUseMove(gBattlerAttacker))
            {
                BtlController_EmitSpriteInvisibility(gBattlerAttacker, BUFFER_A, FALSE);
                MarkBattlerForControllerExec(gBattlerAttacker);
                gStatuses3[gBattlerAttacker] &= ~STATUS3_SEMI_INVULNERABLE;
                gSpecialStatuses[gBattlerAttacker].restoredBattlerSprite = TRUE;
                gBattleScripting.moveendState++;
                return;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_TARGET_VISIBLE: // make target sprite visible
            if (!gSpecialStatuses[gBattlerTarget].restoredBattlerSprite && gBattlerTarget < gBattlersCount
                && !(gStatuses3[gBattlerTarget] & STATUS3_SEMI_INVULNERABLE))
            {
                BtlController_EmitSpriteInvisibility(gBattlerTarget, BUFFER_A, FALSE);
                MarkBattlerForControllerExec(gBattlerTarget);
                gStatuses3[gBattlerTarget] &= ~STATUS3_SEMI_INVULNERABLE;
                gBattleScripting.moveendState++;
                return;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_NUM_HITS:
            if (gBattlerAttacker != gBattlerTarget
                && gMovesInfo[gCurrentMove].category != DAMAGE_CATEGORY_STATUS
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                && TARGET_TURN_DAMAGED)
            {
                gBattleStruct->timesGotHit[GetBattlerSide(gBattlerTarget)][gBattlerPartyIndexes[gBattlerTarget]]++;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_SUBSTITUTE: // update substitute
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gDisableStructs[i].substituteHP == 0)
                    gBattleMons[i].status2 &= ~STATUS2_SUBSTITUTE;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_SKY_DROP_CONFUSE: // If a Pokemon was released from Sky Drop and was in LOCK_CONFUSE, go to "confused due to fatigue" scripts and clear Sky Drop data.
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleStruct->skyDropTargets[i] == 0xFE)
                {
                    u8 targetId;
                    // Find the battler id of the Pokemon that was held by Sky Drop
                    for (targetId = 0; targetId < gBattlersCount; targetId++)
                    {
                        if (gBattleStruct->skyDropTargets[targetId] == i)
                            break;
                    }

                    // Set gBattlerAttacker to the battler id of the target
                    gBattlerAttacker = targetId;

                    // Jump to "confused due to fatigue" script
                    gBattlescriptCurrInstr = BattleScript_ThrashConfuses;

                    // Clear skyDropTargets data
                    gBattleStruct->skyDropTargets[i] = 0xFF;
                    gBattleStruct->skyDropTargets[targetId] = 0xFF;
                    return;
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_UPDATE_LAST_MOVES:
            if ((gMoveResultFlags & (MOVE_RESULT_FAILED | MOVE_RESULT_DOESNT_AFFECT_FOE))
             || (gBattleMons[gBattlerAttacker].status2 & (STATUS2_FLINCHED))
             || gProtectStructs[gBattlerAttacker].prlzImmobility)
                gBattleStruct->lastMoveFailed |= gBitTable[gBattlerAttacker];
            else
                gBattleStruct->lastMoveFailed &= ~(gBitTable[gBattlerAttacker]);

            // Set ShellTrap to activate after the attacker's turn if target was hit by a physical move.
            if (gMovesInfo[gChosenMoveByBattler[gBattlerTarget]].effect == EFFECT_SHELL_TRAP
                && gBattlerTarget != gBattlerAttacker
                && GetBattlerSide(gBattlerTarget) != GetBattlerSide(gBattlerAttacker)
                && gProtectStructs[gBattlerTarget].physicalDmg
                && gProtectStructs[gBattlerTarget].physicalBattlerId == gBattlerAttacker
                && !TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove))
            {
                gProtectStructs[gBattlerTarget].shellTrap = TRUE;
                // Change move order in double battles, so the hit mon with shell trap moves immediately after being hit.
                if (IsDoubleBattle())
                {
                    ChangeOrderTargetAfterAttacker();
                }
            }

            if (gHitMarker & HITMARKER_SWAP_ATTACKER_TARGET)
            {
                u8 temp;
                SWAP(gBattlerAttacker, gBattlerTarget, temp);
                gHitMarker &= ~HITMARKER_SWAP_ATTACKER_TARGET;
            }
            if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
            {
                gDisableStructs[gBattlerAttacker].usedMoves |= gBitTable[gCurrMovePos];
                gBattleStruct->lastMoveTarget[gBattlerAttacker] = gBattlerTarget;
                if (gHitMarker & HITMARKER_ATTACKSTRING_PRINTED)
                {
                    gLastPrintedMoves[gBattlerAttacker] = gChosenMove;
                    gLastUsedMove = gCurrentMove;
                    if (IsMaxMove(gCurrentMove))
                        gBattleStruct->dynamax.lastUsedBaseMove = gBattleStruct->dynamax.baseMoves[gBattlerAttacker];
                }
            }
            if (!(gAbsentBattlerFlags & gBitTable[gBattlerAttacker])
                && !(gBattleStruct->absentBattlerFlags & gBitTable[gBattlerAttacker])
                && gMovesInfo[originallyUsedMove].effect != EFFECT_BATON_PASS
                && gMovesInfo[originallyUsedMove].effect != EFFECT_HEALING_WISH)
            {
                if (gHitMarker & HITMARKER_OBEYS)
                {
                    if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
                    {
                        gLastMoves[gBattlerAttacker] = gChosenMove;
                        RecordKnownMove(gBattlerAttacker, gChosenMove);
                        gLastResultingMoves[gBattlerAttacker] = gCurrentMove;
                    }
                }
                else
                {
                    gLastMoves[gBattlerAttacker] = MOVE_UNAVAILABLE;
                    gLastResultingMoves[gBattlerAttacker] = MOVE_UNAVAILABLE;
                }

                if (!(gHitMarker & HITMARKER_FAINTED(gBattlerTarget)))
                    gLastHitBy[gBattlerTarget] = gBattlerAttacker;

                if (gHitMarker & HITMARKER_OBEYS && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
                {
                    if (gChosenMove == MOVE_UNAVAILABLE)
                    {
                        gLastLandedMoves[gBattlerTarget] = gChosenMove;
                    }
                    else
                    {
                        gLastLandedMoves[gBattlerTarget] = gCurrentMove;
                        GET_MOVE_TYPE(gCurrentMove, gLastHitByType[gBattlerTarget]);
                    }
                }
                else
                {
                    gLastLandedMoves[gBattlerTarget] = MOVE_UNAVAILABLE;
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_MIRROR_MOVE: // mirror move
            if (!(gAbsentBattlerFlags & gBitTable[gBattlerAttacker])
                && !(gBattleStruct->absentBattlerFlags & gBitTable[gBattlerAttacker])
                && !gMovesInfo[originallyUsedMove].mirrorMoveBanned
                && gHitMarker & HITMARKER_OBEYS
                && gBattlerAttacker != gBattlerTarget
                && !(gHitMarker & HITMARKER_FAINTED(gBattlerTarget))
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
            {
                gBattleStruct->lastTakenMove[gBattlerTarget] = gChosenMove;
                gBattleStruct->lastTakenMoveFrom[gBattlerTarget][gBattlerAttacker] = gChosenMove;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_NEXT_TARGET: // For moves hitting two opposing Pokemon.
        {
            u16 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);
            // Set a flag if move hits either target (for throat spray that can't check damage)
            if (!(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE)
             && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
                gProtectStructs[gBattlerAttacker].targetAffected = TRUE;

            gBattleStruct->targetsDone[gBattlerAttacker] |= gBitTable[gBattlerTarget];
            if (!(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE)
                && gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                && !gProtectStructs[gBattlerAttacker].chargingTurn
                && (moveTarget == MOVE_TARGET_BOTH
                    || moveTarget == MOVE_TARGET_FOES_AND_ALLY)
                && !(gHitMarker & HITMARKER_NO_ATTACKSTRING))
            {
                u32 nextTarget = GetNextTarget(moveTarget, FALSE);
                gHitMarker |= HITMARKER_NO_PPDEDUCT;

                if (nextTarget != MAX_BATTLERS_COUNT)
                {
                    gBattleStruct->moveTarget[gBattlerAttacker] = gBattlerTarget = nextTarget; // Fix for moxie spread moves
                    gBattleScripting.moveendState = 0;
                    MoveValuesCleanUp();
                    gBattleScripting.moveEffect = gBattleScripting.savedMoveEffect;

                    if (gMovesInfo[gCurrentMove].effect == EFFECT_EXPLOSION)
                        BattleScriptPush(gBattleMoveEffects[EFFECT_HIT].battleScript); // Edge case for Explosion not changing targets
                    else
                        BattleScriptPush(GET_MOVE_BATTLESCRIPT(gCurrentMove));
                    gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
                    return;
                }
                // Check if the move used was actually a bounced move. If so, we need to go back to the original attacker and make sure, its move hits all 2 or 3 pokemon.
                else if (gBattleStruct->bouncedMoveIsUsed)
                {
                    u8 originalBounceTarget = gBattlerAttacker;
                    gBattleStruct->bouncedMoveIsUsed = FALSE;
                    gBattlerAttacker = gBattleStruct->attackerBeforeBounce;
                    gBattleStruct->targetsDone[gBattlerAttacker] |= gBitTable[originalBounceTarget];
                    gBattleStruct->targetsDone[originalBounceTarget] = 0;

                    nextTarget = GetNextTarget(moveTarget, FALSE);
                    if (nextTarget != MAX_BATTLERS_COUNT)
                    {
                        // We found another target for the original move user.
                        gBattleStruct->moveTarget[gBattlerAttacker] = gBattlerTarget = nextTarget;
                        gBattleScripting.moveendState = 0;
                        gBattleScripting.animTurn = 0;
                        gBattleScripting.animTargetsHit = 0;
                        MoveValuesCleanUp();
                        BattleScriptPush(GET_MOVE_BATTLESCRIPT(gCurrentMove));
                        gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
                        return;
                    }
                }

                gHitMarker |= HITMARKER_NO_ATTACKSTRING;
                gHitMarker &= ~HITMARKER_NO_PPDEDUCT;
            }
            RecordLastUsedMoveBy(gBattlerAttacker, gCurrentMove);
            gBattleScripting.moveendState++;
            break;
        }
        case MOVEEND_MULTIHIT_MOVE:
        {
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
            && !(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE)
            && gMultiHitCounter
            && !(gMovesInfo[gCurrentMove].effect == EFFECT_PRESENT && gBattleStruct->presentBasePower == 0)) // Silly edge case
            {
                gMultiHitCounter--;
                if (!IsBattlerAlive(gBattlerTarget) && gMovesInfo[gCurrentMove].effect != EFFECT_DRAGON_DARTS)
                    gMultiHitCounter = 0;

                gBattleScripting.multihitString[4]++;
                if (gMultiHitCounter == 0)
                {
                    BattleScriptPushCursor();
                    if (gMovesInfo[gCurrentMove].argument == MOVE_EFFECT_SCALE_SHOT && !NoAliveMonsForEitherParty())
                        gBattlescriptCurrInstr = BattleScript_ScaleShot;
                    else
                        gBattlescriptCurrInstr = BattleScript_MultiHitPrintStrings;
                    effect = TRUE;
                }
                else
                {
                    if (gMovesInfo[gCurrentMove].effect == EFFECT_DRAGON_DARTS
                     && gBattleStruct->moveTarget[gBattlerAttacker] == gBattlerTarget // Haven't already changed targets
                     && CanTargetPartner(gBattlerAttacker, gBattlerTarget)
                     && !TargetFullyImmuneToCurrMove(gBattlerAttacker, BATTLE_PARTNER(gBattlerTarget)))
                        gBattlerTarget = BATTLE_PARTNER(gBattlerTarget); // Target the partner in doubles for second hit.

                    if (gBattleMons[gBattlerAttacker].hp
                     && gBattleMons[gBattlerTarget].hp
                     && (gChosenMove == MOVE_SLEEP_TALK || (gChosenMove == MOVE_SNORE) || !(gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP))
                     && !(gBattleMons[gBattlerAttacker].status1 & STATUS1_FREEZE))
                    {
                        if (gSpecialStatuses[gBattlerAttacker].parentalBondState)
                            gSpecialStatuses[gBattlerAttacker].parentalBondState--;

                        gHitMarker |= (HITMARKER_NO_PPDEDUCT | HITMARKER_NO_ATTACKSTRING);
                        gBattleScripting.animTargetsHit = 0;
                        gBattleScripting.moveendState = 0;
                        gSpecialStatuses[gBattlerTarget].sturdied = 0;
                        gSpecialStatuses[gBattlerTarget].focusBanded = 0; // Delete this line to make Focus Band last for the duration of the whole move turn.
                        gSpecialStatuses[gBattlerTarget].focusSashed = 0; // Delete this line to make Focus Sash last for the duration of the whole move turn.
                        gSpecialStatuses[gBattlerAttacker].multiHitOn = TRUE;
                        MoveValuesCleanUp();
                        BattleScriptPush(GET_MOVE_BATTLESCRIPT(gCurrentMove));
                        gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
                        return;
                    }
                    else
                    {
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_MultiHitPrintStrings;
                        effect = TRUE;
                    }
                }
            }
            gMultiHitCounter = 0;
            gSpecialStatuses[gBattlerAttacker].parentalBondState = PARENTAL_BOND_OFF;
            gSpecialStatuses[gBattlerAttacker].multiHitOn = 0;
            gBattleScripting.moveendState++;
            break;
        }
        // The order of abilities/items activating after moves hitting multiple targets is
        // 1. Magician
        // 2. The fastest mon gets switched out using Eject Button / Eject Pack
        // 3. White Herb activates
        // 4. Red Card activates
        // 5. Life Orb / Shell Bell
        // 6. Pickpocket
        case MOVEEND_MAGICIAN:
            if (GetBattlerAbility(gBattlerAttacker) == ABILITY_MAGICIAN
              && gCurrentMove != MOVE_FLING && gCurrentMove != MOVE_NATURAL_GIFT
              && gBattleMons[gBattlerAttacker].item == ITEM_NONE
              && gBattleMons[gBattlerTarget].item != ITEM_NONE
              && IsBattlerAlive(gBattlerAttacker)
              && TARGET_TURN_DAMAGED
              && CanStealItem(gBattlerAttacker, gBattlerTarget, gBattleMons[gBattlerTarget].item)
              && !gSpecialStatuses[gBattlerAttacker].gemBoost   // In base game, gems are consumed after magician would activate.
              && !(gWishFutureKnock.knockedOffMons[GetBattlerSide(gBattlerTarget)] & gBitTable[gBattlerPartyIndexes[gBattlerTarget]])
              && !DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove)
              && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
              && (GetBattlerAbility(gBattlerTarget) != ABILITY_STICKY_HOLD || !IsBattlerAlive(gBattlerTarget)))
            {
                StealTargetItem(gBattlerAttacker, gBattlerTarget);
                gBattleScripting.battler = gBattlerAbility = gBattlerAttacker;
                gEffectBattler = gBattlerTarget;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_MagicianActivates;
                gSpecialStatuses[gBattlerAttacker].preventLifeOrbDamage = TRUE;
                effect = TRUE;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_EJECT_ITEMS:
            {
                // Because sorting the battlers by speed takes lots of cycles, it's better to just check if any of the battlers has the Eject items.
                u32 ejectPackBattlers = 0, ejectButtonBattlers = 0, i;
                for (i = 0; i < gBattlersCount; i++)
                {
                    u32 holdEffect;
                    holdEffect = GetBattlerHoldEffect(i, TRUE);
                    if (holdEffect == HOLD_EFFECT_EJECT_BUTTON)
                        ejectButtonBattlers |= gBitTable[i];
                    else if (holdEffect == HOLD_EFFECT_EJECT_PACK)
                        ejectPackBattlers |= gBitTable[i];
                }
                if (ejectButtonBattlers || ejectPackBattlers)
                {
                    u8 battlers[4] = {0, 1, 2, 3};
                    SortBattlersBySpeed(battlers, FALSE);

                    for (i = 0; i < gBattlersCount; i++)
                    {
                        u32 battler = battlers[i];

                        if (battler != gBattlerAttacker && ejectButtonBattlers & gBitTable[battler])
                        {
                            if (TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove)) // Apparently Sheer Force blocks Eject Button, but not Eject Pack
                                continue;
                            // Since we check if battler was damaged, we don't need to check move result.
                            // In fact, doing so actually prevents multi-target moves from activating eject button properly
                            if (!BATTLER_TURN_DAMAGED(battler))
                                continue;
                        }
                        else if (ejectPackBattlers & gBitTable[battler])
                        {
                            if (!gProtectStructs[battler].statFell || gProtectStructs[battler].disableEjectPack)
                                continue;
                        }
                        else
                        {
                            continue;
                        }

                        if (IsBattlerAlive(battler)
                            && CountUsablePartyMons(battler) > 0 // Has mon to switch into
                            // Does not activate if attacker used Parting Shot and can switch out
                            && !(gMovesInfo[gCurrentMove].effect == EFFECT_HIT_SWITCH_TARGET && CanBattlerSwitch(gBattlerAttacker))
                            )
                        {
                            gBattleScripting.battler = battler;
                            gLastUsedItem = gBattleMons[battler].item;
                            if (gMovesInfo[gCurrentMove].effect == EFFECT_HIT_ESCAPE)
                                gBattlescriptCurrInstr = BattleScript_MoveEnd;  // Prevent user switch-in selection
                            effect = TRUE;
                            BattleScriptPushCursor();
                            if (ejectButtonBattlers & gBitTable[battler])
                            {
                                gBattlescriptCurrInstr = BattleScript_EjectButtonActivates;
                            }
                            else // Eject Pack
                            {
                                gBattlescriptCurrInstr = BattleScript_EjectPackActivates;
                                // Are these 2 lines below needed?
                                gProtectStructs[battler].statFell = FALSE;
                                gSpecialStatuses[gBattlerAttacker].preventLifeOrbDamage = TRUE;
                            }
                            break; // Only the fastest Eject item activates
                        }
                    }
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_WHITE_HERB:
            for (i = 0; i < gBattlersCount; i++)
            {
                if (IsBattlerAlive(i)
                    && ItemBattleEffects(ITEMEFFECT_STATS_CHANGED, i, FALSE))
                {
                    effect = TRUE;
                    break;
                }
            }
            if (!effect)
                gBattleScripting.moveendState++;
            break;
        case MOVEEND_RED_CARD:
            {
                u32 redCardBattlers = 0, i;
                for (i = 0; i < gBattlersCount; i++)
                {
                    if (i == gBattlerAttacker)
                        continue;
                    if (GetBattlerHoldEffect(i, TRUE) == HOLD_EFFECT_RED_CARD)
                        redCardBattlers |= gBitTable[i];
                }
                if (redCardBattlers
                  && (gMovesInfo[gCurrentMove].effect != EFFECT_HIT_SWITCH_TARGET || gBattleStruct->hitSwitchTargetFailed)
                  && IsBattlerAlive(gBattlerAttacker)
                  && !TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove)
                  && GetBattlerAbility(gBattlerAttacker) != ABILITY_GUARD_DOG)
                {
                    // Since we check if battler was damaged, we don't need to check move result.
                    // In fact, doing so actually prevents multi-target moves from activating red card properly
                    u8 battlers[4] = {0, 1, 2, 3};
                    SortBattlersBySpeed(battlers, FALSE);
                    for (i = 0; i < gBattlersCount; i++)
                    {
                        u32 battler = battlers[i];
                        // Search for fastest hit pokemon with a red card
                        // Attacker is the one to be switched out, battler is one with red card
                        if (redCardBattlers & gBitTable[battler]
                          && IsBattlerAlive(battler)
                          && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove)
                          && BATTLER_TURN_DAMAGED(battler)
                          && CanBattlerSwitch(gBattlerAttacker))
                        {
                            gLastUsedItem = gBattleMons[battler].item;
                            SaveBattlerTarget(battler); // save battler with red card
                            gBattleScripting.battler = battler;
                            gEffectBattler = gBattlerAttacker;
                            if (gMovesInfo[gCurrentMove].effect == EFFECT_HIT_ESCAPE)
                                gBattlescriptCurrInstr = BattleScript_MoveEnd;  // Prevent user switch-in selection
                            BattleScriptPushCursor();
                            gBattlescriptCurrInstr = BattleScript_RedCardActivates;
                            gSpecialStatuses[gBattlerAttacker].preventLifeOrbDamage = TRUE;
                            effect = TRUE;
                            break;  // Only fastest red card activates
                        }
                    }
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_LIFEORB_SHELLBELL:
            if (ItemBattleEffects(ITEMEFFECT_LIFEORB_SHELLBELL, 0, FALSE))
                effect = TRUE;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_PICKPOCKET:
            if (IsBattlerAlive(gBattlerAttacker)
              && gBattleMons[gBattlerAttacker].item != ITEM_NONE        // Attacker must be holding an item
              && !(gWishFutureKnock.knockedOffMons[GetBattlerSide(gBattlerAttacker)] & gBitTable[gBattlerPartyIndexes[gBattlerAttacker]])   // But not knocked off
              && !(TestIfSheerForceAffected(gBattlerAttacker, gCurrentMove))  // Pickpocket doesn't activate for sheer force
              && IsMoveMakingContact(gCurrentMove, gBattlerAttacker)    // Pickpocket requires contact
              && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))           // Obviously attack needs to have worked
            {
                u8 battlers[4] = {0, 1, 2, 3};
                SortBattlersBySpeed(battlers, FALSE); // Pickpocket activates for fastest mon without item
                for (i = 0; i < gBattlersCount; i++)
                {
                    u8 battler = battlers[i];
                    // Attacker is mon who made contact, battler is mon with pickpocket
                    if (battler != gBattlerAttacker                                                     // Cannot pickpocket yourself
                      && GetBattlerAbility(battler) == ABILITY_PICKPOCKET                               // Target must have pickpocket ability
                      && BATTLER_TURN_DAMAGED(battler)                                                  // Target needs to have been damaged
                      && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove)              // Subsitute unaffected
                      && IsBattlerAlive(battler)                                                        // Battler must be alive to pickpocket
                      && gBattleMons[battler].item == ITEM_NONE                                         // Pickpocketer can't have an item already
                      && CanStealItem(battler, gBattlerAttacker, gBattleMons[gBattlerAttacker].item))   // Cannot steal plates, mega stones, etc
                    {
                        gBattlerTarget = gBattlerAbility = battler;
                        // Battle scripting is super brittle so we shall do the item exchange now (if possible)
                        if (GetBattlerAbility(gBattlerAttacker) != ABILITY_STICKY_HOLD)
                            StealTargetItem(gBattlerTarget, gBattlerAttacker);  // Target takes attacker's item

                        gEffectBattler = gBattlerAttacker;
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_Pickpocket;   // Includes sticky hold check to print separate string
                        effect = TRUE;
                        break; // Pickpocket activates on fastest mon, so exit loop.
                    }
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_DANCER: // Special case because it's so annoying
            if (gMovesInfo[gCurrentMove].danceMove && !gBattleStruct->snatchedMoveIsUsed)
            {
                u32 battler, nextDancer = 0;
                bool32 hasDancerTriggered = FALSE;

                for (battler = 0; battler < gBattlersCount; battler++)
                {
                    if (gSpecialStatuses[battler].dancerUsedMove)
                    {
                        // in case a battler fails to act on a Dancer-called move
                        hasDancerTriggered = TRUE;
                        break;
                    }
                }

                if (!(gMoveResultFlags & (MOVE_RESULT_FAILED | MOVE_RESULT_DOESNT_AFFECT_FOE)
                 || (gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE && !hasDancerTriggered)
                 || (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove && gBattleStruct->bouncedMoveIsUsed)))
                {   // Dance move succeeds
                    // Set target for other Dancer mons; set bit so that mon cannot activate Dancer off of its own move
                    if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
                    {
                        gBattleScripting.savedBattler = gBattlerTarget | 0x4;
                        gBattleScripting.savedBattler |= (gBattlerAttacker << 4);
                        gSpecialStatuses[gBattlerAttacker].dancerUsedMove = TRUE;
                    }
                    for (battler = 0; battler < gBattlersCount; battler++)
                    {
                        if (GetBattlerAbility(battler) == ABILITY_DANCER && !gSpecialStatuses[battler].dancerUsedMove)
                        {
                            if (!nextDancer || (gBattleMons[battler].speed < gBattleMons[nextDancer & 0x3].speed))
                                nextDancer = battler | 0x4;
                        }
                    }
                    if (nextDancer && AbilityBattleEffects(ABILITYEFFECT_MOVE_END_OTHER, nextDancer & 0x3, 0, 0, 0))
                        effect = TRUE;
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_EMERGENCY_EXIT: // Special case, because moves hitting multiple opponents stop after switching out
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleResources->flags->flags[i] & RESOURCE_FLAG_EMERGENCY_EXIT)
                {
                    gBattleResources->flags->flags[i] &= ~RESOURCE_FLAG_EMERGENCY_EXIT;
                    gSpecialStatuses[i].emergencyExited = TRUE;
                    gBattlerTarget = gBattlerAbility = i;
                    BattleScriptPushCursor();
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER || GetBattlerSide(i) == B_SIDE_PLAYER)
                    {
                        if (B_ABILITY_POP_UP == TRUE)
                            gBattlescriptCurrInstr = BattleScript_EmergencyExit;
                        else
                            gBattlescriptCurrInstr = BattleScript_EmergencyExitNoPopUp;
                    }
                    else
                    {
                        if (B_ABILITY_POP_UP == TRUE)
                            gBattlescriptCurrInstr = BattleScript_EmergencyExitWild;
                        else
                            gBattlescriptCurrInstr = BattleScript_EmergencyExitWildNoPopUp;
                    }
                    return;
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_SYMBIOSIS:
            for (i = 0; i < gBattlersCount; i++)
            {
                if ((gSpecialStatuses[i].berryReduced
                      || (B_SYMBIOSIS_GEMS >= GEN_7 && gSpecialStatuses[i].gemBoost))
                    && SYMBIOSIS_CHECK(i, BATTLE_PARTNER(i)))
                {
                    BestowItem(BATTLE_PARTNER(i), i);
                    gLastUsedAbility = gBattleMons[BATTLE_PARTNER(i)].ability;
                    gBattleScripting.battler = gBattlerAbility = BATTLE_PARTNER(i);
                    gBattlerAttacker = i;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_SymbiosisActivates;
                    effect = TRUE;
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_SAME_MOVE_TURNS:
            if (gCurrentMove != gLastResultingMoves[gBattlerAttacker] || gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                gBattleStruct->sameMoveTurns[gBattlerAttacker] = 0;
            else if (gCurrentMove == gLastResultingMoves[gBattlerAttacker] && gSpecialStatuses[gBattlerAttacker].parentalBondState != PARENTAL_BOND_1ST_HIT)
                gBattleStruct->sameMoveTurns[gBattlerAttacker]++;
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_SET_EVOLUTION_TRACKER:
            // If the Pokémon needs to keep track of move usage for its evolutions, do it
            if (originallyUsedMove != MOVE_NONE)
                TryUpdateEvolutionTracker(EVO_USE_MOVE_TWENTY_TIMES, 1, originallyUsedMove);
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_CLEAR_BITS: // Clear/Set bits for things like using a move for all targets and all hits.
            if (gSpecialStatuses[gBattlerAttacker].instructedChosenTarget)
                *(gBattleStruct->moveTarget + gBattlerAttacker) = gSpecialStatuses[gBattlerAttacker].instructedChosenTarget & 0x3;
            if (gSpecialStatuses[gBattlerAttacker].dancerOriginalTarget)
                *(gBattleStruct->moveTarget + gBattlerAttacker) = gSpecialStatuses[gBattlerAttacker].dancerOriginalTarget & 0x3;

            if (B_RAMPAGE_CANCELLING >= GEN_5
              && MoveHasAdditionalEffectSelf(gCurrentMove, MOVE_EFFECT_THRASH) // If we're rampaging
              && (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)         // And it is unusable
              && (gBattleMons[gBattlerAttacker].status2 & STATUS2_LOCK_CONFUSE) != STATUS2_LOCK_CONFUSE_TURN(1))  // And won't end this turn
                CancelMultiTurnMoves(gBattlerAttacker); // Cancel it



            if (gBattleStruct->savedAttackerCount > 0)
            {
                // #if TESTING
                // Test_ExitWithResult(TEST_RESULT_ERROR,  "savedAttackerCount is greater than 0! More calls to SaveBattlerAttacker than RestoreBattlerAttacker!");
                // #else
                DebugPrintfLevel(MGBA_LOG_WARN, "savedAttackerCount is greater than 0! More calls to SaveBattlerAttacker than RestoreBattlerAttacker!");
                // #endif
            }
            if (gBattleStruct->savedTargetCount > 0)
            {
                // #if TESTING
                // Test_ExitWithResult(TEST_RESULT_ERROR, "savedTargetCount is greater than 0! More calls to SaveBattlerTarget than RestoreBattlerTarget!");
                // #else
                DebugPrintfLevel(MGBA_LOG_WARN, "savedTargetCount is greater than 0! More calls to SaveBattlerTarget than RestoreBattlerTarget!");
                // #endif
            }
            gBattleStruct->targetsDone[gBattlerAttacker] = 0;
            gProtectStructs[gBattlerAttacker].targetAffected = FALSE;
            gProtectStructs[gBattlerAttacker].shellTrap = FALSE;
            gBattleStruct->ateBoost[gBattlerAttacker] = 0;
            gStatuses3[gBattlerAttacker] &= ~STATUS3_ME_FIRST;
            gSpecialStatuses[gBattlerAttacker].gemBoost = FALSE;
            gSpecialStatuses[gBattlerAttacker].damagedMons = 0;
            gSpecialStatuses[gBattlerAttacker].preventLifeOrbDamage = 0;
            gSpecialStatuses[gBattlerTarget].berryReduced = FALSE;
            gBattleScripting.moveEffect = 0;
            gBattleStruct->hitSwitchTargetFailed = FALSE;
            gBattleStruct->isAtkCancelerForCalledMove = FALSE;
            gBattleStruct->swapDamageCategory = FALSE;
            gBattleStruct->categoryOverride = FALSE;
            gBattleStruct->bouncedMoveIsUsed = FALSE;
            gBattleStruct->snatchedMoveIsUsed = FALSE;
            gBattleStruct->enduredDamage = 0;
            gBattleStruct->additionalEffectsCounter = 0;
            gBattleStruct->poisonPuppeteerConfusion = FALSE;
            gBattleStruct->fickleBeamBoosted = FALSE;
            gBattleStruct->distortedTypeMatchups = 0;
            gBattleStruct->usedMicleBerry &= ~(1u << gBattlerAttacker);
            if (gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE)
                gBattleStruct->pledgeMove = FALSE;
            if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE)
                SetActiveGimmick(gBattlerAttacker, GIMMICK_NONE);
            if (B_CHARGE <= GEN_8 || moveType == TYPE_ELECTRIC)
                gStatuses3[gBattlerAttacker] &= ~(STATUS3_CHARGED_UP);
            memset(gQueuedStatBoosts, 0, sizeof(gQueuedStatBoosts));
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_COUNT:
            break;
        }

        if (endMode == 1 && effect == FALSE)
            gBattleScripting.moveendState = MOVEEND_COUNT;
        if (endMode == 2 && endState == gBattleScripting.moveendState)
            gBattleScripting.moveendState = MOVEEND_COUNT;

    } while (gBattleScripting.moveendState != MOVEEND_COUNT && effect == FALSE);

    if (gBattleScripting.moveendState == MOVEEND_COUNT && effect == FALSE)
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_sethealblock(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gStatuses3[gBattlerTarget] & STATUS3_HEAL_BLOCK)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gStatuses3[gBattlerTarget] |= STATUS3_HEAL_BLOCK;
        gDisableStructs[gBattlerTarget].healBlockTimer = 5;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_returnatktoball(void)
{
    CMD_ARGS();

    if (!(gHitMarker & HITMARKER_FAINTED(gBattlerAttacker)))
    {
        BtlController_EmitReturnMonToBall(gBattlerAttacker, BUFFER_A, FALSE);
        MarkBattlerForControllerExec(gBattlerAttacker);
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_getswitchedmondata(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (gBattleControllerExecFlags)
        return;

    gBattlerPartyIndexes[battler] = gBattleStruct->monToSwitchIntoId[battler];

    BtlController_EmitGetMonData(battler, BUFFER_A, REQUEST_ALL_BATTLE, gBitTable[gBattlerPartyIndexes[battler]]);
    MarkBattlerForControllerExec(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_switchindataupdate(void)
{
    CMD_ARGS(u8 battler);

    struct BattlePokemon oldData;
    u32 battler, i;
    u8 *monData;

    if (gBattleControllerExecFlags)
        return;

    battler = GetBattlerForBattleScript(cmd->battler);
    oldData = gBattleMons[battler];
    monData = (u8 *)(&gBattleMons[battler]);

    for (i = 0; i < sizeof(struct BattlePokemon); i++)
        monData[i] = gBattleResources->bufferB[battler][4 + i];

    // Edge case: the sent out pokemon has 0 HP. This should never happen.
    if (!IsBattlerAlive(battler))
    {
        // If it's a test, mark it as invalid.
        if (gTestRunnerEnabled)
        {
            TestRunner_Battle_InvalidNoHPMon(battler, gBattlerPartyIndexes[battler]);
        }
        // Handle in-game scenario.
        else
        {
            struct Pokemon *party = GetBattlerParty(battler);
            // Find the first possible replacement for the not valid pokemon.
            for (i = 0; i < PARTY_SIZE; i++)
            {
                if (IsValidForBattle(&party[i]))
                    break;
            }
            // There is valid replacement.
            if (i != PARTY_SIZE)
            {
                gBattlerPartyIndexes[battler] = gBattleStruct->monToSwitchIntoId[battler] = i;
                BtlController_EmitGetMonData(battler, BUFFER_A, REQUEST_ALL_BATTLE, gBitTable[gBattlerPartyIndexes[battler]]);
                MarkBattlerForControllerExec(battler);
                return;
            }
        }
    }

    gBattleMons[battler].types[0] = gSpeciesInfo[gBattleMons[battler].species].types[0];
    gBattleMons[battler].types[1] = gSpeciesInfo[gBattleMons[battler].species].types[1];
    gBattleMons[battler].types[2] = TYPE_MYSTERY;
    gBattleMons[battler].ability = GetAbilityBySpecies(gBattleMons[battler].species, gBattleMons[battler].abilityNum);
    #if TESTING
    if (gTestRunnerEnabled)
    {
        u32 side = GetBattlerSide(battler);
        u32 partyIndex = gBattlerPartyIndexes[battler];
        if (TestRunner_Battle_GetForcedAbility(side, partyIndex))
            gBattleMons[battler].ability = gBattleStruct->overwrittenAbilities[battler] = TestRunner_Battle_GetForcedAbility(side, partyIndex);
    }
    #endif

    // check knocked off item
    i = GetBattlerSide(battler);
    if (gWishFutureKnock.knockedOffMons[i] & gBitTable[gBattlerPartyIndexes[battler]])
    {
        gBattleMons[battler].item = ITEM_NONE;
    }

    if (gMovesInfo[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        for (i = 0; i < NUM_BATTLE_STATS; i++)
        {
            gBattleMons[battler].statStages[i] = oldData.statStages[i];
        }
        gBattleMons[battler].status2 = oldData.status2;
    }

    SwitchInClearSetData(battler);

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE
        && gBattleMons[battler].maxHP / 2 >= gBattleMons[battler].hp
        && IsBattlerAlive(battler)
        && !(gBattleMons[battler].status1 & STATUS1_SLEEP))
    {
        gBattleStruct->palaceFlags |= gBitTable[battler];
    }

    gBattleScripting.battler = battler;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, battler, gBattlerPartyIndexes[battler]);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_switchinanim(void)
{
    u32 battler;

    CMD_ARGS(u8 battler, bool8 dontClearSubstitute);

    if (gBattleControllerExecFlags)
        return;

    battler = GetBattlerForBattleScript(cmd->battler);

    if (GetBattlerSide(battler) == B_SIDE_OPPONENT
        && !(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                 | BATTLE_TYPE_EREADER_TRAINER
                                 | BATTLE_TYPE_RECORDED_LINK
                                 | BATTLE_TYPE_TRAINER_HILL
                                 | BATTLE_TYPE_FRONTIER)))
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[battler].species), FLAG_SET_SEEN, gBattleMons[battler].personality);

    gAbsentBattlerFlags &= ~(gBitTable[battler]);

    BtlController_EmitSwitchInAnim(battler, BUFFER_A, gBattlerPartyIndexes[battler], cmd->dontClearSubstitute);
    MarkBattlerForControllerExec(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        BattleArena_InitPoints();
}

bool32 CanBattlerSwitch(u32 battler)
{
    s32 i, lastMonId, battlerIn1, battlerIn2;
    bool32 ret = FALSE;
    struct Pokemon *party;

    if (BATTLE_TWO_VS_ONE_OPPONENT && GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        battlerIn1 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        battlerIn2 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        party = gEnemyParty;

        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && i != gBattlerPartyIndexes[battlerIn1] && i != gBattlerPartyIndexes[battlerIn2])
                break;
        }

        ret = (i != PARTY_SIZE);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        party = GetBattlerParty(battler);

        lastMonId = 0;
        if (battler & 2)
            lastMonId = MULTI_PARTY_SIZE;

        for (i = lastMonId; i < lastMonId + MULTI_PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0
             && gBattlerPartyIndexes[battler] != i)
                break;
        }

        ret = (i != lastMonId + MULTI_PARTY_SIZE);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
        {
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            {
                party = gPlayerParty;

                lastMonId = 0;
                if (GetLinkTrainerFlankId(GetBattlerMultiplayerId(battler)) == TRUE)
                    lastMonId = MULTI_PARTY_SIZE;
            }
            else
            {
                party = gEnemyParty;

                if (battler == 1)
                    lastMonId = 0;
                else
                    lastMonId = MULTI_PARTY_SIZE;
            }
        }
        else
        {
            party = GetBattlerParty(battler);

            lastMonId = 0;
            if (GetLinkTrainerFlankId(GetBattlerMultiplayerId(battler)) == TRUE)
                lastMonId = MULTI_PARTY_SIZE;
        }

        for (i = lastMonId; i < lastMonId + MULTI_PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0
             && gBattlerPartyIndexes[battler] != i)
                break;
        }

        ret = (i != lastMonId + MULTI_PARTY_SIZE);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        party = gEnemyParty;

        lastMonId = 0;
        if (battler == B_POSITION_OPPONENT_RIGHT)
            lastMonId = PARTY_SIZE / 2;

        for (i = lastMonId; i < lastMonId + (PARTY_SIZE / 2); i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0
             && gBattlerPartyIndexes[battler] != i)
                break;
        }

        ret = (i != lastMonId + (PARTY_SIZE / 2));
    }
    else
    {
        if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        {
            battlerIn1 = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);

            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                battlerIn2 = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            else
                battlerIn2 = battlerIn1;

            party = gEnemyParty;
        }
        else
        {
            // Check if attacker side has mon to switch into
            battlerIn1 = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                battlerIn2 = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            else
                battlerIn2 = battlerIn1;

            party = gPlayerParty;
        }

        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_HP) != 0
             && GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && i != gBattlerPartyIndexes[battlerIn1] && i != gBattlerPartyIndexes[battlerIn2])
                break;
        }

        ret = (i != PARTY_SIZE);
    }
    return ret;
}

static void Cmd_jumpifcantswitch(void)
{
    CMD_ARGS(u8 battler:7, u8 ignoreEscapePrevention:1, const u8 *jumpInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (!cmd->ignoreEscapePrevention && !CanBattlerEscape(battler))
    {
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
    {
        if (CanBattlerSwitch(battler))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
           gBattlescriptCurrInstr = cmd->jumpInstr;
    }
}

// Opens the party screen to choose a new Pokémon to send out.
// slotId is the Pokémon to replace.
// Note that this is not used by the Switch action, only replacing fainted Pokémon or Baton Pass
static void ChooseMonToSendOut(u32 battler, u8 slotId)
{
    gBattleStruct->battlerPartyIndexes[battler] = gBattlerPartyIndexes[battler];
    gBattleStruct->monToSwitchIntoId[battler] = PARTY_SIZE;
    gBattleStruct->field_93 &= ~(gBitTable[battler]);

    BtlController_EmitChoosePokemon(battler, BUFFER_A, PARTY_ACTION_SEND_OUT, slotId, ABILITY_NONE, gBattleStruct->battlerPartyOrders[battler]);
    MarkBattlerForControllerExec(battler);
}

static void Cmd_openpartyscreen(void)
{
    CMD_ARGS(u8 battler:7, u8 partyScreenOptional:1, const u8 *failInstr);

    u32 flags = 0;
    u8 hitmarkerFaintBits = 0;
    u32 i, battler = 0;
    const u8 *failInstr = cmd->failInstr;

    if (cmd->battler == BS_FAINTED_MULTIPLE_1)
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_MULTI) || !(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        {
            for (battler = 0; battler < gBattlersCount; battler++)
            {
                if (gHitMarker & HITMARKER_FAINTED(battler))
                {
                    if (HasNoMonsToSwitch(battler, PARTY_SIZE, PARTY_SIZE))
                    {
                        gAbsentBattlerFlags |= gBitTable[battler];
                        gHitMarker &= ~HITMARKER_FAINTED(battler);
                        BtlController_EmitLinkStandbyMsg(battler, BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                        MarkBattlerForControllerExec(battler);
                    }
                    else if (!gSpecialStatuses[battler].faintedHasReplacement)
                    {
                        ChooseMonToSendOut(battler, PARTY_SIZE);
                        gSpecialStatuses[battler].faintedHasReplacement = TRUE;
                    }
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(battler, BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(battler);
                }
            }
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            bool8 hasReplacement_0, hasReplacement_1, hasReplacement_2, hasReplacement_3;

            hitmarkerFaintBits = gHitMarker >> 28;

            if (gBitTable[0] & hitmarkerFaintBits)
            {
                battler = 0;
                if (HasNoMonsToSwitch(battler, PARTY_SIZE, PARTY_SIZE))
                {
                    gAbsentBattlerFlags |= gBitTable[battler];
                    gHitMarker &= ~HITMARKER_FAINTED(battler);
                    BtlController_EmitCantSwitch(battler, BUFFER_A);
                    MarkBattlerForControllerExec(battler);
                }
                else if (!gSpecialStatuses[battler].faintedHasReplacement)
                {
                    ChooseMonToSendOut(battler, gBattleStruct->monToSwitchIntoId[2]);
                    gSpecialStatuses[battler].faintedHasReplacement = TRUE;
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(battler, BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(battler);
                    flags |= 1;
                }
            }
            if (gBitTable[2] & hitmarkerFaintBits && !(gBitTable[0] & hitmarkerFaintBits))
            {
                battler = 2;
                if (HasNoMonsToSwitch(battler, PARTY_SIZE, PARTY_SIZE))
                {
                    gAbsentBattlerFlags |= gBitTable[battler];
                    gHitMarker &= ~HITMARKER_FAINTED(battler);
                    BtlController_EmitCantSwitch(battler, BUFFER_A);
                    MarkBattlerForControllerExec(battler);
                }
                else if (!gSpecialStatuses[battler].faintedHasReplacement)
                {
                    ChooseMonToSendOut(battler, gBattleStruct->monToSwitchIntoId[0]);
                    gSpecialStatuses[battler].faintedHasReplacement = TRUE;
                }
                else if (!(flags & 1))
                {
                    BtlController_EmitLinkStandbyMsg(battler, BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(battler);
                }
            }
            if (gBitTable[1] & hitmarkerFaintBits)
            {
                battler = 1;
                if (HasNoMonsToSwitch(battler, PARTY_SIZE, PARTY_SIZE))
                {
                    gAbsentBattlerFlags |= gBitTable[battler];
                    gHitMarker &= ~HITMARKER_FAINTED(battler);
                    BtlController_EmitCantSwitch(battler, BUFFER_A);
                    MarkBattlerForControllerExec(battler);
                }
                else if (!gSpecialStatuses[battler].faintedHasReplacement)
                {
                    ChooseMonToSendOut(battler, gBattleStruct->monToSwitchIntoId[3]);
                    gSpecialStatuses[battler].faintedHasReplacement = TRUE;
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(battler, BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(battler);
                    flags |= 2;
                }
            }
            if (gBitTable[3] & hitmarkerFaintBits && !(gBitTable[1] & hitmarkerFaintBits))
            {
                battler = 3;
                if (HasNoMonsToSwitch(battler, PARTY_SIZE, PARTY_SIZE))
                {
                    gAbsentBattlerFlags |= gBitTable[battler];
                    gHitMarker &= ~HITMARKER_FAINTED(battler);
                    BtlController_EmitCantSwitch(battler, BUFFER_A);
                    MarkBattlerForControllerExec(battler);
                }
                else if (!gSpecialStatuses[battler].faintedHasReplacement)
                {
                    ChooseMonToSendOut(battler, gBattleStruct->monToSwitchIntoId[1]);
                    gSpecialStatuses[battler].faintedHasReplacement = TRUE;
                }
                else if (!(flags & 2))
                {
                    BtlController_EmitLinkStandbyMsg(battler, BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(battler);
                }
            }

            hasReplacement_0 = gSpecialStatuses[0].faintedHasReplacement;
            if (!hasReplacement_0)
            {
                hasReplacement_2 = gSpecialStatuses[2].faintedHasReplacement;
                if (!hasReplacement_2 && hitmarkerFaintBits != 0)
                {
                    if (gAbsentBattlerFlags & gBitTable[0])
                        battler = 2;
                    else
                        battler = 0;

                    BtlController_EmitLinkStandbyMsg(battler, BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(battler);
                }

            }
            hasReplacement_1 = gSpecialStatuses[1].faintedHasReplacement;
            if (!hasReplacement_1)
            {
                hasReplacement_3 = gSpecialStatuses[3].faintedHasReplacement;
                if (!hasReplacement_3 && hitmarkerFaintBits != 0)
                {
                    if (gAbsentBattlerFlags & gBitTable[1])
                        battler = 3;
                    else
                        battler = 1;

                    BtlController_EmitLinkStandbyMsg(battler, BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(battler);
                }
            }
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (cmd->battler == BS_FAINTED_MULTIPLE_2)
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                hitmarkerFaintBits = gHitMarker >> 28;
                if (gBitTable[2] & hitmarkerFaintBits && gBitTable[0] & hitmarkerFaintBits)
                {
                    battler = 2;
                    if (HasNoMonsToSwitch(battler, gBattleResources->bufferB[0][1], PARTY_SIZE))
                    {
                        gAbsentBattlerFlags |= gBitTable[battler];
                        gHitMarker &= ~HITMARKER_FAINTED(battler);
                        BtlController_EmitCantSwitch(battler, BUFFER_A);
                        MarkBattlerForControllerExec(battler);
                    }
                    else if (!gSpecialStatuses[battler].faintedHasReplacement)
                    {
                        ChooseMonToSendOut(battler, gBattleStruct->monToSwitchIntoId[0]);
                        gSpecialStatuses[battler].faintedHasReplacement = TRUE;
                    }
                }
                if (gBitTable[3] & hitmarkerFaintBits && hitmarkerFaintBits & gBitTable[1])
                {
                    battler = 3;
                    if (HasNoMonsToSwitch(battler, gBattleResources->bufferB[1][1], PARTY_SIZE))
                    {
                        gAbsentBattlerFlags |= gBitTable[battler];
                        gHitMarker &= ~HITMARKER_FAINTED(battler);
                        BtlController_EmitCantSwitch(battler, BUFFER_A);
                        MarkBattlerForControllerExec(battler);
                    }
                    else if (!gSpecialStatuses[battler].faintedHasReplacement)
                    {
                        ChooseMonToSendOut(battler, gBattleStruct->monToSwitchIntoId[1]);
                        gSpecialStatuses[battler].faintedHasReplacement = TRUE;
                    }
                }
                gBattlescriptCurrInstr = cmd->nextInstr;
            }
            else
            {
                // Not multi or double battle
                gBattlescriptCurrInstr = cmd->nextInstr;
            }
        }
        else
        {
            // Multi battle
            gBattlescriptCurrInstr = cmd->nextInstr;
        }

        hitmarkerFaintBits = gHitMarker >> 28;

        gBattlerFainted = 0;
        while (!(gBitTable[gBattlerFainted] & hitmarkerFaintBits)
               && gBattlerFainted < gBattlersCount)
            gBattlerFainted++;

        if (gBattlerFainted == gBattlersCount)
            gBattlescriptCurrInstr = failInstr;
    }
    else
    {
        if (cmd->partyScreenOptional)
            hitmarkerFaintBits = PARTY_ACTION_CHOOSE_MON; // Used here as the caseId for the EmitChoose function.
        else
            hitmarkerFaintBits = PARTY_ACTION_SEND_OUT;

        battler = GetBattlerForBattleScript(cmd->battler);
        if (gSpecialStatuses[battler].faintedHasReplacement)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else if (HasNoMonsToSwitch(battler, PARTY_SIZE, PARTY_SIZE))
        {
            gAbsentBattlerFlags |= gBitTable[battler];
            gHitMarker &= ~HITMARKER_FAINTED(battler);
            gBattlescriptCurrInstr = failInstr;
        }
        else
        {
            *(gBattleStruct->battlerPartyIndexes + battler) = gBattlerPartyIndexes[battler];
            *(gBattleStruct->monToSwitchIntoId + battler) = PARTY_SIZE;
            gBattleStruct->field_93 &= ~(gBitTable[battler]);

            BtlController_EmitChoosePokemon(battler, BUFFER_A, hitmarkerFaintBits, *(gBattleStruct->monToSwitchIntoId + BATTLE_PARTNER(battler)), ABILITY_NONE, gBattleStruct->battlerPartyOrders[battler]);
            MarkBattlerForControllerExec(battler);

            gBattlescriptCurrInstr = cmd->nextInstr;

            if (GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT && gBattleResults.playerSwitchesCounter < 255)
                gBattleResults.playerSwitchesCounter++;

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                for (i = 0; i < gBattlersCount; i++)
                {
                    if (i != battler)
                    {
                        BtlController_EmitLinkStandbyMsg(i, BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                        MarkBattlerForControllerExec(i);
                    }
                }
            }
            else
            {
                u32 battlerOpposite = GetBattlerAtPosition(BATTLE_OPPOSITE(GetBattlerPosition(battler)));
                if (gAbsentBattlerFlags & gBitTable[battlerOpposite])
                    battlerOpposite ^= BIT_FLANK;

                // Make sure we're checking a valid battler. In edge case scenarios - battler could be absent and battlerOpposite would become a non-existent one softlocking the game.
                if (battlerOpposite < gBattlersCount)
                {
                    BtlController_EmitLinkStandbyMsg(battlerOpposite, BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(battlerOpposite);
                }
            }
        }
    }
}

static void Cmd_switchhandleorder(void)
{
    CMD_ARGS(u8 battler, u8 state);

    u32 battler, i;
    if (gBattleControllerExecFlags)
        return;

    battler = GetBattlerForBattleScript(cmd->battler);

    switch (cmd->state)
    {
    case 0:
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattleResources->bufferB[i][0] == CONTROLLER_CHOSENMONRETURNVALUE)
            {
                *(gBattleStruct->monToSwitchIntoId + i) = gBattleResources->bufferB[i][1];
                if (!(gBattleStruct->field_93 & gBitTable[i]))
                {
                    RecordedBattle_SetBattlerAction(i, gBattleResources->bufferB[i][1]);
                    gBattleStruct->field_93 |= gBitTable[i];
                }
            }
        }
        break;
    case 1:
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            SwitchPartyOrder(battler);
        break;
    case 2:
        if (!(gBattleStruct->field_93 & gBitTable[battler]))
        {
            RecordedBattle_SetBattlerAction(battler, gBattleResources->bufferB[battler][1]);
            gBattleStruct->field_93 |= gBitTable[battler];
        }
        // fall through
    case 3:
        gBattleCommunication[0] = gBattleResources->bufferB[battler][1];
        *(gBattleStruct->monToSwitchIntoId + battler) = gBattleResources->bufferB[battler][1];

        if (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            *(battler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) &= 0xF;
            *(battler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) |= (gBattleResources->bufferB[battler][2] & 0xF0);
            *(battler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 1) = gBattleResources->bufferB[battler][3];

            *((BATTLE_PARTNER(battler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) &= (0xF0);
            *((BATTLE_PARTNER(battler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) |= (gBattleResources->bufferB[battler][2] & 0xF0) >> 4;
            *((BATTLE_PARTNER(battler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 2) = gBattleResources->bufferB[battler][3];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            SwitchPartyOrderInGameMulti(battler, *(gBattleStruct->monToSwitchIntoId + battler));
        }
        else
        {
            SwitchPartyOrder(battler);
        }

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].species)
        PREPARE_MON_NICK_BUFFER(gBattleTextBuff2, battler, gBattleResources->bufferB[battler][1])
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void SetDmgHazardsBattlescript(u8 battler, u8 multistringId)
{
    gBattleMons[battler].status2 &= ~STATUS2_DESTINY_BOND;
    gHitMarker &= ~HITMARKER_DESTINYBOND;
    gBattleScripting.battler = battler;
    gBattleCommunication[MULTISTRING_CHOOSER] = multistringId;

    BattleScriptPushCursor();
    if (gBattlescriptCurrInstr[1] == BS_TARGET)
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnTarget;
    else if (gBattlescriptCurrInstr[1] == BS_ATTACKER)
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnAttacker;
    else if (gBattlescriptCurrInstr[1] == BS_SCRIPTING)
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnBattlerScripting;
    else
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnFaintedBattler;
}

bool32 DoSwitchInAbilities(u32 battler)
{
    return (TryPrimalReversion(battler)
         || AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, battler, 0, 0, 0)
         || (gBattleWeather & B_WEATHER_ANY && WEATHER_HAS_EFFECT && AbilityBattleEffects(ABILITYEFFECT_ON_WEATHER, battler, 0, 0, 0))
         || (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY && AbilityBattleEffects(ABILITYEFFECT_ON_TERRAIN, battler, 0, 0, 0)));
}

static void UpdateSentMonFlags(u32 battler)
{
    UpdateSentPokesToOpponentValue(battler);

    gHitMarker &= ~HITMARKER_FAINTED(battler);
    gSpecialStatuses[battler].faintedHasReplacement = FALSE;

    if (!BattlerHasAi(battler))
        gBattleStruct->appearedInBattle |= gBitTable[gBattlerPartyIndexes[battler]];
}

static bool32 DoSwitchInEffectsForBattler(u32 battler)
{
    u32 i = 0;
    // Neutralizing Gas announces itself before hazards
    if (gBattleMons[battler].ability == ABILITY_NEUTRALIZING_GAS && gSpecialStatuses[battler].announceNeutralizingGas == 0)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_NEUTRALIZING_GAS;
        gSpecialStatuses[battler].announceNeutralizingGas = TRUE;
        gBattlerAbility = battler;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SwitchInAbilityMsgRet;
    }
    // Healing Wish activates before hazards.
    // Starting from Gen8 - it heals only pokemon which can be healed. In gens 5,6,7 the effect activates anyways.
    else if (((gBattleStruct->storedHealingWish & gBitTable[battler]) || (gBattleStruct->storedLunarDance & gBitTable[battler]))
        && (gBattleMons[battler].hp != gBattleMons[battler].maxHP || gBattleMons[battler].status1 != 0 || B_HEALING_WISH_SWITCH < GEN_8))
    {
        if (gBattleStruct->storedHealingWish & gBitTable[battler])
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_HealingWishActivates;
            gBattleStruct->storedHealingWish  &= ~(gBitTable[battler]);
        }
        else // Lunar Dance
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_LunarDanceActivates;
            gBattleStruct->storedLunarDance  &= ~(gBitTable[battler]);
        }
    }
    else if (!(gDisableStructs[battler].spikesDone)
        && (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SPIKES)
        && GetBattlerAbility(battler) != ABILITY_MAGIC_GUARD
        && IsBattlerAffectedByHazards(battler, FALSE)
        && IsBattlerGrounded(battler))
    {
        u8 spikesDmg = (5 - gSideTimers[GetBattlerSide(battler)].spikesAmount) * 2;
        gBattleMoveDamage = GetNonDynamaxMaxHP(battler) / (spikesDmg);
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gDisableStructs[battler].spikesDone = TRUE;
        SetDmgHazardsBattlescript(battler, B_MSG_PKMNHURTBYSPIKES);
    }
    else if (!(gDisableStructs[battler].stealthRockDone)
        && (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_STEALTH_ROCK)
        && IsBattlerAffectedByHazards(battler, FALSE)
        && GetBattlerAbility(battler) != ABILITY_MAGIC_GUARD)
    {
        gDisableStructs[battler].stealthRockDone = TRUE;
        gBattleMoveDamage = GetStealthHazardDamage(gMovesInfo[MOVE_STEALTH_ROCK].type, battler);

        if (gBattleMoveDamage != 0)
            SetDmgHazardsBattlescript(battler, B_MSG_STEALTHROCKDMG);
    }
    else if (!(gDisableStructs[battler].toxicSpikesDone)
        && (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_TOXIC_SPIKES)
        && IsBattlerGrounded(battler))
    {
        gDisableStructs[battler].toxicSpikesDone = TRUE;
        if (IS_BATTLER_OF_TYPE(battler, TYPE_POISON)) // Absorb the toxic spikes.
        {
            gSideStatuses[GetBattlerSide(battler)] &= ~SIDE_STATUS_TOXIC_SPIKES;
            gSideTimers[GetBattlerSide(battler)].toxicSpikesAmount = 0;
            gBattleScripting.battler = battler;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_ToxicSpikesAbsorbed;
        }
        else if (IsBattlerAffectedByHazards(battler, TRUE))
        {
            i = GetBattlerAbility(battler);
            if (!(gBattleMons[battler].status1 & STATUS1_ANY)
                && !IS_BATTLER_OF_TYPE(battler, TYPE_STEEL)
                && i != ABILITY_IMMUNITY
                && i != ABILITY_PURIFYING_SALT
                && !IsAbilityOnSide(battler, ABILITY_PASTEL_VEIL)
                && !(gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_SAFEGUARD)
                && !(gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN))
            {
                if (gSideTimers[GetBattlerSide(battler)].toxicSpikesAmount >= 2)
                    gBattleMons[battler].status1 |= STATUS1_TOXIC_POISON;
                else
                    gBattleMons[battler].status1 |= STATUS1_POISON;

                BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[battler].status1), &gBattleMons[battler].status1);
                MarkBattlerForControllerExec(battler);
                gBattleScripting.battler = battler;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ToxicSpikesPoisoned;
            }
        }
    }
    else if (!(gDisableStructs[battler].stickyWebDone)
        && (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_STICKY_WEB)
        && IsBattlerAffectedByHazards(battler, FALSE)
        && IsBattlerGrounded(battler))
    {
        gDisableStructs[battler].stickyWebDone = TRUE;
        gBattleScripting.battler = battler;
        SET_STATCHANGER(STAT_SPEED, 1, TRUE);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_StickyWebOnSwitchIn;
    }
    else if (!(gDisableStructs[battler].steelSurgeDone)
        && (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_STEELSURGE)
        && IsBattlerAffectedByHazards(battler, FALSE)
        && GetBattlerAbility(battler) != ABILITY_MAGIC_GUARD)
    {
        gDisableStructs[battler].steelSurgeDone = TRUE;
        gBattleMoveDamage = GetStealthHazardDamage(gMovesInfo[MOVE_G_MAX_STEELSURGE].type, battler);

        if (gBattleMoveDamage != 0)
            SetDmgHazardsBattlescript(battler, B_MSG_SHARPSTEELDMG);
    }
    else if (gBattleMons[battler].hp != gBattleMons[battler].maxHP && gBattleStruct->zmove.healReplacement)
    {
        gBattleStruct->zmove.healReplacement = FALSE;
        gBattleMoveDamage = -1 * (gBattleMons[battler].maxHP);
        gBattleScripting.battler = battler;
        BattleScriptPushCursor();
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_HP_TRAP;
        gBattlescriptCurrInstr = BattleScript_HealReplacementZMove;
        return TRUE;
    }
    else
    {
        u32 battlerAbility = GetBattlerAbility(battler);
        // There is a hack here to ensure the truant counter will be 0 when the battler's next turn starts.
        // The truant counter is not updated in the case where a mon switches in after a lost judgment in the battle arena.
        if (battlerAbility == ABILITY_TRUANT
            && gCurrentActionFuncId != B_ACTION_USE_MOVE
            && !gDisableStructs[battler].truantSwitchInHack)
            gDisableStructs[battler].truantCounter = 1;

        gDisableStructs[battler].truantSwitchInHack = 0;

        if (DoSwitchInAbilities(battler) || ItemBattleEffects(ITEMEFFECT_ON_SWITCH_IN, battler, FALSE))
            return TRUE;
        else if (AbilityBattleEffects(ABILITYEFFECT_OPPORTUNIST, battler, 0, 0, 0))
            return TRUE;

        for (i = 0; i < gBattlersCount; i++)
        {
            if (i == battler)
                continue;

            switch (GetBattlerAbility(i))
            {
            case ABILITY_TRACE:
                if (AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, i, 0, 0, 0))
                    return TRUE;
                break;
            case ABILITY_FORECAST:
            case ABILITY_FLOWER_GIFT:
            case ABILITY_ICE_FACE:
            case ABILITY_PROTOSYNTHESIS:
                if (AbilityBattleEffects(ABILITYEFFECT_ON_WEATHER, i, 0, 0, 0))
                    return TRUE;
                break;
            }
        }

        gDisableStructs[battler].stickyWebDone = FALSE;
        gDisableStructs[battler].spikesDone = FALSE;
        gDisableStructs[battler].toxicSpikesDone = FALSE;
        gDisableStructs[battler].stealthRockDone = FALSE;
        gDisableStructs[battler].steelSurgeDone = FALSE;

        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == battler)
                gActionsByTurnOrder[i] = B_ACTION_CANCEL_PARTNER;

            gBattleStruct->hpOnSwitchout[GetBattlerSide(i)] = gBattleMons[i].hp;
        }

        gBattleStruct->forcedSwitch &= ~(gBitTable[battler]);
        return FALSE;
    }

    return TRUE; // Effect's script plays.
}

static void Cmd_switchineffects(void)
{
    CMD_ARGS(u8 battler);
    u32 i, battler = GetBattlerForBattleScript(cmd->battler);

    switch (cmd->battler)
    {
    // Multiple mons fainted and are being switched-in. Their abilities/hazards will play according to speed ties.
    case BS_FAINTED_MULTIPLE_1: // Saves the battlers.
        gBattleStruct->multipleSwitchInBattlers |= gBitTable[battler];
        UpdateSentMonFlags(battler);

        // Increment fainted battler.
        do
        {
            gBattlerFainted++;
            if (gBattlerFainted >= gBattlersCount)
                break;
            if (gHitMarker & HITMARKER_FAINTED(gBattlerFainted) && !(gAbsentBattlerFlags & gBitTable[gBattlerFainted]))
                break;
        } while (1);

        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    case BS_FAINTED_MULTIPLE_2: // Plays hazards/abilities.
        switch (gBattleStruct->multipleSwitchInState)
        {
        case 0: // Sort battlers by speed
            for (i = 0; i < gBattlersCount; i++)
                gBattleStruct->multipleSwitchInSortedBattlers[i] = i;
            SortBattlersBySpeed(gBattleStruct->multipleSwitchInSortedBattlers, FALSE);
            gBattleStruct->multipleSwitchInState++;
            gBattleStruct->multipleSwitchInCursor = 0;
            // Loop through all available battlers
        case 1:
            for (; gBattleStruct->multipleSwitchInCursor < gBattlersCount; gBattleStruct->multipleSwitchInCursor++)
            {
                gBattlerFainted = gBattleStruct->multipleSwitchInSortedBattlers[gBattleStruct->multipleSwitchInCursor];
                if (gBattleStruct->multipleSwitchInBattlers & gBitTable[gBattlerFainted])
                {
                    if (DoSwitchInEffectsForBattler(gBattlerFainted))
                        return;
                }
            }
            // All battlers done, end
            gBattleStruct->multipleSwitchInBattlers = 0;
            gBattleStruct->multipleSwitchInState = 0;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        break;
    default:
        UpdateSentMonFlags(battler);
        if (!DoSwitchInEffectsForBattler(battler))
            gBattlescriptCurrInstr = cmd->nextInstr;
        break;
    }
}

static void Cmd_trainerslidein(void)
{
    CMD_ARGS(u8 position);

    u32 battler = GetBattlerForBattleScript(cmd->position);
    BtlController_EmitTrainerSlide(battler, BUFFER_A);
    MarkBattlerForControllerExec(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_playse(void)
{
    CMD_ARGS(u16 song);

    BtlController_EmitPlaySE(gBattlerAttacker, BUFFER_A, cmd->song);
    MarkBattlerForControllerExec(gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_fanfare(void)
{
    CMD_ARGS(u16 song);

    BtlController_EmitPlayFanfareOrBGM(gBattlerAttacker, BUFFER_A, cmd->song, FALSE);
    MarkBattlerForControllerExec(gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_playfaintcry(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitFaintingCry(battler, BUFFER_A);
    MarkBattlerForControllerExec(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_endlinkbattle(void)
{
    CMD_ARGS();

    u32 battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
    BtlController_EmitEndLinkBattle(battler, BUFFER_A, gBattleOutcome);
    MarkBattlerForControllerExec(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_returntoball(void)
{
    CMD_ARGS(u8 battler, bool8 changingForm);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitReturnMonToBall(battler, BUFFER_A, TRUE);
    MarkBattlerForControllerExec(battler);

    // Don't always execute a form change here otherwise we can stomp gigantamax
    if(!cmd->changingForm)
        TryBattleFormChange(battler, FORM_CHANGE_BATTLE_SWITCH);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_handlelearnnewmove(void)
{
    CMD_ARGS(const u8 *learnedMovePtr, const u8 *nothingToLearnPtr, bool8 isFirstMove);

    u32 monId = gBattleStruct->expGetterMonId;
    u16 learnMove = MonTryLearningNewMove(&gPlayerParty[monId], cmd->isFirstMove);
    while (learnMove == MON_ALREADY_KNOWS_MOVE)
        learnMove = MonTryLearningNewMove(&gPlayerParty[monId], FALSE);

    if (learnMove == MOVE_NONE || RECORDED_WILD_BATTLE)
    {
        gBattlescriptCurrInstr = cmd->nothingToLearnPtr;
    }
    else if (learnMove == MON_HAS_MAX_MOVES)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        u32 battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

        if (gBattlerPartyIndexes[battler] == monId
            && !(gBattleMons[battler].status2 & STATUS2_TRANSFORMED))
        {
            GiveMoveToBattleMon(&gBattleMons[battler], learnMove);
        }
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            battler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            if (gBattlerPartyIndexes[battler] == monId
                && !(gBattleMons[battler].status2 & STATUS2_TRANSFORMED))
            {
                GiveMoveToBattleMon(&gBattleMons[battler], learnMove);
            }
        }

        gBattlescriptCurrInstr = cmd->learnedMovePtr;
    }
}

static void Cmd_yesnoboxlearnmove(void)
{
    CMD_ARGS(const u8 *forgotMovePtr);

    switch (gBattleScripting.learnMoveState)
    {
    case 0:
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gBattleScripting.learnMoveState++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateYesNoCursorAt(0);
        break;
    case 1:
        if (JOY_NEW(DPAD_UP) && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateYesNoCursorAt(0);
        }
        if (JOY_NEW(DPAD_DOWN) && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
        }
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[1] == 0)
            {
                HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gBattleScripting.learnMoveState++;
            }
            else
            {
                gBattleScripting.learnMoveState = 5;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBattleScripting.learnMoveState = 5;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            ShowSelectMovePokemonSummaryScreen(gPlayerParty, gBattleStruct->expGetterMonId, gPlayerPartyCount - 1, ReshowBattleScreenAfterMenu, gMoveToLearn);
            gBattleScripting.learnMoveState++;
        }
        break;
    case 3:
        if (!gPaletteFade.active && gMain.callback2 == BattleMainCB2)
        {
            gBattleScripting.learnMoveState++;
        }
        break;
    case 4:
        if (!gPaletteFade.active && gMain.callback2 == BattleMainCB2)
        {
            u8 movePosition = GetMoveSlotToReplace();
            if (movePosition == MAX_MON_MOVES)
            {
                gBattleScripting.learnMoveState = 5;
            }
            else
            {
                u16 moveId = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_MOVE1 + movePosition);
                if (IsMoveHM(moveId))
                {
                    PrepareStringBattle(STRINGID_HMMOVESCANTBEFORGOTTEN, B_POSITION_PLAYER_LEFT);
                    gBattleScripting.learnMoveState = 6;
                }
                else
                {
                    gBattlescriptCurrInstr = cmd->forgotMovePtr;

                    PREPARE_MOVE_BUFFER(gBattleTextBuff2, moveId)

                    RemoveMonPPBonus(&gPlayerParty[gBattleStruct->expGetterMonId], movePosition);
                    SetMonMoveSlot(&gPlayerParty[gBattleStruct->expGetterMonId], gMoveToLearn, movePosition);

                    if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterMonId && MOVE_IS_PERMANENT(0, movePosition))
                    {
                        RemoveBattleMonPPBonus(&gBattleMons[0], movePosition);
                        SetBattleMonMoveSlot(&gBattleMons[0], gMoveToLearn, movePosition);
                    }
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                        && gBattlerPartyIndexes[2] == gBattleStruct->expGetterMonId
                        && MOVE_IS_PERMANENT(2, movePosition))
                    {
                        RemoveBattleMonPPBonus(&gBattleMons[2], movePosition);
                        SetBattleMonMoveSlot(&gBattleMons[2], gMoveToLearn, movePosition);
                    }
                }
            }
        }
        break;
    case 5:
        HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        gBattlescriptCurrInstr = cmd->nextInstr;
        break;
    case 6:
        if (gBattleControllerExecFlags == 0)
        {
            gBattleScripting.learnMoveState = 2;
        }
        break;
    }
}

static void Cmd_yesnoboxstoplearningmove(void)
{
    CMD_ARGS(const u8 *noInstr);

    switch (gBattleScripting.learnMoveState)
    {
    case 0:
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gBattleScripting.learnMoveState++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateYesNoCursorAt(0);
        break;
    case 1:
        if (JOY_NEW(DPAD_UP) && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateYesNoCursorAt(0);
        }
        if (JOY_NEW(DPAD_DOWN) && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
        }
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);

            if (gBattleCommunication[1] != 0)
                gBattlescriptCurrInstr = cmd->noInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;

            HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBattlescriptCurrInstr = cmd->noInstr;
            HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
        }
        break;
    }
}

static void Cmd_hitanimation(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (!(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE) || !(DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove)) || gDisableStructs[battler].substituteHP == 0)
    {
        BtlController_EmitHitAnimation(battler, BUFFER_A);
        MarkBattlerForControllerExec(battler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static u32 GetTrainerMoneyToGive(u16 trainerId)
{
    u32 lastMonLevel = 0;
    u32 moneyReward;
    u8 trainerMoney = 0;

    if (trainerId == TRAINER_SECRET_BASE)
    {
        moneyReward = 20 * gBattleResources->secretBase->party.levels[0] * gBattleStruct->moneyMultiplier;
    }
    else
    {
        const struct TrainerMon *party = GetTrainerPartyFromId(trainerId);
        if (party == NULL)
            return 20;
        lastMonLevel = party[GetTrainerPartySizeFromId(trainerId) - 1].lvl;
        trainerMoney = gTrainerClasses[GetTrainerClassFromId(trainerId)].money;

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * trainerMoney;
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * 2 * trainerMoney;
        else
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * trainerMoney;
    }

    return moneyReward;
}

static void Cmd_getmoneyreward(void)
{
    CMD_ARGS();

    u32 money;
    u8 sPartyLevel = 1;

    if (gBattleOutcome == B_OUTCOME_WON)
    {
        money = GetTrainerMoneyToGive(gTrainerBattleOpponent_A);
        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            money += GetTrainerMoneyToGive(gTrainerBattleOpponent_B);
        AddMoney(&gSaveBlock1Ptr->money, money);
    }
    else
    {
        s32 i, count;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
             && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL) > sPartyLevel)
                    sPartyLevel = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            }
        }
        for (count = 0, i = 0; i < ARRAY_COUNT(sBadgeFlags); i++)
        {
            if (FlagGet(sBadgeFlags[i]) == TRUE)
                ++count;
        }
        money = sWhiteOutBadgeMoney[count] * sPartyLevel;
        RemoveMoney(&gSaveBlock1Ptr->money, money);
    }

    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff1, 5, money);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Command is never used
static void Cmd_updatebattlermoves(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);

    switch (gBattleCommunication[0])
    {
    case 0:
        BtlController_EmitGetMonData(battler, BUFFER_A, REQUEST_ALL_BATTLE, 0);
        MarkBattlerForControllerExec(battler);
        gBattleCommunication[0]++;
        break;
    case 1:
         if (gBattleControllerExecFlags == 0)
         {
            s32 i;
            struct BattlePokemon *bufferPoke = (struct BattlePokemon *) &gBattleResources->bufferB[battler][4];
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                gBattleMons[battler].moves[i] = bufferPoke->moves[i];
                gBattleMons[battler].pp[i] = bufferPoke->pp[i];
            }
            gBattlescriptCurrInstr = cmd->nextInstr;
         }
         break;
    }
}

static void Cmd_swapattackerwithtarget(void)
{
    CMD_ARGS();

    u8 temp;
    SWAP(gBattlerAttacker, gBattlerTarget, temp);

    if (gHitMarker & HITMARKER_SWAP_ATTACKER_TARGET)
        gHitMarker &= ~HITMARKER_SWAP_ATTACKER_TARGET;
    else
        gHitMarker |= HITMARKER_SWAP_ATTACKER_TARGET;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_incrementgamestat(void)
{
    CMD_ARGS(u8 stat);

    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        IncrementGameStat(cmd->stat);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_drawpartystatussummary(void)
{
    CMD_ARGS(u8 battler);

    u32 battler, i;
    struct Pokemon *party;
    struct HpAndStatus hpStatuses[PARTY_SIZE];

    if (gBattleControllerExecFlags)
        return;

    battler = GetBattlerForBattleScript(cmd->battler);
    party = GetBattlerParty(battler);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE
            || GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
        {
            hpStatuses[i].hp = 0xFFFF;
            hpStatuses[i].status = 0;
        }
        else
        {
            hpStatuses[i].hp = GetMonData(&party[i], MON_DATA_HP);
            hpStatuses[i].status = GetMonData(&party[i], MON_DATA_STATUS);
        }
    }

    BtlController_EmitDrawPartyStatusSummary(battler, BUFFER_A, hpStatuses, 1);
    MarkBattlerForControllerExec(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_hidepartystatussummary(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitHidePartyStatusSummary(battler, BUFFER_A);
    MarkBattlerForControllerExec(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumptocalledmove(void)
{
    CMD_ARGS(bool8 notChosenMove);

    if (cmd->notChosenMove)
        gCurrentMove = gCalledMove;
    else
        gChosenMove = gCurrentMove = gCalledMove;

    gBattlescriptCurrInstr = GET_MOVE_BATTLESCRIPT(gCurrentMove);
}

static void Cmd_statusanimation(void)
{
    CMD_ARGS(u8 battler);

    if (gBattleControllerExecFlags == 0)
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        if (!(gStatuses3[battler] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[battler].substituteHP == 0
            && !(gHitMarker & (HITMARKER_NO_ANIMATIONS | HITMARKER_DISABLE_ANIMATION)))
        {
            BtlController_EmitStatusAnimation(battler, BUFFER_A, FALSE, gBattleMons[battler].status1);
            MarkBattlerForControllerExec(battler);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_status2animation(void)
{
    CMD_ARGS(u8 battler, u32 status2);

    if (gBattleControllerExecFlags == 0)
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        u32 status2ToAnim = cmd->status2;
        if (!(gStatuses3[battler] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[battler].substituteHP == 0
            && !(gHitMarker & (HITMARKER_NO_ANIMATIONS | HITMARKER_DISABLE_ANIMATION)))
        {
            BtlController_EmitStatusAnimation(battler, BUFFER_A, TRUE, gBattleMons[battler].status2 & status2ToAnim);
            MarkBattlerForControllerExec(battler);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_chosenstatusanimation(void)
{
    CMD_ARGS(u8 battler, bool8 isStatus2, u32 status);

    if (gBattleControllerExecFlags == 0)
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        u32 wantedStatus = cmd->status;
        if (!(gStatuses3[battler] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[battler].substituteHP == 0
            && !(gHitMarker & (HITMARKER_NO_ANIMATIONS | HITMARKER_DISABLE_ANIMATION)))
        {
            BtlController_EmitStatusAnimation(battler, BUFFER_A, cmd->isStatus2, wantedStatus);
            MarkBattlerForControllerExec(battler);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_yesnobox(void)
{
    CMD_ARGS();

    switch (gBattleCommunication[0])
    {
    case 0:
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gBattleCommunication[0]++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateYesNoCursorAt(0);
        break;
    case 1:
        if (JOY_NEW(DPAD_UP) && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateYesNoCursorAt(0);
        }
        if (JOY_NEW(DPAD_DOWN) && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
        }
        if (JOY_NEW(B_BUTTON))
        {
            gBattleCommunication[CURSOR_POSITION] = 1;
            PlaySE(SE_SELECT);
            HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        break;
    }
}

static void Cmd_cancelallactions(void)
{
    CMD_ARGS();

    s32 i;

    for (i = 0; i < gBattlersCount; i++)
        gActionsByTurnOrder[i] = B_ACTION_CANCEL_PARTNER;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setgravity(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gFieldStatuses & STATUS_FIELD_GRAVITY)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gFieldStatuses |= STATUS_FIELD_GRAVITY;
        gFieldTimers.gravityTimer = 5;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static bool32 TryCheekPouch(u32 battler, u32 itemId)
{
    if (ItemId_GetPocket(itemId) == POCKET_BERRIES
        && GetBattlerAbility(battler) == ABILITY_CHEEK_POUCH
        && !(gStatuses3[battler] & STATUS3_HEAL_BLOCK)
        && gBattleStruct->ateBerry[GetBattlerSide(battler)] & gBitTable[gBattlerPartyIndexes[battler]]
        && !BATTLER_MAX_HP(battler))
    {
        gBattleMoveDamage = GetNonDynamaxMaxHP(battler) / 3;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;
        gBattlerAbility = battler;
        BattleScriptPush(gBattlescriptCurrInstr + 2);
        gBattlescriptCurrInstr = BattleScript_CheekPouchActivates;
        return TRUE;
    }
    return FALSE;
}

// Used by Bestow and Symbiosis to take an item from one battler and give to another.
static void BestowItem(u32 battlerAtk, u32 battlerDef)
{
    gLastUsedItem = gBattleMons[battlerAtk].item;

    gBattleMons[battlerAtk].item = ITEM_NONE;
    BtlController_EmitSetMonData(battlerAtk, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battlerAtk].item), &gBattleMons[battlerAtk].item);
    MarkBattlerForControllerExec(battlerAtk);
    CheckSetUnburden(battlerAtk);

    gBattleMons[battlerDef].item = gLastUsedItem;
    BtlController_EmitSetMonData(battlerDef, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battlerDef].item), &gBattleMons[battlerDef].item);
    MarkBattlerForControllerExec(battlerDef);
    gBattleResources->flags->flags[battlerDef] &= ~RESOURCE_FLAG_UNBURDEN;
}

// Called by Cmd_removeitem. itemId represents the item that was removed, not being given.
static bool32 TrySymbiosis(u32 battler, u32 itemId)
{
    if (!gBattleStruct->itemLost[B_SIDE_PLAYER][gBattlerPartyIndexes[battler]].stolen
        && gBattleStruct->changedItems[battler] == ITEM_NONE
        && GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_EJECT_BUTTON
        && GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_EJECT_PACK
        && (B_SYMBIOSIS_GEMS < GEN_7 || !(gSpecialStatuses[battler].gemBoost))
        && gCurrentMove != MOVE_FLING //Fling and damage-reducing berries are handled separately.
        && !gSpecialStatuses[battler].berryReduced
        && SYMBIOSIS_CHECK(battler, BATTLE_PARTNER(battler)))
    {
        BestowItem(BATTLE_PARTNER(battler), battler);
        gLastUsedAbility = gBattleMons[BATTLE_PARTNER(battler)].ability;
        gBattleScripting.battler = gBattlerAbility = BATTLE_PARTNER(battler);
        gBattlerAttacker = battler;
        BattleScriptPush(gBattlescriptCurrInstr + 2);
        gBattlescriptCurrInstr = BattleScript_SymbiosisActivates;
        return TRUE;
    }
    return FALSE;
}

static void Cmd_removeitem(void)
{
    CMD_ARGS(u8 battler);

    u32 battler;
    u16 itemId = 0;

    if (gBattleScripting.overrideBerryRequirements)
    {
        // bug bite / pluck - don't remove current item
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }

    battler = GetBattlerForBattleScript(cmd->battler);
    itemId = gBattleMons[battler].item;

    // Popped Air Balloon cannot be restored by any means.
    // Corroded items cannot be restored either.
    if (GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_AIR_BALLOON
        && gMovesInfo[gCurrentMove].effect != EFFECT_CORROSIVE_GAS)
        gBattleStruct->usedHeldItems[gBattlerPartyIndexes[battler]][GetBattlerSide(battler)] = itemId; // Remember if switched out

    gBattleMons[battler].item = ITEM_NONE;
    gBattleStruct->canPickupItem |= (1u << battler);
    CheckSetUnburden(battler);

    BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battler].item), &gBattleMons[battler].item);
    MarkBattlerForControllerExec(battler);

    ClearBattlerItemEffectHistory(battler);
    if (!TryCheekPouch(battler, itemId) && !TrySymbiosis(battler, itemId))
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_atknameinbuff1(void)
{
    CMD_ARGS();

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker]);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_drawlvlupbox(void)
{
    CMD_ARGS();

    if (gBattleScripting.drawlvlupboxState == 0)
    {
        // If the Pokémon getting exp is not in-battle then
        // slide out a banner with their name and icon on it.
        // Otherwise skip ahead.
        if (IsMonGettingExpSentOut())
            gBattleScripting.drawlvlupboxState = 3;
        else
            gBattleScripting.drawlvlupboxState = 1;
    }

    switch (gBattleScripting.drawlvlupboxState)
    {
    case 1:
        // Start level up banner
        gBattle_BG2_Y = 96;
        SetBgAttribute(2, BG_ATTR_PRIORITY, 0);
        ShowBg(2);
        InitLevelUpBanner();
        gBattleScripting.drawlvlupboxState = 2;
        break;
    case 2:
        if (!SlideInLevelUpBanner())
            gBattleScripting.drawlvlupboxState = 3;
        break;
    case 3:
        // Init level up box
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 256;
        SetBgAttribute(0, BG_ATTR_PRIORITY, 1);
        SetBgAttribute(1, BG_ATTR_PRIORITY, 0);
        ShowBg(0);
        ShowBg(1);
        HandleBattleWindow(18, 7, 29, 19, WINDOW_BG1);
        gBattleScripting.drawlvlupboxState = 4;
        break;
    case 4:
        // Draw page 1 of level up box
        DrawLevelUpWindow1();
        PutWindowTilemap(B_WIN_LEVEL_UP_BOX);
        CopyWindowToVram(B_WIN_LEVEL_UP_BOX, COPYWIN_FULL);
        gBattleScripting.drawlvlupboxState++;
        break;
    case 5:
    case 7:
        // Wait for draw after each page
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            gBattle_BG1_Y = 0;
            gBattleScripting.drawlvlupboxState++;
        }
        break;
    case 6:
        if (gMain.newKeys != 0 || RECORDED_WILD_BATTLE)
        {
            // Draw page 2 of level up box
            PlaySE(SE_SELECT);
            DrawLevelUpWindow2();
            CopyWindowToVram(B_WIN_LEVEL_UP_BOX, COPYWIN_GFX);
            gBattleScripting.drawlvlupboxState++;
        }
        break;
    case 8:
        if (gMain.newKeys != 0 || RECORDED_WILD_BATTLE)
        {
            // Close level up box
            PlaySE(SE_SELECT);
            HandleBattleWindow(18, 7, 29, 19, WINDOW_BG1 | WINDOW_CLEAR);
            gBattleScripting.drawlvlupboxState++;
        }
        break;
    case 9:
        if (!SlideOutLevelUpBanner())
        {
            ClearWindowTilemap(B_WIN_LEVEL_UP_BANNER);
            CopyWindowToVram(B_WIN_LEVEL_UP_BANNER, COPYWIN_MAP);

            ClearWindowTilemap(B_WIN_LEVEL_UP_BOX);
            CopyWindowToVram(B_WIN_LEVEL_UP_BOX, COPYWIN_MAP);

            SetBgAttribute(2, BG_ATTR_PRIORITY, 2);
            ShowBg(2);

            gBattleScripting.drawlvlupboxState = 10;
        }
        break;
    case 10:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetBgAttribute(0, BG_ATTR_PRIORITY, 0);
            SetBgAttribute(1, BG_ATTR_PRIORITY, 1);
            ShowBg(0);
            ShowBg(1);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        break;
    }
}

static void DrawLevelUpWindow1(void)
{
    u16 currStats[NUM_STATS];

    GetMonLevelUpWindowStats(&gPlayerParty[gBattleStruct->expGetterMonId], currStats);
    DrawLevelUpWindowPg1(B_WIN_LEVEL_UP_BOX, gBattleResources->beforeLvlUp->stats, currStats, TEXT_DYNAMIC_COLOR_5, TEXT_DYNAMIC_COLOR_4, TEXT_DYNAMIC_COLOR_6);
}

static void DrawLevelUpWindow2(void)
{
    u16 currStats[NUM_STATS];

    GetMonLevelUpWindowStats(&gPlayerParty[gBattleStruct->expGetterMonId], currStats);
    DrawLevelUpWindowPg2(B_WIN_LEVEL_UP_BOX, currStats, TEXT_DYNAMIC_COLOR_5, TEXT_DYNAMIC_COLOR_4, TEXT_DYNAMIC_COLOR_6);
}

static void InitLevelUpBanner(void)
{
    gBattle_BG2_Y = 0;
    gBattle_BG2_X = LEVEL_UP_BANNER_START;

    LoadPalette(sLevelUpBanner_Pal, BG_PLTT_ID(6), sizeof(sLevelUpBanner_Pal));
    CopyToWindowPixelBuffer(B_WIN_LEVEL_UP_BANNER, sLevelUpBanner_Gfx, 0, 0);
    PutWindowTilemap(B_WIN_LEVEL_UP_BANNER);
    CopyWindowToVram(B_WIN_LEVEL_UP_BANNER, COPYWIN_FULL);

    PutMonIconOnLvlUpBanner();
}

static bool8 SlideInLevelUpBanner(void)
{
    if (IsDma3ManagerBusyWithBgCopy())
        return TRUE;

    if (gBattle_BG2_X == LEVEL_UP_BANNER_END)
        return FALSE;

    if (gBattle_BG2_X == LEVEL_UP_BANNER_START)
        DrawLevelUpBannerText();

    gBattle_BG2_X += 8;
    if (gBattle_BG2_X >= LEVEL_UP_BANNER_END)
        gBattle_BG2_X = LEVEL_UP_BANNER_END;

    return (gBattle_BG2_X != LEVEL_UP_BANNER_END);
}

static void DrawLevelUpBannerText(void)
{
    struct TextPrinterTemplate printerTemplate;
    u8 *txtPtr;
    u32 var;

    struct Pokemon *mon = &gPlayerParty[gBattleStruct->expGetterMonId];
    u32 monLevel = GetMonData(mon, MON_DATA_LEVEL);
    u8 monGender = GetMonGender(mon);
    GetMonNickname(mon, gStringVar4);

    printerTemplate.currentChar = gStringVar4;
    printerTemplate.windowId = B_WIN_LEVEL_UP_BANNER;
    printerTemplate.fontId = FONT_SMALL;
    printerTemplate.x = 32;
    printerTemplate.y = 0;
    printerTemplate.currentX = 32;
    printerTemplate.currentY = 0;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = TEXT_COLOR_WHITE;
    printerTemplate.bgColor = TEXT_COLOR_TRANSPARENT;
    printerTemplate.shadowColor = TEXT_COLOR_DARK_GRAY;

    AddTextPrinter(&printerTemplate, TEXT_SKIP_DRAW, NULL);

    txtPtr = gStringVar4;
    *(txtPtr)++ = CHAR_EXTRA_SYMBOL;
    *(txtPtr)++ = CHAR_LV_2;

    var = (u32)(txtPtr);
    txtPtr = ConvertIntToDecimalStringN(txtPtr, monLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
    var = (u32)(txtPtr) - var;
    txtPtr = StringFill(txtPtr, CHAR_SPACER, 4 - var);

    if (monGender != MON_GENDERLESS)
    {
        if (monGender == MON_MALE)
        {
            txtPtr = WriteColorChangeControlCode(txtPtr, 0, TEXT_DYNAMIC_COLOR_3);
            txtPtr = WriteColorChangeControlCode(txtPtr, 1, TEXT_DYNAMIC_COLOR_4);
            *(txtPtr++) = CHAR_MALE;
        }
        else
        {
            txtPtr = WriteColorChangeControlCode(txtPtr, 0, TEXT_DYNAMIC_COLOR_5);
            txtPtr = WriteColorChangeControlCode(txtPtr, 1, TEXT_DYNAMIC_COLOR_6);
            *(txtPtr++) = CHAR_FEMALE;
        }
        *(txtPtr++) = EOS;
    }

    printerTemplate.y = 10;
    printerTemplate.currentY = 10;
    AddTextPrinter(&printerTemplate, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(B_WIN_LEVEL_UP_BANNER, COPYWIN_GFX);
}

static bool8 SlideOutLevelUpBanner(void)
{
    if (gBattle_BG2_X == LEVEL_UP_BANNER_START)
        return FALSE;

    if (gBattle_BG2_X - 16 < LEVEL_UP_BANNER_START)
        gBattle_BG2_X = LEVEL_UP_BANNER_START;
    else
        gBattle_BG2_X -= 16;

    return (gBattle_BG2_X != LEVEL_UP_BANNER_START);
}

#define sDestroy data[0]
#define sXOffset data[1]

static void PutMonIconOnLvlUpBanner(void)
{
    u8 spriteId;
    struct SpriteSheet iconSheet;
    struct SpritePalette iconPalSheet;

    struct Pokemon *mon = &gPlayerParty[gBattleStruct->expGetterMonId];
    u32 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);

    iconSheet.data = GetMonIconPtr(species, personality);
    iconSheet.size = 0x200;
    iconSheet.tag = TAG_LVLUP_BANNER_MON_ICON;

    iconPalSheet.data = GetValidMonIconPalettePtr(species);
    iconPalSheet.tag = TAG_LVLUP_BANNER_MON_ICON;

    LoadSpriteSheet(&iconSheet);
    LoadSpritePalette(&iconPalSheet);

    spriteId = CreateSprite(&sSpriteTemplate_MonIconOnLvlUpBanner, 256, 10, 0);
    gSprites[spriteId].sDestroy = FALSE;
    gSprites[spriteId].sXOffset = gBattle_BG2_X;
}

static void SpriteCB_MonIconOnLvlUpBanner(struct Sprite *sprite)
{
    sprite->x2 = sprite->sXOffset - gBattle_BG2_X;

    if (sprite->x2 != 0)
    {
        sprite->sDestroy = TRUE;
    }
    else if (sprite->sDestroy)
    {
        DestroySprite(sprite);
        FreeSpriteTilesByTag(TAG_LVLUP_BANNER_MON_ICON);
        FreeSpritePaletteByTag(TAG_LVLUP_BANNER_MON_ICON);
    }
}

#undef sDestroy
#undef sXOffset

static bool32 IsMonGettingExpSentOut(void)
{
    if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterMonId)
        return TRUE;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && gBattlerPartyIndexes[2] == gBattleStruct->expGetterMonId)
        return TRUE;

    return FALSE;
}

static void Cmd_resetsentmonsvalue(void)
{
    CMD_ARGS();

    ResetSentPokesToOpponentValue();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setatktoplayer0(void)
{
    CMD_ARGS();

    gBattlerAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_makevisible(void)
{
    CMD_ARGS(u8 battler);
    u32 battler;

    if (gBattleControllerExecFlags)
        return;

    battler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitSpriteInvisibility(battler, BUFFER_A, FALSE);
    MarkBattlerForControllerExec(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_recordability(void)
{
    CMD_ARGS(u8 battler);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    RecordAbilityBattle(battler, gBattleMons[battler].ability);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BufferMoveToLearnIntoBattleTextBuff2(void)
{
    PREPARE_MOVE_BUFFER(gBattleTextBuff2, gMoveToLearn);
}

static void Cmd_buffermovetolearn(void)
{
    CMD_ARGS();

    BufferMoveToLearnIntoBattleTextBuff2();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifplayerran(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (TryRunFromBattle(gBattlerFainted))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_hpthresholds(void)
{
    CMD_ARGS(u8 battler);

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        u32 opposingBattler = BATTLE_OPPOSITE(battler);

        s32 result = gBattleMons[opposingBattler].hp * 100 / gBattleMons[opposingBattler].maxHP;
        if (result == 0)
            result = 1;

        if (result > 69 || !IsBattlerAlive(opposingBattler))
            gBattleStruct->hpScale = 0;
        else if (result > 39)
            gBattleStruct->hpScale = 1;
        else if (result > 9)
            gBattleStruct->hpScale = 2;
        else
            gBattleStruct->hpScale = 3;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_hpthresholds2(void)
{
    CMD_ARGS(u8 battler);

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        u32 battler = GetBattlerForBattleScript(cmd->battler);
        u32 opposingBattler = BATTLE_OPPOSITE(battler);
        u8 hpSwitchout = *(gBattleStruct->hpOnSwitchout + GetBattlerSide(opposingBattler));
        s32 result = (hpSwitchout - gBattleMons[opposingBattler].hp) * 100 / hpSwitchout;

        if (gBattleMons[opposingBattler].hp >= hpSwitchout)
            gBattleStruct->hpScale = 0;
        else if (result <= 29)
            gBattleStruct->hpScale = 1;
        else if (result <= 69)
            gBattleStruct->hpScale = 2;
        else
            gBattleStruct->hpScale = 3;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_useitemonopponent(void)
{
    CMD_ARGS();

    gBattlerInMenuId = gBattlerAttacker;
    PokemonUseItemEffects(&gEnemyParty[gBattlerPartyIndexes[gBattlerAttacker]], gLastUsedItem, gBattlerPartyIndexes[gBattlerAttacker], 0, TRUE);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static bool32 HasAttackerFaintedTarget(void)
{
    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        && gMovesInfo[gCurrentMove].power != 0
        && (gLastHitBy[gBattlerTarget] == 0xFF || gLastHitBy[gBattlerTarget] == gBattlerAttacker)
        && gBattleStruct->moveTarget[gBattlerAttacker] == gBattlerTarget
        && gBattlerTarget != gBattlerAttacker
        && gCurrentTurnActionNumber == GetBattlerTurnOrderNum(gBattlerAttacker)
        && (gChosenMove == gChosenMoveByBattler[gBattlerAttacker] || gChosenMove == gBattleMons[gBattlerAttacker].moves[gChosenMovePos] || gChosenMove == GetMaxMove(gBattlerAttacker, gChosenMoveByBattler[gBattlerAttacker])))
        return TRUE;
    else
        return FALSE;
}

bool32 CanPoisonType(u8 battlerAttacker, u8 battlerTarget)
{
    return GetBattlerAbility(battlerAttacker) == ABILITY_CORROSION
        || (!IS_BATTLER_OF_TYPE(battlerTarget, TYPE_STEEL) && !IS_BATTLER_OF_TYPE(battlerTarget, TYPE_POISON));
}

bool32 CanParalyzeType(u8 battlerAttacker, u8 battlerTarget)
{
    return !(B_PARALYZE_ELECTRIC >= GEN_6 && IS_BATTLER_OF_TYPE(battlerTarget, TYPE_ELECTRIC));
}

bool32 CanUseLastResort(u8 battler)
{
    u32 i;
    u32 knownMovesCount = 0, usedMovesCount = 0;

    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[battler].moves[i] != MOVE_NONE)
            knownMovesCount++;
        if (i != gCurrMovePos && gDisableStructs[battler].usedMoves & gBitTable[i]) // Increment used move count for all moves except current Last Resort.
            usedMovesCount++;
    }

    return (knownMovesCount >= 2 && usedMovesCount >= knownMovesCount - 1);
}

static void RemoveAllWeather(void)
{
    gWishFutureKnock.weatherDuration = 0;

    if (gBattleWeather & B_WEATHER_RAIN)
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_END_RAIN;
    else if(gBattleWeather & B_WEATHER_SANDSTORM)
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_END_SANDSTORM;
    else if(gBattleWeather & B_WEATHER_SUN)
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_END_SUN;
    else if(gBattleWeather & B_WEATHER_HAIL)
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_END_HAIL;
    else if(gBattleWeather & B_WEATHER_STRONG_WINDS)
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_END_STRONG_WINDS;
    else if(gBattleWeather & B_WEATHER_SNOW)
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_END_SNOW;
    else if(gBattleWeather & B_WEATHER_FOG)
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_END_FOG;
    else
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_END_COUNT;  // failsafe

    gBattleWeather = 0;    // remove the weather
}

static void RemoveAllTerrains(void)
{
    gFieldTimers.terrainTimer = 0;
    switch (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
    {
    case STATUS_FIELD_MISTY_TERRAIN:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_END_MISTY;
        break;
    case STATUS_FIELD_GRASSY_TERRAIN:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_END_GRASSY;
        break;
    case STATUS_FIELD_ELECTRIC_TERRAIN:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_END_ELECTRIC;
        break;
    case STATUS_FIELD_PSYCHIC_TERRAIN:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_END_PSYCHIC;
        break;
    default:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_COUNT;  // failsafe
        break;
    }
    gFieldStatuses &= ~STATUS_FIELD_TERRAIN_ANY;    // remove the terrain
}

#define DEFOG_CLEAR(status, structField, battlescript, move)\
{                                                           \
    if (*sideStatuses & status)                             \
    {                                                       \
        if (clear)                                          \
        {                                                   \
            if (move)                                       \
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, move);\
            *sideStatuses &= ~status;                       \
            sideTimer->structField = 0;                     \
            BattleScriptPushCursor();                       \
            gBattlescriptCurrInstr = battlescript;          \
        }                                                   \
        return TRUE;                                        \
    }                                                       \
}

static bool32 TryDefogClear(u32 battlerAtk, bool32 clear)
{
    s32 i;
    u8 saveBattler = gBattlerAttacker;

    for (i = 0; i < 2; i++)
    {
        struct SideTimer *sideTimer = &gSideTimers[i];
        u32 *sideStatuses = &gSideStatuses[i];

        gBattlerAttacker = i; // For correct battle string. Ally's / Foe's
        if (GetBattlerSide(battlerAtk) != i)
        {
            DEFOG_CLEAR(SIDE_STATUS_REFLECT, reflectTimer, BattleScript_SideStatusWoreOffReturn, MOVE_REFLECT);
            DEFOG_CLEAR(SIDE_STATUS_LIGHTSCREEN, lightscreenTimer, BattleScript_SideStatusWoreOffReturn, MOVE_LIGHT_SCREEN);
            DEFOG_CLEAR(SIDE_STATUS_MIST, mistTimer, BattleScript_SideStatusWoreOffReturn, MOVE_MIST);
            DEFOG_CLEAR(SIDE_STATUS_AURORA_VEIL, auroraVeilTimer, BattleScript_SideStatusWoreOffReturn, MOVE_AURORA_VEIL);
            DEFOG_CLEAR(SIDE_STATUS_SAFEGUARD, safeguardTimer, BattleScript_SideStatusWoreOffReturn, MOVE_SAFEGUARD);
        }
        DEFOG_CLEAR(SIDE_STATUS_SPIKES, spikesAmount, BattleScript_SpikesDefog, 0);
        DEFOG_CLEAR(SIDE_STATUS_STEALTH_ROCK, stealthRockAmount, BattleScript_StealthRockDefog, 0);
        DEFOG_CLEAR(SIDE_STATUS_TOXIC_SPIKES, toxicSpikesAmount, BattleScript_ToxicSpikesDefog, 0);
        DEFOG_CLEAR(SIDE_STATUS_STICKY_WEB, stickyWebAmount, BattleScript_StickyWebDefog, 0);
        DEFOG_CLEAR(SIDE_STATUS_STEELSURGE, steelsurgeAmount, BattleScript_SteelsurgeDefog, 0);
        if (gBattleWeather & B_WEATHER_FOG)
        {
            gBattleWeather &= ~B_WEATHER_FOG;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_FogEnded_Ret;
            return TRUE;
        }
        if (B_DEFOG_CLEARS_TERRAIN >= GEN_8 && (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY))
        {
            RemoveAllTerrains();
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_TerrainEnds_Ret;
            return TRUE;
        }
    }

    gBattlerAttacker = saveBattler;

    return FALSE;
}

static bool32 TryTidyUpClear(u32 battlerAtk, bool32 clear)
{
    s32 i;
    u8 saveBattler = gBattlerAttacker;

    for (i = 0; i < NUM_BATTLE_SIDES; i++)
    {
        struct SideTimer *sideTimer = &gSideTimers[i];
        u32 *sideStatuses = &gSideStatuses[i];

        gBattlerAttacker = i; // For correct battle string. Ally's / Foe's
        DEFOG_CLEAR(SIDE_STATUS_SPIKES, spikesAmount, BattleScript_SpikesDefog, 0);
        DEFOG_CLEAR(SIDE_STATUS_STEALTH_ROCK, stealthRockAmount, BattleScript_StealthRockDefog, 0);
        DEFOG_CLEAR(SIDE_STATUS_TOXIC_SPIKES, toxicSpikesAmount, BattleScript_ToxicSpikesDefog, 0);
        DEFOG_CLEAR(SIDE_STATUS_STICKY_WEB, stickyWebAmount, BattleScript_StickyWebDefog, 0);
    }

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (gBattleMons[i].status2 & STATUS2_SUBSTITUTE)
        {
            if (clear)
            {
                gBattlerTarget = i;
                gDisableStructs[i].substituteHP = 0;
                gBattleMons[i].status2 &= ~STATUS2_SUBSTITUTE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SubstituteFade;
            }
            gBattlerAttacker = saveBattler;
            return TRUE;
        }
    }

    gBattlerAttacker = saveBattler;
    return FALSE;
}

u32 IsFlowerVeilProtected(u32 battler)
{
    if (IS_BATTLER_OF_TYPE(battler, TYPE_GRASS))
        return IsAbilityOnSide(battler, ABILITY_FLOWER_VEIL);
    else
        return 0;
}

u32 IsLeafGuardProtected(u32 battler)
{
    if (IsBattlerWeatherAffected(battler, B_WEATHER_SUN))
        return GetBattlerAbility(battler) == ABILITY_LEAF_GUARD;
    else
        return 0;
}

bool32 IsShieldsDownProtected(u32 battler)
{
    return (GetBattlerAbility(battler) == ABILITY_SHIELDS_DOWN
            && GetFormIdFromFormSpeciesId(gBattleMons[battler].species) < GetFormIdFromFormSpeciesId(SPECIES_MINIOR_CORE_RED)); // Minior is not in core form
}

u32 IsAbilityStatusProtected(u32 battler)
{
    return IsFlowerVeilProtected(battler)
        || IsLeafGuardProtected(battler)
        || IsShieldsDownProtected(battler);
}

u32 GetHighestStatId(u32 battler)
{
    u32 i, highestId = STAT_ATK, highestStat = gBattleMons[battler].attack;

    for (i = STAT_DEF; i < NUM_STATS; i++)
    {
        u16 *statVal = &gBattleMons[battler].attack + (i - 1);
        if (*statVal > highestStat)
        {
            highestStat = *statVal;
            highestId = i;
        }
    }
    return highestId;
}

static bool32 IsRototillerAffected(u32 battler)
{
    if (!IsBattlerAlive(battler))
        return FALSE;
    if (!IsBattlerGrounded(battler))
        return FALSE;   // Only grounded battlers affected
    if (!IS_BATTLER_OF_TYPE(battler, TYPE_GRASS))
        return FALSE;   // Only grass types affected
    if (gStatuses3[battler] & STATUS3_SEMI_INVULNERABLE)
        return FALSE;   // Rototiller doesn't affected semi-invulnerable battlers
    if (BlocksPrankster(MOVE_ROTOTILLER, gBattlerAttacker, battler, FALSE))
        return FALSE;
    return TRUE;
}

static bool32 IsElectricAbilityAffected(u32 battler, u32 ability)
{
    u32 moveType;

    if (gBattleStruct->dynamicMoveType == 0)
        moveType = gMovesInfo[gCurrentMove].type;
    else if (!(gBattleStruct->dynamicMoveType & F_DYNAMIC_TYPE_IGNORE_PHYSICALITY))
        moveType = gBattleStruct->dynamicMoveType & DYNAMIC_TYPE_MASK;
    else
        moveType = gMovesInfo[gCurrentMove].type;

    if (moveType == TYPE_ELECTRIC
     && (ability != ABILITY_LIGHTNING_ROD || B_REDIRECT_ABILITY_IMMUNITY >= GEN_5)
     && GetBattlerAbility(battler) == ability)
        return TRUE;
    else
        return FALSE;
}

static bool32 IsTeatimeAffected(u32 battler)
{
    if (ItemId_GetPocket(gBattleMons[battler].item) != POCKET_BERRIES)
        return FALSE;   // Only berries
    if (gStatuses3[battler] & STATUS3_SEMI_INVULNERABLE)
        return FALSE;   // Teatime doesn't affected semi-invulnerable battlers
    return TRUE;
}

#define COURTCHANGE_SWAP(status, structField, temp)                     \
{                                                                       \
    temp = gSideStatuses[B_SIDE_PLAYER];                                \
    if (gSideStatuses[B_SIDE_OPPONENT] & status)                        \
        gSideStatuses[B_SIDE_PLAYER] |= status;                         \
    else                                                                \
        gSideStatuses[B_SIDE_PLAYER] &= ~(status);                      \
    if (temp & status)                                                  \
        gSideStatuses[B_SIDE_OPPONENT] |= status;                       \
    else                                                                \
        gSideStatuses[B_SIDE_OPPONENT] &= ~(status);                    \
    SWAP(sideTimerPlayer->structField, sideTimerOpp->structField, temp);\
}                                                                       \

#define UPDATE_COURTCHANGED_BATTLER(structField)\
{                                               \
    temp = sideTimerPlayer->structField;        \
    sideTimerPlayer->structField = BATTLE_OPPOSITE(sideTimerOpp->structField);        \
    sideTimerOpp->structField = BATTLE_OPPOSITE(temp);        \
}                                               \

static void CourtChangeSwapSideStatuses(void)
{
    struct SideTimer *sideTimerPlayer = &gSideTimers[B_SIDE_PLAYER];
    struct SideTimer *sideTimerOpp = &gSideTimers[B_SIDE_OPPONENT];
    u32 temp;

    // Swap timers and statuses
    COURTCHANGE_SWAP(SIDE_STATUS_REFLECT, reflectTimer, temp)
    COURTCHANGE_SWAP(SIDE_STATUS_LIGHTSCREEN, lightscreenTimer, temp)
    COURTCHANGE_SWAP(SIDE_STATUS_MIST, mistTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_SAFEGUARD, safeguardTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_AURORA_VEIL, auroraVeilTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_TAILWIND, tailwindTimer, temp);
    // Lucky Chant doesn't exist in gen 8, but seems like it should be affected by Court Change
    COURTCHANGE_SWAP(SIDE_STATUS_LUCKY_CHANT, luckyChantTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_SPIKES, spikesAmount, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_STEALTH_ROCK, stealthRockAmount, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_TOXIC_SPIKES, toxicSpikesAmount, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_STICKY_WEB, stickyWebAmount, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_STEELSURGE, steelsurgeAmount, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_DAMAGE_NON_TYPES, damageNonTypesTimer, temp);
    // Track Pledge effect side
    COURTCHANGE_SWAP(SIDE_STATUS_RAINBOW, rainbowTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_SEA_OF_FIRE, seaOfFireTimer, temp);
    COURTCHANGE_SWAP(SIDE_STATUS_SWAMP, swampTimer, temp);

    // Change battler IDs of swapped effects. Needed for the correct string when they expire
    // E.g. "Foe's Reflect wore off!"
    UPDATE_COURTCHANGED_BATTLER(reflectBattlerId);
    UPDATE_COURTCHANGED_BATTLER(lightscreenBattlerId);
    UPDATE_COURTCHANGED_BATTLER(mistBattlerId);
    UPDATE_COURTCHANGED_BATTLER(safeguardBattlerId);
    UPDATE_COURTCHANGED_BATTLER(auroraVeilBattlerId);
    UPDATE_COURTCHANGED_BATTLER(tailwindBattlerId);
    UPDATE_COURTCHANGED_BATTLER(luckyChantBattlerId);
    UPDATE_COURTCHANGED_BATTLER(stickyWebBattlerId);

    // Track which side originally set the Sticky Web
    SWAP(sideTimerPlayer->stickyWebBattlerSide, sideTimerOpp->stickyWebBattlerSide, temp);

    // Swap what type set the Gigantamax damage over time effect
    SWAP(sideTimerPlayer->damageNonTypesType, sideTimerOpp->damageNonTypesType, temp);
}

static void HandleScriptMegaPrimalBurst(u32 caseId, u32 battler, u32 type)
{
    struct Pokemon *party = GetBattlerParty(battler);
    struct Pokemon *mon = &party[gBattlerPartyIndexes[battler]];
    u32 side = GetBattlerSide(battler);

    // Change species.
    if (caseId == 0)
    {
        if (type == HANDLE_TYPE_MEGA_EVOLUTION)
        {
            if (!TryBattleFormChange(battler, FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM))
                TryBattleFormChange(battler, FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE);
        }
        else if (type == HANDLE_TYPE_PRIMAL_REVERSION)
            TryBattleFormChange(battler, FORM_CHANGE_BATTLE_PRIMAL_REVERSION);
        else
            TryBattleFormChange(battler, FORM_CHANGE_BATTLE_ULTRA_BURST);

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[battler].species);

        BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_SPECIES_BATTLE, gBitTable[gBattlerPartyIndexes[battler]], sizeof(gBattleMons[battler].species), &gBattleMons[battler].species);
        MarkBattlerForControllerExec(battler);
    }
    // Update healthbox and elevation and play cry.
    else
    {
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], mon, HEALTHBOX_ALL);
        if (side == B_SIDE_OPPONENT)
            SetBattlerShadowSpriteCallback(battler, gBattleMons[battler].species);
        if (type == HANDLE_TYPE_MEGA_EVOLUTION)
            SetGimmickAsActivated(battler, GIMMICK_MEGA);
        if (type == HANDLE_TYPE_ULTRA_BURST)
            SetGimmickAsActivated(battler, GIMMICK_ULTRA_BURST);
    }
}

// Return True if the order was changed, and false if the order was not changed(for example because the target would move after the attacker anyway).
static bool32 ChangeOrderTargetAfterAttacker(void)
{
    u32 i;
    u8 data[MAX_BATTLERS_COUNT];
    u8 actionsData[MAX_BATTLERS_COUNT];

    if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
        return FALSE;
    if (GetBattlerTurnOrderNum(gBattlerAttacker) + 1 == GetBattlerTurnOrderNum(gBattlerTarget))
        return B_AFTER_YOU_TURN_ORDER >= GEN_8;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        data[i] = gBattlerByTurnOrder[i];
        actionsData[i] = gActionsByTurnOrder[i];
    }
    if (GetBattlerTurnOrderNum(gBattlerAttacker) == 0 && GetBattlerTurnOrderNum(gBattlerTarget) == 2)
    {
        gBattlerByTurnOrder[1] = gBattlerTarget;
        gActionsByTurnOrder[1] = actionsData[2];
        gBattlerByTurnOrder[2] = data[1];
        gActionsByTurnOrder[2] = actionsData[1];
    }
    else if (GetBattlerTurnOrderNum(gBattlerAttacker) == 0 && GetBattlerTurnOrderNum(gBattlerTarget) == 3)
    {
        gBattlerByTurnOrder[1] = gBattlerTarget;
        gActionsByTurnOrder[1] = actionsData[3];
        gBattlerByTurnOrder[2] = data[1];
        gActionsByTurnOrder[2] = actionsData[1];
        gBattlerByTurnOrder[3] = data[2];
        gActionsByTurnOrder[3] = actionsData[2];
    }
    else // Attacker == 1, Target == 3
    {
        gBattlerByTurnOrder[2] = gBattlerTarget;
        gActionsByTurnOrder[2] = actionsData[3];
        gBattlerByTurnOrder[3] = data[2];
        gActionsByTurnOrder[3] = actionsData[2];
    }
    return TRUE;
}

static u32 CalculateBattlerPartyCount(u32 battler)
{
    u32 count;
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        count = CalculatePlayerPartyCount();
    else
        count = CalculateEnemyPartyCount();
    return count;
}

static void Cmd_various(void)
{
    CMD_ARGS(u8 battler, u8 id);

    struct Pokemon *mon;
    s32 i;
    u8 data[10];
    u32 side, battler, bits;

    if (gBattleControllerExecFlags)
        return;

    battler = GetBattlerForBattleScript(cmd->battler);

    switch (cmd->id)
    {
    // Roar will fail in a double wild battle when used by the player against one of the two alive wild mons.
    // Also when an opposing wild mon uses it againt its partner.
    case VARIOUS_JUMP_IF_ROAR_FAILS:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (WILD_DOUBLE_BATTLE
            && GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER
            && GetBattlerSide(gBattlerTarget) == B_SIDE_OPPONENT
            && IS_WHOLE_SIDE_ALIVE(gBattlerTarget))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else if (WILD_DOUBLE_BATTLE
                 && GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT
                 && GetBattlerSide(gBattlerTarget) == B_SIDE_OPPONENT)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_ABSENT:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (!IsBattlerAlive(battler))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_SHIELDS_DOWN_PROTECTED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (IsShieldsDownProtected(battler))
        {
            gBattlerAbility = battler;
            gBattlescriptCurrInstr = cmd->jumpInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_JUMP_IF_HOLD_EFFECT:
    {
        VARIOUS_ARGS(u8 holdEffect, const u8 *jumpInstr, u8 equal);
        if ((GetBattlerHoldEffect(battler, TRUE) == cmd->holdEffect) == cmd->equal)
        {
            if (cmd->equal)
                gLastUsedItem = gBattleMons[battler].item; // For B_LAST_USED_ITEM
            gBattlescriptCurrInstr = cmd->jumpInstr;
        }
        else
        {
            if (!cmd->equal)
                gLastUsedItem = gBattleMons[battler].item; // For B_LAST_USED_ITEM
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_JUMP_IF_NO_ALLY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (!IsBattlerAlive(BATTLE_PARTNER(battler)))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_INFATUATE_WITH_BATTLER:
    {
        VARIOUS_ARGS(u8 infatuateWith);
        gBattleScripting.battler = battler;
        gBattleMons[battler].status2 |= STATUS2_INFATUATED_WITH(GetBattlerForBattleScript(cmd->infatuateWith));
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SET_LAST_USED_ITEM:
    {
        VARIOUS_ARGS();
        gLastUsedItem = gBattleMons[battler].item;
        break;
    }
    case VARIOUS_TRY_FAIRY_LOCK:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gFieldStatuses |= STATUS_FIELD_FAIRY_LOCK;
            gFieldTimers.fairyLockTimer = 2;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_GET_STAT_VALUE:
    {
        VARIOUS_ARGS(u8 stat);
        i = cmd->stat;
        gBattleMoveDamage = *(u16 *)(&gBattleMons[battler].attack) + (i - 1);
        gBattleMoveDamage *= gStatStageRatios[gBattleMons[battler].statStages[i]][0];
        gBattleMoveDamage /= gStatStageRatios[gBattleMons[battler].statStages[i]][1];
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_FULL_HP:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (BATTLER_MAX_HP(battler))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_FRISK:
    {
        VARIOUS_ARGS();
        while (gBattleStruct->friskedBattler < gBattlersCount)
        {
            gBattlerTarget = gBattleStruct->friskedBattler++;
            if (GetBattlerSide(battler) != GetBattlerSide(gBattlerTarget)
                && IsBattlerAlive(gBattlerTarget)
                && gBattleMons[gBattlerTarget].item != ITEM_NONE)
            {
                gLastUsedItem = gBattleMons[gBattlerTarget].item;
                RecordItemEffectBattle(gBattlerTarget, GetBattlerHoldEffect(gBattlerTarget, FALSE));
                BattleScriptPushCursor();
                // If Frisk identifies two mons' items, show the pop-up only once.
                if (gBattleStruct->friskedAbility)
                {
                    gBattlescriptCurrInstr = BattleScript_FriskMsg;
                }
                else
                {
                    gBattleStruct->friskedAbility = TRUE;
                    gBattlescriptCurrInstr = BattleScript_FriskMsgWithPopup;
                }
                return;
            }
        }
        gBattleStruct->friskedBattler = 0;
        gBattleStruct->friskedAbility = FALSE;
        break;
    }
    case VARIOUS_POISON_TYPE_IMMUNITY:
    {
        VARIOUS_ARGS(u8 target, const u8 *failInstr);
        if (!CanPoisonType(battler, GetBattlerForBattleScript(cmd->target)))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_PARALYZE_TYPE_IMMUNITY:
    {
        VARIOUS_ARGS(u8 target, const u8 *failInstr);
        if (!CanParalyzeType(battler, GetBattlerForBattleScript(cmd->target)))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRACE_ABILITY:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].ability = gBattleStruct->overwrittenAbilities[battler] = gBattleStruct->tracedAbility[battler];
        break;
    }
    case VARIOUS_TRY_ILLUSION_OFF:
    {
        VARIOUS_ARGS();
        if (GetIllusionMonPtr(battler) != NULL)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_IllusionOff;
            return;
        }
        break;
    }
    case VARIOUS_SET_SPRITEIGNORE0HP:
    {
        VARIOUS_ARGS(bool8 ignore0HP);
        gBattleStruct->spriteIgnore0Hp = cmd->ignore0HP;
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_UPDATE_NICK:
    {
        VARIOUS_ARGS();
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            mon = &gPlayerParty[gBattlerPartyIndexes[battler]];
        else
            mon = &gEnemyParty[gBattlerPartyIndexes[battler]];
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], mon, HEALTHBOX_NICK);
        break;
    }
    case VARIOUS_JUMP_IF_NOT_BERRY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (ItemId_GetPocket(gBattleMons[battler].item) == POCKET_BERRIES)
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->jumpInstr;
        return;
    }
    case VARIOUS_CHECK_IF_GRASSY_TERRAIN_HEALS:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if ((gStatuses3[battler] & (STATUS3_SEMI_INVULNERABLE | STATUS3_HEAL_BLOCK))
            || BATTLER_MAX_HP(battler)
            || !gBattleMons[battler].hp
            || !(IsBattlerGrounded(battler)))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gBattleMoveDamage = GetNonDynamaxMaxHP(battler) / 16;
            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
            gBattleMoveDamage *= -1;

            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_GRAVITY_ON_AIRBORNE_MONS:
    {
        VARIOUS_ARGS();
        // Cancel all multiturn moves of IN_AIR Pokemon except those being targeted by Sky Drop.
        if (gStatuses3[battler] & STATUS3_ON_AIR && !(gStatuses3[battler] & STATUS3_SKY_DROPPED))
            CancelMultiTurnMoves(battler);

        gStatuses3[battler] &= ~(STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS | STATUS3_ON_AIR | STATUS3_SKY_DROPPED);
        break;
    }
    case VARIOUS_SPECTRAL_THIEF:
    {
        VARIOUS_ARGS();
        // Raise stats
        for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
        {
            if (gBattleStruct->stolenStats[0] & gBitTable[i])
            {
                gBattleStruct->stolenStats[0] &= ~(gBitTable[i]);
                SET_STATCHANGER(i, gBattleStruct->stolenStats[i], FALSE);
                if (ChangeStatBuffs(GET_STAT_BUFF_VALUE_WITH_SIGN(gBattleScripting.statChanger), i, MOVE_EFFECT_CERTAIN | MOVE_EFFECT_AFFECTS_USER, NULL) == STAT_CHANGE_WORKED)
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_StatUpMsg;
                    return;
                }
            }
        }
        break;
    }
    case VARIOUS_SET_POWDER:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].status2 |= STATUS2_POWDER;
        break;
    }
    case VARIOUS_ACUPRESSURE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        bits = 0;
        for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
        {
            if (CompareStat(battler, i, MAX_STAT_STAGE, CMP_LESS_THAN))
                bits |= gBitTable[i];
        }
        if (bits)
        {
            u32 statId;
            do
            {
                statId = (Random() % (NUM_BATTLE_STATS - 1)) + 1;
            } while (!(bits & gBitTable[statId]));

            SET_STATCHANGER(statId, 2, FALSE);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
    }
    case VARIOUS_CANCEL_MULTI_TURN_MOVES:
    {
        VARIOUS_ARGS();
        const u8 *result;
        result = CancelMultiTurnMoves(battler);
        if (result)
        {
            gBattlescriptCurrInstr = result;
            return;
        }
        break;
    }
    case VARIOUS_SET_MAGIC_COAT_TARGET:
    {
        VARIOUS_ARGS();
        gBattleStruct->attackerBeforeBounce = battler;
        gBattlerAttacker = gBattlerTarget;
        side = BATTLE_OPPOSITE(GetBattlerSide(gBattlerAttacker));
        if (IsAffectedByFollowMe(gBattlerAttacker, side, gCurrentMove))
            gBattlerTarget = gSideTimers[side].followmeTarget;
        else
            gBattlerTarget = battler;
        break;
    }
    case VARIOUS_IS_RUNNING_IMPOSSIBLE:
    {
        VARIOUS_ARGS();
        gBattleCommunication[0] = IsRunningFromBattleImpossible(battler);
        break;
    }
    case VARIOUS_GET_MOVE_TARGET:
    {
        VARIOUS_ARGS();
        gBattlerTarget = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
        break;
    }
    case VARIOUS_GET_BATTLER_FAINTED:
    {
        VARIOUS_ARGS();
        if (gHitMarker & HITMARKER_FAINTED(battler))
            gBattleCommunication[0] = TRUE;
        else
            gBattleCommunication[0] = FALSE;
        break;
    }
    case VARIOUS_RESET_SWITCH_IN_ABILITY_BITS:
    {
        VARIOUS_ARGS();
        gSpecialStatuses[battler].switchInAbilityDone = FALSE;
        break;
    }
    case VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP:
    {
        VARIOUS_ARGS();
        if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterMonId || gBattlerPartyIndexes[2] == gBattleStruct->expGetterMonId)
        {
            if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterMonId)
                battler = 0;
            else
                battler = 2;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gBattleMons[battler].moves[i] == gBattleStruct->choicedMove[battler])
                    break;
            }
            if (i == MAX_MON_MOVES)
                gBattleStruct->choicedMove[battler] = MOVE_NONE;
        }
        break;
    }
    case VARIOUS_RESET_PLAYER_FAINTED:
    {
        VARIOUS_ARGS();
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_DOUBLE))
            && gBattleTypeFlags & BATTLE_TYPE_TRAINER
            && IsBattlerAlive(B_POSITION_PLAYER_LEFT)
            && IsBattlerAlive(B_POSITION_OPPONENT_LEFT))
        {
            gHitMarker &= ~HITMARKER_PLAYER_FAINTED;
        }
        break;
    }
    case VARIOUS_PALACE_FLAVOR_TEXT:
    {
        VARIOUS_ARGS();
        // Try and print end-of-turn Battle Palace flavor text (e.g. "A glint appears in mon's eyes")
        gBattleCommunication[0] = FALSE; // whether or not msg should be printed
        gBattleScripting.battler = battler = gBattleCommunication[1];
        if (!(gBattleStruct->palaceFlags & gBitTable[battler])
            && gBattleMons[battler].maxHP / 2 >= gBattleMons[battler].hp
            && IsBattlerAlive(battler)
            && !(gBattleMons[battler].status1 & STATUS1_SLEEP))
        {
            gBattleStruct->palaceFlags |= gBitTable[battler];
            gBattleCommunication[0] = TRUE;
            gBattleCommunication[MULTISTRING_CHOOSER] = gNaturesInfo[GetNatureFromPersonality(gBattleMons[battler].personality)].battlePalaceFlavorText;
        }
        break;
    }
    case VARIOUS_ARENA_JUDGMENT_WINDOW:
    {
        VARIOUS_ARGS();

        i = BattleArena_ShowJudgmentWindow(&gBattleCommunication[0]);

        // BattleArena_ShowJudgmentWindow's last state was an intermediate step.
        // Return without advancing the current instruction so that it will be called again.
        if (i == ARENA_RESULT_RUNNING)
            return;

        gBattleCommunication[1] = i;
        break;
    }
    case VARIOUS_ARENA_OPPONENT_MON_LOST:
    {
        VARIOUS_ARGS();
        gBattleMons[1].hp = 0;
        gHitMarker |= HITMARKER_FAINTED(1);
        gBattleStruct->arenaLostOpponentMons |= gBitTable[gBattlerPartyIndexes[1]];
        gDisableStructs[1].truantSwitchInHack = 1;
        break;
    }
    case VARIOUS_ARENA_PLAYER_MON_LOST:
    {
        VARIOUS_ARGS();
        gBattleMons[0].hp = 0;
        gHitMarker |= HITMARKER_FAINTED(0);
        gHitMarker |= HITMARKER_PLAYER_FAINTED;
        gBattleStruct->arenaLostPlayerMons |= gBitTable[gBattlerPartyIndexes[0]];
        gDisableStructs[0].truantSwitchInHack = 1;
        break;
    }
    case VARIOUS_ARENA_BOTH_MONS_LOST:
    {
        VARIOUS_ARGS();
        gBattleMons[0].hp = 0;
        gBattleMons[1].hp = 0;
        gHitMarker |= HITMARKER_FAINTED(0);
        gHitMarker |= HITMARKER_FAINTED(1);
        gHitMarker |= HITMARKER_PLAYER_FAINTED;
        gBattleStruct->arenaLostPlayerMons |= gBitTable[gBattlerPartyIndexes[0]];
        gBattleStruct->arenaLostOpponentMons |= gBitTable[gBattlerPartyIndexes[1]];
        gDisableStructs[0].truantSwitchInHack = 1;
        gDisableStructs[1].truantSwitchInHack = 1;
        break;
    }
    case VARIOUS_EMIT_YESNOBOX:
    {
        VARIOUS_ARGS();
        BtlController_EmitYesNoBox(battler, BUFFER_A);
        MarkBattlerForControllerExec(battler);
        break;
    }
    case VARIOUS_DRAW_ARENA_REF_TEXT_BOX:
    {
        VARIOUS_ARGS();
        DrawArenaRefereeTextBox();
        break;
    }
    case VARIOUS_ERASE_ARENA_REF_TEXT_BOX:
    {
        VARIOUS_ARGS();
        EraseArenaRefereeTextBox();
        break;
    }
    case VARIOUS_ARENA_JUDGMENT_STRING:
    {
        CMD_ARGS(u8 id, u8 _);
        BattleStringExpandPlaceholdersToDisplayedString(gRefereeStringsTable[cmd->id]);
        BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TEXT);
        break;
    }
    case VARIOUS_ARENA_WAIT_STRING:
    {
        VARIOUS_ARGS();
        if (IsTextPrinterActive(ARENA_WIN_JUDGMENT_TEXT))
            return;
        break;
    }
    case VARIOUS_WAIT_CRY:
    {
        VARIOUS_ARGS();
        if (!IsCryFinished())
            return;
        break;
    }
    case VARIOUS_RETURN_OPPONENT_MON1:
    {
        VARIOUS_ARGS();
        battler = 1;
        if (IsBattlerAlive(battler))
        {
            BtlController_EmitReturnMonToBall(battler, BUFFER_A, FALSE);
            MarkBattlerForControllerExec(battler);
        }
        break;
    }
    case VARIOUS_RETURN_OPPONENT_MON2:
    {
        VARIOUS_ARGS();
        if (gBattlersCount > 3)
        {
            battler = 3;
            if (IsBattlerAlive(battler))
            {
                BtlController_EmitReturnMonToBall(battler, BUFFER_A, FALSE);
                MarkBattlerForControllerExec(battler);
            }
        }
        break;
    }
    case VARIOUS_VOLUME_DOWN:
    {
        VARIOUS_ARGS();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x55);
        break;
    }
    case VARIOUS_VOLUME_UP:
    {
        VARIOUS_ARGS();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        break;
    }
    case VARIOUS_SET_ALREADY_STATUS_MOVE_ATTEMPT:
    {
        VARIOUS_ARGS();
        gBattleStruct->alreadyStatusedMoveAttempt |= gBitTable[battler];
        break;
    }
    case VARIOUS_PALACE_TRY_ESCAPE_STATUS:
    {
        VARIOUS_ARGS();
        if (BattlePalace_TryEscapeStatus(battler))
            return;
        break;
    }
    case VARIOUS_SET_TELEPORT_OUTCOME:
    {
        VARIOUS_ARGS();
        // Don't end the battle if one of the wild mons teleported from the wild double battle
        // and its partner is still alive.
        if (GetBattlerSide(battler) == B_SIDE_OPPONENT && IsBattlerAlive(BATTLE_PARTNER(battler)))
        {
            gAbsentBattlerFlags |= gBitTable[battler];
            gHitMarker |= HITMARKER_FAINTED(battler);
            gBattleMons[battler].hp = 0;
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP, &gBattleMons[battler].hp);
            SetHealthboxSpriteInvisible(gHealthboxSpriteIds[battler]);
            FaintClearSetData(battler);
        }
        else if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        {
            gBattleOutcome = B_OUTCOME_PLAYER_TELEPORTED;
        }
        else
        {
            gBattleOutcome = B_OUTCOME_MON_TELEPORTED;
        }
        break;
    }
    case VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC:
    {
        VARIOUS_ARGS();
        BtlController_EmitPlayFanfareOrBGM(battler, BUFFER_A, MUS_VICTORY_TRAINER, TRUE);
        MarkBattlerForControllerExec(battler);
        break;
    }
    case VARIOUS_STAT_TEXT_BUFFER:
    {
        VARIOUS_ARGS();
        PREPARE_STAT_BUFFER(gBattleTextBuff1, gBattleCommunication[0]);
        break;
    }
    case VARIOUS_SWITCHIN_ABILITIES:
    {
        VARIOUS_ARGS();
        gBattlescriptCurrInstr = cmd->nextInstr;
        AbilityBattleEffects(ABILITYEFFECT_NEUTRALIZINGGAS, battler, 0, 0, 0);
        AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, battler, 0, 0, 0);
        AbilityBattleEffects(ABILITYEFFECT_OPPORTUNIST, battler, 0, 0, 0);
        return;
    }
    case VARIOUS_INSTANT_HP_DROP:
    {
        VARIOUS_ARGS();
        BtlController_EmitHealthBarUpdate(battler, BUFFER_A, INSTANT_HP_BAR_DROP);
        MarkBattlerForControllerExec(battler);
        break;
    }
    case VARIOUS_CLEAR_STATUS:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].status1 = 0;
        BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[battler].status1), &gBattleMons[battler].status1);
        MarkBattlerForControllerExec(battler);
        break;
    }
    case VARIOUS_RESTORE_PP:
    {
        VARIOUS_ARGS();
        for (i = 0; i < 4; i++)
        {
            gBattleMons[battler].pp[i] = CalculatePPWithBonus(gBattleMons[battler].moves[i], gBattleMons[battler].ppBonuses, i);
            data[i] = gBattleMons[battler].pp[i];
        }
        data[i] = gBattleMons[battler].ppBonuses;
        BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_PP_DATA_BATTLE, 0, 5, data);
        MarkBattlerForControllerExec(battler);
        break;
    }
    case VARIOUS_TRY_ACTIVATE_MOXIE:    // and chilling neigh + as one ice rider
    {
        VARIOUS_ARGS();

        u16 battlerAbility = GetBattlerAbility(battler);

        if ((battlerAbility == ABILITY_MOXIE
         || battlerAbility == ABILITY_CHILLING_NEIGH
         || battlerAbility == ABILITY_AS_ONE_ICE_RIDER)
          && HasAttackerFaintedTarget()
          && !NoAliveMonsForEitherParty()
          && CompareStat(gBattlerAttacker, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
        {
            SET_STATCHANGER(STAT_ATK, 1, FALSE);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK);
            BattleScriptPush(cmd->nextInstr);
            gLastUsedAbility = battlerAbility;
            if (battlerAbility == ABILITY_AS_ONE_ICE_RIDER)
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_CHILLING_NEIGH;
            gBattlescriptCurrInstr = BattleScript_RaiseStatOnFaintingTarget;
            return;
        }
        break;
    }
    case VARIOUS_TRY_ACTIVATE_GRIM_NEIGH:   // and as one shadow rider
    {
        VARIOUS_ARGS();

        u16 battlerAbility = GetBattlerAbility(battler);

        if ((battlerAbility == ABILITY_GRIM_NEIGH
         || battlerAbility == ABILITY_AS_ONE_SHADOW_RIDER)
          && HasAttackerFaintedTarget()
          && !NoAliveMonsForEitherParty()
          && CompareStat(gBattlerAttacker, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN))
        {
            SET_STATCHANGER(STAT_SPATK, 1, FALSE);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_SPATK);
            BattleScriptPush(cmd->nextInstr);
            gLastUsedAbility = battlerAbility;
            if (battlerAbility == ABILITY_AS_ONE_SHADOW_RIDER)
                gBattleScripting.abilityPopupOverwrite = gLastUsedAbility = ABILITY_GRIM_NEIGH;
            gBattlescriptCurrInstr = BattleScript_RaiseStatOnFaintingTarget;
            return;
        }
        break;
    }
    case VARIOUS_TRY_ACTIVATE_RECEIVER: // Partner gets fainted's ally ability
    {
        VARIOUS_ARGS();
        gBattlerAbility = BATTLE_PARTNER(battler);
        i = GetBattlerAbility(gBattlerAbility);
        if (IsBattlerAlive(gBattlerAbility)
            && (i == ABILITY_RECEIVER || i == ABILITY_POWER_OF_ALCHEMY)
            && GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_ABILITY_SHIELD
            && !gAbilitiesInfo[gBattleMons[battler].ability].cantBeCopied)
        {
            gBattleStruct->tracedAbility[gBattlerAbility] = gBattleMons[battler].ability; // re-using the variable for trace
            gBattleScripting.battler = battler;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_ReceiverActivates;
            return;
        }
        break;
    }
    case VARIOUS_TRY_ACTIVATE_BEAST_BOOST:
    {
        VARIOUS_ARGS();

        i = GetHighestStatId(battler);
        if (GetBattlerAbility(battler) == ABILITY_BEAST_BOOST
            && HasAttackerFaintedTarget()
            && !NoAliveMonsForEitherParty()
            && CompareStat(gBattlerAttacker, i, MAX_STAT_STAGE, CMP_LESS_THAN))
        {
            SET_STATCHANGER(i, 1, FALSE);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, i);
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_AttackerAbilityStatRaise;
            return;
        }
        break;
    }
    case VARIOUS_TRY_ACTIVATE_SOULHEART:
    {
        VARIOUS_ARGS();
        while (gBattleStruct->soulheartBattlerId < gBattlersCount)
        {
            gBattleScripting.battler = gBattleStruct->soulheartBattlerId++;
            if (GetBattlerAbility(gBattleScripting.battler) == ABILITY_SOUL_HEART
                && IsBattlerAlive(gBattleScripting.battler)
                && !NoAliveMonsForEitherParty()
                && CompareStat(gBattleScripting.battler, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                SET_STATCHANGER(STAT_SPATK, 1, FALSE);
                PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_SPATK);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ScriptingAbilityStatRaise;
                return;
            }
        }
        gBattleStruct->soulheartBattlerId = 0;
        break;
    }
    case VARIOUS_TRY_ACTIVATE_FELL_STINGER:
    {
        VARIOUS_ARGS();
        if (gMovesInfo[gCurrentMove].effect == EFFECT_FELL_STINGER
            && HasAttackerFaintedTarget()
            && !NoAliveMonsForEitherParty()
            && CompareStat(gBattlerAttacker, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
        {
            SET_STATCHANGER(STAT_ATK, (B_FELL_STINGER_STAT_RAISE >= GEN_7 ? 3 : 2), FALSE);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK);
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_FellStingerRaisesStat;
            return;
        }
        break;
    }
    case VARIOUS_PLAY_MOVE_ANIMATION:
    {
        VARIOUS_ARGS(u16 move);
        BtlController_EmitMoveAnimation(battler, BUFFER_A, cmd->move, gBattleScripting.animTurn, 0, 0, gBattleMons[battler].friendship, &gDisableStructs[battler], gMultiHitCounter);
        MarkBattlerForControllerExec(battler);
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SET_LUCKY_CHANT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (!(gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_LUCKY_CHANT))
        {
            gSideStatuses[GetBattlerSide(battler)] |= SIDE_STATUS_LUCKY_CHANT;
            gSideTimers[GetBattlerSide(battler)].luckyChantBattlerId = battler;
            gSideTimers[GetBattlerSide(battler)].luckyChantTimer = 5;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
    }
    case VARIOUS_SUCKER_PUNCH_CHECK:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gProtectStructs[gBattlerTarget].obstructed)
            gBattlescriptCurrInstr = cmd->failInstr;
        else if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
            gBattlescriptCurrInstr = cmd->failInstr;
        else if (IS_MOVE_STATUS(gBattleMons[gBattlerTarget].moves[gBattleStruct->chosenMovePositions[gBattlerTarget]]))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SET_SIMPLE_BEAM:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gAbilitiesInfo[gBattleMons[gBattlerTarget].ability].cantBeOverwritten
            || gBattleMons[gBattlerTarget].ability == ABILITY_SIMPLE)
        {
            RecordAbilityBattle(gBattlerTarget, gBattleMons[gBattlerTarget].ability);
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else if (GetBattlerHoldEffect(gBattlerTarget, TRUE) == HOLD_EFFECT_ABILITY_SHIELD)
        {
            RecordItemEffectBattle(gBattlerTarget, HOLD_EFFECT_ABILITY_SHIELD);
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            if (gBattleMons[gBattlerTarget].ability == ABILITY_NEUTRALIZING_GAS)
                gSpecialStatuses[gBattlerTarget].neutralizingGasRemoved = TRUE;

            gBattleMons[gBattlerTarget].ability = gBattleStruct->overwrittenAbilities[gBattlerTarget] = ABILITY_SIMPLE;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_ENTRAINMENT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].cantBeCopied
          || gAbilitiesInfo[gBattleMons[gBattlerTarget].ability].cantBeOverwritten)
        {
            RecordAbilityBattle(gBattlerTarget, gBattleMons[gBattlerTarget].ability);
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else if (GetBattlerHoldEffect(gBattlerTarget, TRUE) == HOLD_EFFECT_ABILITY_SHIELD)
        {
            RecordItemEffectBattle(gBattlerTarget, HOLD_EFFECT_ABILITY_SHIELD);
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            if (gBattleMons[gBattlerTarget].ability == gBattleMons[gBattlerAttacker].ability
                || (GetActiveGimmick(gBattlerTarget) == GIMMICK_DYNAMAX))
            {
                gBattlescriptCurrInstr = cmd->failInstr;
            }
            else
            {
                gBattleMons[gBattlerTarget].ability = gBattleStruct->overwrittenAbilities[gBattlerTarget] = gBattleMons[gBattlerAttacker].ability;
                gBattlescriptCurrInstr = cmd->nextInstr;
            }
        }
        return;
    }
    case VARIOUS_SET_LAST_USED_ABILITY:
    {
        VARIOUS_ARGS();
        gLastUsedAbility = gBattleMons[battler].ability;
        break;
    }
    case VARIOUS_INVERT_STAT_STAGES:
    {
        VARIOUS_ARGS();
        for (i = 0; i < NUM_BATTLE_STATS; i++)
        {
            if (gBattleMons[battler].statStages[i] < DEFAULT_STAT_STAGE) // Negative becomes positive.
                gBattleMons[battler].statStages[i] = DEFAULT_STAT_STAGE + (DEFAULT_STAT_STAGE - gBattleMons[battler].statStages[i]);
            else if (gBattleMons[battler].statStages[i] > DEFAULT_STAT_STAGE) // Positive becomes negative.
                gBattleMons[battler].statStages[i] = DEFAULT_STAT_STAGE - (gBattleMons[battler].statStages[i] - DEFAULT_STAT_STAGE);
        }
        break;
    }
    case VARIOUS_TRY_ME_FIRST:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        u16 move = gBattleMons[gBattlerTarget].moves[gBattleStruct->chosenMovePositions[gBattlerTarget]];
        if (IS_MOVE_STATUS(move) || gMovesInfo[move].meFirstBanned
            || GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
        {
            if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE && !IS_MOVE_STATUS(move))
            {
                gBattleStruct->zmove.baseMoves[gBattlerAttacker] = move;
                gCalledMove = GetTypeBasedZMove(move);
            }
            else
            {
                gCalledMove = move;
            }
            gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
            gBattlerTarget = GetMoveTarget(gCalledMove, NO_TARGET_OVERRIDE);
            gStatuses3[gBattlerAttacker] |= STATUS3_ME_FIRST;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_JUMP_IF_BATTLE_END:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (NoAliveMonsForEitherParty())
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_ELECTRIFY:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gStatuses4[gBattlerTarget] |= STATUS4_ELECTRIFIED;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_SOAK:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if ((GetBattlerType(gBattlerTarget, 0, FALSE) == gMovesInfo[gCurrentMove].type
            && GetBattlerType(gBattlerTarget, 1, FALSE) == gMovesInfo[gCurrentMove].type)
            || GetActiveGimmick(gBattlerTarget) == GIMMICK_TERA)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            SET_BATTLER_TYPE(gBattlerTarget, gMovesInfo[gCurrentMove].type);
            PREPARE_TYPE_BUFFER(gBattleTextBuff1, gMovesInfo[gCurrentMove].type);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_HANDLE_FORM_CHANGE:
    {
        VARIOUS_ARGS(u8 case_);
        if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
            mon = &gEnemyParty[gBattlerPartyIndexes[battler]];
        else
            mon = &gPlayerParty[gBattlerPartyIndexes[battler]];

        // Change species.
        if (cmd->case_ == 0)
        {
            /* What was the idea here?
            if (!gBattleTextBuff1)
                PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[battler].species);
            */
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_SPECIES_BATTLE, gBitTable[gBattlerPartyIndexes[battler]], sizeof(gBattleMons[battler].species), &gBattleMons[battler].species);
            MarkBattlerForControllerExec(battler);
        }
        // Change stats.
        else if (cmd->case_ == 1)
        {
            RecalcBattlerStats(battler, mon);
        }
        // Update healthbox.
        else
        {
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], mon, HEALTHBOX_ALL);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_LAST_RESORT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (CanUseLastResort(battler))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->failInstr;
        return;
    }
    case VARIOUS_SET_ARG_TO_BATTLE_DAMAGE:
    {
        VARIOUS_ARGS();
        gBattleMoveDamage = gMovesInfo[gCurrentMove].argument;
        break;
    }
    case VARIOUS_TRY_HIT_SWITCH_TARGET:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (IsBattlerAlive(gBattlerAttacker)
         && IsBattlerAlive(gBattlerTarget)
         && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
         && TARGET_TURN_DAMAGED
         && GetBattlerAbility(gBattlerTarget) != ABILITY_GUARD_DOG)
        {
            gBattleScripting.switchCase = B_SWITCH_HIT;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
    }
    case VARIOUS_TRY_AUTOTOMIZE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (GetBattlerWeight(battler) > 1)
        {
            gDisableStructs[battler].autotomizeCount++;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
    }
    case VARIOUS_TRY_INSTRUCT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        u16 move = gLastPrintedMoves[gBattlerTarget];
        if (move == MOVE_NONE || move == MOVE_UNAVAILABLE || MoveHasAdditionalEffectSelf(move, MOVE_EFFECT_RECHARGE)
         || gMovesInfo[move].instructBanned
         || gBattleMoveEffects[gMovesInfo[move].effect].twoTurnEffect
         || (GetActiveGimmick(gBattlerTarget) == GIMMICK_DYNAMAX)
         || IsZMove(move)
         || IsMaxMove(move))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gSpecialStatuses[gBattlerTarget].instructedChosenTarget = *(gBattleStruct->moveTarget + gBattlerTarget) | 0x4;
            gCalledMove = move;
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gBattleMons[gBattlerTarget].moves[i] == gCalledMove)
                {
                    gCurrMovePos = i;
                    i = 4;
                    break;
                }
            }
            if (i != 4 || gBattleMons[gBattlerTarget].pp[gCurrMovePos] == 0)
                gBattlescriptCurrInstr = cmd->failInstr;
            else
            {
                gEffectBattler = gBattleStruct->lastMoveTarget[gBattlerTarget];
                gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
                gBattleStruct->atkCancellerTracker = 0;
                PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, battler, gBattlerPartyIndexes[battler]);
                gBattlescriptCurrInstr = cmd->nextInstr;
            }
        }
        return;
    }
    case VARIOUS_ABILITY_POPUP:
    {
        VARIOUS_ARGS();
        CreateAbilityPopUp(battler, gBattleMons[battler].ability, (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) != 0);
        break;
    }
    case VARIOUS_UPDATE_ABILITY_POPUP:
    {
        VARIOUS_ARGS();
        UpdateAbilityPopup(battler);
        break;
    }
    case VARIOUS_JUMP_IF_TARGET_ALLY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->jumpInstr;
        return;
    }
    case VARIOUS_TRY_SYNCHRONOISE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (!DoBattlersShareType(gBattlerAttacker, gBattlerTarget))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_LOSE_TYPE:
    {
        VARIOUS_ARGS(u8 type);
        RemoveBattlerType(battler, cmd->type);
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_PSYCHO_SHIFT:
        {
            VARIOUS_ARGS(const u8 *failInstr);
            u32 targetAbility = GetBattlerAbility(gBattlerTarget);
            // Psycho shift works
            if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_POISON) && CanBePoisoned(gBattlerAttacker, gBattlerTarget, targetAbility))
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            else if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_TOXIC_POISON) && CanBePoisoned(gBattlerAttacker, gBattlerTarget, targetAbility))
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            else if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_BURN) && CanBeBurned(gBattlerTarget, targetAbility))
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            else if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_PARALYSIS) && CanBeParalyzed(gBattlerTarget, targetAbility))
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
            else if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP) && CanBeSlept(gBattlerTarget, targetAbility))
                gBattleCommunication[MULTISTRING_CHOOSER] = 4;
            else if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_FROSTBITE) && CanGetFrostbite(gBattlerTarget))
                gBattleCommunication[MULTISTRING_CHOOSER] = 5;
            else
            {
                gBattlescriptCurrInstr = cmd->failInstr;
                return;
            }
            gBattleMons[gBattlerTarget].status1 = gBattleMons[gBattlerAttacker].status1 & STATUS1_ANY;
            battler = gBattlerTarget;
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[battler].status1), &gBattleMons[battler].status1);
            MarkBattlerForControllerExec(battler);
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }
    case VARIOUS_CURE_STATUS:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].status1 = 0;
        BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[battler].status1), &gBattleMons[battler].status1);
        MarkBattlerForControllerExec(battler);
        break;
    }
    case VARIOUS_POWER_TRICK:
    {
        VARIOUS_ARGS();
        gStatuses3[battler] ^= STATUS3_POWER_TRICK;
        SWAP(gBattleMons[battler].attack, gBattleMons[battler].defense, i);
        break;
    }
    case VARIOUS_AFTER_YOU:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (ChangeOrderTargetAfterAttacker())
        {
            gSpecialStatuses[gBattlerTarget].afterYou = 1;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
    }
    case VARIOUS_BESTOW:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gBattleMons[gBattlerAttacker].item == ITEM_NONE
            || gBattleMons[gBattlerTarget].item != ITEM_NONE
            || !CanBattlerGetOrLoseItem(gBattlerAttacker, gBattleMons[gBattlerAttacker].item)
            || !CanBattlerGetOrLoseItem(gBattlerTarget, gBattleMons[gBattlerAttacker].item)
            || gWishFutureKnock.knockedOffMons[GetBattlerSide(gBattlerTarget)] & gBitTable[gBattlerPartyIndexes[gBattlerTarget]])
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            BestowItem(gBattlerAttacker, gBattlerTarget);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_JUMP_IF_NOT_GROUNDED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (!IsBattlerGrounded(battler))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_HANDLE_TRAINER_SLIDE_MSG:
    {
        VARIOUS_ARGS(u8 case_);
        if (cmd->case_ == 0)
        {
            // Save sprite IDs, because trainer slide in will overwrite gBattlerSpriteIds variable.
            gBattleScripting.savedDmg = (gBattlerSpriteIds[battler] & 0xFF) | (gBattlerSpriteIds[BATTLE_PARTNER(battler)] << 8);
            HideBattlerShadowSprite(battler);
        }
        else if (cmd->case_ == 1)
        {
            BtlController_EmitPrintString(battler, BUFFER_A, STRINGID_TRAINERSLIDE);
            MarkBattlerForControllerExec(battler);
        }
        else
        {
            gBattlerSpriteIds[BATTLE_PARTNER(battler)] = gBattleScripting.savedDmg >> 8;
            gBattlerSpriteIds[battler] = gBattleScripting.savedDmg & 0xFF;
            if (IsBattlerAlive(battler))
            {
                SetBattlerShadowSpriteCallback(battler, gBattleMons[battler].species);
                BattleLoadMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[battler]], battler);
            }
            i = BATTLE_PARTNER(battler);
            if (IsBattlerAlive(i))
            {
                SetBattlerShadowSpriteCallback(i, gBattleMons[i].species);
                BattleLoadMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[i]], i);
            }
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF:
    {
        VARIOUS_ARGS();
        if ((i = ShouldDoTrainerSlide(battler, TRAINER_SLIDE_FIRST_DOWN)))
        {
            gBattleScripting.battler = battler;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = (i == 1 ? BattleScript_TrainerASlideMsgRet : BattleScript_TrainerBSlideMsgRet);
            return;
        }
        break;
    }
    case VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON:
    {
        VARIOUS_ARGS();
        if ((i = ShouldDoTrainerSlide(battler, TRAINER_SLIDE_LAST_SWITCHIN)))
        {
            gBattleScripting.battler = battler;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = (i == 1 ? BattleScript_TrainerASlideMsgRet : BattleScript_TrainerBSlideMsgRet);
            return;
        }
        break;
    }
    case VARIOUS_SET_AURORA_VEIL:
    {
        VARIOUS_ARGS();
        if (gSideStatuses[GetBattlerSide(battler)] & SIDE_STATUS_AURORA_VEIL
            || !(WEATHER_HAS_EFFECT && gBattleWeather & (B_WEATHER_HAIL | B_WEATHER_SNOW)))
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        }
        else
        {
            gSideStatuses[GetBattlerSide(battler)] |= SIDE_STATUS_AURORA_VEIL;
            if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
                gSideTimers[GetBattlerSide(battler)].auroraVeilTimer = 8;
            else
                gSideTimers[GetBattlerSide(battler)].auroraVeilTimer = 5;
            gSideTimers[GetBattlerSide(battler)].auroraVeilBattlerId = battler;

            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMonsInBattle(BATTLE_ALIVE_SIDE, gBattlerAttacker) == 2)
                gBattleCommunication[MULTISTRING_CHOOSER] = 5;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 5;
        }
        break;
    }
    case VARIOUS_TRY_THIRD_TYPE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (IS_BATTLER_OF_TYPE(battler, gMovesInfo[gCurrentMove].argument) || GetActiveGimmick(battler) == GIMMICK_TERA)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gBattleMons[battler].types[2] = gMovesInfo[gCurrentMove].argument;
            PREPARE_TYPE_BUFFER(gBattleTextBuff1, gMovesInfo[gCurrentMove].argument);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_DESTROY_ABILITY_POPUP:
    {
        VARIOUS_ARGS();
        DestroyAbilityPopUp(battler);
        break;
    }
    case VARIOUS_TOTEM_BOOST:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        battler = gBattlerAttacker;
        if (gQueuedStatBoosts[battler].stats == 0)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;    // stats done, exit
        }
        else
        {
            for (i = 0; i < (NUM_BATTLE_STATS - 1); i++)
            {
                if (gQueuedStatBoosts[battler].stats & (1 << i))
                {
                    if (gQueuedStatBoosts[battler].statChanges[i] <= -1)
                        SET_STATCHANGER(i + 1, abs(gQueuedStatBoosts[battler].statChanges[i]), TRUE);
                    else
                        SET_STATCHANGER(i + 1, gQueuedStatBoosts[battler].statChanges[i], FALSE);

                    gQueuedStatBoosts[battler].stats &= ~(1 << i);
                    gBattleScripting.battler = battler;
                    gBattlerTarget = battler;
                    if (gQueuedStatBoosts[battler].stats & 0x80)
                    {
                        gQueuedStatBoosts[battler].stats &= ~0x80; // set 'aura flared to life' flag
                        gBattlescriptCurrInstr = BattleScript_TotemFlaredToLife;
                    }
                    else
                    {
                        gBattlescriptCurrInstr = cmd->jumpInstr;   // do boost
                    }
                    return;
                }
            }
            gBattlescriptCurrInstr = cmd->nextInstr;    // exit if loop failed (failsafe)
        }
        return;
    }
    case VARIOUS_MOVEEND_ITEM_EFFECTS:
    {
        VARIOUS_ARGS();
        if (ItemBattleEffects(ITEMEFFECT_NORMAL, battler, FALSE))
            return;
        break;
    }
    case VARIOUS_ROOM_SERVICE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_ROOM_SERVICE && TryRoomService(battler))
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BerryStatRaiseRet;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
    }
    case VARIOUS_TERRAIN_SEED:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_SEEDS)
        {
            u8 effect = 0;
            u16 item = gBattleMons[battler].item;
            switch (GetBattlerHoldEffectParam(battler))
            {
            case HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN:
                effect = TryHandleSeed(battler, STATUS_FIELD_ELECTRIC_TERRAIN, STAT_DEF, item, FALSE);
                break;
            case HOLD_EFFECT_PARAM_GRASSY_TERRAIN:
                effect = TryHandleSeed(battler, STATUS_FIELD_GRASSY_TERRAIN, STAT_DEF, item, FALSE);
                break;
            case HOLD_EFFECT_PARAM_MISTY_TERRAIN:
                effect = TryHandleSeed(battler, STATUS_FIELD_MISTY_TERRAIN, STAT_SPDEF, item, FALSE);
                break;
            case HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN:
                effect = TryHandleSeed(battler, STATUS_FIELD_PSYCHIC_TERRAIN, STAT_SPDEF, item, FALSE);
                break;
            }

            if (effect)
                return;
        }
        gBattlescriptCurrInstr = cmd->failInstr;
        return;
    }
    case VARIOUS_MAKE_INVISIBLE:
    {
        VARIOUS_ARGS();
        if (gBattleControllerExecFlags)
            break;

        BtlController_EmitSpriteInvisibility(battler, BUFFER_A, TRUE);
        MarkBattlerForControllerExec(battler);
        break;
    }
    case VARIOUS_EERIE_SPELL_PP_REDUCE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gLastMoves[battler] != 0 && gLastMoves[battler] != 0xFFFF)
        {
            s32 i;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gLastMoves[battler] == gBattleMons[battler].moves[i])
                    break;
            }

            if (i != MAX_MON_MOVES && gBattleMons[battler].pp[i] != 0)
            {
                s32 ppToDeduct = 3;

                if (gBattleMons[battler].pp[i] < ppToDeduct)
                    ppToDeduct = gBattleMons[battler].pp[i];

                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastMoves[battler])
                ConvertIntToDecimalStringN(gBattleTextBuff2, ppToDeduct, STR_CONV_MODE_LEFT_ALIGN, 1);
                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 1, ppToDeduct)
                gBattleMons[battler].pp[i] -= ppToDeduct;
                if (!(gDisableStructs[battler].mimickedMoves & gBitTable[i])
                    && !(gBattleMons[battler].status2 & STATUS2_TRANSFORMED))
                {
                    BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_PPMOVE1_BATTLE + i, 0, sizeof(gBattleMons[battler].pp[i]), &gBattleMons[battler].pp[i]);
                    MarkBattlerForControllerExec(battler);
                }

                if (gBattleMons[battler].pp[i] == 0 && gBattleStruct->skyDropTargets[battler] == 0xFF)
                    CancelMultiTurnMoves(battler);

                gBattlescriptCurrInstr = cmd->nextInstr;    // continue
            }
            else
            {
                gBattlescriptCurrInstr = cmd->failInstr;   // cant reduce pp
            }
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;   // cant reduce pp
        }
        return;
    }
    case VARIOUS_JUMP_IF_TEAM_HEALTHY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && IsBattlerAlive(BATTLE_PARTNER(battler)))
        {
            u8 partner = BATTLE_PARTNER(battler);
            if ((gBattleMons[battler].hp == gBattleMons[battler].maxHP && !(gBattleMons[battler].status1 & STATUS1_ANY))
             && (gBattleMons[partner].hp == gBattleMons[partner].maxHP && !(gBattleMons[partner].status1 & STATUS1_ANY)))
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else // single battle
        {
            if (gBattleMons[battler].hp == gBattleMons[battler].maxHP && !(gBattleMons[battler].status1 & STATUS1_ANY))
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_HEAL_QUARTER_HP:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        gBattleMoveDamage = GetNonDynamaxMaxHP(battler) / 4;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        if (gBattleMons[battler].hp == gBattleMons[battler].maxHP)
            gBattlescriptCurrInstr = cmd->failInstr;    // fail
        else
            gBattlescriptCurrInstr = cmd->nextInstr;   // can heal
        return;
    }
    case VARIOUS_REMOVE_TERRAIN:
    {
        VARIOUS_ARGS();
        RemoveAllTerrains();
        break;
    }
    case VARIOUS_JUMP_IF_UNDER_200:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        // If the Pokemon is less than 200 kg, or weighing less than 441 lbs, then Sky Drop will work. Otherwise, it will fail.
        if (GetBattlerWeight(gBattlerTarget) < 2000)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SET_SKY_DROP:
    {
        VARIOUS_ARGS();
        gStatuses3[gBattlerTarget] |= (STATUS3_SKY_DROPPED | STATUS3_ON_AIR);
        /* skyDropTargets holds the information of who is in a particular instance of Sky Drop.
           This is needed in the case that multiple Pokemon use Sky Drop in the same turn or if
           the target of a Sky Drop faints while in the air.*/
        gBattleStruct->skyDropTargets[gBattlerAttacker] = gBattlerTarget;
        gBattleStruct->skyDropTargets[gBattlerTarget] = gBattlerAttacker;

        // End any multiturn effects caused by the target except STATUS2_LOCK_CONFUSE
        gBattleMons[gBattlerTarget].status2 &= ~(STATUS2_MULTIPLETURNS);
        gBattleMons[gBattlerTarget].status2 &= ~(STATUS2_UPROAR);
        gBattleMons[gBattlerTarget].status2 &= ~(STATUS2_BIDE);
        gDisableStructs[gBattlerTarget].rolloutTimer = 0;
        gDisableStructs[gBattlerTarget].furyCutterCounter = 0;

        // End any Follow Me/Rage Powder effects caused by the target
        if (gSideTimers[GetBattlerSide(gBattlerTarget)].followmeTimer != 0 && gSideTimers[GetBattlerSide(gBattlerTarget)].followmeTarget == gBattlerTarget)
            gSideTimers[GetBattlerSide(gBattlerTarget)].followmeTimer = 0;

        break;
    }
    case VARIOUS_CLEAR_SKY_DROP:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        // Check to see if the initial target of this Sky Drop fainted before the 2nd turn of Sky Drop.
        // If so, make the move fail. If not, clear all of the statuses and continue the move.
        if (gBattleStruct->skyDropTargets[gBattlerAttacker] == 0xFF)
            gBattlescriptCurrInstr = cmd->failInstr;
        else
        {
            gBattleStruct->skyDropTargets[gBattlerAttacker] = 0xFF;
            gBattleStruct->skyDropTargets[gBattlerTarget] = 0xFF;
            gStatuses3[gBattlerTarget] &= ~(STATUS3_SKY_DROPPED | STATUS3_ON_AIR);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }

        // Confuse target if they were in the middle of Petal Dance/Outrage/Thrash when targeted.
        if (gBattleMons[gBattlerTarget].status2 & STATUS2_LOCK_CONFUSE)
            gBattleScripting.moveEffect = (MOVE_EFFECT_CONFUSION | MOVE_EFFECT_CERTAIN);
        return;
    }
    case VARIOUS_SKY_DROP_YAWN: // If the mon that's sleeping due to Yawn was holding a Pokemon in Sky Drop, release the target and clear Sky Drop data.
    {
        VARIOUS_ARGS();
        if (gBattleStruct->skyDropTargets[gEffectBattler] != 0xFF && !(gStatuses3[gEffectBattler] & STATUS3_SKY_DROPPED))
        {
            // Set the target of Sky Drop as gEffectBattler
            gEffectBattler = gBattleStruct->skyDropTargets[gEffectBattler];

            // Clear skyDropTargets data
            gBattleStruct->skyDropTargets[gBattleStruct->skyDropTargets[gEffectBattler]] = 0xFF;
            gBattleStruct->skyDropTargets[gEffectBattler] = 0xFF;

            // If the target was in the middle of Outrage/Thrash/etc. when targeted by Sky Drop, confuse them on release and do proper animation
            if (gBattleMons[gEffectBattler].status2 & STATUS2_LOCK_CONFUSE && CanBeConfused(gEffectBattler))
            {
                gBattleMons[gEffectBattler].status2 &= ~(STATUS2_LOCK_CONFUSE);
                gBattlerAttacker = gEffectBattler;
                gBattleMons[gBattlerTarget].status2 |= STATUS2_CONFUSION_TURN(((Random()) % 4) + 2);
                gBattlescriptCurrInstr = BattleScript_ThrashConfuses;
                return;
            }
        }
        break;
    }
    case VARIOUS_JUMP_IF_PRANKSTER_BLOCKED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (BlocksPrankster(gCurrentMove, gBattlerAttacker, battler, TRUE))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_TO_CLEAR_PRIMAL_WEATHER:
    {
        bool8 shouldNotClear = FALSE;

        for (i = 0; i < gBattlersCount; i++)
        {
            u32 ability = GetBattlerAbility(i);
            if (((ability == ABILITY_DESOLATE_LAND && gBattleWeather & B_WEATHER_SUN_PRIMAL)
             || (ability == ABILITY_PRIMORDIAL_SEA && gBattleWeather & B_WEATHER_RAIN_PRIMAL)
             || (ability == ABILITY_DELTA_STREAM && gBattleWeather & B_WEATHER_STRONG_WINDS))
             && IsBattlerAlive(i))
                shouldNotClear = TRUE;
        }
        if (gBattleWeather & B_WEATHER_SUN_PRIMAL && !shouldNotClear)
        {
            gBattleWeather &= ~B_WEATHER_SUN_PRIMAL;
            PrepareStringBattle(STRINGID_EXTREMESUNLIGHTFADED, battler);
            gBattleCommunication[MSG_DISPLAY] = 1;
        }
        else if (gBattleWeather & B_WEATHER_RAIN_PRIMAL && !shouldNotClear)
        {
            gBattleWeather &= ~B_WEATHER_RAIN_PRIMAL;
            PrepareStringBattle(STRINGID_HEAVYRAINLIFTED, battler);
            gBattleCommunication[MSG_DISPLAY] = 1;
        }
        else if (gBattleWeather & B_WEATHER_STRONG_WINDS && !shouldNotClear)
        {
            gBattleWeather &= ~B_WEATHER_STRONG_WINDS;
            PrepareStringBattle(STRINGID_STRONGWINDSDISSIPATED, battler);
            gBattleCommunication[MSG_DISPLAY] = 1;
        }
        break;
    }
    case VARIOUS_TRY_END_NEUTRALIZING_GAS:
    {
        VARIOUS_ARGS();
        if (gSpecialStatuses[battler].neutralizingGasRemoved)
        {
            gSpecialStatuses[battler].neutralizingGasRemoved = FALSE;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_NeutralizingGasExits;
            return;
        }
        break;
    }
    case VARIOUS_GET_ROTOTILLER_TARGETS:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        // Gets the battlers to be affected by rototiller. If there are none, print 'But it failed!'
        {
            u32 count = 0;
            for (i = 0; i < gBattlersCount; i++)
            {
                gSpecialStatuses[i].rototillerAffected = FALSE;
                if (IsRototillerAffected(i))
                {
                    gSpecialStatuses[i].rototillerAffected = TRUE;
                    count++;
                }
            }

            if (count == 0)
                gBattlescriptCurrInstr = cmd->failInstr;   // Rototiller fails
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_JUMP_IF_NOT_ROTOTILLER_AFFECTED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (gSpecialStatuses[battler].rototillerAffected)
        {
            gSpecialStatuses[battler].rototillerAffected = FALSE;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->jumpInstr;   // Unaffected by rototiller - print STRINGID_NOEFFECTONTARGET
        }
        return;
    }
    // TODO: Convert this to a proper FORM_CHANGE type.
    case VARIOUS_TRY_ACTIVATE_BATTLE_BOND:
    {
        VARIOUS_ARGS();
        if (gBattleMons[gBattlerAttacker].species == SPECIES_GRENINJA_BATTLE_BOND
            && HasAttackerFaintedTarget()
            && CalculateBattlerPartyCount(gBattlerTarget) > 1
            && !(gBattleStruct->battleBondTransformed[GetBattlerSide(gBattlerAttacker)] & gBitTable[gBattlerPartyIndexes[gBattlerAttacker]]))
        {
            gBattleStruct->battleBondTransformed[GetBattlerSide(gBattlerAttacker)] |= gBitTable[gBattlerPartyIndexes[gBattlerAttacker]];
            PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].species);
            gBattleStruct->changedSpecies[GetBattlerSide(gBattlerAttacker)][gBattlerPartyIndexes[gBattlerAttacker]] = gBattleMons[gBattlerAttacker].species;
            gBattleMons[gBattlerAttacker].species = SPECIES_GRENINJA_ASH;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_BattleBondActivatesOnMoveEndAttacker;
            return;
        }
        break;
    }
    case VARIOUS_CONSUME_BERRY:
    {
        VARIOUS_ARGS(bool8 fromBattler);
        if (gBattleScripting.overrideBerryRequirements == 2)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }

        if (cmd->fromBattler)
            gLastUsedItem = gBattleMons[battler].item;

        gBattleStruct->ateBerry[battler & BIT_SIDE] |= gBitTable[gBattlerPartyIndexes[battler]];
        gBattleScripting.battler = gEffectBattler = gBattlerTarget = battler;    // Cover all berry effect battler cases. e.g. ChangeStatBuffs uses target ID
        if (ItemBattleEffects(ITEMEFFECT_USE_LAST_ITEM, battler, FALSE))
            return;
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_CANT_REVERT_TO_PRIMAL:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (GetBattleFormChangeTargetSpecies(battler, FORM_CHANGE_BATTLE_PRIMAL_REVERSION) == SPECIES_NONE)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_WEATHER_AFFECTED:
        {
            VARIOUS_ARGS(u32 flags, const u8 *jumpInstr);
            u32 flags = cmd->flags;
            if (IsBattlerWeatherAffected(battler, flags))
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }
    case VARIOUS_JUMP_IF_SPECIES:
    {
        VARIOUS_ARGS(u16 species, const u8 *jumpInstr);
        if (gBattleMons[battler].species == cmd->species)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_LEAF_GUARD_PROTECTED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (IsLeafGuardProtected(battler))
        {
            gBattlerAbility = battler;
            gBattlescriptCurrInstr = cmd->jumpInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_SET_ATTACKER_STICKY_WEB_USER:
    {
        VARIOUS_ARGS();
        // For Mirror Armor: "If the Pokémon with this Ability is affected by Sticky Web, the effect is reflected back to the Pokémon which set it up.
        //  If Pokémon which set up Sticky Web is not on the field, no Pokémon have their Speed lowered."
        gBattlerAttacker = gBattlerTarget;  // Initialize 'fail' condition
        SET_STATCHANGER(STAT_SPEED, 1, TRUE);
        if (gSideTimers[GetBattlerSide(battler)].stickyWebBattlerId != 0xFF)
            gBattlerAttacker = gSideTimers[GetBattlerSide(battler)].stickyWebBattlerId;
        break;
    }
    case VARIOUS_CUT_1_3_HP_RAISE_STATS:
        {
            VARIOUS_ARGS(const u8 *failInstr);

            bool8 atLeastOneStatBoosted = FALSE;
            u16 hpFraction = max(1, GetNonDynamaxMaxHP(gBattlerAttacker) / 3);

            for (i = 1; i < NUM_STATS; i++)
            {
                if (CompareStat(gBattlerAttacker, i, MAX_STAT_STAGE, CMP_LESS_THAN))
                {
                    atLeastOneStatBoosted = TRUE;
                    break;
                }
            }
            if (atLeastOneStatBoosted && gBattleMons[gBattlerAttacker].hp > hpFraction)
            {
                gBattleMoveDamage = hpFraction;
                gBattlescriptCurrInstr = cmd->nextInstr;
            }
            else
            {
                gBattlescriptCurrInstr = cmd->failInstr;
            }
            return;
        }
    case VARIOUS_CHECK_POLTERGEIST:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gBattleMons[battler].item == ITEM_NONE
           || gFieldStatuses & STATUS_FIELD_MAGIC_ROOM
           || GetBattlerAbility(battler) == ABILITY_KLUTZ)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            PREPARE_ITEM_BUFFER(gBattleTextBuff1, gBattleMons[battler].item);
            gLastUsedItem = gBattleMons[battler].item;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_NO_RETREAT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gDisableStructs[battler].noRetreat)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            if (!(gBattleMons[battler].status2 & STATUS2_ESCAPE_PREVENTION))
                gDisableStructs[battler].noRetreat = TRUE;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_CAN_TAR_SHOT_WORK:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        // Tar Shot will fail if it's already been used on the target and its speed can't be lowered further
        if (!gDisableStructs[battler].tarShot
            && CompareStat(battler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->failInstr;
        return;
    }
    case VARIOUS_CURE_CERTAIN_STATUSES:
    {
        VARIOUS_ARGS();
        // Check infatuation
        if (gBattleMons[battler].status2 & STATUS2_INFATUATION)
        {
            gBattleMons[battler].status2 &= ~(STATUS2_INFATUATION);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_INFATUATION;  // STRINGID_TARGETGOTOVERINFATUATION
            StringCopy(gBattleTextBuff1, gStatusConditionString_LoveJpn);
        }
        // Check taunt
        if (gDisableStructs[battler].tauntTimer != 0)
        {
            gDisableStructs[battler].tauntTimer = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_TAUNT;
            PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_TAUNT);
        }
        // Check encore
        if (gDisableStructs[battler].encoreTimer != 0)
        {
            gDisableStructs[battler].encoredMove = 0;
            gDisableStructs[battler].encoreTimer = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_ENCORE;   // STRINGID_PKMNENCOREENDED
        }
        // Check torment
        if (gBattleMons[battler].status2 & STATUS2_TORMENT)
        {
            gBattleMons[battler].status2 &= ~(STATUS2_TORMENT);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_TORMENT;
        }
        // Check heal block
        if (gStatuses3[battler] & STATUS3_HEAL_BLOCK)
        {
            gStatuses3[battler] &= ~(STATUS3_HEAL_BLOCK);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_HEALBLOCK;
        }
        // Check disable
        if (gDisableStructs[battler].disableTimer != 0)
        {
            gDisableStructs[battler].disableTimer = 0;
            gDisableStructs[battler].disabledMove = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_DISABLE;
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_RESET_NEGATIVE_STAT_STAGES:
    {
        VARIOUS_ARGS();
        battler = gBattlerTarget;
        for (i = 0; i < NUM_BATTLE_STATS; i++)
            if (gBattleMons[battler].statStages[i] < DEFAULT_STAT_STAGE)
                gBattleMons[battler].statStages[i] = DEFAULT_STAT_STAGE;
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_LAST_USED_ITEM_BERRY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (ItemId_GetPocket(gLastUsedItem) == POCKET_BERRIES)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_LAST_USED_ITEM_HOLD_EFFECT:
    {
        VARIOUS_ARGS(u8 holdEffect, const u8 *jumpInstr);
        if (ItemId_GetHoldEffect(gLastUsedItem) == cmd->holdEffect)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SAVE_BATTLER_ITEM:
    {
        VARIOUS_ARGS();
        gBattleResources->battleHistory->heldItems[battler] = gBattleMons[battler].item;
        break;
    }
    case VARIOUS_RESTORE_BATTLER_ITEM:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].item = gBattleResources->battleHistory->heldItems[battler];
        break;
    }
    case VARIOUS_BATTLER_ITEM_TO_LAST_USED_ITEM:
    {
        VARIOUS_ARGS();
        gBattleMons[battler].item = gLastUsedItem;
        break;
    }
    case VARIOUS_SET_BEAK_BLAST:
    {
        VARIOUS_ARGS();
        gProtectStructs[battler].beakBlastCharge = TRUE;
        break;
    }
    case VARIOUS_SWAP_SIDE_STATUSES:
    {
        VARIOUS_ARGS();
        CourtChangeSwapSideStatuses();
        break;
    }
    case VARIOUS_SWAP_STATS:
        {
            VARIOUS_ARGS(u8 stat);

            u8 stat = cmd->stat;
            u16 temp;

            switch (stat)
            {
            case STAT_HP:
                SWAP(gBattleMons[gBattlerAttacker].hp, gBattleMons[gBattlerTarget].hp, temp);
                break;
            case STAT_ATK:
                SWAP(gBattleMons[gBattlerAttacker].attack, gBattleMons[gBattlerTarget].attack, temp);
                break;
            case STAT_DEF:
                SWAP(gBattleMons[gBattlerAttacker].defense, gBattleMons[gBattlerTarget].defense, temp);
                break;
            case STAT_SPEED:
                SWAP(gBattleMons[gBattlerAttacker].speed, gBattleMons[gBattlerTarget].speed, temp);
                break;
            case STAT_SPATK:
                SWAP(gBattleMons[gBattlerAttacker].spAttack, gBattleMons[gBattlerTarget].spAttack, temp);
                break;
            case STAT_SPDEF:
                SWAP(gBattleMons[gBattlerAttacker].spDefense, gBattleMons[gBattlerTarget].spDefense, temp);
                break;
            }
            PREPARE_STAT_BUFFER(gBattleTextBuff1, stat);
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }
    case VARIOUS_TEATIME_TARGETS:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        u32 count = 0;

        for (i = 0; i < gBattlersCount; i++)
        {
            if (IsTeatimeAffected(i))
                count++;
        }
        if (count == 0)
            gBattlescriptCurrInstr = cmd->jumpInstr;   // Teatime fails
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TEATIME_INVUL:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (ItemId_GetPocket(gBattleMons[battler].item) == POCKET_BERRIES && !(gStatuses3[gBattlerTarget] & (STATUS3_SEMI_INVULNERABLE)))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->jumpInstr;
        return;
    }
    case VARIOUS_TRY_WIND_RIDER_POWER:
        {
            VARIOUS_ARGS(const u8 *failInstr);
            u16 ability = GetBattlerAbility(battler);
            if (GetBattlerSide(battler) == GetBattlerSide(gBattlerAttacker)
             && (ability == ABILITY_WIND_RIDER || ability == ABILITY_WIND_POWER))
            {
                gLastUsedAbility = ability;
                RecordAbilityBattle(battler, gLastUsedAbility);
                gBattlerAbility = gBattleScripting.battler = battler;
                gBattlescriptCurrInstr = cmd->nextInstr;
            }
            else
            {
                gBattlescriptCurrInstr = cmd->failInstr;
            }
            return;
        }
    case VARIOUS_ACTIVATE_WEATHER_CHANGE_ABILITIES:
    {
        VARIOUS_ARGS();
        gBattlescriptCurrInstr = cmd->nextInstr;
        AbilityBattleEffects(ABILITYEFFECT_ON_WEATHER, battler, 0, 0, 0);
        return;
    }
    case VARIOUS_ACTIVATE_TERRAIN_CHANGE_ABILITIES:
    {
        VARIOUS_ARGS();
        gBattlescriptCurrInstr = cmd->nextInstr;
        AbilityBattleEffects(ABILITYEFFECT_ON_TERRAIN, battler, 0, 0, 0);
        return;
    }
    case VARIOUS_STORE_HEALING_WISH:
    {
        VARIOUS_ARGS();
        if (gCurrentMove == MOVE_LUNAR_DANCE)
            gBattleStruct->storedLunarDance |= gBitTable[battler];
        else
            gBattleStruct->storedHealingWish |= gBitTable[battler];
        break;
    }
    case VARIOUS_HIT_SWITCH_TARGET_FAILED:
    {
        VARIOUS_ARGS();
        gBattleStruct->hitSwitchTargetFailed = TRUE;
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_REVIVAL_BLESSING:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        u32 side = GetBattlerSide(gBattlerAttacker);
        u8 index = GetFirstFaintedPartyIndex(gBattlerAttacker);

        // Move fails if there are no battlers to revive.
        if (index == PARTY_SIZE)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
            return;
        }

        // Battler selected! Revive and go to next instruction.
        if (gSelectedMonPartyId != PARTY_SIZE)
        {
            struct Pokemon *party = GetSideParty(side);

            u16 hp = GetMonData(&party[gSelectedMonPartyId], MON_DATA_MAX_HP) / 2;
            BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_HP_BATTLE, gBitTable[gSelectedMonPartyId], sizeof(hp), &hp);
            MarkBattlerForControllerExec(gBattlerAttacker);
            PREPARE_SPECIES_BUFFER(gBattleTextBuff1, GetMonData(&party[gSelectedMonPartyId], MON_DATA_SPECIES));

            // If an on-field battler is revived, it needs to be sent out again.
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE &&
                gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerAttacker)] == gSelectedMonPartyId)
            {
                gBattleScripting.battler = BATTLE_PARTNER(gBattlerAttacker);
                gBattleCommunication[MULTIUSE_STATE] = TRUE;
            }

            gSelectedMonPartyId = PARTY_SIZE;
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }

        // Open party menu, wait to go to next instruction.
        else
        {
            BtlController_EmitChoosePokemon(gBattlerAttacker, BUFFER_A, PARTY_ACTION_CHOOSE_FAINTED_MON, PARTY_SIZE, ABILITY_NONE, gBattleStruct->battlerPartyOrders[gBattlerAttacker]);
            MarkBattlerForControllerExec(gBattlerAttacker);
        }
        return;
    }
    } // End of switch (cmd->id)

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void TryResetProtectUseCounter(u32 battler)
{
    u32 lastMove = gLastResultingMoves[battler];
    if (lastMove == MOVE_UNAVAILABLE
        || (!gBattleMoveEffects[gMovesInfo[lastMove].effect].usesProtectCounter
          && (B_ALLY_SWITCH_FAIL_CHANCE >= GEN_9 && gMovesInfo[lastMove].effect != EFFECT_ALLY_SWITCH)))
        gDisableStructs[battler].protectUses = 0;
}

static void Cmd_setprotectlike(void)
{
    CMD_ARGS();

    bool32 fail = TRUE;
    bool32 notLastTurn = TRUE;

    TryResetProtectUseCounter(gBattlerAttacker);
    if (gCurrentTurnActionNumber == (gBattlersCount - 1))
        notLastTurn = FALSE;

    if ((sProtectSuccessRates[gDisableStructs[gBattlerAttacker].protectUses] >= Random() && notLastTurn)
        || (gCurrentMove == MOVE_WIDE_GUARD && B_WIDE_GUARD != GEN_5)
        || (gCurrentMove == MOVE_QUICK_GUARD && B_QUICK_GUARD != GEN_5))
    {
        if (!gMovesInfo[gCurrentMove].argument) // Protects one mon only.
        {
            if (gMovesInfo[gCurrentMove].effect == EFFECT_ENDURE)
            {
                gProtectStructs[gBattlerAttacker].endured = TRUE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_BRACED_ITSELF;
            }
            else if (gCurrentMove == MOVE_DETECT || gCurrentMove == MOVE_PROTECT)
            {
                gProtectStructs[gBattlerAttacker].protected = TRUE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_ITSELF;
            }
            else if (gCurrentMove == MOVE_SPIKY_SHIELD)
            {
                gProtectStructs[gBattlerAttacker].spikyShielded = TRUE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_ITSELF;
            }
            else if (gCurrentMove == MOVE_KINGS_SHIELD)
            {
                gProtectStructs[gBattlerAttacker].kingsShielded = TRUE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_ITSELF;
            }
            else if (gCurrentMove == MOVE_BANEFUL_BUNKER)
            {
                gProtectStructs[gBattlerAttacker].banefulBunkered = TRUE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_ITSELF;
            }
            else if (gCurrentMove == MOVE_OBSTRUCT)
            {
                gProtectStructs[gBattlerAttacker].obstructed = TRUE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_ITSELF;
            }
            else if (gCurrentMove == MOVE_MAX_GUARD)
            {
                gProtectStructs[gBattlerAttacker].maxGuarded = TRUE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_ITSELF;
            }
            else if (gCurrentMove == MOVE_SILK_TRAP)
            {
                gProtectStructs[gBattlerAttacker].silkTrapped = TRUE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_ITSELF;
            }
            else if (gCurrentMove == MOVE_BURNING_BULWARK)
            {
                gProtectStructs[gBattlerAttacker].burningBulwarked = TRUE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_ITSELF;
            }

            gDisableStructs[gBattlerAttacker].protectUses++;
            fail = FALSE;
        }
        else // Protects the whole side.
        {
            u8 side = GetBattlerSide(gBattlerAttacker);
            if (gCurrentMove == MOVE_WIDE_GUARD && !(gSideStatuses[side] & SIDE_STATUS_WIDE_GUARD))
            {
                gSideStatuses[side] |= SIDE_STATUS_WIDE_GUARD;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_TEAM;
                gDisableStructs[gBattlerAttacker].protectUses++;
                fail = FALSE;
            }
            else if (gCurrentMove == MOVE_QUICK_GUARD && !(gSideStatuses[side] & SIDE_STATUS_QUICK_GUARD))
            {
                gSideStatuses[side] |= SIDE_STATUS_QUICK_GUARD;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_TEAM;
                gDisableStructs[gBattlerAttacker].protectUses++;
                fail = FALSE;
            }
            else if (gCurrentMove == MOVE_CRAFTY_SHIELD && !(gSideStatuses[side] & SIDE_STATUS_CRAFTY_SHIELD))
            {
                gSideStatuses[side] |= SIDE_STATUS_CRAFTY_SHIELD;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_TEAM;
                gDisableStructs[gBattlerAttacker].protectUses++;
                fail = FALSE;
            }
            else if (gCurrentMove == MOVE_MAT_BLOCK && !(gSideStatuses[side] & SIDE_STATUS_MAT_BLOCK))
            {
                gSideStatuses[side] |= SIDE_STATUS_MAT_BLOCK;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECTED_TEAM;
                fail = FALSE;
            }
        }
    }

    if (fail)
    {
        gDisableStructs[gBattlerAttacker].protectUses = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PROTECT_FAILED;
        gMoveResultFlags |= MOVE_RESULT_MISSED;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_tryexplosion(void)
{
    CMD_ARGS();

    if (gBattleControllerExecFlags)
        return;

    gBattleMoveDamage = gBattleMons[gBattlerAttacker].hp;
    BtlController_EmitHealthBarUpdate(gBattlerAttacker, BUFFER_A, INSTANT_HP_BAR_DROP);
    MarkBattlerForControllerExec(gBattlerAttacker);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setatkhptozero(void)
{
    CMD_ARGS();

    if (gBattleControllerExecFlags)
        return;

    gBattleMons[gBattlerAttacker].hp = 0;
    BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_HP_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].hp), &gBattleMons[gBattlerAttacker].hp);
    MarkBattlerForControllerExec(gBattlerAttacker);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifnexttargetvalid(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    const u8 *jumpInstr = cmd->jumpInstr;

    for (gBattlerTarget++; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (gBattlerTarget == gBattlerAttacker && !(GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove) & MOVE_TARGET_USER))
            continue;
        if (IsBattlerAlive(gBattlerTarget))
            break;
    }

    if (gBattlerTarget >= gBattlersCount)
        gBattlescriptCurrInstr = cmd->nextInstr;
    else
        gBattlescriptCurrInstr = jumpInstr;
}

static void Cmd_tryhealhalfhealth(void)
{
    CMD_ARGS(const u8 *failInstr, u8 battler);

    const u8 *failInstr = cmd->failInstr;

    if (cmd->battler == BS_ATTACKER)
        gBattlerTarget = gBattlerAttacker;

    gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerTarget) / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;
    gBattleMoveDamage *= -1;

    if (gBattleMons[gBattlerTarget].hp == gBattleMons[gBattlerTarget].maxHP)
        gBattlescriptCurrInstr = failInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void SetMoveForMirrorMove(u32 move)
{
    gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
    // Edge case, we used Z Mirror Move, got the stat boost and now need to use the Z-move
    if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE && !IS_MOVE_STATUS(move))
    {
        gBattleStruct->zmove.baseMoves[gBattlerAttacker] = move;
        gCurrentMove = GetTypeBasedZMove(move);
    }
    else
    {
        gCurrentMove = move;
    }

    SetAtkCancellerForCalledMove();
    gBattlerTarget = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
    gBattlescriptCurrInstr = GET_MOVE_BATTLESCRIPT(gCurrentMove);
}

static void Cmd_trymirrormove(void)
{
    CMD_ARGS();

    s32 i, validMovesCount;
    u16 move;
    u16 validMoves[MAX_BATTLERS_COUNT] = {0};

    for (validMovesCount = 0, i = 0; i < gBattlersCount; i++)
    {
        if (i != gBattlerAttacker)
        {
            move = gBattleStruct->lastTakenMoveFrom[gBattlerAttacker][i];
            if (move != MOVE_NONE && move != MOVE_UNAVAILABLE)
            {
                validMoves[validMovesCount] = move;
                validMovesCount++;
            }
        }
    }

    move = gBattleStruct->lastTakenMove[gBattlerAttacker];
    if (move != MOVE_NONE && move != MOVE_UNAVAILABLE)
    {
        SetMoveForMirrorMove(move);
    }
    else if (validMovesCount != 0)
    {
        SetMoveForMirrorMove(validMoves[Random() % validMovesCount]);
    }
    else // no valid moves found
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setfieldweather(void)
{
    CMD_ARGS(u8 weather);

    u8 weather = cmd->weather;

    if (!TryChangeBattleWeather(gBattlerAttacker, weather, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_FAILED;
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }

    switch (weather)
    {
    case ENUM_WEATHER_RAIN:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STARTED_RAIN;
        break;
    case ENUM_WEATHER_SUN:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STARTED_SUNLIGHT;
        break;
    case ENUM_WEATHER_SANDSTORM:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STARTED_SANDSTORM;
        break;
    case ENUM_WEATHER_HAIL:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STARTED_HAIL;
        break;
    case ENUM_WEATHER_SNOW:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STARTED_SNOW;
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setreflect(void)
{
    CMD_ARGS();

    if (gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_REFLECT)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SIDE_STATUS_FAILED;
    }
    else
    {
        gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_REFLECT;
        if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[GetBattlerSide(gBattlerAttacker)].reflectTimer = 8;
        else
            gSideTimers[GetBattlerSide(gBattlerAttacker)].reflectTimer = 5;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].reflectBattlerId = gBattlerAttacker;

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMonsInBattle(BATTLE_ALIVE_SIDE, gBattlerAttacker) == 2)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_REFLECT_DOUBLE;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_REFLECT_SINGLE;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setseeded(void)
{
    CMD_ARGS();

    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT || gStatuses3[gBattlerTarget] & STATUS3_LEECHSEED)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LEECH_SEED_MISS;
    }
    else if (IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_GRASS))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LEECH_SEED_FAIL;
    }
    else
    {
        gStatuses3[gBattlerTarget] |= gBattlerAttacker;
        gStatuses3[gBattlerTarget] |= STATUS3_LEECHSEED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LEECH_SEED_SET;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_manipulatedamage(void)
{
    CMD_ARGS(u8 mode);

    switch (cmd->mode)
    {
    case DMG_CHANGE_SIGN:
        gBattleMoveDamage *= -1;
        break;
    case DMG_RECOIL_FROM_MISS:
        if (B_RECOIL_IF_MISS_DMG >= GEN_5)
        {
            gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 2;
        }
        else if (B_RECOIL_IF_MISS_DMG == GEN_4)
        {
            if ((gBattleMons[gBattlerTarget].maxHP / 2) < gBattleMoveDamage)
                gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerTarget) / 2;
        }
        else
        {
            gBattleMoveDamage /= 2;
        }
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        break;
    case DMG_DOUBLED:
        gBattleMoveDamage *= 2;
        break;
    case DMG_1_8_TARGET_HP:
        gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerTarget) / 8;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        break;
    case DMG_FULL_ATTACKER_HP:
        gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker);
        break;
    case DMG_CURR_ATTACKER_HP:
        gBattleMoveDamage = GetNonDynamaxHP(gBattlerAttacker);
        break;
    case DMG_BIG_ROOT:
        gBattleMoveDamage = GetDrainedBigRootHp(gBattlerAttacker, gBattleMoveDamage);
        break;
    case DMG_RECOIL_FROM_IMMUNE:
        gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerTarget) / 2;
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_trysetrest(void)
{
    CMD_ARGS(const u8 *failInstr);

    const u8 *failInstr = cmd->failInstr;
    gBattlerTarget = gBattlerAttacker;
    gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP * (-1);

    if (gBattleMons[gBattlerTarget].hp == gBattleMons[gBattlerTarget].maxHP)
    {
        gBattlescriptCurrInstr = failInstr;
    }
    else if (IsBattlerTerrainAffected(gBattlerTarget, STATUS_FIELD_ELECTRIC_TERRAIN))
    {
        gBattlescriptCurrInstr = BattleScript_ElectricTerrainPrevents;
    }
    else if (IsBattlerTerrainAffected(gBattlerTarget, STATUS_FIELD_MISTY_TERRAIN))
    {
        gBattlescriptCurrInstr = BattleScript_MistyTerrainPrevents;
    }
    else
    {
        if (gBattleMons[gBattlerTarget].status1 & ((u8)(~STATUS1_SLEEP)))
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_REST_STATUSED;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_REST;

        gBattleMons[gBattlerTarget].status1 = STATUS1_SLEEP_TURN(3);
        BtlController_EmitSetMonData(gBattlerTarget, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].status1), &gBattleMons[gBattlerTarget].status1);
        MarkBattlerForControllerExec(gBattlerTarget);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifnotfirstturn(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    const u8 *jumpInstr = cmd->jumpInstr;

    if (gDisableStructs[gBattlerAttacker].isFirstTurn && !(gSpecialStatuses[gBattlerAttacker].instructedChosenTarget))
        gBattlescriptCurrInstr = cmd->nextInstr;
    else
        gBattlescriptCurrInstr = jumpInstr;
}

static void Cmd_setmiracleeye(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (!(gStatuses3[gBattlerTarget] & STATUS3_MIRACLE_EYED))
    {
        gStatuses3[gBattlerTarget] |= STATUS3_MIRACLE_EYED;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

bool8 UproarWakeUpCheck(u8 battler)
{
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (!(gBattleMons[i].status2 & STATUS2_UPROAR) || (GetBattlerAbility(battler) == ABILITY_SOUNDPROOF && B_UPROAR_IGNORE_SOUNDPROOF < GEN_5))
            continue;

        gBattleScripting.battler = i;

        if (gBattlerTarget == 0xFF)
            gBattlerTarget = i;
        else if (gBattlerTarget == i)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_SLEEP_UPROAR;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_UPROAR_KEPT_AWAKE;

        break;
    }

    if (i == gBattlersCount)
        return FALSE;
    else
        return TRUE;
}

static void Cmd_jumpifuproarwakes(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (UproarWakeUpCheck(gBattlerTarget))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_stockpile(void)
{
    CMD_ARGS(u8 id);

    switch (cmd->id)
    {
    case 0:
        if (gDisableStructs[gBattlerAttacker].stockpileCounter >= 3)
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_STOCKPILE;
        }
        else
        {
            gDisableStructs[gBattlerAttacker].stockpileCounter++;
            gDisableStructs[gBattlerAttacker].stockpileBeforeDef = gBattleMons[gBattlerAttacker].statStages[STAT_DEF];
            gDisableStructs[gBattlerAttacker].stockpileBeforeSpDef = gBattleMons[gBattlerAttacker].statStages[STAT_SPDEF];
            PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 1, gDisableStructs[gBattlerAttacker].stockpileCounter);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STOCKPILED;
        }
        break;
    case 1: // Save def/sp def stats.
        if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            gDisableStructs[gBattlerAttacker].stockpileDef += gBattleMons[gBattlerAttacker].statStages[STAT_DEF] - gDisableStructs[gBattlerAttacker].stockpileBeforeDef;
            gDisableStructs[gBattlerAttacker].stockpileSpDef += gBattleMons[gBattlerAttacker].statStages[STAT_SPDEF] - gDisableStructs[gBattlerAttacker].stockpileBeforeSpDef;
        }
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_stockpiletobasedamage(void)
{
    CMD_ARGS(const u8 *failInstr);

    const u8 *failInstr = cmd->failInstr;
    if (gDisableStructs[gBattlerAttacker].stockpileCounter == 0)
    {
        gBattlescriptCurrInstr = failInstr;
    }
    else
    {
        if (gBattleCommunication[MISS_TYPE] != B_MSG_PROTECTED)
            gBattleScripting.animTurn = gDisableStructs[gBattlerAttacker].stockpileCounter;

        if (!(gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_1ST_HIT && IsBattlerAlive(gBattlerTarget)))
        {
            gBattleStruct->moveEffect2 = MOVE_EFFECT_STOCKPILE_WORE_OFF;
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_stockpiletohpheal(void)
{
    CMD_ARGS(const u8 *failInstr);

    const u8 *failInstr = cmd->failInstr;

    if (gDisableStructs[gBattlerAttacker].stockpileCounter == 0 && !gBattleStruct->snatchedMoveIsUsed)
    {
        gBattlescriptCurrInstr = failInstr;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWALLOW_FAILED;
    }
    else
    {
        if (gBattleMons[gBattlerAttacker].maxHP == gBattleMons[gBattlerAttacker].hp)
        {
            gDisableStructs[gBattlerAttacker].stockpileCounter = 0;
            gBattlescriptCurrInstr = failInstr;
            gBattlerTarget = gBattlerAttacker;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWALLOW_FULL_HP;
        }
        else
        {
            if (gDisableStructs[gBattlerAttacker].stockpileCounter > 0)
            {
                gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / (1 << (3 - gDisableStructs[gBattlerAttacker].stockpileCounter));
                gBattleScripting.animTurn = gDisableStructs[gBattlerAttacker].stockpileCounter;
                gBattleStruct->moveEffect2 = MOVE_EFFECT_STOCKPILE_WORE_OFF;
            }
            else // Snatched move
            {
                gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 4;
                gBattleScripting.animTurn = 1;
            }

            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
            gBattleMoveDamage *= -1;
            
            gBattlescriptCurrInstr = cmd->nextInstr;
            gBattlerTarget = gBattlerAttacker;
        }
    }
}

// Sign change for drained HP handled in GetDrainedBigRootHp
static void Cmd_setdrainedhp(void)
{
    CMD_ARGS();

    if (gMovesInfo[gCurrentMove].argument != 0)
        gBattleMoveDamage = (gHpDealt * gMovesInfo[gCurrentMove].argument / 100);
    else
        gBattleMoveDamage = (gHpDealt / 2);

    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static u16 ReverseStatChangeMoveEffect(u16 moveEffect)
{
    switch (moveEffect)
    {
    // +1
    case MOVE_EFFECT_ATK_PLUS_1:
        return MOVE_EFFECT_ATK_MINUS_1;
    case MOVE_EFFECT_DEF_PLUS_1:
        return MOVE_EFFECT_DEF_MINUS_1;
    case MOVE_EFFECT_SPD_PLUS_1:
        return MOVE_EFFECT_SPD_MINUS_1;
    case MOVE_EFFECT_SP_ATK_PLUS_1:
        return MOVE_EFFECT_SP_ATK_MINUS_1;
    case MOVE_EFFECT_SP_DEF_PLUS_1:
        return MOVE_EFFECT_SP_DEF_MINUS_1;
    case MOVE_EFFECT_ACC_PLUS_1:
        return MOVE_EFFECT_ACC_MINUS_1;
    case MOVE_EFFECT_EVS_PLUS_1:
        return MOVE_EFFECT_EVS_MINUS_1;
    // -1
    case MOVE_EFFECT_ATK_MINUS_1:
        return MOVE_EFFECT_ATK_PLUS_1;
    case MOVE_EFFECT_DEF_MINUS_1:
        return MOVE_EFFECT_DEF_PLUS_1;
    case MOVE_EFFECT_SPD_MINUS_1:
        return MOVE_EFFECT_SPD_PLUS_1;
    case MOVE_EFFECT_SP_ATK_MINUS_1:
        return MOVE_EFFECT_SP_ATK_PLUS_1;
    case MOVE_EFFECT_SP_DEF_MINUS_1:
        return MOVE_EFFECT_SP_DEF_PLUS_1;
    case MOVE_EFFECT_ACC_MINUS_1:
        return MOVE_EFFECT_ACC_PLUS_1;
    case MOVE_EFFECT_EVS_MINUS_1:
    // +2
    case MOVE_EFFECT_ATK_PLUS_2:
        return MOVE_EFFECT_ATK_MINUS_2;
    case MOVE_EFFECT_DEF_PLUS_2:
        return MOVE_EFFECT_DEF_MINUS_2;
    case MOVE_EFFECT_SPD_PLUS_2:
        return MOVE_EFFECT_SPD_MINUS_2;
    case MOVE_EFFECT_SP_ATK_PLUS_2:
        return MOVE_EFFECT_SP_ATK_MINUS_2;
    case MOVE_EFFECT_SP_DEF_PLUS_2:
        return MOVE_EFFECT_SP_DEF_MINUS_2;
    case MOVE_EFFECT_ACC_PLUS_2:
        return MOVE_EFFECT_ACC_MINUS_2;
    case MOVE_EFFECT_EVS_PLUS_2:
        return MOVE_EFFECT_EVS_MINUS_2;
    // -2
    case MOVE_EFFECT_ATK_MINUS_2:
        return MOVE_EFFECT_ATK_PLUS_2;
    case MOVE_EFFECT_DEF_MINUS_2:
        return MOVE_EFFECT_DEF_PLUS_2;
    case MOVE_EFFECT_SPD_MINUS_2:
        return MOVE_EFFECT_SPD_PLUS_2;
    case MOVE_EFFECT_SP_ATK_MINUS_2:
        return MOVE_EFFECT_SP_ATK_PLUS_2;
    case MOVE_EFFECT_SP_DEF_MINUS_2:
        return MOVE_EFFECT_SP_DEF_PLUS_2;
    case MOVE_EFFECT_ACC_MINUS_2:
        return MOVE_EFFECT_ACC_PLUS_2;
    case MOVE_EFFECT_EVS_MINUS_2:
        return MOVE_EFFECT_EVS_PLUS_2;
    default:
        return 0;
    }
}

static u32 ChangeStatBuffs(s8 statValue, u32 statId, u32 flags, const u8 *BS_ptr)
{
    bool32 certain = FALSE;
    bool32 notProtectAffected = FALSE;
    u32 index, battler, battlerAbility, battlerHoldEffect;
    bool32 affectsUser = (flags & MOVE_EFFECT_AFFECTS_USER);
    bool32 mirrorArmored = (flags & STAT_CHANGE_MIRROR_ARMOR);

    if (affectsUser)
        battler = gBattlerAttacker;
    else
        battler = gBattlerTarget;

    battlerAbility = GetBattlerAbility(battler);
    battlerHoldEffect = GetBattlerHoldEffect(battler, TRUE);

    gSpecialStatuses[battler].changedStatsBattlerId = gBattlerAttacker;

    flags &= ~(MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_MIRROR_ARMOR);

    if (flags & MOVE_EFFECT_CERTAIN)
        certain = TRUE;
    flags &= ~MOVE_EFFECT_CERTAIN;

    if (flags & STAT_CHANGE_NOT_PROTECT_AFFECTED)
        notProtectAffected++;
    flags &= ~STAT_CHANGE_NOT_PROTECT_AFFECTED;

    if (battlerAbility == ABILITY_CONTRARY)
    {
        statValue ^= STAT_BUFF_NEGATIVE;
        gBattleScripting.statChanger ^= STAT_BUFF_NEGATIVE;
        RecordAbilityBattle(battler, battlerAbility);
        if (flags & STAT_CHANGE_UPDATE_MOVE_EFFECT)
        {
            flags &= ~STAT_CHANGE_UPDATE_MOVE_EFFECT;
            gBattleScripting.moveEffect = ReverseStatChangeMoveEffect(gBattleScripting.moveEffect);
        }
    }
    else if (battlerAbility == ABILITY_SIMPLE)
    {
        statValue = (SET_STAT_BUFF_VALUE(GET_STAT_BUFF_VALUE(statValue) * 2)) | ((statValue <= -1) ? STAT_BUFF_NEGATIVE : 0);
    }

    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);

    if (statValue <= -1) // Stat decrease.
    {
        if (gSideTimers[GetBattlerSide(battler)].mistTimer
            && !certain && gCurrentMove != MOVE_CURSE
            && !(battler == gBattlerTarget && GetBattlerAbility(gBattlerAttacker) == ABILITY_INFILTRATOR))
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                if (gSpecialStatuses[battler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleScripting.battler = battler;
                    gBattlescriptCurrInstr = BattleScript_MistProtected;
                    gSpecialStatuses[battler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (gCurrentMove != MOVE_CURSE
                 && notProtectAffected != TRUE && JumpIfMoveAffectedByProtect(gCurrentMove))
        {
            gBattlescriptCurrInstr = BattleScript_ButItFailed;
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if ((battlerHoldEffect == HOLD_EFFECT_CLEAR_AMULET || CanAbilityPreventStatLoss(battlerAbility))
              && (!affectsUser || mirrorArmored) && !certain && gCurrentMove != MOVE_CURSE)
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                if (gSpecialStatuses[battler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    gBattleScripting.battler = battler;
                    if (battlerHoldEffect == HOLD_EFFECT_CLEAR_AMULET)
                    {
                        gLastUsedItem = gBattleMons[battler].item;
                        BattleScriptPush(BS_ptr);
                        gBattlescriptCurrInstr = BattleScript_ItemNoStatLoss;
                        RecordItemEffectBattle(battler, HOLD_EFFECT_CLEAR_AMULET);
                    }
                    else
                    {
                        gBattlerAbility = battler;
                        BattleScriptPush(BS_ptr);
                        gBattlescriptCurrInstr = BattleScript_AbilityNoStatLoss;
                        gLastUsedAbility = battlerAbility;
                        RecordAbilityBattle(battler, gLastUsedAbility);
                    }
                    gSpecialStatuses[battler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if ((index = IsFlowerVeilProtected(battler)) && !certain)
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                if (gSpecialStatuses[battler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleScripting.battler = battler;
                    gBattlerAbility = index - 1;
                    gBattlescriptCurrInstr = BattleScript_FlowerVeilProtectsRet;
                    gLastUsedAbility = ABILITY_FLOWER_VEIL;
                    gSpecialStatuses[battler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (!certain
                && (((battlerAbility == ABILITY_KEEN_EYE || battlerAbility == ABILITY_MINDS_EYE) && statId == STAT_ACC)
                || (B_ILLUMINATE_EFFECT >= GEN_9 && battlerAbility == ABILITY_ILLUMINATE && statId == STAT_ACC)
                || (battlerAbility == ABILITY_HYPER_CUTTER && statId == STAT_ATK)
                || (battlerAbility == ABILITY_BIG_PECKS && statId == STAT_DEF)))
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                BattleScriptPush(BS_ptr);
                gBattleScripting.battler = battler;
                gBattlerAbility = battler;
                gBattlescriptCurrInstr = BattleScript_AbilityNoSpecificStatLoss;
                gLastUsedAbility = battlerAbility;
                RecordAbilityBattle(battler, gLastUsedAbility);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (battlerAbility == ABILITY_MIRROR_ARMOR && !affectsUser && !mirrorArmored && gBattlerAttacker != gBattlerTarget && battler == gBattlerTarget)
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                SET_STATCHANGER(statId, GET_STAT_BUFF_VALUE(statValue) | STAT_BUFF_NEGATIVE, TRUE);
                BattleScriptPush(BS_ptr);
                gBattleScripting.battler = battler;
                gBattlerAbility = battler;
                gBattlescriptCurrInstr = BattleScript_MirrorArmorReflect;
                RecordAbilityBattle(battler, gBattleMons[battler].ability);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else // try to decrease
        {
            statValue = -GET_STAT_BUFF_VALUE(statValue);
            if (gBattleMons[battler].statStages[statId] == 1)
                statValue = -1;
            else if (gBattleMons[battler].statStages[statId] == 2 && statValue < -2)
                statValue = -2;
            gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
            index = 1;
            if (statValue == -2)
            {
                gBattleTextBuff2[1] = B_BUFF_STRING;
                gBattleTextBuff2[2] = STRINGID_STATHARSHLY;
                gBattleTextBuff2[3] = STRINGID_STATHARSHLY >> 8;
                index = 4;
            }
            else if (statValue <= -3)
            {
                gBattleTextBuff2[1] = B_BUFF_STRING;
                gBattleTextBuff2[2] = STRINGID_SEVERELY & 0xFF;
                gBattleTextBuff2[3] = STRINGID_SEVERELY >> 8;
                index = 4;
            }
            gBattleTextBuff2[index++] = B_BUFF_STRING;
            gBattleTextBuff2[index++] = STRINGID_STATFELL;
            gBattleTextBuff2[index++] = STRINGID_STATFELL >> 8;
            gBattleTextBuff2[index] = B_BUFF_EOS;

            if (gBattleMons[battler].statStages[statId] == MIN_STAT_STAGE)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_DECREASE;
            }
            else
            {
                gProtectStructs[battler].statFell = TRUE;   // Eject pack, lash out
                gBattleCommunication[MULTISTRING_CHOOSER] = (gBattlerTarget == battler); // B_MSG_ATTACKER_STAT_FELL or B_MSG_DEFENDER_STAT_FELL
            }
        }
    }
    else // stat increase
    {
        statValue = GET_STAT_BUFF_VALUE(statValue);
        if (gBattleMons[battler].statStages[statId] == 11)
            statValue = 1;
        else if (gBattleMons[battler].statStages[statId] == 10 && statValue > 2)
            statValue = 2;
        gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
        index = 1;
        if (statValue == 2)
        {
            gBattleTextBuff2[1] = B_BUFF_STRING;
            gBattleTextBuff2[2] = STRINGID_STATSHARPLY;
            gBattleTextBuff2[3] = STRINGID_STATSHARPLY >> 8;
            index = 4;
        }
        else if (statValue >= 3)
        {
            gBattleTextBuff2[1] = B_BUFF_STRING;
            gBattleTextBuff2[2] = STRINGID_DRASTICALLY & 0xFF;
            gBattleTextBuff2[3] = STRINGID_DRASTICALLY >> 8;
            index = 4;
        }
        gBattleTextBuff2[index++] = B_BUFF_STRING;
        gBattleTextBuff2[index++] = STRINGID_STATROSE;
        gBattleTextBuff2[index++] = STRINGID_STATROSE >> 8;
        gBattleTextBuff2[index] = B_BUFF_EOS;

        if (gBattleMons[battler].statStages[statId] == MAX_STAT_STAGE)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_INCREASE;
        }
        else
        {
            u32 statIncrease;
            if ((statValue + gBattleMons[battler].statStages[statId]) > MAX_STAT_STAGE)
                statIncrease = MAX_STAT_STAGE - gBattleMons[battler].statStages[statId];
            else
                statIncrease = statValue;

            gBattleCommunication[MULTISTRING_CHOOSER] = (gBattlerTarget == battler);
            gProtectStructs[battler].statRaised = TRUE;

            // Check Mirror Herb / Opportunist
            for (index = 0; index < gBattlersCount; index++)
            {
                if (GetBattlerSide(index) == GetBattlerSide(battler))
                    continue; // Only triggers on opposing side

                if (GetBattlerAbility(index) == ABILITY_OPPORTUNIST
                 && gProtectStructs[battler].activateOpportunist == 0) // don't activate opportunist on other mon's opportunist raises
                {
                    gProtectStructs[index].activateOpportunist = 2;      // set stats to copy
                }
                if (GetBattlerHoldEffect(index, TRUE) == HOLD_EFFECT_MIRROR_HERB)
                {
                    gProtectStructs[index].eatMirrorHerb = 1;
                }

                if (gProtectStructs[index].activateOpportunist == 2 || gProtectStructs[index].eatMirrorHerb == 1)
                {
                    gQueuedStatBoosts[index].stats |= (1 << (statId - 1));    // -1 to start at atk
                    gQueuedStatBoosts[index].statChanges[statId - 1] += statIncrease;
                }
            }
        }
    }

    gBattleMons[battler].statStages[statId] += statValue;
    if (gBattleMons[battler].statStages[statId] < MIN_STAT_STAGE)
        gBattleMons[battler].statStages[statId] = MIN_STAT_STAGE;
    if (gBattleMons[battler].statStages[statId] > MAX_STAT_STAGE)
        gBattleMons[battler].statStages[statId] = MAX_STAT_STAGE;

    if (gBattleCommunication[MULTISTRING_CHOOSER] == B_MSG_STAT_WONT_INCREASE && flags & STAT_CHANGE_ALLOW_PTR)
        gMoveResultFlags |= MOVE_RESULT_MISSED;

    if (gBattleCommunication[MULTISTRING_CHOOSER] == B_MSG_STAT_WONT_INCREASE && !(flags & STAT_CHANGE_ALLOW_PTR))
        return STAT_CHANGE_DIDNT_WORK;

    return STAT_CHANGE_WORKED;
}

static void Cmd_statbuffchange(void)
{
    CMD_ARGS(u16 flags, const u8 *failInstr);

    u16 flags = cmd->flags;
    const u8 *ptrBefore = gBattlescriptCurrInstr;
    const u8 *failInstr = cmd->failInstr;

    if (ChangeStatBuffs(GET_STAT_BUFF_VALUE_WITH_SIGN(gBattleScripting.statChanger), GET_STAT_BUFF_ID(gBattleScripting.statChanger), flags, failInstr) == STAT_CHANGE_WORKED)
        gBattlescriptCurrInstr = cmd->nextInstr;
    else if (gBattlescriptCurrInstr == ptrBefore) // Prevent infinite looping.
        gBattlescriptCurrInstr = failInstr;
}

bool32 TryResetBattlerStatChanges(u8 battler)
{
    u32 j;
    bool32 ret = FALSE;

    gDisableStructs[battler].stockpileDef = 0;
    gDisableStructs[battler].stockpileSpDef = 0;
    for (j = 0; j < NUM_BATTLE_STATS; j++)
    {
        if (gBattleMons[battler].statStages[j] != DEFAULT_STAT_STAGE)
            ret = TRUE; // returns TRUE if any stat was reset

        gBattleMons[battler].statStages[j] = DEFAULT_STAT_STAGE;
    }

    return ret;
}

// Haze
static void Cmd_normalisebuffs(void)
{
    CMD_ARGS();

    s32 i;

    for (i = 0; i < gBattlersCount; i++)
        TryResetBattlerStatChanges(i);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setbide(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerAttacker].status2 |= STATUS2_MULTIPLETURNS;
    gLockedMoves[gBattlerAttacker] = gCurrentMove;
    gBideDmg[gBattlerAttacker] = 0;
    gBattleMons[gBattlerAttacker].status2 |= STATUS2_BIDE_TURN(2);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_twoturnmoveschargestringandanimation(void)
{
    CMD_ARGS(const u8 *animationThenStringPtr);

    gBattleScripting.savedStringId = LOHALF(gMovesInfo[gCurrentMove].argument);
    if (B_UPDATED_MOVE_DATA < GEN_5 || MoveHasChargeTurnAdditionalEffect(gCurrentMove))
        gBattlescriptCurrInstr = cmd->animationThenStringPtr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setmultihitcounter(void)
{
    CMD_ARGS(u8 value);

    if (cmd->value)
    {
        gMultiHitCounter = cmd->value;
    }
    else
    {
        if (GetBattlerAbility(gBattlerAttacker) == ABILITY_SKILL_LINK)
        {
            gMultiHitCounter = 5;
        }
        else
        {
            // WARNING: These seem to be unused, see SetRandomMultiHitCounter.
            if (B_MULTI_HIT_CHANCE >= GEN_5)
                // 35%: 2 hits, 35%: 3 hits, 15% 4 hits, 15% 5 hits.
                gMultiHitCounter = RandomWeighted(RNG_HITS, 0, 0, 7, 7, 3, 3);
            else
                // 37.5%: 2 hits, 37.5%: 3 hits, 12.5% 4 hits, 12.5% 5 hits.
                gMultiHitCounter = RandomWeighted(RNG_HITS, 0, 0, 3, 3, 1, 1);
        }
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_initmultihitstring(void)
{
    CMD_ARGS();

    PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_forcerandomswitch(void)
{
    CMD_ARGS(const u8 *failInstr);

    s32 i;
    s32 battler1PartyId = 0;
    s32 battler2PartyId = 0;

    s32 firstMonId;
    s32 lastMonId = 0; // + 1
    struct Pokemon *party = NULL;
    u8 validMons[PARTY_SIZE];
    s32 validMonsCount = 0;

    bool32 redCardForcedSwitch = FALSE;

    // Red card checks against wild pokemon. If we have reached here, the player has a mon to switch into
    // Red card swaps attacker with target to get the animation correct, so here we check attacker which is really the target. Thanks GF...
    if (gBattleScripting.switchCase == B_SWITCH_RED_CARD
      && !(gBattleTypeFlags & BATTLE_TYPE_TRAINER)
      && GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT)   // Check opponent's red card activating
    {
        if (!WILD_DOUBLE_BATTLE)
        {
            // Wild mon with red card will end single battle
            gBattlescriptCurrInstr = BattleScript_RoarSuccessEndBattle;
            return;
        }
        else
        {
            // Wild double battle, wild mon red card activation on player
            if (IS_WHOLE_SIDE_ALIVE(gBattlerTarget))
            {
                // Both player's battlers are alive
                redCardForcedSwitch = FALSE;
            }
            else
            {
                // Player has only one mon alive -> force red card switch before manually switching to other mon
                redCardForcedSwitch = TRUE;
            }
        }
    }

    // Swapping pokemon happens in:
    // trainer battles
    // wild double battles when an opposing pokemon uses it against one of the two alive player mons
    // wild double battle when a player pokemon uses it against its partner
    if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        || (WILD_DOUBLE_BATTLE
            && GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT
            && GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER
            && IS_WHOLE_SIDE_ALIVE(gBattlerTarget))
        || (WILD_DOUBLE_BATTLE
            && GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER
            && GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
        || redCardForcedSwitch
       )
    {
        party = GetBattlerParty(gBattlerTarget);

        if (BATTLE_TWO_VS_ONE_OPPONENT && GetBattlerSide(gBattlerTarget) == B_SIDE_OPPONENT)
        {
            firstMonId = 0;
            lastMonId = 6;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerTarget)];
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER && gBattleTypeFlags & BATTLE_TYPE_LINK)
            || (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER && gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            || (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
        {
            if ((gBattlerTarget & BIT_FLANK) != B_FLANK_LEFT)
            {
                firstMonId = PARTY_SIZE / 2;
                lastMonId = PARTY_SIZE;
            }
            else
            {
                firstMonId = 0;
                lastMonId = PARTY_SIZE / 2;
            }
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerTarget)];
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
                 || (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK))
        {
            if (GetLinkTrainerFlankId(GetBattlerMultiplayerId(gBattlerTarget)) == B_FLANK_RIGHT)
            {
                firstMonId = PARTY_SIZE / 2;
                lastMonId = PARTY_SIZE;
            }
            else
            {
                firstMonId = 0;
                lastMonId = PARTY_SIZE / 2;
            }
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerTarget)];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
            {
                firstMonId = 0;
                lastMonId = PARTY_SIZE;
            }
            else
            {
                if ((gBattlerTarget & BIT_FLANK) != B_FLANK_LEFT)
                {
                    firstMonId = PARTY_SIZE / 2;
                    lastMonId = PARTY_SIZE;
                }
                else
                {
                    firstMonId = 0;
                    lastMonId = PARTY_SIZE / 2;
                }
            }
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerTarget)];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            firstMonId = 0;
            lastMonId = PARTY_SIZE;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerTarget)];
        }
        else
        {
            firstMonId = 0;
            lastMonId = PARTY_SIZE;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget]; // there is only one Pokémon out in single battles
            battler1PartyId = gBattlerPartyIndexes[gBattlerTarget];
        }

        for (i = firstMonId; i < lastMonId; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0
             && i != battler1PartyId
             && i != battler2PartyId)
             {
                 validMons[validMonsCount++] = i;
             }
        }

        if (validMonsCount == 0)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            *(gBattleStruct->battlerPartyIndexes + gBattlerTarget) = gBattlerPartyIndexes[gBattlerTarget];
            gBattlescriptCurrInstr = BattleScript_RoarSuccessSwitch;
            gBattleStruct->forcedSwitch |= gBitTable[gBattlerTarget];
            *(gBattleStruct->monToSwitchIntoId + gBattlerTarget) = validMons[RandomUniform(RNG_FORCE_RANDOM_SWITCH, 0, validMonsCount - 1)];

            if (!IsMultiBattle())
                SwitchPartyOrder(gBattlerTarget);

            if ((gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                || (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI)
                || (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                || (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                SwitchPartyOrderLinkMulti(gBattlerTarget, i, 0);
                SwitchPartyOrderLinkMulti(BATTLE_PARTNER(gBattlerTarget), i, 1);
            }

            if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                SwitchPartyOrderInGameMulti(gBattlerTarget, i);
        }
    }
    else
    {
        // In normal wild doubles, Roar will always fail if the user's level is less than the target's.
        if (gBattleMons[gBattlerAttacker].level >= gBattleMons[gBattlerTarget].level)
            gBattlescriptCurrInstr = BattleScript_RoarSuccessEndBattle;
        else
            gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_tryconversiontypechange(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 validMoves = 0;
    u8 moveChecked = 0;
    u8 moveType = 0;

    if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_TERA)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
        return;
    }

    if (B_UPDATED_CONVERSION >= GEN_6)
    {
        // Changes user's type to its first move's type
        for (moveChecked = 0; moveChecked < MAX_MON_MOVES; moveChecked++)
        {
            if (gBattleMons[gBattlerAttacker].moves[moveChecked] != MOVE_NONE)
            {
                moveType = gMovesInfo[gBattleMons[gBattlerAttacker].moves[moveChecked]].type;
                break;
            }
        }
        if (IS_BATTLER_OF_TYPE(gBattlerAttacker, moveType))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            SET_BATTLER_TYPE(gBattlerAttacker, moveType);
            PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
    else
    {
        // Randomly changes user's type to one of its moves' type
        while (validMoves < MAX_MON_MOVES)
        {
            if (gBattleMons[gBattlerAttacker].moves[validMoves] == MOVE_NONE)
                break;

            validMoves++;
        }

        for (moveChecked = 0; moveChecked < validMoves; moveChecked++)
        {
            moveType = gMovesInfo[gBattleMons[gBattlerAttacker].moves[moveChecked]].type;

            if (moveType == TYPE_MYSTERY)
            {
                if (IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
                    moveType = TYPE_GHOST;
                else
                    moveType = TYPE_NORMAL;
            }
            if (moveType != gBattleMons[gBattlerAttacker].types[0]
                && moveType != gBattleMons[gBattlerAttacker].types[1]
                && moveType != gBattleMons[gBattlerAttacker].types[2])
            {
                break;
            }
        }

        if (moveChecked == validMoves)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            do
            {
                while ((moveChecked = MOD(Random(), MAX_MON_MOVES)) >= validMoves);

                moveType = gMovesInfo[gBattleMons[gBattlerAttacker].moves[moveChecked]].type;

                if (moveType == TYPE_MYSTERY)
                {
                    if (IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
                        moveType = TYPE_GHOST;
                    else
                        moveType = TYPE_NORMAL;
                }
            }
            while (moveType == gBattleMons[gBattlerAttacker].types[0] || moveType == gBattleMons[gBattlerAttacker].types[1] || moveType == gBattleMons[gBattlerAttacker].types[2]);

            SET_BATTLER_TYPE(gBattlerAttacker, moveType);
            PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);

            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
}

static void Cmd_givepaydaymoney(void)
{
    CMD_ARGS();

    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)) && gPaydayMoney != 0)
    {
        u32 bonusMoney = gPaydayMoney * gBattleStruct->moneyMultiplier;
        AddMoney(&gSaveBlock1Ptr->money, bonusMoney);

        PREPARE_HWORD_NUMBER_BUFFER(gBattleTextBuff1, 5, bonusMoney)

        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_PrintPayDayMoneyString;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setlightscreen(void)
{
    CMD_ARGS();

    if (gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_LIGHTSCREEN)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SIDE_STATUS_FAILED;
    }
    else
    {
        gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_LIGHTSCREEN;
        if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[GetBattlerSide(gBattlerAttacker)].lightscreenTimer = 8;
        else
            gSideTimers[GetBattlerSide(gBattlerAttacker)].lightscreenTimer = 5;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].lightscreenBattlerId = gBattlerAttacker;

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMonsInBattle(BATTLE_ALIVE_SIDE, gBattlerAttacker) == 2)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_LIGHTSCREEN_DOUBLE;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_LIGHTSCREEN_SINGLE;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_tryKO(void)
{
    CMD_ARGS(const u8 *failInstr);

    bool32 lands = FALSE;
    u32 holdEffect = GetBattlerHoldEffect(gBattlerTarget, TRUE);
    u16 targetAbility = GetBattlerAbility(gBattlerTarget);

    // Dynamaxed Pokemon cannot be hit by OHKO moves.
    if ((GetActiveGimmick(gBattlerTarget) == GIMMICK_DYNAMAX))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_KO_UNAFFECTED;
        gBattlescriptCurrInstr = cmd->failInstr;
        return;
    }

    gPotentialItemEffectBattler = gBattlerTarget;
    if (holdEffect == HOLD_EFFECT_FOCUS_BAND
        && (Random() % 100) < GetBattlerHoldEffectParam(gBattlerTarget))
    {
        gSpecialStatuses[gBattlerTarget].focusBanded = TRUE;
        RecordItemEffectBattle(gBattlerTarget, holdEffect);
    }
    else if (holdEffect == HOLD_EFFECT_FOCUS_SASH && BATTLER_MAX_HP(gBattlerTarget))
    {
        gSpecialStatuses[gBattlerTarget].focusSashed = TRUE;
        RecordItemEffectBattle(gBattlerTarget, holdEffect);
    }

    if (targetAbility == ABILITY_STURDY)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gLastUsedAbility = ABILITY_STURDY;
        gBattlescriptCurrInstr = BattleScript_SturdyPreventsOHKO;
        gBattlerAbility = gBattlerTarget;
    }
    else
    {
        if ((((gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS)
                && gDisableStructs[gBattlerTarget].battlerWithSureHit == gBattlerAttacker)
            || GetBattlerAbility(gBattlerAttacker) == ABILITY_NO_GUARD
            || targetAbility == ABILITY_NO_GUARD)
            && gBattleMons[gBattlerAttacker].level >= gBattleMons[gBattlerTarget].level)
        {
            lands = TRUE;
        }
        else
        {
            u16 odds = gMovesInfo[gCurrentMove].accuracy + (gBattleMons[gBattlerAttacker].level - gBattleMons[gBattlerTarget].level);
            if (B_SHEER_COLD_ACC >= GEN_7 && gCurrentMove == MOVE_SHEER_COLD && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_ICE))
                odds -= 10;
            if (RandomPercentage(RNG_ACCURACY, odds) && gBattleMons[gBattlerAttacker].level >= gBattleMons[gBattlerTarget].level)
                lands = TRUE;
        }

        if (lands)
        {
            if (gProtectStructs[gBattlerTarget].endured)
            {
                gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - 1;
                gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED;
            }
            else if (gSpecialStatuses[gBattlerTarget].focusBanded || gSpecialStatuses[gBattlerTarget].focusSashed)
            {
                gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - 1;
                gMoveResultFlags |= MOVE_RESULT_FOE_HUNG_ON;
                gLastUsedItem = gBattleMons[gBattlerTarget].item;
            }
            else if (B_AFFECTION_MECHANICS == TRUE && gSpecialStatuses[gBattlerTarget].affectionEndured)
            {
                gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - 1;
                gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED_AFFECTION;
            }
            else
            {
                gBattleMoveDamage = gBattleMons[gBattlerTarget].hp;
                gMoveResultFlags |= MOVE_RESULT_ONE_HIT_KO;
            }
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            if (gBattleMons[gBattlerAttacker].level >= gBattleMons[gBattlerTarget].level)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_KO_MISS;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_KO_UNAFFECTED;
            gBattlescriptCurrInstr = cmd->failInstr;
        }
    }
}

// Super Fang
static void Cmd_damagetohalftargethp(void)
{
    CMD_ARGS();

    gBattleMoveDamage = GetNonDynamaxHP(gBattlerTarget) / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_unused_95(void)
{
}

static void Cmd_unused_96(void)
{
}

static void Cmd_tryinfatuating(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (GetBattlerAbility(gBattlerTarget) == ABILITY_OBLIVIOUS)
    {
        gBattlescriptCurrInstr = BattleScript_NotAffectedAbilityPopUp;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        RecordAbilityBattle(gBattlerTarget, ABILITY_OBLIVIOUS);
    }
    else
    {
        if (gBattleMons[gBattlerTarget].status2 & STATUS2_INFATUATION
            || !AreBattlersOfOppositeGender(gBattlerAttacker, gBattlerTarget))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gBattleMons[gBattlerTarget].status2 |= STATUS2_INFATUATED_WITH(gBattlerAttacker);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
}

static void Cmd_updatestatusicon(void)
{
    CMD_ARGS(u8 battler);
    u32 battler;

    if (gBattleControllerExecFlags)
        return;

    if (cmd->battler != BS_ATTACKER_WITH_PARTNER)
    {
        battler = GetBattlerForBattleScript(cmd->battler);
        BtlController_EmitStatusIconUpdate(battler, BUFFER_A, gBattleMons[battler].status1, gBattleMons[battler].status2);
        MarkBattlerForControllerExec(battler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        battler = gBattlerAttacker;
        if (!(gAbsentBattlerFlags & gBitTable[battler]))
        {
            BtlController_EmitStatusIconUpdate(battler, BUFFER_A, gBattleMons[battler].status1, gBattleMons[battler].status2);
            MarkBattlerForControllerExec(battler);
        }
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        {
            battler = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gBattlerAttacker)));
            if (!(gAbsentBattlerFlags & gBitTable[battler]))
            {
                BtlController_EmitStatusIconUpdate(battler, BUFFER_A, gBattleMons[battler].status1, gBattleMons[battler].status2);
                MarkBattlerForControllerExec(battler);
            }
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setmist(void)
{
    CMD_ARGS();

    if (gSideTimers[GetBattlerSide(gBattlerAttacker)].mistTimer)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MIST_FAILED;
    }
    else
    {
        gSideTimers[GetBattlerSide(gBattlerAttacker)].mistTimer = 5;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].mistBattlerId = gBattlerAttacker;
        gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_MIST;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_MIST;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setfocusenergy(void)
{
    CMD_ARGS(u8 battler);
    u8 battler = GetBattlerForBattleScript(cmd->battler);

    if ((gMovesInfo[gCurrentMove].effect == EFFECT_DRAGON_CHEER && (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE) || (gAbsentBattlerFlags & gBitTable[battler])))
     || gBattleMons[battler].status2 & STATUS2_FOCUS_ENERGY_ANY)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FOCUS_ENERGY_FAILED;
    }
    else if (gMovesInfo[gCurrentMove].effect == EFFECT_DRAGON_CHEER && !IS_BATTLER_OF_TYPE(battler, TYPE_DRAGON))
    {
        gBattleMons[battler].status2 |= STATUS2_DRAGON_CHEER;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_GETTING_PUMPED;
    }
    else
    {
        gBattleMons[battler].status2 |= STATUS2_FOCUS_ENERGY;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_GETTING_PUMPED;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_transformdataexecution(void)
{
    CMD_ARGS();

    gChosenMove = MOVE_UNAVAILABLE;
    gBattlescriptCurrInstr = cmd->nextInstr;
    if (gBattleMons[gBattlerTarget].status2 & STATUS2_TRANSFORMED
        || gBattleStruct->illusion[gBattlerTarget].on
        || gStatuses3[gBattlerTarget] & STATUS3_SEMI_INVULNERABLE)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TRANSFORM_FAILED;
    }
    else
    {
        s32 i;
        u8 *battleMonAttacker, *battleMonTarget;
        u8 timesGotHit;

        gBattleMons[gBattlerAttacker].status2 |= STATUS2_TRANSFORMED;
        gDisableStructs[gBattlerAttacker].disabledMove = MOVE_NONE;
        gDisableStructs[gBattlerAttacker].disableTimer = 0;
        gDisableStructs[gBattlerAttacker].transformedMonPersonality = gBattleMons[gBattlerTarget].personality;
        gDisableStructs[gBattlerAttacker].transformedMonShininess = gBattleMons[gBattlerTarget].isShiny;
        gDisableStructs[gBattlerAttacker].mimickedMoves = 0;
        gDisableStructs[gBattlerAttacker].usedMoves = 0;

        timesGotHit = gBattleStruct->timesGotHit[GetBattlerSide(gBattlerTarget)][gBattlerPartyIndexes[gBattlerTarget]];
        gBattleStruct->timesGotHit[GetBattlerSide(gBattlerAttacker)][gBattlerPartyIndexes[gBattlerAttacker]] = timesGotHit;

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerTarget].species)

        battleMonAttacker = (u8 *)(&gBattleMons[gBattlerAttacker]);
        battleMonTarget = (u8 *)(&gBattleMons[gBattlerTarget]);

        for (i = 0; i < offsetof(struct BattlePokemon, pp); i++)
            battleMonAttacker[i] = battleMonTarget[i];

        gBattleStruct->overwrittenAbilities[gBattlerAttacker] = GetBattlerAbility(gBattlerTarget);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gMovesInfo[gBattleMons[gBattlerAttacker].moves[i]].pp < 5)
                gBattleMons[gBattlerAttacker].pp[i] = gMovesInfo[gBattleMons[gBattlerAttacker].moves[i]].pp;
            else
                gBattleMons[gBattlerAttacker].pp[i] = 5;
        }

        // update AI knowledge
        RecordAllMoves(gBattlerAttacker);
        RecordAbilityBattle(gBattlerAttacker, gBattleMons[gBattlerAttacker].ability);

        BtlController_EmitResetActionMoveSelection(gBattlerAttacker, BUFFER_A, RESET_MOVE_SELECTION);
        MarkBattlerForControllerExec(gBattlerAttacker);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TRANSFORMED;
    }
}

static void Cmd_setsubstitute(void)
{
    CMD_ARGS();

    u32 factor = gMovesInfo[gCurrentMove].effect == EFFECT_SHED_TAIL ? 2 : 4;
    u32 hp;

    if (factor == 2)
        hp = (GetNonDynamaxMaxHP(gBattlerAttacker)+1) / factor; // shed tail rounds up
    else
        hp = GetNonDynamaxMaxHP(gBattlerAttacker) / factor; // one bit value will only work for Pokémon which max hp can go to 1020(which is more than possible in games)

    if (hp == 0)
        hp = 1;

    if (gBattleMons[gBattlerAttacker].hp <= hp)
    {
        gBattleMoveDamage = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SUBSTITUTE_FAILED;
    }
    else
    {
        gBattleMoveDamage = hp;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattleMons[gBattlerAttacker].status2 |= STATUS2_SUBSTITUTE;
        gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_WRAPPED;
        gDisableStructs[gBattlerAttacker].substituteHP = gBattleMoveDamage;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_SUBSTITUTE;
        gHitMarker |= HITMARKER_IGNORE_SUBSTITUTE;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_mimicattackcopy(void)
{
    CMD_ARGS(const u8 *failInstr);

    if ((gMovesInfo[gLastMoves[gBattlerTarget]].mimicBanned)
        || (gBattleMons[gBattlerAttacker].status2 & STATUS2_TRANSFORMED)
        || gLastMoves[gBattlerTarget] == MOVE_NONE
        || gLastMoves[gBattlerTarget] == MOVE_UNAVAILABLE)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        int i;

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gBattlerAttacker].moves[i] == gLastMoves[gBattlerTarget])
                break;
        }

        if (i == MAX_MON_MOVES)
        {
            gChosenMove = 0xFFFF;
            gBattleMons[gBattlerAttacker].moves[gCurrMovePos] = gLastMoves[gBattlerTarget];
            if (gMovesInfo[gLastMoves[gBattlerTarget]].pp < 5)
                gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = gMovesInfo[gLastMoves[gBattlerTarget]].pp;
            else
                gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = 5;

            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastMoves[gBattlerTarget])

            gDisableStructs[gBattlerAttacker].mimickedMoves |= gBitTable[gCurrMovePos];
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
    }
}

static bool32 InvalidMetronomeMove(u32 move)
{
    return gMovesInfo[move].effect == EFFECT_PLACEHOLDER
        || gMovesInfo[move].metronomeBanned;
}

static void Cmd_metronome(void)
{
    CMD_ARGS();

#if B_METRONOME_MOVES >= GEN_9
    u32 moveCount = MOVES_COUNT_GEN9;
#elif B_METRONOME_MOVES >= GEN_8
    u32 moveCount = MOVES_COUNT_GEN8;
#elif B_METRONOME_MOVES >= GEN_7
    u32 moveCount = MOVES_COUNT_GEN7;
#elif B_METRONOME_MOVES >= GEN_6
    u32 moveCount = MOVES_COUNT_GEN6;
#elif B_METRONOME_MOVES >= GEN_5
    u32 moveCount = MOVES_COUNT_GEN5;
#elif B_METRONOME_MOVES >= GEN_4
    u32 moveCount = MOVES_COUNT_GEN4;
#elif B_METRONOME_MOVES >= GEN_3
    u32 moveCount = MOVES_COUNT_GEN3;
#elif B_METRONOME_MOVES >= GEN_2
    u32 moveCount = MOVES_COUNT_GEN2;
#else
    u32 moveCount = MOVES_COUNT_GEN1;
#endif

    gCurrentMove = RandomUniformExcept(RNG_METRONOME, 1, moveCount - 1, InvalidMetronomeMove);
    gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
    SetAtkCancellerForCalledMove();
    gBattlescriptCurrInstr = GET_MOVE_BATTLESCRIPT(gCurrentMove);
    gBattlerTarget = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
}

static void Cmd_dmgtolevel(void)
{
    CMD_ARGS();

    gBattleMoveDamage = gBattleMons[gBattlerAttacker].level;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_psywavedamageeffect(void)
{
    CMD_ARGS();

    s32 randDamage = B_PSYWAVE_DMG >= GEN_6 ? (Random() % 101) : ((Random() % 11) * 10);
    gBattleMoveDamage = gBattleMons[gBattlerAttacker].level * (randDamage + 50) / 100;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_counterdamagecalculator(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
    u8 sideTarget = GetBattlerSide(gProtectStructs[gBattlerAttacker].physicalBattlerId);

    if (gProtectStructs[gBattlerAttacker].physicalDmg
        && sideAttacker != sideTarget
        && gBattleMons[gProtectStructs[gBattlerAttacker].physicalBattlerId].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBattlerAttacker].physicalDmg * 2;

        if (IsAffectedByFollowMe(gBattlerAttacker, sideTarget, gCurrentMove))
            gBattlerTarget = gSideTimers[sideTarget].followmeTarget;
        else
            gBattlerTarget = gProtectStructs[gBattlerAttacker].physicalBattlerId;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

// A copy of Cmd with the physical -> special field changes
static void Cmd_mirrorcoatdamagecalculator(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
    u8 sideTarget = GetBattlerSide(gProtectStructs[gBattlerAttacker].specialBattlerId);

    if (gProtectStructs[gBattlerAttacker].specialDmg
        && sideAttacker != sideTarget
        && gBattleMons[gProtectStructs[gBattlerAttacker].specialBattlerId].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBattlerAttacker].specialDmg * 2;

        if (IsAffectedByFollowMe(gBattlerAttacker, sideTarget, gCurrentMove))
            gBattlerTarget = gSideTimers[sideTarget].followmeTarget;
        else
            gBattlerTarget = gProtectStructs[gBattlerAttacker].specialBattlerId;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_disablelastusedattack(void)
{
    CMD_ARGS(const u8 *failInstr);

    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[gBattlerTarget].moves[i] == gLastMoves[gBattlerTarget])
            break;
    }
    if (gDisableStructs[gBattlerTarget].disabledMove == MOVE_NONE
        && i != MAX_MON_MOVES && gBattleMons[gBattlerTarget].pp[i] != 0)
    {
        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerTarget].moves[i])

        gDisableStructs[gBattlerTarget].disabledMove = gBattleMons[gBattlerTarget].moves[i];
        if (B_DISABLE_TURNS >= GEN_5)
            gDisableStructs[gBattlerTarget].disableTimer = 4;
        else if (B_DISABLE_TURNS >= GEN_4)
            gDisableStructs[gBattlerTarget].disableTimer = (Random() & 3) + 4; // 4-7 turns
        else
            gDisableStructs[gBattlerTarget].disableTimer = (Random() & 3) + 2; // 2-5 turns
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_trysetencore(void)
{
    CMD_ARGS(const u8 *failInstr);

    s32 i;

    if (IsMaxMove(gLastMoves[gBattlerTarget]) && !(GetActiveGimmick(gBattlerTarget) == GIMMICK_DYNAMAX))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gBattlerTarget].moves[i] == gBattleStruct->dynamax.baseMoves[gBattlerTarget])
                break;
        }
    }
    else
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gBattlerTarget].moves[i] == gLastMoves[gBattlerTarget])
                break;
        }
    }

    if ((gMovesInfo[gLastMoves[gBattlerTarget]].encoreBanned)
     || gLastMoves[gBattlerTarget] == MOVE_NONE
     || gLastMoves[gBattlerTarget] == MOVE_UNAVAILABLE)
    {
        i = MAX_MON_MOVES;
    }

    if (gDisableStructs[gBattlerTarget].encoredMove == MOVE_NONE
        && i != MAX_MON_MOVES && gBattleMons[gBattlerTarget].pp[i] != 0)
    {
        gDisableStructs[gBattlerTarget].encoredMove = gBattleMons[gBattlerTarget].moves[i];
        gDisableStructs[gBattlerTarget].encoredMovePos = i;
        // Encore always lasts 3 turns, but we need to account for a scenario where Encore changes the move during the same turn.
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
            gDisableStructs[gBattlerTarget].encoreTimer = 4;
        else
            gDisableStructs[gBattlerTarget].encoreTimer = 3;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_painsplitdmgcalc(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (!(DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove)))
    {
        s32 hpDiff = (gBattleMons[gBattlerAttacker].hp + GetNonDynamaxHP(gBattlerTarget)) / 2;
        s32 painSplitHp = gBattleMoveDamage = GetNonDynamaxHP(gBattlerTarget) - hpDiff;
        u8 *storeLoc = (void *)(&gBattleScripting.painSplitHp);

        storeLoc[0] = (painSplitHp);
        storeLoc[1] = (painSplitHp & 0x0000FF00) >> 8;
        storeLoc[2] = (painSplitHp & 0x00FF0000) >> 16;
        storeLoc[3] = (painSplitHp & 0xFF000000) >> 24;

        gBattleMoveDamage = gBattleMons[gBattlerAttacker].hp - hpDiff;
        gSpecialStatuses[gBattlerTarget].shellBellDmg = IGNORE_SHELL_BELL;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

// Conversion 2
static void Cmd_settypetorandomresistance(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gLastLandedMoves[gBattlerAttacker] == MOVE_NONE
     || gLastLandedMoves[gBattlerAttacker] == MOVE_UNAVAILABLE)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (gBattleMoveEffects[gMovesInfo[gLastLandedMoves[gBattlerAttacker]].effect].twoTurnEffect
            && gBattleMons[gLastHitBy[gBattlerAttacker]].status2 & STATUS2_MULTIPLETURNS)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_TERA)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (gLastHitByType[gBattlerAttacker] == TYPE_STELLAR || gLastHitByType[gBattlerAttacker] == TYPE_MYSTERY)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        u32 i, resistTypes = 0;
        u32 hitByType = gLastHitByType[gBattlerAttacker];

        for (i = 0; i < NUMBER_OF_MON_TYPES; i++) // Find all types that resist.
        {
            switch (GetTypeModifier(hitByType, i))
            {
            case UQ_4_12(0):
            case UQ_4_12(0.5):
                resistTypes |= gBitTable[i];
                break;
            }
        }

        while (resistTypes != 0)
        {
            i = Random() % NUMBER_OF_MON_TYPES;
            if (resistTypes & gBitTable[i])
            {
                if (IS_BATTLER_OF_TYPE(gBattlerAttacker, i))
                {
                    resistTypes &= ~(gBitTable[i]); // Type resists, but the user is already of this type.
                }
                else
                {
                    SET_BATTLER_TYPE(gBattlerAttacker, i);
                    PREPARE_TYPE_BUFFER(gBattleTextBuff1, i);
                    gBattlescriptCurrInstr = cmd->nextInstr;
                    return;
                }
            }
        }

        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_setalwayshitflag(void)
{
    CMD_ARGS();

    gStatuses3[gBattlerTarget] &= ~STATUS3_ALWAYS_HITS;
    gStatuses3[gBattlerTarget] |= STATUS3_ALWAYS_HITS_TURN(2);
    gDisableStructs[gBattlerTarget].battlerWithSureHit = gBattlerAttacker;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Sketch
static void Cmd_copymovepermanently(void)
{
    CMD_ARGS(const u8 *failInstr);

    gChosenMove = MOVE_UNAVAILABLE;

    if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_TRANSFORMED)
        && gLastPrintedMoves[gBattlerTarget] != MOVE_UNAVAILABLE
        && !gMovesInfo[gLastPrintedMoves[gBattlerTarget]].sketchBanned)
    {
        s32 i;

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gBattlerAttacker].moves[i] == MOVE_SKETCH)
                continue;
            if (gBattleMons[gBattlerAttacker].moves[i] == gLastPrintedMoves[gBattlerTarget])
                break;
        }

        if (i != MAX_MON_MOVES)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else // sketch worked
        {
            struct MovePpInfo movePpData;

            gBattleMons[gBattlerAttacker].moves[gCurrMovePos] = gLastPrintedMoves[gBattlerTarget];
            gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = gMovesInfo[gLastPrintedMoves[gBattlerTarget]].pp;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                movePpData.moves[i] = gBattleMons[gBattlerAttacker].moves[i];
                movePpData.pp[i] = gBattleMons[gBattlerAttacker].pp[i];
            }
            movePpData.ppBonuses = gBattleMons[gBattlerAttacker].ppBonuses;

            BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_MOVES_PP_BATTLE, 0, sizeof(movePpData), &movePpData);
            MarkBattlerForControllerExec(gBattlerAttacker);

            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastPrintedMoves[gBattlerTarget])

            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_trychoosesleeptalkmove(void)
{
    CMD_ARGS(const u8 *failInstr);

    u32 i, unusableMovesBits = 0, movePosition;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gMovesInfo[gBattleMons[gBattlerAttacker].moves[i]].sleepTalkBanned
            || gBattleMoveEffects[gMovesInfo[gBattleMons[gBattlerAttacker].moves[i]].effect].twoTurnEffect)
        {
            unusableMovesBits |= gBitTable[i];
        }
    }

    unusableMovesBits = CheckMoveLimitations(gBattlerAttacker, unusableMovesBits, ~(MOVE_LIMITATION_PP | MOVE_LIMITATION_CHOICE_ITEM));
    if (unusableMovesBits == ALL_MOVES_MASK) // all 4 moves cannot be chosen
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else // at least one move can be chosen
    {
        // Set Sleep Talk as used move, so it works with Last Resort.
        gDisableStructs[gBattlerAttacker].usedMoves |= gBitTable[gCurrMovePos];
        do
        {
            movePosition = MOD(Random(), MAX_MON_MOVES);
        } while ((gBitTable[movePosition] & unusableMovesBits));

        if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE && !IS_MOVE_STATUS(gBattleMons[gBattlerAttacker].moves[movePosition]))
        {
            gBattleStruct->zmove.baseMoves[gBattlerAttacker] = gBattleMons[gBattlerAttacker].moves[movePosition];
            gCalledMove = GetTypeBasedZMove(gBattleMons[gBattlerAttacker].moves[movePosition]);
        }
        else
        {
            gCalledMove = gBattleMons[gBattlerAttacker].moves[movePosition];
        }
        gCurrMovePos = movePosition;
        gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
        gBattlerTarget = GetMoveTarget(gCalledMove, NO_TARGET_OVERRIDE);
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_setdestinybond(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerAttacker].status2 |= STATUS2_DESTINY_BOND;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void TrySetDestinyBondToHappen(void)
{
    u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
    u8 sideTarget = GetBattlerSide(gBattlerTarget);
    if (gBattleMons[gBattlerTarget].status2 & STATUS2_DESTINY_BOND
        && sideAttacker != sideTarget
        && !(gHitMarker & HITMARKER_GRUDGE))
    {
        gHitMarker |= HITMARKER_DESTINYBOND;
    }
}

static void Cmd_trysetdestinybondtohappen(void)
{
    CMD_ARGS();

    TrySetDestinyBondToHappen();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_settailwind(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 side = GetBattlerSide(gBattlerAttacker);

    if (!(gSideStatuses[side] & SIDE_STATUS_TAILWIND))
    {
        gSideStatuses[side] |= SIDE_STATUS_TAILWIND;
        gSideTimers[side].tailwindBattlerId = gBattlerAttacker;
        gSideTimers[side].tailwindTimer = B_TAILWIND_TURNS >= GEN_5 ? 4 : 3;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_tryspiteppreduce(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gLastMoves[gBattlerTarget] != MOVE_NONE
     && gLastMoves[gBattlerTarget] != MOVE_UNAVAILABLE)
    {
        s32 i;

        // Get move slot to reduce PP.
        if (IsMaxMove(gLastMoves[gBattlerTarget]))
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gBattleStruct->dynamax.baseMoves[gBattlerTarget] == gBattleMons[gBattlerTarget].moves[i])
                    break;
            }
        }
        else
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gLastMoves[gBattlerTarget] == gBattleMons[gBattlerTarget].moves[i])
                    break;
            }
        }

        if (i != MAX_MON_MOVES && gBattleMons[gBattlerTarget].pp[i] > (B_CAN_SPITE_FAIL >= GEN_4 ? 0 : 1))
        {
            s32 ppToDeduct = B_PP_REDUCED_BY_SPITE >= GEN_4 ? 4 : (Random() & 3) + 2;
            // G-Max Depletion only deducts 2 PP.
            if (IsMaxMove(gCurrentMove) && gMovesInfo[gCurrentMove].argument == MAX_EFFECT_SPITE)
                ppToDeduct = 2;

            if (gBattleMons[gBattlerTarget].pp[i] < ppToDeduct)
                ppToDeduct = gBattleMons[gBattlerTarget].pp[i];

            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastMoves[gBattlerTarget])

            ConvertIntToDecimalStringN(gBattleTextBuff2, ppToDeduct, STR_CONV_MODE_LEFT_ALIGN, 1);

            PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 1, ppToDeduct)

            gBattleMons[gBattlerTarget].pp[i] -= ppToDeduct;

            // if (MOVE_IS_PERMANENT(gBattlerTarget, i)), but backwards
            if (!(gDisableStructs[gBattlerTarget].mimickedMoves & gBitTable[i])
                && !(gBattleMons[gBattlerTarget].status2 & STATUS2_TRANSFORMED))
            {
                BtlController_EmitSetMonData(gBattlerTarget, BUFFER_A, REQUEST_PPMOVE1_BATTLE + i, 0, sizeof(gBattleMons[gBattlerTarget].pp[i]), &gBattleMons[gBattlerTarget].pp[i]);
                MarkBattlerForControllerExec(gBattlerTarget);
            }

            gBattlescriptCurrInstr = cmd->nextInstr;

            // Don't cut off Sky Drop if pp is brought to zero.
            if (gBattleMons[gBattlerTarget].pp[i] == 0 && gBattleStruct->skyDropTargets[gBattlerTarget] == 0xFF)
                CancelMultiTurnMoves(gBattlerTarget);
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_healpartystatus(void)
{
    CMD_ARGS();

    u32 zero = 0;
    u32 partner = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gBattlerAttacker)));
    u8 toHeal = 0;

    if (gCurrentMove == MOVE_HEAL_BELL)
    {
        struct Pokemon *party = GetBattlerParty(gBattlerAttacker);
        s32 i;

        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_BELL;

        if (GetBattlerAbility(gBattlerAttacker) != ABILITY_SOUNDPROOF
         || B_HEAL_BELL_SOUNDPROOF == GEN_5 || B_HEAL_BELL_SOUNDPROOF >= GEN_8)
        {
            gBattleMons[gBattlerAttacker].status1 = 0;
            gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;
        }
        else
        {
            RecordAbilityBattle(gBattlerAttacker, gBattleMons[gBattlerAttacker].ability);
            gBattleCommunication[MULTISTRING_CHOOSER] |= B_MSG_BELL_SOUNDPROOF_ATTACKER;
        }

        gBattleScripting.battler = partner;

        if (IsBattlerAlive(partner))
        {
            if (GetBattlerAbility(partner) != ABILITY_SOUNDPROOF || B_HEAL_BELL_SOUNDPROOF == GEN_5)
            {
                gBattleMons[partner].status1 = 0;
                gBattleMons[partner].status2 &= ~STATUS2_NIGHTMARE;
            }
            else
            {
                RecordAbilityBattle(partner, gBattleMons[partner].ability);
                gBattleCommunication[MULTISTRING_CHOOSER] |= B_MSG_BELL_SOUNDPROOF_PARTNER;
            }
        }

        // Because the above MULTISTRING_CHOOSER are ORd, if both are set then it will be B_MSG_BELL_BOTH_SOUNDPROOF

        for (i = 0; i < PARTY_SIZE; i++)
        {
            u16 species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
            u8 abilityNum = GetMonData(&party[i], MON_DATA_ABILITY_NUM);

            if (species != SPECIES_NONE && species != SPECIES_EGG)
            {
                u16 ability;
                bool32 isAttacker = gBattlerPartyIndexes[gBattlerAttacker] == i;
                bool32 isDoublesPartner = gBattlerPartyIndexes[partner] == i && IsBattlerAlive(partner);

                if (B_HEAL_BELL_SOUNDPROOF == GEN_5 || (isAttacker && B_HEAL_BELL_SOUNDPROOF >= GEN_8))
                    ability = ABILITY_NONE;
                else if (B_HEAL_BELL_SOUNDPROOF > GEN_5 && !isAttacker && !isDoublesPartner)
                    ability = ABILITY_NONE;
                else if (isAttacker)
                    ability = GetBattlerAbility(gBattlerAttacker);
                else if (isDoublesPartner)
                    ability = GetBattlerAbility(partner);
                else
                {
                    ability = GetAbilityBySpecies(species, abilityNum);
                    #if TESTING
                    if (gTestRunnerEnabled)
                    {
                        u32 side = GetBattlerSide(gBattlerAttacker);
                        if (TestRunner_Battle_GetForcedAbility(side, i))
                            ability = TestRunner_Battle_GetForcedAbility(side, i);
                    }
                    #endif
                }

                if (ability != ABILITY_SOUNDPROOF)
                    toHeal |= (1 << i);
            }
        }
    }
    else // Aromatherapy
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SOOTHING_AROMA;
        toHeal = (1 << PARTY_SIZE) - 1;

        gBattleMons[gBattlerAttacker].status1 = 0;
        gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
            && !(gAbsentBattlerFlags & gBitTable[partner]))
        {
            gBattleMons[partner].status1 = 0;
            gBattleMons[partner].status2 &= ~STATUS2_NIGHTMARE;
        }

    }

    if (toHeal)
    {
        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_STATUS_BATTLE, toHeal, sizeof(zero), &zero);
        MarkBattlerForControllerExec(gBattlerAttacker);
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_cursetarget(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_CURSED)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleMons[gBattlerTarget].status2 |= STATUS2_CURSED;
        gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_trysetspikes(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 targetSide = BATTLE_OPPOSITE(GetBattlerSide(gBattlerAttacker));

    if (gSideTimers[targetSide].spikesAmount == 3)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gSideStatuses[targetSide] |= SIDE_STATUS_SPIKES;
        gSideTimers[targetSide].spikesAmount++;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setforesight(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerTarget].status2 |= STATUS2_FORESIGHT;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_trysetperishsong(void)
{
    CMD_ARGS(const u8 *failInstr);

    s32 i;
    s32 notAffectedCount = 0;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gStatuses3[i] & STATUS3_PERISH_SONG
            || GetBattlerAbility(i) == ABILITY_SOUNDPROOF
            || BlocksPrankster(gCurrentMove, gBattlerAttacker, i, TRUE))
        {
            notAffectedCount++;
        }
        else
        {
            gStatuses3[i] |= STATUS3_PERISH_SONG;
            gDisableStructs[i].perishSongTimer = 3;
        }
    }

    if (notAffectedCount == gBattlersCount)
        gBattlescriptCurrInstr = cmd->failInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_handlerollout(void)
{
    CMD_ARGS();

    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        CancelMultiTurnMoves(gBattlerAttacker);
        gBattlescriptCurrInstr = BattleScript_MoveMissedPause;
    }
    else
    {
        if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)) // First hit.
        {
            gDisableStructs[gBattlerAttacker].rolloutTimer = 5;
            gDisableStructs[gBattlerAttacker].rolloutTimerStartValue = 5;
            gBattleMons[gBattlerAttacker].status2 |= STATUS2_MULTIPLETURNS;
            gLockedMoves[gBattlerAttacker] = gCurrentMove;
        }
        if (--gDisableStructs[gBattlerAttacker].rolloutTimer == 0) // Last hit.
        {
            gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_MULTIPLETURNS;
        }

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifconfusedandstatmaxed(void)
{
    CMD_ARGS(u8 stat, const u8 *jumpInstr);

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_CONFUSION
      && !CompareStat(gBattlerTarget, cmd->stat, MAX_STAT_STAGE, CMP_LESS_THAN))
        gBattlescriptCurrInstr = cmd->jumpInstr; // Fails if we're confused AND stat cannot be raised
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_handlefurycutter(void)
{
    CMD_ARGS();

    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        gDisableStructs[gBattlerAttacker].furyCutterCounter = 0;
        gBattlescriptCurrInstr = BattleScript_MoveMissedPause;
    }
    else
    {
        u32 max;

        if (B_UPDATED_MOVE_DATA >= GEN_6)
            max = 3;
        else if (B_UPDATED_MOVE_DATA == GEN_5)
            max = 4;
        else
            max = 5;

        if (gDisableStructs[gBattlerAttacker].furyCutterCounter < max
            && gSpecialStatuses[gBattlerAttacker].parentalBondState != PARENTAL_BOND_2ND_HIT) // Don't increment counter on second hit
            gDisableStructs[gBattlerAttacker].furyCutterCounter++;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setembargo(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gStatuses3[gBattlerTarget] & STATUS3_EMBARGO)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gStatuses3[gBattlerTarget] |= STATUS3_EMBARGO;
        gDisableStructs[gBattlerTarget].embargoTimer = 5;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_presentdamagecalculation(void)
{
    CMD_ARGS();

    u32 rand = Random() & 0xFF;

    /* Don't reroll present effect/power for the second hit of Parental Bond.
     * Not sure if this is the correct behaviour, but bulbapedia states
     * that if present heals the foe, it doesn't strike twice, and if it deals
     * damage, the second strike will always deal damage too. This is a simple way
     * to replicate that effect.
     */
    if (gSpecialStatuses[gBattlerAttacker].parentalBondState != PARENTAL_BOND_2ND_HIT)
    {
        if (rand < 102)
        {
            gBattleStruct->presentBasePower = 40;
        }
        else if (rand < 178)
        {
            gBattleStruct->presentBasePower = 80;
        }
        else if (rand < 204)
        {
            gBattleStruct->presentBasePower = 120;
        }
        else
        {
            gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerTarget) / 4;
            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
            gBattleMoveDamage *= -1;
            gBattleStruct->presentBasePower = 0;
        }
    }

    if (gBattleStruct->presentBasePower)
    {
        gBattlescriptCurrInstr = BattleScript_HitFromCritCalc;
    }
    else if (gBattleMons[gBattlerTarget].maxHP == gBattleMons[gBattlerTarget].hp)
    {
        gBattlescriptCurrInstr = BattleScript_AlreadyAtFullHp;
    }
    else
    {
        gMoveResultFlags &= ~MOVE_RESULT_DOESNT_AFFECT_FOE;
        gBattlescriptCurrInstr = BattleScript_PresentHealTarget;
    }
}

static void Cmd_setsafeguard(void)
{
    CMD_ARGS();

    if (gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_SAFEGUARD)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SIDE_STATUS_FAILED;
    }
    else
    {
        gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_SAFEGUARD;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].safeguardTimer = 5;
        gSideTimers[GetBattlerSide(gBattlerAttacker)].safeguardBattlerId = gBattlerAttacker;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_SAFEGUARD;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_magnitudedamagecalculation(void)
{
    CMD_ARGS();

    u32 magnitude = Random() % 100;

    if (magnitude < 5)
    {
        gBattleStruct->magnitudeBasePower = 10;
        magnitude = 4;
    }
    else if (magnitude < 15)
    {
        gBattleStruct->magnitudeBasePower = 30;
        magnitude = 5;
    }
    else if (magnitude < 35)
    {
        gBattleStruct->magnitudeBasePower = 50;
        magnitude = 6;
    }
    else if (magnitude < 65)
    {
        gBattleStruct->magnitudeBasePower = 70;
        magnitude = 7;
    }
    else if (magnitude < 85)
    {
        gBattleStruct->magnitudeBasePower = 90;
        magnitude = 8;
    }
    else if (magnitude < 95)
    {
        gBattleStruct->magnitudeBasePower = 110;
        magnitude = 9;
    }
    else
    {
        gBattleStruct->magnitudeBasePower = 150;
        magnitude = 10;
    }

    PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 2, magnitude)

    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (gBattlerTarget == gBattlerAttacker)
            continue;
        if (!(gAbsentBattlerFlags & gBitTable[gBattlerTarget])) // A valid target was found.
            break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifnopursuitswitchdmg(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (gMultiHitCounter == 1)
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
            gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        else
            gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
    }
    else
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
            gBattlerTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        else
            gBattlerTarget = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
    }

    if (gChosenActionByBattler[gBattlerTarget] == B_ACTION_USE_MOVE
        && gBattlerAttacker == *(gBattleStruct->moveTarget + gBattlerTarget)
        && !(gBattleMons[gBattlerTarget].status1 & (STATUS1_SLEEP | STATUS1_FREEZE))
        && gBattleMons[gBattlerAttacker].hp
        && !gDisableStructs[gBattlerTarget].truantCounter
        && gMovesInfo[gChosenMoveByBattler[gBattlerTarget]].effect == EFFECT_PURSUIT)
    {
        s32 i;

        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == gBattlerTarget)
                gActionsByTurnOrder[i] = B_ACTION_TRY_FINISH;
        }

        gCurrentMove = gChosenMove = gChosenMoveByBattler[gBattlerTarget];
        gCurrMovePos = gChosenMovePos = *(gBattleStruct->chosenMovePositions + gBattlerTarget);
        gBattlescriptCurrInstr = cmd->nextInstr;
        gBattleScripting.animTurn = 1;
        gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
}

static void Cmd_unused_bb(void)
{
}

// Belly Drum, Fillet Away
static void Cmd_halvehp(void)
{
    CMD_ARGS(const u8 *failInstr);

    u32 halfHp = GetNonDynamaxMaxHP(gBattlerAttacker) / 2;

    if (!(GetNonDynamaxMaxHP(gBattlerAttacker) / 2))
        halfHp = 1;

    if (gBattleMons[gBattlerAttacker].hp > halfHp)
    {
        gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

// Psych Up
static void Cmd_copyfoestats(void)
{
    CMD_ARGS(const u8 *unused);

    s32 i;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
    {
        gBattleMons[gBattlerAttacker].statStages[i] = gBattleMons[gBattlerTarget].statStages[i];
    }

    gBattlescriptCurrInstr = cmd->nextInstr; // Has an unused jump ptr(possibly for a failed attempt) parameter.
}

static void Cmd_rapidspinfree(void)
{
    CMD_ARGS();

    u8 atkSide = GetBattlerSide(gBattlerAttacker);

    if (gBattleMons[gBattlerAttacker].status2 & STATUS2_WRAPPED)
    {
        gBattleScripting.battler = gBattlerTarget;
        gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_WRAPPED;
        gBattlerTarget = *(gBattleStruct->wrappedBy + gBattlerAttacker);
        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleStruct->wrappedMove[gBattlerAttacker]);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_WrapFree;
    }
    else if (gStatuses3[gBattlerAttacker] & STATUS3_LEECHSEED)
    {
        gStatuses3[gBattlerAttacker] &= ~STATUS3_LEECHSEED;
        gStatuses3[gBattlerAttacker] &= ~STATUS3_LEECHSEED_BATTLER;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_LeechSeedFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_SPIKES)
    {
        gSideStatuses[atkSide] &= ~SIDE_STATUS_SPIKES;
        gSideTimers[atkSide].spikesAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SpikesFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_TOXIC_SPIKES)
    {
        gSideStatuses[atkSide] &= ~SIDE_STATUS_TOXIC_SPIKES;
        gSideTimers[atkSide].toxicSpikesAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_ToxicSpikesFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_STICKY_WEB)
    {
        gSideStatuses[atkSide] &= ~SIDE_STATUS_STICKY_WEB;
        gSideTimers[atkSide].stickyWebAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_StickyWebFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_STEALTH_ROCK)
    {
        gSideStatuses[atkSide] &= ~SIDE_STATUS_STEALTH_ROCK;
        gSideTimers[atkSide].stealthRockAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_StealthRockFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_STEELSURGE)
    {
        gSideStatuses[atkSide] &= ~SIDE_STATUS_STEELSURGE;
        gSideTimers[atkSide].steelsurgeAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SteelsurgeFree;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setdefensecurlbit(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerAttacker].status2 |= STATUS2_DEFENSE_CURL;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_recoverbasedonsunlight(void)
{
    CMD_ARGS(const u8 *failInstr);

    gBattlerTarget = gBattlerAttacker;
    if (gBattleMons[gBattlerAttacker].hp != gBattleMons[gBattlerAttacker].maxHP)
    {
        if (gCurrentMove == MOVE_SHORE_UP)
        {
            if (WEATHER_HAS_EFFECT && gBattleWeather & B_WEATHER_SANDSTORM)
                gBattleMoveDamage = 20 * GetNonDynamaxMaxHP(gBattlerAttacker) / 30;
            else
                gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 2;
        }
        else
        {
            if (!(gBattleWeather & B_WEATHER_ANY) || !WEATHER_HAS_EFFECT || GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_UTILITY_UMBRELLA)
                gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 2;
            else if (gBattleWeather & B_WEATHER_SUN)
                gBattleMoveDamage = 20 * GetNonDynamaxMaxHP(gBattlerAttacker) / 30;
            else // not sunny weather
                gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 4;
        }

        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_setstickyweb(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 targetSide = GetBattlerSide(gBattlerTarget);

    if (gSideStatuses[targetSide] & SIDE_STATUS_STICKY_WEB)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gSideStatuses[targetSide] |= SIDE_STATUS_STICKY_WEB;
        gSideTimers[targetSide].stickyWebBattlerId = gBattlerAttacker; // For Mirror Armor
        gSideTimers[targetSide].stickyWebBattlerSide = GetBattlerSide(gBattlerAttacker); // For Court Change/Defiant - set this to the user's side
        gSideTimers[targetSide].stickyWebAmount = 1;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_selectfirstvalidtarget(void)
{
    CMD_ARGS();

    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (gBattlerTarget == gBattlerAttacker && !(GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove) & MOVE_TARGET_USER))
            continue;
        if (IsBattlerAlive(gBattlerTarget))
            break;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_trysetfutureattack(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gWishFutureKnock.futureSightCounter[gBattlerTarget] != 0)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gSideStatuses[GetBattlerSide(gBattlerTarget)] |= SIDE_STATUS_FUTUREATTACK;
        gWishFutureKnock.futureSightMove[gBattlerTarget] = gCurrentMove;
        gWishFutureKnock.futureSightBattlerIndex[gBattlerTarget] = gBattlerAttacker;
        gWishFutureKnock.futureSightPartyIndex[gBattlerTarget] = gBattlerPartyIndexes[gBattlerAttacker];
        gWishFutureKnock.futureSightCounter[gBattlerTarget] = 3;

        if (gCurrentMove == MOVE_DOOM_DESIRE)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOOM_DESIRE;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FUTURE_SIGHT;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_trydobeatup(void)
{
#if B_BEAT_UP >= GEN_5
    CMD_ARGS();

    gBattleStruct->beatUpSlot++;
    gBattlescriptCurrInstr = cmd->nextInstr;
#else
    CMD_ARGS(const u8 *endInstr, const u8 *failInstr);
    struct Pokemon *party = GetBattlerParty(gBattlerAttacker);

    if (!IsBattlerAlive(gBattlerTarget))
    {
        gBattlescriptCurrInstr = cmd->endInstr;
    }
    else
    {
        u8 beforeLoop = gBattleCommunication[0];
        for (;gBattleCommunication[0] < PARTY_SIZE; gBattleCommunication[0]++)
        {
            if (GetMonData(&party[gBattleCommunication[0]], MON_DATA_HP)
                && GetMonData(&party[gBattleCommunication[0]], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
                && GetMonData(&party[gBattleCommunication[0]], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
                && !GetMonData(&party[gBattleCommunication[0]], MON_DATA_STATUS))
                break;
        }
        if (gBattleCommunication[0] < PARTY_SIZE)
        {
            PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattleCommunication[0])

            gBattlescriptCurrInstr = cmd->nextInstr;

            gBattleMoveDamage = gSpeciesInfo[GetMonData(&party[gBattleCommunication[0]], MON_DATA_SPECIES)].baseAttack;
            gBattleMoveDamage *= gMovesInfo[gCurrentMove].power;
            gBattleMoveDamage *= (GetMonData(&party[gBattleCommunication[0]], MON_DATA_LEVEL) * 2 / 5 + 2);
            gBattleMoveDamage /= gSpeciesInfo[gBattleMons[gBattlerTarget].species].baseDefense;
            gBattleMoveDamage = (gBattleMoveDamage / 50) + 2;
            if (gProtectStructs[gBattlerAttacker].helpingHand)
                gBattleMoveDamage = gBattleMoveDamage * 15 / 10;

            gBattleCommunication[0]++;
        }
        else if (beforeLoop != 0)
            gBattlescriptCurrInstr = cmd->endInstr;
        else
            gBattlescriptCurrInstr = cmd->failInstr;
    }
#endif
}

static void Cmd_setsemiinvulnerablebit(void)
{
    CMD_ARGS(bool8 clear);

    if (gBattleMoveEffects[gMovesInfo[gCurrentMove].effect].semiInvulnerableEffect == TRUE)
    {
        u32 semiInvulnerableEffect = UNCOMPRESS_BITS(HIHALF(gMovesInfo[gCurrentMove].argument));
        if (cmd->clear)
            gStatuses3[gBattlerAttacker] &= ~semiInvulnerableEffect;
        else
            gStatuses3[gBattlerAttacker] |= semiInvulnerableEffect;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static bool32 CheckIfCanFireTwoTurnMoveNow(u8 battler, bool8 checkChargeTurnEffects)
{
    // Semi-invulnerable moves cannot skip their charge turn (except with Power Herb)
    if (gBattleMoveEffects[gMovesInfo[gCurrentMove].effect].semiInvulnerableEffect == TRUE)
        return FALSE;

    // If this move has charge turn effects, it must charge, activate them, then try to fire
    if (checkChargeTurnEffects && MoveHasChargeTurnAdditionalEffect(gCurrentMove))
        return FALSE;

    // Insert custom conditions here

    // Certain two-turn moves may fire on the first turn in the right weather (Solar Beam, Electro Shot)
    // By default, all two-turn moves have the option of adding weather to their argument
    if (IsBattlerWeatherAffected(battler, HIHALF(gMovesInfo[gCurrentMove].argument)))
        return TRUE;

    return FALSE;
}

static void Cmd_tryfiretwoturnmovenowbyeffect(void)
{
    CMD_ARGS(u8 battler, bool8 checkChargeTurnEffects, const u8 *jumpInstr);

    if (CheckIfCanFireTwoTurnMoveNow(cmd->battler, cmd->checkChargeTurnEffects) == TRUE)
    {
        gBattleScripting.animTurn = 1;
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setminimize(void)
{
    CMD_ARGS();

    if (gHitMarker & HITMARKER_OBEYS)
        gStatuses3[gBattlerAttacker] |= STATUS3_MINIMIZED;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_unused_c8(void)
{
}

static void Cmd_trymemento(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (B_MEMENTO_FAIL >= GEN_4
      && (gBattleCommunication[MISS_TYPE] == B_MSG_PROTECTED
        || gStatuses3[gBattlerTarget] & STATUS3_SEMI_INVULNERABLE
        || IsBattlerProtected(gBattlerAttacker, gBattlerTarget, gCurrentMove)
        || DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove)))
    {
        // Failed, target was protected.
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (B_MEMENTO_FAIL < GEN_4
        && gBattleMons[gBattlerTarget].statStages[STAT_ATK] == MIN_STAT_STAGE
        && gBattleMons[gBattlerTarget].statStages[STAT_SPATK] == MIN_STAT_STAGE
        && gBattleCommunication[MISS_TYPE] != B_MSG_PROTECTED)
    {
        // Failed, unprotected target already has minimum Attack and Special Attack.
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        // Success, drop user's HP bar to 0
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].hp;
        BtlController_EmitHealthBarUpdate(gBattlerAttacker, BUFFER_A, INSTANT_HP_BAR_DROP);
        MarkBattlerForControllerExec(gBattlerAttacker);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

// Follow Me
static void Cmd_setforcedtarget(void)
{
    CMD_ARGS();

    gSideTimers[GetBattlerSide(gBattlerTarget)].followmeTimer = 1;
    gSideTimers[GetBattlerSide(gBattlerTarget)].followmeTarget = gBattlerTarget;
    gSideTimers[GetBattlerSide(gBattlerTarget)].followmePowder = gMovesInfo[gCurrentMove].powderMove;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setcharge(void)
{
    CMD_ARGS(u8 battler);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    gStatuses3[battler] |= STATUS3_CHARGED_UP;
    if (B_CHARGE < GEN_9)
        gDisableStructs[battler].chargeTimer = 2;
    else
        gDisableStructs[battler].chargeTimer = 0;
    gBattlescriptCurrInstr++;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Nature Power
static void Cmd_callterrainattack(void)
{
    CMD_ARGS();

    gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
    gCurrentMove = GetNaturePowerMove(gBattlerAttacker);
    gBattlerTarget = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
    BattleScriptPush(GET_MOVE_BATTLESCRIPT(gCurrentMove));
    gBattlescriptCurrInstr = cmd->nextInstr;
}

u32 GetNaturePowerMove(u32 battler)
{
    u32 move = sNaturePowerMoves[gBattleTerrain];
    if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
        move = MOVE_MOONBLAST;
    else if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
        move = MOVE_THUNDERBOLT;
    else if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
        move = MOVE_ENERGY_BALL;
    else if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
        move = MOVE_PSYCHIC;
    else if (sNaturePowerMoves[gBattleTerrain] == MOVE_NONE)
        move = MOVE_TRI_ATTACK;

    if (GetActiveGimmick(battler) == GIMMICK_Z_MOVE)
    {
        gBattleStruct->zmove.baseMoves[gBattlerAttacker] = move;
        move = GetTypeBasedZMove(move);
    }

    return move;
}

// Refresh
static void Cmd_cureifburnedparalysedorpoisoned(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gBattleMons[gBattlerAttacker].status1 & (STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON | STATUS1_FROSTBITE))
    {
        gBattleMons[gBattlerAttacker].status1 = 0;
        gBattlescriptCurrInstr = cmd->nextInstr;
        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].status1), &gBattleMons[gBattlerAttacker].status1);
        MarkBattlerForControllerExec(gBattlerAttacker);
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_settorment(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_TORMENT
        || (GetActiveGimmick(gBattlerTarget) == GIMMICK_DYNAMAX))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleMons[gBattlerTarget].status2 |= STATUS2_TORMENT;
        gDisableStructs[gBattlerTarget].tormentTimer = PERMANENT_TORMENT; // permanent
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifnodamage(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (gProtectStructs[gBattlerAttacker].physicalDmg || gProtectStructs[gBattlerAttacker].specialDmg)
        gBattlescriptCurrInstr = cmd->nextInstr;
    else
        gBattlescriptCurrInstr = cmd->jumpInstr;
}

static void Cmd_settaunt(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (B_OBLIVIOUS_TAUNT >= GEN_6 && GetBattlerAbility(gBattlerTarget) == ABILITY_OBLIVIOUS)
    {
        gBattlescriptCurrInstr = BattleScript_NotAffectedAbilityPopUp;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        RecordAbilityBattle(gBattlerTarget, ABILITY_OBLIVIOUS);
    }
    else if (gDisableStructs[gBattlerTarget].tauntTimer == 0)
    {
        u8 turns;
        if (B_TAUNT_TURNS >= GEN_5)
        {
            turns = 4;
            if (GetBattlerTurnOrderNum(gBattlerTarget) > GetBattlerTurnOrderNum(gBattlerAttacker))
                turns--; // If the target hasn't yet moved this turn, Taunt lasts for only three turns (source: Bulbapedia)
        }
        else if (B_TAUNT_TURNS >= GEN_4)
        {
            turns = (Random() & 2) + 3;
        }
        else
        {
            turns = 2;
        }

        gDisableStructs[gBattlerTarget].tauntTimer = turns;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_trysethelpinghand(void)
{
    CMD_ARGS(const u8 *failInstr);

    gBattlerTarget = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gBattlerAttacker)));

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
        && !(gAbsentBattlerFlags & gBitTable[gBattlerTarget])
        && !gProtectStructs[gBattlerAttacker].helpingHand
        && !gProtectStructs[gBattlerTarget].helpingHand)
    {
        gProtectStructs[gBattlerTarget].helpingHand = TRUE;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

// Trick
static void Cmd_tryswapitems(void)
{
    CMD_ARGS(const u8 *failInstr);

    // opponent can't swap items with player in regular battles
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL
        || (GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT
            && !(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_SECRET_BASE
                                  | BATTLE_TYPE_RECORDED_LINK
                                  | (B_TRAINERS_KNOCK_OFF_ITEMS == TRUE ? BATTLE_TYPE_TRAINER : 0)
                                  ))))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
        u8 sideTarget = GetBattlerSide(gBattlerTarget);

        // You can't swap items if they were knocked off in regular battles
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                             | BATTLE_TYPE_EREADER_TRAINER
                             | BATTLE_TYPE_FRONTIER
                             | BATTLE_TYPE_SECRET_BASE
                             | BATTLE_TYPE_RECORDED_LINK))
            && (gWishFutureKnock.knockedOffMons[sideAttacker] & gBitTable[gBattlerPartyIndexes[gBattlerAttacker]]
                || gWishFutureKnock.knockedOffMons[sideTarget] & gBitTable[gBattlerPartyIndexes[gBattlerTarget]]))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        // can't swap if two Pokémon don't have an item
        // or if either of them is an enigma berry or a mail
        else if ((gBattleMons[gBattlerAttacker].item == ITEM_NONE && gBattleMons[gBattlerTarget].item == ITEM_NONE)
                 || !CanBattlerGetOrLoseItem(gBattlerAttacker, gBattleMons[gBattlerAttacker].item)
                 || !CanBattlerGetOrLoseItem(gBattlerAttacker, gBattleMons[gBattlerTarget].item)
                 || !CanBattlerGetOrLoseItem(gBattlerTarget, gBattleMons[gBattlerTarget].item)
                 || !CanBattlerGetOrLoseItem(gBattlerTarget, gBattleMons[gBattlerAttacker].item))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        // check if ability prevents swapping
        else if (GetBattlerAbility(gBattlerTarget) == ABILITY_STICKY_HOLD)
        {
            gBattlescriptCurrInstr = BattleScript_StickyHoldActivates;
            gLastUsedAbility = gBattleMons[gBattlerTarget].ability;
            RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
        }
        // took a while, but all checks passed and items can be safely swapped
        else
        {
            u16 oldItemAtk, *newItemAtk;

            newItemAtk = &gBattleStruct->changedItems[gBattlerAttacker];
            oldItemAtk = gBattleMons[gBattlerAttacker].item;
            *newItemAtk = gBattleMons[gBattlerTarget].item;

            gBattleMons[gBattlerAttacker].item = ITEM_NONE;
            gBattleMons[gBattlerTarget].item = oldItemAtk;

            RecordItemEffectBattle(gBattlerAttacker, 0);
            RecordItemEffectBattle(gBattlerTarget, ItemId_GetHoldEffect(oldItemAtk));

            BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(*newItemAtk), newItemAtk);
            MarkBattlerForControllerExec(gBattlerAttacker);

            BtlController_EmitSetMonData(gBattlerTarget, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].item), &gBattleMons[gBattlerTarget].item);
            MarkBattlerForControllerExec(gBattlerTarget);

            gBattleStruct->choicedMove[gBattlerTarget] = MOVE_NONE;
            gBattleStruct->choicedMove[gBattlerAttacker] = MOVE_NONE;

            gBattlescriptCurrInstr = cmd->nextInstr;

            PREPARE_ITEM_BUFFER(gBattleTextBuff1, *newItemAtk)
            PREPARE_ITEM_BUFFER(gBattleTextBuff2, oldItemAtk)

            if (!(sideAttacker == sideTarget && IsPartnerMonFromSameTrainer(gBattlerAttacker)))
            {
                // if targeting your own side and you aren't in a multi battle, don't save items as stolen
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    TrySaveExchangedItem(gBattlerAttacker, oldItemAtk);
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    TrySaveExchangedItem(gBattlerTarget, *newItemAtk);
            }

            if (oldItemAtk != ITEM_NONE && *newItemAtk != ITEM_NONE)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ITEM_SWAP_BOTH;  // attacker's item -> <- target's item
            }
            else if (oldItemAtk == ITEM_NONE && *newItemAtk != ITEM_NONE)
            {
                if (GetBattlerAbility(gBattlerAttacker) == ABILITY_UNBURDEN && gBattleResources->flags->flags[gBattlerAttacker] & RESOURCE_FLAG_UNBURDEN)
                    gBattleResources->flags->flags[gBattlerAttacker] &= ~RESOURCE_FLAG_UNBURDEN;

                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ITEM_SWAP_TAKEN; // nothing -> <- target's item
            }
            else
            {
                CheckSetUnburden(gBattlerAttacker);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ITEM_SWAP_GIVEN; // attacker's item -> <- nothing
            }
        }
    }
}

// Role Play, Doodle
static void Cmd_trycopyability(void)
{
    CMD_ARGS(u8 battler, const u8 *failInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    u16 defAbility = gBattleMons[gBattlerTarget].ability;

    if (gBattleMons[battler].ability == defAbility
      || defAbility == ABILITY_NONE
      || gAbilitiesInfo[gBattleMons[battler].ability].cantBeSuppressed
      || gAbilitiesInfo[gBattleMons[BATTLE_PARTNER(battler)].ability].cantBeSuppressed
      || gAbilitiesInfo[defAbility].cantBeCopied)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleScripting.abilityPopupOverwrite = gBattleMons[battler].ability;
        gBattleMons[battler].ability = gBattleStruct->overwrittenAbilities[battler] = defAbility;
        gLastUsedAbility = defAbility;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_trywish(void)
{
    CMD_ARGS(u8 turnNumber, const u8 *failInstr);

    switch (cmd->turnNumber)
    {
    case 0: // use wish
        if (gWishFutureKnock.wishCounter[gBattlerAttacker] == 0)
        {
            gWishFutureKnock.wishCounter[gBattlerAttacker] = 2;
            gWishFutureKnock.wishPartyId[gBattlerAttacker] = gBattlerPartyIndexes[gBattlerAttacker];
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        break;
    case 1: // heal effect
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gBattlerTarget, gWishFutureKnock.wishPartyId[gBattlerTarget])
        if (B_WISH_HP_SOURCE >= GEN_5)
        {
            if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                gBattleMoveDamage = max(1, GetMonData(&gPlayerParty[gWishFutureKnock.wishPartyId[gBattlerTarget]], MON_DATA_MAX_HP) / 2);
            else
                gBattleMoveDamage = max(1, GetMonData(&gEnemyParty[gWishFutureKnock.wishPartyId[gBattlerTarget]], MON_DATA_MAX_HP) / 2);
        }
        else
        {
            gBattleMoveDamage = max(1, GetNonDynamaxMaxHP(gBattlerAttacker) / 2);
        }

        gBattleMoveDamage *= -1;
        if (gBattleMons[gBattlerTarget].hp == gBattleMons[gBattlerTarget].maxHP)
            gBattlescriptCurrInstr = cmd->failInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;

        break;
    }
}

static void Cmd_settoxicspikes(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 targetSide = GetBattlerSide(gBattlerTarget);
    if (gSideTimers[targetSide].toxicSpikesAmount >= 2)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gSideTimers[targetSide].toxicSpikesAmount++;
        gSideStatuses[targetSide] |= SIDE_STATUS_TOXIC_SPIKES;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setgastroacid(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gAbilitiesInfo[gBattleMons[gBattlerTarget].ability].cantBeSuppressed)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        if (gBattleMons[gBattlerTarget].ability == ABILITY_NEUTRALIZING_GAS)
            gSpecialStatuses[gBattlerTarget].neutralizingGasRemoved = TRUE;

        gStatuses3[gBattlerTarget] |= STATUS3_GASTRO_ACID;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setyawn(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gStatuses3[gBattlerTarget] & STATUS3_YAWN
        || gBattleMons[gBattlerTarget].status1 & STATUS1_ANY)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (IsBattlerTerrainAffected(gBattlerTarget, STATUS_FIELD_ELECTRIC_TERRAIN))
    {
        // When Yawn is used while Electric Terrain is set and drowsiness is set from Yawn being used against target in the previous turn:
        // "But it failed" will display first.
        gBattlescriptCurrInstr = BattleScript_ElectricTerrainPrevents;
    }
    else if (IsBattlerTerrainAffected(gBattlerTarget, STATUS_FIELD_MISTY_TERRAIN))
    {
        // When Yawn is used while Misty Terrain is set and drowsiness is set from Yawn being used against target in the previous turn:
        // "But it failed" will display first.
        gBattlescriptCurrInstr = BattleScript_MistyTerrainPrevents;
    }
    else
    {
        gStatuses3[gBattlerTarget] |= STATUS3_YAWN_TURN(2);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setdamagetohealthdifference(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (GetNonDynamaxHP(gBattlerTarget) <= gBattleMons[gBattlerAttacker].hp)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleMoveDamage = GetNonDynamaxHP(gBattlerTarget) - gBattleMons[gBattlerAttacker].hp;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void HandleRoomMove(u32 statusFlag, u8 *timer, u8 stringId)
{
    if (gFieldStatuses & statusFlag)
    {
        gFieldStatuses &= ~statusFlag;
        *timer = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = stringId + 1;
    }
    else
    {
        gFieldStatuses |= statusFlag;
        *timer = 5;
        gBattleCommunication[MULTISTRING_CHOOSER] = stringId;
    }
}

static void Cmd_setroom(void)
{
    CMD_ARGS();

    switch (gMovesInfo[gCurrentMove].effect)
    {
    case EFFECT_TRICK_ROOM:
        HandleRoomMove(STATUS_FIELD_TRICK_ROOM, &gFieldTimers.trickRoomTimer, 0);
        break;
    case EFFECT_WONDER_ROOM:
        HandleRoomMove(STATUS_FIELD_WONDER_ROOM, &gFieldTimers.wonderRoomTimer, 2);
        break;
    case EFFECT_MAGIC_ROOM:
        HandleRoomMove(STATUS_FIELD_MAGIC_ROOM, &gFieldTimers.magicRoomTimer, 4);
        break;
    default:
        gBattleCommunication[MULTISTRING_CHOOSER] = 6;
        break;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Skill Swap
static void Cmd_tryswapabilities(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gAbilitiesInfo[gBattleMons[gBattlerAttacker].ability].cantBeSwapped
      || gAbilitiesInfo[gBattleMons[gBattlerTarget].ability].cantBeSwapped)
    {
        RecordAbilityBattle(gBattlerTarget, gBattleMons[gBattlerTarget].ability);
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (GetBattlerHoldEffect(gBattlerTarget, TRUE) == HOLD_EFFECT_ABILITY_SHIELD)
    {
        RecordItemEffectBattle(gBattlerTarget, HOLD_EFFECT_ABILITY_SHIELD);
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT || (GetActiveGimmick(gBattlerTarget) == GIMMICK_DYNAMAX))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            u16 abilityAtk = gBattleMons[gBattlerAttacker].ability;
            gBattleMons[gBattlerAttacker].ability = gBattleStruct->overwrittenAbilities[gBattlerAttacker] = gBattleMons[gBattlerTarget].ability;
            gBattleMons[gBattlerTarget].ability = gBattleStruct->overwrittenAbilities[gBattlerTarget] = abilityAtk;

            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
}

static void Cmd_tryimprison(void)
{
    CMD_ARGS(const u8 *failInstr);

    if ((gStatuses3[gBattlerAttacker] & STATUS3_IMPRISONED_OTHERS))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (B_IMPRISON >= GEN_5)
    {
        gStatuses3[gBattlerAttacker] |= STATUS3_IMPRISONED_OTHERS;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        u8 battler, sideAttacker;

        sideAttacker = GetBattlerSide(gBattlerAttacker);
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            if (sideAttacker != GetBattlerSide(battler))
            {
                s32 attackerMoveId;
                for (attackerMoveId = 0; attackerMoveId < MAX_MON_MOVES; attackerMoveId++)
                {
                    s32 i;
                    for (i = 0; i < MAX_MON_MOVES; i++)
                    {
                        if (gBattleMons[gBattlerAttacker].moves[attackerMoveId] == gBattleMons[battler].moves[i]
                            && gBattleMons[gBattlerAttacker].moves[attackerMoveId] != MOVE_NONE)
                            break;
                    }
                    if (i != MAX_MON_MOVES)
                        break;
                }
                if (attackerMoveId != MAX_MON_MOVES)
                {
                    gStatuses3[gBattlerAttacker] |= STATUS3_IMPRISONED_OTHERS;
                    gBattlescriptCurrInstr = cmd->nextInstr;
                    break;
                }
            }
        }
        if (battler == gBattlersCount) // In Generation 3 games, Imprison fails if the user doesn't share any moves with any of the foes.
            gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_setstealthrock(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 targetSide = GetBattlerSide(gBattlerTarget);
    if (gSideStatuses[targetSide] & SIDE_STATUS_STEALTH_ROCK)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gSideStatuses[targetSide] |= SIDE_STATUS_STEALTH_ROCK;
        gSideTimers[targetSide].stealthRockAmount = 1;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setuserstatus3(void)
{
    CMD_ARGS(u32 flags, const u8 *failInstr);

    u32 flags = cmd->flags;

    if (gStatuses3[gBattlerAttacker] & flags)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gStatuses3[gBattlerAttacker] |= flags;
        if (flags & STATUS3_MAGNET_RISE)
            gDisableStructs[gBattlerAttacker].magnetRiseTimer = 5;
        if (flags & STATUS3_LASER_FOCUS)
            gDisableStructs[gBattlerAttacker].laserFocusTimer = 2;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_assistattackselect(void)
{
    CMD_ARGS(const u8 *failInstr);

    s32 chooseableMovesNo = 0;
    struct Pokemon *party;
    s32 monId, moveId;
    u16 *validMoves = Alloc(sizeof(u16) * PARTY_SIZE * MAX_MON_MOVES);

    if (validMoves != NULL)
    {
        party = GetBattlerParty(gBattlerAttacker);

        for (monId = 0; monId < PARTY_SIZE; monId++)
        {
            if (monId == gBattlerPartyIndexes[gBattlerAttacker])
                continue;
            if (GetMonData(&party[monId], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
                continue;
            if (GetMonData(&party[monId], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
                continue;

            for (moveId = 0; moveId < MAX_MON_MOVES; moveId++)
            {
                u16 move = GetMonData(&party[monId], MON_DATA_MOVE1 + moveId);

                if (gMovesInfo[move].assistBanned)
                    continue;

                validMoves[chooseableMovesNo++] = move;
            }
        }
    }

    if (chooseableMovesNo)
    {
        gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
        gCalledMove = validMoves[Random() % chooseableMovesNo];
        gBattlerTarget = GetMoveTarget(gCalledMove, NO_TARGET_OVERRIDE);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }

    TRY_FREE_AND_SET_NULL(validMoves);
}

static void Cmd_trysetmagiccoat(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gCurrentTurnActionNumber == gBattlersCount - 1) // moves last turn
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gProtectStructs[gBattlerAttacker].bounceMove = TRUE;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

// Snatch
static void Cmd_trysetsnatch(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gCurrentTurnActionNumber == gBattlersCount - 1) // moves last turn
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gProtectStructs[gBattlerAttacker].stealMove = TRUE;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_unused2(void)
{
}

static void Cmd_switchoutabilities(void)
{
    CMD_ARGS(u8 battler);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (gBattleMons[battler].ability == ABILITY_NEUTRALIZING_GAS)
    {
        gBattleMons[battler].ability = ABILITY_NONE;
        BattleScriptPush(gBattlescriptCurrInstr);
        gBattlescriptCurrInstr = BattleScript_NeutralizingGasExits;
    }
    else
    {
        switch (GetBattlerAbility(battler))
        {
        case ABILITY_NATURAL_CURE:
            gBattleMons[battler].status1 = 0;
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_STATUS_BATTLE,
                                         gBitTable[*(gBattleStruct->battlerPartyIndexes + battler)],
                                         sizeof(gBattleMons[battler].status1),
                                         &gBattleMons[battler].status1);
            MarkBattlerForControllerExec(battler);
            break;
        case ABILITY_REGENERATOR:
            gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 3;
            gBattleMoveDamage += gBattleMons[battler].hp;
            if (gBattleMoveDamage > gBattleMons[battler].maxHP)
                gBattleMoveDamage = gBattleMons[battler].maxHP;
            BtlController_EmitSetMonData(battler, BUFFER_A, REQUEST_HP_BATTLE,
                                         gBitTable[*(gBattleStruct->battlerPartyIndexes + battler)],
                                         sizeof(gBattleMoveDamage),
                                         &gBattleMoveDamage);
            MarkBattlerForControllerExec(battler);
            break;
        }

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifhasnohp(void)
{
    CMD_ARGS(u8 battler, const u8 *jumpInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);

    if (!IsBattlerAlive(battler))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifnotcurrentmoveargtype(void)
{
    CMD_ARGS(u8 battler, const u8 *failInstr);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    const u8 *failInstr = cmd->failInstr;

    if (!IS_BATTLER_OF_TYPE(battler, gMovesInfo[gCurrentMove].argument))
        gBattlescriptCurrInstr = failInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_pickup(void)
{
    CMD_ARGS();

    u32 i, j;
    u16 species, heldItem, ability;
    u8 lvlDivBy10;

    if (!InBattlePike()) // No items in Battle Pike.
    {
        bool32 isInPyramid = InBattlePyramid_();
        for (i = 0; i < PARTY_SIZE; i++)
        {
            species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
            heldItem = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
            lvlDivBy10 = (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL)-1) / 10; //Moving this here makes it easier to add in abilities like Honey Gather.
            if (lvlDivBy10 > 9)
                lvlDivBy10 = 9;

            ability = gSpeciesInfo[species].abilities[GetMonData(&gPlayerParty[i], MON_DATA_ABILITY_NUM)];

            if (ability == ABILITY_PICKUP
                && species != SPECIES_NONE
                && species != SPECIES_EGG
                && heldItem == ITEM_NONE
                && (Random() % 10) == 0)
            {
                if (isInPyramid)
                {
                    heldItem = GetBattlePyramidPickupItemId();
                    SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &heldItem);
                }
                else
                {
                    u32 rand = Random() % 100;
                    u32 percentTotal = 0;

                    for (j = 0; j < ARRAY_COUNT(sPickupTable); j++)
                    {
                        percentTotal += sPickupTable[j].percentage[lvlDivBy10];
                        if (rand < percentTotal)
                        {
                            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &sPickupTable[j].itemId);
                            break;
                        }
                    }
                }
            }
            else if (ability == ABILITY_HONEY_GATHER
                && species != 0
                && species != SPECIES_EGG
                && heldItem == ITEM_NONE)
            {
                if ((lvlDivBy10 + 1 ) * 5 > Random() % 100)
                {
                    heldItem = ITEM_HONEY;
                    SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &heldItem);
                }
            }
            else if (P_SHUCKLE_BERRY_JUICE == GEN_2
                && species == SPECIES_SHUCKLE
                && heldItem == ITEM_ORAN_BERRY
                && (Random() % 16) == 0)
            {
                heldItem = ITEM_BERRY_JUICE;
                SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &heldItem);
            }
        }
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_unused3(void)
{
}

static void Cmd_unused4(void)
{
}

// Water and Mud Sport
static void Cmd_settypebasedhalvers(void)
{
    CMD_ARGS(const u8 *failInstr);

    bool8 worked = FALSE;

    if (gMovesInfo[gCurrentMove].effect == EFFECT_MUD_SPORT)
    {
        if (B_SPORT_TURNS >= GEN_6)
        {
            if (!(gFieldStatuses & STATUS_FIELD_MUDSPORT))
            {
                gFieldStatuses |= STATUS_FIELD_MUDSPORT;
                gFieldTimers.mudSportTimer = 5;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEAKEN_ELECTRIC;
                worked = TRUE;
            }
        }
        else
        {
            if (!(gStatuses4[gBattlerAttacker] & STATUS4_MUD_SPORT))
            {
                gStatuses4[gBattlerAttacker] |= STATUS4_MUD_SPORT;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEAKEN_ELECTRIC;
                worked = TRUE;
            }
        }
    }
    else // Water Sport
    {
        if (B_SPORT_TURNS >= GEN_6)
        {
            if (!(gFieldStatuses & STATUS_FIELD_WATERSPORT))
            {
                gFieldStatuses |= STATUS_FIELD_WATERSPORT;
                gFieldTimers.waterSportTimer = 5;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEAKEN_FIRE;
                worked = TRUE;
            }
        }
        else
        {
            if (!(gStatuses4[gBattlerAttacker] & STATUS4_WATER_SPORT))
            {
                gStatuses4[gBattlerAttacker] |= STATUS4_WATER_SPORT;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEAKEN_FIRE;
                worked = TRUE;
            }
        }
    }

    if (worked)
        gBattlescriptCurrInstr = cmd->nextInstr;
    else
        gBattlescriptCurrInstr = cmd->failInstr;
}

bool32 DoesSubstituteBlockMove(u32 battlerAtk, u32 battlerDef, u32 move)
{
    if (!(gBattleMons[battlerDef].status2 & STATUS2_SUBSTITUTE))
        return FALSE;
    else if (gMovesInfo[move].ignoresSubstitute)
        return FALSE;
    else if (GetBattlerAbility(battlerAtk) == ABILITY_INFILTRATOR)
        return FALSE;
    else
        return TRUE;
}

bool32 DoesDisguiseBlockMove(u32 battler, u32 move)
{
    if (!(gBattleMons[battler].species == SPECIES_MIMIKYU_DISGUISED || gBattleMons[battler].species == SPECIES_MIMIKYU_TOTEM_DISGUISED)
        || gBattleMons[battler].status2 & STATUS2_TRANSFORMED
        || (!gProtectStructs[battler].confusionSelfDmg && (IS_MOVE_STATUS(move) || gHitMarker & HITMARKER_PASSIVE_DAMAGE))
        || gHitMarker & HITMARKER_IGNORE_DISGUISE
        || GetBattlerAbility(battler) != ABILITY_DISGUISE)
        return FALSE;
    else
        return TRUE;
}

static void Cmd_jumpifsubstituteblocks(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_tryrecycleitem(void)
{
    CMD_ARGS(const u8 *failInstr);

    u16 *usedHeldItem;

    if (gCurrentMove == MOVE_NONE && GetBattlerAbility(gBattlerAttacker) == ABILITY_PICKUP)
        usedHeldItem = &gBattleStruct->usedHeldItems[gBattlerPartyIndexes[gBattlerTarget]][GetBattlerSide(gBattlerTarget)];
    else
        usedHeldItem = &gBattleStruct->usedHeldItems[gBattlerPartyIndexes[gBattlerAttacker]][GetBattlerSide(gBattlerAttacker)];
    if (*usedHeldItem != ITEM_NONE && gBattleMons[gBattlerAttacker].item == ITEM_NONE)
    {
        gLastUsedItem = *usedHeldItem;
        *usedHeldItem = ITEM_NONE;
        gBattleMons[gBattlerAttacker].item = gLastUsedItem;

        BtlController_EmitSetMonData(gBattlerAttacker, BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gBattlerAttacker].item), &gBattleMons[gBattlerAttacker].item);
        MarkBattlerForControllerExec(gBattlerAttacker);

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

bool32 CanCamouflage(u8 battler)
{
    if (IS_BATTLER_OF_TYPE(battler, sTerrainToType[gBattleTerrain]))
        return FALSE;
    return TRUE;
}

static void Cmd_settypetoterrain(void)
{
    CMD_ARGS(const u8 *failInstr);

    u8 terrainType;
    switch(gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
    {
    case STATUS_FIELD_ELECTRIC_TERRAIN:
        terrainType = TYPE_ELECTRIC;
        break;
    case STATUS_FIELD_GRASSY_TERRAIN:
        terrainType = TYPE_GRASS;
        break;
    case STATUS_FIELD_MISTY_TERRAIN:
        terrainType = TYPE_FAIRY;
        break;
    case STATUS_FIELD_PSYCHIC_TERRAIN:
        terrainType = TYPE_PSYCHIC;
        break;
    default:
        terrainType = sTerrainToType[gBattleTerrain];
        break;
    }

    if (!IS_BATTLER_OF_TYPE(gBattlerAttacker, terrainType) && GetActiveGimmick(gBattlerAttacker) != GIMMICK_TERA)
    {
        SET_BATTLER_TYPE(gBattlerAttacker, terrainType);
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, terrainType);

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

// Unused
static void Cmd_pursuitdoubles(void)
{
    CMD_ARGS(const u8 *failInstr);

    u32 battler = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gBattlerAttacker)));

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
        && !(gAbsentBattlerFlags & gBitTable[battler])
        && gChosenActionByBattler[battler] == B_ACTION_USE_MOVE
        && gMovesInfo[gChosenMoveByBattler[battler]].effect == EFFECT_PURSUIT)
    {
        gActionsByTurnOrder[battler] = B_ACTION_TRY_FINISH;
        gCurrentMove = gChosenMoveByBattler[battler];
        gBattlescriptCurrInstr = cmd->nextInstr;
        gBattleScripting.animTurn = 1;
        gBattleScripting.savedBattler = gBattlerAttacker;
        gBattlerAttacker = battler;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_snatchsetbattlers(void)
{
    CMD_ARGS();

    gEffectBattler = gBattlerAttacker;

    if (gBattlerAttacker == gBattlerTarget)
        gBattlerAttacker = gBattlerTarget = gBattleScripting.battler;
    else
        gBattlerTarget = gBattleScripting.battler;

    gBattleScripting.battler = gEffectBattler;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Brick Break
static void Cmd_removelightscreenreflect(void)
{
    CMD_ARGS();

    u8 side;
    bool32 failed;

    if (B_BRICK_BREAK >= GEN_4)
        side = GetBattlerSide(gBattlerTarget); // From Gen 4 onwards, Brick Break can remove screens on the user's side if used on an ally
    else
        side = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;

    if (B_BRICK_BREAK >= GEN_5)
        failed = (gMoveResultFlags & MOVE_RESULT_NO_EFFECT);
    else
        failed = FALSE;

    if (!failed
     && (gSideTimers[side].reflectTimer
      || gSideTimers[side].lightscreenTimer
      || gSideTimers[side].auroraVeilTimer))
    {
        gSideStatuses[side] &= ~SIDE_STATUS_REFLECT;
        gSideStatuses[side] &= ~SIDE_STATUS_LIGHTSCREEN;
        gSideStatuses[side] &= ~SIDE_STATUS_AURORA_VEIL;
        gSideTimers[side].reflectTimer = 0;
        gSideTimers[side].lightscreenTimer = 0;
        gSideTimers[side].auroraVeilTimer = 0;
        gBattleScripting.animTurn = 1;
        gBattleScripting.animTargetsHit = 1;
    }
    else
    {
        gBattleScripting.animTurn = 0;
        gBattleScripting.animTargetsHit = 0;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

u8 GetCatchingBattler(void)
{
    if (IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)))
        return GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    else
        return GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
}

static void Cmd_handleballthrow(void)
{
    CMD_ARGS();

    u16 ballMultiplier = 100;
    s8 ballAddition = 0;

    if (gBattleControllerExecFlags)
        return;

    gBattlerTarget = GetCatchingBattler();

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        BtlController_EmitBallThrowAnim(gBattlerAttacker, BUFFER_A, BALL_TRAINER_BLOCK);
        MarkBattlerForControllerExec(gBattlerAttacker);
        gBattlescriptCurrInstr = BattleScript_TrainerBallBlock;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
    {
        BtlController_EmitBallThrowAnim(gBattlerAttacker, BUFFER_A, BALL_3_SHAKES_SUCCESS);
        MarkBattlerForControllerExec(gBattlerAttacker);
        gBattlescriptCurrInstr = BattleScript_WallyBallThrow;
    }
    else
    {
        u32 odds, i;
        u8 catchRate;

        gLastThrownBall = gLastUsedItem;
        gBallToDisplay = gLastThrownBall;
        if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            catchRate = gBattleStruct->safariCatchFactor * 1275 / 100;
        else
            catchRate = gSpeciesInfo[gBattleMons[gBattlerTarget].species].catchRate;

        if (gSpeciesInfo[gBattleMons[gBattlerTarget].species].isUltraBeast)
        {
            if (gLastUsedItem == ITEM_BEAST_BALL)
                ballMultiplier = 500;
            else
                ballMultiplier = 10;
        }
        else
        {
            switch (gLastUsedItem)
            {
            case ITEM_ULTRA_BALL:
                ballMultiplier = 200;
                break;
            case ITEM_SPORT_BALL:
                if (B_SPORT_BALL_MODIFIER <= GEN_7)
                    ballMultiplier = 150;
                break;
            case ITEM_GREAT_BALL:
                ballMultiplier = 150;
                break;
            case ITEM_SAFARI_BALL:
                if (B_SAFARI_BALL_MODIFIER <= GEN_7)
                    ballMultiplier = 150;
                break;
            case ITEM_NET_BALL:
                if (IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_WATER) || IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_BUG))
                    ballMultiplier = B_NET_BALL_MODIFIER >= GEN_7 ? 350 : 300;
                break;
            case ITEM_DIVE_BALL:
                if (GetCurrentMapType() == MAP_TYPE_UNDERWATER
                    || (B_DIVE_BALL_MODIFIER >= GEN_4 && (gIsFishingEncounter || gIsSurfingEncounter)))
                    ballMultiplier = 350;
                break;
            case ITEM_NEST_BALL:
                if (B_NEST_BALL_MODIFIER >= GEN_6)
                {
                    //((41 - Pokémon's level) ÷ 10)× if Pokémon's level is between 1 and 29, 1× otherwise.
                    if (gBattleMons[gBattlerTarget].level < 30)
                        ballMultiplier = 410 - (gBattleMons[gBattlerTarget].level * 10);
                }
                else if (B_NEST_BALL_MODIFIER >= GEN_5)
                {
                    //((41 - Pokémon's level) ÷ 10)×, minimum 1×
                    if (gBattleMons[gBattlerTarget].level < 31)
                        ballMultiplier = 410 - (gBattleMons[gBattlerTarget].level * 10);
                }
                else if (gBattleMons[gBattlerTarget].level < 40)
                {
                    //((40 - Pokémon's level) ÷ 10)×, minimum 1×
                    ballMultiplier = 400 - (gBattleMons[gBattlerTarget].level * 10);
                    if (ballMultiplier <= 90)
                        ballMultiplier = 100;
                }
                break;
            case ITEM_REPEAT_BALL:
                if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gBattlerTarget].species), FLAG_GET_CAUGHT))
                    ballMultiplier = (B_REPEAT_BALL_MODIFIER >= GEN_7 ? 350 : 300);
                break;
            case ITEM_TIMER_BALL:
                ballMultiplier = 100 + (gBattleResults.battleTurnCounter * (B_TIMER_BALL_MODIFIER >= GEN_5 ? 30 : 10));
                if (ballMultiplier > 400)
                    ballMultiplier = 400;
                break;
            case ITEM_DUSK_BALL:
                i = GetTimeOfDay();
                if (i == TIME_EVENING || i == TIME_NIGHT || gMapHeader.cave || gMapHeader.mapType == MAP_TYPE_UNDERGROUND)
                    ballMultiplier = (B_DUSK_BALL_MODIFIER >= GEN_7 ? 300 : 350);
                break;
            case ITEM_QUICK_BALL:
                if (gBattleResults.battleTurnCounter == 0)
                    ballMultiplier = (B_QUICK_BALL_MODIFIER >= GEN_5 ? 500 : 400);
                break;
            case ITEM_LEVEL_BALL:
                if (gBattleMons[gBattlerAttacker].level >= 4 * gBattleMons[gBattlerTarget].level)
                    ballMultiplier = 800;
                else if (gBattleMons[gBattlerAttacker].level > 2 * gBattleMons[gBattlerTarget].level)
                    ballMultiplier = 400;
                else if (gBattleMons[gBattlerAttacker].level > gBattleMons[gBattlerTarget].level)
                    ballMultiplier = 200;
                break;
            case ITEM_LURE_BALL:
                if (gIsFishingEncounter)
                {
                    if (B_LURE_BALL_MODIFIER >= GEN_8)
                        ballMultiplier = 400;
                    else if (B_LURE_BALL_MODIFIER >= GEN_7)
                        ballMultiplier = 500;
                    else
                        ballMultiplier = 300;
                }
                break;
            case ITEM_MOON_BALL:
            {
                const struct Evolution *evolutions = GetSpeciesEvolutions(gBattleMons[gBattlerTarget].species);
                if (evolutions == NULL)
                    break;
                for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
                {
                    if (evolutions[i].method == EVO_ITEM
                        && evolutions[i].param == ITEM_MOON_STONE)
                        ballMultiplier = 400;
                }
            }
            break;
            case ITEM_LOVE_BALL:
                if (gBattleMons[gBattlerTarget].species == gBattleMons[gBattlerAttacker].species)
                {
                    u8 gender1 = GetMonGender(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]]);
                    u8 gender2 = GetMonGender(&gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]]);

                    if (gender1 != gender2 && gender1 != MON_GENDERLESS && gender2 != MON_GENDERLESS)
                        ballMultiplier = 800;
                }
                break;
            case ITEM_FAST_BALL:
                if (gSpeciesInfo[gBattleMons[gBattlerTarget].species].baseSpeed >= 100)
                    ballMultiplier = 400;
                break;
            case ITEM_HEAVY_BALL:
                i = GetSpeciesWeight(gBattleMons[gBattlerTarget].species);
                if (B_HEAVY_BALL_MODIFIER >= GEN_7)
                {
                    if (i < 1000)
                        ballAddition = -20;
                    else if (i < 2000)
                        ballAddition = 0;
                    else if (i < 3000)
                        ballAddition = 20;
                    else
                        ballAddition = 30;
                }
                else if (B_HEAVY_BALL_MODIFIER >= GEN_4)
                {
                    if (i < 2048)
                        ballAddition = -20;
                    else if (i < 3072)
                        ballAddition = 20;
                    else if (i < 4096)
                        ballAddition = 30;
                    else
                        ballAddition = 40;
                }
                else
                {
                    if (i < 1024)
                        ballAddition = -20;
                    else if (i < 2048)
                        ballAddition = 0;
                    else if (i < 3072)
                        ballAddition = 20;
                    else if (i < 4096)
                        ballAddition = 30;
                    else
                        ballAddition = 40;
                }
                break;
            case ITEM_DREAM_BALL:
                if (B_DREAM_BALL_MODIFIER >= GEN_8 && (gBattleMons[gBattlerTarget].status1 & STATUS1_SLEEP || GetBattlerAbility(gBattlerTarget) == ABILITY_COMATOSE))
                    ballMultiplier = 400;
                break;
            case ITEM_BEAST_BALL:
                ballMultiplier = 10;
                break;
            }
        }

        // catchRate is unsigned, which means that it may potentially overflow if sum is applied directly.
        if (catchRate < 21 && ballAddition == -20)
            catchRate = 1;
        else
            catchRate = catchRate + ballAddition;

        odds = (catchRate * ballMultiplier / 100)
            * (gBattleMons[gBattlerTarget].maxHP * 3 - gBattleMons[gBattlerTarget].hp * 2)
            / (3 * gBattleMons[gBattlerTarget].maxHP);

        if (gBattleMons[gBattlerTarget].status1 & (STATUS1_SLEEP | STATUS1_FREEZE))
            odds *= 2;
        if (gBattleMons[gBattlerTarget].status1 & (STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON | STATUS1_FROSTBITE))
            odds = (odds * 15) / 10;

        if (gBattleResults.catchAttempts[gLastUsedItem - FIRST_BALL] < 255)
            gBattleResults.catchAttempts[gLastUsedItem - FIRST_BALL]++;

        if (odds > 254) // mon caught
        {
            BtlController_EmitBallThrowAnim(gBattlerAttacker, BUFFER_A, BALL_3_SHAKES_SUCCESS);
            MarkBattlerForControllerExec(gBattlerAttacker);
            TryBattleFormChange(gBattlerTarget, FORM_CHANGE_END_BATTLE);
            gBattlescriptCurrInstr = BattleScript_SuccessBallThrow;
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_POKEBALL, &gLastUsedItem);

            if (CalculatePlayerPartyCount() == PARTY_SIZE)
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;

            if (gLastUsedItem == ITEM_HEAL_BALL)
            {
                MonRestorePP(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]]);
                HealStatusConditions(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], STATUS1_ANY, gBattlerTarget);
                gBattleMons[gBattlerTarget].hp = gBattleMons[gBattlerTarget].maxHP;
                SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_HP, &gBattleMons[gBattlerTarget].hp);
            }
        }
        else // mon may be caught, calculate shakes
        {
            u8 shakes;
            u8 maxShakes;

            gBattleSpritesDataPtr->animationData->isCriticalCapture = FALSE;
            gBattleSpritesDataPtr->animationData->criticalCaptureSuccess = FALSE;

            if (CriticalCapture(odds))
            {
                maxShakes = BALL_1_SHAKE;  // critical capture doesn't guarantee capture
                gBattleSpritesDataPtr->animationData->isCriticalCapture = TRUE;
            }
            else
            {
                maxShakes = BALL_3_SHAKES_SUCCESS;
            }

            if (gLastUsedItem == ITEM_MASTER_BALL)
            {
                shakes = maxShakes;
            }
            else
            {
                odds = Sqrt(Sqrt(16711680 / odds));
                odds = 1048560 / odds;
                for (shakes = 0; shakes < maxShakes && Random() < odds; shakes++);
            }

            BtlController_EmitBallThrowAnim(gBattlerAttacker, BUFFER_A, shakes);
            MarkBattlerForControllerExec(gBattlerAttacker);

            if (shakes == maxShakes) // mon caught, copy of the code above
            {
                if (IsCriticalCapture())
                    gBattleSpritesDataPtr->animationData->criticalCaptureSuccess = TRUE;

                TryBattleFormChange(gBattlerTarget, FORM_CHANGE_END_BATTLE);
                gBattlescriptCurrInstr = BattleScript_SuccessBallThrow;
                SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_POKEBALL, &gLastUsedItem);

                if (CalculatePlayerPartyCount() == PARTY_SIZE)
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;

                if (gLastUsedItem == ITEM_HEAL_BALL)
                {
                    MonRestorePP(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]]);
                    HealStatusConditions(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], STATUS1_ANY, gBattlerTarget);
                    gBattleMons[gBattlerTarget].hp = gBattleMons[gBattlerTarget].maxHP;
                    SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_HP, &gBattleMons[gBattlerTarget].hp);
                }
            }
            else // not caught
            {
                if (!gHasFetchedBall)
                    gLastUsedBall = gLastUsedItem;

                if (IsCriticalCapture())
                    gBattleCommunication[MULTISTRING_CHOOSER] = BALL_3_SHAKES_FAIL;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = shakes;

                gBattlescriptCurrInstr = BattleScript_ShakeBallThrow;
            }
        }
    }
}

static void Cmd_givecaughtmon(void)
{
    CMD_ARGS();

    if (B_RESTORE_HELD_BATTLE_ITEMS >= GEN_9)
    {
        u16 lostItem = gBattleStruct->itemLost[B_SIDE_OPPONENT][gBattlerPartyIndexes[GetCatchingBattler()]].originalItem;
        if (lostItem != ITEM_NONE && ItemId_GetPocket(lostItem) != POCKET_BERRIES)
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_HELD_ITEM, &lostItem);  // Restore non-berry items
    }

    if (GiveMonToPlayer(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]]) != MON_GIVEN_TO_PARTY)
    {
        if (!ShouldShowBoxWasFullMessage())
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SENT_SOMEONES_PC;
            StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_PC_BOX_TO_SEND_MON)));
            GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_NICKNAME, gStringVar2);
        }
        else
        {
            StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_PC_BOX_TO_SEND_MON))); // box the mon was sent to
            GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_NICKNAME, gStringVar2);
            StringCopy(gStringVar3, GetBoxNamePtr(GetPCBoxToSendMon())); //box the mon was going to be sent to
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SOMEONES_BOX_FULL;
        }

        // Change to B_MSG_SENT_LANETTES_PC or B_MSG_LANETTES_BOX_FULL
        if (FlagGet(FLAG_SYS_PC_LANETTE))
            gBattleCommunication[MULTISTRING_CHOOSER]++;
    }

    gBattleResults.caughtMonSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_SPECIES, NULL);
    GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_NICKNAME, gBattleResults.caughtMonNick);
    gBattleResults.caughtMonBall = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_POKEBALL, NULL);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_trysetcaughtmondexflags(void)
{
    CMD_ARGS(const u8 *failInstr);

    u32 species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_SPECIES, NULL);
    u32 personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_PERSONALITY, NULL);

    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_SET_CAUGHT, personality);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_displaydexinfo(void)
{
    CMD_ARGS();

    u16 species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_SPECIES, NULL);

    switch (gBattleCommunication[0])
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gBattleCommunication[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            struct Pokemon *mon = &gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]];
            FreeAllWindowBuffers();
            gBattleCommunication[TASK_ID] = DisplayCaughtMonDexPage(species,
                                                                    GetMonData(mon, MON_DATA_IS_SHINY),
                                                                    GetMonData(mon, MON_DATA_PERSONALITY));
            gBattleCommunication[0]++;
        }
        break;
    case 2:
        if (!gPaletteFade.active
            && gMain.callback2 == BattleMainCB2
            && !gTasks[gBattleCommunication[TASK_ID]].isActive)
        {
            SetVBlankCallback(VBlankCB_Battle);
            gBattleCommunication[0]++;
        }
        break;
    case 3:
        InitBattleBgsVideo();
        LoadBattleTextboxAndBackground();
        gBattle_BG3_X = 256;
        gBattleCommunication[0]++;
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            BeginNormalPaletteFade(PALETTES_BG, 0, 16, 0, RGB_BLACK);
            ShowBg(0);
            ShowBg(3);
            gBattleCommunication[0]++;
        }
        break;
    case 5:
        if (!gPaletteFade.active)
            gBattlescriptCurrInstr = cmd->nextInstr;
        break;
    }
}

void HandleBattleWindow(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags)
{
    s32 destY, destX, bgId;
    u16 var = 0;

    for (destY = yStart; destY <= yEnd; destY++)
    {
        for (destX = xStart; destX <= xEnd; destX++)
        {
            if (destY == yStart)
            {
                if (destX == xStart)
                    var = 0x1022;
                else if (destX == xEnd)
                    var = 0x1024;
                else
                    var = 0x1023;
            }
            else if (destY == yEnd)
            {
                if (destX == xStart)
                    var = 0x1028;
                else if (destX == xEnd)
                    var = 0x102A;
                else
                    var = 0x1029;
            }
            else
            {
                if (destX == xStart)
                    var = 0x1025;
                else if (destX == xEnd)
                    var = 0x1027;
                else
                    var = 0x1026;
            }

            if (flags & WINDOW_CLEAR)
                var = 0;

            bgId = (flags & WINDOW_BG1) ? 1 : 0;
            CopyToBgTilemapBufferRect_ChangePalette(bgId, &var, destX, destY, 1, 1, 0x11);
        }
    }
}

void BattleCreateYesNoCursorAt(u8 cursorPosition)
{
    u16 src[2];
    src[0] = 1;
    src[1] = 2;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 0x19, 9 + (2 * cursorPosition), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);
}

void BattleDestroyYesNoCursorAt(u8 cursorPosition)
{
    u16 src[2];
    src[0] = 0x1016;
    src[1] = 0x1016;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 0x19, 9 + (2 * cursorPosition), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);
}

static void Cmd_trygivecaughtmonnick(void)
{
    CMD_ARGS(const u8 *successInstr);

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        HandleBattleWindow(YESNOBOX_X_Y, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, B_WIN_YESNO);
        gBattleCommunication[MULTIUSE_STATE]++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateYesNoCursorAt(0);
        break;
    case 1:
        if (JOY_NEW(DPAD_UP) && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateYesNoCursorAt(0);
        }
        if (JOY_NEW(DPAD_DOWN) && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
        }
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                gBattleCommunication[MULTIUSE_STATE]++;
                BeginFastPaletteFade(3);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 4;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBattleCommunication[MULTIUSE_STATE] = 4;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_NICKNAME, gBattleStruct->caughtMonNick);
            FreeAllWindowBuffers();

            DoNamingScreen(NAMING_SCREEN_CAUGHT_MON, gBattleStruct->caughtMonNick,
                           GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_SPECIES),
                           GetMonGender(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]]),
                           GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_PERSONALITY, NULL),
                           BattleMainCB2);

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
        {
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_NICKNAME, gBattleStruct->caughtMonNick);
            gBattlescriptCurrInstr = cmd->successInstr;
        }
        break;
    case 4:
        if (CalculatePlayerPartyCount() == PARTY_SIZE)
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->successInstr;
        break;
    }
}

static void Cmd_subattackerhpbydmg(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerAttacker].hp -= gBattleMoveDamage;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_removeattackerstatus1(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerAttacker].status1 = 0;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// CMD_ARGS is not needed for these functions as they end the script execution.
static void Cmd_finishaction(void)
{
    gCurrentActionFuncId = B_ACTION_FINISHED;
}

static void Cmd_finishturn(void)
{
    gCurrentActionFuncId = B_ACTION_FINISHED;
    gCurrentTurnActionNumber = gBattlersCount;
}

static void Cmd_trainerslideout(void)
{
    CMD_ARGS(u8 position);

    u32 battler = GetBattlerForBattleScript(cmd->position);
    BtlController_EmitTrainerSlideBack(battler, BUFFER_A);
    MarkBattlerForControllerExec(battler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static const u16 sTelekinesisBanList[] =
{
    SPECIES_DIGLETT,
    SPECIES_DUGTRIO,
    SPECIES_DIGLETT_ALOLAN,
    SPECIES_DUGTRIO_ALOLAN,
    SPECIES_SANDYGAST,
    SPECIES_PALOSSAND,
    SPECIES_GENGAR_MEGA,
};

bool32 IsTelekinesisBannedSpecies(u16 species)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sTelekinesisBanList); i++)
    {
        if (species == sTelekinesisBanList[i])
            return TRUE;
    }
    return FALSE;
}

static void Cmd_settelekinesis(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gStatuses3[gBattlerTarget] & (STATUS3_TELEKINESIS | STATUS3_ROOTED | STATUS3_SMACKED_DOWN)
        || gFieldStatuses & STATUS_FIELD_GRAVITY
        || IsTelekinesisBannedSpecies(gBattleMons[gBattlerTarget].species))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gStatuses3[gBattlerTarget] |= STATUS3_TELEKINESIS;
        gDisableStructs[gBattlerTarget].telekinesisTimer = 3;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_swapstatstages(void)
{
    CMD_ARGS(u8 stat);

    u8 stat = cmd->stat;
    s8 atkStatStage = gBattleMons[gBattlerAttacker].statStages[stat];
    s8 defStatStage = gBattleMons[gBattlerTarget].statStages[stat];

    gBattleMons[gBattlerAttacker].statStages[stat] = defStatStage;
    gBattleMons[gBattlerTarget].statStages[stat] = atkStatStage;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static u16 *GetBattlerStat(struct BattlePokemon *battler, u32 stat)
{
    switch (stat)
    {
    case STAT_ATK:   return &battler->attack;
    case STAT_DEF:   return &battler->defense;
    case STAT_SPATK: return &battler->spAttack;
    case STAT_SPDEF: return &battler->spDefense;
    default:         return NULL;
    }
}

static void Cmd_averagestats(void)
{
    CMD_ARGS(u8 stat);

    u16 *stat1 = GetBattlerStat(&gBattleMons[gBattlerAttacker], cmd->stat);
    u16 *stat2 = GetBattlerStat(&gBattleMons[gBattlerTarget], cmd->stat);
    u16 avg = (*stat1 + *stat2) / 2;
    *stat1 = *stat2 = avg;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifoppositegenders(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (AreBattlersOfOppositeGender(gBattlerAttacker, gBattlerTarget))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_unused(void)
{
}

static void Cmd_tryworryseed(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gAbilitiesInfo[gBattleMons[gBattlerTarget].ability].cantBeOverwritten
      || gBattleMons[gBattlerTarget].ability == ABILITY_INSOMNIA)
    {
        RecordAbilityBattle(gBattlerTarget, gBattleMons[gBattlerTarget].ability);
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (GetBattlerHoldEffect(gBattlerTarget, TRUE) == HOLD_EFFECT_ABILITY_SHIELD)
    {
        RecordItemEffectBattle(gBattlerTarget, HOLD_EFFECT_ABILITY_SHIELD);
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleMons[gBattlerTarget].ability = gBattleStruct->overwrittenAbilities[gBattlerTarget] = ABILITY_INSOMNIA;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_callnative(void)
{
    CMD_ARGS(void (*func)(void));
    void (*func)(void) = cmd->func;
    func();
}

// Callnative Funcs

static void SaveBattlerTarget(u32 battler)
{
    if (gBattleStruct->savedTargetCount < NELEMS(gBattleStruct->savedBattlerTarget))
        gBattleStruct->savedBattlerTarget[gBattleStruct->savedTargetCount++] = battler;
    else
        DebugPrintfLevel(MGBA_LOG_WARN, "Attempting to exceed savedBattlerTarget array size!");
}

static void SaveBattlerAttacker(u32 battler)
{
    if (gBattleStruct->savedAttackerCount < NELEMS(gBattleStruct->savedBattlerAttacker))
        gBattleStruct->savedBattlerAttacker[gBattleStruct->savedAttackerCount++] = battler;
    else
        DebugPrintfLevel(MGBA_LOG_WARN, "Attempting to exceed savedBattlerAttacker array size!");
}

void BS_SaveTarget(void)
{
    NATIVE_ARGS();
    SaveBattlerTarget(gBattlerTarget);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_RestoreTarget(void)
{
    NATIVE_ARGS();
    if (gBattleStruct->savedTargetCount > 0)
    {
        gBattleStruct->savedTargetCount--;
        gBattlerTarget = gBattleStruct->savedBattlerTarget[gBattleStruct->savedTargetCount];
    }
    else
    {
        // #if TESTING
        // Test_ExitWithResult(TEST_RESULT_ERROR, "BS_RestoreTarget attempting to restore an empty target!");
        // #else
        DebugPrintfLevel(MGBA_LOG_WARN, "BS_RestoreTarget attempting to restore an empty target!");
        // #endif
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_SaveAttacker(void)
{
    NATIVE_ARGS();
    SaveBattlerAttacker(gBattlerAttacker);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_RestoreAttacker(void)
{
    NATIVE_ARGS();
    if (gBattleStruct->savedAttackerCount > 0)
    {
        gBattleStruct->savedAttackerCount--;
        gBattlerAttacker = gBattleStruct->savedBattlerAttacker[gBattleStruct->savedAttackerCount];
    }
    else
    {
        // #if TESTING
        // Test_ExitWithResult(TEST_RESULT_ERROR,  "BS_RestoreAttacker attempting to restore an empty attacker!");
        // #else
        DebugPrintfLevel(MGBA_LOG_WARN, "BS_RestoreAttacker attempting to restore an empty attacker!");
        // #endif
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_CalcMetalBurstDmg(void)
{
    NATIVE_ARGS(const u8 *failInstr);

    u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
    u8 sideTarget = 0;

    if (gProtectStructs[gBattlerAttacker].physicalDmg
        && sideAttacker != (sideTarget = GetBattlerSide(gProtectStructs[gBattlerAttacker].physicalBattlerId))
        && gBattleMons[gProtectStructs[gBattlerAttacker].physicalBattlerId].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBattlerAttacker].physicalDmg * 150 / 100;

        if (IsAffectedByFollowMe(gBattlerAttacker, sideTarget, gCurrentMove))
            gBattlerTarget = gSideTimers[sideTarget].followmeTarget;
        else
            gBattlerTarget = gProtectStructs[gBattlerAttacker].physicalBattlerId;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (gProtectStructs[gBattlerAttacker].specialDmg
             && sideAttacker != (sideTarget = GetBattlerSide(gProtectStructs[gBattlerAttacker].specialBattlerId))
             && gBattleMons[gProtectStructs[gBattlerAttacker].specialBattlerId].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBattlerAttacker].specialDmg * 150 / 100;

        if (IsAffectedByFollowMe(gBattlerAttacker, sideTarget, gCurrentMove))
            gBattlerTarget = gSideTimers[sideTarget].followmeTarget;
        else
            gBattlerTarget = gProtectStructs[gBattlerAttacker].specialBattlerId;

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

void BS_JumpIfCantFling(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (!CanFling(battler))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfMoreThanHalfHP(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (gBattleMons[battler].hp > (gBattleMons[battler].maxHP + 1) / 2)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_DoStockpileStatChangesWearOff(void)
{
    NATIVE_ARGS(u8 battler, const u8 *statChangeInstr);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (gDisableStructs[battler].stockpileDef != 0)
    {
        SET_STATCHANGER(STAT_DEF, abs(gDisableStructs[battler].stockpileDef), TRUE);
        gDisableStructs[battler].stockpileDef = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = cmd->statChangeInstr;
    }
    else if (gDisableStructs[battler].stockpileSpDef)
    {
        SET_STATCHANGER(STAT_SPDEF, abs(gDisableStructs[battler].stockpileSpDef), TRUE);
        gDisableStructs[battler].stockpileSpDef = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = cmd->statChangeInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static bool32 CriticalCapture(u32 odds)
{
    u32 numCaught;

    if (B_CRITICAL_CAPTURE == FALSE)
        return FALSE;

    numCaught = GetNationalPokedexCount(FLAG_GET_CAUGHT);

    if (numCaught <= (NATIONAL_DEX_COUNT * 30) / 650)
        odds = 0;
    else if (numCaught <= (NATIONAL_DEX_COUNT * 150) / 650)
        odds /= 2;
    else if (numCaught <= (NATIONAL_DEX_COUNT * 300) / 650)
        ;   // odds = (odds * 100) / 100;
    else if (numCaught <= (NATIONAL_DEX_COUNT * 450) / 650)
        odds = (odds * 150) / 100;
    else if (numCaught <= (NATIONAL_DEX_COUNT * 600) / 650)
        odds *= 2;
    else
        odds = (odds * 250) / 100;

    if (CheckBagHasItem(ITEM_CATCHING_CHARM, 1))
        odds = (odds * (100 + B_CATCHING_CHARM_BOOST)) / 100;

    odds /= 6;
    if ((Random() % 255) < odds)
        return TRUE;

    return FALSE;
}

bool32 IsMoveAffectedByParentalBond(u32 move, u32 battler)
{
    if (move != MOVE_NONE && move != MOVE_UNAVAILABLE && move != MOVE_STRUGGLE
        && !gMovesInfo[move].parentalBondBanned
        && gMovesInfo[move].category != DAMAGE_CATEGORY_STATUS
        && gMovesInfo[move].strikeCount < 2
        && gMovesInfo[move].effect != EFFECT_MULTI_HIT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            switch (GetBattlerMoveTargetType(battler, move))
            {
            // Both foes are alive, spread move strikes once
            case MOVE_TARGET_BOTH:
                if (CountAliveMonsInBattle(BATTLE_ALIVE_SIDE, gBattlerTarget) >= 2)
                    return FALSE;
                break;
            // Either both foes or one foe and its ally are alive; spread move strikes once
            case MOVE_TARGET_FOES_AND_ALLY:
                if (CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_BATTLER, gBattlerAttacker) >= 2)
                    return FALSE;
                break;
            default:
            break;
            }
        }
        return TRUE;
    }
    return FALSE;
}

static bool8 IsFinalStrikeEffect(u32 moveEffect)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sFinalStrikeOnlyEffects); i++)
    {
        if (moveEffect == sFinalStrikeOnlyEffects[i])
            return TRUE;
    }
    return FALSE;
}

static bool8 CanAbilityPreventStatLoss(u16 abilityDef)
{
    switch (abilityDef)
    {
    case ABILITY_CLEAR_BODY:
    case ABILITY_FULL_METAL_BODY:
    case ABILITY_WHITE_SMOKE:
        return TRUE;
    }
    return FALSE;
}

static bool8 CanBurnHitThaw(u16 move)
{
    u8 i;

    if (B_BURN_HIT_THAW >= GEN_6)
    {
        for (i = 0; i < gMovesInfo[move].numAdditionalEffects; i++)
        {
            if (gMovesInfo[move].additionalEffects[i].moveEffect == MOVE_EFFECT_BURN)
                return TRUE;
        }
    }
    return FALSE;
}

void BS_CheckParentalBondCounter(void)
{
    NATIVE_ARGS(u8 counter, const u8 *jumpInstr);
    // Some effects should only happen on the first or second strike of Parental Bond,
    // so a way to check this in battle scripts is useful
    if (gSpecialStatuses[gBattlerAttacker].parentalBondState == cmd->counter && IsBattlerAlive(gBattlerTarget))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfCantLoseItem(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);
    u8 battler = GetBattlerForBattleScript(cmd->battler);
    u16 item = gBattleMons[battler].item;

    if (item == ITEM_NONE || !CanBattlerGetOrLoseItem(battler, item))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_GetBattlerSide(void)
{
    NATIVE_ARGS(u8 battler);
    gBattleCommunication[0] = GetBattlerSide(GetBattlerForBattleScript(cmd->battler));
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TrySymbiosis(void)
{
    NATIVE_ARGS();
    //called by Bestow, Fling, and Bug Bite, which don't work with Cmd_removeitem.
    u32 partner = BATTLE_PARTNER(gBattlerAttacker);
    if (SYMBIOSIS_CHECK(gBattlerAttacker, partner))
    {
        BestowItem(partner, gBattlerAttacker);
        gLastUsedAbility = gBattleMons[partner].ability;
        gBattleScripting.battler = gBattlerAbility = partner;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SymbiosisActivates;
        return;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_SetZEffect(void)
{
    SetZEffect();   // Handles battle script jumping internally
}

static void TryUpdateRoundTurnOrder(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u32 i;
        u32 j = 0;
        u32 k = 0;
        u32 currRounder = 0;
        u8 roundUsers[3] = {0xFF, 0xFF, 0xFF};
        u8 nonRoundUsers[3] = {0xFF, 0xFF, 0xFF};
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == gBattlerAttacker)
            {
                currRounder = i + 1; // Current battler going after attacker
                break;
            }
        }

        // Get battlers after us using round
        for (i = currRounder; i < gBattlersCount; i++)
        {
            if (gChosenMoveByBattler[gBattlerByTurnOrder[i]] == MOVE_ROUND)
                roundUsers[j++] = gBattlerByTurnOrder[i];
            else
                nonRoundUsers[k++] = gBattlerByTurnOrder[i];
        }

        // update turn order for round users
        for (i = 0; roundUsers[i] != 0xFF && i < 3; i++)
        {
            gBattlerByTurnOrder[currRounder] = roundUsers[i];
            gProtectStructs[roundUsers[i]].quash = TRUE; // Make it so their turn order can't be changed again
            currRounder++;
        }

        // Update turn order for non-round users
        for (i = 0; nonRoundUsers[i] != 0xFF && i < 3; i++)
        {
            gBattlerByTurnOrder[currRounder] = nonRoundUsers[i];
            currRounder++;
        }
    }
}

u8 GetFirstFaintedPartyIndex(u8 battler)
{
    u32 i;
    u32 start = 0;
    u32 end = PARTY_SIZE;
    struct Pokemon *party = GetBattlerParty(battler);

    // Check whether partner is separate trainer.
    if ((GetBattlerSide(battler) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        || (GetBattlerSide(battler) == B_SIDE_OPPONENT && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
    {
        if (GetBattlerPosition(battler) == B_POSITION_OPPONENT_LEFT
            || GetBattlerPosition(battler) == B_POSITION_PLAYER_LEFT)
        {
            end = PARTY_SIZE / 2;
        }
        else
        {
            start = PARTY_SIZE / 2;
        }
    }

    // Loop through to find fainted battler.
    for (i = start; i < end; ++i)
    {
        u32 species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE
            && species != SPECIES_EGG
            && GetMonData(&party[i], MON_DATA_HP) == 0)
        {
            return i;
        }
    }

    // Returns PARTY_SIZE if none found.
    return PARTY_SIZE;
}

void ApplyExperienceMultipliers(s32 *expAmount, u8 expGetterMonId, u8 faintedBattler)
{
    u32 holdEffect = GetMonHoldEffect(&gPlayerParty[expGetterMonId]);

    if (IsTradedMon(&gPlayerParty[expGetterMonId]))
        *expAmount = (*expAmount * 150) / 100;
    if (holdEffect == HOLD_EFFECT_LUCKY_EGG)
        *expAmount = (*expAmount * 150) / 100;
    if (B_UNEVOLVED_EXP_MULTIPLIER >= GEN_6 && IsMonPastEvolutionLevel(&gPlayerParty[expGetterMonId]))
        *expAmount = (*expAmount * 4915) / 4096;
    if (B_AFFECTION_MECHANICS == TRUE && GetMonAffectionHearts(&gPlayerParty[expGetterMonId]) >= AFFECTION_FOUR_HEARTS)
        *expAmount = (*expAmount * 4915) / 4096;
    if (CheckBagHasItem(ITEM_EXP_CHARM, 1)) //is also for other exp boosting Powers if/when implemented
        *expAmount = (*expAmount * 150) / 100;

    if (B_SCALED_EXP >= GEN_5 && B_SCALED_EXP != GEN_6)
    {
        // Note: There is an edge case where if a pokemon receives a large amount of exp, it wouldn't be properly calculated
        //       because of multiplying by scaling factor(the value would simply be larger than an u32 can hold). Hence u64 is needed.
        u64 value = *expAmount;
        u8 faintedLevel = gBattleMons[faintedBattler].level;
        u8 expGetterLevel = GetMonData(&gPlayerParty[expGetterMonId], MON_DATA_LEVEL);

        value *= sExperienceScalingFactors[(faintedLevel * 2) + 10];
        value /= sExperienceScalingFactors[faintedLevel + expGetterLevel + 10];

        *expAmount = value + 1;
    }
}

void BS_ItemRestoreHP(void)
{
    NATIVE_ARGS(const u8 *alreadyMaxHpInstr, const u8 *restoreBattlerInstr);
    u16 healAmount;
    u32 battler = MAX_BATTLERS_COUNT;
    u32 healParam = ItemId_GetEffect(gLastUsedItem)[6];
    u32 side = GetBattlerSide(gBattlerAttacker);
    struct Pokemon *party = GetSideParty(side);
    u16 hp = GetMonData(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], MON_DATA_HP);
    u16 maxHP = GetMonData(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], MON_DATA_MAX_HP);
    gBattleCommunication[MULTIUSE_STATE] = 0;

    if (hp == maxHP)
    {
        gBattlescriptCurrInstr = cmd->alreadyMaxHpInstr;
    }
    else
    {
        // Track the number of Revives used in a battle.
        if (hp == 0 && side == B_SIDE_PLAYER && gBattleResults.numRevivesUsed < 255)
            gBattleResults.numRevivesUsed++;

        // Check if the recipient is an active battler.
        if (gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[gBattlerAttacker])
            battler = gBattlerAttacker;
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                    && gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerAttacker)])
            battler = BATTLE_PARTNER(gBattlerAttacker);

        // Get amount to heal.
        switch (healParam)
        {
            case ITEM6_HEAL_HP_FULL:
                healAmount = maxHP;
                break;
            case ITEM6_HEAL_HP_HALF:
                healAmount = maxHP / 2;
                break;
            case ITEM6_HEAL_HP_QUARTER:
                healAmount = maxHP / 4;
                break;
            default:
                healAmount = healParam;
                break;
        }
        if (hp + healAmount > maxHP)
            healAmount = maxHP - hp;

        gBattleScripting.battler = battler;
        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, GetMonData(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], MON_DATA_SPECIES));

        // Heal is applied as move damage if battler is active.
        if (battler != MAX_BATTLERS_COUNT && hp != 0)
        {
            gBattleMoveDamage = -healAmount;
            gBattlescriptCurrInstr = cmd->restoreBattlerInstr;
        }
        else
        {
            hp += healAmount;
            SetMonData(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], MON_DATA_HP, &hp);

            // Revived battlers on the field need to be brought back.
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && battler != MAX_BATTLERS_COUNT)
            {
                gAbsentBattlerFlags &= ~gBitTable[battler];
                gBattleMons[battler].hp = hp;
                gBattleCommunication[MULTIUSE_STATE] = TRUE;
            }
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
}

void BS_ItemCureStatus(void)
{
    NATIVE_ARGS(const u8 *noStatusInstr);
    u32 battler = gBattlerAttacker;
    u32 side = GetBattlerSide(gBattlerAttacker);
    u32 previousStatus2 = 0;
    bool32 statusChanged = FALSE;
    struct Pokemon *party = GetSideParty(side);

    // Heal Status2 conditions if battler is active.
    if (gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[gBattlerAttacker])
    {
        previousStatus2 = gBattleMons[battler].status2;
        gBattleMons[gBattlerAttacker].status2 &= ~GetItemStatus2Mask(gLastUsedItem);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                && gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerAttacker)])
    {
        battler = BATTLE_PARTNER(gBattlerAttacker);
        previousStatus2 = gBattleMons[battler].status2;
        gBattleMons[battler].status2 &= ~GetItemStatus2Mask(gLastUsedItem);
    }

    if (previousStatus2 != gBattleMons[battler].status2)
        statusChanged = TRUE;

    // Heal Status1 conditions.
    if (!HealStatusConditions(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], GetItemStatus1Mask(gLastUsedItem), battler))
    {
        statusChanged = TRUE;
        if (GetItemStatus1Mask(gLastUsedItem) & STATUS1_SLEEP)
            gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
        if (GetItemStatus2Mask(gLastUsedItem) & STATUS2_CONFUSION)
            gStatuses4[battler] &= ~STATUS4_INFINITE_CONFUSION;
    }

    if (statusChanged)
    {
        gBattleScripting.battler = battler;
        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, GetMonData(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], MON_DATA_SPECIES));
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->noStatusInstr;
    }
}

void BS_ItemIncreaseStat(void)
{
    NATIVE_ARGS();
    u16 statId = ItemId_GetEffect(gLastUsedItem)[1];
    u16 stages = ItemId_GetHoldEffectParam(gLastUsedItem);
    SET_STATCHANGER(statId, stages, FALSE);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_ItemRestorePP(void)
{
    NATIVE_ARGS();
    const u8 *effect = ItemId_GetEffect(gLastUsedItem);
    u32 i, pp, maxPP, moveId, loopEnd;
    u32 battler = MAX_BATTLERS_COUNT;
    struct Pokemon *mon = (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER) ? &gPlayerParty[gBattleStruct->itemPartyIndex[gBattlerAttacker]] : &gEnemyParty[gBattleStruct->itemPartyIndex[gBattlerAttacker]];

    // Check whether to apply to all moves.
    if (effect[4] & ITEM4_HEAL_PP_ONE)
    {
        i = gBattleStruct->itemMoveIndex[gBattlerAttacker];
        loopEnd = i + 1;
    }
    else
    {
        i = 0;
        loopEnd = MAX_MON_MOVES;
    }

    // Check if the recipient is an active battler.
    if (gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[gBattlerAttacker])
        battler = gBattlerAttacker;
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                && gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerAttacker)])
        battler = BATTLE_PARTNER(gBattlerAttacker);

    // Heal PP!
    for (; i < loopEnd; i++)
    {
        pp = GetMonData(mon, MON_DATA_PP1 + i, NULL);
        moveId = GetMonData(mon, MON_DATA_MOVE1 + i, NULL);
        maxPP = CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), i);
        if (pp != maxPP)
        {
            pp += effect[6];
            if (pp > maxPP)
                pp = maxPP;
            SetMonData(mon, MON_DATA_PP1 + i, &pp);

            // Update battler PP if needed.
            if (battler != MAX_BATTLERS_COUNT
                && gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[battler]
                && MOVE_IS_PERMANENT(battler, i))
            {
                gBattleMons[battler].pp[i] = pp;
            }
        }
    }
    gBattleScripting.battler = battler;
    PREPARE_SPECIES_BUFFER(gBattleTextBuff1, GetMonData(mon, MON_DATA_SPECIES));
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryRevertWeatherForm(void)
{
    NATIVE_ARGS();
    if (TryBattleFormChange(gBattlerTarget, FORM_CHANGE_BATTLE_WEATHER))
    {
        gBattleScripting.battler = gBattlerTarget;
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_TargetFormChangeWithStringNoPopup;
        return;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_HandleMegaEvolution(void)
{
    NATIVE_ARGS(u8 battler, u8 caseId);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    HandleScriptMegaPrimalBurst(cmd->caseId, battler, HANDLE_TYPE_MEGA_EVOLUTION);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_HandlePrimalReversion(void)
{
    NATIVE_ARGS(u8 battler, u8 caseId);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    HandleScriptMegaPrimalBurst(cmd->caseId, battler, HANDLE_TYPE_PRIMAL_REVERSION);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_HandleUltraBurst(void)
{
    NATIVE_ARGS(u8 battler, u8 caseId);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    HandleScriptMegaPrimalBurst(cmd->caseId, battler, HANDLE_TYPE_ULTRA_BURST);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfShellTrap(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    if (gProtectStructs[battler].shellTrap)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfEmergencyExited(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);
    u8 battler = GetBattlerForBattleScript(cmd->battler);
    if (gSpecialStatuses[battler].emergencyExited)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfElectricAbilityAffected(void)
{
    NATIVE_ARGS(u8 battler, u16 ability, const u8 *jumpInstr);
    u32 battler = GetBattlerForBattleScript(cmd->battler);

    if (IsElectricAbilityAffected(battler, cmd->ability))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_ApplySaltCure(void)
{
    NATIVE_ARGS(u8 battler);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    gStatuses4[battler] |= STATUS4_SALT_CURE;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfArgument(void)
{
    NATIVE_ARGS(u8 argument, const u8 *jumpInstr);

    if (gMovesInfo[gCurrentMove].argument == cmd->argument)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_SetRemoveTerrain(void)
{
    NATIVE_ARGS(const u8 *jumpInstr);
    u32 statusFlag = 0;

    switch (gMovesInfo[gCurrentMove].effect)
    {
    case EFFECT_MISTY_TERRAIN:
        statusFlag = STATUS_FIELD_MISTY_TERRAIN;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_MISTY;
        break;
    case EFFECT_GRASSY_TERRAIN:
        statusFlag = STATUS_FIELD_GRASSY_TERRAIN;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_GRASSY;
        break;
    case EFFECT_ELECTRIC_TERRAIN:
        statusFlag = STATUS_FIELD_ELECTRIC_TERRAIN;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_ELECTRIC;
        break;
    case EFFECT_PSYCHIC_TERRAIN:
        statusFlag = STATUS_FIELD_PSYCHIC_TERRAIN;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_PSYCHIC;
        break;
    case EFFECT_HIT_SET_REMOVE_TERRAIN:
        switch (gMovesInfo[gCurrentMove].argument)
        {
        case ARG_SET_PSYCHIC_TERRAIN: // Genesis Supernova
            statusFlag = STATUS_FIELD_PSYCHIC_TERRAIN;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_PSYCHIC;
            break;
        case ARG_TRY_REMOVE_TERRAIN_HIT: // Splintered Stormshards
        case ARG_TRY_REMOVE_TERRAIN_FAIL: // Steel Roller
            if (!(gFieldStatuses & STATUS_FIELD_TERRAIN_ANY))
            {
                // No terrain to remove, jump to battle script pointer.
                gBattlescriptCurrInstr = cmd->jumpInstr;
            }
            else
            {
                // Remove all terrains.
                RemoveAllTerrains();
                gBattlescriptCurrInstr = cmd->nextInstr;
            }
            return;
        default:
            break;
        }
        break;
    }

    if (gFieldStatuses & statusFlag || statusFlag == 0)
    {
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
    {
        u32 atkHoldEffect = GetBattlerHoldEffect(gBattlerAttacker, TRUE);

        gFieldStatuses &= ~(STATUS_FIELD_TERRAIN_ANY | STATUS_FIELD_TERRAIN_PERMANENT);
        gFieldStatuses |= statusFlag;
        gFieldTimers.terrainTimer = (atkHoldEffect == HOLD_EFFECT_TERRAIN_EXTENDER) ? 8 : 5;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_JumpIfTerrainAffected(void)
{
    NATIVE_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);
    u32 battler = GetBattlerForBattleScript(cmd->battler);

    if (IsBattlerTerrainAffected(battler, cmd->flags))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryReflectType(void)
{
    NATIVE_ARGS(const u8 *failInstr);
    u16 targetBaseSpecies = GET_BASE_SPECIES_ID(gBattleMons[gBattlerTarget].species);
    u8 targetType1 = GetBattlerType(gBattlerTarget, 0, FALSE);
    u8 targetType2 = GetBattlerType(gBattlerTarget, 1, FALSE);
    u8 targetType3 = GetBattlerType(gBattlerTarget, 2, FALSE);

    if (targetBaseSpecies == SPECIES_ARCEUS || targetBaseSpecies == SPECIES_SILVALLY)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_TERA)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (IS_BATTLER_TYPELESS(gBattlerTarget))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else if (targetType1 == TYPE_MYSTERY && targetType2 == TYPE_MYSTERY && targetType3 != TYPE_MYSTERY)
    {
        gBattleMons[gBattlerAttacker].types[0] = TYPE_NORMAL;
        gBattleMons[gBattlerAttacker].types[1] = TYPE_NORMAL;
        gBattleMons[gBattlerAttacker].types[2] = targetType3;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (targetType1 == TYPE_MYSTERY && targetType2 != TYPE_MYSTERY)
    {
        gBattleMons[gBattlerAttacker].types[0] = targetType2;
        gBattleMons[gBattlerAttacker].types[1] = targetType2;
        gBattleMons[gBattlerAttacker].types[2] = targetType3;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (targetType1 != TYPE_MYSTERY && targetType2 == TYPE_MYSTERY)
    {
        gBattleMons[gBattlerAttacker].types[0] = targetType1;
        gBattleMons[gBattlerAttacker].types[1] = targetType1;
        gBattleMons[gBattlerAttacker].types[2] = targetType3;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattleMons[gBattlerAttacker].types[0] = targetType1;
        gBattleMons[gBattlerAttacker].types[1] = targetType2;
        gBattleMons[gBattlerAttacker].types[2] = targetType3;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_TrySetOctolock(void)
{
    NATIVE_ARGS(u8 battler, const u8 *failInstr);
    u32 battler = GetBattlerForBattleScript(cmd->battler);

    if (gDisableStructs[battler].octolock)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gDisableStructs[battler].octolock = TRUE;
        gBattleMons[battler].status2 |= STATUS2_ESCAPE_PREVENTION;
        gDisableStructs[battler].battlerPreventingEscape = gBattlerAttacker;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_SetGlaiveRush(void)
{
    NATIVE_ARGS();
    gStatuses4[gBattlerAttacker] |= STATUS4_GLAIVE_RUSH;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// TODO: Convert this to a proper FORM_CHANGE type.
void BS_TryRelicSong(void)
{
    NATIVE_ARGS();

    if (GetBattlerAbility(gBattlerAttacker) != ABILITY_SHEER_FORCE && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_TRANSFORMED)
        && (gBattleMons[gBattlerAttacker].species == SPECIES_MELOETTA_ARIA || gBattleMons[gBattlerAttacker].species == SPECIES_MELOETTA_PIROUETTE))
    {
        if (gBattleMons[gBattlerAttacker].species == SPECIES_MELOETTA_ARIA)
            gBattleMons[gBattlerAttacker].species = SPECIES_MELOETTA_PIROUETTE;
        else if (gBattleMons[gBattlerAttacker].species == SPECIES_MELOETTA_PIROUETTE)
            gBattleMons[gBattlerAttacker].species = SPECIES_MELOETTA_ARIA;

        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_AttackerFormChangeMoveEffect;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_SetPledge(void)
{
    NATIVE_ARGS(const u8 *jumpInstr);

    u32 partner = BATTLE_PARTNER(gBattlerAttacker);
    u32 partnerMove = gBattleMons[partner].moves[gBattleStruct->chosenMovePositions[partner]];
    u32 i = 0;
    u32 k = 0;

    if (gBattleStruct->pledgeMove && !(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE))
    {
        PrepareStringBattle(STRINGID_USEDMOVE, gBattlerAttacker);
        gHitMarker |= HITMARKER_ATTACKSTRING_PRINTED;

        if ((gCurrentMove == MOVE_GRASS_PLEDGE && partnerMove == MOVE_WATER_PLEDGE)
         || (gCurrentMove == MOVE_WATER_PLEDGE && partnerMove == MOVE_GRASS_PLEDGE))
        {
            gCurrentMove = MOVE_GRASS_PLEDGE;
            gBattlescriptCurrInstr = BattleScript_EffectCombinedPledge_Grass;
        }
        else if ((gCurrentMove == MOVE_FIRE_PLEDGE && partnerMove == MOVE_GRASS_PLEDGE)
              || (gCurrentMove == MOVE_GRASS_PLEDGE && partnerMove == MOVE_FIRE_PLEDGE))
        {
            gCurrentMove = MOVE_FIRE_PLEDGE;
            gBattlescriptCurrInstr = BattleScript_EffectCombinedPledge_Fire;
        }
        else if ((gCurrentMove == MOVE_WATER_PLEDGE && partnerMove == MOVE_FIRE_PLEDGE)
              || (gCurrentMove == MOVE_FIRE_PLEDGE && partnerMove == MOVE_WATER_PLEDGE))
        {
            gCurrentMove = MOVE_WATER_PLEDGE;
            gBattlescriptCurrInstr = BattleScript_EffectCombinedPledge_Water;
        }

        gBattleCommunication[MSG_DISPLAY] = 0;
    }
    else if ((gChosenActionByBattler[partner] == B_ACTION_USE_MOVE)
          && gBattleTypeFlags & BATTLE_TYPE_DOUBLE
          && IsBattlerAlive(partner)
          && GetBattlerTurnOrderNum(gBattlerAttacker) < GetBattlerTurnOrderNum(partner)
          && !(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE)
          && gCurrentMove != partnerMove
          && gMovesInfo[partnerMove].effect == EFFECT_PLEDGE)
    {
        u32 currPledgeUser = 0;
        u32 newTurnOrder[] = {0xFF, 0xFF};

        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == gBattlerAttacker)
            {
                currPledgeUser = i + 1; // Current battler going after attacker
                break;
            }
        }
        for (i = currPledgeUser; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] != partner)
            {
                newTurnOrder[k] = gBattlerByTurnOrder[i];
                k++;
            }
        }

        gBattlerByTurnOrder[currPledgeUser] = partner;
        currPledgeUser++;

        for (i = 0; newTurnOrder[i] != 0xFF && i < 2; i++)
        {
            gBattlerByTurnOrder[currPledgeUser] = newTurnOrder[i];
            currPledgeUser++;
        }

        gBattleStruct->pledgeMove = TRUE;
        gBattleScripting.battler = partner;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattleStruct->pledgeMove = FALSE;
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
}

void BS_SetPledgeStatus(void)
{
    NATIVE_ARGS(u8 battler, u32 sideStatus);

    u32 battler = GetBattlerForBattleScript(cmd->battler);
    u32 side = GetBattlerSide(battler);

    gBattleStruct->pledgeMove = FALSE;
    if (!(gSideStatuses[side] & cmd->sideStatus))
    {
        gSideStatuses[side] |= cmd->sideStatus;

        switch (cmd->sideStatus)
        {
        case SIDE_STATUS_RAINBOW:
            gSideTimers[side].rainbowTimer = 4;
            break;
        case SIDE_STATUS_SEA_OF_FIRE:
            gSideTimers[side].seaOfFireTimer = 4;
            break;
        case SIDE_STATUS_SWAMP:
            gSideTimers[side].swampTimer = 4;
        }

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
}

void BS_TryTrainerSlideZMoveMsg(void)
{
    NATIVE_ARGS();
    s32 shouldSlide;

    if ((shouldSlide = ShouldDoTrainerSlide(gBattlerAttacker, TRAINER_SLIDE_Z_MOVE)))
    {
        gBattleScripting.battler = gBattlerAttacker;
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = (shouldSlide == 1 ? BattleScript_TrainerASlideMsgRet : BattleScript_TrainerBSlideMsgRet);
    }
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryTrainerSlideMegaEvolutionMsg(void)
{
    NATIVE_ARGS();
    s32 shouldSlide;

    if ((shouldSlide = ShouldDoTrainerSlide(gBattlerAttacker, TRAINER_SLIDE_MEGA_EVOLUTION)))
    {
        gBattleScripting.battler = gBattlerAttacker;
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = (shouldSlide == 1 ? BattleScript_TrainerASlideMsgRet : BattleScript_TrainerBSlideMsgRet);
    }
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryTrainerSlideDynamaxMsg(void)
{
    NATIVE_ARGS();
    s32 shouldSlide;

    if ((shouldSlide = ShouldDoTrainerSlide(gBattleScripting.battler, TRAINER_SLIDE_DYNAMAX)))
    {
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = (shouldSlide == 1 ? BattleScript_TrainerASlideMsgRet : BattleScript_TrainerBSlideMsgRet);
    }
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryHealPulse(void)
{
    NATIVE_ARGS(const u8 *failInstr);

    if (BATTLER_MAX_HP(gBattlerTarget))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        if (GetBattlerAbility(gBattlerAttacker) == ABILITY_MEGA_LAUNCHER && gMovesInfo[gCurrentMove].pulseMove)
            gBattleMoveDamage = -(GetNonDynamaxMaxHP(gBattlerTarget) * 75 / 100);
        else if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN && gMovesInfo[gCurrentMove].argument == MOVE_EFFECT_FLORAL_HEALING)
            gBattleMoveDamage = -(GetNonDynamaxMaxHP(gBattlerTarget) * 2 / 3);
        else
            gBattleMoveDamage = -(GetNonDynamaxMaxHP(gBattlerTarget) / 2);

        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = -1;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_TryCopycat(void)
{
    NATIVE_ARGS(const u8 *failInstr);

    if (gLastUsedMove == MOVE_NONE || gLastUsedMove == MOVE_UNAVAILABLE || gMovesInfo[gLastUsedMove].copycatBanned || IsZMove(gLastUsedMove))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE && !IS_MOVE_STATUS(gLastUsedMove))
        {
            gBattleStruct->zmove.baseMoves[gBattlerAttacker] = gLastUsedMove;
            gCalledMove = GetTypeBasedZMove(gLastUsedMove);
        }
        else if (IsMaxMove(gLastUsedMove))
        {
            gCalledMove = gBattleStruct->dynamax.lastUsedBaseMove;
        }
        else
        {
            gCalledMove = gLastUsedMove;
        }

        gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
        gBattlerTarget = GetMoveTarget(gCalledMove, NO_TARGET_OVERRIDE);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_TryDefog(void)
{
    NATIVE_ARGS(u8 clear, const u8 *failInstr);

    if (cmd->clear)
    {
        if (TryDefogClear(gEffectBattler, TRUE))
            return;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        if (TryDefogClear(gBattlerAttacker, FALSE))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->failInstr;
    }
}

void BS_TryUpperHand(void)
{
    NATIVE_ARGS(const u8 *failInstr);

    if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget)
     || gChosenMoveByBattler[gBattlerTarget] == MOVE_NONE
     || IS_MOVE_STATUS(gChosenMoveByBattler[gBattlerTarget])
     || GetChosenMovePriority(gBattlerTarget) < 1 || GetChosenMovePriority(gBattlerTarget) > 3) // Fails if priority is less than 1 or greater than 3, if target already moved, or if using a status
        gBattlescriptCurrInstr = cmd->failInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryTriggerStatusForm(void)
{
    NATIVE_ARGS();
    if (TryBattleFormChange(gBattlerTarget, FORM_CHANGE_STATUS))
    {
        gBattleScripting.battler = gBattlerTarget;
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_TargetFormChangeWithStringNoPopup;
        return;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_AllySwitchSwapBattler(void)
{
    NATIVE_ARGS();

    gBattleScripting.battler = gBattlerAttacker;
    gBattlerAttacker ^= BIT_FLANK;
    gProtectStructs[gBattlerAttacker].usedAllySwitch = TRUE;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_AllySwitchFailChance(void)
{
    NATIVE_ARGS(const u8 *failInstr);

    if (B_ALLY_SWITCH_FAIL_CHANCE >= GEN_9)
    {
        TryResetProtectUseCounter(gBattlerAttacker);
        if (sProtectSuccessRates[gDisableStructs[gBattlerAttacker].protectUses] < Random())
        {
            gDisableStructs[gBattlerAttacker].protectUses = 0;
            gBattlescriptCurrInstr = cmd->failInstr;
            return;
        }
        else
        {
            gDisableStructs[gBattlerAttacker].protectUses++;
        }
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_SetPhotonGeyserCategory(void)
{
    NATIVE_ARGS();
    if (!((gMovesInfo[gCurrentMove].effect == EFFECT_TERA_BLAST && GetActiveGimmick(gBattlerAttacker) != GIMMICK_TERA)
            || (gMovesInfo[gCurrentMove].effect == EFFECT_TERA_STARSTORM && GetActiveGimmick(gBattlerAttacker) != GIMMICK_TERA && gBattleMons[gBattlerAttacker].species == SPECIES_TERAPAGOS_STELLAR)))
        gBattleStruct->swapDamageCategory = (GetCategoryBasedOnStats(gBattlerAttacker) != gMovesInfo[gCurrentMove].category);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_RunStatChangeItems(void)
{
    NATIVE_ARGS(u8 battler);

    // Change instruction before calling ItemBattleEffects.
    gBattlescriptCurrInstr = cmd->nextInstr;
    ItemBattleEffects(ITEMEFFECT_STATS_CHANGED, GetBattlerForBattleScript(cmd->battler), FALSE);
}

static void TryUpdateEvolutionTracker(u32 evolutionMethod, u32 upAmount, u16 usedMove)
{
    u32 i;

    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER
     && !(gBattleTypeFlags & (BATTLE_TYPE_LINK
                             | BATTLE_TYPE_EREADER_TRAINER
                             | BATTLE_TYPE_RECORDED_LINK
                             | BATTLE_TYPE_TRAINER_HILL
                             | BATTLE_TYPE_FRONTIER)))
    {
        const struct Evolution *evolutions = GetSpeciesEvolutions(gBattleMons[gBattlerAttacker].species);
        if (evolutions == NULL)
            return;

        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            if (evolutions[i].method == evolutionMethod)
            {
                // We only have 10 bits to use
                u16 val = min(1023, GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]], MON_DATA_EVOLUTION_TRACKER) + upAmount);
                // Reset progress if you faint for the recoil method.
                switch (evolutionMethod)
                {
                    case EVO_USE_MOVE_TWENTY_TIMES:
                        if (evolutions[i].param == usedMove)
                            SetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]], MON_DATA_EVOLUTION_TRACKER, &val);
                        break;
                    case EVO_RECOIL_DAMAGE_MALE:
                    case EVO_RECOIL_DAMAGE_FEMALE:
                        if (gBattleMons[gBattlerAttacker].hp == 0)
                            val = 0;
                        SetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]], MON_DATA_EVOLUTION_TRACKER, &val);
                        break;
                    case EVO_DEFEAT_THREE_WITH_ITEM:
                        if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_SPECIES) == GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]], MON_DATA_SPECIES)
                         && GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_HELD_ITEM) == evolutions[i].param)
                            SetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]], MON_DATA_EVOLUTION_TRACKER, &val);
                        break;
                }
                return;
            }
        }
    }
}

void BS_TryUpdateRecoilTracker(void)
{
    NATIVE_ARGS();
    u8 gender = GetMonGender(&gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]]);

    switch(gender)
    {
        case MON_MALE:
            TryUpdateEvolutionTracker(EVO_RECOIL_DAMAGE_MALE, gBattleMoveDamage, MOVE_NONE);
            break;
        case MON_FEMALE:
            TryUpdateEvolutionTracker(EVO_RECOIL_DAMAGE_FEMALE, gBattleMoveDamage, MOVE_NONE);
            break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryUpdateLeadersCrestTracker(void)
{
    NATIVE_ARGS();
    TryUpdateEvolutionTracker(EVO_DEFEAT_THREE_WITH_ITEM, 1, MOVE_NONE);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryTidyUp(void)
{
    NATIVE_ARGS(u8 clear, const u8 *jumpInstr);

    if (cmd->clear)
    {
        if (TryTidyUpClear(gEffectBattler, TRUE))
            return;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        if (TryTidyUpClear(gBattlerAttacker, FALSE))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_TryGulpMissile(void)
{
    NATIVE_ARGS();

    if ((gBattleMons[gBattlerAttacker].species == SPECIES_CRAMORANT)
     && (gCurrentMove == MOVE_DIVE)
     && (GetBattlerAbility(gBattlerAttacker) == ABILITY_GULP_MISSILE)
     && TryBattleFormChange(gBattlerAttacker, FORM_CHANGE_BATTLE_HP_PERCENT))
        gBattlescriptCurrInstr = BattleScript_GulpMissileFormChange;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryActivateGulpMissile(void)
{
    NATIVE_ARGS();

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
        && TARGET_TURN_DAMAGED
        && gBattleMons[gBattlerTarget].species != SPECIES_CRAMORANT
        && GetBattlerAbility(gBattlerTarget) == ABILITY_GULP_MISSILE)
    {
        if (GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
        {
            gBattleMoveDamage = GetNonDynamaxMaxHP(gBattlerAttacker) / 4;
            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
        }

        switch(gBattleMons[gBattlerTarget].species)
        {
            case SPECIES_CRAMORANT_GORGING:
                BattleScriptPushCursor();
                TryBattleFormChange(gBattlerTarget, FORM_CHANGE_HIT_BY_MOVE);
                gBattlescriptCurrInstr = BattleScript_GulpMissileGorging;
                return;
            case SPECIES_CRAMORANT_GULPING:
                BattleScriptPushCursor();
                TryBattleFormChange(gBattlerTarget, FORM_CHANGE_HIT_BY_MOVE);
                gBattlescriptCurrInstr = BattleScript_GulpMissileGulping;
                return;
        }
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_TryQuash(void)
{
    NATIVE_ARGS(const u8 *failInstr);
    u32 i, j;

    // It's true if foe is faster, has a bigger priority, or switches
    if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
        return;
    }

    // If the above condition is not true, it means we are faster than the foe, so we can set the quash bit
    gProtectStructs[gBattlerTarget].quash = TRUE;

    // this implementation assumes turn order is correct when using Quash
    i = GetBattlerTurnOrderNum(gBattlerTarget);
    for (j = i + 1; j < gBattlersCount; j++)
    {
        // Gen 7- config makes target go last so that the order of quash targets is kept for the correct turn order
        // Gen 8+ config alters Turn Order of the target according to speed, dynamic speed should handle the rest
        if (B_QUASH_TURN_ORDER < GEN_8 || GetWhichBattlerFaster(gBattlerByTurnOrder[i], gBattlerByTurnOrder[j], FALSE) == -1)
            SwapTurnOrder(i, j);
        else
            break;
        i++;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_CopyFoesStatIncrease(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);
    u32 stat = 0;
    u32 battler = GetBattlerForBattleScript(cmd->battler);

    if (gQueuedStatBoosts[battler].stats == 0)
    {
        for (stat = 0; stat < (NUM_BATTLE_STATS - 1); stat++)
        {
            if (gQueuedStatBoosts[battler].statChanges[stat] != 0)
                gQueuedStatBoosts[battler].stats |= (1 << stat);
        }
        gBattlescriptCurrInstr = cmd->jumpInstr;
        return;
    }

    for (stat = 0; stat < (NUM_BATTLE_STATS - 1); stat++)
    {
        if (gQueuedStatBoosts[battler].stats & (1 << stat))
        {
            if (gQueuedStatBoosts[battler].statChanges[stat] <= -1)
                SET_STATCHANGER(stat + 1, abs(gQueuedStatBoosts[battler].statChanges[stat]), TRUE);
            else
                SET_STATCHANGER(stat + 1, gQueuedStatBoosts[battler].statChanges[stat], FALSE);

            gQueuedStatBoosts[battler].stats &= ~(1 << stat);
            gBattlerTarget = battler;
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }
    }
    gBattlescriptCurrInstr = cmd->jumpInstr;
}

void BS_RemoveWeather(void)
{
    NATIVE_ARGS();
    RemoveAllWeather();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_ApplyTerastallization(void)
{
    NATIVE_ARGS();
    ApplyBattlerVisualsForTeraAnim(gBattlerAttacker);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_DamageToQuarterTargetHP(void)
{
    NATIVE_ARGS();
    gBattleMoveDamage = (3 * GetNonDynamaxHP(gBattlerTarget)) / 4;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_FickleBeamDamageCalculation(void)
{
    NATIVE_ARGS();
    gBattleStruct->fickleBeamBoosted = FALSE;

    if (RandomPercentage(RNG_FICKLE_BEAM, 30))
    {
        gBattleStruct->fickleBeamBoosted = TRUE;
        gBattlescriptCurrInstr = BattleScript_FickleBeamDoubled;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_TryTarShot(void)
{
    NATIVE_ARGS(const u8 *failInstr);
    if (gDisableStructs[gBattlerTarget].tarShot || GetActiveGimmick(gBattlerTarget) == GIMMICK_TERA)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gDisableStructs[gBattlerTarget].tarShot = TRUE;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

void BS_JumpIfBlockedBySoundproof(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);
    u32 battler = GetBattlerForBattleScript(cmd->battler);
    if (gMovesInfo[gCurrentMove].soundMove && GetBattlerAbility(battler) == ABILITY_SOUNDPROOF)
    {
        gLastUsedAbility = ABILITY_SOUNDPROOF;
        gBattlescriptCurrInstr = cmd->jumpInstr;
        RecordAbilityBattle(battler, gLastUsedAbility);
        gBattlerAbility = battler;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}
