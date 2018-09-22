	.include "MPlayDef.s"

	.equ	se_w207b_grp, voicegroup128
	.equ	se_w207b_pri, 4
	.equ	se_w207b_rev, reverb_set+50
	.equ	se_w207b_mvl, 127
	.equ	se_w207b_key, 0
	.equ	se_w207b_tbs, 1
	.equ	se_w207b_exg, 0
	.equ	se_w207b_cmp, 1

	.section .rodata
	.global	se_w207b
	.align	2

@********************** Track  1 **********************@

se_w207b_1:
	.byte	KEYSH , se_w207b_key+0
	.byte	TEMPO , 150*se_w207b_tbs/2
	.byte		VOICE , 56
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 65*se_w207b_mvl/mxv
	.byte		BEND  , c_v+8
	.byte		N01   , Cs6 , v112
	.byte	W01
	.byte		BEND  , c_v+0
	.byte		N01   , Dn6 , v100
	.byte	W01
	.byte		        Dn6 , v060
	.byte	W04
	.byte		BEND  , c_v-8
	.byte		N01   , Ds6 , v112
	.byte	W01
	.byte		BEND  , c_v+0
	.byte		N01   , En6 , v100
	.byte	W01
	.byte		        En6 , v060
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_w207b:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w207b_pri	@ Priority
	.byte	se_w207b_rev	@ Reverb.

	.word	se_w207b_grp

	.word	se_w207b_1

	.end
