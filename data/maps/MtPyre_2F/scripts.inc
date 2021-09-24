MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F, 255, 0, 0
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Memories of my darling Skitty…\n"
	.string "My eyes overflow thinking about it.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ooch, ouch… There are holes in the\n"
	.string "ground here and there.\p"
	.string "I didn't notice and took a tumble from\n"
	.string "the floor above.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hey! Are you searching for Pokémon?\n"
	.string "You came along after me! You're rude!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ayieeeeh!\n"
	.string "I'm sorry, forgive me, please!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "People don't come here often, so\n"
	.string "I thought there'd be rare Pokémon.$"

MtPyre_2F_Text_LukeIntro:
	.string "Luke: We're here on a dare.\p"
	.string "Heheh, if I show her how cool I am,\n"
	.string "she'll fall for me. I know it!\p"
	.string "I know! I'll cream you and show her\n"
	.string "how cool I am!$"

MtPyre_2F_Text_LukeDefeat:
	.string "Luke: Whoopsie!$"

MtPyre_2F_Text_LukePostBattle:
	.string "Luke: Well, we lost but that's okay!\n"
	.string "I'm right here by your side.\l"
	.string "We'll make it through this dare!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "Luke: If you want to take me on,\n"
	.string "bring some more Pokémon.\p"
	.string "If you don't, I won't be able to show\n"
	.string "off to my girl how cool I am!$"

MtPyre_2F_Text_DezIntro:
	.string "Dez: I came here on a dare with my\n"
	.string "boyfriend.\p"
	.string "It's really scary, but I'm with my\n"
	.string "boyfriend. It's okay.\p"
	.string "I know! I'll get my boyfriend to look\n"
	.string "cool by beating you!$"

MtPyre_2F_Text_DezDefeat:
	.string "Dez: Waaaah! I'm scared!$"

MtPyre_2F_Text_DezPostBattle:
	.string "Dez: We're lovey-dovey, so we don't\n"
	.string "care if we lose!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "Dez: If you want to challenge us, you\n"
	.string "should bring at least two Pokémon.\p"
	.string "My boyfriend's strong.\n"
	.string "Just one Pokémon won't do at all.$"

MtPyre_2F_Text_LeahIntro:
	.string "You are an unfamiliar sight…\n"
	.string "Depart before anything befalls you!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm…\n"
	.string "You're durable.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Our family has been Trainers here\n"
	.string "since my great-grandmother's time…\p"
	.string "It is my duty to protect this\n"
	.string "mountain…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiyaaaaah!\n"
	.string "I'm terrified!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Nooooooo!\n"
	.string "I lost my wits!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "I get freaked out every time I see\n"
	.string "anything move…\p"
	.string "I shouldn't have come here to train…$"

