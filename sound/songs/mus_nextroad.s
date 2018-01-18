	.include "MPlayDef.s"

	.equ	mus_nextroad_grp, voicegroup_86816B0
	.equ	mus_nextroad_pri, 0
	.equ	mus_nextroad_rev, reverb_set+50
	.equ	mus_nextroad_mvl, 127
	.equ	mus_nextroad_key, 0
	.equ	mus_nextroad_tbs, 1
	.equ	mus_nextroad_exg, 0
	.equ	mus_nextroad_cmp, 1

	.section .rodata
	.global	mus_nextroad
	.align	2

@********************** Track  1 **********************@

mus_nextroad_1:
	.byte	KEYSH , mus_nextroad_key+0
	.byte	TEMPO , 128*mus_nextroad_tbs/2
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 62*mus_nextroad_mvl/mxv
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte	W96
	.byte	W96
mus_nextroad_1_B1:
	.byte	TEMPO , 128*mus_nextroad_tbs/2
	.byte		VOL   , 32*mus_nextroad_mvl/mxv
	.byte		PAN   , c_v+30
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		VOICE , 60
	.byte	W24
	.byte		N08   , Ds4 , v112
	.byte	W04
	.byte		LFOS  , 44
	.byte	W04
	.byte		N08   , Ds4 , v032
	.byte	W08
	.byte		N04   , Cn4 , v112
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W04
	.byte		        As4 , v112
	.byte	W04
	.byte		N08   , As4 , v032
	.byte	W12
	.byte		N20   , Gs4 , v112
	.byte	W08
	.byte	W12
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		N08   , Fn4 
	.byte	W08
	.byte		        Fn4 , v032
	.byte	W08
	.byte		        Ds4 , v112
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Cs4 , v032
	.byte	W08
	.byte		        Cn4 , v112
	.byte	W08
	.byte		N04   , Gs3 
	.byte	W04
	.byte		N08   , Gs3 , v032
	.byte	W12
	.byte		N04   , As3 , v112
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		N48   , Cn4 , v112
	.byte	W24
	.byte		MOD   , 8
	.byte		VOL   , 30*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        28*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        27*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        22*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        17*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        12*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		N08   , Cn4 , v032
	.byte	W12
	.byte		VOL   , 33*mus_nextroad_mvl/mxv
	.byte	W36
	.byte		VOICE , 56
	.byte		VOL   , 61*mus_nextroad_mvl/mxv
	.byte	W48
	.byte		PAN   , c_v+42
	.byte	W08
	.byte		N04   , Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		        Gn4 , v112
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W04
	.byte		        Gs4 , v112
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W44
	.byte		PAN   , c_v-20
	.byte		N08   , Ds4 , v112
	.byte	W08
	.byte		        Ds4 , v032
	.byte	W08
	.byte		N04   , Cn4 , v112
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W04
	.byte		        Ds5 , v112
	.byte	W04
	.byte		        Ds5 , v032
	.byte	W12
	.byte		N20   , Cs5 , v112
	.byte	W08
	.byte	W12
	.byte		N04   , Cn5 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		N08   , As4 , v032
	.byte	W12
	.byte		N04   , Gs4 , v112
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W04
	.byte		N48   , Fs4 , v112
	.byte	W24
	.byte		MOD   , 8
	.byte		VOL   , 58*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        49*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        46*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        42*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        40*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_nextroad_mvl/mxv
	.byte		N08   , Fs4 , v032
	.byte	W24
	.byte		N04   , Fn4 , v112
	.byte	W04
	.byte		N08   , Fn4 , v032
	.byte	W12
	.byte		N04   , Fs4 , v112
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		N48   , Gs4 , v112
	.byte	W24
	.byte		MOD   , 8
	.byte		VOL   , 58*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        51*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        46*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        42*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        38*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        36*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		N48   , As4 
	.byte	W04
	.byte		VOL   , 25*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        40*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        45*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        52*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        56*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        61*mus_nextroad_mvl/mxv
	.byte		MOD   , 8
	.byte	W04
	.byte		VOL   , 65*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        61*mus_nextroad_mvl/mxv
	.byte	W16
	.byte		MOD   , 0
	.byte		N08   , As4 , v032
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 85
	.byte	W96
	.byte		VOL   , 35*mus_nextroad_mvl/mxv
	.byte		PAN   , c_v-58
	.byte		BEND  , c_v+1
	.byte	W02
	.byte		N04   , Gs3 , v112
	.byte	W02
	.byte		PAN   , c_v-57
	.byte	W02
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W02
	.byte		PAN   , c_v-55
	.byte	W02
	.byte		N04   , Cs4 
	.byte	W02
	.byte		PAN   , c_v-49
	.byte	W02
	.byte		N04   , Fn4 
	.byte	W02
	.byte		PAN   , c_v-47
	.byte	W02
	.byte		N04   , Gs4 
	.byte	W02
	.byte		PAN   , c_v-41
	.byte	W02
	.byte		N04   , Fn4 
	.byte	W02
	.byte		PAN   , c_v-38
	.byte	W02
	.byte		N04   , Gs4 
	.byte	W02
	.byte		PAN   , c_v-32
	.byte	W02
	.byte		N04   , Cs5 
	.byte	W02
	.byte		PAN   , c_v-28
	.byte	W02
	.byte		N04   , Gs4 
	.byte	W02
	.byte		PAN   , c_v-18
	.byte	W02
	.byte		N04   , Cs5 
	.byte	W02
	.byte		PAN   , c_v-11
	.byte	W02
	.byte		N04   , Fn5 
	.byte	W02
	.byte		PAN   , c_v-3
	.byte	W02
	.byte		N04   , Cs5 
	.byte	W02
	.byte		PAN   , c_v+3
	.byte	W02
	.byte		N04   , Fn5 
	.byte	W02
	.byte		PAN   , c_v+11
	.byte	W02
	.byte		N04   , Gs5 
	.byte	W02
	.byte		PAN   , c_v+19
	.byte	W02
	.byte		N04   , Fn5 
	.byte	W02
	.byte		PAN   , c_v+26
	.byte	W02
	.byte		N04   , Gs5 
	.byte	W02
	.byte		PAN   , c_v+32
	.byte	W02
	.byte		N04   , Cs6 
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W02
	.byte		N04   , Gs5 
	.byte	W02
	.byte		PAN   , c_v+49
	.byte	W02
	.byte		N04   , Cs6 
	.byte	W02
	.byte		PAN   , c_v+61
	.byte	W02
	.byte		N04   , Fn6 
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W02
	.byte		N04   , Cs6 
	.byte	W04
	.byte		        Fn6 
	.byte	W04
	.byte		        Gs6 
	.byte	W02
	.byte		VOL   , 24*mus_nextroad_mvl/mxv
	.byte		PAN   , c_v+58
	.byte	W02
	.byte		N04   , As6 
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W02
	.byte		N04   , Gn6 
	.byte	W02
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		N04   , Ds6 
	.byte	W02
	.byte		PAN   , c_v+2
	.byte	W02
	.byte		N04   , Gn6 
	.byte	W02
	.byte		PAN   , c_v-9
	.byte	W02
	.byte		N04   , Ds6 
	.byte	W02
	.byte		PAN   , c_v-16
	.byte	W02
	.byte		N04   , As5 
	.byte	W02
	.byte		PAN   , c_v-23
	.byte	W02
	.byte		N04   , Ds6 
	.byte	W02
	.byte		PAN   , c_v-29
	.byte	W02
	.byte		N04   , As5 
	.byte	W02
	.byte		PAN   , c_v-32
	.byte	W02
	.byte		N04   , Gn5 
	.byte	W02
	.byte		PAN   , c_v-35
	.byte	W02
	.byte		N04   , As5 
	.byte	W02
	.byte		PAN   , c_v-38
	.byte	W02
	.byte		N04   , Gn5 
	.byte	W02
	.byte		PAN   , c_v-42
	.byte	W02
	.byte		N04   , Ds5 
	.byte	W02
	.byte		PAN   , c_v-45
	.byte	W02
	.byte		N04   , Gn5 
	.byte	W02
	.byte		PAN   , c_v-48
	.byte	W02
	.byte		N04   , Ds5 
	.byte	W02
	.byte		PAN   , c_v-50
	.byte	W02
	.byte		N04   , As4 
	.byte	W02
	.byte		PAN   , c_v-53
	.byte	W02
	.byte		N04   , Ds5 
	.byte	W02
	.byte		PAN   , c_v-56
	.byte	W02
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W02
	.byte		PAN   , c_v-57
	.byte	W02
	.byte		N04   , As4 
	.byte	W02
	.byte		PAN   , c_v-59
	.byte	W02
	.byte		N04   , Gn4 
	.byte	W02
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		N04   , Ds4 
	.byte	W02
	.byte		PAN   , c_v-63
	.byte	W02
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte	W02
	.byte	W02
	.byte		        Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W02
	.byte		PAN   , c_v-31
	.byte	W02
	.byte		N04   , Ds3 
	.byte	W02
	.byte		PAN   , c_v+1
	.byte	W02
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W02
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W02
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		N04   , Fn3 
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W02
	.byte		N04   , Ds3 
	.byte	W02
	.byte		PAN   , c_v-63
	.byte	W02
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W02
	.byte	TEMPO , 122*mus_nextroad_tbs/2
	.byte		VOL   , 18*mus_nextroad_mvl/mxv
	.byte	W02
	.byte		N04   , Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W02
	.byte		PAN   , c_v-31
	.byte	W02
	.byte		N04   , Ds3 
	.byte	W02
	.byte		PAN   , c_v+1
	.byte	W02
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W02
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W02
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		N04   , Fn3 
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W02
	.byte		N04   , Ds3 
	.byte	W02
	.byte		PAN   , c_v-63
	.byte	W02
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W02
	.byte	TEMPO , 120*mus_nextroad_tbs/2
	.byte		VOL   , 11*mus_nextroad_mvl/mxv
	.byte	W02
	.byte		N04   , Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W02
	.byte		PAN   , c_v-31
	.byte	W02
	.byte		N04   , Ds3 
	.byte	W02
	.byte		PAN   , c_v+1
	.byte	W02
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W02
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W02
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		N04   , Fn3 
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W02
	.byte		N04   , Ds3 
	.byte	W02
	.byte		PAN   , c_v-63
	.byte	W02
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Gn2 
	.byte	W02
	.byte		PAN   , c_v-57
	.byte	W02
	.byte		N04   , As2 
	.byte	W02
	.byte		PAN   , c_v-48
	.byte	W02
	.byte		N04   , Cs3 
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W02
	.byte		N04   , Ds3 
	.byte	W02
	.byte		PAN   , c_v+20
	.byte	W02
	.byte		N04   , Gn3 
	.byte	W02
	.byte		PAN   , c_v+43
	.byte	W02
	.byte		N04   , As3 
	.byte	W02
	.byte		PAN   , c_v+61
	.byte	W02
	.byte		N04   , Cs4 
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W02
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W06
	.byte	GOTO
	 .word	mus_nextroad_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_nextroad_2:
	.byte	KEYSH , mus_nextroad_key+0
	.byte		VOICE , 56
	.byte		PAN   , c_v-48
	.byte		LFOS  , 44
	.byte		VOL   , 73*mus_nextroad_mvl/mxv
	.byte		XCMD  , xIECV , 20
	.byte		        xIECL , 14
	.byte	W96
	.byte	W72
	.byte		VOL   , 44*mus_nextroad_mvl/mxv
	.byte	W16
	.byte		N04   , Gs3 , v080
	.byte	W04
	.byte		        As3 
	.byte	W04
mus_nextroad_2_B1:
	.byte		VOICE , 83
	.byte		PAN   , c_v-48
	.byte		MOD   , 3
	.byte		VOL   , 44*mus_nextroad_mvl/mxv
	.byte		N04   , Cn4 , v080
	.byte	W24
	.byte		N04   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W24
	.byte		N04   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W32
	.byte		        Cs4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gs4 
	.byte	W24
	.byte		N04   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W24
	.byte		N04   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		VOICE , 56
	.byte	W96
	.byte		MOD   , 2
	.byte		VOL   , 73*mus_nextroad_mvl/mxv
	.byte	W72
	.byte		N08   , Fn5 , v112
	.byte	W08
	.byte		PAN   , c_v+52
	.byte		N02   , Ds5 , v084
	.byte	W02
	.byte		PAN   , c_v+32
	.byte		N02   , Cs5 , v076
	.byte	W02
	.byte		PAN   , c_v+23
	.byte		N02   , Cn5 , v064
	.byte	W02
	.byte		PAN   , c_v+11
	.byte		N02   , As4 , v060
	.byte	W02
	.byte		PAN   , c_v-20
	.byte		N02   , Gs4 , v052
	.byte	W02
	.byte		PAN   , c_v-32
	.byte		N02   , Fs4 , v044
	.byte	W02
	.byte		PAN   , c_v-37
	.byte		N02   , Fn4 , v036
	.byte	W02
	.byte		PAN   , c_v-56
	.byte		N02   , Ds4 , v032
	.byte	W02
	.byte	W96
mus_nextroad_2_000:
	.byte	W72
	.byte		VOICE , 56
	.byte		N08   , Gn5 , v112
	.byte	W08
	.byte		PAN   , c_v+52
	.byte		N02   , Fs5 , v084
	.byte	W02
	.byte		PAN   , c_v+32
	.byte		N02   , Fn5 , v076
	.byte	W02
	.byte		PAN   , c_v+23
	.byte		N02   , Ds5 , v064
	.byte	W02
	.byte		PAN   , c_v+11
	.byte		N02   , Cs5 , v060
	.byte	W02
	.byte		PAN   , c_v-20
	.byte		N02   , Cn5 , v052
	.byte	W02
	.byte		PAN   , c_v-32
	.byte		N02   , As4 , v044
	.byte	W02
	.byte		PAN   , c_v-37
	.byte		N02   , Gs4 , v036
	.byte	W02
	.byte		PAN   , c_v-56
	.byte		N02   , Fs4 , v032
	.byte	W02
	.byte	PEND
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_nextroad_2_000
	.byte	W96
	.byte	W96
	.byte		VOICE , 60
	.byte		VOL   , 30*mus_nextroad_mvl/mxv
	.byte		PAN   , c_v+47
	.byte	W96
	.byte	W72
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		N72   , Cn4 
	.byte	W72
	.byte		N24   , As3 
	.byte	W24
	.byte		N40   , An3 
	.byte	W40
	.byte		N04   , Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		N48   , Ds3 
	.byte	W48
	.byte	GOTO
	 .word	mus_nextroad_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_nextroad_3:
	.byte	KEYSH , mus_nextroad_key+0
	.byte		VOICE , 58
	.byte		PAN   , c_v+0
	.byte		VOL   , 85*mus_nextroad_mvl/mxv
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W72
	.byte		        c_v+0
	.byte		N24   , Ds1 , v112
	.byte	W12
	.byte		BEND  , c_v+4
	.byte	W04
	.byte		        c_v+22
	.byte	W04
	.byte		        c_v+41
	.byte	W04
mus_nextroad_3_B1:
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		VOL   , 78*mus_nextroad_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N08   , Gs1 , v112
	.byte	W48
	.byte		        Ds1 
	.byte	W48
	.byte		        Fs1 
	.byte	W48
	.byte		        Cs1 
	.byte	W40
	.byte		N04   , Ds1 , v072
	.byte	W04
	.byte		N04   
	.byte	W04
mus_nextroad_3_000:
	.byte		N08   , Gs1 , v112
	.byte	W48
	.byte		        Ds1 
	.byte	W48
	.byte	PEND
	.byte		        Fs1 
	.byte	W24
	.byte		        Cs1 
	.byte	W32
	.byte		N04   , Ds1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte	PATT
	 .word	mus_nextroad_3_000
	.byte		N08   , Fs1 , v112
	.byte	W48
	.byte		        Cs1 
	.byte	W48
	.byte		        Fn1 
	.byte	W48
	.byte		VOL   , 44*mus_nextroad_mvl/mxv
	.byte		N48   , Cs1 
	.byte	W02
	.byte		VOL   , 46*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        51*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        54*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        55*mus_nextroad_mvl/mxv
	.byte	W02
	.byte		        58*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        61*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        64*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        66*mus_nextroad_mvl/mxv
	.byte	W02
	.byte		        68*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        73*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        78*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        81*mus_nextroad_mvl/mxv
	.byte	W02
	.byte		        85*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        88*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        91*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        61*mus_nextroad_mvl/mxv
	.byte		N08   , Fs1 
	.byte	W24
	.byte		        Cs1 
	.byte	W24
	.byte		        Ds1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N24   , Gn1 
	.byte	W24
	.byte		VOICE , 38
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		N08   , Cs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        As0 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		N08   , Cs1 
	.byte	W16
	.byte		VOICE , 56
	.byte	W08
	.byte		VOL   , 74*mus_nextroad_mvl/mxv
	.byte		N08   , Cn5 
	.byte	W10
	.byte		VOICE , 38
	.byte	W06
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		N08   , Cn2 
	.byte	W08
	.byte		PAN   , c_v+0
	.byte		N08   , Ds1 
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte		N08   
	.byte	W16
	.byte		N04   , Ds2 
	.byte	W08
	.byte		N08   , Cs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Cn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gn0 
	.byte	W08
	.byte		        An0 
	.byte	W08
	.byte		        Bn0 
	.byte	W08
	.byte		N08   , Cn1 
	.byte	W24
	.byte		VOICE , 56
	.byte		VOL   , 74*mus_nextroad_mvl/mxv
	.byte		N08   , Ds5 
	.byte	W10
	.byte		VOICE , 38
	.byte	W06
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		N08   , Cn2 
	.byte	W08
	.byte		        Fn1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , En1 
	.byte	W08
	.byte		        Ds1 
	.byte	W16
	.byte		N04   , Ds2 
	.byte	W08
	.byte		        As0 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		N08   , Cs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        As0 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		N08   , Cs1 
	.byte	W40
	.byte		        Cn2 
	.byte	W08
	.byte		        Ds1 
	.byte	W16
	.byte		N04   
	.byte	W32
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W04
	.byte		VOICE , 56
	.byte	W04
	.byte		VOL   , 73*mus_nextroad_mvl/mxv
	.byte		N08   , Ds5 
	.byte	W10
	.byte		VOICE , 38
	.byte	W02
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		N08   , As1 
	.byte	W08
	.byte		        Cn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gn0 
	.byte	W08
	.byte		        An0 
	.byte	W08
	.byte		        Bn0 
	.byte	W08
	.byte		N08   , Cn1 
	.byte	W40
	.byte		        Cn2 
	.byte	W08
	.byte		        Fn1 
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N08   , En1 
	.byte	W08
	.byte		        Ds1 
	.byte	W16
	.byte		N04   , Ds2 
	.byte	W08
	.byte		N08   , Dn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W96
	.byte		        Ds1 
	.byte	W96
	.byte		N72   , Fn1 
	.byte	W96
	.byte	W72
	.byte		N24   , Ds1 
	.byte	W24
	.byte	GOTO
	 .word	mus_nextroad_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_nextroad_4:
	.byte	KEYSH , mus_nextroad_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		MOD   , 1
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W88
	.byte		N04   , Cn3 , v124
	.byte	W04
	.byte		        Cs3 
	.byte	W04
mus_nextroad_4_B1:
	.byte		PAN   , c_v+3
	.byte		N08   , Ds3 , v124
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W05
	.byte		N08   , Ds3 , v032
	.byte	W08
	.byte		N04   , Cn3 , v124
	.byte	W04
	.byte		        Cn3 , v032
	.byte	W04
	.byte		        As3 , v124
	.byte	W04
	.byte		N08   , As3 , v032
	.byte	W12
	.byte		N20   , Gs3 , v124
	.byte	W20
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		N08   , Fn3 , v032
	.byte	W12
	.byte		N04   , Ds3 , v124
	.byte	W04
	.byte		        Ds3 , v032
	.byte	W04
	.byte		N48   , Cs3 , v124
	.byte	W24
	.byte		MOD   , 8
	.byte		VOL   , 95*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        84*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        73*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        63*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        51*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        45*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_nextroad_mvl/mxv
	.byte		N08   , Cs3 , v032
	.byte	W12
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte	W12
	.byte		N04   , Cn3 , v124
	.byte	W04
	.byte		N08   , Cn3 , v032
	.byte	W12
	.byte		N04   , Cs3 , v124
	.byte	W04
	.byte		        Cs3 , v032
	.byte	W04
	.byte		N48   , Ds3 , v124
	.byte	W24
	.byte		MOD   , 8
	.byte		VOL   , 95*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        84*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        73*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        63*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        51*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        45*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		VOICE , 60
	.byte		MOD   , 0
	.byte		VOL   , 38*mus_nextroad_mvl/mxv
	.byte		N08   , Ds3 , v032
	.byte	W04
	.byte		VOL   , 36*mus_nextroad_mvl/mxv
	.byte	W08
	.byte		        97*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		N04   , Cn4 , v124
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N08   , Ds4 , v032
	.byte	W12
	.byte		N04   , Cn4 , v124
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		N52   , Ds4 
	.byte	W24
	.byte		MOD   , 8
	.byte		VOL   , 95*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        84*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        73*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        63*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        51*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        45*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 1
	.byte		VOL   , 38*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		N04   , Ds4 , v032
	.byte	W04
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		N04   , Fs3 , v124
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		        Fs3 , v124
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		        Fs3 , v124
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		        Cs3 , v124
	.byte	W04
	.byte		        Cs3 , v032
	.byte	W04
	.byte		        Gn3 , v124
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N08   , Ds3 , v124
	.byte	W08
	.byte		N04   , Ds3 , v032
	.byte	W08
	.byte		        Cn3 , v124
	.byte	W04
	.byte		        Cn3 , v032
	.byte	W04
	.byte		        Ds4 , v124
	.byte	W04
	.byte		        Ds4 , v032
	.byte	W12
	.byte		N20   , Cs4 , v124
	.byte	W20
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N08   , As3 , v032
	.byte	W12
	.byte		N04   , Gs3 , v124
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W04
	.byte		N48   , Fs3 , v124
	.byte	W24
	.byte		MOD   , 8
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        89*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        82*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        75*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        70*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        63*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 1
	.byte		N08   , Fs3 , v032
	.byte	W08
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte	W16
	.byte		N04   , Fn3 , v124
	.byte	W04
	.byte		N08   , Fn3 , v032
	.byte	W12
	.byte		N04   , Fs3 , v124
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		N72   , Gs3 , v124
	.byte	W08
	.byte		VOL   , 80*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        72*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        64*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        44*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        38*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        35*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        38*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        42*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        48*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        53*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        64*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        71*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        76*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        84*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        88*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        95*mus_nextroad_mvl/mxv
	.byte		MOD   , 8
	.byte		N04   , Cs4 
	.byte	W04
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		N08   , Cs4 , v032
	.byte	W04
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte	W08
	.byte		N04   , Ds4 , v124
	.byte	W04
	.byte		        Ds4 , v032
	.byte	W04
	.byte		MOD   , 1
	.byte		N32   , En4 , v124
	.byte	W04
	.byte		VOL   , 93*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        89*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        80*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 9
	.byte	W04
	.byte		VOL   , 74*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        70*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        67*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        62*mus_nextroad_mvl/mxv
	.byte		MOD   , 0
	.byte		N04   , Fs4 , v112
	.byte	W04
	.byte		VOL   , 56*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		        51*mus_nextroad_mvl/mxv
	.byte		N04   , En4 
	.byte	W04
	.byte		VOL   , 34*mus_nextroad_mvl/mxv
	.byte	W04
	.byte		VOICE , 56
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Ds4 
	.byte	W04
	.byte		VOL   , 76*mus_nextroad_mvl/mxv
	.byte	W01
	.byte		        70*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        61*mus_nextroad_mvl/mxv
	.byte	W01
	.byte		        56*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        50*mus_nextroad_mvl/mxv
	.byte	W01
	.byte		        45*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        41*mus_nextroad_mvl/mxv
	.byte		MOD   , 8
	.byte	W01
	.byte		VOL   , 36*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        35*mus_nextroad_mvl/mxv
	.byte	W01
	.byte		        38*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        42*mus_nextroad_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Ds5 , v124
	.byte	W01
	.byte		VOL   , 45*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        54*mus_nextroad_mvl/mxv
	.byte	W01
	.byte		        58*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        62*mus_nextroad_mvl/mxv
	.byte	W01
	.byte		        66*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		        72*mus_nextroad_mvl/mxv
	.byte	W01
	.byte		        76*mus_nextroad_mvl/mxv
	.byte	W03
	.byte		MOD   , 10
	.byte		VOL   , 87*mus_nextroad_mvl/mxv
	.byte	W01
	.byte		        97*mus_nextroad_mvl/mxv
	.byte	W07
	.byte		MOD   , 1
	.byte		VOL   , 90*mus_nextroad_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N16   , Cn5 
	.byte	W16
	.byte		N04   , Cs5 
	.byte	W08
	.byte		        Ds5 
	.byte	W04
	.byte		N08   , Ds5 , v032
	.byte	W12
	.byte		N24   , Cs5 , v124
	.byte	W16
	.byte		MOD   , 8
	.byte	W08
	.byte		        1
	.byte		N04   , Cn5 
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W04
	.byte		        As4 , v124
	.byte	W04
	.byte		        As4 , v032
	.byte	W04
	.byte		        Cn5 , v124
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W04
	.byte		        Gs4 , v124
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W04
	.byte		N48   , As4 , v124
	.byte	W24
	.byte		MOD   , 10
	.byte	W24
	.byte		        1
	.byte		N08   , As4 , v032
	.byte	W48
	.byte		N16   , Gn4 , v124
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W04
	.byte		        As4 , v124
	.byte	W04
	.byte		        As4 , v032
	.byte	W12
	.byte		N24   , Ds5 , v124
	.byte	W08
	.byte		MOD   , 6
	.byte	W16
	.byte		        1
	.byte		N04   , Cs5 
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		        Cn5 , v124
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W04
	.byte		        Cs5 , v124
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		        Gn4 , v124
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W04
	.byte		N16   , As4 , v124
	.byte	W16
	.byte		N04   , Cn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		N24   , An4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Cn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N48   , Gs4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        1
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Gn4 , v032
	.byte	W16
	.byte		N04   , Gs4 , v124
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W04
	.byte		N24   , Gs4 , v124
	.byte	W08
	.byte		MOD   , 8
	.byte	W16
	.byte		        1
	.byte		N16   , Gn4 
	.byte	W16
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Fn4 , v032
	.byte	W04
	.byte		N16   , Fn4 , v124
	.byte	W16
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        Gs4 , v032
	.byte	W08
	.byte		        Gn4 , v124
	.byte	W08
	.byte		        Gn4 , v032
	.byte	W08
	.byte		N40   , Fn4 , v124
	.byte	W24
	.byte		MOD   , 8
	.byte	W16
	.byte		        1
	.byte		N32   , Ds4 
	.byte	W16
	.byte		MOD   , 8
	.byte	W16
	.byte		        1
	.byte		N20   , Cn4 
	.byte	W20
	.byte		N04   , Bn4 
	.byte	W04
	.byte		TIE   , Cn5 
	.byte	W24
	.byte		MOD   , 2
	.byte	W24
	.byte		        6
	.byte	W24
	.byte		        10
	.byte	W24
	.byte		        1
	.byte	W16
	.byte		EOT   
	.byte		N08   , As4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Gs4 , v032
	.byte	W08
	.byte		N24   , Gs4 , v124
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Gn4 , v032
	.byte	W08
	.byte		        Gs4 , v124
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        As4 , v032
	.byte	W08
	.byte		N24   , As4 , v124
	.byte	W08
	.byte		MOD   , 8
	.byte	W16
	.byte		        1
	.byte		N08   , Gs4 
	.byte	W08
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        1
	.byte		N72   , An4 
	.byte	W48
	.byte		MOD   , 8
	.byte	W24
	.byte		        1
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N48   , Fn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        1
	.byte		N04   , Ds4 
	.byte	W04
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		N04   , Fn4 
	.byte	W04
	.byte		VOL   , 83*mus_nextroad_mvl/mxv
	.byte		N04   , Ds4 
	.byte	W04
	.byte		VOL   , 69*mus_nextroad_mvl/mxv
	.byte		N04   , Fn4 
	.byte	W04
	.byte		VOL   , 63*mus_nextroad_mvl/mxv
	.byte		N04   , Ds4 
	.byte	W04
	.byte		VOL   , 53*mus_nextroad_mvl/mxv
	.byte		N04   , Fn4 
	.byte	W04
	.byte		VOL   , 47*mus_nextroad_mvl/mxv
	.byte		N04   , Ds4 
	.byte	W04
	.byte		VOL   , 38*mus_nextroad_mvl/mxv
	.byte		N04   , Fn4 
	.byte	W04
	.byte		VOL   , 29*mus_nextroad_mvl/mxv
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		N04   , Cn2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte	GOTO
	 .word	mus_nextroad_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_nextroad_5:
	.byte	KEYSH , mus_nextroad_key+0
	.byte		VOICE , 47
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		PAN   , c_v-23
	.byte	W96
mus_nextroad_5_000:
	.byte	W88
	.byte		N04   , Cn2 , v112
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PEND
mus_nextroad_5_B1:
	.byte		N08   , Ds2 , v112
	.byte	W48
	.byte		N16   , Gs1 
	.byte	W48
	.byte		N08   , Cs2 
	.byte	W48
	.byte		N16   , Fs1 
	.byte	W40
	.byte		N04   , Cs2 , v080
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   , Ds2 , v112
	.byte	W48
	.byte		N16   , Gs1 
	.byte	W40
	.byte		N04   , Fs2 , v080
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		N12   , Gs2 , v104
	.byte	W24
	.byte		        Ds2 , v112
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Cs2 
	.byte	W16
	.byte		N04   , Gs1 , v080
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   , Ds2 , v112
	.byte	W40
	.byte		N04   , Gs1 
	.byte	W08
	.byte		N16   
	.byte	W48
	.byte		N12   , Fs2 
	.byte	W24
	.byte		        As1 
	.byte	W16
	.byte		N08   , Fs1 
	.byte	W08
	.byte		N12   , Cs2 
	.byte	W24
	.byte		N08   , Fs1 
	.byte	W24
	.byte		N10   , Gs2 
	.byte	W48
	.byte		N04   , Gs1 , v024
	.byte	W04
	.byte		        Gs1 , v032
	.byte	W04
	.byte		        Gs1 , v040
	.byte	W04
	.byte		        Gs1 , v048
	.byte	W04
	.byte		        Gs1 , v056
	.byte	W04
	.byte		        Gs1 , v064
	.byte	W04
	.byte		        Gs1 , v072
	.byte	W04
	.byte		        Gs1 , v080
	.byte	W04
	.byte		        Gs1 , v088
	.byte	W04
	.byte		        Gs1 , v096
	.byte	W04
	.byte		        Gs1 , v104
	.byte	W04
	.byte		        Gs1 , v112
	.byte	W04
	.byte		N08   , Cs2 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        Ds2 , v116
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N04   , Gn2 , v120
	.byte	W04
	.byte		        Gn2 , v112
	.byte	W04
	.byte		N08   , Ds2 , v116
	.byte	W08
	.byte		        Ds2 , v112
	.byte	W08
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W88
	.byte		N04   , Cn3 
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N16   , Cs2 
	.byte	W64
	.byte		N08   
	.byte	W32
	.byte		N24   , Ds2 
	.byte	W64
	.byte		N08   , Ds2 , v020
	.byte	W08
	.byte		N04   , Ds2 , v036
	.byte	W04
	.byte		        Ds2 , v048
	.byte	W04
	.byte		        Ds2 , v064
	.byte	W04
	.byte		        Ds2 , v072
	.byte	W04
	.byte		        Ds2 , v092
	.byte	W04
	.byte		        Ds2 , v096
	.byte	W04
	.byte		N16   , Fn2 , v112
	.byte	W96
	.byte	PATT
	 .word	mus_nextroad_5_000
	.byte	GOTO
	 .word	mus_nextroad_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_nextroad_6:
	.byte	KEYSH , mus_nextroad_key+0
	.byte		VOICE , 48
	.byte		PAN   , c_v-39
	.byte		VOL   , 48*mus_nextroad_mvl/mxv
	.byte		LFOS  , 44
	.byte	W96
	.byte	W96
mus_nextroad_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+40
	.byte		N04   , Cs3 , v112
	.byte	W04
	.byte		PAN   , c_v+8
	.byte		N04   , En3 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , Gs3 
	.byte	W04
	.byte		PAN   , c_v-33
	.byte		N04   , En3 
	.byte	W04
	.byte		PAN   , c_v-39
	.byte		N04   , Gs3 
	.byte	W04
	.byte		PAN   , c_v-40
	.byte		N04   , Cs4 
	.byte	W04
	.byte		PAN   , c_v-37
	.byte		N04   , Gs3 
	.byte	W04
	.byte		PAN   , c_v-30
	.byte		N04   , Cs4 
	.byte	W04
	.byte		PAN   , c_v-17
	.byte		N04   , En4 
	.byte	W04
	.byte		PAN   , c_v-12
	.byte		N04   , Cs4 
	.byte	W04
	.byte		PAN   , c_v-5
	.byte		N04   , En4 
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N04   , Gs4 
	.byte	W04
	.byte		PAN   , c_v+6
	.byte		N04   , Gn5 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		PAN   , c_v+11
	.byte		N04   , As4 
	.byte	W04
	.byte		PAN   , c_v+13
	.byte		N04   , Ds5 
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , As4 
	.byte	W04
	.byte		PAN   , c_v+20
	.byte		N04   , Gn4 
	.byte	W04
	.byte		PAN   , c_v+24
	.byte		N04   , As4 
	.byte	W04
	.byte		PAN   , c_v+27
	.byte		N04   , Gn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Ds4 
	.byte	W04
	.byte		PAN   , c_v+36
	.byte		N04   , Gn4 
	.byte	W04
	.byte		PAN   , c_v+40
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		PAN   , c_v-54
	.byte	W48
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Ds5 
	.byte	W32
	.byte		PAN   , c_v+60
	.byte		N04   , As4 
	.byte	W01
	.byte		PAN   , c_v+58
	.byte	W03
	.byte		        c_v+50
	.byte		N04   , Cn5 
	.byte	W04
	.byte		        As4 
	.byte	W01
	.byte		PAN   , c_v+19
	.byte	W03
	.byte		N04   , Gs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W01
	.byte		PAN   , c_v+6
	.byte	W03
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		PAN   , c_v-4
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		PAN   , c_v-12
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        Cs4 
	.byte	W01
	.byte		PAN   , c_v-19
	.byte	W03
	.byte		N04   , Ds4 
	.byte	W04
	.byte		PAN   , c_v-23
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Cn4 
	.byte	W01
	.byte		PAN   , c_v-24
	.byte	W03
	.byte		N04   , Cs4 
	.byte	W01
	.byte		PAN   , c_v-26
	.byte	W03
	.byte		        c_v-28
	.byte		N04   , Cn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As3 
	.byte	W01
	.byte		PAN   , c_v-37
	.byte	W03
	.byte		        c_v-40
	.byte		N04   , Cn4 
	.byte	W01
	.byte		PAN   , c_v-43
	.byte	W03
	.byte		        c_v-44
	.byte		N04   , As3 
	.byte	W04
	.byte		N40   
	.byte	W40
	.byte		N04   , An3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W32
	.byte	W96
	.byte	W48
	.byte		        Cn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W32
	.byte	W96
	.byte		PAN   , c_v+60
	.byte		N04   , Ds5 
	.byte	W01
	.byte		PAN   , c_v+58
	.byte	W03
	.byte		        c_v+50
	.byte		N04   , Cn5 
	.byte	W04
	.byte		        An4 
	.byte	W01
	.byte		PAN   , c_v+19
	.byte	W03
	.byte		N04   , Cn5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fn4 
	.byte	W01
	.byte		PAN   , c_v+6
	.byte	W03
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v-4
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v-12
	.byte		N04   , An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W01
	.byte		PAN   , c_v-19
	.byte	W03
	.byte		N04   , An3 
	.byte	W04
	.byte		PAN   , c_v-23
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W01
	.byte		PAN   , c_v-24
	.byte	W03
	.byte		N04   , Fn3 
	.byte	W01
	.byte		PAN   , c_v-26
	.byte	W03
	.byte		        c_v-28
	.byte		N04   , Ds3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Fn3 
	.byte	W01
	.byte		PAN   , c_v-37
	.byte	W03
	.byte		        c_v-40
	.byte		N04   , Ds3 
	.byte	W01
	.byte		PAN   , c_v-43
	.byte	W03
	.byte		        c_v-44
	.byte		N04   , Cn3 
	.byte	W04
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_nextroad_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_nextroad_7:
	.byte	KEYSH , mus_nextroad_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		PAN   , c_v-63
	.byte		VOL   , 61*mus_nextroad_mvl/mxv
	.byte		XCMD  , xIECV , 14
	.byte		        xIECL , 12
	.byte		BENDR , 12
	.byte	W96
	.byte		MOD   , 0
	.byte	W72
	.byte		VOL   , 36*mus_nextroad_mvl/mxv
	.byte	W24
mus_nextroad_7_B1:
	.byte		VOICE , 85
	.byte		PAN   , c_v-63
	.byte		VOL   , 36*mus_nextroad_mvl/mxv
	.byte		N04   , Ds3 , v112
	.byte	W24
	.byte		        Ds3 , v096
	.byte	W32
	.byte		        Ds3 , v112
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cs3 
	.byte	W24
	.byte		N04   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W16
	.byte		        Ds3 , v096
	.byte	W08
	.byte		N04   
	.byte	W32
	.byte		        Ds3 , v112
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cs3 
	.byte	W16
	.byte		        Cs3 , v096
	.byte	W08
	.byte		N04   
	.byte	W32
	.byte		        As2 , v112
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Ds4 
	.byte	W24
	.byte		N04   
	.byte	W32
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		        Cs4 , v096
	.byte	W08
	.byte		N04   
	.byte	W32
	.byte		        Cs4 , v112
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Fn3 
	.byte	W24
	.byte		        Fn3 , v096
	.byte	W32
	.byte		        Fn3 , v112
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		VOL   , 65*mus_nextroad_mvl/mxv
	.byte		N32   , En4 
	.byte	W24
	.byte		MOD   , 12
	.byte	W08
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		MOD   , 0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 14
	.byte	W12
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		VOICE , 84
	.byte		MOD   , 0
	.byte		VOL   , 40*mus_nextroad_mvl/mxv
	.byte		N64   , Gs2 
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		        14
	.byte	W12
	.byte		        0
	.byte	W04
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N08   , Gs2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N64   , As2 
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		        14
	.byte	W16
	.byte		        3
	.byte		N04   , An2 
	.byte	W08
	.byte		N08   , As2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N64   , Cn3 
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		        14
	.byte	W16
	.byte		        3
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N08   , Cn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N04   , Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N04   , Ds3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N64   , Gs3 
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		        16
	.byte	W16
	.byte		        3
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		N64   , As3 
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		        14
	.byte	W16
	.byte		        3
	.byte		N04   , An3 
	.byte	W08
	.byte		N08   , Gn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N64   , Cn4 
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		        14
	.byte	W16
	.byte		        3
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N08   , Cn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N48   , Cn4 
	.byte	W24
	.byte		MOD   , 14
	.byte	W24
	.byte		VOICE , 87
	.byte		MOD   , 3
	.byte		VOL   , 36*mus_nextroad_mvl/mxv
	.byte		PAN   , c_v-58
	.byte		N04   , Gs3 
	.byte	W04
	.byte		PAN   , c_v-57
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		PAN   , c_v-55
	.byte		N04   , Cs4 
	.byte	W04
	.byte		PAN   , c_v-49
	.byte		N04   , Fn4 
	.byte	W04
	.byte		PAN   , c_v-47
	.byte		N04   , Gs4 
	.byte	W04
	.byte		PAN   , c_v-41
	.byte		N04   , Fn4 
	.byte	W04
	.byte		PAN   , c_v-38
	.byte		N04   , Gs4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Cs5 
	.byte	W04
	.byte		PAN   , c_v-28
	.byte		N04   , Gs4 
	.byte	W04
	.byte		PAN   , c_v-18
	.byte		N04   , Cs5 
	.byte	W04
	.byte		PAN   , c_v-11
	.byte		N04   , Fn5 
	.byte	W04
	.byte		PAN   , c_v-3
	.byte		N04   , Cs5 
	.byte	W04
	.byte		PAN   , c_v+3
	.byte		N04   , Fn5 
	.byte	W04
	.byte		PAN   , c_v+11
	.byte		N04   , Gs5 
	.byte	W04
	.byte		PAN   , c_v+19
	.byte		N04   , Fn5 
	.byte	W04
	.byte		PAN   , c_v+26
	.byte		N04   , Gs5 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Cs6 
	.byte	W04
	.byte		PAN   , c_v+40
	.byte		N04   , Gs5 
	.byte	W04
	.byte		PAN   , c_v+49
	.byte		N04   , Cs6 
	.byte	W04
	.byte		PAN   , c_v+61
	.byte		N04   , Fn6 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cs6 
	.byte	W04
	.byte		        Fn6 
	.byte	W04
	.byte		        Gs6 
	.byte	W04
	.byte		PAN   , c_v+58
	.byte		VOL   , 28*mus_nextroad_mvl/mxv
	.byte		N04   , As6 
	.byte	W04
	.byte		PAN   , c_v+40
	.byte		N04   , Gn6 
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Ds6 
	.byte	W04
	.byte		PAN   , c_v+2
	.byte		N04   , Gn6 
	.byte	W04
	.byte		PAN   , c_v-9
	.byte		N04   , Ds6 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , As5 
	.byte	W04
	.byte		PAN   , c_v-23
	.byte		N04   , Ds6 
	.byte	W04
	.byte		PAN   , c_v-29
	.byte		N04   , As5 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Gn5 
	.byte	W04
	.byte		PAN   , c_v-35
	.byte		N04   , As5 
	.byte	W04
	.byte		PAN   , c_v-38
	.byte		N04   , Gn5 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Ds5 
	.byte	W04
	.byte		PAN   , c_v-45
	.byte		N04   , Gn5 
	.byte	W04
	.byte		PAN   , c_v-48
	.byte		N04   , Ds5 
	.byte	W04
	.byte		PAN   , c_v-50
	.byte		N04   , As4 
	.byte	W04
	.byte		PAN   , c_v-53
	.byte		N04   , Ds5 
	.byte	W04
	.byte		PAN   , c_v-56
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		PAN   , c_v-57
	.byte		N04   , As4 
	.byte	W04
	.byte		PAN   , c_v-59
	.byte		N04   , Gn4 
	.byte	W04
	.byte		PAN   , c_v-61
	.byte		N04   , Ds4 
	.byte	W04
	.byte		PAN   , c_v-63
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		PAN   , c_v-31
	.byte		N04   , Ds3 
	.byte	W04
	.byte		PAN   , c_v+1
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Fn3 
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N04   , Ds3 
	.byte	W04
	.byte		PAN   , c_v-63
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		VOL   , 21*mus_nextroad_mvl/mxv
	.byte		N04   , Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		PAN   , c_v-31
	.byte		N04   , Ds3 
	.byte	W04
	.byte		PAN   , c_v+1
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Fn3 
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N04   , Ds3 
	.byte	W04
	.byte		PAN   , c_v-63
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		VOL   , 15*mus_nextroad_mvl/mxv
	.byte		N04   , Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		PAN   , c_v-31
	.byte		N04   , Ds3 
	.byte	W04
	.byte		PAN   , c_v+1
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Fn3 
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N04   , Ds3 
	.byte	W04
	.byte		PAN   , c_v-63
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		PAN   , c_v-57
	.byte		N04   , As2 
	.byte	W04
	.byte		PAN   , c_v-48
	.byte		N04   , Cs3 
	.byte	W04
	.byte		PAN   , c_v-8
	.byte		N04   , Ds3 
	.byte	W04
	.byte		PAN   , c_v+20
	.byte		N04   , Gn3 
	.byte	W04
	.byte		PAN   , c_v+43
	.byte		N04   , As3 
	.byte	W04
	.byte		PAN   , c_v+61
	.byte		N04   , Cs4 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte	GOTO
	 .word	mus_nextroad_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_nextroad_8:
	.byte	KEYSH , mus_nextroad_key+0
	.byte		VOICE , 81
	.byte		VOL   , 48*mus_nextroad_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte	W96
	.byte	W96
mus_nextroad_8_B1:
	.byte		VOICE , 81
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+0
	.byte		N48   , As2 , v112
	.byte	W24
	.byte		MOD   , 8
	.byte	W24
	.byte		        2
	.byte		N04   , Ds3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		MOD   , 4
	.byte		PAN   , c_v+63
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
mus_nextroad_8_000:
	.byte		N16   , Fn3 , v112
	.byte	W16
	.byte		N04   , Ds2 
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N04   , Ds2 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Ds2 
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N04   , Ds2 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_nextroad_8_000
	.byte		N16   , As3 , v112
	.byte	W16
	.byte		N04   , Gs2 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , Gs2 
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N04   , Gs2 
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , Gs2 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Cs2 
	.byte	W08
	.byte	PATT
	 .word	mus_nextroad_8_000
	.byte	PATT
	 .word	mus_nextroad_8_000
	.byte		N36   , An3 , v112
	.byte	W24
	.byte		MOD   , 8
	.byte	W12
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		MOD   , 4
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N04   , An3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Gs5 
	.byte	W04
	.byte		VOL   , 38*mus_nextroad_mvl/mxv
	.byte		N04   , As5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		VOL   , 30*mus_nextroad_mvl/mxv
	.byte		N04   , Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		VOL   , 22*mus_nextroad_mvl/mxv
	.byte		N04   , Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte	GOTO
	 .word	mus_nextroad_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_nextroad_9:
	.byte	KEYSH , mus_nextroad_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 61*mus_nextroad_mvl/mxv
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v096
	.byte	W16
	.byte		        En1 , v112
	.byte	W04
	.byte	W12
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
mus_nextroad_9_B1:
mus_nextroad_9_000:
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v088
	.byte	W08
	.byte		        En1 , v112
	.byte	W16
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_nextroad_9_000
	.byte	PATT
	 .word	mus_nextroad_9_000
	.byte	PATT
	 .word	mus_nextroad_9_000
	.byte	PATT
	 .word	mus_nextroad_9_000
	.byte	PATT
	 .word	mus_nextroad_9_000
	.byte	PATT
	 .word	mus_nextroad_9_000
	.byte	W48
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		        En1 , v096
	.byte	W08
	.byte		        En1 , v112
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		VOL   , 97*mus_nextroad_mvl/mxv
	.byte		N04   , Cn1 , v076
	.byte		N48   , An2 , v108
	.byte	W08
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W08
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
mus_nextroad_9_001:
	.byte		N04   , Cn1 , v127
	.byte	W08
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W16
	.byte		        Dn1 , v112
	.byte	W08
	.byte	PEND
mus_nextroad_9_002:
	.byte		N04   , Cn1 , v127
	.byte	W08
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W08
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
	.byte	PEND
	.byte		        Cn1 , v127
	.byte	W08
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W04
	.byte		        Dn1 , v112
	.byte	W04
	.byte		        Cn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn1 , v127
	.byte		N48   , An2 , v108
	.byte	W08
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W08
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
	.byte	PATT
	 .word	mus_nextroad_9_001
	.byte	PATT
	 .word	mus_nextroad_9_002
	.byte		N04   , Cn1 , v127
	.byte	W08
	.byte		N08   , Fs1 , v112
	.byte	W08
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W08
	.byte		        Dn1 , v112
	.byte		N08   , Fs1 
	.byte	W08
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Dn1 , v127
	.byte	W04
	.byte		        Dn1 , v112
	.byte	W04
	.byte		        Cn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		VOL   , 62*mus_nextroad_mvl/mxv
	.byte		N04   , En1 
	.byte		N48   , An2 
	.byte	W16
	.byte		N04   , En1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte		N48   , An2 
	.byte	W12
	.byte		N04   , En1 
	.byte	W12
	.byte		N04   
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		N04   
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        En1 , v052
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	GOTO
	 .word	mus_nextroad_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_nextroad_10:
	.byte	KEYSH , mus_nextroad_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		VOL   , 32*mus_nextroad_mvl/mxv
	.byte		N01   , An3 , v112
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N01   , An3 , v112
	.byte	W16
	.byte		        An3 , v096
	.byte	W16
	.byte		        An3 , v112
	.byte	W16
	.byte		N01   
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W16
	.byte		        An3 , v096
	.byte	W08
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
mus_nextroad_10_B1:
	.byte		VOICE , 127
	.byte		PAN   , c_v-63
	.byte		VOL   , 32*mus_nextroad_mvl/mxv
	.byte		N01   , An3 , v112
	.byte	W16
	.byte		N01   
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		        An3 , v088
	.byte	W08
	.byte		        An3 , v112
	.byte	W16
	.byte		        An3 , v096
	.byte	W08
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
mus_nextroad_10_000:
	.byte		PAN   , c_v+63
	.byte		N01   , An3 , v112
	.byte	W16
	.byte		N01   
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		        An3 , v088
	.byte	W08
	.byte		        An3 , v112
	.byte	W16
	.byte		        An3 , v096
	.byte	W08
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte	PEND
mus_nextroad_10_001:
	.byte		PAN   , c_v-63
	.byte		N01   , An3 , v112
	.byte	W16
	.byte		N01   
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		        An3 , v088
	.byte	W08
	.byte		        An3 , v112
	.byte	W16
	.byte		        An3 , v096
	.byte	W08
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_nextroad_10_000
	.byte	PATT
	 .word	mus_nextroad_10_001
	.byte	PATT
	 .word	mus_nextroad_10_000
	.byte	PATT
	 .word	mus_nextroad_10_001
	.byte		PAN   , c_v+63
	.byte		VOL   , 41*mus_nextroad_mvl/mxv
	.byte		N01   , An3 , v112
	.byte	W16
	.byte		N01   
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		        An3 , v088
	.byte	W08
	.byte		        An3 , v112
	.byte	W16
	.byte		        An3 , v096
	.byte	W08
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		VOL   , 48*mus_nextroad_mvl/mxv
	.byte		N01   , An5 , v124
	.byte	W08
	.byte		        An5 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        An5 , v112
	.byte	W08
	.byte		        An5 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        An5 , v112
	.byte	W08
	.byte		        An5 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        An5 , v112
	.byte	W08
	.byte		        An5 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
mus_nextroad_10_002:
	.byte		N01   , An5 , v124
	.byte	W08
	.byte		        An5 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        An5 , v112
	.byte	W08
	.byte		        An5 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        An5 , v112
	.byte	W08
	.byte		        An5 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		        An5 , v112
	.byte	W08
	.byte		        An5 , v080
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_nextroad_10_002
	.byte	PATT
	 .word	mus_nextroad_10_002
	.byte	PATT
	 .word	mus_nextroad_10_002
	.byte	PATT
	 .word	mus_nextroad_10_002
	.byte	PATT
	 .word	mus_nextroad_10_002
	.byte	PATT
	 .word	mus_nextroad_10_002
	.byte		PAN   , c_v-63
	.byte		VOL   , 36*mus_nextroad_mvl/mxv
	.byte		N01   , An3 , v112
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N01   , An3 , v112
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N01   , An3 , v112
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N01   
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N01   , An3 , v112
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W16
	.byte		N01   
	.byte	W08
	.byte		N01   
	.byte	W04
	.byte		        An3 , v080
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte	GOTO
	 .word	mus_nextroad_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_nextroad:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_nextroad_pri	@ Priority
	.byte	mus_nextroad_rev	@ Reverb.

	.word	mus_nextroad_grp

	.word	mus_nextroad_1
	.word	mus_nextroad_2
	.word	mus_nextroad_3
	.word	mus_nextroad_4
	.word	mus_nextroad_5
	.word	mus_nextroad_6
	.word	mus_nextroad_7
	.word	mus_nextroad_8
	.word	mus_nextroad_9
	.word	mus_nextroad_10

	.end
