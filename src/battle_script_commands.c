#include "global.h"
#include "battle.h"
#include "battle_move_effects.h"
#include "battle_message.h"
#include "battle_ai_script_commands.h"
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
#include "pokemon_item_effects.h"
#include "m4a.h"
#include "mail.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "task.h"
#include "naming_screen.h"

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
extern u8 gUnknown_0202407A[BATTLE_BANKS_COUNT];
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
extern u16 gUnknown_02024260[4];
extern u8 gUnknown_02024270[4];
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
extern u16 gLastUsedMove;
extern u16 gUnknownMovesUsedByBanks[BATTLE_BANKS_COUNT];
extern u16 gLastUsedMovesByBanks[BATTLE_BANKS_COUNT];
extern u16 gTrainerBattleOpponent_A;
extern u16 gTrainerBattleOpponent_B;
extern u8 gUnknown_020241E9;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern u16 gBattle_BG3_X;
extern struct MusicPlayerInfo gMPlay_BGM;

struct TrainerMoney
{
    u8 classId;
    u8 value;
};

extern const struct BattleMove gBattleMoves[];
extern const struct BaseStats gBaseStats[];
extern const u8 gTypeEffectiveness[];
extern const u16 gMissStringIds[];
extern const u16 gTrappingMoves[];
extern const struct TrainerMoney gTrainerMoneyTable[];
extern const u8* const gBattleScriptsForMoveEffects[];

// functions
extern void sub_81A5718(u8 bank); // battle frontier 2
extern void sub_81A56B4(void); // battle frontier 2
extern void sub_81BFA38(struct Pokemon* party, u8 monPartyId, u8 monCount, void (*callback)(void), u16 move); // pokemon summary screen
extern u8 sub_81C1B94(void); // pokemon summary screen
extern void IncrementGameStat(u8 statId); // rom_4
extern void sub_81D388C(struct Pokemon* mon, void* statStoreLocation); // pokenav.s
extern void sub_81D3640(u8 arg0, void* statStoreLocation1, void* statStoreLocation2, u8 arg3, u8 arg4, u8 arg5); // pokenav.s
extern void sub_81D3784(u8 arg0, void* statStoreLocation1, u8 arg2, u8 arg3, u8 arg4); // pokenav.s
extern u8* GetMonNickname(struct Pokemon* mon, u8* dst); // party_menu
extern u8 sub_81A5258(u8* arg0); // battle frontier 2
extern void sub_81A5BF8(void); // battle frontier 2
extern void sub_81A5D44(void); // battle frontier 2
extern void sub_81B8E80(u8 bank, u8, u8); // party menu
extern bool8 sub_81B1250(void); // ?
extern u8 GetScaledHPFraction(s16 hp, s16 maxhp, u8 scale); // battle interface
extern bool8 InBattlePike(void);
extern bool8 InBattlePyramid(void);
extern u16 GetBattlePyramidPickupItemId(void);
extern u8 sav1_map_get_light_level(void);
extern u8 sub_813B21C(void);
extern u16 get_unknown_box_id(void);
extern void c2_berry_program_update_menu(void);
extern void sub_8035AA4(void);

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
extern const u8 BattleScript_StickyHoldActivates[];
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
extern const u8 BattleScript_RageIsBuilding[];
extern const u8 BattleScript_DefrostedViaFireMove[];
extern const u8 gUnknown_082DB87D[];
extern const u8 gUnknown_082DAE90[];
extern const u8 gUnknown_082DAE59[];
extern const u8 gUnknown_082DAEC7[];
extern const u8 BattleScript_MoveEffectSleep[];
extern const u8 BattleScript_MoveEffectPoison[];
extern const u8 BattleScript_MoveEffectBurn[];
extern const u8 BattleScript_MoveEffectFreeze[];
extern const u8 BattleScript_MoveEffectParalysis[];
extern const u8 BattleScript_MoveEffectToxic[];
extern const u8 BattleScript_MoveEffectConfusion[];
extern const u8 BattleScript_MoveEffectUproar[];
extern const u8 BattleScript_MoveEffectPayDay[];
extern const u8 BattleScript_MoveEffectWrap[];
extern const u8 BattleScript_MoveEffectRecoil33[];
extern const u8 BattleScript_DampStopsExplosion[];
extern const u8 BattleScript_MistProtected[];
extern const u8 BattleScript_AbilityNoStatLoss[];
extern const u8 BattleScript_AbilityNoSpecificStatLoss[];
extern const u8 BattleScript_ButItFailed[];
extern const u8 gUnknown_082DADD8[];
extern const u8 BattleScript_PrintPayDayMoneyString[];
extern const u8 BattleScript_SturdyPreventsOHKO[];
extern const u8 BattleScript_ObliviousPreventsAttraction[];
extern const u8 BattleScript_PauseEffectivenessSoundResultMsgEndMove[];
extern const u8 BattleScript_CastformChange[];
extern const u8 BattleScript_TrainerBallBlock[];
extern const u8 BattleScript_WallyBallThrow[];
extern const u8 BattleScript_SuccessBallThrow[];
extern const u8 BattleScript_ShakeBallThrow[];
extern const u8 BattleScript_PresentDamageTarget[];
extern const u8 BattleScript_AlreadyAtFullHp[];
extern const u8 BattleScript_PresentHealTarget[];
extern const u8 BattleScript_WrapFree[];
extern const u8 BattleScript_LeechSeedFree[];
extern const u8 BattleScript_SpikesFree[];

// strings
extern const u8 gText_BattleYesNoChoice[];

// read via orr
#define BSScriptRead32(ptr) ((ptr)[0] | (ptr)[1] << 8 | (ptr)[2] << 16 | (ptr)[3] << 24)
#define BSScriptRead16(ptr) ((ptr)[0] | ((ptr)[1] << 8))
#define BSScriptReadPtr(ptr) ((void *)BSScriptRead32(ptr))

// read via add
#define BS2ScriptRead32(ptr) ((ptr)[0] + ((ptr)[1] << 8) + ((ptr)[2] << 16) + ((ptr)[3] << 24))
#define BS2ScriptRead16(ptr) ((ptr)[0] + ((ptr)[1] << 8))
#define BS2ScriptReadPtr(ptr) ((void *)BS2ScriptRead32(ptr))

#define TARGET_PROTECT_AFFECTED ((gProtectStructs[gBankTarget].protected && gBattleMoves[gCurrentMove].flags & FLAG_PROTECT_AFFECTED))

#define TARGET_TURN_DAMAGED (((gSpecialStatuses[gBankTarget].moveturnLostHP_physical || gSpecialStatuses[gBankTarget].moveturnLostHP_special)))

// this file's functions
static bool8 IsTwoTurnsMove(u16 move);
static void DestinyBondFlagUpdate(void);
static u8 AttacksThisTurn(u8 bank, u16 move); // Note: returns 1 if it's a charging turn, otherwise 2.
static void CheckWonderGuardAndLevitate(void);
static u8 ChangeStatBuffs(s8 statValue, u8 statId, u8, const u8* BS_ptr);
static bool32 IsMonGettingExpSentOut(void);
static void sub_804F17C(void);
static bool8 sub_804F1CC(void);
static void sub_804F100(void);
static void sub_804F144(void);
static bool8 sub_804F344(void);
static void PutMonIconOnLvlUpBox(void);
static void PutLevelAndGenderOnLvlUpBox(void);

static void SpriteCB_MonIconOnLvlUpBox(struct Sprite* sprite);

static void atk00_attackcanceler(void);
static void atk01_accuracycheck(void);
static void atk02_attackstring(void);
static void atk03_ppreduce(void);
static void atk04_critcalc(void);
static void atk05_damagecalc1(void);
static void atk06_typecalc(void);
static void atk07_dmg_adjustment(void);
static void atk08_dmg_adjustment2(void);
static void atk09_attackanimation(void);
static void atk0A_waitanimation(void);
static void atk0B_healthbarupdate(void);
static void atk0C_datahpupdate(void);
static void atk0D_critmessage(void);
static void atk0E_effectiveness_sound(void);
static void atk0F_resultmessage(void);
static void atk10_printstring(void);
static void atk11_printstring_playeronly(void);
static void atk12_waitmessage(void);
static void atk13_printfromtable(void);
static void atk14_printfromtable_playeronly(void);
static void atk15_seteffectwithchance(void);
static void atk16_seteffectprimary(void);
static void atk17_seteffectsecondary(void);
static void atk18_status_effect_clear(void);
static void atk19_faint_pokemon(void);
static void atk1A_faint_animation(void);
static void atk1B_faint_effects_clear(void);
static void atk1C_jumpifstatus(void);
static void atk1D_jumpifstatus2(void);
static void atk1E_jumpifability(void);
static void atk1F_jumpifsideaffecting(void);
static void atk20_jumpifstat(void);
static void atk21_jumpifstatus3(void);
static void atk22_jumpiftype(void);
static void atk23_getexp(void);
static void atk24(void);
static void atk25_move_values_cleanup(void);
static void atk26_set_multihit(void);
static void atk27_decrement_multihit(void);
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
static void atk32_copyarray_withindex(void);
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
static void atk40_jump_if_move_affected_by_protect(void);
static void atk41_call(void);
static void atk42_jumpiftype2(void);
static void atk43_jumpifabilitypresent(void);
static void atk44(void);
static void atk45_playanimation(void);
static void atk46_playanimation2(void);
static void atk47_setgraphicalstatchangevalues(void);
static void atk48_playstatchangeanimation(void);
static void atk49_moveend(void);
static void atk4A_typecalc2(void);
static void atk4B_return_atk_to_ball(void);
static void atk4C_copy_poke_data(void);
static void atk4D_switch_data_update(void);
static void atk4E_switchin_anim(void);
static void atk4F_jump_if_cannot_switch(void);
static void atk50_openpartyscreen(void);
static void atk51_switch_handle_order(void);
static void atk52_switch_in_effects(void);
static void atk53_trainer_slide(void);
static void atk54_effectiveness_sound(void);
static void atk55_play_sound(void);
static void atk56_fainting_cry(void);
static void atk57(void);
static void atk58_return_to_ball(void);
static void atk59_learnmove_inbattle(void);
static void atk5A_yesnoboxlearnmove(void);
static void atk5B_yesnoboxstoplearningmove(void);
static void atk5C_hitanimation(void);
static void atk5D_getmoneyreward(void);
static void atk5E_8025A70(void);
static void atk5F_8025B24(void);
static void atk60_increment_gamestat(void);
static void atk61_8025BA4(void);
static void atk62_08025C6C(void);
static void atk63_jumptorandomattack(void);
static void atk64_statusanimation(void);
static void atk65_status2animation(void);
static void atk66_chosenstatusanimation(void);
static void atk67_yesnobox(void);
static void atk68_80246A0(void);
static void atk69_dmg_adjustment3(void);
static void atk6A_removeitem(void);
static void atk6B_atknameinbuff1(void);
static void atk6C_draw_lvlupbox(void);
static void atk6D_reset_sentpokes_value(void);
static void atk6E_set_atk_to_player0(void);
static void atk6F_set_visible(void);
static void atk70_record_last_used_ability(void);
static void atk71_buffer_move_to_learn(void);
static void atk72_jump_if_can_run_frombattle(void);
static void atk73_hp_thresholds(void);
static void atk74_hp_thresholds2(void);
static void atk75_item_effect_on_opponent(void);
static void atk76_various(void);
static void atk77_set_protect_like(void);
static void atk78_faintifabilitynotdamp(void);
static void atk79_setatkhptozero(void);
static void atk7A_jumpwhiletargetvalid(void);
static void atk7B_healhalfHP_if_possible(void);
static void atk7C_trymirrormove(void);
static void atk7D_set_rain(void);
static void atk7E_setreflect(void);
static void atk7F_setseeded(void);
static void atk80_manipulatedamage(void);
static void atk81_setrest(void);
static void atk82_jumpifnotfirstturn(void);
static void atk83_nop(void);
static void atk84_jump_if_cant_sleep(void);
static void atk85_stockpile(void);
static void atk86_stockpiletobasedamage(void);
static void atk87_stockpiletohpheal(void);
static void atk88_negativedamage(void);
static void atk89_statbuffchange(void);
static void atk8A_normalisebuffs(void);
static void atk8B_setbide(void);
static void atk8C_confuseifrepeatingattackends(void);
static void atk8D_setmultihit_counter(void);
static void atk8E_init_multihit_string(void);
static void atk8F_forcerandomswitch(void);
static void atk90_conversion_type_change(void);
static void atk91_givepaydaymoney(void);
static void atk92_setlightscreen(void);
static void atk93_ko_move(void);
static void atk94_damagetohalftargethp(void);
static void atk95_setsandstorm(void);
static void atk96_weatherdamage(void);
static void atk97_try_infatuation(void);
static void atk98_status_icon_update(void);
static void atk99_setmist(void);
static void atk9A_set_focusenergy(void);
static void atk9B_transformdataexecution(void);
static void atk9C_set_substitute(void);
static void atk9D_mimicattackcopy(void);
static void atk9E_metronome(void);
static void atk9F_dmgtolevel(void);
static void atkA0_psywavedamageeffect(void);
static void atkA1_counterdamagecalculator(void);
static void atkA2_mirrorcoatdamagecalculator(void);
static void atkA3_disablelastusedattack(void);
static void atkA4_setencore(void);
static void atkA5_painsplitdmgcalc(void);
static void atkA6_settypetorandomresistance(void);
static void atkA7_setalwayshitflag(void);
static void atkA8_copymovepermanently(void);
static void atkA9_sleeptalk_choose_move(void);
static void atkAA_set_destinybond(void);
static void atkAB_DestinyBondFlagUpdate(void);
static void atkAC_remaininghptopower(void);
static void atkAD_spite_ppreduce(void);
static void atkAE_heal_party_status(void);
static void atkAF_cursetarget(void);
static void atkB0_set_spikes(void);
static void atkB1_set_foresight(void);
static void atkB2_setperishsong(void);
static void atkB3_rolloutdamagecalculation(void);
static void atkB4_jumpifconfusedandstatmaxed(void);
static void atkB5_furycuttercalc(void);
static void atkB6_happinesstodamagecalculation(void);
static void atkB7_presentdamagecalculation(void);
static void atkB8_set_safeguard(void);
static void atkB9_magnitudedamagecalculation(void);
static void atkBA_jumpifnopursuitswitchdmg(void);
static void atkBB_setsunny(void);
static void atkBC_maxattackhalvehp(void);
static void atkBD_copyfoestats(void);
static void atkBE_rapidspinfree(void);
static void atkBF_set_defense_curl(void);
static void atkC0_recoverbasedonsunlight(void);
static void atkC1_hidden_power(void);
static void atkC2_selectnexttarget(void);
static void atkC3_setfutureattack(void);
static void atkC4_beat_up(void);
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
static void atkD1_set_helpinghand(void);
static void atkD2_swap_items(void);
static void atkD3_copy_ability(void);
static void atkD4_wish_effect(void);
static void atkD5_setroots(void);
static void atkD6_doubledamagedealtifdamaged(void);
static void atkD7_setyawn(void);
static void atkD8_setdamagetohealthdifference(void);
static void atkD9_scaledamagebyhealthratio(void);
static void atkDA_abilityswap(void);
static void atkDB_imprisoneffect(void);
static void atkDC_setgrudge(void);
static void atkDD_weightdamagecalculation(void);
static void atkDE_asistattackselect(void);
static void atkDF_setmagiccoat(void);
static void atkE0_setstealstatchange(void);
static void atkE1_intimidate_string_loader(void);
static void atkE2_switchout_abilities(void);
static void atkE3_jumpifhasnohp(void);
static void atkE4_getsecretpowereffect(void);
static void atkE5_pickup(void);
static void atkE6_castform_change_animation(void);
static void atkE7_castform_data_change(void);
static void atkE8_settypebasedhalvers(void);
static void atkE9_setweatherballtype(void);
static void atkEA_recycleitem(void);
static void atkEB_settypetoterrain(void);
static void atkEC_pursuit_sth(void);
static void atkED_802B4B4(void);
static void atkEE_removelightscreenreflect(void);
static void atkEF_pokeball_catch_calculation(void);
static void atkF0_give_caught_mon(void);
static void atkF1_set_caught_mon_dex_flags(void);
static void atkF2_display_dex_info(void);
static void atkF3_nickname_caught_poke(void);
static void atkF4_subattackerhpbydmg(void);
static void atkF5_removeattackerstatus1(void);
static void atkF6_802BF48(void);
static void atkF7_802BF54(void);
static void atkF8_trainer_slide_back(void);

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
    atk15_seteffectwithchance,
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
    atk49_moveend,
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
    atk5A_yesnoboxlearnmove,
    atk5B_yesnoboxstoplearningmove,
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
    atk67_yesnobox,
    atk68_80246A0,
    atk69_dmg_adjustment3,
    atk6A_removeitem,
    atk6B_atknameinbuff1,
    atk6C_draw_lvlupbox,
    atk6D_reset_sentpokes_value,
    atk6E_set_atk_to_player0,
    atk6F_set_visible,
    atk70_record_last_used_ability,
    atk71_buffer_move_to_learn,
    atk72_jump_if_can_run_frombattle,
    atk73_hp_thresholds,
    atk74_hp_thresholds2,
    atk75_item_effect_on_opponent,
    atk76_various,
    atk77_set_protect_like,
    atk78_faintifabilitynotdamp,
    atk79_setatkhptozero,
    atk7A_jumpwhiletargetvalid,
    atk7B_healhalfHP_if_possible,
    atk7C_trymirrormove,
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
    atk8E_init_multihit_string,
    atk8F_forcerandomswitch,
    atk90_conversion_type_change,
    atk91_givepaydaymoney,
    atk92_setlightscreen,
    atk93_ko_move,
    atk94_damagetohalftargethp,
    atk95_setsandstorm,
    atk96_weatherdamage,
    atk97_try_infatuation,
    atk98_status_icon_update,
    atk99_setmist,
    atk9A_set_focusenergy,
    atk9B_transformdataexecution,
    atk9C_set_substitute,
    atk9D_mimicattackcopy,
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
    atkBE_rapidspinfree,
    atkBF_set_defense_curl,
    atkC0_recoverbasedonsunlight,
    atkC1_hidden_power,
    atkC2_selectnexttarget,
    atkC3_setfutureattack,
    atkC4_beat_up,
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
    atkE3_jumpifhasnohp,
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
    atkF0_give_caught_mon,
    atkF1_set_caught_mon_dex_flags,
    atkF2_display_dex_info,
    atkF3_nickname_caught_poke,
    atkF4_subattackerhpbydmg,
    atkF5_removeattackerstatus1,
    atkF6_802BF48,
    atkF7_802BF54,
    atkF8_trainer_slide_back
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

// The chance is 1/N for each stage.
static const u16 sCriticalHitChance[] = {16, 8, 4, 3, 2};

static const u32 sStatusFlagsForMoveEffects[] =
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

static const u8* const sMoveEffectBS_Ptrs[] =
{
    BattleScript_MoveEffectSleep,	    //  0
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_SLEEP
    BattleScript_MoveEffectPoison,		//	MOVE_EFFECT_POISON
    BattleScript_MoveEffectBurn,		//	MOVE_EFFECT_BURN
    BattleScript_MoveEffectFreeze,		//	MOVE_EFFECT_FREEZE
    BattleScript_MoveEffectParalysis,   //	MOVE_EFFECT_PARALYSIS
    BattleScript_MoveEffectToxic,		//	MOVE_EFFECT_TOXIC
    BattleScript_MoveEffectConfusion,	//	MOVE_EFFECT_CONFUSION
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_FLINCH
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_TRI_ATTACK
    BattleScript_MoveEffectUproar,		//	MOVE_EFFECT_UPROAR
    BattleScript_MoveEffectPayDay,		//	MOVE_EFFECT_PAYDAY
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_CHARGING
    BattleScript_MoveEffectWrap,		//	MOVE_EFFECT_WRAP
    BattleScript_MoveEffectRecoil33,	//	MOVE_EFFECT_RECOIL_25
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_ATK_PLUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_DEF_PLUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_SPD_PLUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_SP_ATK_PLUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_SP_DEF_PLUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_ACC_PLUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_EVS_PLUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_ATK_MINUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_DEF_MINUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_SPD_MINUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_SP_ATK_MINUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_SP_DEF_MINUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_ACC_MINUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_EVS_MINUS_1
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_RECHARGE
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_RAGE
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_STEAL_ITEM
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_PREVENT_ESCAPE
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_NIGHTMARE
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_ALL_STATS_UP
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_RAPIDSPIN
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_REMOVE_PARALYSIS
    BattleScript_MoveEffectSleep,		//	MOVE_EFFECT_ATK_DEF_DOWN
    BattleScript_MoveEffectRecoil33,	//	MOVE_EFFECT_RECOIL_33_PARALYSIS
};

static const struct WindowTemplate sUnusedWinTemplate = {0, 1, 3, 7, 0xF, 0x1F, 0x3F};

static const u16 sUnknown_0831C2C8[] = INCBIN_U16("graphics/battle_interface/unk_battlebox.gbapal");
static const u8 sUnknown_0831C2E8[] = INCBIN_U8("graphics/battle_interface/unk_battlebox.4bpp.lz");

// unused
static const u8 sRubyLevelUpStatBoxStats[] =
{
    MON_DATA_MAX_HP, MON_DATA_SPATK, MON_DATA_ATK,
    MON_DATA_SPDEF, MON_DATA_DEF, MON_DATA_SPD
};

#define MON_ICON_LVLUP_BOX_TAG      0xD75A

static const struct OamData sOamData_MonIconOnLvlUpBox =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = 0,
    .x = 0,
    .matrixNum = 0,
    .size = 2,
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

static const u16 sMovesForbiddenToCopy[] =
{
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
     METRONOME_FORBIDDEN_END
};

static const u8 sFlailHpScaleToPowerTable[] =
{
    1, 200,
    4, 150,
    9, 100,
    16, 80,
    32, 40,
    48, 20
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

// format: min. weight (hectograms), base power
static const u16 sWeightToDamageTable[] =
{
    100, 20,
    250, 40,
    500, 60,
    1000, 80,
    2000, 100,
    0xFFFF, 0xFFFF
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
	ITEM_TM44,
	ITEM_ELIXIR,
	ITEM_TM01,
	ITEM_LEFTOVERS,
	ITEM_TM26,
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

// could be a 2d array or a struct
const ALIGNED(4) u8 gUnknown_0831C494[] =
{
    0x3d, 0x44, 0x3d, 0x44, 0x14, 0x2d, 0x54, 0x5c,
    0x46, 0x55, 0x20, 0x5c, 0x26, 0x45, 0x46, 0x55,
    0x14, 0x5a, 0x46, 0x5c, 0x1e, 0x32, 0x20, 0x5a,
    0x38, 0x4e, 0x38, 0x4e, 0x19, 0x28, 0x4b, 0x5a,
    0x45, 0x4b, 0x1c, 0x53, 0x23, 0x2d, 0x1d, 0x23,
    0x3e, 0x48, 0x1e, 0x32, 0x3a, 0x5f, 0x58, 0x5e,
    0x22, 0x2d, 0x1d, 0x28, 0x23, 0x28, 0x23, 0x5f,
    0x38, 0x4e, 0x38, 0x4e, 0x23, 0x50, 0x22, 0x5e,
    0x2c, 0x5e, 0x22, 0x28, 0x38, 0x4e, 0x38, 0x4e,
    0x1e, 0x58, 0x1e, 0x58, 0x1e, 0x2b, 0x1b, 0x21,
    0x28, 0x5a, 0x19, 0x57, 0x12, 0x58, 0x5a, 0x5f,
    0x58, 0x5e, 0x16, 0x2a, 0x2a, 0x5c, 0x2a, 0x2f,
    0x38, 0x4e, 0x38, 0x4e
};

static const u8 sUnknown_0831C4F8[] =
{
	0x03, 0x00, 0x01, 0x00, 0x00, 0x01, 0x03, 0x00,
	0x01, 0x02, 0x02, 0x00, 0x03, 0x01, 0x03, 0x01,
	0x02, 0x03, 0x03, 0x02, 0x01, 0x00, 0x02, 0x02,
	0x03, 0x00, 0x00, 0x00
};

static void atk00_attackcanceler(void)
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

static void JumpIfMoveFailed(u8 adder, u16 move)
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

static void atk40_jump_if_move_affected_by_protect(void)
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

static void atk01_accuracycheck(void)
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

        calc = sAccuracyStageRatios[buff].dividend * moveAcc;
        calc /= sAccuracyStageRatios[buff].divisor;

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

static void atk02_attackstring(void)
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

static void atk03_ppreduce(void)
{
    s32 ppToDeduct = 1;

    if (gBattleExecBuffer)
        return;

    if (!gSpecialStatuses[gBankAttacker].flag20)
    {
        switch (gBattleMoves[gCurrentMove].target)
        {
        case MOVE_TARGET_FOES_AND_ALLY:
            ppToDeduct += AbilityBattleEffects(ABILITYEFFECT_COUNT_ON_FIELD, gBankAttacker, ABILITY_PRESSURE, 0, 0);
            break;
        case MOVE_TARGET_BOTH:
        case MOVE_TARGET_OPPONENTS_FIELD:
            ppToDeduct += AbilityBattleEffects(ABILITYEFFECT_COUNT_OTHER_SIDE, gBankAttacker, ABILITY_PRESSURE, 0, 0);
            break;
        default:
            if (gBankAttacker != gBankTarget && gBattleMons[gBankTarget].ability == ABILITY_PRESSURE)
                ppToDeduct++;
            break;
        }
    }

    if (!(gHitMarker & (HITMARKER_NO_PPDEDUCT | HITMARKER_NO_ATTACKSTRING)) && gBattleMons[gBankAttacker].pp[gCurrMovePos])
    {
        gProtectStructs[gBankAttacker].notFirstStrike = 1;

        if (gBattleMons[gBankAttacker].pp[gCurrMovePos] > ppToDeduct)
            gBattleMons[gBankAttacker].pp[gCurrMovePos] -= ppToDeduct;
        else
            gBattleMons[gBankAttacker].pp[gCurrMovePos] = 0;

        if (!(gBattleMons[gBankAttacker].status2 & STATUS2_TRANSFORMED)
            && !((gDisableStructs[gBankAttacker].unk18_b) & gBitTable[gCurrMovePos]))
        {
            gActiveBank = gBankAttacker;
            EmitSetMonData(0, REQUEST_PPMOVE1_BATTLE + gCurrMovePos, 0, 1, &gBattleMons[gBankAttacker].pp[gCurrMovePos]);
            MarkBufferBankForExecution(gBankAttacker);
        }
    }

    gHitMarker &= ~(HITMARKER_NO_PPDEDUCT);
    gBattlescriptCurrInstr++;
}

static void atk04_critcalc(void)
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
     && !(Random() % sCriticalHitChance[critChance]))
        gCritMultiplier = 2;
    else
        gCritMultiplier = 1;

    gBattlescriptCurrInstr++;
}

static void atk05_damagecalc1(void)
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

static void ModulateDmgByType(u8 multiplier)
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

static void atk06_typecalc(void)
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

static void ModulateDmgByType2(u8 multiplier, u16 move, u8* flags) // same as ModulateDmgByType except different arguments
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

static void Unused_ApplyRandomDmgMultiplier(void)
{
    ApplyRandomDmgMultiplier();
}

static void atk07_dmg_adjustment(void)
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

static void atk08_dmg_adjustment2(void) // The same as 0x7 except it doesn't check for false swipe move effect.
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

static void atk09_attackanimation(void)
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

static void atk0A_waitanimation(void)
{
    if (gBattleExecBuffer == 0)
        gBattlescriptCurrInstr++;
}

static void atk0B_healthbarupdate(void)
{
    if (gBattleExecBuffer)
        return;

    if (!(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

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

static void atk0C_datahpupdate(void)
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
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
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
                    if (gBattlescriptCurrInstr[1] == BS_GET_TARGET)
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
                    if (gBattlescriptCurrInstr[1] == BS_GET_TARGET)
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
                    if (gBattlescriptCurrInstr[1] == BS_GET_TARGET)
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
            EmitSetMonData(0, REQUEST_HP_BATTLE, 0, 2, &gBattleMons[gActiveBank].hp);
            MarkBufferBankForExecution(gActiveBank);
        }
    }
    else
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
        if (gSpecialStatuses[gActiveBank].moveturnLostHP == 0)
            gSpecialStatuses[gActiveBank].moveturnLostHP = 0xFFFF;
    }
    gBattlescriptCurrInstr += 2;
}

static void atk0D_critmessage(void)
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

static void atk0E_effectiveness_sound(void)
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

static void atk0F_resultmessage(void)
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

static void atk10_printstring(void)
{
    if (gBattleExecBuffer == 0)
    {
        u16 var = BS2ScriptRead16(gBattlescriptCurrInstr + 1);
        PrepareStringBattle(var, gBankAttacker);
        gBattlescriptCurrInstr += 3;
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

static void atk11_printstring_playeronly(void)
{
    gActiveBank = gBankAttacker;

    EmitPrintStringPlayerOnly(0, BS2ScriptRead16(gBattlescriptCurrInstr + 1));
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 3;
    gBattleCommunication[MSG_DISPLAY] = 1;
}

static void atk12_waitmessage(void)
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

static void atk13_printfromtable(void)
{
    if (gBattleExecBuffer == 0)
    {
        const u16 *ptr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        ptr += gBattleCommunication[MULTISTRING_CHOOSER];

        PrepareStringBattle(*ptr, gBankAttacker);

        gBattlescriptCurrInstr += 5;
        gBattleCommunication[MSG_DISPLAY] = 1;
    }
}

static void atk14_printfromtable_playeronly(void)
{
    if (gBattleExecBuffer == 0)
    {
        const u16 *ptr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        ptr += gBattleCommunication[MULTISTRING_CHOOSER];

        gActiveBank = gBankAttacker;
        EmitPrintStringPlayerOnly(0, *ptr);
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
        switch (sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]])
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

            if (sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]] == STATUS_SLEEP)
                gBattleMons[gEffectBank].status1 |= ((Random() & 3) + 2);
            else
                gBattleMons[gEffectBank].status1 |= sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]];

            gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];

            gActiveBank = gEffectBank;
            EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gEffectBank].status1);
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
        if (gBattleMons[gEffectBank].status2 & sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]])
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
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
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
                        gBattleMons[gEffectBank].status2 |= sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]];
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
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
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
                gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
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
                    gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];

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
                gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
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
                    else if (gBattleMons[gBankAttacker].item != 0
                        || gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY
                        || IS_ITEM_MAIL(gBattleMons[gBankTarget].item)
                        || gBattleMons[gBankTarget].item == 0)
                    {
                        gBattlescriptCurrInstr++;
                    }
                    else
                    {
                        u16* changedItem = &gBattleStruct->changedItems[gBankAttacker];
                        gLastUsedItem = *changedItem = gBattleMons[gBankTarget].item;
                        gBattleMons[gBankTarget].item = 0;

                        gActiveBank = gBankAttacker;
                        EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gLastUsedItem);
                        MarkBufferBankForExecution(gBankAttacker);

                        gActiveBank = gBankTarget;
                        EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gBankTarget].item);
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
                    EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
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
                gBattlescriptCurrInstr = sMoveEffectBS_Ptrs[gBattleCommunication[MOVE_EFFECT_BYTE]];
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
                        gBattlescriptCurrInstr = BattleScript_StickyHoldActivates;
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

static void atk15_seteffectwithchance(void)
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

static void atk16_seteffectprimary(void)
{
    SetMoveEffect(TRUE, 0);
}

static void atk17_seteffectsecondary(void)
{
    SetMoveEffect(FALSE, 0);
}

static void atk18_status_effect_clear(void)
{
    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    if (gBattleCommunication[MOVE_EFFECT_BYTE] <= MOVE_EFFECT_TOXIC)
        gBattleMons[gActiveBank].status1 &= (~sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]]);
    else
        gBattleMons[gActiveBank].status2 &= (~sStatusFlagsForMoveEffects[gBattleCommunication[MOVE_EFFECT_BYTE]]);

    gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
    gBattlescriptCurrInstr += 2;
    gBattleScripting.field_16 = 0;
}

static void atk19_faint_pokemon(void)
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
                EmitSetMonData(0, moveIndex + REQUEST_PPMOVE1_BATTLE, 0, 1, &gBattleMons[gActiveBank].pp[moveIndex]);
                MarkBufferBankForExecution(gActiveBank);

                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[gBankAttacker].moves[moveIndex])
            }
        }
        else
        {
            gBattlescriptCurrInstr += 7;
        }
    }
}

static void atk1A_faint_animation(void)
{
    if (gBattleExecBuffer == 0)
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
        EmitFaintAnimation(0);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr += 2;
    }
}

static void atk1B_faint_effects_clear(void)
{
    if (gBattleExecBuffer == 0)
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

        if (!(gBattleTypeFlags & BATTLE_TYPE_ARENA) || gBattleMons[gActiveBank].hp == 0)
        {
            gBattleMons[gActiveBank].status1 = 0;
            EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 0x4, &gBattleMons[gActiveBank].status1);
            MarkBufferBankForExecution(gActiveBank);
        }

        UndoEffectsAfterFainting(); // Effects like attractions, trapping, etc.
        gBattlescriptCurrInstr += 2;
    }
}

static void atk1C_jumpifstatus(void)
{
    u8 bank = GetBattleBank(gBattlescriptCurrInstr[1]);
    u32 flags = BS2ScriptRead32(gBattlescriptCurrInstr + 2);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 6);

    if (gBattleMons[bank].status1 & flags && gBattleMons[bank].hp)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 10;
}

static void atk1D_jumpifstatus2(void)
{
    u8 bank = GetBattleBank(gBattlescriptCurrInstr[1]);
    u32 flags = BS2ScriptRead32(gBattlescriptCurrInstr + 2);
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 6);

    if (gBattleMons[bank].status2 & flags && gBattleMons[bank].hp)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 10;
}

static void atk1E_jumpifability(void)
{
    u8 bank;
    u8 ability = gBattlescriptCurrInstr[2];
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 3);

    if (gBattlescriptCurrInstr[1] == BS_GET_ATTACKER_SIDE)
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
    else if (gBattlescriptCurrInstr[1] == BS_GET_NOT_ATTACKER_SIDE)
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
        bank = GetBattleBank(gBattlescriptCurrInstr[1]);
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

static void atk1F_jumpifsideaffecting(void)
{
    u8 side;
    u16 flags;
    const u8* jumpPtr;

    if (gBattlescriptCurrInstr[1] == BS_GET_ATTACKER)
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

static void atk20_jumpifstat(void)
{
    u8 ret = 0;
    u8 bank = GetBattleBank(gBattlescriptCurrInstr[1]);
    u8 value = gBattleMons[bank].statStages[gBattlescriptCurrInstr[3]];

    switch (gBattlescriptCurrInstr[2])
    {
    case CMP_EQUAL:
        if (value == gBattlescriptCurrInstr[4])
            ret++;
        break;
    case CMP_NOT_EQUAL:
        if (value != gBattlescriptCurrInstr[4])
            ret++;
        break;
    case CMP_GREATER_THAN:
        if (value > gBattlescriptCurrInstr[4])
            ret++;
        break;
    case CMP_LESS_THAN:
        if (value < gBattlescriptCurrInstr[4])
            ret++;
        break;
    case CMP_COMMON_BITS:
        if (value & gBattlescriptCurrInstr[4])
            ret++;
        break;
    case CMP_NO_COMMON_BITS:
        if (!(value & gBattlescriptCurrInstr[4]))
            ret++;
        break;
    }

    if (ret)
        gBattlescriptCurrInstr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 5);
    else
        gBattlescriptCurrInstr += 9;
}

static void atk21_jumpifstatus3(void)
{
    u32 flags;
    const u8* jumpPtr;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
    flags = BS2ScriptRead32(gBattlescriptCurrInstr + 2);
    jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 7);

    if (gBattlescriptCurrInstr[6])
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

static void atk22_jumpiftype(void)
{
    u8 bank = GetBattleBank(gBattlescriptCurrInstr[1]);
    u8 type = gBattlescriptCurrInstr[2];
    const u8* jumpPtr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 3);

    if (gBattleMons[bank].type1 == type || gBattleMons[bank].type2 == type)
        gBattlescriptCurrInstr = jumpPtr;
    else
        gBattlescriptCurrInstr += 7;
}

static void atk23_getexp(void)
{
    u16 item;
    s32 i; // also used as stringId
    u8 holdEffect;
    s32 sentIn;

    s32 viaExpShare = 0;
    u16* exp = &gBattleStruct->expValue;

    gBank1 = GetBattleBank(gBattlescriptCurrInstr[1]);
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

                    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gBattleStruct->expGetterBank, gBattleStruct->expGetterId)

					// buffer 'gained' or 'gained a boosted'
					PREPARE_STRING_BUFFER(gBattleTextBuff2, i)

                    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff3, 5, gBattleMoveDamage)

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

                PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gActiveBank, gBattleStruct->expGetterId)

                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 3, GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_LEVEL))

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
static void atk24(void)
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
static void atk24(void)
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

static void MoveValuesCleanUp(void)
{
    gBattleMoveFlags = 0;
    gBattleScripting.dmgMultiplier = 1;
    gCritMultiplier = 1;
    gBattleCommunication[MOVE_EFFECT_BYTE] = 0;
    gBattleCommunication[6] = 0;
    gHitMarker &= ~(HITMARKER_DESTINYBOND);
    gHitMarker &= ~(HITMARKER_SYNCHRONISE_EFFECT);
}

static void atk25_move_values_cleanup(void)
{
    MoveValuesCleanUp();
    gBattlescriptCurrInstr += 1;
}

static void atk26_set_multihit(void)
{
    gMultiHitCounter = gBattlescriptCurrInstr[1];
    gBattlescriptCurrInstr += 2;
}

static void atk27_decrement_multihit(void)
{
    if (--gMultiHitCounter == 0)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
}

static void atk28_goto(void)
{
    gBattlescriptCurrInstr = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
}

static void atk29_jumpifbyte(void)
{
    u8 caseID = gBattlescriptCurrInstr[1];
    const u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 2);
    u8 value = gBattlescriptCurrInstr[6];
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

static void atk2A_jumpifhalfword(void)
{
    u8 caseID = gBattlescriptCurrInstr[1];
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

static void atk2B_jumpifword(void)
{
    u8 caseID = gBattlescriptCurrInstr[1];
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

static void atk2C_jumpifarrayequal(void)
{
    const u8* mem1 = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    const u8* mem2 = BS2ScriptReadPtr(gBattlescriptCurrInstr + 5);
    u32 size = gBattlescriptCurrInstr[9];
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

static void atk2D_jumpifarraynotequal(void)
{
    u8 equalBytes = 0;
    const u8* mem1 = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    const u8* mem2 = BS2ScriptReadPtr(gBattlescriptCurrInstr + 5);
    u32 size = gBattlescriptCurrInstr[9];
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

static void atk2E_setbyte(void)
{
    u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    *memByte = gBattlescriptCurrInstr[5];

    gBattlescriptCurrInstr += 6;
}

static void atk2F_addbyte(void)
{
    u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    *memByte += gBattlescriptCurrInstr[5];
    gBattlescriptCurrInstr += 6;
}

static void atk30_subbyte(void)
{
    u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    *memByte -= gBattlescriptCurrInstr[5];
    gBattlescriptCurrInstr += 6;
}

static void atk31_copyarray(void)
{
    u8* dest = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    const u8* src = BS2ScriptReadPtr(gBattlescriptCurrInstr + 5);
    s32 size = gBattlescriptCurrInstr[9];

    s32 i;
    for (i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }

    gBattlescriptCurrInstr += 10;
}

static void atk32_copyarray_withindex(void)
{
    u8* dest = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    const u8* src = BS2ScriptReadPtr(gBattlescriptCurrInstr + 5);
    const u8* index = BS2ScriptReadPtr(gBattlescriptCurrInstr + 9);
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
    u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    *memByte |= gBattlescriptCurrInstr[5];
    gBattlescriptCurrInstr += 6;
}

static void atk34_orhalfword(void)
{
    u16* memHword = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    u16 val = BS2ScriptRead16(gBattlescriptCurrInstr + 5);

    *memHword |= val;
    gBattlescriptCurrInstr += 7;
}

static void atk35_orword(void)
{
    u32* memWord = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    u32 val = BS2ScriptRead32(gBattlescriptCurrInstr + 5);

    *memWord |= val;
    gBattlescriptCurrInstr += 9;
}

static void atk36_bicbyte(void)
{
    u8* memByte = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    *memByte &= ~(gBattlescriptCurrInstr[5]);
    gBattlescriptCurrInstr += 6;
}

static void atk37_bichalfword(void)
{
    u16* memHword = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    u16 val = BS2ScriptRead16(gBattlescriptCurrInstr + 5);

    *memHword &= ~val;
    gBattlescriptCurrInstr += 7;
}

static void atk38_bicword(void)
{
    u32* memWord = BS2ScriptReadPtr(gBattlescriptCurrInstr + 1);
    u32 val = BS2ScriptRead32(gBattlescriptCurrInstr + 5);

    *memWord &= ~val;
    gBattlescriptCurrInstr += 9;
}

static void atk39_pause(void)
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

static void atk3A_waitstate(void)
{
    if (gBattleExecBuffer == 0)
        gBattlescriptCurrInstr++;
}

static void atk3B_healthbar_update(void)
{
    if (gBattlescriptCurrInstr[1] == BS_GET_TARGET)
        gActiveBank = gBankTarget;
    else
        gActiveBank = gBankAttacker;

    EmitHealthBarUpdate(0, gBattleMoveDamage);
    MarkBufferBankForExecution(gActiveBank);
    gBattlescriptCurrInstr += 2;
}

static void atk3C_return(void)
{
    BattleScriptPop();
}

static void atk3D_end(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        sub_81A5718(gBankAttacker);

    gBattleMoveFlags = 0;
    gActiveBank = 0;
    gFightStateTracker = 0xB;
}

static void atk3E_end2(void)
{
    gActiveBank = 0;
    gFightStateTracker = 0xB;
}

static void atk3F_end3(void) // pops the main function stack
{
    BattleScriptPop();
    if (BATTLE_CALLBACKS_STACK->size)
        BATTLE_CALLBACKS_STACK->size--;
    gBattleMainFunc = BATTLE_CALLBACKS_STACK->function[BATTLE_CALLBACKS_STACK->size];
}

static void atk41_call(void)
{
    BattleScriptPush(gBattlescriptCurrInstr + 5);
    gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
}

static void atk42_jumpiftype2(void)
{
    u8 bank = GetBattleBank(gBattlescriptCurrInstr[1]);

    if (gBattlescriptCurrInstr[2] == gBattleMons[bank].type1 || gBattlescriptCurrInstr[2] == gBattleMons[bank].type2)
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 3);
    else
        gBattlescriptCurrInstr += 7;
}

static void atk43_jumpifabilitypresent(void)
{
    if (AbilityBattleEffects(ABILITYEFFECT_CHECK_ON_FIELD, 0, gBattlescriptCurrInstr[1], 0, 0))
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
    else
        gBattlescriptCurrInstr += 6;
}

static void atk44(void)
{
    *(gBankAttacker + gBattleStruct->field_54) = 1;
}

static void atk45_playanimation(void)
{
    const u16* argumentPtr;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
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

static void atk46_playanimation2(void) // animation Id is stored in the first pointer
{
    const u16* argumentPtr;
    const u8* animationIdPtr;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
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

static void atk47_setgraphicalstatchangevalues(void)
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

#ifdef NONMATCHING
static void atk48_playstatchangeanimation(void)
{
    u32 currStat = 0;
    s16 statAnimId = 0;
    s16 checkingStatAnimId = 0;
    s32 changeableStats = 0;
    u32 statsToCheck = 0;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
    statsToCheck = gBattlescriptCurrInstr[2];

    if (gBattlescriptCurrInstr[3] & ATK48_STAT_NEGATIVE) // goes down
    {
        checkingStatAnimId = (gBattlescriptCurrInstr[3] & ATK48_STAT_BY_TWO) ? 0x2D : 0x15;
        while (statsToCheck != 0)
        {
            if (statsToCheck & 1)
            {
                if (!(gBattlescriptCurrInstr[3] & ATK48_LOWER_FAIL_CHECK))
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
            statsToCheck >>= 1, checkingStatAnimId++, currStat++;
        }

        if (changeableStats > 1) // more than one stat, so the color is gray
        {
            if (gBattlescriptCurrInstr[3] & ATK48_STAT_BY_TWO)
                statAnimId = 0x3A;
            else
                statAnimId = 0x39;
        }
    }
    else // goes up
    {
        checkingStatAnimId = (gBattlescriptCurrInstr[3] & ATK48_STAT_BY_TWO) ? 0x26 : 0xE;
        while (statsToCheck != 0)
        {
            if (statsToCheck & 1 && gBattleMons[gActiveBank].statStages[currStat] < 0xC)
            {
                statAnimId = checkingStatAnimId;
                changeableStats++;
            }
            statsToCheck >>= 1, checkingStatAnimId += 1, currStat++;
        }

        if (changeableStats > 1) // more than one stat, so the color is gray
        {
            if (gBattlescriptCurrInstr[3] & ATK48_STAT_BY_TWO)
                statAnimId = 0x38;
            else
                statAnimId = 0x37;
        }
    }

    if (gBattlescriptCurrInstr[3] & ATK48_BIT_x4 && changeableStats < 2)
    {
        gBattlescriptCurrInstr += 4;
    }
    else if (changeableStats != 0 && gBattleScripting.field_1B == 0)
    {
        EmitBattleAnimation(0, B_ANIM_STATS_CHANGE, statAnimId);
        MarkBufferBankForExecution(gActiveBank);
        if (gBattlescriptCurrInstr[3] & ATK48_BIT_x4 && changeableStats > 1)
            gBattleScripting.field_1B = 1;
        gBattlescriptCurrInstr += 4;
    }
    else
    {
        gBattlescriptCurrInstr += 4;
    }
}
#else
__attribute__((naked))
static void atk48_playstatchangeanimation(void)
{
    asm("\n\
    .syntax unified\n\
    push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	sub sp, 0x4\n\
	movs r7, 0\n\
	movs r0, 0\n\
	mov r8, r0\n\
	movs r3, 0\n\
	ldr r5, =gBattlescriptCurrInstr\n\
	ldr r0, [r5]\n\
	ldrb r0, [r0, 0x1]\n\
	str r3, [sp]\n\
	bl GetBattleBank\n\
	ldr r2, =gActiveBank\n\
	strb r0, [r2]\n\
	ldr r0, [r5]\n\
	ldrb r4, [r0, 0x2]\n\
	ldrb r1, [r0, 0x3]\n\
	movs r0, 0x1\n\
	ands r0, r1\n\
	ldr r3, [sp]\n\
	cmp r0, 0\n\
	beq _0804BAEC\n\
	movs r0, 0x2\n\
	ands r0, r1\n\
	movs r1, 0x15\n\
	cmp r0, 0\n\
	beq _0804BA18\n\
	movs r1, 0x2D\n\
_0804BA18:\n\
	cmp r4, 0\n\
	beq _0804BAC0\n\
	movs r0, 0x1\n\
	mov r10, r0\n\
	ldr r0, =gBattleMons + 0x18\n\
	mov r9, r0\n\
	lsls r5, r1, 16\n\
_0804BA26:\n\
	adds r0, r4, 0\n\
	mov r1, r10\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _0804BAB2\n\
	ldr r0, =gBattlescriptCurrInstr\n\
	ldr r0, [r0]\n\
	ldrb r1, [r0, 0x3]\n\
	movs r0, 0x8\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _0804BA58\n\
	ldr r0, =gActiveBank\n\
	ldrb r1, [r0]\n\
	movs r0, 0x58\n\
	muls r0, r1\n\
	adds r0, r7, r0\n\
	b _0804BAA0\n\
	.pool\n\
_0804BA58:\n\
	ldr r6, =gActiveBank\n\
	ldrb r0, [r6]\n\
	str r3, [sp]\n\
	bl GetBankIdentity\n\
	mov r1, r10\n\
	ands r1, r0\n\
	lsls r0, r1, 1\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	ldr r1, =gSideTimers\n\
	adds r0, r1\n\
	ldrb r0, [r0, 0x4]\n\
	ldr r3, [sp]\n\
	cmp r0, 0\n\
	bne _0804BAB2\n\
	ldr r0, =gBattleMons\n\
	ldrb r2, [r6]\n\
	movs r1, 0x58\n\
	muls r2, r1\n\
	adds r0, r2, r0\n\
	adds r0, 0x20\n\
	ldrb r0, [r0]\n\
	cmp r0, 0x1D\n\
	beq _0804BAB2\n\
	cmp r0, 0x49\n\
	beq _0804BAB2\n\
	cmp r0, 0x33\n\
	bne _0804BA96\n\
	cmp r7, 0x6\n\
	beq _0804BAB2\n\
_0804BA96:\n\
	cmp r0, 0x34\n\
	bne _0804BA9E\n\
	cmp r7, 0x1\n\
	beq _0804BAB2\n\
_0804BA9E:\n\
	adds r0, r7, r2\n\
_0804BAA0:\n\
	add r0, r9\n\
	ldrb r0, [r0]\n\
	lsls r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0\n\
	ble _0804BAB2\n\
	lsrs r0, r5, 16\n\
	mov r8, r0\n\
	adds r3, 0x1\n\
_0804BAB2:\n\
	lsrs r4, 1\n\
	movs r1, 0x80\n\
	lsls r1, 9\n\
	adds r5, r1\n\
	adds r7, 0x1\n\
	cmp r4, 0\n\
	bne _0804BA26\n\
_0804BAC0:\n\
	ldr r0, =gBattlescriptCurrInstr\n\
	mov r9, r0\n\
	cmp r3, 0x1\n\
	ble _0804BB4E\n\
	ldr r0, [r0]\n\
	ldrb r1, [r0, 0x3]\n\
	movs r0, 0x2\n\
	ands r0, r1\n\
	movs r1, 0x39\n\
	mov r8, r1\n\
	cmp r0, 0\n\
	beq _0804BB4E\n\
	movs r0, 0x3A\n\
	b _0804BB4C\n\
	.pool\n\
_0804BAEC:\n\
	movs r0, 0x2\n\
	ands r0, r1\n\
	movs r1, 0xE\n\
	cmp r0, 0\n\
	beq _0804BAF8\n\
	movs r1, 0x26\n\
_0804BAF8:\n\
	mov r9, r5\n\
	cmp r4, 0\n\
	beq _0804BB34\n\
	ldr r6, =gBattleMons + 0x18\n\
	adds r5, r2, 0\n\
	lsls r2, r1, 16\n\
_0804BB04:\n\
	movs r0, 0x1\n\
	ands r0, r4\n\
	cmp r0, 0\n\
	beq _0804BB26\n\
	ldrb r1, [r5]\n\
	movs r0, 0x58\n\
	muls r0, r1\n\
	adds r0, r7, r0\n\
	adds r0, r6\n\
	ldrb r0, [r0]\n\
	lsls r0, 24\n\
	asrs r0, 24\n\
	cmp r0, 0xB\n\
	bgt _0804BB26\n\
	lsrs r1, r2, 16\n\
	mov r8, r1\n\
	adds r3, 0x1\n\
_0804BB26:\n\
	lsrs r4, 1\n\
	movs r0, 0x80\n\
	lsls r0, 9\n\
	adds r2, r0\n\
	adds r7, 0x1\n\
	cmp r4, 0\n\
	bne _0804BB04\n\
_0804BB34:\n\
	cmp r3, 0x1\n\
	ble _0804BB4E\n\
	mov r1, r9\n\
	ldr r0, [r1]\n\
	ldrb r1, [r0, 0x3]\n\
	movs r0, 0x2\n\
	ands r0, r1\n\
	movs r1, 0x37\n\
	mov r8, r1\n\
	cmp r0, 0\n\
	beq _0804BB4E\n\
	movs r0, 0x38\n\
_0804BB4C:\n\
	mov r8, r0\n\
_0804BB4E:\n\
	mov r1, r9\n\
	ldr r2, [r1]\n\
	ldrb r1, [r2, 0x3]\n\
	movs r0, 0x4\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _0804BB6C\n\
	cmp r3, 0x1\n\
	bgt _0804BB6C\n\
	adds r0, r2, 0x4\n\
	mov r1, r9\n\
	b _0804BBBA\n\
	.pool\n\
_0804BB6C:\n\
	cmp r3, 0\n\
	beq _0804BBB4\n\
	ldr r4, =gBattleScripting\n\
	ldrb r0, [r4, 0x1B]\n\
	cmp r0, 0\n\
	bne _0804BBB4\n\
	movs r0, 0\n\
	movs r1, 0x1\n\
	mov r2, r8\n\
	str r3, [sp]\n\
	bl EmitBattleAnimation\n\
	ldr r0, =gActiveBank\n\
	ldrb r0, [r0]\n\
	bl MarkBufferBankForExecution\n\
	ldr r0, =gBattlescriptCurrInstr\n\
	ldr r0, [r0]\n\
	ldrb r1, [r0, 0x3]\n\
	movs r0, 0x4\n\
	ands r0, r1\n\
	ldr r3, [sp]\n\
	cmp r0, 0\n\
	beq _0804BBA4\n\
	cmp r3, 0x1\n\
	ble _0804BBA4\n\
	movs r0, 0x1\n\
	strb r0, [r4, 0x1B]\n\
_0804BBA4:\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	b _0804BBB6\n\
	.pool\n\
_0804BBB4:\n\
	mov r1, r9\n\
_0804BBB6:\n\
	ldr r0, [r1]\n\
	adds r0, 0x4\n\
_0804BBBA:\n\
	str r0, [r1]\n\
	add sp, 0x4\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
    .syntax divided");
}
#endif // NONMATCHING

#define ATK49_LAST_CASE 17

static void atk49_moveend(void)
{
    s32 i;
    bool32 effect;
    u8 moveType;
    u8 holdEffectAtk;
    u16 *choicedMoveAtk;
    u8 arg1, arg2;
    u16 lastMove;

    effect = FALSE;

    if (gLastUsedMove == 0xFFFF)
        lastMove = 0;
    else
        lastMove = gLastUsedMove;

    arg1 = gBattlescriptCurrInstr[1];
    arg2 = gBattlescriptCurrInstr[2];

    if (gBattleMons[gBankAttacker].item == ITEM_ENIGMA_BERRY)
        holdEffectAtk = gEnigmaBerries[gBankAttacker].holdEffect;
    else
        holdEffectAtk = ItemId_GetHoldEffect(gBattleMons[gBankAttacker].item);

    choicedMoveAtk = &gBattleStruct->choicedMove[gBankAttacker];

    GET_MOVE_TYPE(gCurrentMove, moveType);

    do
    {
        switch (gBattleScripting.atk49_state)
        {
        case 0: // rage check
            if (gBattleMons[gBankTarget].status2 & STATUS2_RAGE
                && gBattleMons[gBankTarget].hp != 0 && gBankAttacker != gBankTarget
                && GetBankSide(gBankAttacker) != GetBankSide(gBankTarget)
                && !(gBattleMoveFlags & MOVESTATUS_NOEFFECT) && TARGET_TURN_DAMAGED
                && gBattleMoves[gCurrentMove].power && gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK] <= 0xB)
            {
                gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK]++;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_RageIsBuilding;
                effect = TRUE;
            }
            gBattleScripting.atk49_state++;
            break;
        case 1: // defrosting check
            if (gBattleMons[gBankTarget].status1 & STATUS_FREEZE
                && gBattleMons[gBankTarget].hp != 0 && gBankAttacker != gBankTarget
                && gSpecialStatuses[gBankTarget].moveturnLostHP_special
                && !(gBattleMoveFlags & MOVESTATUS_NOEFFECT) && moveType == TYPE_FIRE)
            {
                gBattleMons[gBankTarget].status1 &= ~(STATUS_FREEZE);
                gActiveBank = gBankTarget;
                EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gBankTarget].status1);
                MarkBufferBankForExecution(gActiveBank);
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_DefrostedViaFireMove;
                effect = TRUE;
            }
            gBattleScripting.atk49_state++;
            break;
        case 2: // target synchronize
            if (AbilityBattleEffects(ABILITYEFFECT_SYNCHRONIZE, gBankTarget, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.atk49_state++;
            break;
        case 3: // contact abilities
            if (AbilityBattleEffects(ABILITYEFFECT_CONTACT, gBankTarget, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.atk49_state++;
            break;
        case 4: // status immunities
            if (AbilityBattleEffects(ABILITYEFFECT_IMMUNITY, 0, 0, 0, 0))
                effect = TRUE; // it loops through all banks, so we increment after its done with all banks
            else
                gBattleScripting.atk49_state++;
            break;
        case 5: // attacker synchronize
            if (AbilityBattleEffects(ABILITYEFFECT_ATK_SYNCHRONIZE, gBankAttacker, 0, 0, 0))
                effect = TRUE;
            gBattleScripting.atk49_state++;
            break;
        case 6: // update choice band move
            if (!(gHitMarker & HITMARKER_OBEYS) || holdEffectAtk != HOLD_EFFECT_CHOICE_BAND
                || gLastUsedMove == MOVE_STRUGGLE || (*choicedMoveAtk != 0 && *choicedMoveAtk != 0xFFFF))
                    goto LOOP;
            if (gLastUsedMove == MOVE_BATON_PASS && !(gBattleMoveFlags & MOVESTATUS_FAILED))
            {
                gBattleScripting.atk49_state++;
                break;
            }
            *choicedMoveAtk = gLastUsedMove;
            LOOP:
            {
                for (i = 0; i < 4; i++)
                {
                    if (gBattleMons[gBankAttacker].moves[i] == *choicedMoveAtk)
                        break;
                }
                if (i == 4)
                    *choicedMoveAtk = 0;

                gBattleScripting.atk49_state++;
            }
            break;
        case 7: // changed held items
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                u16* changedItem = &gBattleStruct->changedItems[i];
                if (*changedItem != 0)
                {
                    gBattleMons[i].item = *changedItem;
                    *changedItem = 0;
                }
            }
            gBattleScripting.atk49_state++;
            break;
        case 11: // item effects for all banks
            if (ItemBattleEffects(3, 0, FALSE))
                effect = TRUE;
            else
                gBattleScripting.atk49_state++;
            break;
        case 12: // king's rock and shell bell
            if (ItemBattleEffects(4, 0, FALSE))
                effect = TRUE;
            gBattleScripting.atk49_state++;
            break;
        case 8: // make attacker sprite invisible
            if (gStatuses3[gBankAttacker] & (STATUS3_SEMI_INVULNERABLE)
                && gHitMarker & HITMARKER_NO_ANIMATIONS)
            {
                gActiveBank = gBankAttacker;
                EmitSpriteInvisibility(0, TRUE);
                MarkBufferBankForExecution(gActiveBank);
                gBattleScripting.atk49_state++;
                return;
            }
            gBattleScripting.atk49_state++;
            break;
        case 9: // make attacker sprite visible
            if (gBattleMoveFlags & MOVESTATUS_NOEFFECT
                || !(gStatuses3[gBankAttacker] & (STATUS3_SEMI_INVULNERABLE))
                || HasMoveFailed(gBankAttacker))
            {
                gActiveBank = gBankAttacker;
                EmitSpriteInvisibility(0, FALSE);
                MarkBufferBankForExecution(gActiveBank);
                gStatuses3[gBankAttacker] &= ~(STATUS3_SEMI_INVULNERABLE);
                gSpecialStatuses[gBankAttacker].restoredBankSprite = 1;
                gBattleScripting.atk49_state++;
                return;
            }
            gBattleScripting.atk49_state++;
            break;
        case 10: // make target sprite visible
            if (!gSpecialStatuses[gBankTarget].restoredBankSprite && gBankTarget < gNoOfAllBanks
                && !(gStatuses3[gBankTarget] & STATUS3_SEMI_INVULNERABLE))
            {
                gActiveBank = gBankTarget;
                EmitSpriteInvisibility(0, FALSE);
                MarkBufferBankForExecution(gActiveBank);
                gStatuses3[gBankTarget] &= ~(STATUS3_SEMI_INVULNERABLE);
                gBattleScripting.atk49_state++;
                return;
            }
            gBattleScripting.atk49_state++;
            break;
        case 13: // update substitute
            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gDisableStructs[i].substituteHP == 0)
                    gBattleMons[i].status2 &= ~(STATUS2_SUBSTITUTE);
            }
            gBattleScripting.atk49_state++;
            break;
        case 14: // This case looks interesting, although I am not certain what it does. Probably fine tunes edge cases.
            if (gHitMarker & HITMARKER_PURSUIT_TRAP)
            {
                gActiveBank = gBankAttacker;
                gBankAttacker = gBankTarget;
                gBankTarget = gActiveBank;
                gHitMarker &= ~(HITMARKER_PURSUIT_TRAP);
            }
            if (gHitMarker & HITMARKER_ATTACKSTRING_PRINTED)
            {
                gUnknownMovesUsedByBanks[gBankAttacker] = gLastUsedMove;
            }
            if (!(gAbsentBankFlags & gBitTable[gBankAttacker])
                && !(gBattleStruct->field_91 & gBitTable[gBankAttacker])
                && gBattleMoves[lastMove].effect != EFFECT_BATON_PASS)
            {
                if (gHitMarker & HITMARKER_OBEYS)
                {
                    gLastUsedMovesByBanks[gBankAttacker] = gLastUsedMove;
                    gUnknown_02024260[gBankAttacker] = gCurrentMove;
                }
                else
                {
                    gLastUsedMovesByBanks[gBankAttacker] = 0xFFFF;
                    gUnknown_02024260[gBankAttacker] = 0xFFFF;
                }

                if (!(gHitMarker & HITMARKER_FAINTED(gBankTarget)))
                    gUnknown_02024270[gBankTarget] = gBankAttacker;

                if (gHitMarker & HITMARKER_OBEYS && !(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
                {
                    if (gLastUsedMove == 0xFFFF)
                    {
                        gUnknown_02024250[gBankTarget] = gLastUsedMove;
                    }
                    else
                    {
                        gUnknown_02024250[gBankTarget] = gCurrentMove;
                        GET_MOVE_TYPE(gCurrentMove, gUnknown_02024258[gBankTarget]);
                    }
                }
                else
                {
                    gUnknown_02024250[gBankTarget] = 0xFFFF;
                }
            }
            gBattleScripting.atk49_state++;
            break;
        case 15: // mirror move
            if (!(gAbsentBankFlags & gBitTable[gBankAttacker]) && !(gBattleStruct->field_91 & gBitTable[gBankAttacker])
                && gBattleMoves[lastMove].flags & FLAG_MIRROR_MOVE_AFFECTED && gHitMarker & HITMARKER_OBEYS
                && gBankAttacker != gBankTarget && !(gHitMarker & HITMARKER_FAINTED(gBankTarget))
                && !(gBattleMoveFlags & MOVESTATUS_NOEFFECT))
            {
                u8 target, attacker;

                *(gBattleStruct->mirrorMoves + gBankTarget * 2 + 0) = gLastUsedMove;
                *(gBattleStruct->mirrorMoves + gBankTarget * 2 + 1) = gLastUsedMove >> 8;

                target = gBankTarget;
                attacker = gBankAttacker;
                *(attacker * 2 + target * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0) = gLastUsedMove;

                target = gBankTarget;
                attacker = gBankAttacker;
                *(attacker * 2 + target * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) = gLastUsedMove >> 8;
            }
            gBattleScripting.atk49_state++;
            break;
        case 16: //
            if (!(gHitMarker & HITMARKER_UNABLE_TO_USE_MOVE) && gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                && !gProtectStructs[gBankAttacker].chargingTurn && gBattleMoves[gCurrentMove].target == MOVE_TARGET_BOTH
                && !(gHitMarker & HITMARKER_NO_ATTACKSTRING))
            {
                u8 bank = GetBankByIdentity(GetBankIdentity(gBankTarget) ^ BIT_MON);
                if (gBattleMons[bank].hp != 0)
                {
                    gBankTarget = bank;
                    gHitMarker |= HITMARKER_NO_ATTACKSTRING;
                    gBattleScripting.atk49_state = 0;
                    MoveValuesCleanUp();
                    BattleScriptPush(gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect]);
                    gBattlescriptCurrInstr = gUnknown_082DB87D;
                    return;
                }
                else
                {
                    gHitMarker |= HITMARKER_NO_ATTACKSTRING;
                }
            }
            gBattleScripting.atk49_state++;
            break;
        case ATK49_LAST_CASE:
            break;
        }

        if (arg1 == 1 && effect == FALSE)
            gBattleScripting.atk49_state = ATK49_LAST_CASE;
        if (arg1 == 2 && arg2 == gBattleScripting.atk49_state)
            gBattleScripting.atk49_state = ATK49_LAST_CASE;

    } while (gBattleScripting.atk49_state != ATK49_LAST_CASE && effect == FALSE);

    if (gBattleScripting.atk49_state == ATK49_LAST_CASE && effect == FALSE)
        gBattlescriptCurrInstr += 3;
}

static void atk4A_typecalc2(void)
{
    u8 flags = 0;
    s32 i = 0;
    u8 moveType = gBattleMoves[gCurrentMove].type;

    if (gBattleMons[gBankTarget].ability == ABILITY_LEVITATE && moveType == TYPE_GROUND)
    {
        gLastUsedAbility = gBattleMons[gBankTarget].ability;
        gBattleMoveFlags |= (MOVESTATUS_MISSED | MOVESTATUS_NOTAFFECTED);
        gUnknown_02024250[gBankTarget] = 0;
        gBattleCommunication[6] = moveType;
        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
    }
    else
    {
        while (gTypeEffectiveness[i]!= TYPE_ENDTABLE)
        {
            if (gTypeEffectiveness[i] == TYPE_FORESIGHT)
            {
                if (gBattleMons[gBankTarget].status2 & STATUS2_FORESIGHT)
                {
                    break;
                }
                else
                {
                    i += 3;
                    continue;
                }
            }

            if (gTypeEffectiveness[i] == moveType)
            {
                // check type1
                if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type1)
                {
                    if (gTypeEffectiveness[i + 2] == 0)
                    {
                        gBattleMoveFlags |= MOVESTATUS_NOTAFFECTED;
                        break;
                    }
                    if (gTypeEffectiveness[i + 2] == 5)
                    {
                        flags |= MOVESTATUS_NOTVERYEFFECTIVE;
                    }
                    if (gTypeEffectiveness[i + 2] == 20)
                    {
                        flags |= MOVESTATUS_SUPEREFFECTIVE;
                    }
                }
                // check type2
                if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type2)
                {
                    if (gBattleMons[gBankTarget].type1 != gBattleMons[gBankTarget].type2
                        && gTypeEffectiveness[i + 2] == 0)
                    {
                        gBattleMoveFlags |= MOVESTATUS_NOTAFFECTED;
                        break;
                    }
                    if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type2
                        && gBattleMons[gBankTarget].type1 != gBattleMons[gBankTarget].type2
                        && gTypeEffectiveness[i + 2] == 5)
                    {
                        flags |= MOVESTATUS_NOTVERYEFFECTIVE;
                    }
                    if (gTypeEffectiveness[i + 1] == gBattleMons[gBankTarget].type2
                        && gBattleMons[gBankTarget].type1 != gBattleMons[gBankTarget].type2
                        && gTypeEffectiveness[i + 2] == 20)
                    {
                        flags |= MOVESTATUS_SUPEREFFECTIVE;
                    }
                }
            }
            i += 3;
        }
    }

    if (gBattleMons[gBankTarget].ability == ABILITY_WONDER_GUARD
        && !(flags & MOVESTATUS_NOEFFECT)
        && AttacksThisTurn(gBankAttacker, gCurrentMove) == 2
        && (!(flags & MOVESTATUS_SUPEREFFECTIVE) || ((flags & (MOVESTATUS_SUPEREFFECTIVE | MOVESTATUS_NOTVERYEFFECTIVE)) == (MOVESTATUS_SUPEREFFECTIVE | MOVESTATUS_NOTVERYEFFECTIVE)))
        && gBattleMoves[gCurrentMove].power)
    {
        gLastUsedAbility = ABILITY_WONDER_GUARD;
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gUnknown_02024250[gBankTarget] = 0;
        gBattleCommunication[6] = 3;
        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
    }
    if (gBattleMoveFlags & MOVESTATUS_NOTAFFECTED)
        gProtectStructs[gBankAttacker].notEffective = 1;

    gBattlescriptCurrInstr++;
}

static void atk4B_return_atk_to_ball(void)
{
    gActiveBank = gBankAttacker;
    if (!(gHitMarker & HITMARKER_FAINTED(gActiveBank)))
    {
        EmitReturnPokeToBall(0, 0);
        MarkBufferBankForExecution(gActiveBank);
    }
    gBattlescriptCurrInstr++;
}

static void atk4C_copy_poke_data(void)
{
    if (gBattleExecBuffer)
        return;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    gBattlePartyID[gActiveBank] = *(gBattleStruct->field_5C + gActiveBank);

    EmitGetMonData(0, 0, gBitTable[gBattlePartyID[gActiveBank]]);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 2;
}

static void atk4D_switch_data_update(void)
{
    struct BattlePokemon oldData;
    s32 i;
    u8 *monData;

    if (gBattleExecBuffer)
        return;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
    oldData = gBattleMons[gActiveBank];
    monData = (u8*)(&gBattleMons[gActiveBank]);

    for (i = 0; i < sizeof(struct BattlePokemon); i++)
    {
        monData[i] = gBattleBufferB[gActiveBank][4 + i];
    }

    gBattleMons[gActiveBank].type1 = gBaseStats[gBattleMons[gActiveBank].species].type1;
    gBattleMons[gActiveBank].type2 = gBaseStats[gBattleMons[gActiveBank].species].type2;
    gBattleMons[gActiveBank].ability = GetAbilityBySpecies(gBattleMons[gActiveBank].species, gBattleMons[gActiveBank].altAbility);

    // check knocked off item
    i = GetBankSide(gActiveBank);
    if (gWishFutureKnock.knockedOffPokes[i] & gBitTable[gBattlePartyID[gActiveBank]])
    {
        gBattleMons[gActiveBank].item = 0;
    }

    if (gBattleMoves[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        for (i = 0; i < 8; i++)
        {
            gBattleMons[gActiveBank].statStages[i] = oldData.statStages[i];
        }
        gBattleMons[gActiveBank].status2 = oldData.status2;
    }

    SwitchInClearStructs();

    if (gBattleTypeFlags & BATTLE_TYPE_PALACE && gBattleMons[gActiveBank].maxHP / 2 >= gBattleMons[gActiveBank].hp
        && gBattleMons[gActiveBank].hp != 0 && !(gBattleMons[gActiveBank].status1 & STATUS_SLEEP))
    {
        gBattleStruct->field_92 |= gBitTable[gActiveBank];
    }

    gBattleScripting.bank = gActiveBank;
    gBattleTextBuff1[0] = PLACEHOLDER_BEGIN;
    gBattleTextBuff1[1] = 7;
    gBattleTextBuff1[2] = gActiveBank;
    gBattleTextBuff1[3] = gBattlePartyID[gActiveBank];
    gBattleTextBuff1[4] = EOS;

    gBattlescriptCurrInstr += 2;
}

static void atk4E_switchin_anim(void)
{
    if (gBattleExecBuffer)
        return;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    if (GetBankSide(gActiveBank) == SIDE_OPPONENT
        && !(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                 | BATTLE_TYPE_EREADER_TRAINER
                                 | BATTLE_TYPE_x2000000
                                 | BATTLE_TYPE_x4000000
                                 | BATTLE_TYPE_FRONTIER)))
            HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBank].species), FLAG_SET_SEEN, gBattleMons[gActiveBank].personality);

    gAbsentBankFlags &= ~(gBitTable[gActiveBank]);

    EmitSwitchInAnim(0, gBattlePartyID[gActiveBank], gBattlescriptCurrInstr[2]);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 3;

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        sub_81A56B4();
}

static void atk4F_jump_if_cannot_switch(void)
{
    s32 val = 0;
    s32 compareVar = 0;
    struct Pokemon *party = NULL;
    s32 r7 = 0;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1] & ~(ATK4F_DONT_CHECK_STATUSES));

    if (!(gBattlescriptCurrInstr[1] & ATK4F_DONT_CHECK_STATUSES)
        && ((gBattleMons[gActiveBank].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
            || (gStatuses3[gActiveBank] & STATUS3_ROOTED)))
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        #ifndef NONMATCHING
            asm("":::"r5");
        #endif // NONMATCHING
        if (GetBankSide(gActiveBank) == SIDE_OPPONENT)
            party = gEnemyParty;
        else
            party = gPlayerParty;

        val = 0;
        if (2 & gActiveBank)
            val = 3;

        for (compareVar = val + 3; val < compareVar; val++)
        {
            if (GetMonData(&party[val], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[val], MON_DATA_IS_EGG)
             && GetMonData(&party[val], MON_DATA_HP) != 0
             && gBattlePartyID[gActiveBank] != val)
                break;
        }

        if (val == compareVar)
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_x800000)
        {
            if (GetBankSide(gActiveBank) == SIDE_PLAYER)
            {
                party = gPlayerParty;

                val = 0;
                if (sub_806D82C(sub_806D864(gActiveBank)) == TRUE)
                    val = 3;
            }
            else
            {
                party = gEnemyParty;

                if (gActiveBank == 1)
                    val = 0;
                else
                    val = 3;
            }
        }
        else
        {
            if (GetBankSide(gActiveBank) == SIDE_OPPONENT)
                party = gEnemyParty;
            else
                party = gPlayerParty;


            val = 0;
            if (sub_806D82C(sub_806D864(gActiveBank)) == TRUE)
                val = 3;
        }

        for (compareVar = val + 3; val < compareVar; val++)
        {
            if (GetMonData(&party[val], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[val], MON_DATA_IS_EGG)
             && GetMonData(&party[val], MON_DATA_HP) != 0
             && gBattlePartyID[gActiveBank] != val)
                break;
        }

        if (val == compareVar)
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && GetBankSide(gActiveBank) == SIDE_OPPONENT)
    {
        party = gEnemyParty;

        val = 0;
        if (gActiveBank == 3)
            val = 3;

        for (compareVar = val + 3; val < compareVar; val++)
        {
            if (GetMonData(&party[val], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[val], MON_DATA_IS_EGG)
             && GetMonData(&party[val], MON_DATA_HP) != 0
             && gBattlePartyID[gActiveBank] != val)
                break;
        }

        if (val == compareVar)
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
    else
    {
        if (GetBankSide(gActiveBank) == SIDE_OPPONENT)
        {
            r7 = GetBankByIdentity(1);

            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                compareVar = GetBankByIdentity(3);
            else
                compareVar = r7;

            party = gEnemyParty;
        }
        else
        {
            r7 = GetBankByIdentity(0);

            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                compareVar = GetBankByIdentity(2);
            else
                compareVar = r7;

            party = gPlayerParty;
        }
        for (val = 0; val < 6; val++)
        {
            if (GetMonData(&party[val], MON_DATA_HP) != 0
             && GetMonData(&party[val], MON_DATA_SPECIES) != SPECIES_NONE
             && !GetMonData(&party[val], MON_DATA_IS_EGG)
             && val != gBattlePartyID[r7] && val != gBattlePartyID[compareVar])
                break;
        }

        if (val == 6)
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;
    }
}

static void sub_804CF10(u8 arg0)
{
    *(gBattleStruct->field_58 + gActiveBank) = gBattlePartyID[gActiveBank];
    *(gBattleStruct->field_5C + gActiveBank) = 6;
    gBattleStruct->field_93 &= ~(gBitTable[gActiveBank]);

    EmitChoosePokemon(0, 1, arg0, 0, gBattleStruct->field_60[gActiveBank]);
    MarkBufferBankForExecution(gActiveBank);
}

static void atk50_openpartyscreen(void)
{
    u32 flags;
    u8 hitmarkerFaintBits;
    u8 bank;
    const u8 *jumpPtr;

    bank = 0;
    flags = 0;
    jumpPtr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);

    if (gBattlescriptCurrInstr[1] == 5)
    {
        if ((gBattleTypeFlags & (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_MULTI)) != BATTLE_TYPE_DOUBLE)
        {
            for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
            {
                if (gHitMarker & HITMARKER_FAINTED(gActiveBank))
                {
                    if (sub_80423F4(gActiveBank, 6, 6))
                    {
                        gAbsentBankFlags |= gBitTable[gActiveBank];
                        gHitMarker &= ~(HITMARKER_FAINTED(gActiveBank));
                        EmitLinkStandbyMsg(0, 2, 0);
                        MarkBufferBankForExecution(gActiveBank);
                    }
                    else if (!gSpecialStatuses[gActiveBank].flag40)
                    {
                        sub_804CF10(6);
                        gSpecialStatuses[gActiveBank].flag40 = 1;
                    }
                }
                else
                {
                    EmitLinkStandbyMsg(0, 2, 0);
                    MarkBufferBankForExecution(gActiveBank);
                }
            }
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            u8 flag40_0, flag40_1, flag40_2, flag40_3;

            hitmarkerFaintBits = gHitMarker >> 0x1C;

            if (gBitTable[0] & hitmarkerFaintBits)
            {
                gActiveBank = 0;
                if (sub_80423F4(0, 6, 6))
                {
                    gAbsentBankFlags |= gBitTable[gActiveBank];
                    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBank));
                    Emit_x2A(0);
                    MarkBufferBankForExecution(gActiveBank);
                }
                else if (!gSpecialStatuses[gActiveBank].flag40)
                {
                    sub_804CF10(gBattleStruct->field_5C[2]);
                    gSpecialStatuses[gActiveBank].flag40 = 1;
                }
                else
                {
                    EmitLinkStandbyMsg(0, 2, 0);
                    MarkBufferBankForExecution(gActiveBank);
                    flags |= 1;
                }
            }
            if (gBitTable[2] & hitmarkerFaintBits && !(gBitTable[0] & hitmarkerFaintBits))
            {
                gActiveBank = 2;
                if (sub_80423F4(2, 6, 6))
                {
                    gAbsentBankFlags |= gBitTable[gActiveBank];
                    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBank));
                    Emit_x2A(0);
                    MarkBufferBankForExecution(gActiveBank);
                }
                else if (!gSpecialStatuses[gActiveBank].flag40)
                {
                    sub_804CF10(gBattleStruct->field_5C[0]);
                    gSpecialStatuses[gActiveBank].flag40 = 1;
                }
                else if (!(flags & 1))
                {
                    EmitLinkStandbyMsg(0, 2, 0);
                    MarkBufferBankForExecution(gActiveBank);
                }
            }
            if (gBitTable[1] & hitmarkerFaintBits)
            {
                gActiveBank = 1;
                if (sub_80423F4(1, 6, 6))
                {
                    gAbsentBankFlags |= gBitTable[gActiveBank];
                    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBank));
                    Emit_x2A(0);
                    MarkBufferBankForExecution(gActiveBank);
                }
                else if (!gSpecialStatuses[gActiveBank].flag40)
                {
                    sub_804CF10(gBattleStruct->field_5C[3]);
                    gSpecialStatuses[gActiveBank].flag40 = 1;
                }
                else
                {
                    EmitLinkStandbyMsg(0, 2, 0);
                    MarkBufferBankForExecution(gActiveBank);
                    flags |= 2;
                }
            }
            if (gBitTable[3] & hitmarkerFaintBits && !(gBitTable[1] & hitmarkerFaintBits))
            {
                gActiveBank = 3;
                if (sub_80423F4(3, 6, 6))
                {
                    gAbsentBankFlags |= gBitTable[gActiveBank];
                    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBank));
                    Emit_x2A(0);
                    MarkBufferBankForExecution(gActiveBank);
                }
                else if (!gSpecialStatuses[gActiveBank].flag40)
                {
                    sub_804CF10(gBattleStruct->field_5C[1]);
                    gSpecialStatuses[gActiveBank].flag40 = 1;
                }
                else if (!(flags & 2))
                {
                    EmitLinkStandbyMsg(0, 2, 0);
                    MarkBufferBankForExecution(gActiveBank);
                }
            }

            flag40_0 = gSpecialStatuses[0].flag40;
            if (!flag40_0)
            {
                flag40_2 = gSpecialStatuses[2].flag40;
                if (!flag40_2 && hitmarkerFaintBits != 0)
                {
                    if (gAbsentBankFlags & gBitTable[0])
                        gActiveBank = 2;
                    else
                        gActiveBank = 0;

                    EmitLinkStandbyMsg(0, 2, 0);
                    MarkBufferBankForExecution(gActiveBank);
                }

            }
            flag40_1 = gSpecialStatuses[1].flag40;
            if (!flag40_1)
            {
                flag40_3 = gSpecialStatuses[3].flag40;
                if (!flag40_3 && hitmarkerFaintBits != 0)
                {
                    if (gAbsentBankFlags & gBitTable[1])
                        gActiveBank = 3;
                    else
                        gActiveBank = 1;

                    EmitLinkStandbyMsg(0, 2, 0);
                    MarkBufferBankForExecution(gActiveBank);
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
                    gActiveBank = 2;
                    if (sub_80423F4(2, gBattleBufferB[0][1], 6))
                    {
                        gAbsentBankFlags |= gBitTable[gActiveBank];
                        gHitMarker &= ~(HITMARKER_FAINTED(gActiveBank));
                        Emit_x2A(0);
                        MarkBufferBankForExecution(gActiveBank);
                    }
                    else if (!gSpecialStatuses[gActiveBank].flag40)
                    {
                        sub_804CF10(gBattleStruct->field_5C[0]);
                        gSpecialStatuses[gActiveBank].flag40 = 1;
                    }
                }
                if (gBitTable[3] & hitmarkerFaintBits && hitmarkerFaintBits & gBitTable[1])
                {
                    gActiveBank = 3;
                    if (sub_80423F4(3, gBattleBufferB[1][1], 6))
                    {
                        gAbsentBankFlags |= gBitTable[gActiveBank];
                        gHitMarker &= ~(HITMARKER_FAINTED(gActiveBank));
                        Emit_x2A(0);
                        MarkBufferBankForExecution(gActiveBank);
                    }
                    else if (!gSpecialStatuses[gActiveBank].flag40)
                    {
                        sub_804CF10(gBattleStruct->field_5C[1]);
                        gSpecialStatuses[gActiveBank].flag40 = 1;
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

        gBank1 = 0;
        while (1)
        {
            if (gBitTable[gBank1] & hitmarkerFaintBits)
                break;
            if (gBank1 >= gNoOfAllBanks)
                break;
            gBank1++;
        }

        if (gBank1 == gNoOfAllBanks)
            gBattlescriptCurrInstr = jumpPtr;
    }
    else
    {
        if (gBattlescriptCurrInstr[1] & 0x80)
            hitmarkerFaintBits = 0; // used here as the caseId for the EmitChoose function
        else
            hitmarkerFaintBits = 1;

        bank = GetBattleBank(gBattlescriptCurrInstr[1] & ~(0x80));
        if (gSpecialStatuses[bank].flag40)
        {
            gBattlescriptCurrInstr += 6;
        }
        else if (sub_80423F4(bank, 6, 6))
        {
            gActiveBank = bank;
            gAbsentBankFlags |= gBitTable[gActiveBank];
            gHitMarker &= ~(HITMARKER_FAINTED(gActiveBank));
            gBattlescriptCurrInstr = jumpPtr;
        }
        else
        {
            gActiveBank = bank;
            *(gBattleStruct->field_58 + gActiveBank) = gBattlePartyID[gActiveBank];
            *(gBattleStruct->field_5C + gActiveBank) = 6;
            gBattleStruct->field_93 &= ~(gBitTable[gActiveBank]);

            EmitChoosePokemon(0, hitmarkerFaintBits, *(gBattleStruct->field_5C + (gActiveBank ^ 2)), 0, gBattleStruct->field_60[gActiveBank]);
            MarkBufferBankForExecution(gActiveBank);

            gBattlescriptCurrInstr += 6;

            if (GetBankIdentity(gActiveBank) == 0 && gBattleResults.playerSwitchesCounter < 0xFF)
                gBattleResults.playerSwitchesCounter++;

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                for (gActiveBank = 0; gActiveBank < gNoOfAllBanks; gActiveBank++)
                {
                    if (gActiveBank != bank)
                    {
                        EmitLinkStandbyMsg(0, 2, 0);
                        MarkBufferBankForExecution(gActiveBank);
                    }
                }
            }
            else
            {
                gActiveBank = GetBankByIdentity(GetBankIdentity(bank) ^ BIT_SIDE);
                if (gAbsentBankFlags & gBitTable[gActiveBank])
                    gActiveBank ^= BIT_MON;

                EmitLinkStandbyMsg(0, 2, 0);
                MarkBufferBankForExecution(gActiveBank);
            }
        }
    }
}

static void atk51_switch_handle_order(void)
{
    s32 i;
    if (gBattleExecBuffer)
        return;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    switch (gBattlescriptCurrInstr[2])
    {
    case 0:
        for (i = 0; i < gNoOfAllBanks; i++)
        {
            if (gBattleBufferB[i][0] == 0x22)
            {
                *(gBattleStruct->field_5C + i) = gBattleBufferB[i][1];
                if (!(gBattleStruct->field_93 & gBitTable[i]))
                {
                    RecordedBattle_SetBankAction(i, gBattleBufferB[i][1]);
                    gBattleStruct->field_93 |= gBitTable[i];
                }
            }
        }
        break;
    case 1:
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            sub_803BDA0(gActiveBank);
        break;
    case 2:
        if (!(gBattleStruct->field_93 & gBitTable[gActiveBank]))
        {
            RecordedBattle_SetBankAction(gActiveBank, gBattleBufferB[gActiveBank][1]);
            gBattleStruct->field_93 |= gBitTable[gActiveBank];
        }
        // fall through
    case 3:
        gBattleCommunication[0] = gBattleBufferB[gActiveBank][1];
        *(gBattleStruct->field_5C + gActiveBank) = gBattleBufferB[gActiveBank][1];

        if ((gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_LINK)) == (BATTLE_TYPE_MULTI | BATTLE_TYPE_LINK))
        {
            *(gActiveBank * 3 + (u8*)(gBattleStruct->field_60) + 0) &= 0xF;
            *(gActiveBank * 3 + (u8*)(gBattleStruct->field_60) + 0) |= (gBattleBufferB[gActiveBank][2] & 0xF0);
            *(gActiveBank * 3 + (u8*)(gBattleStruct->field_60) + 1) = gBattleBufferB[gActiveBank][3];

            *((gActiveBank ^ 2) * 3 + (u8*)(gBattleStruct->field_60) + 0) &= (0xF0);
            *((gActiveBank ^ 2) * 3 + (u8*)(gBattleStruct->field_60) + 0) |= (gBattleBufferB[gActiveBank][2] & 0xF0) >> 4;
            *((gActiveBank ^ 2) * 3 + (u8*)(gBattleStruct->field_60) + 2) = gBattleBufferB[gActiveBank][3];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            sub_80571DC(gActiveBank, *(gBattleStruct->field_5C + gActiveBank));
        }
        else
        {
            sub_803BDA0(gActiveBank);
        }

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBankAttacker].species)
        PREPARE_MON_NICK_BUFFER(gBattleTextBuff2, gActiveBank, gBattleBufferB[gActiveBank][1])

        break;
    }

    gBattlescriptCurrInstr += 3;
}

static void atk52_switch_in_effects(void)
{
    s32 i;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
    sub_803FA70(gActiveBank);

    gHitMarker &= ~(HITMARKER_FAINTED(gActiveBank));
    gSpecialStatuses[gActiveBank].flag40 = 0;

    if (!(gSideAffecting[GetBankSide(gActiveBank)] & SIDE_STATUS_SPIKES_DAMAGED)
        && (gSideAffecting[GetBankSide(gActiveBank)] & SIDE_STATUS_SPIKES)
        && gBattleMons[gActiveBank].type1 != TYPE_FLYING
        && gBattleMons[gActiveBank].type2 != TYPE_FLYING
        && gBattleMons[gActiveBank].ability != ABILITY_LEVITATE)
    {
        u8 spikesDmg;

        gSideAffecting[GetBankSide(gActiveBank)] |= SIDE_STATUS_SPIKES_DAMAGED;

        gBattleMons[gActiveBank].status2 &= ~(STATUS2_DESTINY_BOND);
        gHitMarker &= ~(HITMARKER_DESTINYBOND);

        spikesDmg = (5 - gSideTimers[GetBankSide(gActiveBank)].spikesAmount) * 2;
        gBattleMoveDamage = gBattleMons[gActiveBank].maxHP / (spikesDmg);
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattleScripting.bank = gActiveBank;
        BattleScriptPushCursor();

        if (gBattlescriptCurrInstr[1] == 0)
            gBattlescriptCurrInstr = gUnknown_082DAE90;
        else if (gBattlescriptCurrInstr[1] == 1)
            gBattlescriptCurrInstr = gUnknown_082DAE59;
        else
            gBattlescriptCurrInstr = gUnknown_082DAEC7;
    }
    else
    {
        if (gBattleMons[gActiveBank].ability == ABILITY_TRUANT && !gDisableStructs[gActiveBank].truantUnknownBit)
            gDisableStructs[gActiveBank].truantCounter = 1;

        gDisableStructs[gActiveBank].truantUnknownBit = 0;

        if (AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, gActiveBank, 0, 0, 0) == 0 &&
            ItemBattleEffects(0, gActiveBank, 0) == 0)
        {
            gSideAffecting[GetBankSide(gActiveBank)] &= ~(SIDE_STATUS_SPIKES_DAMAGED);

            for (i = 0; i < gNoOfAllBanks; i++)
            {
                if (gTurnOrder[i] == gActiveBank)
                    gUnknown_0202407A[i] = 0xC;
            }

            for (i = 0; i < gNoOfAllBanks; i++)
            {
                u16* hpOnSwitchout = &gBattleStruct->hpOnSwitchout[GetBankSide(i)];
                *hpOnSwitchout = gBattleMons[i].hp;
            }

            if (gBattlescriptCurrInstr[1] == 5)
            {
                u32 hitmarkerFaintBits = gHitMarker >> 0x1C;

                gBank1++;
                while (1)
                {
                    if (hitmarkerFaintBits & gBitTable[gBank1] && !(gAbsentBankFlags & gBitTable[gBank1]))
                        break;
                    if (gBank1 >= gNoOfAllBanks)
                        break;
                    gBank1++;
                }
            }
            gBattlescriptCurrInstr += 2;
        }
    }
}

static void atk53_trainer_slide(void)
{
    gActiveBank = GetBankByIdentity(gBattlescriptCurrInstr[1]);
    EmitTrainerSlide(0);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 2;
}

static void atk54_effectiveness_sound(void)
{
    gActiveBank = gBankAttacker;
    EmitEffectivenessSound(0, BS2ScriptRead16(gBattlescriptCurrInstr + 1));
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 3;
}

static void atk55_play_sound(void)
{
    gActiveBank = gBankAttacker;
    EmitPlaySound(0, BS2ScriptRead16(gBattlescriptCurrInstr + 1), 0);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 3;
}

static void atk56_fainting_cry(void)
{
    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
    EmitFaintingCry(0);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 2;
}

static void atk57(void)
{
    gActiveBank = GetBankByIdentity(0);
    Emit_x37(0, gBattleOutcome);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 1;
}

static void atk58_return_to_ball(void)
{
    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
    EmitReturnPokeToBall(0, 1);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 2;
}

static void atk59_learnmove_inbattle(void)
{
    const u8* jumpPtr1 = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    const u8* jumpPtr2 = BSScriptReadPtr(gBattlescriptCurrInstr + 5);

    u16 ret = MonTryLearningNewMove(&gPlayerParty[gBattleStruct->expGetterId], gBattlescriptCurrInstr[9]);
    while (ret == 0xFFFE)
        ret = MonTryLearningNewMove(&gPlayerParty[gBattleStruct->expGetterId], 0);

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
        gActiveBank = GetBankByIdentity(0);

        if (gBattlePartyID[gActiveBank] == gBattleStruct->expGetterId
            && !(gBattleMons[gActiveBank].status2 & STATUS2_TRANSFORMED))
        {
            GiveMoveToBattleMon(&gBattleMons[gActiveBank], ret);
        }
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            gActiveBank = GetBankByIdentity(2);
            if (gBattlePartyID[gActiveBank] == gBattleStruct->expGetterId
                && !(gBattleMons[gActiveBank].status2 & STATUS2_TRANSFORMED))
            {
                GiveMoveToBattleMon(&gBattleMons[gActiveBank], ret);
            }
        }

        gBattlescriptCurrInstr = jumpPtr1;
    }
}

static void atk5A_yesnoboxlearnmove(void)
{
    gActiveBank = 0;

    switch (gBattleScripting.learnMoveState)
    {
    case 0:
        sub_8056A3C(0x18, 8, 0x1D, 0xD, 0);
        sub_814F9EC(gText_BattleYesNoChoice, 0xC);
        gBattleScripting.learnMoveState++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateCursorAt(0);
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateCursorAt(0);
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateCursorAt(1);
        }
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[1] == 0)
            {
                sub_8056A3C(0x18, 0x8, 0x1D, 0xD, 1);
                BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
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
            sub_81BFA38(gPlayerParty, gBattleStruct->expGetterId, gPlayerPartyCount - 1, ReshowBattleScreenAfterMenu, gMoveToLearn);
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
                u16 moveId = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_MOVE1 + movePosition);
                if (IsHMMove2(moveId))
                {
                    PrepareStringBattle(0x13F, gActiveBank);
                    gBattleScripting.learnMoveState = 6;
                }
                else
                {
                    gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);

                    PREPARE_MOVE_BUFFER(gBattleTextBuff2, moveId)

                    RemoveMonPPBonus(&gPlayerParty[gBattleStruct->expGetterId], movePosition);
                    SetMonMoveSlot(&gPlayerParty[gBattleStruct->expGetterId], gMoveToLearn, movePosition);

                    if (gBattlePartyID[0] == gBattleStruct->expGetterId
                        && !(gBattleMons[0].status2 & STATUS2_TRANSFORMED)
                        && !(gDisableStructs[0].unk18_b & gBitTable[movePosition]))
                    {
                        RemoveBattleMonPPBonus(&gBattleMons[0], movePosition);
                        SetBattleMonMoveSlot(&gBattleMons[0], gMoveToLearn, movePosition);
                    }
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                        && gBattlePartyID[2] == gBattleStruct->expGetterId
                        && !(gBattleMons[2].status2 & STATUS2_TRANSFORMED)
                        && !(gDisableStructs[2].unk18_b & gBitTable[movePosition]))
                    {
                        RemoveBattleMonPPBonus(&gBattleMons[2], movePosition);
                        SetBattleMonMoveSlot(&gBattleMons[2], gMoveToLearn, movePosition);
                    }
                }
            }
        }
        break;
    case 5:
        sub_8056A3C(0x18, 8, 0x1D, 0xD, 1);
        gBattlescriptCurrInstr += 5;
        break;
    case 6:
        if (gBattleExecBuffer == 0)
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
        sub_8056A3C(0x18, 8, 0x1D, 0xD, 0);
        sub_814F9EC(gText_BattleYesNoChoice, 0xC);
        gBattleScripting.learnMoveState++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateCursorAt(0);
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateCursorAt(0);
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateCursorAt(1);
        }
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);

            if (gBattleCommunication[1] != 0)
                gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
            else
                gBattlescriptCurrInstr += 5;

            sub_8056A3C(0x18, 0x8, 0x1D, 0xD, 1);
        }
        else if (gMain.newKeys & B_BUTTON)
        {
            PlaySE(SE_SELECT);
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
            sub_8056A3C(0x18, 0x8, 0x1D, 0xD, 1);
        }
        break;
    }
}

static void atk5C_hitanimation(void)
{
    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    if (gBattleMoveFlags & MOVESTATUS_NOEFFECT)
    {
        gBattlescriptCurrInstr += 2;
    }
    else if (!(gHitMarker & HITMARKER_IGNORE_SUBSTITUTE) || !(gBattleMons[gActiveBank].status2 & STATUS2_SUBSTITUTE) || gDisableStructs[gActiveBank].substituteHP == 0)
    {
        EmitHitAnimation(0);
        MarkBufferBankForExecution(gActiveBank);
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

    if (trainerId == SECRET_BASE_OPPONENT)
    {
        moneyReward = 20 * gBattleResources->secretBase->partyLevels[0] * gBattleStruct->moneyMultiplier;
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
        case PARTY_FLAG_CUSTOM_MOVES:
            {
                const struct TrainerMonNoItemCustomMoves *party = gTrainers[trainerId].party.NoItemCustomMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case PARTY_FLAG_HAS_ITEM:
            {
                const struct TrainerMonItemDefaultMoves *party = gTrainers[trainerId].party.ItemDefaultMoves;
                lastMonLevel = party[gTrainers[trainerId].partySize - 1].lvl;
            }
            break;
        case PARTY_FLAG_CUSTOM_MOVES | PARTY_FLAG_HAS_ITEM:
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

    PREPARE_WORD_NUMBER_BUFFER(gBattleTextBuff1, 5, moneyReward)

    gBattlescriptCurrInstr++;
}

static void atk5E_8025A70(void)
{
    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    switch (gBattleCommunication[0])
    {
    case 0:
        EmitGetMonData(0, REQUEST_ALL_BATTLE, 0);
        MarkBufferBankForExecution(gActiveBank);
        gBattleCommunication[0]++;
        break;
    case 1:
         if (gBattleExecBuffer == 0)
         {
            s32 i;
            struct BattlePokemon* bufferPoke = (struct BattlePokemon*) &gBattleBufferB[gActiveBank][4];
            for (i = 0; i < 4; i++)
            {
                gBattleMons[gActiveBank].moves[i] = bufferPoke->moves[i];
                gBattleMons[gActiveBank].pp[i] = bufferPoke->pp[i];
            }
            gBattlescriptCurrInstr += 2;
         }
         break;
    }
}

static void atk5F_8025B24(void)
{
    gActiveBank = gBankAttacker;
    gBankAttacker = gBankTarget;
    gBankTarget = gActiveBank;

    if (gHitMarker & HITMARKER_PURSUIT_TRAP)
        gHitMarker &= ~(HITMARKER_PURSUIT_TRAP);
    else
        gHitMarker |= HITMARKER_PURSUIT_TRAP;

    gBattlescriptCurrInstr++;
}

static void atk60_increment_gamestat(void)
{
    if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
        IncrementGameStat(gBattlescriptCurrInstr[1]);

    gBattlescriptCurrInstr += 2;
}

static void atk61_8025BA4(void)
{
    s32 i;
    struct Pokemon* party;
    struct HpAndStatus hpStatuses[6];

    if (gBattleExecBuffer)
        return;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    if (GetBankSide(gActiveBank) == SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < 6; i++)
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

    EmitCmd48(0, hpStatuses, 1);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 2;
}

static void atk62_08025C6C(void)
{
    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
    EmitCmd49(0);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 2;
}

static void atk63_jumptorandomattack(void)
{
    if (gBattlescriptCurrInstr[1] != 0)
        gCurrentMove = gRandomMove;
    else
        gLastUsedMove = gCurrentMove = gRandomMove;

    gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
}

static void atk64_statusanimation(void)
{
    if (gBattleExecBuffer == 0)
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
        if (!(gStatuses3[gActiveBank] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[gActiveBank].substituteHP == 0
            && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            EmitStatusAnimation(0, FALSE, gBattleMons[gActiveBank].status1);
            MarkBufferBankForExecution(gActiveBank);
        }
        gBattlescriptCurrInstr += 2;
    }
}

static void atk65_status2animation(void)
{
    u32 wantedToAnimate;

    if (gBattleExecBuffer == 0)
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
        wantedToAnimate = BSScriptRead32(gBattlescriptCurrInstr + 2);
        if (!(gStatuses3[gActiveBank] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[gActiveBank].substituteHP == 0
            && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            EmitStatusAnimation(0, TRUE, gBattleMons[gActiveBank].status2 & wantedToAnimate);
            MarkBufferBankForExecution(gActiveBank);
        }
        gBattlescriptCurrInstr += 6;
    }
}

static void atk66_chosenstatusanimation(void)
{
    u32 wantedStatus;

    if (gBattleExecBuffer == 0)
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
        wantedStatus = BSScriptRead32(gBattlescriptCurrInstr + 3);
        if (!(gStatuses3[gActiveBank] & STATUS3_SEMI_INVULNERABLE)
            && gDisableStructs[gActiveBank].substituteHP == 0
            && !(gHitMarker & HITMARKER_NO_ANIMATIONS))
        {
            EmitStatusAnimation(0, gBattlescriptCurrInstr[2], wantedStatus);
            MarkBufferBankForExecution(gActiveBank);
        }
        gBattlescriptCurrInstr += 7;
    }
}

static void atk67_yesnobox(void)
{
    switch (gBattleCommunication[0])
    {
    case 0:
        sub_8056A3C(0x18, 8, 0x1D, 0xD, 0);
        sub_814F9EC(gText_BattleYesNoChoice, 0xC);
        gBattleCommunication[0]++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateCursorAt(0);
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateCursorAt(0);
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateCursorAt(1);
        }
        if (gMain.newKeys & B_BUTTON)
        {
            gBattleCommunication[CURSOR_POSITION] = 1;
            PlaySE(SE_SELECT);
            sub_8056A3C(0x18, 8, 0x1D, 0xD, 1);
            gBattlescriptCurrInstr++;
        }
        else if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            sub_8056A3C(0x18, 8, 0x1D, 0xD, 1);
            gBattlescriptCurrInstr++;
        }
        break;
    }
}

static void atk68_80246A0(void)
{
    s32 i;

    for (i = 0; i < gNoOfAllBanks; i++)
        gUnknown_0202407A[i] = 0xC;

    gBattlescriptCurrInstr++;
}

static void atk69_dmg_adjustment3(void) // The same as 0x7, except there's no random damage multiplier.
{
    u8 holdEffect, quality;

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

static void atk6A_removeitem(void)
{
    u16* usedHeldItem;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    usedHeldItem = &gBattleStruct->usedHeldItems[gActiveBank];
    *usedHeldItem = gBattleMons[gActiveBank].item;
    gBattleMons[gActiveBank].item = 0;

    EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gActiveBank].item);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 2;
}

static void atk6B_atknameinbuff1(void)
{
    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBankAttacker, gBattlePartyID[gBankAttacker])

    gBattlescriptCurrInstr++;
}

static void atk6C_draw_lvlupbox(void)
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
        SetBgAttribute(2, BG_CTRL_ATTR_MOSAIC, 0);
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
        SetBgAttribute(0, BG_CTRL_ATTR_MOSAIC, 1);
        SetBgAttribute(1, BG_CTRL_ATTR_MOSAIC, 0);
        ShowBg(0);
        ShowBg(1);
        sub_8056A3C(0x12, 7, 0x1D, 0x13, 0x80);
        gBattleScripting.atk6C_state = 4;
        break;
    case 4:
        sub_804F100();
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
            sub_804F144();
            CopyWindowToVram(13, 2);
            gBattleScripting.atk6C_state++;
        }
        break;
    case 8:
        if (gMain.newKeys != 0)
        {
            PlaySE(SE_SELECT);
            sub_8056A3C(0x12, 7, 0x1D, 0x13, 0x81);
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

            SetBgAttribute(2, BG_CTRL_ATTR_MOSAIC, 2);
            ShowBg(2);

            gBattleScripting.atk6C_state = 10;
        }
        break;
    case 10:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetBgAttribute(0, BG_CTRL_ATTR_MOSAIC, 0);
            SetBgAttribute(1, BG_CTRL_ATTR_MOSAIC, 1);
            ShowBg(0);
            ShowBg(1);
            gBattlescriptCurrInstr++;
        }
        break;
    }
}

static void sub_804F100(void)
{
    struct StatsArray currentStats;

    sub_81D388C(&gPlayerParty[gBattleStruct->expGetterId], &currentStats);
    sub_81D3640(0xD, gBattleResources->statsBeforeLvlUp, &currentStats, 0xE, 0xD, 0xF);
}

static void sub_804F144(void)
{
    struct StatsArray currentStats;

    sub_81D388C(&gPlayerParty[gBattleStruct->expGetterId], &currentStats);
    sub_81D3784(0xD, &currentStats, 0xE, 0xD, 0xF);
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
    struct TextSubPrinter subPrinter;
    u8 *txtPtr;
    u32 var;

    monLevel = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_LEVEL);
    monGender = GetMonGender(&gPlayerParty[gBattleStruct->expGetterId]);
    GetMonNickname(&gPlayerParty[gBattleStruct->expGetterId], gStringVar4);

    subPrinter.current_text_offset = gStringVar4;
    subPrinter.windowId = 14;
    subPrinter.fontId = 0;
    subPrinter.x = 32;
    subPrinter.y = 0;
    subPrinter.currentX = 32;
    subPrinter.currentY = 0;
    subPrinter.letterSpacing = 0;
    subPrinter.lineSpacing = 0;
    subPrinter.fontColor_l = TEXT_COLOR_TRANSPARENT;
    subPrinter.fontColor_h = TEXT_COLOR_WHITE;
    subPrinter.bgColor = TEXT_COLOR_TRANSPARENT;
    subPrinter.shadowColor = TEXT_COLOR_DARK_GREY;

    AddTextPrinter(&subPrinter, 0xFF, NULL);

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

    subPrinter.y = 10;
    subPrinter.currentY = 10;
    AddTextPrinter(&subPrinter, 0xFF, NULL);

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

#define sDestroy                    data0
#define sSavedLvlUpBoxXPosition     data1

static void PutMonIconOnLvlUpBox(void)
{
    u8 spriteId;
    const u16* iconPal;
    struct SpriteSheet iconSheet;
    struct SpritePalette iconPalSheet;

    u16 species = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_SPECIES);
    u32 personality = GetMonData(&gPlayerParty[gBattleStruct->expGetterId], MON_DATA_PERSONALITY);

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
    if (gBattlePartyID[0] == gBattleStruct->expGetterId)
        return TRUE;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && gBattlePartyID[2] == gBattleStruct->expGetterId)
        return TRUE;

    return FALSE;
}

static void atk6D_reset_sentpokes_value(void)
{
    ResetSentPokesToOpponentValue();
    gBattlescriptCurrInstr++;
}

static void atk6E_set_atk_to_player0(void)
{
    gBankAttacker = GetBankByIdentity(0);
    gBattlescriptCurrInstr++;
}

static void atk6F_set_visible(void)
{
    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
    EmitSpriteInvisibility(0, FALSE);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 2;
}

static void atk70_record_last_used_ability(void)
{
    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
    RecordAbilityBattle(gActiveBank, gLastUsedAbility);
    gBattlescriptCurrInstr += 1; // UB: Should be + 2, one byte for command and one byte for bank argument.
}

void BufferMoveToLearnIntoBattleTextBuff2(void)
{
    PREPARE_MOVE_BUFFER(gBattleTextBuff2, gMoveToLearn);
}

static void atk71_buffer_move_to_learn(void)
{
    BufferMoveToLearnIntoBattleTextBuff2();
    gBattlescriptCurrInstr++;
}

static void atk72_jump_if_can_run_frombattle(void)
{
    if (CanRunFromBattle(gBank1))
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atk73_hp_thresholds(void)
{
    u8 opposingBank;
    s32 result;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
        opposingBank = gActiveBank ^ BIT_SIDE;

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

static void atk74_hp_thresholds2(void)
{
    u8 opposingBank;
    s32 result;
    u8 hpSwitchout;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
        opposingBank = gActiveBank ^ BIT_SIDE;
        hpSwitchout = *(gBattleStruct->hpOnSwitchout + GetBankSide(opposingBank));
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

static void atk75_item_effect_on_opponent(void)
{
    gBankInMenu = gBankAttacker;
    ExecuteTableBasedItemEffect(&gEnemyParty[gBattlePartyID[gBankAttacker]], gLastUsedItem, gBattlePartyID[gBankAttacker], 0, 1);

    gBattlescriptCurrInstr += 1;
}

static void atk76_various(void)
{
    u8 side;
    s32 i;

    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    switch (gBattlescriptCurrInstr[2])
    {
    case VARIOUS_CANCEL_MULTI_TURN_MOVES:
        CancelMultiTurnMoves(gActiveBank);
        break;
    case VARIOUS_SET_MAGIC_COAT_TARGET:
        gBankAttacker = gBankTarget;
        side = GetBankSide(gBankAttacker) ^ 1;
        if (gSideTimers[side].followmeTimer != 0 && gBattleMons[gSideTimers[side].followmeTarget].hp != 0)
            gBankTarget = gSideTimers[side].followmeTarget;
        else
            gBankTarget = gActiveBank;
        break;
    case 2:
        gBattleCommunication[0] = IsRunningFromBattleImpossible();
        break;
    case VARIOUS_GET_MOVE_TARGET:
        gBankTarget = GetMoveTarget(gCurrentMove, 0);
        break;
    case 4:
        if (gHitMarker & HITMARKER_FAINTED(gActiveBank))
            gBattleCommunication[0] = 1;
        else
            gBattleCommunication[0] = 0;
        break;
    case VARIOUS_RESET_INTIMIDATE_TRACE_BITS:
        gSpecialStatuses[gActiveBank].intimidatedPoke = 0;
        gSpecialStatuses[gActiveBank].traced = 0;
        break;
    case VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP:
        if (gBattlePartyID[0] == gBattleStruct->expGetterId || gBattlePartyID[2] == gBattleStruct->expGetterId)
        {
            u16 *choicedMove;

            if (gBattlePartyID[0] == gBattleStruct->expGetterId)
                gActiveBank = 0;
            else
                gActiveBank = 2;

            choicedMove = &gBattleStruct->choicedMove[gActiveBank];

            for (i = 0; i < 4; i++)
            {
                if (gBattleMons[gActiveBank].moves[i] == *choicedMove)
                    break;
            }
            if (i == 4)
                *choicedMove = 0;
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
        gBattleScripting.bank = gActiveBank = gBattleCommunication[1];
        if (!(gBattleStruct->field_92 & gBitTable[gActiveBank])
            && gBattleMons[gActiveBank].maxHP / 2 >= gBattleMons[gActiveBank].hp
            && gBattleMons[gActiveBank].hp != 0
            && !(gBattleMons[gActiveBank].status1 & STATUS_SLEEP))
        {
            gBattleStruct->field_92 |= gBitTable[gActiveBank];
            gBattleCommunication[0] = 1;
            gBattleCommunication[MULTISTRING_CHOOSER] = sUnknown_0831C4F8[GetNatureFromPersonality(gBattleMons[gActiveBank].personality)];
        }
        break;
    case 9:
        i = sub_81A5258(gBattleCommunication);
        if (i == 0)
            return;

        gBattleCommunication[1] = i;
        break;
    case 10:
        gBattleMons[1].hp = 0;
        gHitMarker |= HITMARKER_FAINTED(1);
        gBattleStruct->field_2A1 |= gBitTable[gBattlePartyID[1]];
        gDisableStructs[1].truantUnknownBit = 1;
        break;
    case 11:
        gBattleMons[0].hp = 0;
        gHitMarker |= HITMARKER_FAINTED(0);
        gHitMarker |= HITMARKER_x400000;
        gBattleStruct->field_2A0 |= gBitTable[gBattlePartyID[0]];
        gDisableStructs[0].truantUnknownBit = 1;
        break;
    case 12:
        gBattleMons[0].hp = 0;
        gBattleMons[1].hp = 0;
        gHitMarker |= HITMARKER_FAINTED(0);
        gHitMarker |= HITMARKER_FAINTED(1);
        gHitMarker |= HITMARKER_x400000;
        gBattleStruct->field_2A0 |= gBitTable[gBattlePartyID[0]];
        gBattleStruct->field_2A1 |= gBitTable[gBattlePartyID[1]];
        gDisableStructs[0].truantUnknownBit = 1;
        gDisableStructs[1].truantUnknownBit = 1;
        break;
    case 13:
        EmitCmd13(0);
        MarkBufferBankForExecution(gActiveBank);
        break;
    case 14:
        sub_81A5BF8();
        break;
    case 15:
        sub_81A5D44();
        break;
    case 16:
        BattleStringExpandPlaceholdersToDisplayedString(gRefereeStringsTable[gBattlescriptCurrInstr[1]]);
        sub_814F9EC(gDisplayedStringBattle, 0x16);
        break;
    case 17:
        if (IsTextPrinterActive(0x16))
            return;
        break;
    case VARIOUS_WAIT_CRY:
        if (!IsCryFinished())
            return;
        break;
    case VARIOUS_RETURN_OPPONENT_MON1:
        gActiveBank = 1;
        if (gBattleMons[gActiveBank].hp != 0)
        {
            EmitReturnPokeToBall(0, 0);
            MarkBufferBankForExecution(gActiveBank);
        }
        break;
    case VARIOUS_RETURN_OPPONENT_MON2:
        if (gNoOfAllBanks > 3)
        {
            gActiveBank = 3;
            if (gBattleMons[gActiveBank].hp != 0)
            {
                EmitReturnPokeToBall(0, 0);
                MarkBufferBankForExecution(gActiveBank);
            }
        }
        break;
    case 21:
        m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x55);
        break;
    case 22:
        m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
        break;
    case 23:
        gBattleStruct->field_2A2 |= gBitTable[gActiveBank];
        break;
    case 24:
        if (sub_805725C(gActiveBank))
            return;
        break;
    case VARIOUS_SET_TELEPORT_OUTCOME:
        if (GetBankSide(gActiveBank) == SIDE_PLAYER)
            gBattleOutcome = BATTLE_PLAYER_TELEPORTED;
        else
            gBattleOutcome = BATTLE_OPPONENT_TELEPORTED;
        break;
    case VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC:
        EmitPlaySound(0, 0x19C, 1);
        MarkBufferBankForExecution(gActiveBank);
        break;
    }

    gBattlescriptCurrInstr += 3;
}

static void atk77_set_protect_like(void) // protect and endure
{
    bool8 notLastTurn = TRUE;
    u16 lastMove = gUnknown_02024260[gBankAttacker];

    if (lastMove != MOVE_PROTECT && lastMove != MOVE_DETECT && lastMove != MOVE_ENDURE)
        gDisableStructs[gBankAttacker].protectUses = 0;

    if (gCurrentMoveTurn == (gNoOfAllBanks - 1))
        notLastTurn = FALSE;

    if (sProtectSuccessRates[gDisableStructs[gBankAttacker].protectUses] >= Random() && notLastTurn)
    {
        if (gBattleMoves[gCurrentMove].effect == EFFECT_PROTECT)
        {
            gProtectStructs[gBankAttacker].protected = 1;
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        }
        if (gBattleMoves[gCurrentMove].effect == EFFECT_ENDURE)
        {
            gProtectStructs[gBankAttacker].endured = 1;
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        }
        gDisableStructs[gBankAttacker].protectUses++;
    }
    else
    {
        gDisableStructs[gBankAttacker].protectUses = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        gBattleMoveFlags |= MOVESTATUS_MISSED;
    }

    gBattlescriptCurrInstr++;
}

static void atk78_faintifabilitynotdamp(void)
{
    if (gBattleExecBuffer)
        return;

    for (gBankTarget = 0; gBankTarget < gNoOfAllBanks; gBankTarget++)
    {
        if (gBattleMons[gBankTarget].ability == ABILITY_DAMP)
            break;
    }

    if (gBankTarget == gNoOfAllBanks)
    {
        gActiveBank = gBankAttacker;
        gBattleMoveDamage = gBattleMons[gActiveBank].hp;
        EmitHealthBarUpdate(0, 0x7FFF);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr++;

        for (gBankTarget = 0; gBankTarget < gNoOfAllBanks; gBankTarget++)
        {
            if (gBankTarget == gBankAttacker)
                continue;
            if (!(gAbsentBankFlags & gBitTable[gBankTarget]))
                break;
        }
    }
    else
    {
        gLastUsedAbility = ABILITY_DAMP;
        RecordAbilityBattle(gBankTarget, gBattleMons[gBankTarget].ability);
        gBattlescriptCurrInstr = BattleScript_DampStopsExplosion;
    }
}

static void atk79_setatkhptozero(void)
{
    if (gBattleExecBuffer)
        return;

    gActiveBank = gBankAttacker;
    gBattleMons[gActiveBank].hp = 0;
    EmitSetMonData(0, REQUEST_HP_BATTLE, 0, 2, &gBattleMons[gActiveBank].hp);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr++;
}

static void atk7A_jumpwhiletargetvalid(void) // Used by intimidate to loop through all targets.
{
    const u8* jumpPtr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        for (gBankTarget++; ; gBankTarget++)
        {
            if (gBankTarget == gBankAttacker)
                continue;
            if (!(gAbsentBankFlags & gBitTable[gBankTarget]))
                break;
        }

        if (gBankTarget >= gNoOfAllBanks)
            gBattlescriptCurrInstr += 5;
        else
            gBattlescriptCurrInstr = jumpPtr;
    }
    else
        gBattlescriptCurrInstr += 5;
}

static void atk7B_healhalfHP_if_possible(void)
{
    const u8* failPtr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);

    if (gBattlescriptCurrInstr[5] == BS_GET_ATTACKER)
        gBankTarget = gBankAttacker;

    gBattleMoveDamage = gBattleMons[gBankTarget].maxHP / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;
    gBattleMoveDamage *= -1;

    if (gBattleMons[gBankTarget].hp == gBattleMons[gBankTarget].maxHP)
        gBattlescriptCurrInstr = failPtr;
    else
        gBattlescriptCurrInstr += 6;
}

static void atk7C_trymirrormove(void)
{
    s32 validMovesCount;
    s32 i;
    u16 move;
    u16 movesArray[4];

    for (i = 0; i < 3; i++)
        movesArray[i] = 0;

    for (validMovesCount = 0, i = 0; i < gNoOfAllBanks; i++)
    {
        if (i != gBankAttacker)
        {
            move = *(i * 2 + gBankAttacker * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 0)
                | (*(i * 2 + gBankAttacker * 8 + (u8*)(gBattleStruct->mirrorMoveArrays) + 1) << 8);

            if (move != 0 && move != 0xFFFF)
            {
                movesArray[validMovesCount] = move;
                validMovesCount++;
            }
        }
    }

    move = *(gBattleStruct->mirrorMoves + gBankAttacker * 2 + 0)
        | (*(gBattleStruct->mirrorMoves + gBankAttacker * 2 + 1) << 8);

    if (move != 0 && move != 0xFFFF)
    {
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gCurrentMove = move;
        gBankTarget = GetMoveTarget(gCurrentMove, 0);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }
    else if (validMovesCount)
    {
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        i = Random() % validMovesCount;
        gCurrentMove = movesArray[i];
        gBankTarget = GetMoveTarget(gCurrentMove, 0);
        gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    }
    else
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
        gBattlescriptCurrInstr++;
    }
}

static void atk7D_set_rain(void)
{
    if (gBattleWeather & WEATHER_RAIN_ANY)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleWeather = WEATHER_RAIN_TEMPORARY;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        gWishFutureKnock.weatherDuration = 5;
    }
    gBattlescriptCurrInstr++;
}

static void atk7E_setreflect(void)
{
    if (gSideAffecting[GET_BANK_SIDE(gBankAttacker)] & SIDE_STATUS_REFLECT)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gSideAffecting[GET_BANK_SIDE(gBankAttacker)] |= SIDE_STATUS_REFLECT;
        gSideTimers[GET_BANK_SIDE(gBankAttacker)].reflectTimer = 5;
        gSideTimers[GET_BANK_SIDE(gBankAttacker)].reflectBank = gBankAttacker;

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMonsInBattle(BATTLE_ALIVE_ATK_SIDE) == 2)
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    gBattlescriptCurrInstr++;
}

static void atk7F_setseeded(void)
{
    if (gBattleMoveFlags & MOVESTATUS_NOEFFECT || gStatuses3[gBankTarget] & STATUS3_LEECHSEED)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else if (gBattleMons[gBankTarget].type1 == TYPE_GRASS || gBattleMons[gBankTarget].type2 == TYPE_GRASS)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gStatuses3[gBankTarget] |= gBankAttacker;
        gStatuses3[gBankTarget] |= STATUS3_LEECHSEED;
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
        if ((gBattleMons[gBankTarget].maxHP / 2) < gBattleMoveDamage)
            gBattleMoveDamage = gBattleMons[gBankTarget].maxHP / 2;
        break;
    case ATK80_DMG_DOUBLED:
        gBattleMoveDamage *= 2;
        break;
    }

    gBattlescriptCurrInstr += 2;
}

static void atk81_setrest(void)
{
    const u8* failJump = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    gActiveBank = gBankTarget = gBankAttacker;
    gBattleMoveDamage = gBattleMons[gBankTarget].maxHP * (-1);

    if (gBattleMons[gBankTarget].hp == gBattleMons[gBankTarget].maxHP)
    {
        gBattlescriptCurrInstr = failJump;
    }
    else
    {
        if (gBattleMons[gBankTarget].status1 & ((u8)(~STATUS_SLEEP)))
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;

        gBattleMons[gBankTarget].status1 = 3;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr += 5;
    }
}

static void atk82_jumpifnotfirstturn(void)
{
    const u8* failJump = BSScriptReadPtr(gBattlescriptCurrInstr + 1);

    if (gDisableStructs[gBankAttacker].isFirstTurn)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = failJump;
}

static void atk83_nop(void)
{
    gBattlescriptCurrInstr++;
}

bool8 UproarWakeUpCheck(u8 bank)
{
    s32 i;

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (!(gBattleMons[i].status2 & STATUS2_UPROAR) || gBattleMons[bank].ability == ABILITY_SOUNDPROOF)
            continue;

        gBattleScripting.bank = i;

        if (gBankTarget == 0xFF)
            gBankTarget = i;
        else if (gBankTarget == i)
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;

        break;
    }

    if (i == gNoOfAllBanks)
        return FALSE;
    else
        return TRUE;
}

static void atk84_jump_if_cant_sleep(void)
{
    const u8* jumpPtr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);

    if (UproarWakeUpCheck(gBankTarget))
    {
        gBattlescriptCurrInstr = jumpPtr;
    }
    else if (gBattleMons[gBankTarget].ability == ABILITY_INSOMNIA
            || gBattleMons[gBankTarget].ability == ABILITY_VITAL_SPIRIT)
    {
        gLastUsedAbility = gBattleMons[gBankTarget].ability;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        gBattlescriptCurrInstr = jumpPtr;
        RecordAbilityBattle(gBankTarget, gLastUsedAbility);
    }
    else
    {
        gBattlescriptCurrInstr += 5;
    }
}

static void atk85_stockpile(void)
{
    if (gDisableStructs[gBankAttacker].stockpileCounter == 3)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gDisableStructs[gBankAttacker].stockpileCounter++;

        PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 1, gDisableStructs[gBankAttacker].stockpileCounter)

        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    gBattlescriptCurrInstr++;
}

static void atk86_stockpiletobasedamage(void)
{
    const u8* jumpPtr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    if (gDisableStructs[gBankAttacker].stockpileCounter == 0)
    {
        gBattlescriptCurrInstr = jumpPtr;
    }
    else
    {
        if (gBattleCommunication[6] != 1)
        {
            gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBankAttacker], &gBattleMons[gBankTarget], gCurrentMove,
                                                    gSideAffecting[GET_BANK_SIDE(gBankTarget)], 0,
                                                    0, gBankAttacker, gBankTarget)
                                * gDisableStructs[gBankAttacker].stockpileCounter;
            gBattleScripting.animTurn = gDisableStructs[gBankAttacker].stockpileCounter;

            if (gProtectStructs[gBankAttacker].helpingHand)
                gBattleMoveDamage = gBattleMoveDamage * 15 / 10;
        }

        gDisableStructs[gBankAttacker].stockpileCounter = 0;
        gBattlescriptCurrInstr += 5;
    }
}

static void atk87_stockpiletohpheal(void)
{
    const u8* jumpPtr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);

    if (gDisableStructs[gBankAttacker].stockpileCounter == 0)
    {
        gBattlescriptCurrInstr = jumpPtr;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else if (gBattleMons[gBankAttacker].maxHP == gBattleMons[gBankAttacker].hp)
    {
        gDisableStructs[gBankAttacker].stockpileCounter = 0;
        gBattlescriptCurrInstr = jumpPtr;
        gBankTarget = gBankAttacker;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / (1 << (3 - gDisableStructs[gBankAttacker].stockpileCounter));

        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        gBattleScripting.animTurn = gDisableStructs[gBankAttacker].stockpileCounter;
        gDisableStructs[gBankAttacker].stockpileCounter = 0;
        gBattlescriptCurrInstr += 5;
        gBankTarget = gBankAttacker;
    }
}

static void atk88_negativedamage(void)
{
    gBattleMoveDamage = -(gHpDealt / 2);
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = -1;

    gBattlescriptCurrInstr++;
}

static u8 ChangeStatBuffs(s8 statValue, u8 statId, u8 flags, const u8* BS_ptr)
{
    bool8 certain = 0;
    bool8 notProtectAffected = FALSE;
    u32 index;

    if (flags & MOVE_EFFECT_AFFECTS_USER)
        gActiveBank = gBankAttacker;
    else
        gActiveBank = gBankTarget;

    flags &= ~(MOVE_EFFECT_AFFECTS_USER);

    if (flags & MOVE_EFFECT_CERTAIN)
        certain++;
    flags &= ~(MOVE_EFFECT_CERTAIN);

    if (flags & STAT_CHANGE_NOT_PROTECT_AFFECTED)
        notProtectAffected++;
    flags &= ~(STAT_CHANGE_NOT_PROTECT_AFFECTED);

    PREPARE_STAT_BUFFER(gBattleTextBuff1, statId)

    if ((statValue << 0x18) < 0) // stat decrease
    {
        if (gSideTimers[GET_BANK_SIDE(gActiveBank)].mistTimer
            && !certain && gCurrentMove != MOVE_CURSE)
        {
            if (flags == STAT_CHANGE_BS_PTR)
            {
                if (gSpecialStatuses[gActiveBank].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleScripting.bank = gActiveBank;
                    gBattlescriptCurrInstr = BattleScript_MistProtected;
                    gSpecialStatuses[gActiveBank].statLowered = 1;
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
        else if ((gBattleMons[gActiveBank].ability == ABILITY_CLEAR_BODY
                  || gBattleMons[gActiveBank].ability == ABILITY_WHITE_SMOKE)
                 && !certain && gCurrentMove != MOVE_CURSE)
        {
            if (flags == STAT_CHANGE_BS_PTR)
            {
                if (gSpecialStatuses[gActiveBank].statLowered)
                {
                    gBattlescriptCurrInstr = BS_ptr;
                }
                else
                {
                    BattleScriptPush(BS_ptr);
                    gBattleScripting.bank = gActiveBank;
                    gBattlescriptCurrInstr = BattleScript_AbilityNoStatLoss;
                    gLastUsedAbility = gBattleMons[gActiveBank].ability;
                    RecordAbilityBattle(gActiveBank, gLastUsedAbility);
                    gSpecialStatuses[gActiveBank].statLowered = 1;
                }
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (gBattleMons[gActiveBank].ability == ABILITY_KEEN_EYE
                 && !certain && statId == STAT_STAGE_ACC)
        {
            if (flags == STAT_CHANGE_BS_PTR)
            {
                BattleScriptPush(BS_ptr);
                gBattleScripting.bank = gActiveBank;
                gBattlescriptCurrInstr = BattleScript_AbilityNoSpecificStatLoss;
                gLastUsedAbility = gBattleMons[gActiveBank].ability;
                RecordAbilityBattle(gActiveBank, gLastUsedAbility);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (gBattleMons[gActiveBank].ability == ABILITY_HYPER_CUTTER
                 && !certain && statId == STAT_STAGE_ATK)
        {
            if (flags == STAT_CHANGE_BS_PTR)
            {
                BattleScriptPush(BS_ptr);
                gBattleScripting.bank = gActiveBank;
                gBattlescriptCurrInstr = BattleScript_AbilityNoSpecificStatLoss;
                gLastUsedAbility = gBattleMons[gActiveBank].ability;
                RecordAbilityBattle(gActiveBank, gLastUsedAbility);
            }
            return STAT_CHANGE_DIDNT_WORK;
        }
        else if (gBattleMons[gActiveBank].ability == ABILITY_SHIELD_DUST && flags == 0)
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
                gBattleTextBuff2[2] = 0xD3; // harshly
                gBattleTextBuff2[3] = 0xD3 >> 8;
                index = 4;
            }
            gBattleTextBuff2[index] = B_BUFF_STRING;
            index++;
            gBattleTextBuff2[index] = 0xD4; // fell
            index++;
            gBattleTextBuff2[index] = 0xD4 >> 8;
            index++;
            gBattleTextBuff2[index] = B_BUFF_EOS;

            if (gBattleMons[gActiveBank].statStages[statId] == 0)
                gBattleCommunication[MULTISTRING_CHOOSER] = 2;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = (gBankTarget == gActiveBank);

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
            gBattleTextBuff2[2] = 0xD1; // sharply
            gBattleTextBuff2[3] = 0xD1 >> 8;
            index = 4;
        }
        gBattleTextBuff2[index] = B_BUFF_STRING;
        index++;
        gBattleTextBuff2[index] = 0xD2; // rose
        index++;
        gBattleTextBuff2[index] = 0xD2 >> 8;
        index++;
        gBattleTextBuff2[index] = B_BUFF_EOS;

        if (gBattleMons[gActiveBank].statStages[statId] == 0xC)
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = (gBankTarget == gActiveBank);
    }

    gBattleMons[gActiveBank].statStages[statId] += statValue;
    if (gBattleMons[gActiveBank].statStages[statId] < 0)
        gBattleMons[gActiveBank].statStages[statId] = 0;
    if (gBattleMons[gActiveBank].statStages[statId] > 0xC)
        gBattleMons[gActiveBank].statStages[statId] = 0xC;

    if (gBattleCommunication[MULTISTRING_CHOOSER] == 2 && flags & STAT_CHANGE_BS_PTR)
        gBattleMoveFlags |= MOVESTATUS_MISSED;

    if (gBattleCommunication[MULTISTRING_CHOOSER] == 2 && !(flags & STAT_CHANGE_BS_PTR))
        return STAT_CHANGE_DIDNT_WORK;

    return STAT_CHANGE_WORKED;
}

static void atk89_statbuffchange(void)
{
    const u8* jumpPtr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
    if (ChangeStatBuffs(gBattleScripting.statChanger & 0xF0, GET_STAT_BUFF_ID(gBattleScripting.statChanger), gBattlescriptCurrInstr[1], jumpPtr) == STAT_CHANGE_WORKED)
        gBattlescriptCurrInstr += 6;
}

static void atk8A_normalisebuffs(void) // haze
{
    s32 i, j;

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        for (j = 0; j < BATTLE_STATS_NO; j++)
            gBattleMons[i].statStages[j] = 6;
    }

    gBattlescriptCurrInstr++;
}

static void atk8B_setbide(void)
{
    gBattleMons[gBankAttacker].status2 |= STATUS2_MULTIPLETURNS;
    gLockedMoves[gBankAttacker] = gCurrentMove;
    gTakenDmg[gBankAttacker] = 0;
    gBattleMons[gBankAttacker].status2 |= (STATUS2_BIDE - 0x100); // 2 turns

    gBattlescriptCurrInstr++;
}

static void atk8C_confuseifrepeatingattackends(void)
{
    if (!(gBattleMons[gBankAttacker].status2 & STATUS2_LOCK_CONFUSE))
        gBattleCommunication[MOVE_EFFECT_BYTE] = (MOVE_EFFECT_THRASH | MOVE_EFFECT_AFFECTS_USER);

    gBattlescriptCurrInstr++;
}

static void atk8D_setmultihit_counter(void)
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
    }

    gBattlescriptCurrInstr += 2;
}

static void atk8E_init_multihit_string(void)
{
    PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)

    gBattlescriptCurrInstr++;
}

static bool8 sub_8051064(void)
{
    if (gBattleMons[gBankAttacker].level >= gBattleMons[gBankTarget].level)
    {
        *(gBattleStruct->field_58 + gBankTarget) = gBattlePartyID[gBankTarget];
    }
    else
    {
        u16 random = Random() & 0xFF;
        if ((u32)((random * (gBattleMons[gBankAttacker].level + gBattleMons[gBankTarget].level) >> 8) + 1) <= (gBattleMons[gBankTarget].level / 4))
        {
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
            return FALSE;
        }
        *(gBattleStruct->field_58 + gBankTarget) = gBattlePartyID[gBankTarget];
    }

    gBattlescriptCurrInstr = gUnknown_082DADD8;
    return TRUE;
}

static void atk8F_forcerandomswitch(void)
{
    s32 i;
    s32 bank1PartyId = 0;
    s32 bank2PartyId = 0;

    #ifdef NONMATCHING
        s32 lastMonId = 0; // + 1
    #else
        register s32 lastMonId asm("r8") = 0; // + 1
    #endif // NONMATCHING

    s32 firstMonId = 0;
    s32 monsCount = 0;
    struct Pokemon* party = NULL;
    s32 validMons = 0;
    s32 minNeeded = 0;

    if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER))
    {
        if (GetBankSide(gBankTarget) == SIDE_PLAYER)
            party = gPlayerParty;
        else
            party = gEnemyParty;

        if ((gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER && gBattleTypeFlags & BATTLE_TYPE_LINK)
            || (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER && gBattleTypeFlags & BATTLE_TYPE_x2000000)
            || (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
        {
            if ((gBankTarget & BIT_MON) != 0)
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
            bank2PartyId = gBattlePartyID[gBankTarget];
            bank1PartyId = gBattlePartyID[gBankTarget ^ BIT_MON];
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_LINK)
                 || (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_x2000000))
        {
            if (sub_806D82C(sub_806D864(gBankTarget)) == 1)
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
            bank2PartyId = gBattlePartyID[gBankTarget];
            bank1PartyId = gBattlePartyID[gBankTarget ^ BIT_MON];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (GetBankSide(gBankTarget) == SIDE_PLAYER)
            {
                firstMonId = 0;
                lastMonId = 6;
                monsCount = 6;
                minNeeded = 2; // since there are two opponents, it has to be a double battle
            }
            else
            {
                if ((gBankTarget & BIT_MON) != 0)
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
            bank2PartyId = gBattlePartyID[gBankTarget];
            bank1PartyId = gBattlePartyID[gBankTarget ^ BIT_MON];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            firstMonId = 0;
            lastMonId = 6;
            monsCount = 6;
            minNeeded = 2;
            bank2PartyId = gBattlePartyID[gBankTarget];
            bank1PartyId = gBattlePartyID[gBankTarget ^ BIT_MON];
        }
        else
        {
            firstMonId = 0;
            lastMonId = 6;
            monsCount = 6;
            minNeeded = 1;
            bank2PartyId = gBattlePartyID[gBankTarget]; // there is only one pokemon out in single battles
            bank1PartyId = gBattlePartyID[gBankTarget];
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
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        }
        else
        {
            if (sub_8051064())
            {
                do
                {
                    i = Random() % monsCount;
                    i += firstMonId;
                }
                while (i == bank2PartyId
                       || i == bank1PartyId
                       || GetMonData(&party[i], MON_DATA_SPECIES) == SPECIES_NONE
                       || GetMonData(&party[i], MON_DATA_IS_EGG) == TRUE
                       || GetMonData(&party[i], MON_DATA_HP) == 0);
            }
            *(gBattleStruct->field_5C + gBankTarget) = i;

            if (!sub_81B1250())
                sub_803BDA0(gBankTarget);

            if ((gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                || (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI)
                || (gBattleTypeFlags & BATTLE_TYPE_x2000000 && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                || (gBattleTypeFlags & BATTLE_TYPE_x2000000 && gBattleTypeFlags & BATTLE_TYPE_MULTI))
            {
                sub_81B8E80(gBankTarget, i, 0);
                sub_81B8E80(gBankTarget ^ BIT_MON, i, 1);
            }

            if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                sub_80571DC(gBankTarget, i);
        }
    }
    else
    {
        sub_8051064();
    }
}

static void atk90_conversion_type_change(void) // randomly changes user's type to one of its moves' type
{
    u8 validMoves = 0;
    u8 moveChecked;
    u8 moveType;

    while (validMoves < 4)
    {
        if (gBattleMons[gBankAttacker].moves[validMoves] == 0)
            break;

        validMoves++;
    }

    for (moveChecked = 0; moveChecked < validMoves; moveChecked++)
    {
        moveType = gBattleMoves[gBattleMons[gBankAttacker].moves[moveChecked]].type;

        if (moveType == TYPE_MYSTERY)
        {
            if (gBattleMons[gBankAttacker].type1 == TYPE_GHOST || gBattleMons[gBankAttacker].type2 == TYPE_GHOST)
                moveType = TYPE_GHOST;
            else
                moveType = TYPE_NORMAL;
        }
        if (moveType != gBattleMons[gBankAttacker].type1
            && moveType != gBattleMons[gBankAttacker].type2)
        {
            break;
        }
    }

    if (moveChecked == validMoves)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        do
        {

            while ((moveChecked = Random() & 3) >= validMoves);

            moveType = gBattleMoves[gBattleMons[gBankAttacker].moves[moveChecked]].type;

            if (moveType == TYPE_MYSTERY)
            {
                if (gBattleMons[gBankAttacker].type1 == TYPE_GHOST || gBattleMons[gBankAttacker].type2 == TYPE_GHOST)
                    moveType = TYPE_GHOST;
                else
                    moveType = TYPE_NORMAL;
            }
        }
        while (moveType == gBattleMons[gBankAttacker].type1 || moveType == gBattleMons[gBankAttacker].type2);

        gBattleMons[gBankAttacker].type1 = moveType;
        gBattleMons[gBankAttacker].type2 = moveType;

        PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType)

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
    if (gSideAffecting[GET_BANK_SIDE(gBankAttacker)] & SIDE_STATUS_LIGHTSCREEN)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gSideAffecting[GET_BANK_SIDE(gBankAttacker)] |= SIDE_STATUS_LIGHTSCREEN;
        gSideTimers[GET_BANK_SIDE(gBankAttacker)].lightscreenTimer = 5;
        gSideTimers[GET_BANK_SIDE(gBankAttacker)].lightscreenBank = gBankAttacker;

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && CountAliveMonsInBattle(BATTLE_ALIVE_ATK_SIDE) == 2)
            gBattleCommunication[MULTISTRING_CHOOSER] = 4;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 3;
    }

    gBattlescriptCurrInstr++;
}

static void atk93_ko_move(void)
{
    u8 holdEffect, param;

    if (gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY)
    {
       holdEffect = gEnigmaBerries[gBankTarget].holdEffect;
       param = gEnigmaBerries[gBankTarget].holdEffectParam;
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(gBattleMons[gBankTarget].item);
        param = ItemId_GetHoldEffectParam(gBattleMons[gBankTarget].item);
    }

    gStringBank = gBankTarget;

    if (holdEffect == HOLD_EFFECT_FOCUS_BAND && (Random() % 100) < param)
    {
        RecordItemEffectBattle(gBankTarget, HOLD_EFFECT_FOCUS_BAND);
        gSpecialStatuses[gBankTarget].focusBanded = 1;
    }

    if (gBattleMons[gBankTarget].ability == ABILITY_STURDY)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gLastUsedAbility = ABILITY_STURDY;
        gBattlescriptCurrInstr = BattleScript_SturdyPreventsOHKO;
        RecordAbilityBattle(gBankTarget, ABILITY_STURDY);
    }
    else
    {
        u16 chance;
        if (!(gStatuses3[gBankTarget] & STATUS3_ALWAYS_HITS))
        {
            chance = gBattleMoves[gCurrentMove].accuracy + (gBattleMons[gBankAttacker].level - gBattleMons[gBankTarget].level);
            if (Random() % 100 + 1 < chance && gBattleMons[gBankAttacker].level >= gBattleMons[gBankTarget].level)
                chance = TRUE;
            else
                chance = FALSE;
        }
        else if (gDisableStructs[gBankTarget].bankWithSureHit == gBankAttacker
                 && gBattleMons[gBankAttacker].level >= gBattleMons[gBankTarget].level)
        {
            chance = TRUE;
        }
        else
        {
            chance = gBattleMoves[gCurrentMove].accuracy + (gBattleMons[gBankAttacker].level - gBattleMons[gBankTarget].level);
            if (Random() % 100 + 1 < chance && gBattleMons[gBankAttacker].level >= gBattleMons[gBankTarget].level)
                chance = TRUE;
            else
                chance = FALSE;
        }
        if (chance)
        {
            if (gProtectStructs[gBankTarget].endured)
            {
                gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;
                gBattleMoveFlags |= MOVESTATUS_ENDURED;
            }
            else if (gSpecialStatuses[gBankTarget].focusBanded)
            {
                gBattleMoveDamage = gBattleMons[gBankTarget].hp - 1;
                gBattleMoveFlags |= MOVESTATUS_HUNGON;
                gLastUsedItem = gBattleMons[gBankTarget].item;
            }
            else
            {
                gBattleMoveDamage = gBattleMons[gBankTarget].hp;
                gBattleMoveFlags |= MOVESTATUS_ONEHITKO;
            }
            gBattlescriptCurrInstr += 5;
        }
        else
        {
            gBattleMoveFlags |= MOVESTATUS_MISSED;
            if (gBattleMons[gBankAttacker].level >= gBattleMons[gBankTarget].level)
                gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        }
    }
}

static void atk94_damagetohalftargethp(void) // super fang
{
    gBattleMoveDamage = gBattleMons[gBankTarget].hp / 2;
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    gBattlescriptCurrInstr++;
}

static void atk95_setsandstorm(void)
{
    if (gBattleWeather & WEATHER_SANDSTORM_ANY)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleWeather = WEATHER_SANDSTORM_TEMPORARY;
        gBattleCommunication[MULTISTRING_CHOOSER] = 3;
        gWishFutureKnock.weatherDuration = 5;
    }
    gBattlescriptCurrInstr++;
}

static void atk96_weatherdamage(void)
{
    if (WEATHER_HAS_EFFECT)
    {
        if (gBattleWeather & WEATHER_SANDSTORM_ANY)
        {
            if (gBattleMons[gBankAttacker].type1 != TYPE_ROCK
                && gBattleMons[gBankAttacker].type1 != TYPE_STEEL
                && gBattleMons[gBankAttacker].type1 != TYPE_GROUND
                && gBattleMons[gBankAttacker].type2 != TYPE_ROCK
                && gBattleMons[gBankAttacker].type2 != TYPE_STEEL
                && gBattleMons[gBankAttacker].type2 != TYPE_GROUND
                && gBattleMons[gBankAttacker].ability != ABILITY_SAND_VEIL
                && !(gStatuses3[gBankAttacker] & STATUS3_UNDERGROUND)
                && !(gStatuses3[gBankAttacker] & STATUS3_UNDERWATER))
            {
                gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 16;
                if (gBattleMoveDamage == 0)
                    gBattleMoveDamage = 1;
            }
            else
            {
                gBattleMoveDamage = 0;
            }
        }
        if (gBattleWeather & WEATHER_HAIL)
        {
            if (gBattleMons[gBankAttacker].type1 != TYPE_ICE
                && gBattleMons[gBankAttacker].type2 != TYPE_ICE
                && !(gStatuses3[gBankAttacker] & STATUS3_UNDERGROUND)
                && !(gStatuses3[gBankAttacker] & STATUS3_UNDERWATER))
            {
                gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 16;
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

    if (gAbsentBankFlags & gBitTable[gBankAttacker])
        gBattleMoveDamage = 0;

    gBattlescriptCurrInstr++;
}

static void atk97_try_infatuation(void)
{
    struct Pokemon *monAttacker, *monTarget;
    u16 speciesAttacker, speciesTarget;
    u32 personalityAttacker, personalityTarget;

    if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
        monAttacker = &gPlayerParty[gBattlePartyID[gBankAttacker]];
    else
        monAttacker = &gEnemyParty[gBattlePartyID[gBankAttacker]];

    if (GetBankSide(gBankTarget) == SIDE_PLAYER)
        monTarget = &gPlayerParty[gBattlePartyID[gBankTarget]];
    else
        monTarget = &gEnemyParty[gBattlePartyID[gBankTarget]];

    speciesAttacker = GetMonData(monAttacker, MON_DATA_SPECIES);
    personalityAttacker = GetMonData(monAttacker, MON_DATA_PERSONALITY);

    speciesTarget = GetMonData(monTarget, MON_DATA_SPECIES);
    personalityTarget = GetMonData(monTarget, MON_DATA_PERSONALITY);

    if (gBattleMons[gBankTarget].ability == ABILITY_OBLIVIOUS)
    {
        gBattlescriptCurrInstr = BattleScript_ObliviousPreventsAttraction;
        gLastUsedAbility = ABILITY_OBLIVIOUS;
        RecordAbilityBattle(gBankTarget, ABILITY_OBLIVIOUS);
    }
    else
    {
        if (GetGenderFromSpeciesAndPersonality(speciesAttacker, personalityAttacker) == GetGenderFromSpeciesAndPersonality(speciesTarget, personalityTarget)
            || gBattleMons[gBankTarget].status2 & STATUS2_INFATUATION
            || GetGenderFromSpeciesAndPersonality(speciesAttacker, personalityAttacker) == MON_GENDERLESS
            || GetGenderFromSpeciesAndPersonality(speciesTarget, personalityTarget) == MON_GENDERLESS)
        {
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        }
        else
        {
            gBattleMons[gBankTarget].status2 |= STATUS2_INFATUATED_WITH(gBankAttacker);
            gBattlescriptCurrInstr += 5;
        }
    }
}

static void atk98_status_icon_update(void)
{
    if (gBattleExecBuffer)
        return;

    if (gBattlescriptCurrInstr[1] != BS_ATTACKER_WITH_PARTNER)
    {
        gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);
        EmitStatusIconUpdate(0, gBattleMons[gActiveBank].status1, gBattleMons[gActiveBank].status2);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr += 2;
    }
    else
    {
        gActiveBank = gBankAttacker;
        if (!(gAbsentBankFlags & gBitTable[gActiveBank]))
        {
            EmitStatusIconUpdate(0, gBattleMons[gActiveBank].status1, gBattleMons[gActiveBank].status2);
            MarkBufferBankForExecution(gActiveBank);
        }
        if ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        {
            gActiveBank = GetBankByIdentity(GetBankIdentity(gBankAttacker) ^ BIT_MON);
            if (!(gAbsentBankFlags & gBitTable[gActiveBank]))
            {
                EmitStatusIconUpdate(0, gBattleMons[gActiveBank].status1, gBattleMons[gActiveBank].status2);
                MarkBufferBankForExecution(gActiveBank);
            }
        }
        gBattlescriptCurrInstr += 2;
    }
}

static void atk99_setmist(void)
{
    if (gSideTimers[GET_BANK_SIDE(gBankAttacker)].mistTimer)
    {
        gBattleMoveFlags |= MOVESTATUS_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gSideTimers[GET_BANK_SIDE(gBankAttacker)].mistTimer = 5;
        gSideTimers[GET_BANK_SIDE(gBankAttacker)].mistBank = gBankAttacker;
        gSideAffecting[GET_BANK_SIDE(gBankAttacker)] |= SIDE_STATUS_MIST;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    gBattlescriptCurrInstr++;
}

static void atk9A_set_focusenergy(void)
{
    if (gBattleMons[gBankAttacker].status2 & STATUS2_FOCUS_ENERGY)
    {
        gBattleMoveFlags |= MOVESTATUS_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gBattleMons[gBankAttacker].status2 |= STATUS2_FOCUS_ENERGY;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    gBattlescriptCurrInstr++;
}

static void atk9B_transformdataexecution(void)
{
    gLastUsedMove = 0xFFFF;
    gBattlescriptCurrInstr++;
    if (gBattleMons[gBankTarget].status2 & STATUS2_TRANSFORMED
        || gStatuses3[gBankTarget] & STATUS3_SEMI_INVULNERABLE)
    {
        gBattleMoveFlags |= MOVESTATUS_FAILED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        s32 i;
        u8 *battleMonAttacker, *battleMonTarget;

        gBattleMons[gBankAttacker].status2 |= STATUS2_TRANSFORMED;
        gDisableStructs[gBankAttacker].disabledMove = 0;
        gDisableStructs[gBankAttacker].disableTimer1 = 0;
        gDisableStructs[gBankAttacker].unk0 = gBattleMons[gBankTarget].personality;
        gDisableStructs[gBankAttacker].unk18_b = 0;

        PREPARE_SPECIES_BUFFER(gBattleTextBuff1, gBattleMons[gBankTarget].species)

        battleMonAttacker = (u8*)(&gBattleMons[gBankAttacker]);
        battleMonTarget = (u8*)(&gBattleMons[gBankTarget]);

        for (i = 0; i < offsetof(struct BattlePokemon, pp); i++)
            battleMonAttacker[i] = battleMonTarget[i];

        for (i = 0; i < 4; i++)
        {
            if (gBattleMoves[gBattleMons[gBankAttacker].moves[i]].pp < 5)
                gBattleMons[gBankAttacker].pp[i] = gBattleMoves[gBattleMons[gBankAttacker].moves[i]].pp;
            else
                gBattleMons[gBankAttacker].pp[i] = 5;
        }

        gActiveBank = gBankAttacker;
        EmitResetActionMoveSelection(0, RESET_MOVE_SELECTION);
        MarkBufferBankForExecution(gActiveBank);
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
}

static void atk9C_set_substitute(void)
{
    u32 hp = gBattleMons[gBankAttacker].maxHP / 4;
    if (gBattleMons[gBankAttacker].maxHP / 4 == 0)
        hp = 1;

    if (gBattleMons[gBankAttacker].hp <= hp)
    {
        gBattleMoveDamage = 0;
        gBattleCommunication[MULTISTRING_CHOOSER] = 1;
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 4; // one bit value will only work for pokemon which max hp can go to 1020(which is more than possible in games)
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattleMons[gBankAttacker].status2 |= STATUS2_SUBSTITUTE;
        gBattleMons[gBankAttacker].status2 &= ~(STATUS2_WRAPPED);
        gDisableStructs[gBankAttacker].substituteHP = gBattleMoveDamage;
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
    gLastUsedMove = 0xFFFF;

    if (IsMoveUncopyableByMimic(gLastUsedMovesByBanks[gBankTarget])
        || gBattleMons[gBankAttacker].status2 & STATUS2_TRANSFORMED
        || gLastUsedMovesByBanks[gBankTarget] == 0
        || gLastUsedMovesByBanks[gBankTarget] == 0xFFFF)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        s32 i;

        for (i = 0; i < 4; i++)
        {
            if (gBattleMons[gBankAttacker].moves[i] == gLastUsedMovesByBanks[gBankTarget])
                break;
        }

        if (i == 4)
        {
            gBattleMons[gBankAttacker].moves[gCurrMovePos] = gLastUsedMovesByBanks[gBankTarget];
            if (gBattleMoves[gLastUsedMovesByBanks[gBankTarget]].pp < 5)
                gBattleMons[gBankAttacker].pp[gCurrMovePos] = gBattleMoves[gLastUsedMovesByBanks[gBankTarget]].pp;
            else
                gBattleMons[gBankAttacker].pp[gCurrMovePos] = 5;


            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastUsedMovesByBanks[gBankTarget])

            gDisableStructs[gBankAttacker].unk18_b |= gBitTable[gCurrMovePos];
            gBattlescriptCurrInstr += 5;
        }
        else
        {
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        }
    }
}

#ifdef NONMATCHING
static void atk9E_metronome(void)
{
    while (1)
    {
        const u16 *move;
        s32 i, j;

        gCurrentMove = (Random() & 0x1FF) + 1;
        if (gCurrentMove > LAST_MOVE_INDEX)
            continue;

        for (i = 0; i < 4; i++); // ?

        for (move = sMovesForbiddenToCopy; ; move++)
        {
            if (*move == gCurrentMove)
                break;
            if (*move == METRONOME_FORBIDDEN_END)
                break;
        }

        if (*move == METRONOME_FORBIDDEN_END)
            break;
    }

    gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
    gBattlescriptCurrInstr = gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect];
    gBankTarget = GetMoveTarget(gCurrentMove, 0);
}

#else
__attribute__((naked))
static void atk9E_metronome(void)
{
    asm(
    "\n\
    .syntax unified\n\
	push {r4-r7,lr}\n\
	mov r7, r8\n\
	push {r7}\n\
	ldr r7, =gCurrentMove\n\
	movs r6, 0xB1\n\
	lsls r6, 1\n\
	ldr r5, =sMovesForbiddenToCopy\n\
	ldr r0, =gBattlescriptCurrInstr\n\
	mov r8, r0\n\
_080524EE:\n\
	bl Random\n\
	ldr r2, =0x000001ff\n\
	adds r1, r2, 0\n\
	ands r0, r1\n\
	adds r0, 0x1\n\
	strh r0, [r7]\n\
	cmp r0, r6\n\
	bhi _080524EE\n\
	movs r0, 0x3\n\
_08052502:\n\
	subs r0, 0x1\n\
	cmp r0, 0\n\
	bge _08052502\n\
	ldr r4, =gCurrentMove\n\
	ldrh r2, [r4]\n\
	ldr r3, =0x0000ffff\n\
	subs r0, r5, 0x2\n\
_08052510:\n\
	adds r0, 0x2\n\
	ldrh r1, [r0]\n\
	cmp r1, r2\n\
	beq _0805251C\n\
	cmp r1, r3\n\
	bne _08052510\n\
_0805251C:\n\
	ldr r0, =0x0000ffff\n\
	cmp r1, r0\n\
	bne _080524EE\n\
	ldr r2, =gHitMarker\n\
	ldr r0, [r2]\n\
	ldr r1, =0xfffffbff\n\
	ands r0, r1\n\
	str r0, [r2]\n\
	ldr r3, =gBattleScriptsForMoveEffects\n\
	ldr r2, =gBattleMoves\n\
	ldrh r1, [r4]\n\
	lsls r0, r1, 1\n\
	adds r0, r1\n\
	lsls r0, 2\n\
	adds r0, r2\n\
	ldrb r0, [r0]\n\
	lsls r0, 2\n\
	adds r0, r3\n\
	ldr r0, [r0]\n\
	mov r1, r8\n\
	str r0, [r1]\n\
	ldrh r0, [r4]\n\
	movs r1, 0\n\
	bl GetMoveTarget\n\
	ldr r1, =gBankTarget\n\
	strb r0, [r1]\n\
	pop {r3}\n\
	mov r8, r3\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
    .pool\n\
    .syntax divided");
}

#endif // NONMATCHING

static void atk9F_dmgtolevel(void)
{
    gBattleMoveDamage = gBattleMons[gBankAttacker].level;
    gBattlescriptCurrInstr++;
}

static void atkA0_psywavedamageeffect(void)
{
    s32 randDamage;

    while ((randDamage = (Random() & 0xF)) > 10);

    randDamage *= 10;
    gBattleMoveDamage = gBattleMons[gBankAttacker].level * (randDamage + 50) / 100;
    gBattlescriptCurrInstr++;
}

static void atkA1_counterdamagecalculator(void)
{
    u8 sideAttacker = GetBankSide(gBankAttacker);
    u8 sideTarget = GetBankSide(gProtectStructs[gBankAttacker].physicalBank);

    if (gProtectStructs[gBankAttacker].physicalDmg
        && sideAttacker != sideTarget
        && gBattleMons[gProtectStructs[gBankAttacker].physicalBank].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBankAttacker].physicalDmg * 2;

        if (gSideTimers[sideTarget].followmeTimer && gBattleMons[gSideTimers[sideTarget].followmeTarget].hp)
            gBankTarget = gSideTimers[sideTarget].followmeTarget;
        else
            gBankTarget = gProtectStructs[gBankAttacker].physicalBank;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkA2_mirrorcoatdamagecalculator(void) // a copy of atkA1 with the physical -> special field changes
{
    u8 sideAttacker = GetBankSide(gBankAttacker);
    u8 sideTarget = GetBankSide(gProtectStructs[gBankAttacker].specialBank);

    if (gProtectStructs[gBankAttacker].specialDmg && sideAttacker != sideTarget && gBattleMons[gProtectStructs[gBankAttacker].specialBank].hp)
    {
        gBattleMoveDamage = gProtectStructs[gBankAttacker].specialDmg * 2;

        if (gSideTimers[sideTarget].followmeTimer && gBattleMons[gSideTimers[sideTarget].followmeTarget].hp)
            gBankTarget = gSideTimers[sideTarget].followmeTarget;
        else
            gBankTarget = gProtectStructs[gBankAttacker].specialBank;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkA3_disablelastusedattack(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[gBankTarget].moves[i] == gLastUsedMovesByBanks[gBankTarget])
            break;
    }
    if (gDisableStructs[gBankTarget].disabledMove == 0
        && i != 4 && gBattleMons[gBankTarget].pp[i] != 0)
    {
        PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[gBankTarget].moves[i])

        gDisableStructs[gBankTarget].disabledMove = gBattleMons[gBankTarget].moves[i];
        gDisableStructs[gBankTarget].disableTimer1 = (Random() & 3) + 2;
        gDisableStructs[gBankTarget].disableTimer2 = gDisableStructs[gBankTarget].disableTimer1; // used to save the random amount of turns?
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkA4_setencore(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gBattleMons[gBankTarget].moves[i] == gLastUsedMovesByBanks[gBankTarget])
            break;
    }

    if (gLastUsedMovesByBanks[gBankTarget] == MOVE_STRUGGLE
        || gLastUsedMovesByBanks[gBankTarget] == MOVE_ENCORE
        || gLastUsedMovesByBanks[gBankTarget] == MOVE_MIRROR_MOVE)
    {
        i = 4;
    }

    if (gDisableStructs[gBankTarget].encoredMove == 0
        && i != 4 && gBattleMons[gBankTarget].pp[i] != 0)
    {
        gDisableStructs[gBankTarget].encoredMove = gBattleMons[gBankTarget].moves[i];
        gDisableStructs[gBankTarget].encoredMovePos = i;
        gDisableStructs[gBankTarget].encoreTimer1 = (Random() & 3) + 3;
        gDisableStructs[gBankTarget].encoreTimer2 = gDisableStructs[gBankTarget].encoreTimer1;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkA5_painsplitdmgcalc(void)
{
    if (!(gBattleMons[gBankTarget].status2 & STATUS2_SUBSTITUTE))
    {
        s32 hpDiff = (gBattleMons[gBankAttacker].hp + gBattleMons[gBankTarget].hp) / 2;
        s32 painSplitHp = gBattleMoveDamage = gBattleMons[gBankTarget].hp - hpDiff;
        u8* storeLoc = (void*)(&gBattleScripting.painSplitHp);

        storeLoc[0] = (painSplitHp);
        storeLoc[1] = (painSplitHp & 0x0000FF00) >> 8;
        storeLoc[2] = (painSplitHp & 0x00FF0000) >> 16;
        storeLoc[3] = (painSplitHp & 0xFF000000) >> 24;

        gBattleMoveDamage = gBattleMons[gBankAttacker].hp - hpDiff;
        gSpecialStatuses[gBankTarget].moveturnLostHP = 0xFFFF;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

#ifdef NONMATCHING
static void atkA6_settypetorandomresistance(void) // conversion 2
{
    if (gUnknown_02024250[gBankAttacker] == 0
        || gUnknown_02024250[gBankAttacker] == 0xFFFF)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else if (IsTwoTurnsMove(gUnknown_02024250[gBankAttacker])
            && gBattleMons[gUnknown_02024270[gBankAttacker]].status2 & STATUS2_MULTIPLETURNS)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        s32 type = 0, rands = 0;
        do
        {
            while (((type = (Random() & 0x7F)) > 0x70));

            type *= 3;

            if (gTypeEffectiveness[type] == gUnknown_02024258[gBankAttacker]
                && gTypeEffectiveness[type + 2] <= 5
                && gBattleMons[gBankAttacker].type1 != gTypeEffectiveness[type + 1]
                && gBattleMons[gBankAttacker].type2 != gTypeEffectiveness[type + 1])
            {
                gBattleMons[gBankAttacker].type1 = type;
                gBattleMons[gBankAttacker].type2 = type;

                PREPARE_TYPE_BUFFER(gBattleTextBuff1, type)

                gBattlescriptCurrInstr += 5;
                return;
            }

            rands++;
        } while (rands <= 999);

        type = 0, rands = 0;
        do
        {
            s8 var = (s8)(gTypeEffectiveness[type]);
            if (var > -1 || var < -2)
            {
                if (gTypeEffectiveness[type] == gUnknown_02024258[gBankAttacker]
                    && gTypeEffectiveness[type + 2] <= 5
                    && gBattleMons[gBankAttacker].type1 != gTypeEffectiveness[type + 1]
                    && gBattleMons[gBankAttacker].type2 != gTypeEffectiveness[type + 1])
                {
                    gBattleMons[gBankAttacker].type1 = gTypeEffectiveness[rands + 1];
                    gBattleMons[gBankAttacker].type2 = gTypeEffectiveness[rands + 1];

                    PREPARE_TYPE_BUFFER(gBattleTextBuff1, gTypeEffectiveness[rands + 1])

                    gBattlescriptCurrInstr += 5;
                    return;
                }
            }
            type += 3, rands += 3;
        } while (rands < 336);

        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

#else
__attribute__((naked))
static void atkA6_settypetorandomresistance(void) // conversion 2
{
    asm(".syntax unified\n\
	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	ldr r1, =gUnknown_02024250\n\
	ldr r4, =gBankAttacker\n\
	ldrb r0, [r4]\n\
	lsls r0, 1\n\
	adds r2, r0, r1\n\
	ldrh r1, [r2]\n\
	cmp r1, 0\n\
	beq _08052B7E\n\
	ldr r0, =0x0000ffff\n\
	cmp r1, r0\n\
	beq _08052B7E\n\
	ldrh r0, [r2]\n\
	bl IsTwoTurnsMove\n\
	lsls r0, 24\n\
	cmp r0, 0\n\
	beq _08052C1C\n\
	ldr r1, =gBattleMons\n\
	ldr r2, =gUnknown_02024270\n\
	ldrb r0, [r4]\n\
	adds r0, r2\n\
	ldrb r2, [r0]\n\
	movs r0, 0x58\n\
	muls r0, r2\n\
	adds r1, 0x50\n\
	adds r0, r1\n\
	ldr r0, [r0]\n\
	movs r1, 0x80\n\
	lsls r1, 5\n\
	ands r0, r1\n\
	cmp r0, 0\n\
	beq _08052C1C\n\
_08052B7E:\n\
	ldr r3, =gBattlescriptCurrInstr\n\
	ldr r2, [r3]\n\
	ldrb r1, [r2, 0x1]\n\
	ldrb r0, [r2, 0x2]\n\
	lsls r0, 8\n\
	orrs r1, r0\n\
	ldrb r0, [r2, 0x3]\n\
	lsls r0, 16\n\
	orrs r1, r0\n\
	ldrb r0, [r2, 0x4]\n\
	lsls r0, 24\n\
	orrs r1, r0\n\
	str r1, [r3]\n\
	b _08052D08\n\
	.pool\n\
_08052BB4:\n\
	mov r0, r12\n\
	strb r5, [r0]\n\
	mov r1, r10\n\
	ldrb r0, [r1]\n\
	muls r0, r2\n\
	adds r0, r7\n\
	adds r0, 0x22\n\
	strb r5, [r0]\n\
	ldr r1, =gBattleTextBuff1\n\
	movs r0, 0xFD\n\
	strb r0, [r1]\n\
	movs r0, 0x3\n\
	strb r0, [r1, 0x1]\n\
	strb r5, [r1, 0x2]\n\
	movs r0, 0xFF\n\
	strb r0, [r1, 0x3]\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	b _08052C0A\n\
	.pool\n\
_08052BE0:\n\
	mov r0, r8\n\
	adds r0, 0x1\n\
	adds r0, r3\n\
	ldrb r2, [r0]\n\
	strb r2, [r4]\n\
	mov r4, r10\n\
	ldrb r0, [r4]\n\
	muls r0, r6\n\
	ldr r7, =gBattleMons\n\
	adds r0, r7\n\
	adds r0, 0x22\n\
	strb r2, [r0]\n\
	ldr r1, =gBattleTextBuff1\n\
	movs r0, 0xFD\n\
	strb r0, [r1]\n\
	movs r0, 0x3\n\
	strb r0, [r1, 0x1]\n\
	strb r2, [r1, 0x2]\n\
	movs r0, 0xFF\n\
	strb r0, [r1, 0x3]\n\
	mov r1, r12\n\
_08052C0A:\n\
	ldr r0, [r1]\n\
	adds r0, 0x5\n\
	str r0, [r1]\n\
	b _08052D08\n\
	.pool\n\
_08052C1C:\n\
	movs r4, 0\n\
	mov r8, r4\n\
	movs r7, 0x7F\n\
	mov r9, r7\n\
_08052C24:\n\
	bl Random\n\
	mov r4, r9\n\
	ands r4, r0\n\
	cmp r4, 0x70\n\
	bhi _08052C24\n\
	lsls r0, r4, 1\n\
	adds r4, r0, r4\n\
	ldr r6, =gTypeEffectiveness\n\
	adds r3, r4, r6\n\
	ldr r1, =gUnknown_02024258\n\
	ldr r2, =gBankAttacker\n\
	ldrb r5, [r2]\n\
	lsls r0, r5, 1\n\
	adds r0, r1\n\
	ldrb r1, [r3]\n\
	mov r10, r2\n\
	ldrh r0, [r0]\n\
	cmp r1, r0\n\
	bne _08052C80\n\
	adds r0, r4, 0x2\n\
	adds r0, r6\n\
	ldrb r0, [r0]\n\
	cmp r0, 0x5\n\
	bhi _08052C80\n\
	ldr r7, =gBattleMons\n\
	movs r2, 0x58\n\
	adds r0, r5, 0\n\
	muls r0, r2\n\
	adds r3, r0, r7\n\
	movs r0, 0x21\n\
	adds r0, r3\n\
	mov r12, r0\n\
	adds r0, r4, 0x1\n\
	adds r0, r6\n\
	ldrb r5, [r0]\n\
	mov r1, r12\n\
	ldrb r0, [r1]\n\
	adds r1, r5, 0\n\
	cmp r0, r1\n\
	beq _08052C80\n\
	adds r0, r3, 0\n\
	adds r0, 0x22\n\
	ldrb r0, [r0]\n\
	cmp r0, r1\n\
	bne _08052BB4\n\
_08052C80:\n\
	movs r7, 0x1\n\
	add r8, r7\n\
	ldr r0, =0x000003e7\n\
	cmp r8, r0\n\
	ble _08052C24\n\
	movs r0, 0\n\
	mov r8, r0\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	mov r12, r1\n\
	ldr r3, =gTypeEffectiveness\n\
	adds r0, r4, 0x1\n\
	adds r0, r3\n\
	mov r9, r0\n\
	adds r5, r3, 0\n\
_08052C9C:\n\
	ldrb r1, [r5]\n\
	cmp r1, 0xFF\n\
	bgt _08052CA6\n\
	cmp r1, 0xFE\n\
	bge _08052CE0\n\
_08052CA6:\n\
	mov r4, r10\n\
	ldrb r2, [r4]\n\
	lsls r0, r2, 1\n\
	ldr r7, =gUnknown_02024258\n\
	adds r0, r7\n\
	ldrh r0, [r0]\n\
	cmp r1, r0\n\
	bne _08052CE0\n\
	ldrb r0, [r5, 0x2]\n\
	cmp r0, 0x5\n\
	bhi _08052CE0\n\
	movs r6, 0x58\n\
	adds r0, r2, 0\n\
	muls r0, r6\n\
	ldr r1, =gBattleMons\n\
	adds r2, r0, r1\n\
	adds r4, r2, 0\n\
	adds r4, 0x21\n\
	ldrb r0, [r4]\n\
	mov r7, r9\n\
	ldrb r1, [r7]\n\
	cmp r0, r1\n\
	beq _08052CE0\n\
	adds r0, r2, 0\n\
	adds r0, 0x22\n\
	ldrb r0, [r0]\n\
	cmp r0, r1\n\
	beq _08052CE0\n\
	b _08052BE0\n\
_08052CE0:\n\
	adds r5, 0x3\n\
	movs r0, 0x3\n\
	add r8, r0\n\
	ldr r0, =0x0000014f\n\
	cmp r8, r0\n\
	bls _08052C9C\n\
	mov r1, r12\n\
	ldr r2, [r1]\n\
	ldrb r1, [r2, 0x1]\n\
	ldrb r0, [r2, 0x2]\n\
	lsls r0, 8\n\
	orrs r1, r0\n\
	ldrb r0, [r2, 0x3]\n\
	lsls r0, 16\n\
	orrs r1, r0\n\
	ldrb r0, [r2, 0x4]\n\
	lsls r0, 24\n\
	orrs r1, r0\n\
	mov r4, r12\n\
	str r1, [r4]\n\
_08052D08:\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
        .syntax divided");
}
#endif // NONMATCHING

static void atkA7_setalwayshitflag(void)
{
    gStatuses3[gBankTarget] &= ~(STATUS3_ALWAYS_HITS);
    gStatuses3[gBankTarget] |= 0x10;
    gDisableStructs[gBankTarget].bankWithSureHit = gBankAttacker;
    gBattlescriptCurrInstr++;
}

static void atkA8_copymovepermanently(void) // sketch
{
    gLastUsedMove = 0xFFFF;

    if (!(gBattleMons[gBankAttacker].status2 & STATUS2_TRANSFORMED)
        && gUnknownMovesUsedByBanks[gBankTarget] != MOVE_STRUGGLE
        && gUnknownMovesUsedByBanks[gBankTarget] != 0
        && gUnknownMovesUsedByBanks[gBankTarget] != 0xFFFF
        && gUnknownMovesUsedByBanks[gBankTarget] != MOVE_SKETCH)
    {
        s32 i;

        for (i = 0; i < 4; i++)
        {
            if (gBattleMons[gBankAttacker].moves[i] == MOVE_SKETCH)
                continue;
            if (gBattleMons[gBankAttacker].moves[i] == gUnknownMovesUsedByBanks[gBankTarget])
                break;
        }

        if (i != 4)
        {
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        }
        else // sketch worked
        {
            struct MovePpInfo movePpData;

            gBattleMons[gBankAttacker].moves[gCurrMovePos] = gUnknownMovesUsedByBanks[gBankTarget];
            gBattleMons[gBankAttacker].pp[gCurrMovePos] = gBattleMoves[gUnknownMovesUsedByBanks[gBankTarget]].pp;
            gActiveBank = gBankAttacker;

            for (i = 0; i < 4; i++)
            {
                movePpData.move[i] = gBattleMons[gBankAttacker].moves[i];
                movePpData.pp[i] = gBattleMons[gBankAttacker].pp[i];
            }
            movePpData.ppBonuses = gBattleMons[gBankAttacker].ppBonuses;

            EmitSetMonData(0, REQUEST_MOVES_PP_BATTLE, 0, sizeof(struct MovePpInfo), &movePpData);
            MarkBufferBankForExecution(gActiveBank);

            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gUnknownMovesUsedByBanks[gBankTarget])

            gBattlescriptCurrInstr += 5;
        }
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static bool8 IsTwoTurnsMove(u16 move)
{
    if (gBattleMoves[move].effect == EFFECT_SKULL_BASH
        || gBattleMoves[move].effect == EFFECT_RAZOR_WIND
        || gBattleMoves[move].effect == EFFECT_SKY_ATTACK
        || gBattleMoves[move].effect == EFFECT_SOLARBEAM
        || gBattleMoves[move].effect == EFFECT_FLY
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

static u8 AttacksThisTurn(u8 bank, u16 move) // Note: returns 1 if it's a charging turn, otherwise 2
{
    // first argument is unused
    if (gBattleMoves[move].effect == EFFECT_SOLARBEAM
        && (gBattleWeather & WEATHER_SUN_ANY))
        return 2;

    if (gBattleMoves[move].effect == EFFECT_SKULL_BASH
        || gBattleMoves[move].effect == EFFECT_RAZOR_WIND
        || gBattleMoves[move].effect == EFFECT_SKY_ATTACK
        || gBattleMoves[move].effect == EFFECT_SOLARBEAM
        || gBattleMoves[move].effect == EFFECT_FLY
        || gBattleMoves[move].effect == EFFECT_BIDE)
    {
        if ((gHitMarker & HITMARKER_x8000000))
            return 1;
    }
    return 2;
}

static void atkA9_sleeptalk_choose_move(void)
{
    s32 i;
    u8 unusableMovesBits = 0;

    for (i = 0; i < 4; i++)
    {
        if (IsInvalidForSleepTalkOrAssist(gBattleMons[gBankAttacker].moves[i])
            || gBattleMons[gBankAttacker].moves[i] == MOVE_FOCUS_PUNCH
            || gBattleMons[gBankAttacker].moves[i] == MOVE_UPROAR
            || IsTwoTurnsMove(gBattleMons[gBankAttacker].moves[i]))
        {
            unusableMovesBits |= gBitTable[i];
        }

    }

    unusableMovesBits = CheckMoveLimitations(gBankAttacker, unusableMovesBits, ~(MOVE_LIMITATION_PP));
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

        gRandomMove = gBattleMons[gBankAttacker].moves[movePosition];
        gCurrMovePos = movePosition;
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
        gBankTarget = GetMoveTarget(gRandomMove, 0);
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkAA_set_destinybond(void)
{
    gBattleMons[gBankAttacker].status2 |= STATUS2_DESTINY_BOND;
    gBattlescriptCurrInstr++;
}

static void DestinyBondFlagUpdate(void)
{
    u8 sideAttacker = GetBankSide(gBankAttacker);
    u8 sideTarget = GetBankSide(gBankTarget);
    if (gBattleMons[gBankTarget].status2 & STATUS2_DESTINY_BOND
        && sideAttacker != sideTarget
        && !(gHitMarker & HITMARKER_GRUDGE))
    {
        gHitMarker |= HITMARKER_DESTINYBOND;
    }
}

static void atkAB_DestinyBondFlagUpdate(void)
{
    DestinyBondFlagUpdate();
    gBattlescriptCurrInstr++;
}

static void atkAC_remaininghptopower(void)
{
    s32 i;
    s32 hpFraction = GetScaledHPFraction(gBattleMons[gBankAttacker].hp, gBattleMons[gBankAttacker].maxHP, 48);

    for (i = 0; i < (s32) sizeof(sFlailHpScaleToPowerTable); i += 2)
    {
        if (hpFraction <= sFlailHpScaleToPowerTable[i])
            break;
    }

    gDynamicBasePower = sFlailHpScaleToPowerTable[i + 1];
    gBattlescriptCurrInstr++;
}

static void atkAD_spite_ppreduce(void)
{
    if (gLastUsedMovesByBanks[gBankTarget] != 0
        && gLastUsedMovesByBanks[gBankTarget] != 0xFFFF)
    {
        s32 i;

        for (i = 0; i < 4; i++)
        {
            if (gLastUsedMovesByBanks[gBankTarget] == gBattleMons[gBankTarget].moves[i])
                break;
        }

        if (i != 4 && gBattleMons[gBankTarget].pp[i] > 1)
        {
            s32 ppToDeduct = (Random() & 3) + 2;
            if (gBattleMons[gBankTarget].pp[i] < ppToDeduct)
                ppToDeduct = gBattleMons[gBankTarget].pp[i];

            PREPARE_MOVE_BUFFER(gBattleTextBuff1, gLastUsedMovesByBanks[gBankTarget])

            ConvertIntToDecimalStringN(gBattleTextBuff2, ppToDeduct, 0, 1);

            PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 1, ppToDeduct)

            gBattleMons[gBankTarget].pp[i] -= ppToDeduct;
            gActiveBank = gBankTarget;

            if (!(gDisableStructs[gActiveBank].unk18_b & gBitTable[i])
                && !(gBattleMons[gActiveBank].status2 & STATUS2_TRANSFORMED))
            {
                EmitSetMonData(0, REQUEST_PPMOVE1_BATTLE + i, 0, 1, &gBattleMons[gActiveBank].pp[i]);
                MarkBufferBankForExecution(gActiveBank);
            }

            gBattlescriptCurrInstr += 5;

            if (gBattleMons[gBankTarget].pp[i] == 0)
                CancelMultiTurnMoves(gBankTarget);
        }
        else
        {
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        }
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkAE_heal_party_status(void)
{
    u32 zero = 0;
    u8 toHeal = 0;

    if (gCurrentMove == MOVE_HEAL_BELL)
    {
        struct Pokemon* party;
        s32 i;

        gBattleCommunication[MULTISTRING_CHOOSER] = 0;

        if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
            party = gPlayerParty;
        else
            party = gEnemyParty;

        if (gBattleMons[gBankAttacker].ability != ABILITY_SOUNDPROOF)
        {
            gBattleMons[gBankAttacker].status1 = 0;
            gBattleMons[gBankAttacker].status2 &= ~(STATUS2_NIGHTMARE);
        }
        else
        {
            RecordAbilityBattle(gBankAttacker, gBattleMons[gBankAttacker].ability);
            gBattleCommunication[MULTISTRING_CHOOSER] |= 1;
        }

        gActiveBank = gBattleScripting.bank = GetBankByIdentity(GetBankIdentity(gBankAttacker) ^ BIT_MON);

        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
            && !(gAbsentBankFlags & gBitTable[gActiveBank]))
        {
            if (gBattleMons[gActiveBank].ability != ABILITY_SOUNDPROOF)
            {
                gBattleMons[gActiveBank].status1 = 0;
                gBattleMons[gActiveBank].status2 &= ~(STATUS2_NIGHTMARE);
            }
            else
            {
                RecordAbilityBattle(gActiveBank, gBattleMons[gActiveBank].ability);
                gBattleCommunication[MULTISTRING_CHOOSER] |= 2;
            }
        }

        for (i = 0; i < 6; i++)
        {
            u16 species = GetMonData(&party[i], MON_DATA_SPECIES2);
            u8 abilityBit = GetMonData(&party[i], MON_DATA_ALT_ABILITY);

            if (species != 0 && species != SPECIES_EGG)
            {
                u8 ability;

                if (gBattlePartyID[gBankAttacker] == i)
                    ability = gBattleMons[gBankAttacker].ability;
                else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                         && gBattlePartyID[gActiveBank] == i
                         && !(gAbsentBankFlags & gBitTable[gActiveBank]))
                    ability = gBattleMons[gActiveBank].ability;
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

        gBattleMons[gBankAttacker].status1 = 0;
        gBattleMons[gBankAttacker].status2 &= ~(STATUS2_NIGHTMARE);

        gActiveBank = GetBankByIdentity(GetBankIdentity(gBankAttacker) ^ 2);
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
            && !(gAbsentBankFlags & gBitTable[gActiveBank]))
        {
            gBattleMons[gActiveBank].status1 = 0;
            gBattleMons[gActiveBank].status2 &= ~(STATUS2_NIGHTMARE);
        }

    }

    if (toHeal)
    {
        gActiveBank = gBankAttacker;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, toHeal, 4, &zero);
        MarkBufferBankForExecution(gActiveBank);
    }

    gBattlescriptCurrInstr++;
}

static void atkAF_cursetarget(void)
{
    if (gBattleMons[gBankTarget].status2 & STATUS2_CURSED)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gBattleMons[gBankTarget].status2 |= STATUS2_CURSED;
        gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattlescriptCurrInstr += 5;
    }
}

static void atkB0_set_spikes(void)
{
    u8 targetSide = GetBankSide(gBankAttacker) ^ BIT_SIDE;

    if (gSideTimers[targetSide].spikesAmount == 3)
    {
        gSpecialStatuses[gBankAttacker].flag20 = 1;
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gSideAffecting[targetSide] |= SIDE_STATUS_SPIKES;
        gSideTimers[targetSide].spikesAmount++;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkB1_set_foresight(void)
{
    gBattleMons[gBankTarget].status2 |= STATUS2_FORESIGHT;
    gBattlescriptCurrInstr++;
}

static void atkB2_setperishsong(void)
{
    s32 i;
    s32 notAffectedCount = 0;

    for (i = 0; i < gNoOfAllBanks; i++)
    {
        if (gStatuses3[i] & STATUS3_PERISH_SONG
            || gBattleMons[i].ability == ABILITY_SOUNDPROOF)
        {
            notAffectedCount++;
        }
        else
        {
            gStatuses3[i] |= STATUS3_PERISH_SONG;
            gDisableStructs[i].perishSong1 = 3;
            gDisableStructs[i].perishSong2 = 3;
        }
    }

    PressurePPLoseOnUsingPerishSong(gBankAttacker);

    if (notAffectedCount == gNoOfAllBanks)
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atkB3_rolloutdamagecalculation(void)
{
    if (gBattleMoveFlags & MOVESTATUS_NOEFFECT)
    {
        CancelMultiTurnMoves(gBankAttacker);
        gBattlescriptCurrInstr = BattleScript_PauseEffectivenessSoundResultMsgEndMove;
    }
    else
    {
        s32 i;

        if (!(gBattleMons[gBankAttacker].status2 & STATUS2_MULTIPLETURNS)) // first hit
        {
            gDisableStructs[gBankAttacker].rolloutTimer1 = 5;
            gDisableStructs[gBankAttacker].rolloutTimer2 = 5;
            gBattleMons[gBankAttacker].status2 |= STATUS2_MULTIPLETURNS;
            gLockedMoves[gBankAttacker] = gCurrentMove;
        }
        if (--gDisableStructs[gBankAttacker].rolloutTimer1 == 0) // last hit
        {
            gBattleMons[gBankAttacker].status2 &= ~(STATUS2_MULTIPLETURNS);
        }

        gDynamicBasePower = gBattleMoves[gCurrentMove].power;

        for (i = 1; i < (5 - gDisableStructs[gBankAttacker].rolloutTimer1); i++)
            gDynamicBasePower *= 2;

        if (gBattleMons[gBankAttacker].status2 & STATUS2_DEFENSE_CURL)
            gDynamicBasePower *= 2;

        gBattlescriptCurrInstr++;
    }
}

static void atkB4_jumpifconfusedandstatmaxed(void)
{
    if (gBattleMons[gBankTarget].status2 & STATUS2_CONFUSION
        && gBattleMons[gBankTarget].statStages[gBattlescriptCurrInstr[1]] == 0xC)
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
    else
        gBattlescriptCurrInstr += 6;
}

static void atkB5_furycuttercalc(void)
{
    if (gBattleMoveFlags & MOVESTATUS_NOEFFECT)
    {
        gDisableStructs[gBankAttacker].furyCutterCounter = 0;
        gBattlescriptCurrInstr = BattleScript_PauseEffectivenessSoundResultMsgEndMove;
    }
    else
    {
        s32 i;

        if (gDisableStructs[gBankAttacker].furyCutterCounter != 5)
            gDisableStructs[gBankAttacker].furyCutterCounter++;

        gDynamicBasePower = gBattleMoves[gCurrentMove].power;

        for (i = 1; i < gDisableStructs[gBankAttacker].furyCutterCounter; i++)
            gDynamicBasePower *= 2;

        gBattlescriptCurrInstr++;
    }
}

static void atkB6_happinesstodamagecalculation(void)
{
    if (gBattleMoves[gCurrentMove].effect == EFFECT_RETURN)
        gDynamicBasePower = 10 * (gBattleMons[gBankAttacker].friendship) / 25;
    else // EFFECT_FRUSTRATION
        gDynamicBasePower = 10 * (255 - gBattleMons[gBankAttacker].friendship) / 25;

    gBattlescriptCurrInstr++;
}

static void atkB7_presentdamagecalculation(void)
{
    s32 rand = Random() & 0xFF;

    if (rand < 102)
        gDynamicBasePower = 40;
    else if (rand < 178)
        gDynamicBasePower = 80;
    else if (rand < 204)
        gDynamicBasePower = 120;
    else
    {
        gBattleMoveDamage = gBattleMons[gBankTarget].maxHP / 4;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;
    }
    if (rand < 204)
        gBattlescriptCurrInstr = BattleScript_PresentDamageTarget;
    else if (gBattleMons[gBankTarget].maxHP == gBattleMons[gBankTarget].hp)
        gBattlescriptCurrInstr = BattleScript_AlreadyAtFullHp;
    else
    {
        gBattleMoveFlags &= ~(MOVESTATUS_NOTAFFECTED);
        gBattlescriptCurrInstr = BattleScript_PresentHealTarget;
    }
}

static void atkB8_set_safeguard(void)
{
    if (gSideAffecting[GET_BANK_SIDE(gBankAttacker)] & SIDE_STATUS_SAFEGUARD)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
    }
    else
    {
        gSideAffecting[GET_BANK_SIDE(gBankAttacker)] |= SIDE_STATUS_SAFEGUARD;
        gSideTimers[GET_BANK_SIDE(gBankAttacker)].safeguardTimer = 5;
        gSideTimers[GET_BANK_SIDE(gBankAttacker)].safeguardBank = gBankAttacker;
        gBattleCommunication[MULTISTRING_CHOOSER] = 5;
    }

    gBattlescriptCurrInstr++;
}

static void atkB9_magnitudedamagecalculation(void)
{
    s32 magnitude = Random() % 100;

    if (magnitude < 5)
    {
        gDynamicBasePower = 10;
        magnitude = 4;
    }
    else if (magnitude < 15)
    {
        gDynamicBasePower = 30;
        magnitude = 5;
    }
    else if (magnitude < 35)
    {
        gDynamicBasePower = 50;
        magnitude = 6;
    }
    else if (magnitude < 65)
    {
        gDynamicBasePower = 70;
        magnitude = 7;
    }
    else if (magnitude < 85)
    {
        gDynamicBasePower = 90;
        magnitude = 8;
    }
    else if (magnitude < 95)
    {
        gDynamicBasePower = 110;
        magnitude = 9;
    }
    else
    {
        gDynamicBasePower = 150;
        magnitude = 10;
    }


    PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 2, magnitude)

    for (gBankTarget = 0; gBankTarget < gNoOfAllBanks; gBankTarget++)
    {
        if (gBankTarget == gBankAttacker)
            continue;
        if (!(gAbsentBankFlags & gBitTable[gBankTarget])) // a valid target was found
            break;
    }

    gBattlescriptCurrInstr++;
}

static void atkBA_jumpifnopursuitswitchdmg(void)
{
    if (gMultiHitCounter == 1)
    {
        if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
            gBankTarget = GetBankByIdentity(IDENTITY_OPPONENT_MON1);
        else
            gBankTarget = GetBankByIdentity(IDENTITY_PLAYER_MON1);
    }
    else
    {
        if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
            gBankTarget = GetBankByIdentity(IDENTITY_OPPONENT_MON2);
        else
            gBankTarget = GetBankByIdentity(IDENTITY_PLAYER_MON2);
    }

    if (gActionForBanks[gBankTarget] == 0
        && gBankAttacker == *(gBattleStruct->moveTarget + gBankTarget)
        && !(gBattleMons[gBankTarget].status1 & (STATUS_SLEEP | STATUS_FREEZE))
        && gBattleMons[gBankAttacker].hp
        && !gDisableStructs[gBankTarget].truantCounter
        && gChosenMovesByBanks[gBankTarget] == MOVE_PURSUIT)
    {
        s32 i;

        for (i = 0; i < gNoOfAllBanks; i++)
        {
            if (gTurnOrder[i] == gBankTarget)
                gUnknown_0202407A[i] = 11;
        }

        gCurrentMove = MOVE_PURSUIT;
        gCurrMovePos = gUnknown_020241E9 = *(gBattleStruct->chosenMovesIds + gBankTarget);
        gBattlescriptCurrInstr += 5;
        gBattleScripting.animTurn = 1;
        gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkBB_setsunny(void)
{
    if (gBattleWeather & WEATHER_SUN_ANY)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleWeather = WEATHER_SUN_TEMPORARY;
        gBattleCommunication[MULTISTRING_CHOOSER] = 4;
        gWishFutureKnock.weatherDuration = 5;
    }

    gBattlescriptCurrInstr++;
}

static void atkBC_maxattackhalvehp(void) // belly drum
{
    u32 halfHp = gBattleMons[gBankAttacker].maxHP / 2;

    if (!(gBattleMons[gBankAttacker].maxHP / 2))
        halfHp = 1;

    if (gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK] < 12
        && gBattleMons[gBankAttacker].hp > halfHp)
    {
        gBattleMons[gBankAttacker].statStages[STAT_STAGE_ATK] = 12;
        gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkBD_copyfoestats(void) // psych up
{
    s32 i;

    for (i = 0; i < BATTLE_STATS_NO; i++)
    {
        gBattleMons[gBankAttacker].statStages[i] = gBattleMons[gBankTarget].statStages[i];
    }

    gBattlescriptCurrInstr += 5; // Has an unused jump ptr(possibly for a failed attempt) parameter.
}

static void atkBE_rapidspinfree(void)
{
    if (gBattleMons[gBankAttacker].status2 & STATUS2_WRAPPED)
    {
        gBattleScripting.bank = gBankTarget;
        gBattleMons[gBankAttacker].status2 &= ~(STATUS2_WRAPPED);
        gBankTarget = *(gBattleStruct->wrappedBy + gBankAttacker);

        gBattleTextBuff1[0] = B_BUFF_PLACEHOLDER_BEGIN;
        gBattleTextBuff1[1] = B_BUFF_MOVE;
        gBattleTextBuff1[2] = *(gBattleStruct->wrappedMove + gBankAttacker * 2 + 0);
        gBattleTextBuff1[3] = *(gBattleStruct->wrappedMove + gBankAttacker * 2 + 1);
        gBattleTextBuff1[4] = B_BUFF_EOS;

        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_WrapFree;
    }
    else if (gStatuses3[gBankAttacker] & STATUS3_LEECHSEED)
    {
        gStatuses3[gBankAttacker] &= ~(STATUS3_LEECHSEED);
        gStatuses3[gBankAttacker] &= ~(STATUS3_LEECHSEED_BANK);
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_LeechSeedFree;
    }
    else if (gSideAffecting[GetBankSide(gBankAttacker)] & SIDE_STATUS_SPIKES)
    {
        gSideAffecting[GetBankSide(gBankAttacker)] &= ~(SIDE_STATUS_SPIKES);
        gSideTimers[GetBankSide(gBankAttacker)].spikesAmount = 0;
        BattleScriptPushCursor();
        gBattlescriptCurrInstr = BattleScript_SpikesFree;
    }
    else
    {
        gBattlescriptCurrInstr++;
    }
}

static void atkBF_set_defense_curl(void)
{
    gBattleMons[gBankAttacker].status2 |= STATUS2_DEFENSE_CURL;
    gBattlescriptCurrInstr++;
}

static void atkC0_recoverbasedonsunlight(void)
{
    gBankTarget = gBankAttacker;

    if (gBattleMons[gBankAttacker].hp != gBattleMons[gBankAttacker].maxHP)
    {
        if (gBattleWeather == 0 || !WEATHER_HAS_EFFECT)
            gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 2;
        else if (gBattleWeather & WEATHER_SUN_ANY)
            gBattleMoveDamage = 20 * gBattleMons[gBankAttacker].maxHP / 30;
        else // not sunny weather
            gBattleMoveDamage = gBattleMons[gBankAttacker].maxHP / 4;

        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

#ifdef NONMATCHING
static void atkC1_hidden_power(void)
{
    s32 powerBits;
    s32 typeBits;

    powerBits = ((gBattleMons[gBankAttacker].hpIV & 2) >> 1)
                  | ((gBattleMons[gBankAttacker].attackIV & 2) << 0)
                  | ((gBattleMons[gBankAttacker].defenseIV & 2) << 1)
                  | ((gBattleMons[gBankAttacker].speedIV & 2) << 2)
                  | ((gBattleMons[gBankAttacker].spAttackIV & 2) << 3)
                  | ((gBattleMons[gBankAttacker].spDefenseIV & 2) << 4);

    typeBits = ((gBattleMons[gBankAttacker].hpIV & 1) << 0)
                  | ((gBattleMons[gBankAttacker].attackIV & 1) << 1)
                  | ((gBattleMons[gBankAttacker].defenseIV & 1) << 2)
                  | ((gBattleMons[gBankAttacker].speedIV & 1) << 3)
                  | ((gBattleMons[gBankAttacker].spAttackIV & 1) << 4)
                  | ((gBattleMons[gBankAttacker].spDefenseIV & 1) << 5);

    gDynamicBasePower = (40 * powerBits) / 63 + 30;

    gBattleStruct->dynamicMoveType = (15 * typeBits) / 63 + 1;
    if (gBattleStruct->dynamicMoveType > 8)
        gBattleStruct->dynamicMoveType++;
    gBattleStruct->dynamicMoveType |= 0xC0;

    gBattlescriptCurrInstr++;
}

#else
__attribute__((naked))
static void atkC1_hidden_power(void)
{
    asm(".syntax unified\n\
        	push {r4-r7,lr}\n\
	mov r7, r10\n\
	mov r6, r9\n\
	mov r5, r8\n\
	push {r5-r7}\n\
	ldr r2, =gBattleMons\n\
	ldr r0, =gBankAttacker\n\
	ldrb r1, [r0]\n\
	movs r0, 0x58\n\
	adds r4, r1, 0\n\
	muls r4, r0\n\
	adds r4, r2\n\
	ldrb r0, [r4, 0x14]\n\
	mov r10, r0\n\
	mov r7, r10\n\
	lsls r7, 27\n\
	adds r0, r7, 0\n\
	lsrs r0, 27\n\
	mov r10, r0\n\
	movs r1, 0x2\n\
	mov r2, r10\n\
	ands r2, r1\n\
	asrs r2, 1\n\
	ldrh r7, [r4, 0x14]\n\
	mov r9, r7\n\
	mov r0, r9\n\
	lsls r0, 22\n\
	mov r9, r0\n\
	lsrs r3, r0, 27\n\
	adds r0, r1, 0\n\
	ands r0, r3\n\
	orrs r2, r0\n\
	ldrb r7, [r4, 0x15]\n\
	mov r8, r7\n\
	mov r0, r8\n\
	lsls r0, 25\n\
	mov r8, r0\n\
	lsrs r3, r0, 27\n\
	adds r0, r1, 0\n\
	ands r0, r3\n\
	lsls r0, 1\n\
	orrs r2, r0\n\
	ldr r6, [r4, 0x14]\n\
	lsls r6, 12\n\
	lsrs r3, r6, 27\n\
	adds r0, r1, 0\n\
	ands r0, r3\n\
	lsls r0, 2\n\
	orrs r2, r0\n\
	ldrh r5, [r4, 0x16]\n\
	lsls r5, 23\n\
	lsrs r3, r5, 27\n\
	adds r0, r1, 0\n\
	ands r0, r3\n\
	lsls r0, 3\n\
	orrs r2, r0\n\
	ldrb r3, [r4, 0x17]\n\
	lsls r3, 26\n\
	lsrs r0, r3, 27\n\
	ands r1, r0\n\
	lsls r1, 4\n\
	orrs r2, r1\n\
	movs r1, 0x1\n\
	adds r4, r1, 0\n\
	mov r7, r10\n\
	ands r4, r7\n\
	mov r0, r9\n\
	lsrs r0, 27\n\
	mov r9, r0\n\
	adds r0, r1, 0\n\
	mov r7, r9\n\
	ands r0, r7\n\
	lsls r0, 1\n\
	orrs r4, r0\n\
	mov r0, r8\n\
	lsrs r0, 27\n\
	mov r8, r0\n\
	adds r0, r1, 0\n\
	mov r7, r8\n\
	ands r0, r7\n\
	lsls r0, 2\n\
	orrs r4, r0\n\
	lsrs r6, 27\n\
	adds r0, r1, 0\n\
	ands r0, r6\n\
	lsls r0, 3\n\
	orrs r4, r0\n\
	lsrs r5, 27\n\
	adds r0, r1, 0\n\
	ands r0, r5\n\
	lsls r0, 4\n\
	orrs r4, r0\n\
	lsrs r3, 27\n\
	ands r1, r3\n\
	lsls r1, 5\n\
	orrs r4, r1\n\
	ldr r5, =gDynamicBasePower\n\
	lsls r0, r2, 2\n\
	adds r0, r2\n\
	lsls r0, 3\n\
	movs r1, 0x3F\n\
	bl __divsi3\n\
	adds r0, 0x1E\n\
	strh r0, [r5]\n\
	ldr r6, =gBattleStruct\n\
	ldr r5, [r6]\n\
	lsls r0, r4, 4\n\
	subs r0, r4\n\
	movs r1, 0x3F\n\
	bl __divsi3\n\
	adds r0, 0x1\n\
	strb r0, [r5, 0x13]\n\
	ldr r1, [r6]\n\
	ldrb r0, [r1, 0x13]\n\
	cmp r0, 0x8\n\
	bls _080544F0\n\
	adds r0, 0x1\n\
	strb r0, [r1, 0x13]\n\
_080544F0:\n\
	ldr r2, [r6]\n\
	ldrb r0, [r2, 0x13]\n\
	movs r1, 0xC0\n\
	orrs r0, r1\n\
	strb r0, [r2, 0x13]\n\
	ldr r1, =gBattlescriptCurrInstr\n\
	ldr r0, [r1]\n\
	adds r0, 0x1\n\
	str r0, [r1]\n\
	pop {r3-r5}\n\
	mov r8, r3\n\
	mov r9, r4\n\
	mov r10, r5\n\
	pop {r4-r7}\n\
	pop {r0}\n\
	bx r0\n\
	.pool\n\
        .syntax divided");
}
#endif // NONMATCHING

static void atkC2_selectnexttarget(void)
{
    for (gBankTarget = 0; gBankTarget < gNoOfAllBanks; gBankTarget++)
    {
        if (gBankTarget == gBankAttacker)
            continue;
        if (!(gAbsentBankFlags & gBitTable[gBankTarget]))
            break;
    }
    gBattlescriptCurrInstr++;
}

static void atkC3_setfutureattack(void)
{
    if (gWishFutureKnock.futureSightCounter[gBankTarget] != 0)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gSideAffecting[GET_BANK_SIDE(gBankTarget)] |= SIDE_STATUS_FUTUREATTACK;
        gWishFutureKnock.futureSightMove[gBankTarget] = gCurrentMove;
        gWishFutureKnock.futureSightAttacker[gBankTarget] = gBankAttacker;
        gWishFutureKnock.futureSightCounter[gBankTarget] = 3;
        gWishFutureKnock.futureSightDmg[gBankTarget] = CalculateBaseDamage(&gBattleMons[gBankAttacker], &gBattleMons[gBankTarget], gCurrentMove,
                                                    gSideAffecting[GET_BANK_SIDE(gBankTarget)], 0,
                                                    0, gBankAttacker, gBankTarget);

        if (gProtectStructs[gBankAttacker].helpingHand)
            gWishFutureKnock.futureSightDmg[gBankTarget] = gWishFutureKnock.futureSightDmg[gBankTarget] * 15 / 10;

        if (gCurrentMove == MOVE_DOOM_DESIRE)
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;

        gBattlescriptCurrInstr += 5;
    }
}

static void atkC4_beat_up(void)
{
    struct Pokemon* party;

    if (GetBankSide(gBankAttacker) == SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleMons[gBankTarget].hp == 0)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
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
            PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gBankAttacker, gBattleCommunication[0])

            gBattlescriptCurrInstr += 9;

            gBattleMoveDamage = gBaseStats[GetMonData(&party[gBattleCommunication[0]], MON_DATA_SPECIES)].baseAttack;
            gBattleMoveDamage *= gBattleMoves[gCurrentMove].power;
            gBattleMoveDamage *= (GetMonData(&party[gBattleCommunication[0]], MON_DATA_LEVEL) * 2 / 5 + 2);
            gBattleMoveDamage /= gBaseStats[gBattleMons[gBankTarget].species].baseDefense;
            gBattleMoveDamage = (gBattleMoveDamage / 50) + 2;
            if (gProtectStructs[gBankAttacker].helpingHand)
                gBattleMoveDamage = gBattleMoveDamage * 15 / 10;

            gBattleCommunication[0]++;
        }
        else if (beforeLoop != 0)
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        else
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 5);
    }
}

static void atkC5_setsemiinvulnerablebit(void)
{
    switch (gCurrentMove)
    {
    case MOVE_FLY:
    case MOVE_BOUNCE:
        gStatuses3[gBankAttacker] |= STATUS3_ON_AIR;
        break;
    case MOVE_DIG:
        gStatuses3[gBankAttacker] |= STATUS3_UNDERGROUND;
        break;
    case MOVE_DIVE:
        gStatuses3[gBankAttacker] |= STATUS3_UNDERWATER;
        break;
    }

    gBattlescriptCurrInstr++;
}

static void atkC6_clearsemiinvulnerablebit(void)
{
    switch (gCurrentMove)
    {
    case MOVE_FLY:
    case MOVE_BOUNCE:
        gStatuses3[gBankAttacker] &= ~STATUS3_ON_AIR;
        break;
    case MOVE_DIG:
        gStatuses3[gBankAttacker] &= ~STATUS3_UNDERGROUND;
        break;
    case MOVE_DIVE:
        gStatuses3[gBankAttacker] &= ~STATUS3_UNDERWATER;
        break;
    }

    gBattlescriptCurrInstr++;
}

static void atkC7_setminimize(void)
{
    if (gHitMarker & HITMARKER_OBEYS)
        gStatuses3[gBankAttacker] |= STATUS3_MINIMIZED;

    gBattlescriptCurrInstr++;
}

static void atkC8_sethail(void)
{
    if (gBattleWeather & WEATHER_HAIL_ANY)
    {
        gBattleMoveFlags |= MOVESTATUS_MISSED;
        gBattleCommunication[MULTISTRING_CHOOSER] = 2;
    }
    else
    {
        gBattleWeather = WEATHER_HAIL;
        gBattleCommunication[MULTISTRING_CHOOSER] = 5;
        gWishFutureKnock.weatherDuration = 5;
    }

    gBattlescriptCurrInstr++;
}

static void atkC9_jumpifattackandspecialattackcannotfall(void) // memento
{
    if (gBattleMons[gBankTarget].statStages[STAT_STAGE_ATK] == 0
        && gBattleMons[gBankTarget].statStages[STAT_STAGE_SPATK] == 0
        && gBattleCommunication[6] != 1)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gActiveBank = gBankAttacker;
        gBattleMoveDamage = gBattleMons[gActiveBank].hp;
        EmitHealthBarUpdate(0, 0x7FFF);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr += 5;
    }
}

static void atkCA_setforcedtarget(void) // follow me
{
    gSideTimers[GetBankSide(gBankAttacker)].followmeTimer = 1;
    gSideTimers[GetBankSide(gBankAttacker)].followmeTarget = gBankAttacker;
    gBattlescriptCurrInstr++;
}

static void atkCB_setcharge(void)
{
    gStatuses3[gBankAttacker] |= STATUS3_CHARGED_UP;
    gDisableStructs[gBankAttacker].chargeTimer1 = 2;
    gDisableStructs[gBankAttacker].chargeTimer2 = 2;
    gBattlescriptCurrInstr++;
}

static void atkCC_callterrainattack(void) // nature power
{
    gHitMarker &= ~(HITMARKER_ATTACKSTRING_PRINTED);
    gCurrentMove = sNaturePowerMoves[gBattleTerrain];
    gBankTarget = GetMoveTarget(gCurrentMove, 0);
    BattleScriptPush(gBattleScriptsForMoveEffects[gBattleMoves[gCurrentMove].effect]);
    gBattlescriptCurrInstr++;
}

static void atkCD_cureifburnedparalysedorpoisoned(void) // refresh
{
    if (gBattleMons[gBankAttacker].status1 & (STATUS_POISON | STATUS_BURN | STATUS_PARALYSIS | STATUS_TOXIC_POISON))
    {
        gBattleMons[gBankAttacker].status1 = 0;
        gBattlescriptCurrInstr += 5;
        gActiveBank = gBankAttacker;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBank].status1);
        MarkBufferBankForExecution(gActiveBank);
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkCE_settorment(void)
{
    if (gBattleMons[gBankTarget].status2 & STATUS2_TORMENT)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gBattleMons[gBankTarget].status2 |= STATUS2_TORMENT;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkCF_jumpifnodamage(void)
{
    if (gProtectStructs[gBankAttacker].physicalDmg || gProtectStructs[gBankAttacker].specialDmg)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
}

static void atkD0_settaunt(void)
{
    if (gDisableStructs[gBankTarget].tauntTimer1 == 0)
    {
        gDisableStructs[gBankTarget].tauntTimer1 = 2;
        gDisableStructs[gBankTarget].tauntTimer2 = 2;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkD1_set_helpinghand(void)
{
    gBankTarget = GetBankByIdentity(GetBankIdentity(gBankAttacker) ^ BIT_MON);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
        && !(gAbsentBankFlags & gBitTable[gBankTarget])
        && !gProtectStructs[gBankAttacker].helpingHand
        && !gProtectStructs[gBankTarget].helpingHand)
    {
        gProtectStructs[gBankTarget].helpingHand = 1;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkD2_swap_items(void) // trick
{
    // opponent can't swap items with player in regular battles
    if (gBattleTypeFlags & BATTLE_TYPE_x4000000
        || (GetBankSide(gBankAttacker) == SIDE_OPPONENT
            && !(gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_SECRET_BASE
                                  | BATTLE_TYPE_x2000000))))
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        u8 sideAttacker = GetBankSide(gBankAttacker);
        u8 sideTarget = GetBankSide(gBankTarget);

        // you can't swap items if they were knocked off in regular battles
        if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK
                             | BATTLE_TYPE_EREADER_TRAINER
                             | BATTLE_TYPE_FRONTIER
                             | BATTLE_TYPE_SECRET_BASE
                             | BATTLE_TYPE_x2000000))
            && (gWishFutureKnock.knockedOffPokes[sideAttacker] & gBitTable[gBattlePartyID[gBankAttacker]]
                || gWishFutureKnock.knockedOffPokes[sideTarget] & gBitTable[gBattlePartyID[gBankTarget]]))
        {
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        }
        // can't swap if two pokemon don't have an item
        // or if either of them is an enigma berry or a mail
        else if ((gBattleMons[gBankAttacker].item == 0 && gBattleMons[gBankTarget].item == 0)
                 || gBattleMons[gBankAttacker].item == ITEM_ENIGMA_BERRY
                 || gBattleMons[gBankTarget].item == ITEM_ENIGMA_BERRY
                 || IS_ITEM_MAIL(gBattleMons[gBankAttacker].item)
                 || IS_ITEM_MAIL(gBattleMons[gBankTarget].item))
        {
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        }
        // check if ability prevents swapping
        else if (gBattleMons[gBankTarget].ability == ABILITY_STICKY_HOLD)
        {
            gBattlescriptCurrInstr = BattleScript_StickyHoldActivates;
            gLastUsedAbility = gBattleMons[gBankTarget].ability;
            RecordAbilityBattle(gBankTarget, gLastUsedAbility);
        }
        // took a while, but all checks passed and items can be safely swapped
        else
        {
            u16 oldItemAtk, *newItemAtk;

            newItemAtk = &gBattleStruct->changedItems[gBankAttacker];
            oldItemAtk = gBattleMons[gBankAttacker].item;
            *newItemAtk = gBattleMons[gBankTarget].item;

            gBattleMons[gBankAttacker].item = 0;
            gBattleMons[gBankTarget].item = oldItemAtk;

            gActiveBank = gBankAttacker;
            EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, newItemAtk);
            MarkBufferBankForExecution(gBankAttacker);

            gActiveBank = gBankTarget;
            EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gBankTarget].item);
            MarkBufferBankForExecution(gBankTarget);

            *(u8*)((u8*)(&gBattleStruct->choicedMove[gBankTarget]) + 0) = 0;
            *(u8*)((u8*)(&gBattleStruct->choicedMove[gBankTarget]) + 1) = 0;

            *(u8*)((u8*)(&gBattleStruct->choicedMove[gBankAttacker]) + 0) = 0;
            *(u8*)((u8*)(&gBattleStruct->choicedMove[gBankAttacker]) + 1) = 0;

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

static void atkD3_copy_ability(void) // role play
{
    if (gBattleMons[gBankTarget].ability != 0
        && gBattleMons[gBankTarget].ability != ABILITY_WONDER_GUARD)
    {
        gBattleMons[gBankAttacker].ability = gBattleMons[gBankTarget].ability;
        gLastUsedAbility = gBattleMons[gBankTarget].ability;
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkD4_wish_effect(void)
{
    switch (gBattlescriptCurrInstr[1])
    {
    case 0: // use wish
        if (gWishFutureKnock.wishCounter[gBankAttacker] == 0)
        {
            gWishFutureKnock.wishCounter[gBankAttacker] = 2;
            gWishFutureKnock.wishUserID[gBankAttacker] = gBattlePartyID[gBankAttacker];
            gBattlescriptCurrInstr += 6;
        }
        else
        {
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
        }
        break;
    case 1: // heal effect
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gBankTarget, gWishFutureKnock.wishUserID[gBankTarget])

        gBattleMoveDamage = gBattleMons[gBankTarget].maxHP / 2;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1;
        gBattleMoveDamage *= -1;

        if (gBattleMons[gBankTarget].hp == gBattleMons[gBankTarget].maxHP)
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
        else
            gBattlescriptCurrInstr += 6;

        break;
    }
}

static void atkD5_setroots(void) // ingrain
{
    if (gStatuses3[gBankAttacker] & STATUS3_ROOTED)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gStatuses3[gBankAttacker] |= STATUS3_ROOTED;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkD6_doubledamagedealtifdamaged(void)
{
    if ((gProtectStructs[gBankAttacker].physicalDmg
         && gProtectStructs[gBankAttacker].physicalBank == gBankTarget)
        || (gProtectStructs[gBankAttacker].specialDmg
            && gProtectStructs[gBankAttacker].specialBank == gBankTarget))
    {
        gBattleScripting.dmgMultiplier = 2;
    }

    gBattlescriptCurrInstr++;
}

static void atkD7_setyawn(void)
{
    if (gStatuses3[gBankTarget] & STATUS3_YAWN
        || gBattleMons[gBankTarget].status1 & STATUS_ANY)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gStatuses3[gBankTarget] |= 0x1000;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkD8_setdamagetohealthdifference(void)
{
    if (gBattleMons[gBankTarget].hp <= gBattleMons[gBankAttacker].hp)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gBattleMoveDamage = gBattleMons[gBankTarget].hp - gBattleMons[gBankAttacker].hp;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkD9_scaledamagebyhealthratio(void)
{
    if (gDynamicBasePower == 0)
    {
        u8 power = gBattleMoves[gCurrentMove].power;
        gDynamicBasePower = gBattleMons[gBankAttacker].hp * power / gBattleMons[gBankAttacker].maxHP;
        if (gDynamicBasePower == 0)
            gDynamicBasePower = 1;
    }
    gBattlescriptCurrInstr++;
}

static void atkDA_abilityswap(void) // skill swap
{
    if ((gBattleMons[gBankAttacker].ability == 0
         && gBattleMons[gBankTarget].ability == 0)
     || gBattleMons[gBankAttacker].ability == ABILITY_WONDER_GUARD
     || gBattleMons[gBankTarget].ability == ABILITY_WONDER_GUARD
     || gBattleMoveFlags & MOVESTATUS_NOEFFECT)
     {
         gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
     }
    else
    {
        u8 abilityAtk = gBattleMons[gBankAttacker].ability;
        gBattleMons[gBankAttacker].ability = gBattleMons[gBankTarget].ability;
        gBattleMons[gBankTarget].ability = abilityAtk;

            gBattlescriptCurrInstr += 5;
    }
}

static void atkDB_imprisoneffect(void)
{
    if ((gStatuses3[gBankAttacker] & STATUS3_IMPRISONED_OTHERS))
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        u8 bank, sideAttacker;

        sideAttacker = GetBankSide(gBankAttacker);
        PressurePPLoseOnUsingImprision(gBankAttacker);
        for (bank = 0; bank < gNoOfAllBanks; bank++)
        {
            if (sideAttacker != GetBankSide(bank))
            {
                s32 attackerMoveId;
                for (attackerMoveId = 0; attackerMoveId < 4; attackerMoveId++)
                {
                    s32 i;
                    for (i = 0; i < 4; i++)
                    {
                        if (gBattleMons[gBankAttacker].moves[attackerMoveId] == gBattleMons[bank].moves[i]
                            && gBattleMons[gBankAttacker].moves[attackerMoveId] != MOVE_NONE)
                            break;
                    }
                    if (i != 4)
                        break;
                }
                if (attackerMoveId != 4)
                {
                    gStatuses3[gBankAttacker] |= STATUS3_IMPRISONED_OTHERS;
                    gBattlescriptCurrInstr += 5;
                    break;
                }
            }
        }
        if (bank == gNoOfAllBanks) // In Generation 3 games, Imprison fails if the user doesn't share any moves with any of the foes
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkDC_setgrudge(void)
{
    if (gStatuses3[gBankAttacker] & STATUS3_GRUDGE)
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gStatuses3[gBankAttacker] |= STATUS3_GRUDGE;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkDD_weightdamagecalculation(void)
{
    s32 i;
    for (i = 0; sWeightToDamageTable[i] != 0xFFFF; i += 2)
    {
        if (sWeightToDamageTable[i] > GetPokedexHeightWeight(SpeciesToNationalPokedexNum(gBattleMons[gBankTarget].species), 1))
            break;
    }

    if (sWeightToDamageTable[i] != 0xFFFF)
        gDynamicBasePower = sWeightToDamageTable[i + 1];
    else
        gDynamicBasePower = 120;

    gBattlescriptCurrInstr++;
}

static void atkDE_asistattackselect(void)
{
    s32 chooseableMovesNo = 0;
    struct Pokemon* party;
    s32 monId, moveId;
    u16* movesArray = gBattleStruct->assistPossibleMoves;

    if (GET_BANK_SIDE(gBankAttacker) != SIDE_PLAYER)
        party = gEnemyParty;
    else
        party = gPlayerParty;

    for (monId = 0; monId < 6; monId++)
    {
        if (monId == gBattlePartyID[gBankAttacker])
            continue;
        if (GetMonData(&party[monId], MON_DATA_SPECIES2) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[monId], MON_DATA_SPECIES2) == SPECIES_EGG)
            continue;

        for (moveId = 0; moveId < 4; moveId++)
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
        gRandomMove = movesArray[((Random() & 0xFF) * chooseableMovesNo) >> 8];
        gBankTarget = GetMoveTarget(gRandomMove, 0);
        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkDF_setmagiccoat(void)
{
    gBankTarget = gBankAttacker;
    gSpecialStatuses[gBankAttacker].flag20 = 1;
    if (gCurrentMoveTurn == gNoOfAllBanks - 1) // moves last turn
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gProtectStructs[gBankAttacker].bounceMove = 1;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkE0_setstealstatchange(void) // snatch
{
    gSpecialStatuses[gBankAttacker].flag20 = 1;
    if (gCurrentMoveTurn == gNoOfAllBanks - 1) // moves last turn
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        gProtectStructs[gBankAttacker].stealMove = 1;
        gBattlescriptCurrInstr += 5;
    }
}

static void atkE1_intimidate_string_loader(void)
{
    u8 side;

    gBattleScripting.bank = gBattleStruct->intimidateBank;
    side = GetBankSide(gBattleScripting.bank);

    PREPARE_ABILITY_BUFFER(gBattleTextBuff1, gBattleMons[gBattleScripting.bank].ability)

    for (;gBankTarget < gNoOfAllBanks; gBankTarget++)
    {
        if (GetBankSide(gBankTarget) == side)
            continue;
        if (!(gAbsentBankFlags & gBitTable[gBankTarget]))
            break;
    }

    if (gBankTarget >= gNoOfAllBanks)
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    else
        gBattlescriptCurrInstr += 5;
}

static void atkE2_switchout_abilities(void)
{
    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    switch (gBattleMons[gActiveBank].ability)
    {
    case ABILITY_NATURAL_CURE:
        gBattleMons[gActiveBank].status1 = 0;
        EmitSetMonData(0, REQUEST_STATUS_BATTLE, gBitTable[*(gBattleStruct->field_58 + gActiveBank)], 4, &gBattleMons[gActiveBank].status1);
        MarkBufferBankForExecution(gActiveBank);
        break;
    }

    gBattlescriptCurrInstr += 2;
}

static void atkE3_jumpifhasnohp(void)
{
    gActiveBank = GetBattleBank(gBattlescriptCurrInstr[1]);

    if (gBattleMons[gActiveBank].hp == 0)
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 2);
    else
        gBattlescriptCurrInstr += 6;
}

static void atkE4_getsecretpowereffect(void)
{
    switch (gBattleTerrain)
    {
    case BATTLE_TERRAIN_GRASS:
        gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_POISON;
        break;
    case BATTLE_TERRAIN_LONG_GRASS:
        gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_SLEEP;
        break;
    case BATTLE_TERRAIN_SAND:
        gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_ACC_MINUS_1;
        break;
    case BATTLE_TERRAIN_UNDERWATER:
        gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_DEF_MINUS_1;
        break;
    case BATTLE_TERRAIN_WATER:
        gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_ATK_MINUS_1;
        break;
    case BATTLE_TERRAIN_POND:
        gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_SPD_MINUS_1;
        break;
    case BATTLE_TERRAIN_ROCK:
        gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_CONFUSION;
        break;
    case BATTLE_TERRAIN_CAVE:
        gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_FLINCH;
        break;
    default:
        gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_PARALYSIS;
        break;
    }
    gBattlescriptCurrInstr++;
}

static void atkE5_pickup(void)
{
    if (!InBattlePike())
    {
        s32 i;
        u16 species, heldItem;
        u8 ability;

        if (InBattlePyramid())
        {
            for (i = 0; i < 6; i++)
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
            for (i = 0; i < 6; i++)
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
                    s32 j;
                    s32 rand = Random() % 100;
                    u8 lvlDivBy10 = (GetMonData(&gPlayerParty[i], MON_DATA_LEVEL) - 1) / 10;
                    if (lvlDivBy10 > 9)
                        lvlDivBy10 = 9;

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
    }

    gBattlescriptCurrInstr++;
}

static void atkE6_castform_change_animation(void)
{
    gActiveBank = gBattleScripting.bank;

    if (gBattleMons[gActiveBank].status2 & STATUS2_SUBSTITUTE)
        *(&gBattleStruct->formToChangeInto) |= 0x80;

    EmitBattleAnimation(0, B_ANIM_CASTFORM_CHANGE, gBattleStruct->formToChangeInto);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr++;
}

static void atkE7_castform_data_change(void)
{
    u8 form;

    gBattlescriptCurrInstr++;
    form = CastformDataTypeChange(gBattleScripting.bank);
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
        if (!(gStatuses3[gBankAttacker] & STATUS3_MUDSPORT))
        {
            gStatuses3[gBankAttacker] |= STATUS3_MUDSPORT;
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            worked = TRUE;
        }
    }
    else // water sport
    {
        if (!(gStatuses3[gBankAttacker] & STATUS3_WATERSPORT))
        {
            gStatuses3[gBankAttacker] |= STATUS3_WATERSPORT;
            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
            worked = TRUE;
        }
    }

    if (worked)
        gBattlescriptCurrInstr += 5;
    else
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
}

static void atkE9_setweatherballtype(void)
{
    if (WEATHER_HAS_EFFECT)
    {
        if (gBattleWeather & WEATHER_ANY)
            gBattleScripting.dmgMultiplier = 2;
        if (gBattleWeather & WEATHER_RAIN_ANY)
            *(&gBattleStruct->dynamicMoveType) = TYPE_WATER | 0x80;
        else if (gBattleWeather & WEATHER_SANDSTORM_ANY)
            *(&gBattleStruct->dynamicMoveType) = TYPE_ROCK | 0x80;
        else if (gBattleWeather & WEATHER_SUN_ANY)
            *(&gBattleStruct->dynamicMoveType) = TYPE_FIRE | 0x80;
        else if (gBattleWeather & WEATHER_HAIL_ANY)
            *(&gBattleStruct->dynamicMoveType) = TYPE_ICE | 0x80;
        else
            *(&gBattleStruct->dynamicMoveType) = TYPE_NORMAL | 0x80;
    }

    gBattlescriptCurrInstr++;
}

static void atkEA_recycleitem(void)
{
    u16 *usedHeldItem;

    gActiveBank = gBankAttacker;
    usedHeldItem = &gBattleStruct->usedHeldItems[gActiveBank];
    if (*usedHeldItem != 0 && gBattleMons[gActiveBank].item == 0)
    {
        gLastUsedItem = *usedHeldItem;
        *usedHeldItem = 0;
        gBattleMons[gActiveBank].item = gLastUsedItem;

        EmitSetMonData(0, REQUEST_HELDITEM_BATTLE, 0, 2, &gBattleMons[gActiveBank].item);
        MarkBufferBankForExecution(gActiveBank);

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkEB_settypetoterrain(void)
{
    if (gBattleMons[gBankAttacker].type1 != sTerrainToType[gBattleTerrain]
        && gBattleMons[gBankAttacker].type2 != sTerrainToType[gBattleTerrain])
    {
        gBattleMons[gBankAttacker].type1 = sTerrainToType[gBattleTerrain];
        gBattleMons[gBankAttacker].type2 = sTerrainToType[gBattleTerrain];

        PREPARE_TYPE_BUFFER(gBattleTextBuff1, sTerrainToType[gBattleTerrain])

        gBattlescriptCurrInstr += 5;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkEC_pursuit_sth(void)
{
    gActiveBank = GetBankByIdentity(GetBankIdentity(gBankAttacker) ^ BIT_MON);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
        && !(gAbsentBankFlags & gBitTable[gActiveBank])
        && gActionForBanks[gActiveBank] == 0
        && gChosenMovesByBanks[gActiveBank] == MOVE_PURSUIT)
    {
        gUnknown_0202407A[gActiveBank] = 11;
        gCurrentMove = MOVE_PURSUIT;
        gBattlescriptCurrInstr += 5;
        gBattleScripting.animTurn = 1;
        gBattleScripting.field_20 = gBankAttacker;
        gBankAttacker = gActiveBank;
    }
    else
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
}

static void atkED_802B4B4(void)
{
    gEffectBank = gBankAttacker;

    if (gBankAttacker == gBankTarget)
        gBankAttacker = gBankTarget = gBattleScripting.bank;
    else
        gBankTarget = gBattleScripting.bank;

    gBattleScripting.bank = gEffectBank;
    gBattlescriptCurrInstr++;
}

static void atkEE_removelightscreenreflect(void) // brick break
{
    u8 opposingSide = GetBankSide(gBankAttacker) ^ BIT_SIDE;

    if (gSideTimers[opposingSide].reflectTimer || gSideTimers[opposingSide].lightscreenTimer)
    {
        gSideAffecting[opposingSide] &= ~(SIDE_STATUS_REFLECT);
        gSideAffecting[opposingSide] &= ~(SIDE_STATUS_LIGHTSCREEN);
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

static void atkEF_pokeball_catch_calculation(void)
{
    u8 ballMultiplier = 0;

    if (gBattleExecBuffer)
        return;

    gActiveBank = gBankAttacker;
    gBankTarget = gBankAttacker ^ BIT_SIDE;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        EmitBallThrow(0, BALL_TRAINER_BLOCK);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr = BattleScript_TrainerBallBlock;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
    {
        EmitBallThrow(0, BALL_3_SHAKES_SUCCESS);
        MarkBufferBankForExecution(gActiveBank);
        gBattlescriptCurrInstr = BattleScript_WallyBallThrow;
    }
    else
    {
        u32 odds;
        u8 catchRate;

        if (gLastUsedItem == ITEM_SAFARI_BALL)
            catchRate = gBattleStruct->field_7C * 1275 / 100;
        else
            catchRate = gBaseStats[gBattleMons[gBankTarget].species].catchRate;

        if (gLastUsedItem > ITEM_SAFARI_BALL)
        {
            switch (gLastUsedItem)
            {
            case ITEM_NET_BALL:
                if (gBattleMons[gBankTarget].type1 == TYPE_WATER
                    || gBattleMons[gBankTarget].type2 == TYPE_WATER
                    || gBattleMons[gBankTarget].type1 == TYPE_BUG
                    || gBattleMons[gBankTarget].type2 == TYPE_BUG)
                    ballMultiplier = 30;
                else
                    ballMultiplier = 10;
                break;
            case ITEM_DIVE_BALL:
                if (sav1_map_get_light_level() == 5)
                    ballMultiplier = 35;
                else
                    ballMultiplier = 10;
                break;
            case ITEM_NEST_BALL:
                if (gBattleMons[gBankTarget].level < 40)
                {
                    ballMultiplier = 40 - gBattleMons[gBankTarget].level;
                    if (ballMultiplier <= 9)
                        ballMultiplier = 10;
                }
                else
                {
                    ballMultiplier = 10;
                }
                break;
            case ITEM_REPEAT_BALL:
                if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gBankTarget].species), FLAG_GET_CAUGHT))
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
            * (gBattleMons[gBankTarget].maxHP * 3 - gBattleMons[gBankTarget].hp * 2)
            / (3 * gBattleMons[gBankTarget].maxHP);

        if (gBattleMons[gBankTarget].status1 & (STATUS_SLEEP | STATUS_FREEZE))
            odds *= 2;
        if (gBattleMons[gBankTarget].status1 & (STATUS_POISON | STATUS_BURN | STATUS_PARALYSIS | STATUS_TOXIC_POISON))
            odds = (odds * 15) / 10;

        if (gLastUsedItem != ITEM_SAFARI_BALL)
        {
            if (gLastUsedItem == ITEM_MASTER_BALL)
            {
                gBattleResults.unk5_1 = 1;
            }
            else
            {
                if (gBattleResults.catchAttempts[gLastUsedItem - ITEM_ULTRA_BALL] < 0xFF)
                    gBattleResults.catchAttempts[gLastUsedItem - ITEM_ULTRA_BALL]++;
            }
        }

        if (odds > 254) // mon caught
        {
            EmitBallThrow(0, BALL_3_SHAKES_SUCCESS);
            MarkBufferBankForExecution(gActiveBank);
            gBattlescriptCurrInstr = BattleScript_SuccessBallThrow;
            SetMonData(&gEnemyParty[gBattlePartyID[gBankTarget]], MON_DATA_POKEBALL, &gLastUsedItem);

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

            EmitBallThrow(0, shakes);
            MarkBufferBankForExecution(gActiveBank);

            if (shakes == BALL_3_SHAKES_SUCCESS) // mon caught, copy of the code above
            {
                gBattlescriptCurrInstr = BattleScript_SuccessBallThrow;
                SetMonData(&gEnemyParty[gBattlePartyID[gBankTarget]], MON_DATA_POKEBALL, &gLastUsedItem);

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

static void atkF0_give_caught_mon(void)
{
    if (GiveMonToPlayer(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]]) != MON_GIVEN_TO_PARTY)
    {
        if (!sub_813B21C())
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = 0;
            StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_STORAGE_UNKNOWN)));
            GetMonData(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]], MON_DATA_NICKNAME, gStringVar2);
        }
        else
        {
            StringCopy(gStringVar1, GetBoxNamePtr(VarGet(VAR_STORAGE_UNKNOWN)));
            GetMonData(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]], MON_DATA_NICKNAME, gStringVar2);
            StringCopy(gStringVar3, GetBoxNamePtr(get_unknown_box_id()));
            gBattleCommunication[MULTISTRING_CHOOSER] = 2;
        }

        if (FlagGet(SYS_PC_LANETTE))
            gBattleCommunication[MULTISTRING_CHOOSER]++;
    }

    gBattleResults.caughtMonSpecies = GetMonData(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]], MON_DATA_SPECIES, NULL);
    GetMonData(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]], MON_DATA_NICKNAME, gBattleResults.caughtMonNick);
    gBattleResults.caughtMonBall = GetMonData(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]], MON_DATA_POKEBALL, NULL);

    gBattlescriptCurrInstr++;
}

static void atkF1_set_caught_mon_dex_flags(void)
{
    u16 species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL);
    u32 personality = GetMonData(&gEnemyParty[0], MON_DATA_PERSONALITY, NULL);

    if (GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT))
    {
        gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
    }
    else
    {
        HandleSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_SET_CAUGHT, personality);
        gBattlescriptCurrInstr += 5;
    }
}

static void atkF2_display_dex_info(void)
{
    u16 species = GetMonData(&gEnemyParty[0], MON_DATA_SPECIES, NULL);

    switch (gBattleCommunication[0])
    {
    case 0:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        gBattleCommunication[0]++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            FreeAllWindowBuffers();
            gBattleCommunication[TASK_ID] = CreateDexDisplayMonDataTask(SpeciesToNationalPokedexNum(species),
                                                                        gBattleMons[gBankTarget].otId,
                                                                        gBattleMons[gBankTarget].personality);
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
        c2_berry_program_update_menu();
        sub_8035AA4();
        gBattle_BG3_X = 0x100;
        gBattleCommunication[0]++;
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            BeginNormalPaletteFade(0xFFFF, 0, 0x10, 0, 0);
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

void sub_8056A3C(u8 xStart, u8 yStart, u8 xEnd, u8 yEnd, u8 flags)
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

            if (flags & 1)
                var = 0;

            if (flags & 0x80)
                CopyToBgTilemapBufferRect_ChangePalette(1, &var, destX, destY, 1, 1, 0x11);
            else
                CopyToBgTilemapBufferRect_ChangePalette(0, &var, destX, destY, 1, 1, 0x11);
        }
    }
}

void BattleCreateCursorAt(u8 cursorPosition)
{
    u16 src[2];
    src[0] = 1;
    src[1] = 2;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 0x19, 9 + (2 * cursorPosition), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);
}

void BattleDestroyCursorAt(u8 cursorPosition)
{
    u16 src[2];
    src[0] = 0x1016;
    src[1] = 0x1016;

    CopyToBgTilemapBufferRect_ChangePalette(0, src, 0x19, 9 + (2 * cursorPosition), 1, 2, 0x11);
    CopyBgTilemapBufferToVram(0);
}

static void atkF3_nickname_caught_poke(void)
{
    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        sub_8056A3C(0x18, 8, 0x1D, 0xD, 0);
        sub_814F9EC(gText_BattleYesNoChoice, 0xC);
        gBattleCommunication[MULTIUSE_STATE]++;
        gBattleCommunication[CURSOR_POSITION] = 0;
        BattleCreateCursorAt(0);
        break;
    case 1:
        if (gMain.newKeys & DPAD_UP && gBattleCommunication[CURSOR_POSITION] != 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 0;
            BattleCreateCursorAt(0);
        }
        if (gMain.newKeys & DPAD_DOWN && gBattleCommunication[CURSOR_POSITION] == 0)
        {
            PlaySE(SE_SELECT);
            BattleDestroyCursorAt(gBattleCommunication[CURSOR_POSITION]);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateCursorAt(1);
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
            GetMonData(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]], MON_DATA_NICKNAME, gBattleStruct->caughtMonNick);
            FreeAllWindowBuffers();

            DoNamingScreen(NAMING_SCREEN_CAUGHT_MON, gBattleStruct->caughtMonNick,
                           GetMonData(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]], MON_DATA_SPECIES),
                           GetMonGender(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]]),
                           GetMonData(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]], MON_DATA_PERSONALITY, NULL),
                           BattleMainCB2);

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active )
        {
            SetMonData(&gEnemyParty[gBattlePartyID[gBankAttacker ^ BIT_SIDE]], MON_DATA_NICKNAME, gBattleStruct->caughtMonNick);
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        }
        break;
    case 4:
        if (CalculatePlayerPartyCount() == 6)
            gBattlescriptCurrInstr += 5;
        else
            gBattlescriptCurrInstr = BSScriptReadPtr(gBattlescriptCurrInstr + 1);
        break;
    }
}

static void atkF4_subattackerhpbydmg(void)
{
    gBattleMons[gBankAttacker].hp -= gBattleMoveDamage;
    gBattlescriptCurrInstr++;
}

static void atkF5_removeattackerstatus1(void)
{
    gBattleMons[gBankAttacker].status1 = 0;
    gBattlescriptCurrInstr++;
}

static void atkF6_802BF48(void)
{
    gFightStateTracker = 0xC;
}

static void atkF7_802BF54(void)
{
    gFightStateTracker = 0xC;
    gCurrentMoveTurn = gNoOfAllBanks;
}

static void atkF8_trainer_slide_back(void)
{
    gActiveBank = GetBankByIdentity(gBattlescriptCurrInstr[1]);
    EmitTrainerSlideBack(0);
    MarkBufferBankForExecution(gActiveBank);

    gBattlescriptCurrInstr += 2;
}
