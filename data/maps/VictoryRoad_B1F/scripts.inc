VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "The thought that I'm getting closer to\n"
	.string "the Pokémon League…\p"
	.string "I'm getting stage fright…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "I couldn't do a thing…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "The Pokémon League became distant\n"
	.string "again… What a letdown…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "To win your way through the Pokémon\n"
	.string "League, you need the trust of your\l"
	.string "Pokémon.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Your relationship is based on\n"
	.string "solid trust.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "By being together all the time, trust\n"
	.string "grows between Pokémon and Trainers.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "This isn't the goal. It's only a place\n"
	.string "on the way to the Pokémon League.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "That's the way!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "You'll do fine, for sure!\n"
	.string "Your Pokémon are all eager to go!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "My Pokémon are cosmically\n"
	.string "awe inspiring!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "I've never met anyone like you before.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Even outside of battle, I sense\n"
	.string "incredible power emanating from you\l"
	.string "and your Pokémon.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "Okay, no need to get your back up!\n"
	.string "Relax, let's take it easy!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Whoa!\n"
	.string "Wonderful!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Sure, this is Victory Road.\p"
	.string "But it's not all that different from\n"
	.string "the path you've taken so far.\p"
	.string "Try to enjoy things the rest of\n"
	.string "the way!$"

