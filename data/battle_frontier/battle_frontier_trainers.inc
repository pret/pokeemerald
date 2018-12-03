	.align 2
gBattleFrontierTrainers:: @ 85D5ACC
@ 0
	.4byte FACILITY_CLASS_YOUNGSTER
	.string "BRADY$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NEVER
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_LOSE
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_STRONG
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_I
	.2byte EC_WORD_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_QUES
	.2byte -1
	.2byte EC_WORD_BUT
	.2byte EC_WORD_HOW
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Brady

@ 1
	.4byte FACILITY_CLASS_YOUNGSTER
	.string "CONNER$", 8
@ pre-battle speech
	.2byte EC_WORD_LOSING
	.2byte EC_WORD_DOESN_T
	.2byte EC_WORD_BUG
	.2byte EC_WORD_ME
	.2byte -1
	.2byte -1
@ win speech
	.2byte EC_WORD_A
	.2byte EC_WORD_WIN
	.2byte EC_WORD_IS
	.2byte EC_WORD_JUST
	.2byte EC_WORD_AWESOME
	.2byte -1
@ loss speech
	.2byte EC_WORD_DARN
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_LOSING
	.2byte EC_WORD_DOES
	.2byte EC_WORD_BUG
	.2byte EC_WORD_ME
	.4byte gBattleFrontierTrainerMons_Conner

@ 2
	.4byte FACILITY_CLASS_YOUNGSTER
	.string "BRADLEY$", 8
@ pre-battle speech
	.2byte EC_WORD_HEY_THERE
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_MY
	.2byte EC_WORD_OPPONENT
	.2byte EC_WORD_TODAY
@ win speech
	.2byte EC_WORD_HAHAHA
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_SEE_YA
	.2byte EC_WORD_LATER
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_TOMORROW
	.2byte EC_WORD_IS
	.2byte EC_WORD_WHEN
	.2byte EC_WORD_WE
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_BATTLE
	.4byte gBattleFrontierTrainerMons_Bradley

@ 3
	.4byte FACILITY_CLASS_LASS
	.string "CYBIL$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_NOT_VERY
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_AT
	.2byte EC_WORD_ALL
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_SAD
	.2byte EC_WORD_TO
	.2byte EC_WORD_SEE
	.2byte EC_WORD_YOU
	.2byte EC_MOVE2(STRUGGLE)
@ loss speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_BE
	.2byte EC_WORD_HAPPENING
	.2byte EC_WORD_TO_ME
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Cybil

@ 4
	.4byte FACILITY_CLASS_LASS
	.string "RODETTE$", 8
@ pre-battle speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_SO
	.2byte EC_WORD_EXCITING
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_INCREDIBLE
	.2byte EC_WORD_HOW
	.2byte EC_WORD_STRONG
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_OH_DEAR
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_JUST
	.2byte EC_WORD_NO
	.2byte EC_WORD_GOOD
	.4byte gBattleFrontierTrainerMons_Rodette

@ 5
	.4byte FACILITY_CLASS_LASS
	.string "PEGGY$", 8
@ pre-battle speech
	.2byte EC_WORD_GET
	.2byte EC_WORD_READY
	.2byte EC_WORD_TO
	.2byte EC_WORD_BE
	.2byte EC_WORD_DESTROYED
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_HAHAHA
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_LOLLING
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_SAD
	.2byte EC_WORD_THANKS
	.2byte EC_WORD_TO
	.2byte EC_WORD_YOU
	.4byte gBattleFrontierTrainerMons_Peggy

@ 6
	.4byte FACILITY_CLASS_SCHOOL_KID_M
	.string "KEITH$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_JUST
	.2byte EC_WORD_STUDY
	.2byte EC_WORD_YOU
	.2byte EC_WORD_KNOW
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_STUDY
	.2byte EC_WORD_ENOUGH
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_TO
	.2byte EC_WORD_STUDY
	.2byte EC_WORD_MORE
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Keith

@ 7
	.4byte FACILITY_CLASS_SCHOOL_KID_M
	.string "GRAYSON$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_CHILD_S_PLAY
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_DONE
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_WE
	.2byte EC_WORD_WERE
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_TOYS
	.2byte EC_WORD_TO
	.2byte EC_WORD_YOU
	.4byte gBattleFrontierTrainerMons_Grayson

@ 8
	.4byte FACILITY_CLASS_SCHOOL_KID_M
	.string "GLENN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WOULD
	.2byte EC_WORD_BE
	.2byte EC_WORD_COOL
	.2byte EC_WORD_IF_I_WIN
	.2byte -1
@ win speech
	.2byte EC_WORD_COOL
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I_AM
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_BE
	.2byte EC_WORD_COOL
	.4byte gBattleFrontierTrainerMons_Glenn

@ 9
	.4byte FACILITY_CLASS_SCHOOL_KID_F
	.string "LILIANA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_GIVE_UP
	.2byte EC_WORD_UNTIL
	.2byte EC_WORD_I
	.2byte EC_WORD_WIN
@ win speech
	.2byte EC_WORD_THERE
	.2byte EC_WORD_IS
	.2byte EC_WORD_NO
	.2byte EC_WORD_SURRENDER
	.2byte EC_WORD_IN
	.2byte EC_WORD_ME
@ loss speech
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_IT
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_I
	.2byte EC_WORD_GIVE_UP
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Liliana

@ 10
	.4byte FACILITY_CLASS_SCHOOL_KID_F
	.string "ELISE$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_STRATEGY
	.2byte EC_WORD_IS
	.2byte EC_WORD_FROM
	.2byte EC_WORD_MY
	.2byte EC_WORD_FATHER
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WIN
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_FATHER
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_WON
@ loss speech
	.2byte EC_WORD_FORGIVE
	.2byte EC_WORD_ME
	.2byte EC_WORD_FATHER
	.2byte EC_WORD_FOR
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_LOST
	.4byte gBattleFrontierTrainerMons_Elise

@ 11
	.4byte FACILITY_CLASS_SCHOOL_KID_F
	.string "ZOEY$", 8
@ pre-battle speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_IT
@ win speech
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_SO
	.2byte EC_WORD_MUCH
@ loss speech
	.2byte EC_WORD_WERE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_BEING
	.2byte EC_WORD_SERIOUS
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Zoey

@ 12
	.4byte FACILITY_CLASS_RICH_BOY
	.string "MANUEL$", 8
@ pre-battle speech
	.2byte EC_WORD_ME
	.2byte EC_WORD_LOSE
	.2byte EC_WORD_QUES
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_PREPOSTEROUS
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_NATURALLY
	.2byte EC_WORD_I
	.2byte EC_WORD_WIN
	.2byte -1
	.2byte -1
	.2byte -1
@ loss speech
	.2byte EC_WORD_WAAAH
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_LOST
	.2byte EC_WORD_MOTHER
	.4byte gBattleFrontierTrainerMons_Manuel

@ 13
	.4byte FACILITY_CLASS_RICH_BOY
	.string "RUSS$", 8
@ pre-battle speech
	.2byte EC_WORD_THEY
	.2byte EC_WORD_ALL
	.2byte EC_WORD_WANT
	.2byte EC_WORD_MY
	.2byte EC_WORD_FABULOUS
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_PARTY
@ loss speech
	.2byte EC_WORD_HOW
	.2byte EC_WORD_COULD
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DO
	.2byte EC_WORD_THAT
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Russ

@ 14
	.4byte FACILITY_CLASS_RICH_BOY
	.string "DUSTIN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_COOL
	.2byte EC_WORD_POKEMON
	.2byte -1
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_MYSELF
	.2byte EC_WORD_WHEN_I_WIN
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_MYSELF
	.2byte EC_WORD_IF_I_LOSE
	.2byte EC_WORD_TOO
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Dustin

@ 15
	.4byte FACILITY_CLASS_LADY
	.string "TINA$", 8
@ pre-battle speech
	.2byte EC_WORD_IF_I_WIN
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_MOVE2(SWEET_KISS)
@ win speech
	.2byte EC_WORD_HERE_IT_IS
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE2(SWEET_KISS)
	.2byte EC_WORD_FROM
	.2byte EC_WORD_MY
	.2byte EC_POKEMON2(JYNX)
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WANT
	.2byte EC_WORD_A
	.2byte EC_MOVE(SWIFT)
	.2byte EC_MOVE2(MEGA_KICK)
	.2byte EC_WORD_INSTEAD
	.4byte gBattleFrontierTrainerMons_Tina

@ 16
	.4byte FACILITY_CLASS_LADY
	.string "GILLIAN$", 8
@ pre-battle speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_GOURMET
	.2byte EC_WORD_THING
	.2byte EC_WORD_IS
	.2byte EC_WORD_SO
	.2byte EC_WORD_YESTERDAY
@ win speech
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_NEVER
	.2byte EC_WORD_GO
	.2byte EC_WORD_OUT
	.2byte EC_WORD_OF
	.2byte EC_WORD_FASHION
@ loss speech
	.2byte EC_WORD_LOSING
	.2byte EC_WORD_DOESN_T
	.2byte EC_WORD_DISAPPOINT
	.2byte EC_WORD_ME
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Gillian

@ 17
	.4byte FACILITY_CLASS_LADY
	.string "ZOE$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVEN_T
	.2byte EC_WORD_A
	.2byte EC_WORD_WORRY
	.2byte EC_WORD_AT
	.2byte EC_WORD_ALL
@ win speech
	.2byte EC_WORD_LIFE
	.2byte EC_WORD_IS
	.2byte EC_WORD_ALWAYS
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_TO_ME
	.2byte -1
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WORRY
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_SKILL
	.4byte gBattleFrontierTrainerMons_Zoe

@ 18
	.4byte FACILITY_CLASS_CAMPER
	.string "CHEN$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TOTALLY
	.2byte EC_WORD_READY
	.2byte EC_WORD_TO
	.2byte EC_WORD_ROCK
	.2byte EC_WORD_TODAY
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_READY
	.2byte EC_WORD_TO
	.2byte EC_WORD_GO
	.2byte EC_WORD_ON
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_LOST
	.2byte EC_WORD_MY
	.2byte EC_MOVE(FOCUS_ENERGY)
	.2byte EC_WORD_AND
	.2byte EC_WORD_TOUGHNESS
	.4byte gBattleFrontierTrainerMons_Chen

@ 19
	.4byte FACILITY_CLASS_CAMPER
	.string "AL$", 8
@ pre-battle speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_SAYS
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_TOUGH
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_ME
	.2byte EC_WORD_WHO_IS
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_TOUGH
	.2byte -1
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_RIGHT
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_TOUGH
	.4byte gBattleFrontierTrainerMons_Al

@ 20
	.4byte FACILITY_CLASS_CAMPER
	.string "MITCH$", 8
@ pre-battle speech
	.2byte EC_WORD_MOTHER
	.2byte EC_WORD_NATURE
	.2byte EC_WORD_IS
	.2byte EC_WORD_MY
	.2byte EC_WORD_ALLY
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_WAS
	.2byte EC_WORD_THAT
	.2byte EC_WORD_ENOUGH
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_MOTHER
	.2byte EC_WORD_NATURE
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_LET_ME_WIN
	.2byte EC_WORD_QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Mitch

@ 21
	.4byte FACILITY_CLASS_PICNICKER
	.string "ANNE$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_WAIT
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_NOW
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_HAPPINESS
	.2byte EC_WORD_IS
	.2byte EC_WORD_OVERWHELMING
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOU_VE
	.2byte EC_WORD_DESTROYED
	.2byte EC_WORD_MY
	.2byte EC_WORD_HAPPINESS
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Anne

@ 22
	.4byte FACILITY_CLASS_PICNICKER
	.string "ALIZE$", 8
@ pre-battle speech
	.2byte EC_WORD_CUTE
	.2byte EC_WORD_AND
	.2byte EC_WORD_AWFULLY
	.2byte EC_WORD_STRONG
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_ME
@ win speech
	.2byte EC_WORD_YUP
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_CUTE
	.2byte EC_WORD_AND
	.2byte EC_WORD_AWFULLY
	.2byte EC_WORD_STRONG
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_WEAK
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_CUTE
	.4byte gBattleFrontierTrainerMons_Alize

@ 23
	.4byte FACILITY_CLASS_PICNICKER
	.string "LAUREN$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_OLD
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_ALSO
	.2byte EC_WORD_GOOD
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SAID
	.2byte EC_WORD_I_WAS
	.2byte EC_WORD_OLD
	.2byte EC_WORD_BUT
	.2byte EC_WORD_GOOD
@ loss speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_A
	.2byte EC_WORD_WEIRD
	.2byte EC_WORD_DREAM
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Lauren

@ 24
	.4byte FACILITY_CLASS_TUBER_M
	.string "KIPP$", 8
@ pre-battle speech
	.2byte EC_WORD_IF_I_WIN
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_GO
	.2byte EC_MOVE2(SURF)
@ win speech
	.2byte EC_WORD_YEAH
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_OFF
	.2byte EC_WORD_TO
	.2byte EC_MOVE2(SURF)
@ loss speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_NO
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_A
	.2byte EC_MOVE(WHIRLPOOL)
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Kipp

@ 25
	.4byte FACILITY_CLASS_TUBER_M
	.string "JASON$", 8
@ pre-battle speech
	.2byte EC_WORD_TEACH
	.2byte EC_WORD_ME
	.2byte EC_WORD_A
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_STRATEGY
	.2byte -1
@ win speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_STRATEGY
	.2byte EC_WORD_QUES_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_WOW
	.2byte EC_WORD_THAT
	.2byte EC_WORD_IS
	.2byte EC_WORD_AN
	.2byte EC_WORD_AWESOME
	.2byte EC_WORD_STRATEGY
	.4byte gBattleFrontierTrainerMons_Jason

@ 26
	.4byte FACILITY_CLASS_TUBER_M
	.string "JOHN$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_A
	.2byte EC_WORD_PRETTY
	.2byte EC_WORD_NEW
	.2byte EC_WORD_TRAINER
	.2byte -1
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NEW
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NEW
	.2byte EC_WORD_SO
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_IF_I_LOSE
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_John

@ 27
	.4byte FACILITY_CLASS_TUBER_F
	.string "ANN$", 8
@ pre-battle speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_SO
	.2byte EC_WORD_EXCITING
	.2byte EC_WORD_IT
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_IS
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SO
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN
	.2byte EC_WORD_CRY
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SO
	.2byte EC_WORD_SAD
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_CRY
	.4byte gBattleFrontierTrainerMons_Ann

@ 28
	.4byte FACILITY_CLASS_TUBER_F
	.string "EILEEN$", 8
@ pre-battle speech
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_PRETEND
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_AN
	.2byte EC_WORD_ADULT
	.2byte EC_WORD_OK_QUES
@ win speech
	.2byte EC_WORD_SO
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_AN
	.2byte EC_WORD_ADULT
	.2byte EC_WORD_FEELING
@ loss speech
	.2byte EC_WORD_AN
	.2byte EC_WORD_ADULT
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_BEAT
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Eileen

@ 29
	.4byte FACILITY_CLASS_TUBER_F
	.string "CARLIE$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_SUMMER
	.2byte EC_WORD_VACATION
	.2byte EC_WORD_IS
	.2byte EC_WORD_FOR
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_SUMMER
	.2byte EC_WORD_VACATION
	.2byte EC_WORD_WILL
	.2byte EC_WORD_BE
	.2byte EC_WORD_AWESOME
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T_WIN
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_THIS
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Carlie

@ 30
	.4byte FACILITY_CLASS_SWIMMER_M
	.string "GORDON$", 8
@ pre-battle speech
	.2byte EC_WORD_VICTORY
	.2byte EC_WORD_WILL
	.2byte EC_WORD_COME
	.2byte EC_WORD_TO_ME
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_OH_YEAH
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_WON
@ loss speech
	.2byte EC_WORD_NOTHING
	.2byte EC_WORD_IS
	.2byte EC_WORD_WORKING
	.2byte EC_WORD_OUT
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
	.4byte gBattleFrontierTrainerMons_Gordon

@ 31
	.4byte FACILITY_CLASS_SWIMMER_M
	.string "AYDEN$", 8
@ pre-battle speech
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_A
	.2byte EC_WORD_HOT
	.2byte EC_WORD_BATTLE
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_WATER
	.2byte EC_WORD_TO
	.2byte EC_WORD_COOL
	.2byte EC_WORD_DOWN
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_ME
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_ICE
	.2byte EC_WORD_COLD
	.4byte gBattleFrontierTrainerMons_Ayden

@ 32
	.4byte FACILITY_CLASS_SWIMMER_M
	.string "MARCO$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_MOVE2(SURF)
	.2byte EC_WORD_IN
	.2byte EC_WORD_THE
	.2byte EC_WORD_WINTER
	.2byte EC_WORD_TOO
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_GO
	.2byte EC_MOVE2(SURF)
	.2byte EC_WORD_RIGHT
	.2byte EC_WORD_NOW
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_MOVE2(BEAT_UP)
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(SURF)
	.2byte EC_WORD_BOARD
	.4byte gBattleFrontierTrainerMons_Marco

@ 33
	.4byte FACILITY_CLASS_SWIMMER_F
	.string "CIERRA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_TO
	.2byte EC_WORD_SYNCHRONIZE
	.2byte EC_WORD_MY
	.2byte EC_WORD_SWIFT_SWIM
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_SYNCHRONIZE
	.2byte EC_WORD_WITH
	.2byte EC_WORD_ME
	.2byte -1
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_TO
	.2byte EC_WORD_SYNCHRONIZE
	.2byte EC_WORD_BETTER
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Cierra

@ 34
	.4byte FACILITY_CLASS_SWIMMER_F
	.string "MARCY$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_A
	.2byte EC_WORD_KNOCKOUT
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN_T_WIN
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_AFTER
	.2byte EC_WORD_ALL
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_A
	.2byte EC_WORD_KNOCKOUT
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_NOT
	.2byte EC_WORD_THE
	.2byte EC_WORD_KNOCKOUT
	.2byte EC_WORD_I
	.2byte EC_WORD_MEAN
	.4byte gBattleFrontierTrainerMons_Marcy

@ 35
	.4byte FACILITY_CLASS_SWIMMER_F
	.string "KATHY$", 8
@ pre-battle speech
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_WON
	.2byte EC_WORD_EVERY
	.2byte EC_WORD_MATCH
	.2byte EC_WORD_TODAY
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_SO
	.2byte EC_WORD_GREAT
	.2byte EC_WORD_TO
	.2byte EC_WORD_WIN
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_HUH_QUES
	.2byte EC_WORD_I
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_NOT
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_LOST
	.4byte gBattleFrontierTrainerMons_Kathy

@ 36
	.4byte FACILITY_CLASS_POKEFAN_M
	.string "PEYTON$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NEVER
	.2byte EC_WORD_DISAPPOINTED
	.2byte EC_WORD_WITH
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_IF
	.2byte EC_WORD_WE
	.2byte EC_WORD_WIN
	.2byte EC_WORD_TOGETHER
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_MORE
	.2byte EC_WORD_IF_I_LOSE
	.4byte gBattleFrontierTrainerMons_Peyton

@ 37
	.4byte FACILITY_CLASS_POKEFAN_M
	.string "JULIAN$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_RIGHT
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_TOTALLY
	.2byte EC_WORD_OUT
	.2byte EC_WORD_OF
	.2byte EC_WORD_THE
	.2byte EC_WORD_QUESTION
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DO
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Julian

@ 38
	.4byte FACILITY_CLASS_POKEFAN_M
	.string "QUINN$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ARE
	.2byte EC_WORD_BUT
	.2byte EC_WORD_A
	.2byte EC_WORD_DREAM
@ win speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_A
	.2byte EC_WORD_BEAUTIFUL
	.2byte EC_WORD_DREAM
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_AN
	.2byte EC_WORD_AWFUL
	.2byte EC_MOVE(NIGHTMARE)
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Quinn

@ 39
	.4byte FACILITY_CLASS_POKEFAN_F
	.string "HAYLEE$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_HOW
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_OVERWHELMING
	.2byte EC_WORD_JOY
	.2byte EC_WORD_OVER
	.2byte EC_WORD_THIS
@ loss speech
	.2byte EC_WORD_DESTROYED
	.2byte EC_WORD_IS
	.2byte EC_WORD_THE
	.2byte EC_WORD_WAY
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.4byte gBattleFrontierTrainerMons_Haylee

@ 40
	.4byte FACILITY_CLASS_POKEFAN_F
	.string "AMANDA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_COME
	.2byte EC_WORD_FROM
	.2byte EC_WORD_A
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_FAMILY
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_TREASURE
	.2byte EC_WORD_THIS
	.2byte EC_WORD_WIN
	.2byte -1
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_GO_HOME
	.2byte EC_WORD_RIGHT
	.2byte EC_WORD_NOW
	.4byte gBattleFrontierTrainerMons_Amanda

@ 41
	.4byte FACILITY_CLASS_POKEFAN_F
	.string "STACY$", 8
@ pre-battle speech
	.2byte EC_WORD_ALL
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_THEIR
	.2byte EC_WORD_OWN
	.2byte EC_WORD_CUTE_CHARM
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SEE
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_I
	.2byte EC_WORD_NOT
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Stacy

@ 42
	.4byte FACILITY_CLASS_PKMN_BREEDER_M
	.string "RAFAEL$", 8
@ pre-battle speech
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_SEE
	.2byte EC_WORD_SOME
	.2byte EC_WORD_SPIRIT
@ win speech
	.2byte EC_WORD_THAT_S_IT_EXCL
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_THE
	.2byte EC_WORD_SPIRIT
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_WELL
	.2byte EC_WORD_SO
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_FOR
	.2byte EC_WORD_OUR
	.2byte EC_WORD_SPIRIT
	.4byte gBattleFrontierTrainerMons_Rafael

@ 43
	.4byte FACILITY_CLASS_PKMN_BREEDER_M
	.string "OLIVER$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_WORD_GENIUS
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_HOW
	.2byte EC_WORD_A
	.2byte EC_WORD_GENIUS
	.2byte EC_WORD_WORKS
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_MORE
	.2byte EC_WORD_A
	.2byte EC_WORD_GENIUS
	.2byte EC_WORD_THAN
	.2byte EC_WORD_I_AM
	.4byte gBattleFrontierTrainerMons_Oliver

@ 44
	.4byte FACILITY_CLASS_PKMN_BREEDER_M
	.string "PAYTON$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_TRAIN
	.2byte EC_WORD_FROM
	.2byte EC_WORD_THE
	.2byte EC_WORD_EGG
	.2byte EC_WORD_UP
@ win speech
	.2byte EC_WORD_WELL
	.2byte EC_WORD_DONE
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte -1
	.2byte -1
@ loss speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_A
	.2byte EC_MOVE2(SOFT_BOILED)
	.2byte EC_WORD_LOSS
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Payton

@ 45
	.4byte FACILITY_CLASS_POKEMON_BREEDER_F
	.string "PAMELA$", 8
@ pre-battle speech
	.2byte EC_WORD_ALL
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_A
	.2byte EC_WORD_KIND
	.2byte EC_WORD_TRAINER
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_TOO
	.2byte EC_WORD_BAD
	.2byte EC_WORD_YOU
	.2byte EC_WORD_LOST
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_KIND
	.2byte EC_WORD_AND
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_ALSO
	.2byte EC_WORD_STRONG
	.4byte gBattleFrontierTrainerMons_Pamela

@ 46
	.4byte FACILITY_CLASS_POKEMON_BREEDER_F
	.string "ELIZA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_MY
	.2byte EC_WORD_CHILDREN
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SO
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
@ loss speech
	.2byte EC_WORD_OH_DEAR
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SO
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_THIS
	.4byte gBattleFrontierTrainerMons_Eliza

@ 47
	.4byte FACILITY_CLASS_POKEMON_BREEDER_F
	.string "MARISA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_PROMISE
	.2byte EC_WORD_TO
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_SERIOUSLY
	.2byte -1
@ win speech
	.2byte EC_WORD_PROMISE
	.2byte EC_WORD_ME
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WILL
	.2byte EC_WORD_DO
	.2byte EC_WORD_BETTER
@ loss speech
	.2byte EC_WORD_PROMISE
	.2byte EC_WORD_ME
	.2byte EC_WORD_ANOTHER
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Marisa

@ 48
	.4byte FACILITY_CLASS_BUG_CATCHER
	.string "LEWIS$", 8
@ pre-battle speech
	.2byte EC_WORD_A_LITTLE
	.2byte EC_WORD_BUG
	.2byte EC_WORD_IS
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_QUES
	.2byte EC_WORD_HAHAHA
@ win speech
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_A
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_BUG
@ loss speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_A
	.2byte EC_WORD_BUG
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Lewis

@ 49
	.4byte FACILITY_CLASS_BUG_CATCHER
	.string "YOSHI$", 8
@ pre-battle speech
	.2byte EC_WORD_BUG
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_ME
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_LOVEY_DOVEY
@ win speech
	.2byte EC_WORD_BUG
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ARE
	.2byte EC_WORD_THE
	.2byte EC_WORD_BEST
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_IGNORANT
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_BUG
	.2byte EC_WORD_POKEMON
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Yoshi

@ 50
	.4byte FACILITY_CLASS_BUG_CATCHER
	.string "DESTIN$", 8
@ pre-battle speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_WAY
	.2byte EC_WORD_TOO
	.2byte EC_WORD_HOT
	.2byte EC_WORD_HERE
	.2byte -1
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_TO
	.2byte EC_MOVE(OVERHEAT)
	.2byte -1
	.2byte -1
@ loss speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_SOME
	.2byte EC_WORD_WATER
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Destin

@ 51
	.4byte FACILITY_CLASS_NINJA_BOY
	.string "KEON$", 8
@ pre-battle speech
	.2byte EC_WORD_FORGIVE
	.2byte EC_WORD_ME
	.2byte EC_WORD_BUT
	.2byte EC_WORD_HERE_I_COME
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_FORGIVE
	.2byte EC_WORD_ME
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_WORD_OVERWHELMING
	.2byte EC_WORD_POWER
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Keon

@ 52
	.4byte FACILITY_CLASS_NINJA_BOY
	.string "STUART$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_PROMISE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_A
	.2byte EC_WORD_HOT
	.2byte EC_WORD_BATTLE
@ win speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_MASTER
	.2byte EC_WORD_OF
	.2byte EC_WORD_COOL
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_ME
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SEE
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT
	.2byte EC_WORD_SO
	.2byte EC_WORD_COOL
	.4byte gBattleFrontierTrainerMons_Stuart

@ 53
	.4byte FACILITY_CLASS_NINJA_BOY
	.string "NESTOR$", 8
@ pre-battle speech
	.2byte EC_WORD_SHOW
	.2byte EC_WORD_ME
	.2byte EC_WORD_A
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_SMOOTH
	.2byte EC_WORD_MOVE
@ win speech
	.2byte EC_WORD_THERE
	.2byte EC_WORD_WAS
	.2byte EC_WORD_NOTHING
	.2byte EC_WORD_SMOOTH
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_THAT
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_ARE
	.2byte EC_WORD_SMOOTH
	.2byte EC_WORD_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Nestor

@ 54
	.4byte FACILITY_CLASS_BUG_MANIAC
	.string "DERRICK$", 8
@ pre-battle speech
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_SEE
	.2byte EC_WORD_YOU
	.2byte EC_MOVE2(MEDITATE)
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_ME
@ win speech
	.2byte EC_WORD_HOW
	.2byte EC_WORD_I
	.2byte EC_MOVE2(MEDITATE)
	.2byte EC_WORD_IS
	.2byte EC_WORD_JUST
	.2byte EC_WORD_BEAUTIFUL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_MOVE2(MEDITATE)
	.2byte EC_WORD_FOR
	.2byte EC_WORD_A
	.2byte EC_MOVE2(CALM_MIND)
	.4byte gBattleFrontierTrainerMons_Derrick

@ 55
	.4byte FACILITY_CLASS_BUG_MANIAC
	.string "BRYSON$", 8
@ pre-battle speech
	.2byte EC_MOVE2(POISON_POWDER)
	.2byte EC_WORD_IS
	.2byte EC_WORD_IN
	.2byte EC_WORD_OUR
	.2byte EC_MOVE2(COTTON_SPORE)
	.2byte EC_WORD_MOVE
@ win speech
	.2byte EC_WORD_HOW_DO
	.2byte EC_WORD_YOU
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_OUR
	.2byte EC_MOVE2(POISON_POWDER)
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(COTTON_SPORE)
	.2byte EC_WORD_WAS
	.2byte EC_WORD_USELESS
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Bryson

@ 56
	.4byte FACILITY_CLASS_BUG_MANIAC
	.string "CLAYTON$", 8
@ pre-battle speech
	.2byte EC_WORD_HUH_QUES
	.2byte -1
	.2byte -1
	.2byte EC_WORD_WHERE
	.2byte EC_WORD_IS_IT_QUES
	.2byte -1
@ win speech
	.2byte EC_WORD_WHERE
	.2byte EC_WORD_IS_IT_QUES
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_LOST
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKENAV
@ loss speech
	.2byte EC_WORD_WHERE
	.2byte EC_WORD_IS_IT_QUES
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_LOST
	.2byte EC_WORD_MY
	.2byte EC_WORD_SENSE
	.4byte gBattleFrontierTrainerMons_Clayton

@ 57
	.4byte FACILITY_CLASS_FISHERMAN
	.string "TRENTON$", 8
@ pre-battle speech
	.2byte EC_WORD_COME_OVER
	.2byte EC_WORD_FOR
	.2byte EC_WORD_SOME
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_WATER
	.2byte -1
@ win speech
	.2byte EC_WORD_MMM
	.2byte EC_WORD_DO
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WANT
	.2byte EC_WORD_SOME
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_GOT
	.2byte EC_WORD_THIS
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_WATER
	.2byte EC_WORD_SHOPPING
	.4byte gBattleFrontierTrainerMons_Trenton

@ 58
	.4byte FACILITY_CLASS_FISHERMAN
	.string "JENSON$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_WILL
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DOWNCAST
@ win speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_THE
	.2byte EC_MOVE(CUT)
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_THE
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_WHO_IS
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_DOWNCAST
	.4byte gBattleFrontierTrainerMons_Jenson

@ 59
	.4byte FACILITY_CLASS_FISHERMAN
	.string "WESLEY$", 8
@ pre-battle speech
	.2byte EC_POKEMON2(MEW)
	.2byte EC_POKEMON2(MEW)
	.2byte EC_WORD_IS
	.2byte EC_WORD_HOW
	.2byte EC_WORD_I
	.2byte EC_WORD_CRY
@ win speech
	.2byte EC_WORD_YES
	.2byte EC_WORD_I
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_CUTE
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_POKEMON2(MEW)
	.2byte EC_POKEMON2(MEW)
	.2byte EC_WORD_EXCL
	.2byte EC_POKEMON2(MEW)
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Wesley

@ 60
	.4byte FACILITY_CLASS_RUIN_MANIAC
	.string "ANTON$", 8
@ pre-battle speech
	.2byte EC_WORD_GET
	.2byte EC_WORD_READY
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
	.2byte EC_WORD_TO
	.2byte EC_MOVE(THRASH)
@ win speech
	.2byte EC_WORD_WAHAHAHA
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_THAT
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_A
	.2byte EC_WORD_TOUGH
	.2byte EC_WORD_LOSS
	.2byte EC_WORD_TO
	.2byte EC_MOVE2(SWALLOW)
	.4byte gBattleFrontierTrainerMons_Anton

@ 61
	.4byte FACILITY_CLASS_RUIN_MANIAC
	.string "LAWSON$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_YOUNG
	.2byte EC_WORD_AT
	.2byte EC_WORD_HEART
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_NOT
	.2byte EC_WORD_COOL
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_NOT
	.2byte EC_WORD_AT
	.2byte EC_WORD_ALL
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_OLD
	.2byte EC_WORD_AND
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_SHAKY
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Lawson

@ 62
	.4byte FACILITY_CLASS_RUIN_MANIAC
	.string "SAMMY$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_PARTY
	.2byte EC_WORD_IS
	.2byte EC_WORD_READY
	.2byte EC_WORD_TO
	.2byte EC_WORD_ROCK
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_PARTY
	.2byte EC_WORD_IS
	.2byte EC_WORD_JUST
	.2byte EC_WORD_INCREDIBLE
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CRY
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_WORD_PARTY
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Sammy

@ 63
	.4byte FACILITY_CLASS_COLLECTOR
	.string "ARNIE$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NO_1
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_NO
	.2byte EC_WORD_RIVAL
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SEE
	.2byte EC_WORD_QUES
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_LOSE
@ loss speech
	.2byte EC_WORD_NO
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_ACCEPT
	.2byte EC_WORD_THIS
	.4byte gBattleFrontierTrainerMons_Arnie

@ 64
	.4byte FACILITY_CLASS_COLLECTOR
	.string "ADRIAN$", 8
@ pre-battle speech
	.2byte EC_WORD_YAHOO
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_YAHOO
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_GOOD_BYE
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_GOOD_BYE
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Adrian

@ 65
	.4byte FACILITY_CLASS_COLLECTOR
	.string "TRISTAN$", 8
@ pre-battle speech
	.2byte EC_WORD_CONFUSED
	.2byte EC_WORD_QUES
	.2byte -1
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_A
	.2byte EC_WORD_GENIUS
@ win speech
	.2byte EC_WORD_SEE
	.2byte EC_WORD_QUES
	.2byte -1
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_A
	.2byte EC_WORD_GENIUS
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT
	.2byte EC_WORD_A
	.2byte EC_WORD_GENIUS
	.2byte EC_WORD_IN
	.2byte EC_WORD_BATTLE
	.4byte gBattleFrontierTrainerMons_Tristan

@ 66
	.4byte FACILITY_CLASS_PARASOL_LADY
	.string "JULIANA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_THINK
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SHOPPING
	.2byte EC_WORD_TOO
	.2byte EC_WORD_MUCH
@ win speech
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_A
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_PLUSH_DOLL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SO
	.2byte EC_WORD_WANT
	.2byte EC_WORD_ANOTHER
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_PLUSH_DOLL
	.4byte gBattleFrontierTrainerMons_Juliana

@ 67
	.4byte FACILITY_CLASS_PARASOL_LADY
	.string "RYLEE$", 8
@ pre-battle speech
	.2byte EC_WORD_SHOW
	.2byte EC_WORD_ME
	.2byte EC_WORD_THAT
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_GUTS
@ win speech
	.2byte EC_WORD_BYE_BYE
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_NO
	.2byte EC_WORD_GUTS
@ loss speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_GUTSY
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_QUITE
	.2byte EC_WORD_SUPER
	.4byte gBattleFrontierTrainerMons_Rylee

@ 68
	.4byte FACILITY_CLASS_PARASOL_LADY
	.string "CHELSEA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SERIOUSLY
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_TO
	.2byte EC_WORD_WIN
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_MY
	.2byte EC_WORD_WILL
	.2byte EC_WORD_TO
	.2byte EC_WORD_WIN
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_FAR
	.2byte EC_WORD_TOO_STRONG
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Chelsea

@ 69
	.4byte FACILITY_CLASS_BEAUTY
	.string "DANELA$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_MUST_BE
	.2byte EC_WORD_MY
	.2byte EC_WORD_OPPONENT
	.2byte EC_WORD_NOW
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_OH_DEAR
	.2byte EC_WORD_TOO_WEAK
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_GIVE_UP
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_AND
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_GOOD_BYE
	.4byte gBattleFrontierTrainerMons_Danela

@ 70
	.4byte FACILITY_CLASS_BEAUTY
	.string "LIZBETH$", 8
@ pre-battle speech
	.2byte EC_WORD_IF_I_LOSE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_MOVE2(PRESENT)
@ win speech
	.2byte EC_WORD_HERE_IT_IS
	.2byte EC_WORD_A_LITTLE
	.2byte EC_WORD_PRAISE
	.2byte EC_WORD_AS
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE2(PRESENT)
@ loss speech
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE2(PRESENT)
	.2byte EC_WORD_QUES_EXCL
	.2byte EC_WORD_HERE_IT_IS
	.2byte EC_WORD_A
	.2byte EC_MOVE(DOUBLE_SLAP)
	.4byte gBattleFrontierTrainerMons_Lizbeth

@ 71
	.4byte FACILITY_CLASS_BEAUTY
	.string "AMELIA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_BELIEVE
	.2byte EC_WORD_IN
	.2byte EC_WORD_CUTE
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_APPEAL
@ win speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_SENSE
	.2byte EC_WORD_IS
	.2byte EC_WORD_A
	.2byte EC_WORD_DISASTER
@ loss speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_AWFUL
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_HOME
	.4byte gBattleFrontierTrainerMons_Amelia

@ 72
	.4byte FACILITY_CLASS_AROMA_LADY
	.string "JILLIAN$", 8
@ pre-battle speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_IS
	.2byte EC_WORD_THAT
	.2byte EC_WORD_I
	.2byte EC_WORD_SMELL
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_THE
	.2byte EC_MOVE(SWEET_SCENT)
	.2byte EC_WORD_OF
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_WATER
@ loss speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_OFFENSIVE
	.2byte EC_WORD_STENCH
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_WHAT
	.4byte gBattleFrontierTrainerMons_Jillian

@ 73
	.4byte FACILITY_CLASS_AROMA_LADY
	.string "ABBIE$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_TRY
	.2byte EC_WORD_MY
	.2byte EC_WORD_SECRET
	.2byte EC_MOVE(AROMATHERAPY)
	.2byte EC_WORD_OK_QUES
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE(AROMATHERAPY)
	.2byte EC_WORD_IS
	.2byte EC_WORD_TERRIBLE
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOU
@ loss speech
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SMELL
	.2byte EC_WORD_A
	.2byte EC_WORD_THING
	.2byte EC_WORD_QUES_EXCL
	.4byte gBattleFrontierTrainerMons_Abbie

@ 74
	.4byte FACILITY_CLASS_AROMA_LADY
	.string "BRIANA$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_BOY
	.2byte EC_WORD_FRIEND
	.2byte EC_WORD_WORKS
	.2byte EC_WORD_TOO
	.2byte EC_WORD_MUCH
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_MISS
	.2byte EC_WORD_HIM
	.2byte EC_WORD_MORE
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SO
	.2byte EC_WORD_LONESOME
	.2byte EC_WORD_WITHOUT
	.2byte EC_WORD_HIM
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Briana

@ 75
	.4byte FACILITY_CLASS_GUITARIST
	.string "ANTONIO$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_HOW
	.2byte EC_WORD_TO
	.2byte EC_WORD_GO
	.2byte EC_WORD_GO
@ win speech
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_TO
	.2byte EC_WORD_DANCE
@ loss speech
	.2byte EC_WORD_GO
	.2byte EC_WORD_GO
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_JUST
	.2byte EC_MOVE(FLAIL)
	.2byte EC_WORD_ABOUT
	.4byte gBattleFrontierTrainerMons_Antonio

@ 76
	.4byte FACILITY_CLASS_GUITARIST
	.string "JADEN$", 8
@ pre-battle speech
	.2byte EC_WORD_HELLO
	.2byte EC_WORD_I
	.2byte EC_WORD_THINK
	.2byte EC_WORD_I
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_YOU
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_ME
	.2byte EC_MOVE(THRASH)
	.2byte EC_WORD_IN
	.2byte EC_MOVE2(FRUSTRATION)
@ loss speech
	.2byte EC_WORD_THIS_IS_IT_EXCL
	.2byte -1
	.2byte -1
	.2byte EC_WORD_GOOD_BYE
	.2byte EC_WORD_FOREVER
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Jaden

@ 77
	.4byte FACILITY_CLASS_GUITARIST
	.string "DAKOTA$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_TO
	.2byte EC_WORD_DANCE
	.2byte EC_WORD_WITH
	.2byte EC_WORD_POWER
@ win speech
	.2byte EC_WORD_GOT
	.2byte EC_WORD_IT
	.2byte EC_WORD_QUES
	.2byte EC_WORD_DANCE
	.2byte EC_WORD_WITH
	.2byte EC_WORD_POWER
@ loss speech
	.2byte EC_WORD_OKAY
	.2byte EC_WORD_YOU
	.2byte EC_WORD_UNDERSTAND
	.2byte EC_WORD_ALL_RIGHT
	.2byte EC_WORD_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Dakota

@ 78
	.4byte FACILITY_CLASS_BIRD_KEEPER
	.string "BRAYDEN$", 8
@ pre-battle speech
	.2byte EC_WORD_COLOR_CHANGE
	.2byte EC_WORD_VERSION
	.2byte EC_WORD_TOYS
	.2byte EC_WORD_ARE
	.2byte EC_WORD_USELESS
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_COLLECT
	.2byte EC_WORD_NORMAL
	.2byte EC_WORD_VERSION
	.2byte EC_WORD_TOYS
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_MOVE2(ATTRACT)
	.2byte EC_WORD_COLOR_CHANGE
	.2byte EC_WORD_VERSION
	.2byte EC_WORD_TOYS
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Brayden

@ 79
	.4byte FACILITY_CLASS_BIRD_KEEPER
	.string "CORSON$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_GET
	.2byte EC_WORD_TO
	.2byte EC_MOVE2(BEAT_UP)
	.2byte EC_WORD_ON
	.2byte EC_WORD_YOU
@ win speech
	.2byte EC_WORD_TOO
	.2byte EC_WORD_EASY
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SO
	.2byte EC_WORD_COOL
@ loss speech
	.2byte EC_WORD_WHY
	.2byte EC_WORD_QUES_EXCL
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_MOVE2(CURSE)
	.2byte EC_WORD_YOU
	.4byte gBattleFrontierTrainerMons_Corson

@ 80
	.4byte FACILITY_CLASS_BIRD_KEEPER
	.string "TREVIN$", 8
@ pre-battle speech
	.2byte EC_WORD_THERE
	.2byte EC_WORD_IS
	.2byte EC_WORD_NONE
	.2byte EC_WORD_BETTER
	.2byte EC_WORD_THAN
	.2byte EC_WORD_ME
@ win speech
	.2byte EC_WORD_YES_SIR_EXCL
	.2byte -1
	.2byte -1
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_THE
	.2byte EC_WORD_BEST
@ loss speech
	.2byte EC_WORD_SERIOUS
	.2byte EC_WORD_QUES_EXCL
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Trevin

@ 81
	.4byte FACILITY_CLASS_SAILOR
	.string "PATRICK$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_PERFECT
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_GIVE_UP
	.2byte EC_WORD_NOW
	.2byte -1
@ win speech
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_BE
	.2byte EC_WORD_DISAPPOINTED
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_PERFECT
	.2byte -1
@ loss speech
	.2byte EC_WORD_BUT
	.2byte EC_WORD_HOW
	.2byte EC_WORD_QUES
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_PERFECT
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Patrick

@ 82
	.4byte FACILITY_CLASS_SAILOR
	.string "KADEN$", 8
@ pre-battle speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_ARE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_UP
	.2byte EC_WORD_TO
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WERE
	.2byte EC_WORD_A
	.2byte EC_WORD_SURPRISE
	.2byte EC_WORD_TO_ME
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_WHO
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Kaden

@ 83
	.4byte FACILITY_CLASS_SAILOR
	.string "MAXWELL$", 8
@ pre-battle speech
	.2byte EC_WORD_HEY_THERE
	.2byte EC_WORD_WHO_IS
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_RIVAL
	.2byte EC_WORD_QUES
	.2byte -1
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_RIVAL
	.2byte EC_WORD_IS
	.2byte EC_WORD_MY
	.2byte EC_WORD_GIRL
	.2byte EC_WORD_FRIEND
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_MAKING
	.2byte EC_WORD_YOU
	.2byte EC_WORD_MY
	.2byte EC_WORD_RIVAL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Maxwell

@ 84
	.4byte FACILITY_CLASS_HIKER
	.string "DARYL$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_HOW
	.2byte EC_WORD_TO
	.2byte EC_MOVE(CHARGE)
@ win speech
	.2byte EC_WORD_AM
	.2byte EC_WORD_I
	.2byte EC_WORD_OVERWHELMING
	.2byte EC_WORD_OR
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_A
	.2byte EC_WORD_LEGEND
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Daryl

@ 85
	.4byte FACILITY_CLASS_HIKER
	.string "KENNETH$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_BETTER
	.2byte EC_WORD_NOT
	.2byte EC_MOVE2(SLACK_OFF)
	.2byte EC_WORD_WITH
	.2byte EC_WORD_ME
@ win speech
	.2byte EC_WORD_DID
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(TAUNT)
	.2byte EC_WORD_INTIMIDATE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Kenneth

@ 86
	.4byte FACILITY_CLASS_HIKER
	.string "RICH$", 8
@ pre-battle speech
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE(FACADE)
	.2byte EC_WORD_DOESN_T
	.2byte EC_MOVE2(TRICK)
	.2byte EC_WORD_ME
	.2byte -1
@ win speech
	.2byte EC_WORD_SERIOUSLY
	.2byte EC_WORD_ARE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_OK_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_TOUGH
	.2byte EC_WORD_ON
	.2byte EC_WORD_ME
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Rich

@ 87
	.4byte FACILITY_CLASS_KINDLER
	.string "CADEN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_BE
	.2byte EC_WORD_DEFEATED
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_FIRE
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_FIRE
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TIRED
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_SO
	.2byte EC_WORD_HOT
	.4byte gBattleFrontierTrainerMons_Caden

@ 88
	.4byte FACILITY_CLASS_KINDLER
	.string "MARLON$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_WORD_POKEDEX
	.2byte EC_WORD_IS
	.2byte EC_WORD_A_LITTLE
	.2byte EC_WORD_RADIO
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_A_LITTLE
	.2byte EC_WORD_RADIO
	.2byte EC_WORD_HUH_QUES
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_TOTALLY
	.2byte EC_WORD_COOL
@ loss speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_NOT
	.2byte EC_WORD_QUES
	.2byte EC_WORD_IS
	.2byte EC_WORD_POKENAV
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Marlon

@ 89
	.4byte FACILITY_CLASS_KINDLER
	.string "NASH$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_ON
	.2byte EC_WORD_FIRE
	.2byte EC_WORD_BABY
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LEFT
	.2byte EC_WORD_YOU
	.2byte EC_WORD_JUST
	.2byte EC_WORD_AN
	.2byte EC_MOVE2(EMBER)
@ loss speech
	.2byte EC_WORD_AIYEEH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_NO
	.2byte EC_WORD_WATER
	.2byte EC_WORD_PLEASE
	.4byte gBattleFrontierTrainerMons_Nash

@ 90
	.4byte FACILITY_CLASS_RUNNING_TRIATHLETE_M
	.string "ROBBY$", 8
@ pre-battle speech
	.2byte EC_WORD_HAHAHA
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_TO
	.2byte EC_WORD_MEET_YOU
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_THE
	.2byte EC_WORD_LEADER
	.2byte EC_WORD_WITH
	.2byte EC_WORD_REFRESHING
	.2byte EC_WORD_SERENE_GRACE
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_MOVE(THRASH)
	.2byte EC_WORD_MY
	.2byte EC_WORD_TOYS
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Robby

@ 91
	.4byte FACILITY_CLASS_RUNNING_TRIATHLETE_M
	.string "REECE$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(QUICK_ATTACK)
	.2byte EC_WORD_CAN
	.2byte EC_WORD_BEAT
	.2byte EC_WORD_A
	.2byte EC_MOVE2(TELEPORT)
@ win speech
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_I
	.2byte EC_WORD_SAID
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_DARN
	.2byte EC_WORD_FAST
@ loss speech
	.2byte EC_WORD_I_WAS
	.2byte EC_WORD_KIDDING
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_THAT
	.2byte EC_MOVE2(TELEPORT)
	.2byte EC_WORD_THING
	.4byte gBattleFrontierTrainerMons_Reece

@ 92
	.4byte FACILITY_CLASS_RUNNING_TRIATHLETE_F
	.string "KATHRYN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_TRAIN
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_ENOUGH
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_DON_T
	.2byte EC_MOVE2(TAUNT)
	.2byte EC_WORD_ME
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_THAT
	.2byte EC_WORD_OK_QUES
@ loss speech
	.2byte EC_WORD_WHY
	.2byte EC_WORD_COULDN_T
	.2byte EC_WORD_I
	.2byte EC_WORD_WIN
	.2byte EC_WORD_THIS
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Kathryn

@ 93
	.4byte FACILITY_CLASS_RUNNING_TRIATHLETE_F
	.string "ELLEN$", 8
@ pre-battle speech
	.2byte EC_WORD_CRUSH
	.2byte EC_WORD_YOU
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_AN
	.2byte EC_WORD_EGG
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_A
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_VICTORY
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
@ loss speech
	.2byte EC_WORD_TOO
	.2byte EC_WORD_TOUGH
	.2byte EC_WORD_TO
	.2byte EC_WORD_CRUSH
	.2byte EC_WORD_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Ellen

@ 94
	.4byte FACILITY_CLASS_SWIMMING_TRIATHLETE_M
	.string "RAMON$", 8
@ pre-battle speech
	.2byte EC_WORD_OKAY
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_PERFECTION
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_THAT
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_A
	.2byte EC_WORD_SECRET
	.2byte EC_WORD_WHY
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_HAPPY
	.4byte gBattleFrontierTrainerMons_Ramon

@ 95
	.4byte FACILITY_CLASS_SWIMMING_TRIATHLETE_M
	.string "ARTHUR$", 8
@ pre-battle speech
	.2byte EC_WORD_HERE_I_COME
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_READY
	.2byte EC_WORD_FOR
	.2byte EC_WORD_IT
	.2byte EC_WORD_ALL
@ win speech
	.2byte EC_WORD_THAT_S_IT_EXCL
	.2byte -1
	.2byte -1
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_FABULOUS
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_NOT
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Arthur

@ 96
	.4byte FACILITY_CLASS_SWIMMING_TRIATHLETE_F
	.string "ALONDRA$", 8
@ pre-battle speech
	.2byte EC_WORD_EVERY
	.2byte EC_WORD_DAY
	.2byte EC_WORD_IS
	.2byte EC_WORD_A
	.2byte EC_WORD_GREAT
	.2byte EC_WORD_DAY
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(DIVE)
	.2byte EC_WORD_WILL
	.2byte EC_WORD_BE
	.2byte EC_WORD_A
	.2byte EC_WORD_LEGEND
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(DIVE)
	.2byte EC_WORD_LEFT
	.2byte EC_WORD_ME
	.2byte EC_WORD_COLD
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Alondra

@ 97
	.4byte FACILITY_CLASS_SWIMMING_TRIATHLETE_F
	.string "ADRIANA$", 8
@ pre-battle speech
	.2byte EC_WORD_COME
	.2byte EC_WORD_SEE
	.2byte EC_WORD_AN
	.2byte EC_WORD_INCREDIBLE
	.2byte EC_WORD_SWIFT_SWIM
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_IT
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_SO
	.2byte EC_WORD_EASY
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_MOVE2(BEAT_UP)
	.2byte EC_WORD_AND
	.2byte EC_WORD_TIRED
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Adriana

@ 98
	.4byte FACILITY_CLASS_CYCLING_TRIATHLETE_M
	.string "MALIK$", 8
@ pre-battle speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_NOT
	.2byte EC_WORD_ANOTHER
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_FINALLY
	.2byte EC_WORD_WON
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TIRED
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_FINALLY
	.2byte EC_WORD_LOST
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TIRED
	.4byte gBattleFrontierTrainerMons_Malik

@ 99
	.4byte FACILITY_CLASS_CYCLING_TRIATHLETE_F
	.string "JILL$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_THE
	.2byte EC_MOVE2(QUICK_ATTACK)
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_THE
	.2byte EC_MOVE2(QUICK_ATTACK)
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_WINS
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_THE
	.2byte EC_MOVE2(QUICK_ATTACK)
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_GIVES
	.2byte EC_WORD_UP
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Jill

@ 100
	.4byte FACILITY_CLASS_RUNNING_TRIATHLETE_M
	.string "ERIK$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_THE
	.2byte EC_WORD_SPEED_BOOST
	.2byte EC_WORD_HERO
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_FROM
	.2byte EC_WORD_THE
	.2byte EC_WORD_SPEED_BOOST
	.2byte EC_WORD_HERO
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_WAAAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_NO
	.2byte EC_WORD_NO
	.2byte EC_WORD_EXCL_EXCL
	.4byte gBattleFrontierTrainerMons_Erik

@ 101
	.4byte FACILITY_CLASS_RUNNING_TRIATHLETE_F
	.string "YAZMIN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WOULD
	.2byte EC_WORD_RATHER
	.2byte EC_WORD_RUN
	.2byte EC_WORD_THAN
	.2byte EC_WORD_BIKE
@ win speech
	.2byte EC_WORD_YES
	.2byte EC_WORD_I
	.2byte EC_WORD_WOULD
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_RATHER
	.2byte EC_WORD_RUN
@ loss speech
	.2byte EC_WORD_BYE_BYE
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_RUN_AWAY
	.4byte gBattleFrontierTrainerMons_Yazmin

@ 102
	.4byte FACILITY_CLASS_SWIMMING_TRIATHLETE_M
	.string "JAMAL$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_BE
	.2byte EC_WORD_A
	.2byte EC_WORD_FATHER
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_WAIT
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_WORD_BABY
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_BABY
	.2byte EC_WORD_WILL
	.2byte EC_WORD_BE
	.2byte EC_WORD_TOTALLY
	.2byte EC_WORD_AWESOME
	.4byte gBattleFrontierTrainerMons_Jamal

@ 103
	.4byte FACILITY_CLASS_SWIMMING_TRIATHLETE_F
	.string "LESLIE$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_BE
	.2byte EC_WORD_A
	.2byte EC_WORD_MOTHER
@ win speech
	.2byte EC_WORD_A
	.2byte EC_WORD_BABY
	.2byte EC_WORD_WILL
	.2byte EC_WORD_BE
	.2byte EC_WORD_A_LITTLE
	.2byte EC_WORD_CHALLENGE
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TOO
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_TO
	.2byte EC_WORD_BE
	.2byte EC_WORD_ANGRY
	.4byte gBattleFrontierTrainerMons_Leslie

@ 104
	.4byte FACILITY_CLASS_CYCLING_TRIATHLETE_M
	.string "DAVE$", 8
@ pre-battle speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_I
	.2byte EC_WORD_DO
	.2byte EC_WORD_TODAY
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_ENJOY
	.2byte EC_WORD_SOME
	.2byte EC_WORD_SPORTS
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_GO
	.2byte EC_WORD_PLAY
	.2byte EC_WORD_A
	.2byte EC_WORD_GAME
	.4byte gBattleFrontierTrainerMons_Dave

@ 105
	.4byte FACILITY_CLASS_CYCLING_TRIATHLETE_M
	.string "CARLO$", 8
@ pre-battle speech
	.2byte EC_WORD_HAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_YEAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DO
	.2byte EC_WORD_THINGS
	.2byte EC_WORD_AT
	.2byte EC_MOVE(EXTREME_SPEED)
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LOST
	.2byte EC_WORD_AT
	.2byte EC_MOVE(EXTREME_SPEED)
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Carlo

@ 106
	.4byte FACILITY_CLASS_CYCLING_TRIATHLETE_F
	.string "EMILIA$", 8
@ pre-battle speech
	.2byte EC_WORD_ME
	.2byte EC_WORD_WORRY
	.2byte EC_WORD_QUES
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_NONE
@ win speech
	.2byte EC_WORD_AHAHA
	.2byte EC_WORD_SEE
	.2byte EC_WORD_QUES
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_FANTASTIC
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_AHAHA
	.2byte EC_WORD_SEE
	.2byte EC_WORD_QUES
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_ENTERTAINING
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Emilia

@ 107
	.4byte FACILITY_CLASS_CYCLING_TRIATHLETE_F
	.string "DALIA$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_BIKE
	.2byte EC_WORD_IS
	.2byte EC_WORD_VERY
	.2byte EC_WORD_EXPENSIVE
	.2byte -1
@ win speech
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_COME
	.2byte EC_WORD_NEAR
	.2byte EC_WORD_MY
	.2byte EC_WORD_BIKE
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_BIKE
	.2byte EC_WORD_IS
	.2byte EC_WORD_MY
	.2byte EC_WORD_BEST
	.2byte EC_WORD_FRIEND
	.4byte gBattleFrontierTrainerMons_Dalia

@ 108
	.4byte FACILITY_CLASS_BLACK_BELT
	.string "HITOMI$", 8
@ pre-battle speech
	.2byte EC_WORD_YEAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_HAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_QUES_EXCL
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
	.2byte EC_WORD_QUES_EXCL
@ loss speech
	.2byte EC_WORD_AIYEEH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_EXCL_EXCL
	.4byte gBattleFrontierTrainerMons_Hitomi

@ 109
	.4byte FACILITY_CLASS_BLACK_BELT
	.string "RICARDO$", 8
@ pre-battle speech
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_PLAY
	.2byte EC_WORD_TIME
	.2byte EC_WORD_IS
	.2byte EC_WORD_OVER
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_OUT
	.2byte EC_WORD_OF
	.2byte EC_WORD_HERE
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_HIT
	.2byte EC_WORD_ME
	.2byte EC_WORD_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Ricardo

@ 110
	.4byte FACILITY_CLASS_BLACK_BELT
	.string "SHIZUKA$", 8
@ pre-battle speech
	.2byte EC_WORD_SHOW
	.2byte EC_WORD_ME
	.2byte EC_WORD_THAT
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_SERIOUS
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_FORGET
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_YOU
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_PERFECT
	.2byte EC_WORD_IN
	.2byte EC_WORD_EVERY
	.2byte EC_WORD_WAY
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Shizuka

@ 111
	.4byte FACILITY_CLASS_BATTLE_GIRL
	.string "JOANA$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_LOSE
	.2byte EC_WORD_RIGHT
	.2byte EC_WORD_AWAY
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_THE
	.2byte EC_WORD_WINNER
	.2byte EC_WORD_HEAR
	.2byte EC_WORD_ME
	.2byte EC_MOVE2(ROAR)
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_REFUSE
	.2byte EC_WORD_TO
	.2byte EC_WORD_ACCEPT
	.2byte EC_WORD_THAT
	.2byte EC_MOVE(OUTRAGE)
	.4byte gBattleFrontierTrainerMons_Joana

@ 112
	.4byte FACILITY_CLASS_BATTLE_GIRL
	.string "KELLY$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_NIGHT
	.2byte EC_WORD_SCHOOL
	.2byte EC_WORD_IS
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_SCARY
@ win speech
	.2byte EC_WORD_A
	.2byte EC_WORD_LADY
	.2byte EC_WORD_GHOST
	.2byte EC_WORD_APPEARS
	.2byte EC_WORD_THERE
	.2byte -1
@ loss speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_HOME
	.2byte EC_WORD_WORK
	.2byte EC_WORD_IS
	.2byte EC_WORD_AWFULLY
	.2byte EC_WORD_SCARY
	.4byte gBattleFrontierTrainerMons_Kelly

@ 113
	.4byte FACILITY_CLASS_BATTLE_GIRL
	.string "RAYNA$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NO_1
	.2byte EC_WORD_WHEN
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_POWER
@ win speech
	.2byte EC_WORD_UNDERSTAND
	.2byte EC_WORD_MY
	.2byte EC_WORD_POWER
	.2byte EC_WORD_NOW
	.2byte EC_WORD_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_TERRIBLE
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TERRIBLE
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Rayna

@ 114
	.4byte FACILITY_CLASS_EXPERT_M
	.string "EVAN$", 8
@ pre-battle speech
	.2byte EC_WORD_EVERY
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_HAS
	.2byte EC_WORD_A
	.2byte EC_WORD_SMELL
	.2byte -1
@ win speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_THE
	.2byte EC_MOVE(SWEET_SCENT)
	.2byte EC_WORD_OF
	.2byte EC_WORD_VICTORY
@ loss speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_AWFUL
	.2byte EC_WORD_STENCH
	.2byte EC_WORD_OF
	.2byte EC_WORD_A
	.2byte EC_WORD_LOSS
	.4byte gBattleFrontierTrainerMons_Evan

@ 115
	.4byte FACILITY_CLASS_EXPERT_M
	.string "JORDAN$", 8
@ pre-battle speech
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_BEAT
	.2byte EC_WORD_ME
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_QUES_EXCL
	.2byte -1
	.2byte EC_WORD_BUT
	.2byte EC_WORD_HOW
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Jordan

@ 116
	.4byte FACILITY_CLASS_EXPERT_M
	.string "JOEL$", 8
@ pre-battle speech
	.2byte EC_WORD_FUFUFU
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
@ win speech
	.2byte EC_WORD_GIGGLE
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
@ loss speech
	.2byte EC_WORD_HAHAHA
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Joel

@ 117
	.4byte FACILITY_CLASS_EXPERT_F
	.string "KRISTEN$", 8
@ pre-battle speech
	.2byte EC_WORD_HAHAHA
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte EC_WORD_A
	.2byte EC_WORD_KID
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_WORD_JUST
	.2byte EC_WORD_A_LITTLE
	.2byte EC_WORD_KID
	.2byte EC_WORD_AFTER
	.2byte EC_WORD_ALL
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_A
	.2byte EC_WORD_TOUGH
	.2byte EC_WORD_KID
	.2byte EC_WORD_HUH_QUES
	.2byte EC_WORD_HUMPH
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Kristen

@ 118
	.4byte FACILITY_CLASS_EXPERT_F
	.string "SELPHY$", 8
@ pre-battle speech
	.2byte EC_WORD_HUH_QUES
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_IS_IT_QUES
	.2byte -1
	.2byte -1
	.2byte -1
@ win speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_YES
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_WHY
	.2byte EC_WORD_NOT
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_NO
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_WHY
	.2byte EC_WORD_NOT
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Selphy

@ 119
	.4byte FACILITY_CLASS_EXPERT_F
	.string "CHLOE$", 8
@ pre-battle speech
	.2byte EC_WORD_COME
	.2byte EC_WORD_WE
	.2byte EC_WORD_WILL
	.2byte EC_WORD_DO
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_NOW
@ win speech
	.2byte EC_WORD_MORE
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_ANOTHER
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_STRONG
	.2byte EC_WORD_YOU
	.2byte EC_WORD_ARE
	.4byte gBattleFrontierTrainerMons_Chloe

@ 120
	.4byte FACILITY_CLASS_PSYCHIC_M
	.string "NORTON$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_YOU
	.2byte -1
	.2byte -1
@ win speech
	.2byte EC_WORD_EXCUSE_ME
	.2byte EC_WORD_BUT
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_A
	.2byte EC_WORD_PUSHOVER
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_SOME
	.2byte EC_WORD_KIND
	.2byte EC_WORD_OF
	.2byte EC_WORD_AWESOME
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Norton

@ 121
	.4byte FACILITY_CLASS_PSYCHIC_M
	.string "LUKAS$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_JOKING
	.2byte EC_WORD_IS
	.2byte EC_WORD_PRETTY
	.2byte EC_WORD_TERRIBLE
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_ROCK_HEAD
	.2byte EC_WORD_EXISTS
	.2byte EC_WORD_TO
	.2byte EC_WORD_SHINE
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_ROCK_HEAD
	.2byte EC_WORD_COME
	.2byte EC_WORD_TO
	.2byte EC_WORD_SHINE
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Lukas

@ 122
	.4byte FACILITY_CLASS_PSYCHIC_M
	.string "ZACH$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_AN
	.2byte EC_WORD_EXCELLENT
	.2byte EC_MOVE2(MIMIC)
	.2byte EC_WORD_OF
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_A_LITTLE
	.2byte EC_POKEMON2(TOGEPI)
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_ANGRY
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_A
	.2byte EC_POKEMON2(MANKEY)
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Zach

@ 123
	.4byte FACILITY_CLASS_PSYCHIC_F
	.string "KAITLYN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CRUSH
	.2byte EC_WORD_THINGS
	.2byte EC_WORD_WITH
	.2byte EC_WORD_PSYCHIC
	.2byte EC_WORD_POWER
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_VICTORY
	.2byte EC_WORD_WILL
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_THE
	.2byte EC_WORD_NEWS
@ loss speech
	.2byte EC_WORD_NO
	.2byte EC_WORD_NO
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_THIS
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_DO
	.4byte gBattleFrontierTrainerMons_Kaitlyn

@ 124
	.4byte FACILITY_CLASS_PSYCHIC_F
	.string "BREANNA$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_WILL
	.2byte EC_WORD_CRUSH
	.2byte EC_WORD_YOU
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_SOME
	.2byte EC_WORD_MORE
	.2byte EC_WORD_OF
	.2byte EC_WORD_THIS
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_GUTS
	.2byte EC_WORD_AND
	.2byte EC_WORD_SKILL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Breanna

@ 125
	.4byte FACILITY_CLASS_PSYCHIC_F
	.string "KENDRA$", 8
@ pre-battle speech
	.2byte EC_WORD_IF
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_SMART
	.2byte EC_WORD_STOP
	.2byte EC_WORD_RIGHT
	.2byte EC_WORD_NOW
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SAID
	.2byte EC_WORD_THAT
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_STOP
@ loss speech
	.2byte EC_WORD_WHY
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_YOU
	.2byte EC_WORD_STOP
	.2byte EC_WORD_QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Kendra

@ 126
	.4byte FACILITY_CLASS_HEX_MANIAC
	.string "MOLLY$", 8
@ pre-battle speech
	.2byte EC_WORD_WILL
	.2byte EC_WORD_MY
	.2byte EC_WORD_CUTE_CHARM
	.2byte EC_MOVE2(ATTRACT)
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ARE
	.2byte EC_WORD_MY
	.2byte EC_WORD_TOYS
	.2byte EC_WORD_NOW
@ loss speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_HOW
	.2byte EC_WORD_COULD
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Molly

@ 127
	.4byte FACILITY_CLASS_HEX_MANIAC
	.string "JAZMIN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_FORECAST
	.2byte EC_WORD_TERRIBLE
	.2byte EC_WORD_THINGS
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOU
@ win speech
	.2byte EC_WORD_THERE
	.2byte EC_WORD_WASN_T
	.2byte EC_WORD_MY
	.2byte EC_WORD_FORECAST
	.2byte EC_WORD_RIGHT
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(FORESIGHT)
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_SHOW
	.2byte EC_WORD_ME
	.2byte EC_WORD_THIS
	.4byte gBattleFrontierTrainerMons_Jazmin

@ 128
	.4byte FACILITY_CLASS_HEX_MANIAC
	.string "KELSEY$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVEN_T
	.2byte EC_WORD_SLEPT
	.2byte EC_WORD_IN
	.2byte EC_WORD_DAYS
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_SLEEP
	.2byte EC_WORD_WILL
	.2byte EC_WORD_BE
	.2byte EC_WORD_EXCELLENT
	.2byte EC_WORD_NOW
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_DESTROYED
	.2byte EC_WORD_MY
	.2byte EC_WORD_SLEEP
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Kelsey

@ 129
	.4byte FACILITY_CLASS_POKEMANIAC
	.string "JALEN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_ALLOW
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_TO
	.2byte EC_MOVE(THRASH)
@ win speech
	.2byte EC_WORD_HAHAHA
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_ARE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_ANGRY
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_WHY
	.2byte EC_WORD_IS
	.2byte EC_WORD_THIS
	.2byte EC_WORD_SO
	.2byte EC_WORD_HARD
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Jalen

@ 130
	.4byte FACILITY_CLASS_POKEMANIAC
	.string "GRIFFEN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_MOVE2(SWALLOW)
	.2byte EC_MOVE2(SLUDGE)
	.2byte EC_WORD_TO
	.2byte EC_MOVE2(TRANSFORM)
	.2byte EC_WORD_MYSELF
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_MOVE(GROWTH)
	.2byte EC_WORD_OF
	.2byte EC_MOVE2(ACID_ARMOR)
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_MOVE(GROWTH)
	.2byte EC_WORD_OF
	.2byte EC_WORD_SUCTION_CUPS
	.4byte gBattleFrontierTrainerMons_Griffen

@ 131
	.4byte FACILITY_CLASS_POKEMANIAC
	.string "XANDER$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_GOT
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ON
	.2byte EC_WORD_RENTAL
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_INCREDIBLE
	.2byte EC_WORD_MY
	.2byte EC_WORD_RENTAL
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_WON
@ loss speech
	.2byte EC_WORD_RENTAL
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_UP
	.2byte EC_WORD_TO
	.2byte EC_MOVE2(SCRATCH)
	.4byte gBattleFrontierTrainerMons_Xander

@ 132
	.4byte FACILITY_CLASS_GENTLEMAN
	.string "MARVIN$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_UP
	.2byte EC_WORD_TO
	.2byte EC_WORD_THE
	.2byte EC_WORD_CHALLENGE
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_THINK
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_ENOUGH
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_PERFECT
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_SO
	.2byte EC_WORD_MUCH
	.4byte gBattleFrontierTrainerMons_Marvin

@ 133
	.4byte FACILITY_CLASS_GENTLEMAN
	.string "BRENNAN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_MOVE2(WISH)
	.2byte EC_WORD_TO
	.2byte EC_WORD_SEE
	.2byte EC_WORD_THE
	.2byte EC_WORD_NEWS
@ win speech
	.2byte EC_WORD_COMICS
	.2byte EC_WORD_GET
	.2byte EC_WORD_DAMP
	.2byte EC_WORD_FROM
	.2byte EC_WORD_DRIZZLE
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_TIGHT
	.2byte EC_WORD_MONEY
	.2byte EC_WORD_LIVING
	.2byte EC_WORD_CHANNEL
	.2byte EC_WORD_QUES_EXCL
	.4byte gBattleFrontierTrainerMons_Brennan

@ 134
	.4byte FACILITY_CLASS_BUG_MANIAC
	.string "BALEY$", 8
@ pre-battle speech
	.2byte EC_MOVE(SCREECH)
	.2byte EC_WORD_IS
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_MUSIC
	.2byte EC_WORD_TO_ME
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE(SCREECH)
	.2byte EC_WORD_STRATEGY
	.2byte EC_WORD_IS
	.2byte EC_WORD_THE
	.2byte EC_WORD_BEST
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_SOUNDPROOF
	.2byte EC_WORD_QUES
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Baley

@ 135
	.4byte FACILITY_CLASS_RUIN_MANIAC
	.string "ZACKARY$", 8
@ pre-battle speech
	.2byte EC_WORD_CAN
	.2byte EC_WORD_YOU
	.2byte EC_MOVE(DIG)
	.2byte EC_WORD_IT
	.2byte EC_WORD_YO
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_MOVE2(TAKE_DOWN)
	.2byte EC_WORD_TAKE
	.2byte EC_WORD_A
	.2byte EC_MOVE2(DIVE)
	.2byte EC_WORD_YO
	.2byte EC_WORD_YO
@ loss speech
	.2byte EC_WORD_BREAK
	.2byte EC_WORD_DOWN
	.2byte EC_MOVE2(DIVE)
	.2byte EC_WORD_TIME
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
	.4byte gBattleFrontierTrainerMons_Zackary

@ 136
	.4byte FACILITY_CLASS_COLLECTOR
	.string "GABRIEL$", 8
@ pre-battle speech
	.2byte EC_MOVE2(POUND)
	.2byte EC_WORD_THE
	.2byte EC_WORD_THICK_FAT
	.2byte EC_WORD_ON
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(BELLY_DRUM)
@ win speech
	.2byte EC_MOVE2(POUND)
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(BELLY_DRUM)
	.2byte EC_MOVE2(POUND)
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(BELLY_DRUM)
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(BELLY_DRUM)
	.2byte EC_WORD_WAS
	.2byte EC_WORD_TOO_WEAK
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Gabriel

@ 137
	.4byte FACILITY_CLASS_PARASOL_LADY
	.string "EMILY$", 8
@ pre-battle speech
	.2byte EC_WORD_HOW
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_A_TINY_BIT
	.2byte EC_WORD_OF
	.2byte EC_MOVE(HYPNOSIS)
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE(HYPNOSIS)
	.2byte EC_WORD_STRATEGY
	.2byte EC_WORD_WORKS
	.2byte EC_WORD_TO
	.2byte EC_WORD_PERFECTION
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE(HYPNOSIS)
	.2byte EC_WORD_STRATEGY
	.2byte EC_WORD_WENT
	.2byte EC_WORD_BADLY
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Emily

@ 138
	.4byte FACILITY_CLASS_BEAUTY
	.string "JORDYN$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_MY
	.2byte EC_WORD_SECRET
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT
	.2byte EC_WORD_AS
	.2byte EC_WORD_I
	.2byte EC_WORD_APPEAR
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_BUT
	.2byte EC_WORD_HOW
	.2byte EC_WORD_DID
	.2byte EC_WORD_YOU
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Jordyn

@ 139
	.4byte FACILITY_CLASS_AROMA_LADY
	.string "SOFIA$", 8
@ pre-battle speech
	.2byte EC_POKEMON(LOUDRED)
	.2byte EC_WORD_PROBABLY
	.2byte EC_WORD_HAS
	.2byte EC_WORD_A
	.2byte EC_MOVE(SWEET_SCENT)
	.2byte -1
@ win speech
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_THE
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_THAT
	.2byte EC_WORD_I
	.2byte EC_WORD_GET
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WORK
	.2byte EC_WORD_AT
	.2byte EC_WORD_THE
	.2byte EC_WORD_DEPT_STORE
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Sofia

@ 140
	.4byte FACILITY_CLASS_COOLTRAINER_M
	.string "BRADEN$", 8
@ pre-battle speech
	.2byte EC_WORD_I_CHOOSE_YOU
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_THIS_IS_IT_EXCL
	.2byte -1
	.2byte -1
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_PRETTY
	.2byte EC_WORD_AWESOME
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_MYSELF
@ loss speech
	.2byte EC_WORD_ALL_RIGHT
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_SURRENDER
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Braden

@ 141
	.4byte FACILITY_CLASS_COOLTRAINER_M
	.string "KAYDEN$", 8
@ pre-battle speech
	.2byte EC_WORD_THEY
	.2byte EC_WORD_OVERDO
	.2byte EC_WORD_THAT
	.2byte EC_WORD_GOURMET
	.2byte EC_WORD_THING
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_WORD_THAT
	.2byte EC_WORD_GOURMET
	.2byte EC_WORD_THING
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
@ loss speech
	.2byte EC_WORD_HEY
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_PRETTY
	.2byte EC_WORD_TASTY
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Kayden

@ 142
	.4byte FACILITY_CLASS_COOLTRAINER_M
	.string "COOPER$", 8
@ pre-battle speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_ABSOLUTELY
	.2byte EC_WORD_BE
	.2byte EC_WORD_A
	.2byte EC_WORD_PUSHOVER
@ win speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_TOO
	.2byte EC_WORD_EXCITING
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SORRY
	.4byte gBattleFrontierTrainerMons_Cooper

@ 143
	.4byte FACILITY_CLASS_COOLTRAINER_F
	.string "JULIA$", 8
@ pre-battle speech
	.2byte EC_WORD_SPIRIT
	.2byte EC_WORD_ALONE
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WIN
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_ACCEPT
	.2byte EC_WORD_THIS
	.2byte EC_WORD_WITH
	.2byte EC_WORD_SERENE_GRACE
@ loss speech
	.2byte EC_WORD_FOR_NOW
	.2byte EC_WORD_GOOD_BYE
	.2byte EC_WORD_BUT
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_NOT
	.2byte EC_WORD_OVER
	.4byte gBattleFrontierTrainerMons_Julia

@ 144
	.4byte FACILITY_CLASS_COOLTRAINER_F
	.string "AMARA$", 8
@ pre-battle speech
	.2byte EC_WORD_WROOOAAR_EXCL
	.2byte EC_WORD_EXCL_EXCL
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SO
	.2byte EC_WORD_READY
	.2byte EC_WORD_EXCL_EXCL
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LOSE
	.2byte EC_WORD_MYSELF
	.2byte EC_WORD_IF
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_EXCITING
@ loss speech
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_TOO
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_TO
	.2byte EC_MOVE2(TACKLE)
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Amara

@ 145
	.4byte FACILITY_CLASS_COOLTRAINER_F
	.string "LYNN$", 8
@ pre-battle speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_SECRET
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_BE
	.2byte EC_WORD_HIDDEN
	.2byte EC_WORD_FOREVER
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_SECRET
	.2byte EC_WORD_NOW
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN_T
	.2byte EC_MOVE(SAFEGUARD)
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_OWN
	.2byte EC_WORD_SECRET
	.4byte gBattleFrontierTrainerMons_Lynn

@ 146
	.4byte FACILITY_CLASS_PKMN_RANGER_M
	.string "JOVAN$", 8
@ pre-battle speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_SENSE
	.2byte EC_WORD_IS
	.2byte EC_WORD_SADLY
	.2byte EC_WORD_LACKING
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_SENSE
	.2byte EC_WORD_IS
	.2byte EC_WORD_COOL
	.2byte EC_WORD_ISN_T_IT_QUES
@ loss speech
	.2byte EC_WORD_I_WAS
	.2byte EC_WORD_MINUS
	.2byte EC_WORD_MY
	.2byte EC_WORD_NORMAL
	.2byte EC_WORD_POWER
	.2byte EC_WORD_TODAY
	.4byte gBattleFrontierTrainerMons_Jovan

@ 147
	.4byte FACILITY_CLASS_PKMN_RANGER_M
	.string "DOMINIC$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_THIS
	.2byte EC_WORD_EXCELLENT
	.2byte EC_WORD_CAMERA
	.2byte -1
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_CAMERA
	.2byte EC_WORD_WAS
	.2byte EC_WORD_AWFULLY
	.2byte EC_WORD_EXPENSIVE
	.2byte -1
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_CAMERA
	.2byte EC_WORD_DOESN_T
	.2byte EC_WORD_MISS
	.2byte EC_WORD_A
	.2byte EC_WORD_THING
	.4byte gBattleFrontierTrainerMons_Dominic

@ 148
	.4byte FACILITY_CLASS_PKMN_RANGER_M
	.string "NIKOLAS$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_MOVE2(MIMIC)
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_AFTER
	.2byte EC_WORD_EVERY
	.2byte EC_WORD_BATTLE
@ win speech
	.2byte EC_WORD_IF_I_WIN
	.2byte EC_WORD_I
	.2byte EC_WORD_PRETEND
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_A
	.2byte EC_POKEMON2(TAUROS)
@ loss speech
	.2byte EC_WORD_IF_I_LOSE
	.2byte EC_WORD_I
	.2byte EC_WORD_PRETEND
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_A
	.2byte EC_POKEMON2(MILTANK)
	.4byte gBattleFrontierTrainerMons_Nikolas

@ 149
	.4byte FACILITY_CLASS_PKMN_RANGER_F
	.string "VALERIA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_MOVE2(WISH)
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WOULD
	.2byte EC_WORD_NOT
	.2byte EC_MOVE2(GLARE)
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_REALLY
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_WORD_REALLY
	.2byte EC_MOVE(SCARY_FACE)
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Valeria

@ 150
	.4byte FACILITY_CLASS_PKMN_RANGER_F
	.string "DELANEY$", 8
@ pre-battle speech
	.2byte EC_WORD_SCHOOL
	.2byte EC_WORD_IS
	.2byte EC_WORD_OVER
	.2byte EC_WORD_TIME
	.2byte EC_WORD_TO
	.2byte EC_WORD_PLAY
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_BOY
	.2byte EC_WORD_FRIEND
	.2byte EC_WORD_IS
	.2byte EC_WORD_FROM
	.2byte EC_WORD_SCHOOL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_TO
	.2byte EC_WORD_WORK
	.2byte EC_WORD_NEXT
	.2byte EC_WORD_WEEK
	.4byte gBattleFrontierTrainerMons_Delaney

@ 151
	.4byte FACILITY_CLASS_PKMN_RANGER_F
	.string "MEGHAN$", 8
@ pre-battle speech
	.2byte EC_WORD_SCHOOL
	.2byte EC_WORD_IS
	.2byte EC_WORD_OUT
	.2byte EC_WORD_TIME
	.2byte EC_WORD_TO
	.2byte EC_WORD_PLAY
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_BOY
	.2byte EC_WORD_FRIEND
	.2byte EC_WORD_LIKES
	.2byte EC_WORD_COMICS
	.2byte -1
@ loss speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_BACK
	.2byte EC_WORD_TO
	.2byte EC_WORD_SCHOOL
	.2byte EC_WORD_SOON
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Meghan

@ 152
	.4byte FACILITY_CLASS_DRAGON_TAMER
	.string "ROBERTO$", 8
@ pre-battle speech
	.2byte EC_WORD_DRAGON
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ARE
	.2byte EC_WORD_INVINCIBLE
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WEREN_T
	.2byte EC_WORD_BAD
	.2byte EC_WORD_I_WAS
	.2byte EC_WORD_JUST
	.2byte EC_WORD_BETTER
@ loss speech
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SATISFIED
	.2byte EC_WORD_YET
	.2byte EC_WORD_QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Roberto

@ 153
	.4byte FACILITY_CLASS_DRAGON_TAMER
	.string "DAMIAN$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_PURE_POWER
	.2byte EC_WORD_IS
	.2byte EC_WORD_MACHINE
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(MACH_PUNCH)
	.2byte EC_WORD_WILL
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_A
	.2byte EC_MOVE(BRICK_BREAK)
@ loss speech
	.2byte EC_WORD_ARRGH
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_NO
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Damian

@ 154
	.4byte FACILITY_CLASS_DRAGON_TAMER
	.string "BRODY$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_SENSE
	.2byte EC_WORD_SEEMS
	.2byte EC_POKEMON(ODDISH)
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_MY
	.2byte EC_WORD_FAMILY
	.2byte EC_WORD_STAY_AT_HOME
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_QUESTION
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_SENSE
	.2byte EC_WORD_SERIOUSLY
	.4byte gBattleFrontierTrainerMons_Brody

@ 155
	.4byte FACILITY_CLASS_DRAGON_TAMER
	.string "GRAHAM$", 8
@ pre-battle speech
	.2byte EC_WORD_YEAH
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_YEAH_YEAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_WAHAHAHA
	.2byte EC_WORD_WAHAHAHA
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_WAHAHAHA
	.2byte EC_WORD_WAHAHAHA
	.2byte EC_WORD_EXCL_EXCL
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_MY
	.2byte EC_WORD_BAD
	.4byte gBattleFrontierTrainerMons_Graham

@ 156
	.4byte FACILITY_CLASS_POKEFAN_M
	.string "TYLOR$", 8
@ pre-battle speech
	.2byte EC_WORD_ARE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(HEAT_WAVE)
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_YES
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_ON
	.2byte EC_WORD_FIRE
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I_WAS
	.2byte EC_WORD_ON
	.2byte EC_WORD_FIRE
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOU
	.4byte gBattleFrontierTrainerMons_Tylor

@ 157
	.4byte FACILITY_CLASS_POKEFAN_F
	.string "JAREN$", 8
@ pre-battle speech
	.2byte EC_WORD_FIGHTING
	.2byte EC_WORD_SPIRIT
	.2byte EC_WORD_QUES
	.2byte EC_WORD_ME
	.2byte EC_WORD_QUES
	.2byte -1
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_MORE
	.2byte EC_WORD_CUTE
	.2byte EC_WORD_POKEMON
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_QUITE
	.2byte EC_WORD_CUTE
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Jaren

@ 158
	.4byte FACILITY_CLASS_PKMN_BREEDER_M
	.string "CORDELL$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_IS
	.2byte EC_WORD_DECIDED
	.2byte EC_WORD_ON
	.2byte EC_WORD_SPIRIT
@ win speech
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_YOU
	.2byte EC_WORD_ACCEPT
	.2byte EC_WORD_THAT
	.2byte EC_WORD_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_BE
	.2byte EC_WORD_ON
	.2byte EC_WORD_MY
	.2byte EC_WORD_WAY
	.4byte gBattleFrontierTrainerMons_Cordell

@ 159
	.4byte FACILITY_CLASS_POKEMON_BREEDER_F
	.string "JAZLYN$", 8
@ pre-battle speech
	.2byte EC_WORD_IS
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEDEX
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_AWESOME
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_OH_YEAH
	.2byte EC_WORD_WOW
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEDEX
	.2byte EC_WORD_IS
	.2byte EC_WORD_SUPER
@ loss speech
	.2byte EC_WORD_AN
	.2byte EC_WORD_AVANT_GARDE
	.2byte EC_WORD_POKEDEX
	.2byte EC_WORD_WOULD
	.2byte EC_WORD_BE
	.2byte EC_WORD_AWESOME
	.4byte gBattleFrontierTrainerMons_Jazlyn

@ 160
	.4byte FACILITY_CLASS_YOUNGSTER
	.string "ZACHERY$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_MY
	.2byte EC_WORD_OWN
	.2byte EC_WORD_PLACE
	.2byte EC_WORD_YEEHAW_EXCL
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_AN
	.2byte EC_WORD_EXCITING
	.2byte EC_WORD_TIME
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_FLATTEN
	.2byte EC_WORD_MY
	.2byte EC_WORD_HAPPINESS
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Zachery

@ 161
	.4byte FACILITY_CLASS_YOUNGSTER
	.string "JOHAN$", 8
@ pre-battle speech
	.2byte EC_WORD_WINTER
	.2byte EC_WORD_WILL
	.2byte EC_WORD_SOON
	.2byte EC_WORD_BE
	.2byte EC_WORD_HERE
	.2byte -1
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_ALLOWANCE
	.2byte EC_WORD_COULD
	.2byte EC_WORD_USE
	.2byte EC_WORD_A
	.2byte EC_MOVE2(HELPING_HAND)
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_ALWAYS
	.2byte EC_WORD_USE
	.2byte EC_WORD_MY
	.2byte EC_WORD_ALLOWANCE
	.2byte EC_WORD_UP
	.4byte gBattleFrontierTrainerMons_Johan

@ 162
	.4byte FACILITY_CLASS_LASS
	.string "SHEA$", 8
@ pre-battle speech
	.2byte EC_WORD_DO
	.2byte EC_WORD_YOU
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_WITH
	.2byte EC_WORD_BEAUTY
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_IN
	.2byte EC_WORD_AN
	.2byte EC_WORD_UGLY
	.2byte EC_WORD_WAY
@ loss speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_IS
	.2byte EC_WORD_BEAUTY
	.2byte EC_WORD_TO
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Shea

@ 163
	.4byte FACILITY_CLASS_LASS
	.string "KAILA$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_THIRSTY
	.2byte EC_WORD_RIGHT
	.2byte EC_WORD_NOW
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_COULD
	.2byte EC_WORD_USE
	.2byte EC_WORD_A
	.2byte EC_WORD_COLD
	.2byte EC_WORD_DRINK
@ loss speech
	.2byte EC_WORD_THAT
	.2byte EC_WORD_LOSS
	.2byte EC_WORD_IS
	.2byte EC_WORD_HARD
	.2byte EC_WORD_TO
	.2byte EC_MOVE2(SWALLOW)
	.4byte gBattleFrontierTrainerMons_Kaila

@ 164
	.4byte FACILITY_CLASS_SCHOOL_KID_M
	.string "ISIAH$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_PRETEND
	.2byte EC_WORD_TO
	.2byte EC_WORD_STUDY
	.2byte EC_WORD_A_LOT
	.2byte -1
@ win speech
	.2byte EC_WORD_I
	.2byte EC_MOVE2(TRICK)
	.2byte EC_WORD_MOTHER
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_WORD_ALLOWANCE
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_STUDY
	.2byte EC_WORD_MORE
	.4byte gBattleFrontierTrainerMons_Isiah

@ 165
	.4byte FACILITY_CLASS_SCHOOL_KID_M
	.string "GARRETT$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_ENJOY
	.2byte EC_WORD_COMICS
	.2byte EC_WORD_AND
	.2byte EC_WORD_THIS
	.2byte EC_WORD_GAME
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_THIS
	.2byte EC_WORD_MUSIC
	.2byte EC_WORD_IDOL
	.2byte EC_WORD_TOO
@ loss speech
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_TO
	.2byte EC_WORD_STUDY
	.2byte EC_WORD_MORE
	.4byte gBattleFrontierTrainerMons_Garrett

@ 166
	.4byte FACILITY_CLASS_SCHOOL_KID_F
	.string "HAYLIE$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WORRY
	.2byte EC_WORD_TOO
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_TO
	.2byte EC_WORD_SLEEP
@ win speech
	.2byte EC_WORD_A
	.2byte EC_WORD_WIN
	.2byte EC_WORD_GIVES
	.2byte EC_WORD_ME
	.2byte EC_WORD_A
	.2byte EC_MOVE2(CALM_MIND)
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_INSOMNIA
	.2byte EC_WORD_WILL
	.2byte EC_WORD_GET
	.2byte EC_WORD_BAD
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Haylie

@ 167
	.4byte FACILITY_CLASS_SCHOOL_KID_F
	.string "MEGAN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_BELIEVE
	.2byte EC_WORD_IN
	.2byte EC_WORD_AN
	.2byte EC_MOVE(AROMATHERAPY)
	.2byte EC_WORD_BATH
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_A
	.2byte EC_WORD_HEALTHY
	.2byte EC_WORD_CLEAR_BODY
	.2byte -1
@ loss speech
	.2byte EC_WORD_IF
	.2byte EC_WORD_ONLY
	.2byte EC_MOVE(AROMATHERAPY)
	.2byte EC_WORD_WERE
	.2byte EC_WORD_LESS
	.2byte EC_WORD_EXPENSIVE
	.4byte gBattleFrontierTrainerMons_Megan

@ 168
	.4byte FACILITY_CLASS_RICH_BOY
	.string "ISSAC$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_HOBBY
	.2byte EC_WORD_QUES
	.2byte -1
	.2byte -1
	.2byte -1
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_ANY
	.2byte EC_WORD_KIND
	.2byte EC_WORD_OF
	.2byte EC_MOVE2(WATER_SPORT)
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DISLIKE
	.2byte EC_WORD_ANY
	.2byte EC_WORD_KIND
	.2byte EC_WORD_OF
	.2byte EC_MOVE2(MUD_SPORT)
	.4byte gBattleFrontierTrainerMons_Issac

@ 169
	.4byte FACILITY_CLASS_RICH_BOY
	.string "QUINTON$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SAD
	.2byte EC_WORD_CAUSE
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TOO_WEAK
	.2byte -1
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_TOO_STRONG
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
	.2byte -1
@ loss speech
	.2byte EC_WORD_HEY
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_DID
	.2byte EC_WORD_I
	.2byte EC_WORD_DO
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Quinton

@ 170
	.4byte FACILITY_CLASS_LADY
	.string "SALMA$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU_VE
	.2byte EC_WORD_GOT
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_HUSTLE
	.2byte EC_WORD_ON
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WIN
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HUSTLE
	.2byte EC_WORD_ON
	.2byte EC_WORD_OUT
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_GET
	.2byte EC_WORD_HOW
	.2byte EC_WORD_I
	.2byte EC_WORD_LOST
	.4byte gBattleFrontierTrainerMons_Salma

@ 171
	.4byte FACILITY_CLASS_LADY
	.string "ANSLEY$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_BORED
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_DANCE
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
@ win speech
	.2byte EC_WORD_YOU_VE
	.2byte EC_WORD_BORED
	.2byte EC_WORD_ME
	.2byte EC_WORD_SOME
	.2byte EC_WORD_MORE
	.2byte -1
@ loss speech
	.2byte EC_WORD_TAKE
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE2(FRUSTRATION)
	.2byte EC_WORD_SOME
	.2byte EC_WORD_OTHER
	.2byte EC_WORD_PLACE
	.4byte gBattleFrontierTrainerMons_Ansley

@ 172
	.4byte FACILITY_CLASS_BUG_CATCHER
	.string "HOLDEN$", 8
@ pre-battle speech
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_COMMEMORATE
	.2byte EC_WORD_MY
	.2byte EC_WORD_COOLNESS
	.2byte EC_WORD_IN
	.2byte EC_WORD_BATTLE
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_TOO_WEAK
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ANY
	.2byte EC_WORD_PRAISE
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_SENSE
	.2byte EC_WORD_IS
	.2byte EC_WORD_AMUSING
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Holden

@ 173
	.4byte FACILITY_CLASS_BUG_CATCHER
	.string "LUCA$", 8
@ pre-battle speech
	.2byte EC_WORD_WE
	.2byte EC_WORD_WILL
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_WORD_COOL
	.2byte EC_WORD_BATTLE
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
	.2byte EC_WORD_IN
	.2byte EC_WORD_A
	.2byte EC_WORD_COOL
	.2byte EC_WORD_WAY
@ loss speech
	.2byte EC_WORD_HELLO
	.2byte EC_WORD_QUES
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_JUST
	.2byte EC_WORD_A
	.2byte EC_WORD_KID
	.4byte gBattleFrontierTrainerMons_Luca

@ 174
	.4byte FACILITY_CLASS_NINJA_BOY
	.string "JAMISON$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(SECRET_POWER)
	.2byte EC_WORD_IS
	.2byte EC_WORD_OVERWHELMING
	.2byte EC_WORD_TO
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_DID
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SEE
	.2byte EC_WORD_THAT
	.2byte EC_WORD_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_USE
	.2byte EC_MOVE(SMOKESCREEN)
	.2byte EC_WORD_TO
	.2byte EC_WORD_ESCAPE
	.4byte gBattleFrontierTrainerMons_Jamison

@ 175
	.4byte FACILITY_CLASS_NINJA_BOY
	.string "GUNNAR$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_MOVE(CUT)
	.2byte EC_WORD_DOWN
	.2byte EC_WORD_EVERY
	.2byte EC_WORD_OPPONENT
	.2byte -1
@ win speech
	.2byte EC_WORD_DON_T
	.2byte EC_MOVE(GRUDGE)
	.2byte EC_WORD_ME
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_LOSS
@ loss speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_LOSE
	.2byte EC_WORD_THAT
	.2byte EC_MOVE(SCARY_FACE)
	.2byte EC_WORD_OF
	.2byte EC_WORD_YOURS
	.4byte gBattleFrontierTrainerMons_Gunnar

@ 176
	.4byte FACILITY_CLASS_TUBER_M
	.string "CRAIG$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_WAIT
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_WORD_TRAIN
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_TRAIN
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_HERE
	.2byte EC_WORD_YET
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_HERE_IT_IS
	.2byte EC_WORD_MY
	.2byte EC_WORD_TRAIN
	.2byte EC_WORD_SEE_YA
	.2byte EC_WORD_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Craig

@ 177
	.4byte FACILITY_CLASS_TUBER_M
	.string "PIERCE$", 8
@ pre-battle speech
	.2byte EC_WORD_THERE
	.2byte EC_WORD_WAS
	.2byte EC_WORD_A
	.2byte EC_MOVE2(HEAT_WAVE)
	.2byte EC_WORD_LAST
	.2byte EC_WORD_WEEK
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_TAKE
	.2byte EC_WORD_A
	.2byte EC_MOVE2(HEAT_WAVE)
	.2byte -1
@ loss speech
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_IT
	.2byte EC_MOVE(HAIL)
	.2byte EC_WORD_TOO
	.2byte EC_WORD_QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Pierce

@ 178
	.4byte FACILITY_CLASS_TUBER_F
	.string "REGINA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_TO
	.2byte EC_WORD_PLAY
	.2byte EC_WORD_IN
	.2byte EC_WORD_WATER
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_REFUSE
	.2byte EC_WORD_TO
	.2byte EC_WORD_COME
	.2byte EC_WORD_OUT
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_NOT
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_IN
	.2byte EC_WORD_WATER
	.4byte gBattleFrontierTrainerMons_Regina

@ 179
	.4byte FACILITY_CLASS_TUBER_F
	.string "ALISON$", 8
@ pre-battle speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_KINDERGARTEN
	.2byte EC_WORD_MAGAZINE
	.2byte EC_WORD_IS
	.2byte EC_WORD_TOO
	.2byte EC_WORD_MUCH
@ win speech
	.2byte EC_WORD_HOW
	.2byte EC_WORD_TO
	.2byte EC_WORD_BUG
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_TEACHER
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_ENJOY
	.2byte EC_WORD_A
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_SCHOOL
	.2byte EC_WORD_DIET
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Alison

@ 180
	.4byte FACILITY_CLASS_BUG_MANIAC
	.string "HANK$", 8
@ pre-battle speech
	.2byte EC_WORD_THERE
	.2byte EC_WORD_IS
	.2byte EC_WORD_A
	.2byte EC_WORD_BUG
	.2byte EC_WORD_EVENT
	.2byte EC_WORD_SOON
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_A
	.2byte EC_WORD_BUG
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_SHOW
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_YOU
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_BUG
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Hank

@ 181
	.4byte FACILITY_CLASS_BUG_MANIAC
	.string "EARL$", 8
@ pre-battle speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_INVINCIBLE
	.2byte EC_WORD_BUG
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_IS
	.2byte EC_WORD_HERE
@ win speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_INVINCIBLE
	.2byte EC_WORD_BUG
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_AM
	.2byte EC_WORD_I
@ loss speech
	.2byte EC_WORD_SEE
	.2byte EC_WORD_HOW
	.2byte EC_WORD_FAST
	.2byte EC_WORD_I
	.2byte EC_WORD_RUN_AWAY
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Earl

@ 182
	.4byte FACILITY_CLASS_FISHERMAN
	.string "RAMIRO$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WENT
	.2byte EC_WORD_TO
	.2byte EC_WORD_A
	.2byte EC_WORD_FISHING
	.2byte EC_WORD_SCHOOL
@ win speech
	.2byte EC_WORD_SERIOUSLY
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_IN
	.2byte EC_WORD_THE
	.2byte EC_WORD_FISHING
	.2byte EC_WORD_HALL_OF_FAME
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_GO
	.2byte EC_WORD_BACK
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Ramiro

@ 183
	.4byte FACILITY_CLASS_FISHERMAN
	.string "HUNTER$", 8
@ pre-battle speech
	.2byte EC_WORD_SHOW
	.2byte EC_WORD_ME
	.2byte EC_WORD_A
	.2byte EC_WORD_TOTALLY
	.2byte EC_WORD_COOL
	.2byte EC_MOVE(CROSS_CHOP)
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_TOO_WEAK
	.2byte EC_WORD_TO
	.2byte EC_WORD_DO
	.2byte EC_WORD_A
	.2byte EC_MOVE(CROSS_CHOP)
@ loss speech
	.2byte EC_WORD_WAS
	.2byte EC_WORD_IT
	.2byte EC_WORD_A
	.2byte EC_WORD_MISTAKE
	.2byte EC_WORD_QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Hunter

@ 184
	.4byte FACILITY_CLASS_RUIN_MANIAC
	.string "AIDEN$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_WORK
	.2byte EC_WORD_IS
	.2byte EC_WORD_MAKING
	.2byte EC_WORD_ME
	.2byte EC_WORD_HEALTHY
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SEE
	.2byte EC_WORD_QUES
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_HEALTHY
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_MORE
	.2byte EC_WORD_HEALTHY
	.2byte EC_WORD_THAN
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Aiden

@ 185
	.4byte FACILITY_CLASS_RUIN_MANIAC
	.string "XAVIER$", 8
@ pre-battle speech
	.2byte EC_WORD_HEY_THERE
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_EXCL_EXCL
@ win speech
	.2byte EC_WORD_GOOD_BYE
	.2byte EC_WORD_AND
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_FUNNY
	.2byte -1
@ loss speech
	.2byte EC_WORD_WOWEE
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_NO
	.2byte EC_WORD_NO
	.2byte EC_WORD_EXCL_EXCL
	.4byte gBattleFrontierTrainerMons_Xavier

@ 186
	.4byte FACILITY_CLASS_COLLECTOR
	.string "CLINTON$", 8
@ pre-battle speech
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_SEE
	.2byte EC_WORD_MY
	.2byte EC_MOVE(HYPNOSIS)
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE2(FURY_SWIPES)
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE(STRENGTH)
	.2byte EC_WORD_YOUNG
	.2byte EC_WORD_TRAINER
@ loss speech
	.2byte EC_WORD_TCH
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TOO_WEAK
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Clinton

@ 187
	.4byte FACILITY_CLASS_COLLECTOR
	.string "JESSE$", 8
@ pre-battle speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_IS
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_WORD_MOTHER
@ win speech
	.2byte EC_WORD_MOTHER
	.2byte EC_WORD_WILL
	.2byte EC_WORD_BE
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_MY
	.2byte EC_WORD_MOTHER
	.2byte EC_WORD_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Jesse

@ 188
	.4byte FACILITY_CLASS_GUITARIST
	.string "EDUARDO$", 8
@ pre-battle speech
	.2byte EC_WORD_OUR
	.2byte EC_WORD_MUSIC
	.2byte EC_WORD_WILL
	.2byte EC_WORD_PLAY
	.2byte EC_WORD_ALL
	.2byte EC_WORD_NIGHT
@ win speech
	.2byte EC_WORD_NIGHTTIME
	.2byte EC_WORD_IS
	.2byte EC_WORD_WHEN
	.2byte EC_WORD_I
	.2byte EC_WORD_PLAY
	.2byte EC_WORD_BEST
@ loss speech
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_PARTY
	.2byte EC_WORD_UNTIL
	.2byte EC_WORD_THE
	.2byte EC_MOVE(MORNING_SUN)
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Eduardo

@ 189
	.4byte FACILITY_CLASS_GUITARIST
	.string "HAL$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TRENDY
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_I
	.2byte EC_WORD_QUES
	.2byte -1
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_HIP_AND
	.2byte EC_WORD_HAPPENING
	.2byte EC_WORD_OH_YEAH
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_ALWAYS
	.2byte EC_WORD_TRENDY
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_VERY
	.2byte EC_WORD_MUCH
	.4byte gBattleFrontierTrainerMons_Hal

@ 190
	.4byte FACILITY_CLASS_BIRD_KEEPER
	.string "GAGE$", 8
@ pre-battle speech
	.2byte EC_WORD_HERE_IT_IS
	.2byte EC_WORD_A
	.2byte EC_WORD_FLYING
	.2byte EC_WORD_TYPE
	.2byte EC_WORD_HIDDEN
	.2byte EC_WORD_MOVE
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_A
	.2byte EC_WORD_FLYING
	.2byte EC_WORD_TYPE
	.2byte EC_WORD_VICTORY
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_IF_I_LOSE
	.2byte EC_WORD_I
	.2byte EC_WORD_JUST
	.2byte EC_MOVE(FLY)
	.2byte EC_WORD_AWAY
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Gage

@ 191
	.4byte FACILITY_CLASS_BIRD_KEEPER
	.string "ARNOLD$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_WEIRD
	.2byte EC_WORD_FROM
	.2byte EC_WORD_A
	.2byte EC_WORD_DREAM
@ win speech
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE(SCARY_FACE)
	.2byte EC_WORD_WAS
	.2byte EC_WORD_IN
	.2byte EC_WORD_MY
	.2byte EC_WORD_DREAM
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_INCREDIBLE
	.2byte EC_WORD_DREAM
	.2byte EC_WORD_WAS
	.2byte EC_WORD_SO
	.2byte EC_WORD_WEIRD
	.4byte gBattleFrontierTrainerMons_Arnold

@ 192
	.4byte FACILITY_CLASS_SAILOR
	.string "JARRETT$", 8
@ pre-battle speech
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_DANCE
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_YESTERDAY
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_HOW
	.2byte EC_WORD_I
	.2byte EC_WORD_DANCE
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_APPRECIATE
	.2byte EC_WORD_HOW
	.2byte EC_WORD_I
	.2byte EC_WORD_DANCE
	.4byte gBattleFrontierTrainerMons_Jarrett

@ 193
	.4byte FACILITY_CLASS_SAILOR
	.string "GARETT$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_GIRL
	.2byte EC_WORD_GIVES
	.2byte EC_WORD_ME
	.2byte EC_WORD_A_LITTLE
	.2byte EC_MOVE2(SWEET_KISS)
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_GIRL
	.2byte EC_WORD_FRIEND
	.2byte EC_WORD_IS
	.2byte EC_WORD_MY
	.2byte EC_WORD_TREASURE
@ loss speech
	.2byte EC_WORD_A
	.2byte EC_WORD_TREASURE
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_ALWAYS
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_MONEY
	.4byte gBattleFrontierTrainerMons_Garett

@ 194
	.4byte FACILITY_CLASS_HIKER
	.string "EMANUEL$", 8
@ pre-battle speech
	.2byte EC_WORD_SMARTNESS
	.2byte EC_WORD_ALONE
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WIN
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT_VERY
	.2byte EC_WORD_SMART
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
@ loss speech
	.2byte EC_WORD_HOW
	.2byte EC_WORD_DID
	.2byte EC_WORD_YOU
	.2byte EC_MOVE2(FAKE_OUT)
	.2byte EC_WORD_ME
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Emanuel

@ 195
	.4byte FACILITY_CLASS_HIKER
	.string "GUSTAVO$", 8
@ pre-battle speech
	.2byte EC_MOVE(CHARGE)
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_MOVE(CHARGE)
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_SURRENDER
	.2byte EC_WORD_QUES
	.2byte -1
	.2byte EC_WORD_SO
	.2byte EC_WORD_SOON
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_ME
	.2byte EC_WORD_SURRENDER
	.2byte EC_WORD_YET
	.4byte gBattleFrontierTrainerMons_Gustavo

@ 196
	.4byte FACILITY_CLASS_KINDLER
	.string "KAMERON$", 8
@ pre-battle speech
	.2byte EC_WORD_TAKE_THAT
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_MY
	.2byte EC_WORD_FIERY
	.2byte EC_MOVE2(TRICK)
@ win speech
	.2byte EC_WORD_DID
	.2byte EC_WORD_MY
	.2byte EC_WORD_FIERY
	.2byte EC_MOVE2(TRICK)
	.2byte EC_MOVE(ASTONISH)
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_FALL
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(TRICK)
	.4byte gBattleFrontierTrainerMons_Kameron

@ 197
	.4byte FACILITY_CLASS_KINDLER
	.string "ALFREDO$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_WORD_FIERY
	.2byte EC_WORD_GOURMET
	.2byte EC_WORD_AM
	.2byte EC_WORD_I
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_A
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_GOURMET
	.2byte EC_WORD_VICTORY
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_A
	.2byte EC_WORD_DISASTER
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Alfredo

@ 198
	.4byte FACILITY_CLASS_GENTLEMAN
	.string "RUBEN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_WAIT
	.2byte EC_WORD_TO
	.2byte EC_WORD_GET
	.2byte EC_WORD_GOING
@ win speech
	.2byte EC_WORD_GET
	.2byte EC_WORD_GOING
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_GOOD_BYE
@ loss speech
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_GOT
	.2byte EC_WORD_TO
	.2byte EC_WORD_GET
	.2byte EC_WORD_GOING
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Ruben

@ 199
	.4byte FACILITY_CLASS_GENTLEMAN
	.string "LAMAR$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_MOVE2(PRESENT)
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
	.2byte EC_WORD_QUES
	.2byte -1
@ win speech
	.2byte EC_WORD_MMM
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_QUITE
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_A
	.2byte EC_WORD_GAME
	.2byte EC_WORD_IS_IT_QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Lamar

@ 200
	.4byte FACILITY_CLASS_YOUNGSTER
	.string "JAXON$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_WORD_SHELL_ARMOR
	.2byte EC_WORD_IS
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_FATHER
	.2byte EC_WORD_AND
	.2byte EC_WORD_MOTHER
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_ACCEPT
@ loss speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_A
	.2byte EC_WORD_SHELL_ARMOR
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Jaxon

@ 201
	.4byte FACILITY_CLASS_YOUNGSTER
	.string "LOGAN$", 8
@ pre-battle speech
	.2byte EC_WORD_IF_I_LOSE
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_STUDY
	.2byte EC_WORD_FOR
	.2byte EC_WORD_SCHOOL
@ win speech
	.2byte EC_WORD_ME
	.2byte EC_WORD_STUDY
	.2byte EC_WORD_QUES
	.2byte EC_WORD_NOT_VERY
	.2byte EC_WORD_LIKELY_TO
	.2byte EC_WORD_SEE
@ loss speech
	.2byte EC_WORD_NO
	.2byte EC_WORD_THANKS
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_SLEEP
	.4byte gBattleFrontierTrainerMons_Logan

@ 202
	.4byte FACILITY_CLASS_LASS
	.string "EMILEE$", 8
@ pre-battle speech
	.2byte EC_WORD_IS
	.2byte EC_WORD_THIS
	.2byte EC_WORD_KIND
	.2byte EC_WORD_OF
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_OK_QUES
@ win speech
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_GO
	.2byte EC_WORD_FOR
	.2byte EC_WORD_AN
	.2byte EC_MOVE(ICY_WIND)
	.2byte EC_MOVE2(SURF)
@ loss speech
	.2byte EC_WORD_HOW
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_A
	.2byte EC_MOVE(ROCK_SLIDE)
	.2byte EC_WORD_SHOW
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Emilee

@ 203
	.4byte FACILITY_CLASS_LASS
	.string "JOSIE$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_CONTEST
	.2byte EC_WORD_IS
	.2byte EC_WORD_PRETTY
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_MODE
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_THINGS
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_TOTALLY
	.2byte EC_WORD_LACKING
	.2byte EC_WORD_IN
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_SENSE
	.4byte gBattleFrontierTrainerMons_Josie

@ 204
	.4byte FACILITY_CLASS_CAMPER
	.string "ARMANDO$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_MORE
	.2byte EC_WORD_GRASS
	.2byte EC_WORD_TYPE
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_TRADE
	.2byte EC_WORD_ME
	.2byte EC_WORD_A
	.2byte EC_WORD_GRASS
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_PLEASE
@ loss speech
	.2byte EC_WORD_THERE
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_ENOUGH
	.2byte EC_WORD_GRASS
	.2byte EC_WORD_TYPE
	.2byte EC_WORD_POKEMON
	.4byte gBattleFrontierTrainerMons_Armando

@ 205
	.4byte FACILITY_CLASS_CAMPER
	.string "SKYLER$", 8
@ pre-battle speech
	.2byte EC_MOVE2(INGRAIN)
	.2byte EC_WORD_IS
	.2byte EC_WORD_MY
	.2byte EC_WORD_CHOICE
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_MOVE
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_MOVE
	.2byte EC_WORD_ME
	.2byte EC_WORD_NOW
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_MOVE(CUT)
	.2byte EC_WORD_ME
	.2byte EC_WORD_DOWN
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Skyler

@ 206
	.4byte FACILITY_CLASS_PICNICKER
	.string "RUTH$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_ENJOY
	.2byte EC_WORD_THIS
	.2byte EC_WORD_BATTLE
@ win speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_TOO
	.2byte EC_WORD_EASY
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_STOP
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_ENJOY
	.2byte EC_WORD_THIS
	.4byte gBattleFrontierTrainerMons_Ruth

@ 207
	.4byte FACILITY_CLASS_PICNICKER
	.string "MELODY$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_MOVE2(WISH)
	.2byte EC_WORD_SUNDAY
	.2byte EC_WORD_IS
	.2byte EC_WORD_A
	.2byte EC_MOVE2(SUNNY_DAY)
@ win speech
	.2byte EC_WORD_SUNDAY
	.2byte EC_WORD_SEEMS
	.2byte EC_WORD_FOREVER
	.2byte EC_WORD_TO
	.2byte EC_WORD_COME
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_FORECAST
	.2byte EC_WORD_SAYS
	.2byte EC_WORD_IT
	.2byte EC_WORD_WILL
	.2byte EC_MOVE(HAIL)
	.4byte gBattleFrontierTrainerMons_Melody

@ 208
	.4byte FACILITY_CLASS_SWIMMER_M
	.string "PEDRO$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_WORD_SWIFT_SWIM
	.2byte EC_WORD_WILL
	.2byte EC_WORD_DO
	.2byte EC_WORD_YOU
	.2byte EC_WORD_GOOD
@ win speech
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_HOW
	.2byte EC_WORD_I
	.2byte EC_WORD_SINK
	.2byte EC_WORD_AN
	.2byte EC_WORD_OPPONENT
@ loss speech
	.2byte EC_WORD_UH_OH
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_A
	.2byte EC_MOVE(WHIRLPOOL)
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Pedro

@ 209
	.4byte FACILITY_CLASS_SWIMMER_M
	.string "ERICK$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_MOVE2(TACKLE)
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DOWN
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_YOU
	.2byte EC_WORD_RUN_AWAY
	.2byte EC_WORD_YOU
	.2byte EC_WORD_LOSER
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_THINK
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WOULD
	.2byte EC_MOVE(COUNTER)
	.4byte gBattleFrontierTrainerMons_Erick

@ 210
	.4byte FACILITY_CLASS_SWIMMER_F
	.string "ELAINE$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_HEROINE
	.2byte EC_WORD_ADVENTURE
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_GOING
	.2byte EC_WORD_WELL
@ win speech
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT
	.2byte EC_WORD_A
	.2byte EC_WORD_HEROINE
	.4byte gBattleFrontierTrainerMons_Elaine

@ 211
	.4byte FACILITY_CLASS_SWIMMER_F
	.string "JOYCE$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_ME
	.2byte EC_WORD_GO
	.2byte EC_WORD_AHAHA
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_LALALA
	.2byte EC_WORD_NO
	.2byte EC_WORD_LOSING
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_LALALA
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte EC_WORD_HUH_QUES
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Joyce

@ 212
	.4byte FACILITY_CLASS_POKEFAN_M
	.string "TODD$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_A
	.2byte EC_WORD_LIGHTNINGROD
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_WORD_POWER
@ win speech
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_ALL
	.2byte EC_WORD_YOU
	.2byte EC_WORD_COULD
	.2byte EC_MOVE(ABSORB)
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_MOVE2(REFLECT)
	.2byte EC_WORD_MY
	.2byte EC_WORD_POWER
	.2byte EC_WORD_BACK
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Todd

@ 213
	.4byte FACILITY_CLASS_POKEFAN_M
	.string "GAVIN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_MOVE(BIDE)
	.2byte EC_WORD_MY
	.2byte EC_WORD_TIME
	.2byte -1
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_OVER
	.2byte EC_WORD_SO
	.2byte EC_WORD_SOON
	.2byte EC_WORD_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_MISTAKE
	.2byte EC_WORD_WAS
	.2byte EC_WORD_TOO
	.2byte EC_WORD_EXPENSIVE
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Gavin

@ 214
	.4byte FACILITY_CLASS_POKEFAN_F
	.string "MALORY$", 8
@ pre-battle speech
	.2byte EC_WORD_PROMISE
	.2byte EC_WORD_TO
	.2byte EC_WORD_SHOW
	.2byte EC_WORD_ME
	.2byte EC_WORD_CUTE
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_GIGGLE
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_SO
	.2byte EC_WORD_MUCH
@ loss speech
	.2byte EC_WORD_TCH
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_VERY
	.2byte EC_WORD_NICE
	.4byte gBattleFrontierTrainerMons_Malory

@ 215
	.4byte FACILITY_CLASS_POKEFAN_F
	.string "ESTHER$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_A
	.2byte EC_WORD_NICE
	.2byte EC_MOVE2(PRESENT)
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_GET
	.2byte EC_WORD_ME
	.2byte EC_WORD_A
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_GAME
@ loss speech
	.2byte EC_WORD_MESSAGE
	.2byte EC_WORD_CARDS
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_A
	.2byte EC_WORD_WEAK
	.2byte EC_MOVE2(PRESENT)
	.4byte gBattleFrontierTrainerMons_Esther

@ 216
	.4byte FACILITY_CLASS_PKMN_BREEDER_M
	.string "OSCAR$", 8
@ pre-battle speech
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_SEE
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POWER
	.2byte EC_WORD_IN
	.2byte EC_WORD_FULL
@ win speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_NOT
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_FULL
	.2byte EC_WORD_POWER
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_NOT
	.2byte EC_WORD_FUNNY
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_TOO_STRONG
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Oscar

@ 217
	.4byte FACILITY_CLASS_PKMN_BREEDER_M
	.string "WILSON$", 8
@ pre-battle speech
	.2byte EC_WORD_WORK
	.2byte EC_WORD_IS
	.2byte EC_WORD_MAKING
	.2byte EC_WORD_ME
	.2byte EC_WORD_AN
	.2byte EC_WORD_EARLY_BIRD
@ win speech
	.2byte EC_WORD_ALL
	.2byte EC_WORD_WORK
	.2byte EC_WORD_AND
	.2byte EC_WORD_NO
	.2byte EC_WORD_PLAY
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_MOVE(ENDURE)
	.2byte EC_WORD_IS
	.2byte EC_WORD_ALL
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN
	.2byte EC_WORD_DO
	.4byte gBattleFrontierTrainerMons_Wilson

@ 218
	.4byte FACILITY_CLASS_POKEMON_BREEDER_F
	.string "CLARE$", 8
@ pre-battle speech
	.2byte EC_WORD_YAY
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_A
	.2byte EC_WORD_TOUGH
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_AWW
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_A
	.2byte EC_WORD_WIMPY
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_COOL
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_A
	.2byte EC_WORD_GENIUS
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Clare

@ 219
	.4byte FACILITY_CLASS_POKEMON_BREEDER_F
	.string "TESS$", 8
@ pre-battle speech
	.2byte EC_WORD_WANT
	.2byte EC_WORD_SOME
	.2byte EC_POKEMON(GULPIN)
	.2byte EC_WORD_DESIGN
	.2byte EC_WORD_SWEETS
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_THEY_RE
	.2byte EC_WORD_A
	.2byte EC_WORD_SECRET
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_GOURMET
	.2byte EC_WORD_ITEM
@ loss speech
	.2byte EC_WORD_THEY_RE
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_REFRESHING
	.2byte EC_WORD_TOO
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Tess

@ 220
	.4byte FACILITY_CLASS_COOLTRAINER_M
	.string "LEON$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_BETTER
	.2byte EC_WORD_THAN
	.2byte EC_WORD_ANY
	.2byte EC_WORD_OTHER
	.2byte EC_WORD_TRAINER
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DID
	.2byte EC_WORD_IT
	.2byte EC_MOVE2(JUMP_KICK)
	.2byte EC_WORD_FOR
	.2byte EC_WORD_JOY
@ loss speech
	.2byte EC_WORD_BACK
	.2byte EC_WORD_HOME
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_GO
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Leon

@ 221
	.4byte FACILITY_CLASS_COOLTRAINER_M
	.string "ALONZO$", 8
@ pre-battle speech
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_NOT
	.2byte EC_WORD_LOST
	.2byte EC_WORD_ONCE
	.2byte EC_WORD_YET
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_SAD
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_BECOMES
	.2byte EC_WORD_YOU
	.2byte -1
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_BELIEVE
	.2byte EC_WORD_THIS
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Alonzo

@ 222
	.4byte FACILITY_CLASS_COOLTRAINER_M
	.string "VINCE$", 8
@ pre-battle speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_TOP
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_ME
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_TOP
	.2byte EC_WORD_RANK
	.2byte EC_WORD_BELONGS_TO
	.2byte EC_WORD_ME
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_APPEAL
	.2byte EC_WORD_THIS
	.2byte EC_MOVE(OUTRAGE)
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Vince

@ 223
	.4byte FACILITY_CLASS_COOLTRAINER_M
	.string "BRYON$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(BARRAGE)
	.2byte EC_WORD_WILL
	.2byte EC_MOVE2(SLAM)
	.2byte EC_WORD_YOU
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_COUNT_ON
	.2byte EC_WORD_ANY
	.2byte EC_WORD_LESS
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_JUST
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_GET
	.2byte EC_WORD_IT
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Bryon

@ 224
	.4byte FACILITY_CLASS_COOLTRAINER_F
	.string "AVA$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_A
	.2byte EC_WORD_TREASURE
	.2byte EC_WORD_OF
	.2byte EC_WORD_THIS
	.2byte EC_WORD_WORLD
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_WORLD
	.2byte EC_WORD_IS
	.2byte EC_WORD_FULL
	.2byte EC_WORD_OF
	.2byte EC_WORD_WONDER
@ loss speech
	.2byte EC_WORD_WHY
	.2byte EC_WORD_ARE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SO
	.2byte EC_WORD_TERRIBLE
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Ava

@ 225
	.4byte FACILITY_CLASS_COOLTRAINER_F
	.string "MIRIAM$", 8
@ pre-battle speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_A
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_WITH
	.2byte EC_WORD_A
	.2byte EC_MOVE(SCARY_FACE)
@ win speech
	.2byte EC_WORD_AHAHA
	.2byte EC_WORD_YOU
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_AIYEEH
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_YOU
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_ARE
	.2byte EC_WORD_SCARY
	.4byte gBattleFrontierTrainerMons_Miriam

@ 226
	.4byte FACILITY_CLASS_COOLTRAINER_F
	.string "CARRIE$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_SHOW
	.2byte EC_WORD_YOU
	.2byte EC_WORD_GUTSY
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_ALL
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_GUTS
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_NO
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_MOVE(SELF_DESTRUCT)
	.2byte EC_WORD_MODE
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Carrie

@ 227
	.4byte FACILITY_CLASS_COOLTRAINER_F
	.string "GILLIAN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SEEK
	.2byte EC_WORD_A
	.2byte EC_WORD_TRULY
	.2byte EC_WORD_GREAT
	.2byte EC_WORD_BATTLE
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_A_LOT
	.2byte EC_WORD_BETTER
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_A_LITTLE
	.2byte EC_WORD_TOO
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_TO
	.2byte EC_WORD_TAKE
	.4byte gBattleFrontierTrainerMons_Gillian2

@ 228
	.4byte FACILITY_CLASS_PKMN_RANGER_M
	.string "TYLER$", 8
@ pre-battle speech
	.2byte EC_WORD_YO
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_GO
	.2byte EC_WORD_EXCL_EXCL
@ win speech
	.2byte EC_WORD_YO
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
	.2byte EC_WORD_YO
@ loss speech
	.2byte EC_WORD_YO
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_LOST
	.2byte EC_WORD_YO
	.4byte gBattleFrontierTrainerMons_Tyler

@ 229
	.4byte FACILITY_CLASS_PKMN_RANGER_M
	.string "CHAZ$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_TOO
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_POWER
@ win speech
	.2byte EC_WORD_THEY
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_MORE
	.2byte EC_WORD_POWER
	.2byte EC_WORD_NOW
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YEAH
	.2byte EC_MOVE2(TAKE_DOWN)
	.2byte EC_WORD_THEIR
	.2byte EC_WORD_POWER
	.2byte EC_WORD_A_TINY_BIT
	.2byte EC_WORD_PLEASE
	.4byte gBattleFrontierTrainerMons_Chaz

@ 230
	.4byte FACILITY_CLASS_PKMN_RANGER_M
	.string "NELSON$", 8
@ pre-battle speech
	.2byte EC_WORD_WELL_THEN
	.2byte EC_WORD_WILL
	.2byte EC_WORD_THIS
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_WORK
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SEE
	.2byte EC_WORD_THAT
	.2byte EC_WORD_IT
	.2byte EC_WORD_WAS
	.2byte EC_WORD_TOO_STRONG
@ loss speech
	.2byte EC_WORD_IT
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_MATCH_UP
	.2byte EC_WORD_WELL
	.2byte EC_WORD_I
	.2byte EC_WORD_THINK
	.4byte gBattleFrontierTrainerMons_Nelson

@ 231
	.4byte FACILITY_CLASS_PKMN_RANGER_F
	.string "SHANIA$", 8
@ pre-battle speech
	.2byte EC_WORD_ALL
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ABSOLUTELY
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_ME
@ win speech
	.2byte EC_WORD_HAPPINESS
	.2byte EC_WORD_IS
	.2byte EC_WORD_A
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_WITH
	.2byte EC_WORD_CUTE_CHARM
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_SO
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_TO
	.2byte EC_WORD_CUTE
	.2byte EC_WORD_POKEMON
	.4byte gBattleFrontierTrainerMons_Shania

@ 232
	.4byte FACILITY_CLASS_PKMN_RANGER_F
	.string "STELLA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_SEE
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_WELL
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_THEY
	.2byte EC_WORD_BORING
	.2byte EC_WORD_QUES
	.2byte EC_WORD_AHAHA
@ loss speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ARE
	.2byte EC_WORD_SOMETHING
	.2byte EC_WORD_ELSE
	.2byte EC_WORD_ALL_RIGHT
	.4byte gBattleFrontierTrainerMons_Stella

@ 233
	.4byte FACILITY_CLASS_PKMN_RANGER_F
	.string "DORINE$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_YOUNG
	.2byte EC_WORD_AND
	.2byte EC_WORD_STRONG
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_SEE
	.2byte EC_WORD_QUES
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_I
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_WORKING
	.2byte EC_WORD_OUT
	.2byte EC_WORD_AT
	.2byte EC_WORD_ALL
	.4byte gBattleFrontierTrainerMons_Dorine

@ 234
	.4byte FACILITY_CLASS_DRAGON_TAMER
	.string "MADDOX$", 8
@ pre-battle speech
	.2byte EC_WORD_DRAGON
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ARE
	.2byte EC_WORD_MY
	.2byte EC_WORD_NO_1
	.2byte EC_WORD_CHOICE
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_NO
	.2byte EC_WORD_SECRET
	.2byte EC_WORD_DRAGON
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_WIN
@ loss speech
	.2byte EC_WORD_DRAGON
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_NOT
	.2byte EC_WORD_LOSE
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Maddox

@ 235
	.4byte FACILITY_CLASS_DRAGON_TAMER
	.string "DAVIN$", 8
@ pre-battle speech
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_HEAR
	.2byte EC_WORD_YOU
	.2byte EC_MOVE2(ROAR)
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_WROOOAAR_EXCL
	.2byte -1
	.2byte -1
	.2byte EC_WORD_VICTORY
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_WROOOAAR_EXCL
	.2byte -1
	.2byte -1
	.2byte EC_WORD_WHY
	.2byte EC_WORD_QUES_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Davin

@ 236
	.4byte FACILITY_CLASS_DRAGON_TAMER
	.string "TREVON$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_LIVING
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_WITH
	.2byte EC_WORD_DRAGON
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_WAY
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_LIVING
	.2byte EC_WORD_IS
	.2byte EC_WORD_PERFECT
@ loss speech
	.2byte EC_WORD_YOU_VE
	.2byte EC_WORD_DESTROYED
	.2byte EC_WORD_THE
	.2byte EC_WORD_WAY
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_LIVING
	.4byte gBattleFrontierTrainerMons_Trevon

@ 237
	.4byte FACILITY_CLASS_BLACK_BELT
	.string "MATEO$", 8
@ pre-battle speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_BE
	.2byte EC_WORD_OVER
	.2byte EC_WORD_SOON
	.2byte EC_WORD_ENOUGH
@ win speech
	.2byte EC_WORD_WELL
	.2byte EC_WORD_THAT
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_TAKE
	.2byte EC_WORD_VERY
	.2byte EC_WORD_MUCH
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_LOSE
	.2byte EC_WORD_SO
	.2byte EC_WORD_SOON
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Mateo

@ 238
	.4byte FACILITY_CLASS_BLACK_BELT
	.string "BRET$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_ROCK_SOLID
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_THE
	.2byte EC_WORD_BEST
@ win speech
	.2byte EC_WORD_TOUGHNESS
	.2byte EC_WORD_IS
	.2byte EC_WORD_THE
	.2byte EC_WORD_WAY
	.2byte EC_WORD_TO
	.2byte EC_WORD_GO
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_ALSO
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_WORD_PLUSH_DOLL
	.2byte EC_WORD_COLLECTION
	.4byte gBattleFrontierTrainerMons_Bret

@ 239
	.4byte FACILITY_CLASS_BLACK_BELT
	.string "RAUL$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_REJECT
	.2byte EC_WORD_EVERY
	.2byte EC_WORD_WEAK
	.2byte EC_WORD_TRAINER
	.2byte -1
@ win speech
	.2byte EC_WORD_HUMPH
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_ANOTHER
	.2byte EC_WORD_WEAK
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_THERE
	.2byte EC_WORD_IS
	.2byte EC_WORD_NOTHING
	.2byte EC_WORD_WEAK
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_YOU
	.4byte gBattleFrontierTrainerMons_Raul

@ 240
	.4byte FACILITY_CLASS_BATTLE_GIRL
	.string "KAY$", 8
@ pre-battle speech
	.2byte EC_WORD_AND
	.2byte EC_WORD_YET
	.2byte EC_WORD_ANOTHER
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_QUES
	.2byte -1
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TIRED
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_OVER
	.2byte EC_WORD_AT
	.2byte EC_WORD_LAST
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Kay

@ 241
	.4byte FACILITY_CLASS_BATTLE_GIRL
	.string "ELENA$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_GIRL
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_ME
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_A
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_GIRL
	.2byte EC_WORD_AWESOME
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DISLIKE
	.2byte EC_WORD_A
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_GIRL
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Elena

@ 242
	.4byte FACILITY_CLASS_BATTLE_GIRL
	.string "ALANA$", 8
@ pre-battle speech
	.2byte EC_WORD_EAT
	.2byte EC_WORD_MY
	.2byte EC_WORD_INVINCIBLE
	.2byte EC_WORD_ATTACK
	.2byte EC_WORD_YOU
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_TO
	.2byte EC_WORD_LEARN
	.2byte -1
@ loss speech
	.2byte EC_WORD_SO
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_WORD_INVINCIBLE
	.2byte EC_WORD_ATTACK
	.4byte gBattleFrontierTrainerMons_Alana

@ 243
	.4byte FACILITY_CLASS_EXPERT_M
	.string "ALEXAS$", 8
@ pre-battle speech
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_TO
	.2byte EC_WORD_MEET_YOU
	.2byte EC_WORD_YOUNG
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_WAHAHAHA
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_GIVE
	.2byte EC_WORD_IT
	.2byte EC_WORD_UP
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_ARE
	.2byte EC_WORD_A
	.2byte EC_WORD_STRONG
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_KID
	.4byte gBattleFrontierTrainerMons_Alexas

@ 244
	.4byte FACILITY_CLASS_EXPERT_M
	.string "WESTON$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_PLAY
	.2byte EC_WORD_DOWN
	.2byte EC_WORD_ALL_RIGHT
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_FAR
	.2byte EC_WORD_TOO
	.2byte EC_WORD_EASY
	.2byte EC_WORD_TO
	.2byte EC_WORD_ATTACK
@ loss speech
	.2byte EC_WORD_WELL
	.2byte EC_WORD_WELL
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_I
	.2byte EC_WORD_SURRENDER
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Weston

@ 245
	.4byte FACILITY_CLASS_EXPERT_M
	.string "JASPER$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT
	.2byte EC_WORD_OLD
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SKILLED
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_SKILLED
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SHOCKED
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_DOWN
	.2byte EC_WORD_I
	.2byte EC_WORD_GO
	.4byte gBattleFrontierTrainerMons_Jasper

@ 246
	.4byte FACILITY_CLASS_EXPERT_F
	.string "NADIA$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_BEAT
	.2byte EC_WORD_ME
	.2byte EC_WORD_DOWN
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_HAH
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_BEAT
	.2byte EC_WORD_YOU
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_MOVE2(BEAT_UP)
	.2byte EC_WORD_AND
	.2byte EC_WORD_DOWNCAST
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Nadia

@ 247
	.4byte FACILITY_CLASS_EXPERT_F
	.string "MIRANDA$", 8
@ pre-battle speech
	.2byte EC_WORD_WELL
	.2byte EC_WORD_WELL
	.2byte -1
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_START
	.2byte -1
@ win speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_QUES
	.2byte EC_WORD_DONE
	.2byte EC_WORD_SO
	.2byte EC_WORD_SOON
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_WELL
	.2byte EC_WORD_I
	.2byte EC_WORD_SEE
	.2byte EC_WORD_THAT
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TOO_WEAK
	.4byte gBattleFrontierTrainerMons_Miranda

@ 248
	.4byte FACILITY_CLASS_EXPERT_F
	.string "EMMA$", 8
@ pre-battle speech
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_BEEN
	.2byte EC_WORD_HEARING
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_YOU
	.2byte -1
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_THINK
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_MISHEARD
	.2byte EC_WORD_THINGS
	.2byte -1
@ loss speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_BEEN
	.2byte EC_WORD_HEARING
	.2byte EC_WORD_IS
	.2byte EC_WORD_RIGHT
	.4byte gBattleFrontierTrainerMons_Emma

@ 249
	.4byte FACILITY_CLASS_PSYCHIC_M
	.string "ROLANDO$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_A
	.2byte EC_WORD_SUPER
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_HERO
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_WAS
	.2byte EC_WORD_THAT
	.2byte EC_WORD_ENOUGH
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_NOT
	.2byte EC_WORD_BEAT
	.2byte EC_WORD_A
	.2byte EC_WORD_HERO
	.4byte gBattleFrontierTrainerMons_Rolando

@ 250
	.4byte FACILITY_CLASS_PSYCHIC_M
	.string "STANLY$", 8
@ pre-battle speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_BE
	.2byte EC_WORD_AN
	.2byte EC_WORD_EASY
	.2byte EC_WORD_MATCH
@ win speech
	.2byte EC_WORD_IT
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_WAS
	.2byte EC_WORD_EASY
	.2byte -1
	.2byte -1
@ loss speech
	.2byte EC_WORD_ARE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_NOW
	.2byte EC_WORD_QUES
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Stanly

@ 251
	.4byte FACILITY_CLASS_PSYCHIC_M
	.string "DARIO$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(FORESIGHT)
	.2byte EC_WORD_SAYS
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_WIN
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(FORESIGHT)
	.2byte EC_WORD_HAS
	.2byte EC_WORD_BEEN
	.2byte EC_WORD_PERFECT
	.2byte -1
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_SEE
	.2byte EC_WORD_THIS
	.2byte EC_MOVE(REVERSAL)
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Dario

@ 252
	.4byte FACILITY_CLASS_PSYCHIC_F
	.string "KARLEE$", 8
@ pre-battle speech
	.2byte EC_WORD_SOMETHING
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_WILL
	.2byte EC_WORD_COME
	.2byte EC_WORD_OF
	.2byte EC_WORD_THIS
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SEE
	.2byte EC_WORD_QUES
	.2byte EC_WORD_FANTASTIC
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_THAT
	.2byte EC_WORD_SOMETHING
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_WENT
	.2byte EC_WORD_TO
	.2byte EC_WORD_YOU
	.4byte gBattleFrontierTrainerMons_Karlee

@ 253
	.4byte FACILITY_CLASS_PSYCHIC_F
	.string "JAYLIN$", 8
@ pre-battle speech
	.2byte EC_WORD_EVERY
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_HAS
	.2byte EC_WORD_BEEN
	.2byte EC_WORD_TOO_WEAK
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_MAKING
	.2byte EC_WORD_ME
	.2byte EC_MOVE(YAWN)
	.2byte EC_WORD_THAT
	.2byte EC_WORD_BATTLE
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SLEPT
	.2byte EC_WORD_AND
	.2byte EC_WORD_SO
	.2byte EC_WORD_I
	.2byte EC_WORD_LOST
	.4byte gBattleFrontierTrainerMons_Jaylin

@ 254
	.4byte FACILITY_CLASS_PSYCHIC_F
	.string "INGRID$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT
	.2byte EC_WORD_A
	.2byte EC_WORD_VERY
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_TRAINER
@ win speech
	.2byte EC_WORD_WASN_T
	.2byte EC_WORD_THAT
	.2byte EC_WORD_A
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_MATCH
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LOST
	.2byte EC_WORD_CAUSE
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Ingrid

@ 255
	.4byte FACILITY_CLASS_HEX_MANIAC
	.string "DELILAH$", 8
@ pre-battle speech
	.2byte EC_WORD_DON_T
	.2byte EC_MOVE(GRUDGE)
	.2byte EC_WORD_ME
	.2byte EC_WORD_IF_I_WIN
	.2byte EC_WORD_OK_QUES
	.2byte -1
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_TO
	.2byte EC_WORD_SEE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_ANGRY
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_MOVE(GRUDGE)
	.2byte EC_WORD_WITH
	.2byte EC_WORD_YOU
	.4byte gBattleFrontierTrainerMons_Delilah

@ 256
	.4byte FACILITY_CLASS_HEX_MANIAC
	.string "CARLY$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_SCATTER
	.2byte EC_WORD_SOME
	.2byte EC_MOVE2(POISON_POWDER)
	.2byte EC_WORD_ABOUT
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_HOW
	.2byte EC_WORD_MY
	.2byte EC_WORD_STRATEGY
	.2byte EC_WORD_WORKS
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DISLIKE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_AND
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEMON
	.4byte gBattleFrontierTrainerMons_Carly

@ 257
	.4byte FACILITY_CLASS_HEX_MANIAC
	.string "LEXIE$", 8
@ pre-battle speech
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_SEE
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_WASN_T
	.2byte EC_WORD_THAT
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_EH_QUES
	.2byte -1
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_MORE
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_THAN
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.4byte gBattleFrontierTrainerMons_Lexie

@ 258
	.4byte FACILITY_CLASS_POKEMANIAC
	.string "MILLER$", 8
@ pre-battle speech
	.2byte EC_WORD_HELLO
	.2byte EC_WORD_QUES
	.2byte -1
	.2byte EC_WORD_HELLO
	.2byte EC_WORD_QUES_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_HELLO
	.2byte EC_WORD_MOTHER
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_PHONE
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_WORKING
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Miller

@ 259
	.4byte FACILITY_CLASS_POKEMANIAC
	.string "MARV$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN
	.2byte EC_WORD_LOSE
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE(SWAGGER)
	.2byte EC_WORD_NOW
@ win speech
	.2byte EC_WORD_THERE
	.2byte EC_WORD_IS
	.2byte EC_WORD_NO
	.2byte EC_MOVE(SWAGGER)
	.2byte EC_WORD_LEFT
	.2byte EC_WORD_EH_QUES
@ loss speech
	.2byte EC_WORD_GO
	.2byte EC_WORD_ON
	.2byte EC_MOVE(SWAGGER)
	.2byte EC_WORD_ALL
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WANT
	.4byte gBattleFrontierTrainerMons_Marv

@ 260
	.4byte FACILITY_CLASS_POKEMANIAC
	.string "LAYTON$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TOTALLY
	.2byte EC_WORD_COOL
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_UP
	.2byte EC_WORD_TO
	.2byte EC_WORD_ME
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_COOL
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_NO
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Layton

@ 261
	.4byte FACILITY_CLASS_GENTLEMAN
	.string "BROOKS$", 8
@ pre-battle speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_A
	.2byte EC_WORD_HIGH
	.2byte EC_WORD_LEVEL
	.2byte EC_WORD_BATTLE
@ win speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_HIGH
	.2byte EC_WORD_LEVEL
	.2byte EC_WORD_AND
	.2byte EC_WORD_EXCITING
	.2byte EC_WORD_TOO
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_TOO
	.2byte EC_WORD_HIGH
	.2byte EC_WORD_IN
	.2byte EC_WORD_LEVEL
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Brooks

@ 262
	.4byte FACILITY_CLASS_GENTLEMAN
	.string "GREGORY$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT
	.2byte EC_WORD_THAT
	.2byte EC_WORD_OLD
	.2byte EC_WORD_YET
	.2byte -1
@ win speech
	.2byte EC_WORD_WHO
	.2byte EC_WORD_SAYS
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_TOO
	.2byte EC_WORD_OLD
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_NOT
	.2byte EC_WORD_THAT
	.2byte EC_WORD_OLD
	.4byte gBattleFrontierTrainerMons_Gregory

@ 263
	.4byte FACILITY_CLASS_GENTLEMAN
	.string "REESE$", 8
@ pre-battle speech
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_A
	.2byte EC_WORD_COUPLE
	.2byte EC_WORD_THINGS
	.2byte -1
	.2byte -1
@ win speech
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_DIET
	.2byte EC_WORD_PLAY
	.2byte EC_WORD_SPORTS
	.2byte EC_WORD_INSTEAD
	.2byte -1
@ loss speech
	.2byte EC_WORD_INSTEAD
	.2byte EC_WORD_OF
	.2byte EC_WORD_TELEVISION
	.2byte EC_WORD_GET
	.2byte EC_WORD_A
	.2byte EC_WORD_BOOK
	.4byte gBattleFrontierTrainerMons_Reese

@ 264
	.4byte FACILITY_CLASS_RUNNING_TRIATHLETE_M
	.string "MASON$", 8
@ pre-battle speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_THIS
	.2byte EC_WORD_SCARY
	.2byte -1
@ win speech
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_NOW
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_DISAPPOINTED
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Mason

@ 265
	.4byte FACILITY_CLASS_RUNNING_TRIATHLETE_M
	.string "TOBY$", 8
@ pre-battle speech
	.2byte EC_WORD_LISTEN
	.2byte EC_WORD_UP
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_ALWAYS
	.2byte EC_WORD_WIN
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_A
	.2byte EC_WORD_GENIUS
	.2byte EC_WORD_OR
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN
	.2byte EC_WORD_BEAT
	.2byte EC_WORD_YOU
	.2byte EC_WORD_AT
	.2byte EC_WORD_SMARTNESS
	.4byte gBattleFrontierTrainerMons_Toby

@ 266
	.4byte FACILITY_CLASS_RUNNING_TRIATHLETE_F
	.string "DOROTHY$", 8
@ pre-battle speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_SPORTS
	.2byte EC_WORD_WORLD
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_ACCEPT
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_THAT
	.2byte EC_WORD_WIN
	.2byte EC_WORD_WAS
	.2byte EC_WORD_REFRESHING
@ loss speech
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_THAT
	.2byte EC_WORD_LOSS
	.2byte EC_WORD_WAS
	.2byte EC_WORD_REFRESHING
	.4byte gBattleFrontierTrainerMons_Dorothy

@ 267
	.4byte FACILITY_CLASS_RUNNING_TRIATHLETE_F
	.string "PIPER$", 8
@ pre-battle speech
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_YOU
	.2byte EC_WORD_NEED
	.2byte EC_WORD_A
	.2byte EC_WORD_SPEED_BOOST
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_NEED
	.2byte EC_WORD_TO
	.2byte EC_WORD_SHOW
	.2byte EC_WORD_MORE
	.2byte EC_WORD_GUTS
@ loss speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_YOU
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Piper

@ 268
	.4byte FACILITY_CLASS_SWIMMING_TRIATHLETE_M
	.string "FINN$", 8
@ pre-battle speech
	.2byte EC_WORD_NOT
	.2byte EC_WORD_ANOTHER
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
@ win speech
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_THIS
	.2byte EC_WORD_EVER
	.2byte EC_WORD_END
	.2byte EC_WORD_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_FINALLY
	.2byte EC_WORD_GET
	.2byte EC_WORD_TO
	.2byte EC_MOVE2(REST)
	.2byte EC_WORD_A_LITTLE
	.4byte gBattleFrontierTrainerMons_Finn

@ 269
	.4byte FACILITY_CLASS_SWIMMING_TRIATHLETE_M
	.string "SAMIR$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_MOVE2(DIVE)
	.2byte EC_WORD_BELOW
	.2byte EC_WORD_THE
	.2byte EC_MOVE2(SURF)
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_YAHOO
	.2byte EC_WORD_TAKE
	.2byte EC_WORD_A
	.2byte EC_MOVE2(DIVE)
	.2byte EC_WORD_YOU
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_SINK
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Samir

@ 270
	.4byte FACILITY_CLASS_SWIMMING_TRIATHLETE_F
	.string "FIONA$", 8
@ pre-battle speech
	.2byte EC_WORD_DID
	.2byte EC_WORD_YOU
	.2byte EC_WORD_LIMBER
	.2byte EC_WORD_UP
	.2byte EC_WORD_BEFORE
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_NEED
	.2byte EC_WORD_TO
	.2byte EC_WORD_BE
	.2byte EC_WORD_MORE
	.2byte EC_WORD_READY
@ loss speech
	.2byte EC_WORD_BEING
	.2byte EC_WORD_LIMBER
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_WORK
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
	.4byte gBattleFrontierTrainerMons_Fiona

@ 271
	.4byte FACILITY_CLASS_SWIMMING_TRIATHLETE_F
	.string "GLORIA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_TO
	.2byte EC_WORD_ATTACK
	.2byte EC_WORD_WITH
	.2byte EC_WORD_SUCTION_CUPS
@ win speech
	.2byte EC_WORD_GIGGLE
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_OVER
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOU
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_GET
	.2byte EC_WORD_HOW
	.2byte EC_WORD_SUCTION_CUPS
	.2byte EC_WORD_WORK
	.4byte gBattleFrontierTrainerMons_Gloria

@ 272
	.4byte FACILITY_CLASS_CYCLING_TRIATHLETE_M
	.string "NICO$", 8
@ pre-battle speech
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_A
	.2byte EC_MOVE(SONIC_BOOM)
	.2byte EC_WORD_I_VE_ARRIVED
	.2byte -1
	.2byte -1
@ win speech
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_TO
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SO
	.2byte EC_WORD_DOWNCAST
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_WITH
	.2byte EC_WORD_A
	.2byte EC_MOVE2(SUPERSONIC)
	.2byte EC_WORD_SPEED_BOOST
	.4byte gBattleFrontierTrainerMons_Nico

@ 273
	.4byte FACILITY_CLASS_CYCLING_TRIATHLETE_M
	.string "JEREMY$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_MASTER
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_MY
	.2byte EC_WORD_DREAM
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_DREAM
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_FAR
	.2byte EC_WORD_OFF
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I
	.2byte EC_WORD_DREAM
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_HAPPENING
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Jeremy

@ 274
	.4byte FACILITY_CLASS_CYCLING_TRIATHLETE_F
	.string "CAITLIN$", 8
@ pre-battle speech
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_YOU
	.2byte EC_WORD_THINK
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_CUTE
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_THERE
	.2byte EC_WORD_IS
	.2byte EC_WORD_MORE
	.2byte EC_WORD_TO_ME
	.2byte EC_WORD_THAN
	.2byte EC_WORD_CUTENESS
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_CUTE_CHARM
	.2byte EC_WORD_DOESN_T
	.2byte EC_MOVE2(ATTRACT)
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Caitlin

@ 275
	.4byte FACILITY_CLASS_CYCLING_TRIATHLETE_F
	.string "REENA$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_ALWAYS
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_YAY
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_YAHOO
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
@ loss speech
	.2byte EC_WORD_YAHOO
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOU
	.4byte gBattleFrontierTrainerMons_Reena

@ 276
	.4byte FACILITY_CLASS_BUG_MANIAC
	.string "AVERY$", 8
@ pre-battle speech
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_GOT
	.2byte EC_WORD_A_LOT
	.2byte EC_WORD_OF
	.2byte EC_WORD_BUG
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_BUG
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ARE
	.2byte EC_WORD_ALL
	.2byte EC_WORD_UNBELIEVABLE
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_BUG
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ARE
	.2byte EC_WORD_ALL
	.2byte EC_WORD_UPSIDE_DOWN
	.4byte gBattleFrontierTrainerMons_Avery

@ 277
	.4byte FACILITY_CLASS_BUG_MANIAC
	.string "LIAM$", 8
@ pre-battle speech
	.2byte EC_WORD_WE
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_DISLIKE
	.2byte EC_WORD_FIRE
	.2byte EC_WORD_AND
	.2byte EC_WORD_FLYING
@ win speech
	.2byte EC_WORD_BUG
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_BAD
	.2byte EC_WORD_HEY_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_WE
	.2byte EC_WORD_DISLIKE
	.2byte EC_WORD_HEY_QUES
	.4byte gBattleFrontierTrainerMons_Liam

@ 278
	.4byte FACILITY_CLASS_FISHERMAN
	.string "THEO$", 8
@ pre-battle speech
	.2byte EC_WORD_FISHING
	.2byte EC_WORD_IS
	.2byte EC_WORD_MY
	.2byte EC_WORD_CHOICE
	.2byte EC_WORD_IN
	.2byte EC_WORD_LIFE
@ win speech
	.2byte EC_WORD_WATER
	.2byte EC_WORD_POKEMON
	.2byte EC_MOVE2(ATTRACT)
	.2byte EC_WORD_ME
	.2byte EC_WORD_WITHOUT
	.2byte EC_WORD_END
@ loss speech
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_COUNT_ON
	.2byte EC_WORD_THAT
	.2byte EC_WORD_HAPPENING
	.2byte EC_WORD_ANOTHER
	.2byte EC_WORD_TIME
	.4byte gBattleFrontierTrainerMons_Theo

@ 279
	.4byte FACILITY_CLASS_FISHERMAN
	.string "BAILEY$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_AN
	.2byte EC_WORD_ADULT
	.2byte EC_WORD_I
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_EASY
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_AN
	.2byte EC_WORD_ADULT
	.2byte EC_WORD_I
	.2byte EC_MOVE2(SWALLOW)
	.2byte EC_WORD_JOY
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_AN
	.2byte EC_WORD_ADULT
	.2byte EC_WORD_I
	.2byte EC_MOVE2(SWALLOW)
	.2byte EC_MOVE2(FRUSTRATION)
	.4byte gBattleFrontierTrainerMons_Bailey

@ 280
	.4byte FACILITY_CLASS_RUIN_MANIAC
	.string "HUGO$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_TRY
	.2byte EC_WORD_THE
	.2byte EC_WORD_BEST
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_WIN
	.2byte EC_WORD_IF
	.2byte EC_WORD_I
	.2byte EC_WORD_TRY
	.2byte EC_WORD_ENOUGH
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DID
	.2byte EC_WORD_TRY
	.2byte EC_WORD_DIDN_T
	.2byte EC_WORD_I
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Hugo

@ 281
	.4byte FACILITY_CLASS_RUIN_MANIAC
	.string "BRYCE$", 8
@ pre-battle speech
	.2byte EC_WORD_I_WAS
	.2byte EC_WORD_ON
	.2byte EC_WORD_VACATION
	.2byte EC_WORD_UNTIL
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_YESTERDAY
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_HAVEN_T
	.2byte EC_WORD_LOST
	.2byte EC_WORD_MY
	.2byte EC_WORD_SKILL
	.2byte EC_WORD_YET
@ loss speech
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_IT
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_SLEEP
	.4byte gBattleFrontierTrainerMons_Bryce

@ 282
	.4byte FACILITY_CLASS_COLLECTOR
	.string "GIDEON$", 8
@ pre-battle speech
	.2byte EC_WORD_WHAT_S_UP_QUES
	.2byte EC_WORD_YOU
	.2byte EC_WORD_THINK
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_COOL
	.2byte EC_WORD_BUT
	.2byte EC_WORD_NOT
	.2byte EC_WORD_SCARY
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_AT
	.2byte EC_WORD_MY
	.2byte EC_WORD_FABULOUS
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_SENSE
	.4byte gBattleFrontierTrainerMons_Gideon

@ 283
	.4byte FACILITY_CLASS_COLLECTOR
	.string "TRISTON$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WOULD
	.2byte EC_WORD_RATHER
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_AT
	.2byte EC_WORD_POKEMON
@ win speech
	.2byte EC_WORD_HUH_QUES
	.2byte EC_WORD_YOU
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
	.2byte EC_WORD_QUES_EXCL
@ loss speech
	.2byte EC_WORD_SEE
	.2byte EC_WORD_QUES
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_ALWAYS
	.2byte EC_WORD_LOSE
	.4byte gBattleFrontierTrainerMons_Triston

@ 284
	.4byte FACILITY_CLASS_GUITARIST
	.string "CHARLES$", 8
@ pre-battle speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_HOPELESS
	.2byte EC_WORD_TO
	.2byte EC_MOVE2(STRUGGLE)
	.2byte EC_WORD_WITH
	.2byte EC_WORD_ME
@ win speech
	.2byte EC_MOVE(SUBMISSION)
	.2byte EC_WORD_WAS
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_CHOICE
	.2byte -1
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_DOWN
	.2byte EC_WORD_DOWN
	.2byte EC_WORD_DOWN
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Charles

@ 285
	.4byte FACILITY_CLASS_GUITARIST
	.string "RAYMOND$", 8
@ pre-battle speech
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_HEAR
	.2byte EC_WORD_MY
	.2byte EC_WORD_SONG
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_SATISFIED
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_SATISFIED
	.2byte EC_WORD_IS
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_BE
	.4byte gBattleFrontierTrainerMons_Raymond

@ 286
	.4byte FACILITY_CLASS_BIRD_KEEPER
	.string "DIRK$", 8
@ pre-battle speech
	.2byte EC_WORD_FLYING
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ARE
	.2byte EC_WORD_ABOVE
	.2byte EC_WORD_THE
	.2byte EC_MOVE2(REST)
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN_T_WIN
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_FLYING
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_RULE
@ loss speech
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_THERE
	.2byte EC_WORD_MORE
	.2byte EC_WORD_FLYING
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Dirk

@ 287
	.4byte FACILITY_CLASS_BIRD_KEEPER
	.string "HAROLD$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_APPEAL
	.2byte EC_WORD_TO
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DO
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_SO
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DISLIKE
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Harold

@ 288
	.4byte FACILITY_CLASS_SAILOR
	.string "OMAR$", 8
@ pre-battle speech
	.2byte EC_WORD_LET_ME_WIN
	.2byte EC_WORD_IN
	.2byte EC_MOVE(RETURN)
	.2byte EC_WORD_FOR
	.2byte EC_WORD_A
	.2byte EC_MOVE2(PRESENT)
@ win speech
	.2byte EC_WORD_HERE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_ARE
	.2byte EC_WORD_SOME
	.2byte EC_MOVE2(TOXIC)
	.2byte EC_WORD_SWEETS
@ loss speech
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE2(PRESENT)
	.2byte EC_WORD_QUES
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_FOR
	.2byte EC_WORD_QUES_EXCL
	.4byte gBattleFrontierTrainerMons_Omar

@ 289
	.4byte FACILITY_CLASS_SAILOR
	.string "PETER$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_BRAG
	.2byte EC_WORD_ABOUT
	.2byte EC_WORD_MY
	.2byte EC_WORD_HAPPINESS
	.2byte EC_WORD_OK_QUES
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_TO
	.2byte EC_WORD_LISTEN
	.2byte EC_WORD_TO_ME
	.2byte EC_WORD_BRAG
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_DISAPPOINTED
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_LISTEN
	.2byte EC_WORD_TO_ME
	.4byte gBattleFrontierTrainerMons_Peter

@ 290
	.4byte FACILITY_CLASS_HIKER
	.string "DEV$", 8
@ pre-battle speech
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_GET
	.2byte EC_WORD_A
	.2byte EC_WORD_MOVE
	.2byte EC_WORD_ON
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_GET
	.2byte EC_WORD_TO
	.2byte EC_WORD_NAP
	.2byte EC_WORD_AFTER
	.2byte EC_WORD_THAT
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_TO
	.2byte EC_WORD_NAP
	.2byte EC_WORD_AFTER
	.2byte EC_WORD_THAT
	.4byte gBattleFrontierTrainerMons_Dev

@ 291
	.4byte FACILITY_CLASS_HIKER
	.string "COREY$", 8
@ pre-battle speech
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_TEACH
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HOW
	.2byte EC_WORD_TOUGH
	.2byte EC_WORD_I_AM
@ win speech
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_AT
	.2byte EC_WORD_ME
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_A
	.2byte EC_MOVE(BRICK_BREAK)
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(FRUSTRATION)
	.2byte EC_WORD_IS
	.2byte EC_WORD_CLOSE
	.2byte EC_WORD_TO
	.2byte EC_MOVE2(ERUPTION)
	.4byte gBattleFrontierTrainerMons_Corey

@ 292
	.4byte FACILITY_CLASS_KINDLER
	.string "ANDRE$", 8
@ pre-battle speech
	.2byte EC_WORD_NOW
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_A
	.2byte EC_WORD_PERFECT
	.2byte EC_WORD_FLAME_BODY
@ win speech
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_AT
	.2byte EC_WORD_MY
	.2byte EC_WORD_FIERY
	.2byte EC_WORD_DANCE
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WANT
	.2byte EC_WORD_AN
	.2byte EC_MOVE2(EXPLOSION)
	.2byte EC_WORD_HERE
	.2byte EC_WORD_QUES
	.4byte gBattleFrontierTrainerMons_Andre

@ 293
	.4byte FACILITY_CLASS_KINDLER
	.string "FERRIS$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NO_1
	.2byte EC_WORD_IN
	.2byte EC_WORD_THE
	.2byte EC_WORD_OLD
	.2byte EC_WORD_CLASS
@ win speech
	.2byte EC_WORD_NO_1
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT
	.2byte EC_WORD_NO_1
	.2byte EC_WORD_ANY
	.2byte EC_WORD_MORE
	.2byte EC_WORD_ELLIPSIS
	.4byte gBattleFrontierTrainerMons_Ferris

@ 294
	.4byte FACILITY_CLASS_PARASOL_LADY
	.string "ALIVIA$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_GIDDY
	.2byte EC_WORD_SO
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_YOU
@ win speech
	.2byte EC_WORD_IT
	.2byte EC_WORD_WAS
	.2byte EC_WORD_ALL
	.2byte EC_WORD_TOGETHER
	.2byte EC_WORD_TOO
	.2byte EC_WORD_EASY
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_GIDDY
	.2byte EC_WORD_UP
	.2byte EC_WORD_AND
	.2byte EC_WORD_AWAY
	.4byte gBattleFrontierTrainerMons_Alivia

@ 295
	.4byte FACILITY_CLASS_PARASOL_LADY
	.string "PAIGE$", 8
@ pre-battle speech
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_ENJOY
	.2byte EC_WORD_OUR
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_TOGETHER
	.2byte -1
@ win speech
	.2byte EC_WORD_THAT_S_IT_EXCL
	.2byte -1
	.2byte -1
	.2byte EC_WORD_THANK_YOU
	.2byte EC_WORD_VERY
	.2byte EC_WORD_MUCH
@ loss speech
	.2byte EC_WORD_THAT_S_IT_EXCL
	.2byte -1
	.2byte -1
	.2byte EC_WORD_DO
	.2byte EC_WORD_GO
	.2byte EC_WORD_ON
	.4byte gBattleFrontierTrainerMons_Paige

@ 296
	.4byte FACILITY_CLASS_BEAUTY
	.string "ANYA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DISLIKE
	.2byte EC_WORD_OH
	.2byte EC_WORD_SO
	.2byte EC_WORD_PRETTY
	.2byte EC_WORD_FASHION
@ win speech
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_MATCH
	.2byte EC_WORD_THE
	.2byte EC_WORD_PERSON
	.2byte -1
@ loss speech
	.2byte EC_WORD_PRETTY
	.2byte EC_WORD_COULD
	.2byte EC_WORD_BE
	.2byte EC_WORD_GOOD
	.2byte -1
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Anya

@ 297
	.4byte FACILITY_CLASS_BEAUTY
	.string "DAWN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_GO
	.2byte EC_WORD_ALL
	.2byte EC_WORD_OUT
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_BE
	.2byte EC_WORD_A
	.2byte EC_WORD_BABY
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WON
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_MOVE
	.2byte EC_WORD_ON
	.2byte EC_WORD_EXCL
	.4byte gBattleFrontierTrainerMons_Dawn

@ 298
	.4byte FACILITY_CLASS_AROMA_LADY
	.string "ABBY$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_A
	.2byte EC_WORD_TRAINER
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_REFRESHING
@ win speech
	.2byte EC_WORD_VICTORY
	.2byte EC_WORD_HAS
	.2byte EC_WORD_A
	.2byte EC_MOVE(SWEET_SCENT)
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_AN
	.2byte EC_WORD_AWFUL
	.2byte EC_WORD_STENCH
	.2byte EC_WORD_EXCL
	.2byte -1
	.4byte gBattleFrontierTrainerMons_Abby

@ 299
	.4byte FACILITY_CLASS_AROMA_LADY
	.string "GRETEL$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAUSE
	.2byte EC_MOVE(OUTRAGE)
	.2byte EC_WORD_AS
	.2byte EC_WORD_A
	.2byte EC_WORD_TRAINER
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_NATURAL
	.2byte EC_WORD_SEE_YA
	.2byte EC_WORD_BYE_BYE
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_HARD
	.2byte EC_WORD_TO
	.2byte EC_WORD_BELIEVE
	.2byte EC_WORD_BUT
	.2byte EC_WORD_CONGRATS
	.4byte gBattleFrontierTrainerMons_Gretel
