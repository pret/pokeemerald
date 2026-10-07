RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applywaitmovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "O, het is elke dag zo moeilijk…\p"
	.string "Wat er moeilijk is?\n"
	.string "Moet je dat nog vragen?\p"
	.string "Elke dag bedenken wat we\n"
	.string "gaan eten.\p"
	.string "Elke dag iets te eten bedenken is\n"
	.string "echt niet makkelijk.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "O, hallo!\n"
	.string "Welkom bij de familie PEPPER.\p"
	.string "Ik heb een vraag voor je.\n"
	.string "Heb je weleens opgepast?\p"
	.string "Ik ben net vader, dus een kind\n"
	.string "opvoeden is helemaal nieuw voor me.\p"
	.string "En ik heb een probleem. Mijn dochter\n"
	.string "WALDA lacht niet genoeg.\p"
	.string "Als ik iets grappigs zeg, lacht ze\n"
	.string "misschien wel.\p"
	.string "Weet jij een grappig woord of\n"
	.string "zinnetje voor me?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Ik zeg de laatste tijd “{STR_VAR_1}”\n"
	.string "om haar aan het lachen te maken.\p"
	.string "Weet jij een beter woord of\n"
	.string "zinnetje?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "O, geweldig.\n"
	.string "Zeg het maar, wat is je idee?$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "O, is dat zo?\p"
	.string "Nou, als je iets goeds weet,\n"
	.string "hoor ik het graag.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, ik snap het.\n"
	.string "Nou, laten we het proberen.$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "O, ja! Ze lacht!\n"
	.string "O, ik ben net zo blij als zij!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, ik snap het.\n"
	.string "Nou, laten we het proberen.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Ze lacht helemaal niet.\n"
	.string "Misschien is WALDA heel serieus…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "O, dus je weet geen goede woorden.\n"
	.string "Dan bedenk ik zelf wel iets.\p"
	.string "Hmm…\n"
	.string "Wat dacht je van “{STR_VAR_1}”?\l"
	.string "Eens kijken of dat werkt.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmmm… Ze lacht helemaal niet.\n"
	.string "Misschien is WALDA heel serieus…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "O, dus je weet geen goede woorden.\n"
	.string "Dan probeer ik het maar met wat ik\l"
	.string "vroeger zei.\p"
	.string "Maar als je iets goeds weet,\n"
	.string "zeg het me dan gewoon, oké?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Dank je wel!\p"
	.string "Dankzij jou lachte mijn lieve WALDA\n"
	.string "naar me!\p"
	.string "Ik zie er misschien gewoon uit, maar\n"
	.string "ik ben een topper bij DEVON\l"
	.string "CORPORATION.\p"
	.string "Zal ik iets voor je terugdoen?\p"
	.string "Weet je wat? Ik zet nieuwe\n"
	.string "achtergronden in de BOXEN van het\l"
	.string "POKéMON-opslagsysteem op de PC.\p"
	.string "Kies in het achtergrondmenu\n"
	.string "“VRIENDEN”.\p"
	.string "Daar staan dan de nieuwe\n"
	.string "achtergronden.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "Het is een POKéMON-knuffel!$"

