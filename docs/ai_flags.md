# What are AI Flags?
AI flags alter the behavior of AI controlled trainers.  These flags affect what moves the AI chooses to use, what Pokémon the AI sends out and when they decide to switch, overarching strategic choices the AI prefers to make, and more.

The AI flags can be found in [`include/constants/battle_ai.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/battle_ai.h). Some flags have their own dedicated functions that affect how the AI scores its options when choosing what to do in battle, and those functions can be found in [`src/battle_ai_main.c`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/battle_ai_main.c). Other flags are used in conditional checks to gate certain behaviour behind certain flags, which you can typically find by searching the codebase for the flag name and browsing from there.

# What flags should you use?
When adding new AI flags it is recommended to use `AI_FLAG_CHECK_BAD_MOVE`, `AI_FLAG_CHECK_VIABILITY`, `AI_FLAG_TRY_TO_FAINT` to make sure the AI makes good decisions. It is especially important to use `AI_FLAG_CHECK_BAD_MOVE` in combination with any added flags otherwise the AI will use moves that can fail.

Other flags should be used with consideration to the circumstances.

# How do you use them?
Adding an AI flag to a trainer is straightforward, but the process is different depending on how trainers are being defined.

## `COMPETITIVE_PARTY_SYNTAX == TRUE`
If you are using competitive syntax parties, navigate to the trainer data in [`src/data/trainers.party`](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/trainers.party), find the trainer you’d like to change, and add flags like so:
AI: Check Bad Move / Try to Faint / Check Viability. The name of each flag is just the constant, but without AI_FLAG at the beginning. For example, to add `AI_FLAG_SEQUENCE_SWITCHING`, any of the following will work:
* AI_FLAG_SEQUENCE_SWITCHING
* SEQUENCE_SWITCHING
* SEQUENCE SWITCHING
* Sequence_Switching
* Sequence Switching

## `COMPETITIVE_PARTY_SYNTAX != TRUE` / Not Found
If you are not using competitive syntax parties, instead access the trainer data directly in [`src/data/trainers.h`](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/trainers.h), and add flags like so, typed exactly the same as the flag names themselves: 
`.aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY`

# What AI Flags does pokeemerald-expansion have?
This section lists all of expansion’s AI Flags and briefly describes the effect they have on the AI’s behaviour. In all cases, please check the corresponding function or surrounding code around their implementation for more details. Some of these functions are vanilla, some share a name with vanilla but have been modified to varying degrees, and some are completely new.

## `AI_FLAG_CHECK_BAD_MOVE`
The AI will avoid using moves that are likely to fail in the current situation. This flag helps prevent the AI from making ineffective choices, such as using moves into immunities, into invulnerable states, or when the moves are otherwise hindered by abilities, terrain, or status conditions. 

## `AI_FLAG_TRY_TO_FAINT`
AI will prioritize KOing the player if able rather than using status moves. Will prioritize using a move that can OHKO the player. If the player can KO the AI’s mon and the AI’s mon is slower, prioritize priority moves (this does not prevent the AI from switching out instead).

This flag handles scoring for OHKOs but does not handle 2HKOs at all, `AI_FLAG_STRONGEST_MOVE` should be used for 2HKO scoring.

## `AI_FLAG_CHECK_VIABILITY`
This flag is divided into two components to calculate the best available move for the current context:
- **`AI_CompareDamagingMoves`**: This function compares damaging moves against each other and picks the best one.
- **`AI_CalcMoveEffectScore`**: This function checks every move effect (status or damaging move effect) and increases the score accordingly.

This is different to `AI_FLAG_CHECK_BAD_MOVE` as it calculates how poor a move is and not whether it will fail or not.

## `AI_FLAG_SETUP_FIRST_TURN`
AI will prioritize using setup moves on the first turn. These include stat buffs, field effects, status moves, etc.

This is just a flat increase without any consideration of whether it makes sense to use the move or not. For better move choice quality for those moves, `AI_FLAG_CHECK_VIABILITY` should be used.

## `AI_FLAG_RISKY`
AI will generally behave more recklessly. This AI enables the following behaviour:
* Always assume the highest damage roll when scoring moves
* Blindly Mirror Coat / Counter based on the player mon’s species higher attacking stat
* Moves with Recoil if they miss are not treated differently even if accuracy is lowered
* Prioritize maximizing damage from moves at the cost of accuracy
* Prioritize moves with low change strong effects (Ancient Power etc., check `AI_Risky` function for full list)
* Switch offensively mid battle rather than defensively (if using `AI_FLAG_SMART_MON_CHOICES`)
* Prioritize Explosion moves

## `AI_FLAG_PREFER_STRONGEST_MOVE`
Adds score bonus to any move the AI has that either OHKOs or 2HKOs the player. 

Keep in mind that this is a weaker form of `AI_FLAG_TRY_TO_FAINT` at scoring OHKOs as it does not take into account who is attacking first, it does however handle 2HKOs.

## `AI_FLAG_PREFER_BATON_PASS`
AI prefers raising its own stats if it has >= 60% HP, as well as Ingrain, Aqua Ring, and Protect. Prioritizes Baton Bass if the mon is rooted (Ingrain) or has the Aqua Ring effect, and doesn’t if it has been Leech Seeded. 

## `AI_FLAG_DOUBLE_BATTLE`
This flag is automatically set in double battles, and controls much of the doubles-specific scoring. I’ll summarize some of its scoring as follows:
* Don’t use Helping Hand if partner is, don’t Perish Trap your partner, don’t change the weather if they are, don’t buff stats if partner will trigger Anger Point for us
* Collaborate with partner to Perish Trap opponent, Magnet Rise to protect partner, Dragon Cheer partner if applicable
* Prioritize using weather move if it benefits partner
* Prioritize triggering partner’s good abilities if possible (Motor Drive, Storm Drain, Beat Up -> Justified, etc.)
* Handle Skill Swap smartly, both with the partner and against the player

## `AI_FLAG_HP_AWARE`
Lets the AI make decisions based on how much remaining HP its mon(s) and the player’s mon(s) have.

With respect to the AI’s mons, in doubles:
* Allows the AI to attack its partner with a move it can absorb if its low on HP (ie. Electric move on partner with Volt Absorb)
* Prioritizes healing its partner if its HP is <= 50% if able

In both singles and doubles:
* Prioritizes not using moves that require the user fainting (Destiny Bond, Explosion etc.) and healing moves while on >= 70% HP.
* Prioritize not using moves that require the user fainting or losing significant HP (Belly Drum etc) while between 30% and 70% HP
* Prioritize not using setup moves (Light Screen etc.) and Bide while on <= 30% HP 

With respect to the player’s mons:
* Prioritize not using many status moves (stat buffs, Poison, Pain Split) if the player has between 30% and 70% HP
* Prioritize not using any status moves if the player is has <= 30% HP

## `AI_FLAG_POWERFUL_STATUS`
AI prioritizes setting up field effects (Trick Room, Rain Dance, etc.) and side statuses (Tailwind, Spikes, etc.), even if it could faint the target.

## `AI_FLAG_NEGATE_UNAWARE`
AI does not understand ability suppression (Mold Breaker etc., weather suppression (Air Lock etc.), redirection abilities (Lightningrod etc.) being temporarily removed due to move effects (Sky Drop etc.), or item suppression (Magic Room etc.) and will ignore them. This is a handicap flag.

## `AI_FLAG_WILL_SUICIDE`
AI prioritizes self destruction moves (Explosion, Memento). 

## `AI_FLAG_PREFER_STATUS_MOVES`
AI gets a score bonus for status moves. This should be combined with `AI_FLAG_CHECK_BAD_MOVE` to prevent using only status moves.

## `AI_FLAG_STALL`
AI prefers simple classically "stalling" behaviour. It will prioritize:
* Mean Look, Fairy Lock, and Wrap for trapping
* Increasing its defense and special defense
* Moves that inflict Poison if it also has a Protect move
* Copying defense and special defense buffs

## `AI_FLAG_SMART_SWITCHING`
Affects when the AI chooses to switch. AI will make smarter decisions about when to switch out mid-battle. Automatically enables `AI_FLAG_SMART_MON_CHOICES`, which is required as the vanilla mon selection AI is not smart enough to handle several switch-triggering situations appropriately, leading to bizarre behaviour. Many of these checks have intentional failure rates, so the AI won’t switch out 100% of the time in these cases to keep the player from being able to predict perfectly. Some of these also only apply to singles, and many of them are being simplified for the sake of brevity. This flag lets the AI trigger switches when:
* It can’t hit Wonder Guard and has another mon in the party that can (switch that mon in)
* It’s going to die to Perish Song, can’t KO the player and is affected by Yawn, is being severely affected by a status condition that switching helps (Curse, Toxic, Leech Seed)
* It has a mon that can trap the player’s mon and win the 1v1 (switch that mon in)
* It has a mon in the party that can absorb the player’s next expected attack (switch that mon in)
* It will not switch if the current mon will die to hazards on re-entry and it has no means of clearing them in its party
* All its moves are bad
* It can take advantage of Natural Cure or Regenerator
* Its Encore’d into something bad
* Its primary attacking stats are sufficiently lowered
* Its "odds are bad", which is a generic "try to make smart, player-like decisions generally speaking" check. Switches can be triggered if the player has a good switchin candidate (`AI_FLAG_SMART_MON_CHOICES`), and:
* The current mon has a bad type matchup and doesn’t have a super effective move and has at least ½ HP, or ¼ HP and Regenerator, or
* The current mon loses the 1v1 quickly and has at least ½ HP, or ¼ and Regenerator

## `AI_FLAG_ACE_POKEMON`
Marks the last Pokemon in the party as the Ace Pokemon. It will not be used unless it is the last one remaining, or is forced to be switched in (Roar, U-Turn with 1 mon remaining, etc.)

## `AI_FLAG_OMNISCIENT`
AI has full knowledge of player moves, abilities, and hold items, and can use this knowledge when making decisions. 

## `AI_FLAG_SMART_MON_CHOICES`
Affects what the AI chooses to send out after a switch. AI will make smarter decisions when choosing which mon to send out mid-battle and after a KO, which are handled separately. Automatically included when `AI_FLAG_SMART_SWITCHING` is enabled.

With this flag enabled, the AI will prioritize choosing mons after a KO prioritizing the following criteria:
* Trapper (can trap the player’s mon and win the 1v1)
* Revenge killer (outspeeds an OHKOs / is outsped and OHKOs, is not OHKOd/ outspeeds and 2HKOs, is not OHKOd / is outsped and 2HKOs, is not 2HKOd)
* Has good type matchup and a super effective move
* Has good type matchup and does not have a super effective move
* Has Baton Pass
* If no mons meet any of the above criteria, choose the one that does the most damage

And will choose mons after a mid-battle switch prioritizing the following criteria:
* Trapper (can trap the player’s mon and win the 1v1)
* Has good type matchup and a super effective move
* Has good type matchup and does not have a super effective move
* Is not 3HKO’d by the player
* Has Baton Pass

## `AI_FLAG_CONSERVATIVE`
AI always assumes it will roll the lowest possible result when comparing damage in scoring. 

## `AI_FLAG_SEQUENCE_SWITCHING`
AI will always switch out after a KO in exactly party order as defined in the trainer data (ie. slot 1, then 2, then 3, etc.). The AI will never switch out mid-battle unless forced to (Roar etc.). If the AI uses a move that requires a switch where it makes a decision about what to send in (U-Turn etc.), it will always switch out into the lowest available party index.
