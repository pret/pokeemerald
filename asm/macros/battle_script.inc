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

	.macro healthbarupdate bank
	.byte 0xb
	.byte \bank
	.endm

	.macro datahpupdate bank
	.byte 0xc
	.byte \bank
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

	.macro clearstatusfromeffect bank
	.byte 0x18
	.byte \bank
	.endm

	.macro tryfaintmon bank, param1, param2
	.byte 0x19
	.byte \bank
	.byte \param1
	.4byte \param2
	.endm

	.macro dofaintanimation bank
	.byte 0x1a
	.byte \bank
	.endm

	.macro cleareffectsonfaint bank
	.byte 0x1b
	.byte \bank
	.endm

	.macro jumpifstatus bank, status1, param2
	.byte 0x1c
	.byte \bank
	.4byte \status1
	.4byte \param2
	.endm

	.macro jumpifstatus2 bank, status2, param2
	.byte 0x1d
	.byte \bank
	.4byte \status2
	.4byte \param2
	.endm

	.macro jumpifability param0, ability, param2
	.byte 0x1e
	.byte \param0
	.byte \ability
	.4byte \param2
	.endm

	.macro jumpifsideaffecting bank, sidestatus, param2
	.byte 0x1f
	.byte \bank
	.2byte \sidestatus
	.4byte \param2
	.endm

	.macro jumpifstat bank, ifflag, stat, param3, param4
	.byte 0x20
	.byte \bank
	.byte \ifflag
	.byte \stat
	.byte \param3
	.4byte \param4
	.endm

	.macro jumpifstatus3condition bank, status3, param2, param3
	.byte 0x21
	.byte \bank
	.4byte \status3
	.byte \param2
	.4byte \param3
	.endm

	.macro jumpiftype bank, type, param2
	.byte 0x22
	.byte \bank
	.byte \type
	.4byte \param2
	.endm

	.macro getexp bank
	.byte 0x23
	.byte \bank
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

	.macro healthbar_update bank
	.byte 0x3b
	.byte \bank
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

	.macro playanimation bank, param1, param2
	.byte 0x45
	.byte \bank
	.byte \param1
	.4byte \param2
	.endm

	.macro playanimation2 bank, param1, param2
	.byte 0x46
	.byte \bank
	.4byte \param1
	.4byte \param2
	.endm

	.macro setgraphicalstatchangevalues
	.byte 0x47
	.endm

	.macro playstatchangeanimation bank, param1, param2
	.byte 0x48
	.byte \bank
	.byte \param1
	.byte \param2
	.endm

	.macro moveend param0, param1
	.byte 0x49
	.byte \param0
	.byte \param1
	.endm

	.macro typecalc2
	.byte 0x4a
	.endm

	.macro returnatktoball
	.byte 0x4b
	.endm

	.macro getswitchedmondata bank
	.byte 0x4c
	.byte \bank
	.endm

	.macro switchindataupdate bank
	.byte 0x4d
	.byte \bank
	.endm

	.macro switchinanim bank, dontclearsubstitutebit
	.byte 0x4e
	.byte \bank
	.byte \dontclearsubstitutebit
	.endm

	.macro jumpifcantswitch bank, param1
	.byte 0x4f
	.byte \bank
	.4byte \param1
	.endm

	.macro openpartyscreen param0, param1
	.byte 0x50
	.byte \param0
	.4byte \param1
	.endm

	.macro switchhandleorder bank, param1
	.byte 0x51
	.byte \bank
	.byte \param1
	.endm

	.macro switchineffects bank
	.byte 0x52
	.byte \bank
	.endm

	.macro trainerslidein bank
	.byte 0x53
	.byte \bank
	.endm

	.macro playse param0
	.byte 0x54
	.2byte \param0
	.endm

	.macro fanfare param0
	.byte 0x55
	.2byte \param0
	.endm

	.macro playfaintcry bank
	.byte 0x56
	.byte \bank
	.endm

	.macro atk57
	.byte 0x57
	.endm

	.macro returntoball bank
	.byte 0x58
	.byte \bank
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

	.macro hitanimation bank
	.byte 0x5c
	.byte \bank
	.endm

	.macro getmoneyreward
	.byte 0x5d
	.endm

	.macro atk5E bank
	.byte 0x5e
	.byte \bank
	.endm

	.macro swapattackerwithtarget
	.byte 0x5f
	.endm

	.macro incrementgamestat param0
	.byte 0x60
	.byte \param0
	.endm

	.macro drawpartystatussummary bank
	.byte 0x61
	.byte \bank
	.endm

	.macro hidepartystatussummary bank
	.byte 0x62
	.byte \bank
	.endm

	.macro jumptorandomattack param0
	.byte 0x63
	.byte \param0
	.endm

	.macro statusanimation bank
	.byte 0x64
	.byte \bank
	.endm

	.macro status2animation bank, status2
	.byte 0x65
	.byte \bank
	.4byte \status2
	.endm

	.macro chosenstatusanimation bank, param1, param2
	.byte 0x66
	.byte \bank
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

	.macro removeitem bank
	.byte 0x6a
	.byte \bank
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

	.macro makevisible bank
	.byte 0x6f
	.byte \bank
	.endm

	.macro recordlastability bank
	.byte 0x70
	.byte \bank
	.endm

	.macro buffermovetolearn
	.byte 0x71
	.endm

	.macro jumpifplayerran param0
	.byte 0x72
	.4byte \param0
	.endm

	.macro hpthresholds bank
	.byte 0x73
	.byte \bank
	.endm

	.macro hpthresholds2 bank
	.byte 0x74
	.byte \bank
	.endm

	.macro useitemonopponent
	.byte 0x75
	.endm

	.macro various bank, param1
	.byte 0x76
	.byte \bank
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

	.macro tryhealhalfhealth param0, bank
	.byte 0x7b
	.4byte \param0
	.byte \bank
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

	.macro negativedamage
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

	.macro updatestatusicon bank
	.byte 0x98
	.byte \bank
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

	.macro hiddenpowercalc
	.byte 0xc1
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

	.macro switchoutabilities bank
	.byte 0xe2
	.byte \bank
	.endm

	.macro jumpifhasnohp bank, param1
	.byte 0xe3
	.byte \bank
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

	.macro setweatherballtype
	.byte 0xe9
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
	
@ various command changed to more readable macros
	.macro cancelmultiturnmoves bank
	various \bank, VARIOUS_CANCEL_MULTI_TURN_MOVES
	.endm
	
	.macro setmagiccoattarget bank
	various \bank, VARIOUS_SET_MAGIC_COAT_TARGET
	.endm
	
	.macro getifcantrunfrombattle bank
	various \bank, VARIOUS_IS_RUNNING_IMPOSSIBLE
	.endm
	
	.macro getmovetarget bank
	various \bank, VARIOUS_GET_MOVE_TARGET
	.endm
	
	.macro various4 bank
	various \bank, 4
	.endm
	
	.macro resetintrimidatetracebits bank
	various \bank, VARIOUS_RESET_INTIMIDATE_TRACE_BITS
	.endm
	
	.macro updatechoicemoveonlvlup bank
	various \bank, VARIOUS_UPDATE_CHOICE_MOVE_ON_LVL_UP
	.endm
	
	.macro various7 bank
	various \bank, 7
	.endm
	
	.macro various8 bank
	various \bank, 8
	.endm
	
	.macro various9 bank
	various \bank, 9
	.endm
	
	.macro various10 bank
	various \bank, 10
	.endm
	
	.macro various11 bank
	various \bank, 11
	.endm
	
	.macro various12 bank
	various \bank, 12
	.endm
	
	.macro forfeityesnobox bank
	various \bank, VARIOUS_EMIT_YESNOBOX
	.endm
	
	.macro various14 bank
	various \bank, 14
	.endm
	
	.macro various15 bank
	various \bank, 15
	.endm
	
	.macro various16 bank
	various \bank, 16
	.endm
	
	.macro various17 bank
	various \bank, 17
	.endm
	
	.macro waitcry bank
	various \bank, VARIOUS_WAIT_CRY
	.endm
	
	.macro returnopponentmon1toball bank
	various \bank, VARIOUS_RETURN_OPPONENT_MON1
	.endm
	
	.macro returnopponentmon2toball bank
	various \bank, VARIOUS_RETURN_OPPONENT_MON2
	.endm
	
	.macro various21 bank
	various \bank, 21
	.endm
	
	.macro various22 bank
	various \bank, 22
	.endm
	
	.macro various23 bank
	various \bank, 23
	.endm
	
	.macro various24 bank
	various \bank, 24
	.endm
	
	.macro setoutcomeonteleport bank
	various \bank, VARIOUS_SET_TELEPORT_OUTCOME
	.endm
	
	.macro playtrainerdefeatbgm bank
	various \bank, VARIOUS_PLAY_TRAINER_DEFEATED_MUSIC
	.endm
	
@ helpful macros
	.macro setstatchanger stat, stages, down
	setbyte sSTATCHANGER \stat | \stages << 4 | \down << 7
	.endm
	
	.macro setmoveeffect effect
	setbyte cEFFECT_CHOOSER \effect
	.endm
	
	.macro chosenstatus1animation bank, status
	chosenstatusanimation \bank 0x0 \status
	.endm
	
	.macro chosenstatus2animation bank, status
	chosenstatusanimation \bank 0x1 \status
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
	
	.macro jumpifstatus3 bank, status, jumpptr
	jumpifstatus3condition \bank, \status, 0x0, \jumpptr
	.endm
	
	.macro jumpifnostatus3 bank, status, jumpptr
	jumpifstatus3condition \bank, \status, 0x1, \jumpptr
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
