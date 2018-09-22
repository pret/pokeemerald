	.include "MPlayDef.s"

	.equ	mus_rg_fan5_grp, voicegroup178
	.equ	mus_rg_fan5_pri, 5
	.equ	mus_rg_fan5_rev, reverb_set+50
	.equ	mus_rg_fan5_mvl, 127
	.equ	mus_rg_fan5_key, 0
	.equ	mus_rg_fan5_tbs, 1
	.equ	mus_rg_fan5_exg, 0
	.equ	mus_rg_fan5_cmp, 1

	.section .rodata
	.global	mus_rg_fan5
	.align	2

@********************** Track  1 **********************@

mus_rg_fan5_1:
	.byte	KEYSH , mus_rg_fan5_key+0
	.byte	TEMPO , 44*mus_rg_fan5_tbs/2
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 51*mus_rg_fan5_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W06
	.byte	TEMPO , 72*mus_rg_fan5_tbs/2
	.byte		        c_v-64
	.byte		N10   , As3 , v080
	.byte	W06
	.byte	W03
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N03   , Cn4 
	.byte	W02
	.byte	W03
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		PAN   , c_v-64
	.byte	W01
	.byte		N10   , Ds4 
	.byte	W04
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Fn4 
	.byte	W05
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		MOD   , 7
	.byte		N01   
	.byte	W02
	.byte		PAN   , c_v-64
	.byte	W01
	.byte		N16   , As4 
	.byte	W02
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 46*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        43*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        37*mus_rg_fan5_mvl/mxv
	.byte		MOD   , 3
	.byte	W02
	.byte		VOL   , 34*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        30*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        24*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        19*mus_rg_fan5_mvl/mxv
	.byte		MOD   , 0
	.byte	W01
	.byte		VOL   , 12*mus_rg_fan5_mvl/mxv
	.byte	W02
	.byte		        8*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        4*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        0*mus_rg_fan5_mvl/mxv
	.byte	W04
	.byte	W06
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_fan5_2:
	.byte	KEYSH , mus_rg_fan5_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 76*mus_rg_fan5_mvl/mxv
	.byte	W06
	.byte		N03   , Gn4 , v072
	.byte	W05
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W03
	.byte		N10   , Ds4 
	.byte	W02
	.byte	W06
	.byte	W02
	.byte		N03   , Gs4 
	.byte	W04
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W03
	.byte		N03   , As4 
	.byte	W05
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W03
	.byte		VOL   , 64*mus_rg_fan5_mvl/mxv
	.byte		N16   , Ds5 
	.byte	W02
	.byte		VOL   , 55*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        53*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        48*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        44*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        40*mus_rg_fan5_mvl/mxv
	.byte	W02
	.byte		        33*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        30*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        24*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        22*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        16*mus_rg_fan5_mvl/mxv
	.byte	W02
	.byte		        15*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        11*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        8*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        0*mus_rg_fan5_mvl/mxv
	.byte	W03
	.byte	W06
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_fan5_3:
	.byte	KEYSH , mus_rg_fan5_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 77*mus_rg_fan5_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W06
	.byte		N10   , Ds2 , v088
	.byte	W06
	.byte	W04
	.byte		        Gs2 
	.byte	W02
	.byte	W06
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		N10   , Gn2 
	.byte	W04
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte	W01
	.byte		MOD   , 7
	.byte	W01
	.byte		VOL   , 69*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        60*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        51*mus_rg_fan5_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N13   , Ds2 , v100
	.byte	W02
	.byte		VOL   , 46*mus_rg_fan5_mvl/mxv
	.byte		MOD   , 5
	.byte	W01
	.byte		VOL   , 38*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        33*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        31*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        28*mus_rg_fan5_mvl/mxv
	.byte		MOD   , 4
	.byte	W02
	.byte		VOL   , 24*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        22*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        18*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        12*mus_rg_fan5_mvl/mxv
	.byte		MOD   , 2
	.byte	W01
	.byte		VOL   , 8*mus_rg_fan5_mvl/mxv
	.byte	W02
	.byte		        0*mus_rg_fan5_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W04
	.byte	W06
	.byte		        0
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_fan5_4:
	.byte	KEYSH , mus_rg_fan5_key+0
	.byte		VOICE , 13
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 62*mus_rg_fan5_mvl/mxv
	.byte	W06
	.byte		N03   , Gn3 , v127
	.byte	W03
	.byte		PAN   , c_v+32
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W03
	.byte		N10   , Ds3 
	.byte	W02
	.byte	W01
	.byte		PAN   , c_v-32
	.byte	W05
	.byte	W02
	.byte		N03   , Gs3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W03
	.byte		N03   , As3 
	.byte	W03
	.byte		PAN   , c_v+32
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W03
	.byte		N13   , Ds4 
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_fan5_5:
	.byte	KEYSH , mus_rg_fan5_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 70*mus_rg_fan5_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , Gn4 , v127
	.byte	W05
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		PAN   , c_v+24
	.byte	W01
	.byte		N10   , Ds4 
	.byte	W02
	.byte		MOD   , 4
	.byte	W06
	.byte	W02
	.byte		        0
	.byte		PAN   , c_v-32
	.byte		N03   , Gs4 
	.byte	W04
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W03
	.byte		PAN   , c_v+22
	.byte		N03   , As4 
	.byte	W05
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		PAN   , c_v+32
	.byte	W01
	.byte		N13   
	.byte	W02
	.byte	W03
	.byte		VOL   , 57*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        44*mus_rg_fan5_mvl/mxv
	.byte	W02
	.byte		        36*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        25*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        12*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        4*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        1*mus_rg_fan5_mvl/mxv
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_fan5_6:
	.byte	KEYSH , mus_rg_fan5_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v-48
	.byte		VOL   , 56*mus_rg_fan5_mvl/mxv
	.byte	W06
	.byte		N03   , Fs2 , v096
	.byte	W03
	.byte		PAN   , c_v+48
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W03
	.byte		N10   , Bn4 , v052
	.byte	W02
	.byte	W01
	.byte		PAN   , c_v-48
	.byte	W05
	.byte	W02
	.byte		N03   , Fs2 , v092
	.byte	W04
	.byte		PAN   , c_v+50
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v-48
	.byte	W02
	.byte		N01   , Fs2 , v096
	.byte	W01
	.byte	W01
	.byte		N01   
	.byte	W03
	.byte		N14   , Bn4 , v056
	.byte	W02
	.byte	W06
	.byte	W01
	.byte		VOL   , 44*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        35*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        28*mus_rg_fan5_mvl/mxv
	.byte	W01
	.byte		        8*mus_rg_fan5_mvl/mxv
	.byte	W02
	.byte		        0*mus_rg_fan5_mvl/mxv
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_fan5:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_fan5_pri	@ Priority
	.byte	mus_rg_fan5_rev	@ Reverb.

	.word	mus_rg_fan5_grp

	.word	mus_rg_fan5_1
	.word	mus_rg_fan5_2
	.word	mus_rg_fan5_3
	.word	mus_rg_fan5_4
	.word	mus_rg_fan5_5
	.word	mus_rg_fan5_6

	.end
