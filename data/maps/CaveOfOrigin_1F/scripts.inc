CaveOfOrigin_1F_MapScripts:: @ 8235768
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_1F_OnTransition
	.byte 0

CaveOfOrigin_1F_OnTransition: @ 823576E
	call_if_set FLAG_UNUSED_RS_LEGENDARY_BATTLE_DONE, CaveOfOrigin_EventScript_DisableTriggers
	end
