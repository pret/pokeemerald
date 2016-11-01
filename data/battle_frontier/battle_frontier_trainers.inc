	.align 2
gBattleFrontierTrainers:: @ 85D5ACC
@ 0
	.4byte TRAINER_CLASS_YOUNGSTER
	.string "BRADY$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word NEVER
	ec_word GOING
	ec_word TO
	ec_word LOSE
	ec_word EXCL
@ win speech
	ec_word I_AM
	ec_word STRONG
	ec_word AREN_T
	ec_word I
	ec_word QUES
	.2byte -1
@ loss speech
	ec_word WHAT
	ec_word QUES
	.2byte -1
	ec_word BUT
	ec_word HOW
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Brady

@ 1
	.4byte TRAINER_CLASS_YOUNGSTER
	.string "CONNER$", 8
@ pre-battle speech
	ec_word LOSING
	ec_word DOESN_T
	ec_word BUG
	ec_word ME
	.2byte -1
	.2byte -1
@ win speech
	ec_word A
	ec_word WIN
	ec_word IS
	ec_word JUST
	ec_word AWESOME
	.2byte -1
@ loss speech
	ec_word DARN
	ec_word ELLIPSIS
	ec_word LOSING
	ec_word DOES
	ec_word BUG
	ec_word ME
	.4byte gBattleFrontierTrainerMons_Conner

@ 2
	.4byte TRAINER_CLASS_YOUNGSTER
	.string "BRADLEY$", 8
@ pre-battle speech
	ec_word HEY_THERE
	ec_word EXCL
	ec_word YOU_RE
	ec_word MY
	ec_word OPPONENT
	ec_word TODAY
@ win speech
	ec_word HAHAHA
	ec_word EXCL
	.2byte -1
	ec_word SEE_YA
	ec_word LATER
	ec_word EXCL
@ loss speech
	ec_word TOMORROW
	ec_word IS
	ec_word WHEN
	ec_word WE
	ec_word REALLY
	ec_word BATTLE
	.4byte gBattleFrontierTrainerMons_Bradley

@ 3
	.4byte TRAINER_CLASS_LASS
	.string "CYBIL$", 8
@ pre-battle speech
	ec_word YOU_RE
	ec_word REALLY
	ec_word NOT_VERY
	ec_word SCARY
	ec_word AT
	ec_word ALL
@ win speech
	ec_word IT_S
	ec_word SAD
	ec_word TO
	ec_word SEE
	ec_word YOU
	ec_move2 STRUGGLE
@ loss speech
	ec_word THIS
	ec_word CAN_T
	ec_word BE
	ec_word HAPPENING
	ec_word TO_ME
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Cybil

@ 4
	.4byte TRAINER_CLASS_LASS
	.string "RODETTE$", 8
@ pre-battle speech
	ec_word OH
	ec_word THIS
	ec_word IS
	ec_word SO
	ec_word EXCITING
	ec_word EXCL
@ win speech
	ec_word IT_S
	ec_word INCREDIBLE
	ec_word HOW
	ec_word STRONG
	ec_word I_AM
	ec_word EXCL
@ loss speech
	ec_word OH_DEAR
	ec_word ELLIPSIS
	ec_word I_AM
	ec_word JUST
	ec_word NO
	ec_word GOOD
	.4byte gBattleFrontierTrainerMons_Rodette

@ 5
	.4byte TRAINER_CLASS_LASS
	.string "PEGGY$", 8
@ pre-battle speech
	ec_word GET
	ec_word READY
	ec_word TO
	ec_word BE
	ec_word DESTROYED
	ec_word EXCL
@ win speech
	ec_word HAHAHA
	ec_word EXCL_EXCL
	.2byte -1
	ec_word I_AM
	ec_word LOLLING
	ec_word EXCL
@ loss speech
	ec_word I_AM
	ec_word FEELING
	ec_word SAD
	ec_word THANKS
	ec_word TO
	ec_word YOU
	.4byte gBattleFrontierTrainerMons_Peggy

@ 6
	.4byte TRAINER_CLASS_SCHOOL_KID_1
	.string "KEITH$", 8
@ pre-battle speech
	ec_word I
	ec_word DON_T
	ec_word JUST
	ec_word STUDY
	ec_word YOU
	ec_word KNOW
@ win speech
	ec_word YOU
	ec_word DON_T
	ec_word STUDY
	ec_word ENOUGH
	ec_word ELLIPSIS
	.2byte -1
@ loss speech
	ec_word I
	ec_word NEED
	ec_word TO
	ec_word STUDY
	ec_word MORE
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Keith

@ 7
	.4byte TRAINER_CLASS_SCHOOL_KID_1
	.string "GRAYSON$", 8
@ pre-battle speech
	ec_word A
	ec_word POKEMON
	ec_word BATTLE
	ec_word ISN_T
	ec_word CHILD_S_PLAY
	ec_word EXCL
@ win speech
	ec_word YOU_RE
	ec_word DONE
	ec_word AREN_T
	ec_word YOU
	ec_word QUES
	.2byte -1
@ loss speech
	ec_word WE
	ec_word WERE
	ec_word LIKE
	ec_word TOYS
	ec_word TO
	ec_word YOU
	.4byte gBattleFrontierTrainerMons_Grayson

@ 8
	.4byte TRAINER_CLASS_SCHOOL_KID_1
	.string "GLENN$", 8
@ pre-battle speech
	ec_word I
	ec_word WOULD
	ec_word BE
	ec_word COOL
	ec_word IF_I_WIN
	.2byte -1
@ win speech
	ec_word COOL
	ec_word EXCL
	.2byte -1
	ec_word THAT_S
	ec_word WHAT
	ec_word I_AM
@ loss speech
	ec_word I_AM
	ec_word NOT
	ec_word GOING
	ec_word TO
	ec_word BE
	ec_word COOL
	.4byte gBattleFrontierTrainerMons_Glenn

@ 9
	.4byte TRAINER_CLASS_SCHOOL_KID_2
	.string "LILIANA$", 8
@ pre-battle speech
	ec_word I
	ec_word WON_T
	ec_word GIVE_UP
	ec_word UNTIL
	ec_word I
	ec_word WIN
@ win speech
	ec_word THERE
	ec_word IS
	ec_word NO
	ec_word SURRENDER
	ec_word IN
	ec_word ME
@ loss speech
	ec_word THAT_S
	ec_word IT
	ec_word ELLIPSIS
	ec_word I
	ec_word GIVE_UP
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Liliana

@ 10
	.4byte TRAINER_CLASS_SCHOOL_KID_2
	.string "ELISE$", 8
@ pre-battle speech
	ec_word MY
	ec_word STRATEGY
	ec_word IS
	ec_word FROM
	ec_word MY
	ec_word FATHER
@ win speech
	ec_word I
	ec_word WIN
	ec_word EXCL
	ec_word FATHER
	ec_word I_VE
	ec_word WON
@ loss speech
	ec_word FORGIVE
	ec_word ME
	ec_word FATHER
	ec_word FOR
	ec_word I_VE
	ec_word LOST
	.4byte gBattleFrontierTrainerMons_Elise

@ 11
	.4byte TRAINER_CLASS_SCHOOL_KID_2
	.string "ZOEY$", 8
@ pre-battle speech
	ec_word PLEASE
	ec_word BATTLE
	ec_word LIKE
	ec_word YOU
	ec_word MEAN
	ec_word IT
@ win speech
	ec_word THANK_YOU
	ec_word EXCL_EXCL
	.2byte -1
	ec_word THANK_YOU
	ec_word SO
	ec_word MUCH
@ loss speech
	ec_word WERE
	ec_word YOU
	ec_word REALLY
	ec_word BEING
	ec_word SERIOUS
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Zoey

@ 12
	.4byte TRAINER_CLASS_RICH_BOY
	.string "MANUEL$", 8
@ pre-battle speech
	ec_word ME
	ec_word LOSE
	ec_word QUES
	ec_word THAT_S
	ec_word PREPOSTEROUS
	ec_word EXCL
@ win speech
	ec_word NATURALLY
	ec_word I
	ec_word WIN
	.2byte -1
	.2byte -1
	.2byte -1
@ loss speech
	ec_word WAAAH
	ec_word EXCL
	.2byte -1
	ec_word I
	ec_word LOST
	ec_word MOTHER
	.4byte gBattleFrontierTrainerMons_Manuel

@ 13
	.4byte TRAINER_CLASS_RICH_BOY
	.string "RUSS$", 8
@ pre-battle speech
	ec_word THEY
	ec_word ALL
	ec_word WANT
	ec_word MY
	ec_word FABULOUS
	ec_word POKEMON
@ win speech
	ec_word I
	ec_word WILL
	ec_word HAVE
	ec_word A
	ec_word POKEMON
	ec_word PARTY
@ loss speech
	ec_word HOW
	ec_word COULD
	ec_word YOU
	ec_word DO
	ec_word THAT
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Russ

@ 14
	.4byte TRAINER_CLASS_RICH_BOY
	.string "DUSTIN$", 8
@ pre-battle speech
	ec_word I
	ec_word REALLY
	ec_word LIKE
	ec_word COOL
	ec_word POKEMON
	.2byte -1
@ win speech
	ec_word I
	ec_word LIKE
	ec_word MYSELF
	ec_word WHEN_I_WIN
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word I
	ec_word LIKE
	ec_word MYSELF
	ec_word IF_I_LOSE
	ec_word TOO
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Dustin

@ 15
	.4byte TRAINER_CLASS_LADY
	.string "TINA$", 8
@ pre-battle speech
	ec_word IF_I_WIN
	ec_word YOU
	ec_word CAN
	ec_word HAVE
	ec_word A
	ec_move2 SWEET_KISS
@ win speech
	ec_word HERE_IT_IS
	ec_word YOUR
	ec_move2 SWEET_KISS
	ec_word FROM
	ec_word MY
	ec_pokemon2 JYNX
@ loss speech
	ec_word YOU
	ec_word WANT
	ec_word A
	ec_move1 SWIFT
	ec_move2 MEGA_KICK
	ec_word INSTEAD
	.4byte gBattleFrontierTrainerMons_Tina

@ 16
	.4byte TRAINER_CLASS_LADY
	.string "GILLIAN$", 8
@ pre-battle speech
	ec_word THE
	ec_word GOURMET
	ec_word THING
	ec_word IS
	ec_word SO
	ec_word YESTERDAY
@ win speech
	ec_word POKEMON
	ec_word NEVER
	ec_word GO
	ec_word OUT
	ec_word OF
	ec_word FASHION
@ loss speech
	ec_word LOSING
	ec_word DOESN_T
	ec_word DISAPPOINT
	ec_word ME
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Gillian

@ 17
	.4byte TRAINER_CLASS_LADY
	.string "ZOE$", 8
@ pre-battle speech
	ec_word I
	ec_word HAVEN_T
	ec_word A
	ec_word WORRY
	ec_word AT
	ec_word ALL
@ win speech
	ec_word LIFE
	ec_word IS
	ec_word ALWAYS
	ec_word GOOD
	ec_word TO_ME
	.2byte -1
@ loss speech
	ec_word I
	ec_word WORRY
	ec_word ABOUT
	ec_word MY
	ec_word POKEMON
	ec_word SKILL
	.4byte gBattleFrontierTrainerMons_Zoe

@ 18
	.4byte TRAINER_CLASS_CAMPER
	.string "CHEN$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word TOTALLY
	ec_word READY
	ec_word TO
	ec_word ROCK
	ec_word TODAY
@ win speech
	ec_word I_AM
	ec_word READY
	ec_word TO
	ec_word GO
	ec_word ON
	ec_word EXCL
@ loss speech
	ec_word I_VE
	ec_word LOST
	ec_word MY
	ec_move1 FOCUS_ENERGY
	ec_word AND
	ec_word TOUGHNESS
	.4byte gBattleFrontierTrainerMons_Chen

@ 19
	.4byte TRAINER_CLASS_CAMPER
	.string "AL$", 8
@ pre-battle speech
	ec_word YOUR
	ec_word LOOK
	ec_word SAYS
	ec_word YOU_RE
	ec_word REALLY
	ec_word TOUGH
@ win speech
	ec_word IT_S
	ec_word ME
	ec_word WHO_IS
	ec_word REALLY
	ec_word TOUGH
	.2byte -1
@ loss speech
	ec_word I_AM
	ec_word RIGHT
	ec_word EXCL
	ec_word YOU_RE
	ec_word REALLY
	ec_word TOUGH
	.4byte gBattleFrontierTrainerMons_Al

@ 20
	.4byte TRAINER_CLASS_CAMPER
	.string "MITCH$", 8
@ pre-battle speech
	ec_word MOTHER
	ec_word NATURE
	ec_word IS
	ec_word MY
	ec_word ALLY
	ec_word EXCL
@ win speech
	ec_word WAS
	ec_word THAT
	ec_word ENOUGH
	ec_word FOR
	ec_word YOU
	ec_word QUES
@ loss speech
	ec_word MOTHER
	ec_word NATURE
	ec_word DIDN_T
	ec_word LET_ME_WIN
	ec_word QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Mitch

@ 21
	.4byte TRAINER_CLASS_PICNICKER
	.string "ANNE$", 8
@ pre-battle speech
	ec_word I
	ec_word CAN_T
	ec_word WAIT
	ec_word LET_S
	ec_word BATTLE
	ec_word NOW
@ win speech
	ec_word MY
	ec_word HAPPINESS
	ec_word IS
	ec_word OVERWHELMING
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word YOU_VE
	ec_word DESTROYED
	ec_word MY
	ec_word HAPPINESS
	ec_word ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Anne

@ 22
	.4byte TRAINER_CLASS_PICNICKER
	.string "ALIZE$", 8
@ pre-battle speech
	ec_word CUTE
	ec_word AND
	ec_word AWFULLY
	ec_word STRONG
	ec_word THAT_S
	ec_word ME
@ win speech
	ec_word YUP
	ec_word I_AM
	ec_word CUTE
	ec_word AND
	ec_word AWFULLY
	ec_word STRONG
@ loss speech
	ec_word I_AM
	ec_word WEAK
	ec_word ELLIPSIS
	ec_word BUT
	ec_word I_AM
	ec_word CUTE
	.4byte gBattleFrontierTrainerMons_Alize

@ 23
	.4byte TRAINER_CLASS_PICNICKER
	.string "LAUREN$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word OLD
	ec_word BUT
	ec_word I_AM
	ec_word ALSO
	ec_word GOOD
@ win speech
	ec_word I
	ec_word SAID
	ec_word I_WAS
	ec_word OLD
	ec_word BUT
	ec_word GOOD
@ loss speech
	ec_word WHAT
	ec_word A
	ec_word WEIRD
	ec_word DREAM
	ec_word THAT_WAS
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Lauren

@ 24
	.4byte TRAINER_CLASS_TUBER_2
	.string "KIPP$", 8
@ pre-battle speech
	ec_word IF_I_WIN
	ec_word I_AM
	ec_word GOING
	ec_word TO
	ec_word GO
	ec_move2 SURF
@ win speech
	ec_word YEAH
	ec_word EXCL
	ec_word I_AM
	ec_word OFF
	ec_word TO
	ec_move2 SURF
@ loss speech
	ec_word OH
	ec_word NO
	ec_word EXCL
	ec_word A
	ec_move1 WHIRLPOOL
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Kipp

@ 25
	.4byte TRAINER_CLASS_TUBER_2
	.string "JASON$", 8
@ pre-battle speech
	ec_word TEACH
	ec_word ME
	ec_word A
	ec_word GOOD
	ec_word STRATEGY
	.2byte -1
@ win speech
	ec_word THAT_WAS
	ec_word YOUR
	ec_word GOOD
	ec_word STRATEGY
	ec_word QUES_EXCL
	.2byte -1
@ loss speech
	ec_word WOW
	ec_word THAT
	ec_word IS
	ec_word AN
	ec_word AWESOME
	ec_word STRATEGY
	.4byte gBattleFrontierTrainerMons_Jason

@ 26
	.4byte TRAINER_CLASS_TUBER_2
	.string "JOHN$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word A
	ec_word PRETTY
	ec_word NEW
	ec_word TRAINER
	.2byte -1
@ win speech
	ec_word I_AM
	ec_word NEW
	ec_word BUT
	ec_word I
	ec_word WON
	ec_word EXCL
@ loss speech
	ec_word I_AM
	ec_word NEW
	ec_word SO
	ec_word WHAT
	ec_word IF_I_LOSE
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_John

@ 27
	.4byte TRAINER_CLASS_TUBER_1
	.string "ANN$", 8
@ pre-battle speech
	ec_word IT_S
	ec_word SO
	ec_word EXCITING
	ec_word IT
	ec_word REALLY
	ec_word IS
@ win speech
	ec_word I_AM
	ec_word SO
	ec_word HAPPY
	ec_word I
	ec_word CAN
	ec_word CRY
@ loss speech
	ec_word I_AM
	ec_word SO
	ec_word SAD
	ec_word I
	ec_word WILL
	ec_word CRY
	.4byte gBattleFrontierTrainerMons_Ann

@ 28
	.4byte TRAINER_CLASS_TUBER_1
	.string "EILEEN$", 8
@ pre-battle speech
	ec_word LET_S
	ec_word PRETEND
	ec_word I_AM
	ec_word AN
	ec_word ADULT
	ec_word OK_QUES
@ win speech
	ec_word SO
	ec_word THIS
	ec_word IS
	ec_word AN
	ec_word ADULT
	ec_word FEELING
@ loss speech
	ec_word AN
	ec_word ADULT
	ec_word CAN_T
	ec_word BEAT
	ec_word YOU
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Eileen

@ 29
	.4byte TRAINER_CLASS_TUBER_1
	.string "CARLIE$", 8
@ pre-battle speech
	ec_word MY
	ec_word SUMMER
	ec_word VACATION
	ec_word IS
	ec_word FOR
	ec_word POKEMON
@ win speech
	ec_word MY
	ec_word SUMMER
	ec_word VACATION
	ec_word WILL
	ec_word BE
	ec_word AWESOME
@ loss speech
	ec_word I
	ec_word CAN_T_WIN
	ec_word LIKE
	ec_word THIS
	ec_word ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Carlie

@ 30
	.4byte TRAINER_CLASS_SWIMMER_M
	.string "GORDON$", 8
@ pre-battle speech
	ec_word VICTORY
	ec_word WILL
	ec_word COME
	ec_word TO_ME
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word OH_YEAH
	ec_word EXCL
	.2byte -1
	ec_word I
	ec_word REALLY
	ec_word WON
@ loss speech
	ec_word NOTHING
	ec_word IS
	ec_word WORKING
	ec_word OUT
	ec_word FOR
	ec_word ME
	.4byte gBattleFrontierTrainerMons_Gordon

@ 31
	.4byte TRAINER_CLASS_SWIMMER_M
	.string "AYDEN$", 8
@ pre-battle speech
	ec_word COME_ON
	ec_word I
	ec_word NEED
	ec_word A
	ec_word HOT
	ec_word BATTLE
@ win speech
	ec_word I
	ec_word NEED
	ec_word WATER
	ec_word TO
	ec_word COOL
	ec_word DOWN
@ loss speech
	ec_word YOU
	ec_word HAVE
	ec_word ME
	ec_word FEELING
	ec_word ICE
	ec_word COLD
	.4byte gBattleFrontierTrainerMons_Ayden

@ 32
	.4byte TRAINER_CLASS_SWIMMER_M
	.string "MARCO$", 8
@ pre-battle speech
	ec_word I
	ec_move2 SURF
	ec_word IN
	ec_word THE
	ec_word WINTER
	ec_word TOO
@ win speech
	ec_word I
	ec_word WILL
	ec_word GO
	ec_move2 SURF
	ec_word RIGHT
	ec_word NOW
@ loss speech
	ec_word I
	ec_word WILL
	ec_move2 BEAT_UP
	ec_word MY
	ec_move2 SURF
	ec_word BOARD
	.4byte gBattleFrontierTrainerMons_Marco

@ 33
	.4byte TRAINER_CLASS_SWIMMER_F
	.string "CIERRA$", 8
@ pre-battle speech
	ec_word I
	ec_word LIKE
	ec_word TO
	ec_word SYNCHRONIZE
	ec_word MY
	ec_word SWIFT_SWIM
@ win speech
	ec_word MY
	ec_word POKEMON
	ec_word SYNCHRONIZE
	ec_word WITH
	ec_word ME
	.2byte -1
@ loss speech
	ec_word I
	ec_word NEED
	ec_word TO
	ec_word SYNCHRONIZE
	ec_word BETTER
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Cierra

@ 34
	.4byte TRAINER_CLASS_SWIMMER_F
	.string "MARCY$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word A
	ec_word KNOCKOUT
	ec_word YOU
	ec_word CAN_T_WIN
	ec_word EXCL
@ win speech
	ec_word AFTER
	ec_word ALL
	ec_word I_AM
	ec_word A
	ec_word KNOCKOUT
	ec_word EXCL
@ loss speech
	ec_word THAT_S
	ec_word NOT
	ec_word THE
	ec_word KNOCKOUT
	ec_word I
	ec_word MEAN
	.4byte gBattleFrontierTrainerMons_Marcy

@ 35
	.4byte TRAINER_CLASS_SWIMMER_F
	.string "KATHY$", 8
@ pre-battle speech
	ec_word I_VE
	ec_word WON
	ec_word EVERY
	ec_word MATCH
	ec_word TODAY
	ec_word EXCL
@ win speech
	ec_word IT_S
	ec_word SO
	ec_word GREAT
	ec_word TO
	ec_word WIN
	ec_word EXCL
@ loss speech
	ec_word HUH_QUES
	ec_word I
	ec_word SHOULD
	ec_word NOT
	ec_word HAVE
	ec_word LOST
	.4byte gBattleFrontierTrainerMons_Kathy

@ 36
	.4byte TRAINER_CLASS_POKEFAN_1
	.string "PEYTON$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word NEVER
	ec_word DISAPPOINTED
	ec_word WITH
	ec_word MY
	ec_word POKEMON
@ win speech
	ec_word I_AM
	ec_word HAPPY
	ec_word IF
	ec_word WE
	ec_word WIN
	ec_word TOGETHER
@ loss speech
	ec_word I
	ec_word ADORE
	ec_word MY
	ec_word POKEMON
	ec_word MORE
	ec_word IF_I_LOSE
	.4byte gBattleFrontierTrainerMons_Peyton

@ 37
	.4byte TRAINER_CLASS_POKEFAN_1
	.string "JULIAN$", 8
@ pre-battle speech
	ec_word YOU
	ec_word ADORE
	ec_word YOUR
	ec_word POKEMON
	ec_word RIGHT
	ec_word QUES
@ win speech
	ec_word YOU_RE
	ec_word TOTALLY
	ec_word OUT
	ec_word OF
	ec_word THE
	ec_word QUESTION
@ loss speech
	ec_word YOU
	ec_word DO
	ec_word ADORE
	ec_word YOUR
	ec_word POKEMON
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Julian

@ 38
	.4byte TRAINER_CLASS_POKEFAN_1
	.string "QUINN$", 8
@ pre-battle speech
	ec_word MY
	ec_word POKEMON
	ec_word ARE
	ec_word BUT
	ec_word A
	ec_word DREAM
@ win speech
	ec_word THIS
	ec_word IS
	ec_word A
	ec_word BEAUTIFUL
	ec_word DREAM
	ec_word EXCL
@ loss speech
	ec_word THIS
	ec_word IS
	ec_word AN
	ec_word AWFUL
	ec_move1 NIGHTMARE
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Quinn

@ 39
	.4byte TRAINER_CLASS_POKEFAN_2
	.string "HAYLEE$", 8
@ pre-battle speech
	ec_word I
	ec_word DON_T
	ec_word KNOW
	ec_word HOW
	ec_word I_AM
	ec_word FEELING
@ win speech
	ec_word I_AM
	ec_word FEELING
	ec_word OVERWHELMING
	ec_word JOY
	ec_word OVER
	ec_word THIS
@ loss speech
	ec_word DESTROYED
	ec_word IS
	ec_word THE
	ec_word WAY
	ec_word I_AM
	ec_word FEELING
	.4byte gBattleFrontierTrainerMons_Haylee

@ 40
	.4byte TRAINER_CLASS_POKEFAN_2
	.string "AMANDA$", 8
@ pre-battle speech
	ec_word I
	ec_word COME
	ec_word FROM
	ec_word A
	ec_word TRAINER
	ec_word FAMILY
@ win speech
	ec_word I
	ec_word WILL
	ec_word TREASURE
	ec_word THIS
	ec_word WIN
	.2byte -1
@ loss speech
	ec_word I
	ec_word WANT
	ec_word TO
	ec_word GO_HOME
	ec_word RIGHT
	ec_word NOW
	.4byte gBattleFrontierTrainerMons_Amanda

@ 41
	.4byte TRAINER_CLASS_POKEFAN_2
	.string "STACY$", 8
@ pre-battle speech
	ec_word ALL
	ec_word POKEMON
	ec_word HAVE
	ec_word THEIR
	ec_word OWN
	ec_word CUTE_CHARM
@ win speech
	ec_word YOU
	ec_word SEE
	ec_word WHAT
	ec_word I
	ec_word MEAN
	ec_word QUES
@ loss speech
	ec_word SHOULD
	ec_word I
	ec_word NOT
	ec_word ADORE
	ec_word POKEMON
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Stacy

@ 42
	.4byte TRAINER_CLASS_PKMN_BREEDER_2
	.string "RAFAEL$", 8
@ pre-battle speech
	ec_word COME_ON
	ec_word EXCL
	ec_word LET_S
	ec_word SEE
	ec_word SOME
	ec_word SPIRIT
@ win speech
	ec_word THAT_S_IT_EXCL
	ec_word THAT_S
	ec_word THE
	ec_word SPIRIT
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word WELL
	ec_word SO
	ec_word MUCH
	ec_word FOR
	ec_word OUR
	ec_word SPIRIT
	.4byte gBattleFrontierTrainerMons_Rafael

@ 43
	.4byte TRAINER_CLASS_PKMN_BREEDER_2
	.string "OLIVER$", 8
@ pre-battle speech
	ec_word A
	ec_word GENIUS
	ec_word THAT_S
	ec_word WHAT
	ec_word I_AM
	ec_word EXCL
@ win speech
	ec_word THAT_S
	ec_word HOW
	ec_word A
	ec_word GENIUS
	ec_word WORKS
	ec_word EXCL
@ loss speech
	ec_word YOU_RE
	ec_word MORE
	ec_word A
	ec_word GENIUS
	ec_word THAN
	ec_word I_AM
	.4byte gBattleFrontierTrainerMons_Oliver

@ 44
	.4byte TRAINER_CLASS_PKMN_BREEDER_2
	.string "PAYTON$", 8
@ pre-battle speech
	ec_word I
	ec_word TRAIN
	ec_word FROM
	ec_word THE
	ec_word EGG
	ec_word UP
@ win speech
	ec_word WELL
	ec_word DONE
	ec_word EXCL
	.2byte -1
	.2byte -1
	.2byte -1
@ loss speech
	ec_word THAT_WAS
	ec_word A
	ec_move2 SOFT_BOILED
	ec_word LOSS
	ec_word ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Payton

@ 45
	.4byte TRAINER_CLASS_PKMN_BREEDER_1
	.string "PAMELA$", 8
@ pre-battle speech
	ec_word ALL
	ec_word POKEMON
	ec_word ADORE
	ec_word A
	ec_word KIND
	ec_word TRAINER
@ win speech
	ec_word IT_S
	ec_word TOO
	ec_word BAD
	ec_word YOU
	ec_word LOST
	.2byte -1
@ loss speech
	ec_word YOU_RE
	ec_word KIND
	ec_word AND
	ec_word YOU_RE
	ec_word ALSO
	ec_word STRONG
	.4byte gBattleFrontierTrainerMons_Pamela

@ 46
	.4byte TRAINER_CLASS_PKMN_BREEDER_1
	.string "ELIZA$", 8
@ pre-battle speech
	ec_word I
	ec_word ADORE
	ec_word POKEMON
	ec_word LIKE
	ec_word MY
	ec_word CHILDREN
@ win speech
	ec_word I_AM
	ec_word SO
	ec_word HAPPY
	ec_word FOR
	ec_word MY
	ec_word POKEMON
@ loss speech
	ec_word OH_DEAR
	ec_word I_AM
	ec_word SO
	ec_word SORRY
	ec_word ABOUT
	ec_word THIS
	.4byte gBattleFrontierTrainerMons_Eliza

@ 47
	.4byte TRAINER_CLASS_PKMN_BREEDER_1
	.string "MARISA$", 8
@ pre-battle speech
	ec_word I
	ec_word PROMISE
	ec_word TO
	ec_word BATTLE
	ec_word SERIOUSLY
	.2byte -1
@ win speech
	ec_word PROMISE
	ec_word ME
	ec_word YOU
	ec_word WILL
	ec_word DO
	ec_word BETTER
@ loss speech
	ec_word PROMISE
	ec_word ME
	ec_word ANOTHER
	ec_word BATTLE
	ec_word PLEASE
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Marisa

@ 48
	.4byte TRAINER_CLASS_BUG_CATCHER
	.string "LEWIS$", 8
@ pre-battle speech
	ec_word A_LITTLE
	ec_word BUG
	ec_word IS
	ec_word SCARY
	ec_word QUES
	ec_word HAHAHA
@ win speech
	ec_word LOOK
	ec_word LOOK
	ec_word EXCL
	ec_word A
	ec_word SCARY
	ec_word BUG
@ loss speech
	ec_word OH
	ec_word A
	ec_word BUG
	ec_word ISN_T
	ec_word SCARY
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Lewis

@ 49
	.4byte TRAINER_CLASS_BUG_CATCHER
	.string "YOSHI$", 8
@ pre-battle speech
	ec_word BUG
	ec_word POKEMON
	ec_word MAKE
	ec_word ME
	ec_word FEELING
	ec_word LOVEY_DOVEY
@ win speech
	ec_word BUG
	ec_word POKEMON
	ec_word ARE
	ec_word THE
	ec_word BEST
	ec_word EXCL
@ loss speech
	ec_word YOU_RE
	ec_word IGNORANT
	ec_word ABOUT
	ec_word BUG
	ec_word POKEMON
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Yoshi

@ 50
	.4byte TRAINER_CLASS_BUG_CATCHER
	.string "DESTIN$", 8
@ pre-battle speech
	ec_word IT_S
	ec_word WAY
	ec_word TOO
	ec_word HOT
	ec_word HERE
	.2byte -1
@ win speech
	ec_word I_AM
	ec_word ABOUT
	ec_word TO
	ec_move1 OVERHEAT
	.2byte -1
	.2byte -1
@ loss speech
	ec_word PLEASE
	ec_word I
	ec_word NEED
	ec_word SOME
	ec_word WATER
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Destin

@ 51
	.4byte TRAINER_CLASS_NINJA_BOY
	.string "KEON$", 8
@ pre-battle speech
	ec_word FORGIVE
	ec_word ME
	ec_word BUT
	ec_word HERE_I_COME
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word FORGIVE
	ec_word ME
	ec_word FOR
	ec_word MY
	ec_word OVERWHELMING
	ec_word POWER
@ loss speech
	ec_word I_AM
	ec_word SORRY
	ec_word ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Keon

@ 52
	.4byte TRAINER_CLASS_NINJA_BOY
	.string "STUART$", 8
@ pre-battle speech
	ec_word I
	ec_word PROMISE
	ec_word YOU
	ec_word A
	ec_word HOT
	ec_word BATTLE
@ win speech
	ec_word THE
	ec_word MASTER
	ec_word OF
	ec_word COOL
	ec_word THAT_S
	ec_word ME
@ loss speech
	ec_word I
	ec_word SEE
	ec_word I_AM
	ec_word NOT
	ec_word SO
	ec_word COOL
	.4byte gBattleFrontierTrainerMons_Stuart

@ 53
	.4byte TRAINER_CLASS_NINJA_BOY
	.string "NESTOR$", 8
@ pre-battle speech
	ec_word SHOW
	ec_word ME
	ec_word A
	ec_word REALLY
	ec_word SMOOTH
	ec_word MOVE
@ win speech
	ec_word THERE
	ec_word WAS
	ec_word NOTHING
	ec_word SMOOTH
	ec_word ABOUT
	ec_word THAT
@ loss speech
	ec_word YOU
	ec_word REALLY
	ec_word ARE
	ec_word SMOOTH
	ec_word EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Nestor

@ 54
	.4byte TRAINER_CLASS_BUG_MANIAC
	.string "DERRICK$", 8
@ pre-battle speech
	ec_word LET_S
	ec_word SEE
	ec_word YOU
	ec_move2 MEDITATE
	ec_word LIKE
	ec_word ME
@ win speech
	ec_word HOW
	ec_word I
	ec_move2 MEDITATE
	ec_word IS
	ec_word JUST
	ec_word BEAUTIFUL
@ loss speech
	ec_word I
	ec_word WILL
	ec_move2 MEDITATE
	ec_word FOR
	ec_word A
	ec_move2 CALM_MIND
	.4byte gBattleFrontierTrainerMons_Derrick

@ 55
	.4byte TRAINER_CLASS_BUG_MANIAC
	.string "BRYSON$", 8
@ pre-battle speech
	ec_move2 POISON_POWDER
	ec_word IS
	ec_word IN
	ec_word OUR
	ec_move2 COTTON_SPORE
	ec_word MOVE
@ win speech
	ec_word HOW_DO
	ec_word YOU
	ec_word LIKE
	ec_word OUR
	ec_move2 POISON_POWDER
	ec_word QUES
@ loss speech
	ec_word MY
	ec_move2 COTTON_SPORE
	ec_word WAS
	ec_word USELESS
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Bryson

@ 56
	.4byte TRAINER_CLASS_BUG_MANIAC
	.string "CLAYTON$", 8
@ pre-battle speech
	ec_word HUH_QUES
	.2byte -1
	.2byte -1
	ec_word WHERE
	ec_word IS_IT_QUES
	.2byte -1
@ win speech
	ec_word WHERE
	ec_word IS_IT_QUES
	ec_word I_VE
	ec_word LOST
	ec_word MY
	ec_word POKENAV
@ loss speech
	ec_word WHERE
	ec_word IS_IT_QUES
	ec_word I_VE
	ec_word LOST
	ec_word MY
	ec_word SENSE
	.4byte gBattleFrontierTrainerMons_Clayton

@ 57
	.4byte TRAINER_CLASS_FISHERMAN
	.string "TRENTON$", 8
@ pre-battle speech
	ec_word COME_OVER
	ec_word FOR
	ec_word SOME
	ec_word TASTY
	ec_word WATER
	.2byte -1
@ win speech
	ec_word MMM
	ec_word DO
	ec_word YOU
	ec_word WANT
	ec_word SOME
	ec_word QUES
@ loss speech
	ec_word I
	ec_word GOT
	ec_word THIS
	ec_word TASTY
	ec_word WATER
	ec_word SHOPPING
	.4byte gBattleFrontierTrainerMons_Trenton

@ 58
	.4byte TRAINER_CLASS_FISHERMAN
	.string "JENSON$", 8
@ pre-battle speech
	ec_word MY
	ec_word POKEMON
	ec_word WILL
	ec_word MAKE
	ec_word YOU
	ec_word DOWNCAST
@ win speech
	ec_word YOUR
	ec_word POKEMON
	ec_word DON_T
	ec_word MAKE
	ec_word THE
	ec_move1 CUT
@ loss speech
	ec_word I_AM
	ec_word THE
	ec_word TRAINER
	ec_word WHO_IS
	ec_word FEELING
	ec_word DOWNCAST
	.4byte gBattleFrontierTrainerMons_Jenson

@ 59
	.4byte TRAINER_CLASS_FISHERMAN
	.string "WESLEY$", 8
@ pre-battle speech
	ec_pokemon2 MEW
	ec_pokemon2 MEW
	ec_word IS
	ec_word HOW
	ec_word I
	ec_word CRY
@ win speech
	ec_word YES
	ec_word I
	ec_word KNOW
	ec_word I_AM
	ec_word CUTE
	ec_word EXCL
@ loss speech
	ec_pokemon2 MEW
	ec_pokemon2 MEW
	ec_word EXCL
	ec_pokemon2 MEW
	ec_word EXCL_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Wesley

@ 60
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.string "ANTON$", 8
@ pre-battle speech
	ec_word GET
	ec_word READY
	ec_word FOR
	ec_word ME
	ec_word TO
	ec_move1 THRASH
@ win speech
	ec_word WAHAHAHA
	ec_word EXCL
	ec_word SORRY
	ec_word ABOUT
	ec_word THAT
	ec_word EXCL
@ loss speech
	ec_word IT_S
	ec_word A
	ec_word TOUGH
	ec_word LOSS
	ec_word TO
	ec_move2 SWALLOW
	.4byte gBattleFrontierTrainerMons_Anton

@ 61
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.string "LAWSON$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word YOUNG
	ec_word AT
	ec_word HEART
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word NOT
	ec_word COOL
	ec_word EXCL
	ec_word NOT
	ec_word AT
	ec_word ALL
@ loss speech
	ec_word I_AM
	ec_word OLD
	ec_word AND
	ec_word FEELING
	ec_word SHAKY
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Lawson

@ 62
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.string "SAMMY$", 8
@ pre-battle speech
	ec_word MY
	ec_word PARTY
	ec_word IS
	ec_word READY
	ec_word TO
	ec_word ROCK
@ win speech
	ec_word MY
	ec_word PARTY
	ec_word IS
	ec_word JUST
	ec_word INCREDIBLE
	ec_word EXCL
@ loss speech
	ec_word I
	ec_word CRY
	ec_word FOR
	ec_word MY
	ec_word PARTY
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Sammy

@ 63
	.4byte TRAINER_CLASS_COLLECTOR
	.string "ARNIE$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word NO_1
	ec_word I
	ec_word HAVE
	ec_word NO
	ec_word RIVAL
@ win speech
	ec_word YOU
	ec_word SEE
	ec_word QUES
	ec_word I
	ec_word CAN_T
	ec_word LOSE
@ loss speech
	ec_word NO
	ec_word EXCL
	ec_word I
	ec_word WON_T
	ec_word ACCEPT
	ec_word THIS
	.4byte gBattleFrontierTrainerMons_Arnie

@ 64
	.4byte TRAINER_CLASS_COLLECTOR
	.string "ADRIAN$", 8
@ pre-battle speech
	ec_word YAHOO
	ec_word EXCL
	.2byte -1
	ec_word YAHOO
	ec_word EXCL_EXCL
	.2byte -1
@ win speech
	ec_word THANK_YOU
	ec_word EXCL
	.2byte -1
	ec_word THANK_YOU
	ec_word EXCL_EXCL
	.2byte -1
@ loss speech
	ec_word GOOD_BYE
	ec_word EXCL
	.2byte -1
	ec_word GOOD_BYE
	ec_word EXCL_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Adrian

@ 65
	.4byte TRAINER_CLASS_COLLECTOR
	.string "TRISTAN$", 8
@ pre-battle speech
	ec_word CONFUSED
	ec_word QUES
	.2byte -1
	ec_word I_AM
	ec_word A
	ec_word GENIUS
@ win speech
	ec_word SEE
	ec_word QUES
	.2byte -1
	ec_word I_AM
	ec_word A
	ec_word GENIUS
@ loss speech
	ec_word I_AM
	ec_word NOT
	ec_word A
	ec_word GENIUS
	ec_word IN
	ec_word BATTLE
	.4byte gBattleFrontierTrainerMons_Tristan

@ 66
	.4byte TRAINER_CLASS_PARASOL_LADY
	.string "JULIANA$", 8
@ pre-battle speech
	ec_word I
	ec_word THINK
	ec_word I_AM
	ec_word SHOPPING
	ec_word TOO
	ec_word MUCH
@ win speech
	ec_word BUT
	ec_word I
	ec_word WANT
	ec_word A
	ec_word POKEMON
	ec_word PLUSH_DOLL
@ loss speech
	ec_word I
	ec_word SO
	ec_word WANT
	ec_word ANOTHER
	ec_word POKEMON
	ec_word PLUSH_DOLL
	.4byte gBattleFrontierTrainerMons_Juliana

@ 67
	.4byte TRAINER_CLASS_PARASOL_LADY
	.string "RYLEE$", 8
@ pre-battle speech
	ec_word SHOW
	ec_word ME
	ec_word THAT
	ec_word YOU
	ec_word HAVE
	ec_word GUTS
@ win speech
	ec_word BYE_BYE
	ec_word EXCL
	ec_word YOU
	ec_word HAVE
	ec_word NO
	ec_word GUTS
@ loss speech
	ec_word THAT_WAS
	ec_word GUTSY
	ec_word ELLIPSIS
	ec_word YOU_RE
	ec_word QUITE
	ec_word SUPER
	.4byte gBattleFrontierTrainerMons_Rylee

@ 68
	.4byte TRAINER_CLASS_PARASOL_LADY
	.string "CHELSEA$", 8
@ pre-battle speech
	ec_word I
	ec_word SERIOUSLY
	ec_word MEAN
	ec_word TO
	ec_word WIN
	ec_word EXCL
@ win speech
	ec_word THAT_WAS
	ec_word MY
	ec_word WILL
	ec_word TO
	ec_word WIN
	.2byte -1
@ loss speech
	ec_word YOU_RE
	ec_word FAR
	ec_word TOO_STRONG
	ec_word FOR
	ec_word ME
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Chelsea

@ 69
	.4byte TRAINER_CLASS_BEAUTY
	.string "DANELA$", 8
@ pre-battle speech
	ec_word YOU
	ec_word MUST_BE
	ec_word MY
	ec_word OPPONENT
	ec_word NOW
	ec_word EXCL
@ win speech
	ec_word OH_DEAR
	ec_word TOO_WEAK
	ec_word EXCL
	ec_word DON_T
	ec_word GIVE_UP
	ec_word EXCL
@ loss speech
	ec_word THAT_WAS
	ec_word GOOD
	ec_word AND
	ec_word THIS
	ec_word IS
	ec_word GOOD_BYE
	.4byte gBattleFrontierTrainerMons_Danela

@ 70
	.4byte TRAINER_CLASS_BEAUTY
	.string "LIZBETH$", 8
@ pre-battle speech
	ec_word IF_I_LOSE
	ec_word YOU
	ec_word CAN
	ec_word HAVE
	ec_word A
	ec_move2 PRESENT
@ win speech
	ec_word HERE_IT_IS
	ec_word A_LITTLE
	ec_word PRAISE
	ec_word AS
	ec_word YOUR
	ec_move2 PRESENT
@ loss speech
	ec_word YOUR
	ec_move2 PRESENT
	ec_word QUES_EXCL
	ec_word HERE_IT_IS
	ec_word A
	ec_move1 DOUBLE_SLAP
	.4byte gBattleFrontierTrainerMons_Lizbeth

@ 71
	.4byte TRAINER_CLASS_BEAUTY
	.string "AMELIA$", 8
@ pre-battle speech
	ec_word I
	ec_word BELIEVE
	ec_word IN
	ec_word CUTE
	ec_word FASHION
	ec_word APPEAL
@ win speech
	ec_word YOUR
	ec_word FASHION
	ec_word SENSE
	ec_word IS
	ec_word A
	ec_word DISASTER
@ loss speech
	ec_word THAT_WAS
	ec_word AWFUL
	ec_word EXCL
	ec_word I_AM
	ec_word GOING
	ec_word HOME
	.4byte gBattleFrontierTrainerMons_Amelia

@ 72
	.4byte TRAINER_CLASS_AROMA_LADY
	.string "JILLIAN$", 8
@ pre-battle speech
	ec_word WHAT
	ec_word IS
	ec_word THAT
	ec_word I
	ec_word SMELL
	ec_word QUES
@ win speech
	ec_word IT_S
	ec_word THE
	ec_move1 SWEET_SCENT
	ec_word OF
	ec_word TASTY
	ec_word WATER
@ loss speech
	ec_word IT_S
	ec_word YOUR
	ec_word OFFENSIVE
	ec_word STENCH
	ec_word THAT_S
	ec_word WHAT
	.4byte gBattleFrontierTrainerMons_Jillian

@ 73
	.4byte TRAINER_CLASS_AROMA_LADY
	.string "ABBIE$", 8
@ pre-battle speech
	ec_word YOU
	ec_word TRY
	ec_word MY
	ec_word SECRET
	ec_move1 AROMATHERAPY
	ec_word OK_QUES
@ win speech
	ec_word MY
	ec_move1 AROMATHERAPY
	ec_word IS
	ec_word TERRIBLE
	ec_word FOR
	ec_word YOU
@ loss speech
	ec_word DIDN_T
	ec_word YOU
	ec_word SMELL
	ec_word A
	ec_word THING
	ec_word QUES_EXCL
	.4byte gBattleFrontierTrainerMons_Abbie

@ 74
	.4byte TRAINER_CLASS_AROMA_LADY
	.string "BRIANA$", 8
@ pre-battle speech
	ec_word MY
	ec_word BOY
	ec_word FRIEND
	ec_word WORKS
	ec_word TOO
	ec_word MUCH
@ win speech
	ec_word I
	ec_word ONLY
	ec_word MISS
	ec_word HIM
	ec_word MORE
	ec_word ELLIPSIS
@ loss speech
	ec_word I_AM
	ec_word SO
	ec_word LONESOME
	ec_word WITHOUT
	ec_word HIM
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Briana

@ 75
	.4byte TRAINER_CLASS_GUITARIST
	.string "ANTONIO$", 8
@ pre-battle speech
	ec_word I
	ec_word KNOW
	ec_word HOW
	ec_word TO
	ec_word GO
	ec_word GO
@ win speech
	ec_word BUT
	ec_word I
	ec_word DON_T
	ec_word LIKE
	ec_word TO
	ec_word DANCE
@ loss speech
	ec_word GO
	ec_word GO
	ec_word ELLIPSIS
	ec_word JUST
	ec_move1 FLAIL
	ec_word ABOUT
	.4byte gBattleFrontierTrainerMons_Antonio

@ 76
	.4byte TRAINER_CLASS_GUITARIST
	.string "JADEN$", 8
@ pre-battle speech
	ec_word HELLO
	ec_word I
	ec_word THINK
	ec_word I
	ec_word ADORE
	ec_word YOU
@ win speech
	ec_word YOU
	ec_word MAKE
	ec_word ME
	ec_move1 THRASH
	ec_word IN
	ec_move2 FRUSTRATION
@ loss speech
	ec_word THIS_IS_IT_EXCL
	.2byte -1
	.2byte -1
	ec_word GOOD_BYE
	ec_word FOREVER
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Jaden

@ 77
	.4byte TRAINER_CLASS_GUITARIST
	.string "DAKOTA$", 8
@ pre-battle speech
	ec_word YOU
	ec_word HAVE
	ec_word TO
	ec_word DANCE
	ec_word WITH
	ec_word POWER
@ win speech
	ec_word GOT
	ec_word IT
	ec_word QUES
	ec_word DANCE
	ec_word WITH
	ec_word POWER
@ loss speech
	ec_word OKAY
	ec_word YOU
	ec_word UNDERSTAND
	ec_word ALL_RIGHT
	ec_word EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Dakota

@ 78
	.4byte TRAINER_CLASS_BIRD_KEEPER
	.string "BRAYDEN$", 8
@ pre-battle speech
	ec_word COLOR_CHANGE
	ec_word VERSION
	ec_word TOYS
	ec_word ARE
	ec_word USELESS
	ec_word EXCL
@ win speech
	ec_word I
	ec_word ONLY
	ec_word COLLECT
	ec_word NORMAL
	ec_word VERSION
	ec_word TOYS
@ loss speech
	ec_word I
	ec_move2 ATTRACT
	ec_word COLOR_CHANGE
	ec_word VERSION
	ec_word TOYS
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Brayden

@ 79
	.4byte TRAINER_CLASS_BIRD_KEEPER
	.string "CORSON$", 8
@ pre-battle speech
	ec_word I
	ec_word GET
	ec_word TO
	ec_move2 BEAT_UP
	ec_word ON
	ec_word YOU
@ win speech
	ec_word TOO
	ec_word EASY
	ec_word EXCL
	ec_word I_AM
	ec_word SO
	ec_word COOL
@ loss speech
	ec_word WHY
	ec_word QUES_EXCL
	.2byte -1
	ec_word I
	ec_move2 CURSE
	ec_word YOU
	.4byte gBattleFrontierTrainerMons_Corson

@ 80
	.4byte TRAINER_CLASS_BIRD_KEEPER
	.string "TREVIN$", 8
@ pre-battle speech
	ec_word THERE
	ec_word IS
	ec_word NONE
	ec_word BETTER
	ec_word THAN
	ec_word ME
@ win speech
	ec_word YES_SIR_EXCL
	.2byte -1
	.2byte -1
	ec_word I_AM
	ec_word THE
	ec_word BEST
@ loss speech
	ec_word SERIOUS
	ec_word QUES_EXCL
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Trevin

@ 81
	.4byte TRAINER_CLASS_SAILOR
	.string "PATRICK$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word PERFECT
	ec_word EXCL
	ec_word GIVE_UP
	ec_word NOW
	.2byte -1
@ win speech
	ec_word DON_T
	ec_word BE
	ec_word DISAPPOINTED
	ec_word I_AM
	ec_word PERFECT
	.2byte -1
@ loss speech
	ec_word BUT
	ec_word HOW
	ec_word QUES
	ec_word I_AM
	ec_word PERFECT
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Patrick

@ 82
	.4byte TRAINER_CLASS_SAILOR
	.string "KADEN$", 8
@ pre-battle speech
	ec_word WHAT
	ec_word ARE
	ec_word YOU
	ec_word UP
	ec_word TO
	ec_word QUES
@ win speech
	ec_word YOU
	ec_word WERE
	ec_word A
	ec_word SURPRISE
	ec_word TO_ME
	ec_word EXCL
@ loss speech
	ec_word I
	ec_word DON_T
	ec_word KNOW
	ec_word WHO
	ec_word I_AM
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Kaden

@ 83
	.4byte TRAINER_CLASS_SAILOR
	.string "MAXWELL$", 8
@ pre-battle speech
	ec_word HEY_THERE
	ec_word WHO_IS
	ec_word YOUR
	ec_word RIVAL
	ec_word QUES
	.2byte -1
@ win speech
	ec_word MY
	ec_word RIVAL
	ec_word IS
	ec_word MY
	ec_word GIRL
	ec_word FRIEND
@ loss speech
	ec_word I_AM
	ec_word MAKING
	ec_word YOU
	ec_word MY
	ec_word RIVAL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Maxwell

@ 84
	.4byte TRAINER_CLASS_HIKER
	.string "DARYL$", 8
@ pre-battle speech
	ec_word I
	ec_word ONLY
	ec_word KNOW
	ec_word HOW
	ec_word TO
	ec_move1 CHARGE
@ win speech
	ec_word AM
	ec_word I
	ec_word OVERWHELMING
	ec_word OR
	ec_word WHAT
	ec_word QUES
@ loss speech
	ec_word YOU_RE
	ec_word GOING
	ec_word TO
	ec_word A
	ec_word LEGEND
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Daryl

@ 85
	.4byte TRAINER_CLASS_HIKER
	.string "KENNETH$", 8
@ pre-battle speech
	ec_word YOU
	ec_word BETTER
	ec_word NOT
	ec_move2 SLACK_OFF
	ec_word WITH
	ec_word ME
@ win speech
	ec_word DID
	ec_word MY
	ec_move2 TAUNT
	ec_word INTIMIDATE
	ec_word YOU
	ec_word QUES
@ loss speech
	ec_word I_AM
	ec_word SORRY
	ec_word ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Kenneth

@ 86
	.4byte TRAINER_CLASS_HIKER
	.string "RICH$", 8
@ pre-battle speech
	ec_word YOUR
	ec_move1 FACADE
	ec_word DOESN_T
	ec_move2 TRICK
	ec_word ME
	.2byte -1
@ win speech
	ec_word SERIOUSLY
	ec_word ARE
	ec_word YOU
	ec_word REALLY
	ec_word OK_QUES
	.2byte -1
@ loss speech
	ec_word THAT_WAS
	ec_word REALLY
	ec_word TOUGH
	ec_word ON
	ec_word ME
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Rich

@ 87
	.4byte TRAINER_CLASS_KINDLER
	.string "CADEN$", 8
@ pre-battle speech
	ec_word I
	ec_word CAN_T
	ec_word BE
	ec_word DEFEATED
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word FIRE
	ec_word EXCL
	.2byte -1
	ec_word FIRE
	ec_word EXCL_EXCL
	.2byte -1
@ loss speech
	ec_word I_AM
	ec_word TIRED
	ec_word ELLIPSIS
	ec_word IT_S
	ec_word SO
	ec_word HOT
	.4byte gBattleFrontierTrainerMons_Caden

@ 88
	.4byte TRAINER_CLASS_KINDLER
	.string "MARLON$", 8
@ pre-battle speech
	ec_word A
	ec_word POKEDEX
	ec_word IS
	ec_word A_LITTLE
	ec_word RADIO
	ec_word QUES
@ win speech
	ec_word A_LITTLE
	ec_word RADIO
	ec_word HUH_QUES
	ec_word THAT_S
	ec_word TOTALLY
	ec_word COOL
@ loss speech
	ec_word IT_S
	ec_word NOT
	ec_word QUES
	ec_word IS
	ec_word POKENAV
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Marlon

@ 89
	.4byte TRAINER_CLASS_KINDLER
	.string "NASH$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word ON
	ec_word FIRE
	ec_word BABY
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word I
	ec_word LEFT
	ec_word YOU
	ec_word JUST
	ec_word AN
	ec_move2 EMBER
@ loss speech
	ec_word AIYEEH
	ec_word EXCL_EXCL
	.2byte -1
	ec_word NO
	ec_word WATER
	ec_word PLEASE
	.4byte gBattleFrontierTrainerMons_Nash

@ 90
	.4byte TRAINER_CLASS_TRIATHLETE_3
	.string "ROBBY$", 8
@ pre-battle speech
	ec_word HAHAHA
	ec_word EXCL
	ec_word HAPPY
	ec_word TO
	ec_word MEET_YOU
	ec_word EXCL
@ win speech
	ec_word I_AM
	ec_word THE
	ec_word LEADER
	ec_word WITH
	ec_word REFRESHING
	ec_word SERENE_GRACE
@ loss speech
	ec_word I
	ec_word WILL
	ec_move1 THRASH
	ec_word MY
	ec_word TOYS
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Robby

@ 91
	.4byte TRAINER_CLASS_TRIATHLETE_3
	.string "REECE$", 8
@ pre-battle speech
	ec_word MY
	ec_move2 QUICK_ATTACK
	ec_word CAN
	ec_word BEAT
	ec_word A
	ec_move2 TELEPORT
@ win speech
	ec_word LIKE
	ec_word I
	ec_word SAID
	ec_word I_AM
	ec_word DARN
	ec_word FAST
@ loss speech
	ec_word I_WAS
	ec_word KIDDING
	ec_word ABOUT
	ec_word THAT
	ec_move2 TELEPORT
	ec_word THING
	.4byte gBattleFrontierTrainerMons_Reece

@ 92
	.4byte TRAINER_CLASS_TRIATHLETE_4
	.string "KATHRYN$", 8
@ pre-battle speech
	ec_word I
	ec_word DON_T
	ec_word TRAIN
	ec_word GOOD
	ec_word ENOUGH
	ec_word QUES
@ win speech
	ec_word DON_T
	ec_move2 TAUNT
	ec_word ME
	ec_word LIKE
	ec_word THAT
	ec_word OK_QUES
@ loss speech
	ec_word WHY
	ec_word COULDN_T
	ec_word I
	ec_word WIN
	ec_word THIS
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Kathryn

@ 93
	.4byte TRAINER_CLASS_TRIATHLETE_4
	.string "ELLEN$", 8
@ pre-battle speech
	ec_word CRUSH
	ec_word YOU
	ec_word LIKE
	ec_word AN
	ec_word EGG
	ec_word EXCL
@ win speech
	ec_word THAT_WAS
	ec_word A
	ec_word TASTY
	ec_word VICTORY
	ec_word FOR
	ec_word ME
@ loss speech
	ec_word TOO
	ec_word TOUGH
	ec_word TO
	ec_word CRUSH
	ec_word EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Ellen

@ 94
	.4byte TRAINER_CLASS_TRIATHLETE_5
	.string "RAMON$", 8
@ pre-battle speech
	ec_word OKAY
	ec_word EXCL
	.2byte -1
	ec_word THIS
	ec_word IS
	ec_word PERFECTION
@ win speech
	ec_word I_AM
	ec_word HAPPY
	ec_word THAT
	ec_word I
	ec_word WON
	ec_word EXCL
@ loss speech
	ec_word IT_S
	ec_word A
	ec_word SECRET
	ec_word WHY
	ec_word I_AM
	ec_word HAPPY
	.4byte gBattleFrontierTrainerMons_Ramon

@ 95
	.4byte TRAINER_CLASS_TRIATHLETE_5
	.string "ARTHUR$", 8
@ pre-battle speech
	ec_word HERE_I_COME
	ec_word FEELING
	ec_word READY
	ec_word FOR
	ec_word IT
	ec_word ALL
@ win speech
	ec_word THAT_S_IT_EXCL
	.2byte -1
	.2byte -1
	ec_word THAT_WAS
	ec_word FABULOUS
	ec_word EXCL
@ loss speech
	ec_word THAT_WAS
	ec_word NOT
	ec_word WHAT
	ec_word I
	ec_word NEED
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Arthur

@ 96
	.4byte TRAINER_CLASS_TRIATHLETE_6
	.string "ALONDRA$", 8
@ pre-battle speech
	ec_word EVERY
	ec_word DAY
	ec_word IS
	ec_word A
	ec_word GREAT
	ec_word DAY
@ win speech
	ec_word MY
	ec_move2 DIVE
	ec_word WILL
	ec_word BE
	ec_word A
	ec_word LEGEND
@ loss speech
	ec_word MY
	ec_move2 DIVE
	ec_word LEFT
	ec_word ME
	ec_word COLD
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Alondra

@ 97
	.4byte TRAINER_CLASS_TRIATHLETE_6
	.string "ADRIANA$", 8
@ pre-battle speech
	ec_word COME
	ec_word SEE
	ec_word AN
	ec_word INCREDIBLE
	ec_word SWIFT_SWIM
	ec_word EXCL
@ win speech
	ec_word I
	ec_word MAKE
	ec_word IT
	ec_word LOOK
	ec_word SO
	ec_word EASY
@ loss speech
	ec_word I_AM
	ec_word FEELING
	ec_move2 BEAT_UP
	ec_word AND
	ec_word TIRED
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Adriana

@ 98
	.4byte TRAINER_CLASS_TRIATHLETE_1
	.string "MALIK$", 8
@ pre-battle speech
	ec_word OH
	ec_word NOT
	ec_word ANOTHER
	ec_word BATTLE
	ec_word PLEASE
	ec_word ELLIPSIS
@ win speech
	ec_word I
	ec_word FINALLY
	ec_word WON
	ec_word ELLIPSIS
	ec_word I_AM
	ec_word TIRED
@ loss speech
	ec_word I
	ec_word FINALLY
	ec_word LOST
	ec_word ELLIPSIS
	ec_word I_AM
	ec_word TIRED
	.4byte gBattleFrontierTrainerMons_Malik

@ 99
	.4byte TRAINER_CLASS_TRIATHLETE_2
	.string "JILL$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word THE
	ec_move2 QUICK_ATTACK
	ec_word TRAINER
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word THE
	ec_move2 QUICK_ATTACK
	ec_word TRAINER
	ec_word WINS
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word THE
	ec_move2 QUICK_ATTACK
	ec_word TRAINER
	ec_word GIVES
	ec_word UP
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Jill

@ 100
	.4byte TRAINER_CLASS_TRIATHLETE_3
	.string "ERIK$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word THE
	ec_word SPEED_BOOST
	ec_word HERO
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word THANK_YOU
	ec_word FROM
	ec_word THE
	ec_word SPEED_BOOST
	ec_word HERO
	ec_word EXCL
@ loss speech
	ec_word WAAAH
	ec_word EXCL_EXCL
	.2byte -1
	ec_word NO
	ec_word NO
	ec_word EXCL_EXCL
	.4byte gBattleFrontierTrainerMons_Erik

@ 101
	.4byte TRAINER_CLASS_TRIATHLETE_4
	.string "YAZMIN$", 8
@ pre-battle speech
	ec_word I
	ec_word WOULD
	ec_word RATHER
	ec_word RUN
	ec_word THAN
	ec_word BIKE
@ win speech
	ec_word YES
	ec_word I
	ec_word WOULD
	ec_word MUCH
	ec_word RATHER
	ec_word RUN
@ loss speech
	ec_word BYE_BYE
	ec_word EXCL
	ec_word I_AM
	ec_word GOING
	ec_word TO
	ec_word RUN_AWAY
	.4byte gBattleFrontierTrainerMons_Yazmin

@ 102
	.4byte TRAINER_CLASS_TRIATHLETE_5
	.string "JAMAL$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word GOING
	ec_word TO
	ec_word BE
	ec_word A
	ec_word FATHER
@ win speech
	ec_word I
	ec_word CAN_T
	ec_word WAIT
	ec_word FOR
	ec_word MY
	ec_word BABY
@ loss speech
	ec_word MY
	ec_word BABY
	ec_word WILL
	ec_word BE
	ec_word TOTALLY
	ec_word AWESOME
	.4byte gBattleFrontierTrainerMons_Jamal

@ 103
	.4byte TRAINER_CLASS_TRIATHLETE_6
	.string "LESLIE$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word GOING
	ec_word TO
	ec_word BE
	ec_word A
	ec_word MOTHER
@ win speech
	ec_word A
	ec_word BABY
	ec_word WILL
	ec_word BE
	ec_word A_LITTLE
	ec_word CHALLENGE
@ loss speech
	ec_word I_AM
	ec_word TOO
	ec_word HAPPY
	ec_word TO
	ec_word BE
	ec_word ANGRY
	.4byte gBattleFrontierTrainerMons_Leslie

@ 104
	.4byte TRAINER_CLASS_TRIATHLETE_1
	.string "DAVE$", 8
@ pre-battle speech
	ec_word WHAT
	ec_word SHOULD
	ec_word I
	ec_word DO
	ec_word TODAY
	ec_word QUES
@ win speech
	ec_word I
	ec_word SHOULD
	ec_word ENJOY
	ec_word SOME
	ec_word SPORTS
	ec_word EXCL
@ loss speech
	ec_word I
	ec_word WILL
	ec_word GO
	ec_word PLAY
	ec_word A
	ec_word GAME
	.4byte gBattleFrontierTrainerMons_Dave

@ 105
	.4byte TRAINER_CLASS_TRIATHLETE_1
	.string "CARLO$", 8
@ pre-battle speech
	ec_word HAH
	ec_word EXCL_EXCL
	.2byte -1
	ec_word YEAH
	ec_word EXCL_EXCL
	.2byte -1
@ win speech
	ec_word I
	ec_word DO
	ec_word THINGS
	ec_word AT
	ec_move1 EXTREME_SPEED
	ec_word EXCL
@ loss speech
	ec_word I
	ec_word LOST
	ec_word AT
	ec_move1 EXTREME_SPEED
	ec_word ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Carlo

@ 106
	.4byte TRAINER_CLASS_TRIATHLETE_2
	.string "EMILIA$", 8
@ pre-battle speech
	ec_word ME
	ec_word WORRY
	ec_word QUES
	ec_word I
	ec_word HAVE
	ec_word NONE
@ win speech
	ec_word AHAHA
	ec_word SEE
	ec_word QUES
	ec_word THAT_WAS
	ec_word FANTASTIC
	ec_word EXCL
@ loss speech
	ec_word AHAHA
	ec_word SEE
	ec_word QUES
	ec_word THAT_WAS
	ec_word ENTERTAINING
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Emilia

@ 107
	.4byte TRAINER_CLASS_TRIATHLETE_2
	.string "DALIA$", 8
@ pre-battle speech
	ec_word MY
	ec_word BIKE
	ec_word IS
	ec_word VERY
	ec_word EXPENSIVE
	.2byte -1
@ win speech
	ec_word DON_T
	ec_word COME
	ec_word NEAR
	ec_word MY
	ec_word BIKE
	ec_word EXCL
@ loss speech
	ec_word MY
	ec_word BIKE
	ec_word IS
	ec_word MY
	ec_word BEST
	ec_word FRIEND
	.4byte gBattleFrontierTrainerMons_Dalia

@ 108
	.4byte TRAINER_CLASS_BLACK_BELT
	.string "HITOMI$", 8
@ pre-battle speech
	ec_word YEAH
	ec_word EXCL_EXCL
	.2byte -1
	ec_word HAH
	ec_word EXCL_EXCL
	.2byte -1
@ win speech
	ec_word WHAT
	ec_word QUES_EXCL
	.2byte -1
	ec_word I
	ec_word WON
	ec_word QUES_EXCL
@ loss speech
	ec_word AIYEEH
	ec_word EXCL_EXCL
	.2byte -1
	ec_word I_AM
	ec_word SORRY
	ec_word EXCL_EXCL
	.4byte gBattleFrontierTrainerMons_Hitomi

@ 109
	.4byte TRAINER_CLASS_BLACK_BELT
	.string "RICARDO$", 8
@ pre-battle speech
	ec_word COME_ON
	ec_word EXCL
	ec_word PLAY
	ec_word TIME
	ec_word IS
	ec_word OVER
@ win speech
	ec_word YOU_RE
	ec_word OUT
	ec_word OF
	ec_word HERE
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word PLEASE
	ec_word DON_T
	ec_word HIT
	ec_word ME
	ec_word EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Ricardo

@ 110
	.4byte TRAINER_CLASS_BLACK_BELT
	.string "SHIZUKA$", 8
@ pre-battle speech
	ec_word SHOW
	ec_word ME
	ec_word THAT
	ec_word YOU_RE
	ec_word SERIOUS
	ec_word EXCL
@ win speech
	ec_word I
	ec_word WON_T
	ec_word FORGET
	ec_word ABOUT
	ec_word YOU
	.2byte -1
@ loss speech
	ec_word YOU_RE
	ec_word PERFECT
	ec_word IN
	ec_word EVERY
	ec_word WAY
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Shizuka

@ 111
	.4byte TRAINER_CLASS_BATTLE_GIRL
	.string "JOANA$", 8
@ pre-battle speech
	ec_word YOU_RE
	ec_word GOING
	ec_word TO
	ec_word LOSE
	ec_word RIGHT
	ec_word AWAY
@ win speech
	ec_word I_AM
	ec_word THE
	ec_word WINNER
	ec_word HEAR
	ec_word ME
	ec_move2 ROAR
@ loss speech
	ec_word I
	ec_word REFUSE
	ec_word TO
	ec_word ACCEPT
	ec_word THAT
	ec_move1 OUTRAGE
	.4byte gBattleFrontierTrainerMons_Joana

@ 112
	.4byte TRAINER_CLASS_BATTLE_GIRL
	.string "KELLY$", 8
@ pre-battle speech
	ec_word MY
	ec_word NIGHT
	ec_word SCHOOL
	ec_word IS
	ec_word REALLY
	ec_word SCARY
@ win speech
	ec_word A
	ec_word LADY
	ec_word GHOST
	ec_word APPEARS
	ec_word THERE
	.2byte -1
@ loss speech
	ec_word THE
	ec_word HOME
	ec_word WORK
	ec_word IS
	ec_word AWFULLY
	ec_word SCARY
	.4byte gBattleFrontierTrainerMons_Kelly

@ 113
	.4byte TRAINER_CLASS_BATTLE_GIRL
	.string "RAYNA$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word NO_1
	ec_word WHEN
	ec_word IT_S
	ec_word ABOUT
	ec_word POWER
@ win speech
	ec_word UNDERSTAND
	ec_word MY
	ec_word POWER
	ec_word NOW
	ec_word QUES
	.2byte -1
@ loss speech
	ec_word TERRIBLE
	ec_word ELLIPSIS
	.2byte -1
	ec_word I_AM
	ec_word TERRIBLE
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Rayna

@ 114
	.4byte TRAINER_CLASS_EXPERT_1
	.string "EVAN$", 8
@ pre-battle speech
	ec_word EVERY
	ec_word BATTLE
	ec_word HAS
	ec_word A
	ec_word SMELL
	.2byte -1
@ win speech
	ec_word OH
	ec_word EXCL
	ec_word THE
	ec_move1 SWEET_SCENT
	ec_word OF
	ec_word VICTORY
@ loss speech
	ec_word THE
	ec_word AWFUL
	ec_word STENCH
	ec_word OF
	ec_word A
	ec_word LOSS
	.4byte gBattleFrontierTrainerMons_Evan

@ 115
	.4byte TRAINER_CLASS_EXPERT_1
	.string "JORDAN$", 8
@ pre-battle speech
	ec_word GOOD
	ec_word EXCL
	.2byte -1
	ec_word COME_ON
	ec_word EXCL_EXCL
	.2byte -1
@ win speech
	ec_word YOU
	ec_word CAN_T
	ec_word BEAT
	ec_word ME
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word WHAT
	ec_word QUES_EXCL
	.2byte -1
	ec_word BUT
	ec_word HOW
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Jordan

@ 116
	.4byte TRAINER_CLASS_EXPERT_1
	.string "JOEL$", 8
@ pre-battle speech
	ec_word FUFUFU
	ec_word ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
@ win speech
	ec_word GIGGLE
	ec_word ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
@ loss speech
	ec_word HAHAHA
	ec_word ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Joel

@ 117
	.4byte TRAINER_CLASS_EXPERT_2
	.string "KRISTEN$", 8
@ pre-battle speech
	ec_word HAHAHA
	ec_word ELLIPSIS
	.2byte -1
	ec_word A
	ec_word KID
	ec_word ELLIPSIS
@ win speech
	ec_word JUST
	ec_word A_LITTLE
	ec_word KID
	ec_word AFTER
	ec_word ALL
	ec_word EXCL
@ loss speech
	ec_word A
	ec_word TOUGH
	ec_word KID
	ec_word HUH_QUES
	ec_word HUMPH
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Kristen

@ 118
	.4byte TRAINER_CLASS_EXPERT_2
	.string "SELPHY$", 8
@ pre-battle speech
	ec_word HUH_QUES
	ec_word WHAT
	ec_word IS_IT_QUES
	.2byte -1
	.2byte -1
	.2byte -1
@ win speech
	ec_word OH
	ec_word YES
	ec_word EXCL
	ec_word WHY
	ec_word NOT
	ec_word QUES
@ loss speech
	ec_word OH
	ec_word NO
	ec_word EXCL
	ec_word WHY
	ec_word NOT
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Selphy

@ 119
	.4byte TRAINER_CLASS_EXPERT_2
	.string "CHLOE$", 8
@ pre-battle speech
	ec_word COME
	ec_word WE
	ec_word WILL
	ec_word DO
	ec_word BATTLE
	ec_word NOW
@ win speech
	ec_word MORE
	ec_word EXCL
	.2byte -1
	ec_word ANOTHER
	ec_word BATTLE
	ec_word EXCL
@ loss speech
	ec_word OH
	ec_word EXCL
	.2byte -1
	ec_word STRONG
	ec_word YOU
	ec_word ARE
	.4byte gBattleFrontierTrainerMons_Chloe

@ 120
	.4byte TRAINER_CLASS_PSYCHIC_1
	.string "NORTON$", 8
@ pre-battle speech
	ec_word I
	ec_word KNOW
	ec_word ONLY
	ec_word YOU
	.2byte -1
	.2byte -1
@ win speech
	ec_word EXCUSE_ME
	ec_word BUT
	ec_word YOU_RE
	ec_word A
	ec_word PUSHOVER
	ec_word EXCL
@ loss speech
	ec_word YOU_RE
	ec_word SOME
	ec_word KIND
	ec_word OF
	ec_word AWESOME
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Norton

@ 121
	.4byte TRAINER_CLASS_PSYCHIC_1
	.string "LUKAS$", 8
@ pre-battle speech
	ec_word MY
	ec_word JOKING
	ec_word IS
	ec_word PRETTY
	ec_word TERRIBLE
	ec_word ELLIPSIS
@ win speech
	ec_word YOUR
	ec_word ROCK_HEAD
	ec_word EXISTS
	ec_word TO
	ec_word SHINE
	ec_word EXCL
@ loss speech
	ec_word YOUR
	ec_word ROCK_HEAD
	ec_word COME
	ec_word TO
	ec_word SHINE
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Lukas

@ 122
	.4byte TRAINER_CLASS_PSYCHIC_1
	.string "ZACH$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word AN
	ec_word EXCELLENT
	ec_move2 MIMIC
	ec_word OF
	ec_word POKEMON
@ win speech
	ec_word I_AM
	ec_word HAPPY
	ec_word LIKE
	ec_word A_LITTLE
	ec_pokemon2 TOGEPI
	ec_word EXCL
@ loss speech
	ec_word I_AM
	ec_word ANGRY
	ec_word LIKE
	ec_word A
	ec_pokemon2 MANKEY
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Zach

@ 123
	.4byte TRAINER_CLASS_PSYCHIC_2
	.string "KAITLYN$", 8
@ pre-battle speech
	ec_word I
	ec_word CRUSH
	ec_word THINGS
	ec_word WITH
	ec_word PSYCHIC
	ec_word POWER
@ win speech
	ec_word MY
	ec_word VICTORY
	ec_word WILL
	ec_word MAKE
	ec_word THE
	ec_word NEWS
@ loss speech
	ec_word NO
	ec_word NO
	ec_word ELLIPSIS
	ec_word THIS
	ec_word WON_T
	ec_word DO
	.4byte gBattleFrontierTrainerMons_Kaitlyn

@ 124
	.4byte TRAINER_CLASS_PSYCHIC_2
	.string "BREANNA$", 8
@ pre-battle speech
	ec_word MY
	ec_word POKEMON
	ec_word WILL
	ec_word CRUSH
	ec_word YOU
	ec_word EXCL
@ win speech
	ec_word HAVE
	ec_word SOME
	ec_word MORE
	ec_word OF
	ec_word THIS
	ec_word EXCL
@ loss speech
	ec_word YOU
	ec_word HAVE
	ec_word GUTS
	ec_word AND
	ec_word SKILL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Breanna

@ 125
	.4byte TRAINER_CLASS_PSYCHIC_2
	.string "KENDRA$", 8
@ pre-battle speech
	ec_word IF
	ec_word YOU_RE
	ec_word SMART
	ec_word STOP
	ec_word RIGHT
	ec_word NOW
@ win speech
	ec_word I
	ec_word SAID
	ec_word THAT
	ec_word YOU
	ec_word SHOULD
	ec_word STOP
@ loss speech
	ec_word WHY
	ec_word DIDN_T
	ec_word YOU
	ec_word STOP
	ec_word QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Kendra

@ 126
	.4byte TRAINER_CLASS_HEX_MANIAC
	.string "MOLLY$", 8
@ pre-battle speech
	ec_word WILL
	ec_word MY
	ec_word CUTE_CHARM
	ec_move2 ATTRACT
	ec_word YOU
	ec_word QUES
@ win speech
	ec_word YOUR
	ec_word POKEMON
	ec_word ARE
	ec_word MY
	ec_word TOYS
	ec_word NOW
@ loss speech
	ec_word OH
	ec_word HOW
	ec_word COULD
	ec_word YOU
	ec_word QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Molly

@ 127
	.4byte TRAINER_CLASS_HEX_MANIAC
	.string "JAZMIN$", 8
@ pre-battle speech
	ec_word I
	ec_word FORECAST
	ec_word TERRIBLE
	ec_word THINGS
	ec_word FOR
	ec_word YOU
@ win speech
	ec_word THERE
	ec_word WASN_T
	ec_word MY
	ec_word FORECAST
	ec_word RIGHT
	ec_word QUES
@ loss speech
	ec_word MY
	ec_move2 FORESIGHT
	ec_word DIDN_T
	ec_word SHOW
	ec_word ME
	ec_word THIS
	.4byte gBattleFrontierTrainerMons_Jazmin

@ 128
	.4byte TRAINER_CLASS_HEX_MANIAC
	.string "KELSEY$", 8
@ pre-battle speech
	ec_word I
	ec_word HAVEN_T
	ec_word SLEPT
	ec_word IN
	ec_word DAYS
	ec_word ELLIPSIS
@ win speech
	ec_word MY
	ec_word SLEEP
	ec_word WILL
	ec_word BE
	ec_word EXCELLENT
	ec_word NOW
@ loss speech
	ec_word YOU
	ec_word HAVE
	ec_word DESTROYED
	ec_word MY
	ec_word SLEEP
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Kelsey

@ 129
	.4byte TRAINER_CLASS_POKEMANIAC
	.string "JALEN$", 8
@ pre-battle speech
	ec_word I
	ec_word DON_T
	ec_word ALLOW
	ec_word POKEMON
	ec_word TO
	ec_move1 THRASH
@ win speech
	ec_word HAHAHA
	ec_word EXCL
	ec_word ARE
	ec_word YOU
	ec_word ANGRY
	ec_word QUES
@ loss speech
	ec_word WHY
	ec_word IS
	ec_word THIS
	ec_word SO
	ec_word HARD
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Jalen

@ 130
	.4byte TRAINER_CLASS_POKEMANIAC
	.string "GRIFFEN$", 8
@ pre-battle speech
	ec_word I
	ec_move2 SWALLOW
	ec_move2 SLUDGE
	ec_word TO
	ec_move2 TRANSFORM
	ec_word MYSELF
@ win speech
	ec_word I
	ec_word HAVE
	ec_word A
	ec_move1 GROWTH
	ec_word OF
	ec_move2 ACID_ARMOR
@ loss speech
	ec_word I
	ec_word HAVE
	ec_word A
	ec_move1 GROWTH
	ec_word OF
	ec_word SUCTION_CUPS
	.4byte gBattleFrontierTrainerMons_Griffen

@ 131
	.4byte TRAINER_CLASS_POKEMANIAC
	.string "XANDER$", 8
@ pre-battle speech
	ec_word I
	ec_word GOT
	ec_word MY
	ec_word POKEMON
	ec_word ON
	ec_word RENTAL
@ win speech
	ec_word IT_S
	ec_word INCREDIBLE
	ec_word MY
	ec_word RENTAL
	ec_word POKEMON
	ec_word WON
@ loss speech
	ec_word RENTAL
	ec_word POKEMON
	ec_word AREN_T
	ec_word UP
	ec_word TO
	ec_move2 SCRATCH
	.4byte gBattleFrontierTrainerMons_Xander

@ 132
	.4byte TRAINER_CLASS_GENTLEMAN
	.string "MARVIN$", 8
@ pre-battle speech
	ec_word YOU_RE
	ec_word UP
	ec_word TO
	ec_word THE
	ec_word CHALLENGE
	ec_word QUES
@ win speech
	ec_word I
	ec_word DIDN_T
	ec_word THINK
	ec_word YOU_RE
	ec_word GOOD
	ec_word ENOUGH
@ loss speech
	ec_word I_AM
	ec_word FEELING
	ec_word PERFECT
	ec_word THANK_YOU
	ec_word SO
	ec_word MUCH
	.4byte gBattleFrontierTrainerMons_Marvin

@ 133
	.4byte TRAINER_CLASS_GENTLEMAN
	.string "BRENNAN$", 8
@ pre-battle speech
	ec_word I
	ec_move2 WISH
	ec_word TO
	ec_word SEE
	ec_word THE
	ec_word NEWS
@ win speech
	ec_word COMICS
	ec_word GET
	ec_word DAMP
	ec_word FROM
	ec_word DRIZZLE
	ec_word QUES
@ loss speech
	ec_word THE
	ec_word TIGHT
	ec_word MONEY
	ec_word LIVING
	ec_word CHANNEL
	ec_word QUES_EXCL
	.4byte gBattleFrontierTrainerMons_Brennan

@ 134
	.4byte TRAINER_CLASS_BUG_MANIAC
	.string "BALEY$", 8
@ pre-battle speech
	ec_move1 SCREECH
	ec_word IS
	ec_word LIKE
	ec_word MUSIC
	ec_word TO_ME
	ec_word EXCL
@ win speech
	ec_word MY
	ec_move1 SCREECH
	ec_word STRATEGY
	ec_word IS
	ec_word THE
	ec_word BEST
@ loss speech
	ec_word YOU_RE
	ec_word SOUNDPROOF
	ec_word QUES
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Baley

@ 135
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.string "ZACKARY$", 8
@ pre-battle speech
	ec_word CAN
	ec_word YOU
	ec_move1 DIG
	ec_word IT
	ec_word YO
	ec_word QUES
@ win speech
	ec_move2 TAKE_DOWN
	ec_word TAKE
	ec_word A
	ec_move2 DIVE
	ec_word YO
	ec_word YO
@ loss speech
	ec_word BREAK
	ec_word DOWN
	ec_move2 DIVE
	ec_word TIME
	ec_word FOR
	ec_word ME
	.4byte gBattleFrontierTrainerMons_Zackary

@ 136
	.4byte TRAINER_CLASS_COLLECTOR
	.string "GABRIEL$", 8
@ pre-battle speech
	ec_move2 POUND
	ec_word THE
	ec_word THICK_FAT
	ec_word ON
	ec_word MY
	ec_move2 BELLY_DRUM
@ win speech
	ec_move2 POUND
	ec_word MY
	ec_move2 BELLY_DRUM
	ec_move2 POUND
	ec_word MY
	ec_move2 BELLY_DRUM
@ loss speech
	ec_word MY
	ec_move2 BELLY_DRUM
	ec_word WAS
	ec_word TOO_WEAK
	ec_word ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Gabriel

@ 137
	.4byte TRAINER_CLASS_PARASOL_LADY
	.string "EMILY$", 8
@ pre-battle speech
	ec_word HOW
	ec_word ABOUT
	ec_word A_TINY_BIT
	ec_word OF
	ec_move1 HYPNOSIS
	ec_word QUES
@ win speech
	ec_word MY
	ec_move1 HYPNOSIS
	ec_word STRATEGY
	ec_word WORKS
	ec_word TO
	ec_word PERFECTION
@ loss speech
	ec_word MY
	ec_move1 HYPNOSIS
	ec_word STRATEGY
	ec_word WENT
	ec_word BADLY
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Emily

@ 138
	.4byte TRAINER_CLASS_BEAUTY
	.string "JORDYN$", 8
@ pre-battle speech
	ec_word YOU
	ec_word DON_T
	ec_word KNOW
	ec_word MY
	ec_word SECRET
	ec_word ELLIPSIS
@ win speech
	ec_word I_AM
	ec_word NOT
	ec_word AS
	ec_word I
	ec_word APPEAR
	ec_word ELLIPSIS
@ loss speech
	ec_word BUT
	ec_word HOW
	ec_word DID
	ec_word YOU
	ec_word KNOW
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Jordyn

@ 139
	.4byte TRAINER_CLASS_AROMA_LADY
	.string "SOFIA$", 8
@ pre-battle speech
	ec_pokemon1 LOUDRED
	ec_word PROBABLY
	ec_word HAS
	ec_word A
	ec_move1 SWEET_SCENT
	.2byte -1
@ win speech
	ec_word THAT_S
	ec_word THE
	ec_word FEELING
	ec_word THAT
	ec_word I
	ec_word GET
@ loss speech
	ec_word I
	ec_word WORK
	ec_word AT
	ec_word THE
	ec_word DEPT_STORE
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Sofia

@ 140
	.4byte TRAINER_CLASS_COOLTRAINER_1
	.string "BRADEN$", 8
@ pre-battle speech
	ec_word I_CHOOSE_YOU
	ec_word EXCL
	.2byte -1
	ec_word THIS_IS_IT_EXCL
	.2byte -1
	.2byte -1
@ win speech
	ec_word I_AM
	ec_word FEELING
	ec_word PRETTY
	ec_word AWESOME
	ec_word ABOUT
	ec_word MYSELF
@ loss speech
	ec_word ALL_RIGHT
	ec_word EXCL
	.2byte -1
	ec_word I
	ec_word SURRENDER
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Braden

@ 141
	.4byte TRAINER_CLASS_COOLTRAINER_1
	.string "KAYDEN$", 8
@ pre-battle speech
	ec_word THEY
	ec_word OVERDO
	ec_word THAT
	ec_word GOURMET
	ec_word THING
	ec_word ELLIPSIS
@ win speech
	ec_word THAT
	ec_word GOURMET
	ec_word THING
	ec_word ISN_T
	ec_word FOR
	ec_word ME
@ loss speech
	ec_word HEY
	ec_word THIS
	ec_word IS
	ec_word PRETTY
	ec_word TASTY
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Kayden

@ 142
	.4byte TRAINER_CLASS_COOLTRAINER_1
	.string "COOPER$", 8
@ pre-battle speech
	ec_word THIS
	ec_word SHOULD
	ec_word ABSOLUTELY
	ec_word BE
	ec_word A
	ec_word PUSHOVER
@ win speech
	ec_word THAT_WAS
	ec_word TOO
	ec_word EXCITING
	ec_word FOR
	ec_word ME
	ec_word ELLIPSIS
@ loss speech
	ec_word PLEASE
	ec_word EXCL
	.2byte -1
	ec_word SORRY
	ec_word I_AM
	ec_word SORRY
	.4byte gBattleFrontierTrainerMons_Cooper

@ 143
	.4byte TRAINER_CLASS_COOLTRAINER_2
	.string "JULIA$", 8
@ pre-battle speech
	ec_word SPIRIT
	ec_word ALONE
	ec_word WON_T
	ec_word MAKE
	ec_word YOU
	ec_word WIN
@ win speech
	ec_word YOU
	ec_word SHOULD
	ec_word ACCEPT
	ec_word THIS
	ec_word WITH
	ec_word SERENE_GRACE
@ loss speech
	ec_word FOR_NOW
	ec_word GOOD_BYE
	ec_word BUT
	ec_word IT_S
	ec_word NOT
	ec_word OVER
	.4byte gBattleFrontierTrainerMons_Julia

@ 144
	.4byte TRAINER_CLASS_COOLTRAINER_2
	.string "AMARA$", 8
@ pre-battle speech
	ec_word WROOOAAR_EXCL
	ec_word EXCL_EXCL
	ec_word I_AM
	ec_word SO
	ec_word READY
	ec_word EXCL_EXCL
@ win speech
	ec_word I
	ec_word LOSE
	ec_word MYSELF
	ec_word IF
	ec_word IT_S
	ec_word EXCITING
@ loss speech
	ec_word THAT_S
	ec_word TOO
	ec_word MUCH
	ec_word TO
	ec_move2 TACKLE
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Amara

@ 145
	.4byte TRAINER_CLASS_COOLTRAINER_2
	.string "LYNN$", 8
@ pre-battle speech
	ec_word YOUR
	ec_word SECRET
	ec_word CAN_T
	ec_word BE
	ec_word HIDDEN
	ec_word FOREVER
@ win speech
	ec_word I
	ec_word KNOW
	ec_word YOUR
	ec_word SECRET
	ec_word NOW
	ec_word EXCL
@ loss speech
	ec_word YOU
	ec_word CAN_T
	ec_move1 SAFEGUARD
	ec_word YOUR
	ec_word OWN
	ec_word SECRET
	.4byte gBattleFrontierTrainerMons_Lynn

@ 146
	.4byte TRAINER_CLASS_PKMN_RANGER_1
	.string "JOVAN$", 8
@ pre-battle speech
	ec_word YOUR
	ec_word BATTLE
	ec_word SENSE
	ec_word IS
	ec_word SADLY
	ec_word LACKING
@ win speech
	ec_word MY
	ec_word BATTLE
	ec_word SENSE
	ec_word IS
	ec_word COOL
	ec_word ISN_T_IT_QUES
@ loss speech
	ec_word I_WAS
	ec_word MINUS
	ec_word MY
	ec_word NORMAL
	ec_word POWER
	ec_word TODAY
	.4byte gBattleFrontierTrainerMons_Jovan

@ 147
	.4byte TRAINER_CLASS_PKMN_RANGER_1
	.string "DOMINIC$", 8
@ pre-battle speech
	ec_word I
	ec_word HAVE
	ec_word THIS
	ec_word EXCELLENT
	ec_word CAMERA
	.2byte -1
@ win speech
	ec_word MY
	ec_word CAMERA
	ec_word WAS
	ec_word AWFULLY
	ec_word EXPENSIVE
	.2byte -1
@ loss speech
	ec_word MY
	ec_word CAMERA
	ec_word DOESN_T
	ec_word MISS
	ec_word A
	ec_word THING
	.4byte gBattleFrontierTrainerMons_Dominic

@ 148
	.4byte TRAINER_CLASS_PKMN_RANGER_1
	.string "NIKOLAS$", 8
@ pre-battle speech
	ec_word I
	ec_move2 MIMIC
	ec_word POKEMON
	ec_word AFTER
	ec_word EVERY
	ec_word BATTLE
@ win speech
	ec_word IF_I_WIN
	ec_word I
	ec_word PRETEND
	ec_word I_AM
	ec_word A
	ec_pokemon2 TAUROS
@ loss speech
	ec_word IF_I_LOSE
	ec_word I
	ec_word PRETEND
	ec_word I_AM
	ec_word A
	ec_pokemon2 MILTANK
	.4byte gBattleFrontierTrainerMons_Nikolas

@ 149
	.4byte TRAINER_CLASS_PKMN_RANGER_2
	.string "VALERIA$", 8
@ pre-battle speech
	ec_word I
	ec_move2 WISH
	ec_word YOU
	ec_word WOULD
	ec_word NOT
	ec_move2 GLARE
@ win speech
	ec_word YOU_RE
	ec_word MEAN
	ec_word EXCL
	ec_word I
	ec_word MEAN
	ec_word REALLY
@ loss speech
	ec_word YOU
	ec_word HAVE
	ec_word A
	ec_word REALLY
	ec_move1 SCARY_FACE
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Valeria

@ 150
	.4byte TRAINER_CLASS_PKMN_RANGER_2
	.string "DELANEY$", 8
@ pre-battle speech
	ec_word SCHOOL
	ec_word IS
	ec_word OVER
	ec_word TIME
	ec_word TO
	ec_word PLAY
@ win speech
	ec_word MY
	ec_word BOY
	ec_word FRIEND
	ec_word IS
	ec_word FROM
	ec_word SCHOOL
@ loss speech
	ec_word I
	ec_word HAVE
	ec_word TO
	ec_word WORK
	ec_word NEXT
	ec_word WEEK
	.4byte gBattleFrontierTrainerMons_Delaney

@ 151
	.4byte TRAINER_CLASS_PKMN_RANGER_2
	.string "MEGHAN$", 8
@ pre-battle speech
	ec_word SCHOOL
	ec_word IS
	ec_word OUT
	ec_word TIME
	ec_word TO
	ec_word PLAY
@ win speech
	ec_word MY
	ec_word BOY
	ec_word FRIEND
	ec_word LIKES
	ec_word COMICS
	.2byte -1
@ loss speech
	ec_word IT_S
	ec_word BACK
	ec_word TO
	ec_word SCHOOL
	ec_word SOON
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Meghan

@ 152
	.4byte TRAINER_CLASS_DRAGON_TAMER
	.string "ROBERTO$", 8
@ pre-battle speech
	ec_word DRAGON
	ec_word POKEMON
	ec_word ARE
	ec_word INVINCIBLE
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word YOU
	ec_word WEREN_T
	ec_word BAD
	ec_word I_WAS
	ec_word JUST
	ec_word BETTER
@ loss speech
	ec_word AREN_T
	ec_word YOU
	ec_word SATISFIED
	ec_word YET
	ec_word QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Roberto

@ 153
	.4byte TRAINER_CLASS_DRAGON_TAMER
	.string "DAMIAN$", 8
@ pre-battle speech
	ec_word MY
	ec_word PURE_POWER
	ec_word IS
	ec_word MACHINE
	ec_word LIKE
	ec_word EXCL
@ win speech
	ec_word MY
	ec_move2 MACH_PUNCH
	ec_word WILL
	ec_word MAKE
	ec_word A
	ec_move1 BRICK_BREAK
@ loss speech
	ec_word ARRGH
	ec_word EXCL
	.2byte -1
	ec_word NO
	ec_word EXCL_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Damian

@ 154
	.4byte TRAINER_CLASS_DRAGON_TAMER
	.string "BRODY$", 8
@ pre-battle speech
	ec_word MY
	ec_word FASHION
	ec_word SENSE
	ec_word SEEMS
	ec_pokemon1 ODDISH
	ec_word QUES
@ win speech
	ec_word IT_S
	ec_word MY
	ec_word FAMILY
	ec_word STAY_AT_HOME
	ec_word LOOK
	ec_word EXCL
@ loss speech
	ec_word I
	ec_word QUESTION
	ec_word YOUR
	ec_word FASHION
	ec_word SENSE
	ec_word SERIOUSLY
	.4byte gBattleFrontierTrainerMons_Brody

@ 155
	.4byte TRAINER_CLASS_DRAGON_TAMER
	.string "GRAHAM$", 8
@ pre-battle speech
	ec_word YEAH
	ec_word EXCL
	.2byte -1
	ec_word YEAH_YEAH
	ec_word EXCL_EXCL
	.2byte -1
@ win speech
	ec_word WAHAHAHA
	ec_word WAHAHAHA
	ec_word EXCL
	ec_word WAHAHAHA
	ec_word WAHAHAHA
	ec_word EXCL_EXCL
@ loss speech
	ec_word I_AM
	ec_word SORRY
	ec_word ELLIPSIS
	ec_word IT_S
	ec_word MY
	ec_word BAD
	.4byte gBattleFrontierTrainerMons_Graham

@ 156
	.4byte TRAINER_CLASS_POKEFAN_1
	.string "TYLOR$", 8
@ pre-battle speech
	ec_word ARE
	ec_word YOU
	ec_word FEELING
	ec_word MY
	ec_move2 HEAT_WAVE
	ec_word QUES
@ win speech
	ec_word YES
	ec_word I_AM
	ec_word ON
	ec_word FIRE
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word BUT
	ec_word I_WAS
	ec_word ON
	ec_word FIRE
	ec_word FOR
	ec_word YOU
	.4byte gBattleFrontierTrainerMons_Tylor

@ 157
	.4byte TRAINER_CLASS_POKEFAN_2
	.string "JAREN$", 8
@ pre-battle speech
	ec_word FIGHTING
	ec_word SPIRIT
	ec_word QUES
	ec_word ME
	ec_word QUES
	.2byte -1
@ win speech
	ec_word I
	ec_word WANT
	ec_word MORE
	ec_word CUTE
	ec_word POKEMON
	.2byte -1
@ loss speech
	ec_word YOUR
	ec_word POKEMON
	ec_word LOOK
	ec_word QUITE
	ec_word CUTE
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Jaren

@ 158
	.4byte TRAINER_CLASS_PKMN_BREEDER_2
	.string "CORDELL$", 8
@ pre-battle speech
	ec_word A
	ec_word BATTLE
	ec_word IS
	ec_word DECIDED
	ec_word ON
	ec_word SPIRIT
@ win speech
	ec_word CAN_T
	ec_word YOU
	ec_word ACCEPT
	ec_word THAT
	ec_word QUES
	.2byte -1
@ loss speech
	ec_word I
	ec_word WILL
	ec_word BE
	ec_word ON
	ec_word MY
	ec_word WAY
	.4byte gBattleFrontierTrainerMons_Cordell

@ 159
	.4byte TRAINER_CLASS_PKMN_BREEDER_1
	.string "JAZLYN$", 8
@ pre-battle speech
	ec_word IS
	ec_word YOUR
	ec_word POKEDEX
	ec_word REALLY
	ec_word AWESOME
	ec_word QUES
@ win speech
	ec_word OH_YEAH
	ec_word WOW
	ec_word YOUR
	ec_word POKEDEX
	ec_word IS
	ec_word SUPER
@ loss speech
	ec_word AN
	ec_word AVANT_GARDE
	ec_word POKEDEX
	ec_word WOULD
	ec_word BE
	ec_word AWESOME
	.4byte gBattleFrontierTrainerMons_Jazlyn

@ 160
	.4byte TRAINER_CLASS_YOUNGSTER
	.string "ZACHERY$", 8
@ pre-battle speech
	ec_word I
	ec_word HAVE
	ec_word MY
	ec_word OWN
	ec_word PLACE
	ec_word YEEHAW_EXCL
@ win speech
	ec_word IT_S
	ec_word AN
	ec_word EXCITING
	ec_word TIME
	ec_word FOR
	ec_word ME
@ loss speech
	ec_word YOU
	ec_word CAN_T
	ec_word FLATTEN
	ec_word MY
	ec_word HAPPINESS
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Zachery

@ 161
	.4byte TRAINER_CLASS_YOUNGSTER
	.string "JOHAN$", 8
@ pre-battle speech
	ec_word WINTER
	ec_word WILL
	ec_word SOON
	ec_word BE
	ec_word HERE
	.2byte -1
@ win speech
	ec_word MY
	ec_word ALLOWANCE
	ec_word COULD
	ec_word USE
	ec_word A
	ec_move2 HELPING_HAND
@ loss speech
	ec_word I
	ec_word ALWAYS
	ec_word USE
	ec_word MY
	ec_word ALLOWANCE
	ec_word UP
	.4byte gBattleFrontierTrainerMons_Johan

@ 162
	.4byte TRAINER_CLASS_LASS
	.string "SHEA$", 8
@ pre-battle speech
	ec_word DO
	ec_word YOU
	ec_word BATTLE
	ec_word WITH
	ec_word BEAUTY
	ec_word QUES
@ win speech
	ec_word YOU
	ec_word BATTLE
	ec_word IN
	ec_word AN
	ec_word UGLY
	ec_word WAY
@ loss speech
	ec_word WHAT
	ec_word IS
	ec_word BEAUTY
	ec_word TO
	ec_word YOU
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Shea

@ 163
	.4byte TRAINER_CLASS_LASS
	.string "KAILA$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word FEELING
	ec_word THIRSTY
	ec_word RIGHT
	ec_word NOW
	ec_word ELLIPSIS
@ win speech
	ec_word I
	ec_word COULD
	ec_word USE
	ec_word A
	ec_word COLD
	ec_word DRINK
@ loss speech
	ec_word THAT
	ec_word LOSS
	ec_word IS
	ec_word HARD
	ec_word TO
	ec_move2 SWALLOW
	.4byte gBattleFrontierTrainerMons_Kaila

@ 164
	.4byte TRAINER_CLASS_SCHOOL_KID_1
	.string "ISIAH$", 8
@ pre-battle speech
	ec_word I
	ec_word PRETEND
	ec_word TO
	ec_word STUDY
	ec_word A_LOT
	.2byte -1
@ win speech
	ec_word I
	ec_move2 TRICK
	ec_word MOTHER
	ec_word FOR
	ec_word MY
	ec_word ALLOWANCE
@ loss speech
	ec_word I
	ec_word DON_T
	ec_word WANT
	ec_word TO
	ec_word STUDY
	ec_word MORE
	.4byte gBattleFrontierTrainerMons_Isiah

@ 165
	.4byte TRAINER_CLASS_SCHOOL_KID_1
	.string "GARRETT$", 8
@ pre-battle speech
	ec_word I
	ec_word ENJOY
	ec_word COMICS
	ec_word AND
	ec_word THIS
	ec_word GAME
@ win speech
	ec_word I
	ec_word LIKE
	ec_word THIS
	ec_word MUSIC
	ec_word IDOL
	ec_word TOO
@ loss speech
	ec_word BUT
	ec_word I
	ec_word HAVE
	ec_word TO
	ec_word STUDY
	ec_word MORE
	.4byte gBattleFrontierTrainerMons_Garrett

@ 166
	.4byte TRAINER_CLASS_SCHOOL_KID_2
	.string "HAYLIE$", 8
@ pre-battle speech
	ec_word I
	ec_word WORRY
	ec_word TOO
	ec_word MUCH
	ec_word TO
	ec_word SLEEP
@ win speech
	ec_word A
	ec_word WIN
	ec_word GIVES
	ec_word ME
	ec_word A
	ec_move2 CALM_MIND
@ loss speech
	ec_word MY
	ec_word INSOMNIA
	ec_word WILL
	ec_word GET
	ec_word BAD
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Haylie

@ 167
	.4byte TRAINER_CLASS_SCHOOL_KID_2
	.string "MEGAN$", 8
@ pre-battle speech
	ec_word I
	ec_word BELIEVE
	ec_word IN
	ec_word AN
	ec_move1 AROMATHERAPY
	ec_word BATH
@ win speech
	ec_word I
	ec_word WANT
	ec_word A
	ec_word HEALTHY
	ec_word CLEAR_BODY
	.2byte -1
@ loss speech
	ec_word IF
	ec_word ONLY
	ec_move1 AROMATHERAPY
	ec_word WERE
	ec_word LESS
	ec_word EXPENSIVE
	.4byte gBattleFrontierTrainerMons_Megan

@ 168
	.4byte TRAINER_CLASS_RICH_BOY
	.string "ISSAC$", 8
@ pre-battle speech
	ec_word MY
	ec_word HOBBY
	ec_word QUES
	.2byte -1
	.2byte -1
	.2byte -1
@ win speech
	ec_word I
	ec_word LIKE
	ec_word ANY
	ec_word KIND
	ec_word OF
	ec_move2 WATER_SPORT
@ loss speech
	ec_word I
	ec_word DISLIKE
	ec_word ANY
	ec_word KIND
	ec_word OF
	ec_move2 MUD_SPORT
	.4byte gBattleFrontierTrainerMons_Issac

@ 169
	.4byte TRAINER_CLASS_RICH_BOY
	.string "QUINTON$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word SAD
	ec_word CAUSE
	ec_word I_AM
	ec_word TOO_WEAK
	.2byte -1
@ win speech
	ec_word YOU
	ec_word AREN_T
	ec_word TOO_STRONG
	ec_word FOR
	ec_word ME
	.2byte -1
@ loss speech
	ec_word HEY
	ec_word WHAT
	ec_word DID
	ec_word I
	ec_word DO
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Quinton

@ 170
	.4byte TRAINER_CLASS_LADY
	.string "SALMA$", 8
@ pre-battle speech
	ec_word YOU_VE
	ec_word GOT
	ec_word YOUR
	ec_word HUSTLE
	ec_word ON
	ec_word EXCL
@ win speech
	ec_word I
	ec_word WIN
	ec_word YOU
	ec_word HUSTLE
	ec_word ON
	ec_word OUT
@ loss speech
	ec_word I
	ec_word DON_T
	ec_word GET
	ec_word HOW
	ec_word I
	ec_word LOST
	.4byte gBattleFrontierTrainerMons_Salma

@ 171
	.4byte TRAINER_CLASS_LADY
	.string "ANSLEY$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word BORED
	ec_word ELLIPSIS
	ec_word DANCE
	ec_word FOR
	ec_word ME
@ win speech
	ec_word YOU_VE
	ec_word BORED
	ec_word ME
	ec_word SOME
	ec_word MORE
	.2byte -1
@ loss speech
	ec_word TAKE
	ec_word YOUR
	ec_move2 FRUSTRATION
	ec_word SOME
	ec_word OTHER
	ec_word PLACE
	.4byte gBattleFrontierTrainerMons_Ansley

@ 172
	.4byte TRAINER_CLASS_BUG_CATCHER
	.string "HOLDEN$", 8
@ pre-battle speech
	ec_word LET_S
	ec_word COMMEMORATE
	ec_word MY
	ec_word COOLNESS
	ec_word IN
	ec_word BATTLE
@ win speech
	ec_word YOU_RE
	ec_word TOO_WEAK
	ec_word FOR
	ec_word ANY
	ec_word PRAISE
	.2byte -1
@ loss speech
	ec_word YOUR
	ec_word BATTLE
	ec_word SENSE
	ec_word IS
	ec_word AMUSING
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Holden

@ 173
	.4byte TRAINER_CLASS_BUG_CATCHER
	.string "LUCA$", 8
@ pre-battle speech
	ec_word WE
	ec_word WILL
	ec_word HAVE
	ec_word A
	ec_word COOL
	ec_word BATTLE
@ win speech
	ec_word I
	ec_word WON
	ec_word IN
	ec_word A
	ec_word COOL
	ec_word WAY
@ loss speech
	ec_word HELLO
	ec_word QUES
	ec_word I_AM
	ec_word JUST
	ec_word A
	ec_word KID
	.4byte gBattleFrontierTrainerMons_Luca

@ 174
	.4byte TRAINER_CLASS_NINJA_BOY
	.string "JAMISON$", 8
@ pre-battle speech
	ec_word MY
	ec_move2 SECRET_POWER
	ec_word IS
	ec_word OVERWHELMING
	ec_word TO
	ec_word POKEMON
@ win speech
	ec_word DID
	ec_word YOU
	ec_word SEE
	ec_word THAT
	ec_word QUES
	.2byte -1
@ loss speech
	ec_word I
	ec_word WILL
	ec_word USE
	ec_move1 SMOKESCREEN
	ec_word TO
	ec_word ESCAPE
	.4byte gBattleFrontierTrainerMons_Jamison

@ 175
	.4byte TRAINER_CLASS_NINJA_BOY
	.string "GUNNAR$", 8
@ pre-battle speech
	ec_word I
	ec_move1 CUT
	ec_word DOWN
	ec_word EVERY
	ec_word OPPONENT
	.2byte -1
@ win speech
	ec_word DON_T
	ec_move1 GRUDGE
	ec_word ME
	ec_word FOR
	ec_word YOUR
	ec_word LOSS
@ loss speech
	ec_word PLEASE
	ec_word LOSE
	ec_word THAT
	ec_move1 SCARY_FACE
	ec_word OF
	ec_word YOURS
	.4byte gBattleFrontierTrainerMons_Gunnar

@ 176
	.4byte TRAINER_CLASS_TUBER_2
	.string "CRAIG$", 8
@ pre-battle speech
	ec_word I
	ec_word CAN_T
	ec_word WAIT
	ec_word FOR
	ec_word MY
	ec_word TRAIN
@ win speech
	ec_word MY
	ec_word TRAIN
	ec_word ISN_T
	ec_word HERE
	ec_word YET
	ec_word ELLIPSIS
@ loss speech
	ec_word HERE_IT_IS
	ec_word MY
	ec_word TRAIN
	ec_word SEE_YA
	ec_word EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Craig

@ 177
	.4byte TRAINER_CLASS_TUBER_2
	.string "PIERCE$", 8
@ pre-battle speech
	ec_word THERE
	ec_word WAS
	ec_word A
	ec_move2 HEAT_WAVE
	ec_word LAST
	ec_word WEEK
@ win speech
	ec_word I
	ec_word CAN_T
	ec_word TAKE
	ec_word A
	ec_move2 HEAT_WAVE
	.2byte -1
@ loss speech
	ec_word DIDN_T
	ec_word IT
	ec_move1 HAIL
	ec_word TOO
	ec_word QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Pierce

@ 178
	.4byte TRAINER_CLASS_TUBER_1
	.string "REGINA$", 8
@ pre-battle speech
	ec_word I
	ec_word LIKE
	ec_word TO
	ec_word PLAY
	ec_word IN
	ec_word WATER
@ win speech
	ec_word I
	ec_word REFUSE
	ec_word TO
	ec_word COME
	ec_word OUT
	.2byte -1
@ loss speech
	ec_word YOU_RE
	ec_word NOT
	ec_word MUCH
	ec_word GOOD
	ec_word IN
	ec_word WATER
	.4byte gBattleFrontierTrainerMons_Regina

@ 179
	.4byte TRAINER_CLASS_TUBER_1
	.string "ALISON$", 8
@ pre-battle speech
	ec_word THIS
	ec_word KINDERGARTEN
	ec_word MAGAZINE
	ec_word IS
	ec_word TOO
	ec_word MUCH
@ win speech
	ec_word HOW
	ec_word TO
	ec_word BUG
	ec_word YOUR
	ec_word TEACHER
	ec_word QUES
@ loss speech
	ec_word ENJOY
	ec_word A
	ec_word TASTY
	ec_word SCHOOL
	ec_word DIET
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Alison

@ 180
	.4byte TRAINER_CLASS_BUG_MANIAC
	.string "HANK$", 8
@ pre-battle speech
	ec_word THERE
	ec_word IS
	ec_word A
	ec_word BUG
	ec_word EVENT
	ec_word SOON
@ win speech
	ec_word IT_S
	ec_word A
	ec_word BUG
	ec_word FASHION
	ec_word SHOW
	ec_word EXCL
@ loss speech
	ec_word DON_T
	ec_word YOU
	ec_word LIKE
	ec_word BUG
	ec_word POKEMON
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Hank

@ 181
	.4byte TRAINER_CLASS_BUG_MANIAC
	.string "EARL$", 8
@ pre-battle speech
	ec_word THE
	ec_word INVINCIBLE
	ec_word BUG
	ec_word TRAINER
	ec_word IS
	ec_word HERE
@ win speech
	ec_word THE
	ec_word INVINCIBLE
	ec_word BUG
	ec_word TRAINER
	ec_word AM
	ec_word I
@ loss speech
	ec_word SEE
	ec_word HOW
	ec_word FAST
	ec_word I
	ec_word RUN_AWAY
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Earl

@ 182
	.4byte TRAINER_CLASS_FISHERMAN
	.string "RAMIRO$", 8
@ pre-battle speech
	ec_word I
	ec_word WENT
	ec_word TO
	ec_word A
	ec_word FISHING
	ec_word SCHOOL
@ win speech
	ec_word SERIOUSLY
	ec_word I_AM
	ec_word IN
	ec_word THE
	ec_word FISHING
	ec_word HALL_OF_FAME
@ loss speech
	ec_word I
	ec_word WANT
	ec_word TO
	ec_word GO
	ec_word BACK
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Ramiro

@ 183
	.4byte TRAINER_CLASS_FISHERMAN
	.string "HUNTER$", 8
@ pre-battle speech
	ec_word SHOW
	ec_word ME
	ec_word A
	ec_word TOTALLY
	ec_word COOL
	ec_move1 CROSS_CHOP
@ win speech
	ec_word YOU_RE
	ec_word TOO_WEAK
	ec_word TO
	ec_word DO
	ec_word A
	ec_move1 CROSS_CHOP
@ loss speech
	ec_word WAS
	ec_word IT
	ec_word A
	ec_word MISTAKE
	ec_word QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Hunter

@ 184
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.string "AIDEN$", 8
@ pre-battle speech
	ec_word MY
	ec_word WORK
	ec_word IS
	ec_word MAKING
	ec_word ME
	ec_word HEALTHY
@ win speech
	ec_word YOU
	ec_word SEE
	ec_word QUES
	ec_word I_AM
	ec_word HEALTHY
	ec_word EXCL
@ loss speech
	ec_word YOU_RE
	ec_word MORE
	ec_word HEALTHY
	ec_word THAN
	ec_word I_AM
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Aiden

@ 185
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.string "XAVIER$", 8
@ pre-battle speech
	ec_word HEY_THERE
	ec_word EXCL
	.2byte -1
	ec_word LOOK
	ec_word LOOK
	ec_word EXCL_EXCL
@ win speech
	ec_word GOOD_BYE
	ec_word AND
	ec_word THANK_YOU
	ec_word THAT_WAS
	ec_word FUNNY
	.2byte -1
@ loss speech
	ec_word WOWEE
	ec_word EXCL
	.2byte -1
	ec_word NO
	ec_word NO
	ec_word EXCL_EXCL
	.4byte gBattleFrontierTrainerMons_Xavier

@ 186
	.4byte TRAINER_CLASS_COLLECTOR
	.string "CLINTON$", 8
@ pre-battle speech
	ec_word WANT
	ec_word TO
	ec_word SEE
	ec_word MY
	ec_move1 HYPNOSIS
	ec_word QUES
@ win speech
	ec_word YOUR
	ec_move2 FURY_SWIPES
	ec_word YOUR
	ec_move1 STRENGTH
	ec_word YOUNG
	ec_word TRAINER
@ loss speech
	ec_word TCH
	ec_word ELLIPSIS
	.2byte -1
	ec_word I_AM
	ec_word TOO_WEAK
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Clinton

@ 187
	.4byte TRAINER_CLASS_COLLECTOR
	.string "JESSE$", 8
@ pre-battle speech
	ec_word THIS
	ec_word BATTLE
	ec_word IS
	ec_word FOR
	ec_word MY
	ec_word MOTHER
@ win speech
	ec_word MOTHER
	ec_word WILL
	ec_word BE
	ec_word HAPPY
	ec_word FOR
	ec_word ME
@ loss speech
	ec_word I
	ec_word WANT
	ec_word MY
	ec_word MOTHER
	ec_word EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Jesse

@ 188
	.4byte TRAINER_CLASS_GUITARIST
	.string "EDUARDO$", 8
@ pre-battle speech
	ec_word OUR
	ec_word MUSIC
	ec_word WILL
	ec_word PLAY
	ec_word ALL
	ec_word NIGHT
@ win speech
	ec_word NIGHTTIME
	ec_word IS
	ec_word WHEN
	ec_word I
	ec_word PLAY
	ec_word BEST
@ loss speech
	ec_word LET_S
	ec_word PARTY
	ec_word UNTIL
	ec_word THE
	ec_move1 MORNING_SUN
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Eduardo

@ 189
	.4byte TRAINER_CLASS_GUITARIST
	.string "HAL$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word TRENDY
	ec_word AREN_T
	ec_word I
	ec_word QUES
	.2byte -1
@ win speech
	ec_word I_AM
	ec_word FEELING
	ec_word HIP_AND
	ec_word HAPPENING
	ec_word OH_YEAH
	ec_word EXCL
@ loss speech
	ec_word I_AM
	ec_word ALWAYS
	ec_word TRENDY
	ec_word THANK_YOU
	ec_word VERY
	ec_word MUCH
	.4byte gBattleFrontierTrainerMons_Hal

@ 190
	.4byte TRAINER_CLASS_BIRD_KEEPER
	.string "GAGE$", 8
@ pre-battle speech
	ec_word HERE_IT_IS
	ec_word A
	ec_word FLYING
	ec_word TYPE
	ec_word HIDDEN
	ec_word MOVE
@ win speech
	ec_word IT_S
	ec_word A
	ec_word FLYING
	ec_word TYPE
	ec_word VICTORY
	ec_word EXCL
@ loss speech
	ec_word IF_I_LOSE
	ec_word I
	ec_word JUST
	ec_move1 FLY
	ec_word AWAY
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Gage

@ 191
	.4byte TRAINER_CLASS_BIRD_KEEPER
	.string "ARNOLD$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word FEELING
	ec_word WEIRD
	ec_word FROM
	ec_word A
	ec_word DREAM
@ win speech
	ec_word YOUR
	ec_move1 SCARY_FACE
	ec_word WAS
	ec_word IN
	ec_word MY
	ec_word DREAM
@ loss speech
	ec_word MY
	ec_word INCREDIBLE
	ec_word DREAM
	ec_word WAS
	ec_word SO
	ec_word WEIRD
	.4byte gBattleFrontierTrainerMons_Arnold

@ 192
	.4byte TRAINER_CLASS_SAILOR
	.string "JARRETT$", 8
@ pre-battle speech
	ec_word COME_ON
	ec_word LET_S
	ec_word DANCE
	ec_word LIKE
	ec_word IT_S
	ec_word YESTERDAY
@ win speech
	ec_word YOU
	ec_word LIKE
	ec_word HOW
	ec_word I
	ec_word DANCE
	ec_word QUES
@ loss speech
	ec_word YOU
	ec_word DON_T
	ec_word APPRECIATE
	ec_word HOW
	ec_word I
	ec_word DANCE
	.4byte gBattleFrontierTrainerMons_Jarrett

@ 193
	.4byte TRAINER_CLASS_SAILOR
	.string "GARETT$", 8
@ pre-battle speech
	ec_word MY
	ec_word GIRL
	ec_word GIVES
	ec_word ME
	ec_word A_LITTLE
	ec_move2 SWEET_KISS
@ win speech
	ec_word MY
	ec_word GIRL
	ec_word FRIEND
	ec_word IS
	ec_word MY
	ec_word TREASURE
@ loss speech
	ec_word A
	ec_word TREASURE
	ec_word ISN_T
	ec_word ALWAYS
	ec_word ABOUT
	ec_word MONEY
	.4byte gBattleFrontierTrainerMons_Garett

@ 194
	.4byte TRAINER_CLASS_HIKER
	.string "EMANUEL$", 8
@ pre-battle speech
	ec_word SMARTNESS
	ec_word ALONE
	ec_word WON_T
	ec_word MAKE
	ec_word YOU
	ec_word WIN
@ win speech
	ec_word I_AM
	ec_word NOT_VERY
	ec_word SMART
	ec_word BUT
	ec_word I
	ec_word WON
@ loss speech
	ec_word HOW
	ec_word DID
	ec_word YOU
	ec_move2 FAKE_OUT
	ec_word ME
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Emanuel

@ 195
	.4byte TRAINER_CLASS_HIKER
	.string "GUSTAVO$", 8
@ pre-battle speech
	ec_move1 CHARGE
	ec_word EXCL
	.2byte -1
	ec_move1 CHARGE
	ec_word EXCL_EXCL
	.2byte -1
@ win speech
	ec_word SURRENDER
	ec_word QUES
	.2byte -1
	ec_word SO
	ec_word SOON
	ec_word QUES
@ loss speech
	ec_word YOU
	ec_word CAN_T
	ec_word MAKE
	ec_word ME
	ec_word SURRENDER
	ec_word YET
	.4byte gBattleFrontierTrainerMons_Gustavo

@ 196
	.4byte TRAINER_CLASS_KINDLER
	.string "KAMERON$", 8
@ pre-battle speech
	ec_word TAKE_THAT
	ec_word EXCL
	ec_word IT_S
	ec_word MY
	ec_word FIERY
	ec_move2 TRICK
@ win speech
	ec_word DID
	ec_word MY
	ec_word FIERY
	ec_move2 TRICK
	ec_move1 ASTONISH
	ec_word QUES
@ loss speech
	ec_word YOU
	ec_word DIDN_T
	ec_word FALL
	ec_word FOR
	ec_word MY
	ec_move2 TRICK
	.4byte gBattleFrontierTrainerMons_Kameron

@ 197
	.4byte TRAINER_CLASS_KINDLER
	.string "ALFREDO$", 8
@ pre-battle speech
	ec_word A
	ec_word FIERY
	ec_word GOURMET
	ec_word AM
	ec_word I
	ec_word EXCL
@ win speech
	ec_word IT_S
	ec_word A
	ec_word TASTY
	ec_word GOURMET
	ec_word VICTORY
	ec_word EXCL
@ loss speech
	ec_word WHAT
	ec_word A
	ec_word DISASTER
	ec_word THAT_WAS
	ec_word EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Alfredo

@ 198
	.4byte TRAINER_CLASS_GENTLEMAN
	.string "RUBEN$", 8
@ pre-battle speech
	ec_word I
	ec_word CAN_T
	ec_word WAIT
	ec_word TO
	ec_word GET
	ec_word GOING
@ win speech
	ec_word GET
	ec_word GOING
	ec_word EXCL
	ec_word THIS
	ec_word IS
	ec_word GOOD_BYE
@ loss speech
	ec_word I_VE
	ec_word GOT
	ec_word TO
	ec_word GET
	ec_word GOING
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Ruben

@ 199
	.4byte TRAINER_CLASS_GENTLEMAN
	.string "LAMAR$", 8
@ pre-battle speech
	ec_word A
	ec_move2 PRESENT
	ec_word FOR
	ec_word ME
	ec_word QUES
	.2byte -1
@ win speech
	ec_word MMM
	ec_word THIS
	ec_word IS
	ec_word QUITE
	ec_word TASTY
	ec_word ELLIPSIS
@ loss speech
	ec_word OH
	ec_word IT_S
	ec_word A
	ec_word GAME
	ec_word IS_IT_QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Lamar

@ 200
	.4byte TRAINER_CLASS_YOUNGSTER
	.string "JAXON$", 8
@ pre-battle speech
	ec_word A
	ec_word SHELL_ARMOR
	ec_word IS
	ec_word WHAT
	ec_word I
	ec_word WANT
@ win speech
	ec_word MY
	ec_word FATHER
	ec_word AND
	ec_word MOTHER
	ec_word WON_T
	ec_word ACCEPT
@ loss speech
	ec_word PLEASE
	ec_word I
	ec_word NEED
	ec_word A
	ec_word SHELL_ARMOR
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Jaxon

@ 201
	.4byte TRAINER_CLASS_YOUNGSTER
	.string "LOGAN$", 8
@ pre-battle speech
	ec_word IF_I_LOSE
	ec_word I
	ec_word WILL
	ec_word STUDY
	ec_word FOR
	ec_word SCHOOL
@ win speech
	ec_word ME
	ec_word STUDY
	ec_word QUES
	ec_word NOT_VERY
	ec_word LIKELY_TO
	ec_word SEE
@ loss speech
	ec_word NO
	ec_word THANKS
	ec_word I_AM
	ec_word GOING
	ec_word TO
	ec_word SLEEP
	.4byte gBattleFrontierTrainerMons_Logan

@ 202
	.4byte TRAINER_CLASS_LASS
	.string "EMILEE$", 8
@ pre-battle speech
	ec_word IS
	ec_word THIS
	ec_word KIND
	ec_word OF
	ec_word BATTLE
	ec_word OK_QUES
@ win speech
	ec_word LET_S
	ec_word GO
	ec_word FOR
	ec_word AN
	ec_move1 ICY_WIND
	ec_move2 SURF
@ loss speech
	ec_word HOW
	ec_word ABOUT
	ec_word A
	ec_move1 ROCK_SLIDE
	ec_word SHOW
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Emilee

@ 203
	.4byte TRAINER_CLASS_LASS
	.string "JOSIE$", 8
@ pre-battle speech
	ec_word A
	ec_word POKEMON
	ec_word FASHION
	ec_word CONTEST
	ec_word IS
	ec_word PRETTY
@ win speech
	ec_word I
	ec_word REALLY
	ec_word LIKE
	ec_word MODE
	ec_word FASHION
	ec_word THINGS
@ loss speech
	ec_word YOU_RE
	ec_word TOTALLY
	ec_word LACKING
	ec_word IN
	ec_word FASHION
	ec_word SENSE
	.4byte gBattleFrontierTrainerMons_Josie

@ 204
	.4byte TRAINER_CLASS_CAMPER
	.string "ARMANDO$", 8
@ pre-battle speech
	ec_word I
	ec_word NEED
	ec_word MORE
	ec_word GRASS
	ec_word TYPE
	ec_word POKEMON
@ win speech
	ec_word TRADE
	ec_word ME
	ec_word A
	ec_word GRASS
	ec_word POKEMON
	ec_word PLEASE
@ loss speech
	ec_word THERE
	ec_word AREN_T
	ec_word ENOUGH
	ec_word GRASS
	ec_word TYPE
	ec_word POKEMON
	.4byte gBattleFrontierTrainerMons_Armando

@ 205
	.4byte TRAINER_CLASS_CAMPER
	.string "SKYLER$", 8
@ pre-battle speech
	ec_move2 INGRAIN
	ec_word IS
	ec_word MY
	ec_word CHOICE
	ec_word BATTLE
	ec_word MOVE
@ win speech
	ec_word YOU
	ec_word CAN_T
	ec_word MOVE
	ec_word ME
	ec_word NOW
	ec_word EXCL
@ loss speech
	ec_word YOU
	ec_move1 CUT
	ec_word ME
	ec_word DOWN
	ec_word ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Skyler

@ 206
	.4byte TRAINER_CLASS_PICNICKER
	.string "RUTH$", 8
@ pre-battle speech
	ec_word I
	ec_word WANT
	ec_word TO
	ec_word ENJOY
	ec_word THIS
	ec_word BATTLE
@ win speech
	ec_word THAT_WAS
	ec_word MUCH
	ec_word TOO
	ec_word EASY
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word PLEASE
	ec_word STOP
	ec_word I
	ec_word DON_T
	ec_word ENJOY
	ec_word THIS
	.4byte gBattleFrontierTrainerMons_Ruth

@ 207
	.4byte TRAINER_CLASS_PICNICKER
	.string "MELODY$", 8
@ pre-battle speech
	ec_word I
	ec_move2 WISH
	ec_word SUNDAY
	ec_word IS
	ec_word A
	ec_move2 SUNNY_DAY
@ win speech
	ec_word SUNDAY
	ec_word SEEMS
	ec_word FOREVER
	ec_word TO
	ec_word COME
	ec_word ELLIPSIS
@ loss speech
	ec_word THE
	ec_word FORECAST
	ec_word SAYS
	ec_word IT
	ec_word WILL
	ec_move1 HAIL
	.4byte gBattleFrontierTrainerMons_Melody

@ 208
	.4byte TRAINER_CLASS_SWIMMER_M
	.string "PEDRO$", 8
@ pre-battle speech
	ec_word A
	ec_word SWIFT_SWIM
	ec_word WILL
	ec_word DO
	ec_word YOU
	ec_word GOOD
@ win speech
	ec_word THAT_S
	ec_word HOW
	ec_word I
	ec_word SINK
	ec_word AN
	ec_word OPPONENT
@ loss speech
	ec_word UH_OH
	ec_word EXCL
	.2byte -1
	ec_word A
	ec_move1 WHIRLPOOL
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Pedro

@ 209
	.4byte TRAINER_CLASS_SWIMMER_M
	.string "ERICK$", 8
@ pre-battle speech
	ec_word I
	ec_word WILL
	ec_move2 TACKLE
	ec_word YOU
	ec_word DOWN
	ec_word EXCL
@ win speech
	ec_word DON_T
	ec_word YOU
	ec_word RUN_AWAY
	ec_word YOU
	ec_word LOSER
	ec_word EXCL
@ loss speech
	ec_word I
	ec_word DIDN_T
	ec_word THINK
	ec_word YOU
	ec_word WOULD
	ec_move1 COUNTER
	.4byte gBattleFrontierTrainerMons_Erick

@ 210
	.4byte TRAINER_CLASS_SWIMMER_F
	.string "ELAINE$", 8
@ pre-battle speech
	ec_word MY
	ec_word HEROINE
	ec_word ADVENTURE
	ec_word ISN_T
	ec_word GOING
	ec_word WELL
@ win speech
	ec_word THANK_YOU
	ec_word EXCL
	ec_word THAT_S
	ec_word WHAT
	ec_word I
	ec_word NEED
@ loss speech
	ec_word I
	ec_word KNOW
	ec_word I_AM
	ec_word NOT
	ec_word A
	ec_word HEROINE
	.4byte gBattleFrontierTrainerMons_Elaine

@ 211
	.4byte TRAINER_CLASS_SWIMMER_F
	.string "JOYCE$", 8
@ pre-battle speech
	ec_word YOU
	ec_word MAKE
	ec_word ME
	ec_word GO
	ec_word AHAHA
	ec_word EXCL
@ win speech
	ec_word LALALA
	ec_word NO
	ec_word LOSING
	ec_word FOR
	ec_word ME
	ec_word EXCL
@ loss speech
	ec_word LALALA
	ec_word ELLIPSIS
	.2byte -1
	ec_word HUH_QUES
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Joyce

@ 212
	.4byte TRAINER_CLASS_POKEFAN_1
	.string "TODD$", 8
@ pre-battle speech
	ec_word YOU_RE
	ec_word A
	ec_word LIGHTNINGROD
	ec_word FOR
	ec_word MY
	ec_word POWER
@ win speech
	ec_word THAT_S
	ec_word ALL
	ec_word YOU
	ec_word COULD
	ec_move1 ABSORB
	ec_word QUES
@ loss speech
	ec_word YOU
	ec_move2 REFLECT
	ec_word MY
	ec_word POWER
	ec_word BACK
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Todd

@ 213
	.4byte TRAINER_CLASS_POKEFAN_1
	.string "GAVIN$", 8
@ pre-battle speech
	ec_word I
	ec_word WILL
	ec_move1 BIDE
	ec_word MY
	ec_word TIME
	.2byte -1
@ win speech
	ec_word IT_S
	ec_word OVER
	ec_word SO
	ec_word SOON
	ec_word QUES
	.2byte -1
@ loss speech
	ec_word MY
	ec_word MISTAKE
	ec_word WAS
	ec_word TOO
	ec_word EXPENSIVE
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Gavin

@ 214
	.4byte TRAINER_CLASS_POKEFAN_2
	.string "MALORY$", 8
@ pre-battle speech
	ec_word PROMISE
	ec_word TO
	ec_word SHOW
	ec_word ME
	ec_word CUTE
	ec_word POKEMON
@ win speech
	ec_word GIGGLE
	ec_word ELLIPSIS
	.2byte -1
	ec_word THANK_YOU
	ec_word SO
	ec_word MUCH
@ loss speech
	ec_word TCH
	ec_word YOUR
	ec_word POKEMON
	ec_word AREN_T
	ec_word VERY
	ec_word NICE
	.4byte gBattleFrontierTrainerMons_Malory

@ 215
	.4byte TRAINER_CLASS_POKEFAN_2
	.string "ESTHER$", 8
@ pre-battle speech
	ec_word I
	ec_word WANT
	ec_word A
	ec_word NICE
	ec_move2 PRESENT
	ec_word ELLIPSIS
@ win speech
	ec_word PLEASE
	ec_word GET
	ec_word ME
	ec_word A
	ec_word POKEMON
	ec_word GAME
@ loss speech
	ec_word MESSAGE
	ec_word CARDS
	ec_word MAKE
	ec_word A
	ec_word WEAK
	ec_move2 PRESENT
	.4byte gBattleFrontierTrainerMons_Esther

@ 216
	.4byte TRAINER_CLASS_PKMN_BREEDER_2
	.string "OSCAR$", 8
@ pre-battle speech
	ec_word LET_S
	ec_word SEE
	ec_word YOUR
	ec_word POWER
	ec_word IN
	ec_word FULL
@ win speech
	ec_word THAT_WAS
	ec_word NOT
	ec_word YOUR
	ec_word FULL
	ec_word POWER
	ec_word EXCL
@ loss speech
	ec_word NOT
	ec_word FUNNY
	ec_word ELLIPSIS
	ec_word YOU_RE
	ec_word TOO_STRONG
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Oscar

@ 217
	.4byte TRAINER_CLASS_PKMN_BREEDER_2
	.string "WILSON$", 8
@ pre-battle speech
	ec_word WORK
	ec_word IS
	ec_word MAKING
	ec_word ME
	ec_word AN
	ec_word EARLY_BIRD
@ win speech
	ec_word ALL
	ec_word WORK
	ec_word AND
	ec_word NO
	ec_word PLAY
	ec_word ELLIPSIS
@ loss speech
	ec_move1 ENDURE
	ec_word IS
	ec_word ALL
	ec_word I
	ec_word CAN
	ec_word DO
	.4byte gBattleFrontierTrainerMons_Wilson

@ 218
	.4byte TRAINER_CLASS_PKMN_BREEDER_1
	.string "CLARE$", 8
@ pre-battle speech
	ec_word YAY
	ec_word EXCL
	ec_word A
	ec_word TOUGH
	ec_word TRAINER
	ec_word EXCL
@ win speech
	ec_word AWW
	ec_word EXCL
	ec_word A
	ec_word WIMPY
	ec_word TRAINER
	ec_word EXCL
@ loss speech
	ec_word COOL
	ec_word EXCL
	ec_word A
	ec_word GENIUS
	ec_word TRAINER
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Clare

@ 219
	.4byte TRAINER_CLASS_PKMN_BREEDER_1
	.string "TESS$", 8
@ pre-battle speech
	ec_word WANT
	ec_word SOME
	ec_pokemon1 GULPIN
	ec_word DESIGN
	ec_word SWEETS
	ec_word QUES
@ win speech
	ec_word THEY_RE
	ec_word A
	ec_word SECRET
	ec_word POKEMON
	ec_word GOURMET
	ec_word ITEM
@ loss speech
	ec_word THEY_RE
	ec_word TASTY
	ec_word EXCL
	ec_word REFRESHING
	ec_word TOO
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Tess

@ 220
	.4byte TRAINER_CLASS_COOLTRAINER_1
	.string "LEON$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word BETTER
	ec_word THAN
	ec_word ANY
	ec_word OTHER
	ec_word TRAINER
@ win speech
	ec_word I
	ec_word DID
	ec_word IT
	ec_move2 JUMP_KICK
	ec_word FOR
	ec_word JOY
@ loss speech
	ec_word BACK
	ec_word HOME
	ec_word I
	ec_word WILL
	ec_word GO
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Leon

@ 221
	.4byte TRAINER_CLASS_COOLTRAINER_1
	.string "ALONZO$", 8
@ pre-battle speech
	ec_word I_VE
	ec_word NOT
	ec_word LOST
	ec_word ONCE
	ec_word YET
	ec_word EXCL
@ win speech
	ec_word YOUR
	ec_word SAD
	ec_word LOOK
	ec_word BECOMES
	ec_word YOU
	.2byte -1
@ loss speech
	ec_word I
	ec_word DON_T
	ec_word BELIEVE
	ec_word THIS
	ec_word ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Alonzo

@ 222
	.4byte TRAINER_CLASS_COOLTRAINER_1
	.string "VINCE$", 8
@ pre-battle speech
	ec_word THE
	ec_word TOP
	ec_word TRAINER
	ec_word THAT_S
	ec_word ME
	ec_word EXCL
@ win speech
	ec_word THE
	ec_word TOP
	ec_word RANK
	ec_word BELONGS_TO
	ec_word ME
	ec_word EXCL
@ loss speech
	ec_word I
	ec_word WILL
	ec_word APPEAL
	ec_word THIS
	ec_move1 OUTRAGE
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Vince

@ 223
	.4byte TRAINER_CLASS_COOLTRAINER_1
	.string "BRYON$", 8
@ pre-battle speech
	ec_word MY
	ec_move2 BARRAGE
	ec_word WILL
	ec_move2 SLAM
	ec_word YOU
	ec_word EXCL
@ win speech
	ec_word YOU
	ec_word DIDN_T
	ec_word COUNT_ON
	ec_word ANY
	ec_word LESS
	ec_word QUES
@ loss speech
	ec_word I
	ec_word JUST
	ec_word DON_T
	ec_word GET
	ec_word IT
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Bryon

@ 224
	.4byte TRAINER_CLASS_COOLTRAINER_2
	.string "AVA$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word A
	ec_word TREASURE
	ec_word OF
	ec_word THIS
	ec_word WORLD
@ win speech
	ec_word MY
	ec_word WORLD
	ec_word IS
	ec_word FULL
	ec_word OF
	ec_word WONDER
@ loss speech
	ec_word WHY
	ec_word ARE
	ec_word YOU
	ec_word SO
	ec_word TERRIBLE
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Ava

@ 225
	.4byte TRAINER_CLASS_COOLTRAINER_2
	.string "MIRIAM$", 8
@ pre-battle speech
	ec_word OH
	ec_word A
	ec_word TRAINER
	ec_word WITH
	ec_word A
	ec_move1 SCARY_FACE
@ win speech
	ec_word AHAHA
	ec_word YOU
	ec_word ONLY
	ec_word LOOK
	ec_word SCARY
	ec_word EXCL
@ loss speech
	ec_word AIYEEH
	ec_word EXCL
	ec_word YOU
	ec_word REALLY
	ec_word ARE
	ec_word SCARY
	.4byte gBattleFrontierTrainerMons_Miriam

@ 226
	.4byte TRAINER_CLASS_COOLTRAINER_2
	.string "CARRIE$", 8
@ pre-battle speech
	ec_word I
	ec_word WILL
	ec_word SHOW
	ec_word YOU
	ec_word GUTSY
	ec_word EXCL
@ win speech
	ec_word IT_S
	ec_word ALL
	ec_word ABOUT
	ec_word GUTS
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word OH
	ec_word NO
	ec_word ELLIPSIS
	ec_move1 SELF_DESTRUCT
	ec_word MODE
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Carrie

@ 227
	.4byte TRAINER_CLASS_COOLTRAINER_2
	.string "GILLIAN$", 8
@ pre-battle speech
	ec_word I
	ec_word SEEK
	ec_word A
	ec_word TRULY
	ec_word GREAT
	ec_word BATTLE
@ win speech
	ec_word I
	ec_word NEED
	ec_word A_LOT
	ec_word BETTER
	ec_word BATTLE
	ec_word ELLIPSIS
@ loss speech
	ec_word THAT_WAS
	ec_word A_LITTLE
	ec_word TOO
	ec_word MUCH
	ec_word TO
	ec_word TAKE
	.4byte gBattleFrontierTrainerMons_Gillian2

@ 228
	.4byte TRAINER_CLASS_PKMN_RANGER_1
	.string "TYLER$", 8
@ pre-battle speech
	ec_word YO
	ec_word EXCL
	.2byte -1
	ec_word LET_S
	ec_word GO
	ec_word EXCL_EXCL
@ win speech
	ec_word YO
	ec_word EXCL
	.2byte -1
	ec_word I
	ec_word WON
	ec_word YO
@ loss speech
	ec_word YO
	ec_word EXCL
	.2byte -1
	ec_word I
	ec_word LOST
	ec_word YO
	.4byte gBattleFrontierTrainerMons_Tyler

@ 229
	.4byte TRAINER_CLASS_PKMN_RANGER_1
	.string "CHAZ$", 8
@ pre-battle speech
	ec_word MY
	ec_word POKEMON
	ec_word HAVE
	ec_word TOO
	ec_word MUCH
	ec_word POWER
@ win speech
	ec_word THEY
	ec_word HAVE
	ec_word MORE
	ec_word POWER
	ec_word NOW
	ec_word EXCL
@ loss speech
	ec_word YEAH
	ec_move2 TAKE_DOWN
	ec_word THEIR
	ec_word POWER
	ec_word A_TINY_BIT
	ec_word PLEASE
	.4byte gBattleFrontierTrainerMons_Chaz

@ 230
	.4byte TRAINER_CLASS_PKMN_RANGER_1
	.string "NELSON$", 8
@ pre-battle speech
	ec_word WELL_THEN
	ec_word WILL
	ec_word THIS
	ec_word POKEMON
	ec_word WORK
	ec_word QUES
@ win speech
	ec_word I
	ec_word SEE
	ec_word THAT
	ec_word IT
	ec_word WAS
	ec_word TOO_STRONG
@ loss speech
	ec_word IT
	ec_word DIDN_T
	ec_word MATCH_UP
	ec_word WELL
	ec_word I
	ec_word THINK
	.4byte gBattleFrontierTrainerMons_Nelson

@ 231
	.4byte TRAINER_CLASS_PKMN_RANGER_2
	.string "SHANIA$", 8
@ pre-battle speech
	ec_word ALL
	ec_word MY
	ec_word POKEMON
	ec_word ABSOLUTELY
	ec_word ADORE
	ec_word ME
@ win speech
	ec_word HAPPINESS
	ec_word IS
	ec_word A
	ec_word POKEMON
	ec_word WITH
	ec_word CUTE_CHARM
@ loss speech
	ec_word YOU_RE
	ec_word SO
	ec_word MEAN
	ec_word TO
	ec_word CUTE
	ec_word POKEMON
	.4byte gBattleFrontierTrainerMons_Shania

@ 232
	.4byte TRAINER_CLASS_PKMN_RANGER_2
	.string "STELLA$", 8
@ pre-battle speech
	ec_word I
	ec_word WANT
	ec_word TO
	ec_word SEE
	ec_word YOUR
	ec_word POKEMON
@ win speech
	ec_word WELL
	ec_word AREN_T
	ec_word THEY
	ec_word BORING
	ec_word QUES
	ec_word AHAHA
@ loss speech
	ec_word YOUR
	ec_word POKEMON
	ec_word ARE
	ec_word SOMETHING
	ec_word ELSE
	ec_word ALL_RIGHT
	.4byte gBattleFrontierTrainerMons_Stella

@ 233
	.4byte TRAINER_CLASS_PKMN_RANGER_2
	.string "DORINE$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word YOUNG
	ec_word AND
	ec_word STRONG
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word SEE
	ec_word QUES
	ec_word AREN_T
	ec_word I
	ec_word GOOD
	ec_word QUES
@ loss speech
	ec_word THIS
	ec_word ISN_T
	ec_word WORKING
	ec_word OUT
	ec_word AT
	ec_word ALL
	.4byte gBattleFrontierTrainerMons_Dorine

@ 234
	.4byte TRAINER_CLASS_DRAGON_TAMER
	.string "MADDOX$", 8
@ pre-battle speech
	ec_word DRAGON
	ec_word POKEMON
	ec_word ARE
	ec_word MY
	ec_word NO_1
	ec_word CHOICE
@ win speech
	ec_word IT_S
	ec_word NO
	ec_word SECRET
	ec_word DRAGON
	ec_word POKEMON
	ec_word WIN
@ loss speech
	ec_word DRAGON
	ec_word POKEMON
	ec_word SHOULD
	ec_word NOT
	ec_word LOSE
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Maddox

@ 235
	.4byte TRAINER_CLASS_DRAGON_TAMER
	.string "DAVIN$", 8
@ pre-battle speech
	ec_word LET_S
	ec_word HEAR
	ec_word YOU
	ec_move2 ROAR
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word WROOOAAR_EXCL
	.2byte -1
	.2byte -1
	ec_word VICTORY
	ec_word EXCL_EXCL
	.2byte -1
@ loss speech
	ec_word WROOOAAR_EXCL
	.2byte -1
	.2byte -1
	ec_word WHY
	ec_word QUES_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Davin

@ 236
	.4byte TRAINER_CLASS_DRAGON_TAMER
	.string "TREVON$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word LIVING
	ec_word ONLY
	ec_word WITH
	ec_word DRAGON
	ec_word POKEMON
@ win speech
	ec_word THE
	ec_word WAY
	ec_word I_AM
	ec_word LIVING
	ec_word IS
	ec_word PERFECT
@ loss speech
	ec_word YOU_VE
	ec_word DESTROYED
	ec_word THE
	ec_word WAY
	ec_word I_AM
	ec_word LIVING
	.4byte gBattleFrontierTrainerMons_Trevon

@ 237
	.4byte TRAINER_CLASS_BLACK_BELT
	.string "MATEO$", 8
@ pre-battle speech
	ec_word THIS
	ec_word SHOULD
	ec_word BE
	ec_word OVER
	ec_word SOON
	ec_word ENOUGH
@ win speech
	ec_word WELL
	ec_word THAT
	ec_word DIDN_T
	ec_word TAKE
	ec_word VERY
	ec_word MUCH
@ loss speech
	ec_word I
	ec_word CAN_T
	ec_word LOSE
	ec_word SO
	ec_word SOON
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Mateo

@ 238
	.4byte TRAINER_CLASS_BLACK_BELT
	.string "BRET$", 8
@ pre-battle speech
	ec_word I
	ec_word LIKE
	ec_word ROCK_SOLID
	ec_word POKEMON
	ec_word THE
	ec_word BEST
@ win speech
	ec_word TOUGHNESS
	ec_word IS
	ec_word THE
	ec_word WAY
	ec_word TO
	ec_word GO
@ loss speech
	ec_word I
	ec_word ALSO
	ec_word HAVE
	ec_word A
	ec_word PLUSH_DOLL
	ec_word COLLECTION
	.4byte gBattleFrontierTrainerMons_Bret

@ 239
	.4byte TRAINER_CLASS_BLACK_BELT
	.string "RAUL$", 8
@ pre-battle speech
	ec_word I
	ec_word REJECT
	ec_word EVERY
	ec_word WEAK
	ec_word TRAINER
	.2byte -1
@ win speech
	ec_word HUMPH
	ec_word EXCL
	ec_word ANOTHER
	ec_word WEAK
	ec_word TRAINER
	ec_word ELLIPSIS
@ loss speech
	ec_word THERE
	ec_word IS
	ec_word NOTHING
	ec_word WEAK
	ec_word ABOUT
	ec_word YOU
	.4byte gBattleFrontierTrainerMons_Raul

@ 240
	.4byte TRAINER_CLASS_BATTLE_GIRL
	.string "KAY$", 8
@ pre-battle speech
	ec_word AND
	ec_word YET
	ec_word ANOTHER
	ec_word BATTLE
	ec_word QUES
	.2byte -1
@ win speech
	ec_word I
	ec_word WON
	ec_word BUT
	ec_word I_AM
	ec_word TIRED
	ec_word ELLIPSIS
@ loss speech
	ec_word GOOD
	ec_word IT_S
	ec_word OVER
	ec_word AT
	ec_word LAST
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Kay

@ 241
	.4byte TRAINER_CLASS_BATTLE_GIRL
	.string "ELENA$", 8
@ pre-battle speech
	ec_word A
	ec_word BATTLE
	ec_word GIRL
	ec_word THAT_S
	ec_word ME
	ec_word EXCL
@ win speech
	ec_word ISN_T
	ec_word A
	ec_word BATTLE
	ec_word GIRL
	ec_word AWESOME
	ec_word QUES
@ loss speech
	ec_word YOU
	ec_word DISLIKE
	ec_word A
	ec_word BATTLE
	ec_word GIRL
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Elena

@ 242
	.4byte TRAINER_CLASS_BATTLE_GIRL
	.string "ALANA$", 8
@ pre-battle speech
	ec_word EAT
	ec_word MY
	ec_word INVINCIBLE
	ec_word ATTACK
	ec_word YOU
	ec_word EXCL
@ win speech
	ec_word YOU
	ec_word HAVE
	ec_word MUCH
	ec_word TO
	ec_word LEARN
	.2byte -1
@ loss speech
	ec_word SO
	ec_word MUCH
	ec_word FOR
	ec_word MY
	ec_word INVINCIBLE
	ec_word ATTACK
	.4byte gBattleFrontierTrainerMons_Alana

@ 243
	.4byte TRAINER_CLASS_EXPERT_1
	.string "ALEXAS$", 8
@ pre-battle speech
	ec_word GOOD
	ec_word TO
	ec_word MEET_YOU
	ec_word YOUNG
	ec_word TRAINER
	ec_word EXCL
@ win speech
	ec_word WAHAHAHA
	ec_word EXCL
	.2byte -1
	ec_word GIVE
	ec_word IT
	ec_word UP
@ loss speech
	ec_word YOU
	ec_word ARE
	ec_word A
	ec_word STRONG
	ec_word TRAINER
	ec_word KID
	.4byte gBattleFrontierTrainerMons_Alexas

@ 244
	.4byte TRAINER_CLASS_EXPERT_1
	.string "WESTON$", 8
@ pre-battle speech
	ec_word I
	ec_word DON_T
	ec_word PLAY
	ec_word DOWN
	ec_word ALL_RIGHT
	ec_word QUES
@ win speech
	ec_word YOU_RE
	ec_word FAR
	ec_word TOO
	ec_word EASY
	ec_word TO
	ec_word ATTACK
@ loss speech
	ec_word WELL
	ec_word WELL
	ec_word ELLIPSIS
	ec_word I
	ec_word SURRENDER
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Weston

@ 245
	.4byte TRAINER_CLASS_EXPERT_1
	.string "JASPER$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word NOT
	ec_word OLD
	ec_word I_AM
	ec_word SKILLED
	ec_word EXCL
@ win speech
	ec_word SKILLED
	ec_word THAT_S
	ec_word WHAT
	ec_word I_AM
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word I_AM
	ec_word SHOCKED
	ec_word EXCL
	ec_word DOWN
	ec_word I
	ec_word GO
	.4byte gBattleFrontierTrainerMons_Jasper

@ 246
	.4byte TRAINER_CLASS_EXPERT_2
	.string "NADIA$", 8
@ pre-battle speech
	ec_word YOU
	ec_word CAN_T
	ec_word BEAT
	ec_word ME
	ec_word DOWN
	ec_word EXCL
@ win speech
	ec_word HAH
	ec_word EXCL
	.2byte -1
	ec_word I
	ec_word BEAT
	ec_word YOU
@ loss speech
	ec_word I_AM
	ec_move2 BEAT_UP
	ec_word AND
	ec_word DOWNCAST
	ec_word ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Nadia

@ 247
	.4byte TRAINER_CLASS_EXPERT_2
	.string "MIRANDA$", 8
@ pre-battle speech
	ec_word WELL
	ec_word WELL
	.2byte -1
	ec_word LET_S
	ec_word START
	.2byte -1
@ win speech
	ec_word WHAT
	ec_word QUES
	ec_word DONE
	ec_word SO
	ec_word SOON
	ec_word QUES
@ loss speech
	ec_word WELL
	ec_word I
	ec_word SEE
	ec_word THAT
	ec_word I_AM
	ec_word TOO_WEAK
	.4byte gBattleFrontierTrainerMons_Miranda

@ 248
	.4byte TRAINER_CLASS_EXPERT_2
	.string "EMMA$", 8
@ pre-battle speech
	ec_word I_VE
	ec_word BEEN
	ec_word HEARING
	ec_word ABOUT
	ec_word YOU
	.2byte -1
@ win speech
	ec_word I
	ec_word THINK
	ec_word I_VE
	ec_word MISHEARD
	ec_word THINGS
	.2byte -1
@ loss speech
	ec_word WHAT
	ec_word I_VE
	ec_word BEEN
	ec_word HEARING
	ec_word IS
	ec_word RIGHT
	.4byte gBattleFrontierTrainerMons_Emma

@ 249
	.4byte TRAINER_CLASS_PSYCHIC_1
	.string "ROLANDO$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word A
	ec_word SUPER
	ec_word POKEMON
	ec_word HERO
	ec_word EXCL
@ win speech
	ec_word WAS
	ec_word THAT
	ec_word ENOUGH
	ec_word FOR
	ec_word YOU
	ec_word QUES
@ loss speech
	ec_word YOU
	ec_word SHOULD
	ec_word NOT
	ec_word BEAT
	ec_word A
	ec_word HERO
	.4byte gBattleFrontierTrainerMons_Rolando

@ 250
	.4byte TRAINER_CLASS_PSYCHIC_1
	.string "STANLY$", 8
@ pre-battle speech
	ec_word THIS
	ec_word SHOULD
	ec_word BE
	ec_word AN
	ec_word EASY
	ec_word MATCH
@ win speech
	ec_word IT
	ec_word REALLY
	ec_word WAS
	ec_word EASY
	.2byte -1
	.2byte -1
@ loss speech
	ec_word ARE
	ec_word YOU
	ec_word HAPPY
	ec_word NOW
	ec_word QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Stanly

@ 251
	.4byte TRAINER_CLASS_PSYCHIC_1
	.string "DARIO$", 8
@ pre-battle speech
	ec_word MY
	ec_move2 FORESIGHT
	ec_word SAYS
	ec_word I
	ec_word WILL
	ec_word WIN
@ win speech
	ec_word MY
	ec_move2 FORESIGHT
	ec_word HAS
	ec_word BEEN
	ec_word PERFECT
	.2byte -1
@ loss speech
	ec_word I
	ec_word DIDN_T
	ec_word SEE
	ec_word THIS
	ec_move1 REVERSAL
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Dario

@ 252
	.4byte TRAINER_CLASS_PSYCHIC_2
	.string "KARLEE$", 8
@ pre-battle speech
	ec_word SOMETHING
	ec_word GOOD
	ec_word WILL
	ec_word COME
	ec_word OF
	ec_word THIS
@ win speech
	ec_word YOU
	ec_word SEE
	ec_word QUES
	ec_word FANTASTIC
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word THAT
	ec_word SOMETHING
	ec_word GOOD
	ec_word WENT
	ec_word TO
	ec_word YOU
	.4byte gBattleFrontierTrainerMons_Karlee

@ 253
	.4byte TRAINER_CLASS_PSYCHIC_2
	.string "JAYLIN$", 8
@ pre-battle speech
	ec_word EVERY
	ec_word TRAINER
	ec_word HAS
	ec_word BEEN
	ec_word TOO_WEAK
	ec_word ELLIPSIS
@ win speech
	ec_word IT_S
	ec_word MAKING
	ec_word ME
	ec_move1 YAWN
	ec_word THAT
	ec_word BATTLE
@ loss speech
	ec_word I
	ec_word SLEPT
	ec_word AND
	ec_word SO
	ec_word I
	ec_word LOST
	.4byte gBattleFrontierTrainerMons_Jaylin

@ 254
	.4byte TRAINER_CLASS_PSYCHIC_2
	.string "INGRID$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word NOT
	ec_word A
	ec_word VERY
	ec_word MEAN
	ec_word TRAINER
@ win speech
	ec_word WASN_T
	ec_word THAT
	ec_word A
	ec_word GOOD
	ec_word MATCH
	ec_word QUES
@ loss speech
	ec_word I
	ec_word LOST
	ec_word CAUSE
	ec_word YOU_RE
	ec_word MEAN
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Ingrid

@ 255
	.4byte TRAINER_CLASS_HEX_MANIAC
	.string "DELILAH$", 8
@ pre-battle speech
	ec_word DON_T
	ec_move1 GRUDGE
	ec_word ME
	ec_word IF_I_WIN
	ec_word OK_QUES
	.2byte -1
@ win speech
	ec_word I_AM
	ec_word SORRY
	ec_word TO
	ec_word SEE
	ec_word YOU
	ec_word ANGRY
@ loss speech
	ec_word I
	ec_word HAVE
	ec_word A
	ec_move1 GRUDGE
	ec_word WITH
	ec_word YOU
	.4byte gBattleFrontierTrainerMons_Delilah

@ 256
	.4byte TRAINER_CLASS_HEX_MANIAC
	.string "CARLY$", 8
@ pre-battle speech
	ec_word I
	ec_word WILL
	ec_word SCATTER
	ec_word SOME
	ec_move2 POISON_POWDER
	ec_word ABOUT
@ win speech
	ec_word IT_S
	ec_word SCARY
	ec_word HOW
	ec_word MY
	ec_word STRATEGY
	ec_word WORKS
@ loss speech
	ec_word I
	ec_word DISLIKE
	ec_word YOU
	ec_word AND
	ec_word YOUR
	ec_word POKEMON
	.4byte gBattleFrontierTrainerMons_Carly

@ 257
	.4byte TRAINER_CLASS_HEX_MANIAC
	.string "LEXIE$", 8
@ pre-battle speech
	ec_word WANT
	ec_word TO
	ec_word SEE
	ec_word SCARY
	ec_word POKEMON
	ec_word QUES
@ win speech
	ec_word WASN_T
	ec_word THAT
	ec_word SCARY
	ec_word EH_QUES
	.2byte -1
	.2byte -1
@ loss speech
	ec_word YOU_RE
	ec_word MORE
	ec_word SCARY
	ec_word THAN
	ec_word MY
	ec_word POKEMON
	.4byte gBattleFrontierTrainerMons_Lexie

@ 258
	.4byte TRAINER_CLASS_POKEMANIAC
	.string "MILLER$", 8
@ pre-battle speech
	ec_word HELLO
	ec_word QUES
	.2byte -1
	ec_word HELLO
	ec_word QUES_EXCL
	.2byte -1
@ win speech
	ec_word HELLO
	ec_word MOTHER
	ec_word EXCL
	ec_word I
	ec_word WON
	ec_word EXCL
@ loss speech
	ec_word MY
	ec_word PHONE
	ec_word ISN_T
	ec_word WORKING
	ec_word ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Miller

@ 259
	.4byte TRAINER_CLASS_POKEMANIAC
	.string "MARV$", 8
@ pre-battle speech
	ec_word YOU
	ec_word CAN
	ec_word LOSE
	ec_word YOUR
	ec_move1 SWAGGER
	ec_word NOW
@ win speech
	ec_word THERE
	ec_word IS
	ec_word NO
	ec_move1 SWAGGER
	ec_word LEFT
	ec_word EH_QUES
@ loss speech
	ec_word GO
	ec_word ON
	ec_move1 SWAGGER
	ec_word ALL
	ec_word YOU
	ec_word WANT
	.4byte gBattleFrontierTrainerMons_Marv

@ 260
	.4byte TRAINER_CLASS_POKEMANIAC
	.string "LAYTON$", 8
@ pre-battle speech
	ec_word I
	ec_word KNOW
	ec_word I_AM
	ec_word TOTALLY
	ec_word COOL
	ec_word EXCL
@ win speech
	ec_word YOU
	ec_word CAN
	ec_word LOOK
	ec_word UP
	ec_word TO
	ec_word ME
@ loss speech
	ec_word YOU_RE
	ec_word COOL
	ec_word EXCL
	ec_word NO
	ec_word REALLY
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Layton

@ 261
	.4byte TRAINER_CLASS_GENTLEMAN
	.string "BROOKS$", 8
@ pre-battle speech
	ec_word THIS
	ec_word IS
	ec_word A
	ec_word HIGH
	ec_word LEVEL
	ec_word BATTLE
@ win speech
	ec_word THAT_WAS
	ec_word HIGH
	ec_word LEVEL
	ec_word AND
	ec_word EXCITING
	ec_word TOO
@ loss speech
	ec_word YOU_RE
	ec_word TOO
	ec_word HIGH
	ec_word IN
	ec_word LEVEL
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Brooks

@ 262
	.4byte TRAINER_CLASS_GENTLEMAN
	.string "GREGORY$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word NOT
	ec_word THAT
	ec_word OLD
	ec_word YET
	.2byte -1
@ win speech
	ec_word WHO
	ec_word SAYS
	ec_word I_AM
	ec_word TOO
	ec_word OLD
	ec_word QUES
@ loss speech
	ec_word PLEASE
	ec_word I_AM
	ec_word REALLY
	ec_word NOT
	ec_word THAT
	ec_word OLD
	.4byte gBattleFrontierTrainerMons_Gregory

@ 263
	.4byte TRAINER_CLASS_GENTLEMAN
	.string "REESE$", 8
@ pre-battle speech
	ec_word I_VE
	ec_word A
	ec_word COUPLE
	ec_word THINGS
	.2byte -1
	.2byte -1
@ win speech
	ec_word DON_T
	ec_word DIET
	ec_word PLAY
	ec_word SPORTS
	ec_word INSTEAD
	.2byte -1
@ loss speech
	ec_word INSTEAD
	ec_word OF
	ec_word TELEVISION
	ec_word GET
	ec_word A
	ec_word BOOK
	.4byte gBattleFrontierTrainerMons_Reese

@ 264
	.4byte TRAINER_CLASS_TRIATHLETE_3
	.string "MASON$", 8
@ pre-battle speech
	ec_word PLEASE
	ec_word DON_T
	ec_word MAKE
	ec_word THIS
	ec_word SCARY
	.2byte -1
@ win speech
	ec_word THANK_YOU
	ec_word ELLIPSIS
	.2byte -1
	ec_word I_AM
	ec_word HAPPY
	ec_word NOW
@ loss speech
	ec_word I_AM
	ec_word DISAPPOINTED
	ec_word ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Mason

@ 265
	.4byte TRAINER_CLASS_TRIATHLETE_3
	.string "TOBY$", 8
@ pre-battle speech
	ec_word LISTEN
	ec_word UP
	.2byte -1
	ec_word I
	ec_word ALWAYS
	ec_word WIN
@ win speech
	ec_word I_AM
	ec_word A
	ec_word GENIUS
	ec_word OR
	ec_word WHAT
	ec_word QUES
@ loss speech
	ec_word I
	ec_word CAN
	ec_word BEAT
	ec_word YOU
	ec_word AT
	ec_word SMARTNESS
	.4byte gBattleFrontierTrainerMons_Toby

@ 266
	.4byte TRAINER_CLASS_TRIATHLETE_4
	.string "DOROTHY$", 8
@ pre-battle speech
	ec_word THE
	ec_word SPORTS
	ec_word WORLD
	ec_word SHOULD
	ec_word ACCEPT
	ec_word POKEMON
@ win speech
	ec_word THANK_YOU
	ec_word EXCL
	ec_word THAT
	ec_word WIN
	ec_word WAS
	ec_word REFRESHING
@ loss speech
	ec_word THANK_YOU
	ec_word EXCL
	ec_word THAT
	ec_word LOSS
	ec_word WAS
	ec_word REFRESHING
	.4byte gBattleFrontierTrainerMons_Dorothy

@ 267
	.4byte TRAINER_CLASS_TRIATHLETE_4
	.string "PIPER$", 8
@ pre-battle speech
	ec_word COME_ON
	ec_word YOU
	ec_word NEED
	ec_word A
	ec_word SPEED_BOOST
	ec_word QUES
@ win speech
	ec_word YOU
	ec_word NEED
	ec_word TO
	ec_word SHOW
	ec_word MORE
	ec_word GUTS
@ loss speech
	ec_word OH
	ec_word YOU
	ec_word EXCL
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Piper

@ 268
	.4byte TRAINER_CLASS_TRIATHLETE_5
	.string "FINN$", 8
@ pre-battle speech
	ec_word NOT
	ec_word ANOTHER
	ec_word TRAINER
	ec_word BATTLE
	ec_word ELLIPSIS
	.2byte -1
@ win speech
	ec_word WON_T
	ec_word THIS
	ec_word EVER
	ec_word END
	ec_word QUES
	.2byte -1
@ loss speech
	ec_word I
	ec_word FINALLY
	ec_word GET
	ec_word TO
	ec_move2 REST
	ec_word A_LITTLE
	.4byte gBattleFrontierTrainerMons_Finn

@ 269
	.4byte TRAINER_CLASS_TRIATHLETE_5
	.string "SAMIR$", 8
@ pre-battle speech
	ec_word I
	ec_move2 DIVE
	ec_word BELOW
	ec_word THE
	ec_move2 SURF
	ec_word EXCL
@ win speech
	ec_word YAHOO
	ec_word TAKE
	ec_word A
	ec_move2 DIVE
	ec_word YOU
	ec_word EXCL
@ loss speech
	ec_word I_AM
	ec_word GOING
	ec_word TO
	ec_word SINK
	ec_word ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Samir

@ 270
	.4byte TRAINER_CLASS_TRIATHLETE_6
	.string "FIONA$", 8
@ pre-battle speech
	ec_word DID
	ec_word YOU
	ec_word LIMBER
	ec_word UP
	ec_word BEFORE
	ec_word QUES
@ win speech
	ec_word YOU
	ec_word NEED
	ec_word TO
	ec_word BE
	ec_word MORE
	ec_word READY
@ loss speech
	ec_word BEING
	ec_word LIMBER
	ec_word DIDN_T
	ec_word WORK
	ec_word FOR
	ec_word ME
	.4byte gBattleFrontierTrainerMons_Fiona

@ 271
	.4byte TRAINER_CLASS_TRIATHLETE_6
	.string "GLORIA$", 8
@ pre-battle speech
	ec_word I
	ec_word LIKE
	ec_word TO
	ec_word ATTACK
	ec_word WITH
	ec_word SUCTION_CUPS
@ win speech
	ec_word GIGGLE
	ec_word ELLIPSIS
	ec_word IT_S
	ec_word OVER
	ec_word FOR
	ec_word YOU
@ loss speech
	ec_word I
	ec_word DON_T
	ec_word GET
	ec_word HOW
	ec_word SUCTION_CUPS
	ec_word WORK
	.4byte gBattleFrontierTrainerMons_Gloria

@ 272
	.4byte TRAINER_CLASS_TRIATHLETE_1
	.string "NICO$", 8
@ pre-battle speech
	ec_word LIKE
	ec_word A
	ec_move1 SONIC_BOOM
	ec_word I_VE_ARRIVED
	.2byte -1
	.2byte -1
@ win speech
	ec_word SORRY
	ec_word TO
	ec_word MAKE
	ec_word YOU
	ec_word SO
	ec_word DOWNCAST
@ loss speech
	ec_word I_AM
	ec_word GOING
	ec_word WITH
	ec_word A
	ec_move2 SUPERSONIC
	ec_word SPEED_BOOST
	.4byte gBattleFrontierTrainerMons_Nico

@ 273
	.4byte TRAINER_CLASS_TRIATHLETE_1
	.string "JEREMY$", 8
@ pre-battle speech
	ec_word A
	ec_word POKEMON
	ec_word MASTER
	ec_word THAT_S
	ec_word MY
	ec_word DREAM
@ win speech
	ec_word MY
	ec_word DREAM
	ec_word ISN_T
	ec_word FAR
	ec_word OFF
	ec_word EXCL
@ loss speech
	ec_word WHAT
	ec_word I
	ec_word DREAM
	ec_word ISN_T
	ec_word HAPPENING
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Jeremy

@ 274
	.4byte TRAINER_CLASS_TRIATHLETE_2
	.string "CAITLIN$", 8
@ pre-battle speech
	ec_word DON_T
	ec_word YOU
	ec_word THINK
	ec_word I_AM
	ec_word CUTE
	ec_word QUES
@ win speech
	ec_word THERE
	ec_word IS
	ec_word MORE
	ec_word TO_ME
	ec_word THAN
	ec_word CUTENESS
@ loss speech
	ec_word MY
	ec_word CUTE_CHARM
	ec_word DOESN_T
	ec_move2 ATTRACT
	ec_word YOU
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Caitlin

@ 275
	.4byte TRAINER_CLASS_TRIATHLETE_2
	.string "REENA$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word ALWAYS
	ec_word HAPPY
	ec_word HAPPY
	ec_word HAPPY
	ec_word EXCL
@ win speech
	ec_word OH
	ec_word YAY
	ec_word EXCL
	ec_word YAHOO
	ec_word FOR
	ec_word ME
@ loss speech
	ec_word YAHOO
	ec_word EXCL
	ec_word I_AM
	ec_word HAPPY
	ec_word FOR
	ec_word YOU
	.4byte gBattleFrontierTrainerMons_Reena

@ 276
	.4byte TRAINER_CLASS_BUG_MANIAC
	.string "AVERY$", 8
@ pre-battle speech
	ec_word I_VE
	ec_word GOT
	ec_word A_LOT
	ec_word OF
	ec_word BUG
	ec_word POKEMON
@ win speech
	ec_word MY
	ec_word BUG
	ec_word POKEMON
	ec_word ARE
	ec_word ALL
	ec_word UNBELIEVABLE
@ loss speech
	ec_word MY
	ec_word BUG
	ec_word POKEMON
	ec_word ARE
	ec_word ALL
	ec_word UPSIDE_DOWN
	.4byte gBattleFrontierTrainerMons_Avery

@ 277
	.4byte TRAINER_CLASS_BUG_MANIAC
	.string "LIAM$", 8
@ pre-battle speech
	ec_word WE
	ec_word REALLY
	ec_word DISLIKE
	ec_word FIRE
	ec_word AND
	ec_word FLYING
@ win speech
	ec_word BUG
	ec_word POKEMON
	ec_word AREN_T
	ec_word BAD
	ec_word HEY_QUES
	.2byte -1
@ loss speech
	ec_word YOU
	ec_word KNOW
	ec_word WHAT
	ec_word WE
	ec_word DISLIKE
	ec_word HEY_QUES
	.4byte gBattleFrontierTrainerMons_Liam

@ 278
	.4byte TRAINER_CLASS_FISHERMAN
	.string "THEO$", 8
@ pre-battle speech
	ec_word FISHING
	ec_word IS
	ec_word MY
	ec_word CHOICE
	ec_word IN
	ec_word LIFE
@ win speech
	ec_word WATER
	ec_word POKEMON
	ec_move2 ATTRACT
	ec_word ME
	ec_word WITHOUT
	ec_word END
@ loss speech
	ec_word DON_T
	ec_word COUNT_ON
	ec_word THAT
	ec_word HAPPENING
	ec_word ANOTHER
	ec_word TIME
	.4byte gBattleFrontierTrainerMons_Theo

@ 279
	.4byte TRAINER_CLASS_FISHERMAN
	.string "BAILEY$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word AN
	ec_word ADULT
	ec_word I
	ec_word BATTLE
	ec_word EASY
@ win speech
	ec_word I_AM
	ec_word AN
	ec_word ADULT
	ec_word I
	ec_move2 SWALLOW
	ec_word JOY
@ loss speech
	ec_word I_AM
	ec_word AN
	ec_word ADULT
	ec_word I
	ec_move2 SWALLOW
	ec_move2 FRUSTRATION
	.4byte gBattleFrontierTrainerMons_Bailey

@ 280
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.string "HUGO$", 8
@ pre-battle speech
	ec_word I
	ec_word TRY
	ec_word THE
	ec_word BEST
	ec_word I
	ec_word CAN
@ win speech
	ec_word I
	ec_word CAN_WIN
	ec_word IF
	ec_word I
	ec_word TRY
	ec_word ENOUGH
@ loss speech
	ec_word I
	ec_word DID
	ec_word TRY
	ec_word DIDN_T
	ec_word I
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Hugo

@ 281
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.string "BRYCE$", 8
@ pre-battle speech
	ec_word I_WAS
	ec_word ON
	ec_word VACATION
	ec_word UNTIL
	ec_word ONLY
	ec_word YESTERDAY
@ win speech
	ec_word I
	ec_word HAVEN_T
	ec_word LOST
	ec_word MY
	ec_word SKILL
	ec_word YET
@ loss speech
	ec_word THAT_S
	ec_word IT
	ec_word ELLIPSIS
	ec_word I
	ec_word NEED
	ec_word SLEEP
	.4byte gBattleFrontierTrainerMons_Bryce

@ 282
	.4byte TRAINER_CLASS_COLLECTOR
	.string "GIDEON$", 8
@ pre-battle speech
	ec_word WHAT_S_UP_QUES
	ec_word YOU
	ec_word THINK
	ec_word I_AM
	ec_word SCARY
	ec_word QUES
@ win speech
	ec_word I_AM
	ec_word COOL
	ec_word BUT
	ec_word NOT
	ec_word SCARY
	ec_word EXCL
@ loss speech
	ec_word LOOK
	ec_word AT
	ec_word MY
	ec_word FABULOUS
	ec_word FASHION
	ec_word SENSE
	.4byte gBattleFrontierTrainerMons_Gideon

@ 283
	.4byte TRAINER_CLASS_COLLECTOR
	.string "TRISTON$", 8
@ pre-battle speech
	ec_word I
	ec_word WOULD
	ec_word RATHER
	ec_word LOOK
	ec_word AT
	ec_word POKEMON
@ win speech
	ec_word HUH_QUES
	ec_word YOU
	ec_word MEAN
	ec_word I
	ec_word WON
	ec_word QUES_EXCL
@ loss speech
	ec_word SEE
	ec_word QUES
	.2byte -1
	ec_word I
	ec_word ALWAYS
	ec_word LOSE
	.4byte gBattleFrontierTrainerMons_Triston

@ 284
	.4byte TRAINER_CLASS_GUITARIST
	.string "CHARLES$", 8
@ pre-battle speech
	ec_word IT_S
	ec_word HOPELESS
	ec_word TO
	ec_move2 STRUGGLE
	ec_word WITH
	ec_word ME
@ win speech
	ec_move1 SUBMISSION
	ec_word WAS
	ec_word YOUR
	ec_word ONLY
	ec_word CHOICE
	.2byte -1
@ loss speech
	ec_word I_AM
	ec_word GOING
	ec_word DOWN
	ec_word DOWN
	ec_word DOWN
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Charles

@ 285
	.4byte TRAINER_CLASS_GUITARIST
	.string "RAYMOND$", 8
@ pre-battle speech
	ec_word WANT
	ec_word TO
	ec_word HEAR
	ec_word MY
	ec_word SONG
	ec_word QUES
@ win speech
	ec_word SATISFIED
	ec_word THAT_S
	ec_word WHAT
	ec_word I_AM
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word SATISFIED
	ec_word IS
	ec_word WHAT
	ec_word I
	ec_word CAN_T
	ec_word BE
	.4byte gBattleFrontierTrainerMons_Raymond

@ 286
	.4byte TRAINER_CLASS_BIRD_KEEPER
	.string "DIRK$", 8
@ pre-battle speech
	ec_word FLYING
	ec_word POKEMON
	ec_word ARE
	ec_word ABOVE
	ec_word THE
	ec_move2 REST
@ win speech
	ec_word YOU
	ec_word CAN_T_WIN
	ec_word EXCL
	ec_word FLYING
	ec_word POKEMON
	ec_word RULE
@ loss speech
	ec_word AREN_T
	ec_word THERE
	ec_word MORE
	ec_word FLYING
	ec_word POKEMON
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Dirk

@ 287
	.4byte TRAINER_CLASS_BIRD_KEEPER
	.string "HAROLD$", 8
@ pre-battle speech
	ec_word MY
	ec_word POKEMON
	ec_word APPEAL
	ec_word TO
	ec_word YOU
	ec_word QUES
@ win speech
	ec_word YOU
	ec_word DO
	ec_word LIKE
	ec_word MY
	ec_word POKEMON
	ec_word QUES
@ loss speech
	ec_word SO
	ec_word YOU
	ec_word DISLIKE
	ec_word MY
	ec_word POKEMON
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Harold

@ 288
	.4byte TRAINER_CLASS_SAILOR
	.string "OMAR$", 8
@ pre-battle speech
	ec_word LET_ME_WIN
	ec_word IN
	ec_move1 RETURN
	ec_word FOR
	ec_word A
	ec_move2 PRESENT
@ win speech
	ec_word HERE
	ec_word YOU
	ec_word ARE
	ec_word SOME
	ec_move2 TOXIC
	ec_word SWEETS
@ loss speech
	ec_word YOUR
	ec_move2 PRESENT
	ec_word QUES
	ec_word WHAT
	ec_word FOR
	ec_word QUES_EXCL
	.4byte gBattleFrontierTrainerMons_Omar

@ 289
	.4byte TRAINER_CLASS_SAILOR
	.string "PETER$", 8
@ pre-battle speech
	ec_word I
	ec_word BRAG
	ec_word ABOUT
	ec_word MY
	ec_word HAPPINESS
	ec_word OK_QUES
@ win speech
	ec_word YOU
	ec_word HAVE
	ec_word TO
	ec_word LISTEN
	ec_word TO_ME
	ec_word BRAG
@ loss speech
	ec_word I_AM
	ec_word DISAPPOINTED
	ec_word YOU
	ec_word WON_T
	ec_word LISTEN
	ec_word TO_ME
	.4byte gBattleFrontierTrainerMons_Peter

@ 290
	.4byte TRAINER_CLASS_HIKER
	.string "DEV$", 8
@ pre-battle speech
	ec_word COME_ON
	ec_word LET_S
	ec_word GET
	ec_word A
	ec_word MOVE
	ec_word ON
@ win speech
	ec_word I
	ec_word GET
	ec_word TO
	ec_word NAP
	ec_word AFTER
	ec_word THAT
@ loss speech
	ec_word I
	ec_word NEED
	ec_word TO
	ec_word NAP
	ec_word AFTER
	ec_word THAT
	.4byte gBattleFrontierTrainerMons_Dev

@ 291
	.4byte TRAINER_CLASS_HIKER
	.string "COREY$", 8
@ pre-battle speech
	ec_word LET_S
	ec_word TEACH
	ec_word YOU
	ec_word HOW
	ec_word TOUGH
	ec_word I_AM
@ win speech
	ec_word LOOK
	ec_word AT
	ec_word ME
	ec_word MAKE
	ec_word A
	ec_move1 BRICK_BREAK
@ loss speech
	ec_word MY
	ec_move2 FRUSTRATION
	ec_word IS
	ec_word CLOSE
	ec_word TO
	ec_move2 ERUPTION
	.4byte gBattleFrontierTrainerMons_Corey

@ 292
	.4byte TRAINER_CLASS_KINDLER
	.string "ANDRE$", 8
@ pre-battle speech
	ec_word NOW
	ec_word THIS
	ec_word IS
	ec_word A
	ec_word PERFECT
	ec_word FLAME_BODY
@ win speech
	ec_word LOOK
	ec_word AT
	ec_word MY
	ec_word FIERY
	ec_word DANCE
	ec_word EXCL
@ loss speech
	ec_word YOU
	ec_word WANT
	ec_word AN
	ec_move2 EXPLOSION
	ec_word HERE
	ec_word QUES
	.4byte gBattleFrontierTrainerMons_Andre

@ 293
	.4byte TRAINER_CLASS_KINDLER
	.string "FERRIS$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word NO_1
	ec_word IN
	ec_word THE
	ec_word OLD
	ec_word CLASS
@ win speech
	ec_word NO_1
	ec_word THAT_S
	ec_word WHAT
	ec_word I_AM
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word I_AM
	ec_word NOT
	ec_word NO_1
	ec_word ANY
	ec_word MORE
	ec_word ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Ferris

@ 294
	.4byte TRAINER_CLASS_PARASOL_LADY
	.string "ALIVIA$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word FEELING
	ec_word GIDDY
	ec_word SO
	ec_word SHOULD
	ec_word YOU
@ win speech
	ec_word IT
	ec_word WAS
	ec_word ALL
	ec_word TOGETHER
	ec_word TOO
	ec_word EASY
@ loss speech
	ec_word I
	ec_word WILL
	ec_word GIDDY
	ec_word UP
	ec_word AND
	ec_word AWAY
	.4byte gBattleFrontierTrainerMons_Alivia

@ 295
	.4byte TRAINER_CLASS_PARASOL_LADY
	.string "PAIGE$", 8
@ pre-battle speech
	ec_word LET_S
	ec_word ENJOY
	ec_word OUR
	ec_word BATTLE
	ec_word TOGETHER
	.2byte -1
@ win speech
	ec_word THAT_S_IT_EXCL
	.2byte -1
	.2byte -1
	ec_word THANK_YOU
	ec_word VERY
	ec_word MUCH
@ loss speech
	ec_word THAT_S_IT_EXCL
	.2byte -1
	.2byte -1
	ec_word DO
	ec_word GO
	ec_word ON
	.4byte gBattleFrontierTrainerMons_Paige

@ 296
	.4byte TRAINER_CLASS_BEAUTY
	.string "ANYA$", 8
@ pre-battle speech
	ec_word I
	ec_word DISLIKE
	ec_word OH
	ec_word SO
	ec_word PRETTY
	ec_word FASHION
@ win speech
	ec_word FASHION
	ec_word SHOULD
	ec_word MATCH
	ec_word THE
	ec_word PERSON
	.2byte -1
@ loss speech
	ec_word PRETTY
	ec_word COULD
	ec_word BE
	ec_word GOOD
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Anya

@ 297
	.4byte TRAINER_CLASS_BEAUTY
	.string "DAWN$", 8
@ pre-battle speech
	ec_word I
	ec_word GO
	ec_word ALL
	ec_word OUT
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word DON_T
	ec_word BE
	ec_word A
	ec_word BABY
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word YOU
	ec_word WON
	ec_word EXCL
	ec_word MOVE
	ec_word ON
	ec_word EXCL
	.4byte gBattleFrontierTrainerMons_Dawn

@ 298
	.4byte TRAINER_CLASS_AROMA_LADY
	.string "ABBY$", 8
@ pre-battle speech
	ec_word I
	ec_word LIKE
	ec_word A
	ec_word TRAINER
	ec_word THAT_S
	ec_word REFRESHING
@ win speech
	ec_word VICTORY
	ec_word HAS
	ec_word A
	ec_move1 SWEET_SCENT
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word WHAT
	ec_word AN
	ec_word AWFUL
	ec_word STENCH
	ec_word EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Abby

@ 299
	.4byte TRAINER_CLASS_AROMA_LADY
	.string "GRETEL$", 8
@ pre-battle speech
	ec_word I
	ec_word CAUSE
	ec_move1 OUTRAGE
	ec_word AS
	ec_word A
	ec_word TRAINER
@ win speech
	ec_word IT_S
	ec_word ONLY
	ec_word NATURAL
	ec_word SEE_YA
	ec_word BYE_BYE
	ec_word EXCL
@ loss speech
	ec_word IT_S
	ec_word HARD
	ec_word TO
	ec_word BELIEVE
	ec_word BUT
	ec_word CONGRATS
	.4byte gBattleFrontierTrainerMons_Gretel
