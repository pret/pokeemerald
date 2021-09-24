SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
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

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "There's a bed…\n"
	.string "Let's take a rest.$"

SSTidalRooms_Text_ColtonIntro:
	.string "I often sail to Lilycove City.\p"
	.string "I enjoy attending Contests,\n"
	.string "you see.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "That was an enjoyable match!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "I get so excited imagining what kinds\n"
	.string "of Pokémon I'll get to see in the next\l"
	.string "Contest. The anticipation of it thrills!$"

SSTidalRooms_Text_MicahIntro:
	.string "Are your friends strong?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Your friends are, indeed, strong.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Friends need not be human.\n"
	.string "For me, Pokémon are treasured friends!$"

SSTidalRooms_Text_ThomasIntro:
	.string "Child…\n"
	.string "Did you knock on the door?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "A loss is to be accepted without haste\n"
	.string "or panic.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "To be never ruffled in any situation is\n"
	.string "the Gentleman's code of conduct.$"

SSTidalRooms_Text_JedIntro:
	.string "Jed: I feel a little shy about this, but…\n"
	.string "We'll show you our lovey-dovey power!$"

SSTidalRooms_Text_JedDefeat:
	.string "Jed: Sigh…$"

SSTidalRooms_Text_JedPostBattle:
	.string "Jed: It's the first time that our lovey-\n"
	.string "dovey power couldn't prevail!\l"
	.string "You must be an awesome Trainer!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "Jed: You only have one Pokémon?\n"
	.string "Isn't that just too lonesome?$"

SSTidalRooms_Text_LeaIntro:
	.string "Lea: I feel a little silly, but…\n"
	.string "We'll show you our lovey-dovey power!$"

SSTidalRooms_Text_LeaDefeat:
	.string "Lea: Oh, boo!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "Lea: I can't believe it!\n"
	.string "Our lovey-dovey power failed…\l"
	.string "You must be an awesome Trainer!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "Lea: I wanted to battle…\n"
	.string "But you don't even have two Pokémon…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, you've come just in time.\p"
	.string "I'm bored, you see.\n"
	.string "You may entertain me.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…That will do.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Perhaps I shall get Father to acquire\n"
	.string "a yacht for me.\l"
	.string "A yacht for me and Pokémon!$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, you're such an adorable Trainer.\n"
	.string "Would you like to have tea?\l"
	.string "Or would you rather battle?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "I see.\n"
	.string "You're the active sort.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "A world cruise on a luxury liner has its\n"
	.string "charms, I must say…\p"
	.string "But, I will admit there is an appealing\n"
	.string "side to touring Hoenn by ferry.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Uh… Hi! I… I'm not acting suspicious!\n"
	.string "Uh… You can have this! For free!\p"
	.string "It… Honestly, I didn't Snatch it from\n"
	.string "someone! I'd never do such a thing!\l"
	.string "It's clean! You can use it!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "Snatch steals the beneficial effects\n"
	.string "of certain moves before they can be\l"
	.string "used by a foe or ally.$"

