#include "global.h"
#include "battle.h"
#include "battle_move_effects.h"
#include "moves.h"
#include "abilities.h"
#include "item.h"
#include "items.h"
#include "hold_effects.h"

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

struct statFractions
{
    u8 dividend;
    u8 divisor;
};

const struct statFractions gAccuracyStageRatios[] =
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
