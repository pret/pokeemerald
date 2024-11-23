#include "config.h"
#include "constants/battle.h"
#include "constants/battle_ai.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_ai_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gBattleAI_ScriptsTable::
	.4byte AI_CheckBadMove          @ AI_SCRIPT_CHECK_BAD_MOVE
	.4byte AI_TryToFaint            @ AI_SCRIPT_TRY_TO_FAINT
	.4byte AI_CheckViability        @ AI_SCRIPT_CHECK_VIABILITY
	.4byte AI_SetupFirstTurn        @ AI_SCRIPT_SETUP_FIRST_TURN
	.4byte AI_Risky                 @ AI_SCRIPT_RISKY
	.4byte AI_PreferPowerExtremes   @ AI_SCRIPT_PREFER_POWER_EXTREMES
	.4byte AI_PreferBatonPass       @ AI_SCRIPT_PREFER_BATON_PASS
	.4byte AI_DoubleBattle 	        @ AI_SCRIPT_DOUBLE_BATTLE
	.4byte AI_HPAware               @ AI_SCRIPT_HP_AWARE
	.4byte AI_TrySunnyDayStart      @ AI_SCRIPT_TRY_SUNNY_DAY_START
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Ret
	.4byte AI_Roaming               @ AI_SCRIPT_ROAMING
	.4byte AI_Safari                @ AI_SCRIPT_SAFARI
	.4byte AI_FirstBattle           @ AI_SCRIPT_FIRST_BATTLE

AI_CheckBadMove:
	if_target_is_ally AI_Ret
	if_move MOVE_FISSURE, AI_CBM_CheckIfNegatesType
	if_move MOVE_HORN_DRILL, AI_CBM_CheckIfNegatesType
	get_how_powerful_move_is
	if_equal MOVE_POWER_OTHER, AI_CheckBadMove_CheckSoundproof
AI_CBM_CheckIfNegatesType:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_VOLT_ABSORB, CheckIfVoltAbsorbCancelsElectric
	if_equal ABILITY_WATER_ABSORB, CheckIfWaterAbsorbCancelsWater
	if_equal ABILITY_FLASH_FIRE, CheckIfFlashFireCancelsFire
	if_equal ABILITY_WONDER_GUARD, CheckIfWonderGuardCancelsMove
	if_equal ABILITY_LEVITATE, CheckIfLevitateCancelsGroundMove
	goto AI_CheckBadMove_CheckSoundproof_

CheckIfVoltAbsorbCancelsElectric:
	get_curr_move_type
	if_equal_ TYPE_ELECTRIC, Score_Minus12
	goto AI_CheckBadMove_CheckSoundproof_

CheckIfWaterAbsorbCancelsWater:
	get_curr_move_type
	if_equal_ TYPE_WATER, Score_Minus12
	goto AI_CheckBadMove_CheckSoundproof_

CheckIfFlashFireCancelsFire:
	get_curr_move_type
	if_equal_ TYPE_FIRE, Score_Minus12
	goto AI_CheckBadMove_CheckSoundproof_

CheckIfWonderGuardCancelsMove:
	if_type_effectiveness AI_EFFECTIVENESS_x2, AI_CheckBadMove_CheckSoundproof_
	goto Score_Minus10

CheckIfLevitateCancelsGroundMove:
	get_curr_move_type
	if_equal_ TYPE_GROUND, Score_Minus10
AI_CheckBadMove_CheckSoundproof_:
	get_how_powerful_move_is
	if_equal MOVE_POWER_OTHER, AI_CheckBadMove_CheckSoundproof  @ Pointless check
AI_CheckBadMove_CheckSoundproof:
	get_ability AI_TARGET
	if_not_equal ABILITY_SOUNDPROOF, AI_CheckBadMove_CheckEffect
	if_move MOVE_GROWL, Score_Minus10
	if_move MOVE_ROAR, Score_Minus10
	if_move MOVE_SING, Score_Minus10
	if_move MOVE_SUPERSONIC, Score_Minus10
	if_move MOVE_SCREECH, Score_Minus10
	if_move MOVE_SNORE, Score_Minus10
	if_move MOVE_UPROAR, Score_Minus10
	if_move MOVE_METAL_SOUND, Score_Minus10
	if_move MOVE_GRASS_WHISTLE, Score_Minus10
AI_CheckBadMove_CheckEffect:
	if_effect EFFECT_SLEEP, AI_CBM_Sleep
	if_effect EFFECT_EXPLOSION, AI_CBM_Explosion
	if_effect EFFECT_DREAM_EATER, AI_CBM_DreamEater
	if_effect EFFECT_ATTACK_UP, AI_CBM_AttackUp
	if_effect EFFECT_DEFENSE_UP, AI_CBM_DefenseUp
	if_effect EFFECT_SPEED_UP, AI_CBM_SpeedUp
	if_effect EFFECT_SPECIAL_ATTACK_UP, AI_CBM_SpAtkUp
	if_effect EFFECT_SPECIAL_DEFENSE_UP, AI_CBM_SpDefUp
	if_effect EFFECT_ACCURACY_UP, AI_CBM_AccUp
	if_effect EFFECT_EVASION_UP, AI_CBM_EvasionUp
	if_effect EFFECT_ATTACK_DOWN, AI_CBM_AttackDown
	if_effect EFFECT_DEFENSE_DOWN, AI_CBM_DefenseDown
	if_effect EFFECT_SPEED_DOWN, AI_CBM_SpeedDown
	if_effect EFFECT_SPECIAL_ATTACK_DOWN, AI_CBM_SpAtkDown
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN, AI_CBM_SpDefDown
	if_effect EFFECT_ACCURACY_DOWN, AI_CBM_AccDown
	if_effect EFFECT_EVASION_DOWN, AI_CBM_EvasionDown
	if_effect EFFECT_HAZE, AI_CBM_Haze
	if_effect EFFECT_BIDE, AI_CBM_HighRiskForDamage
	if_effect EFFECT_ROAR, AI_CBM_Roar
	if_effect EFFECT_TOXIC, AI_CBM_Toxic
	if_effect EFFECT_LIGHT_SCREEN, AI_CBM_LightScreen
	if_effect EFFECT_OHKO, AI_CBM_OneHitKO
	if_effect EFFECT_RAZOR_WIND, AI_CBM_HighRiskForDamage
	if_effect EFFECT_SUPER_FANG, AI_CBM_HighRiskForDamage
	if_effect EFFECT_MIST, AI_CBM_Mist
	if_effect EFFECT_FOCUS_ENERGY, AI_CBM_FocusEnergy
	if_effect EFFECT_CONFUSE, AI_CBM_Confuse
	if_effect EFFECT_ATTACK_UP_2, AI_CBM_AttackUp
	if_effect EFFECT_DEFENSE_UP_2, AI_CBM_DefenseUp
	if_effect EFFECT_SPEED_UP_2, AI_CBM_SpeedUp
	if_effect EFFECT_SPECIAL_ATTACK_UP_2, AI_CBM_SpAtkUp
	if_effect EFFECT_SPECIAL_DEFENSE_UP_2, AI_CBM_SpDefUp
	if_effect EFFECT_ACCURACY_UP_2, AI_CBM_AccUp
	if_effect EFFECT_EVASION_UP_2, AI_CBM_EvasionUp
	if_effect EFFECT_ATTACK_DOWN_2, AI_CBM_AttackDown
	if_effect EFFECT_DEFENSE_DOWN_2, AI_CBM_DefenseDown
	if_effect EFFECT_SPEED_DOWN_2, AI_CBM_SpeedDown
	if_effect EFFECT_SPECIAL_ATTACK_DOWN_2, AI_CBM_SpAtkDown
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN_2, AI_CBM_SpDefDown
	if_effect EFFECT_ACCURACY_DOWN_2, AI_CBM_AccDown
	if_effect EFFECT_EVASION_DOWN_2, AI_CBM_EvasionDown
	if_effect EFFECT_REFLECT, AI_CBM_Reflect
	if_effect EFFECT_POISON, AI_CBM_Toxic
	if_effect EFFECT_PARALYZE, AI_CBM_Paralyze
	if_effect EFFECT_SUBSTITUTE, AI_CBM_Substitute
	if_effect EFFECT_RECHARGE, AI_CBM_HighRiskForDamage
	if_effect EFFECT_LEECH_SEED, AI_CBM_LeechSeed
	if_effect EFFECT_DISABLE, AI_CBM_Disable
	if_effect EFFECT_LEVEL_DAMAGE, AI_CBM_HighRiskForDamage
	if_effect EFFECT_PSYWAVE, AI_CBM_HighRiskForDamage
	if_effect EFFECT_COUNTER, AI_CBM_HighRiskForDamage
	if_effect EFFECT_ENCORE, AI_CBM_Encore
	if_effect EFFECT_SNORE, AI_CBM_DamageDuringSleep
	if_effect EFFECT_SLEEP_TALK, AI_CBM_DamageDuringSleep
	if_effect EFFECT_FLAIL, AI_CBM_HighRiskForDamage
	if_effect EFFECT_MEAN_LOOK, AI_CBM_CantEscape
	if_effect EFFECT_NIGHTMARE, AI_CBM_Nightmare
	if_effect EFFECT_MINIMIZE, AI_CBM_EvasionUp
	if_effect EFFECT_CURSE, AI_CBM_Curse
	if_effect EFFECT_SPIKES, AI_CBM_Spikes
	if_effect EFFECT_FORESIGHT, AI_CBM_Foresight
	if_effect EFFECT_PERISH_SONG, AI_CBM_PerishSong
	if_effect EFFECT_SANDSTORM, AI_CBM_Sandstorm
	if_effect EFFECT_SWAGGER, AI_CBM_Confuse
	if_effect EFFECT_ATTRACT, AI_CBM_Attract
	if_effect EFFECT_RETURN, AI_CBM_HighRiskForDamage
	if_effect EFFECT_PRESENT, AI_CBM_HighRiskForDamage
	if_effect EFFECT_FRUSTRATION, AI_CBM_HighRiskForDamage
	if_effect EFFECT_SAFEGUARD, AI_CBM_Safeguard
	if_effect EFFECT_MAGNITUDE, AI_CBM_Magnitude
	if_effect EFFECT_BATON_PASS, AI_CBM_BatonPass
	if_effect EFFECT_SONICBOOM, AI_CBM_HighRiskForDamage
	if_effect EFFECT_RAIN_DANCE, AI_CBM_RainDance
	if_effect EFFECT_SUNNY_DAY, AI_CBM_SunnyDay
	if_effect EFFECT_BELLY_DRUM, AI_CBM_BellyDrum
	if_effect EFFECT_PSYCH_UP, AI_CBM_Haze
	if_effect EFFECT_MIRROR_COAT, AI_CBM_HighRiskForDamage
	if_effect EFFECT_SKULL_BASH, AI_CBM_HighRiskForDamage
	if_effect EFFECT_FUTURE_SIGHT, AI_CBM_FutureSight
	if_effect EFFECT_TELEPORT, Score_Minus10
	if_effect EFFECT_DEFENSE_CURL, AI_CBM_DefenseUp
	if_effect EFFECT_FAKE_OUT, AI_CBM_FakeOut
	if_effect EFFECT_STOCKPILE, AI_CBM_Stockpile
	if_effect EFFECT_SPIT_UP, AI_CBM_SpitUpAndSwallow
	if_effect EFFECT_SWALLOW, AI_CBM_SpitUpAndSwallow
	if_effect EFFECT_HAIL, AI_CBM_Hail
	if_effect EFFECT_TORMENT, AI_CBM_Torment
	if_effect EFFECT_FLATTER, AI_CBM_Confuse
	if_effect EFFECT_WILL_O_WISP, AI_CBM_WillOWisp
	if_effect EFFECT_MEMENTO, AI_CBM_Memento
	if_effect EFFECT_FOCUS_PUNCH, AI_CBM_HighRiskForDamage
	if_effect EFFECT_HELPING_HAND, AI_CBM_HelpingHand
	if_effect EFFECT_TRICK, AI_CBM_TrickAndKnockOff
	if_effect EFFECT_INGRAIN, AI_CBM_Ingrain
	if_effect EFFECT_SUPERPOWER, AI_CBM_HighRiskForDamage
	if_effect EFFECT_RECYCLE, AI_CBM_Recycle
	if_effect EFFECT_KNOCK_OFF, AI_CBM_TrickAndKnockOff
	if_effect EFFECT_ENDEAVOR, AI_CBM_HighRiskForDamage
	if_effect EFFECT_IMPRISON, AI_CBM_Imprison
	if_effect EFFECT_REFRESH, AI_CBM_Refresh
	if_effect EFFECT_LOW_KICK, AI_CBM_HighRiskForDamage
	if_effect EFFECT_MUD_SPORT, AI_CBM_MudSport
	if_effect EFFECT_TICKLE, AI_CBM_Tickle
	if_effect EFFECT_COSMIC_POWER, AI_CBM_CosmicPower
	if_effect EFFECT_BULK_UP, AI_CBM_BulkUp
	if_effect EFFECT_WATER_SPORT, AI_CBM_WaterSport
	if_effect EFFECT_CALM_MIND, AI_CBM_CalmMind
	if_effect EFFECT_DRAGON_DANCE, AI_CBM_DragonDance
	end

AI_CBM_Sleep:
	get_ability AI_TARGET
	if_equal ABILITY_INSOMNIA, Score_Minus10
	if_equal ABILITY_VITAL_SPIRIT, Score_Minus10
	if_status AI_TARGET, STATUS1_ANY, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	end

AI_CBM_Explosion:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_DAMP, Score_Minus10
	count_usable_party_mons AI_USER
	if_not_equal 0, AI_CBM_Explosion_End
	count_usable_party_mons AI_TARGET
	if_not_equal 0, Score_Minus10
	goto Score_Minus1

AI_CBM_Explosion_End:
	end

AI_CBM_Nightmare:
	if_status2 AI_TARGET, STATUS2_NIGHTMARE, Score_Minus10
	if_not_status AI_TARGET, STATUS1_SLEEP, Score_Minus8
	end

AI_CBM_DreamEater:
	if_not_status AI_TARGET, STATUS1_SLEEP, Score_Minus8
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	end

AI_CBM_BellyDrum:
	if_hp_less_than AI_USER, 51, Score_Minus10
AI_CBM_AttackUp:
	if_stat_level_equal AI_USER, STAT_ATK, MAX_STAT_STAGE, Score_Minus10
	end

AI_CBM_DefenseUp:
	if_stat_level_equal AI_USER, STAT_DEF, MAX_STAT_STAGE, Score_Minus10
	end

AI_CBM_SpeedUp:
	if_stat_level_equal AI_USER, STAT_SPEED, MAX_STAT_STAGE, Score_Minus10
	end

AI_CBM_SpAtkUp:
	if_stat_level_equal AI_USER, STAT_SPATK, MAX_STAT_STAGE, Score_Minus10
	end

AI_CBM_SpDefUp:
	if_stat_level_equal AI_USER, STAT_SPDEF, MAX_STAT_STAGE, Score_Minus10
	end

AI_CBM_AccUp:
	if_stat_level_equal AI_USER, STAT_ACC, MAX_STAT_STAGE, Score_Minus10
	end

AI_CBM_EvasionUp:
	if_stat_level_equal AI_USER, STAT_EVASION, MAX_STAT_STAGE, Score_Minus10
	end

AI_CBM_AttackDown:
	if_stat_level_equal AI_TARGET, STAT_ATK, MIN_STAT_STAGE, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_HYPER_CUTTER, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_DefenseDown:
	if_stat_level_equal AI_TARGET, STAT_DEF, MIN_STAT_STAGE, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_SpeedDown:
	if_stat_level_equal AI_TARGET, STAT_SPEED, MIN_STAT_STAGE, Score_Minus10
	if_ability AI_TARGET, ABILITY_SPEED_BOOST, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_SpAtkDown:
	if_stat_level_equal AI_TARGET, STAT_SPATK, MIN_STAT_STAGE, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_SpDefDown:
	if_stat_level_equal AI_TARGET, STAT_SPDEF, MIN_STAT_STAGE, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_AccDown:
	if_stat_level_equal AI_TARGET, STAT_ACC, MIN_STAT_STAGE, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_KEEN_EYE, Score_Minus10
	goto CheckIfAbilityBlocksStatChange

AI_CBM_EvasionDown:
	if_stat_level_equal AI_TARGET, STAT_EVASION, MIN_STAT_STAGE, Score_Minus10
CheckIfAbilityBlocksStatChange:
	get_ability AI_TARGET
	if_equal ABILITY_CLEAR_BODY, Score_Minus10
	if_equal ABILITY_WHITE_SMOKE, Score_Minus10
	end

AI_CBM_Haze:
	if_stat_level_less_than AI_USER, STAT_ATK, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_DEF, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_SPEED, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_SPATK, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_SPDEF, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_ACC, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_less_than AI_USER, STAT_EVASION, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_ATK, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_DEF, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_SPEED, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_SPATK, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_ACC, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	if_stat_level_more_than AI_TARGET, STAT_EVASION, DEFAULT_STAT_STAGE, AI_CBM_Haze_End
	goto Score_Minus10

AI_CBM_Haze_End:
	end

AI_CBM_Roar:
	count_usable_party_mons AI_TARGET
	if_equal 0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_SUCTION_CUPS, Score_Minus10
	end

AI_CBM_Toxic:
	get_target_type1
	if_equal TYPE_STEEL, Score_Minus10
	if_equal TYPE_POISON, Score_Minus10
	get_target_type2
	if_equal TYPE_STEEL, Score_Minus10
	if_equal TYPE_POISON, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_IMMUNITY, Score_Minus10
	if_status AI_TARGET, STATUS1_ANY, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	end

AI_CBM_LightScreen:
	if_side_affecting AI_USER, SIDE_STATUS_LIGHTSCREEN, Score_Minus8
	end

AI_CBM_OneHitKO:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_STURDY, Score_Minus10
	if_level_cond 1, Score_Minus10
	end

AI_CBM_Magnitude:
	get_ability AI_TARGET
	if_equal ABILITY_LEVITATE, Score_Minus10
AI_CBM_HighRiskForDamage:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_not_equal ABILITY_WONDER_GUARD, AI_CBM_HighRiskForDamage_End
	if_type_effectiveness AI_EFFECTIVENESS_x2, AI_CBM_HighRiskForDamage_End
	goto Score_Minus10

AI_CBM_HighRiskForDamage_End:
	end

AI_CBM_Mist:
	if_side_affecting AI_USER, SIDE_STATUS_MIST, Score_Minus8
	end

AI_CBM_FocusEnergy:
	if_status2 AI_USER, STATUS2_FOCUS_ENERGY, Score_Minus10
	end

AI_CBM_Confuse:
	if_status2 AI_TARGET, STATUS2_CONFUSION, Score_Minus5
	get_ability AI_TARGET
	if_equal ABILITY_OWN_TEMPO, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	end

AI_CBM_Reflect:
	if_side_affecting AI_USER, SIDE_STATUS_REFLECT, Score_Minus8
	end

AI_CBM_Paralyze:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_LIMBER, Score_Minus10
	if_status AI_TARGET, STATUS1_ANY, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	end

AI_CBM_Substitute:
	if_status2 AI_USER, STATUS2_SUBSTITUTE, Score_Minus8
	if_hp_less_than AI_USER, 26, Score_Minus10
	end

AI_CBM_LeechSeed:
	if_status3 AI_TARGET, STATUS3_LEECHSEED, Score_Minus10
	get_target_type1
	if_equal TYPE_GRASS, Score_Minus10
	get_target_type2
	if_equal TYPE_GRASS, Score_Minus10
	end

AI_CBM_Disable:
	if_any_move_disabled AI_TARGET, Score_Minus8
	end

AI_CBM_Encore:
	if_any_move_encored AI_TARGET, Score_Minus8
	end

AI_CBM_DamageDuringSleep:
	if_not_status AI_USER, STATUS1_SLEEP, Score_Minus8
	end

AI_CBM_CantEscape:
	if_status2 AI_TARGET, STATUS2_ESCAPE_PREVENTION, Score_Minus10
	end

AI_CBM_Curse:
	if_stat_level_equal AI_USER, STAT_ATK, MAX_STAT_STAGE, Score_Minus10
	if_stat_level_equal AI_USER, STAT_DEF, MAX_STAT_STAGE, Score_Minus8
	end

AI_CBM_Spikes:
	if_side_affecting AI_TARGET, SIDE_STATUS_SPIKES, Score_Minus10
	end

AI_CBM_Foresight:
	if_status2 AI_TARGET, STATUS2_FORESIGHT, Score_Minus10
	end

AI_CBM_PerishSong:
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, Score_Minus10
	end

AI_CBM_Sandstorm:
	get_weather
	if_equal AI_WEATHER_SANDSTORM, Score_Minus8
	end

AI_CBM_Attract:
	if_status2 AI_TARGET, STATUS2_INFATUATION, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_OBLIVIOUS, Score_Minus10
	get_gender AI_USER
	if_equal MON_MALE, AI_CBM_Attract_CheckIfTargetIsFemale
	if_equal MON_FEMALE, AI_CBM_Attract_CheckIfTargetIsMale
	goto Score_Minus10

AI_CBM_Attract_CheckIfTargetIsFemale:
	get_gender AI_TARGET
	if_equal MON_FEMALE, AI_CBM_Attract_End
	goto Score_Minus10

AI_CBM_Attract_CheckIfTargetIsMale:
	get_gender AI_TARGET
	if_equal MON_MALE, AI_CBM_Attract_End
	goto Score_Minus10

AI_CBM_Attract_End:
	end

AI_CBM_Safeguard:
	if_side_affecting AI_USER, SIDE_STATUS_SAFEGUARD, Score_Minus8
	end

AI_CBM_Memento:
	if_stat_level_equal AI_TARGET, STAT_ATK, MIN_STAT_STAGE, Score_Minus10
	if_stat_level_equal AI_TARGET, STAT_SPATK, MIN_STAT_STAGE, Score_Minus8
AI_CBM_BatonPass:
	count_usable_party_mons AI_USER
	if_equal 0, Score_Minus10
	end

AI_CBM_RainDance:
	get_weather
	if_equal AI_WEATHER_RAIN, Score_Minus8
	end

AI_CBM_SunnyDay:
	get_weather
	if_equal AI_WEATHER_SUN, Score_Minus8
	end

AI_CBM_FutureSight:
	if_side_affecting AI_TARGET, SIDE_STATUS_FUTUREATTACK, Score_Minus12
	if_side_affecting AI_USER, SIDE_STATUS_FUTUREATTACK, Score_Minus12
	score +5
	end

AI_CBM_FakeOut:
	is_first_turn_for AI_USER
	if_equal FALSE, Score_Minus10
	end

AI_CBM_Stockpile:
	get_stockpile_count AI_USER
	if_equal 3, Score_Minus10
	end

AI_CBM_SpitUpAndSwallow:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_stockpile_count AI_USER
	if_equal 0, Score_Minus10
	end

AI_CBM_Hail:
	get_weather
	if_equal AI_WEATHER_HAIL, Score_Minus8
	end

AI_CBM_Torment:
	if_status2 AI_TARGET, STATUS2_TORMENT, Score_Minus10
	end

AI_CBM_WillOWisp:
	get_ability AI_TARGET
	if_equal ABILITY_WATER_VEIL, Score_Minus10
	if_status AI_TARGET, STATUS1_ANY, Score_Minus10
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, Score_Minus10
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	end

AI_CBM_HelpingHand:
	if_not_double_battle Score_Minus10
	end

AI_CBM_TrickAndKnockOff:
	get_ability AI_TARGET
	if_equal ABILITY_STICKY_HOLD, Score_Minus10
	end

AI_CBM_Ingrain:
	if_status3 AI_USER, STATUS3_ROOTED, Score_Minus10
	end

AI_CBM_Recycle:
	get_used_held_item AI_USER
	if_equal ITEM_NONE, Score_Minus10
	end

AI_CBM_Imprison:
	if_status3 AI_USER, STATUS3_IMPRISONED_OTHERS, Score_Minus10
	end

AI_CBM_Refresh:
	if_not_status AI_USER, STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON, Score_Minus10
	end

AI_CBM_MudSport:
	if_status3 AI_USER, STATUS3_MUDSPORT, Score_Minus10
	end

AI_CBM_Tickle:
	if_stat_level_equal AI_TARGET, STAT_ATK, MIN_STAT_STAGE, Score_Minus10
	if_stat_level_equal AI_TARGET, STAT_DEF, MIN_STAT_STAGE, Score_Minus8
	end

AI_CBM_CosmicPower:
	if_stat_level_equal AI_USER, STAT_DEF, MAX_STAT_STAGE, Score_Minus10
	if_stat_level_equal AI_USER, STAT_SPDEF, MAX_STAT_STAGE, Score_Minus8
	end

AI_CBM_BulkUp:
	if_stat_level_equal AI_USER, STAT_ATK, MAX_STAT_STAGE, Score_Minus10
	if_stat_level_equal AI_USER, STAT_DEF, MAX_STAT_STAGE, Score_Minus8
	end

AI_CBM_WaterSport:
	if_status3 AI_USER, STATUS3_WATERSPORT, Score_Minus10
	end

AI_CBM_CalmMind:
	if_stat_level_equal AI_USER, STAT_SPATK, MAX_STAT_STAGE, Score_Minus10
	if_stat_level_equal AI_USER, STAT_SPDEF, MAX_STAT_STAGE, Score_Minus8
	end

AI_CBM_DragonDance:
	if_stat_level_equal AI_USER, STAT_ATK, MAX_STAT_STAGE, Score_Minus10
	if_stat_level_equal AI_USER, STAT_SPEED, MAX_STAT_STAGE, Score_Minus8
	end

Score_Minus1:
	score -1
	end

Score_Minus2:
	score -2
	end

Score_Minus3:
	score -3
	end

Score_Minus5:
	score -5
	end

Score_Minus8:
	score -8
	end

Score_Minus10:
	score -10
	end

Score_Minus12:
	score -12
	end

Score_Minus30:
	score -30
	end

Score_Plus1:
	score +1
	end

Score_Plus2:
	score +2
	end

Score_Plus3:
	score +3
	end

Score_Plus5:
	score +5
	end

Score_Plus10:
	score +10
	end

AI_CheckViability:
	if_target_is_ally AI_Ret
	if_effect EFFECT_SLEEP, AI_CV_Sleep
	if_effect EFFECT_ABSORB, AI_CV_Absorb
	if_effect EFFECT_EXPLOSION, AI_CV_SelfKO
	if_effect EFFECT_DREAM_EATER, AI_CV_DreamEater
	if_effect EFFECT_MIRROR_MOVE, AI_CV_MirrorMove
	if_effect EFFECT_ATTACK_UP, AI_CV_AttackUp
	if_effect EFFECT_DEFENSE_UP, AI_CV_DefenseUp
	if_effect EFFECT_SPEED_UP, AI_CV_SpeedUp
	if_effect EFFECT_SPECIAL_ATTACK_UP, AI_CV_SpAtkUp
	if_effect EFFECT_SPECIAL_DEFENSE_UP, AI_CV_SpDefUp
	if_effect EFFECT_ACCURACY_UP, AI_CV_AccuracyUp
	if_effect EFFECT_EVASION_UP, AI_CV_EvasionUp
	if_effect EFFECT_ALWAYS_HIT, AI_CV_AlwaysHit
	if_effect EFFECT_ATTACK_DOWN, AI_CV_AttackDown
	if_effect EFFECT_DEFENSE_DOWN, AI_CV_DefenseDown
	if_effect EFFECT_SPEED_DOWN, AI_CV_SpeedDown
	if_effect EFFECT_SPECIAL_ATTACK_DOWN, AI_CV_SpAtkDown
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN, AI_CV_SpDefDown
	if_effect EFFECT_ACCURACY_DOWN, AI_CV_AccuracyDown
	if_effect EFFECT_EVASION_DOWN, AI_CV_EvasionDown
	if_effect EFFECT_HAZE, AI_CV_Haze
	if_effect EFFECT_BIDE, AI_CV_Bide
	if_effect EFFECT_ROAR, AI_CV_Roar
	if_effect EFFECT_CONVERSION, AI_CV_Conversion
	if_effect EFFECT_RESTORE_HP, AI_CV_Heal
	if_effect EFFECT_TOXIC, AI_CV_Toxic
	if_effect EFFECT_LIGHT_SCREEN, AI_CV_LightScreen
	if_effect EFFECT_REST, AI_CV_Rest
	if_effect EFFECT_OHKO, AI_CV_OneHitKO
	if_effect EFFECT_RAZOR_WIND, AI_CV_ChargeUpMove
	if_effect EFFECT_SUPER_FANG, AI_CV_SuperFang
	if_effect EFFECT_TRAP, AI_CV_Trap
	if_effect EFFECT_HIGH_CRITICAL, AI_CV_HighCrit
	if_effect EFFECT_CONFUSE, AI_CV_Confuse
	if_effect EFFECT_ATTACK_UP_2, AI_CV_AttackUp
	if_effect EFFECT_DEFENSE_UP_2, AI_CV_DefenseUp
	if_effect EFFECT_SPEED_UP_2, AI_CV_SpeedUp
	if_effect EFFECT_SPECIAL_ATTACK_UP_2, AI_CV_SpAtkUp
	if_effect EFFECT_SPECIAL_DEFENSE_UP_2, AI_CV_SpDefUp
	if_effect EFFECT_ACCURACY_UP_2, AI_CV_AccuracyUp
	if_effect EFFECT_EVASION_UP_2, AI_CV_EvasionUp
	if_effect EFFECT_ATTACK_DOWN_2, AI_CV_AttackDown
	if_effect EFFECT_DEFENSE_DOWN_2, AI_CV_DefenseDown
	if_effect EFFECT_SPEED_DOWN_2, AI_CV_SpeedDown
	if_effect EFFECT_SPECIAL_ATTACK_DOWN_2, AI_CV_SpAtkDown
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN_2, AI_CV_SpDefDown
	if_effect EFFECT_ACCURACY_DOWN_2, AI_CV_AccuracyDown
	if_effect EFFECT_EVASION_DOWN_2, AI_CV_EvasionDown
	if_effect EFFECT_REFLECT, AI_CV_Reflect
	if_effect EFFECT_POISON, AI_CV_Poison
	if_effect EFFECT_PARALYZE, AI_CV_Paralyze
	if_effect EFFECT_SWAGGER, AI_CV_Swagger
	if_effect EFFECT_SPEED_DOWN_HIT, AI_CV_SpeedDownFromChance
	if_effect EFFECT_SKY_ATTACK, AI_CV_ChargeUpMove
	if_effect EFFECT_VITAL_THROW, AI_CV_VitalThrow
	if_effect EFFECT_SUBSTITUTE, AI_CV_Substitute
	if_effect EFFECT_RECHARGE, AI_CV_Recharge
	if_effect EFFECT_LEECH_SEED, AI_CV_Toxic
	if_effect EFFECT_DISABLE, AI_CV_Disable
	if_effect EFFECT_COUNTER, AI_CV_Counter
	if_effect EFFECT_ENCORE, AI_CV_Encore
	if_effect EFFECT_PAIN_SPLIT, AI_CV_PainSplit
	if_effect EFFECT_SNORE, AI_CV_Snore
	if_effect EFFECT_LOCK_ON, AI_CV_LockOn
	if_effect EFFECT_SLEEP_TALK, AI_CV_SleepTalk
	if_effect EFFECT_DESTINY_BOND, AI_CV_DestinyBond
	if_effect EFFECT_FLAIL, AI_CV_Flail
	if_effect EFFECT_HEAL_BELL, AI_CV_HealBell
	if_effect EFFECT_THIEF, AI_CV_Thief
	if_effect EFFECT_MEAN_LOOK, AI_CV_Trap
	if_effect EFFECT_MINIMIZE, AI_CV_EvasionUp
	if_effect EFFECT_CURSE, AI_CV_Curse
	if_effect EFFECT_PROTECT, AI_CV_Protect
	if_effect EFFECT_FORESIGHT, AI_CV_Foresight
	if_effect EFFECT_ENDURE, AI_CV_Endure
	if_effect EFFECT_BATON_PASS, AI_CV_BatonPass
	if_effect EFFECT_PURSUIT, AI_CV_Pursuit
	if_effect EFFECT_MORNING_SUN, AI_CV_HealWeather
	if_effect EFFECT_SYNTHESIS, AI_CV_HealWeather
	if_effect EFFECT_MOONLIGHT, AI_CV_HealWeather
	if_effect EFFECT_RAIN_DANCE, AI_CV_RainDance
	if_effect EFFECT_SUNNY_DAY, AI_CV_SunnyDay
	if_effect EFFECT_BELLY_DRUM, AI_CV_BellyDrum
	if_effect EFFECT_PSYCH_UP, AI_CV_PsychUp
	if_effect EFFECT_MIRROR_COAT, AI_CV_MirrorCoat
	if_effect EFFECT_SKULL_BASH, AI_CV_ChargeUpMove
	if_effect EFFECT_SOLAR_BEAM, AI_CV_ChargeUpMove
	if_effect EFFECT_SEMI_INVULNERABLE, AI_CV_SemiInvulnerable
	if_effect EFFECT_SOFTBOILED, AI_CV_Heal
	if_effect EFFECT_FAKE_OUT, AI_CV_FakeOut
	if_effect EFFECT_SPIT_UP, AI_CV_SpitUp
	if_effect EFFECT_SWALLOW, AI_CV_Heal
	if_effect EFFECT_HAIL, AI_CV_Hail
	if_effect EFFECT_FLATTER, AI_CV_Flatter
	if_effect EFFECT_MEMENTO, AI_CV_SelfKO
	if_effect EFFECT_FACADE, AI_CV_Facade
	if_effect EFFECT_FOCUS_PUNCH, AI_CV_FocusPunch
	if_effect EFFECT_SMELLINGSALT, AI_CV_SmellingSalt
	if_effect EFFECT_TRICK, AI_CV_Trick
	if_effect EFFECT_ROLE_PLAY, AI_CV_ChangeSelfAbility
	if_effect EFFECT_SUPERPOWER, AI_CV_Superpower
	if_effect EFFECT_MAGIC_COAT, AI_CV_MagicCoat
	if_effect EFFECT_RECYCLE, AI_CV_Recycle
	if_effect EFFECT_REVENGE, AI_CV_Revenge
	if_effect EFFECT_BRICK_BREAK, AI_CV_BrickBreak
	if_effect EFFECT_KNOCK_OFF, AI_CV_KnockOff
	if_effect EFFECT_ENDEAVOR, AI_CV_Endeavor
	if_effect EFFECT_ERUPTION, AI_CV_Eruption
	if_effect EFFECT_SKILL_SWAP, AI_CV_ChangeSelfAbility
	if_effect EFFECT_IMPRISON, AI_CV_Imprison
	if_effect EFFECT_REFRESH, AI_CV_Refresh
	if_effect EFFECT_SNATCH, AI_CV_Snatch
	if_effect EFFECT_BLAZE_KICK, AI_CV_HighCrit
	if_effect EFFECT_MUD_SPORT, AI_CV_MudSport
	if_effect EFFECT_OVERHEAT, AI_CV_Overheat
	if_effect EFFECT_TICKLE, AI_CV_DefenseDown
	if_effect EFFECT_COSMIC_POWER, AI_CV_SpDefUp
	if_effect EFFECT_BULK_UP, AI_CV_DefenseUp
	if_effect EFFECT_POISON_TAIL, AI_CV_HighCrit
	if_effect EFFECT_WATER_SPORT, AI_CV_WaterSport
	if_effect EFFECT_CALM_MIND, AI_CV_SpDefUp
	if_effect EFFECT_DRAGON_DANCE, AI_CV_DragonDance
	end

AI_CV_Sleep:
	if_has_move_with_effect AI_TARGET, EFFECT_DREAM_EATER, AI_CV_SleepEncourageSlpDamage
	if_has_move_with_effect AI_TARGET, EFFECT_NIGHTMARE, AI_CV_SleepEncourageSlpDamage
	goto AI_CV_Sleep_End

AI_CV_SleepEncourageSlpDamage:
	if_random_less_than 128, AI_CV_Sleep_End
	score +1
AI_CV_Sleep_End:
	end

AI_CV_Absorb:
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_AbsorbEncourageMaybe
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_AbsorbEncourageMaybe
	goto AI_CV_Absorb_End

AI_CV_AbsorbEncourageMaybe:
	if_random_less_than 50, AI_CV_Absorb_End
	score -3
AI_CV_Absorb_End:
	end

AI_CV_SelfKO:
	if_stat_level_less_than AI_TARGET, STAT_EVASION, 7, AI_CV_SelfKO_Encourage1
	score -1
	if_stat_level_less_than AI_TARGET, STAT_EVASION, 10, AI_CV_SelfKO_Encourage1
	if_random_less_than 128, AI_CV_SelfKO_Encourage1
	score -1
AI_CV_SelfKO_Encourage1:
	if_hp_less_than AI_USER, 80, AI_CV_SelfKO_Encourage2
	if_target_faster AI_CV_SelfKO_Encourage2
	if_random_less_than 50, AI_CV_SelfKO_End
	goto Score_Minus3

AI_CV_SelfKO_Encourage2:
	if_hp_more_than AI_USER, 50, AI_CV_SelfKO_Encourage4
	if_random_less_than 128, AI_CV_SelfKO_Encourage3
	score +1
AI_CV_SelfKO_Encourage3:
	if_hp_more_than AI_USER, 30, AI_CV_SelfKO_End
	if_random_less_than 50, AI_CV_SelfKO_End
	score +1
	goto AI_CV_SelfKO_End

AI_CV_SelfKO_Encourage4:
	if_random_less_than 50, AI_CV_SelfKO_End
	score -1
AI_CV_SelfKO_End:
	end

AI_CV_DreamEater:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_DreamEater_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_DreamEater_ScoreDown1
	goto AI_CV_DreamEater_End

AI_CV_DreamEater_ScoreDown1:
	score -1
AI_CV_DreamEater_End:
	end

AI_CV_MirrorMove:
	if_target_faster AI_CV_MirrorMove2
	get_last_used_bank_move AI_TARGET
	if_not_in_hwords AI_CV_MirrorMove_EncouragedMovesToMirror, AI_CV_MirrorMove2
	if_random_less_than 128, AI_CV_MirrorMove_End
	score +2
	goto AI_CV_MirrorMove_End

AI_CV_MirrorMove2:
	get_last_used_bank_move AI_TARGET
	if_in_hwords AI_CV_MirrorMove_EncouragedMovesToMirror, AI_CV_MirrorMove_End
	if_random_less_than 80, AI_CV_MirrorMove_End
	score -1
AI_CV_MirrorMove_End:
	end

AI_CV_MirrorMove_EncouragedMovesToMirror:
	.2byte MOVE_SLEEP_POWDER
	.2byte MOVE_LOVELY_KISS
	.2byte MOVE_SPORE
	.2byte MOVE_HYPNOSIS
	.2byte MOVE_SING
	.2byte MOVE_GRASS_WHISTLE
	.2byte MOVE_SHADOW_PUNCH
	.2byte MOVE_SAND_ATTACK
	.2byte MOVE_SMOKESCREEN
	.2byte MOVE_TOXIC
	.2byte MOVE_GUILLOTINE
	.2byte MOVE_HORN_DRILL
	.2byte MOVE_FISSURE
	.2byte MOVE_SHEER_COLD
	.2byte MOVE_CROSS_CHOP
	.2byte MOVE_AEROBLAST
	.2byte MOVE_CONFUSE_RAY
	.2byte MOVE_SWEET_KISS
	.2byte MOVE_SCREECH
	.2byte MOVE_COTTON_SPORE
	.2byte MOVE_SCARY_FACE
	.2byte MOVE_FAKE_TEARS
	.2byte MOVE_METAL_SOUND
	.2byte MOVE_THUNDER_WAVE
	.2byte MOVE_GLARE
	.2byte MOVE_POISON_POWDER
	.2byte MOVE_SHADOW_BALL
	.2byte MOVE_DYNAMIC_PUNCH
	.2byte MOVE_HYPER_BEAM
	.2byte MOVE_EXTREME_SPEED
	.2byte MOVE_THIEF
	.2byte MOVE_COVET
	.2byte MOVE_ATTRACT
	.2byte MOVE_SWAGGER
	.2byte MOVE_TORMENT
	.2byte MOVE_FLATTER
	.2byte MOVE_TRICK
	.2byte MOVE_SUPERPOWER
	.2byte MOVE_SKILL_SWAP
	.2byte -1

AI_CV_AttackUp:
	if_stat_level_less_than AI_USER, STAT_ATK, 9, AI_CV_AttackUp2
	if_random_less_than 100, AI_CV_AttackUp3
	score -1
	goto AI_CV_AttackUp3

AI_CV_AttackUp2:
	if_hp_not_equal AI_USER, 100, AI_CV_AttackUp3
	if_random_less_than 128, AI_CV_AttackUp3
	score +2
AI_CV_AttackUp3:
	if_hp_more_than AI_USER, 70, AI_CV_AttackUp_End
	if_hp_less_than AI_USER, 40, AI_CV_AttackUp_ScoreDown2
	if_random_less_than 40, AI_CV_AttackUp_End
AI_CV_AttackUp_ScoreDown2:
	score -2
AI_CV_AttackUp_End:
	end

AI_CV_DefenseUp:
	if_stat_level_less_than AI_USER, STAT_DEF, 9, AI_CV_DefenseUp2
	if_random_less_than 100, AI_CV_DefenseUp3
	score -1
	goto AI_CV_DefenseUp3

AI_CV_DefenseUp2:
	if_hp_not_equal AI_USER, 100, AI_CV_DefenseUp3
	if_random_less_than 128, AI_CV_DefenseUp3
	score +2
AI_CV_DefenseUp3:
	if_hp_less_than AI_USER, 70, AI_CV_DefenseUp4
	if_random_less_than 200, AI_CV_DefenseUp_End
AI_CV_DefenseUp4:
	if_hp_less_than AI_USER, 40, AI_CV_DefenseUp_ScoreDown2
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_DefenseUp5
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes AI_CV_DefenseUp_PhysicalTypes, AI_CV_DefenseUp_ScoreDown2
	if_random_less_than 60, AI_CV_DefenseUp_End
AI_CV_DefenseUp5:
	if_random_less_than 60, AI_CV_DefenseUp_End
AI_CV_DefenseUp_ScoreDown2:
	score -2
AI_CV_DefenseUp_End:
	end

AI_CV_DefenseUp_PhysicalTypes:
	.byte TYPE_NORMAL
	.byte TYPE_FIGHTING
	.byte TYPE_POISON
	.byte TYPE_GROUND
	.byte TYPE_FLYING
	.byte TYPE_ROCK
	.byte TYPE_BUG
	.byte TYPE_GHOST
	.byte TYPE_STEEL
	.byte -1

AI_CV_SpeedUp:
	if_target_faster AI_CV_SpeedUp2
	score -3
	goto AI_CV_SpeedUp_End

AI_CV_SpeedUp2:
	if_random_less_than 70, AI_CV_SpeedUp_End
	score +3
AI_CV_SpeedUp_End:
	end

AI_CV_SpAtkUp:
	if_stat_level_less_than AI_USER, STAT_SPATK, 9, AI_CV_SpAtkUp2
	if_random_less_than 100, AI_CV_SpAtkUp3
	score -1
	goto AI_CV_SpAtkUp3

AI_CV_SpAtkUp2:
	if_hp_not_equal AI_USER, 100, AI_CV_SpAtkUp3
	if_random_less_than 128, AI_CV_SpAtkUp3
	score +2
AI_CV_SpAtkUp3:
	if_hp_more_than AI_USER, 70, AI_CV_SpAtkUp_End
	if_hp_less_than AI_USER, 40, AI_CV_SpAtkUp_ScoreDown2
	if_random_less_than 70, AI_CV_SpAtkUp_End
AI_CV_SpAtkUp_ScoreDown2:
	score -2
AI_CV_SpAtkUp_End:
	end

AI_CV_SpDefUp:
	if_stat_level_less_than AI_USER, STAT_SPDEF, 9, AI_CV_SpDefUp2
	if_random_less_than 100, AI_CV_SpDefUp3
	score -1
	goto AI_CV_SpDefUp3

AI_CV_SpDefUp2:
	if_hp_not_equal AI_USER, 100, AI_CV_SpDefUp3
	if_random_less_than 128, AI_CV_SpDefUp3
	score +2
AI_CV_SpDefUp3:
	if_hp_less_than AI_USER, 70, AI_CV_SpDefUp4
	if_random_less_than 200, AI_CV_SpDefUp_End
AI_CV_SpDefUp4:
	if_hp_less_than AI_USER, 40, AI_CV_SpDefUp_ScoreDown2
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_SpDefUp5
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_in_bytes AI_CV_SpDefUp_PhysicalTypes, AI_CV_SpDefUp_ScoreDown2
	if_random_less_than 60, AI_CV_SpDefUp_End
AI_CV_SpDefUp5:
	if_random_less_than 60, AI_CV_SpDefUp_End
AI_CV_SpDefUp_ScoreDown2:
	score -2
AI_CV_SpDefUp_End:
	end

AI_CV_SpDefUp_PhysicalTypes:
	.byte TYPE_NORMAL
	.byte TYPE_FIGHTING
	.byte TYPE_POISON
	.byte TYPE_GROUND
	.byte TYPE_FLYING
	.byte TYPE_ROCK
	.byte TYPE_BUG
	.byte TYPE_GHOST
	.byte TYPE_STEEL
	.byte -1

AI_CV_AccuracyUp:
	if_stat_level_less_than AI_USER, STAT_ACC, 9, AI_CV_AccuracyUp2
	if_random_less_than 50, AI_CV_AccuracyUp2
	score -2
AI_CV_AccuracyUp2:
	if_hp_more_than AI_USER, 70, AI_CV_AccuracyUp_End
	score -2
AI_CV_AccuracyUp_End:
	end

AI_CV_EvasionUp:
	if_hp_less_than AI_USER, 90, AI_CV_EvasionUp2
	if_random_less_than 100, AI_CV_EvasionUp2
	score +3
AI_CV_EvasionUp2:
	if_stat_level_less_than AI_USER, STAT_EVASION, 9, AI_CV_EvasionUp3
	if_random_less_than 128, AI_CV_EvasionUp3
	score -1
AI_CV_EvasionUp3:
	if_not_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_EvasionUp5
	if_hp_more_than AI_USER, 50, AI_CV_EvasionUp4
	if_random_less_than 80, AI_CV_EvasionUp5
AI_CV_EvasionUp4:
	if_random_less_than 50, AI_CV_EvasionUp5
	score +3
AI_CV_EvasionUp5:
	if_not_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_EvasionUp6
	if_random_less_than 70, AI_CV_EvasionUp6
	score +3
AI_CV_EvasionUp6:
	if_not_status3 AI_USER, STATUS3_ROOTED, AI_CV_EvasionUp7
	if_random_less_than 128, AI_CV_EvasionUp7
	score +2
AI_CV_EvasionUp7:
	if_not_status2 AI_TARGET, STATUS2_CURSED, AI_CV_EvasionUp8
	if_random_less_than 70, AI_CV_EvasionUp8
	score +3
AI_CV_EvasionUp8:
	if_hp_more_than AI_USER, 70, AI_CV_EvasionUp_End
	if_stat_level_equal AI_USER, STAT_EVASION, DEFAULT_STAT_STAGE, AI_CV_EvasionUp_End
	if_hp_less_than AI_USER, 40, AI_CV_EvasionUp_ScoreDown2
	if_hp_less_than AI_TARGET, 40, AI_CV_EvasionUp_ScoreDown2
	if_random_less_than 70, AI_CV_EvasionUp_End
AI_CV_EvasionUp_ScoreDown2:
	score -2
AI_CV_EvasionUp_End:
	end

AI_CV_AlwaysHit:
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 10, AI_CV_AlwaysHit_ScoreUp1
	if_stat_level_less_than AI_USER, STAT_ACC, 2, AI_CV_AlwaysHit_ScoreUp1
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 8, AI_CV_AlwaysHit2
	if_stat_level_less_than AI_USER, STAT_ACC, 4, AI_CV_AlwaysHit2
	goto AI_CV_AlwaysHit_End

AI_CV_AlwaysHit_ScoreUp1:
	score +1
AI_CV_AlwaysHit2:
	if_random_less_than 100, AI_CV_AlwaysHit_End
	score +1
AI_CV_AlwaysHit_End:
	end

AI_CV_AttackDown:
	if_stat_level_equal AI_TARGET, STAT_ATK, DEFAULT_STAT_STAGE, AI_CV_AttackDown3
	score -1
	if_hp_more_than AI_USER, 90, AI_CV_AttackDown2
	score -1
AI_CV_AttackDown2:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 3, AI_CV_AttackDown3
	if_random_less_than 50, AI_CV_AttackDown3
	score -2
AI_CV_AttackDown3:
	if_hp_more_than AI_TARGET, 70, AI_CV_AttackDown4
	score -2
AI_CV_AttackDown4:
	get_target_type1
	if_in_bytes AI_CV_AttackDown_PhysicalTypeList, AI_CV_AttackDown_End
	get_target_type2
	if_in_bytes AI_CV_AttackDown_PhysicalTypeList, AI_CV_AttackDown_End
	if_random_less_than 50, AI_CV_AttackDown_End
	score -2
AI_CV_AttackDown_End:
	end

@ If the target is not of any type in this list then using the move may be discouraged.
@ It seems likely this was meant to be "discourage reducing the target's attack if they're
@ not a physical type", but they've left out Flying, Poison, and Ghost.
AI_CV_AttackDown_PhysicalTypeList:
	.byte TYPE_NORMAL
	.byte TYPE_FIGHTING
	.byte TYPE_GROUND
	.byte TYPE_ROCK
	.byte TYPE_BUG
	.byte TYPE_STEEL
	.byte -1

AI_CV_DefenseDown:
	if_hp_less_than AI_USER, 70, AI_CV_DefenseDown2
	if_stat_level_more_than AI_TARGET, STAT_DEF, 3, AI_CV_DefenseDown3
AI_CV_DefenseDown2:
	if_random_less_than 50, AI_CV_DefenseDown3
	score -2
AI_CV_DefenseDown3:
	if_hp_more_than AI_TARGET, 70, AI_CV_DefenseDown_End
	score -2
AI_CV_DefenseDown_End:
	end

AI_CV_SpeedDownFromChance:
	if_move MOVE_ICY_WIND, AI_CV_SpeedDown
	if_move MOVE_ROCK_TOMB, AI_CV_SpeedDown
	if_move MOVE_MUD_SHOT, AI_CV_SpeedDown
	end

AI_CV_SpeedDown:
	if_target_faster AI_CV_SpeedDown2
	score -3
	goto AI_CV_SpeedDown_End

AI_CV_SpeedDown2:
	if_random_less_than 70, AI_CV_SpeedDown_End
	score +2
AI_CV_SpeedDown_End:
	end

AI_CV_SpAtkDown:
	if_stat_level_equal AI_TARGET, STAT_ATK, DEFAULT_STAT_STAGE, AI_CV_SpAtkDown3
	score -1
	if_hp_more_than AI_USER, 90, AI_CV_SpAtkDown2
	score -1
AI_CV_SpAtkDown2:
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 3, AI_CV_SpAtkDown3
	if_random_less_than 50, AI_CV_SpAtkDown3
	score -2
AI_CV_SpAtkDown3:
	if_hp_more_than AI_TARGET, 70, AI_CV_SpAtkDown4
	score -2
AI_CV_SpAtkDown4:
	get_target_type1
	if_in_bytes AI_CV_SpAtkDown_SpecialTypeList, AI_CV_SpAtkDown_End
	get_target_type2
	if_in_bytes AI_CV_SpAtkDown_SpecialTypeList, AI_CV_SpAtkDown_End
	if_random_less_than 50, AI_CV_SpAtkDown_End
	score -2
AI_CV_SpAtkDown_End:
	end

AI_CV_SpAtkDown_SpecialTypeList:
	.byte TYPE_FIRE
	.byte TYPE_WATER
	.byte TYPE_GRASS
	.byte TYPE_ELECTRIC
	.byte TYPE_PSYCHIC
	.byte TYPE_ICE
	.byte TYPE_DRAGON
	.byte TYPE_DARK
	.byte -1

AI_CV_SpDefDown:
	if_hp_less_than AI_USER, 70, AI_CV_SpDefDown2
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 3, AI_CV_SpDefDown3
AI_CV_SpDefDown2:
	if_random_less_than 50, AI_CV_SpDefDown3
	score -2
AI_CV_SpDefDown3:
	if_hp_more_than AI_TARGET, 70, AI_CV_SpDefDown_End
	score -2
AI_CV_SpDefDown_End:
	end

AI_CV_AccuracyDown:
	if_hp_less_than AI_USER, 70, AI_CV_AccuracyDown2
	if_hp_more_than AI_TARGET, 70, AI_CV_AccuracyDown3
AI_CV_AccuracyDown2:
	if_random_less_than 100, AI_CV_AccuracyDown3
	score -1
AI_CV_AccuracyDown3:
	if_stat_level_more_than AI_USER, STAT_ACC, 4, AI_CV_AccuracyDown4
	if_random_less_than 80, AI_CV_AccuracyDown4
	score -2
AI_CV_AccuracyDown4:
	if_not_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_AccuracyDown5
	if_random_less_than 70, AI_CV_AccuracyDown5
	score +2
AI_CV_AccuracyDown5:
	if_not_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_AccuracyDown6
	if_random_less_than 70, AI_CV_AccuracyDown6
	score +2
AI_CV_AccuracyDown6:
	if_not_status3 AI_USER, STATUS3_ROOTED, AI_CV_AccuracyDown7
	if_random_less_than 128, AI_CV_AccuracyDown7
	score +1
AI_CV_AccuracyDown7:
	if_not_status2 AI_TARGET, STATUS2_CURSED, AI_CV_AccuracyDown8
	if_random_less_than 70, AI_CV_AccuracyDown8
	score +2
AI_CV_AccuracyDown8:
	if_hp_more_than AI_USER, 70, AI_CV_AccuracyDown_End
	if_stat_level_equal AI_TARGET, STAT_ACC, DEFAULT_STAT_STAGE, AI_CV_AccuracyDown_End
	if_hp_less_than AI_USER, 40, AI_CV_AccuracyDown_ScoreDown2
	if_hp_less_than AI_TARGET, 40, AI_CV_AccuracyDown_ScoreDown2
	if_random_less_than 70, AI_CV_AccuracyDown_End
AI_CV_AccuracyDown_ScoreDown2:
	score -2
AI_CV_AccuracyDown_End:
	end

AI_CV_EvasionDown:
	if_hp_less_than AI_USER, 70, AI_CV_EvasionDown2
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 3, AI_CV_EvasionDown3
AI_CV_EvasionDown2:
	if_random_less_than 50, AI_CV_EvasionDown3
	score -2
AI_CV_EvasionDown3:
	if_hp_more_than AI_TARGET, 70, AI_CV_EvasionDown_End
	score -2
AI_CV_EvasionDown_End:
	end

AI_CV_Haze:
	if_stat_level_more_than AI_USER, STAT_ATK, 8, AI_CV_Haze2
	if_stat_level_more_than AI_USER, STAT_DEF, 8, AI_CV_Haze2
	if_stat_level_more_than AI_USER, STAT_SPATK, 8, AI_CV_Haze2
	if_stat_level_more_than AI_USER, STAT_SPDEF, 8, AI_CV_Haze2
	if_stat_level_more_than AI_USER, STAT_EVASION, 8, AI_CV_Haze2
	if_stat_level_less_than AI_TARGET, STAT_ATK, 4, AI_CV_Haze2
	if_stat_level_less_than AI_TARGET, STAT_DEF, 4, AI_CV_Haze2
	if_stat_level_less_than AI_TARGET, STAT_SPATK, 4, AI_CV_Haze2
	if_stat_level_less_than AI_TARGET, STAT_SPDEF, 4, AI_CV_Haze2
	if_stat_level_less_than AI_TARGET, STAT_ACC, 4, AI_CV_Haze2
	goto AI_CV_Haze3

AI_CV_Haze2:
	if_random_less_than 50, AI_CV_Haze3
	score -3
AI_CV_Haze3:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 8, AI_CV_Haze4
	if_stat_level_more_than AI_TARGET, STAT_DEF, 8, AI_CV_Haze4
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 8, AI_CV_Haze4
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 8, AI_CV_Haze4
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 8, AI_CV_Haze4
	if_stat_level_less_than AI_USER, STAT_ATK, 4, AI_CV_Haze4
	if_stat_level_less_than AI_USER, STAT_DEF, 4, AI_CV_Haze4
	if_stat_level_less_than AI_USER, STAT_SPATK, 4, AI_CV_Haze4
	if_stat_level_less_than AI_USER, STAT_SPDEF, 4, AI_CV_Haze4
	if_stat_level_less_than AI_USER, STAT_ACC, 4, AI_CV_Haze4
	if_random_less_than 50, AI_CV_Haze_End
	score -1
	goto AI_CV_Haze_End

AI_CV_Haze4:
	if_random_less_than 50, AI_CV_Haze_End
	score +3
AI_CV_Haze_End:
	end

AI_CV_Bide:
	if_hp_more_than AI_USER, 90, AI_CV_Bide_End
	score -2
AI_CV_Bide_End:
	end

AI_CV_Roar:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 8, AI_CV_Roar2
	if_stat_level_more_than AI_TARGET, STAT_DEF, 8, AI_CV_Roar2
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 8, AI_CV_Roar2
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 8, AI_CV_Roar2
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 8, AI_CV_Roar2
	score -3
	goto AI_CV_Roar_End

AI_CV_Roar2:
	if_random_less_than 128, AI_CV_Roar_End
	score +2
AI_CV_Roar_End:
	end

AI_CV_Conversion:
	if_hp_more_than AI_USER, 90, AI_CV_Conversion2
	score -2
AI_CV_Conversion2:
	get_turn_count
	if_equal 0, AI_CV_Conversion_End
	if_random_less_than 200, Score_Minus2
AI_CV_Conversion_End:
	end

AI_CV_HealWeather:
	get_weather
	if_equal AI_WEATHER_HAIL, AI_CV_HealWeather_ScoreDown2
	if_equal AI_WEATHER_RAIN, AI_CV_HealWeather_ScoreDown2
	if_equal AI_WEATHER_SANDSTORM, AI_CV_HealWeather_ScoreDown2
	goto AI_CV_Heal

AI_CV_HealWeather_ScoreDown2:
	score -2
AI_CV_Heal:
	if_hp_equal AI_USER, 100, AI_CV_Heal3
	if_target_faster AI_CV_Heal4
	score -8
	goto AI_CV_Heal_End

AI_CV_Heal2:
	if_hp_less_than AI_USER, 50, AI_CV_Heal5
	if_hp_more_than AI_USER, 80, AI_CV_Heal3
	if_random_less_than 70, AI_CV_Heal5
AI_CV_Heal3:
	score -3
	goto AI_CV_Heal_End

AI_CV_Heal4:
	if_hp_less_than AI_USER, 70, AI_CV_Heal5
	if_random_less_than 30, AI_CV_Heal5
	score -3
	goto AI_CV_Heal_End

AI_CV_Heal5:
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_SNATCH, AI_CV_Heal6
	if_random_less_than 100, AI_CV_Heal_End
AI_CV_Heal6:
	if_random_less_than 20, AI_CV_Heal_End
	score +2
AI_CV_Heal_End:
	end

AI_CV_Toxic:
	if_user_has_no_attacking_moves AI_CV_Toxic3
	if_hp_more_than AI_USER, 50, AI_CV_Toxic2
	if_random_less_than 50, AI_CV_Toxic2
	score -3
AI_CV_Toxic2:
	if_hp_more_than AI_TARGET, 50, AI_CV_Toxic3
	if_random_less_than 50, AI_CV_Toxic3
	score -3
AI_CV_Toxic3:
	if_has_move_with_effect AI_USER, EFFECT_SPECIAL_DEFENSE_UP, AI_CV_Toxic4
	if_has_move_with_effect AI_USER, EFFECT_PROTECT, AI_CV_Toxic4
	goto AI_CV_Toxic_End

AI_CV_Toxic4:
	if_random_less_than 60, AI_CV_Toxic_End
	score +2
AI_CV_Toxic_End:
	end

AI_CV_LightScreen:
	if_hp_less_than AI_USER, 50, AI_CV_LightScreen_ScoreDown2
	get_target_type1
	if_in_bytes AI_CV_LightScreen_SpecialTypeList, AI_CV_LightScreen_End
	get_target_type2
	if_in_bytes AI_CV_LightScreen_SpecialTypeList, AI_CV_LightScreen_End
	if_random_less_than 50, AI_CV_LightScreen_End
AI_CV_LightScreen_ScoreDown2:
	score -2
AI_CV_LightScreen_End:
	end

AI_CV_LightScreen_SpecialTypeList:
	.byte TYPE_FIRE
	.byte TYPE_WATER
	.byte TYPE_GRASS
	.byte TYPE_ELECTRIC
	.byte TYPE_PSYCHIC
	.byte TYPE_ICE
	.byte TYPE_DRAGON
	.byte TYPE_DARK
	.byte -1

AI_CV_Rest:
	if_target_faster AI_CV_Rest4
	if_hp_not_equal AI_USER, 100, AI_CV_Rest2
	score -8
	goto AI_CV_Rest_End

AI_CV_Rest2:
	if_hp_less_than AI_USER, 40, AI_CV_Rest6
	if_hp_more_than AI_USER, 50, AI_CV_Rest3
	if_random_less_than 70, AI_CV_Rest6
AI_CV_Rest3:
	score -3
	goto AI_CV_Rest_End

AI_CV_Rest4:
	if_hp_less_than AI_USER, 60, AI_CV_Rest6
	if_hp_more_than AI_USER, 70, AI_CV_Rest5
	if_random_less_than 50, AI_CV_Rest6
AI_CV_Rest5:
	score -3
	goto AI_CV_Rest_End

AI_CV_Rest6:
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_SNATCH, AI_CV_Rest7
	if_random_less_than 50, AI_CV_Rest_End
AI_CV_Rest7:
	if_random_less_than 10, AI_CV_Rest_End
	score +3
AI_CV_Rest_End:
	end

AI_CV_OneHitKO:
	end

AI_CV_SuperFang:
	if_hp_more_than AI_TARGET, 50, AI_CV_SuperFang_End
	score -1
AI_CV_SuperFang_End:
	end

AI_CV_Trap:
	if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_Trap2
	if_status2 AI_TARGET, STATUS2_CURSED, AI_CV_Trap2
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, AI_CV_Trap2
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_Trap2
	goto AI_CV_Trap_End

AI_CV_Trap2:
	if_random_less_than 128, AI_CV_Trap_End
	score +1
AI_CV_Trap_End:
	end

AI_CV_HighCrit:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_HighCrit_End
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_HighCrit_End
	if_type_effectiveness AI_EFFECTIVENESS_x2, AI_CV_HighCrit2
	if_type_effectiveness AI_EFFECTIVENESS_x4, AI_CV_HighCrit2
	if_random_less_than 128, AI_CV_HighCrit_End

AI_CV_HighCrit2:
	if_random_less_than 128, AI_CV_HighCrit_End
	score +1
AI_CV_HighCrit_End:
	end

AI_CV_Swagger:
	if_has_move AI_USER, MOVE_PSYCH_UP, AI_CV_SwaggerHasPsychUp
AI_CV_Flatter:
	if_random_less_than 128, AI_CV_Confuse
	score +1
AI_CV_Confuse:
	if_hp_more_than AI_TARGET, 70, AI_CV_Confuse_End
	if_random_less_than 128, AI_CV_Confuse2
	score -1
AI_CV_Confuse2:
	if_hp_more_than AI_TARGET, 50, AI_CV_Confuse_End
	score -1
	if_hp_more_than AI_TARGET, 30, AI_CV_Confuse_End
	score -1
AI_CV_Confuse_End:
	end

AI_CV_SwaggerHasPsychUp:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 3, AI_CV_SwaggerHasPsychUp_Minus5
	score +3
	get_turn_count
	if_not_equal 0, AI_CV_SwaggerHasPsychUp_End
	score +2
	goto AI_CV_SwaggerHasPsychUp_End

AI_CV_SwaggerHasPsychUp_Minus5:
	score -5
AI_CV_SwaggerHasPsychUp_End:
	end

AI_CV_Reflect:
	if_hp_less_than AI_USER, 50, AI_CV_Reflect_ScoreDown2
	get_target_type1
	if_in_bytes AI_CV_Reflect_PhysicalTypeList, AI_CV_Reflect_End
	get_target_type2
	if_in_bytes AI_CV_Reflect_PhysicalTypeList, AI_CV_Reflect_End
	if_random_less_than 50, AI_CV_Reflect_End
AI_CV_Reflect_ScoreDown2:
	score -2
AI_CV_Reflect_End:
	end

AI_CV_Reflect_PhysicalTypeList:
	.byte TYPE_NORMAL
	.byte TYPE_FIGHTING
	.byte TYPE_FLYING
	.byte TYPE_POISON
	.byte TYPE_GROUND
	.byte TYPE_ROCK
	.byte TYPE_BUG
	.byte TYPE_GHOST
	.byte TYPE_STEEL
	.byte -1

AI_CV_Poison:
	if_hp_less_than AI_USER, 50, AI_CV_Poison_ScoreDown1
	if_hp_more_than AI_TARGET, 50, AI_CV_Poison_End
AI_CV_Poison_ScoreDown1:
	score -1
AI_CV_Poison_End:
	end

AI_CV_Paralyze:
	if_target_faster AI_CV_Paralyze2
	if_hp_more_than AI_USER, 70, AI_CV_Paralyze_End
	score -1
	goto AI_CV_Paralyze_End

AI_CV_Paralyze2:
	if_random_less_than 20, AI_CV_Paralyze_End
	score +3
AI_CV_Paralyze_End:
	end

AI_CV_VitalThrow:
	if_target_faster AI_CV_VitalThrow_End
	if_hp_more_than AI_USER, 60, AI_CV_VitalThrow_End
	if_hp_less_than AI_USER, 40, AI_CV_VitalThrow2
	if_random_less_than 180, AI_CV_VitalThrow_End
AI_CV_VitalThrow2:
	if_random_less_than 50, AI_CV_VitalThrow_End
	score -1
AI_CV_VitalThrow_End:
	end

AI_CV_Substitute:
	if_hp_more_than AI_USER, 90, AI_CV_Substitute4
	if_hp_more_than AI_USER, 70, AI_CV_Substitute3
	if_hp_more_than AI_USER, 50, AI_CV_Substitute2
	if_random_less_than 100, AI_CV_Substitute2
	score -1
AI_CV_Substitute2:
	if_random_less_than 100, AI_CV_Substitute3
	score -1
AI_CV_Substitute3:
	if_random_less_than 100, AI_CV_Substitute4
	score -1
AI_CV_Substitute4:
	if_target_faster AI_CV_Substitute_End
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_equal EFFECT_SLEEP, AI_CV_Substitute5
	if_equal EFFECT_TOXIC, AI_CV_Substitute5
	if_equal EFFECT_POISON, AI_CV_Substitute5
	if_equal EFFECT_PARALYZE, AI_CV_Substitute5
	if_equal EFFECT_WILL_O_WISP, AI_CV_Substitute5
	if_equal EFFECT_CONFUSE, AI_CV_Substitute6
	if_equal EFFECT_LEECH_SEED, AI_CV_Substitute7
	goto AI_CV_Substitute_End

AI_CV_Substitute5:
	if_not_status AI_TARGET, STATUS1_ANY, AI_CV_Substitute8
	goto AI_CV_Substitute_End

AI_CV_Substitute6:
	if_not_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_Substitute8
	goto AI_CV_Substitute_End

AI_CV_Substitute7:
	if_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_Substitute_End
AI_CV_Substitute8:
	if_random_less_than 100, AI_CV_Substitute_End
	score +1
AI_CV_Substitute_End:
	end

AI_CV_Recharge:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_Recharge_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_Recharge_ScoreDown1
	if_target_faster AI_CV_Recharge2
	if_hp_more_than AI_USER, 40, AI_CV_Recharge_ScoreDown1
	goto AI_CV_Recharge_End

AI_CV_Recharge2:
	if_hp_less_than AI_USER, 60, AI_CV_Recharge_End
AI_CV_Recharge_ScoreDown1:
	score -1
AI_CV_Recharge_End:
	end

AI_CV_Disable:
	if_target_faster AI_CV_Disable_End
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_Disable2
	score +1
	goto AI_CV_Disable_End

AI_CV_Disable2:
	if_random_less_than 100, AI_CV_Disable_End
	score -1
AI_CV_Disable_End:
	end

@ BUG: The original script would score up Counter when the target's types were not physical
@      This is incorrect since Counter only deals double the damage received if hit by a physical attack
AI_CV_Counter:
	if_status AI_TARGET, STATUS1_SLEEP, AI_CV_Counter_ScoreDown1
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_Counter_ScoreDown1
	if_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_Counter_ScoreDown1
	if_hp_more_than AI_USER, 30, AI_CV_Counter2
	if_random_less_than 10, AI_CV_Counter2
	score -1
AI_CV_Counter2:
	if_hp_more_than AI_USER, 50, AI_CV_Counter3
	if_random_less_than 100, AI_CV_Counter3
	score -1
AI_CV_Counter3:
	if_has_move AI_USER, MOVE_MIRROR_COAT, AI_CV_Counter8
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_Counter5
	if_target_not_taunted AI_CV_Counter4
	if_random_less_than 100, AI_CV_Counter4
	score +1
AI_CV_Counter4:
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes AI_CV_Counter_PhysicalTypeList, AI_CV_Counter_ScoreDown1
	if_random_less_than 100, AI_CV_Counter_End
	score +1
	goto AI_CV_Counter_End

AI_CV_Counter5:
	if_target_not_taunted AI_CV_Counter6
	if_random_less_than 100, AI_CV_Counter6
	score +1
AI_CV_Counter6:
#ifdef BUGFIX
	get_target_type1
	if_in_bytes AI_CV_Counter_PhysicalTypeList, AI_CV_Counter7
	get_target_type2
	if_in_bytes AI_CV_Counter_PhysicalTypeList, AI_CV_Counter7
	goto AI_CV_Counter_End
#else
	get_target_type1
	if_in_bytes AI_CV_Counter_PhysicalTypeList, AI_CV_Counter_End
	get_target_type2
	if_in_bytes AI_CV_Counter_PhysicalTypeList, AI_CV_Counter_End
#endif
AI_CV_Counter7:
	if_random_less_than 50, AI_CV_Counter_End
AI_CV_Counter8:
	if_random_less_than 100, AI_CV_Counter9
	score +4
AI_CV_Counter9:
	end

AI_CV_Counter_ScoreDown1:
	score -1
AI_CV_Counter_End:
	end

AI_CV_Counter_PhysicalTypeList:
	.byte TYPE_NORMAL
	.byte TYPE_FIGHTING
	.byte TYPE_FLYING
	.byte TYPE_POISON
	.byte TYPE_GROUND
	.byte TYPE_ROCK
	.byte TYPE_BUG
	.byte TYPE_GHOST
	.byte TYPE_STEEL
	.byte -1

AI_CV_Encore:
	if_any_move_disabled AI_TARGET, AI_CV_Encore2
	if_target_faster AI_CV_Encore_ScoreDown2
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_not_in_bytes AI_CV_Encore_EncouragedMovesToEncore, AI_CV_Encore_ScoreDown2
AI_CV_Encore2:
	if_random_less_than 30, AI_CV_Encore_End
	score +3
	goto AI_CV_Encore_End

AI_CV_Encore_ScoreDown2:
	score -2
AI_CV_Encore_End:
	end

AI_CV_Encore_EncouragedMovesToEncore:
	.byte EFFECT_DREAM_EATER
	.byte EFFECT_ATTACK_UP
	.byte EFFECT_DEFENSE_UP
	.byte EFFECT_SPEED_UP
	.byte EFFECT_SPECIAL_ATTACK_UP
	.byte EFFECT_HAZE
	.byte EFFECT_ROAR
	.byte EFFECT_CONVERSION
	.byte EFFECT_TOXIC
	.byte EFFECT_LIGHT_SCREEN
	.byte EFFECT_REST
	.byte EFFECT_SUPER_FANG
	.byte EFFECT_SPECIAL_DEFENSE_UP_2
	.byte EFFECT_CONFUSE
	.byte EFFECT_POISON
	.byte EFFECT_PARALYZE
	.byte EFFECT_LEECH_SEED
	.byte EFFECT_SPLASH
	.byte EFFECT_ATTACK_UP_2
	.byte EFFECT_ENCORE
	.byte EFFECT_CONVERSION_2
	.byte EFFECT_LOCK_ON
	.byte EFFECT_HEAL_BELL
	.byte EFFECT_MEAN_LOOK
	.byte EFFECT_NIGHTMARE
	.byte EFFECT_PROTECT
	.byte EFFECT_SKILL_SWAP
	.byte EFFECT_FORESIGHT
	.byte EFFECT_PERISH_SONG
	.byte EFFECT_SANDSTORM
	.byte EFFECT_ENDURE
	.byte EFFECT_SWAGGER
	.byte EFFECT_ATTRACT
	.byte EFFECT_SAFEGUARD
	.byte EFFECT_RAIN_DANCE
	.byte EFFECT_SUNNY_DAY
	.byte EFFECT_BELLY_DRUM
	.byte EFFECT_PSYCH_UP
	.byte EFFECT_FUTURE_SIGHT
	.byte EFFECT_FAKE_OUT
	.byte EFFECT_STOCKPILE
	.byte EFFECT_SPIT_UP
	.byte EFFECT_SWALLOW
	.byte EFFECT_HAIL
	.byte EFFECT_TORMENT
	.byte EFFECT_WILL_O_WISP
	.byte EFFECT_FOLLOW_ME
	.byte EFFECT_CHARGE
	.byte EFFECT_TRICK
	.byte EFFECT_ROLE_PLAY
	.byte EFFECT_INGRAIN
	.byte EFFECT_RECYCLE
	.byte EFFECT_KNOCK_OFF
	.byte EFFECT_SKILL_SWAP
	.byte EFFECT_IMPRISON
	.byte EFFECT_REFRESH
	.byte EFFECT_GRUDGE
	.byte EFFECT_TEETER_DANCE
	.byte EFFECT_MUD_SPORT
	.byte EFFECT_WATER_SPORT
	.byte EFFECT_DRAGON_DANCE
	.byte EFFECT_CAMOUFLAGE
	.byte -1

AI_CV_PainSplit:
	if_hp_less_than AI_TARGET, 80, AI_CV_PainSplit_ScoreDown1
	if_target_faster AI_CV_PainSplit2
	if_hp_more_than AI_USER, 40, AI_CV_PainSplit_ScoreDown1
	score +1
	goto AI_CV_PainSplit_End

AI_CV_PainSplit2:
	if_hp_more_than AI_USER, 60, AI_CV_PainSplit_ScoreDown1
	score +1
	goto AI_CV_PainSplit_End

AI_CV_PainSplit_ScoreDown1:
	score -1
AI_CV_PainSplit_End:
	end

AI_CV_Snore:
	score +2
	end

AI_CV_LockOn:
	if_random_less_than 128, AI_CV_LockOn_End
	score +2
AI_CV_LockOn_End:
	end

AI_CV_SleepTalk:
	if_status AI_USER, STATUS1_SLEEP, Score_Plus10
	score -5
	end

AI_CV_DestinyBond:
	score -1
	if_target_faster AI_CV_DestinyBond_End
	if_hp_more_than AI_USER, 70, AI_CV_DestinyBond_End
	if_random_less_than 128, AI_CV_DestinyBond2
	score +1
AI_CV_DestinyBond2:
	if_hp_more_than AI_USER, 50, AI_CV_DestinyBond_End
	if_random_less_than 128, AI_CV_DestinyBond3
	score +1
AI_CV_DestinyBond3:
	if_hp_more_than AI_USER, 30, AI_CV_DestinyBond_End
	if_random_less_than 100, AI_CV_DestinyBond_End
	score +2
AI_CV_DestinyBond_End:
	end

AI_CV_Flail:
	if_target_faster AI_CV_Flail2
	if_hp_more_than AI_USER, 33, AI_CV_Flail_ScoreDown1
	if_hp_more_than AI_USER, 20, AI_CV_Flail_End
	if_hp_less_than AI_USER, 8, AI_CV_Flail_ScoreUp1
	goto AI_CV_Flail3

AI_CV_Flail2:
	if_hp_more_than AI_USER, 60, AI_CV_Flail_ScoreDown1
	if_hp_more_than AI_USER, 40, AI_CV_Flail_End
	goto AI_CV_Flail3

AI_CV_Flail_ScoreUp1:
	score +1
AI_CV_Flail3:
	if_random_less_than 100, AI_CV_Flail_End
	score +1
	goto AI_CV_Flail_End

AI_CV_Flail_ScoreDown1:
	score -1
AI_CV_Flail_End:
	end

AI_CV_HealBell:
	if_status AI_TARGET, STATUS1_ANY, AI_CV_HealBell_End
	if_status_in_party AI_TARGET, STATUS1_ANY, AI_CV_HealBell_End
	score -5
AI_CV_HealBell_End:
	end

AI_CV_Thief:
	get_hold_effect AI_TARGET
	if_not_in_bytes AI_CV_Thief_EncourageItemsToSteal, AI_CV_Thief_ScoreDown2
	if_random_less_than 50, AI_CV_Thief_End
	score +1
	goto AI_CV_Thief_End

AI_CV_Thief_ScoreDown2:
	score -2
AI_CV_Thief_End:
	end

AI_CV_Thief_EncourageItemsToSteal:
	.byte HOLD_EFFECT_CURE_SLP
	.byte HOLD_EFFECT_CURE_STATUS
	.byte HOLD_EFFECT_RESTORE_HP
	.byte HOLD_EFFECT_EVASION_UP
	.byte HOLD_EFFECT_LEFTOVERS
	.byte HOLD_EFFECT_LIGHT_BALL
	.byte HOLD_EFFECT_THICK_CLUB
	.byte -1

AI_CV_Curse:
	get_user_type1
	if_equal TYPE_GHOST, AI_CV_Curse4
	get_user_type2
	if_equal TYPE_GHOST, AI_CV_Curse4
	if_stat_level_more_than AI_USER, STAT_DEF, 9, AI_CV_Curse_End
	if_random_less_than 128, AI_CV_Curse2
	score +1
AI_CV_Curse2:
	if_stat_level_more_than AI_USER, STAT_DEF, 7, AI_CV_Curse_End
	if_random_less_than 128, AI_CV_Curse3
	score +1
AI_CV_Curse3:
	if_stat_level_more_than AI_USER, STAT_DEF, DEFAULT_STAT_STAGE, AI_CV_Curse_End
	if_random_less_than 128, AI_CV_Curse_End
	score +1
	goto AI_CV_Curse_End

AI_CV_Curse4:
	if_hp_more_than AI_USER, 80, AI_CV_Curse_End
	score -1
AI_CV_Curse_End:
	end

AI_CV_Protect:
	get_protect_count AI_USER
	if_more_than 1, AI_CV_Protect_ScoreDown2
	if_status AI_USER, STATUS1_TOXIC_POISON, AI_CV_Protect3
	if_status2 AI_USER, STATUS2_CURSED, AI_CV_Protect3
	if_status3 AI_USER, STATUS3_PERISH_SONG, AI_CV_Protect3
	if_status2 AI_USER, STATUS2_INFATUATION, AI_CV_Protect3
	if_status3 AI_USER, STATUS3_LEECHSEED, AI_CV_Protect3
	if_status3 AI_USER, STATUS3_YAWN, AI_CV_Protect3
	if_has_move_with_effect AI_TARGET, EFFECT_RESTORE_HP, AI_CV_Protect3
	if_has_move_with_effect AI_TARGET, EFFECT_DEFENSE_CURL, AI_CV_Protect3
	if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_Protect_ScoreUp2
	if_status2 AI_TARGET, STATUS2_CURSED, AI_CV_Protect_ScoreUp2
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, AI_CV_Protect_ScoreUp2
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_Protect_ScoreUp2
	if_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_Protect_ScoreUp2
	if_status3 AI_TARGET, STATUS3_YAWN, AI_CV_Protect_ScoreUp2
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_not_equal EFFECT_LOCK_ON, AI_CV_Protect_ScoreUp2
	goto AI_CV_Protect2

AI_CV_Protect_ScoreUp2:
	score +2
AI_CV_Protect2:
	if_random_less_than 128, AI_CV_Protect4
	score -1
AI_CV_Protect4:
	get_protect_count AI_USER
	if_equal 0, AI_CV_Protect_End
	score -1
	if_random_less_than 128, AI_CV_Protect_End
	score -1
	goto AI_CV_Protect_End

AI_CV_Protect3:
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_not_equal EFFECT_LOCK_ON, AI_CV_Protect_End
AI_CV_Protect_ScoreDown2:
	score -2
AI_CV_Protect_End:
	end

@ BUG: Foresight is only encouraged if the user is Ghost type or
@      has high evasion, but should check target instead
AI_CV_Foresight:
#ifdef BUGFIX
	get_target_type1
	if_equal TYPE_GHOST, AI_CV_Foresight2
	get_target_type2
	if_equal TYPE_GHOST, AI_CV_Foresight2
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 8, AI_CV_Foresight3
#else
	get_user_type1
	if_equal TYPE_GHOST, AI_CV_Foresight2
	get_user_type2
	if_equal TYPE_GHOST, AI_CV_Foresight2
	if_stat_level_more_than AI_USER, STAT_EVASION, 8, AI_CV_Foresight3
#endif
	score -2
	goto AI_CV_Foresight_End

AI_CV_Foresight2:
	if_random_less_than 80, AI_CV_Foresight_End
AI_CV_Foresight3:
	if_random_less_than 80, AI_CV_Foresight_End
	score +2
AI_CV_Foresight_End:
	end

AI_CV_Endure:
	if_hp_less_than AI_USER, 4, AI_CV_Endure2
	if_hp_less_than AI_USER, 35, AI_CV_Endure3
AI_CV_Endure2:
	score -1
	goto AI_CV_Endure_End

AI_CV_Endure3:
	if_random_less_than 70, AI_CV_Endure_End
	score +1
AI_CV_Endure_End:
	end

AI_CV_BatonPass:
	if_stat_level_more_than AI_USER, STAT_ATK, 8, AI_CV_BatonPass2
	if_stat_level_more_than AI_USER, STAT_DEF, 8, AI_CV_BatonPass2
	if_stat_level_more_than AI_USER, STAT_SPATK, 8, AI_CV_BatonPass2
	if_stat_level_more_than AI_USER, STAT_SPDEF, 8, AI_CV_BatonPass2
	if_stat_level_more_than AI_USER, STAT_EVASION, 8, AI_CV_BatonPass2
	goto AI_CV_BatonPass5

AI_CV_BatonPass2:
	if_target_faster AI_CV_BatonPass3
	if_hp_more_than AI_USER, 60, AI_CV_BatonPass_End
	goto AI_CV_BatonPass4

AI_CV_BatonPass3:
	if_hp_more_than AI_USER, 70, AI_CV_BatonPass_End
AI_CV_BatonPass4:
	if_random_less_than 80, AI_CV_BatonPass_End
	score +2
	goto AI_CV_BatonPass_End

AI_CV_BatonPass5:
	if_stat_level_more_than AI_USER, STAT_ATK, 7, AI_CV_BatonPass7
	if_stat_level_more_than AI_USER, STAT_DEF, 7, AI_CV_BatonPass7
	if_stat_level_more_than AI_USER, STAT_SPATK, 7, AI_CV_BatonPass7
	if_stat_level_more_than AI_USER, STAT_SPDEF, 7, AI_CV_BatonPass7
	if_stat_level_more_than AI_USER, STAT_EVASION, 7, AI_CV_BatonPass7
	goto AI_CV_BatonPass_ScoreDown2

AI_CV_BatonPass7:
	if_target_faster AI_CV_BatonPass8
	if_hp_more_than AI_USER, 60, AI_CV_BatonPass_ScoreDown2
	goto AI_CV_BatonPass_End

AI_CV_BatonPass8:
	if_hp_less_than AI_USER, 70, AI_CV_BatonPass_End
AI_CV_BatonPass_ScoreDown2:
	score -2
AI_CV_BatonPass_End:
	end

AI_CV_Pursuit:
	is_first_turn_for AI_USER
	if_not_equal 0, AI_CV_Pursuit_End
	get_target_type1
	if_equal TYPE_GHOST, AI_CV_Pursuit2
	get_target_type1
	if_equal TYPE_PSYCHIC, AI_CV_Pursuit2
	get_target_type2
	if_equal TYPE_GHOST, AI_CV_Pursuit2
	get_target_type2
	if_equal TYPE_PSYCHIC, AI_CV_Pursuit2
	goto AI_CV_Pursuit_End

AI_CV_Pursuit2:
	if_random_less_than 128, AI_CV_Pursuit_End
	score +1
AI_CV_Pursuit_End:
	end

AI_CV_RainDance:
	if_user_faster AI_CV_RainDance2
	get_ability AI_USER
	if_equal ABILITY_SWIFT_SWIM, AI_CV_RainDance3
AI_CV_RainDance2:
	if_hp_less_than AI_USER, 40, AI_CV_RainDance_ScoreDown1
	get_weather
	if_equal AI_WEATHER_HAIL, AI_CV_RainDance3
	if_equal AI_WEATHER_SUN, AI_CV_RainDance3
	if_equal AI_WEATHER_SANDSTORM, AI_CV_RainDance3
	get_ability AI_USER
	if_equal ABILITY_RAIN_DISH, AI_CV_RainDance3
	goto AI_CV_RainDance_End

AI_CV_RainDance3:
	score +1
	goto AI_CV_RainDance_End

AI_CV_RainDance_ScoreDown1:
	score -1
AI_CV_RainDance_End:
	end

AI_CV_SunnyDay:
	if_hp_less_than AI_USER, 40, AI_CV_SunnyDay_ScoreDown1
	get_weather
	if_equal AI_WEATHER_HAIL, AI_CV_SunnyDay2
	if_equal AI_WEATHER_RAIN, AI_CV_SunnyDay2
	if_equal AI_WEATHER_SANDSTORM, AI_CV_SunnyDay2
	goto AI_CV_SunnyDay_End

AI_CV_SunnyDay2:
	score +1
	goto AI_CV_SunnyDay_End

AI_CV_SunnyDay_ScoreDown1:
	score -1
AI_CV_SunnyDay_End:
	end

AI_CV_BellyDrum:
	if_hp_less_than AI_USER, 90, AI_CV_BellyDrum_ScoreDown2
	goto AI_CV_BellyDrum_End

AI_CV_BellyDrum_ScoreDown2:
	score -2
AI_CV_BellyDrum_End:
	end

AI_CV_PsychUp:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 8, AI_CV_PsychUp2
	if_stat_level_more_than AI_TARGET, STAT_DEF, 8, AI_CV_PsychUp2
	if_stat_level_more_than AI_TARGET, STAT_SPATK, 8, AI_CV_PsychUp2
	if_stat_level_more_than AI_TARGET, STAT_SPDEF, 8, AI_CV_PsychUp2
	if_stat_level_more_than AI_TARGET, STAT_EVASION, 8, AI_CV_PsychUp2
	goto AI_CV_PsychUp_ScoreDown2

AI_CV_PsychUp2:
	if_stat_level_less_than AI_USER, STAT_ATK, 7, AI_CV_PsychUp3
	if_stat_level_less_than AI_USER, STAT_DEF, 7, AI_CV_PsychUp3
	if_stat_level_less_than AI_USER, STAT_SPATK, 7, AI_CV_PsychUp3
	if_stat_level_less_than AI_USER, STAT_SPDEF, 7, AI_CV_PsychUp3
	if_stat_level_less_than AI_USER, STAT_EVASION, 7, AI_CV_PsychUp_ScoreUp1
	if_random_less_than 50, AI_CV_PsychUp_End
	goto AI_CV_PsychUp_ScoreDown2

AI_CV_PsychUp_ScoreUp1:
	score +1
AI_CV_PsychUp3:
	score +1
	end

AI_CV_PsychUp_ScoreDown2:
	score -2
AI_CV_PsychUp_End:
	end

@ BUG: The original script would score up Mirror Coat when the target's types were not special
@      This is incorrect since Mirror Coat only deals double the damage received if hit by a special attack
AI_CV_MirrorCoat:
	if_status AI_TARGET, STATUS1_SLEEP, AI_CV_MirrorCoat_ScoreDown1
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_MirrorCoat_ScoreDown1
	if_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_MirrorCoat_ScoreDown1
	if_hp_more_than AI_USER, 30, AI_CV_MirrorCoat2
	if_random_less_than 10, AI_CV_MirrorCoat2
	score -1
AI_CV_MirrorCoat2:
	if_hp_more_than AI_USER, 50, AI_CV_MirrorCoat3
	if_random_less_than 100, AI_CV_MirrorCoat3
	score -1
AI_CV_MirrorCoat3:
	if_has_move AI_USER, MOVE_COUNTER, AI_CV_MirrorCoat_ScoreUp4
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, AI_CV_MirrorCoat5
	if_target_not_taunted AI_CV_MirrorCoat4
	if_random_less_than 100, AI_CV_MirrorCoat4
	score +1
AI_CV_MirrorCoat4:
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes AI_CV_MirrorCoat_SpecialTypeList, AI_CV_MirrorCoat_ScoreDown1
	if_random_less_than 100, AI_CV_MirrorCoat_End
	score +1
	goto AI_CV_MirrorCoat_End

AI_CV_MirrorCoat5:
	if_target_not_taunted AI_CV_MirrorCoat6
	if_random_less_than 100, AI_CV_MirrorCoat6
	score +1
AI_CV_MirrorCoat6:
#ifdef BUGFIX
	get_target_type1
	if_in_bytes AI_CV_MirrorCoat_SpecialTypeList, AI_CV_MirrorCoat7
	get_target_type2
	if_in_bytes AI_CV_MirrorCoat_SpecialTypeList, AI_CV_MirrorCoat7
	goto AI_CV_MirrorCoat_End
#else
	get_target_type1
	if_in_bytes AI_CV_MirrorCoat_SpecialTypeList, AI_CV_MirrorCoat_End
	get_target_type2
	if_in_bytes AI_CV_MirrorCoat_SpecialTypeList, AI_CV_MirrorCoat_End
#endif
AI_CV_MirrorCoat7:
	if_random_less_than 50, AI_CV_MirrorCoat_End
AI_CV_MirrorCoat_ScoreUp4:
	if_random_less_than 100, AI_CV_MirrorCoat_ScoreUp4_End
	score +4
AI_CV_MirrorCoat_ScoreUp4_End:
	end

AI_CV_MirrorCoat_ScoreDown1:
	score -1
AI_CV_MirrorCoat_End:
	end

AI_CV_MirrorCoat_SpecialTypeList:
	.byte TYPE_FIRE
	.byte TYPE_WATER
	.byte TYPE_GRASS
	.byte TYPE_ELECTRIC
	.byte TYPE_PSYCHIC
	.byte TYPE_ICE
	.byte TYPE_DRAGON
	.byte TYPE_DARK
	.byte -1

AI_CV_ChargeUpMove:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_ChargeUpMove_ScoreDown2
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_ChargeUpMove_ScoreDown2
	if_has_move_with_effect AI_TARGET, EFFECT_PROTECT, AI_CV_ChargeUpMove_ScoreDown2
	if_hp_more_than AI_USER, 38, AI_CV_ChargeUpMove_End
	score -1
	goto AI_CV_ChargeUpMove_End

AI_CV_ChargeUpMove_ScoreDown2:
	score -2
AI_CV_ChargeUpMove_End:
	end

AI_CV_SemiInvulnerable:
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_PROTECT, AI_CV_SemiInvulnerable2
	score -1
	goto AI_CV_SemiInvulnerable_End

@ BUG: The scripts for checking type-resistance to weather for semi-invulnerable moves are swapped
@      The result is that the AI is encouraged to stall while taking damage from weather
AI_CV_SemiInvulnerable2:
	if_status AI_TARGET, STATUS1_TOXIC_POISON, AI_CV_SemiInvulnerable_TryEncourage
	if_status2 AI_TARGET, STATUS2_CURSED, AI_CV_SemiInvulnerable_TryEncourage
	if_status3 AI_TARGET, STATUS3_LEECHSEED, AI_CV_SemiInvulnerable_TryEncourage
	get_weather
#ifdef BUGFIX
	if_equal AI_WEATHER_HAIL, AI_CV_SemiInvulnerable_CheckIceType
	if_equal AI_WEATHER_SANDSTORM, AI_CV_SemiInvulnerable_CheckSandstormTypes
#else
	if_equal AI_WEATHER_HAIL, AI_CV_SemiInvulnerable_CheckSandstormTypes
	if_equal AI_WEATHER_SANDSTORM, AI_CV_SemiInvulnerable_CheckIceType
#endif
	goto AI_CV_SemiInvulnerable5

AI_CV_SemiInvulnerable_CheckSandstormTypes:
	get_user_type1
	if_in_bytes AI_CV_SandstormResistantTypes, AI_CV_SemiInvulnerable_TryEncourage
	get_user_type2
	if_in_bytes AI_CV_SandstormResistantTypes, AI_CV_SemiInvulnerable_TryEncourage
	goto AI_CV_SemiInvulnerable5

AI_CV_SemiInvulnerable_CheckIceType:
	get_user_type1
	if_equal TYPE_ICE, AI_CV_SemiInvulnerable_TryEncourage
	get_user_type2
	if_equal TYPE_ICE, AI_CV_SemiInvulnerable_TryEncourage
AI_CV_SemiInvulnerable5:
	if_target_faster AI_CV_SemiInvulnerable_End
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_not_equal EFFECT_LOCK_ON, AI_CV_SemiInvulnerable_TryEncourage
	goto AI_CV_SemiInvulnerable_End

AI_CV_SemiInvulnerable_TryEncourage:
	if_random_less_than 80, AI_CV_SemiInvulnerable_End
	score +1
AI_CV_SemiInvulnerable_End:
	end

AI_CV_SandstormResistantTypes:
	.byte TYPE_GROUND
	.byte TYPE_ROCK
	.byte TYPE_STEEL
	.byte -1

AI_CV_FakeOut:
	score +2
	end

AI_CV_SpitUp:
	get_stockpile_count AI_USER
	if_less_than 2, AI_CV_SpitUp_End
	if_random_less_than 80, AI_CV_SpitUp_End
	score +2
AI_CV_SpitUp_End:
	end

AI_CV_Hail:
	if_hp_less_than AI_USER, 40, AI_CV_Hail_ScoreDown1
	get_weather
	if_equal AI_WEATHER_SUN, AI_CV_Hail2
	if_equal AI_WEATHER_RAIN, AI_CV_Hail2
	if_equal AI_WEATHER_SANDSTORM, AI_CV_Hail2
	goto AI_CV_Hail_End

AI_CV_Hail2:
	score +1
	goto AI_CV_Hail_End

AI_CV_Hail_ScoreDown1:
	score -1
AI_CV_Hail_End:
	end

@ BUG: Facade score is increased if the target is statused, but should be if the user is
AI_CV_Facade:
#ifdef BUGFIX
	if_not_status AI_USER, STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON, AI_CV_Facade_End
#else
	if_not_status AI_TARGET, STATUS1_POISON | STATUS1_BURN | STATUS1_PARALYSIS | STATUS1_TOXIC_POISON, AI_CV_Facade_End
#endif
	score +1
AI_CV_Facade_End:
	end

AI_CV_FocusPunch:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_FocusPunch2
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_FocusPunch2
	if_status AI_TARGET, STATUS1_SLEEP, AI_CV_FocusPunch_ScoreUp1
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_FocusPunch3
	if_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_FocusPunch3
	is_first_turn_for AI_USER
	if_not_equal 0, AI_CV_FocusPunch_End
	if_random_less_than 100, AI_CV_FocusPunch_End
	score +1
	goto AI_CV_FocusPunch_End

AI_CV_FocusPunch2:
	score -1
	goto AI_CV_FocusPunch_End

AI_CV_FocusPunch3:
	if_random_less_than 100, AI_CV_FocusPunch_End
	if_status2 AI_USER, STATUS2_SUBSTITUTE, Score_Plus5
AI_CV_FocusPunch_ScoreUp1:
	score +1
AI_CV_FocusPunch_End:
	end

AI_CV_SmellingSalt:
	if_status AI_TARGET, STATUS1_PARALYSIS, AI_CV_SmellingSalt_ScoreUp1
	goto AI_CV_SmellingSalt_End

AI_CV_SmellingSalt_ScoreUp1:
	score +1
AI_CV_SmellingSalt_End:
	end

AI_CV_Trick:
	get_hold_effect AI_USER
	if_in_bytes AI_CV_Trick_EffectsToEncourage2, AI_CV_Trick3
	if_in_bytes AI_CV_Trick_EffectsToEncourage, AI_CV_Trick4
AI_CV_Trick2:
	score -3
	goto AI_CV_Trick_End

AI_CV_Trick3:
	get_hold_effect AI_TARGET
	if_in_bytes AI_CV_Trick_EffectsToEncourage2, AI_CV_Trick2
	score +5
	goto AI_CV_Trick_End

AI_CV_Trick4:
	get_hold_effect AI_TARGET
	if_in_bytes AI_CV_Trick_EffectsToEncourage, AI_CV_Trick2
	if_random_less_than 50, AI_CV_Trick_End
	score +2
AI_CV_Trick_End:
	end

AI_CV_Trick_EffectsToEncourage:
	.byte HOLD_EFFECT_CONFUSE_SPICY
	.byte HOLD_EFFECT_CONFUSE_DRY
	.byte HOLD_EFFECT_CONFUSE_SWEET
	.byte HOLD_EFFECT_CONFUSE_BITTER
	.byte HOLD_EFFECT_CONFUSE_SOUR
	.byte HOLD_EFFECT_MACHO_BRACE
	.byte HOLD_EFFECT_CHOICE_BAND
	.byte -1

AI_CV_Trick_EffectsToEncourage2:
	.byte HOLD_EFFECT_CHOICE_BAND
	.byte -1

AI_CV_ChangeSelfAbility:
	get_ability AI_USER
	if_in_bytes AI_CV_ChangeSelfAbility_AbilitiesToEncourage, AI_CV_ChangeSelfAbility2
	get_ability AI_TARGET
	if_in_bytes AI_CV_ChangeSelfAbility_AbilitiesToEncourage, AI_CV_ChangeSelfAbility3
AI_CV_ChangeSelfAbility2:
	score -1
	goto AI_CV_ChangeSelfAbility_End

AI_CV_ChangeSelfAbility3:
	if_random_less_than 50, AI_CV_ChangeSelfAbility_End
	score +2
AI_CV_ChangeSelfAbility_End:
	end

AI_CV_ChangeSelfAbility_AbilitiesToEncourage:
	.byte ABILITY_SPEED_BOOST
	.byte ABILITY_BATTLE_ARMOR
	.byte ABILITY_SAND_VEIL
	.byte ABILITY_STATIC
	.byte ABILITY_FLASH_FIRE
	.byte ABILITY_WONDER_GUARD
	.byte ABILITY_EFFECT_SPORE
	.byte ABILITY_SWIFT_SWIM
	.byte ABILITY_HUGE_POWER
	.byte ABILITY_RAIN_DISH
	.byte ABILITY_CUTE_CHARM
	.byte ABILITY_SHED_SKIN
	.byte ABILITY_MARVEL_SCALE
	.byte ABILITY_PURE_POWER
	.byte ABILITY_CHLOROPHYLL
	.byte ABILITY_SHIELD_DUST
	.byte -1

AI_CV_Superpower:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_Superpower_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_Superpower_ScoreDown1
	if_stat_level_less_than AI_USER, STAT_ATK, DEFAULT_STAT_STAGE, AI_CV_Superpower_ScoreDown1
	if_target_faster AI_CV_Superpower2
	if_hp_more_than AI_USER, 40, AI_CV_Superpower_ScoreDown1
	goto AI_CV_Superpower_End

AI_CV_Superpower2:
	if_hp_less_than AI_USER, 60, AI_CV_Superpower_End
AI_CV_Superpower_ScoreDown1:
	score -1
AI_CV_Superpower_End:
	end

AI_CV_MagicCoat:
	if_hp_more_than AI_TARGET, 30, AI_CV_MagicCoat2
	if_random_less_than 100, AI_CV_MagicCoat2
	score -1
AI_CV_MagicCoat2:
	is_first_turn_for AI_USER
	if_equal FALSE, AI_CV_MagicCoat4
	if_random_less_than 150, AI_CV_MagicCoat_End
	score +1
	goto AI_CV_MagicCoat_End

AI_CV_MagicCoat3:
	if_random_less_than 50, AI_CV_MagicCoat_End
AI_CV_MagicCoat4:
	if_random_less_than 30, AI_CV_MagicCoat_End
	score -1
AI_CV_MagicCoat_End:
	end

AI_CV_Recycle:
	get_used_held_item AI_USER
	if_not_in_bytes AI_CV_Recycle_ItemsToEncourage, AI_CV_Recycle_ScoreDown2
	if_random_less_than 50, AI_CV_Recycle_End
	score +1
	goto AI_CV_Recycle_End

AI_CV_Recycle_ScoreDown2:
	score -2
AI_CV_Recycle_End:
	end

AI_CV_Recycle_ItemsToEncourage:
	.byte ITEM_CHESTO_BERRY
	.byte ITEM_LUM_BERRY
	.byte ITEM_STARF_BERRY
	.byte -1

AI_CV_Revenge:
	if_status AI_TARGET, STATUS1_SLEEP, AI_CV_Revenge_ScoreDown2
	if_status2 AI_TARGET, STATUS2_INFATUATION, AI_CV_Revenge_ScoreDown2
	if_status2 AI_TARGET, STATUS2_CONFUSION, AI_CV_Revenge_ScoreDown2
	if_random_less_than 180, AI_CV_Revenge_ScoreDown2
	score +2
	goto AI_CV_Revenge_End

AI_CV_Revenge_ScoreDown2:
	score -2
AI_CV_Revenge_End:
	end

AI_CV_BrickBreak:
	if_side_affecting AI_TARGET, SIDE_STATUS_REFLECT, AI_CV_BrickBreak_ScoreUp1
	goto AI_CV_BrickBreak_End

AI_CV_BrickBreak_ScoreUp1:
	score +1
AI_CV_BrickBreak_End:
	end

AI_CV_KnockOff:
	if_hp_less_than AI_TARGET, 30, AI_CV_KnockOff_End
	is_first_turn_for AI_USER
	if_more_than 0, AI_CV_KnockOff_End
	if_random_less_than 180, AI_CV_KnockOff_End
	score +1
AI_CV_KnockOff_End:
	end

AI_CV_Endeavor:
	if_hp_less_than AI_TARGET, 70, AI_CV_Endeavor_ScoreDown1
	if_target_faster AI_CV_Endeavor2
	if_hp_more_than AI_USER, 40, AI_CV_Endeavor_ScoreDown1
	score +1
	goto AI_CV_Endeavor_End

AI_CV_Endeavor2:
	if_hp_more_than AI_USER, 50, AI_CV_Endeavor_ScoreDown1
	score +1
	goto AI_CV_Endeavor_End

AI_CV_Endeavor_ScoreDown1:
	score -1
AI_CV_Endeavor_End:
	end

AI_CV_Eruption:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_Eruption_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_Eruption_ScoreDown1
	if_target_faster AI_CV_Eruption2
	if_hp_more_than AI_TARGET, 50, AI_CV_Eruption_End
	goto AI_CV_Eruption_ScoreDown1

AI_CV_Eruption2:
	if_hp_more_than AI_TARGET, 70, AI_CV_Eruption_End
AI_CV_Eruption_ScoreDown1:
	score -1
AI_CV_Eruption_End:
	end

AI_CV_Imprison:
	is_first_turn_for AI_USER
	if_more_than 0, AI_CV_Imprison_End
	if_random_less_than 100, AI_CV_Imprison_End
	score +2
AI_CV_Imprison_End:
	end

AI_CV_Refresh:
	if_hp_less_than AI_TARGET, 50, AI_CV_Refresh_ScoreDown1
	goto AI_CV_Refresh_End

AI_CV_Refresh_ScoreDown1:
	score -1
AI_CV_Refresh_End:
	end

AI_CV_Snatch:
	is_first_turn_for AI_USER
	if_equal TRUE, AI_CV_Snatch3
	if_random_less_than 30, AI_CV_Snatch_End
	if_target_faster AI_CV_Snatch2
	if_hp_not_equal AI_USER, 100, AI_CV_Snatch5
	if_hp_less_than AI_TARGET, 70, AI_CV_Snatch5
	if_random_less_than 60, AI_CV_Snatch_End
	goto AI_CV_Snatch5

AI_CV_Snatch2:
	if_hp_more_than AI_TARGET, 25, AI_CV_Snatch5
	if_has_move_with_effect AI_TARGET, EFFECT_RESTORE_HP, AI_CV_Snatch3
	if_has_move_with_effect AI_TARGET, EFFECT_DEFENSE_CURL, AI_CV_Snatch3
	goto AI_CV_Snatch4

AI_CV_Snatch3:
	if_random_less_than 150, AI_CV_Snatch_End
	score +2
	goto AI_CV_Snatch_End

AI_CV_Snatch4:
	if_random_less_than 230, AI_CV_Snatch5
	score +1
	goto AI_CV_Snatch_End

AI_CV_Snatch5:
	if_random_less_than 30, AI_CV_Snatch_End
	score -2
AI_CV_Snatch_End:
	end

AI_CV_MudSport:
	if_hp_less_than AI_USER, 50, AI_CV_MudSport_ScoreDown1
	get_target_type1
	if_equal TYPE_ELECTRIC, AI_CV_MudSport2
	get_target_type2
	if_equal TYPE_ELECTRIC, AI_CV_MudSport2
	goto AI_CV_MudSport_ScoreDown1

AI_CV_MudSport2:
	score +1
	goto AI_CV_MudSport_End

AI_CV_MudSport_ScoreDown1:
	score -1
AI_CV_MudSport_End:
	end

AI_CV_Overheat:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, AI_CV_Overheat_ScoreDown1
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, AI_CV_Overheat_ScoreDown1
	if_target_faster AI_CV_Overheat2
	if_hp_more_than AI_USER, 60, AI_CV_Overheat_End
	goto AI_CV_Overheat_ScoreDown1

AI_CV_Overheat2:
	if_hp_more_than AI_USER, 80, AI_CV_Overheat_End
AI_CV_Overheat_ScoreDown1:
	score -1
AI_CV_Overheat_End:
	end

AI_CV_WaterSport:
	if_hp_less_than AI_USER, 50, AI_CV_WaterSport_ScoreDown1
	get_target_type1
	if_equal TYPE_FIRE, AI_CV_WaterSport2
	get_target_type2
	if_equal TYPE_FIRE, AI_CV_WaterSport2
	goto AI_CV_WaterSport_ScoreDown1

AI_CV_WaterSport2:
	score +1
	goto AI_CV_WaterSport_End

AI_CV_WaterSport_ScoreDown1:
	score -1
AI_CV_WaterSport_End:
	end

AI_CV_DragonDance:
	if_target_faster AI_CV_DragonDance2
	if_hp_more_than AI_USER, 50, AI_CV_DragonDance_End
	if_random_less_than 70, AI_CV_DragonDance_End
	score -1
	goto AI_CV_DragonDance_End

AI_CV_DragonDance2:
	if_random_less_than 128, AI_CV_DragonDance_End
	score +1
AI_CV_DragonDance_End:
	end

AI_TryToFaint:
	if_target_is_ally AI_Ret
	if_can_faint AI_TryToFaint_TryToEncourageQuickAttack
	get_how_powerful_move_is
	if_equal MOVE_NOT_MOST_POWERFUL, Score_Minus1
	if_type_effectiveness AI_EFFECTIVENESS_x4, AI_TryToFaint_DoubleSuperEffective
	end

AI_TryToFaint_DoubleSuperEffective:
	if_random_less_than 80, AI_TryToFaint_End
	score +2
	end

AI_TryToFaint_TryToEncourageQuickAttack:
	if_effect EFFECT_EXPLOSION, AI_TryToFaint_End
	if_not_effect EFFECT_QUICK_ATTACK, AI_TryToFaint_ScoreUp4
	score +2
AI_TryToFaint_ScoreUp4:
	score +4
AI_TryToFaint_End:
	end

AI_SetupFirstTurn:
	if_target_is_ally AI_Ret
	get_turn_count
	if_not_equal 0, AI_SetupFirstTurn_End
	get_considered_move_effect
	if_not_in_bytes AI_SetupFirstTurn_SetupEffectsToEncourage, AI_SetupFirstTurn_End
	if_random_less_than 80, AI_SetupFirstTurn_End
	score +2
AI_SetupFirstTurn_End:
	end

AI_SetupFirstTurn_SetupEffectsToEncourage:
	.byte EFFECT_ATTACK_UP
	.byte EFFECT_DEFENSE_UP
	.byte EFFECT_SPEED_UP
	.byte EFFECT_SPECIAL_ATTACK_UP
	.byte EFFECT_SPECIAL_DEFENSE_UP
	.byte EFFECT_ACCURACY_UP
	.byte EFFECT_EVASION_UP
	.byte EFFECT_ATTACK_DOWN
	.byte EFFECT_DEFENSE_DOWN
	.byte EFFECT_SPEED_DOWN
	.byte EFFECT_SPECIAL_ATTACK_DOWN
	.byte EFFECT_SPECIAL_DEFENSE_DOWN
	.byte EFFECT_ACCURACY_DOWN
	.byte EFFECT_EVASION_DOWN
	.byte EFFECT_CONVERSION
	.byte EFFECT_LIGHT_SCREEN
	.byte EFFECT_SPECIAL_DEFENSE_UP_2
	.byte EFFECT_FOCUS_ENERGY
	.byte EFFECT_CONFUSE
	.byte EFFECT_ATTACK_UP_2
	.byte EFFECT_DEFENSE_UP_2
	.byte EFFECT_SPEED_UP_2
	.byte EFFECT_SPECIAL_ATTACK_UP_2
	.byte EFFECT_SPECIAL_DEFENSE_UP_2
	.byte EFFECT_ACCURACY_UP_2
	.byte EFFECT_EVASION_UP_2
	.byte EFFECT_ATTACK_DOWN_2
	.byte EFFECT_DEFENSE_DOWN_2
	.byte EFFECT_SPEED_DOWN_2
	.byte EFFECT_SPECIAL_ATTACK_DOWN_2
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_2
	.byte EFFECT_ACCURACY_DOWN_2
	.byte EFFECT_EVASION_DOWN_2
	.byte EFFECT_REFLECT
	.byte EFFECT_POISON
	.byte EFFECT_PARALYZE
	.byte EFFECT_SUBSTITUTE
	.byte EFFECT_LEECH_SEED
	.byte EFFECT_MINIMIZE
	.byte EFFECT_CURSE
	.byte EFFECT_SWAGGER
	.byte EFFECT_CAMOUFLAGE
	.byte EFFECT_YAWN
	.byte EFFECT_DEFENSE_CURL
	.byte EFFECT_TORMENT
	.byte EFFECT_FLATTER
	.byte EFFECT_WILL_O_WISP
	.byte EFFECT_INGRAIN
	.byte EFFECT_IMPRISON
	.byte EFFECT_TEETER_DANCE
	.byte EFFECT_TICKLE
	.byte EFFECT_COSMIC_POWER
	.byte EFFECT_BULK_UP
	.byte EFFECT_CALM_MIND
	.byte EFFECT_CAMOUFLAGE
	.byte -1

@ ~60% chance to prefer moves that do 0 or 1 damage, or are in sIgnoredPowerfulMoveEffects
@ Oddly this group includes moves like Explosion and Eruption, so the AI strategy isn't very coherent
AI_PreferPowerExtremes:
	if_target_is_ally AI_Ret
	get_how_powerful_move_is
	if_not_equal MOVE_POWER_OTHER, AI_PreferPowerExtremes_End
	if_random_less_than 100, AI_PreferPowerExtremes_End
	score +2
AI_PreferPowerExtremes_End:
	end

AI_Risky:
	if_target_is_ally AI_Ret
	get_considered_move_effect
	if_not_in_bytes AI_Risky_EffectsToEncourage, AI_Risky_End
	if_random_less_than 128, AI_Risky_End
	score +2
AI_Risky_End:
	end

AI_Risky_EffectsToEncourage:
	.byte EFFECT_SLEEP
	.byte EFFECT_EXPLOSION
	.byte EFFECT_MIRROR_MOVE
	.byte EFFECT_OHKO
	.byte EFFECT_HIGH_CRITICAL
	.byte EFFECT_CONFUSE
	.byte EFFECT_METRONOME
	.byte EFFECT_PSYWAVE
	.byte EFFECT_COUNTER
	.byte EFFECT_DESTINY_BOND
	.byte EFFECT_SWAGGER
	.byte EFFECT_ATTRACT
	.byte EFFECT_PRESENT
	.byte EFFECT_ALL_STATS_UP_HIT
	.byte EFFECT_BELLY_DRUM
	.byte EFFECT_MIRROR_COAT
	.byte EFFECT_FOCUS_PUNCH
	.byte EFFECT_REVENGE
	.byte EFFECT_TEETER_DANCE
	.byte -1

AI_PreferBatonPass:
	if_target_is_ally AI_Ret
	count_usable_party_mons AI_USER
	if_equal 0, AI_PreferBatonPassEnd
	get_how_powerful_move_is
	if_not_equal MOVE_POWER_OTHER, AI_PreferBatonPassEnd
	if_has_move_with_effect AI_USER, EFFECT_BATON_PASS, AI_PreferBatonPass_GoForBatonPass
	if_random_less_than 80, AI_Risky_End
AI_PreferBatonPass_GoForBatonPass:
	if_move MOVE_SWORDS_DANCE, AI_PreferBatonPass2
	if_move MOVE_DRAGON_DANCE, AI_PreferBatonPass2
	if_move MOVE_CALM_MIND, AI_PreferBatonPass2
	if_effect EFFECT_PROTECT, AI_PreferBatonPass_End
	if_move MOVE_BATON_PASS, AI_PreferBatonPass_EncourageIfHighStats
	if_random_less_than 20, AI_Risky_End
	score +3
AI_PreferBatonPass2:
	get_turn_count
	if_equal 0, Score_Plus5
	if_hp_less_than AI_USER, 60, Score_Minus10
	goto Score_Plus1

AI_PreferBatonPass_End:
	get_last_used_bank_move AI_USER
	if_in_hwords sMovesTable_ProtectMoves, Score_Minus2
	score +2
	end

sMovesTable_ProtectMoves:
	.2byte MOVE_PROTECT
	.2byte MOVE_DETECT
	.2byte -1

AI_PreferBatonPass_EncourageIfHighStats:
	get_turn_count
	if_equal 0, Score_Minus2
	if_stat_level_more_than AI_USER, STAT_ATK, DEFAULT_STAT_STAGE + 2, Score_Plus3
	if_stat_level_more_than AI_USER, STAT_ATK, DEFAULT_STAT_STAGE + 1, Score_Plus2
	if_stat_level_more_than AI_USER, STAT_ATK, DEFAULT_STAT_STAGE, Score_Plus1
	if_stat_level_more_than AI_USER, STAT_SPATK, DEFAULT_STAT_STAGE + 2, Score_Plus3
	if_stat_level_more_than AI_USER, STAT_SPATK, DEFAULT_STAT_STAGE + 1, Score_Plus2
	if_stat_level_more_than AI_USER, STAT_SPATK, DEFAULT_STAT_STAGE, Score_Plus1
	end

AI_PreferBatonPassEnd:
	end

AI_DoubleBattle:
	if_target_is_ally AI_TryOnAlly
	if_move MOVE_SKILL_SWAP, AI_DoubleBattleSkillSwap
	get_curr_move_type
	if_move MOVE_EARTHQUAKE, AI_DoubleBattleAllHittingGroundMove
	if_move MOVE_MAGNITUDE, AI_DoubleBattleAllHittingGroundMove
	if_equal TYPE_ELECTRIC, AI_DoubleBattleElectricMove
	if_equal TYPE_FIRE, AI_DoubleBattleFireMove
	get_ability AI_USER
	if_not_equal ABILITY_GUTS, AI_DoubleBattleCheckUserStatus
	if_has_move AI_USER_PARTNER, MOVE_HELPING_HAND, AI_DoubleBattlePartnerHasHelpingHand
	end

AI_DoubleBattlePartnerHasHelpingHand:
	get_how_powerful_move_is
	if_not_equal MOVE_POWER_OTHER, Score_Plus1
	end

AI_DoubleBattleCheckUserStatus:
	if_status AI_USER, STATUS1_ANY, AI_DoubleBattleCheckUserStatus2
	end

AI_DoubleBattleCheckUserStatus2:
	get_how_powerful_move_is
	if_equal MOVE_POWER_OTHER, Score_Minus5
	score +1
	if_equal MOVE_MOST_POWERFUL, Score_Plus2
	end

AI_DoubleBattleAllHittingGroundMove:
	if_ability AI_USER_PARTNER, ABILITY_LEVITATE, Score_Plus2
	if_type AI_USER_PARTNER, TYPE_FLYING, Score_Plus2
	if_type AI_USER_PARTNER, TYPE_FIRE, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_ELECTRIC, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_POISON, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_ROCK, Score_Minus10
	goto Score_Minus3

AI_DoubleBattleSkillSwap:
	get_ability AI_USER
	if_equal ABILITY_TRUANT, Score_Plus5
	get_ability AI_TARGET
	if_equal ABILITY_SHADOW_TAG, Score_Plus2
	if_equal ABILITY_PURE_POWER, Score_Plus2
	end

AI_DoubleBattleElectricMove:
	if_no_ability AI_TARGET_PARTNER, ABILITY_LIGHTNING_ROD, AI_DoubleBattleElectricMoveEnd
	score -2
	if_no_type AI_TARGET_PARTNER, TYPE_GROUND, AI_DoubleBattleElectricMoveEnd
	score -8
AI_DoubleBattleElectricMoveEnd:
	end

AI_DoubleBattleFireMove:
	if_flash_fired AI_USER, AI_DoubleBattleFireMove2
	end

AI_DoubleBattleFireMove2:
	goto Score_Plus1

AI_TryOnAlly:
	get_how_powerful_move_is
	if_equal MOVE_POWER_OTHER, AI_TryStatusMoveOnAlly
	get_curr_move_type
	if_equal TYPE_FIRE, AI_TryFireMoveOnAlly
AI_DiscourageOnAlly:
	goto Score_Minus30

AI_TryFireMoveOnAlly:
	if_ability AI_USER_PARTNER, ABILITY_FLASH_FIRE, AI_TryFireMoveOnAlly_FlashFire
	goto AI_DiscourageOnAlly

AI_TryFireMoveOnAlly_FlashFire:
	if_flash_fired AI_USER_PARTNER, AI_DiscourageOnAlly
	goto Score_Plus3

AI_TryStatusMoveOnAlly:
	if_move MOVE_SKILL_SWAP, AI_TrySkillSwapOnAlly
	if_move MOVE_WILL_O_WISP, AI_TryStatusOnAlly
	if_move MOVE_TOXIC, AI_TryStatusOnAlly
	if_move MOVE_HELPING_HAND, AI_TryHelpingHandOnAlly
	if_move MOVE_SWAGGER, AI_TrySwaggerOnAlly
	goto Score_Minus30_

AI_TrySkillSwapOnAlly:
	get_ability AI_TARGET
	if_equal ABILITY_TRUANT, Score_Plus10
	get_ability AI_USER
	if_not_equal ABILITY_LEVITATE, AI_TrySkillSwapOnAlly2
	get_ability AI_TARGET
	if_equal ABILITY_LEVITATE, Score_Minus30_
	get_target_type1
	if_not_equal TYPE_ELECTRIC, AI_TrySkillSwapOnAlly2
	score +1
	get_target_type2
	if_not_equal TYPE_ELECTRIC, AI_TrySkillSwapOnAlly2
	score +1
	end

AI_TrySkillSwapOnAlly2:
	if_not_equal ABILITY_COMPOUND_EYES, Score_Minus30_
	if_has_move AI_USER_PARTNER, MOVE_FIRE_BLAST, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_THUNDER, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_CROSS_CHOP, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_HYDRO_PUMP, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_DYNAMIC_PUNCH, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_BLIZZARD, AI_TrySkillSwapOnAllyPlus3
	if_has_move AI_USER_PARTNER, MOVE_MEGAHORN, AI_TrySkillSwapOnAllyPlus3
	goto Score_Minus30_

AI_TrySkillSwapOnAllyPlus3:
	goto Score_Plus3

AI_TryStatusOnAlly:
	get_ability AI_TARGET
	if_not_equal ABILITY_GUTS, Score_Minus30_
	if_status AI_TARGET, STATUS1_ANY, Score_Minus30_
	if_hp_less_than AI_USER, 91, Score_Minus30_
	goto Score_Plus5

AI_TryHelpingHandOnAlly:
	if_random_less_than 64, Score_Minus1
	goto Score_Plus2

AI_TrySwaggerOnAlly:
	if_holds_item AI_TARGET, ITEM_PERSIM_BERRY, AI_TrySwaggerOnAlly2
	goto Score_Minus30_

AI_TrySwaggerOnAlly2:
	if_stat_level_more_than AI_TARGET, STAT_ATK, 7, AI_TrySwaggerOnAlly_End
	score +3
AI_TrySwaggerOnAlly_End:
	end

Score_Minus30_:
	score -30
	end

AI_HPAware:
	if_target_is_ally AI_TryOnAlly
	if_hp_more_than AI_USER, 70, AI_HPAware_UserHasHighHP
	if_hp_more_than AI_USER, 30, AI_HPAware_UserHasMediumHP
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenLowHP, AI_HPAware_TryToDiscourage
	goto AI_HPAware_ConsiderTarget

AI_HPAware_UserHasHighHP:
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenHighHP, AI_HPAware_TryToDiscourage
	goto AI_HPAware_ConsiderTarget

AI_HPAware_UserHasMediumHP:
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenMediumHP, AI_HPAware_TryToDiscourage
	goto AI_HPAware_ConsiderTarget

AI_HPAware_TryToDiscourage:
	if_random_less_than 50, AI_HPAware_ConsiderTarget
	score -2
AI_HPAware_ConsiderTarget:
	if_hp_more_than AI_TARGET, 70, AI_HPAware_TargetHasHighHP
	if_hp_more_than AI_TARGET, 30, AI_HPAware_TargetHasMediumHP
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenTargetLowHP, AI_HPAware_TargetTryToDiscourage
	goto AI_HPAware_End

AI_HPAware_TargetHasHighHP:
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenTargetHighHP, AI_HPAware_TargetTryToDiscourage
	goto AI_HPAware_End

AI_HPAware_TargetHasMediumHP:
	get_considered_move_effect
	if_in_bytes AI_HPAware_DiscouragedEffectsWhenTargetMediumHP, AI_HPAware_TargetTryToDiscourage
	goto AI_HPAware_End

AI_HPAware_TargetTryToDiscourage:
	if_random_less_than 50, AI_HPAware_End
	score -2
AI_HPAware_End:
	end

AI_HPAware_DiscouragedEffectsWhenHighHP:
	.byte EFFECT_EXPLOSION
	.byte EFFECT_RESTORE_HP
	.byte EFFECT_REST
	.byte EFFECT_DESTINY_BOND
	.byte EFFECT_FLAIL
	.byte EFFECT_ENDURE
	.byte EFFECT_MORNING_SUN
	.byte EFFECT_SYNTHESIS
	.byte EFFECT_MOONLIGHT
	.byte EFFECT_SOFTBOILED
	.byte EFFECT_MEMENTO
	.byte EFFECT_GRUDGE
	.byte EFFECT_OVERHEAT
	.byte -1

AI_HPAware_DiscouragedEffectsWhenMediumHP:
	.byte EFFECT_EXPLOSION
	.byte EFFECT_ATTACK_UP
	.byte EFFECT_DEFENSE_UP
	.byte EFFECT_SPEED_UP
	.byte EFFECT_SPECIAL_ATTACK_UP
	.byte EFFECT_SPECIAL_DEFENSE_UP
	.byte EFFECT_ACCURACY_UP
	.byte EFFECT_EVASION_UP
	.byte EFFECT_ATTACK_DOWN
	.byte EFFECT_DEFENSE_DOWN
	.byte EFFECT_SPEED_DOWN
	.byte EFFECT_SPECIAL_ATTACK_DOWN
	.byte EFFECT_SPECIAL_DEFENSE_DOWN
	.byte EFFECT_ACCURACY_DOWN
	.byte EFFECT_EVASION_DOWN
	.byte EFFECT_BIDE
	.byte EFFECT_CONVERSION
	.byte EFFECT_LIGHT_SCREEN
	.byte EFFECT_MIST
	.byte EFFECT_FOCUS_ENERGY
	.byte EFFECT_ATTACK_UP_2
	.byte EFFECT_DEFENSE_UP_2
	.byte EFFECT_SPEED_UP_2
	.byte EFFECT_SPECIAL_ATTACK_UP_2
	.byte EFFECT_SPECIAL_DEFENSE_UP_2
	.byte EFFECT_ACCURACY_UP_2
	.byte EFFECT_EVASION_UP_2
	.byte EFFECT_ATTACK_DOWN_2
	.byte EFFECT_DEFENSE_DOWN_2
	.byte EFFECT_SPEED_DOWN_2
	.byte EFFECT_SPECIAL_ATTACK_DOWN_2
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_2
	.byte EFFECT_ACCURACY_DOWN_2
	.byte EFFECT_EVASION_DOWN_2
	.byte EFFECT_CONVERSION_2
	.byte EFFECT_SAFEGUARD
	.byte EFFECT_BELLY_DRUM
	.byte EFFECT_TICKLE
	.byte EFFECT_COSMIC_POWER
	.byte EFFECT_BULK_UP
	.byte EFFECT_CALM_MIND
	.byte EFFECT_DRAGON_DANCE
	.byte -1

AI_HPAware_DiscouragedEffectsWhenLowHP:
	.byte EFFECT_ATTACK_UP
	.byte EFFECT_DEFENSE_UP
	.byte EFFECT_SPEED_UP
	.byte EFFECT_SPECIAL_ATTACK_UP
	.byte EFFECT_SPECIAL_DEFENSE_UP
	.byte EFFECT_ACCURACY_UP
	.byte EFFECT_EVASION_UP
	.byte EFFECT_ATTACK_DOWN
	.byte EFFECT_DEFENSE_DOWN
	.byte EFFECT_SPEED_DOWN
	.byte EFFECT_SPECIAL_ATTACK_DOWN
	.byte EFFECT_SPECIAL_DEFENSE_DOWN
	.byte EFFECT_ACCURACY_DOWN
	.byte EFFECT_EVASION_DOWN
	.byte EFFECT_BIDE
	.byte EFFECT_CONVERSION
	.byte EFFECT_LIGHT_SCREEN
	.byte EFFECT_MIST
	.byte EFFECT_FOCUS_ENERGY
	.byte EFFECT_ATTACK_UP_2
	.byte EFFECT_DEFENSE_UP_2
	.byte EFFECT_SPEED_UP_2
	.byte EFFECT_SPECIAL_ATTACK_UP_2
	.byte EFFECT_SPECIAL_DEFENSE_UP_2
	.byte EFFECT_ACCURACY_UP_2
	.byte EFFECT_EVASION_UP_2
	.byte EFFECT_ATTACK_DOWN_2
	.byte EFFECT_DEFENSE_DOWN_2
	.byte EFFECT_SPEED_DOWN_2
	.byte EFFECT_SPECIAL_ATTACK_DOWN_2
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_2
	.byte EFFECT_ACCURACY_DOWN_2
	.byte EFFECT_EVASION_DOWN_2
	.byte EFFECT_RAGE
	.byte EFFECT_CONVERSION_2
	.byte EFFECT_LOCK_ON
	.byte EFFECT_SAFEGUARD
	.byte EFFECT_BELLY_DRUM
	.byte EFFECT_PSYCH_UP
	.byte EFFECT_MIRROR_COAT
	.byte EFFECT_SOLAR_BEAM
	.byte EFFECT_ERUPTION
	.byte EFFECT_TICKLE
	.byte EFFECT_COSMIC_POWER
	.byte EFFECT_BULK_UP
	.byte EFFECT_CALM_MIND
	.byte EFFECT_DRAGON_DANCE
	.byte -1

AI_HPAware_DiscouragedEffectsWhenTargetHighHP:
	.byte -1

AI_HPAware_DiscouragedEffectsWhenTargetMediumHP:
	.byte EFFECT_ATTACK_UP
	.byte EFFECT_DEFENSE_UP
	.byte EFFECT_SPEED_UP
	.byte EFFECT_SPECIAL_ATTACK_UP
	.byte EFFECT_SPECIAL_DEFENSE_UP
	.byte EFFECT_ACCURACY_UP
	.byte EFFECT_EVASION_UP
	.byte EFFECT_ATTACK_DOWN
	.byte EFFECT_DEFENSE_DOWN
	.byte EFFECT_SPEED_DOWN
	.byte EFFECT_SPECIAL_ATTACK_DOWN
	.byte EFFECT_SPECIAL_DEFENSE_DOWN
	.byte EFFECT_ACCURACY_DOWN
	.byte EFFECT_EVASION_DOWN
	.byte EFFECT_MIST
	.byte EFFECT_FOCUS_ENERGY
	.byte EFFECT_ATTACK_UP_2
	.byte EFFECT_DEFENSE_UP_2
	.byte EFFECT_SPEED_UP_2
	.byte EFFECT_SPECIAL_ATTACK_UP_2
	.byte EFFECT_SPECIAL_DEFENSE_UP_2
	.byte EFFECT_ACCURACY_UP_2
	.byte EFFECT_EVASION_UP_2
	.byte EFFECT_ATTACK_DOWN_2
	.byte EFFECT_DEFENSE_DOWN_2
	.byte EFFECT_SPEED_DOWN_2
	.byte EFFECT_SPECIAL_ATTACK_DOWN_2
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_2
	.byte EFFECT_ACCURACY_DOWN_2
	.byte EFFECT_EVASION_DOWN_2
	.byte EFFECT_POISON
	.byte EFFECT_PAIN_SPLIT
	.byte EFFECT_PERISH_SONG
	.byte EFFECT_SAFEGUARD
	.byte EFFECT_TICKLE
	.byte EFFECT_COSMIC_POWER
	.byte EFFECT_BULK_UP
	.byte EFFECT_CALM_MIND
	.byte EFFECT_DRAGON_DANCE
	.byte -1

AI_HPAware_DiscouragedEffectsWhenTargetLowHP:
	.byte EFFECT_SLEEP
	.byte EFFECT_EXPLOSION
	.byte EFFECT_ATTACK_UP
	.byte EFFECT_DEFENSE_UP
	.byte EFFECT_SPEED_UP
	.byte EFFECT_SPECIAL_ATTACK_UP
	.byte EFFECT_SPECIAL_DEFENSE_UP
	.byte EFFECT_ACCURACY_UP
	.byte EFFECT_EVASION_UP
	.byte EFFECT_ATTACK_DOWN
	.byte EFFECT_DEFENSE_DOWN
	.byte EFFECT_SPEED_DOWN
	.byte EFFECT_SPECIAL_ATTACK_DOWN
	.byte EFFECT_SPECIAL_DEFENSE_DOWN
	.byte EFFECT_ACCURACY_DOWN
	.byte EFFECT_EVASION_DOWN
	.byte EFFECT_BIDE
	.byte EFFECT_CONVERSION
	.byte EFFECT_TOXIC
	.byte EFFECT_LIGHT_SCREEN
	.byte EFFECT_OHKO
	.byte EFFECT_SUPER_FANG //Maybe supposed to be EFFECT_RAZOR_WIND
	.byte EFFECT_SUPER_FANG
	.byte EFFECT_MIST
	.byte EFFECT_FOCUS_ENERGY
	.byte EFFECT_CONFUSE
	.byte EFFECT_ATTACK_UP_2
	.byte EFFECT_DEFENSE_UP_2
	.byte EFFECT_SPEED_UP_2
	.byte EFFECT_SPECIAL_ATTACK_UP_2
	.byte EFFECT_SPECIAL_DEFENSE_UP_2
	.byte EFFECT_ACCURACY_UP_2
	.byte EFFECT_EVASION_UP_2
	.byte EFFECT_ATTACK_DOWN_2
	.byte EFFECT_DEFENSE_DOWN_2
	.byte EFFECT_SPEED_DOWN_2
	.byte EFFECT_SPECIAL_ATTACK_DOWN_2
	.byte EFFECT_SPECIAL_DEFENSE_DOWN_2
	.byte EFFECT_ACCURACY_DOWN_2
	.byte EFFECT_EVASION_DOWN_2
	.byte EFFECT_POISON
	.byte EFFECT_PARALYZE
	.byte EFFECT_PAIN_SPLIT
	.byte EFFECT_CONVERSION_2
	.byte EFFECT_LOCK_ON
	.byte EFFECT_SPITE
	.byte EFFECT_PERISH_SONG
	.byte EFFECT_SWAGGER
	.byte EFFECT_FURY_CUTTER
	.byte EFFECT_ATTRACT
	.byte EFFECT_SAFEGUARD
	.byte EFFECT_PSYCH_UP
	.byte EFFECT_MIRROR_COAT
	.byte EFFECT_WILL_O_WISP
	.byte EFFECT_TICKLE
	.byte EFFECT_COSMIC_POWER
	.byte EFFECT_BULK_UP
	.byte EFFECT_CALM_MIND
	.byte EFFECT_DRAGON_DANCE
	.byte -1

@ Given the AI_TryOnAlly at the beginning it's possible that this was the start of a more
@ comprehensive double battle AI script
AI_TrySunnyDayStart:
	if_target_is_ally AI_TryOnAlly
	if_not_effect EFFECT_SUNNY_DAY, AI_TrySunnyDayStart_End
#ifndef BUGFIX  @ funcResult has not been set in this script yet, below call is nonsense
	if_equal FALSE, AI_TrySunnyDayStart_End
#endif
	is_first_turn_for AI_USER
	if_equal FALSE, AI_TrySunnyDayStart_End
	score +5
AI_TrySunnyDayStart_End:
	end

AI_Roaming:
	if_status2 AI_USER, STATUS2_WRAPPED, AI_Roaming_End
	if_status2 AI_USER, STATUS2_ESCAPE_PREVENTION, AI_Roaming_End
	get_ability AI_TARGET
	if_equal ABILITY_SHADOW_TAG, AI_Roaming_End
	get_ability AI_USER
	if_equal ABILITY_LEVITATE, AI_Roaming_Flee
	get_ability AI_TARGET
	if_equal ABILITY_ARENA_TRAP, AI_Roaming_End
AI_Roaming_Flee:
	flee

AI_Roaming_End:
	end

AI_Safari:
	if_random_safari_flee AI_Safari_Flee
	watch

AI_Safari_Flee:
	flee

AI_FirstBattle:
	if_hp_equal AI_TARGET, 20, AI_FirstBattle_Flee
	if_hp_less_than AI_TARGET, 20, AI_FirstBattle_Flee
	end

AI_FirstBattle_Flee:
	flee

AI_Ret:
	end
