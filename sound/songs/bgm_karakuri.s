	.include "MPlayDef.s"

	.equ	bgm_karakuri_grp, voicegroup_869227C
	.equ	bgm_karakuri_pri, 0
	.equ	bgm_karakuri_rev, reverb_set+50
	.equ	bgm_karakuri_mvl, 127
	.equ	bgm_karakuri_key, 0
	.equ	bgm_karakuri_tbs, 1
	.equ	bgm_karakuri_exg, 0
	.equ	bgm_karakuri_cmp, 1

	.section .rodata
	.global	bgm_karakuri
	.align	2

@********************** Track  1 **********************@

bgm_karakuri_1:
	.byte	KEYSH , bgm_karakuri_key+0
	.byte	TEMPO , 136*bgm_karakuri_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 40*bgm_karakuri_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
bgm_karakuri_1_B1:
bgm_karakuri_1_000:
	.byte		N03   , Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte		        Gn5 , v076
	.byte	W06
	.byte		        Gn5 , v056
	.byte	W06
	.byte		        Gn5 , v072
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte		        Gn5 , v076
	.byte	W06
	.byte		        Gn5 , v056
	.byte	W06
	.byte		        Gn5 , v072
	.byte	W06
	.byte		        Gn5 , v052
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	PATT
	 .word	bgm_karakuri_1_000
	.byte	GOTO
	 .word	bgm_karakuri_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_karakuri_2:
	.byte	KEYSH , bgm_karakuri_key+0
	.byte		VOICE , 13
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*bgm_karakuri_mvl/mxv
	.byte		N03   , As4 , v112
	.byte	W03
	.byte		        Fs4 , v064
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Bn4 , v112
	.byte	W03
	.byte		        Gs4 , v064
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Cn5 , v112
	.byte	W03
	.byte		        An4 , v064
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cs5 , v112
	.byte	W03
	.byte		        As4 , v064
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        As4 
	.byte	W03
bgm_karakuri_2_B1:
	.byte		VOICE , 13
	.byte		VOL   , 45*bgm_karakuri_mvl/mxv
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
bgm_karakuri_2_000:
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte	PEND
	.byte		        Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		VOICE , 24
	.byte		VOL   , 30*bgm_karakuri_mvl/mxv
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Cs6 
	.byte	W12
	.byte		VOICE , 47
	.byte		VOL   , 45*bgm_karakuri_mvl/mxv
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cs2 , v096
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W12
bgm_karakuri_2_001:
	.byte		VOICE , 13
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte	PEND
bgm_karakuri_2_002:
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte	PEND
	.byte		        Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		VOICE , 17
	.byte		VOL   , 42*bgm_karakuri_mvl/mxv
	.byte		N03   , As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		N24   , Fs5 
	.byte	W24
	.byte		N03   , Cs5 , v080
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		VOICE , 56
	.byte		VOL   , 45*bgm_karakuri_mvl/mxv
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Fs5 
	.byte	W06
	.byte		VOICE , 13
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte	PATT
	 .word	bgm_karakuri_2_000
	.byte		N06   , Cs5 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        As5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		VOICE , 60
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N06   , Gs5 
	.byte	W06
	.byte		N03   , Gn5 , v092
	.byte	W03
	.byte		        Fs5 , v084
	.byte	W03
	.byte		        En5 , v072
	.byte	W03
	.byte		        Dn5 , v064
	.byte	W09
	.byte	PATT
	 .word	bgm_karakuri_2_001
	.byte	PATT
	 .word	bgm_karakuri_2_002
	.byte		N06   , Cs5 , v112
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		VOICE , 17
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		VOICE , 21
	.byte		VOL   , 36*bgm_karakuri_mvl/mxv
	.byte		N32   , Fs4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N32   , Fs4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N32   , Ds4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N32   , Fs4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        As4 
	.byte	W06
	.byte		N24   , Cs5 
	.byte	W30
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W18
	.byte		N18   , As4 
	.byte	W18
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N06   , Bn4 
	.byte	W18
	.byte		        Gs4 
	.byte	W18
	.byte		        Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	GOTO
	 .word	bgm_karakuri_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_karakuri_3:
	.byte	KEYSH , bgm_karakuri_key+0
	.byte		VOICE , 21
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 38*bgm_karakuri_mvl/mxv
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		        Fs3 , v064
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Cn4 , v112
	.byte	W03
	.byte		        An3 , v064
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        As3 , v064
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        As3 
	.byte	W03
bgm_karakuri_3_B1:
	.byte	W48
	.byte		VOICE , 56
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte	W48
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte	W96
	.byte	W48
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs3 
	.byte	W12
	.byte	W54
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte	W48
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		VOICE , 17
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		N24   , Cs5 
	.byte	W24
	.byte		N03   , As4 , v080
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Cs4 , v112
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		VOICE , 56
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W06
	.byte		VOICE , 14
	.byte		VOL   , 30*bgm_karakuri_mvl/mxv
	.byte		PAN   , c_v-52
	.byte		N48   , As3 
	.byte	W48
	.byte		PAN   , c_v+47
	.byte		N48   , Fs3 
	.byte	W48
	.byte		PAN   , c_v-49
	.byte		N48   , As3 
	.byte	W48
	.byte		PAN   , c_v+50
	.byte		N48   , Fs3 
	.byte	W48
	.byte		PAN   , c_v-49
	.byte		N48   , As3 
	.byte	W48
	.byte		PAN   , c_v+47
	.byte		N48   , Cs4 
	.byte	W48
	.byte		VOICE , 56
	.byte		N03   , Cs5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , En5 , v092
	.byte	W03
	.byte		        Ds5 , v084
	.byte	W03
	.byte		        Cs5 , v072
	.byte	W03
	.byte		        Bn4 , v064
	.byte	W09
	.byte		VOICE , 73
	.byte		VOL   , 25*bgm_karakuri_mvl/mxv
	.byte		PAN   , c_v-43
	.byte		N06   , Cs5 , v112
	.byte	W06
	.byte		        Ds5 
	.byte	W03
	.byte		PAN   , c_v-28
	.byte	W03
	.byte		N06   , Cs5 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		PAN   , c_v+13
	.byte		N06   , Cs5 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W03
	.byte		PAN   , c_v+40
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		VOL   , 28*bgm_karakuri_mvl/mxv
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		VOL   , 40*bgm_karakuri_mvl/mxv
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		VOL   , 35*bgm_karakuri_mvl/mxv
	.byte		PAN   , c_v+47
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W03
	.byte		PAN   , c_v+32
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		VOL   , 26*bgm_karakuri_mvl/mxv
	.byte		PAN   , c_v+10
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W03
	.byte		VOL   , 31*bgm_karakuri_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-34
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v-49
	.byte		VOL   , 39*bgm_karakuri_mvl/mxv
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		VOICE , 47
	.byte		PAN   , c_v+47
	.byte		VOL   , 56*bgm_karakuri_mvl/mxv
	.byte		N06   , Cs3 
	.byte	W12
	.byte		PAN   , c_v-43
	.byte		N06   , Cs2 
	.byte	W12
	.byte		PAN   , c_v+47
	.byte		N06   , Bn2 
	.byte	W12
	.byte		PAN   , c_v-43
	.byte		N06   , Cs2 
	.byte	W12
	.byte		PAN   , c_v+47
	.byte		N06   , As2 
	.byte	W12
	.byte		PAN   , c_v-43
	.byte		N06   , Cs2 
	.byte	W12
	.byte		PAN   , c_v+47
	.byte		N06   , Gs2 
	.byte	W12
	.byte		PAN   , c_v-43
	.byte		N06   , Cs2 
	.byte	W12
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 30*bgm_karakuri_mvl/mxv
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		VOICE , 13
	.byte		PAN   , c_v-48
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W03
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W03
	.byte		PAN   , c_v-48
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		N06   , As3 
	.byte	W03
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W03
	.byte		PAN   , c_v-48
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Fs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N03   , Ds5 
	.byte	W03
	.byte		N06   , Fs4 
	.byte	W03
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W03
	.byte		PAN   , c_v-48
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W09
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N06   , As4 
	.byte	W03
	.byte		PAN   , c_v-48
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_karakuri_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_karakuri_4:
	.byte	KEYSH , bgm_karakuri_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-62
	.byte		VOL   , 32*bgm_karakuri_mvl/mxv
	.byte		N24   , As3 , v112
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
bgm_karakuri_4_B1:
	.byte		PAN   , c_v-63
	.byte		VOL   , 33*bgm_karakuri_mvl/mxv
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v092
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
bgm_karakuri_4_000:
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v092
	.byte	W06
	.byte		        As2 , v112
	.byte	W03
	.byte		N06   , As2 , v080
	.byte	W09
	.byte	PEND
	.byte	PATT
	 .word	bgm_karakuri_4_000
	.byte		N06   , Gs3 , v112
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N06   , Gs5 
	.byte	W15
	.byte		        Cs2 
	.byte	W03
	.byte		        Cs3 
	.byte	W09
	.byte		        Cs2 
	.byte	W09
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W12
	.byte	W48
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	PATT
	 .word	bgm_karakuri_4_000
	.byte	PATT
	 .word	bgm_karakuri_4_000
	.byte	PATT
	 .word	bgm_karakuri_4_000
	.byte	W96
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , En4 , v092
	.byte	W03
	.byte		        Ds4 , v084
	.byte	W03
	.byte		        Cs4 , v072
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W09
	.byte	PATT
	 .word	bgm_karakuri_4_000
	.byte	PATT
	 .word	bgm_karakuri_4_000
	.byte	PATT
	 .word	bgm_karakuri_4_000
	.byte	W96
	.byte		PAN   , c_v+0
	.byte		VOL   , 32*bgm_karakuri_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N32   , Ds5 , v112
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N32   , Cs5 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		N32   , Bn4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N32   , Ds5 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W06
	.byte		N24   , As5 
	.byte	W30
	.byte		N06   , Bn5 
	.byte	W06
	.byte		        As5 
	.byte	W18
	.byte		N18   , Gn5 
	.byte	W18
	.byte		N24   , Ds5 
	.byte	W24
	.byte		N06   , Fs5 
	.byte	W18
	.byte		        Ds5 
	.byte	W18
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	GOTO
	 .word	bgm_karakuri_4_B1
	.byte		BEND  , c_v+0
	.byte	FINE

@********************** Track  5 **********************@

bgm_karakuri_5:
	.byte	KEYSH , bgm_karakuri_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 34*bgm_karakuri_mvl/mxv
	.byte		N24   , Cs3 , v112
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
bgm_karakuri_5_B1:
	.byte		PAN   , c_v+63
	.byte		VOL   , 36*bgm_karakuri_mvl/mxv
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v092
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
bgm_karakuri_5_000:
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v092
	.byte	W06
	.byte		N06   , Fs3 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_karakuri_5_000
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Cs6 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cs3 
	.byte	W12
	.byte	W96
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte	PATT
	 .word	bgm_karakuri_5_000
	.byte	PATT
	 .word	bgm_karakuri_5_000
	.byte	PATT
	 .word	bgm_karakuri_5_000
	.byte	W96
	.byte		N03   , Fn4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Gn4 , v092
	.byte	W03
	.byte		        Fs4 , v084
	.byte	W03
	.byte		        En4 , v072
	.byte	W03
	.byte		        Dn4 , v064
	.byte	W09
	.byte	PATT
	 .word	bgm_karakuri_5_000
	.byte	PATT
	 .word	bgm_karakuri_5_000
	.byte	PATT
	 .word	bgm_karakuri_5_000
	.byte	W96
	.byte		PAN   , c_v+0
	.byte		VOL   , 36*bgm_karakuri_mvl/mxv
	.byte		N32   , Ds5 , v112
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N32   , Cs5 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		N32   , Bn4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N32   , Ds5 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W18
	.byte		N24   , As5 
	.byte	W30
	.byte		N06   , Bn5 
	.byte	W06
	.byte		        As5 
	.byte	W18
	.byte		N18   , Gn5 
	.byte	W18
	.byte		N24   , Ds5 
	.byte	W24
	.byte		N06   , Fs5 
	.byte	W18
	.byte		        Ds5 
	.byte	W18
	.byte		        Fs5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	GOTO
	 .word	bgm_karakuri_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_karakuri_6:
	.byte	KEYSH , bgm_karakuri_key+0
	.byte		VOICE , 0
	.byte		VOL   , 70*bgm_karakuri_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
bgm_karakuri_6_B1:
bgm_karakuri_6_000:
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v096
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        En3 , v092
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte	PATT
	 .word	bgm_karakuri_6_000
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        Cn1 , v100
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        En3 , v092
	.byte	W06
	.byte	GOTO
	 .word	bgm_karakuri_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_karakuri_7:
	.byte	KEYSH , bgm_karakuri_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 59*bgm_karakuri_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Cs2 , v112
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Cs1 
	.byte	W06
	.byte		BEND  , c_v+9
	.byte	W06
	.byte		        c_v+0
	.byte	W12
bgm_karakuri_7_B1:
bgm_karakuri_7_000:
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_karakuri_7_000
	.byte	PATT
	 .word	bgm_karakuri_7_000
bgm_karakuri_7_001:
	.byte		N03   , Cs1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_karakuri_7_001
	.byte	PATT
	 .word	bgm_karakuri_7_001
	.byte		N03   , Cs1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte	PATT
	 .word	bgm_karakuri_7_000
	.byte	PATT
	 .word	bgm_karakuri_7_000
	.byte	PATT
	 .word	bgm_karakuri_7_000
	.byte	PATT
	 .word	bgm_karakuri_7_001
	.byte	PATT
	 .word	bgm_karakuri_7_001
	.byte	PATT
	 .word	bgm_karakuri_7_001
	.byte		N03   , Cs1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
bgm_karakuri_7_002:
	.byte		N03   , Bn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte	PEND
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N03   , As1 
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte	PATT
	 .word	bgm_karakuri_7_002
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N06   , As1 
	.byte	W12
	.byte		        Cs2 
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Bn1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   , Ds2 
	.byte	W12
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        Fs1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	GOTO
	 .word	bgm_karakuri_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_karakuri_8:
	.byte	KEYSH , bgm_karakuri_key+0
	.byte		VOICE , 13
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 39*bgm_karakuri_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W96
bgm_karakuri_8_B1:
	.byte		VOICE , 56
	.byte		PAN   , c_v+16
	.byte	W48
	.byte		        c_v-43
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+47
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte	W48
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v-45
	.byte		N06   , As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		VOICE , 9
	.byte		PAN   , c_v-16
	.byte		N06   , As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte	W96
	.byte		VOICE , 13
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		PAN   , c_v-38
	.byte		N06   , Cs6 , v080
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte	W96
	.byte		VOL   , 32*bgm_karakuri_mvl/mxv
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 37*bgm_karakuri_mvl/mxv
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Gn4 , v092
	.byte	W03
	.byte		        Fs4 , v084
	.byte	W03
	.byte		        En4 , v072
	.byte	W03
	.byte		        Dn4 , v064
	.byte	W09
	.byte		VOICE , 13
	.byte		VOL   , 34*bgm_karakuri_mvl/mxv
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 48
	.byte		N06   , As4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		VOICE , 47
	.byte		PAN   , c_v+35
	.byte		VOL   , 56*bgm_karakuri_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-33
	.byte		N12   , Cs3 
	.byte	W12
	.byte		PAN   , c_v+34
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cs3 
	.byte	W12
	.byte		PAN   , c_v+34
	.byte		N06   , Fs3 
	.byte	W12
	.byte		PAN   , c_v-33
	.byte		N06   , Fs2 
	.byte	W06
	.byte		PAN   , c_v+40
	.byte		N06   , Fs3 
	.byte	W06
	.byte		VOICE , 13
	.byte		VOL   , 40*bgm_karakuri_mvl/mxv
	.byte	W12
	.byte		N06   , Ds6 , v092
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Bn5 
	.byte	W12
	.byte		        Ds6 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Bn5 
	.byte	W12
	.byte		        Cs6 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Bn5 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Bn5 
	.byte	W18
	.byte		        Cn6 
	.byte	W18
	.byte		        Cs6 
	.byte	W12
	.byte	W12
	.byte		        Ds6 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		        Fs6 
	.byte	W06
	.byte		        Ds6 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		        Cs6 
	.byte	W24
	.byte		        Bn5 
	.byte	W12
	.byte		        As5 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		        Gn5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W12
	.byte		        Gs5 
	.byte	W06
	.byte		        Cs6 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Bn5 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		        As5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        As5 
	.byte	W12
	.byte		        Fs5 
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        As5 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_karakuri_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_karakuri:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_karakuri_pri	@ Priority
	.byte	bgm_karakuri_rev	@ Reverb.

	.word	bgm_karakuri_grp

	.word	bgm_karakuri_1
	.word	bgm_karakuri_2
	.word	bgm_karakuri_3
	.word	bgm_karakuri_4
	.word	bgm_karakuri_5
	.word	bgm_karakuri_6
	.word	bgm_karakuri_7
	.word	bgm_karakuri_8

	.end
