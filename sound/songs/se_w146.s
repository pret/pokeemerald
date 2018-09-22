	.include "MPlayDef.s"

	.equ	se_w146_grp, voicegroup128
	.equ	se_w146_pri, 4
	.equ	se_w146_rev, reverb_set+50
	.equ	se_w146_mvl, 127
	.equ	se_w146_key, 0
	.equ	se_w146_tbs, 1
	.equ	se_w146_exg, 0
	.equ	se_w146_cmp, 1

	.section .rodata
	.global	se_w146
	.align	2

@********************** Track  1 **********************@

se_w146_1:
	.byte	KEYSH , se_w146_key+0
	.byte	TEMPO , 150*se_w146_tbs/2
	.byte		VOICE , 19
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 5*se_w146_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N07   , Bn5 , v080
	.byte	W01
	.byte		VOL   , 55*se_w146_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+3
	.byte	W01
	.byte		VOL   , 67*se_w146_mvl/mxv
	.byte		PAN   , c_v+22
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 90*se_w146_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		PAN   , c_v-12
	.byte		BEND  , c_v-14
	.byte	W02
	.byte		VOL   , 4*se_w146_mvl/mxv
	.byte		PAN   , c_v-22
	.byte		BEND  , c_v-23
	.byte	W01
	.byte		PAN   , c_v-13
	.byte		BEND  , c_v+0
	.byte		N04   , Cn6 
	.byte	W01
	.byte		VOL   , 66*se_w146_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		VOL   , 90*se_w146_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+3
	.byte	W01
	.byte		VOL   , 4*se_w146_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		BEND  , c_v+5
	.byte	W14
	.byte		VOL   , 90*se_w146_mvl/mxv
	.byte	FINE

@******************************************************@
	.align	2

se_w146:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w146_pri	@ Priority
	.byte	se_w146_rev	@ Reverb.

	.word	se_w146_grp

	.word	se_w146_1

	.end
