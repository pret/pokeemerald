	.include "MPlayDef.s"

	.equ	mus_aqa_0_grp, voicegroup065
	.equ	mus_aqa_0_pri, 0
	.equ	mus_aqa_0_rev, reverb_set+50
	.equ	mus_aqa_0_mvl, 127
	.equ	mus_aqa_0_key, 0
	.equ	mus_aqa_0_tbs, 1
	.equ	mus_aqa_0_exg, 0
	.equ	mus_aqa_0_cmp, 1

	.section .rodata
	.global	mus_aqa_0
	.align	2

@********************** Track  1 **********************@

mus_aqa_0_1:
	.byte	KEYSH , mus_aqa_0_key+0
	.byte	TEMPO , 140*mus_aqa_0_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		PAN   , c_v+63
	.byte		VOL   , 46*mus_aqa_0_mvl/mxv
	.byte	W12
mus_aqa_0_1_000:
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_aqa_0_1_000
mus_aqa_0_1_B1:
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	PATT
	 .word	mus_aqa_0_1_000
	.byte	GOTO
	 .word	mus_aqa_0_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_aqa_0_2:
	.byte	KEYSH , mus_aqa_0_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		PAN   , c_v+63
	.byte		VOL   , 43*mus_aqa_0_mvl/mxv
	.byte	W12
mus_aqa_0_2_000:
	.byte	W12
	.byte		N12   , Gn4 , v100
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte		VOL   , 10*mus_aqa_0_mvl/mxv
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOL   , 21*mus_aqa_0_mvl/mxv
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOL   , 32*mus_aqa_0_mvl/mxv
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOL   , 43*mus_aqa_0_mvl/mxv
	.byte	W12
	.byte		N12   
	.byte	W12
mus_aqa_0_2_B1:
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	PATT
	 .word	mus_aqa_0_2_000
	.byte	GOTO
	 .word	mus_aqa_0_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_aqa_0_3:
	.byte	KEYSH , mus_aqa_0_key+0
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 86*mus_aqa_0_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W09
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , An1 , v124
	.byte	W06
	.byte		BEND  , c_v+3
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Fn0 , v112
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gs0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        En0 
	.byte	W06
	.byte		        Fn0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
mus_aqa_0_3_B1:
	.byte		PAN   , c_v+4
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
mus_aqa_0_3_000:
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		N03   , As0 , v096
	.byte	W06
	.byte	PEND
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Fs0 
	.byte	W06
	.byte		        Gn0 , v096
	.byte	W06
	.byte		        As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        Fn0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , As0 
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , Gs1 , v112
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds0 
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Cs1 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs0 
	.byte	W06
	.byte		        Gn0 
	.byte	W06
	.byte		        Ds0 
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Cs1 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gs0 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        Cs0 
	.byte	W06
	.byte		        Dn0 
	.byte	W06
	.byte		        Gn0 
	.byte	W06
	.byte		        Gs0 
	.byte	W06
	.byte	PATT
	 .word	mus_aqa_0_3_000
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W18
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , As0 , v112
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		N03   , As0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W18
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Cs1 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gn0 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        Ds0 
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N03   , Ds0 , v096
	.byte	W06
	.byte		N06   , Ds0 , v112
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte	GOTO
	 .word	mus_aqa_0_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_aqa_0_4:
	.byte	KEYSH , mus_aqa_0_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		VOL   , 65*mus_aqa_0_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte	W96
	.byte	W96
mus_aqa_0_4_B1:
	.byte		VOICE , 1
	.byte		PAN   , c_v-33
	.byte		VOL   , 35*mus_aqa_0_mvl/mxv
	.byte		N03   , As4 , v112
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
mus_aqa_0_4_000:
	.byte		N03   , As4 , v112
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte	PEND
mus_aqa_0_4_001:
	.byte		N03   , As4 , v112
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_aqa_0_4_001
	.byte	PATT
	 .word	mus_aqa_0_4_000
	.byte	PATT
	 .word	mus_aqa_0_4_000
	.byte		VOICE , 56
	.byte		VOL   , 57*mus_aqa_0_mvl/mxv
	.byte		N03   , Fn4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		VOL   , 62*mus_aqa_0_mvl/mxv
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		VOL   , 63*mus_aqa_0_mvl/mxv
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte		VOL   , 75*mus_aqa_0_mvl/mxv
	.byte		N03   , An4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 58*mus_aqa_0_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , En5 , v068
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Fn4 , v112
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		VOICE , 1
	.byte		PAN   , c_v+12
	.byte		VOL   , 54*mus_aqa_0_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W06
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		VOICE , 1
	.byte		N30   , Gn4 
	.byte	W66
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte	W03
	.byte		N03   , As4 
	.byte	W09
	.byte		N06   , Cs5 
	.byte	W09
	.byte		N03   , As4 
	.byte	W09
	.byte		N06   , Cs5 
	.byte	W09
	.byte		N03   , As4 
	.byte	W09
	.byte		N06   , Cs5 
	.byte	W09
	.byte		N03   , As4 
	.byte	W09
	.byte		N06   , Cs5 
	.byte	W09
	.byte		N03   , As4 
	.byte	W09
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn4 
	.byte	W30
	.byte		N03   
	.byte	W03
	.byte		        As4 , v080
	.byte	W03
	.byte		        Cs5 , v088
	.byte	W03
	.byte		        Ds5 , v100
	.byte	W03
	.byte		        As4 , v112
	.byte	W03
	.byte		        Cs5 , v076
	.byte	W03
	.byte		        Ds5 , v088
	.byte	W03
	.byte		        Fn5 , v096
	.byte	W03
	.byte		N06   , Ds5 , v112
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte	W03
	.byte		N03   , Gn4 
	.byte	W09
	.byte		N06   , Gs4 
	.byte	W09
	.byte		N03   , Gn4 
	.byte	W09
	.byte		N06   , Gs4 
	.byte	W09
	.byte		N03   , Gn4 
	.byte	W09
	.byte		N06   , Gs4 
	.byte	W09
	.byte		N03   , Gn4 
	.byte	W09
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N48   , Gn4 
	.byte	W96
	.byte	GOTO
	 .word	mus_aqa_0_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_aqa_0_5:
	.byte	KEYSH , mus_aqa_0_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		PAN   , c_v-20
	.byte		VOL   , 60*mus_aqa_0_mvl/mxv
	.byte		N03   , Cn3 , v112
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		VOICE , 56
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N48   , Fn3 
	.byte	W48
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
mus_aqa_0_5_B1:
	.byte		VOICE , 1
	.byte		PAN   , c_v-38
	.byte		VOL   , 27*mus_aqa_0_mvl/mxv
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
mus_aqa_0_5_000:
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte	PEND
	.byte		N03   , As3 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds2 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Dn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte	PATT
	 .word	mus_aqa_0_5_000
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte	PATT
	 .word	mus_aqa_0_5_000
	.byte		VOICE , 56
	.byte		VOL   , 46*mus_aqa_0_mvl/mxv
	.byte		N03   , Cs3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As2 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		VOL   , 54*mus_aqa_0_mvl/mxv
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		VOL   , 60*mus_aqa_0_mvl/mxv
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		VOL   , 67*mus_aqa_0_mvl/mxv
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		VOL   , 43*mus_aqa_0_mvl/mxv
	.byte		PAN   , c_v-19
	.byte		N06   
	.byte	W06
	.byte		N03   , En3 , v064
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        An2 , v112
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 1
	.byte		VOL   , 39*mus_aqa_0_mvl/mxv
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N30   , As3 
	.byte	W66
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        An4 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte		        As4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W30
	.byte	W48
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs4 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N48   , Ds4 
	.byte	W96
	.byte	GOTO
	 .word	mus_aqa_0_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_aqa_0_6:
	.byte	KEYSH , mus_aqa_0_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 71*mus_aqa_0_mvl/mxv
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W24
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N48   , Fn4 
	.byte	W48
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
mus_aqa_0_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_aqa_0_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_aqa_0_7:
	.byte	KEYSH , mus_aqa_0_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+0
	.byte		VOL   , 33*mus_aqa_0_mvl/mxv
	.byte		BENDR , 12
	.byte	W12
	.byte	W06
	.byte		N06   , Fn5 , v112
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , An4 
	.byte	W06
mus_aqa_0_7_B1:
	.byte		VOICE , 85
	.byte		PAN   , c_v+63
	.byte		VOL   , 39*mus_aqa_0_mvl/mxv
	.byte		N06   , Fn4 , v112
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
mus_aqa_0_7_000:
	.byte		N78   , As3 , v112
	.byte	W24
	.byte		MOD   , 2
	.byte	W48
	.byte		        0
	.byte	W18
	.byte		N06   , Gn3 
	.byte	W06
	.byte	PEND
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*mus_aqa_0_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , Ds3 
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		VOICE , 85
	.byte		VOL   , 39*mus_aqa_0_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte	PATT
	 .word	mus_aqa_0_7_000
	.byte		PAN   , c_v-62
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v072
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Cn3 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 80
	.byte		PAN   , c_v-62
	.byte		VOL   , 39*mus_aqa_0_mvl/mxv
	.byte		N03   , As3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
mus_aqa_0_7_001:
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte	PEND
mus_aqa_0_7_002:
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds2 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Dn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_aqa_0_7_001
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte	PATT
	 .word	mus_aqa_0_7_001
	.byte	PATT
	 .word	mus_aqa_0_7_002
	.byte	PATT
	 .word	mus_aqa_0_7_001
	.byte	GOTO
	 .word	mus_aqa_0_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_aqa_0_8:
	.byte	KEYSH , mus_aqa_0_key+0
	.byte		VOICE , 86
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+0
	.byte		VOL   , 41*mus_aqa_0_mvl/mxv
	.byte		BENDR , 12
	.byte	W12
	.byte	W06
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , As2 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , Gs2 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , Gn2 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As2 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
mus_aqa_0_8_B1:
	.byte		VOICE , 86
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*mus_aqa_0_mvl/mxv
	.byte		N03   , As4 , v112
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		N72   , Gn4 
	.byte	W06
	.byte		VOL   , 43*mus_aqa_0_mvl/mxv
	.byte	W02
	.byte		        34*mus_aqa_0_mvl/mxv
	.byte	W04
	.byte		        29*mus_aqa_0_mvl/mxv
	.byte	W02
	.byte		        27*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        23*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        18*mus_aqa_0_mvl/mxv
	.byte	W04
	.byte		MOD   , 2
	.byte	W15
	.byte		VOL   , 29*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        29*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        32*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        35*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        38*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        43*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        50*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        56*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        59*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        63*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        71*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        50*mus_aqa_0_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N06   , Gn4 , v080
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn4 , v064
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N06   , Gn4 , v048
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*mus_aqa_0_mvl/mxv
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W12
	.byte		N06   , As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N78   , Ds5 
	.byte	W06
	.byte		VOL   , 43*mus_aqa_0_mvl/mxv
	.byte	W02
	.byte		        34*mus_aqa_0_mvl/mxv
	.byte	W04
	.byte		        29*mus_aqa_0_mvl/mxv
	.byte	W02
	.byte		        27*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        23*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        18*mus_aqa_0_mvl/mxv
	.byte	W04
	.byte		MOD   , 2
	.byte	W15
	.byte		VOL   , 29*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        29*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        32*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        35*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        38*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        43*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        50*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        56*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        59*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        63*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        71*mus_aqa_0_mvl/mxv
	.byte	W03
	.byte		        48*mus_aqa_0_mvl/mxv
	.byte		MOD   , 0
	.byte	W18
	.byte		N06   , Cs5 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , Bn4 , v072
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        An4 , v064
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        An4 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		VOICE , 81
	.byte		PAN   , c_v+63
	.byte		VOL   , 40*mus_aqa_0_mvl/mxv
	.byte		N03   , As4 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
mus_aqa_0_8_000:
	.byte		N03   , As4 , v112
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte	PEND
mus_aqa_0_8_001:
	.byte		N03   , As4 , v112
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_aqa_0_8_001
	.byte	PATT
	 .word	mus_aqa_0_8_000
	.byte	PATT
	 .word	mus_aqa_0_8_000
	.byte	PATT
	 .word	mus_aqa_0_8_001
	.byte	PATT
	 .word	mus_aqa_0_8_001
	.byte	GOTO
	 .word	mus_aqa_0_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_aqa_0_9:
	.byte	KEYSH , mus_aqa_0_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 67*mus_aqa_0_mvl/mxv
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v088
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W24
	.byte		N06   
	.byte	W18
	.byte		        Cn1 , v088
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 , v048
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 , v076
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Cn1 , v108
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn1 , v096
	.byte	W06
	.byte		N03   , Dn1 , v100
	.byte	W03
	.byte		        Dn1 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v120
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
mus_aqa_0_9_B1:
mus_aqa_0_9_000:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v088
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W24
	.byte		N06   
	.byte	W18
	.byte		        Cn1 , v088
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		        Cn1 , v088
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W24
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v088
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 , v088
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	PATT
	 .word	mus_aqa_0_9_000
	.byte	GOTO
	 .word	mus_aqa_0_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_aqa_0_10:
	.byte	KEYSH , mus_aqa_0_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+0
	.byte		VOL   , 31*mus_aqa_0_mvl/mxv
	.byte		BENDR , 12
	.byte		BEND  , c_v+1
	.byte	W12
	.byte	W96
	.byte	W96
mus_aqa_0_10_B1:
	.byte	W96
	.byte		VOICE , 83
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		N72   , Gn4 
	.byte	W24
	.byte		MOD   , 2
	.byte	W48
	.byte		        0
	.byte		N06   , Gs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 , v080
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn4 , v056
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		VOICE , 84
	.byte		N06   , As4 , v112
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W12
	.byte		N06   , As4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N78   , Ds5 
	.byte	W24
	.byte		MOD   , 2
	.byte	W48
	.byte		        0
	.byte	W18
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N03   , Bn4 , v072
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        An4 , v064
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        An4 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		VOICE , 87
	.byte		VOL   , 27*mus_aqa_0_mvl/mxv
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W06
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N30   , Gn3 
	.byte	W66
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte	W03
	.byte		N03   , As3 
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W09
	.byte		N03   , As3 
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W09
	.byte		N03   , As3 
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W09
	.byte		N03   , As3 
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W09
	.byte		N03   , As3 
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn3 
	.byte	W30
	.byte		N03   
	.byte	W03
	.byte		        As3 , v080
	.byte	W03
	.byte		        Cs4 , v088
	.byte	W03
	.byte		        Ds4 , v100
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        Cs4 , v076
	.byte	W03
	.byte		        Ds4 , v088
	.byte	W03
	.byte		        Fn4 , v096
	.byte	W03
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte	W03
	.byte		N03   , Gn3 
	.byte	W09
	.byte		N06   , Gs3 
	.byte	W09
	.byte		N03   , Gn3 
	.byte	W09
	.byte		N06   , Gs3 
	.byte	W09
	.byte		N03   , Gn3 
	.byte	W09
	.byte		N06   , Gs3 
	.byte	W09
	.byte		N03   , Gn3 
	.byte	W09
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N03   , Fs3 , v064
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Bn2 
	.byte	W48
	.byte	W03
	.byte	GOTO
	 .word	mus_aqa_0_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_aqa_0:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_aqa_0_pri	@ Priority
	.byte	mus_aqa_0_rev	@ Reverb.

	.word	mus_aqa_0_grp

	.word	mus_aqa_0_1
	.word	mus_aqa_0_2
	.word	mus_aqa_0_3
	.word	mus_aqa_0_4
	.word	mus_aqa_0_5
	.word	mus_aqa_0_6
	.word	mus_aqa_0_7
	.word	mus_aqa_0_8
	.word	mus_aqa_0_9
	.word	mus_aqa_0_10

	.end
