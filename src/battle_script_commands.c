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

// Helper for accessing command arguments and advancing gBattlescriptCurrInstr.
//
// For example accuracycheck is defined as:
//
//     .macro accuracycheck failInstr:req, move:req
//     .byte 0x1
//     .4byte \failInstr
//     .2byte \move
//     .endm
//
// Which corresponds to:
//
//     CMD_ARGS(const u8 *failInstr, u16 move);
//
// The arguments can be accessed as cmd->failInstr and cmd->move.
// gBattlescriptCurrInstr = cmd->nextInstr; advances to the next instruction.
#define CMD_ARGS(...) const struct __attribute__((packed)) { u8 opcode; MEMBERS(__VA_ARGS__) const u8 nextInstr[0]; } *const cmd  = (const void *)gBattlescriptCurrInstr
#define VARIOUS_ARGS(...) CMD_ARGS(u8 battler, u8 id, ##__VA_ARGS__)
#define NATIVE_ARGS(...) CMD_ARGS(void (*func)(void), ##__VA_ARGS__)

#define MEMBERS(...) VARARG_8(MEMBERS_, __VA_ARGS__)
#define MEMBERS_0()
#define MEMBERS_1(a) a;
#define MEMBERS_2(a, b) a; b;
#define MEMBERS_3(a, b, c) a; b; c;
#define MEMBERS_4(a, b, c, d) a; b; c; d;
#define MEMBERS_5(a, b, c, d, e) a; b; c; d; e;
#define MEMBERS_6(a, b, c, d, e, f) a; b; c; d; e; f;
#define MEMBERS_7(a, b, c, d, e, f, g) a; b; c; d; e; f; g;
#define MEMBERS_8(a, b, c, d, e, f, g, h) a; b; c; d; e; f; g; h;

extern struct Evolution gEvolutionTable[][EVOS_PER_MON];

extern const u8 *const gBattleScriptsForMoveEffects[];

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
    MOVE_BIND, MOVE_WRAP, MOVE_FIRE_SPIN, MOVE_CLAMP, MOVE_WHIRLPOOL, MOVE_SAND_TOMB, MOVE_MAGMA_STORM, MOVE_INFESTATION, MOVE_SNAP_TRAP,
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

static bool8 IsTwoTurnsMove(u16 move);
static void TrySetDestinyBondToHappen(void);
static u8 AttacksThisTurn(u8 battlerId, u16 move); // Note: returns 1 if it's a charging turn, otherwise 2.
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
static bool8 IsFinalStrikeEffect(u16 move);
static void TryUpdateRoundTurnOrder(void);
static bool32 ChangeOrderTargetAfterAttacker(void);

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
static void Cmd_seteffectwithchance(void);
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
static void Cmd_jumpifaffectedbyprotect(void);
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
static void Cmd_setrain(void);
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
static void Cmd_confuseifrepeatingattackends(void);
static void Cmd_setmultihitcounter(void);
static void Cmd_initmultihitstring(void);
static void Cmd_forcerandomswitch(void);
static void Cmd_tryconversiontypechange(void);
static void Cmd_givepaydaymoney(void);
static void Cmd_setlightscreen(void);
static void Cmd_tryKO(void);
static void Cmd_damagetohalftargethp(void);
static void Cmd_setsandstorm(void);
static void Cmd_weatherdamage(void);
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
static void Cmd_setsunny(void);
static void Cmd_maxattackhalvehp(void);
static void Cmd_copyfoestats(void);
static void Cmd_rapidspinfree(void);
static void Cmd_setdefensecurlbit(void);
static void Cmd_recoverbasedonsunlight(void);
static void Cmd_setstickyweb(void);
static void Cmd_selectfirstvalidtarget(void);
static void Cmd_trysetfutureattack(void);
static void Cmd_trydobeatup(void);
static void Cmd_setsemiinvulnerablebit(void);
static void Cmd_clearsemiinvulnerablebit(void);
static void Cmd_setminimize(void);
static void Cmd_sethail(void);
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
static void Cmd_getsecretpowereffect(void);
static void Cmd_pickup(void);
static void Cmd_doweatherformchangeanimation(void);
static void Cmd_tryweatherformdatachange(void);
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
    Cmd_seteffectwithchance,                     //0x15
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
    Cmd_jumpifaffectedbyprotect,                 //0x40
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
    Cmd_setrain,                                 //0x7D
    Cmd_setreflect,                              //0x7E
    Cmd_setseeded,                               //0x7F
    Cmd_manipulatedamage,                        //0x80
    Cmd_trysetrest,                              //0x81
    Cmd_jumpifnotfirstturn,                      //0x82
    Cmd_setmiracleeye,                           //0x83
    Cmd_jumpifuproarwakes,                    //0x84
    Cmd_stockpile,                               //0x85
    Cmd_stockpiletobasedamage,                   //0x86
    Cmd_stockpiletohpheal,                       //0x87
    Cmd_setdrainedhp,                            //0x88
    Cmd_statbuffchange,                          //0x89
    Cmd_normalisebuffs,                          //0x8A
    Cmd_setbide,                                 //0x8B
    Cmd_confuseifrepeatingattackends,            //0x8C
    Cmd_setmultihitcounter,                      //0x8D
    Cmd_initmultihitstring,                      //0x8E
    Cmd_forcerandomswitch,                       //0x8F
    Cmd_tryconversiontypechange,                 //0x90
    Cmd_givepaydaymoney,                         //0x91
    Cmd_setlightscreen,                          //0x92
    Cmd_tryKO,                                   //0x93
    Cmd_damagetohalftargethp,                    //0x94
    Cmd_setsandstorm,                            //0x95
    Cmd_weatherdamage,                           //0x96
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
    Cmd_setsunny,                                //0xBB
    Cmd_maxattackhalvehp,                        //0xBC
    Cmd_copyfoestats,                            //0xBD
    Cmd_rapidspinfree,                           //0xBE
    Cmd_setdefensecurlbit,                       //0xBF
    Cmd_recoverbasedonsunlight,                  //0xC0
    Cmd_setstickyweb,                            //0xC1
    Cmd_selectfirstvalidtarget,                  //0xC2
    Cmd_trysetfutureattack,                      //0xC3
    Cmd_trydobeatup,                             //0xC4
    Cmd_setsemiinvulnerablebit,                  //0xC5
    Cmd_clearsemiinvulnerablebit,                //0xC6
    Cmd_setminimize,                             //0xC7
    Cmd_sethail,                                 //0xC8
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
    Cmd_getsecretpowereffect,                    //0xE4
    Cmd_pickup,                                  //0xE5
    Cmd_doweatherformchangeanimation,            //0xE6
    Cmd_tryweatherformdatachange,                //0xE7
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

#define FORBIDDEN_MIMIC         (1 << 0)
#define FORBIDDEN_METRONOME     (1 << 1)
#define FORBIDDEN_ASSIST        (1 << 2)
#define FORBIDDEN_COPYCAT       (1 << 3)
#define FORBIDDEN_SLEEP_TALK    (1 << 4)
#define FORBIDDEN_INSTRUCT      (1 << 5)
#define FORBIDDEN_PARENTAL_BOND (1 << 6)

static const u8 sForbiddenMoves[MOVES_COUNT] =
{
    [MOVE_NONE] = 0xFF, // Can't use a non-move lol
    [MOVE_STRUGGLE] = 0xFF, // Neither Struggle
    [MOVE_AFTER_YOU] = FORBIDDEN_METRONOME,
    [MOVE_APPLE_ACID] = FORBIDDEN_METRONOME,
    [MOVE_ARMOR_CANNON] = FORBIDDEN_METRONOME,
    [MOVE_ARM_THRUST] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_ASSIST] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_ASTRAL_BARRAGE] = FORBIDDEN_METRONOME,
    [MOVE_AURA_WHEEL] = FORBIDDEN_METRONOME,
    [MOVE_BADDY_BAD] = FORBIDDEN_METRONOME,
    [MOVE_BANEFUL_BUNKER] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_BARRAGE] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_BEAK_BLAST] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_BEAT_UP] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_BEHEMOTH_BASH] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_BEHEMOTH_BLADE] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_BELCH] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_BESTOW] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_BIDE] = FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND, // Note: Bide should work with Parental Bond. This will be addressed in future.
    [MOVE_BLAST_BURN] = FORBIDDEN_INSTRUCT,
    [MOVE_BLAZING_TORQUE] = FORBIDDEN_MIMIC | FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_BODY_PRESS] = FORBIDDEN_METRONOME,
    [MOVE_BONE_RUSH] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_BONEMERANG] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_BOUNCE] = FORBIDDEN_ASSIST | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_BOUNCY_BUBBLE] = FORBIDDEN_METRONOME,
    [MOVE_BRANCH_POKE] = FORBIDDEN_METRONOME,
    [MOVE_BREAKING_SWIPE] = FORBIDDEN_METRONOME,
    [MOVE_BULLET_SEED] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_BUZZY_BUZZ] = FORBIDDEN_METRONOME,
    [MOVE_CELEBRATE] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_CHATTER] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_MIMIC | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_CHILLING_WATER] = FORBIDDEN_METRONOME,
    [MOVE_CHILLY_RECEPTION] = FORBIDDEN_METRONOME,
    [MOVE_CIRCLE_THROW] = FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_CLANGOROUS_SOUL] = FORBIDDEN_METRONOME,
    [MOVE_COLLISION_COURSE] = FORBIDDEN_METRONOME,
    [MOVE_COMBAT_TORQUE] = FORBIDDEN_MIMIC | FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_COMET_PUNCH] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_COMEUPPANCE] = FORBIDDEN_METRONOME,
    [MOVE_COPYCAT] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_COUNTER] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_COVET] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_CRAFTY_SHIELD] = FORBIDDEN_METRONOME,
    [MOVE_DECORATE] = FORBIDDEN_METRONOME,
    [MOVE_DESTINY_BOND] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_DETECT] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_DIAMOND_STORM] = FORBIDDEN_METRONOME,
    [MOVE_DIG] = FORBIDDEN_ASSIST | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_DIVE] = FORBIDDEN_ASSIST | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_DOODLE] = FORBIDDEN_METRONOME,
    [MOVE_DOUBLE_IRON_BASH] = FORBIDDEN_METRONOME | FORBIDDEN_PARENTAL_BOND,
    [MOVE_DOUBLE_HIT] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_DOUBLE_KICK] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_DOUBLE_SHOCK] = FORBIDDEN_METRONOME,
    [MOVE_DOUBLE_SLAP] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_DRAGON_ASCENT] = FORBIDDEN_METRONOME,
    [MOVE_DRAGON_ENERGY] = FORBIDDEN_METRONOME,
    [MOVE_DRAGON_DARTS] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_DRAGON_TAIL] = FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_DRUM_BEATING] = FORBIDDEN_METRONOME,
    [MOVE_DUAL_CHOP] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_DUAL_WINGBEAT] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_DYNAMAX_CANNON] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_ELECTRO_DRIFT] = FORBIDDEN_METRONOME,
    [MOVE_ENDEAVOR] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_ENDURE] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_ETERNABEAM] = FORBIDDEN_METRONOME | FORBIDDEN_INSTRUCT,
    [MOVE_EXPLOSION] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_FALSE_SURRENDER] = FORBIDDEN_METRONOME,
    [MOVE_FEINT] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_FIERY_WRATH] = FORBIDDEN_METRONOME,
    [MOVE_FILLET_AWAY] = FORBIDDEN_METRONOME,
    [MOVE_FINAL_GAMBIT] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_FISSURE] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_FLEUR_CANNON] = FORBIDDEN_METRONOME,
    [MOVE_FLING] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_FLOATY_FALL] = FORBIDDEN_METRONOME,
    [MOVE_FLY] = FORBIDDEN_ASSIST | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_FOCUS_PUNCH] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_FOLLOW_ME] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_FREEZE_SHOCK] = FORBIDDEN_METRONOME | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT| FORBIDDEN_PARENTAL_BOND,
    [MOVE_FREEZING_GLARE] = FORBIDDEN_METRONOME,
    [MOVE_FREEZY_FROST] = FORBIDDEN_METRONOME,
    [MOVE_FURY_ATTACK] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_FURY_SWIPES] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_GEAR_GRIND] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_GEOMANCY] = FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_GIGA_IMPACT] = FORBIDDEN_INSTRUCT,
    [MOVE_GLACIAL_LANCE] = FORBIDDEN_METRONOME,
    [MOVE_GLITZY_GLOW] = FORBIDDEN_METRONOME,
    [MOVE_GRAV_APPLE] = FORBIDDEN_METRONOME,
    [MOVE_GUILLOTINE] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_HELPING_HAND] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_HOLD_HANDS] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_HORN_DRILL] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_HYDRO_CANNON] = FORBIDDEN_INSTRUCT,
    [MOVE_HYPER_BEAM] = FORBIDDEN_INSTRUCT,
    [MOVE_HYPER_DRILL] = FORBIDDEN_METRONOME,
    [MOVE_HYPERSPACE_FURY] = FORBIDDEN_METRONOME,
    [MOVE_HYPERSPACE_HOLE] = FORBIDDEN_METRONOME,
    [MOVE_ICE_BALL] = FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_ICE_BURN] = FORBIDDEN_METRONOME | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_ICICLE_SPEAR] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_INSTRUCT] = FORBIDDEN_METRONOME | FORBIDDEN_INSTRUCT,
    [MOVE_JET_PUNCH] = FORBIDDEN_METRONOME,
    [MOVE_JUNGLE_HEALING] = FORBIDDEN_METRONOME,
    [MOVE_KINGS_SHIELD] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_INSTRUCT,
    [MOVE_LIFE_DEW] = FORBIDDEN_METRONOME,
    [MOVE_LIGHT_OF_RUIN] = FORBIDDEN_METRONOME,
    [MOVE_MAKE_IT_RAIN] = FORBIDDEN_METRONOME,
    [MOVE_MAGICAL_TORQUE] = FORBIDDEN_MIMIC | FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_MAT_BLOCK] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_ME_FIRST] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_METEOR_ASSAULT] = FORBIDDEN_METRONOME | FORBIDDEN_INSTRUCT,
    [MOVE_METEOR_BEAM] = FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_METRONOME] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_MIMIC] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_MIMIC | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_MIND_BLOWN] = FORBIDDEN_METRONOME,
    [MOVE_MIRROR_COAT] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_MIRROR_MOVE] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_MISTY_EXPLOSION] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_MOONGEIST_BEAM] = FORBIDDEN_METRONOME,
    [MOVE_NATURE_POWER] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_NATURES_MADNESS] = FORBIDDEN_METRONOME,
    [MOVE_NOXIOUS_TORQUE] = FORBIDDEN_MIMIC | FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_OBSTRUCT] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_INSTRUCT,
    [MOVE_ORDER_UP] = FORBIDDEN_METRONOME,
    [MOVE_ORIGIN_PULSE] = FORBIDDEN_METRONOME,
    [MOVE_OUTRAGE] = FORBIDDEN_INSTRUCT,
    [MOVE_OVERDRIVE] = FORBIDDEN_METRONOME,
    [MOVE_PHANTOM_FORCE] = FORBIDDEN_ASSIST | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_PHOTON_GEYSER] = FORBIDDEN_METRONOME,
    [MOVE_PLASMA_FISTS] = FORBIDDEN_METRONOME,
    [MOVE_POPULATION_BOMB] = FORBIDDEN_METRONOME,
    [MOVE_POUNCE] = FORBIDDEN_METRONOME,
    [MOVE_POWER_SHIFT] = FORBIDDEN_METRONOME,
    [MOVE_PRECIPICE_BLADES] = FORBIDDEN_METRONOME,
    [MOVE_PRISMATIC_LASER] = FORBIDDEN_INSTRUCT,
    [MOVE_PROTECT] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_PYRO_BALL] = FORBIDDEN_METRONOME,
    [MOVE_QUASH] = FORBIDDEN_METRONOME,
    [MOVE_QUICK_GUARD] = FORBIDDEN_METRONOME,
    [MOVE_RAGE_FIST] = FORBIDDEN_METRONOME,
    [MOVE_RAGE_POWDER] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_RAGING_BULL] = FORBIDDEN_METRONOME,
    [MOVE_RAGING_FURY] = FORBIDDEN_METRONOME,
    [MOVE_RAZOR_WIND] = FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_RELIC_SONG] = FORBIDDEN_METRONOME,
    [MOVE_REVIVAL_BLESSING] = FORBIDDEN_METRONOME,
    [MOVE_ROAR] = FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_ROAR_OF_TIME] = FORBIDDEN_INSTRUCT,
    [MOVE_ROCK_BLAST] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_ROCK_WRECKER] = FORBIDDEN_INSTRUCT,
    [MOVE_ROLLOUT] = FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_RUINATION] = FORBIDDEN_METRONOME,
    [MOVE_SAPPY_SEED] = FORBIDDEN_METRONOME,
    [MOVE_SALT_CURE] = FORBIDDEN_METRONOME,
    [MOVE_SCALE_SHOT] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_SECRET_SWORD] = FORBIDDEN_METRONOME,
    [MOVE_SELF_DESTRUCT] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_SHADOW_FORCE] = FORBIDDEN_ASSIST | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_SHED_TAIL] = FORBIDDEN_METRONOME,
    [MOVE_SHEER_COLD] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_SHELL_TRAP] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_SILK_TRAP] = FORBIDDEN_METRONOME,
    [MOVE_SIZZLY_SLIDE] = FORBIDDEN_METRONOME,
    [MOVE_SKETCH] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_MIMIC | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_SKULL_BASH] = FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_SKY_ATTACK] = FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_SKY_DROP] = FORBIDDEN_ASSIST | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_SLEEP_TALK] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_SNAP_TRAP] = FORBIDDEN_METRONOME,
    [MOVE_SNARL] = FORBIDDEN_METRONOME,
    [MOVE_SNATCH] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_INSTRUCT,
    [MOVE_SNORE] = FORBIDDEN_METRONOME,
    [MOVE_SNOWSCAPE] = FORBIDDEN_METRONOME,
    [MOVE_SOLAR_BEAM] = FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_SOLAR_BLADE] = FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_SPARKLY_SWIRL] = FORBIDDEN_METRONOME,
    [MOVE_SPECTRAL_THIEF] = FORBIDDEN_METRONOME,
    [MOVE_SPICY_EXTRACT] = FORBIDDEN_METRONOME,
    [MOVE_SPIKE_CANNON] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_SPIKY_SHIELD] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_SPIRIT_BREAK] = FORBIDDEN_METRONOME,
    [MOVE_SPLISHY_SPLASH] = FORBIDDEN_METRONOME,
    [MOVE_SPOTLIGHT] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_STEAM_ERUPTION] = FORBIDDEN_METRONOME,
    [MOVE_STEEL_BEAM] = FORBIDDEN_METRONOME,
    [MOVE_STRANGE_STEAM] = FORBIDDEN_METRONOME,
    [MOVE_SUNSTEEL_STRIKE] = FORBIDDEN_METRONOME,
    [MOVE_SURGING_STRIKES] = FORBIDDEN_METRONOME | FORBIDDEN_PARENTAL_BOND,
    [MOVE_SWITCHEROO] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_TAIL_SLAP] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_TECHNO_BLAST] = FORBIDDEN_METRONOME,
    [MOVE_THIEF] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_THOUSAND_ARROWS] = FORBIDDEN_METRONOME,
    [MOVE_THOUSAND_WAVES] = FORBIDDEN_METRONOME,
    [MOVE_THRASH] = FORBIDDEN_INSTRUCT,
    [MOVE_THUNDER_CAGE] = FORBIDDEN_METRONOME,
    [MOVE_THUNDEROUS_KICK] = FORBIDDEN_METRONOME,
    [MOVE_TIDY_UP] = FORBIDDEN_METRONOME,
    [MOVE_TRAILBLAZE] = FORBIDDEN_METRONOME,
    [MOVE_TRANSFORM] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_MIMIC | FORBIDDEN_INSTRUCT,
    [MOVE_TRICK] = FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_TRIPLE_AXEL] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_TRIPLE_KICK] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_TWINEEDLE] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_TWIN_BEAM] = FORBIDDEN_METRONOME,
    [MOVE_UPROAR] = FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT | FORBIDDEN_PARENTAL_BOND,
    [MOVE_V_CREATE] = FORBIDDEN_METRONOME,
    [MOVE_VEEVEE_VOLLEY] = FORBIDDEN_METRONOME,
    [MOVE_WATER_SHURIKEN] = FORBIDDEN_PARENTAL_BOND,
    [MOVE_WHIRLWIND] = FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT,
    [MOVE_WICKED_BLOW] = FORBIDDEN_METRONOME,
    [MOVE_WICKED_TORQUE] = FORBIDDEN_MIMIC | FORBIDDEN_METRONOME | FORBIDDEN_ASSIST | FORBIDDEN_COPYCAT | FORBIDDEN_SLEEP_TALK | FORBIDDEN_INSTRUCT,
    [MOVE_WIDE_GUARD] = FORBIDDEN_METRONOME,
    [MOVE_ZIPPY_ZAP] = FORBIDDEN_METRONOME,
};

static const u16 sFinalStrikeOnlyEffects[] =
{
    EFFECT_RELIC_SONG,
    EFFECT_BUG_BITE,
    EFFECT_THIEF,
    EFFECT_BURN_UP,
    EFFECT_DOUBLE_SHOCK,
    EFFECT_SECRET_POWER,
    EFFECT_SMACK_DOWN,
    EFFECT_SPARKLING_ARIA,
    EFFECT_SMELLINGSALT,
    EFFECT_WAKE_UP_SLAP,
    EFFECT_HIT_ESCAPE,
    EFFECT_RECOIL_HP_25,
    EFFECT_HIT_PREVENT_ESCAPE,
    EFFECT_HIT_SWITCH_TARGET,
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

static const u16 sPickupItems[] =
{
    ITEM_POTION,
    ITEM_ANTIDOTE,
    ITEM_SUPER_POTION,
    ITEM_GREAT_BALL,
    ITEM_REPEL,
    ITEM_ESCAPE_ROPE,
    ITEM_X_ATTACK,
    ITEM_FULL_HEAL,
    ITEM_ULTRA_BALL,
    ITEM_HYPER_POTION,
    ITEM_RARE_CANDY,
    ITEM_PROTEIN,
    ITEM_REVIVE,
    ITEM_HP_UP,
    ITEM_FULL_RESTORE,
    ITEM_MAX_REVIVE,
    ITEM_PP_UP,
    ITEM_MAX_ELIXIR,
};

static const u16 sRarePickupItems[] =
{
    ITEM_HYPER_POTION,
    ITEM_NUGGET,
    ITEM_KINGS_ROCK,
    ITEM_FULL_RESTORE,
    ITEM_ETHER,
    ITEM_WHITE_HERB,
    ITEM_TM44_REST,
    ITEM_ELIXIR,
    ITEM_TM01_FOCUS_PUNCH,
    ITEM_LEFTOVERS,
    ITEM_TM26_EARTHQUAKE,
};

static const u8 sPickupProbabilities[] =
{
    30, 40, 50, 60, 70, 80, 90, 94, 98
};

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
#if B_CAMOUFLAGE_TYPES >= GEN_5
    [BATTLE_TERRAIN_MOUNTAIN]         = TYPE_GROUND,
    [BATTLE_TERRAIN_PLAIN]            = TYPE_GROUND,
#elif B_CAMOUFLAGE_TYPES == GEN_4
    [BATTLE_TERRAIN_MOUNTAIN]         = TYPE_ROCK,
    [BATTLE_TERRAIN_PLAIN]            = TYPE_GROUND,
#else
    [BATTLE_TERRAIN_MOUNTAIN]         = TYPE_ROCK,
    [BATTLE_TERRAIN_PLAIN]            = TYPE_NORMAL,
#endif
};

// In Battle Palace, moves are chosen based on the pokemons nature rather than by the player
// Moves are grouped into "Attack", "Defense", or "Support" (see PALACE_MOVE_GROUP_*)
// Each nature has a certain percent chance of selecting a move from a particular group
// and a separate percent chance for each group when below 50% HP
// The table below doesn't list percentages for Support because you can subtract the other two
// Support percentages are listed in comments off to the side instead
#define PALACE_STYLE(atk, def, atkLow, defLow) {atk, atk + def, atkLow, atkLow + defLow}

const ALIGNED(4) u8 gBattlePalaceNatureToMoveGroupLikelihood[NUM_NATURES][4] =
{
    [NATURE_HARDY]   = PALACE_STYLE(61,  7, 61,  7), // 32% support >= 50% HP, 32% support < 50% HP
    [NATURE_LONELY]  = PALACE_STYLE(20, 25, 84,  8), // 55%,  8%
    [NATURE_BRAVE]   = PALACE_STYLE(70, 15, 32, 60), // 15%,  8%
    [NATURE_ADAMANT] = PALACE_STYLE(38, 31, 70, 15), // 31%, 15%
    [NATURE_NAUGHTY] = PALACE_STYLE(20, 70, 70, 22), // 10%,  8%
    [NATURE_BOLD]    = PALACE_STYLE(30, 20, 32, 58), // 50%, 10%
    [NATURE_DOCILE]  = PALACE_STYLE(56, 22, 56, 22), // 22%, 22%
    [NATURE_RELAXED] = PALACE_STYLE(25, 15, 75, 15), // 60%, 10%
    [NATURE_IMPISH]  = PALACE_STYLE(69,  6, 28, 55), // 25%, 17%
    [NATURE_LAX]     = PALACE_STYLE(35, 10, 29,  6), // 55%, 65%
    [NATURE_TIMID]   = PALACE_STYLE(62, 10, 30, 20), // 28%, 50%
    [NATURE_HASTY]   = PALACE_STYLE(58, 37, 88,  6), //  5%,  6%
    [NATURE_SERIOUS] = PALACE_STYLE(34, 11, 29, 11), // 55%, 60%
    [NATURE_JOLLY]   = PALACE_STYLE(35,  5, 35, 60), // 60%,  5%
    [NATURE_NAIVE]   = PALACE_STYLE(56, 22, 56, 22), // 22%, 22%
    [NATURE_MODEST]  = PALACE_STYLE(35, 45, 34, 60), // 20%,  6%
    [NATURE_MILD]    = PALACE_STYLE(44, 50, 34,  6), //  6%, 60%
    [NATURE_QUIET]   = PALACE_STYLE(56, 22, 56, 22), // 22%, 22%
    [NATURE_BASHFUL] = PALACE_STYLE(30, 58, 30, 58), // 12%, 12%
    [NATURE_RASH]    = PALACE_STYLE(30, 13, 27,  6), // 57%, 67%
    [NATURE_CALM]    = PALACE_STYLE(40, 50, 25, 62), // 10%, 13%
    [NATURE_GENTLE]  = PALACE_STYLE(18, 70, 90,  5), // 12%,  5%
    [NATURE_SASSY]   = PALACE_STYLE(88,  6, 22, 20), //  6%, 58%
    [NATURE_CAREFUL] = PALACE_STYLE(42, 50, 42,  5), //  8%, 53%
    [NATURE_QUIRKY]  = PALACE_STYLE(56, 22, 56, 22)  // 22%, 22%
};

static const u8 sBattlePalaceNatureToFlavorTextId[NUM_NATURES] =
{
    [NATURE_HARDY]   = B_MSG_EAGER_FOR_MORE,
    [NATURE_LONELY]  = B_MSG_GLINT_IN_EYE,
    [NATURE_BRAVE]   = B_MSG_GETTING_IN_POS,
    [NATURE_ADAMANT] = B_MSG_GLINT_IN_EYE,
    [NATURE_NAUGHTY] = B_MSG_GLINT_IN_EYE,
    [NATURE_BOLD]    = B_MSG_GETTING_IN_POS,
    [NATURE_DOCILE]  = B_MSG_EAGER_FOR_MORE,
    [NATURE_RELAXED] = B_MSG_GLINT_IN_EYE,
    [NATURE_IMPISH]  = B_MSG_GETTING_IN_POS,
    [NATURE_LAX]     = B_MSG_GROWL_DEEPLY,
    [NATURE_TIMID]   = B_MSG_GROWL_DEEPLY,
    [NATURE_HASTY]   = B_MSG_GLINT_IN_EYE,
    [NATURE_SERIOUS] = B_MSG_EAGER_FOR_MORE,
    [NATURE_JOLLY]   = B_MSG_GETTING_IN_POS,
    [NATURE_NAIVE]   = B_MSG_EAGER_FOR_MORE,
    [NATURE_MODEST]  = B_MSG_GETTING_IN_POS,
    [NATURE_MILD]    = B_MSG_GROWL_DEEPLY,
    [NATURE_QUIET]   = B_MSG_EAGER_FOR_MORE,
    [NATURE_BASHFUL] = B_MSG_EAGER_FOR_MORE,
    [NATURE_RASH]    = B_MSG_GROWL_DEEPLY,
    [NATURE_CALM]    = B_MSG_GETTING_IN_POS,
    [NATURE_GENTLE]  = B_MSG_GLINT_IN_EYE,
    [NATURE_SASSY]   = B_MSG_GROWL_DEEPLY,
    [NATURE_CAREFUL] = B_MSG_GROWL_DEEPLY,
    [NATURE_QUIRKY]  = B_MSG_EAGER_FOR_MORE,
};

static bool32 NoTargetPresent(u8 battlerId, u32 move)
{
    if (!IsBattlerAlive(gBattlerTarget))
        gBattlerTarget = GetMoveTarget(move, NO_TARGET_OVERRIDE);

    switch (GetBattlerMoveTargetType(battlerId, move))
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
    case SPECIES_AEGISLASH: // Shield -> Blade
        if (IS_MOVE_STATUS(gCurrentMove))
            return FALSE;
        gBattleMons[gBattlerAttacker].species = SPECIES_AEGISLASH_BLADE;
        break;
    case SPECIES_AEGISLASH_BLADE: // Blade -> Shield
        if (gCurrentMove != MOVE_KINGS_SHIELD)
            return FALSE;
        gBattleMons[gBattlerAttacker].species = SPECIES_AEGISLASH;
        break;
    }

    BattleScriptPushCursor();
    gBattlescriptCurrInstr = BattleScript_AttackerFormChange;
    return TRUE;
}

bool32 ProteanTryChangeType(u32 battler, u32 ability, u32 move, u32 moveType)
{
      if ((ability == ABILITY_PROTEAN || ability == ABILITY_LIBERO)
         && (gBattleMons[battler].type1 != moveType || gBattleMons[battler].type2 != moveType
             || (gBattleMons[battler].type3 != moveType && gBattleMons[battler].type3 != TYPE_MYSTERY))
         && move != MOVE_STRUGGLE)
    {
        SET_BATTLER_TYPE(gBattlerAttacker, moveType);
        return TRUE;
    }
    return FALSE;
}

static void Cmd_attackcanceler(void)
{
    CMD_ARGS();

    s32 i, moveType;
    u16 attackerAbility = GetBattlerAbility(gBattlerAttacker);

    GET_MOVE_TYPE(gCurrentMove, moveType);

    if (WEATHER_HAS_EFFECT && gBattleMoves[gCurrentMove].power)
    {
        if (moveType == TYPE_FIRE && (gBattleWeather & B_WEATHER_RAIN_PRIMAL))
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_PrimordialSeaFizzlesOutFireTypeMoves;
            return;
        }
        else if (moveType == TYPE_WATER && (gBattleWeather & B_WEATHER_SUN_PRIMAL))
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_DesolateLandEvaporatesWaterTypeMoves;
            return;
        }
    }

    if (gBattleOutcome != 0)
    {
        gCurrentActionFuncId = B_ACTION_FINISHED;
        return;
    }
    if (gBattleMons[gBattlerAttacker].hp == 0 && !(gHitMarker & HITMARKER_NO_ATTACKSTRING))
    {
        gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
        return;
    }
#if B_STANCE_CHANGE_FAIL <= GEN_6
    if (TryAegiFormChange())
        return;
#endif
    if (AtkCanceller_UnableToUseMove())
        return;

    if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_OFF
    && GetBattlerAbility(gBattlerAttacker) == ABILITY_PARENTAL_BOND
    && IsMoveAffectedByParentalBond(gCurrentMove, gBattlerAttacker)
    && !(gAbsentBattlerFlags & gBitTable[gBattlerTarget])
    && gBattleStruct->zmove.toBeUsed[gBattlerAttacker] == MOVE_NONE)
    {
        gSpecialStatuses[gBattlerAttacker].parentalBondState = PARENTAL_BOND_1ST_HIT;
        gMultiHitCounter = 2;
        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
        return;
    }

    // Check Protean activation.
    if (ProteanTryChangeType(gBattlerAttacker, attackerAbility, gCurrentMove, moveType))
    {
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
#if B_STANCE_CHANGE_FAIL >= GEN_7
    if (TryAegiFormChange())
        return;
#endif

    gHitMarker &= ~HITMARKER_ALLOW_NO_PP;

    if (!(gHitMarker & HITMARKER_OBEYS) && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))
    {
        switch (IsMonDisobedient())
        {
        case 0:
            break;
        case 2:
            gHitMarker |= HITMARKER_OBEYS;
            return;
        default:
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            return;
        }
    }

    gHitMarker |= HITMARKER_OBEYS;
    if (NoTargetPresent(gBattlerAttacker, gCurrentMove) && (!IsTwoTurnsMove(gCurrentMove) || (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailedAtkStringPpReduce;
        if (!IsTwoTurnsMove(gCurrentMove) || (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))
            CancelMultiTurnMoves(gBattlerAttacker);
        return;
    }

    if (gProtectStructs[gBattlerTarget].bounceMove
        && gBattleMoves[gCurrentMove].flags & FLAG_MAGIC_COAT_AFFECTED
        && !gProtectStructs[gBattlerAttacker].usesBouncedMove)
    {
        PressurePPLose(gBattlerAttacker, gBattlerTarget, MOVE_MAGIC_COAT);
        gProtectStructs[gBattlerTarget].usesBouncedMove = TRUE;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        gBattleStruct->atkCancellerTracker = CANCELLER_POWDER_MOVE; // Edge case for bouncing a powder move against a grass type pokemon.
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
    else if (GetBattlerAbility(gBattlerTarget) == ABILITY_MAGIC_BOUNCE
             && gBattleMoves[gCurrentMove].flags & FLAG_MAGIC_COAT_AFFECTED
             && !gProtectStructs[gBattlerAttacker].usesBouncedMove)
    {
        gProtectStructs[gBattlerTarget].usesBouncedMove = TRUE;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        gBattleStruct->atkCancellerTracker = CANCELLER_POWDER_MOVE; // Edge case for bouncing a powder move against a grass type pokemon.
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_MagicCoatBounce;
        gBattlerAbility = gBattlerTarget;
        return;
    }

    // Z-moves and Max Moves bypass protection, but deal reduced damage (factored in CalcFinalDmg)
    if (gBattleStruct->zmove.active && IS_BATTLER_PROTECTED(gBattlerTarget))
    {
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_CouldntFullyProtect;
        return;
    }

    for (i = 0; i < gBattlersCount; i++)
    {
        if ((gProtectStructs[gBattlerByTurnOrder[i]].stealMove) && gBattleMoves[gCurrentMove].flags & FLAG_SNATCH_AFFECTED)
        {
            PressurePPLose(gBattlerAttacker, gBattlerByTurnOrder[i], MOVE_SNATCH);
            gProtectStructs[gBattlerByTurnOrder[i]].stealMove = FALSE;
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
    else if (IsBattlerProtected(gBattlerTarget, gCurrentMove)
     && (gCurrentMove != MOVE_CURSE || IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
     && ((!IsTwoTurnsMove(gCurrentMove) || (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)))
     && gBattleMoves[gCurrentMove].effect != EFFECT_SUCKER_PUNCH)
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

static void Cmd_jumpifaffectedbyprotect(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (IsBattlerProtected(gBattlerTarget, gCurrentMove))
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
    if (IsBattlerProtected(gBattlerTarget, move))
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
    if (gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBattlerTarget].battlerWithSureHit == gBattlerAttacker)
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }
#if B_TOXIC_NEVER_MISS >= GEN_6
    else if (gBattleMoves[move].effect == EFFECT_TOXIC && IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_POISON))
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }
#endif
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

    if (gBattleStruct->zmove.active && !(gStatuses3[gBattlerTarget] & STATUS3_SEMI_INVULNERABLE))
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    if ((gStatuses3[gBattlerTarget] & STATUS3_PHANTOM_FORCE)
        || (!(gBattleMoves[move].flags & (FLAG_DMG_IN_AIR | FLAG_DMG_2X_IN_AIR)) && gStatuses3[gBattlerTarget] & STATUS3_ON_AIR)
        || (!(gBattleMoves[move].flags & FLAG_DMG_UNDERGROUND) && gStatuses3[gBattlerTarget] & STATUS3_UNDERGROUND)
        || (!(gBattleMoves[move].flags & FLAG_DMG_UNDERWATER) && gStatuses3[gBattlerTarget] & STATUS3_UNDERWATER))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    if (WEATHER_HAS_EFFECT)
    {
        if ((IsBattlerWeatherAffected(gBattlerTarget, B_WEATHER_RAIN) && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE)))
        {
            // thunder/hurricane ignore acc checks in rain unless target is holding utility umbrella
            JumpIfMoveFailed(7, move);
            return TRUE;
        }
    #if B_BLIZZARD_HAIL >= GEN_4
        else if ((gBattleWeather & (B_WEATHER_HAIL | B_WEATHER_SNOW)) && move == MOVE_BLIZZARD)
        {
            // thunder/hurricane ignore acc checks in rain unless target is holding utility umbrella
            JumpIfMoveFailed(7, move);
            return TRUE;
        }
    #endif
    }

    if (gBattleMoves[move].effect == EFFECT_VITAL_THROW)
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

#if B_MINIMIZE_DMG_ACC >= GEN_6
    if ((gStatuses3[gBattlerTarget] & STATUS3_MINIMIZED) && (gBattleMoves[move].flags & FLAG_DMG_MINIMIZE))
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }
#endif

    if (gBattleMoves[move].accuracy == 0)
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
    u8 atkParam = GetBattlerHoldEffectParam(battlerAtk);
    u8 defParam = GetBattlerHoldEffectParam(battlerDef);

    gPotentialItemEffectBattler = battlerDef;
    accStage = gBattleMons[battlerAtk].statStages[STAT_ACC];
    evasionStage = gBattleMons[battlerDef].statStages[STAT_EVASION];
    if (atkAbility == ABILITY_UNAWARE || atkAbility == ABILITY_KEEN_EYE)
        evasionStage = DEFAULT_STAT_STAGE;
    if (gBattleMoves[move].flags & FLAG_STAT_STAGES_IGNORED)
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

    moveAcc = gBattleMoves[move].accuracy;
    // Check Thunder and Hurricane on sunny weather.
    if (IsBattlerWeatherAffected(battlerDef, B_WEATHER_SUN)
      && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
        moveAcc = 50;
    // Check Wonder Skin.
    if (defAbility == ABILITY_WONDER_SKIN && IS_MOVE_STATUS(move) && moveAcc > 50)
        moveAcc = 50;

    calc = gAccuracyStageRatios[buff].dividend * moveAcc;
    calc /= gAccuracyStageRatios[buff].divisor;

    if (atkAbility == ABILITY_COMPOUND_EYES)
        calc = (calc * 130) / 100; // 1.3 compound eyes boost
    else if (atkAbility == ABILITY_VICTORY_STAR)
        calc = (calc * 110) / 100; // 1.1 victory star boost
    if (IsBattlerAlive(BATTLE_PARTNER(battlerAtk)) && GetBattlerAbility(BATTLE_PARTNER(battlerAtk)) == ABILITY_VICTORY_STAR)
        calc = (calc * 110) / 100; // 1.1 ally's victory star boost

    if (defAbility == ABILITY_SAND_VEIL && WEATHER_HAS_EFFECT && gBattleWeather & B_WEATHER_SANDSTORM)
        calc = (calc * 80) / 100; // 1.2 sand veil loss
    else if (defAbility == ABILITY_SNOW_CLOAK && WEATHER_HAS_EFFECT && (gBattleWeather & (B_WEATHER_HAIL | B_WEATHER_SNOW)))
        calc = (calc * 80) / 100; // 1.2 snow cloak loss
    else if (defAbility == ABILITY_TANGLED_FEET && gBattleMons[battlerDef].status2 & STATUS2_CONFUSION)
        calc = (calc * 50) / 100; // 1.5 tangled feet loss

    if (atkAbility == ABILITY_HUSTLE && IS_MOVE_PHYSICAL(move))
        calc = (calc * 80) / 100; // 1.2 hustle loss

    if (defHoldEffect == HOLD_EFFECT_EVASION_UP)
        calc = (calc * (100 - defParam)) / 100;

    if (atkHoldEffect == HOLD_EFFECT_WIDE_LENS)
        calc = (calc * (100 + atkParam)) / 100;
    else if (atkHoldEffect == HOLD_EFFECT_ZOOM_LENS && GetBattlerTurnOrderNum(battlerAtk) > GetBattlerTurnOrderNum(battlerDef))
        calc = (calc * (100 + atkParam)) / 100;

    if (gProtectStructs[battlerAtk].usedMicleBerry)
    {
        gProtectStructs[battlerAtk].usedMicleBerry = FALSE;
        if (atkAbility == ABILITY_RIPEN)
            calc = (calc * 140) / 100;  // ripen gives 40% acc boost
        else
            calc = (calc * 120) / 100;  // 20% acc boost
    }

    if (gFieldStatuses & STATUS_FIELD_GRAVITY)
        calc = (calc * 5) / 3; // 1.66 Gravity acc boost

#if B_AFFECTION_MECHANICS == TRUE
    // With high affection/friendship there's a chance to evade a move by substracting 10% of its accuracy.
    // I can't find exact information about that chance, so I'm just gonna write it as a 20% chance for now.
    if (GetBattlerFriendshipScore(battlerDef) >= FRIENDSHIP_150_TO_199 && (Random() % 100) <= 20)
        calc = (calc * 90) / 100;
#endif

    return calc;
}

static void Cmd_accuracycheck(void)
{
    CMD_ARGS(const u8 *failInstr, u16 move);

    u16 type, move = cmd->move;
    u16 moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, move);

    if (move == ACC_CURR_MOVE)
        move = gCurrentMove;

    if (move == NO_ACC_CALC_CHECK_LOCK_ON)
    {
        if (gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBattlerTarget].battlerWithSureHit == gBattlerAttacker)
            gBattlescriptCurrInstr = cmd->nextInstr;
        else if (gStatuses3[gBattlerTarget] & (STATUS3_SEMI_INVULNERABLE))
            gBattlescriptCurrInstr = cmd->failInstr;
        else if (!JumpIfMoveAffectedByProtect(0))
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_2ND_HIT
        || (gSpecialStatuses[gBattlerAttacker].multiHitOn && (gBattleMoves[move].effect != EFFECT_TRIPLE_KICK
        || GetBattlerAbility(gBattlerAttacker) == ABILITY_SKILL_LINK)))
    {
        // No acc checks for second hit of Parental Bond or multi hit moves, except Triple Kick/Triple Axel
        gBattlescriptCurrInstr = cmd->nextInstr;
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
            GetBattlerAbility(gBattlerAttacker),
            GetBattlerAbility(gBattlerTarget),
            GetBattlerHoldEffect(gBattlerAttacker, TRUE),
            GetBattlerHoldEffect(gBattlerTarget, TRUE)
        );

        if (!RandomPercentage(RNG_ACCURACY, accuracy))
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_BLUNDER_POLICY)
                gBattleStruct->blunderPolicy = TRUE;    // Only activates from missing through acc/evasion checks

            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE &&
                (moveTarget == MOVE_TARGET_BOTH || moveTarget == MOVE_TARGET_FOES_AND_ALLY))
                gBattleCommunication[MISS_TYPE] = B_MSG_AVOIDED_ATK;
            else
                gBattleCommunication[MISS_TYPE] = B_MSG_MISSED;

            if (gBattleMoves[move].power)
                CalcTypeEffectivenessMultiplier(move, type, gBattlerAttacker, gBattlerTarget, TRUE);
        }
        JumpIfMoveFailed(7, move);
    }
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

    if (gBattleControllerExecFlags)
        return;

    if (!gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure)
    {
        switch (GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove))
        {
        case MOVE_TARGET_FOES_AND_ALLY:
            for (i = 0; i < gBattlersCount; i++)
            {
                if (i != gBattlerAttacker && IsBattlerAlive(i))
                    ppToDeduct += (GetBattlerAbility(i) == ABILITY_PRESSURE);
            }
            break;
        case MOVE_TARGET_BOTH:
        case MOVE_TARGET_OPPONENTS_FIELD:
            for (i = 0; i < gBattlersCount; i++)
            {
                if (GetBattlerSide(i) != GetBattlerSide(gBattlerAttacker) && IsBattlerAlive(i))
                    ppToDeduct += (GetBattlerAbility(i) == ABILITY_PRESSURE);
            }
            break;
        default:
            if (gBattlerAttacker != gBattlerTarget && GetBattlerAbility(gBattlerTarget) == ABILITY_PRESSURE)
                ppToDeduct++;
            break;
        }
    }

    if (!(gHitMarker & (HITMARKER_NO_PPDEDUCT | HITMARKER_NO_ATTACKSTRING)) && gBattleMons[gBattlerAttacker].pp[gCurrMovePos])
    {
        gProtectStructs[gBattlerAttacker].notFirstStrike = TRUE;
        // For item Metronome, echoed voice
        if (gCurrentMove == gLastResultingMoves[gBattlerAttacker]
            && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
            && !WasUnableToUseMove(gBattlerAttacker)
            && gSpecialStatuses[gBattlerAttacker].parentalBondState != PARENTAL_BOND_1ST_HIT) // Don't increment counter on first hit
                gBattleStruct->sameMoveTurns[gBattlerAttacker]++;
        else
            gBattleStruct->sameMoveTurns[gBattlerAttacker] = 0;

        if (gBattleMons[gBattlerAttacker].pp[gCurrMovePos] > ppToDeduct)
            gBattleMons[gBattlerAttacker].pp[gCurrMovePos] -= ppToDeduct;
        else
            gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = 0;

        if (MOVE_IS_PERMANENT(gBattlerAttacker, gCurrMovePos))
        {
            gActiveBattler = gBattlerAttacker;
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_PPMOVE1_BATTLE + gCurrMovePos, 0,
                                         sizeof(gBattleMons[gBattlerAttacker].pp[gCurrMovePos]),
                                         &gBattleMons[gBattlerAttacker].pp[gCurrMovePos]);
            MarkBattlerForControllerExec(gBattlerAttacker);
        }
    }

    gHitMarker &= ~HITMARKER_NO_PPDEDUCT;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// The chance is 1/N for each stage.
#if B_CRIT_CHANCE >= GEN_7
    static const u8 sCriticalHitChance[] = {24, 8, 2, 1, 1};
#elif B_CRIT_CHANCE == GEN_6
    static const u8 sCriticalHitChance[] = {16, 8, 2, 1, 1};
#else
    static const u8 sCriticalHitChance[] = {16, 8, 4, 3, 2}; // Gens 2,3,4,5
#endif // B_CRIT_CHANCE

#define BENEFITS_FROM_LEEK(battler, holdEffect)((holdEffect == HOLD_EFFECT_LEEK) && (GET_BASE_SPECIES_ID(gBattleMons[battler].species) == SPECIES_FARFETCHD || gBattleMons[battler].species == SPECIES_SIRFETCHD))
s32 CalcCritChanceStage(u8 battlerAtk, u8 battlerDef, u32 move, bool32 recordAbility)
{
    s32 critChance = 0;
    u32 abilityAtk = GetBattlerAbility(gBattlerAttacker);
    u32 abilityDef = GetBattlerAbility(gBattlerTarget);
    u32 holdEffectAtk = GetBattlerHoldEffect(battlerAtk, TRUE);

    if (gSideStatuses[battlerDef] & SIDE_STATUS_LUCKY_CHANT
        || gStatuses3[gBattlerAttacker] & STATUS3_CANT_SCORE_A_CRIT)
    {
        critChance = -1;
    }
    else if (abilityDef == ABILITY_BATTLE_ARMOR || abilityDef == ABILITY_SHELL_ARMOR)
    {
        if (recordAbility)
            RecordAbilityBattle(battlerDef, abilityDef);
        critChance = -1;
    }
    else if (gStatuses3[battlerAtk] & STATUS3_LASER_FOCUS
             || gBattleMoves[move].effect == EFFECT_ALWAYS_CRIT
             || (abilityAtk == ABILITY_MERCILESS && gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY)
             || move == MOVE_SURGING_STRIKES)
    {
        critChance = -2;
    }
    else
    {
        critChance  = 2 * ((gBattleMons[gBattlerAttacker].status2 & STATUS2_FOCUS_ENERGY) != 0)
                    + ((gBattleMoves[gCurrentMove].flags & FLAG_HIGH_CRIT) != 0)
                    + (holdEffectAtk == HOLD_EFFECT_SCOPE_LENS)
                    + 2 * (holdEffectAtk == HOLD_EFFECT_LUCKY_PUNCH && gBattleMons[gBattlerAttacker].species == SPECIES_CHANSEY)
                    + 2 * BENEFITS_FROM_LEEK(battlerAtk, holdEffectAtk)
                #if B_AFFECTION_MECHANICS == TRUE
                    + 2 * (GetBattlerFriendshipScore(gBattlerAttacker) >= FRIENDSHIP_200_TO_254)
                #endif
                    + (abilityAtk == ABILITY_SUPER_LUCK);

        if (critChance >= ARRAY_COUNT(sCriticalHitChance))
            critChance = ARRAY_COUNT(sCriticalHitChance) - 1;
    }

    return critChance;
}
#undef BENEFITS_FROM_LEEK

s8 GetInverseCritChance(u8 battlerAtk, u8 battlerDef, u32 move)
{
    s32 critChanceIndex = CalcCritChanceStage(battlerAtk, battlerDef, move, FALSE);
    if(critChanceIndex < 0)
        return -1;
    else
        return sCriticalHitChance[critChanceIndex];
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
        gIsCriticalHit = RandomWeighted(RNG_CRITICAL_HIT, sCriticalHitChance[critChance] - 1, 1);

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
    gBattleMoveDamage = CalculateMoveDamage(gCurrentMove, gBattlerAttacker, gBattlerTarget, moveType, 0, gIsCriticalHit, TRUE, TRUE);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_typecalc(void)
{
    CMD_ARGS();

    u8 moveType;

    GET_MOVE_TYPE(gCurrentMove, moveType);
    CalcTypeEffectivenessMultiplier(gCurrentMove, moveType, gBattlerAttacker, gBattlerTarget, TRUE);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_adjustdamage(void)
{
    CMD_ARGS();

    u8 holdEffect, param;
    u32 moveType;
    u32 friendshipScore = GetBattlerFriendshipScore(gBattlerTarget);
    u32 rand = Random() % 100;

    GET_MOVE_TYPE(gCurrentMove, moveType);

    if (DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
        goto END;
    if (DoesDisguiseBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
        goto END;
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
    #if B_STURDY >= GEN_5
    else if (GetBattlerAbility(gBattlerTarget) == ABILITY_STURDY && BATTLER_MAX_HP(gBattlerTarget))
    {
        RecordAbilityBattle(gBattlerTarget, ABILITY_STURDY);
        gSpecialStatuses[gBattlerTarget].sturdied = TRUE;
    }
    #endif
    else if (holdEffect == HOLD_EFFECT_FOCUS_SASH && BATTLER_MAX_HP(gBattlerTarget))
    {
        RecordItemEffectBattle(gBattlerTarget, holdEffect);
        gSpecialStatuses[gBattlerTarget].focusSashed = TRUE;
    }
#if B_AFFECTION_MECHANICS == TRUE
    else if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER && friendshipScore >= FRIENDSHIP_100_TO_149)
    {
        if ((friendshipScore == FRIENDSHIP_MAX && rand < 25)
         || (friendshipScore == FRIENDSHIP_200_TO_254 && rand < 20)
         || (friendshipScore == FRIENDSHIP_150_TO_199 && rand < 15)
         || (friendshipScore == FRIENDSHIP_100_TO_149 && rand < 10))
            gSpecialStatuses[gBattlerTarget].affectionEndured = TRUE;
    }
#endif

    if (gBattleMoves[gCurrentMove].effect != EFFECT_FALSE_SWIPE
        && !gProtectStructs[gBattlerTarget].endured
        && !gSpecialStatuses[gBattlerTarget].focusBanded
        && !gSpecialStatuses[gBattlerTarget].focusSashed
#if B_AFFECTION_MECHANICS == TRUE
        && !gSpecialStatuses[gBattlerTarget].affectionEndured
#endif
        && !gSpecialStatuses[gBattlerTarget].sturdied)
        goto END;

    // Handle reducing the dmg to 1 hp.
    gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - 1;

    if (gProtectStructs[gBattlerTarget].endured)
    {
        gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED;
    }
    else if (gSpecialStatuses[gBattlerTarget].focusBanded || gSpecialStatuses[gBattlerTarget].focusSashed)
    {
        gMoveResultFlags |= MOVE_RESULT_FOE_HUNG_ON;
        gLastUsedItem = gBattleMons[gBattlerTarget].item;
    }
    else if (gSpecialStatuses[gBattlerTarget].sturdied)
    {
        gMoveResultFlags |= MOVE_RESULT_STURDIED;
        gLastUsedAbility = ABILITY_STURDY;
    }
#if B_AFFECTION_MECHANICS == TRUE
    else if (gSpecialStatuses[gBattlerTarget].affectionEndured)
    {
        gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED_AFFECTION;
    }
#endif

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
        && gBattleMons[gBattlerAttacker].item)
    {
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_GemActivates;
        gLastUsedItem = gBattleMons[gBattlerAttacker].item;
    }

    // B_WEATHER_STRONG_WINDS prints a string when it's about to reduce the power
    // of a move that is Super Effective against a Flying-type Pokémon.
    if (gBattleWeather & B_WEATHER_STRONG_WINDS)
    {
        if ((gBattleMons[gBattlerTarget].type1 == TYPE_FLYING
         && GetTypeModifier(moveType, gBattleMons[gBattlerTarget].type1) >= UQ_4_12(2.0))
         || (gBattleMons[gBattlerTarget].type2 == TYPE_FLYING
         && GetTypeModifier(moveType, gBattleMons[gBattlerTarget].type2) >= UQ_4_12(2.0))
         || (gBattleMons[gBattlerTarget].type3 == TYPE_FLYING
         && GetTypeModifier(moveType, gBattleMons[gBattlerTarget].type3) >= UQ_4_12(2.0)))
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

    if ((gHitMarker & HITMARKER_NO_ANIMATIONS)
        && gCurrentMove != MOVE_TRANSFORM
        && gCurrentMove != MOVE_SUBSTITUTE
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

            gActiveBattler = gBattlerAttacker;

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

            BtlController_EmitMoveAnimation(BUFFER_A, gCurrentMove, gBattleScripting.animTurn, gBattleMovePower, gBattleMoveDamage, gBattleMons[gBattlerAttacker].friendship, &gDisableStructs[gBattlerAttacker], multihit);
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
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);

        if (DoesSubstituteBlockMove(gBattlerAttacker, gActiveBattler, gCurrentMove) && gDisableStructs[gActiveBattler].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            PrepareStringBattle(STRINGID_SUBSTITUTEDAMAGED, gActiveBattler);
        }
        else if (!DoesDisguiseBlockMove(gBattlerAttacker, gActiveBattler, gCurrentMove))
        {
            s16 healthValue = min(gBattleMoveDamage, 10000); // Max damage (10000) not present in R/S, ensures that huge damage values don't change sign

            BtlController_EmitHealthBarUpdate(BUFFER_A, healthValue);
            MarkBattlerForControllerExec(gActiveBattler);

            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER && gBattleMoveDamage > 0)
                gBattleResults.playerMonWasDamaged = TRUE;
        }
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_datahpupdate(void)
{
    CMD_ARGS(u8 battler);

    u32 moveType;

    if (gBattleControllerExecFlags)
        return;

    if (gBattleStruct->dynamicMoveType == 0)
        moveType = gBattleMoves[gCurrentMove].type;
    else if (!(gBattleStruct->dynamicMoveType & F_DYNAMIC_TYPE_1))
        moveType = gBattleStruct->dynamicMoveType & DYNAMIC_TYPE_MASK;
    else
        moveType = gBattleMoves[gCurrentMove].type;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) || (gHitMarker & HITMARKER_PASSIVE_DAMAGE))
    {
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);
        if (DoesSubstituteBlockMove(gBattlerAttacker, gActiveBattler, gCurrentMove) && gDisableStructs[gActiveBattler].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            if (gDisableStructs[gActiveBattler].substituteHP >= gBattleMoveDamage)
            {
                if (gSpecialStatuses[gActiveBattler].dmg == 0)
                    gSpecialStatuses[gActiveBattler].dmg = gBattleMoveDamage;
                gDisableStructs[gActiveBattler].substituteHP -= gBattleMoveDamage;
                gHpDealt = gBattleMoveDamage;
            }
            else
            {
                if (gSpecialStatuses[gActiveBattler].dmg == 0)
                    gSpecialStatuses[gActiveBattler].dmg = gDisableStructs[gActiveBattler].substituteHP;
                gHpDealt = gDisableStructs[gActiveBattler].substituteHP;
                gDisableStructs[gActiveBattler].substituteHP = 0;
            }
            // check substitute fading
            if (gDisableStructs[gActiveBattler].substituteHP == 0)
            {
                gBattlescriptCurrInstr = cmd->nextInstr;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SubstituteFade;
                return;
            }
        }
        else if (DoesDisguiseBlockMove(gBattlerAttacker, gActiveBattler, gCurrentMove))
        {
            gBattleMons[gActiveBattler].species = SPECIES_MIMIKYU_BUSTED;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_TargetFormChange;
        }
        else
        {
            gHitMarker &= ~HITMARKER_IGNORE_SUBSTITUTE;
            if (gBattleMoveDamage < 0) // hp goes up
            {
                gBattleMons[gActiveBattler].hp -= gBattleMoveDamage;
                if (gBattleMons[gActiveBattler].hp > gBattleMons[gActiveBattler].maxHP)
                    gBattleMons[gActiveBattler].hp = gBattleMons[gActiveBattler].maxHP;

            }
            else // hp goes down
            {
                if (gHitMarker & HITMARKER_SKIP_DMG_TRACK)
                {
                    gHitMarker &= ~HITMARKER_SKIP_DMG_TRACK;
                }
                else
                {
                    gTakenDmg[gActiveBattler] += gBattleMoveDamage;
                    if (cmd->battler == BS_TARGET)
                        gTakenDmgByBattler[gActiveBattler] = gBattlerAttacker;
                    else
                        gTakenDmgByBattler[gActiveBattler] = gBattlerTarget;
                }

                if (gBattleMons[gActiveBattler].hp > gBattleMoveDamage)
                {
                    gBattleMons[gActiveBattler].hp -= gBattleMoveDamage;
                    gHpDealt = gBattleMoveDamage;
                }
                else
                {
                    gHpDealt = gBattleMons[gActiveBattler].hp;
                    gBattleMons[gActiveBattler].hp = 0;
                }

                if (!gSpecialStatuses[gActiveBattler].dmg && !(gHitMarker & HITMARKER_PASSIVE_DAMAGE))
                    gSpecialStatuses[gActiveBattler].dmg = gHpDealt;

                if (IS_MOVE_PHYSICAL(gCurrentMove) && !(gHitMarker & HITMARKER_PASSIVE_DAMAGE) && gCurrentMove != MOVE_PAIN_SPLIT)
                {
                    gProtectStructs[gActiveBattler].physicalDmg = gHpDealt;
                    gSpecialStatuses[gActiveBattler].physicalDmg = gHpDealt;
                    if (cmd->battler == BS_TARGET)
                    {
                        gProtectStructs[gActiveBattler].physicalBattlerId = gBattlerAttacker;
                        gSpecialStatuses[gActiveBattler].physicalBattlerId = gBattlerAttacker;
                    }
                    else
                    {
                        gProtectStructs[gActiveBattler].physicalBattlerId = gBattlerTarget;
                        gSpecialStatuses[gActiveBattler].physicalBattlerId = gBattlerTarget;
                    }
                }
                else if (!IS_MOVE_PHYSICAL(gCurrentMove) && !(gHitMarker & HITMARKER_PASSIVE_DAMAGE))
                {
                    gProtectStructs[gActiveBattler].specialDmg = gHpDealt;
                    gSpecialStatuses[gActiveBattler].specialDmg = gHpDealt;
                    if (cmd->battler == BS_TARGET)
                    {
                        gProtectStructs[gActiveBattler].specialBattlerId = gBattlerAttacker;
                        gSpecialStatuses[gActiveBattler].specialBattlerId = gBattlerAttacker;
                    }
                    else
                    {
                        gProtectStructs[gActiveBattler].specialBattlerId = gBattlerTarget;
                        gSpecialStatuses[gActiveBattler].specialBattlerId = gBattlerTarget;
                    }
                }
            }
            gHitMarker &= ~HITMARKER_PASSIVE_DAMAGE;
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_HP_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].hp), &gBattleMons[gActiveBattler].hp);
            MarkBattlerForControllerExec(gActiveBattler);
        }
    }
    else
    {
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);
        if (gSpecialStatuses[gActiveBattler].dmg == 0)
            gSpecialStatuses[gActiveBattler].dmg = 0xFFFF;
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

    gActiveBattler = gBattlerTarget;
    if (!(gMoveResultFlags & MOVE_RESULT_MISSED))
    {
        switch (gMoveResultFlags & ~MOVE_RESULT_MISSED)
        {
        case MOVE_RESULT_SUPER_EFFECTIVE:
            BtlController_EmitPlaySE(BUFFER_A, SE_SUPER_EFFECTIVE);
            MarkBattlerForControllerExec(gActiveBattler);
            break;
        case MOVE_RESULT_NOT_VERY_EFFECTIVE:
            BtlController_EmitPlaySE(BUFFER_A, SE_NOT_EFFECTIVE);
            MarkBattlerForControllerExec(gActiveBattler);
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
                BtlController_EmitPlaySE(BUFFER_A, SE_SUPER_EFFECTIVE);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            else if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
            {
                BtlController_EmitPlaySE(BUFFER_A, SE_NOT_EFFECTIVE);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            else if (!(gMoveResultFlags & (MOVE_RESULT_DOESNT_AFFECT_FOE | MOVE_RESULT_FAILED)))
            {
                BtlController_EmitPlaySE(BUFFER_A, SE_EFFECTIVE);
                MarkBattlerForControllerExec(gActiveBattler);
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
        #if B_AFFECTION_MECHANICS == TRUE
            else if (gMoveResultFlags & MOVE_RESULT_FOE_ENDURED_AFFECTION)
            {
                gSpecialStatuses[gBattlerTarget].affectionEndured = FALSE;
                gMoveResultFlags &= ~MOVE_RESULT_FOE_ENDURED_AFFECTION;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_AffectionBasedEndurance;
                return;
            }
        #endif
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
        u16 id = cmd->id;

        gBattlescriptCurrInstr = cmd->nextInstr;
        PrepareStringBattle(id, gBattlerAttacker);
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

static void Cmd_printselectionstring(void)
{
    CMD_ARGS(u16 id);

    gActiveBattler = gBattlerAttacker;

    BtlController_EmitPrintSelectionString(BUFFER_A, cmd->id);
    MarkBattlerForControllerExec(gActiveBattler);

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

        gActiveBattler = gBattlerAttacker;
        BtlController_EmitPrintSelectionString(BUFFER_A, *ptr);
        MarkBattlerForControllerExec(gActiveBattler);

        gBattlescriptCurrInstr = cmd->nextInstr;
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

u8 GetBattlerTurnOrderNum(u8 battlerId)
{
    s32 i;
    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBattlerByTurnOrder[i] == battlerId)
            break;
    }
    return i;
}

static void CheckSetUnburden(u8 battlerId)
{
    if (GetBattlerAbility(battlerId) == ABILITY_UNBURDEN)
    {
        gBattleResources->flags->flags[battlerId] |= RESOURCE_FLAG_UNBURDEN;
        RecordAbilityBattle(battlerId, ABILITY_UNBURDEN);
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

    gActiveBattler = battlerStealer;
    BtlController_EmitSetMonData(BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gLastUsedItem), &gLastUsedItem); // set attacker item
    MarkBattlerForControllerExec(battlerStealer);

    gActiveBattler = battlerItem;
    BtlController_EmitSetMonData(BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].item), &gBattleMons[battlerItem].item);  // remove target item
    MarkBattlerForControllerExec(battlerItem);

    gBattleStruct->choicedMove[battlerItem] = 0;

    TrySaveExchangedItem(battlerItem, gLastUsedItem);
}

#define INCREMENT_RESET_RETURN                  \
{                                               \
    gBattlescriptCurrInstr++;                   \
    gBattleScripting.moveEffect = 0; \
    return;                                     \
}

#define RESET_RETURN                            \
{                                               \
    gBattleScripting.moveEffect = 0; \
    return;                                     \
}

void SetMoveEffect(bool32 primary, u32 certain)
{
    s32 i, byTwo, affectsUser = 0;
    bool32 statusChanged = FALSE;
    bool32 mirrorArmorReflected = (GetBattlerAbility(gBattlerTarget) == ABILITY_MIRROR_ARMOR);
    u32 flags = 0;
    u16 battlerAbility;
    bool8 activateAfterFaint = FALSE;

    if (gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_1ST_HIT
        && gBattleMons[gBattlerTarget].hp != 0
        && IsFinalStrikeEffect(gCurrentMove))
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
        gEffectBattler = gBattlerAttacker; // battlerId that effects get applied on
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

    if ((battlerAbility == ABILITY_SHIELD_DUST
     || GetBattlerHoldEffect(gEffectBattler, TRUE) == HOLD_EFFECT_COVERT_CLOAK)
      && !(gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
      && !primary
      && (gBattleScripting.moveEffect <= MOVE_EFFECT_TRI_ATTACK || gBattleScripting.moveEffect >= MOVE_EFFECT_SMACK_DOWN)) // Exclude stat lowering effects
    {
        if (battlerAbility == ABILITY_SHIELD_DUST)
            RecordAbilityBattle(gEffectBattler, battlerAbility);
        else
            RecordItemEffectBattle(gEffectBattler, HOLD_EFFECT_COVERT_CLOAK);
        INCREMENT_RESET_RETURN
    }

    if (gSideStatuses[GET_BATTLER_SIDE(gEffectBattler)] & SIDE_STATUS_SAFEGUARD && !(gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
        && !primary && gBattleScripting.moveEffect <= MOVE_EFFECT_CONFUSION)
        INCREMENT_RESET_RETURN

    if (TestSheerForceFlag(gBattlerAttacker, gCurrentMove) && affectsUser != MOVE_EFFECT_AFFECTS_USER)
        INCREMENT_RESET_RETURN

    if (gBattleMons[gEffectBattler].hp == 0 && !activateAfterFaint)
        INCREMENT_RESET_RETURN

    if (DoesSubstituteBlockMove(gBattlerAttacker, gEffectBattler, gCurrentMove) && affectsUser != MOVE_EFFECT_AFFECTS_USER)
        INCREMENT_RESET_RETURN

    if (gBattleScripting.moveEffect <= PRIMARY_STATUS_MOVE_EFFECT) // status change
    {
        switch (sStatusFlagsForMoveEffects[gBattleScripting.moveEffect])
        {
        case STATUS1_SLEEP:
            // check active uproar
            if (battlerAbility != ABILITY_SOUNDPROOF)
            {
                for (gActiveBattler = 0;
                    gActiveBattler < gBattlersCount && !(gBattleMons[gActiveBattler].status2 & STATUS2_UPROAR);
                    gActiveBattler++)
                    ;
            }
            else
                gActiveBattler = gBattlersCount;

            if (gActiveBattler != gBattlersCount)
                break;
            if (!CanSleep(gEffectBattler))
                break;

            CancelMultiTurnMoves(gEffectBattler);
            statusChanged = TRUE;
            break;
        case STATUS1_POISON:
            if ((battlerAbility == ABILITY_IMMUNITY || battlerAbility == ABILITY_PASTEL_VEIL)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                gLastUsedAbility = battlerAbility;
                RecordAbilityBattle(gEffectBattler, battlerAbility);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                    gHitMarker &= ~HITMARKER_IGNORE_SAFEGUARD;
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                }
                RESET_RETURN
            }
            if (!CanPoisonType(gBattleScripting.battler, gEffectBattler)
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STATUS_HAD_NO_EFFECT;
                RESET_RETURN
            }
            if (!CanBePoisoned(gBattleScripting.battler, gEffectBattler))
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_BURN:
            if (gCurrentMove == MOVE_BURNING_JEALOUSY && !gProtectStructs[gEffectBattler].statRaised)
                break;

            if ((battlerAbility == ABILITY_WATER_VEIL || battlerAbility == ABILITY_WATER_BUBBLE)
              && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                gLastUsedAbility = battlerAbility;
                RecordAbilityBattle(gEffectBattler, battlerAbility);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;
                if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                    gHitMarker &= ~HITMARKER_IGNORE_SAFEGUARD;
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                }
                RESET_RETURN
            }
            if (IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_FIRE)
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STATUS_HAD_NO_EFFECT;
                RESET_RETURN
            }

            if (!CanBeBurned(gEffectBattler))
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_FREEZE:
            if (!CanBeFrozen(gEffectBattler))
                break;

            CancelMultiTurnMoves(gEffectBattler);
            statusChanged = TRUE;
            break;
        case STATUS1_PARALYSIS:
            if (battlerAbility == ABILITY_LIMBER)
            {
                if (primary == TRUE || certain == MOVE_EFFECT_CERTAIN)
                {
                    gLastUsedAbility = ABILITY_LIMBER;
                    RecordAbilityBattle(gEffectBattler, ABILITY_LIMBER);

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_PRLZPrevention;

                    if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                        gHitMarker &= ~HITMARKER_IGNORE_SAFEGUARD;
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
            if (!CanParalyzeType(gBattleScripting.battler, gEffectBattler)
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PRLZPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                RESET_RETURN
            }
            if (!CanParalyzeType(gBattleScripting.battler, gEffectBattler))
                break;
            if (!CanBeParalyzed(gEffectBattler))
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_TOXIC_POISON:
            if ((battlerAbility == ABILITY_IMMUNITY || battlerAbility == ABILITY_PASTEL_VEIL)
             && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                gLastUsedAbility = battlerAbility;
                RecordAbilityBattle(gEffectBattler, battlerAbility);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_ABILITY_STATUS;
                    gHitMarker &= ~HITMARKER_IGNORE_SAFEGUARD;
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABILITY_PREVENTS_MOVE_STATUS;
                }
                RESET_RETURN
            }
            if (!CanPoisonType(gBattleScripting.battler, gEffectBattler)
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STATUS_HAD_NO_EFFECT;
                RESET_RETURN
            }
            if (gBattleMons[gEffectBattler].status1)
                break;
            if (CanBePoisoned(gBattleScripting.battler, gEffectBattler))
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
            if (!CanGetFrostbite(gEffectBattler))
                break;

            statusChanged = TRUE;
            break;
        }
        if (statusChanged == TRUE)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);

            if (sStatusFlagsForMoveEffects[gBattleScripting.moveEffect] == STATUS1_SLEEP)
            #if B_SLEEP_TURNS >= GEN_5
                gBattleMons[gEffectBattler].status1 |= STATUS1_SLEEP_TURN(1 + RandomUniform(RNG_SLEEP_TURNS, 1, 3));
            #else
                gBattleMons[gEffectBattler].status1 |= STATUS1_SLEEP_TURN(1 + RandomUniform(RNG_SLEEP_TURNS, 2, 5));
            #endif
            else
                gBattleMons[gEffectBattler].status1 |= sStatusFlagsForMoveEffects[gBattleScripting.moveEffect];

            gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];

            gActiveBattler = gEffectBattler;
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].status1), &gBattleMons[gEffectBattler].status1);
            MarkBattlerForControllerExec(gActiveBattler);

            if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STATUSED_BY_ABILITY;
                gHitMarker &= ~HITMARKER_IGNORE_SAFEGUARD;
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
            u8 side;
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
                    if(gCurrentMove == MOVE_SKY_DROP)
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
                    if (primary == TRUE || certain == MOVE_EFFECT_CERTAIN)
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
                else
                {
                    if (GetBattlerTurnOrderNum(gEffectBattler) > gCurrentTurnActionNumber)
                        gBattleMons[gEffectBattler].status2 |= sStatusFlagsForMoveEffects[gBattleScripting.moveEffect];
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_UPROAR:
                if (!(gBattleMons[gEffectBattler].status2 & STATUS2_UPROAR))
                {
                    gBattleMons[gEffectBattler].status2 |= STATUS2_MULTIPLETURNS;
                    gLockedMoves[gEffectBattler] = gCurrentMove;
                #if B_UPROAR_TURNS >= GEN_5
                    gBattleMons[gEffectBattler].status2 |= STATUS2_UPROAR_TURN(3);
                #else
                    gBattleMons[gEffectBattler].status2 |= STATUS2_UPROAR_TURN((Random() & 3) + 2);
                #endif

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
                if (GET_BATTLER_SIDE(gBattlerAttacker) == B_SIDE_PLAYER && gSpecialStatuses[gBattlerAttacker].parentalBondState!= PARENTAL_BOND_2ND_HIT)
                {
                    u16 payday = gPaydayMoney;
                    gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 5);
                    if (payday > gPaydayMoney)
                        gPaydayMoney = 0xFFFF;

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectPayDay;
                }
                else
                {
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_HAPPY_HOUR:
                if (GET_BATTLER_SIDE(gBattlerAttacker) == B_SIDE_PLAYER && !gBattleStruct->moneyMultiplierMove)
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
                #if B_USE_FROSTBITE == TRUE
                    static const u8 sTriAttackEffects[] = { MOVE_EFFECT_BURN, MOVE_EFFECT_FROSTBITE, MOVE_EFFECT_PARALYSIS };
                #else
                    static const u8 sTriAttackEffects[] = { MOVE_EFFECT_BURN, MOVE_EFFECT_FREEZE, MOVE_EFFECT_PARALYSIS };
                #endif
                    gBattleScripting.moveEffect = RandomElement(RNG_TRI_ATTACK, sTriAttackEffects);
                    SetMoveEffect(FALSE, 0);
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
                #if B_BINDING_TURNS >= GEN_5
                        gDisableStructs[gEffectBattler].wrapTurns = 7;
                    else
                        gDisableStructs[gEffectBattler].wrapTurns = (Random() % 2) + 4;
                #else
                        gDisableStructs[gEffectBattler].wrapTurns = 5;
                    else
                        gDisableStructs[gEffectBattler].wrapTurns = (Random() % 4) + 2;
                #endif

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
                                    affectsUser | STAT_CHANGE_UPDATE_MOVE_EFFECT, 0))
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
                flags = affectsUser;
                if (mirrorArmorReflected && !affectsUser)
                    flags |= STAT_CHANGE_ALLOW_PTR;

                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(1) | STAT_BUFF_NEGATIVE,
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_MINUS_1 + 1,
                                    flags | STAT_CHANGE_UPDATE_MOVE_EFFECT, gBattlescriptCurrInstr + 1))
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
                                    affectsUser | STAT_CHANGE_UPDATE_MOVE_EFFECT, 0))
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
                flags = affectsUser;
                if (mirrorArmorReflected && !affectsUser)
                    flags |= STAT_CHANGE_ALLOW_PTR;
                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(2) | STAT_BUFF_NEGATIVE,
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_MINUS_2 + 1,
                                    flags | STAT_CHANGE_UPDATE_MOVE_EFFECT, gBattlescriptCurrInstr + 1))
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
                    if (!CanStealItem(gBattlerAttacker, gBattlerTarget, gBattleMons[gBattlerTarget].item))
                    {
                        gBattlescriptCurrInstr++;
                        break;
                    }

                    side = GetBattlerSide(gBattlerAttacker);
                    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT
                        && !(gBattleTypeFlags &
                            (BATTLE_TYPE_EREADER_TRAINER
                            | BATTLE_TYPE_FRONTIER
                            | BATTLE_TYPE_LINK
                            | BATTLE_TYPE_RECORDED_LINK
                            | BATTLE_TYPE_SECRET_BASE)))
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else if (!(gBattleTypeFlags &
                            (BATTLE_TYPE_EREADER_TRAINER
                            | BATTLE_TYPE_FRONTIER
                            | BATTLE_TYPE_LINK
                            | BATTLE_TYPE_RECORDED_LINK
                            | BATTLE_TYPE_SECRET_BASE))
                        && (gWishFutureKnock.knockedOffMons[side] & gBitTable[gBattlerPartyIndexes[gBattlerAttacker]]))
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else if (gBattleMons[gBattlerTarget].item
                        && GetBattlerAbility(gBattlerTarget) == ABILITY_STICKY_HOLD)
                    {
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_NoItemSteal;

                        gLastUsedAbility = gBattleMons[gBattlerTarget].ability;
                        RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
                    }
                    else if (gBattleMons[gBattlerAttacker].item != ITEM_NONE
                        || gBattleMons[gBattlerTarget].item == ITEM_ENIGMA_BERRY_E_READER
                        || gBattleMons[gBattlerTarget].item == ITEM_NONE)
                    {
                        gBattlescriptCurrInstr++;
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
            case MOVE_EFFECT_RAPIDSPIN:
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
                if (gBattleMons[gEffectBattler].status2 & STATUS2_LOCK_CONFUSE)
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
            case MOVE_EFFECT_SP_ATK_TWO_DOWN: // Overheat
                if (!NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_SAtkDown2;
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
                    gBattleMoveDamage = gBattleMons[BATTLE_PARTNER(gBattlerTarget)].hp / 16;
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
                    gBattleStruct->stolenStats[0] = 0; // Stats to steal.
                    gBattleScripting.animArg1 = 0;
                    for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                    {
                        if (gBattleMons[gBattlerTarget].statStages[i] > DEFAULT_STAT_STAGE && gBattleMons[gBattlerAttacker].statStages[i] != MAX_STAT_STAGE)
                        {
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
                                    gBattleScripting.animArg1 = STAT_ANIM_PLUS2 - 1 + i;
                                else
                                    gBattleScripting.animArg1 = STAT_ANIM_PLUS1 - 1 + i;
                            }
                            else
                            {
                                if (byTwo)
                                    gBattleScripting.animArg1 = STAT_ANIM_MULTIPLE_PLUS2;
                                else
                                    gBattleScripting.animArg1 = STAT_ANIM_MULTIPLE_PLUS1;
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
                #if B_INCINERATE_GEMS >= GEN_6
                    || (GetBattlerHoldEffect(gEffectBattler, FALSE) == HOLD_EFFECT_GEMS)
                #endif
                )
                {
                    gLastUsedItem = gBattleMons[gEffectBattler].item;
                    gBattleMons[gEffectBattler].item = 0;
                    CheckSetUnburden(gEffectBattler);

                    gActiveBattler = gEffectBattler;
                    BtlController_EmitSetMonData(BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].item), &gBattleMons[gEffectBattler].item);
                    MarkBattlerForControllerExec(gActiveBattler);
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
                    gActiveBattler = gEffectBattler;

                    BtlController_EmitSetMonData(BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].item), &gBattleMons[gEffectBattler].item);
                    MarkBattlerForControllerExec(gActiveBattler);
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectBugBite;
                }
                break;
            case MOVE_EFFECT_RELIC_SONG:
                if (GetBattlerAbility(gBattlerAttacker) != ABILITY_SHEER_FORCE && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_TRANSFORMED))
                {
                    if (gBattleMons[gBattlerAttacker].species == SPECIES_MELOETTA)
                    {
                        gBattleMons[gBattlerAttacker].species = SPECIES_MELOETTA_PIROUETTE;
                        BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeMoveEffect);
                    }
                    else if (gBattleMons[gBattlerAttacker].species == SPECIES_MELOETTA_PIROUETTE)
                    {
                        gBattleMons[gBattlerAttacker].species = SPECIES_MELOETTA;
                        BattleScriptPushCursorAndCallback(BattleScript_AttackerFormChangeMoveEffect);
                    }
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
            case MOVE_EFFECT_SCALE_SHOT:
                if (!NoAliveMonsForEitherParty())
                {
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_DefDownSpeedUp;
                }
                break;
            case MOVE_EFFECT_BURN_UP:
                // This seems unnecessary but is done to make it work properly with Parental Bond
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BurnUpRemoveType;
                break;
            case MOVE_EFFECT_DOUBLE_SHOCK:
                // This seems unnecessary but is done to make it work properly with Parental Bond
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_DoubleShockRemoveType;
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
                    SetMoveEffect(TRUE, 0);
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
                    gBattlescriptCurrInstr = BattleScript_SpikesActivates;
                }
                break;
            }
        }
    }

    gBattleScripting.moveEffect = 0;
}

static void Cmd_seteffectwithchance(void)
{
    CMD_ARGS();

    u32 percentChance;

    if (GetBattlerAbility(gBattlerAttacker) == ABILITY_SERENE_GRACE)
        percentChance = gBattleMoves[gCurrentMove].secondaryEffectChance * 2;
    else
        percentChance = gBattleMoves[gCurrentMove].secondaryEffectChance;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
     && gBattleScripting.moveEffect)
    {
        if (gBattleScripting.moveEffect & MOVE_EFFECT_CERTAIN
         || percentChance >= 100)
        {
            gBattleScripting.moveEffect &= ~MOVE_EFFECT_CERTAIN;
            SetMoveEffect(FALSE, MOVE_EFFECT_CERTAIN);
        }
        else if (RandomPercentage(RNG_SECONDARY_EFFECT, percentChance))
        {
            SetMoveEffect(FALSE, 0);
        }
        else
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }

    gBattleScripting.moveEffect = 0;
    gBattleScripting.multihitMoveEffect = 0;
}

static void Cmd_seteffectprimary(void)
{
    CMD_ARGS();

    SetMoveEffect(TRUE, 0);
}

static void Cmd_seteffectsecondary(void)
{
    CMD_ARGS();

    SetMoveEffect(FALSE, 0);
}

static void Cmd_clearstatusfromeffect(void)
{
    CMD_ARGS(u8 battler);

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);

    if (gBattleScripting.moveEffect <= PRIMARY_STATUS_MOVE_EFFECT)
        gBattleMons[gActiveBattler].status1 &= (~sStatusFlagsForMoveEffects[gBattleScripting.moveEffect]);
    else
        gBattleMons[gActiveBattler].status2 &= (~sStatusFlagsForMoveEffects[gBattleScripting.moveEffect]);

    gBattleScripting.moveEffect = 0;
    gBattlescriptCurrInstr = cmd->nextInstr;
    gBattleScripting.multihitMoveEffect = 0;
}

static void Cmd_tryfaintmon(void)
{
    CMD_ARGS(u8 battler, bool8 isSpikes, const u8 *instr);
    const u8 *instr;

    if (cmd->isSpikes != 0)
    {
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);
        if (gHitMarker & HITMARKER_FAINTED(gActiveBattler))
        {
            instr = cmd->instr;

            BattleScriptPop();
            gBattlescriptCurrInstr = instr;
            gSideStatuses[GetBattlerSide(gActiveBattler)] &= ~(SIDE_STATUS_SPIKES_DAMAGED | SIDE_STATUS_TOXIC_SPIKES_DAMAGED | SIDE_STATUS_STEALTH_ROCK_DAMAGED | SIDE_STATUS_STICKY_WEB_DAMAGED);
        }
        else
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
    else
    {
        u8 battlerId;

        if (cmd->battler == BS_ATTACKER)
        {
            gActiveBattler = gBattlerAttacker;
            battlerId = gBattlerTarget;
            instr = BattleScript_FaintAttacker;
        }
        else
        {
            gActiveBattler = gBattlerTarget;
            battlerId = gBattlerAttacker;
            instr = BattleScript_FaintTarget;
        }
        if (!(gAbsentBattlerFlags & gBitTable[gActiveBattler])
         && gBattleMons[gActiveBattler].hp == 0)
        {
            gHitMarker |= HITMARKER_FAINTED(gActiveBattler);
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = instr;
            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            {
                gHitMarker |= HITMARKER_PLAYER_FAINTED;
                if (gBattleResults.playerFaintCounter < 255)
                    gBattleResults.playerFaintCounter++;
                AdjustFriendshipOnBattleFaint(gActiveBattler);
                gSideTimers[B_SIDE_PLAYER].retaliateTimer = 2;
            }
            else
            {
                if (gBattleResults.opponentFaintCounter < 255)
                    gBattleResults.opponentFaintCounter++;
                gBattleResults.lastOpponentSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES, NULL);
                gSideTimers[B_SIDE_OPPONENT].retaliateTimer = 2;
            }
            if ((gHitMarker & HITMARKER_DESTINYBOND) && gBattleMons[gBattlerAttacker].hp != 0)
            {
                gHitMarker &= ~HITMARKER_DESTINYBOND;
                BattleScriptPush(gBattlescriptCurrInstr);
                gBattleMoveDamage = gBattleMons[battlerId].hp;
                gBattlescriptCurrInstr = BattleScript_DestinyBondTakesLife;
            }
            if ((gStatuses3[gBattlerTarget] & STATUS3_GRUDGE)
             && !(gHitMarker & HITMARKER_GRUDGE)
             && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget)
             && gBattleMons[gBattlerAttacker].hp != 0
             && gCurrentMove != MOVE_STRUGGLE)
            {
                u8 moveIndex = *(gBattleStruct->chosenMovePositions + gBattlerAttacker);

                gBattleMons[gBattlerAttacker].pp[moveIndex] = 0;
                BattleScriptPush(gBattlescriptCurrInstr);
                gBattlescriptCurrInstr = BattleScript_GrudgeTakesPp;
                gActiveBattler = gBattlerAttacker;
                BtlController_EmitSetMonData(BUFFER_A, moveIndex + REQUEST_PPMOVE1_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].pp[moveIndex]), &gBattleMons[gActiveBattler].pp[moveIndex]);
                MarkBattlerForControllerExec(gActiveBattler);

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
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);
        BtlController_EmitFaintAnimation(BUFFER_A);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_cleareffectsonfaint(void)
{
    CMD_ARGS(u8 battler);

    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);

        if (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || gBattleMons[gActiveBattler].hp == 0)
        {
            gBattleMons[gActiveBattler].status1 = 0;
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
            MarkBattlerForControllerExec(gActiveBattler);
        }

        FaintClearSetData(); // Effects like attractions, trapping, etc.
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifstatus(void)
{
    CMD_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);

    u8 battlerId = GetBattlerForBattleScript(cmd->battler);
    u32 flags = cmd->flags;
    const u8 *jumpInstr = cmd->jumpInstr;

    if (gBattleMons[battlerId].status1 & flags && gBattleMons[battlerId].hp != 0)
        gBattlescriptCurrInstr = jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifstatus2(void)
{
    CMD_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);

    u8 battlerId = GetBattlerForBattleScript(cmd->battler);
    u32 flags = cmd->flags;
    const u8 *jumpInstr = cmd->jumpInstr;

    if (gBattleMons[battlerId].status2 & flags && gBattleMons[battlerId].hp != 0)
        gBattlescriptCurrInstr = jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifability(void)
{
    CMD_ARGS(u8 battler, u16 ability, const u8 *jumpInstr);

    u32 battlerId;
    bool32 hasAbility = FALSE;
    u32 ability = cmd->ability;

    switch (cmd->battler)
    {
    default:
        battlerId = GetBattlerForBattleScript(cmd->battler);
        if (GetBattlerAbility(battlerId) == ability)
            hasAbility = TRUE;
        break;
    case BS_ATTACKER_SIDE:
        battlerId = IsAbilityOnSide(gBattlerAttacker, ability);
        if (battlerId)
        {
            battlerId--;
            hasAbility = TRUE;
        }
        break;
    case BS_TARGET_SIDE:
        battlerId = IsAbilityOnOpposingSide(gBattlerAttacker, ability);
        if (battlerId)
        {
            battlerId--;
            hasAbility = TRUE;
        }
        break;
    }

    if (hasAbility)
    {
        gLastUsedAbility = ability;
        gBattlescriptCurrInstr = cmd->jumpInstr;
        RecordAbilityBattle(battlerId, gLastUsedAbility);
        gBattlerAbility = battlerId;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifsideaffecting(void)
{
    CMD_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);

    u8 side;
    u32 flags;
    const u8 *jumpInstr;

    if (cmd->battler == BS_ATTACKER)
        side = GET_BATTLER_SIDE(gBattlerAttacker);
    else
        side = GET_BATTLER_SIDE(gBattlerTarget);

    flags = cmd->flags;
    jumpInstr = cmd->jumpInstr;

    if (gSideStatuses[side] & flags)
        gBattlescriptCurrInstr = jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifstat(void)
{
    CMD_ARGS(u8 battler, u8 comparison, u8 stat, u8 value, const u8 *jumpInstr);

    bool32 ret = 0;
    u8 battlerId = GetBattlerForBattleScript(cmd->battler);
    u8 stat = cmd->stat;
    u8 value = cmd->value;
    u8 comparison = cmd->comparison;

    ret = CompareStat(battlerId, stat, value, comparison);

    if (ret)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifstatus3condition(void)
{
    CMD_ARGS(u8 battler, u32 flags, bool8 jumpIfTrue, const u8 *jumpInstr);

    u32 flags;
    const u8 *jumpInstr;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    flags = cmd->flags;
    jumpInstr = cmd->jumpInstr;

    if (cmd->jumpIfTrue)
    {
        if ((gStatuses3[gActiveBattler] & flags) != 0)
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = jumpInstr;
    }
    else
    {
        if ((gStatuses3[gActiveBattler] & flags) != 0)
            gBattlescriptCurrInstr = jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpbasedontype(void)
{
    CMD_ARGS(u8 battler, u8 type, u8 jumpIfType, const u8 *jumpInstr);

    u8 battlerId = GetBattlerForBattleScript(cmd->battler);
    u8 type = cmd->type;
    const u8 *jumpInstr = cmd->jumpInstr;

    // jumpiftype
    if (cmd->jumpIfType)
    {
        if (IS_BATTLER_OF_TYPE(battlerId, type))
            gBattlescriptCurrInstr = jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
    // jumpifnottype
    else
    {
        if (!IS_BATTLER_OF_TYPE(battlerId, type))
            gBattlescriptCurrInstr = jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_getexp(void)
{
    CMD_ARGS(u8 battler);

    u16 item;
    s32 i; // also used as stringId
    u8 holdEffect;
    s32 sentIn;
    s32 viaExpShare = 0;
    u32 *exp = &gBattleStruct->expValue;

    gBattlerFainted = GetBattlerForBattleScript(cmd->battler);
    sentIn = gSentPokesToOpponent[(gBattlerFainted & 2) >> 1];

    switch (gBattleScripting.getexpState)
    {
    case 0: // check if should receive exp at all
        if (GetBattlerSide(gBattlerFainted) != B_SIDE_OPPONENT || (gBattleTypeFlags &
             (BATTLE_TYPE_LINK
              | BATTLE_TYPE_RECORDED_LINK
              | BATTLE_TYPE_TRAINER_HILL
              | BATTLE_TYPE_FRONTIER
              | BATTLE_TYPE_SAFARI
              | BATTLE_TYPE_BATTLE_TOWER
              | BATTLE_TYPE_EREADER_TRAINER)))
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
            u32 calculatedExp;
            s32 viaSentIn;

            for (viaSentIn = 0, i = 0; i < PARTY_SIZE; i++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE || GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
                    continue;
                if (GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
                    continue;
                if (gBitTable[i] & sentIn)
                    viaSentIn++;

                item = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);

                if (item == ITEM_ENIGMA_BERRY_E_READER)
                    holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
                else
                    holdEffect = ItemId_GetHoldEffect(item);

                if (holdEffect == HOLD_EFFECT_EXP_SHARE)
                    viaExpShare++;
            }
            #if (B_SCALED_EXP >= GEN_5) && (B_SCALED_EXP != GEN_6)
                calculatedExp = gSpeciesInfo[gBattleMons[gBattlerFainted].species].expYield * gBattleMons[gBattlerFainted].level / 5;
            #else
                calculatedExp = gSpeciesInfo[gBattleMons[gBattlerFainted].species].expYield * gBattleMons[gBattlerFainted].level / 7;
            #endif

            #if B_SPLIT_EXP < GEN_6
                if (viaExpShare) // at least one mon is getting exp via exp share
                {
                    *exp = SAFE_DIV(calculatedExp / 2, viaSentIn);
                    if (*exp == 0)
                        *exp = 1;

                    gExpShareExp = calculatedExp / 2 / viaExpShare;
                    if (gExpShareExp == 0)
                        gExpShareExp = 1;
                }
                else
                {
                    *exp = SAFE_DIV(calculatedExp, viaSentIn);
                    if (*exp == 0)
                        *exp = 1;
                    gExpShareExp = 0;
                }
            #else
                *exp = calculatedExp;
                gExpShareExp = calculatedExp / 2;
                if (gExpShareExp == 0)
                    gExpShareExp = 1;
            #endif

            gBattleScripting.getexpState++;
            gBattleStruct->expGetterMonId = 0;
            gBattleStruct->sentInPokes = sentIn;
        }
        // fall through
    case 2: // set exp value to the poke in expgetter_id and print message
        if (gBattleControllerExecFlags == 0)
        {
            item = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_HELD_ITEM);

            if (item == ITEM_ENIGMA_BERRY_E_READER)
                holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
            else
                holdEffect = ItemId_GetHoldEffect(item);

            if (holdEffect != HOLD_EFFECT_EXP_SHARE && !(gBattleStruct->sentInPokes & 1))
            {
                *(&gBattleStruct->sentInPokes) >>= 1;
                gBattleScripting.getexpState = 5;
                gBattleMoveDamage = 0; // used for exp
            }
            else if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gBattleStruct->expGetterMonId >= 3)
                  || GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_LEVEL) == MAX_LEVEL)
            {
                *(&gBattleStruct->sentInPokes) >>= 1;
                gBattleScripting.getexpState = 5;
                gBattleMoveDamage = 0; // used for exp
            #if B_MAX_LEVEL_EV_GAINS >= GEN_5
                MonGainEVs(&gPlayerParty[gBattleStruct->expGetterMonId], gBattleMons[gBattlerFainted].species);
            #endif
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

                if (GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_HP)
                    && !GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_IS_EGG))
                {
                    if (gBattleStruct->sentInPokes & 1)
                        gBattleMoveDamage = *exp;
                    else
                        gBattleMoveDamage = 0;

                    // only give exp share bonus in later gens if the mon wasn't sent out
                #if B_SPLIT_EXP < GEN_6
                    if (holdEffect == HOLD_EFFECT_EXP_SHARE)
                        gBattleMoveDamage += gExpShareExp;
                #else
                    if (holdEffect == HOLD_EFFECT_EXP_SHARE && gBattleMoveDamage == 0)
                        gBattleMoveDamage += gExpShareExp;
                #endif
                    if (holdEffect == HOLD_EFFECT_LUCKY_EGG)
                        gBattleMoveDamage = (gBattleMoveDamage * 150) / 100;
                #if B_TRAINER_EXP_MULTIPLIER <= GEN_7
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        gBattleMoveDamage = (gBattleMoveDamage * 150) / 100;
                #endif
                #if (B_SCALED_EXP >= GEN_5) && (B_SCALED_EXP != GEN_6)
                    {
                        // Note: There is an edge case where if a pokemon receives a large amount of exp, it wouldn't be properly calculated
                        //       because of multiplying by scaling factor(the value would simply be larger than an u32 can hold). Hence u64 is needed.
                        u64 value = gBattleMoveDamage;
                        value *= sExperienceScalingFactors[(gBattleMons[gBattlerFainted].level * 2) + 10];
                        value /= sExperienceScalingFactors[gBattleMons[gBattlerFainted].level + GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_LEVEL) + 10];
                        gBattleMoveDamage = value + 1;
                    }
                #endif
                #if B_AFFECTION_MECHANICS == TRUE
                    if (GetBattlerFriendshipScore(gBattleStruct->expGetterMonId) >= FRIENDSHIP_50_TO_99)
                        gBattleMoveDamage = (gBattleMoveDamage * 120) / 100;
                #endif

                    if (IsTradedMon(&gPlayerParty[gBattleStruct->expGetterMonId]))
                    {
                        // check if the pokemon doesn't belong to the player
                        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gBattleStruct->expGetterMonId >= 3)
                        {
                            i = STRINGID_EMPTYSTRING4;
                        }
                        else
                        {
                            gBattleMoveDamage = (gBattleMoveDamage * 150) / 100;
                            i = STRINGID_ABOOSTED;
                        }
                    }
                    else
                    {
                        i = STRINGID_EMPTYSTRING4;
                    }

                    // get exp getter battlerId
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                    {
                        if (gBattlerPartyIndexes[2] == gBattleStruct->expGetterMonId && !(gAbsentBattlerFlags & gBitTable[2]))
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

                    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gBattleStruct->expGetterBattlerId, gBattleStruct->expGetterMonId);
                    // buffer 'gained' or 'gained a boosted'
                    PREPARE_STRING_BUFFER(gBattleTextBuff2, i);
                    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff3, 6, gBattleMoveDamage);

                    PrepareStringBattle(STRINGID_PKMNGAINEDEXP, gBattleStruct->expGetterBattlerId);
                    MonGainEVs(&gPlayerParty[gBattleStruct->expGetterMonId], gBattleMons[gBattlerFainted].species);
                }
                gBattleStruct->sentInPokes >>= 1;
                gBattleScripting.getexpState++;
            }
        }
        break;
    case 3: // Set stats and give exp
        if (gBattleControllerExecFlags == 0)
        {
            gBattleResources->bufferB[gBattleStruct->expGetterBattlerId][0] = 0;
            if (GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_HP) && GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_LEVEL) != MAX_LEVEL)
            {
                gBattleResources->beforeLvlUp->stats[STAT_HP]    = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_MAX_HP);
                gBattleResources->beforeLvlUp->stats[STAT_ATK]   = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_ATK);
                gBattleResources->beforeLvlUp->stats[STAT_DEF]   = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_DEF);
                gBattleResources->beforeLvlUp->stats[STAT_SPEED] = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_SPEED);
                gBattleResources->beforeLvlUp->stats[STAT_SPATK] = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_SPATK);
                gBattleResources->beforeLvlUp->stats[STAT_SPDEF] = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_SPDEF);

                gActiveBattler = gBattleStruct->expGetterBattlerId;
                BtlController_EmitExpUpdate(BUFFER_A, gBattleStruct->expGetterMonId, gBattleMoveDamage);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            gBattleScripting.getexpState++;
        }
        break;
    case 4: // lvl up if necessary
        if (gBattleControllerExecFlags == 0)
        {
            gActiveBattler = gBattleStruct->expGetterBattlerId;
            if (gBattleResources->bufferB[gActiveBattler][0] == CONTROLLER_TWORETURNVALUES && gBattleResources->bufferB[gActiveBattler][1] == RET_VALUE_LEVELED_UP)
            {
                u16 temp, battlerId = 0xFF;
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && gBattlerPartyIndexes[gActiveBattler] == gBattleStruct->expGetterMonId)
                    HandleLowHpMusicChange(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);

                PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gActiveBattler, gBattleStruct->expGetterMonId);
                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 3, GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_LEVEL));

                BattleScriptPushCursor();
                gLeveledUpInBattle |= gBitTable[gBattleStruct->expGetterMonId];
                gBattlescriptCurrInstr = BattleScript_LevelUp;
                gBattleMoveDamage = T1_READ_32(&gBattleResources->bufferB[gActiveBattler][2]);
                AdjustFriendship(&gPlayerParty[gBattleStruct->expGetterMonId], FRIENDSHIP_EVENT_GROW_LEVEL);

                // update battle mon structure after level up
                if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterMonId && gBattleMons[0].hp)
                    battlerId = 0;
                else if (gBattlerPartyIndexes[2] == gBattleStruct->expGetterMonId && gBattleMons[2].hp && (gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                    battlerId = 2;

                if (battlerId != 0xFF)
                {
                    CopyMonLevelAndBaseStatsToBattleMon(battlerId, &gPlayerParty[gBattleStruct->expGetterMonId]);
                    if (gStatuses3[battlerId] & STATUS3_POWER_TRICK)
                        SWAP(gBattleMons[battlerId].attack, gBattleMons[battlerId].defense, temp);
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
            gBattleStruct->expGetterMonId++;
            if (gBattleStruct->expGetterMonId < PARTY_SIZE)
                gBattleScripting.getexpState = 2; // loop again
            else
                gBattleScripting.getexpState = 6; // we're done
        }
        break;
    case 6: // increment instruction
        if (gBattleControllerExecFlags == 0)
        {
            // not sure why gf clears the item and ability here
            gBattleMons[gBattlerFainted].item = ITEM_NONE;
            gBattleMons[gBattlerFainted].ability = ABILITY_NONE;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        break;
    }
}

#if B_MULTI_BATTLE_WHITEOUT >= GEN_4
static bool32 NoAliveMonsForPlayerAndPartner(void)
{
    u32 i;
    u32 HP_count = 0;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && (gPartnerTrainerId == TRAINER_STEVEN_PARTNER || gPartnerTrainerId >= TRAINER_CUSTOM_PARTNER))
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG)
             && (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || !(gBattleStruct->arenaLostPlayerMons & gBitTable[i])))
            {
                HP_count += GetMonData(&gPlayerParty[i], MON_DATA_HP);
            }
        }
    }

    return (HP_count == 0);
}
#endif

static bool32 NoAliveMonsForPlayer(void)
{
    u32 i;
    u32 HP_count = 0;

    // Get total HP for the player's party to determine if the player has lost
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && (gPartnerTrainerId == TRAINER_STEVEN_PARTNER || gPartnerTrainerId >= TRAINER_CUSTOM_PARTNER))
    {
        // In multi battle with Steven, skip his Pokémon
        for (i = 0; i < MULTI_PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
                HP_count += GetMonData(&gPlayerParty[i], MON_DATA_HP);
        }
    }
    else
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG)
             && (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || !(gBattleStruct->arenaLostPlayerMons & gBitTable[i])))
            {
                HP_count += GetMonData(&gPlayerParty[i], MON_DATA_HP);
            }
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

// For battles that aren't BATTLE_TYPE_LINK or BATTLE_TYPE_RECORDED_LINK, the only thing this
// command does is check whether the player has won/lost by totaling each team's HP. It then
// sets gBattleOutcome accordingly, if necessary.
static void Cmd_checkteamslost(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    if (gBattleControllerExecFlags)
        return;

#if B_MULTI_BATTLE_WHITEOUT >= GEN_4
    if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
    {
        if (NoAliveMonsForPlayerAndPartner())
            gBattleOutcome |= B_OUTCOME_LOST;
    }
    else
    {
        if (NoAliveMonsForPlayer())
            gBattleOutcome |= B_OUTCOME_LOST;
    }
#else
    if (NoAliveMonsForPlayer())
        gBattleOutcome |= B_OUTCOME_LOST;
#endif
    if (NoAliveMonsForOpponent())
        gBattleOutcome |= B_OUTCOME_WON;

    // For link battles that haven't ended, count number of empty battler spots
    // In link multi battles, jump to pointer if more than 1 spot empty
    // In non-multi battles, jump to pointer if 1 spot is missing on both sides
    if (gBattleOutcome == 0 && (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
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

    if (cmd->battler == BS_TARGET)
        gActiveBattler = gBattlerTarget;
    else
        gActiveBattler = gBattlerAttacker;

    BtlController_EmitHealthBarUpdate(BUFFER_A, gBattleMoveDamage);
    MarkBattlerForControllerExec(gActiveBattler);
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
    gActiveBattler = 0;
    gCurrentActionFuncId = B_ACTION_TRY_FINISH;
}

static void Cmd_end2(void)
{
    CMD_ARGS();

    gActiveBattler = 0;
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

    // Pure flying type.
    if (gBattleMons[gBattlerAttacker].type1 == TYPE_FLYING && gBattleMons[gBattlerAttacker].type2 == TYPE_FLYING)
    {
        gBattleStruct->roostTypes[gBattlerAttacker][0] = TYPE_FLYING;
        gBattleStruct->roostTypes[gBattlerAttacker][1] = TYPE_FLYING;
#if B_ROOST_PURE_FLYING >= GEN_5
        SET_BATTLER_TYPE(gBattlerAttacker, TYPE_NORMAL);
#else
        SET_BATTLER_TYPE(gBattlerAttacker, TYPE_MYSTERY);
#endif
    }
    // Dual type with flying type.
    else if (gBattleMons[gBattlerAttacker].type1 == TYPE_FLYING || gBattleMons[gBattlerAttacker].type2 == TYPE_FLYING)
    {
        gBattleStruct->roostTypes[gBattlerAttacker][0] = gBattleMons[gBattlerAttacker].type1;
        gBattleStruct->roostTypes[gBattlerAttacker][1] = gBattleMons[gBattlerAttacker].type2;
        if (gBattleMons[gBattlerAttacker].type1 == TYPE_FLYING)
            gBattleMons[gBattlerAttacker].type1 = TYPE_MYSTERY;
        else if (gBattleMons[gBattlerAttacker].type2 == TYPE_FLYING)
            gBattleMons[gBattlerAttacker].type2 = TYPE_MYSTERY;
    }
    // Non-flying type.
    else
    {
        gBattleStruct->roostTypes[gBattlerAttacker][0] = gBattleMons[gBattlerAttacker].type1;
        gBattleStruct->roostTypes[gBattlerAttacker][1] = gBattleMons[gBattlerAttacker].type2;
    }

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

static void Cmd_playanimation(void)
{
    CMD_ARGS(u8 battler, u8 animId, const u16 *argPtr);

    const u16 *argPtr;
    u8 animId = cmd->animId;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    argPtr = cmd->argPtr;

#if B_TERRAIN_BG_CHANGE == FALSE
    if (animId == B_ANIM_RESTORE_BG)
    {
        // workaround for .if not working
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
#endif

    if (animId == B_ANIM_STATS_CHANGE
     || animId == B_ANIM_SNATCH_MOVE
     || animId == B_ANIM_MEGA_EVOLUTION
     || animId == B_ANIM_ILLUSION_OFF
     || animId == B_ANIM_FORM_CHANGE
     || animId == B_ANIM_SUBSTITUTE_FADE
     || animId == B_ANIM_PRIMAL_REVERSION)
    {
        BtlController_EmitBattleAnimation(BUFFER_A, animId, *argPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (gHitMarker & HITMARKER_NO_ANIMATIONS && animId != B_ANIM_RESTORE_BG)
    {
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_Pausex20;
    }
    else if (animId == B_ANIM_RAIN_CONTINUES
          || animId == B_ANIM_SUN_CONTINUES
          || animId == B_ANIM_SANDSTORM_CONTINUES
          || animId == B_ANIM_HAIL_CONTINUES
          || animId == B_ANIM_SNOW_CONTINUES)
    {
        BtlController_EmitBattleAnimation(BUFFER_A, animId, *argPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        BtlController_EmitBattleAnimation(BUFFER_A, animId, *argPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

// Same as playanimation, except it takes a pointer to some animation id, instead of taking the value directly
static void Cmd_playanimation_var(void)
{
    CMD_ARGS(u8 battler, const u8 *animIdPtr, const u16 *argPtr);

    const u16 *argPtr;
    const u8 *animIdPtr;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    animIdPtr = cmd->animIdPtr;
    argPtr = cmd->argPtr;

    if (*animIdPtr == B_ANIM_STATS_CHANGE
     || *animIdPtr == B_ANIM_SNATCH_MOVE
     || *animIdPtr == B_ANIM_MEGA_EVOLUTION
     || *animIdPtr == B_ANIM_ILLUSION_OFF
     || *animIdPtr == B_ANIM_FORM_CHANGE
     || *animIdPtr == B_ANIM_SUBSTITUTE_FADE
     || *animIdPtr == B_ANIM_PRIMAL_REVERSION)
    {
        BtlController_EmitBattleAnimation(BUFFER_A, *animIdPtr, *argPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (gHitMarker & HITMARKER_NO_ANIMATIONS)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (*animIdPtr == B_ANIM_RAIN_CONTINUES
          || *animIdPtr == B_ANIM_SUN_CONTINUES
          || *animIdPtr == B_ANIM_SANDSTORM_CONTINUES
          || *animIdPtr == B_ANIM_HAIL_CONTINUES
          || *animIdPtr == B_ANIM_SNOW_CONTINUES)
    {
        BtlController_EmitBattleAnimation(BUFFER_A, *animIdPtr, *argPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        BtlController_EmitBattleAnimation(BUFFER_A, *animIdPtr, *argPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setgraphicalstatchangevalues(void)
{
    CMD_ARGS();

    u8 value = GET_STAT_BUFF_VALUE_WITH_SIGN(gBattleScripting.statChanger);

    switch (value)
    {
    case SET_STAT_BUFF_VALUE(1): // +1
        value = STAT_ANIM_PLUS1;
        break;
    case SET_STAT_BUFF_VALUE(2): // +2
        value = STAT_ANIM_PLUS2;
        break;
    case SET_STAT_BUFF_VALUE(3): // +3
        value = STAT_ANIM_PLUS2;
        break;
    case SET_STAT_BUFF_VALUE(1) | STAT_BUFF_NEGATIVE: // -1
        value = STAT_ANIM_MINUS1;
        break;
    case SET_STAT_BUFF_VALUE(2) | STAT_BUFF_NEGATIVE: // -2
        value = STAT_ANIM_MINUS2;
        break;
    case SET_STAT_BUFF_VALUE(3) | STAT_BUFF_NEGATIVE: // -3
        value = STAT_ANIM_MINUS2;
        break;
    default: // <-12,-4> and <4, 12>
        if (value & STAT_BUFF_NEGATIVE)
            value = STAT_ANIM_MINUS2;
        else
            value = STAT_ANIM_PLUS2;
        break;
    }
    gBattleScripting.animArg1 = GET_STAT_BUFF_ID(gBattleScripting.statChanger) + value - 1;
    gBattleScripting.animArg2 = 0;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_playstatchangeanimation(void)
{
    CMD_ARGS(u8 battler, u8 stats, u8 flags);

    u32 ability;
    u32 currStat = 0;
    u32 statAnimId = 0;
    u32 changeableStatsCount = 0;
    u32 stats = 0;
    u32 startingStatAnimId = 0;
    u32 flags = cmd->flags;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    ability = GetBattlerAbility(gActiveBattler);
    stats = cmd->stats;

    // Handle Contrary and Simple
    if (ability == ABILITY_CONTRARY)
        flags ^= STAT_CHANGE_NEGATIVE;
    else if (ability == ABILITY_SIMPLE)
        flags |= STAT_CHANGE_BY_TWO;

    if (flags & STAT_CHANGE_NEGATIVE) // goes down
    {
        if (flags & STAT_CHANGE_BY_TWO)
            startingStatAnimId = STAT_ANIM_MINUS2 - 1;
        else
            startingStatAnimId = STAT_ANIM_MINUS1 - 1;

        while (stats != 0)
        {
            if (stats & 1)
            {
                if (flags & STAT_CHANGE_CANT_PREVENT)
                {
                    if (gBattleMons[gActiveBattler].statStages[currStat] > MIN_STAT_STAGE)
                    {
                        statAnimId = startingStatAnimId + currStat;
                        changeableStatsCount++;
                    }
                }
                else if (!gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].mistTimer
                        && GetBattlerHoldEffect(gActiveBattler, TRUE) != HOLD_EFFECT_CLEAR_AMULET
                        && ability != ABILITY_CLEAR_BODY
                        && ability != ABILITY_FULL_METAL_BODY
                        && ability != ABILITY_WHITE_SMOKE
                        && !(ability == ABILITY_KEEN_EYE && currStat == STAT_ACC)
                        && !(ability == ABILITY_HYPER_CUTTER && currStat == STAT_ATK)
                        && !(ability == ABILITY_BIG_PECKS && currStat == STAT_DEF))
                {
                    if (gBattleMons[gActiveBattler].statStages[currStat] > MIN_STAT_STAGE)
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
            startingStatAnimId = STAT_ANIM_PLUS2 - 1;
        else
            startingStatAnimId = STAT_ANIM_PLUS1 - 1;

        while (stats != 0)
        {
            if (stats & 1 && gBattleMons[gActiveBattler].statStages[currStat] < MAX_STAT_STAGE)
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
        BtlController_EmitBattleAnimation(BUFFER_A, B_ANIM_STATS_CHANGE, statAnimId);
        MarkBattlerForControllerExec(gActiveBattler);
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
            gWishFutureKnock.knockedOffMons[side] |= gBitTable[gBattlerPartyIndexes[battlerDef]];
            CheckSetUnburden(battlerDef);

            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_KnockedOff;
        }
        return TRUE;
    }
    return FALSE;
}

#define SYMBIOSIS_CHECK(battler, ally)                                                                                               \
    GetBattlerAbility(ally) == ABILITY_SYMBIOSIS                   \
    && gBattleMons[battler].item == ITEM_NONE                      \
    && gBattleMons[ally].item != ITEM_NONE                         \
    && CanBattlerGetOrLoseItem(battler, gBattleMons[ally].item)    \
    && CanBattlerGetOrLoseItem(ally, gBattleMons[ally].item)       \
    && gBattleMons[battler].hp != 0                                \
    && gBattleMons[ally].hp != 0

static u32 GetNextTarget(u32 moveTarget)
{
    u32 i;
    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (i != gBattlerAttacker
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
    u16 *choicedMoveAtk = NULL;
    u32 endMode, endState;
    u32 originallyUsedMove;

    if (gChosenMove == MOVE_UNAVAILABLE)
        originallyUsedMove = MOVE_NONE;
    else
        originallyUsedMove = gChosenMove;

    endMode = cmd->endMode;
    endState = cmd->endState;

    holdEffectAtk = GetBattlerHoldEffect(gBattlerAttacker, TRUE);
    choicedMoveAtk = &gBattleStruct->choicedMove[gBattlerAttacker];
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
                if (gProtectStructs[gBattlerTarget].spikyShielded && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
                    gProtectStructs[gBattlerAttacker].touchedProtectLike = FALSE;
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 8;
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
                #if B_KINGS_SHIELD_LOWER_ATK >= GEN_8
                    gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_1;
                #else
                    gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_2;
                #endif
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
                else if (gProtectStructs[gBattlerTarget].obstructed && gCurrentMove != MOVE_SUCKER_PUNCH)
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
                // Not strictly a protect effect, but works the same way
                else if (gProtectStructs[gBattlerTarget].beakBlastCharge
                         && CanBeBurned(gBattlerAttacker)
                         && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
                {
                    gProtectStructs[gBattlerAttacker].touchedProtectLike = FALSE;
                    gBattleMons[gBattlerAttacker].status1 = STATUS1_BURN;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BeakBlastBurn;
                    effect = 1;
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_RAGE: // rage check
            if (gBattleMons[gBattlerTarget].status2 & STATUS2_RAGE
                && gBattleMons[gBattlerTarget].hp != 0
                && gBattlerAttacker != gBattlerTarget
                && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget)
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                && TARGET_TURN_DAMAGED
                && gBattleMoves[gCurrentMove].power != 0
                && CompareStat(gBattlerTarget, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
            {
                gBattleMons[gBattlerTarget].statStages[STAT_ATK]++;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_RageIsBuilding;
                effect = TRUE;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_DEFROST: // defrosting check
            if (gBattleMons[gBattlerTarget].status1 & STATUS1_FREEZE
                && gBattleMons[gBattlerTarget].hp != 0
                && gBattlerAttacker != gBattlerTarget
                && (moveType == TYPE_FIRE
            #if B_BURN_HIT_THAW >= GEN_6
                    || gBattleMoves[gCurrentMove].effect == EFFECT_BURN_HIT
            #endif
                )
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
            {
                gBattleMons[gBattlerTarget].status1 &= ~STATUS1_FREEZE;
                gActiveBattler = gBattlerTarget;
                BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].status1), &gBattleMons[gBattlerTarget].status1);
                MarkBattlerForControllerExec(gActiveBattler);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_DefrostedViaFireMove;
                effect = TRUE;
            }
            if (gBattleMons[gBattlerTarget].status1 & STATUS1_FROSTBITE
                && gBattleMons[gBattlerTarget].hp != 0
                && gBattlerAttacker != gBattlerTarget
                && gBattleMoves[originallyUsedMove].flags & FLAG_THAW_USER
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
            {
                gBattleMons[gBattlerTarget].status1 &= ~STATUS1_FROSTBITE;
                gActiveBattler = gBattlerTarget;
                BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].status1), &gBattleMons[gBattlerTarget].status1);
                MarkBattlerForControllerExec(gActiveBattler);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_FrostbiteHealedViaFireMove;
                effect = TRUE;
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_RECOIL:
            if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                && !(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE)
                && IsBattlerAlive(gBattlerAttacker)
                && gBattleScripting.savedDmg != 0) // Some checks may be redundant alongside this one
            {
                switch (gBattleMoves[gCurrentMove].effect)
                {
                case EFFECT_RECOIL_25: // Take Down, 25% recoil
                    gBattleMoveDamage = max(1, gBattleScripting.savedDmg / 4);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveEffectRecoil;
                    effect = TRUE;
                    break;
                case EFFECT_RECOIL_33: // Double Edge, 33 % recoil
                    gBattleMoveDamage = max(1, gBattleScripting.savedDmg / 3);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveEffectRecoil;
                    effect = TRUE;
                    break;
                case EFFECT_RECOIL_50: // Head Smash, 50 % recoil
                    gBattleMoveDamage = max(1, gBattleScripting.savedDmg / 2);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveEffectRecoil;
                    effect = TRUE;
                    break;
                case EFFECT_RECOIL_33_STATUS: // Flare Blitz - can burn, Volt Tackle - can paralyze
                    gBattleMoveDamage = max(1, gBattleScripting.savedDmg / 3);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveEffectRecoilWithStatus;
                    effect = TRUE;
                    break;
                }
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
            if (gHitMarker & HITMARKER_OBEYS
             && (HOLD_EFFECT_CHOICE(holdEffectAtk) || GetBattlerAbility(gBattlerAttacker) == ABILITY_GORILLA_TACTICS)
             && gChosenMove != MOVE_STRUGGLE
             && (*choicedMoveAtk == MOVE_NONE || *choicedMoveAtk == MOVE_UNAVAILABLE))
            {
                if ((gBattleMoves[gChosenMove].effect == EFFECT_BATON_PASS
                 || gBattleMoves[gChosenMove].effect == EFFECT_HEALING_WISH)
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
                *choicedMoveAtk = MOVE_NONE;
            gBattleScripting.moveendState++;
            break;
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
                effect = TryKnockOffBattleScript(gBattlerTarget);
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
                if (!IsBattlerGrounded(gBattlerTarget) && IsBattlerAlive(gBattlerTarget))
                {
                    gStatuses3[gBattlerTarget] |= STATUS3_SMACKED_DOWN;
                    gStatuses3[gBattlerTarget] &= ~(STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS | STATUS3_ON_AIR);
                    effect = TRUE;
                    BattleScriptPush(gBattlescriptCurrInstr);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectSmackDown;
                }
                break;
            case MOVE_EFFECT_REMOVE_STATUS: // Smelling salts, Wake-Up Slap, Sparkling Aria
                if ((gBattleMons[gBattlerTarget].status1 & gBattleMoves[gCurrentMove].argument) && IsBattlerAlive(gBattlerTarget))
                {
                    gBattleMons[gBattlerTarget].status1 &= ~(gBattleMoves[gCurrentMove].argument);

                    gActiveBattler = gBattlerTarget;
                    BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                    MarkBattlerForControllerExec(gActiveBattler);
                    effect = TRUE;
                    BattleScriptPush(gBattlescriptCurrInstr);
                    switch (gBattleMoves[gCurrentMove].argument)
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
                && gHitMarker & HITMARKER_NO_ANIMATIONS)
            {
                gActiveBattler = gBattlerAttacker;
                BtlController_EmitSpriteInvisibility(BUFFER_A, TRUE);
                MarkBattlerForControllerExec(gActiveBattler);
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
                gActiveBattler = gBattlerAttacker;
                BtlController_EmitSpriteInvisibility(BUFFER_A, FALSE);
                MarkBattlerForControllerExec(gActiveBattler);
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
                gActiveBattler = gBattlerTarget;
                BtlController_EmitSpriteInvisibility(BUFFER_A, FALSE);
                MarkBattlerForControllerExec(gActiveBattler);
                gStatuses3[gBattlerTarget] &= ~STATUS3_SEMI_INVULNERABLE;
                gBattleScripting.moveendState++;
                return;
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
            if (gMoveResultFlags & (MOVE_RESULT_FAILED | MOVE_RESULT_DOESNT_AFFECT_FOE))
                gBattleStruct->lastMoveFailed |= gBitTable[gBattlerAttacker];
            else
                gBattleStruct->lastMoveFailed &= ~(gBitTable[gBattlerAttacker]);

            // Set ShellTrap to activate after the attacker's turn if target was hit by a physical move.
            if (gBattleMoves[gChosenMoveByBattler[gBattlerTarget]].effect == EFFECT_SHELL_TRAP
                && gBattlerTarget != gBattlerAttacker
                && GetBattlerSide(gBattlerTarget) != GetBattlerSide(gBattlerAttacker)
                && gProtectStructs[gBattlerTarget].physicalDmg
                && gProtectStructs[gBattlerTarget].physicalBattlerId == gBattlerAttacker
                && !TestSheerForceFlag(gBattlerAttacker, gCurrentMove))
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
                gActiveBattler = gBattlerAttacker;
                gBattlerAttacker = gBattlerTarget;
                gBattlerTarget = gActiveBattler;
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
                }
            }
            if (!(gAbsentBattlerFlags & gBitTable[gBattlerAttacker])
                && !(gBattleStruct->absentBattlerFlags & gBitTable[gBattlerAttacker])
                && gBattleMoves[originallyUsedMove].effect != EFFECT_BATON_PASS
                && gBattleMoves[originallyUsedMove].effect != EFFECT_HEALING_WISH)
            {
                if (gHitMarker & HITMARKER_OBEYS)
                {
                    if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
                    {
                        gLastMoves[gBattlerAttacker] = gChosenMove;
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
                && gBattleMoves[originallyUsedMove].flags & FLAG_MIRROR_MOVE_AFFECTED
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
                effect = TRUE;
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
                u32 nextTarget = GetNextTarget(moveTarget);
                gHitMarker |= HITMARKER_NO_PPDEDUCT;

                if (nextTarget != MAX_BATTLERS_COUNT)
                {
                    gBattleStruct->moveTarget[gBattlerAttacker] = gBattlerTarget = nextTarget; // Fix for moxie spread moves
                    gBattleScripting.moveendState = 0;
                    MoveValuesCleanUp();
                    gBattleScripting.moveEffect = gBattleScripting.savedMoveEffect;
                    BattleScriptPush(gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect]);
                    gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
                    return;
                }
                // Check if the move used was actually a bounced move. If so, we need to go back to the original attacker and make sure, its move hits all 2 or 3 pokemon.
                else if (gProtectStructs[gBattlerAttacker].usesBouncedMove)
                {
                    u8 originalBounceTarget = gBattlerAttacker;
                    gBattlerAttacker = gBattleStruct->attackerBeforeBounce;
                    gBattleStruct->targetsDone[gBattlerAttacker] |= gBitTable[originalBounceTarget];
                    gBattleStruct->targetsDone[originalBounceTarget] = 0;

                    nextTarget = GetNextTarget(moveTarget);
                    if (nextTarget != MAX_BATTLERS_COUNT)
                    {
                        // We found another target for the original move user.
                        gBattleStruct->moveTarget[gBattlerAttacker] = gBattlerTarget = nextTarget;
                        gBattleScripting.moveendState = 0;
                        gBattleScripting.animTurn = 0;
                        gBattleScripting.animTargetsHit = 0;
                        MoveValuesCleanUp();
                        BattleScriptPush(gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect]);
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
            && !(gCurrentMove == MOVE_PRESENT && gBattleStruct->presentBasePower == 0)) // Silly edge case
            {
                gBattleScripting.multihitString[4]++;
                if (--gMultiHitCounter == 0)
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MultiHitPrintStrings;
                    effect = TRUE;
                }
                else
                {
                    if (gCurrentMove == MOVE_DRAGON_DARTS)
                    {
                        // TODO
                    }

                    if (gBattleMons[gBattlerAttacker].hp
                    && gBattleMons[gBattlerTarget].hp
                    && (gChosenMove == MOVE_SLEEP_TALK || !(gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP))
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
                        BattleScriptPush(gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect]);
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
        case MOVEEND_EJECT_BUTTON:
            if (gBattleMoves[gCurrentMove].effect != EFFECT_HIT_SWITCH_TARGET
              && IsBattlerAlive(gBattlerAttacker)
              && !TestSheerForceFlag(gBattlerAttacker, gCurrentMove)
              && (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER || (gBattleTypeFlags & BATTLE_TYPE_TRAINER)))
            {
                // Since we check if battler was damaged, we don't need to check move result.
                // In fact, doing so actually prevents multi-target moves from activating eject button properly
                u8 battlers[4] = {0, 1, 2, 3};
                SortBattlersBySpeed(battlers, FALSE);
                for (i = 0; i < gBattlersCount; i++)
                {
                    u8 battler = battlers[i];
                    // Attacker is the damage-dealer, battler is mon to be switched out
                    if (IsBattlerAlive(battler)
                      && GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_EJECT_BUTTON
                      && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove)
                      && (gSpecialStatuses[battler].physicalDmg != 0 || gSpecialStatuses[battler].specialDmg != 0)
                      && CountUsablePartyMons(battler) > 0)  // Has mon to switch into
                    {
                        gActiveBattler = gBattleScripting.battler = battler;
                        gLastUsedItem = gBattleMons[battler].item;
                        if (gBattleMoves[gCurrentMove].effect == EFFECT_HIT_ESCAPE)
                            gBattlescriptCurrInstr = BattleScript_MoveEnd;  // Prevent user switch-in selection
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_EjectButtonActivates;
                        effect = TRUE;
                        break; // Only the fastest Eject Button activates
                    }
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_RED_CARD:
            if ((gBattleMoves[gCurrentMove].effect != EFFECT_HIT_SWITCH_TARGET || gBattleStruct->hitSwitchTargetFailed)
              && IsBattlerAlive(gBattlerAttacker)
              && !TestSheerForceFlag(gBattlerAttacker, gCurrentMove)
              && GetBattlerAbility(gBattlerAttacker) != ABILITY_GUARD_DOG)
            {
                // Since we check if battler was damaged, we don't need to check move result.
                // In fact, doing so actually prevents multi-target moves from activating red card properly
                u8 battlers[4] = {0, 1, 2, 3};
                SortBattlersBySpeed(battlers, FALSE);
                for (i = 0; i < gBattlersCount; i++)
                {
                    u8 battler = battlers[i];
                    // Search for fastest hit pokemon with a red card
                    // Attacker is the one to be switched out, battler is one with red card
                    if (battler != gBattlerAttacker
                      && IsBattlerAlive(battler)
                      && !DoesSubstituteBlockMove(gBattlerAttacker, battler, gCurrentMove)
                      && GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_RED_CARD
                      && (gSpecialStatuses[battler].physicalDmg != 0 || gSpecialStatuses[battler].specialDmg != 0)
                      && CanBattlerSwitch(gBattlerAttacker))
                    {
                        gLastUsedItem = gBattleMons[battler].item;
                        gActiveBattler = gBattleStruct->savedBattlerTarget = gBattleScripting.battler = battler;  // Battler with red card
                        gEffectBattler = gBattlerAttacker;
                        if (gBattleMoves[gCurrentMove].effect == EFFECT_HIT_ESCAPE)
                            gBattlescriptCurrInstr = BattleScript_MoveEnd;  // Prevent user switch-in selection
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_RedCardActivates;
                        effect = TRUE;
                        break;  // Only fastest red card activates
                    }
                }
            }
            gBattleScripting.moveendState++;
            break;
        case MOVEEND_EJECT_PACK:
            {
                u8 battlers[4] = {0, 1, 2, 3};
                SortBattlersBySpeed(battlers, FALSE);
                for (i = 0; i < gBattlersCount; i++)
                {
                    u8 battler = battlers[i];
                    if (IsBattlerAlive(battler)
                     && gProtectStructs[battler].statFell
                     && gProtectStructs[battler].disableEjectPack == 0
                     && GetBattlerHoldEffect(battler, TRUE) == HOLD_EFFECT_EJECT_PACK
                     && !(gCurrentMove == MOVE_PARTING_SHOT && CanBattlerSwitch(gBattlerAttacker))  // Does not activate if attacker used Parting Shot and can switch out
                     && CountUsablePartyMons(battler) > 0)  // Has mon to switch into
                    {
                        gProtectStructs[battler].statFell = FALSE;
                        gActiveBattler = gBattleScripting.battler = battler;
                        gLastUsedItem = gBattleMons[battler].item;
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_EjectPackActivates;
                        effect = TRUE;
                        break;  // Only fastest eject pack activates
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
              && !(TestSheerForceFlag(gBattlerAttacker, gCurrentMove))  // Pickpocket doesn't activate for sheer force
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
                      && BATTLER_DAMAGED(battler)                                                       // Target needs to have been damaged
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
            if (gBattleMoves[gCurrentMove].flags & FLAG_DANCE)
            {
                u8 battler, nextDancer = 0;

                if (!(gBattleStruct->lastMoveFailed & gBitTable[gBattlerAttacker]
                    || (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove
                        && gProtectStructs[gBattlerAttacker].usesBouncedMove)))
                {   // Dance move succeeds
                    // Set target for other Dancer mons; set bit so that mon cannot activate Dancer off of its own move
                    if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
                    {
                        gBattleScripting.savedBattler = gBattlerTarget | 0x4;
                        gBattleScripting.savedBattler |= (gBattlerAttacker << 4);
                        gSpecialStatuses[gBattlerAttacker].dancerUsedMove = TRUE;
                    }
                    for (battler = 0; battler < MAX_BATTLERS_COUNT; battler++)
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
                    #if B_ABILITY_POP_UP == TRUE
                        gBattlescriptCurrInstr = BattleScript_EmergencyExit;
                    #else
                        gBattlescriptCurrInstr = BattleScript_EmergencyExitNoPopUp;
                    #endif
                    }
                    else
                    {
                    #if B_ABILITY_POP_UP == TRUE
                        gBattlescriptCurrInstr = BattleScript_EmergencyExitWild;
                    #else
                        gBattlescriptCurrInstr = BattleScript_EmergencyExitWildNoPopUp;
                    #endif
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
                #if B_SYMBIOSIS_GEMS >= GEN_7
                    || gSpecialStatuses[i].gemBoost
                #endif
                    ) && SYMBIOSIS_CHECK(i, BATTLE_PARTNER(i)))
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
        case MOVEEND_CLEAR_BITS: // Clear/Set bits for things like using a move for all targets and all hits.
            if (gSpecialStatuses[gBattlerAttacker].instructedChosenTarget)
                *(gBattleStruct->moveTarget + gBattlerAttacker) = gSpecialStatuses[gBattlerAttacker].instructedChosenTarget & 0x3;
            if (gSpecialStatuses[gBattlerAttacker].dancerOriginalTarget)
                *(gBattleStruct->moveTarget + gBattlerAttacker) = gSpecialStatuses[gBattlerAttacker].dancerOriginalTarget & 0x3;

        #if B_RAMPAGE_CANCELLING >= GEN_5
            if (gBattleMoves[gCurrentMove].effect == EFFECT_RAMPAGE // If we're rampaging
              && (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)         // And it is unusable
              && (gBattleMons[gBattlerAttacker].status2 & STATUS2_LOCK_CONFUSE) != STATUS2_LOCK_CONFUSE_TURN(1))  // And won't end this turn
                CancelMultiTurnMoves(gBattlerAttacker); // Cancel it
        #endif

            gBattleStruct->targetsDone[gBattlerAttacker] = 0;
            gProtectStructs[gBattlerAttacker].usesBouncedMove = FALSE;
            gProtectStructs[gBattlerAttacker].targetAffected = FALSE;
            gProtectStructs[gBattlerAttacker].shellTrap = FALSE;
            gBattleStruct->ateBoost[gBattlerAttacker] = 0;
            gStatuses3[gBattlerAttacker] &= ~STATUS3_ME_FIRST;
            gSpecialStatuses[gBattlerAttacker].gemBoost = FALSE;
            gSpecialStatuses[gBattlerAttacker].damagedMons = 0;
            gSpecialStatuses[gBattlerTarget].berryReduced = FALSE;
            gBattleScripting.moveEffect = 0;
            // clear attacker z move data
            gBattleStruct->zmove.active = FALSE;
            gBattleStruct->zmove.toBeUsed[gBattlerAttacker] = MOVE_NONE;
            gBattleStruct->zmove.effect = EFFECT_HIT;
            gBattleStruct->hitSwitchTargetFailed = FALSE;
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

    gActiveBattler = gBattlerAttacker;
    if (!(gHitMarker & HITMARKER_FAINTED(gActiveBattler)))
    {
        BtlController_EmitReturnMonToBall(BUFFER_A, FALSE);
        MarkBattlerForControllerExec(gActiveBattler);
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_getswitchedmondata(void)
{
    CMD_ARGS(u8 battler);

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);

    gBattlerPartyIndexes[gActiveBattler] = *(gBattleStruct->monToSwitchIntoId + gActiveBattler);

    BtlController_EmitGetMonData(BUFFER_A, REQUEST_ALL_BATTLE, gBitTable[gBattlerPartyIndexes[gActiveBattler]]);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_switchindataupdate(void)
{
    CMD_ARGS(u8 battler);

    struct BattlePokemon oldData;
    s32 i;
    u8 *monData;

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    oldData = gBattleMons[gActiveBattler];
    monData = (u8 *)(&gBattleMons[gActiveBattler]);

    for (i = 0; i < sizeof(struct BattlePokemon); i++)
        monData[i] = gBattleResources->bufferB[gActiveBattler][4 + i];

    gBattleMons[gActiveBattler].type1 = gSpeciesInfo[gBattleMons[gActiveBattler].species].types[0];
    gBattleMons[gActiveBattler].type2 = gSpeciesInfo[gBattleMons[gActiveBattler].species].types[1];
    gBattleMons[gActiveBattler].type3 = TYPE_MYSTERY;
    gBattleMons[gActiveBattler].ability = GetAbilityBySpecies(gBattleMons[gActiveBattler].species, gBattleMons[gActiveBattler].abilityNum);

    // check knocked off item
    i = GetBattlerSide(gActiveBattler);
    if (gWishFutureKnock.knockedOffMons[i] & gBitTable[gBattlerPartyIndexes[gActiveBattler]])
    {
        gBattleMons[gActiveBattler].item = ITEM_NONE;
    }

    if (gBattleMoves[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        for (i = 0; i < NUM_BATTLE_STATS; i++)
        {
            gBattleMons[gActiveBattler].statStages[i] = oldData.statStages[i];
        }
        gBattleMons[gActiveBattler].status2 = oldData.status2;
    }

    SwitchInClearSetData();

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE
        && gBattleMons[gActiveBattler].maxHP / 2 >= gBattleMons[gActiveBattler].hp
        && gBattleMons[gActiveBattler].hp != 0
        && !(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP))
    {
        gBattleStruct->palaceFlags |= gBitTable[gActiveBattler];
    }

    gBattleScripting.battler = gActiveBattler;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gActiveBattler, gBattlerPartyIndexes[gActiveBattler]);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_switchinanim(void)
{
    CMD_ARGS(u8 battler, bool8 dontClearSubstitute);

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT
        && !(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                 | BATTLE_TYPE_EREADER_TRAINER
                                 | BATTLE_TYPE_RECORDED_LINK
                                 | BATTLE_TYPE_TRAINER_HILL
                                 | BATTLE_TYPE_FRONTIER)))
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBattler].species), FLAG_SET_SEEN, gBattleMons[gActiveBattler].personality);

    gAbsentBattlerFlags &= ~(gBitTable[gActiveBattler]);

    BtlController_EmitSwitchInAnim(BUFFER_A, gBattlerPartyIndexes[gActiveBattler], cmd->dontClearSubstitute);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        BattleArena_InitPoints();
}

bool32 CanBattlerSwitch(u32 battlerId)
{
    s32 i, lastMonId, battlerIn1, battlerIn2;
    bool32 ret = FALSE;
    struct Pokemon *party;

    if (BATTLE_TWO_VS_ONE_OPPONENT && GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
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
        party = GetBattlerParty(battlerId);

        lastMonId = 0;
        if (battlerId & 2)
            lastMonId = MULTI_PARTY_SIZE;

        for (i = lastMonId; i < lastMonId + MULTI_PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0
             && gBattlerPartyIndexes[battlerId] != i)
                break;
        }

        ret = (i != lastMonId + MULTI_PARTY_SIZE);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
        {
            if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
            {
                party = gPlayerParty;

                lastMonId = 0;
                if (GetLinkTrainerFlankId(GetBattlerMultiplayerId(battlerId)) == TRUE)
                    lastMonId = MULTI_PARTY_SIZE;
            }
            else
            {
                party = gEnemyParty;

                if (battlerId == 1)
                    lastMonId = 0;
                else
                    lastMonId = MULTI_PARTY_SIZE;
            }
        }
        else
        {
            party = GetBattlerParty(battlerId);

            lastMonId = 0;
            if (GetLinkTrainerFlankId(GetBattlerMultiplayerId(battlerId)) == TRUE)
                lastMonId = MULTI_PARTY_SIZE;
        }

        for (i = lastMonId; i < lastMonId + MULTI_PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0
             && gBattlerPartyIndexes[battlerId] != i)
                break;
        }

        ret = (i != lastMonId + MULTI_PARTY_SIZE);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
    {
        party = gEnemyParty;

        lastMonId = 0;
        if (battlerId == B_POSITION_OPPONENT_RIGHT)
            lastMonId = PARTY_SIZE / 2;

        for (i = lastMonId; i < lastMonId + (PARTY_SIZE / 2); i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0
             && gBattlerPartyIndexes[battlerId] != i)
                break;
        }

        ret = (i != lastMonId + (PARTY_SIZE / 2));
    }
    else
    {
        if (GetBattlerSide(battlerId) == B_SIDE_OPPONENT)
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

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);

    if (!cmd->ignoreEscapePrevention && !CanBattlerEscape(gActiveBattler))
    {
        gBattlescriptCurrInstr = cmd->jumpInstr;
    }
    else
    {
        if (CanBattlerSwitch(gActiveBattler))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
           gBattlescriptCurrInstr = cmd->jumpInstr;
    }
}

// Opens the party screen to choose a new Pokémon to send out.
// slotId is the Pokémon to replace.
// Note that this is not used by the Switch action, only replacing fainted Pokémon or Baton Pass
static void ChooseMonToSendOut(u8 slotId)
{
    *(gBattleStruct->battlerPartyIndexes + gActiveBattler) = gBattlerPartyIndexes[gActiveBattler];
    *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
    gBattleStruct->field_93 &= ~(gBitTable[gActiveBattler]);

    BtlController_EmitChoosePokemon(BUFFER_A, PARTY_ACTION_SEND_OUT, slotId, ABILITY_NONE, gBattleStruct->battlerPartyOrders[gActiveBattler]);
    MarkBattlerForControllerExec(gActiveBattler);
}

static void Cmd_openpartyscreen(void)
{
    CMD_ARGS(u8 battler:7, u8 partyScreenOptional:1, const u8 *failInstr);

    u32 flags;
    u8 hitmarkerFaintBits;
    u8 battlerId;
    const u8 *failInstr;

    battlerId = 0;
    flags = 0;
    failInstr = cmd->failInstr;

    if (cmd->battler == BS_FAINTED_LINK_MULTIPLE_1)
    {
        if ((gBattleTypeFlags & BATTLE_TYPE_MULTI) || !(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gHitMarker & HITMARKER_FAINTED(gActiveBattler))
                {
                    if (HasNoMonsToSwitch(gActiveBattler, PARTY_SIZE, PARTY_SIZE))
                    {
                        gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                        gHitMarker &= ~HITMARKER_FAINTED(gActiveBattler);
                        BtlController_EmitLinkStandbyMsg(BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                    else if (!gSpecialStatuses[gActiveBattler].faintedHasReplacement)
                    {
                        ChooseMonToSendOut(PARTY_SIZE);
                        gSpecialStatuses[gActiveBattler].faintedHasReplacement = TRUE;
                    }
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
            }
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            bool8 hasReplacement_0, hasReplacement_1, hasReplacement_2, hasReplacement_3;

            hitmarkerFaintBits = gHitMarker >> 28;

            if (gBitTable[0] & hitmarkerFaintBits)
            {
                gActiveBattler = 0;
                if (HasNoMonsToSwitch(gActiveBattler, PARTY_SIZE, PARTY_SIZE))
                {
                    gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                    gHitMarker &= ~HITMARKER_FAINTED(gActiveBattler);
                    BtlController_EmitCantSwitch(BUFFER_A);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                else if (!gSpecialStatuses[gActiveBattler].faintedHasReplacement)
                {
                    ChooseMonToSendOut(gBattleStruct->monToSwitchIntoId[2]);
                    gSpecialStatuses[gActiveBattler].faintedHasReplacement = TRUE;
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(gActiveBattler);
                    flags |= 1;
                }
            }
            if (gBitTable[2] & hitmarkerFaintBits && !(gBitTable[0] & hitmarkerFaintBits))
            {
                gActiveBattler = 2;
                if (HasNoMonsToSwitch(gActiveBattler, PARTY_SIZE, PARTY_SIZE))
                {
                    gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                    gHitMarker &= ~HITMARKER_FAINTED(gActiveBattler);
                    BtlController_EmitCantSwitch(BUFFER_A);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                else if (!gSpecialStatuses[gActiveBattler].faintedHasReplacement)
                {
                    ChooseMonToSendOut(gBattleStruct->monToSwitchIntoId[0]);
                    gSpecialStatuses[gActiveBattler].faintedHasReplacement = TRUE;
                }
                else if (!(flags & 1))
                {
                    BtlController_EmitLinkStandbyMsg(BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
            }
            if (gBitTable[1] & hitmarkerFaintBits)
            {
                gActiveBattler = 1;
                if (HasNoMonsToSwitch(gActiveBattler, PARTY_SIZE, PARTY_SIZE))
                {
                    gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                    gHitMarker &= ~HITMARKER_FAINTED(gActiveBattler);
                    BtlController_EmitCantSwitch(BUFFER_A);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                else if (!gSpecialStatuses[gActiveBattler].faintedHasReplacement)
                {
                    ChooseMonToSendOut(gBattleStruct->monToSwitchIntoId[3]);
                    gSpecialStatuses[gActiveBattler].faintedHasReplacement = TRUE;
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(gActiveBattler);
                    flags |= 2;
                }
            }
            if (gBitTable[3] & hitmarkerFaintBits && !(gBitTable[1] & hitmarkerFaintBits))
            {
                gActiveBattler = 3;
                if (HasNoMonsToSwitch(gActiveBattler, PARTY_SIZE, PARTY_SIZE))
                {
                    gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                    gHitMarker &= ~HITMARKER_FAINTED(gActiveBattler);
                    BtlController_EmitCantSwitch(BUFFER_A);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                else if (!gSpecialStatuses[gActiveBattler].faintedHasReplacement)
                {
                    ChooseMonToSendOut(gBattleStruct->monToSwitchIntoId[1]);
                    gSpecialStatuses[gActiveBattler].faintedHasReplacement = TRUE;
                }
                else if (!(flags & 2))
                {
                    BtlController_EmitLinkStandbyMsg(BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
            }

            hasReplacement_0 = gSpecialStatuses[0].faintedHasReplacement;
            if (!hasReplacement_0)
            {
                hasReplacement_2 = gSpecialStatuses[2].faintedHasReplacement;
                if (!hasReplacement_2 && hitmarkerFaintBits != 0)
                {
                    if (gAbsentBattlerFlags & gBitTable[0])
                        gActiveBattler = 2;
                    else
                        gActiveBattler = 0;

                    BtlController_EmitLinkStandbyMsg(BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(gActiveBattler);
                }

            }
            hasReplacement_1 = gSpecialStatuses[1].faintedHasReplacement;
            if (!hasReplacement_1)
            {
                hasReplacement_3 = gSpecialStatuses[3].faintedHasReplacement;
                if (!hasReplacement_3 && hitmarkerFaintBits != 0)
                {
                    if (gAbsentBattlerFlags & gBitTable[1])
                        gActiveBattler = 3;
                    else
                        gActiveBattler = 1;

                    BtlController_EmitLinkStandbyMsg(BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
            }
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (cmd->battler == BS_FAINTED_LINK_MULTIPLE_2)
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                hitmarkerFaintBits = gHitMarker >> 28;
                if (gBitTable[2] & hitmarkerFaintBits && gBitTable[0] & hitmarkerFaintBits)
                {
                    gActiveBattler = 2;
                    if (HasNoMonsToSwitch(gActiveBattler, gBattleResources->bufferB[0][1], PARTY_SIZE))
                    {
                        gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                        gHitMarker &= ~HITMARKER_FAINTED(gActiveBattler);
                        BtlController_EmitCantSwitch(BUFFER_A);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                    else if (!gSpecialStatuses[gActiveBattler].faintedHasReplacement)
                    {
                        ChooseMonToSendOut(gBattleStruct->monToSwitchIntoId[0]);
                        gSpecialStatuses[gActiveBattler].faintedHasReplacement = TRUE;
                    }
                }
                if (gBitTable[3] & hitmarkerFaintBits && hitmarkerFaintBits & gBitTable[1])
                {
                    gActiveBattler = 3;
                    if (HasNoMonsToSwitch(gActiveBattler, gBattleResources->bufferB[1][1], PARTY_SIZE))
                    {
                        gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                        gHitMarker &= ~HITMARKER_FAINTED(gActiveBattler);
                        BtlController_EmitCantSwitch(BUFFER_A);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                    else if (!gSpecialStatuses[gActiveBattler].faintedHasReplacement)
                    {
                        ChooseMonToSendOut(gBattleStruct->monToSwitchIntoId[1]);
                        gSpecialStatuses[gActiveBattler].faintedHasReplacement = TRUE;
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

        battlerId = GetBattlerForBattleScript(cmd->battler);
        if (gSpecialStatuses[battlerId].faintedHasReplacement)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else if (HasNoMonsToSwitch(battlerId, PARTY_SIZE, PARTY_SIZE))
        {
            gActiveBattler = battlerId;
            gAbsentBattlerFlags |= gBitTable[gActiveBattler];
            gHitMarker &= ~HITMARKER_FAINTED(gActiveBattler);
            gBattlescriptCurrInstr = failInstr;
        }
        else
        {
            gActiveBattler = battlerId;
            *(gBattleStruct->battlerPartyIndexes + gActiveBattler) = gBattlerPartyIndexes[gActiveBattler];
            *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
            gBattleStruct->field_93 &= ~(gBitTable[gActiveBattler]);

            BtlController_EmitChoosePokemon(BUFFER_A, hitmarkerFaintBits, *(gBattleStruct->monToSwitchIntoId + BATTLE_PARTNER(gActiveBattler)), ABILITY_NONE, gBattleStruct->battlerPartyOrders[gActiveBattler]);
            MarkBattlerForControllerExec(gActiveBattler);

            gBattlescriptCurrInstr = cmd->nextInstr;

            if (GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_LEFT && gBattleResults.playerSwitchesCounter < 255)
                gBattleResults.playerSwitchesCounter++;

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
                {
                    if (gActiveBattler != battlerId)
                    {
                        BtlController_EmitLinkStandbyMsg(BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                }
            }
            else
            {
                gActiveBattler = GetBattlerAtPosition(BATTLE_OPPOSITE(GetBattlerPosition(battlerId)));
                if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
                    gActiveBattler ^= BIT_FLANK;

                BtlController_EmitLinkStandbyMsg(BUFFER_A, LINK_STANDBY_MSG_ONLY, FALSE);
                MarkBattlerForControllerExec(gActiveBattler);
            }
        }
    }
}

static void Cmd_switchhandleorder(void)
{
    CMD_ARGS(u8 battler, u8 state);

    s32 i;
    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);

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
            SwitchPartyOrder(gActiveBattler);
        break;
    case 2:
        if (!(gBattleStruct->field_93 & gBitTable[gActiveBattler]))
        {
            RecordedBattle_SetBattlerAction(gActiveBattler, gBattleResources->bufferB[gActiveBattler][1]);
            gBattleStruct->field_93 |= gBitTable[gActiveBattler];
        }
        // fall through
    case 3:
        gBattleCommunication[0] = gBattleResources->bufferB[gActiveBattler][1];
        *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = gBattleResources->bufferB[gActiveBattler][1];

        if (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            *(gActiveBattler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) &= 0xF;
            *(gActiveBattler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) |= (gBattleResources->bufferB[gActiveBattler][2] & 0xF0);
            *(gActiveBattler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 1) = gBattleResources->bufferB[gActiveBattler][3];

            *((BATTLE_PARTNER(gActiveBattler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) &= (0xF0);
            *((BATTLE_PARTNER(gActiveBattler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) |= (gBattleResources->bufferB[gActiveBattler][2] & 0xF0) >> 4;
            *((BATTLE_PARTNER(gActiveBattler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 2) = gBattleResources->bufferB[gActiveBattler][3];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            SwitchPartyOrderInGameMulti(gActiveBattler, *(gBattleStruct->monToSwitchIntoId + gActiveBattler));
        }
        else
        {
            SwitchPartyOrder(gActiveBattler);
        }

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].species)
        PREPARE_MON_NICK_BUFFER(gBattleTextBuff2, gActiveBattler, gBattleResources->bufferB[gActiveBattler][1])
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void SetDmgHazardsBattlescript(u8 battlerId, u8 multistringId)
{
    gBattleMons[battlerId].status2 &= ~STATUS2_DESTINY_BOND;
    gHitMarker &= ~HITMARKER_DESTINYBOND;
    gBattleScripting.battler = battlerId;
    gBattleCommunication[MULTISTRING_CHOOSER] = multistringId;

    BattleScriptPushCursor();
    if (gBattlescriptCurrInstr[1] == BS_TARGET)
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnTarget;
    else if (gBattlescriptCurrInstr[1] == BS_ATTACKER)
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnAttacker;
    else
        gBattlescriptCurrInstr = BattleScript_DmgHazardsOnFaintedBattler;
}

bool32 DoSwitchInAbilitiesItems(u32 battlerId)
{
    return (AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, battlerId, 0, 0, 0)
             || (gBattleWeather & B_WEATHER_ANY && WEATHER_HAS_EFFECT && AbilityBattleEffects(ABILITYEFFECT_ON_WEATHER, battlerId, 0, 0, 0))
             || (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY && AbilityBattleEffects(ABILITYEFFECT_ON_TERRAIN, battlerId, 0, 0, 0))
             || ItemBattleEffects(ITEMEFFECT_ON_SWITCH_IN, battlerId, FALSE)
             || AbilityBattleEffects(ABILITYEFFECT_TRACE2, 0, 0, 0, 0));
}

bool32 ShouldPostponeSwitchInAbilities(u32 battlerId)
{
    bool32 aliveOpposing1 = IsBattlerAlive(BATTLE_OPPOSITE(battlerId));
    bool32 aliveOpposing2 = IsBattlerAlive(BATTLE_PARTNER(BATTLE_OPPOSITE(battlerId)));
    // No pokemon on opposing side - postpone.
    if (!aliveOpposing1 && !aliveOpposing2)
        return TRUE;

    // Checks for double battle, so abilities like Intimidate wait until all battlers are switched-in before activating.
    if (IsDoubleBattle())
    {
        if (aliveOpposing1 && !aliveOpposing2 && !HasNoMonsToSwitch(BATTLE_PARTNER(BATTLE_OPPOSITE(battlerId)), PARTY_SIZE, PARTY_SIZE))
            return TRUE;
        if (!aliveOpposing1 && aliveOpposing2 && !HasNoMonsToSwitch(BATTLE_OPPOSITE(battlerId), PARTY_SIZE, PARTY_SIZE))
            return TRUE;
    }

    return FALSE;
}

static void Cmd_switchineffects(void)
{
    CMD_ARGS(u8 battler);

    s32 i;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    UpdateSentPokesToOpponentValue(gActiveBattler);

    gHitMarker &= ~HITMARKER_FAINTED(gActiveBattler);
    gSpecialStatuses[gActiveBattler].faintedHasReplacement = FALSE;

    if (!BattlerHasAi(gActiveBattler))
        gBattleStruct->appearedInBattle |= gBitTable[gBattlerPartyIndexes[gActiveBattler]];

    // Neutralizing Gas announces itself before hazards
    if (gBattleMons[gActiveBattler].ability == ABILITY_NEUTRALIZING_GAS && gSpecialStatuses[gActiveBattler].announceNeutralizingGas == 0)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SWITCHIN_NEUTRALIZING_GAS;
        gSpecialStatuses[gActiveBattler].announceNeutralizingGas = TRUE;
        gBattlerAbility = gActiveBattler;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SwitchInAbilityMsgRet;
    }
    // Healing Wish activates before hazards.
    // Starting from Gen8 - it heals only pokemon which can be healed. In gens 5,6,7 the effect activates anyways.
    else if (((gBattleStruct->storedHealingWish & gBitTable[gActiveBattler]) || (gBattleStruct->storedLunarDance & gBitTable[gActiveBattler]))
        && (gBattleMons[gActiveBattler].hp != gBattleMons[gActiveBattler].maxHP || gBattleMons[gActiveBattler].status1 != 0 || B_HEALING_WISH_SWITCH < GEN_8))
    {
        if (gBattleStruct->storedHealingWish & gBitTable[gActiveBattler])
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_HealingWishActivates;
            gBattleStruct->storedHealingWish  &= ~(gBitTable[gActiveBattler]);
        }
        else // Lunar Dance
        {
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_LunarDanceActivates;
            gBattleStruct->storedLunarDance  &= ~(gBitTable[gActiveBattler]);
        }
    }
    else if (!(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_SPIKES_DAMAGED)
        && (gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_SPIKES)
        && GetBattlerAbility(gActiveBattler) != ABILITY_MAGIC_GUARD
        && IsBattlerAffectedByHazards(gActiveBattler, FALSE)
        && IsBattlerGrounded(gActiveBattler))
    {
        u8 spikesDmg = (5 - gSideTimers[GetBattlerSide(gActiveBattler)].spikesAmount) * 2;
        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / (spikesDmg);
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gSideStatuses[GetBattlerSide(gActiveBattler)] |= SIDE_STATUS_SPIKES_DAMAGED;
        SetDmgHazardsBattlescript(gActiveBattler, B_MSG_PKMNHURTBYSPIKES);
    }
    else if (!(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_STEALTH_ROCK_DAMAGED)
        && (gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_STEALTH_ROCK)
        && IsBattlerAffectedByHazards(gActiveBattler, FALSE)
        && GetBattlerAbility(gActiveBattler) != ABILITY_MAGIC_GUARD)
    {
        gSideStatuses[GetBattlerSide(gActiveBattler)] |= SIDE_STATUS_STEALTH_ROCK_DAMAGED;
        gBattleMoveDamage = GetStealthHazardDamage(gBattleMoves[MOVE_STEALTH_ROCK].type, gActiveBattler);

        if (gBattleMoveDamage != 0)
            SetDmgHazardsBattlescript(gActiveBattler, B_MSG_STEALTHROCKDMG);
    }
    else if (!(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_TOXIC_SPIKES_DAMAGED)
        && (gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_TOXIC_SPIKES)
        && IsBattlerGrounded(gActiveBattler))
    {
        gSideStatuses[GetBattlerSide(gActiveBattler)] |= SIDE_STATUS_TOXIC_SPIKES_DAMAGED;
        if (IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_POISON)) // Absorb the toxic spikes.
        {
            gSideStatuses[GetBattlerSide(gActiveBattler)] &= ~SIDE_STATUS_TOXIC_SPIKES;
            gSideTimers[GetBattlerSide(gActiveBattler)].toxicSpikesAmount = 0;
            gBattleScripting.battler = gActiveBattler;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_ToxicSpikesAbsorbed;
        }
        else if (IsBattlerAffectedByHazards(gActiveBattler, TRUE))
        {
            if (!(gBattleMons[gActiveBattler].status1 & STATUS1_ANY)
                && !IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_STEEL)
                && GetBattlerAbility(gActiveBattler) != ABILITY_IMMUNITY
                && !IsAbilityOnSide(gActiveBattler, ABILITY_PASTEL_VEIL)
                && !(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_SAFEGUARD)
                && !(gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN))
            {
                if (gSideTimers[GetBattlerSide(gActiveBattler)].toxicSpikesAmount >= 2)
                    gBattleMons[gActiveBattler].status1 |= STATUS1_TOXIC_POISON;
                else
                    gBattleMons[gActiveBattler].status1 |= STATUS1_POISON;

                BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
                MarkBattlerForControllerExec(gActiveBattler);
                gBattleScripting.battler = gActiveBattler;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ToxicSpikesPoisoned;
            }
        }
    }
    else if (!(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_STICKY_WEB_DAMAGED)
        && (gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_STICKY_WEB)
        && IsBattlerAffectedByHazards(gActiveBattler, FALSE)
        && IsBattlerGrounded(gActiveBattler))
    {
        gSideStatuses[GetBattlerSide(gActiveBattler)] |= SIDE_STATUS_STICKY_WEB_DAMAGED;
        gBattleScripting.battler = gActiveBattler;
        SET_STATCHANGER(STAT_SPEED, 1, TRUE);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_StickyWebOnSwitchIn;
    }
    else if (gBattleMons[gActiveBattler].hp != gBattleMons[gActiveBattler].maxHP && gBattleStruct->zmove.healReplacement)
    {
        gBattleStruct->zmove.healReplacement = FALSE;
        gBattleMoveDamage = -1 * (gBattleMons[gActiveBattler].maxHP);
        gBattleScripting.battler = gActiveBattler;
        BattleScriptPushCursor();
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_HP_TRAP;
        gBattlescriptCurrInstr = BattleScript_HealReplacementZMove;
        return;
    }
    else
    {
        // There is a hack here to ensure the truant counter will be 0 when the battler's next turn starts.
        // The truant counter is not updated in the case where a mon switches in after a lost judgment in the battle arena.
        if (GetBattlerAbility(gActiveBattler) == ABILITY_TRUANT
            && gCurrentActionFuncId != B_ACTION_USE_MOVE
            && !gDisableStructs[gActiveBattler].truantSwitchInHack)
            gDisableStructs[gActiveBattler].truantCounter = 1;

        gDisableStructs[gActiveBattler].truantSwitchInHack = 0;

        // Don't activate switch-in abilities if the opposing field is empty.
        // This could happen when a mon uses explosion and causes everyone to faint.
        if (ShouldPostponeSwitchInAbilities(gActiveBattler) || gBattleStruct->switchInAbilityPostponed)
        {
            gBattleStruct->switchInAbilityPostponed |= gBitTable[gActiveBattler];
        }
        else
        {
            if (DoSwitchInAbilitiesItems(gActiveBattler))
                return;
        }

        gSideStatuses[GetBattlerSide(gActiveBattler)] &= ~(SIDE_STATUS_SPIKES_DAMAGED | SIDE_STATUS_TOXIC_SPIKES_DAMAGED | SIDE_STATUS_STEALTH_ROCK_DAMAGED | SIDE_STATUS_STICKY_WEB_DAMAGED);

        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == gActiveBattler)
                gActionsByTurnOrder[i] = B_ACTION_CANCEL_PARTNER;

            gBattleStruct->hpOnSwitchout[GetBattlerSide(i)] = gBattleMons[i].hp;
        }

        if (cmd->battler == BS_FAINTED_LINK_MULTIPLE_1)
        {
            u32 hitmarkerFaintBits = gHitMarker >> 28;

            gBattlerFainted++;
            while (1)
            {
                if (hitmarkerFaintBits & gBitTable[gBattlerFainted] && !(gAbsentBattlerFlags & gBitTable[gBattlerFainted]))
                    break;
                if (gBattlerFainted >= gBattlersCount)
                    break;
                gBattlerFainted++;
            }
        }
        gBattleStruct->forcedSwitch &= ~(gBitTable[gActiveBattler]);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_trainerslidein(void)
{
    CMD_ARGS(u8 battler);

    gActiveBattler = GetBattlerAtPosition(cmd->battler);
    BtlController_EmitTrainerSlide(BUFFER_A);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_playse(void)
{
    CMD_ARGS(u16 song);

    gActiveBattler = gBattlerAttacker;
    BtlController_EmitPlaySE(BUFFER_A, cmd->song);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_fanfare(void)
{
    CMD_ARGS(u16 song);

    gActiveBattler = gBattlerAttacker;
    BtlController_EmitPlayFanfareOrBGM(BUFFER_A, cmd->song, FALSE);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_playfaintcry(void)
{
    CMD_ARGS(u8 battler);

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitFaintingCry(BUFFER_A);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_endlinkbattle(void)
{
    CMD_ARGS();

    gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
    BtlController_EmitEndLinkBattle(BUFFER_A, gBattleOutcome);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_returntoball(void)
{
    CMD_ARGS(u8 battler);

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitReturnMonToBall(BUFFER_A, TRUE);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_handlelearnnewmove(void)
{
    CMD_ARGS(const u8 *learnedMovePtr, const u8 *nothingToLearnPtr, bool8 isFirstMove);

    const u8 *learnedMovePtr = cmd->learnedMovePtr;
    const u8 *nothingToLearnPtr = cmd->nothingToLearnPtr;

    u16 learnMove = MonTryLearningNewMove(&gPlayerParty[gBattleStruct->expGetterMonId], cmd->isFirstMove);
    while (learnMove == MON_ALREADY_KNOWS_MOVE)
        learnMove = MonTryLearningNewMove(&gPlayerParty[gBattleStruct->expGetterMonId], FALSE);

    if (learnMove == MOVE_NONE)
    {
        gBattlescriptCurrInstr = nothingToLearnPtr;
    }
    else if (learnMove == MON_HAS_MAX_MOVES)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

        if (gBattlerPartyIndexes[gActiveBattler] == gBattleStruct->expGetterMonId
            && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
        {
            GiveMoveToBattleMon(&gBattleMons[gActiveBattler], learnMove);
        }
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            if (gBattlerPartyIndexes[gActiveBattler] == gBattleStruct->expGetterMonId
                && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
            {
                GiveMoveToBattleMon(&gBattleMons[gActiveBattler], learnMove);
            }
        }

        gBattlescriptCurrInstr = learnedMovePtr;
    }
}

static void Cmd_yesnoboxlearnmove(void)
{
    CMD_ARGS(const u8 *forgotMovePtr);

    gActiveBattler = 0;

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
                if (IsHMMove2(moveId))
                {
                    PrepareStringBattle(STRINGID_HMMOVESCANTBEFORGOTTEN, gActiveBattler);
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

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);

    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else if (!(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE) || !(DoesSubstituteBlockMove(gBattlerAttacker, gActiveBattler, gCurrentMove)) || gDisableStructs[gActiveBattler].substituteHP == 0)
    {
        BtlController_EmitHitAnimation(BUFFER_A);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static u32 GetTrainerMoneyToGive(u16 trainerId)
{
    u32 i = 0;
    u32 lastMonLevel = 0;
    u32 moneyReward;

    if (trainerId == TRAINER_SECRET_BASE)
    {
        moneyReward = 20 * gBattleResources->secretBase->party.levels[0] * gBattleStruct->moneyMultiplier;
    }
    else
    {
        switch (gTrainers[trainerId].partyFlags)
        {
        case 0:
            {
                const struct TrainerMonNoItemDefaultMoves *party = gTrainers[trainerId].party.NoItemDefaultMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case F_TRAINER_PARTY_CUSTOM_MOVESET:
            {
                const struct TrainerMonNoItemCustomMoves *party = gTrainers[trainerId].party.NoItemCustomMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemDefaultMoves *party = gTrainers[trainerId].party.ItemDefaultMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
            {
                const struct TrainerMonItemCustomMoves *party = gTrainers[trainerId].party.ItemCustomMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case F_TRAINER_PARTY_EVERYTHING_CUSTOMIZED:
            {
                const struct TrainerMonCustomized *party = gTrainers[trainerId].party.EverythingCustomized;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        }

        for (; gTrainerMoneyTable[i].classId != 0xFF; i++)
        {
            if (gTrainerMoneyTable[i].classId == gTrainers[trainerId].trainerClass)
                break;
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * gTrainerMoneyTable[i].value;
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * 2 * gTrainerMoneyTable[i].value;
        else
            moneyReward = 4 * lastMonLevel * gBattleStruct->moneyMultiplier * gTrainerMoneyTable[i].value;
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

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);

    switch (gBattleCommunication[0])
    {
    case 0:
        BtlController_EmitGetMonData(BUFFER_A, REQUEST_ALL_BATTLE, 0);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattleCommunication[0]++;
        break;
    case 1:
         if (gBattleControllerExecFlags == 0)
         {
            s32 i;
            struct BattlePokemon *bufferPoke = (struct BattlePokemon *) &gBattleResources->bufferB[gActiveBattler][4];
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                gBattleMons[gActiveBattler].moves[i] = bufferPoke->moves[i];
                gBattleMons[gActiveBattler].pp[i] = bufferPoke->pp[i];
            }
            gBattlescriptCurrInstr = cmd->nextInstr;
         }
         break;
    }
}

static void Cmd_swapattackerwithtarget(void)
{
    CMD_ARGS();

    gActiveBattler = gBattlerAttacker;
    gBattlerAttacker = gBattlerTarget;
    gBattlerTarget = gActiveBattler;

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

    s32 i;
    struct Pokemon *party;
    struct HpAndStatus hpStatuses[PARTY_SIZE];

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);

    party = GetBattlerParty(gActiveBattler);

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

    BtlController_EmitDrawPartyStatusSummary(BUFFER_A, hpStatuses, 1);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_hidepartystatussummary(void)
{
    CMD_ARGS(u8 battler);

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitHidePartyStatusSummary(BUFFER_A);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumptocalledmove(void)
{
    CMD_ARGS(bool8 notChosenMove);

    if (cmd->notChosenMove)
        gCurrentMove = gCalledMove;
    else
        gChosenMove = gCurrentMove = gCalledMove;

    gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
}

static void Cmd_statusanimation(void)
{
    CMD_ARGS(u8 battler);

    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);
        if (!(gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[gActiveBattler].substituteHP == 0
            && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            BtlController_EmitStatusAnimation(BUFFER_A, FALSE, gBattleMons[gActiveBattler].status1);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_status2animation(void)
{
    CMD_ARGS(u8 battler, u32 status2);

    u32 wantedToAnimate;

    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);
        wantedToAnimate = cmd->status2;
        if (!(gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[gActiveBattler].substituteHP == 0
            && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            BtlController_EmitStatusAnimation(BUFFER_A, TRUE, gBattleMons[gActiveBattler].status2 & wantedToAnimate);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_chosenstatusanimation(void)
{
    CMD_ARGS(u8 battler, bool8 isStatus2, u32 status);

    u32 wantedStatus;

    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);
        wantedStatus = cmd->status;
        if (!(gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[gActiveBattler].substituteHP == 0
            && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            BtlController_EmitStatusAnimation(BUFFER_A, cmd->isStatus2, wantedStatus);
            MarkBattlerForControllerExec(gActiveBattler);
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

static bool32 TryCheekPouch(u32 battlerId, u32 itemId)
{
    if (ItemId_GetPocket(itemId) == POCKET_BERRIES
        && GetBattlerAbility(battlerId) == ABILITY_CHEEK_POUCH
        && !(gStatuses3[battlerId] & STATUS3_HEAL_BLOCK)
        && gBattleStruct->ateBerry[GetBattlerSide(battlerId)] & gBitTable[gBattlerPartyIndexes[battlerId]]
        && !BATTLER_MAX_HP(battlerId))
    {
        gBattleMoveDamage = gBattleMons[battlerId].maxHP / 3;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;
        gBattlerAbility = battlerId;
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

    gActiveBattler = battlerAtk;
    gBattleMons[battlerAtk].item = ITEM_NONE;
    BtlController_EmitSetMonData(BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battlerAtk].item), &gBattleMons[battlerAtk].item);
    MarkBattlerForControllerExec(battlerAtk);
    CheckSetUnburden(battlerAtk);

    gActiveBattler = battlerDef;
    gBattleMons[battlerDef].item = gLastUsedItem;
    BtlController_EmitSetMonData(BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battlerDef].item), &gBattleMons[battlerDef].item);
    MarkBattlerForControllerExec(battlerDef);
    gBattleResources->flags->flags[battlerDef] &= ~RESOURCE_FLAG_UNBURDEN;
}

// Called by Cmd_removeitem. itemId represents the item that was removed, not being given.
static bool32 TrySymbiosis(u32 battler, u32 itemId)
{
    if (!gBattleStruct->itemLost[gBattlerPartyIndexes[battler]].stolen
        && gBattleStruct->changedItems[battler] == ITEM_NONE
        && GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_EJECT_BUTTON
        && GetBattlerHoldEffect(battler, TRUE) != HOLD_EFFECT_EJECT_PACK
    #if B_SYMBIOSIS_GEMS >= GEN_7
        && !(gSpecialStatuses[battler].gemBoost)
    #endif
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

    u16 itemId = 0;

    if (gBattleScripting.overrideBerryRequirements)
    {
        // bug bite / pluck - don't remove current item
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    itemId = gBattleMons[gActiveBattler].item;

    // Popped Air Balloon cannot be restored by any means.
    if (GetBattlerHoldEffect(gActiveBattler, TRUE) != HOLD_EFFECT_AIR_BALLOON)
        gBattleStruct->usedHeldItems[gBattlerPartyIndexes[gActiveBattler]][GetBattlerSide(gActiveBattler)] = itemId; // Remember if switched out

    gBattleMons[gActiveBattler].item = ITEM_NONE;
    CheckSetUnburden(gActiveBattler);

    BtlController_EmitSetMonData(BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].item), &gBattleMons[gActiveBattler].item);
    MarkBattlerForControllerExec(gActiveBattler);

    ClearBattlerItemEffectHistory(gActiveBattler);
    if (!TryCheekPouch(gActiveBattler, itemId) && !TrySymbiosis(gActiveBattler, itemId))
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
        if (gMain.newKeys != 0)
        {
            // Draw page 2 of level up box
            PlaySE(SE_SELECT);
            DrawLevelUpWindow2();
            CopyWindowToVram(B_WIN_LEVEL_UP_BOX, COPYWIN_GFX);
            gBattleScripting.drawlvlupboxState++;
        }
        break;
    case 8:
        if (gMain.newKeys != 0)
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

    LoadPalette(sLevelUpBanner_Pal, BG_PLTT_ID(6), PLTT_SIZE_4BPP);
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
    u16 monLevel;
    u8 monGender;
    struct TextPrinterTemplate printerTemplate;
    u8 *txtPtr;
    u32 var;

    monLevel = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_LEVEL);
    monGender = GetMonGender(&gPlayerParty[gBattleStruct->expGetterMonId]);
    GetMonNickname(&gPlayerParty[gBattleStruct->expGetterMonId], gStringVar4);

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
    const u16 *iconPal;
    struct SpriteSheet iconSheet;
    struct SpritePalette iconPalSheet;

    u16 species = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_SPECIES);
    u32 personality = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_PERSONALITY);

    const u8 *iconPtr = GetMonIconPtr(species, personality);
    iconSheet.data = iconPtr;
    iconSheet.size = 0x200;
    iconSheet.tag = TAG_LVLUP_BANNER_MON_ICON;

    iconPal = GetValidMonIconPalettePtr(species);
    iconPalSheet.data = iconPal;
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

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    BtlController_EmitSpriteInvisibility(BUFFER_A, FALSE);
    MarkBattlerForControllerExec(gActiveBattler);

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

    u8 opposingBattler;
    s32 result;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);
        opposingBattler = BATTLE_OPPOSITE(gActiveBattler);

        result = gBattleMons[opposingBattler].hp * 100 / gBattleMons[opposingBattler].maxHP;
        if (result == 0)
            result = 1;

        if (result > 69 || gBattleMons[opposingBattler].hp == 0)
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

    u8 opposingBattler;
    s32 result;
    u8 hpSwitchout;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);
        opposingBattler = BATTLE_OPPOSITE(gActiveBattler);
        hpSwitchout = *(gBattleStruct->hpOnSwitchout + GetBattlerSide(opposingBattler));
        result = (hpSwitchout - gBattleMons[opposingBattler].hp) * 100 / hpSwitchout;

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
        && gBattleMoves[gCurrentMove].power != 0
        && (gLastHitBy[gBattlerTarget] == 0xFF || gLastHitBy[gBattlerTarget] == gBattlerAttacker)
        && gBattleStruct->moveTarget[gBattlerAttacker] == gBattlerTarget
        && gBattlerTarget != gBattlerAttacker
        && gCurrentTurnActionNumber == GetBattlerTurnOrderNum(gBattlerAttacker)
        && (gChosenMove == gChosenMoveByBattler[gBattlerAttacker] || gChosenMove == gBattleMons[gBattlerAttacker].moves[gChosenMovePos]))
        return TRUE;
    else
        return FALSE;
}

static void HandleTerrainMove(u16 move)
{
    u32 statusFlag = 0;

    switch (gBattleMoves[move].effect)
    {
    case EFFECT_MISTY_TERRAIN:
        statusFlag = STATUS_FIELD_MISTY_TERRAIN;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        break;
    case EFFECT_GRASSY_TERRAIN:
        statusFlag = STATUS_FIELD_GRASSY_TERRAIN;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        break;
    case EFFECT_ELECTRIC_TERRAIN:
        statusFlag = STATUS_FIELD_ELECTRIC_TERRAIN;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        break;
    case EFFECT_PSYCHIC_TERRAIN:
        statusFlag = STATUS_FIELD_PSYCHIC_TERRAIN;
        gBattleCommunication[MULTISTRING_CHOOSER] = 3;
        break;
    case EFFECT_HIT_SET_REMOVE_TERRAIN:
        switch (gBattleMoves[move].argument)
        {
        case 0: //genesis supernova
            statusFlag = STATUS_FIELD_PSYCHIC_TERRAIN;
            gBattleCommunication[MULTISTRING_CHOOSER] = 3;
            break;
        case 1: //splintered stormshards
            if (!(gFieldStatuses & STATUS_FIELD_TERRAIN_ANY))
            {
                //no terrain to remove -> jump to battle script pointer
                gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
            }
            else
            {
                // remove all terrain
                gFieldStatuses &= ~STATUS_FIELD_TERRAIN_ANY;
                gBattleCommunication[MULTISTRING_CHOOSER] = 4;
                gBattlescriptCurrInstr += 7;
            }
            return;
        default:
            break;
        }
        break;
    }

    if (gFieldStatuses & statusFlag || statusFlag == 0)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
    }
    else
    {
        gFieldStatuses &= ~STATUS_FIELD_TERRAIN_ANY;
        gFieldStatuses |= statusFlag;
        if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_TERRAIN_EXTENDER)
            gFieldTimers.terrainTimer = 8;
        else
            gFieldTimers.terrainTimer = 5;
        gBattlescriptCurrInstr += 7;
    }
}

bool32 CanPoisonType(u8 battlerAttacker, u8 battlerTarget)
{
    return ((GetBattlerAbility(battlerAttacker) == ABILITY_CORROSION && gBattleMoves[gCurrentMove].split == SPLIT_STATUS)
            || !(IS_BATTLER_OF_TYPE(battlerTarget, TYPE_POISON) || IS_BATTLER_OF_TYPE(battlerTarget, TYPE_STEEL)));
}

bool32 CanParalyzeType(u8 battlerAttacker, u8 battlerTarget)
{
    return !(B_PARALYZE_ELECTRIC >= GEN_6 && IS_BATTLER_OF_TYPE(battlerTarget, TYPE_ELECTRIC));
}

bool32 CanUseLastResort(u8 battlerId)
{
    u32 i;
    u32 knownMovesCount = 0, usedMovesCount = 0;

    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[battlerId].moves[i] != MOVE_NONE)
            knownMovesCount++;
        if (i != gCurrMovePos && gDisableStructs[battlerId].usedMoves & gBitTable[i]) // Increment used move count for all moves except current Last Resort.
            usedMovesCount++;
    }

    return (knownMovesCount >= 2 && usedMovesCount >= knownMovesCount - 1);
}

static void RemoveAllTerrains(void)
{
    gFieldTimers.terrainTimer = 0;
    switch (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
    {
    case STATUS_FIELD_MISTY_TERRAIN:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINENDS_MISTY;
        break;
    case STATUS_FIELD_GRASSY_TERRAIN:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINENDS_GRASS;
        break;
    case STATUS_FIELD_ELECTRIC_TERRAIN:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINENDS_ELECTRIC;
        break;
    case STATUS_FIELD_PSYCHIC_TERRAIN:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINENDS_PSYCHIC;
        break;
    default:
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAINENDS_COUNT;  // failsafe
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

static bool32 TryDefogClear(u8 battlerAtk, bool32 clear)
{
    s32 i;
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
        #if B_DEFOG_CLEARS_TERRAIN >= GEN_8
        if (gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
        {
            RemoveAllTerrains();
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_TerrainEnds_Ret;
            return TRUE;
        }
        #endif // B_DEFOG_CLEARS_TERRAIN
    }

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

u32 GetHighestStatId(u32 battlerId)
{
    u32 i, highestId = STAT_ATK, highestStat = gBattleMons[battlerId].attack;

    for (i = STAT_DEF; i < NUM_STATS; i++)
    {
        u16 *statVal = &gBattleMons[battlerId].attack + (i - 1);
        if (*statVal > highestStat)
        {
            highestStat = *statVal;
            highestId = i;
        }
    }
    return highestId;
}

static bool32 IsRototillerAffected(u32 battlerId)
{
    if (!IsBattlerAlive(battlerId))
        return FALSE;
    if (!IsBattlerGrounded(battlerId))
        return FALSE;   // Only grounded battlers affected
    if (!IS_BATTLER_OF_TYPE(battlerId, TYPE_GRASS))
        return FALSE;   // Only grass types affected
    if (gStatuses3[battlerId] & STATUS3_SEMI_INVULNERABLE)
        return FALSE;   // Rototiller doesn't affected semi-invulnerable battlers
    if (BlocksPrankster(MOVE_ROTOTILLER, gBattlerAttacker, battlerId, FALSE))
        return FALSE;
    return TRUE;
}


static bool32 IsAbilityRodAffected(void)
{
    u32 moveType;

    if (gBattleStruct->dynamicMoveType == 0)
        moveType = gBattleMoves[gCurrentMove].type;
    else if (!(gBattleStruct->dynamicMoveType & 0x40))
        moveType = gBattleStruct->dynamicMoveType & 0x3F;
    else
        moveType = gBattleMoves[gCurrentMove].type;

    if (moveType == TYPE_ELECTRIC && GetBattlerAbility(gBattlerTarget) == ABILITY_LIGHTNING_ROD)
        return TRUE;
    else
        return FALSE;
}

static bool32 IsAbilityMotorAffected(void)
{
    u32 moveType;

    if (gBattleStruct->dynamicMoveType == 0)
        moveType = gBattleMoves[gCurrentMove].type;
    else if (!(gBattleStruct->dynamicMoveType & 0x40))
        moveType = gBattleStruct->dynamicMoveType & 0x3F;
    else
        moveType = gBattleMoves[gCurrentMove].type;

    if (moveType == TYPE_ELECTRIC && GetBattlerAbility(gBattlerTarget) == ABILITY_MOTOR_DRIVE)
        return TRUE;
    else
        return FALSE;
}

static bool32 IsAbilityAbsorbAffected(void)
{
    u32 moveType;

    if (gBattleStruct->dynamicMoveType == 0)
        moveType = gBattleMoves[gCurrentMove].type;
    else if (!(gBattleStruct->dynamicMoveType & 0x40))
        moveType = gBattleStruct->dynamicMoveType & 0x3F;
    else
        moveType = gBattleMoves[gCurrentMove].type;

    if (moveType == TYPE_ELECTRIC && GetBattlerAbility(gBattlerTarget) == ABILITY_VOLT_ABSORB)
        return TRUE;
    else
        return FALSE;
}

static bool32 IsTeatimeAffected(u32 battlerId)
{
    if (ItemId_GetPocket(gBattleMons[battlerId].item) != POCKET_BERRIES)
        return FALSE;   // Only berries
    if (gStatuses3[battlerId] & STATUS3_SEMI_INVULNERABLE)
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
    sideTimerPlayer->structField ^= BIT_SIDE;        \
    sideTimerOpp->structField ^= BIT_SIDE;        \
}                                               \

static bool32 CourtChangeSwapSideStatuses(void)
{
    struct SideTimer *sideTimerPlayer = &gSideTimers[B_SIDE_PLAYER];
    struct SideTimer *sideTimerOpp = &gSideTimers[B_SIDE_OPPONENT];
    u32 temp;

    // TODO: add Pledge-related effects
    // TODO: add Gigantamax-related effects

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

    // Change battler IDs of swapped effects. Needed for the correct string when they expire
    // E.g. "Foe's Reflect wore off!"
    UPDATE_COURTCHANGED_BATTLER(reflectBattlerId);
    UPDATE_COURTCHANGED_BATTLER(lightscreenBattlerId);
    UPDATE_COURTCHANGED_BATTLER(mistBattlerId);
    UPDATE_COURTCHANGED_BATTLER(safeguardBattlerId);
    UPDATE_COURTCHANGED_BATTLER(auroraVeilBattlerId);
    UPDATE_COURTCHANGED_BATTLER(tailwindBattlerId);
    UPDATE_COURTCHANGED_BATTLER(luckyChantBattlerId);

    // For Mirror Armor only
    gBattleStruct->stickyWebUser = gBattlerAttacker;

    // Track which side originally set the Sticky Web
    SWAP(sideTimerPlayer->stickyWebBattlerSide, sideTimerOpp->stickyWebBattlerSide, temp);
}

static void HandleScriptMegaPrimal(u32 caseId, u32 battlerId, bool32 isMega)
{
    struct Pokemon *party = GetBattlerParty(battlerId);
    struct Pokemon *mon = &party[gBattlerPartyIndexes[battlerId]];
    u32 position = GetBattlerPosition(battlerId);
    u32 side = GET_BATTLER_SIDE(battlerId);

    // Change species.
    if (caseId == 0)
    {
        if (isMega)
        {
            if (!TryBattleFormChange(battlerId, FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM))
                TryBattleFormChange(battlerId, FORM_CHANGE_BATTLE_MEGA_EVOLUTION_MOVE);
        }
        else
            TryBattleFormChange(battlerId, FORM_CHANGE_BATTLE_PRIMAL_REVERSION);

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[battlerId].species);

        BtlController_EmitSetMonData(BUFFER_A, REQUEST_SPECIES_BATTLE, gBitTable[gBattlerPartyIndexes[battlerId]], sizeof(gBattleMons[battlerId].species), &gBattleMons[battlerId].species);
        MarkBattlerForControllerExec(battlerId);
    }
    // Update healthbox and elevation and play cry.
    else
    {
        UpdateHealthboxAttribute(gHealthboxSpriteIds[battlerId], mon, HEALTHBOX_ALL);
        if (side == B_SIDE_OPPONENT)
            SetBattlerShadowSpriteCallback(battlerId, gBattleMons[battlerId].species);
        if (isMega)
            gBattleStruct->mega.alreadyEvolved[position] = TRUE;
    }
}

static bool32 CanTeleport(u8 battlerId)
{
    struct Pokemon *party = GetBattlerParty(battlerId);
    u32 species, count, i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData(&party[i], MON_DATA_HP) != 0)
            count++;
    }

    switch (GetBattlerSide(battlerId))
    {
    case B_SIDE_OPPONENT:
        if (count == 1 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            return FALSE;
        break;
    case B_SIDE_PLAYER:
        if (count == 1 || (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && count <= 2))
            return FALSE;
        break;
    }

    return TRUE;
}

// Return True if the order was changed, and false if the order was not changed(for example because the target would move after the attacker anyway).
static bool32 ChangeOrderTargetAfterAttacker(void)
{
    u32 i;
    u8 data[MAX_BATTLERS_COUNT];

    if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget)
        || GetBattlerTurnOrderNum(gBattlerAttacker) + 1 == GetBattlerTurnOrderNum(gBattlerTarget))
        return FALSE;

    for (i = 0; i < gBattlersCount; i++)
        data[i] = gBattlerByTurnOrder[i];
    if (GetBattlerTurnOrderNum(gBattlerAttacker) == 0 && GetBattlerTurnOrderNum(gBattlerTarget) == 2)
    {
        gBattlerByTurnOrder[1] = gBattlerTarget;
        gBattlerByTurnOrder[2] = data[1];
        gBattlerByTurnOrder[3] = data[3];
    }
    else if (GetBattlerTurnOrderNum(gBattlerAttacker) == 0 && GetBattlerTurnOrderNum(gBattlerTarget) == 3)
    {
        gBattlerByTurnOrder[1] = gBattlerTarget;
        gBattlerByTurnOrder[2] = data[1];
        gBattlerByTurnOrder[3] = data[2];
    }
    else // Attacker == 1, Target == 3
    {
        gBattlerByTurnOrder[2] = gBattlerTarget;
        gBattlerByTurnOrder[3] = data[2];
    }
    return TRUE;
}

static void Cmd_various(void)
{
    CMD_ARGS(u8 battler, u8 id);

    struct Pokemon *mon;
    s32 i, j;
    u8 data[10];
    u32 side, bits;

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);

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
        if (!IsBattlerAlive(gActiveBattler))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_SHIELDS_DOWN_PROTECTED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (IsShieldsDownProtected(gActiveBattler))
        {
            gBattlerAbility = gActiveBattler;
            gBattlescriptCurrInstr = cmd->jumpInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_JUMP_IF_NO_HOLD_EFFECT:
    {
        VARIOUS_ARGS(u8 holdEffect, const u8 *jumpInstr);
        if (GetBattlerHoldEffect(gActiveBattler, TRUE) != cmd->holdEffect)
        {
            gBattlescriptCurrInstr = cmd->jumpInstr;
        }
        else
        {
            gLastUsedItem = gBattleMons[gActiveBattler].item;   // For B_LAST_USED_ITEM
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_JUMP_IF_NO_ALLY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (!IsBattlerAlive(BATTLE_PARTNER(gActiveBattler)))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_INFATUATE_WITH_BATTLER:
    {
        VARIOUS_ARGS(u8 infatuateWith);
        gBattleScripting.battler = gActiveBattler;
        gBattleMons[gActiveBattler].status2 |= STATUS2_INFATUATED_WITH(GetBattlerForBattleScript(cmd->infatuateWith));
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SET_LAST_USED_ITEM:
    {
        VARIOUS_ARGS();
        gLastUsedItem = gBattleMons[gActiveBattler].item;
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
        gBattleMoveDamage = *(u16 *)(&gBattleMons[gActiveBattler].attack) + (i - 1);
        gBattleMoveDamage *= gStatStageRatios[gBattleMons[gActiveBattler].statStages[i]][0];
        gBattleMoveDamage /= gStatStageRatios[gBattleMons[gActiveBattler].statStages[i]][1];
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_FULL_HP:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (BATTLER_MAX_HP(gActiveBattler))
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
            if (GET_BATTLER_SIDE2(gActiveBattler) != GET_BATTLER_SIDE2(gBattlerTarget)
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
        if (!CanPoisonType(gActiveBattler, GetBattlerForBattleScript(cmd->target)))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_PARALYZE_TYPE_IMMUNITY:
    {
        VARIOUS_ARGS(u8 target, const u8 *failInstr);
        if (!CanParalyzeType(gActiveBattler, GetBattlerForBattleScript(cmd->target)))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRACE_ABILITY:
    {
        VARIOUS_ARGS();
        gBattleMons[gActiveBattler].ability = gBattleStruct->overwrittenAbilities[gActiveBattler] = gBattleStruct->tracedAbility[gActiveBattler];
        break;
    }
    case VARIOUS_TRY_ILLUSION_OFF:
    {
        VARIOUS_ARGS();
        if (GetIllusionMonPtr(gActiveBattler) != NULL)
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
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            mon = &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]];
        else
            mon = &gEnemyParty[gBattlerPartyIndexes[gActiveBattler]];
        UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], mon, HEALTHBOX_NICK);
        break;
    }
    case VARIOUS_JUMP_IF_NOT_BERRY:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (ItemId_GetPocket(gBattleMons[gActiveBattler].item) == POCKET_BERRIES)
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->jumpInstr;
        return;
    }
    case VARIOUS_CHECK_IF_GRASSY_TERRAIN_HEALS:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if ((gStatuses3[gActiveBattler] & (STATUS3_SEMI_INVULNERABLE | STATUS3_HEAL_BLOCK))
            || BATTLER_MAX_HP(gActiveBattler)
            || !gBattleMons[gActiveBattler].hp
            || !(IsBattlerGrounded(gActiveBattler)))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
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
        if (gStatuses3[gActiveBattler] & STATUS3_ON_AIR && !(gStatuses3[gActiveBattler] & STATUS3_SKY_DROPPED))
            CancelMultiTurnMoves(gActiveBattler);

        gStatuses3[gActiveBattler] &= ~(STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS | STATUS3_ON_AIR | STATUS3_SKY_DROPPED);
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
        gBattleMons[gActiveBattler].status2 |= STATUS2_POWDER;
        break;
    }
    case VARIOUS_ACUPRESSURE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        bits = 0;
        for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
        {
            if (CompareStat(gActiveBattler, i, MAX_STAT_STAGE, CMP_LESS_THAN))
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
        CancelMultiTurnMoves(gActiveBattler);
        break;
    }
    case VARIOUS_SET_MAGIC_COAT_TARGET:
    {
        VARIOUS_ARGS();
        gBattleStruct->attackerBeforeBounce = gActiveBattler;
        gBattlerAttacker = gBattlerTarget;
        side = BATTLE_OPPOSITE(GetBattlerSide(gBattlerAttacker));
        if (IsAffectedByFollowMe(gBattlerAttacker, side, gCurrentMove))
            gBattlerTarget = gSideTimers[side].followmeTarget;
        else
            gBattlerTarget = gActiveBattler;
        break;
    }
    case VARIOUS_IS_RUNNING_IMPOSSIBLE:
    {
        VARIOUS_ARGS();
        gBattleCommunication[0] = IsRunningFromBattleImpossible();
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
        if (gHitMarker & HITMARKER_FAINTED(gActiveBattler))
            gBattleCommunication[0] = TRUE;
        else
            gBattleCommunication[0] = FALSE;
        break;
    }
    case VARIOUS_RESET_SWITCH_IN_ABILITY_BITS:
    {
        VARIOUS_ARGS();
        gSpecialStatuses[gActiveBattler].traced = FALSE;
        gSpecialStatuses[gActiveBattler].switchInAbilityDone = FALSE;
        break;
    }
    case VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP:
    {
        VARIOUS_ARGS();
        if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterMonId || gBattlerPartyIndexes[2] == gBattleStruct->expGetterMonId)
        {
            if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterMonId)
                gActiveBattler = 0;
            else
                gActiveBattler = 2;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gBattleMons[gActiveBattler].moves[i] == gBattleStruct->choicedMove[gActiveBattler])
                    break;
            }
            if (i == MAX_MON_MOVES)
                gBattleStruct->choicedMove[gActiveBattler] = MOVE_NONE;
        }
        break;
    }
    case VARIOUS_RESET_PLAYER_FAINTED:
    {
        VARIOUS_ARGS();
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_DOUBLE))
            && gBattleTypeFlags & BATTLE_TYPE_TRAINER
            && gBattleMons[0].hp != 0
            && gBattleMons[1].hp != 0)
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
        gBattleScripting.battler = gActiveBattler = gBattleCommunication[1];
        if (!(gBattleStruct->palaceFlags & gBitTable[gActiveBattler])
            && gBattleMons[gActiveBattler].maxHP / 2 >= gBattleMons[gActiveBattler].hp
            && gBattleMons[gActiveBattler].hp != 0
            && !(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP))
        {
            gBattleStruct->palaceFlags |= gBitTable[gActiveBattler];
            gBattleCommunication[0] = TRUE;
            gBattleCommunication[MULTISTRING_CHOOSER] = sBattlePalaceNatureToFlavorTextId[GetNatureFromPersonality(gBattleMons[gActiveBattler].personality)];
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
        BtlController_EmitYesNoBox(BUFFER_A);
        MarkBattlerForControllerExec(gActiveBattler);
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
        gActiveBattler = 1;
        if (gBattleMons[gActiveBattler].hp != 0)
        {
            BtlController_EmitReturnMonToBall(BUFFER_A, FALSE);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        break;
    }
    case VARIOUS_RETURN_OPPONENT_MON2:
    {
        VARIOUS_ARGS();
        if (gBattlersCount > 3)
        {
            gActiveBattler = 3;
            if (gBattleMons[gActiveBattler].hp != 0)
            {
                BtlController_EmitReturnMonToBall(BUFFER_A, FALSE);
                MarkBattlerForControllerExec(gActiveBattler);
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
        gBattleStruct->alreadyStatusedMoveAttempt |= gBitTable[gActiveBattler];
        break;
    }
    case VARIOUS_PALACE_TRY_ESCAPE_STATUS:
    {
        VARIOUS_ARGS();
        if (BattlePalace_TryEscapeStatus(gActiveBattler))
            return;
        break;
    }
    case VARIOUS_SET_TELEPORT_OUTCOME:
    {
        VARIOUS_ARGS();
        // Don't end the battle if one of the wild mons teleported from the wild double battle
        // and its partner is still alive.
        if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT && IsBattlerAlive(BATTLE_PARTNER(gActiveBattler)))
        {
            gAbsentBattlerFlags |= gBitTable[gActiveBattler];
            gHitMarker |= HITMARKER_FAINTED(gActiveBattler);
            gBattleMons[gActiveBattler].hp = 0;
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_HP, &gBattleMons[gActiveBattler].hp);
            SetHealthboxSpriteInvisible(gHealthboxSpriteIds[gActiveBattler]);
            FaintClearSetData();
        }
        else if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
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
        BtlController_EmitPlayFanfareOrBGM(BUFFER_A, MUS_VICTORY_TRAINER, TRUE);
        MarkBattlerForControllerExec(gActiveBattler);
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
        AbilityBattleEffects(ABILITYEFFECT_NEUTRALIZINGGAS, gActiveBattler, 0, 0, 0);
        AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, gActiveBattler, 0, 0, 0);
        AbilityBattleEffects(ABILITYEFFECT_TRACE2, gActiveBattler, 0, 0, 0);
        return;
    }
    case VARIOUS_SAVE_TARGET:
    {
        VARIOUS_ARGS();
        gBattleStruct->savedBattlerTarget = gBattlerTarget;
        break;
    }
    case VARIOUS_RESTORE_TARGET:
    {
        VARIOUS_ARGS();
        gBattlerTarget = gBattleStruct->savedBattlerTarget;
        break;
    }
    case VARIOUS_INSTANT_HP_DROP:
    {
        VARIOUS_ARGS();
        BtlController_EmitHealthBarUpdate(BUFFER_A, INSTANT_HP_BAR_DROP);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    }
    case VARIOUS_CLEAR_STATUS:
    {
        VARIOUS_ARGS();
        gBattleMons[gActiveBattler].status1 = 0;
        BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    }
    case VARIOUS_RESTORE_PP:
    {
        VARIOUS_ARGS();
        for (i = 0; i < 4; i++)
        {
            gBattleMons[gActiveBattler].pp[i] = CalculatePPWithBonus(gBattleMons[gActiveBattler].moves[i], gBattleMons[gActiveBattler].ppBonuses, i);
            data[i] = gBattleMons[gActiveBattler].pp[i];
        }
        data[i] = gBattleMons[gActiveBattler].ppBonuses;
        BtlController_EmitSetMonData(BUFFER_A, REQUEST_PP_DATA_BATTLE, 0, 5, data);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    }
    case VARIOUS_TRY_ACTIVATE_MOXIE:    // and chilling neigh + as one ice rider
    {
        VARIOUS_ARGS();

        u16 battlerAbility = GetBattlerAbility(gActiveBattler);

        if ((battlerAbility == ABILITY_MOXIE
         || battlerAbility == ABILITY_CHILLING_NEIGH
         || battlerAbility == ABILITY_AS_ONE_ICE_RIDER)
          && HasAttackerFaintedTarget()
          && !NoAliveMonsForEitherParty()
          && CompareStat(gBattlerAttacker, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
        {
            gBattleMons[gBattlerAttacker].statStages[STAT_ATK]++;
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

        u16 battlerAbility = GetBattlerAbility(gActiveBattler);

        if ((battlerAbility == ABILITY_GRIM_NEIGH
         || battlerAbility == ABILITY_AS_ONE_SHADOW_RIDER)
          && HasAttackerFaintedTarget()
          && !NoAliveMonsForEitherParty()
          && CompareStat(gBattlerAttacker, STAT_SPATK, MAX_STAT_STAGE, CMP_LESS_THAN))
        {
            gBattleMons[gBattlerAttacker].statStages[STAT_SPATK]++;
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
        gBattlerAbility = BATTLE_PARTNER(gActiveBattler);
        i = GetBattlerAbility(gBattlerAbility);
        if (IsBattlerAlive(gBattlerAbility)
            && (i == ABILITY_RECEIVER || i == ABILITY_POWER_OF_ALCHEMY)
            && GetBattlerHoldEffect(gActiveBattler, TRUE) != HOLD_EFFECT_ABILITY_SHIELD)
        {
            switch (gBattleMons[gActiveBattler].ability)
            { // Can't copy these abilities.
            case ABILITY_POWER_OF_ALCHEMY:  case ABILITY_RECEIVER:
            case ABILITY_FORECAST:          case ABILITY_MULTITYPE:
            case ABILITY_FLOWER_GIFT:       case ABILITY_ILLUSION:
            case ABILITY_WONDER_GUARD:      case ABILITY_ZEN_MODE:
            case ABILITY_STANCE_CHANGE:     case ABILITY_IMPOSTER:
            case ABILITY_POWER_CONSTRUCT:   case ABILITY_BATTLE_BOND:
            case ABILITY_SCHOOLING:         case ABILITY_COMATOSE:
            case ABILITY_SHIELDS_DOWN:      case ABILITY_DISGUISE:
            case ABILITY_RKS_SYSTEM:        case ABILITY_TRACE:
                break;
            default:
                gBattleStruct->tracedAbility[gBattlerAbility] = gBattleMons[gActiveBattler].ability; // re-using the variable for trace
                gBattleScripting.battler = gActiveBattler;
                BattleScriptPush(cmd->nextInstr);
                gBattlescriptCurrInstr = BattleScript_ReceiverActivates;
                return;
            }
        }
        break;
    }
    case VARIOUS_TRY_ACTIVATE_BEAST_BOOST:
    {
        VARIOUS_ARGS();
        i = GetHighestStatId(gActiveBattler);
        if (GetBattlerAbility(gActiveBattler) == ABILITY_BEAST_BOOST
            && HasAttackerFaintedTarget()
            && !NoAliveMonsForEitherParty()
            && CompareStat(gBattlerAttacker, i, MAX_STAT_STAGE, CMP_LESS_THAN))
        {
            gBattleMons[gBattlerAttacker].statStages[i]++;
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
                gBattleMons[gBattleScripting.battler].statStages[STAT_SPATK]++;
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
        if (gBattleMoves[gCurrentMove].effect == EFFECT_FELL_STINGER
            && HasAttackerFaintedTarget()
            && !NoAliveMonsForEitherParty()
            && CompareStat(gBattlerAttacker, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN))
        {
        #if B_FELL_STINGER_STAT_RAISE >= GEN_7
            SET_STATCHANGER(STAT_ATK, 3, FALSE);
        #else
            SET_STATCHANGER(STAT_ATK, 2, FALSE);
        #endif
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
        BtlController_EmitMoveAnimation(BUFFER_A, cmd->move, gBattleScripting.animTurn, 0, 0, gBattleMons[gActiveBattler].friendship, &gDisableStructs[gActiveBattler], gMultiHitCounter);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_SET_LUCKY_CHANT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (!(gSideStatuses[GET_BATTLER_SIDE(gActiveBattler)] & SIDE_STATUS_LUCKY_CHANT))
        {
            gSideStatuses[GET_BATTLER_SIDE(gActiveBattler)] |= SIDE_STATUS_LUCKY_CHANT;
            gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].luckyChantBattlerId = gActiveBattler;
            gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].luckyChantTimer = 5;
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
        if (IsEntrainmentTargetOrSimpleBeamBannedAbility(gBattleMons[gBattlerTarget].ability)
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
        if (IsEntrainmentBannedAbilityAttacker(gBattleMons[gBattlerAttacker].ability)
          || IsEntrainmentTargetOrSimpleBeamBannedAbility(gBattleMons[gBattlerTarget].ability))
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
            if (gBattleMons[gBattlerTarget].ability == gBattleMons[gBattlerAttacker].ability)
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
        gLastUsedAbility = gBattleMons[gActiveBattler].ability;
        break;
    }
    case VARIOUS_TRY_HEAL_PULSE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (BATTLER_MAX_HP(gActiveBattler))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            if (GetBattlerAbility(gBattlerAttacker) == ABILITY_MEGA_LAUNCHER && gBattleMoves[gCurrentMove].flags & FLAG_MEGA_LAUNCHER_BOOST)
                gBattleMoveDamage = -(gBattleMons[gActiveBattler].maxHP * 75 / 100);
            else
                gBattleMoveDamage = -(gBattleMons[gActiveBattler].maxHP / 2);

            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = -1;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_QUASH:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget)) // It's true if foe is faster, has a bigger priority, or switches
        {
            gBattlescriptCurrInstr = cmd->failInstr; // This replaces the current battlescript with the "fail" script.
        }
        else // If the condition is not true, it means we are faster than the foe, so we can set the quash bit
        {
            gProtectStructs[gBattlerTarget].quash = TRUE;
            gBattlescriptCurrInstr = cmd->nextInstr; // and then we proceed with the rest of our battlescript
        }
        return;
    }
    case VARIOUS_INVERT_STAT_STAGES:
    {
        VARIOUS_ARGS();
        for (i = 0; i < NUM_BATTLE_STATS; i++)
        {
            if (gBattleMons[gActiveBattler].statStages[i] < DEFAULT_STAT_STAGE) // Negative becomes positive.
                gBattleMons[gActiveBattler].statStages[i] = DEFAULT_STAT_STAGE + (DEFAULT_STAT_STAGE - gBattleMons[gActiveBattler].statStages[i]);
            else if (gBattleMons[gActiveBattler].statStages[i] > DEFAULT_STAT_STAGE) // Positive becomes negative.
                gBattleMons[gActiveBattler].statStages[i] = DEFAULT_STAT_STAGE - (gBattleMons[gActiveBattler].statStages[i] - DEFAULT_STAT_STAGE);
        }
        break;
    }
    case VARIOUS_SET_TERRAIN:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        HandleTerrainMove(gCurrentMove);
        return;
    }
    case VARIOUS_TRY_ME_FIRST:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
            gBattlescriptCurrInstr = cmd->failInstr;
        else if (IS_MOVE_STATUS(gBattleMons[gBattlerTarget].moves[gBattleStruct->chosenMovePositions[gBattlerTarget]]))
            gBattlescriptCurrInstr = cmd->failInstr;
        else
        {
            u16 move = gBattleMons[gBattlerTarget].moves[gBattleStruct->chosenMovePositions[gBattlerTarget]];
            switch (move)
            {
            case MOVE_STRUGGLE:
            case MOVE_CHATTER:
            case MOVE_FOCUS_PUNCH:
            case MOVE_THIEF:
            case MOVE_COVET:
            case MOVE_COUNTER:
            case MOVE_MIRROR_COAT:
            case MOVE_METAL_BURST:
            case MOVE_ME_FIRST:
            case MOVE_BEAK_BLAST:
                gBattlescriptCurrInstr = cmd->failInstr;
                break;
            default:
                gCalledMove = move;
                gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
                gBattlerTarget = GetMoveTarget(gCalledMove, NO_TARGET_OVERRIDE);
                gStatuses3[gBattlerAttacker] |= STATUS3_ME_FIRST;
                gBattlescriptCurrInstr = cmd->nextInstr;
                break;
            }
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
    case VARIOUS_TRY_REFLECT_TYPE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gBattleMons[gBattlerTarget].species == SPECIES_ARCEUS || gBattleMons[gBattlerTarget].species == SPECIES_SILVALLY)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else if (gBattleMons[gBattlerTarget].type1 == TYPE_MYSTERY && gBattleMons[gBattlerTarget].type2 != TYPE_MYSTERY)
        {
            gBattleMons[gBattlerAttacker].type1 = gBattleMons[gBattlerTarget].type2;
            gBattleMons[gBattlerAttacker].type2 = gBattleMons[gBattlerTarget].type2;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else if (gBattleMons[gBattlerTarget].type1 != TYPE_MYSTERY && gBattleMons[gBattlerTarget].type2 == TYPE_MYSTERY)
        {
            gBattleMons[gBattlerAttacker].type1 = gBattleMons[gBattlerTarget].type1;
            gBattleMons[gBattlerAttacker].type2 = gBattleMons[gBattlerTarget].type1;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else if (gBattleMons[gBattlerTarget].type1 == TYPE_MYSTERY && gBattleMons[gBattlerTarget].type2 == TYPE_MYSTERY)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gBattleMons[gBattlerAttacker].type1 = gBattleMons[gBattlerTarget].type1;
            gBattleMons[gBattlerAttacker].type2 = gBattleMons[gBattlerTarget].type2;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_SOAK:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gBattleMons[gBattlerTarget].type1 == gBattleMoves[gCurrentMove].type
            && gBattleMons[gBattlerTarget].type2 == gBattleMoves[gCurrentMove].type)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            SET_BATTLER_TYPE(gBattlerTarget, gBattleMoves[gCurrentMove].type);
            PREPARE_TYPE_BUFFER(gBattleTextBuff1, gBattleMoves[gCurrentMove].type);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_HANDLE_MEGA_EVO:
    {
        VARIOUS_ARGS(u8 case_);
        HandleScriptMegaPrimal(cmd->case_, gActiveBattler, TRUE);
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_HANDLE_PRIMAL_REVERSION:
    {
        VARIOUS_ARGS(u8 case_);
        HandleScriptMegaPrimal(cmd->case_, gActiveBattler, FALSE);
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_HANDLE_FORM_CHANGE:
    {
        VARIOUS_ARGS(u8 case_);
        if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT)
            mon = &gEnemyParty[gBattlerPartyIndexes[gActiveBattler]];
        else
            mon = &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]];

        // Change species.
        if (cmd->case_ == 0)
        {
            if (!gBattleTextBuff1)
                PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gActiveBattler].species);
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_SPECIES_BATTLE, gBitTable[gBattlerPartyIndexes[gActiveBattler]], sizeof(gBattleMons[gActiveBattler].species), &gBattleMons[gActiveBattler].species);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        // Change stats.
        else if (cmd->case_ == 1)
        {
            RecalcBattlerStats(gActiveBattler, mon);
        }
        // Update healthbox.
        else
        {
            UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], mon, HEALTHBOX_ALL);
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_LAST_RESORT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (CanUseLastResort(gActiveBattler))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->failInstr;
        return;
    }
    case VARIOUS_ARGUMENT_STATUS_EFFECT:
    {
        VARIOUS_ARGS();
        switch (gBattleMoves[gCurrentMove].argument)
        {
        case STATUS1_SLEEP:
            gBattleScripting.moveEffect = MOVE_EFFECT_SLEEP;
            break;
        case STATUS1_BURN:
            gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
            break;
        case STATUS1_FREEZE:
            gBattleScripting.moveEffect = MOVE_EFFECT_FREEZE;
            break;
        case STATUS1_PARALYSIS:
            gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
            break;
        case STATUS1_POISON:
            gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
            break;
        case STATUS1_TOXIC_POISON:
            gBattleScripting.moveEffect = MOVE_EFFECT_TOXIC;
            break;
        case STATUS1_FROSTBITE:
            gBattleScripting.moveEffect = MOVE_EFFECT_FROSTBITE;
            break;
        default:
            gBattleScripting.moveEffect = 0;
            break;
        }
        if (gBattleScripting.moveEffect != 0)
        {
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = BattleScript_EffectWithChance;
            return;
        }
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
        if (GetBattlerWeight(gActiveBattler) > 1)
        {
            gDisableStructs[gActiveBattler].autotomizeCount++;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
    }
    case VARIOUS_TRY_COPYCAT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gLastUsedMove == 0xFFFF || (sForbiddenMoves[gLastUsedMove] & FORBIDDEN_COPYCAT))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gCalledMove = gLastUsedMove;
            gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
            gBattlerTarget = GetMoveTarget(gCalledMove, NO_TARGET_OVERRIDE);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_INSTRUCT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if ((sForbiddenMoves[gLastMoves[gBattlerTarget]] & FORBIDDEN_INSTRUCT)
            || gLastMoves[gBattlerTarget] == 0xFFFF)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gSpecialStatuses[gBattlerTarget].instructedChosenTarget = *(gBattleStruct->moveTarget + gBattlerTarget) | 0x4;
            gBattlerAttacker = gBattlerTarget;
            gCalledMove = gLastMoves[gBattlerAttacker];
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gBattleMons[gBattlerAttacker].moves[i] == gCalledMove)
                {
                    gCurrMovePos = i;
                    i = 4;
                    break;
                }
            }
            if (i != 4 || gBattleMons[gBattlerAttacker].pp[gCurrMovePos] == 0)
                gBattlescriptCurrInstr = cmd->failInstr;
            else
            {
                gBattlerTarget = gBattleStruct->lastMoveTarget[gBattlerAttacker];
                gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
                PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gActiveBattler, gBattlerPartyIndexes[gActiveBattler]);
                gBattlescriptCurrInstr = cmd->nextInstr;
            }
        }
        return;
    }
    case VARIOUS_ABILITY_POPUP:
    {
        VARIOUS_ARGS();
        CreateAbilityPopUp(gActiveBattler, gBattleMons[gActiveBattler].ability, (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) != 0);
        break;
    }
    case VARIOUS_UPDATE_ABILITY_POPUP:
    {
        VARIOUS_ARGS();
        UpdateAbilityPopup(gActiveBattler);
        break;
    }
    case VARIOUS_DEFOG:
    {
        VARIOUS_ARGS(bool8 clear, const u8 *failInstr);
        if (cmd->clear) // Clear
        {
            if (TryDefogClear(gEffectBattler, TRUE))
                return;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            if (TryDefogClear(gActiveBattler, FALSE))
                gBattlescriptCurrInstr = cmd->nextInstr;
            else
                gBattlescriptCurrInstr = cmd->failInstr;
        }
        return;
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
        for (i = 0; i < 3; i++)
        {
            if (*(u8 *)(&gBattleMons[gActiveBattler].type1 + i) == cmd->type)
                *(u8 *)(&gBattleMons[gActiveBattler].type1 + i) = TYPE_MYSTERY;
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_PSYCHO_SHIFT:
        {
            VARIOUS_ARGS(const u8 *failInstr);
            // Psycho shift works
            if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_POISON) && CanBePoisoned(gBattlerAttacker, gBattlerTarget))
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            else if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_TOXIC_POISON) && CanBePoisoned(gBattlerAttacker, gBattlerTarget))
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            else if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_BURN) && CanBeBurned(gBattlerTarget))
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            else if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_PARALYSIS) && CanBeParalyzed(gBattlerTarget))
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
            else if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP) && CanSleep(gBattlerTarget))
                gBattleCommunication[MULTISTRING_CHOOSER] = 4;
            else if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_FROSTBITE) && CanBeFrozen(gBattlerTarget))
                gBattleCommunication[MULTISTRING_CHOOSER] = 5;
            else
            {
                gBattlescriptCurrInstr = cmd->failInstr;
                return;
            }
            gBattleMons[gBattlerTarget].status1 = gBattleMons[gBattlerAttacker].status1 & STATUS1_ANY;
            gActiveBattler = gBattlerTarget;
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
            MarkBattlerForControllerExec(gActiveBattler);
            gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }
    case VARIOUS_CURE_STATUS:
    {
        VARIOUS_ARGS();
        gBattleMons[gActiveBattler].status1 = 0;
        BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    }
    case VARIOUS_POWER_TRICK:
    {
        VARIOUS_ARGS();
        gStatuses3[gActiveBattler] ^= STATUS3_POWER_TRICK;
        SWAP(gBattleMons[gActiveBattler].attack, gBattleMons[gActiveBattler].defense, i);
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
            || !CanBattlerGetOrLoseItem(gBattlerTarget, gBattleMons[gBattlerAttacker].item))
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
    case VARIOUS_ARGUMENT_TO_MOVE_EFFECT:
    {
        VARIOUS_ARGS();
        gBattleScripting.moveEffect = gBattleMoves[gCurrentMove].argument;
        break;
    }
    case VARIOUS_JUMP_IF_NOT_GROUNDED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (!IsBattlerGrounded(gActiveBattler))
            gBattlescriptCurrInstr = gBattlescriptCurrInstr = cmd->jumpInstr;
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
            gBattleScripting.savedDmg = (gBattlerSpriteIds[gActiveBattler] & 0xFF) | (gBattlerSpriteIds[BATTLE_PARTNER(gActiveBattler)] << 8);
            HideBattlerShadowSprite(gActiveBattler);
        }
        else if (cmd->case_ == 1)
        {
            BtlController_EmitPrintString(BUFFER_A, STRINGID_TRAINERSLIDE);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        else
        {
            gBattlerSpriteIds[BATTLE_PARTNER(gActiveBattler)] = gBattleScripting.savedDmg >> 8;
            gBattlerSpriteIds[gActiveBattler] = gBattleScripting.savedDmg & 0xFF;
            if (IsBattlerAlive(gActiveBattler))
            {
                SetBattlerShadowSpriteCallback(gActiveBattler, gBattleMons[gActiveBattler].species);
                BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);
            }
            i = BATTLE_PARTNER(gActiveBattler);
            if (IsBattlerAlive(i))
            {
                SetBattlerShadowSpriteCallback(i, gBattleMons[i].species);
                BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[i]], i);
            }
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF:
    {
        VARIOUS_ARGS();
        if ((i = ShouldDoTrainerSlide(gActiveBattler, TRAINER_SLIDE_FIRST_DOWN)))
        {
            gBattleScripting.battler = gActiveBattler;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = (i == 1 ? BattleScript_TrainerASlideMsgRet : BattleScript_TrainerBSlideMsgRet);
            return;
        }
        break;
    }
    case VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON:
    {
        VARIOUS_ARGS();
        if ((i = ShouldDoTrainerSlide(gActiveBattler, TRAINER_SLIDE_LAST_SWITCHIN)))
        {
            gBattleScripting.battler = gActiveBattler;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = (i == 1 ? BattleScript_TrainerASlideMsgRet : BattleScript_TrainerBSlideMsgRet);
            return;
        }
        break;
    }
    case VARIOUS_SET_AURORA_VEIL:
    {
        VARIOUS_ARGS();
        if (gSideStatuses[GET_BATTLER_SIDE(gActiveBattler)] & SIDE_STATUS_AURORA_VEIL
            || !(WEATHER_HAS_EFFECT && gBattleWeather & (B_WEATHER_HAIL | B_WEATHER_SNOW)))
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        }
        else
        {
            gSideStatuses[GET_BATTLER_SIDE(gActiveBattler)] |= SIDE_STATUS_AURORA_VEIL;
            if (GetBattlerHoldEffect(gActiveBattler, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
                gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].auroraVeilTimer = 8;
            else
                gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].auroraVeilTimer = 5;
            gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].auroraVeilBattlerId = gActiveBattler;

            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMonsInBattle(BATTLE_ALIVE_ATK_SIDE) == 2)
                gBattleCommunication[MULTISTRING_CHOOSER] = 5;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 5;
        }
        break;
    }
    case VARIOUS_TRY_THIRD_TYPE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (IS_BATTLER_OF_TYPE(gActiveBattler, gBattleMoves[gCurrentMove].argument))
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gBattleMons[gActiveBattler].type3 = gBattleMoves[gCurrentMove].argument;
            PREPARE_TYPE_BUFFER(gBattleTextBuff1, gBattleMoves[gCurrentMove].argument);
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_DESTROY_ABILITY_POPUP:
    {
        VARIOUS_ARGS();
        DestroyAbilityPopUp(gActiveBattler);
        break;
    }
    case VARIOUS_TOTEM_BOOST:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        gActiveBattler = gBattlerAttacker;
        if (gTotemBoosts[gActiveBattler].stats == 0)
        {
            gBattlescriptCurrInstr = cmd->nextInstr;    // stats done, exit
        }
        else
        {
            for (i = 0; i < (NUM_BATTLE_STATS - 1); i++)
            {
                if (gTotemBoosts[gActiveBattler].stats & (1 << i))
                {
                    if (gTotemBoosts[gActiveBattler].statChanges[i] <= -1)
                        SET_STATCHANGER(i + 1, abs(gTotemBoosts[gActiveBattler].statChanges[i]), TRUE);
                    else
                        SET_STATCHANGER(i + 1, gTotemBoosts[gActiveBattler].statChanges[i], FALSE);

                    gTotemBoosts[gActiveBattler].stats &= ~(1 << i);
                    gBattleScripting.battler = gActiveBattler;
                    gBattlerTarget = gActiveBattler;
                    if (gTotemBoosts[gActiveBattler].stats & 0x80)
                    {
                        gTotemBoosts[gActiveBattler].stats &= ~0x80; // set 'aura flared to life' flag
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
    case VARIOUS_SET_Z_EFFECT:
    {
        VARIOUS_ARGS();
        SetZEffect();   //handles battle script jumping internally
        return;
    }
    case VARIOUS_MOVEEND_ITEM_EFFECTS:
    {
        VARIOUS_ARGS();
        if (ItemBattleEffects(ITEMEFFECT_NORMAL, gActiveBattler, FALSE))
            return;
        break;
    }
    case VARIOUS_ROOM_SERVICE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (GetBattlerHoldEffect(gActiveBattler, TRUE) == HOLD_EFFECT_ROOM_SERVICE && TryRoomService(gActiveBattler))
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
        if (GetBattlerHoldEffect(gActiveBattler, TRUE) == HOLD_EFFECT_SEEDS)
        {
            u8 effect = 0;
            u16 item = gBattleMons[gActiveBattler].item;
            switch (GetBattlerHoldEffectParam(gActiveBattler))
            {
            case HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN:
                effect = TryHandleSeed(gActiveBattler, STATUS_FIELD_ELECTRIC_TERRAIN, STAT_DEF, item, FALSE);
                break;
            case HOLD_EFFECT_PARAM_GRASSY_TERRAIN:
                effect = TryHandleSeed(gActiveBattler, STATUS_FIELD_GRASSY_TERRAIN, STAT_DEF, item, FALSE);
                break;
            case HOLD_EFFECT_PARAM_MISTY_TERRAIN:
                effect = TryHandleSeed(gActiveBattler, STATUS_FIELD_MISTY_TERRAIN, STAT_SPDEF, item, FALSE);
                break;
            case HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN:
                effect = TryHandleSeed(gActiveBattler, STATUS_FIELD_PSYCHIC_TERRAIN, STAT_SPDEF, item, FALSE);
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

        BtlController_EmitSpriteInvisibility(BUFFER_A, TRUE);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    }
    case VARIOUS_JUMP_IF_TERRAIN_AFFECTED:
        {
            VARIOUS_ARGS(u32 flags, const u8 *jumpInstr);
            u32 flags = cmd->flags;
            if (IsBattlerTerrainAffected(gActiveBattler, flags))
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }
    case VARIOUS_EERIE_SPELL_PP_REDUCE:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gLastMoves[gActiveBattler] != 0 && gLastMoves[gActiveBattler] != 0xFFFF)
        {
            s32 i;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gLastMoves[gActiveBattler] == gBattleMons[gActiveBattler].moves[i])
                    break;
            }

            if (i != MAX_MON_MOVES && gBattleMons[gActiveBattler].pp[i] != 0)
            {
                s32 ppToDeduct = 3;

                if (gBattleMons[gActiveBattler].pp[i] < ppToDeduct)
                    ppToDeduct = gBattleMons[gActiveBattler].pp[i];

                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastMoves[gActiveBattler])
                ConvertIntToDecimalStringN(gBattleTextBuff2, ppToDeduct, STR_CONV_MODE_LEFT_ALIGN, 1);
                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 1, ppToDeduct)
                gBattleMons[gActiveBattler].pp[i] -= ppToDeduct;
                if (!(gDisableStructs[gActiveBattler].mimickedMoves & gBitTable[i])
                    && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
                {
                    BtlController_EmitSetMonData(BUFFER_A, REQUEST_PPMOVE1_BATTLE + i, 0, sizeof(gBattleMons[gActiveBattler].pp[i]), &gBattleMons[gActiveBattler].pp[i]);
                    MarkBattlerForControllerExec(gActiveBattler);
                }

                if (gBattleMons[gActiveBattler].pp[i] == 0 && gBattleStruct->skyDropTargets[gActiveBattler] == 0xFF)
                    CancelMultiTurnMoves(gActiveBattler);

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
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && IsBattlerAlive(BATTLE_PARTNER(gActiveBattler)))
        {
            u8 partner = BATTLE_PARTNER(gActiveBattler);
            if ((gBattleMons[gActiveBattler].hp == gBattleMons[gActiveBattler].maxHP && !(gBattleMons[gActiveBattler].status1 & STATUS1_ANY))
             && (gBattleMons[partner].hp == gBattleMons[partner].maxHP && !(gBattleMons[partner].status1 & STATUS1_ANY)))
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else // single battle
        {
            if (gBattleMons[gActiveBattler].hp == gBattleMons[gActiveBattler].maxHP && !(gBattleMons[gActiveBattler].status1 & STATUS1_ANY))
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_HEAL_QUARTER_HP:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 4;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        if (gBattleMons[gActiveBattler].hp == gBattleMons[gActiveBattler].maxHP)
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
        if (BlocksPrankster(gCurrentMove, gBattlerAttacker, gActiveBattler, TRUE))
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
            PrepareStringBattle(STRINGID_EXTREMESUNLIGHTFADED, gActiveBattler);
            gBattleCommunication[MSG_DISPLAY] = 1;
        }
        else if (gBattleWeather & B_WEATHER_RAIN_PRIMAL && !shouldNotClear)
        {
            gBattleWeather &= ~B_WEATHER_RAIN_PRIMAL;
            PrepareStringBattle(STRINGID_HEAVYRAINLIFTED, gActiveBattler);
            gBattleCommunication[MSG_DISPLAY] = 1;
        }
        else if (gBattleWeather & B_WEATHER_STRONG_WINDS && !shouldNotClear)
        {
            gBattleWeather &= ~B_WEATHER_STRONG_WINDS;
            PrepareStringBattle(STRINGID_STRONGWINDSDISSIPATED, gActiveBattler);
            gBattleCommunication[MSG_DISPLAY] = 1;
        }
        break;
    }
    case VARIOUS_TRY_END_NEUTRALIZING_GAS:
    {
        VARIOUS_ARGS();
        if (gSpecialStatuses[gActiveBattler].neutralizingGasRemoved)
        {
            gSpecialStatuses[gActiveBattler].neutralizingGasRemoved = FALSE;
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
        if (gSpecialStatuses[gActiveBattler].rototillerAffected)
        {
            gSpecialStatuses[gActiveBattler].rototillerAffected = FALSE;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        else
        {
            gBattlescriptCurrInstr = cmd->jumpInstr;   // Unaffected by rototiller - print STRINGID_NOEFFECTONTARGET
        }
        return;
    }
    case VARIOUS_TRY_ACTIVATE_BATTLE_BOND:
    {
        VARIOUS_ARGS();
        if (gBattleMons[gBattlerAttacker].species == SPECIES_GRENINJA_BATTLE_BOND
            && HasAttackerFaintedTarget()
            && CalculateEnemyPartyCount() > 1
            && !(gBattleStruct->battleBondTransformed[GET_BATTLER_SIDE2(gBattlerAttacker)] & gBitTable[gBattlerPartyIndexes[gBattlerAttacker]]))
        {
            gBattleStruct->battleBondTransformed[GET_BATTLER_SIDE2(gBattlerAttacker)] |= gBitTable[gBattlerPartyIndexes[gBattlerAttacker]];
            PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].species);
            gBattleStruct->changedSpecies[gBattlerPartyIndexes[gBattlerAttacker]] = gBattleMons[gBattlerAttacker].species;
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
            gLastUsedItem = gBattleMons[gActiveBattler].item;

        gBattleScripting.battler = gEffectBattler = gBattlerTarget = gActiveBattler;    // Cover all berry effect battlerId cases. e.g. ChangeStatBuffs uses target ID
        if (ItemBattleEffects(ITEMEFFECT_USE_LAST_ITEM, gActiveBattler, FALSE))
            return;
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_CANT_REVERT_TO_PRIMAL:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (GetBattleFormChangeTargetSpecies(gActiveBattler, FORM_CHANGE_BATTLE_PRIMAL_REVERSION) == SPECIES_NONE)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_WEATHER_AFFECTED:
        {
            VARIOUS_ARGS(u32 flags, const u8 *jumpInstr);
            u32 flags = cmd->flags;
            if (IsBattlerWeatherAffected(gActiveBattler, flags))
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
            return;
        }
    case VARIOUS_APPLY_PLASMA_FISTS:
    {
        VARIOUS_ARGS();
        for (i = 0; i < gBattlersCount; i++)
            gStatuses4[i] |= STATUS4_PLASMA_FISTS;
        break;
    }
    case VARIOUS_JUMP_IF_SPECIES:
    {
        VARIOUS_ARGS(u16 species, const u8 *jumpInstr);
        if (gBattleMons[gActiveBattler].species == cmd->species)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_PHOTON_GEYSER_CHECK:
    {
        VARIOUS_ARGS();
        gBattleStruct->swapDamageCategory = (GetSplitBasedOnStats(gActiveBattler) == SPLIT_SPECIAL);
        break;
    }
    case VARIOUS_SHELL_SIDE_ARM_CHECK: // 0% chance GameFreak actually checks this way according to DaWobblefet, but this is the only functional explanation at the moment
    {
        VARIOUS_ARGS();

        u32 attackerAtkStat = gBattleMons[gBattlerAttacker].attack;
        u32 targetDefStat = gBattleMons[gBattlerTarget].defense;
        u32 attackerSpAtkStat = gBattleMons[gBattlerAttacker].spAttack;
        u32 targetSpDefStat = gBattleMons[gBattlerTarget].spDefense;
        u8 statStage;
        u32 physical;
        u32 special;

        gBattleStruct->swapDamageCategory = FALSE;

        statStage = gBattleMons[gBattlerAttacker].statStages[STAT_ATK];
        attackerAtkStat *= gStatStageRatios[statStage][0];
        attackerAtkStat /= gStatStageRatios[statStage][1];

        statStage = gBattleMons[gBattlerTarget].statStages[STAT_DEF];
        targetDefStat *= gStatStageRatios[statStage][0];
        targetDefStat /= gStatStageRatios[statStage][1];

        physical = ((((2 * gBattleMons[gBattlerAttacker].level / 5 + 2) * gBattleMoves[gCurrentMove].power * attackerAtkStat) / targetDefStat) / 50);

        statStage = gBattleMons[gBattlerAttacker].statStages[STAT_SPATK];
        attackerSpAtkStat *= gStatStageRatios[statStage][0];
        attackerSpAtkStat /= gStatStageRatios[statStage][1];

        statStage = gBattleMons[gBattlerTarget].statStages[STAT_SPDEF];
        targetSpDefStat *= gStatStageRatios[statStage][0];
        targetSpDefStat /= gStatStageRatios[statStage][1];

        special = ((((2 * gBattleMons[gBattlerAttacker].level / 5 + 2) * gBattleMoves[gCurrentMove].power * attackerSpAtkStat) / targetSpDefStat) / 50);

        if (((physical > special) || (physical == special && (Random() % 2) == 0)))
            gBattleStruct->swapDamageCategory = TRUE;
        break;
    }
    case VARIOUS_JUMP_IF_LEAF_GUARD_PROTECTED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (IsLeafGuardProtected(gActiveBattler))
        {
            gBattlerAbility = gActiveBattler;
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
        if (gBattleStruct->stickyWebUser != 0xFF)
            gBattlerAttacker = gBattleStruct->stickyWebUser;
        break;
    }
    case VARIOUS_CUT_1_3_HP_RAISE_STATS:
        {
            VARIOUS_ARGS(const u8 *failInstr);

            bool8 atLeastOneStatBoosted = FALSE;
            u16 hpFraction = max(1, gBattleMons[gBattlerAttacker].maxHP / 3);

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
    case VARIOUS_SET_OCTOLOCK:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gDisableStructs[gActiveBattler].octolock)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gDisableStructs[gActiveBattler].octolock = TRUE;
            gBattleMons[gActiveBattler].status2 |= STATUS2_ESCAPE_PREVENTION;
            gDisableStructs[gActiveBattler].battlerPreventingEscape = gBattlerAttacker;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_CHECK_POLTERGEIST:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gBattleMons[gActiveBattler].item == ITEM_NONE
           || gFieldStatuses & STATUS_FIELD_MAGIC_ROOM
           || GetBattlerAbility(gActiveBattler) == ABILITY_KLUTZ)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            PREPARE_ITEM_BUFFER(gBattleTextBuff1, gBattleMons[gActiveBattler].item);
            gLastUsedItem = gBattleMons[gActiveBattler].item;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_NO_RETREAT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gDisableStructs[gActiveBattler].noRetreat)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            if (!(gBattleMons[gActiveBattler].status2 & STATUS2_ESCAPE_PREVENTION))
                gDisableStructs[gActiveBattler].noRetreat = TRUE;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_TRY_TAR_SHOT:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        if (gDisableStructs[gActiveBattler].tarShot)
        {
            gBattlescriptCurrInstr = cmd->failInstr;
        }
        else
        {
            gDisableStructs[gActiveBattler].tarShot = TRUE;
            gBattlescriptCurrInstr = cmd->nextInstr;
        }
        return;
    }
    case VARIOUS_CAN_TAR_SHOT_WORK:
    {
        VARIOUS_ARGS(const u8 *failInstr);
        // Tar Shot will fail if it's already been used on the target and its speed can't be lowered further
        if (!gDisableStructs[gActiveBattler].tarShot
            && CompareStat(gActiveBattler, STAT_SPEED, MAX_STAT_STAGE, CMP_LESS_THAN))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->failInstr;
        return;
    }
    case VARIOUS_JUMP_IF_CANT_FLING:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (!CanFling(gActiveBattler))
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_CURE_CERTAIN_STATUSES:
    {
        VARIOUS_ARGS();
        // Check infatuation
        if (gBattleMons[gActiveBattler].status2 & STATUS2_INFATUATION)
        {
            gBattleMons[gActiveBattler].status2 &= ~(STATUS2_INFATUATION);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_INFATUATION;  // STRINGID_TARGETGOTOVERINFATUATION
            StringCopy(gBattleTextBuff1, gStatusConditionString_LoveJpn);
        }
        // Check taunt
        if (gDisableStructs[gActiveBattler].tauntTimer != 0)
        {
            gDisableStructs[gActiveBattler].tauntTimer = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_TAUNT;
            PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_TAUNT);
        }
        // Check encore
        if (gDisableStructs[gActiveBattler].encoreTimer != 0)
        {
            gDisableStructs[gActiveBattler].encoredMove = 0;
            gDisableStructs[gActiveBattler].encoreTimer = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_ENCORE;   // STRINGID_PKMNENCOREENDED
        }
        // Check torment
        if (gBattleMons[gActiveBattler].status2 & STATUS2_TORMENT)
        {
            gBattleMons[gActiveBattler].status2 &= ~(STATUS2_TORMENT);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_TORMENT;
        }
        // Check heal block
        if (gStatuses3[gActiveBattler] & STATUS3_HEAL_BLOCK)
        {
            gStatuses3[gActiveBattler] &= ~(STATUS3_HEAL_BLOCK);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_HEALBLOCK;
        }
        // Check disable
        if (gDisableStructs[gActiveBattler].disableTimer != 0)
        {
            gDisableStructs[gActiveBattler].disableTimer = 0;
            gDisableStructs[gActiveBattler].disabledMove = 0;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MENTALHERBCURE_DISABLE;
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_RESET_NEGATIVE_STAT_STAGES:
    {
        VARIOUS_ARGS();
        gActiveBattler = gBattlerTarget;
        for (i = 0; i < NUM_BATTLE_STATS; i++)
            if (gBattleMons[gActiveBattler].statStages[i] < DEFAULT_STAT_STAGE)
                gBattleMons[gActiveBattler].statStages[i] = DEFAULT_STAT_STAGE;
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
        gBattleResources->battleHistory->heldItems[gActiveBattler] = gBattleMons[gActiveBattler].item;
        break;
    }
    case VARIOUS_RESTORE_BATTLER_ITEM:
    {
        VARIOUS_ARGS();
        gBattleMons[gActiveBattler].item = gBattleResources->battleHistory->heldItems[gActiveBattler];
        break;
    }
    case VARIOUS_BATTLER_ITEM_TO_LAST_USED_ITEM:
    {
        VARIOUS_ARGS();
        gBattleMons[gActiveBattler].item = gLastUsedItem;
        break;
    }
    case VARIOUS_SET_BEAK_BLAST:
    {
        VARIOUS_ARGS();
        gProtectStructs[gActiveBattler].beakBlastCharge = TRUE;
        break;
    }
    case VARIOUS_SWAP_SIDE_STATUSES:
    {
        VARIOUS_ARGS();
        CourtChangeSwapSideStatuses();
        break;
    }
    case VARIOUS_TRY_SYMBIOSIS: //called by Bestow, Fling, and Bug Bite, which don't work with Cmd_removeitem.
    {
        VARIOUS_ARGS();
        if (SYMBIOSIS_CHECK(gActiveBattler, BATTLE_PARTNER(gActiveBattler)))
        {
            BestowItem(BATTLE_PARTNER(gActiveBattler), gActiveBattler);
            gLastUsedAbility = gBattleMons[BATTLE_PARTNER(gActiveBattler)].ability;
            gBattleScripting.battler = gBattlerAbility = BATTLE_PARTNER(gActiveBattler);
            gBattlerAttacker = gActiveBattler;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_SymbiosisActivates;
            return;
        }
        break;
    }
    case VARIOUS_CAN_TELEPORT:
    {
        VARIOUS_ARGS();
        gBattleCommunication[0] = CanTeleport(gActiveBattler);
        break;
    }
    case VARIOUS_GET_BATTLER_SIDE:
    {
        VARIOUS_ARGS();
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            gBattleCommunication[0] = B_SIDE_PLAYER;
        else
            gBattleCommunication[0] = B_SIDE_OPPONENT;
        break;
    }
    case VARIOUS_CHECK_PARENTAL_BOND_COUNTER:
        {
            VARIOUS_ARGS(u8 counter, const u8 *jumpInstr);
            // Some effects should only happen on the first or second strike of Parental Bond,
            // so a way to check this in battle scripts is useful
            u8 counter = cmd->counter;
            if (gSpecialStatuses[gBattlerAttacker].parentalBondState == counter && gBattleMons[gBattlerTarget].hp != 0)
                gBattlescriptCurrInstr = cmd->jumpInstr;
            else
                gBattlescriptCurrInstr = cmd->nextInstr;
            return;
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
        if (ItemId_GetPocket(gBattleMons[gActiveBattler].item) == POCKET_BERRIES && !(gStatuses3[gBattlerTarget] & (STATUS3_SEMI_INVULNERABLE)))
            gBattlescriptCurrInstr = cmd->nextInstr;
        else
            gBattlescriptCurrInstr = cmd->jumpInstr;
        return;
    }
    case VARIOUS_JUMP_IF_ROD:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (IsAbilityRodAffected())
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_MOTOR:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (IsAbilityMotorAffected())
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_ABSORB:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (IsAbilityAbsorbAffected())
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_TRY_WIND_RIDER_POWER:
        {
            VARIOUS_ARGS(const u8 *failInstr);
            u16 ability = GetBattlerAbility(gActiveBattler);
            if (GetBattlerSide(gActiveBattler) == GetBattlerSide(gBattlerAttacker)
             && (ability == ABILITY_WIND_RIDER || ability == ABILITY_WIND_POWER))
            {
                gLastUsedAbility = ability;
                RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
                gBattlerAbility = gBattleScripting.battler = gActiveBattler;
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
        AbilityBattleEffects(ABILITYEFFECT_ON_WEATHER, gActiveBattler, 0, 0, 0);
        return;
    }
    case VARIOUS_ACTIVATE_TERRAIN_CHANGE_ABILITIES:
    {
        VARIOUS_ARGS();
        gBattlescriptCurrInstr = cmd->nextInstr;
        AbilityBattleEffects(ABILITYEFFECT_ON_TERRAIN, gActiveBattler, 0, 0, 0);
        return;
    }
    case VARIOUS_JUMP_IF_EMERGENCY_EXITED:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (gSpecialStatuses[gActiveBattler].emergencyExited)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
            gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_STORE_HEALING_WISH:
    {
        VARIOUS_ARGS();
        if (gCurrentMove == MOVE_LUNAR_DANCE)
            gBattleStruct->storedLunarDance |= gBitTable[gActiveBattler];
        else
            gBattleStruct->storedHealingWish |= gBitTable[gActiveBattler];
        break;
    }
    case VARIOUS_HIT_SWITCH_TARGET_FAILED:
    {
        VARIOUS_ARGS();
        gBattleStruct->hitSwitchTargetFailed = TRUE;
        gBattlescriptCurrInstr = cmd->nextInstr;
        return;
    }
    case VARIOUS_JUMP_IF_SHELL_TRAP:
    {
        VARIOUS_ARGS(const u8 *jumpInstr);
        if (gProtectStructs[gActiveBattler].shellTrap)
            gBattlescriptCurrInstr = cmd->jumpInstr;
        else
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
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_HP_BATTLE, gBitTable[gSelectedMonPartyId], sizeof(hp), &hp);
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
            BtlController_EmitChoosePokemon(BUFFER_A, PARTY_ACTION_CHOOSE_FAINTED_MON, PARTY_SIZE, ABILITY_NONE, gBattleStruct->battlerPartyOrders[gBattlerAttacker]);
            MarkBattlerForControllerExec(gBattlerAttacker);
        }
        return;
    }
    case VARIOUS_TRY_TRAINER_SLIDE_MSG_Z_MOVE:
    {
        VARIOUS_ARGS();
        if ((i = ShouldDoTrainerSlide(gActiveBattler, TRAINER_SLIDE_Z_MOVE)))
        {
            gBattleScripting.battler = gActiveBattler;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = (i == 1 ? BattleScript_TrainerASlideMsgRet : BattleScript_TrainerBSlideMsgRet);
            return;
        }
        break;
    }
    case VARIOUS_TRY_TRAINER_SLIDE_MSG_MEGA_EVOLUTION:
    {
        VARIOUS_ARGS();
        if ((i = ShouldDoTrainerSlide(gActiveBattler, TRAINER_SLIDE_MEGA_EVOLUTION)))
        {
            gBattleScripting.battler = gActiveBattler;
            BattleScriptPush(cmd->nextInstr);
            gBattlescriptCurrInstr = (i == 1 ? BattleScript_TrainerASlideMsgRet : BattleScript_TrainerBSlideMsgRet);
            return;
        }
        break;
    }
    } // End of switch (cmd->id)

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setprotectlike(void)
{
    CMD_ARGS();

    bool32 fail = TRUE;
    bool32 notLastTurn = TRUE;

    if (!(gBattleMoves[gLastResultingMoves[gBattlerAttacker]].flags & FLAG_PROTECTION_MOVE))
        gDisableStructs[gBattlerAttacker].protectUses = 0;

    if (gCurrentTurnActionNumber == (gBattlersCount - 1))
        notLastTurn = FALSE;

    if (sProtectSuccessRates[gDisableStructs[gBattlerAttacker].protectUses] >= Random() && notLastTurn)
    {
        if (!gBattleMoves[gCurrentMove].argument) // Protects one mon only.
        {
            if (gBattleMoves[gCurrentMove].effect == EFFECT_ENDURE)
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
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            }
            else if (gCurrentMove == MOVE_SILK_TRAP)
            {
                gProtectStructs[gBattlerAttacker].silkTrapped = TRUE;
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
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

    u32 dampBattler;
    if (gBattleControllerExecFlags)
        return;

    if ((dampBattler = IsAbilityOnField(ABILITY_DAMP)))
    {
        // Failed, a battler has Damp
        gLastUsedAbility = ABILITY_DAMP;
        gBattlerTarget = --dampBattler;
        gBattlescriptCurrInstr = BattleScript_DampStopsExplosion;
        return;
    }

    gActiveBattler = gBattlerAttacker;
    gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
    BtlController_EmitHealthBarUpdate(BUFFER_A, INSTANT_HP_BAR_DROP);
    MarkBattlerForControllerExec(gActiveBattler);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setatkhptozero(void)
{
    CMD_ARGS();

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = gBattlerAttacker;
    gBattleMons[gActiveBattler].hp = 0;
    BtlController_EmitSetMonData(BUFFER_A, REQUEST_HP_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].hp), &gBattleMons[gActiveBattler].hp);
    MarkBattlerForControllerExec(gActiveBattler);

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

    gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;
    gBattleMoveDamage *= -1;

    if (gBattleMons[gBattlerTarget].hp == gBattleMons[gBattlerTarget].maxHP)
        gBattlescriptCurrInstr = failInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_trymirrormove(void)
{
    CMD_ARGS();

    s32 validMovesCount;
    s32 i;
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
        gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
        gCurrentMove = move;
        gBattlerTarget = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }
    else if (validMovesCount != 0)
    {
        gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
        i = Random() % validMovesCount;
        gCurrentMove = validMoves[i];
        gBattlerTarget = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }
    else // no valid moves found
    {
        gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = TRUE;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setrain(void)
{
    CMD_ARGS();

    if (!TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_RAIN, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_FAILED;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STARTED_RAIN;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setreflect(void)
{
    CMD_ARGS();

    if (gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] & SIDE_STATUS_REFLECT)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SIDE_STATUS_FAILED;
    }
    else
    {
        gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] |= SIDE_STATUS_REFLECT;
        if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].reflectTimer = 8;
        else
            gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].reflectTimer = 5;
        gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].reflectBattlerId = gBattlerAttacker;

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMonsInBattle(BATTLE_ALIVE_ATK_SIDE) == 2)
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
    #if B_RECOIL_IF_MISS_DMG >= GEN_5
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 2;
    #elif B_RECOIL_IF_MISS_DMG == GEN_4
        if ((gBattleMons[gBattlerTarget].maxHP / 2) < gBattleMoveDamage)
            gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 2;
    #else
        gBattleMoveDamage /= 2;
    #endif
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        break;
    case DMG_DOUBLED:
        gBattleMoveDamage *= 2;
        break;
    case DMG_1_8_TARGET_HP:
        gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 8;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        break;
    case DMG_FULL_ATTACKER_HP:
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP;
        break;
    case DMG_CURR_ATTACKER_HP:
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].hp;
        break;
    case DMG_BIG_ROOT:
        gBattleMoveDamage = GetDrainedBigRootHp(gBattlerAttacker, gBattleMoveDamage);
        break;
    case DMG_1_2_ATTACKER_HP:
        gBattleMoveDamage = (gBattleMons[gBattlerAttacker].maxHP + 1) / 2; // Half of Max HP Rounded UP
        break;
    case DMG_RECOIL_FROM_IMMUNE:
        gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 2;
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_trysetrest(void)
{
    CMD_ARGS(const u8 *failInstr);

    const u8 *failInstr = cmd->failInstr;
    gActiveBattler = gBattlerTarget = gBattlerAttacker;
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
        BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifnotfirstturn(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    const u8 *jumpInstr = cmd->jumpInstr;

    if (gDisableStructs[gBattlerAttacker].isFirstTurn)
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

bool8 UproarWakeUpCheck(u8 battlerId)
{
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (!(gBattleMons[i].status2 & STATUS2_UPROAR) || GetBattlerAbility(battlerId) == ABILITY_SOUNDPROOF)
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

    const u8 *jumpInstr = cmd->jumpInstr;
    u32 ability = GetBattlerAbility(gBattlerTarget);

    if (UproarWakeUpCheck(gBattlerTarget))
        gBattlescriptCurrInstr = jumpInstr;
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

        if (!(gSpecialStatuses[gBattlerAttacker].parentalBondState == PARENTAL_BOND_1ST_HIT && gBattleMons[gBattlerTarget].hp != 0))
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

    if (gDisableStructs[gBattlerAttacker].stockpileCounter == 0)
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
            gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / (1 << (3 - gDisableStructs[gBattlerAttacker].stockpileCounter));

            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
            gBattleMoveDamage *= -1;

            gBattleScripting.animTurn = gDisableStructs[gBattlerAttacker].stockpileCounter;
            gBattleStruct->moveEffect2 = MOVE_EFFECT_STOCKPILE_WORE_OFF;
            gBattlescriptCurrInstr = cmd->nextInstr;
            gBattlerTarget = gBattlerAttacker;
        }
    }
}

// Sign change for drained HP handled in GetDrainedBigRootHp
static void Cmd_setdrainedhp(void)
{
    CMD_ARGS();

    if (gBattleMoves[gCurrentMove].argument != 0)
        gBattleMoveDamage = (gHpDealt * gBattleMoves[gCurrentMove].argument / 100);
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
    }
}

static u32 ChangeStatBuffs(s8 statValue, u32 statId, u32 flags, const u8 *BS_ptr)
{
    bool32 certain = FALSE;
    bool32 notProtectAffected = FALSE;
    u32 index;
    u16 activeBattlerAbility;
    bool32 affectsUser = (flags & MOVE_EFFECT_AFFECTS_USER);
    bool32 mirrorArmored = (flags & STAT_CHANGE_MIRROR_ARMOR);

    if (affectsUser)
        gActiveBattler = gBattlerAttacker;
    else
        gActiveBattler = gBattlerTarget;

    activeBattlerAbility = GetBattlerAbility(gActiveBattler);

    gSpecialStatuses[gActiveBattler].changedStatsBattlerId = gBattlerAttacker;

    flags &= ~(MOVE_EFFECT_AFFECTS_USER | STAT_CHANGE_MIRROR_ARMOR);

    if (flags & MOVE_EFFECT_CERTAIN)
        certain = TRUE;
    flags &= ~MOVE_EFFECT_CERTAIN;

    if (flags & STAT_CHANGE_NOT_PROTECT_AFFECTED)
        notProtectAffected++;
    flags &= ~STAT_CHANGE_NOT_PROTECT_AFFECTED;

    if (activeBattlerAbility == ABILITY_CONTRARY)
    {
        statValue ^= STAT_BUFF_NEGATIVE;
        gBattleScripting.statChanger ^= STAT_BUFF_NEGATIVE;
        if (flags & STAT_CHANGE_UPDATE_MOVE_EFFECT)
        {
            flags &= ~STAT_CHANGE_UPDATE_MOVE_EFFECT;
            gBattleScripting.moveEffect = ReverseStatChangeMoveEffect(gBattleScripting.moveEffect);
        }
    }
    else if (activeBattlerAbility == ABILITY_SIMPLE)
    {
        statValue = (SET_STAT_BUFF_VALUE(GET_STAT_BUFF_VALUE(statValue) * 2)) | ((statValue <= -1) ? STAT_BUFF_NEGATIVE : 0);
    }

    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);

    if (statValue <= -1) // Stat decrease.
    {
        if (gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].mistTimer
            && !certain && gCurrentMove != MOVE_CURSE
            && !(gActiveBattler == gBattlerTarget && GetBattlerAbility(gBattlerAttacker) == ABILITY_INFILTRATOR))
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                if (gSpecialStatuses[gActiveBattler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleScripting.battler = gActiveBattler;
                    gBattlescriptCurrInstr = BattleScript_MistProtected;
                    gSpecialStatuses[gActiveBattler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (gCurrentMove != MOVE_CURSE
                 && notProtectAffected != TRUE && JumpIfMoveAffectedByProtect(0))
        {
            gBattlescriptCurrInstr = BattleScript_ButItFailed;
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if ((GetBattlerHoldEffect(gActiveBattler, TRUE) == HOLD_EFFECT_CLEAR_AMULET
                  || activeBattlerAbility == ABILITY_CLEAR_BODY
                  || activeBattlerAbility == ABILITY_FULL_METAL_BODY
                  || activeBattlerAbility == ABILITY_WHITE_SMOKE)
                 && (!affectsUser || mirrorArmored) && !certain && gCurrentMove != MOVE_CURSE)
        {
            if (GetBattlerHoldEffect(gActiveBattler, TRUE) == HOLD_EFFECT_CLEAR_AMULET)
            {
                RecordItemEffectBattle(gActiveBattler, HOLD_EFFECT_CLEAR_AMULET);
            }

            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                if (gSpecialStatuses[gActiveBattler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleScripting.battler = gActiveBattler;
                    gBattlerAbility = gActiveBattler;
                    gBattlescriptCurrInstr = BattleScript_AbilityNoStatLoss;
                    gLastUsedAbility = activeBattlerAbility;
                    RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
                    gSpecialStatuses[gActiveBattler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if ((index = IsFlowerVeilProtected(gActiveBattler)) && !certain)
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                if (gSpecialStatuses[gActiveBattler].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleScripting.battler = gActiveBattler;
                    gBattlerAbility = index - 1;
                    gBattlescriptCurrInstr = BattleScript_FlowerVeilProtectsRet;
                    gLastUsedAbility = ABILITY_FLOWER_VEIL;
                    gSpecialStatuses[gActiveBattler].statLowered = TRUE;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (!certain
                && ((activeBattlerAbility == ABILITY_KEEN_EYE && statId == STAT_ACC)
                || (activeBattlerAbility == ABILITY_HYPER_CUTTER && statId == STAT_ATK)
                || (activeBattlerAbility == ABILITY_BIG_PECKS && statId == STAT_DEF)))
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                BattleScriptPush(BS_ptr);
                gBattleScripting.battler = gActiveBattler;
                gBattlerAbility = gActiveBattler;
                gBattlescriptCurrInstr = BattleScript_AbilityNoSpecificStatLoss;
                gLastUsedAbility = activeBattlerAbility;
                RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (activeBattlerAbility == ABILITY_MIRROR_ARMOR && !affectsUser && !mirrorArmored && gBattlerAttacker != gBattlerTarget && gActiveBattler == gBattlerTarget)
        {
            if (flags == STAT_CHANGE_ALLOW_PTR)
            {
                SET_STATCHANGER(statId, GET_STAT_BUFF_VALUE(statValue) | STAT_BUFF_NEGATIVE, TRUE);
                BattleScriptPush(BS_ptr);
                gBattleScripting.battler = gActiveBattler;
                gBattlerAbility = gActiveBattler;
                gBattlescriptCurrInstr = BattleScript_MirrorArmorReflect;
                RecordAbilityBattle(gActiveBattler, gBattleMons[gActiveBattler].ability);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (activeBattlerAbility == ABILITY_SHIELD_DUST && flags == 0)
        {
            RecordAbilityBattle(gActiveBattler, ABILITY_SHIELD_DUST);
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (flags == 0 && GetBattlerHoldEffect(gActiveBattler, TRUE) == HOLD_EFFECT_COVERT_CLOAK)
        {
            RecordItemEffectBattle(gActiveBattler, HOLD_EFFECT_COVERT_CLOAK);
            return STAT_CHANGE_DIDNT_WORK;
        }
        else // try to decrease
        {
            statValue = -GET_STAT_BUFF_VALUE(statValue);
            if (gBattleMons[gActiveBattler].statStages[statId] == 1)
                statValue = -1;
            else if (gBattleMons[gActiveBattler].statStages[statId] == 2 && statValue < -2)
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

            if (gBattleMons[gActiveBattler].statStages[statId] == MIN_STAT_STAGE)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_DECREASE;
            }
            else
            {
                gProtectStructs[gActiveBattler].statFell = TRUE;   // Eject pack, lash out
                gBattleCommunication[MULTISTRING_CHOOSER] = (gBattlerTarget == gActiveBattler); // B_MSG_ATTACKER_STAT_FELL or B_MSG_DEFENDER_STAT_FELL
            }
        }
    }
    else // stat increase
    {
        statValue = GET_STAT_BUFF_VALUE(statValue);
        if (gBattleMons[gActiveBattler].statStages[statId] == 11)
            statValue = 1;
        else if (gBattleMons[gActiveBattler].statStages[statId] == 10 && statValue > 2)
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

        if (gBattleMons[gActiveBattler].statStages[statId] == MAX_STAT_STAGE)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STAT_WONT_INCREASE;
        }
        else
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = (gBattlerTarget == gActiveBattler);
            gProtectStructs[gActiveBattler].statRaised = TRUE;
            
            // check mirror herb
            for (index = 0; index < gBattlersCount; index++)
            {
                if (GetBattlerSide(index) == GetBattlerSide(gActiveBattler))
                    continue; // Only triggers on opposing side 
                if (GetBattlerHoldEffect(index, TRUE) == HOLD_EFFECT_MIRROR_HERB
                        && gBattleMons[index].statStages[statId] < MAX_STAT_STAGE)
                {                    
                    gProtectStructs[index].eatMirrorHerb = 1;
                    gTotemBoosts[index].stats |= (1 << (statId - 1));    // -1 to start at atk
                    gTotemBoosts[index].statChanges[statId - 1] = statValue;
                }
            }
        }
    }

    gBattleMons[gActiveBattler].statStages[statId] += statValue;
    if (gBattleMons[gActiveBattler].statStages[statId] < MIN_STAT_STAGE)
        gBattleMons[gActiveBattler].statStages[statId] = MIN_STAT_STAGE;
    if (gBattleMons[gActiveBattler].statStages[statId] > MAX_STAT_STAGE)
        gBattleMons[gActiveBattler].statStages[statId] = MAX_STAT_STAGE;

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

    s32 i, j;

    for (i = 0; i < gBattlersCount; i++)
        TryResetBattlerStatChanges(i);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setbide(void)
{
    CMD_ARGS();

    gBattleMons[gBattlerAttacker].status2 |= STATUS2_MULTIPLETURNS;
    gLockedMoves[gBattlerAttacker] = gCurrentMove;
    gTakenDmg[gBattlerAttacker] = 0;
    gBattleMons[gBattlerAttacker].status2 |= STATUS2_BIDE_TURN(2);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_confuseifrepeatingattackends(void)
{
    CMD_ARGS();

    if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_LOCK_CONFUSE) && !gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
        gBattleScripting.moveEffect = (MOVE_EFFECT_THRASH | MOVE_EFFECT_AFFECTS_USER);

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
        #if B_MULTI_HIT_CHANCE >= GEN_5
            // Based on Gen 5's odds
            // 35% for 2 hits
            // 35% for 3 hits
            // 15% for 4 hits
            // 15% for 5 hits
            gMultiHitCounter = Random() % 100;
            if (gMultiHitCounter < 35)
                gMultiHitCounter = 2;
            else if (gMultiHitCounter < 35 + 35)
                gMultiHitCounter = 3;
            else if (gMultiHitCounter < 35 + 35 + 15)
                gMultiHitCounter = 4;
            else
                gMultiHitCounter = 5;
        #else
            // 2 and 3 hits: 37.5%
            // 4 and 5 hits: 12.5%
            gMultiHitCounter = Random() % 4;
            if (gMultiHitCounter > 1)
                gMultiHitCounter = (Random() % 4) + 2;
            else
                gMultiHitCounter += 2;
        #endif
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
    s32 monsCount;
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
            monsCount = 6;
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
            monsCount = PARTY_SIZE / 2;
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
            monsCount = PARTY_SIZE / 2;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerTarget)];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
            {
                firstMonId = 0;
                lastMonId = PARTY_SIZE;
                monsCount = PARTY_SIZE;
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
                monsCount = PARTY_SIZE / 2;
            }
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerTarget)];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            firstMonId = 0;
            lastMonId = PARTY_SIZE;
            monsCount = PARTY_SIZE;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerTarget)];
        }
        else
        {
            firstMonId = 0;
            lastMonId = PARTY_SIZE;
            monsCount = PARTY_SIZE;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget]; // there is only one pokemon out in single battles
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
    u8 moveChecked;
    u8 moveType;

#if B_UPDATED_CONVERSION >= GEN_6
    // Changes user's type to its first move's type
    for (moveChecked = 0; moveChecked < MAX_MON_MOVES; moveChecked++)
    {
        if (gBattleMons[gBattlerAttacker].moves[moveChecked] != MOVE_NONE)
        {
            moveType = gBattleMoves[gBattleMons[gBattlerAttacker].moves[moveChecked]].type;
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
#else
    // Randomly changes user's type to one of its moves' type
    while (validMoves < MAX_MON_MOVES)
    {
        if (gBattleMons[gBattlerAttacker].moves[validMoves] == MOVE_NONE)
            break;

        validMoves++;
    }

    for (moveChecked = 0; moveChecked < validMoves; moveChecked++)
    {
        moveType = gBattleMoves[gBattleMons[gBattlerAttacker].moves[moveChecked]].type;

        if (moveType == TYPE_MYSTERY)
        {
            if (IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
                moveType = TYPE_GHOST;
            else
                moveType = TYPE_NORMAL;
        }
        if (moveType != gBattleMons[gBattlerAttacker].type1
            && moveType != gBattleMons[gBattlerAttacker].type2
            && moveType != gBattleMons[gBattlerAttacker].type3)
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
            while ((moveChecked = Random() & (MAX_MON_MOVES - 1)) >= validMoves);

            moveType = gBattleMoves[gBattleMons[gBattlerAttacker].moves[moveChecked]].type;

            if (moveType == TYPE_MYSTERY)
            {
                if (IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
                    moveType = TYPE_GHOST;
                else
                    moveType = TYPE_NORMAL;
            }
        }
        while (moveType == gBattleMons[gBattlerAttacker].type1 || moveType == gBattleMons[gBattlerAttacker].type2 || moveType == gBattleMons[gBattlerAttacker].type3);

        SET_BATTLER_TYPE(gBattlerAttacker, moveType);
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
#endif
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

    if (gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] & SIDE_STATUS_LIGHTSCREEN)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SIDE_STATUS_FAILED;
    }
    else
    {
        gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] |= SIDE_STATUS_LIGHTSCREEN;
        if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].lightscreenTimer = 8;
        else
            gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].lightscreenTimer = 5;
        gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].lightscreenBattlerId = gBattlerAttacker;

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMonsInBattle(BATTLE_ALIVE_ATK_SIDE) == 2)
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
            u16 odds = gBattleMoves[gCurrentMove].accuracy + (gBattleMons[gBattlerAttacker].level - gBattleMons[gBattlerTarget].level);
        #if B_SHEER_COLD_ACC >= GEN_7
            if (gCurrentMove == MOVE_SHEER_COLD && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_ICE))
                odds -= 10;
        #endif
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
        #if B_AFFECTION_MECHANICS == TRUE
            else if (gSpecialStatuses[gBattlerTarget].affectionEndured)
            {
                gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - 1;
                gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED_AFFECTION;
            }
        #endif
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

    gBattleMoveDamage = gBattleMons[gBattlerTarget].hp / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setsandstorm(void)
{
    CMD_ARGS();

    if (!TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_SANDSTORM, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_FAILED;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STARTED_SANDSTORM;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_weatherdamage(void)
{
    CMD_ARGS();

    u32 ability = GetBattlerAbility(gBattlerAttacker);

    gBattleMoveDamage = 0;
    if (IsBattlerAlive(gBattlerAttacker) && WEATHER_HAS_EFFECT && ability != ABILITY_MAGIC_GUARD)
    {
        if (gBattleWeather & B_WEATHER_SANDSTORM)
        {
            if (!IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_ROCK)
                && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GROUND)
                && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_STEEL)
                && ability != ABILITY_SAND_VEIL
                && ability != ABILITY_SAND_FORCE
                && ability != ABILITY_SAND_RUSH
                && ability != ABILITY_OVERCOAT
                && !(gStatuses3[gBattlerAttacker] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
                && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_SAFETY_GOGGLES)
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
            }
        }
        if (gBattleWeather & B_WEATHER_HAIL)
        {
            if (ability == ABILITY_ICE_BODY
                && !(gStatuses3[gBattlerAttacker] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
                && !BATTLER_MAX_HP(gBattlerAttacker)
                && !(gStatuses3[gBattlerAttacker] & STATUS3_HEAL_BLOCK))
            {
                gBattlerAbility = gBattlerAttacker;
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                gBattleMoveDamage *= -1;
            }
            else if (!IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_ICE)
                && ability != ABILITY_SNOW_CLOAK
                && ability != ABILITY_OVERCOAT
                && ability != ABILITY_ICE_BODY
                && !(gStatuses3[gBattlerAttacker] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
                && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_SAFETY_GOGGLES)
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
            }
        }
        if (gBattleWeather & B_WEATHER_SNOW)
        {
            if (ability == ABILITY_ICE_BODY
                && !(gStatuses3[gBattlerAttacker] & (STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
                && !BATTLER_MAX_HP(gBattlerAttacker)
                && !(gStatuses3[gBattlerAttacker] & STATUS3_HEAL_BLOCK))
            {
                gBattlerAbility = gBattlerAttacker;
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                gBattleMoveDamage *= -1;
            }
        }
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_tryinfatuating(void)
{
    CMD_ARGS(const u8 *failInstr);

    struct Pokemon *monAttacker, *monTarget;
    u16 speciesAttacker, speciesTarget;
    u32 personalityAttacker, personalityTarget;

    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        monAttacker = &gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]];
    else
        monAttacker = &gEnemyParty[gBattlerPartyIndexes[gBattlerAttacker]];

    if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
        monTarget = &gPlayerParty[gBattlerPartyIndexes[gBattlerTarget]];
    else
        monTarget = &gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]];

    speciesAttacker = GetMonData(monAttacker, MON_DATA_SPECIES);
    personalityAttacker = GetMonData(monAttacker, MON_DATA_PERSONALITY);

    speciesTarget = GetMonData(monTarget, MON_DATA_SPECIES);
    personalityTarget = GetMonData(monTarget, MON_DATA_PERSONALITY);

    if (GetBattlerAbility(gBattlerTarget) == ABILITY_OBLIVIOUS)
    {
        gBattlescriptCurrInstr = BattleScript_NotAffectedAbilityPopUp;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        RecordAbilityBattle(gBattlerTarget, ABILITY_OBLIVIOUS);
    }
    else
    {
        if (GetGenderFromSpeciesAndPersonality(speciesAttacker, personalityAttacker) == GetGenderFromSpeciesAndPersonality(speciesTarget, personalityTarget)
            || gBattleMons[gBattlerTarget].status2 & STATUS2_INFATUATION
            || GetGenderFromSpeciesAndPersonality(speciesAttacker, personalityAttacker) == MON_GENDERLESS
            || GetGenderFromSpeciesAndPersonality(speciesTarget, personalityTarget) == MON_GENDERLESS)
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

    if (gBattleControllerExecFlags)
        return;

    if (cmd->battler != BS_ATTACKER_WITH_PARTNER)
    {
        gActiveBattler = GetBattlerForBattleScript(cmd->battler);
        BtlController_EmitStatusIconUpdate(BUFFER_A, gBattleMons[gActiveBattler].status1, gBattleMons[gActiveBattler].status2);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gActiveBattler = gBattlerAttacker;
        if (!(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
        {
            BtlController_EmitStatusIconUpdate(BUFFER_A, gBattleMons[gActiveBattler].status1, gBattleMons[gActiveBattler].status2);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        {
            gActiveBattler = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gBattlerAttacker)));
            if (!(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
            {
                BtlController_EmitStatusIconUpdate(BUFFER_A, gBattleMons[gActiveBattler].status1, gBattleMons[gActiveBattler].status2);
                MarkBattlerForControllerExec(gActiveBattler);
            }
        }
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_setmist(void)
{
    CMD_ARGS();

    if (gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].mistTimer)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_MIST_FAILED;
    }
    else
    {
        gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].mistTimer = 5;
        gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].mistBattlerId = gBattlerAttacker;
        gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] |= SIDE_STATUS_MIST;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_MIST;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setfocusenergy(void)
{
    CMD_ARGS();

    if (gBattleMons[gBattlerAttacker].status2 & STATUS2_FOCUS_ENERGY)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FOCUS_ENERGY_FAILED;
    }
    else
    {
        gBattleMons[gBattlerAttacker].status2 |= STATUS2_FOCUS_ENERGY;
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

        gBattleMons[gBattlerAttacker].status2 |= STATUS2_TRANSFORMED;
        gDisableStructs[gBattlerAttacker].disabledMove = MOVE_NONE;
        gDisableStructs[gBattlerAttacker].disableTimer = 0;
        gDisableStructs[gBattlerAttacker].transformedMonPersonality = gBattleMons[gBattlerTarget].personality;
        gDisableStructs[gBattlerAttacker].transformedMonOtId = gBattleMons[gBattlerTarget].otId;
        gDisableStructs[gBattlerAttacker].mimickedMoves = 0;
        gDisableStructs[gBattlerAttacker].usedMoves = 0;

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerTarget].species)

        battleMonAttacker = (u8 *)(&gBattleMons[gBattlerAttacker]);
        battleMonTarget = (u8 *)(&gBattleMons[gBattlerTarget]);

        for (i = 0; i < offsetof(struct BattlePokemon, pp); i++)
            battleMonAttacker[i] = battleMonTarget[i];

        gBattleStruct->overwrittenAbilities[gBattlerAttacker] = GetBattlerAbility(gBattlerTarget);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMoves[gBattleMons[gBattlerAttacker].moves[i]].pp < 5)
                gBattleMons[gBattlerAttacker].pp[i] = gBattleMoves[gBattleMons[gBattlerAttacker].moves[i]].pp;
            else
                gBattleMons[gBattlerAttacker].pp[i] = 5;
        }

        gActiveBattler = gBattlerAttacker;
        BtlController_EmitResetActionMoveSelection(BUFFER_A, RESET_MOVE_SELECTION);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TRANSFORMED;
    }
}

static void Cmd_setsubstitute(void)
{
    CMD_ARGS();

    u32 hp = gBattleMons[gBattlerAttacker].maxHP / 4;
    if (gBattleMons[gBattlerAttacker].maxHP / 4 == 0)
        hp = 1;

    if (gBattleMons[gBattlerAttacker].hp <= hp)
    {
        gBattleMoveDamage = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SUBSTITUTE_FAILED;
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4; // one bit value will only work for pokemon which max hp can go to 1020(which is more than possible in games)
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

    if ((sForbiddenMoves[gLastMoves[gBattlerTarget]] & FORBIDDEN_MIMIC)
        || (gBattleMons[gBattlerAttacker].status2 & STATUS2_TRANSFORMED)
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
            if (gBattleMoves[gLastMoves[gBattlerTarget]].pp < 5)
                gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = gBattleMoves[gLastMoves[gBattlerTarget]].pp;
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

static void Cmd_metronome(void)
{
    CMD_ARGS();

#if B_METRONOME_MOVES >= GEN_9
    u16 moveCount = MOVES_COUNT_GEN9;
#elif B_METRONOME_MOVES >= GEN_8
    u16 moveCount = MOVES_COUNT_GEN8;
#elif B_METRONOME_MOVES >= GEN_7
    u16 moveCount = MOVES_COUNT_GEN7;
#elif B_METRONOME_MOVES >= GEN_6
    u16 moveCount = MOVES_COUNT_GEN6;
#elif B_METRONOME_MOVES >= GEN_5
    u16 moveCount = MOVES_COUNT_GEN5;
#elif B_METRONOME_MOVES >= GEN_4
    u16 moveCount = MOVES_COUNT_GEN4;
#elif B_METRONOME_MOVES >= GEN_3
    u16 moveCount = MOVES_COUNT_GEN3;
#endif

    while (TRUE)
    {
        gCurrentMove = (Random() % (moveCount - 1)) + 1;
        if (gBattleMoves[gCurrentMove].effect == EFFECT_PLACEHOLDER)
            continue;

        if (!(sForbiddenMoves[gCurrentMove] & FORBIDDEN_METRONOME))
        {
            gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
            gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
            gBattlerTarget = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
            return;
        }
    }
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

    s32 randDamage;
#if B_PSYWAVE_DMG >= GEN_6
    randDamage = (Random() % 101);
#else
    randDamage = (Random() % 11) * 10;
#endif
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
        gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = TRUE;
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
        gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = TRUE;
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
    #if B_DISABLE_TURNS == GEN_3
        gDisableStructs[gBattlerTarget].disableTimer = (Random() & 3) + 2;
    #elif B_DISABLE_TURNS == GEN_4
        gDisableStructs[gBattlerTarget].disableTimer = (Random() & 3) + 4;
    #else
        gDisableStructs[gBattlerTarget].disableTimer = 4;
    #endif
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

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[gBattlerTarget].moves[i] == gLastMoves[gBattlerTarget])
            break;
    }

    if (gLastMoves[gBattlerTarget] == MOVE_NONE
     || gLastMoves[gBattlerTarget] == MOVE_UNAVAILABLE
     || gLastMoves[gBattlerTarget] == MOVE_STRUGGLE
     || gLastMoves[gBattlerTarget] == MOVE_ENCORE
     || gLastMoves[gBattlerTarget] == MOVE_MIRROR_MOVE
     || gLastMoves[gBattlerTarget] == MOVE_SHELL_TRAP)
    {
        i = MAX_MON_MOVES;
    }

    if (gDisableStructs[gBattlerTarget].encoredMove == MOVE_NONE
        && i != MAX_MON_MOVES && gBattleMons[gBattlerTarget].pp[i] != 0)
    {
        gDisableStructs[gBattlerTarget].encoredMove = gBattleMons[gBattlerTarget].moves[i];
        gDisableStructs[gBattlerTarget].encoredMovePos = i;
        gDisableStructs[gBattlerTarget].encoreTimer = 3;
        gDisableStructs[gBattlerTarget].encoreTimer;
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
        s32 hpDiff = (gBattleMons[gBattlerAttacker].hp + gBattleMons[gBattlerTarget].hp) / 2;
        s32 painSplitHp = gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - hpDiff;
        u8 *storeLoc = (void *)(&gBattleScripting.painSplitHp);

        storeLoc[0] = (painSplitHp);
        storeLoc[1] = (painSplitHp & 0x0000FF00) >> 8;
        storeLoc[2] = (painSplitHp & 0x00FF0000) >> 16;
        storeLoc[3] = (painSplitHp & 0xFF000000) >> 24;

        gBattleMoveDamage = gBattleMons[gBattlerAttacker].hp - hpDiff;
        gSpecialStatuses[gBattlerTarget].dmg = 0xFFFF;

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
    else if (IsTwoTurnsMove(gLastLandedMoves[gBattlerAttacker])
            && gBattleMons[gLastHitBy[gBattlerAttacker]].status2 & STATUS2_MULTIPLETURNS)
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
        && gLastPrintedMoves[gBattlerTarget] != MOVE_STRUGGLE
        && gLastPrintedMoves[gBattlerTarget] != MOVE_NONE
        && gLastPrintedMoves[gBattlerTarget] != MOVE_UNAVAILABLE
        && gLastPrintedMoves[gBattlerTarget] != MOVE_SKETCH)
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
            gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = gBattleMoves[gLastPrintedMoves[gBattlerTarget]].pp;
            gActiveBattler = gBattlerAttacker;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                movePpData.moves[i] = gBattleMons[gBattlerAttacker].moves[i];
                movePpData.pp[i] = gBattleMons[gBattlerAttacker].pp[i];
            }
            movePpData.ppBonuses = gBattleMons[gBattlerAttacker].ppBonuses;

            BtlController_EmitSetMonData(BUFFER_A, REQUEST_MOVES_PP_BATTLE, 0, sizeof(movePpData), &movePpData);
            MarkBattlerForControllerExec(gActiveBattler);

            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastPrintedMoves[gBattlerTarget])

            gBattlescriptCurrInstr = cmd->nextInstr;
        }
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static bool8 IsTwoTurnsMove(u16 move)
{
    if (gBattleMoves[move].effect == EFFECT_SKULL_BASH
     || gBattleMoves[move].effect == EFFECT_TWO_TURNS_ATTACK
     || gBattleMoves[move].effect == EFFECT_SOLAR_BEAM
     || gBattleMoves[move].effect == EFFECT_SEMI_INVULNERABLE
     || gBattleMoves[move].effect == EFFECT_BIDE
     || gBattleMoves[move].effect == EFFECT_METEOR_BEAM)
        return TRUE;
    else
        return FALSE;
}

// unused
static u8 AttacksThisTurn(u8 battlerId, u16 move) // Note: returns 1 if it's a charging turn, otherwise 2
{
    // first argument is unused
    if (gBattleMoves[move].effect == EFFECT_SOLAR_BEAM
        && IsBattlerWeatherAffected(battlerId, B_WEATHER_SUN))
        return 2;

    if (gBattleMoves[move].effect == EFFECT_SKULL_BASH
     || gBattleMoves[move].effect == EFFECT_TWO_TURNS_ATTACK
     || gBattleMoves[move].effect == EFFECT_SOLAR_BEAM
     || gBattleMoves[move].effect == EFFECT_SEMI_INVULNERABLE
     || gBattleMoves[move].effect == EFFECT_BIDE)
    {
        if ((gHitMarker & HITMARKER_CHARGING))
            return 1;
    }
    return 2;
}

static void Cmd_trychoosesleeptalkmove(void)
{
    CMD_ARGS(const u8 *failInstr);

    u32 i, unusableMovesBits = 0, movePosition;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if ((sForbiddenMoves[gBattleMons[gBattlerAttacker].moves[i]] & FORBIDDEN_SLEEP_TALK)
            || IsTwoTurnsMove(gBattleMons[gBattlerAttacker].moves[i]))
        {
            unusableMovesBits |= gBitTable[i];
        }
    }

    unusableMovesBits = CheckMoveLimitations(gBattlerAttacker, unusableMovesBits, ~MOVE_LIMITATION_PP);
    if (unusableMovesBits == (1 << MAX_MON_MOVES) - 1) // all 4 moves cannot be chosen
    {
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else // at least one move can be chosen
    {
        do
        {
            movePosition = Random() & (MAX_MON_MOVES - 1);
        } while ((gBitTable[movePosition] & unusableMovesBits));

        gCalledMove = gBattleMons[gBattlerAttacker].moves[movePosition];
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
    #if B_TAILWIND_TURNS >= GEN_5
        gSideTimers[side].tailwindTimer = 4;
    #else
        gSideTimers[side].tailwindTimer = 3;
    #endif
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

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gLastMoves[gBattlerTarget] == gBattleMons[gBattlerTarget].moves[i])
                break;
        }

    #if B_CAN_SPITE_FAIL <= GEN_3
        if (i != MAX_MON_MOVES && gBattleMons[gBattlerTarget].pp[i] > 1)
    #else
        if (i != MAX_MON_MOVES && gBattleMons[gBattlerTarget].pp[i] != 0)
    #endif
        {
        #if B_PP_REDUCED_BY_SPITE <= GEN_3
            s32 ppToDeduct = (Random() & 3) + 2;
        #else
            s32 ppToDeduct = 4;
        #endif

            if (gBattleMons[gBattlerTarget].pp[i] < ppToDeduct)
                ppToDeduct = gBattleMons[gBattlerTarget].pp[i];

            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastMoves[gBattlerTarget])

            ConvertIntToDecimalStringN(gBattleTextBuff2, ppToDeduct, STR_CONV_MODE_LEFT_ALIGN, 1);

            PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 1, ppToDeduct)

            gBattleMons[gBattlerTarget].pp[i] -= ppToDeduct;
            gActiveBattler = gBattlerTarget;

            // if (MOVE_IS_PERMANENT(gActiveBattler, i)), but backwards
            if (!(gDisableStructs[gActiveBattler].mimickedMoves & gBitTable[i])
                && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
            {
                BtlController_EmitSetMonData(BUFFER_A, REQUEST_PPMOVE1_BATTLE + i, 0, sizeof(gBattleMons[gActiveBattler].pp[i]), &gBattleMons[gActiveBattler].pp[i]);
                MarkBattlerForControllerExec(gActiveBattler);
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
    u8 toHeal = 0;

    if (gCurrentMove == MOVE_HEAL_BELL)
    {
        struct Pokemon *party = GetBattlerParty(gBattlerAttacker);
        s32 i;

        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_BELL;

        if (GetBattlerAbility(gBattlerAttacker) != ABILITY_SOUNDPROOF)
        {
            gBattleMons[gBattlerAttacker].status1 = 0;
            gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;
        }
        else
        {
            RecordAbilityBattle(gBattlerAttacker, gBattleMons[gBattlerAttacker].ability);
            gBattleCommunication[MULTISTRING_CHOOSER] |= B_MSG_BELL_SOUNDPROOF_ATTACKER;
        }

        gActiveBattler = gBattleScripting.battler = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gBattlerAttacker)));

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
            && !(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
        {
            if (GetBattlerAbility(gActiveBattler) != ABILITY_SOUNDPROOF)
            {
                gBattleMons[gActiveBattler].status1 = 0;
                gBattleMons[gActiveBattler].status2 &= ~STATUS2_NIGHTMARE;
            }
            else
            {
                RecordAbilityBattle(gActiveBattler, gBattleMons[gActiveBattler].ability);
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

                if (gBattlerPartyIndexes[gBattlerAttacker] == i)
                    ability = GetBattlerAbility(gBattlerAttacker);
                else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                         && gBattlerPartyIndexes[gActiveBattler] == i
                         && !(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
                    ability = GetBattlerAbility(gActiveBattler);
                else
                    ability = GetAbilityBySpecies(species, abilityNum);

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

        gActiveBattler = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gBattlerAttacker)));
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
            && !(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
        {
            gBattleMons[gActiveBattler].status1 = 0;
            gBattleMons[gActiveBattler].status2 &= ~STATUS2_NIGHTMARE;
        }

    }

    if (toHeal)
    {
        gActiveBattler = gBattlerAttacker;
        BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, toHeal, sizeof(zero), &zero);
        MarkBattlerForControllerExec(gActiveBattler);
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
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 2;
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
        gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = TRUE;
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

    PressurePPLoseOnUsingPerishSong(gBattlerAttacker);

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
        if (gDisableStructs[gBattlerAttacker].furyCutterCounter != 5
            && gSpecialStatuses[gBattlerAttacker].parentalBondState != PARENTAL_BOND_1ST_HIT) // Don't increment counter on first hit
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
            gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 4;
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

    if (gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] & SIDE_STATUS_SAFEGUARD)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SIDE_STATUS_FAILED;
    }
    else
    {
        gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] |= SIDE_STATUS_SAFEGUARD;
        gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].safeguardTimer = 5;
        gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].safeguardBattlerId = gBattlerAttacker;
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
        && gChosenMoveByBattler[gBattlerTarget] == MOVE_PURSUIT)
    {
        s32 i;

        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == gBattlerTarget)
                gActionsByTurnOrder[i] = B_ACTION_TRY_FINISH;
        }

        gCurrentMove = MOVE_PURSUIT;
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

static void Cmd_setsunny(void)
{
    CMD_ARGS();

    if (!TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_SUN, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_FAILED;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STARTED_SUNLIGHT;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Belly Drum
static void Cmd_maxattackhalvehp(void)
{
    CMD_ARGS(const u8 *failInstr);

    u32 halfHp = gBattleMons[gBattlerAttacker].maxHP / 2;

    if (!(gBattleMons[gBattlerAttacker].maxHP / 2))
        halfHp = 1;

    // Belly Drum fails if the user's current HP is less than half its maximum, or if the user's Attack is already at +6 (even if the user has Contrary).
    if (gBattleMons[gBattlerAttacker].statStages[STAT_ATK] < MAX_STAT_STAGE
        && gBattleMons[gBattlerAttacker].hp > halfHp)
    {
        gBattleMons[gBattlerAttacker].statStages[STAT_ATK] = MAX_STAT_STAGE;
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 2;
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
                gBattleMoveDamage = 20 * gBattleMons[gBattlerAttacker].maxHP / 30;
            else
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 2;
        }
        else
        {
            if (!(gBattleWeather & B_WEATHER_ANY) || !WEATHER_HAS_EFFECT || GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_UTILITY_UMBRELLA)
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 2;
            else if (gBattleWeather & B_WEATHER_SUN)
                gBattleMoveDamage = 20 * gBattleMons[gBattlerAttacker].maxHP / 30;
            else // not sunny weather
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4;
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
        gSideTimers[targetSide].stickyWebBattlerSide = GetBattlerSide(gBattlerAttacker); // For Court Change/Defiant - set this to the user's side
        gSideTimers[targetSide].stickyWebAmount = 1;
        gBattleStruct->stickyWebUser = gBattlerAttacker;    // For Mirror Armor
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
        gSideStatuses[GET_BATTLER_SIDE(gBattlerTarget)] |= SIDE_STATUS_FUTUREATTACK;
        gWishFutureKnock.futureSightMove[gBattlerTarget] = gCurrentMove;
        gWishFutureKnock.futureSightAttacker[gBattlerTarget] = gBattlerAttacker;
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
    CMD_ARGS(const u8 *endInstr, const u8 *failInstr);

#if B_BEAT_UP >= GEN_5
    gBattleStruct->beatUpSlot++;
    gBattlescriptCurrInstr = cmd->nextInstr;
#else
    struct Pokemon *party = GetBattlerParty(gBattlerAttacker);

    if (gBattleMons[gBattlerTarget].hp == 0)
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
            gBattleMoveDamage *= gBattleMoves[gCurrentMove].power;
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
    CMD_ARGS();

    switch (gCurrentMove)
    {
    case MOVE_FLY:
    case MOVE_BOUNCE:
    case MOVE_SKY_DROP:
        gStatuses3[gBattlerAttacker] |= STATUS3_ON_AIR;
        break;
    case MOVE_DIG:
        gStatuses3[gBattlerAttacker] |= STATUS3_UNDERGROUND;
        break;
    case MOVE_DIVE:
        gStatuses3[gBattlerAttacker] |= STATUS3_UNDERWATER;
        break;
    case MOVE_PHANTOM_FORCE:
    case MOVE_SHADOW_FORCE:
        gStatuses3[gBattlerAttacker] |= STATUS3_PHANTOM_FORCE;
        break;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_clearsemiinvulnerablebit(void)
{
    CMD_ARGS();

    gStatuses3[gBattlerAttacker] &= ~STATUS3_SEMI_INVULNERABLE;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setminimize(void)
{
    CMD_ARGS();

    if (gHitMarker & HITMARKER_OBEYS)
        gStatuses3[gBattlerAttacker] |= STATUS3_MINIMIZED;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_sethail(void)
{
    CMD_ARGS();

    if (!TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_HAIL, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_FAILED;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STARTED_HAIL;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_trymemento(void)
{
    CMD_ARGS(const u8 *failInstr);

    #if B_MEMENTO_FAIL == GEN_3
    if (gBattleMons[gBattlerTarget].statStages[STAT_ATK] == MIN_STAT_STAGE
        && gBattleMons[gBattlerTarget].statStages[STAT_SPATK] == MIN_STAT_STAGE
        && gBattleCommunication[MISS_TYPE] != B_MSG_PROTECTED)
    #else
    if (gBattleCommunication[MISS_TYPE] == B_MSG_PROTECTED
      || gStatuses3[gBattlerTarget] & STATUS3_SEMI_INVULNERABLE
      || IsBattlerProtected(gBattlerTarget, gCurrentMove)
      || DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
    #endif
    {
        // Failed, unprotected target already has minimum Attack and Special Attack.
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        // Success, drop user's HP bar to 0
        gActiveBattler = gBattlerAttacker;
        gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
        BtlController_EmitHealthBarUpdate(BUFFER_A, INSTANT_HP_BAR_DROP);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

// Follow Me
static void Cmd_setforcedtarget(void)
{
    CMD_ARGS();

    gSideTimers[GetBattlerSide(gBattlerTarget)].followmeTimer = 1;
    gSideTimers[GetBattlerSide(gBattlerTarget)].followmeTarget = gBattlerTarget;
    gSideTimers[GetBattlerSide(gBattlerTarget)].followmePowder = TestMoveFlags(gCurrentMove, FLAG_POWDER);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_setcharge(void)
{
    CMD_ARGS();

    gStatuses3[gBattlerAttacker] |= STATUS3_CHARGED_UP;
    gDisableStructs[gBattlerAttacker].chargeTimer = 2;
    gBattlescriptCurrInstr++;
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Nature Power
static void Cmd_callterrainattack(void)
{
    CMD_ARGS();

    gHitMarker &= ~HITMARKER_ATTACKSTRING_PRINTED;
    gCurrentMove = GetNaturePowerMove();
    gBattlerTarget = GetMoveTarget(gCurrentMove, NO_TARGET_OVERRIDE);
    BattleScriptPush(gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect]);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

u16 GetNaturePowerMove(void)
{
    if (gFieldStatuses & STATUS_FIELD_MISTY_TERRAIN)
        return MOVE_MOONBLAST;
    else if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
        return MOVE_THUNDERBOLT;
    else if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
        return MOVE_ENERGY_BALL;
    else if (gFieldStatuses & STATUS_FIELD_PSYCHIC_TERRAIN)
        return MOVE_PSYCHIC;
    else if (sNaturePowerMoves == MOVE_NONE)
        return MOVE_TRI_ATTACK;
    return sNaturePowerMoves[gBattleTerrain];
}

// Refresh
static void Cmd_cureifburnedparalysedorpoisoned(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gBattleMons[gBattlerAttacker].status1 & (STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON | STATUS1_FROSTBITE))
    {
        gBattleMons[gBattlerAttacker].status1 = 0;
        gBattlescriptCurrInstr = cmd->nextInstr;
        gActiveBattler = gBattlerAttacker;
        BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

static void Cmd_settorment(void)
{
    CMD_ARGS(const u8 *failInstr);

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_TORMENT)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleMons[gBattlerTarget].status2 |= STATUS2_TORMENT;
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

#if B_OBLIVIOUS_TAUNT >= GEN_6
    if (GetBattlerAbility(gBattlerTarget) == ABILITY_OBLIVIOUS)
    {
        gBattlescriptCurrInstr = BattleScript_NotAffectedAbilityPopUp;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        RecordAbilityBattle(gBattlerTarget, ABILITY_OBLIVIOUS);
    }
    else
#endif
    if (gDisableStructs[gBattlerTarget].tauntTimer == 0)
    {
        #if B_TAUNT_TURNS >= GEN_5
            u8 turns = 4;
            if (GetBattlerTurnOrderNum(gBattlerTarget) > GetBattlerTurnOrderNum(gBattlerAttacker))
                turns--; // If the target hasn't yet moved this turn, Taunt lasts for only three turns (source: Bulbapedia)
        #elif B_TAUNT_TURNS == GEN_4
            u8 turns = (Random() & 2) + 3;
        #else
            u8 turns = 2;
        #endif

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
                                  #if B_TRAINERS_KNOCK_OFF_ITEMS == TRUE
                                  | BATTLE_TYPE_TRAINER
                                  #endif
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
        // can't swap if two pokemon don't have an item
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

            gActiveBattler = gBattlerAttacker;
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(*newItemAtk), newItemAtk);
            MarkBattlerForControllerExec(gBattlerAttacker);

            gActiveBattler = gBattlerTarget;
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gBattlerTarget].item), &gBattleMons[gBattlerTarget].item);
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

// Role Play
static void Cmd_trycopyability(void)
{
    CMD_ARGS(const u8 *failInstr);

    u16 defAbility = gBattleMons[gBattlerTarget].ability;

    if (gBattleMons[gBattlerAttacker].ability == defAbility
      || defAbility == ABILITY_NONE
      || IsRolePlayBannedAbilityAtk(gBattleMons[gBattlerAttacker].ability)
      || IsRolePlayBannedAbility(defAbility))
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleScripting.abilityPopupOverwrite = gBattleMons[gBattlerAttacker].ability;
        gBattleMons[gBattlerAttacker].ability = gBattleStruct->overwrittenAbilities[gBattlerAttacker] = defAbility;
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
    #if B_WISH_HP_SOURCE >= GEN_5
        if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
            gBattleMoveDamage = max(1, GetMonData(&gPlayerParty[gWishFutureKnock.wishPartyId[gBattlerTarget]], MON_DATA_MAX_HP) / 2);
        else
            gBattleMoveDamage = max(1, GetMonData(&gEnemyParty[gWishFutureKnock.wishPartyId[gBattlerTarget]], MON_DATA_MAX_HP) / 2);
    #else
        gBattleMoveDamage = max(1, gBattleMons[gBattlerTarget].maxHP / 2);
    #endif

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

    if (IsGastroAcidBannedAbility(gBattleMons[gBattlerTarget].ability))
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

    if (gBattleMons[gBattlerTarget].hp <= gBattleMons[gBattlerAttacker].hp)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - gBattleMons[gBattlerAttacker].hp;
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

    switch (gBattleMoves[gCurrentMove].effect)
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

    if (IsSkillSwapBannedAbility(gBattleMons[gBattlerAttacker].ability)
      || IsSkillSwapBannedAbility(gBattleMons[gBattlerTarget].ability))
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
        if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
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
    else
    {
        u8 battlerId, sideAttacker;

        sideAttacker = GetBattlerSide(gBattlerAttacker);
        PressurePPLoseOnUsingImprison(gBattlerAttacker);
        for (battlerId = 0; battlerId < gBattlersCount; battlerId++)
        {
            if (sideAttacker != GetBattlerSide(battlerId))
            {
                s32 attackerMoveId;
                for (attackerMoveId = 0; attackerMoveId < MAX_MON_MOVES; attackerMoveId++)
                {
                    s32 i;
                    for (i = 0; i < MAX_MON_MOVES; i++)
                    {
                        if (gBattleMons[gBattlerAttacker].moves[attackerMoveId] == gBattleMons[battlerId].moves[i]
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
        if (battlerId == gBattlersCount) // In Generation 3 games, Imprison fails if the user doesn't share any moves with any of the foes.
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

                if (sForbiddenMoves[move] & FORBIDDEN_ASSIST)
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

    gBattlerTarget = gBattlerAttacker;
    gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = TRUE;
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

    gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = TRUE;
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

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);
    if (gBattleMons[gActiveBattler].ability == ABILITY_NEUTRALIZING_GAS)
    {
        gBattleMons[gActiveBattler].ability = ABILITY_NONE;
        BattleScriptPush(gBattlescriptCurrInstr);
        gBattlescriptCurrInstr = BattleScript_NeutralizingGasExits;
    }
    else
    {
        switch (GetBattlerAbility(gActiveBattler))
        {
        case ABILITY_NATURAL_CURE:
            gBattleMons[gActiveBattler].status1 = 0;
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE,
                                         gBitTable[*(gBattleStruct->battlerPartyIndexes + gActiveBattler)],
                                         sizeof(gBattleMons[gActiveBattler].status1),
                                         &gBattleMons[gActiveBattler].status1);
            MarkBattlerForControllerExec(gActiveBattler);
            break;
        case ABILITY_REGENERATOR:
            gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 3;
            gBattleMoveDamage += gBattleMons[gActiveBattler].hp;
            if (gBattleMoveDamage > gBattleMons[gActiveBattler].maxHP)
                gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP;
            BtlController_EmitSetMonData(BUFFER_A, REQUEST_HP_BATTLE,
                                         gBitTable[*(gBattleStruct->battlerPartyIndexes + gActiveBattler)],
                                         sizeof(gBattleMoveDamage),
                                         &gBattleMoveDamage);
            MarkBattlerForControllerExec(gActiveBattler);
            break;
        }

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}

static void Cmd_jumpifhasnohp(void)
{
    CMD_ARGS(u8 battler, const u8 *jumpInstr);

    gActiveBattler = GetBattlerForBattleScript(cmd->battler);

    if (gBattleMons[gActiveBattler].hp == 0)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_getsecretpowereffect(void)
{
    CMD_ARGS();

    gBattleScripting.moveEffect = GetSecretPowerMoveEffect();
    gBattlescriptCurrInstr = cmd->nextInstr;
}

u16 GetSecretPowerMoveEffect(void)
{
    u16 moveEffect;
    u32 fieldTerrain = gFieldStatuses & STATUS_FIELD_TERRAIN_ANY;
    if (fieldTerrain)
    {
        switch (fieldTerrain)
        {
        case STATUS_FIELD_MISTY_TERRAIN:
            moveEffect = MOVE_EFFECT_SP_ATK_MINUS_1;
            break;
        case STATUS_FIELD_GRASSY_TERRAIN:
            moveEffect = MOVE_EFFECT_SLEEP;
            break;
        case STATUS_FIELD_ELECTRIC_TERRAIN:
            moveEffect = MOVE_EFFECT_PARALYSIS;
            break;
        case STATUS_FIELD_PSYCHIC_TERRAIN:
            moveEffect = MOVE_EFFECT_SPD_MINUS_1;
            break;
        default:
            moveEffect = MOVE_EFFECT_PARALYSIS;
            break;
        }
    }
    else
    {
        switch (gBattleTerrain)
        {
    #if B_SECRET_POWER_EFFECT >= GEN_6
        case BATTLE_TERRAIN_GRASS:      moveEffect = MOVE_EFFECT_SLEEP; break;
        case BATTLE_TERRAIN_UNDERWATER: moveEffect = MOVE_EFFECT_ATK_MINUS_1; break;
        case BATTLE_TERRAIN_POND:       moveEffect = MOVE_EFFECT_ATK_MINUS_1; break;
        case BATTLE_TERRAIN_MOUNTAIN:   moveEffect = MOVE_EFFECT_ACC_MINUS_1; break;
        case BATTLE_TERRAIN_PUDDLE:     moveEffect = MOVE_EFFECT_SPD_MINUS_1; break;
    #elif B_SECRET_POWER_EFFECT >= GEN_5
        case BATTLE_TERRAIN_GRASS:      moveEffect = MOVE_EFFECT_SLEEP; break;
        case BATTLE_TERRAIN_UNDERWATER: moveEffect = MOVE_EFFECT_DEF_MINUS_1; break;
        case BATTLE_TERRAIN_POND:       moveEffect = MOVE_EFFECT_ATK_MINUS_1; break;
        case BATTLE_TERRAIN_MOUNTAIN:   moveEffect = MOVE_EFFECT_ACC_MINUS_1; break;
        case BATTLE_TERRAIN_PUDDLE:     moveEffect = MOVE_EFFECT_SPD_MINUS_1; break;
    #elif B_SECRET_POWER_EFFECT >= GEN_4
        case BATTLE_TERRAIN_GRASS:      moveEffect = MOVE_EFFECT_SLEEP; break;
        case BATTLE_TERRAIN_UNDERWATER: moveEffect = MOVE_EFFECT_DEF_MINUS_1; break;
        case BATTLE_TERRAIN_POND:       moveEffect = MOVE_EFFECT_ATK_MINUS_1; break;
        case BATTLE_TERRAIN_MOUNTAIN:   moveEffect = MOVE_EFFECT_FLINCH; break;
        case BATTLE_TERRAIN_PUDDLE:     moveEffect = MOVE_EFFECT_ACC_MINUS_1; break;
    #else
        case BATTLE_TERRAIN_GRASS:      moveEffect = MOVE_EFFECT_POISON; break;
        case BATTLE_TERRAIN_UNDERWATER: moveEffect = MOVE_EFFECT_DEF_MINUS_1; break;
        case BATTLE_TERRAIN_POND:       moveEffect = MOVE_EFFECT_SPD_MINUS_1; break;
        case BATTLE_TERRAIN_MOUNTAIN:   moveEffect = MOVE_EFFECT_CONFUSION; break;
        case BATTLE_TERRAIN_PUDDLE:     moveEffect = MOVE_EFFECT_ACC_MINUS_1; break;
    #endif
        case BATTLE_TERRAIN_LONG_GRASS:
            moveEffect = MOVE_EFFECT_SLEEP;
            break;
        case BATTLE_TERRAIN_SAND:
            moveEffect = MOVE_EFFECT_ACC_MINUS_1;
            break;
        case BATTLE_TERRAIN_WATER:
            moveEffect = MOVE_EFFECT_ATK_MINUS_1;
            break;
        case BATTLE_TERRAIN_CAVE:
        case BATTLE_TERRAIN_BURIAL_GROUND:
        case BATTLE_TERRAIN_SPACE:
            moveEffect = MOVE_EFFECT_FLINCH;
            break;
        case BATTLE_TERRAIN_SOARING:
        case BATTLE_TERRAIN_SKY_PILLAR:
        case BATTLE_TERRAIN_MARSH:
        case BATTLE_TERRAIN_SWAMP:
            moveEffect = MOVE_EFFECT_SPD_MINUS_1;
            break;
        case BATTLE_TERRAIN_SNOW:
        case BATTLE_TERRAIN_ICE:
        #if B_USE_FROSTBITE == TRUE
            moveEffect = MOVE_EFFECT_FROSTBITE;
        #else
            moveEffect = MOVE_EFFECT_FREEZE;
        #endif
            break;
        case BATTLE_TERRAIN_VOLCANO:
            moveEffect = MOVE_EFFECT_BURN;
            break;
        case BATTLE_TERRAIN_ULTRA_SPACE:
            moveEffect = MOVE_EFFECT_DEF_MINUS_1;
            break;
        default:
            moveEffect = MOVE_EFFECT_PARALYSIS;
            break;
        }
    }
    return moveEffect;
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

                    for (j = 0; j < ARRAY_COUNT(sPickupProbabilities); j++)
                    {
                        if (sPickupProbabilities[j] > rand)
                        {
                            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &sPickupItems[lvlDivBy10 + j]);
                            break;
                        }
                        else if (rand == 99 || rand == 98)
                        {
                            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &sRarePickupItems[lvlDivBy10 + (99 - rand)]);
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
            #if P_SHUCKLE_BERRY_JUICE == TRUE
            else if (species == SPECIES_SHUCKLE
                && heldItem == ITEM_ORAN_BERRY
                && (Random() % 16) == 0)
            {
                heldItem = ITEM_BERRY_JUICE;
                SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &heldItem);
            }
            #endif
        }
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_doweatherformchangeanimation(void)
{
    CMD_ARGS();

    gActiveBattler = gBattleScripting.battler;

    if (gBattleMons[gActiveBattler].status2 & STATUS2_SUBSTITUTE)
        *(&gBattleStruct->formToChangeInto) |= CASTFORM_SUBSTITUTE;

    BtlController_EmitBattleAnimation(BUFFER_A, B_ANIM_CASTFORM_CHANGE, gBattleStruct->formToChangeInto);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_tryweatherformdatachange(void)
{
    CMD_ARGS();

    // removed in favor of new form system
}

// Water and Mud Sport
static void Cmd_settypebasedhalvers(void)
{
    CMD_ARGS(const u8 *failInstr);

    bool8 worked = FALSE;

    if (gBattleMoves[gCurrentMove].effect == EFFECT_MUD_SPORT)
    {
        #if B_SPORT_TURNS >= GEN_6
            if (!(gFieldStatuses & STATUS_FIELD_MUDSPORT))
            {
                gFieldStatuses |= STATUS_FIELD_MUDSPORT;
                gFieldTimers.mudSportTimer = 5;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEAKEN_ELECTRIC;
                worked = TRUE;
            }
        #else
            if (!(gStatuses4[gBattlerAttacker] & STATUS4_MUD_SPORT))
            {
                gStatuses4[gBattlerAttacker] |= STATUS4_MUD_SPORT;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEAKEN_ELECTRIC;
                worked = TRUE;
            }
        #endif
    }
    else // Water Sport
    {
        #if B_SPORT_TURNS >= GEN_6
            if (!(gFieldStatuses & STATUS_FIELD_WATERSPORT))
            {
                gFieldStatuses |= STATUS_FIELD_WATERSPORT;
                gFieldTimers.waterSportTimer = 5;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEAKEN_FIRE;
                worked = TRUE;
            }
        #else
            if (!(gStatuses4[gBattlerAttacker] & STATUS4_WATER_SPORT))
            {
                gStatuses4[gBattlerAttacker] |= STATUS4_WATER_SPORT;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEAKEN_FIRE;
                worked = TRUE;
            }
        #endif
    }

    if (worked)
        gBattlescriptCurrInstr = cmd->nextInstr;
    else
        gBattlescriptCurrInstr = cmd->failInstr;
}

bool32 DoesSubstituteBlockMove(u8 battlerAtk, u8 battlerDef, u32 move)
{
    if (!(gBattleMons[battlerDef].status2 & STATUS2_SUBSTITUTE))
        return FALSE;
#if B_SOUND_SUBSTITUTE >= GEN_6
    else if (gBattleMoves[move].flags & FLAG_SOUND)
        return FALSE;
#endif
    else if (gBattleMoves[move].flags & FLAG_HIT_IN_SUBSTITUTE)
        return FALSE;
    else if (GetBattlerAbility(battlerAtk) == ABILITY_INFILTRATOR)
        return FALSE;
    else
        return TRUE;
}

bool32 DoesDisguiseBlockMove(u8 battlerAtk, u8 battlerDef, u32 move)
{
    if (gBattleMons[battlerDef].species != SPECIES_MIMIKYU
        || gBattleMons[battlerDef].status2 & STATUS2_TRANSFORMED
        || IS_MOVE_STATUS(move)
        || gHitMarker & HITMARKER_IGNORE_DISGUISE
        || GetBattlerAbility(battlerDef) != ABILITY_DISGUISE)
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

    gActiveBattler = gBattlerAttacker;
    usedHeldItem = &gBattleStruct->usedHeldItems[gBattlerPartyIndexes[gActiveBattler]][GetBattlerSide(gActiveBattler)];
    if (*usedHeldItem != ITEM_NONE && gBattleMons[gActiveBattler].item == ITEM_NONE)
    {
        gLastUsedItem = *usedHeldItem;
        *usedHeldItem = ITEM_NONE;
        gBattleMons[gActiveBattler].item = gLastUsedItem;

        BtlController_EmitSetMonData(BUFFER_A, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].item), &gBattleMons[gActiveBattler].item);
        MarkBattlerForControllerExec(gActiveBattler);

        gBattlescriptCurrInstr = cmd->nextInstr;
    }
    else
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

bool32 CanCamouflage(u8 battlerId)
{
    if (IS_BATTLER_OF_TYPE(battlerId, sTerrainToType[gBattleTerrain]))
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

    if (!IS_BATTLER_OF_TYPE(gBattlerAttacker, terrainType))
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

    gActiveBattler = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gBattlerAttacker)));

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
        && !(gAbsentBattlerFlags & gBitTable[gActiveBattler])
        && gChosenActionByBattler[gActiveBattler] == B_ACTION_USE_MOVE
        && gChosenMoveByBattler[gActiveBattler] == MOVE_PURSUIT)
    {
        gActionsByTurnOrder[gActiveBattler] = B_ACTION_TRY_FINISH;
        gCurrentMove = MOVE_PURSUIT;
        gBattlescriptCurrInstr = cmd->nextInstr;
        gBattleScripting.animTurn = 1;
        gBattleScripting.savedBattler = gBattlerAttacker;
        gBattlerAttacker = gActiveBattler;
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

#if B_BRICK_BREAK >= GEN_4
// From Gen 4 onwards, Brick Break can remove screens on the user's side if used on an ally
    side = GetBattlerSide(gBattlerTarget);
#else
    side = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;
#endif

#if B_BRICK_BREAK >= GEN_5
    failed = (gMoveResultFlags & MOVE_RESULT_NO_EFFECT);
#else
    failed = FALSE;
#endif

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

    gActiveBattler = gBattlerAttacker;
    gBattlerTarget = GetCatchingBattler();

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        BtlController_EmitBallThrowAnim(BUFFER_A, BALL_TRAINER_BLOCK);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = BattleScript_TrainerBallBlock;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
    {
        BtlController_EmitBallThrowAnim(BUFFER_A, BALL_3_SHAKES_SUCCESS);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = BattleScript_WallyBallThrow;
    }
    else
    {
        u32 odds, i;
        u8 catchRate;

        gLastThrownBall = gLastUsedItem;
        if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            catchRate = gBattleStruct->safariCatchFactor * 1275 / 100;
        else
            catchRate = gSpeciesInfo[gBattleMons[gBattlerTarget].species].catchRate;

        if (gSpeciesInfo[gBattleMons[gBattlerTarget].species].flags & SPECIES_FLAG_ULTRA_BEAST)
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
        #if B_SPORT_BALL_MODIFIER <= GEN_7
            case ITEM_SPORT_BALL:
        #endif
            case ITEM_GREAT_BALL:
            case ITEM_SAFARI_BALL:
                ballMultiplier = 150;
                break;
            case ITEM_NET_BALL:
                if (IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_WATER) || IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_BUG))
                #if B_NET_BALL_MODIFIER >= GEN_7
                    ballMultiplier = 350;
                #else
                    ballMultiplier = 300;
                #endif
                break;
            case ITEM_DIVE_BALL:
                if (GetCurrentMapType() == MAP_TYPE_UNDERWATER
                #if B_DIVE_BALL_MODIFIER >= GEN_4
                    || gIsFishingEncounter || gIsSurfingEncounter
                #endif
                )
                    ballMultiplier = 350;
                break;
            case ITEM_NEST_BALL:
            #if B_NEST_BALL_MODIFIER >= GEN_6
                //((41 - Pokémon's level) ÷ 10)× if Pokémon's level is between 1 and 29, 1× otherwise.
                if (gBattleMons[gBattlerTarget].level < 30)
                    ballMultiplier = 410 - (gBattleMons[gBattlerTarget].level * 10);
            #elif B_NEST_BALL_MODIFIER == GEN_5
                //((41 - Pokémon's level) ÷ 10)×, minimum 1×
                if (gBattleMons[gBattlerTarget].level < 31)
                    ballMultiplier = 410 - (gBattleMons[gBattlerTarget].level * 10);
            #else
                //((40 - Pokémon's level) ÷ 10)×, minimum 1×
                if (gBattleMons[gBattlerTarget].level < 40)
                {
                    ballMultiplier = 400 - (gBattleMons[gBattlerTarget].level * 10);
                    if (ballMultiplier <= 90)
                        ballMultiplier = 100;
                }
            #endif
                break;
            case ITEM_REPEAT_BALL:
            if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gBattlerTarget].species), FLAG_GET_CAUGHT))
                #if B_REPEAT_BALL_MODIFIER >= GEN_7
                    ballMultiplier = 350;
                #else
                    ballMultiplier = 300;
                #endif
            break;
            case ITEM_TIMER_BALL:
            #if B_TIMER_BALL_MODIFIER >= GEN_5
                ballMultiplier = (gBattleResults.battleTurnCounter * 30) + 100;
            #else
                ballMultiplier = (gBattleResults.battleTurnCounter * 10) + 100;
            #endif
                if (ballMultiplier > 400)
                    ballMultiplier = 400;
                break;
            case ITEM_DUSK_BALL:
                RtcCalcLocalTime();
                if ((gLocalTime.hours >= 20 && gLocalTime.hours <= 3) || gMapHeader.cave || gMapHeader.mapType == MAP_TYPE_UNDERGROUND)
                #if B_DUSK_BALL_MODIFIER >= GEN_7
                    ballMultiplier = 300;
                #else
                    ballMultiplier = 350;
                #endif
                break;
            case ITEM_QUICK_BALL:
                if (gBattleResults.battleTurnCounter == 0)
                #if B_QUICK_BALL_MODIFIER >= GEN_5
                    ballMultiplier = 500;
                #else
                    ballMultiplier = 400;
                #endif
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
                #if B_LURE_BALL_MODIFIER >= GEN_7
                    ballMultiplier = 500;
                #else
                    ballMultiplier = 300;
                #endif
                break;
            case ITEM_MOON_BALL:
                for (i = 0; i < EVOS_PER_MON; i++)
                {
                    if (gEvolutionTable[gBattleMons[gBattlerTarget].species][i].method == EVO_ITEM
                        && gEvolutionTable[gBattleMons[gBattlerTarget].species][i].param == ITEM_MOON_STONE)
                        ballMultiplier = 400;
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
                i = GetPokedexHeightWeight(SpeciesToNationalPokedexNum(gBattleMons[gBattlerTarget].species), 1);
            #if B_HEAVY_BALL_MODIFIER >= GEN_7
                if (i < 1000)
                    ballAddition = -20;
                else if (i < 2000)
                    ballAddition = 0;
                else if (i < 3000)
                    ballAddition = 20;
                else
                    ballAddition = 30;
            #elif B_HEAVY_BALL_MODIFIER >= GEN_4
                if (i < 2048)
                    ballAddition = -20;
                else if (i < 3072)
                    ballAddition = 20;
                else if (i < 4096)
                    ballAddition = 30;
                else
                    ballAddition = 40;
            #else
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
            #endif
                break;
            case ITEM_DREAM_BALL:
            #if B_DREAM_BALL_MODIFIER >= GEN_8
                if (gBattleMons[gBattlerTarget].status1 & STATUS1_SLEEP || GetBattlerAbility(gBattlerTarget) == ABILITY_COMATOSE)
                    ballMultiplier = 400;
            #else
                ballMultiplier = 100;
            #endif
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
            BtlController_EmitBallThrowAnim(BUFFER_A, BALL_3_SHAKES_SUCCESS);
            MarkBattlerForControllerExec(gActiveBattler);
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
                HealStatusConditions(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], gBattlerPartyIndexes[gBattlerTarget], STATUS1_ANY, gBattlerTarget);
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

            BtlController_EmitBallThrowAnim(BUFFER_A, shakes);
            MarkBattlerForControllerExec(gActiveBattler);

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
                    HealStatusConditions(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], gBattlerPartyIndexes[gBattlerTarget], STATUS1_ANY, gBattlerTarget);
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

    u16 species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_SPECIES, NULL);
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
            FreeAllWindowBuffers();
            gBattleCommunication[TASK_ID] = DisplayCaughtMonDexPage(SpeciesToNationalPokedexNum(species),
                                                                        gBattleMons[GetCatchingBattler()].otId,
                                                                        gBattleMons[GetCatchingBattler()].personality);
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

static void Cmd_finishaction(void)
{
    CMD_ARGS();

    gCurrentActionFuncId = B_ACTION_FINISHED;
}

static void Cmd_finishturn(void)
{
    CMD_ARGS();

    gCurrentActionFuncId = B_ACTION_FINISHED;
    gCurrentTurnActionNumber = gBattlersCount;
}

static void Cmd_trainerslideout(void)
{
    CMD_ARGS(u8 position);

    gActiveBattler = GetBattlerAtPosition(cmd->position);
    BtlController_EmitTrainerSlideBack(BUFFER_A);
    MarkBattlerForControllerExec(gActiveBattler);

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

static void Cmd_averagestats(void)
{
    CMD_ARGS(u8 stat);

    u8 stat = cmd->stat;
    u16 atkStat = *(u16 *)((&gBattleMons[gBattlerAttacker].attack) + (stat - 1));
    u16 defStat = *(u16 *)((&gBattleMons[gBattlerTarget].attack) + (stat - 1));
    u16 average = (atkStat + defStat) / 2;

    *(u16 *)((&gBattleMons[gBattlerAttacker].attack) + (stat - 1)) = average;
    *(u16 *)((&gBattleMons[gBattlerTarget].attack) + (stat - 1)) = average;

    gBattlescriptCurrInstr = cmd->nextInstr;
}

static void Cmd_jumpifoppositegenders(void)
{
    CMD_ARGS(const u8 *jumpInstr);

    u32 atkGender = GetGenderFromSpeciesAndPersonality(gBattleMons[gBattlerAttacker].species, gBattleMons[gBattlerAttacker].personality);
    u32 defGender = GetGenderFromSpeciesAndPersonality(gBattleMons[gBattlerTarget].species, gBattleMons[gBattlerTarget].personality);

    if ((atkGender == MON_MALE && defGender == MON_FEMALE) || (atkGender == MON_FEMALE && defGender == MON_MALE))
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

    if (IsWorrySeedBannedAbility(gBattleMons[gBattlerTarget].ability))
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
        gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = TRUE;
        gBattlescriptCurrInstr = cmd->failInstr;
    }
}

void BS_JumpIfMoreThanHalfHP(void)
{
    NATIVE_ARGS(u8 battler, const u8 *jumpInstr);

    u8 battler = GetBattlerForBattleScript(cmd->battler);
    if (gBattleMons[battler].hp > (gBattleMons[battler].maxHP + 1) / 2)
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_JumpIfHoldEffect(void)
{
    u8 battler = gBattlescriptCurrInstr[5];
    u16 holdEffect = T1_READ_16(gBattlescriptCurrInstr + 6);

    if (GetBattlerHoldEffect(battler, TRUE) == holdEffect)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 8);
    }
    else
    {
        RecordItemEffectBattle(battler, holdEffect);
        gLastUsedItem = gBattleMons[battler].item;   // For B_LAST_USED_ITEM
        gBattlescriptCurrInstr += 12;
    }
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
#if B_CRITICAL_CAPTURE == TRUE
    u32 numCaught = GetNationalPokedexCount(FLAG_GET_CAUGHT);

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
#else
    return FALSE;
#endif
}

bool8 IsMoveAffectedByParentalBond(u16 move, u8 battlerId)
{
    if (gBattleMoves[move].split != SPLIT_STATUS
        && !(sForbiddenMoves[move] & FORBIDDEN_PARENTAL_BOND))
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            switch (GetBattlerMoveTargetType(battlerId, move))
            {
            // Both foes are alive, spread move strikes once
            case MOVE_TARGET_BOTH:
                if (CountAliveMonsInBattle(BATTLE_ALIVE_DEF_SIDE) >= 2)
                    return FALSE;
                break;
            // Either both foes or one foe and its ally are alive; spread move strikes once
            case MOVE_TARGET_FOES_AND_ALLY:
                if (CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_ATTACKER) >= 2)
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

static bool8 IsFinalStrikeEffect(u16 move)
{
    u32 i;
    u16 moveEffect = gBattleMoves[move].effect;

    for (i = 0; i < ARRAY_COUNT(sFinalStrikeOnlyEffects); i++)
    {
        if (moveEffect == sFinalStrikeOnlyEffects[i])
            return TRUE;
    }
    return FALSE;
}

static void TryUpdateRoundTurnOrder(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u32 i;
        u32 j = 0;
        u32 k = 0;
        u32 currRounder;
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
            gActionsByTurnOrder[currRounder] = gActionsByTurnOrder[roundUsers[i]];
            gProtectStructs[roundUsers[i]].quash = TRUE; // Make it so their turn order can't be changed again
            currRounder++;
        }

        // Update turn order for non-round users
        for (i = 0; nonRoundUsers[i] != 0xFF && i < 3; i++)
        {
            gBattlerByTurnOrder[currRounder] = nonRoundUsers[i];
            gActionsByTurnOrder[currRounder] = gActionsByTurnOrder[nonRoundUsers[i]];
            currRounder++;
        }
    }
}

u8 GetFirstFaintedPartyIndex(u8 battlerId)
{
    u32 i;
    u32 start = 0;
    u32 end = PARTY_SIZE;
    struct Pokemon *party = GetBattlerParty(battlerId);

    // Check whether partner is separate trainer.
    if ((GetBattlerSide(battlerId) == B_SIDE_PLAYER && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        || (GetBattlerSide(battlerId) == B_SIDE_OPPONENT && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
    {
        if (GetBattlerPosition(battlerId) == B_POSITION_OPPONENT_LEFT
            || GetBattlerPosition(battlerId) == B_POSITION_PLAYER_LEFT)
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

void BS_ItemRestoreHP(void) {
    NATIVE_ARGS();
    u16 healAmount;
    u32 battlerId = MAX_BATTLERS_COUNT;
    u32 healParam = GetItemEffect(gLastUsedItem)[6];
    u32 side = GetBattlerSide(gBattlerAttacker);
    struct Pokemon *party = GetSideParty(side);
    u16 hp = GetMonData(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], MON_DATA_HP);
    u16 maxHP = GetMonData(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], MON_DATA_MAX_HP);
    gBattleCommunication[MULTIUSE_STATE] = 0;

    // Track the number of Revives used in a battle.
    if (hp == 0 && side == B_SIDE_PLAYER && gBattleResults.numRevivesUsed < 255)
        gBattleResults.numRevivesUsed++;

    // Check if the recipient is an active battler.
    if (gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[gBattlerAttacker])
        battlerId = gBattlerAttacker;
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                && gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerAttacker)])
        battlerId = BATTLE_PARTNER(gBattlerAttacker);

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

    // Heal is applied as move damage if battler is active.
    if (battlerId != MAX_BATTLERS_COUNT && hp != 0)
    {
        gBattleMoveDamage = -healAmount;
    }
    else
    {
        hp += healAmount;
        SetMonData(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], MON_DATA_HP, &hp);

        // Revived battlers on the field need to be brought back.
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && battlerId != MAX_BATTLERS_COUNT)
        {
            gAbsentBattlerFlags &= ~gBitTable[battlerId];
            gBattleCommunication[MULTIUSE_STATE] = TRUE;
        }
    }
    PREPARE_SPECIES_BUFFER(gBattleTextBuff1, GetMonData(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], MON_DATA_SPECIES));
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_ItemCureStatus(void) {
    NATIVE_ARGS();
    struct Pokemon *party = GetBattlerParty(gBattlerAttacker);

    // Heal Status1 conditions.
    HealStatusConditions(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], gBattleStruct->itemPartyIndex[gBattlerAttacker], GetItemStatus1Mask(gLastUsedItem), gBattlerAttacker);

    // Heal Status2 conditions if battler is active.
    if (gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[gBattlerAttacker])
    {
        gBattleMons[gBattlerAttacker].status2 &= ~GetItemStatus2Mask(gLastUsedItem);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                && gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerAttacker)])
    {
        gBattleMons[gBattlerAttacker].status2 &= ~GetItemStatus2Mask(gLastUsedItem);
        gBattlerTarget = BATTLE_PARTNER(gBattlerAttacker);
    }

    if (GetItemStatus1Mask(gLastUsedItem) & STATUS1_SLEEP)
        gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;
    if (GetItemStatus2Mask(gLastUsedItem) & STATUS2_CONFUSION)
        gStatuses4[gBattlerAttacker] &= ~STATUS4_INFINITE_CONFUSION;

    PREPARE_SPECIES_BUFFER(gBattleTextBuff1, GetMonData(&party[gBattleStruct->itemPartyIndex[gBattlerAttacker]], MON_DATA_SPECIES));
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_ItemIncreaseStat(void) {
    NATIVE_ARGS();
    u16 statId = GetItemEffect(gLastUsedItem)[1];
    u16 stages = ItemId_GetHoldEffectParam(gLastUsedItem);
    SET_STATCHANGER(statId, stages, FALSE);
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_ItemRestorePP(void) {
    NATIVE_ARGS();
    const u8 *effect = GetItemEffect(gLastUsedItem);
    u32 i, pp, maxPP, moveId, loopEnd;
    u32 battlerId = MAX_BATTLERS_COUNT;
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
        battlerId = gBattlerAttacker;
    else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                && gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[BATTLE_PARTNER(gBattlerAttacker)])
        battlerId = BATTLE_PARTNER(gBattlerAttacker);

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
            if (battlerId != MAX_BATTLERS_COUNT
                && gBattleStruct->itemPartyIndex[gBattlerAttacker] == gBattlerPartyIndexes[battlerId]
                && MOVE_IS_PERMANENT(battlerId, i))
            {
                gBattleMons[battlerId].pp[i] = pp;
            }
        }
    }
    PREPARE_SPECIES_BUFFER(gBattleTextBuff1, GetMonData(mon, MON_DATA_SPECIES));
    gBattlescriptCurrInstr = cmd->nextInstr;
}

void BS_SetSnow(void)
{
    NATIVE_ARGS();

    if (!TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_SNOW, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WEATHER_FAILED;

    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_STARTED_SNOW;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}
