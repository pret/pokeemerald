VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "TIMMY: J’ai perdu contre toi, {PLAYER},\n"
	.string "mais je ne me sens plus déprimé.\p"
	.string "Maintenant, j’ai un nouveau but dans\n"
	.string "la vie. Avec mon TARSAL, je vais\p"
	.string "parcourir les ARENES et devenir un\n"
	.string "grand DRESSEUR.\p"
	.string "Regarde-moi bien, {PLAYER}.\n"
	.string "Je vais devenir plus fort que toi.\p"
	.string "Quand ce sera le cas, je te défierai\n"
	.string "encore une fois.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "TIMMY: Regarde-moi bien, {PLAYER}.\n"
	.string "Je vais devenir plus fort que toi.\p"
	.string "Quand ce sera le cas, je te défierai\n"
	.string "encore une fois.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "TONTON: Oh! {PLAYER}{KUN}!\n"
	.string "TIMMY est juste à côté.\p"
	.string "Mais avant, j’ai quelque chose à te dire.\p"
	.string "Cet environnement naturel fait des\n"
	.string "merveilles sur la santé de TIMMY.\p"
	.string "Mais ce n’est pas seulement\n"
	.string "l’environnement. Les POKéMON lui\l"
	.string "donnent aussi beaucoup d’espoir.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "TIMMY est parti…\n"
	.string "Il suit son propre chemin…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "TONTON: C’est vrai?\n"
	.string "TIMMY est allé aussi loin tout seul…\p"
	.string "Eh bien, il faudra que je le félicite.\n"
	.string "C’est bien le fils de mon frère.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "SYLVIE: Qui es-tu?\n"
	.string "Oh, d’accord, j’y suis!\p"
	.string "Tu es {PLAYER}. TIMMY m’a parlé de toi.\p"
	.string "Je suis la cousine de TIMMY.\n"
	.string "Enchantée de te rencontrer!\p"
	.string "Je crois que TIMMY est bien plus enjoué\n"
	.string "et solide depuis qu’il est arrivé ici.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "SYLVIE: Ne t’inquiète pas pour\n"
	.string "TIMMY. Tout ira bien pour lui.\p"
	.string "Je connais bien mon petit cousin.\n"
	.string "En plus, il a un POKéMON avec lui.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Grâce à toi, je peux voir ma copine\n"
	.string "tous les jours.\p"
	.string "Si je suis content? Bien entendu!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Le petit ami de ma fille est un garçon\n"
	.string "très expansif et passionné.\p"
	.string "Il creuse jour et nuit un tunnel juste\n"
	.string "pour voir ma fille.\p"
	.string "Ma fille est un peu inquiète, donc elle\n"
	.string "va souvent voir si le tunnel est fini.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "Incroyable, le petit ami de ma fille a\n"
	.string "creusé le tunnel de ses propres mains!\p"
	.string "C’est hallucinant!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Si quelque chose arrivait à TIMMY,\n"
	.string "je ne pourrais plus regarder ses\l"
	.string "parents en face…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "TIMMY était à ETERNARA?\p"
	.string "Ses parents, qui sont à CLEMENTI,\n"
	.string "seraient stupéfaits d’entendre ça!$"

