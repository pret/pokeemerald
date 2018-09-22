	.include "MPlayDef.s"

	.equ	se_w054_grp, voicegroup128
	.equ	se_w054_pri, 4
	.equ	se_w054_rev, reverb_set+50
	.equ	se_w054_mvl, 127
	.equ	se_w054_key, 0
	.equ	se_w054_tbs, 1
	.equ	se_w054_exg, 0
	.equ	se_w054_cmp, 1

	.section .rodata
	.global	se_w054
	.align	2

@********************** Track  1 **********************@

se_w054_1:
	.byte	KEYSH , se_w054_key+0
	.byte	TEMPO , 150*se_w054_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 7*se_w054_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N18   , Cn5 , v052
	.byte	W01
	.byte		VOL   , 20*se_w054_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 41*se_w054_mvl/mxv
	.byte		PAN   , c_v-14
	.byte		BEND  , c_v-16
	.byte	W01
	.byte		VOL   , 70*se_w054_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 93*se_w054_mvl/mxv
	.byte		PAN   , c_v-14
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_w054_mvl/mxv
	.byte		BEND  , c_v+8
	.byte	W01
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		PAN   , c_v-14
	.byte	W01
	.byte		VOL   , 98*se_w054_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+10
	.byte	W01
	.byte		VOL   , 85*se_w054_mvl/mxv
	.byte		PAN   , c_v-14
	.byte		BEND  , c_v+4
	.byte	W02
	.byte		VOL   , 69*se_w054_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-7
	.byte	W01
	.byte		VOL   , 51*se_w054_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v-22
	.byte	W01
	.byte		PAN   , c_v-14
	.byte		VOL   , 38*se_w054_mvl/mxv
	.byte		BEND  , c_v-28
	.byte	W01
	.byte		VOL   , 17*se_w054_mvl/mxv
	.byte		BEND  , c_v-32
	.byte	W01
	.byte		VOL   , 4*se_w054_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W08
	.byte	FINE

@******************************************************@
	.align	2

se_w054:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w054_pri	@ Priority
	.byte	se_w054_rev	@ Reverb.

	.word	se_w054_grp

	.word	se_w054_1

	.end
