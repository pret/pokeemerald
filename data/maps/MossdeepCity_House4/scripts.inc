MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "My little brother says he likes to go\n"
	.string "find people's Secret Bases.$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "My little brother says he likes to\n"
	.string "visit people's Secret Bases and have\l"
	.string "Pokémon battles.$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "Was it you who made a Secret Base\n"
	.string "near {STR_VAR_1}?$"

MossdeepCity_House4_Text_MakeSecretBase:
	.string "You should make a Secret Base\n"
	.string "somewhere. I'll go find it!$"

MossdeepCity_House4_Text_Skitty:
	.string "Skitty: Miyaan?$"

