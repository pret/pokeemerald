#include "global.h"
#include "battle.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "battle_message.h"
#include "battle_anim.h"
#include "battle_ai_script_commands.h"
#include "battle_scripts.h"
#include "constants/moves.h"
#include "constants/abilities.h"
#include "item.h"
#include "constants/items.h"
#include "constants/hold_effects.h"
#include "util.h"
#include "pokemon.h"
#include "random.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "constants/species.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "constants/battle_anim.h"
#include "constants/map_types.h"
#include "text.h"
#include "sound.h"
#include "pokedex.h"
#include "recorded_battle.h"
#include "window.h"
#include "reshow_battle_screen.h"
#include "main.h"
#include "palette.h"
#include "money.h"
#include "bg.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "m4a.h"
#include "mail.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "task.h"
#include "naming_screen.h"
#include "constants/battle_string_ids.h"
#include "battle_setup.h"
#include "overworld.h"
#include "party_menu.h"
#include "constants/battle_config.h"
#include "battle_arena.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "field_specials.h"
#include "pokemon_summary_screen.h"
#include "pokenav.h"
#include "menu_specialized.h"
#include "constants/rgb.h"
#include "data.h"

extern struct MusicPlayerInfo gMPlayInfo_BGM;

extern const u8* const gBattleScriptsForMoveEffects[];

// this file's functions
#define STAT_CHANGE_WORKED      0
#define STAT_CHANGE_DIDNT_WORK  1

static bool8 IsTwoTurnsMove(u16 move);
static void TrySetDestinyBondToHappen(void);
static u8 AttacksThisTurn(u8 battlerId, u16 move); // Note: returns 1 if it's a charging turn, otherwise 2.
static u32 ChangeStatBuffs(s8 statValue, u32 statId, u32 flags, const u8 *BS_ptr);
static bool32 IsMonGettingExpSentOut(void);
static void sub_804F17C(void);
static bool8 sub_804F1CC(void);
static void DrawLevelUpWindow1(void);
static void DrawLevelUpWindow2(void);
static bool8 sub_804F344(void);
static void PutMonIconOnLvlUpBox(void);
static void PutLevelAndGenderOnLvlUpBox(void);

static void SpriteCB_MonIconOnLvlUpBox(struct Sprite* sprite);

static void atk00_attackcanceler(void);
static void atk01_accuracycheck(void);
static void atk02_attackstring(void);
static void atk03_ppreduce(void);
static void atk04_critcalc(void);
static void atk05_damagecalc(void);
static void atk06_typecalc(void);
static void atk07_adjustdamage(void);
static void atk08_multihitresultmessage(void);
static void atk09_attackanimation(void);
static void atk0A_waitanimation(void);
static void atk0B_healthbarupdate(void);
static void atk0C_datahpupdate(void);
static void atk0D_critmessage(void);
static void atk0E_effectivenesssound(void);
static void atk0F_resultmessage(void);
static void atk10_printstring(void);
static void atk11_printselectionstring(void);
static void atk12_waitmessage(void);
static void atk13_printfromtable(void);
static void atk14_printselectionstringfromtable(void);
static void atk15_seteffectwithchance(void);
static void atk16_seteffectprimary(void);
static void atk17_seteffectsecondary(void);
static void atk18_clearstatusfromeffect(void);
static void atk19_tryfaintmon(void);
static void atk1A_dofaintanimation(void);
static void atk1B_cleareffectsonfaint(void);
static void atk1C_jumpifstatus(void);
static void atk1D_jumpifstatus2(void);
static void atk1E_jumpifability(void);
static void atk1F_jumpifsideaffecting(void);
static void atk20_jumpifstat(void);
static void atk21_jumpifstatus3condition(void);
static void atk22_jumpbasedontype(void);
static void atk23_getexp(void);
static void atk24(void);
static void atk25_movevaluescleanup(void);
static void atk26_setmultihit(void);
static void atk27_decrementmultihit(void);
static void atk28_goto(void);
static void atk29_jumpifbyte(void);
static void atk2A_jumpifhalfword(void);
static void atk2B_jumpifword(void);
static void atk2C_jumpifarrayequal(void);
static void atk2D_jumpifarraynotequal(void);
static void atk2E_setbyte(void);
static void atk2F_addbyte(void);
static void atk30_subbyte(void);
static void atk31_copyarray(void);
static void atk32_copyarraywithindex(void);
static void atk33_orbyte(void);
static void atk34_orhalfword(void);
static void atk35_orword(void);
static void atk36_bicbyte(void);
static void atk37_bichalfword(void);
static void atk38_bicword(void);
static void atk39_pause(void);
static void atk3A_waitstate(void);
static void atk3B_healthbar_update(void);
static void atk3C_return(void);
static void atk3D_end(void);
static void atk3E_end2(void);
static void atk3F_end3(void);
static void atk40_jumpifaffectedbyprotect(void);
static void atk41_call(void);
static void atk42_setroost(void);
static void atk43_jumpifabilitypresent(void);
static void atk44_endselectionscript(void);
static void atk45_playanimation(void);
static void atk46_playanimation2(void);
static void atk47_setgraphicalstatchangevalues(void);
static void atk48_playstatchangeanimation(void);
static void atk49_moveend(void);
static void atk4A_sethealblock(void);
static void atk4B_returnatktoball(void);
static void atk4C_getswitchedmondata(void);
static void atk4D_switchindataupdate(void);
static void atk4E_switchinanim(void);
static void atk4F_jumpifcantswitch(void);
static void atk50_openpartyscreen(void);
static void atk51_switchhandleorder(void);
static void atk52_switchineffects(void);
static void atk53_trainerslidein(void);
static void atk54_playse(void);
static void atk55_fanfare(void);
static void atk56_playfaintcry(void);
static void atk57(void);
static void atk58_returntoball(void);
static void atk59_handlelearnnewmove(void);
static void atk5A_yesnoboxlearnmove(void);
static void atk5B_yesnoboxstoplearningmove(void);
static void atk5C_hitanimation(void);
static void atk5D_getmoneyreward(void);
static void atk5E(void);
static void atk5F_swapattackerwithtarget(void);
static void atk60_incrementgamestat(void);
static void atk61_drawpartystatussummary(void);
static void atk62_hidepartystatussummary(void);
static void atk63_jumptocalledmove(void);
static void atk64_statusanimation(void);
static void atk65_status2animation(void);
static void atk66_chosenstatusanimation(void);
static void atk67_yesnobox(void);
static void atk68_cancelallactions(void);
static void atk69_setgravity(void);
static void atk6A_removeitem(void);
static void atk6B_atknameinbuff1(void);
static void atk6C_drawlvlupbox(void);
static void atk6D_resetsentmonsvalue(void);
static void atk6E_setatktoplayer0(void);
static void atk6F_makevisible(void);
static void atk70_recordability(void);
static void atk71_buffermovetolearn(void);
static void atk72_jumpifplayerran(void);
static void atk73_hpthresholds(void);
static void atk74_hpthresholds2(void);
static void atk75_useitemonopponent(void);
static void atk76_various(void);
static void atk77_setprotectlike(void);
static void atk78_faintifabilitynotdamp(void);
static void atk79_setatkhptozero(void);
static void atk7A_jumpifnexttargetvalid(void);
static void atk7B_tryhealhalfhealth(void);
static void atk7C_trymirrormove(void);
static void atk7D_setrain(void);
static void atk7E_setreflect(void);
static void atk7F_setseeded(void);
static void atk80_manipulatedamage(void);
static void atk81_trysetrest(void);
static void atk82_jumpifnotfirstturn(void);
static void atk83_setmiracleeye(void);
static void atk84_jumpifcantmakeasleep(void);
static void atk85_stockpile(void);
static void atk86_stockpiletobasedamage(void);
static void atk87_stockpiletohpheal(void);
static void atk88_setdrainedhp(void);
static void atk89_statbuffchange(void);
static void atk8A_normalisebuffs(void);
static void atk8B_setbide(void);
static void atk8C_confuseifrepeatingattackends(void);
static void atk8D_setmultihitcounter(void);
static void atk8E_initmultihitstring(void);
static void atk8F_forcerandomswitch(void);
static void atk90_tryconversiontypechange(void);
static void atk91_givepaydaymoney(void);
static void atk92_setlightscreen(void);
static void atk93_tryKO(void);
static void atk94_damagetohalftargethp(void);
static void atk95_setsandstorm(void);
static void atk96_weatherdamage(void);
static void atk97_tryinfatuating(void);
static void atk98_updatestatusicon(void);
static void atk99_setmist(void);
static void atk9A_setfocusenergy(void);
static void atk9B_transformdataexecution(void);
static void atk9C_setsubstitute(void);
static void atk9D_mimicattackcopy(void);
static void atk9E_metronome(void);
static void atk9F_dmgtolevel(void);
static void atkA0_psywavedamageeffect(void);
static void atkA1_counterdamagecalculator(void);
static void atkA2_mirrorcoatdamagecalculator(void);
static void atkA3_disablelastusedattack(void);
static void atkA4_trysetencore(void);
static void atkA5_painsplitdmgcalc(void);
static void atkA6_settypetorandomresistance(void);
static void atkA7_setalwayshitflag(void);
static void atkA8_copymovepermanently(void);
static void atkA9_trychoosesleeptalkmove(void);
static void atkAA_setdestinybond(void);
static void atkAB_trysetdestinybondtohappen(void);
static void atkAC_settailwind(void);
static void atkAD_tryspiteppreduce(void);
static void atkAE_healpartystatus(void);
static void atkAF_cursetarget(void);
static void atkB0_trysetspikes(void);
static void atkB1_setforesight(void);
static void atkB2_trysetperishsong(void);
static void atkB3_handlerollout(void);
static void atkB4_jumpifconfusedandstatmaxed(void);
static void atkB5_handlefurycutter(void);
static void atkB6_setembargo(void);
static void atkB7_presentdamagecalculation(void);
static void atkB8_setsafeguard(void);
static void atkB9_magnitudedamagecalculation(void);
static void atkBA_jumpifnopursuitswitchdmg(void);
static void atkBB_setsunny(void);
static void atkBC_maxattackhalvehp(void);
static void atkBD_copyfoestats(void);
static void atkBE_rapidspinfree(void);
static void atkBF_setdefensecurlbit(void);
static void atkC0_recoverbasedonsunlight(void);
static void atkC1_setstickyweb(void);
static void atkC2_selectfirstvalidtarget(void);
static void atkC3_trysetfutureattack(void);
static void atkC4_trydobeatup(void);
static void atkC5_setsemiinvulnerablebit(void);
static void atkC6_clearsemiinvulnerablebit(void);
static void atkC7_setminimize(void);
static void atkC8_sethail(void);
static void atkC9_jumpifattackandspecialattackcannotfall(void);
static void atkCA_setforcedtarget(void);
static void atkCB_setcharge(void);
static void atkCC_callterrainattack(void);
static void atkCD_cureifburnedparalysedorpoisoned(void);
static void atkCE_settorment(void);
static void atkCF_jumpifnodamage(void);
static void atkD0_settaunt(void);
static void atkD1_trysethelpinghand(void);
static void atkD2_tryswapitems(void);
static void atkD3_trycopyability(void);
static void atkD4_trywish(void);
static void atkD5_settoxicspikes(void);
static void atkD6_setgastroacid(void);
static void atkD7_setyawn(void);
static void atkD8_setdamagetohealthdifference(void);
static void atkD9_setroom(void);
static void atkDA_tryswapabilities(void);
static void atkDB_tryimprison(void);
static void atkDC_setstealthrock(void);
static void atkDD_setuserstatus3(void);
static void atkDE_assistattackselect(void);
static void atkDF_trysetmagiccoat(void);
static void atkE0_trysetsnatch(void);
static void atkE1_trygetintimidatetarget(void);
static void atkE2_switchoutabilities(void);
static void atkE3_jumpifhasnohp(void);
static void atkE4_getsecretpowereffect(void);
static void atkE5_pickup(void);
static void atkE6_docastformchangeanimation(void);
static void atkE7_trycastformdatachange(void);
static void atkE8_settypebasedhalvers(void);
static void atkE9_jumpifsubstituteblocks(void);
static void atkEA_tryrecycleitem(void);
static void atkEB_settypetoterrain(void);
static void atkEC_pursuitrelated(void);
static void atkEF_snatchsetbattlers(void);
static void atkEE_removelightscreenreflect(void);
static void atkEF_handleballthrow(void);
static void atkF0_givecaughtmon(void);
static void atkF1_trysetcaughtmondexflags(void);
static void atkF2_displaydexinfo(void);
static void atkF3_trygivecaughtmonnick(void);
static void atkF4_subattackerhpbydmg(void);
static void atkF5_removeattackerstatus1(void);
static void atkF6_finishaction(void);
static void atkF7_finishturn(void);
static void atkF8_trainerslideout(void);
static void atkF9_settelekinesis(void);
static void atkFA_swapstatstages(void);
static void atkFB_averagestats(void);
static void atkFC_jumpifoppositegenders(void);
static void atkFD_trygetbaddreamstarget(void);
static void atkFE_tryworryseed(void);
static void atkFF_metalburstdamagecalculator(void);

void (* const gBattleScriptingCommandsTable[])(void) =
{
    atk00_attackcanceler,
    atk01_accuracycheck,
    atk02_attackstring,
    atk03_ppreduce,
    atk04_critcalc,
    atk05_damagecalc,
    atk06_typecalc,
    atk07_adjustdamage,
    atk08_multihitresultmessage,
    atk09_attackanimation,
    atk0A_waitanimation,
    atk0B_healthbarupdate,
    atk0C_datahpupdate,
    atk0D_critmessage,
    atk0E_effectivenesssound,
    atk0F_resultmessage,
    atk10_printstring,
    atk11_printselectionstring,
    atk12_waitmessage,
    atk13_printfromtable,
    atk14_printselectionstringfromtable,
    atk15_seteffectwithchance,
    atk16_seteffectprimary,
    atk17_seteffectsecondary,
    atk18_clearstatusfromeffect,
    atk19_tryfaintmon,
    atk1A_dofaintanimation,
    atk1B_cleareffectsonfaint,
    atk1C_jumpifstatus,
    atk1D_jumpifstatus2,
    atk1E_jumpifability,
    atk1F_jumpifsideaffecting,
    atk20_jumpifstat,
    atk21_jumpifstatus3condition,
    atk22_jumpbasedontype,
    atk23_getexp,
    atk24,
    atk25_movevaluescleanup,
    atk26_setmultihit,
    atk27_decrementmultihit,
    atk28_goto,
    atk29_jumpifbyte,
    atk2A_jumpifhalfword,
    atk2B_jumpifword,
    atk2C_jumpifarrayequal,
    atk2D_jumpifarraynotequal,
    atk2E_setbyte,
    atk2F_addbyte,
    atk30_subbyte,
    atk31_copyarray,
    atk32_copyarraywithindex,
    atk33_orbyte,
    atk34_orhalfword,
    atk35_orword,
    atk36_bicbyte,
    atk37_bichalfword,
    atk38_bicword,
    atk39_pause,
    atk3A_waitstate,
    atk3B_healthbar_update,
    atk3C_return,
    atk3D_end,
    atk3E_end2,
    atk3F_end3,
    atk40_jumpifaffectedbyprotect,
    atk41_call,
    atk42_setroost,
    atk43_jumpifabilitypresent,
    atk44_endselectionscript,
    atk45_playanimation,
    atk46_playanimation2,
    atk47_setgraphicalstatchangevalues,
    atk48_playstatchangeanimation,
    atk49_moveend,
    atk4A_sethealblock,
    atk4B_returnatktoball,
    atk4C_getswitchedmondata,
    atk4D_switchindataupdate,
    atk4E_switchinanim,
    atk4F_jumpifcantswitch,
    atk50_openpartyscreen,
    atk51_switchhandleorder,
    atk52_switchineffects,
    atk53_trainerslidein,
    atk54_playse,
    atk55_fanfare,
    atk56_playfaintcry,
    atk57,
    atk58_returntoball,
    atk59_handlelearnnewmove,
    atk5A_yesnoboxlearnmove,
    atk5B_yesnoboxstoplearningmove,
    atk5C_hitanimation,
    atk5D_getmoneyreward,
    atk5E,
    atk5F_swapattackerwithtarget,
    atk60_incrementgamestat,
    atk61_drawpartystatussummary,
    atk62_hidepartystatussummary,
    atk63_jumptocalledmove,
    atk64_statusanimation,
    atk65_status2animation,
    atk66_chosenstatusanimation,
    atk67_yesnobox,
    atk68_cancelallactions,
    atk69_setgravity,
    atk6A_removeitem,
    atk6B_atknameinbuff1,
    atk6C_drawlvlupbox,
    atk6D_resetsentmonsvalue,
    atk6E_setatktoplayer0,
    atk6F_makevisible,
    atk70_recordability,
    atk71_buffermovetolearn,
    atk72_jumpifplayerran,
    atk73_hpthresholds,
    atk74_hpthresholds2,
    atk75_useitemonopponent,
    atk76_various,
    atk77_setprotectlike,
    atk78_faintifabilitynotdamp,
    atk79_setatkhptozero,
    atk7A_jumpifnexttargetvalid,
    atk7B_tryhealhalfhealth,
    atk7C_trymirrormove,
    atk7D_setrain,
    atk7E_setreflect,
    atk7F_setseeded,
    atk80_manipulatedamage,
    atk81_trysetrest,
    atk82_jumpifnotfirstturn,
    atk83_setmiracleeye,
    atk84_jumpifcantmakeasleep,
    atk85_stockpile,
    atk86_stockpiletobasedamage,
    atk87_stockpiletohpheal,
    atk88_setdrainedhp,
    atk89_statbuffchange,
    atk8A_normalisebuffs,
    atk8B_setbide,
    atk8C_confuseifrepeatingattackends,
    atk8D_setmultihitcounter,
    atk8E_initmultihitstring,
    atk8F_forcerandomswitch,
    atk90_tryconversiontypechange,
    atk91_givepaydaymoney,
    atk92_setlightscreen,
    atk93_tryKO,
    atk94_damagetohalftargethp,
    atk95_setsandstorm,
    atk96_weatherdamage,
    atk97_tryinfatuating,
    atk98_updatestatusicon,
    atk99_setmist,
    atk9A_setfocusenergy,
    atk9B_transformdataexecution,
    atk9C_setsubstitute,
    atk9D_mimicattackcopy,
    atk9E_metronome,
    atk9F_dmgtolevel,
    atkA0_psywavedamageeffect,
    atkA1_counterdamagecalculator,
    atkA2_mirrorcoatdamagecalculator,
    atkA3_disablelastusedattack,
    atkA4_trysetencore,
    atkA5_painsplitdmgcalc,
    atkA6_settypetorandomresistance,
    atkA7_setalwayshitflag,
    atkA8_copymovepermanently,
    atkA9_trychoosesleeptalkmove,
    atkAA_setdestinybond,
    atkAB_trysetdestinybondtohappen,
    atkAC_settailwind,
    atkAD_tryspiteppreduce,
    atkAE_healpartystatus,
    atkAF_cursetarget,
    atkB0_trysetspikes,
    atkB1_setforesight,
    atkB2_trysetperishsong,
    atkB3_handlerollout,
    atkB4_jumpifconfusedandstatmaxed,
    atkB5_handlefurycutter,
    atkB6_setembargo,
    atkB7_presentdamagecalculation,
    atkB8_setsafeguard,
    atkB9_magnitudedamagecalculation,
    atkBA_jumpifnopursuitswitchdmg,
    atkBB_setsunny,
    atkBC_maxattackhalvehp,
    atkBD_copyfoestats,
    atkBE_rapidspinfree,
    atkBF_setdefensecurlbit,
    atkC0_recoverbasedonsunlight,
    atkC1_setstickyweb,
    atkC2_selectfirstvalidtarget,
    atkC3_trysetfutureattack,
    atkC4_trydobeatup,
    atkC5_setsemiinvulnerablebit,
    atkC6_clearsemiinvulnerablebit,
    atkC7_setminimize,
    atkC8_sethail,
    atkC9_jumpifattackandspecialattackcannotfall,
    atkCA_setforcedtarget,
    atkCB_setcharge,
    atkCC_callterrainattack,
    atkCD_cureifburnedparalysedorpoisoned,
    atkCE_settorment,
    atkCF_jumpifnodamage,
    atkD0_settaunt,
    atkD1_trysethelpinghand,
    atkD2_tryswapitems,
    atkD3_trycopyability,
    atkD4_trywish,
    atkD5_settoxicspikes,
    atkD6_setgastroacid,
    atkD7_setyawn,
    atkD8_setdamagetohealthdifference,
    atkD9_setroom,
    atkDA_tryswapabilities,
    atkDB_tryimprison,
    atkDC_setstealthrock,
    atkDD_setuserstatus3,
    atkDE_assistattackselect,
    atkDF_trysetmagiccoat,
    atkE0_trysetsnatch,
    atkE1_trygetintimidatetarget,
    atkE2_switchoutabilities,
    atkE3_jumpifhasnohp,
    atkE4_getsecretpowereffect,
    atkE5_pickup,
    atkE6_docastformchangeanimation,
    atkE7_trycastformdatachange,
    atkE8_settypebasedhalvers,
    atkE9_jumpifsubstituteblocks,
    atkEA_tryrecycleitem,
    atkEB_settypetoterrain,
    atkEC_pursuitrelated,
    atkEF_snatchsetbattlers,
    atkEE_removelightscreenreflect,
    atkEF_handleballthrow,
    atkF0_givecaughtmon,
    atkF1_trysetcaughtmondexflags,
    atkF2_displaydexinfo,
    atkF3_trygivecaughtmonnick,
    atkF4_subattackerhpbydmg,
    atkF5_removeattackerstatus1,
    atkF6_finishaction,
    atkF7_finishturn,
    atkF8_trainerslideout,
    atkF9_settelekinesis,
    atkFA_swapstatstages,
    atkFB_averagestats,
    atkFC_jumpifoppositegenders,
    atkFD_trygetbaddreamstarget,
    atkFE_tryworryseed,
    atkFF_metalburstdamagecalculator,
};

struct StatFractions
{
    u8 dividend;
    u8 divisor;
};

static const struct StatFractions sAccuracyStageRatios[] =
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

static const u32 sStatusFlagsForMoveEffects[] =
{
    0x00000000,
    STATUS1_SLEEP,
    STATUS1_POISON,
    STATUS1_BURN,
    STATUS1_FREEZE,
    STATUS1_PARALYSIS,
    STATUS1_TOXIC_POISON,
    STATUS2_CONFUSION,
    STATUS2_FLINCHED,
    0x00000000,
    STATUS2_UPROAR,
    0x00000000,
    STATUS2_MULTIPLETURNS,
    STATUS2_WRAPPED,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    STATUS2_RECHARGE,
    0x00000000,
    0x00000000,
    STATUS2_ESCAPE_PREVENTION,
    STATUS2_NIGHTMARE,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    STATUS2_LOCK_CONFUSE,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000
};

static const u8* const sMoveEffectBS_Ptrs[] =
{
    [MOVE_EFFECT_SLEEP] = BattleScript_MoveEffectSleep,
    [MOVE_EFFECT_POISON] = BattleScript_MoveEffectPoison,
    [MOVE_EFFECT_BURN] = BattleScript_MoveEffectBurn,
    [MOVE_EFFECT_FREEZE] = BattleScript_MoveEffectFreeze,
    [MOVE_EFFECT_PARALYSIS] = BattleScript_MoveEffectParalysis,
    [MOVE_EFFECT_TOXIC] = BattleScript_MoveEffectToxic,
    [MOVE_EFFECT_CONFUSION] = BattleScript_MoveEffectConfusion,
    [MOVE_EFFECT_UPROAR] = BattleScript_MoveEffectUproar,
    [MOVE_EFFECT_PAYDAY] = BattleScript_MoveEffectPayDay,
    [MOVE_EFFECT_WRAP] = BattleScript_MoveEffectWrap,
    [MOVE_EFFECT_RECOIL_25] = BattleScript_MoveEffectRecoil,
    [MOVE_EFFECT_RECOIL_33] = BattleScript_MoveEffectRecoil,
};

static const struct WindowTemplate sUnusedWinTemplate = {0, 1, 3, 7, 0xF, 0x1F, 0x3F};

static const u16 sUnknown_0831C2C8[] = INCBIN_U16("graphics/battle_interface/unk_battlebox.gbapal");
static const u32 sUnknown_0831C2E8[] = INCBIN_U32("graphics/battle_interface/unk_battlebox.4bpp.lz");

#define MON_ICON_LVLUP_BOX_TAG      0xD75A

static const struct OamData sOamData_MonIconOnLvlUpBox =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_MonIconOnLvlUpBox =
{
    .tileTag = MON_ICON_LVLUP_BOX_TAG,
    .paletteTag = MON_ICON_LVLUP_BOX_TAG,
    .oam = &sOamData_MonIconOnLvlUpBox,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MonIconOnLvlUpBox
};

static const u16 sProtectSuccessRates[] = {USHRT_MAX, USHRT_MAX / 2, USHRT_MAX / 4, USHRT_MAX / 8};

#define MIMIC_FORBIDDEN_END             0xFFFE
#define METRONOME_FORBIDDEN_END         0xFFFF
#define ASSIST_FORBIDDEN_END            0xFFFF
#define COPYCAT_FORBIDDEN_END           0xFFFF
#define INSTRUCT_FORBIDDEN_END          0xFFFF

static const u16 sMovesForbiddenToCopy[] =
{
    MOVE_TRANSFORM,
    MOVE_METRONOME,
    MOVE_STRUGGLE,
    MOVE_SKETCH,
    MOVE_MIMIC,
    MIMIC_FORBIDDEN_END,
    MOVE_COUNTER,
    MOVE_MIRROR_COAT,
    MOVE_PROTECT,
    MOVE_DETECT,
    MOVE_ENDURE,
    MOVE_DESTINY_BOND,
    MOVE_SLEEP_TALK,
    MOVE_THIEF,
    MOVE_FOLLOW_ME,
    MOVE_SNATCH,
    MOVE_HELPING_HAND,
    MOVE_COVET,
    MOVE_TRICK,
    MOVE_FOCUS_PUNCH,
    MOVE_CIRCLE_THROW,
    MOVE_DRAGON_TAIL,
    MOVE_RAGE_POWDER,
    MOVE_MAT_BLOCK,
    MOVE_SPIKY_SHIELD,
    MOVE_SHELL_TRAP,
    MOVE_SPOTLIGHT,
    MOVE_FEINT,
    MOVE_KING_S_SHIELD,
    METRONOME_FORBIDDEN_END
};


static const u16 sMoveEffectsForbiddenToInstruct[] =
{
    EFFECT_ASSIST,
    //EFFECT_BEAK_BLAST,
    EFFECT_BIDE,
    EFFECT_FOCUS_PUNCH,
    //EFFECT_GEOMANCY,
    EFFECT_INSTRUCT,
    EFFECT_ME_FIRST,
    EFFECT_METRONOME,
    EFFECT_MIRROR_MOVE,
    EFFECT_NATURE_POWER,
    EFFECT_PLACEHOLDER,
    EFFECT_RECHARGE,
    EFFECT_SEMI_INVULNERABLE,
    //EFFECT_SHELL_TRAP,
    EFFECT_SKETCH,
    //EFFECT_SKY_DROP,
    EFFECT_SKULL_BASH,
    EFFECT_SLEEP_TALK,
    EFFECT_SOLARBEAM,
    EFFECT_TRANSFORM,
    EFFECT_TWO_TURNS_ATTACK,
    INSTRUCT_FORBIDDEN_END
};

static const u16 sNaturePowerMoves[] =
{
    MOVE_STUN_SPORE,
    MOVE_RAZOR_LEAF,
    MOVE_EARTHQUAKE,
    MOVE_HYDRO_PUMP,
    MOVE_SURF,
    MOVE_BUBBLE_BEAM,
    MOVE_ROCK_SLIDE,
    MOVE_SHADOW_BALL,
    MOVE_SWIFT,
    MOVE_SWIFT
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

static const u8 sTerrainToType[] =
{
    TYPE_GRASS, // tall grass
    TYPE_GRASS, // long grass
    TYPE_GROUND, // sand
    TYPE_WATER, // underwater
    TYPE_WATER, // water
    TYPE_WATER, // pond water
    TYPE_ROCK, // rock
    TYPE_ROCK, // cave
    TYPE_NORMAL, // building
    TYPE_NORMAL, // plain
};

static const u8 sBallCatchBonuses[] =
{
    20, 15, 10, 15 // Ultra, Great, Poke, Safari
};

const ALIGNED(4) u8 gUnknown_0831C494[][4] =
{
    {0x3d, 0x44, 0x3d, 0x44},
    {0x14, 0x2d, 0x54, 0x5c},
    {0x46, 0x55, 0x20, 0x5c},
    {0x26, 0x45, 0x46, 0x55},
    {0x14, 0x5a, 0x46, 0x5c},
    {0x1e, 0x32, 0x20, 0x5a},
    {0x38, 0x4e, 0x38, 0x4e},
    {0x19, 0x28, 0x4b, 0x5a},
    {0x45, 0x4b, 0x1c, 0x53},
    {0x23, 0x2d, 0x1d, 0x23},
    {0x3e, 0x48, 0x1e, 0x32},
    {0x3a, 0x5f, 0x58, 0x5e},
    {0x22, 0x2d, 0x1d, 0x28},
    {0x23, 0x28, 0x23, 0x5f},
    {0x38, 0x4e, 0x38, 0x4e},
    {0x23, 0x50, 0x22, 0x5e},
    {0x2c, 0x5e, 0x22, 0x28},
    {0x38, 0x4e, 0x38, 0x4e},
    {0x1e, 0x58, 0x1e, 0x58},
    {0x1e, 0x2b, 0x1b, 0x21},
    {0x28, 0x5a, 0x19, 0x57},
    {0x12, 0x58, 0x5a, 0x5f},
    {0x58, 0x5e, 0x16, 0x2a},
    {0x2a, 0x5c, 0x2a, 0x2f},
    {0x38, 0x4e, 0x38, 0x4e}
};

static const u8 sUnknown_0831C4F8[] =
{
    0x03, 0x00, 0x01, 0x00, 0x00, 0x01, 0x03, 0x00,
    0x01, 0x02, 0x02, 0x00, 0x03, 0x01, 0x03, 0x01,
    0x02, 0x03, 0x03, 0x02, 0x01, 0x00, 0x02, 0x02,
    0x03, 0x00, 0x00, 0x00
};

bool32 IsBattlerProtected(u8 battlerId, u16 move)
{
    if (!(gBattleMoves[move].flags & FLAG_PROTECT_AFFECTED))
        return FALSE;
    else if (gBattleMoves[move].effect == MOVE_EFFECT_FEINT)
        return FALSE;
    else if (gProtectStructs[battlerId].protected)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_WIDE_GUARD
             && gBattleMoves[move].target & (MOVE_TARGET_BOTH | MOVE_TARGET_FOES_AND_ALLY))
        return TRUE;
    else if (gProtectStructs[battlerId].banefulBunkered)
        return TRUE;
    else if (gProtectStructs[battlerId].spikyShielded)
        return TRUE;
    else if (gProtectStructs[battlerId].kingsShielded && gBattleMoves[move].power != 0)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_QUICK_GUARD
             && GetChosenMovePriority(gBattlerAttacker) > 0)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_CRAFTY_SHIELD
             && gBattleMoves[move].power == 0)
        return TRUE;
    else if (gSideStatuses[GetBattlerSide(battlerId)] & SIDE_STATUS_MAT_BLOCK
             && gBattleMoves[move].power != 0)
        return TRUE;
    else
        return FALSE;
}

static void atk00_attackcanceler(void)
{
    s32 i;
    u32 moveType;

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
    if (AtkCanceller_UnableToUseMove())
        return;

    // Check Protean activation.
    GET_MOVE_TYPE(gCurrentMove, moveType);
    if (GetBattlerAbility(gBattlerAttacker) == ABILITY_PROTEAN
        && (gBattleMons[gBattlerAttacker].type1 != moveType || gBattleMons[gBattlerAttacker].type2 != moveType ||
            (gBattleMons[gBattlerAttacker].type3 != moveType && gBattleMons[gBattlerAttacker].type3 != TYPE_MYSTERY))
        && gCurrentMove != MOVE_STRUGGLE)
    {
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
        SET_BATTLER_TYPE(gBattlerAttacker, moveType);
        gBattlerAbility = gBattlerAttacker;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_ProteanActivates;
        return;
    }

    if (AtkCanceller_UnableToUseMove2())
        return;
    if (AbilityBattleEffects(ABILITYEFFECT_MOVES_BLOCK, gBattlerTarget, 0, 0, 0))
        return;
    if (!gBattleMons[gBattlerAttacker].pp[gCurrMovePos] && gCurrentMove != MOVE_STRUGGLE && !(gHitMarker & (HITMARKER_x800000 | HITMARKER_NO_ATTACKSTRING))
     && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))
    {
        gBattlescriptCurrInstr = BattleScript_NoPPForMove;
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        return;
    }

    gHitMarker &= ~(HITMARKER_x800000);

    if (!(gHitMarker & HITMARKER_OBEYS) && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))
    {
        i = IsMonDisobedient(); // why use the 'i' variable...?
        switch (i)
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

    if (gProtectStructs[gBattlerTarget].bounceMove
        && gBattleMoves[gCurrentMove].flags & FLAG_MAGICCOAT_AFFECTED
        && !gProtectStructs[gBattlerAttacker].usesBouncedMove)
    {
        PressurePPLose(gBattlerAttacker, gBattlerTarget, MOVE_MAGIC_COAT);
        gProtectStructs[gBattlerTarget].bounceMove = 0;
        gProtectStructs[gBattlerTarget].usesBouncedMove = 1;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_MagicCoatBounce;
        return;
    }
    else if (GetBattlerAbility(gBattlerTarget) == ABILITY_MAGIC_BOUNCE
             && gBattleMoves[gCurrentMove].flags & FLAG_MAGICCOAT_AFFECTED
             && !gProtectStructs[gBattlerAttacker].usesBouncedMove)
    {
        RecordAbilityBattle(gBattlerTarget, ABILITY_MAGIC_BOUNCE);
        gProtectStructs[gBattlerTarget].usesBouncedMove = 1;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_MagicCoatBounce;
        return;
    }

    for (i = 0; i < gBattlersCount; i++)
    {
        if ((gProtectStructs[gBattlerByTurnOrder[i]].stealMove) && gBattleMoves[gCurrentMove].flags & FLAG_SNATCH_AFFECTED)
        {
            PressurePPLose(gBattlerAttacker, gBattlerByTurnOrder[i], MOVE_SNATCH);
            gProtectStructs[gBattlerByTurnOrder[i]].stealMove = 0;
            gBattleScripting.battler = gBattlerByTurnOrder[i];
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_SnatchedMove;
            return;
        }
    }

    if (gSpecialStatuses[gBattlerTarget].lightningRodRedirected)
    {
        gSpecialStatuses[gBattlerTarget].lightningRodRedirected = 0;
        gLastUsedAbility = ABILITY_LIGHTNING_ROD;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_TookAttack;
        RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
    }
    else if (gSpecialStatuses[gBattlerTarget].stormDrainRedirected)
    {
        gSpecialStatuses[gBattlerTarget].stormDrainRedirected = 0;
        gLastUsedAbility = ABILITY_STORM_DRAIN;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_TookAttack;
        RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
    }
    else if (IsBattlerProtected(gBattlerTarget, gCurrentMove)
     && (gCurrentMove != MOVE_CURSE || IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GHOST))
     && ((!IsTwoTurnsMove(gCurrentMove) || (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS))))
    {
        CancelMultiTurnMoves(gBattlerAttacker);
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gLastLandedMoves[gBattlerTarget] = 0;
        gLastHitByType[gBattlerTarget] = 0;
        gBattleCommunication[6] = 1;
        gBattlescriptCurrInstr++;
    }
    else
    {
        gBattlescriptCurrInstr++;
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

static void atk40_jumpifaffectedbyprotect(void)
{
    if (IsBattlerProtected(gBattlerTarget, gCurrentMove))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(5, 0);
        gBattleCommunication[6] = 1;
    }
    else
    {
        gBattlescriptCurrInstr += 5;
    }
}

bool8 JumpIfMoveAffectedByProtect(u16 move)
{
    bool8 affected = FALSE;
    if (IsBattlerProtected(gBattlerTarget, move))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        gBattleCommunication[6] = 1;
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
    else if (gBattleMoves[move].effect == EFFECT_TOXIC && IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_POISON))
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }
    else if (GetBattlerAbility(gBattlerAttacker) == ABILITY_NO_GUARD)
    {
        if (!JumpIfMoveFailed(7, move))
            RecordAbilityBattle(gBattlerAttacker, ABILITY_NO_GUARD);
        return TRUE;
    }
    else if (GetBattlerAbility(gBattlerTarget) == ABILITY_NO_GUARD)
    {
        if (!JumpIfMoveFailed(7, move))
            RecordAbilityBattle(gBattlerTarget, ABILITY_NO_GUARD);
        return TRUE;
    }

    if (!(gHitMarker & HITMARKER_IGNORE_ON_AIR) && gStatuses3[gBattlerTarget] & STATUS3_ON_AIR)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }
    gHitMarker &= ~HITMARKER_IGNORE_ON_AIR;

    if (!(gHitMarker & HITMARKER_IGNORE_UNDERGROUND) && gStatuses3[gBattlerTarget] & STATUS3_UNDERGROUND)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }
    gHitMarker &= ~HITMARKER_IGNORE_UNDERGROUND;

    if (!(gHitMarker & HITMARKER_IGNORE_UNDERWATER) && gStatuses3[gBattlerTarget] & STATUS3_UNDERWATER)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }
    gHitMarker &= ~HITMARKER_IGNORE_UNDERWATER;

    if (gStatuses3[gBattlerTarget] & STATUS3_PHANTOM_FORCE)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    if ((WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_RAIN_ANY) && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
     || (gBattleMoves[move].effect == EFFECT_VITAL_THROW)
     || (gBattleMoves[move].accuracy == 0))
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    return FALSE;
}

static void atk01_accuracycheck(void)
{
    u16 move = T2_READ_16(gBattlescriptCurrInstr + 5);

    if (move == ACC_CURR_MOVE)
        move = gCurrentMove;

    if (move == NO_ACC_CALC_CHECK_LOCK_ON)
    {
        if (gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBattlerTarget].battlerWithSureHit == gBattlerAttacker)
            gBattlescriptCurrInstr += 7;
        else if (gStatuses3[gBattlerTarget] & (STATUS3_SEMI_INVULNERABLE))
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        else if (!JumpIfMoveAffectedByProtect(0))
            gBattlescriptCurrInstr += 7;
    }
    else
    {
        u8 type, moveAcc, atkHoldEffect, atkParam, defHoldEffect, defParam, atkAbility, defAbility;
        s8 buff, accStage, evasionStage;
        u32 calc;

        GET_MOVE_TYPE(move, type);

        if (JumpIfMoveAffectedByProtect(move))
            return;
        if (AccuracyCalcHelper(move))
            return;

        atkAbility = GetBattlerAbility(gBattlerAttacker);
        defAbility = GetBattlerAbility(gBattlerTarget);

        accStage = gBattleMons[gBattlerAttacker].statStages[STAT_ACC];
        evasionStage = gBattleMons[gBattlerTarget].statStages[STAT_EVASION];
        if (atkAbility == ABILITY_UNAWARE)
            evasionStage = 6;
        if (gBattleMoves[move].flags & FLAG_STAT_STAGES_IGNORED)
            evasionStage = 6;
        if (defAbility == ABILITY_UNAWARE)
            accStage = 6;

        if (gBattleMons[gBattlerTarget].status2 & STATUS2_FORESIGHT || gStatuses3[gBattlerTarget] & STATUS3_MIRACLE_EYED)
            buff = accStage;
        else
            buff = accStage + 6 - evasionStage;

        if (buff < 0)
            buff = 0;
        if (buff > 0xC)
            buff = 0xC;

        moveAcc = gBattleMoves[move].accuracy;
        // Check Thunder and Hurricane on sunny weather.
        if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY && (gBattleMoves[move].effect == EFFECT_THUNDER || gBattleMoves[move].effect == EFFECT_HURRICANE))
            moveAcc = 50;
        // Check Wonder Skin.
        if (defAbility == ABILITY_WONDER_SKIN && gBattleMoves[move].power == 0)
            moveAcc = 50;

        calc = sAccuracyStageRatios[buff].dividend * moveAcc;
        calc /= sAccuracyStageRatios[buff].divisor;

        if (atkAbility == ABILITY_COMPOUND_EYES)
            calc = (calc * 130) / 100; // 1.3 compound eyes boost
        else if (atkAbility == ABILITY_VICTORY_STAR)
            calc = (calc * 110) / 100; // 1.1 victory star boost
        if (IsBattlerAlive(BATTLE_PARTNER(gBattlerAttacker)) && GetBattlerAbility(BATTLE_PARTNER(gBattlerAttacker)) == ABILITY_VICTORY_STAR)
            calc = (calc * 110) / 100; // 1.1 ally's victory star boost

        if (defAbility == ABILITY_SAND_VEIL && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SANDSTORM_ANY)
            calc = (calc * 80) / 100; // 1.2 sand veil loss
        else if (defAbility == ABILITY_SNOW_CLOAK && WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_HAIL_ANY)
            calc = (calc * 80) / 100; // 1.2 snow cloak loss
        else if (defAbility == ABILITY_TANGLED_FEET && gBattleMons[gBattlerTarget].status2 & STATUS2_CONFUSION)
            calc = (calc * 50) / 100; // 1.5 tangled feet loss

        if (atkAbility == ABILITY_HUSTLE && IS_MOVE_PHYSICAL(move))
            calc = (calc * 80) / 100; // 1.2 hustle loss

        defHoldEffect = GetBattlerHoldEffect(gBattlerTarget, TRUE);
        defParam = GetBattlerHoldEffectParam(gBattlerTarget);
        gPotentialItemEffectBattler = gBattlerTarget;

        atkHoldEffect = GetBattlerHoldEffect(gBattlerAttacker, TRUE);
        atkParam = GetBattlerHoldEffectParam(gBattlerAttacker);

        if (defHoldEffect == HOLD_EFFECT_EVASION_UP)
            calc = (calc * (100 - defParam)) / 100;

        if (atkHoldEffect == HOLD_EFFECT_WIDE_LENS)
            calc = (calc * (100 + atkParam)) / 100;
        else if (atkHoldEffect == HOLD_EFFECT_ZOOM_LENS && GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget));
            calc = (calc * (100 + atkParam)) / 100;

        // final calculation
        if ((Random() % 100 + 1) > calc)
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE &&
                (gBattleMoves[move].target == MOVE_TARGET_BOTH || gBattleMoves[move].target == MOVE_TARGET_FOES_AND_ALLY))
                gBattleCommunication[6] = 2;
            else
                gBattleCommunication[6] = 0;

            if (gBattleMoves[move].power)
                CalcTypeEffectivenessMultiplier(move, type, gBattlerAttacker, gBattlerTarget, TRUE);
        }
        JumpIfMoveFailed(7, move);
    }
}

static void atk02_attackstring(void)
{
    if (gBattleControllerExecFlags)
         return;
    if (!(gHitMarker & (HITMARKER_NO_ATTACKSTRING | HITMARKER_ATTACKSTRING_PRINTED)))
    {
        PrepareStringBattle(STRINGID_USEDMOVE, gBattlerAttacker);
        gHitMarker |= HITMARKER_ATTACKSTRING_PRINTED;
    }
    gBattlescriptCurrInstr++;
    gBattleCommunication[MSG_DISPLAY] = 0;
}

static void atk03_ppreduce(void)
{
    s32 i, ppToDeduct = 1;

    if (gBattleControllerExecFlags)
        return;

    if (!gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure)
    {
        switch (gBattleMoves[gCurrentMove].target)
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
        gProtectStructs[gBattlerAttacker].notFirstStrike = 1;

        if (gBattleMons[gBattlerAttacker].pp[gCurrMovePos] > ppToDeduct)
            gBattleMons[gBattlerAttacker].pp[gCurrMovePos] -= ppToDeduct;
        else
            gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = 0;

        if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_TRANSFORMED)
            && !((gDisableStructs[gBattlerAttacker].mimickedMoves) & gBitTable[gCurrMovePos]))
        {
            gActiveBattler = gBattlerAttacker;
            BtlController_EmitSetMonData(0, REQUEST_PPMOVE1_BATTLE + gCurrMovePos, 0, 1, &gBattleMons[gBattlerAttacker].pp[gCurrMovePos]);
            MarkBattlerForControllerExec(gBattlerAttacker);
        }
    }

    gHitMarker &= ~(HITMARKER_NO_PPDEDUCT);
    gBattlescriptCurrInstr++;
}

// The chance is 1/N for each stage.
#if B_CRIT_CHANCE == GEN_7
    static const u8 sCriticalHitChance[] = {24, 8, 2, 1, 1};
#elif B_CRIT_CHANCE == GEN_6
    static const u8 sCriticalHitChance[] = {16, 8, 2, 1, 1};
#else
    static const u8 sCriticalHitChance[] = {16, 8, 4, 3, 2}; // Gens 2,3,4,5
#endif // B_CRIT_CHANCE

s32 CalcCritChanceStage(u8 battlerAtk, u8 battlerDef, u32 move, bool32 recordAbility)
{
    s32 critChance = 0;
    u32 abilityAtk = GetBattlerAbility(gBattlerAttacker);
    u32 abilityDef = GetBattlerAbility(gBattlerTarget);

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
             || (abilityAtk == ABILITY_MERCILESS && gBattleMons[battlerDef].status1 & STATUS1_PSN_ANY))
    {
        critChance = -2;
    }
    else
    {
        u32 holdEffectAtk = GetBattlerHoldEffect(battlerAtk, TRUE);

        critChance  = 2 * ((gBattleMons[gBattlerAttacker].status2 & STATUS2_FOCUS_ENERGY) != 0)
                    + ((gBattleMoves[gCurrentMove].flags & FLAG_HIGH_CRIT) != 0)
                    + (holdEffectAtk == HOLD_EFFECT_SCOPE_LENS)
                    + 2 * (holdEffectAtk == HOLD_EFFECT_LUCKY_PUNCH && gBattleMons[gBattlerAttacker].species == SPECIES_CHANSEY)
                    + 2 * (holdEffectAtk == HOLD_EFFECT_STICK && gBattleMons[gBattlerAttacker].species == SPECIES_FARFETCHD)
                    + (abilityAtk == ABILITY_SUPER_LUCK);

        if (critChance >= ARRAY_COUNT(sCriticalHitChance))
            critChance = ARRAY_COUNT(sCriticalHitChance) - 1;
    }

    return critChance;
}

static void atk04_critcalc(void)
{
    s32 critChance = CalcCritChanceStage(gBattlerAttacker, gBattlerTarget, gCurrentMove, TRUE);
    gPotentialItemEffectBattler = gBattlerAttacker;

    if (gBattleTypeFlags & (BATTLE_TYPE_WALLY_TUTORIAL | BATTLE_TYPE_FIRST_BATTLE))
        gIsCriticalHit = FALSE;
    else if (critChance == -1)
        gIsCriticalHit = FALSE;
    else if (critChance == -2)
        gIsCriticalHit = TRUE;
    else if (Random() % sCriticalHitChance[critChance] == 0)
        gIsCriticalHit = TRUE;
    else
        gIsCriticalHit = FALSE;

    gBattlescriptCurrInstr++;
}

static void atk05_damagecalc(void)
{
    u8 moveType;

    GET_MOVE_TYPE(gCurrentMove, moveType);
    gBattleMoveDamage = CalculateMoveDamage(gCurrentMove, gBattlerAttacker, gBattlerTarget, moveType, 0, gIsCriticalHit, TRUE, TRUE);
    gBattlescriptCurrInstr++;
}

static void atk06_typecalc(void)
{
    u8 moveType;

    GET_MOVE_TYPE(gCurrentMove, moveType);
    CalcTypeEffectivenessMultiplier(gCurrentMove, moveType, gBattlerAttacker, gBattlerTarget, TRUE);

    gBattlescriptCurrInstr++;
}

static void atk07_adjustdamage(void)
{
    u8 holdEffect, param;

    if (DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
        goto END;
    if (gBattleMons[gBattlerTarget].hp > gBattleMoveDamage)
        goto END;

    holdEffect = GetBattlerHoldEffect(gBattlerTarget, TRUE);
    param = GetBattlerHoldEffectParam(gBattlerTarget);

    gPotentialItemEffectBattler = gBattlerTarget;

    if (holdEffect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < param)
    {
        RecordItemEffectBattle(gBattlerTarget, holdEffect);
        gSpecialStatuses[gBattlerTarget].focusBanded = 1;
    }
    else if (holdEffect == HOLD_EFFECT_FOCUS_SASH && BATTLER_MAX_HP(gBattlerTarget))
    {
        RecordItemEffectBattle(gBattlerTarget, holdEffect);
        gSpecialStatuses[gBattlerTarget].focusSashed = 1;
    }
    else if (GetBattlerAbility(gBattlerTarget) == ABILITY_STURDY && BATTLER_MAX_HP(gBattlerTarget))
    {
        RecordAbilityBattle(gBattlerTarget, ABILITY_STURDY);
        gSpecialStatuses[gBattlerTarget].sturdied = 1;
    }

    if (gBattleMoves[gCurrentMove].effect != EFFECT_FALSE_SWIPE
        && !gProtectStructs[gBattlerTarget].endured
        && !gSpecialStatuses[gBattlerTarget].focusBanded
        && !gSpecialStatuses[gBattlerTarget].focusSashed
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

END:
    gBattlescriptCurrInstr++;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) && gBattleMoveDamage >= 1)
        gSpecialStatuses[gBattlerAttacker].damagedMons |= gBitTable[gBattlerTarget];

    // Check gems and damage reducing berries.
    if (gSpecialStatuses[gBattlerTarget].berryReduced
        && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        && gBattleMons[gBattlerTarget].item)
    {
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_BerryReduceDmg;
    }
    if (gSpecialStatuses[gBattlerAttacker].gemBoost
        && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        && gBattleMons[gBattlerAttacker].item)
    {
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_GemActivates;
    }
}

static void atk08_multihitresultmessage(void)
{
    if (gBattleControllerExecFlags)
        return;

    if (!(gMoveResultFlags & MOVE_RESULT_FAILED) && !(gMoveResultFlags & MOVE_RESULT_FOE_ENDURED))
    {
        if (gMoveResultFlags & MOVE_RESULT_STURDIED)
        {
            gMoveResultFlags &= ~(MOVE_RESULT_STURDIED | MOVE_RESULT_FOE_HUNG_ON);
            gSpecialStatuses[gBattlerTarget].sturdied = 0; // Delete this line to make Sturdy last for the duration of the whole move turn.
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_SturdiedMsg;
            return;
        }
        else if (gMoveResultFlags & MOVE_RESULT_FOE_HUNG_ON)
        {
            gLastUsedItem = gBattleMons[gBattlerTarget].item;
            gPotentialItemEffectBattler = gBattlerTarget;
            gMoveResultFlags &= ~(MOVE_RESULT_STURDIED | MOVE_RESULT_FOE_HUNG_ON);
            gSpecialStatuses[gBattlerTarget].focusBanded = 0; // Delete this line to make Focus Band last for the duration of the whole move turn.
            gSpecialStatuses[gBattlerTarget].focusSashed = 0; // Delete this line to make Focus Sash last for the duration of the whole move turn.
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_HangedOnMsg;
            return;
        }
    }

    gBattlescriptCurrInstr++;
}

static void atk09_attackanimation(void)
{
    if (gBattleControllerExecFlags)
        return;

    if ((gHitMarker & HITMARKER_NO_ANIMATIONS) && (gCurrentMove != MOVE_TRANSFORM && gCurrentMove != MOVE_SUBSTITUTE))
    {
        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_Pausex20;
        gBattleScripting.animTurn++;
        gBattleScripting.animTargetsHit++;
    }
    else
    {
        if ((gBattleMoves[gCurrentMove].target & MOVE_TARGET_BOTH
             || gBattleMoves[gCurrentMove].target & MOVE_TARGET_FOES_AND_ALLY
             || gBattleMoves[gCurrentMove].target & MOVE_TARGET_DEPENDS)
            && gBattleScripting.animTargetsHit)
        {
            gBattlescriptCurrInstr++;
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

            BtlController_EmitMoveAnimation(0, gCurrentMove, gBattleScripting.animTurn, gBattleMovePower, gBattleMoveDamage, gBattleMons[gBattlerAttacker].friendship, &gDisableStructs[gBattlerAttacker], multihit);
            gBattleScripting.animTurn += 1;
            gBattleScripting.animTargetsHit += 1;
            MarkBattlerForControllerExec(gBattlerAttacker);
            gBattlescriptCurrInstr++;
        }
        else
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_Pausex20;
        }
    }
}

static void atk0A_waitanimation(void)
{
    if (gBattleControllerExecFlags == 0)
        gBattlescriptCurrInstr++;
}

static void atk0B_healthbarupdate(void)
{
    if (gBattleControllerExecFlags)
        return;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

        if (DoesSubstituteBlockMove(gBattlerAttacker, gActiveBattler, gCurrentMove) && gDisableStructs[gActiveBattler].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            PrepareStringBattle(STRINGID_SUBSTITUTEDAMAGED, gActiveBattler);
        }
        else
        {
            s16 healthValue;

            s32 currDmg = gBattleMoveDamage;
            s32 maxPossibleDmgValue = 10000; // not present in R/S, ensures that huge damage values don't change sign

            if (currDmg <= maxPossibleDmgValue)
                healthValue = currDmg;
            else
                healthValue = maxPossibleDmgValue;

            BtlController_EmitHealthBarUpdate(0, healthValue);
            MarkBattlerForControllerExec(gActiveBattler);

            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER && gBattleMoveDamage > 0)
                gBattleResults.playerMonWasDamaged = TRUE;
        }
    }

    gBattlescriptCurrInstr += 2;
}

static void atk0C_datahpupdate(void)
{
    u32 moveType;

    if (gBattleControllerExecFlags)
        return;

    if (gBattleStruct->dynamicMoveType == 0)
        moveType = gBattleMoves[gCurrentMove].type;
    else if (!(gBattleStruct->dynamicMoveType & 0x40))
        moveType = gBattleStruct->dynamicMoveType & 0x3F;
    else
        moveType = gBattleMoves[gCurrentMove].type;

    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
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
                gBattlescriptCurrInstr += 2;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SubstituteFade;
                return;
            }
        }
        else
        {
            gHitMarker &= ~(HITMARKER_IGNORE_SUBSTITUTE);
            if (gBattleMoveDamage < 0) // hp goes up
            {
                gBattleMons[gActiveBattler].hp -= gBattleMoveDamage;
                if (gBattleMons[gActiveBattler].hp > gBattleMons[gActiveBattler].maxHP)
                    gBattleMons[gActiveBattler].hp = gBattleMons[gActiveBattler].maxHP;

            }
            else // hp goes down
            {
                if (gHitMarker & HITMARKER_x20)
                {
                    gHitMarker &= ~(HITMARKER_x20);
                }
                else
                {
                    gTakenDmg[gActiveBattler] += gBattleMoveDamage;
                    if (gBattlescriptCurrInstr[1] == BS_TARGET)
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

                if (!gSpecialStatuses[gActiveBattler].dmg && !(gHitMarker & HITMARKER_x100000))
                    gSpecialStatuses[gActiveBattler].dmg = gHpDealt;

                if (IS_MOVE_PHYSICAL(gCurrentMove) && !(gHitMarker & HITMARKER_x100000) && gCurrentMove != MOVE_PAIN_SPLIT)
                {
                    gProtectStructs[gActiveBattler].physicalDmg = gHpDealt;
                    gSpecialStatuses[gActiveBattler].physicalDmg = gHpDealt;
                    if (gBattlescriptCurrInstr[1] == BS_TARGET)
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
                else if (!IS_MOVE_PHYSICAL(gCurrentMove) && !(gHitMarker & HITMARKER_x100000))
                {
                    gProtectStructs[gActiveBattler].specialDmg = gHpDealt;
                    gSpecialStatuses[gActiveBattler].specialDmg = gHpDealt;
                    if (gBattlescriptCurrInstr[1] == BS_TARGET)
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
            gHitMarker &= ~(HITMARKER_x100000);
            BtlController_EmitSetMonData(0, REQUEST_HP_BATTLE, 0, 2, &gBattleMons[gActiveBattler].hp);
            MarkBattlerForControllerExec(gActiveBattler);
        }
    }
    else
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
        if (gSpecialStatuses[gActiveBattler].dmg == 0)
            gSpecialStatuses[gActiveBattler].dmg = 0xFFFF;
    }
    gBattlescriptCurrInstr += 2;
}

static void atk0D_critmessage(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        if (gIsCriticalHit == TRUE && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
        {
            PrepareStringBattle(STRINGID_CRITICALHIT, gBattlerAttacker);
            gBattleCommunication[MSG_DISPLAY] = 1;
        }
        gBattlescriptCurrInstr++;
    }
}

static void atk0E_effectivenesssound(void)
{
    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = gBattlerTarget;
    if (!(gMoveResultFlags & MOVE_RESULT_MISSED))
    {
        switch (gMoveResultFlags & (~(MOVE_RESULT_MISSED)))
        {
        case MOVE_RESULT_SUPER_EFFECTIVE:
            BtlController_EmitPlaySE(0, SE_KOUKA_H);
            MarkBattlerForControllerExec(gActiveBattler);
            break;
        case MOVE_RESULT_NOT_VERY_EFFECTIVE:
            BtlController_EmitPlaySE(0, SE_KOUKA_L);
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
                BtlController_EmitPlaySE(0, SE_KOUKA_H);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            else if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
            {
                BtlController_EmitPlaySE(0, SE_KOUKA_L);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            else if (!(gMoveResultFlags & (MOVE_RESULT_DOESNT_AFFECT_FOE | MOVE_RESULT_FAILED)))
            {
                BtlController_EmitPlaySE(0, SE_KOUKA_M);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            break;
        }
    }
    gBattlescriptCurrInstr++;
}

static void atk0F_resultmessage(void)
{
    u32 stringId = 0;

    if (gBattleControllerExecFlags)
        return;

    if (gMoveResultFlags & MOVE_RESULT_MISSED && (!(gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE) || gBattleCommunication[6] > 2))
    {
        stringId = gMissStringIds[gBattleCommunication[6]];
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
    else
    {
        gBattleCommunication[MSG_DISPLAY] = 1;
        switch (gMoveResultFlags & (~MOVE_RESULT_MISSED))
        {
        case MOVE_RESULT_SUPER_EFFECTIVE:
            stringId = STRINGID_SUPEREFFECTIVE;
            break;
        case MOVE_RESULT_NOT_VERY_EFFECTIVE:
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
                gMoveResultFlags &= ~(MOVE_RESULT_ONE_HIT_KO);
                gMoveResultFlags &= ~(MOVE_RESULT_SUPER_EFFECTIVE);
                gMoveResultFlags &= ~(MOVE_RESULT_NOT_VERY_EFFECTIVE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_OneHitKOMsg;
                return;
            }
            else if (gMoveResultFlags & MOVE_RESULT_STURDIED)
            {
                gMoveResultFlags &= ~(MOVE_RESULT_STURDIED | MOVE_RESULT_FOE_ENDURED | MOVE_RESULT_FOE_HUNG_ON);
                gSpecialStatuses[gBattlerTarget].sturdied = 0;
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
            else
            {
                gBattleCommunication[MSG_DISPLAY] = 0;
            }
        }
    }

    if (stringId)
        PrepareStringBattle(stringId, gBattlerAttacker);

    gBattlescriptCurrInstr++;

    // Print berry reducing message after result message.
    if (gSpecialStatuses[gBattlerTarget].berryReduced
        && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        gSpecialStatuses[gBattlerTarget].berryReduced = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_PrintBerryReduceString;
    }
}

static void atk10_printstring(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        u16 var = T2_READ_16(gBattlescriptCurrInstr + 1);

        gBattlescriptCurrInstr += 3;
        PrepareStringBattle(var, gBattlerAttacker);
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

static void atk11_printselectionstring(void)
{
    gActiveBattler = gBattlerAttacker;

    BtlController_EmitPrintSelectionString(0, T2_READ_16(gBattlescriptCurrInstr + 1));
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 3;
    gBattleCommunication[MSG_DISPLAY] = 1;
}

static void atk12_waitmessage(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        if (!gBattleCommunication[MSG_DISPLAY])
        {
            gBattlescriptCurrInstr += 3;
        }
        else
        {
            u16 toWait = T2_READ_16(gBattlescriptCurrInstr + 1);
            if (++gPauseCounterBattle >= toWait)
            {
                gPauseCounterBattle = 0;
                gBattlescriptCurrInstr += 3;
                gBattleCommunication[MSG_DISPLAY] = 0;
            }
        }
    }
}

static void atk13_printfromtable(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        const u16 *ptr = (const u16*) T1_READ_PTR(gBattlescriptCurrInstr + 1);
        ptr += gBattleCommunication[MULTISTRING_CHOOSER];

        gBattlescriptCurrInstr += 5;
        PrepareStringBattle(*ptr, gBattlerAttacker);
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

static void atk14_printselectionstringfromtable(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        const u16 *ptr = (const u16*) T1_READ_PTR(gBattlescriptCurrInstr + 1);
        ptr += gBattleCommunication[MULTISTRING_CHOOSER];

        gActiveBattler = gBattlerAttacker;
        BtlController_EmitPrintSelectionString(0, *ptr);
        MarkBattlerForControllerExec(gActiveBattler);

        gBattlescriptCurrInstr += 5;
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
    bool32 noSunCanFreeze = TRUE;

    if (gBattleScripting.moveEffect & MOVE_EFFECT_AFFECTS_USER)
    {
        gEffectBattler = gBattlerAttacker; // battlerId that effects get applied on
        gBattleScripting.moveEffect &= ~(MOVE_EFFECT_AFFECTS_USER);
        affectsUser = MOVE_EFFECT_AFFECTS_USER;
        gBattleScripting.battler = gBattlerTarget; // theoretically the attacker
    }
    else
    {
        gEffectBattler = gBattlerTarget;
        gBattleScripting.battler = gBattlerAttacker;
    }
     // Just in case this flag is still set
    gBattleScripting.moveEffect &= ~(MOVE_EFFECT_CERTAIN);

    if (GetBattlerAbility(gEffectBattler) == ABILITY_SHIELD_DUST && !(gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
        && !primary && gBattleScripting.moveEffect <= 9)
        INCREMENT_RESET_RETURN

    if (gSideStatuses[GET_BATTLER_SIDE(gEffectBattler)] & SIDE_STATUS_SAFEGUARD && !(gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
        && !primary && gBattleScripting.moveEffect <= 7)
        INCREMENT_RESET_RETURN

    if (gBattleMons[gEffectBattler].hp == 0
        && gBattleScripting.moveEffect != MOVE_EFFECT_PAYDAY
        && gBattleScripting.moveEffect != MOVE_EFFECT_STEAL_ITEM)
        INCREMENT_RESET_RETURN

    if (DoesSubstituteBlockMove(gBattlerAttacker, gEffectBattler, gCurrentMove) && affectsUser != MOVE_EFFECT_AFFECTS_USER)
        INCREMENT_RESET_RETURN

    if (gBattleScripting.moveEffect <= 6) // status change
    {
        switch (sStatusFlagsForMoveEffects[gBattleScripting.moveEffect])
        {
        case STATUS1_SLEEP:
            // check active uproar
            if (GetBattlerAbility(gEffectBattler) != ABILITY_SOUNDPROOF)
            {
                for (gActiveBattler = 0;
                    gActiveBattler < gBattlersCount && !(gBattleMons[gActiveBattler].status2 & STATUS2_UPROAR);
                    gActiveBattler++)
                {}
            }
            else
                gActiveBattler = gBattlersCount;

            if (gBattleMons[gEffectBattler].status1)
                break;
            if (gActiveBattler != gBattlersCount)
                break;
            if (GetBattlerAbility(gEffectBattler) == ABILITY_VITAL_SPIRIT
                || GetBattlerAbility(gEffectBattler) == ABILITY_INSOMNIA
                || IsAbilityOnSide(gEffectBattler, ABILITY_SWEET_VEIL)
                || IsFlowerVeilProtected(gEffectBattler))
                break;

            CancelMultiTurnMoves(gEffectBattler);
            statusChanged = TRUE;
            break;
        case STATUS1_POISON:
            if (GetBattlerAbility(gEffectBattler) == ABILITY_IMMUNITY
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                gLastUsedAbility = ABILITY_IMMUNITY;
                RecordAbilityBattle(gEffectBattler, ABILITY_IMMUNITY);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    gHitMarker &= ~(HITMARKER_IGNORE_SAFEGUARD);
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                }
                RESET_RETURN
            }
            if ((IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_POISON) || IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_STEEL))
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                RESET_RETURN
            }
            if (IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_POISON))
                break;
            if (IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_STEEL))
                break;
            if (gBattleMons[gEffectBattler].status1)
                break;
            if (GetBattlerAbility(gEffectBattler) == ABILITY_IMMUNITY || IsFlowerVeilProtected(gEffectBattler))
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_BURN:
            if (GetBattlerAbility(gEffectBattler) == ABILITY_WATER_VEIL
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                gLastUsedAbility = ABILITY_WATER_VEIL;
                RecordAbilityBattle(gEffectBattler, ABILITY_WATER_VEIL);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;
                if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    gHitMarker &= ~(HITMARKER_IGNORE_SAFEGUARD);
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                }
                RESET_RETURN
            }
            if (IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_FIRE)
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                RESET_RETURN
            }
            if (IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_FIRE))
                break;
            if (GetBattlerAbility(gEffectBattler) == ABILITY_WATER_VEIL || IsFlowerVeilProtected(gEffectBattler))
                break;
            if (gBattleMons[gEffectBattler].status1)
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_FREEZE:
            if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY)
                noSunCanFreeze = FALSE;
            if (IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_ICE))
                break;
            if (gBattleMons[gEffectBattler].status1)
                break;
            if (noSunCanFreeze == 0)
                break;
            if (GetBattlerAbility(gEffectBattler) == ABILITY_MAGMA_ARMOR || IsFlowerVeilProtected(gEffectBattler))
                break;

            CancelMultiTurnMoves(gEffectBattler);
            statusChanged = TRUE;
            break;
        case STATUS1_PARALYSIS:
            if (GetBattlerAbility(gEffectBattler) == ABILITY_LIMBER)
            {
                if (primary == TRUE || certain == MOVE_EFFECT_CERTAIN)
                {
                    gLastUsedAbility = ABILITY_LIMBER;
                    RecordAbilityBattle(gEffectBattler, ABILITY_LIMBER);

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_PRLZPrevention;

                    if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                        gHitMarker &= ~(HITMARKER_IGNORE_SAFEGUARD);
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                    }
                    RESET_RETURN
                }
                else
                    break;
            }
            if ((IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_ELECTRIC))
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PRLZPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                RESET_RETURN
            }
            if (IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_ELECTRIC))
                break;
            if (GetBattlerAbility(gEffectBattler) == ABILITY_LIMBER || IsFlowerVeilProtected(gEffectBattler))
                break;
            if (gBattleMons[gEffectBattler].status1)
                break;

            statusChanged = TRUE;
            break;
        case STATUS1_TOXIC_POISON:
            if (GetBattlerAbility(gEffectBattler) == ABILITY_IMMUNITY && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                gLastUsedAbility = ABILITY_IMMUNITY;
                RecordAbilityBattle(gEffectBattler, ABILITY_IMMUNITY);

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                    gHitMarker &= ~(HITMARKER_IGNORE_SAFEGUARD);
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                }
                RESET_RETURN
            }
            if ((IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_POISON) || IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_STEEL))
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                RESET_RETURN
            }
            if (gBattleMons[gEffectBattler].status1)
                break;
            if (!IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_POISON) && !IS_BATTLER_OF_TYPE(gEffectBattler, TYPE_STEEL))
            {
                if (GetBattlerAbility(gEffectBattler) == ABILITY_IMMUNITY || IsFlowerVeilProtected(gEffectBattler))
                    break;

                // It's redundant, because at this point we know the status1 value is 0.
                gBattleMons[gEffectBattler].status1 &= ~(STATUS1_TOXIC_POISON);
                gBattleMons[gEffectBattler].status1 &= ~(STATUS1_POISON);
                statusChanged = TRUE;
                break;
            }
            else
            {
                gMoveResultFlags |= MOVE_RESULT_DOESNT_AFFECT_FOE;
            }
            break;
        }
        if (statusChanged == TRUE)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);

            if (sStatusFlagsForMoveEffects[gBattleScripting.moveEffect] == STATUS1_SLEEP)
                gBattleMons[gEffectBattler].status1 |= ((Random() & 3) + 2);
            else
                gBattleMons[gEffectBattler].status1 |= sStatusFlagsForMoveEffects[gBattleScripting.moveEffect];

            gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];

            gActiveBattler = gEffectBattler;
            BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gEffectBattler].status1);
            MarkBattlerForControllerExec(gActiveBattler);

            if (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                gHitMarker &= ~(HITMARKER_IGNORE_SAFEGUARD);
            }
            else
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
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
                if (GetBattlerAbility(gEffectBattler) == ABILITY_OWN_TEMPO
                    || gBattleMons[gEffectBattler].status2 & STATUS2_CONFUSION)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gEffectBattler].status2 |= (((Random()) % 0x4)) + 2;

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];
                }
                break;
            case MOVE_EFFECT_FLINCH:
                if (GetBattlerAbility(gEffectBattler) == ABILITY_INNER_FOCUS)
                {
                    if (primary == TRUE || certain == MOVE_EFFECT_CERTAIN)
                    {
                        gLastUsedAbility = ABILITY_INNER_FOCUS;
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
                    gBattleMons[gEffectBattler].status2 |= ((Random() & 3) + 2) << 4;

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];
                }
                else
                {
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_PAYDAY:
                if (GET_BATTLER_SIDE(gBattlerAttacker) == B_SIDE_PLAYER)
                {
                    u16 PayDay = gPaydayMoney;
                    gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 5);
                    if (PayDay > gPaydayMoney)
                        gPaydayMoney = 0xFFFF;
                }
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];
                break;
            case MOVE_EFFECT_HAPPY_HOUR:
                if (GET_BATTLER_SIDE(gBattlerAttacker) == B_SIDE_PLAYER)
                {
                    gBattleStruct->moneyMultiplier *= 2;
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
                    gBattleScripting.moveEffect = Random() % 3 + 3;
                    SetMoveEffect(FALSE, 0);
                }
                break;
            case MOVE_EFFECT_CHARGING:
                gBattleMons[gEffectBattler].status2 |= STATUS2_MULTIPLETURNS;
                gLockedMoves[gEffectBattler] = gCurrentMove;
                gProtectStructs[gEffectBattler].chargingTurn = 1;
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
                        gDisableStructs[gEffectBattler].wrapTurns = 7;
                    else
                        gDisableStructs[gEffectBattler].wrapTurns = ((Random() % 2) + 4);

                    gBattleStruct->wrappedMove[gEffectBattler] = gCurrentMove;
                    gBattleStruct->wrappedBy[gEffectBattler] = gBattlerAttacker;

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];

                    for (gBattleCommunication[MULTISTRING_CHOOSER] = 0; ; gBattleCommunication[MULTISTRING_CHOOSER]++)
                    {
                        if (gBattleCommunication[MULTISTRING_CHOOSER] > 5)
                            break;
                        if (gTrappingMoves[gBattleCommunication[MULTISTRING_CHOOSER]] == gCurrentMove)
                            break;
                    }
                }
                break;
            case MOVE_EFFECT_RECOIL_25: // 25% recoil
                gBattleMoveDamage = (gHpDealt) / 4;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];
                break;
            case MOVE_EFFECT_ATK_PLUS_1:
            case MOVE_EFFECT_DEF_PLUS_1:
            case MOVE_EFFECT_SPD_PLUS_1:
            case MOVE_EFFECT_SP_ATK_PLUS_1:
            case MOVE_EFFECT_SP_DEF_PLUS_1:
            case MOVE_EFFECT_ACC_PLUS_1:
            case MOVE_EFFECT_EVS_PLUS_1:
                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(1),
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_PLUS_1 + 1,
                                    affectsUser, 0))
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
                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(1) | STAT_BUFF_NEGATIVE,
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_MINUS_1 + 1,
                                     affectsUser, 0))
                {
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
                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(2),
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_PLUS_2 + 1,
                                    affectsUser, 0))
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
                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(2) | STAT_BUFF_NEGATIVE,
                                    gBattleScripting.moveEffect - MOVE_EFFECT_ATK_MINUS_2 + 1,
                                    affectsUser, 0))
                {
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
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
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
                              | BATTLE_TYPE_x2000000
                              | BATTLE_TYPE_SECRET_BASE)))
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else if (!(gBattleTypeFlags &
                          (BATTLE_TYPE_EREADER_TRAINER
                           | BATTLE_TYPE_FRONTIER
                           | BATTLE_TYPE_LINK
                           | BATTLE_TYPE_x2000000
                           | BATTLE_TYPE_SECRET_BASE))
                        && (gWishFutureKnock.knockedOffMons[side] & gBitTable[gBattlerPartyIndexes[gBattlerAttacker]]))
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else if (gBattleMons[gBattlerTarget].item
                        && gBattleMons[gBattlerTarget].ability == ABILITY_STICKY_HOLD)
                    {
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_NoItemSteal;

                        gLastUsedAbility = gBattleMons[gBattlerTarget].ability;
                        RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
                    }
                    else if (gBattleMons[gBattlerAttacker].item != 0
                        || gBattleMons[gBattlerTarget].item == ITEM_ENIGMA_BERRY
                        || IS_ITEM_MAIL(gBattleMons[gBattlerTarget].item)
                        || gBattleMons[gBattlerTarget].item == 0)
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else
                    {
                        gLastUsedItem = gBattleStruct->changedItems[gBattlerAttacker] = gBattleMons[gBattlerTarget].item;
                        gBattleMons[gBattlerTarget].item = 0;

                        gActiveBattler = gBattlerAttacker;
                        BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gLastUsedItem);
                        MarkBattlerForControllerExec(gBattlerAttacker);

                        gActiveBattler = gBattlerTarget;
                        BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gBattlerTarget].item);
                        MarkBattlerForControllerExec(gBattlerTarget);

                        BattleScriptPush(gBattlescriptCurrInstr + 1);
                        gBattlescriptCurrInstr = BattleScript_ItemSteal;

                        gBattleStruct->choicedMove[gBattlerTarget] = 0;
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
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_AllStatsUp;
                break;
            case MOVE_EFFECT_RAPIDSPIN:
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_RapidSpinAway;
                break;
            case MOVE_EFFECT_REMOVE_STATUS: // Smelling salts
                if (!(gBattleMons[gBattlerTarget].status1 & gBattleMoves[gCurrentMove].argument))
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gBattlerTarget].status1 &= ~(gBattleMoves[gCurrentMove].argument);

                    gActiveBattler = gBattlerTarget;
                    BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                    MarkBattlerForControllerExec(gActiveBattler);

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_TargetPRLZHeal;
                }
                break;
            case MOVE_EFFECT_ATK_DEF_DOWN: // SuperPower
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_AtkDefDown;
                break;
            case MOVE_EFFECT_DEF_SPDEF_DOWN: // Close Combat
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_DefSpDefDown;
                break;
            case MOVE_EFFECT_RECOIL_33: // Double Edge
                gBattleMoveDamage = gHpDealt / 3;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleScripting.moveEffect];
                break;
            case MOVE_EFFECT_RECOIL_50: // Head Smash
                gBattleMoveDamage = gHpDealt / 2;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_MoveEffectRecoil;
                break;
            case MOVE_EFFECT_RECOIL_33_STATUS: // Flare Blitz - can burn, Volt Tackle - can paralyze
                gBattleScripting.savedDmg = gHpDealt / 3;
                if (gBattleScripting.savedDmg == 0)
                    gBattleScripting.savedDmg = 1;

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_MoveEffectRecoilWithStatus;
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
                    gBattleMons[gEffectBattler].status2 |= (((Random() & 1) + 2) << 0xA);
                }
                break;
            case MOVE_EFFECT_KNOCK_OFF:
                if (GetBattlerAbility(gEffectBattler) == ABILITY_STICKY_HOLD)
                {
                    if (gBattleMons[gEffectBattler].item == 0)
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else
                    {
                        gLastUsedAbility = ABILITY_STICKY_HOLD;
                        gBattlescriptCurrInstr = BattleScript_StickyHoldActivates;
                        RecordAbilityBattle(gEffectBattler, ABILITY_STICKY_HOLD);
                    }
                    break;
                }
                if (gBattleMons[gEffectBattler].item)
                {
                    side = GetBattlerSide(gEffectBattler);

                    gLastUsedItem = gBattleMons[gEffectBattler].item;
                    gBattleMons[gEffectBattler].item = 0;
                    gWishFutureKnock.knockedOffMons[side] |= gBitTable[gBattlerPartyIndexes[gEffectBattler]];

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_KnockedOff;

                    gBattleStruct->choicedMove[gEffectBattler] = 0;
                }
                else
                {
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_SP_ATK_TWO_DOWN: // Overheat
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_SAtkDown2;
                break;
            case MOVE_EFFECT_CLEAR_SMOG:
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[gEffectBattler].statStages[i] != 6)
                        break;
                }
                if ((gSpecialStatuses[gEffectBattler].physicalDmg || gSpecialStatuses[gEffectBattler].specialDmg) && i != NUM_BATTLE_STATS)
                {
                    for (i = 0; i < NUM_BATTLE_STATS; i++)
                        gBattleMons[gEffectBattler].statStages[i] = 6;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectClearSmog;
                }
                break;
            case MOVE_EFFECT_SMACK_DOWN:
                if (!IsBattlerGrounded(gBattlerTarget))
                {
                    gStatuses3[gBattlerTarget] |= STATUS3_SMACKED_DOWN;
                    gStatuses3[gBattlerTarget] &= ~(STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS | STATUS3_ON_AIR);
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectSmackDown;
                }
                break;
            case MOVE_EFFECT_FLAME_BURST:
                if (IsBattlerAlive(BATTLE_PARTNER(gBattlerTarget)) && GetBattlerAbility(BATTLE_PARTNER(gBattlerTarget)) != ABILITY_MAGIC_GUARD)
                {
                    gBattleScripting.battler = BATTLE_PARTNER(gBattlerTarget);
                    gBattleMoveDamage = gBattleMons[BATTLE_PARTNER(gBattlerTarget)].hp / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectFlameBurst;
                }
                break;
            case MOVE_EFFECT_FEINT:
                if (gProtectStructs[gBattlerTarget].protected
                    || gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_WIDE_GUARD
                    || gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_QUICK_GUARD
                    || gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_CRAFTY_SHIELD
                    || gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_MAT_BLOCK
                    || gProtectStructs[gBattlerTarget].spikyShielded
                    || gProtectStructs[gBattlerTarget].kingsShielded
                    || gProtectStructs[gBattlerTarget].banefulBunkered)
                {
                    gProtectStructs[gBattlerTarget].protected = 0;
                    gSideStatuses[GetBattlerSide(gBattlerTarget)] &= ~(SIDE_STATUS_WIDE_GUARD);
                    gSideStatuses[GetBattlerSide(gBattlerTarget)] &= ~(SIDE_STATUS_QUICK_GUARD);
                    gSideStatuses[GetBattlerSide(gBattlerTarget)] &= ~(SIDE_STATUS_CRAFTY_SHIELD);
                    gSideStatuses[GetBattlerSide(gBattlerTarget)] &= ~(SIDE_STATUS_MAT_BLOCK);
                    gProtectStructs[gBattlerTarget].spikyShielded = 0;
                    gProtectStructs[gBattlerTarget].kingsShielded = 0;
                    gProtectStructs[gBattlerTarget].banefulBunkered = 0;
                    if (gCurrentMove == MOVE_FEINT)
                    {
                        BattleScriptPush(gBattlescriptCurrInstr + 1);
                        gBattlescriptCurrInstr = BattleScript_MoveEffectFeint;
                    }
                }
                break;
            case MOVE_EFFECT_SPECTRAL_THIEF:
                gBattleStruct->stolenStats[0] = 0; // Stats to steal.
                gBattleScripting.animArg1 = 0;
                for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[gBattlerTarget].statStages[i] > 6 && gBattleMons[gBattlerAttacker].statStages[i] != 12)
                    {
                        gBattleStruct->stolenStats[0] |= gBitTable[i];
                        // Store by how many stages to raise the stat.
                        gBattleStruct->stolenStats[i] = gBattleMons[gBattlerTarget].statStages[i] - 6;
                        while (gBattleMons[gBattlerAttacker].statStages[i] + gBattleStruct->stolenStats[i] > 12)
                            gBattleStruct->stolenStats[i]--;
                        gBattleMons[gBattlerTarget].statStages[i] = 6;

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
                break;
            case MOVE_EFFECT_V_CREATE:
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_VCreateStatLoss;
                break;
            case MOVE_EFFECT_CORE_ENFORCER:
                if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
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
                if (GetBattlerHoldEffect(gEffectBattler, FALSE) == HOLD_EFFECT_GEMS
                    || (gBattleMons[gEffectBattler].item >= FIRST_BERRY_INDEX && gBattleMons[gEffectBattler].item <= LAST_BERRY_INDEX))
                {
                    gLastUsedItem = gBattleMons[gEffectBattler].item;
                    gBattleMons[gEffectBattler].item = 0;
                    gActiveBattler = gEffectBattler;
                    BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gEffectBattler].item);
                    MarkBattlerForControllerExec(gActiveBattler);
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_MoveEffectIncinerate;
                }
                break;
            }
        }
    }

    gBattleScripting.moveEffect = 0;
}

static void atk15_seteffectwithchance(void)
{
    u32 percentChance;

    if (GetBattlerAbility(gBattlerAttacker) == ABILITY_SERENE_GRACE)
        percentChance = gBattleMoves[gCurrentMove].secondaryEffectChance * 2;
    else
        percentChance = gBattleMoves[gCurrentMove].secondaryEffectChance;

    if (gBattleScripting.moveEffect & MOVE_EFFECT_CERTAIN
        && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        gBattleScripting.moveEffect &= ~(MOVE_EFFECT_CERTAIN);
        SetMoveEffect(0, MOVE_EFFECT_CERTAIN);
    }
    else if (Random() % 100 < percentChance
             && gBattleScripting.moveEffect
             && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
    {
        if (percentChance >= 100)
            SetMoveEffect(0, MOVE_EFFECT_CERTAIN);
        else
            SetMoveEffect(0, 0);
    }
    else
    {
        gBattlescriptCurrInstr++;
    }

    gBattleScripting.moveEffect = 0;
    gBattleScripting.multihitMoveEffect = 0;
}

static void atk16_seteffectprimary(void)
{
    SetMoveEffect(TRUE, 0);
}

static void atk17_seteffectsecondary(void)
{
    SetMoveEffect(FALSE, 0);
}

static void atk18_clearstatusfromeffect(void)
{
    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    if (gBattleScripting.moveEffect <= MOVE_EFFECT_TOXIC)
        gBattleMons[gActiveBattler].status1 &= (~sStatusFlagsForMoveEffects[gBattleScripting.moveEffect]);
    else
        gBattleMons[gActiveBattler].status2 &= (~sStatusFlagsForMoveEffects[gBattleScripting.moveEffect]);

    gBattleScripting.moveEffect = 0;
    gBattlescriptCurrInstr += 2;
    gBattleScripting.multihitMoveEffect = 0;
}

static void atk19_tryfaintmon(void)
{
    const u8 *BS_ptr;

    if (gBattlescriptCurrInstr[2] != 0)
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
        if (gHitMarker & HITMARKER_FAINTED(gActiveBattler))
        {
            BS_ptr = T1_READ_PTR(gBattlescriptCurrInstr + 3);

            BattleScriptPop();
            gBattlescriptCurrInstr = BS_ptr;
            gSideStatuses[GetBattlerSide(gActiveBattler)] &= ~(SIDE_STATUS_SPIKES_DAMAGED | SIDE_STATUS_TOXIC_SPIKES_DAMAGED | SIDE_STATUS_STEALTH_ROCK_DAMAGED | SIDE_STATUS_STICKY_WEB_DAMAGED);
        }
        else
        {
            gBattlescriptCurrInstr += 7;
        }
    }
    else
    {
        u8 battlerId;

        if (gBattlescriptCurrInstr[1] == BS_ATTACKER)
        {
            gActiveBattler = gBattlerAttacker;
            battlerId = gBattlerTarget;
            BS_ptr = BattleScript_FaintAttacker;
        }
        else
        {
            gActiveBattler = gBattlerTarget;
            battlerId = gBattlerAttacker;
            BS_ptr = BattleScript_FaintTarget;
        }
        if (!(gAbsentBattlerFlags & gBitTable[gActiveBattler])
         && gBattleMons[gActiveBattler].hp == 0)
        {
            gHitMarker |= HITMARKER_FAINTED(gActiveBattler);
            BattleScriptPush(gBattlescriptCurrInstr + 7);
            gBattlescriptCurrInstr = BS_ptr;
            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            {
                gHitMarker |= HITMARKER_x400000;
                if (gBattleResults.playerFaintCounter < 0xFF)
                    gBattleResults.playerFaintCounter++;
                AdjustFriendshipOnBattleFaint(gActiveBattler);
            }
            else
            {
                if (gBattleResults.opponentFaintCounter < 0xFF)
                    gBattleResults.opponentFaintCounter++;
                gBattleResults.lastOpponentSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES, NULL);
            }
            if ((gHitMarker & HITMARKER_DESTINYBOND) && gBattleMons[gBattlerAttacker].hp != 0)
            {
                gHitMarker &= ~(HITMARKER_DESTINYBOND);
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
                BtlController_EmitSetMonData(0, moveIndex + REQUEST_PPMOVE1_BATTLE, 0, 1, &gBattleMons[gActiveBattler].pp[moveIndex]);
                MarkBattlerForControllerExec(gActiveBattler);

                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].moves[moveIndex])
            }
        }
        else
        {
            gBattlescriptCurrInstr += 7;
        }
    }
}

static void atk1A_dofaintanimation(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
        BtlController_EmitFaintAnimation(0);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 2;
    }
}

static void atk1B_cleareffectsonfaint(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

        if (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || gBattleMons[gActiveBattler].hp == 0)
        {
            gBattleMons[gActiveBattler].status1 = 0;
            BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 0x4, &gBattleMons[gActiveBattler].status1);
            MarkBattlerForControllerExec(gActiveBattler);
        }

        FaintClearSetData(); // Effects like attractions, trapping, etc.
        gBattlescriptCurrInstr += 2;
    }
}

static void atk1C_jumpifstatus(void)
{
    u8 battlerId = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    u32 flags = T2_READ_32(gBattlescriptCurrInstr + 2);
    const u8* jumpPtr = T2_READ_PTR(gBattlescriptCurrInstr + 6);

    if (gBattleMons[battlerId].status1 & flags && gBattleMons[battlerId].hp)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 10;
}

static void atk1D_jumpifstatus2(void)
{
    u8 battlerId = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    u32 flags = T2_READ_32(gBattlescriptCurrInstr + 2);
    const u8* jumpPtr = T2_READ_PTR(gBattlescriptCurrInstr + 6);

    if (gBattleMons[battlerId].status2 & flags && gBattleMons[battlerId].hp)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 10;
}

static void atk1E_jumpifability(void)
{
    u32 battlerId;
    bool32 hasAbility = FALSE;
    u32 ability = gBattlescriptCurrInstr[2];

    switch (gBattlescriptCurrInstr[1])
    {
    default:
        battlerId = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
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
        gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 3);
        RecordAbilityBattle(battlerId, gLastUsedAbility);
        gBattlerAbility = battlerId;
    }
    else
    {
        gBattlescriptCurrInstr += 7;
    }
}

static void atk1F_jumpifsideaffecting(void)
{
    u8 side;
    u32 flags;
    const u8 *jumpPtr;

    if (gBattlescriptCurrInstr[1] == BS_ATTACKER)
        side = GET_BATTLER_SIDE(gBattlerAttacker);
    else
        side = GET_BATTLER_SIDE(gBattlerTarget);

    flags = T2_READ_32(gBattlescriptCurrInstr + 2);
    jumpPtr = T2_READ_PTR(gBattlescriptCurrInstr + 6);

    if (gSideStatuses[side] & flags)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 10;
}

static void atk20_jumpifstat(void)
{
    bool32 ret = 0;
    u8 battlerId = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    u8 statValue = gBattleMons[battlerId].statStages[gBattlescriptCurrInstr[3]];
    u8 cmpTo = gBattlescriptCurrInstr[4];
    u8 cmpKind = gBattlescriptCurrInstr[2];

    // Because this command is used as a way of checking if a stat can be lowered/raised,
    // we need to do some modification at run-time.
    if (GetBattlerAbility(battlerId) == ABILITY_CONTRARY)
    {
        if (cmpKind == CMP_GREATER_THAN)
            cmpKind = CMP_LESS_THAN;
        else if (cmpKind == CMP_LESS_THAN)
            cmpKind = CMP_GREATER_THAN;

        if (cmpTo == 0)
            cmpTo = 0xC;
        else if (cmpTo == 0xC)
            cmpTo = 0;
    }

    switch (cmpKind)
    {
    case CMP_EQUAL:
        if (statValue == cmpTo)
            ret++;
        break;
    case CMP_NOT_EQUAL:
        if (statValue != cmpTo)
            ret++;
        break;
    case CMP_GREATER_THAN:
        if (statValue > cmpTo)
            ret++;
        break;
    case CMP_LESS_THAN:
        if (statValue < cmpTo)
            ret++;
        break;
    case CMP_COMMON_BITS:
        if (statValue & cmpTo)
            ret++;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(statValue & cmpTo))
            ret++;
        break;
    }

    if (ret)
        gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 5);
    else
        gBattlescriptCurrInstr += 9;
}

static void atk21_jumpifstatus3condition(void)
{
    u32 flags;
    const u8 *jumpPtr;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    flags = T2_READ_32(gBattlescriptCurrInstr + 2);
    jumpPtr = T2_READ_PTR(gBattlescriptCurrInstr + 7);

    if (gBattlescriptCurrInstr[6])
    {
        if ((gStatuses3[gActiveBattler] & flags) != 0)
            gBattlescriptCurrInstr += 11;
        else
            gBattlescriptCurrInstr = jumpPtr;
    }
    else
    {
        if ((gStatuses3[gActiveBattler] & flags) != 0)
            gBattlescriptCurrInstr = jumpPtr;
        else
            gBattlescriptCurrInstr += 11;
    }
}

static void atk22_jumpbasedontype(void)
{
    u8 battlerId = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    u8 type = gBattlescriptCurrInstr[2];
    const u8* jumpPtr = T2_READ_PTR(gBattlescriptCurrInstr + 4);

    // jumpiftype
    if (gBattlescriptCurrInstr[3])
    {
        if (IS_BATTLER_OF_TYPE(battlerId, type))
            gBattlescriptCurrInstr = jumpPtr;
        else
            gBattlescriptCurrInstr += 8;
    }
    // jumpifnottype
    else
    {
        if (!IS_BATTLER_OF_TYPE(battlerId, type))
            gBattlescriptCurrInstr = jumpPtr;
        else
            gBattlescriptCurrInstr += 8;
    }
}

static void atk23_getexp(void)
{
    u16 item;
    s32 i; // also used as stringId
    u8 holdEffect;
    s32 sentIn;
    s32 viaExpShare = 0;
    u16 *exp = &gBattleStruct->expValue;

    gBattlerFainted = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    sentIn = gSentPokesToOpponent[(gBattlerFainted & 2) >> 1];

    switch (gBattleScripting.atk23_state)
    {
    case 0: // check if should receive exp at all
        if (GetBattlerSide(gBattlerFainted) != B_SIDE_OPPONENT || (gBattleTypeFlags &
             (BATTLE_TYPE_LINK
              | BATTLE_TYPE_x2000000
              | BATTLE_TYPE_TRAINER_HILL
              | BATTLE_TYPE_FRONTIER
              | BATTLE_TYPE_SAFARI
              | BATTLE_TYPE_BATTLE_TOWER
              | BATTLE_TYPE_EREADER_TRAINER)))
        {
            gBattleScripting.atk23_state = 6; // goto last case
        }
        else
        {
            gBattleScripting.atk23_state++;
            gBattleStruct->givenExpMons |= gBitTable[gBattlerPartyIndexes[gBattlerFainted]];
        }
        break;
    case 1: // calculate experience points to redistribute
        {
            u16 calculatedExp;
            s32 viaSentIn;

            for (viaSentIn = 0, i = 0; i < PARTY_SIZE; i++)
            {
                if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE || GetMonData(&gPlayerParty[i], MON_DATA_HP) == 0)
                    continue;
                if (gBitTable[i] & sentIn)
                    viaSentIn++;

                item = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);

                if (item == ITEM_ENIGMA_BERRY)
                    holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
                else
                    holdEffect = ItemId_GetHoldEffect(item);

                if (holdEffect == HOLD_EFFECT_EXP_SHARE)
                    viaExpShare++;
            }

            calculatedExp = gBaseStats[gBattleMons[gBattlerFainted].species].expYield * gBattleMons[gBattlerFainted].level / 7;

            if (viaExpShare) // at least one mon is getting exp via exp share
            {
                *exp = calculatedExp / 2 / viaSentIn;
                if (*exp == 0)
                    *exp = 1;

                gExpShareExp = calculatedExp / 2 / viaExpShare;
                if (gExpShareExp == 0)
                    gExpShareExp = 1;
            }
            else
            {
                *exp = calculatedExp / viaSentIn;
                if (*exp == 0)
                    *exp = 1;
                gExpShareExp = 0;
            }

            gBattleScripting.atk23_state++;
            gBattleStruct->expGetterMonId = 0;
            gBattleStruct->sentInPokes = sentIn;
        }
        // fall through
    case 2: // set exp value to the poke in expgetter_id and print message
        if (gBattleControllerExecFlags == 0)
        {
            item = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_HELD_ITEM);

            if (item == ITEM_ENIGMA_BERRY)
                holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
            else
                holdEffect = ItemId_GetHoldEffect(item);

            if (holdEffect != HOLD_EFFECT_EXP_SHARE && !(gBattleStruct->sentInPokes & 1))
            {
                *(&gBattleStruct->sentInPokes) >>= 1;
                gBattleScripting.atk23_state = 5;
                gBattleMoveDamage = 0; // used for exp
            }
            else if (GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_LEVEL) == MAX_LEVEL)
            {
                *(&gBattleStruct->sentInPokes) >>= 1;
                gBattleScripting.atk23_state = 5;
                gBattleMoveDamage = 0; // used for exp
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
                    PlayBGM(MUS_KACHI2);
                    gBattleStruct->wildVictorySong++;
                }

                if (GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_HP))
                {
                    if (gBattleStruct->sentInPokes & 1)
                        gBattleMoveDamage = *exp;
                    else
                        gBattleMoveDamage = 0;

                    if (holdEffect == HOLD_EFFECT_EXP_SHARE)
                        gBattleMoveDamage += gExpShareExp;
                    if (holdEffect == HOLD_EFFECT_LUCKY_EGG)
                        gBattleMoveDamage = (gBattleMoveDamage * 150) / 100;
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        gBattleMoveDamage = (gBattleMoveDamage * 150) / 100;

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
                        if (!(gBattlerPartyIndexes[2] != gBattleStruct->expGetterMonId) && !(gAbsentBattlerFlags & gBitTable[2]))
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
                    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff3, 5, gBattleMoveDamage);

                    PrepareStringBattle(STRINGID_PKMNGAINEDEXP, gBattleStruct->expGetterBattlerId);
                    MonGainEVs(&gPlayerParty[gBattleStruct->expGetterMonId], gBattleMons[gBattlerFainted].species);
                }
                gBattleStruct->sentInPokes >>= 1;
                gBattleScripting.atk23_state++;
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
                BtlController_EmitExpUpdate(0, gBattleStruct->expGetterMonId, gBattleMoveDamage);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            gBattleScripting.atk23_state++;
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
                gBattleMoveDamage = (gBattleResources->bufferB[gActiveBattler][2] | (gBattleResources->bufferB[gActiveBattler][3] << 8));
                AdjustFriendship(&gPlayerParty[gBattleStruct->expGetterMonId], 0);

                // update battle mon structure after level up
                if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterMonId && gBattleMons[0].hp)
                    battlerId = 0;
                else if (gBattlerPartyIndexes[2] == gBattleStruct->expGetterMonId && gBattleMons[2].hp && (gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                    battlerId = 2;

                if (battlerId != 0xFF)
                {
                    gBattleMons[battlerId].level = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_LEVEL);
                    gBattleMons[battlerId].hp = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_HP);
                    gBattleMons[battlerId].maxHP = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_MAX_HP);
                    gBattleMons[battlerId].attack = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_ATK);
                    gBattleMons[battlerId].defense = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_DEF);
                    gBattleMons[battlerId].speed = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_SPEED);
                    gBattleMons[battlerId].spAttack = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_SPATK);
                    gBattleMons[battlerId].spDefense = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_SPDEF);

                    if (gStatuses3[battlerId] & STATUS3_POWER_TRICK)
                        SWAP(gBattleMons[battlerId].attack, gBattleMons[battlerId].defense, temp);
                }

                gBattleScripting.atk23_state = 5;
            }
            else
            {
                gBattleMoveDamage = 0;
                gBattleScripting.atk23_state = 5;
            }
        }
        break;
    case 5: // looper increment
        if (gBattleMoveDamage) // there is exp to give, goto case 3 that gives exp
        {
            gBattleScripting.atk23_state = 3;
        }
        else
        {
            gBattleStruct->expGetterMonId++;
            if (gBattleStruct->expGetterMonId <= 5)
                gBattleScripting.atk23_state = 2; // loop again
            else
                gBattleScripting.atk23_state = 6; // we're done
        }
        break;
    case 6: // increment instruction
        if (gBattleControllerExecFlags == 0)
        {
            // not sure why gf clears the item and ability here
            gBattleMons[gBattlerFainted].item = 0;
            gBattleMons[gBattlerFainted].ability = 0;
            gBattlescriptCurrInstr += 2;
        }
        break;
    }
}

static bool32 IsBattleLostForPlayer(void)
{
    u32 i;
    u32 HP_count = 0;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && (gPartnerTrainerId == TRAINER_STEVEN_PARTNER || gPartnerTrainerId >= TRAINER_CUSTOM_PARTNER))
    {
        for (i = 0; i < 3; i++)
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

static bool32 IsBattleWonForPlayer(void)
{
    u32 i;
    u32 HP_count = 0;

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

static void atk24(void)
{
    if (gBattleControllerExecFlags)
        return;

    if (IsBattleLostForPlayer())
        gBattleOutcome |= B_OUTCOME_LOST;
    if (IsBattleWonForPlayer())
        gBattleOutcome |= B_OUTCOME_WON;

    if (gBattleOutcome == 0 && (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000)))
    {
        s32 i;
        s32 foundPlayer;
        s32 foundOpponent;

        // Impossible to decompile loops.
        for (foundPlayer = 0, i = 0; i < gBattlersCount; i += 2)
        {
            if (HITMARKER_UNK(i) & gHitMarker && !gSpecialStatuses[i].flag40)
                foundPlayer++;
        }

        for (foundOpponent = 0, i = 1; i < gBattlersCount; i += 2)
        {
            if (HITMARKER_UNK(i) & gHitMarker && !gSpecialStatuses[i].flag40)
                foundOpponent++;
        }

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (foundOpponent + foundPlayer > 1)
                gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 1);
            else
                gBattlescriptCurrInstr += 5;
        }
        else
        {
            if (foundOpponent != 0 && foundPlayer != 0)
                gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 1);
            else
                gBattlescriptCurrInstr += 5;
        }
    }
    else
    {
        gBattlescriptCurrInstr += 5;
    }
}

static void MoveValuesCleanUp(void)
{
    gMoveResultFlags = 0;
    gIsCriticalHit = FALSE;
    gBattleScripting.moveEffect = 0;
    gBattleCommunication[6] = 0;
    gHitMarker &= ~(HITMARKER_DESTINYBOND);
    gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);
}

static void atk25_movevaluescleanup(void)
{
    MoveValuesCleanUp();
    gBattlescriptCurrInstr += 1;
}

static void atk26_setmultihit(void)
{
    gMultiHitCounter = gBattlescriptCurrInstr[1];
    gBattlescriptCurrInstr += 2;
}

static void atk27_decrementmultihit(void)
{
    if (--gMultiHitCounter == 0)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atk28_goto(void)
{
    gBattlescriptCurrInstr = T2_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atk29_jumpifbyte(void)
{
    u8 caseID = gBattlescriptCurrInstr[1];
    const u8* memByte = T2_READ_PTR(gBattlescriptCurrInstr + 2);
    u8 value = gBattlescriptCurrInstr[6];
    const u8* jumpPtr = T2_READ_PTR(gBattlescriptCurrInstr + 7);

    gBattlescriptCurrInstr += 11;

    switch (caseID)
    {
    case CMP_EQUAL:
        if (*memByte == value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_NOT_EQUAL:
        if (*memByte != value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_GREATER_THAN:
        if (*memByte > value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_LESS_THAN:
        if (*memByte < value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_COMMON_BITS:
        if (*memByte & value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(*memByte & value))
            gBattlescriptCurrInstr = jumpPtr;
        break;
    }
}

static void atk2A_jumpifhalfword(void)
{
    u8 caseID = gBattlescriptCurrInstr[1];
    const u16* memHword = T2_READ_PTR(gBattlescriptCurrInstr + 2);
    u16 value = T2_READ_16(gBattlescriptCurrInstr + 6);
    const u8* jumpPtr = T2_READ_PTR(gBattlescriptCurrInstr + 8);

    gBattlescriptCurrInstr += 12;

    switch (caseID)
    {
    case CMP_EQUAL:
        if (*memHword == value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_NOT_EQUAL:
        if (*memHword != value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_GREATER_THAN:
        if (*memHword > value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_LESS_THAN:
        if (*memHword < value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_COMMON_BITS:
        if (*memHword & value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(*memHword & value))
            gBattlescriptCurrInstr = jumpPtr;
        break;
    }
}

static void atk2B_jumpifword(void)
{
    u8 caseID = gBattlescriptCurrInstr[1];
    const u32* memWord = T2_READ_PTR(gBattlescriptCurrInstr + 2);
    u32 value = T1_READ_32(gBattlescriptCurrInstr + 6);
    const u8* jumpPtr = T2_READ_PTR(gBattlescriptCurrInstr + 10);

    gBattlescriptCurrInstr += 14;

    switch (caseID)
    {
    case CMP_EQUAL:
        if (*memWord == value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_NOT_EQUAL:
        if (*memWord != value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_GREATER_THAN:
        if (*memWord > value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_LESS_THAN:
        if (*memWord < value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_COMMON_BITS:
        if (*memWord & value)
            gBattlescriptCurrInstr = jumpPtr;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(*memWord & value))
            gBattlescriptCurrInstr = jumpPtr;
        break;
    }
}

static void atk2C_jumpifarrayequal(void)
{
    const u8* mem1 = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    const u8* mem2 = T2_READ_PTR(gBattlescriptCurrInstr + 5);
    u32 size = gBattlescriptCurrInstr[9];
    const u8* jumpPtr = T2_READ_PTR(gBattlescriptCurrInstr + 10);

    u8 i;
    for (i = 0; i < size; i++)
    {
        if (*mem1 != *mem2)
        {
            gBattlescriptCurrInstr += 14;
            break;
        }
        mem1++, mem2++;
    }

    if (i == size)
        gBattlescriptCurrInstr = jumpPtr;
}

static void atk2D_jumpifarraynotequal(void)
{
    u8 equalBytes = 0;
    const u8* mem1 = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    const u8* mem2 = T2_READ_PTR(gBattlescriptCurrInstr + 5);
    u32 size = gBattlescriptCurrInstr[9];
    const u8* jumpPtr = T2_READ_PTR(gBattlescriptCurrInstr + 10);

    u8 i;
    for (i = 0; i < size; i++)
    {
        if (*mem1 == *mem2)
        {
            equalBytes++;
        }
        mem1++, mem2++;
    }

    if (equalBytes != size)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 14;
}

static void atk2E_setbyte(void)
{
    u8* memByte = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    *memByte = gBattlescriptCurrInstr[5];

    gBattlescriptCurrInstr += 6;
}

static void atk2F_addbyte(void)
{
    u8* memByte = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    *memByte += gBattlescriptCurrInstr[5];
    gBattlescriptCurrInstr += 6;
}

static void atk30_subbyte(void)
{
    u8* memByte = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    *memByte -= gBattlescriptCurrInstr[5];
    gBattlescriptCurrInstr += 6;
}

static void atk31_copyarray(void)
{
    u8* dest = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    const u8* src = T2_READ_PTR(gBattlescriptCurrInstr + 5);
    s32 size = gBattlescriptCurrInstr[9];

    s32 i;
    for (i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }

    gBattlescriptCurrInstr += 10;
}

static void atk32_copyarraywithindex(void)
{
    u8* dest = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    const u8* src = T2_READ_PTR(gBattlescriptCurrInstr + 5);
    const u8* index = T2_READ_PTR(gBattlescriptCurrInstr + 9);
    s32 size = gBattlescriptCurrInstr[13];

    s32 i;
    for (i = 0; i < size; i++)
    {
        dest[i] = src[i + *index];
    }

    gBattlescriptCurrInstr += 14;
}

static void atk33_orbyte(void)
{
    u8* memByte = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    *memByte |= gBattlescriptCurrInstr[5];
    gBattlescriptCurrInstr += 6;
}

static void atk34_orhalfword(void)
{
    u16* memHword = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u16 val = T2_READ_16(gBattlescriptCurrInstr + 5);

    *memHword |= val;
    gBattlescriptCurrInstr += 7;
}

static void atk35_orword(void)
{
    u32* memWord = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u32 val = T2_READ_32(gBattlescriptCurrInstr + 5);

    *memWord |= val;
    gBattlescriptCurrInstr += 9;
}

static void atk36_bicbyte(void)
{
    u8* memByte = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    *memByte &= ~(gBattlescriptCurrInstr[5]);
    gBattlescriptCurrInstr += 6;
}

static void atk37_bichalfword(void)
{
    u16* memHword = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u16 val = T2_READ_16(gBattlescriptCurrInstr + 5);

    *memHword &= ~val;
    gBattlescriptCurrInstr += 7;
}

static void atk38_bicword(void)
{
    u32* memWord = T2_READ_PTR(gBattlescriptCurrInstr + 1);
    u32 val = T2_READ_32(gBattlescriptCurrInstr + 5);

    *memWord &= ~val;
    gBattlescriptCurrInstr += 9;
}

static void atk39_pause(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        u16 value = T2_READ_16(gBattlescriptCurrInstr + 1);
        if (++gPauseCounterBattle >= value)
        {
            gPauseCounterBattle = 0;
            gBattlescriptCurrInstr += 3;
        }
    }
}

static void atk3A_waitstate(void)
{
    if (gBattleControllerExecFlags == 0)
        gBattlescriptCurrInstr++;
}

static void atk3B_healthbar_update(void)
{
    if (gBattlescriptCurrInstr[1] == BS_TARGET)
        gActiveBattler = gBattlerTarget;
    else
        gActiveBattler = gBattlerAttacker;

    BtlController_EmitHealthBarUpdate(0, gBattleMoveDamage);
    MarkBattlerForControllerExec(gActiveBattler);
    gBattlescriptCurrInstr += 2;
}

static void atk3C_return(void)
{
    BattleScriptPop();
}

static void atk3D_end(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        BattleArena_AddSkillPoints(gBattlerAttacker);

    gMoveResultFlags = 0;
    gActiveBattler = 0;
    gCurrentActionFuncId = B_ACTION_TRY_FINISH;
}

static void atk3E_end2(void)
{
    gActiveBattler = 0;
    gCurrentActionFuncId = B_ACTION_TRY_FINISH;
}

static void atk3F_end3(void) // pops the main function stack
{
    BattleScriptPop();
    if (gBattleResources->battleCallbackStack->size != 0)
        gBattleResources->battleCallbackStack->size--;
    gBattleMainFunc = gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size];
}

static void atk41_call(void)
{
    BattleScriptPush(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atk42_setroost(void)
{
    gBattleResources->flags->flags[gBattlerAttacker] |= RESOURCE_FLAG_ROOST;

    // Pure flying type.
    if (gBattleMons[gBattlerAttacker].type1 == TYPE_FLYING && gBattleMons[gBattlerAttacker].type2 == TYPE_FLYING)
    {
        gBattleStruct->roostTypes[gBattlerAttacker][0] = TYPE_FLYING;
        gBattleStruct->roostTypes[gBattlerAttacker][1] = TYPE_FLYING;
        gBattleStruct->roostTypes[gBattlerAttacker][2] = TYPE_FLYING;
        SET_BATTLER_TYPE(gBattlerAttacker, TYPE_NORMAL);
    }
    // Dual Type with Flying Type.
    else if ((gBattleMons[gBattlerAttacker].type1 == TYPE_FLYING && gBattleMons[gBattlerAttacker].type2 != TYPE_FLYING)
           ||(gBattleMons[gBattlerAttacker].type2 == TYPE_FLYING && gBattleMons[gBattlerAttacker].type1 != TYPE_FLYING))
    {
        gBattleStruct->roostTypes[gBattlerAttacker][0] = gBattleMons[gBattlerAttacker].type1;
        gBattleStruct->roostTypes[gBattlerAttacker][1] = gBattleMons[gBattlerAttacker].type2;
        if (gBattleMons[gBattlerAttacker].type1 == TYPE_FLYING)
            gBattleMons[gBattlerAttacker].type1 = TYPE_MYSTERY;
        if (gBattleMons[gBattlerAttacker].type2 == TYPE_FLYING)
            gBattleMons[gBattlerAttacker].type2 = TYPE_MYSTERY;
    }
    // Non-flying type.
    else if (!IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_FLYING))
    {
        gBattleStruct->roostTypes[gBattlerAttacker][0] = gBattleMons[gBattlerAttacker].type1;
        gBattleStruct->roostTypes[gBattlerAttacker][1] = gBattleMons[gBattlerAttacker].type2;
    }

    gBattlescriptCurrInstr++;
}

static void atk43_jumpifabilitypresent(void)
{
    if (IsAbilityOnField(gBattlescriptCurrInstr[1]))
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
    else
        gBattlescriptCurrInstr += 6;
}

static void atk44_endselectionscript(void)
{
    *(gBattlerAttacker + gBattleStruct->selectionScriptFinished) = TRUE;
}

static void atk45_playanimation(void)
{
    const u16* argumentPtr;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    argumentPtr = T2_READ_PTR(gBattlescriptCurrInstr + 3);

    if (gBattlescriptCurrInstr[2] == B_ANIM_STATS_CHANGE
        || gBattlescriptCurrInstr[2] == B_ANIM_SNATCH_MOVE
        || gBattlescriptCurrInstr[2] == B_ANIM_MEGA_EVOLUTION
        || gBattlescriptCurrInstr[2] == B_ANIM_SUBSTITUTE_FADE)
    {
        BtlController_EmitBattleAnimation(0, gBattlescriptCurrInstr[2], *argumentPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 7;
    }
    else if (gHitMarker & HITMARKER_NO_ANIMATIONS)
    {
        BattleScriptPush(gBattlescriptCurrInstr + 7);
        gBattlescriptCurrInstr = BattleScript_Pausex20;
    }
    else if (gBattlescriptCurrInstr[2] == B_ANIM_RAIN_CONTINUES
             || gBattlescriptCurrInstr[2] == B_ANIM_SUN_CONTINUES
             || gBattlescriptCurrInstr[2] == B_ANIM_SANDSTORM_CONTINUES
             || gBattlescriptCurrInstr[2] == B_ANIM_HAIL_CONTINUES)
    {
        BtlController_EmitBattleAnimation(0, gBattlescriptCurrInstr[2], *argumentPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 7;
    }
    else if (gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr += 7;
    }
    else
    {
        BtlController_EmitBattleAnimation(0, gBattlescriptCurrInstr[2], *argumentPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 7;
    }
}

static void atk46_playanimation2(void) // animation Id is stored in the first pointer
{
    const u16* argumentPtr;
    const u8* animationIdPtr;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    animationIdPtr = T2_READ_PTR(gBattlescriptCurrInstr + 2);
    argumentPtr = T2_READ_PTR(gBattlescriptCurrInstr + 6);

    if (*animationIdPtr == B_ANIM_STATS_CHANGE
        || *animationIdPtr == B_ANIM_SNATCH_MOVE
        || *animationIdPtr == B_ANIM_MEGA_EVOLUTION
        || *animationIdPtr == B_ANIM_SUBSTITUTE_FADE)
    {
        BtlController_EmitBattleAnimation(0, *animationIdPtr, *argumentPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 10;
    }
    else if (gHitMarker & HITMARKER_NO_ANIMATIONS)
    {
        gBattlescriptCurrInstr += 10;
    }
    else if (*animationIdPtr == B_ANIM_RAIN_CONTINUES
             || *animationIdPtr == B_ANIM_SUN_CONTINUES
             || *animationIdPtr == B_ANIM_SANDSTORM_CONTINUES
             || *animationIdPtr == B_ANIM_HAIL_CONTINUES)
    {
        BtlController_EmitBattleAnimation(0, *animationIdPtr, *argumentPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 10;
    }
    else if (gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr += 10;
    }
    else
    {
        BtlController_EmitBattleAnimation(0, *animationIdPtr, *argumentPtr);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 10;
    }
}

static void atk47_setgraphicalstatchangevalues(void)
{
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
    gBattlescriptCurrInstr++;
}

static void atk48_playstatchangeanimation(void)
{
    u32 ability;
    u32 currStat = 0;
    u32 statAnimId = 0;
    u32 changeableStatsCount = 0;
    u32 statsToCheck = 0;
    u32 startingStatAnimId = 0;
    u32 flags = gBattlescriptCurrInstr[3];

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    ability = GetBattlerAbility(gActiveBattler);
    statsToCheck = gBattlescriptCurrInstr[2];

    // Handle Contrary and Simple
    if (ability == ABILITY_CONTRARY)
        flags ^= ATK48_STAT_NEGATIVE;
    else if (ability == ABILITY_SIMPLE)
        flags |= ATK48_STAT_BY_TWO;

    if (flags & ATK48_STAT_NEGATIVE) // goes down
    {
        if (flags & ATK48_STAT_BY_TWO)
            startingStatAnimId = STAT_ANIM_MINUS2 - 1;
        else
            startingStatAnimId = STAT_ANIM_MINUS1 - 1;

        while (statsToCheck != 0)
        {
            if (statsToCheck & 1)
            {
                if (flags & ATK48_DONT_CHECK_LOWER)
                {
                    if (gBattleMons[gActiveBattler].statStages[currStat] > 0)
                    {
                        statAnimId = startingStatAnimId + currStat;
                        changeableStatsCount++;
                    }
                }
                else if (!gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].mistTimer
                        && ability != ABILITY_CLEAR_BODY
                        && ability != ABILITY_WHITE_SMOKE
                        && !(ability == ABILITY_KEEN_EYE && currStat == STAT_ACC)
                        && !(ability == ABILITY_HYPER_CUTTER && currStat == STAT_ATK))
                {
                    if (gBattleMons[gActiveBattler].statStages[currStat] > 0)
                    {
                        statAnimId = startingStatAnimId + currStat;
                        changeableStatsCount++;
                    }
                }
            }
            statsToCheck >>= 1, currStat++;
        }

        if (changeableStatsCount > 1) // more than one stat, so the color is gray
        {
            if (flags & ATK48_STAT_BY_TWO)
                statAnimId = STAT_ANIM_MULTIPLE_MINUS2;
            else
                statAnimId = STAT_ANIM_MULTIPLE_MINUS1;
        }
    }
    else // goes up
    {
        if (flags & ATK48_STAT_BY_TWO)
            startingStatAnimId = STAT_ANIM_PLUS2 - 1;
        else
            startingStatAnimId = STAT_ANIM_PLUS1 - 1;

        while (statsToCheck != 0)
        {
            if (statsToCheck & 1 && gBattleMons[gActiveBattler].statStages[currStat] < 0xC)
            {
                statAnimId = startingStatAnimId + currStat;
                changeableStatsCount++;
            }
            statsToCheck >>= 1, currStat++;
        }

        if (changeableStatsCount > 1) // more than one stat, so the color is gray
        {
            if (flags & ATK48_STAT_BY_TWO)
                statAnimId = STAT_ANIM_MULTIPLE_PLUS2;
            else
                statAnimId = STAT_ANIM_MULTIPLE_PLUS1;
        }
    }

    if (flags & ATK48_ONLY_MULTIPLE && changeableStatsCount < 2)
    {
        gBattlescriptCurrInstr += 4;
    }
    else if (changeableStatsCount != 0 && !gBattleScripting.statAnimPlayed)
    {
        BtlController_EmitBattleAnimation(0, B_ANIM_STATS_CHANGE, statAnimId);
        MarkBattlerForControllerExec(gActiveBattler);
        if (flags & ATK48_ONLY_MULTIPLE && changeableStatsCount > 1)
            gBattleScripting.statAnimPlayed = TRUE;
        gBattlescriptCurrInstr += 4;
    }
    else
    {
        gBattlescriptCurrInstr += 4;
    }
}

static void atk49_moveend(void)
{
    s32 i;
    bool32 effect = FALSE;
    u32 moveType = 0;
    u32 holdEffectAtk = 0;
    u16 *choicedMoveAtk = NULL;
    u32 arg1, arg2;
    u32 originallyUsedMove;

    if (gChosenMove == 0xFFFF)
        originallyUsedMove = 0;
    else
        originallyUsedMove = gChosenMove;

    arg1 = gBattlescriptCurrInstr[1];
    arg2 = gBattlescriptCurrInstr[2];

    holdEffectAtk = GetBattlerHoldEffect(gBattlerAttacker, TRUE);
    choicedMoveAtk = &gBattleStruct->choicedMove[gBattlerAttacker];
    GET_MOVE_TYPE(gCurrentMove, moveType);

    do
    {
        switch (gBattleScripting.atk49_state)
        {
        case ATK49_PROTECT_LIKE_EFFECT:
            if (gBattleMoves[gCurrentMove].flags & FLAG_MAKES_CONTACT)
            {
                if (gProtectStructs[gBattlerTarget].spikyShielded && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD)
                {
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
                    i = gBattlerAttacker;
                    gBattlerAttacker = gBattlerTarget;
                    gBattlerTarget = i; // gBattlerTarget and gBattlerAttacker are swapped in order to activate Defiant, if applicable
                    gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_2;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_KingsShieldEffect;
                    effect = 1;
                }
                else if (gProtectStructs[gBattlerTarget].banefulBunkered)
                {
                    gBattleScripting.moveEffect = MOVE_EFFECT_POISON | MOVE_EFFECT_AFFECTS_USER;
                    PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_BANEFUL_BUNKER);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BanefulBunkerEffect;
                    effect = 1;
                }
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_RAGE: // rage check
            if (gBattleMons[gBattlerTarget].status2 & STATUS2_RAGE
                && gBattleMons[gBattlerTarget].hp != 0 && gBattlerAttacker != gBattlerTarget
                && GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget)
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) && TARGET_TURN_DAMAGED
                && gBattleMoves[gCurrentMove].power && gBattleMons[gBattlerTarget].statStages[STAT_ATK] <= 0xB)
            {
                gBattleMons[gBattlerTarget].statStages[STAT_ATK]++;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_RageIsBuilding;
                effect = TRUE;
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_DEFROST: // defrosting check
            if (gBattleMons[gBattlerTarget].status1 & STATUS1_FREEZE
                && gBattleMons[gBattlerTarget].hp != 0 && gBattlerAttacker != gBattlerTarget
                && gSpecialStatuses[gBattlerTarget].specialDmg
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT) && (moveType == TYPE_FIRE || gBattleMoves[gCurrentMove].effect == EFFECT_SCALD))
            {
                gBattleMons[gBattlerTarget].status1 &= ~(STATUS1_FREEZE);
                gActiveBattler = gBattlerTarget;
                BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBattlerTarget].status1);
                MarkBattlerForControllerExec(gActiveBattler);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_DefrostedViaFireMove;
                effect = TRUE;
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_SYNCHRONIZE_TARGET: // target synchronize
            if (AbilityBattleEffects(ABILITYEFFECT_SYNCHRONIZE, gBattlerTarget, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.atk49_state++;
            break;
        case ATK49_MOVE_END_ABILITIES: // Such as abilities activating on contact(Poison Spore, Rough Skin, etc.).
            if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END, gBattlerTarget, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.atk49_state++;
            break;
        case ATK49_STATUS_IMMUNITY_ABILITIES: // status immunities
            if (AbilityBattleEffects(ABILITYEFFECT_IMMUNITY, 0, 0, 0, 0))
                effect = TRUE; // it loops through all battlers, so we increment after its done with all battlers
            else
                gBattleScripting.atk49_state++;
            break;
        case ATK49_SYNCHRONIZE_ATTACKER: // attacker synchronize
            if (AbilityBattleEffects(ABILITYEFFECT_ATK_SYNCHRONIZE, gBattlerAttacker, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.atk49_state++;
            break;
        case ATK49_CHOICE_MOVE: // update choice band move
            if (!(gHitMarker & HITMARKER_OBEYS) || !HOLD_EFFECT_CHOICE(holdEffectAtk)
                || gChosenMove == MOVE_STRUGGLE || (*choicedMoveAtk != 0 && *choicedMoveAtk != 0xFFFF))
                    goto LOOP;
            if ((gBattleMoves[gChosenMove].effect == EFFECT_BATON_PASS
                 || gBattleMoves[gChosenMove].effect == EFFECT_HEALING_WISH
                 || gBattleMoves[gChosenMove].effect == EFFECT_HIT_ESCAPE)
            && !(gMoveResultFlags & MOVE_RESULT_FAILED))
            {
                gBattleScripting.atk49_state++;
                break;
            }
            *choicedMoveAtk = gChosenMove;
            LOOP:
            {
                for (i = 0; i < MAX_MON_MOVES; i++)
                {
                    if (gBattleMons[gBattlerAttacker].moves[i] == *choicedMoveAtk)
                        break;
                }
                if (i == MAX_MON_MOVES)
                    *choicedMoveAtk = 0;

                gBattleScripting.atk49_state++;
            }
            break;
        case ATK49_CHANGED_ITEMS: // changed held items
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleStruct->changedItems[i] != 0)
                {
                    gBattleMons[i].item = gBattleStruct->changedItems[i];
                    gBattleStruct->changedItems[i] = 0;
                }
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_ITEM_EFFECTS_TARGET:
            if (ItemBattleEffects(ITEMEFFECT_TARGET, gBattlerTarget, FALSE))
                effect = TRUE;
            gBattleScripting.atk49_state++;
            break;
        case ATK49_ITEM_EFFECTS_ALL: // item effects for all battlers
            if (ItemBattleEffects(ITEMEFFECT_MOVE_END, 0, FALSE))
                effect = TRUE;
            else
                gBattleScripting.atk49_state++;
            break;
        case ATK49_KINGSROCK_SHELLBELL: // king's rock and shell bell
            if (ItemBattleEffects(ITEMEFFECT_KINGSROCK_SHELLBELL, 0, FALSE))
                effect = TRUE;
            gBattleScripting.atk49_state++;
            break;
        case ATK49_ATTACKER_INVISIBLE: // make attacker sprite invisible
            if (gStatuses3[gBattlerAttacker] & (STATUS3_SEMI_INVULNERABLE)
                && gHitMarker & HITMARKER_NO_ANIMATIONS)
            {
                gActiveBattler = gBattlerAttacker;
                BtlController_EmitSpriteInvisibility(0, TRUE);
                MarkBattlerForControllerExec(gActiveBattler);
                gBattleScripting.atk49_state++;
                return;
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_ATTACKER_VISIBLE: // make attacker sprite visible
            if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT
                || !(gStatuses3[gBattlerAttacker] & (STATUS3_SEMI_INVULNERABLE))
                || WasUnableToUseMove(gBattlerAttacker))
            {
                gActiveBattler = gBattlerAttacker;
                BtlController_EmitSpriteInvisibility(0, FALSE);
                MarkBattlerForControllerExec(gActiveBattler);
                gStatuses3[gBattlerAttacker] &= ~(STATUS3_SEMI_INVULNERABLE);
                gSpecialStatuses[gBattlerAttacker].restoredBattlerSprite = 1;
                gBattleScripting.atk49_state++;
                return;
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_TARGET_VISIBLE: // make target sprite visible
            if (!gSpecialStatuses[gBattlerTarget].restoredBattlerSprite && gBattlerTarget < gBattlersCount
                && !(gStatuses3[gBattlerTarget] & STATUS3_SEMI_INVULNERABLE))
            {
                gActiveBattler = gBattlerTarget;
                BtlController_EmitSpriteInvisibility(0, FALSE);
                MarkBattlerForControllerExec(gActiveBattler);
                gStatuses3[gBattlerTarget] &= ~(STATUS3_SEMI_INVULNERABLE);
                gBattleScripting.atk49_state++;
                return;
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_SUBSTITUTE: // update substitute
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gDisableStructs[i].substituteHP == 0)
                    gBattleMons[i].status2 &= ~(STATUS2_SUBSTITUTE);
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_UPDATE_LAST_MOVES:
            gDisableStructs[gBattlerAttacker].usedMoves |= gBitTable[gCurrMovePos];
            gBattleStruct->lastMoveTarget[gBattlerAttacker] = gBattlerTarget;
            if (gMoveResultFlags & (MOVE_RESULT_FAILED | MOVE_RESULT_DOESNT_AFFECT_FOE))
                gBattleStruct->lastMoveFailed |= gBitTable[gBattlerAttacker];
            else
                gBattleStruct->lastMoveFailed &= ~(gBitTable[gBattlerAttacker]);

            if (gHitMarker & HITMARKER_SWAP_ATTACKER_TARGET)
            {
                gActiveBattler = gBattlerAttacker;
                gBattlerAttacker = gBattlerTarget;
                gBattlerTarget = gActiveBattler;
                gHitMarker &= ~(HITMARKER_SWAP_ATTACKER_TARGET);
            }
            if (gHitMarker & HITMARKER_ATTACKSTRING_PRINTED)
            {
                gLastPrintedMoves[gBattlerAttacker] = gChosenMove;
                gLastUsedMove = gCurrentMove;
            }
            if (!(gAbsentBattlerFlags & gBitTable[gBattlerAttacker])
                && !(gBattleStruct->field_91 & gBitTable[gBattlerAttacker])
                && gBattleMoves[originallyUsedMove].effect != EFFECT_BATON_PASS
                && gBattleMoves[originallyUsedMove].effect != EFFECT_HEALING_WISH)
            {
                if (gHitMarker & HITMARKER_OBEYS)
                {
                    gLastMoves[gBattlerAttacker] = gChosenMove;
                    gLastResultingMoves[gBattlerAttacker] = gCurrentMove;
                }
                else
                {
                    gLastMoves[gBattlerAttacker] = 0xFFFF;
                    gLastResultingMoves[gBattlerAttacker] = 0xFFFF;
                }

                if (!(gHitMarker & HITMARKER_FAINTED(gBattlerTarget)))
                    gLastHitBy[gBattlerTarget] = gBattlerAttacker;

                if (gHitMarker & HITMARKER_OBEYS && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
                {
                    if (gChosenMove == 0xFFFF)
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
                    gLastLandedMoves[gBattlerTarget] = 0xFFFF;
                }
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_MIRROR_MOVE: // mirror move
            if (!(gAbsentBattlerFlags & gBitTable[gBattlerAttacker]) && !(gBattleStruct->field_91 & gBitTable[gBattlerAttacker])
                && gBattleMoves[originallyUsedMove].flags & FLAG_MIRROR_MOVE_AFFECTED && gHitMarker & HITMARKER_OBEYS
                && gBattlerAttacker != gBattlerTarget && !(gHitMarker & HITMARKER_FAINTED(gBattlerTarget))
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT))
            {
                gBattleStruct->lastTakenMove[gBattlerTarget] = gChosenMove;
                gBattleStruct->lastTakenMoveFrom[gBattlerTarget][gBattlerAttacker] = gChosenMove;
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_NEXT_TARGET: // For moves hitting two opposing Pokemon.
            if (!(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE)
                && gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                && !gProtectStructs[gBattlerAttacker].chargingTurn
                && (gBattleMoves[gCurrentMove].target == MOVE_TARGET_BOTH || gBattleMoves[gCurrentMove].target == MOVE_TARGET_FOES_AND_ALLY)
                && !(gHitMarker & HITMARKER_NO_ATTACKSTRING))
            {
                u8 battlerId;

                if (gBattleMoves[gCurrentMove].target == MOVE_TARGET_FOES_AND_ALLY)
                {
                    for (battlerId = gBattlerTarget + 1; battlerId < gBattlersCount; battlerId++)
                    {
                        if (battlerId == gBattlerAttacker)
                            continue;
                        if (IsBattlerAlive(battlerId))
                            break;
                    }
                }
                else
                {
                    battlerId = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gBattlerTarget)));
                    gHitMarker |= HITMARKER_NO_ATTACKSTRING;
                }

                if (IsBattlerAlive(battlerId))
                {
                    gBattlerTarget = battlerId;
                    gBattleScripting.atk49_state = 0;
                    MoveValuesCleanUp();
                    gBattleScripting.moveEffect = gBattleScripting.savedMoveEffect;
                    BattleScriptPush(gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect]);
                    gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
                    return;
                }
                else
                {
                    gHitMarker |= HITMARKER_NO_ATTACKSTRING;
                }
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_LIFE_ORB:
            if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LIFE_ORB
                && !(GetBattlerAbility(gBattlerAttacker) == ABILITY_SHEER_FORCE && gBattleMoves[gCurrentMove].flags & FLAG_SHEER_FORCE_BOOST)
                && GetBattlerAbility(gBattlerAttacker) != ABILITY_MAGIC_GUARD
                && gSpecialStatuses[gBattlerAttacker].damagedMons)
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 10;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                effect = TRUE;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ItemHurtRet;
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_CLEAR_BITS: // Clear bits active while using a move for all targets and all hits.
            if (gSpecialStatuses[gBattlerAttacker].instructedChosenTarget)
                *(gBattleStruct->moveTarget + gBattlerAttacker) = gSpecialStatuses[gBattlerAttacker].instructedChosenTarget & 0x3;
            gProtectStructs[gBattlerAttacker].usesBouncedMove = 0;
            gBattleStruct->ateBoost[gBattlerAttacker] = 0;
            gStatuses3[gBattlerAttacker] &= ~(STATUS3_ME_FIRST);
            gSpecialStatuses[gBattlerAttacker].gemBoost = 0;
            gSpecialStatuses[gBattlerAttacker].damagedMons = 0;
            gSpecialStatuses[gBattlerTarget].berryReduced = 0;
            gBattleScripting.atk49_state++;
            break;
        case ATK49_COUNT:
            break;
        }

        if (arg1 == 1 && effect == FALSE)
            gBattleScripting.atk49_state = ATK49_COUNT;
        if (arg1 == 2 && arg2 == gBattleScripting.atk49_state)
            gBattleScripting.atk49_state = ATK49_COUNT;

    } while (gBattleScripting.atk49_state != ATK49_COUNT && effect == FALSE);

    if (gBattleScripting.atk49_state == ATK49_COUNT && effect == FALSE)
        gBattlescriptCurrInstr += 3;
}

static void atk4A_sethealblock(void)
{
    if (gStatuses3[gBattlerTarget] & STATUS3_HEAL_BLOCK)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gStatuses3[gBattlerTarget] |= STATUS3_HEAL_BLOCK;
        gDisableStructs[gBattlerTarget].healBlockTimer = 5;
        gBattlescriptCurrInstr += 5;
    }
}

static void atk4B_returnatktoball(void)
{
    gActiveBattler = gBattlerAttacker;
    if (!(gHitMarker & HITMARKER_FAINTED(gActiveBattler)))
    {
        BtlController_EmitReturnMonToBall(0, 0);
        MarkBattlerForControllerExec(gActiveBattler);
    }
    gBattlescriptCurrInstr++;
}

static void atk4C_getswitchedmondata(void)
{
    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    gBattlerPartyIndexes[gActiveBattler] = *(gBattleStruct->monToSwitchIntoId + gActiveBattler);

    BtlController_EmitGetMonData(0, REQUEST_ALL_BATTLE, gBitTable[gBattlerPartyIndexes[gActiveBattler]]);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 2;
}

static void atk4D_switchindataupdate(void)
{
    struct BattlePokemon oldData;
    s32 i;
    u8 *monData;

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    oldData = gBattleMons[gActiveBattler];
    monData = (u8*)(&gBattleMons[gActiveBattler]);

    for (i = 0; i < sizeof(struct BattlePokemon); i++)
    {
        monData[i] = gBattleResources->bufferB[gActiveBattler][4 + i];
    }

    gBattleMons[gActiveBattler].type1 = gBaseStats[gBattleMons[gActiveBattler].species].type1;
    gBattleMons[gActiveBattler].type2 = gBaseStats[gBattleMons[gActiveBattler].species].type2;
    gBattleMons[gActiveBattler].type3 = TYPE_MYSTERY;
    gBattleMons[gActiveBattler].ability = GetAbilityBySpecies(gBattleMons[gActiveBattler].species, gBattleMons[gActiveBattler].altAbility);

    // check knocked off item
    i = GetBattlerSide(gActiveBattler);
    if (gWishFutureKnock.knockedOffMons[i] & gBitTable[gBattlerPartyIndexes[gActiveBattler]])
    {
        gBattleMons[gActiveBattler].item = 0;
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

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE && gBattleMons[gActiveBattler].maxHP / 2 >= gBattleMons[gActiveBattler].hp
        && gBattleMons[gActiveBattler].hp != 0 && !(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP))
    {
        gBattleStruct->field_92 |= gBitTable[gActiveBattler];
    }

    gBattleScripting.battler = gActiveBattler;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gActiveBattler, gBattlerPartyIndexes[gActiveBattler]);

    gBattlescriptCurrInstr += 2;
}

static void atk4E_switchinanim(void)
{
    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT
        && !(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                 | BATTLE_TYPE_EREADER_TRAINER
                                 | BATTLE_TYPE_x2000000
                                 | BATTLE_TYPE_TRAINER_HILL
                                 | BATTLE_TYPE_FRONTIER)))
            HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBattler].species), FLAG_SET_SEEN, gBattleMons[gActiveBattler].personality);

    gAbsentBattlerFlags &= ~(gBitTable[gActiveBattler]);

    BtlController_EmitSwitchInAnim(0, gBattlerPartyIndexes[gActiveBattler], gBattlescriptCurrInstr[2]);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 3;

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        BattleArena_InitPoints();
}

static void atk4F_jumpifcantswitch(void)
{
    s32 i;
    s32 lastMonId;
    u8 battlerIn1, battlerIn2;
    struct Pokemon *party;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1] & ~(ATK4F_DONT_CHECK_STATUSES));

    if (!(gBattlescriptCurrInstr[1] & ATK4F_DONT_CHECK_STATUSES)
        && ((gBattleMons[gActiveBattler].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
            || (gStatuses3[gActiveBattler] & STATUS3_ROOTED)))
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
    }
    else if (BATTLE_TWO_VS_ONE_OPPONENT && GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT)
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

        if (i == PARTY_SIZE)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT)
            party = gEnemyParty;
        else
            party = gPlayerParty;

        i = 0;
        if (gActiveBattler & 2)
            i = 3;

        for (lastMonId = i + 3; i < lastMonId; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0
             && gBattlerPartyIndexes[gActiveBattler] != i)
                break;
        }

        if (i == lastMonId)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x800000)
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            {
                party = gPlayerParty;

                i = 0;
                if (GetLinkTrainerFlankId(GetBattlerMultiplayerId(gActiveBattler)) == TRUE)
                    i = 3;
            }
            else
            {
                party = gEnemyParty;

                if (gActiveBattler == 1)
                    i = 0;
                else
                    i = 3;
            }
        }
        else
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT)
                party = gEnemyParty;
            else
                party = gPlayerParty;

            i = 0;
            if (GetLinkTrainerFlankId(GetBattlerMultiplayerId(gActiveBattler)) == TRUE)
                i = 3;
        }

        for (lastMonId = i + 3; i < lastMonId; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0
             && gBattlerPartyIndexes[gActiveBattler] != i)
                break;
        }

        if (i == lastMonId)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT)
    {
        party = gEnemyParty;

        i = 0;
        if (gActiveBattler == B_POSITION_OPPONENT_RIGHT)
            i = 3;

        for (lastMonId = i + 3; i < lastMonId; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0
             && gBattlerPartyIndexes[gActiveBattler] != i)
                break;
        }

        if (i == lastMonId)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
    else
    {
        if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT)
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

        if (i == 6)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
}

static void sub_804CF10(u8 arg0)
{
    *(gBattleStruct->field_58 + gActiveBattler) = gBattlerPartyIndexes[gActiveBattler];
    *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = 6;
    gBattleStruct->field_93 &= ~(gBitTable[gActiveBattler]);

    BtlController_EmitChoosePokemon(0, PARTY_MUST_CHOOSE_MON, arg0, 0, gBattleStruct->field_60[gActiveBattler]);
    MarkBattlerForControllerExec(gActiveBattler);
}

static void atk50_openpartyscreen(void)
{
    u32 flags;
    u8 hitmarkerFaintBits;
    u8 battlerId;
    const u8 *jumpPtr;

    battlerId = 0;
    flags = 0;
    jumpPtr = T1_READ_PTR(gBattlescriptCurrInstr + 2);

    if (gBattlescriptCurrInstr[1] == 5)
    {
        if ((gBattleTypeFlags & (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_MULTI)) != BATTLE_TYPE_DOUBLE)
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gHitMarker & HITMARKER_FAINTED(gActiveBattler))
                {
                    if (HasNoMonsToSwitch(gActiveBattler, 6, 6))
                    {
                        gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                        gHitMarker &= ~(HITMARKER_FAINTED(gActiveBattler));
                        BtlController_EmitLinkStandbyMsg(0, 2, 0);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                    else if (!gSpecialStatuses[gActiveBattler].flag40)
                    {
                        sub_804CF10(6);
                        gSpecialStatuses[gActiveBattler].flag40 = 1;
                    }
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(0, 2, 0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
            }
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            u8 flag40_0, flag40_1, flag40_2, flag40_3;

            hitmarkerFaintBits = gHitMarker >> 0x1C;

            if (gBitTable[0] & hitmarkerFaintBits)
            {
                gActiveBattler = 0;
                if (HasNoMonsToSwitch(0, 6, 6))
                {
                    gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBattler));
                    BtlController_EmitCmd42(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                else if (!gSpecialStatuses[gActiveBattler].flag40)
                {
                    sub_804CF10(gBattleStruct->monToSwitchIntoId[2]);
                    gSpecialStatuses[gActiveBattler].flag40 = 1;
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(0, 2, 0);
                    MarkBattlerForControllerExec(gActiveBattler);
                    flags |= 1;
                }
            }
            if (gBitTable[2] & hitmarkerFaintBits && !(gBitTable[0] & hitmarkerFaintBits))
            {
                gActiveBattler = 2;
                if (HasNoMonsToSwitch(2, 6, 6))
                {
                    gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBattler));
                    BtlController_EmitCmd42(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                else if (!gSpecialStatuses[gActiveBattler].flag40)
                {
                    sub_804CF10(gBattleStruct->monToSwitchIntoId[0]);
                    gSpecialStatuses[gActiveBattler].flag40 = 1;
                }
                else if (!(flags & 1))
                {
                    BtlController_EmitLinkStandbyMsg(0, 2, 0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
            }
            if (gBitTable[1] & hitmarkerFaintBits)
            {
                gActiveBattler = 1;
                if (HasNoMonsToSwitch(1, 6, 6))
                {
                    gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBattler));
                    BtlController_EmitCmd42(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                else if (!gSpecialStatuses[gActiveBattler].flag40)
                {
                    sub_804CF10(gBattleStruct->monToSwitchIntoId[3]);
                    gSpecialStatuses[gActiveBattler].flag40 = 1;
                }
                else
                {
                    BtlController_EmitLinkStandbyMsg(0, 2, 0);
                    MarkBattlerForControllerExec(gActiveBattler);
                    flags |= 2;
                }
            }
            if (gBitTable[3] & hitmarkerFaintBits && !(gBitTable[1] & hitmarkerFaintBits))
            {
                gActiveBattler = 3;
                if (HasNoMonsToSwitch(3, 6, 6))
                {
                    gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBattler));
                    BtlController_EmitCmd42(0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
                else if (!gSpecialStatuses[gActiveBattler].flag40)
                {
                    sub_804CF10(gBattleStruct->monToSwitchIntoId[1]);
                    gSpecialStatuses[gActiveBattler].flag40 = 1;
                }
                else if (!(flags & 2))
                {
                    BtlController_EmitLinkStandbyMsg(0, 2, 0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
            }

            flag40_0 = gSpecialStatuses[0].flag40;
            if (!flag40_0)
            {
                flag40_2 = gSpecialStatuses[2].flag40;
                if (!flag40_2 && hitmarkerFaintBits != 0)
                {
                    if (gAbsentBattlerFlags & gBitTable[0])
                        gActiveBattler = 2;
                    else
                        gActiveBattler = 0;

                    BtlController_EmitLinkStandbyMsg(0, 2, 0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }

            }
            flag40_1 = gSpecialStatuses[1].flag40;
            if (!flag40_1)
            {
                flag40_3 = gSpecialStatuses[3].flag40;
                if (!flag40_3 && hitmarkerFaintBits != 0)
                {
                    if (gAbsentBattlerFlags & gBitTable[1])
                        gActiveBattler = 3;
                    else
                        gActiveBattler = 1;

                    BtlController_EmitLinkStandbyMsg(0, 2, 0);
                    MarkBattlerForControllerExec(gActiveBattler);
                }
            }
        }
        gBattlescriptCurrInstr += 6;
    }
    else if (gBattlescriptCurrInstr[1] == 6)
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
            {
                hitmarkerFaintBits = gHitMarker >> 0x1C;
                if (gBitTable[2] & hitmarkerFaintBits && gBitTable[0] & hitmarkerFaintBits)
                {
                    gActiveBattler = 2;
                    if (HasNoMonsToSwitch(2, gBattleResources->bufferB[0][1], 6))
                    {
                        gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                        gHitMarker &= ~(HITMARKER_FAINTED(gActiveBattler));
                        BtlController_EmitCmd42(0);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                    else if (!gSpecialStatuses[gActiveBattler].flag40)
                    {
                        sub_804CF10(gBattleStruct->monToSwitchIntoId[0]);
                        gSpecialStatuses[gActiveBattler].flag40 = 1;
                    }
                }
                if (gBitTable[3] & hitmarkerFaintBits && hitmarkerFaintBits & gBitTable[1])
                {
                    gActiveBattler = 3;
                    if (HasNoMonsToSwitch(3, gBattleResources->bufferB[1][1], 6))
                    {
                        gAbsentBattlerFlags |= gBitTable[gActiveBattler];
                        gHitMarker &= ~(HITMARKER_FAINTED(gActiveBattler));
                        BtlController_EmitCmd42(0);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                    else if (!gSpecialStatuses[gActiveBattler].flag40)
                    {
                        sub_804CF10(gBattleStruct->monToSwitchIntoId[1]);
                        gSpecialStatuses[gActiveBattler].flag40 = 1;
                    }
                }
                gBattlescriptCurrInstr += 6;
            }
            else
            {
                gBattlescriptCurrInstr += 6;
            }
        }
        else
        {
            gBattlescriptCurrInstr += 6;
        }

        hitmarkerFaintBits = gHitMarker >> 0x1C;

        gBattlerFainted = 0;
        while (1)
        {
            if (gBitTable[gBattlerFainted] & hitmarkerFaintBits)
                break;
            if (gBattlerFainted >= gBattlersCount)
                break;
            gBattlerFainted++;
        }

        if (gBattlerFainted == gBattlersCount)
            gBattlescriptCurrInstr = jumpPtr;
    }
    else
    {
        if (gBattlescriptCurrInstr[1] & 0x80)
            hitmarkerFaintBits = PARTY_CHOOSE_MON; // Used here as the caseId for the EmitChoose function.
        else
            hitmarkerFaintBits = PARTY_MUST_CHOOSE_MON;

        battlerId = GetBattlerForBattleScript(gBattlescriptCurrInstr[1] & ~(0x80));
        if (gSpecialStatuses[battlerId].flag40)
        {
            gBattlescriptCurrInstr += 6;
        }
        else if (HasNoMonsToSwitch(battlerId, 6, 6))
        {
            gActiveBattler = battlerId;
            gAbsentBattlerFlags |= gBitTable[gActiveBattler];
            gHitMarker &= ~(HITMARKER_FAINTED(gActiveBattler));
            gBattlescriptCurrInstr = jumpPtr;
        }
        else
        {
            gActiveBattler = battlerId;
            *(gBattleStruct->field_58 + gActiveBattler) = gBattlerPartyIndexes[gActiveBattler];
            *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = 6;
            gBattleStruct->field_93 &= ~(gBitTable[gActiveBattler]);

            BtlController_EmitChoosePokemon(0, hitmarkerFaintBits, *(gBattleStruct->monToSwitchIntoId + (gActiveBattler ^ 2)), 0, gBattleStruct->field_60[gActiveBattler]);
            MarkBattlerForControllerExec(gActiveBattler);

            gBattlescriptCurrInstr += 6;

            if (GetBattlerPosition(gActiveBattler) == 0 && gBattleResults.playerSwitchesCounter < 0xFF)
                gBattleResults.playerSwitchesCounter++;

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
                {
                    if (gActiveBattler != battlerId)
                    {
                        BtlController_EmitLinkStandbyMsg(0, 2, 0);
                        MarkBattlerForControllerExec(gActiveBattler);
                    }
                }
            }
            else
            {
                gActiveBattler = GetBattlerAtPosition(GetBattlerPosition(battlerId) ^ BIT_SIDE);
                if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
                    gActiveBattler ^= BIT_FLANK;

                BtlController_EmitLinkStandbyMsg(0, 2, 0);
                MarkBattlerForControllerExec(gActiveBattler);
            }
        }
    }
}

static void atk51_switchhandleorder(void)
{
    s32 i;
    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    switch (gBattlescriptCurrInstr[2])
    {
    case 0:
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattleResources->bufferB[i][0] == 0x22)
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
            sub_803BDA0(gActiveBattler);
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
            *(gActiveBattler * 3 + (u8*)(gBattleStruct->field_60) + 0) &= 0xF;
            *(gActiveBattler * 3 + (u8*)(gBattleStruct->field_60) + 0) |= (gBattleResources->bufferB[gActiveBattler][2] & 0xF0);
            *(gActiveBattler * 3 + (u8*)(gBattleStruct->field_60) + 1) = gBattleResources->bufferB[gActiveBattler][3];

            *((gActiveBattler ^ BIT_FLANK) * 3 + (u8*)(gBattleStruct->field_60) + 0) &= (0xF0);
            *((gActiveBattler ^ BIT_FLANK) * 3 + (u8*)(gBattleStruct->field_60) + 0) |= (gBattleResources->bufferB[gActiveBattler][2] & 0xF0) >> 4;
            *((gActiveBattler ^ BIT_FLANK) * 3 + (u8*)(gBattleStruct->field_60) + 2) = gBattleResources->bufferB[gActiveBattler][3];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            sub_80571DC(gActiveBattler, *(gBattleStruct->monToSwitchIntoId + gActiveBattler));
        }
        else
        {
            sub_803BDA0(gActiveBattler);
        }

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerAttacker].species)
        PREPARE_MON_NICK_BUFFER(gBattleTextBuff2, gActiveBattler, gBattleResources->bufferB[gActiveBattler][1])
        break;
    }

    gBattlescriptCurrInstr += 3;
}

static void SetDmgHazardsBattlescript(u8 battlerId, u8 multistringId)
{
    gBattleMons[battlerId].status2 &= ~(STATUS2_DESTINY_BOND);
    gHitMarker &= ~(HITMARKER_DESTINYBOND);
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

static void atk52_switchineffects(void)
{
    s32 i;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    sub_803FA70(gActiveBattler);

    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBattler));
    gSpecialStatuses[gActiveBattler].flag40 = 0;

    if (!(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_SPIKES_DAMAGED)
        && (gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_SPIKES)
        && IsBattlerGrounded(gActiveBattler))
    {
        u8 spikesDmg = (5 - gSideTimers[GetBattlerSide(gActiveBattler)].spikesAmount) * 2;
        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / (spikesDmg);
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gSideStatuses[GetBattlerSide(gActiveBattler)] |= SIDE_STATUS_SPIKES_DAMAGED;
        SetDmgHazardsBattlescript(gActiveBattler, 0);
    }
    else if (!(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_STEALTH_ROCK_DAMAGED)
        && (gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_STEALTH_ROCK))
    {
        gSideStatuses[GetBattlerSide(gActiveBattler)] |= SIDE_STATUS_STEALTH_ROCK_DAMAGED;
        gBattleMoveDamage = GetStealthHazardDamage(gBattleMoves[MOVE_STEALTH_ROCK].type, gActiveBattler);

        if (gBattleMoveDamage != 0)
            SetDmgHazardsBattlescript(gActiveBattler, 1);
    }
    else if (!(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_TOXIC_SPIKES_DAMAGED)
        && (gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_TOXIC_SPIKES)
        && IsBattlerGrounded(gActiveBattler))
    {
        gSideStatuses[GetBattlerSide(gActiveBattler)] |= SIDE_STATUS_TOXIC_SPIKES_DAMAGED;
        if (IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_POISON)) // Absorb the toxic spikes.
        {
            gSideStatuses[GetBattlerSide(gActiveBattler)] &= ~(SIDE_STATUS_TOXIC_SPIKES);
            gSideTimers[GetBattlerSide(gActiveBattler)].toxicSpikesAmount = 0;
            gBattleScripting.battler = gActiveBattler;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_ToxicSpikesAbsorbed;
        }
        else
        {
            if (!(gBattleMons[gActiveBattler].status1 & STATUS1_ANY)
                && !IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_STEEL)
                && GetBattlerAbility(gActiveBattler) != ABILITY_IMMUNITY
                && !(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_SAFEGUARD))
            {
                if (gSideTimers[GetBattlerSide(gActiveBattler)].toxicSpikesAmount >= 2)
                    gBattleMons[gActiveBattler].status1 |= STATUS1_TOXIC_POISON;
                else
                    gBattleMons[gActiveBattler].status1 |= STATUS1_POISON;

                BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                MarkBattlerForControllerExec(gActiveBattler);
                gBattleScripting.battler = gActiveBattler;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_ToxicSpikesPoisoned;
            }
        }
    }
    else if (!(gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_STICKY_WEB_DAMAGED)
        && (gSideStatuses[GetBattlerSide(gActiveBattler)] & SIDE_STATUS_STICKY_WEB)
        && IsBattlerGrounded(gActiveBattler))
    {
        gSideStatuses[GetBattlerSide(gActiveBattler)] |= SIDE_STATUS_STICKY_WEB_DAMAGED;
        gBattleScripting.battler = gActiveBattler;
        SET_STATCHANGER(STAT_SPEED, 1, TRUE);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_StickyWebOnSwitchIn;
    }
    else
    {
        // There is a hack here to ensure the truant counter will be 0 when the battler's next turn starts.
        // The truant counter is not updated in the case where a mon switches in after a lost judgement in the battle arena.
        if (gBattleMons[gActiveBattler].ability == ABILITY_TRUANT && !gDisableStructs[gActiveBattler].truantSwitchInHack)
            gDisableStructs[gActiveBattler].truantCounter = 1;

        gDisableStructs[gActiveBattler].truantSwitchInHack = 0;

        if (!AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, gActiveBattler, 0, 0, 0)
            && !ItemBattleEffects(ITEMEFFECT_ON_SWITCH_IN, gActiveBattler, FALSE))
        {
            gSideStatuses[GetBattlerSide(gActiveBattler)] &= ~(SIDE_STATUS_SPIKES_DAMAGED | SIDE_STATUS_TOXIC_SPIKES_DAMAGED | SIDE_STATUS_STEALTH_ROCK_DAMAGED | SIDE_STATUS_STICKY_WEB_DAMAGED);

            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattlerByTurnOrder[i] == gActiveBattler)
                    gActionsByTurnOrder[i] = B_ACTION_CANCEL_PARTNER;
            }

            for (i = 0; i < gBattlersCount; i++)
            {
                u16* hpOnSwitchout = &gBattleStruct->hpOnSwitchout[GetBattlerSide(i)];
                *hpOnSwitchout = gBattleMons[i].hp;
            }

            if (gBattlescriptCurrInstr[1] == 5)
            {
                u32 hitmarkerFaintBits = gHitMarker >> 0x1C;

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
            gBattlescriptCurrInstr += 2;
        }
    }
}

static void atk53_trainerslidein(void)
{
    gActiveBattler = GetBattlerAtPosition(gBattlescriptCurrInstr[1]);
    BtlController_EmitTrainerSlide(0);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 2;
}

static void atk54_playse(void)
{
    gActiveBattler = gBattlerAttacker;
    BtlController_EmitPlaySE(0, T2_READ_16(gBattlescriptCurrInstr + 1));
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 3;
}

static void atk55_fanfare(void)
{
    gActiveBattler = gBattlerAttacker;
    BtlController_EmitPlayFanfareOrBGM(0, T2_READ_16(gBattlescriptCurrInstr + 1), FALSE);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 3;
}

static void atk56_playfaintcry(void)
{
    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    BtlController_EmitFaintingCry(0);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 2;
}

static void atk57(void)
{
    gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
    BtlController_EmitCmd55(0, gBattleOutcome);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 1;
}

static void atk58_returntoball(void)
{
    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    BtlController_EmitReturnMonToBall(0, 1);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 2;
}

static void atk59_handlelearnnewmove(void)
{
    const u8 *jumpPtr1 = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    const u8 *jumpPtr2 = T1_READ_PTR(gBattlescriptCurrInstr + 5);

    u16 ret = MonTryLearningNewMove(&gPlayerParty[gBattleStruct->expGetterMonId], gBattlescriptCurrInstr[9]);
    while (ret == 0xFFFE)
        ret = MonTryLearningNewMove(&gPlayerParty[gBattleStruct->expGetterMonId], 0);

    if (ret == 0)
    {
        gBattlescriptCurrInstr = jumpPtr2;
    }
    else if (ret == 0xFFFF)
    {
        gBattlescriptCurrInstr += 10;
    }
    else
    {
        gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);

        if (gBattlerPartyIndexes[gActiveBattler] == gBattleStruct->expGetterMonId
            && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
        {
            GiveMoveToBattleMon(&gBattleMons[gActiveBattler], ret);
        }
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            gActiveBattler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            if (gBattlerPartyIndexes[gActiveBattler] == gBattleStruct->expGetterMonId
                && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
            {
                GiveMoveToBattleMon(&gBattleMons[gActiveBattler], ret);
            }
        }

        gBattlescriptCurrInstr = jumpPtr1;
    }
}

static void atk5A_yesnoboxlearnmove(void)
{
    gActiveBattler = 0;

    switch (gBattleScripting.learnMoveState)
    {
    case 0:
        HandleBattleWindow(0x18, 8, 0x1D, 0xD, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, 0xC);
        gBattleScripting.learnMoveState++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateYesNoCursorAt(0);
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateYesNoCursorAt(0);
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
        }
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[1] == 0)
            {
                HandleBattleWindow(0x18, 0x8, 0x1D, 0xD, WINDOW_CLEAR);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
                gBattleScripting.learnMoveState++;
            }
            else
            {
                gBattleScripting.learnMoveState = 5;
            }
        }
        else if (gMain.newKeys & B_BUTTON)
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
            u8 movePosition = sub_81C1B94();
            if (movePosition == 4)
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
                    gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);

                    PREPARE_MOVE_BUFFER(gBattleTextBuff2, moveId)

                    RemoveMonPPBonus(&gPlayerParty[gBattleStruct->expGetterMonId], movePosition);
                    SetMonMoveSlot(&gPlayerParty[gBattleStruct->expGetterMonId], gMoveToLearn, movePosition);

                    if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterMonId
                        && !(gBattleMons[0].status2 & STATUS2_TRANSFORMED)
                        && !(gDisableStructs[0].mimickedMoves & gBitTable[movePosition]))
                    {
                        RemoveBattleMonPPBonus(&gBattleMons[0], movePosition);
                        SetBattleMonMoveSlot(&gBattleMons[0], gMoveToLearn, movePosition);
                    }
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                        && gBattlerPartyIndexes[2] == gBattleStruct->expGetterMonId
                        && !(gBattleMons[2].status2 & STATUS2_TRANSFORMED)
                        && !(gDisableStructs[2].mimickedMoves & gBitTable[movePosition]))
                    {
                        RemoveBattleMonPPBonus(&gBattleMons[2], movePosition);
                        SetBattleMonMoveSlot(&gBattleMons[2], gMoveToLearn, movePosition);
                    }
                }
            }
        }
        break;
    case 5:
        HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
        gBattlescriptCurrInstr += 5;
        break;
    case 6:
        if (gBattleControllerExecFlags == 0)
        {
            gBattleScripting.learnMoveState = 2;
        }
        break;
    }
}

static void atk5B_yesnoboxstoplearningmove(void)
{
    switch (gBattleScripting.learnMoveState)
    {
    case 0:
        HandleBattleWindow(0x18, 8, 0x1D, 0xD, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, 0xC);
        gBattleScripting.learnMoveState++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateYesNoCursorAt(0);
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateYesNoCursorAt(0);
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
        }
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);

            if (gBattleCommunication[1] != 0)
                gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
            else
                gBattlescriptCurrInstr += 5;

            HandleBattleWindow(0x18, 0x8, 0x1D, 0xD, WINDOW_CLEAR);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
            HandleBattleWindow(0x18, 0x8, 0x1D, 0xD, WINDOW_CLEAR);
        }
        break;
    }
}

static void atk5C_hitanimation(void)
{
    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        gBattlescriptCurrInstr += 2;
    }
    else if (!(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE) || !(DoesSubstituteBlockMove(gBattlerAttacker, gActiveBattler, gCurrentMove)) || gDisableStructs[gActiveBattler].substituteHP == 0)
    {
        BtlController_EmitHitAnimation(0);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 2;
    }
    else
    {
        gBattlescriptCurrInstr += 2;
    }
}

static u32 GetTrainerMoneyToGive(u16 trainerId)
{
    u32 i = 0;
    u32 lastMonLevel = 0;
    u32 moneyReward = 0;

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

static void atk5D_getmoneyreward(void)
{
    u32 moneyReward = GetTrainerMoneyToGive(gTrainerBattleOpponent_A);
    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        moneyReward += GetTrainerMoneyToGive(gTrainerBattleOpponent_B);

    AddMoney(&gSaveBlock1Ptr->money, moneyReward);
    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff1, 5, moneyReward);

    gBattlescriptCurrInstr++;
}

static void atk5E(void)
{
    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    switch (gBattleCommunication[0])
    {
    case 0:
        BtlController_EmitGetMonData(0, REQUEST_ALL_BATTLE, 0);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattleCommunication[0]++;
        break;
    case 1:
         if (gBattleControllerExecFlags == 0)
         {
            s32 i;
            struct BattlePokemon *bufferPoke = (struct BattlePokemon*) &gBattleResources->bufferB[gActiveBattler][4];
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                gBattleMons[gActiveBattler].moves[i] = bufferPoke->moves[i];
                gBattleMons[gActiveBattler].pp[i] = bufferPoke->pp[i];
            }
            gBattlescriptCurrInstr += 2;
         }
         break;
    }
}

static void atk5F_swapattackerwithtarget(void)
{
    gActiveBattler = gBattlerAttacker;
    gBattlerAttacker = gBattlerTarget;
    gBattlerTarget = gActiveBattler;

    if (gHitMarker & HITMARKER_SWAP_ATTACKER_TARGET)
        gHitMarker &= ~(HITMARKER_SWAP_ATTACKER_TARGET);
    else
        gHitMarker |= HITMARKER_SWAP_ATTACKER_TARGET;

    gBattlescriptCurrInstr++;
}

static void atk60_incrementgamestat(void)
{
    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        IncrementGameStat(gBattlescriptCurrInstr[1]);

    gBattlescriptCurrInstr += 2;
}

static void atk61_drawpartystatussummary(void)
{
    s32 i;
    struct Pokemon *party;
    struct HpAndStatus hpStatuses[PARTY_SIZE];

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_NONE
            || GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
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

    BtlController_EmitDrawPartyStatusSummary(0, hpStatuses, 1);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 2;
}

static void atk62_hidepartystatussummary(void)
{
    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    BtlController_EmitHidePartyStatusSummary(0);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 2;
}

static void atk63_jumptocalledmove(void)
{
    if (gBattlescriptCurrInstr[1])
        gCurrentMove = gCalledMove;
    else
        gChosenMove = gCurrentMove = gCalledMove;

    gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
}

static void atk64_statusanimation(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
        if (!(gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[gActiveBattler].substituteHP == 0
            && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            BtlController_EmitStatusAnimation(0, FALSE, gBattleMons[gActiveBattler].status1);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        gBattlescriptCurrInstr += 2;
    }
}

static void atk65_status2animation(void)
{
    u32 wantedToAnimate;

    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
        wantedToAnimate = T1_READ_32(gBattlescriptCurrInstr + 2);
        if (!(gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[gActiveBattler].substituteHP == 0
            && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            BtlController_EmitStatusAnimation(0, TRUE, gBattleMons[gActiveBattler].status2 & wantedToAnimate);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        gBattlescriptCurrInstr += 6;
    }
}

static void atk66_chosenstatusanimation(void)
{
    u32 wantedStatus;

    if (gBattleControllerExecFlags == 0)
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
        wantedStatus = T1_READ_32(gBattlescriptCurrInstr + 3);
        if (!(gStatuses3[gActiveBattler] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[gActiveBattler].substituteHP == 0
            && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            BtlController_EmitStatusAnimation(0, gBattlescriptCurrInstr[2], wantedStatus);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        gBattlescriptCurrInstr += 7;
    }
}

static void atk67_yesnobox(void)
{
    switch (gBattleCommunication[0])
    {
    case 0:
        HandleBattleWindow(0x18, 8, 0x1D, 0xD, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, 0xC);
        gBattleCommunication[0]++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateYesNoCursorAt(0);
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateYesNoCursorAt(0);
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
        }
        if (gMain.newKeys & B_BUTTON)
        {
            gBattleCommunication[CURSOR_POSITION] = 1;
            PlaySE(SE_SELECT);
            HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
            gBattlescriptCurrInstr++;
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            HandleBattleWindow(0x18, 8, 0x1D, 0xD, WINDOW_CLEAR);
            gBattlescriptCurrInstr++;
        }
        break;
    }
}

static void atk68_cancelallactions(void)
{
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
        gActionsByTurnOrder[i] = B_ACTION_CANCEL_PARTNER;

    gBattlescriptCurrInstr++;
}

static void atk69_setgravity(void)
{
    if (gFieldStatuses & STATUS_FIELD_GRAVITY)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        u32 i;

        gFieldStatuses |= STATUS_FIELD_GRAVITY;
        gFieldTimers.gravityTimer = 5;
        gBattlescriptCurrInstr += 5;
    }
}

static void atk6A_removeitem(void)
{
    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    // Popped Air Balloon cannot be restored by no means.
    if (GetBattlerHoldEffect(gActiveBattler, TRUE) != HOLD_EFFECT_AIR_BALLOON)
        gBattleStruct->usedHeldItems[gActiveBattler] = gBattleMons[gActiveBattler].item;

    gBattleMons[gActiveBattler].item = 0;

    BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gActiveBattler].item);
    MarkBattlerForControllerExec(gActiveBattler);

    ClearBattlerItemEffectHistory(gActiveBattler);

    gBattlescriptCurrInstr += 2;
}

static void atk6B_atknameinbuff1(void)
{
    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker]);

    gBattlescriptCurrInstr++;
}

static void atk6C_drawlvlupbox(void)
{
    if (gBattleScripting.atk6C_state == 0)
    {
        if (IsMonGettingExpSentOut())
            gBattleScripting.atk6C_state = 3;
        else
            gBattleScripting.atk6C_state = 1;
    }

    switch (gBattleScripting.atk6C_state)
    {
    case 1:
        gBattle_BG2_Y = 0x60;
        SetBgAttribute(2, BG_ATTR_PRIORITY, 0);
        ShowBg(2);
        sub_804F17C();
        gBattleScripting.atk6C_state = 2;
        break;
    case 2:
        if (!sub_804F1CC())
            gBattleScripting.atk6C_state = 3;
        break;
    case 3:
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0x100;
        SetBgAttribute(0, BG_ATTR_PRIORITY, 1);
        SetBgAttribute(1, BG_ATTR_PRIORITY, 0);
        ShowBg(0);
        ShowBg(1);
        HandleBattleWindow(0x12, 7, 0x1D, 0x13, WINDOW_x80);
        gBattleScripting.atk6C_state = 4;
        break;
    case 4:
        DrawLevelUpWindow1();
        PutWindowTilemap(13);
        CopyWindowToVram(13, 3);
        gBattleScripting.atk6C_state++;
        break;
    case 5:
    case 7:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            gBattle_BG1_Y = 0;
            gBattleScripting.atk6C_state++;
        }
        break;
    case 6:
        if (gMain.newKeys != 0)
        {
            PlaySE(SE_SELECT);
            DrawLevelUpWindow2();
            CopyWindowToVram(13, 2);
            gBattleScripting.atk6C_state++;
        }
        break;
    case 8:
        if (gMain.newKeys != 0)
        {
            PlaySE(SE_SELECT);
            HandleBattleWindow(0x12, 7, 0x1D, 0x13, WINDOW_x80 | WINDOW_CLEAR);
            gBattleScripting.atk6C_state++;
        }
        break;
    case 9:
        if (!sub_804F344())
        {
            ClearWindowTilemap(14);
            CopyWindowToVram(14, 1);

            ClearWindowTilemap(13);
            CopyWindowToVram(13, 1);

            SetBgAttribute(2, BG_ATTR_PRIORITY, 2);
            ShowBg(2);

            gBattleScripting.atk6C_state = 10;
        }
        break;
    case 10:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetBgAttribute(0, BG_ATTR_PRIORITY, 0);
            SetBgAttribute(1, BG_ATTR_PRIORITY, 1);
            ShowBg(0);
            ShowBg(1);
            gBattlescriptCurrInstr++;
        }
        break;
    }
}

static void DrawLevelUpWindow1(void)
{
    u16 currStats[NUM_STATS];

    GetMonLevelUpWindowStats(&gPlayerParty[gBattleStruct->expGetterMonId], currStats);
    DrawLevelUpWindowPg1(0xD, gBattleResources->beforeLvlUp->stats, currStats, 0xE, 0xD, 0xF);
}

static void DrawLevelUpWindow2(void)
{
    u16 currStats[NUM_STATS];

    GetMonLevelUpWindowStats(&gPlayerParty[gBattleStruct->expGetterMonId], currStats);
    DrawLevelUpWindowPg2(0xD, currStats, 0xE, 0xD, 0xF);
}

static void sub_804F17C(void)
{
    gBattle_BG2_Y = 0;
    gBattle_BG2_X = 0x1A0;

    LoadPalette(sUnknown_0831C2C8, 0x60, 0x20);
    CopyToWindowPixelBuffer(14, sUnknown_0831C2E8, 0, 0);
    PutWindowTilemap(14);
    CopyWindowToVram(14, 3);

    PutMonIconOnLvlUpBox();
}

static bool8 sub_804F1CC(void)
{
    if (IsDma3ManagerBusyWithBgCopy())
        return TRUE;

    if (gBattle_BG2_X == 0x200)
        return FALSE;

    if (gBattle_BG2_X == 0x1A0)
        PutLevelAndGenderOnLvlUpBox();

    gBattle_BG2_X += 8;
    if (gBattle_BG2_X >= 0x200)
        gBattle_BG2_X = 0x200;

    return (gBattle_BG2_X != 0x200);
}

static void PutLevelAndGenderOnLvlUpBox(void)
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
    printerTemplate.windowId = 14;
    printerTemplate.fontId = 0;
    printerTemplate.x = 32;
    printerTemplate.y = 0;
    printerTemplate.currentX = 32;
    printerTemplate.currentY = 0;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = TEXT_COLOR_WHITE;
    printerTemplate.bgColor = TEXT_COLOR_TRANSPARENT;
    printerTemplate.shadowColor = TEXT_COLOR_DARK_GREY;

    AddTextPrinter(&printerTemplate, 0xFF, NULL);

    txtPtr = gStringVar4;
    gStringVar4[0] = CHAR_SPECIAL_F9;
    txtPtr++;
    txtPtr[0] = 5;
    txtPtr++;

    var = (u32)(txtPtr);
    txtPtr = ConvertIntToDecimalStringN(txtPtr, monLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
    var = (u32)(txtPtr) - var;
    txtPtr = StringFill(txtPtr, 0x77, 4 - var);

    if (monGender != MON_GENDERLESS)
    {
        if (monGender == MON_MALE)
        {
            txtPtr = WriteColorChangeControlCode(txtPtr, 0, 0xC);
            txtPtr = WriteColorChangeControlCode(txtPtr, 1, 0xD);
            *(txtPtr++) = CHAR_MALE;
        }
        else
        {
            txtPtr = WriteColorChangeControlCode(txtPtr, 0, 0xE);
            txtPtr = WriteColorChangeControlCode(txtPtr, 1, 0xF);
            *(txtPtr++) = CHAR_FEMALE;
        }
        *(txtPtr++) = EOS;
    }

    printerTemplate.y = 10;
    printerTemplate.currentY = 10;
    AddTextPrinter(&printerTemplate, 0xFF, NULL);

    CopyWindowToVram(14, 2);
}

static bool8 sub_804F344(void)
{
    if (gBattle_BG2_X == 0x1A0)
        return FALSE;

    if (gBattle_BG2_X - 16 < 0x1A0)
        gBattle_BG2_X = 0x1A0;
    else
        gBattle_BG2_X -= 16;

    return (gBattle_BG2_X != 0x1A0);
}

#define sDestroy                    data[0]
#define sSavedLvlUpBoxXPosition     data[1]

static void PutMonIconOnLvlUpBox(void)
{
    u8 spriteId;
    const u16* iconPal;
    struct SpriteSheet iconSheet;
    struct SpritePalette iconPalSheet;

    u16 species = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_SPECIES);
    u32 personality = GetMonData(&gPlayerParty[gBattleStruct->expGetterMonId], MON_DATA_PERSONALITY);

    const u8* iconPtr = GetMonIconPtr(species, personality, 1);
    iconSheet.data = iconPtr;
    iconSheet.size = 0x200;
    iconSheet.tag = MON_ICON_LVLUP_BOX_TAG;

    iconPal = GetValidMonIconPalettePtr(species);
    iconPalSheet.data = iconPal;
    iconPalSheet.tag = MON_ICON_LVLUP_BOX_TAG;

    LoadSpriteSheet(&iconSheet);
    LoadSpritePalette(&iconPalSheet);

    spriteId = CreateSprite(&sSpriteTemplate_MonIconOnLvlUpBox, 256, 10, 0);
    gSprites[spriteId].sDestroy = FALSE;
    gSprites[spriteId].sSavedLvlUpBoxXPosition = gBattle_BG2_X;
}

static void SpriteCB_MonIconOnLvlUpBox(struct Sprite* sprite)
{
    sprite->pos2.x = sprite->sSavedLvlUpBoxXPosition - gBattle_BG2_X;

    if (sprite->pos2.x != 0)
    {
        sprite->sDestroy = TRUE;
    }
    else if (sprite->sDestroy)
    {
        DestroySprite(sprite);
        FreeSpriteTilesByTag(MON_ICON_LVLUP_BOX_TAG);
        FreeSpritePaletteByTag(MON_ICON_LVLUP_BOX_TAG);
    }
}

#undef sDestroy
#undef sSavedLvlUpBoxXPosition

static bool32 IsMonGettingExpSentOut(void)
{
    if (gBattlerPartyIndexes[0] == gBattleStruct->expGetterMonId)
        return TRUE;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && gBattlerPartyIndexes[2] == gBattleStruct->expGetterMonId)
        return TRUE;

    return FALSE;
}

static void atk6D_resetsentmonsvalue(void)
{
    ResetSentPokesToOpponentValue();
    gBattlescriptCurrInstr++;
}

static void atk6E_setatktoplayer0(void)
{
    gBattlerAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
    gBattlescriptCurrInstr++;
}

static void atk6F_makevisible(void)
{
    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    BtlController_EmitSpriteInvisibility(0, FALSE);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 2;
}

static void atk70_recordability(void)
{
    u8 battler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
    RecordAbilityBattle(battler, gBattleMons[battler].ability);
    gBattlescriptCurrInstr += 2;
}

void BufferMoveToLearnIntoBattleTextBuff2(void)
{
    PREPARE_MOVE_BUFFER(gBattleTextBuff2, gMoveToLearn);
}

static void atk71_buffermovetolearn(void)
{
    BufferMoveToLearnIntoBattleTextBuff2();
    gBattlescriptCurrInstr++;
}

static void atk72_jumpifplayerran(void)
{
    if (TryRunFromBattle(gBattlerFainted))
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atk73_hpthresholds(void)
{
    u8 opposingBank;
    s32 result;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
        opposingBank = gActiveBattler ^ BIT_SIDE;

        result = gBattleMons[opposingBank].hp * 100 / gBattleMons[opposingBank].maxHP;
        if (result == 0)
            result = 1;

        if (result > 69 || !gBattleMons[opposingBank].hp)
            gBattleStruct->hpScale = 0;
        else if (result > 39)
            gBattleStruct->hpScale = 1;
        else if (result > 9)
            gBattleStruct->hpScale = 2;
        else
            gBattleStruct->hpScale = 3;
    }

    gBattlescriptCurrInstr += 2;
}

static void atk74_hpthresholds2(void)
{
    u8 opposingBank;
    s32 result;
    u8 hpSwitchout;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
        opposingBank = gActiveBattler ^ BIT_SIDE;
        hpSwitchout = *(gBattleStruct->hpOnSwitchout + GetBattlerSide(opposingBank));
        result = (hpSwitchout - gBattleMons[opposingBank].hp) * 100 / hpSwitchout;

        if (gBattleMons[opposingBank].hp >= hpSwitchout)
            gBattleStruct->hpScale = 0;
        else if (result <= 29)
            gBattleStruct->hpScale = 1;
        else if (result <= 69)
            gBattleStruct->hpScale = 2;
        else
            gBattleStruct->hpScale = 3;
    }

    gBattlescriptCurrInstr += 2;
}

static void atk75_useitemonopponent(void)
{
    gBattlerInMenuId = gBattlerAttacker;
    PokemonUseItemEffects(&gEnemyParty[gBattlerPartyIndexes[gBattlerAttacker]], gLastUsedItem, gBattlerPartyIndexes[gBattlerAttacker], 0, 1);
    gBattlescriptCurrInstr += 1;
}

static bool32 HasAttackerFaintedTarget(void)
{
    if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        && gBattleMoves[gCurrentMove].power != 0
        && (gLastHitBy[gBattlerTarget] == 0xFF || gLastHitBy[gBattlerTarget] == gBattlerAttacker)
        && gBattleStruct->moveTarget[gBattlerAttacker] == gBattlerTarget
        && gBattlerTarget != gBattlerAttacker
        && gCurrentTurnActionNumber == GetBattlerTurnOrderNum(gBattlerAttacker)
        && gChosenMove == gChosenMoveByBattler[gBattlerAttacker])
        return TRUE;
    else
        return FALSE;
}

static void HandleTerrainMove(u32 moveEffect)
{
    u32 statusFlag = 0;
    u8 *timer = NULL;

    switch (moveEffect)
    {
    case EFFECT_MISTY_TERRAIN:
        statusFlag = STATUS_FIELD_MISTY_TERRAIN, timer = &gFieldTimers.mistyTerrainTimer;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        break;
    case EFFECT_GRASSY_TERRAIN:
        statusFlag = STATUS_FIELD_GRASSY_TERRAIN, timer = &gFieldTimers.grassyTerrainTimer;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        break;
    case EFFECT_ELECTRIC_TERRAIN:
        statusFlag = STATUS_FIELD_ELECTRIC_TERRAIN, timer = &gFieldTimers.electricTerrainTimer;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        break;
    case EFFECT_PSYCHIC_TERRAIN:
        statusFlag = STATUS_FIELD_PSYCHIC_TERRAIN, timer = &gFieldTimers.psychicTerrainTimer;
        gBattleCommunication[MULTISTRING_CHOOSER] = 3;
        break;
    }

    if (gFieldStatuses & statusFlag || statusFlag == 0)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
    }
    else
    {
        gFieldStatuses &= ~(STATUS_FIELD_MISTY_TERRAIN | STATUS_FIELD_GRASSY_TERRAIN | STATUS_FIELD_ELECTRIC_TERRAIN | STATUS_FIELD_PSYCHIC_TERRAIN);
        gFieldStatuses |= statusFlag;
        if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_TERRAIN_EXTENDER)
            *timer = 8;
        else
            *timer = 5;
        gBattlescriptCurrInstr += 7;
    }
}

bool32 CanUseLastResort(u8 battlerId)
{
    u32 i;
    u32 knownMovesCount = 0, usedMovesCount = 0;

    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[battlerId].moves[i] != MOVE_NONE)
            knownMovesCount++;
        if (gDisableStructs[battlerId].usedMoves & gBitTable[i])
            usedMovesCount++;
    }

    if (knownMovesCount >= 2 && usedMovesCount >= knownMovesCount - 1)
        return TRUE;
    else
        return FALSE;
}

#define DEFOG_CLEAR(status, structField, battlescript, move)\
{                                                           \
    if (*sideStatuses & status)                             \
    {                                                       \
        if (clear)                                          \
        {                                                   \
            if (move)                                       \
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, move);\
            *sideStatuses &= ~(status);                     \
            sideTimer->structField = 0;                     \
            BattleScriptPushCursor();                       \
            gBattlescriptCurrInstr = battlescript;          \
        }                                                   \
        return TRUE;                                        \
    }                                                       \
}

static bool32 ClearDefogHazards(u8 battlerAtk, bool32 clear)
{
    s32 i;
    for (i = 0; i < 2; i++)
    {
        struct SideTimer *sideTimer = &gSideTimers[i];
        u32 *sideStatuses = &gSideStatuses[i];

        gBattlerAttacker = i;
        if (GetBattlerSide(battlerAtk) != i)
        {
            DEFOG_CLEAR(SIDE_STATUS_REFLECT, reflectTimer, BattleScript_SideStatusWoreOffReturn, MOVE_REFLECT);
            DEFOG_CLEAR(SIDE_STATUS_LIGHTSCREEN, lightscreenTimer, BattleScript_SideStatusWoreOffReturn, MOVE_LIGHT_SCREEN);
            DEFOG_CLEAR(SIDE_STATUS_MIST, mistTimer, BattleScript_SideStatusWoreOffReturn, MOVE_MIST);
            DEFOG_CLEAR(SIDE_STATUS_AURORA_VEIL, auroraVeilTimer, BattleScript_SideStatusWoreOffReturn, MOVE_AURORA_VEIL);
            DEFOG_CLEAR(SIDE_STATUS_SAFEGUARD, safeguardTimer, BattleScript_SideStatusWoreOffReturn, MOVE_SAFEGUARD);
        }
        DEFOG_CLEAR(SIDE_STATUS_SPIKES, spikesAmount, BattleScript_SpikesFree, 0);
        DEFOG_CLEAR(SIDE_STATUS_STEALTH_ROCK, stealthRockAmount, BattleScript_StealthRockFree, 0);
        DEFOG_CLEAR(SIDE_STATUS_TOXIC_SPIKES, toxicSpikesAmount, BattleScript_ToxicSpikesFree, 0);
        DEFOG_CLEAR(SIDE_STATUS_STICKY_WEB, stickyWebAmount, BattleScript_StickyWebFree, 0);
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

static void atk76_various(void)
{
    struct Pokemon *mon;
    u8 side;
    s32 i, j;
    u8 data[10];
    u32 bits;

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    switch (gBattlescriptCurrInstr[2])
    {
    // Roar will fail in a double wild battle when used by the player against one of the two alive wild mons.
    // Also when an opposing wild mon uses it againt its partner.
    case VARIOUS_JUMP_IF_ROAR_FAILS:
        if (WILD_DOUBLE_BATTLE
            && GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER
            && GetBattlerSide(gBattlerTarget) == B_SIDE_OPPONENT
            && IS_WHOLE_SIDE_ALIVE(gBattlerTarget))
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        else if (WILD_DOUBLE_BATTLE
                 && GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT
                 && GetBattlerSide(gBattlerTarget) == B_SIDE_OPPONENT)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        else
            gBattlescriptCurrInstr += 7;
        return;
    case VARIOUS_CHECK_IF_GRASSY_TERRAIN_HEALS:
        if ((gStatuses3[gActiveBattler] & (STATUS3_SEMI_INVULNERABLE))
            || BATTLER_MAX_HP(gActiveBattler)
            || !gBattleMons[gActiveBattler].hp
            || !(IsBattlerGrounded(gActiveBattler)))
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = 1;
            gBattleMoveDamage *= -1;

            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_GRAVITY_ON_AIRBORNE_MONS:
        if (gStatuses3[gActiveBattler] & STATUS3_ON_AIR)
            CancelMultiTurnMoves(gActiveBattler);

        gStatuses3[gActiveBattler] &= ~(STATUS3_MAGNET_RISE | STATUS3_TELEKINESIS | STATUS3_ON_AIR);
        break;
    case VARIOUS_SPECTRAL_THIEF:
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
    case VARIOUS_SET_POWDER:
        gBattleMons[gActiveBattler].status2 |= STATUS2_POWDER;
        break;
    case VARIOUS_ACUPRESSURE:
        bits = 0;
        for (i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
        {
            if (gBattleMons[gActiveBattler].statStages[i] != 12)
                bits |= gBitTable[i];
        }
        if (bits)
        {
            u32 statId;
            do
            {
                statId = (Random() % NUM_BATTLE_STATS) + 1;
            } while (!(bits & gBitTable[statId]));

            if (gBattleMons[gActiveBattler].statStages[statId] >= 11)
                SET_STATCHANGER(statId, 1, FALSE);
            else
                SET_STATCHANGER(statId, 2, FALSE);

            gBattlescriptCurrInstr += 7;
        }
        else
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        return;
    case VARIOUS_CANCEL_MULTI_TURN_MOVES:
        CancelMultiTurnMoves(gActiveBattler);
        break;
    case VARIOUS_SET_MAGIC_COAT_TARGET:
        gBattlerAttacker = gBattlerTarget;
        side = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;
        if (gSideTimers[side].followmeTimer != 0 && gBattleMons[gSideTimers[side].followmeTarget].hp != 0)
            gBattlerTarget = gSideTimers[side].followmeTarget;
        else
            gBattlerTarget = gActiveBattler;
        break;
    case VARIOUS_IS_RUNNING_IMPOSSIBLE:
        gBattleCommunication[0] = IsRunningFromBattleImpossible();
        break;
    case VARIOUS_GET_MOVE_TARGET:
        gBattlerTarget = GetMoveTarget(gCurrentMove, 0);
        break;
    case 4:
        if (gHitMarker & HITMARKER_FAINTED(gActiveBattler))
            gBattleCommunication[0] = 1;
        else
            gBattleCommunication[0] = 0;
        break;
    case VARIOUS_RESET_INTIMIDATE_TRACE_BITS:
        gSpecialStatuses[gActiveBattler].intimidatedMon = 0;
        gSpecialStatuses[gActiveBattler].traced = 0;
        gSpecialStatuses[gActiveBattler].switchInAbilityDone = 0;
        break;
    case VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP:
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
                gBattleStruct->choicedMove[gActiveBattler] = 0;
        }
        break;
    case 7:
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_DOUBLE))
            && gBattleTypeFlags & BATTLE_TYPE_TRAINER
            && gBattleMons[0].hp != 0
            && gBattleMons[1].hp != 0)
        {
            gHitMarker &= ~(HITMARKER_x400000);
        }
        break;
    case 8:
        gBattleCommunication[0] = 0;
        gBattleScripting.battler = gActiveBattler = gBattleCommunication[1];
        if (!(gBattleStruct->field_92 & gBitTable[gActiveBattler])
            && gBattleMons[gActiveBattler].maxHP / 2 >= gBattleMons[gActiveBattler].hp
            && gBattleMons[gActiveBattler].hp != 0
            && !(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP))
        {
            gBattleStruct->field_92 |= gBitTable[gActiveBattler];
            gBattleCommunication[0] = 1;
            gBattleCommunication[MULTISTRING_CHOOSER] = sUnknown_0831C4F8[GetNatureFromPersonality(gBattleMons[gActiveBattler].personality)];
        }
        break;
    case VARIOUS_ARENA_JUDGMENT_WINDOW:
        i = BattleArena_ShowJudgmentWindow(&gBattleCommunication[0]);
        if (i == 0)
            return;

        gBattleCommunication[1] = i;
        break;
    case VARIOUS_ARENA_OPPONENT_MON_LOST:
        gBattleMons[1].hp = 0;
        gHitMarker |= HITMARKER_FAINTED(1);
        gBattleStruct->arenaLostOpponentMons |= gBitTable[gBattlerPartyIndexes[1]];
        gDisableStructs[1].truantSwitchInHack = 1;
        break;
    case VARIOUS_ARENA_PLAYER_MON_LOST:
        gBattleMons[0].hp = 0;
        gHitMarker |= HITMARKER_FAINTED(0);
        gHitMarker |= HITMARKER_x400000;
        gBattleStruct->arenaLostPlayerMons |= gBitTable[gBattlerPartyIndexes[0]];
        gDisableStructs[0].truantSwitchInHack = 1;
        break;
    case VARIOUS_ARENA_BOTH_MONS_LOST:
        gBattleMons[0].hp = 0;
        gBattleMons[1].hp = 0;
        gHitMarker |= HITMARKER_FAINTED(0);
        gHitMarker |= HITMARKER_FAINTED(1);
        gHitMarker |= HITMARKER_x400000;
        gBattleStruct->arenaLostPlayerMons |= gBitTable[gBattlerPartyIndexes[0]];
        gBattleStruct->arenaLostOpponentMons |= gBitTable[gBattlerPartyIndexes[1]];
        gDisableStructs[0].truantSwitchInHack = 1;
        gDisableStructs[1].truantSwitchInHack = 1;
        break;
    case VARIOUS_EMIT_YESNOBOX:
        BtlController_EmitUnknownYesNoBox(0);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    case 14:
        DrawArenaRefereeTextBox();
        break;
    case 15:
        RemoveArenaRefereeTextBox();
        break;
    case VARIOUS_ARENA_JUDGMENT_STRING:
        BattleStringExpandPlaceholdersToDisplayedString(gRefereeStringsTable[gBattlescriptCurrInstr[1]]);
        BattlePutTextOnWindow(gDisplayedStringBattle, 0x16);
        break;
    case VARIOUS_ARENA_WAIT_STRING:
        if (IsTextPrinterActive(0x16))
            return;
        break;
    case VARIOUS_WAIT_CRY:
        if (!IsCryFinished())
            return;
        break;
    case VARIOUS_RETURN_OPPONENT_MON1:
        gActiveBattler = 1;
        if (gBattleMons[gActiveBattler].hp != 0)
        {
            BtlController_EmitReturnMonToBall(0, 0);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        break;
    case VARIOUS_RETURN_OPPONENT_MON2:
        if (gBattlersCount > 3)
        {
            gActiveBattler = 3;
            if (gBattleMons[gActiveBattler].hp != 0)
            {
                BtlController_EmitReturnMonToBall(0, 0);
                MarkBattlerForControllerExec(gActiveBattler);
            }
        }
        break;
    case VARIOUS_VOLUME_DOWN:
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x55);
        break;
    case VARIOUS_VOLUME_UP:
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFFFF, 0x100);
        break;
    case VARIOUS_SET_ALREADY_STATUS_MOVE_ATTEMPT:
        gBattleStruct->alreadyStatusedMoveAttempt |= gBitTable[gActiveBattler];
        break;
    case 24:
        if (sub_805725C(gActiveBattler))
            return;
        break;
    case VARIOUS_SET_TELEPORT_OUTCOME:
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
    case VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC:
        BtlController_EmitPlayFanfareOrBGM(0, MUS_KACHI1, TRUE);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    case VARIOUS_STAT_TEXT_BUFFER:
        PREPARE_STAT_BUFFER(gBattleTextBuff1, gBattleCommunication[0]);
        break;
    case VARIOUS_SWITCHIN_ABILITIES:
        gBattlescriptCurrInstr += 3;
        AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, gActiveBattler, 0, 0, 0);
        return;
    case VARIOUS_SAVE_TARGET:
        gBattleStruct->savedBattlerTarget = gBattlerTarget;
        break;
    case VARIOUS_RESTORE_TARGET:
        gBattlerTarget = gBattleStruct->savedBattlerTarget;
        break;
    case VARIOUS_INSTANT_HP_DROP:
        BtlController_EmitHealthBarUpdate(0, INSTANT_HP_BAR_DROP);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    case VARIOUS_CLEAR_STATUS:
        gBattleMons[gActiveBattler].status1 = 0;
        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    case VARIOUS_RESTORE_PP:
        for (i = 0; i < 4; i++)
        {
            gBattleMons[gActiveBattler].pp[i] = CalculatePPWithBonus(gBattleMons[gActiveBattler].moves[i], gBattleMons[gActiveBattler].ppBonuses, i);
            data[i] = gBattleMons[gActiveBattler].pp[i];
        }
        data[i] = gBattleMons[gActiveBattler].ppBonuses;
        BtlController_EmitSetMonData(0, REQUEST_PP_DATA_BATTLE, 0, 5, data);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    case VARIOUS_TRY_ACTIVATE_MOXIE:
        if (GetBattlerAbility(gActiveBattler) == ABILITY_MOXIE
            && HasAttackerFaintedTarget()
            && !IsBattleLostForPlayer()
            && !IsBattleWonForPlayer()
            && gBattleMons[gBattlerAttacker].statStages[STAT_ATK] != 12)
        {
            gBattleMons[gBattlerAttacker].statStages[STAT_ATK]++;
            SET_STATCHANGER(STAT_ATK, 1, FALSE);
            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK);
            BattleScriptPush(gBattlescriptCurrInstr + 3);
            gBattlescriptCurrInstr = BattleScript_AttackerAbilityStatRaise;
            return;
        }
        break;
    case VARIOUS_TRY_ACTIVATE_FELL_STINGER:
        if (gBattleMoves[gCurrentMove].effect == EFFECT_FELL_STINGER
            && HasAttackerFaintedTarget()
            && !IsBattleLostForPlayer()
            && !IsBattleWonForPlayer()
            && gBattleMons[gBattlerAttacker].statStages[STAT_ATK] != 12)
        {
            if (gBattleMons[gBattlerAttacker].statStages[STAT_ATK] >= 11)
                SET_STATCHANGER(STAT_ATK, 1, FALSE);
            else if (gBattleMons[gBattlerAttacker].statStages[STAT_ATK] <= 9 && B_FELL_STINGER_STAT_RAISE == GEN_7)
                SET_STATCHANGER(STAT_ATK, 3, FALSE);
            else
                SET_STATCHANGER(STAT_ATK, 2, FALSE);

            PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK);
            BattleScriptPush(gBattlescriptCurrInstr + 3);
            gBattlescriptCurrInstr = BattleScript_FellStingerRaisesStat;
            return;
        }
        break;
    case VARIOUS_PLAY_MOVE_ANIMATION:
        BtlController_EmitMoveAnimation(0, T1_READ_16(gBattlescriptCurrInstr + 3), gBattleScripting.animTurn, 0, 0, gBattleMons[gActiveBattler].friendship, &gDisableStructs[gActiveBattler], gMultiHitCounter);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 5;
        return;
    case VARIOUS_SET_LUCKY_CHANT:
        if (!(gSideStatuses[GET_BATTLER_SIDE(gActiveBattler)] & SIDE_STATUS_LUCKY_CHANT))
        {
            gSideStatuses[GET_BATTLER_SIDE(gActiveBattler)] |= SIDE_STATUS_LUCKY_CHANT;
            gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].luckyChantBattlerId = gActiveBattler;
            gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].luckyChantTimer = 5;
            gBattlescriptCurrInstr += 7;
        }
        else
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        return;
    case VARIOUS_SUCKER_PUNCH_CHECK:
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        else if (gBattleMoves[gBattleMons[gBattlerTarget].moves[gBattleStruct->chosenMovePositions[gBattlerTarget]]].power == 0)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        else
            gBattlescriptCurrInstr += 7;
        return;
    case VARIOUS_SET_SIMPLE_BEAM:
        switch (gBattleMons[gActiveBattler].ability)
        {
        case ABILITY_SIMPLE:
        case ABILITY_TRUANT:
        case ABILITY_STANCE_CHANGE:
        case ABILITY_MULTITYPE:
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
            break;
        default:
            gBattleMons[gActiveBattler].ability = ABILITY_SIMPLE;
            gBattlescriptCurrInstr += 7;
            break;
        }
        return;
    case VARIOUS_TRY_ENTRAINMENT:
        switch (gBattleMons[gBattlerTarget].ability)
        {
        case ABILITY_TRUANT:
        case ABILITY_MULTITYPE:
        case ABILITY_STANCE_CHANGE:
        case ABILITY_SCHOOLING:
        case ABILITY_COMATOSE:
        case ABILITY_SHIELDS_DOWN:
        case ABILITY_DISGUISE:
        case ABILITY_RKS_SYSTEM:
        case ABILITY_BATTLE_BOND:
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
            return;
        }
        switch (gBattleMons[gBattlerAttacker].ability)
        {
        case ABILITY_TRACE:
        case ABILITY_FORECAST:
        case ABILITY_FLOWER_GIFT:
        case ABILITY_ZEN_MODE:
        case ABILITY_ILLUSION:
        case ABILITY_IMPOSTER:
        case ABILITY_POWER_OF_ALCHEMY:
        case ABILITY_RECEIVER:
        case ABILITY_DISGUISE:
        case ABILITY_POWER_CONSTRUCT:
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
            return;
        }
        if (gBattleMons[gBattlerTarget].ability == gBattleMons[gBattlerAttacker].ability)
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            gBattleMons[gBattlerTarget].ability = gBattleMons[gBattlerAttacker].ability;
            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_SET_LAST_USED_ABILITY:
        gLastUsedAbility = gBattleMons[gActiveBattler].ability;
        break;
    case VARIOUS_TRY_HEAL_PULSE:
        if (BATTLER_MAX_HP(gActiveBattler))
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            if (GetBattlerAbility(gBattlerAttacker) == ABILITY_MEGA_LAUNCHER && gBattleMoves[gCurrentMove].flags & FLAG_MEGA_LAUNCHER_BOOST)
                gBattleMoveDamage = -(gBattleMons[gActiveBattler].maxHP * 75 / 100);
            else
                gBattleMoveDamage = -(gBattleMons[gActiveBattler].maxHP / 2);

            if (gBattleMoveDamage == 0)
                gBattleMoveDamage = -1;
            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_TRY_QUASH:
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            for (i = 0; i < gBattlersCount; i++)
                data[i] = gBattlerByTurnOrder[i];
            for (i = 0; i < gBattlersCount; i++)
            {
                if (data[i] == gBattlerTarget)
                {
                    for (j = i + 1; j < gBattlersCount; j++)
                        data[i++] = data[j];
                }
                else
                {
                    gBattlerByTurnOrder[i] = data[i];
                }
            }
            gBattlerByTurnOrder[gBattlersCount - 1] = gBattlerTarget;
            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_INVERT_STAT_STAGES:
        for (i = 0; i < NUM_BATTLE_STATS; i++)
        {
            if (gBattleMons[gActiveBattler].statStages[i] < 6) // Negative becomes positive.
                gBattleMons[gActiveBattler].statStages[i] = 6 + (6 - gBattleMons[gActiveBattler].statStages[i]);
            else if (gBattleMons[gActiveBattler].statStages[i] > 6) // Positive becomes negative.
                gBattleMons[gActiveBattler].statStages[i] = 6 - (gBattleMons[gActiveBattler].statStages[i] - 6);
        }
        break;
    case VARIOUS_SET_TERRAIN:
        HandleTerrainMove(gBattleMoves[gCurrentMove].effect);
        return;
    case VARIOUS_TRY_ME_FIRST:
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        else if (gBattleMoves[gBattleMons[gBattlerTarget].moves[gBattleStruct->chosenMovePositions[gBattlerTarget]]].power == 0)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
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
                gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
                break;
            default:
                gCalledMove = move;
                gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
                gBattlerTarget = GetMoveTarget(gCalledMove, 0);
                gStatuses3[gBattlerAttacker] |= STATUS3_ME_FIRST;
                gBattlescriptCurrInstr += 7;
                break;
            }
        }
        return;
    case VARIOUS_JUMP_IF_BATTLE_END:
        if (IsBattleLostForPlayer() || IsBattleWonForPlayer())
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        else
            gBattlescriptCurrInstr += 7;
        return;
    case VARIOUS_TRY_ELECTRIFY:
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget))
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            gStatuses3[gBattlerTarget] |= STATUS3_ELECTRIFIED;
            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_TRY_REFLECT_TYPE:
        if (gBattleMons[gBattlerTarget].species == SPECIES_ARCEUS || gBattleMons[gBattlerTarget].species == SPECIES_SILVALLY)
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else if (gBattleMons[gBattlerTarget].type1 == TYPE_MYSTERY && gBattleMons[gBattlerTarget].type2 != TYPE_MYSTERY)
        {
            gBattleMons[gBattlerAttacker].type1 = gBattleMons[gBattlerTarget].type2;
            gBattleMons[gBattlerAttacker].type2 = gBattleMons[gBattlerTarget].type2;
            gBattlescriptCurrInstr += 7;
        }
        else if (gBattleMons[gBattlerTarget].type1 != TYPE_MYSTERY && gBattleMons[gBattlerTarget].type2 == TYPE_MYSTERY)
        {
            gBattleMons[gBattlerAttacker].type1 = gBattleMons[gBattlerTarget].type1;
            gBattleMons[gBattlerAttacker].type2 = gBattleMons[gBattlerTarget].type1;
            gBattlescriptCurrInstr += 7;
        }
        else if (gBattleMons[gBattlerTarget].type1 == TYPE_MYSTERY && gBattleMons[gBattlerTarget].type2 == TYPE_MYSTERY)
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            gBattleMons[gBattlerAttacker].type1 = gBattleMons[gBattlerTarget].type1;
            gBattleMons[gBattlerAttacker].type2 = gBattleMons[gBattlerTarget].type2;
            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_TRY_SOAK:
        if (gBattleMons[gBattlerTarget].type1 == TYPE_WATER && gBattleMons[gBattlerTarget].type2 == TYPE_WATER)
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            SET_BATTLER_TYPE(gBattlerTarget, TYPE_WATER);
            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_HANDLE_MEGA_EVO:
        if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT)
            mon = &gEnemyParty[gBattlerPartyIndexes[gActiveBattler]];
        else
            mon = &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]];

        // Change species.
        if (gBattlescriptCurrInstr[3] == 0)
        {
            gBattleStruct->mega.evolvedSpecies[gActiveBattler] = gBattleMons[gActiveBattler].species;
            if (GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_LEFT
                || (GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_RIGHT && !(gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))))
            {
                gBattleStruct->mega.playerEvolvedSpecies = gBattleStruct->mega.evolvedSpecies[gActiveBattler];
            }

            gBattleMons[gActiveBattler].species = GetMegaEvolutionSpecies(gBattleStruct->mega.evolvedSpecies[gActiveBattler], gBattleMons[gActiveBattler].item);
            PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gActiveBattler].species);

            BtlController_EmitSetMonData(0, REQUEST_SPECIES_BATTLE, gBitTable[gBattlerPartyIndexes[gActiveBattler]], 2, &gBattleMons[gActiveBattler].species);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        // Change stats.
        else if (gBattlescriptCurrInstr[3] == 1)
        {
            CalculateMonStats(mon);
            gBattleMons[gActiveBattler].level = GetMonData(mon, MON_DATA_LEVEL);
            gBattleMons[gActiveBattler].hp = GetMonData(mon, MON_DATA_HP);
            gBattleMons[gActiveBattler].maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            gBattleMons[gActiveBattler].attack = GetMonData(mon, MON_DATA_ATK);
            gBattleMons[gActiveBattler].defense = GetMonData(mon, MON_DATA_DEF);
            gBattleMons[gActiveBattler].speed = GetMonData(mon, MON_DATA_SPEED);
            gBattleMons[gActiveBattler].spAttack = GetMonData(mon, MON_DATA_SPATK);
            gBattleMons[gActiveBattler].spDefense = GetMonData(mon, MON_DATA_SPDEF);
            gBattleMons[gActiveBattler].ability = GetMonAbility(mon);
            gBattleMons[gActiveBattler].type1 = gBaseStats[gBattleMons[gActiveBattler].species].type1;
            gBattleMons[gActiveBattler].type2 = gBaseStats[gBattleMons[gActiveBattler].species].type2;

            gBattleStruct->mega.alreadyEvolved[GetBattlerPosition(gActiveBattler)] = TRUE;
            gBattleStruct->mega.evolvedPartyIds[GetBattlerSide(gActiveBattler)] |= gBitTable[gBattlerPartyIndexes[gActiveBattler]];
        }
        // Update healthbox.
        else
        {
            UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], mon, HEALTHBOX_ALL);
            CreateMegaIndicatorSprite(gActiveBattler, 0);
        }
        gBattlescriptCurrInstr += 4;
        return;
    case VARIOUS_TRY_LAST_RESORT:
        if (CanUseLastResort(gActiveBattler))
            gBattlescriptCurrInstr += 7;
        else
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        return;
    case VARIOUS_ARGUMENT_STATUS_EFFECT:
        switch (gBattleMoves[gCurrentMove].argument)
        {
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
        default:
            gBattleScripting.moveEffect = 0;
            break;
        }
        if (gBattleScripting.moveEffect != 0)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 3);
            gBattlescriptCurrInstr = BattleScript_EffectWithChance;
            return;
        }
        break;
    case VARIOUS_TRY_HIT_SWITCH_TARGET:
        if (IsBattlerAlive(gBattlerAttacker)
            && IsBattlerAlive(gBattlerTarget)
            && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
            && TARGET_TURN_DAMAGED)
        {
            gBattlescriptCurrInstr = BattleScript_ForceRandomSwitch;
        }
        else
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        return;
    case VARIOUS_TRY_AUTONOMIZE:
        if (GetBattlerWeight(gActiveBattler) > 1)
        {
            gDisableStructs[gActiveBattler].autonomizeCount++;
            gBattlescriptCurrInstr += 7;
        }
        else
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        return;
    case VARIOUS_TRY_COPYCAT:
        for (i = 0; sMovesForbiddenToCopy[i] != COPYCAT_FORBIDDEN_END; i++)
        {
            if (sMovesForbiddenToCopy[i] == gLastUsedMove)
                break;
        }
        if (gLastUsedMove == 0 || gLastUsedMove == 0xFFFF || sMovesForbiddenToCopy[i] != COPYCAT_FORBIDDEN_END)
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            gCalledMove = gLastUsedMove;
            gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
            gBattlerTarget = GetMoveTarget(gCalledMove, 0);
            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_TRY_INSTRUCT:
        for (i = 0; sMoveEffectsForbiddenToInstruct[i] != INSTRUCT_FORBIDDEN_END; i++)
        {
            if (sMoveEffectsForbiddenToInstruct[i] == gBattleMoves[gLastMoves[gBattlerTarget]].effect)
                break;
        }
        if (gLastMoves[gBattlerTarget] == 0 || gLastMoves[gBattlerTarget] == 0xFFFF || sMoveEffectsForbiddenToInstruct[i] != INSTRUCT_FORBIDDEN_END
            || gLastMoves[gBattlerTarget] == MOVE_STRUGGLE || gLastMoves[gBattlerTarget] == MOVE_KING_S_SHIELD)
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
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
                gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
            else
            {
                gBattlerTarget = gBattleStruct->lastMoveTarget[gBattlerAttacker];
                gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
                PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gActiveBattler, gBattlerPartyIndexes[gActiveBattler]);
                gBattlescriptCurrInstr += 7;
            }
        }
        return;
    case VARIOUS_ABILITY_POPUP:
        CreateAbilityPopUp(gActiveBattler, gBattleMons[gActiveBattler].ability, (gBattleTypeFlags & BATTLE_TYPE_DOUBLE) != 0);
        break;
    case VARIOUS_DEFOG:
        if (T1_READ_8(gBattlescriptCurrInstr + 3)) // Clear
        {
            if (ClearDefogHazards(gEffectBattler, TRUE))
                return;
            else
                gBattlescriptCurrInstr += 8;
        }
        else
        {
            if (ClearDefogHazards(gActiveBattler, FALSE))
                gBattlescriptCurrInstr += 8;
            else
                gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 4);
        }
        return;
    case VARIOUS_JUMP_IF_TARGET_ALLY:
        if (GetBattlerSide(gBattlerAttacker) != GetBattlerSide(gBattlerTarget))
            gBattlescriptCurrInstr += 7;
        else
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        return;
    case VARIOUS_TRY_SYNCHRONOISE:
        if (!DoBattlersShareType(gBattlerAttacker, gBattlerTarget))
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        else
            gBattlescriptCurrInstr += 7;
        return;
    case VARIOUS_PSYCHO_SHIFT:
        i = TRUE;
        if (gBattleMons[gBattlerAttacker].status1 & STATUS1_PARALYSIS)
        {
            if (GetBattlerAbility(gBattlerTarget) == ABILITY_LIMBER)
            {
                gBattlerAbility = gBattlerTarget;
                BattleScriptPush(T1_READ_PTR(gBattlescriptCurrInstr + 3));
                gBattlescriptCurrInstr = BattleScript_PRLZPrevention;
                i = FALSE;
            }
            else if (IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_ELECTRIC))
            {
                BattleScriptPush(T1_READ_PTR(gBattlescriptCurrInstr + 3));
                gBattlescriptCurrInstr = BattleScript_PRLZPrevention;
                i = FALSE;
            }
            else
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
            }
        }
        else if (gBattleMons[gBattlerAttacker].status1 & STATUS1_PSN_ANY)
        {
            if (GetBattlerAbility(gBattlerTarget) == ABILITY_IMMUNITY)
            {
                gBattlerAbility = gBattlerTarget;
                BattleScriptPush(T1_READ_PTR(gBattlescriptCurrInstr + 3));
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;
                i = FALSE;
            }
            else if (IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_POISON) || IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_STEEL))
            {
                BattleScriptPush(T1_READ_PTR(gBattlescriptCurrInstr + 3));
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;
                i = FALSE;
            }
            else
            {
                if (gBattleMons[gBattlerAttacker].status1 & STATUS1_POISON)
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            }
        }
        else if (gBattleMons[gBattlerAttacker].status1 & STATUS1_BURN)
        {
            if (GetBattlerAbility(gBattlerTarget) == ABILITY_WATER_VEIL)
            {
                gBattlerAbility = gBattlerTarget;
                BattleScriptPush(T1_READ_PTR(gBattlescriptCurrInstr + 3));
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;
                i = FALSE;
            }
            else if (IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_FIRE))
            {
                BattleScriptPush(T1_READ_PTR(gBattlescriptCurrInstr + 3));
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;
                i = FALSE;
            }
            else
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            }
        }
        else if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
        {
            if (GetBattlerAbility(gBattlerTarget) == ABILITY_INSOMNIA || GetBattlerAbility(gBattlerTarget) == ABILITY_VITAL_SPIRIT)
            {
                gBattlerAbility = gBattlerTarget;
                // BattleScriptPush(T1_READ_PTR(gBattlescriptCurrInstr + 3));
                // gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
                i = FALSE;
            }
            else
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = 4;
            }
        }

        if (i == TRUE)
        {
            gBattleMons[gBattlerTarget].status1 = gBattleMons[gBattlerAttacker].status1 & STATUS1_ANY;
            gActiveBattler = gBattlerTarget;
            BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
            MarkBattlerForControllerExec(gActiveBattler);
            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_CURE_STATUS:
        gBattleMons[gActiveBattler].status1 = 0;
        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    case VARIOUS_POWER_TRICK:
        gStatuses3[gActiveBattler] ^= STATUS3_POWER_TRICK;
        SWAP(gBattleMons[gActiveBattler].attack, gBattleMons[gActiveBattler].defense, i);
        break;
    case VARIOUS_AFTER_YOU:
        if (GetBattlerTurnOrderNum(gBattlerAttacker) > GetBattlerTurnOrderNum(gBattlerTarget)
            || GetBattlerTurnOrderNum(gBattlerAttacker) == GetBattlerTurnOrderNum(gBattlerTarget) + 1)
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
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
            else
            {
                gBattlerByTurnOrder[2] = gBattlerTarget;
                gBattlerByTurnOrder[3] = data[2];
            }
            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_BESTOW:
        if (gBattleMons[gBattlerAttacker].item == ITEM_NONE
            || gBattleMons[gBattlerTarget].item != ITEM_NONE
            || !CanBattlerGetOrLoseItem(gBattlerAttacker, gBattleMons[gBattlerAttacker].item)
            || !CanBattlerGetOrLoseItem(gBattlerTarget, gBattleMons[gBattlerAttacker].item))
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            gLastUsedItem = gBattleMons[gBattlerAttacker].item;

            gActiveBattler = gBattlerAttacker;
            gBattleMons[gActiveBattler].item = ITEM_NONE;
            BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gActiveBattler].item);
            MarkBattlerForControllerExec(gActiveBattler);

            gActiveBattler = gBattlerTarget;
            gBattleMons[gActiveBattler].item = gLastUsedItem;
            BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gActiveBattler].item);
            MarkBattlerForControllerExec(gActiveBattler);

            gBattlescriptCurrInstr += 7;
        }
        return;
    case VARIOUS_ARGUMENT_TO_MOVE_EFFECT:
        gBattleScripting.moveEffect = gBattleMoves[gCurrentMove].argument;
        break;
    case VARIOUS_JUMP_IF_NOT_GROUNDED:
        if (!IsBattlerGrounded(gActiveBattler))
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        else
            gBattlescriptCurrInstr += 7;
        return;
    case VARIOUS_HANDLE_TRAINER_SLIDE_MSG:
        if (gBattlescriptCurrInstr[3] == 0)
        {
            gBattleScripting.savedDmg = gBattlerSpriteIds[gActiveBattler];
        }
        else if (gBattlescriptCurrInstr[3] == 1)
        {
            BtlController_EmitPrintString(0, STRINGID_TRAINERSLIDE);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        else
        {
            gBattlerSpriteIds[gActiveBattler] = gBattleScripting.savedDmg;
            if (gBattleMons[gActiveBattler].hp != 0)
            {
                BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[gActiveBattler]], gActiveBattler);
            }
        }
        gBattlescriptCurrInstr += 4;
        return;
    case VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF:
        if (ShouldDoTrainerSlide(gActiveBattler, gTrainerBattleOpponent_A, TRAINER_SLIDE_FIRST_DOWN))
        {
            BattleScriptPush(gBattlescriptCurrInstr + 3);
            gBattlescriptCurrInstr = BattleScript_TrainerSlideMsgRet;
            return;
        }
        break;
    case VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON:
        if (ShouldDoTrainerSlide(gActiveBattler, gTrainerBattleOpponent_A, TRAINER_SLIDE_LAST_SWITCHIN))
        {
            BattleScriptPush(gBattlescriptCurrInstr + 3);
            gBattlescriptCurrInstr = BattleScript_TrainerSlideMsgRet;
            return;
        }
        break;
    case VARIOUS_SET_AURORA_VEIL:
        if (gSideStatuses[GET_BATTLER_SIDE(gActiveBattler)] & SIDE_STATUS_AURORA_VEIL)
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
    case VARIOUS_TRY_THIRD_TYPE:
        if (IS_BATTLER_OF_TYPE(gActiveBattler, gBattleMoves[gCurrentMove].argument))
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            gBattleMons[gActiveBattler].type3 = gBattleMoves[gCurrentMove].argument;
            PREPARE_TYPE_BUFFER(gBattleTextBuff1, gBattleMoves[gCurrentMove].argument);
            gBattlescriptCurrInstr += 7;
        }
        return;
    }

    gBattlescriptCurrInstr += 3;
}

static void atk77_setprotectlike(void)
{
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
                gProtectStructs[gBattlerAttacker].endured = 1;
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            }
            else if (gCurrentMove == MOVE_DETECT || gCurrentMove == MOVE_PROTECT)
            {
                gProtectStructs[gBattlerAttacker].protected = 1;
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            }
            else if (gCurrentMove == MOVE_SPIKY_SHIELD)
            {
                gProtectStructs[gBattlerAttacker].spikyShielded = 1;
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            }
            else if (gCurrentMove == MOVE_KING_S_SHIELD)
            {
                gProtectStructs[gBattlerAttacker].kingsShielded = 1;
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            }
            else if (gCurrentMove == MOVE_BANEFUL_BUNKER)
            {
                gProtectStructs[gBattlerAttacker].banefulBunkered = 1;
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
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
                gDisableStructs[gBattlerAttacker].protectUses++;
                fail = FALSE;
            }
            else if (gCurrentMove == MOVE_QUICK_GUARD && !(gSideStatuses[side] & SIDE_STATUS_QUICK_GUARD))
            {
                gSideStatuses[side] |= SIDE_STATUS_QUICK_GUARD;
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
                gDisableStructs[gBattlerAttacker].protectUses++;
                fail = FALSE;
            }
            else if (gCurrentMove == MOVE_CRAFTY_SHIELD && !(gSideStatuses[side] & SIDE_STATUS_CRAFTY_SHIELD))
            {
                gSideStatuses[side] |= SIDE_STATUS_CRAFTY_SHIELD;
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
                gDisableStructs[gBattlerAttacker].protectUses++;
                fail = FALSE;
            }
            else if (gCurrentMove == MOVE_MAT_BLOCK && !(gSideStatuses[side] & SIDE_STATUS_MAT_BLOCK))
            {
                gSideStatuses[side] |= SIDE_STATUS_MAT_BLOCK;
                gBattleCommunication[MULTISTRING_CHOOSER] = 3;
                fail = FALSE;
            }
        }
    }

    if (fail)
    {
        gDisableStructs[gBattlerAttacker].protectUses = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        gMoveResultFlags |= MOVE_RESULT_MISSED;
    }

    gBattlescriptCurrInstr++;
}

static void atk78_faintifabilitynotdamp(void)
{
    if (gBattleControllerExecFlags)
        return;

    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (gBattleMons[gBattlerTarget].ability == ABILITY_DAMP)
            break;
    }

    if (gBattlerTarget == gBattlersCount)
    {
        gActiveBattler = gBattlerAttacker;
        gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
        BtlController_EmitHealthBarUpdate(0, INSTANT_HP_BAR_DROP);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr++;

        for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
        {
            if (gBattlerTarget == gBattlerAttacker)
                continue;
            if (!(gAbsentBattlerFlags & gBitTable[gBattlerTarget]))
                break;
        }
    }
    else
    {
        gLastUsedAbility = ABILITY_DAMP;
        RecordAbilityBattle(gBattlerTarget, gBattleMons[gBattlerTarget].ability);
        gBattlescriptCurrInstr = BattleScript_DampStopsExplosion;
    }
}

static void atk79_setatkhptozero(void)
{
    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = gBattlerAttacker;
    gBattleMons[gActiveBattler].hp = 0;
    BtlController_EmitSetMonData(0, REQUEST_HP_BATTLE, 0, 2, &gBattleMons[gActiveBattler].hp);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr++;
}

static void atk7A_jumpifnexttargetvalid(void)
{
    const u8 *jumpPtr = T1_READ_PTR(gBattlescriptCurrInstr + 1);

    for (gBattlerTarget++; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (gBattlerTarget == gBattlerAttacker && !(gBattleMoves[gCurrentMove].target & MOVE_TARGET_USER))
            continue;
        if (!(gAbsentBattlerFlags & gBitTable[gBattlerTarget]))
            break;
    }

    if (gBattlerTarget >= gBattlersCount)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = jumpPtr;
}

static void atk7B_tryhealhalfhealth(void)
{
    const u8 *failPtr = T1_READ_PTR(gBattlescriptCurrInstr + 1);

    if (gBattlescriptCurrInstr[5] == BS_ATTACKER)
        gBattlerTarget = gBattlerAttacker;

    gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;
    gBattleMoveDamage *= -1;

    if (gBattleMons[gBattlerTarget].hp == gBattleMons[gBattlerTarget].maxHP)
        gBattlescriptCurrInstr = failPtr;
    else
        gBattlescriptCurrInstr += 6;
}

static void atk7C_trymirrormove(void)
{
    s32 validMovesCount;
    s32 i;
    u16 move;
    u16 movesArray[4] = {0};

    for (validMovesCount = 0, i = 0; i < gBattlersCount; i++)
    {
        if (i != gBattlerAttacker)
        {
            move = gBattleStruct->lastTakenMoveFrom[gBattlerAttacker][i];
            if (move != 0 && move != 0xFFFF)
            {
                movesArray[validMovesCount] = move;
                validMovesCount++;
            }
        }
    }

    move = gBattleStruct->lastTakenMove[gBattlerAttacker];
    if (move != 0 && move != 0xFFFF)
    {
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gCurrentMove = move;
        gBattlerTarget = GetMoveTarget(gCurrentMove, 0);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }
    else if (validMovesCount)
    {
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        i = Random() % validMovesCount;
        gCurrentMove = movesArray[i];
        gBattlerTarget = GetMoveTarget(gCurrentMove, 0);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }
    else
    {
        gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = 1;
        gBattlescriptCurrInstr++;
    }
}

static void atk7D_setrain(void)
{
    if (!TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_RAIN, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    gBattlescriptCurrInstr++;
}

static void atk7E_setreflect(void)
{
    if (gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] & SIDE_STATUS_REFLECT)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
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
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    gBattlescriptCurrInstr++;
}

static void atk7F_setseeded(void)
{
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT || gStatuses3[gBattlerTarget] & STATUS3_LEECHSEED)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else if (IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_GRASS))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gStatuses3[gBattlerTarget] |= gBattlerAttacker;
        gStatuses3[gBattlerTarget] |= STATUS3_LEECHSEED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }

    gBattlescriptCurrInstr++;
}

static void atk80_manipulatedamage(void)
{
    switch (gBattlescriptCurrInstr[1])
    {
    case ATK80_DMG_CHANGE_SIGN:
        gBattleMoveDamage *= -1;
        break;
    case ATK80_DMG_HALF_BY_TWO_NOT_MORE_THAN_HALF_MAX_HP:
        gBattleMoveDamage /= 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        if ((gBattleMons[gBattlerTarget].maxHP / 2) < gBattleMoveDamage)
            gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 2;
        break;
    case ATK80_DMG_DOUBLED:
        gBattleMoveDamage *= 2;
        break;
    case ATK80_1_8_TARGET_HP:
        gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 8;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        break;
    case ATK80_FULL_ATTACKER_HP:
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP;
        break;
    case ATK80_CURR_ATTACKER_HP:
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].hp;
        break;
    }

    gBattlescriptCurrInstr += 2;
}

static void atk81_trysetrest(void)
{
    const u8 *failJump = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    gActiveBattler = gBattlerTarget = gBattlerAttacker;
    gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP * (-1);

    if (gBattleMons[gBattlerTarget].hp == gBattleMons[gBattlerTarget].maxHP)
    {
        gBattlescriptCurrInstr = failJump;
    }
    else
    {
        if (gBattleMons[gBattlerTarget].status1 & ((u8)(~STATUS1_SLEEP)))
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;

        gBattleMons[gBattlerTarget].status1 = 3;
        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 5;
    }
}

static void atk82_jumpifnotfirstturn(void)
{
    const u8* failJump = T1_READ_PTR(gBattlescriptCurrInstr + 1);

    if (gDisableStructs[gBattlerAttacker].isFirstTurn)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = failJump;
}

static void atk83_setmiracleeye(void)
{
    if (!(gStatuses3[gBattlerTarget] & STATUS3_MIRACLE_EYED))
    {
        gStatuses3[gBattlerTarget] |= STATUS3_MIRACLE_EYED;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

bool8 UproarWakeUpCheck(u8 battlerId)
{
    s32 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (!(gBattleMons[i].status2 & STATUS2_UPROAR) || gBattleMons[battlerId].ability == ABILITY_SOUNDPROOF)
            continue;

        gBattleScripting.battler = i;

        if (gBattlerTarget == 0xFF)
            gBattlerTarget = i;
        else if (gBattlerTarget == i)
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;

        break;
    }

    if (i == gBattlersCount)
        return FALSE;
    else
        return TRUE;
}

static void atk84_jumpifcantmakeasleep(void)
{
    const u8 *jumpPtr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    u32 ability = GetBattlerAbility(gBattlerTarget);

    if (UproarWakeUpCheck(gBattlerTarget))
    {
        gBattlescriptCurrInstr = jumpPtr;
    }
    else if (ability == ABILITY_INSOMNIA || ability == ABILITY_VITAL_SPIRIT)
    {
        gLastUsedAbility = ability;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        gBattlescriptCurrInstr = jumpPtr;
        RecordAbilityBattle(gBattlerTarget, gLastUsedAbility);
    }
    else
    {
        gBattlescriptCurrInstr += 5;
    }
}

static void atk85_stockpile(void)
{
    if (gDisableStructs[gBattlerAttacker].stockpileCounter == 3)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gDisableStructs[gBattlerAttacker].stockpileCounter++;

        PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 1, gDisableStructs[gBattlerAttacker].stockpileCounter)

        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    gBattlescriptCurrInstr++;
}

static void atk86_stockpiletobasedamage(void)
{
    const u8* jumpPtr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    if (gDisableStructs[gBattlerAttacker].stockpileCounter == 0)
    {
        gBattlescriptCurrInstr = jumpPtr;
    }
    else
    {
        if (gBattleCommunication[6] != 1)
        {
            gBattleScripting.animTurn = gDisableStructs[gBattlerAttacker].stockpileCounter;
        }

        gDisableStructs[gBattlerAttacker].stockpileCounter = 0;
        gBattlescriptCurrInstr += 5;
    }
}

static void atk87_stockpiletohpheal(void)
{
    const u8* jumpPtr = T1_READ_PTR(gBattlescriptCurrInstr + 1);

    if (gDisableStructs[gBattlerAttacker].stockpileCounter == 0)
    {
        gBattlescriptCurrInstr = jumpPtr;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else if (gBattleMons[gBattlerAttacker].maxHP == gBattleMons[gBattlerAttacker].hp)
    {
        gDisableStructs[gBattlerAttacker].stockpileCounter = 0;
        gBattlescriptCurrInstr = jumpPtr;
        gBattlerTarget = gBattlerAttacker;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / (1 << (3 - gDisableStructs[gBattlerAttacker].stockpileCounter));

        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        gBattleScripting.animTurn = gDisableStructs[gBattlerAttacker].stockpileCounter;
        gDisableStructs[gBattlerAttacker].stockpileCounter = 0;
        gBattlescriptCurrInstr += 5;
        gBattlerTarget = gBattlerAttacker;
    }
}

static void atk88_setdrainedhp(void)
{
    if (gBattleMoves[gCurrentMove].argument != 0)
        gBattleMoveDamage = -(gHpDealt * gBattleMoves[gCurrentMove].argument / 100);
    else
        gBattleMoveDamage = -(gHpDealt / 2);

    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = -1;

    gBattlescriptCurrInstr++;
}

static u32 ChangeStatBuffs(s8 statValue, u32 statId, u32 flags, const u8 *BS_ptr)
{
    bool32 certain = FALSE;
    bool32 notProtectAffected = FALSE;
    u32 index;

    if (flags & MOVE_EFFECT_AFFECTS_USER)
        gActiveBattler = gBattlerAttacker;
    else
        gActiveBattler = gBattlerTarget;

    gSpecialStatuses[gActiveBattler].changedStatsBattlerId = gBattlerAttacker;

    flags &= ~(MOVE_EFFECT_AFFECTS_USER);

    if (flags & MOVE_EFFECT_CERTAIN)
        certain++;
    flags &= ~(MOVE_EFFECT_CERTAIN);

    if (flags & STAT_CHANGE_NOT_PROTECT_AFFECTED)
        notProtectAffected++;
    flags &= ~(STAT_CHANGE_NOT_PROTECT_AFFECTED);

    if (GetBattlerAbility(gActiveBattler) == ABILITY_CONTRARY)
    {
        statValue ^= STAT_BUFF_NEGATIVE;
        gBattleScripting.statChanger ^= STAT_BUFF_NEGATIVE;
    }
    else if (GetBattlerAbility(gActiveBattler) == ABILITY_SIMPLE)
    {
        statValue = (SET_STAT_BUFF_VALUE(GET_STAT_BUFF_VALUE(statValue) * 2)) | ((statValue <= -1) ? STAT_BUFF_NEGATIVE : 0);
    }

    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId);

    if (statValue <= -1) // Stat decrease.
    {
        if (gSideTimers[GET_BATTLER_SIDE(gActiveBattler)].mistTimer
            && !certain && gCurrentMove != MOVE_CURSE)
        {
            if (flags == STAT_CHANGE_BS_PTR)
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
                    gSpecialStatuses[gActiveBattler].statLowered = 1;
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
        else if ((GetBattlerAbility(gActiveBattler) == ABILITY_CLEAR_BODY
                  || GetBattlerAbility(gActiveBattler) == ABILITY_WHITE_SMOKE)
                 && !certain && gCurrentMove != MOVE_CURSE)
        {
            if (flags == STAT_CHANGE_BS_PTR)
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
                    gLastUsedAbility = GetBattlerAbility(gActiveBattler);
                    RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
                    gSpecialStatuses[gActiveBattler].statLowered = 1;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if ((index = IsFlowerVeilProtected(gActiveBattler)) && !certain)
        {
            if (flags == STAT_CHANGE_BS_PTR)
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
                    gSpecialStatuses[gActiveBattler].statLowered = 1;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (GetBattlerAbility(gActiveBattler) == ABILITY_KEEN_EYE
                 && !certain && statId == STAT_ACC)
        {
            if (flags == STAT_CHANGE_BS_PTR)
            {
                BattleScriptPush(BS_ptr);
                gBattleScripting.battler = gActiveBattler;
                gBattlerAbility = gActiveBattler;
                gBattlescriptCurrInstr = BattleScript_AbilityNoSpecificStatLoss;
                gLastUsedAbility = GetBattlerAbility(gActiveBattler);
                RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (GetBattlerAbility(gActiveBattler) == ABILITY_HYPER_CUTTER
                 && !certain && statId == STAT_ATK)
        {
            if (flags == STAT_CHANGE_BS_PTR)
            {
                BattleScriptPush(BS_ptr);
                gBattleScripting.battler = gActiveBattler;
                gBattlerAbility = gActiveBattler;
                gBattlescriptCurrInstr = BattleScript_AbilityNoSpecificStatLoss;
                gLastUsedAbility = GetBattlerAbility(gActiveBattler);
                RecordAbilityBattle(gActiveBattler, gLastUsedAbility);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (GetBattlerAbility(gActiveBattler) == ABILITY_SHIELD_DUST && flags == 0)
        {
            return STAT_CHANGE_DIDNT_WORK;
        }
        else // try to decrease
        {
            statValue = -GET_STAT_BUFF_VALUE(statValue);
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
            gBattleTextBuff2[index] = B_BUFF_STRING;
            index++;
            gBattleTextBuff2[index] = STRINGID_STATFELL;
            index++;
            gBattleTextBuff2[index] = STRINGID_STATFELL >> 8;
            index++;
            gBattleTextBuff2[index] = B_BUFF_EOS;

            if (gBattleMons[gActiveBattler].statStages[statId] == 0)
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = (gBattlerTarget == gActiveBattler);

        }
    }
    else // stat increase
    {
        statValue = GET_STAT_BUFF_VALUE(statValue);
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
        gBattleTextBuff2[index] = B_BUFF_STRING;
        index++;
        gBattleTextBuff2[index] = STRINGID_STATROSE;
        index++;
        gBattleTextBuff2[index] = STRINGID_STATROSE >> 8;
        index++;
        gBattleTextBuff2[index] = B_BUFF_EOS;

        if (gBattleMons[gActiveBattler].statStages[statId] == 0xC)
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = (gBattlerTarget == gActiveBattler);
    }

    gBattleMons[gActiveBattler].statStages[statId] += statValue;
    if (gBattleMons[gActiveBattler].statStages[statId] < 0)
        gBattleMons[gActiveBattler].statStages[statId] = 0;
    if (gBattleMons[gActiveBattler].statStages[statId] > 0xC)
        gBattleMons[gActiveBattler].statStages[statId] = 0xC;

    if (gBattleCommunication[MULTISTRING_CHOOSER] == 2 && flags & STAT_CHANGE_BS_PTR)
        gMoveResultFlags |= MOVE_RESULT_MISSED;

    if (gBattleCommunication[MULTISTRING_CHOOSER] == 2 && !(flags & STAT_CHANGE_BS_PTR))
        return STAT_CHANGE_DIDNT_WORK;

    return STAT_CHANGE_WORKED;
}

static void atk89_statbuffchange(void)
{
    u16 flags = T1_READ_16(gBattlescriptCurrInstr + 1);
    const u8 *ptrBefore = gBattlescriptCurrInstr;
    const u8 *jumpPtr = T1_READ_PTR(gBattlescriptCurrInstr + 3);

    if (ChangeStatBuffs(GET_STAT_BUFF_VALUE_WITH_SIGN(gBattleScripting.statChanger), GET_STAT_BUFF_ID(gBattleScripting.statChanger), flags, jumpPtr) == STAT_CHANGE_WORKED)
        gBattlescriptCurrInstr += 7;
    else if (gBattlescriptCurrInstr == ptrBefore) // Prevent infinite looping.
        gBattlescriptCurrInstr = jumpPtr;
}

static void atk8A_normalisebuffs(void) // haze
{
    s32 i, j;

    for (i = 0; i < gBattlersCount; i++)
    {
        for (j = 0; j < NUM_BATTLE_STATS; j++)
            gBattleMons[i].statStages[j] = 6;
    }

    gBattlescriptCurrInstr++;
}

static void atk8B_setbide(void)
{
    gBattleMons[gBattlerAttacker].status2 |= STATUS2_MULTIPLETURNS;
    gLockedMoves[gBattlerAttacker] = gCurrentMove;
    gTakenDmg[gBattlerAttacker] = 0;
    gBattleMons[gBattlerAttacker].status2 |= (STATUS2_BIDE - 0x100); // 2 turns

    gBattlescriptCurrInstr++;
}

static void atk8C_confuseifrepeatingattackends(void)
{
    if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_LOCK_CONFUSE))
        gBattleScripting.moveEffect = (MOVE_EFFECT_THRASH | MOVE_EFFECT_AFFECTS_USER);

    gBattlescriptCurrInstr++;
}

static void atk8D_setmultihitcounter(void)
{
    if (gBattlescriptCurrInstr[1])
    {
        gMultiHitCounter = gBattlescriptCurrInstr[1];
    }
    else
    {
        gMultiHitCounter = Random() & 3;
        if (gMultiHitCounter > 1)
            gMultiHitCounter = (Random() & 3) + 2;
        else
            gMultiHitCounter += 2;

        if (GetBattlerAbility(gBattlerAttacker) == ABILITY_SKILL_LINK)
            gMultiHitCounter = 5;
    }

    gBattlescriptCurrInstr += 2;
}

static void atk8E_initmultihitstring(void)
{
    PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)

    gBattlescriptCurrInstr++;
}

static void atk8F_forcerandomswitch(void)
{
    s32 i;
    s32 battler1PartyId = 0;
    s32 battler2PartyId = 0;
    s32 lastMonId = 0; // + 1
    s32 firstMonId = 0;
    s32 monsCount = 0;
    struct Pokemon *party = NULL;
    s32 validMons = 0;
    s32 minNeeded = 0;

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
       )
    {
        if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
            party = gPlayerParty;
        else
            party = gEnemyParty;

        if (BATTLE_TWO_VS_ONE_OPPONENT && GetBattlerSide(gBattlerTarget) == B_SIDE_OPPONENT)
        {
            firstMonId = 0;
            lastMonId = 6;
            monsCount = 6;
            minNeeded = 2;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[gBattlerTarget ^ BIT_FLANK];
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER && gBattleTypeFlags & BATTLE_TYPE_LINK)
            || (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER && gBattleTypeFlags & BATTLE_TYPE_x2000000)
            || (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
        {
            if ((gBattlerTarget & BIT_FLANK) != 0)
            {
                firstMonId = 3;
                lastMonId = 6;
            }
            else
            {
                firstMonId = 0;
                lastMonId = 3;
            }
            monsCount = 3;
            minNeeded = 1;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[gBattlerTarget ^ BIT_FLANK];
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
                 || (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_x2000000))
        {
            if (GetLinkTrainerFlankId(GetBattlerMultiplayerId(gBattlerTarget)) == 1)
            {
                firstMonId = 3;
                lastMonId = 6;
            }
            else
            {
                firstMonId = 0;
                lastMonId = 3;
            }
            monsCount = 3;
            minNeeded = 1;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[gBattlerTarget ^ BIT_FLANK];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
            {
                firstMonId = 0;
                lastMonId = 6;
                monsCount = 6;
                minNeeded = 2; // since there are two opponents, it has to be a double battle
            }
            else
            {
                if ((gBattlerTarget & BIT_FLANK) != 0)
                {
                    firstMonId = 3;
                    lastMonId = 6;
                }
                else
                {
                    firstMonId = 0;
                    lastMonId = 3;
                }
                monsCount = 3;
                minNeeded = 1;
            }
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[gBattlerTarget ^ BIT_FLANK];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            firstMonId = 0;
            lastMonId = 6;
            monsCount = 6;
            minNeeded = 2;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget];
            battler1PartyId = gBattlerPartyIndexes[gBattlerTarget ^ BIT_FLANK];
        }
        else
        {
            firstMonId = 0;
            lastMonId = 6;
            monsCount = 6;
            minNeeded = 1;
            battler2PartyId = gBattlerPartyIndexes[gBattlerTarget]; // there is only one pokemon out in single battles
            battler1PartyId = gBattlerPartyIndexes[gBattlerTarget];
        }

        for (i = firstMonId; i < lastMonId; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && GetMonData(&party[i], MON_DATA_HP) != 0)
             {
                 validMons++;
             }
        }

        if (validMons <= minNeeded)
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        }
        else
        {
            *(gBattleStruct->field_58 + gBattlerTarget) = gBattlerPartyIndexes[gBattlerTarget];
            gBattlescriptCurrInstr = BattleScript_RoarSuccessSwitch;

            do
            {
                i = Random() % monsCount;
                i += firstMonId;
            }
            while (i == battler2PartyId
                   || i == battler1PartyId
                   || GetMonData(&party[i], MON_DATA_SPECIES) == SPECIES_NONE
                   || GetMonData(&party[i], MON_DATA_IS_EGG) == TRUE
                   || GetMonData(&party[i], MON_DATA_HP) == 0);

            *(gBattleStruct->monToSwitchIntoId + gBattlerTarget) = i;

            if (!IsMultiBattle())
                sub_803BDA0(gBattlerTarget);

            if ((gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                || (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI)
                || (gBattleTypeFlags & BATTLE_TYPE_x2000000 && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                || (gBattleTypeFlags & BATTLE_TYPE_x2000000 && gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                sub_81B8E80(gBattlerTarget, i, 0);
                sub_81B8E80(gBattlerTarget ^ BIT_FLANK, i, 1);
            }

            if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                sub_80571DC(gBattlerTarget, i);
        }
    }
    else
    {
        // In normal wild doubles, Roar will always fail if the user's level is less than the target's.
        if (gBattleMons[gBattlerAttacker].level >= gBattleMons[gBattlerTarget].level)
            gBattlescriptCurrInstr = BattleScript_RoarSuccessEndBattle;
        else
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atk90_tryconversiontypechange(void) // randomly changes user's type to one of its moves' type
{
    u8 validMoves = 0;
    u8 moveChecked;
    u8 moveType;

    while (validMoves < MAX_MON_MOVES)
    {
        if (gBattleMons[gBattlerAttacker].moves[validMoves] == 0)
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
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        do
        {

            while ((moveChecked = Random() & 3) >= validMoves);

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

        gBattlescriptCurrInstr += 5;
    }
}

static void atk91_givepaydaymoney(void)
{
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000)) && gPaydayMoney != 0)
    {
        u32 bonusMoney = gPaydayMoney * gBattleStruct->moneyMultiplier;
        AddMoney(&gSaveBlock1Ptr->money, bonusMoney);

        PREPARE_HWORD_NUMBER_BUFFER(gBattleTextBuff1, 5, bonusMoney)

        BattleScriptPush(gBattlescriptCurrInstr + 1);
        gBattlescriptCurrInstr = BattleScript_PrintPayDayMoneyString;
    }
    else
    {
        gBattlescriptCurrInstr++;
    }
}

static void atk92_setlightscreen(void)
{
    if (gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] & SIDE_STATUS_LIGHTSCREEN)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
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
            gBattleCommunication[MULTISTRING_CHOOSER] = 4;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 3;
    }

    gBattlescriptCurrInstr++;
}

static void atk93_tryKO(void)
{
    u8 holdEffect, param;

    if (gBattleMons[gBattlerTarget].item == ITEM_ENIGMA_BERRY)
    {
       holdEffect = gEnigmaBerries[gBattlerTarget].holdEffect;
       param = gEnigmaBerries[gBattlerTarget].holdEffectParam;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(gBattleMons[gBattlerTarget].item);
        param = ItemId_GetHoldEffectParam(gBattleMons[gBattlerTarget].item);
    }

    gPotentialItemEffectBattler = gBattlerTarget;

    if (holdEffect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < param)
    {
        RecordItemEffectBattle(gBattlerTarget, HOLD_EFFECT_FOCUS_BAND);
        gSpecialStatuses[gBattlerTarget].focusBanded = 1;
    }

    if (gBattleMons[gBattlerTarget].ability == ABILITY_STURDY)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gLastUsedAbility = ABILITY_STURDY;
        gBattlescriptCurrInstr = BattleScript_SturdyPreventsOHKO;
        RecordAbilityBattle(gBattlerTarget, ABILITY_STURDY);
    }
    else
    {
        u16 chance;
        if (!(gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS))
        {
            chance = gBattleMoves[gCurrentMove].accuracy + (gBattleMons[gBattlerAttacker].level - gBattleMons[gBattlerTarget].level);
            if (Random() % 100 + 1 < chance && gBattleMons[gBattlerAttacker].level >= gBattleMons[gBattlerTarget].level)
                chance = TRUE;
            else
                chance = FALSE;
        }
        else if (gDisableStructs[gBattlerTarget].battlerWithSureHit == gBattlerAttacker
                 && gBattleMons[gBattlerAttacker].level >= gBattleMons[gBattlerTarget].level)
        {
            chance = TRUE;
        }
        else
        {
            chance = gBattleMoves[gCurrentMove].accuracy + (gBattleMons[gBattlerAttacker].level - gBattleMons[gBattlerTarget].level);
            if (Random() % 100 + 1 < chance && gBattleMons[gBattlerAttacker].level >= gBattleMons[gBattlerTarget].level)
                chance = TRUE;
            else
                chance = FALSE;
        }
        if (chance)
        {
            if (gProtectStructs[gBattlerTarget].endured)
            {
                gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - 1;
                gMoveResultFlags |= MOVE_RESULT_FOE_ENDURED;
            }
            else if (gSpecialStatuses[gBattlerTarget].focusBanded)
            {
                gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - 1;
                gMoveResultFlags |= MOVE_RESULT_FOE_HUNG_ON;
                gLastUsedItem = gBattleMons[gBattlerTarget].item;
            }
            else
            {
                gBattleMoveDamage = gBattleMons[gBattlerTarget].hp;
                gMoveResultFlags |= MOVE_RESULT_ONE_HIT_KO;
            }
            gBattlescriptCurrInstr += 5;
        }
        else
        {
            gMoveResultFlags |= MOVE_RESULT_MISSED;
            if (gBattleMons[gBattlerAttacker].level >= gBattleMons[gBattlerTarget].level)
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        }
    }
}

static void atk94_damagetohalftargethp(void) // super fang
{
    gBattleMoveDamage = gBattleMons[gBattlerTarget].hp / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    gBattlescriptCurrInstr++;
}

static void atk95_setsandstorm(void)
{
    if (!TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_SANDSTORM, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = 3;
    }
    gBattlescriptCurrInstr++;
}

static void atk96_weatherdamage(void)
{
    if (WEATHER_HAS_EFFECT)
    {
        u32 ability = GetBattlerAbility(gBattlerAttacker);
        if (gBattleWeather & WEATHER_SANDSTORM_ANY)
        {
            if (!IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_ROCK)
                && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_GROUND)
                && !IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_STEEL)
                && ability != ABILITY_SAND_VEIL
                && ability != ABILITY_SAND_FORCE
                && ability != ABILITY_SAND_RUSH
                && ability != ABILITY_OVERCOAT
                && !(gStatuses3[gBattlerAttacker] & STATUS3_UNDERGROUND)
                && !(gStatuses3[gBattlerAttacker] & STATUS3_UNDERWATER)
                && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_SAFETY_GOOGLES)
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
            }
            else
            {
                gBattleMoveDamage = 0;
            }
        }
        if (gBattleWeather & WEATHER_HAIL_ANY)
        {
            if (ability == ABILITY_ICE_BODY
                && !(gStatuses3[gBattlerAttacker] & STATUS3_UNDERGROUND)
                && !(gStatuses3[gBattlerAttacker] & STATUS3_UNDERWATER)
                && !BATTLER_MAX_HP(gBattlerAttacker)
                && !gStatuses3[gBattlerAttacker] & STATUS3_HEAL_BLOCK)
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
                gBattleMoveDamage *= -1;
            }
            else if (!IS_BATTLER_OF_TYPE(gBattlerAttacker, TYPE_ICE)
                && ability != ABILITY_SNOW_CLOAK
                && ability != ABILITY_OVERCOAT
                && ability != ABILITY_ICE_BODY
                && !(gStatuses3[gBattlerAttacker] & STATUS3_UNDERGROUND)
                && !(gStatuses3[gBattlerAttacker] & STATUS3_UNDERWATER)
                && GetBattlerHoldEffect(gBattlerAttacker, TRUE) != HOLD_EFFECT_SAFETY_GOOGLES)
            {
                gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
            }
            else
            {
                gBattleMoveDamage = 0;
            }
        }
    }
    else
    {
        gBattleMoveDamage = 0;
    }

    if (gAbsentBattlerFlags & gBitTable[gBattlerAttacker])
        gBattleMoveDamage = 0;

    gBattlescriptCurrInstr++;
}

static void atk97_tryinfatuating(void)
{
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

    if (gBattleMons[gBattlerTarget].ability == ABILITY_OBLIVIOUS)
    {
        gBattlescriptCurrInstr = BattleScript_ObliviousPreventsAttraction;
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
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        }
        else
        {
            gBattleMons[gBattlerTarget].status2 |= STATUS2_INFATUATED_WITH(gBattlerAttacker);
            gBattlescriptCurrInstr += 5;
        }
    }
}

static void atk98_updatestatusicon(void)
{
    if (gBattleControllerExecFlags)
        return;

    if (gBattlescriptCurrInstr[1] != BS_ATTACKER_WITH_PARTNER)
    {
        gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);
        BtlController_EmitStatusIconUpdate(0, gBattleMons[gActiveBattler].status1, gBattleMons[gActiveBattler].status2);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 2;
    }
    else
    {
        gActiveBattler = gBattlerAttacker;
        if (!(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
        {
            BtlController_EmitStatusIconUpdate(0, gBattleMons[gActiveBattler].status1, gBattleMons[gActiveBattler].status2);
            MarkBattlerForControllerExec(gActiveBattler);
        }
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        {
            gActiveBattler = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_FLANK);
            if (!(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
            {
                BtlController_EmitStatusIconUpdate(0, gBattleMons[gActiveBattler].status1, gBattleMons[gActiveBattler].status2);
                MarkBattlerForControllerExec(gActiveBattler);
            }
        }
        gBattlescriptCurrInstr += 2;
    }
}

static void atk99_setmist(void)
{
    if (gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].mistTimer)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].mistTimer = 5;
        gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].mistBattlerId = gBattlerAttacker;
        gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] |= SIDE_STATUS_MIST;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    gBattlescriptCurrInstr++;
}

static void atk9A_setfocusenergy(void)
{
    if (gBattleMons[gBattlerAttacker].status2 & STATUS2_FOCUS_ENERGY)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gBattleMons[gBattlerAttacker].status2 |= STATUS2_FOCUS_ENERGY;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    gBattlescriptCurrInstr++;
}

static void atk9B_transformdataexecution(void)
{
    gChosenMove = 0xFFFF;
    gBattlescriptCurrInstr++;
    if (gBattleMons[gBattlerTarget].status2 & STATUS2_TRANSFORMED
        || gStatuses3[gBattlerTarget] & STATUS3_SEMI_INVULNERABLE)
    {
        gMoveResultFlags |= MOVE_RESULT_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        s32 i;
        u8 *battleMonAttacker, *battleMonTarget;

        gBattleMons[gBattlerAttacker].status2 |= STATUS2_TRANSFORMED;
        gDisableStructs[gBattlerAttacker].disabledMove = 0;
        gDisableStructs[gBattlerAttacker].disableTimer = 0;
        gDisableStructs[gBattlerAttacker].transformedMonPersonality = gBattleMons[gBattlerTarget].personality;
        gDisableStructs[gBattlerAttacker].mimickedMoves = 0;
        gDisableStructs[gBattlerAttacker].usedMoves = 0;

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerTarget].species)

        battleMonAttacker = (u8*)(&gBattleMons[gBattlerAttacker]);
        battleMonTarget = (u8*)(&gBattleMons[gBattlerTarget]);

        for (i = 0; i < offsetof(struct BattlePokemon, pp); i++)
            battleMonAttacker[i] = battleMonTarget[i];

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMoves[gBattleMons[gBattlerAttacker].moves[i]].pp < 5)
                gBattleMons[gBattlerAttacker].pp[i] = gBattleMoves[gBattleMons[gBattlerAttacker].moves[i]].pp;
            else
                gBattleMons[gBattlerAttacker].pp[i] = 5;
        }

        gActiveBattler = gBattlerAttacker;
        BtlController_EmitResetActionMoveSelection(0, RESET_MOVE_SELECTION);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
}

static void atk9C_setsubstitute(void)
{
    u32 hp = gBattleMons[gBattlerAttacker].maxHP / 4;
    if (gBattleMons[gBattlerAttacker].maxHP / 4 == 0)
        hp = 1;

    if (gBattleMons[gBattlerAttacker].hp <= hp)
    {
        gBattleMoveDamage = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4; // one bit value will only work for pokemon which max hp can go to 1020(which is more than possible in games)
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattleMons[gBattlerAttacker].status2 |= STATUS2_SUBSTITUTE;
        gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_WRAPPED);
        gDisableStructs[gBattlerAttacker].substituteHP = gBattleMoveDamage;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        gHitMarker |= HITMARKER_IGNORE_SUBSTITUTE;
    }

    gBattlescriptCurrInstr++;
}

static bool8 IsMoveUncopyableByMimic(u16 move)
{
    s32 i;
    for (i = 0; sMovesForbiddenToCopy[i] != MIMIC_FORBIDDEN_END
                && sMovesForbiddenToCopy[i] != move; i++);

    return (sMovesForbiddenToCopy[i] != MIMIC_FORBIDDEN_END);
}

static void atk9D_mimicattackcopy(void)
{
    gChosenMove = 0xFFFF;

    if (IsMoveUncopyableByMimic(gLastMoves[gBattlerTarget])
        || gBattleMons[gBattlerAttacker].status2 & STATUS2_TRANSFORMED
        || gLastMoves[gBattlerTarget] == 0
        || gLastMoves[gBattlerTarget] == 0xFFFF)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
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
            gBattleMons[gBattlerAttacker].moves[gCurrMovePos] = gLastMoves[gBattlerTarget];
            if (gBattleMoves[gLastMoves[gBattlerTarget]].pp < 5)
                gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = gBattleMoves[gLastMoves[gBattlerTarget]].pp;
            else
                gBattleMons[gBattlerAttacker].pp[gCurrMovePos] = 5;


            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastMoves[gBattlerTarget])

            gDisableStructs[gBattlerAttacker].mimickedMoves |= gBitTable[gCurrMovePos];
            gBattlescriptCurrInstr += 5;
        }
        else
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        }
    }
}

static void atk9E_metronome(void)
{
    while (1)
    {
        s32 i;

        gCurrentMove = (Random() % (MOVES_COUNT - 1)) + 1;
        if (gBattleMoves[gCurrentMove].effect == EFFECT_PLACEHOLDER)
            continue;

        i = -1;
        while (1)
        {
            i++;
            if (sMovesForbiddenToCopy[i] == gCurrentMove)
                break;
            if (sMovesForbiddenToCopy[i] == METRONOME_FORBIDDEN_END)
                break;
        }

        if (sMovesForbiddenToCopy[i] == METRONOME_FORBIDDEN_END)
        {
            gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
            gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
            gBattlerTarget = GetMoveTarget(gCurrentMove, 0);
            return;
        }
    }
}

static void atk9F_dmgtolevel(void)
{
    gBattleMoveDamage = gBattleMons[gBattlerAttacker].level;
    gBattlescriptCurrInstr++;
}

static void atkA0_psywavedamageeffect(void)
{
    s32 randDamage;

    while ((randDamage = (Random() & 0xF)) > 10);

    randDamage *= 10;
    gBattleMoveDamage = gBattleMons[gBattlerAttacker].level * (randDamage + 50) / 100;
    gBattlescriptCurrInstr++;
}

static void atkA1_counterdamagecalculator(void)
{
    u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
    u8 sideTarget = GetBattlerSide(gProtectStructs[gBattlerAttacker].physicalBattlerId);

    if (gProtectStructs[gBattlerAttacker].physicalDmg
        && sideAttacker != sideTarget
        && gBattleMons[gProtectStructs[gBattlerAttacker].physicalBattlerId].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBattlerAttacker].physicalDmg * 2;

        if (gSideTimers[sideTarget].followmeTimer && gBattleMons[gSideTimers[sideTarget].followmeTarget].hp)
            gBattlerTarget = gSideTimers[sideTarget].followmeTarget;
        else
            gBattlerTarget = gProtectStructs[gBattlerAttacker].physicalBattlerId;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = 1;
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkA2_mirrorcoatdamagecalculator(void) // a copy of atkA1 with the physical -> special field changes
{
    u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
    u8 sideTarget = GetBattlerSide(gProtectStructs[gBattlerAttacker].specialBattlerId);

    if (gProtectStructs[gBattlerAttacker].specialDmg && sideAttacker != sideTarget && gBattleMons[gProtectStructs[gBattlerAttacker].specialBattlerId].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBattlerAttacker].specialDmg * 2;

        if (gSideTimers[sideTarget].followmeTimer && gBattleMons[gSideTimers[sideTarget].followmeTarget].hp)
            gBattlerTarget = gSideTimers[sideTarget].followmeTarget;
        else
            gBattlerTarget = gProtectStructs[gBattlerAttacker].specialBattlerId;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = 1;
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkA3_disablelastusedattack(void)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[gBattlerTarget].moves[i] == gLastMoves[gBattlerTarget])
            break;
    }
    if (gDisableStructs[gBattlerTarget].disabledMove == 0
        && i != MAX_MON_MOVES && gBattleMons[gBattlerTarget].pp[i] != 0)
    {
        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[gBattlerTarget].moves[i])

        gDisableStructs[gBattlerTarget].disabledMove = gBattleMons[gBattlerTarget].moves[i];
        gDisableStructs[gBattlerTarget].disableTimer = (Random() & 3) + 2;
        gDisableStructs[gBattlerTarget].disableTimerStartValue = gDisableStructs[gBattlerTarget].disableTimer; // used to save the random amount of turns?
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkA4_trysetencore(void)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[gBattlerTarget].moves[i] == gLastMoves[gBattlerTarget])
            break;
    }

    if (gLastMoves[gBattlerTarget] == MOVE_STRUGGLE
        || gLastMoves[gBattlerTarget] == MOVE_ENCORE
        || gLastMoves[gBattlerTarget] == MOVE_MIRROR_MOVE)
    {
        i = 4;
    }

    if (gDisableStructs[gBattlerTarget].encoredMove == 0
        && i != 4 && gBattleMons[gBattlerTarget].pp[i] != 0)
    {
        gDisableStructs[gBattlerTarget].encoredMove = gBattleMons[gBattlerTarget].moves[i];
        gDisableStructs[gBattlerTarget].encoredMovePos = i;
        gDisableStructs[gBattlerTarget].encoreTimer = 3;
        gDisableStructs[gBattlerTarget].encoreTimerStartValue = gDisableStructs[gBattlerTarget].encoreTimer;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkA5_painsplitdmgcalc(void)
{
    if (!(DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove)))
    {
        s32 hpDiff = (gBattleMons[gBattlerAttacker].hp + gBattleMons[gBattlerTarget].hp) / 2;
        s32 painSplitHp = gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - hpDiff;
        u8* storeLoc = (void*)(&gBattleScripting.painSplitHp);

        storeLoc[0] = (painSplitHp);
        storeLoc[1] = (painSplitHp & 0x0000FF00) >> 8;
        storeLoc[2] = (painSplitHp & 0x00FF0000) >> 16;
        storeLoc[3] = (painSplitHp & 0xFF000000) >> 24;

        gBattleMoveDamage = gBattleMons[gBattlerAttacker].hp - hpDiff;
        gSpecialStatuses[gBattlerTarget].dmg = 0xFFFF;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkA6_settypetorandomresistance(void) // conversion 2
{
    if (gLastLandedMoves[gBattlerAttacker] == 0
        || gLastLandedMoves[gBattlerAttacker] == 0xFFFF)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else if (IsTwoTurnsMove(gLastLandedMoves[gBattlerAttacker])
            && gBattleMons[gLastHitBy[gBattlerAttacker]].status2 & STATUS2_MULTIPLETURNS)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
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
                    gBattlescriptCurrInstr += 5;
                    return;
                }
            }
        }

        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkA7_setalwayshitflag(void)
{
    gStatuses3[gBattlerTarget] &= ~(STATUS3_ALWAYS_HITS);
    gStatuses3[gBattlerTarget] |= 0x10;
    gDisableStructs[gBattlerTarget].battlerWithSureHit = gBattlerAttacker;
    gBattlescriptCurrInstr++;
}

static void atkA8_copymovepermanently(void) // sketch
{
    gChosenMove = 0xFFFF;

    if (!(gBattleMons[gBattlerAttacker].status2 & STATUS2_TRANSFORMED)
        && gLastPrintedMoves[gBattlerTarget] != MOVE_STRUGGLE
        && gLastPrintedMoves[gBattlerTarget] != 0
        && gLastPrintedMoves[gBattlerTarget] != 0xFFFF
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
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
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

            BtlController_EmitSetMonData(0, REQUEST_MOVES_PP_BATTLE, 0, sizeof(struct MovePpInfo), &movePpData);
            MarkBattlerForControllerExec(gActiveBattler);

            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastPrintedMoves[gBattlerTarget])

            gBattlescriptCurrInstr += 5;
        }
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static bool8 IsTwoTurnsMove(u16 move)
{
    if (gBattleMoves[move].effect == EFFECT_SKULL_BASH
        || gBattleMoves[move].effect == EFFECT_TWO_TURNS_ATTACK
        || gBattleMoves[move].effect == EFFECT_SOLARBEAM
        || gBattleMoves[move].effect == EFFECT_SEMI_INVULNERABLE
        || gBattleMoves[move].effect == EFFECT_BIDE)
        return TRUE;
    else
        return FALSE;
}

static bool8 IsInvalidForSleepTalkOrAssist(u16 move)
{
    if (move == 0 || move == MOVE_SLEEP_TALK || move == MOVE_ASSIST
        || move == MOVE_MIRROR_MOVE || move == MOVE_METRONOME)
        return TRUE;
    else
        return FALSE;
}

static u8 AttacksThisTurn(u8 battlerId, u16 move) // Note: returns 1 if it's a charging turn, otherwise 2
{
    // first argument is unused
    if (gBattleMoves[move].effect == EFFECT_SOLARBEAM
        && (gBattleWeather & WEATHER_SUN_ANY))
        return 2;

    if (gBattleMoves[move].effect == EFFECT_SKULL_BASH
        || gBattleMoves[move].effect == EFFECT_TWO_TURNS_ATTACK
        || gBattleMoves[move].effect == EFFECT_SOLARBEAM
        || gBattleMoves[move].effect == EFFECT_SEMI_INVULNERABLE
        || gBattleMoves[move].effect == EFFECT_BIDE)
    {
        if ((gHitMarker & HITMARKER_CHARGING))
            return 1;
    }
    return 2;
}

static void atkA9_trychoosesleeptalkmove(void)
{
    s32 i;
    u8 unusableMovesBits = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (IsInvalidForSleepTalkOrAssist(gBattleMons[gBattlerAttacker].moves[i])
            || gBattleMons[gBattlerAttacker].moves[i] == MOVE_FOCUS_PUNCH
            || gBattleMons[gBattlerAttacker].moves[i] == MOVE_UPROAR
            || IsTwoTurnsMove(gBattleMons[gBattlerAttacker].moves[i]))
        {
            unusableMovesBits |= gBitTable[i];
        }

    }

    unusableMovesBits = CheckMoveLimitations(gBattlerAttacker, unusableMovesBits, ~(MOVE_LIMITATION_PP));
    if (unusableMovesBits == 0xF) // all 4 moves cannot be chosen
    {
        gBattlescriptCurrInstr += 5;
    }
    else // at least one move can be chosen
    {
        u32 movePosition;

        do
        {
            movePosition = Random() & 3;
        } while ((gBitTable[movePosition] & unusableMovesBits));

        gCalledMove = gBattleMons[gBattlerAttacker].moves[movePosition];
        gCurrMovePos = movePosition;
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gBattlerTarget = GetMoveTarget(gCalledMove, 0);
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkAA_setdestinybond(void)
{
    gBattleMons[gBattlerAttacker].status2 |= STATUS2_DESTINY_BOND;
    gBattlescriptCurrInstr++;
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

static void atkAB_trysetdestinybondtohappen(void)
{
    TrySetDestinyBondToHappen();
    gBattlescriptCurrInstr++;
}

static void atkAC_settailwind(void)
{
    u8 side = GetBattlerSide(gBattlerAttacker);

    if (!(gSideStatuses[side] & SIDE_STATUS_TAILWIND))
    {
        gSideStatuses[side] |= SIDE_STATUS_TAILWIND;
        gSideTimers[side].tailwindBattlerId = gBattlerAttacker;
        gSideTimers[side].tailwindTimer = 3;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkAD_tryspiteppreduce(void)
{
    if (gLastMoves[gBattlerTarget] != 0
        && gLastMoves[gBattlerTarget] != 0xFFFF)
    {
        s32 i;

        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gLastMoves[gBattlerTarget] == gBattleMons[gBattlerTarget].moves[i])
                break;
        }

        if (i != MAX_MON_MOVES && gBattleMons[gBattlerTarget].pp[i] > 1)
        {
            s32 ppToDeduct = (Random() & 3) + 2;
            if (gBattleMons[gBattlerTarget].pp[i] < ppToDeduct)
                ppToDeduct = gBattleMons[gBattlerTarget].pp[i];

            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastMoves[gBattlerTarget])

            ConvertIntToDecimalStringN(gBattleTextBuff2, ppToDeduct, 0, 1);

            PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 1, ppToDeduct)

            gBattleMons[gBattlerTarget].pp[i] -= ppToDeduct;
            gActiveBattler = gBattlerTarget;

            if (!(gDisableStructs[gActiveBattler].mimickedMoves & gBitTable[i])
                && !(gBattleMons[gActiveBattler].status2 & STATUS2_TRANSFORMED))
            {
                BtlController_EmitSetMonData(0, REQUEST_PPMOVE1_BATTLE + i, 0, 1, &gBattleMons[gActiveBattler].pp[i]);
                MarkBattlerForControllerExec(gActiveBattler);
            }

            gBattlescriptCurrInstr += 5;

            if (gBattleMons[gBattlerTarget].pp[i] == 0)
                CancelMultiTurnMoves(gBattlerTarget);
        }
        else
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        }
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkAE_healpartystatus(void)
{
    u32 zero = 0;
    u8 toHeal = 0;

    if (gCurrentMove == MOVE_HEAL_BELL)
    {
        struct Pokemon *party;
        s32 i;

        gBattleCommunication[MULTISTRING_CHOOSER] = 0;

        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
            party = gPlayerParty;
        else
            party = gEnemyParty;

        if (gBattleMons[gBattlerAttacker].ability != ABILITY_SOUNDPROOF)
        {
            gBattleMons[gBattlerAttacker].status1 = 0;
            gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_NIGHTMARE);
        }
        else
        {
            RecordAbilityBattle(gBattlerAttacker, gBattleMons[gBattlerAttacker].ability);
            gBattleCommunication[MULTISTRING_CHOOSER] |= 1;
        }

        gActiveBattler = gBattleScripting.battler = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_FLANK);

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
            && !(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
        {
            if (gBattleMons[gActiveBattler].ability != ABILITY_SOUNDPROOF)
            {
                gBattleMons[gActiveBattler].status1 = 0;
                gBattleMons[gActiveBattler].status2 &= ~(STATUS2_NIGHTMARE);
            }
            else
            {
                RecordAbilityBattle(gActiveBattler, gBattleMons[gActiveBattler].ability);
                gBattleCommunication[MULTISTRING_CHOOSER] |= 2;
            }
        }

        for (i = 0; i < PARTY_SIZE; i++)
        {
            u16 species = GetMonData(&party[i], MON_DATA_SPECIES2);
            u8 abilityBit = GetMonData(&party[i], MON_DATA_ALT_ABILITY);

            if (species != SPECIES_NONE && species != SPECIES_EGG)
            {
                u8 ability;

                if (gBattlerPartyIndexes[gBattlerAttacker] == i)
                    ability = gBattleMons[gBattlerAttacker].ability;
                else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                         && gBattlerPartyIndexes[gActiveBattler] == i
                         && !(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
                    ability = gBattleMons[gActiveBattler].ability;
                else
                    ability = GetAbilityBySpecies(species, abilityBit);

                if (ability != ABILITY_SOUNDPROOF)
                    toHeal |= (1 << i);
            }
        }
    }
    else // Aromatherapy
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = 4;
        toHeal = 0x3F;

        gBattleMons[gBattlerAttacker].status1 = 0;
        gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_NIGHTMARE);

        gActiveBattler = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_FLANK);
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
            && !(gAbsentBattlerFlags & gBitTable[gActiveBattler]))
        {
            gBattleMons[gActiveBattler].status1 = 0;
            gBattleMons[gActiveBattler].status2 &= ~(STATUS2_NIGHTMARE);
        }

    }

    if (toHeal)
    {
        gActiveBattler = gBattlerAttacker;
        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, toHeal, 4, &zero);
        MarkBattlerForControllerExec(gActiveBattler);
    }

    gBattlescriptCurrInstr++;
}

static void atkAF_cursetarget(void)
{
    if (gBattleMons[gBattlerTarget].status2 & STATUS2_CURSED)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gBattleMons[gBattlerTarget].status2 |= STATUS2_CURSED;
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattlescriptCurrInstr += 5;
    }
}

static void atkB0_trysetspikes(void)
{
    u8 targetSide = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;

    if (gSideTimers[targetSide].spikesAmount == 3)
    {
        gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = 1;
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gSideStatuses[targetSide] |= SIDE_STATUS_SPIKES;
        gSideTimers[targetSide].spikesAmount++;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkB1_setforesight(void)
{
    gBattleMons[gBattlerTarget].status2 |= STATUS2_FORESIGHT;
    gBattlescriptCurrInstr++;
}

static void atkB2_trysetperishsong(void)
{
    s32 i;
    s32 notAffectedCount = 0;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gStatuses3[i] & STATUS3_PERISH_SONG
            || gBattleMons[i].ability == ABILITY_SOUNDPROOF)
        {
            notAffectedCount++;
        }
        else
        {
            gStatuses3[i] |= STATUS3_PERISH_SONG;
            gDisableStructs[i].perishSongTimer = 3;
            gDisableStructs[i].perishSongTimerStartValue = 3;
        }
    }

    PressurePPLoseOnUsingPerishSong(gBattlerAttacker);

    if (notAffectedCount == gBattlersCount)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atkB3_handlerollout(void)
{
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
            gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_MULTIPLETURNS);
        }

        gBattlescriptCurrInstr++;
    }
}

static void atkB4_jumpifconfusedandstatmaxed(void)
{
    if (gBattleMons[gBattlerTarget].status2 & STATUS2_CONFUSION
        && gBattleMons[gBattlerTarget].statStages[gBattlescriptCurrInstr[1]] == 0xC)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
    else
        gBattlescriptCurrInstr += 6;
}

static void atkB5_handlefurycutter(void)
{
    if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
    {
        gDisableStructs[gBattlerAttacker].furyCutterCounter = 0;
        gBattlescriptCurrInstr = BattleScript_MoveMissedPause;
    }
    else
    {
        if (gDisableStructs[gBattlerAttacker].furyCutterCounter != 5)
            gDisableStructs[gBattlerAttacker].furyCutterCounter++;

        gBattlescriptCurrInstr++;
    }
}

static void atkB6_setembargo(void)
{
    if (gStatuses3[gBattlerTarget] & STATUS3_EMBARGO)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gStatuses3[gBattlerTarget] |= STATUS3_EMBARGO;
        gDisableStructs[gBattlerTarget].embargoTimer = 5;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkB7_presentdamagecalculation(void)
{
    u32 rand = Random() & 0xFF;

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
    }

    if (rand < 204)
    {
        gBattlescriptCurrInstr = BattleScript_HitFromCritCalc;
    }
    else if (gBattleMons[gBattlerTarget].maxHP == gBattleMons[gBattlerTarget].hp)
    {
        gBattlescriptCurrInstr = BattleScript_AlreadyAtFullHp;
    }
    else
    {
        gMoveResultFlags &= ~(MOVE_RESULT_DOESNT_AFFECT_FOE);
        gBattlescriptCurrInstr = BattleScript_PresentHealTarget;
    }
}

static void atkB8_setsafeguard(void)
{
    if (gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] & SIDE_STATUS_SAFEGUARD)
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gSideStatuses[GET_BATTLER_SIDE(gBattlerAttacker)] |= SIDE_STATUS_SAFEGUARD;
        gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].safeguardTimer = 5;
        gSideTimers[GET_BATTLER_SIDE(gBattlerAttacker)].safeguardBattlerId = gBattlerAttacker;
        gBattleCommunication[MULTISTRING_CHOOSER] = 5;
    }

    gBattlescriptCurrInstr++;
}

static void atkB9_magnitudedamagecalculation(void)
{
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


    PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 2, magnitude);

    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (gBattlerTarget == gBattlerAttacker)
            continue;
        if (!(gAbsentBattlerFlags & gBitTable[gBattlerTarget])) // A valid target was found.
            break;
    }

    gBattlescriptCurrInstr++;
}

static void atkBA_jumpifnopursuitswitchdmg(void)
{
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
                gActionsByTurnOrder[i] = 11;
        }

        gCurrentMove = MOVE_PURSUIT;
        gCurrMovePos = gChosenMovePos = *(gBattleStruct->chosenMovePositions + gBattlerTarget);
        gBattlescriptCurrInstr += 5;
        gBattleScripting.animTurn = 1;
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkBB_setsunny(void)
{
    if (!TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_SUN, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = 4;
    }

    gBattlescriptCurrInstr++;
}

static void atkBC_maxattackhalvehp(void) // belly drum
{
    u32 halfHp = gBattleMons[gBattlerAttacker].maxHP / 2;

    if (!(gBattleMons[gBattlerAttacker].maxHP / 2))
        halfHp = 1;

    if (gBattleMons[gBattlerAttacker].statStages[STAT_ATK] < 12
        && gBattleMons[gBattlerAttacker].hp > halfHp)
    {
        gBattleMons[gBattlerAttacker].statStages[STAT_ATK] = 12;
        gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkBD_copyfoestats(void) // psych up
{
    s32 i;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
    {
        gBattleMons[gBattlerAttacker].statStages[i] = gBattleMons[gBattlerTarget].statStages[i];
    }

    gBattlescriptCurrInstr += 5; // Has an unused jump ptr(possibly for a failed attempt) parameter.
}

static void atkBE_rapidspinfree(void)
{
    u8 atkSide = GetBattlerSide(gBattlerAttacker);

    if (gBattleMons[gBattlerAttacker].status2 & STATUS2_WRAPPED)
    {
        gBattleScripting.battler = gBattlerTarget;
        gBattleMons[gBattlerAttacker].status2 &= ~(STATUS2_WRAPPED);
        gBattlerTarget = *(gBattleStruct->wrappedBy + gBattlerAttacker);
        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleStruct->wrappedMove[gBattlerAttacker]);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_WrapFree;
    }
    else if (gStatuses3[gBattlerAttacker] & STATUS3_LEECHSEED)
    {
        gStatuses3[gBattlerAttacker] &= ~(STATUS3_LEECHSEED);
        gStatuses3[gBattlerAttacker] &= ~(STATUS3_LEECHSEED_BATTLER);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_LeechSeedFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_SPIKES)
    {
        gSideStatuses[atkSide] &= ~(SIDE_STATUS_SPIKES);
        gSideTimers[atkSide].spikesAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SpikesFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_TOXIC_SPIKES)
    {
        gSideStatuses[atkSide] &= ~(SIDE_STATUS_TOXIC_SPIKES);
        gSideTimers[atkSide].toxicSpikesAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_ToxicSpikesFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_STICKY_WEB)
    {
        gSideStatuses[atkSide] &= ~(SIDE_STATUS_STICKY_WEB);
        gSideTimers[atkSide].stickyWebAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_StickyWebFree;
    }
    else if (gSideStatuses[atkSide] & SIDE_STATUS_STEALTH_ROCK)
    {
        gSideStatuses[atkSide] &= ~(SIDE_STATUS_STEALTH_ROCK);
        gSideTimers[atkSide].stealthRockAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_StealthRockFree;
    }
    else
    {
        gBattlescriptCurrInstr++;
    }
}

static void atkBF_setdefensecurlbit(void)
{
    gBattleMons[gBattlerAttacker].status2 |= STATUS2_DEFENSE_CURL;
    gBattlescriptCurrInstr++;
}

static void atkC0_recoverbasedonsunlight(void)
{
    gBattlerTarget = gBattlerAttacker;

    if (gBattleMons[gBattlerAttacker].hp != gBattleMons[gBattlerAttacker].maxHP)
    {
        if (gBattleWeather == 0 || !WEATHER_HAS_EFFECT)
            gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 2;
        else if (gBattleWeather & WEATHER_SUN_ANY)
            gBattleMoveDamage = 20 * gBattleMons[gBattlerAttacker].maxHP / 30;
        else // not sunny weather
            gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 4;

        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkC1_setstickyweb(void)
{
    u8 targetSide = GetBattlerSide(gBattlerTarget);
    if (gSideStatuses[targetSide] & SIDE_STATUS_STICKY_WEB)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gSideStatuses[targetSide] |= SIDE_STATUS_STICKY_WEB;
        gSideTimers[targetSide].stickyWebAmount = 1;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkC2_selectfirstvalidtarget(void)
{
    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (gBattlerTarget == gBattlerAttacker && !(gBattleMoves[gCurrentMove].target & MOVE_TARGET_USER))
            continue;
        if (!(gAbsentBattlerFlags & gBitTable[gBattlerTarget]))
            break;
    }
    gBattlescriptCurrInstr++;
}

static void atkC3_trysetfutureattack(void)
{
    if (gWishFutureKnock.futureSightCounter[gBattlerTarget] != 0)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gSideStatuses[GET_BATTLER_SIDE(gBattlerTarget)] |= SIDE_STATUS_FUTUREATTACK;
        gWishFutureKnock.futureSightMove[gBattlerTarget] = gCurrentMove;
        gWishFutureKnock.futureSightAttacker[gBattlerTarget] = gBattlerAttacker;
        gWishFutureKnock.futureSightCounter[gBattlerTarget] = 3;

        if (gCurrentMove == MOVE_DOOM_DESIRE)
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;

        gBattlescriptCurrInstr += 5;
    }
}

static void atkC4_trydobeatup(void)
{
    struct Pokemon *party;

    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleMons[gBattlerTarget].hp == 0)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        u8 beforeLoop = gBattleCommunication[0];
        for (;gBattleCommunication[0] < 6; gBattleCommunication[0]++)
        {
            if (GetMonData(&party[gBattleCommunication[0]], MON_DATA_HP)
                && GetMonData(&party[gBattleCommunication[0]], MON_DATA_SPECIES2)
                && GetMonData(&party[gBattleCommunication[0]], MON_DATA_SPECIES2) != SPECIES_EGG
                && !GetMonData(&party[gBattleCommunication[0]], MON_DATA_STATUS))
                    break;
        }
        if (gBattleCommunication[0] < 6)
        {
            PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattleCommunication[0])

            gBattlescriptCurrInstr += 9;

            gBattleMoveDamage = gBaseStats[GetMonData(&party[gBattleCommunication[0]], MON_DATA_SPECIES)].baseAttack;
            gBattleMoveDamage *= gBattleMoves[gCurrentMove].power;
            gBattleMoveDamage *= (GetMonData(&party[gBattleCommunication[0]], MON_DATA_LEVEL) * 2 / 5 + 2);
            gBattleMoveDamage /= gBaseStats[gBattleMons[gBattlerTarget].species].baseDefense;
            gBattleMoveDamage = (gBattleMoveDamage / 50) + 2;
            if (gProtectStructs[gBattlerAttacker].helpingHand)
                gBattleMoveDamage = gBattleMoveDamage * 15 / 10;

            gBattleCommunication[0]++;
        }
        else if (beforeLoop != 0)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        else
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 5);
    }
}

static void atkC5_setsemiinvulnerablebit(void)
{
    switch (gCurrentMove)
    {
    case MOVE_FLY:
    case MOVE_BOUNCE:
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

    gBattlescriptCurrInstr++;
}

static void atkC6_clearsemiinvulnerablebit(void)
{
    gStatuses3[gBattlerAttacker] &= ~(STATUS3_SEMI_INVULNERABLE);
    gBattlescriptCurrInstr++;
}

static void atkC7_setminimize(void)
{
    if (gHitMarker & HITMARKER_OBEYS)
        gStatuses3[gBattlerAttacker] |= STATUS3_MINIMIZED;

    gBattlescriptCurrInstr++;
}

static void atkC8_sethail(void)
{
    if (!TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_HAIL, FALSE))
    {
        gMoveResultFlags |= MOVE_RESULT_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = 5;
    }

    gBattlescriptCurrInstr++;
}

static void atkC9_jumpifattackandspecialattackcannotfall(void) // memento
{
    if (gBattleMons[gBattlerTarget].statStages[STAT_ATK] == 0
        && gBattleMons[gBattlerTarget].statStages[STAT_SPATK] == 0
        && gBattleCommunication[6] != 1)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gActiveBattler = gBattlerAttacker;
        gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
        BtlController_EmitHealthBarUpdate(0, INSTANT_HP_BAR_DROP);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr += 5;
    }
}

static void atkCA_setforcedtarget(void) // follow me
{
    gSideTimers[GetBattlerSide(gBattlerAttacker)].followmeTimer = 1;
    gSideTimers[GetBattlerSide(gBattlerAttacker)].followmeTarget = gBattlerAttacker;
    gBattlescriptCurrInstr++;
}

static void atkCB_setcharge(void)
{
    gStatuses3[gBattlerAttacker] |= STATUS3_CHARGED_UP;
    gDisableStructs[gBattlerAttacker].chargeTimer = 2;
    gDisableStructs[gBattlerAttacker].chargeTimerStartValue = 2;
    gBattlescriptCurrInstr++;
}

static void atkCC_callterrainattack(void) // nature power
{
    gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
    gCurrentMove = sNaturePowerMoves[gBattleTerrain];
    gBattlerTarget = GetMoveTarget(gCurrentMove, 0);
    BattleScriptPush(gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect]);
    gBattlescriptCurrInstr++;
}

static void atkCD_cureifburnedparalysedorpoisoned(void) // refresh
{
    if (gBattleMons[gBattlerAttacker].status1 & (STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON))
    {
        gBattleMons[gBattlerAttacker].status1 = 0;
        gBattlescriptCurrInstr += 5;
        gActiveBattler = gBattlerAttacker;
        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkCE_settorment(void)
{
    if (gBattleMons[gBattlerTarget].status2 & STATUS2_TORMENT)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gBattleMons[gBattlerTarget].status2 |= STATUS2_TORMENT;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkCF_jumpifnodamage(void)
{
    if (gProtectStructs[gBattlerAttacker].physicalDmg || gProtectStructs[gBattlerAttacker].specialDmg)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

static void atkD0_settaunt(void)
{
    if (gDisableStructs[gBattlerTarget].tauntTimer == 0)
    {
        u8 turns = 4;
        if (GetBattlerTurnOrderNum(gBattlerTarget) > GetBattlerTurnOrderNum(gBattlerAttacker))
            turns--; // If the target hasn't yet moved this turn, Taunt lasts for only three turns (source: Bulbapedia)

        gDisableStructs[gBattlerTarget].tauntTimer = gDisableStructs[gBattlerTarget].tauntTimer2 = turns;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkD1_trysethelpinghand(void)
{
    gBattlerTarget = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_FLANK);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
        && !(gAbsentBattlerFlags & gBitTable[gBattlerTarget])
        && !gProtectStructs[gBattlerAttacker].helpingHand
        && !gProtectStructs[gBattlerTarget].helpingHand)
    {
        gProtectStructs[gBattlerTarget].helpingHand = 1;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkD2_tryswapitems(void) // trick
{
    // opponent can't swap items with player in regular battles
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL
        || (GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT
            && !(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_SECRET_BASE
                                  | BATTLE_TYPE_x2000000))))
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
        u8 sideTarget = GetBattlerSide(gBattlerTarget);

        // you can't swap items if they were knocked off in regular battles
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                             | BATTLE_TYPE_EREADER_TRAINER
                             | BATTLE_TYPE_FRONTIER
                             | BATTLE_TYPE_SECRET_BASE
                             | BATTLE_TYPE_x2000000))
            && (gWishFutureKnock.knockedOffMons[sideAttacker] & gBitTable[gBattlerPartyIndexes[gBattlerAttacker]]
                || gWishFutureKnock.knockedOffMons[sideTarget] & gBitTable[gBattlerPartyIndexes[gBattlerTarget]]))
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        }
        // can't swap if two pokemon don't have an item
        // or if either of them is an enigma berry or a mail
        else if ((gBattleMons[gBattlerAttacker].item == 0 && gBattleMons[gBattlerTarget].item == 0)
                 || !CanBattlerGetOrLoseItem(gBattlerAttacker, gBattleMons[gBattlerAttacker].item)
                 || !CanBattlerGetOrLoseItem(gBattlerAttacker, gBattleMons[gBattlerTarget].item)
                 || !CanBattlerGetOrLoseItem(gBattlerTarget, gBattleMons[gBattlerTarget].item)
                 || !CanBattlerGetOrLoseItem(gBattlerTarget, gBattleMons[gBattlerAttacker].item))
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        }
        // check if ability prevents swapping
        else if (gBattleMons[gBattlerTarget].ability == ABILITY_STICKY_HOLD)
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

            gBattleMons[gBattlerAttacker].item = 0;
            gBattleMons[gBattlerTarget].item = oldItemAtk;

            gActiveBattler = gBattlerAttacker;
            BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, newItemAtk);
            MarkBattlerForControllerExec(gBattlerAttacker);

            gActiveBattler = gBattlerTarget;
            BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gBattlerTarget].item);
            MarkBattlerForControllerExec(gBattlerTarget);

            gBattleStruct->choicedMove[gBattlerTarget] = 0;
            gBattleStruct->choicedMove[gBattlerAttacker] = 0;

            gBattlescriptCurrInstr += 5;

            PREPARE_ITEM_BUFFER(gBattleTextBuff1, *newItemAtk)
            PREPARE_ITEM_BUFFER(gBattleTextBuff2, oldItemAtk)

            if (oldItemAtk != 0 && *newItemAtk != 0)
                gBattleCommunication[MULTISTRING_CHOOSER] = 2; // attacker's item -> <- target's item
            else if (oldItemAtk == 0 && *newItemAtk != 0)
                gBattleCommunication[MULTISTRING_CHOOSER] = 0; // nothing -> <- target's item
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 1; // attacker's item -> <- nothing
        }
    }
}

static void atkD3_trycopyability(void) // role play
{
    if (gBattleMons[gBattlerTarget].ability != 0
        && gBattleMons[gBattlerTarget].ability != ABILITY_WONDER_GUARD)
    {
        gBattleMons[gBattlerAttacker].ability = gBattleMons[gBattlerTarget].ability;
        gLastUsedAbility = gBattleMons[gBattlerTarget].ability;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkD4_trywish(void)
{
    switch (gBattlescriptCurrInstr[1])
    {
    case 0: // use wish
        if (gWishFutureKnock.wishCounter[gBattlerAttacker] == 0)
        {
            gWishFutureKnock.wishCounter[gBattlerAttacker] = 2;
            gWishFutureKnock.wishMonId[gBattlerAttacker] = gBattlerPartyIndexes[gBattlerAttacker];
            gBattlescriptCurrInstr += 6;
        }
        else
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        }
        break;
    case 1: // heal effect
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gBattlerTarget, gWishFutureKnock.wishMonId[gBattlerTarget])

        gBattleMoveDamage = gBattleMons[gBattlerTarget].maxHP / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        if (gBattleMons[gBattlerTarget].hp == gBattleMons[gBattlerTarget].maxHP)
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;

        break;
    }
}

static void atkD5_settoxicspikes(void)
{
    u8 targetSide = GetBattlerSide(gBattlerTarget);
    if (gSideTimers[targetSide].toxicSpikesAmount >= 2)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gSideTimers[targetSide].toxicSpikesAmount++;
        gSideStatuses[targetSide] |= SIDE_STATUS_TOXIC_SPIKES;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkD6_setgastroacid(void)
{
    switch (gBattleMons[gBattlerTarget].ability)
    {
    case ABILITY_MULTITYPE:
    case ABILITY_STANCE_CHANGE:
    case ABILITY_SCHOOLING:
    case ABILITY_COMATOSE:
    case ABILITY_SHIELDS_DOWN:
    case ABILITY_DISGUISE:
    case ABILITY_RKS_SYSTEM:
    case ABILITY_BATTLE_BOND:
    case ABILITY_POWER_CONSTRUCT:
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        break;
    default:
        gStatuses3[gBattlerTarget] |= STATUS3_GASTRO_ACID;
        gBattlescriptCurrInstr += 5;
        break;
    }
}

static void atkD7_setyawn(void)
{
    if (gStatuses3[gBattlerTarget] & STATUS3_YAWN
        || gBattleMons[gBattlerTarget].status1 & STATUS1_ANY)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gStatuses3[gBattlerTarget] |= 0x1000;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkD8_setdamagetohealthdifference(void)
{
    if (gBattleMons[gBattlerTarget].hp <= gBattleMons[gBattlerAttacker].hp)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBattlerTarget].hp - gBattleMons[gBattlerAttacker].hp;
        gBattlescriptCurrInstr += 5;
    }
}

static void HandleRoomMove(u32 statusFlag, u8 *timer, u8 stringId)
{
    if (gFieldStatuses & statusFlag)
    {
        gFieldStatuses &= ~(statusFlag);
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

static void atkD9_setroom(void)
{
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
    gBattlescriptCurrInstr++;
}

static void atkDA_tryswapabilities(void) // skill swap
{
    if ((gBattleMons[gBattlerAttacker].ability == 0
         && gBattleMons[gBattlerTarget].ability == 0)
     || gBattleMons[gBattlerAttacker].ability == ABILITY_WONDER_GUARD
     || gBattleMons[gBattlerTarget].ability == ABILITY_WONDER_GUARD
     || gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
     {
         gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
     }
    else
    {
        u8 abilityAtk = gBattleMons[gBattlerAttacker].ability;
        gBattleMons[gBattlerAttacker].ability = gBattleMons[gBattlerTarget].ability;
        gBattleMons[gBattlerTarget].ability = abilityAtk;

        gBattlescriptCurrInstr += 5;
    }
}

static void atkDB_tryimprison(void)
{
    if ((gStatuses3[gBattlerAttacker] & STATUS3_IMPRISONED_OTHERS))
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
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
                    gBattlescriptCurrInstr += 5;
                    break;
                }
            }
        }
        if (battlerId == gBattlersCount) // In Generation 3 games, Imprison fails if the user doesn't share any moves with any of the foes.
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkDC_setstealthrock(void)
{
    u8 targetSide = GetBattlerSide(gBattlerTarget);
    if (gSideStatuses[targetSide] & SIDE_STATUS_STEALTH_ROCK)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gSideStatuses[targetSide] |= SIDE_STATUS_STEALTH_ROCK;
        gSideTimers[targetSide].stealthRockAmount = 1;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkDD_setuserstatus3(void)
{
    u32 flags = T1_READ_32(gBattlescriptCurrInstr + 1);

    if (gStatuses3[gBattlerAttacker] & flags)
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 5);
    }
    else
    {
        gStatuses3[gBattlerAttacker] |= flags;
        if (flags & STATUS3_MAGNET_RISE)
            gDisableStructs[gBattlerAttacker].magnetRiseTimer = 5;
        if (flags & STATUS3_LASER_FOCUS)
            gDisableStructs[gBattlerAttacker].laserFocusTimer = 2;
        gBattlescriptCurrInstr += 9;
    }
}

static void atkDE_assistattackselect(void)
{
    s32 chooseableMovesNo = 0;
    struct Pokemon* party;
    s32 monId, moveId;
    u16* movesArray = gBattleStruct->assistPossibleMoves;

    if (GET_BATTLER_SIDE(gBattlerAttacker) != B_SIDE_PLAYER)
        party = gEnemyParty;
    else
        party = gPlayerParty;

    for (monId = 0; monId < PARTY_SIZE; monId++)
    {
        if (monId == gBattlerPartyIndexes[gBattlerAttacker])
            continue;
        if (GetMonData(&party[monId], MON_DATA_SPECIES2) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[monId], MON_DATA_SPECIES2) == SPECIES_EGG)
            continue;

        for (moveId = 0; moveId < MAX_MON_MOVES; moveId++)
        {
            s32 i = 0;
            u16 move = GetMonData(&party[monId], MON_DATA_MOVE1 + moveId);

            if (IsInvalidForSleepTalkOrAssist(move))
                continue;

            for (; sMovesForbiddenToCopy[i] != ASSIST_FORBIDDEN_END && move != sMovesForbiddenToCopy[i]; i++);

            if (sMovesForbiddenToCopy[i] != ASSIST_FORBIDDEN_END)
                continue;
            if (move == MOVE_NONE)
                continue;

            movesArray[chooseableMovesNo] = move;
            chooseableMovesNo++;
        }
    }
    if (chooseableMovesNo)
    {
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gCalledMove = movesArray[((Random() & 0xFF) * chooseableMovesNo) >> 8];
        gBattlerTarget = GetMoveTarget(gCalledMove, 0);
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkDF_trysetmagiccoat(void)
{
    gBattlerTarget = gBattlerAttacker;
    gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = 1;
    if (gCurrentTurnActionNumber == gBattlersCount - 1) // moves last turn
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gProtectStructs[gBattlerAttacker].bounceMove = 1;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkE0_trysetsnatch(void) // snatch
{
    gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = 1;
    if (gCurrentTurnActionNumber == gBattlersCount - 1) // moves last turn
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gProtectStructs[gBattlerAttacker].stealMove = 1;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkE1_trygetintimidatetarget(void)
{
    u8 side;

    gBattleScripting.battler = gBattleStruct->intimidateBattler;
    side = GetBattlerSide(gBattleScripting.battler);

    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gBattleMons[gBattleScripting.battler].ability)

    for (;gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (GetBattlerSide(gBattlerTarget) == side)
            continue;
        if (!(gAbsentBattlerFlags & gBitTable[gBattlerTarget]))
            break;
    }

    if (gBattlerTarget >= gBattlersCount)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atkE2_switchoutabilities(void)
{
    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    switch (GetBattlerAbility(gActiveBattler))
    {
    case ABILITY_NATURAL_CURE:
        gBattleMons[gActiveBattler].status1 = 0;
        BtlController_EmitSetMonData(0, REQUEST_STATUS_BATTLE, gBitTable[*(gBattleStruct->field_58 + gActiveBattler)], 4, &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    case ABILITY_REGENERATOR:
        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 3;
        gBattleMoveDamage += gBattleMons[gActiveBattler].hp;
        if (gBattleMoveDamage > gBattleMons[gActiveBattler].maxHP)
            gBattleMons[gActiveBattler].maxHP = gBattleMons[gActiveBattler].maxHP;
        BtlController_EmitSetMonData(0, REQUEST_HP_BATTLE, gBitTable[*(gBattleStruct->field_58 + gActiveBattler)], 2, &gBattleMoveDamage);
        MarkBattlerForControllerExec(gActiveBattler);
        break;
    }

    gBattlescriptCurrInstr += 2;
}

static void atkE3_jumpifhasnohp(void)
{
    gActiveBattler = GetBattlerForBattleScript(gBattlescriptCurrInstr[1]);

    if (gBattleMons[gActiveBattler].hp == 0)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 2);
    else
        gBattlescriptCurrInstr += 6;
}

static void atkE4_getsecretpowereffect(void)
{
    switch (gBattleTerrain)
    {
    case BATTLE_TERRAIN_GRASS:
        gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
        break;
    case BATTLE_TERRAIN_LONG_GRASS:
        gBattleScripting.moveEffect = MOVE_EFFECT_SLEEP;
        break;
    case BATTLE_TERRAIN_SAND:
        gBattleScripting.moveEffect = MOVE_EFFECT_ACC_MINUS_1;
        break;
    case BATTLE_TERRAIN_UNDERWATER:
        gBattleScripting.moveEffect = MOVE_EFFECT_DEF_MINUS_1;
        break;
    case BATTLE_TERRAIN_WATER:
        gBattleScripting.moveEffect = MOVE_EFFECT_ATK_MINUS_1;
        break;
    case BATTLE_TERRAIN_POND:
        gBattleScripting.moveEffect = MOVE_EFFECT_SPD_MINUS_1;
        break;
    case BATTLE_TERRAIN_MOUNTAIN:
        gBattleScripting.moveEffect = MOVE_EFFECT_CONFUSION;
        break;
    case BATTLE_TERRAIN_CAVE:
        gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
        break;
    default:
        gBattleScripting.moveEffect = MOVE_EFFECT_PARALYSIS;
        break;
    }
    gBattlescriptCurrInstr++;
}

static void atkE5_pickup(void)
{
    s32 i;
    u16 species, heldItem;
    u8 ability;
    u8 lvlDivBy10;

    if (InBattlePike())
    {

    }
    else if (InBattlePyramid())
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            heldItem = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);

            if (GetMonData(&gPlayerParty[i], MON_DATA_ALT_ABILITY))
                ability = gBaseStats[species].ability2;
            else
                ability = gBaseStats[species].ability1;

            if (ability == ABILITY_PICKUP
                && species != 0
                && species != SPECIES_EGG
                && heldItem == ITEM_NONE
                && (Random() % 10) == 0)
            {
                heldItem = GetBattlePyramidPickupItemId();
                SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &heldItem);
            }
        }
    }
    else
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            heldItem = GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM);
            lvlDivBy10 = (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL)-1) / 10; //Moving this here makes it easier to add in abilities like Honey Gather
            if (lvlDivBy10 > 9)
                lvlDivBy10 = 9;

            if (GetMonData(&gPlayerParty[i], MON_DATA_ALT_ABILITY))
                ability = gBaseStats[species].ability2;
            else
                ability = gBaseStats[species].ability1;

            if (ability == ABILITY_PICKUP
                && species != 0
                && species != SPECIES_EGG
                && heldItem == ITEM_NONE
                && (Random() % 10) == 0)
            {
                s32 j;
                s32 rand = Random() % 100;

                for (j = 0; j < 9; j++)
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
    }

    gBattlescriptCurrInstr++;
}

static void atkE6_docastformchangeanimation(void)
{
    gActiveBattler = gBattleScripting.battler;

    if (gBattleMons[gActiveBattler].status2 & STATUS2_SUBSTITUTE)
        *(&gBattleStruct->formToChangeInto) |= 0x80;

    BtlController_EmitBattleAnimation(0, B_ANIM_CASTFORM_CHANGE, gBattleStruct->formToChangeInto);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr++;
}

static void atkE7_trycastformdatachange(void)
{
    u8 form;

    gBattlescriptCurrInstr++;
    form = CastformDataTypeChange(gBattleScripting.battler);
    if (form)
    {
        BattleScriptPushCursorAndCallback(BattleScript_CastformChange);
        *(&gBattleStruct->formToChangeInto) = form - 1;
    }
}

static void atkE8_settypebasedhalvers(void) // water and mud sport
{
    bool8 worked = FALSE;

    if (gBattleMoves[gCurrentMove].effect == EFFECT_MUD_SPORT)
    {
        if (!(gFieldStatuses & STATUS_FIELD_MUDSPORT))
        {
            gFieldStatuses |= STATUS_FIELD_MUDSPORT;
            gFieldTimers.mudSportTimer = 5;
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            worked = TRUE;
        }
    }
    else // water sport
    {
        if (!(gFieldStatuses & STATUS_FIELD_WATERSPORT))
        {
            gFieldStatuses |= STATUS_FIELD_WATERSPORT;
            gFieldTimers.waterSportTimer = 5;
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            worked = TRUE;
        }
    }

    if (worked)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
}

bool32 DoesSubstituteBlockMove(u8 battlerAtk, u8 battlerDef, u32 move)
{
    if (!(gBattleMons[battlerDef].status2 & STATUS2_SUBSTITUTE))
        return FALSE;
    else if (gBattleMoves[move].flags & FLAG_SOUND && B_SOUND_SUBSTITUTE >= GEN_6)
        return FALSE;
    else if (GetBattlerAbility(battlerAtk) == ABILITY_INFILTRATOR)
        return FALSE;
    else
        return TRUE;
}

static void atkE9_jumpifsubstituteblocks(void)
{
    if (DoesSubstituteBlockMove(gBattlerAttacker, gBattlerTarget, gCurrentMove))
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atkEA_tryrecycleitem(void)
{
    u16 *usedHeldItem;

    gActiveBattler = gBattlerAttacker;
    usedHeldItem = &gBattleStruct->usedHeldItems[gActiveBattler];
    if (*usedHeldItem != 0 && gBattleMons[gActiveBattler].item == 0)
    {
        gLastUsedItem = *usedHeldItem;
        *usedHeldItem = 0;
        gBattleMons[gActiveBattler].item = gLastUsedItem;

        BtlController_EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gActiveBattler].item);
        MarkBattlerForControllerExec(gActiveBattler);

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkEB_settypetoterrain(void)
{
    if (!IS_BATTLER_OF_TYPE(gBattlerAttacker, sTerrainToType[gBattleTerrain]))
    {
        SET_BATTLER_TYPE(gBattlerAttacker, sTerrainToType[gBattleTerrain]);
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, sTerrainToType[gBattleTerrain]);

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkEC_pursuitrelated(void)
{
    gActiveBattler = GetBattlerAtPosition(GetBattlerPosition(gBattlerAttacker) ^ BIT_FLANK);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
        && !(gAbsentBattlerFlags & gBitTable[gActiveBattler])
        && gChosenActionByBattler[gActiveBattler] == 0
        && gChosenMoveByBattler[gActiveBattler] == MOVE_PURSUIT)
    {
        gActionsByTurnOrder[gActiveBattler] = 11;
        gCurrentMove = MOVE_PURSUIT;
        gBattlescriptCurrInstr += 5;
        gBattleScripting.animTurn = 1;
        gBattleScripting.field_20 = gBattlerAttacker;
        gBattlerAttacker = gActiveBattler;
    }
    else
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}

static void atkEF_snatchsetbattlers(void)
{
    gEffectBattler = gBattlerAttacker;

    if (gBattlerAttacker == gBattlerTarget)
        gBattlerAttacker = gBattlerTarget = gBattleScripting.battler;
    else
        gBattlerTarget = gBattleScripting.battler;

    gBattleScripting.battler = gEffectBattler;
    gBattlescriptCurrInstr++;
}

static void atkEE_removelightscreenreflect(void) // brick break
{
    u8 opposingSide = GetBattlerSide(gBattlerAttacker) ^ BIT_SIDE;

    if (gSideTimers[opposingSide].reflectTimer || gSideTimers[opposingSide].lightscreenTimer)
    {
        gSideStatuses[opposingSide] &= ~(SIDE_STATUS_REFLECT);
        gSideStatuses[opposingSide] &= ~(SIDE_STATUS_LIGHTSCREEN);
        gSideTimers[opposingSide].reflectTimer = 0;
        gSideTimers[opposingSide].lightscreenTimer = 0;
        gBattleScripting.animTurn = 1;
        gBattleScripting.animTargetsHit = 1;
    }
    else
    {
        gBattleScripting.animTurn = 0;
        gBattleScripting.animTargetsHit = 0;
    }

    gBattlescriptCurrInstr++;
}

static u8 GetCatchingBattler(void)
{
    if (IsBattlerAlive(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)))
        return GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    else
        return GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
}

static void atkEF_handleballthrow(void)
{
    u8 ballMultiplier = 0;

    if (gBattleControllerExecFlags)
        return;

    gActiveBattler = gBattlerAttacker;
    gBattlerTarget = GetCatchingBattler();

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        BtlController_EmitBallThrowAnim(0, BALL_TRAINER_BLOCK);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = BattleScript_TrainerBallBlock;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
    {
        BtlController_EmitBallThrowAnim(0, BALL_3_SHAKES_SUCCESS);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattlescriptCurrInstr = BattleScript_WallyBallThrow;
    }
    else
    {
        u32 odds;
        u8 catchRate;

        if (gLastUsedItem == ITEM_SAFARI_BALL)
            catchRate = gBattleStruct->safariCatchFactor * 1275 / 100;
        else
            catchRate = gBaseStats[gBattleMons[gBattlerTarget].species].catchRate;

        if (gLastUsedItem > ITEM_SAFARI_BALL)
        {
            switch (gLastUsedItem)
            {
            case ITEM_NET_BALL:
                if (IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_WATER) || IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_BUG))
                    ballMultiplier = 30;
                else
                    ballMultiplier = 10;
                break;
            case ITEM_DIVE_BALL:
                if (GetCurrentMapType() == MAP_TYPE_UNDERWATER)
                    ballMultiplier = 35;
                else
                    ballMultiplier = 10;
                break;
            case ITEM_NEST_BALL:
                if (gBattleMons[gBattlerTarget].level < 40)
                {
                    ballMultiplier = 40 - gBattleMons[gBattlerTarget].level;
                    if (ballMultiplier <= 9)
                        ballMultiplier = 10;
                }
                else
                {
                    ballMultiplier = 10;
                }
                break;
            case ITEM_REPEAT_BALL:
                if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gBattlerTarget].species), FLAG_GET_CAUGHT))
                    ballMultiplier = 30;
                else
                    ballMultiplier = 10;
                break;
            case ITEM_TIMER_BALL:
                ballMultiplier = gBattleResults.battleTurnCounter + 10;
                if (ballMultiplier > 40)
                    ballMultiplier = 40;
                break;
            case ITEM_LUXURY_BALL:
            case ITEM_PREMIER_BALL:
                ballMultiplier = 10;
                break;
            }
        }
        else
            ballMultiplier = sBallCatchBonuses[gLastUsedItem - 2];

        odds = (catchRate * ballMultiplier / 10)
            * (gBattleMons[gBattlerTarget].maxHP * 3 - gBattleMons[gBattlerTarget].hp * 2)
            / (3 * gBattleMons[gBattlerTarget].maxHP);

        if (gBattleMons[gBattlerTarget].status1 & (STATUS1_SLEEP | STATUS1_FREEZE))
            odds *= 2;
        if (gBattleMons[gBattlerTarget].status1 & (STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON))
            odds = (odds * 15) / 10;

        if (gLastUsedItem != ITEM_SAFARI_BALL)
        {
            if (gLastUsedItem == ITEM_MASTER_BALL)
            {
                gBattleResults.usedMasterBall = TRUE;
            }
            else
            {
                if (gBattleResults.catchAttempts[gLastUsedItem - ITEM_ULTRA_BALL] < 0xFF)
                    gBattleResults.catchAttempts[gLastUsedItem - ITEM_ULTRA_BALL]++;
            }
        }

        if (odds > 254) // mon caught
        {
            BtlController_EmitBallThrowAnim(0, BALL_3_SHAKES_SUCCESS);
            MarkBattlerForControllerExec(gActiveBattler);
            gBattlescriptCurrInstr = BattleScript_SuccessBallThrow;
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_POKEBALL, &gLastUsedItem);

            if (CalculatePlayerPartyCount() == 6)
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        }
        else // mon may be caught, calculate shakes
        {
            u8 shakes;

            odds = Sqrt(Sqrt(16711680 / odds));
            odds = 1048560 / odds;

            for (shakes = 0; shakes < 4 && Random() < odds; shakes++);

            if (gLastUsedItem == ITEM_MASTER_BALL)
                shakes = BALL_3_SHAKES_SUCCESS; // why calculate the shakes before that check?

            BtlController_EmitBallThrowAnim(0, shakes);
            MarkBattlerForControllerExec(gActiveBattler);

            if (shakes == BALL_3_SHAKES_SUCCESS) // mon caught, copy of the code above
            {
                gBattlescriptCurrInstr = BattleScript_SuccessBallThrow;
                SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_POKEBALL, &gLastUsedItem);

                if (CalculatePlayerPartyCount() == 6)
                    gBattleCommunication[MULTISTRING_CHOOSER] = 0;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            }
            else // not caught
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = shakes;
                gBattlescriptCurrInstr = BattleScript_ShakeBallThrow;
            }
        }
    }
}

static void atkF0_givecaughtmon(void)
{
    if (GiveMonToPlayer(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]]) != MON_GIVEN_TO_PARTY)
    {
        if (!sub_813B21C())
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_STORAGE_UNKNOWN)));
            GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_NICKNAME, gStringVar2);
        }
        else
        {
            StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_STORAGE_UNKNOWN)));
            GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_NICKNAME, gStringVar2);
            StringCopy(gStringVar3, GetBoxNamePtr(get_unknown_box_id()));
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        }

        if (FlagGet(FLAG_SYS_PC_LANETTE))
            gBattleCommunication[MULTISTRING_CHOOSER]++;
    }

    gBattleResults.caughtMonSpecies = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_SPECIES, NULL);
    GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_NICKNAME, gBattleResults.caughtMonNick);
    gBattleResults.caughtMonBall = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_POKEBALL, NULL);

    gBattlescriptCurrInstr++;
}

static void atkF1_trysetcaughtmondexflags(void)
{
    u16 species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_SPECIES, NULL);
    u32 personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_PERSONALITY, NULL);

    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_SET_CAUGHT, personality);
        gBattlescriptCurrInstr += 5;
    }
}

static void atkF2_displaydexinfo(void)
{
    u16 species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[GetCatchingBattler()]], MON_DATA_SPECIES, NULL);

    switch (gBattleCommunication[0])
    {
    case 0:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        gBattleCommunication[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            gBattleCommunication[TASK_ID] = CreateDexDisplayMonDataTask(SpeciesToNationalPokedexNum(species),
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
        sub_80356D0();
        LoadBattleTextboxAndBackground();
        gBattle_BG3_X = 0x100;
        gBattleCommunication[0]++;
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            BeginNormalPaletteFade(0xFFFF, 0, 0x10, 0, RGB_BLACK);
            ShowBg(0);
            ShowBg(3);
            gBattleCommunication[0]++;
        }
        break;
    case 5:
        if (!gPaletteFade.active)
            gBattlescriptCurrInstr++;
        break;
    }
}

void HandleBattleWindow(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags)
{
    s32 destY, destX;
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

            if (flags & WINDOW_x80)
                CopyToBgTilemapBufferRect_ChangePalette(1, &var, destX, destY, 1, 1, 0x11);
            else
                CopyToBgTilemapBufferRect_ChangePalette(0, &var, destX, destY, 1, 1, 0x11);
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

static void atkF3_trygivecaughtmonnick(void)
{
    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        HandleBattleWindow(0x18, 8, 0x1D, 0xD, 0);
        BattlePutTextOnWindow(gText_BattleYesNoChoice, 0xC);
        gBattleCommunication[MULTIUSE_STATE]++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateYesNoCursorAt(0);
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateYesNoCursorAt(0);
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
        }
        if (gMain.newKeys & A_BUTTON)
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
        else if (gMain.newKeys & B_BUTTON)
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
        if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active )
        {
            SetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_NICKNAME, gBattleStruct->caughtMonNick);
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        }
        break;
    case 4:
        if (CalculatePlayerPartyCount() == 6)
            gBattlescriptCurrInstr += 5;
        else
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        break;
    }
}

static void atkF4_subattackerhpbydmg(void)
{
    gBattleMons[gBattlerAttacker].hp -= gBattleMoveDamage;
    gBattlescriptCurrInstr++;
}

static void atkF5_removeattackerstatus1(void)
{
    gBattleMons[gBattlerAttacker].status1 = 0;
    gBattlescriptCurrInstr++;
}

static void atkF6_finishaction(void)
{
    gCurrentActionFuncId = B_ACTION_FINISHED;
}

static void atkF7_finishturn(void)
{
    gCurrentActionFuncId = B_ACTION_FINISHED;
    gCurrentTurnActionNumber = gBattlersCount;
}

static void atkF8_trainerslideout(void)
{
    gActiveBattler = GetBattlerAtPosition(gBattlescriptCurrInstr[1]);
    BtlController_EmitTrainerSlideBack(0);
    MarkBattlerForControllerExec(gActiveBattler);

    gBattlescriptCurrInstr += 2;
}

static void atkF9_settelekinesis(void)
{
    if (gStatuses3[gBattlerTarget] & (STATUS3_TELEKINESIS | STATUS3_ROOTED | STATUS3_SMACKED_DOWN)
        || gFieldStatuses & STATUS_FIELD_GRAVITY
        || (gBattleMons[gBattlerTarget].species == SPECIES_DIGLETT || gBattleMons[gBattlerTarget].species == SPECIES_DUGTRIO))
    {
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gStatuses3[gBattlerTarget] |= STATUS3_TELEKINESIS;
        gDisableStructs[gBattlerTarget].telekinesisTimer = 3;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkFA_swapstatstages(void)
{
    u8 statId = T1_READ_8(gBattlescriptCurrInstr + 1);
    s8 atkStatStage = gBattleMons[gBattlerAttacker].statStages[statId];
    s8 defStatStage = gBattleMons[gBattlerTarget].statStages[statId];

    gBattleMons[gBattlerAttacker].statStages[statId] = defStatStage;
    gBattleMons[gBattlerTarget].statStages[statId] = atkStatStage;

    gBattlescriptCurrInstr += 2;
}

static void atkFB_averagestats(void)
{
    u8 statId = T1_READ_8(gBattlescriptCurrInstr + 1);
    u16 atkStat = *(u16*)((&gBattleMons[gBattlerAttacker].attack) + (statId - 1));
    u16 defStat = *(u16*)((&gBattleMons[gBattlerTarget].attack) + (statId - 1));
    u16 average = (atkStat + defStat) / 2;

    *(u16*)((&gBattleMons[gBattlerAttacker].attack) + (statId - 1)) = average;
    *(u16*)((&gBattleMons[gBattlerTarget].attack) + (statId - 1)) = average;

    gBattlescriptCurrInstr += 2;
}

static void atkFC_jumpifoppositegenders(void)
{
    u32 atkGender = GetGenderFromSpeciesAndPersonality(gBattleMons[gBattlerAttacker].species, gBattleMons[gBattlerAttacker].personality);
    u32 defGender = GetGenderFromSpeciesAndPersonality(gBattleMons[gBattlerTarget].species, gBattleMons[gBattlerTarget].personality);

    if ((atkGender == MON_MALE && defGender == MON_FEMALE) || (atkGender == MON_FEMALE && defGender == MON_MALE))
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atkFD_trygetbaddreamstarget(void)
{
    u8 badDreamsMonSide = GetBattlerSide(gBattlerAttacker);
    for (;gBattlerTarget < gBattlersCount; gBattlerTarget++)
    {
        if (GetBattlerSide(gBattlerTarget) == badDreamsMonSide)
            continue;
        if (gBattleMons[gBattlerTarget].status1 & STATUS1_SLEEP && IsBattlerAlive(gBattlerTarget))
            break;
    }

    if (gBattlerTarget >= gBattlersCount)
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atkFE_tryworryseed(void)
{
    switch (gBattleMons[gBattlerTarget].ability)
    {
    case ABILITY_INSOMNIA:
    case ABILITY_MULTITYPE:
    case ABILITY_TRUANT:
    case ABILITY_STANCE_CHANGE:
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
        break;
    default:
        gBattleMons[gBattlerTarget].ability = ABILITY_INSOMNIA;
        gBattlescriptCurrInstr += 5;
        break;
    }
}

static void atkFF_metalburstdamagecalculator(void)
{
    u8 sideAttacker = GetBattlerSide(gBattlerAttacker);
    u8 sideTarget = 0;

    if (gProtectStructs[gBattlerAttacker].physicalDmg
        && sideAttacker != (sideTarget = GetBattlerSide(gProtectStructs[gBattlerAttacker].physicalBattlerId))
        && gBattleMons[gProtectStructs[gBattlerAttacker].physicalBattlerId].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBattlerAttacker].physicalDmg * 150 / 100;

        if (gSideTimers[sideTarget].followmeTimer && gBattleMons[gSideTimers[sideTarget].followmeTarget].hp)
            gBattlerTarget = gSideTimers[sideTarget].followmeTarget;
        else
            gBattlerTarget = gProtectStructs[gBattlerAttacker].physicalBattlerId;

        gBattlescriptCurrInstr += 5;
    }
    else if (gProtectStructs[gBattlerAttacker].specialDmg
             && sideAttacker != (sideTarget = GetBattlerSide(gProtectStructs[gBattlerAttacker].specialBattlerId))
             && gBattleMons[gProtectStructs[gBattlerAttacker].specialBattlerId].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBattlerAttacker].specialDmg * 150 / 100;

        if (gSideTimers[sideTarget].followmeTimer && gBattleMons[gSideTimers[sideTarget].followmeTarget].hp)
            gBattlerTarget = gSideTimers[sideTarget].followmeTarget;
        else
            gBattlerTarget = gProtectStructs[gBattlerAttacker].specialBattlerId;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gSpecialStatuses[gBattlerAttacker].ppNotAffectedByPressure = 1;
        gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 1);
    }
}
