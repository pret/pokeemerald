.set REWARD_TYPE, VAR_0x8004
.set REWARD_ITEM, VAR_0x8008

CeruleanCity_House4_Frlg_MapScripts::
	.byte 0

CeruleanCity_House4_EventScript_WonderNewsBerryMan::
	lock
	specialvar REWARD_TYPE, WonderNews_GetRewardInfo
	copyvar REWARD_ITEM, VAR_RESULT
	goto_if_eq REWARD_TYPE, NEWS_REWARD_NONE,       CeruleanCity_House4_EventScript_NoNews
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_SMALL, CeruleanCity_House4_EventScript_Reward_RecvSmall
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_BIG,   CeruleanCity_House4_EventScript_Reward_RecvBig
	goto_if_eq REWARD_TYPE, NEWS_REWARD_WAITING,    CeruleanCity_House4_EventScript_Waiting
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_SMALL, CeruleanCity_House4_EventScript_Reward_SentSmall
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_BIG,   CeruleanCity_House4_EventScript_Reward_SentBig
	goto_if_eq REWARD_TYPE, NEWS_REWARD_AT_MAX,     CeruleanCity_House4_EventScript_AtMax
	end

@ Mystery Gift is not enabled, or the player has no saved Wonder News
CeruleanCity_House4_EventScript_NoNews::
	msgbox CeruleanCity_House4_Text_NothingEntertaining
	release
	end

@ Small reward for receiving Wonder News from friend
CeruleanCity_House4_EventScript_Reward_RecvSmall::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_NewNewsInformativeHaveThis
	giveitem REWARD_ITEM
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Big reward for receiving Wonder News from non-friend source
CeruleanCity_House4_EventScript_Reward_RecvBig::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_IncredibleNewsHaveBerries
	giveitem REWARD_ITEM, 4
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Player has not recently sent Wonder News
CeruleanCity_House4_EventScript_Waiting::
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_House4_Text_WishCouldShareNewsWithOthers
	release
	end

@ Small reward for sending Wonder News every 1-3 times
CeruleanCity_House4_EventScript_Reward_SentSmall::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis
	giveitem REWARD_ITEM
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Big reward for sending Wonder News every 4th time
CeruleanCity_House4_EventScript_Reward_SentBig::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries
	giveitem REWARD_ITEM, 4
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Player has hit reward limit and must wait to receive new rewards
CeruleanCity_House4_EventScript_AtMax::
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews
	release
	end

CeruleanCity_House4_EventScript_MovementReactionToNews::
	playse SE_PIN
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_Delay48
	waitmovement 0
	return

CeruleanCity_House4_EventScript_NoRoomForBerries::
	msgbox CeruleanCity_House4_Text_YourBerryPouchIsFull
	release
	end

CeruleanCity_House4_Text_NothingEntertaining::
	.string "Sigh…\n"
	.string "Too much time, too little to do…\p"
	.string "Is nothing entertaining happening\n"
	.string "anywhere?$"

CeruleanCity_House4_Text_NewNewsInformativeHaveThis::
	.string "Ah!\n"
	.string "A new news report!\p"
	.string "Hmm…\p"
	.string "I see!\n"
	.string "That was quite informative!\p"
	.string "I applaud you for taking interest\n"
	.string "in the news at your young age.\p"
	.string "As my thanks for sharing the news\n"
	.string "with me, I want you to have this.$"

CeruleanCity_House4_Text_IncredibleNewsHaveBerries::
	.string "Oh, oh!\n"
	.string "Th-this news report!\p"
	.string "Hmm…\p"
	.string "Amazing!\n"
	.string "What an incredible piece of news!\p"
	.string "I haven't seen a news story this\n"
	.string "incredible in too long a time!\p"
	.string "Thanks for sharing this fantastic\n"
	.string "news. Have a bunch of BERRIES!$"

CeruleanCity_House4_Text_WishCouldShareNewsWithOthers::
	.string "It seems such a shame to not share\n"
	.string "this news with other folks…\p"
	.string "I wish I could tell someone…\n"
	.string "Let others know the news…$"

CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis::
	.string "Ah, you've spread the news for me?\p"
	.string "Good news becomes worthwhile when\n"
	.string "all sorts of people share it.\p"
	.string "As my thanks for your spreading\n"
	.string "the news, take this!$"

CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries::
	.string "You've spread the news some more?\n"
	.string "Magnificent!\p"
	.string "That piece of news must be\n"
	.string "delighted to be passed around so.\p"
	.string "Yes, indeed!\p"
	.string "Consider this a show of\n"
	.string "appreciation from me and the news.\p"
	.string "I'll give you more BERRIES than\n"
	.string "I usually do.$"

CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews::
	.string "I'm quite enjoying myself with all\n"
	.string "sorts of news.\p"
	.string "Yes, I am satisfied!\n"
	.string "I won't be bored for a while.$"

CeruleanCity_House4_Text_YourBerryPouchIsFull::
	.string "Hm? Your BERRY POUCH is full.\n"
	.string "My gift remains ungiven, then.$"

