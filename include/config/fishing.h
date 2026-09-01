#ifndef GUARD_CONFIG_FISHING_H
#define GUARD_CONFIG_FISHING_H

#define I_FISHING_BITE_ODDS         GEN_LATEST // In Gen 1 and Gen 2, the Old Rod has a 100% chance for a bite, Good Rod has a 66% chance for a bite, and Super Rod has a 50% chance for a bite. In Gen 3, all rods have a base 50% chance for a bite. In Gen 4 onwards, the Old Rod has a base 25% chance for a bite, Good Rod has a 50% chance for a bite, and Super Rod has a 75% chance for a bite.
#define I_FISHING_MINIGAME          GEN_3      // Each generation uses a variation of reeling in Pokémon once they have been hooked. NOTE: Only the Gen 1/2 and Gen 3 minigames are implemented right now!
#define I_FISHING_ENVIRONMENT       GEN_LATEST // In Gen 3, the battle environment when fighting a hooked Pokémon is based on the tile the player is standing on. In Gen 4 onwards, the environment is based on tile that is being fished in, resulting in it usually being a water environment.
#define I_FISHING_STICKY_BOOST      GEN_LATEST // In Gen 3, a Pokemon with Suction Cups or Sticky Hold in the first slot of the party causes the chance for a bite to increase by about 35%. In Gen 4 onwards, it doubles the base bite chance.
#define I_FISHING_FOLLOWER_BOOST    FALSE      // In HGSS, fishing bite odds are increased depending on the friendship of the current following Pokémon.
#define I_FISHING_CHAIN             FALSE      // Introduced in XY, hooking the same Pokémon repeatedly will increase the odds of that mon being shiny. NOTE: This implementation is an approximation of the actual feature, as XY have not been throughoutly documented or datamined.
#define I_FISHING_PROXIMITY         FALSE      // In XY, bite chance is boosted by the number of adjacent non-surfable tiles next to your fishing line
#define I_FISHING_TIME_OF_DAY_BOOST FALSE      // In XY, bite chance is boosted during morning and evening

#endif // GUARD_CONFIG_FISHING_H
