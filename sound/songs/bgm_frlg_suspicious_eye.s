	.include "MPlayDef.s"

	.equ	bgm_frlg_suspicious_eye_grp, voicegroup_86A4804
	.equ	bgm_frlg_suspicious_eye_pri, 0
	.equ	bgm_frlg_suspicious_eye_rev, reverb_set+50
	.equ	bgm_frlg_suspicious_eye_mvl, 127
	.equ	bgm_frlg_suspicious_eye_key, 0
	.equ	bgm_frlg_suspicious_eye_tbs, 1
	.equ	bgm_frlg_suspicious_eye_exg, 0
	.equ	bgm_frlg_suspicious_eye_cmp, 1

	.section .rodata
	.global	bgm_frlg_suspicious_eye
	.align	2

@********************** Track  1 **********************@

bgm_frlg_suspicious_eye_1:
	.byte	KEYSH , bgm_frlg_suspicious_eye_key+0
	.byte	TEMPO , 146*bgm_frlg_suspicious_eye_tbs/2
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		VOL   , 47*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W24
	.byte		N12   , Gs2 , v088
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		VOL   , 23*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N24   , Gs2 
	.byte	W03
	.byte		VOL   , 28*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte		VOL   , 36*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        56*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		MOD   , 0
	.byte		VOL   , 47*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N06   , En2 
	.byte	W24
	.byte		N06   
	.byte	W24
bgm_frlg_suspicious_eye_1_B1:
bgm_frlg_suspicious_eye_1_000:
	.byte		N06   , En2 , v088
	.byte	W24
	.byte		VOL   , 23*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N24   
	.byte	W03
	.byte		VOL   , 28*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		MOD   , 8
	.byte		VOL   , 36*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        41*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        56*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 47*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_suspicious_eye_1_000
	.byte	PATT
	 .word	bgm_frlg_suspicious_eye_1_000
	.byte	PATT
	 .word	bgm_frlg_suspicious_eye_1_000
	.byte	GOTO
	 .word	bgm_frlg_suspicious_eye_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_suspicious_eye_2:
	.byte	KEYSH , bgm_frlg_suspicious_eye_key+0
	.byte		VOICE , 38
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 95*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Cs3 , v120
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N48   , Cs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 84*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W12
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte		VOL   , 96*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
bgm_frlg_suspicious_eye_2_B1:
	.byte		N03   , Cs3 , v120
	.byte	W24
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N24   
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 52*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        84*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		MOD   , 12
	.byte	W03
	.byte		VOL   , 96*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N24   , Cn3 
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 52*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        84*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        96*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte		N12   , An2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W24
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N24   
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 52*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        84*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        96*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N24   , Cn3 
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 52*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        84*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        96*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		MOD   , 12
	.byte	W06
	.byte		        0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_suspicious_eye_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_suspicious_eye_3:
	.byte	KEYSH , bgm_frlg_suspicious_eye_key+0
	.byte		VOICE , 17
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+24
	.byte		VOL   , 47*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W24
	.byte	W24
	.byte		N12   , Cs5 , v124
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N24   , Cs5 
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 30*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        21*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        12*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Gs4 , v127
	.byte	W24
bgm_frlg_suspicious_eye_3_B1:
	.byte		N06   , Gs4 , v127
	.byte	W24
	.byte		VOL   , 23*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N24   , Cn5 , v120
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 30*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        36*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        40*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 42*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N06   , Gs4 , v127
	.byte	W03
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W21
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		VOL   , 23*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N24   , Cn5 
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 30*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        36*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        40*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N06   , Gs4 , v120
	.byte	W24
	.byte		        Gs4 , v127
	.byte	W24
bgm_frlg_suspicious_eye_3_000:
	.byte		N06   , Gs4 , v127
	.byte	W24
	.byte		VOL   , 23*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N24   , Cn5 
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 30*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        36*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        40*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N06   , Gs4 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_frlg_suspicious_eye_3_000
	.byte	GOTO
	 .word	bgm_frlg_suspicious_eye_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_suspicious_eye_4:
	.byte	KEYSH , bgm_frlg_suspicious_eye_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Cs2 , v120
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N36   , Cs1 
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
bgm_frlg_suspicious_eye_4_B1:
	.byte		N06   , Cs1 , v120
	.byte	W24
	.byte		N24   , Cs2 
	.byte	W12
	.byte		VOL   , 60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N06   , Gs1 
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte		N06   , Cs1 
	.byte	W24
	.byte		N24   , Cn2 
	.byte	W12
	.byte		VOL   , 60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N06   , Cs1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W24
	.byte		N24   , Cs2 
	.byte	W12
	.byte		VOL   , 60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N06   , Cs1 
	.byte	W24
	.byte		N24   , Cn2 
	.byte	W12
	.byte		VOL   , 60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N06   , Cs1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	GOTO
	 .word	bgm_frlg_suspicious_eye_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_suspicious_eye_5:
	.byte	KEYSH , bgm_frlg_suspicious_eye_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 95*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Cs3 , v084
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N48   , Cs3 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		VOL   , 84*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W12
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W12
	.byte		        96*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
bgm_frlg_suspicious_eye_5_B1:
bgm_frlg_suspicious_eye_5_000:
	.byte		N03   , Cs4 , v084
	.byte	W24
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		N24   
	.byte	W06
	.byte		VOL   , 52*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		MOD   , 10
	.byte	W03
	.byte		VOL   , 60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        84*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        96*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte		N06   
	.byte	W24
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        52*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		MOD   , 10
	.byte	W03
	.byte		VOL   , 60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        84*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        96*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_suspicious_eye_5_000
	.byte		N06   , Cs4 , v084
	.byte	W24
	.byte		VOL   , 48*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		        52*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		MOD   , 10
	.byte	W03
	.byte		VOL   , 60*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        72*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        84*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W03
	.byte		        96*bgm_frlg_suspicious_eye_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_suspicious_eye_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_suspicious_eye_6:
	.byte	KEYSH , bgm_frlg_suspicious_eye_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 36*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N48   , Cs3 
	.byte	W12
	.byte		MOD   , 9
	.byte	W36
	.byte		        0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
bgm_frlg_suspicious_eye_6_B1:
bgm_frlg_suspicious_eye_6_000:
	.byte		N03   , Cs3 , v127
	.byte	W24
	.byte		N24   
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte		N06   
	.byte	W24
	.byte		N24   , Cn3 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , An2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_suspicious_eye_6_000
	.byte		N06   , Cs3 , v127
	.byte	W24
	.byte		N24   , Cn3 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_suspicious_eye_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_suspicious_eye_7:
	.byte	KEYSH , bgm_frlg_suspicious_eye_key+0
	.byte		VOICE , 0
	.byte		VOL   , 61*bgm_frlg_suspicious_eye_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N48   , Fn2 , v064
	.byte	W48
	.byte		N06   , En3 , v104
	.byte	W12
	.byte		        Dn3 , v084
	.byte	W12
	.byte		        En3 , v104
	.byte	W12
	.byte		        Gs2 , v080
	.byte	W12
bgm_frlg_suspicious_eye_7_B1:
	.byte		N12   , Cn1 , v096
	.byte	W12
	.byte		        Fs2 , v120
	.byte	W12
	.byte		N24   , Fn2 , v048
	.byte	W24
	.byte		N12   , En1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   , Fn2 , v048
	.byte	W24
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		N12   , Fs2 , v096
	.byte	W12
	.byte		N06   , En3 , v120
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gs2 , v080
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W12
	.byte		        En3 , v112
	.byte	W12
	.byte		        Gs2 , v080
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Fn2 , v048
	.byte	W24
	.byte		N06   , Dn3 , v120
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 , v096
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn2 , v120
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_suspicious_eye_7_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_suspicious_eye:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_suspicious_eye_pri	@ Priority
	.byte	bgm_frlg_suspicious_eye_rev	@ Reverb.

	.word	bgm_frlg_suspicious_eye_grp

	.word	bgm_frlg_suspicious_eye_1
	.word	bgm_frlg_suspicious_eye_2
	.word	bgm_frlg_suspicious_eye_3
	.word	bgm_frlg_suspicious_eye_4
	.word	bgm_frlg_suspicious_eye_5
	.word	bgm_frlg_suspicious_eye_6
	.word	bgm_frlg_suspicious_eye_7

	.end
