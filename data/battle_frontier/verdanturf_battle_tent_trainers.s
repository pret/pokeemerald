	.align 2, 0

gVerdanturfBattleTentTrainers: @ 85DE610
@ 0
	.4byte TRAINER_CLASS_AROMA_LADY
	.string "BRENNA$", 8
@ pre-battle speech
	ec_word NO
	ec_word DAYS
	ec_word GO
	ec_word WITHOUT
	ec_word MY
	ec_move1 FAKE_TEARS
@ win speech
	ec_word OH
	ec_word THAT_WAS
	ec_word SO
	ec_word REFRESHING
	ec_word EXCL
	.2byte -1
@ loss speech
	ec_word ALL
	ec_word I
	ec_word EVER
	ec_word GET
	ec_word IS
	ec_move1 TORMENT
	.4byte gVerdanturfBattleTentTrainerMons_Brenna

@ 1
	.4byte TRAINER_CLASS_RUIN_MANIAC
	.string "DILAN$", 8
@ pre-battle speech
	ec_word YOU
	ec_word DON_T
	ec_word KNOW
	ec_word HOW
	ec_word BORED
	ec_word I_AM
@ win speech
	ec_word LOSING
	ec_word ISN_T
	ec_word EXCITING
	ec_word AT
	ec_word ALL
	ec_word ELLIPSIS
@ loss speech
	ec_word EXCITING
	ec_word EXCL_EXCL
	ec_word BYE_BYE
	ec_word TO
	ec_word BEING
	ec_word BORED
	.4byte gVerdanturfBattleTentTrainerMons_Dilan

@ 2
	.4byte TRAINER_CLASS_TUBER_1
	.string "ELIANA$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word GOING
	ec_word ON
	ec_word A
	ec_word VACATION
	ec_word SOON
@ win speech
	ec_word I
	ec_word NEED
	ec_word TO
	ec_word GET
	ec_word SOME
	ec_word MONEY
@ loss speech
	ec_word NO
	ec_word SLEEP
	ec_word UNTIL
	ec_word I
	ec_word GET
	ec_word HOME
	.4byte gVerdanturfBattleTentTrainerMons_Eliana

@ 3
	.4byte TRAINER_CLASS_TUBER_2
	.string "MARKUS$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word SMART
	ec_word EXCL
	ec_word IF_I_LOSE
	ec_word I
	ec_move1 SELF_DESTRUCT
@ win speech
	ec_word IT_S
	ec_word A
	ec_word NON_STOP
	ec_move2 EXPLOSION
	ec_word OF
	ec_word JOY
@ loss speech
	ec_word I_VE
	ec_word LOST
	ec_word ELLIPSIS
	ec_word TIME
	ec_word TO
	ec_move1 SELF_DESTRUCT
	.4byte gVerdanturfBattleTentTrainerMons_Markus

@ 4
	.4byte TRAINER_CLASS_LADY
	.string "CAITLYN$", 8
@ pre-battle speech
	ec_word I_AM
	ec_word BORED
	ec_word OF
	ec_word BEING
	ec_word AN
	ec_word IDOL
@ win speech
	ec_word A
	ec_word BATTLE
	ec_word IS
	ec_word BEST
	ec_word FOR
	ec_word HAPPINESS
@ loss speech
	ec_word LOSING
	ec_word DOESN_T
	ec_word BUG
	ec_word ME
	ec_word AT
	ec_word ALL
	.4byte gVerdanturfBattleTentTrainerMons_Caitlyn

@ 5
	.4byte TRAINER_CLASS_BEAUTY
	.string "DESIREE$", 8
@ pre-battle speech
	ec_word DOESN_T
	ec_word MY
	ec_word BEAUTY
	ec_move1 ASTONISH
	ec_word YOU
	ec_word QUES
@ win speech
	ec_word DID
	ec_word I
	ec_word INTIMIDATE
	ec_word YOU
	ec_word QUES
	.2byte -1
@ loss speech
	ec_word MY
	ec_word BEAUTY
	ec_word DID
	ec_word NOTHING
	ec_word FOR
	ec_word YOU
	.4byte gVerdanturfBattleTentTrainerMons_Desiree

@ 6
	.4byte TRAINER_CLASS_RICH_BOY
	.string "RONALD$", 8
@ pre-battle speech
	ec_word COME_ON
	ec_word I
	ec_word WILL
	ec_word BATTLE
	ec_word SERIOUSLY
	.2byte -1
@ win speech
	ec_word GIVE_UP
	ec_word QUES
	.2byte -1
	ec_word THAT_S
	ec_word REALLY
	ec_word WEAK
@ loss speech
	ec_word I
	ec_word NEED
	ec_word TO
	ec_word DO
	ec_word A
	ec_move2 BATON_PASS
	.4byte gVerdanturfBattleTentTrainerMons_Ronald

@ 7
	.4byte TRAINER_CLASS_POKEMANIAC
	.string "ASHTEN$", 8
@ pre-battle speech
	ec_word OH_YEAH
	ec_word ANOTHER
	ec_word EXCITING
	ec_word BATTLE
	ec_word EXCL
	.2byte -1
@ win speech
	ec_word YOUR
	ec_word POKEMON
	ec_word ARE
	ec_word WIMPY
	ec_word AND
	ec_word BORING
@ loss speech
	ec_word THAT_WAS
	ec_word AN
	ec_word EXCITING
	ec_word LOSS
	ec_word WOW
	ec_word EXCL
	.4byte gVerdanturfBattleTentTrainerMons_Ashten

@ 8
	.4byte TRAINER_CLASS_SWIMMER_M
	.string "GERARD$", 8
@ pre-battle speech
	ec_word LOOK
	ec_word AT
	ec_word MY
	ec_word SUPER
	ec_move2 TEETER_DANCE
	ec_word EXCL
@ win speech
	ec_word THAT_WAS
	ec_word HARD
	ec_word ELLIPSIS
	ec_word AM
	ec_word I
	ec_word OK_QUES
@ loss speech
	ec_word I
	ec_word WON_T
	ec_word FORGIVE
	ec_word YOU
	ec_word FOR
	ec_word THAT
	.4byte gVerdanturfBattleTentTrainerMons_Gerard

@ 9
	.4byte TRAINER_CLASS_CAMPER
	.string "BRADLY$", 8
@ pre-battle speech
	ec_word IT_S
	ec_word LONESOME
	ec_word BUT
	ec_word I
	ec_word VACATION
	ec_word ALONE
@ win speech
	ec_word I
	ec_word WILL
	ec_move1 WITHDRAW
	ec_word INSIDE
	ec_word MY
	ec_word SHELL_ARMOR
@ loss speech
	ec_word OH
	ec_word ELLIPSIS
	.2byte -1
	ec_word ALONE
	ec_word AS
	ec_word ALWAYS
	.4byte gVerdanturfBattleTentTrainerMons_Bradly

@ 10
	.4byte TRAINER_CLASS_BUG_MANIAC
	.string "DENNIS$", 8
@ pre-battle speech
	ec_word ARE
	ec_word YOU
	ec_word REALLY
	ec_word STRONG
	ec_word QUES
	.2byte -1
@ win speech
	ec_word WAHAHAHA
	ec_word EXCL
	.2byte -1
	ec_word WAHAHAHA
	ec_word EXCL_EXCL
	.2byte -1
@ loss speech
	ec_word NICE
	ec_word GOING
	ec_word EXCL
	ec_word I
	ec_word WAS
	ec_word CHILD_S_PLAY
	.4byte gVerdanturfBattleTentTrainerMons_Dennis

@ 11
	.4byte TRAINER_CLASS_GENTLEMAN
	.string "PRESTIN$", 8
@ pre-battle speech
	ec_word THIS
	ec_word IS
	ec_word A
	ec_move1 NIGHTMARE
	ec_word FOR
	ec_word YOU
@ win speech
	ec_word FORGIVE
	ec_word ME
	ec_word ELLIPSIS
	ec_word IT_S
	ec_word A
	ec_word DREAM
@ loss speech
	ec_word I
	ec_word WANT
	ec_word TO
	ec_word WAKE_UP
	ec_word FROM
	ec_word THIS
	.4byte gVerdanturfBattleTentTrainerMons_Prestin

@ 12
	.4byte TRAINER_CLASS_GUITARIST
	.string "ERNESTO$", 8
@ pre-battle speech
	ec_word THIS
	ec_word PARTY
	ec_word GOES
	ec_word ON
	ec_word FOREVER
	ec_word EXCL
@ win speech
	ec_word THE
	ec_word MUSIC
	ec_word PLAYS
	ec_word ON
	ec_word WITHOUT
	ec_word END
@ loss speech
	ec_word NO
	ec_word EXCL
	ec_word THE
	ec_word MUSIC
	ec_word CAN_T
	ec_word STOP
	.4byte gVerdanturfBattleTentTrainerMons_Ernesto

@ 13
	.4byte TRAINER_CLASS_SCHOOL_KID_2
	.string "NALA$", 8
@ pre-battle speech
	ec_word I
	ec_word WANT
	ec_word THE
	ec_word WORLD
	ec_word MOVIE
	ec_word COLLECTION
@ win speech
	ec_word I
	ec_word DON_T
	ec_word LIKE
	ec_word RADIO
	ec_word VERY
	ec_word MUCH
@ loss speech
	ec_word I
	ec_word REFUSE
	ec_word TO
	ec_word BELIEVE
	ec_word THIS
	ec_word EXCL
	.4byte gVerdanturfBattleTentTrainerMons_Nala

@ 14
	.4byte TRAINER_CLASS_COOLTRAINER_1
	.string "DARNELL$", 8
@ pre-battle speech
	ec_word I
	ec_word WILL
	ec_word GO_EASY
	ec_word ON
	ec_word YOU
	.2byte -1
@ win speech
	ec_word YOUR
	ec_move2 FRUSTRATION
	ec_word SHOULD
	ec_word BE
	ec_word HIDDEN
	ec_word AWAY
@ loss speech
	ec_word YOU_RE
	ec_word TOO
	ec_word MUCH
	ec_word TO
	ec_word TAKE
	ec_word ELLIPSIS
	.4byte gVerdanturfBattleTentTrainerMons_Darnell

@ 15
	.4byte TRAINER_CLASS_COOLTRAINER_2
	.string "ASHLYN$", 8
@ pre-battle speech
	ec_word I
	ec_word LOOK
	ec_word TOUGH
	ec_word DO
	ec_word I
	ec_word QUES
@ win speech
	ec_word I_AM
	ec_word NOT
	ec_word OVER
	ec_word YOUR
	ec_move2 TAUNT
	ec_word YET
@ loss speech
	ec_word YOU_RE
	ec_word MEAN
	ec_word EXCL_EXCL
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gVerdanturfBattleTentTrainerMons_Ashlyn

@ 16
	.4byte TRAINER_CLASS_POKEFAN_1
	.string "ADDISON$", 8
@ pre-battle speech
	ec_word YES
	ec_word EXCL
	.2byte -1
	ec_word MY
	ec_word POKEMON
	ec_word EXCL
@ win speech
	ec_word WELL
	ec_word WASN_T
	ec_word THAT
	ec_word EASY
	ec_word QUES
	.2byte -1
@ loss speech
	ec_word WAAAH
	ec_word EXCL
	.2byte -1
	ec_word BUT
	ec_word WHY
	ec_word QUES
	.4byte gVerdanturfBattleTentTrainerMons_Addison

@ 17
	.4byte TRAINER_CLASS_POKEFAN_2
	.string "JUSTINE$", 8
@ pre-battle speech
	ec_word YES
	ec_word EXCL
	.2byte -1
	ec_word COME_ON
	ec_word I_AM
	ec_word READY
@ win speech
	ec_word YOU_RE
	ec_word JUST
	ec_word NOT
	ec_word GOOD
	ec_word ENOUGH
	ec_word EXCL
@ loss speech
	ec_word WOWEE
	ec_word EXCL_EXCL
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gVerdanturfBattleTentTrainerMons_Justine

@ 18
	.4byte TRAINER_CLASS_EXPERT_1
	.string "TYSON$", 8
@ pre-battle speech
	ec_word YOU_RE
	ec_word GOING
	ec_word TO
	ec_word PRESSURE
	ec_word ME
	ec_word QUES
@ win speech
	ec_word WHAT
	ec_word QUES
	ec_word YOU_RE
	ec_word MUCH
	ec_word TOO_WEAK
	ec_word EXCL
@ loss speech
	ec_word THIS
	ec_word DOESN_T
	ec_word MAKE
	ec_word ME
	ec_word HAPPY
	ec_word EXCL
	.4byte gVerdanturfBattleTentTrainerMons_Tyson

@ 19
	.4byte TRAINER_CLASS_EXPERT_2
	.string "LAILA$", 8
@ pre-battle speech
	ec_word A
	ec_move2 STRUGGLE
	ec_word ISN_T
	ec_word VERY
	ec_word COOL
	.2byte -1
@ win speech
	ec_word NOPE
	ec_word NOT_VERY
	ec_word COOL
	ec_word AT
	ec_word ALL
	ec_word EXCL
@ loss speech
	ec_word YOU_RE
	ec_word NOT
	ec_word COOL
	ec_word BUT
	ec_word YOU
	ec_word WON
	.4byte gVerdanturfBattleTentTrainerMons_Laila

@ 20
	.4byte TRAINER_CLASS_YOUNGSTER
	.string "WAREN$", 8
@ pre-battle speech
	ec_word DANGER
	ec_word EXCL
	.2byte -1
	ec_word I
	ec_word SENSE
	ec_word DANGER
@ win speech
	ec_word DID
	ec_word YOU
	ec_word BELIEVE
	ec_word MY
	ec_word LIE
	ec_word QUES_EXCL
@ loss speech
	ec_word I
	ec_word REALLY
	ec_word DID
	ec_word SENSE
	ec_word DANGER
	ec_word ELLIPSIS
	.4byte gVerdanturfBattleTentTrainerMons_Waren

@ 21
	.4byte TRAINER_CLASS_FISHERMAN
	.string "TOBIAS$", 8
@ pre-battle speech
	ec_move2 BARRIER
	ec_word EXCL_EXCL
	.2byte -1
	ec_word NOW
	ec_word COME_ON
	ec_word EXCL
@ win speech
	ec_word HUH_QUES
	ec_word YOU
	ec_word MEAN
	ec_word I
	ec_word WON
	ec_word QUES
@ loss speech
	ec_word I
	ec_word SHOULD
	ec_word KNOW
	ec_word THAT
	ec_word IT_S
	ec_word HOPELESS
	.4byte gVerdanturfBattleTentTrainerMons_Tobias

@ 22
	.4byte TRAINER_CLASS_BIRD_KEEPER
	.string "JOSIAH$", 8
@ pre-battle speech
	ec_word I
	ec_word PROMISE
	ec_word TO
	ec_move1 FLY
	ec_word IF_I_LOSE
	.2byte -1
@ win speech
	ec_word TOO_WEAK
	ec_word ELLIPSIS
	.2byte -1
	ec_word YOU
	ec_move1 FLY
	ec_word INSTEAD
@ loss speech
	ec_word I
	ec_word PROMISE
	ec_word TO
	ec_move1 FLY
	ec_word SOMETIME
	ec_word SOON
	.4byte gVerdanturfBattleTentTrainerMons_Josiah

@ 23
	.4byte TRAINER_CLASS_NINJA_BOY
	.string "DION$", 8
@ pre-battle speech
	ec_word IT_S
	ec_word TRENDY
	ec_word UM
	ec_word BATTLE
	ec_word SOMETHING
	.2byte -1
@ win speech
	ec_word WAS
	ec_word IT
	ec_word ELLIPSIS
	ec_word BATTLE
	ec_word DATE
	ec_word QUES
@ loss speech
	ec_word WAS
	ec_word IT
	ec_word ELLIPSIS
	ec_word BATTLE
	ec_word GOURMET
	ec_word QUES
	.4byte gVerdanturfBattleTentTrainerMons_Dion

@ 24
	.4byte TRAINER_CLASS_PARASOL_LADY
	.string "KENZIE$", 8
@ pre-battle speech
	ec_word THE
	ec_move1 MORNING_SUN
	ec_word GIVES
	ec_word ME
	ec_move1 STRENGTH
	.2byte -1
@ win speech
	ec_word BUT
	ec_word I
	ec_word LIKE
	ec_move2 MOONLIGHT
	ec_word TOO
	.2byte -1
@ loss speech
	ec_word YOU_RE
	ec_word LIKE
	ec_word A
	ec_word TERRIBLE
	ec_move1 SANDSTORM
	ec_word ELLIPSIS
	.4byte gVerdanturfBattleTentTrainerMons_Kenzie

@ 25
	.4byte TRAINER_CLASS_SWIMMER_F
	.string "LILLIAN$", 8
@ pre-battle speech
	ec_word I
	ec_word DO
	ec_word THINGS
	ec_word AT
	ec_word MY
	ec_word OWN_TEMPO
@ win speech
	ec_word I
	ec_word WON
	ec_word QUES
	ec_word WHAT
	ec_word A
	ec_word SURPRISE
@ loss speech
	ec_word AWW
	ec_word ELLIPSIS
	ec_word I
	ec_word NEED
	ec_word A
	ec_word NAP
	.4byte gVerdanturfBattleTentTrainerMons_Lillian

@ 26
	.4byte TRAINER_CLASS_PICNICKER
	.string "LESLEY$", 8
@ pre-battle speech
	ec_word YOU
	ec_word SHOULD
	ec_word NOT
	ec_word BE
	ec_word LOLLING
	ec_word ABOUT
@ win speech
	ec_word YOU
	ec_word SHOULD
	ec_word GET
	ec_word UP
	ec_word EARLIER
	.2byte -1
@ loss speech
	ec_word THIS
	ec_word SHOULD
	ec_word NOT
	ec_word BE
	ec_word HAPPENING
	ec_word EXCL
	.4byte gVerdanturfBattleTentTrainerMons_Lesley

@ 27
	.4byte TRAINER_CLASS_SAILOR
	.string "MARQUIS$", 8
@ pre-battle speech
	ec_word NONE
	ec_word OF
	ec_word THIS
	ec_word IS
	ec_word MAKING
	ec_word SENSE
@ win speech
	ec_word SEE
	ec_word QUES
	ec_word THIS
	ec_word JUST
	ec_word ISN_T
	ec_word NORMAL
@ loss speech
	ec_word SHOULD
	ec_word I
	ec_word CAUSE
	ec_word AN
	ec_move1 UPROAR
	ec_word QUES
	.4byte gVerdanturfBattleTentTrainerMons_Marquis

@ 28
	.4byte TRAINER_CLASS_COLLECTOR
	.string "FREDDY$", 8
@ pre-battle speech
	ec_word I
	ec_word ADORE
	ec_word THIS
	ec_word CUTE
	ec_word TELEVISION
	ec_word IDOL
@ win speech
	ec_word YOU_RE
	ec_word SO
	ec_word FUNNY
	ec_word WHEN
	ec_word YOU_RE
	ec_word ANGRY
@ loss speech
	ec_word LATE
	ec_word NIGHT
	ec_word TELEVISION
	ec_word IS
	ec_word MY
	ec_word LIFE
	.4byte gVerdanturfBattleTentTrainerMons_Freddy

@ 29
	.4byte TRAINER_CLASS_LASS
	.string "CECILIA$", 8
@ pre-battle speech
	ec_word MY
	ec_word FABULOUS
	ec_word CUTENESS
	ec_word IS
	ec_word IN
	ec_word FASHION
@ win speech
	ec_word YOU_RE
	ec_word NO
	ec_word MATCH
	ec_word FOR
	ec_word MY
	ec_word CUTE_CHARM
@ loss speech
	ec_word DON_T
	ec_word YOU
	ec_word HAVE
	ec_word FASHION
	ec_word SENSE
	ec_word QUES
	.4byte gVerdanturfBattleTentTrainerMons_Cecilia
