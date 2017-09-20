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
extern u8 gActionForBanks[4];
extern u8 gCurrentMoveTurn;
extern u8 gBattleBufferB[4][0x200];

extern const struct BattleMove gBattleMoves[];
extern const u16 gMissStringIds[];
extern const u8 gTrainerMoney[];
extern const u8 gTypeEffectiveness[];
extern const struct BaseStats gBaseStats[];

// functions


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
    0x00000007,
    0x00000008,
    0x00000010,
    0x00000020,
    0x00000040,
    0x00000080,
    0x00000007,
    0x00000008,
    0x00000000,
    0x00000070,
    0x00000000,
    0x00001000,
    0x0000E000,
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
    0x00400000,
    0x00000000,
    0x00000000,
    0x04000000,
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
    0x00000C00,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000
};

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
        b_movescr_stack_push_cursor();
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
            b_movescr_stack_push_cursor();
            gBattlescriptCurrInstr = BattleScript_SnatchedMove;
            return;
        }
    }

    if (gSpecialStatuses[gBankTarget].lightningRodRedirected)
    {
        gSpecialStatuses[gBankTarget].lightningRodRedirected = 0;
        gLastUsedAbility = ABILITY_LIGHTNING_ROD;
        b_movescr_stack_push_cursor();
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
        b_movescr_stack_push(gBattlescriptCurrInstr + 1);
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
            b_movescr_stack_push(gBattlescriptCurrInstr + 1);
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
                b_movescr_stack_push_cursor();
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
            b_movescr_stack_push_cursor();
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
                b_movescr_stack_push_cursor();
                gBattlescriptCurrInstr = BattleScript_OneHitKOMsg;
                return;
            }
            else if (gBattleMoveFlags & MOVESTATUS_ENDURED)
            {
                gBattleMoveFlags &= ~(MOVESTATUS_ENDURED | MOVESTATUS_HUNGON);
                b_movescr_stack_push_cursor();
                gBattlescriptCurrInstr = BattleScript_EnduredMsg;
                return;
            }
            else if (gBattleMoveFlags & MOVESTATUS_HUNGON)
            {
                gLastUsedItem = gBattleMons[gBankTarget].item;
                gStringBank = gBankTarget;
                gBattleMoveFlags &= ~(MOVESTATUS_ENDURED | MOVESTATUS_HUNGON);
                b_movescr_stack_push_cursor();
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
