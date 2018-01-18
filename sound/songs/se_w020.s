	.include "MPlayDef.s"

	.equ	se_w020_grp, voicegroup_869D6F4
	.equ	se_w020_pri, 4
	.equ	se_w020_rev, reverb_set+50
	.equ	se_w020_mvl, 127
	.equ	se_w020_key, 0
	.equ	se_w020_tbs, 1
	.equ	se_w020_exg, 0
	.equ	se_w020_cmp, 1

	.section .rodata
	.global	se_w020
	.align	2

@********************** Track  1 **********************@

se_w020_1:
	.byte	KEYSH , se_w020_key+0
	.byte	TEMPO , 150*se_w020_tbs/2
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*se_w020_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N05   , Fs2 , v127
	.byte	W01
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v-3
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v-12
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N11   
	.byte	W02
	.byte		BEND  , c_v-10
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		        c_v+3
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		        c_v-21
	.byte	W01
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v-28
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_w020:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w020_pri	@ Priority
	.byte	se_w020_rev	@ Reverb.

	.word	se_w020_grp

	.word	se_w020_1

	.end
