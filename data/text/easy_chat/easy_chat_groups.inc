	.include "data/text/easy_chat/easy_chat_group_pokemon.s"
	.include "data/text/easy_chat/easy_chat_group_trainer.s"
	.include "data/text/easy_chat/easy_chat_group_status.s"
	.include "data/text/easy_chat/easy_chat_group_battle.s"
	.include "data/text/easy_chat/easy_chat_group_greetings.s"
	.include "data/text/easy_chat/easy_chat_group_people.s"
	.include "data/text/easy_chat/easy_chat_group_voices.s"
	.include "data/text/easy_chat/easy_chat_group_speech.s"
	.include "data/text/easy_chat/easy_chat_group_endings.s"
	.include "data/text/easy_chat/easy_chat_group_feelings.s"
	.include "data/text/easy_chat/easy_chat_group_conditions.s"
	.include "data/text/easy_chat/easy_chat_group_actions.s"
	.include "data/text/easy_chat/easy_chat_group_lifestyle.s"
	.include "data/text/easy_chat/easy_chat_group_hobbies.s"
	.include "data/text/easy_chat/easy_chat_group_time.s"
	.include "data/text/easy_chat/easy_chat_group_misc.s"
	.include "data/text/easy_chat/easy_chat_group_adjectives.s"
	.include "data/text/easy_chat/easy_chat_group_events.s"
	.include "data/text/easy_chat/easy_chat_group_move_1.s"
	.include "data/text/easy_chat/easy_chat_group_move_2.s"
	.include "data/text/easy_chat/easy_chat_group_trendy_saying.s"
	.include "data/text/easy_chat/easy_chat_group_pokemon2.s"

	.align 2
gEasyChatGroups:: @ 859D004
	.4byte gEasyChatGroup_Pokemon
	.2byte 202 @ total number of entries
	.2byte 202 @ number of enabled entries

	.4byte gEasyChatGroup_Trainer
	.2byte 27 @ total number of entries
	.2byte 21 @ number of enabled entries

	.4byte gEasyChatGroup_Status
	.2byte 109 @ total number of entries
	.2byte 109 @ number of enabled entries

	.4byte gEasyChatGroup_Battle
	.2byte 63 @ total number of entries
	.2byte 63 @ number of enabled entries

	.4byte gEasyChatGroup_Greetings
	.2byte 42 @ total number of entries
	.2byte 42 @ number of enabled entries

	.4byte gEasyChatGroup_People
	.2byte 75 @ total number of entries
	.2byte 75 @ number of enabled entries

	.4byte gEasyChatGroup_Voices
	.2byte 63 @ total number of entries
	.2byte 63 @ number of enabled entries

	.4byte gEasyChatGroup_Speech
	.2byte 60 @ total number of entries
	.2byte 60 @ number of enabled entries

	.4byte gEasyChatGroup_Endings
	.2byte 69 @ total number of entries
	.2byte 69 @ number of enabled entries

	.4byte gEasyChatGroup_Feelings
	.2byte 69 @ total number of entries
	.2byte 69 @ number of enabled entries

	.4byte gEasyChatGroup_Conditions
	.2byte 69 @ total number of entries
	.2byte 69 @ number of enabled entries

	.4byte gEasyChatGroup_Actions
	.2byte 78 @ total number of entries
	.2byte 78 @ number of enabled entries

	.4byte gEasyChatGroup_Lifestyle
	.2byte 45 @ total number of entries
	.2byte 45 @ number of enabled entries

	.4byte gEasyChatGroup_Hobbies
	.2byte 54 @ total number of entries
	.2byte 54 @ number of enabled entries

	.4byte gEasyChatGroup_Time
	.2byte 45 @ total number of entries
	.2byte 45 @ number of enabled entries

	.4byte gEasyChatGroup_Misc
	.2byte 42 @ total number of entries
	.2byte 42 @ number of enabled entries

	.4byte gEasyChatGroup_Adjectives
	.2byte 36 @ total number of entries
	.2byte 36 @ number of enabled entries

	.4byte gEasyChatGroup_Events
	.2byte 29 @ total number of entries
	.2byte 29 @ number of enabled entries

	.4byte gEasyChatGroup_Move1
	.2byte 154 @ total number of entries
	.2byte 154 @ number of enabled entries

	.4byte gEasyChatGroup_Move2
	.2byte 200 @ total number of entries
	.2byte 200 @ number of enabled entries

	.4byte gEasyChatGroup_TrendySaying
	.2byte 33 @ total number of entries
	.2byte 33 @ number of enabled entries

	.4byte gEasyChatGroup_Pokemon2
	.2byte 251 @ total number of entries
	.2byte 251 @ number of enabled entries
