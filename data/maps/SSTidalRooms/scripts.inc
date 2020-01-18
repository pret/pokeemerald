SSTidalRooms_MapScripts:: @ 823C9F1
	.byte 0

SSTidalRooms_EventScript_SnatchGiver:: @ 823C9F2
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM49, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM49
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM49
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch:: @ 823CA29
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed:: @ 823CA33
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton:: @ 823CA49
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah:: @ 823CA60
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas:: @ 823CA77
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed:: @ 823CA8E
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea:: @ 823CAA9
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret:: @ 823CAC4
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi:: @ 823CADB
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed: @ 823CAF2
	.string "There's a bed…\n"
	.string "Let's take a rest.$"

SSTidalRooms_Text_ColtonIntro: @ 823CB14
	.string "I often sail to LILYCOVE CITY.\p"
	.string "I enjoy attending CONTESTS,\n"
	.string "you see.$"

SSTidalRooms_Text_ColtonDefeat: @ 823CB58
	.string "That was an enjoyable match!$"

SSTidalRooms_Text_ColtonPostBattle: @ 823CB75
	.string "I get so excited imagining what kinds\n"
	.string "of POKéMON I'll get to see in the next\l"
	.string "CONTEST. The anticipation of it thrills!$"

SSTidalRooms_Text_MicahIntro: @ 823CBEB
	.string "Are your friends strong?$"

SSTidalRooms_Text_MicahDefeat: @ 823CC04
	.string "Your friends are, indeed, strong.$"

SSTidalRooms_Text_MicahPostBattle: @ 823CC26
	.string "Friends need not be human.\n"
	.string "For me, POKéMON are treasured friends!$"

SSTidalRooms_Text_ThomasIntro: @ 823CC68
	.string "Child…\n"
	.string "Did you knock on the door?$"

SSTidalRooms_Text_ThomasDefeat: @ 823CC8A
	.string "A loss is to be accepted without haste\n"
	.string "or panic.$"

SSTidalRooms_Text_ThomasPostBattle: @ 823CCBB
	.string "To be never ruffled in any situation is\n"
	.string "the GENTLEMAN's code of conduct.$"

SSTidalRooms_Text_JedIntro: @ 823CD04
	.string "JED: I feel a little shy about this, but…\n"
	.string "We'll show you our lovey-dovey power!$"

SSTidalRooms_Text_JedDefeat: @ 823CD54
	.string "JED: Sigh…$"

SSTidalRooms_Text_JedPostBattle: @ 823CD5F
	.string "JED: It's the first time that our lovey-\n"
	.string "dovey power couldn't prevail!\l"
	.string "You must be an awesome TRAINER!$"

SSTidalRooms_Text_JedNotEnoughMons: @ 823CDC6
	.string "JED: You only have one POKéMON?\n"
	.string "Isn't that just too lonesome?$"

SSTidalRooms_Text_LeaIntro: @ 823CE04
	.string "LEA: I feel a little silly, but…\n"
	.string "We'll show you our lovey-dovey power!$"

SSTidalRooms_Text_LeaDefeat: @ 823CE4B
	.string "LEA: Oh, boo!$"

SSTidalRooms_Text_LeaPostBattle: @ 823CE59
	.string "LEA: I can't believe it!\n"
	.string "Our lovey-dovey power failed…\l"
	.string "You must be an awesome TRAINER!$"

SSTidalRooms_Text_LeaNotEnoughMons: @ 823CEB0
	.string "LEA: I wanted to battle…\n"
	.string "But you don't even have two POKéMON…$"

SSTidalRooms_Text_GarretIntro: @ 823CEEE
	.string "Ah, you've come just in time.\p"
	.string "I'm bored, you see.\n"
	.string "You may entertain me.$"

SSTidalRooms_Text_GarretDefeat: @ 823CF36
	.string "…That will do.$"

SSTidalRooms_Text_GarretPostBattle: @ 823CF45
	.string "Perhaps I shall get Father to acquire\n"
	.string "a yacht for me.\l"
	.string "A yacht for me and POKéMON!$"

SSTidalRooms_Text_NaomiIntro: @ 823CF97
	.string "Oh, you're such an adorable TRAINER.\n"
	.string "Would you like to have tea?\l"
	.string "Or would you rather battle?$"

SSTidalRooms_Text_NaomiDefeat: @ 823CFF4
	.string "I see.\n"
	.string "You're the active sort.$"

SSTidalRooms_Text_NaomiPostBattle: @ 823D013
	.string "A world cruise on a luxury liner has its\n"
	.string "charms, I must say…\p"
	.string "But, I will admit there is an appealing\n"
	.string "side to touring HOENN by ferry.$"

SSTidalRooms_Text_NotSuspiciousTakeThis: @ 823D098
	.string "Uh… Hi! I… I'm not acting suspicious!\n"
	.string "Uh… You can have this! For free!\p"
	.string "It… Honestly, I didn't SNATCH it from\n"
	.string "someone! I'd never do such a thing!\l"
	.string "It's clean! You can use it!$"

SSTidalRooms_Text_ExplainSnatch: @ 823D145
	.string "SNATCH steals the beneficial effects\n"
	.string "of certain moves before they can be\l"
	.string "used by a foe or ally.$"

