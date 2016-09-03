	.align 2, 0

gFallarborBattleTentTrainers: @ 85DF084
@ 0
	.4byte TRAINER_CLASS_AROMA_LADY
	.charmapstr "AMBER$", 8
@ pre-battle speech
	ec_word I
	ec_word HAVE
	ec_word TO
	ec_word DIET
	ec_word EVERY
	ec_word DAY
@ win speech
	ec_word A
	ec_move1 NIGHTMARE
	ec_word OF
	ec_word SWEETS
	ec_word SHOCKED
	ec_word ME
@ loss speech
	ec_word IF
	ec_word YOU
	ec_word GIVE_UP
	ec_word YOU
	ec_word WILL
	ec_word LOSE
	.4byte gFallarborBattleTentTrainerMons_Amber

@ 1
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.charmapstr "JAVIER$", 8
@ pre-battle speech
	ec_word I
	ec_word NEVER
	ec_word EVER
	ec_word HAVE
	ec_word ENOUGH
	ec_word MONEY
@ win speech
	ec_word I
	ec_word WON
	ec_word BUT
	ec_word I
	ec_word NEED
	ec_word MONEY
@ loss speech
	ec_word I
	ec_word NEED
	ec_word MONEY
	ec_word FOR
	ec_word A
	ec_word BIKE
	.4byte gFallarborBattleTentTrainerMons_Javier

@ 2
	.4byte TRAINER_CLASS_TUBER_1
	.charmapstr "NATALIE$", 8
@ pre-battle speech
	ec_word THE
	ec_word WAY
	ec_word I
	ec_word BATTLE
	ec_word IS
	ec_word WEIRD
@ win speech
	ec_word YOU_RE
	ec_word MUCH
	ec_word TOO_WEAK
	ec_word FOR
	ec_word THIS
	ec_word PLACE
@ loss speech
	ec_word GIVE_ME
	ec_word AN
	ec_word EASY
	ec_word MATCH
	ec_word NEXT
	ec_word TIME
	.4byte gFallarborBattleTentTrainerMons_Natalie

@ 3
	.4byte TRAINER_CLASS_TUBER_2
	.charmapstr "TREVE$", 8
@ pre-battle speech
	ec_word LOOK
	ec_word AT
	ec_word MY
	ec_move2 METRONOME
	ec_word AND
	ec_word SLEEP
@ win speech
	ec_word YEAH
	ec_word EXCL
	ec_move1 HYPNOSIS
	ec_word IS
	ec_word TOTALLY
	ec_word GREAT
@ loss speech
	ec_word MY
	ec_move1 HYPNOSIS
	ec_word DIDN_T
	ec_word WORK
	ec_word ELLIPSIS
	.2byte -1
	.4byte gFallarborBattleTentTrainerMons_Treve

@ 4
	.4byte TRAINER_CLASS_LADY
	.charmapstr "ARIANNA$", 8
@ pre-battle speech
	ec_word IF_I_WIN
	ec_word GIVE_ME
	ec_word POKEMON
	ec_word FOR
	ec_word MY
	ec_word COLLECTION
@ win speech
	ec_word YOUR
	ec_word POKEMON
	ec_word ARE
	ec_word TOO_WEAK
	ec_word TO
	ec_word COLLECT
@ loss speech
	ec_word YOUR
	ec_word POKEMON
	ec_word ARE
	ec_word SOMETHING
	ec_word ELSE
	ec_word ELLIPSIS
	.4byte gFallarborBattleTentTrainerMons_Arianna

@ 5
	.4byte TRAINER_CLASS_BEAUTY
	.charmapstr "JADYN$", 8
@ pre-battle speech
	ec_word MY
	ec_word NAME
	ec_word IS
	ec_word REALLY
	ec_word A
	ec_word MYSTERY
@ win speech
	ec_word MY
	ec_word NAME
	ec_word GOES
	ec_word ON
	ec_word A
	ec_word MYSTERY
@ loss speech
	ec_word MY
	ec_word NAME
	ec_word QUES
	ec_word I_AM
	ec_word YOUR
	ec_word MOTHER
	.4byte gFallarborBattleTentTrainerMons_Jadyn

@ 6
	.4byte TRAINER_CLASS_RICH_BOY
	.charmapstr "GERARDO$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word THE
	ec_word BEST
	ec_word HERO
	ec_word EVER
	ec_word EXCL
@ win speech
	ec_word SEE
	ec_word WHAT
	ec_word I
	ec_word MEAN
	ec_word QUES
	.2byte -1
@ loss speech
	ec_word HUH_QUES
	ec_word YOU
	ec_word WERE
	ec_word RIGHT
	ec_word QUES
	.2byte -1
	.4byte gFallarborBattleTentTrainerMons_Gerardo

@ 7
	.4byte TRAINER_CLASS_POKEMANIAC
	.charmapstr "JONN$", 8
@ pre-battle speech
	ec_word THE
	ec_word WORLD
	ec_move2 SUPERPOWER
	ec_move2 STOMP
	ec_word CONTEST
	ec_word EXCL_EXCL
@ win speech
	ec_word I_AM
	ec_word NO_1
	ec_word EXCL_EXCL
	ec_word HEAR
	ec_word ME
	ec_move2 ROAR
@ loss speech
	ec_word I
	ec_word GIVE_UP
	ec_word EXCL
	ec_word YOU_RE
	ec_word NO_1
	ec_word EXCL
	.4byte gFallarborBattleTentTrainerMons_Jonn

@ 8
	.4byte TRAINER_CLASS_SWIMMER_M
	.charmapstr "ESTEBAN$", 8
@ pre-battle speech
	ec_word YOU_RE
	ec_word A
	ec_word GOOD
	ec_word TRAINER
	ec_word QUES
	ec_word UNBELIEVABLE
@ win speech
	ec_word YOU_RE
	ec_word SOME
	ec_word PUSHOVER
	ec_word OF
	ec_word A
	ec_word TRAINER
@ loss speech
	ec_word YOU_RE
	ec_word MUCH
	ec_word TOO
	ec_word MUCH
	ec_word FOR
	ec_word ME
	.4byte gFallarborBattleTentTrainerMons_Esteban

@ 9
	.4byte TRAINER_CLASS_CAMPER
	.charmapstr "JAMESON$", 8
@ pre-battle speech
	ec_word MY
	ec_word POKEMON
	ec_word ARE
	ec_word SILKY
	ec_word SMOOTH
	ec_word EXCL
@ win speech
	ec_word MY
	ec_word SILKY
	ec_word SMOOTH
	ec_word POKEMON
	ec_word RULE
	ec_word EXCL
@ loss speech
	ec_word MY
	ec_word POKEMON
	ec_move2 STRUGGLE
	ec_word IN
	ec_word YOUR
	ec_word STICKY_HOLD
	.4byte gFallarborBattleTentTrainerMons_Jameson

@ 10
	.4byte TRAINER_CLASS_BUG_MANIAC
	.charmapstr "ALANZO$", 8
@ pre-battle speech
	ec_move2 FORESIGHT
	ec_word IS
	ec_word A
	ec_word POWER
	ec_word I
	ec_word HAVE
@ win speech
	ec_word YOU_RE
	ec_word OBLIVIOUS
	ec_word ABOUT
	ec_move2 FORESIGHT
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word MY
	ec_move2 FORESIGHT
	ec_word IS
	ec_word ALWAYS
	ec_word RIGHT
	ec_word EXCL
	.4byte gFallarborBattleTentTrainerMons_Alanzo

@ 11
	.4byte TRAINER_CLASS_GENTLEMAN
	.charmapstr "HOWARD$", 8
@ pre-battle speech
	ec_word YOUR
	ec_word POKEMON
	ec_word CAN_T
	ec_word BEAT
	ec_word ME
	.2byte -1
@ win speech
	ec_word YOU
	ec_word COULDN_T
	ec_word WIN
	ec_word COULD
	ec_word YOU
	ec_word QUES
@ loss speech
	ec_word YOU
	ec_word WOULD
	ec_word GO
	ec_word ALL
	ec_word OUT
	ec_word ELLIPSIS
	.4byte gFallarborBattleTentTrainerMons_Howard

@ 12
	.4byte TRAINER_CLASS_GUITARIST
	.charmapstr "CONRAD$", 8
@ pre-battle speech
	ec_word YOUR
	ec_word POKEMON
	ec_word ARE
	ec_word PRETTY
	ec_word WILD
	ec_word EXCL
@ win speech
	ec_word WHOAH
	ec_word EXCL_EXCL
	.2byte -1
	ec_word LET_S
	ec_word DANCE
	ec_word EXCL
@ loss speech
	ec_word MY
	ec_word MUSIC
	ec_word WILL
	ec_word PLAY
	ec_word ON
	ec_word ELLIPSIS
	.4byte gFallarborBattleTentTrainerMons_Conrad

@ 13
	.4byte TRAINER_CLASS_SCHOOL_KID_2
	.charmapstr "MAKENNA$", 8
@ pre-battle speech
	ec_word SHOW
	ec_word ME
	ec_word THAT
	ec_word YOU
	ec_word MEAN
	ec_word IT
@ win speech
	ec_word THAT_S
	ec_word WHY
	ec_word I
	ec_word STUDY
	ec_word EVERY
	ec_word DAY
@ loss speech
	ec_word AWW
	ec_word I
	ec_word STUDY
	ec_word EVERY
	ec_word DAY
	ec_word TOO
	.4byte gFallarborBattleTentTrainerMons_Makenna

@ 14
	.4byte TRAINER_CLASS_COOLTRAINER_1
	.charmapstr "BRAYAN$", 8
@ pre-battle speech
	ec_word CAN
	ec_word YOU
	ec_word SEE
	ec_word MY
	ec_word POWER
	ec_word QUES
@ win speech
	ec_word HOW
	ec_word BORING
	ec_word ELLIPSIS
	ec_word THIS
	ec_word IS
	ec_word GOOD_BYE
@ loss speech
	ec_word AM
	ec_word I
	ec_word THE
	ec_word WEAK
	ec_word TRAINER
	ec_word QUES
	.4byte gFallarborBattleTentTrainerMons_Brayan

@ 15
	.4byte TRAINER_CLASS_COOLTRAINER_2
	.charmapstr "MARIANA$", 8
@ pre-battle speech
	ec_word A
	ec_word LIE
	ec_word CAN
	ec_word BE
	ec_word KIND
	ec_word ELLIPSIS
@ win speech
	ec_word THIS
	ec_word IS
	ec_word LIKE
	ec_word THE
	ec_word SUNDAY
	ec_word COMICS
@ loss speech
	ec_word THIS
	ec_word IS
	ec_word LIKE
	ec_word FROM
	ec_word A
	ec_word MOVIE
	.4byte gFallarborBattleTentTrainerMons_Mariana

@ 16
	.4byte TRAINER_CLASS_POKEFAN_1
	.charmapstr "SHELDON$", 8
@ pre-battle speech
	ec_word A
	ec_word POKEMON
	ec_word TEACHER
	ec_word GETS
	ec_word NO
	ec_move2 REST
@ win speech
	ec_word MY
	ec_word SMARTNESS
	ec_word GETS
	ec_word ME
	ec_word EASY
	ec_word WINS
@ loss speech
	ec_word I
	ec_word HAVE
	ec_word TO
	ec_word GO
	ec_word WORK
	ec_word BYE_BYE
	.4byte gFallarborBattleTentTrainerMons_Sheldon

@ 17
	.4byte TRAINER_CLASS_POKEFAN_2
	.charmapstr "GIANNA$", 8
@ pre-battle speech
	ec_word AHAHA
	ec_word YES
	ec_word EXCL
	ec_word LOVEY_DOVEY
	ec_word POKEMON
	ec_word WORLD
@ win speech
	ec_word MY
	ec_word SHINE
	ec_word IS
	ec_word MAKING
	ec_word THINGS
	ec_word BETTER
@ loss speech
	ec_word DO
	ec_word YOU
	ec_word DISLIKE
	ec_word POKEMON
	ec_word QUES
	.2byte -1
	.4byte gFallarborBattleTentTrainerMons_Gianna

@ 18
	.4byte TRAINER_CLASS_EXPERT_1
	.charmapstr "YAHIR$", 8
@ pre-battle speech
	ec_word YOU
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word ELLIPSIS_ELLIPSIS_ELLIPSIS
	ec_word COME_ON
	ec_word EXCL
@ win speech
	ec_word YOU
	ec_word NEED
	ec_word TO
	ec_word TRAIN
	ec_word A_LOT
	ec_word MORE
@ loss speech
	ec_word NOT
	ec_word ENOUGH
	ec_word ELLIPSIS
	ec_word JUST
	ec_word NOT
	ec_word ENOUGH
	.4byte gFallarborBattleTentTrainerMons_Yahir

@ 19
	.4byte TRAINER_CLASS_EXPERT_2
	.charmapstr "BRITNEY$", 8
@ pre-battle speech
	ec_word IT
	ec_word SEEMS
	ec_word THAT
	ec_word YOU_RE
	ec_word QUITE
	ec_word GOOD
@ win speech
	ec_word YOU_RE
	ec_word A
	ec_word LUKEWARM
	ec_word TALENT
	ec_word AT
	ec_word BEST
@ loss speech
	ec_word YOU_RE
	ec_word A
	ec_word COOL
	ec_word HERO
	ec_word AT
	ec_word THIS
	.4byte gFallarborBattleTentTrainerMons_Britney

@ 20
	.4byte TRAINER_CLASS_YOUNGSTER
	.charmapstr "HECTER$", 8
@ pre-battle speech
	ec_word MY
	ec_move2 HIDDEN_POWER
	ec_word IS
	ec_word EXCITING
	ec_word ME
	ec_word EXCL
@ win speech
	ec_word YEEHAW_EXCL
	ec_word LET_S
	ec_word HAVE
	ec_word A
	ec_move2 HIDDEN_POWER
	ec_word PARTY
@ loss speech
	ec_word WAAAH
	ec_word EXCL
	ec_word DON_T
	ec_word YOU
	ec_move2 MIMIC
	ec_word ME
	.4byte gFallarborBattleTentTrainerMons_Hecter

@ 21
	.4byte TRAINER_CLASS_FISHERMAN
	.charmapstr "TANNOR$", 8
@ pre-battle speech
	ec_word YOU
	ec_word HAVE
	ec_word GOT
	ec_word TO
	ec_word BE
	ec_word JOKING
@ win speech
	ec_word YOU_RE
	ec_word THE
	ec_word BEST
	ec_word AT
	ec_word BEING
	ec_word FUNNY
@ loss speech
	ec_word YOU
	ec_word WEREN_T
	ec_word BEING
	ec_word FUNNY
	ec_word AT
	ec_word ALL
	.4byte gFallarborBattleTentTrainerMons_Tannor

@ 22
	.4byte TRAINER_CLASS_BIRD_KEEPER
	.charmapstr "BENJI$", 8
@ pre-battle speech
	ec_word YOU
	ec_word DON_T
	ec_word THINK
	ec_word VERY
	ec_word FAST
	ec_word HUH_QUES
@ win speech
	ec_word SORRY
	ec_word EXCL
	ec_word I
	ec_word DIDN_T
	ec_word MEAN
	ec_word YOU
@ loss speech
	ec_word YOU
	ec_word LEFT
	ec_word ME
	ec_word FEELING
	ec_word SAD
	ec_word ELLIPSIS
	.4byte gFallarborBattleTentTrainerMons_Benji

@ 23
	.4byte TRAINER_CLASS_NINJA_BOY
	.charmapstr "RORY$", 8
@ pre-battle speech
	ec_word DON_T
	ec_word CAUSE
	ec_word AN
	ec_move1 UPROAR
	ec_word YOU
	ec_word EXCL
@ win speech
	ec_word I
	ec_word DON_T
	ec_word NEED
	ec_word AN
	ec_move1 UPROAR
	ec_word EXCL
@ loss speech
	ec_word I_AM
	ec_word GOING
	ec_word TO
	ec_word CAUSE
	ec_word AN
	ec_move1 UPROAR
	.4byte gFallarborBattleTentTrainerMons_Rory

@ 24
	.4byte TRAINER_CLASS_PARASOL_LADY
	.charmapstr "ELEANOR$", 8
@ pre-battle speech
	ec_word I
	ec_word REALLY
	ec_word WANT
	ec_word TO
	ec_word PARTY
	.2byte -1
@ win speech
	ec_word A
	ec_word TRENDY
	ec_word PARTY
	ec_word WOULD
	ec_word BE
	ec_word REFRESHING
@ loss speech
	ec_word DON_T
	ec_word YOU
	ec_word LIKE
	ec_word TO
	ec_word PARTY
	ec_word QUES
	.4byte gFallarborBattleTentTrainerMons_Eleanor

@ 25
	.4byte TRAINER_CLASS_SWIMMER_F
	.charmapstr "EVELYN$", 8
@ pre-battle speech
	ec_word MY
	ec_word PC
	ec_word IS
	ec_word MY
	ec_word SECRET_BASE
	ec_word EXCL
@ win speech
	ec_word IT_S
	ec_word ALL
	ec_word SECRET
	ec_word ON
	ec_word MY
	ec_word PC
@ loss speech
	ec_word NO
	ec_word EXCL
	.2byte -1
	ec_word I
	ec_word REJECT
	ec_word THIS
	.4byte gFallarborBattleTentTrainerMons_Evelyn

@ 26
	.4byte TRAINER_CLASS_PICNICKER
	.charmapstr "ARIELLE$", 8
@ pre-battle speech
	ec_word IT_S
	ec_word NOT_VERY
	ec_word PRETTY
	ec_word BUT
	ec_word I
	ec_word TRY
@ win speech
	ec_word WE_RE
	ec_word NOT_VERY
	ec_word PRETTY
	ec_word BUT
	ec_word WE_RE
	ec_word GREAT
@ loss speech
	ec_word THAT_WAS
	ec_word PRETTY
	ec_word MEAN
	ec_word OF
	ec_word YOU
	ec_word EXCL
	.4byte gFallarborBattleTentTrainerMons_Arielle

@ 27
	.4byte TRAINER_CLASS_SAILOR
	.charmapstr "CONNAR$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word NOT
	ec_word STRONG
	ec_word ENOUGH
	ec_word FOR
	ec_word THIS
@ win speech
	ec_word DO
	ec_word YOU
	ec_word THINK
	ec_word YOU_RE
	ec_word OK_QUES
	.2byte -1
@ loss speech
	ec_word GOOD_BYE
	ec_word AND
	ec_word THANK_YOU
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gFallarborBattleTentTrainerMons_Connar

@ 28
	.4byte TRAINER_CLASS_COLLECTOR
	.charmapstr "MAURICE$", 8
@ pre-battle speech
	ec_word THERE
	ec_word IS
	ec_word NO
	ec_word RADIO
	ec_word OR
	ec_word TELEVISION
@ win speech
	ec_word BUT
	ec_word THERE
	ec_word IS
	ec_word A_LOT
	ec_word OF
	ec_word POKEMON
@ loss speech
	ec_word I
	ec_word CAN_T
	ec_word ENJOY
	ec_word MYSELF
	ec_word WITHOUT
	ec_word MONEY
	.4byte gFallarborBattleTentTrainerMons_Maurice

@ 29
	.4byte TRAINER_CLASS_LASS
	.charmapstr "KIANNA$", 8
@ pre-battle speech
	ec_word I
	ec_word WANT
	ec_word TO
	ec_word GO
	ec_word DEPT_STORE
	ec_word SHOPPING
@ win speech
	ec_word I
	ec_word DISLIKE
	ec_word SHOPPING
	ec_word ALONE
	.2byte -1
	.2byte -1
@ loss speech
	ec_word WANT
	ec_word TO
	ec_word GO
	ec_word SHOPPING
	ec_word TOGETHER
	ec_word QUES
	.4byte gFallarborBattleTentTrainerMons_Kianna
