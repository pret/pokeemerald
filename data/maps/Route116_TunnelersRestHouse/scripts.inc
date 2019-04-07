Route116_TunnelersRestHouse_MapScripts:: @ 822B850
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition: @ 822B856
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_22B85A:: @ 822B85A
	msgbox Route116_TunnelersRestHouse_Text_22B88B, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_22B863:: @ 822B863
	msgbox Route116_TunnelersRestHouse_Text_22B99F, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_22B86C:: @ 822B86C
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_22B881
	msgbox Route116_TunnelersRestHouse_Text_22BAAF, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_22B881:: @ 822B881
	msgbox Route116_TunnelersRestHouse_Text_22BB3B, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_22B88B: @ 822B88B
	.string "That RUSTURF TUNNEL there…\p"
	.string "At first, we had a huge work crew boring\n"
	.string "through rock with the latest machinery.\l"
	.string "But, we had to stop.\p"
	.string "It turns out that we would have had\n"
	.string "a negative effect on wild POKéMON in\l"
	.string "the area.\p"
	.string "So, we've got nothing to do but loll\n"
	.string "around here doing nothing.$"

Route116_TunnelersRestHouse_Text_22B99F: @ 822B99F
	.string "There's a man digging his way to\n"
	.string "VERDANTURF all by his lonesome.\l"
	.string "He's desperate to get through.\p"
	.string "He says that if he digs little by little\n"
	.string "without using machines, he won't\l"
	.string "disturb POKéMON, and he'll avoid\l"
	.string "harming the natural environment.\p"
	.string "I wonder if he made it through yet.$"

Route116_TunnelersRestHouse_Text_22BAAF: @ 822BAAF
	.string "To get to VERDANTURF without using\n"
	.string "this TUNNEL, you'd have to cross the\l"
	.string "sea to DEWFORD, sail on to SLATEPORT,\l"
	.string "then travel through MAUVILLE.$"

Route116_TunnelersRestHouse_Text_22BB3B: @ 822BB3B
	.string "Did you hear? The TUNNEL to VERDANTURF\n"
	.string "has gone through!\p"
	.string "Sometimes, if you hope strongly enough,\n"
	.string "dreams do come true.$"

