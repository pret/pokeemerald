	.include "MPlayDef.s"

	.equ	se_w207_grp, voicegroup128
	.equ	se_w207_pri, 4
	.equ	se_w207_rev, reverb_set+50
	.equ	se_w207_mvl, 127
	.equ	se_w207_key, 0
	.equ	se_w207_tbs, 1
	.equ	se_w207_exg, 0
	.equ	se_w207_cmp, 1

	.section .rodata
	.global	se_w207
	.align	2

@********************** Track  1 **********************@

se_w207_1:
	.byte	KEYSH , se_w207_key+0
	.byte	TEMPO , 190*se_w207_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 28*se_w207_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N15   , An1 , v127
	.byte	W01
	.byte		VOL   , 60*se_w207_mvl/mxv
	.byte	W01
	.byte		        111*se_w207_mvl/mxv
	.byte	W01
	.byte		        120*se_w207_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 109*se_w207_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v-10
	.byte	W01
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v-14
	.byte	W01
	.byte		VOL   , 95*se_w207_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-19
	.byte	W02
	.byte		VOL   , 71*se_w207_mvl/mxv
	.byte		BEND  , c_v-29
	.byte	W01
	.byte		VOL   , 41*se_w207_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W01
	.byte		VOL   , 15*se_w207_mvl/mxv
	.byte		BEND  , c_v-52
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_w207:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w207_pri	@ Priority
	.byte	se_w207_rev	@ Reverb.

	.word	se_w207_grp

	.word	se_w207_1

	.end
