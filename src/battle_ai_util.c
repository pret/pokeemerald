#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_util.h"
#include "battle_ai_script_commands.h"
#include "battle_factory.h"
#include "battle_setup.h"
#include "data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"

// Functions
u32 GetHealthPercentage(u8 battlerId)
{
    return (u32)(100 * gBattleMons[battlerId].hp / gBattleMons[battlerId].maxHP);
}    

bool32 IsBattlerTrapped(u8 battler, bool8 switching)
{
    u8 holdEffect = GetBattlerHoldEffect(battler, TRUE);
	if (IS_BATTLER_OF_TYPE(battler, TYPE_GHOST)
	  || (switching && holdEffect == HOLD_EFFECT_SHED_SHELL)
	  || (!switching && GetBattlerAbility(battler) == ABILITY_RUN_AWAY)
	  || (!switching && holdEffect == HOLD_EFFECT_CAN_ALWAYS_RUN))
    {
		return FALSE;
    }
	else
	{
		if (gBattleMons[battler].status2 & (STATUS2_ESCAPE_PREVENTION | STATUS2_WRAPPED)
          || IsAbilityPreventingEscape(battler)
		  || gStatuses3[battler] & (STATUS3_ROOTED)    // TODO: sky drop target in air
		  || (gFieldStatuses & STATUS_FIELD_FAIRY_LOCK))
			return TRUE;
	}

	return FALSE;
}