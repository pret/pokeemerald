	.include "MPlayDef.s"

	.equ	se_w048_grp, voicegroup128
	.equ	se_w048_pri, 4
	.equ	se_w048_rev, reverb_set+50
	.equ	se_w048_mvl, 127
	.equ	se_w048_key, 0
	.equ	se_w048_tbs, 1
	.equ	se_w048_exg, 0
	.equ	se_w048_cmp, 1

	.section .rodata
	.global	se_w048
	.align	2

@********************** Track  1 **********************@

se_w048_1:
	.byte	KEYSH , se_w048_key+0
	.byte	TEMPO , 150*se_w048_tbs/2
	.byte		VOICE , 43
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		VOL   , 61*se_w048_mvl/mxv
	.byte		BEND  , c_v-4
	.byte		N07   , Gs4 , v127
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		VOL   , 75*se_w048_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v-7
	.byte		VOL   , 93*se_w048_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		PAN   , c_v+9
	.byte		VOL   , 110*se_w048_mvl/mxv
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		PAN   , c_v-12
	.byte		BEND  , c_v+7
	.byte	W02
	.byte	W02
	.byte		VOL   , 0*se_w048_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-4
	.byte		N32   
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v-7
	.byte		VOL   , 36*se_w048_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W02
	.byte		PAN   , c_v+9
	.byte		VOL   , 67*se_w048_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v-13
	.byte		VOL   , 84*se_w048_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 92*se_w048_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		VOL   , 99*se_w048_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 105*se_w048_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		VOL   , 110*se_w048_mvl/mxv
	.byte		PAN   , c_v-13
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 46*se_w048_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		VOL   , 67*se_w048_mvl/mxv
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 84*se_w048_mvl/mxv
	.byte		PAN   , c_v-13
	.byte		BEND  , c_v-6
	.byte	W02
	.byte		VOL   , 100*se_w048_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 110*se_w048_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v-7
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 101*se_w048_mvl/mxv
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v+2
	.byte	W02
	.byte		VOL   , 85*se_w048_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 75*se_w048_mvl/mxv
	.byte		PAN   , c_v-13
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 48*se_w048_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		VOL   , 24*se_w048_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 6*se_w048_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_w048:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w048_pri	@ Priority
	.byte	se_w048_rev	@ Reverb.

	.word	se_w048_grp

	.word	se_w048_1

	.end
