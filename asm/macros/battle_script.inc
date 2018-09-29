@ commands
	.macro attackcanceler
	.byte 0x0
	.endm

	.macro accuracycheck param0, param1
	.byte 0x1
	.4byte \param0
	.2byte \param1
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

	.macro healthbarupdate battler
	.byte 0xb
	.byte \battler
	.endm

	.macro datahpupdate battler
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

	.macro printstring param0
	.byte 0x10
	.2byte \param0
	.endm

	.macro printselectionstring param0
	.byte 0x11
	.2byte \param0
	.endm

	.macro waitmessage param0
	.byte 0x12
	.2byte \param0
	.endm

	.macro printfromtable param0
	.byte 0x13
	.4byte \param0
	.endm

	.macro printselectionstringfromtable param0
	.byte 0x14
	.4byte \param0
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

	.macro clearstatusfromeffect battler
	.byte 0x18
	.byte \battler
	.endm

	.macro tryfaintmon battler, param1, param2
	.byte 0x19
	.byte \battler
	.byte \param1
	.4byte \param2
	.endm

	.macro dofaintanimation battler
	.byte 0x1a
	.byte \battler
	.endm

	.macro cleareffectsonfaint battler
	.byte 0x1b
	.byte \battler
	.endm

	.macro jumpifstatus battler, status1, param2
	.byte 0x1c
	.byte \battler
	.4byte \status1
	.4byte \param2
	.endm

	.macro jumpifstatus2 battler, status2, param2
	.byte 0x1d
	.byte \battler
	.4byte \status2
	.4byte \param2
	.endm

	.macro jumpifability param0, ability, param2
	.byte 0x1e
	.byte \param0
	.byte \ability
	.4byte \param2
	.endm

	.macro jumpifsideaffecting battler, sidestatus, param2
	.byte 0x1f
	.byte \battler
	.4byte \sidestatus
	.4byte \param2
	.endm

	.macro jumpifstat battler, ifflag, stat, param3, param4
	.byte 0x20
	.byte \battler
	.byte \ifflag
	.byte \stat
	.byte \param3
	.4byte \param4
	.endm

	.macro jumpifstatus3condition battler, status3, param2, param3
	.byte 0x21
	.byte \battler
	.4byte \status3
	.byte \param2
	.4byte \param3
	.endm

	.macro jumpiftype battler, type, param2
	.byte 0x22
	.byte \battler
	.byte \type
	.4byte \param2
	.endm

	.macro getexp battler
	.byte 0x23
	.byte \battler
	.endm

	.macro atk24 param0
	.byte 0x24
	.4byte \param0
	.endm

	.macro movevaluescleanup
	.byte 0x25
	.endm

	.macro setmultihit param0
	.byte 0x26
	.byte \param0
	.endm

	.macro decrementmultihit param0
	.byte 0x27
	.4byte \param0
	.endm

	.macro goto param0
	.byte 0x28
	.4byte \param0
	.endm

	.macro jumpifbyte ifflag, param1, param2, param3
	.byte 0x29
	.byte \ifflag
	.4byte \param1
	.byte \param2
	.4byte \param3
	.endm

	.macro jumpifhalfword ifflag, param1, param2, param3
	.byte 0x2a
	.byte \ifflag
	.4byte \param1
	.2byte \param2
	.4byte \param3
	.endm

	.macro jumpifword ifflag, param1, param2, param3
	.byte 0x2b
	.byte \ifflag
	.4byte \param1
	.4byte \param2
	.4byte \param3
	.endm

	.macro jumpifarrayequal param0, param1, param2, param3
	.byte 0x2c
	.4byte \param0
	.4byte \param1
	.byte \param2
	.4byte \param3
	.endm

	.macro jumpifarraynotequal param0, param1, param2, param3
	.byte 0x2d
	.4byte \param0
	.4byte \param1
	.byte \param2
	.4byte \param3
	.endm

	.macro setbyte param0, param1
	.byte 0x2e
	.4byte \param0
	.byte \param1
	.endm

	.macro addbyte param0, param1
	.byte 0x2f
	.4byte \param0
	.byte \param1
	.endm

	.macro subbyte param0, param1
	.byte 0x30
	.4byte \param0
	.byte \param1
	.endm

	.macro copyarray param0, param1, param2
	.byte 0x31
	.4byte \param0
	.4byte \param1
	.byte \param2
	.endm

	.macro copyarraywithindex param0, param1, param2, param3
	.byte 0x32
	.4byte \param0
	.4byte \param1
	.4byte \param2
	.byte \param3
	.endm

	.macro orbyte param0, param1
	.byte 0x33
	.4byte \param0
	.byte \param1
	.endm

	.macro orhalfword param0, param1
	.byte 0x34
	.4byte \param0
	.2byte \param1
	.endm

	.macro orword param0, param1
	.byte 0x35
	.4byte \param0
	.4byte \param1
	.endm

	.macro bicbyte param0, param1
	.byte 0x36
	.4byte \param0
	.byte \param1
	.endm

	.macro bichalfword param0, param1
	.byte 0x37
	.4byte \param0
	.2byte \param1
	.endm

	.macro bicword param0, param1
	.byte 0x38
	.4byte \param0
	.4byte \param1
	.endm

	.macro pause param0
	.byte 0x39
	.2byte \param0
	.endm

	.macro waitstate
	.byte 0x3a
	.endm

	.macro healthbar_update battler
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

	.macro jumpifaffectedbyprotect param0
	.byte 0x40
	.4byte \param0
	.endm

	.macro call param0
	.byte 0x41
	.4byte \param0
	.endm

	.macro setroost
	.byte 0x42
	.endm

	.macro jumpifabilitypresent ability, param1
	.byte 0x43
	.byte \ability
	.4byte \param1
	.endm

	.macro endselectionscript
	.byte 0x44
	.endm

	.macro playanimation battler, param1, param2
	.byte 0x45
	.byte \battler
	.byte \param1
	.4byte \param2
	.endm

	.macro playanimation2 battler, param1, param2
	.byte 0x46
	.byte \battler
	.4byte \param1
	.4byte \param2
	.endm

	.macro setgraphicalstatchangevalues
	.byte 0x47
	.endm

	.macro playstatchangeanimation battler, param1, param2
	.byte 0x48
	.byte \battler
	.byte \param1
	.byte \param2
	.endm

	.macro moveend param0, param1
	.byte 0x49
	.byte \param0
	.byte \param1
	.endm

	.macro sethealblock ptr
	.byte 0x4a
	.4byte \ptr
	.endm

	.macro returnatktoball
	.byte 0x4b
	.endm

	.macro getswitchedmondata battler
	.byte 0x4c
	.byte \battler
	.endm

	.macro switchindataupdate battler
	.byte 0x4d
	.byte \battler
	.endm

	.macro switchinanim battler, dontclearsubstitutebit
	.byte 0x4e
	.byte \battler
	.byte \dontclearsubstitutebit
	.endm

	.macro jumpifcantswitch battler, param1
	.byte 0x4f
	.byte \battler
	.4byte \param1
	.endm

	.macro openpartyscreen param0, param1
	.byte 0x50
	.byte \param0
	.4byte \param1
	.endm

	.macro switchhandleorder battler, param1
	.byte 0x51
	.byte \battler
	.byte \param1
	.endm

	.macro switchineffects battler
	.byte 0x52
	.byte \battler
	.endm

	.macro trainerslidein battler
	.byte 0x53
	.byte \battler
	.endm

	.macro playse param0
	.byte 0x54
	.2byte \param0
	.endm

	.macro fanfare param0
	.byte 0x55
	.2byte \param0
	.endm

	.macro playfaintcry battler
	.byte 0x56
	.byte \battler
	.endm

	.macro atk57
	.byte 0x57
	.endm

	.macro returntoball battler
	.byte 0x58
	.byte \battler
	.endm

	.macro handlelearnnewmove param0, param1, param2
	.byte 0x59
	.4byte \param0
	.4byte \param1
	.byte \param2
	.endm

	.macro yesnoboxlearnmove param0
	.byte 0x5a
	.4byte \param0
	.endm

	.macro yesnoboxstoplearningmove param0
	.byte 0x5b
	.4byte \param0
	.endm

	.macro hitanimation battler
	.byte 0x5c
	.byte \battler
	.endm

	.macro getmoneyreward
	.byte 0x5d
	.endm

	.macro atk5E battler
	.byte 0x5e
	.byte \battler
	.endm

	.macro swapattackerwithtarget
	.byte 0x5f
	.endm

	.macro incrementgamestat param0
	.byte 0x60
	.byte \param0
	.endm

	.macro drawpartystatussummary battler
	.byte 0x61
	.byte \battler
	.endm

	.macro hidepartystatussummary battler
	.byte 0x62
	.byte \battler
	.endm

	.macro jumptocalledmove param0
	.byte 0x63
	.byte \param0
	.endm

	.macro statusanimation battler
	.byte 0x64
	.byte \battler
	.endm

	.macro status2animation battler, status2
	.byte 0x65
	.byte \battler
	.4byte \status2
	.endm

	.macro chosenstatusanimation battler, param1, param2
	.byte 0x66
	.byte \battler
	.byte \param1
	.4byte \param2
	.endm

	.macro yesnobox
	.byte 0x67
	.endm

	.macro cancelallactions
	.byte 0x68
	.endm

	.macro setgravity ptr
	.byte 0x69
	.4byte \ptr
	.endm

	.macro removeitem battler
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

	.macro makevisible battler
	.byte 0x6f
	.byte \battler
	.endm

	.macro recordability battler
	.byte 0x70
	.byte \battler
	.endm

	.macro buffermovetolearn
	.byte 0x71
	.endm

	.macro jumpifplayerran param0
	.byte 0x72
	.4byte \param0
	.endm

	.macro hpthresholds battler
	.byte 0x73
	.byte \battler
	.endm

	.macro hpthresholds2 battler
	.byte 0x74
	.byte \battler
	.endm

	.macro useitemonopponent
	.byte 0x75
	.endm

	.macro various battler, param1
	.byte 0x76
	.byte \battler
	.byte \param1
	.endm

	.macro setprotectlike
	.byte 0x77
	.endm

	.macro faintifabilitynotdamp
	.byte 0x78
	.endm

	.macro setatkhptozero
	.byte 0x79
	.endm

	.macro jumpifnexttargetvalid param0
	.byte 0x7a
	.4byte \param0
	.endm

	.macro tryhealhalfhealth param0, battler
	.byte 0x7b
	.4byte \param0
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

	.macro manipulatedamage param0
	.byte 0x80
	.byte \param0
	.endm

	.macro trysetrest param0
	.byte 0x81
	.4byte \param0
	.endm

	.macro jumpifnotfirstturn param0
	.byte 0x82
	.4byte \param0
	.endm

	.macro setmiracleeye ptr
	.byte 0x83
	.4byte \ptr
	.endm

	.macro jumpifcantmakeasleep param0
	.byte 0x84
	.4byte \param0
	.endm

	.macro stockpile
	.byte 0x85
	.endm

	.macro stockpiletobasedamage param0
	.byte 0x86
	.4byte \param0
	.endm

	.macro stockpiletohpheal param0
	.byte 0x87
	.4byte \param0
	.endm

	.macro setdrainedhp
	.byte 0x88
	.endm

	.macro statbuffchange param0, param1
	.byte 0x89
	.byte \param0
	.4byte \param1
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

	.macro setmultihitcounter param0
	.byte 0x8d
	.byte \param0
	.endm

	.macro initmultihitstring
	.byte 0x8e
	.endm

	.macro forcerandomswitch param0
	.byte 0x8f
	.4byte \param0
	.endm

	.macro tryconversiontypechange param0
	.byte 0x90
	.4byte \param0
	.endm

	.macro givepaydaymoney
	.byte 0x91
	.endm

	.macro setlightscreen
	.byte 0x92
	.endm

	.macro tryKO param0
	.byte 0x93
	.4byte \param0
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

	.macro tryinfatuating param0
	.byte 0x97
	.4byte \param0
	.endm

	.macro updatestatusicon battler
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

	.macro mimicattackcopy param0
	.byte 0x9d
	.4byte \param0
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

	.macro counterdamagecalculator param0
	.byte 0xa1
	.4byte \param0
	.endm

	.macro mirrorcoatdamagecalculator param0
	.byte 0xa2
	.4byte \param0
	.endm

	.macro disablelastusedattack param0
	.byte 0xa3
	.4byte \param0
	.endm

	.macro trysetencore param0
	.byte 0xa4
	.4byte \param0
	.endm

	.macro painsplitdmgcalc param0
	.byte 0xa5
	.4byte \param0
	.endm

	.macro settypetorandomresistance param0
	.byte 0xa6
	.4byte \param0
	.endm

	.macro setalwayshitflag
	.byte 0xa7
	.endm

	.macro copymovepermanently param0
	.byte 0xa8
	.4byte \param0
	.endm

	.macro trychoosesleeptalkmove param0
	.byte 0xa9
	.4byte \param0
	.endm

	.macro setdestinybond
	.byte 0xaa
	.endm

	.macro trysetdestinybondtohappen
	.byte 0xab
	.endm

	.macro settailwind ptr
	.byte 0xac
	.4byte \ptr
	.endm

	.macro tryspiteppreduce param0
	.byte 0xad
	.4byte \param0
	.endm

	.macro healpartystatus
	.byte 0xae
	.endm

	.macro cursetarget param0
	.byte 0xaf
	.4byte \param0
	.endm

	.macro trysetspikes param0
	.byte 0xb0
	.4byte \param0
	.endm

	.macro setforesight
	.byte 0xb1
	.endm

	.macro trysetperishsong param0
	.byte 0xb2
	.4byte \param0
	.endm

	.macro handlerollout
	.byte 0xb3
	.endm

	.macro jumpifconfusedandstatmaxed stat, param1
	.byte 0xb4
	.byte \stat
	.4byte \param1
	.endm

	.macro handlefurycutter
	.byte 0xb5
	.endm

	.macro setembargo ptr
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

	.macro jumpifnopursuitswitchdmg param0
	.byte 0xba
	.4byte \param0
	.endm

	.macro setsunny
	.byte 0xbb
	.endm

	.macro maxattackhalvehp param0
	.byte 0xbc
	.4byte \param0
	.endm

	.macro copyfoestats param0
	.byte 0xbd
	.4byte \param0
	.endm

	.macro rapidspinfree
	.byte 0xbe
	.endm

	.macro setdefensecurlbit
	.byte 0xbf
	.endm

	.macro recoverbasedonsunlight param0
	.byte 0xc0
	.4byte \param0
	.endm

	.macro setstickyweb ptr
	.byte 0xc1
	.4byte \ptr
	.endm

	.macro selectfirstvalidtarget
	.byte 0xc2
	.endm

	.macro trysetfutureattack param0
	.byte 0xc3
	.4byte \param0
	.endm

	.macro trydobeatup param0, param1
	.byte 0xc4
	.4byte \param0
	.4byte \param1
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

	.macro jumpifattackandspecialattackcannotfall param0
	.byte 0xc9
	.4byte \param0
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

	.macro cureifburnedparalysedorpoisoned param0
	.byte 0xcd
	.4byte \param0
	.endm

	.macro settorment param0
	.byte 0xce
	.4byte \param0
	.endm

	.macro jumpifnodamage param0
	.byte 0xcf
	.4byte \param0
	.endm

	.macro settaunt param0
	.byte 0xd0
	.4byte \param0
	.endm

	.macro trysethelpinghand param0
	.byte 0xd1
	.4byte \param0
	.endm

	.macro tryswapitems param0
	.byte 0xd2
	.4byte \param0
	.endm

	.macro trycopyability param0
	.byte 0xd3
	.4byte \param0
	.endm

	.macro trywish param0, param1
	.byte 0xd4
	.byte \param0
	.4byte \param1
	.endm

	.macro settoxicspikes ptr
	.byte 0xd5
	.4byte \ptr
	.endm

	.macro setgastroacid ptr
	.byte 0xd6
	.4byte \ptr
	.endm

	.macro setyawn param0
	.byte 0xd7
	.4byte \param0
	.endm

	.macro setdamagetohealthdifference param0
	.byte 0xd8
	.4byte \param0
	.endm

	.macro setroom
	.byte 0xd9
	.endm

	.macro tryswapabilities param0
	.byte 0xda
	.4byte \param0
	.endm

	.macro tryimprision param0
	.byte 0xdb
	.4byte \param0
	.endm

	.macro setstealthrock param0
	.byte 0xdc
	.4byte \param0
	.endm

	.macro setuserstatus3 flags ptr
	.byte 0xdd
	.4byte \flags
	.4byte \ptr
	.endm

	.macro asistattackselect param0
	.byte 0xde
	.4byte \param0
	.endm

	.macro trysetmagiccoat param0
	.byte 0xdf
	.4byte \param0
	.endm

	.macro trysetsnatch param0
	.byte 0xe0
	.4byte \param0
	.endm

	.macro trygetintimidatetarget param0
	.byte 0xe1
	.4byte \param0
	.endm

	.macro switchoutabilities battler
	.byte 0xe2
	.byte \battler
	.endm

	.macro jumpifhasnohp battler, param1
	.byte 0xe3
	.byte \battler
	.4byte \param1
	.endm

	.macro getsecretpowereffect
	.byte 0xe4
	.endm

	.macro pickup
	.byte 0xe5
	.endm

	.macro docastformchangeanimation
	.byte 0xe6
	.endm

	.macro trycastformdatachange
	.byte 0xe7
	.endm

	.macro settypebasedhalvers param0
	.byte 0xe8
	.4byte \param0
	.endm

	.macro jumpifsubstituteblocks ptr
	.byte 0xe9
	.4byte \ptr
	.endm

	.macro tryrecycleitem param0
	.byte 0xea
	.4byte \param0
	.endm

	.macro settypetoterrain param0
	.byte 0xeb
	.4byte \param0
	.endm

	.macro pursuitrelated param0
	.byte 0xec
	.4byte \param0
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

	.macro trysetcaughtmondexflags param0
	.byte 0xf1
	.4byte \param0
	.endm

	.macro displaydexinfo
	.byte 0xf2
	.endm

	.macro trygivecaughtmonnick param0
	.byte 0xf3
	.4byte \param0
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

	.macro trainerslideout param0
	.byte 0xf8
	.byte \param0
	.endm
	
	.macro settelekinesis ptr
	.byte 0xf9
	.4byte \ptr
	.endm
	
	.macro swapstatstages stat
	.byte 0xfa
	.byte \stat
	.endm
	
	.macro averagestats stat
	.byte 0xfb
	.byte \stat
	.endm
	
	.macro jumpifoppositegenders ptr
	.byte 0xfc
	.4byte \ptr
	.endm
	
	.macro trygetbaddreamstarget ptr
	.byte 0xfd
	.4byte \ptr
	.endm
	
	.macro tryworryseed ptr
	.byte 0xfe
	.4byte \ptr
	.endm
	
	.macro metalburstdamagecalculator ptr
	.byte 0xff
	.4byte \ptr
	.endm
	
@ various command changed to more readable macros
	.macro cancelmultiturnmoves battler
	various \battler, VARIOUS_CANCEL_MULTI_TURN_MOVES
	.endm
	
	.macro setmagiccoattarget battler
	various \battler, VARIOUS_SET_MAGIC_COAT_TARGET
	.endm
	
	.macro getifcantrunfrombattle battler
	various \battler, VARIOUS_IS_RUNNING_IMPOSSIBLE
	.endm
	
	.macro getmovetarget battler
	various \battler, VARIOUS_GET_MOVE_TARGET
	.endm
	
	.macro various4 battler
	various \battler, 4
	.endm
	
	.macro resetintrimidatetracebits battler
	various \battler, VARIOUS_RESET_INTIMIDATE_TRACE_BITS
	.endm
	
	.macro updatechoicemoveonlvlup battler
	various \battler, VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP
	.endm
	
	.macro various7 battler
	various \battler, 7
	.endm
	
	.macro various8 battler
	various \battler, 8
	.endm
	
	.macro various9 battler
	various \battler, 9
	.endm
	
	.macro various10 battler
	various \battler, 10
	.endm
	
	.macro various11 battler
	various \battler, 11
	.endm
	
	.macro various12 battler
	various \battler, 12
	.endm
	
	.macro forfeityesnobox battler
	various \battler, VARIOUS_EMIT_YESNOBOX
	.endm
	
	.macro various14 battler
	various \battler, 14
	.endm
	
	.macro various15 battler
	various \battler, 15
	.endm
	
	.macro various16 battler
	various \battler, 16
	.endm
	
	.macro various17 battler
	various \battler, 17
	.endm
	
	.macro waitcry battler
	various \battler, VARIOUS_WAIT_CRY
	.endm
	
	.macro returnopponentmon1toball battler
	various \battler, VARIOUS_RETURN_OPPONENT_MON1
	.endm
	
	.macro returnopponentmon2toball battler
	various \battler, VARIOUS_RETURN_OPPONENT_MON2
	.endm
	
	.macro volumedown
	various BS_ATTACKER, VARIOUS_VOLUME_DOWN
	.endm
	
	.macro volumeup
	various BS_ATTACKER, VARIOUS_VOLUME_UP
	.endm
	
	.macro various23 battler
	various \battler, 23
	.endm
	
	.macro various24 battler
	various \battler, 24
	.endm
	
	.macro setoutcomeonteleport battler
	various \battler, VARIOUS_SET_TELEPORT_OUTCOME
	.endm
	
	.macro playtrainerdefeatbgm battler
	various \battler, VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC
	.endm
	
	.macro stattextbuffer battler
	various \battler, VARIOUS_STAT_TEXT_BUFFER
	.endm
	
	.macro switchinabilities battler
	various \battler, VARIOUS_SWITCHIN_ABILITIES
	.endm
	
	.macro savetarget
	various BS_TARGET, VARIOUS_SAVE_TARGET
	.endm
	
	.macro restoretarget
	various BS_TARGET, VARIOUS_RESTORE_TARGET
	.endm
	
	.macro instanthpdrop battler
	various \battler, VARIOUS_INSTANT_HP_DROP
	.endm
	
	.macro clearstatus battler
	various \battler, VARIOUS_CLEAR_STATUS
	.endm
	
	.macro restorepp battler
	various \battler, VARIOUS_RESTORE_PP
	.endm
	
	.macro tryactivatemoxie battler
	various \battler, VARIOUS_TRY_ACTIVATE_MOXIE
	.endm
	
	.macro tryactivatefellstinger battler
	various \battler, VARIOUS_TRY_ACTIVATE_FELL_STINGER
	.endm
	
	.macro playmoveanimation battler move
	various \battler, VARIOUS_PLAY_MOVE_ANIMATION
	.2byte \move
	.endm
	
	.macro setluckychant battler ptr
	various \battler VARIOUS_SET_LUCKY_CHANT
	.4byte \ptr
	.endm
	
	.macro suckerpunchcheck ptr
	various BS_ATTACKER, VARIOUS_SUCKER_PUNCH_CHECK
	.4byte \ptr
	.endm
	
	.macro setabilitysimple battler ptr
	various \battler VARIOUS_SET_SIMPLE_BEAM
	.4byte \ptr
	.endm
	
	.macro tryentrainment ptr
	various BS_ATTACKER, VARIOUS_TRY_ENTRAINMENT
	.4byte \ptr
	.endm
	
	.macro setlastusedability battler
	various \battler, VARIOUS_SET_LAST_USED_ABILITY
	.endm
	
	.macro tryhealpulse battler ptr
	various \battler, VARIOUS_TRY_HEAL_PULSE
	.4byte \ptr
	.endm
	
	.macro tryquash ptr
	various BS_ATTACKER, VARIOUS_TRY_QUASH
	.4byte \ptr
	.endm
	
	.macro invertstatstages battler
	various \battler, VARIOUS_INVERT_STAT_STAGES
	.endm
	
	.macro setterrain ptr
	various BS_ATTACKER, VARIOUS_SET_TERRAIN
	.4byte \ptr
	.endm
	
	.macro trymefirst ptr
	various BS_ATTACKER, VARIOUS_TRY_ME_FIRST
	.4byte \ptr
	.endm
	
	.macro jumpifbattleend ptr
	various BS_ATTACKER, VARIOUS_JUMP_IF_BATTLE_END
	.4byte \ptr
	.endm
	
	.macro tryelectrify ptr
	various BS_ATTACKER, VARIOUS_TRY_ELECTRIFY
	.4byte \ptr
	.endm
	
	.macro tryreflecttype ptr
	various BS_ATTACKER, VARIOUS_TRY_REFLECT_TYPE
	.4byte \ptr
	.endm
	
	.macro trysoak ptr
	various BS_ATTACKER, VARIOUS_TRY_SOAK
	.4byte \ptr
	.endm
	
	.macro handlemegaevo battler
	various \battler, VARIOUS_HANDLE_MEGA_EVO
	.endm
	
	.macro jumpifcantuselastresort battler ptr
	various \battler, VARIOUS_TRY_LAST_RESORT
	.4byte \ptr
	.endm
	
	.macro argumentstatuseffect
	various BS_ATTACKER, VARIOUS_ARGUMENT_STATUS_EFFECT
	.endm
	
	.macro tryhitswitchtarget ptr
	various BS_ATTACKER, VARIOUS_TRY_HIT_SWITCH_TARGET
	.4byte \ptr
	.endm
	
	.macro tryautonomize battler ptr
	various \battler, VARIOUS_TRY_AUTONOMIZE
	.4byte \ptr
	.endm
	
	.macro jumpifcantusesynchronoise ptr
	various BS_ATTACKER, VARIOUS_TRY_SYNCHRONOISE
	.4byte \ptr
	.endm
	
	.macro trycopycat ptr
	various BS_ATTACKER, VARIOUS_TRY_COPYCAT
	.4byte \ptr
	.endm
	
	.macro showabilitypopup battler
	various \battler, VARIOUS_ABILITY_POPUP
	.endm
	
	.macro defogclear battler, clear, ptr
	various \battler, VARIOUS_DEFOG
	.byte \clear
	.4byte \ptr
	.endm
	
	.macro jumpiftargetally ptr
	various BS_ATTACKER, VARIOUS_JUMP_IF_TARGET_ALLY
	.4byte \ptr
	.endm
	
	.macro trypsychoshift ptr
	various BS_ATTACKER, VARIOUS_PSYCHO_SHIFT
	.4byte \ptr
	.endm
	
	.macro curestatus battler
	various \battler, VARIOUS_CURE_STATUS
	.endm
	
	.macro powertrick battler
	various \battler, VARIOUS_POWER_TRICK
	.endm

@ helpful macros
	.macro setstatchanger stat, stages, down
	setbyte sSTATCHANGER \stat | \stages << 4 | \down << 7
	.endm
	
	.macro setmoveeffect effect
	setbyte cEFFECT_CHOOSER \effect
	setbyte sSAVED_MOVE_EFFECT \effect
	.endm
	
	.macro chosenstatus1animation battler, status
	chosenstatusanimation \battler 0x0 \status
	.endm
	
	.macro chosenstatus2animation battler, status
	chosenstatusanimation \battler 0x1 \status
	.endm
	
	.macro sethword dst, value
	setbyte \dst, \value & 0xFF
	setbyte \dst + 1, (\value >> 8) & 0xFF
	.endm
	
	.macro setword dst, value
	setbyte \dst, \value & 0xFF
	setbyte \dst + 1, (\value >> 8) & 0xFF
	setbyte \dst + 2, (\value >> 16) & 0xFF
	setbyte \dst + 3, (\value >> 24) & 0xFF
	.endm
	
	.macro copybyte dst, src
	copyarray \dst, \src, 0x1
	.endm
	
	.macro copyhword dst, src
	copyarray \dst, \src, 0x2
	.endm
	
	.macro copyword dst, src
	copyarray \dst, \src, 0x4
	.endm
	
	.macro jumpifbytenotequal byte1, byte2, jumpptr
	jumpifarraynotequal \byte1, \byte2, 0x1, \jumpptr
	.endm
	
	.macro jumpifbyteequal byte1, byte2, jumpptr
	jumpifarrayequal \byte1, \byte2, 0x1, \jumpptr
	.endm
	
	.macro jumpifmove move, jumpptr
	jumpifhalfword CMP_EQUAL, gCurrentMove, \move, \jumpptr
	.endm

	.macro jumpifnotmove move, jumpptr
	jumpifhalfword CMP_NOT_EQUAL, gCurrentMove, \move, \jumpptr
	.endm

	.macro jumpifnotchosenmove move, jumpptr
	jumpifhalfword CMP_NOT_EQUAL, gChosenMove, \move, \jumpptr
	.endm

	.macro jumpifstatus3 battler, status, jumpptr
	jumpifstatus3condition \battler, \status, 0x0, \jumpptr
	.endm
	
	.macro jumpifnostatus3 battler, status, jumpptr
	jumpifstatus3condition \battler, \status, 0x1, \jumpptr
	.endm
	
	.macro jumpifmovehadnoeffect jumpptr
	jumpifbyte CMP_COMMON_BITS, gMoveResultFlags, MOVE_RESULT_NO_EFFECT, \jumpptr
	.endm
	
	.macro jumpifbattletype flags, jumpptr
	jumpifword CMP_COMMON_BITS, gBattleTypeFlags, \flags, \jumpptr
	.endm
	
	.macro jumpifnotbattletype flags, jumpptr
	jumpifword CMP_NO_COMMON_BITS, gBattleTypeFlags, \flags, \jumpptr
	.endm
	
	.macro dmg_1_8_targethp
	manipulatedamage ATK80_1_8_TARGET_HP
	.endm
	
	.macro dmgtomaxattackerhp
	manipulatedamage ATK80_FULL_ATTACKER_HP
	.endm
	
	.macro dmgtocurrattackerhp
	manipulatedamage ATK80_CURR_ATTACKER_HP
	.endm
