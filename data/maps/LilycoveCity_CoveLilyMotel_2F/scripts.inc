LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Je suis le CONCEPTEUR DE JEU.\p"
	.string "Oh, est-ce que c’est vrai?\n"
	.string "Tu travailles sur un POKéDEX?\p"
	.string "C’est difficile de le compléter, mais\n"
	.string "n’abandonne pas.\p"
	.string "Si tu arrives à le compléter, reviens\n"
	.string "me voir.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Waouh! C’est impressionnant!\n"
	.string "Ouais, carrément impressionnant!\p"
	.string "Ce POKéDEX est totalement rempli!\n"
	.string "Tu dois vraiment aimer les POKéMON!\p"
	.string "Je suis si impressionné!\p"
	.string "Laisse-moi te donner quelque chose\n"
	.string "pour récompenser ton exploit!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Moi? C’est à moi que tu parles?\n"
	.string "Je suis le PROGRAMMEUR.\p"
	.string "Je me demande à quoi ressemblent\n"
	.string "les MACHINES A SOUS ici.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Je suis le GRAPHISTE! Les POKéMON de\n"
	.string "HOENN ne sont-ils pas intéressants?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Les filles FLOTTEURS sont à croquer,\n"
	.string "non? Pour affronter une de ces filles…\p"
	.string "Ouhhh, ça m’rend dingue!\p"
	.string "Et les JUMELLES! Mignonnes, hein? Un\n"
	.string "combat 2 contre 2 avec les JUMELLES…\p"
	.string "Ouhhh, c’est terrible!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "La brise marine emballe mon cœur.\n"
	.string "Quel bonheur d’être ici!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Tu ne peux pas savoir où et quand on\n"
	.string "va te défier.\p"
	.string "C’est pour cela que je ne sors jamais\n"
	.string "sans ma GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Hein?!\p"
	.string "Oh, désolé, j’étais en train de dormir!\p"
	.string "Je suis venu voir ce qui se passe dans\n"
	.string "ces CONCOURS POKéMON.\p"
	.string "Je dois admettre que c’est plutôt\n"
	.string "divertissant, mais…\p"
	.string "En tant que puriste, je préfère les\n"
	.string "combats dangereux.\p"
	.string "Mais ce n’est que mon avis. \p"
	.string "{PLAYER}{KUN}, j’espère que tu vas profiter\n"
	.string "de tout: les ARENES, les CONCOURS,\l"
	.string "les TENTES DE COMBAT, tout!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: Il faut beaucoup de stratégie\n"
	.string "pour remporter un CONCOURS.\p"
	.string "Parler des stratégies des CONCOURS\n"
	.string "est, à mon avis, une façon de devenir\l"
	.string "un bon DRESSEUR.$"

