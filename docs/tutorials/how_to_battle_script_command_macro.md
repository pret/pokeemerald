## How to add new Battle Script Commands/Macros

To preface this tutorial, the battle engine upgrade has exhausted all battle script command IDs. Historically, we've used the `various` command to effectively add new commands. However, this has caused issues of maintainability and readability due to the massive switch needed for it. Thanks to the cleanup made by the team and contributors, we now are able to call an infinite amount of commands by using `callnative`. This is preferential to creating a secondary battle script command table like is done in the CFRU.

In general, `gBattlescriptCurrInstr` tracks the current battle script position as a ROM address. Fortunately, we don't need to worry about ROM addresses when using the decomps, but it is important to understand because of how the `callnative` command is set up.

```
	.macro callnative func:req
	.byte 0xff
	.4byte \func
	.endm
```
`callnative` uses the last battle script command ID in order to pass a native function as an argument. Additional optional arguments are added recursively via a macro, so no need to worry about how they need to align to the amount of instructions to skip.

Now, how might we add a custom `callnative` command? Here are the steps. We will use `BS_JumpIfTerrainAffected` as an example.
### 1. Create a macro in `asm/macros/battle_script.inc`. For example:
```c
	.macro jumpifterrainaffected battler:req, terrainFlags:req, jumpInstr:req
	callnative BS_JumpIfTerrainAffected
	.byte \battler
	.4byte \terrainFlags
	.4byte \jumpInstr
	.endm
```
### 2. Add your new callnative command ID to `src/battle_script_commands.c`. For example:
```c
void BS_JumpIfTerrainAffected(void)
{
    NATIVE_ARGS(u8 battler, u32 flags, const u8 *jumpInstr);
    u32 battler = GetBattlerForBattleScript(cmd->battler);

    if (IsBattlerTerrainAffected(battler, cmd->flags))
        gBattlescriptCurrInstr = cmd->jumpInstr;
    else
        gBattlescriptCurrInstr = cmd->nextInstr;
}
```
Each of the arguments defined in the macro (`battler`, `flags`, `failInstr`) need to be called at the start of the command using `NATIVE_ARGS`.
The byte count in the macro should correspond to the type that will be used for the command (eg, `u8` is `byte`, while the pointer are `4byte`).
These arguments can then be accessed as `cmd->battler`, `cmd->flags` and `cmd->failInstr`.
Note that for `cmd->battler` we need to use `GetBattlerForBattleScript` to fetch the correct battler because with the macro we are accessing a scripting command that doesn't corresponds to `gBattlerTarget`, `gBattlerAttacker`, etc.
For the battler argument specifically, most of the time the battler is accessed through `gBattlerAttacker`, `gBattlerTarget` and the battler argument left out.
In the majority of cases, this is fine since the script commands are mostly used for moves and the interaction is usually between an attacker and target.
A script command usually ends with either a jump or next instruction `gBattlescriptCurrInstr = cmd->nextInstr / cmd->nextInstr;` advancing to the next instruction.
