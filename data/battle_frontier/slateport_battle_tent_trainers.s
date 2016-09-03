	.align 2
gSlateportBattleTentTrainers:: @ 85DDA14
@ 0
	.4byte TRAINER_CLASS_AROMA_LADY
	.string "JOLIE$", 8
@ pre-battle speech
	ec_word WHAT
	ec_word WILL
	ec_word I
	ec_word BE
	ec_word TOMORROW
	ec_word QUES
@ win speech
	ec_word I_AM
	ec_word FEELING
	ec_word LIKE
	ec_word IT_S
	ec_word FRIDAY
	ec_word EXCL
@ loss speech
	ec_word I_AM
	ec_word FEELING
	ec_word LIKE
	ec_word IT_S
	ec_word MONDAY
	ec_word ELLIPSIS
	.4byte gSlateportBattleTentTrainerMons_Jolie

@ 1
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.string "MALACHI$", 8
@ pre-battle speech
	ec_word BAD
	ec_word NEWS
	ec_word EXCL
	ec_word IT_S
	ec_word A
	ec_move1 SAND_TOMB
@ win speech
	ec_word YEEHAW_EXCL
	.2byte -1
	.2byte -1
	ec_word I_VE
	ec_word DONE
	ec_word IT
@ loss speech
	ec_word I_VE
	ec_word LOST
	ec_word IN
	ec_word THIS
	ec_move1 SAND_TOMB
	ec_word ELLIPSIS
	.4byte gSlateportBattleTentTrainerMons_Malachi

@ 2
	.4byte TRAINER_CLASS_TUBER_1
	.string "KELSIE$", 8
@ pre-battle speech
	ec_word GO
	ec_word EXCL_EXCL
	ec_word MY
	ec_word BATH
	ec_word POKEMON
	ec_word EXCL_EXCL
@ win speech
	ec_word YAHOO
	ec_word EXCL_EXCL
	ec_word MY
	ec_word BATH
	ec_word POKEMON
	ec_word EXCL_EXCL
@ loss speech
	ec_word GWAH
	ec_word EXCL_EXCL
	ec_word MY
	ec_word BATH
	ec_word POKEMON
	ec_word EXCL_EXCL
	.4byte gSlateportBattleTentTrainerMons_Kelsie

@ 3
	.4byte TRAINER_CLASS_TUBER_2
	.string "DAVON$", 8
@ pre-battle speech
	ec_word YEAH_YEAH
	ec_word EXCL_EXCL
	.2byte -1
	ec_word GREAT
	ec_move1 WHIRLPOOL
	ec_word ISN_T_IT_QUES
@ win speech
	ec_word THAT_WAS
	ec_word LIKE
	ec_word A
	ec_move1 WHIRLPOOL
	ec_word YEAH_YEAH
	ec_word EXCL_EXCL
@ loss speech
	ec_word DON_T
	ec_word GET
	ec_move2 BEAT_UP
	ec_word IN
	ec_word THAT
	ec_move1 WHIRLPOOL
	.4byte gSlateportBattleTentTrainerMons_Davon

@ 4
	.4byte TRAINER_CLASS_LADY
	.string "GLENDA$", 8
@ pre-battle speech
	ec_word CONVERSATION
	ec_word CAN
	ec_word WAIT
	ec_word UNTIL
	ec_word I
	ec_word WIN
@ win speech
	ec_word FABULOUS
	ec_word EXCL
	ec_word I_AM
	ec_word GOING
	ec_word TO
	ec_word ROCK
@ loss speech
	ec_word NO
	ec_word EXCL
	.2byte -1
	ec_word I
	ec_word WASN_T
	ec_word SERIOUS
	.4byte gSlateportBattleTentTrainerMons_Glenda

@ 5
	.4byte TRAINER_CLASS_BEAUTY
	.string "HELENA$", 8
@ pre-battle speech
	ec_word DOES
	ec_word MY
	ec_word BEAUTY
	ec_word INTIMIDATE
	ec_word YOU
	ec_word QUES
@ win speech
	ec_word I_AM
	ec_word SO
	ec_word SORRY
	ec_word BUT
	ec_word YOU_RE
	ec_word BORING
@ loss speech
	ec_word I
	ec_word DO
	ec_word SO
	ec_word ENJOY
	ec_word THIS
	ec_word EXCL
	.4byte gSlateportBattleTentTrainerMons_Helena

@ 6
	.4byte TRAINER_CLASS_RICH_BOY
	.string "RODOLFO$", 8
@ pre-battle speech
	ec_word GO
	ec_word GET
	ec_word A
	ec_pokemon1 WHISCASH
	ec_word FOR
	ec_word ME
@ win speech
	ec_word AWW
	ec_word YOU
	ec_word DON_T
	ec_word HAVE
	ec_word A
	ec_pokemon1 WHISCASH
@ loss speech
	ec_word PLEASE
	ec_word I
	ec_word NEED
	ec_word A
	ec_pokemon1 WHISCASH
	ec_word BADLY
	.4byte gSlateportBattleTentTrainerMons_Rodolfo

@ 7
	.4byte TRAINER_CLASS_POKEMANIAC
	.string "DAVION$", 8
@ pre-battle speech
	ec_word GRAAAH
	ec_word GRAAAH
	ec_word EXCL_EXCL
	ec_word GRAAAH
	ec_word GRAAAH
	ec_word EXCL_EXCL
@ win speech
	ec_move2 ROAR
	ec_word EXCL
	.2byte -1
	ec_move2 ROAR
	ec_word EXCL_EXCL
	.2byte -1
@ loss speech
	ec_word URGH
	ec_word WAAAH
	ec_word EXCL_EXCL
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Davion

@ 8
	.4byte TRAINER_CLASS_SWIMMER_M
	.string "KENDALL$", 8
@ pre-battle speech
	ec_word A_LITTLE
	ec_move2 PETAL_DANCE
	ec_word TO
	ec_word PLEASE
	ec_word YOU
	ec_word EXCL
@ win speech
	ec_word I
	ec_word DO
	ec_word THIS
	ec_word ONLY
	ec_word FOR
	ec_word WORK
@ loss speech
	ec_word HOW
	ec_word COULD
	ec_word YOU
	ec_move2 POUND
	ec_word ME
	ec_word QUES
	.4byte gSlateportBattleTentTrainerMons_Kendall

@ 9
	.4byte TRAINER_CLASS_CAMPER
	.string "COLTEN$", 8
@ pre-battle speech
	ec_word I
	ec_word WANT
	ec_word TO
	ec_word GO
	ec_word RUN
	ec_word AROUND
@ win speech
	ec_word YAY
	ec_word EXCL
	ec_word WANT
	ec_word TO
	ec_word RUN
	ec_word QUES
@ loss speech
	ec_word A
	ec_word SWIFT_SWIM
	ec_word WOULD
	ec_word BE
	ec_word GOOD
	ec_word TOO
	.4byte gSlateportBattleTentTrainerMons_Colten

@ 10
	.4byte TRAINER_CLASS_BUG_MANIAC
	.string "IRVIN$", 8
@ pre-battle speech
	ec_word HAVE
	ec_word A
	ec_word LOOK
	ec_word AT
	ec_word MY
	ec_move1 CONFUSE_RAY
@ win speech
	ec_word YAHOO
	ec_word MY
	ec_move1 CONFUSE_RAY
	ec_word IS
	ec_word THE
	ec_word BEST
@ loss speech
	ec_word GWAH
	ec_word EXCL_EXCL
	.2byte -1
	ec_word I_AM
	ec_word SORRY
	ec_word EXCL
	.4byte gSlateportBattleTentTrainerMons_Irvin

@ 11
	.4byte TRAINER_CLASS_GENTLEMAN
	.string "SHAUN$", 8
@ pre-battle speech
	ec_word LISTEN
	ec_word ELLIPSIS
	ec_word YOU
	ec_word AREN_T
	ec_word VERY
	ec_word GOOD
@ win speech
	ec_word YOU
	ec_word SEE
	ec_word QUES
	ec_word I
	ec_word WAS
	ec_word RIGHT
@ loss speech
	ec_word YES
	ec_word YES
	ec_word ELLIPSIS
	ec_word YOU_RE
	ec_word QUITE
	ec_word SOMETHING
	.4byte gSlateportBattleTentTrainerMons_Shaun

@ 12
	.4byte TRAINER_CLASS_GUITARIST
	.string "KYLER$", 8
@ pre-battle speech
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word QUES
@ win speech
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word YAY
@ loss speech
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word WOW
	.4byte gSlateportBattleTentTrainerMons_Kyler

@ 13
	.4byte TRAINER_CLASS_SCHOOL_KID_2
	.string "MAGGIE$", 8
@ pre-battle speech
	ec_pokemon1 VULPIX
	ec_pokemon1 XATU
	ec_pokemon2 UMBREON
	ec_word ELLIPSIS
	ec_word UM
	ec_word ELLIPSIS
@ win speech
	ec_pokemon1 NOSEPASS
	ec_word ELLIPSIS
	ec_word UM
	ec_pokemon1 SEVIPER
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_pokemon1 NOSEPASS
	ec_word ELLIPSIS
	ec_word UM
	ec_pokemon2 SNORLAX
	ec_word ELLIPSIS
	ec_word UH_OH
	.4byte gSlateportBattleTentTrainerMons_Maggie

@ 14
	.4byte TRAINER_CLASS_COOLTRAINER_1
	.string "STEPHON$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word GOING
	ec_word TO
	ec_word ENJOY
	ec_word AN
	ec_word EGG
@ win speech
	ec_word I
	ec_word WILL
	ec_word ENJOY
	ec_word THIS
	ec_word TASTY
	ec_word VICTORY
@ loss speech
	ec_word AWFUL
	ec_word EXCL_EXCL
	.2byte -1
	ec_word JUST
	ec_word AWFUL
	ec_word EXCL_EXCL
	.4byte gSlateportBattleTentTrainerMons_Stephon

@ 15
	.4byte TRAINER_CLASS_COOLTRAINER_2
	.string "REBECCA$", 8
@ pre-battle speech
	ec_word THAT
	ec_word EGG
	ec_word HAS
	ec_word A
	ec_word TASTY
	ec_word SHINE
@ win speech
	ec_word I
	ec_word CAN_T
	ec_word EXCL
	ec_word SMELL
	ec_word THAT
	ec_word STENCH
@ loss speech
	ec_word YOU
	ec_word CAN_T
	ec_word MAKE
	ec_word ME
	ec_word STOP
	ec_word ELLIPSIS
	.4byte gSlateportBattleTentTrainerMons_Rebecca

@ 16
	.4byte TRAINER_CLASS_POKEFAN_1
	.string "REGGIE$", 8
@ pre-battle speech
	ec_word POKEMON
	ec_word COME
	ec_word BEFORE
	ec_word MONEY
	ec_word OR
	ec_word FAMILY
@ win speech
	ec_word THAT_S
	ec_word WHAT
	ec_word IS
	ec_word MAKING
	ec_word ME
	ec_word STRONG
@ loss speech
	ec_word THAT_S
	ec_word WHY
	ec_word I_AM
	ec_word SO
	ec_word THICK
	ec_word ELLIPSIS
	.4byte gSlateportBattleTentTrainerMons_Reggie

@ 17
	.4byte TRAINER_CLASS_POKEFAN_2
	.string "JANAE$", 8
@ pre-battle speech
	ec_word I
	ec_word JUST
	ec_word ADORE
	ec_word YOUR
	ec_word TOUGH
	ec_word LOOK
@ win speech
	ec_word I
	ec_word LIKE
	ec_word HOW
	ec_word YOU
	ec_move2 STRUGGLE
	.2byte -1
@ loss speech
	ec_word YOU_RE
	ec_word A
	ec_word MEAN
	ec_word AND
	ec_word AWFUL
	ec_word TRAINER
	.4byte gSlateportBattleTentTrainerMons_Janae

@ 18
	.4byte TRAINER_CLASS_EXPERT_1
	.string "CAIDEN$", 8
@ pre-battle speech
	ec_word MY
	ec_move2 CURSE
	ec_word WILL
	ec_word BREAK
	ec_word YOUR
	ec_word SPIRIT
@ win speech
	ec_move2 CURSE
	ec_word QUES
	ec_word IT_S
	ec_word A
	ec_word LIE
	ec_word ELLIPSIS
@ loss speech
	ec_word MY
	ec_move2 CURSE
	ec_word WILL
	ec_word LAST
	ec_word FOREVER
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Caiden

@ 19
	.4byte TRAINER_CLASS_EXPERT_2
	.string "KIRSTEN$", 8
@ pre-battle speech
	ec_word HUH_QUES
	ec_word A
	ec_word BATTLE
	ec_word YOU
	ec_word SAID
	ec_word QUES
@ win speech
	ec_word HUH_QUES
	ec_word STRONG
	ec_word BUT
	ec_word NOT
	ec_word STRONG
	ec_word ENOUGH
@ loss speech
	ec_word HUH_QUES
	ec_word I
	ec_word SURRENDER
	ec_word TO
	ec_word YOUR
	ec_move1 STRENGTH
	.4byte gSlateportBattleTentTrainerMons_Kirsten

@ 20
	.4byte TRAINER_CLASS_YOUNGSTER
	.string "KURTIS$", 8
@ pre-battle speech
	ec_word SORRY
	ec_word YOU_RE
	ec_word GOING
	ec_word TO
	ec_word GET
	ec_move2 BEAT_UP
@ win speech
	ec_word I
	ec_word SAID
	ec_word WE
	ec_word WOULD
	ec_move2 POUND
	ec_word YOU
@ loss speech
	ec_word HOW
	ec_word DID
	ec_word I
	ec_word GET
	ec_move2 BEAT_UP
	ec_word QUES
	.4byte gSlateportBattleTentTrainerMons_Kurtis

@ 21
	.4byte TRAINER_CLASS_FISHERMAN
	.string "STEFAN$", 8
@ pre-battle speech
	ec_word I
	ec_word ONLY
	ec_word WANT
	ec_word CUTE
	ec_word POKEMON
	.2byte -1
@ win speech
	ec_word WHAT
	ec_word IS
	ec_word IT
	ec_word TO
	ec_word YOU
	ec_word QUES
@ loss speech
	ec_word YOU_RE
	ec_word KIND
	ec_word OF
	ec_word AWESOME
	ec_word ELLIPSIS
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Stefan

@ 22
	.4byte TRAINER_CLASS_BIRD_KEEPER
	.string "AVERY$", 8
@ pre-battle speech
	ec_word TOYS
	ec_word EXCL
	ec_word I
	ec_word NEED
	ec_word MORE
	ec_word TOYS
@ win speech
	ec_word I
	ec_word NEED
	ec_word SOME
	ec_word EASY
	ec_word MONEY
	ec_word FAST
@ loss speech
	ec_word I
	ec_word NEED
	ec_word TO
	ec_word WORK
	ec_word FOR
	ec_word MONEY
	.4byte gSlateportBattleTentTrainerMons_Avery

@ 23
	.4byte TRAINER_CLASS_NINJA_BOY
	.string "DWANE$", 8
@ pre-battle speech
	ec_word MMM
	ec_word TASTY
	ec_word ELLIPSIS
	ec_word WONDER
	ec_word WHAT
	ec_word QUES
@ win speech
	ec_word MMM
	ec_word MMM
	ec_word ELLIPSIS
	ec_word YOU
	ec_word DON_T
	ec_word KNOW
@ loss speech
	ec_word MMM
	ec_word MMM
	ec_word ELLIPSIS
	ec_word OH_YEAH
	ec_word THIS_IS_IT_EXCL
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Dwane

@ 24
	.4byte TRAINER_CLASS_PARASOL_LADY
	.string "MCKENNA$", 8
@ pre-battle speech
	ec_word I
	ec_word DISLIKE
	ec_word SMALL
	ec_word TALK
	ec_word LET_S
	ec_word GO
@ win speech
	ec_word YUP
	ec_word THAT_S
	ec_word THAT
	.2byte -1
	.2byte -1
	.2byte -1
@ loss speech
	ec_word KTHX_BYE
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Mckenna

@ 25
	.4byte TRAINER_CLASS_SWIMMER_F
	.string "CAMRYN$", 8
@ pre-battle speech
	ec_word MR
	ec_word JUDGE
	ec_word YOU
	ec_word HAVE
	ec_word OUR
	ec_word TRUST
@ win speech
	ec_word YES_SIR_EXCL
	ec_word WE_RE
	ec_word NO_1
	ec_word IN
	ec_word THIS
	ec_word CONTEST
@ loss speech
	ec_word I
	ec_word WON_T
	ec_word GIVE_UP
	ec_word MY
	ec_word IDOL
	ec_word DREAM
	.4byte gSlateportBattleTentTrainerMons_Camryn

@ 26
	.4byte TRAINER_CLASS_PICNICKER
	.string "NATASHA$", 8
@ pre-battle speech
	ec_word COME_OVER
	ec_word TO
	ec_word MY
	ec_word PLACE
	ec_word OK_QUES
	.2byte -1
@ win speech
	ec_word COME_ON
	ec_word OVER
	ec_word IT
	ec_word WILL
	ec_word BE
	ec_word GREAT
@ loss speech
	ec_word AWW
	ec_word WON_T
	ec_word YOU
	ec_word COME_OVER
	ec_word QUES
	.2byte -1
	.4byte gSlateportBattleTentTrainerMons_Natasha

@ 27
	.4byte TRAINER_CLASS_SAILOR
	.string "AUSTYN$", 8
@ pre-battle speech
	ec_word I
	ec_word DON_T
	ec_word CARE
	ec_word HOW
	ec_word WE
	ec_word MATCH_UP
@ win speech
	ec_word HAH
	ec_word BACK
	ec_word TO
	ec_word SCHOOL
	ec_word FOR
	ec_word YOU
@ loss speech
	ec_word I
	ec_word NEED
	ec_word TO
	ec_word STUDY
	ec_word MY
	ec_word LESSONS
	.4byte gSlateportBattleTentTrainerMons_Austyn

@ 28
	.4byte TRAINER_CLASS_COLLECTOR
	.string "DONOVAN$", 8
@ pre-battle speech
	ec_word OH
	ec_word I_AM
	ec_word FEELING
	ec_word SLIMY
	ec_word ALL
	ec_word OVER
@ win speech
	ec_word YOU_RE
	ec_word GOING
	ec_word DOWN
	ec_word THE
	ec_move2 MEGA_DRAIN
	ec_word HAHAHA
@ loss speech
	ec_word I_AM
	ec_word NATURALLY
	ec_word SLIMY
	ec_word THAT_S
	ec_word WHAT
	ec_word I_AM
	.4byte gSlateportBattleTentTrainerMons_Donovan

@ 29
	.4byte TRAINER_CLASS_LASS
	.string "TAMIA$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word ANGRY
	ec_word WITH
	ec_word MY
	ec_word FATHER
	ec_word ELLIPSIS
@ win speech
	ec_word I
	ec_word REALLY
	ec_word DISLIKE
	ec_word MY
	ec_word FATHER
	ec_word EXCL
@ loss speech
	ec_word I
	ec_word JUST
	ec_word SO
	ec_word ADORE
	ec_word MY
	ec_word FATHER
	.4byte gSlateportBattleTentTrainerMons_Tamia
