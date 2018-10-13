	.include "MPlayDef.s"

	.equ	se_w129_grp, voicegroup128
	.equ	se_w129_pri, 4
	.equ	se_w129_rev, reverb_set+50
	.equ	se_w129_mvl, 127
	.equ	se_w129_key, 0
	.equ	se_w129_tbs, 1
	.equ	se_w129_exg, 0
	.equ	se_w129_cmp, 1

	.section .rodata
	.global	se_w129
	.align	2

@********************** Track  1 **********************@

se_w129_1:
	.byte	KEYSH , se_w129_key+0
	.byte	TEMPO , 180*se_w129_tbs/2
	.byte		VOICE , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*se_w129_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Ds6 , v100
	.byte	W01
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		VOL   , 90*se_w129_mvl/mxv
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 77*se_w129_mvl/mxv
	.byte		BEND  , c_v-37
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*se_w129_mvl/mxv
	.byte		BEND  , c_v-47
	.byte	W02
	.byte		VOL   , 100*se_w129_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 90*se_w129_mvl/mxv
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		VOL   , 77*se_w129_mvl/mxv
	.byte		BEND  , c_v-37
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		VOL   , 37*se_w129_mvl/mxv
	.byte		BEND  , c_v-47
	.byte	W02
	.byte		VOL   , 100*se_w129_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Ds6 , v056
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 90*se_w129_mvl/mxv
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		VOL   , 77*se_w129_mvl/mxv
	.byte		BEND  , c_v-37
	.byte	W01
	.byte		PAN   , c_v-10
	.byte		VOL   , 37*se_w129_mvl/mxv
	.byte		BEND  , c_v-47
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_w129_2:
	.byte	KEYSH , se_w129_key+0
	.byte		VOICE , 53
	.byte		VOL   , 100*se_w129_mvl/mxv
	.byte	W02
	.byte		N06   , Cn6 , v040
	.byte	W04
	.byte	W02
	.byte		N04   , Cn6 , v032
	.byte	W04
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_w129:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w129_pri	@ Priority
	.byte	se_w129_rev	@ Reverb.

	.word	se_w129_grp

	.word	se_w129_1
	.word	se_w129_2

	.end
