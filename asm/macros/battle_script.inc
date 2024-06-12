@ commands
	.macro attackcanceler
	.byte 0x0
	.endm

	.macro accuracycheck failInstr:req, move:req
	.byte 0x1
	.4byte \failInstr
	.2byte \move
	.endm

	.macro attackstring
	.byte 0x2
	.endm

	.macro ppreduce
	.byte 0x3
	.endm

	.macro critcalc
	.byte 0x4
	.endm

	.macro damagecalc
	.byte 0x5
	.endm

	.macro typecalc
	.byte 0x6
	.endm

	.macro adjustdamage
	.byte 0x7
	.endm

	.macro multihitresultmessage
	.byte 0x8
	.endm

	.macro attackanimation
	.byte 0x9
	.endm

	.macro waitanimation
	.byte 0xa
	.endm

	.macro healthbarupdate battler:req
	.byte 0xb
	.byte \battler
	.endm

	.macro datahpupdate battler:req
	.byte 0xc
	.byte \battler
	.endm

	.macro critmessage
	.byte 0xd
	.endm

	.macro effectivenesssound
	.byte 0xe
	.endm

	.macro resultmessage
	.byte 0xf
	.endm

	.macro printstring id:req
	.byte 0x10
	.2byte \id
	.endm

	.macro printsavedstring
	printstring 0
	.endm

	.macro printselectionstring id:req
	.byte 0x11
	.2byte \id
	.endm

	.macro waitmessage time:req
	.byte 0x12
	.2byte \time
	.endm

	.macro printfromtable ptr:req
	.byte 0x13
	.4byte \ptr
	.endm

	.macro printselectionstringfromtable ptr:req
	.byte 0x14
	.4byte \ptr
	.endm

	.macro setadditionaleffects
	1:
	.byte 0x15
	jumpifhalfword CMP_EQUAL, sMOVE_EFFECT, MOVE_EFFECT_CONTINUE, 1b
	.endm

	.macro seteffectprimary moveEffect=0
	.if \moveEffect != 0
		setmoveeffect \moveEffect
	.endif
	.byte 0x16
	.endm

	.macro seteffectsecondary moveEffect=0
	.if \moveEffect != 0
		setmoveeffect \moveEffect
	.endif
	.byte 0x17
	.endm

	.macro clearstatusfromeffect battler:req, moveEffect=0
	.if \moveEffect != 0
		setmoveeffect \moveEffect
	.endif
	.byte 0x18
	.byte \battler
	.endm

	.macro tryfaintmon battler:req
	.byte 0x19
	.byte \battler
	.byte FALSE
	.4byte NULL
	.endm

	.macro tryfaintmon_spikes battler:req, instr:req
	.byte 0x19
	.byte \battler
	.byte TRUE
	.4byte \instr
	.endm

	.macro dofaintanimation battler:req
	.byte 0x1a
	.byte \battler
	.endm

	.macro cleareffectsonfaint battler:req
	.byte 0x1b
	.byte \battler
	.endm

	.macro jumpifstatus battler:req, flags:req, jumpInstr:req
	.byte 0x1c
	.byte \battler
	.4byte \flags
	.4byte \jumpInstr
	.endm

	.macro jumpifstatus2 battler:req, flags:req, jumpInstr:req
	.byte 0x1d
	.byte \battler
	.4byte \flags
	.4byte \jumpInstr
	.endm

	.macro jumpifability battler:req, ability:req, jumpInstr:req
	.byte 0x1e
	.byte \battler
	.2byte \ability
	.4byte \jumpInstr
	.endm

	.macro jumpifsideaffecting battler:req, flags:req, jumpInstr:req
	.byte 0x1f
	.byte \battler
	.4byte \flags
	.4byte \jumpInstr
	.endm

	.macro jumpifstat battler:req, comparison:req, stat:req, value:req, jumpInstr:req
	.byte 0x20
	.byte \battler
	.byte \comparison
	.byte \stat
	.byte \value
	.4byte \jumpInstr
	.endm

	.macro jumpifstatus3condition battler:req, flags:req, jumpIfTrue:req, jumpInstr:req
	.byte 0x21
	.byte \battler
	.4byte \flags
	.byte \jumpIfTrue
	.4byte \jumpInstr
	.endm

	.macro jumpbasedontype battler:req, type:req, jumpIfType:req, jumpInstr:req
	.byte 0x22
	.byte \battler
	.byte \type
	.byte \jumpIfType
	.4byte \jumpInstr
	.endm

	.macro jumpiftype battler:req, type:req, jumpInstr:req
	jumpbasedontype \battler, \type, TRUE, \jumpInstr
	.endm

	.macro jumpifnottype battler:req, type:req, jumpInstr:req
	jumpbasedontype \battler, \type, FALSE, \jumpInstr
	.endm

	.macro getexp battler:req
	.byte 0x23
	.byte \battler
	.endm

	.macro checkteamslost jumpInstr:req
	.byte 0x24
	.4byte \jumpInstr
	.endm

	.macro movevaluescleanup
	.byte 0x25
	.endm

	.macro setmultihit value:req
	.byte 0x26
	.byte \value
	.endm

	.macro decrementmultihit loopInstr:req
	.byte 0x27
	.4byte \loopInstr
	.endm

	.macro goto instr:req
	.byte 0x28
	.4byte \instr
	.endm

	.macro jumpifbyte comparison:req, bytePtr:req, value:req, jumpInstr:req
	.byte 0x29
	.byte \comparison
	.4byte \bytePtr
	.byte \value
	.4byte \jumpInstr
	.endm

	.macro jumpifhalfword comparison:req, halfwordPtr:req, value:req, jumpInstr:req
	.byte 0x2a
	.byte \comparison
	.4byte \halfwordPtr
	.2byte \value
	.4byte \jumpInstr
	.endm

	.macro jumpifword comparison:req, wordPtr:req, value:req, jumpInstr:req
	.byte 0x2b
	.byte \comparison
	.4byte \wordPtr
	.4byte \value
	.4byte \jumpInstr
	.endm

	.macro jumpifarrayequal array1:req, array2:req, size:req, jumpInstr:req
	.byte 0x2c
	.4byte \array1
	.4byte \array2
	.byte \size
	.4byte \jumpInstr
	.endm

	.macro jumpifarraynotequal array1:req, array2:req, size:req, jumpInstr:req
	.byte 0x2d
	.4byte \array1
	.4byte \array2
	.byte \size
	.4byte \jumpInstr
	.endm

	.macro setbyte bytePtr:req, value:req
	.byte 0x2e
	.4byte \bytePtr
	.byte \value
	.endm

	.macro addbyte bytePtr:req, value:req
	.byte 0x2f
	.4byte \bytePtr
	.byte \value
	.endm

	.macro subbyte bytePtr:req, value:req
	.byte 0x30
	.4byte \bytePtr
	.byte \value
	.endm

	.macro copyarray dest:req, src:req, size:req
	.byte 0x31
	.4byte \dest
	.4byte \src
	.byte \size
	.endm

	.macro copyarraywithindex dest:req, src:req, indexPtr:req, size:req
	.byte 0x32
	.4byte \dest
	.4byte \src
	.4byte \indexPtr
	.byte \size
	.endm

	.macro orbyte bytePtr:req, value:req
	.byte 0x33
	.4byte \bytePtr
	.byte \value
	.endm

	.macro orhalfword halfwordPtr:req, value:req
	.byte 0x34
	.4byte \halfwordPtr
	.2byte \value
	.endm

	.macro orword wordPtr:req, value:req
	.byte 0x35
	.4byte \wordPtr
	.4byte \value
	.endm

	.macro bicbyte bytePtr:req, value:req
	.byte 0x36
	.4byte \bytePtr
	.byte \value
	.endm

	.macro bichalfword halfwordPtr:req, value:req
	.byte 0x37
	.4byte \halfwordPtr
	.2byte \value
	.endm

	.macro bicword wordPtr:req, value:req
	.byte 0x38
	.4byte \wordPtr
	.4byte \value
	.endm

	.macro pause frames:req
	.byte 0x39
	.2byte \frames
	.endm

	.macro waitstate
	.byte 0x3a
	.endm

	.macro healthbar_update battler:req
	.byte 0x3b
	.byte \battler
	.endm

	.macro return
	.byte 0x3c
	.endm

	.macro end
	.byte 0x3d
	.endm

	.macro end2
	.byte 0x3e
	.endm

	.macro end3
	.byte 0x3f
	.endm

	.macro call instr:req
	.byte 0x41
	.4byte \instr
	.endm

	.macro setroost
	.byte 0x42
	.endm

	.macro jumpifabilitypresent ability:req, jumpInstr:req
	.byte 0x43
	.2byte \ability
	.4byte \jumpInstr
	.endm

	.macro endselectionscript
	.byte 0x44
	.endm

	.macro playanimation battler:req, animId:req, argPtr=NULL
	.byte 0x45
	.byte \battler
	.byte \animId
	.4byte \argPtr
	.endm

	.macro playanimation_var battler:req, animIdPtr:req, argPtr=NULL
	.byte 0x46
	.byte \battler
	.4byte \animIdPtr
	.4byte \argPtr
	.endm

	.macro setgraphicalstatchangevalues
	.byte 0x47
	.endm

	.macro playstatchangeanimation battler:req, stats:req, flags:req
	.byte 0x48
	.byte \battler
	.byte \stats
	.byte \flags
	.endm

	.macro moveend endMode:req, endState:req
	.byte 0x49
	.byte \endMode
	.byte \endState
	.endm

	@ Help macros for 5 uses of moveend command

	@ All cases
	.macro moveendall
	setbyte sMOVEEND_STATE, 0
	moveend 0, 0
	.endm

	@ Chosen case
	.macro moveendcase case:req
	setbyte sMOVEEND_STATE, \case
	moveend 1, 0
	.endm

	@ All cases from (inclusive)
	.macro moveendfrom from:req
	setbyte sMOVEEND_STATE, \from
	moveend 0, 0
	.endm

	@ All cases from 0 to (not inclusive)
	.macro moveendto to:req
	setbyte sMOVEEND_STATE, 0
	moveend 2, \to
	.endm

	@ Cases from (inclusive) to (not inclusive)
	.macro moveendfromto from:req, to:req
	setbyte sMOVEEND_STATE, \from
	moveend 2, \to
	.endm

	.macro sethealblock failInstr:req
	.byte 0x4a
	.4byte \failInstr
	.endm

	.macro returnatktoball
	.byte 0x4b
	.endm

	.macro getswitchedmondata battler:req
	.byte 0x4c
	.byte \battler
	.endm

	.macro switchindataupdate battler:req
	.byte 0x4d
	.byte \battler
	.endm

	.macro switchinanim battler:req, dontClearSubstitute:req
	.byte 0x4e
	.byte \battler
	.byte \dontClearSubstitute
	.endm

	.macro jumpifcantswitch battler:req, jumpInstr:req
	.byte 0x4f
	.byte \battler
	.4byte \jumpInstr
	.endm

	.macro openpartyscreen battler:req, failInstr:req
	.byte 0x50
	.byte \battler
	.4byte \failInstr
	.endm

	.macro switchhandleorder battler:req, state:req
	.byte 0x51
	.byte \battler
	.byte \state
	.endm

	.macro switchineffects battler:req
	.byte 0x52
	.byte \battler
	.endm

	.macro trainerslidein battler:req
	.byte 0x53
	.byte \battler
	.endm

	.macro playse song:req
	.byte 0x54
	.2byte \song
	.endm

	.macro fanfare song:req
	.byte 0x55
	.2byte \song
	.endm

	.macro playfaintcry battler:req
	.byte 0x56
	.byte \battler
	.endm

	.macro endlinkbattle
	.byte 0x57
	.endm

	.macro returntoball battler:req, changingForm:req
	.byte 0x58
	.byte \battler
	.byte \changingForm
	.endm

	.macro handlelearnnewmove learnedMoveInstr:req, nothingToLearnInstr:req, isFirstMove:req
	.byte 0x59
	.4byte \learnedMoveInstr
	.4byte \nothingToLearnInstr
	.byte \isFirstMove
	.endm

	.macro yesnoboxlearnmove forgotMoveInstr:req
	.byte 0x5a
	.4byte \forgotMoveInstr
	.endm

	.macro yesnoboxstoplearningmove noInstr:req
	.byte 0x5b
	.4byte \noInstr
	.endm

	.macro hitanimation battler:req
	.byte 0x5c
	.byte \battler
	.endm

	.macro getmoneyreward
	.byte 0x5d
	.endm

	.macro updatebattlermoves battler:req
	.byte 0x5e
	.byte \battler
	.endm

	.macro swapattackerwithtarget
	.byte 0x5f
	.endm

	.macro incrementgamestat stat:req
	.byte 0x60
	.byte \stat
	.endm

	.macro drawpartystatussummary battler:req
	.byte 0x61
	.byte \battler
	.endm

	.macro hidepartystatussummary battler:req
	.byte 0x62
	.byte \battler
	.endm

	.macro jumptocalledmove notChosenMove:req
	.byte 0x63
	.byte \notChosenMove
	.endm

	.macro statusanimation battler:req
	.byte 0x64
	.byte \battler
	.endm

	.macro status2animation battler:req, status2:req
	.byte 0x65
	.byte \battler
	.4byte \status2
	.endm

	.macro chosenstatusanimation battler:req, isStatus2:req, status:req
	.byte 0x66
	.byte \battler
	.byte \isStatus2
	.4byte \status
	.endm

	.macro yesnobox
	.byte 0x67
	.endm

	.macro cancelallactions
	.byte 0x68
	.endm

	.macro setgravity failInstr:req
	.byte 0x69
	.4byte \failInstr
	.endm

	.macro removeitem battler:req
	.byte 0x6a
	.byte \battler
	.endm

	.macro atknameinbuff1
	.byte 0x6b
	.endm

	.macro drawlvlupbox
	.byte 0x6c
	.endm

	.macro resetsentmonsvalue
	.byte 0x6d
	.endm

	.macro setatktoplayer0
	.byte 0x6e
	.endm

	.macro makevisible battler:req
	.byte 0x6f
	.byte \battler
	.endm

	.macro recordability battler:req
	.byte 0x70
	.byte \battler
	.endm

	.macro buffermovetolearn
	.byte 0x71
	.endm

	.macro jumpifplayerran jumpInstr:req
	.byte 0x72
	.4byte \jumpInstr
	.endm

	.macro hpthresholds battler:req
	.byte 0x73
	.byte \battler
	.endm

	.macro hpthresholds2 battler:req
	.byte 0x74
	.byte \battler
	.endm

	.macro useitemonopponent
	.byte 0x75
	.endm

	.macro various battler:req, id:req
	.byte 0x76
	.byte \battler
	.byte \id
	.endm

	.macro setprotectlike
	.byte 0x77
	.endm

	.macro tryexplosion
	.byte 0x78
	.endm

	.macro setatkhptozero
	.byte 0x79
	.endm

	.macro jumpifnexttargetvalid jumpInstr:req
	.byte 0x7a
	.4byte \jumpInstr
	.endm

	.macro tryhealhalfhealth failInstr:req, battler:req
	.byte 0x7b
	.4byte \failInstr
	.byte \battler
	.endm

	.macro trymirrormove
	.byte 0x7c
	.endm

	.macro setrain
	.byte 0x7d
	.endm

	.macro setreflect
	.byte 0x7e
	.endm

	.macro setseeded
	.byte 0x7f
	.endm

	.macro manipulatedamage mode:req
	.byte 0x80
	.byte \mode
	.endm

	.macro trysetrest failInstr:req
	.byte 0x81
	.4byte \failInstr
	.endm

	.macro jumpifnotfirstturn jumpInstr:req
	.byte 0x82
	.4byte \jumpInstr
	.endm

	.macro setmiracleeye failInstr:req
	.byte 0x83
	.4byte \failInstr
	.endm

	.macro jumpifuproarwakes jumpInstr:req
	.byte 0x84
	.4byte \jumpInstr
	.endm

	.macro stockpile id:req
	.byte 0x85
	.byte \id
	.endm

	.macro stockpiletobasedamage failInstr:req
	.byte 0x86
	.4byte \failInstr
	.endm

	.macro stockpiletohpheal failInstr:req
	.byte 0x87
	.4byte \failInstr
	.endm

	.macro setdrainedhp
	.byte 0x88
	.endm

	.macro statbuffchange flags:req, failInstr:req
	.byte 0x89
	.2byte \flags
	.4byte \failInstr
	.endm

	.macro normalisebuffs
	.byte 0x8a
	.endm

	.macro setbide
	.byte 0x8b
	.endm

	.macro twoturnmoveschargestringandanimation
	.byte 0x8c
	.4byte 1f @animation then attack string
	@default - attack string then animation
	printsavedstring
	waitmessage B_WAIT_TIME_LONG
	attackanimation
	waitanimation
	goto 2f
	1:
	attackanimation
	waitanimation
	printsavedstring
	waitmessage B_WAIT_TIME_LONG
	2:
	.endm

	.macro setmultihitcounter value:req
	.byte 0x8d
	.byte \value
	.endm

	.macro initmultihitstring
	.byte 0x8e
	.endm

	.macro forcerandomswitch failInstr:req
	.byte 0x8f
	.4byte \failInstr
	.endm

	.macro tryconversiontypechange failInstr:req
	.byte 0x90
	.4byte \failInstr
	.endm

	.macro givepaydaymoney
	.byte 0x91
	.endm

	.macro setlightscreen
	.byte 0x92
	.endm

	.macro tryKO failInstr:req
	.byte 0x93
	.4byte \failInstr
	.endm

	.macro damagetohalftargethp
	.byte 0x94
	.endm

	.macro setsandstorm
	.byte 0x95
	.endm

	.macro weatherdamage
	.byte 0x96
	.endm

	.macro tryinfatuating failInstr:req
	.byte 0x97
	.4byte \failInstr
	.endm

	.macro updatestatusicon battler:req
	.byte 0x98
	.byte \battler
	.endm

	.macro setmist
	.byte 0x99
	.endm

	.macro setfocusenergy battler:req
	.byte 0x9a
	.byte \battler
	.endm

	.macro transformdataexecution
	.byte 0x9b
	.endm

	.macro setsubstitute
	.byte 0x9c
	.endm

	.macro mimicattackcopy failInstr:req
	.byte 0x9d
	.4byte \failInstr
	.endm

	.macro metronome
	.byte 0x9e
	.endm

	.macro dmgtolevel
	.byte 0x9f
	.endm

	.macro psywavedamageeffect
	.byte 0xa0
	.endm

	.macro counterdamagecalculator failInstr:req
	.byte 0xa1
	.4byte \failInstr
	.endm

	.macro mirrorcoatdamagecalculator failInstr:req
	.byte 0xa2
	.4byte \failInstr
	.endm

	.macro disablelastusedattack failInstr:req
	.byte 0xa3
	.4byte \failInstr
	.endm

	.macro trysetencore failInstr:req
	.byte 0xa4
	.4byte \failInstr
	.endm

	.macro painsplitdmgcalc failInstr:req
	.byte 0xa5
	.4byte \failInstr
	.endm

	.macro settypetorandomresistance failInstr:req
	.byte 0xa6
	.4byte \failInstr
	.endm

	.macro setalwayshitflag
	.byte 0xa7
	.endm

	.macro copymovepermanently failInstr:req
	.byte 0xa8
	.4byte \failInstr
	.endm

	.macro trychoosesleeptalkmove failInstr:req
	.byte 0xa9
	.4byte \failInstr
	.endm

	.macro setdestinybond
	.byte 0xaa
	.endm

	.macro trysetdestinybondtohappen
	.byte 0xab
	.endm

	.macro settailwind failInstr:req
	.byte 0xac
	.4byte \failInstr
	.endm

	.macro tryspiteppreduce failInstr:req
	.byte 0xad
	.4byte \failInstr
	.endm

	.macro healpartystatus
	.byte 0xae
	.endm

	.macro cursetarget failInstr:req
	.byte 0xaf
	.4byte \failInstr
	.endm

	.macro trysetspikes failInstr:req
	.byte 0xb0
	.4byte \failInstr
	.endm

	.macro setforesight
	.byte 0xb1
	.endm

	.macro trysetperishsong failInstr:req
	.byte 0xb2
	.4byte \failInstr
	.endm

	.macro handlerollout
	.byte 0xb3
	.endm

	.macro jumpifconfusedandstatmaxed stat:req, jumpInstr:req
	.byte 0xb4
	.byte \stat
	.4byte \jumpInstr
	.endm

	.macro handlefurycutter
	.byte 0xb5
	.endm

	.macro setembargo failInstr:req
	.byte 0xb6
	.4byte \failInstr
	.endm

	.macro presentdamagecalculation
	.byte 0xb7
	.endm

	.macro setsafeguard
	.byte 0xb8
	.endm

	.macro magnitudedamagecalculation
	.byte 0xb9
	.endm

	.macro jumpifnopursuitswitchdmg jumpInstr:req
	.byte 0xba
	.4byte \jumpInstr
	.endm

	.macro setsunny
	.byte 0xbb
	.endm

	.macro halvehp failInstr:req
	.byte 0xbc
	.4byte \failInstr
	.endm

	.macro copyfoestats unused:req
	.byte 0xbd
	.4byte \unused
	.endm

	.macro rapidspinfree
	.byte 0xbe
	.endm

	.macro setdefensecurlbit
	.byte 0xbf
	.endm

	.macro recoverbasedonsunlight failInstr:req
	.byte 0xc0
	.4byte \failInstr
	.endm

	.macro setstickyweb failInstr:req
	.byte 0xc1
	.4byte \failInstr
	.endm

	.macro selectfirstvalidtarget
	.byte 0xc2
	.endm

	.macro trysetfutureattack failInstr:req
	.byte 0xc3
	.4byte \failInstr
	.endm

	.macro trydobeatup endInstr, failInstr
	.byte 0xc4
	.4byte \endInstr
	.4byte \failInstr
	.endm

	.macro setsemiinvulnerablebit clear=FALSE
	.byte 0xc5
	.byte \clear
	.endm

	.macro clearsemiinvulnerablebit
	setsemiinvulnerablebit TRUE
	.endm

	.macro tryfiretwoturnmovenowbyeffect battler:req, checkChargeTurnEffects:req, jumpInstr:req
	.byte 0xc6
	.byte \battler
	.byte \checkChargeTurnEffects
	.4byte \jumpInstr
	.endm

	.macro tryfiretwoturnmovewithoutcharging battler:req, jumpInstr:req
	tryfiretwoturnmovenowbyeffect \battler, TRUE, \jumpInstr
	.endm

	.macro tryfiretwoturnmoveaftercharging battler:req, jumpInstr:req
	tryfiretwoturnmovenowbyeffect \battler, FALSE, \jumpInstr
	.endm

	.macro setminimize
	.byte 0xc7
	.endm

	.macro sethail
	.byte 0xc8
	.endm

	.macro trymemento failInstr:req
	.byte 0xc9
	.4byte \failInstr
	.endm

	.macro setforcedtarget
	.byte 0xca
	.endm

	.macro setcharge battler:req
	.byte 0xcb
	.byte \battler
	.endm

	.macro callterrainattack
	.byte 0xcc
	.endm

	.macro cureifburnedparalysedorpoisoned failInstr:req
	.byte 0xcd
	.4byte \failInstr
	.endm

	.macro settorment failInstr:req
	.byte 0xce
	.4byte \failInstr
	.endm

	.macro jumpifnodamage jumpInstr:req
	.byte 0xcf
	.4byte \jumpInstr
	.endm

	.macro settaunt failInstr:req
	.byte 0xd0
	.4byte \failInstr
	.endm

	.macro trysethelpinghand failInstr:req
	.byte 0xd1
	.4byte \failInstr
	.endm

	.macro tryswapitems failInstr:req
	.byte 0xd2
	.4byte \failInstr
	.endm

	.macro trycopyability battler:req, failInstr:req
	.byte 0xd3
	.byte \battler
	.4byte \failInstr
	.endm

	.macro trywish turnNumber:req, failInstr:req
	.byte 0xd4
	.byte \turnNumber
	.4byte \failInstr
	.endm

	.macro settoxicspikes failInstr:req
	.byte 0xd5
	.4byte \failInstr
	.endm

	.macro setgastroacid failInstr:req
	.byte 0xd6
	.4byte \failInstr
	.endm

	.macro setyawn failInstr:req
	.byte 0xd7
	.4byte \failInstr
	.endm

	.macro setdamagetohealthdifference failInstr:req
	.byte 0xd8
	.4byte \failInstr
	.endm

	.macro setroom
	.byte 0xd9
	.endm

	.macro tryswapabilities failInstr:req
	.byte 0xda
	.4byte \failInstr
	.endm

	.macro tryimprison failInstr:req
	.byte 0xdb
	.4byte \failInstr
	.endm

	.macro setstealthrock failInstr:req
	.byte 0xdc
	.4byte \failInstr
	.endm

	.macro setuserstatus3 flags:req, failInstr:req
	.byte 0xdd
	.4byte \flags
	.4byte \failInstr
	.endm

	.macro assistattackselect failInstr:req
	.byte 0xde
	.4byte \failInstr
	.endm

	.macro trysetmagiccoat failInstr:req
	.byte 0xdf
	.4byte \failInstr
	.endm

	.macro trysetsnatch failInstr:req
	.byte 0xe0
	.4byte \failInstr
	.endm

	.macro unused2 ptr:req
	.byte 0xe1
	.4byte \ptr
	.endm

	.macro switchoutabilities battler:req
	.byte 0xe2
	.byte \battler
	.endm

	.macro jumpifhasnohp battler:req, jumpInstr:req
	.byte 0xe3
	.byte \battler
	.4byte \jumpInstr
	.endm

	.macro jumpifnotcurrentmoveargtype battler:req, failInstr:req
	.byte 0xe4
	.byte \battler
	.4byte \failInstr
	.endm

	.macro pickup
	.byte 0xe5
	.endm

	.macro unused3
	.byte 0xe6
	.endm

	.macro unused4
	.byte 0xe7
	.endm

	.macro settypebasedhalvers failInstr:req
	.byte 0xe8
	.4byte \failInstr
	.endm

	.macro jumpifsubstituteblocks jumpInstr:req
	.byte 0xe9
	.4byte \jumpInstr
	.endm

	.macro tryrecycleitem failInstr:req
	.byte 0xea
	.4byte \failInstr
	.endm

	.macro settypetoterrain failInstr:req
	.byte 0xeb
	.4byte \failInstr
	.endm

	.macro pursuitdoubles failInstr:req
	.byte 0xec
	.4byte \failInstr
	.endm

	.macro snatchsetbattlers
	.byte 0xed
	.endm

	.macro removelightscreenreflect
	.byte 0xee
	.endm

	.macro handleballthrow
	.byte 0xef
	.endm

	.macro givecaughtmon
	.byte 0xf0
	.endm

	.macro trysetcaughtmondexflags failInstr:req
	.byte 0xf1
	.4byte \failInstr
	.endm

	.macro displaydexinfo
	.byte 0xf2
	.endm

	.macro trygivecaughtmonnick successInstr:req
	.byte 0xf3
	.4byte \successInstr
	.endm

	.macro subattackerhpbydmg
	.byte 0xf4
	.endm

	.macro removeattackerstatus1
	.byte 0xf5
	.endm

	.macro finishaction
	.byte 0xf6
	.endm

	.macro finishturn
	.byte 0xf7
	.endm

	.macro trainerslideout position:req
	.byte 0xf8
	.byte \position
	.endm

	.macro settelekinesis failInstr:req
	.byte 0xf9
	.4byte \failInstr
	.endm

	.macro swapstatstages stat:req
	.byte 0xfa
	.byte \stat
	.endm

	.macro averagestats stat:req
	.byte 0xfb
	.byte \stat
	.endm

	.macro jumpifoppositegenders jumpInstr:req
	.byte 0xfc
	.4byte \jumpInstr
	.endm

	.macro unused ptr:req
	.byte 0xfd
	.4byte \ptr
	.endm

	.macro tryworryseed failInstr:req
	.byte 0xfe
	.4byte \failInstr
	.endm

	.macro callnative func:req
	.byte 0xff
	.4byte \func
	.endm

@ callnative macros
	.macro metalburstdamagecalculator failInstr:req
	callnative BS_CalcMetalBurstDmg
	.4byte \failInstr
	.endm

	.macro jumpifcantfling battler:req, jumpInstr:req
	callnative BS_JumpIfCantFling
	.byte \battler
	.4byte \jumpInstr
	.endm

	.macro itemstatchangeeffects battler:req
	callnative BS_RunStatChangeItems
	.byte \battler
	.endm

	.macro allyswitchswapbattlers
	callnative BS_AllySwitchSwapBattler
	.endm

	.macro allyswitchfailchance jumpInstr:req
	callnative BS_AllySwitchFailChance
	.4byte \jumpInstr
	.endm

	.macro dostockpilestatchangeswearoff, battler:req, statChangeInstr:req
	callnative BS_DoStockpileStatChangesWearOff
	.byte \battler
	.4byte \statChangeInstr
	.endm

	.macro jumpifmorethanhalfHP battler:req, jumpInstr:req
	callnative BS_JumpIfMoreThanHalfHP
	.byte \battler
	.4byte \jumpInstr
	.endm

	.macro itemrestorehp jumpInstr:req, restoreBattlerInstr:req
	callnative BS_ItemRestoreHP
	.4byte \jumpInstr
	.4byte \restoreBattlerInstr
	.endm

	.macro itemcurestatus jumpInstr:req
	callnative BS_ItemCureStatus
	.4byte \jumpInstr
	.endm

	.macro itemincreasestat
	callnative BS_ItemIncreaseStat
	.endm

	.macro itemrestorepp
	callnative BS_ItemRestorePP
	.endm

	.macro tryrevertweatherform
	callnative BS_TryRevertWeatherForm
	.endm

	.macro setsnow
	callnative BS_SetSnow
	.endm

	.macro applysaltcure battler:req
	callnative BS_ApplySaltCure
	.byte \battler
	.endm

	.macro trysetoctolock battler:req, failInstr:req
	callnative BS_TrySetOctolock
	.byte \battler
	.4byte \failInstr
	.endm

	.macro setglaiverush
	callnative BS_SetGlaiveRush
	.endm

	.macro tryrelicsong
	callnative BS_TryRelicSong
	.endm

	.macro setpledge jumpInstr:req
	callnative BS_SetPledge
	.4byte \jumpInstr
	.endm

	.macro setpledgestatus battler:req sidestatus:req
	callnative BS_SetPledgeStatus
	.byte \battler
	.4byte \sidestatus
	.endm

	.macro trycopycat failInstr:req
	callnative BS_TryCopycat
	.4byte \failInstr
	.endm

	.macro setzeffect
	callnative BS_SetZEffect
	.endm

	@ Used by effects that may proc Symbiosis but do not call removeitem.
	.macro trysymbiosis
	callnative BS_TrySymbiosis
	.endm

	@ returns B_SIDE_x to gBattleCommunication[0]
	.macro getbattlerside battler:req
	callnative BS_GetBattlerSide
	.byte \battler
	.endm

	.macro checkparentalbondcounter counter:req, ptr:req
	callnative BS_CheckParentalBondCounter
	.byte \counter
	.4byte \ptr
	.endm

	.macro jumpifcantloseitem battler:req, ptr:req
	callnative BS_JumpIfCantLoseItem
	.byte \battler
	.4byte \ptr
	.endm

	.macro handlemegaevo battler:req, case:req
	callnative BS_HandleMegaEvolution
	.byte \battler
	.byte \case
	.endm

	.macro handleprimalreversion battler:req, case:req
	callnative BS_HandlePrimalReversion
	.byte \battler
	.byte \case
	.endm

	.macro handleultraburst battler:req, case:req
	callnative BS_HandleUltraBurst
	.byte \battler
	.byte \case
	.endm

	.macro jumpifshelltrap battler:req, jumpInstr:req
	callnative BS_JumpIfShellTrap
	.byte \battler
	.4byte \jumpInstr
	.endm

	.macro jumpifemergencyexited battler:req, jumpInstr:req
	callnative BS_JumpIfEmergencyExited
	.byte \battler
	.4byte \jumpInstr
	.endm

	.macro jumpifrodaffected battler:req, jumpInstr:req
	callnative BS_JumpIfRod
	.4byte \jumpInstr
	.endm

	.macro jumpifabsorbaffected battler:req, jumpInstr:req
	callnative BS_JumpIfAbsorb
	.4byte \jumpInstr
	.endm

	.macro jumpifmotoraffected battler:req, jumpInstr:req
	callnative BS_JumpIfMotor
	.4byte \jumpInstr
	.endm

	.macro jumpifargument argument:req, jumpInstr:req
	callnative BS_JumpIfArgument
	.byte \argument
	.4byte \jumpInstr
	.endm

	.macro setremoveterrain failInstr:req
	callnative BS_SetRemoveTerrain
	.4byte \failInstr
	.endm

	.macro jumpifterrainaffected battler:req, terrainFlags:req, jumpInstr:req
	callnative BS_JumpIfTerrainAffected
	.byte \battler
	.4byte \terrainFlags
	.4byte \jumpInstr
	.endm

	.macro tryreflecttype failInstr:req
	callnative BS_TryReflectType
	.4byte \failInstr
	.endm

	@ Used to active a different Max Move effects.
	.macro setmaxmoveeffect
	callnative BS_SetMaxMoveEffect
	.endm

	.macro setsteelsurge, failInstr:req
	callnative BS_SetSteelsurge
	.4byte \failInstr
	.endm

	.macro damagenontypes
	callnative BS_DamageNonTypes
	.endm

	.macro trysetstatus1, ptr:req
	callnative BS_TrySetStatus1
	.4byte \ptr
	.endm

	.macro trysetstatus2, ptr:req
	callnative BS_TrySetStatus2
	.4byte \ptr
	.endm

	.macro tryhealsixthhealth, ptr:req
	callnative BS_HealOneSixth
	.4byte \ptr
	.endm

	.macro tryrecycleberry, ptr:req
	callnative BS_TryRecycleBerry
	.4byte \ptr
	.endm

	.macro updatedynamax
	callnative BS_UpdateDynamax
	.endm

	.macro jumpiftargetdynamaxed, ptr:req
	callnative BS_JumpIfDynamaxed
	.4byte \ptr
	.endm

	.macro trytrainerslidezmovemsg
	callnative BS_TryTrainerSlideZMoveMsg
	.endm

	.macro trytrainerslidemegaevolutionmsg
	callnative BS_TryTrainerSlideMegaEvolutionMsg
	.endm

	.macro trytrainerslidedynamaxmsg
	callnative BS_TryTrainerSlideDynamaxMsg
	.endm

	.macro tryhealpulse failInstr:req
	callnative BS_TryHealPulse
	.4byte \failInstr
	.endm

	.macro trydefog clear:req, failInstr:req
	callnative BS_TryDefog
	.byte \clear
	.4byte \failInstr
	.endm

	.macro trytriggerstatusform
	callnative BS_TryTriggerStatusForm
	.endm

	.macro setphotongeysercategory
	callnative BS_SetPhotonGeyserCategory
	.endm

	.macro tryupperhand failInstr:req
	callnative BS_TryUpperHand
	.4byte \failInstr
	.endm

	.macro tryupdaterecoiltracker
	callnative BS_TryUpdateRecoilTracker
	.endm

	.macro trytidyup clear:req, jumpInstr:req
	callnative BS_TryTidyUp
	.byte \clear
	.4byte \jumpInstr
	.endm

	.macro trygulpmissile
	callnative BS_TryGulpMissile
	.endm

	.macro tryactivategulpmissile
	callnative BS_TryActivateGulpMissile
	.endm

	.macro tryquash failInstr:req
	callnative BS_TryQuash
	.4byte \failInstr
	.endm

@ various command changed to more readable macros
	.macro cancelmultiturnmoves battler:req
	various \battler, VARIOUS_CANCEL_MULTI_TURN_MOVES
	.endm

	@ Stores Healing Wish effect.
	.macro storehealingwish battler:req
	various \battler, VARIOUS_STORE_HEALING_WISH
	.endm

	.macro setmagiccoattarget battler:req
	various \battler, VARIOUS_SET_MAGIC_COAT_TARGET
	.endm

	.macro getifcantrunfrombattle battler:req
	various \battler, VARIOUS_IS_RUNNING_IMPOSSIBLE
	.endm

	.macro getmovetarget battler:req
	various \battler, VARIOUS_GET_MOVE_TARGET
	.endm

	.macro getbattlerfainted battler:req
	various \battler, VARIOUS_GET_BATTLER_FAINTED
	.endm

	.macro resetswitchinabilitybits battler:req
	various \battler, VARIOUS_RESET_SWITCH_IN_ABILITY_BITS
	.endm

	.macro updatechoicemoveonlvlup battler:req
	various \battler, VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP
	.endm

	.macro resetplayerfainted
	various BS_ATTACKER, VARIOUS_RESET_PLAYER_FAINTED
	.endm

	.macro palaceflavortext battler:req
	various \battler, VARIOUS_PALACE_FLAVOR_TEXT
	.endm

	.macro arenajudgmentwindow
	various BS_ATTACKER, VARIOUS_ARENA_JUDGMENT_WINDOW
	.endm

	.macro arenaopponentmonlost
	various BS_ATTACKER, VARIOUS_ARENA_OPPONENT_MON_LOST
	.endm

	.macro arenaplayermonlost
	various BS_ATTACKER, VARIOUS_ARENA_PLAYER_MON_LOST
	.endm

	.macro arenabothmonlost
	various BS_ATTACKER, VARIOUS_ARENA_BOTH_MONS_LOST
	.endm

	.macro forfeityesnobox battler:req
	various \battler, VARIOUS_EMIT_YESNOBOX
	.endm

	.macro arenadrawreftextbox
	various BS_ATTACKER, VARIOUS_DRAW_ARENA_REF_TEXT_BOX
	.endm

	.macro arenaerasereftextbox
	various BS_ATTACKER, VARIOUS_ERASE_ARENA_REF_TEXT_BOX
	.endm

	.macro arenajudgmentstring id:req
	various \id, VARIOUS_ARENA_JUDGMENT_STRING
	.endm

	.macro arenawaitmessage id:req
	various \id, VARIOUS_ARENA_WAIT_STRING
	.endm

	.macro waitcry battler:req
	various \battler, VARIOUS_WAIT_CRY
	.endm

	.macro returnopponentmon1toball battler:req
	various \battler, VARIOUS_RETURN_OPPONENT_MON1
	.endm

	.macro returnopponentmon2toball battler:req
	various \battler, VARIOUS_RETURN_OPPONENT_MON2
	.endm

	.macro volumedown
	various BS_ATTACKER, VARIOUS_VOLUME_DOWN
	.endm

	.macro volumeup
	various BS_ATTACKER, VARIOUS_VOLUME_UP
	.endm

	.macro setalreadystatusedmoveattempt battler:req
	various \battler, VARIOUS_SET_ALREADY_STATUS_MOVE_ATTEMPT
	.endm

	.macro palacetryescapestatus battler:req
	various \battler, VARIOUS_PALACE_TRY_ESCAPE_STATUS
	.endm

	.macro setoutcomeonteleport battler:req
	various \battler, VARIOUS_SET_TELEPORT_OUTCOME
	.endm

	.macro playtrainerdefeatbgm battler:req
	various \battler, VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC
	.endm

	.macro stattextbuffer battler:req
	various \battler, VARIOUS_STAT_TEXT_BUFFER
	.endm

	.macro switchinabilities battler:req
	various \battler, VARIOUS_SWITCHIN_ABILITIES
	.endm

	.macro savetarget
	various BS_TARGET, VARIOUS_SAVE_TARGET
	.endm

	.macro restoretarget
	various BS_TARGET, VARIOUS_RESTORE_TARGET
	.endm

	.macro instanthpdrop battler:req
	various \battler, VARIOUS_INSTANT_HP_DROP
	.endm

	.macro clearstatus battler:req
	various \battler, VARIOUS_CLEAR_STATUS
	.endm

	.macro restorepp battler:req
	various \battler, VARIOUS_RESTORE_PP
	.endm

	.macro tryactivatemoxie battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_MOXIE
	.endm

	.macro tryactivatebeastboost battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_BEAST_BOOST
	.endm

	.macro tryactivatereceiver battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_RECEIVER
	.endm

	.macro tryactivatesoulheart
	various BS_ATTACKER, VARIOUS_TRY_ACTIVATE_SOULHEART
	.endm

	.macro tryactivatefellstinger battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_FELL_STINGER
	.endm

	.macro playmoveanimation battler:req, move:req
	various \battler, VARIOUS_PLAY_MOVE_ANIMATION
	.2byte \move
	.endm

	.macro setluckychant battler:req, failInstr:req
	various \battler VARIOUS_SET_LUCKY_CHANT
	.4byte \failInstr
	.endm

	.macro suckerpunchcheck failInstr:req
	various BS_ATTACKER, VARIOUS_SUCKER_PUNCH_CHECK
	.4byte \failInstr
	.endm

	.macro setabilitysimple battler:req, failInstr:req
	various \battler VARIOUS_SET_SIMPLE_BEAM
	.4byte \failInstr
	.endm

	.macro tryentrainment failInstr:req
	various BS_ATTACKER, VARIOUS_TRY_ENTRAINMENT
	.4byte \failInstr
	.endm

	.macro setlastusedability battler:req
	various \battler, VARIOUS_SET_LAST_USED_ABILITY
	.endm

	.macro tryafteryou failInstr:req
	various BS_ATTACKER, VARIOUS_AFTER_YOU
	.4byte \failInstr
	.endm

	.macro trybestow failInstr:req
	various BS_ATTACKER, VARIOUS_BESTOW
	.4byte \failInstr
	.endm

	.macro invertstatstages battler:req
	various \battler, VARIOUS_INVERT_STAT_STAGES
	.endm

	.macro trymefirst failInstr:req
	various BS_ATTACKER, VARIOUS_TRY_ME_FIRST
	.4byte \failInstr
	.endm

	.macro jumpifbattleend jumpInstr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_BATTLE_END
	.4byte \jumpInstr
	.endm

	.macro tryelectrify failInstr:req
	various BS_ATTACKER, VARIOUS_TRY_ELECTRIFY
	.4byte \failInstr
	.endm

	.macro trysoak failInstr:req
	various BS_ATTACKER, VARIOUS_TRY_SOAK
	.4byte \failInstr
	.endm

	.macro handleformchange battler:req, case:req
	various \battler, VARIOUS_HANDLE_FORM_CHANGE
	.byte \case
	.endm

	.macro jumpifcantuselastresort battler:req, jumpInstr:req
	various \battler, VARIOUS_TRY_LAST_RESORT
	.4byte \jumpInstr
	.endm

	.macro setargtobattledamage
	various BS_ATTACKER, VARIOUS_SET_ARG_TO_BATTLE_DAMAGE
	.endm

	.macro tryhitswitchtarget failInstr:req
	various BS_ATTACKER, VARIOUS_TRY_HIT_SWITCH_TARGET
	.4byte \failInstr
	.endm

	.macro tryautotomize battler:req, failInstr:req
	various \battler, VARIOUS_TRY_AUTOTOMIZE
	.4byte \failInstr
	.endm

	.macro jumpifcantusesynchronoise jumpInstr:req
	various BS_ATTACKER, VARIOUS_TRY_SYNCHRONOISE
	.4byte \jumpInstr
	.endm

	.macro showabilitypopup battler:req
	various \battler, VARIOUS_ABILITY_POPUP
	.endm

	.macro updateabilitypopup battler:req
	various \battler, VARIOUS_UPDATE_ABILITY_POPUP
	.endm

	.macro jumpiftargetally jumpInstr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_TARGET_ALLY
	.4byte \jumpInstr
	.endm

	.macro trypsychoshift failInstr:req
	various BS_ATTACKER, VARIOUS_PSYCHO_SHIFT
	.4byte \failInstr
	.endm

	.macro curestatus battler:req
	various \battler, VARIOUS_CURE_STATUS
	.endm

	.macro powertrick battler:req
	various \battler, VARIOUS_POWER_TRICK
	.endm

	.macro jumpifnotgrounded battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_NOT_GROUNDED
	.4byte \jumpInstr
	.endm

	.macro handletrainerslidemsg battler:req, case:req
	various \battler, VARIOUS_HANDLE_TRAINER_SLIDE_MSG
	.byte \case
	.endm

	.macro trytrainerslidefirstdownmsg battler:req
	various \battler, VARIOUS_TRY_TRAINER_SLIDE_MSG_FIRST_OFF
	.endm

	.macro trytrainerslidelastonmsg battler:req
	various \battler, VARIOUS_TRY_TRAINER_SLIDE_MSG_LAST_ON
	.endm

	.macro setauroraveil battler:req
	various \battler, VARIOUS_SET_AURORA_VEIL
	.endm

	.macro trysetthirdtype battler:req, failInstr:req
	various \battler, VARIOUS_TRY_THIRD_TYPE
	.4byte \failInstr
	.endm

	.macro tryaccupressure battler:req, failInstr:req
	various \battler, VARIOUS_ACUPRESSURE
	.4byte \failInstr
	.endm

	.macro setpowder battler:req
	various \battler, VARIOUS_SET_POWDER
	.endm

	.macro spectralthiefprintstats
	various BS_ATTACKER, VARIOUS_SPECTRAL_THIEF
	.endm

	.macro bringdownairbornebattler battler:req
	various \battler, VARIOUS_GRAVITY_ON_AIRBORNE_MONS
	.endm

	.macro checkgrassyterrainheal battler:req, failInstr:req
	various \battler, VARIOUS_CHECK_IF_GRASSY_TERRAIN_HEALS
	.4byte \failInstr
	.endm

	.macro jumpifnotberry battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_NOT_BERRY
	.4byte \jumpInstr
	.endm

	.macro jumpifroarfails jumpInstr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_ROAR_FAILS
	.4byte \jumpInstr
	.endm

	.macro tryinstruct failInstr:req
	various BS_ATTACKER, VARIOUS_TRY_INSTRUCT
	.4byte \failInstr
	.endm

	.macro settracedability battler:req
	various \battler, VARIOUS_TRACE_ABILITY
	.endm

	.macro updatenick battler:req
	various \battler, VARIOUS_UPDATE_NICK
	.endm

	.macro tryillusionoff battler:req
	various \battler, VARIOUS_TRY_ILLUSION_OFF
	.endm

	.macro spriteignore0hp value:req
	various BS_ATTACKER, VARIOUS_SET_SPRITEIGNORE0HP
	.byte \value
	.endm

	.macro getstatvalue battler:req, stat:req
	various \battler, VARIOUS_GET_STAT_VALUE
	.byte \stat
	.endm

	.macro jumpiffullhp battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_FULL_HP
	.4byte \jumpInstr
	.endm

	.macro losetype battler:req, type:req
	various \battler, VARIOUS_LOSE_TYPE
	.byte \type
	.endm

	.macro tryfriskmsg battler:req
	various \battler, VARIOUS_TRY_FRISK
	.endm

	.macro jumpifshieldsdown battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_SHIELDS_DOWN_PROTECTED
	.4byte \jumpInstr
	.endm

	.macro trypoisontype attacker:req, target:req, failInstr:req
	various \attacker, VARIOUS_POISON_TYPE_IMMUNITY
	.byte \target
	.4byte \failInstr
	.endm

	.macro tryparalyzetype attacker:req, target:req, failInstr:req
	various \attacker, VARIOUS_PARALYZE_TYPE_IMMUNITY
	.byte \target
	.4byte \failInstr
	.endm

	.macro trysetfairylock failInstr:req
	various BS_ATTACKER, VARIOUS_TRY_FAIRY_LOCK
	.4byte \failInstr
	.endm

	.macro jumpifnoally battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_NO_ALLY
	.4byte \jumpInstr
	.endm

	.macro jumpifholdeffect battler:req, holdEffect:req, jumpInstr:req, equal=TRUE
	various \battler, VARIOUS_JUMP_IF_HOLD_EFFECT
	.byte \holdEffect
	.4byte \jumpInstr
	.byte \equal
	.endm

	.macro jumpifnoholdeffect battler:req, holdEffect:req, jumpInstr:req
	jumpifholdeffect \battler, \holdEffect, \jumpInstr, FALSE
	.endm

	.macro infatuatewithbattler battler:req, infatuateWith:req
	various \battler, VARIOUS_INFATUATE_WITH_BATTLER
	.byte \infatuateWith
	.endm

	.macro setlastuseditem battler:req
	various \battler, VARIOUS_SET_LAST_USED_ITEM
	.endm

	.macro jumpifabsent battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_ABSENT
	.4byte \jumpInstr
	.endm

	.macro destroyabilitypopup
	various BS_ABILITY_BATTLER, VARIOUS_DESTROY_ABILITY_POPUP
	.endm

	.macro gettotemboost jumpInstr:req
	various BS_ATTACKER, VARIOUS_TOTEM_BOOST
	.4byte \jumpInstr
	.endm

	.macro tryactivategrimneigh, battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_GRIM_NEIGH
	.endm

	.macro consumeberry battler:req, fromBattler:req
	various \battler, VARIOUS_CONSUME_BERRY
	.byte \fromBattler
	.endm

	.macro activateitemeffects battler:req
	various \battler, VARIOUS_MOVEEND_ITEM_EFFECTS
	.endm

	.macro pickpocketsteal
	various 0, VARIOUS_PICKPOCKET
	.endm

	.macro doterrainseed battler:req, failInstr:req
	various \battler, VARIOUS_TERRAIN_SEED
	.4byte \failInstr
	.endm

	.macro makeinvisible battler:req
	various \battler, VARIOUS_MAKE_INVISIBLE
	.endm

	.macro tryroomservice battler:req, failInstr:req
	various \battler, VARIOUS_ROOM_SERVICE
	.4byte \failInstr
	.endm

	.macro jumpifpranksterblocked battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_PRANKSTER_BLOCKED
	.4byte \jumpInstr
	.endm

	.macro eeriespellppreduce failInstr:req
	various BS_TARGET, VARIOUS_EERIE_SPELL_PP_REDUCE
	.4byte \failInstr
	.endm

	.macro jumpifteamhealthy battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_TEAM_HEALTHY
	.4byte \jumpInstr
	.endm

	.macro tryhealquarterhealth battler:req, failInstr:req
	various \battler, VARIOUS_TRY_HEAL_QUARTER_HP
	.4byte \failInstr
	.endm

	.macro removeterrain
	various BS_ATTACKER, VARIOUS_REMOVE_TERRAIN
	.endm

	.macro trytoclearprimalweather
	various BS_ATTACKER, VARIOUS_TRY_TO_CLEAR_PRIMAL_WEATHER
	.endm

	.macro setattackertostickywebuser
	various BS_TARGET, VARIOUS_SET_ATTACKER_STICKY_WEB_USER
	.endm

	.macro getrototillertargets failInstr:req
	various BS_ATTACKER, VARIOUS_GET_ROTOTILLER_TARGETS
	.4byte \failInstr
	.endm

	.macro jumpifnotrototilleraffected battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_NOT_ROTOTILLER_AFFECTED
	.4byte \jumpInstr
	.endm

	.macro tryactivatebattlebond battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_BATTLE_BOND
	.endm

	.macro jumpifcantreverttoprimal jumpInstr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_CANT_REVERT_TO_PRIMAL
	.4byte \jumpInstr
	.endm

	.macro jumpifweatheraffected battler:req, flags:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_WEATHER_AFFECTED
	.4byte \flags
	.4byte \jumpInstr
	.endm

	.macro jumpifspecies battler:req, species:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_SPECIES
	.2byte \species
	.4byte \jumpInstr
	.endm

	.macro tryendneutralizinggas battler:req
	various \battler, VARIOUS_TRY_END_NEUTRALIZING_GAS
	.endm

	.macro trynoretreat battler:req, failInstr:req
	various \battler, VARIOUS_TRY_NO_RETREAT
	.4byte \failInstr
	.endm

	.macro trytarshot battler:req, failInstr:req
	various \battler, VARIOUS_TRY_TAR_SHOT
	.4byte \failInstr
	.endm

	.macro cantarshotwork battler:req, failInstr:req
	various \battler, VARIOUS_CAN_TAR_SHOT_WORK
	.4byte \failInstr
	.endm

	.macro checkpoltergeist battler:req, failInstr:req
	various \battler, VARIOUS_CHECK_POLTERGEIST
	.4byte \failInstr
	.endm

	.macro cutonethirdhpraisestats failInstr:req
	various BS_ATTACKER, VARIOUS_CUT_1_3_HP_RAISE_STATS
	.4byte \failInstr
	.endm

	.macro jumpifteanoberry jumpInstr:req
	various BS_ATTACKER, VARIOUS_TEATIME_TARGETS
	.4byte \jumpInstr
	.endm

	.macro jumpifteainvulnerable battler:req, jumpInstr:req
	various \battler, VARIOUS_TEATIME_INVUL
	.4byte \jumpInstr
	.endm

	.macro curecertainstatuses battler:req
	various \battler, VARIOUS_CURE_CERTAIN_STATUSES
	.endm

	.macro tryresetnegativestatstages battler:req
	various \battler, VARIOUS_TRY_RESET_NEGATIVE_STAT_STAGES
	.endm

	.macro jumpiflastuseditemberry jumpInstr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_LAST_USED_ITEM_BERRY
	.4byte \jumpInstr
	.endm

	.macro jumpiflastuseditemholdeffect battler:req, holdEffect:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_LAST_USED_ITEM_HOLD_EFFECT
	.byte \holdEffect
	.4byte \jumpInstr
	.endm

	.macro savebattleritem battler:req
	various \battler, VARIOUS_SAVE_BATTLER_ITEM
	.endm

	.macro restorebattleritem battler:req
	various \battler, VARIOUS_RESTORE_BATTLER_ITEM
	.endm

	.macro battleritemtolastuseditem battler:req
	various \battler, VARIOUS_BATTLER_ITEM_TO_LAST_USED_ITEM
	.endm

	.macro setbeakblast battler:req
	various \battler, VARIOUS_SET_BEAK_BLAST
	.endm

	.macro swapsidestatuses
	various BS_ATTACKER, VARIOUS_SWAP_SIDE_STATUSES
	.endm

	.macro swapstats stat:req
	various BS_ATTACKER, VARIOUS_SWAP_STATS
	.byte \stat
	.endm

	.macro trywindriderpower battler:req, failInstr:req
	various \battler, VARIOUS_TRY_WIND_RIDER_POWER
	.4byte \failInstr
	.endm

	.macro activateweatherchangeabilities battler:req
	various \battler, VARIOUS_ACTIVATE_WEATHER_CHANGE_ABILITIES
	.endm

	.macro activateterrainchangeabilities battler:req
	various \battler, VARIOUS_ACTIVATE_TERRAIN_CHANGE_ABILITIES
	.endm

@ helpful macros
	.macro setstatchanger stat:req, stages:req, down:req
	setbyte sSTATCHANGER, \stat | \stages << 3 | \down << 7
	.endm

	.macro setmoveeffect effect:req
	sethword sMOVE_EFFECT, \effect
	sethword sSAVED_MOVE_EFFECT, \effect
	.endm

	.macro chosenstatus1animation battler:req, status:req
	chosenstatusanimation \battler, 0x0, \status
	.endm

	.macro chosenstatus2animation battler:req, status:req
	chosenstatusanimation \battler, 0x1, \status
	.endm

	.macro sethword dst:req, value:req
	setbyte \dst, (\value) & 0xFF
	setbyte \dst + 1, ((\value) >> 8) & 0xFF
	.endm

	.macro setword dst:req, value:req
	setbyte \dst, (\value) & 0xFF
	setbyte \dst + 1, ((\value) >> 8) & 0xFF
	setbyte \dst + 2, ((\value) >> 16) & 0xFF
	setbyte \dst + 3, ((\value) >> 24) & 0xFF
	.endm

	.macro copybyte dst:req, src:req
	copyarray \dst, \src, 0x1
	.endm

	.macro copyhword dst:req, src:req
	copyarray \dst, \src, 0x2
	.endm

	.macro copyword dst:req, src:req
	copyarray \dst, \src, 0x4
	.endm

	.macro jumpifbytenotequal byte1:req, byte2:req, jumpInstr:req
	jumpifarraynotequal \byte1, \byte2, 0x1, \jumpInstr
	.endm

	.macro jumpifbyteequal byte1:req, byte2:req, jumpInstr:req
	jumpifarrayequal \byte1, \byte2, 0x1, \jumpInstr
	.endm

	.macro jumpifmove move:req, jumpInstr:req
	jumpifhalfword CMP_EQUAL, gCurrentMove, \move, \jumpInstr
	.endm

	.macro jumpifnotmove move:req, jumpInstr:req
	jumpifhalfword CMP_NOT_EQUAL, gCurrentMove, \move, \jumpInstr
	.endm

	.macro jumpifnotchosenmove move:req, jumpInstr:req
	jumpifhalfword CMP_NOT_EQUAL, gChosenMove, \move, \jumpInstr
	.endm

	.macro jumpifstatus3 battler:req, flags:req, jumpInstr:req
	jumpifstatus3condition \battler, \flags, FALSE, \jumpInstr
	.endm

	.macro jumpifnostatus3 battler:req, flags:req, jumpInstr:req
	jumpifstatus3condition \battler, \flags, TRUE, \jumpInstr
	.endm

	.macro jumpifmovehadnoeffect jumpInstr:req
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_NO_EFFECT, \jumpInstr
	.endm

	.macro jumpifside battler:req, side:req, equalJumpInstr:req
	getbattlerside \battler
	jumpifbyte CMP_EQUAL, gBattleCommunication, \side, \equalJumpInstr
	.endm

	.macro jumpifbattletype flags:req, jumpInstr:req
	jumpifword CMP_COMMON_BITS, gBattleTypeFlags, \flags, \jumpInstr
	.endm

	.macro jumpifnotbattletype flags:req, jumpInstr:req
	jumpifword CMP_NO_COMMON_BITS, gBattleTypeFlags, \flags, \jumpInstr
	.endm

	.macro dmg_1_8_targethp
	manipulatedamage DMG_1_8_TARGET_HP
	.endm

	.macro dmgtomaxattackerhp
	manipulatedamage DMG_FULL_ATTACKER_HP
	.endm

	.macro dmgtocurrattackerhp
	manipulatedamage DMG_CURR_ATTACKER_HP
	.endm

	.macro jumpifflowerveil jumpInstr:req
	jumpifnottype BS_TARGET, TYPE_GRASS, 1f
	jumpifability BS_TARGET_SIDE, ABILITY_FLOWER_VEIL, \jumpInstr
	1:
	.endm

	.macro jumpifflowerveilattacker jumpInstr:req
	jumpifnottype BS_ATTACKER, TYPE_GRASS, 1f
	jumpifability BS_ATTACKER_SIDE, ABILITY_FLOWER_VEIL, \jumpInstr
	1:
	.endm

	.macro setallytonexttarget jumpInstr:req
	jumpifbyte CMP_GREATER_THAN, gBattlerTarget, 0x1, 1f
	addbyte gBattlerTarget, 0x2
	goto \jumpInstr
	1:
	subbyte gBattlerTarget, 0x2
	goto \jumpInstr
	.endm

	.macro setallytonextattacker jumpInstr:req
	jumpifbyte CMP_GREATER_THAN, gBattlerAttacker, 0x1, 1f
	addbyte gBattlerAttacker, 0x2
	goto \jumpInstr
	1:
	subbyte gBattlerAttacker, 0x2
	goto \jumpInstr
	.endm

	.macro jumpifleafguardprotected battler:req, jumpInstr:req
	various \battler, VARIOUS_JUMP_IF_LEAF_GUARD_PROTECTED
	.4byte \jumpInstr
	.endm

	.macro jumpifsafeguard jumpInstr:req
	jumpifability BS_ATTACKER, ABILITY_INFILTRATOR, 1f
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, \jumpInstr
	1:
	.endm

	@ Will jump to script pointer if the target weighs less than 200 kg, or 441 lbs.
	.macro jumpifunder200 battler:req, failInstr:req
	various \battler, VARIOUS_JUMP_IF_UNDER_200
	.4byte \failInstr
	.endm

	@ Sets the sky drop status and does all other necessary operations
	.macro setskydrop
	various 0, VARIOUS_SET_SKY_DROP
	.endm

	@ Clears the sky drop status and does all other necessary operations.
	@ If the target fainted in before this script is called, it goes to the given script.
	.macro clearskydrop failInstr:req
	various 0, VARIOUS_CLEAR_SKY_DROP
	.4byte \failInstr
	.endm

	@ Accounts for if the target of Sky Drop was in confuse_lock when the attacker falls asleep due to Yawn.
	.macro skydropyawn
	various 0, VARIOUS_SKY_DROP_YAWN
	.endm

	@ Tries to increase or decrease a battler's stat's stat stage by a specified amount. If impossible, jumps to \script.
	.macro modifybattlerstatstage battler:req, stat:req, mode:req, amount:req, script:req, animation:req, customString

	@ \mode parameters
	INCREASE = FALSE
	DECREASE = TRUE

	@ \animation parameters
	ANIM_OFF = FALSE
	ANIM_ON = TRUE

	setstatchanger \stat, \amount, \mode
	statbuffchange STAT_CHANGE_ALLOW_PTR, \script
	setgraphicalstatchangevalues
	.if \animation == TRUE
		playanimation \battler, B_ANIM_STATS_CHANGE, sB_ANIM_ARG1
	.endif
	.ifnb \customString
		printstring \customString
	.else
		.if \mode == DECREASE
			printfromtable gStatDownStringIds
		.else
		.if \mode == INCREASE
			printfromtable gStatUpStringIds
		.endif
		.endif
	.endif
	waitmessage B_WAIT_TIME_LONG
	.endm

	.macro hitswitchtargetfailed
	various 0, VARIOUS_HIT_SWITCH_TARGET_FAILED
	.endm

	.macro tryrevivalblessing, jumpInstr:req
	various 0, VARIOUS_TRY_REVIVAL_BLESSING
	.4byte \jumpInstr
	.endm

	@ Will jump to script pointer if the specified battler has or has not fainted.
	.macro jumpiffainted battler:req, value:req, ptr:req
	getbattlerfainted \battler
	jumpifbyte CMP_EQUAL, gBattleCommunication, \value, \ptr
	.endm

	.macro flushtextbox
	printstring STRINGID_EMPTYSTRING3
	waitmessage 1
	.endm
