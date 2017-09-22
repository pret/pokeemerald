#include "global.h"
#include "battle.h"
#include "battle_move_effects.h"
#include "battle_message.h"
#include "battle_ai.h"
#include "moves.h"
#include "abilities.h"
#include "item.h"
#include "items.h"
#include "hold_effects.h"
#include "util.h"
#include "pokemon.h"
#include "calculate_base_damage.h"
#include "rng.h"
#include "battle_controllers.h"
#include "species.h"
#include "songs.h"
#include "text.h"
#include "sound.h"

// variables

extern u8 gCritMultiplier;
extern s32 gBattleMoveDamage;
extern u32 gStatuses3[BATTLE_BANKS_COUNT];
extern u32 gBattleTypeFlags;
extern struct BattleEnigmaBerry gEnigmaBerries[BATTLE_BANKS_COUNT];
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern u8 gActiveBank;
extern u32 gBattleExecBuffer;
extern u8 gNoOfAllBanks;
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gTurnOrder[BATTLE_BANKS_COUNT];
extern u8 gUnknown_02024A76[BATTLE_BANKS_COUNT];
extern u16 gCurrentMove;
extern u8 gLastUsedAbility;
extern u16 gBattleWeather;
extern u8 gStringBank;
extern u8 gEffectBank;
extern u8 gAbsentBankFlags;
extern u8 gMultiHitCounter;
extern u16 gChosenMovesByBanks[BATTLE_BANKS_COUNT];
extern u16 gSideAffecting[2];
extern u16 gPauseCounterBattle;
extern u16 gPaydayMoney;
extern u16 gRandomTurnNumber;
extern u8 gBattleOutcome;
extern u8 gBattleTerrain;
extern u16 gTrainerBattleOpponent;
extern u8 gBankAttacker;
extern u8 gBankTarget;
extern const u8* gBattlescriptCurrInstr;
extern u8 gCurrMovePos;
extern u8 gFightStateTracker;
extern u32 gHitMarker;
extern u8 gBattleMoveFlags;
extern u8 gBattleCommunication[];
extern u16 gUnknown_02024250[4];
extern u16 gUnknown_02024258[4];
extern u8 gStringBank;
extern u16 gDynamicBasePower;
extern u16 gLastUsedItem;
extern u16 gBattleMovePower;
extern s32 gHpDealt;
extern s32 gTakenDmg[BATTLE_BANKS_COUNT];
extern u8 gTakenDmgBanks[BATTLE_BANKS_COUNT];
extern u8 gSentPokesToOpponent[2];
extern u8 gBank1;
extern u16 gExpShareExp;
extern u8 gLeveledUpInBattle;
extern void (*gBattleMainFunc)(void);
extern u8 gPlayerPartyCount;
extern u16 gMoveToLearn;
extern u16 gRandomMove;
extern u8 gBankInMenu;
extern u8 gActionForBanks[BATTLE_BANKS_COUNT];
extern u8 gCurrentMoveTurn;
extern u8 gBattleBufferB[BATTLE_BANKS_COUNT][0x200];
extern u16 gLockedMoves[BATTLE_BANKS_COUNT];
extern u16 gPartnerTrainerId;

extern const struct BattleMove gBattleMoves[];
extern const struct BaseStats gBaseStats[];
extern const u8 gTypeEffectiveness[];
extern const u16 gMissStringIds[];
extern const u16 gTrappingMoves[];
extern const u8 gTrainerMoney[];

// functions
extern void sub_81A5718(u8 bank); // battle frontier 2

// BattleScripts
extern const u8 BattleScript_MoveEnd[];
extern const u8 BattleScript_NoPPForMove[];
extern const u8 BattleScript_MagicCoatBounce[];
extern const u8 BattleScript_TookAttack[];
extern const u8 BattleScript_SnatchedMove[];
extern const u8 BattleScript_Pausex20[];
extern const u8 BattleScript_SubstituteFade[];
extern const u8 BattleScript_HangedOnMsg[];
extern const u8 BattleScript_OneHitKOMsg[];
extern const u8 BattleScript_EnduredMsg[];
extern const u8 BattleScript_PSNPrevention[];
extern const u8 BattleScript_BRNPrevention[];
extern const u8 BattleScript_PRLZPrevention[];
extern const u8 BattleScript_FlinchPrevention[];
extern const u8 BattleScript_StatUp[];
extern const u8 BattleScript_StatDown[];
extern const u8 BattleScript_NoItemSteal[];
extern const u8 BattleScript_ItemSteal[];
extern const u8 BattleScript_RapidSpinAway[];
extern const u8 BattleScript_TargetPRLZHeal[];
extern const u8 BattleScript_KnockedOff[];
extern const u8 BattleScript_StickyHoldOnKnockOff[];
extern const u8 BattleScript_AllStatsUp[];
extern const u8 BattleScript_AtkDefDown[];
extern const u8 BattleScript_SAtkDown2[];
extern const u8 BattleScript_LevelUp[];
extern const u8 BattleScript_WrapFree[];
extern const u8 BattleScript_LeechSeedFree[];
extern const u8 BattleScript_SpikesFree[];
extern const u8 BattleScript_ButItFailed[];
extern const u8 BattleScript_ObliviousPreventsAttraction[];
extern const u8 BattleScript_MistProtected[];
extern const u8 BattleScript_AbilityNoStatLoss[];
extern const u8 BattleScript_AbilityNoSpecificStatLoss[];
extern const u8 BattleScript_TrainerBallBlock[];
extern const u8 BattleScript_WallyBallThrow[];
extern const u8 BattleScript_SuccessBallThrow[];
extern const u8 BattleScript_ShakeBallThrow[];
extern const u8 BattleScript_FaintAttacker[];
extern const u8 BattleScript_FaintTarget[];
extern const u8 BattleScript_DestinyBondTakesLife[];
extern const u8 BattleScript_GrudgeTakesPp[];

// read via orr
#define BSScriptRead32(ptr) ((ptr)[0] | (ptr)[1] << 8 | (ptr)[2] << 16 | (ptr)[3] << 24)
#define BSScriptRead8(ptr) (((u8)((ptr)[0])))
#define BSScriptReadPtr(ptr) ((void *)BSScriptRead32(ptr))

// read via add
#define BS2ScriptRead32(ptr) ((ptr)[0] + ((ptr)[1] << 8) + ((ptr)[2] << 16) + ((ptr)[3] << 24))
#define BS2ScriptRead16(ptr) ((ptr)[0] + ((ptr)[1] << 8))
#define BS2ScriptReadPtr(ptr) ((void *)BS2ScriptRead32(ptr))

#define TARGET_PROTECT_AFFECTED ((gProtectStructs[gBankTarget].protected && gBattleMoves[gCurrentMove].flags & FLAG_PROTECT_AFFECTED))

#define TARGET_TURN_DAMAGED (((gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_physical.moveturnLostHP_special)))

// this file's functions
bool8 IsTwoTurnsMove(u16 move);
void DestinyBondFlagUpdate(void);
u8 AttacksThisTurn(u8 bank, u16 move); // Note: returns 1 if it's a charging turn, otherwise 2.
static void CheckWonderGuardAndLevitate(void);
u8 ChangeStatBuffs(s8 statValue, u8 statId, u8, const u8* BS_ptr);

void atk00_attackcanceler(void);
void atk01_accuracycheck(void);
void atk02_attackstring(void);
void atk03_ppreduce(void);
void atk04_critcalc(void);
void atk05_damagecalc1(void);
void atk06_typecalc(void);
void atk07_dmg_adjustment(void);
void atk08_dmg_adjustment2(void);
void atk09_attackanimation(void);
void atk0A_waitanimation(void);
void atk0B_healthbarupdate(void);
void atk0C_datahpupdate(void);
void atk0D_critmessage(void);
void atk0E_effectiveness_sound(void);
void atk0F_resultmessage(void);
void atk10_printstring(void);
void atk11_printstring_playeronly(void);
void atk12_waitmessage(void);
void atk13_printfromtable(void);
void atk14_printfromtable_playeronly(void);
void atk15_seteffectwithchancetarget(void);
void atk16_seteffectprimary(void);
void atk17_seteffectsecondary(void);
void atk18_status_effect_clear(void);
void atk19_faint_pokemon(void);
void atk1A_faint_animation(void);
void atk1B_faint_effects_clear(void);
void atk1C_jumpifstatus(void);
void atk1D_jumpifstatus2(void);
void atk1E_jumpifability(void);
void atk1F_jumpifsideaffecting(void);
void atk20_jumpifstat(void);
void atk21_jumpifstatus3(void);
void atk22_jumpiftype(void);
void atk23_getexp(void);
void atk24(void);
void atk25_move_values_cleanup(void);
void atk26_set_multihit(void);
void atk27_decrement_multihit(void);
void atk28_goto(void);
void atk29_jumpifbyte(void);
void atk2A_jumpifhalfword(void);
void atk2B_jumpifword(void);
void atk2C_jumpifarrayequal(void);
void atk2D_jumpifarraynotequal(void);
void atk2E_setbyte(void);
void atk2F_addbyte(void);
void atk30_subbyte(void);
void atk31_copyarray(void);
void atk32_copyarray_withindex(void);
void atk33_orbyte(void);
void atk34_orhalfword(void);
void atk35_orword(void);
void atk36_bicbyte(void);
void atk37_bichalfword(void);
void atk38_bicword(void);
void atk39_pause(void);
void atk3A_waitstate(void);
void atk3B_healthbar_update(void);
void atk3C_return(void);
void atk3D_end(void);
void atk3E_end2(void);
void atk3F_end3(void);
void atk40_jump_if_move_affected_by_protect(void);
void atk41_call(void);
void atk42_jumpiftype2(void);
void atk43_jumpifabilitypresent(void);
void atk44(void);
void atk45_playanimation(void);
void atk46_playanimation2(void);
void atk47_setgraphicalstatchangevalues(void);
void atk48_playstatchangeanimation(void);
void atk49_moveendturn(void);
void atk4A_typecalc2(void);
void atk4B_return_atk_to_ball(void);
void atk4C_copy_poke_data(void);
void atk4D_switch_data_update(void);
void atk4E_switchin_anim(void);
void atk4F_jump_if_cannot_switch(void);
void atk50_openpartyscreen(void);
void atk51_switch_handle_order(void);
void atk52_switch_in_effects(void);
void atk53_trainer_slide(void);
void atk54_effectiveness_sound(void);
void atk55_play_sound(void);
void atk56_fainting_cry(void);
void atk57(void);
void atk58_return_to_ball(void);
void atk59_learnmove_inbattle(void);
void atk5A(void);
void atk5B_80256E0(void);
void atk5C_hitanimation(void);
void atk5D_getmoneyreward(void);
void atk5E_8025A70(void);
void atk5F_8025B24(void);
void atk60_increment_gamestat(void);
void atk61_8025BA4(void);
void atk62_08025C6C(void);
void atk63_jumptorandomattack(void);
void atk64_statusanimation(void);
void atk65_status2animation(void);
void atk66_chosenstatusanimation(void);
void atk67_8025ECC(void);
void atk68_80246A0(void);
void atk69_dmg_adjustment2(void);
void atk6A_removeitem(void);
void atk6B_atknameinbuff1(void);
void atk6C_lvlbox_display(void);
void atk6D_set_sentpokes_values(void);
void atk6E_set_atk_to_player0(void);
void atk6F_set_visible(void);
void atk70_record_ability(void);
void atk71_buffer_move_to_learn(void);
void atk72_jump_if_can_run_frombattle(void);
void atk73_hp_thresholds(void);
void atk74_hp_thresholds2(void);
void atk75_8026A58(void);
void atk76_various(void);
void atk77_setprotect(void);
void atk78_faintifabilitynotdamp(void);
void atk79_setatkhptozero(void);
void atk7A_jumpwhiletargetvalid(void);
void atk7B_healhalfHP_if_possible(void);
void atk7C_8025508(void);
void atk7D_set_rain(void);
void atk7E_setreflect(void);
void atk7F_setseeded(void);
void atk80_manipulatedamage(void);
void atk81_setrest(void);
void atk82_jumpifnotfirstturn(void);
void atk83_nop(void);
void atk84_jump_if_cant_sleep(void);
void atk85_stockpile(void);
void atk86_stockpiletobasedamage(void);
void atk87_stockpiletohpheal(void);
void atk88_negativedamage(void);
void atk89_statbuffchange(void);
void atk8A_normalisebuffs(void);
void atk8B_setbide(void);
void atk8C_confuseifrepeatingattackends(void);
void atk8D_setmultihit_counter(void);
void atk8E_prepare_multihit(void);
void atk8F_forcerandomswitch(void);
void atk90_conversion_type_change(void);
void atk91_givepaydaymoney(void);
void atk92_setlightscreen(void);
void atk93_ko_move(void);
void atk94_gethalfcurrentenemyhp(void);
void atk95_setsandstorm(void);
void atk96_weatherdamage(void);
void atk97_try_infatuation(void);
void atk98_status_icon_update(void);
void atk99_setmist(void);
void atk9A_set_focusenergy(void);
void atk9B_transformdataexecution(void);
void atk9C_set_substitute(void);
void atk9D_copyattack(void);
void atk9E_metronome(void);
void atk9F_dmgtolevel(void);
void atkA0_psywavedamageeffect(void);
void atkA1_counterdamagecalculator(void);
void atkA2_mirrorcoatdamagecalculator(void);
void atkA3_disablelastusedattack(void);
void atkA4_setencore(void);
void atkA5_painsplitdmgcalc(void);
void atkA6_settypetorandomresistance(void);
void atkA7_setalwayshitflag(void);
void atkA8_copymovepermanently(void);
void atkA9_sleeptalk_choose_move(void);
void atkAA_set_destinybond(void);
void atkAB_DestinyBondFlagUpdate(void);
void atkAC_remaininghptopower(void);
void atkAD_spite_ppreduce(void);
void atkAE_heal_party_status(void);
void atkAF_cursetarget(void);
void atkB0_set_spikes(void);
void atkB1_set_foresight(void);
void atkB2_setperishsong(void);
void atkB3_rolloutdamagecalculation(void);
void atkB4_jumpifconfusedandstatmaxed(void);
void atkB5_furycuttercalc(void);
void atkB6_happinesstodamagecalculation(void);
void atkB7_presentdamagecalculation(void);
void atkB8_set_safeguard(void);
void atkB9_magnitudedamagecalculation(void);
void atkBA_jumpifnopursuitswitchdmg(void);
void atkBB_setsunny(void);
void atkBC_maxattackhalvehp(void);
void atkBD_copyfoestats(void);
void atkBE_breakfree(void);
void atkBF_set_defense_curl(void);
void atkC0_recoverbasedonsunlight(void);
void atkC1_hidden_power(void);
void atkC2_selectnexttarget(void);
void atkC3_setfutureattack(void);
void atkC4_beat_up(void);
void atkC5_hidepreattack(void);
void atkC6_unhidepostattack(void);
void atkC7_setminimize(void);
void atkC8_sethail(void);
void atkC9_jumpifattackandspecialattackcannotfall(void);
void atkCA_setforcedtarget(void);
void atkCB_setcharge(void);
void atkCC_callterrainattack(void);
void atkCD_cureifburnedparalysedorpoisoned(void);
void atkCE_settorment(void);
void atkCF_jumpifnodamage(void);
void atkD0_settaunt(void);
void atkD1_set_helpinghand(void);
void atkD2_swap_items(void);
void atkD3_copy_ability(void);
void atkD4_wish_effect(void);
void atkD5_setroots(void);
void atkD6_doubledamagedealtifdamaged(void);
void atkD7_setyawn(void);
void atkD8_setdamagetohealthdifference(void);
void atkD9_scaledamagebyhealthratio(void);
void atkDA_abilityswap(void);
void atkDB_imprisoneffect(void);
void atkDC_setgrudge(void);
void atkDD_weightdamagecalculation(void);
void atkDE_asistattackselect(void);
void atkDF_setmagiccoat(void);
void atkE0_setstealstatchange(void);
void atkE1_intimidate_string_loader(void);
void atkE2_switchout_abilities(void);
void atkE3_jumpiffainted(void);
void atkE4_getsecretpowereffect(void);
void atkE5_pickup(void);
void atkE6_castform_change_animation(void);
void atkE7_castform_data_change(void);
void atkE8_settypebasedhalvers(void);
void atkE9_setweatherballtype(void);
void atkEA_recycleitem(void);
void atkEB_settypetoterrain(void);
void atkEC_pursuit_sth(void);
void atkED_802B4B4(void);
void atkEE_removelightscreenreflect(void);
void atkEF_pokeball_catch_calculation(void);
void atkF0_copy_caught_poke(void);
void atkF1_setpoke_as_caught(void);
void atkF2_display_dex_info(void);
void atkF3_nickname_caught_poke(void);
void atkF4_802BEF0(void);
void atkF5_removeattackerstatus1(void);
void atkF6_802BF48(void);
void atkF7_802BF54(void);
void sub_8056EF8(void);

void (* const gBattleScriptingCommandsTable[])(void) =
{
    atk00_attackcanceler,
    atk01_accuracycheck,
    atk02_attackstring,
    atk03_ppreduce,
    atk04_critcalc,
    atk05_damagecalc1,
    atk06_typecalc,
    atk07_dmg_adjustment,
    atk08_dmg_adjustment2,
    atk09_attackanimation,
    atk0A_waitanimation,
    atk0B_healthbarupdate,
    atk0C_datahpupdate,
    atk0D_critmessage,
    atk0E_effectiveness_sound,
    atk0F_resultmessage,
    atk10_printstring,
    atk11_printstring_playeronly,
    atk12_waitmessage,
    atk13_printfromtable,
    atk14_printfromtable_playeronly,
    atk15_seteffectwithchancetarget,
    atk16_seteffectprimary,
    atk17_seteffectsecondary,
    atk18_status_effect_clear,
    atk19_faint_pokemon,
    atk1A_faint_animation,
    atk1B_faint_effects_clear,
    atk1C_jumpifstatus,
    atk1D_jumpifstatus2,
    atk1E_jumpifability,
    atk1F_jumpifsideaffecting,
    atk20_jumpifstat,
    atk21_jumpifstatus3,
    atk22_jumpiftype,
    atk23_getexp,
    atk24,
    atk25_move_values_cleanup,
    atk26_set_multihit,
    atk27_decrement_multihit,
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
    atk32_copyarray_withindex,
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
    atk40_jump_if_move_affected_by_protect,
    atk41_call,
    atk42_jumpiftype2,
    atk43_jumpifabilitypresent,
    atk44,
    atk45_playanimation,
    atk46_playanimation2,
    atk47_setgraphicalstatchangevalues,
    atk48_playstatchangeanimation,
    atk49_moveendturn,
    atk4A_typecalc2,
    atk4B_return_atk_to_ball,
    atk4C_copy_poke_data,
    atk4D_switch_data_update,
    atk4E_switchin_anim,
    atk4F_jump_if_cannot_switch,
    atk50_openpartyscreen,
    atk51_switch_handle_order,
    atk52_switch_in_effects,
    atk53_trainer_slide,
    atk54_effectiveness_sound,
    atk55_play_sound,
    atk56_fainting_cry,
    atk57,
    atk58_return_to_ball,
    atk59_learnmove_inbattle,
    atk5A,
    atk5B_80256E0,
    atk5C_hitanimation,
    atk5D_getmoneyreward,
    atk5E_8025A70,
    atk5F_8025B24,
    atk60_increment_gamestat,
    atk61_8025BA4,
    atk62_08025C6C,
    atk63_jumptorandomattack,
    atk64_statusanimation,
    atk65_status2animation,
    atk66_chosenstatusanimation,
    atk67_8025ECC,
    atk68_80246A0,
    atk69_dmg_adjustment2,
    atk6A_removeitem,
    atk6B_atknameinbuff1,
    atk6C_lvlbox_display,
    atk6D_set_sentpokes_values,
    atk6E_set_atk_to_player0,
    atk6F_set_visible,
    atk70_record_ability,
    atk71_buffer_move_to_learn,
    atk72_jump_if_can_run_frombattle,
    atk73_hp_thresholds,
    atk74_hp_thresholds2,
    atk75_8026A58,
    atk76_various,
    atk77_setprotect,
    atk78_faintifabilitynotdamp,
    atk79_setatkhptozero,
    atk7A_jumpwhiletargetvalid,
    atk7B_healhalfHP_if_possible,
    atk7C_8025508,
    atk7D_set_rain,
    atk7E_setreflect,
    atk7F_setseeded,
    atk80_manipulatedamage,
    atk81_setrest,
    atk82_jumpifnotfirstturn,
    atk83_nop,
    atk84_jump_if_cant_sleep,
    atk85_stockpile,
    atk86_stockpiletobasedamage,
    atk87_stockpiletohpheal,
    atk88_negativedamage,
    atk89_statbuffchange,
    atk8A_normalisebuffs,
    atk8B_setbide,
    atk8C_confuseifrepeatingattackends,
    atk8D_setmultihit_counter,
    atk8E_prepare_multihit,
    atk8F_forcerandomswitch,
    atk90_conversion_type_change,
    atk91_givepaydaymoney,
    atk92_setlightscreen,
    atk93_ko_move,
    atk94_gethalfcurrentenemyhp,
    atk95_setsandstorm,
    atk96_weatherdamage,
    atk97_try_infatuation,
    atk98_status_icon_update,
    atk99_setmist,
    atk9A_set_focusenergy,
    atk9B_transformdataexecution,
    atk9C_set_substitute,
    atk9D_copyattack,
    atk9E_metronome,
    atk9F_dmgtolevel,
    atkA0_psywavedamageeffect,
    atkA1_counterdamagecalculator,
    atkA2_mirrorcoatdamagecalculator,
    atkA3_disablelastusedattack,
    atkA4_setencore,
    atkA5_painsplitdmgcalc,
    atkA6_settypetorandomresistance,
    atkA7_setalwayshitflag,
    atkA8_copymovepermanently,
    atkA9_sleeptalk_choose_move,
    atkAA_set_destinybond,
    atkAB_DestinyBondFlagUpdate,
    atkAC_remaininghptopower,
    atkAD_spite_ppreduce,
    atkAE_heal_party_status,
    atkAF_cursetarget,
    atkB0_set_spikes,
    atkB1_set_foresight,
    atkB2_setperishsong,
    atkB3_rolloutdamagecalculation,
    atkB4_jumpifconfusedandstatmaxed,
    atkB5_furycuttercalc,
    atkB6_happinesstodamagecalculation,
    atkB7_presentdamagecalculation,
    atkB8_set_safeguard,
    atkB9_magnitudedamagecalculation,
    atkBA_jumpifnopursuitswitchdmg,
    atkBB_setsunny,
    atkBC_maxattackhalvehp,
    atkBD_copyfoestats,
    atkBE_breakfree,
    atkBF_set_defense_curl,
    atkC0_recoverbasedonsunlight,
    atkC1_hidden_power,
    atkC2_selectnexttarget,
    atkC3_setfutureattack,
    atkC4_beat_up,
    atkC5_hidepreattack,
    atkC6_unhidepostattack,
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
    atkD1_set_helpinghand,
    atkD2_swap_items,
    atkD3_copy_ability,
    atkD4_wish_effect,
    atkD5_setroots,
    atkD6_doubledamagedealtifdamaged,
    atkD7_setyawn,
    atkD8_setdamagetohealthdifference,
    atkD9_scaledamagebyhealthratio,
    atkDA_abilityswap,
    atkDB_imprisoneffect,
    atkDC_setgrudge,
    atkDD_weightdamagecalculation,
    atkDE_asistattackselect,
    atkDF_setmagiccoat,
    atkE0_setstealstatchange,
    atkE1_intimidate_string_loader,
    atkE2_switchout_abilities,
    atkE3_jumpiffainted,
    atkE4_getsecretpowereffect,
    atkE5_pickup,
    atkE6_castform_change_animation,
    atkE7_castform_data_change,
    atkE8_settypebasedhalvers,
    atkE9_setweatherballtype,
    atkEA_recycleitem,
    atkEB_settypetoterrain,
    atkEC_pursuit_sth,
    atkED_802B4B4,
    atkEE_removelightscreenreflect,
    atkEF_pokeball_catch_calculation,
    atkF0_copy_caught_poke,
    atkF1_setpoke_as_caught,
    atkF2_display_dex_info,
    atkF3_nickname_caught_poke,
    atkF4_802BEF0,
    atkF5_removeattackerstatus1,
    atkF6_802BF48,
    atkF7_802BF54,
    sub_8056EF8
};

struct StatFractions
{
    u8 dividend;
    u8 divisor;
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

// The chance is 1/N for each stage.
const u16 gCriticalHitChance[] = {16, 8, 4, 3, 2};

const u32 gStatusFlagsForMoveEffects[] =
{
    0x00000000,
    STATUS_SLEEP,
    STATUS_POISON,
    STATUS_BURN,
    STATUS_FREEZE,
    STATUS_PARALYSIS,
    STATUS_TOXIC_POISON,
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
    0x08000000,
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

extern const u8* gMoveEffectBS_Ptrs[];

void atk00_attackcanceler(void)
{
    s32 i;

    if (gBattleOutcome)
    {
        gFightStateTracker = 0xC;
        return;
    }
    if (gBattleMons[gBankAttacker].hp == 0 && !(gHitMarker & HITMARKER_NO_ATTACKSTRING))
    {
        gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
        return;
    }
    if (AtkCanceller_UnableToUseMove())
        return;
    if (AbilityBattleEffects(ABILITYEFFECT_MOVES_BLOCK, gBankTarget, 0, 0, 0))
        return;
    if (!gBattleMons[gBankAttacker].pp[gCurrMovePos] && gCurrentMove != MOVE_STRUGGLE && !(gHitMarker & 0x800200)
     && !(gBattleMons[gBankAttacker].status2 & STATUS2_MULTIPLETURNS))
    {
        gBattlescriptCurrInstr = BattleScript_NoPPForMove;
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        return;
    }

    gHitMarker &= ~(HITMARKER_x800000);

    if (!(gHitMarker & HITMARKER_OBEYS) && !(gBattleMons[gBankAttacker].status2 & STATUS2_MULTIPLETURNS))
    {
        i = IsPokeDisobedient(); // why use the 'i' variable...?
        switch (i)
        {
        case 0:
            break;
        case 2:
            gHitMarker |= HITMARKER_OBEYS;
            return;
        default:
            gBattleMoveFlags |= MOVESTATUS_MISSED;
            return;
        }
    }

    gHitMarker |= HITMARKER_OBEYS;

    if (gProtectStructs[gBankTarget].bounceMove && gBattleMoves[gCurrentMove].flags & FLAG_MAGICCOAT_AFFECTED)
    {
        PressurePPLose(gBankAttacker, gBankTarget, MOVE_MAGIC_COAT);
        gProtectStructs[gBankTarget].bounceMove = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_MagicCoatBounce;
        return;
    }

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if ((gProtectStructs[gTurnOrder[i]].stealMove) && gBattleMoves[gCurrentMove].flags & FLAG_SNATCH_AFFECTED)
        {
            PressurePPLose(gBankAttacker, gTurnOrder[i], MOVE_SNATCH);
            gProtectStructs[gTurnOrder[i]].stealMove = 0;
            gBattleScripting.bank = gTurnOrder[i];
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_SnatchedMove;
            return;
        }
    }

    if (gSpecialStatuses[gBankTarget].lightningRodRedirected)
    {
        gSpecialStatuses[gBankTarget].lightningRodRedirected = 0;
        gLastUsedAbility = ABILITY_LIGHTNING_ROD;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_TookAttack;
        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
    }
    else if (TARGET_PROTECT_AFFECTED
     && (gCurrentMove != MOVE_CURSE || (gBattleMons[gBankAttacker].type1 == TYPE_GHOST || gBattleMons[gBankAttacker].type2 == TYPE_GHOST))
     && ((!IsTwoTurnsMove(gCurrentMove) || (gBattleMons[gBankAttacker].status2 & STATUS2_MULTIPLETURNS))))
    {
        CancelMultiTurnMoves(gBankAttacker);
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gUnknown_02024250[gBankTarget] = 0;
        gUnknown_02024258[gBankTarget] = 0;
        gBattleCommunication[6] = 1;
        gBattlescriptCurrInstr++;
    }
    else
    {
        gBattlescriptCurrInstr++;
    }
}

void JumpIfMoveFailed(u8 adder, u16 move)
{
    const void* BS_ptr = gBattlescriptCurrInstr + adder;
    if (gBattleMoveFlags & MOVESTATUS_NOEFFECT)
    {
        gUnknown_02024250[gBankTarget] = 0;
        gUnknown_02024258[gBankTarget] = 0;
        BS_ptr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        DestinyBondFlagUpdate();
        if (AbilityBattleEffects(ABILITYEFFECT_ABSORBING, gBankTarget, 0, 0, move))
            return;
    }
    gBattlescriptCurrInstr = BS_ptr;
}

void atk40_jump_if_move_affected_by_protect(void)
{
    if (TARGET_PROTECT_AFFECTED)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
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
    if (TARGET_PROTECT_AFFECTED)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        JumpIfMoveFailed(7, move);
        gBattleCommunication[6] = 1;
        affected = TRUE;
    }
    return affected;
}

bool8 AccuracyCalcHelper(u16 move)
{
    if (gStatuses3[gBankTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBankTarget].bankWithSureHit == gBankAttacker)
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    if (!(gHitMarker & HITMARKER_IGNORE_ON_AIR) && gStatuses3[gBankTarget] & STATUS3_ON_AIR)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    gHitMarker &= ~HITMARKER_IGNORE_ON_AIR;

    if (!(gHitMarker & HITMARKER_IGNORE_UNDERGROUND) && gStatuses3[gBankTarget] & STATUS3_UNDERGROUND)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    gHitMarker &= ~HITMARKER_IGNORE_UNDERGROUND;

    if (!(gHitMarker & HITMARKER_IGNORE_UNDERWATER) && gStatuses3[gBankTarget] & STATUS3_UNDERWATER)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    gHitMarker &= ~HITMARKER_IGNORE_UNDERWATER;

    if ((WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_RAIN_ANY) && gBattleMoves[move].effect == EFFECT_THUNDER)
     || (gBattleMoves[move].effect == EFFECT_ALWAYS_HIT || gBattleMoves[move].effect == EFFECT_VITAL_THROW))
    {
        JumpIfMoveFailed(7, move);
        return TRUE;
    }

    return FALSE;
}

void atk01_accuracycheck(void)
{
    u16 move = BS2ScriptRead16(gBattlescriptCurrInstr + 5);

    if (move == 0xFFFE || move == 0xFFFF)
    {
        if (gStatuses3[gBankTarget] & STATUS3_ALWAYS_HITS && move == 0xFFFF && gDisableStructs[gBankTarget].bankWithSureHit == gBankAttacker)
            gBattlescriptCurrInstr += 7;
        else if (gStatuses3[gBankTarget] & (STATUS3_ON_AIR | STATUS3_UNDERGROUND | STATUS3_UNDERWATER))
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        else if (!JumpIfMoveAffectedByProtect(0))
            gBattlescriptCurrInstr += 7;
    }
    else
    {
        u8 type, moveAcc, holdEffect, quality;
        s8 buff;
        u16 calc;

        if (move == 0)
            move = gCurrentMove;

        GET_MOVE_TYPE(move, type);

        if (JumpIfMoveAffectedByProtect(move))
            return;
        if (AccuracyCalcHelper(move))
            return;

        if (gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT)
        {
            u8 acc = gBattleMons[gBankAttacker].statStages[STAT_STAGE_ACC];
            buff = acc;
        }
        else
        {
            u8 acc = gBattleMons[gBankAttacker].statStages[STAT_STAGE_ACC];
            buff = acc + 6 - gBattleMons[gBankTarget].statStages[STAT_STAGE_EVASION];
        }

        if (buff < 0)
            buff = 0;
        if (buff > 0xC)
            buff = 0xC;

        moveAcc = gBattleMoves[move].accuracy;
        // check Thunder on sunny weather
        if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY && gBattleMoves[move].effect == EFFECT_THUNDER)
            moveAcc = 50;

        calc = gAccuracyStageRatios[buff].dividend * moveAcc;
        calc /= gAccuracyStageRatios[buff].divisor;

        if (gBattleMons[gBankAttacker].ability == ABILITY_COMPOUND_EYES)
            calc = (calc * 130) / 100; // 1.3 compound eyes boost
        if (WEATHER_HAS_EFFECT && gBattleMons[gBankTarget].ability == ABILITY_SAND_VEIL && gBattleWeather & WEATHER_SANDSTORM_ANY)
            calc = (calc * 80) / 100; // 1.2 sand veil loss
        if (gBattleMons[gBankAttacker].ability == ABILITY_HUSTLE && type < 9)
            calc = (calc * 80) / 100; // 1.2 hustle loss

        if (gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY)
        {
            holdEffect = gEnigmaBerries[gBankTarget].holdEffect;
            quality = gEnigmaBerries[gBankTarget].holdEffectParam;
        }
        else
        {
            holdEffect = ItemId_GetHoldEffect(gBattleMons[gBankTarget].item);
            quality = ItemId_GetHoldEffectParam(gBattleMons[gBankTarget].item);
        }

        gStringBank = gBankTarget;

        if (holdEffect == HOLD_EFFECT_EVASION_UP)
            calc = (calc * (100 - quality)) / 100;

        // final calculation
        if ((Random() % 100 + 1) > calc)
        {
            gBattleMoveFlags |= MOVESTATUS_MISSED;
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE &&
                (gBattleMoves[move].target == MOVE_TARGET_BOTH || gBattleMoves[move].target == MOVE_TARGET_FOES_AND_ALLY))
                gBattleCommunication[6] = 2;
            else
                gBattleCommunication[6] = 0;

            CheckWonderGuardAndLevitate();
        }
        JumpIfMoveFailed(7, move);
    }
}

void atk02_attackstring(void)
{
    if (gBattleExecBuffer)
         return;
    if (!(gHitMarker & (HITMARKER_NO_ATTACKSTRING | HITMARKER_ATTACKSTRING_PRINTED)))
    {
        PrepareStringBattle(4, gBankAttacker);
        gHitMarker |= HITMARKER_ATTACKSTRING_PRINTED;
    }
    gBattlescriptCurrInstr++;
    gBattleCommunication[MSG_DISPLAY] = 0;
}

void atk03_ppreduce(void)
{
    s32 to_deduct = 1;

    if (gBattleExecBuffer)
        return;

    if (!gSpecialStatuses[gBankAttacker].flag20)
    {
        switch (gBattleMoves[gCurrentMove].target)
        {
        case MOVE_TARGET_FOES_AND_ALLY:
            to_deduct += AbilityBattleEffects(ABILITYEFFECT_COUNT_ON_FIELD, gBankAttacker, ABILITY_PRESSURE, 0, 0);
            break;
        case MOVE_TARGET_BOTH:
        case MOVE_TARGET_OPPONENTS_FIELD:
            to_deduct += AbilityBattleEffects(ABILITYEFFECT_COUNT_OTHER_SIZE, gBankAttacker, ABILITY_PRESSURE, 0, 0);
            break;
        default:
            if (gBankAttacker != gBankTarget && gBattleMons[gBankTarget].ability == ABILITY_PRESSURE)
                to_deduct++;
            break;
        }
    }

    if (!(gHitMarker & (HITMARKER_NO_PPDEDUCT | HITMARKER_NO_ATTACKSTRING)) && gBattleMons[gBankAttacker].pp[gCurrMovePos])
    {
        gProtectStructs[gBankAttacker].notFirstStrike = 1;

        if (gBattleMons[gBankAttacker].pp[gCurrMovePos] > to_deduct)
            gBattleMons[gBankAttacker].pp[gCurrMovePos] -= to_deduct;
        else
            gBattleMons[gBankAttacker].pp[gCurrMovePos] = 0;

        if (!(gBattleMons[gBankAttacker].status2 & STATUS2_TRANSFORMED)
            && !((gDisableStructs[gBankAttacker].unk18_b) & gBitTable[gCurrMovePos]))
        {
            gActiveBank = gBankAttacker;
            EmitSetAttributes(0, REQUEST_PPMOVE1_BATTLE + gCurrMovePos, 0, 1, &gBattleMons[gBankAttacker].pp[gCurrMovePos]);
            MarkBufferBankForExecution(gBankAttacker);
        }
    }

    gHitMarker &= ~(HITMARKER_NO_PPDEDUCT);
    gBattlescriptCurrInstr++;
}

void atk04_critcalc(void)
{
    u8 holdEffect;
    u16 item, critChance;

    item = gBattleMons[gBankAttacker].item;

    if (item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[gBankAttacker].holdEffect;
    else
        holdEffect = ItemId_GetHoldEffect(item);

    gStringBank = gBankAttacker;

    critChance  = 2 * ((gBattleMons[gBankAttacker].status2 & STATUS2_FOCUS_ENERGY) != 0)
                + (gBattleMoves[gCurrentMove].effect == EFFECT_HIGH_CRITICAL)
                + (gBattleMoves[gCurrentMove].effect == EFFECT_SKY_ATTACK)
                + (gBattleMoves[gCurrentMove].effect == EFFECT_BLAZE_KICK)
                + (gBattleMoves[gCurrentMove].effect == EFFECT_POISON_TAIL)
                + (holdEffect == HOLD_EFFECT_SCOPE_LENS)
                + 2 * (holdEffect == HOLD_EFFECT_LUCKY_PUNCH && gBattleMons[gBankAttacker].species == SPECIES_CHANSEY)
                + 2 * (holdEffect == HOLD_EFFECT_STICK && gBattleMons[gBankAttacker].species == SPECIES_FARFETCHD);

    if (critChance > 4)
        critChance = 4;

    if ((gBattleMons[gBankTarget].ability != ABILITY_BATTLE_ARMOR && gBattleMons[gBankTarget].ability != ABILITY_SHELL_ARMOR)
     && !(gStatuses3[gBankAttacker] & STATUS3_CANT_SCORE_A_CRIT)
     && !(gBattleTypeFlags & (BATTLE_TYPE_WALLY_TUTORIAL | BATTLE_TYPE_FIRST_BATTLE))
     && !(Random() % gCriticalHitChance[critChance]))
        gCritMultiplier = 2;
    else
        gCritMultiplier = 1;

    gBattlescriptCurrInstr++;
}

void atk05_damagecalc1(void)
{
    u16 sideStatus = gSideAffecting[GET_BANK_SIDE(gBankTarget)];
    gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBankAttacker], &gBattleMons[gBankTarget], gCurrentMove,
                                            sideStatus, gDynamicBasePower,
                                            gBattleStruct->dynamicMoveType, gBankAttacker, gBankTarget);
    gBattleMoveDamage = gBattleMoveDamage * gCritMultiplier * gBattleScripting.dmgMultiplier;

    if (gStatuses3[gBankAttacker] & STATUS3_CHARGED_UP && gBattleMoves[gCurrentMove].type == TYPE_ELECTRIC)
        gBattleMoveDamage *= 2;
    if (gProtectStructs[gBankAttacker].helpingHand)
        gBattleMoveDamage = gBattleMoveDamage * 15 / 10;

    gBattlescriptCurrInstr++;
}

void AI_CalcDmg(u8 bankAtk, u8 bankDef)
{
    u16 sideStatus = gSideAffecting[GET_BANK_SIDE(bankDef)];
    gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[bankAtk], &gBattleMons[bankDef], gCurrentMove,
                                            sideStatus, gDynamicBasePower,
                                            gBattleStruct->dynamicMoveType, bankAtk, bankDef);
    gDynamicBasePower = 0;
    gBattleMoveDamage = gBattleMoveDamage * gCritMultiplier * gBattleScripting.dmgMultiplier;

    if (gStatuses3[bankAtk] & STATUS3_CHARGED_UP && gBattleMoves[gCurrentMove].type == TYPE_ELECTRIC)
        gBattleMoveDamage *= 2;
    if (gProtectStructs[bankAtk].helpingHand)
        gBattleMoveDamage = gBattleMoveDamage * 15 / 10;
}

void ModulateDmgByType(u8 multiplier)
{
    gBattleMoveDamage = gBattleMoveDamage * multiplier / 10;
    if (gBattleMoveDamage == 0 && multiplier != 0)
        gBattleMoveDamage = 1;

    switch (multiplier)
    {
    case TYPE_MUL_NO_EFFECT:
        gBattleMoveFlags |= MOVESTATUS_NOTAFFECTED;
        gBattleMoveFlags &= ~MOVESTATUS_NOTVERYEFFECTIVE;
        gBattleMoveFlags &= ~MOVESTATUS_SUPEREFFECTIVE;
        break;
    case TYPE_MUL_NOT_EFFECTIVE:
        if (gBattleMoves[gCurrentMove].power && !(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
        {
            if (gBattleMoveFlags & MOVESTATUS_SUPEREFFECTIVE)
                gBattleMoveFlags &= ~MOVESTATUS_SUPEREFFECTIVE;
            else
                gBattleMoveFlags |= MOVESTATUS_NOTVERYEFFECTIVE;
        }
        break;
    case TYPE_MUL_SUPER_EFFECTIVE:
        if (gBattleMoves[gCurrentMove].power && !(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
        {
            if (gBattleMoveFlags & MOVESTATUS_NOTVERYEFFECTIVE)
                gBattleMoveFlags &= ~MOVESTATUS_NOTVERYEFFECTIVE;
            else
                gBattleMoveFlags |= MOVESTATUS_SUPEREFFECTIVE;
        }
        break;
    }
}

#define TYPE_FORESIGHT  0xFE
#define TYPE_ENDTABLE   0xFF

void atk06_typecalc(void)
{
    s32 i = 0;
    u8 moveType;

    if (gCurrentMove == MOVE_STRUGGLE)
    {
        gBattlescriptCurrInstr++;
        return;
    }

    GET_MOVE_TYPE(gCurrentMove, moveType);

    // check stab
    if (gBattleMons[gBankAttacker].type1 == moveType || gBattleMons[gBankAttacker].type2 == moveType)
    {
        gBattleMoveDamage = gBattleMoveDamage * 15;
        gBattleMoveDamage = gBattleMoveDamage / 10;
    }

    if (gBattleMons[gBankTarget].ability == ABILITY_LEVITATE && moveType == TYPE_GROUND)
    {
        gLastUsedAbility = gBattleMons[gBankTarget].ability;
        gBattleMoveFlags |= (MOVESTATUS_MISSED | MOVESTATUS_NOTAFFECTED);
        gUnknown_02024250[gBankTarget] = 0;
        gUnknown_02024258[gBankTarget] = 0;
        gBattleCommunication[6] = moveType;
        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
    }
    else
    {
        while (gTypeEffectiveness[i] != TYPE_ENDTABLE)
        {
            if (gTypeEffectiveness[i] == TYPE_FORESIGHT)
            {
                if (gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT)
                    break;
                i += 3;
                continue;
            }
            else if (gTypeEffectiveness[i] == moveType)
            {
                // check type1
                if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type1)
                    ModulateDmgByType(gTypeEffectiveness[i + 2]);
                // check type2
                if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type2 &&
                    gBattleMons[gBankTarget].type1 != gBattleMons[gBankTarget].type2)
                    ModulateDmgByType(gTypeEffectiveness[i + 2]);
            }
            i += 3;
        }
    }

    if (gBattleMons[gBankTarget].ability == ABILITY_WONDER_GUARD && AttacksThisTurn(gBankAttacker, gCurrentMove) == 2
     && (!(gBattleMoveFlags & MOVESTATUS_SUPEREFFECTIVE) || ((gBattleMoveFlags & (MOVESTATUS_SUPEREFFECTIVE | MOVESTATUS_NOTVERYEFFECTIVE)) == (MOVESTATUS_SUPEREFFECTIVE | MOVESTATUS_NOTVERYEFFECTIVE)))
     && gBattleMoves[gCurrentMove].power)
    {
        gLastUsedAbility = ABILITY_WONDER_GUARD;
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gUnknown_02024250[gBankTarget] = 0;
        gUnknown_02024258[gBankTarget] = 0;
        gBattleCommunication[6] = 3;
        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
    }
    if (gBattleMoveFlags & MOVESTATUS_NOTAFFECTED)
        gProtectStructs[gBankAttacker].notEffective = 1;

    gBattlescriptCurrInstr++;
}

static void CheckWonderGuardAndLevitate(void)
{
    u8 flags = 0;
    s32 i = 0;
    u8 moveType;

    if (gCurrentMove == MOVE_STRUGGLE || !gBattleMoves[gCurrentMove].power)
        return;

    GET_MOVE_TYPE(gCurrentMove, moveType);

    if (gBattleMons[gBankTarget].ability == ABILITY_LEVITATE && moveType == TYPE_GROUND)
    {
        gLastUsedAbility = ABILITY_LEVITATE;
        gBattleCommunication[6] = moveType;
        RecordAbilityBattle(gBankTarget, ABILITY_LEVITATE);
        return;
    }

    while (gTypeEffectiveness[i] != TYPE_ENDTABLE)
    {
        if (gTypeEffectiveness[i] == TYPE_FORESIGHT)
        {
            if (gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT)
                break;
            i += 3;
            continue;
        }
        if (gTypeEffectiveness[i] == moveType)
        {
            // check no effect
            if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type1 && gTypeEffectiveness[i + 2] == 0)
            {
                gBattleMoveFlags |= MOVESTATUS_NOTAFFECTED;
                gProtectStructs[gBankAttacker].notEffective = 1;
            }
            if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type2 &&
                gBattleMons[gBankTarget].type1 != gBattleMons[gBankTarget].type2 &&
                gTypeEffectiveness[i + 2] == TYPE_MUL_NO_EFFECT)
            {
                gBattleMoveFlags |= MOVESTATUS_NOTAFFECTED;
                gProtectStructs[gBankAttacker].notEffective = 1;
            }

            // check super effective
            if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type1 && gTypeEffectiveness[i + 2] == 20)
                flags |= 1;
            if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type2
             && gBattleMons[gBankTarget].type1 != gBattleMons[gBankTarget].type2
             && gTypeEffectiveness[i + 2] == TYPE_MUL_SUPER_EFFECTIVE)
                flags |= 1;

            // check not very effective
            if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type1 && gTypeEffectiveness[i + 2] == 5)
                flags |= 2;
            if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type2
             && gBattleMons[gBankTarget].type1 != gBattleMons[gBankTarget].type2
             && gTypeEffectiveness[i + 2] == TYPE_MUL_NOT_EFFECTIVE)
                flags |= 2;
        }
        i += 3;
    }

    if (gBattleMons[gBankTarget].ability == ABILITY_WONDER_GUARD && AttacksThisTurn(gBankAttacker, gCurrentMove) == 2)
    {
        if (((flags & 2) || !(flags & 1)) && gBattleMoves[gCurrentMove].power)
        {
            gLastUsedAbility = ABILITY_WONDER_GUARD;
            gBattleCommunication[6] = 3;
            RecordAbilityBattle(gBankTarget, ABILITY_WONDER_GUARD);
        }
    }
}

void ModulateDmgByType2(u8 multiplier, u16 move, u8* flags) // same as ModulateDmgByType except different arguments
{
    gBattleMoveDamage = gBattleMoveDamage * multiplier / 10;
    if (gBattleMoveDamage == 0 && multiplier != 0)
        gBattleMoveDamage = 1;

    switch (multiplier)
    {
    case TYPE_MUL_NO_EFFECT:
        *flags |= MOVESTATUS_NOTAFFECTED;
        *flags &= ~MOVESTATUS_NOTVERYEFFECTIVE;
        *flags &= ~MOVESTATUS_SUPEREFFECTIVE;
        break;
    case TYPE_MUL_NOT_EFFECTIVE:
        if (gBattleMoves[move].power && !(*flags & MOVESTATUS_NOEFFECT))
        {
            if (*flags & MOVESTATUS_SUPEREFFECTIVE)
                *flags &= ~MOVESTATUS_SUPEREFFECTIVE;
            else
                *flags |= MOVESTATUS_NOTVERYEFFECTIVE;
        }
        break;
    case TYPE_MUL_SUPER_EFFECTIVE:
        if (gBattleMoves[move].power && !(*flags & MOVESTATUS_NOEFFECT))
        {
            if (*flags & MOVESTATUS_NOTVERYEFFECTIVE)
                *flags &= ~MOVESTATUS_NOTVERYEFFECTIVE;
            else
                *flags |= MOVESTATUS_SUPEREFFECTIVE;
        }
        break;
    }
}

u8 TypeCalc(u16 move, u8 bankAtk, u8 bankDef)
{
    s32 i = 0;
    u8 flags = 0;
    u8 moveType;

    if (move == MOVE_STRUGGLE)
        return 0;

    moveType = gBattleMoves[move].type;

    // check stab
    if (gBattleMons[bankAtk].type1 == moveType || gBattleMons[bankAtk].type2 == moveType)
    {
        gBattleMoveDamage = gBattleMoveDamage * 15;
        gBattleMoveDamage = gBattleMoveDamage / 10;
    }

    if (gBattleMons[bankDef].ability == ABILITY_LEVITATE && moveType == TYPE_GROUND)
    {
        flags |= (MOVESTATUS_MISSED | MOVESTATUS_NOTAFFECTED);
    }
    else
    {
        while (gTypeEffectiveness[i]!= TYPE_ENDTABLE)
        {
            if (gTypeEffectiveness[i] == TYPE_FORESIGHT)
            {
                if (gBattleMons[bankDef].status2 & STATUS2_FORESIGHT)
                    break;
                i += 3;
                continue;
            }

            else if (gTypeEffectiveness[i] == moveType)
            {
                // check type1
                if (gTypeEffectiveness[i + 1] == gBattleMons[bankDef].type1)
                    ModulateDmgByType2(gTypeEffectiveness[i + 2], move, &flags);
                // check type2
                if (gTypeEffectiveness[i + 1] == gBattleMons[bankDef].type2 &&
                    gBattleMons[bankDef].type1 != gBattleMons[bankDef].type2)
                    ModulateDmgByType2(gTypeEffectiveness[i + 2], move, &flags);
            }
            i += 3;
        }
    }

    if (gBattleMons[bankDef].ability == ABILITY_WONDER_GUARD && !(flags & MOVESTATUS_MISSED)
        && AttacksThisTurn(bankAtk, move) == 2
        && (!(flags & MOVESTATUS_SUPEREFFECTIVE) || ((flags & (MOVESTATUS_SUPEREFFECTIVE | MOVESTATUS_NOTVERYEFFECTIVE)) == (MOVESTATUS_SUPEREFFECTIVE | MOVESTATUS_NOTVERYEFFECTIVE)))
        && gBattleMoves[move].power)
    {
        flags |= MOVESTATUS_MISSED;
    }
    return flags;
}

u8 AI_TypeCalc(u16 move, u16 species, u8 ability)
{
    s32 i = 0;
    u8 flags = 0;
    u8 type1 = gBaseStats[species].type1, type2 = gBaseStats[species].type2;
    u8 moveType;

    if (move == MOVE_STRUGGLE)
        return 0;

    moveType = gBattleMoves[move].type;

    if (ability == ABILITY_LEVITATE && moveType == TYPE_GROUND)
    {
        flags = MOVESTATUS_MISSED | MOVESTATUS_NOTAFFECTED;
    }
    else
    {
        while (gTypeEffectiveness[i] != TYPE_ENDTABLE)
        {
            if (gTypeEffectiveness[i] == TYPE_FORESIGHT)
            {
                i += 3;
                continue;
            }
            if (gTypeEffectiveness[i] == moveType)
            {
                // check type1
                if (gTypeEffectiveness[i + 1] == type1)
                    ModulateDmgByType2(gTypeEffectiveness[i + 2], move, &flags);
                // check type2
                if (gTypeEffectiveness[i + 1] == type2 && type1 != type2)
                    ModulateDmgByType2(gTypeEffectiveness[i + 2], move, &flags);
            }
            i += 3;
        }
    }
    if (ability == ABILITY_WONDER_GUARD
     && (!(flags & MOVESTATUS_SUPEREFFECTIVE) || ((flags & (MOVESTATUS_SUPEREFFECTIVE | MOVESTATUS_NOTVERYEFFECTIVE)) == (MOVESTATUS_SUPEREFFECTIVE | MOVESTATUS_NOTVERYEFFECTIVE)))
     && gBattleMoves[move].power)
        flags |= MOVESTATUS_NOTAFFECTED;
    return flags;
}

// Multiplies the damage by a random factor between 85% to 100% inclusive
static inline void ApplyRandomDmgMultiplier(void)
{
    u16 rand = Random();
    u16 randPercent = 100 - (rand % 16);

    if (gBattleMoveDamage != 0)
    {
        gBattleMoveDamage *= randPercent;
        gBattleMoveDamage /= 100;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
    }
}

void Unused_ApplyRandomDmgMultiplier(void)
{
    ApplyRandomDmgMultiplier();
}

void atk07_dmg_adjustment(void)
{
    u8 holdEffect, quality;

    ApplyRandomDmgMultiplier();

    if (gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY)
    {
        holdEffect = gEnigmaBerries[gBankTarget].holdEffect, quality = gEnigmaBerries[gBankTarget].holdEffectParam;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(gBattleMons[gBankTarget].item);
        quality = ItemId_GetHoldEffectParam(gBattleMons[gBankTarget].item);
    }

    gStringBank = gBankTarget;

    if (holdEffect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < quality)
    {
        RecordItemEffectBattle(gBankTarget, holdEffect);
        gSpecialStatuses[gBankTarget].focusBanded = 1;
    }
    if (gBattleMons[gBankTarget].status2 & STATUS2_SUBSTITUTE)
        goto END;
    if (gBattleMoves[gCurrentMove].effect != EFFECT_FALSE_SWIPE && !gProtectStructs[gBankTarget].endured
     && !gSpecialStatuses[gBankTarget].focusBanded)
        goto END;

    if (gBattleMons[gBankTarget].hp > gBattleMoveDamage)
        goto END;

    gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;

    if (gProtectStructs[gBankTarget].endured)
    {
        gBattleMoveFlags |= MOVESTATUS_ENDURED;
    }
    else if (gSpecialStatuses[gBankTarget].focusBanded)
    {
        gBattleMoveFlags |= MOVESTATUS_HUNGON;
        gLastUsedItem = gBattleMons[gBankTarget].item;
    }

    END:
        gBattlescriptCurrInstr++;
}

void atk08_dmg_adjustment2(void) // The same as 0x7 except it doesn't check for false swipe move effect.
{
    u8 holdEffect, quality;

    ApplyRandomDmgMultiplier();

    if (gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY)
    {
        holdEffect = gEnigmaBerries[gBankTarget].holdEffect, quality = gEnigmaBerries[gBankTarget].holdEffectParam;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(gBattleMons[gBankTarget].item);
        quality = ItemId_GetHoldEffectParam(gBattleMons[gBankTarget].item);
    }

    gStringBank = gBankTarget;

    if (holdEffect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < quality)
    {
        RecordItemEffectBattle(gBankTarget, holdEffect);
        gSpecialStatuses[gBankTarget].focusBanded = 1;
    }
    if (gBattleMons[gBankTarget].status2 & STATUS2_SUBSTITUTE)
        goto END;
    if (!gProtectStructs[gBankTarget].endured && !gSpecialStatuses[gBankTarget].focusBanded)
        goto END;
    if (gBattleMons[gBankTarget].hp > gBattleMoveDamage)
        goto END;

    gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;

    if (gProtectStructs[gBankTarget].endured)
    {
        gBattleMoveFlags |= MOVESTATUS_ENDURED;
    }
    else if (gSpecialStatuses[gBankTarget].focusBanded)
    {
        gBattleMoveFlags |= MOVESTATUS_HUNGON;
        gLastUsedItem = gBattleMons[gBankTarget].item;
    }

    END:
        gBattlescriptCurrInstr++;
}

void atk09_attackanimation(void)
{
    if (gBattleExecBuffer)
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
        if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
        {
            u8 multihit;

            gActiveBank = gBankAttacker;

            if (gBattleMons[gBankTarget].status2 & STATUS2_SUBSTITUTE)
                multihit = gMultiHitCounter;
            else if (gMultiHitCounter != 0 && gMultiHitCounter != 1)
            {
                if (gBattleMons[gBankTarget].hp <= gBattleMoveDamage)
                    multihit = 1;
                else
                    multihit = gMultiHitCounter;
            }
            else
                multihit = gMultiHitCounter;

            EmitMoveAnimation(0, gCurrentMove, gBattleScripting.animTurn, gBattleMovePower, gBattleMoveDamage, gBattleMons[gBankAttacker].friendship, &gDisableStructs[gBankAttacker], multihit);
            gBattleScripting.animTurn += 1;
            gBattleScripting.animTargetsHit += 1;
            MarkBufferBankForExecution(gBankAttacker);
            gBattlescriptCurrInstr++;
        }
        else
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);
            gBattlescriptCurrInstr = BattleScript_Pausex20;
        }
    }
}

void atk0A_waitanimation(void)
{
    if (gBattleExecBuffer == 0)
        gBattlescriptCurrInstr++;
}

void atk0B_healthbarupdate(void)
{
    if (gBattleExecBuffer)
        return;

    if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
    {
        gActiveBank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));

        if (gBattleMons[gActiveBank].status2 & STATUS2_SUBSTITUTE && gDisableStructs[gActiveBank].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            PrepareStringBattle(0x80, gActiveBank);
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

            EmitHealthBarUpdate(0, healthValue);
            MarkBufferBankForExecution(gActiveBank);

            if (GetBankSide(gActiveBank) == SIDE_PLAYER && gBattleMoveDamage > 0)
                gBattleResults.unk5_0 = 1;
        }
    }

    gBattlescriptCurrInstr += 2;
}

void atk0C_datahpupdate(void)
{
    u32 moveType;

    if (gBattleExecBuffer)
        return;

    if (gBattleStruct->dynamicMoveType == 0)
        moveType = gBattleMoves[gCurrentMove].type;
    else if (!(gBattleStruct->dynamicMoveType & 0x40))
        moveType = gBattleStruct->dynamicMoveType & 0x3F;
    else
        moveType = gBattleMoves[gCurrentMove].type;

    if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
    {
        gActiveBank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
        if (gBattleMons[gActiveBank].status2 & STATUS2_SUBSTITUTE && gDisableStructs[gActiveBank].substituteHP && !(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE))
        {
            if (gDisableStructs[gActiveBank].substituteHP >= gBattleMoveDamage)
            {
                if (gSpecialStatuses[gActiveBank].moveturnLostHP == 0)
                    gSpecialStatuses[gActiveBank].moveturnLostHP = gBattleMoveDamage;
                gDisableStructs[gActiveBank].substituteHP -= gBattleMoveDamage;
                gHpDealt = gBattleMoveDamage;
            }
            else
            {
                if (gSpecialStatuses[gActiveBank].moveturnLostHP == 0)
                    gSpecialStatuses[gActiveBank].moveturnLostHP = gDisableStructs[gActiveBank].substituteHP;
                gHpDealt = gDisableStructs[gActiveBank].substituteHP;
                gDisableStructs[gActiveBank].substituteHP = 0;
            }
            // check substitute fading
            if (gDisableStructs[gActiveBank].substituteHP == 0)
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
                gBattleMons[gActiveBank].hp -= gBattleMoveDamage;
                if (gBattleMons[gActiveBank].hp > gBattleMons[gActiveBank].maxHP)
                    gBattleMons[gActiveBank].hp = gBattleMons[gActiveBank].maxHP;

            }
            else // hp goes down
            {
                if (gHitMarker & HITMARKER_x20)
                {
                    gHitMarker &= ~(HITMARKER_x20);
                }
                else
                {
                    gTakenDmg[gActiveBank] += gBattleMoveDamage;
                    if (BSScriptRead8(gBattlescriptCurrInstr + 1) == BS_GET_TARGET)
                        gTakenDmgBanks[gActiveBank] = gBankAttacker;
                    else
                        gTakenDmgBanks[gActiveBank] = gBankTarget;
                }

                if (gBattleMons[gActiveBank].hp > gBattleMoveDamage)
                {
                    gBattleMons[gActiveBank].hp -= gBattleMoveDamage;
                    gHpDealt = gBattleMoveDamage;
                }
                else
                {
                    gHpDealt = gBattleMons[gActiveBank].hp;
                    gBattleMons[gActiveBank].hp = 0;
                }

                if (!gSpecialStatuses[gActiveBank].moveturnLostHP && !(gHitMarker & HITMARKER_x100000))
                    gSpecialStatuses[gActiveBank].moveturnLostHP = gHpDealt;

                if (moveType <= 8 && !(gHitMarker & HITMARKER_x100000) && gCurrentMove != MOVE_PAIN_SPLIT)
                {
                    gProtectStructs[gActiveBank].physicalDmg = gHpDealt;
                    gSpecialStatuses[gActiveBank].moveturnLostHP_physical = gHpDealt;
                    if (BSScriptRead8(gBattlescriptCurrInstr + 1) == BS_GET_TARGET)
                    {
                        gProtectStructs[gActiveBank].physicalBank = gBankAttacker;
                        gSpecialStatuses[gActiveBank].moveturnPhysicalBank = gBankAttacker;
                    }
                    else
                    {
                        gProtectStructs[gActiveBank].physicalBank = gBankTarget;
                        gSpecialStatuses[gActiveBank].moveturnPhysicalBank = gBankTarget;
                    }
                }
                else if (moveType > 8 && !(gHitMarker & HITMARKER_x100000))
                {
                    gProtectStructs[gActiveBank].specialDmg = gHpDealt;
                    gSpecialStatuses[gActiveBank].moveturnLostHP_special = gHpDealt;
                    if (BSScriptRead8(gBattlescriptCurrInstr + 1) == BS_GET_TARGET)
                    {
                        gProtectStructs[gActiveBank].specialBank = gBankAttacker;
                        gSpecialStatuses[gActiveBank].moveturnSpecialBank = gBankAttacker;
                    }
                    else
                    {
                        gProtectStructs[gActiveBank].specialBank = gBankTarget;
                        gSpecialStatuses[gActiveBank].moveturnSpecialBank = gBankTarget;
                    }
                }
            }
            gHitMarker &= ~(HITMARKER_x100000);
            EmitSetAttributes(0, REQUEST_HP_BATTLE, 0, 2, &gBattleMons[gActiveBank].hp);
            MarkBufferBankForExecution(gActiveBank);
        }
    }
    else
    {
        gActiveBank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
        if (gSpecialStatuses[gActiveBank].moveturnLostHP == 0)
            gSpecialStatuses[gActiveBank].moveturnLostHP = 0xFFFF;
    }
    gBattlescriptCurrInstr += 2;
}

void atk0D_critmessage(void)
{
    if (gBattleExecBuffer == 0)
    {
        if (gCritMultiplier == 2 && !(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
        {
            PrepareStringBattle(0xD9, gBankAttacker);
            gBattleCommunication[MSG_DISPLAY] = 1;
        }
        gBattlescriptCurrInstr++;
    }
}

void atk0E_effectiveness_sound(void)
{
    if (gBattleExecBuffer)
        return;

    gActiveBank = gBankTarget;
    if (!(gBattleMoveFlags & MOVESTATUS_MISSED))
    {
        switch (gBattleMoveFlags & (u8)(~(MOVESTATUS_MISSED)))
        {
        case MOVESTATUS_SUPEREFFECTIVE:
            EmitEffectivenessSound(0, SE_KOUKA_H);
            MarkBufferBankForExecution(gActiveBank);
            break;
        case MOVESTATUS_NOTVERYEFFECTIVE:
            EmitEffectivenessSound(0, SE_KOUKA_L);
            MarkBufferBankForExecution(gActiveBank);
            break;
        case MOVESTATUS_NOTAFFECTED:
        case MOVESTATUS_FAILED:
            // no sound
            break;
        case MOVESTATUS_ENDURED:
        case MOVESTATUS_ONEHITKO:
        case MOVESTATUS_HUNGON:
        default:
            if (gBattleMoveFlags & MOVESTATUS_SUPEREFFECTIVE)
            {
                EmitEffectivenessSound(0, SE_KOUKA_H);
                MarkBufferBankForExecution(gActiveBank);
            }
            else if (gBattleMoveFlags & MOVESTATUS_NOTVERYEFFECTIVE)
            {
                EmitEffectivenessSound(0, SE_KOUKA_L);
                MarkBufferBankForExecution(gActiveBank);
            }
            else if (!(gBattleMoveFlags & (MOVESTATUS_NOTAFFECTED | MOVESTATUS_FAILED)))
            {
                EmitEffectivenessSound(0, SE_KOUKA_M);
                MarkBufferBankForExecution(gActiveBank);
            }
            break;
        }
    }
    gBattlescriptCurrInstr++;
}

void atk0F_resultmessage(void)
{
    u32 stringId = 0;

    if (gBattleExecBuffer)
        return;

    if (gBattleMoveFlags & MOVESTATUS_MISSED && (!(gBattleMoveFlags & MOVESTATUS_NOTAFFECTED) || gBattleCommunication[6] > 2))
    {
        stringId = gMissStringIds[gBattleCommunication[6]];
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
    else
    {
        gBattleCommunication[MSG_DISPLAY] = 1;
        switch (gBattleMoveFlags & (u8)(~(MOVESTATUS_MISSED)))
        {
        case MOVESTATUS_SUPEREFFECTIVE:
            stringId = 0xDE;
            break;
        case MOVESTATUS_NOTVERYEFFECTIVE:
            stringId = 0xDD;
            break;
        case MOVESTATUS_ONEHITKO:
            stringId = 0xDA;
            break;
        case MOVESTATUS_ENDURED:
            stringId = 0x99;
            break;
        case MOVESTATUS_FAILED:
            stringId = 0xE5;
            break;
        case MOVESTATUS_NOTAFFECTED:
            stringId = 0x1B;
            break;
        case MOVESTATUS_HUNGON:
            gLastUsedItem = gBattleMons[gBankTarget].item;
            gStringBank = gBankTarget;
            gBattleMoveFlags &= ~(MOVESTATUS_ENDURED | MOVESTATUS_HUNGON);
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_HangedOnMsg;
            return;
        default:
            if (gBattleMoveFlags & MOVESTATUS_NOTAFFECTED)
            {
                stringId = 0x1B;
            }
            else if (gBattleMoveFlags & MOVESTATUS_ONEHITKO)
            {
                gBattleMoveFlags &= ~(MOVESTATUS_ONEHITKO);
                gBattleMoveFlags &= ~(MOVESTATUS_SUPEREFFECTIVE);
                gBattleMoveFlags &= ~(MOVESTATUS_NOTVERYEFFECTIVE);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_OneHitKOMsg;
                return;
            }
            else if (gBattleMoveFlags & MOVESTATUS_ENDURED)
            {
                gBattleMoveFlags &= ~(MOVESTATUS_ENDURED | MOVESTATUS_HUNGON);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_EnduredMsg;
                return;
            }
            else if (gBattleMoveFlags & MOVESTATUS_HUNGON)
            {
                gLastUsedItem = gBattleMons[gBankTarget].item;
                gStringBank = gBankTarget;
                gBattleMoveFlags &= ~(MOVESTATUS_ENDURED | MOVESTATUS_HUNGON);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_HangedOnMsg;
                return;
            }
            else if (gBattleMoveFlags & MOVESTATUS_FAILED)
            {
                stringId = 0xE5;
            }
            else
            {
                gBattleCommunication[MSG_DISPLAY] = 0;
            }
        }
    }

    if (stringId)
        PrepareStringBattle(stringId, gBankAttacker);

    gBattlescriptCurrInstr++;
}

void atk10_printstring(void)
{
    if (gBattleExecBuffer == 0)
    {
        u16 var = BS2ScriptRead16(gBattlescriptCurrInstr + 1);
        PrepareStringBattle(var, gBankAttacker);
        gBattlescriptCurrInstr += 3;
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

void atk11_printstring_playeronly(void)
{
    gActiveBank = gBankAttacker;

    EmitPrintStringPlayerOnly(0, BS2ScriptRead16(gBattlescriptCurrInstr + 1));
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 3;
    gBattleCommunication[MSG_DISPLAY] = 1;
}

void atk12_waitmessage(void)
{
    if (gBattleExecBuffer == 0)
    {
        if (!gBattleCommunication[MSG_DISPLAY])
        {
            gBattlescriptCurrInstr += 3;
        }
        else
        {
            u16 toWait = BS2ScriptRead16(gBattlescriptCurrInstr + 1);
            if (++gPauseCounterBattle >= toWait)
            {
                gPauseCounterBattle = 0;
                gBattlescriptCurrInstr += 3;
                gBattleCommunication[MSG_DISPLAY] = 0;
            }
        }
    }
}

void atk13_printfromtable(void)
{
    if (gBattleExecBuffer == 0)
    {
        u16 *ptr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        ptr += gBattleCommunication[MULTISTRING_CHOOSER];

        PrepareStringBattle(*(u16*)ptr, gBankAttacker);

        gBattlescriptCurrInstr += 5;
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

void atk14_printfromtable_playeronly(void)
{
    if (gBattleExecBuffer == 0)
    {
        u16 *ptr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        ptr += gBattleCommunication[MULTISTRING_CHOOSER];

        gActiveBank = gBankAttacker;
        EmitPrintStringPlayerOnly(0, *(u16*)ptr);
        MarkBufferBankForExecution(gActiveBank);

        gBattlescriptCurrInstr += 5;
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

u8 BankGetTurnOrder(u8 bank)
{
    s32 i;
    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (gTurnOrder[i] == bank)
            break;
    }
    return i;
}

#define INCREMENT_RESET_RETURN                  \
{                                               \
    gBattlescriptCurrInstr++;                   \
    gBattleCommunication[MOVE_EFFECT_BYTE] = 0; \
    return;                                     \
}

#define RESET_RETURN                            \
{                                               \
    gBattleCommunication[MOVE_EFFECT_BYTE] = 0; \
    return;                                     \
}

void SetMoveEffect(bool8 primary, u8 certain)
{
    bool32 statusChanged = FALSE;
    u8 affectsUser = 0; // 0x40 otherwise
    bool32 noSunCanFreeze = TRUE;

    if (gBattleCommunication[MOVE_EFFECT_BYTE] & MOVE_EFFECT_AFFECTS_USER)
    {
        gEffectBank = gBankAttacker; // bank that effects get applied on
        gBattleCommunication[MOVE_EFFECT_BYTE] &= ~(MOVE_EFFECT_AFFECTS_USER);
        affectsUser = MOVE_EFFECT_AFFECTS_USER;
        gBattleScripting.bank = gBankTarget; // theoretically the attacker
    }
    else
    {
        gEffectBank = gBankTarget;
        gBattleScripting.bank = gBankAttacker;
    }

    if (gBattleMons[gEffectBank].ability == ABILITY_SHIELD_DUST && !(gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
        && !primary && gBattleCommunication[MOVE_EFFECT_BYTE] <= 9)
        INCREMENT_RESET_RETURN

    if (gSideAffecting[GET_BANK_SIDE(gEffectBank)] & SIDE_STATUS_SAFEGUARD && !(gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
        && !primary && gBattleCommunication[MOVE_EFFECT_BYTE] <= 7)
        INCREMENT_RESET_RETURN

    if (gBattleMons[gEffectBank].hp == 0
        && gBattleCommunication[MOVE_EFFECT_BYTE] != MOVE_EFFECT_PAYDAY
        && gBattleCommunication[MOVE_EFFECT_BYTE] != MOVE_EFFECT_STEAL_ITEM)
        INCREMENT_RESET_RETURN

    if (gBattleMons[gEffectBank].status2 & STATUS2_SUBSTITUTE && affectsUser != MOVE_EFFECT_AFFECTS_USER)
        INCREMENT_RESET_RETURN

    if (gBattleCommunication[MOVE_EFFECT_BYTE] <= 6) // status change
    {
        switch (gStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]])
        {
        case STATUS_SLEEP:
            // check active uproar
            if (gBattleMons[gEffectBank].ability != ABILITY_SOUNDPROOF)
            {
                for (gActiveBank = 0;
                    gActiveBank < gNoOfAllBanks && !(gBattleMons[gActiveBank].status2 & STATUS2_UPROAR);
                    gActiveBank++)
                {}
            }
            else
                gActiveBank = gNoOfAllBanks;

            if (gBattleMons[gEffectBank].status1)
                break;
            if (gActiveBank != gNoOfAllBanks)
                break;
            if (gBattleMons[gEffectBank].ability == ABILITY_VITAL_SPIRIT)
                break;
            if (gBattleMons[gEffectBank].ability == ABILITY_INSOMNIA)
                break;

            CancelMultiTurnMoves(gEffectBank);
            statusChanged = TRUE;
            break;
        case STATUS_POISON:
            if (gBattleMons[gEffectBank].ability == ABILITY_IMMUNITY
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                gLastUsedAbility = ABILITY_IMMUNITY;
                RecordAbilityBattle(gEffectBank, ABILITY_IMMUNITY);

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
            if ((gBattleMons[gEffectBank].type1 == TYPE_POISON || gBattleMons[gEffectBank].type2 == TYPE_POISON
                 || gBattleMons[gEffectBank].type1 == TYPE_STEEL || gBattleMons[gEffectBank].type2 == TYPE_STEEL)
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                RESET_RETURN
            }
            if (gBattleMons[gEffectBank].type1 == TYPE_POISON)
                break;
            if (gBattleMons[gEffectBank].type2 == TYPE_POISON)
                break;
            if (gBattleMons[gEffectBank].type1 == TYPE_STEEL)
                break;
            if (gBattleMons[gEffectBank].type2 == TYPE_STEEL)
                break;
            if (gBattleMons[gEffectBank].status1)
                break;
            if (gBattleMons[gEffectBank].ability == ABILITY_IMMUNITY)
                break;

            statusChanged = TRUE;
            break;
        case STATUS_BURN:
            if (gBattleMons[gEffectBank].ability == ABILITY_WATER_VEIL
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                gLastUsedAbility = ABILITY_WATER_VEIL;
                RecordAbilityBattle(gEffectBank, ABILITY_WATER_VEIL);

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
            if ((gBattleMons[gEffectBank].type1 == TYPE_FIRE
                 || gBattleMons[gEffectBank].type2 == TYPE_FIRE)
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_BRNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                RESET_RETURN
            }
            if (gBattleMons[gEffectBank].type1 == TYPE_FIRE)
                break;
            if (gBattleMons[gEffectBank].type2 == TYPE_FIRE)
                break;
            if (gBattleMons[gEffectBank].ability == ABILITY_WATER_VEIL)
                break;
            if (gBattleMons[gEffectBank].status1)
                break;

            statusChanged = TRUE;
            break;
        case STATUS_FREEZE:
            if (WEATHER_HAS_EFFECT && gBattleWeather & WEATHER_SUN_ANY)
                noSunCanFreeze = FALSE;
            if (gBattleMons[gEffectBank].type1 == TYPE_ICE)
                break;
            if (gBattleMons[gEffectBank].type2 == TYPE_ICE)
                break;
            if (gBattleMons[gEffectBank].status1)
                break;
            if (noSunCanFreeze == 0)
                break;
            if (gBattleMons[gEffectBank].ability == ABILITY_MAGMA_ARMOR)
                break;

            CancelMultiTurnMoves(gEffectBank);
            statusChanged = TRUE;
            break;
        case STATUS_PARALYSIS:
            if (gBattleMons[gEffectBank].ability == ABILITY_LIMBER)
            {
                if (primary == TRUE || certain == MOVE_EFFECT_CERTAIN)
                {
                    gLastUsedAbility = ABILITY_LIMBER;
                    RecordAbilityBattle(gEffectBank, ABILITY_LIMBER);

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
            if (gBattleMons[gEffectBank].status1)
                break;

            statusChanged = TRUE;
            break;
        case STATUS_TOXIC_POISON:
            if (gBattleMons[gEffectBank].ability == ABILITY_IMMUNITY && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                gLastUsedAbility = ABILITY_IMMUNITY;
                RecordAbilityBattle(gEffectBank, ABILITY_IMMUNITY);

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
            if ((gBattleMons[gEffectBank].type1 == TYPE_POISON || gBattleMons[gEffectBank].type2 == TYPE_POISON
                 || gBattleMons[gEffectBank].type1 == TYPE_STEEL || gBattleMons[gEffectBank].type2 == TYPE_STEEL)
                && (gHitMarker & HITMARKER_IGNORE_SAFEGUARD)
                && (primary == TRUE || certain == MOVE_EFFECT_CERTAIN))
            {
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_PSNPrevention;

                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
                RESET_RETURN
            }
            if (gBattleMons[gEffectBank].status1)
                break;
            if (gBattleMons[gEffectBank].type1 != TYPE_POISON
                && gBattleMons[gEffectBank].type2 != TYPE_POISON
                && gBattleMons[gEffectBank].type1 != TYPE_STEEL
                && gBattleMons[gEffectBank].type2 != TYPE_STEEL)
            {
                if (gBattleMons[gEffectBank].ability == ABILITY_IMMUNITY)
                    break;

                // It's redundant, because at this point we know the status1 value is 0.
                gBattleMons[gEffectBank].status1 &= ~(STATUS_TOXIC_POISON);
                gBattleMons[gEffectBank].status1 &= ~(STATUS_POISON);
                statusChanged = TRUE;
                break;
            }
            else
            {
                gBattleMoveFlags |= MOVESTATUS_NOTAFFECTED;
            }
            break;
        }
        if (statusChanged == TRUE)
        {
            BattleScriptPush(gBattlescriptCurrInstr + 1);

            if (gStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]] == STATUS_SLEEP)
                gBattleMons[gEffectBank].status1 |= ((Random() & 3) + 2);
            else
                gBattleMons[gEffectBank].status1 |= gStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]];

            gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];

            gActiveBank = gEffectBank;
            EmitSetAttributes(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gEffectBank].status1);
            MarkBufferBankForExecution(gActiveBank);

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

            if (gBattleCommunication[MOVE_EFFECT_BYTE] == MOVE_EFFECT_POISON
             || gBattleCommunication[MOVE_EFFECT_BYTE] == MOVE_EFFECT_TOXIC
             || gBattleCommunication[MOVE_EFFECT_BYTE] == MOVE_EFFECT_PARALYSIS
             || gBattleCommunication[MOVE_EFFECT_BYTE] == MOVE_EFFECT_BURN)
             {
                u8* synchronizeEffect = &gBattleStruct->synchronizeMoveEffect;
                *synchronizeEffect = gBattleCommunication[MOVE_EFFECT_BYTE];
                gHitMarker |= HITMARKER_SYNCHRONISE_EFFECT;
             }
            return;
        }
        else if (statusChanged == FALSE)
        {
            gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
            gBattlescriptCurrInstr++;
            return;
        }
        return;
    }
    else
    {
        if (gBattleMons[gEffectBank].status2 & gStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]])
        {
            gBattlescriptCurrInstr++;
        }
        else
        {
            u8 side;
            switch (gBattleCommunication[MOVE_EFFECT_BYTE])
            {
            case MOVE_EFFECT_CONFUSION:
                if (gBattleMons[gEffectBank].ability == ABILITY_OWN_TEMPO
                    || gBattleMons[gEffectBank].status2 & STATUS2_CONFUSION)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gEffectBank].status2 |= (((Random()) % 0x4)) + 2;

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
                }
                break;
            case MOVE_EFFECT_FLINCH:
                if (gBattleMons[gEffectBank].ability == ABILITY_INNER_FOCUS)
                {
                    if (primary == TRUE || certain == MOVE_EFFECT_CERTAIN)
                    {
                        gLastUsedAbility = ABILITY_INNER_FOCUS;
                        RecordAbilityBattle(gEffectBank, ABILITY_INNER_FOCUS);
                        gBattlescriptCurrInstr = BattleScript_FlinchPrevention;
                    }
                    else
                    {
                        gBattlescriptCurrInstr++;
                    }
                }
                else
                {
                    if (BankGetTurnOrder(gEffectBank) > gCurrentMoveTurn)
                        gBattleMons[gEffectBank].status2 |= gStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]];
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_UPROAR:
                if (!(gBattleMons[gEffectBank].status2 & STATUS2_UPROAR))
                {

                    gBattleMons[gEffectBank].status2 |= STATUS2_MULTIPLETURNS;
                    gLockedMoves[gEffectBank] = gCurrentMove;
                    gBattleMons[gEffectBank].status2 |= ((Random() & 3) + 2) << 4;

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
                }
                else
                {
                    gBattlescriptCurrInstr++;
                }
                break;
            case MOVE_EFFECT_PAYDAY:
                if (GET_BANK_SIDE(gBankAttacker) == SIDE_PLAYER)
                {
                    u16 PayDay = gPaydayMoney;
                    gPaydayMoney += (gBattleMons[gBankAttacker].level * 5);
                    if (PayDay > gPaydayMoney)
                        gPaydayMoney = 0xFFFF;
                }
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
                break;
            case MOVE_EFFECT_TRI_ATTACK:
                if (gBattleMons[gEffectBank].status1)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleCommunication[MOVE_EFFECT_BYTE] = Random() % 3 + 3;
                    SetMoveEffect(FALSE, 0);
                }
                break;
            case MOVE_EFFECT_CHARGING:
                gBattleMons[gEffectBank].status2 |= STATUS2_MULTIPLETURNS;
                gLockedMoves[gEffectBank] = gCurrentMove;
                gProtectStructs[gEffectBank].chargingTurn = 1;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_WRAP:
                if (gBattleMons[gEffectBank].status2 & STATUS2_WRAPPED)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gEffectBank].status2 |= ((Random() & 3) + 3) << 0xD;

                    *(gBattleStruct->wrappedMove + gEffectBank * 2 + 0) = gCurrentMove;
                    *(gBattleStruct->wrappedMove + gEffectBank * 2 + 1) = gCurrentMove >> 8;
                    *(gBattleStruct->wrappedBy + gEffectBank) = gBankAttacker;

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];

                    for (gBattleCommunication[MULTISTRING_CHOOSER] = 0; ; gBattleCommunication[MULTISTRING_CHOOSER]++)
                    {
                        if (gBattleCommunication[MULTISTRING_CHOOSER] > 4)
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
                gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
                break;
            case MOVE_EFFECT_ATK_PLUS_1:
            case MOVE_EFFECT_DEF_PLUS_1:
            case MOVE_EFFECT_SPD_PLUS_1:
            case MOVE_EFFECT_SP_ATK_PLUS_1:
            case MOVE_EFFECT_SP_DEF_PLUS_1:
            case MOVE_EFFECT_ACC_PLUS_1:
            case MOVE_EFFECT_EVS_PLUS_1:
                if (ChangeStatBuffs(SET_STAT_BUFF_VALUE(1),
                                    gBattleCommunication[MOVE_EFFECT_BYTE] - MOVE_EFFECT_ATK_PLUS_1 + 1,
                                    affectsUser, 0))
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleCommunication[MOVE_EFFECT_BYTE] & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
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
                                    gBattleCommunication[MOVE_EFFECT_BYTE] - MOVE_EFFECT_ATK_MINUS_1 + 1,
                                     affectsUser, 0))
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleCommunication[MOVE_EFFECT_BYTE] & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
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
                                    gBattleCommunication[MOVE_EFFECT_BYTE] - MOVE_EFFECT_ATK_PLUS_2 + 1,
                                    affectsUser, 0))
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleCommunication[MOVE_EFFECT_BYTE] & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
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
                                    gBattleCommunication[MOVE_EFFECT_BYTE] - MOVE_EFFECT_ATK_MINUS_2 + 1,
                                    affectsUser, 0))
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleScripting.animArg1 = gBattleCommunication[MOVE_EFFECT_BYTE] & ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                    gBattleScripting.animArg2 = 0;
                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_StatDown;
                }
                break;
            case MOVE_EFFECT_RECHARGE:
                gBattleMons[gEffectBank].status2 |= STATUS2_RECHARGE;
                gDisableStructs[gEffectBank].rechargeCounter = 2;
                gLockedMoves[gEffectBank] = gCurrentMove;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_RAGE:
                gBattleMons[gBankAttacker].status2 |= STATUS2_RAGE;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_STEAL_ITEM:
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_x4000000)
                    {
                        gBattlescriptCurrInstr++;
                        break;
                    }

                    side = GetBankSide(gBankAttacker);
                    if (GetBankSide(gBankAttacker) == SIDE_OPPONENT
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
                        && (gWishFutureKnock.knockedOffPokes[side] & gBitTable[gBattlePartyID[gBankAttacker]]))
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else if (gBattleMons[gBankTarget].item
                        && gBattleMons[gBankTarget].ability == ABILITY_STICKY_HOLD)
                    {
                        BattleScriptPushCursor();
                        gBattlescriptCurrInstr = BattleScript_NoItemSteal;

                        gLastUsedAbility = gBattleMons[gBankTarget].ability;
                        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
                    }
                    else if (gBattleMons[gBankAttacker].item
                        || gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY
                        || (gBattleMons[gBankTarget].item > 0x78 && gBattleMons[gBankTarget].item < 0x85)
                        || gBattleMons[gBankTarget].item == 0)
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else
                    {
                        // This is a leftover from R/S direct use of ewram addresses
                        void** memes1 = (void**)(&gBattleStruct);
                        void* memes2 = (void*)((u32)(gBankAttacker * 2 + offsetof(struct BattleStruct, field_D0)));
                        u16* memes3 = (u16*)(((void*)(*memes1) + (u32)(memes2)));
                        gLastUsedItem = *memes3 = gBattleMons[gBankTarget].item;

                        // A sane representation of this would simply be:
                        // gLastUsedItem = gBattleStruct->field_D0[gBankAttacker] = gBattleMons[gBankTarget].item;

                        gBattleMons[gBankTarget].item = 0;

                        gActiveBank = gBankAttacker;
                        EmitSetAttributes(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gLastUsedItem);
                        MarkBufferBankForExecution(gBankAttacker);

                        gActiveBank = gBankTarget;
                        EmitSetAttributes(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gBankTarget].item);
                        MarkBufferBankForExecution(gBankTarget);

                        BattleScriptPush(gBattlescriptCurrInstr + 1);
                        gBattlescriptCurrInstr = BattleScript_ItemSteal;

                        *(u8*)((u8*)(&gBattleStruct->choicedMove[gBankTarget]) + 0) = 0;
                        *(u8*)((u8*)(&gBattleStruct->choicedMove[gBankTarget]) + 1) = 0;
                    }

                }
                break;
            case MOVE_EFFECT_PREVENT_ESCAPE:
                gBattleMons[gBankTarget].status2 |= STATUS2_ESCAPE_PREVENTION;
                gDisableStructs[gBankTarget].bankPreventingEscape = gBankAttacker;
                gBattlescriptCurrInstr++;
                break;
            case MOVE_EFFECT_NIGHTMARE:
                gBattleMons[gBankTarget].status2 |= STATUS2_NIGHTMARE;
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
            case MOVE_EFFECT_REMOVE_PARALYSIS: // Smelling salts
                if (!(gBattleMons[gBankTarget].status1 & STATUS_PARALYSIS))
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gBankTarget].status1 &= ~(STATUS_PARALYSIS);

                    gActiveBank = gBankTarget;
                    EmitSetAttributes(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
                    MarkBufferBankForExecution(gActiveBank);

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_TargetPRLZHeal;
                }
                break;
            case MOVE_EFFECT_ATK_DEF_DOWN: // SuperPower
                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = BattleScript_AtkDefDown;
                break;
            case MOVE_EFFECT_RECOIL_33_PARALYSIS: // Volt Tackle
                gBattleMoveDamage = gHpDealt / 3;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;

                BattleScriptPush(gBattlescriptCurrInstr + 1);
                gBattlescriptCurrInstr = gMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
                break;
            case MOVE_EFFECT_THRASH:
                if (gBattleMons[gEffectBank].status2 & STATUS2_LOCK_CONFUSE)
                {
                    gBattlescriptCurrInstr++;
                }
                else
                {
                    gBattleMons[gEffectBank].status2 |= STATUS2_MULTIPLETURNS;
                    gLockedMoves[gEffectBank] = gCurrentMove;
                    gBattleMons[gEffectBank].status2 |= (((Random() & 1) + 2) << 0xA);
                }
                break;
            case MOVE_EFFECT_KNOCK_OFF:
                if (gBattleMons[gEffectBank].ability == ABILITY_STICKY_HOLD)
                {
                    if (gBattleMons[gEffectBank].item == 0)
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else
                    {
                        gLastUsedAbility = ABILITY_STICKY_HOLD;
                        gBattlescriptCurrInstr = BattleScript_StickyHoldOnKnockOff;
                        RecordAbilityBattle(gEffectBank, ABILITY_STICKY_HOLD);
                    }
                    break;
                }
                if (gBattleMons[gEffectBank].item)
                {
                    side = GetBankSide(gEffectBank);

                    gLastUsedItem = gBattleMons[gEffectBank].item;
                    gBattleMons[gEffectBank].item = 0;
                    gWishFutureKnock.knockedOffPokes[side] |= gBitTable[gBattlePartyID[gEffectBank]];

                    BattleScriptPush(gBattlescriptCurrInstr + 1);
                    gBattlescriptCurrInstr = BattleScript_KnockedOff;

                    *(u8*)((u8*)(&gBattleStruct->choicedMove[gEffectBank]) + 0) = 0;
                    *(u8*)((u8*)(&gBattleStruct->choicedMove[gEffectBank]) + 1) = 0;
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
            }
        }
    }

    gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
}

void atk15_seteffectwithchancetarget(void)
{
    u32 percentChance;

    if (gBattleMons[gBankAttacker].ability == ABILITY_SERENE_GRACE)
        percentChance = gBattleMoves[gCurrentMove].secondaryEffectChance * 2;
    else
        percentChance = gBattleMoves[gCurrentMove].secondaryEffectChance;

    if (gBattleCommunication[MOVE_EFFECT_BYTE] & MOVE_EFFECT_CERTAIN
        && !(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
    {
        gBattleCommunication[MOVE_EFFECT_BYTE] &= ~(MOVE_EFFECT_CERTAIN);
        SetMoveEffect(0, MOVE_EFFECT_CERTAIN);
    }
    else if (Random() % 100 < percentChance
             && gBattleCommunication[MOVE_EFFECT_BYTE]
             && !(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
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

    gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
    gBattleScripting.field_16 = 0;
}

void atk16_seteffectprimary(void)
{
    SetMoveEffect(TRUE, 0);
}

void atk17_seteffectsecondary(void)
{
    SetMoveEffect(FALSE, 0);
}

void atk18_status_effect_clear(void)
{
    gActiveBank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));

    if (gBattleCommunication[MOVE_EFFECT_BYTE] <= MOVE_EFFECT_TOXIC)
        gBattleMons[gActiveBank].status1 &= (~gStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]]);
    else
        gBattleMons[gActiveBank].status2 &= (~gStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]]);

    gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
    gBattlescriptCurrInstr += 2;
    gBattleScripting.field_16 = 0;
}

void atk19_faint_pokemon(void)
{
    const u8 *BS_ptr;

    if (gBattlescriptCurrInstr[2] != 0)
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
        if (gHitMarker & HITMARKER_FAINTED(gActiveBank))
        {
            BS_ptr = BSScriptReadPtr(gBattlescriptCurrInstr + 3);

            BattleScriptPop();
            gBattlescriptCurrInstr = BS_ptr;
            gSideAffecting[GetBankSide(gActiveBank)] &= ~(SIDE_STATUS_SPIKES_DAMAGED);
        }
        else
        {
            gBattlescriptCurrInstr += 7;
        }
    }
    else
    {
        u8 bank;

        if (gBattlescriptCurrInstr[1] == BS_GET_ATTACKER)
        {
            gActiveBank = gBankAttacker;
            bank = gBankTarget;
            BS_ptr = BattleScript_FaintAttacker;
        }
        else
        {
            gActiveBank = gBankTarget;
            bank = gBankAttacker;
            BS_ptr = BattleScript_FaintTarget;
        }
        if (!(gAbsentBankFlags & gBitTable[gActiveBank])
         && gBattleMons[gActiveBank].hp == 0)
        {
            gHitMarker |= HITMARKER_FAINTED(gActiveBank);
            BattleScriptPush(gBattlescriptCurrInstr + 7);
            gBattlescriptCurrInstr = BS_ptr;
            if (GetBankSide(gActiveBank) == SIDE_PLAYER)
            {
                gHitMarker |= HITMARKER_x400000;
                if (gBattleResults.playerFaintCounter < 0xFF)
                    gBattleResults.playerFaintCounter++;
                AdjustFriendshipOnBattleFaint(gActiveBank);
            }
            else
            {
                if (gBattleResults.opponentFaintCounter < 0xFF)
                    gBattleResults.opponentFaintCounter++;
                gBattleResults.lastOpponentSpecies = GetMonData(&gEnemyParty[gBattlePartyID[gActiveBank]], MON_DATA_SPECIES, NULL);
            }
            if ((gHitMarker & HITMARKER_DESTINYBOND) && gBattleMons[gBankAttacker].hp != 0)
            {
                gHitMarker &= ~(HITMARKER_DESTINYBOND);
                BattleScriptPush(gBattlescriptCurrInstr);
                gBattleMoveDamage = gBattleMons[bank].hp;
                gBattlescriptCurrInstr = BattleScript_DestinyBondTakesLife;
            }
            if ((gStatuses3[gBankTarget] & STATUS3_GRUDGE)
             && !(gHitMarker & HITMARKER_GRUDGE)
             && GetBankSide(gBankAttacker) != GetBankSide(gBankTarget)
             && gBattleMons[gBankAttacker].hp != 0
             && gCurrentMove != MOVE_STRUGGLE)
            {
                u8 moveIndex = *(gBattleStruct->chosenMovesIds + gBankAttacker);

                gBattleMons[gBankAttacker].pp[moveIndex] = 0;
                BattleScriptPush(gBattlescriptCurrInstr);
                gBattlescriptCurrInstr = BattleScript_GrudgeTakesPp;
                gActiveBank = gBankAttacker;
                EmitSetAttributes(0, moveIndex + REQUEST_PPMOVE1_BATTLE, 0, 1, &gBattleMons[gActiveBank].pp[moveIndex]);
                MarkBufferBankForExecution(gActiveBank);

                gBattleTextBuff1[0] = PLACEHOLDER_BEGIN;
                gBattleTextBuff1[1] = 2;
                gBattleTextBuff1[2] = gBattleMons[gBankAttacker].moves[moveIndex];
                gBattleTextBuff1[3] = gBattleMons[gBankAttacker].moves[moveIndex] >> 8;
                gBattleTextBuff1[4] = EOS;
            }
        }
        else
        {
            gBattlescriptCurrInstr += 7;
        }
    }
}

void atk1A_faint_animation(void)
{
    if (gBattleExecBuffer == 0)
    {
        gActiveBank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
        EmitFaintAnimation(0);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr += 2;
    }
}

void atk1B_faint_effects_clear(void)
{
    if (gBattleExecBuffer == 0)
    {
        gActiveBank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));

        if (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || gBattleMons[gActiveBank].hp == 0)
        {
            gBattleMons[gActiveBank].status1 = 0;
            EmitSetAttributes(0, REQUEST_STATUS_BATTLE, 0, 0x4, &gBattleMons[gActiveBank].status1);
            MarkBufferBankForExecution(gActiveBank);
        }

        UndoEffectsAfterFainting(); // Effects like attractions, trapping, etc.
        gBattlescriptCurrInstr += 2;
    }
}

void atk1C_jumpifstatus(void)
{
    u8 bank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
    u32 flags = BS2ScriptRead32(gBattlescriptCurrInstr + 2);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 6);

    if (gBattleMons[bank].status1 & flags && gBattleMons[bank].hp)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 10;
}

void atk1D_jumpifstatus2(void)
{
    u8 bank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
    u32 flags = BS2ScriptRead32(gBattlescriptCurrInstr + 2);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 6);

    if (gBattleMons[bank].status2 & flags && gBattleMons[bank].hp)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 10;
}

void atk1E_jumpifability(void)
{
    u8 bank;
    u8 ability = BSScriptRead8(gBattlescriptCurrInstr + 2);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 3);

    if (BSScriptRead8(gBattlescriptCurrInstr + 1) == BS_GET_ATTACKER_SIDE)
    {
        bank = AbilityBattleEffects(ABILITYEFFECT_CHECK_BANK_SIDE, gBankAttacker, ability, 0, 0);
        if (bank)
        {
            gLastUsedAbility = ability;
            gBattlescriptCurrInstr = jumpPtr;
            RecordAbilityBattle(bank - 1, gLastUsedAbility);
            gBattleScripting.field_15 = bank - 1;
        }
        else
            gBattlescriptCurrInstr += 7;
    }
    else if (BSScriptRead8(gBattlescriptCurrInstr + 1) == BS_GET_NOT_ATTACKER_SIDE)
    {
        bank = AbilityBattleEffects(ABILITYEFFECT_CHECK_OTHER_SIDE, gBankAttacker, ability, 0, 0);
        if (bank)
        {
            gLastUsedAbility = ability;
            gBattlescriptCurrInstr = jumpPtr;
            RecordAbilityBattle(bank - 1, gLastUsedAbility);
            gBattleScripting.field_15 = bank - 1;
        }
        else
            gBattlescriptCurrInstr += 7;
    }
    else
    {
        bank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
        if (gBattleMons[bank].ability == ability)
        {
            gLastUsedAbility = ability;
            gBattlescriptCurrInstr = jumpPtr;
            RecordAbilityBattle(bank, gLastUsedAbility);
            gBattleScripting.field_15 = bank;
        }
        else
            gBattlescriptCurrInstr += 7;
    }
}

void atk1F_jumpifsideaffecting(void)
{
    u8 side;
    u16 flags;
    const u8* jumpPtr;

    if (BSScriptRead8(gBattlescriptCurrInstr + 1) == BS_GET_ATTACKER)
        side = GET_BANK_SIDE(gBankAttacker);
    else
        side = GET_BANK_SIDE(gBankTarget);

    flags = BS2ScriptRead16(gBattlescriptCurrInstr + 2);
    jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 4);

    if (gSideAffecting[side] & flags)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 8;
}

void atk20_jumpifstat(void)
{
    u8 ret = 0;
    u8 bank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
    u8 value = gBattleMons[bank].statStages[BSScriptRead8(gBattlescriptCurrInstr + 3)];

    switch (BSScriptRead8(gBattlescriptCurrInstr + 2))
    {
    case CMP_EQUAL:
        if (value == BSScriptRead8(gBattlescriptCurrInstr + 4))
            ret++;
        break;
    case CMP_NOT_EQUAL:
        if (value != BSScriptRead8(gBattlescriptCurrInstr + 4))
            ret++;
        break;
    case CMP_GREATER_THAN:
        if (value > BSScriptRead8(gBattlescriptCurrInstr + 4))
            ret++;
        break;
    case CMP_LESS_THAN:
        if (value < BSScriptRead8(gBattlescriptCurrInstr + 4))
            ret++;
        break;
    case CMP_COMMON_BITS:
        if (value & BSScriptRead8(gBattlescriptCurrInstr + 4))
            ret++;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(value & BSScriptRead8(gBattlescriptCurrInstr + 4)))
            ret++;
        break;
    }

    if (ret)
        gBattlescriptCurrInstr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 5);
    else
        gBattlescriptCurrInstr += 9;
}

void atk21_jumpifstatus3(void)
{
    u32 flags;
    const u8* jumpPtr;

    gActiveBank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
    flags = BS2ScriptRead32(gBattlescriptCurrInstr + 2);
    jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 7);

    if (BSScriptRead8(gBattlescriptCurrInstr + 6))
    {
        if ((gStatuses3[gActiveBank] & flags) != 0)
            gBattlescriptCurrInstr += 11;
        else
            gBattlescriptCurrInstr = jumpPtr;
    }
    else
    {
        if ((gStatuses3[gActiveBank] & flags) != 0)
            gBattlescriptCurrInstr = jumpPtr;
        else
            gBattlescriptCurrInstr += 11;
    }
}

void atk22_jumpiftype(void)
{
    u8 bank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
    u8 type = BSScriptRead8(gBattlescriptCurrInstr + 2);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 3);

    if (gBattleMons[bank].type1 == type || gBattleMons[bank].type2 == type)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 7;
}

void atk23_getexp(void)
{
    u16 item;
    s32 i; // also used as stringId
    u8 holdEffect;
    s32 sentIn;

    s32 viaExpShare = 0;
    u16* exp = &gBattleStruct->expValue;

    gBank1 = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
    sentIn = gSentPokesToOpponent[(gBank1 & 2) >> 1];

    switch (gBattleScripting.atk23_state)
    {
    case 0: // check if should receive exp at all
        if (GetBankSide(gBank1) != SIDE_OPPONENT || (gBattleTypeFlags &
             (BATTLE_TYPE_LINK
              | BATTLE_TYPE_x2000000
              | BATTLE_TYPE_x4000000
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
            gBattleStruct->field_DF |= gBitTable[gBattlePartyID[gBank1]];
        }
        break;
    case 1: // calculate experience points to redistribute
        {
            u16 calculatedExp;
            s32 viaSentIn;

            for (viaSentIn = 0, i = 0; i < 6; i++)
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

            calculatedExp = gBaseStats[gBattleMons[gBank1].species].expYield * gBattleMons[gBank1].level / 7;

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
            gBattleStruct->expGetterId = 0;
            gBattleStruct->sentInPokes = sentIn;
        }
        // fall through
    case 2: // set exp value to the poke in expgetter_id and print message
        if (gBattleExecBuffer == 0)
        {
            item = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_HELD_ITEM);

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
            else if (GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_LEVEL) == MAX_MON_LEVEL)
            {
                *(&gBattleStruct->sentInPokes) >>= 1;
                gBattleScripting.atk23_state = 5;
                gBattleMoveDamage = 0; // used for exp
            }
            else
            {
                // music change in wild battle after fainting a poke
                if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) && gBattleMons[0].hp && !gBattleStruct->wildVictorySong)
                {
                    BattleMusicStop();
                    PlayBGM(0x161);
                    gBattleStruct->wildVictorySong++;
                }

                if (GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_HP))
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

                    if (IsTradedMon(&gPlayerParty[gBattleStruct->expGetterId]))
                    {
                        // check if the pokemon doesn't belong to the player
                        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gBattleStruct->expGetterId >= 3)
                        {
                            i = 0x149;
                        }
                        else
                        {
                            gBattleMoveDamage = (gBattleMoveDamage * 150) / 100;
                            i = 0x14A;
                        }
                    }
                    else
                    {
						i = 0x149;
					}

                    // get exp getter bank
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                    {
                        if (!(gBattlePartyID[2] != gBattleStruct->expGetterId) && !(gAbsentBankFlags & gBitTable[2]))
                            gBattleStruct->expGetterBank = 2;
                        else
                        {
                            if (!(gAbsentBankFlags & gBitTable[0]))
                                gBattleStruct->expGetterBank = 0;
                            else
                                gBattleStruct->expGetterBank = 2;
                        }
                    }
                    else
                        gBattleStruct->expGetterBank = 0;

                    // buffer poke name
                    gBattleTextBuff1[0] = PLACEHOLDER_BEGIN;
                    gBattleTextBuff1[1] = 4;
                    gBattleTextBuff1[2] = gBattleStruct->expGetterBank;
                    gBattleTextBuff1[3] = gBattleStruct->expGetterId;
                    gBattleTextBuff1[4] = EOS;

					// buffer 'gained' or 'gained a boosted'
					gBattleTextBuff2[0] = PLACEHOLDER_BEGIN;
					gBattleTextBuff2[1] = 0;
					gBattleTextBuff2[2] = i;
					gBattleTextBuff2[3] = (i & 0xFF00) >> 8;
					gBattleTextBuff2[4] = EOS;

                    // buffer exp number
                    gBattleTextBuff3[0] = PLACEHOLDER_BEGIN;
                    gBattleTextBuff3[1] = 1;
                    gBattleTextBuff3[2] = 4; // word
                    gBattleTextBuff3[3] = 5; // max digits
                    gBattleTextBuff3[4] = gBattleMoveDamage;
                    gBattleTextBuff3[5] = (gBattleMoveDamage & 0x0000FF00) >> 8;
                    gBattleTextBuff3[6] = (gBattleMoveDamage & 0x00FF0000) >> 16;
                    gBattleTextBuff3[7] = (gBattleMoveDamage & 0xFF000000) >> 24;
                    gBattleTextBuff3[8] = EOS;

                    PrepareStringBattle(0xD, gBattleStruct->expGetterBank);
                    MonGainEVs(&gPlayerParty[gBattleStruct->expGetterId], gBattleMons[gBank1].species);
                }
                gBattleStruct->sentInPokes >>= 1;
                gBattleScripting.atk23_state++;
            }
        }
        break;
    case 3: // Set stats and give exp
        if (gBattleExecBuffer == 0)
        {
            gBattleBufferB[gBattleStruct->expGetterBank][0] = 0;
            if (GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_HP) && GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_LEVEL) != MAX_MON_LEVEL)
            {
                BATTLE_LVLUP_STATS->hp = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_MAX_HP);
                BATTLE_LVLUP_STATS->atk = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_ATK);
                BATTLE_LVLUP_STATS->def = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_DEF);
                BATTLE_LVLUP_STATS->spd = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPD);
                BATTLE_LVLUP_STATS->spAtk = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPATK);
                BATTLE_LVLUP_STATS->spDef = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPDEF);

                gActiveBank = gBattleStruct->expGetterBank;
                EmitExpUpdate(0, gBattleStruct->expGetterId, gBattleMoveDamage);
                MarkBufferBankForExecution(gActiveBank);
            }
            gBattleScripting.atk23_state++;
        }
        break;
    case 4: // lvl up if necessary
        if (gBattleExecBuffer == 0)
        {
            gActiveBank = gBattleStruct->expGetterBank;
            if (gBattleBufferB[gActiveBank][0] == 0x21 && gBattleBufferB[gActiveBank][1] == 0xB)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && gBattlePartyID[gActiveBank] == gBattleStruct->expGetterId)
                    sub_805E990(&gPlayerParty[gBattlePartyID[gActiveBank]], gActiveBank);

                // buff poke name
                gBattleTextBuff1[0] = PLACEHOLDER_BEGIN;
                gBattleTextBuff1[1] = 4;
                gBattleTextBuff1[2] = gActiveBank;
                gBattleTextBuff1[3] = gBattleStruct->expGetterId;
                gBattleTextBuff1[4] = EOS;

                // buff level
                gBattleTextBuff2[0] = PLACEHOLDER_BEGIN;
                gBattleTextBuff2[1] = 1;
                gBattleTextBuff2[2] = 1;
                gBattleTextBuff2[3] = 3;
                gBattleTextBuff2[4] = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_LEVEL);
                gBattleTextBuff2[5] = EOS;

                BattleScriptPushCursor();
                gLeveledUpInBattle |= gBitTable[gBattleStruct->expGetterId];
                gBattlescriptCurrInstr = BattleScript_LevelUp;
                gBattleMoveDamage = (gBattleBufferB[gActiveBank][2] | (gBattleBufferB[gActiveBank][3] << 8));
                AdjustFriendship(&gPlayerParty[gBattleStruct->expGetterId], 0);

                // update battle mon structure after level up
                if (gBattlePartyID[0] == gBattleStruct->expGetterId && gBattleMons[0].hp)
                {
                    gBattleMons[0].level = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_LEVEL);
                    gBattleMons[0].hp = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_HP);
                    gBattleMons[0].maxHP = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_MAX_HP);
                    gBattleMons[0].attack = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_ATK);
                    gBattleMons[0].defense = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_DEF);
                    // Why is this duplicated?
                    gBattleMons[0].speed = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPD);
                    gBattleMons[0].speed = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPD);

                    gBattleMons[0].spAttack = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPATK);
                    gBattleMons[0].spDefense = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPDEF);
                }
                // What is else if?
                if (gBattlePartyID[2] == gBattleStruct->expGetterId && gBattleMons[2].hp && (gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                {
                    gBattleMons[2].level = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_LEVEL);
                    gBattleMons[2].hp = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_HP);
                    gBattleMons[2].maxHP = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_MAX_HP);
                    gBattleMons[2].attack = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_ATK);
                    gBattleMons[2].defense = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_DEF);
                    // Duplicated again, but this time there's no Sp Defense
                    gBattleMons[2].speed = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPD);
                    gBattleMons[2].speed = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPD);

                    gBattleMons[2].spAttack = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPATK);
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
            gBattleScripting.atk23_state = 3;
        else
        {
            gBattleStruct->expGetterId++;
            if (gBattleStruct->expGetterId <= 5)
                gBattleScripting.atk23_state = 2; // loop again
            else
                gBattleScripting.atk23_state = 6; // we're done
        }
        break;
    case 6: // increment instruction
        if (gBattleExecBuffer == 0)
        {
            // not sure why gf clears the item and ability here
            gBattleMons[gBank1].item = 0;
            gBattleMons[gBank1].ability = 0;
            gBattlescriptCurrInstr += 2;
        }
        break;
    }
}

#ifdef NONMATCHING
void atk24(void)
{
    u16 HP_count = 0;
    s32 i;

    if (gBattleExecBuffer)
        return;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId == STEVEN_PARTNER_ID)
    {
        for (i = 0; i < 3; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
                HP_count += GetMonData(&gPlayerParty[i], MON_DATA_HP);
        }
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG)
                && (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || !(gBattleStruct->field_2A0 & gBitTable[i])))
            {
                HP_count += GetMonData(&gPlayerParty[i], MON_DATA_HP);
            }
        }
    }

    if (HP_count == 0)
        gBattleOutcome |= BATTLE_LOST;

    for (HP_count = 0, i = 0; i < 6; i++)
    {
        if (GetMonData(&gEnemyParty[i], MON_DATA_SPECIES) && !GetMonData(&gEnemyParty[i], MON_DATA_IS_EGG)
            && (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || !(gBattleStruct->field_2A1 & gBitTable[i])))
        {
            HP_count += GetMonData(&gEnemyParty[i], MON_DATA_HP);
        }
    }

    if (HP_count == 0)
        gBattleOutcome |= BATTLE_WON;

    if (gBattleOutcome == 0 && (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_x2000000)))
    {
        s32 foundPlayer;
        s32 foundOpponent;

        // Impossible to decompile loops.
        for (foundPlayer = 0, i = 0; i < gNoOfAllBanks; i += 2)
        {
            if (HITMARKER_UNK(i) & gHitMarker && !gSpecialStatuses[i].flag40)
                foundPlayer++;
        }

        for (foundOpponent = 0, i = 1; i < gNoOfAllBanks; i += 2)
        {
            if (HITMARKER_UNK(i) & gHitMarker && !gSpecialStatuses[i].flag40)
                foundOpponent++;
        }

        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            if (foundOpponent + foundPlayer > 1)
                gBattlescriptCurrInstr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
            else
                gBattlescriptCurrInstr += 5;
        }
        else
        {
            if (foundOpponent != 0 && foundPlayer != 0)
                gBattlescriptCurrInstr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
            else
                gBattlescriptCurrInstr += 5;
        }
    }
    else
    {
        gBattlescriptCurrInstr += 5;
    }
}
#else
__attribute__((naked))
void atk24(void)
{
    asm("\n\
        .syntax unified\n\
        push {r4-r7,lr}\n\
        mov r7, r8\n\
        push {r7}\n\
        movs r6, 0\n\
        ldr r0, =gBattleExecBuffer\n\
        ldr r0, [r0]\n\
        cmp r0, 0\n\
        beq _0804ACE2\n\
        b _0804AF22\n\
    _0804ACE2:\n\
        ldr r0, =gBattleTypeFlags\n\
        ldr r0, [r0]\n\
        movs r1, 0x80\n\
        lsls r1, 15\n\
        ands r0, r1\n\
        cmp r0, 0\n\
        beq _0804AD48\n\
        ldr r0, =gPartnerTrainerId\n\
        ldrh r1, [r0]\n\
        ldr r0, =0x00000c03\n\
        cmp r1, r0\n\
        bne _0804AD48\n\
        movs r5, 0\n\
    _0804ACFC:\n\
        movs r0, 0x64\n\
        adds r1, r5, 0\n\
        muls r1, r0\n\
        ldr r0, =gPlayerParty\n\
        adds r4, r1, r0\n\
        adds r0, r4, 0\n\
        movs r1, 0xB\n\
        bl GetMonData\n\
        cmp r0, 0\n\
        beq _0804AD2C\n\
        adds r0, r4, 0\n\
        movs r1, 0x2D\n\
        bl GetMonData\n\
        cmp r0, 0\n\
        bne _0804AD2C\n\
        adds r0, r4, 0\n\
        movs r1, 0x39\n\
        bl GetMonData\n\
        adds r0, r6, r0\n\
        lsls r0, 16\n\
        lsrs r6, r0, 16\n\
    _0804AD2C:\n\
        adds r5, 0x1\n\
        cmp r5, 0x2\n\
        ble _0804ACFC\n\
        b _0804ADA8\n\
        .pool\n\
    _0804AD48:\n\
        movs r5, 0\n\
    _0804AD4A:\n\
        movs r0, 0x64\n\
        adds r1, r5, 0\n\
        muls r1, r0\n\
        ldr r0, =gPlayerParty\n\
        adds r4, r1, r0\n\
        adds r0, r4, 0\n\
        movs r1, 0xB\n\
        bl GetMonData\n\
        cmp r0, 0\n\
        beq _0804ADA2\n\
        adds r0, r4, 0\n\
        movs r1, 0x2D\n\
        bl GetMonData\n\
        cmp r0, 0\n\
        bne _0804ADA2\n\
        ldr r0, =gBattleTypeFlags\n\
        ldr r0, [r0]\n\
        movs r1, 0x80\n\
        lsls r1, 11\n\
        ands r0, r1\n\
        cmp r0, 0\n\
        beq _0804AD94\n\
        ldr r0, =gBattleStruct\n\
        ldr r0, [r0]\n\
        movs r1, 0xA8\n\
        lsls r1, 2\n\
        adds r0, r1\n\
        ldrb r1, [r0]\n\
        ldr r2, =gBitTable\n\
        lsls r0, r5, 2\n\
        adds r0, r2\n\
        ldr r0, [r0]\n\
        ands r1, r0\n\
        cmp r1, 0\n\
        bne _0804ADA2\n\
    _0804AD94:\n\
        adds r0, r4, 0\n\
        movs r1, 0x39\n\
        bl GetMonData\n\
        adds r0, r6, r0\n\
        lsls r0, 16\n\
        lsrs r6, r0, 16\n\
    _0804ADA2:\n\
        adds r5, 0x1\n\
        cmp r5, 0x5\n\
        ble _0804AD4A\n\
    _0804ADA8:\n\
        cmp r6, 0\n\
        bne _0804ADB6\n\
        ldr r0, =gBattleOutcome\n\
        ldrb r1, [r0]\n\
        movs r2, 0x2\n\
        orrs r1, r2\n\
        strb r1, [r0]\n\
    _0804ADB6:\n\
        movs r6, 0\n\
        movs r5, 0\n\
    _0804ADBA:\n\
        movs r0, 0x64\n\
        adds r1, r5, 0\n\
        muls r1, r0\n\
        ldr r0, =gEnemyParty\n\
        adds r4, r1, r0\n\
        adds r0, r4, 0\n\
        movs r1, 0xB\n\
        bl GetMonData\n\
        cmp r0, 0\n\
        beq _0804AE10\n\
        adds r0, r4, 0\n\
        movs r1, 0x2D\n\
        bl GetMonData\n\
        cmp r0, 0\n\
        bne _0804AE10\n\
        ldr r0, =gBattleTypeFlags\n\
        ldr r0, [r0]\n\
        movs r1, 0x80\n\
        lsls r1, 11\n\
        ands r0, r1\n\
        cmp r0, 0\n\
        beq _0804AE02\n\
        ldr r0, =gBattleStruct\n\
        ldr r0, [r0]\n\
        ldr r1, =0x000002a1\n\
        adds r0, r1\n\
        ldrb r1, [r0]\n\
        ldr r2, =gBitTable\n\
        lsls r0, r5, 2\n\
        adds r0, r2\n\
        ldr r0, [r0]\n\
        ands r1, r0\n\
        cmp r1, 0\n\
        bne _0804AE10\n\
    _0804AE02:\n\
        adds r0, r4, 0\n\
        movs r1, 0x39\n\
        bl GetMonData\n\
        adds r0, r6, r0\n\
        lsls r0, 16\n\
        lsrs r6, r0, 16\n\
    _0804AE10:\n\
        adds r5, 0x1\n\
        cmp r5, 0x5\n\
        ble _0804ADBA\n\
        ldr r2, =gBattleOutcome\n\
        cmp r6, 0\n\
        bne _0804AE24\n\
        ldrb r0, [r2]\n\
        movs r1, 0x1\n\
        orrs r0, r1\n\
        strb r0, [r2]\n\
    _0804AE24:\n\
        ldrb r0, [r2]\n\
        cmp r0, 0\n\
        bne _0804AF1A\n\
        ldr r0, =gBattleTypeFlags\n\
        ldr r1, [r0]\n\
        ldr r2, =0x02000002\n\
        ands r1, r2\n\
        mov r8, r0\n\
        cmp r1, 0\n\
        beq _0804AF1A\n\
        movs r3, 0\n\
        movs r5, 0\n\
        ldr r0, =gNoOfAllBanks\n\
        ldrb r1, [r0]\n\
        mov r12, r0\n\
        ldr r7, =gBattlescriptCurrInstr\n\
        cmp r3, r1\n\
        bge _0804AE70\n\
        ldr r0, =gHitMarker\n\
        movs r6, 0x80\n\
        lsls r6, 21\n\
        ldr r4, [r0]\n\
        adds r2, r1, 0\n\
        ldr r1, =gSpecialStatuses\n\
    _0804AE54:\n\
        adds r0, r6, 0\n\
        lsls r0, r5\n\
        ands r0, r4\n\
        cmp r0, 0\n\
        beq _0804AE68\n\
        ldrb r0, [r1]\n\
        lsls r0, 25\n\
        cmp r0, 0\n\
        blt _0804AE68\n\
        adds r3, 0x1\n\
    _0804AE68:\n\
        adds r1, 0x28\n\
        adds r5, 0x2\n\
        cmp r5, r2\n\
        blt _0804AE54\n\
    _0804AE70:\n\
        movs r2, 0\n\
        movs r5, 0x1\n\
        mov r4, r12\n\
        ldrb r1, [r4]\n\
        cmp r5, r1\n\
        bge _0804AEAA\n\
        ldr r0, =gHitMarker\n\
        movs r4, 0x80\n\
        lsls r4, 21\n\
        mov r12, r4\n\
        ldr r6, [r0]\n\
        ldr r0, =gSpecialStatuses\n\
        adds r4, r1, 0\n\
        adds r1, r0, 0\n\
        adds r1, 0x14\n\
    _0804AE8E:\n\
        mov r0, r12\n\
        lsls r0, r5\n\
        ands r0, r6\n\
        cmp r0, 0\n\
        beq _0804AEA2\n\
        ldrb r0, [r1]\n\
        lsls r0, 25\n\
        cmp r0, 0\n\
        blt _0804AEA2\n\
        adds r2, 0x1\n\
    _0804AEA2:\n\
        adds r1, 0x28\n\
        adds r5, 0x2\n\
        cmp r5, r4\n\
        blt _0804AE8E\n\
    _0804AEAA:\n\
        mov r1, r8\n\
        ldr r0, [r1]\n\
        movs r1, 0x40\n\
        ands r0, r1\n\
        cmp r0, 0\n\
        beq _0804AEF0\n\
        adds r0, r2, r3\n\
        cmp r0, 0x1\n\
        bgt _0804AEF8\n\
        b _0804AF12\n\
        .pool\n\
    _0804AEF0:\n\
        cmp r2, 0\n\
        beq _0804AF12\n\
        cmp r3, 0\n\
        beq _0804AF12\n\
    _0804AEF8:\n\
        ldr r2, [r7]\n\
        ldrb r1, [r2, 0x1]\n\
        ldrb r0, [r2, 0x2]\n\
        lsls r0, 8\n\
        adds r1, r0\n\
        ldrb r0, [r2, 0x3]\n\
        lsls r0, 16\n\
        adds r1, r0\n\
        ldrb r0, [r2, 0x4]\n\
        lsls r0, 24\n\
        adds r1, r0\n\
        str r1, [r7]\n\
        b _0804AF22\n\
    _0804AF12:\n\
        ldr r0, [r7]\n\
        adds r0, 0x5\n\
        str r0, [r7]\n\
        b _0804AF22\n\
    _0804AF1A:\n\
        ldr r1, =gBattlescriptCurrInstr\n\
        ldr r0, [r1]\n\
        adds r0, 0x5\n\
        str r0, [r1]\n\
    _0804AF22:\n\
        pop {r3}\n\
        mov r8, r3\n\
        pop {r4-r7}\n\
        pop {r0}\n\
        bx r0\n\
        .pool\n\
        .syntax divided");
}

#endif // NONMATCHING

void MoveValuesCleanUp(void)
{
    gBattleMoveFlags = 0;
    gBattleScripting.dmgMultiplier = 1;
    gCritMultiplier = 1;
    gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
    gBattleCommunication[6] = 0;
    gHitMarker &= ~(HITMARKER_DESTINYBOND);
    gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);
}

void atk25_move_values_cleanup(void)
{
    MoveValuesCleanUp();
    gBattlescriptCurrInstr += 1;
}

void atk26_set_multihit(void)
{
    gMultiHitCounter = BSScriptRead8(gBattlescriptCurrInstr + 1);
    gBattlescriptCurrInstr += 2;
}

void atk27_decrement_multihit(void)
{
    if (--gMultiHitCounter == 0)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
}

void atk28_goto(void)
{
    gBattlescriptCurrInstr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
}

void atk29_jumpifbyte(void)
{
    u8 caseID = BSScriptRead8(gBattlescriptCurrInstr + 1);
    const u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 2);
    u8 value = BSScriptRead8(gBattlescriptCurrInstr + 6);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 7);

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

void atk2A_jumpifhalfword(void)
{
    u8 caseID = BSScriptRead8(gBattlescriptCurrInstr + 1);
    const u16* memHword = BS2ScriptReadPtr(gBattlescriptCurrInstr + 2);
    u16 value = BS2ScriptRead16(gBattlescriptCurrInstr + 6);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 8);

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

void atk2B_jumpifword(void)
{
    u8 caseID = BSScriptRead8(gBattlescriptCurrInstr + 1);
    const u32* memWord = BS2ScriptReadPtr(gBattlescriptCurrInstr + 2);
    u32 value = BSScriptRead32(gBattlescriptCurrInstr + 6);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 10);

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

void atk2C_jumpifarrayequal(void)
{
    const u8* mem1 = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    const u8* mem2 = BS2ScriptReadPtr(gBattlescriptCurrInstr + 5);
    u32 size = BSScriptRead8(gBattlescriptCurrInstr + 9);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 10);

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

void atk2D_jumpifarraynotequal(void)
{
    u8 equalBytes = 0;
    const u8* mem1 = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    const u8* mem2 = BS2ScriptReadPtr(gBattlescriptCurrInstr + 5);
    u32 size = BSScriptRead8(gBattlescriptCurrInstr + 9);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 10);

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

void atk2E_setbyte(void)
{
    u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    *memByte = BSScriptRead8(gBattlescriptCurrInstr + 5);

    gBattlescriptCurrInstr += 6;
}

void atk2F_addbyte(void)
{
    u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    *memByte += BSScriptRead8(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr += 6;
}

void atk30_subbyte(void)
{
    u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    *memByte -= BSScriptRead8(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr += 6;
}

void atk31_copyarray(void)
{
    u8* dest = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    const u8* src = BS2ScriptReadPtr(gBattlescriptCurrInstr + 5);
    s32 size = BSScriptRead8(gBattlescriptCurrInstr + 9);

    s32 i;
    for (i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }

    gBattlescriptCurrInstr += 10;
}

void atk32_copyarray_withindex(void)
{
    u8* dest = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    const u8* src = BS2ScriptReadPtr(gBattlescriptCurrInstr + 5);
    const u8* index = BS2ScriptReadPtr(gBattlescriptCurrInstr + 9);
    s32 size = BSScriptRead8(gBattlescriptCurrInstr + 13);

    s32 i;
    for (i = 0; i < size; i++)
    {
        dest[i] = src[i + *index];
    }

    gBattlescriptCurrInstr += 14;
}

void atk33_orbyte(void)
{
    u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    *memByte |= BSScriptRead8(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr += 6;
}

void atk34_orhalfword(void)
{
    u16* memHword = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    u16 val = BS2ScriptRead16(gBattlescriptCurrInstr + 5);

    *memHword |= val;
    gBattlescriptCurrInstr += 7;
}

void atk35_orword(void)
{
    u32* memWord = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    u32 val = BS2ScriptRead32(gBattlescriptCurrInstr + 5);

    *memWord |= val;
    gBattlescriptCurrInstr += 9;
}

void atk36_bicbyte(void)
{
    u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    *memByte &= ~(BSScriptRead8(gBattlescriptCurrInstr + 5));
    gBattlescriptCurrInstr += 6;
}

void atk37_bichalfword(void)
{
    u16* memHword = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    u16 val = BS2ScriptRead16(gBattlescriptCurrInstr + 5);

    *memHword &= ~val;
    gBattlescriptCurrInstr += 7;
}

void atk38_bicword(void)
{
    u32* memWord = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    u32 val = BS2ScriptRead32(gBattlescriptCurrInstr + 5);

    *memWord &= ~val;
    gBattlescriptCurrInstr += 9;
}

void atk39_pause(void)
{
    if (gBattleExecBuffer == 0)
    {
        u16 value = BS2ScriptRead16(gBattlescriptCurrInstr + 1);
        if (++gPauseCounterBattle >= value)
        {
            gPauseCounterBattle = 0;
            gBattlescriptCurrInstr += 3;
        }
    }
}

void atk3A_waitstate(void)
{
    if (gBattleExecBuffer == 0)
        gBattlescriptCurrInstr++;
}

void atk3B_healthbar_update(void)
{
    if (BSScriptRead8(gBattlescriptCurrInstr + 1) == BS_GET_TARGET)
        gActiveBank = gBankTarget;
    else
        gActiveBank = gBankAttacker;

    EmitHealthBarUpdate(0, gBattleMoveDamage);
    MarkBufferBankForExecution(gActiveBank);
    gBattlescriptCurrInstr += 2;
}

void atk3C_return(void)
{
    BattleScriptPop();
}

void atk3D_end(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        sub_81A5718(gBankAttacker);

    gBattleMoveFlags = 0;
    gActiveBank = 0;
    gFightStateTracker = 0xB;
}

void atk3E_end2(void)
{
    gActiveBank = 0;
    gFightStateTracker = 0xB;
}

void atk3F_end3(void) // pops the main function stack
{
    BattleScriptPop();
    if (BATTLE_CALLBACKS_STACK->size)
        BATTLE_CALLBACKS_STACK->size--;
    gBattleMainFunc = BATTLE_CALLBACKS_STACK->function[BATTLE_CALLBACKS_STACK->size];
}

void atk41_call(void)
{
    BattleScriptPush(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
}

void atk42_jumpiftype2(void)
{
    u8 bank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));

    if (BSScriptRead8(gBattlescriptCurrInstr + 2) == gBattleMons[bank].type1 || BSScriptRead8(gBattlescriptCurrInstr + 2) == gBattleMons[bank].type2)
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 3);
    else
        gBattlescriptCurrInstr += 7;
}

void atk43_jumpifabilitypresent(void)
{
    if (AbilityBattleEffects(ABILITYEFFECT_CHECK_ON_FIELD, 0, BSScriptRead8(gBattlescriptCurrInstr + 1), 0, 0))
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
    else
        gBattlescriptCurrInstr += 6;
}

void atk44(void)
{
    *(gBankAttacker + gBattleStruct->field_54) = 1;
}

void atk45_playanimation(void)
{
    const u16* argumentPtr;

    gActiveBank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
    argumentPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 3);

    if (gBattlescriptCurrInstr[2] == B_ANIM_STATS_CHANGE
        || gBattlescriptCurrInstr[2] == B_ANIM_SNATCH_MOVE
        || gBattlescriptCurrInstr[2] == B_ANIM_SUBSTITUTE_FADE)
    {
        EmitBattleAnimation(0, gBattlescriptCurrInstr[2], *argumentPtr);
        MarkBufferBankForExecution(gActiveBank);
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
        EmitBattleAnimation(0, gBattlescriptCurrInstr[2], *argumentPtr);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr += 7;
    }
    else if (gStatuses3[gActiveBank] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr += 7;
    }
    else
    {
        EmitBattleAnimation(0, gBattlescriptCurrInstr[2], *argumentPtr);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr += 7;
    }
}

void atk46_playanimation2(void) // animation Id is stored in the first pointer
{
    const u16* argumentPtr;
    const u8* animationIdPtr;

    gActiveBank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
    animationIdPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 2);
    argumentPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 6);

    if (*animationIdPtr == B_ANIM_STATS_CHANGE
        || *animationIdPtr == B_ANIM_SNATCH_MOVE
        || *animationIdPtr == B_ANIM_SUBSTITUTE_FADE)
    {
        EmitBattleAnimation(0, *animationIdPtr, *argumentPtr);
        MarkBufferBankForExecution(gActiveBank);
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
        EmitBattleAnimation(0, *animationIdPtr, *argumentPtr);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr += 10;
    }
    else if (gStatuses3[gActiveBank] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattlescriptCurrInstr += 10;
    }
    else
    {
        EmitBattleAnimation(0, *animationIdPtr, *argumentPtr);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr += 10;
    }
}

void atk47_setgraphicalstatchangevalues(void)
{
    u8 value = 0;
    switch (gBattleScripting.statChanger & 0xF0)
    {
    case 0x10: // +1
        value = 0xF;
        break;
    case 0x20: // +2
        value = 0x27;
        break;
    case 0x90: // -1
        value = 0x16;
        break;
    case 0xA0: // -2
        value = 0x2E;
        break;
    }
    gBattleScripting.animArg1 = (gBattleScripting.statChanger & 0xF) + value - 1;
    gBattleScripting.animArg2 = 0;
    gBattlescriptCurrInstr++;
}

void atk48_playstatchangeanimation(void)
{
    s32 currStat = 0;
    s16 statAnimId = 0;
    s32 checkingStatAnimId = 0;
    s32 changeableStats = 0;
    u32 statsToCheck = 0;

    gActiveBank = GetBattleBank(BSScriptRead8(gBattlescriptCurrInstr + 1));
    statsToCheck = BSScriptRead8(gBattlescriptCurrInstr + 2);

    if (gBattlescriptCurrInstr[3] & 1) // goes down
    {
        for (checkingStatAnimId = (gBattlescriptCurrInstr[3] & 0x2) ? 0x2D : 0x15;
            statsToCheck != 0;
            statsToCheck >>= 1, checkingStatAnimId += 1, currStat++)
        {
            if (!(statsToCheck & 1))
                continue;
            if (!(gBattlescriptCurrInstr[3] & 8))
            {
                if (gBattleMons[gActiveBank].statStages[currStat] > 0)
                {
                    statAnimId = checkingStatAnimId;
                    changeableStats++;
                }
            }
            else if (!gSideTimers[GET_BANK_SIDE(gActiveBank)].mistTimer
                    && gBattleMons[gActiveBank].ability != ABILITY_CLEAR_BODY
                    && gBattleMons[gActiveBank].ability != ABILITY_WHITE_SMOKE
                    && !(gBattleMons[gActiveBank].ability == ABILITY_KEEN_EYE && currStat == STAT_STAGE_ACC)
                    && !(gBattleMons[gActiveBank].ability == ABILITY_HYPER_CUTTER && currStat == STAT_STAGE_ATK))
            {
                if (gBattleMons[gActiveBank].statStages[currStat] > 0)
                {
                    statAnimId = checkingStatAnimId;
                    changeableStats++;
                }
            }
        }

        if (changeableStats > 1) // more than one stat, so the color is gray
        {
            if (gBattlescriptCurrInstr[3] & 2)
                statAnimId = 0x3A;
            else
                statAnimId = 0x39;
        }
    }
    else // goes up
    {
        for (checkingStatAnimId = (gBattlescriptCurrInstr[3] & 0x2) ? 0x26 : 0xE;
            statsToCheck != 0;
            statsToCheck >>= 1, checkingStatAnimId += 1, currStat++)
        {
            if (statsToCheck & 1 && gBattleMons[gActiveBank].statStages[currStat] < 0xC)
            {
                statAnimId = checkingStatAnimId;
                changeableStats++;
            }
        }

        if (changeableStats > 1) // more than one stat, so the color is gray
        {
            if (gBattlescriptCurrInstr[3] & 2)
                statAnimId = 0x38;
            else
                statAnimId = 0x37;
        }
    }

    if (gBattlescriptCurrInstr[3] & 4 && changeableStats < 2)
    {
        gBattlescriptCurrInstr += 4;
    }
    else if (changeableStats != 0 && gBattleScripting.field_1B == 0)
    {
        EmitBattleAnimation(0, B_ANIM_STATS_CHANGE, statAnimId);
        MarkBufferBankForExecution(gActiveBank);
        if (gBattlescriptCurrInstr[3] & 4 && changeableStats > 1)
            gBattleScripting.field_1B = 1;
        gBattlescriptCurrInstr += 4;
    }
    else
    {
        gBattlescriptCurrInstr += 4;
    }
}
