LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hé, hoe gaat het, toekomstige\n"
	.string "KAMPIOEN {PLAYER}?\p"
	.string "De GYMLEIDER van LAVARIDGE, FLANNERY,\n"
	.string "gebruikt VUUR-POKéMON.\p"
	.string "Haar liefde voor POKéMON brandt\n"
	.string "heter dan een vulkaan.\p"
	.string "Kom niet te dichtbij, je verbrandt!\n"
	.string "Spuit haar nat met water\l"
	.string "en ga ervoor!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Wauw! Dat was een bloedhete strijd!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Auauauau!\n"
	.string "Wat is het heet!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Het zweet prikt in mijn ogen…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "In heet zand liggen is goed voor\n"
	.string "de bloedsomloop.\p"
	.string "Het helpt tegen pijn in\n"
	.string "je gewrichten.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Ik probeer te ontspannen.\n"
	.string "Kom me niet storen!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Ik hoop dat FLANNERY je roostert!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Pfff…\p"
	.string "Als je te lang in heet zand ligt,\n"
	.string "word je er doodmoe van…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Je bent nu vast moe.\n"
	.string "Je wilt liever in het hete zand\l"
	.string "rusten, hè?\p"
	.string "Maar wilskracht is een belangrijke\n"
	.string "kracht voor alle TRAINERS.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Wie met vuur speelt, verbrandt…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Je bent echt goed…\n"
	.string "Maar onze LEIDER FLANNERY is sterk.\p"
	.string "Pas op, anders verbrand je\n"
	.string "flink.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Kunnen jouw POKéMON\n"
	.string "200 graden hitte aan?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Het was niet heet genoeg…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Magma is 200 graden heet.\p"
	.string "Jouw POKéMON versloegen mij,\n"
	.string "dus ze overleven magma wel.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Eh…\n"
	.string "Oké, ik vecht tegen je.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, je bent te sterk.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Ik word een mooie en sterke\n"
	.string "TRAINER, net als FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Kom op, schiet op!\n"
	.string "Voordat mijn vuur dooft!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Het is zo heet, maar mijn hart\n"
	.string "voelt ijskoud…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Jouw strijdlust brandt zo fel,\n"
	.string "dat je misschien kans maakt\l"
	.string "tegen onze LEIDER.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Zie je hoe de vlammen woest branden?\n"
	.string "Ze vlammen omdat ik ga winnen!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Er ging iets mis.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Nou en? Zeg ik: nou en?\n"
	.string "Ik loop blootsvoets over hete kolen!\p"
	.string "…Probeer dat nooit na!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Ik hou van bergen,\n"
	.string "maar het meest van vulkanen.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Tja, ik verloor zonder ooit\n"
	.string "controle te hebben.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Ik blijf hier omdat ik fan werd\n"
	.string "van de kracht van FLANNERY.\p"
	.string "Hihihihi.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Welkom… Nee, wacht.\p"
	.string "Kleine TRAINER, fijn dat je er\n"
	.string "bent geraakt!\p"
	.string "Mij is toevertrouwd… Nee, wacht.\p"
	.string "Ik ben FLANNERY, en ik ben hier\n"
	.string "de GYMLEIDER!\p"
	.string "Eh…\n"
	.string "Onderschat me niet, ook al ben ik\l"
	.string "maar kort LEIDER!\p"
	.string "Met de kracht van mijn opa laat ik,\n"
	.string "eh… zien hoe heet onze aanvallen zijn\l"
	.string "op deze grond!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "Ik deed misschien te hard mijn best…\p"
	.string "Ik… Ik ben pas net\n"
	.string "GYMLEIDER.\p"
	.string "Ik probeerde iemand te zijn\n"
	.string "die ik niet ben.\p"
	.string "Ik moet het op mijn eigen manier doen.\n"
	.string "Anders raken mijn POKéMON in de war.\p"
	.string "Bedankt dat je me dat leerde.\n"
	.string "Daarom krijg je dit.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} kreeg de HEAT BADGE\n"
	.string "van FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Met een HEAT BADGE luisteren alle\n"
	.string "POKéMON tot level 50 helemaal naar je,\l"
	.string "ook als je ze ruilde.\p"
	.string "En POKéMON kunnen de HM-aanval\n"
	.string "KRACHT buiten gevechten gebruiken.\p"
	.string "Dit is een bedankje van mij.\n"
	.string "Wees niet verlegen en pak het!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "Die TM50 bevat OVERHITTEN.\p"
	.string "Die aanval doet veel schade\n"
	.string "aan de tegenstander.\p"
	.string "Maar hij verlaagt ook flink de\n"
	.string "SP. AANV van de gebruiker.\l"
	.string "Niet zo handig in lange gevechten.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "GYMLEIDER FLANNERY staat nu\n"
	.string "in de POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Jouw kracht doet me aan iemand\n"
	.string "denken…\p"
	.string "Oh! Ik weet het! Je vecht als NORMAN,\n"
	.string "de GYMLEIDER van PETALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "LAVARIDGE TOWN POKéMON GYM$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "LAVARIDGE TOWN POKéMON GYM\p"
	.string "GEKEURDE TRAINERS VAN FLANNERY:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Een gevecht verliezen\n"
	.string "maakt me niet uit het veld.\p"
	.string "Ik hou van POKéMON.\n"
	.string "Ik hou van vechten.\l"
	.string "En… ik hou van deze GYM!\p"
	.string "Laten we weer superhete aanvallen\n"
	.string "uitwisselen!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Pfff!\n"
	.string "Bijna uitgebarsten!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: Ik verloor,\n"
	.string "maar ik ben helemaal tevreden.\p"
	.string "Ik heb niet vaak zo'n heet\n"
	.string "gevecht.\p"
	.string "Laten we nog eens zo vechten!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: Een gevecht verliezen\n"
	.string "maakt me niet uit het veld.\p"
	.string "Ik hou van POKéMON.\n"
	.string "Ik hou van vechten.\l"
	.string "En… ik hou van deze GYM!\p"
	.string "Laten we weer superhete aanvallen\n"
	.string "uitwisselen!\p"
	.string "Oh, wacht. Heb je maar één POKéMON\n"
	.string "die kan vechten?\p"
	.string "Het spijt me, maar neem minimaal\n"
	.string "twee POKéMON mee als je komt.$"
