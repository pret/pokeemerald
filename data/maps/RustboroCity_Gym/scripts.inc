RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Hé, hoe gaat het?\p"
	.string "Luister, vriend!\n"
	.string "Wil jij KAMPIOEN worden?\p"
	.string "Ik ben zelf geen TRAINER, maar ik\n"
	.string "kan je wel goede tips geven.\p"
	.string "Afgesproken dan! Samen gaan we voor\n"
	.string "de POKéMON-TITEL!\p"
	.string "Als TRAINER moet je GYM BADGES\n"
	.string "verzamelen, toch?\p"
	.string "Maar GYMLEIDERS zijn niet makkelijk!\p"
	.string "En daarom ben ik er!\n"
	.string "Ik geef je de beste tips!\p"
	.string "ROXANNE, de GYMLEIDER, gebruikt\n"
	.string "STEEN-POKéMON.\p"
	.string "STEEN is heel sterk, maar kan niet\n"
	.string "tegen WATER- en GRAS-\l"
	.string "aanvallen.\p"
	.string "Kom straks bij me terug als je de\n"
	.string "GYMLEIDER hebt verslagen.\p"
	.string "Nou, zet 'm op!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Wauw! Wat een geweldige overwinning!\n"
	.string "Mijn aanmoedigen heeft geholpen!\p"
	.string "Super!\n"
	.string "Kijk eens op je TRAINERKAART.\p"
	.string "De STONE BADGE die je kreeg, staat\n"
	.string "er nu op.\p"
	.string "Met andere woorden…\p"
	.string "Je hebt de eerste stap gezet\n"
	.string "naar de titel!\p"
	.string "Dat voelt vast geweldig!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Onderschat ons GYMTRAINERS niet!\n"
	.string "Ik laat zien waarom we beter zijn!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Jij was te goed voor mij…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Je hebt de enge kracht van STEEN\n"
	.string "nog lang niet gezien!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Als je mij niet kunt verslaan, maak\n"
	.string "je geen kans tegen ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wauw! Jij hebt talent!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE is vele malen sterker\n"
	.string "dan ik.\p"
	.string "Pas maar goed op!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "We zitten midden in de stad,\n"
	.string "nou en?\p"
	.string "Mijn STEEN-POKéMON moeten ruimte\n"
	.string "hebben om te stoeien!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Jeetje, jeetje!\n"
	.string "Deze uitdager is pittig!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Respect voor onze LEIDER.\p"
	.string "Zo jong al, en dan zo slim kiezen\n"
	.string "voor STEEN.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Hallo, ik ben ROXANNE, de GYMLEIDER\n"
	.string "van RUSTBORO.\p"
	.string "Ik werd GYMLEIDER om te gebruiken\n"
	.string "wat ik leerde op de POKéMON\l"
	.string "TRAINER'S SCHOOL.\p"
	.string "Laat je me zien hoe jij vecht,\n"
	.string "en met welke POKéMON?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Dus…\n"
	.string "Ik heb verloren…\p"
	.string "Ik moet blijkbaar nog veel\n"
	.string "leren…\p"
	.string "Ik begrijp het.\p"
	.string "De regels van de POKéMON LEAGUE\n"
	.string "zeggen dat TRAINERS dit krijgen als\l"
	.string "ze een GYMLEIDER verslaan.\p"
	.string "Hier is de officiële STONE BADGE\n"
	.string "van de POKéMON LEAGUE.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} krijgt de STONE BADGE\n"
	.string "van ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "De STONE BADGE maakt de AANVAL\n"
	.string "van je POKéMON sterker.\p"
	.string "Dan kunnen ze ook de HM-aanval\n"
	.string "SNIJDEN buiten gevechten gebruiken.\p"
	.string "Neem dit ook maar mee.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Op die TECHNISCHE MACHINE, TM39,\n"
	.string "staat STEENGRAF.\p"
	.string "Hij doet schade met vallende stenen\n"
	.string "en verlaagt ook de SNELHEID.\p"
	.string "Met een TM leert een POKéMON\n"
	.string "meteen de aanval.\p"
	.string "Een TM kun je maar één keer\n"
	.string "gebruiken, dus denk goed na.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Jij bent zo sterk, daag ook andere\n"
	.string "GYMLEIDERS uit.\p"
	.string "Als je tegen veel TRAINERS vecht,\n"
	.string "leer je heel veel.$"

RustboroCity_Gym_Text_GymStatue:
	.string "RUSTBORO CITY POKéMON GYM$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "RUSTBORO CITY POKéMON GYM\p"
	.string "GOEDGEKEURDE TRAINERS VAN ROXANNE:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Piep!\p"
	.string "ROXANNE: O, hallo, {PLAYER}?\n"
	.string "Met ROXANNE uit RUSTBORO CITY.\p"
	.string "BRAWLY vertelde dat je razendsnel\n"
	.string "een betere TRAINER wordt.\p"
	.string "Nou, ik denk liever niet dat ik\n"
	.string "niet van je kan winnen.\p"
	.string "Ik beloof dat ik mijn GYM sterker\n"
	.string "maak, zodat je ons weer kunt uitdagen.\p"
	.string "Ik hoop dat je daar net zoveel zin\n"
	.string "in hebt als ik!\p"
	.string "… … … … … …\n"
	.string "… … … … … Klik!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "GYMLEIDER ROXANNE staat nu\n"
	.string "in de POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Wat fijn je weer te zien.\n"
	.string "Ik ben ROXANNE, de GYMLEIDER hier.\p"
	.string "We hebben allebei vast veel\n"
	.string "gevochten sinds de vorige keer.\p"
	.string "Ik wil zien hoeveel beter we zijn\n"
	.string "geworden. Laten we vechten!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Weer verloren…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Ik moet nog veel leren\n"
	.string "over vechten met POKéMON.\p"
	.string "Daardoor vind ik vechten\n"
	.string "alleen maar leuker!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Wat fijn je weer te zien.\n"
	.string "Ik ben ROXANNE, de GYMLEIDER hier.\p"
	.string "We hebben allebei vast veel\n"
	.string "gevochten sinds de vorige keer.\p"
	.string "Ik wil zien hoeveel beter we zijn\n"
	.string "geworden…\p"
	.string "O nee…\n"
	.string "Je hebt maar één POKéMON bij je?\p"
	.string "Kom terug met minstens nog één\n"
	.string "POKéMON.$"
