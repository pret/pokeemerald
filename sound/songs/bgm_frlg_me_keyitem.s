	.include "MPlayDef.s"

	.equ	bgm_frlg_me_keyitem_grp, voicegroup_86B07B0
	.equ	bgm_frlg_me_keyitem_pri, 5
	.equ	bgm_frlg_me_keyitem_rev, reverb_set+50
	.equ	bgm_frlg_me_keyitem_mvl, 127
	.equ	bgm_frlg_me_keyitem_key, 0
	.equ	bgm_frlg_me_keyitem_tbs, 1
	.equ	bgm_frlg_me_keyitem_exg, 0
	.equ	bgm_frlg_me_keyitem_cmp, 1

	.section .rodata
	.global	bgm_frlg_me_keyitem
	.align	2

@********************** Track  1 **********************@

bgm_frlg_me_keyitem_1:
	.byte	KEYSH , bgm_frlg_me_keyitem_key+0
	.byte	TEMPO , 44*bgm_frlg_me_keyitem_tbs/2
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 51*bgm_frlg_me_keyitem_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W06
	.byte	TEMPO , 72*bgm_frlg_me_keyitem_tbs/2
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
	.byte		VOL   , 46*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        43*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        37*bgm_frlg_me_keyitem_mvl/mxv
	.byte		MOD   , 3
	.byte	W02
	.byte		VOL   , 34*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        30*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        24*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        19*bgm_frlg_me_keyitem_mvl/mxv
	.byte		MOD   , 0
	.byte	W01
	.byte		VOL   , 12*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W02
	.byte		        8*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        4*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        0*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W04
	.byte	W06
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_me_keyitem_2:
	.byte	KEYSH , bgm_frlg_me_keyitem_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 76*bgm_frlg_me_keyitem_mvl/mxv
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
	.byte		VOL   , 64*bgm_frlg_me_keyitem_mvl/mxv
	.byte		N16   , Ds5 
	.byte	W02
	.byte		VOL   , 55*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        53*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        48*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        44*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        40*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W02
	.byte		        33*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        30*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        24*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        22*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        16*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W02
	.byte		        15*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        11*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        8*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        0*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W03
	.byte	W06
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_me_keyitem_3:
	.byte	KEYSH , bgm_frlg_me_keyitem_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 77*bgm_frlg_me_keyitem_mvl/mxv
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
	.byte		VOL   , 69*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        60*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        51*bgm_frlg_me_keyitem_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N13   , Ds2 , v100
	.byte	W02
	.byte		VOL   , 46*bgm_frlg_me_keyitem_mvl/mxv
	.byte		MOD   , 5
	.byte	W01
	.byte		VOL   , 38*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        33*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        31*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        28*bgm_frlg_me_keyitem_mvl/mxv
	.byte		MOD   , 4
	.byte	W02
	.byte		VOL   , 24*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        22*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        18*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        12*bgm_frlg_me_keyitem_mvl/mxv
	.byte		MOD   , 2
	.byte	W01
	.byte		VOL   , 8*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W02
	.byte		        0*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W04
	.byte	W06
	.byte		        0
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_me_keyitem_4:
	.byte	KEYSH , bgm_frlg_me_keyitem_key+0
	.byte		VOICE , 13
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 62*bgm_frlg_me_keyitem_mvl/mxv
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

bgm_frlg_me_keyitem_5:
	.byte	KEYSH , bgm_frlg_me_keyitem_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 70*bgm_frlg_me_keyitem_mvl/mxv
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
	.byte		VOL   , 57*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        44*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W02
	.byte		        36*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        25*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        12*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        4*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        1*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_me_keyitem_6:
	.byte	KEYSH , bgm_frlg_me_keyitem_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v-48
	.byte		VOL   , 56*bgm_frlg_me_keyitem_mvl/mxv
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
	.byte		VOL   , 44*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        35*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        28*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W01
	.byte		        8*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W02
	.byte		        0*bgm_frlg_me_keyitem_mvl/mxv
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_me_keyitem:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_me_keyitem_pri	@ Priority
	.byte	bgm_frlg_me_keyitem_rev	@ Reverb.

	.word	bgm_frlg_me_keyitem_grp

	.word	bgm_frlg_me_keyitem_1
	.word	bgm_frlg_me_keyitem_2
	.word	bgm_frlg_me_keyitem_3
	.word	bgm_frlg_me_keyitem_4
	.word	bgm_frlg_me_keyitem_5
	.word	bgm_frlg_me_keyitem_6

	.end
