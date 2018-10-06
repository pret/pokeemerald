	.include "MPlayDef.s"

	.equ	se_w204_grp, voicegroup128
	.equ	se_w204_pri, 4
	.equ	se_w204_rev, reverb_set+50
	.equ	se_w204_mvl, 127
	.equ	se_w204_key, 0
	.equ	se_w204_tbs, 1
	.equ	se_w204_exg, 0
	.equ	se_w204_cmp, 1

	.section .rodata
	.global	se_w204
	.align	2

@********************** Track  1 **********************@

se_w204_1:
	.byte	KEYSH , se_w204_key+0
	.byte	TEMPO , 150*se_w204_tbs/2
	.byte		VOICE , 37
	.byte		BENDR , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 25*se_w204_mvl/mxv
	.byte		BEND  , c_v+11
	.byte		N02   , Fn4 , v127
	.byte	W01
	.byte		VOL   , 42*se_w204_mvl/mxv
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		VOL   , 62*se_w204_mvl/mxv
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+0
	.byte		N15   
	.byte	W01
	.byte		VOL   , 77*se_w204_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		VOL   , 84*se_w204_mvl/mxv
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		VOL   , 96*se_w204_mvl/mxv
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+20
	.byte	W01
	.byte		VOL   , 100*se_w204_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+25
	.byte	W01
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+30
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+34
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+40
	.byte	W02
	.byte		VOL   , 94*se_w204_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		VOL   , 85*se_w204_mvl/mxv
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+37
	.byte	W01
	.byte		VOL   , 66*se_w204_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+36
	.byte	W01
	.byte		VOL   , 49*se_w204_mvl/mxv
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+34
	.byte	W01
	.byte		VOL   , 32*se_w204_mvl/mxv
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+32
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_w204:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w204_pri	@ Priority
	.byte	se_w204_rev	@ Reverb.

	.word	se_w204_grp

	.word	se_w204_1

	.end
