#include "global.h"
#include "test/battle.h"

// From https://bulbapedia.bulbagarden.net/wiki/Damage#Example

SINGLE_BATTLE_TEST("Damage calculation matches Gen5+")
{
    s16 dmg;
    s16 expectedDamage;
    PARAMETRIZE { expectedDamage = 196; }
    PARAMETRIZE { expectedDamage = 192; }
    PARAMETRIZE { expectedDamage = 192; }
    PARAMETRIZE { expectedDamage = 192; }
    PARAMETRIZE { expectedDamage = 184; }
    PARAMETRIZE { expectedDamage = 184; }
    PARAMETRIZE { expectedDamage = 184; }
    PARAMETRIZE { expectedDamage = 180; }
    PARAMETRIZE { expectedDamage = 180; }
    PARAMETRIZE { expectedDamage = 180; }
    PARAMETRIZE { expectedDamage = 172; }
    PARAMETRIZE { expectedDamage = 172; }
    PARAMETRIZE { expectedDamage = 172; }
    PARAMETRIZE { expectedDamage = 168; }
    PARAMETRIZE { expectedDamage = 168; }
    PARAMETRIZE { expectedDamage = 168; }
    GIVEN {
        PLAYER(SPECIES_GLACEON) { Level(75); Attack(123); }
        OPPONENT(SPECIES_GARCHOMP) { Defense(163); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_ICE_FANG, WITH_RNG(RNG_DAMAGE_MODIFIER, i));
        }
    }
    SCENE{
        MESSAGE("Glaceon used Ice Fang!");
        HP_BAR(opponent, captureDamage: &dmg);
    }
    THEN{
        EXPECT_EQ(expectedDamage, dmg);
    }
}

SINGLE_BATTLE_TEST("Damage calculation matches Gen5+ (Muscle Band, crit)")
{
    s16 dmg;
    s16 expectedDamage;
    PARAMETRIZE { expectedDamage = 324; }
    PARAMETRIZE { expectedDamage = 316; }
    PARAMETRIZE { expectedDamage = 312; }
    PARAMETRIZE { expectedDamage = 312; }
    PARAMETRIZE { expectedDamage = 304; }
    PARAMETRIZE { expectedDamage = 304; }
    PARAMETRIZE { expectedDamage = 300; }
    PARAMETRIZE { expectedDamage = 300; }
    PARAMETRIZE { expectedDamage = 292; }
    PARAMETRIZE { expectedDamage = 292; }
    PARAMETRIZE { expectedDamage = 288; }
    PARAMETRIZE { expectedDamage = 288; }
    PARAMETRIZE { expectedDamage = 280; }
    PARAMETRIZE { expectedDamage = 276; }
    PARAMETRIZE { expectedDamage = 276; }
    PARAMETRIZE { expectedDamage = 268; }
    GIVEN {
        PLAYER(SPECIES_GLACEON) { Level(75); Attack(123); Item(ITEM_MUSCLE_BAND); }
        OPPONENT(SPECIES_GARCHOMP) { Defense(163); }
    } WHEN {
        TURN {
            MOVE(player, MOVE_ICE_FANG, WITH_RNG(RNG_DAMAGE_MODIFIER, i), criticalHit: TRUE);
        }
    }
    SCENE{
        MESSAGE("Glaceon used Ice Fang!");
        HP_BAR(opponent, captureDamage: &dmg);
    }
    THEN{
        EXPECT_EQ(expectedDamage, dmg);
    }
}
