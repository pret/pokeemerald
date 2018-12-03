	.align 2
gSlateportBattleTentTrainers:: @ 85DDA14
@ 0
	.4byte FACILITY_CLASS_AROMA_LADY
	.string "JOLIE$", 8
@ pre-battle speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_WILL
	.2byte EC_WORD_I
	.2byte EC_WORD_BE
	.2byte EC_WORD_TOMORROW
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_FRIDAY
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_MONDAY
	.2byte EC_WORD_ELLIPSIS
	.4byte gSlateportBattleTentTrainerMons_Jolie

@ 1
	.4byte FACILITY_CLASS_RUIN_MANIAC
	.string "MALACHI$", 8
@ pre-battle speech
	.2byte EC_WORD_BAD
	.2byte EC_WORD_NEWS
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_A
	.2byte EC_MOVE(SAND_TOMB)
@ win speech
	.2byte EC_WORD_YEEHAW_EXCL
	.2byte -1
	.2byte -1
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_DONE
	.2byte EC_WORD_IT
@ loss speech
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_LOST
	.2byte EC_WORD_IN
	.2byte EC_WORD_THIS
	.2byte EC_MOVE(SAND_TOMB)
	.2byte EC_WORD_ELLIPSIS
	.4byte gSlateportBattleTentTrainerMons_Malachi

@ 2
	.4byte FACILITY_CLASS_TUBER_F
	.string "KELSIE$", 8
@ pre-battle speech
	.2byte EC_WORD_GO
	.2byte EC_WORD_EXCL_EXCL
	.2byte EC_WORD_MY
	.2byte EC_WORD_BATH
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_EXCL_EXCL
@ win speech
	.2byte EC_WORD_YAHOO
	.2byte EC_WORD_EXCL_EXCL
	.2byte EC_WORD_MY
	.2byte EC_WORD_BATH
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_EXCL_EXCL
@ loss speech
	.2byte EC_WORD_GWAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte EC_WORD_MY
	.2byte EC_WORD_BATH
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_EXCL_EXCL
	.4byte gSlateportBattleTentTrainerMons_Kelsie

@ 3
	.4byte FACILITY_CLASS_TUBER_M
	.string "DAVON$", 8
@ pre-battle speech
	.2byte EC_WORD_YEAH_YEAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_GREAT
	.2byte EC_MOVE(WHIRLPOOL)
	.2byte EC_WORD_ISN_T_IT_QUES
@ win speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_A
	.2byte EC_MOVE(WHIRLPOOL)
	.2byte EC_WORD_YEAH_YEAH
	.2byte EC_WORD_EXCL_EXCL
@ loss speech
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_GET
	.2byte EC_MOVE2(BEAT_UP)
	.2byte EC_WORD_IN
	.2byte EC_WORD_THAT
	.2byte EC_MOVE(WHIRLPOOL)
	.4byte gSlateportBattleTentTrainerMons_Davon

@ 4
	.4byte FACILITY_CLASS_LADY
	.string "GLENDA$", 8
@ pre-battle speech
	.2byte EC_WORD_CONVERSATION
	.2byte EC_WORD_CAN
	.2byte EC_WORD_WAIT
	.2byte EC_WORD_UNTIL
	.2byte EC_WORD_I
	.2byte EC_WORD_WIN
@ win speech
	.2byte EC_WORD_FABULOUS
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_ROCK
@ loss speech
	.2byte EC_WORD_NO
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_WASN_T
	.2byte EC_WORD_SERIOUS
	.4byte gSlateportBattleTentTrainerMons_Glenda

@ 5
	.4byte FACILITY_CLASS_BEAUTY
	.string "HELENA$", 8
@ pre-battle speech
	.2byte EC_WORD_DOES
	.2byte EC_WORD_MY
	.2byte EC_WORD_BEAUTY
	.2byte EC_WORD_INTIMIDATE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SO
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_BUT
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_BORING
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DO
	.2byte EC_WORD_SO
	.2byte EC_WORD_ENJOY
	.2byte EC_WORD_THIS
	.2byte EC_WORD_EXCL
	.4byte gSlateportBattleTentTrainerMons_Helena

@ 6
	.4byte FACILITY_CLASS_RICH_BOY
	.string "RODOLFO$", 8
@ pre-battle speech
	.2byte EC_WORD_GO
	.2byte EC_WORD_GET
	.2byte EC_WORD_A
	.2byte EC_POKEMON(WHISCASH)
	.2byte EC_WORD_FOR
	.2byte EC_WORD_ME
@ win speech
	.2byte EC_WORD_AWW
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_POKEMON(WHISCASH)
@ loss speech
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_A
	.2byte EC_POKEMON(WHISCASH)
	.2byte EC_WORD_BADLY
	.4byte gSlateportBattleTentTrainerMons_Rodolfo

@ 7
	.4byte FACILITY_CLASS_POKEMANIAC
	.string "DAVION$", 8
@ pre-battle speech
	.2byte EC_WORD_GRAAAH
	.2byte EC_WORD_GRAAAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte EC_WORD_GRAAAH
	.2byte EC_WORD_GRAAAH
	.2byte EC_WORD_EXCL_EXCL
@ win speech
	.2byte EC_MOVE2(ROAR)
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_MOVE2(ROAR)
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_URGH
	.2byte EC_WORD_WAAAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Davion

@ 8
	.4byte FACILITY_CLASS_SWIMMER_M
	.string "KENDALL$", 8
@ pre-battle speech
	.2byte EC_WORD_A_LITTLE
	.2byte EC_MOVE2(PETAL_DANCE)
	.2byte EC_WORD_TO
	.2byte EC_WORD_PLEASE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DO
	.2byte EC_WORD_THIS
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_FOR
	.2byte EC_WORD_WORK
@ loss speech
	.2byte EC_WORD_HOW
	.2byte EC_WORD_COULD
	.2byte EC_WORD_YOU
	.2byte EC_MOVE2(POUND)
	.2byte EC_WORD_ME
	.2byte EC_WORD_QUES
	.4byte gSlateportBattleTentTrainerMons_Kendall

@ 9
	.4byte FACILITY_CLASS_CAMPER
	.string "COLTEN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_GO
	.2byte EC_WORD_RUN
	.2byte EC_WORD_AROUND
@ win speech
	.2byte EC_WORD_YAY
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_RUN
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_A
	.2byte EC_WORD_SWIFT_SWIM
	.2byte EC_WORD_WOULD
	.2byte EC_WORD_BE
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_TOO
	.4byte gSlateportBattleTentTrainerMons_Colten

@ 10
	.4byte FACILITY_CLASS_BUG_MANIAC
	.string "IRVIN$", 8
@ pre-battle speech
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_A
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_AT
	.2byte EC_WORD_MY
	.2byte EC_MOVE(CONFUSE_RAY)
@ win speech
	.2byte EC_WORD_YAHOO
	.2byte EC_WORD_MY
	.2byte EC_MOVE(CONFUSE_RAY)
	.2byte EC_WORD_IS
	.2byte EC_WORD_THE
	.2byte EC_WORD_BEST
@ loss speech
	.2byte EC_WORD_GWAH
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_EXCL
	.4byte gSlateportBattleTentTrainerMons_Irvin

@ 11
	.4byte FACILITY_CLASS_GENTLEMAN
	.string "SHAUN$", 8
@ pre-battle speech
	.2byte EC_WORD_LISTEN
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_YOU
	.2byte EC_WORD_AREN_T
	.2byte EC_WORD_VERY
	.2byte EC_WORD_GOOD
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SEE
	.2byte EC_WORD_QUES
	.2byte EC_WORD_I
	.2byte EC_WORD_WAS
	.2byte EC_WORD_RIGHT
@ loss speech
	.2byte EC_WORD_YES
	.2byte EC_WORD_YES
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_QUITE
	.2byte EC_WORD_SOMETHING
	.4byte gSlateportBattleTentTrainerMons_Shaun

@ 12
	.4byte FACILITY_CLASS_GUITARIST
	.string "KYLER$", 8
@ pre-battle speech
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_YAY
@ loss speech
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_ELLIPSIS_ELLIPSIS_ELLIPSIS
	.2byte EC_WORD_WOW
	.4byte gSlateportBattleTentTrainerMons_Kyler

@ 13
	.4byte FACILITY_CLASS_SCHOOL_KID_F
	.string "MAGGIE$", 8
@ pre-battle speech
	.2byte EC_POKEMON(VULPIX)
	.2byte EC_POKEMON(XATU)
	.2byte EC_POKEMON2(UMBREON)
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_UM
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_POKEMON(NOSEPASS)
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_UM
	.2byte EC_POKEMON(SEVIPER)
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_POKEMON(NOSEPASS)
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_UM
	.2byte EC_POKEMON2(SNORLAX)
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_UH_OH
	.4byte gSlateportBattleTentTrainerMons_Maggie

@ 14
	.4byte FACILITY_CLASS_COOLTRAINER_M
	.string "STEPHON$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_ENJOY
	.2byte EC_WORD_AN
	.2byte EC_WORD_EGG
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_ENJOY
	.2byte EC_WORD_THIS
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_VICTORY
@ loss speech
	.2byte EC_WORD_AWFUL
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_JUST
	.2byte EC_WORD_AWFUL
	.2byte EC_WORD_EXCL_EXCL
	.4byte gSlateportBattleTentTrainerMons_Stephon

@ 15
	.4byte FACILITY_CLASS_COOLTRAINER_F
	.string "REBECCA$", 8
@ pre-battle speech
	.2byte EC_WORD_THAT
	.2byte EC_WORD_EGG
	.2byte EC_WORD_HAS
	.2byte EC_WORD_A
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_SHINE
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_SMELL
	.2byte EC_WORD_THAT
	.2byte EC_WORD_STENCH
@ loss speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_ME
	.2byte EC_WORD_STOP
	.2byte EC_WORD_ELLIPSIS
	.4byte gSlateportBattleTentTrainerMons_Rebecca

@ 16
	.4byte FACILITY_CLASS_POKEFAN_M
	.string "REGGIE$", 8
@ pre-battle speech
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_COME
	.2byte EC_WORD_BEFORE
	.2byte EC_WORD_MONEY
	.2byte EC_WORD_OR
	.2byte EC_WORD_FAMILY
@ win speech
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_IS
	.2byte EC_WORD_MAKING
	.2byte EC_WORD_ME
	.2byte EC_WORD_STRONG
@ loss speech
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_WHY
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SO
	.2byte EC_WORD_THICK
	.2byte EC_WORD_ELLIPSIS
	.4byte gSlateportBattleTentTrainerMons_Reggie

@ 17
	.4byte FACILITY_CLASS_POKEFAN_F
	.string "JANAE$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_JUST
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_TOUGH
	.2byte EC_WORD_LOOK
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_HOW
	.2byte EC_WORD_YOU
	.2byte EC_MOVE2(STRUGGLE)
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_A
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_AND
	.2byte EC_WORD_AWFUL
	.2byte EC_WORD_TRAINER
	.4byte gSlateportBattleTentTrainerMons_Janae

@ 18
	.4byte FACILITY_CLASS_EXPERT_M
	.string "CAIDEN$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(CURSE)
	.2byte EC_WORD_WILL
	.2byte EC_WORD_BREAK
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_SPIRIT
@ win speech
	.2byte EC_MOVE2(CURSE)
	.2byte EC_WORD_QUES
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_A
	.2byte EC_WORD_LIE
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_MOVE2(CURSE)
	.2byte EC_WORD_WILL
	.2byte EC_WORD_LAST
	.2byte EC_WORD_FOREVER
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Caiden

@ 19
	.4byte FACILITY_CLASS_EXPERT_F
	.string "KIRSTEN$", 8
@ pre-battle speech
	.2byte EC_WORD_HUH_QUES
	.2byte EC_WORD_A
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SAID
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_HUH_QUES
	.2byte EC_WORD_STRONG
	.2byte EC_WORD_BUT
	.2byte EC_WORD_NOT
	.2byte EC_WORD_STRONG
	.2byte EC_WORD_ENOUGH
@ loss speech
	.2byte EC_WORD_HUH_QUES
	.2byte EC_WORD_I
	.2byte EC_WORD_SURRENDER
	.2byte EC_WORD_TO
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE(STRENGTH)
	.4byte gSlateportBattleTentTrainerMons_Kirsten

@ 20
	.4byte FACILITY_CLASS_YOUNGSTER
	.string "KURTIS$", 8
@ pre-battle speech
	.2byte EC_WORD_SORRY
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_GET
	.2byte EC_MOVE2(BEAT_UP)
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SAID
	.2byte EC_WORD_WE
	.2byte EC_WORD_WOULD
	.2byte EC_MOVE2(POUND)
	.2byte EC_WORD_YOU
@ loss speech
	.2byte EC_WORD_HOW
	.2byte EC_WORD_DID
	.2byte EC_WORD_I
	.2byte EC_WORD_GET
	.2byte EC_MOVE2(BEAT_UP)
	.2byte EC_WORD_QUES
	.4byte gSlateportBattleTentTrainerMons_Kurtis

@ 21
	.4byte FACILITY_CLASS_FISHERMAN
	.string "STEFAN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_ONLY
	.2byte EC_WORD_WANT
	.2byte EC_WORD_CUTE
	.2byte EC_WORD_POKEMON
	.2byte -1
@ win speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_IS
	.2byte EC_WORD_IT
	.2byte EC_WORD_TO
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_KIND
	.2byte EC_WORD_OF
	.2byte EC_WORD_AWESOME
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Stefan

@ 22
	.4byte FACILITY_CLASS_BIRD_KEEPER
	.string "AVERY$", 8
@ pre-battle speech
	.2byte EC_WORD_TOYS
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_MORE
	.2byte EC_WORD_TOYS
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_SOME
	.2byte EC_WORD_EASY
	.2byte EC_WORD_MONEY
	.2byte EC_WORD_FAST
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_TO
	.2byte EC_WORD_WORK
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MONEY
	.4byte gSlateportBattleTentTrainerMons_Avery

@ 23
	.4byte FACILITY_CLASS_NINJA_BOY
	.string "DWANE$", 8
@ pre-battle speech
	.2byte EC_WORD_MMM
	.2byte EC_WORD_TASTY
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_WONDER
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_MMM
	.2byte EC_WORD_MMM
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_KNOW
@ loss speech
	.2byte EC_WORD_MMM
	.2byte EC_WORD_MMM
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_OH_YEAH
	.2byte EC_WORD_THIS_IS_IT_EXCL
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Dwane

@ 24
	.4byte FACILITY_CLASS_PARASOL_LADY
	.string "MCKENNA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DISLIKE
	.2byte EC_WORD_SMALL
	.2byte EC_WORD_TALK
	.2byte EC_WORD_LET_S
	.2byte EC_WORD_GO
@ win speech
	.2byte EC_WORD_YUP
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_THAT
	.2byte -1
	.2byte -1
	.2byte -1
@ loss speech
	.2byte EC_WORD_KTHX_BYE
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Mckenna

@ 25
	.4byte FACILITY_CLASS_SWIMMER_F
	.string "CAMRYN$", 8
@ pre-battle speech
	.2byte EC_WORD_MR
	.2byte EC_WORD_JUDGE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_OUR
	.2byte EC_WORD_TRUST
@ win speech
	.2byte EC_WORD_YES_SIR_EXCL
	.2byte EC_WORD_WE_RE
	.2byte EC_WORD_NO_1
	.2byte EC_WORD_IN
	.2byte EC_WORD_THIS
	.2byte EC_WORD_CONTEST
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_GIVE_UP
	.2byte EC_WORD_MY
	.2byte EC_WORD_IDOL
	.2byte EC_WORD_DREAM
	.4byte gSlateportBattleTentTrainerMons_Camryn

@ 26
	.4byte FACILITY_CLASS_PICNICKER
	.string "NATASHA$", 8
@ pre-battle speech
	.2byte EC_WORD_COME_OVER
	.2byte EC_WORD_TO
	.2byte EC_WORD_MY
	.2byte EC_WORD_PLACE
	.2byte EC_WORD_OK_QUES
	.2byte -1
@ win speech
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_OVER
	.2byte EC_WORD_IT
	.2byte EC_WORD_WILL
	.2byte EC_WORD_BE
	.2byte EC_WORD_GREAT
@ loss speech
	.2byte EC_WORD_AWW
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_YOU
	.2byte EC_WORD_COME_OVER
	.2byte EC_WORD_QUES
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Natasha

@ 27
	.4byte FACILITY_CLASS_SAILOR
	.string "AUSTYN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_CARE
	.2byte EC_WORD_HOW
	.2byte EC_WORD_WE
	.2byte EC_WORD_MATCH_UP
@ win speech
	.2byte EC_WORD_HAH
	.2byte EC_WORD_BACK
	.2byte EC_WORD_TO
	.2byte EC_WORD_SCHOOL
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOU
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_TO
	.2byte EC_WORD_STUDY
	.2byte EC_WORD_MY
	.2byte EC_WORD_LESSONS
	.4byte gSlateportBattleTentTrainerMons_Austyn

@ 28
	.4byte FACILITY_CLASS_COLLECTOR
	.string "DONOVAN$", 8
@ pre-battle speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_FEELING
	.2byte EC_WORD_SLIMY
	.2byte EC_WORD_ALL
	.2byte EC_WORD_OVER
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_GOING
	.2byte EC_WORD_DOWN
	.2byte EC_WORD_THE
	.2byte EC_MOVE2(MEGA_DRAIN)
	.2byte EC_WORD_HAHAHA
@ loss speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NATURALLY
	.2byte EC_WORD_SLIMY
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_I_AM
	.4byte gSlateportBattleTentTrainerMons_Donovan

@ 29
	.4byte FACILITY_CLASS_LASS
	.string "TAMIA$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_ANGRY
	.2byte EC_WORD_WITH
	.2byte EC_WORD_MY
	.2byte EC_WORD_FATHER
	.2byte EC_WORD_ELLIPSIS
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_DISLIKE
	.2byte EC_WORD_MY
	.2byte EC_WORD_FATHER
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_JUST
	.2byte EC_WORD_SO
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_MY
	.2byte EC_WORD_FATHER
	.4byte gSlateportBattleTentTrainerMons_Tamia
