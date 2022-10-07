@ commands
	.macro attackcanceler
	.byte 0x0
	.endm

	.macro accuracycheck failPtr:req, move:req
	.byte 0x1
	.4byte \failPtr
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

	.macro seteffectwithchance
	.byte 0x15
	.endm

	.macro seteffectprimary
	.byte 0x16
	.endm

	.macro seteffectsecondary
	.byte 0x17
	.endm

	.macro clearstatusfromeffect battler:req
	.byte 0x18
	.byte \battler
	.endm

	.macro tryfaintmon battler:req
	.byte 0x19
	.byte \battler
	.byte FALSE
	.4byte NULL
	.endm

	.macro tryfaintmon_spikes battler:req, ptr:req
	.byte 0x19
	.byte \battler
	.byte TRUE
	.4byte \ptr
	.endm

	.macro dofaintanimation battler:req
	.byte 0x1a
	.byte \battler
	.endm

	.macro cleareffectsonfaint battler:req
	.byte 0x1b
	.byte \battler
	.endm

	.macro jumpifstatus battler:req, status1:req, ptr:req
	.byte 0x1c
	.byte \battler
	.4byte \status1
	.4byte \ptr
	.endm

	.macro jumpifstatus2 battler:req, status2:req, ptr:req
	.byte 0x1d
	.byte \battler
	.4byte \status2
	.4byte \ptr
	.endm

	.macro jumpifability battler:req, ability:req, ptr:req
	.byte 0x1e
	.byte \battler
	.2byte \ability
	.4byte \ptr
	.endm

	.macro jumpifsideaffecting battler:req, sidestatus:req, ptr:req
	.byte 0x1f
	.byte \battler
	.4byte \sidestatus
	.4byte \ptr
	.endm

	.macro jumpifstat battler:req, ifflag:req, stat:req, value:req, ptr
	.byte 0x20
	.byte \battler
	.byte \ifflag
	.byte \stat
	.byte \value
	.4byte \ptr
	.endm

	.macro jumpifstatus3condition battler:req, status3:req, condition:req, ptr:req
	.byte 0x21
	.byte \battler
	.4byte \status3
	.byte \condition
	.4byte \ptr
	.endm

	.macro jumpbasedontype battler:req, type:req, case:req, ptr:req
	.byte 0x22
	.byte \battler
	.byte \type
	.byte \case
	.4byte \ptr
	.endm

	.macro jumpiftype battler:req, type:req, ptr:req
	jumpbasedontype \battler, \type, 1, \ptr
	.endm

	.macro jumpifnottype battler:req, type:req, ptr:req
	jumpbasedontype \battler, \type, 0, \ptr
	.endm

	.macro getexp battler:req
	.byte 0x23
	.byte \battler
	.endm

	.macro checkteamslost ptr:req
	.byte 0x24
	.4byte \ptr
	.endm

	.macro movevaluescleanup
	.byte 0x25
	.endm

	.macro setmultihit value:req
	.byte 0x26
	.byte \value
	.endm

	.macro decrementmultihit value:req
	.byte 0x27
	.4byte \value
	.endm

	.macro goto ptr:req
	.byte 0x28
	.4byte \ptr
	.endm

	.macro jumpifbyte ifflag:req, val:req, byte:req, ptr:req
	.byte 0x29
	.byte \ifflag
	.4byte \val
	.byte \byte
	.4byte \ptr
	.endm

	.macro jumpifhalfword ifflag:req, val:req, hword:req, ptr:req
	.byte 0x2a
	.byte \ifflag
	.4byte \val
	.2byte \hword
	.4byte \ptr
	.endm

	.macro jumpifword ifflag:req, val:req, word:req, ptr:req
	.byte 0x2b
	.byte \ifflag
	.4byte \val
	.4byte \word
	.4byte \ptr
	.endm

	.macro jumpifarrayequal val1:req, val2:req, size:req, ptr:req
	.byte 0x2c
	.4byte \val1
	.4byte \val2
	.byte \size
	.4byte \ptr
	.endm

	.macro jumpifarraynotequal val1:req, val2:req, size:req, ptr:req
	.byte 0x2d
	.4byte \val1
	.4byte \val2
	.byte \size
	.4byte \ptr
	.endm

	.macro setbyte ptr:req, byte:req
	.byte 0x2e
	.4byte \ptr
	.byte \byte
	.endm

	.macro addbyte ptr:req, byte:req
	.byte 0x2f
	.4byte \ptr
	.byte \byte
	.endm

	.macro subbyte ptr:req, byte:req
	.byte 0x30
	.4byte \ptr
	.byte \byte
	.endm

	.macro copyarray dest:req, src:req, size:req
	.byte 0x31
	.4byte \dest
	.4byte \src
	.byte \size
	.endm

	.macro copyarraywithindex dest:req, src:req, index:req, size:req
	.byte 0x32
	.4byte \dest
	.4byte \src
	.4byte \index
	.byte \size
	.endm

	.macro orbyte ptr:req, byte:req
	.byte 0x33
	.4byte \ptr
	.byte \byte
	.endm

	.macro orhalfword ptr:req, hword:req
	.byte 0x34
	.4byte \ptr
	.2byte \hword
	.endm

	.macro orword ptr:req, word:req
	.byte 0x35
	.4byte \ptr
	.4byte \word
	.endm

	.macro bicbyte ptr:req, byte:req
	.byte 0x36
	.4byte \ptr
	.byte \byte
	.endm

	.macro bichalfword ptr:req, hword:req
	.byte 0x37
	.4byte \ptr
	.2byte \hword
	.endm

	.macro bicword ptr:req, word:req
	.byte 0x38
	.4byte \ptr
	.4byte \word
	.endm

	.macro pause time:req
	.byte 0x39
	.2byte \time
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

	.macro jumpifaffectedbyprotect ptr:req
	.byte 0x40
	.4byte \ptr
	.endm

	.macro call ptr:req
	.byte 0x41
	.4byte \ptr
	.endm

	.macro setroost
	.byte 0x42
	.endm

	.macro jumpifabilitypresent ability:req, ptr:req
	.byte 0x43
	.2byte \ability
	.4byte \ptr
	.endm

	.macro endselectionscript
	.byte 0x44
	.endm

	.macro playanimation battler:req, animType:req, arg=NULL
	.byte 0x45
	.byte \battler
	.byte \animType
	.4byte \arg
	.endm

	.macro playanimation_var battler:req, animType:req, arg=NULL
	.byte 0x46
	.byte \battler
	.4byte \animType
	.4byte \arg
	.endm

	.macro setgraphicalstatchangevalues
	.byte 0x47
	.endm

	.macro playstatchangeanimation battler:req, stats:req, statchange:req
	.byte 0x48
	.byte \battler
	.byte \stats
	.byte \statchange
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

	.macro sethealblock ptr:req
	.byte 0x4a
	.4byte \ptr
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

	.macro switchinanim battler:req, dontclearsubstitutebit:req
	.byte 0x4e
	.byte \battler
	.byte \dontclearsubstitutebit
	.endm

	.macro jumpifcantswitch battler:req, ptr:req
	.byte 0x4f
	.byte \battler
	.4byte \ptr
	.endm

	.macro openpartyscreen battler:req, ptr:req
	.byte 0x50
	.byte \battler
	.4byte \ptr
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

	.macro returntoball battler:req
	.byte 0x58
	.byte \battler
	.endm

	.macro handlelearnnewmove learnedMovePtr:req, nothingToLearnPtr:req, isFirstMove:req
	.byte 0x59
	.4byte \learnedMovePtr
	.4byte \nothingToLearnPtr
	.byte \isFirstMove
	.endm

	.macro yesnoboxlearnmove forgotMovePtr:req
	.byte 0x5a
	.4byte \forgotMovePtr
	.endm

	.macro yesnoboxstoplearningmove noPtr:req
	.byte 0x5b
	.4byte \noPtr
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

	.macro setgravity ptr:req
	.byte 0x69
	.4byte \ptr
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

	.macro jumpifplayerran ptr:req
	.byte 0x72
	.4byte \ptr
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

	.macro jumpifnexttargetvalid ptr:req
	.byte 0x7a
	.4byte \ptr
	.endm

	.macro tryhealhalfhealth ptr:req, battler:req
	.byte 0x7b
	.4byte \ptr
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

	.macro trysetrest ptr:req
	.byte 0x81
	.4byte \ptr
	.endm

	.macro jumpifnotfirstturn ptr:req
	.byte 0x82
	.4byte \ptr
	.endm

	.macro setmiracleeye ptr:req
	.byte 0x83
	.4byte \ptr
	.endm

	.macro jumpifcantmakeasleep ptr:req
	.byte 0x84
	.4byte \ptr
	.endm

	.macro stockpile id:req
	.byte 0x85
	.byte \id
	.endm

	.macro stockpiletobasedamage ptr:req
	.byte 0x86
	.4byte \ptr
	.endm

	.macro stockpiletohpheal ptr:req
	.byte 0x87
	.4byte \ptr
	.endm

	.macro setdrainedhp
	.byte 0x88
	.endm

	.macro statbuffchange flags:req, jumpptr:req
	.byte 0x89
	.2byte \flags
	.4byte \jumpptr
	.endm

	.macro normalisebuffs
	.byte 0x8a
	.endm

	.macro setbide
	.byte 0x8b
	.endm

	.macro confuseifrepeatingattackends
	.byte 0x8c
	.endm

	.macro setmultihitcounter val:req
	.byte 0x8d
	.byte \val
	.endm

	.macro initmultihitstring
	.byte 0x8e
	.endm

	.macro forcerandomswitch ptr:req
	.byte 0x8f
	.4byte \ptr
	.endm

	.macro tryconversiontypechange ptr:req
	.byte 0x90
	.4byte \ptr
	.endm

	.macro givepaydaymoney
	.byte 0x91
	.endm

	.macro setlightscreen
	.byte 0x92
	.endm

	.macro tryKO ptr:req
	.byte 0x93
	.4byte \ptr
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

	.macro tryinfatuating ptr:req
	.byte 0x97
	.4byte \ptr
	.endm

	.macro updatestatusicon battler:req
	.byte 0x98
	.byte \battler
	.endm

	.macro setmist
	.byte 0x99
	.endm

	.macro setfocusenergy
	.byte 0x9a
	.endm

	.macro transformdataexecution
	.byte 0x9b
	.endm

	.macro setsubstitute
	.byte 0x9c
	.endm

	.macro mimicattackcopy ptr:req
	.byte 0x9d
	.4byte \ptr
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

	.macro counterdamagecalculator ptr:req
	.byte 0xa1
	.4byte \ptr
	.endm

	.macro mirrorcoatdamagecalculator ptr:req
	.byte 0xa2
	.4byte \ptr
	.endm

	.macro disablelastusedattack ptr:req
	.byte 0xa3
	.4byte \ptr
	.endm

	.macro trysetencore ptr:req
	.byte 0xa4
	.4byte \ptr
	.endm

	.macro painsplitdmgcalc ptr:req
	.byte 0xa5
	.4byte \ptr
	.endm

	.macro settypetorandomresistance ptr:req
	.byte 0xa6
	.4byte \ptr
	.endm

	.macro setalwayshitflag
	.byte 0xa7
	.endm

	.macro copymovepermanently ptr:req
	.byte 0xa8
	.4byte \ptr
	.endm

	.macro trychoosesleeptalkmove ptr:req
	.byte 0xa9
	.4byte \ptr
	.endm

	.macro setdestinybond
	.byte 0xaa
	.endm

	.macro trysetdestinybondtohappen
	.byte 0xab
	.endm

	.macro settailwind ptr:req
	.byte 0xac
	.4byte \ptr
	.endm

	.macro tryspiteppreduce ptr:req
	.byte 0xad
	.4byte \ptr
	.endm

	.macro healpartystatus
	.byte 0xae
	.endm

	.macro cursetarget ptr:req
	.byte 0xaf
	.4byte \ptr
	.endm

	.macro trysetspikes ptr:req
	.byte 0xb0
	.4byte \ptr
	.endm

	.macro setforesight
	.byte 0xb1
	.endm

	.macro trysetperishsong ptr:req
	.byte 0xb2
	.4byte \ptr
	.endm

	.macro handlerollout
	.byte 0xb3
	.endm

	.macro jumpifconfusedandstatmaxed stat:req, ptr:req
	.byte 0xb4
	.byte \stat
	.4byte \ptr
	.endm

	.macro handlefurycutter
	.byte 0xb5
	.endm

	.macro setembargo ptr:req
	.byte 0xb6
	.4byte \ptr
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

	.macro jumpifnopursuitswitchdmg ptr:req
	.byte 0xba
	.4byte \ptr
	.endm

	.macro setsunny
	.byte 0xbb
	.endm

	.macro maxattackhalvehp ptr:req
	.byte 0xbc
	.4byte \ptr
	.endm

	.macro copyfoestats ptr:req
	.byte 0xbd
	.4byte \ptr
	.endm

	.macro rapidspinfree
	.byte 0xbe
	.endm

	.macro setdefensecurlbit
	.byte 0xbf
	.endm

	.macro recoverbasedonsunlight ptr:req
	.byte 0xc0
	.4byte \ptr
	.endm

	.macro setstickyweb ptr:req
	.byte 0xc1
	.4byte \ptr
	.endm

	.macro selectfirstvalidtarget
	.byte 0xc2
	.endm

	.macro trysetfutureattack ptr:req
	.byte 0xc3
	.4byte \ptr
	.endm

	.macro trydobeatup endPtr:req, failPtr:req
	.byte 0xc4
	.4byte \endPtr
	.4byte \failPtr
	.endm

	.macro setsemiinvulnerablebit
	.byte 0xc5
	.endm

	.macro clearsemiinvulnerablebit
	.byte 0xc6
	.endm

	.macro setminimize
	.byte 0xc7
	.endm

	.macro sethail
	.byte 0xc8
	.endm

	.macro trymemento ptr:req
	.byte 0xc9
	.4byte \ptr
	.endm

	.macro setforcedtarget
	.byte 0xca
	.endm

	.macro setcharge
	.byte 0xcb
	.endm

	.macro callterrainattack
	.byte 0xcc
	.endm

	.macro cureifburnedparalysedorpoisoned ptr:req
	.byte 0xcd
	.4byte \ptr
	.endm

	.macro settorment ptr:req
	.byte 0xce
	.4byte \ptr
	.endm

	.macro jumpifnodamage ptr:req
	.byte 0xcf
	.4byte \ptr
	.endm

	.macro settaunt ptr:req
	.byte 0xd0
	.4byte \ptr
	.endm

	.macro trysethelpinghand ptr:req
	.byte 0xd1
	.4byte \ptr
	.endm

	.macro tryswapitems ptr:req
	.byte 0xd2
	.4byte \ptr
	.endm

	.macro trycopyability ptr:req
	.byte 0xd3
	.4byte \ptr
	.endm

	.macro trywish turnNumber:req, ptr:req
	.byte 0xd4
	.byte \turnNumber
	.4byte \ptr
	.endm

	.macro settoxicspikes ptr:req
	.byte 0xd5
	.4byte \ptr
	.endm

	.macro setgastroacid ptr:req
	.byte 0xd6
	.4byte \ptr
	.endm

	.macro setyawn ptr:req
	.byte 0xd7
	.4byte \ptr
	.endm

	.macro setdamagetohealthdifference ptr:req
	.byte 0xd8
	.4byte \ptr
	.endm

	.macro setroom
	.byte 0xd9
	.endm

	.macro tryswapabilities ptr:req
	.byte 0xda
	.4byte \ptr
	.endm

	.macro tryimprison ptr:req
	.byte 0xdb
	.4byte \ptr
	.endm

	.macro setstealthrock ptr:req
	.byte 0xdc
	.4byte \ptr
	.endm

	.macro setuserstatus3 flags:req, ptr:req
	.byte 0xdd
	.4byte \flags
	.4byte \ptr
	.endm

	.macro assistattackselect ptr:req
	.byte 0xde
	.4byte \ptr
	.endm

	.macro trysetmagiccoat ptr:req
	.byte 0xdf
	.4byte \ptr
	.endm

	.macro trysetsnatch ptr:req
	.byte 0xe0
	.4byte \ptr
	.endm

	.macro trygetintimidatetarget ptr:req
	.byte 0xe1
	.4byte \ptr
	.endm

	.macro switchoutabilities battler:req
	.byte 0xe2
	.byte \battler
	.endm

	.macro jumpifhasnohp battler:req, ptr:req
	.byte 0xe3
	.byte \battler
	.4byte \ptr
	.endm

	.macro getsecretpowereffect
	.byte 0xe4
	.endm

	.macro pickup
	.byte 0xe5
	.endm

	.macro doweatherformchangeanimation
	.byte 0xe6
	.endm

	.macro tryweatherformdatachange
	.byte 0xe7
	.endm

	.macro settypebasedhalvers ptr:req
	.byte 0xe8
	.4byte \ptr
	.endm

	.macro jumpifsubstituteblocks ptr:req
	.byte 0xe9
	.4byte \ptr
	.endm

	.macro tryrecycleitem ptr:req
	.byte 0xea
	.4byte \ptr
	.endm

	.macro settypetoterrain ptr:req
	.byte 0xeb
	.4byte \ptr
	.endm

	.macro pursuitdoubles ptr:req
	.byte 0xec
	.4byte \ptr
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

	.macro trysetcaughtmondexflags ptr:req
	.byte 0xf1
	.4byte \ptr
	.endm

	.macro displaydexinfo
	.byte 0xf2
	.endm

	.macro trygivecaughtmonnick ptr:req
	.byte 0xf3
	.4byte \ptr
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

	.macro settelekinesis ptr:req
	.byte 0xf9
	.4byte \ptr
	.endm

	.macro swapstatstages stat:req
	.byte 0xfa
	.byte \stat
	.endm

	.macro averagestats stat:req
	.byte 0xfb
	.byte \stat
	.endm

	.macro jumpifoppositegenders ptr:req
	.byte 0xfc
	.4byte \ptr
	.endm

	.macro trygetbaddreamstarget ptr:req
	.byte 0xfd
	.4byte \ptr
	.endm

	.macro tryworryseed ptr:req
	.byte 0xfe
	.4byte \ptr
	.endm

	.macro metalburstdamagecalculator ptr:req
	.byte 0xff
	.4byte \ptr
	.endm

@ various command changed to more readable macros
	.macro cancelmultiturnmoves battler:req
	various \battler, VARIOUS_CANCEL_MULTI_TURN_MOVES
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

	.macro resetintimidatetracebits battler:req
	various \battler, VARIOUS_RESET_INTIMIDATE_TRACE_BITS
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

	.macro setluckychant battler:req, ptr:req
	various \battler VARIOUS_SET_LUCKY_CHANT
	.4byte \ptr
	.endm

	.macro suckerpunchcheck ptr:req
	various BS_ATTACKER, VARIOUS_SUCKER_PUNCH_CHECK
	.4byte \ptr
	.endm

	.macro setabilitysimple battler:req, ptr:req
	various \battler VARIOUS_SET_SIMPLE_BEAM
	.4byte \ptr
	.endm

	.macro tryentrainment ptr:req
	various BS_ATTACKER, VARIOUS_TRY_ENTRAINMENT
	.4byte \ptr
	.endm

	.macro setlastusedability battler:req
	various \battler, VARIOUS_SET_LAST_USED_ABILITY
	.endm

	.macro tryhealpulse battler:req, ptr:req
	various \battler, VARIOUS_TRY_HEAL_PULSE
	.4byte \ptr
	.endm

	.macro tryquash ptr:req
	various BS_ATTACKER, VARIOUS_TRY_QUASH
	.4byte \ptr
	.endm

	.macro tryafteryou ptr:req
	various BS_ATTACKER, VARIOUS_AFTER_YOU
	.4byte \ptr
	.endm

	.macro trybestow ptr:req
	various BS_ATTACKER, VARIOUS_BESTOW
	.4byte \ptr
	.endm

	.macro invertstatstages battler:req
	various \battler, VARIOUS_INVERT_STAT_STAGES
	.endm

	.macro setterrain ptr:req
	various BS_ATTACKER, VARIOUS_SET_TERRAIN
	.4byte \ptr
	.endm

	.macro trymefirst ptr:req
	various BS_ATTACKER, VARIOUS_TRY_ME_FIRST
	.4byte \ptr
	.endm

	.macro jumpifbattleend ptr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_BATTLE_END
	.4byte \ptr
	.endm

	.macro tryelectrify ptr:req
	various BS_ATTACKER, VARIOUS_TRY_ELECTRIFY
	.4byte \ptr
	.endm

	.macro tryreflecttype ptr:req
	various BS_ATTACKER, VARIOUS_TRY_REFLECT_TYPE
	.4byte \ptr
	.endm

	.macro trysoak ptr:req
	various BS_ATTACKER, VARIOUS_TRY_SOAK
	.4byte \ptr
	.endm

	.macro handlemegaevo battler:req, case:req
	various \battler, VARIOUS_HANDLE_MEGA_EVO
	.byte \case
	.endm

	.macro handleprimalreversion battler:req, case:req
	various \battler, VARIOUS_HANDLE_PRIMAL_REVERSION
	.byte \case
	.endm

	.macro handleformchange battler:req, case:req
	various \battler, VARIOUS_HANDLE_FORM_CHANGE
	.byte \case
	.endm

	.macro jumpifcantuselastresort battler:req, ptr:req
	various \battler, VARIOUS_TRY_LAST_RESORT
	.4byte \ptr
	.endm

	.macro argumentstatuseffect
	various BS_ATTACKER, VARIOUS_ARGUMENT_STATUS_EFFECT
	.endm

	.macro tryhitswitchtarget ptr:req
	various BS_ATTACKER, VARIOUS_TRY_HIT_SWITCH_TARGET
	.4byte \ptr
	.endm

	.macro tryautotomize battler:req, ptr:req
	various \battler, VARIOUS_TRY_AUTOTOMIZE
	.4byte \ptr
	.endm

	.macro jumpifcantusesynchronoise ptr:req
	various BS_ATTACKER, VARIOUS_TRY_SYNCHRONOISE
	.4byte \ptr
	.endm

	.macro trycopycat ptr:req
	various BS_ATTACKER, VARIOUS_TRY_COPYCAT
	.4byte \ptr
	.endm

	.macro showabilitypopup battler:req
	various \battler, VARIOUS_ABILITY_POPUP
	.endm

	.macro updateabilitypopup battler:req
	various \battler, VARIOUS_UPDATE_ABILITY_POPUP
	.endm

	.macro defogclear battler:req, clear:req, ptr:req
	various \battler, VARIOUS_DEFOG
	.byte \clear
	.4byte \ptr
	.endm

	.macro jumpiftargetally ptr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_TARGET_ALLY
	.4byte \ptr
	.endm

	.macro trypsychoshift ptr:req
	various BS_ATTACKER, VARIOUS_PSYCHO_SHIFT
	.4byte \ptr
	.endm

	.macro curestatus battler:req
	various \battler, VARIOUS_CURE_STATUS
	.endm

	.macro powertrick battler:req
	various \battler, VARIOUS_POWER_TRICK
	.endm

	.macro argumenttomoveeffect
	various BS_ATTACKER, VARIOUS_ARGUMENT_TO_MOVE_EFFECT
	.endm

	.macro jumpifnotgrounded battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_NOT_GROUNDED
	.4byte \ptr
	.endm

	.macro handletrainerslidemsg battler:req, field:req
	various \battler, VARIOUS_HANDLE_TRAINER_SLIDE_MSG
	.byte \field
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

	.macro trysetthirdtype battler:req, ptr:req
	various \battler, VARIOUS_TRY_THIRD_TYPE
	.4byte \ptr
	.endm

	.macro tryaccupressure battler:req, ptr:req
	various \battler, VARIOUS_ACUPRESSURE
	.4byte \ptr
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

	.macro checkgrassyterrainheal battler:req, ptr:req
	various \battler, VARIOUS_CHECK_IF_GRASSY_TERRAIN_HEALS
	.4byte \ptr
	.endm

	.macro jumpifnotberry battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_NOT_BERRY
	.4byte \ptr
	.endm

	.macro jumpifroarfails ptr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_ROAR_FAILS
	.4byte \ptr
	.endm

	.macro tryinstruct ptr:req
	various BS_ATTACKER, VARIOUS_TRY_INSTRUCT
	.4byte \ptr
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

	.macro spriteignore0hp val:req
	various BS_ATTACKER, VARIOUS_SET_SPRITEIGNORE0HP
	.byte \val
	.endm

	.macro getstatvalue battler:req, statId:req
	various \battler, VARIOUS_GET_STAT_VALUE
	.byte \statId
	.endm

	.macro jumpiffullhp battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_FULL_HP
	.4byte \ptr
	.endm

	.macro losetype battler:req, type:req
	various \battler, VARIOUS_LOSE_TYPE
	.byte \type
	.endm

	.macro tryfriskmsg battler:req
	various \battler, VARIOUS_TRY_FRISK
	.endm

	.macro jumpifshieldsdown battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_SHIELDS_DOWN_PROTECTED
	.4byte \ptr
	.endm

	.macro trypoisontype attacker:req, target:req, ptr:req
	various \attacker, VARIOUS_POISON_TYPE_IMMUNITY
	.byte \target
	.4byte \ptr
	.endm

	.macro tryparalyzetype attacker:req, target:req, ptr:req
	various \attacker, VARIOUS_PARALYZE_TYPE_IMMUNITY
	.byte \target
	.4byte \ptr
	.endm

	.macro trysetfairylock ptr:req
	various BS_ATTACKER, VARIOUS_TRY_FAIRY_LOCK
	.4byte \ptr
	.endm

	.macro jumpifnoally battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_NO_ALLY
	.4byte \ptr
	.endm

	.macro jumpifnoholdeffect battler:req, holdEffet:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_NO_HOLD_EFFECT
	.byte \holdEffet
	.4byte \ptr
	.endm

	.macro infatuatewithbattler battler1:req, battler2:req
	various \battler1, VARIOUS_INFATUATE_WITH_BATTLER
	.byte \battler2
	.endm

	.macro setlastuseditem battler:req
	various \battler, VARIOUS_SET_LAST_USED_ITEM
	.endm

	.macro jumpifabsent battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_ABSENT
	.4byte \ptr
	.endm

	.macro destroyabilitypopup
	various BS_ABILITY_BATTLER, VARIOUS_DESTROY_ABILITY_POPUP
	.endm

	.macro gettotemboost ptr:req
	various BS_ATTACKER, VARIOUS_TOTEM_BOOST
	.4byte \ptr
	.endm

	.macro tryactivategrimneigh, battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_GRIM_NEIGH
	.endm

	.macro setzeffect
	various BS_ATTACKER, VARIOUS_SET_Z_EFFECT
	.endm

	.macro consumeberry battler:req, restoreItem=FALSE
	various \battler, VARIOUS_CONSUME_BERRY
	.byte \restoreItem
	.endm

	.macro activateitemeffects battler:req
	various \battler, VARIOUS_MOVEEND_ITEM_EFFECTS
	.endm

	.macro pickpocketsteal
	various 0, VARIOUS_PICKPOCKET
	.endm

	.macro doterrainseed battler:req, ptr:req
	various \battler, VARIOUS_TERRAIN_SEED
	.4byte \ptr
	.endm

	.macro makeinvisible battler:req
	various \battler, VARIOUS_MAKE_INVISIBLE
	.endm

	.macro tryroomservice battler:req, ptr:req
	various \battler, VARIOUS_ROOM_SERVICE
	.4byte \ptr
	.endm

	.macro jumpifterrainaffected battler:req, terrainFlags:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_TERRAIN_AFFECTED
	.4byte \terrainFlags
	.4byte \ptr
	.endm

	.macro jumpifpranksterblocked battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_PRANKSTER_BLOCKED
	.4byte \ptr
	.endm

	.macro eeriespellppreduce ptr:req
	various BS_TARGET, VARIOUS_EERIE_SPELL_PP_REDUCE
	.4byte \ptr
	.endm

	.macro jumpifteamhealthy battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_TEAM_HEALTHY
	.4byte \ptr
	.endm

	.macro tryhealquarterhealth battler:req, ptr:req
	various \battler, VARIOUS_TRY_HEAL_QUARTER_HP
	.4byte \ptr
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

	.macro getrototillertargets ptr:req
	various BS_ATTACKER, VARIOUS_GET_ROTOTILLER_TARGETS
	.4byte \ptr
	.endm

	.macro jumpifnotrototilleraffected battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_NOT_ROTOTILLER_AFFECTED
	.4byte \ptr
	.endm

	.macro tryactivatebattlebond battler:req
	various \battler, VARIOUS_TRY_ACTIVATE_BATTLE_BOND
	.endm

	.macro jumpifcantreverttoprimal ptr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_CANT_REVERT_TO_PRIMAL
	.4byte \ptr
	.endm

	.macro applyplasmafists
	various BS_ATTACKER, VARIOUS_APPLY_PLASMA_FISTS
	.endm

	.macro jumpifweatheraffected battler:req, weather:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_WEATHER_AFFECTED
	.4byte \weather
	.4byte \ptr
	.endm

	.macro jumpifspecies battler:req, species:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_SPECIES
	.2byte \species
	.4byte \ptr
	.endm

	.macro tryendneutralizinggas battler:req
	various \battler, VARIOUS_TRY_END_NEUTRALIZING_GAS
	.endm

	.macro trytoapplymimicry battler:req, ptr:req
	various \battler, VARIOUS_TRY_TO_APPLY_MIMICRY
	.4byte \ptr
	.endm

	.macro trynoretreat battler:req, ptr:req
	various \battler, VARIOUS_TRY_NO_RETREAT
	.4byte \ptr
	.endm

	.macro trytarshot battler:req, ptr:req
	various \battler, VARIOUS_TRY_TAR_SHOT
	.4byte \ptr
	.endm

	.macro cantarshotwork battler:req, ptr:req
	various \battler, VARIOUS_CAN_TAR_SHOT_WORK
	.4byte \ptr
	.endm

	.macro checkpoltergeist battler:req, ptr:req
	various \battler, VARIOUS_CHECK_POLTERGEIST
	.4byte \ptr
	.endm

	.macro setoctolock battler:req, ptr:req
	various \battler, VARIOUS_SET_OCTOLOCK
	.4byte \ptr
	.endm

	.macro cutonethirdhpraisestats ptr:req
	various BS_ATTACKER, VARIOUS_CUT_1_3_HP_RAISE_STATS
	.4byte \ptr
	.endm

	.macro photongeysercheck battler:req
	various \battler, VARIOUS_PHOTON_GEYSER_CHECK
	.endm

	.macro shellsidearmcheck
	various BS_ATTACKER, VARIOUS_SHELL_SIDE_ARM_CHECK
	.endm

	.macro jumpifcantfling battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_CANT_FLING
	.4byte \ptr
	.endm

	.macro curecertainstatuses battler:req
	various \battler, VARIOUS_CURE_CERTAIN_STATUSES
	.endm

	.macro tryresetnegativestatstages battler:req
	various \battler, VARIOUS_TRY_RESET_NEGATIVE_STAT_STAGES
	.endm

	.macro jumpiflastuseditemberry ptr:req
	various BS_ATTACKER, VARIOUS_JUMP_IF_LAST_USED_ITEM_BERRY
	.4byte \ptr
	.endm

	.macro jumpiflastuseditemholdeffect battler:req, holdEffect:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_LAST_USED_ITEM_HOLD_EFFECT
	.byte \holdEffect
	.4byte \ptr
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

	.macro canteleport battler:req
	various \battler, VARIOUS_CAN_TELEPORT
	.endm

	.macro getbattlerside battler:req
	various \battler, VARIOUS_GET_BATTLER_SIDE
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

	.macro jumpifbytenotequal byte1:req, byte2:req, jumpptr:req
	jumpifarraynotequal \byte1, \byte2, 0x1, \jumpptr
	.endm

	.macro jumpifbyteequal byte1:req, byte2:req, jumpptr:req
	jumpifarrayequal \byte1, \byte2, 0x1, \jumpptr
	.endm

	.macro jumpifmove move:req, jumpptr:req
	jumpifhalfword CMP_EQUAL, gCurrentMove, \move, \jumpptr
	.endm

	.macro jumpifnotmove move:req, jumpptr:req
	jumpifhalfword CMP_NOT_EQUAL, gCurrentMove, \move, \jumpptr
	.endm

	.macro jumpifnotchosenmove move:req, jumpptr:req
	jumpifhalfword CMP_NOT_EQUAL, gChosenMove, \move, \jumpptr
	.endm

	.macro jumpifstatus3 battler:req, status:req, jumpptr:req
	jumpifstatus3condition \battler, \status, FALSE, \jumpptr
	.endm

	.macro jumpifnostatus3 battler:req, status:req, jumpptr:req
	jumpifstatus3condition \battler, \status, TRUE, \jumpptr
	.endm

	.macro jumpifmovehadnoeffect jumpptr:req
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_NO_EFFECT, \jumpptr
	.endm

	.macro jumpifbattletype flags:req, jumpptr:req
	jumpifword CMP_COMMON_BITS, gBattleTypeFlags, \flags, \jumpptr
	.endm

	.macro jumpifnotbattletype flags:req, jumpptr:req
	jumpifword CMP_NO_COMMON_BITS, gBattleTypeFlags, \flags, \jumpptr
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

	.macro dmg_1_2_attackerhp
	manipulatedamage DMG_1_2_ATTACKER_HP
	.endm

	.macro jumpifflowerveil jumpptr:req
	jumpifnottype BS_TARGET, TYPE_GRASS, 1f
	jumpifability BS_TARGET_SIDE, ABILITY_FLOWER_VEIL, \jumpptr
	1:
	.endm

	.macro jumpifflowerveilattacker jumpptr:req
	jumpifnottype BS_ATTACKER, TYPE_GRASS, 1f
	jumpifability BS_ATTACKER_SIDE, ABILITY_FLOWER_VEIL, \jumpptr
	1:
	.endm

	.macro setallytonexttarget jumpptr:req
	jumpifbyte CMP_GREATER_THAN, gBattlerTarget, 0x1, 1f
	addbyte gBattlerTarget, 0x2
	goto \jumpptr
	1:
	subbyte gBattlerTarget, 0x2
	goto \jumpptr
	.endm

	.macro jumpifleafguardprotected battler:req, jumpptr:req
	various \battler, VARIOUS_JUMP_IF_LEAF_GUARD_PROTECTED
	.4byte \jumpptr
	.endm

	.macro jumpifsafeguard jumpptr:req
	jumpifability BS_ATTACKER, ABILITY_INFILTRATOR, 1f
	jumpifsideaffecting BS_TARGET, SIDE_STATUS_SAFEGUARD, \jumpptr
	1:
	.endm

	@ Will jump to script pointer if the target weighs less than 200 kg, or 441 lbs.
	.macro jumpifunder200 battler:req, ptr:req
	various \battler, VARIOUS_JUMP_IF_UNDER_200
	.4byte \ptr
	.endm

	@ Sets the sky drop status and does all other necessary operations
	.macro setskydrop
	various 0, VARIOUS_SET_SKY_DROP
	.endm

	@ Clears the sky drop status and does all other necessary operations.
	@ If the target fainted in before this script is called, it goes to the given script.
	.macro clearskydrop ptr:req
	various 0, VARIOUS_CLEAR_SKY_DROP
	.4byte \ptr
	.endm

	@ Accounts for if the target of Sky Drop was in confuse_lock when the attacker falls asleep due to Yawn.
	.macro skydropyawn
	various 0, VARIOUS_SKY_DROP_YAWN
	.endm

	@ Used by effects that may proc Symbiosis but do not call removeitem.
	.macro trysymbiosis
	various BS_ATTACKER, VARIOUS_TRY_SYMBIOSIS
	.endm
