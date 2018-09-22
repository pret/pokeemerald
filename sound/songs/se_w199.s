	.include "MPlayDef.s"

	.equ	se_w199_grp, voicegroup128
	.equ	se_w199_pri, 4
	.equ	se_w199_rev, reverb_set+50
	.equ	se_w199_mvl, 127
	.equ	se_w199_key, 0
	.equ	se_w199_tbs, 1
	.equ	se_w199_exg, 0
	.equ	se_w199_cmp, 1

	.section .rodata
	.global	se_w199
	.align	2

@********************** Track  1 **********************@

se_w199_1:
	.byte	KEYSH , se_w199_key+0
	.byte	TEMPO , 150*se_w199_tbs/2
	.byte		VOICE , 40
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_w199_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn4 , v100
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte		N03   , Bn3 , v100
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v-6
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+6
	.byte		N01   , Cn4 
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W02
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v-6
	.byte		N01   , Bn3 , v100
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , Bn3 , v100
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_w199:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w199_pri	@ Priority
	.byte	se_w199_rev	@ Reverb.

	.word	se_w199_grp

	.word	se_w199_1

	.end
