@ 0 ==
@ 1 !=
@ 2 <
@ 3 >
@ 4 &=

	.macro calculatedamage
	critical
	atk5
	atk6
	atk7
	.endm


	.macro attackcanceler
	.byte 0x00
	.endm

	.macro accuracycheck address, param1
	.byte 0x01
	.4byte \address
	.2byte \param1
	.endm

	.macro attackstring
	.byte 0x02
	.endm

	.macro ppreduce
	.byte 0x03
	.endm

	.macro critcalc
	.byte 0x04
	.endm

	.macro atk5
	.byte 0x05
	.endm

	.macro atk6
	.byte 0x06
	.endm

	.macro atk7
	.byte 0x07
	.endm

	.macro atk8
	.byte 0x08
	.endm

	.macro attackanimation
	.byte 0x09
	.endm

	.macro waitanimation
	.byte 0x0a
	.endm

	.macro graphicalhpupdate bank
	.byte 0x0b
	.byte \bank
	.endm

	.macro datahpupdate bank
	.byte 0x0c
	.byte \bank
	.endm

	.macro critmessage
	.byte 0x0d
	.endm

	.macro missmessage
	.byte 0x0e
	.endm

	.macro resultmessage
	.byte 0x0f
	.endm

	.macro printstring string
	.byte 0x10
	.2byte \string
	.endm

	.macro printstring2 string
	.byte 0x11
	.2byte \string
	.endm

	.macro waitmessage delay
	.byte 0x12
	.2byte \delay
	.endm

	.macro printfromtable table
	.byte 0x13
	.4byte \table
	.endm

	.macro printfromtable2 table
	.byte 0x14
	.4byte \table
	.endm

	.macro seteffectwithchancetarget
	.byte 0x15
	.endm

	.macro seteffecttarget
	.byte 0x16
	.endm

	.macro seteffectuser
	.byte 0x17
	.endm

	.macro clearstatus bank
	.byte 0x18
	.byte \bank
	.endm

	.macro faintpokemon bank, param2, param3
	.byte 0x19
	.byte \bank
	.byte \param2
	.4byte \param3
	.endm

	.macro atk1a param1
	.byte 0x1a
	.byte \param1
	.endm

	.macro atk1b bank
	.byte 0x1b
	.byte \bank
	.endm

	.macro jumpifstatus bank, status, address
	.byte 0x1c
	.byte \bank
	.4byte \status
	.4byte \address
	.endm

	.macro jumpifsecondarytstatus bank, status, address
	.byte 0x1d
	.byte \bank
	.4byte \status
	.4byte \address
	.endm

	.macro jumpifability bank, ability, address
	.byte 0x1e
	.byte \bank
	.byte \ability
	.4byte \address
	.endm

	.macro jumpifhalverset bank, status, address
	.byte 0x1f
	.byte \bank
	.2byte \status
	.4byte \address
	.endm

	.macro jumpifstat bank, flag, quantity, statid, address
	.byte 0x20
	.byte \bank
	.byte \flag
	.byte \quantity
	.byte \statid
	.4byte \address
	.endm

	.macro jumpifspecialstatusflag bank, mask, status, address
	.byte 0x21
	.byte \bank
	.4byte \mask
	.byte \status
	.4byte \address
	.endm

	.macro jumpiftype bank, type, address
	.byte 0x22
	.byte \bank
	.byte \type
	.4byte \address
	.endm

	.macro atk23 bank
	.byte 0x23
	.byte \bank
	.endm

	.macro atk24 address
	.byte 0x24
	.4byte \address
	.endm

	.macro atk25
	.byte 0x25
	.endm

	.macro atk26 param1
	.byte 0x26
	.byte \param1
	.endm

	.macro atk27 address
	.byte 0x27
	.4byte \address
	.endm

	.macro jump address
	.byte 0x28
	.4byte \address
	.endm

	.macro jumpifbyte ifflag, checkaddr, compare, address
	.byte 0x29
	.byte \ifflag
	.4byte \checkaddr
	.byte \compare
	.4byte \address
	.endm

	.macro jumpifhalfword ifflag, checkaddr, compare, address
	.byte 0x2a
	.byte \ifflag
	.4byte \checkaddr
	.2byte \compare
	.4byte \address
	.endm

	.macro jumpifword ifflag, checkaddr, compare, address
	.byte 0x2b
	.byte \ifflag
	.4byte \checkaddr
	.4byte \compare
	.4byte \address
	.endm

	.macro jumpifarrayequal mem1, mem2, size, address
	.byte 0x2c
	.4byte \mem1
	.4byte \mem2
	.byte \size
	.4byte \address
	.endm

	.macro jumpifarraynotequal mem1, mem2, size, address
	.byte 0x2d
	.4byte \mem1
	.4byte \mem2
	.byte \size
	.4byte \address
	.endm

	.macro setbyte pointer, value
	.byte 0x2e
	.4byte \pointer
	.byte \value
	.endm

	.macro addbyte pointer, value
	.byte 0x2f
	.4byte \pointer
	.byte \value
	.endm

	.macro subtractbyte pointer, value
	.byte 0x30
	.4byte \pointer
	.byte \value
	.endm

	.macro copyarray destination, source, size
	.byte 0x31
	.4byte \destination
	.4byte \source
	.byte \size
	.endm

	.macro atk32 param1, param2, param3, byte
	.byte 0x32
	.4byte \param1
	.4byte \param2
	.4byte \param3
	.byte \byte
	.endm

	.macro orbyte pointer, value
	.byte 0x33
	.4byte \pointer
	.byte \value
	.endm

	.macro orhalfword pointer, value
	.byte 0x34
	.4byte \pointer
	.2byte \value
	.endm

	.macro orword pointer, value
	.byte 0x35
	.4byte \pointer
	.4byte \value
	.endm

	.macro bicbyte pointer, value
	.byte 0x36
	.4byte \pointer
	.byte \value
	.endm

	.macro bichalfword pointer, value
	.byte 0x37
	.4byte \pointer
	.2byte \value
	.endm

	.macro bicword pointer, value
	.byte 0x38
	.4byte \pointer
	.4byte \value
	.endm

	.macro pause pause_duration
	.byte 0x39
	.2byte \pause_duration
	.endm

	.macro waitstateatk
	.byte 0x3a
	.endm

	.macro somethinghealatk3b bank
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

	.macro atk40 address
	.byte 0x40
	.4byte \address
	.endm

	.macro callatk address
	.byte 0x41
	.4byte \address
	.endm

	.macro jumpiftype2 bank, type, address
	.byte 0x42
	.byte \bank
	.byte \type
	.4byte \address
	.endm

	.macro jumpifabilitypresent ability, address
	.byte 0x43
	.byte \ability
	.4byte \address
	.endm

	.macro atk44
	.byte 0x44
	.endm

	.macro playanimation bank, animation, var_address
	.byte 0x45
	.byte \bank
	.byte \animation
	.4byte \var_address
	.endm

	.macro atk46 bank, address, int
	.byte 0x46
	.byte \bank
	.4byte \address
	.4byte \int
	.endm

	.macro atk47
	.byte 0x47
	.endm

	.macro playstatchangeanimation bank, color, byte
	.byte 0x48
	.byte \bank
	.byte \color
	.byte \byte
	.endm

	.macro atk49 byte1, byte2
	.byte 0x49
	.byte \byte1
	.byte \byte2
	.endm

	.macro damagecalc2
	.byte 0x4a
	.endm

	.macro atk4b
	.byte 0x4b
	.endm

	.macro switch1 bank
	.byte 0x4c
	.byte \bank
	.endm

	.macro switch2 bank
	.byte 0x4d
	.byte \bank
	.endm

	.macro switch3 bank, byte
	.byte 0x4e
	.byte \bank
	.byte \byte
	.endm

	.macro jumpifcannotswitch bank, address
	.byte 0x4f
	.byte \bank
	.4byte \address
	.endm

	.macro openpartyscreen bank, address
	.byte 0x50
	.byte \bank
	.4byte \address
	.endm

	.macro atk51 bank, param2
	.byte 0x51
	.byte \bank
	.byte \param2
	.endm

	.macro atk52 bank
	.byte 0x52
	.byte \bank
	.endm

	.macro atk53 bank
	.byte 0x53
	.byte \bank
	.endm

	.macro atk54 word
	.byte 0x54
	.2byte \word
	.endm

	.macro atk55 int
	.byte 0x55
	.4byte \int
	.endm

	.macro atk56 bank_or_side
	.byte 0x56
	.byte \bank_or_side
	.endm

	.macro atk57
	.byte 0x57
	.endm

	.macro atk58 bank
	.byte 0x58
	.byte \bank
	.endm

	.macro checkiflearnmoveinbattle param1, param2, bank_maybe
	.byte 0x59
	.4byte \param1
	.4byte \param2
	.byte \bank_maybe
	.endm

	.macro atk5a address
	.byte 0x5a
	.4byte \address
	.endm

	.macro atk5b address
	.byte 0x5b
	.4byte \address
	.endm

	.macro atk5c bank
	.byte 0x5c
	.byte \bank
	.endm

	.macro atk5d
	.byte 0x5d
	.endm

	.macro atk5e bank
	.byte 0x5e
	.byte \bank
	.endm

	.macro atk5f
	.byte 0x5f
	.endm

	.macro atk60 byte
	.byte 0x60
	.byte \byte
	.endm

	.macro atk61 bank_or_side
	.byte 0x61
	.byte \bank_or_side
	.endm

	.macro atk62 bank_or_side
	.byte 0x62
	.byte \bank_or_side
	.endm

	.macro jumptoattack bank
	.byte 0x63
	.byte \bank
	.endm

	.macro statusanimation bank
	.byte 0x64
	.byte \bank
	.endm

	.macro atk65 bank_or_side, address
	.byte 0x65
	.byte \bank_or_side
	.4byte \address
	.endm

	.macro atk66 bank_or_side, bank_or_side2, address
	.byte 0x66
	.byte \bank_or_side
	.byte \bank_or_side2
	.4byte \address
	.endm

	.macro atk67
	.byte 0x67
	.endm

	.macro atk68
	.byte 0x68
	.endm

	.macro atk69
	.byte 0x69
	.endm

	.macro removeitem bank
	.byte 0x6a
	.byte \bank
	.endm

	.macro atk6b
	.byte 0x6b
	.endm

	.macro atk6c
	.byte 0x6c
	.endm

	.macro atk6d
	.byte 0x6d
	.endm

	.macro atk6e
	.byte 0x6e
	.endm

	.macro atk6f bank
	.byte 0x6f
	.byte \bank
	.endm

	.macro atk70 bank
	.byte 0x70
	.byte \bank
	.endm

	.macro atk71
	.byte 0x71
	.endm

	.macro atk72 address
	.byte 0x72
	.4byte \address
	.endm

	.macro atk73 bank
	.byte 0x73
	.byte \bank
	.endm

	.macro atk74 bank
	.byte 0x74
	.byte \bank
	.endm

	.macro atk75
	.byte 0x75
	.endm

	.macro atk76 bank, byte
	.byte 0x76
	.byte \bank
	.byte \byte
	.endm

	.macro setprotect
	.byte 0x77
	.endm

	.macro faintifabilitynotdamp
	.byte 0x78
	.endm

	.macro setuserhptozero
	.byte 0x79
	.endm

	.macro jumpwhiletargetvalid address
	.byte 0x7a
	.4byte \address
	.endm

	.macro setdamageasrestorehalfmaxhp address, byte
	.byte 0x7b
	.4byte \address
	.byte \byte
	.endm

	.macro jumptolastusedattack
	.byte 0x7c
	.endm

	.macro setrain
	.byte 0x7d
	.endm

	.macro setreflect
	.byte 0x7e
	.endm

	.macro setleechseed
	.byte 0x7f
	.endm

	.macro manipulatedamage id
	.byte 0x80
	.byte \id
	.endm

	.macro setrest address
	.byte 0x81
	.4byte \address
	.endm

	.macro jumpifnotfirstturn address
	.byte 0x82
	.4byte \address
	.endm

	.macro nop3
	.byte 0x83
	.endm

	.macro jumpifcannotsleep address
	.byte 0x84
	.4byte \address
	.endm

	.macro stockpile
	.byte 0x85
	.endm

	.macro stockpiletobasedamage address
	.byte 0x86
	.4byte \address
	.endm

	.macro stockpiletohprecovery address
	.byte 0x87
	.4byte \address
	.endm

	.macro negativedamage
	.byte 0x88
	.endm

	.macro statbuffchange target, address
	.byte 0x89
	.byte \target
	.4byte \address
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

	.macro setloopcounter count
	.byte 0x8d
	.byte \count
	.endm

	.macro atk8e
	.byte 0x8e
	.endm

	.macro forcerandomswitch address
	.byte 0x8f
	.4byte \address
	.endm

	.macro changetypestoenemyattacktype address
	.byte 0x90
	.4byte \address
	.endm

	.macro givemoney
	.byte 0x91
	.endm

	.macro setlightscreen
	.byte 0x92
	.endm

	.macro koplussomethings address
	.byte 0x93
	.4byte \address
	.endm

	.macro gethalfcurrentenemyhp
	.byte 0x94
	.endm

	.macro setsandstorm
	.byte 0x95
	.endm

	.macro weatherdamage
	.byte 0x96
	.endm

	.macro tryinfatuatetarget address
	.byte 0x97
	.4byte \address
	.endm

	.macro atk98 byte
	.byte 0x98
	.byte \byte
	.endm

	.macro setmisteffect
	.byte 0x99
	.endm

	.macro setincreasedcriticalchance
	.byte 0x9a
	.endm

	.macro transformdataexecution
	.byte 0x9b
	.endm

	.macro setsubstituteeffect
	.byte 0x9c
	.endm

	.macro copyattack address
	.byte 0x9d
	.4byte \address
	.endm

	.macro metronomeeffect
	.byte 0x9e
	.endm

	.macro nightshadedamageeffect
	.byte 0x9f
	.endm

	.macro psywavedamageeffect
	.byte 0xa0
	.endm

	.macro counterdamagecalculator address
	.byte 0xa1
	.4byte \address
	.endm

	.macro mirrorcoatdamagecalculator address
	.byte 0xa2
	.4byte \address
	.endm

	.macro disablelastusedattack address
	.byte 0xa3
	.4byte \address
	.endm

	.macro setencore address
	.byte 0xa4
	.4byte \address
	.endm

	.macro painsplitdamagecalculator address
	.byte 0xa5
	.4byte \address
	.endm

	.macro settypetorandomresistance address
	.byte 0xa6
	.4byte \address
	.endm

	.macro setalwayshitflag
	.byte 0xa7
	.endm

	.macro copymovepermanently address
	.byte 0xa8
	.4byte \address
	.endm

	.macro selectrandommovefromusermoves address
	.byte 0xa9
	.4byte \address
	.endm

	.macro destinybondeffect
	.byte 0xaa
	.endm

	.macro atkab
	.byte 0xab
	.endm

	.macro remaininghptopower
	.byte 0xac
	.endm

	.macro reducepprandom address
	.byte 0xad
	.4byte \address
	.endm

	.macro clearstatusifnotsoundproofed
	.byte 0xae
	.endm

	.macro cursetarget address
	.byte 0xaf
	.4byte \address
	.endm

	.macro setspikes address
	.byte 0xb0
	.4byte \address
	.endm

	.macro setforesight
	.byte 0xb1
	.endm

	.macro setperishsong address
	.byte 0xb2
	.4byte \address
	.endm

	.macro rolloutdamagecalculation
	.byte 0xb3
	.endm

	.macro jumpifconfusedandattackmaxed bank, address
	.byte 0xb4
	.byte \bank
	.4byte \address
	.endm

	.macro furycutterdamagecalculation
	.byte 0xb5
	.endm

	.macro happinesstodamagecalculation
	.byte 0xb6
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

	.macro atkba address
	.byte 0xba
	.4byte \address
	.endm

	.macro setsunny
	.byte 0xbb
	.endm

	.macro maxattackhalvehp address
	.byte 0xbc
	.4byte \address
	.endm

	.macro copyfoestats address
	.byte 0xbd
	.4byte \address
	.endm

	.macro breakfree
	.byte 0xbe
	.endm

	.macro setcurled
	.byte 0xbf
	.endm

	.macro recoverbasedonsunlight address
	.byte 0xc0
	.4byte \address
	.endm

	.macro hiddenpowerdamagecalculation
	.byte 0xc1
	.endm

	.macro selectnexttarget
	.byte 0xc2
	.endm

	.macro setfutureattack address
	.byte 0xc3
	.4byte \address
	.endm

	.macro beatupcalculation address1, address2
	.byte 0xc4
	.4byte \address1
	.4byte \address2
	.endm

	.macro hidepreattack
	.byte 0xc5
	.endm

	.macro unhidepostattack
	.byte 0xc6
	.endm

	.macro setminimize
	.byte 0xc7
	.endm

	.macro sethail
	.byte 0xc8
	.endm

	.macro jumpifattackandspecialattackcannotfall address
	.byte 0xc9
	.4byte \address
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

	.macro cureifburnedparalysedorpoisoned address
	.byte 0xcd
	.4byte \address
	.endm

	.macro settorment address
	.byte 0xce
	.4byte \address
	.endm

	.macro jumpifnodamage address
	.byte 0xcf
	.4byte \address
	.endm

	.macro settaunt address
	.byte 0xd0
	.4byte \address
	.endm

	.macro sethelpinghand address
	.byte 0xd1
	.4byte \address
	.endm

	.macro itemswap address
	.byte 0xd2
	.4byte \address
	.endm

	.macro copyability address
	.byte 0xd3
	.4byte \address
	.endm

	.macro atkd4 byte, address
	.byte 0xd4
	.byte \byte
	.4byte \address
	.endm

	.macro setroots address
	.byte 0xd5
	.4byte \address
	.endm

	.macro doubledamagedealtifdamaged
	.byte 0xd6
	.endm

	.macro setyawn address
	.byte 0xd7
	.4byte \address
	.endm

	.macro setdamagetohealthdifference address
	.byte 0xd8
	.4byte \address
	.endm

	.macro scaledamagebyhealthratio
	.byte 0xd9
	.endm

	.macro abilityswap address
	.byte 0xda
	.4byte \address
	.endm

	.macro imprisoneffect address
	.byte 0xdb
	.4byte \address
	.endm

	.macro setgrudge address
	.byte 0xdc
	.4byte \address
	.endm

	.macro weightdamagecalculation
	.byte 0xdd
	.endm

	.macro assistattackselect address
	.byte 0xde
	.4byte \address
	.endm

	.macro setmagiccoat address
	.byte 0xdf
	.4byte \address
	.endm

	.macro setstealstatchange address
	.byte 0xe0
	.4byte \address
	.endm

	.macro atke1 address
	.byte 0xe1
	.4byte \address
	.endm

	.macro atke2 bank
	.byte 0xe2
	.byte \bank
	.endm

	.macro jumpiffainted bank, address
	.byte 0xe3
	.byte \bank
	.4byte \address
	.endm

	.macro naturepowereffect
	.byte 0xe4
	.endm

	.macro pickupitemcalculation
	.byte 0xe5
	.endm

	.macro actualcastformswitch
	.byte 0xe6
	.endm

	.macro castformswitch
	.byte 0xe7
	.endm

	.macro settypebasedhalvers address
	.byte 0xe8
	.4byte \address
	.endm

	.macro seteffectbyweather
	.byte 0xe9
	.endm

	.macro recycleitem address
	.byte 0xea
	.4byte \address
	.endm

	.macro settypetoterrain address
	.byte 0xeb
	.4byte \address
	.endm

	.macro pursuitwhenswitched address
	.byte 0xec
	.4byte \address
	.endm

	.macro snatchmove
	.byte 0xed
	.endm

	.macro removereflectlightscreen
	.byte 0xee
	.endm

	.macro pokemoncatchfunction
	.byte 0xef
	.endm

	.macro catchpoke
	.byte 0xf0
	.endm

	.macro capturesomethingf1 address
	.byte 0xf1
	.4byte \address
	.endm

	.macro capturesomethingf2
	.byte 0xf2
	.endm

	.macro capturesomethingf3 address
	.byte 0xf3
	.4byte \address
	.endm

	.macro removehp
	.byte 0xf4
	.endm

	.macro curestatusfirstword
	.byte 0xf5
	.endm

	.macro atkf6
	.byte 0xf6
	.endm

	.macro activesidesomething
	.byte 0xf7
	.endm

	.macro atkf8 bank
	.byte 0xf8
	.byte \bank
	.endm
