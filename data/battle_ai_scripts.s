	.include "include/constants/battle_ai.h"
	.include "include/constants/abilities.h"
	.include "include/constants/items.h"
	.include "include/constants/moves.h"
	.include "include/constants/battle_move_effects.h"
	.include "include/constants/hold_effects.h"
	.include "constants/battle_constants.inc"
	.include "constants/type_constants.inc"
	.include "asm/macros/battle_ai_script.inc"

	.section script_data, "aw", %progbits

	.align 2
gBattleAI_ScriptsTable:: @ 82DBEF8
	.4byte AI_CheckBadMove
	.4byte AI_CheckViability
	.4byte AI_TryToFaint
	.4byte AI_SetupFirstTurn
	.4byte AI_Risky
	.4byte AI_PreferStrongestMove
	.4byte AI_PreferBatonPass
	.4byte AI_DoubleBattle
	.4byte AI_HPAware
	.4byte AI_Unknown
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
	.4byte AI_Roaming
	.4byte AI_Safari
	.4byte AI_FirstBattle

AI_CheckBadMove:
	if_target_is_ally AI_Ret
	if_move MOVE_FISSURE, BattleAIScript_82DBF92
	if_move MOVE_HORN_DRILL, BattleAIScript_82DBF92
	get_how_powerful_move_is
	if_equal 0, BattleAIScript_82DBFFE

BattleAIScript_82DBF92:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_VOLT_ABSORB, BattleAIScript_82DBFBD
	if_equal ABILITY_WATER_ABSORB, BattleAIScript_82DBFCA
	if_equal ABILITY_FLASH_FIRE, BattleAIScript_82DBFD7
	if_equal ABILITY_WONDER_GUARD, BattleAIScript_82DBFE4
	if_equal ABILITY_LEVITATE, BattleAIScript_82DBFEF
	goto BattleAIScript_82DBFF7

BattleAIScript_82DBFBD:
	get_curr_move_type
	if_equal_ TYPE_ELECTRIC, Score_Minus12
	goto BattleAIScript_82DBFF7

BattleAIScript_82DBFCA:
	get_curr_move_type
	if_equal_ TYPE_WATER, Score_Minus12
	goto BattleAIScript_82DBFF7

BattleAIScript_82DBFD7:
	get_curr_move_type
	if_equal_ TYPE_FIRE, Score_Minus12
	goto BattleAIScript_82DBFF7

BattleAIScript_82DBFE4:
	if_type_effectiveness AI_EFFECTIVENESS_x2, BattleAIScript_82DBFF7
	goto Score_Minus10

BattleAIScript_82DBFEF:
	get_curr_move_type
	if_equal_ TYPE_GROUND, Score_Minus10

BattleAIScript_82DBFF7:
	get_how_powerful_move_is
	if_equal 0, BattleAIScript_82DBFFE

BattleAIScript_82DBFFE:
	get_ability AI_TARGET
	if_not_equal ABILITY_SOUNDPROOF, BattleAIScript_82DC045
	if_move MOVE_GROWL, Score_Minus10
	if_move MOVE_ROAR, Score_Minus10
	if_move MOVE_SING, Score_Minus10
	if_move MOVE_SUPERSONIC, Score_Minus10
	if_move MOVE_SCREECH, Score_Minus10
	if_move MOVE_SNORE, Score_Minus10
	if_move MOVE_UPROAR, Score_Minus10
	if_move MOVE_METAL_SOUND, Score_Minus10
	if_move MOVE_GRASS_WHISTLE, Score_Minus10

BattleAIScript_82DC045:
	if_effect EFFECT_SLEEP, BattleAIScript_82DC2D4
	if_effect EFFECT_EXPLOSION, BattleAIScript_82DC2F7
	if_effect EFFECT_DREAM_EATER, BattleAIScript_82DC330
	if_effect EFFECT_ATTACK_UP, BattleAIScript_82DC348
	if_effect EFFECT_DEFENSE_UP, BattleAIScript_82DC351
	if_effect EFFECT_SPEED_UP, BattleAIScript_82DC35A
	if_effect EFFECT_SPECIAL_ATTACK_UP, BattleAIScript_82DC363
	if_effect EFFECT_SPECIAL_DEFENSE_UP, BattleAIScript_82DC36C
	if_effect EFFECT_ACCURACY_UP, BattleAIScript_82DC375
	if_effect EFFECT_EVASION_UP, BattleAIScript_82DC37E
	if_effect EFFECT_ATTACK_DOWN, BattleAIScript_82DC387
	if_effect EFFECT_DEFENSE_DOWN, BattleAIScript_82DC39C
	if_effect EFFECT_SPEED_DOWN, BattleAIScript_82DC3A9
	if_effect EFFECT_SPECIAL_ATTACK_DOWN, BattleAIScript_82DC3BF
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN, BattleAIScript_82DC3CC
	if_effect EFFECT_ACCURACY_DOWN, BattleAIScript_82DC3D9
	if_effect EFFECT_EVASION_DOWN, BattleAIScript_82DC3EE
	if_effect EFFECT_HAZE, BattleAIScript_82DC405
	if_effect EFFECT_BIDE, BattleAIScript_82DC4ED
	if_effect EFFECT_ROAR, BattleAIScript_82DC47B
	if_effect EFFECT_TOXIC, BattleAIScript_82DC48C
	if_effect EFFECT_LIGHT_SCREEN, BattleAIScript_82DC4C5
	if_effect EFFECT_OHKO, BattleAIScript_82DC4D0
	if_effect EFFECT_RAZOR_WIND, BattleAIScript_82DC4ED
	if_effect EFFECT_SUPER_FANG, BattleAIScript_82DC4ED
	if_effect EFFECT_MIST, BattleAIScript_82DC507
	if_effect EFFECT_FOCUS_ENERGY, BattleAIScript_82DC512
	if_effect EFFECT_CONFUSE, BattleAIScript_82DC51D
	if_effect EFFECT_ATTACK_UP_2, BattleAIScript_82DC348
	if_effect EFFECT_DEFENSE_UP_2, BattleAIScript_82DC351
	if_effect EFFECT_SPEED_UP_2, BattleAIScript_82DC35A
	if_effect EFFECT_SPECIAL_ATTACK_UP_2, BattleAIScript_82DC363
	if_effect EFFECT_SPECIAL_DEFENSE_UP_2, BattleAIScript_82DC36C
	if_effect EFFECT_ACCURACY_UP_2, BattleAIScript_82DC375
	if_effect EFFECT_EVASION_UP_2, BattleAIScript_82DC37E
	if_effect EFFECT_ATTACK_DOWN_2, BattleAIScript_82DC387
	if_effect EFFECT_DEFENSE_DOWN_2, BattleAIScript_82DC39C
	if_effect EFFECT_SPEED_DOWN_2, BattleAIScript_82DC3A9
	if_effect EFFECT_SPECIAL_ATTACK_DOWN_2, BattleAIScript_82DC3BF
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN_2, BattleAIScript_82DC3CC
	if_effect EFFECT_ACCURACY_DOWN_2, BattleAIScript_82DC3D9
	if_effect EFFECT_EVASION_DOWN_2, BattleAIScript_82DC3EE
	if_effect EFFECT_REFLECT, BattleAIScript_82DC53A
	if_effect EFFECT_POISON, BattleAIScript_82DC48C
	if_effect EFFECT_PARALYZE, BattleAIScript_82DC545
	if_effect EFFECT_SUBSTITUTE, BattleAIScript_82DC568
	if_effect EFFECT_RECHARGE, BattleAIScript_82DC4ED
	if_effect EFFECT_LEECH_SEED, BattleAIScript_82DC57A
	if_effect EFFECT_DISABLE, BattleAIScript_82DC595
	if_effect EFFECT_LEVEL_DAMAGE, BattleAIScript_82DC4ED
	if_effect EFFECT_PSYWAVE, BattleAIScript_82DC4ED
	if_effect EFFECT_COUNTER, BattleAIScript_82DC4ED
	if_effect EFFECT_ENCORE, BattleAIScript_82DC59D
	if_effect EFFECT_SNORE, BattleAIScript_82DC5A5
	if_effect EFFECT_SLEEP_TALK, BattleAIScript_82DC5A5
	if_effect EFFECT_FLAIL, BattleAIScript_82DC4ED
	if_effect EFFECT_MEAN_LOOK, BattleAIScript_82DC5B0
	if_effect EFFECT_NIGHTMARE, BattleAIScript_82DC31B
	if_effect EFFECT_MINIMIZE, BattleAIScript_82DC37E
	if_effect EFFECT_CURSE, BattleAIScript_82DC5BB
	if_effect EFFECT_SPIKES, BattleAIScript_82DC5CC
	if_effect EFFECT_FORESIGHT, BattleAIScript_82DC5D7
	if_effect EFFECT_PERISH_SONG, BattleAIScript_82DC5E2
	if_effect EFFECT_SANDSTORM, BattleAIScript_82DC5ED
	if_effect EFFECT_SWAGGER, BattleAIScript_82DC51D
	if_effect EFFECT_ATTRACT, BattleAIScript_82DC5F5
	if_effect EFFECT_RETURN, BattleAIScript_82DC4ED
	if_effect EFFECT_PRESENT, BattleAIScript_82DC4ED
	if_effect EFFECT_FRUSTRATION, BattleAIScript_82DC4ED
	if_effect EFFECT_SAFEGUARD, BattleAIScript_82DC635
	if_effect EFFECT_MAGNITUDE, BattleAIScript_82DC4E5
	if_effect EFFECT_BATON_PASS, BattleAIScript_82DC650
	if_effect EFFECT_SONICBOOM, BattleAIScript_82DC4ED
	if_effect EFFECT_RAIN_DANCE, BattleAIScript_82DC659
	if_effect EFFECT_SUNNY_DAY, BattleAIScript_82DC661
	if_effect EFFECT_BELLY_DRUM, BattleAIScript_82DC341
	if_effect EFFECT_PSYCH_UP, BattleAIScript_82DC405
	if_effect EFFECT_MIRROR_COAT, BattleAIScript_82DC4ED
	if_effect EFFECT_SKULL_BASH, BattleAIScript_82DC4ED
	if_effect EFFECT_FUTURE_SIGHT, BattleAIScript_82DC669
	if_effect EFFECT_TELEPORT, Score_Minus10
	if_effect EFFECT_DEFENSE_CURL, BattleAIScript_82DC351
	if_effect EFFECT_FAKE_OUT, BattleAIScript_82DC680
	if_effect EFFECT_STOCKPILE, BattleAIScript_82DC689
	if_effect EFFECT_SPIT_UP, BattleAIScript_82DC692
	if_effect EFFECT_SWALLOW, BattleAIScript_82DC692
	if_effect EFFECT_HAIL, BattleAIScript_82DC6A1
	if_effect EFFECT_TORMENT, BattleAIScript_82DC6A9
	if_effect EFFECT_FLATTER, BattleAIScript_82DC51D
	if_effect EFFECT_WILL_O_WISP, BattleAIScript_82DC6B4
	if_effect EFFECT_MEMENTO, BattleAIScript_82DC640
	if_effect EFFECT_FOCUS_PUNCH, BattleAIScript_82DC4ED
	if_effect EFFECT_HELPING_HAND, BattleAIScript_82DC6E3
	if_effect EFFECT_TRICK, BattleAIScript_82DC6EB
	if_effect EFFECT_INGRAIN, BattleAIScript_82DC6F4
	if_effect EFFECT_SUPERPOWER, BattleAIScript_82DC4ED
	if_effect EFFECT_RECYCLE, BattleAIScript_82DC6FF
	if_effect EFFECT_KNOCK_OFF, BattleAIScript_82DC6EB
	if_effect EFFECT_ENDEAVOR, BattleAIScript_82DC4ED
	if_effect EFFECT_IMPRISON, BattleAIScript_82DC708
	if_effect EFFECT_REFRESH, BattleAIScript_82DC713
	if_effect EFFECT_LOW_KICK, BattleAIScript_82DC4ED
	if_effect EFFECT_MUD_SPORT, BattleAIScript_82DC71E
	if_effect EFFECT_TICKLE, BattleAIScript_82DC729
	if_effect EFFECT_COSMIC_POWER, BattleAIScript_82DC73A
	if_effect EFFECT_BULK_UP, BattleAIScript_82DC74B
	if_effect EFFECT_WATER_SPORT, BattleAIScript_82DC75C
	if_effect EFFECT_CALM_MIND, BattleAIScript_82DC767
	if_effect EFFECT_DRAGON_DANCE, BattleAIScript_82DC778
	end

BattleAIScript_82DC2D4:
	get_ability AI_TARGET
	if_equal ABILITY_INSOMNIA, Score_Minus10
	if_equal ABILITY_VITAL_SPIRIT, Score_Minus10
	if_status AI_TARGET, STATUS_ANY, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	end

BattleAIScript_82DC2F7:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_DAMP, Score_Minus10
	count_usable_party_mons AI_USER
	if_not_equal 0, BattleAIScript_82DC31A
	count_usable_party_mons AI_TARGET
	if_not_equal 0, Score_Minus10
	goto Score_Minus1

BattleAIScript_82DC31A:
	end

BattleAIScript_82DC31B:
	if_status2 AI_TARGET, STATUS2_NIGHTMARE, Score_Minus10
	if_not_status AI_TARGET, STATUS_SLEEP, Score_Minus8
	end

BattleAIScript_82DC330:
	if_not_status AI_TARGET, STATUS_SLEEP, Score_Minus8
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	end

BattleAIScript_82DC341:
	if_hp_less_than AI_USER, 51, Score_Minus10

BattleAIScript_82DC348:
	if_stat_level_equal AI_USER, ATK, 12, Score_Minus10
	end

BattleAIScript_82DC351:
	if_stat_level_equal AI_USER, DEF, 12, Score_Minus10
	end

BattleAIScript_82DC35A:
	if_stat_level_equal AI_USER, SPEED, 12, Score_Minus10
	end

BattleAIScript_82DC363:
	if_stat_level_equal AI_USER, SPATK, 12, Score_Minus10
	end

BattleAIScript_82DC36C:
	if_stat_level_equal AI_USER, SPDEF, 12, Score_Minus10
	end

BattleAIScript_82DC375:
	if_stat_level_equal AI_USER, ACC, 12, Score_Minus10
	end

BattleAIScript_82DC37E:
	if_stat_level_equal AI_USER, EVASION, 12, Score_Minus10
	end

BattleAIScript_82DC387:
	if_stat_level_equal AI_TARGET, ATK, 0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_HYPER_CUTTER, Score_Minus10
	goto BattleAIScript_82DC3F6

BattleAIScript_82DC39C:
	if_stat_level_equal AI_TARGET, DEF, 0, Score_Minus10
	goto BattleAIScript_82DC3F6

BattleAIScript_82DC3A9:
	if_stat_level_equal AI_TARGET, SPEED, 0, Score_Minus10
	if_ability AI_TARGET, ABILITY_SPEED_BOOST, Score_Minus10
	goto BattleAIScript_82DC3F6

BattleAIScript_82DC3BF:
	if_stat_level_equal AI_TARGET, SPATK, 0, Score_Minus10
	goto BattleAIScript_82DC3F6

BattleAIScript_82DC3CC:
	if_stat_level_equal AI_TARGET, SPDEF, 0, Score_Minus10
	goto BattleAIScript_82DC3F6

BattleAIScript_82DC3D9:
	if_stat_level_equal AI_TARGET, ACC, 0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_KEEN_EYE, Score_Minus10
	goto BattleAIScript_82DC3F6

BattleAIScript_82DC3EE:
	if_stat_level_equal AI_TARGET, EVASION, 0, Score_Minus10

BattleAIScript_82DC3F6:
	get_ability AI_TARGET
	if_equal ABILITY_CLEAR_BODY, Score_Minus10
	if_equal ABILITY_WHITE_SMOKE, Score_Minus10
	end

BattleAIScript_82DC405:
	if_stat_level_less_than AI_USER, ATK, 6, BattleAIScript_82DC47A
	if_stat_level_less_than AI_USER, DEF, 6, BattleAIScript_82DC47A
	if_stat_level_less_than AI_USER, SPEED, 6, BattleAIScript_82DC47A
	if_stat_level_less_than AI_USER, SPATK, 6, BattleAIScript_82DC47A
	if_stat_level_less_than AI_USER, SPDEF, 6, BattleAIScript_82DC47A
	if_stat_level_less_than AI_USER, ACC, 6, BattleAIScript_82DC47A
	if_stat_level_less_than AI_USER, EVASION, 6, BattleAIScript_82DC47A
	if_stat_level_more_than AI_TARGET, ATK, 6, BattleAIScript_82DC47A
	if_stat_level_more_than AI_TARGET, DEF, 6, BattleAIScript_82DC47A
	if_stat_level_more_than AI_TARGET, SPEED, 6, BattleAIScript_82DC47A
	if_stat_level_more_than AI_TARGET, SPATK, 6, BattleAIScript_82DC47A
	if_stat_level_more_than AI_TARGET, SPDEF, 6, BattleAIScript_82DC47A
	if_stat_level_more_than AI_TARGET, ACC, 6, BattleAIScript_82DC47A
	if_stat_level_more_than AI_TARGET, EVASION, 6, BattleAIScript_82DC47A
	goto Score_Minus10

BattleAIScript_82DC47A:
	end

BattleAIScript_82DC47B:
	count_usable_party_mons AI_TARGET
	if_equal 0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_SUCTION_CUPS, Score_Minus10
	end

BattleAIScript_82DC48C:
	get_target_type1
	if_equal TYPE_STEEL, Score_Minus10
	if_equal TYPE_POISON, Score_Minus10
	get_target_type2
	if_equal TYPE_STEEL, Score_Minus10
	if_equal TYPE_POISON, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_IMMUNITY, Score_Minus10
	if_status AI_TARGET, STATUS_ANY, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	end

BattleAIScript_82DC4C5:
	if_side_affecting AI_USER, SIDE_STATUS_LIGHTSCREEN, Score_Minus8
	end

BattleAIScript_82DC4D0:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_STURDY, Score_Minus10
	if_level_cond 1, Score_Minus10
	end

BattleAIScript_82DC4E5:
	get_ability AI_TARGET
	if_equal ABILITY_LEVITATE, Score_Minus10

BattleAIScript_82DC4ED:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_not_equal ABILITY_WONDER_GUARD, BattleAIScript_82DC506
	if_type_effectiveness AI_EFFECTIVENESS_x2, BattleAIScript_82DC506
	goto Score_Minus10

BattleAIScript_82DC506:
	end

BattleAIScript_82DC507:
	if_side_affecting AI_USER, SIDE_STATUS_MIST, Score_Minus8
	end

BattleAIScript_82DC512:
	if_status2 AI_USER, STATUS2_FOCUS_ENERGY, Score_Minus10
	end

BattleAIScript_82DC51D:
	if_status2 AI_TARGET, STATUS2_CONFUSION, Score_Minus5
	get_ability AI_TARGET
	if_equal ABILITY_OWN_TEMPO, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	end

BattleAIScript_82DC53A:
	if_side_affecting AI_USER, SIDE_STATUS_REFLECT, Score_Minus8
	end

BattleAIScript_82DC545:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_LIMBER, Score_Minus10
	if_status AI_TARGET, STATUS_ANY, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	end

BattleAIScript_82DC568:
	if_status2 AI_USER, STATUS2_SUBSTITUTE, Score_Minus8
	if_hp_less_than AI_USER, 26, Score_Minus10
	end

BattleAIScript_82DC57A:
	if_status3 AI_TARGET, STATUS3_LEECHSEED, Score_Minus10
	get_target_type1
	if_equal TYPE_GRASS, Score_Minus10
	get_target_type2
	if_equal TYPE_GRASS, Score_Minus10
	end

BattleAIScript_82DC595:
	if_any_move_disabled AI_TARGET, Score_Minus8
	end

BattleAIScript_82DC59D:
	if_any_move_encored AI_TARGET, Score_Minus8
	end

BattleAIScript_82DC5A5:
	if_not_status AI_USER, STATUS_SLEEP, Score_Minus8
	end

BattleAIScript_82DC5B0:
	if_status2 AI_TARGET, STATUS2_ESCAPE_PREVENTION, Score_Minus10
	end

BattleAIScript_82DC5BB:
	if_stat_level_equal AI_USER, ATK, 12, Score_Minus10
	if_stat_level_equal AI_USER, DEF, 12, Score_Minus8
	end

BattleAIScript_82DC5CC:
	if_side_affecting AI_TARGET, SIDE_STATUS_SPIKES, Score_Minus10
	end

BattleAIScript_82DC5D7:
	if_status2 AI_TARGET, STATUS2_FORESIGHT, Score_Minus10
	end

BattleAIScript_82DC5E2:
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, Score_Minus10
	end

BattleAIScript_82DC5ED:
	get_weather
	if_equal AI_WEATHER_SANDSTORM, Score_Minus8
	end

BattleAIScript_82DC5F5:
	if_status2 AI_TARGET, STATUS2_INFATUATION, Score_Minus10
	get_ability AI_TARGET
	if_equal ABILITY_OBLIVIOUS, Score_Minus10
	get_gender AI_USER
	if_equal 0, BattleAIScript_82DC61A
	if_equal 254, BattleAIScript_82DC627
	goto Score_Minus10

BattleAIScript_82DC61A:
	get_gender AI_TARGET
	if_equal 254, BattleAIScript_82DC634
	goto Score_Minus10

BattleAIScript_82DC627:
	get_gender AI_TARGET
	if_equal 0, BattleAIScript_82DC634
	goto Score_Minus10

BattleAIScript_82DC634:
	end

BattleAIScript_82DC635:
	if_side_affecting AI_USER, SIDE_STATUS_SAFEGUARD, Score_Minus8
	end

BattleAIScript_82DC640:
	if_stat_level_equal AI_TARGET, ATK, 0, Score_Minus10
	if_stat_level_equal AI_TARGET, SPATK, 0, Score_Minus8

BattleAIScript_82DC650:
	count_usable_party_mons AI_USER
	if_equal 0, Score_Minus10
	end

BattleAIScript_82DC659:
	get_weather
	if_equal AI_WEATHER_RAIN, Score_Minus8
	end

BattleAIScript_82DC661:
	get_weather
	if_equal AI_WEATHER_SUN, Score_Minus8
	end

BattleAIScript_82DC669:
	if_side_affecting AI_TARGET, SIDE_STATUS_FUTUREATTACK, Score_Minus12
	if_side_affecting AI_USER, SIDE_STATUS_FUTUREATTACK, Score_Minus12
	score +5
	end

BattleAIScript_82DC680:
	is_first_turn_for AI_USER
	if_equal 0, Score_Minus10
	end

BattleAIScript_82DC689:
	get_stockpile_count AI_USER
	if_equal 3, Score_Minus10
	end

BattleAIScript_82DC692:
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	get_stockpile_count AI_USER
	if_equal 0, Score_Minus10
	end

BattleAIScript_82DC6A1:
	get_weather
	if_equal AI_WEATHER_HAIL, Score_Minus8
	end

BattleAIScript_82DC6A9:
	if_status2 AI_TARGET, STATUS2_TORMENT, Score_Minus10
	end

BattleAIScript_82DC6B4:
	get_ability AI_TARGET
	if_equal ABILITY_WATER_VEIL, Score_Minus10
	if_status AI_TARGET, STATUS_ANY, Score_Minus10
	if_type_effectiveness AI_EFFECTIVENESS_x0, Score_Minus10
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, Score_Minus10
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, Score_Minus10
	if_side_affecting AI_TARGET, SIDE_STATUS_SAFEGUARD, Score_Minus10
	end

BattleAIScript_82DC6E3:
	if_not_double_battle Score_Minus10
	end

BattleAIScript_82DC6EB:
	get_ability AI_TARGET
	if_equal ABILITY_STICKY_HOLD, Score_Minus10
	end

BattleAIScript_82DC6F4:
	if_status3 AI_USER, STATUS3_ROOTED, Score_Minus10
	end

BattleAIScript_82DC6FF:
	get_used_held_item AI_USER
	if_equal 0, Score_Minus10
	end

BattleAIScript_82DC708:
	if_status3 AI_USER, STATUS3_IMPRISONED_OTHERS, Score_Minus10
	end

BattleAIScript_82DC713:
	if_not_status AI_USER, STATUS_POISON | STATUS_BURN | STATUS_PARALYSIS | STATUS_TOXIC_POISON, Score_Minus10
	end

BattleAIScript_82DC71E:
	if_status3 AI_USER, STATUS3_MUDSPORT, Score_Minus10
	end

BattleAIScript_82DC729:
	if_stat_level_equal AI_TARGET, ATK, 0, Score_Minus10
	if_stat_level_equal AI_TARGET, DEF, 0, Score_Minus8
	end

BattleAIScript_82DC73A:
	if_stat_level_equal AI_USER, DEF, 12, Score_Minus10
	if_stat_level_equal AI_USER, SPDEF, 12, Score_Minus8
	end

BattleAIScript_82DC74B:
	if_stat_level_equal AI_USER, ATK, 12, Score_Minus10
	if_stat_level_equal AI_USER, DEF, 12, Score_Minus8
	end

BattleAIScript_82DC75C:
	if_status3 AI_USER, STATUS3_WATERSPORT, Score_Minus10
	end

BattleAIScript_82DC767:
	if_stat_level_equal AI_USER, SPATK, 12, Score_Minus10
	if_stat_level_equal AI_USER, SPDEF, 12, Score_Minus8
	end

BattleAIScript_82DC778:
	if_stat_level_equal AI_USER, ATK, 12, Score_Minus10
	if_stat_level_equal AI_USER, SPEED, 12, Score_Minus8
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

AI_TryToFaint:
	if_target_is_ally AI_Ret
	if_effect EFFECT_SLEEP, BattleAIScript_82DCA92
	if_effect EFFECT_ABSORB, BattleAIScript_82DCAAE
	if_effect EFFECT_EXPLOSION, BattleAIScript_82DCAC8
	if_effect EFFECT_DREAM_EATER, BattleAIScript_82DCB26
	if_effect EFFECT_MIRROR_MOVE, BattleAIScript_82DCB3A
	if_effect EFFECT_ATTACK_UP, BattleAIScript_82DCBBC
	if_effect EFFECT_DEFENSE_UP, BattleAIScript_82DCBF7
	if_effect EFFECT_SPEED_UP, BattleAIScript_82DCC5D
	if_effect EFFECT_SPECIAL_ATTACK_UP, BattleAIScript_82DCC73
	if_effect EFFECT_SPECIAL_DEFENSE_UP, BattleAIScript_82DCCAE
	if_effect EFFECT_ACCURACY_UP, BattleAIScript_82DCD14
	if_effect EFFECT_EVASION_UP, BattleAIScript_82DCD2E
	if_effect EFFECT_ALWAYS_HIT, BattleAIScript_82DCDC8
	if_effect EFFECT_ATTACK_DOWN, BattleAIScript_82DCDF8
	if_effect EFFECT_DEFENSE_DOWN, BattleAIScript_82DCE4A
	if_effect EFFECT_SPEED_DOWN, BattleAIScript_82DCE81
	if_effect EFFECT_SPECIAL_ATTACK_DOWN, BattleAIScript_82DCE97
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN, BattleAIScript_82DCEEB
	if_effect EFFECT_ACCURACY_DOWN, BattleAIScript_82DCF0C
	if_effect EFFECT_EVASION_DOWN, BattleAIScript_82DCFA0
	if_effect EFFECT_HAZE, BattleAIScript_82DCFC1
	if_effect EFFECT_BIDE, BattleAIScript_82DD084
	if_effect EFFECT_ROAR, BattleAIScript_82DD08E
	if_effect EFFECT_CONVERSION, BattleAIScript_82DD0C6
	if_effect EFFECT_RESTORE_HP, BattleAIScript_82DD0F7
	if_effect EFFECT_TOXIC, BattleAIScript_82DD150
	if_effect EFFECT_LIGHT_SCREEN, BattleAIScript_82DD18F
	if_effect EFFECT_REST, BattleAIScript_82DD1BE
	if_effect EFFECT_OHKO, BattleAIScript_82DD21E
	if_effect EFFECT_RAZOR_WIND, BattleAIScript_82DDA0B
	if_effect EFFECT_SUPER_FANG, BattleAIScript_82DD21F
	if_effect EFFECT_TRAP, BattleAIScript_82DD229
	if_effect EFFECT_HIGH_CRITICAL, BattleAIScript_82DD25F
	if_effect EFFECT_CONFUSE, BattleAIScript_82DD296
	if_effect EFFECT_ATTACK_UP_2, BattleAIScript_82DCBBC
	if_effect EFFECT_DEFENSE_UP_2, BattleAIScript_82DCBF7
	if_effect EFFECT_SPEED_UP_2, BattleAIScript_82DCC5D
	if_effect EFFECT_SPECIAL_ATTACK_UP_2, BattleAIScript_82DCC73
	if_effect EFFECT_SPECIAL_DEFENSE_UP_2, BattleAIScript_82DCCAE
	if_effect EFFECT_ACCURACY_UP_2, BattleAIScript_82DCD14
	if_effect EFFECT_EVASION_UP_2, BattleAIScript_82DCD2E
	if_effect EFFECT_ATTACK_DOWN_2, BattleAIScript_82DCDF8
	if_effect EFFECT_DEFENSE_DOWN_2, BattleAIScript_82DCE4A
	if_effect EFFECT_SPEED_DOWN_2, BattleAIScript_82DCE81
	if_effect EFFECT_SPECIAL_ATTACK_DOWN_2, BattleAIScript_82DCE97
	if_effect EFFECT_SPECIAL_DEFENSE_DOWN_2, BattleAIScript_82DCEEB
	if_effect EFFECT_ACCURACY_DOWN_2, BattleAIScript_82DCF0C
	if_effect EFFECT_EVASION_DOWN_2, BattleAIScript_82DCFA0
	if_effect EFFECT_REFLECT, BattleAIScript_82DD2D3
	if_effect EFFECT_POISON, BattleAIScript_82DD303
	if_effect EFFECT_PARALYZE, BattleAIScript_82DD314
	if_effect EFFECT_SWAGGER, BattleAIScript_82DD286
	if_effect EFFECT_SPEED_DOWN_HIT, BattleAIScript_82DCE6B
	if_effect EFFECT_SKY_ATTACK, BattleAIScript_82DDA0B
	if_effect EFFECT_VITAL_THROW, BattleAIScript_82DD331
	if_effect EFFECT_SUBSTITUTE, BattleAIScript_82DD354
	if_effect EFFECT_RECHARGE, BattleAIScript_82DD3EA
	if_effect EFFECT_LEECH_SEED, BattleAIScript_82DD150
	if_effect EFFECT_DISABLE, BattleAIScript_82DD412
	if_effect EFFECT_COUNTER, BattleAIScript_82DD431
	if_effect EFFECT_ENCORE, BattleAIScript_82DD4E3
	if_effect EFFECT_PAIN_SPLIT, BattleAIScript_82DD54B
	if_effect EFFECT_SNORE, BattleAIScript_82DD577
	if_effect EFFECT_LOCK_ON, BattleAIScript_82DD57A
	if_effect EFFECT_SLEEP_TALK, BattleAIScript_82DD583
	if_effect EFFECT_DESTINY_BOND, BattleAIScript_82DD590
	if_effect EFFECT_FLAIL, BattleAIScript_82DD5C6
	if_effect EFFECT_HEAL_BELL, BattleAIScript_82DD60B
	if_effect EFFECT_THIEF, BattleAIScript_82DD622
	if_effect EFFECT_MEAN_LOOK, BattleAIScript_82DD229
	if_effect EFFECT_MINIMIZE, BattleAIScript_82DCD2E
	if_effect EFFECT_CURSE, BattleAIScript_82DD645
	if_effect EFFECT_PROTECT, BattleAIScript_82DD694
	if_effect EFFECT_FORESIGHT, BattleAIScript_82DD75D
	if_effect EFFECT_ENDURE, BattleAIScript_82DD78B
	if_effect EFFECT_BATON_PASS, BattleAIScript_82DD7A9
	if_effect EFFECT_PURSUIT, BattleAIScript_82DD845
	if_effect EFFECT_MORNING_SUN, BattleAIScript_82DD0DD
	if_effect EFFECT_SYNTHESIS, BattleAIScript_82DD0DD
	if_effect EFFECT_MOONLIGHT, BattleAIScript_82DD0DD
	if_effect EFFECT_RAIN_DANCE, BattleAIScript_82DD87B
	if_effect EFFECT_SUNNY_DAY, BattleAIScript_82DD8BA
	if_effect EFFECT_BELLY_DRUM, BattleAIScript_82DD8E3
	if_effect EFFECT_PSYCH_UP, BattleAIScript_82DD8F2
	if_effect EFFECT_MIRROR_COAT, BattleAIScript_82DD95A
	if_effect EFFECT_SKULL_BASH, BattleAIScript_82DDA0B
	if_effect EFFECT_SOLARBEAM, BattleAIScript_82DDA0B
	if_effect EFFECT_SEMI_INVULNERABLE, BattleAIScript_82DDA2F
	if_effect EFFECT_SOFTBOILED, BattleAIScript_82DD0F7
	if_effect EFFECT_FAKE_OUT, BattleAIScript_82DDAB9
	if_effect EFFECT_SPIT_UP, BattleAIScript_82DDABC
	if_effect EFFECT_SWALLOW, BattleAIScript_82DD0F7
	if_effect EFFECT_HAIL, BattleAIScript_82DDACD
	if_effect EFFECT_FLATTER, BattleAIScript_82DD28E
	if_effect EFFECT_MEMENTO, BattleAIScript_82DCAC8
	if_effect EFFECT_FACADE, BattleAIScript_82DDAF6
	if_effect EFFECT_FOCUS_PUNCH, BattleAIScript_82DDB03
	if_effect EFFECT_SMELLINGSALT, BattleAIScript_82DDB5C
	if_effect EFFECT_TRICK, BattleAIScript_82DDB6E
	if_effect EFFECT_ROLE_PLAY, BattleAIScript_82DDBB9
	if_effect EFFECT_SUPERPOWER, BattleAIScript_82DDBF0
	if_effect EFFECT_MAGIC_COAT, BattleAIScript_82DDC20
	if_effect EFFECT_RECYCLE, BattleAIScript_82DDC53
	if_effect EFFECT_REVENGE, BattleAIScript_82DDC72
	if_effect EFFECT_BRICK_BREAK, BattleAIScript_82DDCA0
	if_effect EFFECT_KNOCK_OFF, BattleAIScript_82DDCB2
	if_effect EFFECT_ENDEAVOR, BattleAIScript_82DDCCA
	if_effect EFFECT_ERUPTION, BattleAIScript_82DDCF6
	if_effect EFFECT_SKILL_SWAP, BattleAIScript_82DDBB9
	if_effect EFFECT_IMPRISON, BattleAIScript_82DDD1E
	if_effect EFFECT_REFRESH, BattleAIScript_82DDD2F
	if_effect EFFECT_SNATCH, BattleAIScript_82DDD3E
	if_effect EFFECT_BLAZE_KICK, BattleAIScript_82DD25F
	if_effect EFFECT_MUD_SPORT, BattleAIScript_82DDDA8
	if_effect EFFECT_OVERHEAT, BattleAIScript_82DDDCE
	if_effect EFFECT_TICKLE, BattleAIScript_82DCE4A
	if_effect EFFECT_COSMIC_POWER, BattleAIScript_82DCCAE
	if_effect EFFECT_BULK_UP, BattleAIScript_82DCBF7
	if_effect EFFECT_POISON_TAIL, BattleAIScript_82DD25F
	if_effect EFFECT_WATER_SPORT, BattleAIScript_82DDDF6
	if_effect EFFECT_CALM_MIND, BattleAIScript_82DCCAE
	if_effect EFFECT_DRAGON_DANCE, BattleAIScript_82DDE1C
	end

BattleAIScript_82DCA92:
	if_has_move_with_effect AI_TARGET, EFFECT_DREAM_EATER, BattleAIScript_82DCAA5
	if_has_move_with_effect AI_TARGET, EFFECT_NIGHTMARE, BattleAIScript_82DCAA5
	goto BattleAIScript_82DCAAD

BattleAIScript_82DCAA5:
	if_random_less_than 128, BattleAIScript_82DCAAD
	score +1

BattleAIScript_82DCAAD:
	end

BattleAIScript_82DCAAE:
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, BattleAIScript_82DCABF
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, BattleAIScript_82DCABF
	goto BattleAIScript_82DCAC7

BattleAIScript_82DCABF:
	if_random_less_than 50, BattleAIScript_82DCAC7
	score -3

BattleAIScript_82DCAC7:
	end

BattleAIScript_82DCAC8:
	if_stat_level_less_than AI_TARGET, EVASION, 7, BattleAIScript_82DCAE2
	score -1
	if_stat_level_less_than AI_TARGET, EVASION, 10, BattleAIScript_82DCAE2
	if_random_less_than 128, BattleAIScript_82DCAE2
	score -1

BattleAIScript_82DCAE2:
	if_hp_less_than AI_USER, 80, BattleAIScript_82DCAFA
	if_target_faster BattleAIScript_82DCAFA
	if_random_less_than 50, BattleAIScript_82DCB25
	goto Score_Minus3

BattleAIScript_82DCAFA:
	if_hp_more_than AI_USER, 50, BattleAIScript_82DCB1D
	if_random_less_than 128, BattleAIScript_82DCB09
	score +1

BattleAIScript_82DCB09:
	if_hp_more_than AI_USER, 30, BattleAIScript_82DCB25
	if_random_less_than 50, BattleAIScript_82DCB25
	score +1
	goto BattleAIScript_82DCB25

BattleAIScript_82DCB1D:
	if_random_less_than 50, BattleAIScript_82DCB25
	score -1

BattleAIScript_82DCB25:
	end

BattleAIScript_82DCB26:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, BattleAIScript_82DCB37
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, BattleAIScript_82DCB37
	goto BattleAIScript_82DCB39

BattleAIScript_82DCB37:
	score -1

BattleAIScript_82DCB39:
	end

BattleAIScript_82DCB3A:
	if_target_faster BattleAIScript_82DCB58
	get_last_used_bank_move AI_TARGET
	if_not_in_hwords sMovesTable_82DCB6C, BattleAIScript_82DCB58
	if_random_less_than 128, BattleAIScript_82DCB6B
	score +2
	goto BattleAIScript_82DCB6B

BattleAIScript_82DCB58:
	get_last_used_bank_move AI_TARGET
	if_in_hwords sMovesTable_82DCB6C, BattleAIScript_82DCB6B
	if_random_less_than 80, BattleAIScript_82DCB6B
	score -1

BattleAIScript_82DCB6B:
	end

sMovesTable_82DCB6C:
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

BattleAIScript_82DCBBC:
	if_stat_level_less_than AI_USER, ATK, 9, BattleAIScript_82DCBD1
	if_random_less_than 100, BattleAIScript_82DCBE0
	score -1
	goto BattleAIScript_82DCBE0

BattleAIScript_82DCBD1:
	if_hp_not_equal AI_USER, 100, BattleAIScript_82DCBE0
	if_random_less_than 128, BattleAIScript_82DCBE0
	score +2

BattleAIScript_82DCBE0:
	if_hp_more_than AI_USER, 70, BattleAIScript_82DCBF6
	if_hp_less_than AI_USER, 40, BattleAIScript_82DCBF4
	if_random_less_than 40, BattleAIScript_82DCBF6

BattleAIScript_82DCBF4:
	score -2

BattleAIScript_82DCBF6:
	end

BattleAIScript_82DCBF7:
	if_stat_level_less_than AI_USER, DEF, 9, BattleAIScript_82DCC0C
	if_random_less_than 100, BattleAIScript_82DCC1B
	score -1
	goto BattleAIScript_82DCC1B

BattleAIScript_82DCC0C:
	if_hp_not_equal AI_USER, 100, BattleAIScript_82DCC1B
	if_random_less_than 128, BattleAIScript_82DCC1B
	score +2

BattleAIScript_82DCC1B:
	if_hp_less_than AI_USER, 70, BattleAIScript_82DCC28
	if_random_less_than 200, BattleAIScript_82DCC52

BattleAIScript_82DCC28:
	if_hp_less_than AI_USER, 40, BattleAIScript_82DCC50
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, BattleAIScript_82DCC4A
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes sTypesTable_82DCC53, BattleAIScript_82DCC50
	if_random_less_than 60, BattleAIScript_82DCC52

BattleAIScript_82DCC4A:
	if_random_less_than 60, BattleAIScript_82DCC52

BattleAIScript_82DCC50:
	score -2

BattleAIScript_82DCC52:
	end

sTypesTable_82DCC53:
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

BattleAIScript_82DCC5D:
	if_target_faster BattleAIScript_82DCC6A
	score -3
	goto BattleAIScript_82DCC72

BattleAIScript_82DCC6A:
	if_random_less_than 70, BattleAIScript_82DCC72
	score +3

BattleAIScript_82DCC72:
	end

BattleAIScript_82DCC73:
	if_stat_level_less_than AI_USER, SPATK, 9, BattleAIScript_82DCC88
	if_random_less_than 100, BattleAIScript_82DCC97
	score -1
	goto BattleAIScript_82DCC97

BattleAIScript_82DCC88:
	if_hp_not_equal AI_USER, 100, BattleAIScript_82DCC97
	if_random_less_than 128, BattleAIScript_82DCC97
	score +2

BattleAIScript_82DCC97:
	if_hp_more_than AI_USER, 70, BattleAIScript_82DCCAD
	if_hp_less_than AI_USER, 40, BattleAIScript_82DCCAB
	if_random_less_than 70, BattleAIScript_82DCCAD

BattleAIScript_82DCCAB:
	score -2

BattleAIScript_82DCCAD:
	end

BattleAIScript_82DCCAE:
	if_stat_level_less_than AI_USER, SPDEF, 9, BattleAIScript_82DCCC3
	if_random_less_than 100, BattleAIScript_82DCCD2
	score -1
	goto BattleAIScript_82DCCD2

BattleAIScript_82DCCC3:
	if_hp_not_equal AI_USER, 100, BattleAIScript_82DCCD2
	if_random_less_than 128, BattleAIScript_82DCCD2
	score +2

BattleAIScript_82DCCD2:
	if_hp_less_than AI_USER, 70, BattleAIScript_82DCCDF
	if_random_less_than 200, BattleAIScript_82DCD09

BattleAIScript_82DCCDF:
	if_hp_less_than AI_USER, 40, BattleAIScript_82DCD07
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, BattleAIScript_82DCD01
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_in_bytes sTypesTable_82DCD0A, BattleAIScript_82DCD07
	if_random_less_than 60, BattleAIScript_82DCD09

BattleAIScript_82DCD01:
	if_random_less_than 60, BattleAIScript_82DCD09

BattleAIScript_82DCD07:
	score -2

BattleAIScript_82DCD09:
	end

sTypesTable_82DCD0A:
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

BattleAIScript_82DCD14:
	if_stat_level_less_than AI_USER, ACC, 9, BattleAIScript_82DCD24
	if_random_less_than 50, BattleAIScript_82DCD24
	score -2

BattleAIScript_82DCD24:
	if_hp_more_than AI_USER, 70, BattleAIScript_82DCD2D
	score -2

BattleAIScript_82DCD2D:
	end

BattleAIScript_82DCD2E:
	if_hp_less_than AI_USER, 90, BattleAIScript_82DCD3D
	if_random_less_than 100, BattleAIScript_82DCD3D
	score +3

BattleAIScript_82DCD3D:
	if_stat_level_less_than AI_USER, EVASION, 9, BattleAIScript_82DCD4D
	if_random_less_than 128, BattleAIScript_82DCD4D
	score -1

BattleAIScript_82DCD4D:
	if_not_status AI_TARGET, STATUS_TOXIC_POISON, BattleAIScript_82DCD6C
	if_hp_more_than AI_USER, 50, BattleAIScript_82DCD64
	if_random_less_than 80, BattleAIScript_82DCD6C

BattleAIScript_82DCD64:
	if_random_less_than 50, BattleAIScript_82DCD6C
	score +3

BattleAIScript_82DCD6C:
	if_not_status3 AI_TARGET, STATUS3_LEECHSEED, BattleAIScript_82DCD7E
	if_random_less_than 70, BattleAIScript_82DCD7E
	score +3

BattleAIScript_82DCD7E:
	if_not_status3 AI_USER, STATUS3_ROOTED, BattleAIScript_82DCD90
	if_random_less_than 128, BattleAIScript_82DCD90
	score +2

BattleAIScript_82DCD90:
	if_not_status2 AI_TARGET, STATUS2_CURSED, BattleAIScript_82DCDA2
	if_random_less_than 70, BattleAIScript_82DCDA2
	score +3

BattleAIScript_82DCDA2:
	if_hp_more_than AI_USER, 70, BattleAIScript_82DCDC7
	if_stat_level_equal AI_USER, EVASION, 6, BattleAIScript_82DCDC7
	if_hp_less_than AI_USER, 40, BattleAIScript_82DCDC5
	if_hp_less_than AI_TARGET, 40, BattleAIScript_82DCDC5
	if_random_less_than 70, BattleAIScript_82DCDC7

BattleAIScript_82DCDC5:
	score -2

BattleAIScript_82DCDC7:
	end

BattleAIScript_82DCDC8:
	if_stat_level_more_than AI_TARGET, EVASION, 10, BattleAIScript_82DCDED
	if_stat_level_less_than AI_USER, ACC, 2, BattleAIScript_82DCDED
	if_stat_level_more_than AI_TARGET, EVASION, 8, BattleAIScript_82DCDEF
	if_stat_level_less_than AI_USER, ACC, 4, BattleAIScript_82DCDEF
	goto BattleAIScript_82DCDF7

BattleAIScript_82DCDED:
	score +1

BattleAIScript_82DCDEF:
	if_random_less_than 100, BattleAIScript_82DCDF7
	score +1

BattleAIScript_82DCDF7:
	end

BattleAIScript_82DCDF8:
	if_stat_level_equal AI_TARGET, ATK, 6, BattleAIScript_82DCE1B
	score -1
	if_hp_more_than AI_USER, 90, BattleAIScript_82DCE0B
	score -1

BattleAIScript_82DCE0B:
	if_stat_level_more_than AI_TARGET, ATK, 3, BattleAIScript_82DCE1B
	if_random_less_than 50, BattleAIScript_82DCE1B
	score -2

BattleAIScript_82DCE1B:
	if_hp_more_than AI_TARGET, 70, BattleAIScript_82DCE24
	score -2

BattleAIScript_82DCE24:
	get_target_type1
	if_in_bytes sTypesTable_82DCE43, BattleAIScript_82DCE42
	get_target_type2
	if_in_bytes sTypesTable_82DCE43, BattleAIScript_82DCE42
	if_random_less_than 50, BattleAIScript_82DCE42
	score -2

BattleAIScript_82DCE42:
	end

sTypesTable_82DCE43:
    .byte TYPE_NORMAL
    .byte TYPE_FIGHTING
    .byte TYPE_GROUND
    .byte TYPE_ROCK
    .byte TYPE_BUG
    .byte TYPE_STEEL
    .byte -1

BattleAIScript_82DCE4A:
	if_hp_less_than AI_USER, 70, BattleAIScript_82DCE59
	if_stat_level_more_than AI_TARGET, DEF, 3, BattleAIScript_82DCE61

BattleAIScript_82DCE59:
	if_random_less_than 50, BattleAIScript_82DCE61
	score -2

BattleAIScript_82DCE61:
	if_hp_more_than AI_TARGET, 70, BattleAIScript_82DCE6A
	score -2

BattleAIScript_82DCE6A:
	end

BattleAIScript_82DCE6B:
	if_move MOVE_ICY_WIND, BattleAIScript_82DCE81
	if_move MOVE_ROCK_TOMB, BattleAIScript_82DCE81
	if_move MOVE_MUD_SHOT, BattleAIScript_82DCE81
	end

BattleAIScript_82DCE81:
	if_target_faster BattleAIScript_82DCE8E
	score -3
	goto BattleAIScript_82DCE96

BattleAIScript_82DCE8E:
	if_random_less_than 70, BattleAIScript_82DCE96
	score +2

BattleAIScript_82DCE96:
	end

BattleAIScript_82DCE97:
	if_stat_level_equal AI_TARGET, ATK, 6, BattleAIScript_82DCEBA
	score -1
	if_hp_more_than AI_USER, 90, BattleAIScript_82DCEAA
	score -1

BattleAIScript_82DCEAA:
	if_stat_level_more_than AI_TARGET, SPATK, 3, BattleAIScript_82DCEBA
	if_random_less_than 50, BattleAIScript_82DCEBA
	score -2

BattleAIScript_82DCEBA:
	if_hp_more_than AI_TARGET, 70, BattleAIScript_82DCEC3
	score -2

BattleAIScript_82DCEC3:
	get_target_type1
	if_in_bytes sTypesTable_82DCEE2, BattleAIScript_82DCEE1
	get_target_type2
	if_in_bytes sTypesTable_82DCEE2, BattleAIScript_82DCEE1
	if_random_less_than 50, BattleAIScript_82DCEE1
	score -2

BattleAIScript_82DCEE1:
	end

sTypesTable_82DCEE2:
    .byte TYPE_FIRE
    .byte TYPE_WATER
    .byte TYPE_GRASS
    .byte TYPE_ELECTRIC
    .byte TYPE_PSYCHIC
    .byte TYPE_ICE
    .byte TYPE_DRAGON
    .byte TYPE_DARK
    .byte -1

BattleAIScript_82DCEEB:
	if_hp_less_than AI_USER, 70, BattleAIScript_82DCEFA
	if_stat_level_more_than AI_TARGET, SPDEF, 3, BattleAIScript_82DCF02

BattleAIScript_82DCEFA:
	if_random_less_than 50, BattleAIScript_82DCF02
	score -2

BattleAIScript_82DCF02:
	if_hp_more_than AI_TARGET, 70, BattleAIScript_82DCF0B
	score -2

BattleAIScript_82DCF0B:
	end

BattleAIScript_82DCF0C:
	if_hp_less_than AI_USER, 70, BattleAIScript_82DCF1A
	if_hp_more_than AI_TARGET, 70, BattleAIScript_82DCF22

BattleAIScript_82DCF1A:
	if_random_less_than 100, BattleAIScript_82DCF22
	score -1

BattleAIScript_82DCF22:
	if_stat_level_more_than AI_USER, ACC, 4, BattleAIScript_82DCF32
	if_random_less_than 80, BattleAIScript_82DCF32
	score -2

BattleAIScript_82DCF32:
	if_not_status AI_TARGET, STATUS_TOXIC_POISON, BattleAIScript_82DCF44
	if_random_less_than 70, BattleAIScript_82DCF44
	score +2

BattleAIScript_82DCF44:
	if_not_status3 AI_TARGET, STATUS3_LEECHSEED, BattleAIScript_82DCF56
	if_random_less_than 70, BattleAIScript_82DCF56
	score +2

BattleAIScript_82DCF56:
	if_not_status3 AI_USER, STATUS3_ROOTED, BattleAIScript_82DCF68
	if_random_less_than 128, BattleAIScript_82DCF68
	score +1

BattleAIScript_82DCF68:
	if_not_status2 AI_TARGET, STATUS2_CURSED, BattleAIScript_82DCF7A
	if_random_less_than 70, BattleAIScript_82DCF7A
	score +2

BattleAIScript_82DCF7A:
	if_hp_more_than AI_USER, 70, BattleAIScript_82DCF9F
	if_stat_level_equal AI_TARGET, ACC, 6, BattleAIScript_82DCF9F
	if_hp_less_than AI_USER, 40, BattleAIScript_82DCF9D
	if_hp_less_than AI_TARGET, 40, BattleAIScript_82DCF9D
	if_random_less_than 70, BattleAIScript_82DCF9F

BattleAIScript_82DCF9D:
	score -2

BattleAIScript_82DCF9F:
	end

BattleAIScript_82DCFA0:
	if_hp_less_than AI_USER, 70, BattleAIScript_82DCFAF
	if_stat_level_more_than AI_TARGET, EVASION, 3, BattleAIScript_82DCFB7

BattleAIScript_82DCFAF:
	if_random_less_than 50, BattleAIScript_82DCFB7
	score -2

BattleAIScript_82DCFB7:
	if_hp_more_than AI_TARGET, 70, BattleAIScript_82DCFC0
	score -2

BattleAIScript_82DCFC0:
	end

BattleAIScript_82DCFC1:
	if_stat_level_more_than AI_USER, ATK, 8, BattleAIScript_82DD016
	if_stat_level_more_than AI_USER, DEF, 8, BattleAIScript_82DD016
	if_stat_level_more_than AI_USER, SPATK, 8, BattleAIScript_82DD016
	if_stat_level_more_than AI_USER, SPDEF, 8, BattleAIScript_82DD016
	if_stat_level_more_than AI_USER, EVASION, 8, BattleAIScript_82DD016
	if_stat_level_less_than AI_TARGET, ATK, 4, BattleAIScript_82DD016
	if_stat_level_less_than AI_TARGET, DEF, 4, BattleAIScript_82DD016
	if_stat_level_less_than AI_TARGET, SPATK, 4, BattleAIScript_82DD016
	if_stat_level_less_than AI_TARGET, SPDEF, 4, BattleAIScript_82DD016
	if_stat_level_less_than AI_TARGET, ACC, 4, BattleAIScript_82DD016
	goto BattleAIScript_82DD01E

BattleAIScript_82DD016:
	if_random_less_than 50, BattleAIScript_82DD01E
	score -3

BattleAIScript_82DD01E:
	if_stat_level_more_than AI_TARGET, ATK, 8, BattleAIScript_82DD07B
	if_stat_level_more_than AI_TARGET, DEF, 8, BattleAIScript_82DD07B
	if_stat_level_more_than AI_TARGET, SPATK, 8, BattleAIScript_82DD07B
	if_stat_level_more_than AI_TARGET, SPDEF, 8, BattleAIScript_82DD07B
	if_stat_level_more_than AI_TARGET, EVASION, 8, BattleAIScript_82DD07B
	if_stat_level_less_than AI_USER, ATK, 4, BattleAIScript_82DD07B
	if_stat_level_less_than AI_USER, DEF, 4, BattleAIScript_82DD07B
	if_stat_level_less_than AI_USER, SPATK, 4, BattleAIScript_82DD07B
	if_stat_level_less_than AI_USER, SPDEF, 4, BattleAIScript_82DD07B
	if_stat_level_less_than AI_USER, ACC, 4, BattleAIScript_82DD07B
	if_random_less_than 50, BattleAIScript_82DD083
	score -1
	goto BattleAIScript_82DD083

BattleAIScript_82DD07B:
	if_random_less_than 50, BattleAIScript_82DD083
	score +3

BattleAIScript_82DD083:
	end

BattleAIScript_82DD084:
	if_hp_more_than AI_USER, 90, BattleAIScript_82DD08D
	score -2

BattleAIScript_82DD08D:
	end

BattleAIScript_82DD08E:
	if_stat_level_more_than AI_TARGET, ATK, 8, BattleAIScript_82DD0BD
	if_stat_level_more_than AI_TARGET, DEF, 8, BattleAIScript_82DD0BD
	if_stat_level_more_than AI_TARGET, SPATK, 8, BattleAIScript_82DD0BD
	if_stat_level_more_than AI_TARGET, SPDEF, 8, BattleAIScript_82DD0BD
	if_stat_level_more_than AI_TARGET, EVASION, 8, BattleAIScript_82DD0BD
	score -3
	goto BattleAIScript_82DD0C5

BattleAIScript_82DD0BD:
	if_random_less_than 128, BattleAIScript_82DD0C5
	score +2

BattleAIScript_82DD0C5:
	end

BattleAIScript_82DD0C6:
	if_hp_more_than AI_USER, 90, BattleAIScript_82DD0CF
	score -2

BattleAIScript_82DD0CF:
	get_turn_count
	if_equal 0, BattleAIScript_82DD0DC
	if_random_less_than 200, Score_Minus2

BattleAIScript_82DD0DC:
	end

BattleAIScript_82DD0DD:
	get_weather
	if_equal AI_WEATHER_HAIL, BattleAIScript_82DD0F5
	if_equal AI_WEATHER_RAIN, BattleAIScript_82DD0F5
	if_equal AI_WEATHER_SANDSTORM, BattleAIScript_82DD0F5
	goto BattleAIScript_82DD0F7

BattleAIScript_82DD0F5:
	score -2

BattleAIScript_82DD0F7:
	if_hp_equal AI_USER, 100, BattleAIScript_82DD11F
	if_target_faster BattleAIScript_82DD126
	score -8
	goto BattleAIScript_82DD14F

AI_CV_Heal2:
	if_hp_less_than AI_USER, 50, BattleAIScript_82DD13A
	if_hp_more_than AI_USER, 80, BattleAIScript_82DD11F
	if_random_less_than 70, BattleAIScript_82DD13A

BattleAIScript_82DD11F:
	score -3
	goto BattleAIScript_82DD14F

BattleAIScript_82DD126:
	if_hp_less_than AI_USER, 70, BattleAIScript_82DD13A
	if_random_less_than 30, BattleAIScript_82DD13A
	score -3
	goto BattleAIScript_82DD14F

BattleAIScript_82DD13A:
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_SNATCH, BattleAIScript_82DD147
	if_random_less_than 100, BattleAIScript_82DD14F

BattleAIScript_82DD147:
	if_random_less_than 20, BattleAIScript_82DD14F
	score +2

BattleAIScript_82DD14F:
	end

BattleAIScript_82DD150:
	if_user_has_no_attacking_moves BattleAIScript_82DD173
	if_hp_more_than AI_USER, 50, BattleAIScript_82DD164
	if_random_less_than 50, BattleAIScript_82DD164
	score -3

BattleAIScript_82DD164:
	if_hp_more_than AI_TARGET, 50, BattleAIScript_82DD173
	if_random_less_than 50, BattleAIScript_82DD173
	score -3

BattleAIScript_82DD173:
	if_has_move_with_effect AI_USER, EFFECT_SPECIAL_DEFENSE_UP, BattleAIScript_82DD186
	if_has_move_with_effect AI_USER, EFFECT_PROTECT, BattleAIScript_82DD186
	goto BattleAIScript_82DD18E

BattleAIScript_82DD186:
	if_random_less_than 60, BattleAIScript_82DD18E
	score +2

BattleAIScript_82DD18E:
	end

BattleAIScript_82DD18F:
	if_hp_less_than AI_USER, 50, BattleAIScript_82DD1B2
	get_target_type1
	if_in_bytes sTypesTable_82DD1B5, BattleAIScript_82DD1B4
	get_target_type2
	if_in_bytes sTypesTable_82DD1B5, BattleAIScript_82DD1B4
	if_random_less_than 50, BattleAIScript_82DD1B4

BattleAIScript_82DD1B2:
	score -2

BattleAIScript_82DD1B4:
	end

sTypesTable_82DD1B5:
    .byte TYPE_FIRE
    .byte TYPE_WATER
    .byte TYPE_GRASS
    .byte TYPE_ELECTRIC
    .byte TYPE_PSYCHIC
    .byte TYPE_ICE
    .byte TYPE_DRAGON
    .byte TYPE_DARK
    .byte -1

BattleAIScript_82DD1BE:
	if_target_faster BattleAIScript_82DD1ED
	if_hp_not_equal AI_USER, 100, BattleAIScript_82DD1D2
	score -8
	goto BattleAIScript_82DD21D

BattleAIScript_82DD1D2:
	if_hp_less_than AI_USER, 40, BattleAIScript_82DD208
	if_hp_more_than AI_USER, 50, BattleAIScript_82DD1E6
	if_random_less_than 70, BattleAIScript_82DD208

BattleAIScript_82DD1E6:
	score -3
	goto BattleAIScript_82DD21D

BattleAIScript_82DD1ED:
	if_hp_less_than AI_USER, 60, BattleAIScript_82DD208
	if_hp_more_than AI_USER, 70, BattleAIScript_82DD201
	if_random_less_than 50, BattleAIScript_82DD208

BattleAIScript_82DD201:
	score -3
	goto BattleAIScript_82DD21D

BattleAIScript_82DD208:
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_SNATCH, BattleAIScript_82DD215
	if_random_less_than 50, BattleAIScript_82DD21D

BattleAIScript_82DD215:
	if_random_less_than 10, BattleAIScript_82DD21D
	score +3

BattleAIScript_82DD21D:
	end

BattleAIScript_82DD21E:
	end

BattleAIScript_82DD21F:
	if_hp_more_than AI_TARGET, 50, BattleAIScript_82DD228
	score -1

BattleAIScript_82DD228:
	end

BattleAIScript_82DD229:
	if_status AI_TARGET, STATUS_TOXIC_POISON, BattleAIScript_82DD256
	if_status2 AI_TARGET, STATUS2_CURSED, BattleAIScript_82DD256
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, BattleAIScript_82DD256
	if_status2 AI_TARGET, STATUS2_INFATUATION, BattleAIScript_82DD256
	goto BattleAIScript_82DD25E

BattleAIScript_82DD256:
	if_random_less_than 128, BattleAIScript_82DD25E
	score +1

BattleAIScript_82DD25E:
	end

BattleAIScript_82DD25F:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, BattleAIScript_82DD285
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, BattleAIScript_82DD285
	if_type_effectiveness AI_EFFECTIVENESS_x2, BattleAIScript_82DD27D
	if_type_effectiveness AI_EFFECTIVENESS_x4, BattleAIScript_82DD27D
	if_random_less_than 128, BattleAIScript_82DD285

BattleAIScript_82DD27D:
	if_random_less_than 128, BattleAIScript_82DD285
	score +1

BattleAIScript_82DD285:
	end

BattleAIScript_82DD286:
	if_has_move AI_USER, MOVE_PSYCH_UP, BattleAIScript_82DD2B8

BattleAIScript_82DD28E:
	if_random_less_than 128, BattleAIScript_82DD296
	score +1

BattleAIScript_82DD296:
	if_hp_more_than AI_TARGET, 70, BattleAIScript_82DD2B7
	if_random_less_than 128, BattleAIScript_82DD2A5
	score -1

BattleAIScript_82DD2A5:
	if_hp_more_than AI_TARGET, 50, BattleAIScript_82DD2B7
	score -1
	if_hp_more_than AI_TARGET, 30, BattleAIScript_82DD2B7
	score -1

BattleAIScript_82DD2B7:
	end

BattleAIScript_82DD2B8:
	if_stat_level_more_than AI_TARGET, ATK, 3, BattleAIScript_82DD2D0
	score +3
	get_turn_count
	if_not_equal 0, BattleAIScript_82DD2D2
	score +2
	goto BattleAIScript_82DD2D2

BattleAIScript_82DD2D0:
	score -5

BattleAIScript_82DD2D2:
	end

BattleAIScript_82DD2D3:
	if_hp_less_than AI_USER, 50, BattleAIScript_82DD2F6
	get_target_type1
	if_in_bytes sTypesTable_82DD2F9, BattleAIScript_82DD2F8
	get_target_type2
	if_in_bytes sTypesTable_82DD2F9, BattleAIScript_82DD2F8
	if_random_less_than 50, BattleAIScript_82DD2F8

BattleAIScript_82DD2F6:
	score -2

BattleAIScript_82DD2F8:
	end

sTypesTable_82DD2F9:
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

BattleAIScript_82DD303:
	if_hp_less_than AI_USER, 50, BattleAIScript_82DD311
	if_hp_more_than AI_TARGET, 50, BattleAIScript_82DD313

BattleAIScript_82DD311:
	score -1

BattleAIScript_82DD313:
	end

BattleAIScript_82DD314:
	if_target_faster BattleAIScript_82DD328
	if_hp_more_than AI_USER, 70, BattleAIScript_82DD330
	score -1
	goto BattleAIScript_82DD330

BattleAIScript_82DD328:
	if_random_less_than 20, BattleAIScript_82DD330
	score +3

BattleAIScript_82DD330:
	end

BattleAIScript_82DD331:
	if_target_faster BattleAIScript_82DD353
	if_hp_more_than AI_USER, 60, BattleAIScript_82DD353
	if_hp_less_than AI_USER, 40, BattleAIScript_82DD34B
	if_random_less_than 180, BattleAIScript_82DD353

BattleAIScript_82DD34B:
	if_random_less_than 50, BattleAIScript_82DD353
	score -1

BattleAIScript_82DD353:
	end

BattleAIScript_82DD354:
	if_hp_more_than AI_USER, 90, BattleAIScript_82DD381
	if_hp_more_than AI_USER, 70, BattleAIScript_82DD379
	if_hp_more_than AI_USER, 50, BattleAIScript_82DD371
	if_random_less_than 100, BattleAIScript_82DD371
	score -1

BattleAIScript_82DD371:
	if_random_less_than 100, BattleAIScript_82DD379
	score -1

BattleAIScript_82DD379:
	if_random_less_than 100, BattleAIScript_82DD381
	score -1

BattleAIScript_82DD381:
	if_target_faster BattleAIScript_82DD3E9
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_equal EFFECT_SLEEP, BattleAIScript_82DD3B9
	if_equal EFFECT_TOXIC, BattleAIScript_82DD3B9
	if_equal EFFECT_POISON, BattleAIScript_82DD3B9
	if_equal EFFECT_PARALYZE, BattleAIScript_82DD3B9
	if_equal EFFECT_WILL_O_WISP, BattleAIScript_82DD3B9
	if_equal EFFECT_CONFUSE, BattleAIScript_82DD3C8
	if_equal EFFECT_LEECH_SEED, BattleAIScript_82DD3D7
	goto BattleAIScript_82DD3E9

BattleAIScript_82DD3B9:
	if_not_status AI_TARGET, STATUS_ANY, BattleAIScript_82DD3E1
	goto BattleAIScript_82DD3E9

BattleAIScript_82DD3C8:
	if_not_status2 AI_TARGET, STATUS2_CONFUSION, BattleAIScript_82DD3E1
	goto BattleAIScript_82DD3E9

BattleAIScript_82DD3D7:
	if_status3 AI_TARGET, STATUS3_LEECHSEED, BattleAIScript_82DD3E9

BattleAIScript_82DD3E1:
	if_random_less_than 100, BattleAIScript_82DD3E9
	score +1

BattleAIScript_82DD3E9:
	end

BattleAIScript_82DD3EA:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, BattleAIScript_82DD40F
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, BattleAIScript_82DD40F
	if_target_faster BattleAIScript_82DD408
	if_hp_more_than AI_USER, 40, BattleAIScript_82DD40F
	goto BattleAIScript_82DD411

BattleAIScript_82DD408:
	if_hp_less_than AI_USER, 60, BattleAIScript_82DD411

BattleAIScript_82DD40F:
	score -1

BattleAIScript_82DD411:
	end

BattleAIScript_82DD412:
	if_target_faster BattleAIScript_82DD430
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, BattleAIScript_82DD428
	score +1
	goto BattleAIScript_82DD430

BattleAIScript_82DD428:
	if_random_less_than 100, BattleAIScript_82DD430
	score -1

BattleAIScript_82DD430:
	end

BattleAIScript_82DD431:
	if_status AI_TARGET, STATUS_SLEEP, BattleAIScript_82DD4D6
	if_status2 AI_TARGET, STATUS2_INFATUATION, BattleAIScript_82DD4D6
	if_status2 AI_TARGET, STATUS2_CONFUSION, BattleAIScript_82DD4D6
	if_hp_more_than AI_USER, 30, BattleAIScript_82DD45E
	if_random_less_than 10, BattleAIScript_82DD45E
	score -1

BattleAIScript_82DD45E:
	if_hp_more_than AI_USER, 50, BattleAIScript_82DD46D
	if_random_less_than 100, BattleAIScript_82DD46D
	score -1

BattleAIScript_82DD46D:
	if_has_move AI_USER, MOVE_MIRROR_COAT, BattleAIScript_82DD4CD
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, BattleAIScript_82DD4A4
	if_target_not_taunted BattleAIScript_82DD48B
	if_random_less_than 100, BattleAIScript_82DD48B
	score +1

BattleAIScript_82DD48B:
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes sTypesTable_82DD4D9, BattleAIScript_82DD4D6
	if_random_less_than 100, BattleAIScript_82DD4D8
	score +1
	goto BattleAIScript_82DD4D8

BattleAIScript_82DD4A4:
	if_target_not_taunted BattleAIScript_82DD4B1
	if_random_less_than 100, BattleAIScript_82DD4B1
	score +1

BattleAIScript_82DD4B1:
	get_target_type1
	if_in_bytes sTypesTable_82DD4D9, BattleAIScript_82DD4D8
	get_target_type2
	if_in_bytes sTypesTable_82DD4D9, BattleAIScript_82DD4D8
	if_random_less_than 50, BattleAIScript_82DD4D8

BattleAIScript_82DD4CD:
	if_random_less_than 100, BattleAIScript_82DD4D5
	score +4

BattleAIScript_82DD4D5:
	end

BattleAIScript_82DD4D6:
	score -1

BattleAIScript_82DD4D8:
	end

sTypesTable_82DD4D9:
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

BattleAIScript_82DD4E3:
	if_any_move_disabled AI_TARGET, BattleAIScript_82DD4FC
	if_target_faster BattleAIScript_82DD509
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_not_in_bytes sMoveEffectsTable_82DD50C, BattleAIScript_82DD509

BattleAIScript_82DD4FC:
	if_random_less_than 30, BattleAIScript_82DD50B
	score +3
	goto BattleAIScript_82DD50B

BattleAIScript_82DD509:
	score -2

BattleAIScript_82DD50B:
	end

sMoveEffectsTable_82DD50C:
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

BattleAIScript_82DD54B:
	if_hp_less_than AI_TARGET, 80, BattleAIScript_82DD574
	if_target_faster BattleAIScript_82DD566
	if_hp_more_than AI_USER, 40, BattleAIScript_82DD574
	score +1
	goto BattleAIScript_82DD576

BattleAIScript_82DD566:
	if_hp_more_than AI_USER, 60, BattleAIScript_82DD574
	score +1
	goto BattleAIScript_82DD576

BattleAIScript_82DD574:
	score -1

BattleAIScript_82DD576:
	end

BattleAIScript_82DD577:
	score +2
	end

BattleAIScript_82DD57A:
	if_random_less_than 128, BattleAIScript_82DD582
	score +2

BattleAIScript_82DD582:
	end

BattleAIScript_82DD583:
	if_status AI_USER, STATUS_SLEEP, Score_Plus10
	score -5
	end

BattleAIScript_82DD590:
	score -1
	if_target_faster BattleAIScript_82DD5C5
	if_hp_more_than AI_USER, 70, BattleAIScript_82DD5C5
	if_random_less_than 128, BattleAIScript_82DD5A7
	score +1

BattleAIScript_82DD5A7:
	if_hp_more_than AI_USER, 50, BattleAIScript_82DD5C5
	if_random_less_than 128, BattleAIScript_82DD5B6
	score +1

BattleAIScript_82DD5B6:
	if_hp_more_than AI_USER, 30, BattleAIScript_82DD5C5
	if_random_less_than 100, BattleAIScript_82DD5C5
	score +2

BattleAIScript_82DD5C5:
	end

BattleAIScript_82DD5C6:
	if_target_faster BattleAIScript_82DD5E6
	if_hp_more_than AI_USER, 33, BattleAIScript_82DD608
	if_hp_more_than AI_USER, 20, BattleAIScript_82DD60A
	if_hp_less_than AI_USER, 8, BattleAIScript_82DD5F9
	goto BattleAIScript_82DD5FB

BattleAIScript_82DD5E6:
	if_hp_more_than AI_USER, 60, BattleAIScript_82DD608
	if_hp_more_than AI_USER, 40, BattleAIScript_82DD60A
	goto BattleAIScript_82DD5FB

BattleAIScript_82DD5F9:
	score +1

BattleAIScript_82DD5FB:
	if_random_less_than 100, BattleAIScript_82DD60A
	score +1
	goto BattleAIScript_82DD60A

BattleAIScript_82DD608:
	score -1

BattleAIScript_82DD60A:
	end

BattleAIScript_82DD60B:
	if_status AI_TARGET, STATUS_ANY, BattleAIScript_82DD621
	if_status_in_party AI_TARGET, STATUS_ANY, BattleAIScript_82DD621
	score -5

BattleAIScript_82DD621:
	end

BattleAIScript_82DD622:
	get_hold_effect AI_TARGET
	if_not_in_bytes sHoldEffectsTable_82DD63D, BattleAIScript_82DD63A
	if_random_less_than 50, BattleAIScript_82DD63C
	score +1
	goto BattleAIScript_82DD63C

BattleAIScript_82DD63A:
	score -2

BattleAIScript_82DD63C:
	end

sHoldEffectsTable_82DD63D:
    .byte HOLD_EFFECT_CURE_SLP
    .byte HOLD_EFFECT_CURE_STATUS
    .byte HOLD_EFFECT_RESTORE_HP
    .byte HOLD_EFFECT_EVASION_UP
    .byte HOLD_EFFECT_LEFTOVERS
    .byte HOLD_EFFECT_LIGHT_BALL
    .byte HOLD_EFFECT_THICK_CLUB
    .byte -1

BattleAIScript_82DD645:
	get_user_type1
	if_equal TYPE_GHOST, BattleAIScript_82DD68A
	get_user_type2
	if_equal TYPE_GHOST, BattleAIScript_82DD68A
	if_stat_level_more_than AI_USER, DEF, 9, BattleAIScript_82DD693
	if_random_less_than 128, BattleAIScript_82DD665
	score +1

BattleAIScript_82DD665:
	if_stat_level_more_than AI_USER, DEF, 7, BattleAIScript_82DD693
	if_random_less_than 128, BattleAIScript_82DD675
	score +1

BattleAIScript_82DD675:
	if_stat_level_more_than AI_USER, DEF, 6, BattleAIScript_82DD693
	if_random_less_than 128, BattleAIScript_82DD693
	score +1
	goto BattleAIScript_82DD693

BattleAIScript_82DD68A:
	if_hp_more_than AI_USER, 80, BattleAIScript_82DD693
	score -1

BattleAIScript_82DD693:
	end

BattleAIScript_82DD694:
	get_protect_count AI_USER
	if_more_than 1, BattleAIScript_82DD75A
	if_status AI_USER, STATUS_TOXIC_POISON, BattleAIScript_82DD751
	if_status2 AI_USER, STATUS2_CURSED, BattleAIScript_82DD751
	if_status3 AI_USER, STATUS3_PERISH_SONG, BattleAIScript_82DD751
	if_status2 AI_USER, STATUS2_INFATUATION, BattleAIScript_82DD751
	if_status3 AI_USER, STATUS3_LEECHSEED, BattleAIScript_82DD751
	if_status3 AI_USER, STATUS3_YAWN, BattleAIScript_82DD751
	if_has_move_with_effect AI_TARGET, EFFECT_RESTORE_HP, BattleAIScript_82DD751
	if_has_move_with_effect AI_TARGET, EFFECT_DEFENSE_CURL, BattleAIScript_82DD751
	if_status AI_TARGET, STATUS_TOXIC_POISON, BattleAIScript_82DD730
	if_status2 AI_TARGET, STATUS2_CURSED, BattleAIScript_82DD730
	if_status3 AI_TARGET, STATUS3_PERISH_SONG, BattleAIScript_82DD730
	if_status2 AI_TARGET, STATUS2_INFATUATION, BattleAIScript_82DD730
	if_status3 AI_TARGET, STATUS3_LEECHSEED, BattleAIScript_82DD730
	if_status3 AI_TARGET, STATUS3_YAWN, BattleAIScript_82DD730
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_not_equal EFFECT_LOCK_ON, BattleAIScript_82DD730
	goto BattleAIScript_82DD732

BattleAIScript_82DD730:
	score +2

BattleAIScript_82DD732:
	if_random_less_than 128, BattleAIScript_82DD73A
	score -1

BattleAIScript_82DD73A:
	get_protect_count AI_USER
	if_equal 0, BattleAIScript_82DD75C
	score -1
	if_random_less_than 128, BattleAIScript_82DD75C
	score -1
	goto BattleAIScript_82DD75C

BattleAIScript_82DD751:
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_not_equal EFFECT_LOCK_ON, BattleAIScript_82DD75C

BattleAIScript_82DD75A:
	score -2

BattleAIScript_82DD75C:
	end

BattleAIScript_82DD75D:
	get_user_type1
	if_equal TYPE_GHOST, BattleAIScript_82DD77C
	get_user_type2
	if_equal TYPE_GHOST, BattleAIScript_82DD77C
	if_stat_level_more_than AI_USER, EVASION, 8, BattleAIScript_82DD782
	score -2
	goto BattleAIScript_82DD78A

BattleAIScript_82DD77C:
	if_random_less_than 80, BattleAIScript_82DD78A

BattleAIScript_82DD782:
	if_random_less_than 80, BattleAIScript_82DD78A
	score +2

BattleAIScript_82DD78A:
	end

BattleAIScript_82DD78B:
	if_hp_less_than AI_USER, 4, BattleAIScript_82DD799
	if_hp_less_than AI_USER, 35, BattleAIScript_82DD7A0

BattleAIScript_82DD799:
	score -1
	goto BattleAIScript_82DD7A8

BattleAIScript_82DD7A0:
	if_random_less_than 70, BattleAIScript_82DD7A8
	score +1

BattleAIScript_82DD7A8:
	end

BattleAIScript_82DD7A9:
	if_stat_level_more_than AI_USER, ATK, 8, BattleAIScript_82DD7D6
	if_stat_level_more_than AI_USER, DEF, 8, BattleAIScript_82DD7D6
	if_stat_level_more_than AI_USER, SPATK, 8, BattleAIScript_82DD7D6
	if_stat_level_more_than AI_USER, SPDEF, 8, BattleAIScript_82DD7D6
	if_stat_level_more_than AI_USER, EVASION, 8, BattleAIScript_82DD7D6
	goto BattleAIScript_82DD7FC

BattleAIScript_82DD7D6:
	if_target_faster BattleAIScript_82DD7E8
	if_hp_more_than AI_USER, 60, BattleAIScript_82DD844
	goto BattleAIScript_82DD7EF

BattleAIScript_82DD7E8:
	if_hp_more_than AI_USER, 70, BattleAIScript_82DD844

BattleAIScript_82DD7EF:
	if_random_less_than 80, BattleAIScript_82DD844
	score +2
	goto BattleAIScript_82DD844

BattleAIScript_82DD7FC:
	if_stat_level_more_than AI_USER, ATK, 7, BattleAIScript_82DD829
	if_stat_level_more_than AI_USER, DEF, 7, BattleAIScript_82DD829
	if_stat_level_more_than AI_USER, SPATK, 7, BattleAIScript_82DD829
	if_stat_level_more_than AI_USER, SPDEF, 7, BattleAIScript_82DD829
	if_stat_level_more_than AI_USER, EVASION, 7, BattleAIScript_82DD829
	goto BattleAIScript_82DD842

BattleAIScript_82DD829:
	if_target_faster BattleAIScript_82DD83B
	if_hp_more_than AI_USER, 60, BattleAIScript_82DD842
	goto BattleAIScript_82DD844

BattleAIScript_82DD83B:
	if_hp_less_than AI_USER, 70, BattleAIScript_82DD844

BattleAIScript_82DD842:
	score -2

BattleAIScript_82DD844:
	end

BattleAIScript_82DD845:
	is_first_turn_for AI_USER
	if_not_equal 0, BattleAIScript_82DD87A
	get_target_type1
	if_equal TYPE_GHOST, BattleAIScript_82DD872
	get_target_type1
	if_equal TYPE_PSYCHIC, BattleAIScript_82DD872
	get_target_type2
	if_equal TYPE_GHOST, BattleAIScript_82DD872
	get_target_type2
	if_equal TYPE_PSYCHIC, BattleAIScript_82DD872
	goto BattleAIScript_82DD87A

BattleAIScript_82DD872:
	if_random_less_than 128, BattleAIScript_82DD87A
	score +1

BattleAIScript_82DD87A:
	end

BattleAIScript_82DD87B:
	if_user_faster BattleAIScript_82DD889
	get_ability AI_USER
	if_equal ABILITY_SWIFT_SWIM, BattleAIScript_82DD8B0

BattleAIScript_82DD889:
	if_hp_less_than AI_USER, 40, BattleAIScript_82DD8B7
	get_weather
	if_equal AI_WEATHER_HAIL, BattleAIScript_82DD8B0
	if_equal AI_WEATHER_SUN, BattleAIScript_82DD8B0
	if_equal AI_WEATHER_SANDSTORM, BattleAIScript_82DD8B0
	get_ability AI_USER
	if_equal ABILITY_RAIN_DISH, BattleAIScript_82DD8B0
	goto BattleAIScript_82DD8B9

BattleAIScript_82DD8B0:
	score +1
	goto BattleAIScript_82DD8B9

BattleAIScript_82DD8B7:
	score -1

BattleAIScript_82DD8B9:
	end

BattleAIScript_82DD8BA:
	if_hp_less_than AI_USER, 40, BattleAIScript_82DD8E0
	get_weather
	if_equal AI_WEATHER_HAIL, BattleAIScript_82DD8D9
	if_equal AI_WEATHER_RAIN, BattleAIScript_82DD8D9
	if_equal AI_WEATHER_SANDSTORM, BattleAIScript_82DD8D9
	goto BattleAIScript_82DD8E2

BattleAIScript_82DD8D9:
	score +1
	goto BattleAIScript_82DD8E2

BattleAIScript_82DD8E0:
	score -1

BattleAIScript_82DD8E2:
	end

BattleAIScript_82DD8E3:
	if_hp_less_than AI_USER, 90, BattleAIScript_82DD8EF
	goto BattleAIScript_82DD8F1

BattleAIScript_82DD8EF:
	score -2

BattleAIScript_82DD8F1:
	end

BattleAIScript_82DD8F2:
	if_stat_level_more_than AI_TARGET, ATK, 8, BattleAIScript_82DD91F
	if_stat_level_more_than AI_TARGET, DEF, 8, BattleAIScript_82DD91F
	if_stat_level_more_than AI_TARGET, SPATK, 8, BattleAIScript_82DD91F
	if_stat_level_more_than AI_TARGET, SPDEF, 8, BattleAIScript_82DD91F
	if_stat_level_more_than AI_TARGET, EVASION, 8, BattleAIScript_82DD91F
	goto BattleAIScript_82DD957

BattleAIScript_82DD91F:
	if_stat_level_less_than AI_USER, ATK, 7, BattleAIScript_82DD954
	if_stat_level_less_than AI_USER, DEF, 7, BattleAIScript_82DD954
	if_stat_level_less_than AI_USER, SPATK, 7, BattleAIScript_82DD954
	if_stat_level_less_than AI_USER, SPDEF, 7, BattleAIScript_82DD954
	if_stat_level_less_than AI_USER, EVASION, 7, BattleAIScript_82DD952
	if_random_less_than 50, BattleAIScript_82DD959
	goto BattleAIScript_82DD957

BattleAIScript_82DD952:
	score +1

BattleAIScript_82DD954:
	score +1
	end

BattleAIScript_82DD957:
	score -2

BattleAIScript_82DD959:
	end

BattleAIScript_82DD95A:
	if_status AI_TARGET, STATUS_SLEEP, BattleAIScript_82DD9FF
	if_status2 AI_TARGET, STATUS2_INFATUATION, BattleAIScript_82DD9FF
	if_status2 AI_TARGET, STATUS2_CONFUSION, BattleAIScript_82DD9FF
	if_hp_more_than AI_USER, 30, BattleAIScript_82DD987
	if_random_less_than 10, BattleAIScript_82DD987
	score -1

BattleAIScript_82DD987:
	if_hp_more_than AI_USER, 50, BattleAIScript_82DD996
	if_random_less_than 100, BattleAIScript_82DD996
	score -1

BattleAIScript_82DD996:
	if_has_move AI_USER, MOVE_COUNTER, BattleAIScript_82DD9F6
	get_last_used_bank_move AI_TARGET
	get_move_power_from_result
	if_equal 0, BattleAIScript_82DD9CD
	if_target_not_taunted BattleAIScript_82DD9B4
	if_random_less_than 100, BattleAIScript_82DD9B4
	score +1

BattleAIScript_82DD9B4:
	get_last_used_bank_move AI_TARGET
	get_move_type_from_result
	if_not_in_bytes sTypesTable_82DDA02, BattleAIScript_82DD9FF
	if_random_less_than 100, BattleAIScript_82DDA01
	score +1
	goto BattleAIScript_82DDA01

BattleAIScript_82DD9CD:
	if_target_not_taunted BattleAIScript_82DD9DA
	if_random_less_than 100, BattleAIScript_82DD9DA
	score +1

BattleAIScript_82DD9DA:
	get_target_type1
	if_in_bytes sTypesTable_82DDA02, BattleAIScript_82DDA01
	get_target_type2
	if_in_bytes sTypesTable_82DDA02, BattleAIScript_82DDA01
	if_random_less_than 50, BattleAIScript_82DDA01

BattleAIScript_82DD9F6:
	if_random_less_than 100, BattleAIScript_82DD9FE
	score +4

BattleAIScript_82DD9FE:
	end

BattleAIScript_82DD9FF:
	score -1

BattleAIScript_82DDA01:
	end

sTypesTable_82DDA02:
    .byte TYPE_FIRE
    .byte TYPE_WATER
    .byte TYPE_GRASS
    .byte TYPE_ELECTRIC
    .byte TYPE_PSYCHIC
    .byte TYPE_ICE
    .byte TYPE_DRAGON
    .byte TYPE_DARK
    .byte -1

BattleAIScript_82DDA0B:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, BattleAIScript_82DDA2C
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, BattleAIScript_82DDA2C
	if_has_move_with_effect AI_TARGET, EFFECT_PROTECT, BattleAIScript_82DDA2C
	if_hp_more_than AI_USER, 38, BattleAIScript_82DDA2E
	score -1
	goto BattleAIScript_82DDA2E

BattleAIScript_82DDA2C:
	score -2

BattleAIScript_82DDA2E:
	end

BattleAIScript_82DDA2F:
	if_doesnt_have_move_with_effect AI_TARGET, EFFECT_PROTECT, BattleAIScript_82DDA3D
	score -1
	goto BattleAIScript_82DDAB4

BattleAIScript_82DDA3D:
	if_status AI_TARGET, STATUS_TOXIC_POISON, BattleAIScript_82DDAAC
	if_status2 AI_TARGET, STATUS2_CURSED, BattleAIScript_82DDAAC
	if_status3 AI_TARGET, STATUS3_LEECHSEED, BattleAIScript_82DDAAC
	get_weather
	if_equal AI_WEATHER_HAIL, BattleAIScript_82DDA6D
	if_equal AI_WEATHER_SANDSTORM, BattleAIScript_82DDA88
	goto BattleAIScript_82DDA98

BattleAIScript_82DDA6D:
	get_user_type1
	if_in_bytes sTypesTable_82DDAB5, BattleAIScript_82DDAAC
	get_user_type2
	if_in_bytes sTypesTable_82DDAB5, BattleAIScript_82DDAAC
	goto BattleAIScript_82DDA98

BattleAIScript_82DDA88:
	get_user_type1
	if_equal TYPE_ICE, BattleAIScript_82DDAAC
	get_user_type2
	if_equal TYPE_ICE, BattleAIScript_82DDAAC

BattleAIScript_82DDA98:
	if_target_faster BattleAIScript_82DDAB4
	get_last_used_bank_move AI_TARGET
	get_move_effect_from_result
	if_not_equal EFFECT_LOCK_ON, BattleAIScript_82DDAAC
	goto BattleAIScript_82DDAB4

BattleAIScript_82DDAAC:
	if_random_less_than 80, BattleAIScript_82DDAB4
	score +1

BattleAIScript_82DDAB4:
	end

sTypesTable_82DDAB5:
    .byte TYPE_GROUND
    .byte TYPE_ROCK
    .byte TYPE_STEEL
    .byte -1

BattleAIScript_82DDAB9:
	score +2
	end

BattleAIScript_82DDABC:
	get_stockpile_count AI_USER
	if_less_than 2, BattleAIScript_82DDACC
	if_random_less_than 80, BattleAIScript_82DDACC
	score +2

BattleAIScript_82DDACC:
	end

BattleAIScript_82DDACD:
	if_hp_less_than AI_USER, 40, BattleAIScript_82DDAF3
	get_weather
	if_equal AI_WEATHER_SUN, BattleAIScript_82DDAEC
	if_equal AI_WEATHER_RAIN, BattleAIScript_82DDAEC
	if_equal AI_WEATHER_SANDSTORM, BattleAIScript_82DDAEC
	goto BattleAIScript_82DDAF5

BattleAIScript_82DDAEC:
	score +1
	goto BattleAIScript_82DDAF5

BattleAIScript_82DDAF3:
	score -1

BattleAIScript_82DDAF5:
	end

BattleAIScript_82DDAF6:
	if_not_status AI_TARGET, STATUS_POISON | STATUS_BURN | STATUS_PARALYSIS | STATUS_TOXIC_POISON, BattleAIScript_82DDB02
	score +1

BattleAIScript_82DDB02:
	end

BattleAIScript_82DDB03:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, BattleAIScript_82DDB42
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, BattleAIScript_82DDB42
	if_status AI_TARGET, STATUS_SLEEP, BattleAIScript_82DDB59
	if_status2 AI_TARGET, STATUS2_INFATUATION, BattleAIScript_82DDB49
	if_status2 AI_TARGET, STATUS2_CONFUSION, BattleAIScript_82DDB49
	is_first_turn_for AI_USER
	if_not_equal 0, BattleAIScript_82DDB5B
	if_random_less_than 100, BattleAIScript_82DDB5B
	score +1
	goto BattleAIScript_82DDB5B

BattleAIScript_82DDB42:
	score -1
	goto BattleAIScript_82DDB5B

BattleAIScript_82DDB49:
	if_random_less_than 100, BattleAIScript_82DDB5B
	if_status2 AI_USER, STATUS2_SUBSTITUTE, Score_Plus5

BattleAIScript_82DDB59:
	score +1

BattleAIScript_82DDB5B:
	end

BattleAIScript_82DDB5C:
	if_status AI_TARGET, STATUS_PARALYSIS, BattleAIScript_82DDB6B
	goto BattleAIScript_82DDB6D

BattleAIScript_82DDB6B:
	score +1

BattleAIScript_82DDB6D:
	end

BattleAIScript_82DDB6E:
	get_hold_effect AI_USER
	if_in_bytes sHoldEffectsTable_82DDBB7, BattleAIScript_82DDB89
	if_in_bytes sHoldEffectsTable_82DDBAF, BattleAIScript_82DDB9B

BattleAIScript_82DDB82:
	score -3
	goto BattleAIScript_82DDBAE

BattleAIScript_82DDB89:
	get_hold_effect AI_TARGET
	if_in_bytes sHoldEffectsTable_82DDBB7, BattleAIScript_82DDB82
	score +5
	goto BattleAIScript_82DDBAE

BattleAIScript_82DDB9B:
	get_hold_effect AI_TARGET
	if_in_bytes sHoldEffectsTable_82DDBAF, BattleAIScript_82DDB82
	if_random_less_than 50, BattleAIScript_82DDBAE
	score +2

BattleAIScript_82DDBAE:
	end

sHoldEffectsTable_82DDBAF:
    .byte HOLD_EFFECT_CONFUSE_SPICY
    .byte HOLD_EFFECT_CONFUSE_DRY
    .byte HOLD_EFFECT_CONFUSE_SWEET
    .byte HOLD_EFFECT_CONFUSE_BITTER
    .byte HOLD_EFFECT_CONFUSE_SOUR
    .byte HOLD_EFFECT_MACHO_BRACE
    .byte HOLD_EFFECT_CHOICE_BAND
    .byte -1

sHoldEffectsTable_82DDBB7:
    .byte HOLD_EFFECT_CHOICE_BAND
    .byte -1

BattleAIScript_82DDBB9:
	get_ability AI_USER
	if_in_bytes sAbilitiesTable_82DDBDF, BattleAIScript_82DDBCF
	get_ability AI_TARGET
	if_in_bytes sAbilitiesTable_82DDBDF, BattleAIScript_82DDBD6

BattleAIScript_82DDBCF:
	score -1
	goto BattleAIScript_82DDBDE

BattleAIScript_82DDBD6:
	if_random_less_than 50, BattleAIScript_82DDBDE
	score +2

BattleAIScript_82DDBDE:
	end

sAbilitiesTable_82DDBDF:
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

BattleAIScript_82DDBF0:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, BattleAIScript_82DDC1D
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, BattleAIScript_82DDC1D
	if_stat_level_less_than AI_USER, ATK, 6, BattleAIScript_82DDC1D
	if_target_faster BattleAIScript_82DDC16
	if_hp_more_than AI_USER, 40, BattleAIScript_82DDC1D
	goto BattleAIScript_82DDC1F

BattleAIScript_82DDC16:
	if_hp_less_than AI_USER, 60, BattleAIScript_82DDC1F

BattleAIScript_82DDC1D:
	score -1

BattleAIScript_82DDC1F:
	end

BattleAIScript_82DDC20:
	if_hp_more_than AI_TARGET, 30, BattleAIScript_82DDC2F
	if_random_less_than 100, BattleAIScript_82DDC2F
	score -1

BattleAIScript_82DDC2F:
	is_first_turn_for AI_USER
	if_equal 0, BattleAIScript_82DDC4A
	if_random_less_than 150, BattleAIScript_82DDC52
	score +1
	goto BattleAIScript_82DDC52

AI_CV_MagicCoat3:
	if_random_less_than 50, BattleAIScript_82DDC52

BattleAIScript_82DDC4A:
	if_random_less_than 30, BattleAIScript_82DDC52
	score -1

BattleAIScript_82DDC52:
	end

BattleAIScript_82DDC53:
	get_used_held_item AI_USER
	if_not_in_bytes sItemsTable_82DDC6E, BattleAIScript_82DDC6B
	if_random_less_than 50, BattleAIScript_82DDC6D
	score +1
	goto BattleAIScript_82DDC6D

BattleAIScript_82DDC6B:
	score -2

BattleAIScript_82DDC6D:
	end

sItemsTable_82DDC6E:
    .byte ITEM_CHESTO_BERRY
    .byte ITEM_LUM_BERRY
    .byte ITEM_STARF_BERRY
    .byte -1

BattleAIScript_82DDC72:
	if_status AI_TARGET, STATUS_SLEEP, BattleAIScript_82DDC9D
	if_status2 AI_TARGET, STATUS2_INFATUATION, BattleAIScript_82DDC9D
	if_status2 AI_TARGET, STATUS2_CONFUSION, BattleAIScript_82DDC9D
	if_random_less_than 180, BattleAIScript_82DDC9D
	score +2
	goto BattleAIScript_82DDC9F

BattleAIScript_82DDC9D:
	score -2

BattleAIScript_82DDC9F:
	end

BattleAIScript_82DDCA0:
	if_side_affecting AI_TARGET, SIDE_STATUS_REFLECT, BattleAIScript_82DDCAF
	goto BattleAIScript_82DDCB1

BattleAIScript_82DDCAF:
	score +1

BattleAIScript_82DDCB1:
	end

BattleAIScript_82DDCB2:
	if_hp_less_than AI_TARGET, 30, BattleAIScript_82DDCC9
	is_first_turn_for AI_USER
	if_more_than 0, BattleAIScript_82DDCC9
	if_random_less_than 180, BattleAIScript_82DDCC9
	score +1

BattleAIScript_82DDCC9:
	end

BattleAIScript_82DDCCA:
	if_hp_less_than AI_TARGET, 70, BattleAIScript_82DDCF3
	if_target_faster BattleAIScript_82DDCE5
	if_hp_more_than AI_USER, 40, BattleAIScript_82DDCF3
	score +1
	goto BattleAIScript_82DDCF5

BattleAIScript_82DDCE5:
	if_hp_more_than AI_USER, 50, BattleAIScript_82DDCF3
	score +1
	goto BattleAIScript_82DDCF5

BattleAIScript_82DDCF3:
	score -1

BattleAIScript_82DDCF5:
	end

BattleAIScript_82DDCF6:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, BattleAIScript_82DDD1B
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, BattleAIScript_82DDD1B
	if_target_faster BattleAIScript_82DDD14
	if_hp_more_than AI_TARGET, 50, BattleAIScript_82DDD1D
	goto BattleAIScript_82DDD1B

BattleAIScript_82DDD14:
	if_hp_more_than AI_TARGET, 70, BattleAIScript_82DDD1D

BattleAIScript_82DDD1B:
	score -1

BattleAIScript_82DDD1D:
	end

BattleAIScript_82DDD1E:
	is_first_turn_for AI_USER
	if_more_than 0, BattleAIScript_82DDD2E
	if_random_less_than 100, BattleAIScript_82DDD2E
	score +2

BattleAIScript_82DDD2E:
	end

BattleAIScript_82DDD2F:
	if_hp_less_than AI_TARGET, 50, BattleAIScript_82DDD3B
	goto BattleAIScript_82DDD3D

BattleAIScript_82DDD3B:
	score -1

BattleAIScript_82DDD3D:
	end

BattleAIScript_82DDD3E:
	is_first_turn_for AI_USER
	if_equal 1, BattleAIScript_82DDD85
	if_random_less_than 30, BattleAIScript_82DDDA7
	if_target_faster BattleAIScript_82DDD6B
	if_hp_not_equal AI_USER, 100, BattleAIScript_82DDD9F
	if_hp_less_than AI_TARGET, 70, BattleAIScript_82DDD9F
	if_random_less_than 60, BattleAIScript_82DDDA7
	goto BattleAIScript_82DDD9F

BattleAIScript_82DDD6B:
	if_hp_more_than AI_TARGET, 25, BattleAIScript_82DDD9F
	if_has_move_with_effect AI_TARGET, EFFECT_RESTORE_HP, BattleAIScript_82DDD85
	if_has_move_with_effect AI_TARGET, EFFECT_DEFENSE_CURL, BattleAIScript_82DDD85
	goto BattleAIScript_82DDD92

BattleAIScript_82DDD85:
	if_random_less_than 150, BattleAIScript_82DDDA7
	score +2
	goto BattleAIScript_82DDDA7

BattleAIScript_82DDD92:
	if_random_less_than 230, BattleAIScript_82DDD9F
	score +1
	goto BattleAIScript_82DDDA7

BattleAIScript_82DDD9F:
	if_random_less_than 30, BattleAIScript_82DDDA7
	score -2

BattleAIScript_82DDDA7:
	end

BattleAIScript_82DDDA8:
	if_hp_less_than AI_USER, 50, BattleAIScript_82DDDCB
	get_target_type1
	if_equal TYPE_ELECTRIC, BattleAIScript_82DDDC4
	get_target_type2
	if_equal TYPE_ELECTRIC, BattleAIScript_82DDDC4
	goto BattleAIScript_82DDDCB

BattleAIScript_82DDDC4:
	score +1
	goto BattleAIScript_82DDDCD

BattleAIScript_82DDDCB:
	score -1

BattleAIScript_82DDDCD:
	end

BattleAIScript_82DDDCE:
	if_type_effectiveness AI_EFFECTIVENESS_x0_25, BattleAIScript_82DDDF3
	if_type_effectiveness AI_EFFECTIVENESS_x0_5, BattleAIScript_82DDDF3
	if_target_faster BattleAIScript_82DDDEC
	if_hp_more_than AI_USER, 60, BattleAIScript_82DDDF5
	goto BattleAIScript_82DDDF3

BattleAIScript_82DDDEC:
	if_hp_more_than AI_USER, 80, BattleAIScript_82DDDF5

BattleAIScript_82DDDF3:
	score -1

BattleAIScript_82DDDF5:
	end

BattleAIScript_82DDDF6:
	if_hp_less_than AI_USER, 50, BattleAIScript_82DDE19
	get_target_type1
	if_equal TYPE_FIRE, BattleAIScript_82DDE12
	get_target_type2
	if_equal TYPE_FIRE, BattleAIScript_82DDE12
	goto BattleAIScript_82DDE19

BattleAIScript_82DDE12:
	score +1
	goto BattleAIScript_82DDE1B

BattleAIScript_82DDE19:
	score -1

BattleAIScript_82DDE1B:
	end

BattleAIScript_82DDE1C:
	if_target_faster BattleAIScript_82DDE36
	if_hp_more_than AI_USER, 50, BattleAIScript_82DDE3E
	if_random_less_than 70, BattleAIScript_82DDE3E
	score -1
	goto BattleAIScript_82DDE3E

BattleAIScript_82DDE36:
	if_random_less_than 128, BattleAIScript_82DDE3E
	score +1

BattleAIScript_82DDE3E:
	end

AI_CheckViability:
	if_target_is_ally AI_Ret
	if_can_faint BattleAIScript_82DDE60
	get_how_powerful_move_is
	if_equal 1, Score_Minus1
	if_type_effectiveness AI_EFFECTIVENESS_x4, BattleAIScript_82DDE57
	end

BattleAIScript_82DDE57:
	if_random_less_than 80, BattleAIScript_82DDE70
	score +2
	end

BattleAIScript_82DDE60:
	if_effect EFFECT_EXPLOSION, BattleAIScript_82DDE70
	if_not_effect EFFECT_QUICK_ATTACK, BattleAIScript_82DDE6E
	score +2

BattleAIScript_82DDE6E:
	score +4

BattleAIScript_82DDE70:
	end

AI_SetupFirstTurn:
	if_target_is_ally AI_Ret
	get_turn_count
	if_not_equal 0, BattleAIScript_82DDE8F
	get_considered_move_effect
	if_not_in_bytes sMoveEffectsTable_82DDE90, BattleAIScript_82DDE8F
	if_random_less_than 80, BattleAIScript_82DDE8F
	score +2

BattleAIScript_82DDE8F:
	end

sMoveEffectsTable_82DDE90:
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

AI_PreferStrongestMove:
	if_target_is_ally AI_Ret
	get_how_powerful_move_is
	if_not_equal 0, BattleAIScript_82DDEDC
	if_random_less_than 100, BattleAIScript_82DDEDC
	score +2

BattleAIScript_82DDEDC:
	end

AI_Risky:
	if_target_is_ally AI_Ret
	get_considered_move_effect
	if_not_in_bytes sMoveEffectsTable_82DDEF5, BattleAIScript_82DDEF4
	if_random_less_than 128, BattleAIScript_82DDEF4
	score +2

BattleAIScript_82DDEF4:
	end

sMoveEffectsTable_82DDEF5:
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
	if_equal 0, BattleAIScript_82DDFB3
	get_how_powerful_move_is
	if_not_equal 0, BattleAIScript_82DDFB3
	if_has_move_with_effect AI_USER, EFFECT_BATON_PASS, BattleAIScript_82DDF2A
	if_random_less_than 80, BattleAIScript_82DDEF4

BattleAIScript_82DDF2A:
	if_move MOVE_SWORDS_DANCE, BattleAIScript_82DDF54
	if_move MOVE_DRAGON_DANCE, BattleAIScript_82DDF54
	if_move MOVE_CALM_MIND, BattleAIScript_82DDF54
	if_effect EFFECT_PROTECT, BattleAIScript_82DDF67
	if_move MOVE_BATON_PASS, BattleAIScript_82DDF7B
	if_random_less_than 20, BattleAIScript_82DDEF4
	score +3

BattleAIScript_82DDF54:
	get_turn_count
	if_equal 0, Score_Plus5
	if_hp_less_than AI_USER, 60, Score_Minus10
	goto Score_Plus1

BattleAIScript_82DDF67:
	get_last_used_bank_move AI_USER
	if_in_hwords sMovesTable_82DDF75, Score_Minus2
	score +2
	end

sMovesTable_82DDF75:
    .2byte MOVE_PROTECT
    .2byte MOVE_DETECT
    .2byte -1

BattleAIScript_82DDF7B:
	get_turn_count
	if_equal 0, Score_Minus2
	if_stat_level_more_than AI_USER, ATK, 8, Score_Plus3
	if_stat_level_more_than AI_USER, ATK, 7, Score_Plus2
	if_stat_level_more_than AI_USER, ATK, 6, Score_Plus1
	if_stat_level_more_than AI_USER, SPATK, 8, Score_Plus3
	if_stat_level_more_than AI_USER, SPATK, 7, Score_Plus2
	if_stat_level_more_than AI_USER, SPATK, 6, Score_Plus1
	end

BattleAIScript_82DDFB3:
	end

AI_DoubleBattle:
	if_target_is_ally AI_TryOnAlly
	if_move MOVE_SKILL_SWAP, BattleAIScript_82DE04B
	get_curr_move_type
	if_move MOVE_EARTHQUAKE, BattleAIScript_82DE010
	if_move MOVE_MAGNITUDE, BattleAIScript_82DE010
	if_equal 13, BattleAIScript_82DE062
	if_equal 10, BattleAIScript_82DE079
	get_ability AI_USER
	if_not_equal ABILITY_GUTS, BattleAIScript_82DDFF5
	if_has_move AI_USER_PARTNER, MOVE_HELPING_HAND, BattleAIScript_82DDFED
	end

BattleAIScript_82DDFED:
	get_how_powerful_move_is
	if_not_equal 0, Score_Plus1
	end

BattleAIScript_82DDFF5:
	if_status AI_USER, STATUS_ANY, BattleAIScript_82DE000
	end

BattleAIScript_82DE000:
	get_how_powerful_move_is
	if_equal 0, Score_Minus5
	score +1
	if_equal 2, Score_Plus2
	end

BattleAIScript_82DE010:
	if_ability AI_USER_PARTNER, ABILITY_LEVITATE, Score_Plus2
	if_type AI_USER_PARTNER, TYPE_FLYING, Score_Plus2
	if_type AI_USER_PARTNER, TYPE_FIRE, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_ELECTRIC, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_POISON, Score_Minus10
	if_type AI_USER_PARTNER, TYPE_ROCK, Score_Minus10
	goto Score_Minus3

BattleAIScript_82DE04B:
	get_ability AI_USER
	if_equal ABILITY_TRUANT, Score_Plus5
	get_ability AI_TARGET
	if_equal ABILITY_SHADOW_TAG, Score_Plus2
	if_equal ABILITY_PURE_POWER, Score_Plus2
	end

BattleAIScript_82DE062:
	if_no_ability AI_TARGET_PARTNER, ABILITY_LIGHTNING_ROD, BattleAIScript_82DE078
	score -2
	if_no_type AI_TARGET_PARTNER, TYPE_GROUND, BattleAIScript_82DE078
	score -8

BattleAIScript_82DE078:
	end

BattleAIScript_82DE079:
	if_flash_fired AI_USER, BattleAIScript_82DE080
	end

BattleAIScript_82DE080:
	goto Score_Plus1

AI_TryOnAlly:
	get_how_powerful_move_is
	if_equal 0, BattleAIScript_82DE0B2
	get_curr_move_type
	if_equal TYPE_FIRE, BattleAIScript_82DE099

AI_DiscourageOnAlly:
	goto Score_Minus30

BattleAIScript_82DE099:
	if_ability AI_USER_PARTNER, ABILITY_FLASH_FIRE, BattleAIScript_82DE0A7
	goto AI_DiscourageOnAlly

BattleAIScript_82DE0A7:
	if_flash_fired AI_USER_PARTNER, AI_DiscourageOnAlly
	goto Score_Plus3

BattleAIScript_82DE0B2:
	if_move MOVE_SKILL_SWAP, BattleAIScript_82DE0DA
	if_move MOVE_WILL_O_WISP, BattleAIScript_82DE14F
	if_move MOVE_TOXIC, BattleAIScript_82DE14F
	if_move MOVE_HELPING_HAND, BattleAIScript_82DE16D
	if_move MOVE_SWAGGER, BattleAIScript_82DE178
	goto Score_Minus30_

BattleAIScript_82DE0DA:
	get_ability AI_TARGET
	if_equal ABILITY_TRUANT, Score_Plus10
	get_ability AI_USER
	if_not_equal ABILITY_LEVITATE, BattleAIScript_82DE107
	get_ability AI_TARGET
	if_equal ABILITY_LEVITATE, Score_Minus30_
	get_target_type1
	if_not_equal TYPE_ELECTRIC, BattleAIScript_82DE107
	score +1
	get_target_type2
	if_not_equal TYPE_ELECTRIC, BattleAIScript_82DE107
	score +1
	end

BattleAIScript_82DE107:
	if_not_equal 14, Score_Minus30_
	if_has_move AI_USER_PARTNER, MOVE_FIRE_BLAST, BattleAIScript_82DE14A
	if_has_move AI_USER_PARTNER, MOVE_THUNDER, BattleAIScript_82DE14A
	if_has_move AI_USER_PARTNER, MOVE_CROSS_CHOP, BattleAIScript_82DE14A
	if_has_move AI_USER_PARTNER, MOVE_HYDRO_PUMP, BattleAIScript_82DE14A
	if_has_move AI_USER_PARTNER, MOVE_DYNAMIC_PUNCH, BattleAIScript_82DE14A
	if_has_move AI_USER_PARTNER, MOVE_BLIZZARD, BattleAIScript_82DE14A
	if_has_move AI_USER_PARTNER, MOVE_MEGAHORN, BattleAIScript_82DE14A
	goto Score_Minus30_

BattleAIScript_82DE14A:
	goto Score_Plus3

BattleAIScript_82DE14F:
	get_ability AI_TARGET
	if_not_equal ABILITY_GUTS, Score_Minus30_
	if_status AI_TARGET, STATUS_ANY, Score_Minus30_
	if_hp_less_than AI_USER, 91, Score_Minus30_
	goto Score_Plus5

BattleAIScript_82DE16D:
	if_random_less_than 64, Score_Minus1
	goto Score_Plus2

BattleAIScript_82DE178:
	if_holds_item AI_TARGET, ITEM_PERSIM_BERRY, BattleAIScript_82DE185
	goto Score_Minus30_

BattleAIScript_82DE185:
	if_stat_level_more_than AI_TARGET, ATK, 7, BattleAIScript_82DE18F
	score +3

BattleAIScript_82DE18F:
	end

Score_Minus30_:
	score -30
	end

AI_HPAware:
	if_target_is_ally AI_TryOnAlly
	if_hp_more_than AI_USER, 70, BattleAIScript_82DE1B5
	if_hp_more_than AI_USER, 30, BattleAIScript_82DE1C4
	get_considered_move_effect
	if_in_bytes sMoveEffectsTable_82DE258, BattleAIScript_82DE1D3
	goto BattleAIScript_82DE1DB

BattleAIScript_82DE1B5:
	get_considered_move_effect
	if_in_bytes sMoveEffectsTable_82DE21F, BattleAIScript_82DE1D3
	goto BattleAIScript_82DE1DB

BattleAIScript_82DE1C4:
	get_considered_move_effect
	if_in_bytes sMoveEffectsTable_82DE22D, BattleAIScript_82DE1D3
	goto BattleAIScript_82DE1DB

BattleAIScript_82DE1D3:
	if_random_less_than 50, BattleAIScript_82DE1DB
	score -2

BattleAIScript_82DE1DB:
	if_hp_more_than AI_TARGET, 70, BattleAIScript_82DE1F8
	if_hp_more_than AI_TARGET, 30, BattleAIScript_82DE207
	get_considered_move_effect
	if_in_bytes sMoveEffectsTable_82DE2B1, BattleAIScript_82DE216
	goto BattleAIScript_82DE21E

BattleAIScript_82DE1F8:
	get_considered_move_effect
	if_in_bytes sMoveEffectsTable_82DE288, BattleAIScript_82DE216
	goto BattleAIScript_82DE21E

BattleAIScript_82DE207:
	get_considered_move_effect
	if_in_bytes sMoveEffectsTable_82DE289, BattleAIScript_82DE216
	goto BattleAIScript_82DE21E

BattleAIScript_82DE216:
	if_random_less_than 50, BattleAIScript_82DE21E
	score -2

BattleAIScript_82DE21E:
	end

sMoveEffectsTable_82DE21F:
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

sMoveEffectsTable_82DE22D:
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

sMoveEffectsTable_82DE258:
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
    .byte EFFECT_SOLARBEAM
    .byte EFFECT_ERUPTION
    .byte EFFECT_TICKLE
    .byte EFFECT_COSMIC_POWER
    .byte EFFECT_BULK_UP
    .byte EFFECT_CALM_MIND
    .byte EFFECT_DRAGON_DANCE
    .byte -1

sMoveEffectsTable_82DE288:
    .byte -1

sMoveEffectsTable_82DE289:
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

sMoveEffectsTable_82DE2B1:
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
    .byte EFFECT_SUPER_FANG
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

AI_Unknown:
	if_target_is_ally AI_TryOnAlly
	if_not_effect EFFECT_SUNNY_DAY, BattleAIScript_82DE308
	if_equal 0, BattleAIScript_82DE308
	is_first_turn_for AI_USER
	if_equal 0, BattleAIScript_82DE308
	score +5

BattleAIScript_82DE308:
	end

AI_Roaming:
	if_status2 AI_USER, STATUS2_WRAPPED, BattleAIScript_82DE336
	if_status2 AI_USER, STATUS2_ESCAPE_PREVENTION, BattleAIScript_82DE336
	get_ability AI_TARGET
	if_equal ABILITY_SHADOW_TAG, BattleAIScript_82DE336
	get_ability AI_USER
	if_equal ABILITY_LEVITATE, BattleAIScript_82DE335
	get_ability AI_TARGET
	if_equal ABILITY_ARENA_TRAP, BattleAIScript_82DE336

BattleAIScript_82DE335:
	flee

BattleAIScript_82DE336:
	end

AI_Safari:
	if_random_safari_flee BattleAIScript_82DE33D
	watch

BattleAIScript_82DE33D:
	flee

AI_FirstBattle:
	if_hp_equal AI_TARGET, 20, BattleAIScript_82DE34D
	if_hp_less_than AI_TARGET, 20, BattleAIScript_82DE34D
	end

BattleAIScript_82DE34D:
	flee

AI_Ret:
	end
