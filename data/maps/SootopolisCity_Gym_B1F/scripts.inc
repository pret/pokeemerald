SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "I'll show you the sublime techniques\n"
	.string "I learned from our Leader Juan!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "Please forgive me, Juan…$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "Watch what happens if you crack all\n"
	.string "the floor tiles.$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "You came all the way here, but you won't\n"
	.string "get to see Juan.\p"
	.string "Not if you lose to me, you won't!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "You're strong!\n"
	.string "I was fooled by your cute looks!$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "You might be good enough to avoid\n"
	.string "being wiped out in one hit by Juan.$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "The sight of Juan conducting\n"
	.string "a battle…\p"
	.string "The very beauty of it compelled me to\n"
	.string "become a Trainer.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "You battled with more beauty than\n"
	.string "I could muster…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "The grace you bring to battle is\n"
	.string "fabulous.\p"
	.string "Oh… I'm so fortunate to have found\n"
	.string "Pokémon.$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "I should teach you how harsh battles\n"
	.string "can be.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "Oh.\n"
	.string "You're strong.$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "I'll tell you something good.\p"
	.string "If you want to reach Juan, you\n"
	.string "need to walk on each floor tile once.$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "The Pokémon Gym of the highest level\n"
	.string "in the Hoenn region…\p"
	.string "That's the Sootopolis Gym.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "What a high level you are!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "Rather than being satisfied by being\n"
	.string "in a strong Gym, I imagine training in\l"
	.string "other places will make you stronger.\l"
	.string "But above all, it looks more fun.$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "I train my Pokémon together with\n"
	.string "Juan.\p"
	.string "Don't think I'm a pushover.$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "I was beaten…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "I think you have potential.\n"
	.string "Why don't you stay and train with us?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "A graceful glide across the ice while\n"
	.string "crossing no lines…\p"
	.string "A Trainer putting on that performance\n"
	.string "would be elegantly beautiful!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "Well, excuse me?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "This is really obvious, but how strong\n"
	.string "you are as a Trainer has nothing to do\l"
	.string "with how young or old you are.$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "When I'm with my Pokémon, the time\n"
	.string "flies by before you can say, “Oops!”$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "Oops!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "I wish I could forget about lost causes\n"
	.string "before I can manage an “Oops!”$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "I can battle with really rare Pokémon\n"
	.string "if you'd like.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "Oh, there now! Did you have a good look\n"
	.string "at my Pokémon?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "I came to this Gym because Juan\n"
	.string "praised me for my darling Pokémon.\p"
	.string "Oh, if only I'd met Juan years ago\n"
	.string "when I was younger…$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "Giggle…\n"
	.string "Your grim look is so charming.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "Oh, dear.\n"
	.string "I went much too easy on you.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "You couldn't lay a finger on Juan,\n"
	.string "I'm sure. Giggle…$"

