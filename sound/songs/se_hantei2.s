	.include "MPlayDef.s"

	.equ	se_hantei2_grp, voicegroup129
	.equ	se_hantei2_pri, 5
	.equ	se_hantei2_rev, reverb_set+50
	.equ	se_hantei2_mvl, 127
	.equ	se_hantei2_key, 0
	.equ	se_hantei2_tbs, 1
	.equ	se_hantei2_exg, 0
	.equ	se_hantei2_cmp, 1

	.section .rodata
	.global	se_hantei2
	.align	2

@********************** Track  1 **********************@

se_hantei2_1:
	.byte	KEYSH , se_hantei2_key+0
	.byte	TEMPO , 92*se_hantei2_tbs/2
	.byte		VOICE , 116
	.byte		VOL   , 127*se_hantei2_mvl/mxv
	.byte		PAN   , c_v-62
	.byte		N04   , Fn3 , v127
	.byte	W04
	.byte		VOICE , 10
	.byte		N04   , Cn3 
	.byte	W05
	.byte		VOICE , 116
	.byte		N32   , Fn3 
	.byte	W03
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE

@********************** Track  2 **********************@

se_hantei2_2:
	.byte	KEYSH , se_hantei2_key+0
	.byte		VOICE , 117
	.byte		VOL   , 127*se_hantei2_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+1
	.byte		N04   , Gn3 , v100
	.byte	W04
	.byte		        Dn3 
	.byte	W05
	.byte		N32   , Gn3 
	.byte	W03
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_hantei2:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_hantei2_pri	@ Priority
	.byte	se_hantei2_rev	@ Reverb.

	.word	se_hantei2_grp

	.word	se_hantei2_1
	.word	se_hantei2_2

	.end
