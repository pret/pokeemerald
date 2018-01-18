	.include "MPlayDef.s"

	.equ	mus_b_palace_grp, voicegroup_8697070
	.equ	mus_b_palace_pri, 0
	.equ	mus_b_palace_rev, reverb_set+50
	.equ	mus_b_palace_mvl, 127
	.equ	mus_b_palace_key, 0
	.equ	mus_b_palace_tbs, 1
	.equ	mus_b_palace_exg, 0
	.equ	mus_b_palace_cmp, 1

	.section .rodata
	.global	mus_b_palace
	.align	2

@********************** Track  1 **********************@

mus_b_palace_1:
	.byte	KEYSH , mus_b_palace_key+0
	.byte	TEMPO , 96*mus_b_palace_tbs/2
	.byte		VOICE , 24
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W06
	.byte	W96
	.byte	W96
mus_b_palace_1_000:
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N24   , Gn1 , v088
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-40
	.byte		N24   , Gn1 , v028
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+47
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N24   , Gn1 , v016
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-42
	.byte		N24   , Gn1 , v012
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v088
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v084
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-40
	.byte		N12   , Gn1 , v052
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v048
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+47
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v032
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-41
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte	W48
	.byte	W96
	.byte	W96
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N24   , Gn1 , v088
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-40
	.byte		N24   , Gn1 , v028
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+47
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N24   , Gn1 , v016
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Gn1 , v084
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v088
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v064
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-40
	.byte		N12   , Gn1 , v028
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v020
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+47
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-41
	.byte		N12   , Gn1 , v016
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_b_palace_1_000
	.byte		PAN   , c_v+0
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v088
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v064
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-40
	.byte		N12   , Gn1 , v028
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v020
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+47
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v016
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-41
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W48
	.byte	W96
	.byte	W96
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N24   , Fn1 , v088
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-40
	.byte		N24   , Fn1 , v028
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+47
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-42
	.byte	W12
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        79*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v088
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v064
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-40
	.byte		N12   , Gn1 , v028
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v020
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+47
	.byte		VOL   , 105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v016
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v012
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		PAN   , c_v-41
	.byte		N12   , Gn1 , v008
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
	.byte		        105*mus_b_palace_mvl/mxv
	.byte		N12   , Gn1 , v004
	.byte	W06
	.byte		VOL   , 92*mus_b_palace_mvl/mxv
	.byte	W06
mus_b_palace_1_B1:
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
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_b_palace_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_b_palace_2:
	.byte	KEYSH , mus_b_palace_key+0
	.byte		VOICE , 10
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+3
	.byte		VOL   , 57*mus_b_palace_mvl/mxv
	.byte	W06
mus_b_palace_2_000:
	.byte		PAN   , c_v+4
	.byte	W12
	.byte		        c_v-48
	.byte		N06   , Cn4 , v048
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W12
	.byte	PEND
mus_b_palace_2_001:
	.byte		PAN   , c_v+4
	.byte		N06   , Cn4 , v048
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Gs3 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v+3
	.byte	W24
	.byte		N22   , Cn3 , v092
	.byte	W24
	.byte		N23   , Gn3 
	.byte	W24
	.byte		PAN   , c_v-39
	.byte		N21   , Gn3 , v028
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N21   
	.byte	W24
	.byte		PAN   , c_v+2
	.byte		N24   , Cn3 , v092
	.byte	W24
	.byte		N10   , Gn3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		N24   , Cn4 , v048
	.byte	W11
	.byte	W13
	.byte		PAN   , c_v+45
	.byte		N22   , Cn4 , v036
	.byte	W23
	.byte		PAN   , c_v-32
	.byte		N10   , Cn4 , v032
	.byte	W12
mus_b_palace_2_002:
	.byte		PAN   , c_v+4
	.byte	W12
	.byte		        c_v-48
	.byte		N06   , Cn4 , v048
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W12
	.byte	PEND
mus_b_palace_2_003:
	.byte		PAN   , c_v+4
	.byte		N06   , Fn4 , v048
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		PAN   , c_v-26
	.byte		N06   , Cs4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Gs3 , v036
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte	PEND
	.byte		PAN   , c_v+3
	.byte	W24
	.byte		N22   , Cn3 , v092
	.byte	W24
	.byte		N10   , Gn3 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N24   , Gn2 , v088
	.byte	W24
	.byte		N12   , Gn2 , v092
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		        Cn3 , v092
	.byte	W12
	.byte		N10   
	.byte	W36
	.byte		PAN   , c_v-26
	.byte	W24
	.byte		        c_v+3
	.byte		N06   , Cn3 , v104
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W12
	.byte		N03   , Cn3 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+4
	.byte	W12
	.byte		        c_v-48
	.byte		N06   , Gn4 , v048
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		PAN   , c_v+4
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		PAN   , c_v+2
	.byte	W24
	.byte		N22   , Cn3 , v092
	.byte	W24
	.byte		N23   , Gn3 
	.byte	W24
	.byte		PAN   , c_v-42
	.byte		N21   , Gn3 , v044
	.byte	W24
	.byte		PAN   , c_v+4
	.byte		N12   , Gn2 , v088
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		N22   , Cn3 , v088
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N23   , Cn4 
	.byte	W21
	.byte		PAN   , c_v-40
	.byte	W03
	.byte		N23   , Cn4 , v040
	.byte	W12
	.byte		PAN   , c_v+42
	.byte	W12
	.byte		N22   , Cn4 , v032
	.byte	W15
	.byte		PAN   , c_v-40
	.byte	W09
	.byte		N10   , Cn4 , v028
	.byte	W12
	.byte		PAN   , c_v+4
	.byte	W12
	.byte		        c_v-48
	.byte		N12   , Cn4 , v048
	.byte	W18
	.byte		N06   , Cs4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N12   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+4
	.byte		N12   , Gs3 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   , Gn3 
	.byte	W18
	.byte		N06   , Gs3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N12   , Fn3 
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+2
	.byte	W24
	.byte		N21   , Cn3 , v092
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		PAN   , c_v-39
	.byte		N21   , Cn4 , v032
	.byte	W24
	.byte		PAN   , c_v+44
	.byte		N21   , Cn4 , v024
	.byte	W24
	.byte		PAN   , c_v-39
	.byte		N21   
	.byte	W24
	.byte		PAN   , c_v+44
	.byte		N15   , Cn4 , v016
	.byte	W18
	.byte		PAN   , c_v+2
	.byte	W06
mus_b_palace_2_B1:
	.byte	PATT
	 .word	mus_b_palace_2_000
	.byte	PATT
	 .word	mus_b_palace_2_001
	.byte		PAN   , c_v+2
	.byte	W24
	.byte		N21   , Cn3 , v092
	.byte	W24
	.byte		N23   , Gn3 
	.byte	W24
	.byte		        Gn3 , v028
	.byte	W24
	.byte		N21   
	.byte	W24
	.byte		N24   , Cn3 , v092
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W24
	.byte		        Cn4 , v036
	.byte	W12
	.byte	W12
	.byte		        Cn4 , v024
	.byte	W24
	.byte		N56   
	.byte	W60
	.byte	PATT
	 .word	mus_b_palace_2_002
	.byte	PATT
	 .word	mus_b_palace_2_003
	.byte		PAN   , c_v+3
	.byte	W24
	.byte		N20   , Cn3 , v092
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Gn2 , v064
	.byte	W24
	.byte		N12   , Gn2 , v092
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W12
	.byte		        Cn3 , v092
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N22   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-26
	.byte	W12
	.byte		N08   , Cn4 , v040
	.byte	W12
	.byte	W48
	.byte		PAN   , c_v+4
	.byte	W12
	.byte		        c_v-48
	.byte		N06   , Gn4 , v048
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		PAN   , c_v+4
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		PAN   , c_v+3
	.byte		N06   , Cn4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Cs4 
	.byte	W12
	.byte		PAN   , c_v+1
	.byte	W24
	.byte		N24   , Cn3 , v092
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		PAN   , c_v-42
	.byte		N24   , Gn3 , v044
	.byte	W24
	.byte		PAN   , c_v+4
	.byte	W24
	.byte		N22   , Cn3 , v092
	.byte	W24
	.byte		N08   , Gn3 
	.byte	W12
	.byte		N22   , Cn4 
	.byte	W21
	.byte		PAN   , c_v-40
	.byte	W03
	.byte		N22   , Cn4 , v040
	.byte	W12
	.byte		PAN   , c_v+42
	.byte	W12
	.byte		N22   , Cn4 , v032
	.byte	W15
	.byte		PAN   , c_v-40
	.byte	W09
	.byte		N08   , Cn4 , v028
	.byte	W12
	.byte		PAN   , c_v+4
	.byte	W12
	.byte		        c_v-48
	.byte		N06   , Cn4 , v048
	.byte	W18
	.byte		        Cs4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N06   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+4
	.byte		N06   , Gs3 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Gn3 
	.byte	W18
	.byte		        Gs3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , Fn3 
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+3
	.byte	W24
	.byte		N24   , Cn3 , v092
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		PAN   , c_v-39
	.byte		N24   , Cn4 , v032
	.byte	W24
	.byte		PAN   , c_v+44
	.byte		N24   , Cn4 , v024
	.byte	W24
	.byte		PAN   , c_v-39
	.byte		N24   
	.byte	W24
	.byte		PAN   , c_v+44
	.byte		N18   , Cn4 , v016
	.byte	W18
	.byte		PAN   , c_v+2
	.byte	W06
	.byte	GOTO
	 .word	mus_b_palace_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_b_palace_3:
	.byte	KEYSH , mus_b_palace_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 39*mus_b_palace_mvl/mxv
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , Cn1 , v064
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W10
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W08
	.byte	W16
	.byte		        Cn1 , v032
	.byte	W24
	.byte		        Cn1 , v016
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Cn1 , v012
	.byte	W08
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	W96
	.byte	W96
	.byte		VOICE , 81
	.byte		VOL   , 52*mus_b_palace_mvl/mxv
	.byte	W96
	.byte		N03   , Cn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N02   , Cn1 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N02   , Cn1 
	.byte	W06
	.byte		N02   
	.byte	W06
mus_b_palace_3_B1:
	.byte		N03   , Fn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N02   , Fn1 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N15   , Cn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
mus_b_palace_3_000:
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte	PEND
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   , En1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N02   , Cn1 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		N02   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte	PATT
	 .word	mus_b_palace_3_000
	.byte		N06   , Cn1 , v108
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N03   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   , En1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , En1 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte	PATT
	 .word	mus_b_palace_3_000
	.byte		N12   , Cn1 , v112
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   , En1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn1 
	.byte	W12
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte	GOTO
	 .word	mus_b_palace_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_b_palace_4:
	.byte	KEYSH , mus_b_palace_key+0
	.byte		VOICE , 10
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+16
	.byte		VOL   , 65*mus_b_palace_mvl/mxv
	.byte		N03   , Fn3 , v080
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		N06   , Cn4 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
mus_b_palace_4_000:
	.byte		N06   , Cs4 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , Gs3 , v048
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v+16
	.byte		N24   , Gn2 , v088
	.byte	W24
	.byte	W03
	.byte		N21   , Fn3 , v092
	.byte	W24
	.byte		N23   , Cn4 
	.byte	W21
	.byte		PAN   , c_v-32
	.byte	W03
	.byte		N21   , Cn4 , v024
	.byte	W21
	.byte		PAN   , c_v+54
	.byte	W03
	.byte		N21   
	.byte	W21
	.byte		PAN   , c_v+16
	.byte	W03
	.byte		N24   , Fn3 , v092
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W23
	.byte		PAN   , c_v-32
	.byte	W01
	.byte		N24   , Gn4 , v048
	.byte	W09
	.byte	W14
	.byte		PAN   , c_v+48
	.byte	W01
	.byte		N24   , Gn4 , v036
	.byte	W23
	.byte		PAN   , c_v-48
	.byte	W01
	.byte		N08   , Gn4 , v032
	.byte	W09
mus_b_palace_4_001:
	.byte		PAN   , c_v+16
	.byte		N06   , Cn4 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte	PEND
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , Gs3 , v036
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N24   , Gn2 , v084
	.byte	W24
	.byte	W03
	.byte		        Fn3 , v092
	.byte	W24
	.byte		N08   , Cn4 
	.byte	W12
	.byte		N23   , Gn4 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N23   , Gn4 , v048
	.byte	W09
	.byte	W15
	.byte		PAN   , c_v+48
	.byte		N08   , Gn4 , v032
	.byte	W09
	.byte		PAN   , c_v+16
	.byte	W03
	.byte		N12   , Fn3 , v092
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N23   , Gn4 
	.byte	W09
	.byte		PAN   , c_v-34
	.byte	W15
	.byte		        c_v-32
	.byte		N24   , Gn4 , v056
	.byte	W09
	.byte	W15
	.byte		PAN   , c_v+48
	.byte		N24   , Gn4 , v040
	.byte	W24
	.byte		PAN   , c_v-46
	.byte		N08   
	.byte	W09
	.byte		PAN   , c_v+16
	.byte		N06   , Gn4 , v112
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Gn2 , v088
	.byte	W24
	.byte	W03
	.byte		N22   , Fn3 , v092
	.byte	W24
	.byte		        Cn4 
	.byte	W21
	.byte		PAN   , c_v-29
	.byte	W03
	.byte		N21   , Cn4 , v044
	.byte	W21
	.byte		PAN   , c_v+16
	.byte	W24
	.byte	W03
	.byte		N22   , Fn3 , v088
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W12
	.byte		N23   , Gn4 
	.byte	W18
	.byte		PAN   , c_v-33
	.byte	W06
	.byte		N22   , Gn4 , v040
	.byte	W09
	.byte		PAN   , c_v+34
	.byte	W13
	.byte		N24   , Gn4 , v032
	.byte	W14
	.byte		PAN   , c_v-33
	.byte	W12
	.byte		N08   , Gn4 , v028
	.byte	W09
mus_b_palace_4_002:
	.byte		PAN   , c_v+16
	.byte		N06   , Cn4 , v112
	.byte	W18
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	PEND
mus_b_palace_4_003:
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W18
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte		N12   , Fn2 , v088
	.byte	W12
	.byte		        Fn2 , v064
	.byte	W15
	.byte		N21   , Fn3 , v092
	.byte	W24
	.byte		N23   , Cn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W21
	.byte		PAN   , c_v-33
	.byte	W03
	.byte		N23   , Gn4 , v032
	.byte	W21
	.byte		PAN   , c_v+44
	.byte	W03
	.byte		N23   , Gn4 , v024
	.byte	W21
	.byte		PAN   , c_v-45
	.byte	W03
	.byte		N23   
	.byte	W21
	.byte		PAN   , c_v+43
	.byte	W03
	.byte		N15   , Gn4 , v016
	.byte	W15
	.byte		PAN   , c_v+16
	.byte		N03   , Fn3 , v112
	.byte	W03
	.byte		        Gs3 
	.byte	W03
mus_b_palace_4_B1:
	.byte		PAN   , c_v+16
	.byte		N06   , Cn4 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PATT
	 .word	mus_b_palace_4_000
	.byte		PAN   , c_v+16
	.byte		N24   , Gn2 , v088
	.byte	W24
	.byte	W03
	.byte		N21   , Fn3 , v092
	.byte	W24
	.byte		N23   , Cn4 
	.byte	W21
	.byte		PAN   , c_v-32
	.byte	W03
	.byte		N23   , Cn4 , v024
	.byte	W21
	.byte		PAN   , c_v+54
	.byte	W03
	.byte		N21   
	.byte	W21
	.byte		PAN   , c_v+16
	.byte	W01
	.byte		N21   , Fn3 , v092
	.byte	W24
	.byte	W02
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W22
	.byte		PAN   , c_v-48
	.byte	W02
	.byte		N24   , Gn4 , v036
	.byte	W09
	.byte		PAN   , c_v+55
	.byte	W15
	.byte		N24   , Gn4 , v024
	.byte	W09
	.byte		PAN   , c_v-58
	.byte	W15
	.byte		N23   
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N32   
	.byte	W32
	.byte	W01
	.byte	PATT
	 .word	mus_b_palace_4_001
	.byte		N06   , Cs4 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , Gs3 , v036
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N10   , Cs4 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N24   , Gn2 , v084
	.byte	W24
	.byte	W03
	.byte		N20   , Fn3 , v092
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N44   , Gn4 
	.byte	W32
	.byte	W01
	.byte	W24
	.byte	W03
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N22   , Gn4 
	.byte	W09
	.byte		PAN   , c_v-34
	.byte	W15
	.byte		N08   , Gn4 , v040
	.byte	W09
	.byte		PAN   , c_v+16
	.byte		N06   , Cn3 , v096
	.byte	W06
	.byte		        Cs3 , v080
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W12
	.byte		N03   , Cn3 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W18
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Gn2 , v088
	.byte	W24
	.byte	W03
	.byte		        Fn3 , v092
	.byte	W21
	.byte	W03
	.byte		        Cn4 
	.byte	W21
	.byte		PAN   , c_v-29
	.byte	W03
	.byte		N20   , Cn4 , v044
	.byte	W21
	.byte		PAN   , c_v+16
	.byte		N12   , Gn2 , v088
	.byte	W12
	.byte		        Gn2 , v064
	.byte	W15
	.byte		N24   , Fn3 , v092
	.byte	W21
	.byte	W03
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N22   , Gn4 
	.byte	W18
	.byte		PAN   , c_v-33
	.byte	W06
	.byte		N22   , Gn4 , v040
	.byte	W09
	.byte		PAN   , c_v+34
	.byte	W15
	.byte		N22   , Gn4 , v032
	.byte	W12
	.byte		PAN   , c_v-33
	.byte	W12
	.byte		N08   , Gn4 , v028
	.byte	W09
	.byte	PATT
	 .word	mus_b_palace_4_002
	.byte	PATT
	 .word	mus_b_palace_4_003
	.byte		N12   , Fn2 , v088
	.byte	W12
	.byte		        Fn2 , v064
	.byte	W15
	.byte		N24   , Fn3 , v092
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W21
	.byte		PAN   , c_v-33
	.byte	W03
	.byte		N24   , Gn4 , v032
	.byte	W21
	.byte		PAN   , c_v+44
	.byte	W03
	.byte		N24   , Gn4 , v024
	.byte	W21
	.byte		PAN   , c_v-45
	.byte	W03
	.byte		N24   
	.byte	W21
	.byte		PAN   , c_v+43
	.byte	W03
	.byte		N15   , Gn4 , v016
	.byte	W15
	.byte		PAN   , c_v-16
	.byte		N03   , Fn3 , v112
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte	GOTO
	 .word	mus_b_palace_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_b_palace_5:
	.byte	KEYSH , mus_b_palace_key+0
	.byte		VOICE , 10
	.byte		PAN   , c_v-16
	.byte		VOL   , 65*mus_b_palace_mvl/mxv
	.byte		N03   , Cn3 , v080
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		N06   , Gn3 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W10
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W02
mus_b_palace_5_000:
	.byte	W10
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cs3 , v048
	.byte	W02
	.byte		PAN   , c_v-32
	.byte	W10
	.byte		N06   , Cn3 
	.byte	W14
	.byte	PEND
	.byte		PAN   , c_v-16
	.byte		N24   , Gn1 , v088
	.byte	W22
	.byte		N06   , Gn2 , v092
	.byte	W24
	.byte		N23   , Cn3 
	.byte	W24
	.byte		N21   , Cn3 , v032
	.byte	W24
	.byte	W02
	.byte		N12   , Gn1 , v088
	.byte	W12
	.byte		        Gn1 , v064
	.byte	W10
	.byte		N22   , Gn2 , v092
	.byte	W24
	.byte		N10   , Cn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Gn3 , v048
	.byte	W14
	.byte	W10
	.byte		        Gn3 , v036
	.byte	W24
	.byte		N12   , Gn3 , v032
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W02
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W10
	.byte		        Gn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W02
	.byte	W10
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn3 , v036
	.byte	W02
	.byte		PAN   , c_v-39
	.byte	W04
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W14
	.byte		PAN   , c_v-16
	.byte		N24   , Gn1 , v084
	.byte	W22
	.byte		        Gn2 , v092
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N13   , Gn3 
	.byte	W14
	.byte		N24   , Gn1 , v064
	.byte	W24
	.byte		N12   , Gn1 , v092
	.byte	W12
	.byte		        Gn1 , v064
	.byte	W10
	.byte		        Gn2 , v092
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N23   , Gn3 
	.byte	W24
	.byte		N09   , Gn3 , v040
	.byte	W14
	.byte		N06   , Cn2 , v104
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W10
	.byte		N03   , Cn2 , v112
	.byte	W06
	.byte		N06   
	.byte	W08
	.byte		        Cn4 
	.byte	W18
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W10
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W02
	.byte	W04
	.byte		        Gs2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W14
	.byte		N24   , Gn1 , v088
	.byte	W22
	.byte		        Gn2 , v092
	.byte	W24
	.byte		N23   , Cn3 
	.byte	W24
	.byte		N21   , Cn3 , v044
	.byte	W24
	.byte	W02
	.byte		N12   , Gn1 , v088
	.byte	W12
	.byte		        Gn1 , v064
	.byte	W10
	.byte		N22   , Gn2 , v088
	.byte	W24
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N23   , Gn3 
	.byte	W23
	.byte		PAN   , c_v-36
	.byte	W01
	.byte		N23   , Gn3 , v040
	.byte	W14
	.byte		PAN   , c_v+33
	.byte	W10
	.byte		N23   , Gn3 , v032
	.byte	W17
	.byte		PAN   , c_v-36
	.byte	W07
	.byte		N12   , Gn3 , v028
	.byte	W14
mus_b_palace_5_001:
	.byte		PAN   , c_v-16
	.byte		N06   , Gn3 , v112
	.byte	W18
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W10
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W02
	.byte	PEND
mus_b_palace_5_002:
	.byte	W04
	.byte		N06   , Gs3 , v112
	.byte	W06
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W18
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	W02
	.byte	PEND
	.byte		N12   , Fn1 , v088
	.byte	W12
	.byte		        Fn1 , v064
	.byte	W10
	.byte		N21   , Fn2 , v092
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Gn3 , v032
	.byte	W02
	.byte		PAN   , c_v-41
	.byte	W22
	.byte		N21   , Gn3 , v024
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W22
	.byte		N21   
	.byte	W02
	.byte		PAN   , c_v-47
	.byte	W22
	.byte		N15   , Gn3 , v016
	.byte	W02
	.byte		PAN   , c_v+41
	.byte	W18
	.byte		        c_v-16
	.byte		N03   , Cn3 , v112
	.byte	W03
	.byte		        Fn3 
	.byte	W03
mus_b_palace_5_B1:
	.byte		PAN   , c_v-16
	.byte		N06   , Gn3 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W10
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W02
	.byte	PATT
	 .word	mus_b_palace_5_000
	.byte		PAN   , c_v-16
	.byte		N22   , Gn1 , v088
	.byte	W22
	.byte		N21   , Gn2 , v092
	.byte	W24
	.byte		N23   , Cn3 
	.byte	W24
	.byte		N24   , Cn3 , v032
	.byte	W24
	.byte	W02
	.byte		N12   , Gn1 , v088
	.byte	W12
	.byte		N10   , Gn1 , v064
	.byte	W10
	.byte		N24   , Gn2 , v092
	.byte	W24
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		        Gn3 , v036
	.byte	W14
	.byte	W10
	.byte		        Gn3 , v024
	.byte	W24
	.byte		N56   
	.byte	W60
	.byte		N06   , Gn3 , v112
	.byte	W02
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W10
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W02
	.byte	W10
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn3 , v036
	.byte	W02
	.byte		PAN   , c_v-39
	.byte	W04
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N10   , Fn3 
	.byte	W14
	.byte		PAN   , c_v-16
	.byte		N24   , Gn1 , v084
	.byte	W22
	.byte		N22   , Gn2 , v092
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N08   , Gn3 
	.byte	W14
	.byte		N24   , Gn1 , v064
	.byte	W24
	.byte		N12   , Gn1 , v092
	.byte	W12
	.byte		        Gn1 , v064
	.byte	W10
	.byte		        Gn2 , v092
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N10   , Cn3 
	.byte	W12
	.byte		N22   , Gn3 
	.byte	W24
	.byte		N08   , Gn3 , v040
	.byte	W14
	.byte		N06   , Cn2 , v096
	.byte	W06
	.byte		        Cs2 , v080
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 , v084
	.byte	W10
	.byte		N03   , Cn2 , v112
	.byte	W06
	.byte		N06   
	.byte	W08
	.byte		        Cn4 
	.byte	W18
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W10
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W02
	.byte	W10
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W02
	.byte	W10
	.byte		        Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W14
	.byte		N24   , Gn1 , v088
	.byte	W22
	.byte		        Gn2 , v092
	.byte	W24
	.byte		        Cn3 
	.byte	W02
	.byte	W22
	.byte		        Cn3 , v044
	.byte	W24
	.byte	W02
	.byte		N12   , Gn1 , v088
	.byte	W12
	.byte		        Gn1 , v064
	.byte	W10
	.byte		N22   , Gn2 , v092
	.byte	W24
	.byte		N10   , Cn3 
	.byte	W02
	.byte	W10
	.byte		N22   , Gn3 
	.byte	W23
	.byte		PAN   , c_v-36
	.byte	W01
	.byte		N22   , Gn3 , v040
	.byte	W14
	.byte		PAN   , c_v+33
	.byte	W10
	.byte		N22   , Gn3 , v032
	.byte	W17
	.byte		PAN   , c_v-36
	.byte	W07
	.byte		N08   , Gn3 , v028
	.byte	W14
	.byte	PATT
	 .word	mus_b_palace_5_001
	.byte	PATT
	 .word	mus_b_palace_5_002
	.byte		N12   , Fn1 , v088
	.byte	W12
	.byte		        Fn1 , v064
	.byte	W10
	.byte		N24   , Fn2 , v092
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Gn3 , v032
	.byte	W02
	.byte		PAN   , c_v-41
	.byte	W22
	.byte		N24   , Gn3 , v024
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W22
	.byte		N24   
	.byte	W02
	.byte		PAN   , c_v-47
	.byte	W22
	.byte		N19   , Gn3 , v016
	.byte	W02
	.byte		PAN   , c_v+41
	.byte	W18
	.byte		        c_v+16
	.byte		N03   , Cn3 , v112
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte	GOTO
	 .word	mus_b_palace_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_b_palace_6:
	.byte	KEYSH , mus_b_palace_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*mus_b_palace_mvl/mxv
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		        39*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        38*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        36*mus_b_palace_mvl/mxv
	.byte	W03
	.byte		        35*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        34*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        33*mus_b_palace_mvl/mxv
	.byte	W03
	.byte		        32*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        31*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        30*mus_b_palace_mvl/mxv
	.byte	W03
	.byte		        29*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        28*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        28*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        27*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        26*mus_b_palace_mvl/mxv
	.byte	W04
	.byte		        25*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        24*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        23*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        23*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        22*mus_b_palace_mvl/mxv
	.byte	W04
	.byte		        21*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        20*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        19*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        19*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        18*mus_b_palace_mvl/mxv
	.byte	W04
	.byte		        16*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        15*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        14*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        14*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        13*mus_b_palace_mvl/mxv
	.byte	W03
	.byte		        12*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        11*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        10*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        9*mus_b_palace_mvl/mxv
	.byte	W04
	.byte		        7*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        6*mus_b_palace_mvl/mxv
	.byte	W05
	.byte		        5*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        4*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        3*mus_b_palace_mvl/mxv
	.byte	W04
	.byte		        2*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        1*mus_b_palace_mvl/mxv
	.byte	W01
	.byte		        0*mus_b_palace_mvl/mxv
	.byte	W02
	.byte		        39*mus_b_palace_mvl/mxv
	.byte	W96
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , Cn1 , v064
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W10
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W08
	.byte		PAN   , c_v-48
	.byte	W16
	.byte		N06   , Cn1 , v032
	.byte	W08
	.byte		PAN   , c_v+48
	.byte	W16
	.byte		N06   , Cn1 , v016
	.byte	W08
	.byte		PAN   , c_v-48
	.byte	W16
	.byte		N06   
	.byte	W08
	.byte		PAN   , c_v+48
	.byte	W16
	.byte		N06   , Cn1 , v012
	.byte	W08
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	W96
	.byte	W96
	.byte		VOL   , 52*mus_b_palace_mvl/mxv
	.byte	W96
	.byte		VOICE , 80
	.byte		VOL   , 39*mus_b_palace_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N03   , Cn1 , v112
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
mus_b_palace_6_B1:
	.byte		PAN   , c_v+0
	.byte		N03   , Fn1 , v112
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Fn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   , Fn1 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Fn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Fn1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cs1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N15   , Cn1 
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Cn1 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Cn1 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N06   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Cn1 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , En1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Gn1 
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , En1 
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N03   
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Fn1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N02   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , As1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   , En1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N03   , Cs1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N03   , En1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N02   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N02   
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W18
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Gn1 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N03   , Fn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Cn1 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Cn1 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Cn1 , v108
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   , Fn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Cs1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cn1 , v104
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N03   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Cn1 
	.byte	W18
	.byte		PAN   , c_v-62
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , En1 
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N03   
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W18
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Cn1 
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Gn1 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N03   , En1 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Cn1 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N03   , Gn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cn1 
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Cn1 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Cn1 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v+1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N12   , Cn1 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v-62
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , En1 
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Fn1 
	.byte	W18
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   
	.byte	W18
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Fn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Fn2 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Fn1 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Fn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fn1 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte		N03   , Fn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Fn1 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Fn2 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Fn1 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Fn2 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Fn1 
	.byte	W12
	.byte	GOTO
	 .word	mus_b_palace_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_b_palace_7:
	.byte	KEYSH , mus_b_palace_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 76*mus_b_palace_mvl/mxv
	.byte	W06
mus_b_palace_7_000:
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Bn4 , v064
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn4 , v028
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn4 , v016
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn4 , v008
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W24
	.byte	PEND
	.byte		        c_v+0
	.byte	W24
	.byte		        c_v-32
	.byte		N12   , Bn4 , v064
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn4 , v028
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn4 , v016
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N24   , En2 , v092
	.byte	W12
	.byte		PAN   , c_v+44
	.byte	W12
	.byte		N24   , En2 , v040
	.byte	W12
	.byte		PAN   , c_v-1
	.byte	W12
	.byte		        c_v-46
	.byte		N12   , En2 , v032
	.byte	W24
	.byte		PAN   , c_v+47
	.byte	W60
	.byte		        c_v+0
	.byte	W60
	.byte		N12   , En2 , v092
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte	PATT
	 .word	mus_b_palace_7_000
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		        c_v-32
	.byte		N12   , Bn4 , v064
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn4 , v028
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , An2 , v092
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N24   , Cs2 
	.byte	W24
	.byte	W96
	.byte	W48
	.byte		N14   , En2 , v112
	.byte	W14
	.byte		N09   , Gn2 
	.byte	W10
	.byte		N24   , Cs2 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Cs2 , v044
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Cs2 , v032
	.byte	W24
mus_b_palace_7_001:
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		        c_v-32
	.byte		N12   , Bn4 , v064
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn4 , v028
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn4 , v016
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn4 , v008
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_b_palace_7_001
	.byte	W96
	.byte	W60
	.byte		N12   , En2 , v092
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , An2 , v048
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N12   , Bn4 , v064
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn4 , v028
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn4 , v016
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn4 , v008
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W24
	.byte	PATT
	 .word	mus_b_palace_7_001
	.byte	W60
	.byte		N12   , En2 , v112
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte	W96
mus_b_palace_7_B1:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N12   , Bn4 , v064
	.byte	W12
	.byte		N06   , Fs2 , v048
	.byte	W12
	.byte		N15   , Cn1 , v112
	.byte	W12
	.byte		N06   , Fs2 , v048
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		N03   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte		N06   , Fs2 , v048
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		N03   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , Fs2 , v048
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N12   , Bn4 , v064
	.byte	W12
	.byte		N06   , Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
mus_b_palace_7_002:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte	PEND
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		N03   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W02
	.byte		N09   , Gn2 
	.byte	W04
	.byte		N03   , Cn1 
	.byte	W03
	.byte		        En1 
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte		N06   , Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , Fs2 , v048
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte		N06   , Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N12   , Bn4 , v064
	.byte	W12
	.byte		N06   , Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
mus_b_palace_7_003:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        Dn3 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		N03   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_b_palace_7_003
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte		N06   , Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N12   , Bn4 , v064
	.byte	W12
	.byte		N06   , En1 , v108
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte	PATT
	 .word	mus_b_palace_7_002
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fs2 , v048
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte	GOTO
	 .word	mus_b_palace_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_b_palace_8:
	.byte	KEYSH , mus_b_palace_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 39*mus_b_palace_mvl/mxv
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_b_palace_8_B1:
mus_b_palace_8_000:
	.byte		N01   , Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte	PEND
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W24
mus_b_palace_8_001:
	.byte		N01   , Dn5 , v068
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W18
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_b_palace_8_001
	.byte	PATT
	 .word	mus_b_palace_8_000
	.byte	PATT
	 .word	mus_b_palace_8_000
	.byte	PATT
	 .word	mus_b_palace_8_000
	.byte	PATT
	 .word	mus_b_palace_8_001
	.byte	PATT
	 .word	mus_b_palace_8_001
	.byte		N01   , Dn5 , v068
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W42
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		        Dn5 , v068
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte	PATT
	 .word	mus_b_palace_8_000
	.byte	PATT
	 .word	mus_b_palace_8_000
	.byte	PATT
	 .word	mus_b_palace_8_001
	.byte	PATT
	 .word	mus_b_palace_8_001
	.byte	PATT
	 .word	mus_b_palace_8_000
	.byte	PATT
	 .word	mus_b_palace_8_000
	.byte	PATT
	 .word	mus_b_palace_8_001
	.byte	PATT
	 .word	mus_b_palace_8_001
	.byte	GOTO
	 .word	mus_b_palace_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_b_palace_9:
	.byte	KEYSH , mus_b_palace_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 66*mus_b_palace_mvl/mxv
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_b_palace_9_B1:
	.byte	W96
	.byte	W84
	.byte		N12   , Gn5 , v048
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		        Gn5 , v048
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	GOTO
	 .word	mus_b_palace_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_b_palace:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_b_palace_pri	@ Priority
	.byte	mus_b_palace_rev	@ Reverb.

	.word	mus_b_palace_grp

	.word	mus_b_palace_1
	.word	mus_b_palace_2
	.word	mus_b_palace_3
	.word	mus_b_palace_4
	.word	mus_b_palace_5
	.word	mus_b_palace_6
	.word	mus_b_palace_7
	.word	mus_b_palace_8
	.word	mus_b_palace_9

	.end
