#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveIsAffectedBySheerForce(MOVE_ELECTRO_SHOT) == TRUE);
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Magnitude", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MAGNITUDE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Eruption", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ERUPTION); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Water Spout", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_WATER_SPOUT); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Present", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        //Test will fail if present heals because the hp change would be 0
        //so we want a damaging version of present
        TURN { MOVE(player, MOVE_PRESENT, WITH_RNG(RNG_PRESENT, 1)); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Psywave", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PSYWAVE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Round", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Gyro Ball", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GYRO_BALL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Electro Ball", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRO_BALL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Dragon Energy", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DRAGON_ENERGY); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Belch", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); HP(1); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BELCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Shell Trap", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SHELL_TRAP); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Burn Up", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ZEN_MODE; }
    GIVEN {
        PLAYER(SPECIES_DARMANITAN) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BURN_UP); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Double Shock", s16 damage)
{
    enum Move move = MOVE_NONE;
    PARAMETRIZE { move = MOVE_SKILL_SWAP; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_PIKACHU);
        OPPONENT(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_DOUBLE_SHOCK); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Steel Roller", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRASSY_TERRAIN); MOVE(player, MOVE_STEEL_ROLLER); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Synchronoise", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); HP(1); Item(ITEM_SITRUS_BERRY); }
        OPPONENT(SPECIES_CHANSEY);
    } WHEN {
        TURN { MOVE(player, MOVE_SYNCHRONOISE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Aura Wheel", s16 damage)
{
    enum Move move = MOVE_NONE;
    PARAMETRIZE { move = MOVE_SKILL_SWAP; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_MORPEKO);
        OPPONENT(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_AURA_WHEEL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Hyperspace Fury", s16 damage)
{
    enum Move move = MOVE_NONE;
    PARAMETRIZE { move = MOVE_SKILL_SWAP; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_HOOPA_UNBOUND);
        OPPONENT(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_HYPERSPACE_FURY); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Bolt Beak", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_BOLT_BEAK); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Fishious Rend", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_FISHIOUS_REND); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Comeuppance", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); MOVE(player, MOVE_COMEUPPANCE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't boost Payback", s16 damage)
{
    enum Ability ability = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; }
    PARAMETRIZE { ability = ABILITY_ANGER_POINT; }
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_PAYBACK); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_NE(results[0].damage, 0);
    }
}

static inline bool32 IgnoreMoveForSheerForceBoost(enum Move move)
{
    switch (move) {
        case MOVE_PSYWAVE:       //  Just skip Psywave
        case MOVE_PRESENT:       //  And Present...
        case MOVE_MAGNITUDE:     //  And Magnitude...
        case MOVE_ERUPTION:      //  And Eruption...
        case MOVE_WATER_SPOUT:
        case MOVE_GYRO_BALL:
        case MOVE_SYNCHRONOISE:
        case MOVE_ELECTRO_BALL:
        case MOVE_ROUND:
        case MOVE_BELCH:
        case MOVE_HYPERSPACE_FURY:
        case MOVE_BURN_UP:
        case MOVE_SHELL_TRAP:
        case MOVE_BOLT_BEAK:
        case MOVE_FISHIOUS_REND:
        case MOVE_AURA_WHEEL:
        case MOVE_STEEL_ROLLER:
        case MOVE_DRAGON_ENERGY:
        case MOVE_DOUBLE_SHOCK:
        case MOVE_COMEUPPANCE:
        case MOVE_UPPER_HAND:    //  Bugged?
        case MOVE_GLITZY_GLOW:   //  Light Screen Move Effect seems to be bugged
        case MOVE_PAYBACK:
            return TRUE;
        default:
            return FALSE;
    }
}

static inline bool32 IsMoveSheerForceBoosted(enum Move move)
{
    switch (move) {
        case MOVE_AIR_SLASH:
        case MOVE_ANCIENT_POWER:
        case MOVE_ASTONISH:
        case MOVE_BITE:
        case MOVE_BLIZZARD:
        case MOVE_BODY_SLAM:
        case MOVE_BOUNCE:
        case MOVE_BREAKING_SWIPE:
        case MOVE_BUBBLE:
        case MOVE_BUBBLE_BEAM:
        case MOVE_BUG_BUZZ:
        case MOVE_BULLDOZE:
        case MOVE_BURNING_JEALOUSY:
        case MOVE_CHARGE_BEAM:
        case MOVE_CHILLING_WATER:
        case MOVE_CONFUSION:
        case MOVE_CRUNCH:
        case MOVE_CRUSH_CLAW:
        case MOVE_DARK_PULSE:
        case MOVE_DRAGON_RUSH:
        case MOVE_DRAGON_BREATH:
        case MOVE_DYNAMIC_PUNCH:
        case MOVE_EARTH_POWER:
        case MOVE_EMBER:
        case MOVE_ESPER_WING:
        case MOVE_EXTRASENSORY:
        case MOVE_FAKE_OUT:
        case MOVE_FIRE_BLAST:
        case MOVE_FIRE_FANG:
        case MOVE_FIRE_PUNCH:
        case MOVE_FLAME_CHARGE:
        case MOVE_FLAME_WHEEL:
        case MOVE_FLAMETHROWER:
        case MOVE_FLARE_BLITZ:
        case MOVE_FLASH_CANNON:
        case MOVE_FOCUS_BLAST:
        case MOVE_FORCE_PALM:
        case MOVE_GUNK_SHOT:
        case MOVE_HEADBUTT:
        case MOVE_HEAT_WAVE:
        case MOVE_HURRICANE:
        case MOVE_ICE_BEAM:
        case MOVE_ICE_FANG:
        case MOVE_ICE_PUNCH:
        case MOVE_ICICLE_CRASH:
        case MOVE_ICY_WIND:
        case MOVE_IRON_HEAD:
        case MOVE_IRON_TAIL:
        case MOVE_LAVA_PLUME:
        case MOVE_LIQUIDATION:
        case MOVE_LOW_SWEEP:
        case MOVE_METAL_CLAW:
        case MOVE_MUD_BOMB:
        case MOVE_MUDDY_WATER:
        case MOVE_MUD_SHOT:
        case MOVE_MUD_SLAP:
        case MOVE_MYSTICAL_FIRE:
        case MOVE_PLAY_ROUGH:
        case MOVE_POISON_FANG:
        case MOVE_POISON_JAB:
        case MOVE_POISON_STING:
        case MOVE_POISON_TAIL:
        case MOVE_POUNCE:
        case MOVE_POWER_UP_PUNCH:
        case MOVE_PSYBEAM:
        case MOVE_PSYCHIC:
        case MOVE_RAZOR_SHELL:
        case MOVE_ROCK_CLIMB:
        case MOVE_ROCK_SLIDE:
        case MOVE_ROCK_SMASH:
        case MOVE_ROCK_TOMB:
        case MOVE_SANDSEAR_STORM:
        case MOVE_SCALD:
        case MOVE_SCORCHING_SANDS:
        case MOVE_SECRET_POWER:
        case MOVE_SHADOW_BALL:
        case MOVE_SIGNAL_BEAM:
        case MOVE_SKY_ATTACK:
        case MOVE_SLUDGE_BOMB:
        case MOVE_SLUDGE_WAVE:
        case MOVE_SNARL:
        case MOVE_SNORE:
        case MOVE_STEEL_WING:
        case MOVE_STOMP:
        case MOVE_STONE_AXE:
        case MOVE_STRUGGLE_BUG:
        case MOVE_THROAT_CHOP:
        case MOVE_THUNDER:
        case MOVE_THUNDER_FANG:
        case MOVE_THUNDERBOLT:
        case MOVE_THUNDER_PUNCH:
        case MOVE_TRAILBLAZE:
        case MOVE_TWISTER:
        case MOVE_UPPER_HAND:
        case MOVE_WATER_PULSE:
        case MOVE_WATERFALL:
        case MOVE_ZAP_CANNON:
        case MOVE_ZEN_HEADBUTT:
        case MOVE_ACID:
        case MOVE_ACID_SPRAY:
        case MOVE_ALLURING_VOICE:
        case MOVE_ANCHOR_SHOT:
        case MOVE_APPLE_ACID:
        case MOVE_AQUA_STEP:
        case MOVE_AURA_WHEEL:
        case MOVE_AURORA_BEAM:
        case MOVE_AXE_KICK:
        case MOVE_BARB_BARRAGE:
        case MOVE_BITTER_MALICE:
        case MOVE_BLAZE_KICK:
        case MOVE_BLAZING_TORQUE:
        case MOVE_BLEAKWIND_STORM:
        case MOVE_BLUE_FLARE:
        case MOVE_BOLT_STRIKE:
        case MOVE_BONE_CLUB:
        case MOVE_CEASELESS_EDGE:
        case MOVE_CHATTER:
        case MOVE_CLANGOROUS_SOULBLAZE:
        case MOVE_COMBAT_TORQUE:
        case MOVE_CONSTRICT:
        case MOVE_CROSS_POISON:
        case MOVE_DIAMOND_STORM:
        case MOVE_DIRE_CLAW:
        case MOVE_DISCHARGE:
        case MOVE_DIZZY_PUNCH:
        case MOVE_DOUBLE_IRON_BASH:
        case MOVE_DRUM_BEATING:
        case MOVE_EERIE_SPELL:
        case MOVE_ELECTROWEB:
        case MOVE_ENERGY_BALL:
        case MOVE_FIERY_DANCE:
        case MOVE_FIERY_WRATH:
        case MOVE_FREEZING_GLARE:
        case MOVE_FIRE_LASH:
        #if B_UPDATED_MOVE_DATA < GEN_CHAMPIONS
        case MOVE_FREEZE_DRY:
        #endif
        case MOVE_FREEZE_SHOCK:
        case MOVE_GENESIS_SUPERNOVA:
        case MOVE_GLACIATE:
        case MOVE_GRAV_APPLE:
        case MOVE_HEART_STAMP:
        case MOVE_HYPER_FANG:
        case MOVE_ICE_BURN:
        case MOVE_INFERNAL_PARADE:
        case MOVE_INFERNO:
        case MOVE_LEAF_TORNADO:
        case MOVE_LICK:
        case MOVE_LUMINA_CRASH:
        case MOVE_LUNGE:
        case MOVE_LUSTER_PURGE:
        case MOVE_MAGICAL_TORQUE:
        case MOVE_MALIGNANT_CHAIN:
        case MOVE_MATCHA_GOTCHA:
        case MOVE_METEOR_MASH:
        case MOVE_MIRROR_SHOT:
        case MOVE_MIST_BALL:
        case MOVE_MOONBLAST:
        case MOVE_MORTAL_SPIN:
        case MOVE_MOUNTAIN_GALE:
        case MOVE_MYSTICAL_POWER:
        case MOVE_NEEDLE_ARM:
        case MOVE_NIGHT_DAZE:
        case MOVE_NOXIOUS_TORQUE:
        case MOVE_NUZZLE:
        case MOVE_OCTAZOOKA:
        case MOVE_OMINOUS_WIND:
        case MOVE_ORDER_UP:
        case MOVE_POWDER_SNOW:
        case MOVE_PSYSHIELD_BASH:
        case MOVE_PYRO_BALL:
        case MOVE_RELIC_SONG:
        case MOVE_ROLLING_KICK:
        case MOVE_SACRED_FIRE:
        case MOVE_SALT_CURE:
        case MOVE_SEARING_SHOT:
        case MOVE_SEED_FLARE:
        case MOVE_SHADOW_BONE:
        case MOVE_SHELL_SIDE_ARM:
        case MOVE_SILVER_WIND:
        case MOVE_SKITTER_SMACK:
        case MOVE_SLUDGE:
        case MOVE_SMOG:
        case MOVE_SPARK:
        case MOVE_SPARKLING_ARIA:
        case MOVE_SPIRIT_BREAK:
        case MOVE_SPIRIT_SHACKLE:
        case MOVE_SPLISHY_SPLASH:
        case MOVE_SPRINGTIDE_STORM:
        case MOVE_STEAM_ERUPTION:
        case MOVE_STEAMROLLER:
        case MOVE_STOKED_SPARKSURFER:
        case MOVE_STRANGE_STEAM:
        case MOVE_SYRUP_BOMB:
        case MOVE_THUNDER_SHOCK:
        case MOVE_THUNDEROUS_KICK:
        case MOVE_TORCH_SONG:
        case MOVE_TRI_ATTACK:
        case MOVE_TRIPLE_ARROWS:
        case MOVE_TROP_KICK:
        case MOVE_TWINEEDLE:
        case MOVE_VOLT_TACKLE:
        case MOVE_WICKED_TORQUE:
        case MOVE_WILDBOLT_STORM:
        case MOVE_ZING_ZAP:
        case MOVE_ELECTRO_SHOT:
        case MOVE_PSYCHIC_NOISE:
            return TRUE;
        case MOVE_RAPID_SPIN:
            return B_SPEED_BUFFING_RAPID_SPIN >= GEN_8;
        default:
            return FALSE;
    }
}

// Tests split by generation
DOUBLE_BATTLE_TEST("Sheer Force only boosts the damage of moves it's supposed to boost (Gen1)")
{
    s16 damage1, damage2;
    enum Move move = MOVE_NONE;
    for (enum Move j = MOVE_POUND; j < MOVES_COUNT_GEN1; j++)
    {
        if (GetMoveCategory(j) != DAMAGE_CATEGORY_STATUS && !IgnoreMoveForSheerForceBoost(j))
            PARAMETRIZE { move = j; }
    }
    GIVEN {
        PLAYER(SPECIES_STEELIX) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_BLUK_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_STEELIX) { Ability(ABILITY_STURDY); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
    } WHEN {
        if (move == MOVE_ALLURING_VOICE || move == MOVE_BURNING_JEALOUSY) // Alluring Voice requires the target to boost stats to have an effect
            TURN { MOVE(opponentRight, MOVE_AGILITY); MOVE(playerRight, MOVE_AGILITY); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_UPPER_HAND) // Upper Hand requires the target to be using a damaging priority move
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft); MOVE(playerRight, move, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_COUNTER || move == MOVE_UPPER_HAND)
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft);
                   MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft);
                   MOVE(playerLeft, move, target: opponentRight);
                   MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_MIRROR_COAT || move == MOVE_METAL_BURST)
            TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_SUCKER_PUNCH || move == MOVE_THUNDERCLAP)
            TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_DREAM_EATER)
        {
            TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentRight); MOVE(opponentLeft, MOVE_HYPNOSIS, target: playerRight); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SNORE)
        {
            TURN { MOVE(opponentRight, MOVE_HYPNOSIS, target: playerLeft); MOVE(playerRight, MOVE_HYPNOSIS, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SPIT_UP || move == MOVE_LAST_RESORT)
        {
            TURN { MOVE(playerLeft, MOVE_STOCKPILE); MOVE(opponentLeft, MOVE_STOCKPILE); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        switch (GetMoveEffect(move))
        {
            case EFFECT_TWO_TURNS_ATTACK:
            case EFFECT_SEMI_INVULNERABLE:
            case EFFECT_SOLAR_BEAM:
            case EFFECT_SKY_DROP:
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN {}
                break;
            case EFFECT_FUTURE_SIGHT:
                TURN {}
                TURN {}
                break;
            case EFFECT_BIDE:
                TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                break;
            default:
                break;
        }
    } SCENE {
        if (GetMoveEffect(move) != EFFECT_FUTURE_SIGHT)
        {
            HP_BAR(opponentRight, captureDamage: &damage1);
            HP_BAR(playerRight, captureDamage: &damage2);
        }
        else
        {
            HP_BAR(playerRight, captureDamage: &damage2);
            HP_BAR(opponentRight, captureDamage: &damage1);
        }
    } THEN {
        if (IsMoveSheerForceBoosted(move)) {
            if (!(damage1 > damage2))
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_GT(damage1, damage2);
        } else {
            if (damage1 != damage2)
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_EQ(damage2, damage1);
        }
    }
}

DOUBLE_BATTLE_TEST("Sheer Force only boosts the damage of moves it's supposed to boost (Gen2)")
{
    s16 damage1, damage2;
    enum Move move = MOVE_NONE;
    for (enum Move j = MOVE_SKETCH; j < MOVES_COUNT_GEN2; j++)
    {
        if (GetMoveCategory(j) != DAMAGE_CATEGORY_STATUS && !IgnoreMoveForSheerForceBoost(j))
            PARAMETRIZE { move = j; }
    }
    GIVEN {
        PLAYER(SPECIES_STEELIX) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_BLUK_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_STEELIX) { Ability(ABILITY_STURDY); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
    } WHEN {
        if (move == MOVE_ALLURING_VOICE || move == MOVE_BURNING_JEALOUSY) // Alluring Voice requires the target to boost stats to have an effect
            TURN { MOVE(opponentRight, MOVE_AGILITY); MOVE(playerRight, MOVE_AGILITY); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_UPPER_HAND) // Upper Hand requires the target to be using a damaging priority move
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft); MOVE(playerRight, move, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_COUNTER || move == MOVE_UPPER_HAND)
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft);
                   MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft);
                   MOVE(playerLeft, move, target: opponentRight);
                   MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_MIRROR_COAT || move == MOVE_METAL_BURST)
            TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_SUCKER_PUNCH || move == MOVE_THUNDERCLAP)
            TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_DREAM_EATER)
        {
            TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentRight); MOVE(opponentLeft, MOVE_HYPNOSIS, target: playerRight); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SNORE)
        {
            TURN { MOVE(opponentRight, MOVE_HYPNOSIS, target: playerLeft); MOVE(playerRight, MOVE_HYPNOSIS, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SPIT_UP || move == MOVE_LAST_RESORT)
        {
            TURN { MOVE(playerLeft, MOVE_STOCKPILE); MOVE(opponentLeft, MOVE_STOCKPILE); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        switch (GetMoveEffect(move))
        {
            case EFFECT_TWO_TURNS_ATTACK:
            case EFFECT_SEMI_INVULNERABLE:
            case EFFECT_SOLAR_BEAM:
            case EFFECT_SKY_DROP:
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN {}
                break;
            case EFFECT_FUTURE_SIGHT:
                TURN {}
                TURN {}
                break;
            case EFFECT_BIDE:
                TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                break;
            default:
                break;
        }
    } SCENE {
        if (GetMoveEffect(move) != EFFECT_FUTURE_SIGHT)
        {
            HP_BAR(opponentRight, captureDamage: &damage1);
            HP_BAR(playerRight, captureDamage: &damage2);
        }
        else
        {
            HP_BAR(playerRight, captureDamage: &damage2);
            HP_BAR(opponentRight, captureDamage: &damage1);
        }
    } THEN {
        if (IsMoveSheerForceBoosted(move)) {
            if (!(damage1 > damage2))
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_GT(damage1, damage2);
        } else {
            if (damage1 != damage2)
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_EQ(damage2, damage1);
        }
    }
}

DOUBLE_BATTLE_TEST("Sheer Force only boosts the damage of moves it's supposed to boost (Gen3)")
{
    s16 damage1, damage2;
    enum Move move = MOVE_NONE;
    for (enum Move j = MOVE_FAKE_OUT; j < MOVES_COUNT_GEN3; j++)
    {
        if (GetMoveCategory(j) != DAMAGE_CATEGORY_STATUS && !IgnoreMoveForSheerForceBoost(j))
            PARAMETRIZE { move = j; }
    }
    GIVEN {
        PLAYER(SPECIES_STEELIX) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_BLUK_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_STEELIX) { Ability(ABILITY_STURDY); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
    } WHEN {
        if (move == MOVE_ALLURING_VOICE || move == MOVE_BURNING_JEALOUSY) // Alluring Voice requires the target to boost stats to have an effect
            TURN { MOVE(opponentRight, MOVE_AGILITY); MOVE(playerRight, MOVE_AGILITY); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_UPPER_HAND) // Upper Hand requires the target to be using a damaging priority move
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft); MOVE(playerRight, move, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_COUNTER || move == MOVE_UPPER_HAND)
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft);
                   MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft);
                   MOVE(playerLeft, move, target: opponentRight);
                   MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_MIRROR_COAT || move == MOVE_METAL_BURST)
            TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_SUCKER_PUNCH || move == MOVE_THUNDERCLAP)
            TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_DREAM_EATER)
        {
            TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentRight); MOVE(opponentLeft, MOVE_HYPNOSIS, target: playerRight); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SNORE)
        {
            TURN { MOVE(opponentRight, MOVE_HYPNOSIS, target: playerLeft); MOVE(playerRight, MOVE_HYPNOSIS, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SPIT_UP || move == MOVE_LAST_RESORT)
        {
            TURN { MOVE(playerLeft, MOVE_STOCKPILE); MOVE(opponentLeft, MOVE_STOCKPILE); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        switch (GetMoveEffect(move))
        {
            case EFFECT_TWO_TURNS_ATTACK:
            case EFFECT_SEMI_INVULNERABLE:
            case EFFECT_SOLAR_BEAM:
            case EFFECT_SKY_DROP:
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN {}
                break;
            case EFFECT_FUTURE_SIGHT:
                TURN {}
                TURN {}
                break;
            case EFFECT_BIDE:
                TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                break;
            default:
                break;
        }
    } SCENE {
        if (GetMoveEffect(move) != EFFECT_FUTURE_SIGHT)
        {
            HP_BAR(opponentRight, captureDamage: &damage1);
            HP_BAR(playerRight, captureDamage: &damage2);
        }
        else
        {
            HP_BAR(playerRight, captureDamage: &damage2);
            HP_BAR(opponentRight, captureDamage: &damage1);
        }
    } THEN {
        if (IsMoveSheerForceBoosted(move)) {
            if (!(damage1 > damage2))
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_GT(damage1, damage2);
        } else {
            if (damage1 != damage2)
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_EQ(damage2, damage1);
        }
    }
}

DOUBLE_BATTLE_TEST("Sheer Force only boosts the damage of moves it's supposed to boost (Gen4)")
{
    s16 damage1, damage2;
    enum Move move = MOVE_NONE;
    for (enum Move j = MOVE_ROOST; j < MOVES_COUNT_GEN4; j++)
    {
        if (GetMoveCategory(j) != DAMAGE_CATEGORY_STATUS && !IgnoreMoveForSheerForceBoost(j))
            PARAMETRIZE { move = j; }
    }
    GIVEN {
        PLAYER(SPECIES_STEELIX) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_BLUK_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_STEELIX) { Ability(ABILITY_STURDY); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
    } WHEN {
        if (move == MOVE_ALLURING_VOICE || move == MOVE_BURNING_JEALOUSY) // Alluring Voice requires the target to boost stats to have an effect
            TURN { MOVE(opponentRight, MOVE_AGILITY); MOVE(playerRight, MOVE_AGILITY); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_UPPER_HAND) // Upper Hand requires the target to be using a damaging priority move
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft); MOVE(playerRight, move, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_COUNTER || move == MOVE_UPPER_HAND)
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft);
                   MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft);
                   MOVE(playerLeft, move, target: opponentRight);
                   MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_MIRROR_COAT || move == MOVE_METAL_BURST)
            TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_SUCKER_PUNCH || move == MOVE_THUNDERCLAP)
            TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_DREAM_EATER)
        {
            TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentRight); MOVE(opponentLeft, MOVE_HYPNOSIS, target: playerRight); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SNORE)
        {
            TURN { MOVE(opponentRight, MOVE_HYPNOSIS, target: playerLeft); MOVE(playerRight, MOVE_HYPNOSIS, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SPIT_UP || move == MOVE_LAST_RESORT)
        {
            TURN { MOVE(playerLeft, MOVE_STOCKPILE); MOVE(opponentLeft, MOVE_STOCKPILE); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        switch (GetMoveEffect(move))
        {
            case EFFECT_TWO_TURNS_ATTACK:
            case EFFECT_SEMI_INVULNERABLE:
            case EFFECT_SOLAR_BEAM:
            case EFFECT_SKY_DROP:
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN {}
                break;
            case EFFECT_FUTURE_SIGHT:
                TURN {}
                TURN {}
                break;
            case EFFECT_BIDE:
                TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                break;
            default:
                break;
        }
    } SCENE {
        if (GetMoveEffect(move) != EFFECT_FUTURE_SIGHT)
        {
            HP_BAR(opponentRight, captureDamage: &damage1);
            HP_BAR(playerRight, captureDamage: &damage2);
        }
        else
        {
            HP_BAR(playerRight, captureDamage: &damage2);
            HP_BAR(opponentRight, captureDamage: &damage1);
        }
    } THEN {
        if (IsMoveSheerForceBoosted(move)) {
            if (!(damage1 > damage2))
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_GT(damage1, damage2);
        } else {
            if (damage1 != damage2)
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_EQ(damage2, damage1);
        }
    }
}

DOUBLE_BATTLE_TEST("Sheer Force only boosts the damage of moves it's supposed to boost (Gen5)")
{
    s16 damage1, damage2;
    enum Move move = MOVE_NONE;
    for (enum Move j = MOVE_HONE_CLAWS + 12; j < MOVES_COUNT_GEN5; j++)
    {
        if (GetMoveCategory(j) != DAMAGE_CATEGORY_STATUS && !IgnoreMoveForSheerForceBoost(j))
            PARAMETRIZE { move = j; }
    }
    GIVEN {
        PLAYER(SPECIES_STEELIX) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_BLUK_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_STEELIX) { Ability(ABILITY_STURDY); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
    } WHEN {
        if (move == MOVE_ALLURING_VOICE || move == MOVE_BURNING_JEALOUSY) // Alluring Voice requires the target to boost stats to have an effect
            TURN { MOVE(opponentRight, MOVE_AGILITY); MOVE(playerRight, MOVE_AGILITY); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_UPPER_HAND) // Upper Hand requires the target to be using a damaging priority move
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft); MOVE(playerRight, move, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_COUNTER || move == MOVE_UPPER_HAND)
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft);
                   MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft);
                   MOVE(playerLeft, move, target: opponentRight);
                   MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_MIRROR_COAT || move == MOVE_METAL_BURST)
            TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_SUCKER_PUNCH || move == MOVE_THUNDERCLAP)
            TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_DREAM_EATER)
        {
            TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentRight); MOVE(opponentLeft, MOVE_HYPNOSIS, target: playerRight); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SNORE)
        {
            TURN { MOVE(opponentRight, MOVE_HYPNOSIS, target: playerLeft); MOVE(playerRight, MOVE_HYPNOSIS, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SPIT_UP || move == MOVE_LAST_RESORT)
        {
            TURN { MOVE(playerLeft, MOVE_STOCKPILE); MOVE(opponentLeft, MOVE_STOCKPILE); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        switch (GetMoveEffect(move))
        {
            case EFFECT_TWO_TURNS_ATTACK:
            case EFFECT_SEMI_INVULNERABLE:
            case EFFECT_SOLAR_BEAM:
            case EFFECT_SKY_DROP:
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN {}
                break;
            case EFFECT_FUTURE_SIGHT:
                TURN {}
                TURN {}
                break;
            case EFFECT_BIDE:
                TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                break;
            default:
                break;
        }
    } SCENE {
        if (GetMoveEffect(move) != EFFECT_FUTURE_SIGHT)
        {
            HP_BAR(opponentRight, captureDamage: &damage1);
            HP_BAR(playerRight, captureDamage: &damage2);
        }
        else
        {
            HP_BAR(playerRight, captureDamage: &damage2);
            HP_BAR(opponentRight, captureDamage: &damage1);
        }
    } THEN {
        if (IsMoveSheerForceBoosted(move)) {
            if (!(damage1 > damage2))
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_GT(damage1, damage2);
        } else {
            if (damage1 != damage2)
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_EQ(damage2, damage1);
        }
    }
}

DOUBLE_BATTLE_TEST("Sheer Force only boosts the damage of moves it's supposed to boost (Gen6)")
{
    s16 damage1, damage2;
    enum Move move = MOVE_NONE;
    for (enum Move j = MOVE_FLYING_PRESS; j < MOVES_COUNT_GEN6; j++)
    {
        if (GetMoveCategory(j) != DAMAGE_CATEGORY_STATUS && !IgnoreMoveForSheerForceBoost(j))
            PARAMETRIZE { move = j; }
    }
    GIVEN {
        PLAYER(SPECIES_STEELIX) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_BLUK_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_STEELIX) { Ability(ABILITY_STURDY); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
    } WHEN {
        if (move == MOVE_ALLURING_VOICE || move == MOVE_BURNING_JEALOUSY) // Alluring Voice requires the target to boost stats to have an effect
            TURN { MOVE(opponentRight, MOVE_AGILITY); MOVE(playerRight, MOVE_AGILITY); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_UPPER_HAND) // Upper Hand requires the target to be using a damaging priority move
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft); MOVE(playerRight, move, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_COUNTER || move == MOVE_UPPER_HAND)
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft);
                   MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft);
                   MOVE(playerLeft, move, target: opponentRight);
                   MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_MIRROR_COAT || move == MOVE_METAL_BURST)
            TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_SUCKER_PUNCH || move == MOVE_THUNDERCLAP)
            TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_DREAM_EATER)
        {
            TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentRight); MOVE(opponentLeft, MOVE_HYPNOSIS, target: playerRight); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SNORE)
        {
            TURN { MOVE(opponentRight, MOVE_HYPNOSIS, target: playerLeft); MOVE(playerRight, MOVE_HYPNOSIS, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SPIT_UP || move == MOVE_LAST_RESORT)
        {
            TURN { MOVE(playerLeft, MOVE_STOCKPILE); MOVE(opponentLeft, MOVE_STOCKPILE); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        switch (GetMoveEffect(move))
        {
            case EFFECT_TWO_TURNS_ATTACK:
            case EFFECT_SEMI_INVULNERABLE:
            case EFFECT_SOLAR_BEAM:
            case EFFECT_SKY_DROP:
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN {}
                break;
            case EFFECT_FUTURE_SIGHT:
                TURN {}
                TURN {}
                break;
            case EFFECT_BIDE:
                TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                break;
            default:
                break;
        }
    } SCENE {
        if (GetMoveEffect(move) != EFFECT_FUTURE_SIGHT)
        {
            HP_BAR(opponentRight, captureDamage: &damage1);
            HP_BAR(playerRight, captureDamage: &damage2);
        }
        else
        {
            HP_BAR(playerRight, captureDamage: &damage2);
            HP_BAR(opponentRight, captureDamage: &damage1);
        }
    } THEN {
        if (IsMoveSheerForceBoosted(move)) {
            if (!(damage1 > damage2))
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_GT(damage1, damage2);
        } else {
            if (damage1 != damage2)
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_EQ(damage2, damage1);
        }
    }
}

DOUBLE_BATTLE_TEST("Sheer Force only boosts the damage of moves it's supposed to boost (Gen7)")
{
    s16 damage1, damage2;
    enum Move move = MOVE_NONE;
    for (enum Move j = MOVE_SHORE_UP; j < MOVES_COUNT_GEN7; j++)
    {
        if (GetMoveCategory(j) != DAMAGE_CATEGORY_STATUS && !IgnoreMoveForSheerForceBoost(j))
            PARAMETRIZE { move = j; }
    }
    GIVEN {
        PLAYER(SPECIES_STEELIX) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_BLUK_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_STEELIX) { Ability(ABILITY_STURDY); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
    } WHEN {
        if (move == MOVE_ALLURING_VOICE || move == MOVE_BURNING_JEALOUSY) // Alluring Voice requires the target to boost stats to have an effect
            TURN { MOVE(opponentRight, MOVE_AGILITY); MOVE(playerRight, MOVE_AGILITY); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_UPPER_HAND) // Upper Hand requires the target to be using a damaging priority move
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft); MOVE(playerRight, move, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_COUNTER || move == MOVE_UPPER_HAND)
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft);
                   MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft);
                   MOVE(playerLeft, move, target: opponentRight);
                   MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_MIRROR_COAT || move == MOVE_METAL_BURST)
            TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_SUCKER_PUNCH || move == MOVE_THUNDERCLAP)
            TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_DREAM_EATER)
        {
            TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentRight); MOVE(opponentLeft, MOVE_HYPNOSIS, target: playerRight); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SNORE)
        {
            TURN { MOVE(opponentRight, MOVE_HYPNOSIS, target: playerLeft); MOVE(playerRight, MOVE_HYPNOSIS, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SPIT_UP || move == MOVE_LAST_RESORT)
        {
            TURN { MOVE(playerLeft, MOVE_STOCKPILE); MOVE(opponentLeft, MOVE_STOCKPILE); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        switch (GetMoveEffect(move))
        {
            case EFFECT_TWO_TURNS_ATTACK:
            case EFFECT_SEMI_INVULNERABLE:
            case EFFECT_SOLAR_BEAM:
            case EFFECT_SKY_DROP:
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN {}
                break;
            case EFFECT_FUTURE_SIGHT:
                TURN {}
                TURN {}
                break;
            case EFFECT_BIDE:
                TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                break;
            default:
                break;
        }
    } SCENE {
        if (GetMoveEffect(move) != EFFECT_FUTURE_SIGHT)
        {
            HP_BAR(opponentRight, captureDamage: &damage1);
            HP_BAR(playerRight, captureDamage: &damage2);
        }
        else
        {
            HP_BAR(playerRight, captureDamage: &damage2);
            HP_BAR(opponentRight, captureDamage: &damage1);
        }
    } THEN {
        if (IsMoveSheerForceBoosted(move)) {
            if (!(damage1 > damage2))
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_GT(damage1, damage2);
        } else {
            if (damage1 != damage2)
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_EQ(damage2, damage1);
        }
    }
}

DOUBLE_BATTLE_TEST("Sheer Force only boosts the damage of moves it's supposed to boost (Gen8)")
{
    s16 damage1, damage2;
    enum Move move = MOVE_NONE;
    for (enum Move j = MOVE_DYNAMAX_CANNON; j < MOVES_COUNT_GEN8; j++)
    {
        if (GetMoveCategory(j) != DAMAGE_CATEGORY_STATUS && !IgnoreMoveForSheerForceBoost(j))
            PARAMETRIZE { move = j; }
    }
    GIVEN {
        PLAYER(SPECIES_STEELIX) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_BLUK_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_STEELIX) { Ability(ABILITY_STURDY); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
    } WHEN {
        if (move == MOVE_ALLURING_VOICE || move == MOVE_BURNING_JEALOUSY) // Alluring Voice requires the target to boost stats to have an effect
            TURN { MOVE(opponentRight, MOVE_AGILITY); MOVE(playerRight, MOVE_AGILITY); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_UPPER_HAND) // Upper Hand requires the target to be using a damaging priority move
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft); MOVE(playerRight, move, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_COUNTER || move == MOVE_UPPER_HAND)
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft);
                   MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft);
                   MOVE(playerLeft, move, target: opponentRight);
                   MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_MIRROR_COAT || move == MOVE_METAL_BURST)
            TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_SUCKER_PUNCH || move == MOVE_THUNDERCLAP)
            TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_DREAM_EATER)
        {
            TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentRight); MOVE(opponentLeft, MOVE_HYPNOSIS, target: playerRight); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SNORE)
        {
            TURN { MOVE(opponentRight, MOVE_HYPNOSIS, target: playerLeft); MOVE(playerRight, MOVE_HYPNOSIS, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SPIT_UP || move == MOVE_LAST_RESORT)
        {
            TURN { MOVE(playerLeft, MOVE_STOCKPILE); MOVE(opponentLeft, MOVE_STOCKPILE); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        switch (GetMoveEffect(move))
        {
            case EFFECT_TWO_TURNS_ATTACK:
            case EFFECT_SEMI_INVULNERABLE:
            case EFFECT_SOLAR_BEAM:
            case EFFECT_SKY_DROP:
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN {}
                break;
            case EFFECT_FUTURE_SIGHT:
                TURN {}
                TURN {}
                break;
            case EFFECT_BIDE:
                TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                break;
            default:
                break;
        }
    } SCENE {
        if (GetMoveEffect(move) != EFFECT_FUTURE_SIGHT)
        {
            HP_BAR(opponentRight, captureDamage: &damage1);
            HP_BAR(playerRight, captureDamage: &damage2);
        }
        else
        {
            HP_BAR(playerRight, captureDamage: &damage2);
            HP_BAR(opponentRight, captureDamage: &damage1);
        }
    } THEN {
        if (IsMoveSheerForceBoosted(move)) {
            if (!(damage1 > damage2))
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_GT(damage1, damage2);
        } else {
            if (damage1 != damage2)
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_EQ(damage2, damage1);
        }
    }
}

// Last test should always go up to MOVES_COUNT to catch users moves
DOUBLE_BATTLE_TEST("Sheer Force only boosts the damage of moves it's supposed to boost (Gen9)")
{
    s16 damage1, damage2;
    enum Move move = MOVE_NONE;
    for (enum Move j = MOVE_TERA_BLAST; j < MOVES_COUNT; j++)
    {
        if (GetMoveCategory(j) != DAMAGE_CATEGORY_STATUS && !IgnoreMoveForSheerForceBoost(j))
            PARAMETRIZE { move = j; }
    }
    GIVEN {
        PLAYER(SPECIES_STEELIX) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_BLUK_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_STEELIX) { Ability(ABILITY_STURDY); Item(ITEM_BLUK_BERRY); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Level(100); Item(ITEM_BLUK_BERRY); }
    } WHEN {
        if (move == MOVE_ALLURING_VOICE || move == MOVE_BURNING_JEALOUSY) // Alluring Voice requires the target to boost stats to have an effect
            TURN { MOVE(opponentRight, MOVE_AGILITY); MOVE(playerRight, MOVE_AGILITY); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_UPPER_HAND) // Upper Hand requires the target to be using a damaging priority move
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft); MOVE(playerRight, move, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_COUNTER || move == MOVE_UPPER_HAND)
            TURN { MOVE(opponentRight, MOVE_QUICK_ATTACK, target: playerLeft);
                   MOVE(playerRight, MOVE_QUICK_ATTACK, target: opponentLeft);
                   MOVE(playerLeft, move, target: opponentRight);
                   MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_MIRROR_COAT || move == MOVE_METAL_BURST)
            TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_SUCKER_PUNCH || move == MOVE_THUNDERCLAP)
            TURN { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        else if (move == MOVE_DREAM_EATER)
        {
            TURN { MOVE(playerLeft, MOVE_HYPNOSIS, target: opponentRight); MOVE(opponentLeft, MOVE_HYPNOSIS, target: playerRight); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SNORE)
        {
            TURN { MOVE(opponentRight, MOVE_HYPNOSIS, target: playerLeft); MOVE(playerRight, MOVE_HYPNOSIS, target: opponentLeft); MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else if (move == MOVE_SPIT_UP || move == MOVE_LAST_RESORT)
        {
            TURN { MOVE(playerLeft, MOVE_STOCKPILE); MOVE(opponentLeft, MOVE_STOCKPILE); }
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        }
        else
            TURN { MOVE(playerLeft, move, target: opponentRight); MOVE(opponentLeft, move, target: playerRight); }
        switch (GetMoveEffect(move))
        {
            case EFFECT_TWO_TURNS_ATTACK:
            case EFFECT_SEMI_INVULNERABLE:
            case EFFECT_SOLAR_BEAM:
            case EFFECT_SKY_DROP:
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN {}
                break;
            case EFFECT_FUTURE_SIGHT:
                TURN {}
                TURN {}
                break;
            case EFFECT_BIDE:
                TURN { MOVE(opponentRight, MOVE_WATER_GUN, target: playerLeft); MOVE(playerRight, MOVE_WATER_GUN, target: opponentLeft); SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                TURN { SKIP_TURN(playerLeft); SKIP_TURN(opponentLeft); }
                break;
            default:
                break;
        }
    } SCENE {
        if (GetMoveEffect(move) != EFFECT_FUTURE_SIGHT)
        {
            HP_BAR(opponentRight, captureDamage: &damage1);
            HP_BAR(playerRight, captureDamage: &damage2);
        }
        else
        {
            HP_BAR(playerRight, captureDamage: &damage2);
            HP_BAR(opponentRight, captureDamage: &damage1);
        }
    } THEN {
        if (IsMoveSheerForceBoosted(move)) {
            if (!(damage1 > damage2))
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_GT(damage1, damage2);
        } else {
            if (damage1 != damage2)
                DebugPrintf("Move that failed: %S", gMovesInfo[move].name);
            EXPECT_EQ(damage2, damage1);
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI sees Sheer Force skips additional effects")
{
    enum Ability ability;
    enum Move expectedMove, move;

    PARAMETRIZE { ability = ABILITY_ROUGH_SKIN;  move = MOVE_KARATE_CHOP; expectedMove = MOVE_POWER_UP_PUNCH; }
    PARAMETRIZE { ability = ABILITY_ROUGH_SKIN;  move = MOVE_BRICK_BREAK; expectedMove = MOVE_POWER_UP_PUNCH; }
    PARAMETRIZE { ability = ABILITY_SHEER_FORCE; move = MOVE_BRICK_BREAK; expectedMove = MOVE_BRICK_BREAK;    }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_DRUDDIGON) { Ability(ability); Moves(MOVE_POWER_UP_PUNCH, move); }
    } WHEN {
        TURN { EXPECT_MOVE(opponent, expectedMove); }
    }
}

SINGLE_BATTLE_TEST("Sheer Force doesn't activate Shell Bell")
{
    GIVEN {
        PLAYER(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); Item(ITEM_SHELL_BELL); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EARTH_POWER); }
    } SCENE {
        NONE_OF {
            HP_BAR(player);
        }
    }
}
