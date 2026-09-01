# What are Dynamic AI Functions?
Dynamic AI functions enable AI behaviour to be controlled on a per-battle basis by being set directly ahead of a particular battle when scripting. They allow for unique move scoring or switching decisions that are not applied at scale to multiple trainers or the entire AI as a whole.

As such they're really useful for one-shot battle setups like boss fights or totem Pokemon or narrative tie-ins like switch happy Jugglers that would benefit from specialized AI that only applies during those specific fights.

There are currently two different types of dynamic AI functions, one that affects move scoring and one that affects switching.

# How do I use the dynamic move scoring function?
There are a few steps involved:
- Be sure to set `AI_FLAG_DYNAMIC_FUNC` on the trainer you'll be using your unique behaviour for
- Write your custom AI logic. Our example for this is `AI_TagBattlePreferFoe`, and you should match its arguments and return structure in your own custom function.
- In the script the triggers the battle, add a call to `setdynamicaifunc` specifying your function, as in:
```
setdynamicaifunc AI_TagBattlePreferFoe
multi_2_vs_2 TRAINER_SIRIUS_NOVA_HYPERION_TAG, Text_NovaInsurgence_Arrival_Hyperion_Loss, TRAINER_SIRIUS_NOVA_DEIMOS_RECRUIT_TAG, Text_NovaInsurgence_Arrival_DeimosRecruit_Loss, TRAINER_SIRIUS_WHARF_TRITON_PARTNER, TRAINER_PIC_BACK_TRITON
```
That's it! The scoring function will be used in the battle immediately following it, and automatically cleared at the end of the battle. You can then use `setdynamicaifunc` with the same or a different AI scoring function as you see fit.

# How do I use the dynamic switching function?
There are a few steps involved:
- Write your custom AI logic. Our example for this is `ShouldSwitchDynFuncExample`, and you should match its arguments and return structure in your own custom function.
- In the script that triggers the battle, add a call to `setdynamicswitchaifunc` specifying your function, as in:
```
setdynamicswitchaifunc ShouldSwitchDynFuncExample
trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
```
That's it! The switching function will be used in the battle immediately following it, and automatically cleared at the end of the battle. You can then use `setdynamicswitchaifunc` with the same or a different AI scoring function as you see fit.
