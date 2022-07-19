MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
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
	.string "Souvenirs de mon cher SKITTY…\n"
	.string "A sa pensée, les larmes me viennent.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ouille, ouille… Des trous parsèment le\n"
	.string "sol ici et là.\p"
	.string "J’avais pas fait attention et je suis\n"
	.string "tombé de l’étage du dessus.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hé! Tu cherches des POKéMON?\n"
	.string "Alors tu m’as trouvé! Quelle audace!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Aïïïïe!\n"
	.string "Désolé, excuse-moi, je t’en prie!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Les gens venant rarement ici, je me\n"
	.string "disais qu’il y aurait des POKéMON rares.$"

MtPyre_2F_Text_LukeIntro:
	.string "KARL: C’est un défi.\p"
	.string "Hé, si je lui prouve que je suis génial,\n"
	.string "elle tombera amoureuse de moi. Je l’sais!\p"
	.string "Je sais! Je vais te mettre la pâtée pour\n"
	.string "lui montrer que je suis génial!$"

MtPyre_2F_Text_LukeDefeat:
	.string "KARL: Oh là là!$"

MtPyre_2F_Text_LukePostBattle:
	.string "KARL: On a perdu, mais c’est\n"
	.string "pas grave!\p"
	.string "Je reste avec toi, on va y arriver!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "KARL: Si tu veux m’affronter,\n"
	.string "apporte plus de POKéMON.\p"
	.string "Sinon, je ne pourrai pas montrer à ma\n"
	.string "copine à quel point je suis génial!$"

MtPyre_2F_Text_DezIntro:
	.string "ANNIE: Si je suis là, c’est parce qu’on\n"
	.string "a fait un pari avec mon petit ami.\p"
	.string "C’est effrayant, mais comme je suis\n"
	.string "avec mon petit ami, ça va.\p"
	.string "Je sais! Mon petit ami va être craquant\n"
	.string "quand il va te battre!$"

MtPyre_2F_Text_DezDefeat:
	.string "ANNIE: Aaaaah! J’ai peur!$"

MtPyre_2F_Text_DezPostBattle:
	.string "ANNIE: On s’aime tendrement, alors on\n"
	.string "s’en fiche de perdre!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "ANNIE: Pour nous affronter, il faut\n"
	.string "que tu aies au moins deux POKéMON.\p"
	.string "Mon petit ami est fort.\n"
	.string "Un seul POKéMON, ça ne suffira pas!$"

MtPyre_2F_Text_LeahIntro:
	.string "Je pressens un malheur…\n"
	.string "Pars avant qu’il ne soit trop tard!$"

MtPyre_2F_Text_LeahDefeat:
	.string "Humm…\n"
	.string "Plutôt coriace!$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Dans ma famille, nous sommes DRESSEURS\n"
	.string "depuis des générations…\p"
	.string "Il est de mon devoir de protéger cette\n"
	.string "montagne…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Aaaaah!\n"
	.string "Je suis terrifié!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Nooon!\n"
	.string "J’ai perdu toute confiance en moi!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "J’ai peur dès que je vois quelque chose\n"
	.string "bouger…\p"
	.string "Je n’aurais pas dû venir m’entraîner\n"
	.string "ici…$"

