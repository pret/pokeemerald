	.include "MPlayDef.s"

	.equ	se_w063_grp, voicegroup128
	.equ	se_w063_pri, 4
	.equ	se_w063_rev, reverb_set+50
	.equ	se_w063_mvl, 127
	.equ	se_w063_key, 0
	.equ	se_w063_tbs, 1
	.equ	se_w063_exg, 0
	.equ	se_w063_cmp, 1

	.section .rodata
	.global	se_w063
	.align	2

@********************** Track  1 **********************@

se_w063_1:
	.byte	KEYSH , se_w063_key+0
	.byte	TEMPO , 150*se_w063_tbs/2
	.byte		VOICE , 18
	.byte		VOL   , 110*se_w063_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , En3 , v127
	.byte	W03
	.byte		N01   , As3 
	.byte	W03
	.byte		N02   , Gn3 
	.byte	W03
	.byte		N01   , Cs4 
	.byte	W03
	.byte		PAN   , c_v+7
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		N01   , As3 
	.byte	W03
	.byte		PAN   , c_v-7
	.byte		N02   , Gn3 , v040
	.byte	W03
	.byte		N01   , Cs4 
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_w063_2:
	.byte	KEYSH , se_w063_key+0
	.byte		VOICE , 5
	.byte		VOL   , 110*se_w063_mvl/mxv
	.byte		N01   , Cn3 , v040
	.byte	W02
	.byte		N01   
	.byte	W04
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W04
se_w063_2_000:
	.byte		N01   , Cn3 , v020
	.byte	W02
	.byte		N01   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	se_w063_2_000
	.byte	FINE

@******************************************************@
	.align	2

se_w063:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w063_pri	@ Priority
	.byte	se_w063_rev	@ Reverb.

	.word	se_w063_grp

	.word	se_w063_1
	.word	se_w063_2

	.end
