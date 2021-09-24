BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	compare VAR_FRONTIER_MANIAC_FACILITY, 0
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferSingle
	compare VAR_FRONTIER_MANIAC_FACILITY, 1
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferDouble
	compare VAR_FRONTIER_MANIAC_FACILITY, 2
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferMulti
	compare VAR_FRONTIER_MANIAC_FACILITY, 3
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferMultiLink
	compare VAR_FRONTIER_MANIAC_FACILITY, 4
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattleDome
	compare VAR_FRONTIER_MANIAC_FACILITY, 5
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	compare VAR_FRONTIER_MANIAC_FACILITY, 6
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	compare VAR_FRONTIER_MANIAC_FACILITY, 7
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattleArena
	compare VAR_FRONTIER_MANIAC_FACILITY, 8
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattlePike
	compare VAR_FRONTIER_MANIAC_FACILITY, 9
	call_if_eq BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
	compare VAR_FRONTIER_MANIAC_FACILITY, 3
	call_if_le BattleFrontier_Lounge2_EventScript_BattleTowerNews
	compare VAR_FRONTIER_MANIAC_FACILITY, 4
	call_if_ge BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring 0, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring 0, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring 0, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring 0, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring 0, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring 0, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring 0, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring 0, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring 0, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring 0, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Howdy! When it comes to news about\n"
	.string "the Battle Frontier, I'm no. 1.\p"
	.string "You can think of me as\n"
	.string "the Frontier Maniac.\p"
	.string "Just checking, but you are a Trainer,\n"
	.string "isn't that right?\p"
	.string "I'll happily share the hottest news\n"
	.string "I gathered about the Battle Frontier.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Howdy! Did you swing by to grill me\n"
	.string "about the latest word? Oh, all right!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Well? Well? Well?\p"
	.string "I'm sure my information's been\n"
	.string "seriously useful to you, right?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Let's see now…\p"
	.string "It sounds like the {STR_VAR_1}\n"
	.string "is the hottest place going.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Let's see now…\p"
	.string "It sounds like Battle Tower\n"
	.string "{STR_VAR_1} is the hottest.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Trainers that Scott\n"
	.string "calls the Frontier Brains is there.\p"
	.string "It's this mysterious Trainer called\n"
	.string "the Salon Maiden that runs the place.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Have you battled the Salon Maiden?\p"
	.string "When she's measuring up her opponent,\n"
	.string "she apparently uses these Pokémon:\p"
	.string "A Psychic-type PSI Pokémon,\n"
	.string "a Fire-type Volcano Pokémon,\l"
	.string "and a Normal-type Sleeping Pokémon.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Have you battled the Salon Maiden\n"
	.string "when she's serious?\p"
	.string "When she's battling flat out,\n"
	.string "she apparently uses these Pokémon:\p"
	.string "A Dragon & Psychic Eon Pokémon,\n"
	.string "an Electric-type Thunder Pokémon,\l"
	.string "and a Normal-type Sleeping Pokémon.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Trainers that Scott\n"
	.string "calls the Frontier Brains is there.\p"
	.string "It's this flamboyant Trainer called\n"
	.string "the Dome Ace that runs the place.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Have you battled the Dome Ace?\p"
	.string "When he's treating the opponent\n"
	.string "lightly, he uses these three Pokémon:\p"
	.string "A Dragon & Flying Dragon Pokémon,\n"
	.string "a Water & Ground Mud Fish Pokémon,\l"
	.string "and a Fire & Flying Flame Pokémon.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Have you battled the Dome Ace\n"
	.string "when he's serious?\p"
	.string "When he's demonstrating his strategy,\n"
	.string "he uses these three Pokémon:\p"
	.string "A Dragon & Flying Eon Pokémon,\n"
	.string "a Water & Ground Mud Fish Pokémon,\l"
	.string "and a Steel- & Psychic-type Iron Leg\l"
	.string "Pokémon.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Trainers that Scott\n"
	.string "calls the Frontier Brains is there.\p"
	.string "It's this freaky Trainer called\n"
	.string "the Factory Head that runs the place.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Have you battled the Factory Head\n"
	.string "already?\p"
	.string "Let me think… When he goes to battle,\n"
	.string "he just gets three rental Pokémon.\p"
	.string "He battles under pretty much the same\n"
	.string "conditions as you.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Have you battled the Factory Head\n"
	.string "when he's serious?\p"
	.string "When he goes seriously to battle,\n"
	.string "he still gets three rental Pokémon.\p"
	.string "He battles under virtually the same\n"
	.string "conditions as you.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Trainers that Scott\n"
	.string "calls the Frontier Brains is there.\p"
	.string "It's this scary Trainer called\n"
	.string "the Pike Queen that runs the place.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Have you battled the Pike Queen\n"
	.string "before?\p"
	.string "When she's in a good mood, they say\n"
	.string "she uses these three Pokémon:\p"
	.string "A Poison-type Fang Snake Pokémon,\n"
	.string "a Bug & Rock Mold Pokémon,\l"
	.string "and a Water-type Tender Pokémon.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Have you battled the Pike Queen\n"
	.string "when she's serious?\p"
	.string "When she's seriously annoyed, they say\n"
	.string "she uses these three Pokémon:\p"
	.string "A Poison-type Fang Snake Pokémon,\n"
	.string "a Steel & Ground Iron Snake Pokémon,\l"
	.string "and a Water- & Flying-type Atrocious\l"
	.string "Pokémon.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Trainers that Scott\n"
	.string "calls the Frontier Brains is there.\p"
	.string "It's this cute Trainer called\n"
	.string "the Arena Tycoon that runs the place.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Have you battled the Arena Tycoon\n"
	.string "before?\p"
	.string "When she's assessing the foe's ability,\n"
	.string "she supposedly uses these Pokémon:\p"
	.string "A Bug & Fighting Single Horn Pokémon,\n"
	.string "a Dark-type Moonlight Pokémon,\l"
	.string "and a Bug & Ghost Shed Pokémon.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Have you battled the Arena Tycoon\n"
	.string "when she's serious?\p"
	.string "When she battles for keeps,\n"
	.string "she supposedly uses these Pokémon:\p"
	.string "A Dark-type Moonlight Pokémon,\n"
	.string "a Ghost & Poison Shadow Pokémon\l"
	.string "and a Grass- & Fighting-type\l"
	.string "Mushroom Pokémon.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Trainers that Scott\n"
	.string "calls the Frontier Brains is there.\p"
	.string "It's this sinister Trainer called\n"
	.string "the Palace Maven that runs the place.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Have you battled the Palace Maven\n"
	.string "before?\p"
	.string "When he's testing the opponent's\n"
	.string "spirit, he's said to use these Pokémon:\p"
	.string "A Poison & Flying-type Bat Pokémon,\n"
	.string "a Normal-type Lazy Pokémon, and a\l"
	.string "Water- & Ice-type Transport Pokémon.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Have you battled the Palace Maven\n"
	.string "when he's serious?\p"
	.string "When he throws his entire might into\n"
	.string "battle, he's said to use these Pokémon:\p"
	.string "A Fire-type Legendary Pokémon,\n"
	.string "a Normal-type Lazy Pokémon,\l"
	.string "and a Water-type Aurora Pokémon.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Trainers that Scott\n"
	.string "calls the Frontier Brains is there.\p"
	.string "It's this fiery-hot Trainer called\n"
	.string "the Pyramid King that runs the place.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Have you battled the Pyramid King\n"
	.string "before?\p"
	.string "When he's checking the foe's power,\n"
	.string "he apparently uses these Pokémon:\p"
	.string "A Rock-type Rock Peak Pokémon,\n"
	.string "an Ice-type Iceberg Pokémon,\l"
	.string "and a Steel-type Iron Pokémon.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Have you battled the Pyramid King\n"
	.string "when he's serious?\p"
	.string "When he's pumped with hot power,\n"
	.string "he apparently uses these Pokémon:\p"
	.string "An Ice & Flying Freeze Pokémon, an\n"
	.string "Electric & Flying Electric Pokémon,\l"
	.string "and a Fire- & Flying-type Flame\l"
	.string "Pokémon.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Sure, there are several places where\n"
	.string "you can enter Double Battles.\p"
	.string "But the Double Battle Rooms of\n"
	.string "the Battle Tower are, like, basic!\p"
	.string "They're where you should learn about\n"
	.string "how Double Battles are played here\l"
	.string "in the Battle Frontier.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Watch yourself in the battles here.\p"
	.string "I hear there are Trainers that have\n"
	.string "strategies they developed just for\l"
	.string "Double Battles.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Once you're confident and comfortable\n"
	.string "with Double Battles here, you should\l"
	.string "think about challenging other places\l"
	.string "offering Double Battles.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "All sorts of Trainers gather in\n"
	.string "the Battle Salon.\p"
	.string "Just think--you may run into your\n"
	.string "friends or followers!\l"
	.string "You should look carefully!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "If you're with a friend, head for the\n"
	.string "Link Multi Battle Room.\p"
	.string "If you play with a strong friend,\n"
	.string "you can expect to see tough foes!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "What amazing news-gathering power!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "What amazing powers of observation!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "What amazing power of persuasion!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…What is this place?\n"
	.string "It's scaring me…$"

