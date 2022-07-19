.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hum… Ils ont doublé leur clientèle en\n"
	.string "faisant des POKéMON une attraction?\p"
	.string "Je devrais peut-être prendre un\n"
	.string "POKéMON gracieux comme mascotte\l"
	.string "pour notre auberge.\p"
	.string "Je me demande si ça attirera plus\n"
	.string "de monde chez nous.$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, pardon! Désolé!\n"
	.string "J’étais trop absorbé par la télé!\p"
	.string "Depuis que la TEAM AQUA a débarqué en\n"
	.string "ville, les touristes n’approchent plus.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hé, faut pas rester là!\n"
	.string "J’vois pas la télé!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Etonnant! Tu veux dire qu’un POKéMON\n"
	.string "a trouvé un objet perdu par quelqu’un?\p"
	.string "Ça par exemple! Si on avait un POKéMON\n"
	.string "aussi intelligent que ça…\p"
	.string "On pourrait retrouver tout ce que nos\n"
	.string "clients perdent…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, pardon! Désolé!\n"
	.string "J’étais absorbé par la télé!\p"
	.string "J’ai entendu dire que quelqu’un avait\n"
	.string "débusqué la PLANQUE AQUA.\p"
	.string "Grâce à ça, on vient juste de faire une\n"
	.string "réservation pour tout un groupe.\p"
	.string "C’était une entreprise nommée… hum…\n"
	.string "GAME quelque chose…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Etonnant! Un POKéMON de garde a\n"
	.string "attrapé un voleur?\p"
	.string "Ça alors! Si on avait un POKéMON aussi\n"
	.string "robuste pour monter la garde…\p"
	.string "On aimerait pouvoir garantir une\n"
	.string "totale sécurité à notre clientèle.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, pardon! Désolé!\n"
	.string "J’étais absorbé par la télé!\p"
	.string "Oh, oui. Un grand groupe de clients\n"
	.string "est arrivé il y a peu.\p"
	.string "Ils ont réservé sous le nom de GAME\n"
	.string "FREAK. Je suppose qu’ils font des jeux.\p"
	.string "Oh, je ferais mieux de m’occuper\n"
	.string "de leur dîner!$"

