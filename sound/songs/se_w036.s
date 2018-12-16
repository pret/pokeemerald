	.include "MPlayDef.s"

	.equ	se_w036_grp, voicegroup128
	.equ	se_w036_pri, 4
	.equ	se_w036_rev, reverb_set+50
	.equ	se_w036_mvl, 127
	.equ	se_w036_key, 0
	.equ	se_w036_tbs, 1
	.equ	se_w036_exg, 0
	.equ	se_w036_cmp, 1

	.section .rodata
	.global	se_w036
	.align	2

@********************** Track  1 **********************@

se_w036_1:
	.byte	KEYSH , se_w036_key+0
	.byte	TEMPO , 150*se_w036_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 105*se_w036_mvl/mxv
	.byte		BEND  , c_v-48
	.byte		N10   , Gn0 , v127
	.byte	W02
	.byte		PAN   , c_v+7
	.byte		BEND  , c_v-32
	.byte	W01
	.byte		        c_v-16
	.byte	W01
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		        c_v+15
	.byte	W01
	.byte		PAN   , c_v+14
	.byte	W01
	.byte		BEND  , c_v+32
	.byte	W01
	.byte		PAN   , c_v+19
	.byte	W03
	.byte		        c_v+0
	.byte		VOL   , 105*se_w036_mvl/mxv
	.byte		BEND  , c_v-32
	.byte		N10
	.byte	W02
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		PAN   , c_v-11
	.byte		BEND  , c_v+16
	.byte	W02
	.byte		        c_v+32
	.byte	W01
	.byte		PAN   , c_v-15
	.byte	W01
	.byte		BEND  , c_v+48
	.byte	W01
	.byte		PAN   , c_v-20
	.byte	W03
	.byte		        c_v+0
	.byte		VOL   , 105*se_w036_mvl/mxv
	.byte		BEND  , c_v-16
	.byte		N10
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		        c_v+16
	.byte	W01
	.byte		        c_v+32
	.byte	W02
	.byte		        c_v+47
	.byte	W02
	.byte		        c_v+63
	.byte	W16
	.byte	FINE

@******************************************************@
	.align	2

se_w036:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w036_pri	@ Priority
	.byte	se_w036_rev	@ Reverb.

	.word	se_w036_grp

	.word	se_w036_1

	.end
