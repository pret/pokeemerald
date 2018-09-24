	.include "MPlayDef.s"

	.equ	mus_rg_purin_grp, voicegroup135
	.equ	mus_rg_purin_pri, 5
	.equ	mus_rg_purin_rev, reverb_set+50
	.equ	mus_rg_purin_mvl, 127
	.equ	mus_rg_purin_key, 0
	.equ	mus_rg_purin_tbs, 1
	.equ	mus_rg_purin_exg, 0
	.equ	mus_rg_purin_cmp, 1

	.section .rodata
	.global	mus_rg_purin
	.align	2

@********************** Track  1 **********************@

mus_rg_purin_1:
	.byte	KEYSH , mus_rg_purin_key+0
	.byte	TEMPO , 146*mus_rg_purin_tbs/2
	.byte		VOICE , 21
	.byte		LFOS  , 50
	.byte		BENDR , 12
	.byte		VOL   , 22*mus_rg_purin_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v+2
	.byte		N52   , En5 , v100
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 17*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        3*mus_rg_purin_mvl/mxv
	.byte		MOD   , 20
	.byte	W06
	.byte		VOL   , 2*mus_rg_purin_mvl/mxv
	.byte	W04
	.byte		N12   , Bn5 
	.byte	W02
	.byte		MOD   , 1
	.byte		VOL   , 22*mus_rg_purin_mvl/mxv
	.byte	W10
	.byte		N36   , Gs5 
	.byte	W08
	.byte		VOL   , 17*mus_rg_purin_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 13*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        7*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        4*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        4*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		MOD   , 1
	.byte	W01
	.byte		N48   , Fs5 
	.byte	W02
	.byte		VOL   , 22*mus_rg_purin_mvl/mxv
	.byte	W09
	.byte		MOD   , 7
	.byte	W09
	.byte		VOL   , 15*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        13*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        8*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        4*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        2*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		MOD   , 1
	.byte	W01
	.byte		N12   , Gs5 
	.byte	W02
	.byte		VOL   , 22*mus_rg_purin_mvl/mxv
	.byte	W10
	.byte		N36   , An5 
	.byte	W08
	.byte		VOL   , 17*mus_rg_purin_mvl/mxv
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 13*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        9*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        7*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        5*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        4*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		MOD   , 1
	.byte	W01
	.byte		N48   , Gs5 
	.byte	W02
	.byte		VOL   , 22*mus_rg_purin_mvl/mxv
	.byte	W09
	.byte		MOD   , 7
	.byte	W09
	.byte		VOL   , 17*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        14*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_purin_mvl/mxv
	.byte		MOD   , 19
	.byte	W03
	.byte		VOL   , 6*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        4*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		MOD   , 1
	.byte	W01
	.byte		N24   , Fs5 
	.byte	W02
	.byte		VOL   , 22*mus_rg_purin_mvl/mxv
	.byte	W09
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 11*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		MOD   , 1
	.byte	W01
	.byte		N24   , Gs5 
	.byte	W02
	.byte		VOL   , 22*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 11*mus_rg_purin_mvl/mxv
	.byte	W09
	.byte		        6*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		MOD   , 2
	.byte	W01
	.byte		N60   , En5 
	.byte	W01
	.byte		MOD   , 1
	.byte	W01
	.byte		VOL   , 22*mus_rg_purin_mvl/mxv
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 17*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        13*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        9*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        5*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        2*mus_rg_purin_mvl/mxv
	.byte	W18
	.byte		MOD   , 0
	.byte	W24
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_purin_2:
	.byte	KEYSH , mus_rg_purin_key+0
	.byte		VOICE , 21
	.byte		LFOS  , 50
	.byte		BENDR , 12
	.byte		VOL   , 68*mus_rg_purin_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N48   , En4 , v127
	.byte	W12
	.byte		MOD   , 4
	.byte	W06
	.byte		VOL   , 45*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        29*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        18*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        15*mus_rg_purin_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 9*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        7*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		MOD   , 2
	.byte		VOL   , 68*mus_rg_purin_mvl/mxv
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 45*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        16*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        6*mus_rg_purin_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 4*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		MOD   , 2
	.byte		VOL   , 68*mus_rg_purin_mvl/mxv
	.byte		N48   , Fs4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W06
	.byte		VOL   , 45*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        17*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte		MOD   , 8
	.byte	W06
	.byte		        2
	.byte		VOL   , 68*mus_rg_purin_mvl/mxv
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N36   , An4 
	.byte	W06
	.byte		VOL   , 45*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		MOD   , 4
	.byte		VOL   , 34*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte		MOD   , 8
	.byte	W06
	.byte		        2
	.byte		VOL   , 68*mus_rg_purin_mvl/mxv
	.byte		N48   , Gs4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W06
	.byte		VOL   , 45*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        26*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        18*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        16*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte		MOD   , 8
	.byte	W06
	.byte		        2
	.byte		VOL   , 68*mus_rg_purin_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W09
	.byte		VOL   , 45*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        33*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		MOD   , 4
	.byte		VOL   , 22*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		MOD   , 2
	.byte		VOL   , 68*mus_rg_purin_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W06
	.byte		VOL   , 45*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_purin_mvl/mxv
	.byte		MOD   , 4
	.byte	W03
	.byte		VOL   , 11*mus_rg_purin_mvl/mxv
	.byte	W09
	.byte		MOD   , 2
	.byte		VOL   , 68*mus_rg_purin_mvl/mxv
	.byte		N68   , En4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W06
	.byte		VOL   , 45*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        27*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        24*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        23*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		MOD   , 10
	.byte		VOL   , 21*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        19*mus_rg_purin_mvl/mxv
	.byte	W06
	.byte		        17*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        14*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        8*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        6*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        5*mus_rg_purin_mvl/mxv
	.byte	W03
	.byte		        2*mus_rg_purin_mvl/mxv
	.byte	W15
	.byte		MOD   , 0
	.byte	W09
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_purin_3:
	.byte	KEYSH , mus_rg_purin_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 62
	.byte		BENDR , 12
	.byte		VOL   , 45*mus_rg_purin_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		BEND  , c_v+1
	.byte	W06
	.byte		N48   , En4 , v032
	.byte	W18
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N48   , Fs4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N36   , An4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N48   , Gs4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N24   , Gs4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N60   , En4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W36
	.byte		VOL   , 34*mus_rg_purin_mvl/mxv
	.byte	W12
	.byte		        22*mus_rg_purin_mvl/mxv
	.byte	W18
	.byte		MOD   , 0
	.byte	W18
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_purin_4:
	.byte	KEYSH , mus_rg_purin_key+0
	.byte		VOICE , 81
	.byte		VOL   , 45*mus_rg_purin_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		LFOS  , 62
	.byte		BENDR , 12
	.byte		BEND  , c_v+2
	.byte	W12
	.byte		N52   , En4 , v024
	.byte	W12
	.byte		MOD   , 3
	.byte	W36
	.byte	W03
	.byte		        0
	.byte	W01
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N36   , Gs4 
	.byte	W14
	.byte		MOD   , 4
	.byte	W06
	.byte	W15
	.byte		        0
	.byte	W01
	.byte		N48   , Fs4 
	.byte	W14
	.byte		MOD   , 4
	.byte	W32
	.byte	W02
	.byte		N12   , Gs4 
	.byte	W02
	.byte		MOD   , 0
	.byte	W10
	.byte		N36   , An4 
	.byte	W11
	.byte		MOD   , 4
	.byte	W09
	.byte	W16
	.byte		N48   , Gs4 
	.byte	W02
	.byte		MOD   , 0
	.byte	W12
	.byte		        4
	.byte	W32
	.byte	W02
	.byte		N24   , Fs4 
	.byte	W02
	.byte		MOD   , 0
	.byte	W22
	.byte		N24   , Gs4 
	.byte	W08
	.byte	W16
	.byte		N48   , En4 
	.byte	W08
	.byte		MOD   , 4
	.byte	W24
	.byte		VOL   , 34*mus_rg_purin_mvl/mxv
	.byte	W12
	.byte		        23*mus_rg_purin_mvl/mxv
	.byte	W36
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_purin:
	.byte	4	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_purin_pri	@ Priority
	.byte	mus_rg_purin_rev	@ Reverb.

	.word	mus_rg_purin_grp

	.word	mus_rg_purin_1
	.word	mus_rg_purin_2
	.word	mus_rg_purin_3
	.word	mus_rg_purin_4

	.end
