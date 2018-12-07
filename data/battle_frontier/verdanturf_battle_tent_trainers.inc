	.align 2
gVerdanturfBattleTentTrainers:: @ 85DE610
@ 0
	.4byte FACILITY_CLASS_AROMA_LADY
	.string "BRENNA$", 8
@ pre-battle speech
	.2byte EC_WORD_NO
	.2byte EC_WORD_DAYS
	.2byte EC_WORD_GO
	.2byte EC_WORD_WITHOUT
	.2byte EC_WORD_MY
	.2byte EC_MOVE(FAKE_TEARS)
@ win speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_SO
	.2byte EC_WORD_REFRESHING
	.2byte EC_WORD_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_ALL
	.2byte EC_WORD_I
	.2byte EC_WORD_EVER
	.2byte EC_WORD_GET
	.2byte EC_WORD_IS
	.2byte EC_MOVE(TORMENT)
	.4byte gVerdanturfBattleTentTrainerMons_Brenna

@ 1
	.4byte FACILITY_CLASS_RUIN_MANIAC
	.string "DILAN$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_HOW
	.2byte EC_WORD_BORED
	.2byte EC_WORD_I_AM
@ win speech
	.2byte EC_WORD_LOSING
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_EXCITING
	.2byte EC_WORD_AT
	.2byte EC_WORD_ALL
	.2byte EC_WORD_ELLIPSIS
@ loss speech
	.2byte EC_WORD_EXCITING
	.2byte EC_WORD_EXCL_EXCL
	.2byte EC_WORD_BYE_BYE
	.2byte EC_WORD_TO
	.2byte EC_WORD_BEING
	.2byte EC_WORD_BORED
	.4byte gVerdanturfBattleTentTrainerMons_Dilan

@ 2
	.4byte FACILITY_CLASS_TUBER_F
	.string "ELIANA$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_GOING
	.2byte EC_WORD_ON
	.2byte EC_WORD_A
	.2byte EC_WORD_VACATION
	.2byte EC_WORD_SOON
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_TO
	.2byte EC_WORD_GET
	.2byte EC_WORD_SOME
	.2byte EC_WORD_MONEY
@ loss speech
	.2byte EC_WORD_NO
	.2byte EC_WORD_SLEEP
	.2byte EC_WORD_UNTIL
	.2byte EC_WORD_I
	.2byte EC_WORD_GET
	.2byte EC_WORD_HOME
	.4byte gVerdanturfBattleTentTrainerMons_Eliana

@ 3
	.4byte FACILITY_CLASS_TUBER_M
	.string "MARKUS$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_SMART
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_IF_I_LOSE
	.2byte EC_WORD_I
	.2byte EC_MOVE(SELF_DESTRUCT)
@ win speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_A
	.2byte EC_WORD_NON_STOP
	.2byte EC_MOVE2(EXPLOSION)
	.2byte EC_WORD_OF
	.2byte EC_WORD_JOY
@ loss speech
	.2byte EC_WORD_I_VE
	.2byte EC_WORD_LOST
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_TIME
	.2byte EC_WORD_TO
	.2byte EC_MOVE(SELF_DESTRUCT)
	.4byte gVerdanturfBattleTentTrainerMons_Markus

@ 4
	.4byte FACILITY_CLASS_LADY
	.string "CAITLYN$", 8
@ pre-battle speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_BORED
	.2byte EC_WORD_OF
	.2byte EC_WORD_BEING
	.2byte EC_WORD_AN
	.2byte EC_WORD_IDOL
@ win speech
	.2byte EC_WORD_A
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_IS
	.2byte EC_WORD_BEST
	.2byte EC_WORD_FOR
	.2byte EC_WORD_HAPPINESS
@ loss speech
	.2byte EC_WORD_LOSING
	.2byte EC_WORD_DOESN_T
	.2byte EC_WORD_BUG
	.2byte EC_WORD_ME
	.2byte EC_WORD_AT
	.2byte EC_WORD_ALL
	.4byte gVerdanturfBattleTentTrainerMons_Caitlyn

@ 5
	.4byte FACILITY_CLASS_BEAUTY
	.string "DESIREE$", 8
@ pre-battle speech
	.2byte EC_WORD_DOESN_T
	.2byte EC_WORD_MY
	.2byte EC_WORD_BEAUTY
	.2byte EC_MOVE(ASTONISH)
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_DID
	.2byte EC_WORD_I
	.2byte EC_WORD_INTIMIDATE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_BEAUTY
	.2byte EC_WORD_DID
	.2byte EC_WORD_NOTHING
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOU
	.4byte gVerdanturfBattleTentTrainerMons_Desiree

@ 6
	.4byte FACILITY_CLASS_RICH_BOY
	.string "RONALD$", 8
@ pre-battle speech
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_SERIOUSLY
	.2byte -1
@ win speech
	.2byte EC_WORD_GIVE_UP
	.2byte EC_WORD_QUES
	.2byte -1
	.2byte EC_WORD_THAT_S
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_WEAK
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_TO
	.2byte EC_WORD_DO
	.2byte EC_WORD_A
	.2byte EC_MOVE2(BATON_PASS)
	.4byte gVerdanturfBattleTentTrainerMons_Ronald

@ 7
	.4byte FACILITY_CLASS_POKEMANIAC
	.string "ASHTEN$", 8
@ pre-battle speech
	.2byte EC_WORD_OH_YEAH
	.2byte EC_WORD_ANOTHER
	.2byte EC_WORD_EXCITING
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_EXCL
	.2byte -1
@ win speech
	.2byte EC_WORD_YOUR
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_ARE
	.2byte EC_WORD_WIMPY
	.2byte EC_WORD_AND
	.2byte EC_WORD_BORING
@ loss speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_AN
	.2byte EC_WORD_EXCITING
	.2byte EC_WORD_LOSS
	.2byte EC_WORD_WOW
	.2byte EC_WORD_EXCL
	.4byte gVerdanturfBattleTentTrainerMons_Ashten

@ 8
	.4byte FACILITY_CLASS_SWIMMER_M
	.string "GERARD$", 8
@ pre-battle speech
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_AT
	.2byte EC_WORD_MY
	.2byte EC_WORD_SUPER
	.2byte EC_MOVE2(TEETER_DANCE)
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_THAT_WAS
	.2byte EC_WORD_HARD
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_AM
	.2byte EC_WORD_I
	.2byte EC_WORD_OK_QUES
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WON_T
	.2byte EC_WORD_FORGIVE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_FOR
	.2byte EC_WORD_THAT
	.4byte gVerdanturfBattleTentTrainerMons_Gerard

@ 9
	.4byte FACILITY_CLASS_CAMPER
	.string "BRADLY$", 8
@ pre-battle speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_LONESOME
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I
	.2byte EC_WORD_VACATION
	.2byte EC_WORD_ALONE
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_MOVE(WITHDRAW)
	.2byte EC_WORD_INSIDE
	.2byte EC_WORD_MY
	.2byte EC_WORD_SHELL_ARMOR
@ loss speech
	.2byte EC_WORD_OH
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte EC_WORD_ALONE
	.2byte EC_WORD_AS
	.2byte EC_WORD_ALWAYS
	.4byte gVerdanturfBattleTentTrainerMons_Bradly

@ 10
	.4byte FACILITY_CLASS_BUG_MANIAC
	.string "DENNIS$", 8
@ pre-battle speech
	.2byte EC_WORD_ARE
	.2byte EC_WORD_YOU
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_STRONG
	.2byte EC_WORD_QUES
	.2byte -1
@ win speech
	.2byte EC_WORD_WAHAHAHA
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_WAHAHAHA
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
@ loss speech
	.2byte EC_WORD_NICE
	.2byte EC_WORD_GOING
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_I
	.2byte EC_WORD_WAS
	.2byte EC_WORD_CHILD_S_PLAY
	.4byte gVerdanturfBattleTentTrainerMons_Dennis

@ 11
	.4byte FACILITY_CLASS_GENTLEMAN
	.string "PRESTIN$", 8
@ pre-battle speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_A
	.2byte EC_MOVE(NIGHTMARE)
	.2byte EC_WORD_FOR
	.2byte EC_WORD_YOU
@ win speech
	.2byte EC_WORD_FORGIVE
	.2byte EC_WORD_ME
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_A
	.2byte EC_WORD_DREAM
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_TO
	.2byte EC_WORD_WAKE_UP
	.2byte EC_WORD_FROM
	.2byte EC_WORD_THIS
	.4byte gVerdanturfBattleTentTrainerMons_Prestin

@ 12
	.4byte FACILITY_CLASS_GUITARIST
	.string "ERNESTO$", 8
@ pre-battle speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_PARTY
	.2byte EC_WORD_GOES
	.2byte EC_WORD_ON
	.2byte EC_WORD_FOREVER
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_THE
	.2byte EC_WORD_MUSIC
	.2byte EC_WORD_PLAYS
	.2byte EC_WORD_ON
	.2byte EC_WORD_WITHOUT
	.2byte EC_WORD_END
@ loss speech
	.2byte EC_WORD_NO
	.2byte EC_WORD_EXCL
	.2byte EC_WORD_THE
	.2byte EC_WORD_MUSIC
	.2byte EC_WORD_CAN_T
	.2byte EC_WORD_STOP
	.4byte gVerdanturfBattleTentTrainerMons_Ernesto

@ 13
	.4byte FACILITY_CLASS_SCHOOL_KID_F
	.string "NALA$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WANT
	.2byte EC_WORD_THE
	.2byte EC_WORD_WORLD
	.2byte EC_WORD_MOVIE
	.2byte EC_WORD_COLLECTION
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_RADIO
	.2byte EC_WORD_VERY
	.2byte EC_WORD_MUCH
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_REFUSE
	.2byte EC_WORD_TO
	.2byte EC_WORD_BELIEVE
	.2byte EC_WORD_THIS
	.2byte EC_WORD_EXCL
	.4byte gVerdanturfBattleTentTrainerMons_Nala

@ 14
	.4byte FACILITY_CLASS_COOLTRAINER_M
	.string "DARNELL$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WILL
	.2byte EC_WORD_GO_EASY
	.2byte EC_WORD_ON
	.2byte EC_WORD_YOU
	.2byte -1
@ win speech
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE2(FRUSTRATION)
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_BE
	.2byte EC_WORD_HIDDEN
	.2byte EC_WORD_AWAY
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_TOO
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_TO
	.2byte EC_WORD_TAKE
	.2byte EC_WORD_ELLIPSIS
	.4byte gVerdanturfBattleTentTrainerMons_Darnell

@ 15
	.4byte FACILITY_CLASS_COOLTRAINER_F
	.string "ASHLYN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_LOOK
	.2byte EC_WORD_TOUGH
	.2byte EC_WORD_DO
	.2byte EC_WORD_I
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_NOT
	.2byte EC_WORD_OVER
	.2byte EC_WORD_YOUR
	.2byte EC_MOVE2(TAUNT)
	.2byte EC_WORD_YET
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gVerdanturfBattleTentTrainerMons_Ashlyn

@ 16
	.4byte FACILITY_CLASS_POKEFAN_M
	.string "ADDISON$", 8
@ pre-battle speech
	.2byte EC_WORD_YES
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_MY
	.2byte EC_WORD_POKEMON
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_WELL
	.2byte EC_WORD_WASN_T
	.2byte EC_WORD_THAT
	.2byte EC_WORD_EASY
	.2byte EC_WORD_QUES
	.2byte -1
@ loss speech
	.2byte EC_WORD_WAAAH
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_BUT
	.2byte EC_WORD_WHY
	.2byte EC_WORD_QUES
	.4byte gVerdanturfBattleTentTrainerMons_Addison

@ 17
	.4byte FACILITY_CLASS_POKEFAN_F
	.string "JUSTINE$", 8
@ pre-battle speech
	.2byte EC_WORD_YES
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_I_AM
	.2byte EC_WORD_READY
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_JUST
	.2byte EC_WORD_NOT
	.2byte EC_WORD_GOOD
	.2byte EC_WORD_ENOUGH
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_WOWEE
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte -1
	.2byte -1
	.2byte -1
	.4byte gVerdanturfBattleTentTrainerMons_Justine

@ 18
	.4byte FACILITY_CLASS_EXPERT_M
	.string "TYSON$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_GOING
	.2byte EC_WORD_TO
	.2byte EC_WORD_PRESSURE
	.2byte EC_WORD_ME
	.2byte EC_WORD_QUES
@ win speech
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_QUES
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_MUCH
	.2byte EC_WORD_TOO_WEAK
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_DOESN_T
	.2byte EC_WORD_MAKE
	.2byte EC_WORD_ME
	.2byte EC_WORD_HAPPY
	.2byte EC_WORD_EXCL
	.4byte gVerdanturfBattleTentTrainerMons_Tyson

@ 19
	.4byte FACILITY_CLASS_EXPERT_F
	.string "LAILA$", 8
@ pre-battle speech
	.2byte EC_WORD_A
	.2byte EC_MOVE2(STRUGGLE)
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_VERY
	.2byte EC_WORD_COOL
	.2byte -1
@ win speech
	.2byte EC_WORD_NOPE
	.2byte EC_WORD_NOT_VERY
	.2byte EC_WORD_COOL
	.2byte EC_WORD_AT
	.2byte EC_WORD_ALL
	.2byte EC_WORD_EXCL
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_NOT
	.2byte EC_WORD_COOL
	.2byte EC_WORD_BUT
	.2byte EC_WORD_YOU
	.2byte EC_WORD_WON
	.4byte gVerdanturfBattleTentTrainerMons_Laila

@ 20
	.4byte FACILITY_CLASS_YOUNGSTER
	.string "WAREN$", 8
@ pre-battle speech
	.2byte EC_WORD_DANGER
	.2byte EC_WORD_EXCL
	.2byte -1
	.2byte EC_WORD_I
	.2byte EC_WORD_SENSE
	.2byte EC_WORD_DANGER
@ win speech
	.2byte EC_WORD_DID
	.2byte EC_WORD_YOU
	.2byte EC_WORD_BELIEVE
	.2byte EC_WORD_MY
	.2byte EC_WORD_LIE
	.2byte EC_WORD_QUES_EXCL
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_REALLY
	.2byte EC_WORD_DID
	.2byte EC_WORD_SENSE
	.2byte EC_WORD_DANGER
	.2byte EC_WORD_ELLIPSIS
	.4byte gVerdanturfBattleTentTrainerMons_Waren

@ 21
	.4byte FACILITY_CLASS_FISHERMAN
	.string "TOBIAS$", 8
@ pre-battle speech
	.2byte EC_MOVE2(BARRIER)
	.2byte EC_WORD_EXCL_EXCL
	.2byte -1
	.2byte EC_WORD_NOW
	.2byte EC_WORD_COME_ON
	.2byte EC_WORD_EXCL
@ win speech
	.2byte EC_WORD_HUH_QUES
	.2byte EC_WORD_YOU
	.2byte EC_WORD_MEAN
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_KNOW
	.2byte EC_WORD_THAT
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_HOPELESS
	.4byte gVerdanturfBattleTentTrainerMons_Tobias

@ 22
	.4byte FACILITY_CLASS_BIRD_KEEPER
	.string "JOSIAH$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_PROMISE
	.2byte EC_WORD_TO
	.2byte EC_MOVE(FLY)
	.2byte EC_WORD_IF_I_LOSE
	.2byte -1
@ win speech
	.2byte EC_WORD_TOO_WEAK
	.2byte EC_WORD_ELLIPSIS
	.2byte -1
	.2byte EC_WORD_YOU
	.2byte EC_MOVE(FLY)
	.2byte EC_WORD_INSTEAD
@ loss speech
	.2byte EC_WORD_I
	.2byte EC_WORD_PROMISE
	.2byte EC_WORD_TO
	.2byte EC_MOVE(FLY)
	.2byte EC_WORD_SOMETIME
	.2byte EC_WORD_SOON
	.4byte gVerdanturfBattleTentTrainerMons_Josiah

@ 23
	.4byte FACILITY_CLASS_NINJA_BOY
	.string "DION$", 8
@ pre-battle speech
	.2byte EC_WORD_IT_S
	.2byte EC_WORD_TRENDY
	.2byte EC_WORD_UM
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_SOMETHING
	.2byte -1
@ win speech
	.2byte EC_WORD_WAS
	.2byte EC_WORD_IT
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_DATE
	.2byte EC_WORD_QUES
@ loss speech
	.2byte EC_WORD_WAS
	.2byte EC_WORD_IT
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_BATTLE
	.2byte EC_WORD_GOURMET
	.2byte EC_WORD_QUES
	.4byte gVerdanturfBattleTentTrainerMons_Dion

@ 24
	.4byte FACILITY_CLASS_PARASOL_LADY
	.string "KENZIE$", 8
@ pre-battle speech
	.2byte EC_WORD_THE
	.2byte EC_MOVE(MORNING_SUN)
	.2byte EC_WORD_GIVES
	.2byte EC_WORD_ME
	.2byte EC_MOVE(STRENGTH)
	.2byte -1
@ win speech
	.2byte EC_WORD_BUT
	.2byte EC_WORD_I
	.2byte EC_WORD_LIKE
	.2byte EC_MOVE2(MOONLIGHT)
	.2byte EC_WORD_TOO
	.2byte -1
@ loss speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_LIKE
	.2byte EC_WORD_A
	.2byte EC_WORD_TERRIBLE
	.2byte EC_MOVE(SANDSTORM)
	.2byte EC_WORD_ELLIPSIS
	.4byte gVerdanturfBattleTentTrainerMons_Kenzie

@ 25
	.4byte FACILITY_CLASS_SWIMMER_F
	.string "LILLIAN$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_DO
	.2byte EC_WORD_THINGS
	.2byte EC_WORD_AT
	.2byte EC_WORD_MY
	.2byte EC_WORD_OWN_TEMPO
@ win speech
	.2byte EC_WORD_I
	.2byte EC_WORD_WON
	.2byte EC_WORD_QUES
	.2byte EC_WORD_WHAT
	.2byte EC_WORD_A
	.2byte EC_WORD_SURPRISE
@ loss speech
	.2byte EC_WORD_AWW
	.2byte EC_WORD_ELLIPSIS
	.2byte EC_WORD_I
	.2byte EC_WORD_NEED
	.2byte EC_WORD_A
	.2byte EC_WORD_NAP
	.4byte gVerdanturfBattleTentTrainerMons_Lillian

@ 26
	.4byte FACILITY_CLASS_PICNICKER
	.string "LESLEY$", 8
@ pre-battle speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_NOT
	.2byte EC_WORD_BE
	.2byte EC_WORD_LOLLING
	.2byte EC_WORD_ABOUT
@ win speech
	.2byte EC_WORD_YOU
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_GET
	.2byte EC_WORD_UP
	.2byte EC_WORD_EARLIER
	.2byte -1
@ loss speech
	.2byte EC_WORD_THIS
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_NOT
	.2byte EC_WORD_BE
	.2byte EC_WORD_HAPPENING
	.2byte EC_WORD_EXCL
	.4byte gVerdanturfBattleTentTrainerMons_Lesley

@ 27
	.4byte FACILITY_CLASS_SAILOR
	.string "MARQUIS$", 8
@ pre-battle speech
	.2byte EC_WORD_NONE
	.2byte EC_WORD_OF
	.2byte EC_WORD_THIS
	.2byte EC_WORD_IS
	.2byte EC_WORD_MAKING
	.2byte EC_WORD_SENSE
@ win speech
	.2byte EC_WORD_SEE
	.2byte EC_WORD_QUES
	.2byte EC_WORD_THIS
	.2byte EC_WORD_JUST
	.2byte EC_WORD_ISN_T
	.2byte EC_WORD_NORMAL
@ loss speech
	.2byte EC_WORD_SHOULD
	.2byte EC_WORD_I
	.2byte EC_WORD_CAUSE
	.2byte EC_WORD_AN
	.2byte EC_MOVE(UPROAR)
	.2byte EC_WORD_QUES
	.4byte gVerdanturfBattleTentTrainerMons_Marquis

@ 28
	.4byte FACILITY_CLASS_COLLECTOR
	.string "FREDDY$", 8
@ pre-battle speech
	.2byte EC_WORD_I
	.2byte EC_WORD_ADORE
	.2byte EC_WORD_THIS
	.2byte EC_WORD_CUTE
	.2byte EC_WORD_TELEVISION
	.2byte EC_WORD_IDOL
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_SO
	.2byte EC_WORD_FUNNY
	.2byte EC_WORD_WHEN
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_ANGRY
@ loss speech
	.2byte EC_WORD_LATE
	.2byte EC_WORD_NIGHT
	.2byte EC_WORD_TELEVISION
	.2byte EC_WORD_IS
	.2byte EC_WORD_MY
	.2byte EC_WORD_LIFE
	.4byte gVerdanturfBattleTentTrainerMons_Freddy

@ 29
	.4byte FACILITY_CLASS_LASS
	.string "CECILIA$", 8
@ pre-battle speech
	.2byte EC_WORD_MY
	.2byte EC_WORD_FABULOUS
	.2byte EC_WORD_CUTENESS
	.2byte EC_WORD_IS
	.2byte EC_WORD_IN
	.2byte EC_WORD_FASHION
@ win speech
	.2byte EC_WORD_YOU_RE
	.2byte EC_WORD_NO
	.2byte EC_WORD_MATCH
	.2byte EC_WORD_FOR
	.2byte EC_WORD_MY
	.2byte EC_WORD_CUTE_CHARM
@ loss speech
	.2byte EC_WORD_DON_T
	.2byte EC_WORD_YOU
	.2byte EC_WORD_HAVE
	.2byte EC_WORD_FASHION
	.2byte EC_WORD_SENSE
	.2byte EC_WORD_QUES
	.4byte gVerdanturfBattleTentTrainerMons_Cecilia
